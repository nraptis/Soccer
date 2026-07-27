#include "TwistExpander_Canopus.hpp"
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

TwistExpander_Canopus::TwistExpander_Canopus()
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

void TwistExpander_Canopus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8602F87ED160C57CULL; std::uint64_t aIngress = 0xC13AEA06ED6D912AULL; std::uint64_t aCarry = 0xDF30E66F17C3E593ULL;

    std::uint64_t aWandererA = 0xA9D1EE54F96A2D25ULL; std::uint64_t aWandererB = 0x9545259194B27E49ULL; std::uint64_t aWandererC = 0xD6E7554ECA5EB274ULL; std::uint64_t aWandererD = 0x907396CCF53E1759ULL;
    std::uint64_t aWandererE = 0xA1F097D1DAE5011FULL; std::uint64_t aWandererF = 0xA39239F0554D4D33ULL; std::uint64_t aWandererG = 0xA1ED74A4653C818DULL; std::uint64_t aWandererH = 0xFA214BF96A1051FDULL;
    std::uint64_t aWandererI = 0xBFB9ECED1B6A4A7BULL; std::uint64_t aWandererJ = 0x9365277AB258B83EULL; std::uint64_t aWandererK = 0xBDA0660F0FEED316ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC13D32411EF024E4ULL;
        aCarry = 0xB2D875BFFAA30524ULL;
        aWandererA = 0x83287B3353BCD071ULL;
        aWandererB = 0xE344E3875877490FULL;
        aWandererC = 0xF95FFFB70CE5F0EDULL;
        aWandererD = 0xC854F4CCFE8FCA79ULL;
        aWandererE = 0x98C1F071C606C2E1ULL;
        aWandererF = 0xB776DED8F5B68511ULL;
        aWandererG = 0xB8DE7FECB0F71C88ULL;
        aWandererH = 0xFD1CD80D73954974ULL;
        aWandererI = 0xC11BF399A6231BBDULL;
        aWandererJ = 0xC85B1C0303551F81ULL;
        aWandererK = 0xF866C042CF8FB22DULL;
    TwistExpander_Canopus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x89607D201B6C5803ULL; std::uint64_t aIngress = 0xF3AC80E379A21A56ULL; std::uint64_t aCarry = 0xFFA7C1B470EFE7BBULL;

    std::uint64_t aWandererA = 0xBF32089195F6792FULL; std::uint64_t aWandererB = 0xB8054AB34A58C2A2ULL; std::uint64_t aWandererC = 0x8CEBB0B879CDD0A0ULL; std::uint64_t aWandererD = 0x95553B493FEC6598ULL;
    std::uint64_t aWandererE = 0xEE0C21ED42EE59C2ULL; std::uint64_t aWandererF = 0xE148BD01329D9A52ULL; std::uint64_t aWandererG = 0xFA5EACFD776852E7ULL; std::uint64_t aWandererH = 0xA423A89E131B264FULL;
    std::uint64_t aWandererI = 0xC5D98E017BDC2FBBULL; std::uint64_t aWandererJ = 0x8714C8B57577E896ULL; std::uint64_t aWandererK = 0xF8350024C34EA811ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE0AF005990C91283ULL;
        aCarry = 0xA1A788E0403FD946ULL;
        aWandererA = 0x8CC6D68AF4D646D5ULL;
        aWandererB = 0xFB2C00C2611E4ED8ULL;
        aWandererC = 0xFEF38FCEA0DECF49ULL;
        aWandererD = 0xB08CEEA54E0B6B17ULL;
        aWandererE = 0xE5F3AEC55AC0E534ULL;
        aWandererF = 0xAEB224ACBAA5B958ULL;
        aWandererG = 0xF4C19D48032900FDULL;
        aWandererH = 0x96D461AE16AB631CULL;
        aWandererI = 0x9CE51C91F7CD508DULL;
        aWandererJ = 0xCF2A79EBA51AFD88ULL;
        aWandererK = 0xED50ED9794C76ED8ULL;
    TwistExpander_Canopus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC1F36CD9F57DC122ULL; std::uint64_t aIngress = 0xF2204F061A8DF509ULL; std::uint64_t aCarry = 0xB3160EE6BCFA2E40ULL;

    std::uint64_t aWandererA = 0xE85C01BD7B42F075ULL; std::uint64_t aWandererB = 0xF9FCA263637C8F78ULL; std::uint64_t aWandererC = 0x87C7FFC130E4C2D7ULL; std::uint64_t aWandererD = 0xE6E4EBD6BE6500CBULL;
    std::uint64_t aWandererE = 0xC08BC4CB686AEEA6ULL; std::uint64_t aWandererF = 0xC0730E0FC3754510ULL; std::uint64_t aWandererG = 0xB8D6A91E427779A2ULL; std::uint64_t aWandererH = 0xDDFA9DF54AD01355ULL;
    std::uint64_t aWandererI = 0xF27AA9EA17FCCE42ULL; std::uint64_t aWandererJ = 0x9FB80AB1567689CEULL; std::uint64_t aWandererK = 0xDB35F609B959C222ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE8AE6CC077152C11ULL;
        aCarry = 0xE11CFE2CB14C02BAULL;
        aWandererA = 0xFDC70F1AE05E9759ULL;
        aWandererB = 0xC321A5D57272B122ULL;
        aWandererC = 0x8E3E0BA12F5CE6E1ULL;
        aWandererD = 0xE347474E4704C265ULL;
        aWandererE = 0x9805CF77ECAED91CULL;
        aWandererF = 0xD97F06D922B92D4CULL;
        aWandererG = 0xA0EE527BDAFFAE5AULL;
        aWandererH = 0xF4FCDF45A545B03FULL;
        aWandererI = 0xC472763A6EF2075BULL;
        aWandererJ = 0xA0E85F7A8103F2AAULL;
        aWandererK = 0xFBB7BA6450C132ACULL;
    TwistExpander_Canopus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA65DEF847254F47CULL; std::uint64_t aIngress = 0xDC7DB8A1B19A4B76ULL; std::uint64_t aCarry = 0x817DAE4A0D82510DULL;

    std::uint64_t aWandererA = 0xC61A5C79FC50C62AULL; std::uint64_t aWandererB = 0xCF6F65AC83070DD1ULL; std::uint64_t aWandererC = 0xAA361C41045DB4FEULL; std::uint64_t aWandererD = 0x9D802CF89321893EULL;
    std::uint64_t aWandererE = 0xAC2B01EA70246993ULL; std::uint64_t aWandererF = 0xE70C97D6318D77D7ULL; std::uint64_t aWandererG = 0xA13E2BBD4B2BA224ULL; std::uint64_t aWandererH = 0xC92AFDA3B4F1BFF4ULL;
    std::uint64_t aWandererI = 0xA15538233E93DB80ULL; std::uint64_t aWandererJ = 0xCB830BAA24D12E2BULL; std::uint64_t aWandererK = 0xA54FB251664B2B48ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD3F37EB7638955FFULL;
        aCarry = 0xB746DCDD7BFB2D69ULL;
        aWandererA = 0xBA99EDA897AEF6F8ULL;
        aWandererB = 0x8FD9F59164A817BCULL;
        aWandererC = 0xBB52C3BD87DC96C7ULL;
        aWandererD = 0xAC8513CA90CEEF1DULL;
        aWandererE = 0xCBEC02B0B0FA6C3CULL;
        aWandererF = 0x8FE87E2B5667EFB9ULL;
        aWandererG = 0xE9C656DB7642302DULL;
        aWandererH = 0x95F343776D52E38FULL;
        aWandererI = 0x8A9FED1A78434A00ULL;
        aWandererJ = 0x96250C6107697223ULL;
        aWandererK = 0x83BF9C8BE27E408DULL;
    TwistExpander_Canopus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Canopus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE1535404545E6BBDULL;
    std::uint64_t aIngress = 0x831D66BAAA2E3828ULL;
    std::uint64_t aCarry = 0xF501F26D563D5B1FULL;

    std::uint64_t aWandererA = 0xC74473C391BB9C71ULL;
    std::uint64_t aWandererB = 0x9FC42F65DB86B0E1ULL;
    std::uint64_t aWandererC = 0xD02F3C54FF491FF1ULL;
    std::uint64_t aWandererD = 0xF915E637FC4657DBULL;
    std::uint64_t aWandererE = 0xDB73D7D6FA98208AULL;
    std::uint64_t aWandererF = 0xCAB0740C030E9171ULL;
    std::uint64_t aWandererG = 0x943F2A10CC5D0C1CULL;
    std::uint64_t aWandererH = 0xA77B66AC03A671F0ULL;
    std::uint64_t aWandererI = 0x988D9B240D6CC74AULL;
    std::uint64_t aWandererJ = 0xC2CCB361E7080EE6ULL;
    std::uint64_t aWandererK = 0xE054C1087A36D994ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    TwistExpander_Canopus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KEY(pWorkSpace,
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

void TwistExpander_Canopus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBF30D0049320EBAFULL; std::uint64_t aIngress = 0xEBF1F2D720467F15ULL; std::uint64_t aCarry = 0xD68D436105416F87ULL;

    std::uint64_t aWandererA = 0xF0021247C27FB699ULL; std::uint64_t aWandererB = 0xA8444C5AEB864116ULL; std::uint64_t aWandererC = 0x980846890AB4E3D0ULL; std::uint64_t aWandererD = 0xBA7B1D1D535D8CC1ULL;
    std::uint64_t aWandererE = 0xB3B9ED217A0277D3ULL; std::uint64_t aWandererF = 0xEE689A5A89A9D76EULL; std::uint64_t aWandererG = 0xF31C45D82A93BBD0ULL; std::uint64_t aWandererH = 0xEC2E605C85796900ULL;
    std::uint64_t aWandererI = 0xD8994F25B6079E4FULL; std::uint64_t aWandererJ = 0xE4C3234F6F0360B5ULL; std::uint64_t aWandererK = 0xE5DFD5D771C4AEADULL;

    // [twist]
        aPrevious = 0xB51D95E1420AF72FULL;
        aCarry = 0xE00672EF8FEED3CCULL;
        aWandererA = 0xA4B32EAF45617B31ULL;
        aWandererB = 0x851C267E3D2B0784ULL;
        aWandererC = 0xA401035676EF9E61ULL;
        aWandererD = 0xF36FE0AADA82D95DULL;
        aWandererE = 0xCEFD4D3D2D674396ULL;
        aWandererF = 0xDEA891A073CAD305ULL;
        aWandererG = 0xB32A3917E69015B7ULL;
        aWandererH = 0x8AD5305B58D1C5BEULL;
        aWandererI = 0xCAAE55C97E9C878BULL;
        aWandererJ = 0xDAE67A50D26D90FAULL;
        aWandererK = 0xBAA406905E257584ULL;
    TwistExpander_Canopus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Canopus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Canopus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Canopus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 14 of 33
    // Exploration cases: 0
    // Structural maximin 517 / 674; family total 6965
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1510U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 14 of 33
    // Exploration cases: 0
    // Structural maximin 521 / 674; family total 6986
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 430U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 14 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1064 / 1248; total 14018
void TwistExpander_Canopus::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 14 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1066 / 1248; total 14143
void TwistExpander_Canopus::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
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

const TwistDomainSaltSet TwistExpander_Canopus::kKeyRotateSalts = {
    {
        {
            0x65AE25F836A372AEULL, 0x76E8B5E0AD0482AAULL, 0xFA07EF3C13B7D40DULL, 0xE8E2B2596B721888ULL, 
            0xA90BAC9DFD074EC2ULL, 0xC992A67CCE2CEDF8ULL, 0x3D9178FBC370A9DDULL, 0x90E76F3909E29856ULL, 
            0xFF508A8B7F342AD5ULL, 0x432E074444654C27ULL, 0x0476D651E706FA2BULL, 0x1B99E9E989283CFEULL, 
            0xA7BEFF7F835DEE76ULL, 0x67D44F969781EC04ULL, 0xFBCBD83A92C90151ULL, 0x65C9B35C24A11D39ULL, 
            0x4125AC7DC8444457ULL, 0x362AD36FCC83B8FFULL, 0x5D9C2C55AE2AA21BULL, 0xCF15DEDEEF597CC9ULL, 
            0x36B35C0B8A4DF1D2ULL, 0x548E991C7C8B6F9CULL, 0xFDCC254BBA06439FULL, 0x244C179C926941CBULL, 
            0xB0B69E4A66C36EAAULL, 0xC3752E5BBEABDFD7ULL, 0x5DC5111D28041422ULL, 0xBE7DAEA55DE56797ULL, 
            0x6A38B399EE2BC7DEULL, 0xAA65B34F4C5FE474ULL, 0xD0D067A619E0DDCBULL, 0xC25FB37138532561ULL
        },
        {
            0x5DE17C5C9DBE2400ULL, 0xB90D9EFEE6CC4D71ULL, 0x2D6B1EADAE84E9ACULL, 0x80F7E0027E4BB67FULL, 
            0x3BDDB6EE8ABC0074ULL, 0x715862E7974C8732ULL, 0xD31E06430E3A0922ULL, 0x50322777557268BFULL, 
            0x527AEF4BC8F73033ULL, 0x409C25F16A6B0EE2ULL, 0x7197D7C7B6041EC9ULL, 0x72F558E92614C19DULL, 
            0xEA82B0D5950F2213ULL, 0x10817C14B8710590ULL, 0xBE8220C350465602ULL, 0xD3E80B060DD73316ULL, 
            0xE742FEEDD063F8B2ULL, 0x8718B194DE7C1B5DULL, 0xC7AE025E75C4BE74ULL, 0x3DCB540B80ED08F7ULL, 
            0x514735B7BE9984CCULL, 0xA6F60928F10CFB50ULL, 0xC5C4818CCA43D253ULL, 0xAFD6FDD1A20D638DULL, 
            0xC3EC4268192B8E48ULL, 0x965C6ED5E0BB726DULL, 0xDB3E996F7A6DB499ULL, 0x9D4483D253F88F70ULL, 
            0x47A2F54FDFE5303AULL, 0x4458C353EE17E435ULL, 0x916AAB4352ED7D45ULL, 0xB235CC31BAA043C0ULL
        },
        {
            0x245493AFC2C24B26ULL, 0x3FE48B3E702E7467ULL, 0xC8A886F16FEAFA9EULL, 0xAC617D4F9A16A588ULL, 
            0xC2D67C0FB04569F1ULL, 0xB5375672EA644484ULL, 0x37AF4A836B71DB28ULL, 0x51F78D370F8D9053ULL, 
            0xE3217012CDB199D3ULL, 0x73666D6B5FBE14E7ULL, 0x1E50C81A19AA21C9ULL, 0xF0747E7E51FD1798ULL, 
            0x74BA2943C28A3025ULL, 0xC001C21EAA04C408ULL, 0x098AB64187FEBF12ULL, 0xF29DC19C1A6ECF72ULL, 
            0x76BAC913A598F619ULL, 0x82211957A3130C72ULL, 0x6DBE310D549499EEULL, 0x1E1E243E0A827E7AULL, 
            0x0549716D4574A14CULL, 0x8D5C7724EA8E82B1ULL, 0x3F2F93F59BE6BB62ULL, 0xBA7832576C1DF899ULL, 
            0xD72E34BFDE782E2DULL, 0xE55654E72AAF4EB6ULL, 0x61DF711F9733E4F0ULL, 0x64E7B3D0B398D1F8ULL, 
            0x814BFA77F970E817ULL, 0xFE32B51CEC029BFEULL, 0xAD34E8A8D0FAC3B6ULL, 0xCAEB6C46629F5762ULL
        },
        {
            0x4EB17E23459FAA69ULL, 0x853170F076FFA42BULL, 0x7B84F5434F5E5319ULL, 0x336773B538C9410EULL, 
            0x1BA5DF0C1D2C70F2ULL, 0xEBEB2298F8AD9C5FULL, 0xF79EA24EAB139612ULL, 0xE0DB17E2AA5431B5ULL, 
            0xD2C028B96DA8FAD3ULL, 0x89A26F3119D57A61ULL, 0x5C6E588F11928881ULL, 0xE32BCCF418653F6DULL, 
            0x6F1511997B44F210ULL, 0x5114041A85CDFE72ULL, 0x29DC631707471935ULL, 0xDBF38B7059EE7458ULL, 
            0xF09EAED2550DA142ULL, 0x42F02711F1D1596EULL, 0x7ACB4D020D6D8287ULL, 0x3E5E45D223A7B5C1ULL, 
            0x5D55E24E0D402C73ULL, 0x479A6B41AACFBDA1ULL, 0xF340F950E0DC62F1ULL, 0xB5186A8F58D58E8BULL, 
            0x704637EFD4F1782CULL, 0x0EBEC20556120EFBULL, 0x3EFE61A97563E132ULL, 0x72B1760BAA2B3A6BULL, 
            0x164A405930717A1CULL, 0x8542222D784DF483ULL, 0xB3A89B8881F15969ULL, 0x6B12AABB5B9512DBULL
        },
        {
            0xE24C5FC80837530FULL, 0x413BFBF50CCBCF8BULL, 0xE02088CE3EE26752ULL, 0x5E29A638E10CFF98ULL, 
            0x6F78AA25CA6DD01DULL, 0x0B8C0F80E47E88AAULL, 0xC6A225C241FC947CULL, 0x449F98A2DB405B32ULL, 
            0xDA3FE91046B5212BULL, 0x68CB0D02112F18BDULL, 0xDF77056D44307DF2ULL, 0x8AFC90D7677D8E8EULL, 
            0xD24797B188B0408DULL, 0x6187553AC8FD4461ULL, 0x6555A97BD7753D17ULL, 0x179CFD482C0776F1ULL, 
            0xB4B17ECBD1521E72ULL, 0x2610EC96A4275EF3ULL, 0x94170E32F2748F72ULL, 0x07A3579386B18E55ULL, 
            0xF18A1917A0618BE8ULL, 0x0724A0638598349AULL, 0x263A48671BC9E808ULL, 0xE9206188E21D7755ULL, 
            0xBA0DE49B754FB5E4ULL, 0x8CF99988B64C228AULL, 0xD03A6784BAF75907ULL, 0x3507A15E02CB437EULL, 
            0x53113CEA33409EF3ULL, 0x559BB09D6507A36CULL, 0xA28AEA059AAFFE2BULL, 0xE2F4F7350704CCA6ULL
        },
        {
            0x184F6278337F4B45ULL, 0x40730EC5A09CB192ULL, 0xD605DD4E72287548ULL, 0x5DA168649E2E2E54ULL, 
            0x123626EAAA19D7B5ULL, 0xC05015DB4481E17FULL, 0x6F6F04A09DC1E118ULL, 0xB507A1B170FFA0AFULL, 
            0xCBB179CC97467973ULL, 0xA45C12E998DA5DE8ULL, 0x840B815234303442ULL, 0x1DE61D123D991D13ULL, 
            0x7336E749AA7FDB89ULL, 0x7605CAC47764D0D3ULL, 0x24E5F080B4C07596ULL, 0x1032AB0797CACEE0ULL, 
            0x437867F82B1AAD90ULL, 0x585FE2DA3C0B0FFAULL, 0x7B756493952C5B5BULL, 0x394311D3CA5B3E07ULL, 
            0x7703A20BBD79886FULL, 0xBD61CE2A388001F2ULL, 0x83EB4925BF3074E8ULL, 0xBD06E0C201E6C1AAULL, 
            0x449C6ABEE26979BCULL, 0x9F603FE85992179AULL, 0x249CBF917C0B3E4FULL, 0xF2015738F9F4A82EULL, 
            0x0F8A6B8F18CC6968ULL, 0x14F3B1D607AF3E92ULL, 0x28E42E217099764DULL, 0x6BC6683F928EE264ULL
        }
    },
    {
        {
            0x16D01A0B4BB87C80ULL, 0x41FE5C180034B210ULL, 0x07F37FA48CF41F10ULL, 0x8B81B8704515F65CULL, 
            0x5C2C16AD56CE6E93ULL, 0xF107E4A41F8FCA17ULL, 0xA82D1A66A6FE91B7ULL, 0x9062807C76DFF1E0ULL, 
            0xAAD597505D13F19CULL, 0xAEDDA9DE6306FBA8ULL, 0x82B00D1894011172ULL, 0x457858647F8CF3BDULL, 
            0xB9EC235341D8E8B3ULL, 0x7AB87D1A240AF4BEULL, 0xC660D44725F6527DULL, 0x45FB599E3960419DULL, 
            0x3971422BF90EEFD4ULL, 0x74DBE560A54E04E0ULL, 0x21BACBF6C0E87860ULL, 0xD2F7B370A9F9A001ULL, 
            0x72B3CE732D41187FULL, 0x9861C6A28BDDD772ULL, 0x6BC4120CAA080D60ULL, 0x907349713FA52F0CULL, 
            0x48E6B0241345D136ULL, 0x379FC0208C806E3CULL, 0x9E55AC19357EC980ULL, 0xC848C6C490F4BFABULL, 
            0xDB8B28D40822127BULL, 0xCAAEC39DE521E195ULL, 0x174730DD761AEE72ULL, 0x7C4FB8E3D7DE35BBULL
        },
        {
            0x520FD9CB2E771A87ULL, 0xED0D63D09FFF99B0ULL, 0xDAE670732C477B56ULL, 0x852EDE6D7FC4DBD4ULL, 
            0x6E444E3163296FC2ULL, 0xE9FC3CBF758766CDULL, 0x002BD145F0840431ULL, 0x3E92146F8E4C8344ULL, 
            0x04046A6FFE6A8799ULL, 0x71122BD9023C716BULL, 0x345A174F9249FF39ULL, 0x9821CE94F2877203ULL, 
            0xB36E8560A9AA520EULL, 0x72382EE9C3B12BC6ULL, 0xF7A754E874AB0726ULL, 0xD59B4136E00CDA43ULL, 
            0x252B299D744F9640ULL, 0x24DC9071A13C9AB0ULL, 0x8DDEBD49EFE93BE6ULL, 0xE00526C9EED1E007ULL, 
            0xFAF68EA7B2AAB53DULL, 0xF89461532BCC5390ULL, 0x91B1C5A3E3ADE296ULL, 0x251016769EA4CE6FULL, 
            0x1DAE60C3064BE3A2ULL, 0xD9D67F3BCED0842CULL, 0xD9C2D0CCDB77BA05ULL, 0x35D15C7AD46BA2E0ULL, 
            0x922AAAD0498A5FF1ULL, 0x9C6CA4B9B018F8DCULL, 0x042EE59E8EEBE84CULL, 0x7D0E335696C9AE57ULL
        },
        {
            0x8F1DC701687E4693ULL, 0x1B8EE47B04B84BDDULL, 0x4B57B76F907F6B1DULL, 0x787FB7A37B3F37ECULL, 
            0x28B37FC787FC505CULL, 0x905161B99E80FBD7ULL, 0x76B1624A6CE91504ULL, 0xD5EAB6DBE8BD4693ULL, 
            0x5B268DA4DE0236DCULL, 0x9B091E4C7DAB9A29ULL, 0xEC62A003C639813AULL, 0x8F2952F47814CA3DULL, 
            0x14BF429F968BD0A8ULL, 0xF9CE0973E097C303ULL, 0x91FE5257A970EADAULL, 0x5760E85C6439F4B7ULL, 
            0xE61DF99BA8E5F84AULL, 0x0A2572BB6BEC6A02ULL, 0xD6810DAF0553C623ULL, 0xCF4F996345019028ULL, 
            0xB595B8EC1ED75206ULL, 0xEE4958098B51D2DCULL, 0x745E8E030318A8F2ULL, 0xB73FB3F7A38C0019ULL, 
            0xB58E8E52AA48B821ULL, 0x5C23DD09071A35A9ULL, 0xEAA66C98FBCDAF4AULL, 0x960D27D5ADB4E66EULL, 
            0xAB64409177B35EABULL, 0xCFC7AB5C573BA138ULL, 0xCD0448A2C3EF8C25ULL, 0xAFC14F94E5BF4501ULL
        },
        {
            0xB559667921F38616ULL, 0xCB123CD38ADAAB6DULL, 0x9A4DA75483D17065ULL, 0x32CC52AC2323BCDFULL, 
            0x7E4D89DBD839292DULL, 0x8C126E183E109E5AULL, 0xE102B2D4787EA7ABULL, 0x9B606A957D5509F1ULL, 
            0xA0C25E9DE20E943AULL, 0x63C97058A0EA70C6ULL, 0xE3B2339E7F1C35D9ULL, 0xFEB5478A1ABDB894ULL, 
            0x1CB1F01BDADBB7CEULL, 0x92052B23AE38DE7BULL, 0x2F3992B7737548B3ULL, 0xAA3DD01C858F3776ULL, 
            0x179054105B02D772ULL, 0x38DF265B06CEA569ULL, 0xE3FEF49F490BD707ULL, 0x4334FCEACCF776CDULL, 
            0x706F9FA825A6DB7EULL, 0xD030EF68F821181AULL, 0xDC80A1746A71067CULL, 0xE4FB97E2982E69CEULL, 
            0xCB65EFB1B879C44AULL, 0x13C468FE767EAEC5ULL, 0xEE861B90389427F8ULL, 0x7D2CEC14596E8C30ULL, 
            0x51FCFCB1A5996C48ULL, 0xE4DE81CCC5BDC05AULL, 0x66D171FFEEDB7AEDULL, 0x735A8F1F7B7AFC79ULL
        },
        {
            0x7FEF3F0752B4E00FULL, 0xE32472475B645610ULL, 0x2D1231C91F91996AULL, 0x58E34D158444E34BULL, 
            0x4D4D7D27B30CB115ULL, 0xFD2F58171B8AA850ULL, 0x86E4D7CE75BEAD0CULL, 0xE89604C4203E92CAULL, 
            0x832A4D6F3109AA79ULL, 0x60FE7751D58F4AE9ULL, 0x1CB8A800D4634227ULL, 0x50709450D90F4738ULL, 
            0x738BB73289718A10ULL, 0x946BB3776414CB52ULL, 0x363505550FC1170DULL, 0xCEECB3D16D50852BULL, 
            0x18FE78220135279DULL, 0xBBBB1AF2F49F2E99ULL, 0xDAC1FC3FB3297BB9ULL, 0xF6F2EF1E3EC31B0BULL, 
            0xBAAB6726BC89097EULL, 0xE3EDD1F7BAA4DF66ULL, 0x15F4CA83035CA6D8ULL, 0xAC5D2A7955F9F1A6ULL, 
            0x5C7B8B4A9628D645ULL, 0x383BA11CCB1FBFD3ULL, 0xD2302340B354C552ULL, 0x477F344058E1FE7BULL, 
            0x77DE2A2467D4A745ULL, 0x8FD92E5B838C9B3DULL, 0xF025331C98EC8701ULL, 0x19D08B1B883BA196ULL
        },
        {
            0xDFB3DD5D17B38217ULL, 0x6FD2E81D20443937ULL, 0x8329915BF23A5ACEULL, 0x8B2BA40209CF687EULL, 
            0x2F473AE43C60A3CCULL, 0x2229DD8548F613CBULL, 0x15512D3ED1826481ULL, 0x6EFFBDAD02D4A54FULL, 
            0x199E370A6F376838ULL, 0x911779B60F51B947ULL, 0x8815E598479A50C7ULL, 0xB5B92342B591DE1FULL, 
            0x4C506A844DF49682ULL, 0x0AA1BF53C9AC22ADULL, 0xF682D4B3D7AB54C5ULL, 0x8412F45DCCB719BCULL, 
            0xBC4DB11A032E4820ULL, 0xBEF0670030807E54ULL, 0x54691C59264FA118ULL, 0x431DBBDB465C7216ULL, 
            0x3778498EEFFAD9C5ULL, 0xB46DFFA37D7DA357ULL, 0xD912A9710FCE407CULL, 0x747091D6288C4E2EULL, 
            0x6F01C6233A93FEF3ULL, 0x5FACBE5A7D036C17ULL, 0x3D2D0FBAA341F8CFULL, 0x1561638815643C07ULL, 
            0x085882F4AA48BA61ULL, 0xF7A8E3E26257AA9DULL, 0x99EABD18DD0C2EB7ULL, 0xFF3F42ADCD6618A8ULL
        }
    },
    {
        {
            0xE200CA14A2C4748CULL, 0xA6A57D9CFCFB1EB7ULL, 0x1B36198BEAF97A88ULL, 0xAA34F3E53075F0A0ULL, 
            0x096AB8F5469F205EULL, 0xF1710A3E0B3ED755ULL, 0xB15A40BD740A8D45ULL, 0xF49B954F98111B09ULL, 
            0x9E930FF15D32D0F5ULL, 0xA0D56A5B6BF0FD08ULL, 0x5013F85E6F0DE804ULL, 0xF0685730BD1E8C33ULL, 
            0xA73A611BCFDDFACCULL, 0xD8FD3927AD6FA09DULL, 0x25CB08B9FC612CA7ULL, 0x03D0BEC2606453B1ULL, 
            0x9677BE85EBC4B577ULL, 0xF8303F051AC2DA68ULL, 0x906E22834FAFD416ULL, 0x513D48F16648C2FEULL, 
            0xE359AD65D269897CULL, 0x40EB24A547B0E6ACULL, 0x293353FF91121E16ULL, 0x984209DF5CE26C78ULL, 
            0x75ACE47269702974ULL, 0xC6DAEFF3D525213BULL, 0x145D4320B40879ABULL, 0x6CBA388DA4E75C4BULL, 
            0xBA3E96ABB9605691ULL, 0xC8D751F37DF8F102ULL, 0x6E971080F5B5E77CULL, 0x3A7342466F583195ULL
        },
        {
            0x633319C9B28387DCULL, 0x829D5A3408D33C67ULL, 0x8FBB9E2F0D56918BULL, 0x1DB712E6D3F305B7ULL, 
            0x5A42C8718E488680ULL, 0x67B58CFCB67EA8CDULL, 0x091DBCD13CC3BA7FULL, 0x779ED703D610F0EFULL, 
            0x58A1CCC93BD6A404ULL, 0x169ACAF4E243CBBEULL, 0xE7294AE5CB93B88FULL, 0xBC757F019EDF94F4ULL, 
            0x7B0AFCA53642EF2BULL, 0x2375FA8B45A1101CULL, 0xB99B84CECC279B93ULL, 0x194B711F155674EEULL, 
            0x972E62A2FADE06DAULL, 0xF344DE4303BECAAAULL, 0xAECBE875E0061404ULL, 0xC6BA2CC460117C0AULL, 
            0xADEF608B7D4DE930ULL, 0x1C50385A627A691CULL, 0xCA490F52D88535ACULL, 0xA6FA7CB9D432A5D7ULL, 
            0x5C0D611613A26C83ULL, 0xEC7A21B32C30FCB0ULL, 0x5901ED41EB24E60CULL, 0xF8095A2ADE1CF1E0ULL, 
            0x475EA2C80B31F2F8ULL, 0x3A3D2078055F6F02ULL, 0x23C6A65A32C98979ULL, 0x0A7919C4E9BCA490ULL
        },
        {
            0xF3A67509294F945CULL, 0xB57E5F3D2E0F280BULL, 0x89549CB7F169A12EULL, 0x2F432B44F27A62F7ULL, 
            0x12715204E0F0462DULL, 0x8E4EB2468A66578FULL, 0x3B09AF0FCAE9DA23ULL, 0x7398600B588F00F4ULL, 
            0x7B678670332B8C49ULL, 0x15FE65F222E1B088ULL, 0xD77D7A78466915C6ULL, 0xFA364784D7A4F2F6ULL, 
            0xEA95338FE3414BABULL, 0x01E58109BDC3F41CULL, 0xF122D80FDAA052D5ULL, 0x8880D630B34C183FULL, 
            0x26A56CB23C3EED75ULL, 0x7A1ED7E92F20F1C2ULL, 0x6B6A482727CC433FULL, 0x8AC0ACB35214F2BEULL, 
            0x88E0E558D6C8E8AEULL, 0x9FE15E4B7E2664FBULL, 0xCD96699F5FBDF410ULL, 0x5343C32A7A850B43ULL, 
            0xD639C6F128EB3E1BULL, 0x3CB005D52D281147ULL, 0x0D53C127876817C6ULL, 0x60B97FEAEA9923ACULL, 
            0x7D131D51F8C3E724ULL, 0x94D3CE040A9D05CBULL, 0x47B1AF961C5B0DE1ULL, 0x4CE691D7BAE367DAULL
        },
        {
            0xE51E403E5056EC3FULL, 0xAB393487A75DA371ULL, 0x186EB62616B80223ULL, 0xBF88B9D94CB13AC2ULL, 
            0xE15883FF47F2A9A9ULL, 0xD7B867E77511A3A0ULL, 0x40D9BCB0467977B1ULL, 0x8357CE11353A85C4ULL, 
            0x4BCFE611E70A104FULL, 0x47C5591661173A00ULL, 0xD6E257EB0CC9ECA0ULL, 0xD2D3888B5C4F5FD9ULL, 
            0x63E184549FEE41C1ULL, 0xE79101949546BD02ULL, 0x3D80A5966F82E39CULL, 0x06882F8B4A30DF77ULL, 
            0x4A399AC4991FD0B0ULL, 0x0F7C22BD83E08718ULL, 0x2289798065192B22ULL, 0x7F275B44DD4225C0ULL, 
            0x3ECFF8D1679907ECULL, 0x97B2D3A3AFDD4D70ULL, 0x6CE612C8038463AEULL, 0x1E5178819EC52BD6ULL, 
            0x991528F6204226BCULL, 0x41460871AAB347ACULL, 0x97605DD3B1649047ULL, 0x14D32E2F1DE5C3F6ULL, 
            0xC3C753B2DDB04A9EULL, 0x26D25878F45BD49EULL, 0xC517E48B63298A57ULL, 0xF2113FC51657208FULL
        },
        {
            0xE1DFDCEC5EA94DB4ULL, 0x2509783F53946D34ULL, 0x9FDB03BB6F80B7CBULL, 0x483DC214816A0175ULL, 
            0xDEB313B2D23FAEDAULL, 0x0F16E0A033847D97ULL, 0x54639884951D0492ULL, 0x888205E8200F97E3ULL, 
            0xBE0E95EF73B54AC9ULL, 0x403B8E39C406E567ULL, 0xF62C52D505BCCAD5ULL, 0x13255A4D98CE61D7ULL, 
            0x3082016A813C33EDULL, 0x596892BD58976164ULL, 0x3DC4093BDE7FBEF5ULL, 0x59B5C81B8676C66CULL, 
            0x6756801DC285D43DULL, 0x1AF86451F6951F3CULL, 0x7F98CF592C6B9BA6ULL, 0x03EAA3A7759B864BULL, 
            0x546F01D4B3CF1E80ULL, 0x5B24ECFB3E75A09EULL, 0x59EDF4312587DCD5ULL, 0x64B31F6FDA8FEAB0ULL, 
            0x19293334EDAFCEF4ULL, 0x4183DA102B0A70ACULL, 0x1D3922E97240BC31ULL, 0x5EC35DB5D17E67C4ULL, 
            0xFC097432090979E3ULL, 0xACECB94A2937D210ULL, 0xFF4F99B7DEA95475ULL, 0x7DCD2259F54FF03EULL
        },
        {
            0x336A3E6DAE339842ULL, 0x84A922653E5EC19DULL, 0xF5932B985D69023DULL, 0x920753B17B901F85ULL, 
            0x495FD50181EFFA28ULL, 0xEA6F296DD10B3CEBULL, 0x1BF35CB49511870AULL, 0x5EAD7CC115A8A42AULL, 
            0x526B6D137CA5E947ULL, 0x0647BED058B008EAULL, 0x70AA79B7381583E5ULL, 0x260EDF1EB00DEBA4ULL, 
            0xFBC0DB1A94FA97EDULL, 0x5F85DF9BF279DE6BULL, 0x2C752716865A5C45ULL, 0x8F778AB003DD1069ULL, 
            0x83F6449CCF4872EAULL, 0x837CC6031585B07AULL, 0x86A92AA8DDF85AFAULL, 0xE926468D706E4F66ULL, 
            0x8C90998F3740D7A7ULL, 0xA387A453A602C383ULL, 0xDBEC0CBD04F15746ULL, 0xFD49C218CFA9649EULL, 
            0x56B88CC8A9286CBCULL, 0x79CF0EB51256F1D5ULL, 0x6BBC30143F51C06CULL, 0xBD581AEF0EA5FC88ULL, 
            0x351E01570E67DED3ULL, 0x0C78F6507C0F8C90ULL, 0x0C320C6C5E78966DULL, 0x1D8F7DB461579CE6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeyRotateConstants = {
    0xA63AE95CE5BB4122ULL,
    0x3C5E7C53ED8DC4BAULL,
    0xBB7AE359775469C1ULL,
    0xA63AE95CE5BB4122ULL,
    0x3C5E7C53ED8DC4BAULL,
    0xBB7AE359775469C1ULL,
    0x277899432C7F9416ULL,
    0x611C6802C9051411ULL,
    0x60,
    0x1F,
    0x28,
    0xD6,
    0xFF,
    0x1C,
    0xE4,
    0xBC
};

const TwistDomainSaltSet TwistExpander_Canopus::kKeySpawnSalts = {
    {
        {
            0xBAA398EC1F8DA73CULL, 0x481A9BBCB3F6BB5BULL, 0xC06991CDF9BD23B7ULL, 0xA3CD2B274AF71958ULL, 
            0x75D884FB13591FF8ULL, 0xF6D5BD71C29A8A2AULL, 0x0C7EDC1251C362E1ULL, 0x95FF530D85059E4CULL, 
            0x2FC24662CDBC0B80ULL, 0x662BEBB848052CF3ULL, 0x1B2EBCF2462466E6ULL, 0x779E916886ED0742ULL, 
            0xE0F9BDA3340E331FULL, 0x2CC45323442FBA45ULL, 0x173A59A7053A3390ULL, 0x2801928252903FEAULL, 
            0xC4AD2C134F3822C7ULL, 0x007F121C488225B1ULL, 0x1E3DDBE5DB70ACB8ULL, 0x86D2A8853AF32DABULL, 
            0xE570B59AFDB1886FULL, 0xFFE35B71A7C5F92BULL, 0x993DDCDFE7C3499EULL, 0x58711DF3380AD31DULL, 
            0x9057C047804192B2ULL, 0x97A849792FD828A6ULL, 0x2980A55A97D9DF62ULL, 0x583359BE825418E9ULL, 
            0x0C587B671AB04F6DULL, 0x7BF5BD463B0C855CULL, 0x159DD91FD5498D03ULL, 0x98A5ABBF19A7D4C2ULL
        },
        {
            0xD178FD8186B8397DULL, 0x025D993506357656ULL, 0x4E9FC9D08E8CAB79ULL, 0xF59D0BBF4FC04E1FULL, 
            0x5650354C2B5167B7ULL, 0xDEF96E2E10A37E0AULL, 0x655A9148D0FBE104ULL, 0xFAAD47BC22513C89ULL, 
            0xFECCFF96FDFE4D33ULL, 0xDE71BFB0775DF2D7ULL, 0xEC86FF7E937F6E7CULL, 0x05431ACA4AA9B167ULL, 
            0xAE448B33B5836F3EULL, 0x32D9957B33B5C3A0ULL, 0xA49C43DB794EBD91ULL, 0x00BB73BD40EA304DULL, 
            0xDFE4D4418C457C8AULL, 0xBCB3D4B877390050ULL, 0x68266B116A28C377ULL, 0x721525F47C88C1B0ULL, 
            0xA04EE1ED382C15A0ULL, 0x0518F5E7E96B8B45ULL, 0xE5E9E012103107AFULL, 0xC4EC0DAC237D449BULL, 
            0x39ACE9759E7D0D0AULL, 0x18C6ABCC91C95109ULL, 0xB05593B8C1314356ULL, 0x5C3B37A342159284ULL, 
            0x3D03703DC57DC282ULL, 0xED2EA3A29DB4E528ULL, 0xEC7855260B7CBAF3ULL, 0x8C93C42020B0F553ULL
        },
        {
            0x3141C8973A09C9DBULL, 0x5B96EA1B97C2FEB2ULL, 0x44A2B08BAF9DD9ABULL, 0xEE4C2868CA2B1CA0ULL, 
            0x80DDDB1962D367D9ULL, 0xD2E947ABC9327B51ULL, 0x17FD674F835828E8ULL, 0xDCA47B53F5F7269CULL, 
            0xC2C4B7F3AE764135ULL, 0x525D8036801B533CULL, 0x87B78890F87559DCULL, 0x56A32818DAB7610EULL, 
            0x7F32DE6E427ECE22ULL, 0xB23BC307077981C7ULL, 0x39E3C58F4E818246ULL, 0x060DCDF841205A97ULL, 
            0x5DB3E18F7059D164ULL, 0xAF1F6BED06DBBECCULL, 0xDAED4392EEDA89E2ULL, 0x521248AA427BD1D9ULL, 
            0xBBCC5A513C814E92ULL, 0x60F439828FE6AA02ULL, 0xD7680B54F7539233ULL, 0x7643FE612D23C8CAULL, 
            0xBD4C206418218EFAULL, 0x3615922B8B873EF0ULL, 0x9DBF7659BE9BD7B4ULL, 0xB3C47526E7C6E2A3ULL, 
            0x19F9B37454994537ULL, 0x35D12B24A73D9FB0ULL, 0x87BA66EE1527854CULL, 0x17E6CC10A1138C87ULL
        },
        {
            0xCAC3F758F29D5C53ULL, 0xE8F603A0CFD27278ULL, 0xA2267C72F8BD930CULL, 0xBFFE064E2D2673D4ULL, 
            0xDFAF797F62AD4E13ULL, 0x36502012CFC6AA6FULL, 0x03E477A14017B290ULL, 0x274D49297CBD6B8DULL, 
            0x39A7006787209C58ULL, 0x0EFB0E9BE6C6110AULL, 0xB17599743F1BCEABULL, 0x5A7681DFAB83D32FULL, 
            0x84246BF441A96B77ULL, 0xFAFFE2AEA213383BULL, 0x6B72ECE7473EB0F0ULL, 0xEF3CA358F0B39440ULL, 
            0x122FF985C2454F0DULL, 0xAEE86F54F091918FULL, 0xDF6AE74B53364B6CULL, 0xD5F3EB640E57C880ULL, 
            0x7E1312A13C629A9BULL, 0x344E83C25211AF8CULL, 0x91820751531031F1ULL, 0x00A02212E3800010ULL, 
            0xA99CB3D14211374DULL, 0x9BA8118920E7C0B4ULL, 0x538E45ED7AB37964ULL, 0xF5E7D76D48E4A0BAULL, 
            0xE0D0C8C9A2B818A5ULL, 0xAB6E5ACEE03BECEDULL, 0x4A0002CDACC011C7ULL, 0xD07B7DABEF1B4BC4ULL
        },
        {
            0x9BE4D8C24B0765C9ULL, 0x65B741E73AB5BF12ULL, 0x0BBD19DFED4BFA17ULL, 0xDD01C7F27028FD40ULL, 
            0xB7A09C41FC03E35EULL, 0x86E0237298F97322ULL, 0x4B719539D2CE5961ULL, 0xB596E21F4F15CFF7ULL, 
            0x41AFB55F5E404DB5ULL, 0xC18D7EF49D88FA94ULL, 0x66A3571E18D478B6ULL, 0xED64FB5504ABE0A8ULL, 
            0x85578F8BBE399F7CULL, 0xC6B9F698ACB9715AULL, 0x86F2EECD28C249F1ULL, 0xF364821557E41822ULL, 
            0xF7BF93392A05146FULL, 0x47C99076B3EE711DULL, 0x0F4AED3532B15587ULL, 0xA68E927C55CEB002ULL, 
            0x5CFB7CE56A72D6D0ULL, 0x2878FD6F15BA6BD7ULL, 0xEEA85A0340BBF57AULL, 0x903E47349CC460A0ULL, 
            0xF2C4494AB8D6B148ULL, 0x3115F94331CA4A7DULL, 0x0D854F7397F4CBE4ULL, 0xF8323DA4EBDAC616ULL, 
            0xA6784D14E5F8E211ULL, 0xA6306D6128FA5983ULL, 0x52BFA3F25C7A9B76ULL, 0x7BA6A979CBCB64BDULL
        },
        {
            0x303D6721B7611C37ULL, 0x9CB6C9A4FE3CAE26ULL, 0xC567557A8609FB6FULL, 0x9E265B8458D2856DULL, 
            0x296137CE1203254CULL, 0xE837FBE3B9052F49ULL, 0xA1F4BFAACE0BF0F9ULL, 0x05096B0C67E87819ULL, 
            0x3A631CE90E09C2F1ULL, 0x248ACAEEAF7DFBB4ULL, 0x866C8F13B6061285ULL, 0x846EB3AE04F59E4BULL, 
            0xD130004319DDC8D3ULL, 0x6F3C43CF7D7B36D0ULL, 0xB466A7D24D4258FFULL, 0x0A2D73AE8B200219ULL, 
            0xADCC443A39427008ULL, 0xAFC2653FB041AB5EULL, 0xACB5B802177056B4ULL, 0x59ECE4DB7C57944BULL, 
            0x5BC21234BE6B9F29ULL, 0xDA908C5527489E39ULL, 0xB2C5FAB44A451F64ULL, 0x7CFE5E930A46FF7AULL, 
            0x617702B89C1CCE5EULL, 0x50EDF8F327054395ULL, 0x918D0C223A674A79ULL, 0xA1B30A28A97E51EAULL, 
            0x204D6395D97334FDULL, 0xE83A98C2829BA784ULL, 0xDAEF46AD47228A44ULL, 0x0098F860CC531466ULL
        }
    },
    {
        {
            0x6FEDE5F8510E9A54ULL, 0x550C4D56FE97AF13ULL, 0x3C8CC55179B4E5DBULL, 0xCCC5E86176667284ULL, 
            0x7457C4B7878EB79CULL, 0xF361931030D98A11ULL, 0x51DE60BC87E9102FULL, 0xA11685437258E320ULL, 
            0x15C384539EDCEE8FULL, 0xB817903E86B3E465ULL, 0xC95219F061E6AA2BULL, 0x1B6AA62D90F988C2ULL, 
            0x4DD8435A9781D479ULL, 0x2E5F3CBE2599D35EULL, 0x43A8E52E92689878ULL, 0xE28216F483EC14A4ULL, 
            0xCC74A243FDF15E2CULL, 0xA750F4917B0C45A2ULL, 0x11873FB9915E71E3ULL, 0xA1C53DDBFF4F3EA9ULL, 
            0x143E65594D4939F3ULL, 0xCBA4656F04884812ULL, 0xD9555B44411E4D1AULL, 0x5F401A6F44D7B1CCULL, 
            0xAD4A931B14C0E010ULL, 0xA09FD10A6F69C06CULL, 0x7AAA6E38AFED7743ULL, 0x6074CAB9878A2349ULL, 
            0xDCEBFE2C39696B40ULL, 0x411A3ED59F31683BULL, 0x33F105447AEFF716ULL, 0xD7BE3C3AE1C8B250ULL
        },
        {
            0x2225523B023DB634ULL, 0x7892CECB3A03E96AULL, 0xBC7DE9B54F914D65ULL, 0x387AA7C987389788ULL, 
            0x65B0BFDF8215CDEFULL, 0xFCE3464BB4C6A74EULL, 0xD69864F177695D8CULL, 0x6415AFFCE7EB747CULL, 
            0xFA1AD3915FB42A00ULL, 0x98C50F6B970DE062ULL, 0x116CAE54327C1F7FULL, 0xFEE092A9477CE295ULL, 
            0xA0499B591F9F7DA8ULL, 0x8BA31C0F6EE8ADD5ULL, 0x593766343AFDE64FULL, 0xEE1979C8C80C58D1ULL, 
            0x029123E747F43818ULL, 0x654CE7DA2DCC1238ULL, 0xC605619AA9A0404DULL, 0xD9182B5E285623B5ULL, 
            0xD95F19EF47BCD119ULL, 0x63F810AAF9DC0A75ULL, 0x3CFA2C34235568D9ULL, 0xC8CE4AC52AA6AA3AULL, 
            0x5CAE7181329AFA52ULL, 0xCDB1C8CB256A637EULL, 0xE5651CAA0E77FDBFULL, 0xEC07A860642F9EE8ULL, 
            0x92E1DF6D17729222ULL, 0x134317A45F8F0E39ULL, 0xFAED3A5F6D735A0AULL, 0xC8EED7702C5C0580ULL
        },
        {
            0x3D48D65183ED6D20ULL, 0xA947D5FF355196FFULL, 0x6A5F008A34E39D70ULL, 0x79913E26378312ECULL, 
            0x163116DDCCEAF9DDULL, 0x472687000D26759DULL, 0xB66DE6359BE3AB29ULL, 0x7F79FF6F71330974ULL, 
            0x5D70DD33D70BB6EFULL, 0xFF2D84BEE8B965F6ULL, 0xBF63DDF37219D4A9ULL, 0xA3B174DA8D00AFD6ULL, 
            0x7CF3B00DC6874D2FULL, 0x21182D2DDA14B354ULL, 0x9B9B428A97596738ULL, 0x6574193FCF3EA5FEULL, 
            0xE656159834320246ULL, 0x0AE030C899A2D4DFULL, 0x7059E9FEFE8EE1B8ULL, 0xDED462FC58D30F00ULL, 
            0xEAAB1C1B7A27721DULL, 0xC4887D8FFEE4E1C5ULL, 0xB4C2225534BF1E3AULL, 0x06B088D795383A16ULL, 
            0x0EB67E11DA357ACEULL, 0x3775D830BF135DC7ULL, 0xBA113439369814CCULL, 0xC4A97441F102DCC1ULL, 
            0x514E0925EF0D440AULL, 0x1485686078E18B6AULL, 0x2C73A21B1F032639ULL, 0x2B735E2794CC4245ULL
        },
        {
            0x86850700F2D2BFBEULL, 0x31BE46E701C3A9DEULL, 0xF155BA41390A42E9ULL, 0x6CBBB21CCF373BE5ULL, 
            0x9719C6FAB5E8F845ULL, 0x30DFEBA145F12CEDULL, 0xDB778F9BA5278AB3ULL, 0x5727BF043E6DDDD7ULL, 
            0x0BFBE5FA6D8A26BEULL, 0xF2DB20C96C50F810ULL, 0xD2BB09A2417DD269ULL, 0x5A0B14C12EAA32D3ULL, 
            0x5B2B9FD6CD44DB35ULL, 0xFA98DE780B0A0289ULL, 0x7B9548DAD1B4DBB6ULL, 0xF8D68D2BF9A6FC27ULL, 
            0xE8A23DBE02D74752ULL, 0x136CDF8D7A48309BULL, 0x618B68E8D6495C8AULL, 0xEF540780669BB332ULL, 
            0x6180214EB65EC3FCULL, 0x27DE2327B284A4B0ULL, 0xAF8CB65F290B4D92ULL, 0x51B105260A91A299ULL, 
            0x0915FE5AF994C7CAULL, 0x9F75EED5106D3648ULL, 0x927A49D80F4CDC7CULL, 0x33089A779AD1DC37ULL, 
            0xE20EC14F30B8FC37ULL, 0x26754931E5F9FAFBULL, 0x60B0BC9CD9673D1DULL, 0xAF5068298BE5223FULL
        },
        {
            0x88F2C0947464B08CULL, 0x9877ED112D4BD1EAULL, 0x9A8EEFBCF408AED1ULL, 0xD89212AECE3C46C5ULL, 
            0x150E7FCAEFB6B6DBULL, 0x851B4890AF927EA1ULL, 0x1B2EC6A5E077253CULL, 0x2063CAE0961D78D0ULL, 
            0x3B6371D7C9A0EB86ULL, 0xBE9EBCC32BD3A8B0ULL, 0x7A4E8DBCFEE71D7DULL, 0x84138F405DDAC544ULL, 
            0x30D6B9BBD8C0D949ULL, 0x0F9861FDBA888F47ULL, 0xC2C68A7463A39F77ULL, 0x453F64175E570596ULL, 
            0x998B78E917C10278ULL, 0x16719F8A7337F63EULL, 0x253F811909F179B9ULL, 0x6250C735B1140724ULL, 
            0xC80AEDFB2CB1C42AULL, 0x346042CCD0756E0CULL, 0x47742F4FAE7F722CULL, 0x5E92A4FF6495F24DULL, 
            0x752A74727328FB8FULL, 0x07656F191C0DD292ULL, 0x1C9F7367C2864B56ULL, 0x0D864540FE535B69ULL, 
            0xB7E1E220EC0E2835ULL, 0x3DA724FA19401532ULL, 0x712E9FF8CA15C5A8ULL, 0x77390D803ADE044EULL
        },
        {
            0xFE7BE9A783FE4264ULL, 0x2CD792B5CF57B31FULL, 0xABA84F1B630D9EF6ULL, 0x25FB5EB7739D9F01ULL, 
            0x18476EEBC8FDE079ULL, 0x5D48C6E9CD2340B8ULL, 0x05E5AD23207464FAULL, 0x39B87D9B1314A6ABULL, 
            0x5056EFFD0259483AULL, 0x805551F1C18B3A68ULL, 0x9504F9E96B51D66CULL, 0x8B647BB77C437D6EULL, 
            0xB72AEB9AEB539873ULL, 0x89E21FECCFFD0D52ULL, 0x3051A45BF2594024ULL, 0x55B60A65D2C6FE77ULL, 
            0xEBFC78CFA7DC685DULL, 0xDC25EB32908E7B67ULL, 0xACC3D2784907D2EDULL, 0xFD80C915F98685F3ULL, 
            0xFEBBCA0627C7C9E6ULL, 0x7D267B51D2383415ULL, 0x2624E9AEC03F488CULL, 0x47C0C2BBCCC748BDULL, 
            0xDA99CD1C48FD8D1EULL, 0xFFDB5FABE861C485ULL, 0x3F45C081B6292596ULL, 0xD4FF49F21D36BE74ULL, 
            0x2F47CAAB31CDD731ULL, 0xF0B3E98014401E9DULL, 0x0AD5C6FC32E83E13ULL, 0x8C627A6B0590D3B9ULL
        }
    },
    {
        {
            0x06C1E86E8A51F609ULL, 0xC4DCFD525484FBADULL, 0xBC6E5648BCC5FD6DULL, 0x744BCA9D6786C9CDULL, 
            0xCF439AA2E25D46E2ULL, 0x42F9CF191636E9D1ULL, 0x1FEFD8B2EBA3E430ULL, 0x7C3858D525EC01D1ULL, 
            0x2B0605EFB57F3E35ULL, 0xC2B2C5B0481DAFFDULL, 0x5F334151CB3F0931ULL, 0xF8840708C9166D80ULL, 
            0xD38CBF027CB015C4ULL, 0xBB0F720B913BB102ULL, 0x6E35899522EFC657ULL, 0xB8320CA5D8689D0EULL, 
            0x2F7D14C3EF1FD2E5ULL, 0x682C4BDCBD216AC5ULL, 0x4EC69D200E0F69DEULL, 0x1FF1C3CB8018ACCBULL, 
            0x4850D8E1C5FE2F25ULL, 0x8FBE3D11D1BE566FULL, 0xAED3CFA3C79F6AACULL, 0x9729930DA2D34B05ULL, 
            0xCC754504E00332A5ULL, 0xEFAA12A1F6970815ULL, 0x1DC59608F00B7FADULL, 0x52C5E12EAAFFB5E3ULL, 
            0x81BD2A82A153A013ULL, 0x3C33D6841591FF89ULL, 0xE957D80EF2DF47B6ULL, 0x72C0DD9CD90029E8ULL
        },
        {
            0x149057C0504661B5ULL, 0x01DAF6AFB80309D1ULL, 0x3D809CBF830819F9ULL, 0xFEAA16981BAA62F2ULL, 
            0x734B7C4AE0AEDC07ULL, 0x030E14CE7ABC48B7ULL, 0xD1EB59DD21ADCECFULL, 0x81962CE7C5813AF7ULL, 
            0x701D2EB5C8C5CCBEULL, 0xAD929277F95AB237ULL, 0xFFD85F82984A4202ULL, 0x23F122353C2C2BB1ULL, 
            0x6F1D9026DBDD70D9ULL, 0x6DC584AF1282F17BULL, 0xDBE1287B14003926ULL, 0x82A904DDF9B4818DULL, 
            0xF2D6E2E0CEFA3F4AULL, 0x6B6F81E53B8D2A67ULL, 0x760667CD5BF35D7CULL, 0x8FDAEC21C26F83C5ULL, 
            0xDA7BADF2A54994F7ULL, 0x41B1307AA00F3BD0ULL, 0x9ECEDC54AB82AA20ULL, 0x207007591747307CULL, 
            0xE52826253C077546ULL, 0x677AD85AA17CB5FCULL, 0xA40F765220B4B455ULL, 0x7E0331337A037B38ULL, 
            0xB0D01F84FAE22E28ULL, 0x707AFDA75D2415CDULL, 0x822A163F091E481DULL, 0x30182F8B521B405EULL
        },
        {
            0xED725AF514C903AFULL, 0xFC58ABF9BDBD0D2CULL, 0x93B8778442919F45ULL, 0x42306BEF054A021FULL, 
            0x26FFE3CC63093CD5ULL, 0xAD06257D3769BF9BULL, 0x05FC5C516883B519ULL, 0x0F10C0BD85C08E6DULL, 
            0xF89DC01B8F4CE5A7ULL, 0x18D32E06A8B870E8ULL, 0x9C3521DF052CDA21ULL, 0x9EB0712CFBECFDB2ULL, 
            0xF02938A0F6776874ULL, 0xC0028A5B0616DFFAULL, 0xB6941E9A330F15F2ULL, 0x24C5327BB6A261F7ULL, 
            0xEDC3B3229EB1DBBAULL, 0x36BCEB1E8A8EDC83ULL, 0xEDB9D6B975472B03ULL, 0x7F45C133A0E3CCB7ULL, 
            0x18817F1C09F9D4EEULL, 0xE7F63DFCE0628824ULL, 0x697BC11EEB8315C7ULL, 0x03918F483997B495ULL, 
            0x6BB15D62CB13BCADULL, 0xEC79814F54DAA9A1ULL, 0x013AA86F9FA59E08ULL, 0x4D55EFD86290D873ULL, 
            0x2E924D9E1366676CULL, 0xD21757A5984CC2CEULL, 0x916F8CF348468E66ULL, 0xA397A0D49E34C1B8ULL
        },
        {
            0xEADD1E87A7BF46F7ULL, 0x8C554B438B470E6FULL, 0xED909CAD6FA5BCEDULL, 0xE268DD8EEABFC1D3ULL, 
            0x0351B23A04A018AAULL, 0x1391E28B1FEF8F3DULL, 0x3351A5AA832E5FC4ULL, 0xB663B1DADD86B631ULL, 
            0xE50DFFE29676C362ULL, 0xECF162221538905BULL, 0xE2013E97903D391CULL, 0x7D621D9824F93BF9ULL, 
            0xB05EE67BE9997BE3ULL, 0xA888F557FEE48D34ULL, 0xDE9B1CD74E315194ULL, 0x7080F3ED80B6310DULL, 
            0x10A22DA0200F2115ULL, 0x6B09924BEA0E5FC2ULL, 0x314CE8C5F02C4001ULL, 0x809E5B8B74F4A193ULL, 
            0x634761941A65BE9AULL, 0xD1E18D3714A4599FULL, 0x88218200DFCC1C97ULL, 0x349826DA769155DBULL, 
            0xC67B95B31D2AC801ULL, 0xE35C8EE65F726092ULL, 0x2AFB34C44FDE6776ULL, 0xF9341B25479092B3ULL, 
            0xD0708BD372E70DB4ULL, 0xB8BD40633FAACB0AULL, 0xBB798C77CAA1C7EAULL, 0x047C99CB293D1298ULL
        },
        {
            0xE50D22F3F021523AULL, 0xC7EBCAEB1D9CD84FULL, 0x217078803BC72949ULL, 0xDB974C038BFF17FEULL, 
            0x876A2A2EF85AE912ULL, 0x7ADAF85D2B99AA60ULL, 0x0A23155A1F5192B0ULL, 0x6119826D8CB0BD5BULL, 
            0x9746CBC30AAE0315ULL, 0xF89940C5727D6A53ULL, 0x8823DB0AC3C570EDULL, 0x72938FCF5CADF3A5ULL, 
            0xEE9D4CA86DF78212ULL, 0xCDACF9FAB0EED084ULL, 0x375A2C3E519FCB04ULL, 0x11CFF170C3DC1A7CULL, 
            0x8107877E6E299121ULL, 0x13B38A8D532F29ABULL, 0x3EB1829DBBAC8979ULL, 0xA584C20253808ABEULL, 
            0xC174433F92A3CE45ULL, 0x6D0E81978DA3481FULL, 0x6B641D770594BD9EULL, 0x719FDDF850A3C887ULL, 
            0x323FDF6DFB8E480EULL, 0x17E7B8F7D30EA433ULL, 0xC3BD6EE83BF3C7B4ULL, 0xD9BE284C8DFE19B7ULL, 
            0x53CE6C66E04CF95AULL, 0x7A1DA3671EC26384ULL, 0x98B7873888FAD248ULL, 0x5FB1890ADD5A4850ULL
        },
        {
            0x64C5495357689D0FULL, 0x319F75A060EF37AEULL, 0xC9D1D38DBE9A9E2BULL, 0x407FE907699DAB71ULL, 
            0x5280AC77CB9523ECULL, 0x1AC63AAD11D8EBB9ULL, 0x0B6D70878C5D4200ULL, 0x586737EB47B5095EULL, 
            0xF51B2D51F9C85C97ULL, 0x7FAC48C60A41E5E7ULL, 0x0C5B821EAE0738F0ULL, 0xCF4554876C0DF2FFULL, 
            0xE59424B8E6DF33AEULL, 0xF7884FF1D034583FULL, 0xF2AEB7F1DF59F001ULL, 0xC29983FCA50F33A1ULL, 
            0x120AA2098912A347ULL, 0x5655874B5473E124ULL, 0xF6C39A26EB430DD5ULL, 0xD7F802CDA4A253B6ULL, 
            0xEEB25A1891D3E65EULL, 0x150DACAA6C763978ULL, 0x26D736F5EEBA0F08ULL, 0x3608518D61CE6F3CULL, 
            0xA063D9F2B40D9786ULL, 0x760CBBCF6D9DC3DAULL, 0x13333D6DB8588848ULL, 0x7631D8FA5099D861ULL, 
            0xC61F3DE13585A949ULL, 0xFAC70792ECE03518ULL, 0x40D4CA0E93F4C911ULL, 0x6771EBBD1594E856ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeySpawnConstants = {
    0x7FFD8D4705C5881DULL,
    0x6665F17503F593ECULL,
    0xC7DE9629C59937CEULL,
    0x7FFD8D4705C5881DULL,
    0x6665F17503F593ECULL,
    0xC7DE9629C59937CEULL,
    0x3D57EB59DF4CBDC4ULL,
    0x00E3D83AA3D7CA2FULL,
    0x04,
    0xBB,
    0x5D,
    0x54,
    0x9E,
    0x9F,
    0xF1,
    0x85
};

const TwistDomainSaltSet TwistExpander_Canopus::kSeedSalts = {
    {
        {
            0x866BCD7FAA8D42EAULL, 0x95F60D4AEEE5AFA5ULL, 0x05468DB25FE55F17ULL, 0x2D309E41496B400BULL, 
            0x477401303E0C6249ULL, 0x7A35CA29E39DBFB1ULL, 0xD40B21AE7797CB71ULL, 0x48C08209E87B5E2DULL, 
            0xDB208E15D9ED0409ULL, 0x42550CFA7C16B5A7ULL, 0xA136525A8F03F7C5ULL, 0x37358B67F4AABC82ULL, 
            0xE81786B98F4A2A1BULL, 0x8BE32ADAE161DAE0ULL, 0xE500BDB2E2548FEDULL, 0x851A987016DD2E67ULL, 
            0xC0CDCD2D2A39075BULL, 0x0B67DD5F44E76A5AULL, 0xE3E669D3AFA040BEULL, 0xA3486374F9F59000ULL, 
            0x536418D19F24E323ULL, 0x56E010FD32ADE55BULL, 0x28DF7626C43DA13BULL, 0x28965F67A905458CULL, 
            0x0F6296AEFB8EB585ULL, 0xA615887C8FA77CD1ULL, 0x4685A77FFCD567C9ULL, 0x5129A723D8F431B2ULL, 
            0xB9CAB23A1458D5ABULL, 0x5048B075337FD1AFULL, 0x7FED804A8DA47263ULL, 0x42812467B58130CCULL
        },
        {
            0xFC607B1C926694B7ULL, 0x1F78C48BEDA5983AULL, 0xF5F7FCAAA6B3EC04ULL, 0x70AF8491A1D05CA7ULL, 
            0x6F5138DF105AF4B7ULL, 0x5E0E25E64F9D6819ULL, 0xB717E688C3386CC6ULL, 0xA01E5E593D4B7AEAULL, 
            0x8C5A5A253477694DULL, 0x1CC16F10A03791B2ULL, 0x92E1BF9D8379FDC1ULL, 0xEDF92C1D66E11460ULL, 
            0x0736E804829A0078ULL, 0xCC30AB2C3CC08914ULL, 0x2B09C805EA0D1C69ULL, 0x0C3077FED56540C7ULL, 
            0x4DE34773A1901821ULL, 0x8598B70A8B72AA8AULL, 0x71F3DAC8D26C8AF6ULL, 0x1F33C1DB6BD318A6ULL, 
            0x4DC636D1B1FDD550ULL, 0x93AAAC2EC13B7FF4ULL, 0xFC26C93B5AAA0308ULL, 0xA219324F0BA34C5BULL, 
            0xA024B1A6F01BA8ADULL, 0xE13BFF5001A81CFFULL, 0xE737DB7060EDA29CULL, 0x23132BD2ED316E5FULL, 
            0xB8DED93E14FFF1AFULL, 0x51F7701C0ED84782ULL, 0xB2D344F2E92347ADULL, 0x1E83C3DC74E873A7ULL
        },
        {
            0xEA6C7AB1A70CD954ULL, 0x86EC6F9F2FAC2CE3ULL, 0xC8EDFCA86C52A14DULL, 0x1FC1E2CCD150E3D7ULL, 
            0x727DFDF169CBDA71ULL, 0xA1B81EC68B2BA7E7ULL, 0x18D241DEBB0020EEULL, 0x0DA65033208B5473ULL, 
            0x17E734E70299AF05ULL, 0xBF826730D5225ADAULL, 0xE96FE20A5DA7C0F9ULL, 0xA1B5D7648416CBECULL, 
            0xA8E098E16640744FULL, 0xD98E871BBA295375ULL, 0xAE53771D0D2FD085ULL, 0xCC77C8614B321380ULL, 
            0x9AC2D6AE30277D7BULL, 0xA87B2D3D4A167186ULL, 0xE85BAE0FF0E66C41ULL, 0x70C7CE47C7FAA77AULL, 
            0x0C482790B0DEE52BULL, 0x82940C4651F759A7ULL, 0x61828243DD95105BULL, 0x7EA0C3B4AA4E956DULL, 
            0x26149C7588A48528ULL, 0x3273363B367E4442ULL, 0xF280AAAF82578955ULL, 0x845E9E4DD1D42BFCULL, 
            0x1CB6A9BE26D1E1FAULL, 0x43C94C33B9AC5227ULL, 0x666A538805AE9B07ULL, 0x9480F899E9D07A5DULL
        },
        {
            0x896D2CB283F33879ULL, 0xC48389DA12652DB6ULL, 0xA3D84551FFC14927ULL, 0x7B0456B43D9B33AFULL, 
            0x7DC9D4E2C7F296B9ULL, 0x79C4A81B603CD868ULL, 0xD308128252CE8067ULL, 0x02A3ACCE6D4A0900ULL, 
            0xCE0FF2A828143822ULL, 0xDCE0C704A2ADC7E6ULL, 0x976BA902E46BC55BULL, 0x8B982A4D94FC707EULL, 
            0xEF277EC42859FA0CULL, 0x3E6E156FF1445A41ULL, 0xF165F12399EDDC0DULL, 0x522AB51C9C8E24B4ULL, 
            0x138708D947CFEF14ULL, 0x89C411F174827CEDULL, 0xCADA72984896C7A1ULL, 0xCC29638A3D6B16C7ULL, 
            0x8A287BAE095B55A0ULL, 0xD6C203C94A5FEBE5ULL, 0xF42713A8975DF68BULL, 0x6DE599306E33B91EULL, 
            0x12E26A468AF65EAFULL, 0xB98E1B1025F0405CULL, 0xCB768B2901F96DE7ULL, 0xD0A6B7FFBAE4AE34ULL, 
            0x6BBFB7A04CA0EA29ULL, 0xBE8BF1FF217DE37EULL, 0x6F53513E4579479DULL, 0x8C8557C55A855E1EULL
        },
        {
            0xBE5A1EC67E9E1CE1ULL, 0xD32DBDBE4DDADA5DULL, 0x6BC9E2B89DB9E504ULL, 0x581BF56BC1A75D0FULL, 
            0xABC6560D2CAB5E7DULL, 0xCC56C1F40DC7D572ULL, 0xCA168F516069350CULL, 0x77F023357A3E1F01ULL, 
            0x0897A1E16D9CCA21ULL, 0xD5252A60C8388731ULL, 0xBC08F11FB63BFCA6ULL, 0x11406BE205686E0BULL, 
            0xAFC950866DA226BFULL, 0x61A9145477959D8EULL, 0x96814D5B3A306F3BULL, 0xE4BEBE7A883AB0AAULL, 
            0x53BEE2A5DB49BDB7ULL, 0x867DCA6F0CC12BE9ULL, 0x19EEABAEB5B1E21BULL, 0x0EE1D3E72DEFF2A2ULL, 
            0xF338867013685AE1ULL, 0xD9144E87328EF94BULL, 0xE487E0B953EE753DULL, 0x459D5C3A6AB0C7D5ULL, 
            0x8120FBDDAB148FABULL, 0x62540C307E112CA4ULL, 0x521C5AB9892D292DULL, 0x23960D3B7723BC86ULL, 
            0x3C8E321FFF42D094ULL, 0x1E9317C7AA61A99CULL, 0xA63549B89560442EULL, 0xAF99FB8443718A86ULL
        },
        {
            0xC32A46258C55C170ULL, 0x8EA86F43C312C0C6ULL, 0x6E31AB865E3E1FDDULL, 0x1FB8C94D02ECE5E0ULL, 
            0xAE8DAA9DAB02B2A7ULL, 0x0B8A7BCF87FA47A0ULL, 0xDE06CDE0464873D8ULL, 0xF9F5095A8D5DB877ULL, 
            0x516125E9B3E0DB31ULL, 0xE4C8EA85DBD4CD36ULL, 0xDB867BD01DF2DB7EULL, 0xC7479B0C4DDE447BULL, 
            0xC6417E2A8EB2E07EULL, 0x44A72CBF51F4E7BCULL, 0x90B75FA72BAE7FC8ULL, 0x7D14CE6DF4214A60ULL, 
            0x8364555820C36A99ULL, 0xEC3355C6EA019D59ULL, 0xDB415DD4B6046826ULL, 0x88FF83928994ADE0ULL, 
            0x01F211DB7FFDF87DULL, 0x0FEEF771E4573CE2ULL, 0xDB3C5096FC596291ULL, 0x4DA4C609C59100A5ULL, 
            0x328D804256FA60EEULL, 0x8F11DF38A558D231ULL, 0xEFB8555E72856AD2ULL, 0x43A1A7278865591DULL, 
            0xF5988165D8204CF7ULL, 0x77C363D156DD0BE6ULL, 0xD7110EC8DE3F7ACAULL, 0xCDA3F29D2D61693EULL
        }
    },
    {
        {
            0x1EA4CF94B9EE6350ULL, 0x75043E4D05EA2D4EULL, 0x1812B25F1167008BULL, 0x0A5B1A53D759B7D0ULL, 
            0xEE788DEE82D9270FULL, 0xD487B299751C07AFULL, 0x8838B0D406629681ULL, 0x2FEB812C24B7C60AULL, 
            0xE03CD7D0DBC9450EULL, 0xEFB5E8CC7137DFF6ULL, 0x17DD591CD04489B4ULL, 0x69E7D27FE8687882ULL, 
            0x454100885BB26412ULL, 0x219ED8C4D19C1ECEULL, 0xB55B76074441559BULL, 0xF3B10F70EA9BB3DEULL, 
            0x071EEAC9D3319705ULL, 0xB8322DFB594D2274ULL, 0x7D3CF76A237959D4ULL, 0xD46F10DF6B146362ULL, 
            0xE7DA90C771BE147AULL, 0xA1C4121E9D63A9F2ULL, 0xBFD635091CE24B5CULL, 0xF8A7825AB053CDE4ULL, 
            0xF35BC85DEBC30A30ULL, 0x7B879D2D7135BDF5ULL, 0x81E37B00B2701DD7ULL, 0xCCDBA8072234E9E3ULL, 
            0x52737E30E5C12F18ULL, 0x6200E39FAF4150D1ULL, 0x6FFFC3B25B94FC2AULL, 0x0E15C17B50B487F9ULL
        },
        {
            0x1B50B5CB6462042DULL, 0x055F7616BACA31D3ULL, 0x1B136D691B47A675ULL, 0xE036FAFD98772FD0ULL, 
            0xAA57A1605B699023ULL, 0xF5E4F489C52AAF72ULL, 0xCA14BBA8430BAC60ULL, 0xD7A2B1F6BBB71C18ULL, 
            0x3CF67C0DE29C2F54ULL, 0x605DCAD4484D84BBULL, 0xCC61E15A561CC9F8ULL, 0x8F942451A5271B20ULL, 
            0xD32D6139113FC642ULL, 0x843E154EDC9AD265ULL, 0x193B5C6107044DD3ULL, 0xC8FC3BBF1CFBEBC7ULL, 
            0x87916F476044F42DULL, 0x96C0AB11C4AC85E1ULL, 0x6E2AFF303AEB279CULL, 0x3635BF867DC23FA1ULL, 
            0x0CA0B3F9E8AE39FCULL, 0xB303E016F00CC221ULL, 0x9E1A5E811A77E422ULL, 0x484431DC53DD62ADULL, 
            0x505C73FD799DE325ULL, 0x8779B8BD8E130314ULL, 0x16DDEE037D7A6627ULL, 0x0E466AC0391E49F5ULL, 
            0x4C87020BF47A5C1EULL, 0x0EE2EE1255BBEDC5ULL, 0x4928AE14340365FAULL, 0x3837DE02F46EECA4ULL
        },
        {
            0xDE0F48F94584EFC5ULL, 0xE24C4E51CEE97485ULL, 0x4259185E38B6DECFULL, 0xD84FFAC04DA6B98DULL, 
            0x78C29099FEEB30C2ULL, 0xF0D706FACAF44601ULL, 0xE9F3EB7B7C40CDDBULL, 0xF6266D95115B6614ULL, 
            0xD1489EF70B0372DFULL, 0x0977C1AD6A505D2FULL, 0x9622578BDE0FE2F5ULL, 0x005CE1E17F991399ULL, 
            0xAEA3051796DCBBA8ULL, 0xE7DFF16F99DE0253ULL, 0x586E22C2E44856CCULL, 0xE273383E4DAC3161ULL, 
            0x22A02782B1E3507AULL, 0xE3371B56DDF596B0ULL, 0x27450F1733BF8559ULL, 0xC4D6ADA28BC5E220ULL, 
            0x4EAA344A44BE1A2CULL, 0x11BD4043D14093D9ULL, 0x55D1E14C4CBD2C05ULL, 0x34D251FFD0306464ULL, 
            0xB4269BA29BBB1BA7ULL, 0xBDDB0C4D79E1341DULL, 0x9456EE32F98E6D49ULL, 0xCCE43EB4EB965B9EULL, 
            0x7093204B0A1836EEULL, 0xD4393B97F3E8510DULL, 0x5C5489A189700E2BULL, 0x2E0F84118F2383ECULL
        },
        {
            0x8D323B78E4D89E74ULL, 0x49F0B608AE95A765ULL, 0xAFEB4828510A369DULL, 0x0FBCFC07BFEBFDA7ULL, 
            0x48B9358339AFF638ULL, 0x8007607A4B1036A4ULL, 0x852A047AD17A0E67ULL, 0x5578263FD386F3E0ULL, 
            0x05ACD23C4F639E33ULL, 0x5EF28CD7821A51E6ULL, 0xA6169F319D8EA502ULL, 0xF2905BD77A48AC89ULL, 
            0xD6ED67EBBDCC326EULL, 0x16603E9953117CD5ULL, 0xFCEC5E7EC0575917ULL, 0xEDDB5CB7F4D800BCULL, 
            0x53EDA6888CC7B9DFULL, 0xA2ED3E12F9AC3E2EULL, 0x72F05CC6B8B54057ULL, 0xD666FAFE2371D7C6ULL, 
            0x85851DBA82BE39E4ULL, 0x617493C891EAA075ULL, 0x7AB531264814DB18ULL, 0xF7EADCC6B710950BULL, 
            0xFFAE003F9B13E1B2ULL, 0xEA392FE2F262F8F2ULL, 0xE0854F322D2C8A62ULL, 0xCCAB7593112E2535ULL, 
            0xF8811955BFBEEEF3ULL, 0x5244F69F2B3F7BCDULL, 0x25F737DE0375C423ULL, 0x6563D2367F0B1174ULL
        },
        {
            0xC026CDE9B621E263ULL, 0x410405F29D5D35F9ULL, 0x6270EAC51ACEADFDULL, 0x2999678F72986A98ULL, 
            0x66113F4199426DF1ULL, 0x55E966564F8676C7ULL, 0x474DC9DCB4B6A3ACULL, 0x5987912AA3DA9F5AULL, 
            0xE18690C156DF3671ULL, 0xB77ACD9D0109D618ULL, 0x3FDB0CF44BAC1F51ULL, 0xE6D8D4C09E25D8C4ULL, 
            0xEE2D44134A5A2469ULL, 0xCF685721D20B8598ULL, 0x04EE602A331005B8ULL, 0x1E5FDCD75AE19227ULL, 
            0x76A4C86009315F61ULL, 0xC5CE0A44CED12189ULL, 0x2D32975EB4382A35ULL, 0xF07139955BDBC732ULL, 
            0x6DE1A82B861CCB66ULL, 0xE91E6DD2AF789F15ULL, 0x8F880F45A06988E8ULL, 0xF6FBCB102CE4E2F3ULL, 
            0x6A8CCB8418276AE1ULL, 0xBC69C4439D55078DULL, 0x49A2E9098E803856ULL, 0x983333368F2263C5ULL, 
            0x8E96FA9D6428CAF4ULL, 0xBE799B1171B0347FULL, 0x89786F51B309A1D4ULL, 0x0C983FD2F5A0970DULL
        },
        {
            0xE359A413423C2F07ULL, 0xBD07378736038F28ULL, 0x2AF8EAE614A02BC7ULL, 0xF71273A5A2AE51B8ULL, 
            0x004A7F0BB1311E8DULL, 0xEEAEE42364FC1140ULL, 0xA3C187148956E170ULL, 0xDE5CFA3B83FA7E01ULL, 
            0xF682CB7B9A0A1AEDULL, 0xE7D86433C842BE14ULL, 0xCE5E99B0C271033CULL, 0xFDCE10ACCAB8756CULL, 
            0x34285855422A9384ULL, 0x77EE158AD45CB6C0ULL, 0xB11076750365907CULL, 0xF8DDCBCEB86945E4ULL, 
            0xE81EB8837ABE4B43ULL, 0x17EDFFFD4CCF4E6FULL, 0x53FF769D3866B1B6ULL, 0xE38448B74AF3B6E3ULL, 
            0xE3CD83E2391A735FULL, 0x342DF8365BEF71E7ULL, 0x70740CFCDF328D0CULL, 0x8F3AB0DFA92D19E8ULL, 
            0xEA921F5A6636FA50ULL, 0x3C9F75B5D191DFF1ULL, 0x343DEF1745F27D61ULL, 0x67DB9D7F3948F0ACULL, 
            0x2F33746F3B7ED095ULL, 0x46EFB36E1AAF7D9FULL, 0xCFB6A36465960320ULL, 0x9F09B94ED1F57A06ULL
        }
    },
    {
        {
            0x113E638F7CD62285ULL, 0x7C302701C6BFC1ACULL, 0x2AC2F1B1E4E9D2E3ULL, 0xBFC176BB5A7B3AA7ULL, 
            0x36E878B804402FA7ULL, 0xD27DFC693A6B9690ULL, 0xF86A114E5CF7708CULL, 0xD97448CD0F219610ULL, 
            0x4F6F538E308FC568ULL, 0x56CA695FADA564B5ULL, 0xDEC3FB3950775349ULL, 0x6AF80D9951952E6FULL, 
            0x30241E981CAC3C12ULL, 0xA2BA6BCA90E0A3DAULL, 0x14961F15E9413510ULL, 0x3033486D71D7DD02ULL, 
            0x3B746E9F20AAF0CAULL, 0xD9F4C4E8783611E6ULL, 0x36E01057C9D251F8ULL, 0x7D165CED746243D5ULL, 
            0x73B4CD66F895B819ULL, 0x4A79B5F06228ED72ULL, 0xD4E2B3357CF86028ULL, 0xFCC77DC9CF741E8CULL, 
            0x6EA0878608F28920ULL, 0x563D1DBA4740AC4CULL, 0x62835ACFFD08236DULL, 0x1D8FA690E4418D93ULL, 
            0xE49DA39FE00A4396ULL, 0x37BE135EDFFC1E87ULL, 0xD9F01A0D5ACA7857ULL, 0x9CA39B0F088A1775ULL
        },
        {
            0x511E2BCF41AFE1E7ULL, 0xA0C9C2930837492EULL, 0x9EF9C43FE3BB5E65ULL, 0x36DFAC54392F1092ULL, 
            0xA4EA66BFDC27EFA4ULL, 0xE865173F74663BFCULL, 0xE26B86FBC94EC970ULL, 0xFB0C1DC517942988ULL, 
            0x1097B531EFCA9FAAULL, 0xD824C5BC9943554BULL, 0x48467AE7C42F159DULL, 0x382D9447A35C90FEULL, 
            0x8558E83A417E7456ULL, 0xA3B7DD5BB542D3D1ULL, 0x527C24D04A5094AFULL, 0xDD1E1E1997ABF7D8ULL, 
            0xCFC56509569F12B9ULL, 0x1543C030CA37723DULL, 0xE0227E0772CC7B51ULL, 0x2791B12B44644CBFULL, 
            0x61D646A17EF4C1A1ULL, 0x789CFDB5AC15BA43ULL, 0xA1CB36295AD15D33ULL, 0x092B571BFB0F6B18ULL, 
            0x0F34E405F89A9197ULL, 0xD9950ECAE5158163ULL, 0xEE37C0FF4C42BAA9ULL, 0xFDF9300C8518EE3EULL, 
            0x61569CF2F816AF4EULL, 0x639736F971ADCC54ULL, 0x2237E0F71FAB9BAAULL, 0x10E02EC9DBE9F8FCULL
        },
        {
            0x14270A9CF702BC29ULL, 0x6011718CBB7B4A52ULL, 0x2BFBEE7BECFD287FULL, 0xEB0A9ABAD5CA9A9FULL, 
            0x9ED87611BCB205A4ULL, 0xE0F19E42D78AA56AULL, 0xF6938899222136F1ULL, 0xD057081EE211B309ULL, 
            0x307052FDC285E18AULL, 0xDD2FE8CCF804A42DULL, 0xC61F8695789DD05CULL, 0xC019F0E89054ED41ULL, 
            0x86604EC14076A5F2ULL, 0x2B5417ECA50ABF9BULL, 0xF251900F1BAF3ABFULL, 0xD9D00B5FE1C6971DULL, 
            0xD231B558AE5D9507ULL, 0xC98F50A9C6194D9FULL, 0x75189E8E0CE2D607ULL, 0x416841530CFF364FULL, 
            0xB9BC1B8434075F6CULL, 0x2AB8613AF2D3A851ULL, 0x6B25A94E0762C87DULL, 0xD9D2B376FD659075ULL, 
            0x50D720DA7C3D2F51ULL, 0xA447D7EEDB99F8C6ULL, 0xBB59F96D8755905CULL, 0xE11E962CCFDF2061ULL, 
            0x7ACF73240B61A891ULL, 0xD7EF20068EFD6F2BULL, 0x28D6CC9C1155CD23ULL, 0xD836AA35EE851EBBULL
        },
        {
            0x05B8EB24170D2B6EULL, 0x090F038043AAB25FULL, 0xACA7A16F19BC3D94ULL, 0x2739263AB76CD247ULL, 
            0xBF557F7EA3C61342ULL, 0xAE7D0FAD3B978B63ULL, 0xF0D7EC7B74BC3B91ULL, 0xA5BE01262C4F6EC5ULL, 
            0xF5034B42A4B73971ULL, 0xFB67703F4AB46B1DULL, 0x8A1099B276A678DFULL, 0x10B2A16E2FB54C1BULL, 
            0x3BED7699316E1730ULL, 0xEC8121C4FE6B363FULL, 0x6262C18D4F5B5367ULL, 0x404E95B2C6ABEB38ULL, 
            0xFEE6587E28842954ULL, 0x15C532099A3D6430ULL, 0x01B4EF5D7BF14227ULL, 0xBF118828305CDDA0ULL, 
            0x4E96684420128E39ULL, 0x51E27D958BDE791FULL, 0x83437D03F82712F4ULL, 0xB5B38A3D4801CCA2ULL, 
            0x2F3BC85C5D62A8B4ULL, 0x048950497F8F31ECULL, 0x1527A76011A7681DULL, 0xF8F49FC863D05635ULL, 
            0x393F71D4F28D0289ULL, 0xEA0861C443643E09ULL, 0xE7EAD55DC2C0A573ULL, 0xCDE9FA6D851132A1ULL
        },
        {
            0xC5817D33310A1D67ULL, 0x99F2C80726AA4BB4ULL, 0x12D7EAA2F23FFAEFULL, 0xE3B3251DD0FE1BEAULL, 
            0xF0D208E0B8B30BF4ULL, 0x81AEB9E63CCC3B32ULL, 0x08B4A68EDC507071ULL, 0xF7AEDCE4327DE82EULL, 
            0x0C322076F2EC16CBULL, 0x1AD32C9EA5FDC438ULL, 0xA8708DCFC574CA54ULL, 0xEB20A82568B4303FULL, 
            0x39DF08F5E88B0915ULL, 0x75F0E26514DA6758ULL, 0x7816335B26A52F07ULL, 0xC6DB993A0E1D2405ULL, 
            0xAA7AC8DBC601DCBCULL, 0x03195CA3884F3601ULL, 0x1F3B23AD66E60EE9ULL, 0x0A032D9942ADED7CULL, 
            0xE880FDF147B75904ULL, 0xAF87C59F6779FC5FULL, 0xF8A4BF82592E9375ULL, 0x6E3A50AEA720AB1AULL, 
            0x2164A6824C568921ULL, 0xC6E7325C16D870A9ULL, 0x04DCE91E873637F4ULL, 0xC2B0230741FE74D2ULL, 
            0x859E03DD40DFB429ULL, 0x6BCC23D797CC19BAULL, 0x63A877B2BD6CDDB4ULL, 0x8080AA7F6A77DEFFULL
        },
        {
            0x6DACE1BA8010AB60ULL, 0xC628732A06B29593ULL, 0xDE2AB41AE54BE236ULL, 0x576FFEDF40441B5EULL, 
            0xBE8D9874863E3E45ULL, 0xF7E3565AF2C366A4ULL, 0xAF73771A71EEDD1BULL, 0xE8D9FF873960688AULL, 
            0xC9B0485C5E9C777AULL, 0x7A3D31CF1C59675DULL, 0x76C3C924B73966CFULL, 0x6B924CFAB132CA10ULL, 
            0x3C1E0A3F9EC9CFD2ULL, 0x4DF5300BCA207F2DULL, 0xFDE5384C778B51AEULL, 0xF2A5A28256F5BBB8ULL, 
            0xFE7DC0F87DDCF299ULL, 0x0EF8A679B813A241ULL, 0x214B9A1ADEB4484DULL, 0xB91363C23F86A4CBULL, 
            0x6B7C49670A7E5226ULL, 0x88A93DB2AF0D8EC5ULL, 0x84C7BF1A34C53003ULL, 0xED52444BC580DCB8ULL, 
            0xC2DA6AE15525EA65ULL, 0x7F04239435B7EFF9ULL, 0xAB8D7E6A08BCACD5ULL, 0x8779F950191349E2ULL, 
            0x7DF691E0645E44A5ULL, 0x9FA09A29AEE86666ULL, 0x302A10F9D3E0E565ULL, 0x3DA7BBEBD09AC91AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kSeedConstants = {
    0x4C026B29297FCB8AULL,
    0x7845342373D74B0DULL,
    0x90C048E989D3CB49ULL,
    0x4C026B29297FCB8AULL,
    0x7845342373D74B0DULL,
    0x90C048E989D3CB49ULL,
    0x120DFB2F54F7C1F5ULL,
    0xF39D28471199E431ULL,
    0x2B,
    0x37,
    0x7D,
    0x71,
    0x37,
    0xA8,
    0xA5,
    0x4F
};

const TwistDomainSaltSet TwistExpander_Canopus::kTwistSalts = {
    {
        {
            0x269AD26E2455E7C0ULL, 0x545BFD508D9BE2C5ULL, 0xEF01C33D3766DDDAULL, 0x4C4F934452AD7189ULL, 
            0xD9C261A40D6CC988ULL, 0xF99417382F1FA54DULL, 0x69427F5DD8520031ULL, 0x9AE6A107E42B22A2ULL, 
            0x26C9A86FB7B0AADCULL, 0x595995F1C3C5B823ULL, 0x255BF0F20535B481ULL, 0xAC608532BB7CF2EFULL, 
            0x614C03787B2FB047ULL, 0x63E807AF742C100CULL, 0xDB5FAA528D27645AULL, 0x79E135BDCC265EB2ULL, 
            0xDE476BE860090848ULL, 0x14A52488568CC54BULL, 0xA4DB13DA31986A84ULL, 0xC3C990F1BC3877A1ULL, 
            0xEFBB66CD8F29E291ULL, 0xA52119A8DA650501ULL, 0xD341FE51E2475F8BULL, 0x9A5F7094CADFF5B6ULL, 
            0x61213EBAFA68009EULL, 0xF1039496E13E4087ULL, 0xAF24DFC2C68168ECULL, 0x2C9EB2702418DBCFULL, 
            0x5DA528BF430087EEULL, 0x32E9AD711CC32DFEULL, 0xABCCB7C016245D8EULL, 0xF32F91281A800524ULL
        },
        {
            0x816222E128CD00DDULL, 0xE20DA2B52222D72CULL, 0xC27B830CFBA2C32FULL, 0xA5055C070AB6B434ULL, 
            0xDB170AC2FE69DE96ULL, 0xF282DF53F7C23BC3ULL, 0xCEB1A1EBFBBFDBE4ULL, 0x275D76E951D26611ULL, 
            0x963226D8E06A78B7ULL, 0xDBD65566DBF341D3ULL, 0x7846A1D7BB21E201ULL, 0xF3D3DB8808E347C4ULL, 
            0x5D50AE10CB8A38CFULL, 0xBE9B36D4C1656862ULL, 0xCBB5F8BDA8FC444CULL, 0x7521B05CEB18016AULL, 
            0x6AD70045DA70815EULL, 0xD84432B189ED145EULL, 0x66DAB560005A3835ULL, 0x0A4A57F6F280045AULL, 
            0x96C0462720ABBD10ULL, 0xA02FCCD0EDB229C3ULL, 0xA2808CB1702531C6ULL, 0xD354C56FD6649B52ULL, 
            0xBB590D6BFEBEB7B3ULL, 0xAEAA984CB223E8B6ULL, 0x1DAB03514742D369ULL, 0xD496DDB335A09C9BULL, 
            0xADB84327997C0D1EULL, 0x37D3F1DCDCB9DB1EULL, 0xDDCB3B0F5D7C57A5ULL, 0x97FF5325F2B7274BULL
        },
        {
            0x70423D47B3452785ULL, 0x14E7140C550ECBEEULL, 0x4528DCA40CE5ECB8ULL, 0x58191A4C02F8E203ULL, 
            0x884611B0DCAB287EULL, 0xB8DB94874E8B086CULL, 0xEB2646612C86A535ULL, 0x686C7AD00B043577ULL, 
            0xCFCDC729417DCB20ULL, 0x3690D1CA5AAEC40AULL, 0x1C14695CAE09C742ULL, 0xBE4F11F1A37E7245ULL, 
            0xFFC93DF381787EA8ULL, 0xCE6A964346DC9DB9ULL, 0x64C2FE9447329302ULL, 0x63B84AD7091AA789ULL, 
            0x202220C0D703BBDCULL, 0x79AF9E1BAF22D519ULL, 0x97D4DD11AC230294ULL, 0xA0C437E55CE7B31EULL, 
            0x41556F19C5C1A0BAULL, 0x349D31D5253C6D79ULL, 0xDD9BC64E7F9D6CC4ULL, 0xD5D20C1826046106ULL, 
            0x383F3FEB556F625CULL, 0x98AB44A4B14C0152ULL, 0x48F687BCE6621375ULL, 0xC691CB4235144657ULL, 
            0x923FF2B75F251A77ULL, 0x786B330FB12564FDULL, 0xE4E45A8D8E4769C6ULL, 0x25F0BBAD18066733ULL
        },
        {
            0x7285BDA7A3FA9B7AULL, 0xC26C28BE1D0253D9ULL, 0x194530A70C3C309AULL, 0xF3461B8B9DEE8A68ULL, 
            0xB52BFC0C67B3A3C8ULL, 0xD733558CD455DC3EULL, 0x09FCA37E13668D06ULL, 0xE9EFA1899B9AB62FULL, 
            0x4D8B3FE9A23F7503ULL, 0x80A711EDA9732FD1ULL, 0xB9FC997EC3BB3727ULL, 0x4D1C759E60024DC5ULL, 
            0xB1309F3AFCBECCF1ULL, 0x251FCC791E3ADB99ULL, 0x038545C54B0E3683ULL, 0x78BF0D4720144AE7ULL, 
            0x8CFC2DCC4C6D8FC6ULL, 0xD8B39AA7F1B73C87ULL, 0x8585219CDF53D1A9ULL, 0x36291277675839CDULL, 
            0x906FFFC2E27CB2BFULL, 0xA128CDC689ED65CFULL, 0xF8B23EE210E3B4F1ULL, 0xD49AE67CA75562F7ULL, 
            0xC26D5FABB6E8A319ULL, 0xEA9E22C3E5DDD294ULL, 0x954C043AEE32E09CULL, 0x315C8898EAFBA881ULL, 
            0xF445ECAC4BB0CB65ULL, 0xE8104EEC302B5116ULL, 0x5A7CA691BA65B5DBULL, 0xB7830C3F2420179AULL
        },
        {
            0x7A77F1ECC33315B1ULL, 0x9BBE1A6179269E96ULL, 0x6CB28302CBA5E65BULL, 0x7483E5694484799CULL, 
            0x9F335AB7D081CA4CULL, 0x0C9AFAE12525AFF2ULL, 0x6F0A6ABB7C04D16EULL, 0x024F98C943BDE3B1ULL, 
            0xEE64AF4C5C36FCF4ULL, 0x33227377BC25A86EULL, 0xF769C7EBDA519A1FULL, 0x4E0A2C5B4A4F48DBULL, 
            0x7BCF059D69D17B33ULL, 0x1F7C742B694CB704ULL, 0x432214F48EC0A09DULL, 0x644CD51D95669E80ULL, 
            0x0B053904B457275BULL, 0xA144324F1884C6B3ULL, 0x542CDD4EFE7DD74CULL, 0x62628338CFAB6DE8ULL, 
            0xCFECD04B59849CFCULL, 0x580D897E854CE022ULL, 0x357C676117A983EFULL, 0x75DB816EA270130AULL, 
            0x7C09D9D53027FE06ULL, 0x7AAE9A15E10F7A70ULL, 0xDD66070ED72E2FAEULL, 0x04FFA16F2724A4C5ULL, 
            0x2A9633F003054BC2ULL, 0x1150BA3761710361ULL, 0xD8824DC04721FE5EULL, 0x64803CEBD36564C3ULL
        },
        {
            0xA65A1973782B5156ULL, 0x53411E68EB1D594EULL, 0x632B3D6A0A6101DFULL, 0x76E68DA90FEEF3A0ULL, 
            0x11778867EFD0F380ULL, 0x3CB340C42732E4DBULL, 0xECF96A173E9DA818ULL, 0xCFBD3E86C60B0698ULL, 
            0x64FBF3C32E56C8E4ULL, 0x022746AFFDF4B5C6ULL, 0xC73D055F8C21B22EULL, 0x8D88C5B61C459261ULL, 
            0x9F0FF55AFA385193ULL, 0x95AA06D67E2862E3ULL, 0x745C3DCC2010E35AULL, 0x6607F19EF3ECCDD9ULL, 
            0xB621C58F4E733F8FULL, 0x833E190D9373B9A7ULL, 0x2978D66A21A22168ULL, 0x4A18C54E5434CB84ULL, 
            0xFDD8F52C7537B2E2ULL, 0x6E0B1BF968366CEEULL, 0xEE4AD5EB55649C1CULL, 0x9EA7526545CE6A1BULL, 
            0x8A61A146672EA5F4ULL, 0x892D6BFBA4F2D48DULL, 0x0342B95DE0E1D470ULL, 0x481AE0453537D44DULL, 
            0x8F37E914B4DDD12AULL, 0x09B7C7D05CF82929ULL, 0x7CC695FEA3EDC618ULL, 0x7D5EA6A885BE5E78ULL
        }
    },
    {
        {
            0x268A128FA8430926ULL, 0x8ABDDC818E3B01EFULL, 0xFF812CCD7B8E8FCFULL, 0x05D030CED3713D63ULL, 
            0x3635BF89333894DFULL, 0xC208108F39B2125BULL, 0x1A800A369FF8700BULL, 0x146838A4C917EBE2ULL, 
            0xA4B0EBC06FC2E5D4ULL, 0x94209699D4FF6E42ULL, 0xAD85D03844F00D9AULL, 0x4BBD5E15271CC67DULL, 
            0x903DDD8C2E4A7799ULL, 0x6C878D33E872F845ULL, 0x7E43768230B878DEULL, 0x200CCA39E124E28FULL, 
            0xDF4E989DEDB4EE75ULL, 0x74E6962C2DA87D58ULL, 0xD0B7F1C997599003ULL, 0x3CDCE0F4BC7A0FACULL, 
            0xDB96DCA3C1E48D37ULL, 0x53424FC75B4FC0A6ULL, 0xBFC05279B03C4479ULL, 0xFBC227449D23D724ULL, 
            0xA19FE7FEE7021C57ULL, 0x158E963BA1481517ULL, 0x0D944761B48F7025ULL, 0xED4254690B1BFFE5ULL, 
            0xD35AD25D6CBC304FULL, 0x620F53DBAD4F6CD9ULL, 0x33B995317050038FULL, 0x2C1E599FAE1D00AFULL
        },
        {
            0xFD28793066D95EFCULL, 0x1B5D07DBFCA2706EULL, 0x39FF7B9327E8DE63ULL, 0x69D3CFEA1DFA5B62ULL, 
            0x1E7C994C9D7D2746ULL, 0xAB5F770E8673F8FFULL, 0xE61457981BA1B565ULL, 0x621D2DF718352490ULL, 
            0x02C9EC6E3F62F424ULL, 0x8A2BCE8182C6046FULL, 0x5EB3CA38B078401BULL, 0x7A2F30B560D7BFB4ULL, 
            0xA3017DB070F6B40FULL, 0x270FBE4FC6B313AAULL, 0x1137DF96B5017442ULL, 0x01A53D7C9E8FB660ULL, 
            0x314959917335AF45ULL, 0x831268FFD7A8CD8EULL, 0xB618302F58B513A5ULL, 0x97D3977681EFE80CULL, 
            0x848ED179A9DACCE2ULL, 0x176CB3169185FEA4ULL, 0x5589C7232BE5B8ADULL, 0x8F631DA49225A0E4ULL, 
            0xC8A0A3DBD0D8D37CULL, 0x060180BFC3A6C87BULL, 0x46E4CE5964D48FA1ULL, 0xFBEA3372714083FFULL, 
            0xFCA24B2296E3A660ULL, 0xFB5A17B79ECA8513ULL, 0x517F5D615B2417D4ULL, 0xBD49E513B858176FULL
        },
        {
            0xDDFBF2BA928D3145ULL, 0x580B511D3EC8FAD0ULL, 0xEA74E36FA478BDA1ULL, 0x4F8F0488C1C7E2A0ULL, 
            0xAE095D66DB0895C7ULL, 0xBEA9D619AD5AA977ULL, 0x2C22490BB372C867ULL, 0x178FF171F6B5025CULL, 
            0x13B524AE5E179EDDULL, 0x47ADF83960D9AB5AULL, 0x1D446D8A96F56A58ULL, 0xB9B41E12683979FDULL, 
            0xE69E72035FB9B597ULL, 0xBA20E35E549854E8ULL, 0x41DB7966B8BDD0C3ULL, 0x8130C74F9C3A68F2ULL, 
            0x97323087AB7BB421ULL, 0xBC0ABC64EF6A129CULL, 0x2257D87B7829013EULL, 0xBFD62D7310ACEF61ULL, 
            0x2C4C6834FB89B2D3ULL, 0xDE22CF53C5633AC3ULL, 0x2C5703973FD02F49ULL, 0xC9DC23CDAAB3C3C1ULL, 
            0x6F15CD404F5F1FBEULL, 0xC06DBB4CD0B7D293ULL, 0x5AFC24E66A2DC7CAULL, 0x402216958BA5E7ABULL, 
            0x3008DF35EE627A5AULL, 0x2BB279DEAB82933EULL, 0x328E51A608EC2644ULL, 0x3B51D93BA4D83D96ULL
        },
        {
            0xF318D034913E686CULL, 0xAD0E2BD46D212BF9ULL, 0xD387E2BB9BDE422AULL, 0xF70AE35B541ADBDBULL, 
            0x7C0434F937D1DFB1ULL, 0xA4E26DCD7E22C9B0ULL, 0xECC871801E5286E1ULL, 0xA85AE810F628EE2BULL, 
            0x6607107629176FBAULL, 0x1F7712A94B517E42ULL, 0x0AE6B3DC29CEFB12ULL, 0x2DB92617FA767F2EULL, 
            0x5BFE60F7D2B769A3ULL, 0x0330D4619877DE71ULL, 0x480501ED695A20E7ULL, 0x0063BDB497CE7E3CULL, 
            0x451A4EEE3ED13EECULL, 0xA76D12E22987F1EEULL, 0xD4CB33D17BB68A66ULL, 0x52A7CA0D240CCCE9ULL, 
            0x8C4008BF9A30663EULL, 0x44E4A0657B183228ULL, 0x1764C3AC91F22FDFULL, 0x2BBBE48521A2E177ULL, 
            0xD93D453777807D90ULL, 0xA9DBB19AF3AC17B4ULL, 0xACE73A67A3064BF0ULL, 0x76D6B283374A8630ULL, 
            0x2289F802D4307DA9ULL, 0x3A0AA83A9176D7B4ULL, 0x175C6ED94FE349FBULL, 0x6D6AF51741B9C4C5ULL
        },
        {
            0x005A6801D4D72D8AULL, 0x9911505707C9333CULL, 0x21BE140E4A611D77ULL, 0xFC75496422F3E61DULL, 
            0x902969A1E5DBB5A4ULL, 0x76345933E29EF28BULL, 0x6D8C7410433808A3ULL, 0x3827E6FF485639A6ULL, 
            0xDAAFDC0B70ADDB63ULL, 0x9A3B6DEACC5A9355ULL, 0x46282D8FB1EF5CDCULL, 0x1D3C3FB30A37294AULL, 
            0xEFFA1451DC560954ULL, 0xDB762279BE9490D2ULL, 0x47E836EDA7B2DC13ULL, 0x52DB63E41FB820A8ULL, 
            0xAE7183A37CDD221AULL, 0x68E02E4D9C7831B0ULL, 0xF6BAA7FED837C5A1ULL, 0x2452CC1DF7F877EEULL, 
            0x2F77643B6C4E895DULL, 0xD97DE9170C521CABULL, 0x51757E9B6E13326FULL, 0x766F5AEDCE0B6622ULL, 
            0xDFDADC09306D4A28ULL, 0x320E1814F2FC76DCULL, 0x21E15BA9D932D096ULL, 0x864B8B12D2EDA9E5ULL, 
            0x1DD9782D14CED7B5ULL, 0xB0633BBFA9DCE9B3ULL, 0x1682041AABD81511ULL, 0x3149CAF5B3DB4B1AULL
        },
        {
            0xB69FF83066769696ULL, 0x2AB1185856E99793ULL, 0xE8E0C392626563B5ULL, 0xDDF122141ABE9A92ULL, 
            0xDC9DC8F0DF315063ULL, 0x5DB1ACD678423711ULL, 0xF12122FFD87AADE3ULL, 0xD79D135142ACA928ULL, 
            0x48E3A3655FB942F6ULL, 0x557492602C865226ULL, 0xDD4F5CF7A6C2ECE5ULL, 0x631906C0F91E5A99ULL, 
            0x432E93DC001C0616ULL, 0x797538B45FAA7D1EULL, 0xE14B4B9F91D8E312ULL, 0xDC318D2F9AF4BA4EULL, 
            0x0C1B4C99EF0719BCULL, 0xA9242164DD6083DBULL, 0x3A31DE6CE7497F27ULL, 0x885B5524922CD716ULL, 
            0xDC15F8B8F01DEA06ULL, 0x67D1AE12A81DA4A7ULL, 0x98E4580C3C014681ULL, 0x6F6D1050B1453732ULL, 
            0xC893CD7B4F5F66A5ULL, 0xA10721CA301F70BBULL, 0xF0BA1BA4E2A98C7EULL, 0xF0D9CA572E42C9EEULL, 
            0x5DBB7DA70F1F4E4FULL, 0x24984D923A080C71ULL, 0xF4A51B454A32456AULL, 0x49CB6FDEDBA11429ULL
        }
    },
    {
        {
            0x59F54207B33D1621ULL, 0xD83861EE7F577BFBULL, 0x01B51BA22500EF98ULL, 0xB263D6184065DD40ULL, 
            0x99595446E23B5E97ULL, 0x1A0351594FBFEA9BULL, 0xBDCFA73003AA88A7ULL, 0x7443290969C161FCULL, 
            0xA7B83B1780C3C29CULL, 0x69B2B1AF7C768CEEULL, 0xF00DA20F5B3962B2ULL, 0xDAFA7A0B8A5A3C2AULL, 
            0xEA7F3DCB49FFAEC5ULL, 0xF14A39EF84A1CF75ULL, 0x0431AD24FBD97152ULL, 0xA5E09F90569BEA75ULL, 
            0x57494A7CBD539B46ULL, 0x7DE31CE2DC9BB199ULL, 0xEFD587EB5A4E77FEULL, 0xE90862AE0D6E378DULL, 
            0x1CAD8646516683FCULL, 0x30E24954134E14D4ULL, 0xB925E0C465E27D4CULL, 0x926AD37DB3733FECULL, 
            0x679C15D97BEA34C1ULL, 0x9F8758453BB957EDULL, 0x139C5FBB98423661ULL, 0x0361A3724D0C604CULL, 
            0xC777A7A968899B8FULL, 0xAECE727DD156D456ULL, 0xFDCD1E1F872F564FULL, 0xCB8DDFD44CFB2C8CULL
        },
        {
            0x6CBF75B570176A4BULL, 0x14709045B01928DBULL, 0x73897D5A26BB8424ULL, 0x9D4E7C026A0E45F6ULL, 
            0x3C9FAFF3D600426BULL, 0xA047B1CEBD050C46ULL, 0xA3223AEF157DD79BULL, 0x96659F0275FA3647ULL, 
            0xCDEAE4A865559795ULL, 0x6CAE1B6D22E9553DULL, 0xA4F0D9B4BCA6F8BBULL, 0x228E1A067165031DULL, 
            0x6621E5B6905859DEULL, 0xC767B6D83038A3B2ULL, 0x2577A9FF2A4CDB4BULL, 0xADB66BA1ACD634A1ULL, 
            0x3CFD9D05DF326178ULL, 0x07C845AE7B0C899CULL, 0x51714E129AF1F770ULL, 0xC4B2505918205F32ULL, 
            0xA101F6C796F8C9DDULL, 0x35D880A41C48BCA2ULL, 0x785B5E267194E1BEULL, 0x5F3807A4F2C36553ULL, 
            0x5EBEDA6CA77D4E92ULL, 0x2C29741A354D623DULL, 0x7BB53BE8369E3C6FULL, 0x5A2641ABFFAFFA1EULL, 
            0x2BF7E72C4F80E889ULL, 0xB8D9DEF553FE2CE2ULL, 0x1B615321014FCF5FULL, 0xED938E4393A4D25EULL
        },
        {
            0x3F86FCFF649D88FEULL, 0x6320B5B5B671658CULL, 0xD3A42D44FD8A695BULL, 0x51166D539BD37B2BULL, 
            0x764D5E1A48831C60ULL, 0x97962AE51C8FDD09ULL, 0xAA4601B9A4FF8D29ULL, 0xA4DD34F2168EE494ULL, 
            0x58A2D894FF357725ULL, 0xD6F19A71FF0D9802ULL, 0x729A2D923D373AAFULL, 0xABB68676D1B72F56ULL, 
            0xB92F8244D5B278A1ULL, 0x6D9DF4CE27B9572BULL, 0x7C75D7C5DE1F075EULL, 0x6D4A950D6216A804ULL, 
            0x1821575393FED452ULL, 0x5D200CADB2FA2E5FULL, 0xFF711E732BF4821CULL, 0xC70F76AF54B7A042ULL, 
            0x1AF67CF5B4AE47C3ULL, 0x52FFBEF446E5369BULL, 0xA5DD76864E5BF262ULL, 0x8E916EA36E5A34B8ULL, 
            0x094A81DBF5BB55DDULL, 0x065E9BF8C7405672ULL, 0x56B7125786101025ULL, 0x59AF9D0C4C241FB0ULL, 
            0xC94FE5B2B80E81E3ULL, 0x93F76231A8114244ULL, 0x826B12028DCED8A7ULL, 0x74C80F43F0711D59ULL
        },
        {
            0xEB62E98D6BA906C9ULL, 0xAC3923656DC981CAULL, 0x7AE9900EE939A9D3ULL, 0xEA86283F24330942ULL, 
            0x9F647E9BB8D47568ULL, 0x1977C8534FF96574ULL, 0xE5C138869388DB7EULL, 0x0CB247CA0762F934ULL, 
            0x0FB4369297C6ECADULL, 0x91C9C6CFF610B6D0ULL, 0x30DE5B65AADD0A6DULL, 0x775749251F74B6ABULL, 
            0xA8AD927C4CECC2C2ULL, 0x1DB855CAF5A02DB3ULL, 0x01F76653FC3A0192ULL, 0xADCBF943DE7DC8C1ULL, 
            0x86E6631F8FB6EEE1ULL, 0x007AB2A23F649B8FULL, 0x0A21561AAC0B4060ULL, 0x621C4728CDE1F1CDULL, 
            0x8CFFBFB93A2C3C8BULL, 0xD2F6C8A948EF06CEULL, 0x1B453DC056AA9DDBULL, 0x822D34857C7AB75AULL, 
            0x19FF591D6659D135ULL, 0x1FB0D75699D2E964ULL, 0x2BD6B49FE7B3B1D4ULL, 0x93C398580B30C30FULL, 
            0xA24FA11B54067DE3ULL, 0x1D68B24A0F5BAD00ULL, 0x4E0D23313CD20092ULL, 0x253D9CDCF004C82BULL
        },
        {
            0xDFBDB5F3F3D63977ULL, 0x016155AD783096D8ULL, 0xF05021C749AFA45AULL, 0x29D608EB86BFDC8AULL, 
            0x008378ADD50E0735ULL, 0xDD163858B6EA4E78ULL, 0x517EAB6C924F519FULL, 0x599A367B707C309FULL, 
            0x47466C7E88CBCDDCULL, 0x3D1D0FF696EDB8A1ULL, 0xA3ED7A2EE2C68F4DULL, 0xC61A569017227D17ULL, 
            0x1CD995CD1B9FA275ULL, 0xC1F550864C9088A8ULL, 0x06F85330D7DAA420ULL, 0x8BD107D276ACD358ULL, 
            0x6D31485C55859D08ULL, 0xDA02C1F4F2566350ULL, 0xD1619B1EEBA6809AULL, 0xD690F20D1DCBF06AULL, 
            0x968F03FB4B9DE59BULL, 0xD2F8B5077514C230ULL, 0x0DCADDC95FA34CE6ULL, 0xA3E587FD376D8D65ULL, 
            0x7ED13364ADBCFF83ULL, 0x66F497E147361018ULL, 0xB23A01CD51AE54D4ULL, 0x4A3B2BBEFC95223EULL, 
            0x4C1C17E0AC8CC105ULL, 0x504C9E3E4EBE5F46ULL, 0xD4FEAFFA477E0DB9ULL, 0x6D307674AB65DBC7ULL
        },
        {
            0x0DF3574D1440FF68ULL, 0x0C574EB304FDFD8EULL, 0x114A6034F19C685FULL, 0x76D8A4B4E6BD2CABULL, 
            0x096489C9AA36E80FULL, 0x043E910FEE73D284ULL, 0x101BFF8A722B9FD2ULL, 0xF2467C46D6640FECULL, 
            0x2F2D8A2CF23A2494ULL, 0x42B870DDD2D21E44ULL, 0xCB39F8A794387BFCULL, 0xB7B6CD1F90ED795AULL, 
            0xD7235E8669F4DB47ULL, 0x67B7802D73695C16ULL, 0x9579ABE12B532B54ULL, 0x480989E2D8DECBBAULL, 
            0xBD92589C296E9AA5ULL, 0x280E2708896DD84DULL, 0x3C09019FD075D100ULL, 0x14FB7722B2DB44DDULL, 
            0x7D984F84C90FC0CDULL, 0x7EED4B3B211B6E11ULL, 0x12C53675E29BDB5CULL, 0xA6DB13F9B03ADF51ULL, 
            0x0FF884AA9C2B81D4ULL, 0x4AA9AD9FF6BE8386ULL, 0xDD65360C82ABCE24ULL, 0xA0F188528B48902FULL, 
            0x2EE1A7B87ABDF8A0ULL, 0xC910919B6BC24E20ULL, 0x0E53E96113B34D3BULL, 0x2ADA91803D202600ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kTwistConstants = {
    0x8ACACEA3E54171B6ULL,
    0x725C83DC5B22EB4FULL,
    0x051B3C91B09CD55AULL,
    0x8ACACEA3E54171B6ULL,
    0x725C83DC5B22EB4FULL,
    0x051B3C91B09CD55AULL,
    0xD4842A22089006FCULL,
    0x8A07B1F79EE22A24ULL,
    0xBC,
    0x83,
    0xE4,
    0xF4,
    0x3F,
    0x02,
    0xA1,
    0xAC
};

