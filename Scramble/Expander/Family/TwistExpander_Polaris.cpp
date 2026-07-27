#include "TwistExpander_Polaris.hpp"
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

TwistExpander_Polaris::TwistExpander_Polaris()
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

void TwistExpander_Polaris::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFEC05AAF7A6E649BULL; std::uint64_t aIngress = 0xD860FEBB4F394D85ULL; std::uint64_t aCarry = 0xACC60C5D6FE26A2BULL;

    std::uint64_t aWandererA = 0xAC0E43CF7D50C651ULL; std::uint64_t aWandererB = 0xA2A1C03A6D346D29ULL; std::uint64_t aWandererC = 0xCE05E7F3B06A9D55ULL; std::uint64_t aWandererD = 0xF8635A1545FF04DAULL;
    std::uint64_t aWandererE = 0xD3D2B2DF9785BA33ULL; std::uint64_t aWandererF = 0xE4E59486C7078913ULL; std::uint64_t aWandererG = 0xEA4DADFDD16DD70BULL; std::uint64_t aWandererH = 0xF6CD60BA4AD2D446ULL;
    std::uint64_t aWandererI = 0x93A21719E85E9148ULL; std::uint64_t aWandererJ = 0x8D83FD9E6A3CD943ULL; std::uint64_t aWandererK = 0x81F020AC1EA9C974ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE63D9EC7D948349FULL;
        aCarry = 0xC2974D81910FB042ULL;
        aWandererA = 0xF713B2E4D93F83AFULL;
        aWandererB = 0xF8D8AF92B1F8372EULL;
        aWandererC = 0xE4C5B8D2584BDEF5ULL;
        aWandererD = 0xFF206C1756D22AEBULL;
        aWandererE = 0xDDD6E984D3E803CEULL;
        aWandererF = 0xEDDD28E01D5DB332ULL;
        aWandererG = 0xBE92653F47277784ULL;
        aWandererH = 0x80C3496B30A69615ULL;
        aWandererI = 0x8F70FE4AA51302DDULL;
        aWandererJ = 0xE8E9637AB182DA64ULL;
        aWandererK = 0xB2401D723769EF9CULL;
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
    std::uint64_t aPrevious = 0xB049FA2B3BF72DA9ULL; std::uint64_t aIngress = 0xA8CED65B435175BDULL; std::uint64_t aCarry = 0xE2D99C5B4E6D4B29ULL;

    std::uint64_t aWandererA = 0xB17731CC439BFF36ULL; std::uint64_t aWandererB = 0xBEB4D526A12D7C62ULL; std::uint64_t aWandererC = 0xB0314C4F2FCF03A5ULL; std::uint64_t aWandererD = 0xB8B7236207B733C8ULL;
    std::uint64_t aWandererE = 0xDF179A981E42B05AULL; std::uint64_t aWandererF = 0xDA3BBDA9FA5FBB7DULL; std::uint64_t aWandererG = 0xF3A86E1299462BCBULL; std::uint64_t aWandererH = 0x90F6888D069E3BB8ULL;
    std::uint64_t aWandererI = 0x8467DCA27F99B7E9ULL; std::uint64_t aWandererJ = 0xE88034DD7624E37DULL; std::uint64_t aWandererK = 0xFB4D2A2B4722937BULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFAA0A5051E00129CULL;
        aCarry = 0x9CF1D1EF7614F974ULL;
        aWandererA = 0xD9804B09F1EF3837ULL;
        aWandererB = 0xC0C37958F302D1C8ULL;
        aWandererC = 0xD20A28F85D7A56BBULL;
        aWandererD = 0xA6A0E7A7FE8FEE1CULL;
        aWandererE = 0xC7CC9402517EC987ULL;
        aWandererF = 0xD968281D5F31D5A9ULL;
        aWandererG = 0xF587921FC26A6F73ULL;
        aWandererH = 0x8431DB9DF5DDCD62ULL;
        aWandererI = 0xC1C56D274A1BAAF8ULL;
        aWandererJ = 0xE9924F410EE36D3BULL;
        aWandererK = 0xCCE64C20BA384173ULL;
    TwistExpander_Polaris_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE58D8C053AAB7C32ULL; std::uint64_t aIngress = 0xD3E0C5CC3EC70014ULL; std::uint64_t aCarry = 0x8F7C3BEEC5B77B4DULL;

    std::uint64_t aWandererA = 0x9F705E89D734486BULL; std::uint64_t aWandererB = 0xD42911A1D7D16CD8ULL; std::uint64_t aWandererC = 0xB7E4861029765EC1ULL; std::uint64_t aWandererD = 0xEAB44B5C74341CB7ULL;
    std::uint64_t aWandererE = 0x8E577F6141F9CCF7ULL; std::uint64_t aWandererF = 0x8376EC116F420137ULL; std::uint64_t aWandererG = 0xA8CB0407DCFD7D4BULL; std::uint64_t aWandererH = 0xA9386FE69F7FCE76ULL;
    std::uint64_t aWandererI = 0xE812F4C55A281252ULL; std::uint64_t aWandererJ = 0xB81E7D8CD3405990ULL; std::uint64_t aWandererK = 0xFBD1128191986A60ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDA53D0BEE7B86811ULL;
        aCarry = 0xBD01B9D949751BC3ULL;
        aWandererA = 0xCC2C1BFDCEEB72BBULL;
        aWandererB = 0xE0537D7907D4190CULL;
        aWandererC = 0x86AC40D81A8950A8ULL;
        aWandererD = 0xD6045557ADEB4D5EULL;
        aWandererE = 0xB7EC025019175EE6ULL;
        aWandererF = 0xA1D04867FB4BF332ULL;
        aWandererG = 0xAB95A0180AB28A66ULL;
        aWandererH = 0x9517DA075C93366DULL;
        aWandererI = 0x897055E332296563ULL;
        aWandererJ = 0xB1988558A7FB0335ULL;
        aWandererK = 0x926E4EE32599E03CULL;
    TwistExpander_Polaris_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB3FF65718E729516ULL; std::uint64_t aIngress = 0xBC75AB9E642B7126ULL; std::uint64_t aCarry = 0xEB6F27F9FA3823EAULL;

    std::uint64_t aWandererA = 0xF2CF592F9EED4B55ULL; std::uint64_t aWandererB = 0x9C030EC0D208D820ULL; std::uint64_t aWandererC = 0xF67BE1F286014D5DULL; std::uint64_t aWandererD = 0xDC49CCEEB52B07AFULL;
    std::uint64_t aWandererE = 0xADD318642DEA5B1FULL; std::uint64_t aWandererF = 0x8378F81059F47BA9ULL; std::uint64_t aWandererG = 0xE765725800CEDEB5ULL; std::uint64_t aWandererH = 0xC0C62F904D74B950ULL;
    std::uint64_t aWandererI = 0xA5862A1191D826F5ULL; std::uint64_t aWandererJ = 0xFFD0E9F866D2DFC8ULL; std::uint64_t aWandererK = 0xE940BB5CF06C5551ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC7778BBFA6A5CE0FULL;
        aCarry = 0xBBCDB119D9E99A11ULL;
        aWandererA = 0xF3ABA7E3F1B87B98ULL;
        aWandererB = 0x82EFEC3DBCED172FULL;
        aWandererC = 0xE3E769C49B4C1AFDULL;
        aWandererD = 0xB00B73405E91C8BBULL;
        aWandererE = 0x9AAB4150297D3806ULL;
        aWandererF = 0xA78052ADB56F64E7ULL;
        aWandererG = 0xEFD1ABAB10DEE29AULL;
        aWandererH = 0xA3B8B3F843B69F8BULL;
        aWandererI = 0xA77E86EB886ABA7AULL;
        aWandererJ = 0x9A5E771D2A41AA84ULL;
        aWandererK = 0xD9039D42BB72DCE3ULL;
    TwistExpander_Polaris_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_D_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0x846CFEF6AF2A8BB8ULL;
    std::uint64_t aIngress = 0xBB3F165FB4970A33ULL;
    std::uint64_t aCarry = 0xA9A631BFCC63C30AULL;

    std::uint64_t aWandererA = 0xA3FC221DB439B5D9ULL;
    std::uint64_t aWandererB = 0x8C93D2AA66ECAF98ULL;
    std::uint64_t aWandererC = 0xBACD663F8AE37DF1ULL;
    std::uint64_t aWandererD = 0x97D02745644BC86EULL;
    std::uint64_t aWandererE = 0xF3E1FB3CE5DEFC4AULL;
    std::uint64_t aWandererF = 0xCABFD4A460C8FD40ULL;
    std::uint64_t aWandererG = 0xC49ABF1888929A9DULL;
    std::uint64_t aWandererH = 0xD5F6DD07798EDFFCULL;
    std::uint64_t aWandererI = 0xE748296FB00B961BULL;
    std::uint64_t aWandererJ = 0xF677065A97A623D1ULL;
    std::uint64_t aWandererK = 0xDB4344188809C3DEULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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

    TwistExpander_Polaris_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Polaris_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Polaris_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KEY(pWorkSpace,
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

void TwistExpander_Polaris::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF388BDB682F55B3DULL; std::uint64_t aIngress = 0xDA50E25FF5BA8000ULL; std::uint64_t aCarry = 0xF453FC1DB7A08CDAULL;

    std::uint64_t aWandererA = 0xA98E730F5ABD129FULL; std::uint64_t aWandererB = 0xA3AB3FDF2F4F1A62ULL; std::uint64_t aWandererC = 0xD71EFEDDD14E42D4ULL; std::uint64_t aWandererD = 0xB47196C12479EC8EULL;
    std::uint64_t aWandererE = 0xA2AAAE2664C08971ULL; std::uint64_t aWandererF = 0xE9EC210335E5C29EULL; std::uint64_t aWandererG = 0xA73821E9F5806842ULL; std::uint64_t aWandererH = 0xBD14C7D56392A61CULL;
    std::uint64_t aWandererI = 0xAC3469392EAFD06AULL; std::uint64_t aWandererJ = 0x93F0E7CA03282DD8ULL; std::uint64_t aWandererK = 0x89EB77536ED261F3ULL;

    // [twist]
        aPrevious = 0x8F0DC4B90A0EA1A6ULL;
        aCarry = 0xC81EA7F1D5AA482BULL;
        aWandererA = 0xD421460D103941D1ULL;
        aWandererB = 0xE856FF299A3B35D6ULL;
        aWandererC = 0xB1B567998852C72AULL;
        aWandererD = 0x82DA4D66FB75D091ULL;
        aWandererE = 0xE4ED3F33AD8D2CD1ULL;
        aWandererF = 0xBAD2770459A11DB1ULL;
        aWandererG = 0xE9A739EBB4B45825ULL;
        aWandererH = 0xE4982FF4BFA0BF69ULL;
        aWandererI = 0xB7F35453D259704CULL;
        aWandererJ = 0xEFB211D9744E0A1DULL;
        aWandererK = 0xDCC5278D47AA9399ULL;
    TwistExpander_Polaris_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Polaris_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Polaris_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Polaris::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Polaris::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Polaris::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 24 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 12294
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1735U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 24 of 33
    // Exploration cases: 0
    // Structural maximin 509 / 674; family total 12253
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 24 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1049 / 1248; total 24696
void TwistExpander_Polaris::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
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
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 24 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1051 / 1248; total 24828
void TwistExpander_Polaris::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Polaris::kKeyRotateSalts = {
    {
        {
            0x38579678B32D480BULL, 0x01646F7630DCA369ULL, 0x5BD8AB39A4336CF4ULL, 0x7EC7ED5908200B85ULL, 
            0xB365DE5C6403E416ULL, 0x00E6390BACCD2E2CULL, 0x9AF3654080121C35ULL, 0x07A4624755EA60A8ULL, 
            0x42CBE14784E8A919ULL, 0xA049F292E8B93D0AULL, 0xA67D3C865DAEC6E1ULL, 0x86CD8B72E960E1E1ULL, 
            0x6B4B696C929CFB23ULL, 0x66B3A0C8F30A74AAULL, 0xAE4D419F842AF041ULL, 0xB0A782BB82B509F3ULL, 
            0xFE7BEC7CBA13483CULL, 0x9A47A1C5358F6103ULL, 0xAF81B16EE56E8594ULL, 0x5D5A3682925E13BEULL, 
            0x7AB92C3A1544E433ULL, 0x49EA7693F60B08BFULL, 0xB60BBDB253381730ULL, 0xC656689F3971FA6DULL, 
            0xB243110038E057E6ULL, 0x9EBB41EE8EA59DAAULL, 0xD60AB7E2D890AD44ULL, 0x05FFE26E79540440ULL, 
            0x523C7AF86E6C8110ULL, 0x8BB68BBFAAE351B2ULL, 0xFC0680BA7CFAAD03ULL, 0x367D7FE57668CA97ULL
        },
        {
            0x8CA96C3BF1F3551DULL, 0x51666BE481A36A7FULL, 0x7367429F88770896ULL, 0x3CC622A17433E271ULL, 
            0xE45AD599254930B9ULL, 0xCD0CEA60598138A5ULL, 0x88263E64D91D1318ULL, 0x0E2B1EE895D6AB12ULL, 
            0x26EADA0E410DAB9BULL, 0xA3AE3E9685176CA6ULL, 0xD87805F45F63103CULL, 0x7DC3C2E43262C99DULL, 
            0xCEA4F0A741FE51F8ULL, 0x657F2E5B19491047ULL, 0x1A96A76D6DBE90BEULL, 0x9F460774AD7D97D5ULL, 
            0xDEEB5F69B1A3DF52ULL, 0x15D86A1E42C2FE7AULL, 0x3AF393B6164030BBULL, 0x2CD7B985B783BB56ULL, 
            0x7DC63E2A25AB5151ULL, 0xFC39083325901D4FULL, 0xCA1DDBD05781D501ULL, 0x77DDC10600FCA1CEULL, 
            0x8353D166558A28E3ULL, 0xDC4B19EC447E3CF0ULL, 0xBA5B04022534C124ULL, 0x1DC4374BB9AB5BFDULL, 
            0xA9DBBC8786D40535ULL, 0xBC9CECD10A79FD17ULL, 0x2A263557783D1453ULL, 0xD988947A9BC2B86EULL
        },
        {
            0xCFFF07277169B15BULL, 0xB87718C8266652C1ULL, 0x9A1CAA8ED4A172A9ULL, 0x399E9AFD158042A6ULL, 
            0xA405D666678EF4F1ULL, 0x76EB8D5CB88C7220ULL, 0x37F13E3EF210766EULL, 0x810E56A4FE2A212EULL, 
            0x5BEC652F7FF1E7A8ULL, 0x33DE6DA5002DEA85ULL, 0x6EFFD4C2B41796A2ULL, 0x91B02B3568F42963ULL, 
            0xF2766242F5778E7AULL, 0x26EE875E79DAA2B4ULL, 0x4BFAB45DF43B6AF7ULL, 0x890CCE4A0DA6B8D2ULL, 
            0x2410FDADE74B3178ULL, 0xD46E992CB83AF11CULL, 0xB85DED22D9C2553CULL, 0x3176258F8D8D4339ULL, 
            0x8C329716D55A340DULL, 0x5665F50017D93766ULL, 0x3A7B5680A7E2BD26ULL, 0x392651494E432BA3ULL, 
            0x82982E1AE77FEC4BULL, 0x345F970770C2E664ULL, 0xD41457C95B57527BULL, 0x41C79B1109ECBB92ULL, 
            0xF4F004255F4C638AULL, 0x6FCFDC302F13EDB8ULL, 0xEB64CA30CC20E6DCULL, 0x7E616E46FE6B752AULL
        },
        {
            0x60A0C756FF818CB3ULL, 0xAE30219E721B5B20ULL, 0x33FB0CB24BB083ADULL, 0xEEEB4DA2B451AC73ULL, 
            0x1E5F5D56FDA6EA57ULL, 0x1D8D40A2A52DD7E8ULL, 0xAE81065E96377D7EULL, 0xD530910D66475190ULL, 
            0x2482EE2E2C2E65B6ULL, 0xD2D114421A1BA05EULL, 0x9E01DCFBCA32A6E5ULL, 0xE5B7BDED3D840335ULL, 
            0xC6C27D2B8DFA7F2AULL, 0xF652957243CBA50AULL, 0xCCD3C2B303AF8C73ULL, 0xBE324E270CB801B8ULL, 
            0xA039FF4C55616BAFULL, 0x320299DFFFB9A212ULL, 0x1AF67AEF1809C2DDULL, 0xCDBE9B5F7A2914F5ULL, 
            0x39A9AFF7BE27EC9EULL, 0x0584C5BED3FC1D6BULL, 0x675C6091E497D4F3ULL, 0xFF8EBF8D6CBACB2FULL, 
            0x1F5973A72073A895ULL, 0x1091B1200953BC9BULL, 0x255304888031112EULL, 0xD6C90BAF5455D426ULL, 
            0x63B36DADB27B38A1ULL, 0xBEFB8C256BDB6AABULL, 0xA0A7004145BD0822ULL, 0x367B3C0F9D96C291ULL
        },
        {
            0x2E42CAFDACFFB701ULL, 0x70DB23169F186591ULL, 0x6D653DA01E5A6537ULL, 0x7AC282B95F5D8740ULL, 
            0xA30223C89F8A6B89ULL, 0xFE3C4AE6343F3E39ULL, 0x7780F7E2257D94C8ULL, 0xD0CA5F2D4D1B57EEULL, 
            0x1BAE2F4E5286A6CCULL, 0xE4017B8FD549EEDAULL, 0x6B0F17DABF2348C6ULL, 0x301C63D35DA12842ULL, 
            0x68F38A08C2939972ULL, 0x7CB35848315A2A9DULL, 0xA2C580C680649D27ULL, 0xD7A4F3508FF84BA0ULL, 
            0x32C2096D0991E70EULL, 0xC00CA5344E5D1E29ULL, 0xD8F67FC6997DA3C9ULL, 0x2BAD2CF421340F5EULL, 
            0xDAF47092E6DB9311ULL, 0x79DECBE258EF29CDULL, 0xADA846B34183A245ULL, 0x4F3EDBBDD5E1009FULL, 
            0x144EA985B7BF3B97ULL, 0x3118A74725B0DD22ULL, 0x72A087918A5E53DAULL, 0x2933E3712EC75221ULL, 
            0xCDFF009FB9963E6DULL, 0x8E1D0E99AE0A471BULL, 0xC342E6E5E2BE5CF4ULL, 0xDAAAA6AE991C4FF0ULL
        },
        {
            0x9017C4188B56D7C0ULL, 0x3C798AA6B2923A41ULL, 0x96CF4D5B0D5BA989ULL, 0x7464B4904C1BC8F9ULL, 
            0xBB712A0AEF099737ULL, 0x646791CD1F16A57DULL, 0x86C947E0699B3F51ULL, 0x4CB16B74050AAC78ULL, 
            0xFDDE5D5402F4DA8BULL, 0x84ED7E796D4C36E1ULL, 0xEFF8FFFEBE88B8D9ULL, 0x2BDF6E6014C808C0ULL, 
            0x0E6A6DC8BCB0427FULL, 0x8F711F2C207F722CULL, 0x0C7D950DFA7F9B26ULL, 0xB6F1D491C539ADA7ULL, 
            0xAC0A924F21C35E3DULL, 0xDC0224146A573E75ULL, 0xFF0A858F7E1E844DULL, 0x7409D3C5D959D1C3ULL, 
            0x6E46CB8C427C28B7ULL, 0x1BA4CABBBD24D599ULL, 0x627C19055610D059ULL, 0x0F861DD7E17CF8ACULL, 
            0xC72951D02C2884F7ULL, 0xA4210AC3FAF300E8ULL, 0x75124469C18F8D3EULL, 0xD6F35FA7D3378507ULL, 
            0xB8EB5CA827CAF54FULL, 0xCC8BB757A715CA90ULL, 0x5133B703E3257EFBULL, 0x063DA35BEE4FF6CBULL
        }
    },
    {
        {
            0x65155BEA971A3DE3ULL, 0x0775C1AD80C7F35BULL, 0xB47A366994FFD8BEULL, 0xEC7F18B79568ED94ULL, 
            0xB0C19E774F8DAD8BULL, 0x4D11792F9943DA55ULL, 0xC9C9E777523FD0D5ULL, 0xEB5E138A80F8A9F1ULL, 
            0x5666A62E2091B343ULL, 0xAD62F0A7077D2AD6ULL, 0x37DF7751F95C1A65ULL, 0xF407A3103DA14888ULL, 
            0x68AB70AE6E74120FULL, 0xE3AE16DAC996DBACULL, 0x32BFE86E3386C40CULL, 0xBD6AF76F0584E0BCULL, 
            0x276E34A4E9ABE818ULL, 0x5C71A2C7FDF71A12ULL, 0x853676F63ACBCD63ULL, 0x4A18045EEB62507CULL, 
            0xC3BA7025AFC3BD65ULL, 0x581DF02D93680A47ULL, 0xAA1F03855592943BULL, 0xE1602C386CD993BDULL, 
            0x9D55C6DDEF5E4B5BULL, 0x7044555F582AEE16ULL, 0xB7E1E3223D791FAAULL, 0x187D3DC4EBA49515ULL, 
            0x6488F613D1292217ULL, 0x6A5D89B99B7E2FC2ULL, 0x343184360FD0A35AULL, 0x0AAD65AC7F85374BULL
        },
        {
            0x0AFCC393A27C4B59ULL, 0x1D3107F22D7B4590ULL, 0x53D65AA3474266F6ULL, 0x2A23E146C3035DA3ULL, 
            0xAD18DA710BC41585ULL, 0x8D0931FCC2BC7595ULL, 0x43CCE7467E4AE071ULL, 0x869FA75261D271DCULL, 
            0x9036FDC0CFB70853ULL, 0x6F4BEF2F3A6180D0ULL, 0xB549ECE84D98A9FEULL, 0x47DCE08067BF178FULL, 
            0x42AD3BA519180C4FULL, 0x54389564ABAC4FB7ULL, 0xDF391E73391D7DB2ULL, 0x94FAD28584C30DE1ULL, 
            0x51F0B8EC16160F0EULL, 0xAE1A326B6F73A95DULL, 0xEF2F8C44C9BF7C3DULL, 0x209BA7F174986C96ULL, 
            0xCC455556D5B9A9ECULL, 0x46DBF03E32AF227EULL, 0xA9CA591BE1AB0C89ULL, 0x749F61335578E976ULL, 
            0x1649EF4F1DA5B259ULL, 0xA81C7CEDCD089AA5ULL, 0x1DC856BA37576967ULL, 0x3142988106FF094CULL, 
            0x556CE62B1E4B4ACFULL, 0x0A9F6E87B6D329D7ULL, 0x16B2C873556C04F8ULL, 0x875B014EAFB1B51CULL
        },
        {
            0xDF8291DC4FED05B7ULL, 0x948B1FE18A9FB5CAULL, 0xB8EA5416F97DD6C4ULL, 0x58124503D5105383ULL, 
            0x998375203472E34AULL, 0xE01D3ED8FD4A9368ULL, 0xC5EC20D146BDE2E6ULL, 0xA6DC0323EF2F0BE8ULL, 
            0x3E805F1E8E49FEE7ULL, 0x0EC46DE9E8EE0C79ULL, 0xBC0C22A3816ACF5CULL, 0x4809CC200B81F5B4ULL, 
            0x21448389D0411750ULL, 0x91A1FB0679B7E063ULL, 0x2A94381E503B7C65ULL, 0xEAEC41F2DCCDB828ULL, 
            0x338753D1076BFCA8ULL, 0x19A6DE9028E4A60DULL, 0xDB7EC6BFCA42F1AFULL, 0x1762115A8A029B02ULL, 
            0x3647B0D7571C5C2FULL, 0x3EB984AA296CB8EDULL, 0x456B6AB7F9515FA3ULL, 0xEA068A28D5DC0570ULL, 
            0x059237EE743DDF32ULL, 0xA43B5F58381C66FDULL, 0x124C6D875F3749F9ULL, 0xF9E3AB048936488EULL, 
            0x9F7F63403E072C78ULL, 0xC9EF7D3057A8380DULL, 0x7E146ACEA330E215ULL, 0xBDF5E8F80409A177ULL
        },
        {
            0x0174B8EE61A823C1ULL, 0x1747D5A4EC6D0028ULL, 0xE3506BF019CD6CFFULL, 0xE95F70E6B343E10EULL, 
            0x34BC5772328C7960ULL, 0x3D4D84BF89F7A73FULL, 0x96C6B2B766BB1651ULL, 0x3E68B56B2C3F42EDULL, 
            0x0715DE39CE673976ULL, 0xDE3CF0E3DDA8B854ULL, 0x0CED9948FF2CFAA1ULL, 0x712B1C7B97EA8754ULL, 
            0x3CC553037DEFA772ULL, 0x95C7C7258D1032ACULL, 0x45F13A123C1CAB8BULL, 0x65B19DB18F61693DULL, 
            0xDD4615DF17354D67ULL, 0x1112DFEEB0FF88A2ULL, 0x09B09B45D3E4EC44ULL, 0xBD6CF398B25ECF5DULL, 
            0x54698E9B56D394E7ULL, 0x50AF026ACE6B7488ULL, 0xFB29CF2D47255588ULL, 0xDB7B5A28510924C5ULL, 
            0xB5534E470D82E10EULL, 0x4431AC83BE845451ULL, 0x31CB1AB7ADD782E7ULL, 0x9EF21D028D58CCEDULL, 
            0x57FE8FD9C3A658B2ULL, 0x85F30A2BB0C85710ULL, 0x46FF09F2DA5B8928ULL, 0x51C42D8653EAAC59ULL
        },
        {
            0xF1CB51CF16C3D33FULL, 0x9AA7FDB228DCFF3FULL, 0xDCEE24CC1C5262C9ULL, 0xAD12579EBC751C4CULL, 
            0x41E09D6BBDFE3521ULL, 0xE2CA9C70B53D83F1ULL, 0x1202C79E32155017ULL, 0x0CA479B2747DC160ULL, 
            0xB18DB5C3EFF8C119ULL, 0xF9478A45DB4E9D17ULL, 0x68B5B5BFF91CF109ULL, 0x193EFF4D38BC7DD4ULL, 
            0x301E7328C20B725EULL, 0x75C7D38AE8F95984ULL, 0x570CB55E740670EAULL, 0x98863E3658731318ULL, 
            0x84AAE2D73ABAD58FULL, 0x1867FE0E1B2B4286ULL, 0x9BDEE141E380F02EULL, 0x41F462DCDA857AFBULL, 
            0xC4DC7EBD6E802F63ULL, 0x609C1A610F2507BBULL, 0x569FB83F9EA7D559ULL, 0xFA86703763475E70ULL, 
            0x515B96C3BEA6CDE4ULL, 0x67DB0CB34E3E121BULL, 0xE20D6DDD9F07C92EULL, 0x6EB173FCE9AE7ACBULL, 
            0x674A1851104D48B8ULL, 0x36B2D9F0FC56FFDCULL, 0x3E6C8828F1E27E18ULL, 0x09F1536110A13F9BULL
        },
        {
            0xE36F1E143334640FULL, 0xB4DA63CBD03F8389ULL, 0x0885B650D913416DULL, 0xEB1561EEC4A1E064ULL, 
            0xE2657DB1C71AC0E7ULL, 0x2553B4D00AF936D2ULL, 0x17D704928E707686ULL, 0xCEEA42B6F0616F35ULL, 
            0xC43BEFAB3C58DA34ULL, 0xBF4B34A5C5234091ULL, 0xC339EB499E392F2DULL, 0xFC563E034A5E71A2ULL, 
            0xC1FDF5F6C0765A25ULL, 0xD8D4116A0DE9D66CULL, 0xCED0A44E1E16FC78ULL, 0x3269BBFC50759FE6ULL, 
            0xB4F8A6B97D022C41ULL, 0xAC0B1128682E4FF8ULL, 0x3A63006638016A21ULL, 0xED4069147DB2A7E1ULL, 
            0x584DE6C7631F27A3ULL, 0x3D65CC82003461D5ULL, 0x4C00FB6E7402F4ADULL, 0x2DC21909D983D188ULL, 
            0xF2481A46945008D6ULL, 0x4DCF00FF3DF81398ULL, 0x58D43156D8F5D25BULL, 0xDC49F2949A58AACBULL, 
            0x1A520EBAEA66F75DULL, 0x23ECFE722897E136ULL, 0xE7968631FEC2EF98ULL, 0x8B4C6018C5400CD0ULL
        }
    },
    {
        {
            0x56CF65C1CE864F6FULL, 0x38CFBCCF2BC13076ULL, 0x94CF777E16AFD3CBULL, 0x0C4C5558EFCB1A23ULL, 
            0xDCE32358144462EEULL, 0x55300F5E66FC9584ULL, 0x0AD1CA88C5AD7E9EULL, 0x0D25E27F725AC2BFULL, 
            0x81E3F7FF161E4CF6ULL, 0x4BF8982D53EA173FULL, 0xCB0C4AB02FC3E550ULL, 0x482A26D894F9F391ULL, 
            0x7F5473A9389A89CFULL, 0x3FE83718463922B4ULL, 0xB15C7BD510E6DEE6ULL, 0xF90F87386B530E97ULL, 
            0x7BD93D0B277486F7ULL, 0x92C125ABA69F415DULL, 0x01297A1F0A4571B5ULL, 0x7B33843ED0EF2DFAULL, 
            0x6C47B0AE6C70A089ULL, 0xB52F72B8E5F6ECD2ULL, 0xC397ACFEBA7B264AULL, 0x809419A6B69713EAULL, 
            0x31959E0DD30338EBULL, 0x4E0BAF79BB8D9F05ULL, 0x5F3DDD167406A3A9ULL, 0x37AA5FD67629D5FCULL, 
            0x09CC5844F0EB9F19ULL, 0x8A28F3A42CEF964DULL, 0xDB9A2B58E7812736ULL, 0x6DCBA3F39DEE2BCAULL
        },
        {
            0xA3DF2AEA71DCA1F3ULL, 0xB6560B52F049F05DULL, 0xE1091B91D8B9B8D7ULL, 0xB2FD44F09ADFE2A4ULL, 
            0xBE5A9D440794169EULL, 0x2132F1C843F64201ULL, 0xF2493040DEF2B450ULL, 0xA06D2247D77BD257ULL, 
            0xF4A3CECEFD4BA035ULL, 0x0CC813755BEB1D60ULL, 0xBB1C26333E35BEA5ULL, 0xD06BAE31AFCB447AULL, 
            0xB456DAFC8122D232ULL, 0xB3B77C915845EE36ULL, 0x7DD4DCB51FEBBDDEULL, 0x7C44F4EEBC633FE7ULL, 
            0xC9A8F9F2C590C380ULL, 0x635E53A9F13D8B70ULL, 0x50A4FB87B64468C4ULL, 0x28960C7FB2AA3F70ULL, 
            0x6EA1ABFA2C1DD252ULL, 0xE60734C9025BAF68ULL, 0xEBCECDD4B0459297ULL, 0xFFEFB92E715B56B9ULL, 
            0x1432E1A8BAE51027ULL, 0xBA505A83D645EB19ULL, 0x4718D12BB1DB45E9ULL, 0x660DA859A03F3F58ULL, 
            0x5CD162F8D437750FULL, 0x505BBD781E1BD71EULL, 0xF058A086D1DA1309ULL, 0xC8C92140427848C5ULL
        },
        {
            0xFC67BDEAD09F6A75ULL, 0x8291CBE5143B0F1CULL, 0x472771B61E01548FULL, 0x527A8B671FABFDE4ULL, 
            0xD3F6D906A51C1EB8ULL, 0x5B92ECC3DF6BD177ULL, 0x4B26132106300AE9ULL, 0x1723CD97DB0E1CB9ULL, 
            0x95752074633D09ACULL, 0xBBCF36B5D92A3F14ULL, 0xC4F22E39AFF2B736ULL, 0x9C1B4B816678A5B2ULL, 
            0x028840996C2BD260ULL, 0xB69DC044B149C7C2ULL, 0xD0E337E684F463B9ULL, 0xE947B77EC3BFCE48ULL, 
            0x67E1F00FFB282D75ULL, 0x23E3EE581BD1FF04ULL, 0xC2C7C5FEFE161BEEULL, 0xB8951275BCD8FAC4ULL, 
            0x90C27FB8F54C8DA0ULL, 0x108635B2764548C2ULL, 0xCE5570DBF65DB4E2ULL, 0x9B3E1E99A0AE5B70ULL, 
            0xF79EFF352ADB41C9ULL, 0x5DA9F9784F63E473ULL, 0xE8B320582262E7D5ULL, 0x7EA0D2EE06BA700EULL, 
            0xF532CFA322C47C86ULL, 0xBAF6710306C4A258ULL, 0x15D407A70B4100A2ULL, 0x1AA9D41EA2FA8FE6ULL
        },
        {
            0x7EED4A24ACA07AA5ULL, 0xF91D722394F5544DULL, 0x4FCF24D3CD46BECAULL, 0xEB9AEEE31EBD88DDULL, 
            0x63AD310625C90AB2ULL, 0x23FEFD10A263B1FEULL, 0xA2D3B259321826B4ULL, 0xFA505B5693544F7EULL, 
            0xB2FF9AF241223AACULL, 0x9704DBBBC2B6398DULL, 0x9389661A029FE9A6ULL, 0x629A03CF5EECA64AULL, 
            0x0EECB16EFA532D9CULL, 0x2DB5266076DE81CAULL, 0x4E176C8124E91B5FULL, 0x71231EFCBED46C2BULL, 
            0x160D051B1FC63757ULL, 0x721F51AE4FDB0D5BULL, 0xD3F0F9FAD89010DCULL, 0x62DC0894476AD6FCULL, 
            0x4F4192756E1E5871ULL, 0x11C9C12AF8D3F65AULL, 0x5EAAB098C0DEB13FULL, 0x5802B5D8F4940C5FULL, 
            0xE07E106125B6F346ULL, 0x67D570DDBDCEADCAULL, 0xB5DE0FF5DD45186AULL, 0x5734B4402C9E3544ULL, 
            0x73844913659D62F0ULL, 0xF04221AF32AB8ADEULL, 0xEF6F9AEF1ABCA565ULL, 0xD6774C6A848A59EFULL
        },
        {
            0x89DB01BFE580C08CULL, 0x41936A2EBDD3858BULL, 0xBD02BCD2CD189D5DULL, 0x868913872853A36EULL, 
            0xAA79B96EBBA86A3DULL, 0x400696B9FCBB47F0ULL, 0xF63DB3397C76643BULL, 0x64EE205C0364C51AULL, 
            0x886A3C47C26CE2C0ULL, 0xDE8AF485F90B9295ULL, 0x1D129B8B1A768E65ULL, 0x2FDD4C10C2FA2F02ULL, 
            0x09ABC642BE813BB3ULL, 0x92FB3C1EDE348E92ULL, 0xF67539F353FDF367ULL, 0x0CAF38B044082268ULL, 
            0x3C4E338F56548EB5ULL, 0x36022723E89378E3ULL, 0x24EF20015DCA3A30ULL, 0x2ED866A02DF5A19BULL, 
            0x898314D427C0A29CULL, 0xC2E053263D200996ULL, 0x886BB7A7E74D7909ULL, 0x476AA07E687DBD92ULL, 
            0x839BA23924F2C8E4ULL, 0x2DF89B056FD6E8FFULL, 0x35BEF6218AE2BBACULL, 0xB9602EEBB78C8E2BULL, 
            0xC2AE5DBD67C7393DULL, 0x63F5E172129F2086ULL, 0x796036EA01907986ULL, 0x8B5830F49279C557ULL
        },
        {
            0x0A40693F69FB6853ULL, 0x88535F476A121C53ULL, 0x3A41AA24AED88411ULL, 0x043791244CBD85A7ULL, 
            0x14DC8A3ACC39D438ULL, 0x795794EE5AA4733DULL, 0x5C694D05929E6D37ULL, 0x39B82644B30AE55DULL, 
            0xDB82748798D6883EULL, 0xA5060CD2678EFB20ULL, 0x8C0364A2F7DDF207ULL, 0x3A026BEF61D81946ULL, 
            0xCAAA7C5741C6F4BAULL, 0x0A91F080B4C2A478ULL, 0xC41CAA415650E609ULL, 0xE133B1193BB8AF8FULL, 
            0x9BC2A705E8FC1ECDULL, 0x456BF4065CB36342ULL, 0xC6CBD29789D4505AULL, 0x8FCDB129F5BCA072ULL, 
            0x275B43269ED0D2FCULL, 0x300A186D63475805ULL, 0x9898A63E09367AE4ULL, 0x0B26481D60FD5F4EULL, 
            0x20E9370DD7393717ULL, 0x166B2F21B0B70C29ULL, 0x9CEA194682BECB40ULL, 0xBE1C352A3549C6C9ULL, 
            0x65B87F53DD0BEDA5ULL, 0xEC2855ECE094A7A5ULL, 0xECDEAD4C7AC216EAULL, 0x3D72E07BEE6AB177ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeyRotateConstants = {
    0xB227F32CF9C5E63CULL,
    0x32FD0D91611ABBDAULL,
    0x017C066AE6778E6DULL,
    0xB227F32CF9C5E63CULL,
    0x32FD0D91611ABBDAULL,
    0x017C066AE6778E6DULL,
    0x2686CA872121978FULL,
    0xD91A7F7CC424970AULL,
    0xE7,
    0x3F,
    0x5B,
    0xD8,
    0xFF,
    0xF4,
    0x1E,
    0x1F
};

const TwistDomainSaltSet TwistExpander_Polaris::kKeySpawnSalts = {
    {
        {
            0x6078AE2F76E1F760ULL, 0x12F6D34FF450AEC5ULL, 0xC361C477707E17C6ULL, 0xFA105506D75E178FULL, 
            0x5351701A226D8AD6ULL, 0x246BF9D97E32AE47ULL, 0xDF93A2707307DD25ULL, 0xE6441B56F372F064ULL, 
            0xD841F494AE4A1653ULL, 0xF7403DB4E783E9D5ULL, 0x4DCA36DE7403416EULL, 0x71A7BB6B0CF32EE4ULL, 
            0x1231888A1CBED640ULL, 0xC42E51163DC3129EULL, 0xF488318EC849C7E8ULL, 0xED8B5B3E8A591471ULL, 
            0x64D0EC319BE1413CULL, 0x61F3578058BD69FCULL, 0x2B10BB8B1E466672ULL, 0xD6947F8DBD146F15ULL, 
            0x676560C8274845E8ULL, 0x88E333BD888901A5ULL, 0x453DFF48BBF04FF8ULL, 0x596543A54B018DCDULL, 
            0x01EC96B91EDEA867ULL, 0xFEE3B6D50268B862ULL, 0xAEB5ECEE0EE5D6EFULL, 0x005BEB1EC91783DDULL, 
            0xBB8D91F5957E27E6ULL, 0x92B8AD72D353E9B2ULL, 0x03D1F30662F67963ULL, 0x24383C4400FE4A2AULL
        },
        {
            0x615AB2EDBAFE5A96ULL, 0x35D47EA17EEA1FDBULL, 0xB5D04D92928C8F97ULL, 0xD4CDE74AC1811AF2ULL, 
            0xD49D30E3D308DEB4ULL, 0xA677575D0E2EAE40ULL, 0xEEE54F80E8C6EE6DULL, 0x69225B1D474CF700ULL, 
            0x9C2DDF12F8E2FC6DULL, 0xAB3C7CE395F27F44ULL, 0xE71A857760F34DC5ULL, 0x8ED3F1D42476E7BAULL, 
            0xC1612B19359E6F3CULL, 0xF5047CDF956C0F5DULL, 0x59D01909FD1C2B56ULL, 0xCC63AF683F7EA027ULL, 
            0xF6BAEF2BFA1524E0ULL, 0x991CE58095EC6508ULL, 0x828A49A8D5134BC6ULL, 0xB17346FB421F4FBFULL, 
            0x580E806B7E960F26ULL, 0xF34B072FD4229E59ULL, 0xA0AF0004E24FD176ULL, 0x4640E46E8E635D8CULL, 
            0x1869CC4FB71BD304ULL, 0x3D79A49374022BD7ULL, 0x57E03B95821A4193ULL, 0xA2B78641E35276E3ULL, 
            0xC0C0BE1B9D3A2B1DULL, 0x50D5690D4A5BEEB0ULL, 0x8CBEC2CDFA834918ULL, 0xEB61BAB548AF03DDULL
        },
        {
            0x58B8BBE551BA8486ULL, 0xB4B95CC5A95C3DD0ULL, 0x3A6FC602A8D8AAE2ULL, 0x7C55B8050C58FCCDULL, 
            0xB84F3C80EFEB86A6ULL, 0x151D5671D748EAFAULL, 0xACDCB1E06CE39F82ULL, 0xC54EEE79E474FFA3ULL, 
            0x438324CE1597514FULL, 0x50E880EBD2CB4BF8ULL, 0x6D827DDCF9701C0CULL, 0x3440A3DE775A548BULL, 
            0x0908589F10857E29ULL, 0xD7D2AED614527639ULL, 0xB0B5A10EE8D6D574ULL, 0x315083AC6F324545ULL, 
            0xD7624BDAF56814DCULL, 0x194AD728CCA35CB9ULL, 0x66D363E2A505E099ULL, 0xFBA33BAC153BB978ULL, 
            0xC85990AA1195B68AULL, 0xB6AF5E53C8D80950ULL, 0xD459B4D64BAA9EF2ULL, 0xB628E1A573231055ULL, 
            0x65BF0B073538EF09ULL, 0x54AD8EFEF6614F85ULL, 0xE09B7E9337DDC57CULL, 0x9DF8E4017BDB6AA6ULL, 
            0xA35DCC8474C7CF3AULL, 0x14A9D1FC239692CDULL, 0x5ABECF1E57E911D9ULL, 0x30D2C78D3E65AA0DULL
        },
        {
            0xEE2ECA82124EF867ULL, 0x009B5A331AE7A3D7ULL, 0x1FECC6A5F1023619ULL, 0xA5C9C2990938C0A8ULL, 
            0x34E3D6B7C7B0D7FCULL, 0x27AADF725E41F597ULL, 0xD28FE3081ADBD7C4ULL, 0x6C744A23C0A39EB8ULL, 
            0x37AC8C67DA90D22AULL, 0x28E7C86717A65385ULL, 0x3215FF003292A38EULL, 0xC10C70AAB4883FBFULL, 
            0x0DF3945F7E357EB3ULL, 0xEFD5A401D9506652ULL, 0xCFB55B01604897A9ULL, 0xA30626C0080A842FULL, 
            0x51494819A760AA34ULL, 0xA8DF5BE316DA0FFDULL, 0x2DA6101437B7BE08ULL, 0xD52C013EAFA58236ULL, 
            0x03B1CF1ED90096E2ULL, 0x0AAE85DC0329BCE1ULL, 0x2B42BB92C4864143ULL, 0xD4DD7F937091DE31ULL, 
            0x1F1D3097567433F5ULL, 0x4CDDE0E04E1B55FAULL, 0x125CD8B2C54B7E98ULL, 0x9A05899BFD03029EULL, 
            0x336D54A21464EE41ULL, 0xA10DBD166816E7F3ULL, 0xEF3B04FE1CD404BEULL, 0xB5510B03970DA374ULL
        },
        {
            0x8A6FCDE55C9F5ED0ULL, 0xB444D5027366FA46ULL, 0x67329ED559B125AEULL, 0x5BBE4F69DBD80002ULL, 
            0x6FC73070C74CD112ULL, 0x93EEABA249DC0925ULL, 0xDB25F90988A14F5FULL, 0xD2A73F5F25A41DB2ULL, 
            0x5DBE74BD0BBFE075ULL, 0x07907EB3CD3C49CAULL, 0xCFB22EA9304D0A40ULL, 0x3D3BF61BEF89C2F4ULL, 
            0xF2206ADB58D323CAULL, 0xE0BC6365BC9F4161ULL, 0xDF8323C8810E07BDULL, 0xB8CF168AF5C15D7BULL, 
            0x18AF67709BE61604ULL, 0xD96CC7BCF51CE82CULL, 0x7164FD2A933E4B5EULL, 0xD8F23FB79D2D0E04ULL, 
            0x6D01B0AF8A317B74ULL, 0x1C76FDB9530C08B5ULL, 0x21B58A357A994CD2ULL, 0xC8BF732C301C7D4AULL, 
            0x8D16D007F2754EB8ULL, 0x7C16D19F19BCB704ULL, 0xD35B6724D4A5B3F1ULL, 0x85F457C57B52857AULL, 
            0x069E67DFF95AD280ULL, 0xD40EC6B11C889BB9ULL, 0x256850CC08F3AAE3ULL, 0x0978FE2DC6DB39CEULL
        },
        {
            0x31EF3E5F50E78CE0ULL, 0xB4636542C4782F9CULL, 0xF860576036B5277DULL, 0xFA7DE49A9DB34819ULL, 
            0x4E8A9E3D82360F40ULL, 0x17608885FA66B3B5ULL, 0x213AA64C1DEF044EULL, 0xE2832C1E3DEB5D00ULL, 
            0x75441B8709DC94D4ULL, 0xD1929DF925831023ULL, 0xBB5195E95F9A1517ULL, 0x532741CCF4828248ULL, 
            0x43927D90BA25709DULL, 0x3F8F7C44A67AE1E9ULL, 0xCCC67360553DD2B5ULL, 0x69CF48AEE8F01A97ULL, 
            0xCA9AD154D1957569ULL, 0x2564D1379818C050ULL, 0x1130F1CA3224BD86ULL, 0xB1B0DBC5F5B57A44ULL, 
            0x0E928FC951739898ULL, 0xC202E66D753CCAD7ULL, 0x4CF8786B72F4C350ULL, 0x42D3F5FCF46369CDULL, 
            0xB295AD295E0EE868ULL, 0x76B84A7AA63189EDULL, 0x67D57EF843655533ULL, 0x381BB9BBB9C5525DULL, 
            0x22E4AEC9669EF1A1ULL, 0x75E6214951641761ULL, 0xB1486440F171EB2DULL, 0x7EE7D5FA6BF0FA13ULL
        }
    },
    {
        {
            0x76D48EA5BFB5482FULL, 0x8E80E57960C4E0EEULL, 0x2A7D8A5D4CF3A363ULL, 0x7DC3755599168EC9ULL, 
            0x4DB9E2668B140795ULL, 0xAFA4F72D84F570C2ULL, 0xEDD2EC66E8D0A4B7ULL, 0xB8E6E1F8BCFC7364ULL, 
            0x5D82E60BDFB2F886ULL, 0x841CC9A80FCF6586ULL, 0x5A6BBAAE9EDDA0D7ULL, 0xD6BBCA72E85F97A1ULL, 
            0x91B2824588EE1566ULL, 0x587FA034FE149005ULL, 0xC85842255F191554ULL, 0x5615996F6C33C934ULL, 
            0xD2D4D144824E7395ULL, 0x98740253768FFE81ULL, 0x509851022C3DEF03ULL, 0x884A0222A1DC710CULL, 
            0xA2F9F5B26EB8DD75ULL, 0x9DF499C1B51BFFB5ULL, 0xE24B8C57D5F97994ULL, 0x2FD46BE738C59A8EULL, 
            0x22906DB7C1279A9BULL, 0x66EEA12950B07681ULL, 0xC9D1B983167E3C57ULL, 0x2F08A95A2E6994E7ULL, 
            0x909A3BFF0CDAEAC4ULL, 0xB4969C37B7852E3DULL, 0xAEF69A6347BAFF0CULL, 0x15D8D5967993C6F1ULL
        },
        {
            0xBFA90C6060E2CCF2ULL, 0x85D44796EA668989ULL, 0x2E561D6F0CFA44DAULL, 0x56F33C645B157290ULL, 
            0x2962D95EDAB74EADULL, 0x2FC36E268FE6F0B5ULL, 0x66E8EFB1B66B4AABULL, 0x11F006998E1AC013ULL, 
            0x8BF03F3B3550FE0EULL, 0x656683D9EC91733CULL, 0x3214A3A05C4B54FDULL, 0xFBF5F7070854E1ABULL, 
            0xDA410E42D6474896ULL, 0x595EAFE4602F079EULL, 0x419C200573EA2AB3ULL, 0x394BFB27C5960D5AULL, 
            0x6F5EACB0562D1A5EULL, 0x31A434FCEFCFA766ULL, 0x2F241185D676B69BULL, 0x14247869DCF33680ULL, 
            0xC56B837DC678B98EULL, 0x8EF05339DAC47B2EULL, 0xAA79C0B62BBE3AB9ULL, 0x8797B4E8163E7BFAULL, 
            0x6770F6916D45E102ULL, 0x63F13B26C1A4DB7FULL, 0x4609EA713723C01CULL, 0x67F6CD02ACE6A59BULL, 
            0x443140A7005A9C42ULL, 0xA36F50FA39A09E57ULL, 0x97C676AA7AA2FD2AULL, 0x6DE0A792D50140FAULL
        },
        {
            0x92022A5024283BCCULL, 0x9F3426383AE5114DULL, 0x3B6298815C4C2588ULL, 0x47DD53105D1B0CE4ULL, 
            0x4A08A1C980A05EB4ULL, 0x599E47EE91C2EC2DULL, 0xA9290BA5E1EC6ADEULL, 0x49C13BE199BD2C3CULL, 
            0x717A8114B385F9BAULL, 0xAE8E2776CDF0C283ULL, 0x96606E603360AA14ULL, 0xC476B559679D24EEULL, 
            0x4CD46CEAB2A2B814ULL, 0x3651240D8D1E90DEULL, 0xDAD3A0484BF20812ULL, 0x584CBF2BFDCF4B8CULL, 
            0x29FA33E537676435ULL, 0xBD8E4A652AA5786FULL, 0xCE88795129D3BA71ULL, 0x483C30F4BA3139F1ULL, 
            0xC6CCF64903476B21ULL, 0x3A85CFB931269A34ULL, 0x8E4FD155607B6440ULL, 0x436675F4D3AF8587ULL, 
            0x99D260BB5520B701ULL, 0x8C63D04D4B0AD58FULL, 0x7772E2387022B161ULL, 0xBD916FE9DCA52EEFULL, 
            0x34BAC5388CEB0A0AULL, 0x692197925978E625ULL, 0x464F209F527F59BBULL, 0x0305BB7137CB9D26ULL
        },
        {
            0x42B4F590E497571AULL, 0x66EEC475234A8C4AULL, 0xB05187C055E38688ULL, 0xAF079730BB01EC29ULL, 
            0x2679575E8BFE0E7EULL, 0xED8022A3876BD84BULL, 0x08E0FAEE8B02C6D2ULL, 0x1DB50D35D047DCAEULL, 
            0x89EC83E866E0B530ULL, 0x32399F5C77EC3F18ULL, 0x92FCF3EB7A3AD49EULL, 0xAC0B6C0F1037F41EULL, 
            0xC361F89A1E94824DULL, 0xDBF5F9D02D6A7293ULL, 0x6120374062AE619AULL, 0x136CB48DE142A005ULL, 
            0x20CFC87EB820291EULL, 0xE005281CC75A18B5ULL, 0x8001C0B2C2A3348FULL, 0xD2FA14EE161FF87AULL, 
            0x836A1BBE40B7C813ULL, 0xFBB06D777363119CULL, 0x7678342531884D35ULL, 0x98D9590C66D59790ULL, 
            0x879263C533DAF52EULL, 0xDFBAB29A47EB0D04ULL, 0xF5A2F3D2092C3E89ULL, 0x9B826E184FC6F5E6ULL, 
            0xB0505F8FABD90B81ULL, 0xE21C9758EC827964ULL, 0x14B6D292F5E785B2ULL, 0x4BB68B8F147C9522ULL
        },
        {
            0xDAB26F78FD875565ULL, 0xC69995860FFE70E9ULL, 0x99AE139BB42DFA69ULL, 0xECA9C8B0935AD802ULL, 
            0x8560274B368E3A54ULL, 0xE3DE2CECE78A75DEULL, 0x8F4F4088138CE36AULL, 0xB9E84697EAA6E13CULL, 
            0x0CCEC1A02F2EB46DULL, 0xBD84D90173CE8E91ULL, 0xEDBFEA43BFF9ED02ULL, 0x69B0AC9A22F7EE54ULL, 
            0xC4462CFD014A5C7EULL, 0x09603F81E87172BBULL, 0x8D41C28BE93BE40BULL, 0xDAD22144EC3C0337ULL, 
            0x3625B7E78AAF2B1BULL, 0xE3B08FF5A5677738ULL, 0xF22A66F669E31C15ULL, 0x84BFA000BCFFCBDAULL, 
            0x4E8AC95856A94FF2ULL, 0x549736431E5BF950ULL, 0x8F02ADF692F07007ULL, 0xAF31F6E648B109CDULL, 
            0x389666F0C759F37FULL, 0x09132F31B9CCD2DCULL, 0xED89B31AB8022A5DULL, 0xFBA293E1E8B827EFULL, 
            0x78D366D0AAA90E4FULL, 0x2A91163A9B67827FULL, 0x05ECF0C16F78498BULL, 0x3BB6360CE64AE1A9ULL
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
            0xCD2E1DBE8246A3CAULL, 0x49F26D07BAA57377ULL, 0xE7C9E73B69E88401ULL, 0x7182E66C3736485CULL, 
            0x36A76834CC09F7EAULL, 0xF64E9360A325EA61ULL, 0x2FEA5382351B9C04ULL, 0x3C1502901645D120ULL, 
            0x9BA24A7F1F942AD9ULL, 0xCD79C731638851B9ULL, 0x032237CF6643A63EULL, 0xF95362DC5E3C71F1ULL, 
            0x9EEC354C668F58B5ULL, 0x6774C3250CD15D52ULL, 0xDBF2952105924B4AULL, 0xE6ACF82EBF03B9E4ULL, 
            0x74FBE7B1FDB2C2B7ULL, 0x164D29FA28BBA4EDULL, 0x342C15AB53FA6B04ULL, 0xF72A32A8CA06FB95ULL, 
            0xE6C659618C95CD10ULL, 0xE8DE3EF8275E07FDULL, 0xEBB258C9D9166734ULL, 0x62E98930F59B0A40ULL, 
            0x75C9B0906824ACC3ULL, 0xFA9BED0A14E8DD31ULL, 0xBA4BF8DFAD762B1CULL, 0x3C4AB9F550707882ULL, 
            0x468070AF88A9D0E5ULL, 0xAEB65F3D509D62C8ULL, 0x7F477A76B117D39EULL, 0x09B5A2DF4AD8B594ULL
        },
        {
            0xFB42AC9D68710125ULL, 0xD9939F67DA7F55AEULL, 0x08EC6E5359C99221ULL, 0x7EA5259ABBA7A4F0ULL, 
            0x6DF96D844BE73CA3ULL, 0xE6ECE3DF543FA5CDULL, 0x4E1C2E182D0B294FULL, 0x914CEA53C92E153CULL, 
            0xE3AC626E3D3EB29EULL, 0xE608F05D4F32F21DULL, 0x0CEB68A183C9D659ULL, 0xC929A148576A0254ULL, 
            0xE293701C7F7A632BULL, 0x52BEC13183A35B86ULL, 0x9C23461F6A0D6027ULL, 0x12AE5724F6CDD5EDULL, 
            0x17B1AC6D6D711770ULL, 0x5750B605FCDDFCC7ULL, 0xC6F725286D6F9984ULL, 0x87767D9C32992290ULL, 
            0x755143D1D60AE791ULL, 0x9332A866167BA5F6ULL, 0x69D1445806748066ULL, 0xE83E985C3B833371ULL, 
            0x597920E06A1F8ED3ULL, 0x10DDAA019A4EF1B8ULL, 0x22B4CB820694BDC7ULL, 0xF1843E18EA426AFCULL, 
            0xFEE566638686AB5DULL, 0x6404AA66045EEAEEULL, 0x73DD20D271BC6CC6ULL, 0x08D6FE60BFABD1BAULL
        },
        {
            0x7EAABFE7DAF068F4ULL, 0x0971F146EA26BFC6ULL, 0x1B0136CC3F088421ULL, 0x02B06F9E6F6710A4ULL, 
            0xB7F66A60560E43D5ULL, 0x1CC4AC2FFE6B16FFULL, 0x392965483E225FDBULL, 0x52AF2B5152657C81ULL, 
            0xC08977CD0432FE23ULL, 0x94D9EA2260D30F02ULL, 0x5DAB3649D909A2A2ULL, 0x5567CAC13E9227B5ULL, 
            0x298F48638F61275DULL, 0xE08167053A6CB4CDULL, 0xE11164D9A8C49B62ULL, 0xE96712DD6A5B7FB3ULL, 
            0xBD6F2E8345D9399AULL, 0xA8716CF62BDF2DEBULL, 0xFB605A5EC55F1ED5ULL, 0x8B787C3ACFB98317ULL, 
            0x9FBD94175CB23B29ULL, 0x1C78014F7DA2082CULL, 0xE09CDE896186D9B8ULL, 0xC97126D6B092A2BCULL, 
            0x00A3F5FEA51E1B59ULL, 0x4A214DCEB19FDE08ULL, 0x361CB66AD194E899ULL, 0x02652F4838A9EB43ULL, 
            0xCEEF15D5042A5587ULL, 0xCF8BF4FF69F9378FULL, 0x389FCCDB5C60269BULL, 0x3E6BA6D4991594E2ULL
        },
        {
            0x10B5DA72086616AFULL, 0x70D441A0C7F1EB26ULL, 0xBC2E4C666968141AULL, 0xF4BCCF3CCEC0CAEBULL, 
            0x792BA72ABB672F83ULL, 0x9D3AA5D43E799D64ULL, 0x2BBFE787DEBF1542ULL, 0x77889C7CCDB29781ULL, 
            0x8233E4E51C87FEB1ULL, 0xEAB49A0C78376DD4ULL, 0xB1FF4F15A981860FULL, 0xF6417A0A2297CBB1ULL, 
            0xBFA7C508D4C7DA71ULL, 0x2A42A9CE91A160D6ULL, 0xE041F2B4C17D2C39ULL, 0xD7413E0726246970ULL, 
            0xA6DBE479D8A0319EULL, 0xCEA5DD4467A8AA2CULL, 0xC0CEAB848519E954ULL, 0x7586019987A47EB9ULL, 
            0xCB73C60788E6EAE1ULL, 0xDBA82CEC5179B0BEULL, 0x41494AAB6A5A074BULL, 0xDDFA4FE6464707B4ULL, 
            0x9C10E92AB1C144D3ULL, 0x5502951E60366902ULL, 0xB8A552BD7884ABEBULL, 0x2EB9CD9013A3CEB9ULL, 
            0x9C053285F7548498ULL, 0x0B4860D6389746D6ULL, 0xDFFD704A92356F8CULL, 0x56F802AD071AE690ULL
        },
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
            0x330D647A5C3D83BDULL, 0xA16F90B912CE3BE5ULL, 0x3C7C9D75599A79D3ULL, 0xFD2B09E8391E7E07ULL, 
            0x5C629FF749B57E92ULL, 0xF012D10D1E3DEA1AULL, 0x4D72E117C5C55A99ULL, 0x7EBC39518F5AF7DDULL, 
            0x4A398E5B7D968E24ULL, 0x8E533A9521558C9BULL, 0xF9D94A3757D5D136ULL, 0x4839440BDBC91ACEULL, 
            0xCC080E510DC43449ULL, 0xEEF8D84E4569DADAULL, 0xEDA8760A2FF47884ULL, 0x61AB17A76E6DB499ULL, 
            0x57A3EB12D25CF9E8ULL, 0x8AED00FEDFCA6C68ULL, 0x449E9A642FDDA33EULL, 0x453A207541A8FA1EULL, 
            0x2BAB3AB0B7D5942FULL, 0x0FF45A80FB7E69D3ULL, 0x7FE898CBD8197726ULL, 0x8A74E12BF36BD398ULL, 
            0xAF16A7E8FDC00DB4ULL, 0x5F7C163DC4FC97ACULL, 0x2747D224C4F997DAULL, 0x60BB3C98AD519B2EULL, 
            0xA0DBB7CF1FBF283CULL, 0x2FBADC5FACAFAAB7ULL, 0x01D8638458B2FA42ULL, 0xF5C7197C2F3B827DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeySpawnConstants = {
    0xA935D4D1EF396CBCULL,
    0x60BBF8129EE5824CULL,
    0x46FF92915E606893ULL,
    0xA935D4D1EF396CBCULL,
    0x60BBF8129EE5824CULL,
    0x46FF92915E606893ULL,
    0x0A4B3F53F27633C1ULL,
    0x7414E0E869734D6CULL,
    0x86,
    0xF0,
    0xDA,
    0x23,
    0xAE,
    0x3C,
    0xA0,
    0xCD
};

const TwistDomainSaltSet TwistExpander_Polaris::kSeedSalts = {
    {
        {
            0xB300E4494736866DULL, 0x7E8B8E078DBF23EDULL, 0xB779ECDE96547BBEULL, 0xB70E9E9B18E7F842ULL, 
            0x8EA3B34DA80FEB17ULL, 0x7BA618F43DD2A556ULL, 0x4108545CC2AD9EA2ULL, 0xA7643EAD6F44C422ULL, 
            0x961C8289BC8955F6ULL, 0xF97CEF959819AB8BULL, 0xBA1DDBE3022EE7DAULL, 0x8E413C7A747B83C9ULL, 
            0xF2730EF824E4F720ULL, 0x5FB0A46DFD3B8FBAULL, 0x07D21AE9B7F9D118ULL, 0x8485A20CFDE6B3ADULL, 
            0x8CBB0E5A2158FB96ULL, 0xB7F3239A8CF9186EULL, 0xB36514E28933EE4BULL, 0x2B880FB8BA9E9582ULL, 
            0x8F0C3CB3371877D7ULL, 0x884F07D0D08B57B6ULL, 0x59B212F1D2DC49F3ULL, 0x6C44DD118427BCFDULL, 
            0x8B606D738F575133ULL, 0xA4069D3F13104745ULL, 0xB2E4A29C21D5ECA9ULL, 0xA74E07AAC2ABE9C6ULL, 
            0xA45D67E29023CB66ULL, 0xB512C9E32A640D11ULL, 0x16039C650F4CD4DEULL, 0xB5DCFE567E5F45ECULL
        },
        {
            0x9E50157D308B738CULL, 0x1324DC57F4585944ULL, 0x124A6DD408AF2DD2ULL, 0x1105039476EC313AULL, 
            0x83FF76BE451531CBULL, 0x8C7EC94C4C0C39F7ULL, 0xAE4AE59A6DC81C5AULL, 0x7C0FB8720C002905ULL, 
            0x87F2780A4625382CULL, 0x52305AF3E4493956ULL, 0xB430F5161E57EC94ULL, 0x835DF37658D74275ULL, 
            0xBB45BDBFF7E619E5ULL, 0x6323A37BD4AD910AULL, 0x4B68565152FC950FULL, 0x113A32249997C367ULL, 
            0xC26FA10B91CE0773ULL, 0xE1634F119F9144D3ULL, 0x6F85A3B07CD41DF7ULL, 0x74AD40F99AC43ACAULL, 
            0xAA8D72A084FBEE0DULL, 0x849C2B990FEEACB6ULL, 0x30710EE22D1A5DB9ULL, 0x95A0E36867943C5CULL, 
            0x883C22BA75D7E392ULL, 0x572E858794CFB5D8ULL, 0x3539364312E47657ULL, 0x676B8427D5B514F0ULL, 
            0x66C7FEDA8DA314AEULL, 0x5E0FF1BD40661A78ULL, 0xBBEE13650C4604C1ULL, 0x149E7C34F7FCD909ULL
        },
        {
            0x78BF0DB5B946ADBCULL, 0x6302951A6694050BULL, 0x9A962959FE5609F3ULL, 0x1F529BFE01BD3D65ULL, 
            0x106F05DDC5073ABAULL, 0xDC05FD4CA53E38ADULL, 0x5C2FC42D34132098ULL, 0x28053568BF5B8637ULL, 
            0x7B8BE24E95D1CB0EULL, 0x3AD9C8C659D1B83DULL, 0x6C1AB65ACD535770ULL, 0x6882E04E66960BC9ULL, 
            0x5FAFBA86954DD145ULL, 0xFA5371D9CCA8E7B7ULL, 0x719A33C93FB04197ULL, 0x05F312A18B01E0B4ULL, 
            0xDBC8428AFA77A5ABULL, 0xA88C3FD064BBE325ULL, 0x85D3858B0ABD014FULL, 0xD683946789817F93ULL, 
            0xDC25B91356E14165ULL, 0x97084A285FBAD01AULL, 0xC68B9F27B5C111E9ULL, 0x1D830E5D70642971ULL, 
            0x428D65DC200D2BB0ULL, 0x4B720211930565D4ULL, 0x37062BD69DFBCC40ULL, 0x153D8002D289DCE4ULL, 
            0x2E3BB66881A607B1ULL, 0x5055D412A3878AEBULL, 0xFBBCF3876694A241ULL, 0x47C752EAFE921C72ULL
        },
        {
            0xE86B4F485D915DF5ULL, 0x96FEE88235BB0DD5ULL, 0xBE51F76FBE001185ULL, 0xAA3A7C35AF53645FULL, 
            0x029A5EAF74B9CF18ULL, 0xABFB40943F52B83BULL, 0x832317ECCC04681FULL, 0xD0A22EB246FF11A2ULL, 
            0xC5993F5C720DC1F8ULL, 0x1050E2AE525031E0ULL, 0x64B8DA8B893F26C3ULL, 0xBF9390A212DCD253ULL, 
            0x43C7E07F476BF5F0ULL, 0xFE4E43BBA557B957ULL, 0x7B0E7887A42C4DB4ULL, 0xB38A0449C4219A00ULL, 
            0x76D5B06990251808ULL, 0x07416AA848E07E78ULL, 0xC80A9547C88BD087ULL, 0x43EE05AC655257BDULL, 
            0x5246504FAEC92729ULL, 0x4A9FA28098814A77ULL, 0xF6F266B17F946B99ULL, 0x8EF1D80DEC957A51ULL, 
            0xAD16200FEE0BFED8ULL, 0x9BFAAF0B517EC890ULL, 0xCB41E6065B88C0C7ULL, 0xC2922361EE03AF6AULL, 
            0x8693A28817D955CCULL, 0x84C1E6E8C466F531ULL, 0xB809C25CCACCE3F0ULL, 0x3C73CA4A753F7A5EULL
        },
        {
            0xACB738BB59974DE9ULL, 0xB419E7197D9D5305ULL, 0xB44854CBC1D0E8F5ULL, 0x433CDA3ECD526B0FULL, 
            0x63AD34108969002AULL, 0x531306B6D47575F3ULL, 0xC0150BC03C7EBC1AULL, 0xD0A2DCCEA704CF31ULL, 
            0xDD05C3337781AE1CULL, 0xFF5A7E20542A4712ULL, 0x6C620AB3DA30F422ULL, 0xEB34C0B528A6D62CULL, 
            0xF8ACFB83254C987FULL, 0xA4BEF5A1DCB80DE2ULL, 0xEA204AA200BB338FULL, 0x4C4A9ED1CE03878EULL, 
            0xA46100C2ADA7284CULL, 0x9AE5B0A87E07BFACULL, 0xB1CBD23A42478243ULL, 0x7D1A4F1368038C81ULL, 
            0x7637B82CE3E46C6CULL, 0x19E358DA4A5AAD43ULL, 0x5150B6146EB7CC39ULL, 0xB4BDA410F6507AC4ULL, 
            0x454A9FEA8FC9F0ACULL, 0x359B73138D93E099ULL, 0x400D52D339AFA6C9ULL, 0x0CF20ECD3D671CDDULL, 
            0x7B439BCF268321A1ULL, 0xCE9C6617B6706E42ULL, 0x5D85ED1F2C7F84FCULL, 0xB958224E83F8A912ULL
        },
        {
            0xA63AA41A77024123ULL, 0xCE85245C0340C49BULL, 0x1A396D407BCC7A09ULL, 0x4C544C84A4F117FBULL, 
            0xA133A65AA94DAA61ULL, 0xD3E032507B881522ULL, 0xDDC0B6B1A921C004ULL, 0xE9DAEDB1BEB7ED48ULL, 
            0xC96DC7E512FFE82BULL, 0xFAFD3155322818C6ULL, 0x212FE16B5BB978A3ULL, 0x30A60ED8B0507800ULL, 
            0xBAD3D86E195344CDULL, 0x0FCB6E9D149128B7ULL, 0x4D1B8853BBFBF8CCULL, 0xE0BF59C876D08C80ULL, 
            0xD08D364C6103659AULL, 0x8DC860474BA9B721ULL, 0x5B74526E0C44CF2DULL, 0x36475FC67BB6C647ULL, 
            0x8DC0B8D23226C108ULL, 0x9636C6C098A034CAULL, 0xE3C4ECEFB986F340ULL, 0x390042CDF441176FULL, 
            0xA313292F5F620184ULL, 0xAB438B0620C18A20ULL, 0x96E152A87A267855ULL, 0x3592E50D759BB6AAULL, 
            0x5F731CB9D9561B82ULL, 0x94E74E2285BE0C1AULL, 0xBA6CEFA0FA49A1F5ULL, 0x82B36C84D806B89BULL
        }
    },
    {
        {
            0x3264897E5745E96FULL, 0x39BBD6AC894EC774ULL, 0x472064CA24138941ULL, 0x66C8C3CF0984A5C6ULL, 
            0xAEBF6F4EA3462E3FULL, 0x8E19C00E424F71F7ULL, 0xAC277A0E07EE6652ULL, 0x048B568F43F263B5ULL, 
            0x7104EDCC39DC2DB6ULL, 0xAF614733C671BD86ULL, 0x089F9355C3459100ULL, 0x4427559F49903053ULL, 
            0x8668448FFFC0AA52ULL, 0x27DCDD65EA2B6F6AULL, 0x8B221857F1D82AFCULL, 0x3D27CB8FD22C72F3ULL, 
            0x21F29FD1C01F9A41ULL, 0x550807ACE4580225ULL, 0xDC280D55171B623BULL, 0x98B888B8ABA7B42EULL, 
            0xB0110DDE2F097EF3ULL, 0x6B36233C1839A837ULL, 0x0F8596E0CC6E5514ULL, 0xD830740731867860ULL, 
            0x460661C10887BA95ULL, 0x4585CE6062D85D04ULL, 0xF100321271AE2ABAULL, 0xBDEC918839F3CD7EULL, 
            0xEA3ACDB2735C9102ULL, 0x130E304AA9699F48ULL, 0xA3BE20BB98A2DBFFULL, 0xA509BD82502C2EBBULL
        },
        {
            0x771DC65D3D43EDFBULL, 0xEE0D9A6571725C6BULL, 0xC14928B1F01836B8ULL, 0x2C8829F9036A0908ULL, 
            0x73C407C0AE383315ULL, 0x0113756C5152316FULL, 0x093E04AEFD791F7AULL, 0xE95EAE30A2A3FA38ULL, 
            0xE94036CF0199D569ULL, 0xB6BB3A442BD37062ULL, 0xB4432F93331DD8EEULL, 0x8837D97EBD99141EULL, 
            0x94A4C82A6211369DULL, 0x64652BF1C8D2DF27ULL, 0xABD1A193D16D5A25ULL, 0x0A1E0985754E93FBULL, 
            0xEA380E5E1354C778ULL, 0xD2E60A242DE053FDULL, 0xEECDD9C4680F5FDBULL, 0x1C9A6CE75C127BAEULL, 
            0x4A28D889D63C49DFULL, 0x2357F9F996F4AA43ULL, 0xAB644BF16ACD70FDULL, 0x4C20B33839E23384ULL, 
            0xA41C5BE29A612B48ULL, 0xA4982982263E124CULL, 0x5332CA3F3761A907ULL, 0xFD67F220D5DE4E82ULL, 
            0xFCC725FEEEA65E6DULL, 0x275ACFBF30EDACE7ULL, 0x8591333109D18DB1ULL, 0xAD5FE70BFC644647ULL
        },
        {
            0xB8A8306A0CC2A05DULL, 0xECEB3C580B845975ULL, 0x4C81EB825D7D4875ULL, 0xAC8EEE279588B89BULL, 
            0x7D360A1D1670F283ULL, 0x4611FE7283BF359EULL, 0xAEE1179F74CFA0AAULL, 0x4AEA3A6D638DEF0DULL, 
            0x271380CD91881785ULL, 0x12D26A6ECF8A4405ULL, 0x3F9E232C254C8C64ULL, 0x453C29C52B362756ULL, 
            0xBB7ECC04B1A4C85CULL, 0x333D128344E453E1ULL, 0x619DD5C174D4D9F0ULL, 0x6EE7973AD8C8D07EULL, 
            0x4343DF547A35685BULL, 0x70294FD1B90C4866ULL, 0xA4C460F414640D48ULL, 0xDA5A264B036F2632ULL, 
            0x76F82EB9FDB594CFULL, 0xAB46E0EF5935E724ULL, 0xB4E2B5A1F33C1E60ULL, 0xAD22711F7C25633AULL, 
            0x807B041CD84D0D22ULL, 0x1A73424E6FA389EEULL, 0x36BE014D26C58A5BULL, 0x7711B61B421178E7ULL, 
            0x711D1EFC05DD8E15ULL, 0x4CA01E87C203C216ULL, 0xBC6BB6F34598C1EFULL, 0x4240D98755EEF8EFULL
        },
        {
            0x64F5452FB6808D13ULL, 0xD0159D97A3C6F258ULL, 0x4A523FCB8C643A88ULL, 0x9B498E26C5E421B9ULL, 
            0x5353CC8E3917BA54ULL, 0x36D3FA64110BBA9FULL, 0x6FB94701160517EBULL, 0x6E69B8ABB8A3FF76ULL, 
            0xEBB0D008F00F2CB1ULL, 0x9FC0D8BC6D3CC404ULL, 0x56363486C946613FULL, 0x7E48DA44DA518F91ULL, 
            0x4DBBF8B8B0BBFC06ULL, 0x1FC98470D21EA8C5ULL, 0x9E4D159FF5B56E64ULL, 0xB7F9B7BC7C1E4F4CULL, 
            0x26E550B17E82E529ULL, 0x2D345F07FA96F0EFULL, 0xBE6053CC5AD2A71CULL, 0xFFA58E0C27BA3F41ULL, 
            0x916D3C8B72D311E8ULL, 0x05F81A0E05BE902CULL, 0xD18DAC2E8BA824BDULL, 0x9CC678C8B8A04EA5ULL, 
            0xB7E0D9F5F7857B41ULL, 0x6EDBEE4AEA7DFD15ULL, 0xFB8314A903439F33ULL, 0xC7FF1A3CAA4FE930ULL, 
            0xF9EA36A232129A87ULL, 0x5F216BC2BEEB7624ULL, 0x272FF6CF2921350CULL, 0xCD020F73640DA7BFULL
        },
        {
            0x76E50BEF8E5360FAULL, 0x835871097DD5FD26ULL, 0xB2357B2608AC02AAULL, 0x49DF67781BDC3EFAULL, 
            0x19834DAE1657EBECULL, 0xB9CA9B0E77866BEBULL, 0xA7632872588C6AAEULL, 0x75493CB64A314902ULL, 
            0x0A811E420551570EULL, 0xB497F1FEF96577D9ULL, 0xE4F5A8C7BA29D50FULL, 0xBD23FAE3742B79D3ULL, 
            0xC5883C118445C2F5ULL, 0xCAF80C2CFB860884ULL, 0x283C498771FC4B99ULL, 0x19CE064A61F9DF2BULL, 
            0xB58B99FAE2052A76ULL, 0x380C8FB07053EABDULL, 0x58CF1392DA1E7590ULL, 0xE4B13FDA04E57BF4ULL, 
            0x5A906DA03AC3C099ULL, 0xEF637EC70D273931ULL, 0xA64B01C16BBE75A8ULL, 0x8834BDF3C9A5CFAAULL, 
            0x44AA6CFC5BEA04E0ULL, 0xDFC4ABF79457A171ULL, 0x153DB3BE12FECC63ULL, 0x3EF094757A4CD511ULL, 
            0x8D55CBE399C72C24ULL, 0xB402BE6B69F640E6ULL, 0xD8CA003B1809CAE5ULL, 0x750A7964EA9F0975ULL
        },
        {
            0x2ABFDE33E82B0332ULL, 0x7307C16708C335BEULL, 0x6A56EBE69B595E1EULL, 0x5B2BE131C2894415ULL, 
            0xD6E7521B8EAB42C2ULL, 0x718822E317D0FE64ULL, 0x0ED393A3B8CF4D9CULL, 0xFDB22CD78FB61C72ULL, 
            0xE86EACAFF2C781FCULL, 0xE21690E32FADE589ULL, 0x2B528450AEB5ACDFULL, 0xB215772D5C1ECF8DULL, 
            0x8C1D2623D4F05D4FULL, 0xD3D1A6D8CD271106ULL, 0x62C8878BCA98E693ULL, 0x7B514C63B92FA522ULL, 
            0x88565322EB7E63EBULL, 0x5A4D8808AF2D27B7ULL, 0xBA4364B0ECD9330BULL, 0x89DE13C0F1E90892ULL, 
            0x36600AC58558118EULL, 0xCB3A680C22A04349ULL, 0xC48A59B3C33941FFULL, 0x25CDA99D1CB22F64ULL, 
            0xDBDF423812ED0149ULL, 0xF5B6C6E28133D90DULL, 0xF7E575FA8922B3CCULL, 0x30CAC4FDDCB9CBB5ULL, 
            0x16406086F3F256AEULL, 0xD702CC957DC53E32ULL, 0x0E30B52E6EC47F17ULL, 0xA13AE6E677364394ULL
        }
    },
    {
        {
            0xBEDE1FDC18797EF2ULL, 0x1AC84051A978550DULL, 0x2D28EBAB0C927C29ULL, 0xDA2D72E17294926CULL, 
            0x992AF67B1DBA4E8DULL, 0x4E38E817EBD14999ULL, 0x76FE43B325914455ULL, 0x97DA8391A0A7A78DULL, 
            0x10CD373515B49A8FULL, 0x0CFA94A2CFCDBCF3ULL, 0x14C89B80D7FA505EULL, 0x2E20C45F25C119CFULL, 
            0x70647AE346DFED28ULL, 0x23D69095256C5853ULL, 0x7FB01318BBD66DD2ULL, 0x875289FFE1635F67ULL, 
            0x082BF87930264146ULL, 0xD450DE42D293D004ULL, 0x033DD040993B5F74ULL, 0x4C66C41F657F979BULL, 
            0xD0C29368C0A4999BULL, 0x67B25CF6E270A511ULL, 0x625931540898DCAAULL, 0x0D74B1895E598481ULL, 
            0x33471AFE9610D54FULL, 0xC95974BF97CAA91DULL, 0x3D3E10DB76FAE970ULL, 0x0759C9C181297BE7ULL, 
            0x6C8F9E2E093E6E64ULL, 0x673C1F3C45350A19ULL, 0x8536B21B193E0321ULL, 0xEEEF6FDFC966670AULL
        },
        {
            0x21A0A754EB0A8CD0ULL, 0x17D0244B37191144ULL, 0x059C6CEB0DFDF8F0ULL, 0x1FAFD7433A11B740ULL, 
            0xFC4F562B9011BBBBULL, 0x54E72A296DB96C70ULL, 0xE27A89C3566F9676ULL, 0xB475D1333FC81718ULL, 
            0x08D941D409AC3626ULL, 0x5C2D3796424E8665ULL, 0x7FAC8A3BD063AFA0ULL, 0xE20D6DDDC20B0313ULL, 
            0x6F87793AB51B62BEULL, 0x009894AE8D2127FEULL, 0xBF34C9896450C2E8ULL, 0x9D2BACAE6C2978CCULL, 
            0x89D908897C31DB88ULL, 0x925594D7BF1B71D4ULL, 0xF789F0B59FA9C24EULL, 0xCA3557959B27F5F1ULL, 
            0xD30A87867FC43857ULL, 0xC195FE594FECCB3CULL, 0x90C0327EA397C0B8ULL, 0xBE7500DBDDC2E91CULL, 
            0x30A91976B9485BE2ULL, 0xD76131388EE92D0EULL, 0x3064C4F63ACA5E3FULL, 0x1CD5A331F6564E4CULL, 
            0xD5919CE4D55DDF75ULL, 0xFF6356C3095BC5F5ULL, 0xDE47A07C58768CB4ULL, 0x03F528F0FB350DE9ULL
        },
        {
            0xAFE616B4DE91F37EULL, 0xBF2D7875A22C8E90ULL, 0x3F5A1176F850FB59ULL, 0xFE1D0F8536C83AC6ULL, 
            0x0FA8C0D1A10FAE2EULL, 0x9670A430CCF68506ULL, 0xDBD57FB2BC6E7837ULL, 0x56AC24840F27C624ULL, 
            0xD89895B8837BCF4EULL, 0x988F67EBAE74EC21ULL, 0xD5B87B0C3858E2ABULL, 0xE305C1FC6EDD88EDULL, 
            0x5D8EB1D86041E9F4ULL, 0x8A9227305CA1EFE1ULL, 0x15CA6FDF8ECA96F3ULL, 0xE6C10D38CA1F8BB2ULL, 
            0x9727AB5F70149657ULL, 0x78A1C11BD8CB8808ULL, 0x885D3381B13A3836ULL, 0xD455B1E9CA72DEA3ULL, 
            0x1D38AC3ECEC05E37ULL, 0x749E6BE2D9785A12ULL, 0x9C820B7DDD45C9FCULL, 0x48F68E1EC54B4EDFULL, 
            0x2354979562CA64ACULL, 0xC90344175CA94B61ULL, 0xDBC9E26B61748C70ULL, 0x4D6E3821D3A4DA4DULL, 
            0x55BC43FFA8143323ULL, 0xAE7C2A0251B6A220ULL, 0x7CD29D14FA71294FULL, 0x3BC99AFE53CD8D5BULL
        },
        {
            0x75698902B9D5AE7EULL, 0xBB1CB2EE7BB95A5CULL, 0x7F81F951836F9FB8ULL, 0x182052C5146768F1ULL, 
            0xAA5072B0DBFDA9B3ULL, 0x4C07BD5D3AC7EBB2ULL, 0xF8BE900455C68488ULL, 0x79991107BE2BCA9EULL, 
            0x083B640259FF4997ULL, 0x68D344978AC23246ULL, 0x0E3B19400746245AULL, 0xA8648CD4D9F7A2FFULL, 
            0x6DABA3136C53B21AULL, 0x0FE56EAF57C684B9ULL, 0x55774C3185B25085ULL, 0xEAEE4D8D5539F2FAULL, 
            0x11739059EFF1E99DULL, 0x6BFA6F6B2CE51E0BULL, 0x9C16BFFC3BA0FFD6ULL, 0x012B27E66191D841ULL, 
            0xAC2657978DAFE72CULL, 0xE49F83B7D5593B9FULL, 0x3CB46EF3BD938481ULL, 0x906D8D0483B0A2A9ULL, 
            0x8E604CFE1E31745DULL, 0x73DA799151AD1B92ULL, 0xA26FB4ADB9763A7FULL, 0x7E0E722FAD78AFD4ULL, 
            0x91B77F1907895A69ULL, 0x585C4D61383EC662ULL, 0xF0BF60658838D8B2ULL, 0x8F269497A974E7B9ULL
        },
        {
            0x7543714D2BD1D7DBULL, 0xE98258597A0D7625ULL, 0x59E4E256433CACCBULL, 0x9038E6EF7F8E615FULL, 
            0x07332362B18D32C4ULL, 0x8BD756CE95B43955ULL, 0x6FA55CD50C76CAC9ULL, 0x713C7BF2E7035A98ULL, 
            0xBE4E3D7C7045CA9FULL, 0x914E4B85F78DEAC0ULL, 0x9F06ACB48E48222BULL, 0xE4D6C6B9F879D62BULL, 
            0x3F0FC65411C5C4F6ULL, 0xD93459714615730FULL, 0xA70082A625075F79ULL, 0xDB1DA92784D46B4CULL, 
            0xA169EDFDC931B4A7ULL, 0xB04B7570AF01F3D2ULL, 0xB4FDEB495DE9C1D2ULL, 0xDADEEA871D141265ULL, 
            0x33D3BC4C0551D1C5ULL, 0xCFE1AA7738C2BB10ULL, 0xE0141E2FB691C51FULL, 0x56B38BB687E3198DULL, 
            0x06BDF8D90B30CD73ULL, 0xA00B6B098712AA80ULL, 0x843E2E8EDE08B610ULL, 0xC2F6D854659DBB21ULL, 
            0x918E14F7E26880C6ULL, 0x3566900C4A76EA24ULL, 0x7E42E219EE552054ULL, 0x6C586C88F74E6CB7ULL
        },
        {
            0xEAC5CF698E9E46FCULL, 0xABB74E96218CEF7DULL, 0x69715C1217E876BDULL, 0x1562C21100A49366ULL, 
            0xDAC3F38F65B0085CULL, 0x381A2A00D45B4FF4ULL, 0x019BD6A868C25CD1ULL, 0x2E2B376336D01D00ULL, 
            0x55A192E2A1575F38ULL, 0x5EFA171A72ECF0C2ULL, 0x77FAA360155ED5FEULL, 0x463F2190E6402A09ULL, 
            0x8D9CE4EF0192E4DEULL, 0xD5D20A7FA10F1E48ULL, 0xA71226A8E017CBE8ULL, 0x21048A534D7534B5ULL, 
            0xD23B0FD5313FE404ULL, 0xACDB0D2E6A88D6F0ULL, 0xBD29DD7568A3914DULL, 0x235E351B3E4772D1ULL, 
            0x25AACE905BBE82B1ULL, 0xEB3EC1B425DA3223ULL, 0x14EF18395704EBB7ULL, 0xD9287120A13F4E4BULL, 
            0x6480D1383CFBCB15ULL, 0xF713DCF3CD4E9252ULL, 0x502ADC8CE234C16EULL, 0x852E674E65704124ULL, 
            0x430745DE7A846BDAULL, 0x4350C3A0A8452A8AULL, 0x839CB4BE12FE0523ULL, 0x13D4F9A83AD98E89ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kSeedConstants = {
    0x9130219DCEAA957AULL,
    0x6C6979320DA60E4EULL,
    0xB37F1394F23FF571ULL,
    0x9130219DCEAA957AULL,
    0x6C6979320DA60E4EULL,
    0xB37F1394F23FF571ULL,
    0x45EC8559505E7FA7ULL,
    0x94BDAD6BE06016B8ULL,
    0xEB,
    0x35,
    0xD5,
    0xB2,
    0xB5,
    0x11,
    0xCB,
    0x9C
};

const TwistDomainSaltSet TwistExpander_Polaris::kTwistSalts = {
    {
        {
            0x77C23FD25D4CF0F2ULL, 0xF1CCF7C0ACDDC578ULL, 0x384AEB58E924BF78ULL, 0x6BB1503FD15438FDULL, 
            0x7C462044324E9724ULL, 0x5EB6C223A231198FULL, 0x1CBF699B1F4173D6ULL, 0xB22F44FE4C923D87ULL, 
            0x0E8FE1C0907484ABULL, 0xA7F34CFBBD441140ULL, 0x160B0CF03B5A90D3ULL, 0xC0C4262A6574B1C6ULL, 
            0x29E5E36AD01F4F57ULL, 0x10D15DCA0BCF4272ULL, 0x5596362D0B61EE7DULL, 0xF846B5C433EE330BULL, 
            0xEC3E2C09CE43827BULL, 0x1C53BDD80BBB2166ULL, 0x8B1EBAEDE8810F5AULL, 0x0BEF73BB1981FB9BULL, 
            0x412F443C28AC310DULL, 0x3EBC01318C0FB58EULL, 0xEB9AD97E06E18DCEULL, 0xF0EE5DB25117159EULL, 
            0xF8D22C3F03CDC7B1ULL, 0x0D8046AB64BFD938ULL, 0x3051AE70EBE92467ULL, 0x68A9F77F1DDCFC94ULL, 
            0x8190F440CCE75C07ULL, 0xE6131A8852EB92C3ULL, 0xB21B0F9A7B7DD4FAULL, 0x97499FDA5FF2ABF7ULL
        },
        {
            0x2D7707C9C07E6C18ULL, 0xEF45E3C099876253ULL, 0x207CEA3313507BC8ULL, 0xCD86A2D933E67153ULL, 
            0xF33908279DC34B8FULL, 0x29978C1E36DC2953ULL, 0xD7DF1A0ED1D1CE4BULL, 0xDF161B9F37A4F31BULL, 
            0x70B29C5BC55BF91DULL, 0xE21366C2BB7BFD55ULL, 0x6FFFACB5FB2C32A3ULL, 0xA708D4AA9863D629ULL, 
            0xAB5E5DEBC0AB2E67ULL, 0x5829B368DE5E5B1DULL, 0x4070DDF7B0F90CBBULL, 0x63496EBC0A0D2FD4ULL, 
            0xC024BED40F2757F3ULL, 0x9EAEF4420C667A52ULL, 0xFAA1A7D9BD896884ULL, 0xF8934AD257C83F6EULL, 
            0x00CBD7812AA7C5AAULL, 0x420973384E9A83BFULL, 0x5BF5AB9432120511ULL, 0xAA717494E3F38A20ULL, 
            0x7E72C59B95D46CAFULL, 0x6E2E2380B12CC208ULL, 0xB8A52F9E7D865D72ULL, 0x04B03D5B1AEF16B0ULL, 
            0x047AC4E98F06931BULL, 0x4F0C76742C5487BEULL, 0x90599DE40B58366EULL, 0xAEF1F16800A3879AULL
        },
        {
            0x5010FFC5FF55214EULL, 0x903E7D1215E8E6A5ULL, 0xE0175C932B261EE4ULL, 0xE2F79618E71714D7ULL, 
            0x37CC92C4DAEA9DB4ULL, 0xCFE5E945BC3D7FDEULL, 0x02074998238BA23FULL, 0x0938B8AB1DD787A1ULL, 
            0x606C995A81911021ULL, 0x50C724AF4267EA5DULL, 0x68CAC26B59E62F1CULL, 0x0A5E63C44405172EULL, 
            0x029B3ADD79993381ULL, 0x530FF6C5E9F3C477ULL, 0x24498219266C28DDULL, 0x13E59E363063FB5CULL, 
            0x216528813C89D097ULL, 0xF81AFE992A10E36DULL, 0xB4D910FC4452286EULL, 0x681B981A9B1EB6EDULL, 
            0x235DDF36467A7387ULL, 0xBA203D42597ED450ULL, 0xBED4440FD49C2546ULL, 0xC8510018FE302542ULL, 
            0xE967BF53E65C04C2ULL, 0x8D420FDFB68287C8ULL, 0xA8592D17DA4B4423ULL, 0x6E280DE5B89F13CEULL, 
            0xE2D4D13DDF0737CEULL, 0x0407365C7DC5A0E0ULL, 0x4C4788312A9A7C7DULL, 0xDCBFADA4CE2E283AULL
        },
        {
            0x4E7B688852F4B401ULL, 0xAC313C50D17BA0B8ULL, 0x62EFE1CAF5E30988ULL, 0x3FC64F1CFA3623B9ULL, 
            0xCC89A01F429C868EULL, 0x8E664B1F00BE0199ULL, 0xFDC0D5F7F61C818EULL, 0xC00860B7D48B9251ULL, 
            0xC8FA5F8F8E1E523AULL, 0xE7C548FF728A2146ULL, 0xEB68C967B738F0E0ULL, 0x1D141194817C695EULL, 
            0xC15CB4EC5EF01825ULL, 0x9081262A52296F7EULL, 0x4DF9AD362C504EB1ULL, 0x107FB1A6DD335A11ULL, 
            0x76904A686337A025ULL, 0xB686F10F4527AC79ULL, 0x9FED6EF257C95873ULL, 0xF344EC0E968F7972ULL, 
            0x5143DEA0AA53666DULL, 0xF61EF7097C35555CULL, 0x98DA1602503C85CAULL, 0xD43B799648B18B24ULL, 
            0x2E646EFAFBFD20F2ULL, 0x9F4C15096BCB0AC6ULL, 0x7426ABE3C4248025ULL, 0x5228B610790C73DFULL, 
            0x06F9A4F2285176F0ULL, 0x3F6781E44F0C6B2FULL, 0xAADA2A1266EC5A1DULL, 0x363F557AA27E160CULL
        },
        {
            0x47DF9F1D4A8DC5BAULL, 0xA4243D2A9578E348ULL, 0xEE60D2A19403E599ULL, 0xF67359C03935D6DAULL, 
            0x436A81B8D26DD7CEULL, 0xB90E962C64FDBAFFULL, 0x1409B585B338DEB8ULL, 0xD0712B3151C4F08AULL, 
            0x7F1AB074FD6BABCAULL, 0xA392A535C261FF1EULL, 0x6F0EEFBFE371B1B4ULL, 0x92ACCFBC22035D20ULL, 
            0x5A95B7AB7204D0CDULL, 0x3DE14D987530689DULL, 0x8AC5761C9A694B85ULL, 0x10E0ED0279F65FDFULL, 
            0xB2391A6EB39D6B57ULL, 0xC1D0466C7085B7A9ULL, 0xA7960D6AD1607BE9ULL, 0x0758A62557939935ULL, 
            0xC8F93D3CBBDEE0F3ULL, 0x795F0AB53DEAA3D6ULL, 0x22BD28D0BB1D870DULL, 0xD084C74753CAFDEAULL, 
            0x845BEE2648474D5FULL, 0x6518B175F22A659BULL, 0x2E59120DDC89117DULL, 0x1F6CFDDEA831C3D3ULL, 
            0x5FA3386196E0A4E1ULL, 0x0E502A778A888A27ULL, 0xE278DCB11D12A315ULL, 0xF3149FC48F6F99A6ULL
        },
        {
            0x0A068AFECAA1882FULL, 0x22E9617EC776B06FULL, 0x72DCB62370623CBEULL, 0x138F4209D8B4813FULL, 
            0xF229CC7784CE4F6EULL, 0x9735C38D0DD848C7ULL, 0x57A72991999738A6ULL, 0x68A9B0AC2BF0D2A0ULL, 
            0x7159FDADB101EEE3ULL, 0x5A0E1B8D3E271B5AULL, 0xDB2F0CDD60200293ULL, 0x84D796406D975F74ULL, 
            0xA269E5D505F39AFFULL, 0x6369BEEF174834EDULL, 0x414802D39ACC84D7ULL, 0x79F979CAFF292945ULL, 
            0x8E180ECAE3C08261ULL, 0xA40045E6415DFCE4ULL, 0x525A4F2DEAB38D3EULL, 0xBC7D3FE8601310A9ULL, 
            0x00BC25C193C82655ULL, 0x7787F4E58012A809ULL, 0xB4C9AEE607484C5FULL, 0x2FA012081E0A9840ULL, 
            0x42521EA41E6E0401ULL, 0x7957D300FB2CFC39ULL, 0xFAE10C21C63DE924ULL, 0xBD199BF97FEF269AULL, 
            0x817068F955F19775ULL, 0xDA919632EB05CD86ULL, 0x9E6C392645D599B4ULL, 0x1AC28A2C4B14A348ULL
        }
    },
    {
        {
            0xA0BE01215D943E34ULL, 0x1014208BEBFDB30EULL, 0xF19169FC1C2DFA62ULL, 0xDF2BB301BC0B1C53ULL, 
            0xEC2938B1A5BD4328ULL, 0xA4CAD9A8ABA80607ULL, 0x5AF1BBC31FFCB825ULL, 0xA4A1AB09427F8E10ULL, 
            0x6B6FEAA434ADF07FULL, 0x45898969ECAB3C39ULL, 0x398162A20155E945ULL, 0x4B806359D2EF0CB1ULL, 
            0x295D73CF28CCDDCDULL, 0x8C7DEC576742A938ULL, 0xB9E4B6A1FD77530DULL, 0x89B9C8A3C42F1CF8ULL, 
            0xBFE95D14410DD7CCULL, 0x7806D1A7ECF60DD8ULL, 0x5A1FC2B135D168DAULL, 0x6991FF1F4F8898FFULL, 
            0x7225E37CE275A5E6ULL, 0x00B07E04146E3646ULL, 0x31A467F5C2137329ULL, 0x792FCE24F0BC21E6ULL, 
            0x24E59C03F4EDAD2FULL, 0x4488B752B446EECEULL, 0x28CBD5F098C04FA1ULL, 0x00F2796D13286877ULL, 
            0x6901E115A3BA6383ULL, 0xFB0098038B365786ULL, 0xDF4E173BA532BC33ULL, 0x1956757B23CC30B6ULL
        },
        {
            0x79BCF7F03C9E71F3ULL, 0xC9288AD7170E2CC4ULL, 0xCD609932DD0C8A75ULL, 0x146B9F61BCB62B13ULL, 
            0xBCCBB815C6AB58C7ULL, 0xBF7ED915CF20DD9DULL, 0x2EA809499BF32BF0ULL, 0xA52338D54C72EEE4ULL, 
            0x8414A5CA79D14FC7ULL, 0x856C9E4D60815F79ULL, 0x890703B0EACCD392ULL, 0x7A3C5B0275518E62ULL, 
            0xC08EC5A056877CF8ULL, 0xF340927E981BF60CULL, 0xCB73E832FBD56B31ULL, 0xE9944046C5484247ULL, 
            0x774A52FB2B7DDBE0ULL, 0xC87131A57214FB8CULL, 0x756F37B25C22067AULL, 0x588F84F7C64DFCFDULL, 
            0x0FCD7CFD3315208FULL, 0x42303F63CE2D4A69ULL, 0x7EBE76C6318FE7FEULL, 0x4EE7A0EA37AF0BADULL, 
            0x4513440B6C0B7A5EULL, 0x54DDE7D4E7A1A62AULL, 0xFA40DB3C6ED8A2D9ULL, 0x6A7E48D8D792BB1AULL, 
            0x0F02CE806A0DD3B5ULL, 0x9AB423626408CE12ULL, 0x434C93C9B3F5D878ULL, 0x04D275C908E6E638ULL
        },
        {
            0x8E6F05D720349B33ULL, 0x40B5CF7FF5685A1EULL, 0x8D9A6124069BAA16ULL, 0xBA7553254ED1AB5DULL, 
            0x07FFD44CBC20CEA3ULL, 0x38845C4C8E4B722CULL, 0xCAF532313733EA8FULL, 0x9368666BF07517E9ULL, 
            0x7371CC056DD540CDULL, 0xB843FD135288A2CCULL, 0x54D1C58C4277B88EULL, 0x0BEE3DE786DA252DULL, 
            0xFE10D7F412FA9CAAULL, 0x1AF46DBCB5BBEC25ULL, 0x8C9B249DE4E8CBA6ULL, 0xD53B719BF362B429ULL, 
            0x72163003ECE4A317ULL, 0x8EBB0F9D096DEB78ULL, 0x6878ECFE91BAA7E8ULL, 0x0047A9A9B10F3B6EULL, 
            0xDE1A942A00DEE724ULL, 0xF95AA8DAB8C1EC12ULL, 0x9C9E80AC091DBE13ULL, 0xD72EFA0B28CBA038ULL, 
            0x9AB92590BE742CE6ULL, 0xDEB09F67A85EE655ULL, 0x0C0E237542364160ULL, 0x19A2548DFE65119BULL, 
            0x9F5DD00E50A6A4F3ULL, 0xBA8013447E8997F1ULL, 0xFCACF489D479BDEFULL, 0x3104B004AA2AC15FULL
        },
        {
            0x770010FFFDAAF650ULL, 0x7D67FF2095A2CE42ULL, 0x4B07619B1D892319ULL, 0x912EC7A40D656CB2ULL, 
            0x2E1525736162BFACULL, 0xD0E92B2E5FA16247ULL, 0x51135AA62FFE5AB5ULL, 0x0D3BE03CDCFAE7F6ULL, 
            0xC559E60A9B261B5BULL, 0xC37B81C341349C16ULL, 0x8530A5C97D02C81AULL, 0x8B7487AF68DCF947ULL, 
            0x597689276B65FE94ULL, 0x0AC8A43953AE55A5ULL, 0x2EFDE6F3184F4B05ULL, 0xE3367E0654866DCDULL, 
            0x0574827E71291393ULL, 0x07A89B6A485199C4ULL, 0x5C73502AA8101A3DULL, 0x85169E1288EA86A7ULL, 
            0x76215E7BC0635DE3ULL, 0x864819DBC838EB4AULL, 0x54CDE2D21532C3DDULL, 0x18279505D284250EULL, 
            0x466143F2F378E094ULL, 0xD15982FAAB4A06CCULL, 0x5DF868985D458713ULL, 0xE854A1828C12EC11ULL, 
            0xD5C84333DFF4DA6FULL, 0xE5FEBC591CB3E256ULL, 0xF01C890A8A772F63ULL, 0xC95276904E48A6BDULL
        },
        {
            0x7C4BBB51574AD4D9ULL, 0x4CC2EEA2055D875EULL, 0xAA1E0E486F31AD37ULL, 0x0C78212C67F7DABDULL, 
            0xFE6692D5F0EB9399ULL, 0x29E97D709F76A81BULL, 0xC74D92583B39961FULL, 0xB1AD16CD4F3E9ECAULL, 
            0x0B56A35467BA1EE7ULL, 0x8AEF1963869E0D97ULL, 0x406E81E9CB5E78B4ULL, 0xB66A359FE1FA31F5ULL, 
            0x0BEB9F0D6EB264BCULL, 0x609BF804359504B3ULL, 0xCC92325DF6E04B09ULL, 0xCD7CB1B4B22A75C5ULL, 
            0x3D9411EBDB8824E8ULL, 0xE4DED31A056C00FDULL, 0x78AAB815FAF3FEA9ULL, 0xA320F8790E67E2F3ULL, 
            0x9347680401746152ULL, 0x76A0BAD940719B68ULL, 0xBC2501DA83207958ULL, 0x91FB2EC50C99A270ULL, 
            0xC393F655B9AAB0DDULL, 0xCF2A8BA525350F2CULL, 0xB7727158229C4E01ULL, 0x4E5D57D1E8C1CAB0ULL, 
            0xD6F948C94049FCC1ULL, 0xD6971B6CB89536A0ULL, 0x1B708B3B9E8C282FULL, 0x1F80DCD07AAE6CCEULL
        },
        {
            0xB47A07B48ED6F14AULL, 0x5AEBC7AA438E8884ULL, 0xF8382FF784D0D9F2ULL, 0xCF24A67BFF3E7C62ULL, 
            0xEF154F0EFA3373EFULL, 0xA3E7CD7C997EB874ULL, 0x673960CCE4411285ULL, 0xADE6C4EF1AAB00F5ULL, 
            0x4A100C502C996789ULL, 0xCDFA5912CCC12EB3ULL, 0xDC87B1FFC2D5C8AEULL, 0x9F0031F833EB6F1FULL, 
            0x97E231B5FFC6793DULL, 0xD61702430979CA80ULL, 0x56DFF7D5142ECB35ULL, 0xC9926341C250F54AULL, 
            0x5299CC71E7F775BAULL, 0x4AC9CCF2113EFA43ULL, 0xEE600E0C6EF69E88ULL, 0x8C38FA74718FA2B1ULL, 
            0x5852B52195F2C9A3ULL, 0x42D38FDD6880CD87ULL, 0xD68E5E78D075B078ULL, 0xF0F38E15C9E13F78ULL, 
            0x93E0CBE566A128B0ULL, 0x764B8BEE4C29DF9AULL, 0x5546258770B7C773ULL, 0xE154649ACA2EBA93ULL, 
            0x48D0A3CECF3DCA90ULL, 0x49D542DD56E72520ULL, 0xB39F27F4BB39D64CULL, 0xB60874091889E85DULL
        }
    },
    {
        {
            0xE4B64EED17D07123ULL, 0x1A61CAF605438A44ULL, 0xA42D543AF6CA0BAFULL, 0xF69F5802A0669957ULL, 
            0xA33C36D4420F6163ULL, 0x731E244670A3C83EULL, 0x7F580CE0D59EFCA1ULL, 0x7198673C413CC6D6ULL, 
            0x0E10464347E488BEULL, 0x39AA10ED0EFCA4C3ULL, 0x90BDEF8929A2B9B1ULL, 0x09999CEC14E53E5CULL, 
            0x1691024C8A65B4B5ULL, 0x9E35459C9D1319D8ULL, 0xA7048EE73977A628ULL, 0xB3F38441C4CEC5ADULL, 
            0x7F789B41E7135BF5ULL, 0x3977AA0611B6FE9CULL, 0x0B7B65C4F251ED0BULL, 0xA9779ECEB6AEC23EULL, 
            0x93F15FBC914F53DCULL, 0x7DBD3445A5585332ULL, 0xC0E7F785AA5FF078ULL, 0xE04076421B080539ULL, 
            0x1C6F9B769743BFD9ULL, 0x17602B558A02A185ULL, 0x2421DCE51A28CA15ULL, 0xDFE5CAB89707FC5AULL, 
            0x902C346B2971AD8AULL, 0x325B14E5457F0F8DULL, 0x532DEB446DFCE335ULL, 0xD21C8E1F38BAE8A4ULL
        },
        {
            0xDC9F49316F847D8CULL, 0xDAE361E5C29C715CULL, 0x5E8202DC8DF7F2ABULL, 0xB03720BE7BFEE31DULL, 
            0xCC52176B90E9A071ULL, 0xE5B56C79BC043DA4ULL, 0x53721FEAB5BFC840ULL, 0xE68444944C758B2CULL, 
            0xEC5951BBAF479DA2ULL, 0x864A6423226AF566ULL, 0x0A9F83B88E751C23ULL, 0xD769110C3C5C2728ULL, 
            0x2A2D9C71C78E2293ULL, 0x49307338453304FAULL, 0xA4BCAAB8CC6D9FA9ULL, 0xC2F835775C8E1D84ULL, 
            0x4217004E6C8CC2BBULL, 0x67A07452A1F8A1D9ULL, 0xC385FFD37CDC1482ULL, 0x8644719EFC096612ULL, 
            0x8E4792CFB15C4C32ULL, 0x9F5E85846812AD18ULL, 0xF268D9AE69A58815ULL, 0x86843400F1107428ULL, 
            0x1A079057332F171CULL, 0xF50D7570B9DE2DB7ULL, 0x27032788BB5F30ADULL, 0x90EC225C13479EBDULL, 
            0x63BAA09F0F69861EULL, 0xF54B0B7FFF253554ULL, 0xD7D3CB47EF8EFB8BULL, 0x5CA68C057FC8F62EULL
        },
        {
            0x359CA1FED964BFF9ULL, 0x2E2ECE40375592DAULL, 0x7A68D6851275219CULL, 0x13CDEFDCD6A31D50ULL, 
            0x0D499AECAD8EF0A8ULL, 0xC42E096A53094247ULL, 0x354290C5A260ED9BULL, 0xDB53E87824FCE581ULL, 
            0x3E75735B7286E12BULL, 0x8735AEB5DFBD7FDDULL, 0x4059DC2E79039E1CULL, 0xC135158E05C63CD0ULL, 
            0xFDB6E280256A4513ULL, 0x09F7F4D0C330EDBFULL, 0x3E1F102AD4A7E289ULL, 0xA3E0B0871347C063ULL, 
            0xD578938BE2222688ULL, 0xC58211B41D0BFA60ULL, 0x489421D13C9767ABULL, 0x6F6F557557F18544ULL, 
            0x5FEC9C7AA3BC7C23ULL, 0xEB191522058890BFULL, 0xA5738F77A7E645A6ULL, 0xD8860AEBFF76C903ULL, 
            0x381E597E5848A463ULL, 0xD1339E79025C5821ULL, 0x9D9907483230A395ULL, 0x8BE270F791713554ULL, 
            0xE1E7570D307276E5ULL, 0x6B56A47C7A0304B6ULL, 0xA5C4D022677CAFA1ULL, 0xED2DC6B71E216CAAULL
        },
        {
            0x1EF29DC772E1F2F7ULL, 0xDDEA50598D582212ULL, 0x1C278EA44289A610ULL, 0xC5815128FBCF99A4ULL, 
            0xB636D20FF02891B5ULL, 0xAE62774B0F80DF0BULL, 0x58000962D2120DE7ULL, 0x79A416EB8B27F4AAULL, 
            0xE54CD55BEF6461DCULL, 0x3D16C808AADB8418ULL, 0x3AA4A3CE36130121ULL, 0x76DB583041DC448DULL, 
            0xFF30EB5CE76BF038ULL, 0x8ACEF4E5676A6A9CULL, 0x039F38D7E5DFD589ULL, 0xE8F6507BA9FFE5E6ULL, 
            0x798CD7716B8E84E1ULL, 0x07AA653D0E45E840ULL, 0x9AC1AF2689B94235ULL, 0xA6E3419F3A69AAA0ULL, 
            0xC489F6FBF982546CULL, 0xDF72749CFA84787DULL, 0x3F5E8ED6B588C096ULL, 0xA7C9CDCF9617FFC7ULL, 
            0xA3D1A4E50C989032ULL, 0x6A446BE569497473ULL, 0x8A65A07D4E9BF30AULL, 0x02795FFB52834EE4ULL, 
            0x2C86D33BF3966DC0ULL, 0xFDBCAE38D7F40593ULL, 0x1DC1BB778FA68A6CULL, 0xB809286EB52334B2ULL
        },
        {
            0x1C69A8C6A60F3895ULL, 0xB994CF5A64A18CE3ULL, 0x28C7F65C7FEE391EULL, 0xA7A95586B2C8B8D4ULL, 
            0x130059230CF7F1B8ULL, 0x20DEBED043D26875ULL, 0xB085F9533B895C33ULL, 0x6BC51AE8D83F7E56ULL, 
            0x944C6DDE4162CE9DULL, 0x62D5EC6E0D4D3B23ULL, 0x95ABC4069E26AB80ULL, 0x337ECC11A0397603ULL, 
            0x325319E9F390FE60ULL, 0x92E392533D853C0CULL, 0xB7DA259CB5644BA3ULL, 0x1C448991280155EEULL, 
            0xF9A9E82C7DBB3330ULL, 0x43989EEE751BA24BULL, 0x0619EE27FDA494A4ULL, 0x7089AB3805218F56ULL, 
            0xF6F4E34A28B873ADULL, 0x107EF96803D88E4CULL, 0x70F33985B88B6DE9ULL, 0xC6EF609C17EEF5CAULL, 
            0x215B4E23EADA0200ULL, 0x16C0BEFF84416640ULL, 0xC22C1E36432DD670ULL, 0xE64B3A21CBD47393ULL, 
            0xE76016C067E49B80ULL, 0x68220CDAEBF8524CULL, 0x2ECC431820ABC78EULL, 0xFC5DFFDF35113AF5ULL
        },
        {
            0x653DAC1ED5575806ULL, 0xBFA11505E5BF6720ULL, 0x2E86CB5603EE3ACAULL, 0x2EEFD6DC35199321ULL, 
            0x7BE3CF0A12594774ULL, 0x7A66165D964D77F2ULL, 0x490852EB93731CC0ULL, 0x1418BCF908CDF926ULL, 
            0x9815A4D031E5D7E3ULL, 0x04AD88FDC75A7A0EULL, 0xA19398ADD92759E4ULL, 0x3C93390E249FBE79ULL, 
            0x584640705C5F0A13ULL, 0x598BEEF4842B05CAULL, 0x0E46DA17E709CC54ULL, 0x6A76A5C384EBD95CULL, 
            0xAAE51021F0577295ULL, 0x2C62E144CF671137ULL, 0xA95D260E277F2336ULL, 0xA61C10C267F128F7ULL, 
            0xA61B474BE389A344ULL, 0xDB4135A43485D8D1ULL, 0xB38E8FC7AE1236A2ULL, 0x78402B83E8B51280ULL, 
            0xA232F1CEC323FAD9ULL, 0x7E6C90A753271376ULL, 0x08F75991B7ACF268ULL, 0x6DE6F0128CEB13B4ULL, 
            0x19B544C7EB3FBCB3ULL, 0x7FBEA9A1D4E9CCC0ULL, 0x31B20D70B37D83AEULL, 0x31383F2C37A7E690ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kTwistConstants = {
    0x900050D861B8F62FULL,
    0xA130DF595E27FA22ULL,
    0x56A6EA61AB6A391EULL,
    0x900050D861B8F62FULL,
    0xA130DF595E27FA22ULL,
    0x56A6EA61AB6A391EULL,
    0xB3676C91D579FC71ULL,
    0x76CF8638D2A2AC6EULL,
    0xA8,
    0xB2,
    0xCD,
    0x79,
    0x84,
    0x9D,
    0x6B,
    0xD3
};

