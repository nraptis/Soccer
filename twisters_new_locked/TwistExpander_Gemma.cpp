#include "TwistExpander_Gemma.hpp"
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

TwistExpander_Gemma::TwistExpander_Gemma()
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

void TwistExpander_Gemma::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD786E6EB89593D63ULL; std::uint64_t aIngress = 0x9393CA0FC07F6D2CULL; std::uint64_t aCarry = 0xF9A19761B91A0FD6ULL;

    std::uint64_t aWandererA = 0x83A9FC61781263D9ULL; std::uint64_t aWandererB = 0x88FA46174AF9D334ULL; std::uint64_t aWandererC = 0xC423CCEE8BE9FD66ULL; std::uint64_t aWandererD = 0xB177C1B2D8390F71ULL;
    std::uint64_t aWandererE = 0xD6E36797FA3D3844ULL; std::uint64_t aWandererF = 0x8EA8D744315D4C24ULL; std::uint64_t aWandererG = 0xC5AD01626C9E10ADULL; std::uint64_t aWandererH = 0xFC5B9C6C76789A03ULL;
    std::uint64_t aWandererI = 0xA960720CDD6F8558ULL; std::uint64_t aWandererJ = 0xB58BE8CE8BEA67C4ULL; std::uint64_t aWandererK = 0xFA4DE5ED81B64072ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD48F9D5107FCAE2CULL;
        aCarry = 0xB01B4B0CAD1F828FULL;
        aWandererA = 0xA4EC401B13ADF4D6ULL;
        aWandererB = 0xA8DA708F1159E9C9ULL;
        aWandererC = 0x8782F21F16F2529DULL;
        aWandererD = 0x949E4F732555C7FCULL;
        aWandererE = 0xB75D677D3CF0CE0CULL;
        aWandererF = 0xA54A1FA63E1EB766ULL;
        aWandererG = 0xCE9662FD78A2E873ULL;
        aWandererH = 0xABC512AB2D68B6DBULL;
        aWandererI = 0xEC5DCAC2783000E7ULL;
        aWandererJ = 0xF26A2E04E7BB5D26ULL;
        aWandererK = 0xDE752B0D040B01CAULL;
    TwistExpander_Gemma_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x851818076E0F30F5ULL; std::uint64_t aIngress = 0x91D9564737C13BE8ULL; std::uint64_t aCarry = 0xE2D2D088A64D1AF6ULL;

    std::uint64_t aWandererA = 0x817A97ABEF3D4AE3ULL; std::uint64_t aWandererB = 0x93EF8DD4830F8250ULL; std::uint64_t aWandererC = 0xE7BE8EBF79DFD3E0ULL; std::uint64_t aWandererD = 0xCABA3DDEB06BDD90ULL;
    std::uint64_t aWandererE = 0xB31B56AFA1A7C43CULL; std::uint64_t aWandererF = 0xB3088E8EF6952BECULL; std::uint64_t aWandererG = 0xA49AEE4254652A4DULL; std::uint64_t aWandererH = 0xB11411E7E822264CULL;
    std::uint64_t aWandererI = 0xD1F88751560FDC3DULL; std::uint64_t aWandererJ = 0xDA7AE5102D36723FULL; std::uint64_t aWandererK = 0x8E1772919132B4CBULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFA13F89AE954679BULL;
        aCarry = 0x9CC98A2C5BD02B6FULL;
        aWandererA = 0xD3A9539833E7BADAULL;
        aWandererB = 0xB390E24389DD4A7BULL;
        aWandererC = 0xD5FFF7B4E953EF97ULL;
        aWandererD = 0xE48927FFC31A799BULL;
        aWandererE = 0xD3DD5CD6D30EEAEBULL;
        aWandererF = 0x94038CF6045C3FB5ULL;
        aWandererG = 0xD7FE0CDA6F03EB73ULL;
        aWandererH = 0x862373D99723B621ULL;
        aWandererI = 0x916E0414A5232F4BULL;
        aWandererJ = 0xDAFEC6BCA7BD4053ULL;
        aWandererK = 0xBCDF34D395869B7AULL;
    TwistExpander_Gemma_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Gemma::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDB1C6DA316BEFE94ULL;
    std::uint64_t aIngress = 0xBA66B80E845F34CEULL;
    std::uint64_t aCarry = 0xFFE03C1C534A164EULL;

    std::uint64_t aWandererA = 0xE2EFA6123669A151ULL;
    std::uint64_t aWandererB = 0xBC4DD78910644852ULL;
    std::uint64_t aWandererC = 0xAC40AC3418688B56ULL;
    std::uint64_t aWandererD = 0xF4026858D09EE650ULL;
    std::uint64_t aWandererE = 0xE1788E8E73D32DF5ULL;
    std::uint64_t aWandererF = 0x929C708771C3B424ULL;
    std::uint64_t aWandererG = 0xFE4639325EDF22B5ULL;
    std::uint64_t aWandererH = 0xB54D6FF7155A4B58ULL;
    std::uint64_t aWandererI = 0xF647270E912739A6ULL;
    std::uint64_t aWandererJ = 0xC61F05466E9B796EULL;
    std::uint64_t aWandererK = 0x8E775D006E048E3DULL;

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
    TwistExpander_Gemma_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
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
    TwistExpander_Gemma_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
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
    TwistExpander_Gemma_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 28 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 911 / 1088 (83.73%)
// Total distance from earlier candidates: 25139
void TwistExpander_Gemma::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 467U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1486U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 982U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1244U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 940U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1552U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 955U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1357U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1741U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 217U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1092U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 869U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1767U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 416U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1759U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2041U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1848U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1403U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 104U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1782U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 708U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 106U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 322U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1312U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 200U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 361U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 836U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 936U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1641U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1495U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 5U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1849U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1327U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 60U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1274U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 654U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 329U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 722U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1783U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1877U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1828U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 10U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1247U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1955U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 672U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 979U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1695U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 846U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1169U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 879U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 703U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 586U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2021U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2013U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1943U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 501U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1276U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1829U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1736U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1603U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1315U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1597U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1907U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1184U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Gemma::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB92D6679650BC437ULL; std::uint64_t aIngress = 0xC3B2ADCCD4A50A01ULL; std::uint64_t aCarry = 0xD9AB73356FB0612BULL;

    std::uint64_t aWandererA = 0xE7C16418423C206CULL; std::uint64_t aWandererB = 0xA6E0AE305D1512F7ULL; std::uint64_t aWandererC = 0xEC50E4A168D0F558ULL; std::uint64_t aWandererD = 0xDA2A91B67900CDB9ULL;
    std::uint64_t aWandererE = 0x8D89B46488163A4EULL; std::uint64_t aWandererF = 0xE7830145F4EE8CEEULL; std::uint64_t aWandererG = 0xA826445732A632D8ULL; std::uint64_t aWandererH = 0xEFFB9911F9151EB6ULL;
    std::uint64_t aWandererI = 0xD545F7CE88E96584ULL; std::uint64_t aWandererJ = 0xE56D94CA2B123016ULL; std::uint64_t aWandererK = 0x837346AD693F7D91ULL;

    // [seed]
        aPrevious = 0xB1FA4C22C09E5674ULL;
        aCarry = 0x86716B3928F365C3ULL;
        aWandererA = 0xE26B2F2D9173FB5DULL;
        aWandererB = 0xA8CAD7E453C6EC0BULL;
        aWandererC = 0x81F2307E7AD62A72ULL;
        aWandererD = 0xF82EC97E8F67265FULL;
        aWandererE = 0xEC3D0187A09EDE19ULL;
        aWandererF = 0xB0F9DB28B7A85F54ULL;
        aWandererG = 0xDB6046D808E42977ULL;
        aWandererH = 0x9CDD02C32557CA03ULL;
        aWandererI = 0x964CBEDFF027E81DULL;
        aWandererJ = 0x96D2A11890F2AB42ULL;
        aWandererK = 0x8B7367FC74BD9074ULL;
    TwistExpander_Gemma_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 28 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 14624; nearest pair: 459 / 674
void TwistExpander_Gemma::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1910U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7383U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6616U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8143U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5040U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5997U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7353U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4221U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7799U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5884U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1148U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 645U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7034U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7425U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4994U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6992U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1382U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 139U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1242U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1087U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 281U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1172U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1875U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 851U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1448U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1666U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 595U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 584U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 957U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1031U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 184U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 331U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 438U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1514U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 390U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 28 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 14623; nearest pair: 470 / 674
void TwistExpander_Gemma::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1428U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1547U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2666U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7253U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 833U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2396U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5454U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2856U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4461U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2677U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3605U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6985U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7471U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1888U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8020U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2671U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 306U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 955U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 951U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 271U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1436U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 515U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 139U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1542U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1717U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 480U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 947U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 412U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 310U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 763U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1541U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1591U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Gemma::kPhaseASalts = {
    {
        {
            0x1E3696B2B82FC8CDULL, 0x95EE11EB09B74727ULL, 0x0DB747633D357C62ULL, 0xB379881BD64BF8BCULL, 
            0x81578932A7765ACEULL, 0xB0451E193FDE288EULL, 0xFC66E257530A60D1ULL, 0x1F21881B1CC02936ULL, 
            0x6F558CD86B2EA513ULL, 0x6BD2649A75E2F78FULL, 0xF3725CC7E72C6BEAULL, 0xFA564E12C5431448ULL, 
            0xE2F4F6DFFC4F34A3ULL, 0x6649A9A17BE4DD01ULL, 0xCFA3D0B1889D5D21ULL, 0xB2690436D0315AC3ULL, 
            0x5B092C8D2A67733DULL, 0x970217B244291F88ULL, 0x7BED2775717489EAULL, 0x1E0F68BCC980634BULL, 
            0x419605BC5432E54DULL, 0xEE804DF12E62593CULL, 0x2CEEF80C31AF86DEULL, 0xF0AB0B7C26E5D3D8ULL, 
            0xB9001D04A29D6D68ULL, 0x9C3A6474DD5AB079ULL, 0x87FA1EB7FC593F87ULL, 0xD6D9DE93E5E9EA45ULL, 
            0x0A349E930A43A24EULL, 0x98D48743D9FA961BULL, 0xA4C54413EF9453E0ULL, 0xA80A7840FBC77683ULL
        },
        {
            0xE6E0B9D3E744154DULL, 0x49586288CADD7ADAULL, 0x28AFEDB802D2100DULL, 0xAD92A6E2EFBE6568ULL, 
            0x5FC3349E0773DF7AULL, 0x8A4C9FCB711E1A9EULL, 0x67945766168D903BULL, 0xB6DB7B96C7107670ULL, 
            0x867CB78E68D07C19ULL, 0x9D2AA6BE19EEDFF5ULL, 0xCF1FC7F4DC4F015AULL, 0x944E51EF881E0710ULL, 
            0x0BCAA9ECD4B4FEA8ULL, 0x622EF31040E043E6ULL, 0xEA67A679A07BA592ULL, 0xCB9B950C0F76284EULL, 
            0x32BCADC7B1C065EDULL, 0x28A5C1BEE4EA7E88ULL, 0x7CB98F8068753D9CULL, 0x7D67471AB9F2568AULL, 
            0x4D79620E050B49FDULL, 0xD3D0AAE3A5AC7B1FULL, 0x2B3D1DE04A733566ULL, 0x364236E2BF7B9A08ULL, 
            0x2402495143137A9DULL, 0xB447AE6CC91B490BULL, 0x65F2BE8934793F94ULL, 0x617C7BEBF6683636ULL, 
            0x2EBF6E72648E5FDCULL, 0x87DB42D284CCA0E7ULL, 0xC5D39BAFD1ADE715ULL, 0x42A7FC37CCB5E832ULL
        },
        {
            0xD3B64D8A4B711798ULL, 0xFE099AFE9B152FF8ULL, 0xB4C8C5357C585908ULL, 0xD7FD05FA50530F9DULL, 
            0x290FFF4EF7270E6BULL, 0x47F1973EEE7C1970ULL, 0x35A7D05438E57A3FULL, 0xF3F5AA1672F7DEADULL, 
            0xF726D67B33EA75D1ULL, 0x68FEE592024C281DULL, 0xDF1374281021CDD7ULL, 0xFDAC598DE34766B0ULL, 
            0xEE5E1A2B7309110CULL, 0x8C5F04751A6D0000ULL, 0x84BC306864CA8012ULL, 0x6EEA8137EEE97E21ULL, 
            0xE42AC6F32F71C6B0ULL, 0x34E5DFBAE2E907C3ULL, 0xCB0757ADBF9BA806ULL, 0x42D76165E5E24B88ULL, 
            0x3707EF3FD51160E1ULL, 0x18644AC23B68BB7FULL, 0xB3ADC339A80698B8ULL, 0x39831969DA85AFA7ULL, 
            0x3F8C919FB8446FEAULL, 0xA379BE81040AC7ACULL, 0x3107555943D15E75ULL, 0x6FC3E64DFAEB7091ULL, 
            0x312165361E29115AULL, 0xA56D3C3F448012BAULL, 0x1746BDD95E86D52AULL, 0xEF66699007568DB9ULL
        },
        {
            0x548EE27961C8F16BULL, 0x6C298F6C6A0E4D68ULL, 0x1003750980F1B198ULL, 0xBA8E0F741B11EB0BULL, 
            0xA3A9F3CC7B3A2C85ULL, 0x476AA5AC660331C4ULL, 0x0FCDBC031EF553E8ULL, 0x37B8C3307B86511AULL, 
            0x57B5EEEE95CE1B8FULL, 0x97282077A9DD8862ULL, 0x7476A10C2FF38984ULL, 0xBF9B58813A22670DULL, 
            0x783FD09AE70144F6ULL, 0xAA50E5B0C8C6A5DBULL, 0xBCA249D24FCF0F6AULL, 0x9F59140CFFCC864FULL, 
            0x26C9097D45F4B54AULL, 0x9A72D2FA6164BEFAULL, 0x2719A19C2BBDA650ULL, 0xDF6CE158CE4E2BD0ULL, 
            0xFB8D772BD80B3CCDULL, 0x98E6F6537E73F4E0ULL, 0xCF58AD514E5C1F66ULL, 0xFF74B20D45588604ULL, 
            0x298DED0557554A05ULL, 0x6DC92DA87CD2E299ULL, 0x705C780B489980B9ULL, 0x67E835A1E671F6D5ULL, 
            0x1E5749D51864ECA2ULL, 0x2BE1B5E1A2846A1BULL, 0x75977CB772D6C825ULL, 0xB9C23675259D6F74ULL
        },
        {
            0xDD600252E815ECECULL, 0x588AA4F7226596D4ULL, 0xF15CB3C2AB5791F6ULL, 0xF4C7990174AA4EA9ULL, 
            0xEF903A4AA82CE691ULL, 0xBBE28873AFC90AA7ULL, 0xA068DA8782D5B760ULL, 0xD1BB8586E6AA3168ULL, 
            0x84543383314B458DULL, 0x8C88A7CE500863C6ULL, 0x21F43B0AB1429446ULL, 0x5AB6760DF361CDB4ULL, 
            0x89DB399F22C48CD6ULL, 0x223DA87ACFE578D7ULL, 0x109568409FD84009ULL, 0x5FF9DDB4505423E5ULL, 
            0x42C6630B9276A832ULL, 0xE496CC0B31309E02ULL, 0x44E3DF607B0CF183ULL, 0xFBF0DC22A1149011ULL, 
            0x4E6B511442931741ULL, 0xA00F078EEA8C15A1ULL, 0x904616C6EA001E8DULL, 0x3CA0C6A8ECCE3B79ULL, 
            0xE1052F1822A380D9ULL, 0xC02F08740DA76DA9ULL, 0x79133D9BFD0F55ECULL, 0xAD77C091651EAC2DULL, 
            0xE50A1729A6B92D87ULL, 0x4AE25643DB5E0B9DULL, 0x81DB332E8F6215ABULL, 0x39FDE16689481A63ULL
        },
        {
            0x1D1A0D75678185D5ULL, 0x0DEB39C5770A42FCULL, 0x5D1A60EDEDC3E799ULL, 0x9C1A6A723BC8AE94ULL, 
            0xA28E29B3B6E8C168ULL, 0xC3095E6F9ABCA245ULL, 0xBCC13459FB71B959ULL, 0x5AC06442A3EF44E9ULL, 
            0x91B2307BF84D1B6CULL, 0xFE7721D40786AC4EULL, 0x06808F4EFB41815BULL, 0x24D616CF558484BDULL, 
            0x6936917415D8A840ULL, 0x785122768B12C4FDULL, 0x9FD5714E43583B42ULL, 0x0C430D6472E245FAULL, 
            0x92BD349D61887B99ULL, 0xDA9CA6668C194CC5ULL, 0xCE08A9648AFE908AULL, 0xFE3CC7666E7D8A04ULL, 
            0x6011D0FC7B3CA93DULL, 0x08048729D7BA89F5ULL, 0x3EEE834F447703A1ULL, 0x7F5B66E7E92A1466ULL, 
            0xFC191EE6B5CE2AE5ULL, 0x19BE7201D4ACAF5BULL, 0xD0AEBEE12E78D532ULL, 0xE0A06759C2A209E3ULL, 
            0x6CA6C804B2AB1EC0ULL, 0xE987003ED0B0ED00ULL, 0x051B805DC0ABC8FDULL, 0xE64E2F27FB4323EFULL
        }
    },
    {
        {
            0x1D7D57F5DBDFEE45ULL, 0xC75214F6D3B6FD0AULL, 0x62277521A11FFDEBULL, 0x15841994F59C8F39ULL, 
            0x4E8097CB43FF1C00ULL, 0xA4771B39C439CF15ULL, 0x96E0802495FDAFE9ULL, 0xC7E75A28BE9A907DULL, 
            0x46903EAA9935F900ULL, 0xE985C5E8113DFFF7ULL, 0x2A7C1DE2CF777DB4ULL, 0xD0DFAD072C53F728ULL, 
            0x6402251C07177477ULL, 0x3B914EC392388B79ULL, 0x37115AEB5DFC3668ULL, 0xA71C704377DDC819ULL, 
            0x4BBC3B0614167A85ULL, 0xA0A63ABCB3A13506ULL, 0xC4AAA7D1E9666195ULL, 0xF26F1E00FF109BB7ULL, 
            0xBF06EE167515466EULL, 0x796151A002E7F5D6ULL, 0xB2EE372C421BCDF3ULL, 0xE2B6F353FFEC5631ULL, 
            0x428E2BA622914CA0ULL, 0x879644ACE2DAC125ULL, 0xFD9EBDACAF2454B5ULL, 0x35F3079139836CB8ULL, 
            0xC54AF15B264502F9ULL, 0x307F71054483E61EULL, 0xB551B4B89E33E603ULL, 0x3170780762C4856CULL
        },
        {
            0xC834B96E28205A25ULL, 0x9BE7F83FE75B7274ULL, 0x5DF0E35A214C5E7FULL, 0x5ABB27E17A6DFB19ULL, 
            0xFD4277ED8625F0B9ULL, 0x7B6407624BA35D92ULL, 0x20C4A9D685918884ULL, 0x5B250F5FC4EE9166ULL, 
            0xEBE97FC4767485ECULL, 0xCD5B818612DD67B4ULL, 0x22E698DC0183BD7CULL, 0x1D5B5D522A2FBB92ULL, 
            0x2EAA0DA5F1A6767EULL, 0x2B41E5D068FC9871ULL, 0xE6ED23E80659AA45ULL, 0x522D65FB5A9E3B91ULL, 
            0x5207E2BC618E3D1AULL, 0xDCAB39BD0709364AULL, 0x30E95BFBA7609E53ULL, 0xC9CCC0CA43D9CF87ULL, 
            0xD3BCACBDB856967CULL, 0xD3154E408D423870ULL, 0xE0C591DE9564B18CULL, 0x10C0C3F376C03D72ULL, 
            0x01159C3B0B118810ULL, 0xD4FF0DD722A5F552ULL, 0xFF6743A9C3412E8EULL, 0xFB0F5FD7CAD4E727ULL, 
            0x8C85EAEC0FB62012ULL, 0xCAA3F471D9BC7F2CULL, 0x3F95C946E8590F4CULL, 0x9A6F02F81A2DD37CULL
        },
        {
            0xD8AA2A9FD26ABE64ULL, 0x90E48B24394864A7ULL, 0x59C569372DC25B14ULL, 0x6797CA2A2A34E935ULL, 
            0xDECA1CA78054CBB7ULL, 0x47EA50D29D3AF346ULL, 0x55242AE590BC69B4ULL, 0x46C30DE401D07534ULL, 
            0x5C7E6D7B68EE201AULL, 0xD3EBF040E130161AULL, 0xDAB8219DCA9F2F30ULL, 0xE0F0BFD52BCA2E74ULL, 
            0x8B7DB0975661C352ULL, 0x743FB5626095622AULL, 0xA0435CF62DC3EB8EULL, 0x95105C76C03C3D89ULL, 
            0x709095DB2AC00008ULL, 0x86BE65E2955D3B9FULL, 0x59DF12FEC5F1BFC3ULL, 0xA6B6BC16C20940DEULL, 
            0xDC57AFC065E06D2DULL, 0x3409E20BA24CDD2DULL, 0x4751FEFEA2446B46ULL, 0x78F856E53BA9F9CAULL, 
            0xAFBAA108C1621EC1ULL, 0x7047C57A8C8A39F1ULL, 0x753E416170F5EBBBULL, 0x151C0564DB961833ULL, 
            0x76B71276D1EBE0EDULL, 0xDEFA3831CF1556F7ULL, 0x8173D7D3FB8B28BEULL, 0x52477587AE578BAAULL
        },
        {
            0x78E780157F33BE48ULL, 0xB5435BC284EBB9ECULL, 0x6720CEC6CA297A89ULL, 0xE942D2EDFD8B088DULL, 
            0xB941A33E122620A2ULL, 0xD1036E56FE0BA868ULL, 0x2AD572E0014EB050ULL, 0xF6725737C6D36EEBULL, 
            0x3BBE165784B79012ULL, 0x65DC34FFD165E81CULL, 0x7645B32F4FE4228CULL, 0x55CA1FBD2F6C2C42ULL, 
            0x92D2893528D9F935ULL, 0xE4ED730FEF53E682ULL, 0x728EB802C79F2332ULL, 0xC72370DA00E5CC18ULL, 
            0xB6C39C4C71B45B64ULL, 0x06929EA1D8E68C30ULL, 0x5CDCC95ECB28E2FBULL, 0x355B8E1ADDE84FD4ULL, 
            0x8ECF9D92EF54A162ULL, 0xC37E0308A0DCA63FULL, 0xB75C735239383AD3ULL, 0x77ECFD06623F4F0DULL, 
            0x64CD77C4D7448FD0ULL, 0xF1CF1CCDD8F3FF44ULL, 0xC73ED79651B352C8ULL, 0x3F98CA34A22DB05EULL, 
            0x50E0BE2A44EC1320ULL, 0x405048E823FDE098ULL, 0x625027E79668A826ULL, 0x5FAD6F7B03D15DF8ULL
        },
        {
            0x47739DB63051924DULL, 0x53882DF058CD07D4ULL, 0xD7AD79283396B96EULL, 0x1D3B6CC327B8DF00ULL, 
            0x26DA4A0BD2A00A82ULL, 0x94E49A5DA4E01FF6ULL, 0x46751F3E011891E0ULL, 0xDB0A14471EA58D20ULL, 
            0x8F3C1306A0921C26ULL, 0xEFF79B91682D1EABULL, 0x9289B43A06B13CA1ULL, 0x804C50BBC87BAB49ULL, 
            0x3B895400A500624BULL, 0xC9FA7AAF0D1EA09EULL, 0xA6D37E24D276BE17ULL, 0x3D01FC315BBB4800ULL, 
            0xBFD03C3C55992D3BULL, 0x01ECE43A5B1B326BULL, 0xD376FCB4BBA86A18ULL, 0xECBF55BCC867DFC3ULL, 
            0xB91E8F7DFEFA1A96ULL, 0xF7CCFA48B7F9A933ULL, 0x44FCC4FF263EB73AULL, 0xD6972A1D288F3C40ULL, 
            0xACBA7FF507EAAB86ULL, 0xE1D0A433F686F627ULL, 0x8ABEB3A4E4A05CE1ULL, 0xDDAE2B3EB8CE3D8AULL, 
            0x86619D66FC09B100ULL, 0x8B409BCD9C9D1752ULL, 0x4F05FA09B24A2563ULL, 0x3DB063FFE84DF6FAULL
        },
        {
            0x7C5A9F1E34CDDD0AULL, 0x04C30237894841C6ULL, 0xB51D41C30A2BD440ULL, 0xB6F47A30ED53B447ULL, 
            0xC151443BD95199EAULL, 0xB715A4F2E67FD930ULL, 0xD455FE9EF3BFFCACULL, 0xE13B575545707060ULL, 
            0x5CB766C9B45D9BF9ULL, 0xBE520DF2B2C5AE85ULL, 0xD8AAF14519132358ULL, 0xE913613FD0F55E55ULL, 
            0x7798F37E052CF72DULL, 0xE688ABD6D59034C6ULL, 0xB4DBC5C3883CDC5BULL, 0x91E50ED8451BE7EBULL, 
            0xC250F71B1C320102ULL, 0x92E5CA1FF35CED20ULL, 0xB4684B283CC39D7BULL, 0xA76D7B6952B2E5DCULL, 
            0x46929FC9B9D837AAULL, 0x70BC81AB6EDD2E00ULL, 0xCAB86B9609BA524DULL, 0x6673CA4DC6347052ULL, 
            0x8D596F02EA85A136ULL, 0x21ED93CC8B8BFA5EULL, 0xB7080DA1BC4EBF1DULL, 0xDE38127E8438B34AULL, 
            0x7C1E883E1CD189C7ULL, 0xEC29C81FC39F1824ULL, 0x64D0E6DACE945084ULL, 0x179874C7179D9D9EULL
        }
    },
    {
        {
            0x6C89248C7C758305ULL, 0xB9C15403599088CAULL, 0x92E4358F9EF4A145ULL, 0x544FFCC0424EADB4ULL, 
            0x28C074CB0A4A3D60ULL, 0x009DA8F22960C40CULL, 0x757D9B6E7CF8A3C7ULL, 0x13E8C49AA57B9705ULL, 
            0x6DC6F37DFF52F36CULL, 0xBFD5211FCE1AE8D4ULL, 0xE4D77AF8A07E33DEULL, 0x3856E098FBA14D9AULL, 
            0xB5BFDABC864CB336ULL, 0x3DE78FF7C83E2EB0ULL, 0x7FFBE00C2B4AC72EULL, 0x5773D3C747BE2650ULL, 
            0x741A73B9B7A22DB2ULL, 0xF91EA2451B88E73DULL, 0x85C7CB2987CF5DADULL, 0x1AD51769D4922560ULL, 
            0x1CE7DC5FF912D5ECULL, 0xAFD7FC97835C46AEULL, 0x0D558C7E57B8B1B7ULL, 0x2B2F2FA0C42D42E9ULL, 
            0x99F190EE98E14B30ULL, 0xE7D86FEAF84B7E68ULL, 0xDD3C003E49BF98C5ULL, 0xFEF311CF5A432008ULL, 
            0x0DEDD32E68C07261ULL, 0x774AA5B86BCD631AULL, 0x541BEF7F144F24B8ULL, 0x4C74B1D220605EA7ULL
        },
        {
            0x63BF5418CBE8F3A7ULL, 0xE0E42DBEC5F83BB0ULL, 0x2CFD14653EC58015ULL, 0x2D42BA722E521325ULL, 
            0x6E57CE4C7249E9ACULL, 0xFDA475496CA232A6ULL, 0xA7ADCA249C8E2A39ULL, 0x3FF3C5EEA0A7D191ULL, 
            0x7A039CB96FB78492ULL, 0x049F2EAF3240C435ULL, 0x78D68431EB129354ULL, 0xEACC83916C08F9BFULL, 
            0xA4B6359C27FA52ACULL, 0x3DEAA508A17A5B11ULL, 0x0ED4D4F87F67EDCEULL, 0xDB1C5586D7C4D3BBULL, 
            0x76680A60FDB246A8ULL, 0x3B784CC8763AF84DULL, 0x891C63C2ADC6863AULL, 0x0E934E60CB71B3B1ULL, 
            0xD6A9D841472A0443ULL, 0x620443E155DA44D3ULL, 0xFB614CDD679B554EULL, 0x989E16A104FFC138ULL, 
            0x0013EEB3E55F6AA0ULL, 0x5D7D3678C454C0A5ULL, 0xF68A168FCF1B82B8ULL, 0x3574464609850106ULL, 
            0x959917278F019700ULL, 0x6E126032EA3952C0ULL, 0xD10E150DC68A997FULL, 0x6BCE6073AEA77965ULL
        },
        {
            0xCD674F49A3A2B5C3ULL, 0x35FDBE5F5A9AB6D3ULL, 0xFE936F56BB8E9602ULL, 0x29B8DD8D7BDD9C81ULL, 
            0x03037EB762D6BD7FULL, 0xBFAA4C49409E5B5AULL, 0x3AA6E68EA296DE65ULL, 0x129EAAB4C4D72368ULL, 
            0x7E8ABA1E2A2703D5ULL, 0xE4EA0A0EC48D5514ULL, 0x3E697B59DC5BEEA2ULL, 0x70D60A59F80CA1C9ULL, 
            0x6A509BAAF6B3BA6AULL, 0xB3A98851132BD824ULL, 0x3399FB150423316BULL, 0x6B42FE4498807976ULL, 
            0xAF327CD68AF17DF1ULL, 0xDA93FAB26F98BE79ULL, 0x2B76AF4B7D514929ULL, 0xFC55749ADB46EAC2ULL, 
            0x129729F6F98BA8B2ULL, 0x1BC66D3CB9AF45F8ULL, 0x348A7F9975E7DB39ULL, 0x3578D93F1087BF2AULL, 
            0xC9EDCCFAD6B41D78ULL, 0x697B8CA028EEA711ULL, 0xD015934A4AA0E2C3ULL, 0xBD9392AA7EBF9414ULL, 
            0x60E84D6ACC9E2C96ULL, 0x634C834BA2723F15ULL, 0x9EC4F0835D7574F6ULL, 0x56775251DEA237BFULL
        },
        {
            0x667E78CDC211D417ULL, 0x745883B11B970CE3ULL, 0xDA8B308F800915BCULL, 0x81AA841725415626ULL, 
            0x2127267F90C92AFFULL, 0xD877DD98915C9BE5ULL, 0x53481B96BF638232ULL, 0x51A28815F927A65DULL, 
            0x9C63D96413605563ULL, 0xADD42D72F0D7A05FULL, 0xBA010A235438D989ULL, 0x6609B68B8A6E988EULL, 
            0x41C7246CBB091AFDULL, 0x1946F6F01583631EULL, 0x774AE7FDF8F7A880ULL, 0x708AADF1CB8C0264ULL, 
            0x903B55C6F88D3BC3ULL, 0x3335E4B27DE5AA13ULL, 0xF62F889DA7910141ULL, 0x3164E20DE4C43FCFULL, 
            0xF29D7997296A9282ULL, 0xF271B48361320BC0ULL, 0xF2DC94BF3AB11450ULL, 0xBC66AAE623907955ULL, 
            0x74ABA48D4651EDE8ULL, 0x4965686DE9C7E62CULL, 0x4727B6A7BE1CF040ULL, 0xC405985E891193CDULL, 
            0xC61BC942955F0769ULL, 0xBA991B3E3571AB0FULL, 0xC7185DCC135FA66BULL, 0x246A3310143C61AAULL
        },
        {
            0x1A031F19E6BE766DULL, 0xF47AA3FC3126A59BULL, 0x74E3203275694D5EULL, 0x762A15D91A983254ULL, 
            0x34374F2B97EB93E1ULL, 0x3129BB699344AA9AULL, 0xF8C273CE29B59885ULL, 0xA39CF70DA3C0CDADULL, 
            0x74DE209AD5999B89ULL, 0xA3FD48E8690F525BULL, 0x3B015517A331011FULL, 0xBFF08C913DEB5169ULL, 
            0x5A995E75D50D3756ULL, 0x4EF1A1CE42D1FDBFULL, 0x1F1BC161289469EAULL, 0x35E735D70A0711A6ULL, 
            0x4319600A5E20A42AULL, 0xA9F104818AE6E11DULL, 0xD6007DF1E40A89C9ULL, 0xD5CABDDF547D3AE0ULL, 
            0xCF376A23E99CCA3CULL, 0x45CE73FDA2A8D3C4ULL, 0x3DB33CF75FA347B0ULL, 0xA2DADC423217D44FULL, 
            0x46297EB18C0DF4C9ULL, 0x06E15B6ACDF658FFULL, 0x97A9AB706C37588CULL, 0x40796F7FBCDF2AA8ULL, 
            0xA0ECEDCA8FB50DA4ULL, 0xA666DA0003B19C39ULL, 0xEEDEE7B80CF9C789ULL, 0xEEDB1E21CBE06B39ULL
        },
        {
            0x39FDC91FEDCEE93AULL, 0x4B68676B4E7836E4ULL, 0x2BEC557F615F2A56ULL, 0x803FA91B1C1F0321ULL, 
            0xD16BCCE0B67B2590ULL, 0xC3018BC331BD8813ULL, 0x7B42A8D0681E9152ULL, 0xC5B505E56C3BCA60ULL, 
            0x84FFA7434BEEC92CULL, 0xDFD87C549C85AD48ULL, 0xBC541B9E9A25E94AULL, 0x15091022E199C6B1ULL, 
            0x57950B563CBA1EDEULL, 0xA0AAD5DEFDBFC0D6ULL, 0xBD4124E0F20EECB1ULL, 0x9EB0EF3B37E2E488ULL, 
            0x376E7019038CCD16ULL, 0x9E52CE65D356956EULL, 0xA0D3D65FA4444303ULL, 0x367613652B326272ULL, 
            0xE32B704F09526428ULL, 0x42486F5B77C48C4CULL, 0x87969BC60980F3D2ULL, 0xDB575C8B50FBE35EULL, 
            0xBC8187E2DECA5ECBULL, 0x9C29F3AFF927A1C3ULL, 0xFE0C46F7AF01C502ULL, 0x085B0B0C98CC44FBULL, 
            0x1178231522351EC3ULL, 0x38EFB6E9A88A9216ULL, 0x434B72493177883CULL, 0x4D9B4F5B04F5B72CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kPhaseAConstants = {
    0xC5994C4494656461ULL,
    0x8F589A7200D435FFULL,
    0x4023AEA2688DCA11ULL,
    0xC5994C4494656461ULL,
    0x8F589A7200D435FFULL,
    0x4023AEA2688DCA11ULL,
    0x86E2EC20E4096872ULL,
    0xF8196DC805E7EFB6ULL,
    0x09,
    0xF8,
    0xE1,
    0x3A,
    0xF5,
    0x7F,
    0x89,
    0x46
};

const TwistDomainSaltSet TwistExpander_Gemma::kPhaseBSalts = {
    {
        {
            0x0B20BA65E2FFBAF0ULL, 0xF07572DDE7AE809EULL, 0x9322C7C7DDB39184ULL, 0x621107F519DE1F3EULL, 
            0xB3CA5B163D8D8403ULL, 0x567B8E4BAF34D496ULL, 0xA044C3AB09F3F770ULL, 0x240B1ED4780776EEULL, 
            0x425E59B68B0FAE28ULL, 0xDE0C11EF794BFD5EULL, 0x4025EF6ADAE0175AULL, 0xC22709E1D39C669BULL, 
            0x255F8371D598E3FEULL, 0x5EC49037326ADF69ULL, 0x1D99A2B1D15BBCEDULL, 0xED68AEE1BE367DDAULL, 
            0x27219D1721DDCCC3ULL, 0x3B15383D1A7509ECULL, 0x7A7DB2FE0DD8AD7AULL, 0xFF9F86B7FB0B7235ULL, 
            0xB88954E379867623ULL, 0x390D9D42B03D6096ULL, 0xE27263834460C3E2ULL, 0x3D46DDDB1105E52FULL, 
            0x9A56E45F4964F7C9ULL, 0x92204DD3B342B734ULL, 0xFB0F9227F975ED4EULL, 0x5AA93230B9970830ULL, 
            0x04B7BEC223B1837DULL, 0x10B1F628F2344682ULL, 0x6AC57E605A57BA8EULL, 0x1D8209E07A11E213ULL
        },
        {
            0xC9BE4F33F973D6F3ULL, 0x6CFB4AD613AEF6BCULL, 0x3D24301B1B1B7869ULL, 0x21A712190A428C96ULL, 
            0xE1E3F403917501F5ULL, 0x94E0454D50F57339ULL, 0xE98058015923545BULL, 0xBA5535B8F087972EULL, 
            0x3237D76E73FF5947ULL, 0x84398756C5453E63ULL, 0xF3B5D31CCA8C40E5ULL, 0xF7278410B9E8202EULL, 
            0xBFEB428B70C4AC70ULL, 0x4D636759373BEDB6ULL, 0x0639AB21EEF5C1BFULL, 0xB25E6AED8E787733ULL, 
            0xADB9E331222865A1ULL, 0xEB44C536FE31172BULL, 0x51B2C3B53B71B041ULL, 0xD2A71A167508ECAAULL, 
            0x37F5D6B067933F02ULL, 0xD38AF6507A11FBF2ULL, 0x506212DE2927E776ULL, 0x0C026D977FE577BDULL, 
            0x56ACD5EE3B74CA81ULL, 0x53E1DA8B43244C36ULL, 0x59D19D0DC9D9DD49ULL, 0x98252F3FA00FFD4FULL, 
            0xF21F9D427D99370EULL, 0x91F83B0FE3AB4B63ULL, 0x534D6C0EB43ED4EFULL, 0x9607B978EEC4EFC4ULL
        },
        {
            0xACC9E5F27D5DEC90ULL, 0x725238C9BFB917ECULL, 0x069E985010471165ULL, 0xAFD2D93038645D9AULL, 
            0x3EB8D3108A0173B0ULL, 0x41D8EC2F6F5BA912ULL, 0xDFD9EB1A27D45776ULL, 0x7411E4A6E7CC6002ULL, 
            0x4C4DBE221AFB50E1ULL, 0x9F6E2C75B140E141ULL, 0x3921D7E7F31E1694ULL, 0xF16EAFA64E428C7AULL, 
            0x1C37E9DDFF011601ULL, 0xC1BDC74F7BABF943ULL, 0xF76A63ADDBF7CA76ULL, 0x9EEAFBC12D327342ULL, 
            0xCAEE59E25CB33144ULL, 0x120F33A6DE65F9ACULL, 0xCA15D0CE8E3C6FFCULL, 0x2A51E6C6933E99C5ULL, 
            0x7867039BD8585A98ULL, 0xB438E15792353C5AULL, 0xEEE8D8FA25A5DF12ULL, 0xA9581DFC8E6AF158ULL, 
            0xC396A2339163C442ULL, 0xA76B596651774B50ULL, 0x0AD965C700E794E7ULL, 0x445159AE5DD8F3BFULL, 
            0x7D706CA05F227C37ULL, 0x1753ADFB7D3928FDULL, 0xFABCAAFF19ABD518ULL, 0x75DB7AA96319F2A0ULL
        },
        {
            0x186DDC5E8091BFC5ULL, 0x58F77268EA17EBC0ULL, 0x3D8348BF115A2900ULL, 0xCA1533BE590CB111ULL, 
            0x1429246BD419731BULL, 0x64F75F32307B2A1EULL, 0xC63130A753E1D986ULL, 0x3BAA4EA3EC5F8CEAULL, 
            0xE0CE2FAAFC2046ABULL, 0x00DE78F881D62A01ULL, 0x82D0E1E094E2F603ULL, 0x8D8B5A6C5183B748ULL, 
            0xC7B68CE9D1486764ULL, 0xEAFA4694926FF324ULL, 0x3595D59BA30724AEULL, 0xD07BBFC4A20FD9E4ULL, 
            0xF430AE408B828F40ULL, 0x8C43DFA6ACB78177ULL, 0x854A2C5239A13C66ULL, 0x21941ADB78BA4F59ULL, 
            0xA473ECDB18950E87ULL, 0x0B45F6B5DD03DCB5ULL, 0xABF4C6AD44E837A1ULL, 0xB05C9301440EF43BULL, 
            0x53941472281CBB5AULL, 0xBC53EA279752A818ULL, 0x0EC52EA7456ED41FULL, 0xA8FAC7416B4E7D06ULL, 
            0xDD66160F341912F0ULL, 0x0069E429D0745FB0ULL, 0x25EB1DC6C397ADF3ULL, 0x4D713008660B59F2ULL
        },
        {
            0xD435765BDF2B2FB7ULL, 0x5BBE3652403D271CULL, 0x58AD2A79F8B5789DULL, 0xC577E8F8077A4618ULL, 
            0x563F91F98CD7709EULL, 0x62F212187E52A0ACULL, 0x7B3D229380C6685EULL, 0xFABE233AB95A67BDULL, 
            0x1635289B14A8D3B2ULL, 0xEA9606893FAD64A5ULL, 0xE213873A31DADD54ULL, 0xB6CCF0257EB20D18ULL, 
            0xC5AEDC3D65F1FC19ULL, 0x833F07336913FA5CULL, 0xABB2135A87A54A22ULL, 0x4A1E3483F7FD87F4ULL, 
            0x63E337AD1B24CE5DULL, 0x701D59E41A54E153ULL, 0xBCCB23A05085DCFEULL, 0x9589C10DB6E59928ULL, 
            0x9685680006A50322ULL, 0x1F1788BE50CCC247ULL, 0xDA6811BE2307CA47ULL, 0xED614A5C290131F9ULL, 
            0x3302D75FFE800E12ULL, 0x6DE4E5487AD0985CULL, 0x81BB85B34FB1FA1EULL, 0xEE335CA83651DDB5ULL, 
            0xF67CAB829764A538ULL, 0x4F8EBECC6DBFB48DULL, 0xAACA2C45EC9F20EDULL, 0xDD2EE6596201B028ULL
        },
        {
            0xE6F450A9C6D28BEFULL, 0x05FEAC047B2291E2ULL, 0x934ABD5E58DD78DFULL, 0x15A97FB6FAE24660ULL, 
            0x8F7CFF7AD1680507ULL, 0xF48D28B954BAB6E4ULL, 0x46E9DDFD7EF5F891ULL, 0x71B4674BB390517AULL, 
            0x3C5DBC67C582B089ULL, 0x2E0E9426077A58FCULL, 0xFB1F648D08DCED7FULL, 0xBC37FB5EBAACD016ULL, 
            0x00E3824EDDFC7D5FULL, 0x81247A81BB2CF6CAULL, 0xC44153B7984BE200ULL, 0x8C6F51286430ADB1ULL, 
            0xA2775F51F2F01317ULL, 0x639353B44C5FA8A5ULL, 0xE74A8A245395B8BBULL, 0xE2BCF54CF01F4E19ULL, 
            0x7070349CF4732B3AULL, 0x252D0ADD74D1186FULL, 0x95699EADD60F4084ULL, 0xB20B1B5E9C665ADAULL, 
            0x0D91BCC26030F3E1ULL, 0x1708B1E8C886754AULL, 0x750DAE3224918B5FULL, 0xBCB589BF52839867ULL, 
            0x6B1DDF4680F51001ULL, 0x47A7851DDE336A74ULL, 0xF319727AF0324E9BULL, 0x038E55862F46D001ULL
        }
    },
    {
        {
            0xF1DF9003A662F4F6ULL, 0x899849D6B0B7FF8AULL, 0xF0CC7CFD1C90728EULL, 0xC3306DA1448D4092ULL, 
            0x77DE1BC4A7709099ULL, 0x891429BD67B59A9FULL, 0xB1099EB15E4B4A88ULL, 0xEEF9807235C2D007ULL, 
            0xF1347E1B02A18E53ULL, 0x950800830AA55F41ULL, 0x25D601695A0B407EULL, 0xD3C78D26AD673FBAULL, 
            0x1D287097A94E412FULL, 0xF03C1050EBF731A2ULL, 0x933ACF6DDCBF2F31ULL, 0x2C00295F9A60F207ULL, 
            0xFFC42639B7E7348AULL, 0x1AF24A5423591586ULL, 0xD1A24E502153597CULL, 0xF0283DDC50E1D30DULL, 
            0x4F2D8818D1C3C106ULL, 0xA49915695D536ECAULL, 0x0C020CA2D41F0BC9ULL, 0x15A3ED4FA7DC8F63ULL, 
            0xD644A04DF29900E5ULL, 0x475C85B7A1A1C41EULL, 0xAB4C33CC989DCE1CULL, 0x7FD30B1E21CD07D5ULL, 
            0x9DD994B31039B645ULL, 0x98DBB86E6E4B2315ULL, 0x2BBCFDE1D3A64CD4ULL, 0x45A2BEC6695E0607ULL
        },
        {
            0xFC6AE3292F7955FCULL, 0xCB951A59DEA01DADULL, 0xBE72A9A2164643B8ULL, 0x57B65F1D5811FEBBULL, 
            0x17509F5461CEBEF7ULL, 0x3CB35F5FB7590884ULL, 0x03DAA5A07D03D24BULL, 0xD150FB8B9051EDB7ULL, 
            0xF94B898EA637905AULL, 0xAD212F58F929B703ULL, 0xCC857A4AD1D1FB2FULL, 0xE28B122E06C94BBFULL, 
            0x4D784C3AB65CB44DULL, 0x4D5CB45705FA0D90ULL, 0xE7BB8DE4957E4596ULL, 0x755FBE81F96D05A3ULL, 
            0xC3E6E7A8DEE77914ULL, 0x61FAE0B022E78E65ULL, 0xD7CE58F5DD823884ULL, 0x0D558CD10B6496F0ULL, 
            0x00C5F46B9555B63AULL, 0xABF3F4B787ADB3A5ULL, 0xC3DBC0A987D50DBDULL, 0x50EF317904851BA7ULL, 
            0x8F885012A58A7043ULL, 0xA1B8C9288915F035ULL, 0x0747745825619509ULL, 0xA2749FF38CB433D0ULL, 
            0xD34D0D066EF210D3ULL, 0xFC7C89F6F95A6DD9ULL, 0x318E5825EC86E92EULL, 0x88CA5E56119D7626ULL
        },
        {
            0xE040491B585DD871ULL, 0x371867832161AB88ULL, 0x2ED073E352C5C57DULL, 0x925FABBDC4A0BEE2ULL, 
            0x30CD98F978D7242AULL, 0xA0A2EB73E8917470ULL, 0x0DBE66CA0CFC62C6ULL, 0x4383A5744CFFA436ULL, 
            0xF4CC2AB3CB574A30ULL, 0x403B6DF20117CA2CULL, 0x2B7B2D5990FC784FULL, 0x88F35F82AE71B9FDULL, 
            0xC97B6AB77F474CF6ULL, 0x8C5F781FA10B075EULL, 0x5E8BDB78E0EE7586ULL, 0xE53BB4C184AEE727ULL, 
            0xD6DB83E44C0B02C0ULL, 0x9EB9E8FA69B7CD05ULL, 0xF60F588343CAC8A9ULL, 0xB741E55C27C8C41AULL, 
            0x2F94A09FC05019A4ULL, 0xE13663770FEC73C3ULL, 0x11DA08B8AC46B3CFULL, 0x7EB0FB7FF9FA8FF6ULL, 
            0x271D732FA9BE26C1ULL, 0x828A55EC892BFA90ULL, 0x3BC4A10000732BACULL, 0xF47EE1A52057C614ULL, 
            0xA01124ADEF004C46ULL, 0x7F18940B776A768EULL, 0x84BA5615E385B7D2ULL, 0x9693D1716CE8B0D9ULL
        },
        {
            0x54A021F027C03FC2ULL, 0x8B73D9E4EFAAD943ULL, 0x832A84B41D181D6DULL, 0x996FCE407404FC26ULL, 
            0x2500C8A4A7226682ULL, 0x232751B78178DEF8ULL, 0x67DB73066FFE04ABULL, 0x46748CEA629FA296ULL, 
            0xC4A0B0BD245F4C20ULL, 0x6D3E1BFBAA4C6DBBULL, 0xB70FA6A2F788B0C3ULL, 0x7E063F9EC4143441ULL, 
            0x0F2F5D2612884884ULL, 0x0297218A90C8A1AEULL, 0x0B76D68802CC16EBULL, 0xB49354EEE0984DEFULL, 
            0x11DBE88E2BF73F10ULL, 0xD9B59867D80A3AB6ULL, 0xACF2879A85589359ULL, 0xB7A85EBFDE2528BDULL, 
            0x3B52D66451A62F92ULL, 0x4605A0BD97010EAFULL, 0xF131F8916FE0DA48ULL, 0x069BCC2C05AF5DCBULL, 
            0x60293F4514C94ED7ULL, 0xBB7502E354C5AB08ULL, 0x3AA7FADABB7291C9ULL, 0xDA4B58E8550DC832ULL, 
            0xA325C612F48464DDULL, 0x3E754911DE6112AFULL, 0x2426092573C54145ULL, 0xFED86F604B8ECFE4ULL
        },
        {
            0x93E4A5B75021ACE6ULL, 0x10596323929B7B49ULL, 0x4E263785002D6DC1ULL, 0x6313867BCDAAB654ULL, 
            0x6E636DB11B1E3B70ULL, 0x73CCDF5B7800CF91ULL, 0x5E495DDF10B03C52ULL, 0xCDB5026202E5DD4AULL, 
            0x0CEBD30E241493D2ULL, 0xB3F53A30C0E8D07EULL, 0xF24F6BCD393A5EB0ULL, 0xAEB32078B4DD8256ULL, 
            0xC42381E13E050658ULL, 0x5556E9BBAFA03CB8ULL, 0x628AC338833B0F48ULL, 0xFDB40C2DD244A6D2ULL, 
            0x452B32FC4A3C8814ULL, 0x79801433320236F1ULL, 0xE0A98D08A9CF73A4ULL, 0xCBF8A234AE73ECD5ULL, 
            0xA6A5C191407864BCULL, 0x3C824E304267A06AULL, 0x7455570626465938ULL, 0xFD646C7F765C0B44ULL, 
            0xDFE0D4D2C7AB1AFBULL, 0xC0E1A74F02661D52ULL, 0x9C992E4EC60137B6ULL, 0xC1D25ACCD01F811EULL, 
            0x512C054EDB7060FFULL, 0x7FCA08C45F1AB8A5ULL, 0x28E82C9DEBDD5FECULL, 0xC8685C5966D7AF83ULL
        },
        {
            0x083B32037CEF97A4ULL, 0x625137EC9D489D9CULL, 0x12AB14CB346FA639ULL, 0xBEB111D76468BC20ULL, 
            0xDC387CE64D42E7A3ULL, 0xF1F397C49F363B9DULL, 0x5A64336A1B801307ULL, 0xD386FDF6B4687A87ULL, 
            0x42DFA95C19C1DE72ULL, 0x52E96B82DA787157ULL, 0x4DDF04C85C6D0C45ULL, 0x7D3EAF21CC1290B9ULL, 
            0x0CE18D9F39281259ULL, 0x3786D7480BBB7883ULL, 0xDFF706EEE046A06AULL, 0x5DFD1DABAEF73769ULL, 
            0x315FC66DF659810DULL, 0x5014A94B8D417B93ULL, 0xD062DB7A20C20B36ULL, 0x60D12554275CAE02ULL, 
            0x47F32495C50B023DULL, 0x6F9DB9F25E4E53A9ULL, 0xC6B2DF9802DDE3AEULL, 0x32443F2C250D5E34ULL, 
            0x73D4680238159D26ULL, 0xE1AFE80CC67A15FCULL, 0x9DB5629E88DF6D5DULL, 0x9818D1DE6BFE44A8ULL, 
            0x483754CA320E8324ULL, 0x1F3BBDC498A354E5ULL, 0xB6C245AEDFBCA1E0ULL, 0x83CC74483A9BC405ULL
        }
    },
    {
        {
            0x3FBA435E1A1DDEF9ULL, 0x885575D1C2731B49ULL, 0xD2273B2FF8BD8774ULL, 0xF1360D198A0625E8ULL, 
            0x869BCE54F20C7AEAULL, 0x5D6E4940E0E71C82ULL, 0x802E8559E2C729C5ULL, 0x06AB9BF2DB219676ULL, 
            0x6BDA66F4FDB75A35ULL, 0xD5052B75AB097D87ULL, 0x8364B30742F5C923ULL, 0x2D5CF5A4AE91B910ULL, 
            0x09261D7C70BFBB6AULL, 0x04B321F892636C6BULL, 0xD6B5CE464A4A80AAULL, 0x721D227002968133ULL, 
            0x62FD60335B681019ULL, 0x32A4F9E8F83471DEULL, 0x19E5A7A71C9939E7ULL, 0x568332E359304334ULL, 
            0xD7AF5FBAF86C8258ULL, 0x84260E1A0EAD8618ULL, 0xA4EACDAB998B2816ULL, 0x4EEEC82D47CB195FULL, 
            0x00A2E16E2829F8F2ULL, 0x4023C406CFEB46B5ULL, 0x66EFF426D8B6084AULL, 0xA9789E2F6C54B6A8ULL, 
            0xCEFD60C8DF55DCBAULL, 0x9646A600DF8CF089ULL, 0xC4E11AA87844EAE1ULL, 0x251AFF52C3356F6CULL
        },
        {
            0x04741243DE1D3E95ULL, 0xDE2E4738C5AC558AULL, 0xDA22D6EFDDC1DE23ULL, 0x6ACA60FE0746F165ULL, 
            0x911A723AD229A1EAULL, 0x0067C589863A613EULL, 0xBBB747148C08F1F7ULL, 0x7DDBC397765614DCULL, 
            0xDC9DCE16B855EA5EULL, 0xDF63C249BBA41FFEULL, 0xE6FFF9A6C969661BULL, 0x9CB6E5F62EA2320CULL, 
            0x4E1E0803E70E1354ULL, 0x843872402EE6A815ULL, 0x85609C223306171BULL, 0xA8CFB23FE4DAAB2AULL, 
            0x9CAB29CE2913D531ULL, 0x04183E374EF9F009ULL, 0xF89EECADCD96D53BULL, 0x3D2F6FCA0AC7AB17ULL, 
            0x5B6814C2180B9729ULL, 0xFC57900B9A9B6B76ULL, 0x90749B28B244E51BULL, 0xDC54CA33B76399A0ULL, 
            0x79D7ADDADF4750ECULL, 0x38E36A472302EDEAULL, 0x7E909680264E954AULL, 0x8BF004C826A46E59ULL, 
            0xE9EAC3647E49E472ULL, 0xE3FEAA73F5AB5DF9ULL, 0xEDEAF98212754A93ULL, 0xCE31F4E5D4CDA560ULL
        },
        {
            0x7526F8DAA098EB87ULL, 0xC070C5A2F07A6439ULL, 0xAABC33643BB1ECFFULL, 0xE6C45924B0B81D4EULL, 
            0x262A0D8F0504275EULL, 0x3A367FCDFC6B2F42ULL, 0xDBFF533B1C69071CULL, 0x41868CCAAB93A8B5ULL, 
            0xA4576F505AC27058ULL, 0x1C9590E0AFE1C655ULL, 0x4895C25A60ADC181ULL, 0x1D7F5A7AA0B81046ULL, 
            0x80307900FB7A209AULL, 0x8B7619E1A8329473ULL, 0xC18DCC153B0DA6F5ULL, 0x9BE61F0D5C449338ULL, 
            0xA4AFB5D6E3E462D8ULL, 0x659FE85A1F8446DDULL, 0x80D0B2586BB2FD40ULL, 0x3E5E9669C543D07DULL, 
            0xE37B5EC0F890DB0EULL, 0x91152736DCC3BA00ULL, 0x55477CA5C6868004ULL, 0xBAF6E50F0885DACFULL, 
            0x78C9609DB29CFCB3ULL, 0x75663DD79CD93922ULL, 0x476C11193C242BF2ULL, 0xE07DC69A1B91DC6EULL, 
            0x940714341E49FF1CULL, 0xDCBF92893B5EB664ULL, 0xFFB66DBDE7DA9E54ULL, 0x053A9D55682C8557ULL
        },
        {
            0xD64787BD681F7CCFULL, 0x7ABCFC75126E554AULL, 0x708496A74AA1801BULL, 0xD8160384CE241302ULL, 
            0x54645DE13212499FULL, 0xF845FF4B136DC73CULL, 0x16845605653EC6A9ULL, 0x362F69EB88675446ULL, 
            0x1EC7D0917103CDD0ULL, 0x9A9C930283B6D571ULL, 0x6CF3DE3D8BF6CF89ULL, 0x53773DBC597C3863ULL, 
            0xA3F2BF10C13D985AULL, 0x5C942ECEEB217ACFULL, 0x78B0E2BCE9C7A147ULL, 0xE633C72638AA85DCULL, 
            0x490CB133A23F59AFULL, 0xBB978C590D2ABD5CULL, 0x99C19B9AEA8A9227ULL, 0x172B8D25E3BC8008ULL, 
            0x4F1C26C9D5CB88AAULL, 0x6E4D18E694DFC6A0ULL, 0x43BB62FC2009FC14ULL, 0xAAA37A4D2D53F0FEULL, 
            0xE66D8DD94D5DC08AULL, 0x81E6B23743037278ULL, 0xDB36F8B7EE80A623ULL, 0xAEF601B512EBE6F5ULL, 
            0x49AF476CD74696CFULL, 0x4B736AEF4D35E2BAULL, 0xEAA3A627FF7E97EFULL, 0x427FD2E4516B2213ULL
        },
        {
            0x8CCF28E520C1A5D6ULL, 0x27D9824624523819ULL, 0xAF2B192B776EE39BULL, 0x75F4C48C3D3272A5ULL, 
            0xAF4729B5E56787D6ULL, 0x32B203A846C69A48ULL, 0x24F9D0DE46748C4CULL, 0xBC136CECD9538E40ULL, 
            0x4DF5F2F67C5B009CULL, 0xF0932EC82ED39CAAULL, 0xABDD784E545938AEULL, 0xC2E47590F3649EEBULL, 
            0x2923D1A58A432574ULL, 0xDAD49635254D77E5ULL, 0xD02E42AFA8EF415EULL, 0x982A695801ADD894ULL, 
            0x335ADD1152A6706DULL, 0x632D36CFCB3E74CAULL, 0xF7C70F185A04C5F5ULL, 0xBCA0B1FBC0BC31DFULL, 
            0x168D3A9CE31C397CULL, 0xF5AD3702259CF86FULL, 0xBB812A35393D0A07ULL, 0x501B0CC8415A5691ULL, 
            0xB00CAA98E5C81970ULL, 0xC14AA9455C52952FULL, 0x684D38CBC78A3060ULL, 0xE5F4E5E9817FA6FBULL, 
            0x7D19168264BC941AULL, 0xC148AEADC3960EB8ULL, 0x9D704782C0D51CE0ULL, 0x80BF809F4E1CBF18ULL
        },
        {
            0x15741452EC3938E0ULL, 0x15E7F85ADC52A412ULL, 0xDE1C2BD1ABA9E542ULL, 0x4072F998E80E1CB1ULL, 
            0xD35130D26A2BA3F2ULL, 0x3A5FC7EE3B5FC9A7ULL, 0x0C736C819D8DE211ULL, 0xAA9EEC36A4A9532BULL, 
            0xE62B61D246CBE24EULL, 0xC5B0AD30CA2FD05CULL, 0x8013374F20E1A7D1ULL, 0xE71E9FC280730A5BULL, 
            0x1C33474CC798927DULL, 0xB0AC37FCABF103B3ULL, 0x354D107B8654E300ULL, 0xD3C754D753F50A14ULL, 
            0x1B97D37BBD1E89A4ULL, 0x572CAA2294022944ULL, 0xE452EAFA4B9DFC7DULL, 0x61ABB9238A12CFD8ULL, 
            0xA6BCE9D42E585D7CULL, 0x93C92EA7FAD3F490ULL, 0x9C7FBDCBCBA69105ULL, 0x778F84DD72E079F0ULL, 
            0xCF6DE7D81215F789ULL, 0x40570AC7C7ABA595ULL, 0x3BE65B76707175C0ULL, 0x0CDB98765411FF3CULL, 
            0x205D7C1AE21FF0D5ULL, 0xEF086275952F8EFAULL, 0x3E9181CDC9905125ULL, 0xDCF26E7DC8F32C4AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kPhaseBConstants = {
    0xBCF4C6B1CB2F22D0ULL,
    0x7273A195C1490755ULL,
    0xD5C36C578FDC6693ULL,
    0xBCF4C6B1CB2F22D0ULL,
    0x7273A195C1490755ULL,
    0xD5C36C578FDC6693ULL,
    0xB667F3EC599220ADULL,
    0xA302FAA0F0D22059ULL,
    0x56,
    0x91,
    0xD3,
    0x6E,
    0xE6,
    0xED,
    0xB7,
    0x86
};

const TwistDomainSaltSet TwistExpander_Gemma::kPhaseCSalts = {
    {
        {
            0xBE402145404B0818ULL, 0xA154DB40661139B0ULL, 0x355629303E7F3148ULL, 0x9F777E5798964505ULL, 
            0xD326023C007C6B17ULL, 0xA3F11E20CD5BA84EULL, 0xF4EC8A4A5800698DULL, 0xDBF6FD7D5A57570EULL, 
            0x09A39F2B1F82863DULL, 0xB73F61AC7912C2A8ULL, 0x177606D67F0CE759ULL, 0x7D8C17B941A2676CULL, 
            0x7E520DAC4B256DADULL, 0xFC4D8C28A6D2922AULL, 0xD19B609E3E7A4ED8ULL, 0x30EC4940CAD7B6B1ULL, 
            0x68CF3E66E6DDAF0CULL, 0xD1415B9521068D16ULL, 0xF3E89E8D56C03720ULL, 0x97A36670D38E1B03ULL, 
            0x16342041C0254C8AULL, 0x473E9863A1395C9DULL, 0xBAD57A3CA9E8549CULL, 0xB09A80A9F7B63274ULL, 
            0xD178043288CAA1EFULL, 0x2EB5CBF89EC2192BULL, 0x31979A57344FADA6ULL, 0x5EE9B3B026D64F8AULL, 
            0x854003404E4C5A0DULL, 0x4749E84F2B333EFBULL, 0xD85B2BBF3A501ADCULL, 0x188DB73C37F92A03ULL
        },
        {
            0x5194EF7DEB27C335ULL, 0x09683FFD43A44CFBULL, 0x56C397EEAA3F62C4ULL, 0x8EB2D7174B098BFEULL, 
            0x5209D887B05FE083ULL, 0x83BD32E45ACDD037ULL, 0x4140FD653739EA31ULL, 0x06A6420D097EB939ULL, 
            0xE2DD722AC4D31FE3ULL, 0xFD8065BDBDDFEA2CULL, 0xFEE2180C894A3960ULL, 0x98272EC977761060ULL, 
            0x95C924C3E571D52FULL, 0xA8746B7B15FF5B6EULL, 0x9251AF6E5E8F5861ULL, 0x5830E44F8D4A0F89ULL, 
            0xEE5668F302DAA769ULL, 0xA8B012903C8C1B5AULL, 0x07C12FC236D749C9ULL, 0x7D26707E3EF5BB88ULL, 
            0xD64C87B4C11CC89DULL, 0x426C24F35CEAB0A6ULL, 0x726E4F45FD0A8468ULL, 0x02EA2413C0B930C4ULL, 
            0x2C2F917613D6CAB7ULL, 0xE4D304749E4353BDULL, 0xD7EADEC6AB93AF3BULL, 0xA0A19E997ED56C9CULL, 
            0x6F89C2465EF7E832ULL, 0xC05CE56EC3ED9D1CULL, 0x752F92F0A2075F52ULL, 0x760547528AE666CDULL
        },
        {
            0xDD7DB925426A8E11ULL, 0x6C13CB373D4E8839ULL, 0x454BDB5D7A99BE7CULL, 0x4FC1111EF4E005C5ULL, 
            0x0538EFBD15774EE3ULL, 0x0BE50DC7E971F765ULL, 0x49FBEE65700999FDULL, 0xEDA0D06416D1FE97ULL, 
            0xAA6803EECFF18F3BULL, 0x0132C0818275BF7CULL, 0x1B35329636E87AB3ULL, 0xC403E2EA72A33B68ULL, 
            0xDC82FCE1F2125178ULL, 0x77B11E8F67FCB06DULL, 0xBFF1EE32FD2F19A2ULL, 0xEDD8E08D757E2AA2ULL, 
            0xC4C94A37DE0E73B2ULL, 0x8C7A263243546576ULL, 0xB68EA9224DE4D197ULL, 0x3BBBCAE220168291ULL, 
            0xE093566D57F00930ULL, 0x2E4755E63B8ADCE3ULL, 0xA2E559D261FCD139ULL, 0x2421E6B9CDF04EA8ULL, 
            0xE7F83B4AEA96946DULL, 0x09E2F21C09B88D0AULL, 0xB0D42981EE99DE9EULL, 0x6B30C864C5ED1DB7ULL, 
            0xB6D8E5197334993EULL, 0x7565F4F6F57D6549ULL, 0xBB644FA3E7041C7FULL, 0x511060C33849902DULL
        },
        {
            0xC557DFD1B2746D02ULL, 0x578C1C332E3698E4ULL, 0x4CB2FCE5557434CEULL, 0x1A04B72E67797A84ULL, 
            0x8F7A9330712F849EULL, 0xED4A82D7C2984377ULL, 0x81BF2343E12B9690ULL, 0xA8827CF7B76C5233ULL, 
            0xF6705ECCFC1DD981ULL, 0x0C09A9C374980439ULL, 0xFF866F3FA6D44EDFULL, 0x65DAF6E5F6016C65ULL, 
            0x93BC2C168A4CDEA3ULL, 0xD79BBE5F71302569ULL, 0x1A97A6645ACEA54BULL, 0xE9F32EDDA27E3C4BULL, 
            0x85DB52B127346D08ULL, 0x1CBCE7F46FC9BC32ULL, 0x7B3701E1AA03DF5BULL, 0xBA80AE9A9D74EAB3ULL, 
            0xDC7CD182BC5DBBABULL, 0x7CC53BAE876D7576ULL, 0x245E37F379CCDA09ULL, 0x7A53AC8E351F7CE0ULL, 
            0x2146FBE8F9469131ULL, 0x7436FA68B9E7C5F5ULL, 0x48784F531F0E3879ULL, 0x7ACBC885733ADF32ULL, 
            0x6A37075C6497BAABULL, 0x5FE85243E8B7E155ULL, 0x22F5DCEAC0450439ULL, 0xEE708F8ACDF6D1B5ULL
        },
        {
            0xBDDEBC1CBBBDEF1CULL, 0x0BA793B39BE2A486ULL, 0x7DFDFF1021276DE8ULL, 0xC4F7B4E1726CC632ULL, 
            0x448F3C3288AA36CAULL, 0xEA15CDD525E04842ULL, 0x830E93394E457821ULL, 0x0AB2B6EC91041687ULL, 
            0x53287EC75E84AE59ULL, 0x579E52000679C503ULL, 0x562227B05FC45C73ULL, 0x98B236ABF1D8298CULL, 
            0x4ECED91B14B3DEC4ULL, 0x7102E11C548CC07DULL, 0x99BB7EDA4FBDE3B7ULL, 0xBC74AE5755EBB5C2ULL, 
            0x1B43FD25E6FCB999ULL, 0x289A3B79E209C8DFULL, 0x0E005F8BEB257E76ULL, 0xA6E04243B7F51BB2ULL, 
            0xE7CE6F941C8BBB3AULL, 0x808AD7D79873C09CULL, 0xCAFBA42EC2BE7FF6ULL, 0xE5BC02E7D4722ADFULL, 
            0x30036CF70C93259FULL, 0xE24F9A35675EDA96ULL, 0x1CC7ED857EBAEB27ULL, 0xE526698AEACA8FF8ULL, 
            0xDEAE7DED6EF1BF84ULL, 0xA2BC91A68B5D8F48ULL, 0xD8950189616E6E70ULL, 0xB7549A4E077F2C23ULL
        },
        {
            0x957657B966FDBD9AULL, 0x0FE44355DBE939A7ULL, 0x0F15CFEC38639AAFULL, 0x2D201006C374559EULL, 
            0xCE2CF3F7A3961784ULL, 0x61871AA0F4F9DC0CULL, 0x863CC364F801F310ULL, 0x5F6218882E10B829ULL, 
            0xDF9DFB363AB52103ULL, 0x6FA52ECBA709A9A8ULL, 0xEA483B463E435E3EULL, 0xA26B55BCA2066857ULL, 
            0x7BAD6047EE117D1FULL, 0x1B25BD95C437B6A0ULL, 0xBEC3FB7E628E2553ULL, 0x19FACF4ED95AB675ULL, 
            0x22E9F3C285CD5609ULL, 0x965843429BAB1131ULL, 0x42E0BD54A3404BC2ULL, 0xA5FA4B5ED3A46AABULL, 
            0xF985042DC9D3AE12ULL, 0x516CE27633D18816ULL, 0x4278841CFC0538FEULL, 0xE7E66490E68DD58EULL, 
            0x0B44DBC8F684D439ULL, 0xDF644C9A4B4935D3ULL, 0x6932B57E1E34A976ULL, 0x9BB616546E5DD3C7ULL, 
            0xF4A31D07C3152224ULL, 0x20A2AB425E5D9EB0ULL, 0x95371B67CB7292E0ULL, 0x9EC715E794661568ULL
        }
    },
    {
        {
            0x36D07C7ACA030580ULL, 0x72FC1F390681BAF1ULL, 0x96E0277D7D6CF030ULL, 0x8E2138C6E4ED4D9BULL, 
            0xB219CBAB0F57306FULL, 0x2843BDAF2E7E5277ULL, 0x9E7483ED8DCDF900ULL, 0x7CEBA28C61BC2F5DULL, 
            0x99B3BCB550288FC0ULL, 0xB46DDB20E94561B1ULL, 0xEA849FACA2B0E786ULL, 0x434162639A412CDEULL, 
            0x57BAD8C468AEFD90ULL, 0xC90305D27B065CA2ULL, 0x5C60D1C3F91EB253ULL, 0xCADCB465ABFDCADEULL, 
            0x2A60B66125C52625ULL, 0x777E68A9367F4824ULL, 0x9990F997F7726776ULL, 0x5256CF93EAC06339ULL, 
            0x2BA3A4ECE2A3AE44ULL, 0x5D85EF006672A3C7ULL, 0x56CF50D34D32258CULL, 0x920ACE02D8F38C18ULL, 
            0xB56D12B5DEDDF08EULL, 0x3A858C8853FF227DULL, 0x9E9A2D2BD87307DCULL, 0xF05A8F37D54AB915ULL, 
            0xCAF2016F5046716AULL, 0x549486148E8FB5D2ULL, 0x63B3C931F27869CEULL, 0x060016054EA88626ULL
        },
        {
            0x61233579B6CE614EULL, 0x1F1D13E7AFD7274FULL, 0xA421ED54E686DFA6ULL, 0x9F2FAE352D55E928ULL, 
            0xA527A42FE788814FULL, 0x7E8D0B559DC37245ULL, 0x0F9EC99C80F100E5ULL, 0x95B3F809277E3529ULL, 
            0xD77DB8115A1AFD38ULL, 0x1735A5192A2CC387ULL, 0xAE53C5AB84EC5C42ULL, 0xEAC22454D1930940ULL, 
            0x32E6AC588F5E75B8ULL, 0xB64EB904AA933C31ULL, 0x5D625230F3845D6EULL, 0x8150DF88D58C059AULL, 
            0x022D8D4E88FC3EBEULL, 0x9112B5B1A6695EE9ULL, 0xB084785B3C3994B6ULL, 0x613D38D56A578127ULL, 
            0x28C1EA277678251AULL, 0x9E087B8466D274FBULL, 0xF68CFCA032B7576AULL, 0xE43752C4E93F6C9FULL, 
            0xDC35E14600B761FEULL, 0x372464A52F8274C2ULL, 0x3538F6CF8EAD0250ULL, 0x009E10EDAD243414ULL, 
            0x53C1F364DFDEE97BULL, 0x31E77DDE48E47BA9ULL, 0xA27008F280F93F52ULL, 0xC7CD96B416610DFDULL
        },
        {
            0xD46D9CEF6EC1E388ULL, 0x10C2C9EF8564E298ULL, 0x9ED861E8372E3D42ULL, 0x8171AD7C112FECBDULL, 
            0x8B4D6540D871427EULL, 0xBE68DECC05A8F959ULL, 0x183F400DBB22F073ULL, 0x347DC4ACFCEF4DEEULL, 
            0x33E0D0A022707803ULL, 0xD375E9F97BE1F0A8ULL, 0xE0E7A767A86911BFULL, 0xB973C2C34F7068AAULL, 
            0x93677713949170B3ULL, 0x1829071C27D9D517ULL, 0x8D369DDD7ECCE8FAULL, 0xDEF89B4C9A50E330ULL, 
            0x91371810CCBF2685ULL, 0x77B4FDC510B27296ULL, 0xB7EB4A5B1F38CBF5ULL, 0x53E8D1CFCCF2AE3CULL, 
            0x98C58572F4D813CAULL, 0x9D2DEA4492F4F565ULL, 0xAFC957B76EB96FD7ULL, 0x4302E1331F671B3DULL, 
            0xB443248396647502ULL, 0x2EA41498FF2871E7ULL, 0x44C352FCFDCCD05EULL, 0x2E83199E277A58B4ULL, 
            0x568A0737305D6B8AULL, 0x25ED1B1A6753219FULL, 0x374303D1058BDF2EULL, 0x9980EEB1C8FB897BULL
        },
        {
            0xFC9E546A42210529ULL, 0x6E352C8E0C6A4580ULL, 0x9A7724060B66EF62ULL, 0x1402518C123FBDCFULL, 
            0x79C1D689077EA576ULL, 0xD2CE31B2D7EE96FBULL, 0x9EBF8F4F097847A7ULL, 0x8551C701D5C82C6DULL, 
            0xA03AE06DE9A26984ULL, 0x563E676DA12BEC52ULL, 0xD7DDCC19EA94F62AULL, 0xBCFDA8E6D16581C2ULL, 
            0xD8D4DC53A76A448DULL, 0xDCC1E8E4F508DD00ULL, 0x90EF311872C58950ULL, 0x14A5034D9B6858FBULL, 
            0xCB7E02C91F63E0D9ULL, 0x64824509645FB40CULL, 0x5A22457CE6AC580EULL, 0xD6ED020FBF9CF4B2ULL, 
            0x8BD533F851DE4601ULL, 0x1C580BEEE05C72AFULL, 0x65688188F5A0A897ULL, 0x2434F35CB63A4E55ULL, 
            0x9E6E993307DDB643ULL, 0xDC70A4962D39BAD4ULL, 0x0287DC83139D8B7AULL, 0xD73AD3A03670CDE9ULL, 
            0x7CCAE21EA32408F6ULL, 0x08DD8D43EC414143ULL, 0xBDCC4D7ED3004436ULL, 0x3E537DDEB2173101ULL
        },
        {
            0xC21735E1784846A8ULL, 0x9A0A9E68AA4F836CULL, 0x2845ABDB56A1C92EULL, 0x76001C9AB9549B19ULL, 
            0xA20BCBA93FD4E44AULL, 0x46B2FAD4AFF2BD60ULL, 0x358A78D0C27CE3D3ULL, 0x48639909E5576D18ULL, 
            0x4A290E7B6951C6EEULL, 0x856E8D891FD47C28ULL, 0x5259A1310BDA7DD7ULL, 0x5202B5AF2AB3754BULL, 
            0x114C7ECFC5784878ULL, 0x2CA47146482E77CEULL, 0xA11526637B4DA7F2ULL, 0x18DA7867C605B367ULL, 
            0x3624DBF5DFE6E2BEULL, 0x707A607F6A97DF03ULL, 0x496C8ED1A5CBD8D2ULL, 0x88DCF348D0CD5599ULL, 
            0xBE4CABA5794991A6ULL, 0x459E34D4A5659D53ULL, 0x8E19F1A134077A5AULL, 0x8D3F6417A66064CEULL, 
            0xFD5821CFDA553CE8ULL, 0xE77BC4874E7B5ED3ULL, 0x2514E989E3B907CFULL, 0x198848D7A600B383ULL, 
            0xFC58C25A9D0FBCD6ULL, 0xEA13E9552AF64DE1ULL, 0x41A4E198AB8273B8ULL, 0x27B1F7C991709707ULL
        },
        {
            0x9BBA43A0EB374A8BULL, 0xB83AECFA3184DEA1ULL, 0x12BC8CB64CA13A8BULL, 0x87EA621177D64E83ULL, 
            0xD7A234B700179D9BULL, 0xC57E3C105A8F6486ULL, 0xCDFE1A04AB5F2F1EULL, 0xB41683D97BE00DC9ULL, 
            0x8B382B2EAFEE38ACULL, 0xEE691D3532CB9B49ULL, 0xEB9B4296717C2139ULL, 0xE3923C9975B384A5ULL, 
            0x24456A45C772B96CULL, 0x4A08183282ABD3B9ULL, 0xC479451ED947585CULL, 0x21098836D84E77D3ULL, 
            0x8A150B4B152E42E5ULL, 0xE7B368AE1127CD09ULL, 0xACE08700AFB22F62ULL, 0x7E1A7965D7AF18F6ULL, 
            0x4B25C594BBEA7288ULL, 0xA507D3061C205E9DULL, 0x7661923B2D228D7EULL, 0x8A1A774D121227BDULL, 
            0xFDD4E67D4886025BULL, 0x1EBB038D0E22118AULL, 0x87D09F8DD0DE5FDDULL, 0xDD14292106BF7BCDULL, 
            0x095E3A94C6760354ULL, 0x918CC6EF77B7763AULL, 0x548A6F90184C394CULL, 0x2E10A6B39905DBC9ULL
        }
    },
    {
        {
            0x5B8A2EA37B4FE05CULL, 0x73504F0E4ACBCE2BULL, 0x05B6F7E24FFC5E46ULL, 0x28E5E1C54330446CULL, 
            0x8D37C42B2D0744CBULL, 0x4F42662AFF8EC79BULL, 0xA2FFD7F580B4A26DULL, 0xB73D2FE3EA664204ULL, 
            0x6F1BF937FA6571DDULL, 0xBFF5F12FE54E37F7ULL, 0xEAE2026492744589ULL, 0x3892F993A86AB3B9ULL, 
            0xAE6663C4D960A400ULL, 0xDA598737711130F1ULL, 0x84781C643D0A24A3ULL, 0x3D0A845A4CBB0753ULL, 
            0x21701EEC6D18A438ULL, 0xB43F866F33689EF3ULL, 0x08DF8796C52AED86ULL, 0xAE47EE4C68E2527FULL, 
            0xC2424A0BC40BACB2ULL, 0x98A9F116886D8D1AULL, 0x3A570CED63CBDE9BULL, 0x3DD58CA1EFBE0862ULL, 
            0xFB275AD5E602574CULL, 0x1B8080D39813C919ULL, 0x782B8D72DA89559EULL, 0x7C4D417A7B22324DULL, 
            0x65BBD226C2E51F85ULL, 0x349A222EDF6B6287ULL, 0x3BDB0C59EDF9D23EULL, 0xE600C8E2932206BEULL
        },
        {
            0xA49B29ECD356EC27ULL, 0x6A99F9EC7037494DULL, 0x3D054C0DD509A12EULL, 0xFA8EA64BB6175B44ULL, 
            0xEB8A28487607588EULL, 0xB56F5F154AF8320AULL, 0x2016A7C17A27946FULL, 0xF63E38DB668F6422ULL, 
            0x30B5167A525A0879ULL, 0x218C1A75C8079754ULL, 0xB7B9284186140D17ULL, 0xC2609998A9A633FCULL, 
            0x2F725BC5132BF6A5ULL, 0x62CB7C4EFA1BFE43ULL, 0x8CA9C288F33FA59AULL, 0xDEF4A4823CCF3412ULL, 
            0x22451F89CEEE1281ULL, 0x25A95018E0346018ULL, 0xC235395038D5951DULL, 0x37A741A1ABE050FDULL, 
            0xCC7CCD7CE4100F46ULL, 0x04F7DD90F71A6D93ULL, 0xF0D96D607B06CC68ULL, 0xF84DE4DFDA6D3A5EULL, 
            0xBE0839294C98E1DAULL, 0x8665AA6B1DC70B2FULL, 0x868BC1AED4F66F2BULL, 0x83399429BBA1E81DULL, 
            0xAE91A3CEDAF2E98BULL, 0x7CD92B82EFACC171ULL, 0xD5FB9B484CA65ADAULL, 0x0ED8878FFD46EA44ULL
        },
        {
            0x3FBC54BFFD451BC9ULL, 0xBE5929E6026889DEULL, 0x2510B702BEA50E10ULL, 0x107D50CB5A3E8162ULL, 
            0x419DACF69AFF1BE9ULL, 0x714F2B09DAE310D6ULL, 0x7C09ECBA986296BDULL, 0xD3C6659EA6E4D792ULL, 
            0x8E7A0107817DD6DFULL, 0x73F9CFFA09F1FFC6ULL, 0x247B402A12A07CD8ULL, 0x3B74288FC425C691ULL, 
            0xA7AD09ED8BE33388ULL, 0x4B1D60588A9E228BULL, 0x00FA71B62AC372BDULL, 0x345A5DD3055B4495ULL, 
            0xC429DCFEA2CB41D6ULL, 0x594C59FACD967CDCULL, 0x1C4355F99A8F8CF0ULL, 0xA9D26691F0486D95ULL, 
            0x85B8B53364180FFFULL, 0x4E038B6D46475200ULL, 0x5FAEAAEAC6F2C394ULL, 0x4E9A7B02EB1AACF9ULL, 
            0x8834899CEFC4D535ULL, 0xAD0AAC240052CDB7ULL, 0xFA75AB4821386FD8ULL, 0x58D4B48F5965A64FULL, 
            0x6317834857EEE93BULL, 0x1FD110D40284A595ULL, 0x52B2987C36837775ULL, 0x4AB3CBEB17AB6D1BULL
        },
        {
            0x9211CD594578905FULL, 0x4B767A9C9F0A8563ULL, 0x54C21E02C83EEEB6ULL, 0x3FD670D228488878ULL, 
            0x811C0481CF4F5B2EULL, 0x0554A1E49A33CDCDULL, 0x2587AFBE9AC2EF35ULL, 0x9532E698AEE513E7ULL, 
            0xE60C543E41DECFAEULL, 0x9BAF7D5B792B0769ULL, 0x4B096A15B5C6093EULL, 0xFF4D96F9107916D7ULL, 
            0x6E5E170D0C0EBAF8ULL, 0x7F86F41E002EC76BULL, 0x68E65F108B2FD139ULL, 0x5A185B563214A697ULL, 
            0x6995C3F65378DD69ULL, 0xEF1A698AED3DE414ULL, 0x9DFDA122D49957D3ULL, 0xF7B4F589B1D45CE5ULL, 
            0x4D4586191528CF39ULL, 0x7E5F24BCCAEB9C29ULL, 0x4CA3BB4D107ECEBBULL, 0xDEE1526994093019ULL, 
            0x18DBEBF934610B3DULL, 0x4F127CE7B4BA7A9CULL, 0x7AA45A44269BCFACULL, 0xFD142A12775760B1ULL, 
            0x7C0AE38C333D70AFULL, 0xD654FFA4550A1E45ULL, 0x8DC00D4E9BC34AF9ULL, 0xD70F746B3ACAD80BULL
        },
        {
            0xF70703189B9E4FEAULL, 0xD4A616B7116B1D49ULL, 0x7A2C5D1F70086DF5ULL, 0xBF64E18FE8E6B48BULL, 
            0x4802323ED235CE6FULL, 0xA957890374B2C7F0ULL, 0xC604FAABCE55C2A2ULL, 0x8A6D021950C285AEULL, 
            0x12F5F4AE89582095ULL, 0xE9F8308B96973840ULL, 0x2BBB9A3E78C33495ULL, 0x9C03EB5E30FEDB1CULL, 
            0x27EC696090072236ULL, 0x378D82E4D307E3A0ULL, 0x9BE6C363F62AECB3ULL, 0x493BD69198C3097AULL, 
            0x72141806DA2F0EE2ULL, 0x42EEAEDD5DB7896BULL, 0xF25F997F7A9A632EULL, 0x4BC844F5703C4A8CULL, 
            0x5B8F4E5CF24FC81BULL, 0xDE117D237CEC5824ULL, 0x6E7E920F131BD4EBULL, 0xB863746A8031A928ULL, 
            0x22EDDA7323E704DEULL, 0x9413E2292F6F6822ULL, 0xB74A8816E80794DEULL, 0x6DC38ED1A0FBE205ULL, 
            0xD6EB327B87F8F645ULL, 0xD9148B812AC25E86ULL, 0xEE2B29FFC34C74C9ULL, 0x2C7AEB377CDCC715ULL
        },
        {
            0x5348A28FEBA9E3A6ULL, 0x1AFA18BDBE32491FULL, 0xBE0FA2DEB78EF5F0ULL, 0x53F7FDC0818BE9CAULL, 
            0x1558ABB7571F78D7ULL, 0x0DCE37A5C151F63DULL, 0x8670DF83B597F41EULL, 0x2EB6BF4B192D72C4ULL, 
            0x4226FEF7C45AB949ULL, 0x1AFE1566DD70690AULL, 0xD7A1193B556D03ECULL, 0xE0EA5302D5BEA1EBULL, 
            0x6146737E692F691DULL, 0x2CD2E9DE053B22A9ULL, 0x6EFAEF5BD8EA7C74ULL, 0xCC65141A380DDC11ULL, 
            0x52A582BF4C98CEC2ULL, 0x5814F33B1240323DULL, 0xE06499C87504860FULL, 0x027432981C7F9785ULL, 
            0x6CF23872E236C5CFULL, 0x4FFCCD494F1D4071ULL, 0x3E60637B19B74704ULL, 0xC66256909FAEBB99ULL, 
            0x7E7E844AE3FB3A8FULL, 0x17660F8906ABA652ULL, 0x3ADD2ACC85AACB9FULL, 0xDC8A96C847B5434DULL, 
            0xE8D4EE1ED6F8F261ULL, 0x16196C215390D3EFULL, 0xEE4D6F5869654F34ULL, 0xF9ABDA1FEF5E2E45ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kPhaseCConstants = {
    0xBD97873C52B61AA6ULL,
    0xA2D50C41292924CAULL,
    0x79A635F5E7991812ULL,
    0xBD97873C52B61AA6ULL,
    0xA2D50C41292924CAULL,
    0x79A635F5E7991812ULL,
    0x033B1E51213169A0ULL,
    0x27BBE1777F17CCDEULL,
    0x2E,
    0x99,
    0xDF,
    0x91,
    0x1D,
    0x9E,
    0xC8,
    0x96
};

const TwistDomainSaltSet TwistExpander_Gemma::kPhaseDSalts = {
    {
        {
            0x6F71528D8741262BULL, 0x2B2DD15AF3BAAB3FULL, 0xBF1A31DA404E75F3ULL, 0x17B98882B6716404ULL, 
            0x425D16887E80A5BDULL, 0x436D30EA7E855C00ULL, 0xF369308A6C78A749ULL, 0x002D0BC22AC59BDDULL, 
            0x2A9CDAB47B54AEEDULL, 0x97AD02BB1E85FF40ULL, 0x74C4BFD7BBB839B4ULL, 0x6043F4BF64A07EFCULL, 
            0x396C3F8AEC8CDB13ULL, 0x8BBA38BCA5940D32ULL, 0x2E088292879C3201ULL, 0x6EE7197F79B16871ULL, 
            0x308CFBE49A152A25ULL, 0x73EDBEF28A0D79E9ULL, 0x89961A11E63DEA01ULL, 0xED7C9EA142DF9A0CULL, 
            0xE136CD42E01C5176ULL, 0x543A87872D5033D3ULL, 0x82B84E8CD59F934AULL, 0x331761EB5F06565EULL, 
            0xF0B05F2C03BBCD68ULL, 0xE37F6F7801BC5DEEULL, 0x22EAB21B1EA3FB72ULL, 0x12FAD449F0520435ULL, 
            0x00F7C7B73A7F6875ULL, 0x75E4CF6A4C8E16E7ULL, 0x2BF8AD742DF7C08FULL, 0x63666752CE6922CAULL
        },
        {
            0xD698C1A6614D0695ULL, 0xA0C1139F490DDEF6ULL, 0x15D0CDA6D1E4A6C1ULL, 0x1C543A7CE2897C04ULL, 
            0xD6088A646A4A01FFULL, 0xFC436E5D6E3F33D8ULL, 0x1DFBD62DE0EB6AF5ULL, 0xC362629EB9948327ULL, 
            0x513C23B033A97A38ULL, 0x9E645782E0CEB160ULL, 0xCF0140AA34CE61D7ULL, 0x2B0A0CFDA77F9B02ULL, 
            0x3B6BE00C81012C36ULL, 0xE4F86205781E4A68ULL, 0x0755B5667C9C0A90ULL, 0x67368D94EB41A99EULL, 
            0x447081ED5D0FE7BFULL, 0x6423498BC8AC2BF3ULL, 0x14AE79A7B0E88AD5ULL, 0x87FDD7159F577290ULL, 
            0x94F716446E4656B8ULL, 0x7414BFE90019C084ULL, 0x9834BEFA7CF2CC3BULL, 0xF76C3B38629A9742ULL, 
            0x16212568C4F540CDULL, 0x7CD3E13894EA36D0ULL, 0x8417F918C7F55437ULL, 0xB3896E4DFC6A4E62ULL, 
            0xDAE1CAF255EAB5FDULL, 0x6451EB4E721B8A81ULL, 0x67DA8544A618618BULL, 0xFF5EF1FDD0BC734AULL
        },
        {
            0x3D59F406D6BAF36FULL, 0x3D3846DAFDE5955BULL, 0x0D677E59C008FD28ULL, 0xD3040D1794DA82B2ULL, 
            0x02DCEB18713BE253ULL, 0xAF6B85B6B04210CDULL, 0xD73BA86F2423D920ULL, 0xC8947401528A1150ULL, 
            0x7309436ED1B4B582ULL, 0x693C9C4B10BB2648ULL, 0xA9CD2D7ECE4DFD54ULL, 0xFC611E514DD0CBFFULL, 
            0xE9B5E252ECE7CD5AULL, 0x6F7512E3E3499461ULL, 0x7DB97E7D58BAEA75ULL, 0xE5591DB74573AA9AULL, 
            0x7331F82B305F2E5DULL, 0xD43614B012D366B5ULL, 0xB45F8255912FB66FULL, 0x4236AA129CEC0752ULL, 
            0x999D43DBD081894DULL, 0xBC01C8FD55EF9D52ULL, 0x05E8BA346E8BCE72ULL, 0xAEE8BB90DCA0C8D3ULL, 
            0x7246BEC9DB307425ULL, 0x6EBBED973405DCBAULL, 0xF474306A8EBA7CDDULL, 0x6A9C2503F4A84CF4ULL, 
            0x32C36919B39072C4ULL, 0x0411EC4F5C37D6EEULL, 0x150F77343C6CE97AULL, 0x00401758439950FBULL
        },
        {
            0xED276E5F3ABFEB56ULL, 0x97A53288F9C20803ULL, 0x1421FC426F62B4CCULL, 0xEBC0916FE6ABF227ULL, 
            0xBDCA121BBE6F88ADULL, 0x384EF3CF62599CD8ULL, 0x297060784184B248ULL, 0x4705508438F37E8AULL, 
            0xE9DAD42686F3CD0EULL, 0x9676B0B5CC5DC1E2ULL, 0x905D8105561B2B02ULL, 0xCC0EB276409E1D39ULL, 
            0xCF77814035EAA216ULL, 0x7F2559209E8DD52EULL, 0x228CECB37898891BULL, 0x14FCEB02BD888056ULL, 
            0xE3591EF4E7291513ULL, 0xAE96CE64C1C91293ULL, 0xD230AF5249671821ULL, 0xFC614A2FBBD3B20CULL, 
            0xEE1D4A111EAC8286ULL, 0x41510452FEE09FDDULL, 0x68DE822C015F3254ULL, 0x63618CB9C4D03FD8ULL, 
            0x8623FDBB45B0F995ULL, 0x7E2CABBB83BBCDD2ULL, 0x5A71543129E1332CULL, 0xD2493AE17E8B782BULL, 
            0x5DDFA3457343913DULL, 0xBFE2F016B4C38673ULL, 0x970D0C9D49A57CE3ULL, 0xAD04B876B6FB5EB3ULL
        },
        {
            0x765A56AE41DB380DULL, 0xC7790B1B775C92E3ULL, 0x611051911EE9940FULL, 0x6606A667E0731E24ULL, 
            0x1979DCFD9B3E4740ULL, 0x462F673A98FD91DEULL, 0x3624E46C0A6B9488ULL, 0xF8B4B68661559E26ULL, 
            0x7E40886AAE3C8E36ULL, 0x74B9DA9A13DC3B04ULL, 0x470F7D47D7C33015ULL, 0xA15F2BE5297DCC4FULL, 
            0x6C4350F285BAA82CULL, 0x886E9A31B1F07AEDULL, 0x55EFE7559CD56703ULL, 0x44A8AEB9A4A1E51DULL, 
            0x4396B91B8E6B4DEBULL, 0x612BB8BCFC4F41F8ULL, 0x0608BC2F6254D203ULL, 0x472459618EA10B9AULL, 
            0xC8DB59E806954E4AULL, 0xACA3B4DF8197E06FULL, 0xE54F279A5D5DD418ULL, 0x5AE0BF04AFAF98EDULL, 
            0x03365BF9F4082909ULL, 0xD2F831DC82385C62ULL, 0x6302CFE67A028C10ULL, 0x52454571CC2E4E6EULL, 
            0x46B5DE018F08733DULL, 0xD636CCCBC21068D6ULL, 0x9BFB11AA5F6A8898ULL, 0xE3199DC817C2F35CULL
        },
        {
            0x6867DD723D5D62D0ULL, 0x9D8E6FE0E9FAB925ULL, 0x787B8AADC727EDD2ULL, 0xDBED788DAC06E1F5ULL, 
            0xD1F3FF199B079BEBULL, 0xD54315D5B951C761ULL, 0xF9DC376A20D3A25FULL, 0x2BBDDB03CB4CC31EULL, 
            0x048CEA6BE9CA4C96ULL, 0x27D42D3F2A57FDF0ULL, 0x2774DC58B566E76FULL, 0x26965A363A627743ULL, 
            0x0E560AC8DFA29B95ULL, 0x9C9C9D4E452A8762ULL, 0x34CC2547669522A9ULL, 0x9484A19BC8FFC3C7ULL, 
            0xE96B94C52689F534ULL, 0x5FA94D4EB3B47D79ULL, 0x5F3D276BBCB0349FULL, 0x103550B46A5F4B3FULL, 
            0x3B6CA4D4AD6F90F2ULL, 0xD47FE97F047764A0ULL, 0x5811F223A6972F06ULL, 0xC52648D7184450F8ULL, 
            0x330398CC6BE1BA61ULL, 0x70F7798DC0318EF6ULL, 0x130F00CBE57097A5ULL, 0x6F24E8C9CD8913E8ULL, 
            0x2BAEB6F879FABCEEULL, 0x694067E3439070D9ULL, 0x2B458FB7CDE951A4ULL, 0x107F3435A11363F7ULL
        }
    },
    {
        {
            0x525645452563ACC4ULL, 0x7DAF250F33EA1BBCULL, 0xE9008102FE95BCA6ULL, 0x064EDA6F40DA84CAULL, 
            0x81517CE7B05C2247ULL, 0x21949FA73044DE05ULL, 0x2044C867AC84CD7FULL, 0x0EAA4D4A110ECAD4ULL, 
            0x0BC14383965D0824ULL, 0x613DCD82222CB255ULL, 0x0D6669AD8C080F55ULL, 0x43D539B3FF059D46ULL, 
            0x46586C740D4B8DDDULL, 0x61D03216C7990FE3ULL, 0xA2BC6E6FA9AECE58ULL, 0x37985CA2C541A064ULL, 
            0x22A8A5D8DD7728FEULL, 0x90B32F39AC54A7E8ULL, 0x9B1EE2F730CA5BD7ULL, 0x200A4C42CF05A9CAULL, 
            0xA47AE06CC9A0725CULL, 0xBA95BFDB192C2713ULL, 0xE7BD67ABA4592B93ULL, 0xC330CC015AFACD25ULL, 
            0xB3CE8168BE8F95C8ULL, 0xFEDE76204F8DED40ULL, 0x1172245E508B8785ULL, 0x986AE9C0FB1FC025ULL, 
            0xCBD41F9EA7517DA5ULL, 0x2C2D3541A8468D83ULL, 0x8884F21D0E376C23ULL, 0x206ED03F0F743121ULL
        },
        {
            0x569A0E8D6640E362ULL, 0x8D23478B0B111E53ULL, 0x98841935C9FCE3A2ULL, 0xBAC9BF4C93CF866CULL, 
            0x986433E2F016E878ULL, 0xD7D8784E40C950B2ULL, 0x56C47019EA8DA323ULL, 0x858C2FACDC39246EULL, 
            0x688E6E1C09A47FBDULL, 0xE6D44EE3F30193CBULL, 0x07B326263E9C68B5ULL, 0xAC87085E695BBD4AULL, 
            0xB84AD0A31DAD310AULL, 0x8E41E0A9C1F843A5ULL, 0xEFAF1985A53BBCC3ULL, 0xCD792FBB17DC19A5ULL, 
            0x7817B4A466F1DC78ULL, 0xDB88AD7C31CF7D45ULL, 0xF2CB4B79316BBEF5ULL, 0x301D2470E92B95FBULL, 
            0x33E71E2527F9BFA7ULL, 0x5C80DDC3F108276EULL, 0x2EDF4B2DA8EA5267ULL, 0xDDD97DC038EE4286ULL, 
            0x5F5199973C39C4DAULL, 0x77A2BAB14CC74410ULL, 0xE2D163C35DD33BB0ULL, 0x2D51A76A8D52FDFAULL, 
            0x2F6267EBF7AEA7EAULL, 0x611E8BF64C6D0B27ULL, 0x25519547A596BC20ULL, 0x8C0AC79CEE94D5ACULL
        },
        {
            0x86E5893F679CFF0AULL, 0xB5A3E2C4F73A7671ULL, 0x93F82856B1665479ULL, 0x54EF77A470258CEBULL, 
            0xF860E0D01311D737ULL, 0xC798F46524069950ULL, 0xE4D814C63B247556ULL, 0xCFF05FE3A1055A54ULL, 
            0x1BBC2D4AB43838E5ULL, 0x5C01C01419E9BAD2ULL, 0xAD4FE557BDC294F1ULL, 0x8B698B914F0BCE38ULL, 
            0x843E2CB6F3BB8F41ULL, 0x8B18833BC5C8F609ULL, 0x0F0815E317CB5D41ULL, 0x6B703A29A2BCE41CULL, 
            0x2137EA97D847B311ULL, 0x4E7FE0FEA079442DULL, 0x9CEAC6B840C872E5ULL, 0x51EF6905091D6442ULL, 
            0x16764AB5AC0D00BCULL, 0x557C75D27E2ED29EULL, 0x8392234951C65B79ULL, 0x56523934AC8A8A2AULL, 
            0x718664F4BB8CC931ULL, 0x50E4694EDC5209A3ULL, 0xA764588A140141F9ULL, 0x3FECF3E89D94F9CBULL, 
            0xB47CD2C015AB4830ULL, 0x98DCF9D72F8C0825ULL, 0x85B4F63538124538ULL, 0x14329AC0AA61D16BULL
        },
        {
            0x3F4457FE1997E04CULL, 0x529B62DF70E26FA3ULL, 0x7AA36743586D75E1ULL, 0x9E99131BF554DF40ULL, 
            0xC21E6DEF4AC56B75ULL, 0xAB6A4197AEB5D1D1ULL, 0x106377D6946107A2ULL, 0xD68F9DAA79D9ED7BULL, 
            0x9314D747C4DA3615ULL, 0x63295473C537E083ULL, 0x1391E93818D86CBEULL, 0x569CD6197B828990ULL, 
            0xBF4234F7773D0061ULL, 0x5C652CF742398B6EULL, 0x0FE95051A3D886A5ULL, 0x69ADE47CACA599CBULL, 
            0x5750BBAE92C89D97ULL, 0x7529826F09FC2E73ULL, 0x09381410E5DD06DCULL, 0x742672F27F83FFDFULL, 
            0xF2E44834C081FE9FULL, 0xAE5070FB00E67C0FULL, 0xEC9396AC6C2D853CULL, 0x065076C7C8B8B412ULL, 
            0xABEE7369AB98A73EULL, 0xC5EE4C9189460DA2ULL, 0xA04EBA5885C3C56BULL, 0xD7145141145FDEFDULL, 
            0x7188CC8F74015650ULL, 0xD41FD9625C9E28E5ULL, 0xDF23182206F4CF4BULL, 0x38A72BB311A92FBEULL
        },
        {
            0x6A0AC292F039F300ULL, 0x0E08D1E3B3FAFA1DULL, 0x98E147B66AE5155FULL, 0x352E7ABE41CFA025ULL, 
            0x0C1FDB8AFFD0A6F3ULL, 0xC21312DBB6C10372ULL, 0x1EC97D849EDA0748ULL, 0x67E4897376D067DCULL, 
            0xC8640EACA46461D3ULL, 0xB0C48FB89196FBE0ULL, 0xA88703F42DE774C6ULL, 0x973431734BE34E51ULL, 
            0x8BF1750483B92E1BULL, 0x928BBB830E1A6760ULL, 0xFB62A64F7DF455DDULL, 0xD5002F832C730B98ULL, 
            0x01FD8E0FA3556505ULL, 0x6BAAB009FA88E4F9ULL, 0x7BEDE80909A86C14ULL, 0x3C917D5792E5972CULL, 
            0x5EB1A439781E327DULL, 0xB373773EB0CD3985ULL, 0x4E609C2E7384A824ULL, 0x232D1D754B89266AULL, 
            0x6D0F9AA721159D14ULL, 0xBDAAFF463E864863ULL, 0x0A1B6EEEB775E02FULL, 0xB29C18BA1E69EA52ULL, 
            0xEDD536679961581AULL, 0xA7AFF5F3157C99EFULL, 0x81CFD27ECDC3221FULL, 0x5416919B05A4839BULL
        },
        {
            0x69713356F62A1476ULL, 0x18C4F7965A34A008ULL, 0xF0EF7B64001237DAULL, 0x94FE5BC4C676E5C2ULL, 
            0x6EE29323409071D7ULL, 0x8FB345B1256B3E68ULL, 0x76C7D9399F460FD7ULL, 0x2ACFDB26096672C8ULL, 
            0xB22732D23BC4B601ULL, 0xAB18ECA9C37D711CULL, 0xBF1E7C4B3D1066C3ULL, 0x135FFCC49AD2F7DEULL, 
            0x3C88BC7A0BAADE63ULL, 0x1995CF8DC96446ACULL, 0x85CD874F395C3CA9ULL, 0x48EA86491E09F037ULL, 
            0x54700BD748DDF649ULL, 0x82849C4A71FFB772ULL, 0x338D39EB90CD065BULL, 0x5B67C590973E3E19ULL, 
            0x8564C0FFFD9CDB77ULL, 0xB3E3151289741EBEULL, 0x675EDE5ED2E94E33ULL, 0x6896EC2BDA51B9D9ULL, 
            0x9AE1EE312658F7E1ULL, 0x30CCBD8325F93232ULL, 0x257D9F434B1B7535ULL, 0x09211C430E06A840ULL, 
            0x584D9E19E3421793ULL, 0x63C8786E9CC279CDULL, 0x27507D0340A4F667ULL, 0x3869409472879C44ULL
        }
    },
    {
        {
            0xD70F29439977CD14ULL, 0xA22838CB55E1D607ULL, 0xB8AF5D7023321B5AULL, 0x87A7B8596BD9B812ULL, 
            0xB0008A36397064B2ULL, 0x693E54A7DEAAE75DULL, 0x14D5AF9EC49DDF81ULL, 0x65AE65079605B766ULL, 
            0x7BC8A999E06D1E73ULL, 0x65C862DF797F29D7ULL, 0x606342E2CFB82528ULL, 0x09F6C98B4796F6BDULL, 
            0x1DB7C9BFA25E1461ULL, 0xFDAD84568051BA45ULL, 0xA300C88BE6AB0BFDULL, 0xC0F54DC8E1236721ULL, 
            0x01420D5A18B4CA22ULL, 0x42A2C7DBAFFA1F42ULL, 0xCC9CC9228693D661ULL, 0xFEBA3E41735B3C92ULL, 
            0xC08167BA76429B17ULL, 0x3AE446C5C01C36CBULL, 0xCFA5DFE862C57950ULL, 0x8E965F6234E69BB2ULL, 
            0xB4744D9DE1826B66ULL, 0x5A7429B59AB8F4AFULL, 0xD5388B6A263DF659ULL, 0xE8FBDFE0560E56E6ULL, 
            0x26A6942294A59DC2ULL, 0xD2F6BDCB266FA435ULL, 0x0048E7B3D88AF7F8ULL, 0x62A08668A98D3BE9ULL
        },
        {
            0x92D221BCF67C68F9ULL, 0x668F1EB83A2B9FA4ULL, 0xF383041425B22E15ULL, 0xCF752B5972D3E0CBULL, 
            0x0491E36B65EB7E59ULL, 0x9D4683975D62921EULL, 0x587A2AC2D27D4CB3ULL, 0x1F126CCAD3D4ECF4ULL, 
            0x1BFBE09D9471C598ULL, 0xD93E084853D88BAFULL, 0xAEA814700BD8F43EULL, 0x967D2C92B3B6AF82ULL, 
            0xEDA44D7F6D3E64F2ULL, 0xDEA0D6F4B7B6588DULL, 0x434A37872680F938ULL, 0x07B732E5E2B58CBCULL, 
            0x74B528AB460FFB82ULL, 0x377BD36E54EF200EULL, 0x0E2A0EAF3D06FED0ULL, 0x1A8A92DC1F770FA7ULL, 
            0xB7DB5D50EDD530ADULL, 0x3C468B69D2609082ULL, 0x7FEECCF98B6C5383ULL, 0x22B6D8BAAAE23509ULL, 
            0x912BE07FE3F91753ULL, 0x71D232888B1AAFA8ULL, 0xAF31379A0236B114ULL, 0xCFE455FCF27D3205ULL, 
            0xD44AA6EE5539853FULL, 0x012D77EBA9FA2A75ULL, 0x4D5586A18A9DF3CAULL, 0x2C62904077E31635ULL
        },
        {
            0x17B6FCCE6DB407BFULL, 0x945E50A7B15DAA5AULL, 0x2EEB5B9F5F51CF08ULL, 0x246B58E9CD1A5567ULL, 
            0x57A114E526C1162CULL, 0xC6CF2AFB3F5BEA48ULL, 0x178C5EE9E3007FDAULL, 0x00160E6556D985D9ULL, 
            0x16F7D58C40C7B0FDULL, 0xED132FBA4B611B30ULL, 0xDEAD4E32486006EDULL, 0x6B6AA40327F08D01ULL, 
            0x9B7F6A62F41D3306ULL, 0x58177131FD135DB3ULL, 0xC54153E309DE8EB8ULL, 0x224DD1CFE5F378E6ULL, 
            0xC8665280BF32FEEAULL, 0x1DA8CD7963F5A12BULL, 0xA63A763EB343AADEULL, 0x7D8D9508986DF2C6ULL, 
            0xDCB0C3A8B98A6231ULL, 0xD20E9453D2A09621ULL, 0x3FCD65AF7EA8C4FBULL, 0x0A2A36ADA8D465FEULL, 
            0x250DA1C4058E5F63ULL, 0xD56E5E7DAC02C562ULL, 0xE1CCCB36FD42CAEEULL, 0x5F71E023350A7969ULL, 
            0x29BF0416C786684DULL, 0x53718CBC63261327ULL, 0xC7AEEC415E40B99CULL, 0xEEF9AA97D6B145FEULL
        },
        {
            0xE4FB6AE4008A0688ULL, 0xD1742CF28B2AE2B2ULL, 0xE5771CA3DB7A8970ULL, 0x6017E8B824579CE1ULL, 
            0xC38F16C96217857AULL, 0xD7BD7F643CE7CA16ULL, 0xFF0622D3CCA12537ULL, 0xBD0C8F4A969964B8ULL, 
            0xC4FE6497A48ECEF9ULL, 0xFD0DC92255F8AD3DULL, 0xD32060695A481FBCULL, 0x64CCAEE4E95A04CBULL, 
            0x0358D5621599E339ULL, 0xAEBDB0CD5DE06A3EULL, 0xD227E312E4D28642ULL, 0x10F9C60322AF3936ULL, 
            0xE84F23E21C22324DULL, 0x36F5EA0A5D3DBDB9ULL, 0x8855494215D9C52CULL, 0x7636C2BF9D012D8CULL, 
            0x6670BB0C47BA8BF9ULL, 0xE0FB4846511B5749ULL, 0x7E6CE0E64F4ADC22ULL, 0x41603E9B43126403ULL, 
            0xCF2D80B8D352BBC4ULL, 0x240CEBB919908065ULL, 0x54CA560DFA38DA26ULL, 0x015A35E6267A7FDAULL, 
            0x4E058B13F1445946ULL, 0x4A867018534DFB72ULL, 0x4D7D8D26CBD51ABFULL, 0xBC2CC7AB6C73952AULL
        },
        {
            0xEE1DAFBC66260BD1ULL, 0x574D5135D0B6B9CCULL, 0xF732A8B3ED1C7B7BULL, 0xCA14F0204A297089ULL, 
            0xF9E1D6F9859C33F9ULL, 0x2619DB911D9F7692ULL, 0x20C4F03EA912023FULL, 0xB40DF42495C870F0ULL, 
            0x7B110806A7ADBDB1ULL, 0x186C49190999744CULL, 0xF5AE6656EEF4B3C4ULL, 0xBF05151798778CF0ULL, 
            0xEECD1241CB703128ULL, 0x8DB1427D4AC6AAF0ULL, 0x5E569870CC682CACULL, 0xE5EE651EEC9CC41FULL, 
            0x843020A3EB4BBE6AULL, 0xB1335DE4FCA401C0ULL, 0x647AF28F9D354772ULL, 0x1723B81295158A08ULL, 
            0x2D664EA187EDC311ULL, 0x4EBAC8DC9E56ED77ULL, 0xBC4F87F9FA561EB1ULL, 0x6F50795393A389EEULL, 
            0xDDC4E58B1E8259F3ULL, 0xCDCBF38E738FC5C3ULL, 0xE798E02B128459CBULL, 0x73E7EC855B4F4E54ULL, 
            0x75B4AA6C329B2B4BULL, 0x556EC63F2B49C98BULL, 0x8EE28A4F8B25E441ULL, 0x26D00DE426C412B7ULL
        },
        {
            0xB47BF971241447ADULL, 0xAA8153D45D642DE5ULL, 0xBDDDB5C11A64F081ULL, 0xAA36D4F458213764ULL, 
            0xB53F8C39ACE9C89DULL, 0x59793B15F26385BDULL, 0x1344CC82B9E73447ULL, 0x06EB5A96A2647E1AULL, 
            0x32B4CC3A58B8F33BULL, 0x339AD1A1B59EE84EULL, 0x496ECD4DB442EF21ULL, 0x60BF7EE2835F090AULL, 
            0x23E23F2611C2A86AULL, 0xE1AC3A7C763EF223ULL, 0x8FC263BBD54CDC00ULL, 0x79AD0389E26FE021ULL, 
            0x5D610A84ACB15F5BULL, 0xCFD8739255523B84ULL, 0xE6295227A0481935ULL, 0x5A698C43023DE23CULL, 
            0xDDF5ED77340B75E7ULL, 0x4CBB41E11B2BFF04ULL, 0x4A13B1F0ECBA47ACULL, 0x7183CEB583EA5F27ULL, 
            0xD8E40D2091684B3DULL, 0x5B46AD0517754A35ULL, 0x4A666F50ED9FEB59ULL, 0x140DAF49C764E8C5ULL, 
            0xC397E0B67FFE191BULL, 0xBC019282B8F20356ULL, 0xA15A8ECCDB1830E7ULL, 0xA6C52B178262E5E9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kPhaseDConstants = {
    0xD391F2AACDBEBC64ULL,
    0x8CC2D7C7E28915BBULL,
    0x4402BC5239ECEEF7ULL,
    0xD391F2AACDBEBC64ULL,
    0x8CC2D7C7E28915BBULL,
    0x4402BC5239ECEEF7ULL,
    0x2DECBD7668DD4376ULL,
    0xB365B2E112C1D4AAULL,
    0xEE,
    0xC1,
    0x23,
    0x2B,
    0x2C,
    0x9E,
    0xBF,
    0x34
};

