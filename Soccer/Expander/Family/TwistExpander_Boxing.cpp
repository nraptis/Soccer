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
    std::uint64_t aPrevious = 0x92C824DD5F7C603AULL; std::uint64_t aIngress = 0x9613AB9E20467B84ULL; std::uint64_t aCarry = 0xA68D022191A4176BULL;

    std::uint64_t aWandererA = 0x8275E343578F4529ULL; std::uint64_t aWandererB = 0x8CCFFB1AA78CF0BDULL; std::uint64_t aWandererC = 0xE007EDA6FC59D747ULL; std::uint64_t aWandererD = 0xAA867FF83894A1FEULL;
    std::uint64_t aWandererE = 0xC92DE94E4688052AULL; std::uint64_t aWandererF = 0xE424437B464873D7ULL; std::uint64_t aWandererG = 0xB6836C081406B114ULL; std::uint64_t aWandererH = 0x9191681F2473D77CULL;
    std::uint64_t aWandererI = 0xAEB2CF9F24241EB7ULL; std::uint64_t aWandererJ = 0xC66280C019BA64DFULL; std::uint64_t aWandererK = 0xF6E238FD738DCB86ULL;

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
        aPrevious = 13730211197779416607U;
        aCarry = 13280160540858544995U;
        aWandererA = 13878251013513952597U;
        aWandererB = 16413669707245672106U;
        aWandererC = 16962534676923363744U;
        aWandererD = 16943708787677489120U;
        aWandererE = 12538380993167907449U;
        aWandererF = 10733088755130742025U;
        aWandererG = 13140527936511014294U;
        aWandererH = 10655142159105074054U;
        aWandererI = 15911238702305398383U;
        aWandererJ = 10232633881510876010U;
        aWandererK = 15274362142041819056U;
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
    // read from: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
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
    std::uint64_t aPrevious = 0x96606FF736520DE8ULL; std::uint64_t aIngress = 0xF8560EA61BA0FFF1ULL; std::uint64_t aCarry = 0xBCFF96FBFA3C773BULL;

    std::uint64_t aWandererA = 0xFFDE7F18E6053A92ULL; std::uint64_t aWandererB = 0xEC0F4FF83BA09C4BULL; std::uint64_t aWandererC = 0xD50244235D14E66DULL; std::uint64_t aWandererD = 0xECFCC8D566852354ULL;
    std::uint64_t aWandererE = 0xD59B1A3B8576A118ULL; std::uint64_t aWandererF = 0xDE9BC42055EF72AFULL; std::uint64_t aWandererG = 0xF2F94E7B629D14EAULL; std::uint64_t aWandererH = 0x8395935BC7F4DB63ULL;
    std::uint64_t aWandererI = 0x9B9E213A4C019B0BULL; std::uint64_t aWandererJ = 0xDE3EF90D1363D758ULL; std::uint64_t aWandererK = 0xA39A396F77E050C9ULL;

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
        aPrevious = 9946841920921989028U;
        aCarry = 9554256132394484284U;
        aWandererA = 15405713219419988947U;
        aWandererB = 17305416808959685254U;
        aWandererC = 15049147931132250248U;
        aWandererD = 14254323202479883067U;
        aWandererE = 13713856339602021345U;
        aWandererF = 11724888040078984570U;
        aWandererG = 15416792835959455101U;
        aWandererH = 16702099767714752919U;
        aWandererI = 12074965075439974147U;
        aWandererJ = 10669938599432648496U;
        aWandererK = 10498501980191802087U;
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
    std::uint64_t aPrevious = 0xDBFBADAE760A92EFULL;
    std::uint64_t aIngress = 0xF380964C83B8472DULL;
    std::uint64_t aCarry = 0x957C9CE00995BE0DULL;

    std::uint64_t aWandererA = 0xC5DB2B86A19325EFULL;
    std::uint64_t aWandererB = 0xAE0F51C24ADD0952ULL;
    std::uint64_t aWandererC = 0xBD59C016234C28BEULL;
    std::uint64_t aWandererD = 0xF7A9C06525978C12ULL;
    std::uint64_t aWandererE = 0xF26623561BDE0DC0ULL;
    std::uint64_t aWandererF = 0xA070CCE4E8A3946CULL;
    std::uint64_t aWandererG = 0xCAB28C75D7310CF6ULL;
    std::uint64_t aWandererH = 0xB0560DA41E1A26E3ULL;
    std::uint64_t aWandererI = 0xCF2C3590A5A7BF65ULL;
    std::uint64_t aWandererJ = 0xD94897C44860BA40ULL;
    std::uint64_t aWandererK = 0xC18E006BB8619605ULL;

    // [seed]
        TwistSnow::AES256Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneC);
        TwistSnow::Sha256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneE);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA, 3);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
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
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneB, aExpandLaneA, aInvestLaneG);
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
    // write to: invest_c, invest_d, work_a, work_b, work_c, work_d
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, invest_a, invest_b, invest_c, invest_d
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
    // write to: fire_a, fire_b, operation_a, operation_b, operation_c, operation_d
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
    // temp storage: snow_a, snow_b, work_c, work_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_c, snow_d, expand_a, expand_b, expand_c, expand_d
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
    // temp storage: invest_a, invest_b, invest_c, invest_d, fire_a, fire_b, fire_c, fire_d
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
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
    std::uint64_t aPrevious = 0xCDC563FEFA2F26C4ULL; std::uint64_t aIngress = 0xDC83AD134468293FULL; std::uint64_t aCarry = 0xCFB4B7F013B527C5ULL;

    std::uint64_t aWandererA = 0xC479CA5F80444583ULL; std::uint64_t aWandererB = 0xCE4EC2D84EDC7D9BULL; std::uint64_t aWandererC = 0xFC9E41DF4683AD5EULL; std::uint64_t aWandererD = 0xB3C2256BC174BC62ULL;
    std::uint64_t aWandererE = 0x881974231C87A14AULL; std::uint64_t aWandererF = 0xD7F12AC812D605F5ULL; std::uint64_t aWandererG = 0xE901468FFE447943ULL; std::uint64_t aWandererH = 0x99AA68E420973EE0ULL;
    std::uint64_t aWandererI = 0xBCF9FEBF3848483FULL; std::uint64_t aWandererJ = 0x90C51083FC0CFD79ULL; std::uint64_t aWandererK = 0xD1E6F9875703FB46ULL;

    // [seed]
    {
        aPrevious = 12575255383086731437U;
        aCarry = 17184909956018706551U;
        aWandererA = 16287700737890154298U;
        aWandererB = 14161822384840442783U;
        aWandererC = 12893322369847075462U;
        aWandererD = 15988397888143170514U;
        aWandererE = 10431274023405697971U;
        aWandererF = 9692725339503868423U;
        aWandererG = 10621679284672579104U;
        aWandererH = 12698423124950789990U;
        aWandererI = 13486145216957743626U;
        aWandererJ = 10759318231345774826U;
        aWandererK = 9581714123386795292U;
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
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 3, 2 with offsets 7361U, 7111U, 8065U, 5276U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7361U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7111U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8065U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5276U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 2, 1, 0 with offsets 6534U, 7293U, 2478U, 754U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6534U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7293U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2478U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 754U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 1, 0, 3 with offsets 1518U, 896U, 1390U, 1999U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1518U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 896U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1390U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1999U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 2, 1 with offsets 4830U, 5528U, 1102U, 3040U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4830U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5528U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1102U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3040U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 1, 2, 0 with offsets 1081U, 1395U, 974U, 1031U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1081U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1395U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 974U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1031U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 3, 2, 0, 1 with offsets 549U, 1112U, 341U, 1981U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 549U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1112U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1981U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 3, 2, 1, 0 with offsets 119U, 381U, 1107U, 1603U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 119U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 381U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1107U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1603U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 1, 2, 3 with offsets 1395U, 1668U, 339U, 1278U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1395U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 339U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1278U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 105U, 1594U, 758U, 1786U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1594U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 758U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1786U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 1 with offsets 1059U, 7777U, 6541U, 3980U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1059U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7777U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6541U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3980U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 1, 0, 2 with offsets 2794U, 6213U, 1829U, 7443U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2794U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6213U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1829U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7443U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 0 with offsets 983U, 1506U, 4572U, 668U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 983U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1506U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4572U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 668U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 0, 1, 3 with offsets 1498U, 1527U, 2087U, 1034U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1498U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1527U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2087U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1034U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3419U, 495U, 6732U, 7674U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3419U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 495U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 6732U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 7674U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1549U, 427U, 593U, 490U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1549U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 427U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 593U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 490U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1800U, 1907U, 401U, 668U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1800U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1907U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 401U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1266U, 65U, 1328U, 707U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1266U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 65U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1328U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 707U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 976U, 635U, 1540U, 1896U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 976U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 635U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1896U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 3, 1 [0..<W_KEY]
        // offsets: 1691U, 1345U, 849U, 641U
        // byte shifts: 8U, 16U, 0U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1345U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 641U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseASalts = {
    {
        {
            0x03E8C2AFB32DE157ULL, 0xBCD0B9F2E75AA67BULL, 0xF60B3E8313A3E879ULL, 0x97EBD69CD352C28AULL, 
            0xC2C8E520A386F17CULL, 0x8FE16768A18AF808ULL, 0x5C83AB97ED190B72ULL, 0xFE3D9CF7C7FDF929ULL, 
            0x08B3C12BAF06C1B6ULL, 0xC3FA38F25BAFDD56ULL, 0x74BE26AE8F852AC9ULL, 0xEE008ED284C08ACDULL, 
            0x95845E1757444C86ULL, 0x305769A5624B45BCULL, 0xB57688BD018AEF3BULL, 0x9E300A2D0BA4F477ULL, 
            0xB724BE78C1824465ULL, 0x66BD57384B30174AULL, 0xED33AC2E30E1C9BFULL, 0xC3D728E9952803B8ULL, 
            0x414B2D3B4A682B1DULL, 0xAC460B5DB64E6F09ULL, 0x6BDEA2A750EB5451ULL, 0x2BB5ED509E954BCBULL, 
            0x04C7F96F405DAF98ULL, 0x9B0BFE5167F40B34ULL, 0x9427B70754786789ULL, 0x71E27B2276E1C7B5ULL, 
            0x9447242BDF4052B7ULL, 0xDC5FA39DFC358E26ULL, 0xD0BEF1909503A737ULL, 0x4046567E28BC1395ULL
        },
        {
            0x7C30DDF48D09A1C9ULL, 0x6C83616256504BE0ULL, 0x735B93FC5BA0801CULL, 0xFD33A4B4EF6BC878ULL, 
            0xAE0956DCA0292B64ULL, 0xEE05A00D266DD3DEULL, 0x87980564A8E2CAEFULL, 0x563ED0696F7CE8A2ULL, 
            0xDB49F97D1FD1B620ULL, 0xDC7A831EFAD2A1E9ULL, 0x42B4D972F92C9A32ULL, 0x95AF08079696DEBFULL, 
            0x5D9645B8FED6FD33ULL, 0x260BF28EB0BC0911ULL, 0x786E4FD7B13B3CEBULL, 0x79BFAEB33D947D5FULL, 
            0x38A1734AF660917CULL, 0x1ACD643DBF0CAFE9ULL, 0xDFCE388C51924CE1ULL, 0x994DD9DB1772DDF4ULL, 
            0x19933590779D2416ULL, 0x48BA7EF7663C6DCFULL, 0xF146AA6A5097035EULL, 0x0EF10DD2768CF8CAULL, 
            0xFD2BC0AC57DF58FFULL, 0x826AC6CE6D087D57ULL, 0xEE5CCAD4E11795F3ULL, 0x4F546C1F5640DFBBULL, 
            0x9A96D2C51100547EULL, 0xA31583BCF5E5216AULL, 0x90597CE68D2FDF3DULL, 0xD98E0AE31193B492ULL
        },
        {
            0x6887A87E3A545CD4ULL, 0x6AA4648A17265474ULL, 0x8DD491B925484FE5ULL, 0xA058348F88859E83ULL, 
            0xD49F028267308FE2ULL, 0x5DDCE12A64A904B8ULL, 0x27E99FDD835EF5E8ULL, 0x68434382C54F59C7ULL, 
            0xF774A0093EC6CEE3ULL, 0xD1668FF557C36AA6ULL, 0x0D5A49D44362C89FULL, 0xDA5272DCA8BED93FULL, 
            0x5518163C2C412617ULL, 0xB04A48FF7A8C8B63ULL, 0x893A5C1970243A81ULL, 0xA04CFA0C2418A2ADULL, 
            0x4583B00EE080B879ULL, 0xB4E89F1A86A602A4ULL, 0xD1E28EC97D0F8212ULL, 0xC9E0B2F9628FDD85ULL, 
            0xFC1255828EA596DAULL, 0xBDD231DA53ADAF28ULL, 0xA8BFFFB3CE031DEEULL, 0xB58C0B7A0666F68CULL, 
            0xD7319703C9C3AB80ULL, 0x375086994AED4DA3ULL, 0x6A24031B5A019FD6ULL, 0x90286791D4A183F8ULL, 
            0xFF34BC812702DEF7ULL, 0x5AC51BEAFE5091CCULL, 0x52D91BD4CE6DA3BCULL, 0xB3B212B784AB715AULL
        },
        {
            0x5CC200CAD7733E71ULL, 0x621168ABCD809610ULL, 0x320FAB28E1A60279ULL, 0xA0313BA755D3CC15ULL, 
            0x8E86093993B539A8ULL, 0x579E3C4290110FA1ULL, 0xE8A2BE1E540BA688ULL, 0xD5E405F1E802E9EFULL, 
            0x11880DC5F39799F9ULL, 0x96DA2A1146F548DEULL, 0x1BC2B23CA15C4BB0ULL, 0x1447DCA69A3063F2ULL, 
            0x5CD7D50783055988ULL, 0x1508EA7C327ECB8DULL, 0x192C9E848AFCB83CULL, 0xADEF2171B139BEFFULL, 
            0x204B08F1984BFDC1ULL, 0x5C03DE635A5FA1AAULL, 0x272529B9DDFD35E6ULL, 0x9E8071EA46F1EF45ULL, 
            0x5F1838A2D5A76D33ULL, 0xA38B2BDDDF274C30ULL, 0x53F3334D3124F22FULL, 0xD65600AE3AF32982ULL, 
            0xF4498B60CE0040A9ULL, 0x7267951345BBEDACULL, 0xD2D4E7189A96158AULL, 0x5263987F795E420EULL, 
            0x6D0FB6E3615A6A26ULL, 0x136079F2D69C1DB5ULL, 0xCD7E100BDA9555AAULL, 0x756A0C60FF6E822EULL
        },
        {
            0xE97CA19714054BE0ULL, 0x049C56A0755C66D2ULL, 0xAAA59C9FC435A02DULL, 0x1C02F727AD95242FULL, 
            0x5C6CD69FD51B00D3ULL, 0xD51BEBF3F4DD213AULL, 0xD446C9F1EB3BC75BULL, 0x451C45B9938B22C6ULL, 
            0x540DA8470354ED85ULL, 0x087F35B0F5712C01ULL, 0x4ACF6F8882EC0026ULL, 0x764A3F1F723523D9ULL, 
            0x3CF4C63E4BB8F695ULL, 0x409AB12573AAB84EULL, 0xD5435D0EC27452B0ULL, 0x6D1EB8F9DC3FA1A7ULL, 
            0xDE10D652F61C1CBBULL, 0x4C1FEF5D1D3D6EC6ULL, 0x6C44606F90044838ULL, 0x95811E45637A2FFDULL, 
            0x6E5D3D82E13FB183ULL, 0x4237DF63DA6D9D36ULL, 0x18353727B94D3B03ULL, 0x194E220471BBFA08ULL, 
            0x35BEA7B210C03C35ULL, 0x340424AAB4684895ULL, 0x47D61F74A34DF1C0ULL, 0xA65414B2F6080DC7ULL, 
            0x9479E6BEBDE56ECEULL, 0x844C4CE381F36D79ULL, 0x3B324B3A13E02473ULL, 0xB6F4361FF4BB9466ULL
        },
        {
            0x088ADC8754686F92ULL, 0x44434526F491AB1EULL, 0x6DE8470A3A648A82ULL, 0x7F51B6EE16873C3CULL, 
            0x65F7F96FFCE5A33CULL, 0x60FADE9CCDE898AEULL, 0x217665506333552EULL, 0x32AEBEE3B9AA7374ULL, 
            0x6D7169A54F619C21ULL, 0x8CF5C999ED0FA5F9ULL, 0x2DEC2B1108A300BBULL, 0xD613326C1A57549FULL, 
            0xF16624F1D206B2DFULL, 0xB4E7F68AD62F829CULL, 0x1983ECE252068B80ULL, 0xED29CD131D90649CULL, 
            0x0B2DBA1F9D703B18ULL, 0x734EB59330D52EFEULL, 0xE68164EC44AAED39ULL, 0xDE0659615708155CULL, 
            0x46A19E3B0ACE32BFULL, 0x5C619BAE77AFA463ULL, 0xDE65C6ABAAA5566BULL, 0x4A832236CDF2427DULL, 
            0x94735A266831F7CEULL, 0x103C0F5A2303A8D0ULL, 0x95D0EA34EAC2C91CULL, 0xCC9225CC3786B261ULL, 
            0xB58D1F4E25F0730BULL, 0x46DD6F319731A423ULL, 0xF8A23EF26CD4983FULL, 0x847104B411540A26ULL
        }
    },
    {
        {
            0xE64B926A5EFE8736ULL, 0xB2B2F252980A4603ULL, 0x4465766A6ED5701DULL, 0x7EBE3B1A18C696F8ULL, 
            0x868345D54159F8CFULL, 0x7CE1D729C8EB494FULL, 0x9D05132B06DA5BF5ULL, 0xD7837A9B160C15F5ULL, 
            0xAE083E386BEF468DULL, 0x881DF1BDA6CDB879ULL, 0x7CC77AFCA67253E2ULL, 0xE1555760D630E720ULL, 
            0xC2D33BBA17FF0D9DULL, 0xE22EBB8392D98F5FULL, 0x076514A07EEFE7E0ULL, 0x34E2225E52827B16ULL, 
            0x60F6A72F55431CE7ULL, 0x118D6E998A1670D9ULL, 0xFEDDC97161F8751DULL, 0x1578E9F7EB84D32CULL, 
            0xBC3B983C2FF63C53ULL, 0xDF665E60E7A2DCE5ULL, 0x01D8AA900FC14368ULL, 0xD7ED116123BB3620ULL, 
            0xC1D9F8AFE119A172ULL, 0x199B50747B559739ULL, 0x410AC14D12413FD1ULL, 0x645FE5E2DD823F80ULL, 
            0x848B55872B5234D8ULL, 0xD363476D3990E3E2ULL, 0x58B2A465B365B3CCULL, 0x703D5D18D4200947ULL
        },
        {
            0xA9968A1416C708FBULL, 0xFB437006DF7F73F7ULL, 0xB1C71BBF01A50231ULL, 0x4A8790CB451CA60FULL, 
            0xF4A087B90F2F8314ULL, 0xE4B62B5381BD005EULL, 0x58B775FCBA541003ULL, 0x41FF346DE3EC139EULL, 
            0x944D67AAE2CF8C9BULL, 0x21611279A60DC3F5ULL, 0x2BA8CC532EB1BDBAULL, 0x0D8B23B441066770ULL, 
            0xB00C25C455147DBBULL, 0x094E885C66ED2D61ULL, 0x6CBA74FDE9873205ULL, 0xB1EDB750C5774E95ULL, 
            0x2AD6D0251355F451ULL, 0x1ACD7A4758649302ULL, 0x400154C19C606A31ULL, 0xE71541E9FCD00D06ULL, 
            0xDBD21059DF4C4F70ULL, 0xC9315C723A7975BEULL, 0xDCF9FD0B56A1DE79ULL, 0xE472ABB4BB1CD299ULL, 
            0x8346CB1A510D4E0CULL, 0xBF699CA330370B08ULL, 0x065A701A82613ADFULL, 0x47DA536E28F25F46ULL, 
            0xF56D200EAE9D18C4ULL, 0x610DF333F00CDDE9ULL, 0x58812F2FBE4620A2ULL, 0x8983E8EAC4B0989DULL
        },
        {
            0x0EFF7B243EDDBDF1ULL, 0x2F11591FF577D284ULL, 0xDB364CEE3E5E864AULL, 0xD07CAE0B4C72824CULL, 
            0x36B0CB6F812C8859ULL, 0x92285909FE779C4FULL, 0xE1E8EB04444ED59BULL, 0x020170FB8F467E81ULL, 
            0xD4C10C9910CE779BULL, 0x11E7F2BA1471950BULL, 0xFC80F22BE4A93CCEULL, 0x5B5C351CA840EC7AULL, 
            0xA3CAE1E0ECB41F3DULL, 0xD32370BB09DD8AF4ULL, 0x73674EF556A7D449ULL, 0x729500D225EDA198ULL, 
            0x21F0A0EE20821E6EULL, 0x8AA46705168F9303ULL, 0x7924C86699BDC09DULL, 0x7E7A3C01A7F51DD6ULL, 
            0x3C88E4BD3989BF32ULL, 0x83B8F4C97A0E28A0ULL, 0xF41C4DD4470DFE58ULL, 0xFA86DA67766164F5ULL, 
            0x6E1579A2A358DED1ULL, 0x1CC0B7C363D331EEULL, 0x39377765C286AB66ULL, 0x61E4E5984A4B7F4FULL, 
            0x9CCF1A5EB70DE9D9ULL, 0x89D26A8EFF3C2908ULL, 0x6708F522BD6975EFULL, 0x0913C952794E08ECULL
        },
        {
            0xC72934E3FE705378ULL, 0xDB88FEDD06DE2FB1ULL, 0x4A100FEE3371C264ULL, 0xD9488011E6F180A7ULL, 
            0x44C0A2CE8E078100ULL, 0x5571A40DA6D31007ULL, 0x9EADC6C5349FED82ULL, 0x19028F6435165F52ULL, 
            0x9EBBB916AF1970D6ULL, 0xAB05EE8F81CC0D01ULL, 0xEC1B3D977F88776AULL, 0x38D0AD113E8924CAULL, 
            0x5BE4122F001BA08EULL, 0x51EBA2165D9EEBBBULL, 0xBBDF254EF6E20466ULL, 0xDD3C87860EB054A5ULL, 
            0x5AB899AA605951A6ULL, 0xE119ACFD23E8682EULL, 0xBE24A3660D680019ULL, 0xDDFE153256E258C5ULL, 
            0x41A5524480878A96ULL, 0x6AC287CAB79A80B3ULL, 0x1E0C9AD108150B64ULL, 0x21444F22D8F56282ULL, 
            0x2C11BC631BFCCEEFULL, 0xAD98B608E7F82E57ULL, 0xDC68F0592145D545ULL, 0xBB9638DAA94959B7ULL, 
            0x2E3157E0DB67B1ADULL, 0x14245DC5FFA7C49AULL, 0xFCCEFAE75C284090ULL, 0xD4B07D6F8B63739DULL
        },
        {
            0x263C377FB3EA07DFULL, 0x9881DF74A710DB3EULL, 0x9B4E6B95F54EBAB3ULL, 0xA9A78085A5ED0E84ULL, 
            0x06AF6D82CB80ACFFULL, 0xA20503BF96071B15ULL, 0x24B1F59ED5FBE1F5ULL, 0xE944CC61E2384DBAULL, 
            0x8012F127AA5B2FEAULL, 0xB10539B384C3187FULL, 0x50BF175B1726695BULL, 0xECB118BE26F8EFD6ULL, 
            0x498EB5110DACB76EULL, 0x9AA68F3E11CBA1D2ULL, 0x6986E9FF084665F4ULL, 0xF37B10F2A7F680A4ULL, 
            0x1109887BDC084058ULL, 0x800D83834625BEBAULL, 0x4DA897904AC5012FULL, 0xDF6F5C00FD241CF5ULL, 
            0x8684AB52610BDF38ULL, 0x54922C1D518027D2ULL, 0x441C8F12EFA75F37ULL, 0x00C94D3C029BCA95ULL, 
            0x8B7468D09EEABA37ULL, 0xD060A5C1A3A4C8FDULL, 0x80F473591033D1DFULL, 0x171F52590220C531ULL, 
            0x62E22295E687A1BCULL, 0x7F2C40069DFD2C17ULL, 0x12C3AFD3D130FB5BULL, 0x6ADF630D312B22BFULL
        },
        {
            0x6D3553A0DBD7D180ULL, 0xA6F6B75B2F5F2968ULL, 0x1BEC4F26D6D93BE7ULL, 0xE096A22056C3F176ULL, 
            0xC288D5ABA1A93D04ULL, 0xE855BD11BE49C9B1ULL, 0xAAC91E1AC8910AF1ULL, 0xC545FAE5CFEC7DB5ULL, 
            0xBD7C44F451D3CA6CULL, 0x3A4B4632CEC60E27ULL, 0xE0D631B646FAAEBBULL, 0xDC1CC2A42D810CE3ULL, 
            0xD554A248A3289F9BULL, 0x715DC27AF5B70FA3ULL, 0x56EAA6FD7FFB613CULL, 0x6C5E184F5D5F36B8ULL, 
            0xC70CF7C42A4269B6ULL, 0x4F07A5ADE68BAAC6ULL, 0x36E285A7E3E6F728ULL, 0x9E8F6938BAA813DBULL, 
            0xC48E297C27993080ULL, 0xDE486223F14C1485ULL, 0x2AB9431F316B0E8DULL, 0xE4A7927E77DE40C7ULL, 
            0x02975934F89699DBULL, 0x583B025094965FD0ULL, 0x35D66B8DB1DD183AULL, 0x8FE838734CF512F0ULL, 
            0x73DC049B76450389ULL, 0x5F6C4B91658C878CULL, 0x700F40B61B4B3A04ULL, 0x38B5B15775B1755CULL
        }
    },
    {
        {
            0x16CC793C3747CE53ULL, 0x983D744A1A641D20ULL, 0xD8B7E8988D9EF7FFULL, 0xC5F75CCEFB46DCA8ULL, 
            0x9F8797F95A1E9022ULL, 0x9BA54BEBE2296F71ULL, 0x8B08631B649C538EULL, 0x4EE38BAD9F3CC821ULL, 
            0x46A0217FD027DBB2ULL, 0xE4267AF72F57C1ABULL, 0xECB4E799A6141D84ULL, 0xEA002329613F0C3BULL, 
            0xE4DFE7486D6745C0ULL, 0x5C503AA49C9E9777ULL, 0x2CD38EFB5D707E49ULL, 0xDD156E885E6A003CULL, 
            0x0BF8FBD586682DBEULL, 0x583C216366D2D2E7ULL, 0x9D2DBEA1B413B1A2ULL, 0x3BA581C738CD4CDDULL, 
            0x58279AE28F878B5CULL, 0x0BA32AAD3CDDB4BAULL, 0xEA32474F5655935CULL, 0x7D748F9CF2A91C7AULL, 
            0x6199F8BE90E8AF5DULL, 0x33F70CB2489E07DBULL, 0x115B8D63FD62E8FAULL, 0x61B29F7DC90D99C2ULL, 
            0xDBA4139CAB6DC233ULL, 0x3A3A6C291844A758ULL, 0xE631BB6505134044ULL, 0x0670A8E89FDC7312ULL
        },
        {
            0xAE0D681869531517ULL, 0x9065AACE99F42CA6ULL, 0xC481B4CE7792B19EULL, 0x0862673DBC319534ULL, 
            0x38A522A5B97F2135ULL, 0xC466A136DA7F7237ULL, 0x54FC1B599AA22050ULL, 0x9E8028383308794AULL, 
            0xBCA451713A893913ULL, 0xBD7E62E19D33507DULL, 0x284D60CC2100A187ULL, 0x71B0E772653C3B00ULL, 
            0xE10AD63B4DFEDB32ULL, 0xD72EF00452597937ULL, 0x8D7DB0A6A8A7A681ULL, 0x1C353A75FDBAAFFCULL, 
            0xF49CF8FBCD34918BULL, 0xFDA5D7B283D07DADULL, 0xAB08DAAF7EDD9F7BULL, 0xFB08A41B665DB34DULL, 
            0x4E6C886035EA510AULL, 0x9C8955465E56E7F7ULL, 0xC4D12AA15FD91676ULL, 0xDAE3DC3E33E4B82DULL, 
            0xF0BE2DDED13F8556ULL, 0x999AA4FF7CC37204ULL, 0x4723D1353978B382ULL, 0x55EF0C7EBA852109ULL, 
            0x81C823359342AC28ULL, 0x2BE435A5CFFE50A9ULL, 0xDABFE197AF8F0E4BULL, 0x3088C2A9B7BCDD9CULL
        },
        {
            0xFBE37E17F8CF350DULL, 0x123300D766584427ULL, 0xFC0E3B3821C08100ULL, 0x36CEA6362ABC7905ULL, 
            0x0F0A563A4465722FULL, 0xA38F1CF9A4EC6181ULL, 0xCDDF76EA14CFA2F4ULL, 0x98FCF38DEF0DB705ULL, 
            0x4BF4902AE34AE9B3ULL, 0xE31FD55717EBA888ULL, 0x40909229BC95BAEBULL, 0x427A58859938E57FULL, 
            0x30B6804DEFB66426ULL, 0x6F606684651EA8CDULL, 0xD67F8080E80903B8ULL, 0xD5913AD6A5CA5525ULL, 
            0xF3D187A8E6366484ULL, 0xCBF65B3FDB438BCDULL, 0x2716B97370B3B58CULL, 0x70124B8896904FBEULL, 
            0x6E27E9DB5456EE74ULL, 0xD8046BBF44ACF5DCULL, 0x6284DD33E4FCEB36ULL, 0xF7777C1691CB932AULL, 
            0xCD84CE99157B55F4ULL, 0x76111A548C05A132ULL, 0x5B9750EF3EFE587BULL, 0x654C198472FBC8FCULL, 
            0xE14297AD1835ED50ULL, 0x1DCBA02B18629669ULL, 0xC6B48DB701E04F2FULL, 0x5CB7560A030E1B9DULL
        },
        {
            0x565A4486C4BF8FCBULL, 0x4186C3EC8464F6D1ULL, 0x5FD5CAADB4CDAFAEULL, 0x78A3611D74CE3493ULL, 
            0x75E709FAE459741CULL, 0x5FC988F6597C1C00ULL, 0xBC07A24B0D207B05ULL, 0xD1F3DA3F20E5DB59ULL, 
            0xB7779CB27138D392ULL, 0x099E389146903277ULL, 0x27BAB62AF45A4B52ULL, 0x0B74F38A913B6AF1ULL, 
            0x4385BCC3EC65DBFEULL, 0xD2E83CF302E4EF59ULL, 0xC323D41C28F3F495ULL, 0x5C54B5C4F1DB3606ULL, 
            0x945DC3E28483D430ULL, 0xE92CD162CD77806DULL, 0xD57CCDDC3ABC3C3FULL, 0x3D911088A599D440ULL, 
            0x50F7844C21C1C3EEULL, 0x3D9F645D656D8FE9ULL, 0xD763E7C24A2223F9ULL, 0x3FB186170C27122AULL, 
            0xF9CFFCCBF13405EFULL, 0x1104F337CBCEF5F9ULL, 0xCCBE944CFA700996ULL, 0x9A91C22B721DB19CULL, 
            0xF82FA2BCFA3C5794ULL, 0x36BD78EA8351B09FULL, 0xF4A49B07834B0860ULL, 0x8A78C60137CEE591ULL
        },
        {
            0x8CE7F881FF71755DULL, 0xCEECFD1FC52199B9ULL, 0xF1D987ACD456EA5DULL, 0x8CF9FAB98E517381ULL, 
            0xBC5AD011F635C1E2ULL, 0xD192170C712355F4ULL, 0x378362635E2F700EULL, 0x9914EABBC42F750FULL, 
            0x5F1359795FFA79D0ULL, 0x283A2327685A9EB6ULL, 0xB30897C28AF8729FULL, 0x4146FA898640F4A7ULL, 
            0x7B60D1FC20A005EAULL, 0x312D9E646D6DB034ULL, 0x6B4F149871C5354CULL, 0xEA9C4472F979B7CEULL, 
            0xCB657915D7F9A6A1ULL, 0x249CD99163770EF8ULL, 0xAD49B7BC8E1DD3F6ULL, 0x15337A06C9D8EF65ULL, 
            0x4CF51F92BCE990BDULL, 0x6F6F3ED27FAE0639ULL, 0x22871497169736E2ULL, 0xAFFD7A5138C0255EULL, 
            0x9F68CA45861E8E75ULL, 0xB382E69C23F2DBE5ULL, 0xC327950B51A815E6ULL, 0x6C207EFE9AB9EBA4ULL, 
            0x1A795745B65B251AULL, 0xA569606497477355ULL, 0xBD60018C6CDFEFBEULL, 0x667CF9F5ABF1BBF3ULL
        },
        {
            0x04F1823B6A83FAF5ULL, 0xA085A2B62E044ECCULL, 0x8C6656FC0657CD94ULL, 0xC67048930AC257C1ULL, 
            0x37127D5219564EF9ULL, 0x2731278EAFF4C639ULL, 0xA97D8034A5C36B80ULL, 0xBDA02E9CC3BE143EULL, 
            0x973E8266B56F9963ULL, 0xFEC7095A718A3ED2ULL, 0xECA959982C59065CULL, 0x6E3564539705F562ULL, 
            0x05BFC442905D2398ULL, 0x89F1557CCB4D73CEULL, 0x18327188E640069AULL, 0x223DB2A983101336ULL, 
            0x5CAE0385067A9D19ULL, 0x36CB05FBC48D9E2AULL, 0x0A50337E5AF3ED73ULL, 0xF04F6783580644B2ULL, 
            0x3AA5A6A922D99FB2ULL, 0xC3F6E5A85C8E840AULL, 0x73F6B0928FA5F9CAULL, 0x03D09944E851BC04ULL, 
            0xA45B017901B51205ULL, 0x62220C9EA83B2CAEULL, 0xA33B65E17ADE1315ULL, 0xE88602AA99F994DAULL, 
            0xBB50B3E1AE72BC4BULL, 0xD128D3B8543E7070ULL, 0x705E97077C893EFCULL, 0x5B7A9BDCC6DBD0BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseAConstants = {
    0xDD386064557AEE80ULL,
    0xA86A5E9A5165F404ULL,
    0x577A7643233A761FULL,
    0xDD386064557AEE80ULL,
    0xA86A5E9A5165F404ULL,
    0x577A7643233A761FULL,
    0xC6B7AE33667DF503ULL,
    0x3F98A5CAE4FB0FD6ULL,
    0xD5,
    0x64,
    0x75,
    0xF0,
    0x4C,
    0xDD,
    0x66,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseBSalts = {
    {
        {
            0x75C752988714367CULL, 0xA3EDBE2C9AE34F8AULL, 0x53BB35BF177A4F7AULL, 0x8803C20D7702A4BBULL, 
            0xA4256901512F9CFEULL, 0x01B60B604A43F986ULL, 0xD6FE7BCFDD5554F2ULL, 0x16256632BDD55ED1ULL, 
            0xB1593812FA8B7589ULL, 0xA1729AB764057CBDULL, 0xE37A901CC7AFD8C8ULL, 0xCDCCCB513D73CE61ULL, 
            0x9BB2B22BB8434A56ULL, 0x643CC690183A4A22ULL, 0xA758E5FA137E21D6ULL, 0x0E0FB5E3D1FCAAC7ULL, 
            0x5AB9FCB4C3BE3041ULL, 0x39ACA361B3ECA9AFULL, 0x2BD3E4F097F936A7ULL, 0xF384B25318EAB5BEULL, 
            0x80BEA4B97521CC64ULL, 0x4B922DED67B2D502ULL, 0xBB8C0640B9D691C3ULL, 0xEF516BC7A6E952EEULL, 
            0xF6856B0C16E04A11ULL, 0xFCF6ED1D1080D489ULL, 0xCDBC84B1F6B25954ULL, 0xCD21F6E3A356F753ULL, 
            0x1402FB832BD94CA6ULL, 0xD5B408A860B0FABFULL, 0x7D6A651D8A7C6B42ULL, 0x516B098B8C664D48ULL
        },
        {
            0x12F600C685405E60ULL, 0xE2CD59CFCC2EFF10ULL, 0xE2DB08AC7F8C5738ULL, 0x574255CF01740F9BULL, 
            0xB7D992A7D32DF3AEULL, 0x1CE5AE955FF58935ULL, 0x6DF5DF3E523F832BULL, 0x7F17D60F8E1DEEADULL, 
            0x367D5BD6BC4B9692ULL, 0x7DBBEA1A97825998ULL, 0x3B7ED0F6321BEC97ULL, 0x1452CB25058CDDBDULL, 
            0x62F0AC8356DC559BULL, 0x423B58486268E256ULL, 0x5C563F09C2C8CD57ULL, 0xD631FABCC720AE63ULL, 
            0x77503F5025B4F16DULL, 0xDDF07812C43A4CE8ULL, 0xD791B7CE29947459ULL, 0x17F8AA0A094E8322ULL, 
            0xAF540C17A6FC2CABULL, 0x0303D0CDD779FFBCULL, 0xB36E9E0C57929D76ULL, 0x0ED597541F2C66C7ULL, 
            0x31DB11E7BC1D3A9DULL, 0x58C821B81DCB9EE9ULL, 0xCCE188D6DE6D5F19ULL, 0xE66A9DDE5555DBE0ULL, 
            0xB69230C438A8A8DDULL, 0x4E1685469FB5C39CULL, 0xA416D85348CB813FULL, 0x24DD805F68C18101ULL
        },
        {
            0x16C0C38141E9F974ULL, 0x4197A59AA324674AULL, 0x60C2698CC2390809ULL, 0x96E15D7B2963B092ULL, 
            0x88C8CCF516FA8A8BULL, 0x10AE249462EA7F68ULL, 0xADD55B03981AC066ULL, 0xAC2B6A62C59A0ECCULL, 
            0xD76A9E1DAD9CD660ULL, 0x6BD38AEB9A43C0CAULL, 0xCBD2874F2111E722ULL, 0xDA214FD90902F88FULL, 
            0x0F0673B889793259ULL, 0x6D64A85AF78F8D34ULL, 0x45BD20A7FEA02B50ULL, 0x2F5C2575E41EAFC3ULL, 
            0xA748863CA421CCBDULL, 0x4FB5395335F9724EULL, 0x4864F459E39B77CFULL, 0x3424BD7841C52A5AULL, 
            0x7989DEA72EF046B1ULL, 0xCB164CA2A9A4D1DDULL, 0x35AAEE75EF8A0E71ULL, 0x40B5AE839EA39658ULL, 
            0x7BAFCF26B79A7C81ULL, 0x99F881E9332245D6ULL, 0xA01669A7B90A8162ULL, 0xF7C31462E0DF46EDULL, 
            0xE814D26121F84BD9ULL, 0x21FEE7BB517CF1A7ULL, 0x1C2419DF13A8501BULL, 0xD03DF36C54DB463AULL
        },
        {
            0xFC9168D3873274FAULL, 0xE3DB2ACF32689194ULL, 0x78A2684C2CDCDF63ULL, 0x7616C9E976F02376ULL, 
            0xF5A5C263EFFF5C19ULL, 0xE93BA40B8A07865CULL, 0x33E18CD99AB81FC6ULL, 0x1421C1B8BFF08336ULL, 
            0x7E494BEBB1C39D52ULL, 0x0C950EF6861D3D4BULL, 0xF2222BCBDC65D3B1ULL, 0x873431715072F679ULL, 
            0x885753208581C16CULL, 0x0ED037194E6E949FULL, 0xA523C7CD08B2903AULL, 0x760616D1A74F1C00ULL, 
            0xDF420DD24A68F25CULL, 0x2BC359186CA3BA87ULL, 0xF9F198C20454D466ULL, 0x91942691BBA3A2DFULL, 
            0x06E15D3D09D03AB4ULL, 0xFA856355EE5ABB88ULL, 0xC41A8147CB3E0D38ULL, 0x3E3F276BAD70C8F5ULL, 
            0x9BB96A21A1A23243ULL, 0x6626A62B694771E4ULL, 0xB4F9A9BF3008B59FULL, 0xB6571CE6BB145429ULL, 
            0x7CE8A81EBB9F20C1ULL, 0x690B0F11E73698F1ULL, 0x1E1299356466698BULL, 0x8679ED0827EABA38ULL
        },
        {
            0x76E6036BBE02289DULL, 0xE8BE36D21C659385ULL, 0x9E0A50CA65D37B51ULL, 0xE17790AAA04AD67AULL, 
            0x40C335FDD0D9CD4AULL, 0x7025DC9EBC310C19ULL, 0xD11FD889B628BEF4ULL, 0xE8D04EA20401F3ACULL, 
            0xAD1CD2F8A3DA1795ULL, 0x22D5126B14E76E77ULL, 0x4EC03F9868F3A1F9ULL, 0xC9EE6928FA0509DCULL, 
            0x85B2265E66B0227EULL, 0xC47F9BC5BF91133AULL, 0xFD21AD37F7612A05ULL, 0x9B91718128EC8A13ULL, 
            0x8638FC5FC93FD939ULL, 0xE4C50131553DD346ULL, 0x2D1BF6E84583959EULL, 0x43F4E2FF4D8197D9ULL, 
            0x9E2B70FDC1CE8CC0ULL, 0x61A728EDD6F76A8BULL, 0x6D5C20C2C3489C82ULL, 0xE69048BE3A69208FULL, 
            0x78B43AF6F139CFA9ULL, 0x11AE574476E9C7C1ULL, 0xAB5C64806232AE38ULL, 0x3E1148C5DFB6B09DULL, 
            0xFF7D7B8768ABB431ULL, 0xFB72C5EDFFC2C1B4ULL, 0xB9334DD75E3B3C7DULL, 0x93090458D4FAC39AULL
        },
        {
            0xE9B5CEC9AFF8A4B6ULL, 0xF5CA606C905420F8ULL, 0xD81C150BFA0B0537ULL, 0x2CCA55EDB1F87121ULL, 
            0xFA24FA27F3B331BCULL, 0x5D9F2CB8742B03E4ULL, 0xC07FE1D1F25FEE51ULL, 0x849FB52EE1CDC2BFULL, 
            0x9E978696511EA6E1ULL, 0xF5891762F1D1F6A1ULL, 0xAFD136819D3927CBULL, 0x7974C7150592A4A5ULL, 
            0xDA56E63EAF29EB02ULL, 0xF056985FBCA71A6CULL, 0xF3A1E52E4851AB47ULL, 0x02C0BB01CCB277ACULL, 
            0x566E18DA1D1457ABULL, 0x5489F809D4A0A290ULL, 0x4850FFA3D4D64CC2ULL, 0x45C70BCADEAB5715ULL, 
            0x1872465C184B0E96ULL, 0xDE96EB3DCEE63E16ULL, 0x6BCBE4F192ED03F5ULL, 0x8EA90DAFFB5F0422ULL, 
            0x7A8CB4BC66E8EA31ULL, 0xA853DD2EADCAE749ULL, 0x16FA9033DDCBC902ULL, 0x02267F0C646C0CA8ULL, 
            0x0D0B09B286E4AACEULL, 0xFC3806821D0ED420ULL, 0x3E7C96416C3348DBULL, 0x1AEB169911A2E777ULL
        }
    },
    {
        {
            0x9495823A8D6F7A07ULL, 0xDAD7C10495F9BCF4ULL, 0x4A1AA910234FDE79ULL, 0x1404454487ACC678ULL, 
            0x4DA8F16827CEF33EULL, 0x0DE3145CDC6DA089ULL, 0xC76DB4614FB46314ULL, 0x5828A12D51D7AAA0ULL, 
            0xB3C58F786619560DULL, 0x998DDECE4249E832ULL, 0x962DFEE00967312AULL, 0x2335840E76F04590ULL, 
            0xB5CC471B003FE1FFULL, 0x7FC1239D70B7C358ULL, 0xD2089F5FC6932BBAULL, 0xC18A1D68B81B2200ULL, 
            0x252C1E0B4EDD73AAULL, 0x710252F64CB8B6F8ULL, 0x5E0B237533320776ULL, 0x5F25FBE3D7D9AFAEULL, 
            0x641BB3DEEF4FC503ULL, 0xD1BCBD38286467ECULL, 0xAD79EFD4BAA994BDULL, 0x7E78BC6D74A67A47ULL, 
            0xABD81039788FD1B1ULL, 0xDF7EDC2C77A41DCBULL, 0x39BF6F8978F3827AULL, 0x490689DF3436AEC0ULL, 
            0x6CA340D6623FEA2AULL, 0x0A9D2C2014364FA3ULL, 0x3921D726DDC62B9BULL, 0x06E8FBAB70375298ULL
        },
        {
            0xD939CB158E0C0500ULL, 0x812F30688E4D8B57ULL, 0x6C00CE1203048554ULL, 0x4535214A52C7C74CULL, 
            0xCBEFF2465D151D10ULL, 0x375A6D7403B7702EULL, 0x3E7DAB668F0E269CULL, 0xE46633A0E5D13343ULL, 
            0x76A81E947BF90D17ULL, 0x3FCD371962E00BC1ULL, 0x0A0A2DD5A512DC6DULL, 0x2944C592C60C20A3ULL, 
            0xCE54F0EFA947B9F5ULL, 0xB635BF63DBACA77BULL, 0x1E8F091E04050ECCULL, 0x3E418AB913C924E8ULL, 
            0xCA3A8DFD8FFAF4B1ULL, 0xFD8DEFE3295A7885ULL, 0xD8D89FF2A8443EF3ULL, 0x4D3692C85AC69CEDULL, 
            0xE651DB2EB83D42D9ULL, 0xDB6A388327052F6AULL, 0xB9B3DCE43D074D7FULL, 0xEF61871DBCA62905ULL, 
            0x3A02B48F83FB6CEDULL, 0x81DBBE2203A3ECFFULL, 0x9287E8FF442531C1ULL, 0x4B857D7767D8BE11ULL, 
            0xC84936B81C42F6BEULL, 0x07BB92FD21103794ULL, 0xAC248D943D8ADDFDULL, 0x74961BDD958492A5ULL
        },
        {
            0x0A5D93980C9C3836ULL, 0xCEDDC9EB3920011BULL, 0x8FE1800A6A94FE57ULL, 0x15BA14BA3786727AULL, 
            0x9F83D03981B83C5AULL, 0x86649DDE90DFC306ULL, 0x232B9C8FE19FC6F6ULL, 0x1A8EC1CED1FF1603ULL, 
            0xCB7E5AF620B18DA0ULL, 0x3C19A9DB31BC5FCBULL, 0xFC5E9EE8933C9BC3ULL, 0xDF9DA136F3E7013FULL, 
            0x1DA6DB8E6D812834ULL, 0x39638935AA45FA9CULL, 0x382D4855925489BFULL, 0xE3645DF57F41B40CULL, 
            0x70795E0363798FAFULL, 0xA7C71743BF5EDB00ULL, 0xB1545F129FAE642EULL, 0xB132EAFE0CC281C8ULL, 
            0xE2133AA21EE4B2CBULL, 0xC261D652C6919A11ULL, 0x8215C949662FB860ULL, 0x4AD73BBDF9CEF6B5ULL, 
            0xEA686F7E3EDE6709ULL, 0xE6B3870BCCB38CDAULL, 0x64BC1D14322A181FULL, 0x7C6364B0983AF103ULL, 
            0xA8D8ACA998B44A9BULL, 0x3FCBDF68C4A40ACCULL, 0x97A44B094B751D73ULL, 0xC12A96A94FC75FBBULL
        },
        {
            0x3D5A48862EB45032ULL, 0xCB0B6E6D8F92EFFAULL, 0xE3314360612A415CULL, 0x16D53DA99F99F38EULL, 
            0xE5900E9DC446EC20ULL, 0x2CD868FB012FB3EFULL, 0x3E1D7372CF1698F2ULL, 0x2B04043B4649974DULL, 
            0x4C08EC8F08CD1258ULL, 0xFB12CAC7C792E93FULL, 0x3BF8C8A811AD272EULL, 0xCE9F5E502F577471ULL, 
            0x34F7F76F7209ECE0ULL, 0xE60A155B2B7305E3ULL, 0x3EAFF799A3DF950DULL, 0x6725487146022DACULL, 
            0xBF47737A29DB8CFAULL, 0xEA01A8803B20BC0DULL, 0x8C6548DE48A69BC7ULL, 0x2DF92D0E0A92A818ULL, 
            0x749FBB40A3A2EBC7ULL, 0xB2107D853C5B10F2ULL, 0x9236B5CE424E3E48ULL, 0x534867500FABC46CULL, 
            0x21E8D2673EFB7E6AULL, 0x03F30C73ECA4D3BEULL, 0x946998309BC0E31FULL, 0x6F812521558D09BEULL, 
            0xC7E931B02CCA3601ULL, 0x6D6506C83C605BB7ULL, 0x1EF3A57DC6E90B61ULL, 0xBDFF1185AD75913FULL
        },
        {
            0x13989D72C26D0172ULL, 0xFFA7BF3A791EC3AEULL, 0xD0C86E6B7F30416CULL, 0x3B05E072DCDA9D24ULL, 
            0xB3430DA40EDE2F0FULL, 0x7D1338865A86D28DULL, 0x07E1A0F3CA4FB671ULL, 0x6B6E7ED76A6AFA35ULL, 
            0xC5E8F65391207559ULL, 0xF2C8E33AC406D38CULL, 0x0F53E9BB32EFCBF2ULL, 0x9FCAF3E10BE70025ULL, 
            0xAA520D36DA197B42ULL, 0x5720043AA8E75923ULL, 0x59634AB95FAD92D0ULL, 0x52ABEA03799B8503ULL, 
            0xDCC52A4D93580E4CULL, 0x2721F68A080DC86EULL, 0x23EAE048597F6D2BULL, 0xD5A325F4CE11D641ULL, 
            0x7E2D325E1283F7A2ULL, 0x27BFD88CAE552E7DULL, 0xB42B135E8D67DAB1ULL, 0x1E03895D03B9F9A5ULL, 
            0xFE85D86C3FBCE566ULL, 0x74575550F4C3D41AULL, 0xB42816BC9AB8EAC7ULL, 0x78AB6BD18358C7AEULL, 
            0xFF34A1234EEFBB62ULL, 0x94838E7EC76E2281ULL, 0x4A6479E1C3691FEEULL, 0x207D032554D484B3ULL
        },
        {
            0xCACF7CEB0E2A87BAULL, 0xAA833DC5C9D7066DULL, 0xB04571F1EE7B9739ULL, 0x678A754256F5B84AULL, 
            0xCF4F901A6F50E35AULL, 0x666390D928D85200ULL, 0x55F68050A517FDEEULL, 0x8D64FDD855DB6FBCULL, 
            0x52CD33822729AB02ULL, 0xC2FED1CDB2B78178ULL, 0x173C36FC9FA4CB24ULL, 0xC5E3BD15C849A993ULL, 
            0xB833A407D6AE222EULL, 0xAE71E7FE785717D4ULL, 0x406DA1CFBC5D9BDBULL, 0x446A0CAA90D1C132ULL, 
            0x8E783429E776CE5AULL, 0xE3F6E4C31466CE1CULL, 0x80CDE5C044A0AD01ULL, 0xAAAB60D658EE5368ULL, 
            0xCFA6C3B610C8F1A3ULL, 0x25E201D8B5731851ULL, 0x724B30102B15A277ULL, 0x700C4A3481FE5A3DULL, 
            0xDE044E1E09BE69C5ULL, 0xAA25A94F2661B0DAULL, 0x6CDAE9E90F7E9F2EULL, 0xDB81BFF2021457B5ULL, 
            0x3133F5DA8B597A87ULL, 0x80B7B64DC339A6EAULL, 0xD0F2AC201C806BB9ULL, 0x7555D29C76DEEF7CULL
        }
    },
    {
        {
            0xD7D0E4A94CFB947AULL, 0x936CACE572E14F41ULL, 0xB8B356093E38ACA6ULL, 0x23EF6090980AEEE8ULL, 
            0x6EDE17B342DA483EULL, 0x539DA93224D66EFEULL, 0xBC4C2C8310D46451ULL, 0x403D20D63DC94A6CULL, 
            0xC61FD59F2F2B81B5ULL, 0xC3DEF3E66D243666ULL, 0x0B3514620C48A0B8ULL, 0xA31752DE9049FB03ULL, 
            0x94A324B5EC37983FULL, 0x8752349541632EB7ULL, 0xBD6A9778AE700B58ULL, 0x7830477F3E2644DDULL, 
            0x934E6B679339BB83ULL, 0x4A9C817792D7F4B9ULL, 0x9E8FC824C251D696ULL, 0x2E050F6A69475A78ULL, 
            0xF0B9AF926EA38665ULL, 0x3E2D7E7637344E04ULL, 0x6C8F2550BC2FB3E8ULL, 0x413B56A4CA095068ULL, 
            0x9045C78A563BA715ULL, 0x9BF493DF03CF173FULL, 0xDB4E9599F3DEBC99ULL, 0xE866DF9FBC8398A4ULL, 
            0xD8F37EE936219680ULL, 0xAC93F976F8146794ULL, 0xE6230A1D0E694A1AULL, 0xF3B31017EB5EF6DCULL
        },
        {
            0x54CD2CA24A2D2A7FULL, 0x9BDF79304E392F1FULL, 0x8ED8F65B2229A98FULL, 0x39C350205BC1399AULL, 
            0x3BC2596725AEE3BCULL, 0xEF52B0E973BE2E30ULL, 0x2EF3659EF5D23535ULL, 0x6B4912D27C70C779ULL, 
            0xAB797F72F0A30E11ULL, 0xC929A0870C04347FULL, 0x63256E5C9A6A8B34ULL, 0xA07E3FB904847670ULL, 
            0x5679741DA6761796ULL, 0xB1C7532F1FA8E2B0ULL, 0xB9E9A4F2AD0E4EBFULL, 0x254091DA9BCAAB07ULL, 
            0xF0C01BDA6320B482ULL, 0x6D38AF27ECDDCFD5ULL, 0x8153C150B3FA339FULL, 0x66890DB1E6CDBCBEULL, 
            0x3AB672B61465F288ULL, 0xD958391243833E72ULL, 0x999082C910752466ULL, 0x72C60BB0E85AC504ULL, 
            0x252E0E3CB6E046CAULL, 0xCF74A48946E0893EULL, 0xBD6C643407DAD7D2ULL, 0xF3E894D226C8BFCBULL, 
            0x73447C413DCC5AA4ULL, 0xB46123D8CB5CB161ULL, 0x03D4FD176B2FC38CULL, 0x00F43CA22B2ED29DULL
        },
        {
            0xC67081F7DA708A5DULL, 0xE5D302B988001453ULL, 0xE713C7CA8266A407ULL, 0x6CC8A567A70A13D6ULL, 
            0xB31282484C100D02ULL, 0x7A5FC47122174642ULL, 0xC69497BB1B814A7DULL, 0xF8A29EFC2CE8E67AULL, 
            0x2CE47FA9A098C83FULL, 0xEB9DE69BA82A2C22ULL, 0xB58CF262DDA442FFULL, 0xBC22EFCC42F9C306ULL, 
            0x8AB2B0477EAE34D6ULL, 0xE4EB2E8F3902E661ULL, 0xB42F3B0BC2B9E911ULL, 0xCCDD3FE998428019ULL, 
            0x1D57DB14DE1A8018ULL, 0x91418CAF7965893CULL, 0xC3CA87694BD3B8BAULL, 0xB6E59513154AC008ULL, 
            0x8C85198E4FA40482ULL, 0x2107B654F18C77FBULL, 0xA4B37DD41AC477EDULL, 0x044BE65AE3D30659ULL, 
            0x3697122DB624F71AULL, 0x3F36DE47526AF9D0ULL, 0x3805EC4D796D21FCULL, 0xE984FB66ED570ABFULL, 
            0x6AC6739051D188E7ULL, 0xE9CF38347CCEDAB9ULL, 0x0C43F5379360B4B1ULL, 0xDCBC81571A33F8ECULL
        },
        {
            0x266E8FC71A071208ULL, 0x00DC2432CDDDD57DULL, 0x2EB86B56A4C3BFEAULL, 0x2E6B248417B9B1D1ULL, 
            0x8B38C8CBD7F3F402ULL, 0x6DF9B4CB22C613F4ULL, 0xF31553197A61ECF3ULL, 0x1ECE15A667BFDAABULL, 
            0x8E085ED6486B185AULL, 0x25738EAB064D8208ULL, 0x6EDFEF6BF92D1A11ULL, 0x66A3E33A0479137BULL, 
            0xC15DB26FC0EE70B3ULL, 0x9B59829B7477E91DULL, 0x2A8EDE8CE4255742ULL, 0x197EC1C86E6C0768ULL, 
            0x818737C0CF541AFCULL, 0xD46ED57BDB4EA445ULL, 0xB76F0737C40ECAD5ULL, 0x35DB3F7BEB841079ULL, 
            0x03E9792272864F2AULL, 0xE87105E92693ACF7ULL, 0xA36AA08052EF9169ULL, 0xE95FC51D08234FB1ULL, 
            0x1327DD699BEA5484ULL, 0x6C845E9554ADCCE1ULL, 0x3C45474012977C7CULL, 0xE6EF53B9D4DD8B46ULL, 
            0x466238F93102070EULL, 0xEBEBB444EADC9270ULL, 0xEE0E2CE734994DDDULL, 0x32C3C198C0ED69D6ULL
        },
        {
            0x786CF8F61690E2F9ULL, 0x381249DE539091A9ULL, 0x90D00FB25B514CEDULL, 0x936D4BC1AC448AA2ULL, 
            0xDD9D3B392533A1EEULL, 0xFB0967C223555341ULL, 0x8982BA7683B88297ULL, 0xD1DD35FFEC966705ULL, 
            0x5A79C7B9964114AFULL, 0xFD25138026759702ULL, 0x0033FAFFCA2943EAULL, 0xFBD26EBF4CCA8ED6ULL, 
            0xDE303EF79D92F1B5ULL, 0xA06CCB9AC45FBB7DULL, 0x48420B138E51B508ULL, 0xB3F2573AD23CD115ULL, 
            0xA6F039504FE01365ULL, 0x58CA38E3959C201CULL, 0xD1B63B620E4FB4A1ULL, 0x558CA8FBFAF58218ULL, 
            0x7093AB9D4D32F4FEULL, 0xA1404589BC053C52ULL, 0x8CD3F4E352B1FF30ULL, 0x28D3552CA9DB59D9ULL, 
            0x5DA856AA489F4ED0ULL, 0xF1C1E431A48115FBULL, 0x4329F9B13F71640BULL, 0xD4649D0795E1C606ULL, 
            0x7B7FC3B8129E83EAULL, 0x6B695DC23852C5BDULL, 0xFEE88E5013125CA7ULL, 0xF3BEAD7A4E452F7CULL
        },
        {
            0x017FB6A3407BFF6DULL, 0x1C8DAEC9C1089042ULL, 0x73F82860CC1285DCULL, 0x46B4B7EC1E8BD002ULL, 
            0x601FD9E214B9937DULL, 0x75D4A82753F86A32ULL, 0xDBF21C078EAB5E20ULL, 0x2079F3998CE4E479ULL, 
            0xCF125E0B9C67EBDEULL, 0x3BBD3ABE3FEDC649ULL, 0x2CA63AA03947D0FFULL, 0x39C84F946BF67404ULL, 
            0x2FCAEAAB9E527A0BULL, 0x153560FC63AC7978ULL, 0x092E6D5C20031640ULL, 0x892A289103760404ULL, 
            0xD48D9EDAB84E114BULL, 0x231BB4FE2CDD0105ULL, 0xF6CB4361D99FE448ULL, 0xEC8E154DBF208A2CULL, 
            0xFA84F3985DF6F0A6ULL, 0x68C14ED1997E8CA8ULL, 0xFE9F05162706F285ULL, 0x761F160E3B745163ULL, 
            0x4D932B751FE2AEE2ULL, 0xA4AB6AF8C7E92726ULL, 0x10FF750AF7F70722ULL, 0x1A5874676AC4BC45ULL, 
            0xF36B35B35A942258ULL, 0x08BD28B6B0EA5DF1ULL, 0x6D52A2FC85594C8CULL, 0xA49C94F3B9B637F3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseBConstants = {
    0x9FE7599FE3B1BAFEULL,
    0x9FA510F34CDA61B8ULL,
    0x601C2837E258CC75ULL,
    0x9FE7599FE3B1BAFEULL,
    0x9FA510F34CDA61B8ULL,
    0x601C2837E258CC75ULL,
    0x2B3D1188DCA5FC5BULL,
    0xE38DA2C32866A5C9ULL,
    0x39,
    0x70,
    0x40,
    0x77,
    0x3A,
    0x20,
    0x9E,
    0x67
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseCSalts = {
    {
        {
            0x6A5E5668C2B91172ULL, 0xA09D04A5036ECE54ULL, 0xE8426845B5C093ECULL, 0xFB7513D71772A86BULL, 
            0xF7154908DEA8FED6ULL, 0xEBF3D8B8E0DF1FE7ULL, 0x7D21C99110F9DF56ULL, 0x1A7138136750EA67ULL, 
            0xDD889062421A79D4ULL, 0x508865711F4B2127ULL, 0x8F0CDA0918EF1AEFULL, 0x5D242DE9655E364DULL, 
            0xC8BA9B46E24A292CULL, 0x0229C35AC2173A6AULL, 0xF085ED6942646D33ULL, 0x0D0616A2006DB9D3ULL, 
            0xD60469C84364C918ULL, 0xAD9C6611543090E9ULL, 0x86F1BA4213280E9AULL, 0xBAC436F9A8504522ULL, 
            0x0580ED34CF9DE12FULL, 0x383BC1EA4AA6640BULL, 0x932071EFC31AEF86ULL, 0x5B60D33A2AF67ACEULL, 
            0x9EA6C78E8A7B659DULL, 0x0BCEE0294C51A664ULL, 0xD9F43D2D51715BCCULL, 0x4E0BC021DBCB9A61ULL, 
            0xA8A434001B666E71ULL, 0xF9D78BFB41ADEC30ULL, 0x25143A6BFEC5A03CULL, 0xED34BD0CD9C02138ULL
        },
        {
            0xFD105A23A59083B8ULL, 0x7ECB726D729052E2ULL, 0x7D7744957AFFBD7AULL, 0x6C081CC44948C659ULL, 
            0xEDB4CDD7F3441A49ULL, 0x128CA9698638FEFDULL, 0x3391A50AB003C9EDULL, 0xB2939C80339C167EULL, 
            0x4BBB2598A73F45C2ULL, 0xF0EB44533AE62426ULL, 0x1A6B1977A7EF219AULL, 0x51B26863071480EFULL, 
            0xE85DB448153919C4ULL, 0xCE16BE1A5F7BFC13ULL, 0x26E0D713CAF1446BULL, 0x5ECFBBEA741805D9ULL, 
            0x99AC0C812D94AC51ULL, 0x276BDF2D84F54551ULL, 0xC2CA518A09E04F9BULL, 0xF15109E62EFE004BULL, 
            0x3DDB7E985E6843FEULL, 0x782E40216726A2DBULL, 0x65030A58960F846AULL, 0x55B434BAEE2FF579ULL, 
            0x8C3F44F83FC3528CULL, 0x4F993C5CAFC79049ULL, 0xC6AB06B20F097375ULL, 0xC4D76BC2168B1E38ULL, 
            0x351EF84BAF36B0ECULL, 0x59BF15DD498E3BB9ULL, 0x9006F75B6AACF456ULL, 0xE06C96049FC6C063ULL
        },
        {
            0x5577B53A5BA4FF82ULL, 0x8C0B8838C853CFA5ULL, 0xD374436802C4419FULL, 0xB52281E121E12A8DULL, 
            0x328E139C122C30D6ULL, 0xFAB645EFF42CCCDCULL, 0x64B6DF84B6B620FBULL, 0x0CCD4E90F1F46221ULL, 
            0x476C3FC4AD1C56A3ULL, 0x6B2DE36CF3F583A5ULL, 0x566823B8ECA493D4ULL, 0x3D039B8422A73942ULL, 
            0xDB7CD4416BDF3A45ULL, 0xE9FA2E5F83BF80D6ULL, 0x4B8730E9F5908F3CULL, 0xF3752D521FD26E48ULL, 
            0x35ADAC126C17D477ULL, 0x1BA30F93D385AF7AULL, 0xF5AE63732D6948E9ULL, 0x560D8B8EA0DE233FULL, 
            0x3E21E6C7D835146EULL, 0xD712267462A1ADB3ULL, 0xFF25BFCB26F58DE3ULL, 0x31876AEC0C2C1545ULL, 
            0xFABB585B54ECA444ULL, 0x79DE2E1793BDBBE8ULL, 0xEB048C68CECE8458ULL, 0x5B1FFC54E24E2023ULL, 
            0x45457860EC7ECB99ULL, 0x54E0CE7B5FCD33A2ULL, 0xDAD76F0F9C5E5837ULL, 0xA2520EFFF5082E71ULL
        },
        {
            0x740F89963BE9A883ULL, 0x544A602BA78DCF75ULL, 0x01E982775C27A2DEULL, 0xC1B8A0B98C120536ULL, 
            0x7D9420122AD848B2ULL, 0x562755654FF46424ULL, 0xEB94956B8E80A0BCULL, 0x87AB313E61FEB067ULL, 
            0x6D222BF499D8D21DULL, 0x4D49B3E21CD1EAB6ULL, 0x523741A6D2FE8596ULL, 0xD01535B7940B580DULL, 
            0x39E2057417A722F5ULL, 0x0CFAE811612785C7ULL, 0x3683C7E5A6D1EB6CULL, 0xC65A1035C5E1F765ULL, 
            0xDF90DF7C9F091BFAULL, 0xADEF2654CF13C42FULL, 0xF744B534638C6DD7ULL, 0x536161FAE840A607ULL, 
            0x7618B3EB6F66A7B4ULL, 0x7012A8D172E9F721ULL, 0x353259D40FB5BCBFULL, 0x8C33875F17F89DC0ULL, 
            0x674D1755CC716034ULL, 0xF82B134DDF36A1AEULL, 0xBC7B5FC305EB1BF2ULL, 0x615CF2128E1081F6ULL, 
            0x110EE7A30E485251ULL, 0x3BCC03BBA746804DULL, 0xE9AC74CCEDE09564ULL, 0xE2C7491DB1E544D9ULL
        },
        {
            0x81E6E13E73AD3FDFULL, 0xFD2FF0F3A81EEA40ULL, 0x0FBEE8EC25097092ULL, 0x2E85528150461EEBULL, 
            0xCE848BB14C9E90C1ULL, 0x212E6F8A86C8D8AAULL, 0xEB63E2AA0B948EA2ULL, 0xE782A1375C1EFB6AULL, 
            0xD97E2703D7221BFEULL, 0x23BDB81140FF6244ULL, 0xCA7561893B1C494FULL, 0x250CEB50FACE0085ULL, 
            0xECF263570E2B4A3AULL, 0xC81BEEA723E40F94ULL, 0x73C3DF100A69905AULL, 0xBCE79E4ED858166BULL, 
            0x862FA26F218FA12FULL, 0xF2DA8A5934C8C75EULL, 0x7CD2C1CAB6FD2056ULL, 0x848D55EA637DCC64ULL, 
            0x0F2447C9C56480E4ULL, 0x62C3B7FA2A86A2CCULL, 0xF15D794FE535AC05ULL, 0xECA4EB78EAB4D1A8ULL, 
            0x12694F7E38BCE9BEULL, 0xF08863D42BF4A537ULL, 0xAA910855F151006FULL, 0x013FCDEEF396AFB2ULL, 
            0x7C09F60D382DCC3DULL, 0x0A306276E0FE19EAULL, 0x4CDE8CA00D9D0122ULL, 0xEEA87F59E312B4B7ULL
        },
        {
            0xA390FE90EC9B466DULL, 0x6C8FF65AC870A865ULL, 0x9DF2460DB3EE0935ULL, 0x2D11FFC5ED84CB10ULL, 
            0x41837CE68ABF4A8DULL, 0x21D59CD61C59BCE6ULL, 0x79A1BEC407988345ULL, 0xC0378902D46FFEA4ULL, 
            0x9126883370E1277BULL, 0x4C2C892E2F76FDE0ULL, 0x2DD82FEB30E67EFFULL, 0xB05AC859BE26A9A4ULL, 
            0x2BFD43DC85B57F94ULL, 0x2003289E479CE97DULL, 0x361923B5E4B7ABD9ULL, 0x8C77C0AA58134A5DULL, 
            0x0BCA702B74BB0D93ULL, 0xF3404A72B0EE2C3BULL, 0xA065A0520E1784E1ULL, 0xF27C32FE2D5EB5A2ULL, 
            0x3867B6D9373CCC23ULL, 0x8CFD60284785664AULL, 0x56F56EA723366A2CULL, 0x7AA280DF120D3841ULL, 
            0xCB55C13511ED6252ULL, 0x98A288360F5203A4ULL, 0xFC98A4F5A0C9234BULL, 0xA844577D4D2CCCB3ULL, 
            0x02E70FD410BBE32BULL, 0x121B57184ECB9AC8ULL, 0xC75837EF6323B4D7ULL, 0xB234901DF2F22F5DULL
        }
    },
    {
        {
            0xE9D0E8DDAA7D558BULL, 0xB3CCDB387FAD026BULL, 0xBEA76735B417A057ULL, 0xB8442CE3C442839FULL, 
            0x79FF613FD0308D20ULL, 0x464ED4AB597D0935ULL, 0x3F8F40EC4FFACDC3ULL, 0x391C635264BAA569ULL, 
            0x7717C7AB1DB275DCULL, 0x8D5778893525AE4BULL, 0xA4AD88D096425E47ULL, 0x2AB0E2A596570AAAULL, 
            0xFE7EADBB37635F37ULL, 0x808A861282282213ULL, 0x0D40653602FEDBB7ULL, 0xBA618FE1CD908D84ULL, 
            0xF862C8174BF468A7ULL, 0xA58715904E511DE6ULL, 0x9E9EB5BBBAD4D1F8ULL, 0x98E15E08492C46E2ULL, 
            0xF3121AB7446F4025ULL, 0x92FC4D51F9C4523BULL, 0x22CAAE73765EB5D9ULL, 0xB316469B5A071CC1ULL, 
            0x4748DD8F639DBDA9ULL, 0x2DF3967AFD1AEC31ULL, 0x8050694225EDCAE9ULL, 0xAD887E89F70B7ED3ULL, 
            0x02780CFBED103997ULL, 0xD009D2A6CF626F75ULL, 0x02BEAA6425F2586AULL, 0x1CD7A6CD008C1AF6ULL
        },
        {
            0x6A8CBC9C9AA91CFBULL, 0x6F2F98E378FB792CULL, 0x2372BB84FFE494A3ULL, 0xC19C2DCF9A89C2F1ULL, 
            0x6CE0F643922C874BULL, 0x17A3926CFC611CCAULL, 0xE4CA0A794B85E1CAULL, 0x7F1F3E619C08368DULL, 
            0xB20DCC7C3F62D015ULL, 0x42E2D033F1735887ULL, 0x3D34A0795183C134ULL, 0xA8230228060399D1ULL, 
            0xA8978C737FE52BB6ULL, 0x50356480360202C3ULL, 0xD29B6EF1823003D2ULL, 0xB65BF6FBFBE79E38ULL, 
            0x9A6B13A427A5F991ULL, 0xB8F00758DE4D53FAULL, 0xBFD400B241A87316ULL, 0xB70D7DF68044D040ULL, 
            0xF3A0604C78DE59A0ULL, 0x13942CDA8F95C67AULL, 0x536539B308309B47ULL, 0x68B7A23BFAF7DEF8ULL, 
            0x3289B0AFAF6A5759ULL, 0xC1714A841FE5F188ULL, 0xB4B9AFE86CDB052CULL, 0x95FEFE6B55FC54A6ULL, 
            0xBC4998E007E09FF6ULL, 0x57F217DC44A37EA0ULL, 0x4748BE0DEB6F58B2ULL, 0xFB0EA51241E8EFA2ULL
        },
        {
            0x5375122793D0D597ULL, 0x46A187A4B843F415ULL, 0x2605402F89A14DB6ULL, 0xBA1B14A21D9EC266ULL, 
            0x6B808E672C210F3BULL, 0x5D36BA8B4DCF920EULL, 0x9CD9161FF496B5D4ULL, 0x9ABF496AF6C547AEULL, 
            0x7F9CA8916105104EULL, 0x3ACE869A0E36DA8AULL, 0xB2F7A2775831A045ULL, 0xDDFFCA6869CF6077ULL, 
            0xF29CA6AAB88E628AULL, 0xBA99C82C732F58B5ULL, 0x4DFB22C747C902FAULL, 0x12EC423F46743882ULL, 
            0x5CDAE04144F122F9ULL, 0x9D4DF2E143BCAA3AULL, 0x577BBE1AE7A2C87EULL, 0x06F3DF16B74418DCULL, 
            0x120D36FCF98BA350ULL, 0xCF7A88C48ABB53E7ULL, 0x10BA2620C3445AE7ULL, 0x997AB90CEDF8BDCBULL, 
            0xC16275192617505CULL, 0x0F96B90087397B3CULL, 0xCA6654BA56309E6DULL, 0xEC6809F3A7D4084FULL, 
            0x350647C0ADD3FE9BULL, 0xC57105E581E64E30ULL, 0xBF0EA1C25DDC5DB2ULL, 0x28FE269C0FBB35FAULL
        },
        {
            0xE0D2CD8AD98F6930ULL, 0xD69A52226DD37AB2ULL, 0x0E8F95381733B37DULL, 0x1ECACAB113AD5AF0ULL, 
            0x5BA71ECA02178271ULL, 0x9DC0C622F893E4CEULL, 0xB4742F9B0F778079ULL, 0x4502F1DDF8D42D4AULL, 
            0xF808CE7D7DBC0E5EULL, 0xACE998E3E467727BULL, 0x05313B768D16AAA4ULL, 0xA288814DCBF5FDD2ULL, 
            0x56E729056966D5ABULL, 0xED63EC2699AF6CA5ULL, 0x7195747BD37A94E6ULL, 0xC75698EFDF5C7447ULL, 
            0x3F559A35F139CA7FULL, 0x51E6E7B132E1ECE4ULL, 0xE60D899A8DFFA918ULL, 0xB63263032DBB47ABULL, 
            0x902296D7539DB064ULL, 0x3C32F2A4A84C3D95ULL, 0xE7B7AE5BDF853844ULL, 0xB94A9F648484DA81ULL, 
            0x7BAC992FE83741AAULL, 0x812B588B2DFFDA67ULL, 0x8C36DCEA60A45E59ULL, 0x69D7CE37EBC19C0AULL, 
            0xB753A2938EFC7472ULL, 0x00F0874C5ED67934ULL, 0x3149C85103D06661ULL, 0xE296EFD42C5D06FDULL
        },
        {
            0x91CEF39CDA39EBC1ULL, 0xFCCABE22DEBCBF68ULL, 0x7AC80FEF3ECA1EBAULL, 0x76C5F9F93647842DULL, 
            0xCE7442FFE4F70468ULL, 0x0F7F9AD4863F5C5AULL, 0x7FE92457560BEFD0ULL, 0x0F83C924FC3B4F20ULL, 
            0xE748E25A1700C64CULL, 0x40A319AB49BD7F4BULL, 0x46F0BA3635418D9AULL, 0xDF62C6C507BF217DULL, 
            0x48353DE026DEE322ULL, 0x2AA9D5EFE09CE641ULL, 0x0AAD6F279ED6F3F5ULL, 0x7E309B4983C2501EULL, 
            0xB3AA8947C18BB064ULL, 0xCC44D0FFE72C8B64ULL, 0xED4D7DA5C5B7C0D8ULL, 0x3CE82EFEBB920A42ULL, 
            0x0FE6E9C59B26612DULL, 0xF50B79164CFE1EE4ULL, 0xFBA5FE8659AEA7ECULL, 0x0414E26BF350106AULL, 
            0xB80E7373B4C5839AULL, 0x6C10C582593F85B6ULL, 0x5641274CEEE72FE6ULL, 0xF349B532DA2B713FULL, 
            0x757AD04E676C3F41ULL, 0x0D0CC7330F14BDCEULL, 0x28A43F41EBF14F70ULL, 0xA7E2631868F70B05ULL
        },
        {
            0x46AB150D3EAE6629ULL, 0xB4853A0F0DD89D56ULL, 0xE3DBBB43E0AF7747ULL, 0x843B0B6FBFA962EEULL, 
            0xBED9A9394E263549ULL, 0x2C9DE63675079EAFULL, 0xCDDB86ED60AADB7DULL, 0x3E4D9A7CD5C59D0DULL, 
            0x2980A57A71914BFEULL, 0xDA3D5E12D551B586ULL, 0xC37364CF7ABDC0C6ULL, 0x8CA47D0939B377CDULL, 
            0xCD527374BAC6E67AULL, 0x68720F6943C6C2CCULL, 0x4A1253A15CBF3822ULL, 0xAE721291942A94A4ULL, 
            0x262FF790876C48F0ULL, 0x5B67A267A3CAC8C8ULL, 0x1A7888C14C2E847BULL, 0x63BE0EB2C45A45B4ULL, 
            0xFAF902E21230777EULL, 0x4E193AAAC8648115ULL, 0x17011CC800C003F3ULL, 0x387635D8665FD9A7ULL, 
            0x1E5192CBEE4F7D3AULL, 0xB7E81894E5C73976ULL, 0x8569706496C35A0BULL, 0x6EAB0929D971A768ULL, 
            0x93E189F316D6892CULL, 0x4C64F710D9CEAE1AULL, 0xC2FD1BB24484141DULL, 0xD37EC91CA66DC147ULL
        }
    },
    {
        {
            0xCE7671E4C9099A47ULL, 0x051F7B8E847EDAF8ULL, 0x498DB8A1791B5B03ULL, 0x4C546848AFD0751FULL, 
            0x6F27EEAA8F31C245ULL, 0xA69AB24433E024C7ULL, 0x305A813036E23100ULL, 0xA83FA7AF72D21A66ULL, 
            0x50F38EEDDDFDE324ULL, 0x158EB81D9A503304ULL, 0xC1594C7E58C0B379ULL, 0xF989961B7A1CBEEDULL, 
            0xEEF3B8DA1F62BD0FULL, 0xA7B23DC55709DA61ULL, 0x8191E5CB363B63C1ULL, 0x0457906F3EEA69D9ULL, 
            0x1728E205472FFBCFULL, 0x36B5214371AFEFBCULL, 0x83124C1BD8EFA57DULL, 0x4413FD733AB57101ULL, 
            0x604817484BA49B73ULL, 0xCD9771588A220906ULL, 0x83A6BE8E9BCD0E28ULL, 0x4DF6E3F8805FE76EULL, 
            0x9E3EB1F5B11B8434ULL, 0x2787F2CD93ECC0B5ULL, 0x7B10D13C69EAD0EBULL, 0xE148FC5AFEC6399DULL, 
            0x6A3EDF8D5D96A929ULL, 0x7D2EDAB4E131EBFBULL, 0x8B42EDA5C13E8AF1ULL, 0x1A81BAB1E7D2FCD6ULL
        },
        {
            0x8B79E6ECE963EB42ULL, 0xFA419C9D9236AF55ULL, 0x0CE429763822BACCULL, 0x771F73D528523190ULL, 
            0xADEA4C2CF60BE803ULL, 0xDE363E3923CE99AAULL, 0x14D391A17FB85D47ULL, 0x57EBC25EC4616A53ULL, 
            0xE928A548D2BA6463ULL, 0x292D907A100D63C9ULL, 0x6E401B7FBB6F09D7ULL, 0x5AEC83931F064357ULL, 
            0x4BA89157A9CA2E8CULL, 0x001BC9579596FC4AULL, 0xEA0B87A6DB6CD34CULL, 0x7D3F89C2403C97DEULL, 
            0xCA95F07980B3B4A5ULL, 0xA9F56E11E47AA551ULL, 0x5D026BEC3A0837B7ULL, 0x0630CB6DB609AF00ULL, 
            0x6C8D6BCFA5B7B925ULL, 0x4CF8F70499501F26ULL, 0x4B54D73AE2349C0FULL, 0xC1EC9A75150EC353ULL, 
            0x6260A2DCC76EDF46ULL, 0x62C817F066B1C0BAULL, 0xAE96680005C97EA5ULL, 0x16FD752DDBC39A8EULL, 
            0xEF3881AAEA71D67EULL, 0x96BE1BE402F81578ULL, 0xC8385931FCB91C1AULL, 0x51907FB76683CDDBULL
        },
        {
            0x62A9DD74841B2661ULL, 0xAD612AA53280D2ADULL, 0xC8449AF2E183D804ULL, 0xAB03F911210CAE38ULL, 
            0xC0A5A105A69B85D5ULL, 0xD38F8AAE07674249ULL, 0xE144B9B93948B894ULL, 0x9DB9FBE15A1200A7ULL, 
            0x6F10BFFD74AD346AULL, 0x70C40DAF130F6C33ULL, 0xE49813CBBD06E924ULL, 0xAE369B54996D312AULL, 
            0x3FA98360EC762069ULL, 0x7A7C4D8E88BAEC53ULL, 0x60794C627D289592ULL, 0x0A33AEF4E66FE0F2ULL, 
            0xA8E13ED91CDC4913ULL, 0xCE3B297B9630736DULL, 0x1B4640A03848F2F2ULL, 0x698B48EE5984BBD0ULL, 
            0xA3FF084D38C3238BULL, 0xB6636888F23335D8ULL, 0xB9C954DB42D67562ULL, 0xD8D3558D74B50752ULL, 
            0x545B299A2B01A462ULL, 0xA088BCBF1216E404ULL, 0xC792B8A73FDB5A0AULL, 0xC1A2AE690E51F9C8ULL, 
            0xD1BEFB47B0B93C17ULL, 0xC58680509126521AULL, 0x80CB633A54CF5EDAULL, 0xF7458D439856EF7CULL
        },
        {
            0x0851EEE6E1184A84ULL, 0x689647A61B740194ULL, 0xADFF3AAA764B1EE2ULL, 0x275C3C3C7C798EEBULL, 
            0x6D612066669E3710ULL, 0x78AB8F70DBA10E3DULL, 0x2D628160B1859124ULL, 0x783059DEFD265FA1ULL, 
            0x4A9CF490F7877BD2ULL, 0x74960CB7F76DB9D2ULL, 0x73645CF3AB9F355AULL, 0x847E989079B878B7ULL, 
            0xAA4974B6A22EBCD0ULL, 0xACDC8546BF9D945CULL, 0x1F3D60952E57D124ULL, 0xA3CF7E92D500B488ULL, 
            0xF00E63DC8601FECBULL, 0xCED87861BEE423F8ULL, 0x407BD547D4F61FD0ULL, 0xAF471CF9903E68A4ULL, 
            0x97A354620B3D4042ULL, 0xA08CF217D320B022ULL, 0xB28FB5A81485BD25ULL, 0xFD60FA02D0100951ULL, 
            0x68F7F4CB7F35A0AEULL, 0xFDC39DF31182E3EDULL, 0x23B99D50E3DE2E3FULL, 0x748BABE6244F1A91ULL, 
            0x966E6BE38809BFF1ULL, 0x1E4B5BC71509F2A0ULL, 0x4E7EAAF534B115D5ULL, 0xBB2B188B64AD4155ULL
        },
        {
            0x16707731DBC83AA0ULL, 0x0E93A441344528D4ULL, 0x0450DAF9016B069EULL, 0xD913A77A4FC57E47ULL, 
            0xEC5BA358D9F00C2AULL, 0xCAC2978D4D8705E0ULL, 0x0F4B3F4018959BA1ULL, 0x5A5C6A2A3E636AC0ULL, 
            0x25C80F5093B4DC90ULL, 0xA3E62B1457D6463CULL, 0x3C396645FF47674DULL, 0x77F50033D91F7C72ULL, 
            0xAFF4914EF35C7ED0ULL, 0x7EDC9FE51E49ABD0ULL, 0x216F70CFB72FE955ULL, 0xF23C4D32C90407CCULL, 
            0x19341B5104B23E3DULL, 0xB306054F7893F24FULL, 0xA177B5598DC13F21ULL, 0x85FC01159B7BDA32ULL, 
            0x9F45736438D5E0E2ULL, 0xFF076C17886FC532ULL, 0xAFA90A7AEAE733D8ULL, 0x64ABC3F2096B665CULL, 
            0x7288E026A5C7EC7DULL, 0x64D29C359475DCB9ULL, 0xD773E7E849BC151DULL, 0x2C71D7F16595624EULL, 
            0x26105E2760A3A1A6ULL, 0xB62B76EC2C7E72CEULL, 0x3CABAD9A4073FFFDULL, 0xE10DFEF03AD790BCULL
        },
        {
            0x8DDA021002DBC60DULL, 0x4F25499FECA53616ULL, 0xBAE9FF125C3EA504ULL, 0x9480141F81979E91ULL, 
            0xB3FF28272E61D86EULL, 0xF39887639B479540ULL, 0x24B8B72077421EACULL, 0x66950F2CA2123631ULL, 
            0xB2BA429C69F8BB9AULL, 0x48C81D0B3E4D60AAULL, 0x81124B7DEE3D6BD7ULL, 0xAA60919B23AF8AEDULL, 
            0x110380F6233037EBULL, 0x08310B9E8E2EB924ULL, 0xD954B640130290DCULL, 0x27E1A9883B2FB853ULL, 
            0xB2DC7ACF62E49D91ULL, 0xE9B4D157FFD3B7EDULL, 0xAE1AA7CE27AC93C0ULL, 0xC3EF51ADACC0453EULL, 
            0x03B3AB0F8F955304ULL, 0xCD945E3528C08878ULL, 0x2D4D1C6D6E6EC89AULL, 0x707C36B8CAF87438ULL, 
            0x2BBFCA4659D370AEULL, 0x5D7EEF639565DACEULL, 0x7FADDC2D4C08F7C7ULL, 0x3E694CCEC0E597C7ULL, 
            0xB977F7C03035F42CULL, 0x3065417412236A73ULL, 0xC7C3CD98B48AFD56ULL, 0x27257496B1CBF4FEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseCConstants = {
    0x8DA7D0830D9C6AA0ULL,
    0x824A34628FE891ACULL,
    0x115988B4EFAFDD8CULL,
    0x8DA7D0830D9C6AA0ULL,
    0x824A34628FE891ACULL,
    0x115988B4EFAFDD8CULL,
    0xB688ADCDCFACEFDDULL,
    0x49EAD047734B679FULL,
    0xEC,
    0x62,
    0x1D,
    0xB0,
    0xCF,
    0xB8,
    0x88,
    0x3D
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseDSalts = {
    {
        {
            0x4F939FB05D94593DULL, 0x0D48C84B5BBF17F0ULL, 0xB40C7E87542DF990ULL, 0x5FAA43F7946C0DFCULL, 
            0xC84F7EDE1E1E8C67ULL, 0xA02A0418E3C92457ULL, 0xB56D70841C793F01ULL, 0x4D4939E9684A3206ULL, 
            0xD09757D060993B35ULL, 0xCAD826B58BC8B5FEULL, 0x7C46C374016E36C5ULL, 0xB6475E6CC0882E46ULL, 
            0x626C220F190A81A3ULL, 0xB3D513A03AB65F88ULL, 0xFBCD26C5888E1933ULL, 0x8ABE18749E0BAE79ULL, 
            0x6B130B905CFFD3F1ULL, 0xBBEF4C70EB50A45BULL, 0x432C8BA21B23F100ULL, 0x2A8D960DE6B1CF66ULL, 
            0xD9E2B8A667CDB76BULL, 0x0C76515A49BFF3C6ULL, 0x320D668A974101F8ULL, 0x68D87B22B2F4108CULL, 
            0x9FC9B45C4C2DD181ULL, 0x1235E1DAA0D8AC63ULL, 0xC294F0256EF9F737ULL, 0xE6EFD1D0C54ACACFULL, 
            0x46C9ECCA59618FB5ULL, 0x8F6BF4E68349E0EFULL, 0x196B5628DE1E4295ULL, 0xAB6B0C1697200617ULL
        },
        {
            0x39351EE754A6698EULL, 0xDD17FB317B7291DFULL, 0xF2DFDA24E8C5F128ULL, 0x2AE66C138566E700ULL, 
            0xAE98C5000B14D2A8ULL, 0x6AA6843A5B3D6E4FULL, 0x755C662A73AE1BFCULL, 0x60D59B5F0690E3D6ULL, 
            0x7A107D0A92863460ULL, 0xCBAE651890BA6697ULL, 0xE179457104E6D062ULL, 0x61D77060078C94C1ULL, 
            0x39C2A03BCB95CCAAULL, 0x9E5504B5FA44A274ULL, 0xABBB306E097BC7EBULL, 0xF2D1FDEB208EEB8BULL, 
            0x968CA4387BAF3B4DULL, 0x6CEA85490D4E95D1ULL, 0x14BF4BE8FCB7536DULL, 0xEE3C9684C77FE125ULL, 
            0x23B7696CDC6C32B3ULL, 0x3061B7B42E840280ULL, 0x391137CBA7C6590DULL, 0x5AC764C9921DF71DULL, 
            0x6871300A49037C63ULL, 0x82F3FA8478A5C7B8ULL, 0xADE92839C14FCA86ULL, 0x1D63B53F7C6EFB07ULL, 
            0x73A02CDE0793500FULL, 0x7B87307A25460314ULL, 0xC76BA77270D76E2DULL, 0x4CC6232211BAC0AFULL
        },
        {
            0x6D6FF6AEC40A82CDULL, 0x1B13BAEF6B8B221EULL, 0x67AD6975300C64D6ULL, 0x5D3F6ED307180409ULL, 
            0xB057E9F539B76F4FULL, 0x00083A2B843CE832ULL, 0xA7C9F907E101365CULL, 0xF77DEEDD5002F3C4ULL, 
            0xFF855A801A50A3F7ULL, 0x56F2EFC0E7D4A094ULL, 0xBD013DFD6A55F845ULL, 0x16CD78D4BB021EC0ULL, 
            0xF8F2EE434B611691ULL, 0xAB2BBDCDD02579A3ULL, 0x755A38F036BD1E63ULL, 0xFDE693C2840B4703ULL, 
            0x9CFF6E4E0066C9F9ULL, 0xB5BC6518ABC7E9CFULL, 0xC20ED1F08DBD74E8ULL, 0x060ED601C0B7D45BULL, 
            0xA750646E2D6F4323ULL, 0x69A67BD78315B636ULL, 0x0880990D865EA138ULL, 0x1668F0BCCB0CCB3BULL, 
            0xF6C553AF65FD0223ULL, 0xEF7AF963DECE16B6ULL, 0x631BEED190EACE6BULL, 0x3B660D730C3CDE6BULL, 
            0x3D524F338FB25935ULL, 0x5BBC33B6BDA7EE22ULL, 0x8C66BED79A8A37FDULL, 0xA76025289F24AA24ULL
        },
        {
            0xC7832FB97CACAFA0ULL, 0x3D73F4A7A7B16F1CULL, 0x778923468A978366ULL, 0x648B792BFBE587C8ULL, 
            0x6028E18B1B62F4E9ULL, 0xC9ACB8EF41F65440ULL, 0xB53DD0EB653E0D7EULL, 0xBF65EF3FFC81FE68ULL, 
            0xD150FF4D7911F946ULL, 0x339F4F639276CFFAULL, 0x0EFF5D27366B8423ULL, 0x32672D486D84ED6BULL, 
            0x41F9816FD536A8D5ULL, 0x8DE048BACF1E494AULL, 0x0EF2F4CC71196823ULL, 0x2AC9333C2E011F48ULL, 
            0xC463C746C8AB632FULL, 0xDA7C3C92E5D33692ULL, 0x3F64C1F8BBA69849ULL, 0x4BA2CF5C8B1D8AE8ULL, 
            0xBED91B379866355DULL, 0xC6404155C3DB4883ULL, 0x778E55BEFE65F2F6ULL, 0xB8F6072C358F9D59ULL, 
            0xD9C27447544ACAEFULL, 0xA1E1411CE572C99BULL, 0x6C3FCE2AEBAE2E95ULL, 0x88EC7A1FB0D4D086ULL, 
            0x5706B7B62DE15BEAULL, 0x7557190B4ABCB897ULL, 0x9D1214299974F8C7ULL, 0x96D0A1066B46A778ULL
        },
        {
            0x67E6CDB8B776DEC0ULL, 0x473FBA422388EE37ULL, 0xB6193CAD8D3AD1B4ULL, 0xD0B940D1C87913B9ULL, 
            0x87061A9AA14EFD8DULL, 0x887210FAF3EAA051ULL, 0x962C114F4BA7890EULL, 0xE80671B202267A76ULL, 
            0x43292D260DB309EBULL, 0x90D14A4E1B34E258ULL, 0x427850E8681D86CAULL, 0x47BADFFA67031295ULL, 
            0x132E0D7ECF2501ABULL, 0xFD1792E3BB29F212ULL, 0x669BE12B53B526B7ULL, 0x2150133B26408FACULL, 
            0x39576D15EFE50011ULL, 0x0F3A235B50FF86DAULL, 0x3BA6849DFE504920ULL, 0x4CCB09215D2A739EULL, 
            0x7043CF9FC173DD52ULL, 0x6FECF69E3199C228ULL, 0x9237E97FB62BC089ULL, 0xA1BDD2D32C5AD8ACULL, 
            0xA65E9FD34F93650CULL, 0xF7A47F0F4BE2D95FULL, 0xA8C1D7B620B8FCFFULL, 0x79A4B0571B457384ULL, 
            0x10D7FAC411B20E86ULL, 0x800FDF01E8A272DDULL, 0x18E01E174F95AA25ULL, 0x9D4F03BE8AA3F150ULL
        },
        {
            0x159F79AF532FDBF6ULL, 0x743E35FE53017EC0ULL, 0x5A38A9C806D13A6BULL, 0x1A4ADA5F64F9B7E5ULL, 
            0x796C7293AD048B9CULL, 0x2FDB4E15B8F1E5E7ULL, 0xE78D109BA71A6CC1ULL, 0x2390AE1FF19B1DB3ULL, 
            0xE309FEE7D9558EFDULL, 0x6D1E7FDB8BD65FCAULL, 0xE25355248E17CF17ULL, 0x7A5611B7F8161970ULL, 
            0x975FB728F152C3CAULL, 0xE7F551736EBDBE72ULL, 0x428CFE2FE2B19CEEULL, 0x00D0A68ECD1595F6ULL, 
            0xC4FEAE987FE9E6EEULL, 0xF13CE143E3B5E03FULL, 0x96D90696B933100FULL, 0x47BE77C201D7FB95ULL, 
            0xAD6CF20F1E569B1BULL, 0x64CAFA3C38DBAD41ULL, 0xA1470980233425DCULL, 0xB91701C2262C4758ULL, 
            0x3C0A49B7683785B7ULL, 0x1757EB6C91B8D468ULL, 0x28E4E47B78F5BD44ULL, 0x25F97A8224874AE5ULL, 
            0xA75CCB6BD17E4681ULL, 0x37004A04B6739528ULL, 0x7D9D9D29E15680F0ULL, 0x9D7EE2AD7598FBEEULL
        }
    },
    {
        {
            0x7016F02727D7D05EULL, 0xB1BA7BDCA487E801ULL, 0xB2309CBB5D88665AULL, 0x4A571DF1D4ACC061ULL, 
            0xD6FCFADAE46AC955ULL, 0x31B16159AAF59CB4ULL, 0x0D04936A15DC0485ULL, 0x3E46042A874473C0ULL, 
            0x6305B6A51DC7EE22ULL, 0x742B45F7FC9B5A19ULL, 0xAD54E3CCED44A319ULL, 0xD69E13B40D879F68ULL, 
            0x515B6A0A9AE09393ULL, 0xD458603E08F2EA01ULL, 0xE0FF5924BBDCEF96ULL, 0x0DB1EF00AC296439ULL, 
            0x4DC292F82BC3B600ULL, 0x899485077861B042ULL, 0x1A753F2280A89EE1ULL, 0xAD1D9EEEB145F80EULL, 
            0x6077CBD5B507FA6CULL, 0xDC75A61F318A0451ULL, 0xFFFCACC568406994ULL, 0x783C03F63F2B58AFULL, 
            0x2777CCB0A12A178CULL, 0x2D5AA9A9FCA3586AULL, 0x3A2586928D5CC069ULL, 0x92F41806065C1950ULL, 
            0xA02B6C2B6BF08289ULL, 0x3A742F3D26EDF9C3ULL, 0x98833F086E9CF8BDULL, 0x03CFDF270E175DCBULL
        },
        {
            0xCEAEF1B69DB95542ULL, 0x23EFDB82E2ABFF7AULL, 0xBA9D7DC535E8FBF1ULL, 0x2F205FFC228F8D1DULL, 
            0x536CD2AB82EFFA88ULL, 0xF00A4AD51214D6EFULL, 0x4A81D3BF0407C06DULL, 0x891A28CB0D79BD06ULL, 
            0x4358A774099E77D0ULL, 0xEC735B5DB3585E35ULL, 0x3404C87121708252ULL, 0x75BF50C63D3702B9ULL, 
            0x7300616C3BE70552ULL, 0x2B66FE15884652ADULL, 0x8B050F4B86759881ULL, 0x550DA4E4DB01B9F0ULL, 
            0x341CBE563ED7523AULL, 0xA284F2EF68A49821ULL, 0xB6F01D1CFB3C4A5BULL, 0xF1B412888E5DB2A0ULL, 
            0x0C402C6800D67427ULL, 0xAA0CAF6BA3559EC7ULL, 0xD46C311DCBE2EBFCULL, 0xEE387E20CA5BC8FFULL, 
            0x0C7895CCD1205DC7ULL, 0x1C2EF7B34AB56399ULL, 0x6B0A62A1B6D3484DULL, 0x1B40C2783FC72191ULL, 
            0x351211F89E31448BULL, 0x10B719BFFAE059BFULL, 0x5AF18C50F3802D4CULL, 0x4554339BC45C9119ULL
        },
        {
            0x891313BB4FC3D381ULL, 0x964E71EF9690B5C6ULL, 0xE23A10E7B391FBF0ULL, 0x30820AEF0D4308EDULL, 
            0x62E9BB2BADD53310ULL, 0x848377E8C1F86463ULL, 0x60F1596123AE0C90ULL, 0xD1399553BCE971C4ULL, 
            0xA03C7F57BF59D433ULL, 0xD3039DA714DCB097ULL, 0xCF03AF746E07159FULL, 0x4E1A37E7BC68677AULL, 
            0x260F0E0F9EC1D36FULL, 0xC455091ACA07F58EULL, 0xC1C0DE5D762D01A8ULL, 0x8177EE645EF48637ULL, 
            0xF4401A61922727B0ULL, 0xF9ACF12D72273E46ULL, 0xDED790AADC79CEE7ULL, 0xC735493CD70A3312ULL, 
            0xB6CCD41AAB665830ULL, 0x7E4C825061B8D17FULL, 0xC06C56FE7CD94B6DULL, 0x7C68319ADFEB94A4ULL, 
            0xCA2C7EA3985B3D3BULL, 0x9906C959A5B2AD6BULL, 0xBF9B9F95BC764D44ULL, 0x243B2567B50B6306ULL, 
            0x3E95308E33748325ULL, 0x01AEFAB8A8B36FF0ULL, 0x5A32444BE283B13DULL, 0x21580424539724A1ULL
        },
        {
            0xE5CBF4CBAAD49F17ULL, 0x6B9358131D39EE90ULL, 0x5F201369D4FCC740ULL, 0xECCB3BB4DA0AD7AFULL, 
            0x374A061786DFA7F5ULL, 0x2FCCE1256317BB01ULL, 0x9703F1ACD8CEF2BDULL, 0x2EB8EF1D6107EEE7ULL, 
            0xAE7D8EFEBF13D745ULL, 0x02B4AF555BD62B1BULL, 0x492BB73DD6C843FEULL, 0x2C9BF28402EA911CULL, 
            0x17C9DA9C87894E1AULL, 0xFCCC9E97AB5AB59BULL, 0xE36B1D574BF820ECULL, 0xB2DF817C6057A748ULL, 
            0x84BE5617331309B3ULL, 0xE38515872EA0683CULL, 0x839BBACF9051CF78ULL, 0x4DF984CDB7B17BDBULL, 
            0x87899B0795ECD957ULL, 0x5C615D44AFC0D154ULL, 0xBF391C873A03A129ULL, 0x884225DB8E2C0C89ULL, 
            0x984EC3AF0A611240ULL, 0x79D62818AAFA02FAULL, 0x7CA60AC157FD241EULL, 0xDEA0073F86373917ULL, 
            0x06FC3FDA5A2FC29FULL, 0x5D028F9838E36916ULL, 0x05BAED9350E28AA2ULL, 0xDBEFEDE9D5954A75ULL
        },
        {
            0x3075A078FB06CCEAULL, 0x939D9F5902C06CDEULL, 0x2D137B9017844A37ULL, 0xAAB070D6A1EFEE61ULL, 
            0x2BE09C4C3885C4C5ULL, 0x67DB1FD16B33C9B2ULL, 0x5CF12A6AB36B2386ULL, 0x6B49D6D76D252859ULL, 
            0x2EDB22AAF455D8E2ULL, 0x7664A079D5DDBA7FULL, 0xBBD01C6505DAA24DULL, 0x77F7528DBED586E0ULL, 
            0x4E59F46572117763ULL, 0x19580A818623AECAULL, 0x63CDF1D932A938ACULL, 0x1133129673D66A5FULL, 
            0xDD9E79251DC644BCULL, 0x3A1D93580213E5F4ULL, 0xA4E48FEBA98C9D54ULL, 0x98386DF7F40966A4ULL, 
            0xD400F1A17A07200CULL, 0xEF5EC11D15E88D2AULL, 0x20C7BCF55D1D9862ULL, 0x0B40A38957893D4AULL, 
            0xFF89C3C10107B3AAULL, 0x145BA9BC33C32B7DULL, 0xDC931B672FCC4DA1ULL, 0x2123CFB12AAA93EEULL, 
            0xDCECCC89406721AAULL, 0x0AAC20B1C6B95C61ULL, 0x1B947DB41423D5D7ULL, 0x54818C1E63B78C0EULL
        },
        {
            0xE7D09B9A6132FA75ULL, 0x8D66B88630024737ULL, 0x9DF3D7E1A84283DAULL, 0x0A6E70B0D2C44039ULL, 
            0x223BC7ED78345F8DULL, 0x4327C60F5A05CD96ULL, 0x09C2B8A91EDCC7FBULL, 0x97DE46DC15B631FBULL, 
            0xFD50B6E4E98495A7ULL, 0xA6D594EED6199721ULL, 0x340A4833D9626392ULL, 0xB9005E8F196F6902ULL, 
            0x52F2BEF1F07C310DULL, 0x169123D5F5866ED7ULL, 0xAF9EBFD72CEA83CFULL, 0x5A1E226E8F403E4FULL, 
            0x6E0849C8D3659D46ULL, 0x9AAD43795FFCF1FFULL, 0xC72C0F8064B3C34BULL, 0xD918D9E8BF0BA293ULL, 
            0xD3C565EEA012636CULL, 0xC84DA4ECEA9C2ACDULL, 0xC038B289B273566FULL, 0xC7A0635A63751E79ULL, 
            0xFF355876E42E01F0ULL, 0xF43D53848F94FC51ULL, 0x78DEADDA54729D9BULL, 0x0BC489BBF403772FULL, 
            0x7DEC51F13D329EADULL, 0xD8AE523078D466D6ULL, 0x8D20086FFAF5B784ULL, 0x2267F4EA6D48C910ULL
        }
    },
    {
        {
            0x11DC99DA7E58AAFBULL, 0x0E8B8D442D9A248CULL, 0xB1C9F702979EB013ULL, 0xA12575D0404FA778ULL, 
            0x1C8E8BA3DF966172ULL, 0xC10F55E5A92939DFULL, 0x44E7466AE2AAB9B4ULL, 0x49AC356B47134F18ULL, 
            0xC69906929A5B4C1BULL, 0xC0FD959426D08833ULL, 0x5A064940CD041FE6ULL, 0x6196E716AAFD5E72ULL, 
            0xD14E929809FEDA71ULL, 0x008CBE1B2D0B1FC3ULL, 0xBE9789DABB9DFC22ULL, 0xC182D6C96C56B700ULL, 
            0x2F824AA5975AB1DFULL, 0x8C3833F383F35C60ULL, 0xB6414C81015D1D91ULL, 0xAD431C0FFC31D3B5ULL, 
            0xDF2E53C460497962ULL, 0xE2EB1ECC9310CFBEULL, 0xCCD7E511F6A5C200ULL, 0x867EE941CAFA754CULL, 
            0x1928104452A77649ULL, 0x75830B8D12D1645DULL, 0xAEEEB90C21EED286ULL, 0xCEA1817DF178C4E1ULL, 
            0x2BD377C6E2C8AE71ULL, 0x6D3AEDF64B92F24CULL, 0x987A90C10C1689D8ULL, 0x49307DB5CDB94730ULL
        },
        {
            0x9F8A580EF9E4801AULL, 0x4826499AE8F58218ULL, 0x81E8BB50BEE9AAB0ULL, 0x766D6E44A466042DULL, 
            0x3BA882980B7A940DULL, 0x72EA957B71A82A2AULL, 0x475C9151BDCB2E6DULL, 0x512032E70EC263E2ULL, 
            0x6E1006775F991AB0ULL, 0xF2DFA0F7684512F4ULL, 0x50DE9A0A74E36EE4ULL, 0xECB219EFE324356DULL, 
            0x5E7D2D75079B5842ULL, 0x2B2C50D47C283809ULL, 0x6434AFB9A008E651ULL, 0xA04D187B64AFAACDULL, 
            0xA265B935B9B88915ULL, 0xFD0B8888B19CC3E6ULL, 0x7B019508FD8BCF13ULL, 0x6BE2588AF30A1D47ULL, 
            0x5F97DC92370DCB1EULL, 0xEE7CF83F292991ADULL, 0x9FE28AF37C9FCC7FULL, 0x1E556E48B23718F3ULL, 
            0x72D22ECB93EDDDD6ULL, 0xFF8D9FA8BB52E3BFULL, 0xA1F6082C3187A9E9ULL, 0xB24E6334FF49F359ULL, 
            0xBD54E52FAD88641EULL, 0xDEA12784C8140BE8ULL, 0x16780CF2B5775B23ULL, 0x57C229A856E1D724ULL
        },
        {
            0x08C219DE6767C222ULL, 0xFC6895709F6DFF97ULL, 0x7550609422F00367ULL, 0xDB2B728DCFA9F24AULL, 
            0xFEED8D1486EF4C45ULL, 0x4EA8569A0264C8B3ULL, 0x81526422F3CC7FF1ULL, 0x3F7CD0289B31CCE1ULL, 
            0xFB459CBFC4BB81C2ULL, 0xD325B98844700120ULL, 0xAC6D82A7462E22D4ULL, 0x11E7113EB1491609ULL, 
            0x23E167301952C999ULL, 0x90C5A20AE3493E30ULL, 0x4F57C591DFDED55BULL, 0x83D9E8767E2C113BULL, 
            0x1494657D03DAB34DULL, 0x450A9AF19FCDCB61ULL, 0x601051C204F7FCF8ULL, 0x56534CF665A883C7ULL, 
            0x74CA93149F41D271ULL, 0x0D758F7E5309C782ULL, 0x794BA52B5A9155ECULL, 0x844A3F78FE68D58AULL, 
            0xCF82E118CBF554A1ULL, 0x1AC0138F269B7CE9ULL, 0x8843DBD59639512AULL, 0xE5635C1A33E71D59ULL, 
            0x127218CE5C397B71ULL, 0xA5BC9B5F2E867328ULL, 0x27A593ADEC5A8E61ULL, 0xA4A9CE2ABA112679ULL
        },
        {
            0x8B12F135436C1EEDULL, 0x479D6469932B06ADULL, 0x4EF45D2755C75218ULL, 0x03C692C6583F646AULL, 
            0x1CD20701D1AABA7BULL, 0xB217A382C6A30E30ULL, 0x4E2CE64B0E84C8BAULL, 0x086C36FB15E311FCULL, 
            0x1EE31CD5A4CDB647ULL, 0x89A53E8BC105EF57ULL, 0x0EACA0098761538DULL, 0x0EF9706776EA76BAULL, 
            0xA392003101B206BDULL, 0x238CBD944351B4F5ULL, 0x415B9FD8A5BB3B09ULL, 0x0072E6AE3EEB1EC1ULL, 
            0x50F3A4C7573AE4D5ULL, 0x5AB42D4BDD8552D0ULL, 0xDAD1F9D69697A984ULL, 0x8FA81923CC7629C6ULL, 
            0x8BF418DEAF457148ULL, 0x0BC83C9AE4214711ULL, 0x449F9D082818C37EULL, 0xCDF8988E1C4E63ACULL, 
            0x691D5FA4304C3BEDULL, 0x00B1F932D8A130C8ULL, 0x2D79EA26337AB056ULL, 0x0635FD98FAA3D658ULL, 
            0xF89CF6B5E77A5113ULL, 0x28C542B7EFBBB4E6ULL, 0x256C93241BC3F887ULL, 0x33547799E0D67EE5ULL
        },
        {
            0xB749EFD89E320171ULL, 0x4D4BC2708F1FA0A0ULL, 0xF48215402D6FD331ULL, 0x778C656FCE76CE78ULL, 
            0x3FCC86033B0AF05AULL, 0xDD4AE4ADAE4F7D69ULL, 0x6FDB2E3A1FEBAB71ULL, 0x1C750321FDE561E9ULL, 
            0x87BC84E59DA9CCBCULL, 0x92CBDF1D4D5437D5ULL, 0x1B713083E2D9A8D2ULL, 0xB52354C58F3E13DDULL, 
            0x9F3257DA99F859AEULL, 0xDFB8E8C97E6560ADULL, 0x1A89507C925D9CF3ULL, 0x3BCEFF9AADC807E1ULL, 
            0xC2D567ED58F2F3AEULL, 0x54796B0FF208B7CBULL, 0x6DF80D28E80352A8ULL, 0xF3B199266FFDCC50ULL, 
            0x439C3C4426C66061ULL, 0x4D06E02BA87FC224ULL, 0x7A2C550EDCFC05A4ULL, 0x816B5FC7B013BD54ULL, 
            0x4666625999CB9070ULL, 0x68F5D5501B83B4F3ULL, 0xFFF788D81DEFCD15ULL, 0x85A542028B0F7AE6ULL, 
            0xE20F7FC664CDE67CULL, 0xF84B096748CA3E15ULL, 0x8FBF175022341742ULL, 0xA3EF66CC4DC1A71CULL
        },
        {
            0xC53A899EFA81A3DAULL, 0xE96E1FC9502C61D3ULL, 0x09E62EE0F924C734ULL, 0xC149754AF0A6FDD9ULL, 
            0xAC8A57EA577FB424ULL, 0xFE814CB64610557EULL, 0x22B18DD0C722755BULL, 0xF1C262EB2F03F042ULL, 
            0x6E67AA7E8CE6580FULL, 0xE140D5982BEBA83EULL, 0x266B1F6BEEC68F44ULL, 0x24340520EE51BD3FULL, 
            0x0289C8438801F6F4ULL, 0x0EACD6546DD9503FULL, 0xFDC806CA169C6B51ULL, 0x27F14346729DF34EULL, 
            0xE503A57AEFFDB801ULL, 0xF088B913713DFD22ULL, 0x097B5207757715D3ULL, 0x71169FA912EFFB11ULL, 
            0x5397C85B3DF7C826ULL, 0x0FED0C66D748C10EULL, 0x3B6EC1A819CC79DCULL, 0x4BCCEE6E1A289785ULL, 
            0xF1762AD440F369E9ULL, 0xFE34DE611DC649F1ULL, 0xED7FF23B5440FDF5ULL, 0xBAF3F1CB74A29AEEULL, 
            0xE11929961D08185CULL, 0xDC5ED9D8D22E7902ULL, 0xF21C6522A4B2F718ULL, 0xAFDE527590E0083BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseDConstants = {
    0xE099A05EA31081C5ULL,
    0x0F02D71FFA2D0FE4ULL,
    0x23E2B09671C98979ULL,
    0xE099A05EA31081C5ULL,
    0x0F02D71FFA2D0FE4ULL,
    0x23E2B09671C98979ULL,
    0x139B7654AD1DD164ULL,
    0x41FB600ED22134E8ULL,
    0x13,
    0x38,
    0xFC,
    0x5B,
    0x8A,
    0x01,
    0x1C,
    0x9C
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseESalts = {
    {
        {
            0x009C97B03954A713ULL, 0xAB2954923CA34313ULL, 0x2E15BF1B8A9914BBULL, 0x2C96A08595CBE5B1ULL, 
            0xACCDA23B8D9AA56FULL, 0x97BB6EA89B429B05ULL, 0xA983A68DA6140FC1ULL, 0xACD50C49FE6D1A8BULL, 
            0xDE25953254B6D90EULL, 0x4843E3DD0F6B7BACULL, 0xDE5BD1D8F984DEE3ULL, 0xB0E572A35155339FULL, 
            0x1EF095CBEF6122D9ULL, 0x6B8E7F4815FDDF6CULL, 0x6DD5C532FF819C54ULL, 0x946A8DA08F4955CCULL, 
            0xE3780008EB66386BULL, 0xF211F45C938C1204ULL, 0x837A82C89A296808ULL, 0xE004EA9A59FAC917ULL, 
            0xF59D9201302B1F0CULL, 0x13FDB71BFD97AD4AULL, 0xB52AEE643BB84838ULL, 0xD8FFECE9DB17B5C5ULL, 
            0x5094C43EA42B38A1ULL, 0x2368A51E72A71CBFULL, 0xC2C2573B42F0DBFFULL, 0x75149D4E5B7AD96EULL, 
            0xA943A9AF894CFF13ULL, 0x1599E7D1B442078FULL, 0xD0EBEB67B89931FEULL, 0x4356D1AA3A364798ULL
        },
        {
            0xAADB987B1474DD8AULL, 0x8C855686674DC9D4ULL, 0xE05B1CDF8B78F989ULL, 0x5DEF7B1974536881ULL, 
            0x056A5309A184DEE1ULL, 0xEA6AADFFA581761CULL, 0xE6EE2481F383504BULL, 0x208102021789DA0DULL, 
            0x7408F7F48E166E42ULL, 0x65BCACAA4EB6FE0BULL, 0x82D9827E495F7C74ULL, 0x99F0F7E3DCD0E736ULL, 
            0x5A4B047A414D0095ULL, 0x3BF884137266D965ULL, 0xFA3C143A84E4ECF6ULL, 0xA23D299F85D63685ULL, 
            0x884F94A77F00F07CULL, 0xCD0AC15C590AD99FULL, 0x34AB7BD7DCF19BA6ULL, 0xF2B2DCE694E3F8B9ULL, 
            0xF8E902D740AEFCA9ULL, 0x18C9A70FDB782962ULL, 0x8B905B31703594BEULL, 0xAFF8C439771E3610ULL, 
            0xF08BE1BCBF53DD5FULL, 0x8C643815B3DF98E1ULL, 0x44553BBE246E2BC8ULL, 0x578BC81B68B6C6AEULL, 
            0xF8377491073CD884ULL, 0x114DC1DC9C4F5C08ULL, 0x37CD3B88725C4E1AULL, 0x3C01CFECDCB7E230ULL
        },
        {
            0xDDCF436E6E371FA6ULL, 0x3920BC48A9B11DABULL, 0x8F3FA01FFBAD9CC2ULL, 0x7474FE249E4D3CF3ULL, 
            0x6A8EE4F5F7CD28C0ULL, 0x56F37BB241E8FD8BULL, 0xBD724E437297A290ULL, 0xE2DAB146E277DFA3ULL, 
            0x57E58C04446AFEC2ULL, 0xB581377A939C5824ULL, 0xE20C7F4457A93AF8ULL, 0x7922C4DB032416D1ULL, 
            0xE45E55BF658AE421ULL, 0x7B6AA0E9FC63E269ULL, 0x3F85B9129E3CDE1FULL, 0xBD1F2A25B351E80AULL, 
            0x3ED9FA22D996D4EBULL, 0xAD100B2D78E770F2ULL, 0x3CD85885741336AAULL, 0xE2610703CF96491DULL, 
            0x6E38AABBEC251840ULL, 0x7899EDC699B189E4ULL, 0x2431BA882F067E23ULL, 0xD38C4527F4E76B55ULL, 
            0x882969D063AB33B4ULL, 0x3DB55486E824DFA6ULL, 0xF4BA5790E19B2E86ULL, 0xF21D38C1122F3DB2ULL, 
            0x4324CC58EC1B9E69ULL, 0xAE8292BBC9D4FEF5ULL, 0xCC52DE4DC83BF43FULL, 0x1ABE4932676F1793ULL
        },
        {
            0x76C3AF4E177BE21AULL, 0x2523EFC07827EA4FULL, 0xA644A7B4B0A30AF4ULL, 0xF881221AF29443F9ULL, 
            0x5D0DD54217EE2ECBULL, 0x6316D32C92A4DEB8ULL, 0x4CF55A034F8F4044ULL, 0xCFCE60F04E81ABC2ULL, 
            0x1C04305E46411276ULL, 0x68307ECA811EEA0FULL, 0x92D05FE2C95F8F78ULL, 0x0894B569A1E5DD7BULL, 
            0xE02288CA04ED9CFBULL, 0xD9B82025118DD4D1ULL, 0x9B15A4E546975AC3ULL, 0x49DDEF1675DEB7A2ULL, 
            0x286160297392E794ULL, 0x43CF63E8B1AA2E17ULL, 0x9A90529BEA93B384ULL, 0x0E738D56945F503EULL, 
            0x8310F8C2B2D01966ULL, 0x8721548FD0B40F50ULL, 0xD2CA52D6F035A8FAULL, 0xA4D7C71F65C4D904ULL, 
            0x6D4B6044597AD1A2ULL, 0x1B0131271FAC00AFULL, 0x705F66EBBD37E4EAULL, 0x808A5A508B6C0F35ULL, 
            0xE6EE38B04A1567A5ULL, 0x87663BA7CC7F2E07ULL, 0xCE01A5F5CAE2CE04ULL, 0x69FA28002E8B58F8ULL
        },
        {
            0xF3A4E9F9D5DE0401ULL, 0xF31FDC89B76D56F6ULL, 0x7E741319190A4DF7ULL, 0x0144A6B78EF3EF7EULL, 
            0x9D06454EA6D8A071ULL, 0xA116D5D1C1C0EB05ULL, 0x02FE504498D3B3FDULL, 0x0158E309EE87B6E5ULL, 
            0x1193315D404AFF88ULL, 0x7067169F63EA19A1ULL, 0x7B07DB46396953A4ULL, 0xF5987AC53B31357CULL, 
            0xF7B242C13A985EDEULL, 0xD13804592F3310E6ULL, 0x18D1180C8D37C03EULL, 0x78066BD11D783FF4ULL, 
            0x8F44465ACD2D1221ULL, 0x01FD6406A15B4277ULL, 0xBDDE71111B848914ULL, 0x4F805C255E5EF400ULL, 
            0x4A570238A8A65E73ULL, 0xFC752BBFC00B46CAULL, 0xE9861D44F7C7C773ULL, 0x05A89F6DE18D4D51ULL, 
            0xF27713C41B3CCA44ULL, 0xA286F78BAF20205AULL, 0x10D03E69C1AB9156ULL, 0x36334AD72FFB533CULL, 
            0x3D41CE12CF77D75BULL, 0xBB517F5646237C39ULL, 0x48D35424EFD321D6ULL, 0xD3C573AB9160C453ULL
        },
        {
            0xBE0637D0FC697680ULL, 0x58AC161B377ADC94ULL, 0x56A73F2F7FA60EC7ULL, 0x2584011B426F2125ULL, 
            0x4A4C28711AE1DD82ULL, 0xFEB81AC6CAD14BFEULL, 0x250F4363CE4DE895ULL, 0xEDDEFDAD09FF7FE4ULL, 
            0x07EAAD8FB1CE5E1DULL, 0x8F6FB66D2D338AA8ULL, 0x63F23E731A2618F9ULL, 0xAA04E218B00D3425ULL, 
            0xB3B2E00D7C6CE41EULL, 0x25F64E9F0342BA43ULL, 0x0666AB3D1232072EULL, 0x1C4AA213D695FA49ULL, 
            0x50CD9F19636BA967ULL, 0x9796F8E9815DE5E4ULL, 0x005C034184169294ULL, 0x2D42A26081F0A8AEULL, 
            0x4BB92A2FF617FCDDULL, 0x405FEC113256760FULL, 0x65FBBD79F9DA61F2ULL, 0x24DF0A2AAC79D16EULL, 
            0x08AACA11D86233B7ULL, 0xFDDFC539F5473167ULL, 0x798118F391F3F9EFULL, 0x82B913284AF5B64CULL, 
            0xDE130FA93F6B099CULL, 0xB33FFDDEDB72E244ULL, 0x243F6574FDF86899ULL, 0x1A4F6CA1BA414EAEULL
        }
    },
    {
        {
            0x8C18B1AA932AD8BEULL, 0x1E3D73D1BA3A316CULL, 0x6DA45DF8C285BFE1ULL, 0xDE412B8ACDCE816FULL, 
            0xA18AF39856C370EBULL, 0x5E4A33FB2056F504ULL, 0x825B810F524964C4ULL, 0x31C0229E7D9DFDBEULL, 
            0x680072A4A27C02ACULL, 0xE046831282B11509ULL, 0xB7E85CC75FBB91DAULL, 0x4691A73F0F17AD5DULL, 
            0xF7066220FB1AA97BULL, 0xC8BA581E2BDB3C81ULL, 0x09C7BC36D207E441ULL, 0x61DFC6BBE7F1DFDAULL, 
            0xF4247A56D6CF4ECDULL, 0x2CE875C87D82CBD3ULL, 0x1AFDBC14ECA77534ULL, 0x09AD79074D7832BCULL, 
            0xF32719E7CD96154AULL, 0xECAB93319C9B3BAAULL, 0xF0AD7E88285144B6ULL, 0xA3C87C56F69A7F0CULL, 
            0xB4B4A08604AA1568ULL, 0x4AC02178663BCE88ULL, 0x10DA537B41C51512ULL, 0x9D2757B2D07F7896ULL, 
            0x5B945974E0694FE3ULL, 0x4FC8AC70029756E7ULL, 0xD21B80EADD93CC24ULL, 0x80DDA2F909A71BFFULL
        },
        {
            0x97A1E692C3D498FCULL, 0xF70307279A251804ULL, 0x9FA6566638F01564ULL, 0xAB0C448F6C9FAC66ULL, 
            0xEA00A69E61324E1AULL, 0x6C51CBD3CD683138ULL, 0x7A1F396BE887459AULL, 0xDB9309F60036DF99ULL, 
            0x7959B74F30BDCDCAULL, 0xC2C4EC6C30DD6B34ULL, 0x174487DEA6A676C8ULL, 0x6CC382848A05BB33ULL, 
            0x5B7C698C33452EFDULL, 0x20FFB23C8E277E43ULL, 0x276747A2D0CCC7D5ULL, 0x3BB90EEFDFABBB6AULL, 
            0xA378E49DCE66650DULL, 0x260FE7C2806F212FULL, 0xCB81A9349C1766FCULL, 0xBC885B85093599E6ULL, 
            0xFA5B7F7A41318523ULL, 0xD00AFCAA36AC84ABULL, 0xC161C4B56D3A1CB1ULL, 0xD75DE5D558B27806ULL, 
            0x9FB8B763A736E85BULL, 0xB9B85E711706858BULL, 0x433FBF0E954AA052ULL, 0xAA4D5AE578E1DE04ULL, 
            0x95A5A94D831FAAA4ULL, 0x7D9D378EF1474C83ULL, 0xECC180BAE8C66E4CULL, 0x2E1D97A1D546EC62ULL
        },
        {
            0x23D5196398BCC0C3ULL, 0xFA67FF89AF194507ULL, 0x51D4B3720CB8C442ULL, 0x169CADF23F149FC4ULL, 
            0x1D66A60C624080C2ULL, 0x34F0C194D0DA7D1DULL, 0x881D5B85E1FDB16DULL, 0x5B394F2C2C3A44B7ULL, 
            0x635457EE967E47E2ULL, 0x61414FA0DCF12602ULL, 0x15992391CB2DBAEDULL, 0xCF4BFDA75D52518BULL, 
            0xE0207EFAC6F0B109ULL, 0xFF3009EE23AFC163ULL, 0x3311D99AFB0177CDULL, 0x151C3F22700C6A0BULL, 
            0xD68CAE080B2A321CULL, 0x21F4731B3463676DULL, 0x07A20EAD6B114747ULL, 0xB3EDDB8EEF83E0CEULL, 
            0x7E6E44E98914FF01ULL, 0x71276B51D48860E6ULL, 0x16A9A42ACA3F323BULL, 0xDA7100E59AE88179ULL, 
            0x6BB2F919348B457DULL, 0x4A45C6946B113BB1ULL, 0x59E4642234F34E21ULL, 0x74C596DA2BDF8ABBULL, 
            0xE01FDE289651B6F8ULL, 0x48104F357072F4F9ULL, 0xDDA73A2DCA7922DAULL, 0x2F14E18B2B72E03AULL
        },
        {
            0xE5F3F483173D4253ULL, 0x4BD32CDEAD02189CULL, 0x6A754E3E74AF9619ULL, 0x79ED9459F3857951ULL, 
            0x48E6943789F579A2ULL, 0x6C4670D2D26CC58AULL, 0x49DD54AB3976B634ULL, 0x2D593B35DCF29C7AULL, 
            0xD2985D002BB395BDULL, 0x400BB728696D6332ULL, 0x0FD41BBD6741A5CEULL, 0x579C7B7229DB70C1ULL, 
            0x219E94F481CD689EULL, 0xD4FC84A9A88FE2C5ULL, 0x7540004217C638C3ULL, 0x1F3759D28A11ACB2ULL, 
            0x81E3532FA3A11522ULL, 0x65C8170EF169F8EDULL, 0xECC20FEF3AA154B4ULL, 0x8735216993A0BDB5ULL, 
            0x9F814E93366816ABULL, 0x84F58A28ACD6610CULL, 0x8C4AF3CDB4A79094ULL, 0x10571FCD2FA8C887ULL, 
            0x39FB6E1E7B8C69ABULL, 0x736B09DC6FA4887AULL, 0x23B6B324345C98C8ULL, 0xAF43B221C15413B4ULL, 
            0x29F6963E4BC9E027ULL, 0xA28D1ADCD5A023DCULL, 0x751FAA092A9DD52DULL, 0x77105D0629083F8FULL
        },
        {
            0xE6BBA4DC10DB4D73ULL, 0x2D26D669C21D6F6AULL, 0x7C985B3F73EC44A1ULL, 0xE73156DE4FB134E2ULL, 
            0xD4556E57624772E9ULL, 0x237FDA681C6BB2B5ULL, 0x14952196C2A4B881ULL, 0xD81DB14AF992B399ULL, 
            0xDA5DA105174E4E61ULL, 0x6918D4B9F7EC165EULL, 0xE3E9FF51CDCAC8B5ULL, 0x9176B6A1803563BDULL, 
            0x794A396F1D7E708BULL, 0xEB5A88B00B3E7039ULL, 0x8432E0F7D1E43E9BULL, 0xA39DAF51D460F9CFULL, 
            0x7176999C46EACBDCULL, 0xEE938859ABA58A59ULL, 0x4CB6A0AA37CD8416ULL, 0x30E09FBAE14C7C92ULL, 
            0xFCB2C4319CCABFD7ULL, 0x025CCE7E67274C90ULL, 0xD91ACE18EE0C6907ULL, 0xEA425FA06557335FULL, 
            0xF9A8C09469352EF5ULL, 0x82573F5D84F2E016ULL, 0x4A2937BCE151C64BULL, 0xBAE445F0A3DD219AULL, 
            0x3962230ECE9CCD97ULL, 0x68575293EB178F5BULL, 0xC94C447AC550268DULL, 0x8AA531D98CA47A59ULL
        },
        {
            0x6AA8D94C644EA83AULL, 0xDE84ACBD0EA5E688ULL, 0x92C7780248EED732ULL, 0x79BAA782E8B9212DULL, 
            0x74BF3CB3C092876FULL, 0x830E5AEFEB786D3BULL, 0xDC7D1D5810CE7824ULL, 0x14186A3C3FC22F2EULL, 
            0x678D3E89EC2F4E54ULL, 0xB3123FD5C52042E0ULL, 0xCE0E84EC9FF22C4BULL, 0x070D490C6F6C683BULL, 
            0x19E656C38F737FAEULL, 0x1AC27C80529CCE62ULL, 0xD3A9EFDC5565F281ULL, 0x61B4093A96AB332DULL, 
            0x717D49556F77BBE9ULL, 0x26338A62845B940EULL, 0xA8B606E7F2D2D84EULL, 0x21518B4AAE38D32EULL, 
            0xC795184ABB177465ULL, 0x5A96B93EA1D00A72ULL, 0x168CCBBD7DA1BD32ULL, 0xDC40B59243B1623EULL, 
            0x2023B86E5AAB8610ULL, 0xB49F2A642D02040EULL, 0x1199C0D90BB86C02ULL, 0x594D3F38ECA955F2ULL, 
            0x8BDDA2DE5F6D25F2ULL, 0xD48D7C7B7E835F66ULL, 0x37CAA03AF82364CBULL, 0xF317317ED7997B0DULL
        }
    },
    {
        {
            0x13CC8CCBE6032EF7ULL, 0xEE4520EAC5F03957ULL, 0x56937EDA1D040423ULL, 0xCAE7D6FA3DA08DF4ULL, 
            0xEEB9E07E3175367BULL, 0xC2AF92431F004FE7ULL, 0xA8E84E24E91173B6ULL, 0xAB7AEE82D7A4009FULL, 
            0x9349550B968928CBULL, 0x75F39BAF6F4809ADULL, 0x8189C512326613E7ULL, 0x0586F384258155B7ULL, 
            0x3062BEF94A1C5288ULL, 0xCC97FF0CAA3B6B70ULL, 0x3D9439C36EBB03A5ULL, 0xF582526FB548E494ULL, 
            0x3070AA6AE24C6FDDULL, 0x60A73E1EF49549F0ULL, 0x91C0E9E280AD760BULL, 0xCCAEB48E1E56BA28ULL, 
            0x5FD6051A17961F60ULL, 0x82159F36FB4EFCFCULL, 0x5DA49B284A05C828ULL, 0x6C4AE487262C8162ULL, 
            0x2B5855CFC515F514ULL, 0x52F6407B10023ED9ULL, 0x09AF352EB401E7A7ULL, 0x483E7C84784CED20ULL, 
            0x176DA4979A7FAE45ULL, 0x2890A18B7D13D790ULL, 0xB978412E02356974ULL, 0xCAAF2198750BDBE8ULL
        },
        {
            0x23F08BE313C4EFCEULL, 0xF45D71CE1E9CA787ULL, 0x503E335D474B6577ULL, 0x5C10B99AD7189233ULL, 
            0x162D0740BA16F2DEULL, 0x8CA36B06B6056E80ULL, 0x304D220B7C60D77AULL, 0xF30AFFC8CDE6E64DULL, 
            0xB8D8C215E06BC07AULL, 0x3113371325D94EF7ULL, 0x010C6E8658F18BD1ULL, 0x1BB8736B89BB79AFULL, 
            0x0275C6B372962F49ULL, 0xAF7535005DA340A9ULL, 0x2410BF896C4B45D3ULL, 0xE4F14A7ABF73B110ULL, 
            0x68E0A58A0CC59AC8ULL, 0x4F5912116AA43358ULL, 0xA8B47EAF200BE277ULL, 0xFFF62629510E3ED7ULL, 
            0xAC5002F44E49AF11ULL, 0xDA74A12942AC0C2CULL, 0xAE2F9F0AE86E8E2DULL, 0x109249A04A0077EBULL, 
            0xB004BB800EBA55ADULL, 0xE846702F9BBBEE22ULL, 0x6E85B9D6B9BED67CULL, 0xAB908F7E0C6CEB31ULL, 
            0x3FFBB3F20B352F46ULL, 0x098A6A3A574A7686ULL, 0x91542722AD83C446ULL, 0xE3439999FBE955C8ULL
        },
        {
            0x51FCDA627F9A51C4ULL, 0x352A427D7367F9EFULL, 0xD2AAC874822F36BFULL, 0x6003AA85B574E5A9ULL, 
            0xD7EC73A1FB63E81CULL, 0x1ABCC9887DA2CF8BULL, 0xBC15B84576C6D73FULL, 0x2DE9F963ADA66213ULL, 
            0xD451EF5D1F022915ULL, 0xD0AC8C7711AF3AB5ULL, 0x6FBB49C790502A93ULL, 0xCDCDB6E39F4BDFEAULL, 
            0x5F3D08770A07E314ULL, 0x72D6306B73B3D6BEULL, 0xD482CAC005242B2CULL, 0xFC7F150BDA410357ULL, 
            0xAC3F3FD661CF75A7ULL, 0xA2868023380C6028ULL, 0x29C13A024DF55082ULL, 0xF94525200FD1A2A6ULL, 
            0xA8E74E3B301B8099ULL, 0x147738C2CFE608DEULL, 0x1F5C406C161BA9F1ULL, 0x4034C87CD417D76DULL, 
            0xA5A4A9DE32641754ULL, 0xA8C5F89E5CB659AEULL, 0x33765DB5A7DC30EAULL, 0x04DEA39A8D0DF1ACULL, 
            0xB1CD1F373F680369ULL, 0xA17E5C933C3ECD99ULL, 0x933A808625AE11AFULL, 0x91140318C8712765ULL
        },
        {
            0xDD93E076D1D95377ULL, 0xB08405C0E3DD9D00ULL, 0x2DA6DE436B748AC1ULL, 0x143D21CB1BD3C680ULL, 
            0x11377EDF394FF2DCULL, 0xC788C344E39612D5ULL, 0x0754B3961FB171EAULL, 0x7DE5AB1C9D14B98DULL, 
            0x77DDA7C9E77EF342ULL, 0xC772CAD9612A33E3ULL, 0x2A2A7FFC3AF80C56ULL, 0x67C8768F643106D6ULL, 
            0xD3329095A571C46AULL, 0x89CF307BD061C5CEULL, 0x212085CCC8862B4FULL, 0x9B919615853C5700ULL, 
            0x9A0C765D3851C68BULL, 0x1B00578CF310106BULL, 0x78B87ECD60B2782AULL, 0x9FB7D3F6B3843ADAULL, 
            0x3F7A4ABD06986D80ULL, 0x73C2435D3B928C19ULL, 0x9ABB2B216895935FULL, 0x7B02696E0A52291FULL, 
            0x4D2943AB8E6E88E4ULL, 0xA461B53C3F93927BULL, 0xFE9CD54472141BD3ULL, 0xB30E8466A30EC148ULL, 
            0xF76A80D7B5AC24F7ULL, 0x0F9BF6A546937D4AULL, 0xC436F49A4271723DULL, 0xF6DA102F2F5C1FB7ULL
        },
        {
            0x3592E10ADC7A7C4DULL, 0x288EC5EAD07946B7ULL, 0xDF371EFC3789EB8CULL, 0x4DEE7D97E9B87AA8ULL, 
            0xD06156FA9F6A6B8FULL, 0x4CB67796A97132A5ULL, 0xA798C91C6A9C7FBBULL, 0xA70559DE98E64029ULL, 
            0x0AB4BF68FFDB38E0ULL, 0x3CE702C10170FF92ULL, 0xA944CF9F405894E7ULL, 0xD8915F1C8DFF923BULL, 
            0x3CACC234FDE21BB3ULL, 0xB0622DFF5CBEEE7AULL, 0xCC340AEB483E7A8FULL, 0x29A129A68D9AD936ULL, 
            0xB03CEC38B150B438ULL, 0xC791E124AC43AA73ULL, 0xB6DBF514AD17AE52ULL, 0xE1AF1D3F0C609C4BULL, 
            0x38E20D2A8C0A9C95ULL, 0x5EC59D259E29A1B4ULL, 0x481C681CDF03ADF5ULL, 0x64FA07E1B65B71A3ULL, 
            0xB720945F0DAAB4D4ULL, 0x6B471A012E0C9594ULL, 0xEC4D8C3B67F84AE8ULL, 0xC3E12996811B77CFULL, 
            0x923635FD2E857FB8ULL, 0x7C2AAB9B6B78AE27ULL, 0x724837C9CF2DFC3EULL, 0xC0BB0F5160E9EEB9ULL
        },
        {
            0x526EE07FAD269F40ULL, 0xA9125A128606F0CFULL, 0xFF95D02C0B4B4134ULL, 0x67E1861C7BE849F9ULL, 
            0x0D3D54F1CA49A69EULL, 0x8B926AD4E669705BULL, 0x6FDEA226B31ED7B7ULL, 0x8C1DAF989C67DC96ULL, 
            0xA75A293A428321DCULL, 0x145B8A1918A9C8B2ULL, 0x00CB031152F5618EULL, 0xC44CE7462178FA85ULL, 
            0x7B85E56042BA5514ULL, 0xBCDCE782AB4EFDF3ULL, 0x6974876F98DEB2A1ULL, 0x65AF4FD3DD1D2A1DULL, 
            0xE992275A98139371ULL, 0x2F22B698E7C6198BULL, 0x4D4B6FE272A1090EULL, 0xEECF724D06769235ULL, 
            0x3E731BE9BA30C032ULL, 0xEB1CD0363CED0306ULL, 0xD3113855AE3EF733ULL, 0x0C11F6E8DAA9D64DULL, 
            0x8D796D21C78477D1ULL, 0xBB3FBD496410BC2EULL, 0x84B156543B2B4E61ULL, 0x5B9D39A966789E94ULL, 
            0xE56DDE14C560B2DBULL, 0xF40CD4ED904D9F79ULL, 0x88564D1AFB427F81ULL, 0x0BAD924D63570114ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseEConstants = {
    0x73BC761D1D1FB29EULL,
    0xF0F4C5066355BF0FULL,
    0x709BE73C68352136ULL,
    0x73BC761D1D1FB29EULL,
    0xF0F4C5066355BF0FULL,
    0x709BE73C68352136ULL,
    0x4FBAA91922564B04ULL,
    0x626EC97BDD6B9100ULL,
    0x6B,
    0x58,
    0x1F,
    0xE2,
    0x7A,
    0x3F,
    0x9E,
    0x48
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseFSalts = {
    {
        {
            0x2DF7288B8614B767ULL, 0xA77063098EF69190ULL, 0x195F8850DD3B5482ULL, 0x9429A4622FA0F208ULL, 
            0x8D4F503A7B048921ULL, 0x5F5BFE33D55C9173ULL, 0xCA7B37FD2AAAF2A3ULL, 0xC69922D8110E685DULL, 
            0x7522C37D886CB66BULL, 0x39A57E882B30E840ULL, 0x6A19E740FFA00939ULL, 0x6C5FBC5492A1A472ULL, 
            0x4DA7E044AAC5C7B9ULL, 0xED6BAC3FBCED2B97ULL, 0x9533DE0CFB7B74C0ULL, 0x17DE63973C604076ULL, 
            0xB4D6A4AEC4ADA84CULL, 0x875635E9EAE0C142ULL, 0x0F9563FFFA41FDD8ULL, 0x123C6577C5E8A87CULL, 
            0xD9753D98AB9C7D5FULL, 0x4FA483203B25C4F1ULL, 0x7ABCE9E620E460F8ULL, 0x53666B4B938BDEB8ULL, 
            0x2824DDC20E0CC1CCULL, 0x5CEC5BD0B795B4C3ULL, 0x483393420F3D517AULL, 0x5F381BCB1097A84FULL, 
            0x3C73934D2F5C1C8AULL, 0xAB9789A4D4246D55ULL, 0xD1792C14EBD9DB6CULL, 0x083BFE936EF5400AULL
        },
        {
            0xB9940A0720049124ULL, 0x09D0E3B77A135A3AULL, 0xD71D18C8681D32AEULL, 0xCA8034E026130EE5ULL, 
            0xAD60174C50AAE401ULL, 0x4A18EC2CE0638EEFULL, 0x6259703E02940EF2ULL, 0x8F0F6A0687E14A5EULL, 
            0x563A4B854089FF35ULL, 0xC40B747B8CFFB8C2ULL, 0xED982B16FCA2AB1CULL, 0x2F824A33F0A88C42ULL, 
            0xB0953E90EE10C1F7ULL, 0xDE1432448DEE1EACULL, 0x33CDDDF059F2EBD8ULL, 0x433F508C52A8C382ULL, 
            0xC8E62D7294B92B93ULL, 0xB0B4937C5167F88AULL, 0xE6C8359D0229BDE8ULL, 0x7BFB05D961115777ULL, 
            0x99679A5028764A7BULL, 0x80AB0BFED235AE90ULL, 0x9D822EE72A653882ULL, 0xE13038C89C163264ULL, 
            0xF334A3E496B441B8ULL, 0x0A8AC92DB2454ADAULL, 0x73239290ED0ACEB1ULL, 0x13140160F6AD6D32ULL, 
            0x6366569889F12934ULL, 0x5CE61C1ED7148E0DULL, 0x710E85A578B7DAB6ULL, 0xE6E370FA300DAA09ULL
        },
        {
            0xA4985D9EC73154C3ULL, 0x6B1A57EE08CDB6A2ULL, 0x085E4B2495425419ULL, 0xFF2C7F31D3208E76ULL, 
            0xBB30F8189A50B2DCULL, 0xDABF6E8CCE2456A2ULL, 0xE8E424E180375E58ULL, 0x6D24D62F59457BFAULL, 
            0x681AD6F248FE617CULL, 0x08421B3E58CD2EF6ULL, 0x6C9735FBD5300C3CULL, 0xAACCB1C8300D5717ULL, 
            0x84A745469C35DA7FULL, 0x92BE2DD2A3771840ULL, 0xF052EEF5A085B4D6ULL, 0x6F828E149C2FA43DULL, 
            0xEB4EE365A71B0C50ULL, 0x6BB8CA87E77912FEULL, 0x625FD37DAEE19D56ULL, 0xA336ABE31ED02263ULL, 
            0x4845E4A31045C5C4ULL, 0xA34EE568DCB535DDULL, 0x85061E4505078A09ULL, 0x649F56EE402758F9ULL, 
            0x391F0A96B30D5168ULL, 0x0E3EA30E674E05EDULL, 0xAE256DCC851C9911ULL, 0xC38ACC15EB10088CULL, 
            0x8FE153DDF48DFC33ULL, 0x592D14FC274FD1A4ULL, 0xA4316E017D15BBF0ULL, 0x35AF02DD23F46F1FULL
        },
        {
            0x9397C76B00011771ULL, 0x33A371C93B4A9154ULL, 0xEB180C3815A5F8B8ULL, 0x9EB558A7FA8E9489ULL, 
            0x7D5C2846891DC784ULL, 0xCD4265E2AE182C3BULL, 0x5410E5600B043B77ULL, 0x3E12B29736F21D52ULL, 
            0x278FDEBCE43585B5ULL, 0x8D95B5F1FBC390CEULL, 0xFCD6AA36EA5AF2CAULL, 0xBBF8BD466B0877B5ULL, 
            0x34AFB3C104A549D6ULL, 0x5FCB8B50F230CECAULL, 0x44E4B7988A851981ULL, 0xD53634A6167C2A5EULL, 
            0x6402F9E45BE30B0FULL, 0xAAC370ABC677BD2BULL, 0xF03A21B02F786E7CULL, 0xB213AD768ED69908ULL, 
            0xD3D5DBB61A8C4F77ULL, 0xCF331C611097B613ULL, 0xAC81D8206A0EC5F5ULL, 0xA5947CFDDB3A8393ULL, 
            0xEDC14BBFFE153E36ULL, 0xF1BC08506BB276EEULL, 0x5B9B8FDE0567BAF2ULL, 0x07D4DA88A8ADFCCEULL, 
            0x686F45B96AEEAB1DULL, 0xB16F9A9A6E192554ULL, 0x4925A79BF49D3AE4ULL, 0xEA29CD21FD0938ABULL
        },
        {
            0xEB35EE7258F14D71ULL, 0xA91A063101E9F9B8ULL, 0x0F9EF5ACB4AFF3E4ULL, 0x793C9A82F6F2676EULL, 
            0x0C073402EC08D0D0ULL, 0x2157F1EA47D7D955ULL, 0xBCE9B277C93A72B2ULL, 0x9919B92C429010AEULL, 
            0x702B27DBA25E8202ULL, 0x404BD09E435C4A3BULL, 0xEF6BBFB214F890B8ULL, 0xDF8B4F2D88E66E31ULL, 
            0xB14B547C6BD962C7ULL, 0x5170B8EC906E834AULL, 0x16905932A8A0BB3AULL, 0xB68B91F0BC58DABDULL, 
            0x5FA72A2CA8416718ULL, 0xAA86ABF30DC20CFBULL, 0x61CFC2534B37D085ULL, 0xF337365F4F98E70AULL, 
            0x1B766E554F3BD340ULL, 0x71F5C1B463224E46ULL, 0x522AC08F281362CAULL, 0x3A261EDB6AC7FCC1ULL, 
            0x14DA088BAF46752AULL, 0x8813FBCDD292EC8DULL, 0x9C47C07A39E3F1A2ULL, 0xF7FC056867DDE730ULL, 
            0xBBFAECF4E6E56FA5ULL, 0xB5BBA0BCADF67CCCULL, 0xF84630991FADA432ULL, 0x15B944801F939168ULL
        },
        {
            0x8B533B11C6808A94ULL, 0xF9F2BC5AACD87449ULL, 0xA900CCFFB539BDF2ULL, 0x9591F5CFD196C75DULL, 
            0xAF37A0BF8462B74CULL, 0xD363AE8269907E43ULL, 0x29F936AAC56BC5A8ULL, 0xD49E9E3517781DFBULL, 
            0xC1E7681AD8842783ULL, 0x004C5F4E6EFC5C65ULL, 0x7EC3099A6EF50C72ULL, 0xC36812A993127D35ULL, 
            0xB498D9149FFA37ECULL, 0x375404B6EA4A9567ULL, 0xE8907B84891E67CCULL, 0xF40738381CBCCF0FULL, 
            0x9E8ECD6C6867A3F8ULL, 0x6A19ECFDF3976D09ULL, 0x177E62F878E9C3D8ULL, 0x0D5D6114A2837373ULL, 
            0x0459A8B51AF12927ULL, 0x1FE40E4FD0CCA14AULL, 0x3ED1EB8D9252386EULL, 0x0E0CB2A9B03DC15CULL, 
            0x22E2AEACEC9FBF0DULL, 0x69D988CE7A64EEA4ULL, 0x427506153A17FFD7ULL, 0x0C903A3BE96C5265ULL, 
            0x8E32F513EC339D12ULL, 0x69B60A633C2FC0BEULL, 0x13F9BD8AB0E16104ULL, 0xB6004754EE3BEDC9ULL
        }
    },
    {
        {
            0x83A13C3A1A6C1AE6ULL, 0xCFA27F158ABA226BULL, 0x5FBDB0A32FC9A4FCULL, 0x3E912C13D44CA0F0ULL, 
            0xD144F1C5B8365B1DULL, 0xD0C9368886DEF2B8ULL, 0x56EBB7E3809E3100ULL, 0xE15A032B74247FBDULL, 
            0x6FFC9380CE30FC59ULL, 0xF268F24152E56DFCULL, 0xABD7FF36A1632887ULL, 0x3A4D6001C0633A27ULL, 
            0x64229B1E3992231FULL, 0x926B5627813879B9ULL, 0xFE15332627D689A9ULL, 0x91EC902555E1926CULL, 
            0x006C17F9EDCA0CCBULL, 0x585EB96B1176CF68ULL, 0xE86FF40D8660F1CEULL, 0xE140625CD96D4994ULL, 
            0x55CE9A3926941EFCULL, 0x6789676FD3EEF661ULL, 0x53E7FA828BDFC924ULL, 0x05FC19AB04EDC5BCULL, 
            0xA536D261131429ACULL, 0xE29B8E5A84FF0E44ULL, 0x539EB5C4233BE482ULL, 0x7B7C3B0E8E8DA8BAULL, 
            0xEF8D784616D5197AULL, 0xD6ECAFBEE6A3390CULL, 0x31FA0ADF11CC3DC2ULL, 0xDA3E1A20A15EAA91ULL
        },
        {
            0x42E948937FB598FCULL, 0x81BDE7C123E2B382ULL, 0xB71CF2C87B65D0F7ULL, 0x0660AC18944696B9ULL, 
            0xE0596235C8AB4A24ULL, 0x5C9F7C0DAF9A3332ULL, 0x47B96430BE937AC3ULL, 0x2D2B3386C5FADA74ULL, 
            0x89950A0B07CC94CDULL, 0x2D2637CC5A763363ULL, 0x3AEA3F3475F54393ULL, 0x2A1B08D169C15A06ULL, 
            0xB8770232DBF9C477ULL, 0xD83DCA87D23BF722ULL, 0x26AA262D9B35E665ULL, 0xFC7355456D82D142ULL, 
            0x2B8E41A08ABB2A9BULL, 0x1779F8624ED0FD89ULL, 0xF1F7DB027A091B20ULL, 0xDEF7B64348063162ULL, 
            0xF21C451A679FF545ULL, 0x53DA2F60D05A43B7ULL, 0xB487D93565928A6CULL, 0x4D4A0E73E80311BDULL, 
            0x3FB50E99A0DA422EULL, 0xE7052B148FD855D6ULL, 0x3536DF005B61E2CEULL, 0xA1C44386A83A937AULL, 
            0x2E9BCB2D4EB59DEAULL, 0x37B625CF95CEF819ULL, 0x9BD3286B49435913ULL, 0x3DAC25E98B9FF8D1ULL
        },
        {
            0xAA542F32C7EF004AULL, 0x5108F4D90FC72E4AULL, 0x91857E1B27A3166CULL, 0x5BCA931B892FD428ULL, 
            0xA8B3393909ECF410ULL, 0xDBA37422778D38EAULL, 0x530BE286E225A367ULL, 0xF2F290072EE3A795ULL, 
            0x15B52EA842C9B2A6ULL, 0x7D4A5DE2F443963AULL, 0x2BDFD5E21679FF99ULL, 0x79671824DB58BBDFULL, 
            0x59507692DBF254B4ULL, 0x4BCDF99FF9A9F131ULL, 0x5FADC37269B1368BULL, 0x502D7A9F64579F98ULL, 
            0x1378E5E0E3B7B412ULL, 0x712AF8E7F64BF494ULL, 0xDCB4FB62A182E2BEULL, 0x11A15CCC62083288ULL, 
            0x1F80B7662E8644E8ULL, 0xB60B2BB220A5B5C6ULL, 0x62A039519EEB8B72ULL, 0x37F89C520E77F158ULL, 
            0x3DBE91B662EC575BULL, 0x17A694E447692C9FULL, 0xB74F19003C47AC09ULL, 0x37E4B9333C87D9F1ULL, 
            0x926EFFE9D8B84C2FULL, 0xD1754DF7B4B6CEDFULL, 0x0F25CD959EB57315ULL, 0xAAAB9321278B826CULL
        },
        {
            0x8AB7630555B5D72BULL, 0x1F53E7FBAEFD84E2ULL, 0xE4599AC82E7CD9C2ULL, 0xA1E1296056EECA79ULL, 
            0xA3E86770FFF15938ULL, 0x12239553A98CBB96ULL, 0x79FBA065F875831CULL, 0x43451AB307DEF340ULL, 
            0x5B1567F757C583D8ULL, 0x8B137800BDBBEDF3ULL, 0xC7915C74BDFBAA0CULL, 0xE2EE9C1CDC238677ULL, 
            0x0990F68C54E2F412ULL, 0x03BCFBF58114CFD1ULL, 0xC6329D9E641815B5ULL, 0x3300BC0FFCD73E6FULL, 
            0x0EF52E3313F30240ULL, 0x8BCC56E8D286F18DULL, 0x24DD40D44DBF70AEULL, 0x5342D50E66630CBAULL, 
            0xC329DF662CE346A3ULL, 0x24D71DD75916EBA4ULL, 0xACA93B50D91BEF56ULL, 0x27CE0F52944BAB3DULL, 
            0x3AAFBB78CFC695CDULL, 0x5E9EDCA31BD43C42ULL, 0xBF9481D070C31A4EULL, 0xDDEF7038AC15B7B5ULL, 
            0xAD86AF8DB14AC2E0ULL, 0x5A89B7718496D2A6ULL, 0xE4B5BB77A0055B25ULL, 0x92C40A89C0C9E13AULL
        },
        {
            0x9FCDE7E242856027ULL, 0xDB0981CBF45935EFULL, 0x78263FB703048BD1ULL, 0x7F068EBD714E8F90ULL, 
            0x77212827E58BA2C6ULL, 0x87940EC97589772EULL, 0x5F7238A465FCDD93ULL, 0x711E6B27A0CE6C60ULL, 
            0xCA28FB961EE0AF05ULL, 0x5CD0EC15C222E639ULL, 0xD237182F06994FACULL, 0xF84075C47479400BULL, 
            0x0D013CCEEF406B8EULL, 0xDA57135C70623BDBULL, 0xA2E0B5E0D724EE3CULL, 0xE4CA0A69E62F34C0ULL, 
            0x7309C62A70708581ULL, 0x7974B4D73829CF30ULL, 0xDB517134BC217533ULL, 0x5E4F9ED3A1EB75BDULL, 
            0xC0DE5A98FCD190F4ULL, 0x57542E4731A259F7ULL, 0x4F0D33897139069BULL, 0x3CDD0C1A6A454B4AULL, 
            0xDE8ECD9702EED66EULL, 0x3A3AF09F05450FDAULL, 0x0415C42F6DBEE792ULL, 0x6033D753A11DAFE9ULL, 
            0x18C322C72DF7866AULL, 0x70AFF117D70CAB4FULL, 0x1E1C6DBF3634C954ULL, 0x8F9EA3865770953AULL
        },
        {
            0xA962E973BB0ABB6CULL, 0xDC1E6001771C63A1ULL, 0x7429C74D9DE3502AULL, 0x399C195AA19EF81FULL, 
            0x12BFD274485A132BULL, 0x4B68B5AFB496A430ULL, 0x7CE88EA793EAA392ULL, 0xAC2E76AA336A75B2ULL, 
            0x740938BB9B636411ULL, 0x71F67F388FCB2D43ULL, 0xF94AC548A773A4DCULL, 0x909AAF79A3731295ULL, 
            0x444E17F35B864251ULL, 0x0D78C48DB51645DBULL, 0x1F1379D9F6330C79ULL, 0x943ED288EA2576EDULL, 
            0xA952830498662CA8ULL, 0xAC75AEBF6A64F7FAULL, 0x834D9ACC3E6A2D33ULL, 0x53126864D2BB927BULL, 
            0xEDD31D78B420D912ULL, 0x4F197650DBB45264ULL, 0x73BF773F46B744CDULL, 0xF5843CEDD94DFF38ULL, 
            0x951944A989DC3BE4ULL, 0xDA763CAA2E6DF8A6ULL, 0x95466AFC40958350ULL, 0xE19B217B950E0F0DULL, 
            0x68E292F3DFFD8847ULL, 0x2FFD2843E6EED491ULL, 0x6C44A6077E0B9FD8ULL, 0xC66E134B13F28D08ULL
        }
    },
    {
        {
            0xB86383EF97FD060DULL, 0x32D00819B98CBCDAULL, 0x9A67A41F5D249B38ULL, 0xA2EA518BBE97AB22ULL, 
            0x994D5ADB847DA85FULL, 0x008BF7496A5814B7ULL, 0x28892302BE84BA15ULL, 0x55F37CAEF6498D73ULL, 
            0x2E34AA76C009B18DULL, 0x4C4D4236A39D0171ULL, 0x537C49652AA89E9EULL, 0x2FAF0EFAE227B5EFULL, 
            0x5BC56F5801E1C9E8ULL, 0xE2F3AD9319849AEDULL, 0x3123F7409A28D101ULL, 0x75D56CDBE78C969EULL, 
            0xE38DA4C0FBDBEFADULL, 0x59140D758BF2F583ULL, 0xEC3B8DC8EBEF072CULL, 0xAAD520EE190EC49BULL, 
            0x27A482AC744BE105ULL, 0x323EC5261D99B6A7ULL, 0xDB63CD6DF9C75CF0ULL, 0xAAA55F4AB5B413F8ULL, 
            0x4A1E8B1ABB2ED47DULL, 0x3C207446C60FFE58ULL, 0x622F67CF254AD7A8ULL, 0xFE2C6912F086E05DULL, 
            0x24EF39932B50270FULL, 0xC235771A1D470064ULL, 0xECE24DED0085FCD9ULL, 0xCBB63033B893DEACULL
        },
        {
            0xAB4A6BDBFCF59A66ULL, 0x7278B3B34DAEBF28ULL, 0xF8EA715BA0063B4AULL, 0x0ABC05C51DA1D845ULL, 
            0x57E9BA2DD762E668ULL, 0x933EA4EEC13FCCDDULL, 0x67ACB0E52BB177D5ULL, 0xE002A896C2C74B4EULL, 
            0x8DAB4FAFE4AB4FBEULL, 0x2467AEB97A5FC3D1ULL, 0xE178A132997061F5ULL, 0x2F629710F5E06E81ULL, 
            0xCA4A0194CB2199A2ULL, 0x8DDF66D94249E09CULL, 0x6A80556F81DCC728ULL, 0x65A641A300C097C8ULL, 
            0x66FCE869EEF15B46ULL, 0x2BECCD6F9365BFBDULL, 0x557539C8FD22FEE1ULL, 0xFB665AE36B0FA23CULL, 
            0xDA48BEA478522040ULL, 0xD9E82052BA81FAEBULL, 0xDC429A5FEDE58C56ULL, 0x181722A6169F1C0AULL, 
            0xDA0672CEC71B1281ULL, 0xDBF50C8FF981C5ABULL, 0x25F742E27500F227ULL, 0x945EEA758FEBB8BDULL, 
            0x9A7F7855C2F33369ULL, 0xFC6C6252FD373DF9ULL, 0xFF6AF634F1E6A9A4ULL, 0xBAC5622601E8C056ULL
        },
        {
            0x0614FC88A9C1C162ULL, 0xA3204C96D283C41CULL, 0xB6812FBC49D83B4BULL, 0xAD9BDA0DD10C7134ULL, 
            0x4799716F466BC168ULL, 0x35E3BC565EA235CDULL, 0x6FC71C61776249A2ULL, 0x41387D9C3313445FULL, 
            0x731B9870D6372B94ULL, 0x0ADC3AD038AE60D2ULL, 0xDDDC58E2824691BBULL, 0x723C69572F1C222DULL, 
            0x67CAD33AE4CBB023ULL, 0x33AD2364C65AE6BCULL, 0xA687E1701C8EB970ULL, 0x85F1CAF1791914EAULL, 
            0xB8407CF8F6CBC513ULL, 0x147F9AF4A1E39C1FULL, 0xC072A624B9D3F299ULL, 0xDCD4F17CB7C9950EULL, 
            0xD8514324EBDE0E5FULL, 0x5E692C74021055D8ULL, 0xD7F2973F00EC579BULL, 0x659691ACFDA3FE89ULL, 
            0x3BB8FFFF96530447ULL, 0xA135C45C8AC11730ULL, 0x9E75AD7BDE100C9DULL, 0x07B1F947D1238218ULL, 
            0x477ECB8A31383D12ULL, 0xD48718C17B7B6D76ULL, 0x7D1451606133548CULL, 0x4170F3882CF93345ULL
        },
        {
            0x5A44968DD32F327CULL, 0x6B2BCCB21144938BULL, 0x8ADDCC0DA27AB0C3ULL, 0x4E4139118E00DF30ULL, 
            0x3BF17430DCF98580ULL, 0xC7217A5D864FADB9ULL, 0xF73106E3A03AF6BDULL, 0x206EE038375ACAB8ULL, 
            0x6AEA5E4A3E659C02ULL, 0xCAC47CC8B4DB5C96ULL, 0xE2FF6C22A80DD04AULL, 0xA57D3BF781AB599CULL, 
            0x0C69336F6354EDB7ULL, 0x6D94FF6CBC8ECBCEULL, 0xE7F705041EF3075AULL, 0xA5751070166494B5ULL, 
            0xE32D9BB368BBA7CBULL, 0xA7A3E94A52214BCAULL, 0x3BC1597713B8FADAULL, 0xD76A99DAA1B68F86ULL, 
            0x741160789BBD46E1ULL, 0xBDBB18F2FA236EDEULL, 0x59301AA816166F69ULL, 0x5C71A64F5D521763ULL, 
            0x0285DD84D2D2110BULL, 0x3B9081CE2FA36851ULL, 0xD82CEBFA8E616780ULL, 0x9647AE659F066BFBULL, 
            0x3AB6EDA11EB32DA5ULL, 0x097F347EFA965978ULL, 0x90C6C67F9CB794EFULL, 0x46B56FA718403AF9ULL
        },
        {
            0xD552F9C32C49060BULL, 0x173E3AA958096947ULL, 0xE94851E78EB30511ULL, 0x37A244B22781D14CULL, 
            0xFCB8145F557EE7E8ULL, 0x3CADF2718BD106ABULL, 0x1A36127761EA200CULL, 0xD0B52F89F5869702ULL, 
            0x6E1C7412D5BAD847ULL, 0x7516B05795C40DD4ULL, 0xFEE6116C0B495E94ULL, 0xE9B4EEC2CAF39A70ULL, 
            0x91549BD6C0F96AB5ULL, 0x9FFF6886970A9355ULL, 0xA771D377C93B632DULL, 0x7A2A1C48A68EAD2DULL, 
            0x4B23FFE467F1A3CFULL, 0x5769A694F069CE27ULL, 0xB8DF01FE5254B495ULL, 0x0E832638D42289C5ULL, 
            0xEE9FCD4BBFD0240BULL, 0x9D081291D03D6214ULL, 0x7CC10897E1547DECULL, 0xF5E99B17E3E6C316ULL, 
            0x24C52D468D7E1C0EULL, 0x8C86762B3EF2FB6BULL, 0x5B34630287189800ULL, 0xB358BD1890E9D465ULL, 
            0x099FB1B6C41AE12FULL, 0x466F19B530F1CB7FULL, 0x264369E4EF84ACCDULL, 0xCDBEF1E058EB11F9ULL
        },
        {
            0x0F55F15ECF9572D7ULL, 0x1EC4354979818964ULL, 0xB491030E027780B1ULL, 0x672EF9024904EABEULL, 
            0x364EF0550DA5136CULL, 0xC626CA9FD8F91F6CULL, 0x3FDD356353357FF5ULL, 0x40A7F0459F1987F3ULL, 
            0xB6B8A97545EF462AULL, 0xFB4C53F166996859ULL, 0x003998848239E1B1ULL, 0x515519B9551ABFC3ULL, 
            0x68621996DF3FDBD7ULL, 0x0F7D59D3C7D7372DULL, 0xB383ABE933EE2B24ULL, 0xA48288C8767D030FULL, 
            0xC31FE8F5C11BAE0EULL, 0xE8EA9BAFC1380BD6ULL, 0xF7DD0A9F8A48D82FULL, 0x56F7F7281EB73855ULL, 
            0x22FFCE99C1500F2BULL, 0xF9E18FA8E455A218ULL, 0xA9C4DBE977FA8053ULL, 0x1A6D42A6E7E9C14DULL, 
            0x71A90545DC9A0D9DULL, 0x6F790E6A5D2F08D8ULL, 0x221A2BBDB1AADFBCULL, 0x1448F295FD1222E5ULL, 
            0x881430DE2702B445ULL, 0xD54215BFECC087C8ULL, 0x54857A4CB0D7BD71ULL, 0x81FD45412555BA51ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseFConstants = {
    0xCBF75CFC3AC49C45ULL,
    0x3A581C8FA9FC49E1ULL,
    0x0E99C3CC24DCEE4CULL,
    0xCBF75CFC3AC49C45ULL,
    0x3A581C8FA9FC49E1ULL,
    0x0E99C3CC24DCEE4CULL,
    0x21CCEA89933154E7ULL,
    0x9E182C518E0D4A9BULL,
    0x93,
    0xCA,
    0x41,
    0xFE,
    0xFA,
    0x18,
    0xDB,
    0x04
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseGSalts = {
    {
        {
            0x31BB4004A44C9FBEULL, 0x43E6A935D5DF777AULL, 0x56A4CDFDAF559CD3ULL, 0xFB5606D1503E162DULL, 
            0x9D9B7F659E02F090ULL, 0x009700FEA63E17FAULL, 0x12AB33CD2AB4E101ULL, 0xBC91D99B4ECE2F48ULL, 
            0x4FBA2E84C979E897ULL, 0xCD95EEDE3511DF79ULL, 0x2592D9C470AFB791ULL, 0x7245E10401E36B41ULL, 
            0xAA9FF901580C2850ULL, 0x9AAD6E49CB2A7EEEULL, 0xDBE2896B37DA4919ULL, 0x92FB78A3194EE031ULL, 
            0x0FE97B5DBDC8173AULL, 0x0C0AD4B48BAEEFBDULL, 0xCC64F4AB3548663FULL, 0x8E621CFE21D9B567ULL, 
            0xFCCF1D6461B8353EULL, 0xDC4DD2974FC2B4E6ULL, 0x3B086A1967BB022DULL, 0x7632CB8C9081F198ULL, 
            0xFD095E1EA7966DF4ULL, 0x302315FE651D5713ULL, 0xFAD09AA5FFBB09A5ULL, 0x3D9F185A40EEE7BEULL, 
            0xA9506E1C748C0AD7ULL, 0x8E3B290CFA99D413ULL, 0x3503FC7B5A5A34C3ULL, 0x83C979D209ABF07CULL
        },
        {
            0xF4D2DB218D491E5BULL, 0x3365551E9E6CBB21ULL, 0x814823A7D682C02FULL, 0x9FEEEB3A1CEC5F47ULL, 
            0xC3B7218A323B9494ULL, 0x727AEF65BAD3A493ULL, 0x8B52C6E2902704C8ULL, 0x1B1431F687CC23E6ULL, 
            0xE6F70C2C5CFD5D19ULL, 0xAF392FFFB344807FULL, 0xEB2B36E26BBC7C51ULL, 0xD749C0125F524BB6ULL, 
            0x37AFA1DDD436DB69ULL, 0x570A936E1FC1E4FAULL, 0xB9345A3D9F68D64FULL, 0x7C85104C2411B9E9ULL, 
            0xF27192391A160B5BULL, 0x34FB26791C68441EULL, 0xB179EA9E199E41B8ULL, 0xD13942F885826954ULL, 
            0x06B57CB6618D5AEAULL, 0x50B45B05641514B1ULL, 0x04B80A4C311A5DBCULL, 0x9DF556C863E110ABULL, 
            0x991BF6065936FA47ULL, 0x77BA4C14870971EBULL, 0x43073611EEEAB709ULL, 0xC62A07B65185A65FULL, 
            0x96B16CD49AF00B59ULL, 0x5B7968F09030AA7EULL, 0x90CF218A9C8067D0ULL, 0x36A74E0810B7C2B2ULL
        },
        {
            0x0E244B752EA40AB4ULL, 0x0F6968330AEC93B6ULL, 0x8C9FBABE77D973E2ULL, 0xA09CB9662AE7E1BBULL, 
            0xB12AC722BDFDDA74ULL, 0x7A64787B449A1C25ULL, 0x3FC4F85DBA430AB6ULL, 0x416D5FB9E5BFAADBULL, 
            0x9A5FC5A98F765F9AULL, 0x7828154C97CB5E42ULL, 0xDE7AD928CDA472F8ULL, 0xC0ACCB4577355B99ULL, 
            0xD66BEE2A76E2B232ULL, 0x0A76FBD483095205ULL, 0x3E6F02CBB021543AULL, 0x626B3C494716CA9AULL, 
            0x839C02E04F36977FULL, 0x7C8BD59D27B1A64AULL, 0x6F07847106F973AFULL, 0xCA2CC68BD470642BULL, 
            0xA5563A63B0A9173FULL, 0x60F62E60C8E2B9C3ULL, 0x37869C43BF9CC378ULL, 0x43EC1BE2AF90102EULL, 
            0x8BFCCFE5EADA1B30ULL, 0xAC456D82396F2136ULL, 0xCE3B95FBD2BFFD1CULL, 0x305F612AE3DC35BCULL, 
            0x38CA266F5F80AF4EULL, 0x4E54BDFEBDF0DE75ULL, 0xFA3E75AA1945ED5EULL, 0x32083A23D8566870ULL
        },
        {
            0x114B741B8F515AE1ULL, 0x76674D770ECBCF87ULL, 0xA7D9D0CF27B536E2ULL, 0xD25DA9D1F84CB552ULL, 
            0x395067D61215BBB9ULL, 0xE7CC8BB348EBDF6AULL, 0x0C56F17720B91A85ULL, 0x771F9F648DD596C0ULL, 
            0xFEF1C5F6CC631C04ULL, 0x5FD72A66EEC37648ULL, 0x40C28521048B68ABULL, 0xA0C7BEE663DDA120ULL, 
            0xF8F22C5F56F3FDC6ULL, 0x8597AD095DDC4AADULL, 0x4E9EB2BB224838E9ULL, 0xFB78D6162B8277B8ULL, 
            0xA91CB878E5F22206ULL, 0x0FDACB3CCB429ABDULL, 0xF60CCFB9BE7C6AF3ULL, 0x234E0135937CFD0BULL, 
            0xD6E7A48952855A2EULL, 0xB0C5B69E9BC9D444ULL, 0x3480C078DFF3B037ULL, 0xFE253E4B6502046CULL, 
            0xA562804BD73BDFC9ULL, 0xA72A9E802C33ADB7ULL, 0x199AF893D1D8FF2FULL, 0x028BAC4EE74735A7ULL, 
            0xE52DE6C6338A62EAULL, 0x222A6A04D4D32F37ULL, 0x4EA54CC1E7A7C9F1ULL, 0x64CEEF9F19767590ULL
        },
        {
            0x83203BDA5419A42EULL, 0xC27742A87F2C3C1EULL, 0x9CCFCB33A6E23875ULL, 0xEAEB14A82CEE6967ULL, 
            0x737AB35C9A13CF05ULL, 0x1DAD3FD603522341ULL, 0x199847C3C5139A85ULL, 0xAFC049080D9C4FE3ULL, 
            0x646C205A3C549D5BULL, 0xC4EF4C6657B4F427ULL, 0xE9E87EE0A8126BAAULL, 0xF08D12B3EE112D83ULL, 
            0xE49072B60F23EB74ULL, 0x4DD774341E692D27ULL, 0x9128EF52BEEF5346ULL, 0xEB7AAA99C85DA38FULL, 
            0xDCF2F5C5FBFBC35DULL, 0xC64C58904E9744C2ULL, 0xB32FCE2C133DB507ULL, 0x81F1E7083CD487BFULL, 
            0x834966814AEF49F0ULL, 0x43875FB47FCCFE68ULL, 0x7DA49E25A201D1C9ULL, 0x575584EDF683EAB8ULL, 
            0x8F88D398DB155756ULL, 0xE8CE80AF4C352947ULL, 0x6B455F960FE5B908ULL, 0x5528B60B49CFE500ULL, 
            0x01E1C1C88DEB3B34ULL, 0x6A4C84FADF0DB952ULL, 0xB7E9F0367C7898EFULL, 0x4F238E893BCD886EULL
        },
        {
            0xEE08DE7CE2FED3D0ULL, 0x63DCF72A13460758ULL, 0x57DC8D3D1FD70D94ULL, 0x4C393CD0FD04E777ULL, 
            0x03BFE4C7C04CAE65ULL, 0xF88066E8F5927AA1ULL, 0x34F9494520065546ULL, 0x61B31788FAC5A022ULL, 
            0xF7F192A9600D08BCULL, 0x06E58AF25C474CB4ULL, 0xBD9DA8EF801AF93FULL, 0xFA964E4750757F3FULL, 
            0xE671E032CFAF5BB0ULL, 0x2AFCB4B6B184AE2BULL, 0xAED67A474BAD9A3CULL, 0x35A0B440B47CD6C0ULL, 
            0xBC9D0F30FE0B3035ULL, 0xC9647A3AF4999E3BULL, 0x159C83B187E183D2ULL, 0x062D050DF55376D7ULL, 
            0xD87FFF3B98ACC055ULL, 0xD80989D9270FA4A8ULL, 0x388579C55441FBBEULL, 0xC4B50D8EA150FB98ULL, 
            0x7FC5D295DED8895AULL, 0x70AB736E228C63DCULL, 0x6954657D8E8058CBULL, 0x5388760490AE97ECULL, 
            0x87F900DF7CE0B1A4ULL, 0x879BDE500C0F3783ULL, 0x783F9A727DE2E154ULL, 0x50F3ABD0DF4BA82EULL
        }
    },
    {
        {
            0x9DBF5217928C5D56ULL, 0x60E1BC026217C0EBULL, 0x3011C419C0876EA8ULL, 0x9557F74A18DDD0D1ULL, 
            0x3F2E54A544EE4634ULL, 0x76D6D9825B0DD5EBULL, 0x5D532DD9FAD40352ULL, 0x8FC34D3CF772585AULL, 
            0x40A4E7B41232850BULL, 0x865392941A5D42CCULL, 0xBEA5C7F6A0EC570AULL, 0xC13F76AE03D96458ULL, 
            0x7BA18428875D9A58ULL, 0x9DD4398A4750CD22ULL, 0x13DEBF438F498DBCULL, 0x5DD9AA369FBF2DA6ULL, 
            0x3347E482D8B5AB2AULL, 0xBBB728BAE14ED846ULL, 0xE642CB2E6E620D42ULL, 0xEDF9B31D1116A12FULL, 
            0x16B1E386468EA166ULL, 0xF29CA813C92BC8A1ULL, 0x156904E899BCE3C2ULL, 0xDA949BBA1CE858BFULL, 
            0x2E8CFA53C298FAF2ULL, 0xD1FA07D357AAF955ULL, 0x3929A1CAEB66A3ACULL, 0xDDE11869D505DEFBULL, 
            0x5112035802FED8F0ULL, 0x24B2E07F295B5029ULL, 0xDCADAE8F6D54FC99ULL, 0x3E72288F0B5D6446ULL
        },
        {
            0xFB6EFB139EAA422DULL, 0x096D0217A34F9AA4ULL, 0xB9BC37EA39E00986ULL, 0x8893CB59C34AB01CULL, 
            0xA016DCE9CD430282ULL, 0xEDAEE1333DCB0616ULL, 0xB2CB25D059371DD0ULL, 0x9C2AE84335A6F744ULL, 
            0x28A762F6498F410DULL, 0xFC0E5758AB87EFD7ULL, 0x3BC18FDBDCF16228ULL, 0x717765FF20AE8868ULL, 
            0xBA54A5D8BAB6F733ULL, 0x96E2544F8E71F8C8ULL, 0x2BD838282F10FA63ULL, 0x1BD27013BCE50815ULL, 
            0x8B956BB3C77291F4ULL, 0x4CCC8CD2AF41641EULL, 0xB7F9673E4BBA21B4ULL, 0xFF0236BD1CFA6FCAULL, 
            0x2B81F61883ECB209ULL, 0x9D36F0F71F0E8D64ULL, 0xAB821A9147ACC851ULL, 0x85B5CE794C5B2B24ULL, 
            0xEC016C97E27E18CCULL, 0xBE67ED3524BC0122ULL, 0xCE848F51770603AEULL, 0xE13BFD760161625CULL, 
            0x9122AA651EFACE13ULL, 0xA443275F357DFCE8ULL, 0x729569576046661AULL, 0x1682765ADC29BCB5ULL
        },
        {
            0xDC041858FDA6F6F4ULL, 0x526C62E7E9DB82BBULL, 0xB7D8D415D3424041ULL, 0xD6C9C94650982E1AULL, 
            0x10926DB154BDA953ULL, 0xBC8FCAC59FB609E5ULL, 0x81EFBC44BC74D47BULL, 0x0E473062C56C39A1ULL, 
            0xD36695C063A6D28AULL, 0x9E328BA386ACFBF6ULL, 0xD8C666EF82D20575ULL, 0xDC2644DC0E5AF571ULL, 
            0xA6C21EC3A760D07CULL, 0x84D37C04F58A1795ULL, 0x2EAE77675D60E5DBULL, 0x3AD90EFEF325C0B0ULL, 
            0x75D36C3CFE9232F7ULL, 0x8430F3DB5C6BEEFDULL, 0xA086A610A9D2801CULL, 0xA974117E64D103A7ULL, 
            0x7409BAABB18349F8ULL, 0xA92829D9DE3A6E82ULL, 0xD969BAECEB776C88ULL, 0x2EAB289F64D36C43ULL, 
            0x56861B14D7AA572CULL, 0xD72B0099B4D082C3ULL, 0x2AF0E3B6373F2878ULL, 0xE22FB4F95125AC00ULL, 
            0xF4EB9E9D1C30222BULL, 0xD4187FEE7FADF733ULL, 0xB4C6DD852D70EA93ULL, 0xC9D2C185520D5954ULL
        },
        {
            0xEE7C7FA0CA10A577ULL, 0x76428EC5191428D2ULL, 0xCA773FC5CF262F27ULL, 0x9C915799387C2AC1ULL, 
            0x3FA3A82DD1993426ULL, 0xDB3378BF2FFA56E6ULL, 0xE5C3C7B8615BA9A8ULL, 0xD1228F3D72F58E77ULL, 
            0xCEB3837CD73AC649ULL, 0x1C2A0E9EB91C0477ULL, 0x910CEC80AA91D4FAULL, 0x354E9559115AF413ULL, 
            0x64D63D4361D6003BULL, 0xD5013EEA8880D3C4ULL, 0xD29E460E6582F624ULL, 0xCA1E7DA23727B9E6ULL, 
            0xDE346A800C94AAC5ULL, 0x615D8E6F5C49EB4BULL, 0xF8B28A4C5C25D0FEULL, 0x9817159CC03CC13DULL, 
            0xAF1D8CA55DE5DE7FULL, 0x2B91413C8A64478CULL, 0xE98A8F39E486F078ULL, 0x9A93436B29694399ULL, 
            0x777EDAAE53021676ULL, 0x2BD4A4B469E1E04CULL, 0x3F2D315C4E593063ULL, 0xC89E4046BD887064ULL, 
            0x95BAC4F70686203EULL, 0x506B1DACCA881D65ULL, 0x56ED3EC1E9431EB9ULL, 0x446498557E11F682ULL
        },
        {
            0x4F53B473C41ADDD4ULL, 0x86229A5C6C13510FULL, 0x072F7252C2E2C2B4ULL, 0x1B5066015F0B01C5ULL, 
            0xCB44CFDBA229D5E2ULL, 0x3098486BF390AE55ULL, 0x5A782732CC6DF64EULL, 0xE21AC1E71ABC5A27ULL, 
            0x0EB566572EAE491BULL, 0xCCDC81BCE0D20B8CULL, 0xA490D8EDC26141DCULL, 0x090570DD4DF19D45ULL, 
            0x48E18D452DD9FAC5ULL, 0x9A3F9CECE33CB58FULL, 0xB80E3EB8468C2283ULL, 0xE623BBBF38EA7859ULL, 
            0x7AB60990EAC01E4CULL, 0x1A234BFE6CB6549CULL, 0x1B022121E2FFB052ULL, 0xC6E6B47853AD298FULL, 
            0xCFC662D1D74B56CAULL, 0xFC976EAA004CA0FDULL, 0x51DA80C22AC53FC9ULL, 0xF2E637CB0EFE480FULL, 
            0xE0BEC5A0DA8B4549ULL, 0xE7C2ED096D7E7DA7ULL, 0x79223F66D6F70E17ULL, 0x0BCF259687A1AB0BULL, 
            0x26F9107D31A34600ULL, 0x58C69216F56A1EC6ULL, 0xB8BA0085DD5B7E44ULL, 0xFD06C80287977044ULL
        },
        {
            0xAF309EF5354E7871ULL, 0xEF20CFA8144E34F9ULL, 0xEAF9038BE08863D5ULL, 0xC160667C97ED5488ULL, 
            0xA5F42EE8AEBDD7AFULL, 0xA3093330AD229B65ULL, 0xEA59CA6F0790A04FULL, 0xA3A8FBA649AC0CF9ULL, 
            0x21A803F7771AFCE6ULL, 0x8424ECBD2136DD0FULL, 0x5E5B4E4EE4BCAC1DULL, 0x5DC1A3B10AB5C2FFULL, 
            0x9E686722C9B8F67EULL, 0x5A2490423748137DULL, 0x5BF344D312996B34ULL, 0x07F1E3EA31C91F28ULL, 
            0xB81BCF61B34C87F9ULL, 0x12593AD736FA73FFULL, 0x0A788E90565CE6E0ULL, 0x5DAE8F98870DCD67ULL, 
            0xAB7A66AFA02C82AEULL, 0xE262004C6CDE1727ULL, 0x31BCA6C1E90E0395ULL, 0x0E4685D88D77D1CCULL, 
            0xD7E2F9B6A919E6C2ULL, 0x80F5386B8FB62FCAULL, 0xAD91A838DC527333ULL, 0x1DA1BE6867BDFA2EULL, 
            0xE15FEA8C3BEFF6D4ULL, 0x42E3B892D6B58C6EULL, 0x25D1882205FA4376ULL, 0x3F91D45141A4ACD1ULL
        }
    },
    {
        {
            0x05AA3823246114E3ULL, 0x14814038FA862A2CULL, 0x64B98D5376A5C3C8ULL, 0xFD2B4754F83930F8ULL, 
            0xC032BAB28D60D8DAULL, 0x4071506AC99FE895ULL, 0x31523D17C2135F0FULL, 0xBB8FFBA7174082EAULL, 
            0x88B39DEB35E3894BULL, 0x038A5A9568E8B5FAULL, 0xDC68B344E04D89D4ULL, 0xCFB1F88C56D1E6A4ULL, 
            0x26C295DD5BCD20FAULL, 0x3D9957DC119DD342ULL, 0xBD94DC94E1597F60ULL, 0x2EE684E8940DE379ULL, 
            0x9EC4A340A96F4C25ULL, 0xEA2E864C841D43DFULL, 0x82C81941377669CDULL, 0x1C0FB538DDCD94D7ULL, 
            0x09B2690C746C5900ULL, 0x9927768FCB98BDFEULL, 0xFC40F00FB1AA7774ULL, 0xF13D17F6843F8AE1ULL, 
            0xB750E95F527EC8E1ULL, 0x3E046257A2E6CAC0ULL, 0x4DCE16133B7B7EC0ULL, 0xD6F1101ABFFFEE60ULL, 
            0xEF7C1A8FFAC0DA70ULL, 0x0D8EB20E1096FCC0ULL, 0xECA416EADB2EB9DCULL, 0xEFD08499FB0433A3ULL
        },
        {
            0xF7AF59007F8D92AFULL, 0xFA502CD258DBFA53ULL, 0xEBB853267042A6B0ULL, 0x81CF782B9888D5DBULL, 
            0x8C5378ADC83C39D6ULL, 0x55A8FEC71B5B7DE3ULL, 0x88F60A46A95ED568ULL, 0x0FFD828D858FEB45ULL, 
            0x86E9071BD5E63284ULL, 0xC9B71D61DEC2C920ULL, 0x20C7F993E75BA207ULL, 0xF202B461E2E53577ULL, 
            0x3E6B9B308477059CULL, 0x77C2A54D894CED16ULL, 0x279126F478E3E71DULL, 0x252A00222DBAA49DULL, 
            0xAABCCDDABEFBBF6BULL, 0x7C589425A35EC27CULL, 0xDC60205205A76F8FULL, 0x5BD48F02B6FE45F1ULL, 
            0x8235972B9DFBE68EULL, 0xFD7B6CBB82839000ULL, 0xF12285C59CE4467DULL, 0x5981247C7C7287E4ULL, 
            0x08C7047ED647ED93ULL, 0x0E34F28DE08893E9ULL, 0xEB20B385507CDB0CULL, 0x6615D13C9C5B258DULL, 
            0xF0D8FFCD0633114EULL, 0x8979E17EAEB7E668ULL, 0x6C7C89E5653F00CCULL, 0x31E75D674FD45102ULL
        },
        {
            0xAB30E7DC94680CC2ULL, 0x29DE1ADF1690932DULL, 0x815F7B0A2054C36DULL, 0x9B43875284EEDA45ULL, 
            0xDECCBAC79A7643BBULL, 0xC0B906913FFE7F38ULL, 0xEFD51BEE48C161E3ULL, 0xA16D8A3124EE6D4EULL, 
            0x7742FC2A2FB909B8ULL, 0x4E89FC6CCEB8478FULL, 0xFC262CD6B40025C3ULL, 0x8F7C7F93BE86F98DULL, 
            0x25FDE6C6F92D779FULL, 0x5B98555388728544ULL, 0xB03414285B069A9DULL, 0x9935119EC1CECCCFULL, 
            0x68522B6F849CFC0AULL, 0xF264990F65C590EBULL, 0x5D176FACA7DE168DULL, 0xA957EC0743C29FE0ULL, 
            0xEB24DB1A58AE693FULL, 0xE98A25CEEB7D8BDFULL, 0x56421274C23F5670ULL, 0x843BDE6237891F12ULL, 
            0xC7C9BC2CB765DF50ULL, 0xF4BE382E37BF2144ULL, 0x467FF227F67DC12DULL, 0xB1DC74FE5E6F32D0ULL, 
            0xB762B7FEB38AC4D7ULL, 0x672D7F9EFF55C868ULL, 0x7722F1130F1D1BF5ULL, 0xFD22A6889C71E5F1ULL
        },
        {
            0x514E0B0EFC3FA295ULL, 0xF98E0A02C4CFEDC4ULL, 0x8109F540CFE94FE5ULL, 0xF2FAE9D5079C1E1AULL, 
            0x59FBA4ADB3C06C87ULL, 0x47A2CB3A7753544DULL, 0x3A0FF1605924F97BULL, 0xC09232F198FB871EULL, 
            0x53B450F609FBB31CULL, 0xF394C9E2B2EB1894ULL, 0xD1E12100B8DDC49EULL, 0x9C470F4A7450247CULL, 
            0x7E21370802B0C301ULL, 0x08CE7D368A17FEDAULL, 0x1130FDAF40025121ULL, 0x12AA0C7DD9ADF909ULL, 
            0xF2E74D61FF609FF4ULL, 0x3E54ED978FFDC186ULL, 0xCEA1299192BB9235ULL, 0x524587DFD83956EBULL, 
            0x8F34094CE898D96DULL, 0x5EA862EAB41FED16ULL, 0x0256454D129AE9FAULL, 0xF92138C3D65B8EC3ULL, 
            0xCDB1AB55E07A3A88ULL, 0x30E95F9EEE8055ADULL, 0x6E27D63DC5DAF633ULL, 0xE9471EBF71D46E1DULL, 
            0x909EF0CEC39FE4ECULL, 0x873BF76BEF603B0CULL, 0xCAF50FF3DD28F39EULL, 0x3DCC929561039D12ULL
        },
        {
            0xC313DC4BCD6871BCULL, 0x35138C8ADDA22D45ULL, 0x05DA3BAC6989135BULL, 0x7440E0E667FBC036ULL, 
            0xC44A430424E6E6C0ULL, 0x5C8D3F2822B2F959ULL, 0x8DAC8EF2B5738A6FULL, 0x894B6D9C366FA5AEULL, 
            0x4E7192EEF4B84F35ULL, 0xD25DF51CC3E72A6EULL, 0xD0AFB90A81FBB3D3ULL, 0x8BF9F94494A03AD8ULL, 
            0x356684BDFAB90473ULL, 0x11E04EF51F59839FULL, 0xC7417CE8F78AF291ULL, 0x8ECC0FC3ED866BC7ULL, 
            0x9661EF4265CF93B2ULL, 0x3FA99996C5E80EF8ULL, 0x706D826E35FBAFAEULL, 0xD1A3F159A3143EA2ULL, 
            0xE3C3D7E5B51DA809ULL, 0x3B8FA08B290A9D64ULL, 0xDE837806D618D370ULL, 0xA62F95F70BCB6526ULL, 
            0x0B242EB322E394CDULL, 0x0DB2E3342BFE1B8DULL, 0x6E89A3530DBAF22EULL, 0x32693862B2AE3C86ULL, 
            0x7493AA7EC6EE19F1ULL, 0x586A60C70E60B0F8ULL, 0xB462F4D89FAE0B1AULL, 0x6CE90E375E26D0CAULL
        },
        {
            0x52A1F5F972D67857ULL, 0xCF25C96444DC4F2DULL, 0x5975E88A8ED8B998ULL, 0xA4B5AFE4AE4AD41EULL, 
            0x3B4CAB577C75A095ULL, 0xA0816AF35D564B74ULL, 0x5D1E831CE4B20C46ULL, 0x40F6CBD5A08D50B3ULL, 
            0xA2DBC9454F4673FDULL, 0x691BCE4F436FCCA3ULL, 0xE130C5E0B8550797ULL, 0x31646013FD50B12EULL, 
            0xEA6DF3685FC7042AULL, 0x171999D4754901A3ULL, 0xCE9EA35A51F2133DULL, 0x8E7879CC07DEE001ULL, 
            0x6F1C99644991D2ADULL, 0xFD003F002EE5D5B6ULL, 0x221C3E04FDDC7CF6ULL, 0xAF9631947042FE47ULL, 
            0xCA197CBF9E9EFFD0ULL, 0x5656A4E77D2C0031ULL, 0x901CFE29A057E805ULL, 0x6E7B32FE36681E9CULL, 
            0x61874BFDD449C5EBULL, 0xB0F155DD72E16CBAULL, 0x1313BC9D2C8ABE1CULL, 0x0BCA4C405F16CA96ULL, 
            0x7EA4D0B67A074330ULL, 0x08549270DA63998EULL, 0x4677088458AA3CC5ULL, 0x5C9DD62214171BAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseGConstants = {
    0x9CC1CD00097A874CULL,
    0xC08049F3B316F4B9ULL,
    0x5AF7DE8A1FD05FFEULL,
    0x9CC1CD00097A874CULL,
    0xC08049F3B316F4B9ULL,
    0x5AF7DE8A1FD05FFEULL,
    0x1CDAFF3EEACA164EULL,
    0xEA174C725BA44586ULL,
    0xF9,
    0x35,
    0x9B,
    0x85,
    0xCE,
    0x4F,
    0xC0,
    0x99
};

const TwistDomainSaltSet TwistExpander_Boxing::kPhaseHSalts = {
    {
        {
            0xB628ADC2C33DF715ULL, 0x666CF55C1680AA0AULL, 0x3C2D156BF272F3C1ULL, 0xB5D2BDEE397F9406ULL, 
            0x642BA459E1561232ULL, 0x39D3E0FB63FB21D8ULL, 0xF653870D7C530E4AULL, 0x7FB63CD1ACCBC2F0ULL, 
            0x313AC86D78595AE0ULL, 0x28AB5366100CDD14ULL, 0x282CFB878BE93495ULL, 0x3FE5B4593C44390AULL, 
            0x2C8A32171D0B8119ULL, 0x1F08C983C7B45C7CULL, 0x5AFF67466307FF2CULL, 0x668CAE94B04D85CCULL, 
            0x8FC9152DCD9F63C5ULL, 0x3535B68FC2E9A8F0ULL, 0x4D8AA59ED4E3A955ULL, 0x6497B18276CC80D5ULL, 
            0xE7E7F561A0A6C3D8ULL, 0x3158181243A7206BULL, 0x67AAEBD44017D991ULL, 0x686668A890BD5E4AULL, 
            0xDEAB9D2FAAF97D9CULL, 0x30E2E8EEA70A6518ULL, 0x5B4999EEB389C846ULL, 0x19B7DD492894D1EEULL, 
            0x8A78A0797EF8D9A2ULL, 0x529D16C4AE7F99D4ULL, 0x61CB67ED296AD446ULL, 0x4B550DA1EBC87198ULL
        },
        {
            0x554003F98E025E69ULL, 0x851700F6A531AA5AULL, 0x0CBE5E3E19027776ULL, 0xACFDBAD8E13F56E5ULL, 
            0x3D6B53661A774744ULL, 0x21CF01892A20994AULL, 0x14D0822105010E7CULL, 0x1C164B2F726C0883ULL, 
            0x1DD5F37106562EB7ULL, 0xDB743469BF5E1299ULL, 0xC05D40E02A5E2783ULL, 0xD6C297B7F718D24CULL, 
            0xE08D9FC5AEDC4F27ULL, 0x789F4DCC272375EBULL, 0xB3EB8B31EC8CB0A6ULL, 0x4C417C959580F649ULL, 
            0xC731AAE39FA01016ULL, 0x7CBFB058E25312D0ULL, 0xAA911FB3E26DA804ULL, 0x2E85E757CC8413B5ULL, 
            0x473604DF68D2A7F1ULL, 0xDB42E0CD2508666BULL, 0x5B964D337AD08C0DULL, 0x0136F7927727FFBCULL, 
            0xB15996A798F18C19ULL, 0xF777EF2E03E24275ULL, 0xA485421D47A0B6DCULL, 0x930DE71B4F631BE1ULL, 
            0x70137F6979A37485ULL, 0x7849B4DC62A80750ULL, 0xD7EAAD65CE68C697ULL, 0xDEC8296507122383ULL
        },
        {
            0x8F603D8F3AD9BC23ULL, 0x32DEBEB2605445F0ULL, 0x38E7CBAF10E513FAULL, 0x12EFAD74F046138FULL, 
            0xE822FFB52703E8B4ULL, 0x8AA17645A90B7870ULL, 0x8507FF4643D383C9ULL, 0xB034005334BEC1AAULL, 
            0x438876A58548C024ULL, 0x46B5942F3066D70CULL, 0x379F311605718968ULL, 0xD86C2B99C0D8F01EULL, 
            0x48BA4B48E4639262ULL, 0xAE1D924AC6B9AF71ULL, 0xFE8E8ED356ABDF35ULL, 0x0E47E6AAEA9EF22DULL, 
            0xD37CFC325FF98743ULL, 0x4A971696C8843607ULL, 0x5C4F3E972226F231ULL, 0xE6C49E35F2A437D8ULL, 
            0x7D232F5D9B5F58B2ULL, 0x60214723DA1A11B7ULL, 0x8696A5373E66359DULL, 0x0CC8CEB5E7EB5334ULL, 
            0x9CD1BDB124E02026ULL, 0xEBD85F72A9A2284EULL, 0x014DFC483BBD9B2BULL, 0xC3404F44A97DDE35ULL, 
            0xCF9C5598E3D6C37DULL, 0x64A8D6FB9C4C16FEULL, 0x47006456F70136D7ULL, 0x7944A0A6CA1E909EULL
        },
        {
            0xF1EECA72DC9A2F97ULL, 0xE69D9B9A0B454E32ULL, 0x299CE0FAD9E760FFULL, 0xFB5431907C8199FFULL, 
            0x7CEB88168F0FE5E7ULL, 0x5DE49F537319A17AULL, 0x74209ED4A687521AULL, 0x3B29F2FA1599461FULL, 
            0xF1D262850E2EF73EULL, 0x6741A49F256AE406ULL, 0xDE05E852A1FFD411ULL, 0x3DA826E01A8FB5FEULL, 
            0x510462C7F669FC52ULL, 0x80AA086F5C784B94ULL, 0x1B751A0CF915F6F1ULL, 0xE5C70FC096A77457ULL, 
            0x130ABC7CEDDB24A3ULL, 0xED1248E26EC7EC66ULL, 0x40599E9BD470DFF5ULL, 0x9C43CD6D18B4918CULL, 
            0xB0C89E29194593E7ULL, 0x4760CFE23A61E2F2ULL, 0x9D5CE358395973A7ULL, 0x361484C09F2B0994ULL, 
            0xE6DAD5357EE1E17AULL, 0x6E84CC05223F8E4FULL, 0x33740367E972065CULL, 0xF6012005779E7A81ULL, 
            0xAAAECA7B3C0D5ABCULL, 0x9B874240DBB18B47ULL, 0xF97FD1E186B87046ULL, 0xDC7E3790773E0AB0ULL
        },
        {
            0x6208465663C563A2ULL, 0x225B58680ECA205CULL, 0x6EBC0F429099698DULL, 0x26426C4AB85C242AULL, 
            0xFCDD7F06DF1E4AECULL, 0x163AF3D0EC5BF476ULL, 0x8D218BD6655A11E9ULL, 0x12F189B94F1F7742ULL, 
            0x9741A7A189A2F926ULL, 0x01F098E6DC36D1BFULL, 0x60D2F249E3E41ADAULL, 0x16BE4ED5150AB9A6ULL, 
            0x3C4CEADB538768A2ULL, 0xEAE4E5825536802DULL, 0x481E8AB0B8973E75ULL, 0x59D6950E764EE41BULL, 
            0xD97EA6AF310EB231ULL, 0x234FC5B1DD1D5F1DULL, 0xC16888B32939FC88ULL, 0x3B3C6220D8513C3AULL, 
            0x962E00222C8D7595ULL, 0x65DD24D68DBE6B1EULL, 0xE3496237A5DDBFD4ULL, 0x738979B2CDBE5F60ULL, 
            0x95124DC43F99F153ULL, 0x325FD5B40F11F425ULL, 0x56EEB2699B73366FULL, 0x0A8BA6C06DF2F586ULL, 
            0x30BBB5ACBBF2AECCULL, 0x1D4A55996BDE132EULL, 0xCF8045A415C1EAFEULL, 0xD1698E4D5DAFB81CULL
        },
        {
            0xA139B0E765345347ULL, 0x98E82B149145CA92ULL, 0x196492088DC0215EULL, 0x944FE8C2CE43D681ULL, 
            0x4E5CB035227055FBULL, 0x6188CAABE5A912ECULL, 0xFBEB6D17948560C7ULL, 0xE7F58A28CDF2BE5DULL, 
            0xAB4AA5621C5390EAULL, 0xA1D724230118CFFAULL, 0x2F9444598A1D8843ULL, 0x07C0CED942E82EF2ULL, 
            0x152BB4F4C2FA633DULL, 0x3666DAD928802C64ULL, 0x27040AD3BA33D680ULL, 0x042565C4AE6F91FEULL, 
            0xC0557C3391C1869BULL, 0x88983B1634AAF55AULL, 0x880AD9590B3983A1ULL, 0x096ACECB3A53E0A1ULL, 
            0x01094DA74ADACC3AULL, 0xAD84055F528D5596ULL, 0x34EADE0C82A60B6CULL, 0x8C91CC18C137F606ULL, 
            0xC1C2C201459ED7E5ULL, 0x8A89D1181DD8EA57ULL, 0x878B683942FFC949ULL, 0x438C12AF25F422ACULL, 
            0xE6512D9A36E35C14ULL, 0x6E5992D506FF3C9BULL, 0xA8289F6647707223ULL, 0x803EACB1A3AAF245ULL
        }
    },
    {
        {
            0x71572B1846CDAAD7ULL, 0x16FCE39FFFBC845AULL, 0xF01018D8F7A42D8FULL, 0x2237916BA5596163ULL, 
            0xDD805BEDDFD7C94DULL, 0x9810B7F76B5B07EBULL, 0xBCA043EE0F83D225ULL, 0x2FCF6736352C4719ULL, 
            0xEE9AC0BD60F33E89ULL, 0xD861182CDC948A08ULL, 0xF7F0686DBEB5148FULL, 0x0A8F4CA26A306A8FULL, 
            0xB1354C8F9C817523ULL, 0x44FD34CFD3585766ULL, 0x49C5C1D9791FC49AULL, 0x50E0DA7577C04B62ULL, 
            0x382B9A73C9A184C5ULL, 0xD20450BDC74C8B89ULL, 0xA5959D9C16D65E3AULL, 0xB38D9D518EAF641CULL, 
            0x6C1C4661FE5F92E6ULL, 0x94B6FA128B4DDBD7ULL, 0xEC20369AC63C6359ULL, 0xB65310847004D990ULL, 
            0x6733B950FFC2DEEFULL, 0x862D72C98897C2C8ULL, 0xE3BD246FC8A8C7ACULL, 0x5D8C4CEAAE834662ULL, 
            0xD86AD5EE46C2BF9BULL, 0x514A5A40C2E06B97ULL, 0x6301D0B827BDD5FEULL, 0xF9EA997808F3BCA5ULL
        },
        {
            0x956619109CEFCF09ULL, 0xA7933FD97E6588EBULL, 0x505AABDE42CA3EE7ULL, 0x45BBF4E829CC00FDULL, 
            0x92270E5D41FB27FEULL, 0x17C5D82369460203ULL, 0x055A222CEF276EE5ULL, 0x00FC78446805DBDAULL, 
            0x08CCD0D66C338DDCULL, 0x67100BDFBF48AF7DULL, 0x259921106C8FEA00ULL, 0x4E01EABB838A4E38ULL, 
            0x3DFC9CCAF1DBF4D2ULL, 0x9D5866932D70F856ULL, 0x7CF7B536F0EB88D1ULL, 0x8E312FCA531C47C2ULL, 
            0x3EDAC1F02CAACCB2ULL, 0x5C6AF87A5E1321CDULL, 0x30BAB0EA88853158ULL, 0xCA0EEB57A264F246ULL, 
            0x816E79D57DAE7C04ULL, 0xABFB6CDA3C2DF488ULL, 0xA01FC11EEC32599CULL, 0xFA253456A05A2D17ULL, 
            0x7CA4885D10494C91ULL, 0x4F43466895D68B77ULL, 0xF82CD6FDDF383413ULL, 0xE825B52CCD387FE6ULL, 
            0x4D28D354D8D09A56ULL, 0x3B7255AF7FE341C7ULL, 0xC444F1F15F7AA209ULL, 0xEBE4049FCAF43011ULL
        },
        {
            0x30910371425E220CULL, 0x18A371FA502A5BFDULL, 0x8DC3AF2E7C63BBDBULL, 0xE987A47A1008B11EULL, 
            0x6C498899FE5D2DE4ULL, 0x52C4137F68F7B6D7ULL, 0x39860AD95EAA6C0EULL, 0xCCD05A945054A798ULL, 
            0x976130B88A42A94EULL, 0x15B2F049B6F3AB23ULL, 0x67463A7844933743ULL, 0x9263145C8BB1094AULL, 
            0xE94584B70522C25EULL, 0x51E04AA459EFB6C0ULL, 0x956F7509D898621AULL, 0x481CE132A8DA51C3ULL, 
            0x1FB4F290A0272EE3ULL, 0x80BCB968906EC790ULL, 0x2306081FB4301FD1ULL, 0x3A07E3ACF6DC991DULL, 
            0xA8031A8F0C6AB630ULL, 0xC286890044DE72DBULL, 0x9B238353E5C86DA0ULL, 0x6AFD87035EFACCBBULL, 
            0x88DE28FE7AB1D2C1ULL, 0x719D020B486B758EULL, 0x4FE429A9CBF06777ULL, 0xE2DF93E263D49065ULL, 
            0x396D48BE4E4A301AULL, 0xB76E3332CED6E563ULL, 0x1D2552B543DDDDACULL, 0xDEBC7622FACB6338ULL
        },
        {
            0xD9CC17ADF62B97D6ULL, 0x0BF56DE87B78AD79ULL, 0x8B2B351631D1D51EULL, 0xCFC64ECB3A2111A3ULL, 
            0x942AEF60B0084C9DULL, 0x0C0F581D85107B98ULL, 0xF13536822CE16007ULL, 0x828DE7DA13E06354ULL, 
            0x3E51803F9C30B5D0ULL, 0x1F50431984322D27ULL, 0xEBC46D609BD3243BULL, 0xD81F9171FAE7D2C9ULL, 
            0x93B597E07C5CF60EULL, 0x3C6AF3A7EFD92881ULL, 0xD65028F85B2D80BFULL, 0xDC3EDF7D7E92EDF3ULL, 
            0x15367D304BB80CF8ULL, 0x4EAFD8D9B97620CCULL, 0x6224A1FE219B73D7ULL, 0xD9F881D0AF276B3CULL, 
            0x50F7D6A084BD891EULL, 0xB2F0635CA43DC753ULL, 0x9DAB4928CD194104ULL, 0x3B9115FF6B462BD1ULL, 
            0x93FD8734ED81D88CULL, 0xB39830A4BD9CF989ULL, 0x1172C3B56FF1D221ULL, 0xF8FF95DCDA4223E2ULL, 
            0xE444D5E69F8B7C29ULL, 0x4D5DCB7BF26BF194ULL, 0x570F799CF5322CD4ULL, 0x8648DDBC6CB62E99ULL
        },
        {
            0xFFF996E4E3F32D86ULL, 0xEA3C8737742569E5ULL, 0xB0AF79E86F0E004BULL, 0xBFC761D46DD65277ULL, 
            0xB7DD9D0AC009F0B5ULL, 0xF13509D29C12D0BAULL, 0x91ABF1BA965AF546ULL, 0xAECF66D447F4FD5AULL, 
            0xCBAA913336E381C5ULL, 0x4E3A67E31C82CD17ULL, 0x157EDEE38F5D665CULL, 0x8D6BA19BE1E28739ULL, 
            0x53BC20E560246AC6ULL, 0x9F24BA5D76BC843AULL, 0xC7FA1A08E889AFDBULL, 0x0203A8D43A9C890FULL, 
            0x42AC1C3AA4C49760ULL, 0x7E47B308F4811D55ULL, 0xF0811353A58051C2ULL, 0xB5C7EBE225F4DA25ULL, 
            0xCF72BA6045F3B998ULL, 0x4AB3DD9D55D8D6EDULL, 0x8AE132A70A1A5A9EULL, 0x47B49090964131D7ULL, 
            0x43BBA0C29BD07904ULL, 0xFA725D950BF42321ULL, 0xFFA682CA9380639AULL, 0xDAA2C26222CB4287ULL, 
            0x1D2EF9395CA0CFC8ULL, 0xF95DE3A2C7E3E35DULL, 0x5D31AD30EEE9719CULL, 0x09FC8920D26B7740ULL
        },
        {
            0xD13CB887E47FE953ULL, 0x5AAE82AA6BC5BF0BULL, 0x0479795944748B5AULL, 0x97A2BBB1F4121654ULL, 
            0xB22D023E3AFFB2B2ULL, 0x33C3E0E9E92D9283ULL, 0x55FB7386FC51A3E2ULL, 0xBD5A8A9D06CFCD2FULL, 
            0x0D91756F8B375611ULL, 0x3DEE82F6B2D130B3ULL, 0xC1ADB36A07D3EDCDULL, 0x29ED4C53373BF3EAULL, 
            0x05A57A716B2399B8ULL, 0x825B74D09E46EC9FULL, 0xC27D7DCD2E2D21F2ULL, 0xF7C285A0D850E26EULL, 
            0xBB1881E68637A02AULL, 0x151DF62AC6B4F989ULL, 0x4B9A16BD06376C90ULL, 0x5A0671094E4E1072ULL, 
            0x2EBDE4B5BD206354ULL, 0x599BD061A713230AULL, 0x9D07CE96D7A3E000ULL, 0x4238DA88831FF767ULL, 
            0x4B286BA475F3E749ULL, 0x0BE4F20F4AF3E7C1ULL, 0x37FBE07A141E5251ULL, 0xCD33F87F13387534ULL, 
            0x44A3F2C9093C78BEULL, 0xFB5A51864BE23B5EULL, 0x96CBE071A1B2EFFDULL, 0xECECC22E4011F046ULL
        }
    },
    {
        {
            0xF172306541C247D2ULL, 0x4DC4885537404B76ULL, 0x03B87FAC173344D3ULL, 0x8D57AC7E66FE1DBFULL, 
            0x3ABA299C9660B3E4ULL, 0x15885F3DAEAFB950ULL, 0x7E4B96DAE5868D2AULL, 0xD2CE3BC4AF6AF835ULL, 
            0x69BEE674904F9EA8ULL, 0x495474B1818C6683ULL, 0x59466BE32A1A87A7ULL, 0x57FCE4EC41D803E2ULL, 
            0x183E5377507E810CULL, 0x7780A703562952E9ULL, 0xF6996DC91A90958BULL, 0x3BDC862932CE0145ULL, 
            0xED529DD391BCC218ULL, 0xEBE8292A67FB723AULL, 0xA7CC62A210CA4C03ULL, 0xF605C8C5F2044434ULL, 
            0x58918B3705F2BB5EULL, 0x2B13161D172E8F75ULL, 0x2695EBAF51BBB8BBULL, 0x92C3D65A43F623C9ULL, 
            0x96D516BEA08D09DCULL, 0x712748B02011062BULL, 0x87277A085496A973ULL, 0x0273319DE059AE55ULL, 
            0xDCDC3A63680EC153ULL, 0x12C21F6E548BF54AULL, 0x2E86072EC97EEFBBULL, 0x3ED1F7793D31D366ULL
        },
        {
            0xE1A520C87791B528ULL, 0xF579ECE77FE2F19DULL, 0x4333E2DC84174E99ULL, 0x2AA9C80338EC7B74ULL, 
            0xEF69CF3ABE971CD3ULL, 0x3E5A9E5C682A6763ULL, 0xA247D709FD7337E9ULL, 0xA798A4DD7C2E2AA9ULL, 
            0x8368FD293B2D4A00ULL, 0xCD5C451CD4F559ABULL, 0x685984C9FCAFDB9CULL, 0xAE047654F11D2501ULL, 
            0x64BA3F6778EB2F6EULL, 0x24F21B7934A7CD61ULL, 0x4907EEC8D8ADF33FULL, 0x7EC4DD47C227CE2BULL, 
            0x07F562A67FC3EB90ULL, 0xE911C02039B6682BULL, 0x95C62BA56594158CULL, 0x724456C098406D3DULL, 
            0xFEEC6BE1FB9D6479ULL, 0x6F1FB2F0DCFA05D3ULL, 0xC5618AA9AC7DD2F6ULL, 0xA52AC2CC5F5CBBAEULL, 
            0x7ED821D25F0741B7ULL, 0xEADEDF8E60A9CAF0ULL, 0xD907821BD84D6BA2ULL, 0x3072F60D9CF52565ULL, 
            0xF4C1E622F5B983FDULL, 0x53FED243B29C0122ULL, 0xC079EE3714A7CBDFULL, 0x963160BC8CB28B87ULL
        },
        {
            0x91AABE2195DF74BFULL, 0x02E4827B87A54A92ULL, 0x7A9234FAFDBE0FEEULL, 0xBC0A1E8A82E5DE3DULL, 
            0x6FE54FA1ED92B66BULL, 0x3F147088057F7E1FULL, 0xB7CA5BA6BAD9BD36ULL, 0xFF74E56A37CC80D0ULL, 
            0xC3F78942E0E86065ULL, 0xB98A94B7F8596E5EULL, 0x40953E0BB1A5932FULL, 0x440D3E5F5786B07CULL, 
            0x0ABF1AE74A89FD49ULL, 0x1910D007DC3764F6ULL, 0x2F25C82C43C84748ULL, 0x1CC66C94055F0524ULL, 
            0xCA4AF3C7C04D47F5ULL, 0x8303F0B8B398A62EULL, 0x5D99F9F431963EB9ULL, 0xB8F951E0E2FB305DULL, 
            0x30C38ABA3F66058BULL, 0x3CF356790177643DULL, 0x174EF8008F5130A4ULL, 0x01090BDE0F1EDAE5ULL, 
            0x9076D416805423F0ULL, 0x64E9F2D6F926E7F4ULL, 0x409445F81F5C1BDEULL, 0x48810F1B5495723FULL, 
            0x4F5C23A8EE213F34ULL, 0xB0560FECA585E2C2ULL, 0xAF2BF43F776ED1D9ULL, 0xEF042A2F6B6225F1ULL
        },
        {
            0x5E0527FFC3499CB3ULL, 0x3C93529F43BD5193ULL, 0xDE24608549A22382ULL, 0x71BF9BBC414FD7D7ULL, 
            0xFB4E60FDC77CE985ULL, 0xF188E8ADF3080551ULL, 0x50499B475EA6CEB7ULL, 0x8774FD2748A971CBULL, 
            0xCBE6D774D2966550ULL, 0x56F0214B1BF420C3ULL, 0x52F0C346556D91E7ULL, 0xA144A911610F1BBAULL, 
            0x05D0ACFC18963834ULL, 0x608018A38960766FULL, 0xBD10F55C19EBE2C8ULL, 0x00555D2529A92F31ULL, 
            0xE77C43503758895BULL, 0xE9B52BBE8CAA346BULL, 0xE57129FEAA205490ULL, 0xD316DDCD1CE4589FULL, 
            0x9B4758E7F79DD800ULL, 0x5CCAB8BE0348992DULL, 0xF5A5CFC46872720FULL, 0xCEA08D5C35060A84ULL, 
            0x58C57C60BC5FA170ULL, 0x8D52003303FC8A11ULL, 0xD04DBF7A79CC9A51ULL, 0x287A5FB2206A1B15ULL, 
            0xCABEC56D901FAFE8ULL, 0xDABF843AC508E762ULL, 0x49637FC3F4E590FCULL, 0x26FC70B8DB3CFFAFULL
        },
        {
            0xFC775D1B94FDD98FULL, 0xBE7983A7639E8802ULL, 0x537137222C0AF608ULL, 0xD19B6D65A640501CULL, 
            0x2C8876D6B4F33997ULL, 0x02BE81CF651F698CULL, 0xCCC2A294226F828DULL, 0x14A521C27FE60AE9ULL, 
            0xD0AEE45785290E89ULL, 0x34EB7B770B193C7DULL, 0xF22F7AC21C02BD59ULL, 0x16A3DDF0F7E717D8ULL, 
            0x86187B0CBDDCDCEAULL, 0xA3C59253B0D8A33BULL, 0x334C1880BD8FA9FEULL, 0xCA9587033EF1845EULL, 
            0x44E32B5CD0A11E3AULL, 0x7AE88424407857E2ULL, 0xBC53BBF54AD0B119ULL, 0x430482398849B153ULL, 
            0xB0E5CFE80186769CULL, 0x600FF7BA69B5EB0AULL, 0x2CA46BD7455BB32DULL, 0x537F7277619B6D76ULL, 
            0x4B92323260435D2DULL, 0x45E1942633054824ULL, 0x3F54A45A65261B32ULL, 0x49D2FC3B9552A9C1ULL, 
            0x4350C7CA87B51554ULL, 0x953798C51582F20FULL, 0x3D89AD8C908B2179ULL, 0x6CD4A415B48A5392ULL
        },
        {
            0xFA9BF9B37B7896FDULL, 0x557AAB38CEF3C4D6ULL, 0x570030E1ABE1DCE8ULL, 0xAA0D82D4808D86A0ULL, 
            0x1F55C730FBB6BB16ULL, 0xC3C5BF2F300AB68DULL, 0x756D4C1F2C00A74AULL, 0x9B0894D15C55E1A0ULL, 
            0x53B90BFA569247C6ULL, 0x089336900530A4CDULL, 0x12FC62E7B3A7306AULL, 0xCD6EF0D24FB32598ULL, 
            0xC5B62549A297DD3BULL, 0xA45FA62F3459C32EULL, 0x0E71D11D01EE2A34ULL, 0x22D57807C36FCF4BULL, 
            0x14712B2883BEDD14ULL, 0xB7F4E0B508817817ULL, 0xE2B612AE7CB2B227ULL, 0x6E9BE63B7143BD3EULL, 
            0x54BEC8240AFC17B3ULL, 0x4C773C039DE766E2ULL, 0x9F84101E3A3B4BABULL, 0x1E628D5C6DA81FF5ULL, 
            0xBD4B51B76061F8C9ULL, 0xC3E2C38C05EEE791ULL, 0x9CB756843BEEC60EULL, 0x720A0B6900A2F7DFULL, 
            0x43AEBF168185654AULL, 0x755884F7ED259D8AULL, 0xD2EE6F1901E69DB7ULL, 0x96DD6FA46E61554AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Boxing::kPhaseHConstants = {
    0x5A2D1A9D02A310B4ULL,
    0x30144A0DA273F29EULL,
    0x3938C2344836FD7BULL,
    0x5A2D1A9D02A310B4ULL,
    0x30144A0DA273F29EULL,
    0x3938C2344836FD7BULL,
    0xF3070D205442A96CULL,
    0xD57229822B349989ULL,
    0x33,
    0x1A,
    0xAA,
    0xF8,
    0xD9,
    0x20,
    0x87,
    0x5C
};

