#include "TwistExpander_Billiards.hpp"
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

TwistExpander_Billiards::TwistExpander_Billiards()
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

void TwistExpander_Billiards::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x892E54765A0C87E0ULL; std::uint64_t aIngress = 0x95A9AD7C5EB99586ULL; std::uint64_t aCarry = 0x9045CD89B9A2F522ULL;

    std::uint64_t aWandererA = 0xAC6AD5DAF72F5417ULL; std::uint64_t aWandererB = 0xECCF0977DD002D13ULL; std::uint64_t aWandererC = 0xE273E37EC1B052D2ULL; std::uint64_t aWandererD = 0x822A1E0F73413CC6ULL;
    std::uint64_t aWandererE = 0xCAEC5B1539016CA6ULL; std::uint64_t aWandererF = 0xAA4DDFC25D02E669ULL; std::uint64_t aWandererG = 0xAFECAAD097692B98ULL; std::uint64_t aWandererH = 0xABEF1E55F03F2506ULL;
    std::uint64_t aWandererI = 0xAF1A8B69C447ECFEULL; std::uint64_t aWandererJ = 0xC4AF333E5EE56A70ULL; std::uint64_t aWandererK = 0xDD9A2C7E39210C2CULL;

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
        aPrevious = 15427619654566630958U;
        aCarry = 11857465686541848295U;
        aWandererA = 16630879067124547830U;
        aWandererB = 9511749565451601904U;
        aWandererC = 13961436932161030155U;
        aWandererD = 17662778067551988873U;
        aWandererE = 16622804867357834963U;
        aWandererF = 10539618769883419119U;
        aWandererG = 13934595770644869845U;
        aWandererH = 12720564618041301726U;
        aWandererI = 13910630996101649572U;
        aWandererJ = 15971395190055919105U;
        aWandererK = 17273884695855428918U;
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
    TwistExpander_Billiards_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Billiards::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0xB13CCFD84C6A1009ULL; std::uint64_t aIngress = 0xF1C0547ED8E5961BULL; std::uint64_t aCarry = 0xDCDC568DE065AB39ULL;

    std::uint64_t aWandererA = 0xE51F2F609DA4697DULL; std::uint64_t aWandererB = 0xBA709BF6A99A908AULL; std::uint64_t aWandererC = 0xBFA9F7A94526F0A2ULL; std::uint64_t aWandererD = 0xF4426A1D48621D2AULL;
    std::uint64_t aWandererE = 0xC83F8B3384722C6DULL; std::uint64_t aWandererF = 0xEE939DD80E1FC0F6ULL; std::uint64_t aWandererG = 0xFCEE64511EB9606CULL; std::uint64_t aWandererH = 0x9BEB3B99C8E07963ULL;
    std::uint64_t aWandererI = 0x9D35BB062C53447DULL; std::uint64_t aWandererJ = 0xE0CDA274FFF3649DULL; std::uint64_t aWandererK = 0xA27F7AD878728B94ULL;

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
        aPrevious = 18307151126034135879U;
        aCarry = 14771619008541072169U;
        aWandererA = 16350292590907901710U;
        aWandererB = 15423025487170452346U;
        aWandererC = 10472882002239494804U;
        aWandererD = 9319912877999230841U;
        aWandererE = 16558102540371412267U;
        aWandererF = 15951949915863319058U;
        aWandererG = 15943925714741620381U;
        aWandererH = 12874446082285125333U;
        aWandererI = 13865057928813190830U;
        aWandererJ = 11733229565054090607U;
        aWandererK = 14019610598377287556U;
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
    TwistExpander_Billiards_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Billiards::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCCAF99410B3DF41CULL;
    std::uint64_t aIngress = 0xE8869128AE7DF8DEULL;
    std::uint64_t aCarry = 0xD9DDFAE35AA2A4D6ULL;

    std::uint64_t aWandererA = 0x9C9AEC28CA2CF805ULL;
    std::uint64_t aWandererB = 0xEBA6726152F4728CULL;
    std::uint64_t aWandererC = 0xB4AB9C137ED88E1CULL;
    std::uint64_t aWandererD = 0x820A70B3FB21E8EEULL;
    std::uint64_t aWandererE = 0xAF95316B0A44FF48ULL;
    std::uint64_t aWandererF = 0x88DF36A1590B650BULL;
    std::uint64_t aWandererG = 0xA9795352EF56D453ULL;
    std::uint64_t aWandererH = 0xAC695E0C3A32EBACULL;
    std::uint64_t aWandererI = 0x8FF21C7B1116FB1FULL;
    std::uint64_t aWandererJ = 0x9C9D55C5633133D2ULL;
    std::uint64_t aWandererK = 0x91958DD82668800CULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::Aria256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
        TwistSquash::SquashB(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneF);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneC, 1);
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
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneD, aExpandLaneB, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneB, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneB, aExpandLaneC, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
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
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneC, 5);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneB, 6);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA, 7);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
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
    TwistExpander_Billiards_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Billiards::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Billiards::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x84E36AF255D9DDBBULL; std::uint64_t aIngress = 0xF28CE440CE76E591ULL; std::uint64_t aCarry = 0xCFE4C93D51B6B81BULL;

    std::uint64_t aWandererA = 0xFE1644062F6631B7ULL; std::uint64_t aWandererB = 0x8B08E32B2CE3CC13ULL; std::uint64_t aWandererC = 0xB494B0C34C0ADCAEULL; std::uint64_t aWandererD = 0xB486199498209002ULL;
    std::uint64_t aWandererE = 0x854332033AEF6C8BULL; std::uint64_t aWandererF = 0xA22126611E2544CDULL; std::uint64_t aWandererG = 0xBED86909B47083B8ULL; std::uint64_t aWandererH = 0xA36875751960FE07ULL;
    std::uint64_t aWandererI = 0xCBC03417BA6BBF64ULL; std::uint64_t aWandererJ = 0xE72CDD4B205790E1ULL; std::uint64_t aWandererK = 0x93702F492EC29153ULL;

    // [seed]
    {
        aPrevious = 10890033506023545253U;
        aCarry = 17584804556542676989U;
        aWandererA = 16184181103232178696U;
        aWandererB = 16180896467969245744U;
        aWandererC = 10396369503317578226U;
        aWandererD = 17970870766945507218U;
        aWandererE = 13195203100123510125U;
        aWandererF = 15357912699227107793U;
        aWandererG = 10463327209670618950U;
        aWandererH = 10807601601710100867U;
        aWandererI = 11743719248017336132U;
        aWandererJ = 16698090116831757611U;
        aWandererK = 10316085652683642131U;
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
    TwistExpander_Billiards_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Billiards_Arx::Twist_C(pWorkSpace,
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
        TwistExpander_Billiards_Arx::GROW_A(pWorkSpace,
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
        TwistExpander_Billiards_Arx::GROW_B(pWorkSpace,
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

void TwistExpander_Billiards::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 8U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 3, 1, 2 with offsets 7652U, 6973U, 3312U, 1768U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7652U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6973U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3312U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1768U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 0, 2, 1 with offsets 4835U, 875U, 2542U, 1648U
        // byte shifts: 16U, 24U, 0U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4835U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 875U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2542U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1648U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 0, 3 with offsets 1930U, 7254U, 6230U, 4537U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1930U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7254U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6230U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4537U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 3, 0 with offsets 1841U, 5952U, 5300U, 2797U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1841U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5952U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5300U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2797U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 3, 1, 0 with offsets 1879U, 175U, 1173U, 1433U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1879U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 175U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1433U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 0, 2, 3, 1 with offsets 1910U, 1314U, 2002U, 455U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1910U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1314U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2002U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 455U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 0, 3, 2, 1 with offsets 135U, 1515U, 1237U, 74U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 135U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1515U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1237U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 74U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 3, 0, 2 with offsets 1993U, 1799U, 890U, 1843U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1799U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 890U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1843U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1247U, 1620U, 798U, 652U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1247U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1620U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 798U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 652U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Billiards::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 1, 0 with offsets 5780U, 105U, 2451U, 3459U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5780U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 105U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2451U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3459U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 2, 0, 1 with offsets 6318U, 7622U, 5101U, 6364U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7622U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5101U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6364U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 3, 2, 3 with offsets 2129U, 451U, 8098U, 6873U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2129U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 451U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8098U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6873U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 3, 2 with offsets 7302U, 4466U, 3868U, 2987U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7302U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4466U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3868U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2987U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 8020U, 1275U, 4634U, 3085U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 8020U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1275U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4634U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3085U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1862U, 1252U, 925U, 147U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1862U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1252U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 147U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1929U, 217U, 287U, 1351U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1929U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 217U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 287U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1351U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 1071U, 305U, 1834U, 1756U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1071U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 305U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1834U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1756U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 338U, 1316U, 1737U, 20U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 338U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1316U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1737U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 20U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 2, 1, 3, 0 [0..<W_KEY]
        // offsets: 637U, 223U, 431U, 1569U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 637U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 223U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1569U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseASalts = {
    {
        {
            0x70B90341DC7F5E9AULL, 0x7C9C59E5A6809960ULL, 0x2F671277D0712811ULL, 0xD912E5CE2A218A21ULL, 
            0xDFC702615F263787ULL, 0x667D5D6286647235ULL, 0xD35E3EA02C49FB7FULL, 0xA5970280957B5CCCULL, 
            0xA6D55F114F383895ULL, 0x4D6A885CEB3BBFB7ULL, 0x7C95CB0FE4E304E6ULL, 0xAD336F038FCB010BULL, 
            0xE17A7FA6472F961AULL, 0xFD236CE6525824F5ULL, 0xA2E878D6781F618FULL, 0x5A6EDBFC6158544AULL, 
            0xB7F1D43D590E95E9ULL, 0xE73DA85A840F73EDULL, 0x9B9EFCFD5A6EE610ULL, 0xCD1E492F3315771DULL, 
            0x86B837D98A97DB38ULL, 0xCF9EA02647F0EACEULL, 0xD79C7384B0F8DB14ULL, 0xDC3EE00AD991DEC4ULL, 
            0x7AD91C659980C9C4ULL, 0x16EDF2C35A4F6D44ULL, 0xEFD174C5DD036035ULL, 0x117056963EC9B7B1ULL, 
            0xA8567541D31FD5EAULL, 0x25C72293E855292FULL, 0x28347AF6D59F3414ULL, 0x884308BC61546137ULL
        },
        {
            0xFA89F9A957C6B4CBULL, 0x3695191F31204ECFULL, 0xEFFDF5F1A18C6B9DULL, 0xC3D95C7C56FACA16ULL, 
            0x174861537AF9C3A3ULL, 0xA466E800EC509967ULL, 0x9E3BFFC41B785216ULL, 0x154396187ED40345ULL, 
            0x6A3ADCBFA2F064ABULL, 0xAD665F249B407228ULL, 0x314B4AB00A4064BFULL, 0xE3C8AA49F13496E2ULL, 
            0x6C9C4DAB803AECF3ULL, 0xC3545CF803335F78ULL, 0xF041C91AE65677E7ULL, 0x9BA118683138292DULL, 
            0x9AD2605CED826B93ULL, 0x3112BC56C5C48F1CULL, 0x11E794C00ED24A12ULL, 0xA25FC5BD023A5963ULL, 
            0x1FC04730DC23E919ULL, 0xEA4FE0770D8176C3ULL, 0xF44082B0688A4F79ULL, 0x685A0145CFE8FDAEULL, 
            0x38CF1F3B120D77EAULL, 0x277211107988759DULL, 0x2BDC0DBE1373F65BULL, 0xCC0A4E3AB20E02F5ULL, 
            0xBB40E2F48BB548D6ULL, 0xAB2F353C12DD3246ULL, 0xA001E7381B9CA1BFULL, 0xA34296280AC27DCDULL
        },
        {
            0x948EE4D810DFF42AULL, 0x0788C546B132B465ULL, 0xADC6532AB6ABDFEDULL, 0xC2E01FE863523532ULL, 
            0x5A47B7D658F7E057ULL, 0xF61C6BA4FA0804EEULL, 0x6DB46DD5F9F614A3ULL, 0xD6A51EDC099F9E01ULL, 
            0xA91364B1A59A7278ULL, 0x113495EF42AB99C4ULL, 0x7825BACFE03B2921ULL, 0x997802B7D59D9487ULL, 
            0x07085FE14F00EE0CULL, 0xE6D5BAD438C98C52ULL, 0x10EC7FBD75A29D04ULL, 0x09EA95A17B567CA8ULL, 
            0x10B66B5A767B88FDULL, 0x03E18749FBEDAB5AULL, 0xDD9A3D878FEC3EE0ULL, 0xC969732B7FCEB762ULL, 
            0xB74FC048036C0751ULL, 0x734FD5E511DC93D4ULL, 0xE70C30F15FA5A0E7ULL, 0x7E61B7F1C65A836CULL, 
            0x5DBC6B07589AB58DULL, 0xDFFF270599F8CC0DULL, 0x2006F2DFE6ED617AULL, 0xFF25A1868D6DC414ULL, 
            0x6447DCB24AEA363CULL, 0xDE16E5404852CA63ULL, 0x1404E0B3D22F1B48ULL, 0x3DE080B1CF7ECFECULL
        },
        {
            0x79E9A06616C49BE7ULL, 0x4D68B54BD608477AULL, 0x6E410E93462511FAULL, 0xA501D8D87C61770EULL, 
            0x42616D8217079577ULL, 0x733F40D749345021ULL, 0x1508926CA7084B35ULL, 0x335EE4D342C2E630ULL, 
            0x23220378E851793DULL, 0x06D9DE39644322E3ULL, 0xD9686A2A591D23C7ULL, 0x2E92EBA102FC52A4ULL, 
            0x346B1DCBF2A8BBF7ULL, 0x23A8A7BDE30E1A9DULL, 0x1B6432A636C5A1B4ULL, 0x80A1353057C6791FULL, 
            0x39BCCFCA34D2453DULL, 0x009C4DEAA0910064ULL, 0xD15FD3FF98C72B3AULL, 0x74931B181A950252ULL, 
            0x42F5822489348DC8ULL, 0x763229912890A157ULL, 0x7DA87771E429831FULL, 0x06F2C33402900878ULL, 
            0xF99D33FBE507A8BDULL, 0x1E62313D538363F3ULL, 0x59B407ED028D8F69ULL, 0x6481880239D369D6ULL, 
            0x9A69E5B2C76973C1ULL, 0x18F1C53FBA6C88B5ULL, 0xB3263C86E1E23A06ULL, 0x7644E17EA1AB81AEULL
        },
        {
            0xAEA723D7F35CF5F2ULL, 0x6CA5FA38205AF9A5ULL, 0x3789FA504D20C391ULL, 0xD2E0474AED9761FBULL, 
            0xB2DA59F05660A2CCULL, 0xE47BAD56AAA2C028ULL, 0x3696665E708BE935ULL, 0x3226EBA562AE89FBULL, 
            0x210603524550762CULL, 0x4657442CF9D04257ULL, 0x6ECC99BC23DBC3D2ULL, 0x65A8EAB37320D4CFULL, 
            0x62FE11270A70AF40ULL, 0xE5F5DC46D6811B1CULL, 0x8A81DC5723F45335ULL, 0xEBFCF0651800AFEEULL, 
            0x9683A7468568EBB7ULL, 0xCC3D322573C7C7B6ULL, 0x94D6CF498A9C2179ULL, 0xA1686CCE2804D5A1ULL, 
            0xF942FCFF9269928BULL, 0xEE055B650650CA3FULL, 0xA61A8799C4E7F1EFULL, 0x9F356AECEE11EF14ULL, 
            0x66695684C8AD4729ULL, 0x24F128779BAD35A6ULL, 0x711DDD277B030E83ULL, 0x6E063E06C1E358F0ULL, 
            0xDC2215FD2950EB93ULL, 0xA66ABA99E748ACD5ULL, 0x09EE809E8E96B134ULL, 0xBD9AD3172D3C7556ULL
        },
        {
            0x5C1E17D2401EDEC1ULL, 0x069142EFEA69702AULL, 0x9F5BA1D321137736ULL, 0xA8BB397A286210BDULL, 
            0x606B14524A78E8ACULL, 0x40D98082AFF082B7ULL, 0xDBD1E78463458441ULL, 0x14D03EEFE872D8E9ULL, 
            0xD0C34FC812D3925EULL, 0x95AF5F54A582C169ULL, 0xF80A94CD1D29D458ULL, 0xB4C85859A578E36CULL, 
            0x8589EEC2CFE006B6ULL, 0x2B5CD9492421C63AULL, 0x9F982F81BF2ECC97ULL, 0x9A094655431A4EBCULL, 
            0x22ED88701FFF3C6DULL, 0x1F5D999180D95099ULL, 0x7DAEFDCB8F2FC253ULL, 0xE7724F4341CC2AB1ULL, 
            0x07B2B4E90A02538CULL, 0x7668F0558E36031CULL, 0x7A5F307677A26AD9ULL, 0x76E25896BEB4309BULL, 
            0x4CC36819443116BEULL, 0x9EDCE2FC05D8BF45ULL, 0xE42261AE20DF71F5ULL, 0xA21AA4EAB107D618ULL, 
            0x6A00D3CAA6E88086ULL, 0x6CD0560B7420B3A7ULL, 0x45C1A7FBCE9D7321ULL, 0xF38417D080C39417ULL
        }
    },
    {
        {
            0xBC976F6C4396F845ULL, 0x14C759461278D606ULL, 0xDB04E0030AF6F671ULL, 0xFC29E940BDDAC331ULL, 
            0x3BC02E7B5C39CD85ULL, 0x99950F4A0F31780DULL, 0xEED3D4AB822C92FAULL, 0xEFAAD4EBCEB39FDFULL, 
            0xCA42648D8E8DA263ULL, 0x461B168042C48CAAULL, 0xEBBB03B580960723ULL, 0x7B4474B36F0C7552ULL, 
            0xA311338CF3E33B0EULL, 0xF95C2FD804715C0AULL, 0x032B8263F16668A3ULL, 0x24231B518EBFC212ULL, 
            0x12A58B850D908C37ULL, 0xCE5445F0187EC8C2ULL, 0x005DA86D25726599ULL, 0x5DE6F17B979E1DCEULL, 
            0x7EFD36AF17892E0EULL, 0xF40F92FF49D7A9C0ULL, 0x1B5F5FE04D8DA3BFULL, 0x615B0FC85EEA7F02ULL, 
            0x11D68A008545D2A8ULL, 0x1525C802568CD095ULL, 0x3055334FA55C9537ULL, 0x91B3BD7DC0A0172FULL, 
            0x1A011E42C567C910ULL, 0xC7A652B93A2FB142ULL, 0x62C5BDDCD1CA1BEDULL, 0x347096339F0D10F9ULL
        },
        {
            0xE256D28DB6A51052ULL, 0x1075618BEA7D0D18ULL, 0xB0FBB90ED318DA7AULL, 0xA76118CFE265270AULL, 
            0x71E15D5EAC48D6B5ULL, 0x8FA7C9B06E6E0DF4ULL, 0xF8D5CA40789B3C7EULL, 0xCD07D736D118F09EULL, 
            0x8C6987F9970AAF36ULL, 0xFFFA4C6C9CE16B12ULL, 0x80D0EED52583C12BULL, 0x234B2AE461D5D478ULL, 
            0xC17F9AD8183064A9ULL, 0xED1D59B40E502E9CULL, 0x93F4C3E61AC5FCD8ULL, 0x56B26D212FDB3890ULL, 
            0x8658989A8FDDE153ULL, 0xA2D93C54ED2CAF40ULL, 0x2C9B0AA35402C269ULL, 0xD20655E5542E26D7ULL, 
            0x02332CED0D48CD81ULL, 0x6DC033124093C84DULL, 0xBABF2DA433150A78ULL, 0x59A2479DE58DAA4FULL, 
            0xD52A9CA5CC3AC3ECULL, 0x726C0D636189CF87ULL, 0xF08DF786EE73B37AULL, 0x094F799A1C56534FULL, 
            0x6F5A54DD4C988B3FULL, 0x4BC2B0C7F7E1EC8DULL, 0x7B5B3F264D720155ULL, 0xDD1730C96FACFC13ULL
        },
        {
            0x9BE211003C5E08D2ULL, 0xB5A25EDA6CC2F027ULL, 0x6C5496E922A4011CULL, 0xB0079BAC541C43CFULL, 
            0xB99D3103127D6E48ULL, 0xD951972D340EF9CBULL, 0xB07433337196DD79ULL, 0x3E686EC5F117F2A2ULL, 
            0xE1CF380A375877D6ULL, 0x0EEFAECC4F2F726BULL, 0xB28EA34D7D6879E7ULL, 0xE186E000695F0F18ULL, 
            0x7F089BDB43CC9209ULL, 0x645E7DD0F07FA031ULL, 0x1294F5493762617DULL, 0x4302E93C3BF8D45CULL, 
            0xD83C3E261E77ADB5ULL, 0x13F515E8A2803365ULL, 0x8DC2462E902C5567ULL, 0xD386800224D42B60ULL, 
            0x7A797AC5F3BFA1F4ULL, 0xE571827E3E639D91ULL, 0x2D58B5287D6D9B8EULL, 0x35FA371BDC2F781BULL, 
            0xFF53BB17A47F67FCULL, 0xA35ECAAA2F08717CULL, 0xE14F0B627CA2F1D0ULL, 0xBD52A328DBBB8723ULL, 
            0x2C583F6D175324E5ULL, 0x78ED02F13E4E0140ULL, 0x84651D82082A5F21ULL, 0xF1DAE3BCE47C269BULL
        },
        {
            0xCC9F8875E49B95A7ULL, 0x5D10A4CB436BE935ULL, 0x3B7C04BDF96E82F1ULL, 0xBEE3A17E1A04FE0CULL, 
            0x0B22EB76CA9CDF92ULL, 0xAE899F087E8766DFULL, 0xC2DEF1E45A3224A9ULL, 0x8CF4309D07AFF894ULL, 
            0x49C1CA933D7AE173ULL, 0x5C6727126054A05EULL, 0xB124A193E0F7617AULL, 0xC576B9EC4A97A360ULL, 
            0x00D058333D4423F8ULL, 0xD3B12A7EFEDB3E95ULL, 0xE1C1C626C2C88A93ULL, 0xA9A0C43BD4F799C4ULL, 
            0x3B5BEA0357ED3F77ULL, 0xE0C02078B9116CEAULL, 0x6F24D7E447F04FC5ULL, 0x96504ED12265BB15ULL, 
            0xD001523150166E91ULL, 0x4BAAA6B39F609F15ULL, 0x8000750EFABD8FDCULL, 0xFD8173F36745540FULL, 
            0x90D2AB27AFA15569ULL, 0x1CA9434D2D07C1BFULL, 0xF6746012715841E4ULL, 0xFBC0FBEFA1C6178BULL, 
            0xFD32203D14705E90ULL, 0x128CB057F263F45BULL, 0x8B880780C1CDE53EULL, 0x119A1560D06A1CFDULL
        },
        {
            0x4FB6650DF15A26A1ULL, 0xB13958A4DF9B764EULL, 0xC0F7C781F4DFE581ULL, 0xA669BD5DFDEB55B8ULL, 
            0x11FD7E2317B5B4FDULL, 0xFE22D06319CD57A8ULL, 0x26F15930B93E7FBBULL, 0x6BFDD57D760B4716ULL, 
            0xDCDB3ECD816E8A83ULL, 0x4CD6DC08BF75F382ULL, 0x12C361FC8324BF2FULL, 0x1A5438D21C789C0EULL, 
            0x60D83EF1F66FC9B9ULL, 0xCD248C280F68A116ULL, 0x6B3DD65359BAFEFEULL, 0x88B37428006CF70AULL, 
            0xEE3090A06B0DCA59ULL, 0xE927C7FD20E51F55ULL, 0x5536B6DEA6072377ULL, 0xC5B962B22B4767D9ULL, 
            0xFE34C69B1EA8DB87ULL, 0x5268AAAF21BCF16EULL, 0x75AF656D696AE3BCULL, 0x60D42D1A32EAE0C8ULL, 
            0x24C95602F529AA38ULL, 0x7700764EF39EF12CULL, 0x398C2BB194C4B3C3ULL, 0xDE6A2FB406ECF958ULL, 
            0x61F934A4E83239B8ULL, 0xB3C8CE0BDA7EB941ULL, 0xF9675850AEAFCF70ULL, 0xFED6FC20F58E1F90ULL
        },
        {
            0x1D6CE7C6B945219FULL, 0xF36731CD846E8000ULL, 0xE40E34BB74B05348ULL, 0x443A9EB96AD545BCULL, 
            0x6544CBDDBA5E1527ULL, 0xB7E08FBAB4663585ULL, 0x73424D85BD6B820EULL, 0x2D7F938AE04D4BD8ULL, 
            0xBA22EC94D176A3B4ULL, 0x95B13F608752F301ULL, 0x4E9E8D334EBBB3A3ULL, 0xB2A8BC756B0EEE2BULL, 
            0x1C53CB88335D91F3ULL, 0x34171CFE52CED39CULL, 0xF61F248E0BD0DFF0ULL, 0xBD7A3B862359566EULL, 
            0x090DEA414CC9F14DULL, 0x64AB182A8699071CULL, 0xC9B0B04002F88E9DULL, 0x1A084435A1CAEFC4ULL, 
            0xD649818D5E91286DULL, 0x08C697805A4FAC7CULL, 0x6F235F8C8AE4A543ULL, 0xF6EE3EAC88EF767AULL, 
            0xC12740500C880B57ULL, 0x25F6C04E6C181F9BULL, 0xB29808F4B1D7738BULL, 0xA3AC2F0E74FA875EULL, 
            0xE6FB1197099C08AEULL, 0xB048538CDBB67B2BULL, 0x458AD9BD25CC5ED9ULL, 0x96989DBFD7BD39D3ULL
        }
    },
    {
        {
            0x759AFE4CF420AD6EULL, 0x59608A2484911B1CULL, 0x59D8365630494CB0ULL, 0x0E403599D63CDE2BULL, 
            0xF3F838DFDA6390C7ULL, 0x05338D4FE9AC08C3ULL, 0x8FF388E826BE3B90ULL, 0x96F5D4C010D6E038ULL, 
            0x03692400C03525ABULL, 0x321015DBB8D970C7ULL, 0x6F4173AAC1B8A199ULL, 0x5738EA4727EE3581ULL, 
            0x2A732E7025DD3FF2ULL, 0x659351B58A4BE908ULL, 0x4F592372BB856ECEULL, 0xBE1D1CCF04946577ULL, 
            0x04F082078889257DULL, 0x013841E4FED984F2ULL, 0x33F89102B06670BDULL, 0xE61490E313BC0844ULL, 
            0x8C89EA7154A349EAULL, 0x2DBC352C6F008B5EULL, 0x8E9D82C3E51EF223ULL, 0xAED2BFFD787D6820ULL, 
            0x6A05E06B850BDCE6ULL, 0x91ADE7FE2800B672ULL, 0xB011BF8B8AC6FD96ULL, 0xE5AF6B0DCCFC4913ULL, 
            0x88EBCD2CBAB04DC8ULL, 0x03A8D704411EC5FFULL, 0x3802DC493C175AA6ULL, 0x1CED8DDBA71A44D5ULL
        },
        {
            0xFCD0765520E01590ULL, 0x86011AA6A6F0E780ULL, 0xA21E8EC637FFC457ULL, 0x6B340B0D7035C3CDULL, 
            0x0813F24B67D72860ULL, 0xDB9714F330C9B143ULL, 0xF5A56AFF841B100EULL, 0xA5C61445C4677187ULL, 
            0xEEFE6A73B60CE705ULL, 0x560336A113BC2E79ULL, 0x1C917A7560DD3EFAULL, 0x47F617D53708B0E1ULL, 
            0x2B86EAE303B420CBULL, 0xB0325541E5CBB84BULL, 0x64470C4037357058ULL, 0xAA6705DDEDC5C8F2ULL, 
            0x1237D3107A0C5DC5ULL, 0x84C09882CD09E6D3ULL, 0x72784C16C38D430FULL, 0x423A14DBABF8E930ULL, 
            0x85D2E8CCF700BC00ULL, 0x65C68C7B691B579AULL, 0x4A86516819F832B8ULL, 0xDA91A5C2E283F0D3ULL, 
            0xEA720E6D9582EDADULL, 0x985D0BDD16B113FFULL, 0x2164185B9DFBCEEBULL, 0x05F3EDC6342F7CCBULL, 
            0x60D685F9685B96A2ULL, 0x46122875E6CE6A8FULL, 0xF7915BC013B8141AULL, 0xF79815FD60670A8EULL
        },
        {
            0xA05D2E4317433A1EULL, 0x607ACD4E81DCCD52ULL, 0x0F0512D10180161BULL, 0x3611074CAD8810E2ULL, 
            0x9BEA6BB07C06A5FEULL, 0x622E95E267DF34D3ULL, 0x60BDFCD32C5DF9C3ULL, 0xDDB312EE702C44DDULL, 
            0x04237164295AE4ABULL, 0x2979425A5A61A4C5ULL, 0x027D6DE0FBBA5EC3ULL, 0x00684F183A4A386CULL, 
            0xC266C756E003033CULL, 0x54ECBD9C23FE06BBULL, 0x427F26209FA427D6ULL, 0xE861889E17F4EC15ULL, 
            0xF8A776F65B57CC9BULL, 0x337EE1A49AA29B60ULL, 0x4606172E8606D64EULL, 0xD1F9CD2764B2A25FULL, 
            0x8C4DF8EE3726FD82ULL, 0xB3BD85B71311F0DAULL, 0x2AF509494B6E0EA3ULL, 0xE3939E3A45D856CEULL, 
            0x547A7EC40B79099EULL, 0x625128929E495316ULL, 0xCB85A26C13871841ULL, 0x70F7FFE5910133E2ULL, 
            0x57585E392FBEF549ULL, 0x3F6D7EE80BFBC15CULL, 0xD18A6F76BD836F66ULL, 0x43382F965B2C1BB2ULL
        },
        {
            0xB3265C0150466AC7ULL, 0xD7030810F17C9B46ULL, 0x51651B12A9324DF0ULL, 0xB61563E8ADC1A6D7ULL, 
            0xA8688AE146530682ULL, 0x7B310AD76415D01EULL, 0x0C1320DEF4DE2E91ULL, 0x3D75462B2213B10CULL, 
            0x15BACD52941F03C3ULL, 0x0D2478F8F4D1181AULL, 0x1FEBBE11FC7C8507ULL, 0x0B7B4C778FEA9906ULL, 
            0x195C669F5E1E9B9EULL, 0x55430318DF057DFCULL, 0x6434C0B6F449BF87ULL, 0x8FA12DA4C78EA7B8ULL, 
            0x8F34288DC9461174ULL, 0x158D503B96EA010BULL, 0x4414913077D3E391ULL, 0xCC0F7DC62E4C3792ULL, 
            0x577C0A4473CB5F87ULL, 0x94AB21F950032B2BULL, 0xCB41F5E4C8AE7781ULL, 0xAB964D8FD638CA5AULL, 
            0xC41A4A04E0F1FF4AULL, 0x99E09BE9771F17B9ULL, 0x55F1DAE1B5AD1AF7ULL, 0x5971479D7D6CCE96ULL, 
            0x8EA74297362B4E42ULL, 0x4B1AB7C47D6F3C57ULL, 0xCF14CFD518C25CC3ULL, 0x2409F6B4F731951AULL
        },
        {
            0x253B9AF2073A26F5ULL, 0x026F02668B6CD69BULL, 0x1DBD1DE0E96C44A7ULL, 0xC8EC5DDB1C90C89DULL, 
            0x48782ABCEC79FA45ULL, 0x3C1426D47A0C09F6ULL, 0xB2BD68965BBE3BE4ULL, 0x50DA5D6EAFB5ECD6ULL, 
            0xA5A744E20125D4F4ULL, 0x44C3271C171EE960ULL, 0xA57EAC3935063AE0ULL, 0xA91DC88AFC84DDFFULL, 
            0x603AD91A611AB99FULL, 0x58CF6F1CA753D925ULL, 0xC499A226D5562112ULL, 0x08C682C9CCBDBBF6ULL, 
            0x9F64E207B47304CFULL, 0x07BCDBF576304CA9ULL, 0xC37D9F4A179AEF40ULL, 0x986C7AC62E8CBC77ULL, 
            0x9BFDEC2467C2F255ULL, 0xD74147D440567B58ULL, 0x24277181A773FE2DULL, 0x95F6E8F0B02E385FULL, 
            0x0C9F2A3B5CC17FFFULL, 0xC6BCE94655BC8E8BULL, 0x4B1EB78D19D9EFF1ULL, 0x9601AECFB4CE38B5ULL, 
            0x92312A4B962C8E4CULL, 0xE1568E12D6E25145ULL, 0x3159321866934F61ULL, 0x38516F9A79B00235ULL
        },
        {
            0x9BFA09FE2C845F09ULL, 0x0F7DB34782ABB6DEULL, 0x78E201E3E58C2708ULL, 0x28A8EDD84E7E6841ULL, 
            0x7E69F4120243890EULL, 0xB92B6B76EC90A730ULL, 0x717EEBBC97E64CC9ULL, 0x91E19DED10BE4DAEULL, 
            0x78EE9DBDEF5BD347ULL, 0x0FD6BED3F75CB633ULL, 0xA5DB844F421A73EFULL, 0xC7C5EF6343041A56ULL, 
            0x2A8B517905A77185ULL, 0x816A5B8A38134521ULL, 0x82B2C2E80A937D56ULL, 0x6574CC40911E2D2EULL, 
            0xEE35BD9FDA6DE001ULL, 0x27F3E65F27A1A4D2ULL, 0xB2BCCDB68A888965ULL, 0x6E59317AC103665DULL, 
            0x35530C74DCEB9404ULL, 0x5C322785D194EF64ULL, 0xBC400B25352B466BULL, 0xEED2E338511C37AAULL, 
            0x9A005D3471981926ULL, 0x29BDDB285CCA5FBAULL, 0x870EC2A22CC45945ULL, 0x5D5644FCAF56B00EULL, 
            0xE98C3A95A17E4223ULL, 0xC2A895D77F90C1D0ULL, 0xA37C0773D0DA7185ULL, 0xC734A2A899874872ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseAConstants = {
    0x56FFC9F78DD1008FULL,
    0x4C98721C524D4DBAULL,
    0x4E3675B5D2183061ULL,
    0x56FFC9F78DD1008FULL,
    0x4C98721C524D4DBAULL,
    0x4E3675B5D2183061ULL,
    0x21E8BFC51B105754ULL,
    0xBDCA993B6F236B90ULL,
    0x34,
    0x5F,
    0xE4,
    0x27,
    0x29,
    0x46,
    0xBE,
    0x60
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseBSalts = {
    {
        {
            0x14215D984CEA3D19ULL, 0x913525D1CD853B15ULL, 0x4E361B44F26833C7ULL, 0x2C4BDB50540EA0C3ULL, 
            0xDC6BAE302BD64BF8ULL, 0x9893521C38B92FE3ULL, 0xB9DE864B1D400292ULL, 0x4D4BBB2D9452E6C1ULL, 
            0xC285DC6D8C405979ULL, 0xEEE7911C175A94AEULL, 0xE81A737D3CA21787ULL, 0xA503623D50234EF0ULL, 
            0x010BBAA97C3B6D4AULL, 0x14E70783C1A8344BULL, 0x0847CFBDA273C6D0ULL, 0xF0BFB6D0A4AA05E6ULL, 
            0x645FB1D43C5CFCC5ULL, 0x9AE86AF24864471AULL, 0xE203B712DA2BC10CULL, 0xFB450651C33AA608ULL, 
            0x84CD1B37BA897933ULL, 0x4C8A2BF1E67F6EEEULL, 0x2AFAE709642E1255ULL, 0x1DF7910AB4925A3AULL, 
            0x6961DF15AFC45D18ULL, 0xB501D112747AB6FAULL, 0xAC84F109CF16E222ULL, 0x117DB59A9C0CA25AULL, 
            0x4440B2F9DDFCF1EBULL, 0xAF8F9A3F08CB4A74ULL, 0x9C7950AF9EE20820ULL, 0x24C3FF80EFD053CAULL
        },
        {
            0x29A9743DF647FE16ULL, 0x8A4226BDB65D9510ULL, 0xD7CAB999228468F6ULL, 0x5409A3C87D6CA2FFULL, 
            0xA96573EAC84C10FEULL, 0x2A93B4C598460D6BULL, 0xB008ECF766DEAA30ULL, 0xDAAC3C98C4AD0D06ULL, 
            0xF7FD8BC92D26928CULL, 0x339F8682EEE6C7BEULL, 0x73DA89D390D6B0D5ULL, 0x723B326BC9FFCD2CULL, 
            0xFCF66EAEAA1B7323ULL, 0x5C9AFB6CB64217B9ULL, 0x4672FCDC2704AEF7ULL, 0xCD7356F675F83518ULL, 
            0x36C8F65C64AA8424ULL, 0xC69537000D139806ULL, 0xE3090A9920F54BE3ULL, 0x562BD9A2F80DFD04ULL, 
            0x0221225D22131716ULL, 0x1B2E3AF00F57E144ULL, 0xCE987705C0E21659ULL, 0x633AFAE5D1A4DB8DULL, 
            0x3DEEA7E3A79B23CEULL, 0xAE05D7B47B074A4EULL, 0xCE6CD74105856EA3ULL, 0xE4E7EEB8A36E5FA5ULL, 
            0xA94A91427597FCE2ULL, 0xDF4703B83C8BC491ULL, 0x29BFB4313BF71CC6ULL, 0x50A4547B42D7E9FDULL
        },
        {
            0x1921464F1D5CC570ULL, 0x4021392A3E8D83B4ULL, 0x86584F8F3AEB908AULL, 0x35F67EB1EB3C3589ULL, 
            0x157A4DB26DA02464ULL, 0x18135D223222A45CULL, 0xE1A2B0B9636A8D2EULL, 0x93D175EF53332118ULL, 
            0xB9E8AEFA4893AB86ULL, 0xA8CD698A1D431128ULL, 0x6B9D96E1FA227729ULL, 0x1872F2BD6F5A8CC0ULL, 
            0x1B8EB8D326BAC265ULL, 0xC94255A33014ED9FULL, 0xAE412E06733566D6ULL, 0x76339D1685487217ULL, 
            0xD956BD1210018982ULL, 0xD5B6D1E1F7D56E55ULL, 0x6B339C4FA19407F9ULL, 0x906D011E0D63855BULL, 
            0x2E65FB5796BD1C11ULL, 0x1BEAFFBAD6458B86ULL, 0x832985BC175881CBULL, 0xE17D805522368229ULL, 
            0x04CA883685DB960CULL, 0x469C2E069DA809A6ULL, 0x6F493F263449F8DCULL, 0xEA9BBABA75CF75D3ULL, 
            0xD3C9B2A60076F164ULL, 0xEACFCBFC96E71674ULL, 0xE33C5F37264754D0ULL, 0x6FABBFC9820BB032ULL
        },
        {
            0x4410452CC123E9FDULL, 0xC8357024AC4DF1A7ULL, 0xA8BDD688F1B32510ULL, 0x61D543D83D813A26ULL, 
            0xEEA6531C98015A39ULL, 0x384A5A8BF7F53CCDULL, 0x0C41A6253E8C1976ULL, 0x102326FA63B349CAULL, 
            0xD9CB7F25ED648A41ULL, 0x66FF6591155F36C2ULL, 0x2B171D789B1D6404ULL, 0x90AB1B77BB8BA1FBULL, 
            0x5202F2A861D5145EULL, 0x90D280DBA593EFA6ULL, 0x896A13D5A238D635ULL, 0xC5DD4695D7E7FB78ULL, 
            0xAFC5EC500E106CFEULL, 0xD17A2973F08BF824ULL, 0x2620C7318D4B9A01ULL, 0x2FD8834D2A85C6ADULL, 
            0xFF00CC2CE06BC3B8ULL, 0x646F776FDA1C818DULL, 0x322C01EC4BDAC23BULL, 0x65F9773478EC159BULL, 
            0x1D2567EC50C94148ULL, 0x188C4B69D8093903ULL, 0x379B05874ADBFF39ULL, 0xD624E7D3C469649DULL, 
            0xF480101A9D78A77DULL, 0x139DA80A96D976F2ULL, 0xD0E54A31F7F9EDC3ULL, 0xE46A7B74890CA568ULL
        },
        {
            0xEABACA01E121253CULL, 0xC71C2BFFA5C56AC5ULL, 0x972D5D79A5011D4AULL, 0x514438FA92CD6F3FULL, 
            0x7D950266AD242E75ULL, 0x99232717DD0BF32BULL, 0xC172EA616D668D4BULL, 0x312F3B96D41B5BCFULL, 
            0xFA1AD4AA1FBE9622ULL, 0x912C5E2C7D5D04A7ULL, 0xC17A0450743D9A05ULL, 0x93FEEAFCF17E055DULL, 
            0x0B590B889303D836ULL, 0x019E451F84592860ULL, 0xD1A249F442168935ULL, 0x887EF80221493D92ULL, 
            0xF2950A473B009FB1ULL, 0xB261782A457B2AE4ULL, 0xE507BD8EEC803CC1ULL, 0xD120E669F391BAB5ULL, 
            0x31C7F2F7B2EE2C88ULL, 0xEEDB321440BC09CBULL, 0x27C2BCAB654C772DULL, 0xE1C7F22202E6D753ULL, 
            0x4C6D4A0BF2BFA1F5ULL, 0xF7A9F075D1B47995ULL, 0x26AEFE6837A7F4C7ULL, 0x90C1CDE5B8C718D1ULL, 
            0xE462C8EBE5143C45ULL, 0x0ED435679DCAA288ULL, 0x13AC7C99D3BFEEFDULL, 0x22E3F956352DED4CULL
        },
        {
            0x8FD08C9355A7435DULL, 0xAB20DB8DD0E7E01EULL, 0x88578E8C53CDE483ULL, 0x16EB129A8FB744E5ULL, 
            0xDBE60BDC86FA3917ULL, 0xDE9191AFC9B0BDBFULL, 0xD2A46F40AC31D9F0ULL, 0x9BA3F47E86633BB7ULL, 
            0x1C7AE2E155740D63ULL, 0xE268617078C0FAA8ULL, 0x6D4989BB5D0EDCD7ULL, 0x842FC491BF0466BDULL, 
            0xAB4A517CD838B3CDULL, 0x92FB16C7C60639B7ULL, 0xD855F846673E2F94ULL, 0x7BCBBB6E07BFBAF9ULL, 
            0x8D15C2A17C6C56F3ULL, 0x268845B0A5D82A77ULL, 0x1FE563560E3EF281ULL, 0xB2F6179B9088840BULL, 
            0xB7AAC56B7CC5D393ULL, 0xD129E675C116AEE9ULL, 0xAB9A005985555CF3ULL, 0x8350CD6AF53195B5ULL, 
            0xDD736ACB556B576DULL, 0xECA1AAF37A16F2B1ULL, 0x74FDF04A7D8A48D6ULL, 0x53382D5142D6AB54ULL, 
            0x49FA8F446DF46A6BULL, 0xFAC9D3B8804F0C27ULL, 0xFA396B3D96C1A957ULL, 0x058AC79342901AA7ULL
        }
    },
    {
        {
            0x99D546333021DEEFULL, 0xC35F77F1A02B2414ULL, 0xD062B2EE80A31CD8ULL, 0x9B6FFA69B0A9384DULL, 
            0xCACE58D848D5E7E7ULL, 0xA8EABDB2170B6FACULL, 0x9BD8C57CAF5BE325ULL, 0xA965CDD020E6C9C3ULL, 
            0x798AB5BFD383D63DULL, 0x67A76E40DC0F7926ULL, 0xC4BECB0332E62D00ULL, 0x11ED6F8133956B33ULL, 
            0x2290151B3E4E9594ULL, 0xD4FE76E13CF92354ULL, 0x3EA162F8E5935B69ULL, 0x600647AE3D3A3482ULL, 
            0x1E111D5055DA577CULL, 0xC9D7825A134C16EDULL, 0xF505667FA18A7E7EULL, 0xE99EA4977B1D9CD2ULL, 
            0xE0E61A02B529598FULL, 0x448976911E130786ULL, 0x41516CDA627F1147ULL, 0xFCAAA28132D054A4ULL, 
            0x10341D983FB95F02ULL, 0x3E4C6F80DF412B46ULL, 0x9ACF5FA2BA27BDE0ULL, 0x2A5A3BF76C92C383ULL, 
            0x268D75C29B09597DULL, 0xBC6DBCAA2811C249ULL, 0xC6DAAD166136AD67ULL, 0x61FA117049B1082EULL
        },
        {
            0x87BB45D60A62A149ULL, 0x4FB1E173E4A0A9AFULL, 0x3BAD3EAFEDE602CCULL, 0xC4F2367EEF995657ULL, 
            0x5E320CFF5368C1D8ULL, 0x78ABC1D86A499DB0ULL, 0x1D559AD66588AB93ULL, 0x27A5592FA4DA5385ULL, 
            0x9212DC2E2A4B8B4AULL, 0xB9D410F2AABDA1B9ULL, 0x8FE3292A68CB7431ULL, 0xA420FEBB10139E60ULL, 
            0x0129918690205D21ULL, 0x59E1E507F9D20A1CULL, 0xD12F3D3925412A84ULL, 0x7D076D9406C4D079ULL, 
            0x1AB4D7CA94BC3811ULL, 0xB30EB7C2D72393A4ULL, 0x25144F6586636206ULL, 0xB35158030F0B3DF8ULL, 
            0x3EE43A107246122CULL, 0x8048B1C5DFEDE725ULL, 0x918724C7B334D131ULL, 0xD57E6C6EEAA2D922ULL, 
            0xBEB77981C58D2132ULL, 0x59155F29D0BC8B20ULL, 0xECFAF85323BC305CULL, 0x310BAE0A64B485EAULL, 
            0xDA24103914F4B62EULL, 0xAB894403124358E5ULL, 0x045932684DDACCBBULL, 0x3D6D23C5A3CCAFB1ULL
        },
        {
            0x42C008ADBD20BD4EULL, 0xF6DFBE849B60DA40ULL, 0x8E5534771BE84CF2ULL, 0xB24736F220157CFEULL, 
            0x0CD5A0089640575CULL, 0x6942CB188E256630ULL, 0x003E1AC07D61C202ULL, 0x28E9E61F8A32F7E9ULL, 
            0xB373643868975E13ULL, 0xF7FEB5841E1BD0F4ULL, 0x1C50511DC0DFDDA2ULL, 0x73F07A07265D23F8ULL, 
            0x0785980956B193EEULL, 0x9B769571471691E4ULL, 0xEBE56EA68A601029ULL, 0x61114F577F37D920ULL, 
            0xC768A0679AA0BC34ULL, 0xC13D6493DBDF384CULL, 0xE945E460F8104C4DULL, 0x01FF926980E4F460ULL, 
            0x7114089A5917EEFCULL, 0x1F62A04D329A4C4DULL, 0x960004FBD6F51188ULL, 0xDF1E2B75BDC78A0CULL, 
            0xBAE1AFDF6A90CAF6ULL, 0xE99239E60E88644CULL, 0x7C7DC392EFD0406AULL, 0x40F54AD02425CCBAULL, 
            0xA149E4E6B1499877ULL, 0x1CBF2A5E0FCA4002ULL, 0x8B3740ADFF0C616BULL, 0x535108FA76B6353EULL
        },
        {
            0xE0DA5667DFB14D87ULL, 0xC0FF538DB21D8BF1ULL, 0xA7D52A83D56BE656ULL, 0x22312190E898D52EULL, 
            0xEF8ED871566F18F3ULL, 0x3217F27523336904ULL, 0x3B941C90506E9F2EULL, 0x9959D71F585EE130ULL, 
            0x6DD5F035A4B1F488ULL, 0xF94D42D91632049AULL, 0xF0D142422E6C3E88ULL, 0xB182D77E323797DBULL, 
            0x32CDEEBF8CF190CCULL, 0x56D71413FB38054FULL, 0x10F600F614351BA2ULL, 0xB17B58E4ACBDF217ULL, 
            0xB1D8A5830B6E7423ULL, 0x426CD60C4D0F1487ULL, 0x22BEC4B6DA1ADB09ULL, 0x769544EC0B1331ABULL, 
            0x10C63253BFEE161CULL, 0x4823E6728F07952AULL, 0xBBDCEE2FE396C19EULL, 0x069CD5FE21CD5B30ULL, 
            0x09AB38B816881BCFULL, 0x903B8329C13CD5A0ULL, 0x019DC823CC06D0DEULL, 0xE37A79D9FEB5FC30ULL, 
            0xFF2439632D211323ULL, 0x9CD4A01315273E81ULL, 0x80E76AC9E90D5497ULL, 0x755C841BBB6B4E41ULL
        },
        {
            0x85C1A63F707BD7ABULL, 0x4E1E1740B61B6BD4ULL, 0x95E2E8181EE77B3EULL, 0xAA23E28BC1FD294AULL, 
            0x8C550EA5A6C75FDBULL, 0xBE40C38E10C3BC0AULL, 0x1A6C2592AD6AB8BFULL, 0x4B2526AE1EAD4934ULL, 
            0xD9236D1E1C8B2245ULL, 0x2F944A1B3A43316AULL, 0xA3E5D24B0ACF45DDULL, 0x35FD548791335FB2ULL, 
            0x361F15AFF17E8107ULL, 0xF37F84A15C676B2AULL, 0x14198CC68E97DB99ULL, 0xA510A36A089C3D63ULL, 
            0xD2E15A951B939E8BULL, 0x38BE2677D252EA5AULL, 0x065E6509F120F742ULL, 0x05D3F7C5A89AB0A6ULL, 
            0x0CAC987B59F564F2ULL, 0x0EEC61B1D9FC0E25ULL, 0x3E804DDC4515A8EDULL, 0x032B031E1DA97F05ULL, 
            0x7A4C6A266BC07BB4ULL, 0xC98E822D29CB8081ULL, 0x162E1B74A153342EULL, 0x627724EAE1AD7837ULL, 
            0x99AB3F4D11BBD757ULL, 0xBBA3D624F29D93E9ULL, 0xBD1A75583446AA3CULL, 0xA59479F14D56BE2DULL
        },
        {
            0xB58F3383C9AFDB30ULL, 0xC2CD249E37B03E66ULL, 0x00C49A2AA034C04AULL, 0xB78A27D3BE7E70F0ULL, 
            0xB7E7EADC5411BF87ULL, 0x0E9392FC40120DECULL, 0xCF8FE7684A579F62ULL, 0x28DCDF2F566BF3B4ULL, 
            0xB2EFC9C6B6FC4C7DULL, 0x392AB8D6A5D9677EULL, 0x410A8E6DAD4EC85FULL, 0xE4CE601A004666CFULL, 
            0x4967C03D8C1275A3ULL, 0x8028428BFF235E73ULL, 0x1CDE5D8B779E3108ULL, 0x980DA8B8CB81BA2EULL, 
            0x324AC0B19E8DB2DCULL, 0xBB73EC015383804CULL, 0x9E933DCB3ED03455ULL, 0x1ED0F8C0801ECA09ULL, 
            0x41C638CB7B76A7F8ULL, 0x9AB5584FCAA332A3ULL, 0x793B71B271B84016ULL, 0x13F1E84246C55F75ULL, 
            0x31DCB4602EFDA731ULL, 0xC8666778C57C535CULL, 0x85E0A028ED04FCE4ULL, 0x8CC6F1D69B9971CAULL, 
            0x25EBA4CD8A934CEEULL, 0x63EF73A21AD0AC2CULL, 0x6D54D72B38472603ULL, 0xC348069C41FB395FULL
        }
    },
    {
        {
            0x614271EA1C100640ULL, 0x45211582037D8A6DULL, 0x636062D38BF000E1ULL, 0xF7A2EBBFC133BECFULL, 
            0x03C046DBD527FA7EULL, 0xEC761E6BABAE51B4ULL, 0xA7AF187D1B5B7B7CULL, 0x745178E87B93E0D1ULL, 
            0x65757C91A7DC31B4ULL, 0x3C05052F66832268ULL, 0x0A0B9280157644ABULL, 0x4CC6B2EF6FC0D4C0ULL, 
            0x9E307315A89985C9ULL, 0x92622DA4728BB44EULL, 0xA2346C2E55CB1CF9ULL, 0x2597E8FD09C98880ULL, 
            0xD7772A63EE529874ULL, 0xF34D06081B315A5CULL, 0x42142271E650AFCAULL, 0xF8B8667A7F0C8D6BULL, 
            0x711F616D34ADAE1AULL, 0xD9FFC7723532945DULL, 0xCB4F779999BC3E41ULL, 0x264733DED7312BEAULL, 
            0x8E970AFEDE8F0B7EULL, 0x43DB5D05558E88A5ULL, 0x124839DC2B332542ULL, 0x3099B6034AA30A3BULL, 
            0x60629DD1716F63F4ULL, 0x83BC77F33DD8887DULL, 0xEF43FA7B64CA2E4AULL, 0x3DEF1E032DF61F39ULL
        },
        {
            0x9049AD1CFDC45E04ULL, 0x91A98F9CDF72EAB4ULL, 0xA46487B79250DC23ULL, 0xE41F0BB34136927BULL, 
            0x24A815BA4B5FE35BULL, 0x3116AFB577210FDAULL, 0xE665BFFB4CD024F1ULL, 0xEFBB7FC71425475EULL, 
            0x9C7FE11054D9A75EULL, 0xC933A60599587A25ULL, 0x869ED4DD56AE171BULL, 0xEAC1983F20D9231CULL, 
            0xF1E51601AB731569ULL, 0xF2991E9C48F1C538ULL, 0xE4CE8034F95F1AADULL, 0xBD06BF11A83074E7ULL, 
            0xD313E12D73A96590ULL, 0x96FB0305187A3BE2ULL, 0xE0A0692431E38889ULL, 0xC6DBC5D78AC3417EULL, 
            0x1DC6C9CCBE0AD250ULL, 0xB49B0AD0A065F64BULL, 0xD29501829E49B3C8ULL, 0x332444092F336830ULL, 
            0x1129007CE6A6D846ULL, 0x2CCA753E3C1D9EBBULL, 0xA9507D1E280E236DULL, 0x9106F9B06BF45C85ULL, 
            0xC10D633D835B13D8ULL, 0x5B3174208155DB67ULL, 0x3506EAEE8BD3270CULL, 0x8658218BA043C2EAULL
        },
        {
            0x872C68A358D2A140ULL, 0xD127BDB323DEE93CULL, 0xAF4E6FBE6268F9E3ULL, 0xBC146E375E78BB67ULL, 
            0x8F54A3A26B42C2EDULL, 0x734C5B7B1EF08F7EULL, 0xBFD9EC32BEFC9304ULL, 0x031557EFEF49787BULL, 
            0xEA7439A3518526BDULL, 0xE4EB0C2D5B84632DULL, 0x4C483CECF761EEA7ULL, 0xA013AE5BD86546E9ULL, 
            0x71AD9C2B03B539FDULL, 0x35F54C76961C844DULL, 0x6216AFEE14FE2007ULL, 0x6E2690279199EF72ULL, 
            0xE67DBC7B3B4BF338ULL, 0xA54C0A34E3D6A6A0ULL, 0x43A19DD0514FD62DULL, 0x7323E3C9CC59B067ULL, 
            0x48EAE944A93805BAULL, 0x7F2F4B62D4AC5D87ULL, 0xFEFBF95401A586DDULL, 0xE6382FBB9602613FULL, 
            0x7ABC5A2BAC82A7E3ULL, 0x7E899BF051C169BEULL, 0x5A268F83D6DB5462ULL, 0x5E5FB8DD98652470ULL, 
            0x5DB1FB3715FF6367ULL, 0xD0B78323D183FF19ULL, 0x394B4FB8BA93E3FCULL, 0x440A8637D377D2A9ULL
        },
        {
            0xB1E54F012FEDB4F1ULL, 0x7B3AA93F187B4D7FULL, 0xD754AEBB6D17BFEEULL, 0x20E5ECE3731C77E2ULL, 
            0x7E04E15175698BA7ULL, 0xB8146F1C94D59A54ULL, 0xC1618214DE91F069ULL, 0x50B6B82FE3374C37ULL, 
            0x67E00641B33A630AULL, 0x1052BE4AA04333EBULL, 0x2023B492B83781E6ULL, 0xC23621B4B9AB2A05ULL, 
            0x15D68E3742084278ULL, 0xF4FF7754899E1FD6ULL, 0x55602651E990F8B3ULL, 0x131AF43D0E1FC136ULL, 
            0x833D402FF06309E0ULL, 0x5498DCF651A2E84BULL, 0x5A9EE41EDD9C9026ULL, 0x39FBA9C49D0F44A5ULL, 
            0x837C462747F868CAULL, 0x3088EE1BA1B42D36ULL, 0x044DCD1104280CD8ULL, 0xB8D5636C50BDF731ULL, 
            0xCD2622E3F0DEB30CULL, 0xA4AED9283A81FB3EULL, 0x21D8CEFF5E0D72ADULL, 0xB0F7C4AD66D8E9B3ULL, 
            0x6A73A61A72489F5EULL, 0x2A81F3F13492488FULL, 0xAD9AEC3CB63F2D36ULL, 0x4151B8ACBB944120ULL
        },
        {
            0x9C7B0AAE0A587255ULL, 0x50FDD977C2AF14BFULL, 0x46C665E3A58732C6ULL, 0xE9C05AA5C5CB422AULL, 
            0xAB6ABA611548C6CFULL, 0x44C32885384BE3E2ULL, 0x57A8D950C38C3B98ULL, 0xDE7505230225DFC7ULL, 
            0x90DD875A1FCF37A3ULL, 0xD7471842C98E2865ULL, 0x0BD72FAA4D88F137ULL, 0xAA9EA922CFFD414AULL, 
            0xBB2F47A89D392AF7ULL, 0x4D8DBA326CE365C5ULL, 0xD62F0E0B4A8A1F12ULL, 0x4E3720A2C28FE544ULL, 
            0x2EDC7EAED3B9DA24ULL, 0xA5DF71707A088418ULL, 0x249ECA52CD562D5EULL, 0xEC1E5FB40230917CULL, 
            0x187519256BE4ECD0ULL, 0x4CE6192420EAEB87ULL, 0x97062FA3DAB5A909ULL, 0xCE7793904A036055ULL, 
            0xDEADACD6B9471CBEULL, 0xCB0CD462BCC6AA48ULL, 0xAA4662C22D03A87FULL, 0xEE76DB49B9535EA1ULL, 
            0x39C3C70B76F77777ULL, 0x88A28F9EA2936178ULL, 0xBEA9286311968A86ULL, 0x9A9E777AF4139F75ULL
        },
        {
            0x4EA8D316A5407881ULL, 0xE9D026702D6FBC10ULL, 0x3CE5674253A72DA7ULL, 0x3FB9050B9F3E523CULL, 
            0xE00D8EA81C7E4005ULL, 0x417125BD60E09176ULL, 0x9B6965C60B461786ULL, 0x4AB506D57BAA08AAULL, 
            0x72CCF7D4A00A9EA6ULL, 0x610D1FC562E27F09ULL, 0x414C3450A837B2DFULL, 0xC4707B98EBD6C198ULL, 
            0x602C21E9AA066C8BULL, 0xE1F07C7F2489D135ULL, 0x8E6C82206E08F5A6ULL, 0x6C74402D23E5CFCDULL, 
            0x7EA57324555BCDE5ULL, 0x50DF0FD1DA622504ULL, 0x53DF2C8E032724FAULL, 0x85FEC46564A5C2E9ULL, 
            0xDAE01C3743FA012BULL, 0x0F367EEB8DE90822ULL, 0x746097CB832B2ADAULL, 0x77F471867A3D3CA2ULL, 
            0x5BCD9C0E495A0E64ULL, 0x77D36C92D006755EULL, 0x3D4DD6E5BD6B1FD4ULL, 0xE2AF6CDC52AFC8ACULL, 
            0xE408D9A727F4B10DULL, 0x2A277BF5BE9EDCD0ULL, 0xECCC28A2A9589459ULL, 0x45A0BF7CD22E3CD8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseBConstants = {
    0x162E23A27DB3E5DCULL,
    0xD303FABFABBFC380ULL,
    0x5BE1A301147D9EE6ULL,
    0x162E23A27DB3E5DCULL,
    0xD303FABFABBFC380ULL,
    0x5BE1A301147D9EE6ULL,
    0xA139874D1430C886ULL,
    0x5600A194356DF75DULL,
    0x9A,
    0x46,
    0x32,
    0x41,
    0xFF,
    0x05,
    0xB2,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseCSalts = {
    {
        {
            0xF36282B892417975ULL, 0xB84724C88885119DULL, 0x2B26AAE70C88DB1BULL, 0x6681CCDB17AED02CULL, 
            0xB29EAF92D53CAE97ULL, 0xD9255C254D9F9139ULL, 0x70158DF7CBC63EA3ULL, 0x38D41EA7BB172E74ULL, 
            0xDDEF1B46988F63ABULL, 0x377B00B0EE3030D6ULL, 0x47962DA030F5DB0DULL, 0x9687F1EC6E6C9BE7ULL, 
            0x4BBD3FAAF431F205ULL, 0x90DC78B4D8BC308DULL, 0xC238DA2316BA9714ULL, 0xE1A43BFA84DC5222ULL, 
            0x9714DAE01BCC00FDULL, 0x4797CCB289766F16ULL, 0xE0BE0CB97845FB87ULL, 0x7E6D2390E94D08F9ULL, 
            0x01B6A299AD77E1E6ULL, 0x549112C915E15600ULL, 0xABAA862C1176734BULL, 0xCE3BFF1F0BA3EED2ULL, 
            0x7C56EA8B70CF0DA2ULL, 0xA40E5EE5D01AD11BULL, 0xBBF1234DCA29FE92ULL, 0xDC47A8AC50A2D046ULL, 
            0x781F6B98A4BAB20CULL, 0xA42A4AB63E0D0912ULL, 0x6843BE8E495A1E6AULL, 0x1B1F24C1676E47A4ULL
        },
        {
            0x3A4EBC96C6A41882ULL, 0x9CD25FA9871F24BBULL, 0xDAB32A245A9C2E8CULL, 0x1D60F2C8243735AFULL, 
            0x1B6C9B66CA577F52ULL, 0x3F06C9A6B9F345C0ULL, 0xD749242A3FC06B21ULL, 0xD2B75DAA78D01CC8ULL, 
            0xF40C5D264C5BA89AULL, 0xB9274A4C14779113ULL, 0x88ADF4F5C79B3D48ULL, 0xC700981823FBBD68ULL, 
            0xA505977A72BC09CFULL, 0x63CFA986D458ACB6ULL, 0xC5BF3DB1E10DE92AULL, 0x9321AD25B9C82812ULL, 
            0x08F60FB404122E0BULL, 0x8920B5034486547DULL, 0x0442438B0A257634ULL, 0x04C41007D9BB1CD1ULL, 
            0xE5F2989DFEFD76FCULL, 0x542EA6CF30B13CA0ULL, 0x62FA00502925B972ULL, 0x1F92EBB2EAC0C0EAULL, 
            0xF70BF980468A4318ULL, 0x335AC074B8C4EFD2ULL, 0xCD795B25A67AFFF5ULL, 0x90CEFB0C53868355ULL, 
            0x034B10DEA9065BF1ULL, 0x56E320FAF9CD5ADCULL, 0xED271943CA6DCFA0ULL, 0x45E28B56724E7D3FULL
        },
        {
            0xDC7FE173009C3D76ULL, 0xD9DB6B70F630FD3BULL, 0x9F47A8CD83DC4B3AULL, 0xD95592F3C286FF02ULL, 
            0x68CF1DC0C658CB0CULL, 0x6953F0E40E35110EULL, 0xE1FDB5B7EFE7B5C0ULL, 0x9D7DACBAC0223597ULL, 
            0x799F98734DD368E6ULL, 0x7CD837ECD3625DE3ULL, 0x4A0E85352199566BULL, 0xAF8BFA22B0F41B86ULL, 
            0xD7C3CEB8C1D79E83ULL, 0xB5E4A921CE3970C8ULL, 0xD7DB6ED38E292B9CULL, 0x3F44AAA5675D495EULL, 
            0x72AE0DE23419402DULL, 0x8AD4193EE9CF9F20ULL, 0x1AA6E9C0DA0DABC4ULL, 0x16DD782D6ABE67C5ULL, 
            0x37EBAFC55361D7F8ULL, 0xD11052C8CDF7F44AULL, 0xBF921E5DC1A062B1ULL, 0x50C827C0DFEF6895ULL, 
            0x223CB6A63104DDC3ULL, 0x39337FBFE6AAE506ULL, 0xC22E0452D14C7C8BULL, 0x4923231A90F5F0B7ULL, 
            0xA356AE9C1DB336EDULL, 0x21F54D6329C947DCULL, 0x8FA035EEC718C5D4ULL, 0x90030EA0153FBD78ULL
        },
        {
            0xC7BE464D94F7A7F9ULL, 0x4568BBFE28766EA1ULL, 0x3F3B985BE8BF8B0BULL, 0x1B36FC251E0CE7A1ULL, 
            0xF5FB167CFB6266D3ULL, 0x12E3B57731458ECCULL, 0x4A865F30B5BB244EULL, 0x56F983387C07D37FULL, 
            0x11B2A431E6CF3F1CULL, 0x8C300626F856B40DULL, 0xD229D5552472925FULL, 0x6784E40DA34451E3ULL, 
            0xE8E1570CD8F15A6EULL, 0x8B198CCA558AED3FULL, 0xC3E5BE98364F5682ULL, 0x32F194EA11BEB578ULL, 
            0x016E6F382B3AE6F5ULL, 0xDE1CC5E7A869F3BEULL, 0x1D65B63FC056D383ULL, 0x2BAC18E510457E40ULL, 
            0xC83ECC30A1AE3FB3ULL, 0x1B5D0756EF650633ULL, 0xDF3A5285E3DAF7AEULL, 0x26D02BD85A5FE49FULL, 
            0xE3F5D5A12B255FC1ULL, 0x6F37F16967947FF3ULL, 0x3976C6413C918B57ULL, 0xFBB99C737BA6529CULL, 
            0xC889D86723BA1657ULL, 0x025612E7E151833EULL, 0xB2CFE1F5B0CB7B92ULL, 0xCDF911AE217D61E0ULL
        },
        {
            0x1C04D0ADE117A27CULL, 0x379D206C05BA164BULL, 0xB2755A7AF8246D72ULL, 0xCF25F395A1BBF01EULL, 
            0x97F8BA586245EE56ULL, 0x645256A71D8FFBF3ULL, 0xA4AD949C7F805485ULL, 0x8AB48CF80EA8EF18ULL, 
            0xA0964826B7DE78C4ULL, 0x9E5F675411D82DDEULL, 0xEA7B728B160C8B9BULL, 0x5465A7E138055E0CULL, 
            0x294648936904E0FEULL, 0x865758FC032C5804ULL, 0x20CBA8DD57F4367DULL, 0xB5E0E164A1B12440ULL, 
            0x1E63E5DCEA75551CULL, 0x731773864B4E17D6ULL, 0x676F33E86062F53FULL, 0x05157CBC841A4823ULL, 
            0xF7C2E077070AB046ULL, 0xF2E32ACD6183A799ULL, 0x3842162B2A942491ULL, 0xBF324BB0698CD1A6ULL, 
            0x2D45F3E53D9D16F6ULL, 0xA96CCBEB893278BBULL, 0x73E9AE498378FD42ULL, 0xD86E7C12CE7CA0F4ULL, 
            0xC76477B69B41A087ULL, 0x16FE4E2EEBF2A668ULL, 0x5A4FB4B24CD268BCULL, 0x947F862CCD63E8E1ULL
        },
        {
            0x052E1C9C0D944E23ULL, 0xF33BCD41A98A1AAFULL, 0x110ECC117E67ED41ULL, 0x9CCF9828D0682930ULL, 
            0xDA92632CBD4080ACULL, 0xF2414F0E74A3C5F9ULL, 0x9EAEAA1265ED8E2CULL, 0x33BED78E4D4F0063ULL, 
            0x99F3D5CB07FF5F80ULL, 0x399E02E79ED75022ULL, 0x3419B9C35F805104ULL, 0x5F7C68E13D51E317ULL, 
            0x9441E55B2F28A820ULL, 0x81260396934536CCULL, 0x5E59261AB838E038ULL, 0x0A51F37BC64A3C66ULL, 
            0x2CE9DD339BDE9AE4ULL, 0xF062B1484595C000ULL, 0xDED196D7732A01E5ULL, 0x074F90938F65A4EEULL, 
            0x4BA55778546280FAULL, 0x61F53895476E4936ULL, 0xF449AE6EF789D8DAULL, 0x9BB2D49FF632C626ULL, 
            0x892164301C3042E1ULL, 0xB7EB1EC78693C45EULL, 0x0831C4F073F28420ULL, 0x23EACFC1F4B7AD6DULL, 
            0xD765C912900A137FULL, 0x2FF33B1DBDBC1424ULL, 0xF3406D11A362B52FULL, 0xCEFFA45E16CD8A70ULL
        }
    },
    {
        {
            0x555DC8AA72AC93F0ULL, 0x25F22F67D8661E30ULL, 0x0224AA237A640C86ULL, 0x26DA3F4816832A76ULL, 
            0x1A1F1B1A677E5286ULL, 0x5CD6C3963D54E39CULL, 0xDA832F8BA0308F39ULL, 0xC1814177BCA739CBULL, 
            0xD774AB9F43CEA91FULL, 0xBB5524AE435A3F65ULL, 0x24E296F0284C90DEULL, 0x38050118A55009D4ULL, 
            0x22CB072BAB32210EULL, 0xAF97A5DA11FEBDB7ULL, 0xC1497A38FF27EDC2ULL, 0xC1F3ED79372744AEULL, 
            0x32F62721BA7EF0B6ULL, 0xC9E9F560557AB12FULL, 0xC002B73B17C999D9ULL, 0xAFBEB30A3F335712ULL, 
            0x97CC7CCE61C05B12ULL, 0xD789BED8EEA287DAULL, 0x60C385938E35864BULL, 0x52878CC60BBE4A73ULL, 
            0x8E62C6BE49D54D58ULL, 0x60182EB181AA4F11ULL, 0x4E330C9CE234F20AULL, 0x7992A2A8CCB6E836ULL, 
            0x0F87959CAF427785ULL, 0xAF2CE5A4CAFE5D3FULL, 0xF33274E6C2360896ULL, 0x6843EA55AF8AC1BBULL
        },
        {
            0x770680053AF55C49ULL, 0xDDB1F95F907634FBULL, 0xC5CB97A5ABCDDC01ULL, 0x0D6FD18F9B4BDA5DULL, 
            0x00A2037D2A133DBFULL, 0x11DE61C3A2C72D6AULL, 0x8D931136ED6E620FULL, 0x004928C53D2A3898ULL, 
            0xE6362D55EB5CA409ULL, 0x16F0FA443FFEB689ULL, 0x67EF186B0A51DF28ULL, 0x96A7DC61F5CD4F8BULL, 
            0x5A486082EDE0CAA8ULL, 0xFB5A3C7A40123C21ULL, 0xCE822555DC0F3F4EULL, 0x40205535BF731980ULL, 
            0x6FB6E2A81456909DULL, 0xE9156365ECD4785CULL, 0x5600DE503A6CB430ULL, 0x4AC9693B060805C3ULL, 
            0x8BE62E1E5A1E476DULL, 0x28E36800C5ED263DULL, 0xEE334CD80B5E29B6ULL, 0x6F248DF9738027CCULL, 
            0xC0316975914544B8ULL, 0x6BEEBCF36DAEC141ULL, 0xD6031A491CEC2C1BULL, 0x86D28B39165D5FC6ULL, 
            0xF3C4E242C4AF78BFULL, 0xBFBAF8741D3873F2ULL, 0x627C1363D2708E32ULL, 0xE91C988DED5184F1ULL
        },
        {
            0x70CE0DF2D49CBA09ULL, 0x2DE43563C1C56E8BULL, 0xD61462781AF3D604ULL, 0x88B7E85E4C956C78ULL, 
            0xC86E9CCD11AC95FFULL, 0x1204EF53B3D49926ULL, 0xE5B85BE5794A82AAULL, 0xFE40EFF777171301ULL, 
            0x38206A16AEE01E3AULL, 0x14FB8FE0A0068C60ULL, 0x34F27DC2DC56377EULL, 0xA317974FCA6E0352ULL, 
            0x8BD4ACDD7B852872ULL, 0xAEAE50F5AF9EA993ULL, 0xBF459FEA25C21ABEULL, 0x1B0980BE0D81251FULL, 
            0x1EC69E8A949A1716ULL, 0x04CA8710908AA42BULL, 0x7180F37B32882802ULL, 0x3FC7228E3799FF5BULL, 
            0xC11FFAD42266DD1EULL, 0xAD8F6230F62CA0C3ULL, 0xE4726F1A61A641E6ULL, 0xA95F819E58144D1DULL, 
            0xF7CEC139329762B4ULL, 0x9D0E5FD0D90A6EAEULL, 0xDA18EB16D3506DE2ULL, 0x33543DBC27CF2028ULL, 
            0x1C69FEB97776718BULL, 0xF832AC1B5329E06AULL, 0x60C0FC47F1953E36ULL, 0x819D26DF1498249AULL
        },
        {
            0xAD846EF4F5E6B333ULL, 0xC75792F33B23878AULL, 0xE809A33DFBC27BC5ULL, 0x69A1D026D54254AFULL, 
            0xB5F9A9E651990608ULL, 0x62E9A2705C9A8965ULL, 0xE7D9081ACEDFAAA9ULL, 0x480C69FA82DDD50BULL, 
            0x6AAD792CF7D9A95BULL, 0x4F5FA1D05192CB61ULL, 0x8BFF261DD0EA4877ULL, 0x752564110AF39B16ULL, 
            0xB7D2987808EADF2AULL, 0x7B1561A698ECD1A3ULL, 0x3624CE9D6492F48AULL, 0x5F1A5D5DD8AA8FADULL, 
            0x1496FB162EB26FF2ULL, 0xA74EEC94C383FBFCULL, 0xDFF19A3EE27DD047ULL, 0xD099809190CA2F58ULL, 
            0x96BAB3730F967DF6ULL, 0x274680DD9A123455ULL, 0xB7866178291F111AULL, 0x22532BD4E118D0C5ULL, 
            0xD41D123EDC5E44ADULL, 0xE9F6B9B8A58528F3ULL, 0xA076C5CA885CAB74ULL, 0x4DBE8D4EC66ADB7DULL, 
            0x76CD7CADB818A5B7ULL, 0x13C5EA1B6EE19BAAULL, 0xD0AD7CC316894362ULL, 0x7AA851432BEAC015ULL
        },
        {
            0x75B1708015B772AFULL, 0xB12DE5EAE3634126ULL, 0x087772882C146BDAULL, 0xFBD9C91468FA4399ULL, 
            0xAA6B1C0A017366DAULL, 0xD1BE82B2A75CB27FULL, 0xD0F6FE1AE2AA1183ULL, 0xC4492CC12246B057ULL, 
            0x338A1F7D4E7FD432ULL, 0xB6F1278115749376ULL, 0x841721E7D1D22FE0ULL, 0x286871692B935FAFULL, 
            0x5B0ABEF9B3E60356ULL, 0x1BB8A28F010A9CC7ULL, 0xA0DC34D1E6889050ULL, 0xB9D860E00F596577ULL, 
            0xC685062262792C64ULL, 0x7A4DB764932A2932ULL, 0x087445633A95CE5AULL, 0xBC11A07CB34A4755ULL, 
            0xFA0F4BD225382A29ULL, 0xB127B44256D51D53ULL, 0x502D30764A6D9F16ULL, 0xADEFEBFD3EA32272ULL, 
            0xAAF8D640519A2FE8ULL, 0x6C9AD27C68FE821EULL, 0x71E0522C3441CA9CULL, 0xEC2FDE6DD820B0FFULL, 
            0x3579B83351E97399ULL, 0x7E2E0A49CD0239C5ULL, 0x5E8E1B1C05727525ULL, 0x65144B565ACB4296ULL
        },
        {
            0xAFE7E80072EBE5DFULL, 0xC87364E67EC58C05ULL, 0xAEDD4FD22F132F41ULL, 0xCBF8C7D8F184DEC1ULL, 
            0x7818B73280B78F11ULL, 0xA2434276DE728770ULL, 0x2E0E72076B474C53ULL, 0xA5EA8992F9CF224EULL, 
            0xD9008AB8D0CDE694ULL, 0x0D83C51B336BBEA7ULL, 0xECE249F75B7ECDDFULL, 0x010646AE987F9626ULL, 
            0x16992E3C180E258EULL, 0x15984F23ACD04DFBULL, 0x7B9265713F07904DULL, 0xC6FCAE16D56905DEULL, 
            0x5090B5B6B65A50F9ULL, 0xD643BE87515AD7EAULL, 0x976F1FD29435A707ULL, 0x55268AE78193F897ULL, 
            0x9B1BA66617C46672ULL, 0x5BC569115CD5B367ULL, 0x176C81C0C29C22B7ULL, 0x61CBEB9CD221668FULL, 
            0x6F07673281B9BC6FULL, 0xD2B3EF5895BD4E3AULL, 0x4D70FEA163AE9E71ULL, 0x0C588056A47C6FE2ULL, 
            0x6B10ACA88F366731ULL, 0x24B794A2367CDF81ULL, 0x0A944EA63B6496C2ULL, 0x2649733E0A4E8B02ULL
        }
    },
    {
        {
            0xE198C38434D5E9DAULL, 0xBD8E108D4344ADCEULL, 0x0909091B1929D8CBULL, 0x726650D462567F3CULL, 
            0x2E96397A8ED63A9DULL, 0xEA5DF6AC2DBADEFEULL, 0x078139725E94A456ULL, 0x391364E7770955DEULL, 
            0xA9BBF501DBCA45BBULL, 0xC668CB44F7985B0BULL, 0x5B337849498D68C7ULL, 0xF945CBBBF3DF3E0FULL, 
            0x6A930007BEF933A2ULL, 0xF034F5BB3DF7247BULL, 0x078A5C481C30C996ULL, 0x831A307ABF2224DFULL, 
            0x56E52BB23D3D33A1ULL, 0x0F4F054C1C2841ADULL, 0xFFE60E44D5F7F8A4ULL, 0xA651FC4DED460440ULL, 
            0x34CB047DD2B3C460ULL, 0x1482316F76833D40ULL, 0x174907D79F4E48A1ULL, 0xD5ADCE3BEF56F776ULL, 
            0x8A3AC721520FA78BULL, 0x825E6597B1F88632ULL, 0x592354992FD7FDF9ULL, 0xF085845BF4880913ULL, 
            0x61B1C9CC08284FC6ULL, 0xE8330AA58EC534DEULL, 0x3459D2B100E6703FULL, 0x37263B776581ECCBULL
        },
        {
            0xA04F54D6325BF040ULL, 0xA4BDFF492E70176EULL, 0xEA14C82E409B09D9ULL, 0x8D0EF9DAC45EE5A9ULL, 
            0x9A794EB708052417ULL, 0x98AE2DA7D44BA69DULL, 0xBF9B99553EE5FC6BULL, 0x5C05806A660D686DULL, 
            0x0275C2AEBC3CCC6DULL, 0xF47A4710244A72A7ULL, 0x83F4AE3C30D8EC5EULL, 0xAECB9D20AD898C5EULL, 
            0x980DD0E155A44CB2ULL, 0x66A4614660F53E6CULL, 0xE8F6583166B3621CULL, 0xF940C7C8E2BF4BD3ULL, 
            0x93E98E10077545C3ULL, 0x381652D9179D59E3ULL, 0xCE2F5DE114FF6097ULL, 0x864804F0363690F8ULL, 
            0xA2E8D7B971FB5F13ULL, 0x4286DB2B0FF38F34ULL, 0x9EFB80B0C722F43FULL, 0xC2738701CA5750B7ULL, 
            0x2C8168FD750051C1ULL, 0x4FB01AA670BA2D1AULL, 0x12F0A5351562D8B8ULL, 0xAEE05018AE9447BBULL, 
            0xF394A485348DBE45ULL, 0x667A1064791FB71BULL, 0xB5F555DB5F8343CEULL, 0x30F4610C436220C3ULL
        },
        {
            0x470016DFF318E497ULL, 0xE50439BA5934548AULL, 0x622808FE77C48D07ULL, 0x113A9708037BAE6DULL, 
            0x97E2174457AA9FA4ULL, 0x98D0B2B1D4B9AFDAULL, 0x2B4CBC9F9CBD9ADFULL, 0xC4E84B55B21B2968ULL, 
            0xF51C817D303C46BDULL, 0x898F51DDAAB3FF77ULL, 0x032F36D1FE9CC573ULL, 0xFE41AEB1CC6A4FCAULL, 
            0xF6F0BD5929A08521ULL, 0x2C9B319D6043E559ULL, 0x7D8051F8485D6E1DULL, 0xE8806E3FCC93F8C8ULL, 
            0x5EF3C2FF9BBB5262ULL, 0x46BB6B82B907D8D6ULL, 0x77CCD2C84B776710ULL, 0xC3B7A1E933B7ECB4ULL, 
            0xA3C1F774CEE3592AULL, 0xAB229C0570338071ULL, 0x3380C035DEFAC724ULL, 0x4B37A7F37B70658BULL, 
            0xABDEC127ABA1CD9EULL, 0xA0C36F267B44EA1AULL, 0x5A5BDD28B4CE6CEBULL, 0x3E69C9BFCE40D33DULL, 
            0xAC3ED358946A37E1ULL, 0x66BB10A27C222866ULL, 0x1C48E99F59B9F5DBULL, 0x4B3F80CA575BCD07ULL
        },
        {
            0x6DB5F9EA715B03BAULL, 0x6B1F2545C163A2D6ULL, 0x6BAF5C8326146A58ULL, 0xFA8C8C1E07873E53ULL, 
            0xA5549C50A67670DEULL, 0xF61518F062B0AD12ULL, 0x4E387BA822E72DBDULL, 0x1389664247F858F9ULL, 
            0x29871C757F32AF38ULL, 0xA9701B2D7B6E3D8EULL, 0xEC1BC16BA15AD3FDULL, 0x9D68F57708FFEC4EULL, 
            0x3C01360A4614611EULL, 0x17411D6F0FA9695FULL, 0x1CD8B06B8044BC5AULL, 0xD32F09C91C76B25BULL, 
            0x07C4F34EB115C05AULL, 0x5FD89D6275277CA5ULL, 0x52E0F50C8DE829A0ULL, 0x6C7ABC3EBD1A123AULL, 
            0x872046DC7FB01CFAULL, 0xD21788B31C5B2625ULL, 0x41CD8EE2ED12AE8AULL, 0xC57821ACD91EEDBCULL, 
            0x5550C3A33AF19075ULL, 0x407C5A30239E9688ULL, 0xA718C00C69150E25ULL, 0x3351718B56AAA260ULL, 
            0x947299829C6782D2ULL, 0x3F48B5698EA98CF3ULL, 0x37E136E023AA2F62ULL, 0xED297165FD07EF3DULL
        },
        {
            0x3529E37F1347F399ULL, 0x883361E1CCF69B14ULL, 0xF64ED4B890A407CDULL, 0xA32C008D487AABD3ULL, 
            0xC9D40DC7A1626F0FULL, 0xCA0933AB3F81936CULL, 0x43A68834A0FD0989ULL, 0xCBD66FB18CCC7B09ULL, 
            0xCB10BDE13B92217DULL, 0xCE0C3B640E0408DAULL, 0x030F0B31A1D72D02ULL, 0xDBF0779D40E84E07ULL, 
            0x5BA43C73F5E4A245ULL, 0xBF9E4E2C297CF9D9ULL, 0x97821FD902745BF8ULL, 0xA56F32A644E31509ULL, 
            0xAFCAA54FCC50CD35ULL, 0xB8580C49E6865802ULL, 0xFA2579C3B120C5B2ULL, 0xA80B2D571C44121FULL, 
            0x94DC73598332A415ULL, 0x5443EC0DF2A27469ULL, 0x060078EC315C0C79ULL, 0x514B5362B00EE201ULL, 
            0xA206BDC6E4A57AB8ULL, 0x1D9495CD8ACE8F92ULL, 0xDE618AAF029C429FULL, 0xC1C0E2DCD86579C7ULL, 
            0xFEEB99D32DEA4049ULL, 0x755EAF2DE4F7F472ULL, 0x170E1F1341D5E5ADULL, 0xAE8F6052AE44629CULL
        },
        {
            0xB71E36F9A472CB70ULL, 0x616883F82572EDA3ULL, 0x28E8C126AE0B5370ULL, 0xF6EDFE5F3437C206ULL, 
            0x4CF0ECBE522F390BULL, 0xD783C4795A5FDE8BULL, 0xE05213CEC5B61A47ULL, 0xA1277ED012A342E8ULL, 
            0xABBBA0A19312AC48ULL, 0xAB89F51B105214B1ULL, 0xACB98FF6CCE2F039ULL, 0xD8A06E2549E247D4ULL, 
            0x88B65FD8E84B907FULL, 0x9A294D089C4A21EFULL, 0xC4B8BF95F9E3B933ULL, 0x2D5B29697C943C31ULL, 
            0xDCE5FB0C42EFCEA5ULL, 0xDBBC9C368CF77910ULL, 0x37F57C8EA3AB6B25ULL, 0x3961D727606F08A3ULL, 
            0x35780031A7982973ULL, 0xFA531DA61E012F0CULL, 0x81E4386703C92C88ULL, 0x753998AE2B096AD9ULL, 
            0xCB21A92B829F75D9ULL, 0x3AE46CDBFED8CDBCULL, 0xC75532D42867A73AULL, 0x3400892FF8DAF089ULL, 
            0x485A8EFAE43CC088ULL, 0x3F6509D6DF7C3E3EULL, 0xF16117C59329CA1EULL, 0x063FFA7FD75046A6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseCConstants = {
    0xDEF4C26063EF425AULL,
    0x024DF1CC35706925ULL,
    0x45C795AA109A68A8ULL,
    0xDEF4C26063EF425AULL,
    0x024DF1CC35706925ULL,
    0x45C795AA109A68A8ULL,
    0x71CCB2DC1DFC3C00ULL,
    0x16721FF42D250320ULL,
    0x9C,
    0x03,
    0xDE,
    0xA1,
    0xB1,
    0xF4,
    0x70,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseDSalts = {
    {
        {
            0x5A458E63C64F7CC9ULL, 0x3CC7E77669A6A05EULL, 0x371E58A29E27017CULL, 0x1D5C2CB81877908EULL, 
            0x72506A1BAB57506FULL, 0x493227DA0668D853ULL, 0x0CFA763EA9E13B68ULL, 0xE8165E7EECC9F340ULL, 
            0xB9F35D8428E99BA1ULL, 0x6DCAB0C716BEF7B9ULL, 0xB8C13658B0EBF9D5ULL, 0x3FE0DAF94C163F99ULL, 
            0x009D53BD83E27B37ULL, 0x8F38EB8F5302E1B9ULL, 0x9868DC53A183946CULL, 0x3B0EAEF6A39E07CCULL, 
            0xE6AE41E1A5D2DBFDULL, 0xE4188ED7DDD8244BULL, 0xD733C444366B8A56ULL, 0x43A28132F622D776ULL, 
            0x80813FFF57691C98ULL, 0xC0837024439F284DULL, 0xE5AE4E21ABBE8591ULL, 0x98B44D835918FE22ULL, 
            0x7578E4A46DC85CFBULL, 0x13184D5E135BBCBAULL, 0x1F60ADFA5A8D3B6FULL, 0x309D8C4A2D56DC28ULL, 
            0x88CEA2387167183AULL, 0xD764FAB55416FB9CULL, 0x07AFA08B53439EA9ULL, 0x02FE27BBE9D2851DULL
        },
        {
            0x1439FF5C71B3ADE1ULL, 0x985599EDF087AFDCULL, 0x78B2C1AA14BB8739ULL, 0xB5232E01CE25BB51ULL, 
            0xAAD54DEB983324A1ULL, 0x8C24FFBA4BE81331ULL, 0x095E4010341365C4ULL, 0x84F85ADE77D6607EULL, 
            0x3275939D115EFDE6ULL, 0xB6A4FAB48BCA687CULL, 0x32BB02AF7F8C3210ULL, 0x60429DBEC395DAA1ULL, 
            0x72307D6E5F4591C4ULL, 0x0D74EEAFA9605E3BULL, 0x8324F1478E1883C1ULL, 0xE9CC2446CB17B300ULL, 
            0x9CC6AFD523BF63FAULL, 0x5F00D22C9A5B0B1EULL, 0x275E7ECA66EE8C98ULL, 0x297EBDCCC98C132EULL, 
            0x378E0DD81B3E5BCFULL, 0x4F028FAE57CFAF3DULL, 0x349329D2C6D0C150ULL, 0x62234417BD064D7BULL, 
            0xACC47590D5CF6952ULL, 0xB938239C4BFFF1FEULL, 0xC5EF312467DFC847ULL, 0x2156726B3B880A26ULL, 
            0x0AA108D06A20C0DAULL, 0xAE5FFD3D58A7C739ULL, 0xE74CAC53D9AAC26BULL, 0x69B7FAD6537847A2ULL
        },
        {
            0xA73AA92CDE66D32CULL, 0x6E6A85CD05C54E17ULL, 0x14B2020E793FC2E5ULL, 0x2AE7045EC37B12D1ULL, 
            0xB012B7CD52BF3E3AULL, 0x24CD485EC06DED96ULL, 0x0367CE0560D7CA6BULL, 0x9789AEAD61B98B06ULL, 
            0x253E81F520B7AB5EULL, 0x2B9E7A93F3316BA6ULL, 0x9401D5467011BAA9ULL, 0xF54F1BE890CAF94BULL, 
            0x5A6E9B228E45ECCDULL, 0x509D5F6821B53C4CULL, 0xC550B876C88A9E1DULL, 0x027511F9ED35D0BDULL, 
            0x733EB1EF69703741ULL, 0x33EF3455565569A2ULL, 0x213B5C78CA6267D8ULL, 0xBD9E58345CB6387BULL, 
            0xBAE640165FEA76F3ULL, 0xFFADBFE695A03084ULL, 0x4171F8E7FCB94AB3ULL, 0x58F3CC66615EE11AULL, 
            0x3FFC0E7108FE354DULL, 0xE80E0E43FD2005F7ULL, 0x71B70968C9B38B9FULL, 0xA1D63E6F78F0BABFULL, 
            0x001A4125EC4810E3ULL, 0x009DCC2CD8A1045AULL, 0x79E319436C9B1506ULL, 0xCBCDF29F2422D8E9ULL
        },
        {
            0xDABC8D73E14CD060ULL, 0x5D24FFA3960397B8ULL, 0x40F77C347A57845EULL, 0xC085E6699E48B9E3ULL, 
            0xA612B3ACDF3E404EULL, 0x38BE65327DE60A44ULL, 0x8012E83BD1ED2F0FULL, 0xEBD569052155C288ULL, 
            0x5DDA73681E2B7FA9ULL, 0xA04D5AAF8B69EC97ULL, 0x395154B65F6693EAULL, 0x4D36751C411FBB99ULL, 
            0xC008D72DE48708BCULL, 0x5DF10208DEC4261FULL, 0x468CD258B6AC409CULL, 0x4AAD61922071C7F9ULL, 
            0x9CC500952CDC1E77ULL, 0x2B83A9862149F102ULL, 0xD94D7B8B399D0546ULL, 0xB2DC8FEC3C98E373ULL, 
            0x812ED24F9539ED3AULL, 0x6EB72C473BFA834FULL, 0x9947F5F079BCDDC0ULL, 0x025D0DCF32469B97ULL, 
            0x42B33C6499C83C71ULL, 0x2A7BE8E97669B592ULL, 0xFF7F7D195182CAC7ULL, 0x6F5059964CC77439ULL, 
            0xDDAA00F0689BAC1FULL, 0x47A1E0B9FFFB992BULL, 0x7F2D0343170BD796ULL, 0xDE2DC10EF056D201ULL
        },
        {
            0x6A18D2ED5D321CA3ULL, 0x1585F2D7B7BACA3DULL, 0xCADFB13FB59E61F2ULL, 0x62C8261CE01CFF61ULL, 
            0xB9FD3CB029EAE8C0ULL, 0x73DFD6187E44EF6FULL, 0x43C0574DB9F37141ULL, 0x1F7B99A7373C17D1ULL, 
            0xA5C05541A2A02297ULL, 0x1DA2CBD5DC1FBEB9ULL, 0xA5FADDDD0649AC89ULL, 0x59B27226DCAF6D68ULL, 
            0xE559ADDB58EADAB2ULL, 0x4B2B65DC9D589A45ULL, 0xAADCF15BEB42EB9FULL, 0x7D9ED5A34BF6BA60ULL, 
            0x01E108E26C888FCBULL, 0x72B45BBD0C8EF7DBULL, 0xAE4A24711C021DCDULL, 0xBC58B79C4AFE13F2ULL, 
            0x74E7285598B54C28ULL, 0x7940BCB7EE1186FBULL, 0xA6A54833515FF091ULL, 0x7BC7DA863446E807ULL, 
            0x43C70DE56CCA020BULL, 0xC2D66ABEB4AB6F25ULL, 0x7D88284707E83511ULL, 0x64435A7A34C97D9CULL, 
            0x02C20DC38EB2CDCEULL, 0xDAD32D7FBED04EA8ULL, 0x8D89F6718F9A15FDULL, 0xD240E804C5FB2548ULL
        },
        {
            0x71C3C6BD2607BB93ULL, 0xDBD382CF14C69CAFULL, 0x4C5F238A6875F506ULL, 0x50326A3CF31A035EULL, 
            0xE737177C9050AF0CULL, 0x6975C9CB427F6EB7ULL, 0x10967C37D40880F6ULL, 0xE1FC383B18D36762ULL, 
            0x1A19BE04D26F0453ULL, 0x406C1C93DB916EBDULL, 0x3014F303E5017ACBULL, 0x7B75464675B2E07DULL, 
            0xFB936F68663CCF76ULL, 0x66C42B86F91C5E71ULL, 0x0230EF70092F2F09ULL, 0x298CADFA5C822585ULL, 
            0xE9722F4E2BAE0F64ULL, 0x0AD7FFCDCFD9EB26ULL, 0x6D2DE345E0D224DCULL, 0xA3B3A55A6931CAB5ULL, 
            0x897252E7453B955FULL, 0xE913E9D3D46B52EEULL, 0xC2B31D907FE1FECBULL, 0xF81289AE4D6D8247ULL, 
            0x6E841CB4EDD15CDCULL, 0xA3AA8D5E3251F16CULL, 0xADDE922D4152654FULL, 0xE3F5E1706355E5C2ULL, 
            0xD12BFA376B3C3B01ULL, 0x87CB5B06F601C79FULL, 0xB887F404FE66DE28ULL, 0xED0832558A7FEC45ULL
        }
    },
    {
        {
            0xF273D6FB3A5BFA0EULL, 0x7E14E0DCCB5BF421ULL, 0xAACB92C8B28ED28FULL, 0xE3BB5AF310A559CCULL, 
            0x90877A1E5EF80BE1ULL, 0x04A68A05486E1D8BULL, 0x04AA52A7D972B84AULL, 0x8E18BFC81EAC01B2ULL, 
            0xBD1F2D6101080A5FULL, 0x616578D773EDEEB2ULL, 0xE45A44DC42124F1BULL, 0xAAA38C4958EB16C2ULL, 
            0x2F4C146C62100248ULL, 0x3A2239AF5E3005BBULL, 0x6B0AD73145D2D061ULL, 0x5806164944DF5AE7ULL, 
            0x8D33880B62410B14ULL, 0xD4D0AC71DFC678A8ULL, 0x7D674C64A7ED263AULL, 0xB3AACDA68F4F4F4BULL, 
            0x62C92F7D3EEFD960ULL, 0xD5A1B0922301FB25ULL, 0x96E830A810DDDD8BULL, 0x0BD3FE1AE265BBD3ULL, 
            0xB53664734ADD5C7EULL, 0x0DAC4B02BBC106FEULL, 0x403A8EA9E8BCDBB6ULL, 0x7D34D0941795A5EFULL, 
            0xBC766A482B99CCFAULL, 0x8B3A7845B9F71461ULL, 0xEDDEB0AE898EDC6BULL, 0xE28FBD8398D49671ULL
        },
        {
            0x6BA7D493CA0367E4ULL, 0xF9604270F63CE585ULL, 0xCDBDD2D9BC7BBC20ULL, 0xFD498F0E0928F23FULL, 
            0x99050B45AB9C7E6DULL, 0xDBC3A604C0D9DED8ULL, 0x3FB7EF4915AF2149ULL, 0xCDC827348E90D230ULL, 
            0x0C55BAAB9364D99AULL, 0xB9AC0291B903A63FULL, 0x1F6A9844D11F3698ULL, 0x289858B64DDFB741ULL, 
            0x6975E27FD2377694ULL, 0xD3DA877439F173B9ULL, 0x818AEB2538B95208ULL, 0xEBFAA7745403C912ULL, 
            0x3B269F02B0D6A397ULL, 0x08EA89A726F5D095ULL, 0xEB3277090E98BC38ULL, 0xA3BF5FA6A1624D19ULL, 
            0x5C1503AD69E881EBULL, 0x13E284F064FEE526ULL, 0xB353C079C92CC1EFULL, 0x847DD3A1EFBD29D7ULL, 
            0x1474807CB927FA8BULL, 0x6C6041E5025A92F0ULL, 0x2D10D136B47F8CF9ULL, 0x847F55D64831E2C2ULL, 
            0x31934F8375DC9726ULL, 0x0F98A090432B34C9ULL, 0x56CDE6D34D528A93ULL, 0xB5E65086804BF0D0ULL
        },
        {
            0xC83B001758092A1AULL, 0xC61330911AE6B209ULL, 0xDA3D8430F5BC1511ULL, 0xA5CF4DF70793D975ULL, 
            0x6726B04D28E709DDULL, 0x6B9236E54E0B323DULL, 0x30030B02D09F4979ULL, 0x1C4191D8B8EE04C3ULL, 
            0x8D084C353234DA20ULL, 0x8198011B19767924ULL, 0x81139723E525FB69ULL, 0x48BBA19B57F7809BULL, 
            0x4A4320C07761D6A3ULL, 0xA9BC2E25B0608764ULL, 0x0D47487427C19F03ULL, 0x4F40EEBD92AFC306ULL, 
            0xA071B40E5B5AE22AULL, 0xC481E2515966ED25ULL, 0xB3E5D62119A38ABBULL, 0x0CFA050B5F818C4EULL, 
            0xDDE437A64162A44CULL, 0x8BC74365EAE085E1ULL, 0xA949F3E067A3F0DDULL, 0xB38086F6B7A21150ULL, 
            0xFC65A93F43363C62ULL, 0x5A6A223904809040ULL, 0x4E170B7CC6D1B054ULL, 0x69743EE479D0EC2CULL, 
            0xE83EF69C68CAADC7ULL, 0x61211246EF7A50F1ULL, 0xF3C0F167B2C4A5FCULL, 0xE75F594FDB00CEDDULL
        },
        {
            0xA8ECA6B942CF32FFULL, 0x696415747ECF0CE5ULL, 0x67D64D84BC82A5CEULL, 0xE18712D07DF1ADFAULL, 
            0xB413960701B35441ULL, 0xFFA98A01C847755FULL, 0xC5163CFAFC74CA20ULL, 0xC677BFBF8C661FC1ULL, 
            0x9D158340BB8CA1E4ULL, 0xEC507D1FC13ED976ULL, 0xA70E4250EE9F7072ULL, 0xEC4689795F846D41ULL, 
            0x6D14536D87A64DEBULL, 0x407B3C974EC697AFULL, 0xFBE71AB63D565811ULL, 0x09CF19FC3A45B1E5ULL, 
            0xA767263AE152DC8FULL, 0x9AE5B7A99C38FD65ULL, 0xA0723858A2A4B06DULL, 0xF4EB493FDABA13BFULL, 
            0xAF88C5394077D499ULL, 0x427EB9894EB3ABF0ULL, 0x9EA2EDEFB6A5F76CULL, 0x6D226C8B73543BA1ULL, 
            0x32D6B9035DBDF03DULL, 0x06097EDC5E32F457ULL, 0x480E95EE86F0A295ULL, 0x00A1EB9D70CE7246ULL, 
            0xF3F55C033F44CCBBULL, 0x18B3B22A2DDD8221ULL, 0x5B3ED0D7DDCD3191ULL, 0xAD3A49B98DA32EF7ULL
        },
        {
            0x904E4E07ADA41A79ULL, 0xE9EEDF005F1F967CULL, 0x070A2DF8475B99C9ULL, 0xB85E7B3933C6FAE7ULL, 
            0x7959F30E00A66F8EULL, 0xCBED57778B55416CULL, 0x361EB64375966F6BULL, 0x9D38456DEA7723F2ULL, 
            0x5ACB79CDD518B034ULL, 0xB75A014AEFA93ED4ULL, 0x6331A77CCC9ABBDCULL, 0x51A675AE49CF0152ULL, 
            0xFCECF0545ABEDDFBULL, 0xB78A80D9268A9F1AULL, 0x15370030F437E7AFULL, 0x850520A125A5BD64ULL, 
            0x89FE8DF3C2E1C889ULL, 0x92545176FA5A4304ULL, 0x4EAC1DFD55D909BCULL, 0xD89647D0FF2A464AULL, 
            0x1F27F5E952663416ULL, 0x52276228A9AAA3B6ULL, 0xF5052E83A36B55CEULL, 0x8F102903D48ABDB5ULL, 
            0x365213D90088B4A9ULL, 0x9CC3CCB674DCE58FULL, 0xC3665986D1C76A0FULL, 0xA63A1579290EAC9CULL, 
            0x51FF859FF467331FULL, 0x23EABD55C670B477ULL, 0xF263916F9D6E837EULL, 0x6856FCD32FC96287ULL
        },
        {
            0x8323D7569FF0A599ULL, 0xD3D893EBFC139149ULL, 0xD9C3C8B4297A0D5EULL, 0x5F3AEB0B83310E12ULL, 
            0xBE807E31DB98B197ULL, 0x8F4865D8A994F58DULL, 0xBA75CCCC0A2887D7ULL, 0xF246C4AA8E204512ULL, 
            0x4AE5378A9AFC09ECULL, 0x8939D27E5EF58D9FULL, 0x5429321F8850249EULL, 0xB8CE35887831319DULL, 
            0x3DDCD740B068B249ULL, 0x51F0EE96C976AC3CULL, 0xF55268134D036D2AULL, 0x65A376C76DD54282ULL, 
            0xC121EE8A03AE2174ULL, 0x97C797213F3A3999ULL, 0x67B3F86990F1A468ULL, 0x23B5B90A10622121ULL, 
            0x5EEAC5340B970C2DULL, 0xD41E899FB7917CE5ULL, 0x8532C4B15965C391ULL, 0x51629CE9BA90ED29ULL, 
            0x9913BBC8ACAA7770ULL, 0xECFFC06CF95CC312ULL, 0x0AE79FE9340F07FEULL, 0x2E68922C162D82BAULL, 
            0x92D87B91C2D32F17ULL, 0x208A05D8A293E638ULL, 0x79B4CFCC19EB43E5ULL, 0x5BE4B744574CEA0CULL
        }
    },
    {
        {
            0x4215337B8B1C0E6EULL, 0x1C755DD7E903FDAAULL, 0x11A3772A4126B3C7ULL, 0x9071E53ED288C0BBULL, 
            0xC1FD13CACDB7F79FULL, 0xECD2411250C01FECULL, 0x694B15D215720FF8ULL, 0x7AA6A445A6AF0A7DULL, 
            0x71481B770BCF537DULL, 0x661F706A9747347BULL, 0x83D3A4239EFF3419ULL, 0x1C0D45B631DCD05AULL, 
            0xECC6F01A06EE5C33ULL, 0x5D701BD90ED8C9AEULL, 0x00B4D440D313E91DULL, 0xB8A43EACB1EB9B60ULL, 
            0x9811FE5993F92FFFULL, 0x514D29980ED5EF20ULL, 0x2EB505A00110CE15ULL, 0x249837E6757D5BA1ULL, 
            0x32FC5FE904DE194BULL, 0xB3247A579D6D27A9ULL, 0xB68C9FE7C4F02EF2ULL, 0xDF1C24235D23EFA8ULL, 
            0x9ACFEFFA0F786E95ULL, 0x1CF9C92EB04EF837ULL, 0xFF3BEAEE8798085CULL, 0x9C930C17446B41EFULL, 
            0x132C5CFE98C564D5ULL, 0x4810A62C8871472BULL, 0xF30C3C2F40739EBAULL, 0x5A8196633C1B014EULL
        },
        {
            0x38E633B798EAC385ULL, 0x3001D96DA635EA73ULL, 0x3711767542C92EAAULL, 0xF093DEFF1ACF0493ULL, 
            0xBF1C6EBBE96C2830ULL, 0xB950B746CE20CEA0ULL, 0xB777589405878E93ULL, 0x613CD287FCF18C3BULL, 
            0x6BE7BA6B53F5F311ULL, 0xC3A7D192EFAF28ADULL, 0x52CAD4F1C8D375C9ULL, 0x70FFD836BC15A783ULL, 
            0x345B9B2A2B2C51C3ULL, 0xE3F4DE953E9BB207ULL, 0x504CD6C136AEEC68ULL, 0x94FE65AB7BB9D578ULL, 
            0xDF59E4717BED1238ULL, 0xFC3A35B32962B479ULL, 0xEE3952B91EA31620ULL, 0x54F702DEE2060297ULL, 
            0x7064B1F32352F554ULL, 0x3A3E08FDE5A6EB65ULL, 0x3BB9286AEE121F2FULL, 0x3646937B437432B6ULL, 
            0x43D17953E452169DULL, 0x274A4BA8777E298DULL, 0x359159217F4E355BULL, 0x95BF0EA6E61B7B6FULL, 
            0xCF6E3C1441B9CEABULL, 0x6FF63426FCBEDB4FULL, 0x99F549824D9FE30EULL, 0xA4B01D5D8A03EC7CULL
        },
        {
            0x00106D7E67BA3956ULL, 0xC0A16275E6489646ULL, 0x145F8A1C9FEBD8A0ULL, 0x388C6E1490675A64ULL, 
            0xA73ECA8CB0591F8BULL, 0xDF088BC3E4E5F179ULL, 0xCF7656DE73F64F38ULL, 0x709FE4148489E287ULL, 
            0x3DAB1C4BFB9C853EULL, 0xB9D17C5BF2A7F121ULL, 0xDF35B50A99C78FD8ULL, 0x091BAF7B46A2AAD5ULL, 
            0x533B17EA3DDBC208ULL, 0xB3D09607056FEC27ULL, 0xDEBDEEFFDAD57AB5ULL, 0x7CB9B45878464F7CULL, 
            0x2C4B81F94AFAEB8EULL, 0xD2972CF0B66B42F8ULL, 0x20869DD7BD775523ULL, 0x59E05A399C450065ULL, 
            0x48B02E8366D3432DULL, 0x00DE5BC513B28CF6ULL, 0xE971016B8D30A08FULL, 0x224CCF7DEDDF590CULL, 
            0x328B5B3A3920B361ULL, 0xE693CCE5C21EC051ULL, 0x8FF36D000B6C3E02ULL, 0x3607ED47DC82665AULL, 
            0x309978ADBE1E30DCULL, 0x5050C6BA5A66A58EULL, 0xC5480F97D45E4CBBULL, 0x5BD2FF0BE34FDD4BULL
        },
        {
            0x8B86C494272DF7DCULL, 0x271E00EBA7C1F1D8ULL, 0x8BC7183B3DFEEF67ULL, 0x349439903ED80D0CULL, 
            0xD1775DE490CA0867ULL, 0x695654F514665915ULL, 0x321787B4759C46D9ULL, 0x986F9B79F2ACE9F0ULL, 
            0xD3A740E670A3371DULL, 0xD6AC1A3890BC137BULL, 0x27E06894C94AE8C6ULL, 0xCA5E90ECEE00072FULL, 
            0x8F4067E9B6612E67ULL, 0xAB2616760DFEF86BULL, 0xFDF9601325833F7FULL, 0xB2110373C972F384ULL, 
            0x31A9ECBABF27F2E2ULL, 0x571D77A369A77F5CULL, 0x258335F4E01DB22CULL, 0xB7B16380810992CEULL, 
            0xBBB9EAD5FFC6B8C1ULL, 0xD2DFA40D69057A6CULL, 0x94AA1958F0CC1B66ULL, 0x39C6D4F1C5B22192ULL, 
            0x5E2A14F778E31905ULL, 0x5229A0428801901DULL, 0x4534525943E5AA76ULL, 0xBC30CA8272799C3CULL, 
            0x2C2794103370F7B0ULL, 0x8C33B0AA5CA63B26ULL, 0xF03213CD009B4540ULL, 0x8E805339597A3305ULL
        },
        {
            0xAFA53915A1065515ULL, 0x25E7A785E9FACC96ULL, 0x3D2D3D4A16DEB06FULL, 0x9F821710FD3C59B5ULL, 
            0xCA620C01F7DDC317ULL, 0x53E20DE425EB71B0ULL, 0x4E23FEE2DF275B5EULL, 0x2008F42FE9CAFC61ULL, 
            0x5E1AA52E66BCF739ULL, 0x54E659F470E8AE52ULL, 0x375BF333B6916A0FULL, 0x25EC85C12B256A1BULL, 
            0x7B7D7C3A92F1E9D3ULL, 0x7EE3B50C0CB072B6ULL, 0x78D96521B3BA0DCDULL, 0x3C5CB8397A0B14EDULL, 
            0x6F7E3F7E18F1E672ULL, 0x72AA052343A4A22EULL, 0x915901774DE475C2ULL, 0x9D6C61E259B86801ULL, 
            0xC87B3980E47C2B4AULL, 0x09F5284F61D93F68ULL, 0x3476555C31E336A8ULL, 0x1E93C0A24B6A847AULL, 
            0x97BE837CC42EA9ECULL, 0xEF93159EC02C73E5ULL, 0x3CDFC3D6146297F5ULL, 0xDF378C909FC4B460ULL, 
            0xE637BA2861545B30ULL, 0x368E9F9A27DAE7F1ULL, 0xEC9AFA98A58A41BFULL, 0xC211E20DE85D9D83ULL
        },
        {
            0x395FD514EDA43AD0ULL, 0x691C96EB2A8C2D43ULL, 0x2BB589D0BF265248ULL, 0xE38876984B470F47ULL, 
            0xB77E2BB4138F5A5BULL, 0xFEE4B7AAB0F48DC9ULL, 0x1C4DC7D3CBFF9B86ULL, 0x65D2C5A84C6B6EBFULL, 
            0x7A11036CC66A5DE2ULL, 0x32FCC5056A1998ECULL, 0x6840BE594A250C27ULL, 0x89EB43D7D4712119ULL, 
            0xA823CB6A314DFF53ULL, 0x4FAA5F93F812F8C0ULL, 0x4CC718E6CFE55815ULL, 0x4F0F07F0FFA9E35BULL, 
            0xA592278FE1C9DD1DULL, 0x7EC311B1574897C4ULL, 0x823DCA3C4EC96BDEULL, 0xC6DCC8772763EA85ULL, 
            0xA6E2B962261B5D47ULL, 0x37E4A4CD97C03A72ULL, 0x28F2B9F27E96B1C3ULL, 0x078A460F3219F992ULL, 
            0x8B90E3B4313A9ADDULL, 0x23260B9BC39B2D9CULL, 0x76223D7399320A9AULL, 0x074EF83345F357C4ULL, 
            0x882A625221D616D2ULL, 0x84EFCB53F0F365D2ULL, 0x76DBB05017DC9CACULL, 0x8B4ECC5DDD77F93BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseDConstants = {
    0x03CAE540D276F935ULL,
    0xD82CE78B6FED7EF0ULL,
    0x94BA5EBEF6DC254AULL,
    0x03CAE540D276F935ULL,
    0xD82CE78B6FED7EF0ULL,
    0x94BA5EBEF6DC254AULL,
    0x7FE2C80A7D364F65ULL,
    0xCEE63B53879139D5ULL,
    0x45,
    0xC1,
    0xB3,
    0xE5,
    0xF3,
    0xAC,
    0x0E,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseESalts = {
    {
        {
            0xE7C9D3A451B52090ULL, 0x3C31C5B0CFC948BEULL, 0x6C8A0D572C7FDB03ULL, 0x67176A60A4AA5C4CULL, 
            0xA582FAA8E7C557DEULL, 0x050B8E7BFDB8BD73ULL, 0xD903EE5FD41D85F8ULL, 0x6962C57FF98C1868ULL, 
            0x4ECAC347BF687057ULL, 0x779192676A43ECA5ULL, 0xE60A78F7FECD520DULL, 0x4F3D37F3793663F8ULL, 
            0x3686B4102B80396DULL, 0xAC05D1C1B6F94B62ULL, 0x3D95C29887669FE4ULL, 0x52E7A5A98B32CD99ULL, 
            0xF562DFCD73303CD1ULL, 0x958849E15B24F686ULL, 0xB25CE02B49477CDFULL, 0x248DA3D45281937CULL, 
            0xAAC441818F4E7285ULL, 0x71802E563F8DFC32ULL, 0x4B42BEF9D636BEB0ULL, 0x411221F669BDD280ULL, 
            0xDD99CD4600A1E111ULL, 0xED25FF96FFEED6C0ULL, 0xF2E134C74F4B2022ULL, 0xF37A46280FDC65A0ULL, 
            0x98D28DDEB4F728FFULL, 0xBCA5F0F91184D8A4ULL, 0x329562500BC0E593ULL, 0xA74DE4F2F3C81563ULL
        },
        {
            0xF3E8FC80A25B903BULL, 0x5610C593CFCE454AULL, 0x5BB5741442CCA499ULL, 0xE96B41D91AEF4A3BULL, 
            0xFD39D3584B8538A4ULL, 0xD1C281858FB3C40DULL, 0x9D504BD1B835E9D3ULL, 0xDF6461EECAC7386DULL, 
            0x130BE2F8A72B1995ULL, 0xBA09CE266B325238ULL, 0xC9ABCEFD7A351EF9ULL, 0x7043882E367E784AULL, 
            0x8838073846DD1EFCULL, 0x9DAF7EADE65540E2ULL, 0x9096F533AD914F88ULL, 0xF91B7FDE686EC903ULL, 
            0x7FED8E88F58C9DB4ULL, 0x5202EDA79AF08352ULL, 0xAD758C04073AF0E4ULL, 0x132B50BF48C3B683ULL, 
            0xAF023A4653566159ULL, 0x36AB78E11F6D5B4AULL, 0xE315046DAB51FAE3ULL, 0x6A743A0C95466F1AULL, 
            0x0B5B4C44B470B016ULL, 0x9293AF78CD424384ULL, 0xAC0FA2C70777A246ULL, 0xA4B01B3DAD192277ULL, 
            0x5FBE56D642B3F4A2ULL, 0xAF00E76FB48F909EULL, 0x97A8B9DF49901EFAULL, 0xF79F92726754854DULL
        },
        {
            0x85AD957487910A86ULL, 0x51A03DC4E402252FULL, 0xC81CDE1D390ADDA9ULL, 0x143072B9E4CCF383ULL, 
            0x32D93A1D9EC8CA4BULL, 0x5E777BA21BE8FAE1ULL, 0xAF11D7242485C3CBULL, 0xC619F3DFB8F68438ULL, 
            0x96555C02F8AFF3F3ULL, 0x681DF711C38F8A74ULL, 0x033A46E6D75EC3A9ULL, 0x9146AAD51F17A8ACULL, 
            0x3334384D42DDC0CEULL, 0x99B054445864B93CULL, 0x9E67CC9250D586DBULL, 0x8CAC43A96F4DBD54ULL, 
            0x758422F90EF6B88DULL, 0xBEB93C79BAF0CDC9ULL, 0x60144D8280A742E7ULL, 0xC9F511D7E33DAA71ULL, 
            0xC3D576E4B7D355E3ULL, 0x71B1D164A9D39D29ULL, 0xB20729D08E033123ULL, 0x55D0C49CB1BE4F4BULL, 
            0x2EFD8488E1417308ULL, 0x10F22656CF8AADA9ULL, 0x84A546E9D0BF34E9ULL, 0x12A1704111A8B62CULL, 
            0x455F6E5BD8C9BAD2ULL, 0xDEE85BB2AF4F9D4FULL, 0x41ECA528492D6B9AULL, 0xD1E5CBBF85DAF575ULL
        },
        {
            0x148561F0D8EF90B3ULL, 0x7461150BD86D6F8FULL, 0xB2282DA228B2B245ULL, 0x008D2B5B3D83525DULL, 
            0x628276647BC0B6BDULL, 0x031AF527EAF6CFFEULL, 0xA54331D6EF5AEC75ULL, 0x7E84B3E73C8F6253ULL, 
            0x8898C4281DE640B4ULL, 0xCFF8A3423FA4A39DULL, 0x44265C0DE45C0152ULL, 0x1D5BCA6B6C0B9A99ULL, 
            0xB33DE99BFC006E8FULL, 0x6D5A466B6C4FA033ULL, 0x9BF5F03F5C899EFAULL, 0xC455A20BC2AC8139ULL, 
            0xC9A339ED2B3B40AEULL, 0x3E1A6164D85CC2C8ULL, 0x21FA6613F20BA99DULL, 0x794F82D96A1A6C74ULL, 
            0x8FA60B544301EC42ULL, 0x77EEE23CA2941C73ULL, 0x0DAC05F958BFD377ULL, 0x07B7F8F98F44D861ULL, 
            0x8E5EFC4D135CFAD8ULL, 0xA2059A00C791C137ULL, 0x54759ABFF06CE1CBULL, 0x75DB72CC5355FC53ULL, 
            0x6CEE14D88704DD87ULL, 0xA18B8BBF496C546EULL, 0xCE22904EEB32A9ABULL, 0x5EE2896AD0E9CB76ULL
        },
        {
            0x80D94DE8627A0162ULL, 0x0728E98CC1B29CE2ULL, 0x9D2F59841EDAE142ULL, 0x5729920BC3580FFBULL, 
            0x4B8E72A52D91C518ULL, 0x84CA02D169B0F1E6ULL, 0x031E1AB1D7B516FBULL, 0xC1F59B0D649A7D0DULL, 
            0x24A8988425CB1DC9ULL, 0xB467DE1B41832588ULL, 0xBA62387EEA596921ULL, 0x4C2E742044FEBFD3ULL, 
            0x58106F74467B233EULL, 0xAF863220958CB252ULL, 0x563A8AF117DDAEB9ULL, 0x703CD8DD8266157DULL, 
            0xC04A00D8360A140FULL, 0x4283192FA9700E12ULL, 0x98A4147948B99606ULL, 0xDCB34406C4BDDCEFULL, 
            0xFB2AF3A1FCB2A95BULL, 0x4C39D0BA3EC04B4BULL, 0x3466026F084339C2ULL, 0x7192E870DE58C71EULL, 
            0x8592BA077406F9CFULL, 0x341C36447A728C5FULL, 0xF4422D6B487D289AULL, 0x4C58B90D37D48213ULL, 
            0x05C8A4AC5383705EULL, 0xABFFBAF5F3D2C493ULL, 0x54C5B295DBAB913AULL, 0x64165BE97024A1B5ULL
        },
        {
            0x18AE1DF7B476F8FEULL, 0xC2944FE6F1E282AAULL, 0xCDCA5916E00ED723ULL, 0x7FAF1108CEB5B4E1ULL, 
            0x9A9FE4E69B0ED990ULL, 0x1FA92C8782888070ULL, 0x4F4925F252C5806CULL, 0x7CD5E77213D97855ULL, 
            0x2DCDB7F11E080FEAULL, 0x256561856995FD0FULL, 0x40E5065138090271ULL, 0x274C43BDA9AEE64BULL, 
            0xBBF87794EE8DFEADULL, 0x63018645626AF873ULL, 0xC636C93CDE829348ULL, 0xB11A5F37B0C5E9CCULL, 
            0x5B6A8123CF073799ULL, 0x8380FACBDCC6DEECULL, 0x345FB5E95F2A98FDULL, 0x41010D77EB8A5502ULL, 
            0x316ED0424042CF94ULL, 0xF6F88D5F29DE605DULL, 0x25B33F78A7668C55ULL, 0x8FA56065FE4AB81EULL, 
            0x4B2C18B5797C575BULL, 0xEDBF3892A24FA3F3ULL, 0x0CF0621DE5CCC710ULL, 0x93DAE88FFEE1547BULL, 
            0x4D16FF25E8DD2514ULL, 0x89256DB021483207ULL, 0x57C746E805C7F434ULL, 0x575EB07FB081B838ULL
        }
    },
    {
        {
            0x125FDCBBF6980AD1ULL, 0x27E89ED97893F410ULL, 0xBD73FA926E829F03ULL, 0xFA684B2099F52A91ULL, 
            0xB17E5A2F9011921DULL, 0x5FE986AC1B10773CULL, 0xEDCC859A6C003D67ULL, 0x07F6CA2E2380FF9EULL, 
            0x27D29501026213F9ULL, 0x22B60DC8CC56CEC3ULL, 0xB14785335186EE03ULL, 0xEC205101FA2E3846ULL, 
            0xAFDEE3F7882475F7ULL, 0xDB211C4EDB3DBB89ULL, 0xFCC89403AFD45207ULL, 0xD219294235409282ULL, 
            0x674CA3CEDF320723ULL, 0xC1D60B6EE4AC265BULL, 0x25F737582B6E2025ULL, 0xF7211E59F3CDB82CULL, 
            0x5A45D1AE865141D7ULL, 0x6962CFF171AB63FDULL, 0x621FBCD50BB3F501ULL, 0x745BC2D91AC73F86ULL, 
            0xFA30D84B5F6BCACAULL, 0x5B66774E258EC9BEULL, 0x507AF80C4CDB1C7AULL, 0x49D24F5013823901ULL, 
            0x365409B23C10B84CULL, 0x1F48DE62CD754C38ULL, 0x84B88485CBCC70ECULL, 0x0CE77F5F1C949F87ULL
        },
        {
            0xC6064239555E9C23ULL, 0x3066F5D76353E814ULL, 0xE7F25FDD1F248197ULL, 0x70D15F9FF715AE6BULL, 
            0xC225DAD931B59252ULL, 0x3414512ECACFDA5BULL, 0x89B6A15AC4168E86ULL, 0x44584927FCF283C9ULL, 
            0x9B09BE01D486B759ULL, 0xB898C2044CB7B2F6ULL, 0x39F34279C267A9E0ULL, 0xA6571B4BD2021D13ULL, 
            0x87EAF97F0974EE09ULL, 0x293647F8071D6743ULL, 0xD961F57412A930F6ULL, 0x8C65782505A06455ULL, 
            0xDE4AE525C33F15C3ULL, 0x15C792362C53CDBEULL, 0xF10C45F57386FC83ULL, 0xD5A289B2D18E8CD3ULL, 
            0xBA8C3DE95B12E39FULL, 0xDE4F5FD4E7C5FFEDULL, 0xCBFA9048C51892DBULL, 0x21B42EA05C61B197ULL, 
            0x7879ECC150FC5B8BULL, 0xEBE994A553E81A19ULL, 0x3DA15C67938E02D4ULL, 0x77CD360BE884C584ULL, 
            0xF34326E5823CFFAAULL, 0x99AE737791EA3860ULL, 0xABE902F742AE2DB6ULL, 0x2445345AB4428C26ULL
        },
        {
            0x2A03CF94EFEE61B4ULL, 0xF56EAA161078F7F4ULL, 0x4F05419AC71ECFE2ULL, 0x45337384D020C484ULL, 
            0x14AA063380F56778ULL, 0xE456CA321D3AFBDBULL, 0xE3E0493382089D8EULL, 0x44064F2118AED9BEULL, 
            0x70A215C843C7A1E3ULL, 0x402065995046B928ULL, 0x190AC049D10ADA92ULL, 0xBEC18C8CB1DA41A4ULL, 
            0x361B3DAD59EE8003ULL, 0x37BF73A8240542CAULL, 0x50E4691D044ADCA0ULL, 0x390F2DDBE9B6A3C5ULL, 
            0x1BAADF4D3D2FD152ULL, 0x6256037CCFA1BF4FULL, 0x29DB8160D7B96078ULL, 0x6300D01F81BD2604ULL, 
            0x38901FD9256FFB03ULL, 0x5C9411D8597AC7DAULL, 0x10D0DB30080F8AEEULL, 0x41C77BBD2DB7F2EDULL, 
            0x24C89E4F6BDB8DB9ULL, 0xB03F48B835F77541ULL, 0x0C311188326381B9ULL, 0x5158BC0152C12B11ULL, 
            0x3DBD251F11D493FFULL, 0xB4BAE32BB283987FULL, 0x81EB0D08466882B1ULL, 0x6BF94F6A670702BDULL
        },
        {
            0xD2318898A1D6C945ULL, 0xB771F95B20E58684ULL, 0x0B06B26EA0262AC5ULL, 0x91B65C4A60586022ULL, 
            0x1CA69D544FA37330ULL, 0xEEC4ABF1D6B8553AULL, 0x6442299016567393ULL, 0xD2E039A3ED50575BULL, 
            0x5DB81FC275022A80ULL, 0x7755D2343AEA2AEEULL, 0x9F7DE2B2BFAC17E0ULL, 0x0EC59CFEF475F7EBULL, 
            0xA007B75F4907EF6CULL, 0x64D11ACC0DA05983ULL, 0xD5B940D489293235ULL, 0x389BE35B01172456ULL, 
            0x28D69EAF615FB954ULL, 0x3E12D7978F83B6D7ULL, 0xFFE96FDF6272ED07ULL, 0xAFDC647EFC28F2D0ULL, 
            0x818C8AE9B700D30FULL, 0xE1C296028C5917DBULL, 0x85B8DD441AA1184CULL, 0xA09BFD24F8CB7BF4ULL, 
            0x5B4BFCDF97854B30ULL, 0xE39EFC0B86DD7EC2ULL, 0x34EECA4C72B75897ULL, 0x157891FA3BF70300ULL, 
            0x693D9DA6E0F56904ULL, 0x4C5AB8AF39A2BC21ULL, 0xB371369C655F0729ULL, 0x8F0DFCF40C38F350ULL
        },
        {
            0xFD38F21A20D185ECULL, 0xC3749FF846391C51ULL, 0xBB2A660ECFBA34A5ULL, 0x7D339CD996B78498ULL, 
            0x2D225C4D9DAB95FDULL, 0x6EB637038326988DULL, 0x36BD5CDD99A53133ULL, 0x42FDE2FE55108A68ULL, 
            0x9B92ABACF450BCCDULL, 0x93072EDB73649AF3ULL, 0xAE52EC9094FAE46EULL, 0xAA0174E01AA45ACEULL, 
            0x267FE138DC79F7C9ULL, 0x0D512723FDA4FC84ULL, 0xBB0B0DDE6403BEAAULL, 0xFFE901AD46F3F533ULL, 
            0x8196A9181F970156ULL, 0x6D587C5B4C57FA01ULL, 0x6EF41A387B6606ECULL, 0x8FB15B82E7B43293ULL, 
            0xDAAB42254539ABD1ULL, 0x1B3ED860CFEADFDCULL, 0xC37DC0E803A20BD3ULL, 0x3C5292716C9FACB6ULL, 
            0x511DEB95B66E590BULL, 0x150A2E94D4316A1EULL, 0x622B12CB97B7DEFDULL, 0x4B98B538642B1BBFULL, 
            0x340CB8CE6A9E51F7ULL, 0x3AB52357C1B71F83ULL, 0x7EB48241A1D98E52ULL, 0x63EA1F0F7408B273ULL
        },
        {
            0x49D5BECD0580944DULL, 0x284FCC79A9BCBDD1ULL, 0xDE8E190CF3DEAC58ULL, 0x0CD71B7C2AE1C8B6ULL, 
            0xD22D730C6402EB1CULL, 0xFD07D8718F5588FBULL, 0xCE43B44769E0658BULL, 0x53B9AFFF327ACEB6ULL, 
            0x126090DD748256B8ULL, 0x1FEC5F417A13F960ULL, 0x9D9DEEE7A7A24F8DULL, 0xF16FD45CAA6BB940ULL, 
            0x3B552F5CB40EE7B8ULL, 0xB69353342DBAFDE0ULL, 0x89B5A5BDA4BF8659ULL, 0x166A247A54986DCFULL, 
            0xFF8878B1D8E06A32ULL, 0x841FF91F78166AE7ULL, 0x9C095520B6933887ULL, 0x0F428BA4DF0899E0ULL, 
            0x51578A0912BAE70CULL, 0x6A112FEE0834DE63ULL, 0xB8ABBA93D138CC57ULL, 0x2FA73441BFC1B716ULL, 
            0x9F90160832EDDBC6ULL, 0x7E8825B665035587ULL, 0x06755EA9D94A1BD4ULL, 0xD49BF31C08818865ULL, 
            0x6D98F8C82FEFCB8FULL, 0xCD7534F0F6CB70E0ULL, 0x9118B8F0220A1FC3ULL, 0x36F1193A16CDF0F6ULL
        }
    },
    {
        {
            0x1817732EE7AADAB5ULL, 0x174433242DB2BBCCULL, 0x1B8A04E19796F267ULL, 0xFC5A544B9E94D8BCULL, 
            0x0D3B6BFDAEC736E6ULL, 0x0C2052CE6E2BE212ULL, 0xC8A949CA518521D1ULL, 0x49FCD8983BF337EAULL, 
            0x7CCFEA50A09A62E0ULL, 0x3E7F012C0078112DULL, 0x9A2FEC3A8AB15D8DULL, 0xBDBDDF192009C55CULL, 
            0xD5DC86748042F3FFULL, 0x8AD7A247EDECEFCDULL, 0xFB453EA1EADCB1AEULL, 0x39E9DAE59706DAE7ULL, 
            0x60744C7746D491D6ULL, 0xDC419EE5FF0F745CULL, 0xF824FDECF6800338ULL, 0xB4EB6AB074864BCAULL, 
            0xAEA6F4BD855204E6ULL, 0xE85D8FC92F213AD9ULL, 0xCB0CD4C1B56831DCULL, 0x7448B2B9CAC697F4ULL, 
            0xD1398F7E8CD4B3E7ULL, 0x9DFB8FA2FA57684EULL, 0xE6D92E2B9A675D88ULL, 0x87A523B741C8E853ULL, 
            0xA00867F0D1C85196ULL, 0x479C1ED6490E68BCULL, 0xD35C88BBFC9E33D6ULL, 0x705F8E5373A8B84FULL
        },
        {
            0xB1ED5FD3A3EFE2FFULL, 0x5345D0D638D1E898ULL, 0xAEAB0EAEBB4544B8ULL, 0x5C782D2486B9965BULL, 
            0xBBB43244AFE7A235ULL, 0xFC3E1BD4EC0925D2ULL, 0x834162E7BD0DDD67ULL, 0xD36F98A24039AC01ULL, 
            0xDBF578D0A1ED3A77ULL, 0xAFF8821C67ECEAE5ULL, 0xEEC33045CB914FE0ULL, 0xCE4C29B7E2454C1EULL, 
            0xAA6BB5A55A2BF2FCULL, 0x1A46DD524C8D92CAULL, 0x167D8FA3C6C87FD9ULL, 0x6D05017A9545E236ULL, 
            0xD3887A43BF622C27ULL, 0x751BEC2DE26D0FADULL, 0xBFACFC8BACCA3853ULL, 0x2AADA35075E9DA94ULL, 
            0xA95D84680D1F6824ULL, 0xD64F529F9F0BCD01ULL, 0x0C1CCED91065DFF5ULL, 0x8DD5436467E2A265ULL, 
            0x3673AEBE4C48D96EULL, 0x973C4591A7795507ULL, 0xD80CB19D03F025C6ULL, 0x87E07C39F001FE2CULL, 
            0x7FE03DE973B7602BULL, 0x692F509C99B3C913ULL, 0x9E1BCE9254558A4BULL, 0x72AACA79748207ACULL
        },
        {
            0xC19B881741D49584ULL, 0x1C78466DBA6F156FULL, 0x14D4E82B89899CCBULL, 0x6E70E2E7CD6E7D84ULL, 
            0x3C0A73784393FFD9ULL, 0x073A99A94B147045ULL, 0xD6E6310E4D9DD46FULL, 0x3DF186110A8E3BD4ULL, 
            0x2D7E898D8B550D6DULL, 0xABA5556604DE482EULL, 0x58B8C1A1AAB15B67ULL, 0x7FF1999BE1008386ULL, 
            0x96304C1B19F28BBBULL, 0xC915388B6C879E80ULL, 0x3F911BB2E1D5F886ULL, 0x2964BEF3865001B5ULL, 
            0x6A6647958435F500ULL, 0x2A25183D88EF4620ULL, 0x6DB3D6D7301C9518ULL, 0xAAB03034CB38A416ULL, 
            0xABD0F13DB1423740ULL, 0xCF480C63F5A6512AULL, 0x12BCE10182B69FB5ULL, 0x6754C30638A564D1ULL, 
            0x7A1ADEF5CD433653ULL, 0x6D6A3806CA056E2DULL, 0x67B4EC2C45D3F8AAULL, 0x590824460AC8D0B4ULL, 
            0x1499F965321ABABFULL, 0xE78A56150F822358ULL, 0x63DDC3BBEB3C5A24ULL, 0x0678F8F9ECF1B907ULL
        },
        {
            0xB01FE057E08DD877ULL, 0x2810BD0E1620C2DBULL, 0xE4CCDA3CF4247DC1ULL, 0x192EAD9367AA84DDULL, 
            0x9EEDEA55CE50EAC3ULL, 0x94E89ABDD584013CULL, 0x9C3F5935475E6ADEULL, 0xD23A2B5CCC0D0072ULL, 
            0xD7CAC54C27B3AC66ULL, 0xC7FFF0D0F7E8AFC3ULL, 0xC57D18334E373561ULL, 0x0139F0F3FEDF7027ULL, 
            0x55723736B301EA56ULL, 0x094DFBBEC7C3488CULL, 0x124785BA6F49D627ULL, 0xEC07C02E12680186ULL, 
            0xADCFC183A48FE623ULL, 0x01FCABE7C6718BAFULL, 0x9B9628465F730475ULL, 0x62EE27D5CB984797ULL, 
            0xB478C01AD97FDEFFULL, 0x9173F0A1CBF6BB01ULL, 0x37398CD2BA2B3815ULL, 0x1763D8C75D293367ULL, 
            0x486E508ADE6B1913ULL, 0xB2E41D98F76F1D0DULL, 0xC5D048E3DDCEB538ULL, 0x30AC4CDDCFFC83F9ULL, 
            0x1D561287B992FEE3ULL, 0x5BBBB18A736626C2ULL, 0x1C99A0785E8138B5ULL, 0x82507559F3C17797ULL
        },
        {
            0x1F6BCFCAE26E3F41ULL, 0xA878513353A6EA1AULL, 0xC85968E646579AE4ULL, 0x800E719EF7D2757EULL, 
            0x5CF7B13CF6D67FDFULL, 0x0DBE282EB16F7F2FULL, 0x1C36077BA4AA203EULL, 0xAF95E0A9CEF623A9ULL, 
            0x7979E5E2F010A4F9ULL, 0x58571A71441634CAULL, 0xEB050A6A37080AA1ULL, 0xBD8FC8A4E4C55247ULL, 
            0xFE8641077A921539ULL, 0x9824E53AB779FBFCULL, 0x25461F15226B7D05ULL, 0x32E726C7FE9A45B8ULL, 
            0xD70A16134DF6FB75ULL, 0x4A24BC02133F20A2ULL, 0x71C7DB967492AA46ULL, 0x9EB6E927C02D6571ULL, 
            0x3EA8A7B43D533470ULL, 0x0BBB79FB338C788DULL, 0x3C80BFD225725EC3ULL, 0xA72F8A7968DF5839ULL, 
            0xDE68624B835E0E1BULL, 0x257C722FFDBB69A3ULL, 0xF1D7A301CFFD8FE3ULL, 0x80E9BB19A1BAA17CULL, 
            0x3D844CF43C66C741ULL, 0x027F4FCFEA55B947ULL, 0xAABDDD44A7A65C2EULL, 0xC669649811E2B7A2ULL
        },
        {
            0x05893C3296F62FD4ULL, 0x9FBC6900E3B44744ULL, 0x2836D8781EB6DAE7ULL, 0xE7333A6A383FBAAAULL, 
            0xFF69332428FA7D42ULL, 0x2BF0F1F40104EC47ULL, 0x48C41AA3316B29BFULL, 0x3BA4540346F4739EULL, 
            0x45F0D0C309FD18F6ULL, 0x3B771534C3F412F6ULL, 0xDDF77C48900C7DC3ULL, 0xABA880AE0EB4BD32ULL, 
            0xB3959C20130B8E14ULL, 0xBBED003757E71332ULL, 0x624DE0FE36796B5EULL, 0xB8E70FEF2294CC14ULL, 
            0x6DAD49146EB6F148ULL, 0xCD7D5053F4219DD0ULL, 0x4C08875BE5D3756BULL, 0x72BD9BF2BD8DD6D7ULL, 
            0xB5BE0ECCD79621F8ULL, 0x5DDF8A630E1049B4ULL, 0x9C8396DF799DB022ULL, 0x9A9A57E38FECB8DAULL, 
            0xBE71656D56B77BF5ULL, 0x5FA7C97D4CDD8B6EULL, 0x1CF2856295510D07ULL, 0x1FF8F7554FC61DF7ULL, 
            0x6AA7FB657B301C33ULL, 0xF4867C33472D4237ULL, 0xBDCC91A8673F98B1ULL, 0x335CDF19652C058FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseEConstants = {
    0x5652D5A23D46B1AFULL,
    0x2778C63534AF51C3ULL,
    0xF99F2F68458F819FULL,
    0x5652D5A23D46B1AFULL,
    0x2778C63534AF51C3ULL,
    0xF99F2F68458F819FULL,
    0x59C70438F0850547ULL,
    0x0556CDEA1C05A6ACULL,
    0x8C,
    0xE0,
    0xF6,
    0x6F,
    0xE2,
    0x65,
    0xEC,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseFSalts = {
    {
        {
            0x91EF2B31F9B2CA88ULL, 0x39B5E1ABFF0616E5ULL, 0xF306BBDCE8758955ULL, 0xC90123F142905FEEULL, 
            0x8E4B810083A51460ULL, 0x45A05EC956AEFE72ULL, 0xA4444B64B0869471ULL, 0xC72093CFCF2C6B21ULL, 
            0xAFB094C8965CB69AULL, 0xEBE73C6859BF32AAULL, 0xCF1B15D3E92DC7D0ULL, 0x1F4E54448E21FB75ULL, 
            0xAC30D33F4A6C430BULL, 0x1AFB165F24F84E21ULL, 0x37A392186A021A20ULL, 0xD0FA2B67295C067FULL, 
            0x97620CBF061951FBULL, 0xFCEA4AB9569AEB5BULL, 0x392B56DBA0859F51ULL, 0xFB40774F1BF64AF7ULL, 
            0x4C486FDC2834F185ULL, 0x48FEAA6A04CBA03DULL, 0x127ECE509839280CULL, 0xC82A73B8B70A93E5ULL, 
            0x42A137726541A241ULL, 0x82A17A63AC1C952DULL, 0x63C57BA254E6CD45ULL, 0xD3760204A8E3222BULL, 
            0x1586150A574C266EULL, 0x01D56374B33C6A23ULL, 0x4455CD0725DBF898ULL, 0x8613760E54451419ULL
        },
        {
            0x34D01D7BE8A7AE08ULL, 0x92BCCB7DECE62292ULL, 0x2A59F9BB29858D00ULL, 0x4F453BB6AD7284D9ULL, 
            0x9066C23D2E936953ULL, 0x35A0AE705A662B4BULL, 0xDDF866EAAC436204ULL, 0x4AA1DD69CE0F2731ULL, 
            0x58A91144C05E5393ULL, 0x750FCA6E58EE34F4ULL, 0x01B4427E36BC2C25ULL, 0x6B0CFBFC00E45720ULL, 
            0xF32F8580FE8762C6ULL, 0xFCE580724D1B40D7ULL, 0x287398A5F4EFB7C4ULL, 0x3FC3F5A107D3ADF5ULL, 
            0x072BBB3A1FFD07F3ULL, 0x349050BA87C913BCULL, 0xE170859DB13865FAULL, 0x49FE3733EB985EC4ULL, 
            0x24A71C2188112363ULL, 0x7D8D475864F93EFAULL, 0x2D61F051F5792C22ULL, 0x0699D5F953733A92ULL, 
            0x47004378D2F85A26ULL, 0xA92DB84637881ECAULL, 0xB3ABE2E3B79BA79FULL, 0xFEE05FA10A7E6B2BULL, 
            0x8E18D39EB61546DFULL, 0x832E32CE331F16DEULL, 0x837B5C2A7E218C31ULL, 0x603A5A814211F96AULL
        },
        {
            0xCD0232F9534FED0FULL, 0x21BDBCDE3645EA0CULL, 0x00F819AE3BDA2E47ULL, 0x1E06B980BBD92244ULL, 
            0x499C323EC158DC3AULL, 0xAC6B30AC6D1810A3ULL, 0x1BFA099C01D11ADDULL, 0x49AC633A7771CF90ULL, 
            0x088355B76596F371ULL, 0xDE6714E16DC1959AULL, 0xE4167F7FDC992999ULL, 0x89C80DD5E911C9BEULL, 
            0x39A3BB522F5A152FULL, 0xDAEBA4FE5746958FULL, 0x9D6AE1E8A565036AULL, 0x831938F2B01083CEULL, 
            0x96684C041CA02C24ULL, 0x65C179D06B9545E9ULL, 0x4E488C5A7FFF0E24ULL, 0x8FDE52984DB166DAULL, 
            0xF674C2E17A0A5131ULL, 0x0FD590288E33F2AFULL, 0xEFB25990864D0E51ULL, 0x3BDA80D0E2792AC8ULL, 
            0x69946FBAFD4E856BULL, 0xC5578013E480F36CULL, 0x59CE4B1633442318ULL, 0xACA8C401D4D141DCULL, 
            0x07024CCE77AB3F7FULL, 0x7246024C1E4F0927ULL, 0x91C7C8109A6B3674ULL, 0x3D0D0E9AABBFAE5BULL
        },
        {
            0xDF4F9EF8D703A119ULL, 0xB4EA19F41664D65BULL, 0x7735F65BA6855A74ULL, 0x7A6520C164AE311CULL, 
            0xCBDDE2B99C8644B8ULL, 0x77A271AF43CD0DFBULL, 0xBA006573F72B40B6ULL, 0x952888CB15FA68E1ULL, 
            0x75F368CE4864E8AFULL, 0x588197E3F9754A47ULL, 0x96A534F3E4E65AE9ULL, 0xF3D9F3172E5D13D6ULL, 
            0xE2E95E9D14A71CCDULL, 0x2890029C8F023ECFULL, 0x7B536800A116F870ULL, 0x9DEB4F47ED4A59F3ULL, 
            0x15D145EF3B31FB9FULL, 0x8D389832F17A65FFULL, 0x281E3A1F0A35C536ULL, 0xAEE46090B6F1A97AULL, 
            0xE0005E5588F40D80ULL, 0x26326344FD0636C4ULL, 0x6A4A4538AA9498B3ULL, 0xF125D1EC3644524DULL, 
            0x02B39C70376373DAULL, 0x6D001281688A3116ULL, 0xB69569438E9C8515ULL, 0xEB067BE4EE0BE8F1ULL, 
            0x21B2C64E39E2BBD0ULL, 0x3D23C28FBB8A1582ULL, 0xB7A76AD68D5BFF4CULL, 0xEFC9CEA0EF3B3A8CULL
        },
        {
            0xFD46C92295B0C2A2ULL, 0xA7411509A62669D0ULL, 0xA039560DD0826047ULL, 0xFCA7F2D05A24B2D5ULL, 
            0xF7296C6F7EA119F3ULL, 0x0DDBF15ABE3D900FULL, 0xFDC2C44DE15D5112ULL, 0x58D0C29FDD299283ULL, 
            0x0C76DA3050F168ACULL, 0x6C045FDE1C6A4EE8ULL, 0x889C4A3388101EE9ULL, 0x6B7F3286CBF612F6ULL, 
            0x4BF4FCFA7425A790ULL, 0x9C5EF1772B8E0E27ULL, 0xC4F9DC3913F2C5CEULL, 0x50F889E729869808ULL, 
            0x9BDDE53FADE5B038ULL, 0x287B65AE9B8D1C96ULL, 0xA364D4C35EE7C135ULL, 0x3A660FE026F1EECEULL, 
            0x35EA6A43AA64A4AAULL, 0x1FC28BC059C1897CULL, 0x56BE5DDE47751737ULL, 0x93D7D4640C5D17CAULL, 
            0x685BFFD66DC7AAAEULL, 0xBC2FED0F428526FCULL, 0x76E2CC0D5BC3D585ULL, 0xC5A49DE1F64B044BULL, 
            0x12F93B6C3E246DC6ULL, 0x7D33C5DBBE5FA5FAULL, 0x8FA7E930D083F12CULL, 0x945D8721CED5F227ULL
        },
        {
            0xA7197ABB2A75D471ULL, 0xCAED1B86EA78F54EULL, 0xE4F1DE2C352C1E99ULL, 0x1EC60310501A240CULL, 
            0x01F53E76A9F08F83ULL, 0xF71B58CE14E2C8D7ULL, 0x52268E0CD3B9DE00ULL, 0xCDA41D95A9D41787ULL, 
            0x04652931967DA09FULL, 0x10D9263879DACB92ULL, 0x11906544FF4C2776ULL, 0xE0E3B4414634EC12ULL, 
            0x06B34821D24B80D9ULL, 0xA74E0C67591BB5CAULL, 0xA3E92423640B5E9FULL, 0x665716F9E20FB937ULL, 
            0xE5A728525BB4810BULL, 0x69272546CC5FD698ULL, 0xB256C6E80C5AC8FBULL, 0x06A922B03E545439ULL, 
            0xF8430CBB114ADC84ULL, 0x134FCCE98CBB61BBULL, 0xBCD8CE41E0427419ULL, 0x44D1CFAE213608EAULL, 
            0xF7E4E2AA861F61C6ULL, 0x3E31C40687B1B7A8ULL, 0xB3720CA7832EF22AULL, 0xBCEC2E683811B589ULL, 
            0xE4692348F4DC5941ULL, 0x0E8E97EF2149CF2EULL, 0xC51D2A86685E1ECAULL, 0xC839658BA2AFBF4AULL
        }
    },
    {
        {
            0x653B70DB4E4770EAULL, 0xF1724F65E135B146ULL, 0xA3E2B49E1BA5A136ULL, 0x0F9D436C4BBA2D8FULL, 
            0x79B52B47A407851EULL, 0x9ED52591B3671DD2ULL, 0x36BECC8ABE3194A4ULL, 0x315A04979304F1D5ULL, 
            0x782DA63540B69501ULL, 0x93C412E56D9480FAULL, 0x334502ADBD7002BDULL, 0xE84CF2FE52D69737ULL, 
            0xF65458C322263766ULL, 0xC38EBFABECD59445ULL, 0xF313E95925A1B07DULL, 0x40814190853505D2ULL, 
            0xCA737BF64FE8577AULL, 0xC6BF1722955D8A31ULL, 0x0B2AE5BED571F917ULL, 0xB2260409B806AD17ULL, 
            0x7EB2C2A3042B17F7ULL, 0x38712649C8D54725ULL, 0x1979555FD93EAB83ULL, 0x707E14C44B124613ULL, 
            0xE5E25489A89DD3D4ULL, 0x7E6440A32EE5B752ULL, 0x6CE76FFC6FDB1EBEULL, 0x35852DCF582290EEULL, 
            0x5DD49057E87DF54DULL, 0xFBBDCF0C0B2FCCACULL, 0x315DE1BAA7AB20CDULL, 0xF91A4BDF7032EB7FULL
        },
        {
            0x310CE380603E1731ULL, 0x3ADC44EA44035A08ULL, 0x87D7D35C209F8F66ULL, 0xB166166708EDBA3AULL, 
            0xFD6E4E91F8FF85FEULL, 0x05AA2086ED3A12C1ULL, 0x7947065BED011535ULL, 0xD0DD5F85B19085F9ULL, 
            0x680F87E74EF88BC5ULL, 0x4B47EFB79889321AULL, 0x27A46E3A9D6D8F2EULL, 0xD863E6188D0CD93DULL, 
            0x2ADF8AE9C2387B22ULL, 0x65788BA20A349941ULL, 0x98B4FFCFB15861FCULL, 0x487EB10E61C66584ULL, 
            0x48B9E796DAC6127BULL, 0x7BCA9A33A439AA80ULL, 0x90B01E5B4A306E51ULL, 0x3F3582D21B6466DFULL, 
            0x2B8FF204EB48D468ULL, 0x1C041EC707A8D162ULL, 0x4CEB9B451EC414D8ULL, 0x21336EFB999AF729ULL, 
            0xD1F62B9D2BC18304ULL, 0x940B965FFFF2446BULL, 0xD61856DE1894B3B9ULL, 0x16AA697511B91D6BULL, 
            0x22D2FAAD8347EF1CULL, 0x07D42AF6474F8DC6ULL, 0x0D8B97FF5B68F593ULL, 0x277190CC212D148EULL
        },
        {
            0x51FD1E1F14185D67ULL, 0xED2C391BDDA068B6ULL, 0xC6013A06FA5AFF3FULL, 0xD2ADE052583D60FBULL, 
            0xC0A9D8AF76B974FFULL, 0x8F6D7F4E06366615ULL, 0x38040DEEDA1B667BULL, 0xBAE8E1BA62391178ULL, 
            0xA366B836A580BA6CULL, 0x68CBA27080972530ULL, 0x5F8F267E382DABF7ULL, 0x89BF8D17FC853DF8ULL, 
            0x773EB4D6A2481A83ULL, 0xF20B530827D20FAFULL, 0x0589E2513723DD11ULL, 0xED9CA1EB7825F86BULL, 
            0x3AEB2BCAD74899B8ULL, 0x501FE1ACB4D73546ULL, 0x8E0C476284D68ED6ULL, 0x892885B8EC9E4463ULL, 
            0x0E725B1A98004E7EULL, 0x34EE2BB215B25B80ULL, 0x604717CF9668B637ULL, 0xA2F16B39FD296E37ULL, 
            0x24E5AB0F3372F73DULL, 0xAFFD686FBB4BA810ULL, 0x3EAE010B5C5FDBDCULL, 0x737DBB7ADDCADF17ULL, 
            0xEAE80117138738B0ULL, 0x428BF5B9211725CFULL, 0x342F3114678AA6E7ULL, 0x0B1315D500674267ULL
        },
        {
            0xD9E96DE34C13D8DCULL, 0x60E253C2E6CE680FULL, 0xD64E8C53B94062E3ULL, 0x3A4B8C3E9C261950ULL, 
            0x70055454FD67E2DAULL, 0x94BCB7029548AA3BULL, 0xC64D96D591298A47ULL, 0xEA48E30B010E71AAULL, 
            0xA7D61B04C79FDAFFULL, 0xCA48AFCB71433177ULL, 0x8F7C4ABA3397BB7AULL, 0x3FABC827CE747F8BULL, 
            0xDBCD4D52A6596A26ULL, 0xD463B370CC1BDC32ULL, 0xFE19D146400F3B56ULL, 0x467791224CBF3953ULL, 
            0x2D77586987ADFE58ULL, 0xAE2AABD496EB3D43ULL, 0x26AE4674D85FC1A6ULL, 0xD2CC23C606BBE0CAULL, 
            0x41CCBC21670053EFULL, 0xC57BF94BDB2E9677ULL, 0xCAC38157B6F03160ULL, 0x514A40F859688B08ULL, 
            0x9BC9781ABC5CB22CULL, 0xA7DE64729A43DAE4ULL, 0x09F34B39CF02C165ULL, 0xB8D34C72292CEFF8ULL, 
            0xAB14CFDEB1D43BA1ULL, 0xAD0B243BA934E14FULL, 0xC5F4D36F5F6B7A75ULL, 0xD59ECC96A54694E8ULL
        },
        {
            0x1A916F4F5EBCF2D6ULL, 0xC403AB040B26797EULL, 0xCE55F0E258463BE8ULL, 0x53F801216E900D1DULL, 
            0x38045EC4A73920F0ULL, 0x2B5F12B1EE117428ULL, 0x1950C8161019450EULL, 0x6AA247471222D467ULL, 
            0xC623530123DB3789ULL, 0x5AF1E97685C46F17ULL, 0x7A49056E01022795ULL, 0x511DADC4877F22AAULL, 
            0x419685755BE70157ULL, 0x129989929763B6B9ULL, 0xE5422D7F8B0F718FULL, 0xD4E75B40070EB926ULL, 
            0x58ACDF396B0C3C75ULL, 0x9A9D125119418FDFULL, 0x389F33CD80712E9FULL, 0x3957566B847CD837ULL, 
            0xB7B1606528BD087AULL, 0x46C1576F54EA9750ULL, 0xC1D9F94F73E986E2ULL, 0x7DEDFC236C84FCD9ULL, 
            0x3F40208314AC7DA9ULL, 0x30DFACFCE6EAA1E9ULL, 0xEA0473729420DDA8ULL, 0xCF7E379C17D6D30AULL, 
            0x4BDBDC5361045A80ULL, 0xF69AA703409E4D22ULL, 0x1E99D14A132B7049ULL, 0x46FD2D5DDD591E61ULL
        },
        {
            0xEB96ADFCB45E48DAULL, 0x86550F046EB07870ULL, 0x85AAF6627AA50C6CULL, 0x1EFE5788D7E553DAULL, 
            0xC7915CB1AD8C1DE0ULL, 0x45AD8A4D431D3DB6ULL, 0xC8430F2917818C2BULL, 0x4D3CCC10E32103D5ULL, 
            0xC8DDA6AC173846EDULL, 0xB5F50A9FF786D423ULL, 0xB75DF96A116FE6ADULL, 0x76F8CFB87CE759A8ULL, 
            0xAB5C971D616A3C1CULL, 0xB15698D2A7E6997CULL, 0xEF715F89D9E08CA1ULL, 0xB1085B3C01856427ULL, 
            0xC666C1EDF5EE1B0EULL, 0xBA2C028D0A6D9CAAULL, 0x2F7CB255FC63606DULL, 0x3E72C93E984DABB6ULL, 
            0xC5813A7B0E4710A4ULL, 0xE06497AB11C3D564ULL, 0x3A94B42471295AC0ULL, 0x24550F62E650D8EAULL, 
            0xE0DA633B9B5F5741ULL, 0x2CE0ABDFBE73DBA9ULL, 0x9E4229AD937A261AULL, 0xD67D2BC3F7A53C31ULL, 
            0xA5AC8C760E7F852EULL, 0xC126983FF8B074F2ULL, 0x8E195338E73C0202ULL, 0x09FFE4B24AB4DE95ULL
        }
    },
    {
        {
            0xC21601F127AF6D5DULL, 0x8ED1535C8A55902EULL, 0xA316F41BC80846CCULL, 0x8550D679BA2B42E8ULL, 
            0x7D486C93386B66E7ULL, 0xFA26FA398B5D0697ULL, 0x61798EFF6AC8D1B4ULL, 0x3A884EC9E6DF9530ULL, 
            0x5B6575154E37E6F7ULL, 0x6CBEC7FFDBC75771ULL, 0x5A956C23417F15BEULL, 0x51B0FB9FAC50EFB0ULL, 
            0x30597F537E3D09F6ULL, 0xBFDB52EEC1A1DEB1ULL, 0xB8C7A529C8512DE0ULL, 0x9883FEE7D3A1D0A7ULL, 
            0x959372063FA79854ULL, 0xC0AED2F980E70BACULL, 0x4B5DF507CA4FD69EULL, 0x3D94FB57558EFD53ULL, 
            0x92A47FF511EFABB6ULL, 0xADD72BDD03387C5BULL, 0x8F754AC02E47A2AEULL, 0x208B19723D9C3553ULL, 
            0x15454E458790A9DBULL, 0x5EBEA6126C728DF8ULL, 0xEE56C1BD683B233EULL, 0x0771C76F27D72501ULL, 
            0x0598B80B629DE913ULL, 0x206520BB73EE3C55ULL, 0x1ADEE9BBADCF59E5ULL, 0x521C6B7E9AEE3F43ULL
        },
        {
            0x01A05B63515CD4D3ULL, 0xBEC80FECB1C5F46BULL, 0x14606B1E9CA6DA2DULL, 0xC81707515CDB97C9ULL, 
            0x77319174203CF3D1ULL, 0x22955A20E2E5CA88ULL, 0x3D61AD0EB1E5F193ULL, 0x120FD95DDA573CFBULL, 
            0xFF6D45FBB6B92A99ULL, 0xF8FB56317B0DA7E3ULL, 0xD7E74874A2C37376ULL, 0x752247D833162FC6ULL, 
            0x49A1D627A7858AD1ULL, 0x8E8445F04F3CC341ULL, 0x283BE0EA103CF509ULL, 0x3C6675842E7D9C17ULL, 
            0x29961B84BCF89A3FULL, 0x5CEA941162D1F067ULL, 0xFBED6559445771E3ULL, 0x7842F1501FEE5D42ULL, 
            0xEEBED41CD6904A44ULL, 0x70470D0CE9DCB902ULL, 0x9C418C48C3FB32C0ULL, 0x3F04361CB28143BCULL, 
            0x4B94D404C75027F9ULL, 0x80F335D0D4CFA5C4ULL, 0x9B250B91CE4B9A21ULL, 0x112C4688AE35D2E8ULL, 
            0xD64F6BB7106B6E72ULL, 0x21E66D19C698FA8EULL, 0x1A79849B4EDCD395ULL, 0xB0C8AC9841718948ULL
        },
        {
            0xCB7016051B8B0223ULL, 0xEC2F63C0D5066398ULL, 0xC6A9EACF9DB5264AULL, 0x665F1D01022DFBB9ULL, 
            0xC9A465EDA65141F0ULL, 0x02D38396C75D77C2ULL, 0xF0716AFAAE40D3CDULL, 0xDF7DE5CF8F8EBF22ULL, 
            0xBB5D450E5053A9D3ULL, 0x2D4C7F5130788B18ULL, 0xC2E88EF3428FEF85ULL, 0xE7D85E869B90D428ULL, 
            0xF3DC3A573853C04CULL, 0x4A088881CE8840B8ULL, 0xAFCC38709D26D5F7ULL, 0x846498672CF450DBULL, 
            0x55444A2DFA244865ULL, 0x60B4BDB4661326E8ULL, 0x104DB4927F3B7923ULL, 0x3D597200ED270F6BULL, 
            0x1A7F8AC88481F78CULL, 0x42FF84551EB7C0A0ULL, 0x3BF9577D89CFA8C7ULL, 0x83BF0046D97DA341ULL, 
            0x64645D77389C1F00ULL, 0xB3D2895D0074E37DULL, 0xE3EA945562BD2D7DULL, 0xE2E5657EA193C662ULL, 
            0xFFAB4BEB6EC96F8BULL, 0x14C7240219271559ULL, 0xE76A42B4D609DE77ULL, 0xF1CBC853E1E12A5FULL
        },
        {
            0x6EAECA301FA4852CULL, 0x4E065B543FB566C3ULL, 0x08F9EFE132AD4C6CULL, 0x3A50A9688970F53EULL, 
            0x554BFB2E39250C3CULL, 0xD994209F0E72F2BFULL, 0x085BC6D70D9AA85EULL, 0xA121144A953A8951ULL, 
            0xFD1A5D98BBD339B9ULL, 0x67934B11AA6C70CCULL, 0x27BA8F4608C51799ULL, 0x5BB32384386BB844ULL, 
            0x11C7C398759E3729ULL, 0xB600A4D4C75C3591ULL, 0xB2699B39AD19DD00ULL, 0x2ABE66A24DFBFBB6ULL, 
            0x0832C1D700985850ULL, 0x6AE04584E225541CULL, 0x3B73EEE786A87FB7ULL, 0x4547C78AFC70804EULL, 
            0xF6D5682E6F5C6045ULL, 0x9D9D32B45D58693DULL, 0x5EBF5E0470F61594ULL, 0xE0E098FA6AED052AULL, 
            0x9D82D097C548A8CAULL, 0x3BE01358139EBFECULL, 0x643244F524C95AA1ULL, 0x5D9FFAC8A524F523ULL, 
            0xF97D99F384396556ULL, 0x5CF52F0B72B18C8EULL, 0xC3BD8CF893DBAB3AULL, 0xCED882269D5B40D7ULL
        },
        {
            0xE80801243D2D8274ULL, 0x005073091C4F2D9EULL, 0x5A127A2A965EFAB6ULL, 0x03A9281E13E1A3D1ULL, 
            0x8BD76559E2DBFC5CULL, 0xC48D38A195547F61ULL, 0xF19E01CE9A15037FULL, 0xC5DBDC858561D927ULL, 
            0x8841D00F72DF7EAAULL, 0x6FB504BF0154ECF5ULL, 0x44DB758AC7BE5037ULL, 0x332A6F2E9496BC97ULL, 
            0x37E44674257795CFULL, 0x878A2D1C94D5B9BFULL, 0x4D8B913958F69927ULL, 0xF73D10C72A0594E4ULL, 
            0xE03F73B119197C7FULL, 0x163FDEC805332D7CULL, 0x0F860B80DB5BF4F0ULL, 0x73728E85B4B6C180ULL, 
            0x0C2806058252DCACULL, 0xF53F3C509AB33790ULL, 0x467253493F258724ULL, 0x80D8EDCFACF6945AULL, 
            0x3B85135DDAA5D480ULL, 0x1966FB8E334E63C7ULL, 0x8ED61A486B1F71B5ULL, 0x5B0F6D80A09FEDEAULL, 
            0x36F4406F676445A5ULL, 0x3F85E4E76573F00BULL, 0xE058060840753A6FULL, 0x71C900ACE76BE69AULL
        },
        {
            0xE30C6AAB54D55B1AULL, 0x9485868E7FFC8E6CULL, 0x6C153710DF384F97ULL, 0xC81DB37A3041B461ULL, 
            0xC8D176E070ABC527ULL, 0xCD6BCB7B05080E88ULL, 0x7BA1538980392FBFULL, 0x66CE680A09562F85ULL, 
            0xBAA123EFD5BD1F7DULL, 0x55A7CF3F7C67A4EDULL, 0xCC0A4F9C7A670674ULL, 0x7F0EC72447C6EAD3ULL, 
            0x65CB1A3200BCDD97ULL, 0xE546F490345F6F4FULL, 0xD6A9E2324E876DF0ULL, 0x38E53686B614DF56ULL, 
            0x16922FFABEF11C48ULL, 0x92D88583F651F815ULL, 0xBB36D1034CDC269AULL, 0x465189DA8BAE0C85ULL, 
            0x7F0C7CB4D2DF4645ULL, 0xE5C5A3F85EDCCC12ULL, 0xB6850A874EE7AE86ULL, 0xF13735C5C30CCD07ULL, 
            0x3E1EECD096D0A117ULL, 0x0AAB6DD68A6C532AULL, 0x4AC13286215A0AF6ULL, 0xA2C6D243767B1AC5ULL, 
            0xDE9511A65F6DA291ULL, 0x97E5D1701033B907ULL, 0xD67EBF712397BA57ULL, 0xC78465C0A474B066ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseFConstants = {
    0xEC7241EDC0868258ULL,
    0x2BFA15FEC134D3C6ULL,
    0x98CAB45942596741ULL,
    0xEC7241EDC0868258ULL,
    0x2BFA15FEC134D3C6ULL,
    0x98CAB45942596741ULL,
    0x179879D4260C75EBULL,
    0x70DDA658B0E1B6E9ULL,
    0x65,
    0xC2,
    0xAE,
    0x22,
    0xC0,
    0x10,
    0xDC,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseGSalts = {
    {
        {
            0x9F6F166DFDB9094FULL, 0x265E3ABA432277FCULL, 0xC63AF497F14FF814ULL, 0x8935E2FC6EA5620DULL, 
            0x889A21E092138122ULL, 0xFF6E41369AF2B421ULL, 0x3C5ADC3BE2C447C7ULL, 0xB76F44FF779B755CULL, 
            0x2BC6DB5E10AC5C76ULL, 0xF033B12A6A1303CFULL, 0x094C80703CA23BE4ULL, 0xC8975558EAFB8BAFULL, 
            0xCBA4A7057C6158C4ULL, 0x9101D31CFB47F103ULL, 0xFC3E9529CBEBB4B5ULL, 0x1C1455CB143B6033ULL, 
            0xF8797EEFDA6639B5ULL, 0x76D43815A2EC346FULL, 0x9FEB8CD95D270FEDULL, 0xB236044B17B90F3EULL, 
            0xAEFB9DC8BB4D5136ULL, 0x4B94D5329D05EF91ULL, 0x78D749A9FF4CDE82ULL, 0xD68B24DEC9BB08D0ULL, 
            0xCF08B447548EF627ULL, 0xA2A9C0CF68F7CEF9ULL, 0x6BB0570C9FE6C663ULL, 0xC3A0E4A1CFD22ED1ULL, 
            0xF5340FCBF14D889BULL, 0x35FC1B2CA39D14A1ULL, 0x153612B96CE1A2F3ULL, 0x5CCE73ABAE5E634BULL
        },
        {
            0xC1D2DDA87CCFBC44ULL, 0x151D7A5E3BE079F5ULL, 0x7B526AC6F58EA1DDULL, 0xCBBC0D8A6F42DB20ULL, 
            0x704AFFD9CDAEB141ULL, 0x08B1A309824D288CULL, 0xF46D1A3D8CDB30E4ULL, 0x95641F3CD1B9175AULL, 
            0xD302915E6900A133ULL, 0x14FB5B86282A295AULL, 0x3A7176DE63499D04ULL, 0x66092851E88E5EADULL, 
            0x009461F835D83F41ULL, 0xA910CE9427B9DA03ULL, 0xD4CF2D3B84E3AA17ULL, 0xB4E1F4C77BA83395ULL, 
            0xCBD5A3636A451110ULL, 0x60143F42919F2775ULL, 0x3AC38FB53A389066ULL, 0xEA2E0E05E5CADCD0ULL, 
            0xA3817684264A4A6CULL, 0xBC483C699706C13AULL, 0x3D52F8AD7ACDC284ULL, 0x23873DFA4F299D27ULL, 
            0x6E0EDFC50A23BB42ULL, 0x62A5001011281B45ULL, 0xD52561E5576764F5ULL, 0xB476A335A127B870ULL, 
            0x53D968936CA40F0DULL, 0x53B7B9F4B1365618ULL, 0x8E4E7F4257FE2C3CULL, 0xE2F7C9FB796813BDULL
        },
        {
            0xBA204A4BC1C22483ULL, 0xE95EDCD81B8D5C6BULL, 0xDC574297B6B8F080ULL, 0xE88A7B80B0D2704FULL, 
            0x6E8C12FC9E95D2E7ULL, 0x8E2C9BF822F0EB4EULL, 0x561729E6BD4E76A5ULL, 0x84027C164C0A7828ULL, 
            0x53945A08249C123AULL, 0xB9ADC0C34994E8BFULL, 0x96AB7B22AE31753BULL, 0xF5CDD375F8D6D7EFULL, 
            0x7CF139023C440A6DULL, 0xACCE65742459967EULL, 0x0D219230E22211E0ULL, 0x4C1159085C34ECDEULL, 
            0xE7CDD72F705F125CULL, 0x82ADC01BE3119840ULL, 0x8D2F35F2FEF9E42CULL, 0x34A0BA0C043D51C0ULL, 
            0x44F6A7FBE5F89860ULL, 0x27D7F26DFBF7A268ULL, 0xC34E08D7C50AC803ULL, 0x3638C8AE20BE33FCULL, 
            0xA1C5C516540CE34EULL, 0xBEE83B70951EC353ULL, 0x3D4A6513086D55D2ULL, 0x2910087AC590DF20ULL, 
            0x1AF6A884835AD3A5ULL, 0x64B814C89D5855B7ULL, 0xBAD11E3C56A12172ULL, 0x468526022911F7A2ULL
        },
        {
            0x10F429D5C290C848ULL, 0x5495C4C4F85217B7ULL, 0x2657C111093271B6ULL, 0x0A4804D8961E9062ULL, 
            0xC70B074A5C0A4DE8ULL, 0xB47E4F782B8A72A6ULL, 0x8F0A4F7E3CA6338CULL, 0x259F8A6CD2FE01DDULL, 
            0x5C8F26AD7ECFBB9EULL, 0x3F82A83680897D4AULL, 0xA6277E22928981F5ULL, 0x048EB3791AFA04DEULL, 
            0xFC5ED75D9B836B82ULL, 0xE7E4C6893A33CC71ULL, 0x74023AE43E6BA08BULL, 0xD3754F22BB0487F0ULL, 
            0xF4FD522FFB771CFCULL, 0x92AAAF6395DCF25BULL, 0x3D0121FE81AE7CB5ULL, 0x5BE3078AE2EF9363ULL, 
            0x23F4E224819F5D9CULL, 0xDD9073F8A67C561DULL, 0x7D429C49A6D6F8BBULL, 0x6484F908E1F1EFF6ULL, 
            0xA63AEBE267AFB491ULL, 0x6B6478A7F99CB060ULL, 0xFBE783B3F1E5EC2EULL, 0x3D51BF42C0B8ACAFULL, 
            0x44357139B57B191EULL, 0x4B89B5E1318C70F3ULL, 0xC280A402F5D3C322ULL, 0xCBF993C871F10D27ULL
        },
        {
            0x0577B73F2B5A1A84ULL, 0x18BCB6EFA988D36FULL, 0xF3C03E64C0C0D9E0ULL, 0x9888006F48F15A0EULL, 
            0x7AD5CB4B481ABCBCULL, 0xD3770C919936E3EEULL, 0xAC495B17AEE612C0ULL, 0x09B749C4B68E96F1ULL, 
            0xB3E1E910BD24F1D6ULL, 0xF0BB6967B9DF6DD5ULL, 0x8343A8AD1E431BC6ULL, 0x81DD671480733671ULL, 
            0x0F7195ACFAA3863CULL, 0xDE53C0CB9722B80FULL, 0xECE7DC94C221C7E4ULL, 0x148A6F5FCF2C05E5ULL, 
            0x1E280CD815BA5C1CULL, 0xF5D68896C1045F57ULL, 0x78CC25A520EC91D2ULL, 0x8A15E610CD298211ULL, 
            0xE53F49E1AD04F5CBULL, 0xA770D02F5B71EA6BULL, 0x18D2B8A10B04CA95ULL, 0xC14BD32CB64E1A71ULL, 
            0x0233C256017939DFULL, 0x589FBBFF9BA4532FULL, 0x99B67686F2A3D0C2ULL, 0x32E37CE4B663C365ULL, 
            0x84D8202CB6726581ULL, 0x7D1646334180E756ULL, 0x51D150A37AEBD61AULL, 0x9BB0FE84FCF96C1CULL
        },
        {
            0xEECE54BFEFD1A504ULL, 0x2F6008EDFD146099ULL, 0x0D670922D5B82DB8ULL, 0x225E6EBA0FDF4111ULL, 
            0x017DA1B1F8E67801ULL, 0xBCC8B36532D5ED63ULL, 0x0ECD61455C4C7BF6ULL, 0xEBF24A9B24DE5481ULL, 
            0x47460A594594EBE2ULL, 0xC7B64D096164EB1EULL, 0x05D8657742B7D8CFULL, 0x720D982406272442ULL, 
            0xC729E87D64CD57CBULL, 0xA8057B1799125FF0ULL, 0x1CBD38C10C36EA3CULL, 0x70CFEAABF5737C06ULL, 
            0xF240F1CBB01934D9ULL, 0x0F316B3C9BDF6E1AULL, 0x48D13DEAED91861DULL, 0x19F1912A7E7DF3E0ULL, 
            0x17028D8C5C1FD0B4ULL, 0x5CB166CA7662F039ULL, 0x5B0428DDEEB8D718ULL, 0x3E64EBEC92DE7EBFULL, 
            0xB4D94940219D49D2ULL, 0x290355369CF567C6ULL, 0x4366BB10900EFF19ULL, 0xD668B24320808643ULL, 
            0x13672C8EC517C595ULL, 0x86E58ECCBBA11DF6ULL, 0x77147E872F704D6BULL, 0x567CF4570B489593ULL
        }
    },
    {
        {
            0x79B46BB0FCE32B5CULL, 0x5E70BC5119899A36ULL, 0x663427FF5B4A4CF3ULL, 0x424177DE71C2E329ULL, 
            0xDE10BD07FCDE2AB3ULL, 0xF751CDCB7863A761ULL, 0x7E44AA9B23576B7FULL, 0xE528B8C191BA5BF0ULL, 
            0xE47F8297F4A28381ULL, 0x6C4BA4B29EB95D24ULL, 0x88C51A2539DB34E8ULL, 0xBB6804480F193BD9ULL, 
            0x5459E2ACCCD0B528ULL, 0xD646416AB5FB7835ULL, 0x093C1D65BD277957ULL, 0x2B650F1D5613E051ULL, 
            0x7113A91EF12CCAFCULL, 0xB03B2C4BEE693129ULL, 0xD6ED66DAFB043CF6ULL, 0x75138DE262520AF8ULL, 
            0x5177BA78AD1D5F09ULL, 0x4BCCCEFD38C21340ULL, 0x46F04E26E9F238D5ULL, 0xEE29B2C0F00D7F5CULL, 
            0xBBDFCD6CC33F9EACULL, 0x1EF95AE9DA6480A8ULL, 0x87588C303E783F72ULL, 0x925563AE51ADAD29ULL, 
            0xD6F097A7F49A3A29ULL, 0x21B84DCA223B7732ULL, 0x1BCD5C6E48E882BBULL, 0x359E5B32D3F70DB1ULL
        },
        {
            0x309128AB568A8849ULL, 0x4AC59450659EC9A2ULL, 0xD8E0242CBE71992AULL, 0x1894AC6433D26F3DULL, 
            0x360E62E4392050BBULL, 0xDAC56FDCFB676A1EULL, 0xEE73F5E079D145D3ULL, 0x9B9FB3844F97DF81ULL, 
            0x7CB7289D5DAEB215ULL, 0xDDF69EDFCAECA0BFULL, 0xA1DBDB83C0508B83ULL, 0x22801DE94953F80DULL, 
            0xB12222D8D22AF417ULL, 0x4247282FAF33837AULL, 0x31050432FCB0297CULL, 0x16B4F9EC08573663ULL, 
            0x38CB9946F05A1FB0ULL, 0xA17C4050EDCF9969ULL, 0x52C567430D1BF2F4ULL, 0x0E619239BB446AF3ULL, 
            0x895773F8D083E375ULL, 0x11CAE0E50D023EF1ULL, 0x53A855D119400C86ULL, 0xAD3D83EC2695E121ULL, 
            0x16AD75F8CEC42794ULL, 0xC953E60CCFEDFB3DULL, 0x01C376EC07790DB9ULL, 0x08E380EE1F88B23FULL, 
            0x2E4397067BDA06CDULL, 0xB8BFBFEDA2DBC985ULL, 0xC55859AEE0E8142DULL, 0x0ADD37F8B8B3545BULL
        },
        {
            0x0BDDED8C95FDB2D0ULL, 0x24BB9AB8CDA903B9ULL, 0x43144D7B1099FDF3ULL, 0xECC1753161295C09ULL, 
            0x1A0B3E82447D3D6FULL, 0xD00C673D686192D3ULL, 0x8C3CE3C36D956B6EULL, 0x72396D2EBF8966D1ULL, 
            0x7F174B4CBBEBCD55ULL, 0x3C3188BF142BF37DULL, 0x4BD9A706B8B858B0ULL, 0xE4780125CD0B1F86ULL, 
            0x79159950ABA74528ULL, 0x4809155CB6DEEBC4ULL, 0xEAC89CA84D310651ULL, 0xF24C01D835B084BFULL, 
            0xEBFA9751C00AB837ULL, 0xE338C8A3E3C55E9AULL, 0x356C3E2C0DADA406ULL, 0x856644EC169A923CULL, 
            0x2FC0F174A860776DULL, 0x3BEBD99038EE3AABULL, 0xD7A9651D2B51596CULL, 0x6580E27B11DE7A40ULL, 
            0xB2BFED31C191D533ULL, 0xA366FECDE613EF37ULL, 0xB00FA98033AB6E10ULL, 0x842343AC96E752B5ULL, 
            0xD51494437766E23AULL, 0x91F23B895912F52CULL, 0xFE36A89B78BE0177ULL, 0xE3576C7D9320E1CAULL
        },
        {
            0x91C744F0DA4B5940ULL, 0x56E91D804C4C6978ULL, 0x969D6E3E73D4959BULL, 0x5C76B265917F929DULL, 
            0x2E1B14C9BA74F00AULL, 0x6C946A5CC66AB832ULL, 0x489852C980C01633ULL, 0x113148BEB3A5634DULL, 
            0x0451876FCE41578BULL, 0x32B1A30DA6A54EEDULL, 0xC29FEF9BE298E3AEULL, 0xED78A8BBA52DFDA1ULL, 
            0x1B2D908DA1602597ULL, 0xBD761CD9EAA808D5ULL, 0xF6BB29A3427B01FCULL, 0xDFD5E95E967436ABULL, 
            0x9121AD42D7577AD1ULL, 0xD26FEB7E8F7C719FULL, 0x2619993E0C64C25BULL, 0xE66039A08A82F255ULL, 
            0x726507B1D5A6FC19ULL, 0x7DD50AEA70CD7FA4ULL, 0xD2544C921929DCAAULL, 0xDC94472172B90C71ULL, 
            0x47979A06C95F0ADAULL, 0x3100AC0A1183F102ULL, 0x7493074C061649BEULL, 0xE3E383563E3B3C0BULL, 
            0x66DA487736CDB111ULL, 0x9055B1059AEBA758ULL, 0x7F7419EC590F8B1DULL, 0x7D23294A9C50EDDAULL
        },
        {
            0x99B719D4E1AD01E7ULL, 0xBB4431E7C60DC2ABULL, 0x1B63C64BDC1030CCULL, 0x1B2A6D1D0C0C2EBEULL, 
            0xF58B1CAABCE2E4FCULL, 0x75952F61BEBDBF2CULL, 0x3E1D5BDBD8946815ULL, 0xE5448E7498485519ULL, 
            0xDEBADFA2AB6AD7A3ULL, 0x7DFB3B2A1CD124DCULL, 0xEC0BBCE8362C9D45ULL, 0xBA113DD45600EF2BULL, 
            0x6BDCB6C6BCB8A911ULL, 0xE366D94ABB0BE14DULL, 0x29A45F7D398AB535ULL, 0x2E5BDF4532F3C914ULL, 
            0xDE427681572EB569ULL, 0x6702B5065C51470CULL, 0x46440D27472D9421ULL, 0xFB7DF1EEFA0A771FULL, 
            0x8629C61AB73D0B5CULL, 0x647BC3BA4592451CULL, 0x78AB89858DD8BBDCULL, 0xF6C66A5EEA964751ULL, 
            0xB06A1A5632A2F3ACULL, 0x90C70773D1FC0264ULL, 0x44141721D9D23008ULL, 0x3EBD39D48EF8FF49ULL, 
            0x8339C077BAB8BB0AULL, 0xB6815140A36CA3A1ULL, 0xEB6CD533074FE89BULL, 0x8E16F888FFAFF71BULL
        },
        {
            0x664B7384EDFEF930ULL, 0xAFE651FF441F653EULL, 0xF5791378DA3CB223ULL, 0x0402185375534EBEULL, 
            0x66F862593E8FA91AULL, 0xE9CA3EE3F8B47296ULL, 0xDAF3CF43A091D400ULL, 0x3A56FE89F4651F29ULL, 
            0x686DD7A09FE93A31ULL, 0x44E075A4E2CA5676ULL, 0xD7725F98C85F8581ULL, 0xD846875DF947FBF9ULL, 
            0x166E668E2F8DCDCCULL, 0x121847B1A105D3ABULL, 0xEA9E92DC18811F9AULL, 0xE26ADCC15B9B9A73ULL, 
            0x1410C79DCF8FA272ULL, 0x7AA162DFEA9FFEE1ULL, 0x27A30707534202A1ULL, 0x289B2457282751D9ULL, 
            0xD32C7BEAD6E24F89ULL, 0x2E8AD276F87A5CB9ULL, 0xA9C8EC147C8E4929ULL, 0xA4F934200AC726A5ULL, 
            0x588D2001E6679B0DULL, 0x2B03D43A11946C12ULL, 0xC4E2D67C4E7543B0ULL, 0x9539FB3EAD7F620CULL, 
            0x2E9F216949884B63ULL, 0x3949341F4C157D32ULL, 0x41122BC6BD095EF2ULL, 0xF34377AC2164C6BDULL
        }
    },
    {
        {
            0xE467C811C80CC785ULL, 0xE991B0CF1E346907ULL, 0xE95339FDB91E060EULL, 0x4ECC98F49861B8ECULL, 
            0x0C2FEB461780EB18ULL, 0x887057F4EE509537ULL, 0xFA3698B275E8F114ULL, 0xD9FC4748BB2F6A48ULL, 
            0x3200AEF531A50E6EULL, 0x64E3720F0B1BA421ULL, 0x197B3277736C245BULL, 0x90A9318421445CC1ULL, 
            0x15937F5B40400CF7ULL, 0x06132968608B741BULL, 0x857A48537EDC027AULL, 0xC6DF9D0F7A2945F8ULL, 
            0x5DB0FCF98F003F47ULL, 0xE60DD6E791BC8938ULL, 0x60E89D68722442A4ULL, 0x85D653365A452F4EULL, 
            0x96BB77DA4ABB63FFULL, 0x3FA775C4BF32F881ULL, 0xD9108C2527100F35ULL, 0xF4D64CB96D8C5538ULL, 
            0xC14A892090C1E4E3ULL, 0x3946809A5391E0A3ULL, 0x9ABBC62DEEDCD2EEULL, 0x0506E8CFA09AA03DULL, 
            0xDB2C9C9CA4090F80ULL, 0x63E7691864C06AB9ULL, 0x0200BD3D5460049FULL, 0xB487C406D3E92939ULL
        },
        {
            0x6CDC5571BD264109ULL, 0x8FD84B69861216A5ULL, 0x0F6B0DF210FF212FULL, 0x5D6E9840C3D07463ULL, 
            0xF7B2A5D666B543C9ULL, 0xB391CCE4550E2CB9ULL, 0xC0F4343628FB451AULL, 0x078101F96E66DC34ULL, 
            0xAF27CD79FA106CA2ULL, 0x4D4603F00BBCE62DULL, 0x4C22BD606C34431EULL, 0xCE60757614A171A5ULL, 
            0xEACF59E3D8E760E5ULL, 0x8229E21813E330F8ULL, 0xB9B53A09274815ABULL, 0x96EB1FCE24555117ULL, 
            0x35E9F12E3C061B96ULL, 0x413B04F79295D8DBULL, 0x359858A9BF26809CULL, 0x77722A63D2A257A3ULL, 
            0xB0ECCBE7A54280A6ULL, 0x6F70294C4A608CF4ULL, 0x75A0B1A2E852B4FEULL, 0xF9A617A4F21083FDULL, 
            0x722D1E8DFFD9252BULL, 0xE57C05C19123AC6EULL, 0xB24DF3D80ECC618FULL, 0x1A40A68B49F0997DULL, 
            0x2162B6CF32DCD460ULL, 0x6A2BAE7110F3C881ULL, 0xCC7F31307B75AC7BULL, 0xD878D805E0C3D8FEULL
        },
        {
            0x2DD834F11602CD10ULL, 0x6D254A36BC7E5C0DULL, 0xF28568934C7F45F6ULL, 0x698718D59517C35EULL, 
            0xBE8B0008B4688ACFULL, 0x062BCEF445304DF6ULL, 0xFBF2622DBF467A9BULL, 0x2313C3D9951ED51CULL, 
            0x86037CFB9BD54C4FULL, 0x30796B84524B5C73ULL, 0x24E8490B0814182DULL, 0x5BC417296E2B2DC5ULL, 
            0xC1705BB64534CB03ULL, 0xEBE24FED41B0BC9FULL, 0x710B8DC579BF3753ULL, 0x10434BA144D38AA0ULL, 
            0x54DBA3F34609E81FULL, 0xFCDA7BA4753614F3ULL, 0xF73081CD644FBE5AULL, 0xCC7C0303A5D708B3ULL, 
            0x5C0B113F159F2E8EULL, 0x31E17EA66810EB48ULL, 0x3BF3E10CCE226CD6ULL, 0xCECA4A0D7C972DD2ULL, 
            0x47155FBF098C75ADULL, 0x900E4DF12A6D1D9AULL, 0xA97777EB672D391CULL, 0xEBFEE0BE79E6A38CULL, 
            0xE19565B766EE5C22ULL, 0xC8D7A6C88D92D614ULL, 0x300803C335CC0509ULL, 0xB586F38D19763F94ULL
        },
        {
            0xE4DD1614658494C4ULL, 0x997A25DA5C8CF688ULL, 0x35136593845DAE87ULL, 0x55021FD3F6BC9F6FULL, 
            0x56C7222E8A623B33ULL, 0x8B14BC920568478DULL, 0x161ED754059B0D3DULL, 0xA095590199EB10F6ULL, 
            0x8E3427AE74FC0F3FULL, 0xCADEC0D588F568CBULL, 0xBBF9CC021B9175ACULL, 0xA36D0A74B8732B00ULL, 
            0x983FD5BAB7882381ULL, 0x58F0B844F771D49CULL, 0x355FE3448C2B8531ULL, 0x60FE32B870F9C46AULL, 
            0x82E09BC6AC6F1DE5ULL, 0xD3BF391D19864FA9ULL, 0x8B3DBC09A3D5E1F5ULL, 0x5EE71B5EC64F52D9ULL, 
            0x38993E83040B4AE1ULL, 0x8E521751B14A6749ULL, 0xEE48E721034214ABULL, 0x3A53729FEEBAD6A4ULL, 
            0xB52FFCB8B4EC4AFBULL, 0x11FB7638B40F1A1BULL, 0xE687E2A13F10EE11ULL, 0x77CE8EEC1E402729ULL, 
            0xE98F786353A0D913ULL, 0x5FAFB14F450C2452ULL, 0xD3DA633E38DBD2DCULL, 0x1354445221011D96ULL
        },
        {
            0x02A969131775C75EULL, 0x8E65BA5CF1E6FFB9ULL, 0x9D17A97DCB9F1B1FULL, 0xD58C12AC97066D75ULL, 
            0xF9942AFA9A850A5AULL, 0x6081F67EE792EEDBULL, 0x155BE812B33C0200ULL, 0xB364CEC75A3F6BFAULL, 
            0x890D4B3F8E6438CEULL, 0xDF4B6879304F152AULL, 0x809D95C9D39198EDULL, 0x52116FDFA724EC30ULL, 
            0xA521CF7241DEE230ULL, 0xD15C0C9E0D291648ULL, 0xC4C8A1262CF8576EULL, 0x91916A086AE9C0EBULL, 
            0xDE6445A69C439838ULL, 0xCC30E01ECCDD7011ULL, 0x0C7A6DE146FFB8B0ULL, 0xBDD99791B3837412ULL, 
            0x555CCE4579C20C7FULL, 0xFB656C897156F0EAULL, 0x3B48AA8FD7BD201FULL, 0x26E234C8E3ADA8F0ULL, 
            0x2BEF69607D31E0F5ULL, 0x45FB71A11448FF48ULL, 0x6A0692596C8760BFULL, 0xBB9DE9E3BC308556ULL, 
            0xFC02280F20D4A340ULL, 0x002C5714E12A2328ULL, 0x6CB67A3471EC12C9ULL, 0x3312A08412F70A4EULL
        },
        {
            0x8D1CD2E7DE475B02ULL, 0x5D6BC1ABC3159ABEULL, 0x0C037E4965831BBEULL, 0x9DF5BA4B42F9AEC8ULL, 
            0xA51F58770992B818ULL, 0xA727DD41F4B2F127ULL, 0x7C2A67CB58B71B58ULL, 0x2EDC502BA79BF3D1ULL, 
            0xD6BCEA69DBCB3D59ULL, 0x8001A2EA8B917584ULL, 0x14F08F22578673F0ULL, 0x482A24D13DCA1416ULL, 
            0x2992DEEA6C8A65B0ULL, 0x6D65BEF8439E3B20ULL, 0x938CBF53FFA474AAULL, 0xBF8EF39A88ADE88AULL, 
            0xAFC07AC15348E8A1ULL, 0x03B5ADCED19A6019ULL, 0xB9CDAE7E28C0A1B4ULL, 0x302B12AA6864C479ULL, 
            0xD5143B8B3A7D18B6ULL, 0x1AAF8831579A0806ULL, 0xDDFFE36FF163F84AULL, 0xEACC41FB94BFA182ULL, 
            0xFF7FFD7E639C02FAULL, 0xD0B140425A8E640AULL, 0x9163593120466CB9ULL, 0xCE34FB72BE7024A2ULL, 
            0x07AE6FD373EFF276ULL, 0x262D293DC3488263ULL, 0x8CA414D0AEC00C0FULL, 0x15BBE991A447A3E4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseGConstants = {
    0x4B633BB67B2BBB01ULL,
    0x897DA0D9AA048132ULL,
    0x9F05832366A27790ULL,
    0x4B633BB67B2BBB01ULL,
    0x897DA0D9AA048132ULL,
    0x9F05832366A27790ULL,
    0x753534C0D47FC980ULL,
    0x0E0453E37D4FFF03ULL,
    0x84,
    0x74,
    0xE6,
    0x56,
    0x9D,
    0x36,
    0xA7,
    0x2B
};

const TwistDomainSaltSet TwistExpander_Billiards::kPhaseHSalts = {
    {
        {
            0xBC9B8D21F24B28B2ULL, 0x1456F66094FBC76BULL, 0x2A191CC68853D160ULL, 0x1740BCEE5F510C7DULL, 
            0x0706A1A159DA3DF2ULL, 0xBE989A92687B5DE3ULL, 0x8EE93CF8AF335197ULL, 0x7713BD89757A0D36ULL, 
            0x40095504930AAE09ULL, 0x9C4E5F35F4F5646EULL, 0x7D0D2DD2C37F9A69ULL, 0x1ADD774BA0162335ULL, 
            0x16F5F1DCBDB55570ULL, 0x963AEE31F7D9759BULL, 0x16037581C2C5D2A4ULL, 0x38613AE05964BC83ULL, 
            0x2BB9B3B1B41BD7B6ULL, 0xD8C1FA075C4C09E5ULL, 0x50C75DA3369F073BULL, 0x520075788AF40E8FULL, 
            0xBF6E317987F77FD8ULL, 0x177BF7C04813C442ULL, 0x614C9772FD65A712ULL, 0x5AF687E88D3EC038ULL, 
            0xF56C198852B28E4BULL, 0x91746817A0E6D10EULL, 0xE404ABEFF0D751F4ULL, 0x7BDB245008739278ULL, 
            0xE768295B9D943444ULL, 0x2C50B9591F7DD2FDULL, 0x996EF5E541DBD1F1ULL, 0xA5020B2D520ECEE1ULL
        },
        {
            0x9FFB82677B0ED376ULL, 0x1D6F2B4738DD2227ULL, 0xAA372DB33943AD53ULL, 0x4CBF7CE3698BEDEFULL, 
            0xB3FAD455E6DA9F05ULL, 0x770295E53F87FA2CULL, 0x1C93DCAE951FFC6EULL, 0x6B5444D4C25ED539ULL, 
            0x7C254221842C8036ULL, 0x9B4A724682A4ED06ULL, 0x5C205516EDE8D93CULL, 0xD15A6799B26C1248ULL, 
            0x7ABAD4D763911DB5ULL, 0xFC398DA9FC44872BULL, 0xB9E48805D1A461BFULL, 0x467A9DD214E85B05ULL, 
            0x66E33BDFE53B6AE9ULL, 0x72ACE5B47432450AULL, 0xDD1DE8D6407FD1A3ULL, 0x734E062BD320E0A9ULL, 
            0x817E34042D5ED7CAULL, 0x2289BDE7F461AD19ULL, 0xECEB14349D53384EULL, 0x54A73DA985A63824ULL, 
            0x74FA04D32699960AULL, 0xEB2C4E37B4E7D2F2ULL, 0x922572F5095F84CDULL, 0x690A0B12839A890AULL, 
            0x1F90FA5854044960ULL, 0x6548FF457D064144ULL, 0xB7981D15FC7C58C5ULL, 0x12D9E7673268D857ULL
        },
        {
            0x5AB749E794920DE2ULL, 0xBF8FBEC5D7DF8B6FULL, 0x2839B7D1773EA1D4ULL, 0x3DFBE9C3D3ACB3D0ULL, 
            0xB71A9CB69AFD2215ULL, 0x4126A8FD6E3BDE59ULL, 0x464B6DA973A16670ULL, 0x161507EC1A617404ULL, 
            0x5161A53C198991AFULL, 0x048671D64F38B1D7ULL, 0xB04F6653EF76F61AULL, 0xC8A7DAFE51B3DCABULL, 
            0x5BC8D87C6EC150DFULL, 0x574FE9004B6565B7ULL, 0x9079667646BA50ACULL, 0xFC161BAC44AD0C7FULL, 
            0x0313883FC9C85DE1ULL, 0x35C9B5C901F880A7ULL, 0xBC378FB9024FE378ULL, 0x5BF9C2D811FE306CULL, 
            0x769535BF9C435915ULL, 0x19C69254B11A0849ULL, 0xC20050BFB2E80A52ULL, 0xD52D47B3A26E42C4ULL, 
            0xD2FE9399A09EE3A2ULL, 0x038ED2BA14FE7F49ULL, 0x4588830C7911F337ULL, 0x5E7F55B5D1E03A01ULL, 
            0x7827EFA2E2314DD2ULL, 0xF45ACF9D618964AFULL, 0xE0FAF41827F2388BULL, 0x96D9D4BF03E1454CULL
        },
        {
            0x4ED3DCDD7766805EULL, 0xC54CB054640DADCEULL, 0xC399C10F6AC690BCULL, 0xA186D3254598A6AFULL, 
            0xE50C3D41DA1C3441ULL, 0xF691D54027C68EBDULL, 0x13EFD286D02C785CULL, 0x6A2F96B73075150FULL, 
            0x56E566AF9E5ACA6DULL, 0xA78D649C4032E9EAULL, 0x8CF4D10A43910F33ULL, 0x5E0A6A17E1832392ULL, 
            0x788AA8C99EE8E2A9ULL, 0x90E39903E81E2CC7ULL, 0x4AE1B892D6B662D8ULL, 0x3421B43AD6AE9EFEULL, 
            0x461EF992E8184ECFULL, 0x90DFAFB0CF2C7D87ULL, 0xFA92D58734C3C94CULL, 0x3DFA4389418EDCA4ULL, 
            0x4BE472F498117386ULL, 0x4E93C27350F17281ULL, 0x89FA892B05C558A6ULL, 0xD1302C0958B53A0BULL, 
            0x5C43ABF4140878B3ULL, 0x8EAA0D8A8A8EC2F6ULL, 0x3E419C81DBE1FBFEULL, 0x8FEED622333AC1FDULL, 
            0x2BFC2EA58DF724BEULL, 0xE011CE5369CA16ABULL, 0x5E0FFD4F59BAC8DCULL, 0xB0AA734381CAC214ULL
        },
        {
            0xE5F8F2926450E401ULL, 0xA23D20042C51CE1CULL, 0x22AAADBDDE743A2DULL, 0x6B610EAA24D7AB80ULL, 
            0x1E55D4FF3BDDF98DULL, 0xF98E4C6356CA6E4EULL, 0x3FF5F6F46DCAFD15ULL, 0xC4FC0BCED77C4A8AULL, 
            0x5FC89DF526EB2827ULL, 0xEB4C9E60AF584DB6ULL, 0x61CCFB8EB2E219ADULL, 0x2114BC2B3D9D731FULL, 
            0xBDEBF272D1FE9698ULL, 0x4A1A1E298D9EDB26ULL, 0x90A0C58984EAD7D8ULL, 0xF337B1F4853E0B40ULL, 
            0x6CC72AF7FDE4FA5BULL, 0x41C2F2931950E3ACULL, 0xA1AC3E1866753CDCULL, 0xB0C51E8537BC0821ULL, 
            0xD6B6CE140F7D7E18ULL, 0xDB3C817993F7308FULL, 0x76EE861FF1253A94ULL, 0x5CF071312FC247C0ULL, 
            0x73C648D8D60FE0AAULL, 0x876916BE689CCAFFULL, 0x0588B58380925E04ULL, 0x675CD3478665E58CULL, 
            0x9C59A4A96D88FEE7ULL, 0xFD2E22F96FE72004ULL, 0x56B485234FBD3C13ULL, 0x7403813D71248DC7ULL
        },
        {
            0xB08B5ADAE2941446ULL, 0xB493248775EA6898ULL, 0x0B5549448F0C0B64ULL, 0x69B1147CAFCAEF2AULL, 
            0x98ED41A09ACDD786ULL, 0xE2E5DD980F534497ULL, 0xC8208385F3FD773EULL, 0x9DC14ED49BFA577CULL, 
            0xBFD46744D25EE80AULL, 0x86EDE656F92E936EULL, 0xFECFE3DBC1075827ULL, 0x709E821305060919ULL, 
            0xEEC92B912F0F64BEULL, 0x2DD7DD47A37C0B02ULL, 0x383E0DAB0813BA20ULL, 0xE9B3FF19852DB3CCULL, 
            0x5B87FA6A3386F923ULL, 0x900C89BA5BC9E5C5ULL, 0x1F459D2259B3B995ULL, 0xE69E266DAB02F61CULL, 
            0x072F0DEF21E134A8ULL, 0x28FC84385D69DDE7ULL, 0x0080136EE05AC4E8ULL, 0x234A83D69D44E4B8ULL, 
            0x43B936C871D219B7ULL, 0x2D0A4F727AE9BD7DULL, 0x5A0866629E29481DULL, 0x280319E44DD269DCULL, 
            0xF4668E3A91E86CECULL, 0xAF8CD218792A04DAULL, 0x90266E2DF71C4AC3ULL, 0xFADBD14AC73EBA55ULL
        }
    },
    {
        {
            0xAEEF78EF786B644FULL, 0x561D006E4522E7B4ULL, 0x1945B658F7D39DCEULL, 0xA0509B55F013125FULL, 
            0x8597A0F1F28861EDULL, 0x9A47508EE99CF0A2ULL, 0x4A8919AD8F307349ULL, 0x629491108478CA19ULL, 
            0x415109C82567311CULL, 0xBE19639590797A72ULL, 0x393C436F71DA3DFEULL, 0x4911BD5D000A283AULL, 
            0xE8D030509ABF4142ULL, 0xBBC3A3CA5F90F3A0ULL, 0xB44025B28CE097B4ULL, 0xE4749C7D008B0101ULL, 
            0x81D38000335349C1ULL, 0x7F9733F2EB19A1DDULL, 0x37980FB8E364CF53ULL, 0x61803FD6A12564D8ULL, 
            0xAD89A7AD90C66932ULL, 0x536506F58305F737ULL, 0xE2D3CB0A35840AA8ULL, 0xA9165791C5307C79ULL, 
            0xB607259C6136C4DAULL, 0x26211014755E86FEULL, 0x1B886DF7416BBCECULL, 0xB95713A54EC89706ULL, 
            0x697EFBAA841D9E40ULL, 0x4695513402A5B8EFULL, 0x88E88C6567C68DE0ULL, 0x0841398A84336409ULL
        },
        {
            0x54BDD2153CA883D5ULL, 0xE9A32460AAD69A96ULL, 0x970A75C9B676F82EULL, 0x9C29F48DD47A4898ULL, 
            0x2D3BDC4382440ABDULL, 0xB48F2A87749248E7ULL, 0xF0C6D8C5F30D34C9ULL, 0xD701674C904AE660ULL, 
            0x6986584D0663F9EAULL, 0x3CD5A2FE460A2798ULL, 0x65AC70EB37DB6164ULL, 0x6189BAB3161CB3AFULL, 
            0xAD713D267A752B02ULL, 0x8E5616E895338F68ULL, 0x88416F02E9F0C541ULL, 0x1C17237B341927B2ULL, 
            0xA85AE63AF2C152EAULL, 0x7B4D069981691B79ULL, 0xE61BC806A7856159ULL, 0x7332144475FA27E6ULL, 
            0x051589616CE1839CULL, 0x4715CC7B6CA0C8A4ULL, 0xB58A280C52041ACFULL, 0x9C5DCD255F0299C8ULL, 
            0x6FDA5D0A877E2329ULL, 0x98DF294BC43CF653ULL, 0xEAFC27E475BA1216ULL, 0x56136822127ABF64ULL, 
            0x3E17EAE54EFEA6C0ULL, 0x0A21824D3645AA48ULL, 0xD64670514E0C19F9ULL, 0x75BEDC1AE574B25AULL
        },
        {
            0x3367A6AAE4EE411AULL, 0xF46BE3889239E6E5ULL, 0xBF20FC574C7A240BULL, 0xEB760FC0E9735C79ULL, 
            0x8DCD1C1EBC473150ULL, 0x9F8566260CF5124BULL, 0xF2296C7738873D5EULL, 0x1C384677DA060AD5ULL, 
            0x01C87D52A5465765ULL, 0xAB32EEFAC7F4BD03ULL, 0x00017351B5E108B1ULL, 0xD065A8673CFDA0C1ULL, 
            0x5E7E24138579ED23ULL, 0xBB00B6DBF43D1842ULL, 0xCEEC1778F3906360ULL, 0x18E13F28C160E19EULL, 
            0xD6AF15212EA2FC87ULL, 0x9AF38EE74F75E0A9ULL, 0xF5C99AC4619D0F25ULL, 0x0B567F3A497BB662ULL, 
            0x7F09322AF6E23CF8ULL, 0x7A7876CDBA7580A2ULL, 0x2732462296F1651FULL, 0x08F28766C36B0BC9ULL, 
            0x8EEE41F9114A3555ULL, 0xE89D77EC5CA8F78CULL, 0xA8286C8889FE95D9ULL, 0x65D95F4A68896555ULL, 
            0x4C42B2B65A2206AAULL, 0xBA69C32F00F4E150ULL, 0x490DA1F0C71A08DDULL, 0xB506FBF24722D35FULL
        },
        {
            0xD50D68DBBD93F41FULL, 0x7DA2BE42DDBCBA6FULL, 0x80B764A4A2986B20ULL, 0xC9319E82249EEC6FULL, 
            0x28DA3C5A30F173BBULL, 0x9EB4E21C1DDEB160ULL, 0x7F75450982816B38ULL, 0xFCC78C3F061264B7ULL, 
            0x2C8D87F5F365A878ULL, 0x64575B65DC0CA945ULL, 0x0DFC4EF42899FD8FULL, 0x30299C5B4005EA4EULL, 
            0xDAFF33756046DDA5ULL, 0xD37AFEEA8DB97692ULL, 0x83723241FF95F1A5ULL, 0x481D8490C5F41A7CULL, 
            0x4FB664A22B0B452AULL, 0xE5371FA70991740BULL, 0x5312AE916755E589ULL, 0x946C5A2985793BDAULL, 
            0xC1FB11049305623EULL, 0x63C55193AE8EC56CULL, 0xFC943187A238D5E5ULL, 0x56A6B3FD2E5F25DCULL, 
            0x41FC5126346F4340ULL, 0x88C2952909FFCD7CULL, 0x66CA168CD20026AAULL, 0x4FA0750C33355B52ULL, 
            0xE21F6AFA67C766ABULL, 0x80729EA58AB58700ULL, 0x1994031CC45D146FULL, 0x8D9B310F32EFA4F3ULL
        },
        {
            0x600067AEF40459ADULL, 0x117153472CEDA654ULL, 0xE50CA00371CD605BULL, 0x037A06DA12E239B9ULL, 
            0x4CE2538B991351B6ULL, 0x2FB148ACE1C89327ULL, 0x5C07C39885DAF7E3ULL, 0xF6066C85218D1C4DULL, 
            0xE4B81B5DB49F9646ULL, 0xADEC263614B8C38BULL, 0xB421FE71047B6B6CULL, 0xB95839E02DC50B2DULL, 
            0x35FD7B4998DE6F42ULL, 0x6C1C8301239D4C9CULL, 0x54178CA57B0BBDD5ULL, 0xBF5159CDCCE796A0ULL, 
            0x603CBF7ECB1A069DULL, 0xF4F89B77CB46FD50ULL, 0xC12CD023AAB91831ULL, 0xB408F6FEAC5E080CULL, 
            0xADE71628C18992AEULL, 0x5892DFCEB5312A5FULL, 0xCF21A2C9CDC2B41DULL, 0x9D49F37AB86CFFA9ULL, 
            0xAF499C11CD95C357ULL, 0x72C84E5701E2DE2FULL, 0x546E02D58AFA77AAULL, 0x4D5DFDB2AE35964FULL, 
            0xBB42A80BD7377A25ULL, 0x14FA40381FEA70EAULL, 0x3DA58BA1B2502E02ULL, 0xF0A652F76C0C030FULL
        },
        {
            0xC8C3AC98D6A56520ULL, 0xD8DD339C1C022EA1ULL, 0xA566788F6CD6964BULL, 0x9DDF76AA6D031B4FULL, 
            0xD29D37C68A2B8C28ULL, 0x0656E25420EC50DDULL, 0x9AA025C02F5D9184ULL, 0xE7C24EF0775D9BDEULL, 
            0x168C8B8E8C7F5575ULL, 0xBAE5340E2D3B7681ULL, 0x3014DEFF7151A3D7ULL, 0x17FFA8756E104150ULL, 
            0xEC303423447DE074ULL, 0x29724E3CA6A130C5ULL, 0xA44E83A0D6929E71ULL, 0x406504271EF4968FULL, 
            0xE052CC27CCAD89D6ULL, 0xFE416D1AD37C2E37ULL, 0xAD872E9D57D70D18ULL, 0x9DFEF1EE65349F7EULL, 
            0xD82FD6469C7F6FF1ULL, 0xC7FE4903FD117286ULL, 0x97C8C24F9A7458FEULL, 0x630C1C0C1CE1BCA5ULL, 
            0x57E2A1C1472A712EULL, 0xE99F8CAC0076D8E6ULL, 0x44FD8202A55A5289ULL, 0xD361F83756BC9333ULL, 
            0x427FE4E6213D7C26ULL, 0x02B3CD3DAF343464ULL, 0xCB7583D5A1CDC03DULL, 0xFA9EBB0C85282385ULL
        }
    },
    {
        {
            0x4B6AA4C2D75E8772ULL, 0x50D378000E2D3769ULL, 0x5FF5FCFD6B333823ULL, 0x8DC26E7437FA97E9ULL, 
            0xF6ED357A5BBE0B48ULL, 0x5F1A557373AB163AULL, 0x0B02EAC2ACD8D6CDULL, 0x6DA171D71175341AULL, 
            0xB21C7A6640E6536CULL, 0xE521E104237CF3BAULL, 0x8A1210E69D166A23ULL, 0xE9D86AE2F72C716BULL, 
            0xC5FAAB20DE459872ULL, 0x08AA9F5F378357CCULL, 0x7C63A27E9CD4823CULL, 0x9EC483996DB83B02ULL, 
            0x480E6555D014477FULL, 0xB3FBBB1B4045F1DFULL, 0x9FA396349E83E59DULL, 0x69AFA332F58112D6ULL, 
            0x3EE2D99BFCCDC80BULL, 0xC31616B03BD65993ULL, 0xD5A373BA76C338AEULL, 0x01E9D131FA087E28ULL, 
            0x1FFF014FF020C717ULL, 0x090B04C0CD6DD0F2ULL, 0x4F1B212778C2402AULL, 0xC3F37AE9ABEBB37CULL, 
            0xAA50F7EE8C027483ULL, 0x91E03D1FBFF94821ULL, 0xE482A4AFD3EB6C21ULL, 0xBCC1CA9E9F93C748ULL
        },
        {
            0x1A8F84CB7CE31D3AULL, 0x95862E3EA4968E7BULL, 0xB2202CEA38153974ULL, 0xC9835D8A3EBBA3A6ULL, 
            0xC5FF5368F87677D6ULL, 0x0C87B79B7CD198ACULL, 0x7BADCFD9504A8E7EULL, 0x1399C09DDDC4E7F7ULL, 
            0x5A9CFBCCC977A767ULL, 0x0BE3C6B4AD95650FULL, 0xB4709D97C82DF487ULL, 0x80DC09B313BCD65FULL, 
            0x19DF312B62147D8DULL, 0xB78C532A1086503DULL, 0x6C3C5A8ED99F85CEULL, 0x0A0D6A4D46DB84E2ULL, 
            0x5F51D1EFD0787A44ULL, 0xC3929E145EC75AAFULL, 0x4D318AD590E5404FULL, 0x2AE26E178A2F43BAULL, 
            0x8A94C3A66A7E2BCDULL, 0xA5A5D8FA92051730ULL, 0x086ED2834B7A53EBULL, 0x1AA8954B35234D53ULL, 
            0x5C20791B35D9936FULL, 0xB0421430D5F2F444ULL, 0xA86176876EA495CCULL, 0x310CD30F5D5F511EULL, 
            0x347F06A99354D882ULL, 0x11F66D182C980AF3ULL, 0x7FB1129A24C209EEULL, 0x8F7D5BEB2F250488ULL
        },
        {
            0x39E1082921DC14FDULL, 0x94B86DCBBE2D338EULL, 0xB6715D717532E023ULL, 0xAB0735B6ABC444ACULL, 
            0xAF7B74E6619A9C04ULL, 0x71F8DE22E237E66EULL, 0xDABF8763297FA047ULL, 0xE7E1490F85C2E49BULL, 
            0xB3AEEFE41007F356ULL, 0x3DC06F4A92C1F4B4ULL, 0x013FEB3509848859ULL, 0x4D01279D1B17F083ULL, 
            0xA967D26C4C62EC69ULL, 0xDA9C447AAAF2C2B9ULL, 0x0234DC25C222FF74ULL, 0x361C72A12EB338E6ULL, 
            0x19840B245E130443ULL, 0xD756C3492D67F401ULL, 0x2B315A2217E28A71ULL, 0xD5CE36C3C376A9A5ULL, 
            0x83ADF5DF6820E51AULL, 0x995E4CCAC6313E30ULL, 0x26A9631A4C1ACB5BULL, 0x15006EA5E6DBE661ULL, 
            0xA69FF9BF71072C2BULL, 0x9958698DE9428DCEULL, 0xDEA0B6EB77FBD6B1ULL, 0xE1D943B03037F98FULL, 
            0xD046CDE8480932F6ULL, 0x93093F3B01A944ADULL, 0xE39216BB69350831ULL, 0x6E151A8A89A10961ULL
        },
        {
            0x8E37500BE81E49DAULL, 0x72F374BF37C8AE29ULL, 0x6CF773431D5D0E8EULL, 0x11CF947D7AF61650ULL, 
            0x9F871446A0DB7243ULL, 0x9123AA4AFBC97F5AULL, 0xABF1FA2EF4082236ULL, 0x207D12C50AD5115DULL, 
            0x5A46E1DC5910BAF0ULL, 0x4BB8628BBCE466D1ULL, 0x4734E5CE580C6F22ULL, 0x03435DE42A6E8D74ULL, 
            0x81BA3234B93BEA33ULL, 0xDD119DDBCA262396ULL, 0x8BEF6C5F0292CAB0ULL, 0x70C4F13942EFBECAULL, 
            0xD2A4FA6A09074CE0ULL, 0xDA61E85A1311867AULL, 0x6B6BD7DBA4C1522DULL, 0x0420A77E307BDABBULL, 
            0x3CBCAF5BA8BAE3D6ULL, 0xB9E65149DA62075AULL, 0xF894E21A7C6924C7ULL, 0xCBE7192AF98EFB87ULL, 
            0xA6D75E95955B5C03ULL, 0x0BEEAD666912B4D4ULL, 0x4078B981D790F41CULL, 0x80709704215AFEB4ULL, 
            0x5A5F7E75C2F501B0ULL, 0x015191D3302BA85EULL, 0x98B2D59D48856295ULL, 0x9C94450596A1681EULL
        },
        {
            0x05068775E6EF7F5FULL, 0xD382793CC0AA0F66ULL, 0x8F33DB242549389DULL, 0x8E7ABDEF81DB33AEULL, 
            0x2074A27AC8A45E9BULL, 0x4217BC86387F4CE0ULL, 0xDF305FAFAB57934AULL, 0x1E7136C60D7423EDULL, 
            0x9A64536C8FC3E8A5ULL, 0x1A83442D2B4C6434ULL, 0x6AEF8E21AA229AFDULL, 0x139E808560286D72ULL, 
            0xC7B423DCD55B44F5ULL, 0x016376AE385DD74DULL, 0x8A00B273DFFD1F35ULL, 0x64EA10AF17927D6AULL, 
            0x945301B0AD8D315AULL, 0xD9F36045D9F2E757ULL, 0xA72BDC6918B214AEULL, 0x1CCAA3FDAFBEFCFAULL, 
            0x75ED282776FE6154ULL, 0x37540209EF73AFFBULL, 0xCBBD41DF7245128AULL, 0xEDFA6FE8874B800EULL, 
            0x9D4DF4D94989D048ULL, 0x7E15CDD2572F9F0AULL, 0x19029764C210096BULL, 0xEB1E887E0E4FFB91ULL, 
            0xF64FCDE87B51DE74ULL, 0x5712384C10B3B376ULL, 0x10A8C4CA90F948A0ULL, 0x5372F72733AEB4B6ULL
        },
        {
            0x5F4F246B676EEAEFULL, 0xC66D482253571B48ULL, 0x783D8F5674925D4BULL, 0x594BD11528771F05ULL, 
            0xD5BDE931516CD053ULL, 0x7E426D86D6A51066ULL, 0x9E9C12FD69344B2DULL, 0x335F683A8CAD0DC5ULL, 
            0xC7FAA2A1CACD9CB2ULL, 0xD88283AD843D8085ULL, 0x0907BB1D25F271FCULL, 0xFD0D3AB51460355BULL, 
            0xC886852EF47C83A5ULL, 0xA588EF3069DB84D9ULL, 0xAE0C4DE851387F0FULL, 0x9A386615B8CFE392ULL, 
            0xD1FDBB6495A6FEFEULL, 0xAD0A29F2BE11397FULL, 0x2EBED69FFB354A33ULL, 0x04136A0227A02EF3ULL, 
            0x5294AA4ACBBD933DULL, 0x5887E1CBBBE61FCAULL, 0x681620FBB8555E1AULL, 0x0A3C75877C88C9EDULL, 
            0xA85CF88F15F09F14ULL, 0xBB494D4054E4DB90ULL, 0x4B27092183CD1207ULL, 0x3E2D5304A3F8D0BCULL, 
            0xB3E78DC7C0B71F37ULL, 0x5574119D006C80F6ULL, 0xE0C645B52AF392B5ULL, 0x2F147AEFCE805FA1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Billiards::kPhaseHConstants = {
    0xFA7F7DEE75021755ULL,
    0xF1F64FD7EF4BD0CFULL,
    0xB3E2697A6374FC9AULL,
    0xFA7F7DEE75021755ULL,
    0xF1F64FD7EF4BD0CFULL,
    0xB3E2697A6374FC9AULL,
    0x7F555733789D3ED6ULL,
    0x0BC071CB1B784D3BULL,
    0xAC,
    0x30,
    0xC9,
    0x8B,
    0x84,
    0x66,
    0x62,
    0x44
};

