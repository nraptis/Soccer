#include "TwistExpander_Vega.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Vega::TwistExpander_Vega()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Vega::KDF_A(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xB3F47E8C18570D47ULL; std::uint64_t aIngress = 0xA18F922770029AB6ULL; std::uint64_t aCarry = 0xF99977E639198F11ULL;

    std::uint64_t aWandererA = 0xFA5EDE79FA5F117CULL; std::uint64_t aWandererB = 0xAAA9982C1AB4DC74ULL; std::uint64_t aWandererC = 0xEC93805BFE3B9388ULL; std::uint64_t aWandererD = 0xD19FA70AB0F614F8ULL;
    std::uint64_t aWandererE = 0x8697B07915E21422ULL; std::uint64_t aWandererF = 0xCF5803A2B00A98DEULL; std::uint64_t aWandererG = 0xCEA852FD82534073ULL; std::uint64_t aWandererH = 0xA990DEA4070609B9ULL;
    std::uint64_t aWandererI = 0xA2C8A76B3C4C497BULL; std::uint64_t aWandererJ = 0xA68454353A9125CFULL; std::uint64_t aWandererK = 0xC0A01EF73F3712FEULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD6763E263404278EULL;
        aCarry = 0xB0F43FEB330E022CULL;
        aWandererA = 0x9A905A064541D5B9ULL;
        aWandererB = 0x95444EA3CB7F3642ULL;
        aWandererC = 0x8E83AA8E36B36443ULL;
        aWandererD = 0xD517FAABF78BD10BULL;
        aWandererE = 0xD987B8AB81A1FEB7ULL;
        aWandererF = 0xB117912CFD306062ULL;
        aWandererG = 0xE08C3A2F1EAA6C30ULL;
        aWandererH = 0xB9EE3C47A28B692FULL;
        aWandererI = 0x86BCA56911524CB0ULL;
        aWandererJ = 0xB39F2B5AF9BA6867ULL;
        aWandererK = 0xC182D049A9D0D06BULL;
    TwistExpander_Vega_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Vega_Arx::KDF_A_D(pWorkSpace,
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

}

void TwistExpander_Vega::KDF_B(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr)) { return; }
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xC47D023C9F78DEFDULL; std::uint64_t aIngress = 0xC99074C5108988E9ULL; std::uint64_t aCarry = 0x8EB687F12118337BULL;

    std::uint64_t aWandererA = 0xC45E4265940C0DADULL; std::uint64_t aWandererB = 0x9AC52E45C5306DB3ULL; std::uint64_t aWandererC = 0x892D6F97D4B1EE4DULL; std::uint64_t aWandererD = 0xA8CB1929E2F220B2ULL;
    std::uint64_t aWandererE = 0xCEA05142CE76E24DULL; std::uint64_t aWandererF = 0x90ED21D04C74803AULL; std::uint64_t aWandererG = 0xED670FBB9E2CBD86ULL; std::uint64_t aWandererH = 0xC5BA8B06C7FC06A4ULL;
    std::uint64_t aWandererI = 0x8651CA4710AF219FULL; std::uint64_t aWandererJ = 0xCE2D57799398328FULL; std::uint64_t aWandererK = 0xD78B836C0439FCF0ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB7CE23495A0E12A3ULL;
        aCarry = 0x90787B9891D15433ULL;
        aWandererA = 0x9139C65C600397A1ULL;
        aWandererB = 0xB2611C60AEDAD9D5ULL;
        aWandererC = 0xC43186F15C5B1414ULL;
        aWandererD = 0xB52A1284736305D3ULL;
        aWandererE = 0xAEE9E9A8487DD30DULL;
        aWandererF = 0xBA9F3BE9C2D37AB0ULL;
        aWandererG = 0xC2546C73537373B5ULL;
        aWandererH = 0xA349FF76259F1A05ULL;
        aWandererI = 0x961DEE22493457D5ULL;
        aWandererJ = 0x92CCDA3F51BDF3C3ULL;
        aWandererK = 0xCDE7C3F36B3F0686ULL;
    TwistExpander_Vega_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aPoisonLaneA, aPoisonLaneB, // output lanes
                         aSpiritLaneA, aSpiritLaneB, // index shuffle seeds
                         aSpiritLaneC, aSpiritLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aPoisonLaneC, aPoisonLaneD, // output lanes
                         aSpiritLaneC, aSpiritLaneD, // index shuffle seeds
                         aSpiritLaneA, aSpiritLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Vega_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Vega::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint8_t *pSnowLaneA,
                                 std::uint8_t *pSnowLaneB,
                                 std::uint8_t *pSnowLaneC,
                                 std::uint8_t *pSnowLaneD,
                                 std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pSnowLaneD == nullptr) ||
        (pDestination == nullptr)) { return; }

    UnrollPasswordToSource(pWorkSpace->mSource, pPassword, pPasswordByteLength);
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleEphemeral.Zero();
    pWorkSpace->mDomainBundle.Zero();
    std::uint8_t *aSource = pWorkSpace->mSource;
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8BC75A9F1D07EF90ULL;
    std::uint64_t aIngress = 0xB23DEEEA48F7E5DEULL;
    std::uint64_t aCarry = 0x846E52DDEC0D7AAFULL;

    std::uint64_t aWandererA = 0xE57F5E9FFD6EFA41ULL;
    std::uint64_t aWandererB = 0x8DEFA094AA6CB394ULL;
    std::uint64_t aWandererC = 0x9CE5ECCEE9100B66ULL;
    std::uint64_t aWandererD = 0x923D3B38CBC93703ULL;
    std::uint64_t aWandererE = 0xBD89E32741C3DA1CULL;
    std::uint64_t aWandererF = 0xAD17335E4DFA209BULL;
    std::uint64_t aWandererG = 0xBA28D013283EDCCFULL;
    std::uint64_t aWandererH = 0xB392C78B61B974B2ULL;
    std::uint64_t aWandererI = 0xFCD66B0209F58685ULL;
    std::uint64_t aWandererJ = 0x96C1C09FF39D13CEULL;
    std::uint64_t aWandererK = 0x8F5BA66539875D8DULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneA, 0);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
    ////////
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneB, 1);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
    ////////
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneD, 2);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
    ////////
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneC, 3);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
    ////////
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    // GSquashInvestToKeyBoxes (start)
    SquashInvestToKeyBoxes(pWorkSpace);
    // GSquashInvestToKeyBoxes (end)
    //
    TwistExpander_Vega_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Vega_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aSpiritLaneA, aSpiritLaneB, // output lanes
                         aHeartLaneC, aHeartLaneD, // index shuffle seeds
                         aHeartLaneA, aHeartLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aSpiritLaneC, aSpiritLaneD, // output lanes
                         aHeartLaneA, aHeartLaneB, // index shuffle seeds
                         aHeartLaneC, aHeartLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Vega_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Vega_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B(pWorkSpace,
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
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

// SmartSquash candidate 33 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 910 / 1088 (83.64%)
// Total distance from earlier candidates: 29692
void TwistExpander_Vega::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 583U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1228U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1625U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 954U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 496U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1114U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 387U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1585U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1057U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 991U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1509U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 324U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1596U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 120U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 340U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1164U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1394U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1903U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 441U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 837U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 506U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 388U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 924U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 60U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 366U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 477U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 604U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1167U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1671U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 308U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1368U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1817U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 21U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 491U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 478U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 134U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1210U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 4U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 284U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1604U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1314U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 940U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 329U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 75U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1774U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1144U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1106U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1782U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1674U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1886U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1614U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 582U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 741U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1498U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1819U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 235U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2013U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1861U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1357U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1094U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 227U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1987U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1283U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1448U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Vega::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pSource, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xEEB152FFA9C1F02AULL; std::uint64_t aIngress = 0x91B4CB855849697BULL; std::uint64_t aCarry = 0x9BA96DC3064572CFULL;

    std::uint64_t aWandererA = 0xCD25CD212928BB33ULL; std::uint64_t aWandererB = 0xDB98320DE3172274ULL; std::uint64_t aWandererC = 0xC46C4BE7E953EB8CULL; std::uint64_t aWandererD = 0xBCCBEAFA357F4C0BULL;
    std::uint64_t aWandererE = 0xBB7FA3B455D5C827ULL; std::uint64_t aWandererF = 0xF2E12D72CF5C8D07ULL; std::uint64_t aWandererG = 0xA42D2EC13D19794DULL; std::uint64_t aWandererH = 0xE5BAC507AAE20AABULL;
    std::uint64_t aWandererI = 0xEDFC3FD9C424C8D8ULL; std::uint64_t aWandererJ = 0x836EF2E254186843ULL; std::uint64_t aWandererK = 0xA3CFA5D866B1F2BDULL;

    // [seed]
        aPrevious = 0x88469A408C51910DULL;
        aCarry = 0x88F6B5B1DC6C9A0BULL;
        aWandererA = 0xA5C796D57B7AE420ULL;
        aWandererB = 0xAA36A14258DF3DAAULL;
        aWandererC = 0xC7848F557C5B7967ULL;
        aWandererD = 0xEE758DC70E9A5442ULL;
        aWandererE = 0xA6D0565F9917B3E9ULL;
        aWandererF = 0xF6B6F06AF7B2FE8CULL;
        aWandererG = 0xEDF5EE97EBCCCDAFULL;
        aWandererH = 0xE63329DE8D7DD47AULL;
        aWandererI = 0xD1FA442D95386E21ULL;
        aWandererJ = 0xCB449746236B6E0DULL;
        aWandererK = 0x8B778C3DC52752C8ULL;
    TwistExpander_Vega_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Vega_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    TwistExpander_Vega_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B(pWorkSpace,
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
}

// GrowA candidate 33 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 17279; nearest pair: 473 / 674
void TwistExpander_Vega::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyA expects four expansion-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyA expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2984U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2812U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 201U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 614U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3462U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7521U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1886U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6658U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3770U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6880U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3398U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6835U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6661U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5466U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 457U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 685U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1671U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1370U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 355U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 799U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1400U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 585U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 102U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 293U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1410U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 800U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 421U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 819U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 60U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1613U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 33 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 17275; nearest pair: 444 / 674
void TwistExpander_Vega::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyB expects four operation-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyB expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7654U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7486U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3337U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6485U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6750U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2650U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5932U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5267U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4727U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3464U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3923U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4315U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5297U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 405U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 863U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 268U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1347U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 132U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 525U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1710U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 29U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 495U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1936U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 66U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1620U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 204U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 281U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1182U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1383U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Vega::kPhaseASalts = {
    {
        {
            0x45FB1E2CAC9A3228ULL, 0x1FC31C4FA81937AFULL, 0x2D2CCAECCAF0C4CDULL, 0x961C0DE83BB9394CULL, 
            0x0702B1EEF4A8BDF1ULL, 0x47E73D3F297A75E5ULL, 0x549638256B72D95AULL, 0x63EB5D1C2C303BE3ULL, 
            0xF223176A30657E38ULL, 0x6FC91F4767FE189CULL, 0x09188E1AF63B4801ULL, 0x97872987CD987E2CULL, 
            0x347FC8882E91CDFAULL, 0x2C8D9D292E701EF0ULL, 0xF78F69D1EB2F1E70ULL, 0x5DC50216D7A090C6ULL, 
            0x0957B94F447E9FE5ULL, 0xF3C29257045C5A46ULL, 0x945678FDD23C1DF0ULL, 0xF01E2E7736627C0EULL, 
            0x625006778661D8BCULL, 0x44CFA69EE73B13BBULL, 0x6B77C8A5FA671600ULL, 0xA8D3F28D9BDE6C78ULL, 
            0xE99B0AC3778C1A5EULL, 0x777DA1D311369048ULL, 0x393C433C6211A6ABULL, 0xE3F1BC282F613423ULL, 
            0xC69A9EEB17773963ULL, 0x19C0A04D5ED1D139ULL, 0xC51333710CDFC186ULL, 0xF4A498738423AF43ULL
        },
        {
            0x538E43F383941FFCULL, 0x9899AA4210FA1530ULL, 0xFD3FA837FD14F0AAULL, 0x980D0ED8B2E52864ULL, 
            0xE93833618F5B4658ULL, 0x97FA6D3C7FEBA695ULL, 0x36B6FDEDCACFE923ULL, 0xEDD904EEE3AE663DULL, 
            0x4C801CD40471E96CULL, 0x3847560648DFBFF2ULL, 0x421F32005FB640DDULL, 0x369B7BD3BF6A5CF0ULL, 
            0x8274DCD120E2ACDFULL, 0x137284995D910D7AULL, 0x61D5441C78C6D723ULL, 0x3BECDECE4E9CBE5EULL, 
            0x80445D3E8D18BBD6ULL, 0xB6956EB49381C3B8ULL, 0xFDD6B13F3376ED11ULL, 0x1A19D9713565C0D8ULL, 
            0xABE92D7DA5B48600ULL, 0xD20EB8B1EDA8B8A9ULL, 0x22809842E9FC7060ULL, 0x91DBCD21F0B3E691ULL, 
            0x85E618228BD05C76ULL, 0x8A55A31C6A41D42CULL, 0xB6BDD70A796A17F0ULL, 0x8E1B8C637D677374ULL, 
            0xEA4762877AD4F2D8ULL, 0xA5F73CB72E3BA623ULL, 0xC1CD39AC3E8C8844ULL, 0xE417625430A3B991ULL
        },
        {
            0x6D7EB5B3E8F012E9ULL, 0x8F5511CCC77760D3ULL, 0x37C014CA7E610DAAULL, 0xC61E01A5B50BBD51ULL, 
            0x4CE2681656D6F99BULL, 0x5AF8560BE46D2F0BULL, 0x6957827592F591B4ULL, 0x8E685BD20A77BA47ULL, 
            0xB1B75DA8D8DC079BULL, 0x13350643BAFB49F0ULL, 0xD9D582D9F6E99CC1ULL, 0x5C29462F0FA7C1A5ULL, 
            0x6BB0BEF4C8973A37ULL, 0x2D86869441EF17CEULL, 0x02FA28226EC19A9AULL, 0x40749E0C781D239CULL, 
            0xB33C3D233480D076ULL, 0x942E35BD1255D88CULL, 0xDDDDEAFA87D88335ULL, 0x9AABCA2CBE4E911DULL, 
            0xE5FB9773C42CAE15ULL, 0xDE1D9C7992FF8579ULL, 0x6DF7C7242B3FB5DEULL, 0x7180498A9B3B1FB4ULL, 
            0x33DE2ECFA806A39AULL, 0x3D8404A160D9C1A9ULL, 0xCAC79A498A3A4C94ULL, 0x2A4DE0715440C9A8ULL, 
            0x23192B9B4E179A65ULL, 0xF45C72E09CE5604EULL, 0xC8FD9D6E294B13ACULL, 0x579D53CB6034EEE6ULL
        },
        {
            0xD905A037C22372BDULL, 0x9A1E730F7927B482ULL, 0xE7DC4E00992B65B5ULL, 0xA5964EB384829F20ULL, 
            0x5D79633D35585A37ULL, 0x0C281CF72CF8260DULL, 0x27D99A82EBCD1FEEULL, 0x2C56B24FA6361560ULL, 
            0x643EFAF82153B836ULL, 0x523150C3E83E263EULL, 0x94F774E0E7D07ADAULL, 0x68C88C3C8075E7D1ULL, 
            0xAA4A12239C2CC50AULL, 0x0E07740138C1028FULL, 0xA4349976AC3CBC21ULL, 0xCB96DCBE75CCE6ACULL, 
            0xDD8D0C57813EC758ULL, 0x124D4730C8D59676ULL, 0xC227FAEB6FB21D67ULL, 0x3406AF867ED9310BULL, 
            0x9068D223D2BCA088ULL, 0x912C5BAF5E819050ULL, 0x7A49A6199115C880ULL, 0x6D1A0E7B98B1D899ULL, 
            0x5C883E589913A951ULL, 0xEE013F7BCDDF60C0ULL, 0xE1092D7EB09131FCULL, 0x84988DD109FB2AF4ULL, 
            0xE6EC1A94EBC6FA11ULL, 0x7A448A68C2B0DCE7ULL, 0xBFF8915ED9DFDB8DULL, 0x004D6C538768A9B7ULL
        },
        {
            0xC5E350F5C40EE7C2ULL, 0x35E5290CE79A5FFDULL, 0xFBF987D410858EC4ULL, 0xE0BA846C1BBD911EULL, 
            0xC107D2C584EAF461ULL, 0xA3560ED4A751CCE7ULL, 0x9996B26C0FAB6AE1ULL, 0xDBFF23CC0356CE4CULL, 
            0xB31D8504647AE803ULL, 0x761A853F954EDFF2ULL, 0x545EF91357B54F1BULL, 0x31437662D468E5F2ULL, 
            0x47F520606A710B46ULL, 0x88B7FCD8D8493658ULL, 0x13A156586E2B342BULL, 0xAA1CFC50EC97E9C5ULL, 
            0xDF206B4C34BA3075ULL, 0x55DD2E4062B0219AULL, 0xDE4884FEDFC83F1FULL, 0xB265784277E24A1CULL, 
            0x0FBCC21066B8FE8DULL, 0xCC60417C4DB82F25ULL, 0xE7C705E228FDA075ULL, 0xB4052F61696A16FCULL, 
            0x28258CE0261D7858ULL, 0xD93537A3435E003BULL, 0x8FF240B1076EE34EULL, 0x636568E42474E38FULL, 
            0xCAC03BBE41CC43B1ULL, 0x9830FBF166AD8A9AULL, 0xC6EFDA5834938863ULL, 0x16CD575D29B9C8B9ULL
        },
        {
            0xE885B488EEE41DEDULL, 0xF081FDAC615BC2F0ULL, 0xFC70AAA0D4891787ULL, 0xBA41E9A3CE744E4FULL, 
            0xC01781B0590096B6ULL, 0xE6FCBA0F592255BEULL, 0x06EC2947124D6D2FULL, 0x35B97FF61FCD0636ULL, 
            0x5181A7647EC2EC75ULL, 0x2DA545ECD236D751ULL, 0x9545812A70F97017ULL, 0x220F7F9F72CDA6E5ULL, 
            0xDCBCC025554317CFULL, 0x78EF6E7E5EA8911DULL, 0xDF014F3B5EFB0CD5ULL, 0x0EBAC0BD6349E7E5ULL, 
            0xEEC365BC34007533ULL, 0x9DCF01592294EAA2ULL, 0xAA70725D60FCE937ULL, 0xC74CE9F8B27CD318ULL, 
            0xFAA7779DB52CCAC1ULL, 0x7E01A978B1711D83ULL, 0xCD6A28AEB3DE9CBCULL, 0x4926467964CF9E1BULL, 
            0x16916DA32442DE5DULL, 0xC03842B56D8C24FFULL, 0x7DF26399B1ECFC67ULL, 0xC12B9BDCC60569A6ULL, 
            0xB6CC65D1EF8DF5CCULL, 0x00016362A9E6B261ULL, 0x10645723CD132C57ULL, 0x665CC645CB60BC39ULL
        }
    },
    {
        {
            0x642C4E4249B517A9ULL, 0x0EB9E48966903D72ULL, 0xA3C17CC6C2E6FB5BULL, 0x8DDDB3AD2D9C1758ULL, 
            0xF85BAA2B5111F0D1ULL, 0x94FCB1515233224FULL, 0x4B8F2530705226E3ULL, 0x8FB1EE0C4B3DCFB0ULL, 
            0xE031E86FA4839D27ULL, 0xFEBB0304C6FCB477ULL, 0xF2D162F04E036695ULL, 0xE5A4A0D64379733DULL, 
            0xDE14656E8F2DD8E1ULL, 0x89737834057F8D26ULL, 0x4877D797AC496CD0ULL, 0xF3EEC446564BE1BDULL, 
            0x94DC93D18A4C17EAULL, 0xAD67A5B6EE3AEBA9ULL, 0xD4F4FAF08DBC980EULL, 0xCC72C48580F54CCEULL, 
            0xA85495A5D1F5A6E6ULL, 0x27733389B14310ABULL, 0xD452EF4D4F9650A3ULL, 0x3632E8C0B04E7A11ULL, 
            0x46631E5E85D8EE33ULL, 0x25302E4F4002E3CFULL, 0x0625533D8B4781EEULL, 0xEA6E0EB962A8F167ULL, 
            0xA487960A26AF2510ULL, 0x2BFA6706A96C37CCULL, 0xB29FD1E9273CD66AULL, 0x460A580B0B3BE5E5ULL
        },
        {
            0x7156C8D3D07F815DULL, 0xEEDF29743068D6A4ULL, 0xA6433758BB8CDE0FULL, 0xCD7300AE90FBCABCULL, 
            0x3600FA24EB8126B1ULL, 0x0FC6F0151A6D80DFULL, 0xEEDA0EF562CA16FEULL, 0x05D6C4D656D58871ULL, 
            0x39597D205A3E2E18ULL, 0x62087811401D7D1FULL, 0x36BF8856CC53C2DBULL, 0xD84D72B3D283A767ULL, 
            0xC4E26FCF7F0918B8ULL, 0xF43F601C3AA4DE08ULL, 0xA13E4CFBFD5C8698ULL, 0xF6825637D94E7930ULL, 
            0xC61C3D06E037B41EULL, 0x7AB2D2D09BF90A71ULL, 0x78870D559CA9D17BULL, 0x9687C12A812C293EULL, 
            0x10080BE362096DC6ULL, 0x45083EFC457C354FULL, 0x7347CFC6B0DDC18DULL, 0x20F2DD0094CDA7F7ULL, 
            0x52FB098DEA0259C7ULL, 0xCE992C888A1101EAULL, 0x3A157BA9C5D6D53CULL, 0x92AA030F3EADB605ULL, 
            0x0B7CDBE3064FCEB2ULL, 0x29BEA909B5B46DA2ULL, 0xD28B569DD4509C57ULL, 0xAE19CBD01833BF4AULL
        },
        {
            0xCCAE700D6A3266F3ULL, 0x354A02D26A6BA448ULL, 0x408F58E5E9E71481ULL, 0x434B6A69078C8595ULL, 
            0xBBB2F03C92184FD2ULL, 0x879ED0B30BAD4032ULL, 0x1AD7F06841C93AFBULL, 0x2AC8A1009203F051ULL, 
            0x32D11C3168729342ULL, 0xDBFEE60DB0C51A98ULL, 0x9B54020B821EEECAULL, 0x27DE399634E1F6BBULL, 
            0x4A2C231EA297723DULL, 0x85FE42DA370F915CULL, 0x7F364FF486025BCBULL, 0xD5DD9F77E6FA3A64ULL, 
            0x5ECB1D67571D1BD1ULL, 0xCF641B38D85E901BULL, 0xF6A16E901F9C8AD8ULL, 0x920D1C849EEB7EDFULL, 
            0x9FA9102D6A4D385DULL, 0x104C55C87EB15883ULL, 0x1EE46ABB26E2485BULL, 0x743756522B6A32C6ULL, 
            0x0FE9B219850CF052ULL, 0x2143AA687BA61160ULL, 0x496B7C943EE79FE1ULL, 0xE6EE5109D744B77CULL, 
            0x88B707B554EFE986ULL, 0xC51DDDB757576FC3ULL, 0xE53FBB0E28F96CE4ULL, 0x158734F57563DB33ULL
        },
        {
            0xFFB2F09ED43B0D27ULL, 0x67D6DD1315400E8AULL, 0x9170009351EF33F3ULL, 0x0DA06B72087C5F7BULL, 
            0xDABF564B13C51186ULL, 0x3A424093E0ACBA5BULL, 0x678743C65B7572EDULL, 0xA1554E4A6A597BDDULL, 
            0x035F0D38F5617C86ULL, 0x99A233925EC6112CULL, 0xBA0E9848CFEE475DULL, 0xE8B9B08508916050ULL, 
            0x928B1E451CE92152ULL, 0xEFE78E952EFE003FULL, 0xA35FFB0A6E435F14ULL, 0x564510005EA2F420ULL, 
            0x3C309C45DD83E84EULL, 0x7B9B4BA795CBB59AULL, 0xDD2395702DAA46E7ULL, 0x0F611D685B554A13ULL, 
            0xA7033749BC80C1B1ULL, 0xDFD21FCBAA5CFED4ULL, 0x2EDA91EF5DF1EDD3ULL, 0xA58F4F13D5977F5CULL, 
            0xD332A6F4D5084BDAULL, 0x8473879D54D63AB8ULL, 0x7C518AF4AC7E0E6DULL, 0x7B1B8547E6121103ULL, 
            0x66489DB991708867ULL, 0x89B40631B51F28C5ULL, 0xB829ADDB2B8B751CULL, 0x00E5AE426CFAF03DULL
        },
        {
            0x1D70D3D78BE6E2BAULL, 0x5F34EDC1807DEEB2ULL, 0x940987DE73DFC020ULL, 0x56327FF453ABF32DULL, 
            0x31887FFB2E31805CULL, 0xECDDE69FCCAE2F51ULL, 0xBCE8E7F48E5CA853ULL, 0x5F1754FDA5376F65ULL, 
            0xE02F6A9963092373ULL, 0xE9B85B4810857159ULL, 0x9D5DA4EA09A87BE5ULL, 0x68F16939050DB3C3ULL, 
            0x6C98C36799FBDC10ULL, 0xA4058CC3BA017FBDULL, 0x64E4312C6BA35D87ULL, 0x48992F8C184CEFA5ULL, 
            0x53772B002CAA92B5ULL, 0x24BAFD50DA77E248ULL, 0x25053575AEB975D9ULL, 0xCA6A7C84A6102848ULL, 
            0xD35F58726CFBCD44ULL, 0x5B2BC89D3F28B9B6ULL, 0x5EF2220A1872EFE1ULL, 0xFB695438DC495A8CULL, 
            0x762B0CBCE816F14DULL, 0x6BFD7C7AC1B15747ULL, 0x44BE784F263E2B67ULL, 0xD7AF69F39DB87013ULL, 
            0x1F23B46BF29A2EC3ULL, 0x93EBB3CEEC93601EULL, 0xB63D192AEBF15EC2ULL, 0x005B65E836797B98ULL
        },
        {
            0xB131A0A2DF002004ULL, 0x4D1ADB6546328C85ULL, 0xE00133AD67C54C3BULL, 0xFFD57E07C13521E6ULL, 
            0x90027B1006F389CAULL, 0x1BD4B530549909ACULL, 0x433CFE8966EE7C0AULL, 0xD307690437519AECULL, 
            0xF683DE842005CC9CULL, 0xB17C33C0B0CB34AEULL, 0x9446FB25424C21E0ULL, 0xACFB8D0FBB3B2550ULL, 
            0x185B18277BFEA8CBULL, 0xBB33FF5AB5CA26A1ULL, 0x2FC85D62C226C5C7ULL, 0x90C2B455ABB48A2FULL, 
            0xC1A74D2D10E3F854ULL, 0x98506E005C1BB0C1ULL, 0x68E735155CE56B93ULL, 0xC1757C6DB80F098DULL, 
            0xAEAFD1C0144387D6ULL, 0xA043AE88DA15C85BULL, 0xD8068DBF814E5DE9ULL, 0x8795A2EAE56070EAULL, 
            0x177ED232A2B404DEULL, 0x83AA6E8CB94081CCULL, 0x4037F3C40FD5930BULL, 0xC98D70794198EF45ULL, 
            0xCF11F5BD27552945ULL, 0x5ED3F4F75CA773F3ULL, 0x3103F0686252E1D0ULL, 0x3E7AA846B89DB902ULL
        }
    },
    {
        {
            0x78484CAA3CB16262ULL, 0xD92FE64F47D93266ULL, 0x5EE3D3F6A67D36BCULL, 0x65FAFC428682CE8AULL, 
            0x53AE5DAEDA95F97BULL, 0xB26BF8E6B95713BAULL, 0x369AC3F20F6812E5ULL, 0x1184D99968B6AA7EULL, 
            0x36882CFD84E89228ULL, 0xF8B3351F00D50C23ULL, 0xD0B091AA02BDEBBBULL, 0xDCE5D7A42984568FULL, 
            0x302676EE0D38DB39ULL, 0x1A78643A9444F3C4ULL, 0xD8D611B066052E37ULL, 0x025E4BB3141F50FBULL, 
            0xD4B9ED7AA8AE5C8EULL, 0xF6447F069788F29FULL, 0x8058B7010C8419FEULL, 0x9B2FC87B1B968FBFULL, 
            0xE4DB2DC64B316F1AULL, 0x5D8E7966996BED62ULL, 0xA50E96E88D853C24ULL, 0xD4A33E36613435B1ULL, 
            0xCE41697C14CF9ABAULL, 0x17A5A0078E8EC565ULL, 0xB6B6B397904D6C41ULL, 0x0BF1C0536849AD74ULL, 
            0xABDBACFFA5DAB7C1ULL, 0xDF050B3F49ACA4CEULL, 0x358BF879C3A46E69ULL, 0xA4AF6603484355ABULL
        },
        {
            0x8FD6DA5DEFF08C21ULL, 0xDE08909839738B22ULL, 0xF9C2BCC679EEECCEULL, 0x76257D6A834970DDULL, 
            0x9E391C9D86F7DDF8ULL, 0xA456D235EF52F460ULL, 0xEE22AF432D701491ULL, 0x8E64B11750DAF641ULL, 
            0xB40028A49006EE4DULL, 0x944A42AB818EDCECULL, 0xFFFC064876137B11ULL, 0xEF356F7EF6508B15ULL, 
            0xFF2146DF9596CCE5ULL, 0x2762F29EFE9EEBC3ULL, 0x77D361EC49D3E00AULL, 0x3FE11E74212401FEULL, 
            0x82FF1C205822E0D1ULL, 0x1B625D177FBAD131ULL, 0xF1F9DBC5922E40B3ULL, 0xECA5B4565BFEA6C2ULL, 
            0xA0DBF8C029DCE107ULL, 0xD3DAA63EA7DC96EDULL, 0xC0E142C35F90505EULL, 0x13F52E8B0FA3EDC3ULL, 
            0xA77A3BCE9686D3CBULL, 0xB17806508698BF30ULL, 0xC3987CFB8307FFC4ULL, 0xFFB7433CAD98A012ULL, 
            0xEE8E6CE08E31AAC7ULL, 0x523069E15F695EF7ULL, 0xEBB12F553ADF9990ULL, 0xA06BEC7C5CCDB696ULL
        },
        {
            0xC281D4012C768680ULL, 0xF9BA154F7FB4FB41ULL, 0xA3EFFEFC835D2686ULL, 0x2E6C05FE60D65286ULL, 
            0xE00DF7E9AE624F6FULL, 0xE02E41DA9E3B4090ULL, 0xA745109C0D756F12ULL, 0x919699D229F6AEA9ULL, 
            0xC60F436448C82100ULL, 0x2E47D484BA7671A2ULL, 0xB216CBC4BC38AA1FULL, 0xDD2F3154EEE5BFD2ULL, 
            0xBDD570E8A6789D6BULL, 0x51B48B561EC2D2D0ULL, 0xFD393A50C354BA31ULL, 0x05E1082298AA69A9ULL, 
            0xFB7179605A2BC7B0ULL, 0x7FEFB3088828736CULL, 0xF9DF1C1438F77818ULL, 0xD200A3EB62D6406DULL, 
            0x912FC1AF4580976DULL, 0xA8EFA45A68191768ULL, 0x51DD8A0CDE55B51AULL, 0xACDEA6752A0C63BFULL, 
            0xDB9B9F9A484ADCB3ULL, 0x5F6513FC9F09ED1CULL, 0x9F30BBD52CB2F931ULL, 0xD9C83E78670873BEULL, 
            0xF4A2DD589EB3B849ULL, 0xBFE581A09B9D061CULL, 0x3DDFBAC55724E419ULL, 0x72D01AFFFD17FB6EULL
        },
        {
            0x1F85B97623E8457FULL, 0x8D0A198F0FC634C7ULL, 0xB26D313F2A300F84ULL, 0x2019047BCE56826CULL, 
            0x662B1E14DFDF099DULL, 0x17B376EE3405C1D4ULL, 0x501734CB116DDC38ULL, 0x6DD442B5BDC988E1ULL, 
            0xC5C3901EFC0419F9ULL, 0x12197680B8A170BFULL, 0x6F9B0CD467CE6FE8ULL, 0x0F217E7609CDFA01ULL, 
            0xE72CE3D8BB963BD5ULL, 0x57F0D9043EA24428ULL, 0x9EDA7D9D96A8FBE9ULL, 0x029C05D2A1C069A5ULL, 
            0xBD01437CFF21B3F9ULL, 0x7CD251C01FC655EFULL, 0x622DDB2A4DCEB7FAULL, 0xB36F4F5F74D16AF6ULL, 
            0x041E568E99A24173ULL, 0x278865903D2D416EULL, 0x9FE28D2627648DD0ULL, 0xEF70194A121FC1B7ULL, 
            0x42D7687B006B24EAULL, 0x095B2562C1CE95FFULL, 0x507738775FE99C3BULL, 0x29B28637E547EC05ULL, 
            0x8A76D2C9BDA09238ULL, 0x4042DE8182325AF9ULL, 0xD36F0D8E4B265179ULL, 0xABDB3FF4B0F96E2DULL
        },
        {
            0x6321AF6904B70C31ULL, 0x962C1F7FC764578EULL, 0x6B677DD78EFADFADULL, 0xB861153CA7E59F50ULL, 
            0xA2CB3BA3C266D4F0ULL, 0x7DCFD0B3725EBB1DULL, 0x7AEBF34266432E42ULL, 0xE4DBD12ACB49B843ULL, 
            0xF6282AEB571458B8ULL, 0xE3F34B53F4F272D8ULL, 0xC1EE2DFE56DC5628ULL, 0xBE61A546C345EE85ULL, 
            0x379580A75F7433FCULL, 0xE0055F7871C28E70ULL, 0x47B8439B3E99D26CULL, 0x9FEA340060D90BFDULL, 
            0x39747D4F9D099AAEULL, 0xCEF9E48BBAE547C6ULL, 0x0105348F2134FC82ULL, 0xCE838DAC30B56D08ULL, 
            0xAAEDB413203BD9B6ULL, 0x59775B9F2E7A99A8ULL, 0x878C4057D866B4E3ULL, 0x7BF31629A0CE38FAULL, 
            0xECD5656445996F3AULL, 0x12A0991EDB47368FULL, 0x850B5E07FEB91715ULL, 0x8BB7005D768F0B19ULL, 
            0x635FB9E02192BE37ULL, 0xCDB1BBDB12FA38B5ULL, 0xCE64B0E1EAC33F65ULL, 0xAA6E791119B5C6A5ULL
        },
        {
            0xA7850E312638F8AEULL, 0x38956901703C57C0ULL, 0x1B90BEE2A2280062ULL, 0x98A56AD2B45E1402ULL, 
            0x6D6FD5DFB439B8C0ULL, 0x353787A9B7385F83ULL, 0x20F8A365609898CFULL, 0x9C4CB42E608DF07EULL, 
            0x7D86E10DE2CCDFF0ULL, 0x4D91674E2526D89DULL, 0xDC7B88E44949B6F4ULL, 0x73DABBEB9089F35EULL, 
            0x189B4EE09F4B83D7ULL, 0x844383D2F1BF18B2ULL, 0x9C43B0E12AFD27DBULL, 0xB99EDF1E08B2F140ULL, 
            0xBB41EF6FFAB62FA8ULL, 0xC7E909F83A3E0CA5ULL, 0x48FEE2200367D22FULL, 0x2B84D5517EA083C9ULL, 
            0x44553E781EFC6475ULL, 0x698F414303DAFDC1ULL, 0xB730BC198037D317ULL, 0x98905EAE112BD3C7ULL, 
            0x7797F01B182E556CULL, 0xD4EDBD7164FD07F4ULL, 0xF005E872E5B2153FULL, 0xCCCEFA337F2FDC0FULL, 
            0xB19B2C8999E32FAEULL, 0xE59272D4F0120A34ULL, 0xF5DD73251152C250ULL, 0xEFA7600050F62C29ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kPhaseAConstants = {
    0xADC118733DAB48DDULL,
    0xA1F9E4DB0EFDDDA9ULL,
    0x7CC4A1C6D1BDE0AFULL,
    0xADC118733DAB48DDULL,
    0xA1F9E4DB0EFDDDA9ULL,
    0x7CC4A1C6D1BDE0AFULL,
    0x7C96CA3AAC2E7B38ULL,
    0xFCC7FB450D219AB9ULL,
    0x07,
    0xE6,
    0x7D,
    0x5C,
    0x2D,
    0x85,
    0x7F,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Vega::kPhaseBSalts = {
    {
        {
            0x1CBEFBCB335FA692ULL, 0x430706BC9EF13FD8ULL, 0x87F8BBF9CCF296CDULL, 0xEC3AB5836D7BDD06ULL, 
            0x6BFCAB11AE82400EULL, 0xC8D765808AEB1F0BULL, 0xB7B3FFF962F1B5ECULL, 0xE0095651B585610FULL, 
            0x5BE2D1AEBA302BA7ULL, 0x3110C8D5285DA659ULL, 0x25926FA2FA0AE0A9ULL, 0xD65F6EF209B1A9ACULL, 
            0x5ACDC753368DD048ULL, 0x2F6BDCF6B369AECAULL, 0x5086897FC29BFA1BULL, 0x73D6AC686A6C1C8FULL, 
            0xC0680C171B8C881CULL, 0xF6FA13AFE2544027ULL, 0xEFE57DD17905A5AFULL, 0x4CF07A7632571C63ULL, 
            0x92809CC4641FA26AULL, 0x7F1C52194FCB63FBULL, 0x699262AA34E43F18ULL, 0x830608B8FF7661BBULL, 
            0x9BEDE235D3D6A9DAULL, 0x37B4E0048C829AAEULL, 0xD2B7E06C463BE043ULL, 0x8490DD92F39963FDULL, 
            0xA721D26D3BDD2CFDULL, 0xDCAE3434D2BECE40ULL, 0x697689AF6B3CA0B4ULL, 0xA2C15BF9D3CBEBAFULL
        },
        {
            0x10D4CBC5D4388FFBULL, 0xFDE568503D887DBDULL, 0xF43726D908FD6662ULL, 0x545387FF23B9BAE7ULL, 
            0x6E08259ECE4B45DFULL, 0xE87867E064710F01ULL, 0x142FFBF4AC0ECC8DULL, 0xAFEABD470C305D4AULL, 
            0x47917B87AE2B8306ULL, 0xF899317121516116ULL, 0x5A74D9E3A21DA971ULL, 0x58734BAE63B6495DULL, 
            0x114EACE689B3956DULL, 0x2DD8DFA7E910049FULL, 0x6E2AD0A033ED76C3ULL, 0xB4FBA38CBF774499ULL, 
            0xFE36F97618A3BCD7ULL, 0x13A29C420997181FULL, 0xAC4930F84D23E46DULL, 0x67E07F8690A59947ULL, 
            0x1262A996DD6D5B5FULL, 0xC3C2FE5FE68A30E7ULL, 0x685D0208A863EB49ULL, 0x22084C5BE698D3D9ULL, 
            0xAE78FC3AE817ED58ULL, 0x8B05D37738634D55ULL, 0xEAC62BEC5061E071ULL, 0xDFCF155C8CDB4B04ULL, 
            0xB5622E38F45BB038ULL, 0x8627F67FFD5ED4C2ULL, 0x3FB14A216C2ECAC8ULL, 0x7AF287A278667AE3ULL
        },
        {
            0xF7D0F7954FA9E488ULL, 0x532EA98B73759A0AULL, 0xB18F593D300BB74DULL, 0x166BABFF4D956328ULL, 
            0x5AA56A41B935B077ULL, 0x8206D61EB48C89DFULL, 0xBFC857E8DA48E862ULL, 0x5D97E17FAE283166ULL, 
            0xABC68D2A0C82F4EBULL, 0xF2D9BB46A067370CULL, 0xCA35CF01B44E50ACULL, 0xB2BE5E8146D8BEB8ULL, 
            0x06ADDF0B112B4FBBULL, 0xC677717D6756E2E9ULL, 0x7A24D9AA8D1B18C4ULL, 0x8B128558B2A68E05ULL, 
            0x7E44CC3005C08544ULL, 0x43BC64B31A10F0A2ULL, 0x559A13A367BC4EC8ULL, 0x73040F8FB0779400ULL, 
            0x751D2C81ABF6424BULL, 0x029859C89A1AACC8ULL, 0xCF62AEF551B06747ULL, 0x84ECEF16079EAA9CULL, 
            0x35597FC8065ACFF4ULL, 0xBD2661D8DB57F355ULL, 0xD53F98D1600CCCAEULL, 0x994182B21636F946ULL, 
            0xEA759B808541B2F5ULL, 0x438EDB1FD24AFC73ULL, 0x7C16F3969E9AA2F5ULL, 0x10E0B8D422C3921DULL
        },
        {
            0x72E4C362E88C3B40ULL, 0x3952259878E67B12ULL, 0x221C4619EBAC0D8AULL, 0x52E2AEF2F4C743D3ULL, 
            0xC031C28428AAC870ULL, 0x80D6F83C82E096CEULL, 0x63CEACC1BE2CE3C9ULL, 0x2DAE0D9BA5D2C887ULL, 
            0xAFBEA8BC26816081ULL, 0xC5D7680B2FE93641ULL, 0xF881CEC273296F14ULL, 0x38CB658976A39F53ULL, 
            0x0126BA1D601DDCB8ULL, 0xF156760C84EDADD7ULL, 0x8FCAD9420D122031ULL, 0x70CC8DD5E63C8535ULL, 
            0x09174D5CEAF8B886ULL, 0xEDDD2DC8018B67DCULL, 0x00929C12537BF70AULL, 0x51FB9B541356BCE2ULL, 
            0xEB5EEA2B95116565ULL, 0x697122182DC5A1F1ULL, 0x2D42DD6F97CDDEC6ULL, 0x8601B58007339FD4ULL, 
            0x7A9CFACBC219DB45ULL, 0x0EBED801BBBB5C45ULL, 0x8FA45ABDDFD7447DULL, 0x28E6AC4E95158255ULL, 
            0x2121116EA96AA50BULL, 0x205151C34B02506EULL, 0x972BEF17C2651424ULL, 0x572230104F1F5840ULL
        },
        {
            0xBAC01FA06CC38426ULL, 0xC929E8A2D860E9BFULL, 0xCF98CC852CE3EEA9ULL, 0xF77D892205C78C3FULL, 
            0x4FD027C875FBAD75ULL, 0x6F4E46C0E9251BD9ULL, 0x8097143FFF1F5051ULL, 0xF90FBC9F53907DFDULL, 
            0x3A1CAFA675816B77ULL, 0x13DDE4BE14A19297ULL, 0x8ED9B65D0F6FC134ULL, 0x8BB7071DA2D0B2BCULL, 
            0x9ACD1542CA190243ULL, 0x2951631A206C0BD9ULL, 0x3327CBFDC575834AULL, 0xC6182D0C4F5D549DULL, 
            0x83CCFB80EA41D257ULL, 0x0626CBB0CB38501EULL, 0xB2AD67D1CDDFBF99ULL, 0xE80DD1B4F2FA058CULL, 
            0x44D53E1B9EF4E6E5ULL, 0x42E60CF8C3500771ULL, 0xFD526DB9F942F34CULL, 0x562C54885E7D2367ULL, 
            0x35759D7C1396EF1DULL, 0xADDC7852BE68BF8BULL, 0xC6D10FE1E87E399BULL, 0xEA28834F7C30B64BULL, 
            0xC950393C33C59BF8ULL, 0x9EC74C6CE56627F7ULL, 0x88B186AB173DDFB0ULL, 0x6C85D505359734F4ULL
        },
        {
            0x48210E361BFC6F40ULL, 0x90C2B967F2780FC5ULL, 0xD9610E8DE34304FCULL, 0xD8A88919E5993AE2ULL, 
            0xDED6A94DE6A96339ULL, 0x3F43AB63271A0DE6ULL, 0x18A82FCE98C7592CULL, 0x50A87B53F9C5AE6EULL, 
            0x740BDA51EE952C79ULL, 0x857390BA0286BF2CULL, 0x474AEDDC8F6DB36EULL, 0x2FCEEB463C197B0CULL, 
            0xB013496C1C3051AEULL, 0x9AFCC17980F5B471ULL, 0x822EC43809921186ULL, 0x42955467D8798581ULL, 
            0xC5C3ED7B5E225BC4ULL, 0x79ECAF43EB52A6EDULL, 0x4D9C3F3CD67D66C8ULL, 0x8E036B1C7C7A6048ULL, 
            0xBF9B9D64959232FDULL, 0xD49CB096F2467AECULL, 0x1EA191DF612A161EULL, 0xEFF53AA1F24A83BAULL, 
            0xA93D1A91E228DA2FULL, 0x8F8E016462B0813DULL, 0x375040250D7E47F2ULL, 0x156894E44A86825CULL, 
            0x7B51415045B2A878ULL, 0xABC3697DE8C2FE7EULL, 0x6B26A4CD36F62152ULL, 0x2BED2E17F7735933ULL
        }
    },
    {
        {
            0xA0DD71083C202D69ULL, 0x5BA5EC5945A1C6BAULL, 0xE8FD233B2E6251F6ULL, 0x724265EBA82B76A3ULL, 
            0x685538504CD53898ULL, 0xA85CDCD04C62BABEULL, 0xBC038BF1276C7150ULL, 0xD62B8B96839C6E8EULL, 
            0x58A606CC281923A5ULL, 0x2B7EB47D66E120F0ULL, 0x2F187A326E77B277ULL, 0xE9D82DE3424F9363ULL, 
            0x5E17866C697F894BULL, 0x8E5156B4F641DF55ULL, 0x6E0946C71AC6C61BULL, 0x54F52B30896216F2ULL, 
            0xF7EBE830F13D4201ULL, 0x070255B0CFD7542AULL, 0x0FE05F4F90DB992FULL, 0x3F24E83848F834CAULL, 
            0xE63D1BDC20DBC694ULL, 0xE64081F3B078074BULL, 0xFB0246D16D4A1E89ULL, 0x2929F8D945F58B0DULL, 
            0x2ECB95D8E1202C53ULL, 0x567A8EC991F74BBBULL, 0xF295F761A15AA451ULL, 0x98609B164B6091BAULL, 
            0x625944254E45A336ULL, 0xA8C8350D2448C26FULL, 0xA46EE1065955EDBBULL, 0x88B5E274B77120C1ULL
        },
        {
            0xF5573D583F670A90ULL, 0x7D6E099718A7CD81ULL, 0x1250FEC1907CB3C0ULL, 0x360CC7F0F83168C1ULL, 
            0x67E545226697325EULL, 0xC4FF43973739E0A2ULL, 0x3CF4017721997D69ULL, 0x0F81CDCD2A07B1FEULL, 
            0x3547AD80F672C1A1ULL, 0xF6FC59900E5A8DB2ULL, 0xDFD6E23B3CA01878ULL, 0x5BFFFA7D144950BBULL, 
            0x765FB760CE632DBCULL, 0xF7EFDA571CB2AB8EULL, 0x3A1285715D670579ULL, 0x4F78570B7BCD9ADBULL, 
            0xAC58690A1EA24AC4ULL, 0x9CF619E60A692E71ULL, 0x31AF8F92DFFB746CULL, 0x3ADE5F419D9E5B99ULL, 
            0xFB8019DA0F79FF32ULL, 0xDBDCC7B76215734CULL, 0x9BE6FD158B06A746ULL, 0x18DF3B6CD9BA277BULL, 
            0x863311400F52DF0EULL, 0xAF17C2A795B3C189ULL, 0xE45D70681A945801ULL, 0xD8C1156A2B953FACULL, 
            0xC0F244CCF7883095ULL, 0x13F5C4CB5336FDA6ULL, 0xDA48616E00A0AE40ULL, 0xC2F66601AD6DEDE9ULL
        },
        {
            0x84759A393B3FA952ULL, 0x05DCF7F3CC27001EULL, 0xFEBA61F40710BA1CULL, 0xD1D2897BCBE5A8A7ULL, 
            0x9D341A1163CF3021ULL, 0xB60771BF0B21572FULL, 0x8079AEDBC0F7709BULL, 0xD22B6D2B03D61305ULL, 
            0xA71357420E2B790FULL, 0x9CE6A8A51186F478ULL, 0x83F3EC3A05DB0F88ULL, 0x4401EDDE4BDBA5BAULL, 
            0x987CF0D6CC23DEC9ULL, 0xD7202A1611584980ULL, 0xDF29016C864774EDULL, 0xE1447C63CD70A1D7ULL, 
            0x998ACFFC8D6E1CD2ULL, 0xBEA114C1008E6863ULL, 0x72EEAD0BF6307EC3ULL, 0x27EB0D76CDE33A0EULL, 
            0x01D596128D2E9BF7ULL, 0xEC7A9CCF56103630ULL, 0x2896D1CC857DB782ULL, 0x64015BD3A99EE847ULL, 
            0x49756C3C9D4683ECULL, 0x79DB3DCF3D0C36DFULL, 0xF56A9FFE39912273ULL, 0xFC86B14A96CD6B4EULL, 
            0xAC41F3180D58D06CULL, 0xC2C5386728E7CADDULL, 0xD5BE3C2E09D152D7ULL, 0xAEDAC06597A0B84BULL
        },
        {
            0xD2BD5A6D59593064ULL, 0x040228058A8CEB2BULL, 0x97EE221B91A3DE70ULL, 0xF2054D02E4CAEB82ULL, 
            0xA7A0F2306EA37FF5ULL, 0xA6A56EF8F36FBE1FULL, 0x24B7F7EC638FD681ULL, 0x2FD2A3C14A7D4724ULL, 
            0x3B40074531A61039ULL, 0x51008076C9F46E76ULL, 0x80C1B21D4D150E1FULL, 0xD0F28F6D95B46AA2ULL, 
            0xCCB97AE11C4ACDB6ULL, 0x768D01AF4E71BC58ULL, 0xBF67787DF1569887ULL, 0x0CF4E68203148CD0ULL, 
            0xB1FFD42E36BA7586ULL, 0x74FB67641861668EULL, 0x4A03230D23219661ULL, 0x6CA40CBCC3E41C26ULL, 
            0xCEDE6B746A367A26ULL, 0xB76167604C8E0A38ULL, 0x317116F53FF9C30EULL, 0x2D8B5BB1B3660EB2ULL, 
            0x1DD8638FA6DA2154ULL, 0x3EBE32B5BB329598ULL, 0xFC50A9018ED34BABULL, 0xC3DEB8B3687F7827ULL, 
            0x078CC7E029608420ULL, 0x697D4B507916A856ULL, 0x537ADA720A2BA64EULL, 0x824CD3F4ADDD9CAEULL
        },
        {
            0x389B01107B3CA7B6ULL, 0x98FD0A9B796A8E6DULL, 0xA63DADE5E81FA3DEULL, 0xA29998BEC307AE55ULL, 
            0xE6A45953CFAF83A4ULL, 0xCE5C7CD9D0AE5BA0ULL, 0xB25D83D2A2C0E5FEULL, 0x94E7FD021B37DE1AULL, 
            0xF1A883EB3032F1F8ULL, 0xE084C0F76ADC18FBULL, 0x4B9C442F324AA022ULL, 0x5C93A0D887C046AAULL, 
            0x42C9909CE477896EULL, 0xB515C898F5818AEDULL, 0x34A7DBF5EB06D548ULL, 0x7C021FA6B57DB4A1ULL, 
            0x701B8279F623E15EULL, 0x6750899AADA27A55ULL, 0x6A84052C574A29E9ULL, 0x67260ED55D45ECFAULL, 
            0xCD68FDCEB7321E33ULL, 0xFBB1F3A6985487A9ULL, 0x3B28CA44069A0D74ULL, 0xC96D857092644B8BULL, 
            0xF934C9AC111E40A2ULL, 0x903BE77B3EF632ACULL, 0x3CC5AF7348DB92CCULL, 0x94BB930ECA983BE4ULL, 
            0x72CFACC068952C9FULL, 0xD3B8FDC2734835E8ULL, 0xC26AA86927F63F3EULL, 0xBEA854B32CFAC734ULL
        },
        {
            0x5447316A90DE0EECULL, 0xB620B1B230996038ULL, 0x1CBA546D5818069EULL, 0xA26E5930718E63B1ULL, 
            0x2F82E763DBE85ACFULL, 0x2C8C77E98560C85FULL, 0x774FB7F6FB2C2EE8ULL, 0x8C400E3DCF9813C9ULL, 
            0x76D03ADA3BABD683ULL, 0x335303EC706683BCULL, 0x2D6FD6B33EDDBED9ULL, 0x91C6F81DFD95641DULL, 
            0xE4411FCE19E6B970ULL, 0x4E7FE23F8CB66F36ULL, 0x6A6DEF0AA3830157ULL, 0x06C8C7CCE1BD9D8EULL, 
            0x00AEFEB4C8C713D0ULL, 0x5A61B085AF600165ULL, 0xFAB4CFF1E4FE3745ULL, 0xA7C8F85ABDCE56D0ULL, 
            0x9F112183C7C25EA9ULL, 0xA574589C4087F1E9ULL, 0xEA364CD2B48F23B1ULL, 0x1CC3C4FE19556C9EULL, 
            0xB795C45244ABA13EULL, 0xB2E8F92E75FB9431ULL, 0xF67BB8C185EAC97CULL, 0x576DD95558F92643ULL, 
            0xEDC6F82071CE92B6ULL, 0x35D02C1AF2AE06B4ULL, 0x69BC808602CCF7F1ULL, 0xF8FFD8C6A863933BULL
        }
    },
    {
        {
            0xE7B43B27DBC20F02ULL, 0x7A199CD4DCA22714ULL, 0x02DFCC686C75B9C1ULL, 0xB08B51D884180D93ULL, 
            0x05AF397AAF267E6DULL, 0x80073BE68725284DULL, 0xA05873D9B031E32CULL, 0x91C54ECC0FC45DBAULL, 
            0x3E6ACC77618922FFULL, 0x742D39A7B71F40EDULL, 0x0171597862E9DE2BULL, 0x8ED300A17F43910FULL, 
            0xDCE2338617D23FB9ULL, 0x18DCEBB9502F9121ULL, 0x7C0C402DCE84650DULL, 0x7B1DB9A2D97EF9EBULL, 
            0x9457092985C823ADULL, 0x4990E79046913536ULL, 0xC4801A08F9D9557CULL, 0x8F3F127152463257ULL, 
            0x956697740A304736ULL, 0x7B57C87039F23963ULL, 0xEDB38A7D7C7295E0ULL, 0xBC9C0DBE931EC0D3ULL, 
            0xB74EBF280F1F1704ULL, 0x5EE55408BA3A1E74ULL, 0x043383ACB9BA1F67ULL, 0xDF633295434A64BEULL, 
            0x0145D10F366BFF09ULL, 0x03DC1A3BB053622BULL, 0x0F0F52DA9AA167D5ULL, 0x8F12C19454C4CB48ULL
        },
        {
            0xEDFEFF2B34396FCAULL, 0x6A77BE2CCC80D26FULL, 0xBD26435CEA4C6C5EULL, 0xFF8B10458F90434CULL, 
            0x1BA916D18F62EDC9ULL, 0x40C54E3337BA490BULL, 0xB5896A22EF82BCC3ULL, 0xB35811EF57436A8CULL, 
            0x7D69E6549262763CULL, 0x720C45A63380E358ULL, 0x4ACB47291D5A157FULL, 0x5901298C96DC9D6AULL, 
            0x488311BAC5C6E083ULL, 0xE9729E852C6CA411ULL, 0x9243B8E150FF93A8ULL, 0x12F5632432901B44ULL, 
            0x58FEEB41B40E454EULL, 0xA00A4BF3455BCE14ULL, 0xDE68BAF35B63377AULL, 0xB6FB7E84DE3EDBD6ULL, 
            0x186DDA54327D88FBULL, 0xC99B2790245ADC5BULL, 0x0881055A306E9753ULL, 0x70C348521AEE5282ULL, 
            0xC2044FFDC0CEFFBFULL, 0x393119D91A152389ULL, 0x132291049587227AULL, 0xD6192638E542B20DULL, 
            0xFC8F98C53A182FA9ULL, 0x95AFEB8033FFAD3AULL, 0xE6C03C0D97DC5467ULL, 0x3402D376C3437061ULL
        },
        {
            0x85CD152CE186308EULL, 0x53B6A5F039F02485ULL, 0x909E13E23780EBB9ULL, 0x69F5DFE6A3890BAFULL, 
            0xAFC74D3E79C3D78EULL, 0xFF44A025D5812691ULL, 0xC1EF43C9AD0B19A5ULL, 0x47E721504D6DAC5EULL, 
            0x9DDE25309E5757BDULL, 0x18EC68EF17340B58ULL, 0x35F69F8F2CE3B841ULL, 0x464953C3BC7CE71FULL, 
            0xF25A810300DD7A13ULL, 0x12F810D926864D58ULL, 0xC048B0E743C77338ULL, 0xF23AC9A6E93BFADBULL, 
            0xCC700487F501114EULL, 0x5876ED61BE9F6941ULL, 0xA77FB477F2CDF210ULL, 0xD6091D34561CA2FDULL, 
            0x0654EA8153005F28ULL, 0x543BDCD559948627ULL, 0x5AE6D8E759DBA3D6ULL, 0x61A53BB581C2CB8DULL, 
            0xDCF46A96A98CA776ULL, 0x19A37E657943ADFEULL, 0x015F7D4D3941FA07ULL, 0x76973DA30D6F696BULL, 
            0xA77659213359729BULL, 0x1A609923E4073E8DULL, 0x4A8A07675592FC96ULL, 0xF805555443A48233ULL
        },
        {
            0xC3FC70444DD89A86ULL, 0x75F55E712B9F5604ULL, 0x06AA3EBBA6C4F17EULL, 0x4B28610001C5609DULL, 
            0x4997452DE9147BB5ULL, 0xEBF278B51EDB331DULL, 0xF5C927B735D08303ULL, 0xB2B0AE2A3EA2C44EULL, 
            0x41E0F95A2940BEF3ULL, 0x7B394C97424E3B21ULL, 0xB7A733E1F70A6F88ULL, 0xBB537A06301D391DULL, 
            0xA2EB1FD62C950DDDULL, 0xAD8EC5F9087CA526ULL, 0x8084999800690338ULL, 0x750E1551C01AC213ULL, 
            0x7A5D193832FCDB11ULL, 0xC10DA5E698CD5179ULL, 0xFF61AA642936780DULL, 0x72D4BD651A9FFAF3ULL, 
            0x72E4150E13793D3BULL, 0x654A6C23A0228D18ULL, 0xC6B2496BC6C5DC0BULL, 0xAE3ADF1048496D7FULL, 
            0xA8F88762AE2E9E51ULL, 0x36962C8F17C151A9ULL, 0x33710CC042BF157AULL, 0xE339B301D242B518ULL, 
            0x54FC7C2B6BD0A4ACULL, 0x9156AD7AB1303774ULL, 0x08D84A6FE073B2A7ULL, 0xA590EE679B59BE83ULL
        },
        {
            0x8BDA475D92DAAE6AULL, 0x93FCDC85957E90FBULL, 0xAB6989E3825B3D58ULL, 0x541206D8D21E8256ULL, 
            0x938B32B44F3540A8ULL, 0x444797E87824E1E1ULL, 0x0DEBF90823C613BEULL, 0xB25F34BB6AB92F85ULL, 
            0xF3963592541F66ADULL, 0xED4B681AC17704F5ULL, 0x0AC536665CB4AFBBULL, 0xB7D1859C99722F55ULL, 
            0x9F78CD6B8E272FBBULL, 0x9D571481BFD2F287ULL, 0x2C7D4909118B6394ULL, 0xBD4DFC8FF77FFBE6ULL, 
            0x71663E5CBB401F6EULL, 0x9A2FB6E898A558AAULL, 0x378338070C1EE1CFULL, 0xE0F6852449299AC7ULL, 
            0xC29C886AF40C7456ULL, 0xFBB8721FD1442B9EULL, 0x8912DAB44CF9B7A4ULL, 0x79199224DF6E34F9ULL, 
            0x278CCB4E15F5CD12ULL, 0x504A8BDCD897CE8BULL, 0x20854600C2FE72CAULL, 0xC1762AEFC2009C69ULL, 
            0xDE171CF37BA4D051ULL, 0x46BF58CE2CE3CB05ULL, 0x2E71874708A7E537ULL, 0xBF6A8C7D47403715ULL
        },
        {
            0x9C9BF729918A33BEULL, 0xE476368E473C5285ULL, 0x6153ACA0F591FA5EULL, 0x78CC1D9485102D61ULL, 
            0x66843E74EFCDD878ULL, 0xF7B958F65452C352ULL, 0xE6998EEFC8893D51ULL, 0x01B898159058EDB2ULL, 
            0x7C5B1363F1897183ULL, 0xD024DEF79ECCC549ULL, 0xBDE880E867665C2BULL, 0xE71638A9308EDCC1ULL, 
            0x321EB6EF30DCB6ECULL, 0x5A144F34899F577DULL, 0x2CE5A3BF76723A4FULL, 0x84FF61C2EACE003BULL, 
            0x8613BF4D60549F16ULL, 0x4D4DF858BBD5FDFCULL, 0xED8B430BAF3E65F8ULL, 0x846855CAB26892FDULL, 
            0x9F21B97F747D0C64ULL, 0x648026255B6DFFDAULL, 0x363EDDFEBF57F1E3ULL, 0xB72D78D0CA10428CULL, 
            0xCC6667860EF41526ULL, 0x5B606A8D5A4A11F4ULL, 0xA89063DA59308E78ULL, 0xC66852843329895AULL, 
            0xFC5BDBF2500A48D3ULL, 0x322FE17437F04CB5ULL, 0x70379C5130B53E8CULL, 0x1A1C21A295F03664ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kPhaseBConstants = {
    0x9C76C6BAC32B5527ULL,
    0x49E75411D1CA4744ULL,
    0x822A7C9613F3C7B6ULL,
    0x9C76C6BAC32B5527ULL,
    0x49E75411D1CA4744ULL,
    0x822A7C9613F3C7B6ULL,
    0x64618055ED15431CULL,
    0x6764E62EAC104FFEULL,
    0x8D,
    0x4C,
    0x09,
    0x6D,
    0x1C,
    0x22,
    0x81,
    0x53
};

const TwistDomainSaltSet TwistExpander_Vega::kPhaseCSalts = {
    {
        {
            0xD7A4A56F7D0C9D31ULL, 0x3D9A90FF655D76A3ULL, 0x49B1DC73A0FD19B5ULL, 0xA47CB87CF8957793ULL, 
            0x0B172D4F5506F6F0ULL, 0x353FFC9674C99ACAULL, 0xA181CF6C74ECA2E6ULL, 0x011895DFD22A3126ULL, 
            0x848F2E0D004B0810ULL, 0x3E1EC61A2C7CBA8AULL, 0xDD7032A6645D0F2CULL, 0x2C2B9F7F6C71EA9DULL, 
            0x01E33FEDDA1075A6ULL, 0x0CCE6FB3CBE51DD6ULL, 0x9D522B7E5ED6D614ULL, 0x49ADB443E023DE1CULL, 
            0x13F69DDD16EC4762ULL, 0xF64DF22DC7E1A02DULL, 0xAB300D83C2151658ULL, 0x80C99E878FC67349ULL, 
            0x25121909BDEBE552ULL, 0xCB8F71C090B865A9ULL, 0x45771984123F20C6ULL, 0x7B762F603DD369E9ULL, 
            0x13E78DDDA5CC80E3ULL, 0x9B45CE3FF9738A78ULL, 0x015E8E8FC28206BFULL, 0xD57915518B2A5B1EULL, 
            0x6B0EB74F89E21B52ULL, 0x3A384C42E03399C6ULL, 0xB9FAD8F99A28EDB7ULL, 0x6B9C588D1C0DCE85ULL
        },
        {
            0x4B2441407E505C6DULL, 0x4229EEF9E5CFB3D5ULL, 0x4351D3BB249C45E1ULL, 0x0E8613A02242D7B2ULL, 
            0x541AB753E94E7998ULL, 0x4690E11A107573E1ULL, 0xAB0CB22B4587FF09ULL, 0x934C3D1D0BAE6A34ULL, 
            0x4DB8B635499DC401ULL, 0x1A67231EAFBD418DULL, 0xBFF3A0813B69A7CDULL, 0x1147F03180AB753BULL, 
            0x10ABBC861DB315ACULL, 0x01BFB6D14B3A3137ULL, 0x26A75E86A9CBDCC6ULL, 0x33020880D8F9BB5FULL, 
            0xA8B179496B7BA2A6ULL, 0xBE3185BB37371F87ULL, 0xC125FAAF1D621884ULL, 0x3D2A96D940F3E547ULL, 
            0x1F09243FF8A174C5ULL, 0xEDAC7F6D66DA09EBULL, 0xB37EEFB16CAB8539ULL, 0x3AA47A5FECF39E1DULL, 
            0xA42AC26ED61002FCULL, 0x6F59D2AFE4AAADB8ULL, 0x9430FFA8FF395E84ULL, 0x8F59A3F7EB483A81ULL, 
            0x37A0B50CB76E22E8ULL, 0x4DBA93FCAB0EB26AULL, 0x9FE036984C867897ULL, 0x7A5BDB0E92D9F163ULL
        },
        {
            0x400E40CDC2ED6338ULL, 0xA264BAF7D2AAF740ULL, 0x79E27CA995FA1C81ULL, 0x8D917FCEE9F9D010ULL, 
            0x72656B6E9050AAA0ULL, 0xA8E2488553120721ULL, 0x2B08987D3F88D47FULL, 0xDF07A1C58CEA0B41ULL, 
            0x2A984A3E6964622FULL, 0x99216E77831E33EAULL, 0x8516AEF3E814F65BULL, 0x0E37A7223EBD1BB1ULL, 
            0x10CF9FC1064A8EA8ULL, 0xE1842CB7AB5B83BDULL, 0xAC558E5422162DBCULL, 0x4C3CC59DBB57EC72ULL, 
            0x0EAF44AEA60D4EA1ULL, 0xEFE068C4DFC46391ULL, 0xA4FBDCF0EDC59A13ULL, 0xD569E9F171960252ULL, 
            0x425D3564C66461A2ULL, 0xEABBE65E604BA143ULL, 0x5F840B839F54FB1FULL, 0xB370A010FD60B8F8ULL, 
            0x4B440EF1A9BB5172ULL, 0xBAF11872FEFAC5E7ULL, 0xC7099BA86AF4B05FULL, 0x2EF223090FD70CFBULL, 
            0x3837BC3A8A4CB9B9ULL, 0xC5F73F5601B049CBULL, 0x44E9724CD2AD31B0ULL, 0x984CFEF37E5978C3ULL
        },
        {
            0x444EF3F91B3D90A8ULL, 0xDC7B97508C679928ULL, 0x1192F450016E9E3AULL, 0xF0EF21DCA029F4AEULL, 
            0x3B919D102D234B7EULL, 0x114FC38036C7AB1AULL, 0x8CB263D8B998EA5AULL, 0x360C2E2701A5006FULL, 
            0xCB52BC417192B526ULL, 0x57C4D04817A3DBDCULL, 0x0C1B8956EE0B94A7ULL, 0x7CB57BFFC83BEFECULL, 
            0x3075D36A84123110ULL, 0x975DB05B2107C1FEULL, 0x407B1FE447ED1CF8ULL, 0x2DA2EF9A1B036F67ULL, 
            0x731452116351C95CULL, 0xCC9F39A6D02EFB5DULL, 0xD9783EDF6D1B0048ULL, 0x50B37B321256AFDFULL, 
            0x7B1E174BCC956096ULL, 0x6019F1811248E7D6ULL, 0x346FDA02F6C0D339ULL, 0x39A6CD5AE78E8B23ULL, 
            0x8C278656C9F192AFULL, 0x87CA4A1AB0BF0466ULL, 0x7569D222A944F760ULL, 0x3101409014E7E92AULL, 
            0xEEA9E4E8DB589585ULL, 0x721FF4CB3FF3B401ULL, 0xD85B2549BAD3E6D9ULL, 0xCD358C34AD9FE92CULL
        },
        {
            0x6C33401B144CA1DEULL, 0x078EEF7AF52F89ECULL, 0x67D0935A6E5B166BULL, 0xADF26A6F8CEDCE9CULL, 
            0x3DC8C5C635D109B6ULL, 0xB11228A58D6B030EULL, 0x56539DCD1736D1C4ULL, 0xD46322F64188F7A5ULL, 
            0xE0340692ADADE083ULL, 0x6758590AECA15673ULL, 0x663876796BEA883EULL, 0x23215CDB13E1ED15ULL, 
            0x9F4AC79A57E921E4ULL, 0x5C47C47F7EE5EA7AULL, 0xC7CE2532D59427BCULL, 0x7065DCD49720EA14ULL, 
            0xF43BEEB8A7BCAAEBULL, 0x11DFC16A3189340CULL, 0xBE2AE23FC4C0F86EULL, 0xCF2C4B5DDF2B2EB2ULL, 
            0xB2F2568E0F111448ULL, 0xB0F03CF063BAAD1BULL, 0x91C921760C3E4C99ULL, 0xFB59B32547DC3DE1ULL, 
            0xED58665168224481ULL, 0x4A88BBD58320A7B1ULL, 0xAEE191F8935CB195ULL, 0x21B169ACA3E06154ULL, 
            0xD34919F5F18E1EBDULL, 0xF10E5EC4E40F9223ULL, 0x4B27A0C2EAD8DF14ULL, 0x264BD35933032222ULL
        },
        {
            0x3095A3928D3BF9F8ULL, 0x27EDF2BCCD64ECACULL, 0x1A78E651E4081EBFULL, 0x82BAA2BE3C8B8B0CULL, 
            0x4C1E2EF61E47C10DULL, 0xCA1B567915C32AFCULL, 0x776B775F5DB2FB20ULL, 0x938D65CBFD658153ULL, 
            0xE3991716D48219D8ULL, 0xB20E531477661428ULL, 0x9797AB13D085A80BULL, 0x04DB77D895CA126EULL, 
            0x841B50DDC0EC7E19ULL, 0x31CF81047117D2CEULL, 0x234813932F4FE239ULL, 0x088E5ED3319D6AA8ULL, 
            0xBE0367482B53AB51ULL, 0x7AEFDCC9FDB19B6FULL, 0x4F00C29DD2FBF354ULL, 0xDAB55B807B2C033AULL, 
            0xDFCBA7BE1D3A2184ULL, 0x53B8DA84D6CB457EULL, 0x69309CA71949B5C9ULL, 0xBE5ACA6C2A6E864DULL, 
            0xF88B1D4A3655E224ULL, 0x87D756E33B5A906FULL, 0xA216259F17638319ULL, 0x39E7D1BAE31A21D3ULL, 
            0x42983C8F616EF017ULL, 0xD8A5D8C21F730E0BULL, 0x208BF58EBA611118ULL, 0x6D74BB558621EF14ULL
        }
    },
    {
        {
            0x72F62BB7EBA0DF14ULL, 0xEAB6F7F123BEFC02ULL, 0xFBC2A4F56C344800ULL, 0xDCFC3E668CF6A48FULL, 
            0xE479F430399334A3ULL, 0x870D5B4A9D636396ULL, 0x486213E8570CE9E4ULL, 0x9A9521329861B1B3ULL, 
            0x24FAA2D2D18A37DAULL, 0xF35E1EDAADA48F78ULL, 0x177EEC832658DD24ULL, 0x8EFBB01937F83CF1ULL, 
            0xAEA58F7EF305D23FULL, 0xC45323CE3B00D32CULL, 0x0786FE9701592A9AULL, 0x68A7382FD96A0923ULL, 
            0x126FEAFE2369E25CULL, 0x4EE2112495CA59C9ULL, 0x8522B41D706E97C7ULL, 0x6FC8C404D8624BF5ULL, 
            0x0036A56F2BBAE325ULL, 0x2E465ABFFE6D6653ULL, 0xD2469A4A8883F93BULL, 0x8C1498970A523AFEULL, 
            0x019C085A227ED106ULL, 0xFED67C117CE57BF9ULL, 0x2104AF8C09D58D28ULL, 0x8EE300764A37D246ULL, 
            0xBABF07167D2C1267ULL, 0xA9866F227D0294A1ULL, 0xF7A1582E43E96ADCULL, 0x4AA669DA8D976232ULL
        },
        {
            0x256A4B10F2330DD5ULL, 0xEEAA5DCF18DB8D76ULL, 0x23E0352D8B7D3F00ULL, 0xBCA608DB9A8A9EE5ULL, 
            0xE4B5EEFE084ACCB9ULL, 0x101D58B6BA9263E2ULL, 0xE2631C033B673891ULL, 0x01922FD53FDDE71DULL, 
            0x2AA94D6AD74ADE96ULL, 0x033A72642D628B6CULL, 0x390A38A97C608D7EULL, 0xC5137BC3EB9424E6ULL, 
            0xF7A340E046013ADEULL, 0xD8359481FDBA2BABULL, 0x21F9A07BCD6266F4ULL, 0x28F595B78ED11C20ULL, 
            0x3D94176D7A2F585CULL, 0xD0D35B443950EE41ULL, 0xC6F13A92352B54CFULL, 0xB022555DD2DE5292ULL, 
            0x5EF345A36975412EULL, 0x29272C5316631B42ULL, 0x2258B60B85379513ULL, 0xB921315671B61FC5ULL, 
            0x7B2306506D7D2464ULL, 0x27AFFAF1A407E126ULL, 0xF029202FDF1118F1ULL, 0x8567E533B55B3E51ULL, 
            0xCC88FA84F8F0C120ULL, 0x1B61C396DA9C42BEULL, 0x938E171E2F620FCDULL, 0x4FF3ABC2F7AB4CF3ULL
        },
        {
            0xDF6B9D560F34FC6FULL, 0xEFE6D83FE90DDEAFULL, 0x5E54CC723E457B45ULL, 0xC7887F9183B761A1ULL, 
            0x96AC8FB9983E828EULL, 0xFFF38B187AF5D397ULL, 0x8E28E698DF9AD05FULL, 0x70B706B37B91B646ULL, 
            0xEAB1A3436FAAAC87ULL, 0x842CDC5FBC576954ULL, 0xE98D2A96F2744763ULL, 0x4B3A086514E9E080ULL, 
            0xC474D8056069233BULL, 0x58A274A0448FFC6AULL, 0x716D8EC599C0A83EULL, 0x9B088D07E1E8093BULL, 
            0xFFC7EF2350689CDEULL, 0x18E34F531762291BULL, 0x5A68AD4709245E50ULL, 0x42159110271F28F2ULL, 
            0x58D5FC8B5EE8DC91ULL, 0xF13AFB8FDDBEE542ULL, 0x263D78D1D267AC38ULL, 0x92A710422DE471A2ULL, 
            0x992C4AB1B07B8814ULL, 0xB75B0380380B7715ULL, 0xC2EBCD79FDD78682ULL, 0x097522EF323B12AEULL, 
            0x766D7B6D326580BFULL, 0x89FD5E7DAD231C79ULL, 0x5A9A6F92DF6A9AEBULL, 0x1A2678EAA107F0E2ULL
        },
        {
            0xA34B6D3DD83F6587ULL, 0x045D2131E9B4A0E8ULL, 0x529C23861FF6C188ULL, 0xCC76C52D7E50A5FBULL, 
            0x4CCD51EFDB64CD5CULL, 0x8D7D6C7F1C36FFC7ULL, 0x204BCC80BF4135EFULL, 0x1B4E59DA938B75AFULL, 
            0xAD844D5D3E969069ULL, 0x536FA079412D0179ULL, 0x8BC34C39500324CFULL, 0xAF9738564DA4B7B5ULL, 
            0x47085D33C4834E7FULL, 0xEB3156B6616B48EAULL, 0x7B3D0CA09052A021ULL, 0x5D911351A9FFCED1ULL, 
            0x02EC502436ED4C30ULL, 0x5103E63DFDF8AA46ULL, 0x81A1F1D40D40AE96ULL, 0xE13C99588D5EA37BULL, 
            0x60D683617027326EULL, 0xCE9AFDD48809390CULL, 0x928D35D28126C9C5ULL, 0x7A06EA34191099F6ULL, 
            0x36279DAAEF2614A2ULL, 0x4C4D5F7BF7C8685CULL, 0x42CB3C80099F8829ULL, 0x0CC64EAA5B8E2275ULL, 
            0x87A8AD17E54184CFULL, 0x05E98846E6077589ULL, 0xB49E1E9944EF5FA3ULL, 0x161D06D7585DF0CDULL
        },
        {
            0xA3C97F9FCF0DDC65ULL, 0x60294F528249EFB4ULL, 0x80A38A860787DBFBULL, 0xAD6FAD2FF0440A15ULL, 
            0xD81447568C711450ULL, 0x070406CED85FF96DULL, 0xF6F63CF27A3D217DULL, 0x88EF3274419975FCULL, 
            0xA76CA193F0C22322ULL, 0xB041B4D8D10D7135ULL, 0xF0AD216DFACD1FC1ULL, 0xDDCEACB687157AF7ULL, 
            0x7D7FA4BAE2FD1BFAULL, 0xAA64017D6A5DB125ULL, 0xD1DBF5DA88219474ULL, 0x2C1D6E342D672DB9ULL, 
            0xB219743ADBBE27D2ULL, 0x296928685476F229ULL, 0xC05BF03A431361F6ULL, 0xE5AB5AFC371DCBC2ULL, 
            0x6813EF46E0D278E5ULL, 0x039AA4C7E35B2851ULL, 0x27F6CDD96D8566C7ULL, 0x804726DB805A517BULL, 
            0x8048E4C9F4F46ED0ULL, 0xC9255FA1E5DDFA8EULL, 0xDE809F716BA2FD85ULL, 0xCFDFB3B17A74091AULL, 
            0x1235B8BDC5087E99ULL, 0x9EE9E25B4D699E87ULL, 0x2D8BC5252DE01C50ULL, 0x68A1D2EF9B45B987ULL
        },
        {
            0x27F4673F27ADF597ULL, 0x53B0A697CC97729FULL, 0x7241E8AF3D6883E8ULL, 0xA6D17707196088E8ULL, 
            0xBD880591529C3C55ULL, 0xEF195DA648B856E4ULL, 0xF839D9D0719E2541ULL, 0x62CC881CECC66EFBULL, 
            0x7A550611EFDA3E72ULL, 0x2264673A8BD567CAULL, 0x732E4EDDDE499F38ULL, 0xFF8DF787013A3278ULL, 
            0xD7E4D1B594694DAEULL, 0xE5073A02D31048A7ULL, 0x9E190D9023E62905ULL, 0xE52DFCFB6835BCEEULL, 
            0xD5ACEC044A98896CULL, 0x7895785F6F577F31ULL, 0x37BA8711C8777E78ULL, 0x270F4C7641FE40A4ULL, 
            0xAEFE42F48FDCC0EEULL, 0x8C335A60033A530BULL, 0x51EDFDB8FF6A0298ULL, 0xC2BDA5BA303C1EB5ULL, 
            0xCF35FBFB80855B16ULL, 0xAD1D852354915096ULL, 0x73CC6A87EC0AB8C1ULL, 0x9E307E9752F2321DULL, 
            0xDDC44275F67D200CULL, 0x55EED4B7E891CB84ULL, 0xD04E11F268CD1E32ULL, 0xB33B7A73256F8272ULL
        }
    },
    {
        {
            0x1282775A4B0198FAULL, 0x04E6731F1DF989C3ULL, 0xDAEA5294E4EDF720ULL, 0x7E388BBA946CAAD8ULL, 
            0x7EE6AF245DD62CEEULL, 0x07EC05429A57CCCAULL, 0x6084A1E0628C94C0ULL, 0xFEA2CB27B8DE34CFULL, 
            0xF752B2DD3F0236A9ULL, 0xFB1AD84D89E499D7ULL, 0x0D5C0E33C2309CE6ULL, 0x03DB717A04D2DC97ULL, 
            0x718E7024AE02AB46ULL, 0x7CB4EE35A74E8DCAULL, 0x36C9E961168A0B67ULL, 0x71AFC62F53F197FDULL, 
            0x34630320091F37AAULL, 0x9F9C7A683080CBAFULL, 0xF472C84C61ABB0ECULL, 0xC21A393CED747990ULL, 
            0x65FB7C8B55254FFDULL, 0x049FD95CB59B2CA1ULL, 0xEC36C31128F0F11AULL, 0x67F4E853F6B40C76ULL, 
            0xD56467C9D9D80990ULL, 0xE98029AC70EFE648ULL, 0xC5E8747D3CD391A4ULL, 0xE54F159F824E5699ULL, 
            0xFCEFF20B8D54CFAFULL, 0x340EBFD0A6ACBD5BULL, 0x9478BC72981E6FDDULL, 0x4BACBD9129A7FD61ULL
        },
        {
            0x1580E4F5FBB3DFC9ULL, 0xBEF9F473BA8DD540ULL, 0xCA7A115670700A9DULL, 0x3BE1009336D18852ULL, 
            0xA9337EF3C7906807ULL, 0xE560451BE14B7CB4ULL, 0xD4AC235B70376B13ULL, 0xA086B55A70433976ULL, 
            0xEEC378B754ECF1D9ULL, 0x9FD1E4298FE1F853ULL, 0xE2F1D1E2ED202E6CULL, 0xF9C20BB7BC755C5DULL, 
            0xA978025BD92E3311ULL, 0xEC2C855F441887E2ULL, 0xEE540F3E39D401DEULL, 0xCD3457E24A4E322FULL, 
            0x857585354F24F0FCULL, 0xA9B42CA7E13BF0E4ULL, 0x2AF7A321D512D075ULL, 0xED7B801414F5A1CFULL, 
            0x81CF70EE63A75463ULL, 0x8CE98CA0A0DD6D9BULL, 0x993E5189C5BE1EA7ULL, 0xC549849227844713ULL, 
            0x4C47D58170063D49ULL, 0xEA084BDA7CB7AF32ULL, 0x039CFF78B87F1934ULL, 0x5E380176FE39471DULL, 
            0x1EE3CD61F019A684ULL, 0x582A3C7A1FFDD04BULL, 0x7944336502A82468ULL, 0x736ED8F8ADFFC14AULL
        },
        {
            0xFCC77D0AD94B8651ULL, 0x9AF3DF11A494C83EULL, 0xA572519C675DC103ULL, 0x37C2E9AB192EA79AULL, 
            0xA4DB231E9DBFECE4ULL, 0x787E78E50FE76459ULL, 0xB85B2AC08DF9B614ULL, 0xE1FCA3EF78F8946AULL, 
            0x2146F3A204A89F97ULL, 0x064607C00D0B00F5ULL, 0x3182B2F77131A6B8ULL, 0xCA16DF9F649E07D0ULL, 
            0x2CC458B43D3216C0ULL, 0x090EC7329397DB67ULL, 0xDAF35C8DBA4DE1D9ULL, 0x33B22C9AE8BBFB51ULL, 
            0x44EBD25F30A59123ULL, 0x984FB7E5F4732E9CULL, 0x71FD7B2EE5E4F5B3ULL, 0x976547AC51AC3995ULL, 
            0x09602AA45F88CDE1ULL, 0xD6BBD710B04533B2ULL, 0x5FC0B1AE7D29E782ULL, 0xAD58653E74A8CA5CULL, 
            0x5A280DF8FC1CF30BULL, 0x12B096BCB7B9DD76ULL, 0x8C0392CE1C0D01EEULL, 0xB92F141C7E886C63ULL, 
            0x1096BFC7C8161A45ULL, 0x2153F854654B5FE6ULL, 0xC87F270D835AD284ULL, 0x61729B1762D74825ULL
        },
        {
            0x03BC67D0F3AB6A9CULL, 0xAC764BBB8166DDB0ULL, 0x6FAFCFA1A9A3226AULL, 0x67425C97D9546465ULL, 
            0x4F0B308409D0F1C8ULL, 0x04DAC8B7524EE4C5ULL, 0x8E6150E990AA620AULL, 0xD43B8CA9687AE801ULL, 
            0x61743D1041F88852ULL, 0xE1149BCD9559B4C2ULL, 0x64A9C0DC6C28A24BULL, 0xC31086E5C1F60B09ULL, 
            0xA10C02E311DEAA0AULL, 0xB7D3E10B5EE8AEFFULL, 0xB5D0199C3D68E086ULL, 0xBA6E86AF2C62B7AFULL, 
            0x56A2CD0D26589A8DULL, 0xF941FAB1EC2633F9ULL, 0x58126CA67BAB76F6ULL, 0xDE6EE15EA4641BA1ULL, 
            0x356956D8792E5B6DULL, 0xF9D69EEBE4B96CF4ULL, 0x0A8D4A39915D3455ULL, 0xEF46B054DAF5B690ULL, 
            0xD026297D3E8E3512ULL, 0xBEAB7235CF591B8CULL, 0xCA9F66EAEE3A9195ULL, 0x023CF50F4725917AULL, 
            0x82A8212F94C7DF3EULL, 0x35FDBA55A775A210ULL, 0xB8AC83D8E6613C46ULL, 0x7A8216BDF18AF5B1ULL
        },
        {
            0xEBAA4466ABC2DB57ULL, 0x43603F040E043BE1ULL, 0x651AFB799981A08BULL, 0x9463AF8651DAE8FDULL, 
            0x06A457EFD4CE24C5ULL, 0x478DC77A12D8C438ULL, 0x977DD18145A3D5F4ULL, 0x2708EB06E467FA1DULL, 
            0xF9546C0E205E6867ULL, 0x02CFAC017BC3AC1BULL, 0x9ED835D09C1ED4C5ULL, 0xF7AE2292D24D462FULL, 
            0xFBAACC30ACE1A384ULL, 0x1DD97F1F83036B9DULL, 0xBBB333A2448BD917ULL, 0xBDFD081E7BEF85E4ULL, 
            0xC3EEEB3E903644A6ULL, 0x33ED0A20412637A2ULL, 0xE05553A4824D2328ULL, 0xB97E7FC2A2FC4941ULL, 
            0xB77302A98FE3E726ULL, 0x147829C093F3B572ULL, 0x9D802BC2BD606E70ULL, 0xE17CA042CA11CE04ULL, 
            0xC14CBFD1C6EFD572ULL, 0xB8A41ECEDF3A5AB7ULL, 0x9F360EA619465768ULL, 0x266DBDEB2C74BDBDULL, 
            0xE41C601092FCB01BULL, 0xB524BD019435C672ULL, 0x8C4FBC1342A8328FULL, 0x92EE0EE0FF64F4C5ULL
        },
        {
            0x88707FBC7D206B47ULL, 0x58787DBE8D95BEB0ULL, 0x31BC634C4A496315ULL, 0xA4FFB432567024C4ULL, 
            0x549C4EFBF2E8CC62ULL, 0xCC892A9633484956ULL, 0xF56F98360D8C233BULL, 0x57E2DD4BC67672DBULL, 
            0x1A30D1141EC65602ULL, 0x51508521F54D2C14ULL, 0x0DB091D3C7246E3CULL, 0x55117F3F0AF2E64DULL, 
            0xC7E77E9451F42646ULL, 0x5D7B251DC5B98088ULL, 0x160F25E7B1878FC4ULL, 0x9F95F61AAAD27CAEULL, 
            0x11FDD4ED4AB5E02AULL, 0xC2F367A4288729C3ULL, 0x21C1E4242E4C0AE1ULL, 0xF49EF9F018A1D06BULL, 
            0x9D9BE638B1C947EEULL, 0x8EADAA96780D5056ULL, 0xC659847D551E08DFULL, 0xADC44861B81D28C2ULL, 
            0xA65217BF510E4F0DULL, 0x3C6B457E021987A0ULL, 0x06D2823D277C0C82ULL, 0xE3748B75210A6723ULL, 
            0x98D806C4B4F41A66ULL, 0x9C88E476C1C751B4ULL, 0x917F0A6631060BB1ULL, 0x6EBEA89FC9BCA708ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kPhaseCConstants = {
    0xFCEB279C3397A716ULL,
    0x5D4C1D820B43CADBULL,
    0xCB10CFFFA68EF622ULL,
    0xFCEB279C3397A716ULL,
    0x5D4C1D820B43CADBULL,
    0xCB10CFFFA68EF622ULL,
    0x7E6CA7F938269835ULL,
    0xF6364846DE6927CEULL,
    0xBA,
    0x8F,
    0x97,
    0xE6,
    0x4E,
    0x2B,
    0xB4,
    0x15
};

const TwistDomainSaltSet TwistExpander_Vega::kPhaseDSalts = {
    {
        {
            0x408FF3A3D2986125ULL, 0x4B82D5098ACEEB42ULL, 0x44AE7E727783FC8EULL, 0xA72C932191C58B26ULL, 
            0xBF5B23CCABE5DC76ULL, 0x8A9B3C5AC1703596ULL, 0x65EC63099DF18348ULL, 0x0A10671CA86C76A1ULL, 
            0x6AFA5C7594369172ULL, 0x80CD0A251ADC7346ULL, 0xEC92856D992B4A50ULL, 0x3DCA2C7C6F644703ULL, 
            0xD8F7C7E30EBD3A63ULL, 0x0C4C653D6E25D2E4ULL, 0x9A2089D09AF93654ULL, 0x28687A6091702C18ULL, 
            0xFC3CFFF5C17907F6ULL, 0x2BD9F7D7C0AB788CULL, 0x870EE5CEFA92CD6DULL, 0xD121A58A44029654ULL, 
            0xD0927475CA7B46DBULL, 0x27AAB410CF486156ULL, 0xCD52B8F12A425D77ULL, 0x990C34732B20A0F7ULL, 
            0x7F2DAA7EB8377030ULL, 0xA45F4310ADDDD114ULL, 0xA608091744E3B8D7ULL, 0x8B32A02A60E68159ULL, 
            0xE704D77FC1F85600ULL, 0x037D682D28B5CA91ULL, 0x18706750D1DE5284ULL, 0xA898889D042ABC15ULL
        },
        {
            0x49BDCB551720C9C8ULL, 0x6E8E35C69A3E1C44ULL, 0x3F2348FB7374183CULL, 0xE9361AFC2EE3DC44ULL, 
            0xEC84813BF1453A43ULL, 0x98709732D3A7C452ULL, 0xCEA2DD3A5DE8505BULL, 0x50887119FE70192AULL, 
            0x90A37BC3F28579F4ULL, 0xAFCAD75A5A79E3B5ULL, 0x4540852CFBD1B33BULL, 0x99827917EE4859F2ULL, 
            0x83A07B150C5EA2E6ULL, 0x7A26F9C924BF2D4AULL, 0xA18D6444E82F5CEDULL, 0xF35A5716DA5A88B2ULL, 
            0xAE923930881DB962ULL, 0x08BCC1ABF07740ABULL, 0x997E820D85ECF87EULL, 0xB161D7C7FD365929ULL, 
            0x02C39526E858B1FEULL, 0x5E7AC29F9F719993ULL, 0x675051CB83B8861BULL, 0xB8EB02BDFA4FF875ULL, 
            0x9F4748A73D3D7CB6ULL, 0xECE8A399A66ACBC5ULL, 0xD9D7956B9FE6FBCEULL, 0xAC1EE1E5443876A8ULL, 
            0x09F75C795A06958BULL, 0xE14486795020E802ULL, 0x620ACB706AD08F7AULL, 0xF63257310DF37BE3ULL
        },
        {
            0x1A13A55D3DF87CBBULL, 0x2080D44DF405B6FDULL, 0xEFEE8277AD8655E6ULL, 0x9A5AD820E054AB39ULL, 
            0x83BCFE9EA0FB7DA2ULL, 0x95EB481087594F22ULL, 0xA0F78D19EC7AA856ULL, 0x8B89C21AB20C0EF4ULL, 
            0x6D46071DF5DD9987ULL, 0xCD755A44D5F2096AULL, 0x13E98B99DBAB054FULL, 0x8C119BB8EA53B43DULL, 
            0x0556432C25B92C24ULL, 0x65E383BC419EC293ULL, 0x9FBC1F3DB70328CBULL, 0xAC6F9E6F533F7EC3ULL, 
            0x7868274434820AC3ULL, 0x471C2990850A0D28ULL, 0x462AD71ECF067286ULL, 0xE00F9D48619743DEULL, 
            0x505620925FAA6473ULL, 0xF9471C9A3B43FEFEULL, 0x5D62F888DF2E2F11ULL, 0x1269CF36AF4BB0ADULL, 
            0x4667647547825E2DULL, 0x62838D8B3BB09571ULL, 0xF94F8D23E876973FULL, 0x6A4FF4249A939F87ULL, 
            0x231200CBCEC97BF4ULL, 0x1769F2FC6A32ED90ULL, 0x6B7B27C164374785ULL, 0xF80888F23DCA991CULL
        },
        {
            0x673E263234FC6681ULL, 0x2109FC3820D2ED83ULL, 0x88595C1508970912ULL, 0xAEEEB72D4FB17FE3ULL, 
            0x9AEBAB8AE195C946ULL, 0x9E1F018A1A8158F4ULL, 0x31975400E710F072ULL, 0x66F97F46125D8FC5ULL, 
            0xF6D2214A9938C2DBULL, 0xCDF1CDC44FC51796ULL, 0x91CB2D4AEDBCD436ULL, 0x871B88A167C737A3ULL, 
            0xFD80D2949186A974ULL, 0x3D206B7E10DDB6DFULL, 0xF0BBE26730D3F498ULL, 0x26CBBD33A079765DULL, 
            0x482069F1785E76FFULL, 0x82E92A3EAE7AA735ULL, 0xB3F7083CF1D8CCB5ULL, 0x36DD7601B998450CULL, 
            0x933E50E5C3BD35D8ULL, 0xC7235B355C1BEFA6ULL, 0xF1EA7B0AFFC87F0FULL, 0x4496B101302066B4ULL, 
            0x5112EEF923440F30ULL, 0xE8B59B8FFCE4EC3BULL, 0x33B74F709B44DBB9ULL, 0xEA898EF5459CD283ULL, 
            0xDD6CC5F5E6907806ULL, 0x8706996A9A15214FULL, 0x58A792980992874CULL, 0xD0B04A2193DDCC82ULL
        },
        {
            0x9AFAE970C013A162ULL, 0xA8AD9228BB87E48BULL, 0x6C5E129525D5D211ULL, 0xCD2C30AB4A3C36BFULL, 
            0xE55FEB33750BD0D5ULL, 0x0C421C5FA2554A57ULL, 0xD9A88F1F25B5942BULL, 0x43B9FEC34877B15BULL, 
            0xE0D2B84527C2F515ULL, 0xC74A33725935A0C9ULL, 0xD4C7A8E21D2DFC8CULL, 0x303F33B6AE4257A7ULL, 
            0x77137F54B2311063ULL, 0x304C10FCE332D811ULL, 0x343C02FE73505036ULL, 0x5C78CADAEE2EE7CBULL, 
            0xF64E1CF9B22FAE26ULL, 0xE578B2316E18FE88ULL, 0x87C725CAA0A6987AULL, 0xB774A83450FCF952ULL, 
            0xA4277857F1AB1BBFULL, 0xFF8A84739F82C56AULL, 0x16A966225EBF58C5ULL, 0x1A8BE43E8C1F9716ULL, 
            0xD0267A079192F736ULL, 0x038215DB804692ACULL, 0x72FEEF8DC32E9256ULL, 0xC6CA7AF80CA6A5EBULL, 
            0x0A2429437A5197B7ULL, 0x079D8A8A05EE1FBAULL, 0x195C2884A56E1262ULL, 0x6BC0D4CF9B9C18CEULL
        },
        {
            0xAAEFFF4BA2E715B4ULL, 0x5F82A50E64D1241AULL, 0xD2BAED42E0931883ULL, 0x1260E21848234B48ULL, 
            0xC8E0580401CA9822ULL, 0xB02C0A4FB06A60ADULL, 0xAE267FC8551E21AAULL, 0xDFBDC22EE907A09EULL, 
            0x2F9CB897209FB2B4ULL, 0xD4729036893EB307ULL, 0xB7F41E05DACC9314ULL, 0x1D886C1D0AA9C023ULL, 
            0xC1C7F4F4AA1B3791ULL, 0xE0E8FC9C3A3FAC56ULL, 0x6E7906D9E2D8B126ULL, 0xE2EF886C905DB6EFULL, 
            0x72A0D4C944D100A5ULL, 0xA20325E3DB7C03E3ULL, 0xC3D0D9727776FB1DULL, 0xB8673AB2105FEA23ULL, 
            0x5B4B539BF4AFFCCBULL, 0x6FC786921105C9D8ULL, 0xC8EFC12DAA0DD78AULL, 0x0DCE4E3661D3FC47ULL, 
            0x161F2D041FFF589FULL, 0xC9F0DF2CB81F84C4ULL, 0x855C44A14C4DE78CULL, 0x27D295FC8DA76DD6ULL, 
            0xE9164521E42BF265ULL, 0x72C335A742914118ULL, 0x78322070311A6312ULL, 0xE62D88ECB211216BULL
        }
    },
    {
        {
            0x810DC651A26FBF1FULL, 0xAC7AFA3B4401729AULL, 0x4052771DC05E371DULL, 0x92B97ECF0C8D212AULL, 
            0x24C052031C552091ULL, 0xE47DE9EDAB5F3534ULL, 0xE1487E7AE08A90E1ULL, 0x86F80F0C187FBA53ULL, 
            0x3B6A464D022F1A20ULL, 0x4786A13E0B2B771BULL, 0xCEC8AE72E88B8CB6ULL, 0x0CF24DF6465663C9ULL, 
            0x9303CAD040377D3DULL, 0x56BBE50330601A66ULL, 0x69B4AE78619BACB9ULL, 0x689EAD560EF77AD5ULL, 
            0x38043B9598459917ULL, 0x8520FDD501EF6963ULL, 0xC3F8AE71B16CCE9EULL, 0x29E97F0A609049B8ULL, 
            0x88EEFDC6F44A510BULL, 0xA27CD0035B2530E5ULL, 0xD36073935DE4AD85ULL, 0x8FEE7FA3EFCA7F06ULL, 
            0xDA22BAB171E90007ULL, 0x6DB70CB71BF714EEULL, 0x8317919686546B08ULL, 0x4FB6C4DB6166135AULL, 
            0xC1F5D7BE2E7F7DDBULL, 0xB566761C41BC4E96ULL, 0xB03F98924F5F29A3ULL, 0xA136F0972C2A0E9BULL
        },
        {
            0x24B5B173D08C904BULL, 0xE19FB63630EFB82FULL, 0x0AF26A8E7929B3F8ULL, 0xF312C864731F33D7ULL, 
            0x5EF853F73371B5AAULL, 0xFD35E9CCF2C3E655ULL, 0xE77AEBF3356F9FA2ULL, 0xCD657F7117F023E4ULL, 
            0xC0B06F6DBAA5DF85ULL, 0xBCDA4AEB8474F7F6ULL, 0x4418DC0450D5A989ULL, 0x84A5B2F3A6877BC7ULL, 
            0x3B5ADD5DA181892AULL, 0x3B76B1ED387C31B3ULL, 0x99145E83FC8A664FULL, 0xBB7E0270E02672FBULL, 
            0xAD3CC76716CFAA68ULL, 0xE412A5842CC082EEULL, 0x1253E555E6734B77ULL, 0xAC453AFF991DCA4CULL, 
            0xE6FF876D4047B491ULL, 0x258D142CE1466086ULL, 0xE71A8EDA52D8CC1CULL, 0xA893CACB9F7DD7B7ULL, 
            0xC7D52796D81884CFULL, 0x7F6804A287A3A7E7ULL, 0x25AC1FE4AC2F9662ULL, 0x99F02F1281618850ULL, 
            0x5E30EF635D5E89AEULL, 0x00C39FD801D0D335ULL, 0x179150B56D55667AULL, 0x0CF77F055041CF25ULL
        },
        {
            0xB0FCFC725DEAA6B9ULL, 0x058398D9B22A7CC9ULL, 0x3A066C02BC150AF5ULL, 0x1F7ECF0462395F4EULL, 
            0x2FE0E5F2DB849513ULL, 0xB365DA71E5606980ULL, 0x1580388A2327B41DULL, 0xBE54AB961EB72325ULL, 
            0x7AF1CC5C0863977FULL, 0x34AAB2C0F7D1FE39ULL, 0x273178B6784D3AFCULL, 0x4A20DB40C4DDF340ULL, 
            0x003F3723A15C5C74ULL, 0x05ED53FC69586820ULL, 0x0DD597DD008103D6ULL, 0x9869788CC5BCECC8ULL, 
            0x3736C7AE2EC07FBFULL, 0x7CBE834696B96B22ULL, 0xF90ED8F7032B9B5DULL, 0x0238B3A0AC4EDCFBULL, 
            0xD178107C49C10ADAULL, 0x3B92516A621DA473ULL, 0x772B0C6904EE48D7ULL, 0xAD48A83C8B6FE2EFULL, 
            0xC86D0F9B254FD26FULL, 0x4DF245990DC25D97ULL, 0xD2911BDEFEBEDC9CULL, 0x05537B0B434F3FDFULL, 
            0x64A9C9047A6DF517ULL, 0x3CDDAF40C44267D0ULL, 0xB98CFAC64B015E5EULL, 0x459FD23989AB1E46ULL
        },
        {
            0xEFD01A54069F79F9ULL, 0x2DD6207D0C673AA5ULL, 0xE470362A9C489238ULL, 0xAB3E9A888A425537ULL, 
            0x5EFF5727BDC23D06ULL, 0x622447AD64DDAE7CULL, 0x25DB0DE8D8FE61EBULL, 0xA0896C0373D51660ULL, 
            0xAC85A281550DD189ULL, 0xD2F682BBDEB98F3BULL, 0x3B6EF550B94631D9ULL, 0xE4770A5548C6DBDEULL, 
            0xE02B580221071697ULL, 0xC7FADFA7D29E0A1DULL, 0xC3F9594ADA368FD1ULL, 0x68492A3435CF033DULL, 
            0x4ED85CA36094AC6FULL, 0x8DBF3E54FAF6B30EULL, 0x88476F21F2D30EC9ULL, 0x6C26C0D52FDC9A06ULL, 
            0x5F53FD4639FFC7EDULL, 0x25192C5B4602A8E0ULL, 0xB4A3878270B3E12CULL, 0x8604C4C776A18E98ULL, 
            0x7931B72DE56DE5F7ULL, 0xADADF2003315176CULL, 0x3E39F1CAF3C268D7ULL, 0xB981273375FD5439ULL, 
            0x28B9089FECD9666DULL, 0x7203E5A71268B368ULL, 0xAD4A53D61B9219DAULL, 0xA0C96053374216BEULL
        },
        {
            0x7DB7072C4263A591ULL, 0x455E2FBD54C897C1ULL, 0xBB5B3EC13C48AC68ULL, 0xEA52F6A6359AA180ULL, 
            0x826402310E75B660ULL, 0xD4CA56C94B742D49ULL, 0x959D586D79044490ULL, 0x5EDA017FE83E6744ULL, 
            0x7AF1192451214448ULL, 0x1C3928548C81E6ACULL, 0xD7058137F1C23EB7ULL, 0x4C8E0EECF139856DULL, 
            0x6318FB6E139D67ABULL, 0xC182F002AD91E41AULL, 0x636C91796C672280ULL, 0xE4C25DD2B8E29782ULL, 
            0x9C791C606B51D51FULL, 0x09C48B993A4A037DULL, 0xE1A4F3CEB9FF385FULL, 0x35F66293D5A2A4B8ULL, 
            0xDF3B02FD0E5258ADULL, 0x030261FC08B2A675ULL, 0x9BD22BDD469AF6F5ULL, 0xB71FC4EC0CE6BDBBULL, 
            0x85B1C4BC4166C260ULL, 0xE98E92E8A3F505CCULL, 0xD527DA295F7F41C5ULL, 0x4745B5CC817899A9ULL, 
            0x59D1649071567897ULL, 0x4D5916EED791DF3EULL, 0xF44740022E658035ULL, 0x29E18B699F14197AULL
        },
        {
            0xE564F8C9EF1A600CULL, 0x230BEBA09970ECFDULL, 0xA53CDECD24C4E5BEULL, 0x8D96DBA0C43C7451ULL, 
            0xEC0D6E580B8C93ADULL, 0xEC6984E6DE06ECDEULL, 0xC037D61E5E72FD90ULL, 0x91FC9285F162F40FULL, 
            0x94BC657AEA4A5747ULL, 0x6CB0AA210693853AULL, 0xEDCF68FD979F76B8ULL, 0x35F269158B6F41D4ULL, 
            0xB118443EB3F63B67ULL, 0x90E6B41593C1D1B5ULL, 0x006659A25F6D2875ULL, 0x82E8FD86BF087DBBULL, 
            0x9167DC4092485885ULL, 0xE33C374F1550BFE8ULL, 0xB9EC5F22C9E38E15ULL, 0xF972FC7BB8771A18ULL, 
            0x7513BD1A41FB386DULL, 0x2F4393A03EC92A70ULL, 0x2D52632209AA5C99ULL, 0x3FD11D34F90FCDF5ULL, 
            0x905326BFCFF627B4ULL, 0x501B974774E616ECULL, 0x0ED1ED9C7B609020ULL, 0xF0B64D7944C668EFULL, 
            0xD0D8ECEE8AA2CB6EULL, 0x584E1A533B03ACAAULL, 0xFE21D76586EB5AA1ULL, 0xB043C6B2811E31DAULL
        }
    },
    {
        {
            0x15922DB76478D960ULL, 0x5D4A6DF286B288C9ULL, 0xD23F895A4E05A614ULL, 0x456F1C5F9FDE9CFFULL, 
            0xFC8EB128839E0D48ULL, 0x347A9DF4EDC291E3ULL, 0x73859510CD709662ULL, 0x37E917A0B5A2FF2CULL, 
            0x31B65AAA73A2DCEDULL, 0x166AF89D12B972ECULL, 0xCC6F4D701947B6DEULL, 0x5673D52A63392824ULL, 
            0x020FC50A4E3EFF65ULL, 0xC97838DAEDF6FC1DULL, 0xFAE4AE96C24195DAULL, 0x35C4AFCBA5C9C46DULL, 
            0x085B03E5E03BF04FULL, 0x66740D5968944278ULL, 0xCA626BE7DEA41B0DULL, 0x167172A51819C4D0ULL, 
            0x6B2EE581D24FC632ULL, 0xC9D4E1F39723FD0BULL, 0x003FD752EE6703FFULL, 0x1AD17579C667BB61ULL, 
            0xB6463513203A6B33ULL, 0xFF811E175DAA1F8BULL, 0xA7B84B85AFF21DE0ULL, 0xFE01494C7B93FEBCULL, 
            0xC017521E3507382EULL, 0xDAD259887D30A990ULL, 0x227FC150B60BF80DULL, 0x7F8FE7E6FF0997D6ULL
        },
        {
            0x06393F9E60E7F43FULL, 0xC5CF054E1C93ACE8ULL, 0x1FF077A444AE4CFBULL, 0x146C434D3CAB683CULL, 
            0x84235F3501C38E2BULL, 0xD8CBE9D9C626D761ULL, 0x2390D1C920826102ULL, 0xB4BE65363B16F914ULL, 
            0x74E88A06471E2C2AULL, 0x733E3666C852846FULL, 0xF973FCA0F3B3B601ULL, 0xE9C4DB7F042AED12ULL, 
            0xE562B8C4E15315BAULL, 0x845C8AB0944356B4ULL, 0x416D9239EB908C9DULL, 0x46A3600FACDDA05DULL, 
            0x89F0D4B719529349ULL, 0xA119D7EA7572E4E7ULL, 0x2D599C54A508113FULL, 0x3DBE609C4F269D92ULL, 
            0x6E5EB8A0ED39791EULL, 0x29B4BFFF9F6B4AF6ULL, 0x80449DD10AA27183ULL, 0x28D675AB6BD9A1D6ULL, 
            0x5892D80B33C61ECDULL, 0xDB5DD28ED0E75C7AULL, 0xA7D5CB9E6DB91553ULL, 0xDDAABFEADB146331ULL, 
            0xC484794A08E6463AULL, 0xAA8E30FC53C90BACULL, 0x2A29ACA33DCDEC2FULL, 0xB86322C8A20524F0ULL
        },
        {
            0xFA3EAE65E9426282ULL, 0x7784DA1113DBD410ULL, 0xDF7A2D402AE9EFEFULL, 0x1F9A2A2580BB97B8ULL, 
            0x9F683072CFE1B935ULL, 0x7980346C04CC1CD3ULL, 0xB2FD462644C39270ULL, 0xD26F3FC2F9C633A3ULL, 
            0x5FC5201689F84DBEULL, 0x80E809C1DC65C9BFULL, 0xAC560F58E0F40A03ULL, 0xFE84EF33646C9493ULL, 
            0x71200EB7FB3B1BB9ULL, 0xC56AA1FA74630666ULL, 0x5E1A229F4F82B108ULL, 0x9F049B096D6A49A6ULL, 
            0xB41E046A67E56D29ULL, 0x92D91729261B5DA2ULL, 0x64E34224F00F0F51ULL, 0xECF40FD9D5D9F6DBULL, 
            0x95F5897408433C9BULL, 0xE0D9A5BED5805131ULL, 0x7F15BFE792DECE5FULL, 0xA73403234FED146EULL, 
            0xB07087E116FF1030ULL, 0x8E3C14A644EB02B7ULL, 0xD9E7D927F79F63A3ULL, 0x9A67D47BC3226567ULL, 
            0x8FC31843C3451161ULL, 0x0C215508BE9FEB98ULL, 0x596743BBE4338F70ULL, 0x594B23B6A8A35B06ULL
        },
        {
            0xB2A452DD526E4228ULL, 0xFC58E8084C284141ULL, 0xD1EF5F57AB73C4E9ULL, 0xB9AAB2FCD00688B5ULL, 
            0x36C0A00A70833ECDULL, 0x53F0CDBFECC27829ULL, 0x23B6A8EEF5F707D5ULL, 0x6AE29E84E71D2A13ULL, 
            0xF895F3778C100151ULL, 0xCE197E499D1DC230ULL, 0x9C6E3E9B94FA4280ULL, 0x11E6A442D972E6A3ULL, 
            0xD4BC906BA12791F2ULL, 0x1D80730D5975C8FBULL, 0x33BB2A778AA8AD74ULL, 0x0CCB8A8A5580C522ULL, 
            0xDFEA88671A4FB454ULL, 0xABEAFF7F10AC2C24ULL, 0x7C4E41AEAAF6A996ULL, 0x7EEDDD85AB003EEBULL, 
            0xFA22F47E6D37F4FCULL, 0x7CE2E91E85B2056EULL, 0xEC2D38BAEB3EC459ULL, 0x7D00567987490D6BULL, 
            0xC48450C1BCEF241FULL, 0x7245345EABDCB41AULL, 0x92C41E3EAAD7841EULL, 0x157717200FCB7A9AULL, 
            0x965323978470684CULL, 0xD6BA3FDEA242BE7CULL, 0x82AD5F2EF12368BEULL, 0xCA9BC4BA32C493B2ULL
        },
        {
            0xA64F462CF32EB3A3ULL, 0x56826FB2EF9750EEULL, 0x48FE526E0C099CB2ULL, 0x4034DC55D458E256ULL, 
            0x2BE1824295536D20ULL, 0xDF666A224CFF4177ULL, 0x4D7D1DEC92C6EC93ULL, 0xD117F0028E653DB1ULL, 
            0xB73BEF46778F6C8BULL, 0x0B64712C45A72ECDULL, 0xDC3FDEBC47593038ULL, 0x78CA202A07D16EF5ULL, 
            0x36976BD6690D6ABBULL, 0xA9D639434F1EC600ULL, 0x883FDD79C7C868F4ULL, 0xD593815142E5DC60ULL, 
            0x8FE2866178EC62BFULL, 0x0149BBCD0808C338ULL, 0x90BD0B357E097EF6ULL, 0x9A29BD2225B505C1ULL, 
            0xA95223E118FEC6E0ULL, 0x52A94E5351165BE0ULL, 0xE73B0C86224D914AULL, 0x34A4051E4AF01BCAULL, 
            0xAB02D089C22F4927ULL, 0xB3E508E4E9894CC5ULL, 0x86B6A02FF29C0A89ULL, 0x377CC29C4DAFAA3FULL, 
            0x615EB69194F6063BULL, 0x317E0A5BDC6BFF8EULL, 0x9D47A49432176F0BULL, 0x080707FBA0DEE807ULL
        },
        {
            0x10F06E240D54C2A2ULL, 0x724079A63E9EF586ULL, 0xEF1F578094F92FAFULL, 0x54FD230DB585945BULL, 
            0xF205143E379B728CULL, 0xB8F949066E8E5242ULL, 0x9F9BCFF34A360891ULL, 0xB48A017A3FC3B69DULL, 
            0x7BFECCFA2242634FULL, 0xE605AD2D0E71F058ULL, 0xD97C3B8503D33CBEULL, 0xD125D855FBCC207BULL, 
            0xA65165FA3BE1BF47ULL, 0xCB7DBCB1F5800316ULL, 0xEA6212D7C4C7D9B9ULL, 0x74A3E7C4B8C5EC9FULL, 
            0x52FD8BD9339DB31EULL, 0xBF9EC84B881B21F5ULL, 0x5204B73C31DD1AA0ULL, 0xA32912374A1D8667ULL, 
            0xE7CFF6CD11068A6DULL, 0xFEB4ED1465833E62ULL, 0x35A46AB168EB37A3ULL, 0x39536E04609240BFULL, 
            0xC80C60528EAFF7FAULL, 0x2C8B72019B21DBC2ULL, 0xBB5846195ED2A658ULL, 0x8E05427B25E4768AULL, 
            0x352E4AD90C4D9037ULL, 0x67B0A51D16424D3BULL, 0x7F23B4F5DA2E6FA0ULL, 0xB4E8CA58E33A66D4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kPhaseDConstants = {
    0xF57BE7665C9E43A5ULL,
    0x4471841213BB6E46ULL,
    0xF8DBD1F174803025ULL,
    0xF57BE7665C9E43A5ULL,
    0x4471841213BB6E46ULL,
    0xF8DBD1F174803025ULL,
    0x29A9D2F474F9D741ULL,
    0x57F027889AF0EF74ULL,
    0x1A,
    0x19,
    0xA1,
    0x10,
    0x75,
    0x80,
    0x75,
    0x39
};

