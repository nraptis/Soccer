#include "TwistExpander_Aldebaran.hpp"
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

TwistExpander_Aldebaran::TwistExpander_Aldebaran()
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

void TwistExpander_Aldebaran::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB7C8E2C60E98D4CFULL; std::uint64_t aIngress = 0xF77E625095EE1749ULL; std::uint64_t aCarry = 0x94F7E40AE83B9340ULL;

    std::uint64_t aWandererA = 0x9817EA3B7CE6577AULL; std::uint64_t aWandererB = 0x8CD5946415B26CF7ULL; std::uint64_t aWandererC = 0xF792AE641A753D03ULL; std::uint64_t aWandererD = 0xD4B0D3A0C243500DULL;
    std::uint64_t aWandererE = 0xFD1EE010A24F87D8ULL; std::uint64_t aWandererF = 0xCF92203D30438C6AULL; std::uint64_t aWandererG = 0xC2EDBB05C6D40D56ULL; std::uint64_t aWandererH = 0x8B1382FD4E967711ULL;
    std::uint64_t aWandererI = 0xB315CC02F9809A89ULL; std::uint64_t aWandererJ = 0xF6F268BC4E8B28F0ULL; std::uint64_t aWandererK = 0xEBB5E49427326239ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8690F455BA8725B0ULL;
        aCarry = 0xBD4DE64E353FA64FULL;
        aWandererA = 0xF0081A8604FFFB33ULL;
        aWandererB = 0xD9041B1A54C5A429ULL;
        aWandererC = 0xFC4099BF4480B28AULL;
        aWandererD = 0xD07A0266C782793DULL;
        aWandererE = 0xAE79A2C0BBAFB7E5ULL;
        aWandererF = 0xDA9B4792FAC05811ULL;
        aWandererG = 0xE745A482A4496B9CULL;
        aWandererH = 0xC9AC0339AC0BA349ULL;
        aWandererI = 0x82E44CDF873CC0B0ULL;
        aWandererJ = 0xD6B38A02C0359735ULL;
        aWandererK = 0xBDCF801C2476DC0AULL;
    TwistExpander_Aldebaran_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDCCAF18284A49C70ULL; std::uint64_t aIngress = 0xC4C0156A6ED29C75ULL; std::uint64_t aCarry = 0x967D85755E5B4469ULL;

    std::uint64_t aWandererA = 0xA42FED5DB277301BULL; std::uint64_t aWandererB = 0xA583FB808923143EULL; std::uint64_t aWandererC = 0x81160C0C03BD87E4ULL; std::uint64_t aWandererD = 0x969C99022A54E628ULL;
    std::uint64_t aWandererE = 0xF4EFF50B1C86045BULL; std::uint64_t aWandererF = 0xF6C5FABD1F3A80E2ULL; std::uint64_t aWandererG = 0xFCE43735339771C4ULL; std::uint64_t aWandererH = 0xA2D1D85858F8B0E3ULL;
    std::uint64_t aWandererI = 0xD56E7B3EDD1B32BCULL; std::uint64_t aWandererJ = 0x8B2BF2AE55F8003BULL; std::uint64_t aWandererK = 0xAED1604DF1F4B367ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE4B921DAFF9C309EULL;
        aCarry = 0xEA1339615957CD50ULL;
        aWandererA = 0x8A34736A12DB0B6EULL;
        aWandererB = 0xDB2661AF957512B1ULL;
        aWandererC = 0x857AB65741E54F00ULL;
        aWandererD = 0x857852588BC49B44ULL;
        aWandererE = 0x86125B92F62BE9A8ULL;
        aWandererF = 0x95A4EF18AB5FB0E9ULL;
        aWandererG = 0xD4DE49B5F99A7FA6ULL;
        aWandererH = 0xED53CE7DF4AA8619ULL;
        aWandererI = 0xDD8CA0BBE3A7F71FULL;
        aWandererJ = 0xBC99224768F4505EULL;
        aWandererK = 0x8EA253591141E6ADULL;
    TwistExpander_Aldebaran_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD81F4392B4E02220ULL; std::uint64_t aIngress = 0xC7CBC28340EF6B4FULL; std::uint64_t aCarry = 0x859EABD648BB5B39ULL;

    std::uint64_t aWandererA = 0xA2584DB1F9E722F7ULL; std::uint64_t aWandererB = 0xED1589911EA11F41ULL; std::uint64_t aWandererC = 0xC4D2E78320628EF2ULL; std::uint64_t aWandererD = 0xAA22B6613D662800ULL;
    std::uint64_t aWandererE = 0x902F2D9B48962807ULL; std::uint64_t aWandererF = 0xF84E4F5749081081ULL; std::uint64_t aWandererG = 0xABAE601ED4664C3DULL; std::uint64_t aWandererH = 0xD1C6715E8213E8C1ULL;
    std::uint64_t aWandererI = 0xB9A5B8F3BFDAE234ULL; std::uint64_t aWandererJ = 0x8C9DA97F3C495A26ULL; std::uint64_t aWandererK = 0xEB221FC6AFDFBFF3ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8642B7CA8E49F96FULL;
        aCarry = 0xB95BDB7C298354B7ULL;
        aWandererA = 0xD6FF199AE715E2CBULL;
        aWandererB = 0x8C9DF30E97F7F980ULL;
        aWandererC = 0xCA5206307367B672ULL;
        aWandererD = 0x88F188F3BCEFE5CBULL;
        aWandererE = 0x8E0AEC9393E05027ULL;
        aWandererF = 0xA0CD713635430D1FULL;
        aWandererG = 0xAFF6023491BC4F12ULL;
        aWandererH = 0xB1AA189D44676063ULL;
        aWandererI = 0x8852D0C7B0250DBFULL;
        aWandererJ = 0x94D46390F011CAAEULL;
        aWandererK = 0x83A50BC9BF7F796AULL;
    TwistExpander_Aldebaran_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC62FE403F78226FEULL; std::uint64_t aIngress = 0xA8BBE4EC95120B08ULL; std::uint64_t aCarry = 0xD7C5A5721B965070ULL;

    std::uint64_t aWandererA = 0xBD87992D19F97E0FULL; std::uint64_t aWandererB = 0xA88CAA9CCC6C8642ULL; std::uint64_t aWandererC = 0xC2D90EFC19290AD1ULL; std::uint64_t aWandererD = 0xD6297D01C64BC25AULL;
    std::uint64_t aWandererE = 0xF2CFD6636123476BULL; std::uint64_t aWandererF = 0x8DC80C0530CEB745ULL; std::uint64_t aWandererG = 0xEED7A928B47FB4BBULL; std::uint64_t aWandererH = 0xA717238F8B0EA355ULL;
    std::uint64_t aWandererI = 0xB48AE5CAB0BFF55EULL; std::uint64_t aWandererJ = 0xEED1C931EDBC59BBULL; std::uint64_t aWandererK = 0xF7AE6E6199DF62EFULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD224D6490241EFF0ULL;
        aCarry = 0xD8779C479A5F13C6ULL;
        aWandererA = 0xB7D99C7C6E1C787CULL;
        aWandererB = 0xEEA00F887411CF09ULL;
        aWandererC = 0xB05EABD966BE3F61ULL;
        aWandererD = 0xCCAD4503FCCC9902ULL;
        aWandererE = 0x9C3AA44564BEF2F4ULL;
        aWandererF = 0xF146BB052FD1255BULL;
        aWandererG = 0xACAB5429603B848DULL;
        aWandererH = 0xF287F75AFE0DBEE8ULL;
        aWandererI = 0xAD333C6AA938A828ULL;
        aWandererJ = 0xD2DF6FE6FED1E3DFULL;
        aWandererK = 0xC991F24F9BFE8CE5ULL;
    TwistExpander_Aldebaran_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x911C58041BDC389BULL;
    std::uint64_t aIngress = 0xD9648813CBBB5D7AULL;
    std::uint64_t aCarry = 0xDF33DF993D900247ULL;

    std::uint64_t aWandererA = 0xA526D567CD0064DBULL;
    std::uint64_t aWandererB = 0xFDEAFE3AABC6A50CULL;
    std::uint64_t aWandererC = 0x9536C343941E014FULL;
    std::uint64_t aWandererD = 0xE922F9F76C758B65ULL;
    std::uint64_t aWandererE = 0x8B7816A11EBD35FDULL;
    std::uint64_t aWandererF = 0x86942FB07DBD6941ULL;
    std::uint64_t aWandererG = 0xBFE9FCAB9DC59D41ULL;
    std::uint64_t aWandererH = 0x83FB4690E6700367ULL;
    std::uint64_t aWandererI = 0xF345C307E39C8959ULL;
    std::uint64_t aWandererJ = 0xE146F2C86A3652E2ULL;
    std::uint64_t aWandererK = 0xC4CDB19EF9459BE8ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    TwistExpander_Aldebaran_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KEY(pWorkSpace,
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

void TwistExpander_Aldebaran::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE888E014A15F2BE1ULL; std::uint64_t aIngress = 0xF2D51F8CC6E492F7ULL; std::uint64_t aCarry = 0x840344F9B5AB07A8ULL;

    std::uint64_t aWandererA = 0xAC8D5B55114A2EDAULL; std::uint64_t aWandererB = 0xDBA6887D1005997CULL; std::uint64_t aWandererC = 0xF053F21E78C2ADF5ULL; std::uint64_t aWandererD = 0xF8E5AEBD22E7850AULL;
    std::uint64_t aWandererE = 0x99E0E9BA9BF63AF7ULL; std::uint64_t aWandererF = 0xDE4D75B0E5C54BD7ULL; std::uint64_t aWandererG = 0xCF74993B4E260BACULL; std::uint64_t aWandererH = 0xF86A5D1448005F26ULL;
    std::uint64_t aWandererI = 0x8F0098440097C98CULL; std::uint64_t aWandererJ = 0xE43BBCA2199043B5ULL; std::uint64_t aWandererK = 0xC522C3CDF181B4DEULL;

    // [twist]
        aPrevious = 0x952433A0969EB88DULL;
        aCarry = 0xFFB15438B5636D97ULL;
        aWandererA = 0xC0A28F6B5E0D4F61ULL;
        aWandererB = 0x9BC1F2342060EE45ULL;
        aWandererC = 0xF6375E6EBED7950BULL;
        aWandererD = 0xA94D4538657019B2ULL;
        aWandererE = 0xE0F404D3102AB552ULL;
        aWandererF = 0xF3841B61FDEFB9ABULL;
        aWandererG = 0xB39F3CF5BB77C811ULL;
        aWandererH = 0xC79A2D8DE3D1C202ULL;
        aWandererI = 0x945A11F927D0FC03ULL;
        aWandererJ = 0xBA7584206AF6279AULL;
        aWandererK = 0xE4B6C6DB2BC03151ULL;
    TwistExpander_Aldebaran_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Aldebaran::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Aldebaran::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Aldebaran::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 3 of 33
    // Exploration cases: 0
    // Structural maximin 598 / 674; family total 1204
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1825U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 3 of 33
    // Exploration cases: 0
    // Structural maximin 590 / 674; family total 1180
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1015U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 3 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1140 / 1248; total 2281
void TwistExpander_Aldebaran::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
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
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
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
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 3 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1147 / 1248; total 2296
void TwistExpander_Aldebaran::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
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
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1939U) & W_KEY1);
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
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeyRotateSalts = {
    {
        {
            0x189ADDA3E650E22CULL, 0x0C6202CBE2FA9123ULL, 0xB923342D0CD21F5BULL, 0x24F951317C8CAA5AULL, 
            0x1FDCD9CCE457A458ULL, 0xFF979EAAF8726CACULL, 0x940578369E931BCFULL, 0x19DA03525DB294C7ULL, 
            0xC5E91E9491F8D8ADULL, 0xF2F7DAAC40D3AC41ULL, 0x1CD9337336EB7F3AULL, 0x04A26A7EB4B97EE4ULL, 
            0xCD56E2948DA7F23CULL, 0x5845ED761498BF8AULL, 0xED4D34CDB9486AF1ULL, 0x079BFD166629F40DULL, 
            0x1308210FDC7C1DF8ULL, 0x493C8FA96AC31C8BULL, 0xFDC17BD64B4CBAA9ULL, 0xBEB38E240FEAF8B8ULL, 
            0x26C8FE05E79DB3C5ULL, 0x7B3853E74206A65CULL, 0x820E1399ED79B80FULL, 0x7CE24ABE1AE60C34ULL, 
            0xE3B914D194DF38A8ULL, 0x5B0DB2AE7608B7CCULL, 0x1B5C63ACD7F0964AULL, 0x5B8AB1FDE06669A9ULL, 
            0xA9D5CB8125E386BAULL, 0x882D4C6D5145DE84ULL, 0x2C1ECAF0E42A3F04ULL, 0xB1DDD6A4D7EEDD54ULL
        },
        {
            0x80E7195504790ED5ULL, 0x9F6ECC89382991C3ULL, 0xD08B76E0CEFCB942ULL, 0x109A622452439172ULL, 
            0x18D0F08498394F5BULL, 0xA43DB89260A5F0FAULL, 0x4E9D94664AFCD966ULL, 0x2639895E607021C1ULL, 
            0xEC0A1440D630AB7CULL, 0x1806A932376978E8ULL, 0xB4A3456A552809A0ULL, 0xE76C7A025E1F7087ULL, 
            0x9ACB7931F5F3D2C7ULL, 0x53A00CF4C07D4710ULL, 0x5712FF695431965AULL, 0xCBC50333E4D3B073ULL, 
            0xF5786A8141DCA892ULL, 0xD3FE7C30AFD27445ULL, 0x29D53F3A62FF6D64ULL, 0xED783EC54F87F308ULL, 
            0x26D135D16B0C3CADULL, 0x9E2990427A0290B1ULL, 0x7AFA76D7D6E5C45BULL, 0xBDB186C20598F2CDULL, 
            0x7C3B64D4767DD31CULL, 0x6462CA38EE456F6CULL, 0xA90AE02122A93F2CULL, 0x84D28979D9E99BCCULL, 
            0x9E33BDECB20F5911ULL, 0x6FE66B40D2744983ULL, 0x21EA46EE83C05A77ULL, 0x4E954282EFE33382ULL
        },
        {
            0xD83A8B955FEE9BB6ULL, 0xA6F3BE9BBC3B9FF8ULL, 0x5A5AF9347737D805ULL, 0x2E437D7B2233829DULL, 
            0x88F6B5E6E1513940ULL, 0x9AF125394E8FA431ULL, 0xF4239CC57B353408ULL, 0x028D9D8207196762ULL, 
            0xEC603954EDF9B892ULL, 0x9DBAE9E8C5F1AAC2ULL, 0xE3415A55CFAA73BEULL, 0x0AC5881F0D7506CFULL, 
            0x0BBCDC63DBBAEF60ULL, 0x3B5F5DD2AE097AF3ULL, 0xCF51040818E4C982ULL, 0xDCF067718500AB16ULL, 
            0xC83254CDF90C26FEULL, 0xB56EFB68C12E861BULL, 0xADCC95DED32742A8ULL, 0xE645B564EB09BC4CULL, 
            0x09EF79F7F598C379ULL, 0x17CEFB16FFABB521ULL, 0x2266A5A7E4DFCA9DULL, 0x5CA351707BD7B157ULL, 
            0x4E62F5AF6AB98E48ULL, 0xE1532A23AA0B7DA9ULL, 0xE65DE23977916DEFULL, 0x7290BA625B0C106EULL, 
            0x3F0AE95EDC0ADC78ULL, 0x7E264D22F808A313ULL, 0x2459EC5FEA0342E7ULL, 0xEB1420BBEED85A4FULL
        },
        {
            0x739102C63472E8BEULL, 0x1B71236244118B17ULL, 0xA4C74257B4B930C5ULL, 0xB81085ED675C3C73ULL, 
            0x13F743D12E771E04ULL, 0x5C349A8F9B308F20ULL, 0xF8E561B494C15FA2ULL, 0xD184E2350D7655D8ULL, 
            0x247EF6918BE98792ULL, 0x2AD3660314EAEE9BULL, 0x51CA6A0CD58FAC0DULL, 0xBAB04B3D343859FDULL, 
            0x2B61D58F013F9C08ULL, 0xE944D8DE6ED8723CULL, 0xD6F9739F2E70FBA5ULL, 0x2581C07CDEE3B9A2ULL, 
            0xB66529AAE339DDA7ULL, 0x70F5E61F503C9ADFULL, 0x66E44478D5922057ULL, 0xBCCAD0FFCB6A500AULL, 
            0x058E274CB1C68BD8ULL, 0xA38C1903480D4E7FULL, 0xAD0F9307159BFC25ULL, 0x1F64A6515FAAD7CBULL, 
            0x97E48252FE536D3DULL, 0x843C0AA6338E7556ULL, 0xB155E867C972788CULL, 0x4CAD18ED558FD25AULL, 
            0x71118945270333F5ULL, 0x324FFCC52A8C8846ULL, 0xABEDFF6810C39AF2ULL, 0x05BAE45954D7BB14ULL
        },
        {
            0x8FAAD7462343C806ULL, 0x27B176248B8E5C7DULL, 0x4CAB68A45AF932E4ULL, 0xAD3B3581AAA60530ULL, 
            0x7B42301229A812C6ULL, 0x1A7996FE084F53EDULL, 0x370FC753B6F100F0ULL, 0x793ED9CD814A58DBULL, 
            0x91C5D75F377B21A0ULL, 0x5160FF28D590A72EULL, 0x8F02F26DF864146BULL, 0x95BA184EE63E0D3EULL, 
            0x1104559695F73DABULL, 0x8A9968AC32351EDEULL, 0x31DDBCE8F009A8E3ULL, 0x3B434115D9DA50A6ULL, 
            0x1D25DC5288E1E7F3ULL, 0x56BB5C1C9E0AFD90ULL, 0x10C10C9DE1B04DAAULL, 0xE8B6E365F8477F8AULL, 
            0x29965BBA82A47E8FULL, 0x4096C78168050097ULL, 0xB374A9D487963DC5ULL, 0x496F2A696CA25BECULL, 
            0x9E3C553BAA0769E0ULL, 0xA78FB5D4E0E92F27ULL, 0xD1D8A4A6768504F7ULL, 0xD0FAC7AD278EA441ULL, 
            0x558FBA2E369DF8B4ULL, 0x3759D7D58DFA4A57ULL, 0x5DEFDADA5D59CB81ULL, 0xF0596E3E8D0DB4C3ULL
        },
        {
            0xBA59C59EF7CC7375ULL, 0x271431D6FD806493ULL, 0xEA22626D8D8A9236ULL, 0x9250E09A6654ADA5ULL, 
            0x608E628039DEDDFDULL, 0x47E5D026CD3BB6A7ULL, 0x3B08D2C79C6ABAF2ULL, 0xD42149EF2E00F250ULL, 
            0xDA8B92B190CFADA6ULL, 0xF69AC9742317BC82ULL, 0x0AACA76BB5C19504ULL, 0xA5A2CB886C70992CULL, 
            0x9F08847787E23EA2ULL, 0x3DAF5DC8C917503EULL, 0x4C5EEE13DF81007EULL, 0xCF80212FFC51F6C9ULL, 
            0xAB17C8BCC2DE64F8ULL, 0xCC48BCD484F2C757ULL, 0xB375D203ABBF2825ULL, 0xC6AA094922CBD9BBULL, 
            0xA7771043EB9FDEE9ULL, 0xD957FED6A81ECC88ULL, 0x5D75B657FE438229ULL, 0xCFE5F5627693E6F7ULL, 
            0x1A09A0E78391A71AULL, 0x5DB4DD4B45037F3BULL, 0x0DBC6ED888770C4EULL, 0x0889802947F637FBULL, 
            0x1E6C88202CB131BFULL, 0xCA95D5DE59631F40ULL, 0x58ADDB1FF2E185E1ULL, 0xC1979D5102895597ULL
        }
    },
    {
        {
            0xBB61F14B21521A08ULL, 0xF5AC373603DC3918ULL, 0xED9D924FF8173238ULL, 0x86A48C4C616CC0F3ULL, 
            0x0ED2D487F2B92692ULL, 0x8D61F74FA7E19640ULL, 0x763D667B72FE8A7EULL, 0xC8EE50C975894DABULL, 
            0x38860B98ADD9A885ULL, 0xBC7F0E46F66E527FULL, 0xC28B867F5D055FA2ULL, 0x0223D17DC9656818ULL, 
            0x79DCCDFC34619594ULL, 0x97B79AB675E5DC31ULL, 0xB7B793C7B13C1656ULL, 0xA0019B9A5504DEFFULL, 
            0xB9D2BAA58464F3E5ULL, 0x95572CE5251C6F80ULL, 0x35AF6000C144B165ULL, 0xB65755D97E083639ULL, 
            0xA4EFF2464461E0B6ULL, 0x7E1E0AFB8FFA97D5ULL, 0xA98C617E6B8CC58BULL, 0x361D576C85C701C9ULL, 
            0xBA71C68047FDDA69ULL, 0x60599253D4524F01ULL, 0x46837320CF7EF213ULL, 0x15C497EFF2B7E93AULL, 
            0x3429B1B893EE13B9ULL, 0xFE34CFC48ADA1987ULL, 0x14132CE0A3F8E6C0ULL, 0x346AF2C6FF70F999ULL
        },
        {
            0x794248B4DFF028D4ULL, 0xD4FDD2B8C4B43A30ULL, 0x46000BBEEDE6DD10ULL, 0x6382470AAA9C7E1DULL, 
            0x824E3FFB0EDA6529ULL, 0xAB6D5FD4ECE8654BULL, 0x42FA8E737D560615ULL, 0x378E611FA25A6D4CULL, 
            0x2976E53278F1F263ULL, 0x3CFC02127C3D15F8ULL, 0x575D396560CF9C7BULL, 0xB06D3A12FFC1DB3EULL, 
            0x273996E29B44BF62ULL, 0xC543B3687AD9023AULL, 0x308E268CF2EB2B4FULL, 0xD026BBB19D3E6B13ULL, 
            0x16122CE3445D5766ULL, 0x082805FF853065C7ULL, 0x11067F4376E273ABULL, 0x084706927AF23430ULL, 
            0xF5EECB255AF4C4D4ULL, 0x3C310929D6147881ULL, 0xFAD97852BE0359CBULL, 0x6F7668261A658F81ULL, 
            0x57818E7E021B44F6ULL, 0x35E25DEA8AE039C4ULL, 0x43AA6CCC2E86BF7DULL, 0xFFB71CEDD5174394ULL, 
            0x87F0A2285043984CULL, 0x7241F41889277A3EULL, 0x3DDE11BF9505045EULL, 0x73AEB15F77A53292ULL
        },
        {
            0x1924867AAA7287A0ULL, 0xC3D7026D6EEBD131ULL, 0xFC3D6BD2745790CEULL, 0x16D8068AB5337A55ULL, 
            0x24EC66B53797929EULL, 0x7CC799AF8FEC5E9EULL, 0x5AFA940390F4213AULL, 0xF99A7ED30C1B6C1BULL, 
            0x2EC05E68D55587AFULL, 0x0A9768A67D5C6C31ULL, 0xBC9A9A8CB0709591ULL, 0xCFF104762F8DB88CULL, 
            0x672C2F707D6A46ADULL, 0x34690DEA0FBCC109ULL, 0x2EFB0C7BAFFCC02DULL, 0x70D8BA4D1B5E0AC3ULL, 
            0x60D46497137EB755ULL, 0x1DFEDD7DA08C28E1ULL, 0x4CE2F400D5CA62DFULL, 0xAB338C43457C725EULL, 
            0xEC7C793245462717ULL, 0x70DEC7B85FD5363EULL, 0x31AAA6A7F12C88E2ULL, 0x0EEABCCB35585792ULL, 
            0xD57F32A72CB29AD7ULL, 0x5F760A0803101D90ULL, 0x424DAFA257F0AF78ULL, 0x675874117F258442ULL, 
            0x86F5DDEECA4F3A9EULL, 0x4C04AAF28FC5FF21ULL, 0x5DBD21D9DDF8ABB6ULL, 0x4BEFC87D6C807208ULL
        },
        {
            0xC794D71841DA8419ULL, 0x6F0F1D45DB44CECCULL, 0x8ED93E73A00C8057ULL, 0xAFE762B24EDCB484ULL, 
            0x0C9A8B2C5C638930ULL, 0xA827BC709A25127FULL, 0xC9D98343A01D587BULL, 0x3A0595E34D2E2793ULL, 
            0x40220C1376E8EE60ULL, 0x7E6D650AAF0AD39CULL, 0x71C562E466FB5794ULL, 0xB48BD8A9CC1213AAULL, 
            0x2983A54BD52111B2ULL, 0xB1B388EC697AEC94ULL, 0xED657C81EDE17118ULL, 0x9D43D434B5F46176ULL, 
            0x26A3B708F0714953ULL, 0xB79A2E8B7019F22FULL, 0x6B8244672A94E38BULL, 0xBD4EB0E658B617E8ULL, 
            0x76E64158EACE5A94ULL, 0x38B197508D3C3210ULL, 0xA45D9A7F27B299F4ULL, 0x76F6F10ED06BA803ULL, 
            0x3289285B4F23B5EAULL, 0xE2613CF28AC9DEB1ULL, 0x510AFAA48865539DULL, 0x9FADE6AE717D9154ULL, 
            0x3D9622E970019F42ULL, 0x69B17F0318A1C666ULL, 0xBEFCD30FA6292BB7ULL, 0x9C50B6EA3569D59FULL
        },
        {
            0x2256A92896845167ULL, 0xBFB4146F64FCBF0CULL, 0x43E452578C45456FULL, 0x4FC6C66F3EEA694CULL, 
            0x7B70AFED8D9727EAULL, 0x5404BEF40FD1F180ULL, 0x5978EA8440F69CBBULL, 0xED67B74D4EE4C391ULL, 
            0xDC56E843FEDB291AULL, 0x0996635EC66684F1ULL, 0xEDB05372E3E416BEULL, 0x209296063D894A7FULL, 
            0x337B840B61AD1C4CULL, 0xBAA6B149B9786106ULL, 0xC3B80CE4318EA3CBULL, 0xA8C9666779CE5D1CULL, 
            0xC481FFD1D306E51EULL, 0xA29D5B945F5F4878ULL, 0xFA608EE2E4FE0E1AULL, 0x3B86964D905657EBULL, 
            0x0C3931F18CBFD871ULL, 0x44BA5D2C4E023B1FULL, 0xA8206F2A41F71FDBULL, 0x2FCA3EF568C8986EULL, 
            0x2EEA5623715CBB2BULL, 0xAE93B8B9960517D4ULL, 0xDCCBA878F1A0D143ULL, 0x9D13DCF5356473AEULL, 
            0xC6B2C65001BECACBULL, 0xA45FC51A993D9677ULL, 0x480CB87A5B7CD6B4ULL, 0xA29884F5EE25346FULL
        },
        {
            0x845DA83FE767CAC8ULL, 0xA34FAC6F6DD20CD3ULL, 0xE1A35CFE64D6040AULL, 0x86CCAEAFFB1CCE00ULL, 
            0xC688F5494B585296ULL, 0x306E7C08115CE2EEULL, 0xB83A6EFAFD1E3EEEULL, 0xEC628F993F51DDAFULL, 
            0x493725CA9FD3821AULL, 0xD551D3B9B1AC903BULL, 0x93EC9738C2870B32ULL, 0x17A58F2952211E02ULL, 
            0x0B338253231C0372ULL, 0x5078881B40961DC0ULL, 0x1624A952A987CC34ULL, 0x8A530C8BCF2CA7F4ULL, 
            0x735F9FA99444DA4CULL, 0xA655DF6E13F32AEFULL, 0x8359BA5E0A5E230EULL, 0x58764AE011A2A5A3ULL, 
            0xF4E6CD0EA68E775FULL, 0xDC578BEF4DA7CBF6ULL, 0x444997F618A2E3E2ULL, 0x33DF9FAF85C13B7EULL, 
            0x6B89A9B4A2A0D15EULL, 0xF07B8EEEAC36FA65ULL, 0xC6F9F2F7CC108543ULL, 0x37F56EA4E0E71AAFULL, 
            0xC1C5DA8F8964FE30ULL, 0x8724932EE3D8633BULL, 0x9E1494E94922E074ULL, 0xE0BC5D24E009565EULL
        }
    },
    {
        {
            0xD865B288BC672D2CULL, 0x318E796661196738ULL, 0x5248E973C436F21FULL, 0x7BCD78C09EB7D42BULL, 
            0xF2070C5DEB14C3B5ULL, 0x59912978914EF488ULL, 0x066713E71F284D41ULL, 0xE6FA2228F6B30DC5ULL, 
            0xA9B02670AE614C4DULL, 0xC98FCA07734B3C4CULL, 0xDB1C8A962946968FULL, 0x6F36BA6C9AEF066CULL, 
            0xA9ED31944DCF2B05ULL, 0xF4A2EA2007350770ULL, 0x086E895315454FCCULL, 0xE9CA245563830272ULL, 
            0xDF59453DE0DE855FULL, 0x7E4D11C7EFA763AFULL, 0x11F2DF6B25EFE645ULL, 0x35D65E956C0E320BULL, 
            0x11C85B7B028BD0F6ULL, 0x9A8473D5D05C34F9ULL, 0xCB703B3509BD902AULL, 0xE6247A74DBAF0A9AULL, 
            0x763076E35170F85BULL, 0xFF7F0720714C396DULL, 0xC7654B245E8B0596ULL, 0x4F2CC3F4F874A8C2ULL, 
            0xFADF1B20D1058976ULL, 0xE1F4A361CDBA34CEULL, 0xC79CF21C2E5F23BDULL, 0xB3D12DE0B2FA515DULL
        },
        {
            0x548F1E8EA4DB86FAULL, 0x521BA900EA059934ULL, 0xE026C769208B210DULL, 0xCF9B498DE98D56FCULL, 
            0x03511C5C3A593119ULL, 0xEAB2B6F8B33ABC5EULL, 0x49730EE90CBB2C93ULL, 0x58BBC6C0B31AAE5CULL, 
            0xDC57C28D2B88DD5EULL, 0x3CFA3500CD694BBDULL, 0xF906E3C34767F78EULL, 0xBFA73B9BCFE927DAULL, 
            0x9C04E1025B3C0EF6ULL, 0x416E350AD06CCB43ULL, 0x5675D06B11699EDFULL, 0x0E396730FB2BBC29ULL, 
            0x0150864674C3F2F5ULL, 0xCB7E5EB0AE14B5C8ULL, 0xB0752C0472147CE2ULL, 0xBF71597448F1557EULL, 
            0x743415FCC83CB80FULL, 0x00C633D921ADB866ULL, 0xA7EA50E73482BA15ULL, 0x558EF8CB805ED4FFULL, 
            0xF01BA29E7BE93EF0ULL, 0xB066A4342D7096B7ULL, 0x0B48BBFF8F0E10A1ULL, 0x13773A20E7858115ULL, 
            0x7DA91E7905A79F14ULL, 0x99329D8F35E4468BULL, 0xFC00489AFEB30A96ULL, 0x8CEA77319863CE5EULL
        },
        {
            0x5F6F50554C1CEE50ULL, 0x806076A7738B9C53ULL, 0x6259245C15687A3CULL, 0xA8F929CA6D54952EULL, 
            0x18F026250BF7E305ULL, 0x5C6101A84502F83EULL, 0x255535FBCF57F5CBULL, 0x4E3EC85FB085F07DULL, 
            0x9FC299A9AE900545ULL, 0x061DD9EDDEF1E1DBULL, 0x0AD94853249EEACAULL, 0xD13BCA2300286728ULL, 
            0x597E9F2CFEDDB657ULL, 0xAB12FB3331A79908ULL, 0xB9D4BA0ED8C5DC56ULL, 0x2F0250DD6CB6133CULL, 
            0x1BEBBCE91B42E091ULL, 0xD1B96B2DFA4AFE7FULL, 0xDE496DCA9375CBD9ULL, 0xCB8E43DC0BFBFFD1ULL, 
            0xE8FCDDB845EF5AACULL, 0x125FF33D96E46208ULL, 0x48220A0471D2A3DCULL, 0x85CAEFE0DAA9DB16ULL, 
            0x2C576013A146ADD7ULL, 0x99A922E00D94CD59ULL, 0xE7E104819FC19E27ULL, 0x20E0A9EC510F3BC6ULL, 
            0x273E8C1B11015AB0ULL, 0x19D29D73404D38B5ULL, 0xD697639439E236B3ULL, 0x25A358F355451C40ULL
        },
        {
            0xDB98245D40343D5BULL, 0x78A578788B12DAB5ULL, 0x381B1B13E27E9EF7ULL, 0xDD3B64965DF2C0A9ULL, 
            0x2E6C167C9A40CC75ULL, 0x5C11FAF7E23C03DEULL, 0xEBE3E9F0883A0CB9ULL, 0x2BC77F9869415567ULL, 
            0xF60C2D236F70D21FULL, 0xE0BA53FF850CD7B6ULL, 0x9F38E1A737DDC004ULL, 0x3D2A64D761F9D6FAULL, 
            0x89D220C4471DCFC0ULL, 0x8FC177430377BEBDULL, 0x791C082F5A0421F9ULL, 0x7CBF545A2CB0FA21ULL, 
            0x3D994DEB5581712AULL, 0x09F4558D861ACB70ULL, 0xA1D90AFC4C5E484FULL, 0x3ACBA75E73CAD430ULL, 
            0x8C5762D80FD2969BULL, 0x792C4AEE3047CB43ULL, 0xBF972F2826F748BEULL, 0xBB0B2807A01E574EULL, 
            0x9C91AE2DFA82D384ULL, 0xC559B9A589141782ULL, 0x5042C6ED7B5867B9ULL, 0xDA4558E60B32C506ULL, 
            0xB7A60AA084F34730ULL, 0x30700DC86E13A5FEULL, 0xE31368A869131BB6ULL, 0x0560F4F797D4B7DBULL
        },
        {
            0x91A99762B963D86EULL, 0x9DA622DD86BADF82ULL, 0x251F25CDA63007A0ULL, 0x9F63FCFFA270A81FULL, 
            0x07AB22B506B40020ULL, 0xAC6A0A9A90465D00ULL, 0x2448C8A0F1DAEC5AULL, 0x9B805A67418B886EULL, 
            0x62221168A5DC3306ULL, 0xC28B158BA037210BULL, 0xDC789F8F8C260FB8ULL, 0x4A101B58FA244E16ULL, 
            0xB48B80F4615A8D99ULL, 0x9DACADF4EC349B19ULL, 0x7F94675A20A930FCULL, 0xE6F99C62D03F6B96ULL, 
            0xA06D7E182C89FDE0ULL, 0x00CFCD4EBA49975AULL, 0x13F020434957EFDFULL, 0x2E213F8ABB6AE2E7ULL, 
            0xED525CD6F54551A5ULL, 0xD19316A5AFAB5B45ULL, 0xC726040643EBE02EULL, 0xA02C8CB1E7DD7E3DULL, 
            0x5DF1B43B7F1FE585ULL, 0x141991F4A3C63C2DULL, 0x78C15918670732FBULL, 0xE0899E5C16769BB2ULL, 
            0x73D6837A523981BAULL, 0x9842EF99B7CA3466ULL, 0xB0BCE3D4CF8583DBULL, 0xF42AF0803F52DA99ULL
        },
        {
            0xA8260F87CCBD6157ULL, 0x22327BC4B074752EULL, 0x69EE4FA4AC61838CULL, 0x675B9E5101BD0F82ULL, 
            0xD8A3B6C35C73E4D7ULL, 0xC55F2B78C724B31AULL, 0xC5747065A8BADB84ULL, 0x7C646DE046AEA406ULL, 
            0x5DC996D14EFE8E4CULL, 0xE66E2411171B52CDULL, 0x08CEBBF26D570F6AULL, 0x582BE7144CCAF22EULL, 
            0x22A54E3CF74D5083ULL, 0xCCBF373D1142D844ULL, 0x906DA6E0EA183711ULL, 0x2471CADB72EDF135ULL, 
            0x8EB9AF1D50410DF4ULL, 0xA3088E0931E12EE0ULL, 0x4E1EA0854F8104D3ULL, 0xAA31B50F79272B2DULL, 
            0xCBFB4CA9CE714D5EULL, 0x432C5D4620A219F9ULL, 0x4F7840DCF45810EBULL, 0x54DFD78E208E4460ULL, 
            0xFCFB49381667C271ULL, 0xD9EAC17AA6D64F13ULL, 0x2B17919030D6524EULL, 0x8A1D17F7157631C5ULL, 
            0x5A05822DAA45A739ULL, 0x1218062839C1089BULL, 0x3563E5BB4FFE8E74ULL, 0x151A6603FE8DA248ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeyRotateConstants = {
    0x8AB7BA7EF8EB02D8ULL,
    0xC81D498C45469C3AULL,
    0x2D8049E98009CEE9ULL,
    0x8AB7BA7EF8EB02D8ULL,
    0xC81D498C45469C3AULL,
    0x2D8049E98009CEE9ULL,
    0x2EBC1E1106EDBCDCULL,
    0x278E2FFE1E30DB58ULL,
    0x87,
    0xC5,
    0x13,
    0xA6,
    0x71,
    0x7F,
    0x82,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeySpawnSalts = {
    {
        {
            0xB43F82F763A4A1C9ULL, 0x170755E18CEEC726ULL, 0x2707200DBC746AACULL, 0x3D19357BD53905C3ULL, 
            0x8AFCC2FF9CFEC307ULL, 0x3B133C3199518C67ULL, 0x67BDA2FFF4BAE0C8ULL, 0x57188F7B985D264FULL, 
            0x78A5345860DB60F4ULL, 0x4E1A6B0EA3C6B570ULL, 0x94FF1FE7E4700251ULL, 0xA4F25B47213C4ECFULL, 
            0x4B7E6FA44E461B6DULL, 0x453D9B513194C3BDULL, 0xA1F908705B41BF91ULL, 0x7362C1858ABE5623ULL, 
            0xDF28013D2C71C8F6ULL, 0xB4A9E6FF8C9711B4ULL, 0x56C6039BF241F61AULL, 0x3D70DDB778F2DD0BULL, 
            0x663661B346CA9103ULL, 0x97B09B4C3E33E7A3ULL, 0x108690AF19BD1D1CULL, 0x1A8715D637928576ULL, 
            0x16AED019A14651D9ULL, 0x501C25C91F387B2FULL, 0x24D09CEFEF3BCD20ULL, 0x9C041FAB5BB0F3D3ULL, 
            0x2DCFB0A1378C677EULL, 0x634C416F75589A63ULL, 0x28AB37BF220B5002ULL, 0x03094F5416800281ULL
        },
        {
            0xA9DA1F1DE5244776ULL, 0x895D5C2B65D3B0A5ULL, 0x6FE91B5398E696F4ULL, 0xFBEAFD475F2F80ACULL, 
            0xB776E83C33B4B7C1ULL, 0x845967A111E04618ULL, 0x60B2CEC666A831E4ULL, 0x48E458921480D1D5ULL, 
            0x21DB2775F861452BULL, 0x782F1F4DA9AFD36FULL, 0x9E3013179038561EULL, 0xF5BAEA3A1506A298ULL, 
            0x867CAA048847ADBEULL, 0x4B0A313CE8721846ULL, 0x05D21BCEBE68E9ADULL, 0xF49FE11754E33A69ULL, 
            0x1958CB60E0859F0CULL, 0x3C1E573AA4831287ULL, 0x725B006D1930F690ULL, 0x6FC3B61C98D81747ULL, 
            0xD94B7BEB1003A3CFULL, 0x16CCC2B722C6665FULL, 0x47C1ABD93245004EULL, 0xC57D101AFA2C69C0ULL, 
            0xEDC1E5B80CA51ED3ULL, 0xACF8666896FAE2B5ULL, 0x1BE3EA076FEDF5FFULL, 0x849A0901FF4F3731ULL, 
            0x69D393F55C720CF0ULL, 0x6EEF151DFD627A61ULL, 0xAF5C9AAAB44AC18EULL, 0x5D537E3708725A5DULL
        },
        {
            0xD3441DA865D81240ULL, 0x333A97D51E90D881ULL, 0x2950D4D90CDB3F45ULL, 0x0D65E0AC5368ED52ULL, 
            0xBAED347F393F55A3ULL, 0xA9C22288758327D1ULL, 0x7C5BF712C2529599ULL, 0x10A74AFB76056F1CULL, 
            0xD538528AB6F1E242ULL, 0xEDFC5C0BDFA3D3C4ULL, 0x341A338CA35963EDULL, 0x7C966F098A53BF08ULL, 
            0xFD0E6179A0F3C495ULL, 0xE435723319212CCBULL, 0xEE72EA6F865848B4ULL, 0xAD1CFFE31442BECAULL, 
            0xDB2CE37AF351163DULL, 0x1E662E65211DA319ULL, 0x1211D42DAC690CF0ULL, 0x902804B17B26517DULL, 
            0x96E5C13FE6D4EBEFULL, 0x1A8F308AB97E69E8ULL, 0x2B64A874EA5BF7BAULL, 0xE1981B2A940E1F6FULL, 
            0xD2D6F91E94D9BB53ULL, 0xF0058F4F51CFAA5BULL, 0x5BB73CEBFB2CA735ULL, 0x1857C20B75C91201ULL, 
            0xEF949099DEDDE8B8ULL, 0xC9BD7580032206E9ULL, 0xBA6A3757E6DAA5A9ULL, 0xDE641E11CDB91FCCULL
        },
        {
            0xE890471C275E0A9EULL, 0x085897B8AF6FF737ULL, 0x409F1E5A63BC5DFCULL, 0x9DC5B175B8722657ULL, 
            0x8E5EFD21BB690E03ULL, 0x5E2CF64157548BC2ULL, 0xBAFC3EC34A09AF8EULL, 0x257C691D1E05906DULL, 
            0x06C7BBA679B1380DULL, 0xDCF6C14E1F66FFA8ULL, 0xEBF71B26208F94A5ULL, 0x345CEEAC213AFE2CULL, 
            0x430DE39864DE70F4ULL, 0x710E82B7884221D3ULL, 0x50BCAB3861A4ECC4ULL, 0xB2FD523016013424ULL, 
            0xE27F5370D2133828ULL, 0x64B4291A7CAD2583ULL, 0xBB40D2F0F7260C87ULL, 0x4AB05D6CDE0D7A8AULL, 
            0xD02F7F05593EAD45ULL, 0x4EA926A771EB2E02ULL, 0xEEAF8312ECE91B84ULL, 0xF10D529E9808E253ULL, 
            0x9530292D339878D2ULL, 0x2F1AA19CDDD3CA3FULL, 0x726803B5E6A908E3ULL, 0x5EB2B6B5841C8F90ULL, 
            0xF5DEF6DC0AFCA79AULL, 0x7B767652DE08AC62ULL, 0xD44897933E6C1892ULL, 0xF18F5D0102F08DB5ULL
        },
        {
            0x672F5F9DCA3D21AAULL, 0x54BDBB5421D4A0BBULL, 0x4E8C4566A3BE5097ULL, 0xE4A986123CECD323ULL, 
            0x748E3C44F2BDC613ULL, 0x376152358F31468EULL, 0xB609AC952C2E68CBULL, 0xA564A703FC01C7A7ULL, 
            0x91D9D5081F44D01FULL, 0x2B7F6E5E4736277AULL, 0x7E723C9CF553D502ULL, 0xBDB9734C047B4C69ULL, 
            0xC3B2D6290FF279DBULL, 0x6F8CCBB5654F2614ULL, 0xE5481CE57F81C4C3ULL, 0x2B2039D182D831CFULL, 
            0x50626786631E96B6ULL, 0xB01D690A8283EDBDULL, 0x09E2DA8A7B164193ULL, 0xCB2CEFD5BBFE0A59ULL, 
            0xE17252E5E2B203E8ULL, 0xFFB2DA736924C638ULL, 0x3395AD0414ACFB51ULL, 0x9F0318B932FAFE19ULL, 
            0x48F5C2802BD027C2ULL, 0xC890816559A4FC9DULL, 0x0FB3FFFA1DD9F543ULL, 0x0FC79E7B397CF017ULL, 
            0x2D1DBC75A3ACA38AULL, 0x79A7EC69DC4B39C0ULL, 0xDCF2B93224BC5C1BULL, 0x2843F2466E714E09ULL
        },
        {
            0xE7B1A374CFF02E31ULL, 0x5223589D037D08A9ULL, 0xB3113FAD971D2543ULL, 0xD7FE59CA93FB648EULL, 
            0x698CC172A55D01FDULL, 0x9F3FFC391B52D13AULL, 0xD016AFFAA0B0EE0CULL, 0xF7AA06A520519597ULL, 
            0xBC8188EB9B5D0EE9ULL, 0x9D8D74CEB63575F5ULL, 0x761B3C84E3F24CC0ULL, 0x4381AF3463583329ULL, 
            0x7A7B3B2FA268096AULL, 0x1C74BA38F26D6799ULL, 0x899A920DDC8747F3ULL, 0x1E44D1744DC6F335ULL, 
            0x227C4A0862A7EAF2ULL, 0xA07159C43947A1B1ULL, 0x5112CEE6A900E7B3ULL, 0xB365A51742762025ULL, 
            0x352EC0A00286FE1AULL, 0xFEEE71AC2E03A996ULL, 0x03ED254F99DCA748ULL, 0xBA1AB12098AA6483ULL, 
            0x16FC7698CAC9C4B9ULL, 0x34B380D292DF0120ULL, 0xA0C87E73C137FFEBULL, 0x1BA6DD453CB3CEFDULL, 
            0xB8E1C6541D2EFBA3ULL, 0x591E255220C496A2ULL, 0x34CBE7113AD2CA4DULL, 0x6548A7646ADE834DULL
        }
    },
    {
        {
            0x152A6D31034C4464ULL, 0x592D0F785E49B6BFULL, 0x0E7D577D2D34CCBCULL, 0x233647F5B5C9D42DULL, 
            0x77AC9B57343099A2ULL, 0x73E6F0B0CB7A61AFULL, 0x185AEEFD4BAC6C58ULL, 0xC82942D98CCE97A7ULL, 
            0xEFE984F782900357ULL, 0xA618CD298429EA13ULL, 0x33F76C5340FE3F9BULL, 0x22C6E662FB2B938BULL, 
            0x2865185A4B68BDF3ULL, 0x5EC2707EA7E6C76EULL, 0x802577763A6DB4D8ULL, 0xB0204C321C69BE74ULL, 
            0x7DBEEA86546F543BULL, 0x8FA726F38CB03A5CULL, 0xDAC1E0756D723D7DULL, 0xECF68D3E689FBC7CULL, 
            0xDD16E31F1D3D98E8ULL, 0x16F1AA2F4EA658E2ULL, 0x8C63A4CC14A326E0ULL, 0x905DA94F22A56A7BULL, 
            0x774D73DE32FB82B9ULL, 0x6F66C74F400C068FULL, 0xF8BB3CEA6F4C9F89ULL, 0x7448585C205867E2ULL, 
            0x5E8054328B0B94DCULL, 0xF3D3689B527FE4D5ULL, 0x0362ED3161F4806CULL, 0x476018A135C037E0ULL
        },
        {
            0x089A90476BF53C3CULL, 0x93C29035BF2AF3EDULL, 0x96ED2BA8DDC71800ULL, 0x5E31E37BBA53429DULL, 
            0x4DC246A9A7570F5EULL, 0xD518BA81A39A6990ULL, 0x635D9328A8B22461ULL, 0x91DA92C74887DC4DULL, 
            0xDE5810004FEA7DF0ULL, 0x65F410E2C10BDA67ULL, 0x48376D69CDEA8DDDULL, 0x31B7CFDA00D42E0CULL, 
            0xAA1BAF8183EFADA6ULL, 0x0AE83BED557ED6A2ULL, 0x14E762C26AE77201ULL, 0xB68B035A2D3A473CULL, 
            0x34ACEA44EC7152B5ULL, 0xAE0EEF797A7CE733ULL, 0xE26766B46A230B3BULL, 0x685F2AF33C0E455AULL, 
            0xE744FF4096A003C0ULL, 0x8CAF8B2DFCCC7647ULL, 0x5DB4C576BEB79A2BULL, 0xE0FB0DACC04A21D9ULL, 
            0x49F384C63D35BA96ULL, 0x130569DD59531D33ULL, 0x71262097A94C3616ULL, 0x6CC168D1278BB0F6ULL, 
            0x354791CCEC5842ADULL, 0x17138D06E1B71125ULL, 0xE05419F87DC9ED4FULL, 0xDAB8B80959C09BE6ULL
        },
        {
            0x12BFE3C2EF8CD0DDULL, 0x2F68F71C443BF1ABULL, 0x830B9DFFBA6AE652ULL, 0xDF7690A2AD5D04F9ULL, 
            0x20A98065B34EAE0CULL, 0xAFF7D37A02DAC546ULL, 0xD06BAE4363C56DDAULL, 0x8630980325AE2CC9ULL, 
            0xB7D2F21A220C52F9ULL, 0x32F770C1A3D6B37DULL, 0x7A8A964BDB7CD620ULL, 0x0608D701A404A5E5ULL, 
            0x70FABD267D0236C1ULL, 0x7F0F1E0C57BAE514ULL, 0xA614CF132B45CAD6ULL, 0x068ADF629C31D003ULL, 
            0x387479BD0A26C518ULL, 0x66EDFB488B8EC422ULL, 0xA8C78723D2384DD8ULL, 0x21CFDE42D4F69614ULL, 
            0xF4F0E8EE132A0985ULL, 0x7CD9718899BB1925ULL, 0x3F33D3BAA3641BC1ULL, 0x5CB4B845E81FA0AAULL, 
            0xB58CF38B3062F3FFULL, 0xC135251B6C3A80F8ULL, 0xEE871E8603E94AD9ULL, 0xD11B1493CD856778ULL, 
            0x6B563EF650F0ABD2ULL, 0xE63FF1ED600FC781ULL, 0x9D1D2686A3390B53ULL, 0xF57B625145DC1A3FULL
        },
        {
            0x863790532D5C6E14ULL, 0x2F4A93CEEABCACDAULL, 0xA221FA16B11E8AE0ULL, 0xBA93FB5D4BEB60E1ULL, 
            0x5E5889196F3BA87FULL, 0xFF49E97937C393F1ULL, 0x87845C9A74C06EF0ULL, 0x0F502C393511723BULL, 
            0xE4168E1BC3067840ULL, 0xA133C4F96A6EF353ULL, 0x20A82796EFEBD41FULL, 0x5A7D1E1A73839760ULL, 
            0x8DA1DD2186746679ULL, 0x896A581F7E8CA8BBULL, 0xD2527887122173F1ULL, 0x3295F1F18A99A56AULL, 
            0x420719C29675E2CFULL, 0x799794CCB0117FE9ULL, 0x3376674B618C2B5AULL, 0xF93BEA2391F8D82AULL, 
            0x1ED06D33F74EA562ULL, 0x2A7EACD6FFCAA3EFULL, 0xBDFFEEA2B7AA8CA5ULL, 0xB03FF9F01CF92C0FULL, 
            0x3AFCE4DD62C6E14CULL, 0xEDF11F7476075847ULL, 0x5BB284F35FCB6408ULL, 0x2A73015807EE763CULL, 
            0x3BFFBC07DC18E3E0ULL, 0x2F4A9E44FC76E546ULL, 0x4C7AC45F1C41DE43ULL, 0xE4E23BC182936A03ULL
        },
        {
            0x695186C706657B56ULL, 0x0C42AA5305D774B3ULL, 0x389E682BAEE77E82ULL, 0x4FAF7D9C0AC6309AULL, 
            0x840CAA1C1FCA5E9AULL, 0x899CB798ED0F1147ULL, 0x0F3175C292C0E1C0ULL, 0xEA2C129429CFF4B3ULL, 
            0x765054ACFCA268F7ULL, 0xC4D3C45C9B034D6DULL, 0x58D4224088C0CBD7ULL, 0xD38ED0D11F1F7601ULL, 
            0xA6F63A3162914AE9ULL, 0xD4347E3FDC39ED7FULL, 0xBE833F115CDE4047ULL, 0xF743C5FCB6020AA1ULL, 
            0x9C739A4DF2C115BCULL, 0x8912060BA7186892ULL, 0x06462DDC413AA3F7ULL, 0x8FA931A30C7A5AA2ULL, 
            0x699078C86EF80EFDULL, 0xFB533BD0C40596EBULL, 0x6EF30DEEAB3A6101ULL, 0x7BC61456189E57CEULL, 
            0x56DF0340BE2C0F03ULL, 0xC83F62793BC504A5ULL, 0xDD5E52ACEE49316AULL, 0xE9B1C81AFC16C9A1ULL, 
            0xF939C3253DEEA444ULL, 0xD25863FB841C147DULL, 0x425FD2FC307D9394ULL, 0x191986FB6D90E085ULL
        },
        {
            0xBA2527DB24571295ULL, 0x0833A1545D450F7EULL, 0x3E1E291F38726D4EULL, 0x215CBA2205C2BA42ULL, 
            0xE15E717A84AA59B4ULL, 0x4A1FFDEDFDC28484ULL, 0x67ED5B71FB0EA254ULL, 0x44EE26437A74359CULL, 
            0x24AAAA680F1A2EFBULL, 0x9BF91D62B32DD28AULL, 0xCFCFE1BAFC8D4BB7ULL, 0xE2F393C73EFB2FA8ULL, 
            0xD582A4A70E0A6B6EULL, 0xFB6B10CB6C3B059FULL, 0x3E4BF33816717927ULL, 0xA723E6842ABF5C90ULL, 
            0x81D7191810D20D93ULL, 0xCAA670C67F4687C3ULL, 0x222EC039C4DC9A44ULL, 0xB202DEAD24DD2D92ULL, 
            0x3BEE53DD7A95E0FBULL, 0xB56A99B84A5D27E4ULL, 0x6E109D5E85F2FBA9ULL, 0x128691F401186332ULL, 
            0x3469527B3380A7FAULL, 0xB352D92006F35C57ULL, 0x8515EAD32F9ED1A0ULL, 0x554CC46521097549ULL, 
            0x0BE35C8DC139E037ULL, 0x2FF24EB0203D2F7CULL, 0x893311D39A36B91DULL, 0xD734FEA51699CDA8ULL
        }
    },
    {
        {
            0x8130FF996EE4CE7CULL, 0x7BAB79C455BD68F2ULL, 0xF2B991392E5FA738ULL, 0x79A96761AEE7E7D1ULL, 
            0xC3C7CA5E184D3335ULL, 0xE7D7A40DCB086A6CULL, 0x193054D88C2D0F82ULL, 0xE7667277D14CFF6EULL, 
            0x547DC7AD20FAA6FEULL, 0xC6026BD1C2697A25ULL, 0x603C77B806AEA339ULL, 0xB2BA488E19C3B23DULL, 
            0xB07D848AC33B5CF0ULL, 0xD33EB73EDCB8937FULL, 0xF7C19389C3312D0FULL, 0x42E7F017A2B14D8CULL, 
            0x9CA366FB9E882166ULL, 0xA2941CC067E5F073ULL, 0x4114750576132424ULL, 0xDAD69EC445772B2BULL, 
            0xED980E9C0500E6E4ULL, 0x223B18A15A65C4B7ULL, 0xE16A595766D8BAD8ULL, 0x535A4D941504E89BULL, 
            0x6971C69C147ECA00ULL, 0x7D0BE4BD5A2AF4E9ULL, 0x2DFEE69B920894DAULL, 0x39678A07FE321B52ULL, 
            0xE12A50840A8FF585ULL, 0xC840871AC5E27B40ULL, 0x6FB6B84878029C1DULL, 0x311F470C20BA9014ULL
        },
        {
            0xCAECC84EA7E6176CULL, 0x47B1975E28D030D3ULL, 0x39212A78035F67A6ULL, 0x33585E93A92830E6ULL, 
            0xC60ECF1D5A191DB4ULL, 0xD6E99174C64E3ED6ULL, 0xD0A829B93B6EDFCEULL, 0x2331AB5D7345C16AULL, 
            0x360B4B7961B40691ULL, 0xA9005B6DB2FDA2BDULL, 0x3E5EBC8F029120F9ULL, 0x88F23350F1B93EA2ULL, 
            0x0AF7C6DF60796DA6ULL, 0x153DAAB19E433A33ULL, 0xC8776301A854ABC5ULL, 0xA5AAEF40ED769364ULL, 
            0xBEAC95EC1166EB47ULL, 0xF5C93BCCA4FB0B56ULL, 0x94140852DB430317ULL, 0xC64B45D502A4D59AULL, 
            0x1D48CF11B59D5A13ULL, 0xEA4576E5D0B1BF45ULL, 0x37E4A2AA442F81ECULL, 0xC6C4336B8544F757ULL, 
            0x5843AD321884F1F8ULL, 0xD20CAC1CDE657F38ULL, 0xEBB29CA6E320DA5CULL, 0x24BA1054A49D9A1AULL, 
            0xCABFAFBC7FFB9F24ULL, 0xF310F3A5A0D72CACULL, 0xB6BD3E31C63AFC33ULL, 0xE47674E2337A0090ULL
        },
        {
            0xC4FDCABCEFE4B9EAULL, 0x5CCEE777E3572365ULL, 0xEBC95F143BAA3B09ULL, 0xEA75B8EB5D44E72CULL, 
            0x4E472BAA06B468F3ULL, 0x1A3F7E6901843894ULL, 0x806BA59B6607B10BULL, 0xA98A7907BFD0C584ULL, 
            0xB3B3353B10829956ULL, 0x42C836D2F49F24CFULL, 0xC77F2D4CD285E90FULL, 0xFB1D4BEDC6A025BAULL, 
            0xD72D7F238FA998F8ULL, 0x0E0890C4CBBD8E04ULL, 0x3785EE8B5ADDB14CULL, 0x20853305495AAA5DULL, 
            0x6D48012649837064ULL, 0x82C02721D92498FFULL, 0x4AABBBF1DF6B2F72ULL, 0xFBCC3CD35972D183ULL, 
            0x17E6A8BB82DFE4F1ULL, 0x7DC5D4FD82D2F2E2ULL, 0x57E5FFC96C9713F7ULL, 0x3C061FB3D83B37B2ULL, 
            0xE6E9F277D9E0E32AULL, 0x8EF92E15190C84F3ULL, 0x2C6A867ACBE1DCCCULL, 0xCCAB122E1EA5B6A0ULL, 
            0x88C20C6763E86086ULL, 0x89ED117C02090D60ULL, 0x00801BC464E0B759ULL, 0xBA4F3560DB4FE814ULL
        },
        {
            0x097C17DBCD6584E3ULL, 0xE613DEBDFC8C87B3ULL, 0x10B0BB75AC564BCAULL, 0x33C2E12AABD852BDULL, 
            0x11490B4D33BE1314ULL, 0x4F3D7FD2759830ECULL, 0x4AA4A87ADFBC44ECULL, 0x2EE8AE38247F0CE0ULL, 
            0x9BB22E4D7BA6C021ULL, 0x26F60CBC97609B36ULL, 0x521B69220E8D3CF6ULL, 0xCF60B1EEFA27E363ULL, 
            0x398BF7B605A41C3FULL, 0xF99E80574486DFDCULL, 0x26399C12C8775155ULL, 0xA219EAB20F98B142ULL, 
            0x7E8F432939B08D24ULL, 0xAF60A76D148CCA8BULL, 0x5129E406C6C3535EULL, 0xA09D79D93675C902ULL, 
            0xC62DC1763D535ABBULL, 0xA8616872EB15BD0FULL, 0xD5DCB9AB39E47090ULL, 0x662484AA17133FEDULL, 
            0x1AA5426AC98CBF5CULL, 0x66154BAC06C32A5FULL, 0x3D33C72350F59148ULL, 0x43C6EB183B4AFF43ULL, 
            0x6C74FE8A93468929ULL, 0xBE7A56547883D604ULL, 0x632796ED4369D936ULL, 0xE5E42481F1F3DB6EULL
        },
        {
            0xB66628C3F689BC99ULL, 0xC3E6430A036BFCD2ULL, 0xBA0578AB10071B8FULL, 0x67F1699A2935980EULL, 
            0xD59F2D8A63B769FBULL, 0x2C100C92FBC9783FULL, 0xDC8E2EF27426559EULL, 0xE254D1DA77BAD960ULL, 
            0x0047A33EE31997D7ULL, 0x3E73960F7B4F2601ULL, 0xE4CD85573DCFE7C0ULL, 0xA1F9C337DB567731ULL, 
            0x22B5A8EA701A5071ULL, 0x89537D7577D2C03DULL, 0xC8F4592638DE7557ULL, 0xFDF75D22EF02F586ULL, 
            0x069E90383791E599ULL, 0x106992B2D2DA29B2ULL, 0x3EB5F7D1B85821AAULL, 0x425D3B66733740F5ULL, 
            0xB58EDFF37FC268B3ULL, 0xFF247C3E07499C8AULL, 0xA1C0A867C3EA7C6EULL, 0x28AA7C7287603057ULL, 
            0x70B5B0480F19A906ULL, 0xD9226058DC4FDC22ULL, 0x95308E7349857C7DULL, 0x6C329F669F22DAD3ULL, 
            0x241F398E9A1F9289ULL, 0x1252A03BAC384A0AULL, 0x4ABCB0D367FD5F19ULL, 0xA431D95A6CA66069ULL
        },
        {
            0x788FC2EB3A462EDFULL, 0x2F0DEB94A5C9BEA6ULL, 0xD992F010447B74D2ULL, 0x2C00AB02F7BFFA4BULL, 
            0x882E2F1F0E1564AFULL, 0x00C40D09B3BC7819ULL, 0x6C8793ED17C5FD10ULL, 0x7B6DB95FC9B34045ULL, 
            0x14B9A42830FFCAB7ULL, 0x35A8686D86967DF1ULL, 0xD4389812644902B1ULL, 0x6EC6D128343D66DAULL, 
            0xD774547F10140096ULL, 0x3BABA0D07C4426BBULL, 0x3C78DDAAE86C419FULL, 0xBABD4807ED1CCBCAULL, 
            0xFEA256DD395172E9ULL, 0xE3A2B9B21539A4E9ULL, 0x33D9D3D0E863A719ULL, 0xDA386B974D30FF4EULL, 
            0x0866FEDDBC5F1FF6ULL, 0x8A66D6F447DB167AULL, 0x24D1D18B4FA9F246ULL, 0x963541ACFDB24EF3ULL, 
            0x1B95BC35165437DEULL, 0x4FFEFEC49C5F30F8ULL, 0x42B32FF84476DA17ULL, 0x576688EB690EB518ULL, 
            0xDD3416FB1A8AD627ULL, 0x082E6F66DEFD8D47ULL, 0x01E76080FB5F6533ULL, 0x890525948ACFACCCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeySpawnConstants = {
    0x57B63EE1E2F26BECULL,
    0x19678EB67058E13BULL,
    0xBE14B688AFA3AD77ULL,
    0x57B63EE1E2F26BECULL,
    0x19678EB67058E13BULL,
    0xBE14B688AFA3AD77ULL,
    0x4FD87212F5B83648ULL,
    0x92ADFEE96F204A14ULL,
    0xB7,
    0x49,
    0x07,
    0x03,
    0x5D,
    0x6F,
    0x98,
    0x0E
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kSeedSalts = {
    {
        {
            0x370A205CAF8CDFFBULL, 0xA82EEB35FE344D9AULL, 0xA490D21E6FCAF7DDULL, 0x6F34FD68D6B0B8BCULL, 
            0xDCE2F8CE2F2AB1E2ULL, 0x43F07EF434848B3AULL, 0x93A5B62D85CE8B40ULL, 0x57EF4384C8C505EAULL, 
            0x73A6B4D572E2E014ULL, 0xF5A80D4517586A11ULL, 0xF0AA7D45BD75F622ULL, 0xEEAFCF0FF6AC3139ULL, 
            0x5625705811FF40A2ULL, 0x16956E62ACD39CE8ULL, 0xC9FFBFFE91478A7DULL, 0x7CB07F93F28359EFULL, 
            0xFB5CFB462812A5A2ULL, 0x5D1256861168161FULL, 0x4F92515B28D0FA7AULL, 0x43357251943D1AEEULL, 
            0x28F1C7181A08D68AULL, 0x0833FC776856F943ULL, 0xE5FAF4DB2F1CA9BDULL, 0x515A4D64BDA9D722ULL, 
            0x1DD3A32736D33B18ULL, 0xDF18C58A5C779FC0ULL, 0xDDEDC2E07EB336E2ULL, 0xF1900C599AF0670BULL, 
            0x4199960FA68C2224ULL, 0x1E163CF9E4B0A7ADULL, 0x32880835FFB19715ULL, 0x6289F59762DE0ABEULL
        },
        {
            0x76228B89CD4978AEULL, 0x557E4DE34310A5A5ULL, 0xB895E33E02690D02ULL, 0xBA52297C591A8DB0ULL, 
            0xA15D8B4F139E2667ULL, 0x636FB0905189D821ULL, 0xD427BBB221462099ULL, 0x2DF3C271E876FF43ULL, 
            0xFAE1F167DF9982D3ULL, 0x32D395323F69C2DEULL, 0x654CFBF7FBF617BAULL, 0x27EDB53C1F34F52CULL, 
            0x515219EE5A842879ULL, 0x6EBEF466BBC0814BULL, 0x47DFC4C7652BA8A9ULL, 0x4C4789A0FACD1F5FULL, 
            0xC494F03FB322EFA9ULL, 0x1CC65F10542A5091ULL, 0x1D24A2690AEB016FULL, 0x02A6ECA21D820F22ULL, 
            0x7FFC5DEE85BCA311ULL, 0x2F2C11314CA59BBDULL, 0xA96E74143EB77014ULL, 0xB2334F889BC428C4ULL, 
            0x38F510E596A5E702ULL, 0x9795C45B2D9AE36FULL, 0x4F71052E92DEC71CULL, 0x8B16563A23933928ULL, 
            0x351E9F219C08063DULL, 0x2EE9F64C051F895CULL, 0x8B1D67D83371184CULL, 0x3EB05837DF6372C0ULL
        },
        {
            0x395877268E59946DULL, 0xD8E56D4A681E8808ULL, 0x156F87F24393E946ULL, 0x1E9DA2005CF3FC18ULL, 
            0xCDC5D14A30F1E16CULL, 0xE98CEA466FD6338CULL, 0x63C7EC36EDA63AD0ULL, 0xEE6AE1824987201BULL, 
            0xCD8D189B9933B300ULL, 0xF98E83572C881422ULL, 0x5D3FC03E01CA6B54ULL, 0x6D7C91CEEB024322ULL, 
            0xEBD89FD3996A979FULL, 0x6E2A6476EDCC1E68ULL, 0x831E4478CE100AACULL, 0xF7002D4EE54FC75DULL, 
            0x6030865497A43EC2ULL, 0x7C2F5CB8E5126CE6ULL, 0xB700090DFC1F68BFULL, 0x38AEB3EE72BCFE7AULL, 
            0xD0559E2CB96217ABULL, 0xA50FB54350D1BBBAULL, 0xE92C341A6507CAB0ULL, 0xC42F77BAEC67DBE2ULL, 
            0xD61560302751AA65ULL, 0x016304FB51397306ULL, 0xB54AD402D415A603ULL, 0xD0EA2F34306CE60CULL, 
            0xD824BD1C1DE5D7C0ULL, 0x092342A07ABA972BULL, 0xBAA35F080ED68216ULL, 0x944E36425DA5BF8CULL
        },
        {
            0x2195CDB59A052B87ULL, 0xC57180B474FE9443ULL, 0xC2824B0AE9F057ADULL, 0xE535D35DCF6879EFULL, 
            0xA55E79E8C2FAB7B7ULL, 0x0466DCB17F13FA17ULL, 0x59EB11B1586C9F51ULL, 0x128F47E78F4404E7ULL, 
            0xBD555188B5CABE90ULL, 0x6142C32B098204D6ULL, 0x773F3D0D5AFFA895ULL, 0x61E301D6B1710BBBULL, 
            0x0FAC18B1BA72B83DULL, 0x663690AB97BEEB11ULL, 0xE20B3359CF5ADCA2ULL, 0xA03ADA9695996BAFULL, 
            0x1E5E8C13E194D2AFULL, 0x877E9420C98ECF54ULL, 0xC43880E875CA4D0DULL, 0xF9FE4C9D3F096310ULL, 
            0x10E3360E8E2DFA87ULL, 0x14C1F4B514A11B8BULL, 0xCC5623C332C58997ULL, 0x59B44BAA0B39A5DEULL, 
            0x03A9F5E24B1B2A0BULL, 0xA798746EDA2AD344ULL, 0x72EBF09FB1A5E923ULL, 0x1A60F4B42E0FE307ULL, 
            0x35D51288372FBFC9ULL, 0x75A01ED68907324DULL, 0x56AF76FD6A473CB9ULL, 0xB3AE0F2C4F4C8082ULL
        },
        {
            0x413A34BA45E0920DULL, 0x863D1D5BC0394420ULL, 0x62C1DEBA8E948D3AULL, 0x0D1859DE55B7B7C7ULL, 
            0xDAB0139BA45E3EFBULL, 0x9474B7920C4F2250ULL, 0x5D7EA2BBC8BB7641ULL, 0x3CC9CB88DA7C7A44ULL, 
            0xD34C4A2DFD84B6A3ULL, 0xB1A664E364FFF50EULL, 0x532A5624E3254F2AULL, 0x28ACF8520312C32CULL, 
            0xC716107422C0DBC1ULL, 0xB5804A78A619B5C0ULL, 0x0BD2480F7F6D39CDULL, 0xABAF5AF8CC309964ULL, 
            0x07A32DCF30A26558ULL, 0x27968AB1A0899302ULL, 0x05E678669D5F19C0ULL, 0x0170BEB674B4238EULL, 
            0x0D100684D284BF14ULL, 0x25934CE8E46E071CULL, 0x36ECF75B4BD9E156ULL, 0x18CD85AC6FA6281CULL, 
            0x0A124071EC8C1D4EULL, 0x8BA639DE618670ADULL, 0xF4D932A2D792A15BULL, 0x6CA92FDA006389D7ULL, 
            0x1179EF2D5E18CA1EULL, 0xBDA3EC7DF9CEA566ULL, 0x962199C5B8C81253ULL, 0xB0AC3D2A66303408ULL
        },
        {
            0x4C9F895518416DF3ULL, 0x817D83C5FAFDD25FULL, 0x34E08B6D587A7716ULL, 0x52BD9EBCA68F4826ULL, 
            0x3EAC89798D5673BEULL, 0x176BC8471A5AB212ULL, 0xE23F3CC9511BB9E4ULL, 0x0617ADF1C7ABE836ULL, 
            0x81356EDF80CFEF26ULL, 0x5F0C6841F65B861FULL, 0x071E67DA14E7309CULL, 0x486942E98272A4DBULL, 
            0x7CCEABAA59C8AB07ULL, 0xD636E7E84DE04576ULL, 0xCF32C88D86F18F7EULL, 0xA344049741AA14B2ULL, 
            0x1E2B1E7E79D3F523ULL, 0xC01A9D0D1461501CULL, 0x3325221F8A928C12ULL, 0xC417B9DED3D58BC8ULL, 
            0xC720AA0FDEFC39C7ULL, 0x80BFF57087267D8BULL, 0x3F8191B077D9EB14ULL, 0x3A0A888CC27DBDFFULL, 
            0x8F54B05AF2495B87ULL, 0x2AE8032E76463B64ULL, 0x44657824A5A6AB5AULL, 0x84144CF0927AFB99ULL, 
            0xFDC6F70D30148814ULL, 0x96FA7FE5A9C47FE3ULL, 0x8D2E718B1E53E15DULL, 0x44B945589183CDD7ULL
        }
    },
    {
        {
            0x754FAF838AD22ED3ULL, 0x8985FAD6518CF0E2ULL, 0x75D86FEE84B44E14ULL, 0x58B1C4103A3E25E5ULL, 
            0x87188549DE89DA63ULL, 0xB3EA6704405B5F36ULL, 0xF6F0513AB78B4C01ULL, 0x8D90F347FBDCC972ULL, 
            0xB7642EBB28835B36ULL, 0x72E336443D5CBEC7ULL, 0xF16EED4CE88A09BDULL, 0xFB2A450E1612185AULL, 
            0xF3300AE977F1947FULL, 0x090B348CB27DDC10ULL, 0x0F8A6861238F2E94ULL, 0x67BF93BB4506CB58ULL, 
            0x5CA7401C1D99EBE8ULL, 0x7EE9E0D52F8416AAULL, 0xCFD6FFDA1A85BE99ULL, 0xED7F0D2FB8AD5804ULL, 
            0x68FD1D365DA08084ULL, 0xA3C1B99DDF908EF5ULL, 0x0602D1C697A3BE11ULL, 0xFF17D09ABEA8A580ULL, 
            0xD71E4798DCAD27A6ULL, 0x76F0EE7E0C1C32F0ULL, 0x326B27C08E313F5DULL, 0x2EB518C0E47A9D4CULL, 
            0xA814240FC86D8C67ULL, 0x65B19F8C99F3AA7BULL, 0x00242754A7890429ULL, 0x38772B71F6162899ULL
        },
        {
            0xF40AF24B3DFF1ECDULL, 0xCB3E8B167A6522DDULL, 0x10035C91E3E58634ULL, 0x9BCDBFE2F6FB4717ULL, 
            0x373737612BE382B9ULL, 0x9C080A017E70DE9CULL, 0x5017C63102CD666DULL, 0xC43780B4ED24AE28ULL, 
            0x4A314EF583CBF967ULL, 0x7DE6CB65DCF3CA7BULL, 0xA83869C2DD1D4E40ULL, 0x7DAB26DFCDD76FF9ULL, 
            0xFFBCE94F116138D3ULL, 0xEFFC4FBA72573D0CULL, 0xCE3D83C559318B82ULL, 0x1902BB785151FC76ULL, 
            0xD48BDFB5B8FE8E30ULL, 0xC8ADA3D2258C9738ULL, 0x8075B6DE92E0F770ULL, 0xD974023DC4748874ULL, 
            0xC74734DFE1DF708CULL, 0x9927028AAB702783ULL, 0xE6F29E5BA466719AULL, 0x070963A69672A660ULL, 
            0x8ADF1219A808DD7FULL, 0xA304A5DBD3D16CB4ULL, 0x7D167F124C991E74ULL, 0x24ECD0504AA9ED37ULL, 
            0xE547C0870C0FBCF2ULL, 0x4A417AC4531B0C4FULL, 0xF2D489DEF48BAEDEULL, 0x7805403143F19A3EULL
        },
        {
            0x1A7440538B0AE466ULL, 0x34BFB95230849B6EULL, 0x347EEC715FA63DD5ULL, 0xA03F6E1E23436004ULL, 
            0xF51B95409E81F9A8ULL, 0x66CB22881D2B17D3ULL, 0x29AAED61C7B42F04ULL, 0x9A4013F309BA8A0CULL, 
            0x731F952339AB909DULL, 0x4062A4A449488C9EULL, 0xA0D16D55BCED4A43ULL, 0x83ACB43C4A28D59BULL, 
            0x84AC83CB1A460DF0ULL, 0xD9C250BE0FCD490FULL, 0x92550367093F527EULL, 0x08CF46A81DAA9E17ULL, 
            0x6EBE9A4319C37B79ULL, 0xF8D39369F562231DULL, 0xAF87690C535DD738ULL, 0x8C195BA302BF641BULL, 
            0x14A84FFFC9350158ULL, 0xACBF41C0E015C890ULL, 0xE8F0CEE66D9886F8ULL, 0x4A413CC3FB1327E8ULL, 
            0x42B6E02660F08A85ULL, 0x6E77BA860BB3C8BEULL, 0xC2B8DE66768CB71AULL, 0xB7A225163A814BF8ULL, 
            0x674A84067124A0CAULL, 0x6CA1F992B06EFCD2ULL, 0xB61002A381F2D9BAULL, 0xDA3C3208E45B0E21ULL
        },
        {
            0x18D7104B843CB92FULL, 0x175FBF718B82DEC7ULL, 0x2715402869459D9AULL, 0xCF9C17C5AC2BA00EULL, 
            0x3C02A6479184E638ULL, 0x81BC2AF4D07030EDULL, 0x6EE6E242F9FDAC03ULL, 0x4BD4ADF23E74D3C4ULL, 
            0x1C6B67059658BB3AULL, 0x493B46A781EE8DD3ULL, 0x09AA13C295FDB5D4ULL, 0x607D8AC27E068171ULL, 
            0x9D8AEC38AA92EAFEULL, 0x7425998D60D28937ULL, 0xED2AF69B852A5C3DULL, 0x9DAC2A8B7CF54091ULL, 
            0xFA14138ECED51246ULL, 0xDAA4A05C2F833473ULL, 0x1DCC697CEC6B3808ULL, 0x9BBC834A6C66D1FEULL, 
            0xCB95C85899B46A89ULL, 0x7F877E63AF1769F2ULL, 0xB1502FADF5C7D615ULL, 0xFB48CBDD912CC534ULL, 
            0xDE994FA111F7EC00ULL, 0xF0AC6EBD39713D32ULL, 0x83B1B87A3AAB1259ULL, 0x581AA713F8B4111EULL, 
            0x64E35A5E79D31DA7ULL, 0x3EFF5ED205B9F507ULL, 0xDF94686C8585814BULL, 0x940008CFB01D4D8DULL
        },
        {
            0xDE60DD40DDC9ACC9ULL, 0xBC2F09637C317D5DULL, 0xDD6AFB89CFE89128ULL, 0x71A0566AF5B50CBCULL, 
            0x1C445E61BCDA1F73ULL, 0x93BEE41850B3002EULL, 0x15D28115B3159DCBULL, 0x7D9BD8D94A210D76ULL, 
            0xE373EEE904BBB2DFULL, 0x83BEA009229F9FECULL, 0x1C7AF04E4269C7CCULL, 0x51AC76FF25B50FC8ULL, 
            0x75FA3CCA06D1F03AULL, 0xFBADC998D35C7643ULL, 0x890070476DE15568ULL, 0x1E1109770A327679ULL, 
            0xCDE08B5292C82957ULL, 0xBB74CC35DC181E7CULL, 0x17639AD8AE0B5535ULL, 0x2AAE75BC99BCFE31ULL, 
            0x17A68A316BB4F34CULL, 0x9C3F257E5CFAA846ULL, 0x999D8DF54EB76B1DULL, 0xD14F02628B8CFB45ULL, 
            0x59F15F9198DE3FB7ULL, 0xEA3D362944FCC780ULL, 0x53AB42E4B3F7E5C7ULL, 0x2396FF90398722DCULL, 
            0xA1ACD533765575C8ULL, 0x1F8AD0BDB134A04CULL, 0x52F86A86F4CBB290ULL, 0x8F333D4161338EE4ULL
        },
        {
            0x67F47F3AAFEE58B8ULL, 0x1343A22B50DF6483ULL, 0xE3D6C4A5451D3ED4ULL, 0xC5707054FF91B113ULL, 
            0xF6E32AC9275694D3ULL, 0x144E152FFB03A625ULL, 0x0414322079239E55ULL, 0xF071774D77E23610ULL, 
            0xC1A8093C64F71D81ULL, 0xA61314F6DE36D230ULL, 0x66D10D241AC0DA40ULL, 0x33E2FEC4CDCD12CEULL, 
            0xB05E6B0EC7747D48ULL, 0x22AE31ECB35FBF2AULL, 0xF2C6144DCABBE39BULL, 0xBD3DAAADD4F79B3AULL, 
            0x9F8EC0ECE7585D79ULL, 0x549F624D6B6AF43DULL, 0x454FFA2ACC9F6EBBULL, 0x2DE9CAB3E572F616ULL, 
            0xCAFF177C087F7440ULL, 0xE9D8F9515084EB64ULL, 0x47023C296575F465ULL, 0x2BA72A0169E456C2ULL, 
            0x39D70D055FC8D78FULL, 0xC2971028D0EE1FE2ULL, 0x8BF16C7195920915ULL, 0x72BE2F5A23885B38ULL, 
            0x7E6128B2DE46B772ULL, 0x0818AA464179FCC3ULL, 0x9DCD23977E71D591ULL, 0x4A467490D760EF08ULL
        }
    },
    {
        {
            0x06789CCCDC206B88ULL, 0xAD3CC7E46EFE56CCULL, 0xAC4890BDCD4EEEF8ULL, 0x4668B2374B7F554EULL, 
            0x2D8C016FEFD92354ULL, 0xCD81FCDC4F352804ULL, 0xBD76704C74620913ULL, 0x824EAB762DBD0AF7ULL, 
            0xC2FE3E3118026F7FULL, 0x47F3F6CE62CC895AULL, 0xCF7A8B85E767B4CAULL, 0xDC2ABB644A348655ULL, 
            0xE5A556F4445C054FULL, 0xEBBDA86A531395C5ULL, 0x5CDC790E5528593FULL, 0x25CAF2540E4BBC86ULL, 
            0x4CB2302B47FCDBD2ULL, 0x7AC5930374872DF9ULL, 0xB7CC12F860F00823ULL, 0xC420C6AB4FD3996BULL, 
            0x77C569FEA6E1C897ULL, 0x5D7B7BF715DEDCB3ULL, 0x60B06A6547B31641ULL, 0x45D8D5E530758B00ULL, 
            0x63FC78529C5A9430ULL, 0xF57305AAB53BFB05ULL, 0x9B2EC3E37192139DULL, 0xCBC3BA6451F8234BULL, 
            0x18BF8AAD9E21C41DULL, 0x18F773A1EF5267EFULL, 0xF5B9E6DE1A8EC20BULL, 0x9743F490D43C022FULL
        },
        {
            0x547777B7B83CD4E0ULL, 0x993FA1E07DF99B7FULL, 0x7AE5C4CB3754292DULL, 0x5DCD660C3FB0A6F8ULL, 
            0xDACAC91EC6CBA71FULL, 0x524F826550E87AB9ULL, 0x8319EFBA3612B04FULL, 0xE2B6A005266442FAULL, 
            0xA3403813749386E5ULL, 0x57B0A1E2065AB3C0ULL, 0xD6BBDAA529E947CBULL, 0x6AEAD476F790F3F7ULL, 
            0x1A8072DB7A376488ULL, 0x30EC750399BAC9F6ULL, 0x23C7DAC928F52479ULL, 0xBC8FCCB2D71320CCULL, 
            0x22901DAC60E1109BULL, 0x33BD3401D581C933ULL, 0x782D900F93CC7187ULL, 0xA77AAE3CA0710CFEULL, 
            0x0CBA0558C9221137ULL, 0xDBAF1FD3956A8A22ULL, 0x5FD5E16E41F9C73FULL, 0x9AC88D3DCF4AD93AULL, 
            0x220646CD80382EE3ULL, 0xFC79BC98BAFA7401ULL, 0xC466CD086FE1981DULL, 0xD2856426D64CC198ULL, 
            0x23E41F30A994521BULL, 0x388F2D87E9F6BC06ULL, 0x39A6627B8ED1F1EAULL, 0x388686BEA8499CB9ULL
        },
        {
            0xA7ED709F92C06C46ULL, 0xCF1E1978166B2BA2ULL, 0x6ACE49C480DEA26DULL, 0xAF1F153BCB5A8CD2ULL, 
            0x16A3CF9BCDDB128AULL, 0xF66055D7668A42ACULL, 0x6DB247225AC754A3ULL, 0x2927BE06A0967B84ULL, 
            0xDD57EA4B162A9324ULL, 0x8A82DC28206F3E81ULL, 0x50B848DD198DFE5CULL, 0x2A0C4FC240C40AD3ULL, 
            0x35C37C85B7846FA9ULL, 0x11D117A0DF01D564ULL, 0x6BEDDD6EDE10E006ULL, 0x1363FC138DB957C5ULL, 
            0xC6494812F42696B9ULL, 0x2A5F3978E37F41DEULL, 0xA08CF4A863553558ULL, 0xBAF118BC080248B4ULL, 
            0xC1D39D09D007AB5CULL, 0x3179F843244ED06CULL, 0xA8F3B98CFF304113ULL, 0xA60F459BB71E94D1ULL, 
            0x1551B54A6EED00F4ULL, 0xCD6D426E49DBE805ULL, 0xF2DB57C264345E1FULL, 0xCBCCB2B5579FDF34ULL, 
            0xF106D46FB4958D21ULL, 0x30A305723A60ABF4ULL, 0x17795E9E33B54D19ULL, 0x3C94D14B0D6779EAULL
        },
        {
            0xAB751E9FFF631C90ULL, 0xAB6B31F80838E648ULL, 0x29C1402C92C01C65ULL, 0x495B1FF8ACF1B638ULL, 
            0x0CBAD9FC0C891EFFULL, 0xB94B00C174AC0BFEULL, 0x30239B8531A81458ULL, 0xFEC983432581D2D6ULL, 
            0x193290AFD960EBD5ULL, 0x67C3BA200CEAFC87ULL, 0x4DD1CFC365DBEC07ULL, 0x4394D9DC5E3E639DULL, 
            0x0D834A84DECF8AF2ULL, 0xB3E71E9B973AC944ULL, 0x55D26CD207B816DDULL, 0xA2D1C689CE25B304ULL, 
            0x70EF47C93E17E6EEULL, 0xBFFE46E291025D6DULL, 0x882FA35AD5F0AE60ULL, 0xF5EE8AC3842A6994ULL, 
            0xF10BCFFE7A563AD0ULL, 0x8C112C14615624F8ULL, 0xB1429F0E3C9D8099ULL, 0xC088EC005E1904F7ULL, 
            0x7855AB898908900BULL, 0x9A992F3BB027087AULL, 0x4024E5CC57D87A94ULL, 0x55093DDB342C5805ULL, 
            0x26342BC0AB4747D4ULL, 0xA783136FED1EBF58ULL, 0x76666CE09E9A4FCEULL, 0x7C496DF5B7C89AA2ULL
        },
        {
            0x63B002E70F3D840AULL, 0x281ECA407AE10E91ULL, 0xD89D49B53A47631FULL, 0xA59D14C5081CCB9AULL, 
            0x173F9732DD6A54EFULL, 0x799C5F29E479343BULL, 0x0FE9D752DBBA7693ULL, 0x0838F1BDC784F484ULL, 
            0xE0BFEAAE59F5F36EULL, 0x52AAD24E2149ACF2ULL, 0x9905BAD185FF0D37ULL, 0xCCF083639318A293ULL, 
            0x4D9BE7BBB72823DDULL, 0x479FC0A9910E3B7CULL, 0x3C62FAA69A5E6946ULL, 0x473675742C0732D6ULL, 
            0x1D6E9DE1807D6CA6ULL, 0xD866A11143ABC4D2ULL, 0x48634408A4A26A21ULL, 0x0C3784F004126046ULL, 
            0x9F9D17C42F6AA6FCULL, 0xF3927F85A669C63EULL, 0xE5C85541BBF3AE32ULL, 0x6ECE1C2F2CB5CEC7ULL, 
            0x3BD85CAF08C8D8E7ULL, 0xE204609993F01CB7ULL, 0xEE79EE799A4FA331ULL, 0xDCA2BA69EE5390AEULL, 
            0xEFF94BA754C35ECAULL, 0xFD710CDC1A5523FDULL, 0x513A60B03CA8CD21ULL, 0x1955DA573976F0E2ULL
        },
        {
            0x12A5775728AC1C46ULL, 0xA0F7F52F3E6E2D78ULL, 0x372BB959D4AD9578ULL, 0xEE5B9D927DAB77C9ULL, 
            0x6059C447FBFA88EFULL, 0x25CDDF3A2816DD9FULL, 0x66985B26863653DFULL, 0xBA67FC8A78731944ULL, 
            0x58897238C9EC32A4ULL, 0xCDE78BB4EB88463DULL, 0x6D156838B6608E85ULL, 0x33AA4E839A05B218ULL, 
            0x3742B8F3F1C51959ULL, 0xB5DE03FBEABB161FULL, 0xE1648460107BB35FULL, 0x9E572F861913A903ULL, 
            0xA6F43ADDAC76D070ULL, 0x18719A865EAD8A21ULL, 0x2ADBC6132DD11C1AULL, 0x9D062C221DD0A70AULL, 
            0x1915ECCE845421DBULL, 0xD715325DBFB7677EULL, 0x5B1374E2978BEEBEULL, 0xB6CDF289DFCEFBBFULL, 
            0x6444E5ACEC84ADBAULL, 0x884B50DE35D475A1ULL, 0x6769A6B58F8CB046ULL, 0xF1FD164864FC98E3ULL, 
            0x7BD257FB4E3EFCCDULL, 0x0A2116CE0AC2449AULL, 0x9A4AEBE3FCC6DE2CULL, 0x05BC2FC7555BFA01ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kSeedConstants = {
    0x74DEE3DE464A23AEULL,
    0x2166054B5D83B3DCULL,
    0xFDD5EABC0F9F4C26ULL,
    0x74DEE3DE464A23AEULL,
    0x2166054B5D83B3DCULL,
    0xFDD5EABC0F9F4C26ULL,
    0x30C8CD27E71EDD41ULL,
    0x2F97FB307511AABBULL,
    0xA1,
    0x87,
    0x67,
    0x2F,
    0x37,
    0x45,
    0xA4,
    0x94
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kTwistSalts = {
    {
        {
            0x7660131E519085B6ULL, 0xAFF71104B6711D2BULL, 0xBCBBDA27E9EC6F4FULL, 0x6612244EBDFCA16BULL, 
            0x2DE91180AD23B4BCULL, 0x7FF1131C26F41E12ULL, 0xE8EF52C6FA7E811BULL, 0x4AD789497C6311D6ULL, 
            0x36DF9264349B64E3ULL, 0x052CDDA2A6DE6380ULL, 0xCD8DEB557381F3B9ULL, 0xB36252EF27357A63ULL, 
            0x3921B3CA5777E02DULL, 0x1B508DD1D6F89A7CULL, 0x5EF44CB062FF70DAULL, 0xB1361548CA0129F1ULL, 
            0x97592CF4D6EC7190ULL, 0xB40E98FD0846D5F9ULL, 0xEE7997B39E9C2108ULL, 0xB6DBEB28FD2DBB23ULL, 
            0x87D44F7F661A47A5ULL, 0x3D8EC43B81F9A97BULL, 0x5DF44D85ACE13FDFULL, 0x8983FEF93FC1F3A5ULL, 
            0x792C1D6F61210BCDULL, 0xB2E55C646DD69AE6ULL, 0xAC290003CD14A76DULL, 0x426F1555428176E7ULL, 
            0xEE962B876F805AB3ULL, 0x96F4973DF448A223ULL, 0x7138811619CCEF02ULL, 0x44026A0232F52A79ULL
        },
        {
            0x2D77E57A610A0E88ULL, 0x6130A1FC1B40D8D1ULL, 0x2AB230F14DE409F3ULL, 0x948E014C1B23BADFULL, 
            0xD0C398833FD22803ULL, 0xF5A53646F1566394ULL, 0xA2AE62DA58EAE009ULL, 0xCC3B997D0B3D5204ULL, 
            0xAF5976AC3597E492ULL, 0xB81C56EBB35ED16EULL, 0x59C48D70AA325275ULL, 0xC01F8EE2239D1C8BULL, 
            0x10790127D30712BFULL, 0x410ED7AA7D37781BULL, 0xDB44B1AF37810E15ULL, 0x4C203EA38BE6FD3AULL, 
            0x5A7D6B723ED725F0ULL, 0x0E533FC821A39C77ULL, 0xB70D24F66FEA1393ULL, 0xF7711495B0E85534ULL, 
            0x4F69CF1DC10C1C6DULL, 0x7EB9A645A28BCD13ULL, 0x1E219EDF090E86A0ULL, 0x92F0DBF43A4F79A7ULL, 
            0x3D1B87EE1AB11B5AULL, 0x968582B04DD71667ULL, 0x3BAC26542A0A965CULL, 0xE6CA89272B95AE9BULL, 
            0x0011ED7F0441B8A3ULL, 0x24B8D494D885DF6CULL, 0xF848D4FD1FFECA9FULL, 0x2F8A86196858A8F1ULL
        },
        {
            0x73A72DAA4A4758CEULL, 0xD33CD585C72A1963ULL, 0x91094D489B157A26ULL, 0x4235352875DC6A18ULL, 
            0xB227748B2A113055ULL, 0x892F8B00B15FB3C4ULL, 0x2EBB0614B1D33F14ULL, 0x7DC40E65D35CDEABULL, 
            0xAC6C1E2897556D04ULL, 0x78B2B2E298FBB267ULL, 0x2F0F5E3AC94FB240ULL, 0x6A3F9635117965F9ULL, 
            0x104A7E183BC4E96AULL, 0x1ACE269E539EBDD9ULL, 0x5C4B633E9BCCDDC8ULL, 0x4EEFEB89EC5A35C4ULL, 
            0x40D93C89895EDCE2ULL, 0xA7F0140EC53DCAB0ULL, 0x449E09FD24E19808ULL, 0x9558DAA2A2AEAF2AULL, 
            0xB0442D61B4DCBC7CULL, 0x0D82CDB5C1115105ULL, 0x8D6B79B96FC04862ULL, 0xFC7408E182E566F4ULL, 
            0xCEBFA13CC3721B8CULL, 0x7501D6325A2ADC48ULL, 0xBEFFF62050A7C3B8ULL, 0xFA20128DD3336CFBULL, 
            0x653245D2EE96320CULL, 0xEC3B6F56074C6C54ULL, 0x909B3CC12C43C8CCULL, 0x381A690246839DD5ULL
        },
        {
            0x3D586439243480AAULL, 0x986A2F2A5860B572ULL, 0x1FB71E0C6D448E1AULL, 0x414AC376A62A827DULL, 
            0x5A609D2C844B8C8EULL, 0x874C3A962C7B8DD6ULL, 0xFE6E4A8AE0D256BDULL, 0x1F3EA6B8B57E636AULL, 
            0xDA2907BFBB242406ULL, 0x9D158A985ADF7666ULL, 0xAE5B5915344C1407ULL, 0x2F578EC073901A78ULL, 
            0xD1DF83AA22D61561ULL, 0x58407F20652F2097ULL, 0x5A12BBAE34F6112EULL, 0xF192209DD921C1A2ULL, 
            0xC2A1198D1BA1CB95ULL, 0xADF7F4CC50EA9027ULL, 0x9F775195FE650435ULL, 0x5BE44B1D26E3B284ULL, 
            0x38DD9716BA9C76CAULL, 0xD3754EEBA62AFB54ULL, 0x9A895A19918EAF70ULL, 0x7A5E7C2B676051CCULL, 
            0xCC3B4A54130E4DE6ULL, 0x7F321004E642EE61ULL, 0x6800885F82885231ULL, 0x67997948061D141AULL, 
            0x012DA33B8E07AC55ULL, 0x86918CE232E182A2ULL, 0xAFE7F8CD3C8DC8E7ULL, 0xDD9A7B8B44A0E6B6ULL
        },
        {
            0x37E96033D8B4ACE8ULL, 0x788472586F21420CULL, 0x0FFEFD366C8ADC56ULL, 0x0987D9C832D03568ULL, 
            0x998E76B3997ADDA4ULL, 0x58D89C4F8B2A910FULL, 0xBF73F7BF5C98DBE1ULL, 0x8B4B56254BE62E46ULL, 
            0x3E6C63AA2F08C73EULL, 0xCBF0BAEA5BFDCEB3ULL, 0x91A0E6FC75950BB3ULL, 0x3E50D2E2F62591E0ULL, 
            0x7CC732477C93C8D3ULL, 0x703963217A3933E6ULL, 0xA5356D607BAB013BULL, 0x4ADB18D14D88794EULL, 
            0xFEDD1BEA2E82F820ULL, 0xDC624CFD38D3E552ULL, 0x084E64068305D747ULL, 0xBCDEBEAA2F73015BULL, 
            0x5C31FB4F6F2467F5ULL, 0xDB02E9EA183ADA50ULL, 0xD195AEE3D2C4B275ULL, 0xDDEC2B13BFBC8B97ULL, 
            0x559194E262C1C28AULL, 0x2FB73821A0651105ULL, 0xDC3D4A64391F1DA1ULL, 0x76F02052A8095A50ULL, 
            0x097B578A8945991CULL, 0x5A487FA93B2B51F9ULL, 0x0824F92722F6413AULL, 0x8F94180A295A6E53ULL
        },
        {
            0x78CBF6DFABC6FFB1ULL, 0xCDD79165294402F2ULL, 0x22D369A3DBE6E97EULL, 0x2674BFB5BDD4BAB5ULL, 
            0x5DDA643FE52AD19BULL, 0xFFFB9297EB21A867ULL, 0xFD00D396EF59ED89ULL, 0xA75884FFA949101EULL, 
            0x4D833F89AA1E0E29ULL, 0x94584AD42D7F4155ULL, 0x4326C31FBFBB3016ULL, 0x0EC60778C0ADD565ULL, 
            0x3B623169D8F15C03ULL, 0xF41BE43494C52A93ULL, 0x43A3711BAAB2B4B7ULL, 0x8BFE6F8863AA895DULL, 
            0x598EB44AC797B870ULL, 0x51372C9E95B50D37ULL, 0xD076335EB030631FULL, 0x4543E3AB2211AE00ULL, 
            0xD6DFFD629A90EED9ULL, 0xA18A2CCFB27907BBULL, 0xCF85107D1EC960FAULL, 0x0C0CA1BA78928AF8ULL, 
            0x19E7E64DE0991DE4ULL, 0xA7873EF355758977ULL, 0x49B7D9483E7875F1ULL, 0x4EDBC1992E826099ULL, 
            0x304AEB52A774955AULL, 0xC97D79DEC0762284ULL, 0x1BF73F722BC5C0E4ULL, 0x34E18F2767421046ULL
        }
    },
    {
        {
            0xF28603D220E69B74ULL, 0x8CE9D6B24C503627ULL, 0x4BCE12CCC71E36E1ULL, 0x21A818DD2240CBC0ULL, 
            0x5ADC70D705BFA9E6ULL, 0xCB2EF98CFF2F5A1DULL, 0xB0BBD6424BCD50E8ULL, 0x53B85F57D6C76ECBULL, 
            0x6A8EA175B47BA411ULL, 0xC0370A0059E3F111ULL, 0x88D83FE7438EA6BCULL, 0x5D1B14F083A92006ULL, 
            0x134F551ED609C5EBULL, 0xA5DEBB389AB4807FULL, 0xE9BA62A74A6FEC6DULL, 0xF96C2D74BAB3257AULL, 
            0x8900641A7426CF55ULL, 0xF63B6A762122C94EULL, 0xB993C2A69F2CD360ULL, 0x423C517E01DB3C43ULL, 
            0x59B6A6B1834F2C90ULL, 0xBD33864273C86E2CULL, 0x362A838BB2ACF0ECULL, 0xD7A14DA62B06F9DDULL, 
            0x177689ABBFB85FEEULL, 0x35DE6083550729FBULL, 0xDCA1B8E804E470C0ULL, 0x93A074F03982F1E5ULL, 
            0xC4608F3A0743ED2EULL, 0x1BC6309203334863ULL, 0x9350360D223614DDULL, 0x0A5EA1D8375573B1ULL
        },
        {
            0xE4A29011C2893D10ULL, 0xFFB2D5E651BC0E98ULL, 0xC583EB4A703DBF40ULL, 0x9CA1D282933E5C3EULL, 
            0x49CE0A1B09D4BCB5ULL, 0x74654A729E38090CULL, 0x635C12F87115355FULL, 0xB5FDE212F5009465ULL, 
            0xACBB14449FD4C28EULL, 0xADA79871EAE3BD6CULL, 0x466E3B2EFCDC5DCDULL, 0x9FBCCE0D2339F736ULL, 
            0x61E10DB864471E2AULL, 0x02D82A61F2848557ULL, 0x8D10498B9831650FULL, 0x93D52E2B170C5435ULL, 
            0xFC92A1739AC58E40ULL, 0xEEDE7A276F7D1017ULL, 0x223F121ABC25A38AULL, 0x140ACA7E56091E31ULL, 
            0xF349CFDF63E72ABAULL, 0x4306B17398E0F5CAULL, 0x53C5C168A70148E9ULL, 0x025B745E58A6839FULL, 
            0x80767318F1D21823ULL, 0xC5E1CD09DE78AA72ULL, 0x28DB7658E440483AULL, 0x6212F00293F15612ULL, 
            0xC0F128F9F5E2B7B4ULL, 0x691998CFC9686B2BULL, 0x4FADF233F3439310ULL, 0x109F50879C583A2EULL
        },
        {
            0x5E65F47E78FA5E0BULL, 0x5C5F3402E22B3F74ULL, 0x17F262CE7C933C6CULL, 0x44971AD6E46D9FEBULL, 
            0xD20EB9F6B450DFE9ULL, 0x9D79EAF99CAF4AFFULL, 0x41EF857E225DAF50ULL, 0xB2621BE33F3C8432ULL, 
            0x9CB030157D5B8A88ULL, 0x21EA5BA391B2DF55ULL, 0x76083C6492937D10ULL, 0x5FD1833C16D99BECULL, 
            0xE54987784CC16383ULL, 0xC33BBCF820580C88ULL, 0xD87B20BEA9D259F1ULL, 0x8AE35EAB6536AA11ULL, 
            0x20F6B27D3697F504ULL, 0x97FFD64C1B725B6EULL, 0xD847AADD76C80497ULL, 0x5F996A34C5224378ULL, 
            0xC590BE029D058299ULL, 0xA861ECB1CE12D920ULL, 0x8FEA6DA830AA5D83ULL, 0xB6138889FB065EB7ULL, 
            0x0579525EDA38005FULL, 0x6D33C21F0BE41D36ULL, 0x004F5C632A10766BULL, 0xD31ED1E09A869490ULL, 
            0xFE9E55E9A460FE65ULL, 0xF574C37B6BFB0645ULL, 0xBDAD60288082C559ULL, 0x1FE4FDBF7787DC63ULL
        },
        {
            0x0B09036724F28A3EULL, 0x93A63AF5D55EF5A7ULL, 0xA75C69B522DD813AULL, 0xC3680FA67A3EC376ULL, 
            0xA9874171AF050A33ULL, 0x631CDD395D8DF9A3ULL, 0xEB5587DF0A58826BULL, 0x81C36A30E27E237EULL, 
            0x5F0FDB0EEF6EBBADULL, 0xD61F21899C2C2384ULL, 0xA31C32A5BF14F410ULL, 0x67C8DFAFB62E02E9ULL, 
            0x2D068645FE8C873DULL, 0x0399D335D2C48C82ULL, 0xEB5CC55115B97762ULL, 0x9560E50BEF787419ULL, 
            0xF97B0059D6C06E53ULL, 0x39FB6E46F13F5CDBULL, 0x490BF6C340C63354ULL, 0xF948B2C00664C716ULL, 
            0x5CF0B1620A4D2898ULL, 0x02539E633CA675AFULL, 0x53E66EF65030EF4CULL, 0x79E62B6797F5A8B0ULL, 
            0x87B5D91523A642A8ULL, 0x788E65FA472D4047ULL, 0x0D59EFC246261E64ULL, 0x6421CD08C0D42D98ULL, 
            0xE30639765C24B368ULL, 0x3E90B2C344E5F635ULL, 0x9F5D073189F2AA57ULL, 0x14059F411299D521ULL
        },
        {
            0xA58A3F2CC62D4CBEULL, 0xC21C28999EBDE150ULL, 0x8776C35C8650A30DULL, 0x4CC31A48E7341C12ULL, 
            0xD68C1D0708F342A1ULL, 0x53C493A7D35C0F16ULL, 0xDE04A5D187A5B62BULL, 0xBD935371A277512FULL, 
            0xC6A297E6A22DAC72ULL, 0xC5757A0A6A92857DULL, 0x2148740E45FF88BFULL, 0x099CD5E7993C5C10ULL, 
            0xC906BCEA7D34E2C6ULL, 0xBD704D3C92A5A517ULL, 0x516DFC3965DC953FULL, 0xEA23BAA0269AF770ULL, 
            0x1EF0071B3E747E19ULL, 0xCC639922EDB754FEULL, 0xFD244AEE999573FDULL, 0xBE803B58274E037AULL, 
            0x800020CBF45D8983ULL, 0x53BE664DD90C4717ULL, 0xCCEE9D1FB06B7A2EULL, 0xB202AC233E59F04CULL, 
            0xB36BD9BDE61170F6ULL, 0x8F4CF93B2802850DULL, 0x2AD4FD4D2A9EFBC6ULL, 0x61BC0ACE857CC445ULL, 
            0x843887574E88DBEBULL, 0xFEBA3DB13F433067ULL, 0xE4AF450C7DFDC7D9ULL, 0xF63ED9C0885F7A04ULL
        },
        {
            0xDB035C9DCC1E2493ULL, 0x2A9C0A9408BF71C1ULL, 0xEA3D100D1FC01477ULL, 0xA37DB5BE60C12505ULL, 
            0x6EA44F59642209FEULL, 0x7DC8A91A6FC3A1B9ULL, 0x5B049AD33F53859AULL, 0xA4FCB88A59E8618FULL, 
            0xEE162D10FE334FADULL, 0x9EF828A0F7C23A8DULL, 0x9D3155E253059B7FULL, 0x8ACF025082D31F8CULL, 
            0xD012472E94BA9694ULL, 0xEC4B489324BCC42BULL, 0x5C249019696DFA22ULL, 0x7AEE321B328FB399ULL, 
            0x95B3B4A729751909ULL, 0xDD1F06B2BCFAE9B6ULL, 0xC710826991CDCD0DULL, 0xB2C02749CFAF1DE1ULL, 
            0x04D49D73C0D7AF93ULL, 0xB2ABB918CB97F9C2ULL, 0x4281AC1A2B28A6CCULL, 0x360B979B5616B42BULL, 
            0xC41CE573A5A7B7B6ULL, 0x29D5293CF5B0919CULL, 0xFD8A0FC7EB9F3D68ULL, 0x59D42347DC9DF3C2ULL, 
            0xA0DFB84EB0C858F5ULL, 0x16056B52E82F375FULL, 0xFF7F6F0BF65D90ACULL, 0xF29913F3A3DCA584ULL
        }
    },
    {
        {
            0xEFEA98ED3F913A66ULL, 0xF5C47443AD67055DULL, 0x0C57D8C8A608D6ADULL, 0x755EFE64A1A2E7F4ULL, 
            0x6EAE048484D87593ULL, 0x932DBCD1C0CC6DA3ULL, 0x89614A9C732B05C9ULL, 0x161672977A6E6352ULL, 
            0xCB5383E83AF35C3DULL, 0x1FEB0FB3136A18D7ULL, 0x4504C235FD5EE175ULL, 0x91900EDD963D4E30ULL, 
            0x08AA3B99148D569CULL, 0x88C102EFBCCBDE7BULL, 0x935F78916891682FULL, 0xC3116D18DB15406BULL, 
            0xED70B43EE1568D4DULL, 0x1B284FB8CF4917DDULL, 0x66440CE32770AA5BULL, 0xD50E78A62AEAB77AULL, 
            0xC6375E2AAEDB063FULL, 0x1DBE04D70B724838ULL, 0x472BEA62E6BC8825ULL, 0x4E8DAE61D03FC37FULL, 
            0x485DE28EC1D4FAE1ULL, 0x97B0AF0E493D92F6ULL, 0xA7216E0DF1D3FC73ULL, 0xECAD7531322B55AEULL, 
            0xE4DB6330C26F555CULL, 0x1F08449F27441E28ULL, 0x80BB9BD2A59C46C3ULL, 0x21A66D72B85EA19EULL
        },
        {
            0xAE71587AF12E3EDBULL, 0xC1BA64D333C11189ULL, 0x4AFDE723A252C876ULL, 0xC7ED96664BCFC785ULL, 
            0x0F60D203F038F621ULL, 0x0A5260FD8810E776ULL, 0x1F6219D963B26892ULL, 0xD51F1F957E21DD86ULL, 
            0xB7512E3D8F676C5BULL, 0x2F8FB554644B5D99ULL, 0x864B66E448373A8FULL, 0x062D02D00E9173DEULL, 
            0x257EC54B69D0C898ULL, 0x23878915A1895691ULL, 0x5B4CBFE96FC6BF45ULL, 0xF27264DE7FBA7CD9ULL, 
            0x59742CB87D765ACEULL, 0x2A2ED36CADBAA51DULL, 0xF5994120CCC1CBC8ULL, 0x25586893F2B630A4ULL, 
            0x5CA5A90ECE3EE844ULL, 0xB5A01991A1C22CF5ULL, 0xBD21DA135E6EEB15ULL, 0xC06248AF42440B9CULL, 
            0xB76CB4253AD7D638ULL, 0xECEB6587DA126C3DULL, 0xF6695AB0067ACEC0ULL, 0xC047BF89CFDFE872ULL, 
            0x06AEFBA46C5F3FF7ULL, 0xF2A0018EF86C9DEEULL, 0x18757C5B080C6AB1ULL, 0xF3468A09CB0DDDC9ULL
        },
        {
            0xC40AC0BEF9387EADULL, 0x363C58BBFD343E76ULL, 0x01914AA7C9CF627EULL, 0x3F32EF76382F729BULL, 
            0xFA1584307F402DD9ULL, 0x1BC9DD0858E45A29ULL, 0xB800F6F519A4C1C2ULL, 0xC5F1A1FFC9881C3BULL, 
            0x2AE946C1CF9DA176ULL, 0xFDB49435FD4D5E2AULL, 0xEF94B60A0175FCACULL, 0x3D21D27F786BC450ULL, 
            0xD9B2C929AEAA2B77ULL, 0x6DAF934454D035BAULL, 0xB25C6B0E7D0AA5EEULL, 0x474D635200951A61ULL, 
            0x74F429516C8F621EULL, 0x97FFE39EC38CD23AULL, 0x389001B947366C9BULL, 0x93BA49B0344FDE55ULL, 
            0x8F761AE5CFA191FFULL, 0x15B83EED905EAB09ULL, 0xD8C73EF1D706B158ULL, 0x3C4643D1BC74D111ULL, 
            0x210FA36DA52F1854ULL, 0xD737D78949F511A8ULL, 0x1E0AF840576E4C5EULL, 0xB8969281FE879524ULL, 
            0x2CD1B9A364EDBE3DULL, 0x7BD63B0EBC319882ULL, 0x6B96F475DF95CCC6ULL, 0x1349055D9C89C242ULL
        },
        {
            0x1841F28F06AE3D3BULL, 0x94644A83580D6478ULL, 0x00346E9F5F92CE53ULL, 0x9213444DB8604D1BULL, 
            0x2EED38F6BE11A89EULL, 0x14ECAD07968F01A4ULL, 0x1D38A7FAF5A1C05CULL, 0xC5F6A8F106159FA0ULL, 
            0xA4A6A39266458202ULL, 0x4A2D5552C0ABC8C7ULL, 0x66EE3338DA956D82ULL, 0x29B5F7106E7F6FEAULL, 
            0x9C8443C9FBA5ACBBULL, 0xBE2FA2AE4DDBF7D0ULL, 0x78368CBF5BE9937EULL, 0xC53F3235209992A8ULL, 
            0x5DBA7F4449E35A49ULL, 0x974FADCE61E01F79ULL, 0x1268421BFBBC5B97ULL, 0xEB8F9DF08FEF9C16ULL, 
            0x8E9D0EF62C98F7A2ULL, 0xF1C9F37FE18E6115ULL, 0xD1622D81D7060195ULL, 0xF1D3BA5F5A2ABAD8ULL, 
            0xA43F486293A78804ULL, 0xEF52122122D92A3EULL, 0x6B047E8AAD236DEDULL, 0x5CDC262816B82D51ULL, 
            0xB60667A569C497ECULL, 0xF6630AB745AE474DULL, 0xB0D50025BA5D8798ULL, 0xE77BE33EA337B354ULL
        },
        {
            0x919BF7EFD5992589ULL, 0x53ED0D2B83DE2810ULL, 0x5EF8C441E4F1D661ULL, 0x6476D178CA0A8C6EULL, 
            0x6B271C131A81CF4AULL, 0xF9E64C16E95BC536ULL, 0xD7D92BD5CF68E982ULL, 0x9603E66BA32063BBULL, 
            0x8C98E892F3F33B12ULL, 0x509131B8FDCCD5FDULL, 0xA698D719CBB1108FULL, 0x645941CBB3DC0E7CULL, 
            0xBDCA92A7EBC0A61FULL, 0x98088C3FA17C7D5DULL, 0x09D97C4C743F084AULL, 0xDE5637DB611E1D6BULL, 
            0x8A683D058CF541FEULL, 0xC2B3F87D53BC2065ULL, 0x7C396D36C3B7A400ULL, 0x81A31E34CB044834ULL, 
            0x9289D3077D56D013ULL, 0x29E00E301EB9F7D5ULL, 0xD3438AB0E566FA7DULL, 0x8889948AFD290B1EULL, 
            0x0039F8EC9C7BE5FCULL, 0xF65ADFD92B397E64ULL, 0xA10B61D039B2791DULL, 0x99DE1FE4F2548FE4ULL, 
            0xCD4F18812A3E7742ULL, 0x7E1C36DA18439404ULL, 0x6D5E76184C212B78ULL, 0xDF01E313BCE6E359ULL
        },
        {
            0xC95EC2B97E27DAD6ULL, 0x5F035B42FCB841ECULL, 0x6FAFE4B92CA17293ULL, 0xD8ABE1074B6F6D83ULL, 
            0xF0CFF8B8FF1904C9ULL, 0x06A9CAA5B13BCD4EULL, 0x5E5636BCE496B9F7ULL, 0x3B077CCA5C47944BULL, 
            0xFE6A7107843F7C90ULL, 0x428D8FADC004B570ULL, 0x92CE57AA2F9C7B84ULL, 0x165489AEFA941DDAULL, 
            0xC8332E9369B87B2AULL, 0x2622DB3007B4DA67ULL, 0xC56C12BF3D162E8FULL, 0x21CA62C980ECEC6FULL, 
            0x76FF40579BA7CD59ULL, 0x866ECB2928000552ULL, 0x6F9AAFD1F04AC71BULL, 0x7CF71D9C1F2095DDULL, 
            0x67063ADA538A9B3EULL, 0x03180A505EE50D41ULL, 0x09891E65ABAB0DA3ULL, 0x0493CA074E90F29FULL, 
            0x95BAE9D99B06C7D0ULL, 0x70CDE82E5FEACB9CULL, 0x3F72FFBA5B6A3603ULL, 0x65543B00F6C0DCC6ULL, 
            0x79174DD0455D970CULL, 0x1A30A2DB769508A4ULL, 0xF28FB02B31103F95ULL, 0x9C0C0B6C1D1A2E5AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kTwistConstants = {
    0xE9EB67E684461512ULL,
    0xC7552AF99A2A9173ULL,
    0x8741458CC33C2E76ULL,
    0xE9EB67E684461512ULL,
    0xC7552AF99A2A9173ULL,
    0x8741458CC33C2E76ULL,
    0x5B1F756A2FD830D2ULL,
    0x9045A67D720E997FULL,
    0x1E,
    0x6A,
    0xDB,
    0x98,
    0x05,
    0x3D,
    0xF4,
    0x27
};

