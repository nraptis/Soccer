#include "TwistExpander_Polaris.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
//
#include "TwistShiftBox.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Polaris::TwistExpander_Polaris()
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

void TwistExpander_Polaris::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9EBBC7CD9E91F4D4ULL; std::uint64_t aIngress = 0xD766F9EF04FA681FULL; std::uint64_t aCarry = 0xAFCB197F031E59DAULL;

    std::uint64_t aWandererA = 0xA3A2C46D0B88D922ULL; std::uint64_t aWandererB = 0xFF52E4CC9C290C04ULL; std::uint64_t aWandererC = 0x998868649E8DF668ULL; std::uint64_t aWandererD = 0xDB04A0B15FD776CDULL;
    std::uint64_t aWandererE = 0x878A7588D9B90761ULL; std::uint64_t aWandererF = 0x95B811E26599B551ULL; std::uint64_t aWandererG = 0x85D6B3E1D136F8F0ULL; std::uint64_t aWandererH = 0xD5CE0828E4D032CEULL;
    std::uint64_t aWandererI = 0x9C86DC1B01AD59A4ULL; std::uint64_t aWandererJ = 0x9AF1BFF330634129ULL; std::uint64_t aWandererK = 0xCA4F0282B16A5B16ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCF4FDBDBFA494468ULL;
        aCarry = 0x8FCFFD4415EE8018ULL;
        aWandererA = 0x8506EFCEACE8F4C7ULL;
        aWandererB = 0x8B24C1921C2923CBULL;
        aWandererC = 0xFCFC7D4F818E1C63ULL;
        aWandererD = 0x91C15981F43EEFAEULL;
        aWandererE = 0xD0AF4900303B8F40ULL;
        aWandererF = 0xDCC950B7032A6692ULL;
        aWandererG = 0xBB00525F7789CF04ULL;
        aWandererH = 0xB06F94267208E195ULL;
        aWandererI = 0xEF7B84C62B4EF2DBULL;
        aWandererJ = 0xBB15D07728C14773ULL;
        aWandererK = 0x90476996F4AA3202ULL;
    TwistExpander_Polaris_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x95EA03393F07ADCEULL; std::uint64_t aIngress = 0xA7A7F17193E6C6EDULL; std::uint64_t aCarry = 0x82A27AB58ECD856EULL;

    std::uint64_t aWandererA = 0xED176EC6CFD5FF4EULL; std::uint64_t aWandererB = 0xED2F32156E795AFEULL; std::uint64_t aWandererC = 0xF60CFC0A460CF4A7ULL; std::uint64_t aWandererD = 0x9DEE57694EEC724CULL;
    std::uint64_t aWandererE = 0xE652ED71CD056B3CULL; std::uint64_t aWandererF = 0xA5E053F0BD5BFA3EULL; std::uint64_t aWandererG = 0xE130035FC2013627ULL; std::uint64_t aWandererH = 0x886051075A9E9B2AULL;
    std::uint64_t aWandererI = 0xD4C9F8BD2B6C1646ULL; std::uint64_t aWandererJ = 0xCB465BB83C1FF476ULL; std::uint64_t aWandererK = 0xC2CFF929215E7BC6ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD2A9FD35CEED3DBDULL;
        aCarry = 0x8F84EF1056A449BCULL;
        aWandererA = 0xA65D6643DABACECAULL;
        aWandererB = 0xA9F621DF8171C81BULL;
        aWandererC = 0x8DB9E2D03F6A0BFBULL;
        aWandererD = 0xE5A89C588E26BC50ULL;
        aWandererE = 0x9E1D6AEE04D75A91ULL;
        aWandererF = 0xCF3E843AEBE78DB1ULL;
        aWandererG = 0xAD42885E9425C4D3ULL;
        aWandererH = 0xEC0BD1A22B30CD94ULL;
        aWandererI = 0x884FC7B3E629016CULL;
        aWandererJ = 0xA6172D4BCA39A1E3ULL;
        aWandererK = 0xFA24EC274035A634ULL;
    TwistExpander_Polaris_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Polaris::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF0D949AC4DC395D2ULL;
    std::uint64_t aIngress = 0x920F8DDEBBD14CE7ULL;
    std::uint64_t aCarry = 0xD967C9D205D8112FULL;

    std::uint64_t aWandererA = 0xBA313DFBC01E94F8ULL;
    std::uint64_t aWandererB = 0xE8460B69DD93CA18ULL;
    std::uint64_t aWandererC = 0x8E3E2B708067FF70ULL;
    std::uint64_t aWandererD = 0xA6B9CEA5D088D658ULL;
    std::uint64_t aWandererE = 0xF99F666BAC8D5D60ULL;
    std::uint64_t aWandererF = 0x91922D2B4C91E0FBULL;
    std::uint64_t aWandererG = 0xD851B7E11634BC28ULL;
    std::uint64_t aWandererH = 0xC4F13B03CA865A07ULL;
    std::uint64_t aWandererI = 0xE296BD384B43EDD3ULL;
    std::uint64_t aWandererJ = 0xA4F6F6FD822F7C07ULL;
    std::uint64_t aWandererK = 0xCFCBBAC44A2E0181ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneC, 0);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneD, 1);
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
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneA, 2);
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
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneB, 3);
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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
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
    TwistExpander_Polaris_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgD;
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
    TwistExpander_Polaris_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 24 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 914 / 1088 (84.01%)
// Total distance from earlier candidates: 21430
void TwistExpander_Polaris::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1673U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1531U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 737U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1159U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1659U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 150U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1621U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1519U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1297U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1283U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1708U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 371U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1795U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1752U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1553U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1764U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 212U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 902U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1117U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 756U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1635U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1180U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1127U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 264U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1930U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1209U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 971U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 16U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1236U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1577U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 912U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 94U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 963U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1474U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2000U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1275U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1834U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 559U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 522U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1243U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1719U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 575U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1147U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1629U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1050U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 700U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1428U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 305U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1015U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1224U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1376U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 662U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1679U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1582U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1053U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1328U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 873U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 32U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 222U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1966U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1983U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1060U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 719U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 213U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Polaris::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC517F3206B173F62ULL; std::uint64_t aIngress = 0x830D53E314368283ULL; std::uint64_t aCarry = 0xB25E757BD2024715ULL;

    std::uint64_t aWandererA = 0xF8F73C5E6714F07EULL; std::uint64_t aWandererB = 0xF17C1697ED683C9AULL; std::uint64_t aWandererC = 0xADF96DA0586658D5ULL; std::uint64_t aWandererD = 0x8A8180BEDA62FC7CULL;
    std::uint64_t aWandererE = 0x80A30B2791143D4DULL; std::uint64_t aWandererF = 0xDE0BCD7C19026507ULL; std::uint64_t aWandererG = 0xF57848B505822E13ULL; std::uint64_t aWandererH = 0xF142627C2C460930ULL;
    std::uint64_t aWandererI = 0xD7FFA9B3E0D00DECULL; std::uint64_t aWandererJ = 0x8852B8156F040107ULL; std::uint64_t aWandererK = 0xCA895F0125849002ULL;

    // [seed]
        aPrevious = 0x8507372ACFD622E0ULL;
        aCarry = 0xCA6F75855D000D00ULL;
        aWandererA = 0xDAE49EBED9282017ULL;
        aWandererB = 0xB59C1DDE6E40DB17ULL;
        aWandererC = 0xA6D2B385379705EEULL;
        aWandererD = 0xD765D2FD49F58CBCULL;
        aWandererE = 0xF5C6DE4FCCDC239FULL;
        aWandererF = 0x83369D3E974AF495ULL;
        aWandererG = 0x996BE3735D1D7E68ULL;
        aWandererH = 0xA01E340642054FBFULL;
        aWandererI = 0xB6DD06EA8850F351ULL;
        aWandererJ = 0xC61C89F3419A38BCULL;
        aWandererK = 0xB3C0E24AD823D48BULL;
    TwistExpander_Polaris_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
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
    TwistExpander_Polaris_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    TwistExpander_Polaris_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 24 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 12504; nearest pair: 491 / 674
void TwistExpander_Polaris::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2530U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1226U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5849U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 767U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4247U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1360U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1179U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6529U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6654U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5593U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3940U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1097U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5138U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5784U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7453U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 660U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1553U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 135U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 526U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1332U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1957U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1334U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 956U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1361U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1360U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 79U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1708U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 604U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1223U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 241U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1859U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 891U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 24 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 12499; nearest pair: 454 / 674
void TwistExpander_Polaris::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5842U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3775U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2552U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7787U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2150U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8189U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3587U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4040U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 735U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3913U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4301U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4148U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 10U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6338U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6871U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2427U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1658U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1902U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2012U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 676U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 154U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1324U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 426U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1033U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1619U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1093U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1257U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 11U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1290U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 687U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1248U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2042U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Polaris::kPhaseASalts = {
    {
        {
            0xD7C5D3E60398FF3CULL, 0x1973F80C1040957AULL, 0x593551AA22DC7809ULL, 0x03DD778587250350ULL, 
            0x45C250B3002C7D7BULL, 0x5C781DDB9C14FED3ULL, 0x23C75FA5D2D8CB40ULL, 0x00FC2F7986ED62A9ULL, 
            0x05147B341302CE0CULL, 0x51A4C448261F5F76ULL, 0xF22BA7D5A7E35961ULL, 0x0A834BFEF8E89622ULL, 
            0xBC950944C939F0BCULL, 0x40BF83ED054ADEFEULL, 0x520BCF3704A61DDFULL, 0x6048B69EE188DADFULL, 
            0x110C0FF880CB395CULL, 0x96A86FAF23354AECULL, 0xA8C396CA88C86832ULL, 0x0F6BAE056544E218ULL, 
            0x78F3EA623227C421ULL, 0x6782A6A657B2FBEAULL, 0xDE6B8E8F26334321ULL, 0x9EDE8BFC70E274A0ULL, 
            0x53006C39FFBF1108ULL, 0x0CB30F34B20B60F8ULL, 0x4D2C3CD5C98725A6ULL, 0xC5136B683F9991B8ULL, 
            0x3B2AADBFC54AF2E3ULL, 0xE79D1C747A5626D5ULL, 0xF9F904B2695CA6EEULL, 0x623B5928A364A006ULL
        },
        {
            0x425150401A952140ULL, 0x2908569C61327209ULL, 0x3C692F5983ACD5DAULL, 0x1DD8EE1C2ED37DD7ULL, 
            0xDD2054A311A0E94CULL, 0xF2939A3AE6BA9366ULL, 0xAD5BC8C51504646CULL, 0xE3492ED6F2A45618ULL, 
            0xED32227A1A2283E2ULL, 0x23264632CC751D24ULL, 0x57CD71546A265DDBULL, 0x51D93F6664F8DD76ULL, 
            0x091805369DADA3B6ULL, 0x5A2EEA9AF042A7D6ULL, 0x82862F4402AEB08CULL, 0x491593DFDAB52429ULL, 
            0xB1460E59021A4B68ULL, 0xD0F8FBBC1F8D8F89ULL, 0x3AFB194756231D34ULL, 0xD78E7B18FEBC83D9ULL, 
            0x63569856F44193FAULL, 0xF9EB9EA56C8F27F5ULL, 0xC07EDF9335C2B4AAULL, 0xF712EFCDBB44665CULL, 
            0x14DEB2922B6CDF1EULL, 0xAE93A6FA982FE1B0ULL, 0xB65414F026491D6CULL, 0x58B6310A3506E008ULL, 
            0xB70B49A2EF1C6882ULL, 0x83710F23932CFB30ULL, 0xDA14E5987C711157ULL, 0x9EE7B829BBDF5A72ULL
        },
        {
            0x7D35AA12ED7A6E10ULL, 0xDFF6C37270BAFE39ULL, 0x2A5EE779EBE7BD9FULL, 0xAC511CED62D06D4BULL, 
            0x6FFA4A7E65206FCBULL, 0xF79076637C4752E3ULL, 0xD8AE0CCDC7226194ULL, 0xDCE67BB1A3388F61ULL, 
            0x92B112849C2F7B80ULL, 0x7AC33016CFEEDF14ULL, 0xF7D40159260DFA31ULL, 0x7C75390AA10F2230ULL, 
            0x32F73B15AF92BACAULL, 0xDDA27FC36CD3718EULL, 0xDF7993376DAD69CDULL, 0x25B6FF74CBD75B4BULL, 
            0x5703A94156AC72E2ULL, 0x73A869777E504443ULL, 0xEA48121C99F2ED25ULL, 0x1E2A9D9DC36B2635ULL, 
            0x348A9E6EEB2A206CULL, 0x973D984DAD9DD6FCULL, 0x305272A25585D95FULL, 0x66FCE3CABEB3F8A4ULL, 
            0x270A3307EE1367D2ULL, 0xAA39E9578333C228ULL, 0x6E2D035CBCD62D62ULL, 0x5333144B4F6C9385ULL, 
            0xA6DD9144870622E9ULL, 0x4A2296B7C5E48FBDULL, 0x97BA8F7613009CABULL, 0x4F4E52EC3166A393ULL
        },
        {
            0xCB45FB94C105821FULL, 0x684D64EEF1702112ULL, 0x5EFAFFDC34E2DD10ULL, 0x5CFC4D68EFE91283ULL, 
            0xA9A8E96C1DF0713FULL, 0xE15C6810817C5C8AULL, 0x4F645085D33C5ABEULL, 0xA78F142109C3166EULL, 
            0xEA0FA7D8C3D47912ULL, 0x8A995E7A3DC22D0EULL, 0xF1444510FFB4E7A4ULL, 0x4F2E84A8901F9955ULL, 
            0x89D41390F0D73E73ULL, 0xD5A80733889933A1ULL, 0x8ED79736489F4A47ULL, 0x58107EDFC3B4CDC0ULL, 
            0x935CD0AE0726CB86ULL, 0xF952297BF5E86782ULL, 0x195A54FDAAB0E4B6ULL, 0x11F3033309AB058AULL, 
            0xDB28529780515FFCULL, 0x5FBEA316FEC4C1EFULL, 0xC55C58E5CB303FC7ULL, 0x75A4DA4203A3F36BULL, 
            0xFCB4112BF4D2EF98ULL, 0xCEC45ECE9C553167ULL, 0x0C7554E83EC4942BULL, 0x4FEBCAF2E9A2B383ULL, 
            0x7D86294A95CC9BB2ULL, 0xF61508C5D5922242ULL, 0x5E932A889F1FC82DULL, 0xBEA3AD3D16904DA9ULL
        },
        {
            0x02ED74105FEA8642ULL, 0x51B7235084C03F23ULL, 0x57DB029AC25497A4ULL, 0x92434115BD2FB727ULL, 
            0x049C0D6A7B8507B9ULL, 0xD02787DCCD212385ULL, 0x6E656E259EE7ACDCULL, 0xDD033AEC2DCB0C05ULL, 
            0xE4655CBAF3EDF38FULL, 0xDE8B97433CE24A7AULL, 0x5C9D1B4B5E5CDEFBULL, 0x98E32AFB1CD520CBULL, 
            0xDBA3EAC3E5277092ULL, 0xC93D595201CAFF05ULL, 0x0E5F7A9C51E9F732ULL, 0x13F0D494FA59B50AULL, 
            0x2A2C38BEC05F5122ULL, 0x4B889DDF124B45F8ULL, 0xC007B083F7B8F70DULL, 0x44C38732266049D4ULL, 
            0xAF623CDF318C572FULL, 0xBE7CC3B27F0E27C5ULL, 0xBFE55EB69FB5F2FCULL, 0xF2E7A67A1DD37510ULL, 
            0x0C97D8C8F03284B8ULL, 0x11F1BC29B9C3A9C2ULL, 0xC35DEEE0475EE978ULL, 0x84C20ED1EEBE98C4ULL, 
            0x189C196D9B6912C2ULL, 0x94BA0DED7A2BAF77ULL, 0x1764CBE224E35BA5ULL, 0x6CAB1962F6FFDB5AULL
        },
        {
            0x297B47D6840F3432ULL, 0xE02B35B68C8CF4D0ULL, 0x39EC980C68C08957ULL, 0x0D4514D02D7AF5A1ULL, 
            0xC8F725EBCDF78488ULL, 0x53B141DFCDEE1E59ULL, 0x1A7F116BF6BBB2CFULL, 0x8B80C19298EC2C8EULL, 
            0x60B0A44DABFFD14DULL, 0x4B164F8DC74DDA32ULL, 0xA48C14527C982F1EULL, 0xA7EBB3A6B9BE1932ULL, 
            0x9975D3CD61B4C7E0ULL, 0xA786969046FAFA57ULL, 0x998C2CFFA9F169A9ULL, 0xED6C797A38D0A0A8ULL, 
            0x3F9339460D8F1D2DULL, 0xAD9F62797DEA3B14ULL, 0xEEDED51A73EB6106ULL, 0x44F9B9C86571F793ULL, 
            0x116D8A394CD0C285ULL, 0xBC6540C529A0CFC9ULL, 0xEF0243A02479C85AULL, 0x873689236644B315ULL, 
            0xEBE82C84E6405233ULL, 0x8B9956F986ECBF7FULL, 0x2ECA81D78BAE950AULL, 0x4993CD5E231985D3ULL, 
            0x2DB0779084FE4256ULL, 0x6820A532CAEFE689ULL, 0xE1C995D9D854E36CULL, 0x381A0C3B9DC715E7ULL
        }
    },
    {
        {
            0x34EB7874497AE790ULL, 0xA423A9BC39CFB1A3ULL, 0x4C7CC227C2CB7000ULL, 0x4FBB08BF6E5127C8ULL, 
            0xC2C74BA2A98C3472ULL, 0x1C500DE3F0981636ULL, 0xA3AC4B9BA0548FBFULL, 0x34913667CF29FD5AULL, 
            0x806052A3B8713AB1ULL, 0x114D979E0153E7A8ULL, 0xBD421211EC89728EULL, 0x0D76627C8177494BULL, 
            0xEE4FF5E8B28E8BE2ULL, 0x7ECE4406E9CDCDB0ULL, 0xA56CBA00BB4557C2ULL, 0xDDE8C96C9AC94582ULL, 
            0x37891BF38413F231ULL, 0x9B12B0D198F2C884ULL, 0xAB1AF277A7F2F485ULL, 0xA7550696111F9C1AULL, 
            0xF56E06E59FEB83ACULL, 0x1E6604E9983BBB30ULL, 0x4E6540F603FE83F3ULL, 0xE2AFCC69B7DA5E8FULL, 
            0x85C80303EAEE2FF7ULL, 0xAE8647217FB6E2B3ULL, 0x42019B4704FDFD7FULL, 0x3D2F09DECD3AACE3ULL, 
            0x8EDA1D14F89CC66DULL, 0xE0CDB2E1CBC2DA62ULL, 0xCCA910003B2A311AULL, 0x0ED775BE44F0AE5CULL
        },
        {
            0xA50312A53CE31636ULL, 0x2F9E81E503B23EBAULL, 0xFAD5F86F1E4F0D20ULL, 0x07EBF87BD5D2346BULL, 
            0x920C78D71A0AE1ACULL, 0xAB8237D7D7B46576ULL, 0xCA3DC40C393AF391ULL, 0xA361377BE4BE7AE5ULL, 
            0x59A18B7ACBDC46AFULL, 0x38548F65A37DACBFULL, 0xD7858D29F830DC8DULL, 0x39294AB59995DE7FULL, 
            0x3C707A330D0E3C64ULL, 0x3B0A6890569D6E58ULL, 0x0E62ED623F86265FULL, 0x9BF45D6F73274502ULL, 
            0x79D6B308E85E2C6AULL, 0x5E39D7D9CD528AB1ULL, 0x7451E10B6EBB7112ULL, 0x630B88A1575FD651ULL, 
            0x0C677C65099AA4F4ULL, 0x64C20E3D1B9F752EULL, 0xBBAA4AB0670C079AULL, 0xE989F820DFB39BADULL, 
            0x5DD75E917A7B6823ULL, 0x97E836DD3F5694CCULL, 0x5DD2199BE56FEF16ULL, 0xB824933638FF2AF6ULL, 
            0x460061855E045B23ULL, 0x5499A28367B6B06AULL, 0x1F6C76A46DB70E67ULL, 0xD56121FACBAAF81DULL
        },
        {
            0x6AF2D5130DF3949FULL, 0xAFC77D6A027B26B1ULL, 0x85723DA4A2E5D7BEULL, 0x91D3A0EC919E4D8CULL, 
            0xED7135147406DFB3ULL, 0x362A91326A9F60A5ULL, 0x6C1E49954D45FC24ULL, 0x4323B8E100EB8207ULL, 
            0xCEEEABD5BA22EA26ULL, 0x32613F15E2ADB882ULL, 0x56EBCC514A363923ULL, 0xB2D0A7D5EC7215AAULL, 
            0xA117D5CF18470B18ULL, 0x23453B7E9AD337E2ULL, 0x2D0D9821E38E2F01ULL, 0x25828463E66A58A2ULL, 
            0x958C0A0F577BCD54ULL, 0x8A83BEA7DC09EF33ULL, 0x1BEA09013880786BULL, 0x2B266F15DE3E729BULL, 
            0x5DAFB12685223FC1ULL, 0x29B3072B342EC652ULL, 0x7E43DECC760D9F91ULL, 0xA00E3DCC5F1C0080ULL, 
            0xB0AA6BBD789E7619ULL, 0x09B4FC04B3969E7EULL, 0x95871C64653AAA13ULL, 0x00BBC44F7DE682F7ULL, 
            0xEB223E17C3390566ULL, 0xE3F341CB2AFA42E1ULL, 0x766F54C55516948AULL, 0x3444B3F29E986751ULL
        },
        {
            0xA07F6FB69E5B33ECULL, 0xFDA3F2F5C70C0990ULL, 0x6E6A8A602BCBBC06ULL, 0x81F3C373436B3AA0ULL, 
            0x02874BE49E6F2BD2ULL, 0x13ABA57B65F1006DULL, 0x0C4143B267516934ULL, 0x952C7BBAC7601C30ULL, 
            0x97D3D6F8236CDA63ULL, 0x0CC9F4AF5A4F5C13ULL, 0xB400BD8613413061ULL, 0xAE07ED2A8872E7FEULL, 
            0x564CEDD406A46853ULL, 0x9B5E5E3149B8C199ULL, 0x702F110B7AA3B80AULL, 0xDBD9E423584E8784ULL, 
            0xA2BF080432A06632ULL, 0x90C7A38C59757DD3ULL, 0x3AF5E11D65A5B5CEULL, 0x7AE0CE85F2172BB9ULL, 
            0xE566481C2FCDAE02ULL, 0x1A31EFC50B541ECFULL, 0xCF72B9EEC60A3E91ULL, 0x9D80FEE14162FDD7ULL, 
            0x6EF2087ACB837597ULL, 0xE104E8FC618BD75CULL, 0xF339950B194A6B86ULL, 0xAA82A932F93925FCULL, 
            0x87248C2B9196FFDEULL, 0x36865025881D347FULL, 0xB56E69A717942B4EULL, 0x7C8A682259FDF406ULL
        },
        {
            0x09DD6524B4F4F7EAULL, 0xA4F47BB07EBA3299ULL, 0x8D232ABBBF42771DULL, 0xE87F047D61349CAFULL, 
            0x61859C292358FE3AULL, 0xA0F7A2BFCD5F86B1ULL, 0xF00935AD370F94DEULL, 0x58745AF90264654AULL, 
            0x42B01DA2EAACB6E3ULL, 0x16E127F42521C045ULL, 0xD6E3BD4D3E670F3CULL, 0x45BEA0FBBA988B79ULL, 
            0x1DACE23A770CA9E9ULL, 0xAA24ED4BAB6F3D75ULL, 0x7D3F8FBB66936273ULL, 0x39071A3E07048E7FULL, 
            0x19A39E87CE19BCA8ULL, 0xDE58B5760747CC5BULL, 0x212F4CB74C8354E9ULL, 0x757AF4E18B57401EULL, 
            0xD7A7113021567479ULL, 0xC9BF496AA1BB1509ULL, 0xAA58C3997E0B7DF5ULL, 0xD01B53E2D3899265ULL, 
            0x9D0D2FDF0D19B0C6ULL, 0x6123D12F0AEB81B5ULL, 0x4727119308103855ULL, 0xAD6DAE2CDAB2296FULL, 
            0xA093E03CE01F02CCULL, 0x8A75F4BA25DF479EULL, 0xD9EE0F36B9D1B496ULL, 0x78D47C4B2256C7E0ULL
        },
        {
            0x480BD6212EF62802ULL, 0x6BCC953F465C2AA9ULL, 0xC1F621CF70C02F0AULL, 0x153CA876FAF68A93ULL, 
            0xFDB9AF2A3142D9F7ULL, 0x8A9821F1959623BBULL, 0x10CF8B428E2C4C85ULL, 0xC64C553DEFA08B95ULL, 
            0xE468CB4CEAD1A511ULL, 0x4D5A8B3039683FC4ULL, 0x1DC3BF38A0F9C27BULL, 0x30689258086B6F89ULL, 
            0xC92D591597F91831ULL, 0x9ECFBCA6267596E5ULL, 0x94EBAFB29D90F209ULL, 0xB38CB128B1A203BCULL, 
            0xF5AB7322DA41BEA5ULL, 0x0DA81923AE5A166AULL, 0xE12A117E82F9FB32ULL, 0xDBC01E7F01214ED2ULL, 
            0x58092CBFFCA3D4C8ULL, 0xE9C95AFE8D4E2D44ULL, 0xB83E29008B357B90ULL, 0x82D7011A7B115798ULL, 
            0xDB31A3CEBBDDD0C0ULL, 0xFE3A3A4DFFD61EA8ULL, 0xC0D84810A79BE450ULL, 0xD7AC091D48D1AE54ULL, 
            0xF2DD6C1B424E1BBBULL, 0x9AE35A57BD3A5295ULL, 0x7DD6D71779CD07ABULL, 0xEE2BBD582891DDEFULL
        }
    },
    {
        {
            0xAC01D9264F87450CULL, 0xE55AE42D17EFD4ADULL, 0x5F65A6DEB2547F50ULL, 0x666A28A62C1E3579ULL, 
            0x550E626F98B02840ULL, 0x5207C5B297BBB0A2ULL, 0xF8C960AD29FD4F0FULL, 0xFBBD2F506C99E12AULL, 
            0x18E5103FECE251C7ULL, 0x05F2ED93F9BE9E91ULL, 0x1251D4C0453B9D18ULL, 0x9CED5012B0BC8125ULL, 
            0x9D20736E08A62C5EULL, 0x05F9C88EB6425141ULL, 0x04C67E3AB3ABB77CULL, 0x7EF91F3F76C893CCULL, 
            0xC5A0474365E754F8ULL, 0x2B7B297B3D0F2AA7ULL, 0x8BE611A3F9BBE273ULL, 0xC22A0B6DCFEF05F0ULL, 
            0x0A1E3F40DBDB783EULL, 0x57F68AE6245FAE20ULL, 0xCBC85C26CAE84273ULL, 0x96DBA71C8050BF75ULL, 
            0xD2AC479A83FC8231ULL, 0x43816E3342106B1BULL, 0xA7408CD70A6F7DA8ULL, 0xDF1D79079C23CFCCULL, 
            0x4EC6635335E03FE0ULL, 0x031C8E24112B8659ULL, 0xA6CCEDEE2A7FA8C9ULL, 0xFF40965F021488C6ULL
        },
        {
            0x0A379DB2CEC810D1ULL, 0x5DDFAC8A94F90E6AULL, 0x4C04325D50317934ULL, 0xBE93ECD1956C1F01ULL, 
            0xD7C33E33E2229523ULL, 0x106D00D176719217ULL, 0xE05380707EFF3291ULL, 0x9C5704D3A5E1D800ULL, 
            0xF6BF9B24B03FB245ULL, 0xDCD3E1BAE180F244ULL, 0x79DFA6E23A011B67ULL, 0x39754D8E9A72F740ULL, 
            0x878D6AC809AAC722ULL, 0x12BCBFB23C59A645ULL, 0x040458CBED71DB85ULL, 0x2774AF73933B2156ULL, 
            0x75493DC4BBFDF293ULL, 0x2191174B53054AF1ULL, 0xDA4DD8779E2A2950ULL, 0xA93193B98E59750AULL, 
            0x7E952F16BAC65964ULL, 0xE5B632A67D987456ULL, 0xB5CA1FBE6C22E88AULL, 0x38D8E4CBC3909962ULL, 
            0x032BFA7C6ADD7188ULL, 0xD10CF5122AAFE1A2ULL, 0x93773CF1812276F7ULL, 0x6CC67C5D68FB64B3ULL, 
            0x12532DACB50165CAULL, 0x04E20636DD7FD60CULL, 0xF3A4B5B18CEA378DULL, 0xC1A2DCCD0DF6474AULL
        },
        {
            0x5F7417B8CADC8DC1ULL, 0x267AAB033F5675FFULL, 0xD2B8FCC90E322B4CULL, 0x3576FB96DAEC9D0AULL, 
            0x07F16C82137C5DAEULL, 0x37306640896657FCULL, 0xF16DD78BF83B48DEULL, 0x47C76002925541DEULL, 
            0x3FA82766A94CBA36ULL, 0x17297C6C9C2583C6ULL, 0xF738EE4FCF506BD0ULL, 0xFC4633E7EB00140EULL, 
            0x8E2ABB849CC3D379ULL, 0xA3DBCBC5E49E3D49ULL, 0x2E8342BB3FDF6FD4ULL, 0x8C33FAA4E8570D90ULL, 
            0xE2BB8D782ECCC15FULL, 0x4EF056CA800C5EB4ULL, 0xC502AFAA77330B5EULL, 0x2CD3B1E04B47278AULL, 
            0xE3474A817EB78640ULL, 0xBC86C1441076A3C6ULL, 0xC1512F829A88CDD8ULL, 0x1C362818ABB79207ULL, 
            0xCDC34A7210F67F91ULL, 0x6F47D03EC0D1433BULL, 0xBE4A11354537E27EULL, 0xCCF109026036BDA1ULL, 
            0x2A78DD8723D964E3ULL, 0x68CB6639D34CADD4ULL, 0xA71F9C5A38BF34B6ULL, 0x04BABA3589A61200ULL
        },
        {
            0xA96ACD39591CE8E9ULL, 0xF78284E31AA8E2E1ULL, 0x357171584AA0869AULL, 0xFD04951E2C4BC7FAULL, 
            0x8A2EC09AC29D9AABULL, 0x80A5AA4063DBC63BULL, 0x641DF22C0584349EULL, 0x5018ADFEDC7C2B0AULL, 
            0x5161B7089DC0E8C9ULL, 0x34A55DC66891DCA0ULL, 0x9393A58E72EB8122ULL, 0x55D5BA89495938DEULL, 
            0x36186CE3C843E43FULL, 0x04ECFCC17851BE77ULL, 0x900013BA14BEC740ULL, 0x5E435CADB2FB997EULL, 
            0xEFB36BB657D492CBULL, 0xB370B4DE527065EDULL, 0x31D902ADF692A8B1ULL, 0x14ED1283948B335AULL, 
            0xBF62F5AA68E46105ULL, 0xCB392E603F5960DFULL, 0xE98E516F62646BFCULL, 0x00DA267327397E9EULL, 
            0x062659999FD6E9CAULL, 0x3417CEC9A2009EBBULL, 0x5F8BF3E6F56F722EULL, 0xDAFD95188DFCE3E2ULL, 
            0x9947D1FFED255C0CULL, 0x3AF363F2611734F3ULL, 0x270769705F733FA0ULL, 0x1AB2390422B1A2FFULL
        },
        {
            0xEEF4C542C094EA90ULL, 0xDF8A0C7E317C0EBCULL, 0xD065A335BA4B0ADDULL, 0x6BC5302E8C0F75DFULL, 
            0x5BA2C9B00A45A678ULL, 0x65DB7243E928C772ULL, 0xEE610DCB70C9D25DULL, 0xB822C101BCDD4124ULL, 
            0xB89E8ABCDFDDAF10ULL, 0xF7FFCD9962E9C73DULL, 0xD2AD91F45609B0D6ULL, 0x333083CB05BD3D15ULL, 
            0x2A041AC2E6E621B3ULL, 0x56248C1252CFD7F8ULL, 0xA8F3322248977BB4ULL, 0x4E0EB37C6BCD60B6ULL, 
            0xBB117A904FDF46C9ULL, 0x7B9DCA0379B94BEEULL, 0x10F9DA4B8F4DD2C5ULL, 0xB44574E65D18F039ULL, 
            0x8E52F71A1F34D0B4ULL, 0x5162083D0AF6CAEAULL, 0xE2A827AC17842005ULL, 0x7528C9104980EDB0ULL, 
            0xE227C60F8C2BD72DULL, 0x34F3617CF13092BFULL, 0x8ECD627B51CABCDDULL, 0x494D9BFDF32A875FULL, 
            0x9879040835A83B89ULL, 0x3B9D241E1FB36771ULL, 0x4229E6756949D9F8ULL, 0x700628DEE13FC5AFULL
        },
        {
            0x7EE0C55E4351E443ULL, 0x3233A5308EA53790ULL, 0x9388BA26F3BF8BE6ULL, 0x9FFBCC37A7D9A8A2ULL, 
            0xF35C8958AA6FD30FULL, 0x239590664C2CB569ULL, 0xB65218DC5910873CULL, 0xAF8ADC2E5E57D3B9ULL, 
            0xA0E31AFC869827E6ULL, 0x7EB2A71BF2DCC870ULL, 0x7BB37EE2CE4585CFULL, 0x549E4C496510B24DULL, 
            0xD67B28924B305044ULL, 0xCFF490AB3A30443EULL, 0x5148E4D36AE54F10ULL, 0x4D1D916C3739EDF0ULL, 
            0xFAA680858B30025DULL, 0xEDAD6F80FC9A3281ULL, 0xECE18E8B3F3DAFA1ULL, 0x8AE8C02BDB350045ULL, 
            0x5D7674FA50AF5FB1ULL, 0x6040ADE2C1F19613ULL, 0x5473CD000D05733AULL, 0x7967BE32084A7566ULL, 
            0x1AE013033B4D35FEULL, 0x4D432547AA59C99FULL, 0x8CEFCFC226D58B74ULL, 0x29385ED50213FB2CULL, 
            0xC98BF73DFDD82DCBULL, 0x2A7BE2028167BFFFULL, 0x82F4A56C0EBEABBAULL, 0xF56B76002A397C27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kPhaseAConstants = {
    0xC3F22FBEAE624718ULL,
    0x8F42F3D07C43E1C1ULL,
    0xD1CB84E67FC567C3ULL,
    0xC3F22FBEAE624718ULL,
    0x8F42F3D07C43E1C1ULL,
    0xD1CB84E67FC567C3ULL,
    0xA1870C5046DFB34AULL,
    0x656DDD11BA87D078ULL,
    0x41,
    0x8B,
    0xE1,
    0x7F,
    0x83,
    0x3F,
    0x4D,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Polaris::kPhaseBSalts = {
    {
        {
            0x213F3616557E99BCULL, 0xBFCCB03935A25344ULL, 0xAC37F5FA7E76BF2AULL, 0xE13A42198708867DULL, 
            0x961D44F20B683BD6ULL, 0x409C717C3DB0A241ULL, 0xDF25D6509FC29CD9ULL, 0x16CF336E4528A61EULL, 
            0xED8C97C4BE20016AULL, 0x4B6FA6DE0964A362ULL, 0xB5F96E8699435E4CULL, 0xF008559F79F67469ULL, 
            0x470ACC0299209659ULL, 0xD9A7A65338D57B70ULL, 0x81FB5D93FCF7B103ULL, 0xDAD9371E2478EE03ULL, 
            0xCB647338707A0DAAULL, 0x0BDE4A4A9CBF2805ULL, 0xE4DC17B5A02FE223ULL, 0x0E022853FF7D2022ULL, 
            0x8EF9BE29BA3DC4FCULL, 0x92DDF5734F0B6CC3ULL, 0x45ABA31FD24AEEC9ULL, 0xF68EED59922C1664ULL, 
            0x167B05AECD09A137ULL, 0xF5546CD552837A16ULL, 0x1947FAC3FBCA16B3ULL, 0xEB190D60FAA27F0FULL, 
            0x7A192EF1F6DF9F48ULL, 0x12EB9581E219027BULL, 0x284E30F27BE609C0ULL, 0x19EE4C104FF42F8BULL
        },
        {
            0x9C99B147534C1471ULL, 0xCACEE53CFCCECE99ULL, 0x745FC049E23E20B6ULL, 0xDAAFCB51244ED46AULL, 
            0x61FE366FF142C9D3ULL, 0xEF072527ABF3CE93ULL, 0x9EAB789473586EECULL, 0x1B2D45588B925069ULL, 
            0xE8224E413295221FULL, 0x1EB807F465E9C45EULL, 0xECD6BCB351A857CFULL, 0x175C47272BDD6775ULL, 
            0x310C5432D5C06B3AULL, 0x0AF3AF5B53A02618ULL, 0x505FF612F2A6AA85ULL, 0x07E735E08C353F00ULL, 
            0x72F30FE3DF3BD9CBULL, 0xA6318AA6E0CB90E2ULL, 0xC0433A5C291066C1ULL, 0x2C38B11C981F268EULL, 
            0xE2C9088F670CCF34ULL, 0x45AF50DFA5D7C6BCULL, 0x4F24B2147E3D352FULL, 0x62D9C8A56DC4B079ULL, 
            0x18500DEEA1FAC78AULL, 0x92629CA6469FC6F1ULL, 0xF4E19B30E9192D1DULL, 0x4D9C4D35FAD38549ULL, 
            0x4F03A33D5D7C6396ULL, 0x7F27CD9904170A4CULL, 0x72F86D8CA43C7F55ULL, 0x5C87BFAC975D1C33ULL
        },
        {
            0x2D2F21484C26D35DULL, 0xC0D4D4EEC48BA192ULL, 0x41A3A2C10E03BD35ULL, 0x803CDA66474664B2ULL, 
            0xCEBA84835EF34E56ULL, 0xE7F94A327707F817ULL, 0x94CA2006C843581EULL, 0xC9F99E237BDED74FULL, 
            0x7DAF5ED32B5AE18AULL, 0x78C9144D63D3748BULL, 0x6E93A12A77032E51ULL, 0xB8B4E86C73E342F5ULL, 
            0xEB2123C0E27AB8FEULL, 0xD674C859D30788D0ULL, 0x5EDA68D074A9D61AULL, 0x1AA97AA352AE58A2ULL, 
            0x379DB144D3C8C2DEULL, 0x66AB3F919DC69637ULL, 0x880079F3B49474C9ULL, 0xCB8A6166D995015EULL, 
            0x67E675A7A69A5C31ULL, 0xD482C2C18C7B6864ULL, 0xBF71608AEA1F2E06ULL, 0x52FDB370E8EBD5F7ULL, 
            0x1C36DFCE24EB4980ULL, 0xA8F628D93591D86DULL, 0xCB99303F7CF9289EULL, 0x9D504874DAA249C8ULL, 
            0x246DF4FFC4533147ULL, 0xC41F4C907931EDC2ULL, 0x0CEE7E4DAB946482ULL, 0xE473C8529EC8B066ULL
        },
        {
            0x7190BF6E66FB0E73ULL, 0x8F56A60CC0637FA1ULL, 0x9FF4F870BDFEDBE1ULL, 0xD718C89CBCAA643EULL, 
            0x5D8253E9A2C929A4ULL, 0x580EF47359C72402ULL, 0x63D295CA40F3D9B1ULL, 0xF19DE9F007E4F4C6ULL, 
            0x44CF22CEFAB90509ULL, 0xAC60486B8AB99E32ULL, 0x006C5A044ECB2F0DULL, 0x338A06E303FA8AB1ULL, 
            0x4BFADD1DF0AD925EULL, 0x48494F00F90836BCULL, 0x470DDAEB401D3FCEULL, 0xAEA6928BA6331D77ULL, 
            0xDA4ACDC73A45680DULL, 0x1B9F3201FA3F455CULL, 0x0C0CE4EA1C503AF0ULL, 0xEA5B9F58E5ECB38FULL, 
            0x8E1FF80712971ED7ULL, 0xA6F6FC37BBC3001BULL, 0x0828D2CD5CFBCE22ULL, 0xA91210CC5280A996ULL, 
            0xE6D32397E71FAED0ULL, 0x5CF269A226930DC0ULL, 0x81385689C487D059ULL, 0x35632DE9DDA91D48ULL, 
            0xB3A76E3EB28EEEF7ULL, 0xBA205E205A0F408AULL, 0x9D2FF78DD532EB25ULL, 0xA473EC470996D9E9ULL
        },
        {
            0xF97FA8E43D666621ULL, 0xB0A6BB4FCB0F9EA5ULL, 0xC09D5E302CF63C48ULL, 0xBE6E6284DD65631EULL, 
            0x0CA016033FC022A8ULL, 0xAD065A31D965490CULL, 0x6AB993178FEBF44AULL, 0x136FED83A3DE704CULL, 
            0xA0C69EB7BFCC9F58ULL, 0xA07BF911BB7BA139ULL, 0x7B6558B47B77D7C0ULL, 0xDAB139E45ECFA74CULL, 
            0xC210DEFB9746E5FCULL, 0xDE69451EA4B8382DULL, 0xCACC24FEC3DD05EDULL, 0xB07CDE40009BD395ULL, 
            0x9F50CAEA8988B889ULL, 0xC1E9C0C608E0F06DULL, 0xD95A34B0F96C9615ULL, 0x76983BB2AC810AEBULL, 
            0x4172D07DC96CD882ULL, 0x13D6DA6121DFC5E6ULL, 0xCCC294A85F64716DULL, 0x83E920CA9EB9A4D5ULL, 
            0xDBD2190D36755886ULL, 0x1EC65BCD0682334DULL, 0x0FE0C226254422E5ULL, 0x3A6D4E786978E52AULL, 
            0x38038E0EC8023B37ULL, 0x9B8EF5AD806CB45EULL, 0x764342B2F21A5992ULL, 0xD4F9C2BC59A22925ULL
        },
        {
            0x0F66EDB83A3C8C8CULL, 0x4BFC679C8004DCC2ULL, 0xA97F55BDF3343372ULL, 0x99EEE076147E27AEULL, 
            0x16EB054FA5D3D9A5ULL, 0xCF0C9858E21B4BCEULL, 0x75F0707D991F3AB9ULL, 0x530F72AFB2D4F522ULL, 
            0x35648C69FEFAF35BULL, 0xFD19540360306CEEULL, 0xC01CE217BC3C3D18ULL, 0x9CB3308C00E67059ULL, 
            0x4800AB5D0F4FBDF7ULL, 0xFF59C75F9B295637ULL, 0xF1D6B8EC864429ECULL, 0xAE5E29F32A4F4650ULL, 
            0xAF83E9523BB2C122ULL, 0xB9B1E3A544E62435ULL, 0xBDAA7A0DCDF6ED81ULL, 0xF95C6E27577866E3ULL, 
            0x6C4E565FF2BA59FFULL, 0xDD99B717BC826189ULL, 0x2CC41262A3BB2C75ULL, 0x090434FA4AB2A342ULL, 
            0xFD0027DD2B4FC5D6ULL, 0x635ED7DB94607BF9ULL, 0x36EC2E874072F21FULL, 0x4D8200E0D5FE234FULL, 
            0x763EB614D9BB1FE6ULL, 0xBCD2006D8E51226FULL, 0x7BA82F9EFC4F0D3AULL, 0xA23863A32793797CULL
        }
    },
    {
        {
            0x2D12296450171CAEULL, 0xEB509A415CA54221ULL, 0xD6712239A3FB5E1FULL, 0x2CB6519B1C7ADC60ULL, 
            0x5BF440EF5CADBF13ULL, 0x326AF48D34269668ULL, 0x86B69AC657FEA1C2ULL, 0xFF696F9603C506C0ULL, 
            0xBF2F5AF590C64C02ULL, 0x6B666FE27638517AULL, 0x03CB01B01C2559BAULL, 0x281CEFC195FEFA72ULL, 
            0xBF37371E4765DF6AULL, 0xA59D1AC1FCFCC4D9ULL, 0x749CF7C58AEA3A2CULL, 0xF094C6166B82C427ULL, 
            0xA5A8AC5F1268BC4BULL, 0x3ECF9A71F1A03828ULL, 0xE1C6FF7D61CDAADDULL, 0x7180C9E262A1F0A1ULL, 
            0xCC3E85A18EF835A1ULL, 0xFDC903D098EA1E0AULL, 0x3136D88AABB6C717ULL, 0x55414AF297B68AD0ULL, 
            0x5B7F02BD14789E24ULL, 0x0C74E43E958FF6C0ULL, 0xF07092F29206816BULL, 0x6B3A13F8B1D66C29ULL, 
            0xF3C919D87F836A34ULL, 0x506A3E35EE505EDDULL, 0x36D09CE41FA813BFULL, 0xFA249DA009D11754ULL
        },
        {
            0x0ED4AE7347F0A618ULL, 0x934F20E61B0F814BULL, 0x252609537BFFF4FBULL, 0xA42DC11024F1DA13ULL, 
            0x551BC3CD58D1037AULL, 0xB48685F1940D58EDULL, 0xD857A08E9B56C582ULL, 0xC98197F12320083CULL, 
            0x94AB426B438359AAULL, 0x1BC7BEC8A92C6BF1ULL, 0x639A12E1001488D0ULL, 0x76C05C611E8AF181ULL, 
            0xD6FFF9B08C709BEEULL, 0xFA3858E255017F72ULL, 0x77E72A182C55879CULL, 0xE415A5834DBA556AULL, 
            0xDC0BCAF45ACB753FULL, 0x3A1E21F7ED25D422ULL, 0x9DDCF822EBF75C0FULL, 0x4921A744A4B650B4ULL, 
            0xFFE50336FAF5DCDDULL, 0x2836CD33B13A8460ULL, 0xD86C383DF9B3D642ULL, 0x5406DCDD698DE3A8ULL, 
            0xA4CB044AF3D6856EULL, 0x9779D4D79C8C0E56ULL, 0x24502701E31B4FFBULL, 0x1DC471E9900B1602ULL, 
            0x91207615DB0208DCULL, 0x85D71B29051D4ABBULL, 0x8ED7CE11C79B9730ULL, 0x7799647479990E26ULL
        },
        {
            0xA5F03415E01B9432ULL, 0x91A2E7E166AC76C3ULL, 0x5312D6BAE034A5CBULL, 0xDB63026E84FD9F9DULL, 
            0x1B9449064A0212E9ULL, 0x6D4820D998F4F812ULL, 0x631EB5CAB90FD27FULL, 0x0DC2826E202264FDULL, 
            0x26FFE472253F1DA3ULL, 0xCB89E73857ACD1C7ULL, 0xEC26EB05FD72DEF4ULL, 0xC8C506C0D4AD887BULL, 
            0xE1D4B14620C64C15ULL, 0xF8FE24F904B1B0D6ULL, 0x47800775C347AC91ULL, 0xE1211DFDB9463CF9ULL, 
            0xFBFDAE525FF34844ULL, 0x96551ECA4986AAE6ULL, 0x5A812B15A32F0692ULL, 0x77E5E3E2D3D344E0ULL, 
            0xCF635053DFB73547ULL, 0x52FD11FF164C4363ULL, 0xEF43D7A73376F04EULL, 0xFA6159EC573577E0ULL, 
            0x9619F29DD1C15D7BULL, 0x8CD159BAD72A9E2CULL, 0xBA498F6842B59B3CULL, 0x32499338BA9FA5F8ULL, 
            0x00041C16F1836592ULL, 0xC53D9E4B27DED743ULL, 0x37CF99F3C4D42961ULL, 0xB19D7FBDFD4A4889ULL
        },
        {
            0xA060444FAAC31969ULL, 0x8BA9F0AF7BB4435DULL, 0x4C83F3E853102032ULL, 0x2E0588A23AB71A67ULL, 
            0xD44ED16D927425E6ULL, 0x8CDCA791BBD723A9ULL, 0xE3162E7280E281EDULL, 0x47CF9159AD6A0186ULL, 
            0x48B2CE3FCC25B7D8ULL, 0xDD1489BE53D6D775ULL, 0xF2144BD46DCEFAA8ULL, 0x76B5F33712EE70A0ULL, 
            0xDE7F5E408F4D6236ULL, 0x3F8AF8E721B18BFBULL, 0x46970FBC0B45C5DDULL, 0xFD1AE24F4031DE58ULL, 
            0x68735D6A3685ABB8ULL, 0x64C208372417847CULL, 0x207B1C021B6AA857ULL, 0xB59D9EDD2ACD7D56ULL, 
            0xBC3F36CB95275451ULL, 0xAA2A26C5F178113BULL, 0x1D7CB4B6F1DFA36BULL, 0x7FD44E5E129710A0ULL, 
            0xA2860BB9E89EC7E9ULL, 0xAF706A4120A76A59ULL, 0xCF96EEE3360D8F8CULL, 0x1131E5F1344A0713ULL, 
            0x850BEF6F32FC1FFDULL, 0x72AFC10F9487EA01ULL, 0xCE6905303058912EULL, 0x0D68379A8FEE0997ULL
        },
        {
            0x4EE529CA6FC507F9ULL, 0xF86C3E136BE8EA80ULL, 0xA94F9D3E1B56125EULL, 0xC6B30135CF042AB4ULL, 
            0x59F030B794D3A71EULL, 0xB468C960BF9AB0B2ULL, 0xEF8ABA42780F901EULL, 0x4A6DB2DAD1B477ADULL, 
            0xA819D4273FF3CC35ULL, 0x0533E56E605C817DULL, 0xC80FC0EA54F5A3FBULL, 0x18A2698ACE674A30ULL, 
            0x4244B56C7F37FE3CULL, 0x2DD2D51C6B15FF89ULL, 0xBF9BFC01A3B614CCULL, 0x22A55209E82F5914ULL, 
            0x71F97DDAACDD6880ULL, 0xF0C91FA1731E3BCAULL, 0x7C18E5C356515D7FULL, 0x929EDE9BF0AD4631ULL, 
            0xA5F45F352FC3B231ULL, 0x0C788706A70361F4ULL, 0x84BCAA7CD845D0B6ULL, 0xDB90D20F88B6C435ULL, 
            0x09BF2F82C91C416BULL, 0xAE031F77B4FAA67EULL, 0x5311340D1FA1F3EDULL, 0x4ED715D34B6486D5ULL, 
            0x65E9438A06EE9F19ULL, 0xA36708B5D977F133ULL, 0x0A9581BBE80C4726ULL, 0x60436B654F9A30B6ULL
        },
        {
            0x1C38F2FE20401D3BULL, 0x1E06B8B1D15143ADULL, 0x69EE443CBBB98D03ULL, 0xDD05324FFD6872A7ULL, 
            0x0EE48588430FD847ULL, 0x07BD857766E83520ULL, 0xB19334CE23C73C12ULL, 0xD5B310157174FA25ULL, 
            0x8B7ED663F21A251DULL, 0x6001617A1673FF45ULL, 0x2601629C43A33E0AULL, 0xA0C8D22D1E445B5EULL, 
            0x5C2B4281C5711AD0ULL, 0xA1E7727861C98C5FULL, 0x7F5BB6075AC8F69AULL, 0x48C796589EEAFAE6ULL, 
            0x1815D883E96346C5ULL, 0x79714CB5245737C3ULL, 0xF6ED61A6D3348B65ULL, 0x55557D1AF870D896ULL, 
            0xBA4E2A2B782D43F2ULL, 0x5C0533D0551DBD2DULL, 0xF453B044634386E5ULL, 0x497ACF99B02B0F46ULL, 
            0xA11DD96B1CEFB17AULL, 0xC7071FE4028859B4ULL, 0xB4EB60FED9F4C33FULL, 0x9B2C269D01B7C3A2ULL, 
            0xC12027CDA8225CE2ULL, 0x96BB8B4BB99750EFULL, 0x0EE87C53D7AF9FCAULL, 0x6B3B0D166748E43BULL
        }
    },
    {
        {
            0xB7C74027E7D943ACULL, 0xFC053FB29B87D160ULL, 0x91A8E9A0BF1AE9FCULL, 0x16037A8E0109B4EFULL, 
            0xFB031A271F371E31ULL, 0x8169A67757C340D3ULL, 0xC45F6732EFC5172DULL, 0xC358B985C603171FULL, 
            0x0317F26F2845BC76ULL, 0x773E4680675AB09AULL, 0xC6CF5159A2A43420ULL, 0xEE484281006DFF3FULL, 
            0x006ACA02ECFAC923ULL, 0x8E0BD268E6152213ULL, 0x342DCD2A531732EBULL, 0x33B9A0E789E0B485ULL, 
            0xBD10C74DDE12604DULL, 0x27656ECCF69991BDULL, 0x6E2418C64CE87A2BULL, 0xEB337FBA38583BD3ULL, 
            0xE50B978CE7EC8482ULL, 0xB4F89644C7DE169CULL, 0xB971A1A163C7A173ULL, 0xFE0673CAF4CBCFE2ULL, 
            0xE0D01D38FDAB2FABULL, 0x9CC87A02DFDDEF01ULL, 0x3C84B5AB2A0F8F79ULL, 0x8662ECF76D43476CULL, 
            0x158898BA6B9C202EULL, 0x7A6DECC3A83478B2ULL, 0xA7F91AFD5B215B6BULL, 0x344741D0B3B9B47AULL
        },
        {
            0xA63484B92753591AULL, 0x0B8ECF0D79F7760DULL, 0xEEAC273D565D38EEULL, 0xFE3A90CE7752F609ULL, 
            0xBE16245A16F17237ULL, 0xD47CC2EF7B209836ULL, 0xA5DC5A9970A17129ULL, 0x17CBE9D0C1BFBD82ULL, 
            0x1F9F03CF3131C222ULL, 0x11A1B7950BA7BB3FULL, 0x3D07FEB9B36CEC90ULL, 0xCFC514F35841A2C6ULL, 
            0x55D17B533D51278DULL, 0x4930B3A1F65800A8ULL, 0xA9DAAC99045350FAULL, 0x918F387236995E5AULL, 
            0xED79E263E0603CB0ULL, 0x764A5E5660803274ULL, 0x4FB5537B7AA6D72EULL, 0x0A5DFC8E7E737CA9ULL, 
            0xB7CA3CFFAB5B5C0AULL, 0x40C1473C04267074ULL, 0x24A73A5712CD3138ULL, 0xF58A77F49CDEDE1EULL, 
            0xA126E0249C76E7F7ULL, 0x0F10EAF651B3F2BAULL, 0xBE2EC569E21ADD2EULL, 0x99CB6DA3C6A6A2F0ULL, 
            0x695E02BF646579E1ULL, 0xC5E36E20893C5677ULL, 0xF5B4C4118A4B908CULL, 0x53D063A4A31B7F06ULL
        },
        {
            0x2A5A998115363FD2ULL, 0xA5803E2FD118DBF3ULL, 0x34FE42E82EE1CC97ULL, 0xEB224AE928A1FF8FULL, 
            0x0A583FB1A3A543A4ULL, 0xA94E143F7CBF7BC1ULL, 0x6FFADA652405340FULL, 0x9EFB23629D163F14ULL, 
            0x496F4DBCE933972EULL, 0xF6309DE4C19F7890ULL, 0x44ADEEEE5A09187BULL, 0x6EAFA64154179F5DULL, 
            0xE078AB6672AE5749ULL, 0xE8C7AEF017209EC0ULL, 0x7907E654D2E55DF3ULL, 0x89C9AC1EB2CAA689ULL, 
            0x0542875BB513CF04ULL, 0x088168C48019C92BULL, 0x4B60915709E54BA0ULL, 0xC632E0C8A22E28AAULL, 
            0x643CAA00A2707B7CULL, 0x1D1F989DF5A979B3ULL, 0xE31CC27C1C27829AULL, 0x2410E2EB902FDF81ULL, 
            0xE681F2FF95734608ULL, 0x684667B433C282DBULL, 0xEBB08D3EE4162BD4ULL, 0x753205A2E497FDEEULL, 
            0xA8285430B4F90BA6ULL, 0xF39A783CDDE0C135ULL, 0x31D6604405B05486ULL, 0x1CA17333B51F4208ULL
        },
        {
            0x1A04C242AE9FABF1ULL, 0xAD82347F3281EFBDULL, 0x421784B84931A1CCULL, 0xF3AF68FF4FB122B4ULL, 
            0xF67F2A9F4E29E598ULL, 0xCD5FCC1DEB413773ULL, 0x4203FA28F417DAA0ULL, 0xE5FA7996BACE8D3AULL, 
            0xF1BDD48DB2F0B67AULL, 0x84255F44B5B0DC26ULL, 0x44195A02E5001F37ULL, 0x8A16AC4E4EFB6864ULL, 
            0x06C9417477197472ULL, 0xFB5240DA5C2D3816ULL, 0x883BC9FEC32D1814ULL, 0xEAE2A886EBA48B1CULL, 
            0x141BA069DD2B563FULL, 0xE89E5AC12AA8F748ULL, 0xA0AD8794B4CA405BULL, 0xB811901342A1EF69ULL, 
            0x1A94A9CB143BEA99ULL, 0x34D3FE305E240447ULL, 0x564C72FB828261EAULL, 0xCB77BF18F07DDAE3ULL, 
            0x910D45787638F71DULL, 0x66CFBC57D758CE71ULL, 0x3CFE042A7B53DDF5ULL, 0xAFCDD1188D8F9C08ULL, 
            0x54174E54001EA870ULL, 0x20D46C2B501FF72DULL, 0x19971A1CBBD3110DULL, 0xA43E5E565F66EC61ULL
        },
        {
            0x0945AA979B9EA042ULL, 0x33B41269199EB841ULL, 0xF231C9F7FA80ECF8ULL, 0x48B4C5C30840A845ULL, 
            0x13F11EADAE84FE22ULL, 0xEFF9802AB038E80EULL, 0x6A3AFFED75D31A07ULL, 0x407AFD0E6F9837C7ULL, 
            0xED3CB5250A663507ULL, 0x372CCF7C3A27F3ABULL, 0x66B9DEF8E589B2D9ULL, 0x2FA513B386D737C1ULL, 
            0x960C4DBEF336E731ULL, 0xD3919A1C2BD97682ULL, 0xE5896FB6D3E706FAULL, 0xEA4FB7E311E5F2F1ULL, 
            0xA996FCC615DBD0A4ULL, 0xEDA998EBA6A9CACDULL, 0x424B2E3C16EED900ULL, 0x3257C2D889C44C64ULL, 
            0x50ECE7B6DFA03EBDULL, 0x29CA41121B234F21ULL, 0x58EF3547EE8CDB53ULL, 0xDC2FB47E545E98BBULL, 
            0x5D4F4052DD581AAAULL, 0xD0627955C22C0215ULL, 0x2324005EB5BA3F1EULL, 0x57CC7C94F1945676ULL, 
            0x99A15DD3D94FCADFULL, 0xCE6CF67FC8F6F3BAULL, 0x0227DAA791A683A1ULL, 0xF826F20C07BC46CFULL
        },
        {
            0x4821434EC469AD0AULL, 0x4EBFB3B89878FBC8ULL, 0x19DC0CF9C0B17F94ULL, 0x28DC53A902E4FD47ULL, 
            0x5A55FEEB1A9EB2EEULL, 0x917A65BF2E87BAFBULL, 0xA9DA8AD04DFE43DBULL, 0x86B46AED52C04A12ULL, 
            0x0C80AF788E98826AULL, 0x9BBEA27E75D188AFULL, 0xADB214CBADDCD800ULL, 0xFE566C35F2A241FEULL, 
            0xF5F5BAF7945C068BULL, 0xAD4A6CB028C449C4ULL, 0xE630E3F1D8A773EAULL, 0x66A8FC73F1696646ULL, 
            0x8F0198495E601F1DULL, 0x90861B502A87F183ULL, 0x153971F4CAE666BCULL, 0xEE581D0CD52BDCBEULL, 
            0xA6DE9621F0C0C902ULL, 0x1EE00D06D47707D0ULL, 0xFBD4FB868144DB8CULL, 0x8B9A4397DA059ACAULL, 
            0xAF7809E678BC4FCAULL, 0xF8A4C00D8AB5A711ULL, 0xF2CD2C606B68B055ULL, 0x7B7CD5FC015A8411ULL, 
            0xAC06163504C16165ULL, 0xBC37F06EE6EB71C4ULL, 0x579AD180589DB007ULL, 0xC133B7667492B724ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kPhaseBConstants = {
    0x40622231659C30F4ULL,
    0x56A3CDA3257EF297ULL,
    0x75151A34B9188B51ULL,
    0x40622231659C30F4ULL,
    0x56A3CDA3257EF297ULL,
    0x75151A34B9188B51ULL,
    0x5D958327A3C47409ULL,
    0x604BF75B54214F58ULL,
    0x50,
    0x23,
    0x85,
    0xF3,
    0x6E,
    0x3D,
    0xE1,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Polaris::kPhaseCSalts = {
    {
        {
            0xD915DEBEAEE7720BULL, 0x26C96ACE0C3F8CD0ULL, 0xFE4819F1781481E5ULL, 0x91FF61DC0DBB7613ULL, 
            0x48292352B510E16CULL, 0x41D5C670AC5840AAULL, 0x7A71AA83ABFCFEDAULL, 0xF3FE185BEB7F707DULL, 
            0x6AF72615355A8450ULL, 0x13EAA34113A97397ULL, 0x319E9F44BD606960ULL, 0xDAFEB9EABEB21518ULL, 
            0x2E28DC06B41A92EAULL, 0x092F87D90AF68CBCULL, 0xF54F623F692EA7B2ULL, 0xB614946536698D59ULL, 
            0xF8E6BE41993A04C0ULL, 0x6DC75FDD225D4E1AULL, 0x2A7D9A6F308193A1ULL, 0x46490F2BEA91B25EULL, 
            0xC9243403F4C57521ULL, 0x3D6464E3548365C6ULL, 0xC56C69435FC8C536ULL, 0x74BE7954B662DA20ULL, 
            0x8C3DF3FDD88932D9ULL, 0xA5AD736B399DC04FULL, 0xCDE1F0D6274BB9A9ULL, 0x3C7D25F040866BBBULL, 
            0x261571028999BE57ULL, 0x0E8559B20A98BFFFULL, 0xCCA372B1691436C1ULL, 0x9B0F34A3692356C1ULL
        },
        {
            0xBBEB7AE6DDAAC3B7ULL, 0x85EBB95EA3B38098ULL, 0x6DD24E6A68DA8BAAULL, 0x943AB686B18C86E1ULL, 
            0x9C1F2DE4DC961254ULL, 0x9F9F94266E753746ULL, 0x26E1443D2D4FABBFULL, 0x9A7DFC5DA9AC8687ULL, 
            0x195B9B4C267F905CULL, 0x62EC065CBA1E2986ULL, 0x579FA5F33843AB4EULL, 0x50AE5D968F7D0571ULL, 
            0x58FEE34660DA58B6ULL, 0xDDF98CB1D3A1AE44ULL, 0xB73BF1AE513680B6ULL, 0x888CD1BE5B29678EULL, 
            0xD38B243806BAD0A7ULL, 0xB8CB5ECE27D19A0AULL, 0x8B7B8D7BCE36A4C5ULL, 0x5CA4A6E3156BEC31ULL, 
            0x99F87342DA060E22ULL, 0xAAF3F76DDEF5C8E3ULL, 0x7410751422BB94DEULL, 0x35F17AFD7E1077E1ULL, 
            0x9DB32D6D4142BFF1ULL, 0xA6063C7B2D1AB9AFULL, 0x63D5F2E73FD03AB7ULL, 0xF124351A265E89CAULL, 
            0x4DFF2183985D5943ULL, 0x5DB6F616D91BFBCCULL, 0x6E683C32417AB61BULL, 0x4BBCCF5D77A038C3ULL
        },
        {
            0xFC4EC0D26083A555ULL, 0xE88B1CD6332C068BULL, 0x485D982ECD24CA0FULL, 0x2C4AAB9D850C0F97ULL, 
            0x823D30A373D9E2CAULL, 0x4F24255D4975516DULL, 0x3012CE47C6E4E612ULL, 0x5A6AFDDA600F99F8ULL, 
            0x97219DB015F06E86ULL, 0xD658B0683E93BB5DULL, 0xC72888D4DFC1FDBAULL, 0x0AE95DABF251C087ULL, 
            0xEE8CB7E19A72A921ULL, 0x3E9630EEE3B7EA30ULL, 0xCFD3CE21F2C8901DULL, 0x7C1CA2A3F37C8AF7ULL, 
            0xF38BCAA7A7F5203EULL, 0x272B35E20D046C89ULL, 0xE41A1B55A9A587E1ULL, 0x5A89F0DDD4549368ULL, 
            0x7EE3B97805116E35ULL, 0xCEE25F6BF1BA182AULL, 0x34751AEF62ACF52AULL, 0x3CCC4943BE908E5DULL, 
            0xC85A3FE791E458BEULL, 0x0CB5679543369E09ULL, 0xADC9C7D3DB1D23FAULL, 0x95DBC581B7C28EC3ULL, 
            0xC4E020A107199B56ULL, 0xF7ACE43E773A4041ULL, 0xEF4D2D201D174F65ULL, 0x5977138570B432DDULL
        },
        {
            0x214D7CBFFEA1BF6AULL, 0xA00732DEAACA6070ULL, 0xA321E475CA6B6BD1ULL, 0xE1D5DBD6E6D177FFULL, 
            0xD271F18C7AD1423FULL, 0x5ADD56725965DB32ULL, 0x9A67BF41E1F570F6ULL, 0xEA338810718A817DULL, 
            0xC90BC998251F4A7DULL, 0xD2642696DACFBFCFULL, 0xC7E1E9F098F1590CULL, 0x8EFFBA912F9E19C7ULL, 
            0xF9A3172811747D8FULL, 0x0469DF5BB6B3C008ULL, 0x668DBFFE924B170AULL, 0x62AF106A042296A9ULL, 
            0x8BEDCD9C4210D28AULL, 0xA0ACBE6917AA2054ULL, 0x69D7512A4D9AABF7ULL, 0x9E3BE81AA5604CA2ULL, 
            0x4A2CE96732D90A1BULL, 0xA5D945453DAA4C40ULL, 0x05148575CE02F5B1ULL, 0xC4E48ADB91AE8CFAULL, 
            0xB829D327BDE18CC9ULL, 0x18CC50D8654D2140ULL, 0x6259F1384DE103BFULL, 0x8C299F199A254D83ULL, 
            0x2713A5B2F0B29998ULL, 0xA44FD485DADF30ECULL, 0xED38014C86F65C2CULL, 0x2061664FEAECD416ULL
        },
        {
            0x31B73119BB705FB3ULL, 0x7F4587C9C07C0F61ULL, 0x563E6073DEE9BE96ULL, 0x892232CC3AFE8075ULL, 
            0xA924A9D9428AB563ULL, 0xFECC82EBCAC954C4ULL, 0xBCF3DEAB27261F7FULL, 0x14FF224DA5D92F9CULL, 
            0xDC7DF7034D5C7979ULL, 0xC82BEBFD959FD272ULL, 0x4C143B5D61BAC4ECULL, 0x6D5E1CE55BF9459DULL, 
            0x83B01D95859CA05BULL, 0x8A3DCDD6D4E83728ULL, 0x7C25D2514AB2EC7BULL, 0xC5C70AFE86753392ULL, 
            0x1F6C5CA2134B28CFULL, 0x2E9A24CEBEF800C6ULL, 0x7E7B1C641BBD1855ULL, 0x96CD4EBF979EAAB0ULL, 
            0x1779A7FA2073F121ULL, 0xC3E595B2D7EB3FD5ULL, 0xD95666570EE04F42ULL, 0xC5641CAAB681BF52ULL, 
            0xB6FC4E4FDEDC8A29ULL, 0x8C0A2D278B6325C8ULL, 0x8AFC9CC7DC386BEFULL, 0x03D55837EDBE1709ULL, 
            0x96722025140F8F05ULL, 0x35998748480ECE09ULL, 0xF37300FA15F26D42ULL, 0xD0FDDFC351B32477ULL
        },
        {
            0x74423684DD775308ULL, 0x357B00A8B426DE13ULL, 0xD3FEEF6DBBFC21E0ULL, 0x505E8308D02AECBAULL, 
            0xCD0A59D646BBAA8FULL, 0x22DF7F80CB75E3FBULL, 0x55CE016CC713F4DEULL, 0x966774250D3957A6ULL, 
            0xD22AE0CE869B0E56ULL, 0x53109BB73897507CULL, 0x0C47D13CD2126DE5ULL, 0xA4E1C66A0D6C3564ULL, 
            0xC10F8B574F14D4CFULL, 0x671E1F3911A2E4B2ULL, 0xAD0A52639E31A0CBULL, 0xF79620EFB1BE482EULL, 
            0x93BAA618B759CA24ULL, 0x7B6C21F45EF2266BULL, 0xCD9092B959514B3DULL, 0xBAE6C6ACEB8BEDCBULL, 
            0x02AE1D33A79E5244ULL, 0xD460375D0D0FD238ULL, 0xD49B11B66DB452A3ULL, 0x06448C4DE8F56789ULL, 
            0x200FEA067A4C1DBEULL, 0x95C65E0D75FE2062ULL, 0x46C22327430702D3ULL, 0xB467A65361632323ULL, 
            0xAD550C02E9AD9659ULL, 0x8E0A0B28B25C0423ULL, 0x7017938845426DF9ULL, 0x2D7E6FB9331641ADULL
        }
    },
    {
        {
            0xFD401B2047C8B203ULL, 0xB23693CEAD1A1823ULL, 0xD1D2177B2ABC5A2AULL, 0x2397D97D710D434FULL, 
            0x14D5B7E5AC946E1DULL, 0x76FE60477D1D223DULL, 0xFF4E9EE52097842EULL, 0x71D6978BE89CD16CULL, 
            0xD9B1CC77D2C201ABULL, 0x6F3A49CE174C1405ULL, 0x852FEAEB65F2BD35ULL, 0x680C11DB3FFE8DF2ULL, 
            0x4D78F6AA36D433B0ULL, 0x4C299A61E1A74AA1ULL, 0x4EC6BA610B0FEE27ULL, 0xD1BF0813DEAC9633ULL, 
            0x2729558A4B9E19FEULL, 0xBA8BB3941DFC8544ULL, 0x62532789C9B3F573ULL, 0xE83EDC033460AAE1ULL, 
            0x352FF619D9F52672ULL, 0x87BCCCF352C630DFULL, 0x74515ED74C816AF8ULL, 0xE8A0E0DB7FA4FD12ULL, 
            0x2F92617B01138C00ULL, 0x97400E1FE86F28E7ULL, 0x1925ACA6B8048144ULL, 0x4E7E5EB6CE58C4E2ULL, 
            0xC8F9378CE20622A1ULL, 0xE18196974436FF7DULL, 0x585E1BEE55BF3B54ULL, 0xD1E9A96084EAB2F4ULL
        },
        {
            0x3D184EDDF3CDDDFEULL, 0x97267AD11A95A783ULL, 0x3898F0D85A0AF2C2ULL, 0xCD46604F718480DFULL, 
            0x1B662980A7D7ABA5ULL, 0xE9BC2172B5F03DB4ULL, 0xC2108BB8E3DE699CULL, 0xF9570B4F2E960422ULL, 
            0x94832218EBB4B41DULL, 0xBE6624FA3824E826ULL, 0x9D7A4D7499E53730ULL, 0x81ECFC0576F653C5ULL, 
            0xC7DB54E7EBCC53C0ULL, 0x139FD5FD42DC9066ULL, 0x54435206CAF178C8ULL, 0xDD54AE15D20ED32EULL, 
            0x0F01501904B99AD8ULL, 0xAC99C10FBD7926B9ULL, 0xD3E2FD01E25148C8ULL, 0xB44818314896EBC0ULL, 
            0x30EF2D74C3028609ULL, 0x2CC4A276781E9649ULL, 0x6E84857B8B9856F5ULL, 0xFD3827C5EDF67B9EULL, 
            0x63583BB0A6416874ULL, 0xB52867186E394A6DULL, 0xF7B61E1D30D97EA5ULL, 0xD8A49908418E0D69ULL, 
            0xDC9F363397F7FE02ULL, 0xB427903F7548B04AULL, 0x2DAB976B458C72BAULL, 0x6752AEEA92A53D18ULL
        },
        {
            0x7700C5F7B8224A69ULL, 0xB2AC9C2E00313180ULL, 0xBA7E147D09E23B4AULL, 0x5359587101CF52ADULL, 
            0x399D9E838CC037DAULL, 0x90785D51C2ECC766ULL, 0x265FF72DAFB95F50ULL, 0x5331CFAAD6585E4EULL, 
            0xAC3B31D6116C7B3DULL, 0x745306AB6FC6C6D8ULL, 0x1B7CB2753E1034CAULL, 0xD1F5A6E1786B84A8ULL, 
            0x6C476602F1D2C3D1ULL, 0x04100AEC9C3DAEC4ULL, 0xE982578658907913ULL, 0x05693086C3F9A00EULL, 
            0x8DC261FDA7BECC08ULL, 0x4F0114ED2BF3296DULL, 0x470DE1F6D1E6B347ULL, 0xBF33E9E7DF3C025AULL, 
            0xE273AAA108DE1CFFULL, 0xB2DF2F4733062924ULL, 0x5121CC2C480BE4F3ULL, 0xF445DE508E58A09AULL, 
            0xBE60795F1C0EE3C7ULL, 0x0C39A83D78A2F95AULL, 0x26F3EAAA9901A764ULL, 0x900CD758F31CB221ULL, 
            0xE6FCA7057B14D12CULL, 0x5D1AE61239B4F1D2ULL, 0xE00FD561B09679EDULL, 0x6EA7F7DF4FAC0A47ULL
        },
        {
            0x1FB0D66D9094916BULL, 0xD2ECDA9129BA6860ULL, 0x448D1EDCADC07BC7ULL, 0x916D62FCBA989F28ULL, 
            0xB0AC88C8F3127B5DULL, 0xC5530C936C423954ULL, 0x0A24D1D163F4D789ULL, 0x575D9F0730472C1DULL, 
            0xF0D214794347F44BULL, 0x59DFD74E9CFB76F7ULL, 0xD102790B2EE4A698ULL, 0x05448930F0DF5EB2ULL, 
            0x288B6D406CC07041ULL, 0x58ED6CE491CA749DULL, 0xED4B0BB049F48DA8ULL, 0xBB1D86ACE7F23FD3ULL, 
            0x9E5970BE12C5040FULL, 0xB7868A106BD86ADDULL, 0x81052D6F7F4C32CAULL, 0x523053AC1C6E6895ULL, 
            0x98410E8B7575AA22ULL, 0x76D2C3D529E61C0BULL, 0xCB98F7ABB741D0C7ULL, 0x620C814A93E29FF7ULL, 
            0x9C8766677958CEBBULL, 0x3E3587F8D361F488ULL, 0xF3075C8BFCD2B481ULL, 0x48CD71165F6D20B4ULL, 
            0xB44C91733068E981ULL, 0x40F32E9CE0241DFDULL, 0x238F80D035A355F8ULL, 0xC8FE6AD984079826ULL
        },
        {
            0x93E1A62408672CE5ULL, 0x931BDBBC581B8138ULL, 0xDB15642BA8F226F2ULL, 0x44AB92FE7301E93EULL, 
            0x1D00D6E968B4BC9FULL, 0xBC1665CB2D815E8DULL, 0x9C402A92710E0869ULL, 0x195E3DC7C7C58CF0ULL, 
            0xE3BDC5F1B0B167F1ULL, 0x03DA7E6D9AE1D2B1ULL, 0x21247AB5866CECBCULL, 0x1FD31CE6D7D0B99BULL, 
            0xE52A7A90D47C5682ULL, 0xDDA54C01E91F146CULL, 0xE839DE5E9BD4AD4FULL, 0x0EFE0D818B65C905ULL, 
            0x99BFAD425D6ADD17ULL, 0xCCEEF6C2294ED3A5ULL, 0x781ADA4CC63990E6ULL, 0xEB450E258E450C4FULL, 
            0x130BCAC1A3AF6789ULL, 0xB4D904DBCD073018ULL, 0x31B3F24FEDE17920ULL, 0x8748E2002C2C2578ULL, 
            0x986F785A654519DFULL, 0x1AC031661A407504ULL, 0x15061677CBCD5E67ULL, 0x3205837C1FDA5930ULL, 
            0xF936DAFDF010D1AAULL, 0xACD263A7043D1F48ULL, 0xAD1A93D826A88A83ULL, 0x173F7FBE4D8457ADULL
        },
        {
            0xBA0C9B2401B1C566ULL, 0x0E76EDDD4061C209ULL, 0x46DC836429EE0BE2ULL, 0xA800C4703732E1F7ULL, 
            0x268D3CE770169F35ULL, 0xC64D4245EA5A0766ULL, 0x20916B0913D84DACULL, 0x19040A920C807261ULL, 
            0x14012717C07EC1B4ULL, 0x39E55FE3E0998A15ULL, 0xE5993D54E98DAC20ULL, 0xD684545B4731244BULL, 
            0x5026480EA06FD69EULL, 0x757A8A5CD1349038ULL, 0xE481B2A8E4133F32ULL, 0xBABC4EF569E8B91EULL, 
            0xB17BB27A3B7D8148ULL, 0x3E01402428CC7E46ULL, 0x8F91BA0B80141C9DULL, 0xF52C72D4580055E2ULL, 
            0x03DE40599E6FE518ULL, 0xEDF723DF467BE788ULL, 0x872E3FD4C675DE94ULL, 0x36CF4AB16C928A79ULL, 
            0x6F66FD94EBB25B6CULL, 0xA041E36A48937A17ULL, 0x611F13C7673D4A73ULL, 0xD020DCD6EC2F81DAULL, 
            0x45C77B37C49CD22CULL, 0x9D320C88A10B1A2CULL, 0x1C18892EE89C2BEBULL, 0x1F194B5DDC988489ULL
        }
    },
    {
        {
            0x2793D996B409C773ULL, 0xFAD79777639C07D0ULL, 0x1815E71EB21B71B0ULL, 0x3927F600EA53829DULL, 
            0x7B36D9E0679E5CD0ULL, 0xC74EC227DE634723ULL, 0x9A99616CD1E937FDULL, 0xBCB920EC2CDFC8FEULL, 
            0xEF03839063C5A93DULL, 0x148020070262429AULL, 0x07431594A974FDC2ULL, 0x2B01145DBB227381ULL, 
            0x06CF063D58AB340CULL, 0xE70A720052F1FDA4ULL, 0x212634940BBDA9CBULL, 0xC57ED4A81DA4E96FULL, 
            0x65BE0BA13401493DULL, 0x1D06ECA0EA123DAAULL, 0xF4E4ACAE2F5256C5ULL, 0x3950EA66E8CDD6C2ULL, 
            0x6E004FDFFD5478C2ULL, 0xD67C34B576170742ULL, 0x4F7385BB258C22C1ULL, 0x6A7B914B6D557D29ULL, 
            0xC464C10D8A79A9ACULL, 0x42B8F2FF50EF9ED6ULL, 0x4C4CF68E6C559F05ULL, 0x073708DC670DEEFDULL, 
            0xE6D6BF96EE8CD4D6ULL, 0x27FB050BD2922CD7ULL, 0x11396C4031B74DCFULL, 0xB484527140BF0DE4ULL
        },
        {
            0xFD3CA82C99C32876ULL, 0x86154D42A357D25DULL, 0x89E3B0353C34FBC3ULL, 0x552E7F6A71FA957AULL, 
            0xEDE4907696AAE9EEULL, 0xEF6DA2961179D75FULL, 0xAD5886359ECE0189ULL, 0x7BCF103A93B454A0ULL, 
            0x87BC63153770C9C7ULL, 0xF7E211482AFEC57DULL, 0x56EAAB452AE58E46ULL, 0x0DD6FD009DD1E85BULL, 
            0x86613B9DB2F9B976ULL, 0x6FA37FD65B31C13BULL, 0x057420BC7912700EULL, 0xD6EE2249E806BA43ULL, 
            0xD7FF1BEF9C68C54BULL, 0x6C694EDD60FE4584ULL, 0x2DF4DA4461645543ULL, 0xEBC585420D356FB8ULL, 
            0xFF8BD5CF38E38283ULL, 0xAEEADCDD8403AC74ULL, 0x546495870118EFC0ULL, 0x37816FC5E28203A0ULL, 
            0xA7A3FA3A7C9CEF22ULL, 0xFC75DBB63D308193ULL, 0x5542E11439BC7574ULL, 0xE8C01B14CB78E24CULL, 
            0x45F0AE8F90725D23ULL, 0x09167B99750E4E12ULL, 0xEF0DEDBA2CA47247ULL, 0x86B71CC7C38391E9ULL
        },
        {
            0x9CD28C00737C43DCULL, 0x13E2DE0A7E1B2F49ULL, 0x4236121950484DC9ULL, 0x9751A29BFC710BFCULL, 
            0x26563653ED2776E1ULL, 0xE9EB27EEFA0F3299ULL, 0xEE4B327F90D6FBE0ULL, 0xE0423282BB61BE0BULL, 
            0x3FB05CA883F88D17ULL, 0x77AF92B8E28BC70CULL, 0x0B4BBB576DA1CC99ULL, 0x4122074CBA8194ACULL, 
            0xAA70355999FC0A70ULL, 0x4997C0CD0704D2ADULL, 0xBD9CD3EC1A21F7CDULL, 0x54A187517F11B5C1ULL, 
            0x81644E9C44429A89ULL, 0x4DA86FB1957EC80CULL, 0x0FE9707A02F7F49BULL, 0x8090EEB3AC252F0BULL, 
            0x49C1CA53A98D308CULL, 0x3F2D986F51B1180FULL, 0x26BDFE2B3CACE1DEULL, 0xB5C7E119C9AA5EE0ULL, 
            0x03594DABA9400824ULL, 0x745AC28441EDC897ULL, 0xF6885717167F76C6ULL, 0x8ECE2CCD5F336DD0ULL, 
            0xB7C3F216C5F9AE43ULL, 0x1E32F4707E80B869ULL, 0xE2D9E324A9D21DFDULL, 0x89EDC9E1BE8719F7ULL
        },
        {
            0x2FF32441ED349C66ULL, 0x6E6C840326E11F23ULL, 0xC19780A3AD850F10ULL, 0xD4957558BCF428DBULL, 
            0xB85B756F68A57D35ULL, 0x198370D8C6848BCCULL, 0x23A29A2533CD45E7ULL, 0xE967DAE2D35D91B6ULL, 
            0x637F355093EB7E71ULL, 0xB873E27947B83106ULL, 0x833E06AE580ADC9DULL, 0xC0E48BBE6F92D7B2ULL, 
            0xE154F72F16256E34ULL, 0x75D6E5B2391E632AULL, 0xFD8ECB72C7B84053ULL, 0xC499CCC5E8D342B9ULL, 
            0xAE211CBDAF66501AULL, 0x8C5B9554922919ECULL, 0x483D6DDD590D4E42ULL, 0xA7CDF6328850AA53ULL, 
            0x9F108E0CA188B532ULL, 0x9949BA714D58C70AULL, 0xCC3ACD94696DBFADULL, 0xAA76C10DC0041D20ULL, 
            0xA3EFB1CA142CC2FFULL, 0xF5BAA22B19F0425DULL, 0xB861D05320F097C5ULL, 0xD673338297239816ULL, 
            0xE97F8D3808DE3A31ULL, 0x35123CB83520365AULL, 0x7D3738A38033E8C8ULL, 0xC712A9196530B580ULL
        },
        {
            0xE9B1940EEE54DCE2ULL, 0x96B7C5A9741525C0ULL, 0xA1A7787083440132ULL, 0xA29F9AEBBE4B7BE3ULL, 
            0x6A7731BE6A66EBFCULL, 0x9D9197ADB8A2A8F3ULL, 0xC9846F00FEA2DBE5ULL, 0x5889988FB5339871ULL, 
            0xD0F5954B7129109AULL, 0x49F1F5BD868BD8F9ULL, 0xC10DE4A3A1111074ULL, 0xFD67687B115AC191ULL, 
            0x63E55155797C9681ULL, 0x3D4CDB805BA63F8EULL, 0xAD17D3049AEF092FULL, 0xD53F64BAAB1A2EC1ULL, 
            0x5C10D48CFCE076C8ULL, 0xB206016B3C026D49ULL, 0xD99AE3BE93253CA6ULL, 0x521147AA5A56F0E9ULL, 
            0x023638FEE7426592ULL, 0xF0339ECEA5068C9BULL, 0x2A64EF68D9F24272ULL, 0xE5200903543A8F78ULL, 
            0xBBBB84FA2F23046FULL, 0xABA7604216FA45C7ULL, 0x38AF71309E82EE97ULL, 0x90590528B8A8C0E5ULL, 
            0x4311FBB9652E5E87ULL, 0x63754F742F1D1DDEULL, 0x5A1A5C2FB6DB3964ULL, 0x799A56C28CAF5C38ULL
        },
        {
            0xB495ABCC762E0C5EULL, 0xB22FE19C830C336CULL, 0xFCFDA1C7D7B2885EULL, 0xF4B91C92D301C5CAULL, 
            0x157B6C40C4766B68ULL, 0x555C0AD57A3D2CA1ULL, 0xC5D6A637F8187A2AULL, 0x59DD61BD400EC445ULL, 
            0x29C61EAA3D8FA85AULL, 0xACCBC587D48B32DEULL, 0xF68BE4D893DE5C1BULL, 0x183172B69F4DE920ULL, 
            0xB87997B6A1A0C515ULL, 0x084F0443A39BEE3BULL, 0x68D50870149B6576ULL, 0x94BA491DC1225CFCULL, 
            0x009663371A34D189ULL, 0x6A67B0DE7D1A3668ULL, 0x5DC923F253F7A48AULL, 0x0DE1DE26968E1DC1ULL, 
            0xE0053B4A4BA19A22ULL, 0xD6CB16AE4F47E77DULL, 0x2F9FE2CDEFD1738FULL, 0x2A2DA239ADC3C85FULL, 
            0x03FEF9FDF8383EC9ULL, 0x893C8DD5D547BF49ULL, 0x83CF31E674E9D530ULL, 0x0A1BB7E070FB596EULL, 
            0x707D5D4CA479BA70ULL, 0xD5F66F0A30315660ULL, 0x99A9DEDB01AA7F92ULL, 0x49C5359E8C4DAB85ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kPhaseCConstants = {
    0xDC3A6769E085AA01ULL,
    0x079F8689088747EEULL,
    0xC227DFDB316FF283ULL,
    0xDC3A6769E085AA01ULL,
    0x079F8689088747EEULL,
    0xC227DFDB316FF283ULL,
    0x53AEDDB52E90E805ULL,
    0x6D324A7F83291D3CULL,
    0x75,
    0x5D,
    0x4C,
    0x23,
    0x84,
    0x47,
    0xED,
    0xED
};

const TwistDomainSaltSet TwistExpander_Polaris::kPhaseDSalts = {
    {
        {
            0x64DD4EE247F8F943ULL, 0x3F6A322DAC682FF4ULL, 0x292203E823AF14C8ULL, 0x0DE1649CA0C929B2ULL, 
            0x6616FD595F41F200ULL, 0xA1103F8AE9EA638FULL, 0xC17474710C5CDA29ULL, 0xD53EC11F8CB0FCD2ULL, 
            0xF4EB070F5B458342ULL, 0x64AD910ACF136759ULL, 0x486CEC9930D1DFF7ULL, 0xCF45BD6BC52DD0E2ULL, 
            0x703B47A4B39D9F87ULL, 0xEA7463E8FF6778E5ULL, 0x21A67BA8872CF402ULL, 0xBA51F3754DD15EC6ULL, 
            0x59044CC5109D58C4ULL, 0xB68179CCA1978F70ULL, 0x41F2A767DAB5AD44ULL, 0x185BD67F801E6D4EULL, 
            0x935DDF8FEA4EB04FULL, 0x14C894CB9135109EULL, 0x89EB9726CB8EFC6EULL, 0xDB69BD728FCF7F5FULL, 
            0xBDFBF7E054F453B9ULL, 0x2E1E17BCB7243C8BULL, 0x53D5B92FAB16BC53ULL, 0x09CC8A2B93E65734ULL, 
            0x6EAAE96DBC023DA0ULL, 0x87B3783483F54345ULL, 0xBA2341553469181BULL, 0xF24D5124A5C15E40ULL
        },
        {
            0x10528EC9EB718B6AULL, 0x2B04BD88D7192211ULL, 0x6193ED52DDD342BBULL, 0x3CAC86F55E87E016ULL, 
            0x204A7183DE054DC0ULL, 0xA255C92EBE672D32ULL, 0x5ED6FE675BC73A57ULL, 0xA2D869E7ADD036A6ULL, 
            0x6AF854C3FEE60BB3ULL, 0x076286463410024CULL, 0xE66FDB26832ADA92ULL, 0x3AA391CD1C60D335ULL, 
            0x3162C0CBD8ACD62CULL, 0x4BAC8E47C4CCC599ULL, 0x3A80FC3CCE32E7AFULL, 0x95BF546C00AC6E0DULL, 
            0x6FC8512B8F577B6CULL, 0x0574B579EB869F33ULL, 0x72D152FF75FF5529ULL, 0x9CB96A4F67E0C24BULL, 
            0xBF6FBB79A3B7842DULL, 0x152FA9FD37695F7AULL, 0x0653DE3708D5D096ULL, 0x21C54DC64856C642ULL, 
            0xA4EC15349D3C954CULL, 0x197538EC75093080ULL, 0xB5AF3308B57B3538ULL, 0x18E80F79F338FBDCULL, 
            0xACC4BB8A4A6D9A64ULL, 0x28582B48C1C953BDULL, 0x06A2F9BA19BF1BE3ULL, 0xAEF5EC667B71B44AULL
        },
        {
            0xA723F5F1EFCE2FABULL, 0xEB54B0E50961871AULL, 0x4F5A256726F22DDCULL, 0x8DAA24A75F3FA789ULL, 
            0x8B97CC4FC8D49FA2ULL, 0x13D6DEE9CFCF1095ULL, 0x5B93201F72EE500EULL, 0x3D540C0BEC46A5B3ULL, 
            0x735E6D70D7EB2625ULL, 0x6B5EF3B874915DC2ULL, 0x96ACA244C0810464ULL, 0x51ABDDE015A83677ULL, 
            0x7A57CA53F17B306FULL, 0xFD56D862AE31F116ULL, 0x6BA037F165852CB8ULL, 0x8FB34FB62C89222AULL, 
            0x34CAAB734B4ECFCDULL, 0x909FCB1E8011062BULL, 0xA0CA35A84EEE78DDULL, 0x6D8F703F60C3AB1AULL, 
            0x249D23864D9C7EE8ULL, 0xE355F736B90937FCULL, 0x9E910C8FE1F46B99ULL, 0x7ADFB3BBA5BF1E6CULL, 
            0x443DE714F824DC94ULL, 0xEF686B785F1D3952ULL, 0xCD776B4DE4BE6A5BULL, 0xCF7CDC0B3EB23E08ULL, 
            0x5B03A788C6F65538ULL, 0x20619AF8A555A889ULL, 0xFD8DDE696855BB81ULL, 0xA7052DE1CFB108AAULL
        },
        {
            0xBC914C0E5F30833CULL, 0xDDA88A2CDCFCAD14ULL, 0xCCFF43207645A49FULL, 0x2B1D9F300AC74D67ULL, 
            0x54B7ADCA80A45FC2ULL, 0xAB69E30B39EC7F0CULL, 0x911DC82BA1AFFE62ULL, 0x2B1F1780F30198DBULL, 
            0xC52B6BED8BEA342FULL, 0x7F6911DC0E1E038CULL, 0x41583A6EB24BCFA0ULL, 0xA5C21B814231AC15ULL, 
            0xDAEB491896F07A99ULL, 0xA1C838DA9999F07EULL, 0x1945A813629AE90EULL, 0x25651315FEE27B8BULL, 
            0x3D4A419962D2A699ULL, 0x6B67FC42711444AFULL, 0x1D5FBCC3A188CAD0ULL, 0xA22582845962A623ULL, 
            0xF551698FB0E31580ULL, 0xF9778073E8D66CF4ULL, 0xBE6F96A8429C41C4ULL, 0xD117CBED13053833ULL, 
            0x86B979F37C41D6EBULL, 0x0D8FE08183940724ULL, 0x5D9A2C78AB64534AULL, 0x504AB4FEBBC7E63FULL, 
            0x40FB4869B3E063C4ULL, 0x122D6B52ADAC21A3ULL, 0xCD8631BAB47C1D54ULL, 0xDA85950623392E02ULL
        },
        {
            0x359744D13D4AC7CFULL, 0x65C01CD2D726811CULL, 0x76C8A1FEEC1E89B5ULL, 0x325AFE753A8CC70BULL, 
            0xB995D275983899C0ULL, 0xB2EE25ADB9052333ULL, 0xE99CC4BA9DAA5CAFULL, 0x75638D7CDA7443C9ULL, 
            0x08CEEB623F589281ULL, 0x79E34CC55237412AULL, 0x995CA62EBF0C1355ULL, 0x2091A7DF07F22B18ULL, 
            0xDB915C1ED1FB9AA5ULL, 0x12D8F420D1785986ULL, 0x4E2FBAAB1C64848CULL, 0xCA875D88CA317216ULL, 
            0xC76C736E106A9BBCULL, 0xCAD9DAC2CEA61C19ULL, 0xABD4304DB6C99E5BULL, 0xC47AC2BD1B271929ULL, 
            0xBB9F07755172EC44ULL, 0xB5FA50CC2065FA73ULL, 0x054C4478787E6998ULL, 0x4464BC4DCA0012ACULL, 
            0xCBCACCB26B9B8976ULL, 0x0FE160DC393D4BACULL, 0x87D55DDD07A7EDC7ULL, 0x4991F422C95551F9ULL, 
            0x1998611F158E20DCULL, 0xE4AECE9059C7E436ULL, 0xB7CCCC795A556994ULL, 0x308CB8F715FA0747ULL
        },
        {
            0x7DE1FE2EA993EB46ULL, 0x5D6095316B8FD433ULL, 0xB8209E462D8F4D8CULL, 0x9D148EDB21BDE2C9ULL, 
            0xDFB81E37EEDBE6BAULL, 0x3B020C51901FE28FULL, 0xBF82BC9220D4FBBEULL, 0x1AA21CE22AA743D5ULL, 
            0x1AD5DC3D55F89C61ULL, 0x065758DF58A02FF6ULL, 0x00CA3481FA5B2BEEULL, 0xA6319CEAF4A01C5BULL, 
            0xCC811BC30AC468CCULL, 0x260350C861415661ULL, 0x5BBC83507D2E260FULL, 0x0921AAA395E80810ULL, 
            0xD165E463545C30C0ULL, 0x485D8CAF25350938ULL, 0x31BB5B28EEE3A66CULL, 0x1878937F8C02BF0DULL, 
            0x1219C40377BAF2BAULL, 0xB27E1A5D43E5C10EULL, 0x09F65D6100212FAEULL, 0x3CF1D2C1E0F63110ULL, 
            0x2B29AA6B144FEF2EULL, 0xDE575B0B5776D159ULL, 0xB92E91622DD9EA64ULL, 0xAAD60FEB1B14DA09ULL, 
            0x61EF85469BF9C655ULL, 0x339EF8640B1ECE17ULL, 0xB6A6165236204D95ULL, 0x46EF4421A6BF693EULL
        }
    },
    {
        {
            0xE0869600C38EF02DULL, 0xE2F4B0E8411BDF22ULL, 0xF75185EBE957FD20ULL, 0x4278FF3C5BC6DCEAULL, 
            0x9FCE46BC3C84ABD6ULL, 0xE0CA42A025098E90ULL, 0x6A9BEB845EFCA8A8ULL, 0x5839036357E96261ULL, 
            0xABC11F547E8B1D9EULL, 0xCBE4830D1B25F93CULL, 0x0163B02F61377634ULL, 0x4F39247202DD1B2EULL, 
            0xB6D22C7C0B4D9701ULL, 0x332E25CC8F02C996ULL, 0xED2163C28E3EE143ULL, 0x17DE9AFF7D1D857CULL, 
            0xA9EA3D1960087EBEULL, 0xCC6C6CC90AF250F5ULL, 0x849C34711FDA0813ULL, 0x4FFAAB1161A3604DULL, 
            0x41EB5F35DFDB5FD3ULL, 0xA47F67A77E211225ULL, 0x3CAFD4C0339C0601ULL, 0xE9DBBA8BB7A134E0ULL, 
            0x66EA34CAE78075DEULL, 0xC999CD67780FBDDDULL, 0x164F4BD399F611EDULL, 0xA49A329730A71C4EULL, 
            0xC1C85FA2B1F4467CULL, 0xFA14F13586842B63ULL, 0x2154F43284E1DC4AULL, 0xCD28E8BFF0611ED6ULL
        },
        {
            0x7AA555985E2D7C1EULL, 0xFA001A3A56202325ULL, 0xEAAA4C1EBC1305CFULL, 0x603B32828DCF96F4ULL, 
            0x3418BD00F26648C0ULL, 0x68A4A802BCB9D832ULL, 0x6988626E8129296FULL, 0x3EA3696754C2AB2BULL, 
            0x9F861A6EFD1B145FULL, 0x01E3BE6DA0BEE518ULL, 0x15C2E8BF3119DE9AULL, 0x63F1E2044D73C9DCULL, 
            0xA6A1D57C1718C2D9ULL, 0xCDF04C551855657BULL, 0xCC64641B189E6DFCULL, 0x21D376631D3CEA15ULL, 
            0xA6D9870C853D9577ULL, 0xBF68C21E9DB44FA2ULL, 0xCFB92C42A6F161D4ULL, 0x5782F6FAF2E1C8B4ULL, 
            0x7AA40A181FF74D90ULL, 0x13B231A0B2AC6DDFULL, 0xCBE270299C8C238BULL, 0xD4010C9C250139EDULL, 
            0xEC8CA9E21D407604ULL, 0x6E700F48E1A893A7ULL, 0xF82AE6CE54DF7029ULL, 0xE72871FA6FD5F26CULL, 
            0x4A91D113E4B0FF2DULL, 0x5A61590D2425E0BFULL, 0x7719FB2783955EE6ULL, 0x5BF9F890EF6384E8ULL
        },
        {
            0x1FA813CA696BC328ULL, 0x6F2E77AB828EDF16ULL, 0x7E726C88B83DFC6CULL, 0xF8DB3E3BE2FC5FCEULL, 
            0x8EDC73EE71EB690FULL, 0xDCA0C179F566DCBCULL, 0xA27216A1C1493692ULL, 0x1A83AB22663F4597ULL, 
            0xD700B079ED9257C2ULL, 0xA0599FB5FA5DC485ULL, 0x9F6E679ABA34D833ULL, 0x87C16E9E61DE0790ULL, 
            0x3FBC0C11455F8463ULL, 0xB2C714F5E2491409ULL, 0xCE5A95E1B4DA8230ULL, 0x089239B3F1A3CBEFULL, 
            0x79F768541D48D898ULL, 0x3E73EBF1ECA5E07CULL, 0xADBDD4183CB4E153ULL, 0xA05457FB6503C3C9ULL, 
            0x64E432661C996F9FULL, 0x88A423E0C11CF812ULL, 0x4B8A0EBCD1E4286EULL, 0x1D40E9A372645269ULL, 
            0xFFCDE7849EE930B8ULL, 0x7AD83C9D345FAE77ULL, 0x93349ADA61846DC9ULL, 0x55A18C469149DF6BULL, 
            0xDBF3611A10F34E2FULL, 0x9D97863FB11FF033ULL, 0xFBF208B81CF3C5D0ULL, 0x5C70286B9FBE46D3ULL
        },
        {
            0xC9CE0E2B6C25DD1EULL, 0x84486CA1F5049623ULL, 0x8A04BA468A402F30ULL, 0xF2E68F66FB20AF9EULL, 
            0xB91B25EB33615338ULL, 0xDE36A0822A5EBC03ULL, 0x8EFA53D5F2744385ULL, 0x5B86A447092FBF33ULL, 
            0xA841A0056DC71E73ULL, 0x06E0E46E26A39A4BULL, 0x154754A8A202BC28ULL, 0x01B558500A462A6BULL, 
            0x8D9C8BAF15602458ULL, 0x97FCA708E6B8952FULL, 0xEDB177A4B2B50F9AULL, 0xF2084104FD96EA9BULL, 
            0xE9FAC0E4453BBBA2ULL, 0xAFD2225A4114768FULL, 0x505C7F9F5F3E8D0DULL, 0xF80C3775DF700D2CULL, 
            0x40B91AD820346F5EULL, 0x155F890CB7706696ULL, 0x668F513CC48771B0ULL, 0xF367CE410FC1A633ULL, 
            0xE2E2A159FC181829ULL, 0xB97F68C281772ED4ULL, 0xBC357A293C418277ULL, 0x237A9C39880CFF3FULL, 
            0x68B85DBE0FB2F76FULL, 0x3B00D4DD02EA7DA2ULL, 0x865AB90706B5E01AULL, 0xDA13B36066492C00ULL
        },
        {
            0xFBB4DCF9D32C7E68ULL, 0x195774FC7DB28A48ULL, 0x72410D5519B8D4D3ULL, 0x7F7526769826B627ULL, 
            0xBD94ECE31893FA6AULL, 0x2412855813DDA2C6ULL, 0x5C83A0F517CAC010ULL, 0xDB9B7282E8B29070ULL, 
            0xBE64F6506E56F3AFULL, 0xBBB128F111B63FEAULL, 0x8B24085F31AC8583ULL, 0x3292B60AE691B4B3ULL, 
            0x533C424FE7620284ULL, 0xF81F48956558062DULL, 0xA2A6D3A22B967939ULL, 0xF152EF17C4CD8D7CULL, 
            0xCF6AEFBA55AE697DULL, 0xBBD69014C470F076ULL, 0xFC410EF6E2D79843ULL, 0x3D6DF4102C418511ULL, 
            0x621D123DB6BDD9F3ULL, 0x4567406E598C81B9ULL, 0xBC63C422E7847574ULL, 0xD8259EA786DE23B3ULL, 
            0x45C2F40590DF0612ULL, 0x052D69DC8D5B0A09ULL, 0xB8D11F0055C1A216ULL, 0x77D484A857BE9391ULL, 
            0x00B7733AF9652934ULL, 0xD895A085EAB63E1AULL, 0xC5EDBBC2CED389F6ULL, 0xC14511727D97ABB8ULL
        },
        {
            0x35E88CBA47AB7932ULL, 0xCD4D9476457A26C2ULL, 0xDCFD4B5A411C89C8ULL, 0x6C9C012950B9516EULL, 
            0x7634EDD8A5994C5DULL, 0x96B373F7879EEBB0ULL, 0xC47FC54161957A38ULL, 0x07F7BF7788389219ULL, 
            0x5E2997292076EDDBULL, 0x9DFE3AA03DD28AEFULL, 0xCF3CCD38570AFC6EULL, 0x79E1384A7ED209ADULL, 
            0x2A09BADB6205B82EULL, 0x173BE83E8B97362DULL, 0x78D127CE26BD513DULL, 0x778E5677275B3755ULL, 
            0x69FA61916721332DULL, 0xC32F7893F87C671EULL, 0x9DE06EBFD4156549ULL, 0xFDF074EF7664E551ULL, 
            0x4766C92597B82303ULL, 0x1892C634C513239DULL, 0x35C8D4AFB079CA2FULL, 0x808132393391A6EFULL, 
            0x3E26BB1B296CF55EULL, 0xB0A8C963ADDE5860ULL, 0x7EA85706874D4664ULL, 0xFBE692D519D7E07CULL, 
            0x08FD42B766783A81ULL, 0x1C4E0712A5A86DBFULL, 0x1024C01F7AEB670DULL, 0x5D0768812CF12626ULL
        }
    },
    {
        {
            0x9BF789513B00CE41ULL, 0x2F40F77C9DD00D62ULL, 0x77F208B759A76E6DULL, 0xDF40E5F65B6F94D1ULL, 
            0x6D8A7B11B55E167DULL, 0xA67C5EDB355490E0ULL, 0x5CC941F3CF93EA4CULL, 0x81008E47C8060255ULL, 
            0x4288FDCE534AE7B4ULL, 0x36521B98D609A353ULL, 0x5624FDBDA1DDAD91ULL, 0x59FF583C7080E632ULL, 
            0xAB9DDC06B2184F8AULL, 0x0DF0066151555C2FULL, 0xF8D93A15DBD04341ULL, 0x07640418FAEA2CB8ULL, 
            0xDC36521EF4CCB7F3ULL, 0x7BBE14339AFFB90AULL, 0x3DC25B52DDF4F5BCULL, 0x6D86B6578E45E8D0ULL, 
            0x2A9470AB9A6EBED6ULL, 0x86423EF4825DD961ULL, 0x27891F6E0BCD6D39ULL, 0xF6D8BDEEC151330DULL, 
            0x0605B35EE1235FAAULL, 0x2F2E5ED99A47CBBAULL, 0x20F6293E9693B64EULL, 0xE4D19F8D2C634C7FULL, 
            0xC93BAF2777A37A2CULL, 0x0E3866C82B3C5EB4ULL, 0x75507392B7E397DFULL, 0xEE04D07B75CFACF4ULL
        },
        {
            0xF6DF7445F78CCBA7ULL, 0x890DD56A207DDD05ULL, 0xFE961A7CB5A24A49ULL, 0x3E473C8CA63389E6ULL, 
            0x40EA3B2B666B3302ULL, 0x36FFF78A36F0D57CULL, 0xD229EF9C28C43444ULL, 0x6EBDF9BE01B02981ULL, 
            0xD9E7FD379915781AULL, 0x99E1F64BF3C60CB3ULL, 0x4C623240CD574EEAULL, 0x11ED40C5347C3DF8ULL, 
            0xE653DF7C99FF23E6ULL, 0x66CEB1BFA1633BF7ULL, 0xC830312D16A4AB20ULL, 0x1CB02B17729CD007ULL, 
            0xE238D0577CE248DBULL, 0x09B9CD3A9B5A3A0DULL, 0xF9718C31578F8384ULL, 0x4F65C7100EEA8834ULL, 
            0xDFD0012ECFCA741CULL, 0x5BF8F030A946BF57ULL, 0x6228865564426FDFULL, 0xB2D7D0921617BCB0ULL, 
            0x4B048ACC1EB5A54FULL, 0x90BA67FFEF74CB27ULL, 0x68DE6D666567C1FCULL, 0x4C2E400C0AFB5CB1ULL, 
            0x7450BF4CF9E2A329ULL, 0xF4F7C0F039A4166DULL, 0x589030B7EE8C2B62ULL, 0x7A26558F2BDD02FEULL
        },
        {
            0x59F596FC766358B0ULL, 0x12AFC97A6A6586B9ULL, 0x086A93AE7C45F635ULL, 0x3FBD265676ACE77DULL, 
            0x1E0D3C7C3A9BCADEULL, 0x2BCA4505124D7034ULL, 0x7EDD8FD5A9B58093ULL, 0xF829AFE4EC5EA378ULL, 
            0x1EADF8C272D8E0BCULL, 0x5AD910630D9D56ECULL, 0xBC9234AB20CA727AULL, 0x6DB64C8D8F3F38CBULL, 
            0x01BC947EE36D0E33ULL, 0xAFE96F4DA22BF07EULL, 0x6972B5E5BC22A569ULL, 0x2ABE9B29F477BE62ULL, 
            0x1EC0CBB111604E64ULL, 0xD8FECABB3813FD53ULL, 0x78DB0F20CB5B415EULL, 0x70E2BDE00AA7C56CULL, 
            0x9A8F69154007D0D8ULL, 0x9820E25E9F8F1391ULL, 0x73D674F78787769CULL, 0x99D66A5CA32DF924ULL, 
            0x713FB616B604A77AULL, 0xEFE93ED90AC122D0ULL, 0x28492E10339DA33AULL, 0x694E5C9B285490C3ULL, 
            0x0EF917DD5E74E455ULL, 0xA30FBE6759E83D91ULL, 0xB28FB2607ECAE12FULL, 0x4EE7CA82F520357BULL
        },
        {
            0xFEFA3D483C001B46ULL, 0x548CA15EBCE2E2E9ULL, 0x3179EE6E54F16415ULL, 0xF4874B51BA953FF2ULL, 
            0xC3CD9393C2EBDFC0ULL, 0x2E9226ED3A5CDA87ULL, 0xD828A6E06588D31DULL, 0x013C8CB6410E6175ULL, 
            0x6626DFD1365431DBULL, 0x175EC7C642609F46ULL, 0xC93CA9F50C898A2AULL, 0x326ADE992E56AF90ULL, 
            0x656CEE8F2484EB14ULL, 0x6A76C376CED631A1ULL, 0x5D356BDE65FB2357ULL, 0x4A8DEFB2E9239FC8ULL, 
            0xCE50DF0B0B78AE2FULL, 0x4B54CFF04F6D628AULL, 0xC8C1A0ABABF8FA74ULL, 0x19538B42B28154B1ULL, 
            0x1DD61AEB06A62A64ULL, 0x6A3BFC792918C451ULL, 0x646F068AA5F41D6AULL, 0x6498C0B04E8EB8AEULL, 
            0xCFA24566161D6A87ULL, 0x226BE250F5AB330EULL, 0xFC47BD5F7D147EE7ULL, 0xEF368C6C842A765FULL, 
            0x0AEB4D4D7078CA08ULL, 0xA2E46E77C1BCCD26ULL, 0x7795123C1390A3E3ULL, 0x9645437089902E36ULL
        },
        {
            0xEC5F1864C7C53E7AULL, 0x4B215FF94369CC83ULL, 0xC0139A0E505E2C81ULL, 0xD17A7E8D875F0A38ULL, 
            0x9E3E6FF1A35A8E81ULL, 0x15DE855B2A380CBBULL, 0xDDD2F3EED97852EDULL, 0x5CEECA91347CB033ULL, 
            0x5AA0A17609E1B7BDULL, 0x212446DB1A13ECD4ULL, 0x8720F5BDBD2949D2ULL, 0x6CBCC1F81A41D129ULL, 
            0x246A4C88034C0E33ULL, 0x2F4CD18D779CDE63ULL, 0x3AB68E2AD9A5E0E3ULL, 0x5EC825C80F45A42DULL, 
            0x30B65D0B6A98A7FEULL, 0x1BE45BDE52BC7381ULL, 0x8F68FC0C5CE92621ULL, 0xDC339B1AC2FD5A5AULL, 
            0x5A3A7B8F1D5ED761ULL, 0xB8B1C3B5610041AFULL, 0xAC6888A50B22F145ULL, 0x49E3F42BA24B635EULL, 
            0x17AD178681F3F965ULL, 0x92E576D2F2B7EF26ULL, 0x60795A9474C8892FULL, 0xAC4781803E5C8725ULL, 
            0x0C9C675F267374BCULL, 0xA5C93A749EBBAD10ULL, 0x5B9ADE284EF94E40ULL, 0x0F8B19963C6A7EFFULL
        },
        {
            0xCF5DCD934954D168ULL, 0xCA1E62D643FA5D27ULL, 0xAEF828E21641ADAEULL, 0xB19C2E8D85EDF27CULL, 
            0x24405F1DFE1AD5FBULL, 0x79F4F77E652496CFULL, 0x6B4BA74A968B2F1DULL, 0xB403CDF3AC67A216ULL, 
            0x607D29ADEBF8760BULL, 0x0E989F4716F2CD8DULL, 0x4F9D9238F98B3603ULL, 0x2ABF2793DA941588ULL, 
            0xA008039D6FD1A430ULL, 0xE3E0A18C993D7B96ULL, 0xB7C235E381752A51ULL, 0xF8AC97D7FFF49294ULL, 
            0xEF2B6210534183F4ULL, 0x2E82F75C5D7A3948ULL, 0x7E4C5E128C1DE475ULL, 0x2A798B676AB82517ULL, 
            0xB94D6B979C70853EULL, 0x39E9ABE526F094C0ULL, 0xDF8B5248E7A03A04ULL, 0xB1FD2BB4877AC517ULL, 
            0xDDBA262A96948F78ULL, 0x8FE7AF459D86B59BULL, 0xB84E117EB040C545ULL, 0x8AC983B93FB9CF72ULL, 
            0xC2123C927A490C07ULL, 0x6F105F9B155440C7ULL, 0x6BF80D0E2677282EULL, 0x139967A30914428FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kPhaseDConstants = {
    0xD7F4439ECD02EEA7ULL,
    0x1E77C94A9D87C05AULL,
    0xFE07BCED31602D2AULL,
    0xD7F4439ECD02EEA7ULL,
    0x1E77C94A9D87C05AULL,
    0xFE07BCED31602D2AULL,
    0xA32F603DC41048AAULL,
    0x40EDEF24ECF67FDCULL,
    0x7F,
    0x40,
    0xAC,
    0x36,
    0x55,
    0x35,
    0x25,
    0x57
};

