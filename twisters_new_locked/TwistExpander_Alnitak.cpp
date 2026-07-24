#include "TwistExpander_Alnitak.hpp"
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

TwistExpander_Alnitak::TwistExpander_Alnitak()
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

void TwistExpander_Alnitak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA92327534DC89B9BULL; std::uint64_t aIngress = 0xF8FF5251F6F41631ULL; std::uint64_t aCarry = 0x96465D8C88464956ULL;

    std::uint64_t aWandererA = 0xB7B8922BA0AB4998ULL; std::uint64_t aWandererB = 0xDEC4FC6851B09259ULL; std::uint64_t aWandererC = 0xB4FCF3BC3380DFE4ULL; std::uint64_t aWandererD = 0xFCCC7354166B3451ULL;
    std::uint64_t aWandererE = 0xBE69398A9BE45D91ULL; std::uint64_t aWandererF = 0x8CB82DF7505F9165ULL; std::uint64_t aWandererG = 0xB2B6A58FDCD489E8ULL; std::uint64_t aWandererH = 0x97FA23235D7475C5ULL;
    std::uint64_t aWandererI = 0xBEADC091A88ABBB7ULL; std::uint64_t aWandererJ = 0x996DB9566948D6DDULL; std::uint64_t aWandererK = 0x9F231D5538F3197CULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC204532A8D82B6C0ULL;
        aCarry = 0xD0E050706B6C8487ULL;
        aWandererA = 0x882B1878C0FC8EFBULL;
        aWandererB = 0xE3F512C0C9971FF4ULL;
        aWandererC = 0xA05194E899F39CAEULL;
        aWandererD = 0xD08D3137A4848A64ULL;
        aWandererE = 0xBDBC09348ED04992ULL;
        aWandererF = 0xA33C49D45549FE3DULL;
        aWandererG = 0xD1A4312B9992A191ULL;
        aWandererH = 0xD4940EB06D5E841BULL;
        aWandererI = 0xA5B3A98886E5943EULL;
        aWandererJ = 0xC76F1847AE57C96CULL;
        aWandererK = 0xF61842D3394686A3ULL;
    TwistExpander_Alnitak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8E7198B07E3B7187ULL; std::uint64_t aIngress = 0x8A3DFF61A79261E0ULL; std::uint64_t aCarry = 0x94049814C6FE2D7FULL;

    std::uint64_t aWandererA = 0x987A7CD0FF06E3EBULL; std::uint64_t aWandererB = 0x92BE069B14814463ULL; std::uint64_t aWandererC = 0xE0FE594E0B23C2E5ULL; std::uint64_t aWandererD = 0x99900F6D319D4FF1ULL;
    std::uint64_t aWandererE = 0x97CC2514EDCDF0E7ULL; std::uint64_t aWandererF = 0xC7224D52B634731EULL; std::uint64_t aWandererG = 0xADE5BAD8F14DA726ULL; std::uint64_t aWandererH = 0xFA0A375347B43A2AULL;
    std::uint64_t aWandererI = 0xF522A5D4EEC91734ULL; std::uint64_t aWandererJ = 0xC1FBA11C129C847AULL; std::uint64_t aWandererK = 0x9C89B19E04F1F4B1ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB0FCA8D9AA779B12ULL;
        aCarry = 0xAA82E92458003B64ULL;
        aWandererA = 0xE775B1CABB501218ULL;
        aWandererB = 0xE461571E89FE2173ULL;
        aWandererC = 0xD8C4E84251BDA75CULL;
        aWandererD = 0xA8A2D4B4F236096EULL;
        aWandererE = 0xBF5BA5B3E90860CFULL;
        aWandererF = 0xCC160CCDF55CB293ULL;
        aWandererG = 0xB8E3EED60E26399BULL;
        aWandererH = 0xADD8D9D1EA08D00DULL;
        aWandererI = 0xD7AB589BF0BE7FDFULL;
        aWandererJ = 0xEFD5A4218C5EDFB9ULL;
        aWandererK = 0xCA727489698FC158ULL;
    TwistExpander_Alnitak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alnitak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x963212A5047DCA5BULL;
    std::uint64_t aIngress = 0xAFC159D7A3E56A5DULL;
    std::uint64_t aCarry = 0xC708A72771FD5A3EULL;

    std::uint64_t aWandererA = 0xD7E946645C1AB2B6ULL;
    std::uint64_t aWandererB = 0x89A449D11F8A61EEULL;
    std::uint64_t aWandererC = 0xE354EE3DCF631B02ULL;
    std::uint64_t aWandererD = 0xB82C1397628019A2ULL;
    std::uint64_t aWandererE = 0xD5CDC1D8BC406D89ULL;
    std::uint64_t aWandererF = 0x92F140EF139E8A05ULL;
    std::uint64_t aWandererG = 0x8C157B8E6DE1CCACULL;
    std::uint64_t aWandererH = 0xDA2FA4FC56B4CD99ULL;
    std::uint64_t aWandererI = 0xA29545B0525E34F2ULL;
    std::uint64_t aWandererJ = 0xBE5CF30794A5AB95ULL;
    std::uint64_t aWandererK = 0x90907F8C0030E71AULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneD, 0);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneA, 1);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneB, 2);
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
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
    TwistExpander_Alnitak_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
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
    TwistExpander_Alnitak_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Alnitak_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 6 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 951 / 1088 (87.41%)
// Total distance from earlier candidates: 4789
void TwistExpander_Alnitak::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1170U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1698U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 34U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 322U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1876U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2009U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 850U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1820U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1024U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 202U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 427U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1120U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 329U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1046U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1692U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1987U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 530U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 719U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1206U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 856U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 17U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1163U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1145U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1627U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 755U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1952U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 649U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 933U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 369U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 726U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 472U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1922U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1347U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1994U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1912U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1209U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1002U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 600U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1254U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1424U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1068U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1939U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 88U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1982U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1074U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 228U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 167U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1909U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 13U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 365U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1277U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 978U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 295U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1702U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 813U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 852U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 280U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1069U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 946U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 238U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1554U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1000U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 784U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 435U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Alnitak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x966CCA46226B6335ULL; std::uint64_t aIngress = 0xC1EA416A1BD1BD23ULL; std::uint64_t aCarry = 0xFB7AF69A55F54F7AULL;

    std::uint64_t aWandererA = 0x9E4BC70617204EF9ULL; std::uint64_t aWandererB = 0xDF5860039302EBBBULL; std::uint64_t aWandererC = 0x81B27F2A50FA6304ULL; std::uint64_t aWandererD = 0xB713ABCD43D45746ULL;
    std::uint64_t aWandererE = 0x963C0A39368B5362ULL; std::uint64_t aWandererF = 0xE4FAA5FEF1B86BADULL; std::uint64_t aWandererG = 0xFEEA78581CA54F35ULL; std::uint64_t aWandererH = 0x884D22DA6059376CULL;
    std::uint64_t aWandererI = 0xE298BF6E33B72FA7ULL; std::uint64_t aWandererJ = 0xE5298767092AA27FULL; std::uint64_t aWandererK = 0xCC1FDD0D15D607A4ULL;

    // [seed]
        aPrevious = 0xB77BAE1BC013B053ULL;
        aCarry = 0x91E95A9422179BB2ULL;
        aWandererA = 0x816635C9F4498CA3ULL;
        aWandererB = 0xFFFEDBB2E17603FEULL;
        aWandererC = 0xC1F99F108A1E2F29ULL;
        aWandererD = 0xC6F1E056EBD8DE97ULL;
        aWandererE = 0x90A504562A5DC6A4ULL;
        aWandererF = 0xDB1B69A3390179B7ULL;
        aWandererG = 0x97292CCC2EE2EDD3ULL;
        aWandererH = 0x88415278115D6B8CULL;
        aWandererI = 0xDE7A4BCB1795196FULL;
        aWandererJ = 0xE5E575BE9B872DECULL;
        aWandererK = 0xBAC7407B30C48B20ULL;
    TwistExpander_Alnitak_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgD;
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
    TwistExpander_Alnitak_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 6 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 2861; nearest pair: 525 / 674
void TwistExpander_Alnitak::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 101U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4907U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7583U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4425U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3467U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 829U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2562U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2446U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8126U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3324U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2160U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4047U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5819U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2308U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 124U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4906U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 148U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 682U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1727U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 504U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1415U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1468U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 919U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1612U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 760U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1372U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 910U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1816U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 937U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1051U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1977U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 6 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 2853; nearest pair: 540 / 674
void TwistExpander_Alnitak::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7723U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2279U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5465U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6129U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8011U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 227U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6893U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4093U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2041U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6268U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 939U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4267U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4782U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4686U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1686U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 644U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1000U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1124U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1760U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 749U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 432U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1414U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1410U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1605U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1450U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 828U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 974U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 580U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1346U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1041U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1365U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1042U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alnitak::kPhaseASalts = {
    {
        {
            0xCE99B1E959E5A4BBULL, 0x6D6B848FE0D4AE0EULL, 0xCCB79E430395C816ULL, 0xDB69DC5C1421E111ULL, 
            0x277899432C7F9416ULL, 0x7CCA4C17229355F1ULL, 0xB80D43B18A531760ULL, 0xB1D0623B34025445ULL, 
            0xD3DF391CE13B8114ULL, 0xEF955FFCB09CE25DULL, 0xCFB2D30EADABCFD7ULL, 0xCE62610F840A7597ULL, 
            0xAE358B39FEEA9F9BULL, 0x5B54CE26939FE1CAULL, 0xE5FF92109984158BULL, 0xC23136BFA303F9ECULL, 
            0x7794843E5471B1C9ULL, 0x0181BF430A27703FULL, 0x51A72D7418AF59B4ULL, 0x10B1A44C88F64710ULL, 
            0x5058E4DB492EB2BFULL, 0x14D7DBE7598014EFULL, 0x746E01514C2E0B80ULL, 0x4BC15BCD8BD766BBULL, 
            0xED09090D8C14A8DFULL, 0x85A3261511F99368ULL, 0x88CD2EA63EE04333ULL, 0xF25B550ED2D2509DULL, 
            0x512C51E321B1D05EULL, 0xB05BCBE785B23EDAULL, 0x3344F02F7B4896F0ULL, 0xF52C79903B98BCFAULL
        },
        {
            0x5F2C7A8F219D4482ULL, 0x067B2333D8DF8CC4ULL, 0xC43FF53EF3C24EA3ULL, 0x404B0E099A143D75ULL, 
            0x3586152B3D410957ULL, 0xECB1D5A91F762B33ULL, 0x8E543DDC4F67DB48ULL, 0x46217B57323C1AF1ULL, 
            0x7287273BFC89403DULL, 0x05D16E92F2FA7FCCULL, 0xA678FFD2811B2F5AULL, 0xC944B7EF1BB2250DULL, 
            0x65AAB56A4A856AF6ULL, 0xF3C5094DDD88314BULL, 0xFEFDA4492C4F51AEULL, 0xBDE9FB26027225C2ULL, 
            0x30580D110E4D8ABFULL, 0x9F0F7C1F4097221CULL, 0x4868C2BE705424D1ULL, 0x89D3760B499DE017ULL, 
            0x7EBAE2A6B19628ECULL, 0xAEAC58666C651A28ULL, 0x814985A9B4EA6CD3ULL, 0xA9202AA5B1F4409CULL, 
            0x4628D63EE1FDD733ULL, 0x6F40545AE35CF3F7ULL, 0xDBAEBF8BCD9BA4FAULL, 0x1C8177797FDDFD27ULL, 
            0xA80032B74EA2C31CULL, 0x1A88CC9654BD5A95ULL, 0xE2AEC09F5C6F2885ULL, 0x3E80FEE4F1074BCCULL
        },
        {
            0xD24DA5E206FACBB3ULL, 0xEDD83668DA654841ULL, 0x7C13A974AF7C1503ULL, 0xD68A39A4CEB545CBULL, 
            0xE19E927CDBC96B71ULL, 0x9CEE7F6FB81655B7ULL, 0xFCD53FC7B7BCEACFULL, 0x1B80B28124F4D629ULL, 
            0x3EFAE585A646D8E7ULL, 0xBE8A491747FF7061ULL, 0x33EB324E94A83EBFULL, 0x17F46590BDD1366DULL, 
            0x11111F2FA487C5B8ULL, 0x569587AC80960DE7ULL, 0x0FE191D5E5C299D1ULL, 0xD2ECF9960406FE07ULL, 
            0x534CE4CFAD299D39ULL, 0x36DACD1E34EF3018ULL, 0x488094E78E73F92CULL, 0x42EBAC5453C7FE63ULL, 
            0x21070E10F2D5BC46ULL, 0x3BEB582D6B97700AULL, 0x68EC200DA6DC7A17ULL, 0x8BB5C6F3C99ADEA1ULL, 
            0xDE9DD8ED4C6C74D1ULL, 0x28AA53E28F3C929BULL, 0x8C64477E3EBFC270ULL, 0x75CB2538F6C26427ULL, 
            0x4CEED5CE416BED2CULL, 0xD21CD4E8CDEA7493ULL, 0xBF4A9FE9D15B4324ULL, 0xE2B2158FCE43566AULL
        },
        {
            0x0117C15F12975007ULL, 0xD87ABA6ACA3D3365ULL, 0xB4AC79931E94A7F7ULL, 0xB80D1EF4EDB4887BULL, 
            0xEC867E9DD477E5B4ULL, 0x1B1A9AFF17410C10ULL, 0x54272C6D90D34F1AULL, 0xE9DB4E6CC5BE4207ULL, 
            0xDD982DBF2C7264F5ULL, 0x90974B23ED0AE20FULL, 0x78A3CCFA8A209848ULL, 0x1FEFC267B3F5847EULL, 
            0xC703FFB92F921EFFULL, 0x5AF01B4694FC29A7ULL, 0xA8AC9EE658EAC348ULL, 0xE016CC1247CED57AULL, 
            0x047487D9173654D7ULL, 0xCA6F70B9C0EF11ADULL, 0xBDD39E6B7AA34AE8ULL, 0x650C9EB794F36597ULL, 
            0xBD91329BFF6AA19FULL, 0x802F5F42189914EDULL, 0x623E40F6DAFDEACFULL, 0x54E2EE9AB0C1B64DULL, 
            0x6ADFCAEED8756498ULL, 0xBF2F4E3E073102E6ULL, 0x7BBB2EDBB94F01C8ULL, 0x59A579E757366BBBULL, 
            0xC83020B244B9FDDBULL, 0x4AEB8DE12C4D8F28ULL, 0x825A01878113D02DULL, 0x9891B76E69BA9377ULL
        },
        {
            0xD5CC8F0D763BD013ULL, 0x22C87FB461C68FA9ULL, 0xE5BE3B6D0772CCB5ULL, 0x796516BDEDA870CEULL, 
            0xB81B7B13003F11FFULL, 0x78461F09E792C0EEULL, 0x81B14FDB397C771EULL, 0x96DD5774C508851FULL, 
            0x96B8939E2A0424B4ULL, 0x5F1BF6B074822E5CULL, 0xE950D46580A63855ULL, 0x76F038A7B6106700ULL, 
            0xB95A0F338BA6E0F5ULL, 0x07E939A5CFBF7059ULL, 0xE9504B0745A9CDBAULL, 0xC1F19CDCB04E6C10ULL, 
            0x00981D8B5ACA242BULL, 0x0F76DFA810BA4B59ULL, 0xA1E50CE3D32A9158ULL, 0xF49F71D0FD9753CCULL, 
            0xD3613482EAAE3898ULL, 0x80449CCEF2925EE2ULL, 0xA573FC57F83BA508ULL, 0xBBDAD4726DEDC8E9ULL, 
            0xF9CA529F8675BE36ULL, 0xD06E5A3228F898EEULL, 0xDA2A2C570F9BA10CULL, 0x1813784EF1D590D1ULL, 
            0x077753217257ABD3ULL, 0xE60387507D83F3AFULL, 0x5E8DEE4E75F7EEFDULL, 0xC20F9D040F1E8F6CULL
        },
        {
            0xCCE4945D8A00B173ULL, 0xB70DA88E1879DBEDULL, 0xBDD5C4E7975B8796ULL, 0x3A5E5E84D7921217ULL, 
            0xF41252A5FB693827ULL, 0xBF889A1FA9638BD2ULL, 0x80390DF5B7D3CB1FULL, 0x7B93869635BB5BEDULL, 
            0x17625382F026F240ULL, 0xD3913C6CC85AFC65ULL, 0x24FFCC0177A6129AULL, 0x8B6B3639C55F2039ULL, 
            0xC50E708B0C3FD08EULL, 0x81B21B9B44D38FFAULL, 0x62051B00FA368157ULL, 0x9AB3C713F2E4842EULL, 
            0xFE04A3CAB8B3A133ULL, 0xE04B0366AB257274ULL, 0xAFD3BBC0DBC78176ULL, 0xE959D80B5E0ECCECULL, 
            0xFBAAD919BC60E0CAULL, 0x7286970806E1D73EULL, 0x9E4253469E257DBAULL, 0x73B14F0AD0C0C353ULL, 
            0x2B3DB71555503349ULL, 0x58184291AF13C0F7ULL, 0x78D168FF78154E9AULL, 0x84AB93EF71B46227ULL, 
            0xF12D7210DA8F5FB6ULL, 0x627D87AE4FFA4C38ULL, 0xA1D23ED21A441E54ULL, 0x3AEACC309F615072ULL
        }
    },
    {
        {
            0x409341FB02E642F9ULL, 0x0ED7B32A6A860A6DULL, 0x36FEB2586DF1B648ULL, 0x16B545A40F267245ULL, 
            0x3B3461171FAD7473ULL, 0xA89F37BD4D911357ULL, 0x93D0350859DFC631ULL, 0xE04770FC44A4C926ULL, 
            0x0AEC5DC8AF224076ULL, 0x0BBA56C68C2F072BULL, 0xF720A1E7E6E19BC4ULL, 0x5B72F393C233D697ULL, 
            0x6A4ACECE5EC3E66FULL, 0xE034A75D6829D8C4ULL, 0x5455B337CC446AECULL, 0x70853D09849161A1ULL, 
            0x6FEDB98D5A51D2A5ULL, 0xB877548CEA8DF278ULL, 0x0CF746BE41D0AB7EULL, 0xB90D845E3DE3DB79ULL, 
            0xB3D756F954D7C6BBULL, 0x80FF3EF88B8A3753ULL, 0x52F0AE4961AB6845ULL, 0x2AD0115FD8C83F44ULL, 
            0x532614024D0C9D33ULL, 0xEBB04B836AB79755ULL, 0xD1A5E4A52D6D8A65ULL, 0xC46A985C4F97636DULL, 
            0xD946E94D4194DEC0ULL, 0xFCA02EB2150CBCAFULL, 0x19E393FC844E44D5ULL, 0x27815325103EF149ULL
        },
        {
            0x14CF9ACA6458F29DULL, 0x121F96FB606BA404ULL, 0xF6E008ABC14CE5EFULL, 0xE4B6AB6BBD3F064AULL, 
            0xE97A9C72FF8A21B5ULL, 0x72761508CBFCD388ULL, 0xAB38D3B22CF5A708ULL, 0x582E48B8E7D95215ULL, 
            0xB4C8E8C930FCA9C8ULL, 0xD69DF135EB75B391ULL, 0x010C430CD193665EULL, 0x39A25581CA63EC90ULL, 
            0x6A3C59E81D51EB8AULL, 0xA688008AB814088FULL, 0x6FF8B7B10952FA7EULL, 0x5D6550949BEA293DULL, 
            0x8D06ABCAE83CDC37ULL, 0x8A234524DC3E6F1DULL, 0x6F375F30393C1DD2ULL, 0x582A849A6C867CB7ULL, 
            0xA9D8C5929A8BC0ECULL, 0x6B0F4AC711C6497AULL, 0x8AC52BFA17BEB03CULL, 0x3F7BFD45FD353A0CULL, 
            0x16910704EC7C1FD1ULL, 0xC905A017E4A7BC3FULL, 0x7CD72369F80CF77EULL, 0x3B31BC4F11FE8684ULL, 
            0x2844DC5AE67AF5CCULL, 0x9D2E496A1717DD52ULL, 0x510D52033553ECA0ULL, 0x6FF1E6AFF287D68CULL
        },
        {
            0x3EAEDA7A030F7026ULL, 0x9CC8E74544A9FF68ULL, 0x5CD87FACF1C58BB3ULL, 0x1955F44528A436DCULL, 
            0xC8CDDD7AD9E90D34ULL, 0xA13EEC3FE3249676ULL, 0xA26A6AD4CBD0D4D2ULL, 0x49AB575D5924682BULL, 
            0x50E8ABAC2B85B1CFULL, 0xED56A31959620058ULL, 0xFDB2FC3CE65F5B1CULL, 0xC5C8D0D51BC35EE9ULL, 
            0xD02DA405BB16A890ULL, 0xC537F302866520F6ULL, 0xEE1AC2BD5CCCE89FULL, 0x067209AAA75FA1D0ULL, 
            0x825EDB5667907F2EULL, 0x478575089346BED8ULL, 0xF08FACDD07B5E11BULL, 0xCB5745AD52895BC2ULL, 
            0x5CB6840E1F07A621ULL, 0xA91516E0AB62CA14ULL, 0x2CFB24D5CBFF23B5ULL, 0x31B5B432931C4767ULL, 
            0xA2E82EEB8CA30028ULL, 0xD12ADD5C3B557819ULL, 0x847ED92396061A18ULL, 0xECCED9EA8363BC0FULL, 
            0x21516F1AFEE8D303ULL, 0x7F8EB810B903FA25ULL, 0xFC4C09E3C5922D19ULL, 0x0FAF92E6866135EEULL
        },
        {
            0x670A69C9A6112716ULL, 0xC92C36920DD69CA4ULL, 0xB211A1FF8F35C31DULL, 0xB62E841B139B023EULL, 
            0xEE356281B09A9DAEULL, 0x161B6417437B435EULL, 0x42643B9E62E17FC9ULL, 0xEF2089C62A9BAF92ULL, 
            0x8FDA3B95EA6690C0ULL, 0x3B856AD1B7319E68ULL, 0x8179CCFC9C611DA7ULL, 0xB3FAF16B0240506EULL, 
            0x23686F83AF90FC46ULL, 0xF7455AD15CB6A145ULL, 0x8C7B238F13ACE725ULL, 0xD14E77BB8F44A71CULL, 
            0xC184DDD3C7DEC85CULL, 0xF6016EE9399D7963ULL, 0x67D7B028C6581909ULL, 0xCC9C68FB7F7457E9ULL, 
            0xD9B805DCF91D1327ULL, 0x3954AF1BE52A6B7AULL, 0x883761510EFA714FULL, 0x89C245F546E4EDA2ULL, 
            0x9199E8F5C5EBEC16ULL, 0x43847CFE09A9065AULL, 0xFD23078AFBD43C76ULL, 0xD566DDD27683D4D5ULL, 
            0x52D17E0F1CA0F46DULL, 0xCF555E752295C0CDULL, 0x74BC611B331C1577ULL, 0x7AE6501C5015C4ECULL
        },
        {
            0xE63800721692CB65ULL, 0xE930D189582565D3ULL, 0x610136FCFD938563ULL, 0x77C53CF0731DC393ULL, 
            0xD6F2F5150B9DF175ULL, 0x89127345B6920055ULL, 0x4034521AAB445D85ULL, 0xC67D12FA19A46C6CULL, 
            0xFE5A316ED35B79D6ULL, 0x185B456511A1564BULL, 0xDA95B1BC296EAB75ULL, 0xC1E493CBDEA3C5A8ULL, 
            0x5F4C15BE4ECA15BEULL, 0xAEA2C1784A1588FFULL, 0xE8685B5FCA1BC011ULL, 0xCFC436DB094CC299ULL, 
            0x37CAD9B5A71072ABULL, 0x6412808A9A2B921DULL, 0xDF0DA6F4B2D6D8D3ULL, 0x329E8F04E851E96EULL, 
            0x4785E237A3E96C90ULL, 0x75604BF1C4069DC6ULL, 0x3578C01ECFCA3A22ULL, 0x8D2569D01D28A605ULL, 
            0x7BA0E4B37F2E8F21ULL, 0x3330666E56023510ULL, 0x5801F1B9CDA048D5ULL, 0x0BAF19581E7328C1ULL, 
            0x634B56FE07C12279ULL, 0x2C34DA93A7C484CCULL, 0xC9171D6C790F6255ULL, 0x18094E44FB491516ULL
        },
        {
            0x763BCEE70FAF90A6ULL, 0x93E0568212D72A24ULL, 0xB5F5879B698815E3ULL, 0x94C5848E0FC6A690ULL, 
            0xE0C34A7B47154334ULL, 0x8EB11B2D82BD889BULL, 0x69F0D6D628D1304BULL, 0x322F9712B30C6C28ULL, 
            0x390049BCD6CEECBBULL, 0xEABDD4076B16D2BDULL, 0xE602974E64456A32ULL, 0xA841D2BBCE0E7548ULL, 
            0x6FD49551ECEDD6B3ULL, 0x537A22C13E82E4C6ULL, 0xCFBD120BFC75FBE5ULL, 0xE4EE7C19548036B0ULL, 
            0xDF5B36716F117D5AULL, 0x2B3BCB4C5FC0C8C8ULL, 0x88DB1BFF7E844267ULL, 0x62F52C993A50601AULL, 
            0xE465ED5EC71CAB68ULL, 0x63AF64BEB2775E7DULL, 0x0E351BD738A69692ULL, 0xFF11A3ACBBC64D13ULL, 
            0xF432AA3625627F17ULL, 0xD5F45674868FD212ULL, 0x4C1329250A3AEEA3ULL, 0x4268FB8E725A708BULL, 
            0x856D65BA337015E2ULL, 0x8C14E510AB4E03E3ULL, 0x61410199A1F6BE32ULL, 0x5A94E63E1A1247D3ULL
        }
    },
    {
        {
            0x6CF84E062BF78FEAULL, 0xD75545FBC04E2C93ULL, 0xBE180A9C789C1F43ULL, 0xE2364FB76B00CB31ULL, 
            0xD39D10123389C7D5ULL, 0x3D1BA6B6295E6619ULL, 0x6870741FF7411446ULL, 0x48111C414146E971ULL, 
            0x502B5FFE2C9280E4ULL, 0x2F1E8ED463C06C29ULL, 0x208DF6B7A94E3D8CULL, 0xFF525C9A540BE46AULL, 
            0x513D291820EDA8D9ULL, 0x6ED4121E45E8C286ULL, 0x4CB9944D2E689B5DULL, 0x7B76DA27C1217FFDULL, 
            0xF2D0914A23C9BD27ULL, 0x9BB5C0EAA359CEE1ULL, 0xA07BB5B4972F7EDDULL, 0x6D25BC37D40FD167ULL, 
            0x5F40238C17CB47C4ULL, 0xB81D68BFC9C485E9ULL, 0xA6459AAF365DA0EEULL, 0x6B35361BEFF05117ULL, 
            0x91F65175C57F3F86ULL, 0x4A52955A5123110EULL, 0xBE6ED3D4C04F6C17ULL, 0xD8C8DE530082EE1BULL, 
            0x1D0E32D1AA1B34ECULL, 0x8CD46EAE1B759F43ULL, 0x805D89E5FD336BFEULL, 0x8AA5E8904B26B213ULL
        },
        {
            0x3C6C635B30556633ULL, 0xA5B4AB31D7A5B53AULL, 0x069FDF73E27A2193ULL, 0xB79AA9255B665379ULL, 
            0xDDE5C1325C45A75DULL, 0x564DB99FD125BA18ULL, 0x71B41469CAE457C7ULL, 0x769EBFA6DB1AB1BBULL, 
            0xC62B9E8C48DB1C16ULL, 0x5B69A71D1E385A23ULL, 0x79C791A3C3F9271EULL, 0x9A411F63BAD0729EULL, 
            0x8B8B6214791A0BDEULL, 0xE1031A162FDA9A10ULL, 0xFBC24FDB75A516E0ULL, 0x3D2A140A9707BC9AULL, 
            0x747DA9584445EA7AULL, 0xC08AC7D5A3ED1C0DULL, 0xC8D0355886B16E87ULL, 0x5FF2E72F1AD303C5ULL, 
            0xFC2E5D515631F165ULL, 0x644E6A2D1600ACACULL, 0x6D9542BF73822C97ULL, 0x6CA53CE9C20EE407ULL, 
            0x29F955983EE721B1ULL, 0xFC0838E59F31B54DULL, 0x90BAAC80444036DFULL, 0x7C9F439B3328D295ULL, 
            0xEE3D60B7A2B483CAULL, 0xF4572559D6E479C6ULL, 0xCD2D4F8F06935AB6ULL, 0x4380345789E4F735ULL
        },
        {
            0x98CE0B0CCEE72AF2ULL, 0x8BB33DCE60BE6C3BULL, 0x8EE8CDE277C4B1EFULL, 0x493F5A6078EACAB8ULL, 
            0x8D9FF52AD8D941C8ULL, 0x8C61648DC162222AULL, 0xBFB0E94CCE4BF9D7ULL, 0x73CAB39DAAB52C26ULL, 
            0x298E96A0BA7BB20CULL, 0xE9A81341ED929639ULL, 0x487E231FAC8C0532ULL, 0x1650E66631FD9B7CULL, 
            0x6AF1CE6763B28BD1ULL, 0x74A798EF606DDA19ULL, 0x919BCCE0D2B7ADFBULL, 0x6D4331347FB4CEA9ULL, 
            0xA78825B8633334F0ULL, 0x3B264D67B2EDD5EEULL, 0x1CC5A093BF38AFC6ULL, 0x1E330B541988A8F5ULL, 
            0x43E6957BB5BCBABBULL, 0xAB18116B7257E6A5ULL, 0x318BCE8A7389CEC4ULL, 0x675BB9ED35858F6BULL, 
            0xF27956AADAE9912BULL, 0x58840FC40EE764A0ULL, 0x3559971834FC034BULL, 0x7A39A94A6A1CE610ULL, 
            0x25161064AA8E467BULL, 0x7AD456699D322D91ULL, 0xCCEF483A3B3BBE0CULL, 0x49C8E73640DA8046ULL
        },
        {
            0x1AC8B627D4DBD77BULL, 0x54D47AEE626CDFC6ULL, 0x1472D145C2E94457ULL, 0x8783FB95312B8D21ULL, 
            0xC42B6FF8B78B865EULL, 0x6D70B7350FF38909ULL, 0x475377D0226148D3ULL, 0xB96D40E132CEF9E1ULL, 
            0x4D7DBDB7931BA779ULL, 0x0CD9AD811C114BEEULL, 0xF614450F5A321F75ULL, 0x0401DC165970CE05ULL, 
            0x90BA92495469E714ULL, 0x991C3323061702D3ULL, 0x925AEB7F6F926F06ULL, 0x929811F65DCC7E54ULL, 
            0x808DAC1732AC9920ULL, 0x3AB87B63986260FDULL, 0x18F924BA234CF1C9ULL, 0xE52ECB495EAAF4E2ULL, 
            0x14F78ED002F2DF46ULL, 0x197D8DCAE4AE0AB6ULL, 0x30B62448F9CB71F3ULL, 0x4D1E548BB803E7CFULL, 
            0x2DF425598C3FCDA4ULL, 0x839E69879A3F6941ULL, 0xBFE9514B82C9F431ULL, 0x779D8ED1665DBBE5ULL, 
            0x0E83036C05768FF4ULL, 0xE285135DAAADCC40ULL, 0x04D330D4EEEA067EULL, 0x74B4906925D70199ULL
        },
        {
            0x91D50D502773AF41ULL, 0xB6429B7533A893E7ULL, 0xF91FC63654DA4C98ULL, 0x43D80AB18632AF75ULL, 
            0x9119003B3A427675ULL, 0x3FBA1CFE486DA669ULL, 0x7AE963006B63C378ULL, 0x7271B39EC3616B54ULL, 
            0xCE577EFC1AD91103ULL, 0xDAFD87999CDC23CAULL, 0x0D8B34580996687BULL, 0x3CFD030A54FBF447ULL, 
            0xE80CE7B0AEAE2293ULL, 0x2AC453F48066F3AAULL, 0x3B7EE4406B2132F9ULL, 0xC62B68386FBB78EAULL, 
            0x9259E42BEBE72101ULL, 0x4F3DDBA416913AA2ULL, 0x6DB8755D125A56D7ULL, 0x24771202487919D1ULL, 
            0xA1AA052144E28B63ULL, 0xA1F0ABB543C0142CULL, 0xB7BE2C7EFF64D815ULL, 0xDCAFC40E2A9BADE7ULL, 
            0x15C160B6BB789933ULL, 0x9FC85F342D74303DULL, 0xE85EAB0A3AEBBE21ULL, 0x28C28523CE897D0BULL, 
            0xE0A2AD09C16B700FULL, 0xC4AD97742FB5A1F9ULL, 0x1889EB2262306E3AULL, 0x5477AE1758FE9261ULL
        },
        {
            0xC510726671117DDAULL, 0xC4F379CEFB2C5287ULL, 0x932B52B8A309B95CULL, 0x6466FDB03D94C05CULL, 
            0xA863BEB697005342ULL, 0xB2F7C650B79631E8ULL, 0x3B85694DBEF60CAEULL, 0x2B3E4C83957CC561ULL, 
            0x2AC69FA14A0B0271ULL, 0x408B687139523BE8ULL, 0xD9416A465A88526BULL, 0x2B91BFC09FFEAB62ULL, 
            0x798892BB34F7854BULL, 0x77C44141CA9381FDULL, 0x192BD21537E023A5ULL, 0xF8C5E2D7F65674C6ULL, 
            0x0777054563B7DDA8ULL, 0x4B2D6DDF355D8F14ULL, 0x0C373E4E6B21DA43ULL, 0x1F8CCAC94C881F3DULL, 
            0x2FDB018B5F170F74ULL, 0x95D1D1BC972DA79BULL, 0x1CC88ADBFFF3C990ULL, 0x7887B7FED54E820CULL, 
            0xF8650D25858F9FA5ULL, 0xB29BD85DF717B5DAULL, 0x383BCED237F07D93ULL, 0xFB617A641B8F0D2AULL, 
            0x65057F8C73EBC94CULL, 0x54EC7BDB8305F480ULL, 0x201239B0F402D6AFULL, 0xA50E26502F51476EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kPhaseAConstants = {
    0x5227099A20E00840ULL,
    0xEA5B135D3CB741FBULL,
    0x222A8C3EF0849A46ULL,
    0x5227099A20E00840ULL,
    0xEA5B135D3CB741FBULL,
    0x222A8C3EF0849A46ULL,
    0x40D87A4D5610648FULL,
    0x7779F24E18F0BA39ULL,
    0x2E,
    0x16,
    0xEE,
    0x48,
    0x70,
    0x7F,
    0x5A,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Alnitak::kPhaseBSalts = {
    {
        {
            0x6143B652E3B79111ULL, 0x1840B703DA984721ULL, 0x99960D85FD43D738ULL, 0x2A3AC0107E4E99F7ULL, 
            0x25D1D7040F3F2CF9ULL, 0xE89770711BB502CCULL, 0x83D9B0FAE5DB6236ULL, 0x7FCAE9E1AED2BB76ULL, 
            0x0B52A0EE689FEF99ULL, 0x915DCEB77D52CCFCULL, 0xF3FAE35CB2076ED0ULL, 0x9FC097AB662A2F7AULL, 
            0xF35CFE318A27BBAFULL, 0x08934C53668CBBD5ULL, 0x87606E162B952173ULL, 0xB1312CF3AC59B4BDULL, 
            0x4E71EFA262419DF3ULL, 0x310ED9AFB6EACDC1ULL, 0xA892A57D083EB4EFULL, 0x8231C7D9DB4333A4ULL, 
            0xCEF802D958D72669ULL, 0x9E26ADCF509259BBULL, 0x6F959A0EBA9D6E60ULL, 0x40FD9381AB114580ULL, 
            0xDCE6E4F6CE4E0EE6ULL, 0xD04A0849DCF39CE2ULL, 0x9D3CFAE065D925C8ULL, 0x802EFFCE56CA65F4ULL, 
            0x1F5EBFD13E9A39FBULL, 0xCD1A2D410C17F540ULL, 0xDC517053D8D491BFULL, 0xAF43E94900682C7EULL
        },
        {
            0x1E478E2FAA10B521ULL, 0x9E2DBA8E6A263098ULL, 0x280A674E11F30F70ULL, 0x1C9C482968A18152ULL, 
            0x5558F888CE8751E8ULL, 0xB9AAF3459F0818EEULL, 0x164BF51BEA7F7312ULL, 0xE27A1719F9EF2A32ULL, 
            0xB3B0200FE9E95FF0ULL, 0x73239A0FECDB7116ULL, 0xCA13AB197968A890ULL, 0x67A8D763B66AC555ULL, 
            0x7E5642EF7737C185ULL, 0x4AB57C222ED72EC5ULL, 0x78A51ADFDCFA1392ULL, 0xCCD8EDE4A67B2966ULL, 
            0x2FB2328E0931EBC1ULL, 0xBDC14EB3DAA295C7ULL, 0x25A0F8D82D5543EEULL, 0xD12FECE5205271C1ULL, 
            0x4FFAE90E082A7117ULL, 0x85E6E18B80CBA371ULL, 0x910EED59BC779E3EULL, 0xB12D6BDEE4394964ULL, 
            0x7551F28ACD359D72ULL, 0xD5846CE0750A1F0FULL, 0x2AF993D4A279EB8FULL, 0xA0759F39B3EBFD1AULL, 
            0x3CB226946AC3DB3CULL, 0xE59FF30CC353A207ULL, 0xB02DE02C21D9AE6AULL, 0x457CB5B6BC9E2762ULL
        },
        {
            0x8BEC79DEFB1DDAAAULL, 0xE154554BF7CAF634ULL, 0x880FF31A52CC0BBAULL, 0xC5381D9FE1295C48ULL, 
            0x539F5449B9AC3C3EULL, 0x6C583DE3B6281F38ULL, 0xA9E656C980A3948EULL, 0x551C5793E5CE765CULL, 
            0x41A4A8F67ED88052ULL, 0xE9FAB3BD19F9C733ULL, 0x3534853A47026EADULL, 0x063787E023FD035BULL, 
            0x0D9041623E0BDECFULL, 0xA120A681474A5B8AULL, 0x62BDB4D9A68EE3E9ULL, 0xB27D88017292F409ULL, 
            0x04F6FA05DE81B85FULL, 0x8B94C080BA89D544ULL, 0x5F4FABA88977DF87ULL, 0x257F076E58D0CAE4ULL, 
            0xFC083BB57EF6A827ULL, 0x3E3D10F4D7DD28A0ULL, 0x1324D9F60E3E1947ULL, 0xDAC1294E5F3F87E4ULL, 
            0xB24AEFB19D9039BFULL, 0x96A13AEB40BEBFEAULL, 0xB3CDBB1700130F39ULL, 0x5882F332ECA1C495ULL, 
            0x4FDB511B2C520422ULL, 0x44DBEC66B851844FULL, 0x80A93F2C3991D802ULL, 0x70F9748FAE04EFF4ULL
        },
        {
            0xCD363A75B7EB9D1AULL, 0x4655332900B6967BULL, 0x67C3A67C1268EB84ULL, 0x899DE7D210FDAD7BULL, 
            0x9132DF03693CCA85ULL, 0x1B72527E470EC942ULL, 0xD0BE9D31412E6FF5ULL, 0xCCA5B6AFF1BE695FULL, 
            0x967913A5073B3698ULL, 0x34B76F2500F92E93ULL, 0x1C502F321F5A4AD6ULL, 0xA263E53E4A4205C2ULL, 
            0xCFE877EC6FA37A4AULL, 0xC87A4EF0E7690821ULL, 0x64BB9874A43ACFCCULL, 0x060A084A8CB538A0ULL, 
            0xE71CBF31C5764CD3ULL, 0xB3A1460DF9FD8516ULL, 0xD6BB3D924F005EDFULL, 0xB45ED09FD4EFAD1DULL, 
            0xA57BB0ED81516124ULL, 0xCA4DA606AD6AECCAULL, 0x170A2A832F5253A7ULL, 0x4411442F2DCC9291ULL, 
            0x2B67684D6039F29CULL, 0xB0C2909F9B61613BULL, 0xE59B00F991B37F45ULL, 0x5EEF814DEE4B37DEULL, 
            0xB3A319BBFCC0790FULL, 0xC7C22A7E2940072EULL, 0x672287985FD84005ULL, 0x0F411A8FA10B61B6ULL
        },
        {
            0x79C4ECBA7222E206ULL, 0xC95A104C5C39F116ULL, 0x913DEE57F2A8DF63ULL, 0x108E022912BBEBE2ULL, 
            0x28B217C9393721A1ULL, 0x9F54B9EF8FD660B8ULL, 0x86F463CBE90863CFULL, 0x6C43A0BA3B0C7EC8ULL, 
            0xB687D3150D683367ULL, 0x0210CE74EFA2934FULL, 0x509CD6327380CF85ULL, 0xC55BCA5BDBC633FFULL, 
            0xA143CA52A8FDD384ULL, 0xD005A5B1507FF676ULL, 0x2E9A49A2AC3A03F3ULL, 0xBD6D472358DDDF6CULL, 
            0x1983FC9C41DB4217ULL, 0x819B0B7723FACDBCULL, 0x83DD85847DC05600ULL, 0xEFDDDE1371AE5887ULL, 
            0x5A8F3A336255A095ULL, 0x963D359F87748DA6ULL, 0xD564EDB66909A61AULL, 0x3AB92511AF99D5B1ULL, 
            0x8F3E8BAE3EE4E77BULL, 0x8CD800CE88973065ULL, 0xF4BE3B152BF79346ULL, 0xCCF0D0DA8132DA8CULL, 
            0x40220EF095BD58D4ULL, 0x57BBFEF9C462A328ULL, 0xE0A064CE9AFE3594ULL, 0x190603077A6C74B0ULL
        },
        {
            0xE6B42CD93A64479CULL, 0x894042C19F44F3CDULL, 0x3ABB56FAEDE7C5C4ULL, 0x0C8295E1FD0F7F55ULL, 
            0x44BF569CA0B885FBULL, 0x298D5925B1DA1BC4ULL, 0x149D89745F7D60FBULL, 0xED82856C10D5BB1DULL, 
            0x77ED8F2FDF89C648ULL, 0x7845395C5BBD8D25ULL, 0xDEE54E9B3DB0924CULL, 0x9CA702242E45C314ULL, 
            0x7C877D222BC71CD1ULL, 0x98B24C83E5AFB256ULL, 0x17D91BEF94E51B1FULL, 0x3F7675F2C691A5B9ULL, 
            0x03E53B59CD1BF0C3ULL, 0x1CE5A50348A303CDULL, 0x47A312C14525565FULL, 0x1132B9EFAD513A34ULL, 
            0x6FCC7BD8DC184F23ULL, 0xFAF0B16AE79DC813ULL, 0xAA20E632E4F34272ULL, 0x6B6C1F9A5730C728ULL, 
            0x51B3C7053B8BF2DAULL, 0x5EFC3DB94747AC35ULL, 0x0B0445F14B5B37DAULL, 0x088B7E8D0B5DAAE8ULL, 
            0x0126CBCF5DA6B1ECULL, 0xFF7C21D196C1E6E3ULL, 0xC49AE8C2E6C019E9ULL, 0xE10A2E451C0B6B93ULL
        }
    },
    {
        {
            0x85290F5584432DFDULL, 0x844CFB0B5C7A25C5ULL, 0xAB0761C53D740B91ULL, 0x73219C193B58A1E7ULL, 
            0x3EC6A5D34C4DBBE4ULL, 0xAC1D34CB7D5CC84BULL, 0x76D7D8C83D066E98ULL, 0x16FA456F56DBDFA6ULL, 
            0x61B863722F5DFBC8ULL, 0x943FFA12C05637ADULL, 0xCEB660C2BA552535ULL, 0x42F96DF30AFAA9DDULL, 
            0x19DA6F8772AB0328ULL, 0x99B355D62B73481CULL, 0xB939D3CF565FB461ULL, 0x0F74623D4E540644ULL, 
            0x659C7FDF7A328621ULL, 0x277A0BFDCCD71669ULL, 0x8A47913FC9A2D1D5ULL, 0x37FC58DFD621EDD4ULL, 
            0x0858098B32D12DA0ULL, 0x1D28E5299BF0E1ADULL, 0x286301B284661780ULL, 0x942EFF10A80B0952ULL, 
            0x1EB16B46ECE27ADEULL, 0xE38B30EDE99E7CAEULL, 0x755CA474D58107DAULL, 0x3332973294FCA5F6ULL, 
            0x780170B1A0CFFFE0ULL, 0x0B3D76F5811F7775ULL, 0x90CEA6E233088C77ULL, 0x0FEA62932D38CB5AULL
        },
        {
            0x8A4F0102D94D0314ULL, 0xDFAB19B5F53FBD8EULL, 0x71A5107A03046585ULL, 0x25A9621261722D46ULL, 
            0xCE1269EF58761252ULL, 0xE4B75FFC219EDC72ULL, 0xC74639D09F36D240ULL, 0x561127DC10521272ULL, 
            0xCDA95E506ADDF89CULL, 0x110DAA4194E1D0A0ULL, 0x625960B34E33AC46ULL, 0x10F8D7C888D508CBULL, 
            0xEC3A5D19CC4669FAULL, 0xA9FACC5F8C0FC810ULL, 0x22390E61348BDFD8ULL, 0xA033D95307E45041ULL, 
            0x2FDE39A47FCD4A07ULL, 0xD7E38956F5C30C97ULL, 0x90D1530E4767C011ULL, 0xF4F71B888AE20CBFULL, 
            0x0F7F524610342CCCULL, 0x94B98343F1969010ULL, 0x1E32126B0330788FULL, 0x38C48173EB985413ULL, 
            0x6E6BD60AC04C17C1ULL, 0x2F186C9C6E3A8A3FULL, 0xF34F04447E57C620ULL, 0xD362419BF7EF3E9BULL, 
            0xBBFD359FFB6C19F9ULL, 0x0EB1590485AF8729ULL, 0xDA78087F6E4DE32AULL, 0x4C0E3DFCB167EEE0ULL
        },
        {
            0xFE87A0D940C327EFULL, 0x64FBF9F6F06411D2ULL, 0x2AF518B4619D611DULL, 0x418D1E04A727828FULL, 
            0x1F44F7F684F91255ULL, 0x34966A25014FD21FULL, 0x48DB22F3EE12B2FDULL, 0x3945FFF4F2082EE2ULL, 
            0x70D4C2FC20EFBDA0ULL, 0x02E438E9E8AEC219ULL, 0xC0A26CFE6CAA8EB4ULL, 0xED51E174C95428D3ULL, 
            0x3B6EC255AEA55903ULL, 0x10E7BC555A9CA46DULL, 0xE43D598BBFAD79F7ULL, 0xD40023064C6926DFULL, 
            0x88561FCBB90C0A5BULL, 0xF28A69EAA3DDBE60ULL, 0x26E2F62E1F2113D8ULL, 0xFCBBB9AEE4C485F2ULL, 
            0xE869CD3DD8BE7094ULL, 0x8ED70B3FC171588AULL, 0xA77531E7F3ECE508ULL, 0x5B4264AE938AD02AULL, 
            0x9453A42D12D5461FULL, 0x72E75B4351B1227DULL, 0x038BF9452807B021ULL, 0x962F3E3433B8D589ULL, 
            0xACA37AFB77B7EB42ULL, 0x68C72AC495CC130FULL, 0xE77BC5FC065EADCCULL, 0xCCDB503DD51C33F6ULL
        },
        {
            0xD9C68A2FB690DE18ULL, 0x7D5F8AAFB6F6361AULL, 0x8927F14DF2711078ULL, 0xAD2845AE1F7937BCULL, 
            0x705EBB51481B328FULL, 0xA58391668025CDDEULL, 0x9E5D27D3D4B0A26CULL, 0x857DFC8C0E1CC976ULL, 
            0x2EFD06E41BF481E0ULL, 0x34ADA69346819DC9ULL, 0xFB1ACB9B8AE12D1FULL, 0xC14C33456316F328ULL, 
            0xCDD0725610EA9286ULL, 0xF7A864B2DCB24F52ULL, 0x2D83A9B188A4DF5BULL, 0x6608CD8312658C3EULL, 
            0xCA7F24F0FFA70CB4ULL, 0x9DA34937FE4FC26AULL, 0xF7C8E533867BF51EULL, 0x1619C59067020094ULL, 
            0x6DB2065BE46F4D31ULL, 0x12367766B5DF97C9ULL, 0xBFC6933C3867ABBEULL, 0xDF1B06E331FD41A0ULL, 
            0xF98A67AC29E2B2F6ULL, 0x108C8AAC5C9942E5ULL, 0x314167F7460D74C7ULL, 0xA724A914D18BA1C6ULL, 
            0x9D021236F372F4DAULL, 0x0EC23C9E09F35B64ULL, 0x808463C961141B6CULL, 0xC8DF9D6282A0BC8DULL
        },
        {
            0xF4A9FD562FE69C36ULL, 0xAD847CA64D99C0B8ULL, 0x72447A17F0AE1FF7ULL, 0xAF107392A1F98D0CULL, 
            0xD5A77091321C3024ULL, 0x27C0547E434AFCB4ULL, 0xFD55DFE906903DC6ULL, 0xFE68EC03E1A8FAEDULL, 
            0xF48850C8E7C270E2ULL, 0x786544C904AD4891ULL, 0x350641F0231D3E86ULL, 0x3E38B1D9B4D99ECCULL, 
            0xD613278204595716ULL, 0x9BEC2E90C62829F0ULL, 0x428C7BD0ABF8092DULL, 0xA6CB27B21A29ECAEULL, 
            0xAE073707E21BFEF3ULL, 0x2E3A13F9D89AD657ULL, 0x9055ACEE1D2250E3ULL, 0x9EEF8829E30B5356ULL, 
            0x532B8E9BB2C51091ULL, 0xF432C8D95C5A54CCULL, 0x76103DC8D567071FULL, 0xA38ABD406BB4D139ULL, 
            0x8505CD62C0C954ABULL, 0x0F31CDDF5E3C9FDBULL, 0x6B3CA09AD64A255FULL, 0x5F8E6FBE19EBC98CULL, 
            0xC04679866F949F2CULL, 0x12B025CC870071E2ULL, 0xE773AFF6B7810FEAULL, 0x0C8312C02997E0AAULL
        },
        {
            0x4FD5D1AF5B96F0A6ULL, 0x0865928F2FD03A86ULL, 0x089B935188CF944CULL, 0xCD9C19C5DE88A853ULL, 
            0xDBE2114A1936F3FBULL, 0xEA296AFF7B6AD839ULL, 0x418B6740A1EA59FCULL, 0xF6F1D6C6EE534FC4ULL, 
            0xFF10C9240ED5F8CDULL, 0xD73332EC4445FEA9ULL, 0xCBB412FEA3BD06D5ULL, 0x8544F207FBFBF69BULL, 
            0xEA3C01F81466E72BULL, 0x251CB36BA3B79B27ULL, 0x526FDF89A330D450ULL, 0xEF6F3C0ADA36D70DULL, 
            0x546D8D4CE22C04F2ULL, 0xCCE58586031B1DDAULL, 0x345BE0A33B6F67C6ULL, 0x987EA871C453AE67ULL, 
            0x6F0066F44C721565ULL, 0xD0ACE94CE4D1D338ULL, 0x9809424E9E0BB838ULL, 0xFCEB42354DB52542ULL, 
            0xA8AC42F46C15C203ULL, 0x78A051844643A46EULL, 0xBB0CC5FDFFAD2A89ULL, 0x1385165BEA4BE828ULL, 
            0x248BDDA938EEAB0BULL, 0x62F8F7C74E4D0F63ULL, 0x92FD04C7FD5102CAULL, 0x4714403B61F1DBE8ULL
        }
    },
    {
        {
            0x615BD618F9494944ULL, 0x12E34EA9EA689953ULL, 0x7B284C0695508603ULL, 0x1C382742EB31D3A9ULL, 
            0xAE942060CB305FB3ULL, 0xE73D6BA3099DF3E4ULL, 0x94883B27C7C04317ULL, 0xA709C0FD0FC58FF0ULL, 
            0x5CA9F2736DD0F347ULL, 0xD0B66F72C03949CFULL, 0xEBF13B96BD68C42AULL, 0x44BA25E2080E7E83ULL, 
            0x8F4E8FA68E0BFD9DULL, 0x740F87917E3D7439ULL, 0xD17A9DD1264EC2B9ULL, 0x805E68EE25772F39ULL, 
            0x37F3EDE66C4EE5ACULL, 0xF460D1A2CF9FA0FCULL, 0x07FCA2EC453C0484ULL, 0xD1585CC1F972E26CULL, 
            0x83869C01F13FFA08ULL, 0x27F68BC0AEB4D775ULL, 0x73C9C9B46D875FB7ULL, 0x800C2A252953E091ULL, 
            0x3894BF729E9AC9D9ULL, 0xEF208A497957CC24ULL, 0x668605234668325CULL, 0xCCD61122186610DBULL, 
            0x2BE008B72EFCD9D6ULL, 0x5D705FFF59A74E00ULL, 0xA4D704EC807C90E1ULL, 0xE864DDEC9636E8C3ULL
        },
        {
            0x4FE6935FAD810E99ULL, 0xA65377D28E3E3B16ULL, 0x21EF60125283F495ULL, 0x50551B4B54EFE733ULL, 
            0xE2FECBF1EF7BEC8EULL, 0xDC63CAB51EA989CBULL, 0xC6DA725A81C46AA0ULL, 0x9DFA4A200EB31154ULL, 
            0x203FC9E6766F75B0ULL, 0x19CE1239CC9C677BULL, 0x009E12D325F9481BULL, 0xDD087B6A0BE8C5B8ULL, 
            0xED83AB90492CCB04ULL, 0x4C77FAF28FD6FB3DULL, 0xD19BD9CEFA4CF1E9ULL, 0x0AD1202079B6A2CEULL, 
            0x0E177DDC14B186C9ULL, 0x23EA46B84DB6CB4BULL, 0x831C85C4B769919EULL, 0x86B053B650D94051ULL, 
            0x81C6F33266A12981ULL, 0xB3605C8DA3CA77ECULL, 0xEC79822D630D36FAULL, 0x825754D57CCB4A8AULL, 
            0x62461D26858A5F55ULL, 0x817F79DAAD6BE4FFULL, 0xE028470AAAE6568BULL, 0x02557D425DA5462FULL, 
            0x1EDEA0CD9309A326ULL, 0xACEB5B030AC7E5E3ULL, 0xF4743902B0DCBD50ULL, 0xFF01F1A4FAD96FA6ULL
        },
        {
            0x9B203D1EFFDD136BULL, 0x3E949AA29A7FD959ULL, 0x014D18D1F3B4B959ULL, 0x4BB3286D48FFDBBAULL, 
            0xF4DE4FF575CD0C61ULL, 0x0D94BD23B3EEB4EBULL, 0x3117FF40E47A5CB0ULL, 0x3E2D0B08EE0ABBBAULL, 
            0x65AB40579329F018ULL, 0x261BAF46B36D0194ULL, 0x0E955FDFF96CB6E5ULL, 0xD279F31ED8CA6176ULL, 
            0x368C919C90FE2265ULL, 0x0180D95468E10E98ULL, 0x5D941B52AC48B467ULL, 0x8D6F28A42DFD7565ULL, 
            0xA8ACDC0A2EDCD6AFULL, 0xF58B5F965C3D4873ULL, 0x9C256B0FB657E765ULL, 0x624BA9C7AA7ED886ULL, 
            0x7B13FEAC0A4ABDA0ULL, 0x6C10AF50712056F0ULL, 0x5B82C908A577BB3DULL, 0xA07392CAF173B02CULL, 
            0x8F1ADF8BC1BC21C5ULL, 0x2D70822F0C2051C1ULL, 0x3D241319289A1E82ULL, 0x8716FDB71113CB81ULL, 
            0x4ED9A798D05FEAF9ULL, 0x1C85BED39A3AC9F2ULL, 0x6CEC8D41E9E301F3ULL, 0x915A5CAB581B16CCULL
        },
        {
            0xA741599311175C30ULL, 0xCE9BF0267F0D6C03ULL, 0x98B2D227BB79B367ULL, 0x7D25293B5F6BA5CAULL, 
            0xDD36EFECA4609208ULL, 0x9CE5E3FD80E55E49ULL, 0xD115B7E6E1DE4E44ULL, 0x8EB708DA1AB94821ULL, 
            0xA3BB325E66865F02ULL, 0x550B73F4EE46D91CULL, 0x7145DC90AD1545F4ULL, 0x3193C0AA23C24F6AULL, 
            0x863D08D5895B2B15ULL, 0x3C71894B49BC5C2FULL, 0x3C4C3B23FCCE4804ULL, 0x5C5D41B72179F636ULL, 
            0xBA9C144389EB7C61ULL, 0x45569502D2B2DAFCULL, 0x1A159B421B9D4DFEULL, 0x9171999F33894453ULL, 
            0x5E0F1A3EA213FCC7ULL, 0xA054E3DD88E8D9B4ULL, 0x42B67DCF174AF5F9ULL, 0x6F6598B49E248388ULL, 
            0x772CF6A2F0BEE8ECULL, 0x659BFC24595982A6ULL, 0x4911DB67F3C5C693ULL, 0x2B19D05E12965784ULL, 
            0x8A4FE3932439F3DBULL, 0xC8A99A2066413A44ULL, 0xBC0E263563066DBCULL, 0x50458DECC81803CAULL
        },
        {
            0xA4C58AF935107D58ULL, 0x4E8678F9FF78FA3BULL, 0xE271378A9AE40D72ULL, 0xD354C7D7B3CF0223ULL, 
            0x22AFA8FC3038C19FULL, 0x1C72DEF292B1C848ULL, 0x7EF919584ACE312DULL, 0x4395C0C485D8A700ULL, 
            0x7AA6B95FD18AC28CULL, 0x8ED186559C0C7CD2ULL, 0x1DF343B2EDA53CAAULL, 0x75207EE486D5949CULL, 
            0x96FD888E19570FF9ULL, 0x3C95ACB477C4F42BULL, 0x77EF910D3ED4BE57ULL, 0x1E3ADFD24290C63AULL, 
            0x41B168937FFF1E6FULL, 0x4872A3CAF11638AAULL, 0x5F2C574D6FAF2901ULL, 0xAFBCE4AAAB663731ULL, 
            0xF48544E68831833CULL, 0x3742341D3E3DC106ULL, 0x9FBBA02223D41534ULL, 0x931B361FB6066E67ULL, 
            0xADCA41B9ABFBD630ULL, 0xC6A504937C947282ULL, 0x9BCB14BB7988A6DEULL, 0x826620EDA15D740BULL, 
            0xFB0C1AEF096DFAD2ULL, 0x2FE39BB896CFB553ULL, 0x91CE3FAA862B7DB4ULL, 0x027719C3A9F759CFULL
        },
        {
            0x3280F6E5A53E00D9ULL, 0x3E02F23D821FD13CULL, 0x1FFC6D9F4021FB8CULL, 0xADFE830C80154FDBULL, 
            0x23E9CCBD5DB2CA54ULL, 0x6606E03312BD31B6ULL, 0xFBFE4993394EF5ECULL, 0x185CB429B0879A6EULL, 
            0x7ADF67DFA48AB02AULL, 0xF4DD9803B345F2CBULL, 0xCC6EB8161FCD1721ULL, 0x4240592A4815B480ULL, 
            0x449348D048EE6F13ULL, 0x6519CACF3140E12EULL, 0x872C6BE5EAA6CD94ULL, 0xE9B2207422F74362ULL, 
            0xDABE462E84058BADULL, 0xB82137E76DEE763CULL, 0x49E74B47DB76D022ULL, 0x916631D4A2802404ULL, 
            0xB4A2AA59D5D38F20ULL, 0x26F38A3D85506D92ULL, 0x9D1A5A69FFE61C7EULL, 0x76BF1210C310385FULL, 
            0xEC8866183A074EDAULL, 0xF3FD7CEF05D1B971ULL, 0x86634B463AA36550ULL, 0x3C19EAFFDD9163AAULL, 
            0x613AE37BD004E0E8ULL, 0x93B2551B1FFBD4ACULL, 0x42ADBAA0392E70F0ULL, 0xAFA491BF522FDA8AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kPhaseBConstants = {
    0x6B274E752B0557EBULL,
    0xCCB81AFD8198CD6DULL,
    0x424C67B9CAC21874ULL,
    0x6B274E752B0557EBULL,
    0xCCB81AFD8198CD6DULL,
    0x424C67B9CAC21874ULL,
    0x941C4849F9B7D039ULL,
    0x20FE37705A0E19E7ULL,
    0x46,
    0x6A,
    0xCD,
    0x50,
    0xD5,
    0xCA,
    0xCA,
    0xD9
};

const TwistDomainSaltSet TwistExpander_Alnitak::kPhaseCSalts = {
    {
        {
            0xF106C21297B5217CULL, 0xF19C3C1FB023BC01ULL, 0x46A6FF17E3062559ULL, 0x2928BF47ABF85944ULL, 
            0xD23FE14E7B8D7C6BULL, 0xDEB2CAC201D92840ULL, 0x5323B4BC272FEE9AULL, 0xB6C2092CA4C22943ULL, 
            0xE7A400361752E114ULL, 0x925BA1016AA13039ULL, 0xF732A8580C138601ULL, 0x44CEECB6B8287FF7ULL, 
            0x48066F145541FEF5ULL, 0x442E77460B45B0CEULL, 0xB32D3D6E3EF9F78BULL, 0xD243FB28F70460F9ULL, 
            0x2632C88E39D88AEEULL, 0xB2F49E20C9ADDCBDULL, 0x61D85297802B8DFDULL, 0x5AD1CF3E4A0BF398ULL, 
            0x35DE43D071DC6698ULL, 0xE70A4C797194B789ULL, 0x74C8F357809926BCULL, 0x68A05D7CC9540B30ULL, 
            0x541786E0929EE580ULL, 0x09108110E0F7FA27ULL, 0x034E1D901DB3416FULL, 0xA98D279EA27DE62CULL, 
            0xA58F8F5C693E0F20ULL, 0xA3526D38275A1196ULL, 0xD915B9E020A90014ULL, 0xB3DD9ADE75B4386BULL
        },
        {
            0x88C44503433BF345ULL, 0x650A0B277646E8E0ULL, 0xFE09005FCD4A910EULL, 0x819E00B666201D8AULL, 
            0xA4D0CB942674E776ULL, 0xDEC0C8657192D756ULL, 0xD40E83499366BEF1ULL, 0x4FB9248241AFFCB8ULL, 
            0xA818999FC4E50BE7ULL, 0xA52A8827496673D3ULL, 0x183302BBA3B329E7ULL, 0x1515990AC92C6ED7ULL, 
            0xEB135FC41EEFC5A3ULL, 0xD2E8A9C173E966B7ULL, 0x0D01941E1AE580B3ULL, 0xD7567CDFB133430DULL, 
            0xCFFD8BC4872C8E9EULL, 0x358E7F10B098C8A3ULL, 0xFC7891D0B5CB9012ULL, 0xE6C8575B274AB57BULL, 
            0x432B38CB1927F9ADULL, 0xE8F85C7DD33BEDB9ULL, 0x144D34AD4626504BULL, 0xE043F3FB0F2BFBD4ULL, 
            0x9A016E5500E4EB03ULL, 0x3A2DE8F21C73CA03ULL, 0x973DE58950942CC6ULL, 0xD4F7D8E88C9DF93BULL, 
            0x70F5B17CB847C664ULL, 0x4B44D4DA3DE4CEB8ULL, 0x0E43A7F6C4963B0BULL, 0x1C7A435438BB809BULL
        },
        {
            0x348C634D94523AA0ULL, 0xFA9CAA70B48E8172ULL, 0x7C6A4F2F9DD531DCULL, 0xC690B8B81A21DF89ULL, 
            0x6883C35560549108ULL, 0x47B143DA4D60B548ULL, 0xE76438948C6D8078ULL, 0x5A4AA8935771DF78ULL, 
            0x9C72092FE2B58BCFULL, 0x74D41415AB47D363ULL, 0xFA2567D2C3F0EA87ULL, 0x848D9CC4B84FB062ULL, 
            0x95C23E0FD2DF2C42ULL, 0x9E38BF44D41F35A8ULL, 0x8D8ED07E8F7302C5ULL, 0xDBB2D31CC8B0736DULL, 
            0xBFACB1AFBBA0E969ULL, 0x65211426C3E38053ULL, 0xA66098678F609057ULL, 0xE24BE5DC6AD20944ULL, 
            0xAA15D1E4E11C4581ULL, 0x422CD0BBFA3321BEULL, 0x028E7C6D4D2A876AULL, 0x5EDB8C7E5544133AULL, 
            0x45216682357DBF68ULL, 0x169C387AF0236952ULL, 0x1719D0DCC5ECD887ULL, 0x102CD98F882D9D55ULL, 
            0x207309FC3245B9AEULL, 0x2567ABA4504E2565ULL, 0x1A8EC5FBF8FAFAA0ULL, 0x8B04F75EF55E4E59ULL
        },
        {
            0xC0D02D2F0FB65026ULL, 0xC6A0FC920427FFC7ULL, 0xCD11CD67D77FF49DULL, 0xB02487E7466E894AULL, 
            0xD9DCA2419C295327ULL, 0x21E33A94B24D6BBCULL, 0x8918FD713E57E780ULL, 0x6E4AC271B4B54284ULL, 
            0x60538850828AD18BULL, 0x39E7AC535EDD4AF2ULL, 0x50D84D3194AA3B64ULL, 0x0172F8D3DACECCD9ULL, 
            0x23914CE37F54D05BULL, 0x44DE147494356E5FULL, 0xC43178BC6FE602FFULL, 0xB973F33D515C46A7ULL, 
            0x3038954FAB7FC1E8ULL, 0x07FB744C6863A384ULL, 0xE38B6B0BF48E4A74ULL, 0x69C48D32B8B22FDEULL, 
            0xD945CE9B50391663ULL, 0x5903BC35AEEC772CULL, 0xC4460A47A97B5705ULL, 0x9FB1403C2E803B30ULL, 
            0x537ED7CB5CD12572ULL, 0x4621654482425F78ULL, 0xA14151B8F91C4CA9ULL, 0x341C21D6065C6198ULL, 
            0x9C0097884274C0DEULL, 0x3F014A93528BB07CULL, 0x6A6B4B32B3EDEB82ULL, 0x1B13AB377FE836F3ULL
        },
        {
            0xDCA428545866A245ULL, 0xE8029768C9FAE6F0ULL, 0x0303DA31B4080E71ULL, 0x414EF23E85C6F28CULL, 
            0x8D859B59323A9231ULL, 0xC7AC8AB1CDA0DCE1ULL, 0x7497DC0D0B7A0B60ULL, 0xC1AA224B294BB747ULL, 
            0xC58A28CC2BB8E553ULL, 0x3D29579E0DCCBBC2ULL, 0x902A64D71CBA8CA8ULL, 0x004E6257B33B97E1ULL, 
            0x78C2DF421169BAC7ULL, 0x4E6555DC5695EC91ULL, 0x0DC0E5F785C755A2ULL, 0x1B5D1D8669938554ULL, 
            0x6D6899EA5ACF414EULL, 0x10FD6EFAA2E7255CULL, 0xA547E99DAE559BCBULL, 0xD894D38BC3D82264ULL, 
            0x4376AF3ACCA95E5CULL, 0x75539F96067FD19EULL, 0xCE1B499D4C31CDE7ULL, 0x2972276EE3784F05ULL, 
            0x9A4B5D6BE2A56038ULL, 0x791456426D851657ULL, 0xD959FA0A103D32F1ULL, 0x11DD1C78271DAE74ULL, 
            0xA6756D2E20A64515ULL, 0xE2A2FA769A47B3DAULL, 0x2C86D90BF2491738ULL, 0xB8ED3E3343407728ULL
        },
        {
            0x543DE2FF578C77C6ULL, 0x06DD98016E05B73DULL, 0xEBC11D56242C3C0FULL, 0xA53D9BF94776DFCFULL, 
            0x8F473421D71452A8ULL, 0xFFBCEF73AC35529AULL, 0x47FB29513E42F3ABULL, 0x1BB728DEA31D7FE6ULL, 
            0x232248DBEEEEFB03ULL, 0xB9A3674E617237DDULL, 0x4A14BE8B2D187F8AULL, 0x59A7130E2D54A458ULL, 
            0xA4AF297E3090125AULL, 0x1F47452B4BC4EC79ULL, 0x4CF83A89E8EA7A61ULL, 0x8136FEEC12B46CA9ULL, 
            0xD3003ED3F8EC355EULL, 0xF63B163EDF90252FULL, 0x6FE36827DF609A43ULL, 0xB63BFC4016E2AF9EULL, 
            0xBB64438AB6E8FFCDULL, 0xB157CCE96F8757D4ULL, 0xAB7EFD2F307CB0DFULL, 0xC5C09CCCBA099AA0ULL, 
            0x441AA7F32B8F6F35ULL, 0xB5D784CBF37C2A90ULL, 0x51108C74B9AF954DULL, 0xBC730D69718BBF6EULL, 
            0x0BBC2234D43AEE65ULL, 0x3C2CADFAD48E49F3ULL, 0xF59ACA1AB394173CULL, 0x9A5BD1FCD2E97700ULL
        }
    },
    {
        {
            0x5F107EBB0595F459ULL, 0x18DCE8843083840CULL, 0xF44D1A32C65F266FULL, 0xB412C27DF880550FULL, 
            0x3FF69C7DEDD52719ULL, 0x012380EC577733E5ULL, 0xADE9FE47282B1FF4ULL, 0x1CFECAB8FF0E5EA3ULL, 
            0x507258973CD3B2CFULL, 0xD32A91EB4E592555ULL, 0x2B92C2D9D78F8D4DULL, 0x4CF049846E40E6D4ULL, 
            0x5F40EE0218A0E354ULL, 0xD6DA2C1C19982406ULL, 0x9AE4FC43D1F43EF8ULL, 0x5F3C79316FE595BDULL, 
            0x166345631B0576FCULL, 0x233DC01FDEA14D7CULL, 0xF2128779150C292DULL, 0xF64B711ADE38B1E0ULL, 
            0x28635C9781FAB66EULL, 0x921E97DC1E8ECCFEULL, 0xEE425572E4693B7FULL, 0xAFBB46070C3D4362ULL, 
            0xD8FF61840157A92BULL, 0x52423DF21FD91597ULL, 0x5D45A5CA484A3B7DULL, 0x46952EC3F7A458BAULL, 
            0xDDE92FD2BD7A610BULL, 0xA7EDBE281876B53EULL, 0xB486FEE997588E54ULL, 0x03B8DDD84334494AULL
        },
        {
            0x4EDCCCF3669C18CCULL, 0x03680145F673F22CULL, 0xCCCE8A3FD5D8B268ULL, 0xC5B7BC9D0E0A6C78ULL, 
            0x1943DCAC8BFC8DAEULL, 0x7F8B9B41971D1038ULL, 0xA49B94E8036029AFULL, 0x638CD759CD421376ULL, 
            0xA53C2EF88B9F3718ULL, 0x765BCEF218DFD996ULL, 0xB224A997A7A088FAULL, 0x68073C11E5421927ULL, 
            0xF8C69C1DB4670192ULL, 0x40740D67EECD684AULL, 0xF2AC4EE97EDCD5A7ULL, 0xDA0E0F5D982BFB72ULL, 
            0x06AD68211E5CA21AULL, 0x6CE679814CA45161ULL, 0xB3E632ADB47DD91AULL, 0x56E720601B057706ULL, 
            0x70A537F6CACE6AC8ULL, 0x0704FE20FD902093ULL, 0xF035341C409CEA9EULL, 0x909C776646805326ULL, 
            0x309B17DED500CF5BULL, 0x06F2DD73AFCB0DA8ULL, 0xAF7BC7B4D6D7D3A6ULL, 0x42D87496D0DA75BFULL, 
            0x1B4B207DD169EC13ULL, 0x4F9CB90A1C0292B1ULL, 0xB473A4FCC49AC4CBULL, 0x498F2F41C1082D07ULL
        },
        {
            0xB9FB6E6E4661A925ULL, 0x757D32096AE66C5EULL, 0x6A8C0274C1B0C123ULL, 0xC5170327D912B861ULL, 
            0xC7DD92B7A1F78398ULL, 0xACBBD1D8CE0AA6A8ULL, 0xEC7659F71E4A4704ULL, 0xDB0C38823F40E4D8ULL, 
            0xB7D9E67E526A25EFULL, 0x33840FAEFA15B1FDULL, 0xABE10AAB63445F52ULL, 0xF135BE038C360FBFULL, 
            0x8B383ACD1B6CA270ULL, 0xDB30CDCDA58C09B6ULL, 0x6256E0AB26AE5B55ULL, 0xA4E4FA18B291A878ULL, 
            0xE841AB5C48254993ULL, 0xC20530AE99642EC6ULL, 0x36FBCC11730D2F91ULL, 0xEFA75B48D5353F5AULL, 
            0x66D796D9FF0826EAULL, 0x2DBC4B7E932977BCULL, 0x44C60F9FB9BD616FULL, 0x1FE6B865A7DFE38EULL, 
            0xE584D163961844AEULL, 0xE80C5249BF2A8F16ULL, 0x5B1C1245F41022E6ULL, 0xFC67D2B8D075251DULL, 
            0x1DE16A2338876115ULL, 0x29928479EF434D62ULL, 0x2DC841DE073F5B61ULL, 0xB2D0580F84D7FFB3ULL
        },
        {
            0x2E504536FBF5A188ULL, 0x612808FD60998502ULL, 0x5335A2088FA0F775ULL, 0x49710E2D9C4B201BULL, 
            0x845379EB7116D033ULL, 0xCAB7161FD25338F0ULL, 0x4BEA2E6DFFD519CAULL, 0x048754C4ED5564A3ULL, 
            0x089CA945F8138BAFULL, 0xE1B93313067575D9ULL, 0x444928322F410A6DULL, 0x0816A729D7C2494AULL, 
            0x4AD866A90EDEE10AULL, 0xCBB3CC7715EEF44AULL, 0x01DF588B0286103FULL, 0xD4C846E35D06323EULL, 
            0x24946A35FFBC5D65ULL, 0x57DC5EE13677500BULL, 0xC506B9F204C79117ULL, 0x87C7381A383AD9AAULL, 
            0xBD8A6DF6924EF00DULL, 0xFE287A53FA60F766ULL, 0xA5848D7191DBD9A0ULL, 0x8610FE69657BAF78ULL, 
            0xB964D659241897B6ULL, 0x7D6C6DD0A3F5C3B7ULL, 0x179FF44C2EF2C857ULL, 0x7E6CA334BA834CD5ULL, 
            0x3C5065062CDAB215ULL, 0x302C7598CD203E6EULL, 0x723EEC93F8C07779ULL, 0xF01C19EFAE2F79C7ULL
        },
        {
            0xEF024B871FDC040AULL, 0x5CAAE925CF428573ULL, 0x8239FEA36B1276D3ULL, 0xB6F109762D01DA11ULL, 
            0x0D35D85040517AC4ULL, 0x32F5572CFD282D05ULL, 0xC4B4A88D7170E1CBULL, 0xBFE2BCAC92ED4B09ULL, 
            0x9B7BC148C9B7A5D8ULL, 0x983AC09D242D8C79ULL, 0x3559D86DB7E9E724ULL, 0xB24A3FDC50A360B9ULL, 
            0xC69D92C1AE209252ULL, 0x7855019A193C9F34ULL, 0xCBDAA2DDEC9DCD4DULL, 0xDF82D25E66062A81ULL, 
            0xE365F11B10BF488DULL, 0xA5F25DAECF6D4482ULL, 0x556386961476ABF9ULL, 0xF49BA2187BD9C11BULL, 
            0x9E910D85E5AE0518ULL, 0x75A1676120C2AF49ULL, 0xD3ECCB56398D9AFAULL, 0xEA93D1FD548177C7ULL, 
            0x9E648D020E879094ULL, 0x15A0492E68AE7318ULL, 0xB688BAA19B8EB1F3ULL, 0x90891F8A33835C00ULL, 
            0x95111D3713872851ULL, 0x9525BCCBAD7D0B0CULL, 0xD10F1E5CB8C33D6EULL, 0x0CF98582C577342AULL
        },
        {
            0xD5D6B20DCACA68DCULL, 0x0D8F2FCE8DD6107FULL, 0xFE1BCFC53F387EB3ULL, 0x55F044D728055ED6ULL, 
            0x7ADD0A24A6979CCBULL, 0x6803AEAD04A5197FULL, 0xB6BC364DA329F11EULL, 0x0F0FB2B471F2B4B0ULL, 
            0x19F8F357A85CFC1FULL, 0x7827BB5571DD3F0DULL, 0x3FFC4D24EE3CD604ULL, 0xDC54AEF5DC9C8AA4ULL, 
            0xCA1EA185AAE3F09CULL, 0x11B7DA884F8780DCULL, 0x78904AAF87A10869ULL, 0x843B9A4F6F45707AULL, 
            0x33930DCAF0B3A29CULL, 0x7DACA35534C45BBDULL, 0x90F8277DBFDD772CULL, 0x414D2BC65742970EULL, 
            0x254EEB092E7395F1ULL, 0xB7843F52848F01EAULL, 0x45FE8384B5537F74ULL, 0xA251260319B8E0F1ULL, 
            0x44274630E20B8704ULL, 0x0FED91D0CD0818C8ULL, 0x2DBBF4E479B0B1B4ULL, 0x2CFD2B5CB7B18F27ULL, 
            0xBB560130186C9076ULL, 0x3C1D4EB623B4B969ULL, 0xF49AC7B605AF3EC2ULL, 0x58DA922FF06201A5ULL
        }
    },
    {
        {
            0x18AAB1B9F33D16D1ULL, 0x916A97D66D4CC332ULL, 0x71EF2798653E2350ULL, 0xE26FFF1410BE8359ULL, 
            0x3AD497DD03DE2BCFULL, 0xDDFB7B51BE5F776EULL, 0xE01E00FAF3FAE569ULL, 0x1BCB95DF5A9EB51AULL, 
            0xDC52AF173EBC0364ULL, 0xB0C6B96F5D466353ULL, 0xE4CECD106CCFD875ULL, 0x6AECA942C7AE17FAULL, 
            0xB05F65FC716B2466ULL, 0x041F8F4F77DB394EULL, 0x4B6BC40C6936F4CFULL, 0x92F8844EA58E524BULL, 
            0x27802A8C16ECEB3DULL, 0x625530EE255F61D0ULL, 0x8B370185DA1E2DD8ULL, 0x4FAF555C62618DFDULL, 
            0x4456577B4BE45F03ULL, 0xDE98421CE1E94B5AULL, 0x7366DD445E2D6F48ULL, 0x15D7162D09906A3FULL, 
            0x39FB852C93DB40E2ULL, 0xC0209F63224DAD21ULL, 0xD4F373C3D28A36CFULL, 0x4D1B7334058D6913ULL, 
            0xCAB290AE0921D697ULL, 0x8ED56844B971CB50ULL, 0xC372A76BE92E94EBULL, 0x041F08DE05A016FEULL
        },
        {
            0x85F9BFC1A369DC41ULL, 0x80C6C3A022A311DAULL, 0xE5D50D6CCB121282ULL, 0x7DE04B7E0DD89A1AULL, 
            0x810E1069A858D1FDULL, 0x5B1A654689B3026EULL, 0x39213D914F575A67ULL, 0x4F27AE6B9823F0A5ULL, 
            0x725D1844506310F1ULL, 0xD2E42E5A528602C8ULL, 0x9CBF6338F865E1B5ULL, 0x785D893DC5E53113ULL, 
            0x93E3910FE02C8535ULL, 0x1515E1AC18DDEE80ULL, 0x31EF950E9C919E65ULL, 0x46D9EC04D7EA896BULL, 
            0x195A86BC65131C0FULL, 0x99E82D29B04D3938ULL, 0x82A0BE0D7419AA50ULL, 0x25AD3C5B65442258ULL, 
            0x0CC6C8B60C52F3F9ULL, 0x8A96723B1B5DE776ULL, 0x62F3AC7AE12B3998ULL, 0x3FF870E343A403B6ULL, 
            0x5EE19F8C8DD76C2CULL, 0xB24D09A26D4AF11EULL, 0x78F48D46D40827E3ULL, 0x3F1D8E075699E37DULL, 
            0x1250A70091D1763BULL, 0x95A15D037F526C4EULL, 0x7F2A7A41EFE6937EULL, 0x0714C0FD9D3A5B57ULL
        },
        {
            0xE21DC9A70D363577ULL, 0x19C302744B376F2EULL, 0x1403E2D1D2A000D7ULL, 0x6F3A9D7EF89AD4FBULL, 
            0x9FDEAEB012B710FCULL, 0x39A180FB93382A1FULL, 0x818AFF7007CEBA69ULL, 0xA3AC04D24698F665ULL, 
            0xB76D88AFC83CE231ULL, 0x5D584BE7B8E2C281ULL, 0x904F14AF0CE06935ULL, 0x9E74BF28674D6E7DULL, 
            0xA53DAA413F8B7C21ULL, 0xFD4894446A77F289ULL, 0x3AEAD101C4B50336ULL, 0x818F5D1504CD0AD5ULL, 
            0x701DDC6676B46311ULL, 0xA4ABC9F8D32A87C4ULL, 0x9CBAB8AD4FE3830EULL, 0x4884AACE30BFDDB2ULL, 
            0xD0F1C7C98C799F2FULL, 0xCD4207201BC685D4ULL, 0xA4559AF15134EC1BULL, 0x2EADB3E47641125FULL, 
            0xDBE37F11A91B007CULL, 0x672FF44EF481A6B3ULL, 0x88EA7DA79A9ABC4CULL, 0x22680494BDB7D935ULL, 
            0x5C87685FEEEF97AEULL, 0x0D79DF9415015D5EULL, 0x652D2FCC9FF970BDULL, 0x88B5C55F32ED29D0ULL
        },
        {
            0xABD5894473C37D3BULL, 0x8839C3535387CD51ULL, 0xA92C8AC63B10CA90ULL, 0x52E080C0281B5CF4ULL, 
            0x0F13A547D4D2A7F2ULL, 0x74CA0518619707C1ULL, 0x0A9902FBF01316B3ULL, 0x01CD19EDBC1D3C6EULL, 
            0xF3E07C993A6941E6ULL, 0x99F059A4E83AB34AULL, 0x1C95546DF297C536ULL, 0x149EC9D5C55CC76AULL, 
            0x5F1B4CFC8E2187E5ULL, 0xDD972F08FA39F70EULL, 0xDD688371CD355F7FULL, 0x29BC8BD5C87F6699ULL, 
            0x4C864F96E95A988DULL, 0xC96AB8942ED17E8DULL, 0x6BF397ED09EB6179ULL, 0xA424A87EAC5D5F6BULL, 
            0x998F450D0C5D5B48ULL, 0x4637D7A7DF32607FULL, 0xA369FC0A4DA0E091ULL, 0x143A9E5A7B1EF6FCULL, 
            0x61266CE4F66768B6ULL, 0x5E6595660C793C02ULL, 0x0B3E2CB1CF665FAEULL, 0x4EB02184885596E1ULL, 
            0xCD3C5EAFEEE82FBBULL, 0x24F547AE13E45A92ULL, 0x91704860659F5807ULL, 0x23B7B763A82A6CA8ULL
        },
        {
            0x4AACCE52EE7893F6ULL, 0x707B8F72685DED4DULL, 0x26AB5D4BAF599FB6ULL, 0xEE7E784A24B7B860ULL, 
            0xB05B501F356D25ADULL, 0xBAF33B6B473BE54BULL, 0x76D62B0BED28C4B0ULL, 0xF457F7A54E029BF7ULL, 
            0xA0C880C993ABE468ULL, 0x3307F01AE2E168B1ULL, 0xF4277EB338D59106ULL, 0xB5EA797509733509ULL, 
            0xB8A0D67BCBF03E45ULL, 0x5C42FA2B39FC1B8DULL, 0x24CFB9827C821C8EULL, 0x854AC5B08E1F6C65ULL, 
            0xF0859D3DFCBF2E3AULL, 0xC7A5E6D0D15A5079ULL, 0x3C30FC4E5FD56075ULL, 0x8DC275873027102DULL, 
            0x98993E335B247F3EULL, 0xBF76F97EE246701AULL, 0x800D1A5B8DA9B219ULL, 0xAE7DD999C7C3E3E1ULL, 
            0x2C21008416CA60A6ULL, 0x076AE1E13D68370DULL, 0x549BCB822FF8DFC4ULL, 0x2DB22EA2B37B6A06ULL, 
            0xC17B23D15659FA85ULL, 0x7046133E63780F8CULL, 0x5157B2EA4B8A2E3EULL, 0x39532237687D93D0ULL
        },
        {
            0x39746FBAD16E7F32ULL, 0x328B76D173B20502ULL, 0xA68EFF483FD30539ULL, 0x1CE3F406F2836CBFULL, 
            0x46C8928C1EEC4C36ULL, 0x57348FAF9CE0986EULL, 0x97CDE4CF324BF69EULL, 0x522C41D47BF1EF7FULL, 
            0x676FEC51677FFCFAULL, 0xF60EF1262C06B2F0ULL, 0x34DBC5FCD964A099ULL, 0x57BEBC71107FADFDULL, 
            0x88A779A7095EEC9FULL, 0x68380446385F678CULL, 0xE5CD805237AD41C7ULL, 0x43C6A267758A7F16ULL, 
            0x53A271D502875FEBULL, 0xF3D065AD0C379458ULL, 0x36B2D934B6C7B30FULL, 0x0CF8A38C44373E16ULL, 
            0x9037B5DA2AA065A6ULL, 0x0E221874F4736B3DULL, 0x3A76C8F258A8CA13ULL, 0x22AF420BC78C7FE5ULL, 
            0xE99AF492CE4BDF20ULL, 0x69253019BE5D0C49ULL, 0x21830B43B9534C21ULL, 0xEA5C4F42F043D985ULL, 
            0x16AD673D3868CDC2ULL, 0x12429BA55D3E740FULL, 0x6726FF5E07F544D8ULL, 0x18D403BFF5F56D27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kPhaseCConstants = {
    0x9E344BC4075B0884ULL,
    0xF8A9086C212600E9ULL,
    0x5145638A98B51D9FULL,
    0x9E344BC4075B0884ULL,
    0xF8A9086C212600E9ULL,
    0x5145638A98B51D9FULL,
    0x7C8B8FBE105F8BAAULL,
    0x2B5C55E95F25FA19ULL,
    0x42,
    0xFF,
    0x79,
    0xA8,
    0xDF,
    0x93,
    0xA3,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Alnitak::kPhaseDSalts = {
    {
        {
            0xE05661078D769987ULL, 0xA64BC9B2464F9CC9ULL, 0xF5BECE850C2293EAULL, 0xFE88741B4479E296ULL, 
            0x67AADA3EA338530AULL, 0xE87C6866DCF57E8AULL, 0x8F7200C465788A37ULL, 0xCF5DB3F7D2186272ULL, 
            0xAB136B01499A7CABULL, 0xBD761A5239001D2AULL, 0x35B079B87B9AE39DULL, 0x87E89009E60EEAB5ULL, 
            0x8B80CDE09CE82868ULL, 0x925D27A429AE41B0ULL, 0xEE0D9377E9656BA5ULL, 0x852FA10C5EA85748ULL, 
            0xA904AFE906A1D697ULL, 0xF0430F5B078AEFECULL, 0xA13C426002271D62ULL, 0xD3746A0DBF938AFDULL, 
            0x04E81585CFD12B4AULL, 0xC710A8708BA12F64ULL, 0x91AB413B1AA5442AULL, 0x52942C0C39A32825ULL, 
            0x64F43BB3B0A82734ULL, 0x049BF3674812C8BAULL, 0x96C5C1084BE89456ULL, 0x54CAE8B44E5A124DULL, 
            0x606F37759D701AF5ULL, 0xA6EE93E21A7DC0A5ULL, 0x8C87F6A13FF82DDAULL, 0x47E0F9115EA24096ULL
        },
        {
            0xF8CCE93EBAB01AB4ULL, 0x7249F3CC44F063F4ULL, 0x7E6EAC4259C84A5CULL, 0x49537C58A6D6E63EULL, 
            0x1D22EA39A8B2FCB7ULL, 0xA5F5C796ABE03A9EULL, 0x484756EE41D4FC9CULL, 0x334EE2629936D971ULL, 
            0x21CDA5E7C0C02DEFULL, 0xCA173F35C6CC5582ULL, 0x71371C4257AFBEC6ULL, 0xBB31DF4512536097ULL, 
            0x4F9D4C3D1C950FE7ULL, 0xD5CE5795971B4FB1ULL, 0x72C713212AE4DE02ULL, 0xACCDEFAC0E1C0D9CULL, 
            0x48158494AB0F1381ULL, 0x3AE5D34B3C32CB40ULL, 0x2D27EF1E8DDF27EFULL, 0x577B2349187739B2ULL, 
            0x6B00F4C561B4DD5FULL, 0x27EBBA2327D88C6BULL, 0x5471FAD03655B012ULL, 0x6EE13589560E1E28ULL, 
            0x7CF567A6B14D37EAULL, 0x5BFCE0779E9E1AF9ULL, 0xFEFBF2BCA0A2E4A6ULL, 0x8DD8898105B1D6D4ULL, 
            0xED6C3327602B8888ULL, 0x8F1C65F6F7C2C7BAULL, 0xA50E0E753825B6BCULL, 0x00A53B7362E7DED4ULL
        },
        {
            0xC0F717D3FD46D440ULL, 0xA5F4AFD6314359EFULL, 0xC98175E469E83589ULL, 0xB5DEF2A90AF92FEBULL, 
            0x4232998D82D9EEB2ULL, 0x04C12A319D0132EEULL, 0x9A492D3C29368B6FULL, 0x7D6A6EC8395B5C97ULL, 
            0xC66C65CDC3D17DADULL, 0x07BB1F1EB35481BAULL, 0xA8C6FF6CB3046B75ULL, 0x777BCA4754BAFBD6ULL, 
            0x4262F6B88679928FULL, 0x896A0A5AAA9727C7ULL, 0x9753F19E52C599DFULL, 0x9180FF985B4E1F31ULL, 
            0xA4131942FFFE8653ULL, 0x7C717D28D6743778ULL, 0x0FE46C71B306A7BEULL, 0x3DEEF14DD8D58EC3ULL, 
            0x4015C0EACFAE7FDFULL, 0x56953D20B578B41DULL, 0xF00FA25D0E59AB71ULL, 0x7B071CD0F7C9956CULL, 
            0x00FB73B3E922C62BULL, 0x68C1BD6D59F3E9E8ULL, 0x2EB434E7CCC1C7A7ULL, 0x08924E35CC7ED2AFULL, 
            0x0B0FC40FEFCA6D75ULL, 0x125FC19535162FC1ULL, 0xDD45E7D82266F856ULL, 0xFCCCD33B1B938798ULL
        },
        {
            0xDD8561DEF07BDBB6ULL, 0xC72DE91918A7BDD0ULL, 0x7054A29565304653ULL, 0xB8063C947B640C7DULL, 
            0x8E458629737DEDF5ULL, 0x46A5FBD429C28744ULL, 0x6E40F288CC03E8C0ULL, 0x55CD00AAC909DDD5ULL, 
            0xE82DC420E53C4AB7ULL, 0x349A55FF6C458C0AULL, 0x526A8679AE69087DULL, 0xC6CFD6EBB8772E78ULL, 
            0xE4C9E28FC3B43E01ULL, 0xC1805F689AC27C52ULL, 0x1FE82E27B351B095ULL, 0x85D82758E68FE691ULL, 
            0x583F3ABB53D85123ULL, 0x23FE6F2DCF1ED192ULL, 0xFDB36BF2F2332D69ULL, 0x4C4D2ED4671BE4B6ULL, 
            0xE82142BC8FE81504ULL, 0x4834E5D20CC2260EULL, 0x9A098CC159575809ULL, 0x4B0A98BBA2C12A7AULL, 
            0x6FB2617EF13288D4ULL, 0x68386BF0DD34DD7DULL, 0xC5DC0E15F5D70F56ULL, 0x2F9360B55C674029ULL, 
            0xAB24A6FF3C96B7EDULL, 0x57040974AB215E65ULL, 0xB6B4373066355541ULL, 0x39D4CF3164BD4CEDULL
        },
        {
            0xD56D5635D2F810DDULL, 0x9698328556BBC29BULL, 0x3098384D4CBC0839ULL, 0xAE0BEBEAC074FC3EULL, 
            0x897095059271CE99ULL, 0xEA1672BE65FF07CEULL, 0x509081F58CF3EF4DULL, 0x1164BAE84078D64BULL, 
            0x5C7FEE4628A9BAE6ULL, 0xCC3845C43D249564ULL, 0x123647A9FD0FCD73ULL, 0x494C2056C640BE38ULL, 
            0xCC2BD7A2D9989961ULL, 0xCAE53DF5FA78AF4AULL, 0x2EE55CCD520FDF4CULL, 0x903498D56F5930CFULL, 
            0x46A9D95D2D60F995ULL, 0x481F76A32105CD45ULL, 0x7AC5BF0339AE6F17ULL, 0xC61EF694CDB8F3A0ULL, 
            0x1D9C2BA450F34C2DULL, 0xDDFACDD339AA8D0FULL, 0x7D3331BC8F84B07FULL, 0xD47276C318CCB0DCULL, 
            0x3B01F82A34F00B4DULL, 0x36A55DD5454AE45DULL, 0x97D256EB51E8631AULL, 0x1B87EDD83B8E5949ULL, 
            0xE49AF55969933345ULL, 0x2D37FE5510A98C1AULL, 0x1D9ACE44707D49EEULL, 0xB5A988586D46A0A4ULL
        },
        {
            0x35B3FAC0532BA567ULL, 0x7CCC15B0E6C52272ULL, 0x9A79293F895D30DFULL, 0xCE593A021464F285ULL, 
            0x3A42247E2FAB4EC4ULL, 0x80A302662F6A1A84ULL, 0x73CC06F39F10F391ULL, 0xE9F409292801ADB5ULL, 
            0xE2FC49BD417E7E1CULL, 0xF99E7392D2881986ULL, 0x428082A50041CC89ULL, 0x9A24A9CE0AFD5825ULL, 
            0x29CB52AC7D9C41A3ULL, 0xDD4F19AECB6DDD0EULL, 0xA58A92BD4131AE3EULL, 0xB6E314B607489B0BULL, 
            0x40EFE2CC32D4C26AULL, 0x57DD86043EA6D2B2ULL, 0x8476FE034307E3C9ULL, 0xFB729B86C5AC3626ULL, 
            0xD392703A11CCB2ADULL, 0x2D60ED3EC2775F88ULL, 0x519362F5124B9374ULL, 0x63A6AB320D73DB01ULL, 
            0x425C49DDE5DE80CFULL, 0x35939217ACADFCDDULL, 0x18A59B17DFB7F7E5ULL, 0x72AE036E270F1DD1ULL, 
            0x927EDFAF4663EE4AULL, 0x44738AC0D32FB7C6ULL, 0x6182B6FC7C96DA6EULL, 0xB4C287577C5E0328ULL
        }
    },
    {
        {
            0x5C9C89D8EA14DD6FULL, 0x5AC4FD9236573056ULL, 0xEF0A3E7DAAF988A6ULL, 0x5EE532644DFECC40ULL, 
            0xA0FF667D71119EA8ULL, 0xBE3E66A5A4C22A8DULL, 0xD0A6EAD3CEFBB370ULL, 0xF34F3AC6BA8764DDULL, 
            0x2D5E504CDD323494ULL, 0xEA6912DF40D3EAF4ULL, 0xFE57951147394879ULL, 0xCF774C73EC6BD1AAULL, 
            0xAB5EB06B13D430B2ULL, 0x9E7196E48219C9E4ULL, 0xA3C299267AB712CEULL, 0x1D82289FC083D701ULL, 
            0xB9E2281106450285ULL, 0x6B7EED9AC6131CF8ULL, 0x7BA06FC2CC06ECFCULL, 0xE5FA038131B6F073ULL, 
            0xB721BA99E81EFDA6ULL, 0x6E0A9749401A08F1ULL, 0xAE728E5A50F96772ULL, 0x3484A38DD84F8D1DULL, 
            0x1B087E7887CA683AULL, 0x3BA9E87932E1B57DULL, 0x5C6D75E67357E892ULL, 0x8600602AEB025887ULL, 
            0x3A6780EBC2F94C7FULL, 0xEF1E69D7B191A784ULL, 0x33A30EBD6B4BE624ULL, 0x53831373679026AFULL
        },
        {
            0xFD3975FC14F26BA6ULL, 0x3DD34F3A43B97184ULL, 0xFA1850BCCB04E8ABULL, 0x227BBAC8508C5205ULL, 
            0xA98B5BBBCB192A02ULL, 0x372D7325C961E953ULL, 0x75899231416AA3EDULL, 0x53C5239EC1D43931ULL, 
            0x581C56378F997A30ULL, 0x5C10B826690ADBE4ULL, 0x05C40AD621D8252AULL, 0xCA2FB39E6AEB13CDULL, 
            0x5B3509B2320B0266ULL, 0x4234922E1F4E8456ULL, 0xA103F1F49D08B5F0ULL, 0x211BB0887AC58563ULL, 
            0x5F2C3D2132682284ULL, 0xACE7D9CB168EBEDCULL, 0x2B680D2C950355A6ULL, 0x354BF41DCC71B715ULL, 
            0x1A1409E9F446EE22ULL, 0xA6BA3F61A8340684ULL, 0x4C0363A096F80DABULL, 0xB455E8902188A07BULL, 
            0x8B1EA744FE0610EDULL, 0x9A433B90828A520EULL, 0x07B02DBE1B34A275ULL, 0xF912B32B50702FCFULL, 
            0x52BBD78C241BA143ULL, 0x326BA3DC95B8CA2EULL, 0x7BE334959A7D44B8ULL, 0xBB0D26FCD00111E5ULL
        },
        {
            0x90F3BD399A0A8A1EULL, 0x2A3DB3452B42DC78ULL, 0xF736D3E93F65A279ULL, 0x4400B1DA51F625DBULL, 
            0x59E2B01FDA8F4E18ULL, 0x5E1DBE569F882422ULL, 0x893C495579B69572ULL, 0xA50AACAD0C80F11CULL, 
            0x4319380FE5D2DD74ULL, 0x922EAD1097FBB781ULL, 0x1AE3055BC1EEEB15ULL, 0x6494BDA265651720ULL, 
            0xFCDE895FE8DCAC70ULL, 0x33D9C516D1E60CEEULL, 0xFC8D6852ACB6B375ULL, 0x109A44B9335A5615ULL, 
            0x5A5F046F6F75B6B2ULL, 0xE2046C9AA94E0424ULL, 0x925F86A46EB02C40ULL, 0xC0730089AB892CA3ULL, 
            0xB2174F832595CE2EULL, 0x4B75212DB7B672F0ULL, 0x6FD91D37AB139BDCULL, 0x6B3B661B0A59C2B9ULL, 
            0x3FB0052BC375F210ULL, 0x7264353768CBA1E9ULL, 0x832E80D753685FC9ULL, 0xED8F9FD82973C830ULL, 
            0x52E201EBB02AAD57ULL, 0xEADBDCC9F210B2EDULL, 0x7F56312DD0E10061ULL, 0xE48A9B79410AA903ULL
        },
        {
            0x04DFFEAC7BA35FCAULL, 0xD71BCE2B729DC43EULL, 0xE872D483B52E3BABULL, 0x3FD0BF3525109561ULL, 
            0xCBBD47745F969132ULL, 0xF31BFE34F2954703ULL, 0xB4D793F763142929ULL, 0x2334D7C0D8FA5B80ULL, 
            0x8030AF7BE93DF845ULL, 0x2524F805AFA0EEC2ULL, 0xE8F558DF3484FA3FULL, 0xFF2D18FE94CBFDABULL, 
            0x2214FADD6B85FD2CULL, 0x62F9B5C7E0C9E379ULL, 0x6560C93BDC3CA11EULL, 0xBE84B8D34212707EULL, 
            0xB660EC747B2131FBULL, 0x38A78A29F72392ECULL, 0xB820B5D3A2EA2DD2ULL, 0x4AD0CD70A7FCFC0CULL, 
            0xF8D3C3BB2318929DULL, 0xED24277FE2C834E4ULL, 0xDD4164987B35E839ULL, 0x69F8681FCE9C3A24ULL, 
            0x3B37F3EDE2C67D2DULL, 0x527857B13ECA7800ULL, 0xE95337B6C4079C0BULL, 0xE54005337A44D04DULL, 
            0x3158EF330BF4D245ULL, 0x93A83E0E191E0AF1ULL, 0xF68861BF23010C68ULL, 0x9D0D01BE500B0F3FULL
        },
        {
            0xC3F03E99D6CCBBC3ULL, 0x278CB15133E5B166ULL, 0x0836F36B6F9C18A8ULL, 0x31800F14701F44DCULL, 
            0xCA537D7C2DA23694ULL, 0x36F2C2D37EBF493AULL, 0xF1AD3FF827DC0A65ULL, 0xB6F6CB4D223A7761ULL, 
            0x03C677C1DC96800CULL, 0xBD7B7FCC3A88BA0AULL, 0x8810D2621D56BEACULL, 0xDB5A581FAD3755D3ULL, 
            0x4FBE4FA003336477ULL, 0x890CF8FCEBC70709ULL, 0xD6ED9ECC761FB912ULL, 0x7E1755C09567AB86ULL, 
            0xB6AA27A3792B8A02ULL, 0xA313EF14F2E2A5ABULL, 0x98DF6A70086CEEC0ULL, 0xCBE0B265D4277011ULL, 
            0x9FA31583F83976EDULL, 0x2D3A06D68114F192ULL, 0x54FB45E215C585D2ULL, 0xBF6DE75F6B240E63ULL, 
            0xD2B3DC357C6E4800ULL, 0xEB5FF2F1D477733BULL, 0xE5789D402B36F119ULL, 0x5A565569D1C18E84ULL, 
            0x5312380B9E661050ULL, 0x243C836901226EE2ULL, 0x6A8917FC5385D2FDULL, 0x4162C3DE30CFE39EULL
        },
        {
            0xE6C1D764504FBE56ULL, 0xB344497500224683ULL, 0x304237F2660AF294ULL, 0x7B682C5A02B1F62FULL, 
            0x80F528BBE31BA0E6ULL, 0x2433577F1DD55190ULL, 0xF0FE1C711B034EDDULL, 0x1647481CE289E8C8ULL, 
            0x76A164B1E7E3EBF7ULL, 0x789E29C0C8339D24ULL, 0x083A249B95D37A4BULL, 0x40A654A4FE513CBCULL, 
            0x1FD3F319F0A6F5D4ULL, 0xD7993916455C82D0ULL, 0x4AB6D10B45D58C68ULL, 0x96CA20EE123C0A12ULL, 
            0x2E467D7DDC35C0D7ULL, 0x950662C7A51ED9FAULL, 0xE379F4428F22D240ULL, 0x799ED38C1CE6A6C5ULL, 
            0x262396CDA24251B6ULL, 0x036C6B21EAC4E71DULL, 0xCADCC350EA500556ULL, 0xDEA18424955B7B6AULL, 
            0xD72A470767B63930ULL, 0x73CDA46928806C99ULL, 0xE30A8E6552F450FFULL, 0xD93F900D0869E3B8ULL, 
            0x463244F0F4EBABF0ULL, 0x822C0ED14873449CULL, 0x13D6D0027061218FULL, 0x39DBB83C2F14C2A9ULL
        }
    },
    {
        {
            0x2B1AC8AB883BE1AAULL, 0xB7A147A12D48FAF6ULL, 0x78D0F08F12E2A9A3ULL, 0x3FBF0C063BA5E187ULL, 
            0xA8DC2DD0C4BFF482ULL, 0x160B02B8F5E8B6C8ULL, 0x90A252551DB49E09ULL, 0x6C9AA6C8384CE395ULL, 
            0x2C8E34B96F5936BCULL, 0xE7F0FA5AFB31AAD8ULL, 0xD5360C6CEE8D1D85ULL, 0x0C2953EBFB2641A2ULL, 
            0x382DC49C8E707F31ULL, 0xD727D9B2A6E215BBULL, 0x20A89241D8DAFF94ULL, 0x088743F3614BA49AULL, 
            0xE0DA10FCBCFEE570ULL, 0x626AA6A7CC0DE132ULL, 0xF26CF95409F15694ULL, 0x5E6F324934EFE173ULL, 
            0x8720B5CB4665BB83ULL, 0xD8EF1C6904828C12ULL, 0x54AC7D81AC4772B1ULL, 0xAC0AE6759BB0194BULL, 
            0xA739FB761EDFA4D9ULL, 0x45647A1E4EE10A91ULL, 0x75EF73EE49C20FF4ULL, 0x7F4EB7F3453F3891ULL, 
            0x524AC3C02E139F71ULL, 0x3F5CF0BCFD75191CULL, 0xAEB865679F4F7096ULL, 0x7433BA4C919B519AULL
        },
        {
            0x6745189ABC037116ULL, 0xBB9F62661D441072ULL, 0x3DB759660D55AD72ULL, 0x1E174C6984CCE0A2ULL, 
            0xA811D607BFB1A626ULL, 0xC02CCF80F5338B38ULL, 0xBD837C984F75BDE5ULL, 0x24A04A0AA6003A8DULL, 
            0xF5E54C4F62EA0411ULL, 0x4C80CC4A22554A1EULL, 0x7867715DC4AFEE22ULL, 0x3D350AD0B4074D22ULL, 
            0x3FB587E76D44C0D7ULL, 0x1FA04639E2BDA8A4ULL, 0x698DCA2582B35FC6ULL, 0x1E6ECD405B58723CULL, 
            0x0698468ECE84D749ULL, 0x00DFD42B2FA9CD6EULL, 0x1A935B437F33E90DULL, 0x61CACAA209490DAAULL, 
            0xEA4368B7F41D4DC8ULL, 0xFACB9FF3C960D756ULL, 0x5FE4A1CE206F4BC0ULL, 0xF00F52E20A62C1ABULL, 
            0x8E3393E8C08838B2ULL, 0x2332278BC453B56EULL, 0x63EC0131B7A34D9FULL, 0xA564488200C55E93ULL, 
            0xD4E397798AADE88BULL, 0xA7670D224F4D33CEULL, 0xFB1BF55A258315FFULL, 0xAEE5BF6849380888ULL
        },
        {
            0x615DD7210D79E790ULL, 0x85EE2B863DCD3722ULL, 0x6E79A69015C76111ULL, 0x8C05F4D28DF89650ULL, 
            0xE5F0A6C3F7A3AEA1ULL, 0x8962B7B2EA5C018DULL, 0xD8BA24587663B922ULL, 0x98C5824AE8A98851ULL, 
            0x1153450C2C7E9BA4ULL, 0xF22B081007DB9962ULL, 0x967C4E5DCA2B01E8ULL, 0x6CA2A65D73E9CDA7ULL, 
            0xB2C761FF1697762CULL, 0x5C21103704781148ULL, 0xA74485AD50E27D60ULL, 0xEF4227E4076C957CULL, 
            0x9125ADAC7276D57EULL, 0xBFA92AD4A0D9B76DULL, 0xEEEE1BFBD71268EFULL, 0x7032688EBD3FA7CDULL, 
            0x136CE98A7E62361CULL, 0xF8A15C70CAEAF5C6ULL, 0x510F7F881D9F449EULL, 0x77F46C6EEF1DDD14ULL, 
            0x6F36BA98A2EEB399ULL, 0x05C0C330026AC6E2ULL, 0x2120534A51045593ULL, 0x23BF029375DD7CFCULL, 
            0x98E8E2B3DC8EE570ULL, 0xC73F9AC94991AF4CULL, 0xF4C4333E47DF28E2ULL, 0x35D6826F3A0E7C5CULL
        },
        {
            0x7586353631C259CEULL, 0xA6ACAB945881A9DCULL, 0x319D14078901E2D9ULL, 0x011CC25955C40D5BULL, 
            0x3154FD8D637C1EF5ULL, 0xAEB9523FD3DB4F7FULL, 0xB87D6D57E53151B9ULL, 0x10B4F04D0699945CULL, 
            0x763BC9A8EC3480DBULL, 0x77E66D5242835CD1ULL, 0xFD0A801FAC3E7FFDULL, 0xF727AA1231F077E7ULL, 
            0xA58EFA2438EC1AAEULL, 0x2AE022584EBEBB97ULL, 0x6CE5118112544986ULL, 0x376DD479B8F12290ULL, 
            0xC9B3DB115B7FD895ULL, 0x4293C550B7C90E65ULL, 0x3D716E890A2F0B0BULL, 0x0BF626E7FAFA873CULL, 
            0xD6CE85D6672D76F4ULL, 0xAA93D4622C780300ULL, 0x3F2900D1E1F0C8CDULL, 0xB05C0447BCBA3FB5ULL, 
            0x927F652F7E3BD092ULL, 0x3CD694E401111D6AULL, 0xD33AD46CBB605878ULL, 0x3F09C8E0D1126D52ULL, 
            0x914B70789F0A9951ULL, 0xFAB26576C1A2B1A5ULL, 0x9C3291AFB7075CA0ULL, 0x8601725718E0AED7ULL
        },
        {
            0xA6348DD2A1967628ULL, 0x9BFB49D78AC9E8E1ULL, 0x5A61CEB5EC29ECFEULL, 0x9DCDD1FACC3EF50EULL, 
            0x5D0092A8FFB62A3CULL, 0x64A9B37BBBBE1A55ULL, 0x21E00D841721D887ULL, 0x1DF3DC1D5A3F6335ULL, 
            0xE530605D71E84060ULL, 0xFB9204D2A309104BULL, 0x8C72240C2408185DULL, 0x7E1D7A2BCC426942ULL, 
            0xFC426D7A386F44EDULL, 0x1AB5716F7BF87039ULL, 0x96039DDF30BC737AULL, 0x4AF93DBCE181B9E6ULL, 
            0x7ADABC8C0D738BE4ULL, 0xF9882E415762D511ULL, 0xB54D9441099BA15DULL, 0x550610AA2718EEC3ULL, 
            0xC52AD58F85D3F992ULL, 0xD8D4A783C68B6577ULL, 0x22E8BA750387B65EULL, 0x13C6CE192D4C1DBEULL, 
            0x6E0F3CA9D91895CFULL, 0xAC117453A406F1ACULL, 0x28913B2A8C82CA12ULL, 0x5A0149D9A99B8BAEULL, 
            0x8E684D6D4B4B6028ULL, 0xECCB056902BF183CULL, 0xE2B1E2BB48E2B65FULL, 0xCA4048EC3C7DEDA2ULL
        },
        {
            0x746F8D0AB0696605ULL, 0x932AA597D16398EFULL, 0x047E073ABA81A1ECULL, 0x00EC66BB17E2DD65ULL, 
            0x96196B9E9D0CC27EULL, 0x0D093FA6D80E7172ULL, 0x3E02FCCCD639CB24ULL, 0x12AF5676F942AA4DULL, 
            0xCDA26B4ADE6EE6BEULL, 0xF6FE52DEFCF6F416ULL, 0x511EEA98290600C8ULL, 0x6A9A402F80827759ULL, 
            0x48912BB4CAD11793ULL, 0xA13E04551C031F14ULL, 0x915BA937E4F549EFULL, 0x5B4D5AE594AED2A0ULL, 
            0xC41751430F22F88AULL, 0xDD7421C82317D8C2ULL, 0xE5CD12610234DAECULL, 0x150B26D292DA43F5ULL, 
            0x2A25C231E37AF60EULL, 0x18F7674CDB037D35ULL, 0x79235E7DD8613CFEULL, 0xBFD92F5EE8795570ULL, 
            0xFFF92DC6EAC51E85ULL, 0xE30A6E41434695D9ULL, 0xE10F66374B6606B7ULL, 0x269C9FF2F3AE4584ULL, 
            0xD3A23971FDEEFF6EULL, 0x2592D666EEC684A6ULL, 0x02F03CD00EAF27F1ULL, 0x1C7C94D77A576F1AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kPhaseDConstants = {
    0x8A4E1967B6FF91C3ULL,
    0xA66500325AA4B95DULL,
    0x99EECC6A7A7C7563ULL,
    0x8A4E1967B6FF91C3ULL,
    0xA66500325AA4B95DULL,
    0x99EECC6A7A7C7563ULL,
    0xFB6C8903C7A2FD86ULL,
    0x5C71B2E939D5D75FULL,
    0xE4,
    0x74,
    0x19,
    0x91,
    0xAF,
    0x15,
    0x71,
    0x54
};

