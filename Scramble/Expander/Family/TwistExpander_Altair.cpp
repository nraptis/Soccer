#include "TwistExpander_Altair.hpp"
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

TwistExpander_Altair::TwistExpander_Altair()
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

void TwistExpander_Altair::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC91778AC48829218ULL; std::uint64_t aIngress = 0xB84A0F97EEB15F51ULL; std::uint64_t aCarry = 0xC133EF84F65E1D94ULL;

    std::uint64_t aWandererA = 0xEF09781B5FFC2132ULL; std::uint64_t aWandererB = 0x964AD622439E8256ULL; std::uint64_t aWandererC = 0xBAB372D91E6887F3ULL; std::uint64_t aWandererD = 0xA8B07E1300313AD9ULL;
    std::uint64_t aWandererE = 0xC7DDF47C9AA71629ULL; std::uint64_t aWandererF = 0xA7A544D8D8FC9D84ULL; std::uint64_t aWandererG = 0xED0261F0202CF938ULL; std::uint64_t aWandererH = 0xFA4C37261658BF6FULL;
    std::uint64_t aWandererI = 0x977A20F4F7D46487ULL; std::uint64_t aWandererJ = 0x92A5E3A734C0B35FULL; std::uint64_t aWandererK = 0xE7FD98753A84F840ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8EE717DCD055981DULL;
        aCarry = 0xBF5FF07BD71C87C9ULL;
        aWandererA = 0xB862238C913E8343ULL;
        aWandererB = 0xDD59C8FCFC4A3BA9ULL;
        aWandererC = 0x981E8D8DAF90DC44ULL;
        aWandererD = 0xDA24379AD666F6FBULL;
        aWandererE = 0xD88D0155B5C563A9ULL;
        aWandererF = 0xE58ADF79DEF99B4EULL;
        aWandererG = 0x9D877ED0E02BCB68ULL;
        aWandererH = 0xD594B6F3BFC21786ULL;
        aWandererI = 0xB63B9E2C69147B83ULL;
        aWandererJ = 0xB8C239D89EE610CCULL;
        aWandererK = 0xC8DA18539BB53378ULL;
    TwistExpander_Altair_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB4CDEEF6FADDB976ULL; std::uint64_t aIngress = 0xB62DFD6E7CC08FB8ULL; std::uint64_t aCarry = 0xF64EE2FE0EED48B0ULL;

    std::uint64_t aWandererA = 0x91BDE118AEA9255AULL; std::uint64_t aWandererB = 0x974CCE148231F66FULL; std::uint64_t aWandererC = 0xAE999421A445922DULL; std::uint64_t aWandererD = 0xB9D860E64BF6CD5BULL;
    std::uint64_t aWandererE = 0xB092EBFEDFD0CA53ULL; std::uint64_t aWandererF = 0xBA56FDB2AB005917ULL; std::uint64_t aWandererG = 0xAFA7FE7D9130197CULL; std::uint64_t aWandererH = 0xC630BBA8FE594BACULL;
    std::uint64_t aWandererI = 0xCF78469534EDBA16ULL; std::uint64_t aWandererJ = 0x9F76707C61974FD9ULL; std::uint64_t aWandererK = 0xEE5251D62F56C950ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x94E3D06BF432B8B2ULL;
        aCarry = 0xEB2BAF55EF915475ULL;
        aWandererA = 0x99E3085173A68DEAULL;
        aWandererB = 0xDD4FF0DD935B2A80ULL;
        aWandererC = 0xA62FF0CE967E499CULL;
        aWandererD = 0x8A87845FE58282A9ULL;
        aWandererE = 0xFC4858BB004FFF81ULL;
        aWandererF = 0xF563B2AB4093F511ULL;
        aWandererG = 0xE61EB82388D34713ULL;
        aWandererH = 0xF095136C266F43F0ULL;
        aWandererI = 0xD84E55915AD036FBULL;
        aWandererJ = 0xB8DEE177FCCF335DULL;
        aWandererK = 0x8E6206FCF314EC0EULL;
    TwistExpander_Altair_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Altair::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC167801BA95E310EULL;
    std::uint64_t aIngress = 0xF96D4F23829526BEULL;
    std::uint64_t aCarry = 0xEE0D9120381CF5F2ULL;

    std::uint64_t aWandererA = 0xF26CC67B086B346DULL;
    std::uint64_t aWandererB = 0xAA240013FE90875CULL;
    std::uint64_t aWandererC = 0xBEF80998F3C62B04ULL;
    std::uint64_t aWandererD = 0xE6039A850664C535ULL;
    std::uint64_t aWandererE = 0xDD34D7F3E4D6A4C4ULL;
    std::uint64_t aWandererF = 0xDC241B7575B3738AULL;
    std::uint64_t aWandererG = 0xCB195B515023EF10ULL;
    std::uint64_t aWandererH = 0xE43782AFDA10D5D9ULL;
    std::uint64_t aWandererI = 0xCEFCB03428234FAFULL;
    std::uint64_t aWandererJ = 0xDD949EB137EB1E69ULL;
    std::uint64_t aWandererK = 0x8298D7746FF87AE1ULL;

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
    TwistExpander_Altair_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
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
    TwistExpander_Altair_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 7 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 948 / 1088 (87.13%)
// Total distance from earlier candidates: 5751
void TwistExpander_Altair::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 695U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1822U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 599U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 5U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 880U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 979U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1299U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1505U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 962U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 512U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1212U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 559U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 919U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 793U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 331U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1855U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 729U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1205U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 494U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1273U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 561U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 560U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1075U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 210U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1627U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1486U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1891U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1731U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 171U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1156U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 765U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1705U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2039U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1775U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 102U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 479U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1462U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1236U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1222U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 46U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 786U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1936U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1970U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1626U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 379U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 611U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 267U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1628U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1902U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1248U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 819U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1758U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 239U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 766U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 265U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 768U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1081U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1510U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 51U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 305U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 931U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 856U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 462U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1679U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Altair::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD0FBCA165EF720B8ULL; std::uint64_t aIngress = 0xF58E293926656DE5ULL; std::uint64_t aCarry = 0xFB51110E873BE824ULL;

    std::uint64_t aWandererA = 0x8B5E976B56CBC098ULL; std::uint64_t aWandererB = 0xA7BF00C3AB8DAFA1ULL; std::uint64_t aWandererC = 0xCE16B70AEB454120ULL; std::uint64_t aWandererD = 0x997F073AA67D0F05ULL;
    std::uint64_t aWandererE = 0x9098AA6913A5F39FULL; std::uint64_t aWandererF = 0x87A97C662883FF4CULL; std::uint64_t aWandererG = 0xD3577B101790DA5CULL; std::uint64_t aWandererH = 0xA1B1DFCBCD13CFD6ULL;
    std::uint64_t aWandererI = 0xA643D44265E8503AULL; std::uint64_t aWandererJ = 0xCC29AB3771777041ULL; std::uint64_t aWandererK = 0xDBE13ACCDD7E24EBULL;

    // [seed]
        aPrevious = 0xF344F65DE16010A5ULL;
        aCarry = 0xCECA708ABC4F5BF8ULL;
        aWandererA = 0xFE1D59A3FB1F043AULL;
        aWandererB = 0xD61DE22523E95268ULL;
        aWandererC = 0xDF574A0C34C464C3ULL;
        aWandererD = 0xA9586AEB0A4683EEULL;
        aWandererE = 0xAE42F8D2670F55B8ULL;
        aWandererF = 0xA31F870AF3FBFF05ULL;
        aWandererG = 0xE4B5A2770A88D511ULL;
        aWandererH = 0xDB5DC0FB80C3D7ACULL;
        aWandererI = 0x8E516781A9663866ULL;
        aWandererJ = 0xD0E5A1DB8BAE4E3AULL;
        aWandererK = 0xB0DBFCC983347F3FULL;
    TwistExpander_Altair_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
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
    TwistExpander_Altair_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 7 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 3400; nearest pair: 508 / 674
void TwistExpander_Altair::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4142U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3374U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7919U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3909U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1277U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5189U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 643U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3875U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4179U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5573U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5405U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 960U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5682U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1397U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2976U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2576U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 838U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 595U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1360U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1280U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 168U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 404U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 44U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1483U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 57U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1955U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1364U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1045U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1708U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 804U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1987U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 433U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1911U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 7 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 3392; nearest pair: 509 / 674
void TwistExpander_Altair::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6020U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 832U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2216U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3124U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5264U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7858U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2500U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4912U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2467U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 337U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2376U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7359U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7599U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4013U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 975U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 494U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 245U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 710U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 279U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 684U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1891U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 618U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 741U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 184U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1696U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1411U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1921U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 305U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 471U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1819U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1504U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Altair::kPhaseASalts = {
    {
        {
            0x0704A2AE0073A29FULL, 0xF75E92BB31350E49ULL, 0x1DCEE0CB4C606397ULL, 0x1A3EDD3A3593E894ULL, 
            0x5C8B5528AE31BC7EULL, 0xD33F648FCBEE8E4CULL, 0x0C1425D8D250DCECULL, 0x68C166CF2C983067ULL, 
            0xE74D84E8ABE4C630ULL, 0xCB79F265D451DDF4ULL, 0x2B7DEE23CA70E112ULL, 0x05C65B346DB4827FULL, 
            0xF0905E25837A7AF5ULL, 0xB5E983A7A6327AA1ULL, 0xE94A9A08E279BFC6ULL, 0xDFFBBF454A6E1B34ULL, 
            0x58F7A357E5BD34BCULL, 0x5A2A911A9FC9FA7BULL, 0x464B788754FFB517ULL, 0xA86C325B9C923244ULL, 
            0xDD7557BFA02D3827ULL, 0x420F1D02DAA63E29ULL, 0x0051DB4B6076CCF5ULL, 0x71D8DC4CF0C2567DULL, 
            0xB05E4F14ECEFF614ULL, 0x3FE559BD1D758F21ULL, 0x75952BA7908F8471ULL, 0x33A615B848B20CE1ULL, 
            0x234AD7007007AE2DULL, 0xA9E4AB453BCE4BF9ULL, 0xC90D1BAA0C7BA18EULL, 0x91A0810B6AE1956AULL
        },
        {
            0x53FFB9B562BA1094ULL, 0xFDCC5811EC24184FULL, 0x1E1B825FCA618B6DULL, 0x2633595FD238F56DULL, 
            0x17F1CA0E3658FF50ULL, 0xF4096BC7D6E0CB10ULL, 0x994277CE871F6F1DULL, 0x749EE04321F14DD5ULL, 
            0x1E97950E25945001ULL, 0x9801D30D8C882A52ULL, 0x041D413324780BB7ULL, 0x1BC0E3DF93F50667ULL, 
            0x20F69C5C132E0020ULL, 0x1720B87EFEB78051ULL, 0x5D9A93E8D6F4A5BBULL, 0x0932049B0A74A088ULL, 
            0xBA653E8ACC09A76CULL, 0x1FAF3D8C35281217ULL, 0xC406D3E9E7FA1480ULL, 0xCA9F32AD687CA65CULL, 
            0x0586ED19E849C53DULL, 0x3E839025950700D9ULL, 0x1BC6591056304EA2ULL, 0x92EF0B850F2429AFULL, 
            0x7738D86E4E6930A1ULL, 0x4F3E2EB46E13BF0AULL, 0x2131A1C658F377B7ULL, 0x9149583452E64DB4ULL, 
            0x7D275217B7D9D046ULL, 0x40BE7779DE8ABFFCULL, 0xA5D6FA866ED5DECCULL, 0x402DFD127A76FBE3ULL
        },
        {
            0x5C7C0E1DC61DF718ULL, 0x08A4CC60E609D809ULL, 0x064DA333342BDA72ULL, 0x8A949902CF711AEDULL, 
            0xD31FF1F9047768E5ULL, 0x3035205B6BE6EBB3ULL, 0x35EA48DEC1FB694EULL, 0x67C54A7256C62BC9ULL, 
            0x79A35783B470F008ULL, 0xBE95D8782EEB3386ULL, 0x60E6103AC4CA90A4ULL, 0x42098FF499F2A9B6ULL, 
            0xE72E1CDC4C08872BULL, 0xD8E5F3EBD70E0512ULL, 0x3C8A4C9EC514DCB3ULL, 0x4BC49F613A2E729EULL, 
            0x7ECF9F359BDF0515ULL, 0x1F00E0266A1CA69EULL, 0xA4E2F63D2E64AC53ULL, 0x13BA582164254F1CULL, 
            0x6A90CB94251558BFULL, 0xD8287745D3291FCFULL, 0xE93C6EAB8053DBC0ULL, 0xE77E8FA2AF653E77ULL, 
            0x952F39B3A2E49D9BULL, 0xDA07B89EB5BE8FAEULL, 0xE978A2E2B2E96044ULL, 0xA28EA53D05786F61ULL, 
            0x141964E5287F4B03ULL, 0xD1521C3471F1CD59ULL, 0xE57345896DB13F15ULL, 0x13C1621E3596118FULL
        },
        {
            0x350952E7A13A7881ULL, 0x380D4B162A072D50ULL, 0xF5245C39A6BF63ACULL, 0x706A00CD5D601775ULL, 
            0xCF28362C40594265ULL, 0x0AF93E9E9937C1F6ULL, 0x53985E4B556AF1BEULL, 0x0732DE63958C0CB1ULL, 
            0x061EDC7957A593D7ULL, 0xEFAC68CD2C3C88B4ULL, 0x5677F4878CC5AF1EULL, 0x6AF5BBD5990A5D67ULL, 
            0x96C28CF4611FECEBULL, 0x4A311EF2EE56B805ULL, 0xCF3D77E5DDB52E36ULL, 0x79B6D111FC3906B0ULL, 
            0xEE5427F81C337429ULL, 0xDCE4A6FC16E5D2BAULL, 0xF3FCCAD06ECD1E95ULL, 0x193DC04BCFED4EE7ULL, 
            0x4DF171E8F4443D10ULL, 0x6AA72251716E2103ULL, 0x49375FD234DC36B2ULL, 0xDEFB76404D3D8D55ULL, 
            0x0D57E37E1DD6A9CDULL, 0x1EE504EF35EE5EDDULL, 0x04561BE1A3A16A25ULL, 0x9A660C0BB7C8DFB9ULL, 
            0x93CE03DE013E67C3ULL, 0xB8D881A65DE8A35EULL, 0x7DBF4F8F2C278E2AULL, 0xF8442BAFE5ED7CABULL
        },
        {
            0xA3735C08460783F0ULL, 0x0BBDBD7895CCB5ECULL, 0x3CB61A8AB88130F0ULL, 0x19B68AB2407E1236ULL, 
            0xF7B9ABA88C26D9E1ULL, 0xB6A1347F984974C0ULL, 0x2AC4E0D06DAAB79CULL, 0x9C682AD81F9B18FDULL, 
            0x15747ECA0BD07C68ULL, 0x602ABEFF656052BFULL, 0x395EF72217059F75ULL, 0x2B5C60A008D8EF32ULL, 
            0xC5E5A3E240D0E369ULL, 0x36F990073664E48BULL, 0x46D219E42BA3FAD7ULL, 0x245BEEF499247CC3ULL, 
            0x1CAB3EFE9AD37E10ULL, 0x25537FCA75518D62ULL, 0xD779C1F45E5E0492ULL, 0xA9AD122822835D46ULL, 
            0x6E7A1F52820876A7ULL, 0xEF41860ABFB63A39ULL, 0xB53A2A0BDE044A6BULL, 0x33DF0EAA31ED6581ULL, 
            0x77BB53AC991AB010ULL, 0x7CD7A1F0491AD908ULL, 0xB830B261311EA42DULL, 0x4A2D018502426AD4ULL, 
            0xE86BCAA99804594AULL, 0xCA1383C739A253E1ULL, 0x5AC481CA2A3FD729ULL, 0x9779BBA9E6484029ULL
        },
        {
            0x4234A76C7424BDC0ULL, 0xA8C042C5019EA946ULL, 0x8D5F617A5E7590FAULL, 0x99202E8A0817450FULL, 
            0xE0D052AF59B2224EULL, 0xEF7D741E80CD33D5ULL, 0xC04F9AFD5A659385ULL, 0x38032C40A4DAFB4BULL, 
            0x19DFE8E59B2ADCD0ULL, 0x06D15833890D2368ULL, 0x22892A58A725C9C0ULL, 0x8C437EDA2D85CC12ULL, 
            0x27311ADD25345AEDULL, 0x7E0B9CD1F71E9AE4ULL, 0xFE537AF43C80D4B9ULL, 0x98B7B91555E16CE5ULL, 
            0x5A6CC73AD870D2EBULL, 0x8381A60286B1DC3FULL, 0x74F4A6D5E1378312ULL, 0xCACA7B42884C7560ULL, 
            0x97704E43F96E2300ULL, 0xF872CB3CD70222CAULL, 0xF1B01339B7FB8BECULL, 0x5664D1DCFE498188ULL, 
            0x07E208840797744BULL, 0x25AE0F19196858EAULL, 0xFD5CB3908AAA54D8ULL, 0x38D425B10498EBAEULL, 
            0x625F58E363A319BEULL, 0x010EDF5E3D9E0B63ULL, 0xA9DF58FB6B4DAB89ULL, 0xE52AA4257D01A1C8ULL
        }
    },
    {
        {
            0xFB5FFD6E58AAE2D7ULL, 0xDB047952A5161BE4ULL, 0xCF8090BFA019F375ULL, 0xC10B81EADDA48453ULL, 
            0xAE7236687D9FCCAEULL, 0x3EB287094FB92198ULL, 0xF73123E60A51AA48ULL, 0x2B380B9820E0EC4EULL, 
            0x4A08A02505C3C507ULL, 0x4B27B40260EA6588ULL, 0x3CE13EF633F45273ULL, 0x65BF54C5DAF764BEULL, 
            0xC4A3B17769DABFB6ULL, 0xAA2E6693FAD8173CULL, 0xB5A13DFCEEA62A02ULL, 0xB2D11DCB206121C0ULL, 
            0x671E06C8E206ECB5ULL, 0xC03AFF973A3DA1D5ULL, 0xB763892977EB333EULL, 0x89C031FA59B12021ULL, 
            0xE84CD0D56E024B4DULL, 0x9BDE7BEE58DCADBFULL, 0xE964CB5B884316B5ULL, 0x399A418B36450D28ULL, 
            0x2E3FEB3E41A33773ULL, 0xC1B507FD496A7959ULL, 0x36D375192209A6BAULL, 0x7C513E4D6D2841D3ULL, 
            0x7A3078F8AD620C78ULL, 0x3DE39C6F97307F27ULL, 0x89F37E09D5A283ABULL, 0x5CFC37A529FF0AD6ULL
        },
        {
            0x49269A96D5BC34F0ULL, 0xA4C0AD51C9D25678ULL, 0x644522B4BC912545ULL, 0xCD441D06DE06727FULL, 
            0x56D8CC2E65D69486ULL, 0x509FAC061B52837EULL, 0xAE91735FE1F23143ULL, 0x0A9DF15845C2EDA5ULL, 
            0x3B501D06BB5EFF81ULL, 0x5219EA4B31B6775CULL, 0x255779488A06D636ULL, 0x976678AA44F9CC24ULL, 
            0x81B8492ADBEA873BULL, 0xEE824BA5E6E3D430ULL, 0x69BD68F12B33651AULL, 0x2E59A535BF61372CULL, 
            0xF514A591B21D606AULL, 0x69A2F0E62F4D7B3EULL, 0x1266153B8CCEFB43ULL, 0x82E3EF90E65564A3ULL, 
            0x93FDADB0F6F141FFULL, 0xC47D63A22D0B1E28ULL, 0xAA1BEC78D95775F7ULL, 0xE5A64C6F1F770CF3ULL, 
            0xE13D19DB719E48D9ULL, 0x7015867068ECB909ULL, 0xEE70A697CC397680ULL, 0x28D95DEB2BD68E9FULL, 
            0x685281C729127F9CULL, 0x0445C9593251957EULL, 0xEB5BD6F3D35A11D8ULL, 0xF14B1B90D5054928ULL
        },
        {
            0xF41D7D8C7D796F08ULL, 0xACC819EE1A42FDDCULL, 0x92EF97B462EEC819ULL, 0x361EA707FD389DECULL, 
            0xF7E5750ADAA030C0ULL, 0xE1CE0B6AA1DF982CULL, 0xFE80444F1935E7CFULL, 0x186E0E0832833AE1ULL, 
            0xA5BB29344FA9223EULL, 0xA7DA871947F6BCF2ULL, 0x941C75E3038D4AF6ULL, 0x2C9F92CD88448837ULL, 
            0x055366B96D20E850ULL, 0x4A88DF9EB64E4B1EULL, 0x31E6D6D27866A31CULL, 0xEB8FEE66E579F4A0ULL, 
            0x94305CD7D46EA209ULL, 0x53A4C8F8AA7027A3ULL, 0xABBA4E4B3951EEFDULL, 0xF5578F91ED8D05F0ULL, 
            0x6216CC0D6148679DULL, 0x379268E127A1B47DULL, 0x5A7DE069536B9969ULL, 0xA92C07FB7E3C9CBEULL, 
            0x29E815D9C3408B5FULL, 0x3507BED1C8A41062ULL, 0xB2165315045CB0C3ULL, 0x622E3BC0F9FEA5B3ULL, 
            0xC3B61A9B3E52B46DULL, 0x4CFFE5256370E4F4ULL, 0x66BCC8964D826331ULL, 0x64A7F7E4C16E22D1ULL
        },
        {
            0x0099DC690E6776DEULL, 0xB19B92FD2329D582ULL, 0x547EACB82B7760EDULL, 0x99D192F7E36D58C3ULL, 
            0x0D4F3B04D5D005AAULL, 0x2B96B40CF8BBFA55ULL, 0xDB2A7AD031FCCE6BULL, 0x76FB7FF5BDEE00DAULL, 
            0x08C96AC9E8885964ULL, 0xCAF74F95F7D80354ULL, 0xB5ED42A671DE247EULL, 0xA5E363A143165382ULL, 
            0x023FFB1DD56204C1ULL, 0xE3AF51446F65A98DULL, 0x0DE79BF3C4DBA33CULL, 0xCA03A6DCD1C370A1ULL, 
            0x488B4DBA95846303ULL, 0xA71F60564D6A814CULL, 0xB9104C904F2384E9ULL, 0x53128E008E553256ULL, 
            0x5280F77AE9551681ULL, 0x87017AD3BD0AC623ULL, 0xBA20649CA47662A6ULL, 0xC244D7C66A455A37ULL, 
            0xBB8D15154E200C4FULL, 0xB1D6535DFE874A6FULL, 0x0C956C9CFA1727F5ULL, 0x30FCBD1F8DF5D9A7ULL, 
            0xE89E8576D445E33BULL, 0xE362759815E45297ULL, 0x2CBB152F42BB0C06ULL, 0xCE312C24D9F3CE51ULL
        },
        {
            0x47652D4C777DCD13ULL, 0xB8803EE474029040ULL, 0x55AE402028D10F0AULL, 0x57543B7922A3FCF8ULL, 
            0x5FD82DF6A18E9464ULL, 0x6A13BAAC26D4FC98ULL, 0xB7536E625A6E563EULL, 0x626C40FF1A385B02ULL, 
            0x4FE145548E1DFC1FULL, 0xAB9C3C5D5EA6F2BFULL, 0x83B8271F4E552A8CULL, 0xF868DC818589207BULL, 
            0x1C29DCFAF7BF1F88ULL, 0xD7603B2A5905CE9AULL, 0x41AAC8AB1A216E29ULL, 0x36B5B783FBE86718ULL, 
            0x14F900B0CA5CA4A0ULL, 0x7ABE65A4130BF13AULL, 0x737927BAB49CD0DDULL, 0x5C68C9BCC29B645FULL, 
            0xC590CDEC8B5A2E60ULL, 0x471B5A7DD928E6BFULL, 0x214D0A9B2C1C5360ULL, 0xC39A4B6B745642BDULL, 
            0x62EE8FCC90855332ULL, 0xF5B95EFDE257C78CULL, 0x19D4A88906AADDF3ULL, 0x46D87A324249BAD9ULL, 
            0xDFF656DD7BE2F535ULL, 0x3AE3F91C0AA73CB2ULL, 0xA34D20A664BB439EULL, 0x3DFC4A9B8DCC1D63ULL
        },
        {
            0x5CC385678857DE15ULL, 0x2FD64050AD1929E4ULL, 0x19F159DC207C83D5ULL, 0x8FE2C4EA09DDDD35ULL, 
            0xB2F2C7CE31462806ULL, 0xDFAE2D7618B559D4ULL, 0x4F347A360FA10E9FULL, 0x25FE55B60AC25D28ULL, 
            0x9DDF26E4DE6A7FE3ULL, 0x3F76974B33FEB4EFULL, 0x2BEC004EC91400F3ULL, 0x75E99EC33E1DF219ULL, 
            0xC78342404A3989DEULL, 0x2A67CD4B664A7F56ULL, 0x1BF7E390160D35BAULL, 0x250EE037D587EFBAULL, 
            0x328953DADD69E12BULL, 0x70D8CEC4ED35C68DULL, 0xA289AE0644580F1AULL, 0xC800E73075685196ULL, 
            0xC98298BAAEFFD3E3ULL, 0x01F64F75F866DA49ULL, 0xA0BDF7EC0FB359F5ULL, 0x480D2A56000A964BULL, 
            0xF51A026A1942E25DULL, 0xEB28BB4805462F56ULL, 0x38F184E14A1BDE37ULL, 0x857360B7ABBB2C21ULL, 
            0x415905434E369AF4ULL, 0xED32FD1AFE28421FULL, 0x4E69A38084865BE4ULL, 0x5376F55C80E76E26ULL
        }
    },
    {
        {
            0xB188DEE6287C545DULL, 0xBED612C9A38A45C1ULL, 0x5EF903460573F349ULL, 0xEC1FC416BB2C47F2ULL, 
            0xDCFA9920A72491DFULL, 0xD7CC7DDC1781BDF5ULL, 0x0FBF5E389A36057DULL, 0x35324CF5618921FCULL, 
            0x8BFADAA4238EE9D5ULL, 0xEC57E83A2FA9D8E9ULL, 0xC5B12409972B9CDCULL, 0x4E2745C9C8B96779ULL, 
            0x3656146F28BA5896ULL, 0xFD9F8EE01E903F23ULL, 0x915F9F08BD84B296ULL, 0x72A2F3337811502EULL, 
            0x493F8D0CC57790D4ULL, 0x84B5ABF40FD11DA1ULL, 0x62A6717C4B8F6AF6ULL, 0x4EAF0D01631BB185ULL, 
            0xE8A5B332820745EEULL, 0x4FCD86781A7B1A11ULL, 0xCF846A168B88A0B3ULL, 0x86CE6FCFA4E5694CULL, 
            0x1E2D6F41BC01608DULL, 0xE34A25C9FF79A7F4ULL, 0x17F159EB5EBD0CFBULL, 0xAD090B541A723D57ULL, 
            0xF0F44E5C23FACCEFULL, 0x4C51FCF6FF428099ULL, 0x2F693514797A94DFULL, 0xE4F0237CFE65341CULL
        },
        {
            0xBD4805638F87CA5AULL, 0x17DE7088E162716DULL, 0xAFBBD99EFCD41830ULL, 0x2EA61B72CD1185A8ULL, 
            0x96ADA129C38901CFULL, 0x2D8F017CA1F50A77ULL, 0x118A0C14F500156FULL, 0xAF9F96767AAEAEC5ULL, 
            0xC35209FF5A2C5714ULL, 0xC38522421683BC3EULL, 0x9E18EE8BC3EC13D6ULL, 0xA5B5226E45A75DCEULL, 
            0xAF44B0789953B78CULL, 0x90B0BEF7F843D40BULL, 0x41DB8E6A478D14E0ULL, 0x563502FDA24DDBCBULL, 
            0x8C6370428FF48C39ULL, 0xD9E1E1B7528CA924ULL, 0x999060E39DCA0FFCULL, 0x61B3E753BD35C1C6ULL, 
            0x01DBE62EC8BE2AB9ULL, 0x0BD42722ABAE4ED2ULL, 0x681D440D59B16750ULL, 0x76F21A24515F040AULL, 
            0xBD7C49402CFD96EFULL, 0xBA67CB5A2435416BULL, 0xC25BC3D2AF1B8A48ULL, 0x5952CC8986F4BF48ULL, 
            0xB1000E7D91BB5793ULL, 0xA92F229BBA54EC75ULL, 0xD571AFEB1077B486ULL, 0x1B124577620C2E50ULL
        },
        {
            0x024035EEC11240A4ULL, 0xD5C6D7930F8E6DC6ULL, 0xA4DF29ED044B4D13ULL, 0x77984A53FC7711F9ULL, 
            0x2963FCC9131A3417ULL, 0xFFA6CDFA65AC9052ULL, 0xE50F0F4CA0126E16ULL, 0xB079F631F0C0E6C5ULL, 
            0xDC04006594ABB976ULL, 0x5395F419388293AEULL, 0xD46B87BD5E630F99ULL, 0xE0BB05DE1DD935B5ULL, 
            0xCB394A13104D18A3ULL, 0xF6D1C734413983BDULL, 0x4B5215D092E1FC79ULL, 0xEF66C5E2226CB638ULL, 
            0x313CC2628267B7B6ULL, 0x17365AE8AD807A22ULL, 0x68853B326AD62ABBULL, 0x440A92BB243CC05CULL, 
            0xFFCBAEDE312C7333ULL, 0xA20CF0FDBC866BF0ULL, 0x023EDF83A1328ED8ULL, 0x1E69D7992CCCE3A1ULL, 
            0x8CDDAEAABC7620CCULL, 0x315EA6EFA1B54760ULL, 0xBC313279B4BCA1F7ULL, 0x7EA04744ACBFE761ULL, 
            0x651FDA03BA9594DEULL, 0x04C82EF816371E12ULL, 0xE6E4934BB62EA726ULL, 0xBF796E8268CF92A9ULL
        },
        {
            0x87911168100EF637ULL, 0x811FB35F5B018DE3ULL, 0xD0DFBBC2AAA26609ULL, 0x2AFD33E073B656ABULL, 
            0x1DE0CECFC670059CULL, 0xAE943099A87C9686ULL, 0x100548D45692ECB5ULL, 0xB43331FA8DB9DDFFULL, 
            0x71666BE9B0117559ULL, 0xDCF509A60363F6C3ULL, 0x2E135D78DDBB3A8CULL, 0x0CD39C19F8511195ULL, 
            0x814F6588F3E3099CULL, 0x99C7F315857AFC5FULL, 0x230B915554B77678ULL, 0xFAE57D743BED72DCULL, 
            0x0042C230CF9424FBULL, 0x6669453F4FD1C318ULL, 0x223AA9DA56BA7DDCULL, 0x207201F44B3B01A7ULL, 
            0x0883D2A056312CC2ULL, 0xF946B50A7628A41FULL, 0xECEB8E4488BC8A6CULL, 0x215490A145045E6AULL, 
            0x9A0E977EE3197DECULL, 0x34C87704848EE765ULL, 0xE4239C44FB6E6D44ULL, 0xB49D9A882A6760B2ULL, 
            0xEF932D8F1DC4951FULL, 0xB04722F491B07F1EULL, 0x66E0CE66B56A06D6ULL, 0x28E1582D2699A330ULL
        },
        {
            0xC2DCECEF781765D9ULL, 0x7054A6FBBF1051FCULL, 0xCFDA387228054A33ULL, 0xA7DB49CB5A7925EEULL, 
            0xD6C5AAFA806B639AULL, 0x0CBB4D97EB958898ULL, 0xA7EB5F9C986572ADULL, 0xDEC7F2A0C581D1EEULL, 
            0x027D09A57D614D24ULL, 0x9DA0368B22779B5DULL, 0x513A5B5DDADEF573ULL, 0xD33AC2C97437FF89ULL, 
            0xFFB3B7E2752586D1ULL, 0xF4B352F1DCCA79EDULL, 0xA0E53D3D95522EE4ULL, 0x7849A5432D568299ULL, 
            0x1135FA759E125DB3ULL, 0x01C79CB5D3B0040AULL, 0xE73692E98C404788ULL, 0x9B5FAFEEB16EDBE9ULL, 
            0x8EDFBA0B78AA76CBULL, 0x183AB9B91F7D19DAULL, 0x51424BC134B59840ULL, 0xEF11B65F2D91FE24ULL, 
            0x708166EBDC57934EULL, 0xCA17FB17DB75E1B1ULL, 0x9BAE36616443E450ULL, 0xFD129916B214D262ULL, 
            0x1637543A22B7C56CULL, 0x3E218A77FAB46DB1ULL, 0xCBF5F08E79E6C365ULL, 0x28B0D7B74F96B264ULL
        },
        {
            0xB57092B91C821293ULL, 0xAD271783A684C35DULL, 0x5A9009F478147870ULL, 0x2BEE6A07AE3BD9FEULL, 
            0xD8032A889C7B446CULL, 0x7142AA4A11633AC9ULL, 0x2CD38C725BC5544EULL, 0xA6F77582DF862EA3ULL, 
            0x050298A630E2EBFCULL, 0x8E562813BED2C8CDULL, 0xA5457AF8D661607DULL, 0x1FEDACB118AA30B0ULL, 
            0xF13057A2758194A8ULL, 0x688B144DE9FFCC1EULL, 0xD9E25FA73B462DFCULL, 0xE67D51017AC89D3CULL, 
            0x98CE87D3F50CDA6BULL, 0x78305D17A488AEDCULL, 0x21CED1D0727C03B7ULL, 0x583698A0D0697E08ULL, 
            0x4866DC0183C8EC86ULL, 0xBBFA1A9BD60A0514ULL, 0xA59D37D71709D8C1ULL, 0x4D68395EE7115863ULL, 
            0x92CA8A0E05E02DC6ULL, 0x505278E88ED3B9BEULL, 0xCD49F36D5371340AULL, 0xBD0C4DBAC80CE338ULL, 
            0x2837B2D65A4A3FECULL, 0x512A8C60258A54B2ULL, 0xD66E1515B5C749ADULL, 0x24202753CAE46180ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kPhaseAConstants = {
    0x02391982774EB36DULL,
    0xFE88BAAFA1DCE2FCULL,
    0x40834CCB4ACE7EABULL,
    0x02391982774EB36DULL,
    0xFE88BAAFA1DCE2FCULL,
    0x40834CCB4ACE7EABULL,
    0x11C817FE7C6B2A4FULL,
    0x60B3F1D58B9CC7D3ULL,
    0xD8,
    0x61,
    0x23,
    0x47,
    0x76,
    0xE6,
    0x0C,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Altair::kPhaseBSalts = {
    {
        {
            0x455242CC72C84572ULL, 0x96254B4C57819BCFULL, 0x9AD2AB844ACF8888ULL, 0xE3A34D0CD048FBF9ULL, 
            0xACF969C681931B5CULL, 0x6AC6828BE343F82DULL, 0x8D62DB37FF2A119EULL, 0xB85382DBF014514EULL, 
            0xE9CB31A607AEC11BULL, 0x7B92B89710DCFF69ULL, 0x2B9ACB5E28601DE2ULL, 0xAC39FF3F27F54E3EULL, 
            0x144B358C419D211EULL, 0x461E300A90E40D73ULL, 0x7491E115A78DA48DULL, 0x575A1E37C2188056ULL, 
            0x9CAE4BF7CDC941BAULL, 0x836BA0E51EEAF3A1ULL, 0xEFA9A557767018B5ULL, 0x6AB291BFC5684202ULL, 
            0xB376B7414F635683ULL, 0x85313809D56BC5B4ULL, 0x0A947CF6CFF8681EULL, 0xDB34D9511F5310CCULL, 
            0x9B685DA3FCDA78CCULL, 0x7768D07AA059F408ULL, 0x13089E2E40BE75EDULL, 0xE16B853802F6F4CFULL, 
            0xA4C443F3C1C8C8E5ULL, 0x9D0BC3E16CEF298EULL, 0x18CDDF294EBC35EFULL, 0xC62C0C1537698679ULL
        },
        {
            0xD50CDAB2BAAB62E6ULL, 0xB2DE33B0D749A9B1ULL, 0x91AEEC5560E4E1BFULL, 0x326AD19EF4C7059DULL, 
            0x98D35D85D22826F8ULL, 0xE833A57A8C381C70ULL, 0xD700493414687BC7ULL, 0xE64EAD9472D134CAULL, 
            0x7D924EFA8AEB41CDULL, 0x534086C9C4AC79F5ULL, 0xFE952FF42FB2D57CULL, 0x9B8A3CEF2ACE85B9ULL, 
            0xF154853A2CC2ABF6ULL, 0xBA8154D62757FDD4ULL, 0xFF34DB74EA01636BULL, 0xB0057B7A0BF4664EULL, 
            0x05A3FD40AD7FF501ULL, 0xB9CF17FA4D00AAC0ULL, 0x8E98D38CF71E39BFULL, 0xB4D7E07AD6557B90ULL, 
            0xE0527D9B9178E213ULL, 0x9B7436AB2748EF6FULL, 0x975B5E2C560973F0ULL, 0x7648159510FD8DC5ULL, 
            0x2FB0D132AE198FCCULL, 0x1E9DD9F821634532ULL, 0x240B649512B6FFF2ULL, 0x875983DC0FF781CFULL, 
            0x9CA4327377E2B305ULL, 0x37BA2284E9CB147DULL, 0xB02E14F5E04B78AFULL, 0xD3EAEDFA205D8683ULL
        },
        {
            0x72F09D154EC9292FULL, 0xA6B03A5131EA7CA3ULL, 0x31C9934C35492A1FULL, 0x10C69379D73381ABULL, 
            0x67E931327F19CE33ULL, 0x228B312F2A58574AULL, 0x5B1D29C4BAC9D36FULL, 0x6E98914264326556ULL, 
            0x3A1AA5819BB7F5AEULL, 0xF0151FFC10F0267DULL, 0xEB7591111E95A2A3ULL, 0x04CD825C7DA91266ULL, 
            0x5C0F4D47898E80BAULL, 0x8480F3569C257E9BULL, 0x50F9EE78781629A8ULL, 0x4541969B6CDE07CEULL, 
            0x23A369BE407ABDD5ULL, 0x8972579F8CD92459ULL, 0x7FED1E95452ABA89ULL, 0x1E207EE081018521ULL, 
            0xF7CBCB32FAA0E415ULL, 0xC6941731801F7975ULL, 0x254E007CD8B417BEULL, 0x431A0D82FDE234F5ULL, 
            0xFF6135F816192001ULL, 0xC9F9AB31B20A61CAULL, 0x879409AAA17F0FF4ULL, 0xCA838F5206E904AFULL, 
            0x26D93975FC022FACULL, 0x53FE0AFAB817F3F7ULL, 0xCF3431E1B56174B2ULL, 0x05A391DD35AE66B2ULL
        },
        {
            0xD3FA59C1424C066DULL, 0x2BC88168B3FFD847ULL, 0x95D718F43D52EE6EULL, 0xE4A2ECB330772218ULL, 
            0xEBDAFFA58810AE5EULL, 0xFC4B686E15BA02A8ULL, 0xEFC421C9358D13E5ULL, 0x78503EE8A0CAB0BDULL, 
            0xEC370ADB0A887B75ULL, 0xB2E85A35073CAA41ULL, 0x5AA87E927FE7555EULL, 0x337B71B116DF5995ULL, 
            0x0CF78D2F11EE1560ULL, 0x1DE0C3818C65A9CFULL, 0x2E1397C3BDB9CCBDULL, 0x616BF0B18CCF2A28ULL, 
            0xF5808B734D76D618ULL, 0x889B9218D39F4F84ULL, 0xFD2237368F4D97F6ULL, 0x3344CB580A6F68C3ULL, 
            0x22ECC6CA5AB866CEULL, 0x039710881FB0A530ULL, 0x3FDDAA1A4FD56B1BULL, 0x95005C8211271588ULL, 
            0x0EE9EC18C0B94901ULL, 0x6E15851BAEF32A29ULL, 0x6277131F645C5EA5ULL, 0x32C25FF984A5A3E1ULL, 
            0xF00097BE13276124ULL, 0x7C3B534D9FB37959ULL, 0x7DB3AC55C0DD537DULL, 0xC6FF062C4748F2D3ULL
        },
        {
            0x355E853C03E3DC54ULL, 0xA962287D960C162DULL, 0x936050701111636AULL, 0x331591200EC223C2ULL, 
            0x93426DF46599C240ULL, 0x3B1307CD4E4D5DE7ULL, 0x90C5B1C383681092ULL, 0xDB840788F1C5D34FULL, 
            0xDA115DCC92C3F942ULL, 0x61FD8EF332219F4FULL, 0xF94A458C42FA7524ULL, 0xD97C5C18A849AA44ULL, 
            0xDD0475F607899847ULL, 0x27F544ED5BB7024BULL, 0x63C28748B4B1BCF9ULL, 0x49E15F7B92155BF5ULL, 
            0xDD7EACAC3FF17D1DULL, 0xB7C2E941F5A5A712ULL, 0x21E950416480814BULL, 0x9A257528905009F7ULL, 
            0x7371C4FB3E77813BULL, 0x1ECDD72E4E015EA1ULL, 0x98EBA5F058311AFBULL, 0xF94AF744208CE58FULL, 
            0x1EDF49A0CDDC9A4FULL, 0x771F56AFBC1A0BA8ULL, 0x446124AF4BD49C15ULL, 0x002265117B4D93A1ULL, 
            0x4D80367394FE37A4ULL, 0x259037E2090F3D8EULL, 0x1AE1913F5B751974ULL, 0xA9F474569D3478C9ULL
        },
        {
            0x5D5E0E70C862F789ULL, 0xAF255139086F8B34ULL, 0x20277E22CF297237ULL, 0xF79A33052B592509ULL, 
            0xA938D36C2203DA67ULL, 0xE32F2B527BCAB09CULL, 0x7F3ADD6C5453275CULL, 0x6CDDB41DD7E82777ULL, 
            0x346A83481A0EC396ULL, 0x8897882085B46DEEULL, 0xAA1D05C0DC7223DDULL, 0x9CE2ECB3B6D0F4F2ULL, 
            0x9E67DFA41BDECCD9ULL, 0x327F2759DBE8E847ULL, 0xF2AF0E84A2338F48ULL, 0xF215C99FFC1D62C4ULL, 
            0x9C7B74248649DF82ULL, 0xF0366E510CE26AEBULL, 0x4D012C13E8FB99A9ULL, 0x3F4D7E23A5460F7DULL, 
            0x039961DFF259DDAFULL, 0x3634DFD45149F8EEULL, 0x7ABC1563B9D23EF2ULL, 0x3B964EB5C7BB5EE9ULL, 
            0x611355459B1F0E9EULL, 0x9B0B3E818625903BULL, 0xA8144A893D731D69ULL, 0x1A64D5F5D02216D2ULL, 
            0x6DB9494B50A83F13ULL, 0x6695499532D4D755ULL, 0x2BA057E80318777DULL, 0x016EE0995FD120DFULL
        }
    },
    {
        {
            0xD2457DCC1B0EB88BULL, 0xFDF3833133CEC4DEULL, 0x5A4AB8F88E767270ULL, 0x292E959C9067B04FULL, 
            0x5B8207232F7C7ECEULL, 0x76F9A2C262EC7B2AULL, 0xB2A3DEEE802E3064ULL, 0x8BFBD7A54844E5C2ULL, 
            0xF90F15105D474182ULL, 0x23EDAA8B0ED471E9ULL, 0xE7F54D44109B1736ULL, 0x419C431826E6DF93ULL, 
            0x8FECAA8A77061270ULL, 0xA570A31159F3B38BULL, 0x49907E8C96DDE107ULL, 0xD7B95CAD81C96AB2ULL, 
            0x464069896955B6F7ULL, 0x1AA5F343B13EB6EBULL, 0xDB1E3AB286E27ED4ULL, 0xF52F58222DEA8821ULL, 
            0x57B5E3E72EBA6B45ULL, 0x15C64B76AB8225E2ULL, 0xB89FE1972FFABD70ULL, 0xBDBDBBF0A2B4DCC9ULL, 
            0x47C1ED7F2827A511ULL, 0x7AD20F712618848FULL, 0xD5447A958527C8ACULL, 0x1AF497841403EF81ULL, 
            0xA884E9DE62DAD5F6ULL, 0xF60A3C8918B7E010ULL, 0x8037E800297C11D8ULL, 0x6C34596560376A15ULL
        },
        {
            0xE5FBB23E3C5A5D89ULL, 0x2DC0EDE20B5679C9ULL, 0x47B000874BE802D1ULL, 0x4C7CA2BDA3DB57F2ULL, 
            0x09D4C894F0AF5BBCULL, 0x63337C87AE236615ULL, 0xCED1DB31CCA82FF5ULL, 0xDF07702E1E7121F4ULL, 
            0xB8FF09A7EBB66B8EULL, 0xAA5BFB6643AD7F3AULL, 0x1D0C99CB2B61E9E2ULL, 0x00A5924EF6AFE0BBULL, 
            0x2BD8825AE359C860ULL, 0xC6835975D97134A2ULL, 0x2EF9D16E2AB63B63ULL, 0x4650A8B8C452DBC9ULL, 
            0x9885EB260658ED45ULL, 0xEBA1177A20B98353ULL, 0x9788A169AD90BA96ULL, 0x298AD8BEA56DE7D0ULL, 
            0x47DDE8CF6AE809D4ULL, 0x99E76557BDA69B5EULL, 0x283193A3BB73E1E0ULL, 0xAABA58C013816F2BULL, 
            0x5E10F0192C946BF6ULL, 0xBD992529173C953CULL, 0xDAAA0871F23F0C61ULL, 0x609C694B12CB2DD3ULL, 
            0xFB87AC6130671C3FULL, 0x4517E1C4A0C7ACE8ULL, 0x42309730A0BE5160ULL, 0x5BF7AF63415C6E95ULL
        },
        {
            0x93E4738AA52E273CULL, 0xAB8EBEACBF0184B9ULL, 0xE0773395EBD30EDBULL, 0x7876150B6BB8AA2FULL, 
            0xDA31A7A315589F23ULL, 0x62C4DD8C1F9297DBULL, 0xD64B262F972E46CDULL, 0x764C3756096F3FABULL, 
            0xA89B28217AEC79F4ULL, 0x74ACE63E11DA595EULL, 0xF7A239CBFFC1F6A1ULL, 0xA5A6F8ADA1660568ULL, 
            0x897B4181AD7CDB30ULL, 0xF83B4A2E7214E72AULL, 0x2EA89B0FF7C40B24ULL, 0xCB82FE0FAE4F2AFDULL, 
            0x02FC4D2039DDC84EULL, 0xCA6292BA6E981044ULL, 0x84B4985FFEDCED13ULL, 0x858FE304C82B6924ULL, 
            0xF9B690A275F2D763ULL, 0x5B1A2E7D2DBE0C2DULL, 0x69F04F3B48633977ULL, 0x0B864C54CAAA5F36ULL, 
            0x770D2F846443DB04ULL, 0xFAB5E683DD1DAAE5ULL, 0x056E1CE6ADE0AD80ULL, 0xF24E49619350FADCULL, 
            0x6FFCDEF71D9BA7ECULL, 0xA1CC032784B3082FULL, 0x015992BE2269048CULL, 0x9A3460F0B876F2AAULL
        },
        {
            0xF475AB135661F319ULL, 0x3704D1775315BC6FULL, 0xCE35292C9DF40F23ULL, 0x609947FE08EC47A8ULL, 
            0xBB9A0540A442806EULL, 0x7002100CF42A77A3ULL, 0x145BED69AB3554EDULL, 0x5BB3FADB4DA4949AULL, 
            0xD45006955B3567E8ULL, 0x51FAC839696DC705ULL, 0x8E33FB1F1CD9374FULL, 0xB1A7AFC8F31BC47BULL, 
            0x73C21C9F7B3D0EAAULL, 0xF6657D3B80E656ABULL, 0xF57F2EA576737134ULL, 0xA6CBA7B900DC01F6ULL, 
            0xFB3DBA27A594C719ULL, 0xF3925F2E7C15A7AFULL, 0xA3975F35FCBC0CC4ULL, 0x0FA696F2A7587656ULL, 
            0x28F305789D711BDDULL, 0x1319C25EAA0115FDULL, 0x98912471AD5E5AFCULL, 0x50BAE1891033D1B5ULL, 
            0x840678DB3D47C8C5ULL, 0x4F60195ED43C2CB3ULL, 0xF841B9F8A3145F4AULL, 0x0FE49DFA73CB904CULL, 
            0x8CAE9973EE6DE384ULL, 0xA85A78E7572077C4ULL, 0x65E99AD4C02D083AULL, 0xA59B9DDF78DA3A57ULL
        },
        {
            0x36F9D771A3623D8EULL, 0x72C84F1B6052A3DDULL, 0xD93F33C145E3A064ULL, 0xD5040B36DA58A101ULL, 
            0x78F98E6F070D9490ULL, 0x956475C23958C577ULL, 0x86D6380DE0E9B015ULL, 0xA4F0F37CF61036DCULL, 
            0x3EFB7D42F96AE071ULL, 0x91574B20B324BB3DULL, 0x5737CE9A98CE75D0ULL, 0x6E63057F68D4201EULL, 
            0xF8E3CF952B74D65DULL, 0x2FF434BD6B03E525ULL, 0x0946710B184C0587ULL, 0x0F28B9A55C9448D9ULL, 
            0xEC3432976F10DF60ULL, 0x89C9C67F892ABC09ULL, 0x0D1121DF13FE6B70ULL, 0x750E45BCC8114F1AULL, 
            0x93B58C07829B6AA4ULL, 0xD705D6A587041C18ULL, 0x27001FFDE00A3D71ULL, 0xB8991124E528CB28ULL, 
            0x71C777BA5DB3D19CULL, 0xBA6960C858D11FA8ULL, 0xF0C76F2EF6716138ULL, 0xD9B21F5F1AF50287ULL, 
            0x63E19CD6D4D31100ULL, 0x14ED4E2230E67C5CULL, 0x0280CCC00A485F46ULL, 0x8F0332C2B59B861FULL
        },
        {
            0x46C1AA433B2248B0ULL, 0x5C0CCAB7EC0C3C7CULL, 0xAB3E5AEEB7F642DDULL, 0xDEC6E383C0259409ULL, 
            0x0FDB3E026E7D16FDULL, 0x04DC4AF2A9F8B043ULL, 0xAE5BEA89274192DDULL, 0x0A6FF756AECDAA6FULL, 
            0x194BE37C649C0A33ULL, 0xDF58557F52AE5493ULL, 0x62B411901850DEDBULL, 0xD748488EC1502177ULL, 
            0xDD1B0CFDDEADB7AAULL, 0xD56013E6368F3D04ULL, 0x111019F782BB2017ULL, 0xA3739B5DCB716FA0ULL, 
            0xDC3B75F8FB0C0900ULL, 0x6B429EA1112FB122ULL, 0xEB2EC060196258E0ULL, 0xB0C1678B608CA5B5ULL, 
            0x4BEB9B6E731C0712ULL, 0x10E122ED638B0C6CULL, 0x5D00708300E75C42ULL, 0x09FE7B3B380699EFULL, 
            0x77B1CA85A1C38A37ULL, 0x2D175F3418CF8964ULL, 0xCC379EF956F3D54FULL, 0x7D537E1618ED9513ULL, 
            0x54EC2F1922B848ECULL, 0xB46C608167A2BDE6ULL, 0xFFFD9EBFA1804DB0ULL, 0xE4C1E93D348B19C1ULL
        }
    },
    {
        {
            0x61A5243C278198AFULL, 0xAC2ABCC51520FD58ULL, 0x83D7C6C6A4D2EB8FULL, 0x4C1E9E6547D79CEFULL, 
            0x86F059C361F2A639ULL, 0xE1024A41189A61D8ULL, 0xD79E2BA2283D038FULL, 0xD263EADBE280210AULL, 
            0x2018E05CEF53D2DCULL, 0x3D074CE2049BDC91ULL, 0xE06682CE72663021ULL, 0x6EEB8F8AE6AC1FEEULL, 
            0x7BFF9AF433D09FAFULL, 0x16B506D974EE4635ULL, 0x95F3C0F560994D76ULL, 0xB572BC5D1D4C22F7ULL, 
            0x11C71EFBB9C066B2ULL, 0xD0BA5F7EB5653692ULL, 0xC0DEEE8B283739A3ULL, 0x76616EDA0EBB24A5ULL, 
            0xD328C07AD877B0AFULL, 0x73B7B7DFF5098B6BULL, 0x7AB4C56FAB9C41B9ULL, 0x6ABFCEE7EDD05BE6ULL, 
            0xF1589237D4A1A3CCULL, 0x798DD14A4C5765DCULL, 0x5E36CBE304207412ULL, 0x954AEE20ED908F7AULL, 
            0xE927EFB5B8A9AA01ULL, 0xD7F7E295D1EBA5A8ULL, 0x37FB0A29A23AE1FFULL, 0x0B309BC50BA7A5CDULL
        },
        {
            0xEC1787AB0EB45A73ULL, 0x6598B9B6B776F853ULL, 0xA606E8E654A80743ULL, 0xB94BB11F450E2DD8ULL, 
            0x0EB28E325401FDBFULL, 0x8185978F672F7838ULL, 0x67410414F211C8F0ULL, 0xF220AD1E706C8763ULL, 
            0xC0F77138E3DDAAC6ULL, 0x36E10775CDBC985FULL, 0x7D0A8F0FCD18A77BULL, 0xD6A51F8428BF3B4DULL, 
            0xCD847971902C1D6CULL, 0x2A5D55484EC73E97ULL, 0x38B663D33FFB4867ULL, 0x719768D32D76ADFEULL, 
            0xEE88BFAB8FAD4BBFULL, 0x25F1E4A944F39B00ULL, 0x90EAA06879FE391DULL, 0xA5EDC9ECB63FA218ULL, 
            0x3486D6BDF8D3F789ULL, 0x44D27096F3019215ULL, 0x7B556CFC04FEAEA7ULL, 0xC32888166262C457ULL, 
            0x976E17E078C7957EULL, 0x7A088F566843A995ULL, 0x8342E01C208B78B4ULL, 0xD80C46257A5F148CULL, 
            0x8A39AE0215AE41CEULL, 0x9A71BBAAA12EF8CBULL, 0xC927DABE6A3C87DEULL, 0x708B8496F12E67BAULL
        },
        {
            0xF73408BA2C4C9926ULL, 0xE774BB78A8F85D6DULL, 0x0F98C2E35CDAF9C9ULL, 0x77FD2C54E011F917ULL, 
            0x5FCEAD4B4E13A123ULL, 0x0754067BCF91DF10ULL, 0x69A474F22C70F76EULL, 0x2EA81EC80B758D0BULL, 
            0x1A81F2EA57B32E42ULL, 0x9DE3D8AC4CAF7EB2ULL, 0xFB09C3E3729290A9ULL, 0x1519238E8DDF0877ULL, 
            0xBF7BC8D4E720195FULL, 0x1D2D44529162BE9BULL, 0x00233324C0FC37BEULL, 0xF222D211C31FFBC1ULL, 
            0xD4B3D3DECAC5A06DULL, 0xDBA0177ECD0C06AEULL, 0x9DCE626D7C65AED1ULL, 0x3F28DEE3B0286055ULL, 
            0xB780DE1CFCB51E4AULL, 0xF33608B438435522ULL, 0x683C4BE9E141287EULL, 0x38056C3DA9101A09ULL, 
            0x5B5B534D436C940FULL, 0x47CBB7347CB97192ULL, 0xAABC6ED112875D02ULL, 0xA56696E347D00B99ULL, 
            0x992BA4246BC1892EULL, 0x3169FA8A97E27092ULL, 0x835FAB20DA6D6427ULL, 0x15C8A9927EE450ABULL
        },
        {
            0x9DF5E6E827C383D3ULL, 0x52D02B1DDED5BAD2ULL, 0x895058EED78645B5ULL, 0xE872E9757F55BC49ULL, 
            0x9C99D9A9B0D9B6A5ULL, 0x6A0673586C6C84A9ULL, 0x2D04B1BBD141BBBAULL, 0x3E7EB9C99D4B8F87ULL, 
            0xE6186EAAC6846470ULL, 0x67B34964281516F4ULL, 0xCA5EB610FA884BDFULL, 0xCE2B5B2119E57FF5ULL, 
            0x4CFD72E69056CB6FULL, 0x46E46D059A887D88ULL, 0x314548E3E6B4B3B5ULL, 0x4ABF3BDF17E3BF58ULL, 
            0xEEA2F8595ECC08C1ULL, 0x507855A3BBCEC57BULL, 0x06838E3F3DE52D48ULL, 0x3D8421BC7FE3A075ULL, 
            0x4E4CC52C60A0193BULL, 0x480AD1B92766D35EULL, 0x8A1A4F980C122BA4ULL, 0x2319894315516A83ULL, 
            0x7BD312C7E04CE01FULL, 0xEEE6BFBD7F71FA85ULL, 0xF8319E2023B9EC1BULL, 0xD19A6F2EB03BDF7CULL, 
            0xC43148E7B1A10D44ULL, 0x1189EFE46D440725ULL, 0x4BC5D45571A6BA46ULL, 0x854CAD53DBE42D0BULL
        },
        {
            0x419F436EDA938459ULL, 0x8ACD1BCE3BAA9363ULL, 0xF783CDD4DD66C06AULL, 0xF9449C0C1764E224ULL, 
            0x8132CDCF51B92E2FULL, 0xE98F63644EE916EDULL, 0x2D4D5AB4559B1890ULL, 0x6A36D4D95F28D73EULL, 
            0xB4FA604D352FFA2EULL, 0x9D9858C69EC547E4ULL, 0xBE5F4B0CA15B5DCEULL, 0xD2F9B084B64AB1CBULL, 
            0xD208A02C16311D37ULL, 0xB3D21840C70DE0D5ULL, 0x5BDA0A4562BAD2BAULL, 0x0968ACE309B7F903ULL, 
            0xEE6E1020FC51D38EULL, 0xDAF5F72694CB34F0ULL, 0x2648A9930685AB49ULL, 0xE68F96B3030A1786ULL, 
            0xB48CFFC743BA4C9FULL, 0x411144B386E413F0ULL, 0xA779E9A1A85B1108ULL, 0xCE48DAF484416666ULL, 
            0xD6B67BC6817A03E5ULL, 0xE8A8C22F18314937ULL, 0x0D2C33438E5AFD14ULL, 0xC7E66D230E9A178AULL, 
            0x3F164C26E43FF5DFULL, 0xFA8A0F3A1A3E3F0BULL, 0x5A20D90CF226CF5AULL, 0x2D5A069061F0E8ECULL
        },
        {
            0x3CA0E8F95DD1BB25ULL, 0x3FC4802D52482099ULL, 0x3C8E9694DC723E46ULL, 0x4273A797E5854A79ULL, 
            0xBAEE400077457E41ULL, 0xCE59474E22158A3CULL, 0xA9009A39CCBE7D9DULL, 0xC88A5B7FE10829D7ULL, 
            0x070D5470370708BFULL, 0x5D83F8F84BEE48DCULL, 0x8FAE5C96072BE99DULL, 0x6E7447BCEDEF7377ULL, 
            0xB01934016081DB48ULL, 0x7E731BF89119B892ULL, 0x8D517C16A9049227ULL, 0xA978B36481BAD57AULL, 
            0xDF2A8BA98195B306ULL, 0x139B57C73500422EULL, 0xB4C43943CF1366BFULL, 0x68D27123A3E25288ULL, 
            0x5634B37BCB446C31ULL, 0x736481A6D7947CC7ULL, 0x9F2FC49FFC5FD70FULL, 0xE4F8EA04699BAE16ULL, 
            0xCDFB2B151F0073CEULL, 0x46778F090260760DULL, 0xB0EFDCEAA8F95ECCULL, 0x8B683C7EAA1C0FD2ULL, 
            0x9C61328DEB589B9EULL, 0x7024AB2774FCDBA3ULL, 0x1487EB86BD2E5E02ULL, 0xE4287AFE5A170DFDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kPhaseBConstants = {
    0x371EE767A35E231FULL,
    0xB044E4E35C5D3AF2ULL,
    0xE450E9D296D27666ULL,
    0x371EE767A35E231FULL,
    0xB044E4E35C5D3AF2ULL,
    0xE450E9D296D27666ULL,
    0x779A3BE3B4134FADULL,
    0x00DD4D9F98DBB1E3ULL,
    0x15,
    0xD9,
    0x68,
    0xB1,
    0xE6,
    0xD7,
    0xF5,
    0x25
};

const TwistDomainSaltSet TwistExpander_Altair::kPhaseCSalts = {
    {
        {
            0xD43C992B65DB66FBULL, 0x631C4FF376308018ULL, 0xD4572630BE1E44BEULL, 0xAE3A2E5BF4D9AEF0ULL, 
            0x3A41EEC0F9B06643ULL, 0x7B78A0BF6B872E6CULL, 0x80C0469C0C317C0DULL, 0x441D335857F0397EULL, 
            0xDE60D5D8E2158794ULL, 0xFFAFC7B7765D9469ULL, 0x39712BF6C0D64044ULL, 0x7053EC53F6637431ULL, 
            0x2089E3287383B2F9ULL, 0x3CAC435A7F9E0964ULL, 0xDEA0C6ACE6DCB7D2ULL, 0x14B8C53D347B6D64ULL, 
            0xEBFED3B0111CEE94ULL, 0x75CD1BE8C13844F8ULL, 0xDD315EB7405BED4AULL, 0xE86BD89ECE788E21ULL, 
            0x6AC5FCB1B8D5EE61ULL, 0x56F5E8EA789D6F4FULL, 0x13E50FC2ECD555BAULL, 0x635AB53F9D5A8ADEULL, 
            0xB684988CD39CBA5BULL, 0x66A2A984A4B75036ULL, 0x8A5DD3FF458E33E0ULL, 0xFBA6AEE4F315FA80ULL, 
            0x0D4E9D914DA12465ULL, 0xC626480FCE878F9AULL, 0x5C13C70766E2E91AULL, 0x80DF63201A856340ULL
        },
        {
            0x5ADA88873CD5297DULL, 0x2C0DD23F0DBE84CCULL, 0x0AACBCF0F2D8B187ULL, 0x26835199A7F7B4A6ULL, 
            0x27A89CB7C7A96C7DULL, 0x99845F8B8E60B925ULL, 0x463F6DCCC0CEC48BULL, 0x3E9D4C4CCF5618C8ULL, 
            0x716F3CF8395CBE4BULL, 0x82FA853B3AD118BAULL, 0x7AA376F5E569F7A4ULL, 0x1AA44E91955DE453ULL, 
            0x55EBFFDAFF65EC7CULL, 0x74B48CD32999545CULL, 0x5344BB6AE16ECEC6ULL, 0x8D6CF3F0517194EEULL, 
            0xFAD93BF5B4C02850ULL, 0xE7F709A13AF1E8AFULL, 0x51389E3C07AA33C0ULL, 0xB9D1E74087C76045ULL, 
            0x77CF41E6EFD161C1ULL, 0xCA3D2EC80D1B039BULL, 0x4FFC91E9942F921BULL, 0x709ADFEDDA3D2AC5ULL, 
            0x9EFED9E77C6B51DFULL, 0xE8B8A37CDF5DC3FDULL, 0x9D25993EFB431933ULL, 0x0B9826C861EDA896ULL, 
            0xBFB79C4663EDB8B6ULL, 0x8C52EB913D9FCCE5ULL, 0x6DBAB00435692118ULL, 0x7755BC259A3280B5ULL
        },
        {
            0x14431916217E769DULL, 0x27C9382206706590ULL, 0xA5458344C9F0CFC4ULL, 0x1C89400E7422F8B4ULL, 
            0xFDE05B23DB210348ULL, 0xB0315305455AC227ULL, 0xA250C47CAFF0D15DULL, 0x7FCCF91CD88ECF62ULL, 
            0x634EEBB8725EC442ULL, 0x77601EEFB6AC5EFCULL, 0x51EC9ACE852164ADULL, 0xE06250CC00E44978ULL, 
            0x95995CC3505C1D81ULL, 0x1C7F932C52E2E79CULL, 0xF8CDE31378868E2CULL, 0xB188AB04B1F39025ULL, 
            0xACC3B5E3F4AE28F4ULL, 0x5A89FCF94F581A5CULL, 0x65F1782D7D589B46ULL, 0xEC96471575A6CE6DULL, 
            0x762B908E2570440EULL, 0xAD47426F5F504B87ULL, 0x70F9B46ED9A1C6ECULL, 0x31248967DC32ED7BULL, 
            0x0D38175E28363A32ULL, 0xE7FBD75F0ACE7400ULL, 0x2B07E8D5C01FEE91ULL, 0x9BF7690F71D265A6ULL, 
            0x1E8E210AAFBE2F12ULL, 0xBFE48A211B1F4664ULL, 0x76C3EA24BCDB962CULL, 0xC40DBBD5AA88A922ULL
        },
        {
            0x2CCFE11B3E8A2BB0ULL, 0x58CC936260677DAAULL, 0xD87B9E88B45EDF0AULL, 0xA9F9AC560C29931FULL, 
            0x4D8D0B257724CD9EULL, 0xC9A2A18328F20D31ULL, 0xDE7DC2FFB7BB52C0ULL, 0xFCC5C78424C4E866ULL, 
            0x1CDCDE7CD0E076B1ULL, 0x6093E31A641441BAULL, 0xA25103C62595ECA2ULL, 0xD14A7D877A365666ULL, 
            0x8CE53BD057307BB9ULL, 0x0DD39CB3FB3A8F09ULL, 0xC61BCA7052D32FAAULL, 0xE48BAA635641C250ULL, 
            0x5B1265224F7DCEEBULL, 0xB788CD94F97F3165ULL, 0x39E5E730C46F98DCULL, 0xC40E854646D25694ULL, 
            0x2FB7A5D78FA04A3DULL, 0x2DFDCEEAFB1C0919ULL, 0xF6E10A55060410E2ULL, 0x2154AC6246D659DDULL, 
            0xAA0811F2D20C7E83ULL, 0x47E778C40383DE03ULL, 0x66462D6F99F2F6EFULL, 0xF694D4D01212BF55ULL, 
            0x43074E4726CC3120ULL, 0xCE635C1D9FB584A0ULL, 0x94D3A892C8A10493ULL, 0xD10B5A9D4C0F6D13ULL
        },
        {
            0x96F884DBF434C599ULL, 0x12D9BE7BF0B46668ULL, 0xCF4603C03B02B77AULL, 0x0C0EE2B43687235BULL, 
            0x002EDC743F93E76BULL, 0x16A3A481CF379959ULL, 0x8F3F9B53855B6394ULL, 0xDF978922832F9772ULL, 
            0x61846E4D4CBE34E8ULL, 0x69C1E10B5738F0D7ULL, 0xADCAA6AD408CD67BULL, 0xFD4DAEA466AAC6B2ULL, 
            0xC6DF3AB142E51CFCULL, 0x1EEC31CE6EA2CFA5ULL, 0xF7C9E11A4D968C2FULL, 0xC47C1055BFA733FAULL, 
            0x0A87C561B7C308E7ULL, 0xD5ACA6E9CA938B4DULL, 0xE3D9131FFD72D979ULL, 0x07DC769FEBD45ED6ULL, 
            0x39778DB09DD8AD6CULL, 0x58E1C0BA4DBD6107ULL, 0x9E185B40704EFCDEULL, 0xF3797CD7B932091CULL, 
            0x975636251BF9C9FEULL, 0x20CDBBAEC00712D6ULL, 0x9BFCEC6BA208D734ULL, 0xDB51E662CDBF24E8ULL, 
            0x7128105874990A41ULL, 0x0AD32C089139F0E2ULL, 0x3F2A6CEF96DD5AF6ULL, 0x066365451240FF67ULL
        },
        {
            0x3D6C86EA2178D3A7ULL, 0x839A52AC5675ADC1ULL, 0x6C5F9E8830D8E631ULL, 0x0828C11EACDD1EF5ULL, 
            0x0116CFD66987E071ULL, 0x384DC97B428208CEULL, 0xAB74146BA1542E6AULL, 0x6FEFDB618EBDF465ULL, 
            0xC1B0894387FCEC66ULL, 0xC395EDFC0F3FB588ULL, 0x2CB4B0B379D37A39ULL, 0xAAE5EB232B23936CULL, 
            0x213F9C53BBC320F9ULL, 0x6129A5923B7317CBULL, 0xB52552546C1CEE3CULL, 0x4C305EB068874684ULL, 
            0x96AC20AF1A5950B8ULL, 0xDA9A356AB551C641ULL, 0xC090617A470308EDULL, 0xBA92948F7DC9D819ULL, 
            0x71B7EA7296017699ULL, 0xD4871580CC04F695ULL, 0x6E0174AABE98A85EULL, 0xE419799D14734827ULL, 
            0x7C27E07715E8C3E6ULL, 0xD91DA56D9B89A4DAULL, 0x71393ADBBC2E993AULL, 0x83B9DAC78454E964ULL, 
            0xCC977332896A134EULL, 0xC47ED575E3362623ULL, 0x8C54ADD98B0560FCULL, 0xCB51C496BE06CD56ULL
        }
    },
    {
        {
            0x6FA1158543410226ULL, 0x0F28CBA53FA0FC34ULL, 0x38197B741456B81AULL, 0x58E8A0649F4312A7ULL, 
            0x6A6B49FCC0B1BA2FULL, 0x5AA635A5C2A4D20BULL, 0xD6B800236EEE322AULL, 0x3AECBCC2D301E877ULL, 
            0x2BBB79D584E9FCE8ULL, 0x30AA787C5D8238C3ULL, 0x4551ED9CA3C701D9ULL, 0x939F9233C94207F5ULL, 
            0x9E7B8E3B06146A64ULL, 0xB136CA4013A72380ULL, 0xC77743DD6FC5007DULL, 0xB8B5F56B08675581ULL, 
            0x6DF8DEBC165B943EULL, 0x44CC4E2D434F65CFULL, 0x8AAB25133E3B4551ULL, 0x34C53EDA79783883ULL, 
            0xE1067B84BC0A24FFULL, 0xE85E3BA14C670617ULL, 0x9CAE8053CFB65E22ULL, 0xD45ADD6D10CFEC01ULL, 
            0x0C309FFAADD020F8ULL, 0x96370056C5894579ULL, 0xB539AAFD06C03104ULL, 0x9AD66B6BC777D976ULL, 
            0xE9E7A0F4C46DAFC5ULL, 0x5A308E897C877D14ULL, 0x8420F36F621D12B9ULL, 0x25D0F6CFAF5101F7ULL
        },
        {
            0x3BA51F15BED2B2F4ULL, 0x6FAA0A7C57598FB8ULL, 0x1DB19C2156F60FE8ULL, 0xCF3DE11245532759ULL, 
            0x0B7700AE92868ADFULL, 0x08990FB9420B5C15ULL, 0x715D98222E1AD5B3ULL, 0xCDCB64E85C92DEABULL, 
            0x805B55B6FDAEB1BEULL, 0xF29BB1DEDF722871ULL, 0xBC463A2613BCC3C4ULL, 0x5E8705D81909A948ULL, 
            0x7ACBA173158B54A7ULL, 0x90AAD232B62C9ACEULL, 0x86D4F47D3BDFA078ULL, 0xAD0F2E11E9B72C93ULL, 
            0x9C0C7ECB2DEFC2C3ULL, 0x89A3C58B8CEDD53AULL, 0x0AA6482C01A1052FULL, 0xAAE552AF294DD029ULL, 
            0xD959B5CF72CCA0A6ULL, 0xADF58EBC6B6E4E8FULL, 0x5E7F219550CF021AULL, 0x9143B2A2BE168291ULL, 
            0x1BEA39FE1418106FULL, 0x373896F3F6777C05ULL, 0xE27BD9D7DCDF8877ULL, 0xE3992341DA41493AULL, 
            0x2048AA0481E4B087ULL, 0x0F246A6DC3771518ULL, 0x38FAA4FB46C03ACDULL, 0xEC7DCA625972DED7ULL
        },
        {
            0x4A82F2C818282DDFULL, 0xB9B9E5D553235AE0ULL, 0xBD63AD027CA83F68ULL, 0xE89023D5B469BCF2ULL, 
            0x08AEEF3B8C26BF99ULL, 0x4F4D1E5EB51C557CULL, 0xD1E5480AD1A30BE8ULL, 0x935662646716E6B8ULL, 
            0x564675C3E9FCB889ULL, 0xE78D8BA2F1B0FB96ULL, 0x9D3F2E1FD8CF8E78ULL, 0x754D9524973EC6CBULL, 
            0xACF4D19722B501E2ULL, 0xE2301B2762F66990ULL, 0xDC7FCB7B2A817E25ULL, 0x3C3E41FC1871B185ULL, 
            0x907820DCB9F6A518ULL, 0x94A54009749B283EULL, 0x482A6C495B7D659FULL, 0x30E8D1F52FB56F37ULL, 
            0xBC045F52E98E1B73ULL, 0xABD2936DD07BF4D4ULL, 0xEF9DD950DC246905ULL, 0xD3BFD2D0E55E73B7ULL, 
            0x2186B94E0DAD67D1ULL, 0xCAF8B578272568D4ULL, 0xC143A6A5BA40B5C1ULL, 0x664749BB4F6428A2ULL, 
            0x9110086D892940C1ULL, 0xD1AA98E139036F3FULL, 0x3AC0964306A01C60ULL, 0xA034BAA1F7FADC5FULL
        },
        {
            0x71CAD5AE2E9E56C0ULL, 0x8B35D68D94F1BE66ULL, 0x9AD9A4237EF7C6A6ULL, 0x965A215643B24E75ULL, 
            0x012758E684A8B3EAULL, 0x8CE59E39BD0B586DULL, 0xF1A5D0473B1DCC60ULL, 0x0E13EA9FBAFEE384ULL, 
            0x9B2725D3F1A28B75ULL, 0x482174FBCFA9060AULL, 0x9DB35210BF5230E5ULL, 0x3C8C7016E572C2B0ULL, 
            0xA9DC14BEEA60B49AULL, 0x457896DCDB43BD9EULL, 0xAFBBC212425425CAULL, 0xA3473614480E16D3ULL, 
            0xFCE822C27AD644F4ULL, 0x38AF6ECB8F2C5B0BULL, 0x48A8B0EFEAE9F471ULL, 0xCF780D081788FB08ULL, 
            0xA2370DE0786FA8AAULL, 0x60BFA2675A5BE54DULL, 0xE174170D782D0997ULL, 0x6F744A1BE1E6C400ULL, 
            0x86489977A448A386ULL, 0x437E3FA39497CD14ULL, 0x915E707CF850D25EULL, 0x1BDD1218AF9A30F3ULL, 
            0x1523F4FDC992F526ULL, 0xCC76C4D7482830C6ULL, 0x070D56DCD5F7AC78ULL, 0x8588666AC6C9988EULL
        },
        {
            0x4421F3C7785AFA53ULL, 0x83C75ADDDDA3831FULL, 0xB679492D077D945AULL, 0x264D26429500437FULL, 
            0x738FA8E1786D3A72ULL, 0xC79C2EA3F99AABB0ULL, 0xB237F66A22A6A2FBULL, 0xF9AF9CDB9B90E564ULL, 
            0x6FE120AE1A51E3AEULL, 0x2CA463A670329009ULL, 0x8015BB9C3473843BULL, 0xB33F50AFAD690266ULL, 
            0x727D08FBA1A5BE11ULL, 0xE41BAB7A601AB393ULL, 0x503588AD2DE2030CULL, 0x883B4A2524CF2853ULL, 
            0xBD1ED45310D93951ULL, 0x518EF081F38984C3ULL, 0xBDA081F29888E794ULL, 0x44E3A2497B7A56BEULL, 
            0xB3458818362AE499ULL, 0xAE1506C14151C149ULL, 0x550700B4A343EEEEULL, 0x39287F94DE786413ULL, 
            0x59268FDE36D7B1AEULL, 0xDAAAA215EDDC082CULL, 0x954FF70BA60B1676ULL, 0xE24E57CDB8883826ULL, 
            0xF93467D07444E6F1ULL, 0x58B9130C0F0B5A79ULL, 0x9710094078E2C7A3ULL, 0xCC998D07A8395CC7ULL
        },
        {
            0x5B7AB31D6A5B5E0CULL, 0x30F3323725AF6FD7ULL, 0x6A2716A4C6E0B29EULL, 0x0FB0914067001FCEULL, 
            0x04C16C18F419AF0CULL, 0x9BDA01C46EE4A912ULL, 0x788F80BFC2608371ULL, 0x13D62CA2BDF58C13ULL, 
            0x10D438ACFFB970DCULL, 0x9F359DF83EDE335AULL, 0xBBF49ADE505E330AULL, 0x9346649D44DDF9A4ULL, 
            0x70A8E2E9A82A3C59ULL, 0x67F6F3DB31618DD9ULL, 0x5F661503B9D8A9BEULL, 0xC6EA080DD6740652ULL, 
            0xE5C78A985D82063FULL, 0x45967A6753B92FB8ULL, 0x5CA72BD44004910EULL, 0x8058DAB39E2B6F26ULL, 
            0x68A62B65C9F66DBDULL, 0x00BA50BC0BD6F3D1ULL, 0x870C6E2D20BA4EA1ULL, 0x36F5E2FBEF73A69EULL, 
            0x41938A6985254E0DULL, 0x79418B4ECDCBAE50ULL, 0x924F75BC1C10CBCDULL, 0xF1B9ACF02168719BULL, 
            0x7F9C87CBA26CF8AAULL, 0xFAC3D2608B538B41ULL, 0x6C1D01C81525830EULL, 0x1A75238142E64A6AULL
        }
    },
    {
        {
            0x71487482788C56A3ULL, 0x6CE26D42C05C0E22ULL, 0xDF8E49F568112710ULL, 0xF396297E218CAA35ULL, 
            0x1E808585F3887259ULL, 0xEDC2DD81EFE87E0BULL, 0x0AA6B60016057B75ULL, 0x488E2DF5F8F479D1ULL, 
            0x25CD99220B8A9845ULL, 0xC2CDD039D5405134ULL, 0x3BAF8E7FFF9F8A33ULL, 0x1F70618EE8F3C1BFULL, 
            0x6903E0301F75CE80ULL, 0x92EF05004C2C47B4ULL, 0xAF4FF0659B294004ULL, 0xE1173239A0902A46ULL, 
            0x5665D007F6C725B5ULL, 0x222147A85F9028FFULL, 0x36C533FF7BAE0D3EULL, 0x8792CFA7E707FE29ULL, 
            0x1095C8B4D36BE6C1ULL, 0x7B3ED1E8A4A7E20FULL, 0x6189AB9A446B7738ULL, 0x7CE0806C77AD354EULL, 
            0x8A098BFC7D6F54CAULL, 0x54F924E46DEF16DBULL, 0x4B294DE012C87EE4ULL, 0x2D1ACF71D3277ADEULL, 
            0x211E93FE5272634DULL, 0xD9352983E1E8DA7AULL, 0x8A415D7C2033DCD4ULL, 0xF9BA3655F28F3740ULL
        },
        {
            0x1A554E6F4D509D0EULL, 0x9A65FE9F46D62ED3ULL, 0x2B4EAFA48F62C5DFULL, 0xC6D93CD9323858ECULL, 
            0x35DFD74842A4D597ULL, 0x1BC9CB6338762FE3ULL, 0x071EB8D6EEC9A331ULL, 0xB6028250B0D2CECCULL, 
            0x650E489D045E3C8DULL, 0x211A0EA9ECDAFF3AULL, 0x7752D87C1FFEFCFAULL, 0xED64E8B4774F4EFDULL, 
            0xAE02DF54AA06F02FULL, 0xE075494254CC4147ULL, 0xCCDDF8FA6768829BULL, 0x6D6F9BA7E955748FULL, 
            0x25BDC4C79B58AE1CULL, 0xA05BBAB7F9795D88ULL, 0x2301006A198B842EULL, 0x570FFE2042C63D64ULL, 
            0x676170FBAA53A11BULL, 0x411F09F47EC7E674ULL, 0x31A69729B1950FE5ULL, 0x40E699991D366618ULL, 
            0xCD80902F74C418FEULL, 0x6D55FD875B6E3E90ULL, 0x79BAF2F2B4138FB5ULL, 0x0FB5CB2DAECB9124ULL, 
            0x68EECB4D309EC9B0ULL, 0xA1F2CC03C545B48EULL, 0xDF7B01F23F982BE8ULL, 0x3AFB58EC2943A5E6ULL
        },
        {
            0x664A825178317418ULL, 0x43C644A451A44F78ULL, 0x771725D741D29B1DULL, 0xFD4276E16A8AD949ULL, 
            0x07964C21EEAE6934ULL, 0x122FD7EE9E397C2CULL, 0x1B55827627C50EAAULL, 0x913C003CDFB05466ULL, 
            0xAE155EBEF238DC4DULL, 0xB73EBE1F34EF3A26ULL, 0x2D213C2AF38E9EA3ULL, 0x71FB4BA5FDFE11DEULL, 
            0x975EA1BB358F6E01ULL, 0xA180167846398618ULL, 0xADB3B17C9AD89A5FULL, 0x684C64B033AB8DB0ULL, 
            0x73A1C91D02B2024AULL, 0x414244E3468CF39CULL, 0x9E755EFEABB60527ULL, 0xAD6F64C362E86A5AULL, 
            0x8C1985CBCC45BECFULL, 0x6A2466EA4B7D14DAULL, 0x50AFE504B53E5778ULL, 0xF514B599157C3D4CULL, 
            0x60604A547CDB4353ULL, 0x70E90E719D0DC307ULL, 0x2A2AD32B6FC10055ULL, 0xD2E061EFFDC8524EULL, 
            0x05FB34028F016CC7ULL, 0xBB5A52D306771116ULL, 0x0C913E6DE3C67EC7ULL, 0x4CFDEBA12E5D64C8ULL
        },
        {
            0x4FA65600E86562FDULL, 0xFA3C6C47B783C149ULL, 0xA9E2BE612DE2857AULL, 0xEF804F52F7CFD859ULL, 
            0xE13B04672AC4B6D6ULL, 0xCCE01ADF40F18EE1ULL, 0x35FB8464E7EAEAAFULL, 0xA8E2AE6BAA872C2FULL, 
            0x2DC77051B4AE4FDAULL, 0xAE8CD63499DEA77AULL, 0xF737A747D252CEEAULL, 0xF6AE81C8F4E83751ULL, 
            0x887EBCF948BA171EULL, 0x50F5098F710D40A5ULL, 0x84F06E1ADD9E5B32ULL, 0xE41DA10BC2D8B1D6ULL, 
            0x4ECF6CE7B75C6B77ULL, 0x8EF9586E0BE1480FULL, 0xBBB1EE98796EB448ULL, 0x90CF2CDC491BC201ULL, 
            0x81B89E543D25DF2DULL, 0xEB66B182C8BE0430ULL, 0x4115920D66242F90ULL, 0xF183FC32AD7E4E02ULL, 
            0xC5E001AB1B546546ULL, 0x83B529522BA17BCDULL, 0x50708E88142EC4FCULL, 0x56E38BDC2F9106B5ULL, 
            0xB64CAFB9CB777D35ULL, 0xD91D7260165C6278ULL, 0x19356F57AC97A670ULL, 0xDBF87014D99A192FULL
        },
        {
            0x88F9471F94D088E2ULL, 0xE201DA5AAD49D7B5ULL, 0x6CF30DBE2C9E5850ULL, 0x1E1EA5B896C68739ULL, 
            0x64DCE3331FD438E5ULL, 0x8E01F947A40D428BULL, 0xA8746B3A77E38672ULL, 0x1B0DBDAF5E1824D8ULL, 
            0x9D2FA1FE9AE60E59ULL, 0xF4068290D33E450EULL, 0x81184EF42DE6C5CCULL, 0x4133718EC60E7A1AULL, 
            0xB06B907353E3CF75ULL, 0x3ECF204D3CDE4C45ULL, 0x9EE9E6509116A136ULL, 0x5588A74475207FDBULL, 
            0xCF7D71C9D9729AB8ULL, 0xE4A681B6CB09C238ULL, 0xB365F81F8990B30CULL, 0x1F341332B8DE1961ULL, 
            0xA1E85C8F47FE1DB0ULL, 0x3C7123DE1E10BBC0ULL, 0xAFEFD0EBFAA0083EULL, 0x727219273F3C3F8DULL, 
            0xC11A9D7C2B507F48ULL, 0x4A8337F00DA9EECEULL, 0x71FBCBF2DAF479ADULL, 0x23609CF8CDA82C9CULL, 
            0xA4C32A25CC8E2098ULL, 0xF9ECEFB864729545ULL, 0x09838B23082B9F8AULL, 0x827C13C694D2A2BEULL
        },
        {
            0x9350298CE873F477ULL, 0x3B57BE9A00B048EBULL, 0x03A702367936511DULL, 0x32724370C8AEB41EULL, 
            0xC71E6DFE5BD9AA91ULL, 0xC0C8A619AD0DCE9EULL, 0x3BEE7F02F74473C0ULL, 0xF4AB5D5B6284E9A7ULL, 
            0x50FCCA0FC3D32044ULL, 0x4A2EE0E0B337F1C4ULL, 0x3DC2C602FE268BF9ULL, 0x3AAD6B16699F03F5ULL, 
            0xC709A617BB73D676ULL, 0x72184FF8C71F4CC3ULL, 0x2FFB7BF81BC590FDULL, 0x4558FCD27780A169ULL, 
            0xCDF80DF9F49E3A82ULL, 0xCCF68681203A81FCULL, 0xD3533425706649E1ULL, 0x5F0E6067F394C1BEULL, 
            0x0F0C1006299C34C2ULL, 0xF32AC003412CB1E4ULL, 0xEDA946FA34114D03ULL, 0x88D0514D98BAF0EFULL, 
            0x75BA0C0935047C52ULL, 0xA6BD665ECF2EE4A3ULL, 0x1DB11C635BCC123DULL, 0x376838C8462C03E1ULL, 
            0x14FBC1567C57033FULL, 0x72C08533CBF270FEULL, 0x2E2F2A5534DC4379ULL, 0x6BF99CDD19A64F65ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kPhaseCConstants = {
    0xAA36D4973247A8F8ULL,
    0xBCAB9B7C94C2BF02ULL,
    0xEC2ACA73419C91B7ULL,
    0xAA36D4973247A8F8ULL,
    0xBCAB9B7C94C2BF02ULL,
    0xEC2ACA73419C91B7ULL,
    0xCA3B8E2D7531750FULL,
    0x8FD12C8AB577A935ULL,
    0xCD,
    0x9B,
    0x0F,
    0x61,
    0xA5,
    0xE5,
    0x65,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Altair::kPhaseDSalts = {
    {
        {
            0xF1D63ECC45572163ULL, 0x3FB3DABD59CD8E75ULL, 0x1E942066BF0395B1ULL, 0xAEF6D8CF63B5C984ULL, 
            0xB129CB428899598DULL, 0x0D04D811815CA87DULL, 0x5F2D3D26B9DA0A6EULL, 0x16C14B38F08F0A74ULL, 
            0xAFC4752C61A7E0C6ULL, 0xA76165B2CC35AA6FULL, 0xCEFAB9D47DBB6562ULL, 0xE0CA2FC7C971375DULL, 
            0x1D46E04447A0ED40ULL, 0xB96236DBC25688EDULL, 0xFE11B1C9AA914214ULL, 0xADF801F6341BA6EDULL, 
            0x087BFA4D4D71FC61ULL, 0x59275B9405206695ULL, 0x64CA777985EBECB8ULL, 0xEB14E56A64F1E3ADULL, 
            0xA719F0B74851FD9EULL, 0xD34834AB33D14BD7ULL, 0x7463D14AD3E57854ULL, 0xB2FD6BC6BE0AE37FULL, 
            0x9E58458A7CF30703ULL, 0x448970F240C73CEAULL, 0x818F8494515979AEULL, 0x89D48BC091C32A72ULL, 
            0x00259A3FB8BEA960ULL, 0x5161841AD8F4EE9CULL, 0x2741C6CECFD80ADEULL, 0x6C3199A0B473C30AULL
        },
        {
            0x74E73FCDAB7F72B8ULL, 0x0E259A2C526D2BD1ULL, 0xDD6B797EBF672975ULL, 0x7B1D2DA65EEEA650ULL, 
            0x9A2342FD5FCD1882ULL, 0x6B0EC9BB57FE83AAULL, 0x1ADD95B5860F7FE3ULL, 0x6FDDAC15F873B615ULL, 
            0x51F862E16A71D820ULL, 0x3876580BF926082CULL, 0x2C4940C524F54EE3ULL, 0xD154B3500DDB2637ULL, 
            0x4FBE70FA1CCACD8CULL, 0xBDD146DB83A41D12ULL, 0x22BA921E0DE71010ULL, 0x19A0211FF5D2EAB5ULL, 
            0x5AE80E775AF8540BULL, 0x4C7FF36DBC8E3015ULL, 0x60ED45D58E00E8DAULL, 0xAE74B47F819BB531ULL, 
            0xFCD492974C184E75ULL, 0x58C374941953B8EAULL, 0xA7FA577C311F6B96ULL, 0xA4489618118AEDC0ULL, 
            0xFC710362AFF4C201ULL, 0x41EB7257584ECF92ULL, 0x288BF1A3862C5E2DULL, 0x415CE5F79B3E6DB6ULL, 
            0x79460E7F33C69707ULL, 0x726A1ABCA936A939ULL, 0xF04551775C77AADBULL, 0xD61A74F7FCD0B89EULL
        },
        {
            0x55D124AFDFA21234ULL, 0xE8918F5E7706AEDAULL, 0xF7BEE9990781DF71ULL, 0xC8083AAE2825AF87ULL, 
            0x71A265AA661C27C4ULL, 0x532A8976D3118A56ULL, 0x49C724DB18CD0B1AULL, 0x4D157531604B29B8ULL, 
            0xFB7A39EC10B8EAB7ULL, 0x1FFADE748B4DC7EDULL, 0xA51A95A80694B803ULL, 0xCA17B8A8E2D42990ULL, 
            0xCC8F9E5DFABD3800ULL, 0x148BFD40E2173B6CULL, 0x9B607E94C90BF507ULL, 0x2ED5A8DB7941A986ULL, 
            0xA2D520D475A498D2ULL, 0x3F8E43A533E16E39ULL, 0xA4D0516636C42465ULL, 0x0A7CC0E955B5DC42ULL, 
            0xF0A2BBCD8E73507CULL, 0x7EDADF2E27E15E3FULL, 0x49CABCF3E0524B4DULL, 0x44E31DEC87C55714ULL, 
            0x3394C4E7DC61E2BEULL, 0x7F46F91BB7FD0418ULL, 0xB22C3AC84C521029ULL, 0x0B40A25355D8AEABULL, 
            0x6CCE58334F3886ECULL, 0xC940A8101599BAD4ULL, 0x87FEF84C7ED56F6DULL, 0x6BDF0402D86386BEULL
        },
        {
            0x92EA9BF722816285ULL, 0xA735CE14683CFB27ULL, 0x3F48E837DCF20A41ULL, 0x72E044DE6AF3BD74ULL, 
            0x717D1AD20981DDDBULL, 0x70E28EFA649B051AULL, 0x067BD8AE6FE33BACULL, 0xCF30C2731ED4C0C1ULL, 
            0x6889C78FF5BEA496ULL, 0x0358D08A84AD6385ULL, 0x8A785C3FDFEEDDC6ULL, 0xEBA03263CFDEE213ULL, 
            0xCBAEF3D98071CC66ULL, 0xD1C8F0785ED62908ULL, 0x5D36E7C627B127EFULL, 0xDF7A58894C7BD555ULL, 
            0x6A3380C2E3BA1CC2ULL, 0xA91FCC2321F0E5A0ULL, 0x657044F451CB02B5ULL, 0xA6EB4E75890AC716ULL, 
            0x144A94C93015198DULL, 0x5CEE480553287D97ULL, 0xC66D512D0C33F4E1ULL, 0x23584ACF6FB97F82ULL, 
            0x05087685FB49F7E7ULL, 0xA1D254DE66A92C41ULL, 0xB216725EB9DE18A8ULL, 0x393B6B1C793585ECULL, 
            0x4A991816F56535E5ULL, 0xA5E211BF19A913B8ULL, 0x8B16609CBD157E84ULL, 0x003D89E945961F10ULL
        },
        {
            0x98A161A4CB6117E8ULL, 0x484BA78C79B5B336ULL, 0x528F32FF681B4045ULL, 0x8319990554C9FC68ULL, 
            0xB50AE2C4EC120662ULL, 0x1D5B9168B4F5C03DULL, 0xEB7025B004FC235AULL, 0x68905BE6346986D2ULL, 
            0x56F8BB2D48C5E9FCULL, 0xAFA3BC7B204864A2ULL, 0x08AD388019CD4580ULL, 0x13D25F1F8A403A92ULL, 
            0x34E1CBEA5350EA4AULL, 0x425775A79620ECCDULL, 0xD5A79F999EDCE7A0ULL, 0x3FE37FDC35E935D2ULL, 
            0xE865F6DA401F7609ULL, 0x31A4CC51E5E0E0BFULL, 0xBE0672C87D651ACBULL, 0xFEF6091DF6D0EA72ULL, 
            0x93607E54175BAE5BULL, 0x3CD891DDB0071383ULL, 0x14D5C392742AF313ULL, 0xE2E97A748F8D7BFAULL, 
            0xDB4675E6DD551326ULL, 0x0E299D03627BBE6BULL, 0x5628743EBE1CF31BULL, 0x6426D337EA4114FAULL, 
            0xEFC1D2F84BBB6428ULL, 0xC96B009CAB90B6B1ULL, 0x425B349C0E7EBA23ULL, 0x8627D23D24CE0443ULL
        },
        {
            0xA659F077AF768599ULL, 0x689EEC8B691E7771ULL, 0x2052D96633008E34ULL, 0xFCF8B5DEFDFC1D51ULL, 
            0x5188B353CDDDC216ULL, 0x2C32E87AF6FB21A8ULL, 0xE091C1345266FF1DULL, 0x0A0AE9DEE1A1481DULL, 
            0x08378D4E157DDD28ULL, 0xBEC8668C60075A29ULL, 0xEBB2AC1517B005DDULL, 0x3568C7CC6860DAADULL, 
            0x34EB4685D17804A2ULL, 0x4C37A65EEA6B37CEULL, 0x186CF742703AE2EDULL, 0xAEAB63EA2FAD7D92ULL, 
            0xE92F42260ED829ABULL, 0x3483F0A795835141ULL, 0x368AE2E1ADFC8777ULL, 0x0B1A194616A2BEADULL, 
            0x491F8A51D5533EACULL, 0x203EE083DFC3F66DULL, 0xD59D025D77D7B81BULL, 0x6B14E67BDFB7BC9CULL, 
            0x3AB685C0D61477CAULL, 0xDF925436D2ED0F2FULL, 0xD80889BD03302237ULL, 0xC95F267B319F8B20ULL, 
            0x5A4787A8CD18CC88ULL, 0x063380471030B30FULL, 0x20FFFE827B91DB25ULL, 0x941F1F2DFD24205CULL
        }
    },
    {
        {
            0xF94DE649EADF4CCAULL, 0xB5EE1420B5A4810DULL, 0xC65681842E32FD23ULL, 0xD2333C903111C7AEULL, 
            0x4C74F60E87C973FFULL, 0xE4A2705A2D0B29C5ULL, 0x388F6D5DD9957B48ULL, 0x35551A0B42895472ULL, 
            0x525E040D9804B345ULL, 0x376ACA1E980B986BULL, 0x4865F839F2F0B159ULL, 0x6C9365E082484225ULL, 
            0x91C3001D3A11489EULL, 0x97E2E92952385E63ULL, 0xFFB6FE4F32E967F0ULL, 0xE75C29AD30303F12ULL, 
            0xF9D25CFF60B931CEULL, 0xE7EE54F46F0F6581ULL, 0xCB4E220174675C6FULL, 0xB88559D03613E59CULL, 
            0xACA8882185E920B0ULL, 0xF7C7B039912F197FULL, 0xA8E2BE42308E2174ULL, 0xA1707551B79D9E3FULL, 
            0xD789B72F7A22EB2CULL, 0xD28D0E1FB4927898ULL, 0xA2C1F64E1448A546ULL, 0x9CAF344BEFB76166ULL, 
            0x397589AEDEF0C296ULL, 0x9792A6C5B9FE6BE1ULL, 0x627A50FEB1F1984AULL, 0x6887DFCA87FBA23AULL
        },
        {
            0x4B08AB99BFB35AD9ULL, 0xCB345CA395C39BE4ULL, 0x75FC42389BA2A4E3ULL, 0xE4AD896DAD232E72ULL, 
            0xA96FBFF2F3C4B747ULL, 0xC1F04537BBE46597ULL, 0x196C161491645FCBULL, 0xB15EC3749FEC0A54ULL, 
            0x42CC6AF2A4143C05ULL, 0xCC70423D5B6CC9B8ULL, 0x4E2D2D3086ECB856ULL, 0x6E32D93EF79BB792ULL, 
            0x74FF8078E32A0EB1ULL, 0xF1D8E91F24A1E2C5ULL, 0xA12CB3BC7D516093ULL, 0x9ECC9D5ED81D8D09ULL, 
            0xA8EF06D7C090C509ULL, 0x0E55A8FB9942004DULL, 0x4F44B498F6AF856AULL, 0x68D974F8D26A7418ULL, 
            0x515CF2A0C3608BC2ULL, 0x270E7DA14DB03032ULL, 0x6E52339696E02B26ULL, 0xF85F3FDA9A27EB92ULL, 
            0xC1502193576EE397ULL, 0x95C37A2E6BC42014ULL, 0xBE4473E420897F87ULL, 0x5EA3B8D5F2ADF1F0ULL, 
            0xF701A0E2BA98B3B0ULL, 0x75E0CCF2E6BC77B0ULL, 0xC7E8BB246F44CA23ULL, 0x80721AAF69556682ULL
        },
        {
            0xE16AE80BDE58F5FEULL, 0xBC3F3F61949303F9ULL, 0x6226751CF70B6E83ULL, 0xC48DDA5F17BECBA0ULL, 
            0x0E83224ACBC28D9FULL, 0x738A79F9788ABD47ULL, 0xD7CCA504235F3C15ULL, 0x8BABA7ECF1242487ULL, 
            0xEE134FC3E91A49C7ULL, 0xB77B14805E1CA18CULL, 0x06638ACE9798C9A9ULL, 0x49A9F6BBAFD95DD1ULL, 
            0xF585A3966B7707B0ULL, 0x4EFF91E7F17E0942ULL, 0x09FDD721729352F5ULL, 0xD05D85F51D1CBECEULL, 
            0x65E003D2D3D96AECULL, 0xCA110634AF7B1538ULL, 0xEAE8AE8CC63A14D5ULL, 0x5A1E7B7F3715FD88ULL, 
            0xABDB7A8098233947ULL, 0x0395D4BE93129BE7ULL, 0x821A9A1FE642F42DULL, 0x90BFE7A05C48A94DULL, 
            0x094785F8AB6E8570ULL, 0x674DA6ED3D162716ULL, 0x777A419E86492587ULL, 0x1DDCA6E02EB13564ULL, 
            0x673F7B3A3C3625D8ULL, 0x3E060EA9CD404A2AULL, 0x4C975783C97831ABULL, 0xEF5028177780F60CULL
        },
        {
            0xD078295F92EE6DF7ULL, 0x47676A2D553AE1AEULL, 0x55F92872F98B87BEULL, 0xD640A04241D15B4EULL, 
            0xFB30340275B69E98ULL, 0x7F0AE8CBED63E134ULL, 0xD588129F92373897ULL, 0x0B6403CB0C3999AEULL, 
            0x11CF49A9CCCA8F5DULL, 0x93DEDAE7A903B3F9ULL, 0x2E90C5BAB5BC49F0ULL, 0x996F00FECF9D2114ULL, 
            0x37988AACD8D05D9DULL, 0xB77DE9BBC091AD36ULL, 0x19A76A9C6EBE33D5ULL, 0x2DDA796CC57C92AAULL, 
            0x27BDC24391DE704BULL, 0xAD700C32144142B8ULL, 0x4C7F0A24BDB65551ULL, 0x05BBEB2598296BB5ULL, 
            0x91035ACD31A3CD93ULL, 0xA804FD8C59D1492BULL, 0x60D465EBD6D410A9ULL, 0x5F74094919855083ULL, 
            0xCEF620DD063A0E5FULL, 0xFC753AD8EC08EE4AULL, 0x6226F3BA042C2425ULL, 0x3F8E4DB70F3CE6A8ULL, 
            0x8BCDEC60AE0C34FCULL, 0x78AC74F8CC25CB31ULL, 0x1FF26C637332D65FULL, 0x41234A10C811D756ULL
        },
        {
            0x49BCBC23E1773C06ULL, 0x64D35BE0783C48C6ULL, 0x8004000A1E1CC460ULL, 0x8293239730770B5BULL, 
            0xF46C10155822BF76ULL, 0x060FC43F3A3026B8ULL, 0xF29864D9DE2D0FA3ULL, 0x2EF23A3B7AFFE396ULL, 
            0xC807550E77BCFCB0ULL, 0x36C3E7D8C8D0650EULL, 0xF2962E68BAA8D70CULL, 0x496E113135045ADBULL, 
            0xBDE5FFEAB28FB5DEULL, 0xD026450510865E75ULL, 0x4ED463DDC65B48FFULL, 0x714CFF99CEED652BULL, 
            0x45402ECD1B2CD2E8ULL, 0xEE660447479AF0CFULL, 0x3EA57A0722E6004AULL, 0x23FE14E0C8211CD3ULL, 
            0x709FCE55D9906C6CULL, 0x7B3D7E1EE9C11D09ULL, 0xD17ECCCCF5D6ECABULL, 0x09D88D21F918A593ULL, 
            0x3DFCB395894A4BD0ULL, 0x1064321572D82926ULL, 0xB3EB5D093DAD2BF0ULL, 0x627177A2347F23CCULL, 
            0x8D401E43F12D4BC9ULL, 0xCA04E944DDD5F62FULL, 0xC90D6B3AC68CD5ECULL, 0x9C3508A5EA895CCCULL
        },
        {
            0xA1E74D713ABE4083ULL, 0x86BE2CA28B92308BULL, 0xC40AF2A5F2A6D2ACULL, 0x8323365BFCC7716EULL, 
            0xB72C9FE0C6C8A8C3ULL, 0x9A53575A727DC728ULL, 0x14F6D87AEDF3F04DULL, 0xD30B6E0C71EB91BBULL, 
            0x73BF80784C02F929ULL, 0x688DD9894BC0C6BFULL, 0x460848F310CF91E7ULL, 0x08BFD80731D4386BULL, 
            0xDD4660025E952A28ULL, 0x450384196E047C02ULL, 0x084E2D7170EFF319ULL, 0x9E13D5F67C52393EULL, 
            0x352B9EA8EB7B5F2CULL, 0x7BEBBB4D20CB2D72ULL, 0x9B778CB20D77F774ULL, 0x2190EAA57B344E01ULL, 
            0x7BD66784D3F7CB0EULL, 0x7D28012089680FD1ULL, 0x9A4363C6F7F3A65FULL, 0x672BEEE5B5A3AF8CULL, 
            0x08D4947FA3D60E30ULL, 0x76E8B57671167ACEULL, 0x618A6BF57B45FC69ULL, 0x3D55E6C53EA64E58ULL, 
            0xC45B4040B9815410ULL, 0x4C5D650D1B3CC8EBULL, 0x4C28BBA555A99EF9ULL, 0xA2A3ACA4B79BEE35ULL
        }
    },
    {
        {
            0xE1DEE423A6B17F81ULL, 0x6C67315B0696EB02ULL, 0x2837033235BC89DCULL, 0x0DEE2520CA7EF975ULL, 
            0x555B336E70AEFFB6ULL, 0x452429F161344F65ULL, 0xB04901C077AE4130ULL, 0xEA6CB8722D27CE96ULL, 
            0x18A608885CEDF7BBULL, 0x8F5DE5F721034450ULL, 0x6153B99A83804243ULL, 0x875604E860E5CB4DULL, 
            0x7EA18EFF5E8014D5ULL, 0x8CB391123B2F9C85ULL, 0x69FB5CE6261991B3ULL, 0x80DA77BEECC24278ULL, 
            0xCEE3CB9F177122A8ULL, 0x5A344EA8CD0C9DF7ULL, 0x1D591976061662CBULL, 0x62334CB9F2F3013AULL, 
            0x5F2193942A5FABABULL, 0x46F857245989F996ULL, 0x22812BE2032275EEULL, 0xADFD60EEAC3D62BAULL, 
            0x0648306DF5A0D837ULL, 0xCC7C472BA0FCCF2AULL, 0xE3BE6C5FAF45E94FULL, 0x102A38F80426EB80ULL, 
            0x7FF645E07899DCF7ULL, 0xA20258026C905D93ULL, 0x9DF7B86BCEC1D854ULL, 0x68E3950F79C0C867ULL
        },
        {
            0x1361EA78FF322DCEULL, 0x03357C5F87DBD7AEULL, 0x57131AE6159C38A8ULL, 0xC28BE75C87746193ULL, 
            0x633A62D2C976B09AULL, 0xC4C48B50136C1C82ULL, 0x2E4AD0E796EC1EF3ULL, 0x6C1524FBA97440EEULL, 
            0x50AFE99F55690F74ULL, 0x6388772BB262F56AULL, 0xA1E0F407BC6E1EC1ULL, 0x455E05364A9F7516ULL, 
            0x6C70E7049BE0789DULL, 0x5C48763A72022526ULL, 0x3B9CB3B8D93C1C15ULL, 0xF855A7FB639FD625ULL, 
            0xA5FE5B96EA80BB6FULL, 0x8656458FF8D3E946ULL, 0xB9E47B156DCFBC21ULL, 0xF9C7B5375F9A3AB8ULL, 
            0x52D51D86A9006C61ULL, 0xDDB2D08036BD3825ULL, 0xF79B9882E055F9C6ULL, 0x3D74F37868800D78ULL, 
            0x57C4FD0885FAD0D2ULL, 0x09BBB03AC4D7E6FBULL, 0x47B8E30D1880C562ULL, 0x10DFE9011A9E7405ULL, 
            0x80C05CE33E639919ULL, 0x03E28F5203227024ULL, 0x25F18A7B06B8FED7ULL, 0x58CD05120AFADAC2ULL
        },
        {
            0xEE0A7B10ED56487BULL, 0x9FF0FC292E83C969ULL, 0x19AE03216F7BD9D5ULL, 0xD27E995EB9A04880ULL, 
            0x19C0F39D46E4F08CULL, 0x08B43694A8C4B12AULL, 0x88572A7E73A1E203ULL, 0xA98C2085A6C1A160ULL, 
            0xC687216E74344886ULL, 0x615CC6B8819EFCE5ULL, 0xB030AE1622C45D65ULL, 0xC3BB5FCB1B0A2486ULL, 
            0x46ED55AC5122B8FBULL, 0xB1AE8F8FBF4FA33BULL, 0xD3683642C458992FULL, 0x4391AA7AEB92C676ULL, 
            0x1078169F3D749141ULL, 0xA197BEC4C290B0D2ULL, 0xB2A17E97D3572DD9ULL, 0x559E9DB343D72484ULL, 
            0xD60C07840D80C865ULL, 0xEAD2B4E48872BA44ULL, 0x2DB8F5A5635E2B3AULL, 0xCFF80CBA51C348E6ULL, 
            0x06DC341513D9541BULL, 0x10E24D745D38EB89ULL, 0x01ABE5AD516064A5ULL, 0x6CC21C352EC4ABC1ULL, 
            0x92A1AD28970DFA90ULL, 0x5F3B2DC5CD889DF5ULL, 0xA71881F1E5B236FBULL, 0x4CB1FE4EA8756AB8ULL
        },
        {
            0xCE90E73E5398F0BDULL, 0xDB07B6C46401636AULL, 0x161EF116A9AA0112ULL, 0x5B3AA1F19302A85CULL, 
            0xF70609605FDB2C68ULL, 0xEF5FB18555E042C0ULL, 0x90A120BA0FF12199ULL, 0x8E6207A36F2A0DE0ULL, 
            0xE9F828AA84C02D24ULL, 0xC7B03F20B4F27874ULL, 0xC2AB3B6126C529CAULL, 0xFDEEBB77CA572712ULL, 
            0x220874D5038A56F3ULL, 0x2A999D17D5C8CC27ULL, 0xBF50D1421ADE3103ULL, 0xDAD87B7DAC4DD915ULL, 
            0x4B9E036F7E961C8BULL, 0xE30FC1CCD6B12C3CULL, 0xC4FE04A66756384BULL, 0x07A84F534308B3C2ULL, 
            0x07980DBD26596F04ULL, 0xB4CF86FF027467E8ULL, 0xFA72F972E5BD36F1ULL, 0xC9E08CF34A900CA1ULL, 
            0xFB5EF34CF6E6E1E2ULL, 0x0753FE713E6FEC4BULL, 0x710B74A12CC3D356ULL, 0xDE0C7511BF7F6D03ULL, 
            0xD25373A864959592ULL, 0xAFE4721AC6DAB04BULL, 0x6C92833C77801853ULL, 0x81A4ACF25E99CF30ULL
        },
        {
            0xDDD5C8ACD6104696ULL, 0x4F3D2B082E44056BULL, 0x251D4D721C46BFC4ULL, 0x1327460C0042CC66ULL, 
            0x9BE1213A93377113ULL, 0xCBC27B6196397DD0ULL, 0xBF245336FD4D6579ULL, 0x52DAC70E0D14A4FEULL, 
            0x1FD4ECF9DA2BB0E7ULL, 0xFEAB688713AD31CDULL, 0x8040D7AD4FA2631DULL, 0x3A80F5325548A6CDULL, 
            0x72665ECD5BB4806DULL, 0x8DE85BB53E44DD83ULL, 0x50FC95F9930A8A73ULL, 0x1D0421D575D44CF2ULL, 
            0x067FA65F6941237EULL, 0xDF23922EDCE65504ULL, 0x35F49E97FE9B667EULL, 0x50E5ABC7AA7AC2D7ULL, 
            0x57F02763FC7AA26DULL, 0xD15E13CA2D17106DULL, 0x725648C4C06931C9ULL, 0x258E488EED30D2E3ULL, 
            0x1FDCCB05E2F1D917ULL, 0x531365E55F3B4280ULL, 0x8089426C9E84EA48ULL, 0x6110A38A193C485CULL, 
            0x2F16A01C97C1A3B6ULL, 0xA62B804131AE910AULL, 0x144ED98969BF35B7ULL, 0xE141B499FA8F12ACULL
        },
        {
            0xCBC7EC3A860E8767ULL, 0x4061DB0ACC77E408ULL, 0xD35C1771F86C02F2ULL, 0x4894FCAB46EC7E0EULL, 
            0x8C46B6FA13036A0CULL, 0x976343B4E6285E90ULL, 0xB202A47515FE511DULL, 0x540873A0DB5F3ABCULL, 
            0xF9D233DFA4EF1C12ULL, 0xBC4940B794C9082DULL, 0x34A895240BA25036ULL, 0x1B8A9C1D6AE15B93ULL, 
            0x53DA9914E124C044ULL, 0x2F0E87DAE5E11F59ULL, 0x0DE5629BC344F1BCULL, 0x2F2948F3262E592DULL, 
            0xC47425C47406C924ULL, 0x18A90B7A44617FE4ULL, 0x7573A26B49998CFEULL, 0x95B7D69C30CD86A1ULL, 
            0x36B72261E31CEF44ULL, 0x980DF6FAA6F96CCAULL, 0x525E43E73EBF96C9ULL, 0x5DD18D456FCAA081ULL, 
            0x8C7475022CB9574FULL, 0x38DB2123EDE29AEEULL, 0x3C94ED7510017F45ULL, 0x1EAC7DCE5F616105ULL, 
            0xFB1613DD59AD3BB6ULL, 0x328702E377542DF2ULL, 0xED1E7196C1A56C71ULL, 0x8829E9EFA84C7495ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kPhaseDConstants = {
    0x5B2732ABD9363FB1ULL,
    0xBEC259DF2599F2DAULL,
    0xAC480C6625851989ULL,
    0x5B2732ABD9363FB1ULL,
    0xBEC259DF2599F2DAULL,
    0xAC480C6625851989ULL,
    0x3BE5CE4B242C34F8ULL,
    0xE145FC5E847D65A0ULL,
    0x10,
    0x20,
    0xD7,
    0x41,
    0x23,
    0xC5,
    0xD6,
    0xA2
};

