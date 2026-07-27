#include "TwistExpander_Antares.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistSquash.hpp"
#include "TwistShiftBox.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Antares::TwistExpander_Antares()
: TwistExpander() {
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Antares::KDF_A(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xEDBCE94628A2F432ULL; std::uint64_t aIngress = 0xCBFEF7FB6FAF3684ULL; std::uint64_t aCarry = 0x81AB83760820DBEDULL;

    std::uint64_t aWandererA = 0xFAAC7B008DBDED4DULL; std::uint64_t aWandererB = 0x876C7791B6993847ULL; std::uint64_t aWandererC = 0xA74EEBE54AFA1FA6ULL; std::uint64_t aWandererD = 0x977DCB4DA290504EULL;
    std::uint64_t aWandererE = 0xA2D4724CDAD9A3A4ULL; std::uint64_t aWandererF = 0x8054620496BDA8ACULL; std::uint64_t aWandererG = 0x90D874074780D1E9ULL; std::uint64_t aWandererH = 0xDCAB20B2F5C47096ULL;
    std::uint64_t aWandererI = 0x96386B22C7F3052AULL; std::uint64_t aWandererJ = 0xB5DEC540EE3C2F01ULL; std::uint64_t aWandererK = 0xD03BA17945FA4916ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBC4ABBA9C31F6D5EULL;
        aCarry = 0xC2C74E8DCF5536FCULL;
        aWandererA = 0xB5198182DB5107F4ULL;
        aWandererB = 0x90C8EF22C8EDD0F6ULL;
        aWandererC = 0xE4AD9CF7843A4180ULL;
        aWandererD = 0xB6D3DB630DE08140ULL;
        aWandererE = 0xBD3CFF556D001927ULL;
        aWandererF = 0xF25E95E73901939EULL;
        aWandererG = 0x9FD1F1257CDE76A5ULL;
        aWandererH = 0xFD9DCE7FE222DB4AULL;
        aWandererI = 0x8398FF69B4184ADBULL;
        aWandererJ = 0xA6D5EFECED756A66ULL;
        aWandererK = 0xCEFC0533A40D6518ULL;
    TwistExpander_Antares_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWaterLaneA, aWaterLaneB,
                         aWaterLaneC, aWaterLaneD, // output lanes
                         aFireLaneC, aFireLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
                         aWindLaneA, aWindLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_B(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aSoilLaneC = pWorkSpace->mSoilLaneC;
    std::uint8_t *aSoilLaneD = pWorkSpace->mSoilLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xFEAA38A6703DD53FULL; std::uint64_t aIngress = 0xD6EDF64589FED220ULL; std::uint64_t aCarry = 0xB8BB673293C82937ULL;

    std::uint64_t aWandererA = 0xDB67A739AA8F9F55ULL; std::uint64_t aWandererB = 0xEC48612B27BD1F3FULL; std::uint64_t aWandererC = 0xC4EFB0FDB52E0A6AULL; std::uint64_t aWandererD = 0xD0CA7360B2222984ULL;
    std::uint64_t aWandererE = 0xE32B1E091F2DB521ULL; std::uint64_t aWandererF = 0xF5B45BBE3A7E8966ULL; std::uint64_t aWandererG = 0xA69CC7ADB61B59A8ULL; std::uint64_t aWandererH = 0xAC3272B312D5E526ULL;
    std::uint64_t aWandererI = 0xCBF3AA00D1F8DD52ULL; std::uint64_t aWandererJ = 0xE7778EDF8A0B593FULL; std::uint64_t aWandererK = 0xBCF6ABE89CA7048BULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEB9131578BC03010ULL;
        aCarry = 0xB6683832A9227CF6ULL;
        aWandererA = 0x8EA29549ADCE5A8DULL;
        aWandererB = 0xA141F571E2E73D08ULL;
        aWandererC = 0xBF0D57B8660CAC55ULL;
        aWandererD = 0xCEEBCC2D938D01D8ULL;
        aWandererE = 0x8DE10DB117E81AF4ULL;
        aWandererF = 0xCF7CEDDA2B505FA3ULL;
        aWandererG = 0xE27E53808902FB5DULL;
        aWandererH = 0xF309A00F8A8B7E72ULL;
        aWandererI = 0xA09C3BEFC058A599ULL;
        aWandererJ = 0x81B22470109580E5ULL;
        aWandererK = 0xC8FC2EC97AD62830ULL;
    TwistExpander_Antares_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aIceLaneA, aIceLaneB,
                         aIceLaneC, aIceLaneD, // output lanes
                         aSoilLaneC, aSoilLaneD, aLightningLaneC, aLightningLaneD, // index shuffle seeds
                         aLightningLaneA, aLightningLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_C(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_C(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aMagmaLaneC = pWorkSpace->mMagmaLaneC;
    std::uint8_t *aMagmaLaneD = pWorkSpace->mMagmaLaneD;
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x9C0799E4A2DB2409ULL; std::uint64_t aIngress = 0xD5FEE4E003F2C985ULL; std::uint64_t aCarry = 0xE42BA312874B052FULL;

    std::uint64_t aWandererA = 0x92662C2D5FC7DF2AULL; std::uint64_t aWandererB = 0x8C01635E317907BCULL; std::uint64_t aWandererC = 0xABA76D613C8B6EE0ULL; std::uint64_t aWandererD = 0xF43CBD6AFEEFD26DULL;
    std::uint64_t aWandererE = 0xB3A9878AE134C7F7ULL; std::uint64_t aWandererF = 0xBF7EF957ABBFDF62ULL; std::uint64_t aWandererG = 0xF7BE5C87C28DB778ULL; std::uint64_t aWandererH = 0xCBFB8A31591FD748ULL;
    std::uint64_t aWandererI = 0xF495B45B3302E431ULL; std::uint64_t aWandererJ = 0x9D02837410583FC4ULL; std::uint64_t aWandererK = 0x95CDEDCFF6F99DBFULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD060A572AD602647ULL;
        aCarry = 0xD70DE48DB78709BBULL;
        aWandererA = 0xEB2F26471920E4D5ULL;
        aWandererB = 0xD3F8867212D6E1BCULL;
        aWandererC = 0xDF4562BC7DB20368ULL;
        aWandererD = 0xDCEE9E849787BBB0ULL;
        aWandererE = 0xDCBD7F0B99579B89ULL;
        aWandererF = 0xC3CD01A006555F25ULL;
        aWandererG = 0xFF8050050ABC6FBCULL;
        aWandererH = 0xCBD9A6DC9D2D9479ULL;
        aWandererI = 0xEBA5237F6022E91FULL;
        aWandererJ = 0xAF97FC89F77AB3F0ULL;
        aWandererK = 0xE98381A93F99A461ULL;
    TwistExpander_Antares_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_C_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aShadowLaneA, aShadowLaneB,
                         aShadowLaneC, aShadowLaneD, // output lanes
                         aMagmaLaneC, aMagmaLaneD, aPlasmaLaneC, aPlasmaLaneD, // index shuffle seeds
                         aPlasmaLaneA, aPlasmaLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_D(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_D(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xE8DB4264AB285C5CULL; std::uint64_t aIngress = 0xE77ECF5A4463D4A3ULL; std::uint64_t aCarry = 0x923B68B2BC092A3CULL;

    std::uint64_t aWandererA = 0xF8C6966102321F0DULL; std::uint64_t aWandererB = 0x8871E1FF7373023FULL; std::uint64_t aWandererC = 0xCCEA894DC35EA55AULL; std::uint64_t aWandererD = 0xB58F106B7A10E215ULL;
    std::uint64_t aWandererE = 0xA9C242008DBF7402ULL; std::uint64_t aWandererF = 0xB48D268A2C1B086BULL; std::uint64_t aWandererG = 0xB1150B5340731905ULL; std::uint64_t aWandererH = 0xBA681DE5655FBCEAULL;
    std::uint64_t aWandererI = 0xA0766919EB60B235ULL; std::uint64_t aWandererJ = 0xFFC124493A2E724AULL; std::uint64_t aWandererK = 0x809DE265CDD62547ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE5BEB2CDCBCFFE7AULL;
        aCarry = 0xC602AF282837DB4DULL;
        aWandererA = 0xB06135BAB3CE8F5DULL;
        aWandererB = 0xA0D32B0E512EDD55ULL;
        aWandererC = 0x961DC58B979E5952ULL;
        aWandererD = 0x91E3BCACD8981335ULL;
        aWandererE = 0xA0B97E2B6F683AF7ULL;
        aWandererF = 0xFA2AF6CBF0AFC04CULL;
        aWandererG = 0x8CFF8360A35DCE39ULL;
        aWandererH = 0xF919C9D8971AE25DULL;
        aWandererI = 0xF2AE8FAB4AE6DCB8ULL;
        aWandererJ = 0xE7C06717900B6E3EULL;
        aWandererK = 0xF636885445B64429ULL;
    TwistExpander_Antares_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_D_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aVaporLaneA, aVaporLaneB,
                         aVaporLaneC, aVaporLaneD, // output lanes
                         aAetherLaneC, aAetherLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
                         aCelestialLaneA, aCelestialLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Antares::Seed(TwistWorkSpace *pWorkSpace,
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
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
    pWorkSpace->mDomainBundle.Zero();
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aWoodLaneA = pWorkSpace->mWoodLaneA;
    std::uint8_t *aWoodLaneB = pWorkSpace->mWoodLaneB;
    std::uint8_t *aWoodLaneC = pWorkSpace->mWoodLaneC;
    std::uint8_t *aWoodLaneD = pWorkSpace->mWoodLaneD;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aMagmaLaneA = pWorkSpace->mMagmaLaneA;
    std::uint8_t *aMagmaLaneB = pWorkSpace->mMagmaLaneB;
    std::uint8_t *aMagmaLaneC = pWorkSpace->mMagmaLaneC;
    std::uint8_t *aMagmaLaneD = pWorkSpace->mMagmaLaneD;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xB3752B2FEE586F6FULL;
    std::uint64_t aIngress = 0x9B4731DFE1FBAEF8ULL;
    std::uint64_t aCarry = 0x89D8169B56A7FF2EULL;

    std::uint64_t aWandererA = 0xB65276B024C56DB7ULL;
    std::uint64_t aWandererB = 0x9A50A370F679B6E4ULL;
    std::uint64_t aWandererC = 0xA16FB1D2C193FF7DULL;
    std::uint64_t aWandererD = 0xC6A4C3769DF77E5FULL;
    std::uint64_t aWandererE = 0xB09A32B886D093BDULL;
    std::uint64_t aWandererF = 0x80DFA0E5C314D46FULL;
    std::uint64_t aWandererG = 0xA497C80C30BBEEEAULL;
    std::uint64_t aWandererH = 0xD6930436DD39B57DULL;
    std::uint64_t aWandererI = 0xF966A3289F9C8879ULL;
    std::uint64_t aWandererJ = 0xF1CC69142CE2D461ULL;
    std::uint64_t aWandererK = 0xFAD1CAE164A61822ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneB);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeyRotate);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeySpawn
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneC);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    TwistSquash::SquashB(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeySpawn);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Seed
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneSeed);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Twist
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    TwistSquash::SquashA(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneTwist);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    TwistExpander_Antares_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aHeartLaneA, aHeartLaneB,
                         aHeartLaneC, aHeartLaneD, // output lanes
                         aPlasmaLaneC, aPlasmaLaneD, aMagmaLaneC, aMagmaLaneD, // index shuffle seeds
                         aMagmaLaneA, aMagmaLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_F(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneA, aWindLaneB,
                         aWindLaneC, aWindLaneD, // output lanes
                         aCrystalLaneC, aCrystalLaneD, aEarthLaneC, aEarthLaneD, // index shuffle seeds
                         aEarthLaneA, aEarthLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_I(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aCelestialLaneA, aCelestialLaneB,
                         aCelestialLaneC, aCelestialLaneD, // output lanes
                         aAetherLaneC, aAetherLaneD, aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_L(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWoodLaneA, aWoodLaneB,
                         aWoodLaneC, aWoodLaneD, // output lanes
                         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
                         aIceLaneA, aIceLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Antares_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_N(pWorkSpace,
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
    // [KEY — sixteen key rows, lane splits A-P]
    //
    TwistExpander_Antares_Arx::KEY(pWorkSpace,
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

    FoldSeed(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
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
    GrowKeyB(pWorkSpace,
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
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Antares::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pSnowLaneA,
                                       std::uint8_t *pSnowLaneB,
                                       std::uint8_t *pSnowLaneC,
                                       std::uint8_t *pSnowLaneD,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace,
                              pSource,
                              pSnowLaneA,
                              pSnowLaneB,
                              pSnowLaneC,
                              pSnowLaneD,
                              pDestination);
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pSnowLaneD == nullptr) ||
        (pDestination == nullptr)) { return; }
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aWoodLaneA = pWorkSpace->mWoodLaneA;
    std::uint8_t *aWoodLaneB = pWorkSpace->mWoodLaneB;
    std::uint8_t *aWoodLaneC = pWorkSpace->mWoodLaneC;
    std::uint8_t *aWoodLaneD = pWorkSpace->mWoodLaneD;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xA525CDB46AD01037ULL; std::uint64_t aIngress = 0xC09606661179A436ULL; std::uint64_t aCarry = 0x9412840736153247ULL;

    std::uint64_t aWandererA = 0xC1AC2FF0370B3B15ULL; std::uint64_t aWandererB = 0xCBA944034C3C9ADFULL; std::uint64_t aWandererC = 0xE84230387DECB832ULL; std::uint64_t aWandererD = 0x91D11EE533531B91ULL;
    std::uint64_t aWandererE = 0xEE0979C9311FA618ULL; std::uint64_t aWandererF = 0x90033F0704566225ULL; std::uint64_t aWandererG = 0xA0BD34D720766513ULL; std::uint64_t aWandererH = 0x9E4B1EDD3B4AD651ULL;
    std::uint64_t aWandererI = 0xB520CDB0FB96834AULL; std::uint64_t aWandererJ = 0xB8217F09895AA33BULL; std::uint64_t aWandererK = 0xCD2648274F7BCFB0ULL;

    // [twist]
        aPrevious = 0xE3EE15FA3D09F1A7ULL;
        aCarry = 0xE7E0D20B986C2BF9ULL;
        aWandererA = 0xAD1678C6C0A23E89ULL;
        aWandererB = 0xBB7122AB605A1075ULL;
        aWandererC = 0xE8465DEC76D34C57ULL;
        aWandererD = 0xBB2263BCCE4617EFULL;
        aWandererE = 0xED9E44D3FFFE2A88ULL;
        aWandererF = 0x98BE73F401E56869ULL;
        aWandererG = 0xE618BC4413B08E64ULL;
        aWandererH = 0xC1169420463522B7ULL;
        aWandererI = 0xA33E414715BBCDC0ULL;
        aWandererJ = 0x80A8D1F1290060B2ULL;
        aWandererK = 0xFDA7E9A1B60E81E5ULL;
    TwistExpander_Antares_Arx::Twist_A(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Antares_Arx::Twist_B(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Antares_Arx::Twist_C(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgD;
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aHeartLaneA, aHeartLaneB,
                         aHeartLaneC, aHeartLaneD, // output lanes
                         aFireLaneC, aFireLaneD, aWaterLaneC, aWaterLaneD, // index shuffle seeds
                         aWaterLaneA, aWaterLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Antares_Arx::Twist_D(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Antares_Arx::Twist_E(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Antares_Arx::Twist_F(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWoodLaneA, aWoodLaneB,
                         aWoodLaneC, aWoodLaneD, // output lanes
                         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
                         aIceLaneA, aIceLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Antares_Arx::Twist_G(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Antares_Arx::Twist_H(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    FoldTwist(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
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
    GrowKeyB(pWorkSpace,
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
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Antares::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
    TwistExpander::GrowKeyA(pWorkSpace,
             pPrevious,
             pIngress,
             pCarry,
             pWandererA,
             pWandererB,
             pWandererC,
             pWandererD,
             pWandererE,
             pWandererF,
             pWandererG,
             pWandererH,
             pWandererI,
             pWandererJ,
             pWandererK);
    if ((pWorkSpace == nullptr) || (pPrevious == nullptr) ||
        (pIngress == nullptr) || (pCarry == nullptr) ||
        (pWandererA == nullptr) || (pWandererB == nullptr) ||
        (pWandererC == nullptr) || (pWandererD == nullptr) ||
        (pWandererE == nullptr) || (pWandererF == nullptr) ||
        (pWandererG == nullptr) || (pWandererH == nullptr) ||
        (pWandererI == nullptr) || (pWandererJ == nullptr) ||
        (pWandererK == nullptr)) { return; }
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;

    // [grow key a]
    TwistExpander_Antares_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    //
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aVaporLaneA, aVaporLaneB,
                         aVaporLaneC, aVaporLaneD, // output lanes
                         aShadowLaneC, aShadowLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
                         aWindLaneA, aWindLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Antares_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

}

void TwistExpander_Antares::GrowKeyB(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
    TwistExpander::GrowKeyB(pWorkSpace,
             pPrevious,
             pIngress,
             pCarry,
             pWandererA,
             pWandererB,
             pWandererC,
             pWandererD,
             pWandererE,
             pWandererF,
             pWandererG,
             pWandererH,
             pWandererI,
             pWandererJ,
             pWandererK);
    if ((pWorkSpace == nullptr) || (pPrevious == nullptr) ||
        (pIngress == nullptr) || (pCarry == nullptr) ||
        (pWandererA == nullptr) || (pWandererB == nullptr) ||
        (pWandererC == nullptr) || (pWandererD == nullptr) ||
        (pWandererE == nullptr) || (pWandererF == nullptr) ||
        (pWandererG == nullptr) || (pWandererH == nullptr) ||
        (pWandererI == nullptr) || (pWandererJ == nullptr) ||
        (pWandererK == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aKineticLaneC = pWorkSpace->mKineticLaneC;
    std::uint8_t *aKineticLaneD = pWorkSpace->mKineticLaneD;
    std::uint8_t *aChanceLaneA = pWorkSpace->mChanceLaneA;
    std::uint8_t *aChanceLaneB = pWorkSpace->mChanceLaneB;
    std::uint8_t *aChanceLaneC = pWorkSpace->mChanceLaneC;
    std::uint8_t *aChanceLaneD = pWorkSpace->mChanceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;

    // [grow key b]
    TwistExpander_Antares_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    //
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aChanceLaneA, aChanceLaneB,
                         aChanceLaneC, aChanceLaneD, // output lanes
                         aKineticLaneC, aKineticLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
                         aCelestialLaneA, aCelestialLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Antares_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

}

void TwistExpander_Antares::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 9 of 33
    // Exploration cases: 0
    // Structural maximin 531 / 674; family total 4405
    std::uint8_t *aGrowAAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aGrowAAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aGrowAAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aGrowAAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aGrowAVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowAVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowAVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowAVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowAShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowAShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowAShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowAShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowAKeyRowWrite = &(pWorkSpace->mKeyBoxA[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyA expects four expansion-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyA expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1510U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 9 of 33
    // Exploration cases: 0
    // Structural maximin 533 / 674; family total 4346
    std::uint8_t *aGrowBCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aGrowBCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aGrowBCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aGrowBCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aGrowBVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowBVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowBVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowBVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowBShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowBShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowBShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowBShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowBKeyRowWrite = &(pWorkSpace->mKeyBoxB[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyB expects four operation-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyB expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 520U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 9 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1081 / 1248; total 8764
void TwistExpander_Antares::FoldSeed(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldSeed expects sixteen key-width chunks per lane.");

    //
    // FoldSeed — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 9 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1079 / 1248; total 8786
void TwistExpander_Antares::FoldTwist(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldTwist expects sixteen key-width chunks per lane.");

    //
    // FoldTwist — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Antares::kKeyRotateSalts = {
    {
        {
            0x0243BD64FA69AA2EULL, 0x0AFAEB6DA510056BULL, 0xE8FC56238EB97EB7ULL, 0xCF0E625F4A46BF25ULL, 
            0xD2A048DB7108DEC5ULL, 0xC6757365D19BEDC7ULL, 0xBB3D05B4F8A058DFULL, 0x0A842F786EDFF4AEULL, 
            0x6DDA5FE8DAF76091ULL, 0xFD5AFDE5B45BD6FFULL, 0xC0F3B5833F840753ULL, 0x2F649439EA540C3DULL, 
            0x9255798C6AAD5BD8ULL, 0xCF7AABD034111C2CULL, 0xE2FC697530FC4D61ULL, 0x89618D5BAC68A088ULL, 
            0x779418ED2AF991E0ULL, 0x9D1BE6BCBB84D9FAULL, 0x707476FA8738CF61ULL, 0xB85ED3F05AAE1890ULL, 
            0xA9296B82633062BAULL, 0xF8236950302E435EULL, 0xF5FB12E9A3237652ULL, 0x3D06248E4250015CULL, 
            0x16A6C57566D34E64ULL, 0xEE8C6F9E4ED397D8ULL, 0x339A97FBE6FEB3F1ULL, 0x79D3D84E04A658B8ULL, 
            0xE794958C89574A25ULL, 0x2B04CED35068F16AULL, 0xDF4C0661EA8DDC01ULL, 0xC43A7DBB6BE049FCULL
        },
        {
            0x8EAA17D6334762C3ULL, 0xE4BD80B9FD9C4379ULL, 0xFF07AB5BB0247322ULL, 0xE79138693BDDE8ACULL, 
            0x6967A5C92A0D27A1ULL, 0xD2760A16C653A8F3ULL, 0x8E0EC811BE42D81EULL, 0x9D5A78DE097EDE55ULL, 
            0x162EFA4317DCA776ULL, 0xFEFEF52B615BC4B5ULL, 0x3F46E080083D2222ULL, 0x7F96BE6FDA977877ULL, 
            0x8490E33B0E2D67E8ULL, 0x9EC1B40EC692DCA6ULL, 0xA764CCCFBE6D37A1ULL, 0x20016159872CA6C0ULL, 
            0x75151A34B9188B51ULL, 0x908F083237DE0E6DULL, 0x06E35BA50413E9D1ULL, 0xE8AA0C6C0786B8BCULL, 
            0x1ED782E8722BB3D1ULL, 0x8C8D5B507550B79FULL, 0x26FF1E4FF6F51548ULL, 0xD03DF4F24DDA51D1ULL, 
            0x6E93CCF1060ED418ULL, 0x49476198DCB3A340ULL, 0xEB64B4E21A4291FEULL, 0xB6FBF0F9F515157FULL, 
            0xA3E98540059C3D02ULL, 0xC9D867DBE19FB9FFULL, 0xAC474534A9848594ULL, 0xD983DF98AE96B7BEULL
        },
        {
            0xB1B21D7BABD001BFULL, 0xE1CE3D8E5C87E6A6ULL, 0x25C425559CF8557DULL, 0x478D331AA7056963ULL, 
            0xEB652C74532C428CULL, 0x090D578EDD6F4C25ULL, 0x936BD03D9292A0EEULL, 0x53DD8667A6CB44DAULL, 
            0xEC9D6EDB1DECAB15ULL, 0xDEED9AAEDC94EC24ULL, 0x148FD236560C22A0ULL, 0xA3B80EF0AB9B2EEEULL, 
            0xEC4FB5A8344D8D4EULL, 0x0F71E2241E50E32CULL, 0x4CDB087DB57A1C97ULL, 0xB0B181B0C0DE48E2ULL, 
            0x8E1FF2B8EA3848A7ULL, 0xF7D44AF753CED330ULL, 0x0829EB740910D3FAULL, 0x9D05D325CE522624ULL, 
            0x08B55D36AE465DD9ULL, 0x94D1770C0B5F0657ULL, 0x4B091667BF1EA3BBULL, 0x51CFEA9FB2901272ULL, 
            0x90F12ED8DC4D0D38ULL, 0x0E337C078EFD00B6ULL, 0x22F04601B023F3AEULL, 0x4B17B197405404B7ULL, 
            0x22328C09585B0DE3ULL, 0xCD5C94D22CE43D54ULL, 0xEE72D0278D612F2AULL, 0x3A16133AE4A55A41ULL
        },
        {
            0x603306060A8B2873ULL, 0x333ABB34B48F5A52ULL, 0xD7313E196842CAC6ULL, 0x6129BEB486F53485ULL, 
            0xE756A13CF6B8FC78ULL, 0xB2B288ED2754A26FULL, 0xE2DB176E52706CBDULL, 0xC6074D35D2D1D5EDULL, 
            0x6B1A1CDD15EFFA08ULL, 0x70FBB2B9F968787DULL, 0x6A137C1C200DB8ABULL, 0x2CAF6ECB5780FB32ULL, 
            0xFD1DCA697E7E1038ULL, 0xB0CE6AACF03402AAULL, 0x159D984B52430199ULL, 0x1227F5868A549059ULL, 
            0xE5D449E4FC99FF18ULL, 0x4D8C93AA36733C61ULL, 0xFBCF5F777309F45FULL, 0x51DB7AAD1233CDF3ULL, 
            0x0B92BFCA630B0D4AULL, 0x9655121E2E4F6D0EULL, 0x31E1DFE06CF2E991ULL, 0x038A3BD8BF16FE2AULL, 
            0x6F65BF630B9D70F9ULL, 0x695D13310B53D773ULL, 0x5114FC494B8A6EA5ULL, 0xF132AB9E032B3716ULL, 
            0xAACE259A1CCDDD9EULL, 0x89849696B49AC18AULL, 0x9189002954FAB8C7ULL, 0x8A4596F98E496676ULL
        },
        {
            0x2A50ABB99DCECEBDULL, 0x4927826161187FF5ULL, 0xB400542191DB75B2ULL, 0xB6295DBC47F12D0CULL, 
            0xD47D964000EBC3A2ULL, 0xC9ED25C31BF2C65DULL, 0x615373B7DF564468ULL, 0xDD38BEF7523296A3ULL, 
            0xDBE6B27311DEC145ULL, 0x45CF156E36CF29A5ULL, 0x679F7FBE3692D412ULL, 0x81C9BEA73EC27D54ULL, 
            0x18E10FAC436C0ECEULL, 0xAE3AAAAD34CE852EULL, 0x4E97D60FA3823481ULL, 0x9BD51B4FF3604C58ULL, 
            0x085F76DE833CBDE9ULL, 0x6259BBB51A926060ULL, 0x47D10059A6D55885ULL, 0xB3521AE5C1CC5B1BULL, 
            0xD32F62D6F2F86218ULL, 0x3FD7BEE27F6685ACULL, 0x93AD61B789FDD79DULL, 0x3EAA07FA33AB3D49ULL, 
            0xEC081B4D6026FD9AULL, 0x64BB2FF1CB207C4FULL, 0x6C15E87C98E06384ULL, 0xC13576C50B0DC0F0ULL, 
            0x9133590266AE7D88ULL, 0x10B434029DEDC7F5ULL, 0x5076646CC0F67868ULL, 0xB1C2B9F2480AB3FFULL
        },
        {
            0x37D7FA974F147C11ULL, 0xD89FF2C7DED267BCULL, 0x1B0BA1CDB8B35FB2ULL, 0x32816E51051766DCULL, 
            0x174F5EA576DE884AULL, 0x8EEAA1445927AF4AULL, 0xD141DED02949CD6CULL, 0x6FFCB2DF272173EAULL, 
            0xD5F2223FCE3954D6ULL, 0x7A10648D1895D4A0ULL, 0x2B1A25B76D7EBA9DULL, 0x31D5F74E520C948AULL, 
            0xFCAA4DDF7D86F99AULL, 0x92F02B25B94E39A2ULL, 0x1257EB50BB533E59ULL, 0x46C6BAD0931EBC96ULL, 
            0x8608B6A06B961B39ULL, 0xC23847F36DC1C619ULL, 0xC2AE4B086D2981D2ULL, 0xEAE8E865B820884AULL, 
            0x72FBC0BCFA1C2C48ULL, 0xAAC758BAE52AFFBBULL, 0x4FA9ACFF26F10804ULL, 0x1116476281E34CECULL, 
            0x241D887BDCCFCF44ULL, 0x39610EED11AE9FB5ULL, 0xC61C3AFB1CFFC9ECULL, 0x70B26292B8077A7EULL, 
            0x45B0607C597622B4ULL, 0x6C8C0521D648852EULL, 0x94D243CB23E6DE49ULL, 0xA11F208D7C850432ULL
        }
    },
    {
        {
            0xEAC133A4B181A75AULL, 0x58CD66ADE3DB6D8EULL, 0xA321E701694D3D66ULL, 0x64A344EF0B3FDA81ULL, 
            0x51C5F27E90017A45ULL, 0xBAC5A7400741AB4CULL, 0x34D08A878D9EF922ULL, 0xC1B0B5575D75A4BDULL, 
            0xECE814DA27963F73ULL, 0xFF254C5495BC81D8ULL, 0xE141227397D0BC2CULL, 0x549B78DB9E1A4C1FULL, 
            0x8AAAFE9F81F8E605ULL, 0x9DB396E9130A928EULL, 0xA3BF1C8DDBD7D577ULL, 0xFB2D2E3DCC71F029ULL, 
            0x71D45ABD2011121CULL, 0xC2FF17A5750544A2ULL, 0xE21FE969B4F8B5A1ULL, 0xAF3CB05332D02E24ULL, 
            0x3F69642A8CDA3A1BULL, 0xA8173ACF6B5100A6ULL, 0x0DDD43D6CA69B5DBULL, 0xE0ECA0BAEB27E84AULL, 
            0x522D97176AC5A653ULL, 0x6B86E2BB694BE570ULL, 0x1CC738E3C66E4A5CULL, 0x1B136D49120F3592ULL, 
            0x949E742EB1DD8935ULL, 0xA582BC490C52CE1FULL, 0x94FFA13FA148209DULL, 0xF8A5CF2E90DA033BULL
        },
        {
            0x38877805C90A4F5EULL, 0x1217E2BF66DEFD2DULL, 0x96947AAD586223C7ULL, 0x1CC096971CA1D853ULL, 
            0x385AF15FEF08C1A7ULL, 0xE915E0B2DB48CC59ULL, 0x581710ABBFA8AA27ULL, 0xC0DC925F4E5A8D75ULL, 
            0x83FFE68A75B58DACULL, 0x87685746BFBF7077ULL, 0x2B9B642B013A5398ULL, 0x6DF43F45A80A0237ULL, 
            0x5044B749F5E7CA04ULL, 0xDD7B96FBC30B7268ULL, 0x7ECB4419F08BF732ULL, 0x38279412A3F80E10ULL, 
            0x04A78C1FF61A2234ULL, 0x37E8D601FC1C440EULL, 0xD98FEF7C4C21847FULL, 0xC31C4B2E91691310ULL, 
            0xCDE786F61212D97BULL, 0x968A1DBC33BB6397ULL, 0x2492B132346C06DFULL, 0x6E5FD765719078E8ULL, 
            0xB3399FF6267A9C07ULL, 0x5BDA6EB46540A287ULL, 0x03792920949229A5ULL, 0x8920F11C7ADBA28EULL, 
            0xFC0AC0A9C28E04EFULL, 0x2179D77C61454E63ULL, 0x7EDADFFB99CF40D0ULL, 0x0C5663A45A88DF6EULL
        },
        {
            0x3DBC309EB95E964DULL, 0xBF7E7478F292A4D9ULL, 0x175CF1CC24F643FFULL, 0xA51F2E2D7B359B6AULL, 
            0x9734A486C1AA137DULL, 0x5000C75B2F9E11F0ULL, 0x0519E387383C0597ULL, 0x6E984CB73DB2BF33ULL, 
            0x9B52C1120A71FEF1ULL, 0x49E17347CBBA4EC9ULL, 0x5620B7A33DE7D62DULL, 0x0964A541B96A62FAULL, 
            0x417CCCAC939C95E1ULL, 0xCFA6197F81A67FB4ULL, 0xFC0856B003F1F14DULL, 0x7B5A7F88027C6153ULL, 
            0x23FC938D99D358FDULL, 0x90AE76B32BC3D491ULL, 0x5E7518C9FEF71D56ULL, 0xCF35CCE71FB50955ULL, 
            0xB871C03A6C5B8052ULL, 0xC7B4B2B333907D27ULL, 0xEDBF3C18A174ACCCULL, 0x4B09AB2C405C02D2ULL, 
            0x4D02D53CFF81676AULL, 0x7A02ADEBEE3ED17FULL, 0xC10F6A9A8EA77428ULL, 0xB05CEEFE6BF5A19CULL, 
            0xB19EF82E6F77EBA2ULL, 0x263856BEDCAD7152ULL, 0xAEB1237696F447E8ULL, 0x531DE2EDC17C7CF7ULL
        },
        {
            0xC89DC451283C6402ULL, 0x833CF62B21805315ULL, 0xC93CCBDE6DE26EF6ULL, 0x356E5DD87DE17486ULL, 
            0xB700CA341C8BC8BCULL, 0xF9E9C579EB0B3155ULL, 0xD17E5578208F2BF4ULL, 0x61653019B2D3C55AULL, 
            0x718E1CFB9B0E17B9ULL, 0x3BF744B9A148359CULL, 0xF287EF79703388ABULL, 0x46912FCBED625683ULL, 
            0xC8C1A0AF44895590ULL, 0xA7CE53C96A9ECE4AULL, 0xD11300AD0E66F2CBULL, 0x2E06470CEC0D7EE3ULL, 
            0x0029C67587291447ULL, 0x50D106B1BD6E88C8ULL, 0x8A5811D80B4EBC02ULL, 0x8D5B9C1242799F6AULL, 
            0x8370877CD9C2F7FDULL, 0x05ACC12DBB669D18ULL, 0x1689BA38543181B9ULL, 0x6AC0968CDA7CF6BBULL, 
            0xD6DBF18B3C4A3CADULL, 0x49FD721A783C3194ULL, 0x1B7E310906CC1B20ULL, 0x82DE1B7746A0179DULL, 
            0x50E1F3C9F833B007ULL, 0x14E218B54DA2694CULL, 0x655295DE19341A86ULL, 0xB961B1254E63A3C1ULL
        },
        {
            0x72690EF53D140157ULL, 0x4372F60805AB98A7ULL, 0x1096455E45272F8AULL, 0xE49694A53B2BA221ULL, 
            0x482042F328D2C6D1ULL, 0x07A78E342B79A320ULL, 0x0590E40CFB15E38DULL, 0x4CFC1A93A54D913FULL, 
            0xBE5214569AF63CC9ULL, 0xA64F4F76A48834CCULL, 0x6DC68E604DC2EF3EULL, 0xF5FBD81E3C36B26BULL, 
            0xB0D73722FE868590ULL, 0x30429AAB74FFFB23ULL, 0xD6D472A9A6F579ECULL, 0x238FF27D2D8D7BEBULL, 
            0x2EFAF96E552EF999ULL, 0x3EF555CD6D810C34ULL, 0xD97248F60586E9CFULL, 0x637AF97DC1F6D9E9ULL, 
            0x9BED32A53F13EB61ULL, 0x760ADA8C96F87898ULL, 0x8E41066674EF6FA9ULL, 0x5C89C5E12D77FF48ULL, 
            0x6205465496F8CF40ULL, 0x2091149628C0C417ULL, 0x7B05DD5B4D11880CULL, 0x296EEDDD7E897587ULL, 
            0x86D97BEB14B6E68EULL, 0x69C2383218537802ULL, 0x1CB4E5A8140C0F76ULL, 0x7F9873A29AD0F931ULL
        },
        {
            0x019969B13CEF53DEULL, 0xCE09CE9BABE2382CULL, 0x00AA989D62811BCCULL, 0x4A3C6C15F65706C0ULL, 
            0x9CB2710E26B5AB26ULL, 0xEC1C278CA6D38073ULL, 0xB9B7FBBDAA6035C2ULL, 0xBC2BC43EF5F8A6AFULL, 
            0x2D3EAA3E060E2868ULL, 0x6FAB9158C42DD3DFULL, 0x5298E3B1240440C6ULL, 0x7FBC9E7F48FA4BC9ULL, 
            0x47C6E05AD94A22C2ULL, 0x540B5D9BD6C71945ULL, 0xE3A534E0DC05931DULL, 0xD5B09DB4D1E4F733ULL, 
            0x73F86BFD137EC1DEULL, 0x225772CB385756B3ULL, 0xAE51DA9880C711E2ULL, 0x1D92FFC689612BDDULL, 
            0x48E1486032DE8EECULL, 0xD9253B268A231574ULL, 0xC7E5C1CFB86A2693ULL, 0xDED22243590D9DE9ULL, 
            0x932F05A8BACF7E59ULL, 0x41F4ED7FD06DDEACULL, 0x75B58EC326D185C6ULL, 0x607FC7414A8A60F2ULL, 
            0x44C7B3D40BACF451ULL, 0x6F20C06C353242AAULL, 0x3C3890CD43008117ULL, 0x9B25EDD9D9EEB4D4ULL
        }
    },
    {
        {
            0x47B00D1C9E582DA8ULL, 0x355F921FA36BBDEDULL, 0x4E8D1EDA699D3B27ULL, 0x06927DDB638F7815ULL, 
            0xB093DC3100B48BD2ULL, 0xBBF28923E2FCDC92ULL, 0xB8B5B8256AF8548FULL, 0xDEB94834305E50BCULL, 
            0x34B57DF9E5B2B7C1ULL, 0x12E85729B138BF1CULL, 0x8A579B7510B56D93ULL, 0x808DA67D82DFAAE7ULL, 
            0x775C98BE7F44A864ULL, 0xB37540F7D9C357C4ULL, 0xDAE9A0307E0F6483ULL, 0xE8F544296B0ABE9AULL, 
            0xC1EC9016E4D96937ULL, 0xA0C54A127EF12560ULL, 0x31962319960E3355ULL, 0xCF7FB0DBE3A77096ULL, 
            0xCB03A4485BEA9EA3ULL, 0xB0F73554132E1A3EULL, 0x32F987FECFD75DBDULL, 0xCDC1BB5F21BBD7F0ULL, 
            0x88461F800F103BB1ULL, 0x1E19A201E9999AB4ULL, 0x2209D8EA1CC262E5ULL, 0x8A531E99E8444A21ULL, 
            0xAA2D5463C10838FBULL, 0x2A6FC1852ED2A5E5ULL, 0x26A9BEFA0B72F5A2ULL, 0x3BA08A5C31884977ULL
        },
        {
            0xAA335731899401CFULL, 0xB12190F35984F0BFULL, 0x532A2B60EC5F7D16ULL, 0x6297DE38F10AC0BCULL, 
            0xA6383E878031EBE0ULL, 0x0784BBA4C066B141ULL, 0x1EFDCEDF7E11566BULL, 0xFFDCAC60723B902DULL, 
            0x4E9511528A20543CULL, 0xB8379107D1463F3DULL, 0xCABB7CD4E7F58892ULL, 0x5B8E7AF00934D62FULL, 
            0x5700601552840261ULL, 0xA8C40F4898D3791AULL, 0xDA7802F2F0BAAB88ULL, 0x60979F7DF6CFE8D4ULL, 
            0x1394D3C0B609B077ULL, 0x4A075931338BD327ULL, 0x9D203A09D7B2957EULL, 0x8148E2C420E906ACULL, 
            0x8FA1C3BCD939CC69ULL, 0x36DCB0AF185EA68AULL, 0x2BDEF7F09F3F74A0ULL, 0xCF74DB1A0C193759ULL, 
            0x77BA884D87713809ULL, 0x28A3FE97E5E2D3DEULL, 0x811477F9276FF35FULL, 0xBC5C27D2CD58A743ULL, 
            0x545940AC0B77D299ULL, 0x2CA59E8523EAC1BAULL, 0xA5E7BBC9432FA289ULL, 0xDB1FB7704EB97886ULL
        },
        {
            0xC4037B10D00CC7B5ULL, 0x01F47849E3333667ULL, 0x70FABFB0EA51E790ULL, 0x12B534BC298FEC60ULL, 
            0x67D9387AB3B04157ULL, 0xD0441629A01AF327ULL, 0xB5144F56C0BFE817ULL, 0x801783C63108075FULL, 
            0xEE1A5AE9CA1B9A90ULL, 0x03A27438325A0866ULL, 0x9827928AC7947E29ULL, 0x8D9B5BDCADB15593ULL, 
            0x350FABC6BEEE365CULL, 0xFCF07E1F67641A17ULL, 0x49E7A698B93824A3ULL, 0xC016D79004914DDEULL, 
            0xE6312EF22154371CULL, 0x9801407EF30E3921ULL, 0x4D607E3B37B18017ULL, 0xBF1E9DE92C6260A7ULL, 
            0xE547B9D70F913970ULL, 0xE1B0D69F9D396FDEULL, 0x3554994404AC1563ULL, 0xA73B8446E5619CD7ULL, 
            0xCC9C5018C04F4A88ULL, 0xDC912080A80537C8ULL, 0xB0EC534E89DA844EULL, 0x3BEEF9453761004FULL, 
            0xF301255533436117ULL, 0x3C4E5244B8928A37ULL, 0x24053FE8E9972A62ULL, 0xC7FC4E577B954230ULL
        },
        {
            0x9644E3F7D1676E68ULL, 0xFB5D17F1B811964EULL, 0x1C54EA4ABA5A4F14ULL, 0x9CFCFCFFD0E80A09ULL, 
            0xA37A5EEC08B08CE3ULL, 0x6D9348E633D2089FULL, 0x168EF2E9A2FE271AULL, 0x6C20AB100D10365FULL, 
            0xB9C12BF054E9E546ULL, 0x2A1E4DCE139A8DDAULL, 0xD96B5A440C37FB66ULL, 0xD2422852B5311BF6ULL, 
            0x747FC2F4ED955F3BULL, 0xA2F0DDF3D1673FFDULL, 0x7ED1448705D31F3BULL, 0x828E72CC3023ABB1ULL, 
            0x9C132251AF6B3077ULL, 0xEDF86CFA84E97927ULL, 0x6C200DF1F96FB25DULL, 0xD26F406632BEB066ULL, 
            0x80F986C9D9E23872ULL, 0x0729DBEA2A3A6B67ULL, 0x3CA4CD88C016043DULL, 0xB53B25C4404F14EBULL, 
            0x5B34351E27A5AA6CULL, 0x3510ACAC4057F440ULL, 0xF0318EEFEB206BF5ULL, 0xABF70DE5B7B2EFECULL, 
            0xE8B6F5D75211EBE0ULL, 0xFB565A98BB55329CULL, 0x0F5254E0C73B40C0ULL, 0xC6BF8A5B36BBDC5DULL
        },
        {
            0x96FE38F6ECA982D4ULL, 0x2FC58FF0BE3202E9ULL, 0x4A96D7BA04134093ULL, 0x2E91695D0DB666EBULL, 
            0xFC3C32733316059DULL, 0xF43E2C0AC1AF63A1ULL, 0xA9835C6359D7DF5BULL, 0xFA5CF0419356097DULL, 
            0xE4D4D64AFF73CFE5ULL, 0x7D82BB7ACEF11234ULL, 0x147C0ACD4FF3ED2EULL, 0x41B2F59DC55A2382ULL, 
            0x85151FBA5E560437ULL, 0x0E2A1C525933438BULL, 0xABEB8B30B077F38CULL, 0x0EFA1EA540ADC7B0ULL, 
            0xD70F8FB4EFFED938ULL, 0x9EE0B30BDEF540EAULL, 0x1BACB73051F0CF85ULL, 0xE8088B218B9C0075ULL, 
            0xA765F96759E2389FULL, 0x0DD2E7DB953CC724ULL, 0x7353DB87E4A1FBD9ULL, 0xA8248870E0287662ULL, 
            0x7EE35C2340610005ULL, 0x9D6659660267FFD1ULL, 0xDEFE7093C17782CBULL, 0x6DE70E06CD3BBAE1ULL, 
            0x6FFD9A82D27C6268ULL, 0x72CDC4DC9D51AB89ULL, 0xE0E6705441BAC3CFULL, 0x3BBCCD0B0E9B5A53ULL
        },
        {
            0x8AC7B5D0A0A0BFF0ULL, 0x6806911BC8E0C8A0ULL, 0x119673DE15736507ULL, 0xEE5BE676996EAE92ULL, 
            0x0DAFB8A9DA36A0BAULL, 0x8B2C5938CBA02228ULL, 0x52D3109C160A13E9ULL, 0xE9335ACC73E4D128ULL, 
            0xD804AE5753031551ULL, 0x41913B8B88F1C0EEULL, 0x81E301D8CB1527CBULL, 0xDCC6D64B0F0CA8C6ULL, 
            0x66A61D72A4D4D5C3ULL, 0x195CEAFF87CB9E8AULL, 0xB488262E18C20683ULL, 0x5698B7EBF3C9D56FULL, 
            0x24705FFB4CA35635ULL, 0x4EFB87A690AA3BD4ULL, 0x5BC96A46F0714B9CULL, 0x3729CFCDEF875098ULL, 
            0x4AFCB658AF454E9DULL, 0xDB0E5CD69BF44913ULL, 0x9C4C8F2156D1DFEEULL, 0xC0F016ABC66B75E2ULL, 
            0x878FCDC58F9ED82FULL, 0xB7CEB24D79F9E33BULL, 0xDBFF6CE5B3CBE781ULL, 0xA024624AFB2E208CULL, 
            0x0D8D953D4423DDB6ULL, 0xA089AB2A67EAA155ULL, 0x6368C51687CB82D9ULL, 0x7B4F094511F5342EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeyRotateConstants = {
    0x06B31E0B89347B01ULL,
    0x90CEC381E6F566AFULL,
    0x6FDC38EEBF097207ULL,
    0x06B31E0B89347B01ULL,
    0x90CEC381E6F566AFULL,
    0x6FDC38EEBF097207ULL,
    0xE717C2366ADE5F07ULL,
    0x9559D8FB501979EBULL,
    0x5C,
    0x22,
    0xF4,
    0xFF,
    0xA4,
    0x53,
    0x5C,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Antares::kKeySpawnSalts = {
    {
        {
            0x8154E722A78C0B0CULL, 0x99336025E6F96990ULL, 0x47230F6FF21FF8B5ULL, 0xACCE67C0E7B004CCULL, 
            0xEE9717B1A5A917B7ULL, 0x8E106DDCAA704DCAULL, 0x955C9E6A3A1433EEULL, 0xC770F4871D7D077AULL, 
            0x6C2D153340C5E0CFULL, 0x313106747A710D2EULL, 0x9B3F13B82C339757ULL, 0x26C63A64EC398E75ULL, 
            0xEDE440BCB7058403ULL, 0xBA67EA6E63FFF0AAULL, 0x0F4074CC6B2EE7A4ULL, 0xDE022488768DBA1FULL, 
            0xADBBA08F24904BB0ULL, 0x8F91138BE096DBDDULL, 0x2AA7CD5384132837ULL, 0xAC10649B0AAA7ADCULL, 
            0x06160E94C2D9CB12ULL, 0x10C072BF857FA4D3ULL, 0x7E9353DF999518D0ULL, 0x51C6F403D870C844ULL, 
            0xEF6FC2CAF70FD850ULL, 0x9C509D33AC5A9A73ULL, 0x7621CFDF37E06001ULL, 0x049AB8C2EC7A6CA2ULL, 
            0xCE0A2BC925ABF603ULL, 0x9720367F9585339BULL, 0x084B79FF50E7E4C5ULL, 0xD44A08616105D252ULL
        },
        {
            0x3A334740CF5DD875ULL, 0xA98EF4CE43815BEEULL, 0x9888594E4351AFC2ULL, 0x9A76D60BE1B782B1ULL, 
            0xA6D718B1ACB5C462ULL, 0xF3AB5740DFDE02EFULL, 0xCCE59E0803243BA4ULL, 0x70285510B157E873ULL, 
            0x2FEC08F48100E4BDULL, 0x26A107DAF93DE161ULL, 0xA4ED90E9A9B6DB96ULL, 0x057AFA454425B940ULL, 
            0x1CFDB4D215325623ULL, 0x32271B49B8D56A5EULL, 0xB2BD4A92E1FAC587ULL, 0xC0707F842339FAB4ULL, 
            0x0E5C35731DE57C7CULL, 0x81DF4DFDB4656272ULL, 0xC1DA9A58A060F1EEULL, 0xA7808945788D6676ULL, 
            0xE8E9521A2536BCD2ULL, 0x48F3A6CB3CEC1FF8ULL, 0x71B45E84C5FCCF7EULL, 0x42E9114F534A5E9BULL, 
            0x9BB4A7B8B40DEB73ULL, 0xBF1957D3DE8A6E87ULL, 0x8676699C72AAD7FDULL, 0x22A430504D1E16B3ULL, 
            0xA76032B0BC85C151ULL, 0xA7193A49A252C89EULL, 0x81758EE83B5C478DULL, 0x514C6F3A9FF7E518ULL
        },
        {
            0x26A6236932ACC91EULL, 0xA29999F72AF45C5AULL, 0xC9893B7C5FEBF2F7ULL, 0x4DC411134DBBED9BULL, 
            0x6E4945168D212121ULL, 0x302E5DC6EED53D72ULL, 0xFD56FAE516426C19ULL, 0x3E0C6D9023258F44ULL, 
            0xBDD2BCB1884982D0ULL, 0x0634DFF4F7B8DD88ULL, 0x4CEC1B83DA15D8DBULL, 0x7072F6C4CA3934BEULL, 
            0x4419FDE0EF6ADC7CULL, 0x2061BBE284B0EDFCULL, 0xEBE9B3344A7343C2ULL, 0x37F665231AE04495ULL, 
            0x853174892C1E7976ULL, 0x10928A3C18A61D43ULL, 0xA947961DCB3BADBAULL, 0xC08433DA852D524DULL, 
            0xE18E79279E3DD7CAULL, 0x52DDE0191F9292FEULL, 0xB16D744BECA19667ULL, 0xDB0B6C7A43709181ULL, 
            0x3932153CA92A7A1DULL, 0xA48BE1A9F9FB7894ULL, 0xD5909F9870462D80ULL, 0x1078426F9894BDBFULL, 
            0xB5E774B1E314AE19ULL, 0xB78DE258217AAB4FULL, 0x75588EA225C92D9FULL, 0x7A3A7DD8129FF5C4ULL
        },
        {
            0x083F96DCADD1C67FULL, 0xC4B1C2C3CCF2AC9FULL, 0xD3285A40134D2077ULL, 0x9A2B75F07601A126ULL, 
            0xFCC614386FB5938DULL, 0x388D6D199D4A3CA3ULL, 0x52426C4FD14AC372ULL, 0x23973846E3B00E90ULL, 
            0x68E5911E9EE7DFF2ULL, 0xBC0764C42A9444F3ULL, 0x6A7ADB364C315EBDULL, 0x6105A9827B83D25EULL, 
            0x22C5F3CC38F566E0ULL, 0x34F194DF1412A53FULL, 0x0648B59B38E0F9F5ULL, 0xBBFD9E2609FD7269ULL, 
            0x6ACFB9AC30C5657FULL, 0x6873976DA44A1D61ULL, 0xAAC983074A2B8D09ULL, 0x36DE844006425179ULL, 
            0x86C4FE0940C7247DULL, 0xF319768CD48FB57FULL, 0x3DE27BF3D0729FF2ULL, 0x29C8651176539CC4ULL, 
            0x82F88E617836DD05ULL, 0x60CE91853141CD08ULL, 0x955D06BEFD684280ULL, 0x0E2AD6C9005AF8D1ULL, 
            0x195898E56BD60C53ULL, 0x3528F422F4EE7AEAULL, 0xC6D5695F74BE71E0ULL, 0x58D0C1D137D14C8FULL
        },
        {
            0xE1E2ED132683C002ULL, 0x9F2CB3A66DCDA07FULL, 0x0384BFBEC73C5284ULL, 0x34CDFB966B1812EDULL, 
            0x0C6D547357DC5090ULL, 0x3ED21C70658D5274ULL, 0xE73062D252365908ULL, 0x890E3DE791C1E77EULL, 
            0x2F7A82A8F9F444F2ULL, 0xD3EC99DED4BE36D4ULL, 0xE0F557A4AF5D2C54ULL, 0xEB578942FBFA7094ULL, 
            0xF7C31D2E62B2510FULL, 0x8DD91852DAD40262ULL, 0x2AA194FAD242DF0DULL, 0x4F0119389902A400ULL, 
            0x9AFBA11A9D3D705EULL, 0x5C22DEF4883FD105ULL, 0x23AAB35E14FC9DC4ULL, 0xED7CF96EFD7ADD29ULL, 
            0x0A1948D74CB57B10ULL, 0x250F29A9B3E5B0AFULL, 0xBD16FAB42CCE5E2CULL, 0xC95CC56FDE504F51ULL, 
            0xD74B5FB70E274ADBULL, 0xCAC91C584EE94C4DULL, 0xF5B7AE8906DE4826ULL, 0xC1BDB93901F484C5ULL, 
            0x3B2A85F4F820EFD5ULL, 0x4A2596CA1B829FDEULL, 0x3E3FE8BAEF7335C2ULL, 0x60E5A85367E0578AULL
        },
        {
            0x1451EE1835EE835AULL, 0x47262B018140E6E0ULL, 0x7FC75510151337E5ULL, 0x98E1773C98BB12F1ULL, 
            0xE9A02ACA6BF382C0ULL, 0xA3455EBDF9789F79ULL, 0x42D2067FFE5A1CE9ULL, 0x6FA448D22349154FULL, 
            0x1A4E9C25E3C41EF0ULL, 0xABF600744DA6A532ULL, 0x22C1367B12A7FF7FULL, 0x5F33EBEF929B64A8ULL, 
            0xC6955BCB278FBF50ULL, 0xAD13CB7928BEBC7DULL, 0x057F8D111D2F3E69ULL, 0x05BC5FBA37325686ULL, 
            0xB1DB3E1CFEA47F7AULL, 0x03A02B2F761BCE8BULL, 0x7151CEB3C36EAB65ULL, 0xAD94F73F7EC7B1ACULL, 
            0x315203EF856E5A80ULL, 0x8B63ABAC84CB2C5CULL, 0xD233B099E124FBFAULL, 0x3F67DEDAEB1AD15AULL, 
            0x217E2C70A5594632ULL, 0x54C010737ECAF252ULL, 0x5F693BB366B0DDC6ULL, 0x3655E322451E1B42ULL, 
            0x96E62907251B215FULL, 0xD45126A138926213ULL, 0x2F35817118C16DDDULL, 0x156B551D3D97AC29ULL
        }
    },
    {
        {
            0xC2BCC559AEB5D794ULL, 0x69941A29BEAB3ECAULL, 0xFE73719C324F886AULL, 0xEA75C664DF11A173ULL, 
            0x181300BCB44B23B7ULL, 0xCCEACDEF9D4DCBC5ULL, 0xE7F51DEAD2C57B1FULL, 0x9D4860445B6AFAEEULL, 
            0x3FFE5C572779402BULL, 0x299482A552796050ULL, 0xB64298DC98F201B2ULL, 0x58C14E31B3DDEDD4ULL, 
            0x6ABDE6DCFD8508DBULL, 0x2E1AC111FC85C54BULL, 0xDD27CB590AF361C8ULL, 0x9ABD37F999AB490CULL, 
            0xAD417A68D178C5F6ULL, 0x671BBC198EA41B2EULL, 0x0D2C1E606CB05166ULL, 0x145CDAD7C65BADE7ULL, 
            0xC620A3E818543A19ULL, 0xFD61CFCCE3F0607FULL, 0x2DA5FBAB3B6AB6ABULL, 0x0FB05177107BB687ULL, 
            0x7CC113FB9BD40FC7ULL, 0x68BC91CD8A1C1331ULL, 0xB06FA62526B1CF1CULL, 0x25D310B91E4A650AULL, 
            0x4112EE0B3FE2AEC9ULL, 0x15C3434CB942FA4FULL, 0x6441619E381120CFULL, 0x98F989FF4A7B629DULL
        },
        {
            0x08918364764D95C7ULL, 0x7ED8D02FFF2E9B3CULL, 0x44CA236FACBCC59FULL, 0x6F83E85C36DA49B1ULL, 
            0xFA182BC172CC4F70ULL, 0xDD005AE0D81C99C2ULL, 0xB6F720719EA64D3FULL, 0x0C386397A11849AAULL, 
            0xF224E28DB2E08CBCULL, 0x67EB67BA9E6FE46CULL, 0x23312E01B4AFFD52ULL, 0xE99400442855CF7CULL, 
            0x39DB1DCB4E82C266ULL, 0xBC33851E086F1EA9ULL, 0xD6E4D21045140B21ULL, 0x08EDE0509170AA58ULL, 
            0x3EB17746403ACF93ULL, 0xA7C74B2D13538438ULL, 0x2D5FE514370D9DF7ULL, 0xB51737747D18A896ULL, 
            0x365272CC112077E6ULL, 0x55720C666EBBAFF5ULL, 0x00D289F48E31C648ULL, 0x9AC604177E02CDE0ULL, 
            0xC4B40F2493EED48BULL, 0x916A2EBC9C356F30ULL, 0x8F48C24689D840CEULL, 0xE59DBCAEB00BA91BULL, 
            0x8F90CF382CD7F8FFULL, 0xDE873AA89101B6CFULL, 0x2A6F2A30967EC55BULL, 0x5A7042C66C3AD9D8ULL
        },
        {
            0x3858ADBBE52D2CA0ULL, 0xA5D8AFDE712AECC8ULL, 0x9F48B7FB70530AD7ULL, 0x606381D13B3B3B65ULL, 
            0xF2AC586E33478FCFULL, 0x59EFA56CC2BFDCB5ULL, 0xFC4C5BF0E9792048ULL, 0x8457BFFEEAE9A6FEULL, 
            0x9F137F0971B7747CULL, 0x1EAC5E9BE0F4C38EULL, 0x9FF05F58994C92FDULL, 0x5CF1C1C0FF1B7599ULL, 
            0xD71CEA32F246F9BCULL, 0x3E2099EDEA33973CULL, 0x0168F20AB008D7DAULL, 0x0FE6A00D4BB9CF11ULL, 
            0xA9AAF8FC61DD8F63ULL, 0xB0EBF07127725655ULL, 0x01520E848638D688ULL, 0xDC3237B3EA0BD6E3ULL, 
            0x9C3F068498CB4237ULL, 0xFD3C5884DE2DADD1ULL, 0xFCCFD7CF5589BC2EULL, 0x2970858C94FE582DULL, 
            0xDD76B82CAFDC2BE3ULL, 0x3DF6CF3798C0DFA8ULL, 0xA369720EC4551B1FULL, 0xEDB1254FD64570C1ULL, 
            0xCC8711D260572D31ULL, 0x078BBB1BD2B33271ULL, 0x342CC843E9CD2A6DULL, 0xEE1682E161ACE873ULL
        },
        {
            0x68D6F055154D3DD4ULL, 0xF4928BAD23B8600AULL, 0x994BC4415319C8B2ULL, 0x71DF2520853CD46BULL, 
            0x4C4977C5435D95A3ULL, 0x3A1A4AAEF61F914EULL, 0x78F317F389273444ULL, 0x2C02FDA3D6AC4CB0ULL, 
            0x2910533151C19509ULL, 0x2563C7FE6D1EC3E7ULL, 0x1937734F240F7147ULL, 0xA1A75B476C59F624ULL, 
            0xF1A4827358F35AFFULL, 0xA87B80051BC590C3ULL, 0x42A1F92CDDD3975DULL, 0xC5812C0EC77BDF6DULL, 
            0xE5C712EBF428CFC6ULL, 0x907C607C27716F5AULL, 0x2D52AD5B28337413ULL, 0xDA995C5CDEF9AF9FULL, 
            0xCD6B584014DD15ADULL, 0x3CDD9564579A7C5BULL, 0xC833EF33915D3EC6ULL, 0xA336589449498DB9ULL, 
            0xF78FBB24AE2B1C1FULL, 0xA5254C20D51109FDULL, 0xA63A5F4B10651758ULL, 0xA5765312543C7DC5ULL, 
            0xE1FE5944491F93FBULL, 0x6B98B07800905CF5ULL, 0x8B7EE48FED212398ULL, 0x85FCF393FD385FBAULL
        },
        {
            0xE760B4375EC5FE4CULL, 0x575DBB301BD6F075ULL, 0x11643F46C8E4067AULL, 0x1B6715A9B82038B9ULL, 
            0x6764B7065ECBFBB0ULL, 0x67A19AB33261679FULL, 0x3737278493CA91C4ULL, 0x29BD01AE0C171B6CULL, 
            0x23DD49483F0891D0ULL, 0xF7F3E80B59DCD220ULL, 0x78C577BECBE52DD1ULL, 0x8377983D9FFC2CCAULL, 
            0x133946C2598A7A1BULL, 0x3DF4E5A855166ED0ULL, 0x571AC8AA5F2F62C6ULL, 0x069C2C1546DD1210ULL, 
            0x19C292668683C623ULL, 0x77DC02CD29FEBBB3ULL, 0x1EC1599E867C42B1ULL, 0x54584F7F7159151DULL, 
            0xC83BC85BDE3B88E1ULL, 0x7A8D126BA6131F8BULL, 0xD3B881CA49E4C44DULL, 0x5C5E0773433982EDULL, 
            0xFD346012BB40B303ULL, 0xCDC2200BE3C19249ULL, 0xBBDE4852C83EA992ULL, 0x1B1DF707C685E7B3ULL, 
            0x5A7CA84AF49026F3ULL, 0x00F044521E2063C0ULL, 0xFC8D7F32F4CFAFF8ULL, 0x70A2745A40518CD8ULL
        },
        {
            0x4B769AD5D5593976ULL, 0x0B0E987FA935FCD6ULL, 0x15AE08884554797EULL, 0x1A0D19B0132843B2ULL, 
            0xA2D3EA6C409A8949ULL, 0xADA4D156AA94CC54ULL, 0x89F4F55CCAE7958AULL, 0x04ABDFF55726E599ULL, 
            0x776781E9CB0F9E11ULL, 0x7BF3029984AF560CULL, 0xC1726E3776C19378ULL, 0xF0B77C7463E973C4ULL, 
            0x75649B55E4257907ULL, 0xE1DF3A8B955A74C2ULL, 0xD6DF3A088BE773DEULL, 0x08EB65B1BAA788E6ULL, 
            0x0743E284540F8520ULL, 0x3805346322C0C7FDULL, 0xFFA441C8C8591E65ULL, 0x6EF742DB1A7C139DULL, 
            0x92C2C7214290247CULL, 0xEFA865DB051974EFULL, 0xA6975FC10D3894BAULL, 0x1C159BD94C63D323ULL, 
            0xDEFE34DE65ADCD64ULL, 0x15F6820E2BCAAB3BULL, 0xA61671BFFC6885A6ULL, 0x28029E7B6A2EAFBCULL, 
            0x6D9A99DEC71A9DAAULL, 0x47D22FCBFBCD6ECFULL, 0xC38914794DE8A45DULL, 0x224C15C796B0E0C1ULL
        }
    },
    {
        {
            0x47986DA65B420245ULL, 0x14DF7654559AB073ULL, 0x3C09C34993884615ULL, 0x9B07A408C95E3331ULL, 
            0x9FDE24D88081A484ULL, 0xBDBFBAAD79568058ULL, 0x1382BFA4A3B2C5B6ULL, 0x504141B7A9077039ULL, 
            0x3076EC72E6CDC9B6ULL, 0xB0D25031BBBEFFF8ULL, 0x00F9826015FADB99ULL, 0xF6C41693D83D2E10ULL, 
            0x9462295474C0CA61ULL, 0x61E0BC269956F934ULL, 0x1065B9D98A960DB0ULL, 0x59A3C796F162A7B0ULL, 
            0xE9A68A3CCDB6EFE5ULL, 0x216732EC30165BB7ULL, 0x27EE0F609123842FULL, 0x6FF0D17B3D87EDE2ULL, 
            0xFD3923216F87BC26ULL, 0xC5C5915D7E952F67ULL, 0x4B39ACBEAA6D7912ULL, 0xB27010FBCD252E18ULL, 
            0x44E828BB3E67B24AULL, 0x9161189FF9459233ULL, 0x889BD43945AEC0D2ULL, 0x42B72BE2CAF693D2ULL, 
            0xA0218874C1843B6BULL, 0x5FC8844BE1624A5AULL, 0x65F01DAB36FFB26AULL, 0x698D356864CFFD28ULL
        },
        {
            0xED7CBFD9C965B2F3ULL, 0xB847E9083F622627ULL, 0x90246B1E60908B4BULL, 0x12A4B500CB477F5AULL, 
            0xFFA74BF120462C52ULL, 0x10D4B1BAA667BB42ULL, 0x3154EAC2160E89D1ULL, 0xCCD45C16B8DFFD38ULL, 
            0x03114EA5EE0FAB78ULL, 0xB0395BFDCA02A7FCULL, 0xB92F1F5E4E831681ULL, 0x8C513E84F2364DF3ULL, 
            0xB40F6406C2EF504BULL, 0x5587865C5F3D4207ULL, 0x2EF06B06676D00A4ULL, 0x03F7B6AB719FD743ULL, 
            0x14A8A82B3859EA5BULL, 0x01B785C9899CEFEDULL, 0x41F25C6D0DB3765BULL, 0x3F0C36AECAD5ECFEULL, 
            0x2AB602C96EFD8651ULL, 0x53D88AB54A33D702ULL, 0x14246B51BF3B8800ULL, 0x595C7E06624CBCD3ULL, 
            0x37AE9AD9C65C1D3EULL, 0x236037791C7A3A3BULL, 0x50CEFD24E4364D2BULL, 0x81C5A46C61C2F88CULL, 
            0xBA23AF1F779DC9B1ULL, 0xE36AFF917827581BULL, 0x29C22DCA9278D260ULL, 0x5FB8974B682ED13CULL
        },
        {
            0x358427856E3E23B8ULL, 0x24008AFED22A2C04ULL, 0xB6BF1373AC4C4A83ULL, 0x3A188263876A1869ULL, 
            0x2FD43FB6CA3A5DA5ULL, 0x2C4504C097DA73DBULL, 0x3357416CB2346B2FULL, 0x2564C522F4EAD650ULL, 
            0xD552500575DB1EB3ULL, 0x6247B01F7E6B1A4AULL, 0x4F600CDCB0BD3D44ULL, 0x18790E3F68004063ULL, 
            0xFA973BDFA96625E6ULL, 0xC06B225602892E6CULL, 0xA84E7C92DC061A1DULL, 0xFA6C1E2E2E96DF3EULL, 
            0xE4FA6A9EEF70FF83ULL, 0x0E47F26C87EE3690ULL, 0xA24089EAC8269272ULL, 0xA1F3D98CEE1574E5ULL, 
            0x0451BECC58438775ULL, 0xF8B9F2D5074425F8ULL, 0x1FF66EABF3CC382DULL, 0x26756F52F1D2BB37ULL, 
            0x1D43A286B87BD0FCULL, 0x6D644062A831C8B5ULL, 0x2A87D54A6ECFFFD4ULL, 0x7E736178A60772DBULL, 
            0x06971E4808F1B75AULL, 0xD41E7CC47132A770ULL, 0xE33EDB70DE5F71C4ULL, 0x16130BC7AA81EB23ULL
        },
        {
            0x7CB55483F389B0C5ULL, 0xBEE0F53CABB8E833ULL, 0xC535A590DE75C406ULL, 0x6D9DD44B413BA0A2ULL, 
            0x91357B3E56A391C9ULL, 0xF3936D42A2E3A142ULL, 0x013C0AA70B2F6B78ULL, 0x43CCD22767F8454DULL, 
            0x26EF3652AC2774EBULL, 0xE76CE8B5525C9A36ULL, 0x36FA8D3B03988338ULL, 0x3FEC6A1F00767816ULL, 
            0x1FB07CAFDBC76A09ULL, 0x024B2845A338656CULL, 0x8F4F74180B0D5950ULL, 0x210EDF93802375F9ULL, 
            0xD457513A302792DEULL, 0xA9404D1F936898AEULL, 0x0AEAFAD67BCDB9F7ULL, 0x3AD7BFDB530D2A6CULL, 
            0x49B78A65359D5BDBULL, 0x631637EC75BDD744ULL, 0xC26D497A01D13451ULL, 0x4A263DC02C9F8E49ULL, 
            0x290853E878038185ULL, 0x9522AFD73A3D2ECAULL, 0x824EFE1A2C5FE0FAULL, 0x340039E5F19256E1ULL, 
            0x4B2AE7D28ECDB262ULL, 0x462378A3F0BAC1D4ULL, 0x84146CA1E19D09CBULL, 0xDC04D598E55AF813ULL
        },
        {
            0x219169121C23597CULL, 0xA440C566DD3EF298ULL, 0xA82C3C685A65716DULL, 0xA3B43769B264367AULL, 
            0x658B8EB9CD54236BULL, 0xA7A58532F612F2F2ULL, 0xF650D4B08A97423CULL, 0xD338F29A4E1D328BULL, 
            0xE3CEDC224BE3CF83ULL, 0x5DB2B450B8B92981ULL, 0x28BB046A9861DCE6ULL, 0x6A226625E9090F1CULL, 
            0x21C43AE47AC076FAULL, 0xBB3368CFB7BD02F6ULL, 0x2E97A7AF134CCCFBULL, 0x9409EA887DB7D51DULL, 
            0x3D632E0BF30B72E5ULL, 0x340E69F80FD192F8ULL, 0xF6B6DE5B36F1F0F1ULL, 0xB3E9BF63D4EAA8A9ULL, 
            0xDCC584A2B1256048ULL, 0x5E493FA1F40B873CULL, 0x03E06CEAD3DA5921ULL, 0x430A89BAFBB6126BULL, 
            0x0E9866A44B214569ULL, 0x8309EE414DB9CDD8ULL, 0x7C0E890F08B7723BULL, 0xE3B740909B06B74FULL, 
            0xC2F670BA7628B5ACULL, 0xE6085E401EFA75A8ULL, 0x947A1F6A84DFB8F9ULL, 0xFFA46C1C36EB78A1ULL
        },
        {
            0xE820FE01D03213C9ULL, 0xFFA23378076225C0ULL, 0x0AEDB902284C2A91ULL, 0xFB908C5F16CBA238ULL, 
            0xC5ECD424783CB0EDULL, 0x45A1AD20E0AAB75EULL, 0xADD6A38CC8A78968ULL, 0x755E6C89A4FB141BULL, 
            0xD4A488998E308856ULL, 0x2FCA38FEDAC305D9ULL, 0x0E9424D99C4A4B0FULL, 0x0A22EBDAB9FCE70FULL, 
            0x766DEDDABEF80BBCULL, 0x1F5603D2C6D9BD3FULL, 0xB02E6E60B5124937ULL, 0x0A6DEDE10F9354AEULL, 
            0xFD2B2C427E078BEDULL, 0x27E6E1093AA7E8E3ULL, 0x55C51B77534586F8ULL, 0x1E4FD0202BFB8C5AULL, 
            0x06E84FBF0FC92171ULL, 0xB0CCD99D689E935BULL, 0x9DFE8127A0C65CD2ULL, 0x90D700D2E262D232ULL, 
            0x4C2ABACD3DFA2CDEULL, 0x9EEC67EE646E35E4ULL, 0x4854E727AD00E03DULL, 0xB72081281287C2DCULL, 
            0xBC33B9E606057778ULL, 0x624595878A5D6A1EULL, 0xF40D6F5C86972A5DULL, 0x1F87EC43E4A1DEF3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeySpawnConstants = {
    0x3B76C31EFEDCB08CULL,
    0x40BF5EB1AB253781ULL,
    0xC42FD410D4DC7CE6ULL,
    0x3B76C31EFEDCB08CULL,
    0x40BF5EB1AB253781ULL,
    0xC42FD410D4DC7CE6ULL,
    0x0699A51D8CA2A8EBULL,
    0x054B2654AF13BDD4ULL,
    0x6C,
    0xAA,
    0x2D,
    0x76,
    0xDB,
    0xC1,
    0x75,
    0x41
};

const TwistDomainSaltSet TwistExpander_Antares::kSeedSalts = {
    {
        {
            0xCA0C60844204CB0CULL, 0xBF2B972723C7BFCDULL, 0xABD12196BA6AEAC8ULL, 0xCE3FCA78B7EA8B65ULL, 
            0xCA68CDAE9E4A6FC0ULL, 0x9FD0C84186A8C16AULL, 0xD9E3A640A34627E1ULL, 0xB1F29DB9790EEBACULL, 
            0x721324A6B233A8F7ULL, 0x084DC9338B8EFD17ULL, 0xEF37D140BDA5EC73ULL, 0x754130E73A10C9C7ULL, 
            0xDC44FBEADE0DB3D1ULL, 0xF46371C226DCFCB2ULL, 0x9AE90744CA99F967ULL, 0xEFDB3166E90219C2ULL, 
            0xC8B0F91784852E53ULL, 0xB250A60F4DA2B9AEULL, 0x16BF164E2119A9DAULL, 0x49E037CC678E94B2ULL, 
            0xC9C5FE59BDFE69AEULL, 0xE17326CAA9BF5B68ULL, 0x5F4F3BDB677C32DDULL, 0xD66B899B3649E93DULL, 
            0xDFE8EA6CF8230B23ULL, 0x740031D21D4C0134ULL, 0xE2839D9AA8E2BD0FULL, 0xFD779A4B9197FBA3ULL, 
            0x1DA5C9859CDD3908ULL, 0xD1A10308CDBDD5F1ULL, 0x045D7AFC1E0821F4ULL, 0x4E6D91983899D516ULL
        },
        {
            0x188EC4E969B1709EULL, 0xEA812C200418ABD0ULL, 0xC774A7C758FBB36DULL, 0x08B3B9446F585045ULL, 
            0x3BCFCE56CCE1B5D3ULL, 0x4E8F26389E1A6DE3ULL, 0xDA0600540EE1320AULL, 0xDC5E6DC3142F9ED5ULL, 
            0x3C9B92401D8E29B3ULL, 0xF41C64E612B3064AULL, 0xABDE4B92B80C6871ULL, 0xF95E6D83B154DF6AULL, 
            0x3D1B989F2470A0C6ULL, 0x53D35AFD05222468ULL, 0x52B8E245665FEC4AULL, 0xF4B6E1D3F94D518DULL, 
            0x46FD52255A66C62BULL, 0xE6326C271A64B4E2ULL, 0xD3E1BC2193BBC8D9ULL, 0xAC21427AFD454A68ULL, 
            0xEFD60A9DCBED0068ULL, 0x5DB8F2CB744B82FEULL, 0x07A260A59F206ABDULL, 0x371E22B353515514ULL, 
            0x9D58B99F898A57D9ULL, 0xD2AAE04AC368FC03ULL, 0x30C97EFD39672BA5ULL, 0xFC7F3F2ECF96AED8ULL, 
            0x64E83EECF0D69642ULL, 0xBFBD1F7D01653C19ULL, 0x989FCFBC6F700775ULL, 0x7F0BF98DBBFE37C4ULL
        },
        {
            0x708BD915E5D22EF8ULL, 0xBFBAE476A3C3261FULL, 0xD4DD1AFAA7F296E3ULL, 0x0CDDBD2E3B015AAAULL, 
            0x107617DCA9CCA194ULL, 0x9BC54A63079F324BULL, 0x6E85EB35EA8C5B2CULL, 0x75B2AAF5B59F5A95ULL, 
            0xDAA327E8FADAF648ULL, 0x37DC7F0657ACF6D8ULL, 0x5BE0BE5D9958F0EDULL, 0xBBA8A2130C332BEEULL, 
            0x91E68E5D7A4543BFULL, 0xEAF58F50CA61AAA5ULL, 0xBEB4BC4ACA03891FULL, 0x44B3F575BE7F770DULL, 
            0xDA900B9BB58CD658ULL, 0xA05461F8B9FCFC9AULL, 0xCCBFF160BD7DC93FULL, 0x21F050558A4F25DAULL, 
            0x972809F061B44E0DULL, 0x81961A964B90E6CDULL, 0x68178AB04EE5DEBBULL, 0xC059F13DA4DB8D5DULL, 
            0x131BF5FC45139E46ULL, 0x044393FBC79B95F8ULL, 0x394E91EE683595AAULL, 0x49FC1CD9DEBF329DULL, 
            0x5402F2A6223E749FULL, 0xA089CE39FB2CCD01ULL, 0x0D35EEE8B17789C3ULL, 0x8EFC6AFD6FA39FFDULL
        },
        {
            0x47997725750AD418ULL, 0x89BA07ABFE826386ULL, 0xE90542A8AABE111AULL, 0xFE40ECFF4C2049C6ULL, 
            0x9D84BC5860951288ULL, 0xAC0A4346D78F94DEULL, 0xA8AEDF816B974D7BULL, 0x6AE3273071981A26ULL, 
            0x140596D230EEA795ULL, 0x997091A34DBC97D7ULL, 0x0F91F1A4D9E26E64ULL, 0x1BB8B17EBDAD8C16ULL, 
            0x1510366569578D50ULL, 0xB41B4274047F52D4ULL, 0x848302A848D5A8EFULL, 0x0C1A5E7CCB5282FEULL, 
            0x6F6B3CAE9996B28CULL, 0xD9129C495B1F547EULL, 0x52BF9761E0D5B6CDULL, 0x14EC6FFD5882C75DULL, 
            0x438A608996F96A65ULL, 0x294B9153233941FAULL, 0x961CF3E7B8D60C89ULL, 0xF5A7B64589037F2DULL, 
            0x32C0B78CCADAB89AULL, 0x772D02BCF4265416ULL, 0x3886904BC0259078ULL, 0xCE07F925AE633546ULL, 
            0xA0599CB99E93146BULL, 0x2310D7EC496A95D5ULL, 0xFF41F5CC2A1DCE19ULL, 0xCCB5FD6171D1A9F5ULL
        },
        {
            0x13366C16157B4D60ULL, 0x1F649E188D30CCF0ULL, 0x8C1EB22194ACF074ULL, 0x7603142741A630D5ULL, 
            0xE7B8136B13C47EFAULL, 0xA4E5662FB35A5B48ULL, 0x4753BAF2D299E2B7ULL, 0x856AA7A0F2086FC2ULL, 
            0x522C1E7688B96409ULL, 0xCCB1EE3C4E60E53EULL, 0x59AEF443BC8EC459ULL, 0x7E6F90DB949199EFULL, 
            0xAFF5FA581A2C698BULL, 0x35079D8573C463E7ULL, 0xD896D0E9E9BCDC6BULL, 0x708C29CFDABF60E0ULL, 
            0x5B75A5F79DD21496ULL, 0xDC674F577D3C9C75ULL, 0x489916278AE45B7FULL, 0x643F5122811303E4ULL, 
            0x7CFDEFD1668F5122ULL, 0x6D77CDE1DBE08EE5ULL, 0x56BF45320D732899ULL, 0x577E7ADFE4C006A7ULL, 
            0x38B187F9D74BBF2EULL, 0x2C702542C877C03AULL, 0xC32F4B0FAE5F994DULL, 0x46399133A17777B1ULL, 
            0x60B434D70645C494ULL, 0xE34418171661A814ULL, 0x00FA1ECFB2C9CF38ULL, 0xF6E30D8293705D10ULL
        },
        {
            0xA931E407EF6EECFEULL, 0x004F25182DF82B6BULL, 0x69CA401250AF23ECULL, 0x950EEAE4890B07C5ULL, 
            0x7D652DD3BC74B596ULL, 0x35D4A0C43FF96C57ULL, 0x058E527DDF5239E9ULL, 0xC7AFFA2E4E0AAB37ULL, 
            0xA0DABBF548C654ABULL, 0x6E687543A248B112ULL, 0xB948D615B6564165ULL, 0xA4BFD411717AFF41ULL, 
            0x75693F021C053324ULL, 0xAE5ACED0487E7910ULL, 0x0EF6259CB6E55A32ULL, 0x2E4750AE11823F9EULL, 
            0xF801B1336DF15A28ULL, 0x94EDF8A67F0BF8CAULL, 0xA00C3653D0B4972DULL, 0x7915E4820F0C67EDULL, 
            0x4E9B5300CCF5C70DULL, 0x5491857EAED9F890ULL, 0x0197492BAF1712E9ULL, 0x52ABE033B3504809ULL, 
            0xA4F8320D322C06E8ULL, 0xF3BDAFF3BBF48912ULL, 0x4A0D5557BD9DDA73ULL, 0xB2219E3E82E5962FULL, 
            0x20F402B135710613ULL, 0x060201DCC76A5BEBULL, 0x8F4998B6BBDDE5AAULL, 0x9AC5770FC0CFA74BULL
        }
    },
    {
        {
            0xAF57D941D9EBEA97ULL, 0x1E4ECF76AE65E0F1ULL, 0x715CD53942760ABFULL, 0xF2BDD17E1039FADAULL, 
            0x9034C2BF5D171714ULL, 0xB61827E0BE3E79F4ULL, 0xB92262E272E93285ULL, 0x4420BB3F54429933ULL, 
            0x551D23E106779D67ULL, 0x972BC5CE4E926D78ULL, 0x6443363B84D27D94ULL, 0xB6447643F27FC6D4ULL, 
            0x633D08BAA8D92164ULL, 0x0CFEB09A7275E0A0ULL, 0x0CB56C98BB6C9474ULL, 0x5EDC52A7953D3B85ULL, 
            0xA8949F6C598C36C4ULL, 0xE44CD943A6477600ULL, 0x3D4CA53A0A0B96E4ULL, 0xAFD1BD6F95E2E2E3ULL, 
            0x4BCA9757AC2A4A65ULL, 0xD28E7C99780AE462ULL, 0x776FECEA230F1475ULL, 0xB98A4863C1D660E0ULL, 
            0xBA3D68ACED7A37DBULL, 0x6C5F5AEDE1D68C0EULL, 0xAC51D1D6EF7E98EFULL, 0xBC1BBB00741261D8ULL, 
            0x116CE1CE89A5EE2AULL, 0xD41ABA66EA7941CCULL, 0x3642D709A11802CCULL, 0xBDB59349E716D489ULL
        },
        {
            0xF2674B8E80956FA0ULL, 0x2C99FA220CBFE0E3ULL, 0x95836A2C6A38AC45ULL, 0x51D1EB9B7B3E9A7BULL, 
            0xE6E83F7FDE4C3D8DULL, 0xC04CE6B0A3F010F0ULL, 0x2069F49798C21B26ULL, 0x4ECFD1B167421EC0ULL, 
            0x8B45215E19BEFDEBULL, 0x3BEF9E6333E037F5ULL, 0x75480073EE83C152ULL, 0x07740E1BFB02947CULL, 
            0x0C4B8D69E59C984EULL, 0x2A5B2501F88B8CB2ULL, 0xFE83237B76C97BE2ULL, 0x5620863377C82B59ULL, 
            0x13DBAAFF5865E062ULL, 0x83B28AFAE7989C4BULL, 0x4BE319212B7C62C8ULL, 0xFB1B1974AC0E0309ULL, 
            0x5ABA379D844572C3ULL, 0x55BC2B0AEAF0C674ULL, 0xD96A279044B6C733ULL, 0x56FBD631EE3CE95AULL, 
            0x7D0C3FEEA63BECE8ULL, 0x315CE00C4F68AD1DULL, 0x8E7A0EF77179B1E5ULL, 0xF03AFC6758378513ULL, 
            0x7ACC42F4EBBB7BB4ULL, 0x0EE0230E0192DE74ULL, 0x6CD16259656D742DULL, 0x63149E0EA4D1D7D2ULL
        },
        {
            0xB41DBC648EB7404EULL, 0x0463D8A507D31EFFULL, 0x418C077A51123DE9ULL, 0x2173DFB69B906BDBULL, 
            0x7309501509421AF5ULL, 0x4DA0B9662F042CB1ULL, 0x1067A3C9EA23E9E8ULL, 0xF301693AC7D6C30AULL, 
            0xF8EF45098ECECDFCULL, 0xB783122528059E39ULL, 0x99CEBEB645DEA6AAULL, 0x0B680AA5AB6404A5ULL, 
            0x53511C5AB0F7108CULL, 0x4E5B9E56311A0A6AULL, 0xD14DC920D9A93EA3ULL, 0x11FCAEFE3D50E6A8ULL, 
            0x229C04CE0398A3BBULL, 0x8FAC450A07E218A9ULL, 0xFDD952857C81A42AULL, 0xFF1CAF536BC308E7ULL, 
            0x5612273A56EFA979ULL, 0x18EDB0AA64A4F9B7ULL, 0x0B98D7CB420679CCULL, 0x5BD3F31F55204FF3ULL, 
            0x7E1DB4D48403AB02ULL, 0xF01D5C3B0FDB7CC2ULL, 0x0478FB885A8CFBA9ULL, 0x2708DD15E358F649ULL, 
            0xBEBCF9F12A90184FULL, 0x1CCDF0F84715249CULL, 0x414ADA133BB63D5DULL, 0xAB8DD2DBE459441FULL
        },
        {
            0x767C66633928E56FULL, 0x156AF05FFA25586BULL, 0xE2486F9BD46CBDC3ULL, 0x2154E2447B90B154ULL, 
            0xB095982B7649A4DBULL, 0x1DBC370DB829F018ULL, 0x1F67D7497A59820DULL, 0x3E36F0962CB59E3DULL, 
            0x8B2F64AE7D6BCF3BULL, 0x424156A90483D225ULL, 0xA8C0CF0B62FD2DDAULL, 0xE790BE8D3CC58C49ULL, 
            0x702C58A65107CAF1ULL, 0x827FD9B57F39911DULL, 0xA5791D1772EBC00BULL, 0xE08789CC376ABCA3ULL, 
            0x90677223CF31A606ULL, 0x8FE3F936FCB17F47ULL, 0xD6C8EC5403BCB632ULL, 0xF3E33379B429C7CEULL, 
            0x0DD329EE02656377ULL, 0xE11C2726DBB27607ULL, 0x1B052FED852935DBULL, 0xA6889FEF8D286B39ULL, 
            0xE3565DC77DB18D3FULL, 0xD6B4E18709EF5AC7ULL, 0xB8387D760FDB1BBEULL, 0xD83307AE1168EFA1ULL, 
            0x00E135A9474DA62BULL, 0x31FAC3E366BE58CFULL, 0x3542136DFFF9D2D3ULL, 0x44812D6003CD4F84ULL
        },
        {
            0x155A37618E90B8DAULL, 0x6094C9904BEE4820ULL, 0x256848930C3AD08DULL, 0xA84AEB4716AE3048ULL, 
            0x5E7F7F4C5B5407D5ULL, 0x7D387D1EA4984885ULL, 0x93475F831C457F7AULL, 0x928B05A088409195ULL, 
            0x9042DB7C66B28378ULL, 0xEA2EA72E158E4E82ULL, 0xC36120C51BF295F8ULL, 0x43433DA11689B308ULL, 
            0xFD1050BF178918B8ULL, 0x204E6E2E8B7D8036ULL, 0x6675DD451C949E0FULL, 0xE1A4A7441953227CULL, 
            0x7FBD4E77F28597AEULL, 0x3572A23505F986D6ULL, 0xFAA7EF83F5136243ULL, 0x221A2A7B66145EFDULL, 
            0x0AD67822294F3056ULL, 0xECFA073220FC5C08ULL, 0x15B6DA4AF553D497ULL, 0x008CD0282A3391C9ULL, 
            0x5D66AD30B0B52AD2ULL, 0xF723E633B674661FULL, 0xE4E3A6018289B781ULL, 0x492BA705550FEE76ULL, 
            0x342F9164003D8488ULL, 0x5807423E7CD6AE30ULL, 0x0ED664151D4453BCULL, 0x41E3B2FC35D1BA47ULL
        },
        {
            0xA3BDA7A8FE2A3962ULL, 0xA3845C545B93E15DULL, 0x5F39B5555EBFE4BCULL, 0xEB1D7DD608D34A27ULL, 
            0x35494ABBC94A0C3CULL, 0x00AB5AE3BF2E8B46ULL, 0x7DD7108EDCE9829AULL, 0xD370422C81FD6AD0ULL, 
            0x9A2B292F7BD25816ULL, 0xCB6903E2BBCA606DULL, 0xC0F46FD2E969B58FULL, 0x54E4581CF03038BCULL, 
            0x3344C573EEA8159FULL, 0xABCA893F4F2FA4B0ULL, 0xFAA44AF305184F3DULL, 0xEA60FF36D9994AFFULL, 
            0x3AD5C3D924A71EC2ULL, 0xEC3BACAA38F51B20ULL, 0xFFF97DA9BB3D6F85ULL, 0x22092484A560990CULL, 
            0xA78BF06BA814A43BULL, 0x384C332B35A6F6A4ULL, 0x8A18FC48F0A53C28ULL, 0xC6EC61F491435BEDULL, 
            0xEB4C46AD324F5EA4ULL, 0x83E3498AD2DC17B0ULL, 0xA8B904987D83C918ULL, 0x633E486F8333A15BULL, 
            0x8C413984793CF290ULL, 0x47902D9B481E6ED1ULL, 0x54D5EA9D2A4B1162ULL, 0xDFE7290581ECF7FCULL
        }
    },
    {
        {
            0xF8554DA3F06E0C3EULL, 0x235AE0CD970A0BF5ULL, 0xC682038F1D92686EULL, 0xFB0B77766BFFACE1ULL, 
            0x02D7AA78AD9AFF51ULL, 0xD790B70072C686BFULL, 0x804A23D2AB0817B1ULL, 0x5FE769113A3ACD99ULL, 
            0x64C189B13B4AF6AAULL, 0xA22EEB24FCA6E61FULL, 0xA147AAC5E0F250EFULL, 0x5B16C3DCB12E9FA8ULL, 
            0xBAA3DC7D7AFB2DABULL, 0x8C188B9A3CE5F487ULL, 0x65BFF947980131E0ULL, 0x0E565415BB00C44FULL, 
            0x7B88B9BDBFD05384ULL, 0x61FD12FBEBF032E4ULL, 0x3E7A7379CF36AB39ULL, 0x5581F46B8E9D507DULL, 
            0xE197FBB06ED91B9AULL, 0x856139D9897DF526ULL, 0xED71838126D02CFAULL, 0x7692676076697D25ULL, 
            0xBF3A1CF918D99463ULL, 0x06A14C8BA542AB1FULL, 0x1B76501529003936ULL, 0x22B3D602B004AEC2ULL, 
            0xC6D917C31F401D0AULL, 0x0E06A8A7CD93D24FULL, 0x2BA1518E6B98977FULL, 0xCBAC9446C9EF3C7EULL
        },
        {
            0x5C6AA767F9FD2059ULL, 0xC04736A9AF0E2D4BULL, 0xCF1909AC1B4AC36FULL, 0xCB4FB535AAC39C15ULL, 
            0x6866AA9187AD7544ULL, 0x98DE8F58B89115F6ULL, 0xE2FB94239EA65976ULL, 0xA5E81BC873A26432ULL, 
            0x89EEF0FA5975F461ULL, 0x28D4B3216545C854ULL, 0x21D326B2FC21E00CULL, 0x48AC989F15CF4FE6ULL, 
            0xDC90927E299FE3F4ULL, 0x99F023B2AA96904CULL, 0x7124075F2053A6FFULL, 0x216E931F83A8978AULL, 
            0x0F346E60F5283B7BULL, 0x5EE8A5FAD547406CULL, 0xC602F1688DFC2E16ULL, 0xD8F3EC3D2E0574E3ULL, 
            0xA4E2A18522BDF169ULL, 0xDBDBB7B116B71486ULL, 0x5461866233A6439AULL, 0xA7DC36D09C6FD2ADULL, 
            0x585D28A92A443F09ULL, 0xB67584D8189F3A44ULL, 0x228817DBED1BEAA4ULL, 0xE935FABC2062AE1FULL, 
            0x82EE50C6F1EAE364ULL, 0xEBFA926A5A2ED534ULL, 0x97E6BA5F4DEB5C3BULL, 0x028C1F3316366D73ULL
        },
        {
            0xAF941D1E9E0BACB0ULL, 0x433C0C5AF3330561ULL, 0x2D9127702F86522FULL, 0xC4BADED92C184981ULL, 
            0xCD22526D5D3CB244ULL, 0x04674F2EC2614721ULL, 0x28BB220BFBD67FF3ULL, 0x7CB98778A2651684ULL, 
            0x90A35B3454481491ULL, 0xAEE5A9A93512F8A9ULL, 0x54517BB48C262910ULL, 0x3381A2E0C264EACFULL, 
            0xD4EC7D27767EDA77ULL, 0x2B0A8CDA83516FC7ULL, 0x17D62064C439A4A0ULL, 0x0190D3572948E219ULL, 
            0x0D89D95B361DEBEEULL, 0x3FBC1CBD4430C782ULL, 0xDA92B33A3C20C30BULL, 0x489A2135A453EFE7ULL, 
            0xC7F45C23AA4F22DBULL, 0x09C0AE1D5FB73B92ULL, 0xFD03F92541EFDC26ULL, 0x133A53509E5E3B3EULL, 
            0xA0F58CD6B1B785DCULL, 0xC7E930035A62ECBDULL, 0x6037069C351F41D3ULL, 0x0939A4CD611D2A01ULL, 
            0x204CDAC0C36E450EULL, 0x71281866FFBDA8A8ULL, 0x748D85FB57086125ULL, 0x54492FA38188C438ULL
        },
        {
            0xE9BA1B6D62FCF21FULL, 0x50B84A5F8874CCF0ULL, 0x7318FFB3E15F7FD6ULL, 0xCD45C418B51EFB13ULL, 
            0x0021FC9BBC07549BULL, 0x6728EFDF6876E750ULL, 0x978D192384A7B5B8ULL, 0x8D187634C7B56B2AULL, 
            0xBD6E231755A09EE0ULL, 0x31F61C227D68428FULL, 0xE4791A011F32AA68ULL, 0xCADA0D0006B291D3ULL, 
            0x2BCA859A39470864ULL, 0xBFF84F357BA361C8ULL, 0x4CDDE6801CD39852ULL, 0x225E264007B56D8FULL, 
            0x83C1332ED54C6CB5ULL, 0x26B2C7AAAB7EC35DULL, 0x355D4D3044396CD8ULL, 0x0ABEEED786821357ULL, 
            0xA8619C18466F6DB4ULL, 0x63EBB6EAE14089B8ULL, 0x73D8961A735AD9F6ULL, 0x785700B9C24F00C3ULL, 
            0xBBBA8C31C77AABD4ULL, 0x426F8CA45D37FBBEULL, 0x4D99B655DEF61FF1ULL, 0x883D70B2970A26D9ULL, 
            0x6BCE130295BB1C89ULL, 0xA7A926C99EC1BC03ULL, 0x533487FB7938B95DULL, 0x5EE00320BC3C19E9ULL
        },
        {
            0x90E8D1426DA5AA02ULL, 0x72CF12B8A6009654ULL, 0x28D11C78694357C7ULL, 0x803254E97BAF4E29ULL, 
            0x832C44573DD580A4ULL, 0x6F623F9CF8946A8FULL, 0x9413B8932A77B6FAULL, 0xD99096A6C4856FBFULL, 
            0x705283D285651F98ULL, 0xD648A39A58ED2F84ULL, 0x47BC0DF67F3BDA6CULL, 0x5F6D8D09A4385999ULL, 
            0xE072894C9DBDB399ULL, 0x223C6E5BAB7A77C6ULL, 0x593B45C444153FF7ULL, 0x9B55666EB5C51C6EULL, 
            0x8B7A283E5C22CF17ULL, 0xD8C80877908C7BC4ULL, 0x00EF6DB19F74CD7EULL, 0x6113074322F3FAE7ULL, 
            0xA7AFB5CC2373565CULL, 0x2D518060A55B93F7ULL, 0x6FDAE1CFD7EF50FFULL, 0x3C740C7EC9E568E3ULL, 
            0xB766404389995D9AULL, 0x10683F9610DBB443ULL, 0x92859C3D50E7C3AAULL, 0x2A2BF79E3DF862F7ULL, 
            0x587FC5C6BAC8260AULL, 0x52CF955A55215491ULL, 0x07F3D6D10FF0C8DCULL, 0xDECCF7001847B432ULL
        },
        {
            0x8EC47C8CE664D227ULL, 0xB57BA8D4F92B55F4ULL, 0xDE8608899EC14A04ULL, 0x5D6444E5B254C45CULL, 
            0x1F0F83EB3BBFAAFAULL, 0x215BE8506A442136ULL, 0x188F70E558C81A2AULL, 0x868E3C513E98F01EULL, 
            0x747391DD9E056D91ULL, 0xDF509001DF6D5593ULL, 0xC9D64AE67AF71C2FULL, 0xED5361C4D783E294ULL, 
            0x8A03321EA52805A3ULL, 0xCE71B14CE33492C9ULL, 0x608F13C51777BB04ULL, 0xE7DEA7F7E47FEF7FULL, 
            0x95E2F33F796D37B4ULL, 0x998CEBC4D0BE4B76ULL, 0x0422A296004CA136ULL, 0x8F1893F8088A986CULL, 
            0x7FA362A0587D05E9ULL, 0x7B3E5860B6CB8C35ULL, 0xF40449A733FB9253ULL, 0xD9D4B72A1F768E6EULL, 
            0x49C038909E6A8182ULL, 0xD5E49DB37DDAF2D9ULL, 0x84CADA2A3E4DD355ULL, 0xC0FEC01EB83F84CDULL, 
            0x58C75063C72E0C4EULL, 0x45287F2D349DCB4FULL, 0x0CEF9B34E1FE10E9ULL, 0x8DA2944736411311ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kSeedConstants = {
    0x91972B8E1A65D29FULL,
    0xFD13F6148D23AB5FULL,
    0x9021966F148B78AEULL,
    0x91972B8E1A65D29FULL,
    0xFD13F6148D23AB5FULL,
    0x9021966F148B78AEULL,
    0x479DBAD5B4CD16ACULL,
    0xA1A44952CC2FA5F7ULL,
    0x1B,
    0x0D,
    0x68,
    0x3D,
    0x2C,
    0xC4,
    0x2C,
    0x93
};

const TwistDomainSaltSet TwistExpander_Antares::kTwistSalts = {
    {
        {
            0x8F894B1D679DC441ULL, 0x4E6D6A3FA97046E8ULL, 0x045017CC9AAB86CFULL, 0xFC448BEA96466D71ULL, 
            0x6D8683070823F7A9ULL, 0xE3EABF606B48FC5BULL, 0xFF1E1E39291CB36EULL, 0x5A1EEB4677098C8EULL, 
            0x2DB5222974969D26ULL, 0x4EB043BD5255407BULL, 0x1C2FB9397832C86CULL, 0x4578A785CE3DAF52ULL, 
            0xBC4C5B29FE37BAD3ULL, 0xAB0C67F8D5DE33F1ULL, 0x1D8952726B2F8178ULL, 0x72BA3500C0234D2EULL, 
            0x99C941CC64E2FD32ULL, 0x41E1955E8484F653ULL, 0x6401BCB3C1A65FC5ULL, 0xD10C4BC6F68DC5FAULL, 
            0x97464ADAC0310AA7ULL, 0x7853CDE2406F4F5AULL, 0x02FFBFA9D86792FEULL, 0x283204735E4B06E1ULL, 
            0x46CD68AA5F794F1BULL, 0xC2B57E1AE8D67BF5ULL, 0xB4FB172BF4D17016ULL, 0x9D0C71F5836D793EULL, 
            0x6A100B8488E12956ULL, 0x4A156264D62A59E7ULL, 0xD4B2B4FBF0DA3A3BULL, 0xC3167236B5665F38ULL
        },
        {
            0x8A9B9706BCFDA2C3ULL, 0xD4F628CD40F362BFULL, 0x0FA8E3757D15E4A3ULL, 0x83B1A995C0C1DE09ULL, 
            0xCFF43EF253E2B358ULL, 0xF8AC728326C8E61CULL, 0x689A7409B78B564BULL, 0x2BA7C3DB57D92B19ULL, 
            0xE098FAFD9ADDDA79ULL, 0x0B8C2A5B843FD9BCULL, 0xE08B58BD48D7139FULL, 0x8DF6B4403B658E62ULL, 
            0x4CF2DD544CF40CD2ULL, 0x45EB661C31FFCB87ULL, 0x9A7D9B25A67BAD0BULL, 0x335671C8CD584362ULL, 
            0xB254AB2414E80F3EULL, 0xC08FD0D22A8B00CAULL, 0x47B445E0D2E09BF6ULL, 0xC2DABEA6921A5102ULL, 
            0xF63AACB0D1383C1EULL, 0x62EAFEE375F350FFULL, 0x0111C5F319B92962ULL, 0xC635A0A7A2E04612ULL, 
            0xFD35938DB409771BULL, 0x0CDCB2D66345959AULL, 0x8155525003AC501DULL, 0xC754B188CA8C8B57ULL, 
            0x0CAD02A0DFCA227DULL, 0x9FC3D4BC5A842218ULL, 0xF2AD8882023F8438ULL, 0x03E397F56B5D8918ULL
        },
        {
            0x067BC0CD4454C945ULL, 0x5F934F6CCF28948EULL, 0x5187013F1968EB6DULL, 0xD2603EF35E5C3589ULL, 
            0x11018B7A7F374AA4ULL, 0xF10F363BB94E3F14ULL, 0x99690B2CD3B569C5ULL, 0xDA28313C7A6492D0ULL, 
            0x71A23ED2984648C6ULL, 0x2368CF97FACF05F3ULL, 0xA39BD3E550C561F8ULL, 0x066D3B89CE8FDD43ULL, 
            0x0D29CD39B78DA6E7ULL, 0x04BB7992CF5CDA6BULL, 0x7B1664514DB05796ULL, 0x8A0198531951D3EAULL, 
            0xE2FCAFB7B564866BULL, 0x3274FD109E97C516ULL, 0x28926C901AC62DDBULL, 0xDBC6D1876D327EC9ULL, 
            0x026F255111F2814DULL, 0x38A8675078658A9CULL, 0x1EBCB2B861653281ULL, 0xD1CE9977073F6544ULL, 
            0xDE791A23AEEC79BCULL, 0xC5D2D38629BDBDBAULL, 0xE2AA04E12E6F0B6BULL, 0x156752DC785A4449ULL, 
            0xF8B3EADCC552A9CDULL, 0x1E65DB8D18CA0685ULL, 0x699AEC66EC70711EULL, 0xF5495BEDCE39DCFCULL
        },
        {
            0x2406D54CE8DB85F3ULL, 0x095771610437A364ULL, 0xECF707FFDB249EC1ULL, 0x39477D0288A67107ULL, 
            0xA166E99B74DA2B74ULL, 0x9A38808F65079467ULL, 0x079FE880334368E8ULL, 0x118456266BEC51DFULL, 
            0x49A5CD95B5AB3862ULL, 0xE9C37BCA470D053FULL, 0xBC14228322C6A8C6ULL, 0x8D08856247789924ULL, 
            0xD8B954AECF2D5F2AULL, 0x002410FCC4C6294AULL, 0x294E9174B2369612ULL, 0x380A7C8E33D0E0F3ULL, 
            0x3C1EC7B18EFBFA41ULL, 0xB7619FB1B9A058FBULL, 0x807025CF766A830EULL, 0x7DB4BC8140BD890DULL, 
            0x2EA5FD761BB5091EULL, 0xCEC6B9FA66A6EC92ULL, 0xB91F3E6C156F0F59ULL, 0x0D63467609E3F282ULL, 
            0x40DE3806388364DEULL, 0x65A364939AC7A6F6ULL, 0x4072E5FFEDEB5975ULL, 0xBBB7CD2717FFBB4FULL, 
            0x5970CFDC62C0C17EULL, 0x1CF4F77046C9DAACULL, 0xECDFDCCE3C0074E0ULL, 0x82124EBE5EB405F8ULL
        },
        {
            0x2422D8338EFB015AULL, 0x82B34E3912F3A866ULL, 0x244BFB7AD8B241B2ULL, 0x7610DCD7EA5A3A46ULL, 
            0x51C4A505D91F45A3ULL, 0x35A1A15197E5DFB7ULL, 0x2434EC91F4D9019AULL, 0xD2747D1FEB8408EBULL, 
            0x9993F9855114578BULL, 0x1CCF2443B2CDB8F5ULL, 0xA73F69A61A74E357ULL, 0x69CA0554F186FCAAULL, 
            0x3CE88ADBC4A18732ULL, 0x0E5C7DE565F5B989ULL, 0x581CA8370ADFF85EULL, 0x63DAE764778E87DDULL, 
            0xBCD3402580C1D408ULL, 0x08178A4C61FDE905ULL, 0x6520B5DAC9605A96ULL, 0xD2AB196A34093448ULL, 
            0xB71E6567A9D96231ULL, 0xDFEA79C9186AC491ULL, 0xD9CEF2BB29E0DC9DULL, 0x0B2E9371A005FFC9ULL, 
            0xF14E48E1B9A5438DULL, 0x991AAEA2DB6227F3ULL, 0xB25F0959022F9771ULL, 0xB98FB51149187336ULL, 
            0x0BAAAA6FF436F2F9ULL, 0x3C97F5A83CD8547EULL, 0xF741B03214BE4981ULL, 0x4CBEB24CAF5EE7FAULL
        },
        {
            0x829D78202C1CBB99ULL, 0xF656F031E13CE214ULL, 0xC96C31BDE0B3139EULL, 0x8199DA8F7CCBD54AULL, 
            0xF9951E1F041FFA84ULL, 0x0205A93A918E0650ULL, 0xB710013E67409FF9ULL, 0xD2873BD42C5ECE52ULL, 
            0x8D14E6B1F87F267AULL, 0xE599D59A1254FE58ULL, 0x4C38C8F98936A20FULL, 0x747C18235DC2913DULL, 
            0x9F0B0DCF7668E45BULL, 0x335615807A576D14ULL, 0x74BE95D274BB7E05ULL, 0x1966D6186723F66AULL, 
            0x3E58D716BCADE301ULL, 0xF7159A6D17E8D066ULL, 0xD45068B57E385A38ULL, 0x3C3D243AAE943223ULL, 
            0xF1CB5F49799B36C2ULL, 0xE720481E5A7AD622ULL, 0xAF6FE20F378B4B15ULL, 0x48D3068560175F7DULL, 
            0xECBF93FB2CFE0158ULL, 0xD28BC7219A329C25ULL, 0x4ED83F6C2650C49FULL, 0x160B05067CCD6C10ULL, 
            0x4A5E17B412C801E8ULL, 0xC31BA36A67AEFC16ULL, 0xC67CCDD963D24A7DULL, 0x9227E50665E1D9C7ULL
        }
    },
    {
        {
            0x3BB902313748DD55ULL, 0xDCD7B799F1D8F48DULL, 0x8300DF65432C21B4ULL, 0x062619802725A0A8ULL, 
            0x5078CF835DFA8333ULL, 0xBC5ABC7D81DDCCE6ULL, 0x88C0201EB5B7B7D3ULL, 0xF9A93769D599BFABULL, 
            0x3F48ED85CB3F9B02ULL, 0xBC7038CED18A384FULL, 0xB50E093985305708ULL, 0x000265AD3926A0B5ULL, 
            0xFD8CAF03F64AF0C1ULL, 0xF62BD450B62C6AEBULL, 0x65A710973CBEE650ULL, 0xEA38E4B41C0AE580ULL, 
            0xBFB3033029BEF0D2ULL, 0x4920020B157DDE81ULL, 0xF45C767F46052F4EULL, 0xAA762E5BBA872B28ULL, 
            0x6CD182C781212389ULL, 0xAD2DB7C9BC9012EBULL, 0x92BBB2DA732122E1ULL, 0xEC62CC4BDFF133A7ULL, 
            0x5AD5C2827E059633ULL, 0x01504A713794E291ULL, 0xD46A7E33AB580064ULL, 0x369983A18466CFBBULL, 
            0xE7344468E358190FULL, 0x3F1C4DBD5F811296ULL, 0x18C59878C1C7D3A4ULL, 0x47DD4DD2B136FBA3ULL
        },
        {
            0x47E6B5AD0BD77CA3ULL, 0x970BEE0847F8ED4CULL, 0xB32F5016D8A0482CULL, 0x35E7CB9F3167BB79ULL, 
            0x453359735B3A9E27ULL, 0x5B565C1B8884092EULL, 0x79CA73092334D722ULL, 0xA882237DF909B9EBULL, 
            0xCF38F82143A343E6ULL, 0xC1E20EB5ACD51D3DULL, 0x4C88C19A8618F5EBULL, 0xEE7F70FF23D874DCULL, 
            0xF86C74FC635E7B64ULL, 0xB1B009F03E712BCBULL, 0xFAA571E7CF51B687ULL, 0x3936D8C9C6CDA270ULL, 
            0xF2D12612A0DC0444ULL, 0xD41FA7167E8584C1ULL, 0xEAA25665EC0F0DADULL, 0x6FF864FC775F0A9DULL, 
            0xD3E46AFBFE1A552CULL, 0xCDF025504AE795DBULL, 0x9FD09631EEEA7003ULL, 0xC8F8E94ED485C2EDULL, 
            0xBF3DEBA503B702D8ULL, 0xCE5C91EE0B9D9BCCULL, 0xAA6EB7CE48B0CABEULL, 0xE0CFBA314C83AACBULL, 
            0xB3495DB668329932ULL, 0x8F0CBB8BFDB48AF3ULL, 0x92CFFF468AE20B22ULL, 0xCC75258A2E5DA587ULL
        },
        {
            0xE4843DCA88E1AF0EULL, 0xE35E3FD24D25ACC8ULL, 0xC986FBC8EEAE8C9FULL, 0x96905F529C72DE95ULL, 
            0x7F86411862598036ULL, 0x09F233B8E64669BAULL, 0xCEF5593B78578451ULL, 0xC5E4D3E1712539F8ULL, 
            0xE68E89776BA2A2C7ULL, 0x59453CBEE3DEDE6DULL, 0x484D4E9BDBCC5F32ULL, 0x584BD9705D88FEBAULL, 
            0x387084DBC3F46629ULL, 0x15B16EF4CE6F040AULL, 0x2A7C0EE7251D517AULL, 0x0CBC3B42BB911C6DULL, 
            0x0EB5A18FEF6B6512ULL, 0x44DDDF7B7FB3B92DULL, 0x6AF82EC6899F06CBULL, 0x537719E67E43D264ULL, 
            0x020729258FF10C00ULL, 0xF8720FE50E792F94ULL, 0xBA3CE875925271F5ULL, 0x7AC0525824FDF41EULL, 
            0x7E500FB2961E5D0CULL, 0x18BEA9C95F23B699ULL, 0xE9EC25CBFCA3B51BULL, 0xDAF073292ED56781ULL, 
            0xCD05E0627A713447ULL, 0x1F024439BFF2D33DULL, 0x7DF9F5FC8F18B1EBULL, 0x246D33B6B56D9529ULL
        },
        {
            0x62ACD0F4CCF98855ULL, 0x3D8246F73073708AULL, 0x9E908D06F022BA1EULL, 0x504AEDFA4A31EE69ULL, 
            0xC5D886EE9C390F21ULL, 0xFE23D74EB538150AULL, 0x0C31FA81FC90142FULL, 0x73B4C1CD0A44D264ULL, 
            0x115AA15028CE72D2ULL, 0xD34AC1899077D96AULL, 0xE9849343E7F82D4DULL, 0x1F68B2DBEF302EE4ULL, 
            0x1F3DA4B3DC98C92DULL, 0xC40F1663BEC698DEULL, 0x5911406C9BB13F51ULL, 0xFEB1267D4AD23EB2ULL, 
            0x764C916A7616694FULL, 0x2581829CFD86AD1EULL, 0x97FAE8EBF7B92F5AULL, 0x6D35C27DEC468ACFULL, 
            0xB6F0C57D8E3CA7DAULL, 0x01BB33FAAC22B0C8ULL, 0x053EA787AB2DC897ULL, 0xECD36BC73AE4A00BULL, 
            0xD369CE5FEFF2D248ULL, 0x3863B324A6B5974EULL, 0x6918BA4A6832CC46ULL, 0x4C4F0A9AB44432EDULL, 
            0xD9CAE1BBF8CF61C9ULL, 0x4E845E2B204FE8AEULL, 0xA1544D1EA71DC084ULL, 0xFAE01BD0FEF5416DULL
        },
        {
            0xD0B98464CC44CCDBULL, 0xC456B86A3B2532A8ULL, 0xA547442C23082B81ULL, 0x22240D4B6058B5A2ULL, 
            0x83EF0615DF11D272ULL, 0x22C7881B89366EAFULL, 0xD55B14ACF5AA840EULL, 0x1148D2868D33A970ULL, 
            0x123467775BEF35DCULL, 0xA2B6B01A7A81A15CULL, 0x10C5BED814AC829AULL, 0xE0E8FDE368440AC7ULL, 
            0xE2B347D351F7ECE8ULL, 0x33BEA264B4B989B1ULL, 0xC650190B5901FC26ULL, 0x7C6B1448AF10B4D1ULL, 
            0x34FF8649A9E93F6AULL, 0x9B291D224F887C66ULL, 0x3F00C2CE7E623CAFULL, 0x6A4224A8A6BAF60CULL, 
            0x2E241E65C3ECA457ULL, 0x19D0B647008ED16BULL, 0xB040422C370C80F4ULL, 0x38646CEB11D74826ULL, 
            0xB3EEF092C69E9D3EULL, 0x16E98869A94BDA4BULL, 0x021B67DBF46C75C7ULL, 0xD4E3BCFAE15929B8ULL, 
            0xB279EFCE3C1B54D7ULL, 0xFFC430B6341A3282ULL, 0x2303435B9B7ECD84ULL, 0xD71056E025614BDCULL
        },
        {
            0x7DD78FF55C1486A0ULL, 0xBBB1C288B407FA49ULL, 0x80EF474BE414154CULL, 0xD22F32315DC17C1FULL, 
            0x1A3ACC95B70AFC28ULL, 0x6B700615F6E99437ULL, 0xA7B4BD883C46B05DULL, 0xE58658FDDADF5F75ULL, 
            0xF17248974BD166FDULL, 0xC9F6932AA1093BCAULL, 0xCDFEB657D137D210ULL, 0xBF0536E81C71A01AULL, 
            0x7B90BD0BB8DED38BULL, 0xF115DB4CEE41CA3CULL, 0x9E03055D250F2864ULL, 0xB775EEAF084DC65CULL, 
            0x0050DA964B6FDD62ULL, 0xE4237D08D9F7B2C6ULL, 0xE58D002218303999ULL, 0x03F60DA375846858ULL, 
            0xBF15BA501FF7EC02ULL, 0x02CCEC6F156434E5ULL, 0x2C04979AE0D67B07ULL, 0xEFE7E7205F28A9F1ULL, 
            0x9EFE8D580B8D4091ULL, 0xAB3785BF014EDEB4ULL, 0xC21A299AB27EB309ULL, 0x965BC25E15C9CD9AULL, 
            0x02AAD288CC7DFC2DULL, 0x9C16CEE68849E0D9ULL, 0x446187465E842B0CULL, 0x5BD8F9BDE7D093BCULL
        }
    },
    {
        {
            0x51AE1071AD4244C6ULL, 0xE56EAF9CD24592A4ULL, 0x03DC584C6C1D4378ULL, 0xD31D917F0668307CULL, 
            0x894FCE79FFE286BBULL, 0x7452B8D574A1EE94ULL, 0x4D4DE3552A6E74E6ULL, 0x707EA6AF8BB63C3FULL, 
            0x49B619CB2B94E806ULL, 0x3CDF5D35887CF71CULL, 0x6214907C1B276DF6ULL, 0xF9C518C6B07A2CD0ULL, 
            0x2C4CCE975D9BA8CFULL, 0x22290AC345370FF6ULL, 0x619F500C2E0992D0ULL, 0xCA5E71FDF7784D0DULL, 
            0xCBA7AF2F20F536EBULL, 0xFEAA1654B2D89805ULL, 0x1824CAE319EF386CULL, 0x54B589450A25429CULL, 
            0xCE9D33D12B544D2AULL, 0x8B0057FB4EB82D22ULL, 0xD850FC4D0B97B520ULL, 0x22F9F9E32527DE4CULL, 
            0xA3C089731BE78BB0ULL, 0x21AE06D9F8600E56ULL, 0x047A99696F0E8598ULL, 0x4A4B3AE940D31DC3ULL, 
            0x26BC329E44D1CBB9ULL, 0xDD80754183728D73ULL, 0xB429151132B21DA9ULL, 0x7E93793FDA73F191ULL
        },
        {
            0x9C20CBE8830CB119ULL, 0xA4EED1A639633483ULL, 0x6E1D74E7E47B8252ULL, 0x97A47007097D7AD0ULL, 
            0xC3F43C297450F4B9ULL, 0xCC2B572D50727A3CULL, 0x4213E12F8C4D97DEULL, 0x7D764CEA0FF266D9ULL, 
            0xCF24D428328AE686ULL, 0x06019813B68461B8ULL, 0x51B13A5827E2AD46ULL, 0x2749C4625A05259CULL, 
            0x7FD5B836185E7002ULL, 0x927DE2D18CD6D44FULL, 0x43D4E5D3AF1059D0ULL, 0x64DE1C2CC985D57CULL, 
            0xF44B29295BB1CFFCULL, 0xCD35335CE698F5FFULL, 0x6696F95D5D4DF9FFULL, 0x0CECA4D0EA082380ULL, 
            0x8BC315CBAFA30886ULL, 0x47F4CA95A4FD59A2ULL, 0xCF418B66BBD1711CULL, 0xD2212E84E2A5476CULL, 
            0x7EDFEDAED097B9DBULL, 0xCCF7DB7C1424C34EULL, 0x84A423A7D7AA8806ULL, 0x8141D1E180791B98ULL, 
            0x98C3653AFF8EBFB0ULL, 0x610AD60583E00F59ULL, 0x5C718204BD847473ULL, 0x9EDBBC663FC9427CULL
        },
        {
            0x9EBAE59F0F14384CULL, 0xC1E6F4DB7699CF70ULL, 0x0BEF8BA5DBFC2487ULL, 0x502130250E52BC83ULL, 
            0x091839A1E35148F5ULL, 0x7FADE51BD47228AEULL, 0xB8AC28AA91533E6FULL, 0x4A1BBCA4EDFF3648ULL, 
            0xA36B02D7D8F988C4ULL, 0xA6710A9A8B81D372ULL, 0x3C8BAA0A6E9B1E22ULL, 0x7C6198233FCEF458ULL, 
            0x4350E77CAB183856ULL, 0x8C14A547559B9AFFULL, 0x4E060800949988F3ULL, 0x73AA5E31F3DF6196ULL, 
            0xE09E62BA5CFE9842ULL, 0xD67A5BA9D6EF3BA4ULL, 0x57D331CF491D1EF7ULL, 0x79C10FCC18981730ULL, 
            0x86A81756F5B29E74ULL, 0x865D4F0118B0F955ULL, 0xE9D87EE9655EF546ULL, 0x814D5F23D848010EULL, 
            0x22E7CE4A7CD408AFULL, 0xC53F987BC95EA67BULL, 0xA154D55B4469DD35ULL, 0x5AE31088DAF63DBCULL, 
            0x208297D693192177ULL, 0x9305B3283F0BBD17ULL, 0x06D4A900C6B39A2BULL, 0x47433F199E3814DDULL
        },
        {
            0xBF5BB142D680938DULL, 0xF1E411BA8CA73AF8ULL, 0xDFCFCAEBCD6E9982ULL, 0x21153D588B6F528EULL, 
            0xA75319DF62D75733ULL, 0x766F44655DB93E45ULL, 0x2494A9D734907D7EULL, 0x5AFC0464D6B42AF1ULL, 
            0x02EC395580DE950DULL, 0xC9491B8637CC28F6ULL, 0xF48BFC5EA921BD57ULL, 0x836EC64E24F45C98ULL, 
            0x03395C6B524625E4ULL, 0x0549452E05341252ULL, 0x4E8E8AE87067BF72ULL, 0xBF79D7847E3DB598ULL, 
            0xA4E6D4C2DA70B5D5ULL, 0x1917824E3FBA4CD5ULL, 0x5F8AD0C1464758ECULL, 0xDEE79C5BDB5019BAULL, 
            0x2D9865C9C2FB1492ULL, 0xC9776F0C8CFCBD7AULL, 0xE4FD86EA7C00D665ULL, 0xEDC932A1819BAC31ULL, 
            0x019E2A0A02D1B5FEULL, 0xC2B34DB22FE293F2ULL, 0xF0175DA23BFA75D2ULL, 0x4AB7F58F94EC0E6DULL, 
            0xFEC68675794D8C7AULL, 0x07FF49F320AF209FULL, 0xA7387F4E8E6D6C42ULL, 0x5DD8B5DF0451F688ULL
        },
        {
            0x2BC1E164A7E3565CULL, 0x34E63F344856CB10ULL, 0xA1498E74D99309D9ULL, 0x11FF1C28BD2EDA46ULL, 
            0x869E8F908618A6D1ULL, 0x0AC713592DBBAF44ULL, 0x46301EB61118AF81ULL, 0x4BEFDAE7E909B1E5ULL, 
            0x16AF651EF0AF705FULL, 0xC3794BDBC1042A93ULL, 0x42632EAAB956EF49ULL, 0xD5B212D2C78ECBB0ULL, 
            0x22F03711792D284EULL, 0xC3B1EC3270C60238ULL, 0x682E98D788FBB466ULL, 0x766E024BC13EFBB0ULL, 
            0x593A8F8DB3703C80ULL, 0xF60A70B6DE9C2DFEULL, 0x05E2C57FB6A51DD9ULL, 0xCC924043A6C5D248ULL, 
            0xFCDBFE1DA57929EBULL, 0x26BAB5C080BC30CCULL, 0x48F270FA27AEF914ULL, 0x61F1036144380300ULL, 
            0xADB287B0FB165941ULL, 0x1304C8A5093BBCB0ULL, 0x864875743E5951E9ULL, 0xBBE7D0FB40B75D39ULL, 
            0x0657723C3B444838ULL, 0xA69677E656B6AAE6ULL, 0x6F67CA8EBFE75652ULL, 0x12721FD5D54C86C7ULL
        },
        {
            0xB8BB108916ED8CD8ULL, 0xFEF3468B561D0A86ULL, 0x2535A2324E1F3161ULL, 0xB8D5F0069F4388E5ULL, 
            0xBCE4D1432A482295ULL, 0x986B1EE38A3FB301ULL, 0x5A1A9BFB450C634BULL, 0xB09B44629D9AEC83ULL, 
            0xFCDB01EFB5AC2749ULL, 0x524E305C544E5C6DULL, 0x4AA230BA24E9E74DULL, 0x02AE474DEB98B2DCULL, 
            0xA893ECCA16DD9667ULL, 0xD02DA491F9A9AA27ULL, 0xAC4A7B2FE8627EB4ULL, 0x7B98ED62A6893B0DULL, 
            0xC4B27F30FD780D66ULL, 0x6E62481AA5DF0034ULL, 0xEF9E7B3465735AC9ULL, 0x07A1D40A0BB05E92ULL, 
            0x602D0655BD0E2AD8ULL, 0x11DF61B3EE750587ULL, 0x00D74BDE177FAF8FULL, 0x30796E7CBF8BD447ULL, 
            0x411875ADB54BFF4EULL, 0xF1C8154007C1E9ADULL, 0xCF160F1684F41CECULL, 0x4F2D1566BF1BA825ULL, 
            0xE84A5E041E8B9FC4ULL, 0x5FBFE9F8E3595DF7ULL, 0x615B5CEADDDB54F9ULL, 0x288351714E523D09ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kTwistConstants = {
    0x03F3B726C707F61FULL,
    0x9F6CC60677D07DD3ULL,
    0xB3273E5C0E4F7C92ULL,
    0x03F3B726C707F61FULL,
    0x9F6CC60677D07DD3ULL,
    0xB3273E5C0E4F7C92ULL,
    0x4D208E26F870379AULL,
    0x1591B6FBE4F07D33ULL,
    0xA1,
    0x87,
    0x93,
    0x69,
    0xAF,
    0x5F,
    0x30,
    0x57
};

