#include "TwistExpander_Suhail.hpp"
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

TwistExpander_Suhail::TwistExpander_Suhail()
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

void TwistExpander_Suhail::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD7C906CB8F993E17ULL; std::uint64_t aIngress = 0xA3E56D17B5A1C194ULL; std::uint64_t aCarry = 0xE7F128A00436CFC0ULL;

    std::uint64_t aWandererA = 0xBD66A0A8B73BC47EULL; std::uint64_t aWandererB = 0x9CD24CEC29D6B89EULL; std::uint64_t aWandererC = 0x8212CC67640625C5ULL; std::uint64_t aWandererD = 0xCAFF363AC0E3BAC8ULL;
    std::uint64_t aWandererE = 0xC33D3235B578EAF7ULL; std::uint64_t aWandererF = 0x8C7F1471978045B0ULL; std::uint64_t aWandererG = 0xD67386897336D152ULL; std::uint64_t aWandererH = 0xCC5E2DB5040353ABULL;
    std::uint64_t aWandererI = 0xDB137C60070A82ACULL; std::uint64_t aWandererJ = 0xEB293BD76C8F0549ULL; std::uint64_t aWandererK = 0xDAF60EBEFD4ABA4BULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDF4CAA2CCD5C7C65ULL;
        aCarry = 0xBF2B4F9520B75290ULL;
        aWandererA = 0x95C1DE49AF3F9631ULL;
        aWandererB = 0xC5ED55B5D5567A0AULL;
        aWandererC = 0xE6A84C6D5BFC1DDAULL;
        aWandererD = 0x9B6D46A8740C8C41ULL;
        aWandererE = 0xC922DAAC963D000EULL;
        aWandererF = 0xD86E67C550DDA954ULL;
        aWandererG = 0xE51516127ECBDBD4ULL;
        aWandererH = 0xE104B90D2653E3F7ULL;
        aWandererI = 0xD4ED728001CAF1D8ULL;
        aWandererJ = 0xDC7274138878A067ULL;
        aWandererK = 0xBA5B9024798CB029ULL;
    TwistExpander_Suhail_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB187F7E825D741DFULL; std::uint64_t aIngress = 0x8678FD036D07A6FDULL; std::uint64_t aCarry = 0xE0B68B3E53CFB88EULL;

    std::uint64_t aWandererA = 0xA5E6FA8C9504885AULL; std::uint64_t aWandererB = 0x9F2F63C064CF7841ULL; std::uint64_t aWandererC = 0xB9E0919B4083DD8CULL; std::uint64_t aWandererD = 0xD79D44EB670A415CULL;
    std::uint64_t aWandererE = 0xE92AECE177A81A49ULL; std::uint64_t aWandererF = 0x8C904FC6E2AD0B01ULL; std::uint64_t aWandererG = 0xC37C82A84DADEBD1ULL; std::uint64_t aWandererH = 0xED84C1E2A1F5CEF7ULL;
    std::uint64_t aWandererI = 0xEB7DDB6D1BA3B13EULL; std::uint64_t aWandererJ = 0x8544EE98A73FA58EULL; std::uint64_t aWandererK = 0x9858B3367030264DULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB6056ED331604F0FULL;
        aCarry = 0xB463D5A809BA4E37ULL;
        aWandererA = 0xC57CD1A23BD0BB66ULL;
        aWandererB = 0x9E7BBE72238D300BULL;
        aWandererC = 0x94CA4CF7F5F5B94AULL;
        aWandererD = 0x9F02FE060B578FC4ULL;
        aWandererE = 0xFA4020F7609F96F1ULL;
        aWandererF = 0x858FE175501715EEULL;
        aWandererG = 0xBD022F8429F5BF99ULL;
        aWandererH = 0xBED18E8A3CD3D022ULL;
        aWandererI = 0xAF84CCA13C3A1832ULL;
        aWandererJ = 0x9B5AB452EBDC678DULL;
        aWandererK = 0x9199942D8CA40B5CULL;
    TwistExpander_Suhail_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9483BD5FE9475330ULL; std::uint64_t aIngress = 0xBAE1ADA9D551E9D1ULL; std::uint64_t aCarry = 0xA2D202C06F980263ULL;

    std::uint64_t aWandererA = 0xDFA642D9C221A946ULL; std::uint64_t aWandererB = 0x9ADF158D4DB04D60ULL; std::uint64_t aWandererC = 0xA2C0D00CBF6D6F81ULL; std::uint64_t aWandererD = 0xE5652D2B97435947ULL;
    std::uint64_t aWandererE = 0x8512F547274A9F7BULL; std::uint64_t aWandererF = 0xFFC8EC302B6734B8ULL; std::uint64_t aWandererG = 0xFDDCD071092D4094ULL; std::uint64_t aWandererH = 0x8EBD5BD6C453050DULL;
    std::uint64_t aWandererI = 0xAFADBA0E97D13DF5ULL; std::uint64_t aWandererJ = 0xDDB6485DBF74F17EULL; std::uint64_t aWandererK = 0xDD50033A32ABEEEFULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFBD78F1E8FC7049FULL;
        aCarry = 0x86D24E0B3F03C78FULL;
        aWandererA = 0xB3715F5A38CE85ABULL;
        aWandererB = 0xD31544260B61F124ULL;
        aWandererC = 0xF9F0E807571B7395ULL;
        aWandererD = 0xDE6D0856E0911096ULL;
        aWandererE = 0xC8B2694F55D3DCC4ULL;
        aWandererF = 0x81CDD7C0DE6D2028ULL;
        aWandererG = 0xF13AFB22DF6BBF56ULL;
        aWandererH = 0xAA54AD163073BA1EULL;
        aWandererI = 0xA006EB86ABC7E4D1ULL;
        aWandererJ = 0xB87FBDF7D7E75BAEULL;
        aWandererK = 0xE6BBEA171C9BF139ULL;
    TwistExpander_Suhail_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB17333B1E3AF453EULL; std::uint64_t aIngress = 0xFD28F32720581AA5ULL; std::uint64_t aCarry = 0xFF323B3AD2445D38ULL;

    std::uint64_t aWandererA = 0xC5366866F421ECCAULL; std::uint64_t aWandererB = 0xAF98D9E168331D06ULL; std::uint64_t aWandererC = 0xC29117A8028EFBCAULL; std::uint64_t aWandererD = 0xF24ADED27B79DE99ULL;
    std::uint64_t aWandererE = 0xAD68E91C0B077D20ULL; std::uint64_t aWandererF = 0xF0364607AE86E59FULL; std::uint64_t aWandererG = 0xA6164FE9D1A67627ULL; std::uint64_t aWandererH = 0xE5C0555AC388F0F9ULL;
    std::uint64_t aWandererI = 0xECC11EAAB8CC1F8FULL; std::uint64_t aWandererJ = 0xFAA3B9951D482530ULL; std::uint64_t aWandererK = 0xDD9AA3B3CE146B42ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB22B934CFA681065ULL;
        aCarry = 0x960E3E72E400A2F2ULL;
        aWandererA = 0xC2D9ED99A3AE7B5CULL;
        aWandererB = 0xE63A0AE6DBEC7C5BULL;
        aWandererC = 0xB72ED4AA51C7E8F9ULL;
        aWandererD = 0xA73BFE7C3D96568EULL;
        aWandererE = 0x82305CE0122A5D23ULL;
        aWandererF = 0xC46D9C6CDB9FE911ULL;
        aWandererG = 0xC4CE479A4E4305CFULL;
        aWandererH = 0x83554B3039D84868ULL;
        aWandererI = 0xCC207AB9CD6965CBULL;
        aWandererJ = 0xDCD46FE08AC624BAULL;
        aWandererK = 0x9EE777408CD8D094ULL;
    TwistExpander_Suhail_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Suhail::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE3C45BF1903AB53DULL;
    std::uint64_t aIngress = 0xFE0B7B7C391E2267ULL;
    std::uint64_t aCarry = 0x83F31DFAD3A3BB15ULL;

    std::uint64_t aWandererA = 0xE50CA95A9381E132ULL;
    std::uint64_t aWandererB = 0x9B07780305B17D4EULL;
    std::uint64_t aWandererC = 0x97B426E2DF6D5EC8ULL;
    std::uint64_t aWandererD = 0xD9F6C431FFE485EEULL;
    std::uint64_t aWandererE = 0xE7CE8ABE21552CC4ULL;
    std::uint64_t aWandererF = 0xAB8408080DAD7F60ULL;
    std::uint64_t aWandererG = 0xBD8B170123A5404CULL;
    std::uint64_t aWandererH = 0xFDD9DC596371FD8DULL;
    std::uint64_t aWandererI = 0xB51E0133EEDE6A8AULL;
    std::uint64_t aWandererJ = 0xA2B6B9B8CE62E7AAULL;
    std::uint64_t aWandererK = 0x9739F1DBF68D5088ULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    TwistExpander_Suhail_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KEY(pWorkSpace,
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

void TwistExpander_Suhail::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC21079152A39671CULL; std::uint64_t aIngress = 0xD2B62A85E7D0DA7AULL; std::uint64_t aCarry = 0xFF0991667EF47C4AULL;

    std::uint64_t aWandererA = 0xC5AA1EB0A14B6C43ULL; std::uint64_t aWandererB = 0xBAD8DC9F2C8B64A7ULL; std::uint64_t aWandererC = 0xE5F97EDCB3E482E2ULL; std::uint64_t aWandererD = 0xB2FCF4626EAC3661ULL;
    std::uint64_t aWandererE = 0xA1EA0BB28ED7E073ULL; std::uint64_t aWandererF = 0x8B69E42D2085EF60ULL; std::uint64_t aWandererG = 0xA09256390A521013ULL; std::uint64_t aWandererH = 0xE0F31501F577967BULL;
    std::uint64_t aWandererI = 0x9AE86E57B95240ECULL; std::uint64_t aWandererJ = 0x82C4C19F3027F5F0ULL; std::uint64_t aWandererK = 0x8FBCFB81508B393AULL;

    // [twist]
        aPrevious = 0x974303D8D312BB35ULL;
        aCarry = 0xE03904023C4D42A7ULL;
        aWandererA = 0xBC45925580411BF6ULL;
        aWandererB = 0x8517EF982884C0BAULL;
        aWandererC = 0xE86CBB4373837002ULL;
        aWandererD = 0xB8E3442C4990FF84ULL;
        aWandererE = 0xC441A5FACD55CDCCULL;
        aWandererF = 0xDEBE9BF8D9237FC7ULL;
        aWandererG = 0xF047A8143E431EBDULL;
        aWandererH = 0xE37AA1E105013836ULL;
        aWandererI = 0xCE03142FB84CE98FULL;
        aWandererJ = 0xA6E09EFE6EA1EAFCULL;
        aWandererK = 0xA1793FC776C24EF0ULL;
    TwistExpander_Suhail_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Suhail::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Suhail::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Suhail::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 32 of 33
    // Exploration cases: 0
    // Structural maximin 501 / 674; family total 16548
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 32 of 33
    // Exploration cases: 0
    // Structural maximin 503 / 674; family total 16554
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 520U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 32 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1042 / 1248; total 33396
void TwistExpander_Suhail::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 295U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 32 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1044 / 1248; total 33254
void TwistExpander_Suhail::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
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
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Suhail::kKeyRotateSalts = {
    {
        {
            0xA29CFF4549CE51E5ULL, 0x1822965763E1CE94ULL, 0x436D6A670C023C1DULL, 0x194325FE055B9408ULL, 
            0x76A92C4E6E3F936CULL, 0xC876DE16A56D873FULL, 0xB61F11914CCCCDC0ULL, 0x55A8479F9C90C593ULL, 
            0x98B9943B94C750BBULL, 0x72FBE6346255A611ULL, 0xFD590F13D885DD88ULL, 0xBE62952FDBEEFB3CULL, 
            0xFE1EB915F999B812ULL, 0x571EB5CC286F85C7ULL, 0xB2BF22BB82085528ULL, 0x529F2C3C3E12BEFFULL, 
            0x857C544E723D8376ULL, 0x71B96DAEEABB2CEDULL, 0x5B022C95C3F469C4ULL, 0x31E109EE9B5D32E6ULL, 
            0xD7DBE88E86F55217ULL, 0x16FE864A493824BCULL, 0x9278491DE55FC2AAULL, 0xF4F66E6C32842FA5ULL, 
            0xF2AAAAC98B65396BULL, 0x1D452219BD668796ULL, 0x1E8C99911BF0C3FAULL, 0x02AE668FFEB57D9EULL, 
            0x52688FC3E0247AACULL, 0xC3CAADD8B6C1D4DAULL, 0x53E9B07A1985E0D8ULL, 0x40685FD86CC6F616ULL
        },
        {
            0xF5EB46D2987E8674ULL, 0x220A9BC125CD4EA9ULL, 0x836260177DDD458BULL, 0xC619B849CF6AFBEAULL, 
            0xE50C85B541D1156CULL, 0xF26A8FFF1C64E70EULL, 0x07461F0C1EBD8767ULL, 0x3E6B511D0CD0F4FFULL, 
            0x7C52602EB3D5F238ULL, 0xB529C4D23CC05ED6ULL, 0x0120C011D5DE4C0CULL, 0x1160FB3BD8B480B7ULL, 
            0x493272C526C6A1FFULL, 0x68641E8505981832ULL, 0x82B960F7998DCDD0ULL, 0x74EBBF263EA251F9ULL, 
            0xA07E9F2E0527CDC7ULL, 0x2E2462194D813FD9ULL, 0x2399E6A411FB0C46ULL, 0x4C5D844BC5DDDD72ULL, 
            0xD69A4B9C7D7C6163ULL, 0x989BE4594A215AFCULL, 0xC0D647406679B02DULL, 0x4A416128EF7309A8ULL, 
            0x928A51DA28C3EA2DULL, 0xEAE18A4B567107BAULL, 0x2722D8D64BB9CA70ULL, 0x47A2B0ABE2A5A2B3ULL, 
            0xD65B9C3B79BAA479ULL, 0xA3976D23C0C254AEULL, 0x2785EBBE1C9C0B75ULL, 0x171B83FF17A25C80ULL
        },
        {
            0xF13D5B873A27EAE5ULL, 0xCA5659C1C83A8CDCULL, 0x3DCEFADC4C0E83CEULL, 0x139AFEB934A73DFDULL, 
            0x145DFED2D91A5A6FULL, 0xC0BC5DC966ACACE0ULL, 0xF4CB3850BD7647BEULL, 0x749226A05D308A71ULL, 
            0xCA2025EE462ED3CBULL, 0x55D117DA2C93E06EULL, 0x8393F61810984932ULL, 0xCF533FD629BA0D60ULL, 
            0x55F02628ABE3222BULL, 0xB083F1D71B6F696DULL, 0x3FBE6963AF50ECCEULL, 0xAC651362981A0D82ULL, 
            0xAB59BA7946FD2FE0ULL, 0xE18641B10A3AAD81ULL, 0xF6B08097FA1848BBULL, 0xA44983434A7FD1FDULL, 
            0x81C476D746E88FE0ULL, 0x2FE4253CCCF83778ULL, 0xA58731912AEF1964ULL, 0xA851410DD58BE59FULL, 
            0x09D5C150580141AFULL, 0xB46C39F38F503053ULL, 0x68CB4BFD167FB0DBULL, 0x80F5A7C96609D869ULL, 
            0x93990B1440A82C3CULL, 0xC2C72BB359908A10ULL, 0x643761BC2B239555ULL, 0xE4408CF0657CFB4DULL
        },
        {
            0xB3E3B5A3B32CAFD6ULL, 0xD706090BCF0063E9ULL, 0x9C99D24151701560ULL, 0x60BFFBEE58E52967ULL, 
            0x7AE1B5E0163F75E7ULL, 0x058FF80101560407ULL, 0x4885184DC68B036FULL, 0x6AA70A37D7BB89B8ULL, 
            0x08E1B486FEC1A496ULL, 0x0B10F857C91F96DEULL, 0xC233E8976870FED6ULL, 0xE48A7CB1C09F6830ULL, 
            0xA1CBDB0A13E98060ULL, 0xC82396B7C4546820ULL, 0xD445F767D1739B8BULL, 0xEEFEBA86C3988E2CULL, 
            0x7F0B5A24E03240F3ULL, 0xCD82560ABFA54092ULL, 0x0601B2EA9A78D39AULL, 0x29D83C7FE6DD0FF6ULL, 
            0xEE8468D352A17751ULL, 0x91F6012DE49BCF44ULL, 0xAC6862BD204B63B3ULL, 0x413465DA08E5C77EULL, 
            0x1AA98B0DFAF4F09DULL, 0xE48D60C26E825EF3ULL, 0x532C01B0C9C09F3FULL, 0x0BD3C61A88EF3970ULL, 
            0x2467178DA42DE39DULL, 0x381B3A7F73A4056DULL, 0x09086BEC5D5ABC90ULL, 0x5BB13DF78D3AFDFDULL
        },
        {
            0x79ACD56003AD4B57ULL, 0xF3DC6FE0BE0B1097ULL, 0x524FFA1C44236366ULL, 0x7A9FF09CD02949B2ULL, 
            0x71B963416424BC69ULL, 0x96BC1D8094C5BDA5ULL, 0xA883750D6B8BE5C9ULL, 0xA2DA1D67582BB5BCULL, 
            0xA2F18B6CF8BC332EULL, 0x0A7E306A4AA26EFDULL, 0x833DA6CE2A38AC6FULL, 0x829FA84393FE5F83ULL, 
            0x78ACF79AA6BBFC7DULL, 0x9ACFB04441C3AC37ULL, 0xEEAE7BB1C699F570ULL, 0x4FB0F9826A3B4636ULL, 
            0x71710028C68E9348ULL, 0xB507577450DE3A99ULL, 0x8979A75EF369B43BULL, 0x74F042038C1FD3CEULL, 
            0xAA94B0F7789A5525ULL, 0x4A656B16D52AC998ULL, 0xB68011E86C8BC02FULL, 0x7E06E22D2D2E09B4ULL, 
            0xED2BE421903A75AFULL, 0x4B893E16701A451DULL, 0xD995BFAC9565EF33ULL, 0x4B59982F6FA2DC0EULL, 
            0x80E41829F90CEF76ULL, 0x6E85EFD970F29072ULL, 0x1B9C3237664E3469ULL, 0xE15A4DC66D3A0FADULL
        },
        {
            0x1C278DF9633C6F46ULL, 0x95EE7276B318A9EAULL, 0x9B99451911A9AEE4ULL, 0xE727F6A93099CCA8ULL, 
            0x1AF6B8529A729FE9ULL, 0xD52B534825C70FB7ULL, 0x0F1FFFB157146D98ULL, 0xA4F607B24C6CABDEULL, 
            0xA6B1858FAA1DB5C5ULL, 0x8A71CD801D10125FULL, 0x6569157F9C672AA6ULL, 0xE938D053CCEC13FEULL, 
            0xD73DBD19B1F0D9E7ULL, 0x6115EE42C05F803BULL, 0x920B2E94B986209EULL, 0xCD156D197C46D853ULL, 
            0x0A04F9CAC02208A4ULL, 0xDDC39B4911776481ULL, 0xD626D062A9DA650FULL, 0x52E5F421D3F76947ULL, 
            0xDAE3A435242EB645ULL, 0x69FEAA616EF2EC11ULL, 0x8DB6F4ADD5474A0AULL, 0x02EBFB82B7A07915ULL, 
            0xA2BE3FA984DB4D2BULL, 0x8E4C2474D07199D7ULL, 0xE94386AC8CBBB0D6ULL, 0x5411BD423D834026ULL, 
            0xB963727477AC1D58ULL, 0xBB80191D116ACBF8ULL, 0x7320AACBD0059C40ULL, 0x460A1C3C645B9E72ULL
        }
    },
    {
        {
            0xCB11C33B88E30CE4ULL, 0x9731C9C99583BE3CULL, 0x1E8D26EE6BBC22EDULL, 0x0EF3AEE0244ABB2DULL, 
            0x6E5A2C40A4B62D36ULL, 0x2F25775505989D83ULL, 0x0B8F09A4FEE589FFULL, 0xF02FE4579C4ED473ULL, 
            0x1627AED7A8DE9E5CULL, 0xB732C7DD11FCC7EDULL, 0xCE068FC216FB1F7CULL, 0x050FD0B07AAA596DULL, 
            0x7AA12C341A465C8BULL, 0x3B855A40DB0A7716ULL, 0x22A083AAFC58FCE4ULL, 0xCBAB1A892ABC5302ULL, 
            0x52A9468A115FAF9FULL, 0x3D58A971CB369FDDULL, 0x93AF2513799657B2ULL, 0xB1DCA760CD813315ULL, 
            0xFD41831B4DE88C8BULL, 0xEC1D3A3AE23ABFFAULL, 0x7A6CF1D339351CC3ULL, 0xC9F94F8FD436CC61ULL, 
            0x1ABA7C33B1D41008ULL, 0xC932CFEC3B92A0FAULL, 0xA2C4C25D7A6CBDB0ULL, 0xF2F40DE6A34B0B47ULL, 
            0xF68072610BD797B0ULL, 0xF8E7F2935E5090E4ULL, 0xE4864052B05D41BDULL, 0x0B5EE915A92D2758ULL
        },
        {
            0x1E629BB202534F07ULL, 0x4244A9E733DD9AFAULL, 0x7AE30F9495094E12ULL, 0xE36718219D5D2FD2ULL, 
            0xD37E0EF384D90BFFULL, 0xE9A09D100EA675EDULL, 0xAD81220D2DC03F13ULL, 0x5B79211455CC2C0FULL, 
            0x214D459A1CAF6E5BULL, 0xCF39A3576F7F0C30ULL, 0xB23537FA5AFA3D4FULL, 0x04E7448D81C8C198ULL, 
            0xA76F08E7474FE3CDULL, 0xCD6E71D0D7F55BE7ULL, 0x0C252BEE80523B96ULL, 0x6587D699DFEB4BD2ULL, 
            0x586EC2D399B6B069ULL, 0xF43DB2EDAB40111DULL, 0x20AF575E3834CBD1ULL, 0x493314DFAE0C14C0ULL, 
            0xB62063EA12E3015AULL, 0x6A4CDBB1171FC86FULL, 0x32B3DEEDC652BFE3ULL, 0x730011D18B2D033FULL, 
            0x5B84F12444D62966ULL, 0xB3F0DB66BEE7136BULL, 0xD79494F0C7D28D07ULL, 0x65E4F9244624EC4BULL, 
            0x0A7BBF81CBCCB200ULL, 0x55508C1477536FDFULL, 0x828F9CE3B0265361ULL, 0xCFB228525C9E9823ULL
        },
        {
            0xF00F0F4334D76F84ULL, 0x1AE835D7876D100BULL, 0xCCC38F8E40C43D8EULL, 0x1E69935E2FD3C725ULL, 
            0x64FE023F16A4C754ULL, 0x3A8D6509EA907CE0ULL, 0xCE88DF17BAABCF4CULL, 0x8A025D2F2C28BE7EULL, 
            0xA86D9A76DE12884FULL, 0xA46FD36002C5A6D0ULL, 0xBE3087DDDB1B749FULL, 0xB3F6C8D64EADD777ULL, 
            0xB98E80E9E03F158DULL, 0xF32112BE700AEB6DULL, 0x043CFA0573B73FA1ULL, 0x7F9D6802F5003C02ULL, 
            0xD0BD888FB8500095ULL, 0x11E7BE8A26FD39A6ULL, 0x02382BE40A1A9929ULL, 0x50B617EAE193D70AULL, 
            0xD21E2198B1E75B3EULL, 0xA061C804D8410F98ULL, 0x75AB1B660C863AE0ULL, 0x3CE7D1131AF4F448ULL, 
            0xD9392AE63625B92BULL, 0xD91A0B18153C66E4ULL, 0xFEBAB6CF80116369ULL, 0x4DF5ACABF312FFC6ULL, 
            0x1EA34AE5B0D9C7A0ULL, 0x45221A041C075F85ULL, 0x83BAFEF23FC119F3ULL, 0x63FD75DB443E1150ULL
        },
        {
            0x76594510DCE9C216ULL, 0xA6F7BD0C58B5E689ULL, 0x243E330224ED1C8BULL, 0x217235C928CE5060ULL, 
            0xC7E7121F09D0F5F4ULL, 0x8A0BC79CCB920AF5ULL, 0x3018EA317BEE69BEULL, 0x97D0CAC0F7ACAFF6ULL, 
            0x834C4EC228A099C3ULL, 0x551ECABCAB3D6778ULL, 0x2434F51406ADE820ULL, 0x362105ECC3EF475AULL, 
            0x8BB4007780842154ULL, 0x8A920EF5D85931DFULL, 0xA50182131904F5FBULL, 0x6C8D2CDF1EA92BECULL, 
            0xEAA8BFA4CB70123AULL, 0x782AFE323C758764ULL, 0xBB9443733F8373AAULL, 0x9AA0A9C022384C7CULL, 
            0x4A36F408630AF53EULL, 0xBE0D7B27A6A0CA0FULL, 0xAC6A10B5C33736C4ULL, 0xDA59D2EC08296090ULL, 
            0x3BECFBFC11804699ULL, 0x46DAD014F15ABA6EULL, 0xE4AD942362B2572AULL, 0xC7353600C2073746ULL, 
            0xD1660712F63840D7ULL, 0xADFC35837765DF3FULL, 0x7A12BCC1E2F707F8ULL, 0x29B82333308E7513ULL
        },
        {
            0x4C3924DAF18051B2ULL, 0x508A3F416E68E351ULL, 0x9824B6C81971D863ULL, 0x7F532FEB55EA1729ULL, 
            0xE4B7A06C51AAE27CULL, 0x5FADF6CBA0DF64EEULL, 0x4842108E00BA8BB6ULL, 0xA720D217FE770ACFULL, 
            0x918DF6601FD2D38EULL, 0xDD44066535D0C974ULL, 0x5E37B0C5C967005AULL, 0x4CDCA4C253FEFF02ULL, 
            0x8D24F8428D4DB7F3ULL, 0x0A524651AE4931A6ULL, 0xC919F1E24C0033C6ULL, 0x2237ABC1BA32387EULL, 
            0x8EB3D8512B95FE6FULL, 0xE7B95532007CE701ULL, 0x2CEF41449457AD24ULL, 0x365436C280020FFAULL, 
            0xFED4A476C6BF1B70ULL, 0x7E420605838A4E60ULL, 0x285A02558378C1E1ULL, 0xA013B653E86BF76CULL, 
            0xDF6776C4F84491C6ULL, 0x79A850238534A259ULL, 0x8B5A4ED7DC186497ULL, 0x17147EBD9D6391FFULL, 
            0x946AD3FC3703A034ULL, 0x551DAAA35B33A481ULL, 0xD09CA2A7310147E4ULL, 0x049D99634944C7FEULL
        },
        {
            0xB06181E8F27897A6ULL, 0xD4F3E5F4D3D0A554ULL, 0x25F8DB848D02475DULL, 0x56972A38E20974D7ULL, 
            0xFAA7BBD43C4AAE31ULL, 0xDF43571045DDDA0CULL, 0xD12EFE6382FA07F8ULL, 0x792CA3EC163A6D13ULL, 
            0x290CEBDA10A967C1ULL, 0x263F1FC75E7C45C1ULL, 0x0FFC8E96D1FE300CULL, 0x4F995E04CD0AF5D2ULL, 
            0xDB97A3291681D029ULL, 0x313FF1B1F316A2D8ULL, 0xB93169911696784BULL, 0x3682313749431544ULL, 
            0x8164084AD3045871ULL, 0x8171C802E6C3AFC5ULL, 0xD7709F004A8FAC5AULL, 0x8D9D86CED5FC5844ULL, 
            0xCC8C571B82D5447CULL, 0x0F61D2266F3120BDULL, 0xD7C7874730E01990ULL, 0x2077E183FDEA6282ULL, 
            0xBD16194240DD33ACULL, 0xE6B1CE1BA903973CULL, 0xB99EFAD1DD755F2CULL, 0x5CEFEDD54B018CBCULL, 
            0x8ABB385BC12E23B3ULL, 0xC737F5A6D6E142DAULL, 0xCB39715C360DF1C4ULL, 0x7940015A60520F0EULL
        }
    },
    {
        {
            0xC6DD5AD63D774244ULL, 0x147160FEFD4492BCULL, 0x60CA23EC9E677F4BULL, 0x75CC4591744F5EF9ULL, 
            0x26260EEF4AA37CB9ULL, 0x29830EFD880B7F80ULL, 0xDD14426F112FCFCFULL, 0xC068A3C9A0344BA3ULL, 
            0x0F8B08293C1673E4ULL, 0xAAB00DAE49989325ULL, 0xF715B8C1DA6ED348ULL, 0x0319AB2CC3CD09DCULL, 
            0x8D84CEFAAFB64A84ULL, 0xC3F570611DEAC063ULL, 0x31BC0646A34DC08DULL, 0xD85A57044979B9B9ULL, 
            0x53DD9639409D9FAEULL, 0xFA8400050B7B0C56ULL, 0x0BC831B6A837EB11ULL, 0x23E2261A03D82455ULL, 
            0xD811257A2D39431AULL, 0x9E546FE83302B16CULL, 0x9C51E380BBA5A853ULL, 0x52239ECDF7FA8373ULL, 
            0xB32E3D178D3C74D8ULL, 0xC2D3FE8D84610FB5ULL, 0x1AF89C310C01DA4CULL, 0xDAC5AD831E096CF3ULL, 
            0x1DCC05392C9C7488ULL, 0x2FCF5FBF58BC3ABDULL, 0x784E0DA5941F432AULL, 0xC563270F89EFB3A5ULL
        },
        {
            0x524798D009296AA5ULL, 0xF2893B552892EF6FULL, 0x98169464F7B3EDD0ULL, 0x1D3B38C42436A468ULL, 
            0x97B7BB8E8E25F083ULL, 0x5CCD63CE541D690AULL, 0xDA18DB61FE3B17C5ULL, 0x2994A7B1BB740FC5ULL, 
            0x9A579F054B595946ULL, 0x264819EB0206FE4DULL, 0x79A7C7287097D4B8ULL, 0x2B49829B4C2D4973ULL, 
            0x42995B36FFFEDCAAULL, 0xB47E015C04C558ABULL, 0xAC0057AB8B0D6BCCULL, 0x3C26040878CD6E51ULL, 
            0x3625CC7D9336C015ULL, 0xF575033C0B179527ULL, 0x66A3C2558DE09F21ULL, 0xB07AFC1CFFA771EFULL, 
            0xDBBBDC7A98E535E6ULL, 0x68BF4FF09DD80337ULL, 0x04CACC37D9C13EE2ULL, 0x059D56D7D9CC0F4AULL, 
            0xEA1CE08E0E8FDF7CULL, 0xC70C95B0292A49EFULL, 0x7217A15DFE7A7D09ULL, 0xFF9F55DFFE00BD75ULL, 
            0x822BD2243AD9D74DULL, 0x67C35D59C7C5681EULL, 0x939DEC88E8226373ULL, 0xDE6E60A6B8AD2B6FULL
        },
        {
            0xC00F0CD244C36091ULL, 0xE2D6EC0F59B1702BULL, 0x95FD391E94CC6EFFULL, 0xEFA8D887863208F9ULL, 
            0xD86A615A20D6680DULL, 0x6F89CE94D7F86F6DULL, 0x96059A94AAF94906ULL, 0x6846B970EA780BB6ULL, 
            0xD79E7B14B4050B13ULL, 0x21FF398124F934E4ULL, 0xB4E1D8C7541B5A9AULL, 0xADD987279A36587FULL, 
            0x09451373A79D9AEEULL, 0x72967B69483C71B2ULL, 0xAAD9C2280865097CULL, 0x3B99A4E8F87D17E4ULL, 
            0x9C555E3612682F8EULL, 0x70022F5170882804ULL, 0x142B54E87E6AF8F1ULL, 0x30513A99AB21B592ULL, 
            0xB9DC055151F76067ULL, 0xC5526AD00AE1AEE3ULL, 0x89F3842636EB7EDFULL, 0x50F25026CC85B5EEULL, 
            0x7C24B9380589A59AULL, 0x5353B6CDE4027A84ULL, 0x49610CEBF447245FULL, 0xD9C6D6382B422B92ULL, 
            0x69B8BE6221262A9DULL, 0x1605A35CCF724527ULL, 0x5E8E6D6FC786D900ULL, 0xF6C931F1919A78A3ULL
        },
        {
            0xFB9B3750275C0375ULL, 0xCDB73E71CE13C97FULL, 0x02E35998165A4362ULL, 0xEC41479E9814F1EFULL, 
            0x05D195E1A9A878A8ULL, 0x384D9C0FDEAFDECFULL, 0xAE49DC4D0F3F6855ULL, 0x1D57CD7A43773547ULL, 
            0xD0D28EB5A3E79030ULL, 0x9087AF4D390E71ACULL, 0x5C335CEF512D09A2ULL, 0x33BDAC031BA58100ULL, 
            0x2CE0717CDD073C3BULL, 0x29DDE4A7CD74BF25ULL, 0x773860E339D5DFF8ULL, 0x5BC951569646447CULL, 
            0x922510EBC805F03DULL, 0x2B7E4A78204441C9ULL, 0x876390F42AE4D91DULL, 0x3A7DD1B4A44A775CULL, 
            0x69F96F1DBE578C76ULL, 0x5A252120E7A5A1F6ULL, 0xD400047A3FC2FCEDULL, 0x1782B76D1C3687AAULL, 
            0xA02F99017D00A2FAULL, 0xDA3021786022A2AEULL, 0x47256955C6BB182EULL, 0x5346CF0314530189ULL, 
            0x3513C8749A431B80ULL, 0x045B2F27D3460F52ULL, 0xE0FE26B241941F64ULL, 0x40AD4B72FAD6580EULL
        },
        {
            0x6BE1EB8588538AFEULL, 0x5FBD175D174E933AULL, 0x8B9C9B8323027F0BULL, 0x7A54DCD2219148F9ULL, 
            0x70A82F8BD78C35B2ULL, 0xFC594BB971D677BEULL, 0x0D54E01FE73EEEDDULL, 0x09B7B6D61AF95AA2ULL, 
            0xA67AD879FFE670E0ULL, 0x09E1F5FB23C009C8ULL, 0xF3A3BB27F07F921BULL, 0x404909BBA5D2B616ULL, 
            0xFE4DA6DE930D6112ULL, 0x1F42AF79755034EFULL, 0xEA0E096DE528C899ULL, 0xAE38B37954D506E7ULL, 
            0x161B8DBAA66B4E53ULL, 0x91B1E688FB7717BCULL, 0xFD80492218FB4D98ULL, 0xFA981468D1CAF728ULL, 
            0x7FDD71F349634DFBULL, 0x74F52759988C6C3CULL, 0x295CA670F4F818C3ULL, 0xC28E52DFF89DDE83ULL, 
            0x0D2014B50F777642ULL, 0xE81A89285A5BB1B4ULL, 0xE11D336F97E7D901ULL, 0xBA28DB25801843DCULL, 
            0x75D15D69B4E70839ULL, 0x7BAAA4C95B34B7E9ULL, 0x262DB4E19625908EULL, 0x928E7E893B303511ULL
        },
        {
            0x73984F4C074FD1D1ULL, 0xB2D6D269543E8055ULL, 0xF1AA6A5A22D82653ULL, 0xA74EF2B76291B654ULL, 
            0xCEB7D1C95924253EULL, 0xAF8021543D69FE70ULL, 0xE6566917FF27DDD1ULL, 0x5E4D2333E077AF3DULL, 
            0xC536C81D856F4521ULL, 0x515265DCF951B74DULL, 0x1F6C131ACF64AD8CULL, 0xBBE648875310C8C3ULL, 
            0xD4981FF4AA0C8079ULL, 0xB63DCBC6559A68DFULL, 0x61A53B245B724530ULL, 0x54F0DB1EF576C9E0ULL, 
            0xD4F7285882C821ECULL, 0x2843F9187BDFF919ULL, 0x4EE49B6E057B095EULL, 0x8F2594CE334325E2ULL, 
            0xB046ED8C524776AEULL, 0x88AD26FA59032334ULL, 0x2A3362BA37CC5508ULL, 0xF346D230CB95690BULL, 
            0x435FA6E263F80C4CULL, 0x1FFF1EDFBD57E572ULL, 0xBB51283AEB5F7BC1ULL, 0x0A80A4B368A72543ULL, 
            0xD1BF4246EB8D204FULL, 0x351C6D410546DDA4ULL, 0x33F9AC80721391F9ULL, 0xC65278DE6AA1B42AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeyRotateConstants = {
    0x884F985F9FD447D4ULL,
    0x1EDFDD88AAAA6760ULL,
    0x386C010D994053F4ULL,
    0x884F985F9FD447D4ULL,
    0x1EDFDD88AAAA6760ULL,
    0x386C010D994053F4ULL,
    0xE762BB75515F5431ULL,
    0x732ED298CF1B8C96ULL,
    0x51,
    0x9C,
    0x37,
    0x2C,
    0x46,
    0x79,
    0x62,
    0x83
};

const TwistDomainSaltSet TwistExpander_Suhail::kKeySpawnSalts = {
    {
        {
            0x443B6FD31BF35E35ULL, 0x9EA4AA416F04D156ULL, 0xC50DFADCFCC4B247ULL, 0x2240EF812750384BULL, 
            0xB3E2FCF6BF79D6FFULL, 0xF28F8C2618360D75ULL, 0x116FB0DFE85EA4FBULL, 0x865309307F3EF49FULL, 
            0xC2281BF8FB1B9C4AULL, 0x84F9EED3EEF5013DULL, 0x4E50C2BB2D1501F9ULL, 0xBBF996338F48E281ULL, 
            0xCC58AFBD76EC9A60ULL, 0x99E0393DB1F0935CULL, 0xCDC03FC8FABB813BULL, 0x97FA92650D5AA7F8ULL, 
            0x5A87BCDFE970D406ULL, 0x4E110E0866628D77ULL, 0x3ACF8D364495B2B0ULL, 0xE7723241EFD09EFDULL, 
            0xBBE2AFF05780626EULL, 0x3797699D7ECCBA21ULL, 0xE299C6EBE1110918ULL, 0x367509B74F33C828ULL, 
            0xDD1A0B9EF86B646AULL, 0x1A6E4FA934576E6EULL, 0xCDEAE3D73293A47AULL, 0x093BEBC9CDAC93F7ULL, 
            0xCB764BCC56FE7971ULL, 0x31F82522CA1CC5F4ULL, 0xF061E4EAB94412DCULL, 0x6EAD70183BF6E193ULL
        },
        {
            0x90E1328A0B5A8780ULL, 0xFE58970D54E780B1ULL, 0xC80FE4FEAFF3EA60ULL, 0x60C529B295AE57DDULL, 
            0x9AB83741F5E89EC1ULL, 0x1E366B44BE8A1F7FULL, 0xB113BA303981B5E3ULL, 0x0ECF5685EE408ED2ULL, 
            0x6FA01082B2AEA712ULL, 0x9EA6DD3BEFC7A093ULL, 0x1BF3FF5F27317145ULL, 0x4A4F29DB44DEB75FULL, 
            0x714010AEAEDBF663ULL, 0x071AC0A1AD2ED443ULL, 0x74D40E7CEF57C733ULL, 0xA802B0DBD2BA05D6ULL, 
            0x0C1ADFFFECAE8800ULL, 0x43E06B6F7CF0AF00ULL, 0x03CFCD70526FCB9CULL, 0x08A0D9B4930B001BULL, 
            0x9CABCF9967956FAAULL, 0xF8554866055357E7ULL, 0x25F661AD0E26C17AULL, 0xE8B58586E615CA4BULL, 
            0x22D9D4236C335912ULL, 0xE45101679728D30BULL, 0xCD0FB4C79E51FB0DULL, 0x2AB0A51F48D6560DULL, 
            0x5271042387A1D2D8ULL, 0x2766B62D8B248723ULL, 0xDB55F4F12C9C547EULL, 0xD42BCE2BAC42FEB4ULL
        },
        {
            0x97F5C318B516FB15ULL, 0xA9124F772C2A339DULL, 0xABD6C9BE76483D2DULL, 0x38C1B8E3629B91A6ULL, 
            0xEB4571F4835E6A49ULL, 0xF54937B5B36FA4C7ULL, 0x3DE53D33A32CD306ULL, 0x1B99657CE6D29987ULL, 
            0xA51429AC4484A145ULL, 0xBD06FBB35026D9F1ULL, 0x18241FEB96468C42ULL, 0xF48F4A51313F7991ULL, 
            0xC32980105A8F5E8CULL, 0x02F177E7A04C4903ULL, 0x83E702CAC9AED605ULL, 0x09CA531330666834ULL, 
            0xB65E9CEEC4F226E6ULL, 0xF30EC134ACC31755ULL, 0xD200F31BFCFC10A6ULL, 0xC78DF5A1E86F76F6ULL, 
            0xDB88AF63EB2A728BULL, 0x4D3ADD40EB0F15CDULL, 0x34E31F27F7B05241ULL, 0xFF3239746E793C47ULL, 
            0x7D2BFBBD6CC8C36FULL, 0x5EBDB4108FDD8552ULL, 0x86ECE67739B640BCULL, 0x82E6E63549A1B625ULL, 
            0x485652AE9E942C60ULL, 0xF162E51275BBFE14ULL, 0x6D0EF96E5C70AD7FULL, 0xF48D3FBB99AF6A54ULL
        },
        {
            0xED4704D107C04B14ULL, 0x39267B0DF8381765ULL, 0xFA74796BA570860FULL, 0x279FC8533D5C8F91ULL, 
            0x95AD50F9FEABF127ULL, 0xEBA37F3763CBA872ULL, 0x9BEF3B555169C4A7ULL, 0x1A793C10EBF7EBEEULL, 
            0xCAD9AA5C8E136079ULL, 0x04ABB20A0813861FULL, 0xBBBE33298DD7C93CULL, 0x4B8F1BF58E6804AEULL, 
            0xA18D9995CD7EB2DAULL, 0xF3CAEED2EA0C9334ULL, 0xDDC3F7CACEA92FB1ULL, 0x5364BE928E405AA5ULL, 
            0x3691FBDFEC862943ULL, 0x72E6A9E62A82AFDAULL, 0xA32D5132D6A4DD86ULL, 0x93BD77FA3905B88CULL, 
            0x7393A01F0FFAB569ULL, 0x6731E794D56DD564ULL, 0x7E026188BE82A6CEULL, 0x5EED243416D9170CULL, 
            0xAB6918474D32DE32ULL, 0xDA3D21327E3D9D4AULL, 0x678E04F62FC9D8B5ULL, 0xCF916DE65DB5B768ULL, 
            0xF78EE410AEA9CFE0ULL, 0xAE64F89CF8D9AB00ULL, 0xFE122BC0E9E3E20DULL, 0x6A2A0A136E240B31ULL
        },
        {
            0xCFD14DB56EBCA7F3ULL, 0x820A900FE3F97F54ULL, 0xD57DEBB399242DE4ULL, 0x6397A2F64EB42768ULL, 
            0xE6B931551E13F53AULL, 0x8BE348F5098EC784ULL, 0x81E2E42B24378AB2ULL, 0x4E7000F120CBD34BULL, 
            0xD19046D4A7B4EF99ULL, 0xFBFC1E97592D0176ULL, 0x64B3DB9F85BB99A4ULL, 0x74021DC717121320ULL, 
            0x5895C3A8BC4D159EULL, 0xE7E651ABD03A8A6EULL, 0x058D74B13716463CULL, 0x163B4D3F8A1B3151ULL, 
            0xAE70D8FAB54E74E9ULL, 0x40DDA3A97F5FE3ECULL, 0xEEAC1B2F6D3EEB25ULL, 0xA1AA9D6040FBB641ULL, 
            0x1D8726B8888928A0ULL, 0x6DED5E3820121617ULL, 0x3A67D6608C84470CULL, 0x670E5ECC9D9781B9ULL, 
            0x88B31AAE2E9410A1ULL, 0x1FF37B7ED74BB9DDULL, 0x6B9AA76573B3FE1AULL, 0xDF5200323C8D7416ULL, 
            0x15F8308641CF8FE3ULL, 0x4911116A49644A25ULL, 0xB717976713268E68ULL, 0x179534E120C3727EULL
        },
        {
            0xEBA473742605825AULL, 0x84328E52E4D2D597ULL, 0xF501E7D47C0F3CD3ULL, 0x6C4FCEBCF3E7E78FULL, 
            0x4827DCB24E3E6150ULL, 0xA2CD6771D359F39BULL, 0xF104EE309F86C664ULL, 0x2D1003208ED0853CULL, 
            0xEAF9B066846E9737ULL, 0xA09832C426597B46ULL, 0xDC9C210BDCA8A623ULL, 0x62836E4162A67E35ULL, 
            0x658A8A84BDA64EB5ULL, 0xB8999C2723440E99ULL, 0x7DF661B4B697F1AEULL, 0xBFD81CB83BE6A61CULL, 
            0x535E9E8AE02DA2C7ULL, 0x128C2B234D3B39EAULL, 0x037B0933D5041520ULL, 0x9BC17FB67897DF23ULL, 
            0xE3FF63A39CDAEF03ULL, 0xFA2A79667E471A39ULL, 0x160664F69500AFC4ULL, 0xED5ABD288AD1B897ULL, 
            0x987049AA84B22FBFULL, 0xE98DBFD233FF9BEDULL, 0x5F9439580F26EC72ULL, 0x5BA4E99DADDD68DCULL, 
            0x4B6BC2C10F4B4B60ULL, 0x0BDB02837721F568ULL, 0x742DBF2B9666FF98ULL, 0xEF4DEC598E601B6FULL
        }
    },
    {
        {
            0x31AA0D69E9B0E06CULL, 0x7CF958C179B8B9DBULL, 0x3B55401B6FFDDC28ULL, 0x48C33BB91810A309ULL, 
            0xEC0F8F9C6F1A7BB3ULL, 0x87764402F86BF1A2ULL, 0xA58841603CB9469AULL, 0x5C0B815E437B8B13ULL, 
            0x2CD3D5719F5EE911ULL, 0x0E2F6B30626E2144ULL, 0x1D9BBFD6C7EDEF9CULL, 0x8590F53CAA30CEADULL, 
            0x998F5C8F279B31C7ULL, 0x02C1264011A510EAULL, 0x09595D25DBE2FB90ULL, 0x97311065BF406747ULL, 
            0xAD796C4FAE3CC7FBULL, 0x297A25917D6DB95AULL, 0xF2980A98038E94B3ULL, 0x29569778394701D1ULL, 
            0x90BFDC84CE88DB80ULL, 0xCB593B80B5E3EA4EULL, 0xB509DD52502103B4ULL, 0xF998D8CDACAD767AULL, 
            0xFFE989274E76A1E5ULL, 0xE094CEBD26EB7321ULL, 0x124357644DC022EFULL, 0xB7838F7EF2ADB873ULL, 
            0x34165867D683E5A9ULL, 0xFF6ABE7E3A52B60AULL, 0xCB1DE166C75AF0E2ULL, 0xC5FD707188DAA592ULL
        },
        {
            0xF997FB4C38F8561BULL, 0x5F7A6F05E4FAA4BAULL, 0x06FFB7BD2B4C7B3CULL, 0x56E1931AD1EE8B72ULL, 
            0x316CBC0D0FAA775AULL, 0xFF2F93EDD2CB9411ULL, 0xE9517C5F1016CC2EULL, 0xFD816E348313D6D4ULL, 
            0xE3900E52EBFE85E7ULL, 0xFA728F9877FD9323ULL, 0xFA296462A66CC96BULL, 0xB9EBD6B824AC382EULL, 
            0xC2C4D27533303A1DULL, 0xD5B4138D74BB59F7ULL, 0x1D4A17B4113EAC76ULL, 0x7B45587ACFC379ABULL, 
            0x32AC4B891AC8519CULL, 0x7E16A0FECE2831ABULL, 0xF56AAEA5FC2CF949ULL, 0x6F52E5BD8B472844ULL, 
            0x604F0D3CE2555FBCULL, 0x5CF713D0283228A9ULL, 0x3D69CB8F44A9FBD3ULL, 0x38FBFBCB67B105CDULL, 
            0x524FDF6DB3AA3895ULL, 0x00BA2585475BBFF2ULL, 0x7ACAFE5A929B1B0FULL, 0xAD34EA9D20971459ULL, 
            0x95AA0D7E75981592ULL, 0x92558F488C2732C6ULL, 0x6CFD49539B7517F2ULL, 0x2D7A98E49ACC1011ULL
        },
        {
            0x8CA82D432080E52EULL, 0x9908A7A37CE1329AULL, 0x88BECFB98ABDC902ULL, 0x5964E26F10B4915FULL, 
            0x62B7FE4E10C2BC4CULL, 0x5EFACF74099E777CULL, 0x1CC2301F7004FB75ULL, 0x2E1D0C947353E5CBULL, 
            0x14678CBEE2271C7EULL, 0x35C5E98DBA24245CULL, 0x487F45081F783D82ULL, 0xE900211DE768326BULL, 
            0xBFCE3DF9B7B3AFFFULL, 0x7F1295A64E158C87ULL, 0x466675968398F991ULL, 0x7A635D7E68B31C3DULL, 
            0xB2E4BEAD5AFE3937ULL, 0x78502B3E67ADE42BULL, 0x85F6C020E2B5D3B0ULL, 0x0243ADBCCDE583ABULL, 
            0x63FEB082CB397AAEULL, 0x0434AE181492A3BAULL, 0x612CDADC9DCC7A03ULL, 0xA0298EBBB81BE0C7ULL, 
            0x5295987EFA182C5DULL, 0x7527E1C1B80C51D3ULL, 0x25DEC8CE33CEFBC1ULL, 0x344845458541185DULL, 
            0x7ABEC0892F160AADULL, 0x8CAECBE04765483AULL, 0xD43CCDF3EA0FCBEEULL, 0xDB90AAB35D15EA98ULL
        },
        {
            0xA710F5A92DF5BC9FULL, 0x52E851B8303E2957ULL, 0xEE7BC47204EA4617ULL, 0xD23ED226C68C7B34ULL, 
            0xC239FD4826A39FE3ULL, 0x5341292AD816D2BDULL, 0xD5EE3AE7D6D4C683ULL, 0x144160A65E1A3756ULL, 
            0xF272E155A81086E7ULL, 0xED75D7ABEC4A4AB3ULL, 0xABD120DB7C6AFF03ULL, 0x0A7EEF3697CC8516ULL, 
            0xDEED04F44ABFBD4EULL, 0xF6DE501787887CCDULL, 0x5BD9785872A37D81ULL, 0x2AD953E7A9897351ULL, 
            0xDA98C28DF832E5B8ULL, 0x810EF5B9ECF3D0B4ULL, 0xBFFD0C49128D6229ULL, 0x9B3E0E98E95CCFFCULL, 
            0x31452ED08C32E36DULL, 0xE6033A81F6D4EA1DULL, 0xC99D260CFFAC8378ULL, 0x13463D8233F469DCULL, 
            0x24C37B92ABF7136BULL, 0x08D63E943C0DDF19ULL, 0xD3431D7953630D7EULL, 0x423DBD479BAF95FFULL, 
            0x7798DEC223EC3640ULL, 0x8715D62DBB5E38AFULL, 0x77EA0C75F4D6631BULL, 0xE5C16A4E74367B6DULL
        },
        {
            0x45D6A624D4B1072DULL, 0x7C3C60ADDFE86034ULL, 0xD162E5495DA7EF23ULL, 0xC36A5F8431CCC5A6ULL, 
            0x00A8689DE5FFFB9EULL, 0x5FC22A74EE2E32FFULL, 0xDBA17CCB25F32489ULL, 0x829BC8453111A5EEULL, 
            0xB513EF349F1B030CULL, 0x9D5F4BDE372B5DE5ULL, 0xDED125D92EE08A91ULL, 0x0435DC24AC39FE67ULL, 
            0x2BDE064A65457BD0ULL, 0xE6730052920FF938ULL, 0x27D8F9C881CC003CULL, 0x67D7118279590EA4ULL, 
            0xD8FD01545D54DA4DULL, 0x2207180C126BE8A5ULL, 0x2E2393FB9A5D9B58ULL, 0x778B1A1A145EDC9DULL, 
            0x8F38501B149990C1ULL, 0x3372C498C51E5A90ULL, 0x280A0F0CC43153DDULL, 0x0401BCFD270C78A7ULL, 
            0x46707F0D3E641852ULL, 0x0DB17C50C24D67F8ULL, 0x6AEF85A72892FEAEULL, 0xA2CA3E82C0669E91ULL, 
            0xEFEA99F3BBA25306ULL, 0xCB5163BA7D341850ULL, 0x05B6B180CDEDACC6ULL, 0x645D401D7BBF0CE7ULL
        },
        {
            0xBA54C3B0121E0D1CULL, 0xDDD0BB1211B95962ULL, 0x15B523AEB5A97043ULL, 0x6AA7D3077D3711BAULL, 
            0x83B8AC7C39A7C7D5ULL, 0x5E99B6C16AA3DA98ULL, 0xDAE67B8E38084861ULL, 0x5B741719945CA914ULL, 
            0x6596C9A66E2CD211ULL, 0x02FE25640B2C26BEULL, 0x72EE41F00074AA37ULL, 0x993BEBE1920AE60FULL, 
            0x3D7F076A480EC2A4ULL, 0x84CA53AA9ADAB42DULL, 0x295B2F05F6F30F4BULL, 0x61E9F210319D4D1DULL, 
            0x4D94F4E6F1AF4147ULL, 0x039F40A4F841F535ULL, 0x6879217E9A7F84A6ULL, 0x6641C8050BB54D04ULL, 
            0xEA10AFB0DE1478F1ULL, 0x065707867BA81A39ULL, 0x9C768053124BD31AULL, 0x4055B78C73A43D07ULL, 
            0x165EAC54E1FD47E2ULL, 0x948D4AA555CAAFB5ULL, 0x8EF0269BF2FF6F70ULL, 0xF082F3A8313DED68ULL, 
            0x22287E6AD9E708E1ULL, 0x1A50A6A418FCA726ULL, 0x91756DE6BB85AA1DULL, 0x58A5103B08F32E6EULL
        }
    },
    {
        {
            0x6E271FF7D04B3DF4ULL, 0x9BA1927F724DE3DDULL, 0x574DF23A94EDF5E2ULL, 0x707702C92C1023D9ULL, 
            0xA5567B9878A2F79CULL, 0xF3F95EFD86DE7B2AULL, 0xC9E4A584BC35A86CULL, 0x6F7B925CC4BA42CFULL, 
            0x443140832331D7F6ULL, 0x18C1CD27718C4D7EULL, 0xC63F7E5475CBA7B3ULL, 0xD3DCEC61E7C13FA7ULL, 
            0xD10BE3BA1DAC698AULL, 0x1A87A03D988A7840ULL, 0xD66D11AD5318431EULL, 0x5708AEBA4A321DD2ULL, 
            0x9FA2EF40207C5849ULL, 0x700D9A2C2140FC06ULL, 0xBBFCBAE731924008ULL, 0x8C3831FDE65E2607ULL, 
            0x66CD441CD0EFF9F1ULL, 0x8090A09B4934DA86ULL, 0x67F719046E3B5E6CULL, 0x67B3226FA5C56C3DULL, 
            0xD7C9705E2FDC5734ULL, 0x62087E58AAFFFC24ULL, 0x071EF136702D15DCULL, 0x1154426F0D3CF08EULL, 
            0x5B4F4C09CC4A747DULL, 0xA21FF5A09B97B86DULL, 0x94B8B42196BD3714ULL, 0x17FA3A66CA0ED226ULL
        },
        {
            0x4D36FB237328CB9DULL, 0xC8779813B95E51CBULL, 0x116CBA01D09D2D8BULL, 0x665CC80A2E3ED025ULL, 
            0x727B1476963B3CC2ULL, 0x1F2F19241B5403E5ULL, 0xCFC2080E8161E9D5ULL, 0xEDBC8CB7D5BA55F0ULL, 
            0xD9B921F417A51389ULL, 0xE87D7B858FB9FE00ULL, 0xE7CBBE7B004A0632ULL, 0xF9648734169BCD02ULL, 
            0xB71169E23D36E814ULL, 0xF43289842A29F677ULL, 0xBCBD11EF59BA473BULL, 0x82DBE1E8E31235F4ULL, 
            0xE5E87702E59A98F3ULL, 0xDBBF10A6B21119E1ULL, 0x62C3B63676B08B2FULL, 0x371622469FBC677FULL, 
            0xA5F0726E02EEED41ULL, 0x8A4365BA7A8B160BULL, 0x75EFF6214CA60E42ULL, 0xABC28C79C852AC75ULL, 
            0x2DFF31DD84352AF3ULL, 0x92139C448DDAA56CULL, 0x5DE7F297B85C78A6ULL, 0xD0A71B3CA8AAA322ULL, 
            0xD291EA8C3426BE25ULL, 0x403ED663A8B41C73ULL, 0x94BE1E191DC8E3F8ULL, 0xB1B49E6A06BD3774ULL
        },
        {
            0x78122853ED0AA876ULL, 0x10247E1BE96B3BC6ULL, 0x3C8BAD2E54D064DAULL, 0x39F6A4E003A5598AULL, 
            0x163F11FBCB19E1B2ULL, 0x920EA54F561A21BCULL, 0xECF68A4137476C49ULL, 0x8FF8A6E4A574080EULL, 
            0x3E87AEF49BBF4129ULL, 0xCECEC18CD41FCABCULL, 0x58802EF868CB6066ULL, 0xA10A44F0197EEC74ULL, 
            0xA84B61EC54D10E04ULL, 0x6B579F7155AB9238ULL, 0xEB808006953AEE81ULL, 0x48080C99064F5192ULL, 
            0x03DBE0B2B28BE88FULL, 0x60B50F19FE8B8B99ULL, 0x4B2FFD8133B3F029ULL, 0x46C337E2982EC40BULL, 
            0xF539008783705BCCULL, 0x02824C6AC18E08A5ULL, 0x12BD81D748A584B3ULL, 0xDEA36F0AA60C4C48ULL, 
            0x1B14D2DE70A05039ULL, 0xEEB80E8A472D1741ULL, 0xE3FA245321042AFDULL, 0x688DCFC413784CA4ULL, 
            0xF1A8953612FD5497ULL, 0xA5541751EC256921ULL, 0x5986F391628CB24AULL, 0xF5105464B2CA98E5ULL
        },
        {
            0xD689EBF4B6FBEC21ULL, 0xCB90D8A6D40A45DFULL, 0x510D492B271467C3ULL, 0x2CE1FB43F4EC5E9FULL, 
            0x7097230B08E5DA3EULL, 0x65D8D4D2905B1BEFULL, 0x3B85E0262082E9F6ULL, 0xA322A5E8656B6B1FULL, 
            0x9A241B1087EA6807ULL, 0x51CE9E50BE58DAD6ULL, 0x12F43230546AB08FULL, 0x738D4651B3D340BDULL, 
            0x36C397E787A00995ULL, 0xB69D87FECBCF4C03ULL, 0x790334BBA57084A5ULL, 0x6B03A580396BA416ULL, 
            0xBE1390E9BBBDCD4CULL, 0x2196FBB6A78EC569ULL, 0x180ACEBBDCD8F82AULL, 0x78EBAD4988D8CE25ULL, 
            0x4A3450ED4DCB3D92ULL, 0xDCF5E582392D78C2ULL, 0xC7D5CD7C1F34E29CULL, 0x068EF7BC7215FA9FULL, 
            0x83514423632EE3A2ULL, 0x5B7A30854DB3B87AULL, 0x2FD69285C3154621ULL, 0x6ABE9B52E20D3EEAULL, 
            0x9C12D3918EF298DFULL, 0x2E936411BA237064ULL, 0xE241C54D907094C9ULL, 0x3E862AD5DB786FA0ULL
        },
        {
            0x7C4072E96EBAE14CULL, 0xC636DB4046254E53ULL, 0xCA2A3F7A857CC335ULL, 0xD19083D09831DBEFULL, 
            0xA8B3B54D4C31EA63ULL, 0xC0D0740BDC075F40ULL, 0x2B9C69082084966FULL, 0x9BFB912A2D32982BULL, 
            0xDB282E75962192EAULL, 0x8B1980B6383E2401ULL, 0xE8BC5FAC120D94B2ULL, 0xDC38996E821F9B2BULL, 
            0xDE3C05FEDABF81D9ULL, 0x1ECD05831A9E48DCULL, 0xF5FDC1AD0784807CULL, 0xEB45D6EAEAA884F3ULL, 
            0x3825403E4C68D33AULL, 0x78D4E9B0945B8705ULL, 0xD6D774955A383EF3ULL, 0x41793E238BEB9827ULL, 
            0xFF1A93D77337F3B1ULL, 0xD332C1631C9223F4ULL, 0x85765D177FDA29A5ULL, 0x93B0C922527A9CD1ULL, 
            0xE2ED5B7FE80CA24DULL, 0x49AE08EC7A3AEBDBULL, 0xF1DF08F32887CD75ULL, 0xD2D309901C5D2ABBULL, 
            0xC514CE7FB635E7FFULL, 0x7E282BAB2EC5CBD3ULL, 0x8E5657D3151A6236ULL, 0x05867102ACDA7B5AULL
        },
        {
            0xFBC029E3D139CD5CULL, 0x60BDDB2E1C532752ULL, 0x75E2E6304E14EEAFULL, 0xD8074E19BEEE8C70ULL, 
            0xB7D9E5FB6C2F7F24ULL, 0xDC1FAD03E19826D7ULL, 0x4D7D7D5F8EFDE247ULL, 0x935882786073B7C8ULL, 
            0x7A6C7561F6AF4F00ULL, 0x91362615ECE8E275ULL, 0x90F9D9FDBB90CA49ULL, 0xE2480A20B001D7D1ULL, 
            0xA9E0A1C3CA04095EULL, 0x9A9A920EDB5DE13BULL, 0xB3D3257702BA2926ULL, 0x866734E44B81F24BULL, 
            0xB5858DBEFA4E9C80ULL, 0xD2509E1F4BC07042ULL, 0xE006423A5D2E929EULL, 0xC6D3FA1FFBBE9928ULL, 
            0x8529708345C5D841ULL, 0xCFDC8C1EBBBCFD24ULL, 0x79FA1BBAA4D0ED6AULL, 0xD26050DEF30106D6ULL, 
            0x49EF9851C56A1800ULL, 0xB2CF5E0556D1D8D2ULL, 0x8833C54C6DC9B941ULL, 0x2D326266EA5A86A7ULL, 
            0x95DB7B8A28A9D471ULL, 0xF830BBBD1B9C8FEFULL, 0xF9F692F41C5D7EC9ULL, 0xB9B09F7FD6B4E121ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeySpawnConstants = {
    0x9EDA7D9D96A8FBE9ULL,
    0xBF6E277189BAA9CFULL,
    0x5AE60FF7BC5013DAULL,
    0x9EDA7D9D96A8FBE9ULL,
    0xBF6E277189BAA9CFULL,
    0x5AE60FF7BC5013DAULL,
    0x9A837307B42A3E48ULL,
    0x6DE8D2E0EE344098ULL,
    0xE5,
    0x06,
    0x2B,
    0x74,
    0xE0,
    0x1C,
    0x15,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Suhail::kSeedSalts = {
    {
        {
            0x7F47CD74C607AB6BULL, 0x190A8AF48A048900ULL, 0x601106DC40DBE70CULL, 0x0EF10D87D61ED00EULL, 
            0x71EB067C46D8B840ULL, 0xCFC4985705F1040CULL, 0x4ACA26541977F103ULL, 0x756AF5C26817D37FULL, 
            0xB0D66E96A9C62F53ULL, 0x49B89D52C26DFD5EULL, 0x790796FEDF1F21FFULL, 0xCD1BD9EDC9A2CEC4ULL, 
            0x554B85711B072F3DULL, 0xD5837A988ADDD8FAULL, 0x2D2967B97BD3231DULL, 0x6C9A62F3DE93DB18ULL, 
            0x991B381FA45F95C2ULL, 0x46935D90F2B80DE0ULL, 0x87A2ED88AEE1E1F5ULL, 0x692B20A26F50A67EULL, 
            0x4213905CB0D1D682ULL, 0x1776788CE82CF1FEULL, 0xCA92ED22788090D2ULL, 0x724FE74A0984A2F0ULL, 
            0xF6AD42AF551777A9ULL, 0x9A2DA46A4C6081BFULL, 0xA2F06222E4F1DBE2ULL, 0xDD2FD9B0A8B49CD5ULL, 
            0x2FC5BEBC061A1A0FULL, 0x7506DD091F1B28B6ULL, 0x8F896BC6973BEC67ULL, 0x0904EB78A7D310A2ULL
        },
        {
            0x8E614AFC3D2A9566ULL, 0xDCA26C064DD4DB71ULL, 0xA81551FE638940B9ULL, 0xCA4593D922CE9D0BULL, 
            0x9CC11EE961843624ULL, 0xB6793322606724FBULL, 0x0CDE08546ADDBC85ULL, 0x74A9FEB69B0D6593ULL, 
            0x2DF2B51CCC547005ULL, 0x0AE878EC34063EA0ULL, 0xA1BA999FA62EB493ULL, 0x282E227F7B9F4E78ULL, 
            0xA01B14CB02669DE5ULL, 0x549C68BA70AA01F9ULL, 0xD4DD959997475BD7ULL, 0xDA42DBB2376B8795ULL, 
            0x657961C7D341D928ULL, 0xF26AB78F1ABB2002ULL, 0xBE04A35751F631CCULL, 0xFD977755AA6AFAE7ULL, 
            0xA4E2127C71722065ULL, 0xFE73BF0F1417DCE0ULL, 0xCA4501C2203D8BADULL, 0x9CBD3402335746EEULL, 
            0x41FDB8B1E3B31578ULL, 0xED5130F3255360E1ULL, 0x94AC318A1585468DULL, 0x4217F2100B84E461ULL, 
            0x15C2A4ACC446B966ULL, 0x401F1B3F0E659F40ULL, 0x015237110FC42472ULL, 0x7FF2C21893A9716EULL
        },
        {
            0xD26E00CC9F50C53BULL, 0xB58ED21AE0A3C2A7ULL, 0x2BC90C8BE6DCA1E0ULL, 0xD835117DE5CB768DULL, 
            0x554462390C0A9087ULL, 0x398DAA8F96F5784EULL, 0xE7191297636234F9ULL, 0x20F23849EE8CD6ACULL, 
            0xD2CD3C65E8ABC564ULL, 0x99454F78D259CF4BULL, 0x2C8D68CBF6C1FDE8ULL, 0x5FC885DC00ADDF67ULL, 
            0x3F7C9DB433912C27ULL, 0x1B3B88B4694CA70BULL, 0xD07047EE81C42D64ULL, 0x575AC11728B7B7B8ULL, 
            0xEBC2C163BD04980DULL, 0xD273D0CAAAB21B30ULL, 0x3AB0EFF70B91C524ULL, 0xF399D9092F74F955ULL, 
            0xD9BC2B8DDFAA522BULL, 0xA984B21601C60B37ULL, 0x229DA8102FB6C9C3ULL, 0x165E145F3B910562ULL, 
            0x68291ED584C133C9ULL, 0x0BE607E54F3ED98EULL, 0x83BFEDD7C6575AD7ULL, 0x7488E25F8CF83EB8ULL, 
            0x10AFF2C0D3141D19ULL, 0x2B6CCCEEB8058FAEULL, 0x3D3CE75465F322CDULL, 0x8684D18942E4C3B2ULL
        },
        {
            0x18C982772767CB62ULL, 0x7221C8CFA6E0F349ULL, 0x2048A2DD4E4CE8D0ULL, 0x9C25B4D7080B9153ULL, 
            0x9B88891813CF2E27ULL, 0x23AEFC1589890453ULL, 0xF0D51C9E2867B8C2ULL, 0xCB4FFE368EFB215AULL, 
            0x73ECC137278324D7ULL, 0x8C013C2B3C855F4CULL, 0xC2479D2834C4F45BULL, 0x7E5851EAC5342FA1ULL, 
            0x83F405957F17F252ULL, 0x182AC0182535C0A0ULL, 0x2D33FBB11432954EULL, 0x4A38101EEC964013ULL, 
            0x76C23B22539AA1C2ULL, 0xD7A47D88127266C2ULL, 0x15F8CACA75217736ULL, 0xEA31A32F018FD20FULL, 
            0xA7A33FB49DD7C161ULL, 0x85F30C95DEE611B4ULL, 0xED1266AC1D03F9ACULL, 0xE066F8183ADF0934ULL, 
            0xAF2D3A7137170D98ULL, 0x01E3ADE35739E109ULL, 0x28E28CCA923E0719ULL, 0x1FB4BB3B18D49685ULL, 
            0x5ABA87466A89492CULL, 0xF7D43D5C0B6B9F2DULL, 0x7A5259B6B42F3BF2ULL, 0xBBC10CC3AA642FB5ULL
        },
        {
            0xB40FDEE791D587D6ULL, 0x0B8D323864DDC592ULL, 0x82EF6F4DFB2DF5F1ULL, 0x297735BBF7F42CF5ULL, 
            0x7C75AAE0D09E414CULL, 0xB18AE9F056370E1AULL, 0x10AAE224AAC76AF4ULL, 0x5813F46D60B83691ULL, 
            0x12A8F28AEFB1C3D7ULL, 0xB2EBAFF5FFAA7212ULL, 0x830A3386EB7168B6ULL, 0x482A4701B742F3D8ULL, 
            0xC541AE7F507050A6ULL, 0xA37D5ADFD1A1035BULL, 0xBF9406583A92EE63ULL, 0xF85E18AAEC27C2AAULL, 
            0x799F735EED64150FULL, 0x2B65D34DD5E34A3CULL, 0x905CBCB5B5A6C9A6ULL, 0xBB68E2C879BA8263ULL, 
            0xDCB10344A3DB3CC5ULL, 0x3AA0FC4C7B8DD74CULL, 0x93446DC183DEB46FULL, 0x1574635E4C3A4D1EULL, 
            0xBB0B4B97194035D3ULL, 0x15BBB3D14D7BA031ULL, 0x7851A2BD2A05B6D0ULL, 0x85A8AAC4B2D93DCBULL, 
            0x35C1145272FBA0DCULL, 0xCB112A9B37668B88ULL, 0x57E808EAAEC052DEULL, 0xF925A43C78E484D8ULL
        },
        {
            0xDB5C626DE86403B8ULL, 0xBF0696D1C5974DB4ULL, 0xF0A8D35F84CA6141ULL, 0xBDD9ADF3FC3EC049ULL, 
            0x103ED3F4F1D9C519ULL, 0x161CD65058045E92ULL, 0x2DC2C26F5656B772ULL, 0xC6B33DF34D73321BULL, 
            0x98A51835708377E5ULL, 0x4E1C4FD8A013E71AULL, 0x3A9DCF731ADC96D4ULL, 0xAC3BAD67C4224DD9ULL, 
            0x29D4FF1AA8FB0C80ULL, 0x04D8A617FAEF30E3ULL, 0xA3BF6711DB231151ULL, 0xAADA85A2D7EB6005ULL, 
            0xC7BBCF1724FE1BB2ULL, 0xAE7673BA193BFBA5ULL, 0x5CF7ECA078390BFBULL, 0xC03A6444CE0497E1ULL, 
            0xFF3A4A25FF1759A0ULL, 0x7CD20CAC1FCDA2D3ULL, 0xF54AC24C5AD0A6B6ULL, 0x2B90B10CAF618593ULL, 
            0xC51134C42EC7DBC4ULL, 0x3EB79CD46BA3350EULL, 0xA98C234A076FECDEULL, 0x8E1835A4ABD77833ULL, 
            0x19B4DF0B7B44E716ULL, 0x3CF7A1C329194689ULL, 0xC5C2D83293F77499ULL, 0xA11AE6A8009B4898ULL
        }
    },
    {
        {
            0x712793FC76D617D8ULL, 0xDEBF959F99684CE8ULL, 0x5CD1B6CA8BEC94BBULL, 0x65095471C79ADF9CULL, 
            0xFE8C78FF603BB599ULL, 0xDD894ADB952907F9ULL, 0x65AA60AB70B6A930ULL, 0x3FCBC9191F497EE5ULL, 
            0x1ACF016E59DB7572ULL, 0xCCD823585D755A53ULL, 0xDD519389469C73A0ULL, 0xC0943BE415FAF0B3ULL, 
            0xCC9113B974EB80A2ULL, 0xECD8572E1CAB2BB5ULL, 0x1B3852C0BD7A1E62ULL, 0xC17AF5217B666AF8ULL, 
            0x02F3B31C2402C283ULL, 0xCE6283483428FFF6ULL, 0xD0A45049EF783062ULL, 0x76D41DCC64B28057ULL, 
            0x38E638B49DCD2F8FULL, 0xD3D57B498D233003ULL, 0x83B7C818286A92C7ULL, 0xEB0FE38DD7BA753FULL, 
            0x9871551FA5D352F1ULL, 0x0AD4E9ABB77C0F8DULL, 0x9FFF92957B0ECC04ULL, 0x1878E8BA7833776CULL, 
            0x7A9A57CBB801316FULL, 0x3F9BBE3782CF66EFULL, 0x7B549B88081CE740ULL, 0xBB547B5A0901C03BULL
        },
        {
            0xE290942653602AD6ULL, 0x1B93C42B050D08FFULL, 0x4F271DAC231C74F6ULL, 0xC29133E9A1957336ULL, 
            0xBF62BFEA59B2F7E7ULL, 0x83931A532B8F1CA1ULL, 0x286796998746A7DCULL, 0x33777138D74398EFULL, 
            0x65DC63606845EBCBULL, 0xBB10CB57CE650510ULL, 0x11353C0AB6B76AE5ULL, 0xD01AED6EE19891F5ULL, 
            0x9F078B57E148792CULL, 0xDE1AFEB4B2D6BA2BULL, 0x0EFF44FA1BD650D4ULL, 0xBA664A2949BF0001ULL, 
            0x895122E7577F5D95ULL, 0x64573CFE6C62CFDEULL, 0x1023E3E2BA9E2B05ULL, 0x4C29B8082A8B09F7ULL, 
            0xC73848D0FC2FF161ULL, 0xFED251892CEB85A7ULL, 0x4A974A6F325BC830ULL, 0x5AC729E93091FA03ULL, 
            0xFAD116082615B839ULL, 0x9FF493AC939380FFULL, 0x73B2FB579D12C4F9ULL, 0x49E29E2290426573ULL, 
            0xBCA0CBB065315D72ULL, 0xFC65BAE39F66478FULL, 0x6475AE59AD7125A5ULL, 0x720BFC93EE0A695CULL
        },
        {
            0xABDA8EF48C0B48A3ULL, 0xC5B4B68497621AE8ULL, 0xEFE170241DB069BFULL, 0xAB508D346390E7BBULL, 
            0xDF600700842EA746ULL, 0xF5409E6C1DA0711FULL, 0xFCF5C7231A70BD36ULL, 0xD58DDE60F941D839ULL, 
            0x868FAF335AC77345ULL, 0x51A024C08693D547ULL, 0x9B3D484245BBA8BEULL, 0xA7E4BEAD52873ADEULL, 
            0x7F6492FE046CDC41ULL, 0x8E0AC2E714386092ULL, 0xA4225CAD65D9A1F6ULL, 0xF00F9CE14CE7E800ULL, 
            0x470DE74AB1325000ULL, 0x883B0FB49BFC1A99ULL, 0xBFEFD4B2525A5243ULL, 0x25A67D3E1043E14BULL, 
            0xFF8EAC320A58409AULL, 0x7A100F15009E916FULL, 0xE90F0CEE5A3B5A3EULL, 0x8237F9F47AC00203ULL, 
            0x155DB3711CD769B4ULL, 0x8F09438C1D667CF6ULL, 0x482955423F11FC80ULL, 0xD04F56385DDEEF79ULL, 
            0xBC37B03868D282A6ULL, 0x243775FDA490DE72ULL, 0x9B266AED6A933CE0ULL, 0x3F75FDA00B9E8F0FULL
        },
        {
            0x4D4952E4A055D8D1ULL, 0xA6768ED6B4D82A1FULL, 0x37D7ED1A12C7EF09ULL, 0x4E337259C9640588ULL, 
            0x2736695185F261A3ULL, 0x7AFE8EAC02E229C7ULL, 0x5741722D62C7BA7EULL, 0x8E55C0C7372FB3FFULL, 
            0x57A5CD725264484CULL, 0x7A99D0655E337277ULL, 0x5D61D377C16BED1BULL, 0xAFAF55490605A264ULL, 
            0xDD7DA44BE51FB0D7ULL, 0x5E04C189B39FAF41ULL, 0x46E5236A7927C7DBULL, 0xA3976B23D852A66BULL, 
            0x3454327A5E705D87ULL, 0xAED95955FB5CFEA8ULL, 0x877AB8437530E3AAULL, 0x36F83E6FBA6E3D35ULL, 
            0x093CB3215D6A935AULL, 0xD4D722EB9DC16EF9ULL, 0xA5F49052228ED74FULL, 0xA8393754ECB20DA4ULL, 
            0x8563EF9845992B0DULL, 0x7FF50E403A21964EULL, 0xEE58D2C12B1B050EULL, 0xF846FA82DF0D4C83ULL, 
            0xA20BCDC9E1141434ULL, 0xEE3EF7857E3F168FULL, 0x09B42B35CA98FCB2ULL, 0xEABB7CDB88FB33C2ULL
        },
        {
            0xAB4D8EBC210B61B7ULL, 0xDC35BD6AFD4BD8F0ULL, 0x67650AFF19FAF015ULL, 0x1866B702D64DE839ULL, 
            0xB12A37D8F0D7C115ULL, 0xE3B40CE55E95CBACULL, 0xDF10821C2BACA370ULL, 0x86AD9C84FB302959ULL, 
            0x7CDC7339912B75E1ULL, 0x0ECF209989934178ULL, 0x908D1122B4F62CE3ULL, 0x76FC2CBCA3A1D6B4ULL, 
            0x937EF6CD63A815A8ULL, 0x4984F46A025A3472ULL, 0x2C94D1A1266F304EULL, 0x12DFDC490B49BC2FULL, 
            0x00C9D6DEB29C0CB1ULL, 0xB5E2BD109EDBF342ULL, 0x7D6F5ADCD325BF8AULL, 0x9A10E3F19028AA42ULL, 
            0xFFA2AAD16C43E324ULL, 0x61E1C6329FC46647ULL, 0x101B700148618C8AULL, 0x6BCBFED7A48FAD7FULL, 
            0x51F33D3E24FAD83AULL, 0x23733007621AABEEULL, 0xF0F23005378C63D8ULL, 0x7B285731B66B04B8ULL, 
            0xD160F30C98F96F83ULL, 0x3C5F45D73D8DC365ULL, 0xE9BED0B495EA39C4ULL, 0x86F1894267CB7652ULL
        },
        {
            0xDEF39FE81CBACC49ULL, 0xC95AAF727B3FBEFBULL, 0x15DD8DE8DFF3662DULL, 0x7B9CC20F2ED943DFULL, 
            0x507B8F668292E124ULL, 0xBB8473C2477BA019ULL, 0xE8652C36F70AE700ULL, 0x997AEA16B8E15914ULL, 
            0x1BB87B813B67A9A5ULL, 0x739E75D77FF44DC6ULL, 0xBA256CF4DEF370C6ULL, 0x75964D1578D23B18ULL, 
            0x041E4DBF8143313CULL, 0xDEA4A5DDFF517DDCULL, 0xEE90C7FEAD659BA8ULL, 0xACF2D21E16E4FF28ULL, 
            0x4807E5FCB69A110FULL, 0x563B5D0BE9F62EEDULL, 0x6C8394AFA5B691B0ULL, 0xDDA5DC3346102344ULL, 
            0x4FF8EEC247722E5DULL, 0xAA7C3B6ADED2551AULL, 0xDB3CF952CB83FEF2ULL, 0xB56E9C41025D1DFFULL, 
            0x12DECD3144F25FA5ULL, 0x0D0B7ABC39E755FEULL, 0x126D6CA933934F45ULL, 0xE63711672D49838CULL, 
            0x48DF886781BC9026ULL, 0x2F94D37B3EDBBF83ULL, 0xE1401D34589C6AF4ULL, 0xCEA56DDA32E9E2CDULL
        }
    },
    {
        {
            0x362F68719B2CDA34ULL, 0x8B64EF8CA1C166ECULL, 0x079A2C5ECC9F11AFULL, 0xADE9A23CB20DE377ULL, 
            0xA31DAE447773D519ULL, 0xCC49058FC6885753ULL, 0x7D3E6B258C8D6691ULL, 0x7569DA6A7D5C261EULL, 
            0x6724A9DDA61E6144ULL, 0x5FCC54BEAF6C38AEULL, 0x298631B21A6DE9F6ULL, 0xF4DDC69CED89FF8FULL, 
            0x7E7005E6A3690E24ULL, 0xBF98C6E862BFF855ULL, 0xACEBBB990CAFCAA3ULL, 0x4D50C5427F9BC9B5ULL, 
            0x2F009D21DFFA659CULL, 0x036E64287CC6BA7EULL, 0x83DC1F6FF3C49ECEULL, 0x04428C4A50BB81D8ULL, 
            0xDA7364DD93DA235CULL, 0x71D110F990001C5AULL, 0x2E1D2AAB20935A66ULL, 0x294B7990EA8F0EE1ULL, 
            0x6F794F69B7C6BDBCULL, 0x3A583264D08F3614ULL, 0x06985CDE96604628ULL, 0xA6B9FBFEEF196988ULL, 
            0x98CAB81B93F7CC15ULL, 0xFCD0F9F7156667ACULL, 0xA2E7B1C2DE590115ULL, 0x55AC368A333A866DULL
        },
        {
            0xE4A83F1585E500FAULL, 0x3B2669EF0E1CA738ULL, 0x21080BC9F21D1EA2ULL, 0xF9F0B41238727B91ULL, 
            0x8D14D3051563C498ULL, 0x5F824713E5C56108ULL, 0xD14ED930C61F9406ULL, 0x066D2DBBE545E156ULL, 
            0x57DD0744830503AFULL, 0x9FA3A9FBA9328A8CULL, 0x535F6D3C53DEA9B9ULL, 0x08E5D655636CBE54ULL, 
            0xAF82906209E92B19ULL, 0x0A2084F91ACE2083ULL, 0x1EAE16B61979B74AULL, 0x76D5B2EBD048F973ULL, 
            0x43D14E730F8C2B29ULL, 0x2E4B61A9E90250A1ULL, 0xCA541947EF514B4FULL, 0xEA7B58FDE6F963AAULL, 
            0x2087E3F2A9D96C8CULL, 0xD7B40390ACE45C76ULL, 0x70E8BF7DAA0F4156ULL, 0x51CFFE6DF0CD9DEAULL, 
            0x03DEE3456B29CEE9ULL, 0x4266CB64F9A56FFAULL, 0xDD2431A8BCA0122EULL, 0x9AF3EDFCE60F7C43ULL, 
            0x8B05FECA9A6C2495ULL, 0x865D51E934961BFDULL, 0xD2F2026C326FCBACULL, 0x91482CAD31AE67BDULL
        },
        {
            0x316E8F5F753E5FC3ULL, 0x055292EF0F2D4983ULL, 0xEA33739C045A66C8ULL, 0xD821832469BF865FULL, 
            0xA03ED34CCEB5D54CULL, 0x848210D428B3CA42ULL, 0x8219C8DE48D2E96EULL, 0xAC68EDC1D557AFCEULL, 
            0xBC09D6AA8BF0DF0CULL, 0xDB7A6ADD90CF8D21ULL, 0x9F66C41471CAEE98ULL, 0x30B9423E2D00EBCEULL, 
            0x8956A84E89AF2FDCULL, 0x5BA054BE64092D23ULL, 0x3D69A0C1E5CBDDFBULL, 0xACCDDF28FFE8606CULL, 
            0x66C5C1F32F522B16ULL, 0x8D48790537C5254DULL, 0x6AF478525B92A253ULL, 0x7D5B621000F42297ULL, 
            0x462EBFDEF9EAED14ULL, 0x7936D05AD0585E79ULL, 0xE969132AB185EA50ULL, 0xBE1F9C0F917A7485ULL, 
            0x14CA280066C9FF97ULL, 0x8890CD44F042E824ULL, 0x512A3BCF9A4268FCULL, 0xF1392EDA7893C049ULL, 
            0x778861501AD1E93BULL, 0xF4E08101772AE5E4ULL, 0xD7580E1AABBF6C4BULL, 0xB6C0D4DE9B5827FAULL
        },
        {
            0xC9EB5EE5C78DD3ACULL, 0x75E3FA540F45946BULL, 0xD3DF51A8061ACEE3ULL, 0x43A48052E4E949E9ULL, 
            0xA43FCC921FEA2EA9ULL, 0x55D51753F2A0126EULL, 0xCF705F0663E47054ULL, 0x27415D379E9C0944ULL, 
            0x327F626A6D254911ULL, 0x76A4DA01E3839089ULL, 0xEFEC649D652A5B6FULL, 0x8067773700039006ULL, 
            0x21515A3FF7BB00E1ULL, 0x0AD2D4AEA421E3FFULL, 0x60543AE15B972CC8ULL, 0xA3B6F3F06A738559ULL, 
            0x10EF8449745E7455ULL, 0x703EB875B335AF58ULL, 0xFE7255E64BC23BF6ULL, 0x1724E6BC30F3DD6AULL, 
            0xF5F39E31A452436AULL, 0xF5A3200FD611EA36ULL, 0x780CB5D97757B1E4ULL, 0x2BB6785E75138053ULL, 
            0x780EA0A3BAF6AD82ULL, 0x21A4F102D6AAA0C2ULL, 0x6EEFBC6CD25D0B11ULL, 0x4A4FB7B06BD3DB10ULL, 
            0xE0368C5C669F7740ULL, 0x197C62D3D50AC678ULL, 0xCFAE76BDFBD95E36ULL, 0x627B591335392ABFULL
        },
        {
            0x8E2B8B71C8AFAF5DULL, 0xB47182F62C7AB057ULL, 0x819D347818A67F38ULL, 0x8E71C6A86D7BD5B9ULL, 
            0xF334BE424ED6222DULL, 0xD938D243C6D85086ULL, 0x982202530708E7A4ULL, 0x79D0C0495903441AULL, 
            0x13B1DB6AEF70E2E3ULL, 0x88D50BB535063DC2ULL, 0xDBC4D6E593C5DDD0ULL, 0x50BEC890D6639327ULL, 
            0x1AF1F05BA264ED31ULL, 0xD2F2A411D71D7FF2ULL, 0x4A5773DA50CE74FCULL, 0x62C208D0ACB7FAE9ULL, 
            0x00B64A5F03F96C60ULL, 0x975270C3227FEBA8ULL, 0x2D18B0ADAB69DE2CULL, 0x6FE65F775C5D291DULL, 
            0x8C7620373433B527ULL, 0x1CA457DE1D65B445ULL, 0x03476147D813A3B8ULL, 0x5157284FD9C18CABULL, 
            0xF10BD642FDB1E1EDULL, 0x243A72E09FD632D0ULL, 0xB0E1107BD62FD464ULL, 0x26BEDF533E3C2263ULL, 
            0x360869BB440409C4ULL, 0x090D96BC1E775150ULL, 0xE67AEE76885BE185ULL, 0xEBB8446CB36C1B57ULL
        },
        {
            0xACBDD2D2E7B85048ULL, 0xCD94879B1EA864DEULL, 0x4175D719171AA069ULL, 0xDF5FD72C2A9991A0ULL, 
            0xE0BF46C250154444ULL, 0x1ACB7F5F90FAD133ULL, 0xA11B1619D32559AEULL, 0xF6CBDDD06722EEBDULL, 
            0x05CD020B0C3F6D67ULL, 0x15C34F916CC7AE10ULL, 0xCF84C94256FF3EE6ULL, 0xAE7BBE3465B82B50ULL, 
            0x76032F7C82EC2B6CULL, 0xC5AAE4A18F488DB6ULL, 0x20AFEC6E65BCF9D1ULL, 0xDE783132E3C3933EULL, 
            0x073D3EE6B0B91E1EULL, 0x19AD8E64E3BEC332ULL, 0xBCCEB423404B2E8BULL, 0x64374622C1A1D7BAULL, 
            0x03397D5840E6A67FULL, 0xA15E34966DBF5204ULL, 0x9C06B2A9E34A350EULL, 0x98B17B1E81E97719ULL, 
            0x6680F4DD711173AEULL, 0xDF786DC7D31BB096ULL, 0xE31AA50B19DF04B2ULL, 0xAB7B8F049524EFE8ULL, 
            0xD40A4AA57B79412BULL, 0xAC4159CA82D552CEULL, 0xBA6DDB01826AB3F3ULL, 0x47B145A0430C03A5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kSeedConstants = {
    0x4726F0BE62B4FE10ULL,
    0xBD26AF18B2D4B6C8ULL,
    0x8F182E22CE84B988ULL,
    0x4726F0BE62B4FE10ULL,
    0xBD26AF18B2D4B6C8ULL,
    0x8F182E22CE84B988ULL,
    0xF844239CB2B083B6ULL,
    0xDF877E3B4B2D3DCBULL,
    0x9C,
    0xD3,
    0x24,
    0x2C,
    0xC3,
    0xF7,
    0xB0,
    0x87
};

const TwistDomainSaltSet TwistExpander_Suhail::kTwistSalts = {
    {
        {
            0xE7A379383E4D3724ULL, 0xEDC3FA19F688E7FCULL, 0x80EB79D5E4CC75EAULL, 0x20095B59CE8F95E6ULL, 
            0xD985F25B63EFE60DULL, 0x3B78F4A7E4354FB4ULL, 0xC1BD40CEA212BB50ULL, 0x49624B381E255F0AULL, 
            0x7E883193FA0F617DULL, 0x818CF25C2E2CEC3FULL, 0xAC148178387B2840ULL, 0xC959C183F21CC64FULL, 
            0x76F94433713F3F42ULL, 0x8F883527BACCEE6EULL, 0x4F1D34D564112561ULL, 0xA5D5DA64FB0AF527ULL, 
            0xDD5B7A7937D8D605ULL, 0x118C1FDF01018B9DULL, 0xE0B1815097CE1530ULL, 0x285CF5D9D0144509ULL, 
            0x929086052AF3583DULL, 0xC402C07306144EDEULL, 0xA9E9081FF1E477C5ULL, 0xE6DD78823778E7D4ULL, 
            0x6EB0D0ECE1A83CCFULL, 0xA41272F417797DDAULL, 0x28872DC9EB5B20A3ULL, 0x2EC65404CB5CCEC3ULL, 
            0x522CFF8A3B592821ULL, 0x7066428CCDB91418ULL, 0x102F2AF1E20BE044ULL, 0x634C5B96E13EFF0BULL
        },
        {
            0xF9314367030D86BAULL, 0x9F148FD51FC87B1DULL, 0x91584C8B59150FADULL, 0x5FEA1234A1A68763ULL, 
            0xAB410A477FAD58A6ULL, 0x63EA8C47A418BEA4ULL, 0xD11CED571F59E0B6ULL, 0x2CD705927F4D5979ULL, 
            0x5180FF4A509B68CAULL, 0x3181996EFA35156DULL, 0x3A2383E365900029ULL, 0x32EA7958C0245F94ULL, 
            0x6B86910A0796D954ULL, 0x96E97B394C75B306ULL, 0x6EC680C3E1A64DAFULL, 0x905AC35E358C5990ULL, 
            0x2C4DCEE0E20F7767ULL, 0x92931EBB646B00FEULL, 0x4A88A124FB9D44A6ULL, 0xC7B55B3ADFE168E3ULL, 
            0x8B63E9366A9BB235ULL, 0x8635584C3D807A95ULL, 0xDF7B5EB9C7DB46C7ULL, 0xFE08EAD2DD4CDAF8ULL, 
            0x5B8DCB2031D0A25FULL, 0xB6CAD13007698C81ULL, 0x346E88ADD8A86654ULL, 0x7D6BEA0182E5CBFAULL, 
            0x1FD0862F13698A03ULL, 0x8753F8524887E3C2ULL, 0xED47B9CB2BD2273EULL, 0x6D55D5A6CBD218FCULL
        },
        {
            0x6C4410F6058B96B9ULL, 0x3B2A97973045D640ULL, 0xA280D4AC4960F25AULL, 0xE97DDE2744F32CEAULL, 
            0x94FC407B9D139FCFULL, 0xEABDEFF249D7C1F7ULL, 0x747FC46E77D83CF3ULL, 0x8203D7F29E929E86ULL, 
            0x8FF57B9976B5B1AFULL, 0x5E08CF4CCC3BD664ULL, 0x833F4178B79E5538ULL, 0x375923E875EBB6AEULL, 
            0xBC17EFCE0D2B359DULL, 0x38EF0EF9D3F7FCB3ULL, 0x0BE9A203099D33C1ULL, 0x525FB68B072CCA74ULL, 
            0x999B4ABDDC522A97ULL, 0x33E1BF1472EF2725ULL, 0xFDD731E11BCC7401ULL, 0x3F90F6444C61C3F2ULL, 
            0x2EA3B25665E9D4E6ULL, 0xAF654C60ACC0F045ULL, 0x1A92B7DDD8B43F36ULL, 0x6D11F6BED01D37AAULL, 
            0x3DF9DA70509E36A8ULL, 0x6B870DD0A9BE4DB4ULL, 0x274E9BB855ACE666ULL, 0xE2AF9BB2923476AEULL, 
            0x61348181E9D30020ULL, 0x0FA856E6D14C88CEULL, 0x04C305739C3937F0ULL, 0x1CEFC7A84724644CULL
        },
        {
            0xF0E914F40BE19385ULL, 0x37555BB0D5D9950AULL, 0x55BB2694672B944BULL, 0xA975F8392114E32FULL, 
            0x695A618597F4B218ULL, 0xAD269C2C9102F989ULL, 0x587CE4C2A8713063ULL, 0x693297D0D982F300ULL, 
            0xC051AAAB2DCC3F69ULL, 0x9D54197F0EEED701ULL, 0x9B46A87E4172407AULL, 0x5BA61C7A66C75952ULL, 
            0x7E8B6BF81C91497FULL, 0xEBFBB74826DFC204ULL, 0x36FADA6B24C727C3ULL, 0xDF0F92391BA7722AULL, 
            0x49B384EEA008DC4BULL, 0x88F0EDA6FAF753F6ULL, 0x7FE9510C592FDBA3ULL, 0xD7A0307DB0D6D3F1ULL, 
            0xEA7649B8A1E874CDULL, 0xF4FDD5F187F89EB5ULL, 0xD2EF6FA14815D3D7ULL, 0x7E5C47913141571AULL, 
            0x313F2171E0092788ULL, 0x321F3EE3392D0BA5ULL, 0xF7EBBC9374BE05F8ULL, 0x798226ED52D3654DULL, 
            0x5B34D52A83FF6A57ULL, 0x6034BB4315572EE7ULL, 0xF0197E936B2FA291ULL, 0xA116939C014DE71CULL
        },
        {
            0xA6925F00729ED9AFULL, 0x82A32AB97C4FC40FULL, 0x426F4E9BEC3625ABULL, 0x739948B8F45E0B1EULL, 
            0x7BBC3954B7CDE74AULL, 0x376D40AE9D6D706DULL, 0xD58498E787FABF4BULL, 0x80A79D1C5DEA66A3ULL, 
            0x1A784A400E78BE67ULL, 0xD90C71C6BBF03B62ULL, 0x7D425C059B8E70B5ULL, 0x050E9C3F1B085DABULL, 
            0xDD1AFD9E089783D9ULL, 0xEEE12752ED87284CULL, 0x6740C9EF035E7250ULL, 0x8A5AD1BCEA6FD13FULL, 
            0xF16D7DE042D2A6F1ULL, 0x5311E3B2354976A2ULL, 0x4C53A7E6052DA2C0ULL, 0xA0C91571BDAC5A60ULL, 
            0xD57713358315BDE7ULL, 0x5AD766AD46C2731CULL, 0x6D74A73BF76DBA0FULL, 0xADEA07A8CE2B4A34ULL, 
            0x4F9CB5398BA61FF0ULL, 0xF777822A915BEE46ULL, 0x166C2259497429EBULL, 0x5DB372E34C309B47ULL, 
            0x221BF1AE7DE353C6ULL, 0x571C18060E879FF9ULL, 0xD20279FAE1D11D1CULL, 0xDA4E9990610FC23BULL
        },
        {
            0x4118CD92AF0BCB37ULL, 0x006757CAA3914B3AULL, 0xE63A4B27EA4958A3ULL, 0x5A8DDC6974B93740ULL, 
            0x33962FD6D8344E2CULL, 0x711984F67151F132ULL, 0x48A2E3EB690E2BAEULL, 0xD8B709D574A05620ULL, 
            0xD8823FF061CBA1ADULL, 0x46A0F8C839A0ECD0ULL, 0x88E67B8ADECC12B1ULL, 0x164609D6969305B6ULL, 
            0xD171C9BA9CE0191DULL, 0xA7BAA25B8E58DB4DULL, 0xC4F515B1FC15D2FEULL, 0x87B35E5962BFC17BULL, 
            0xE03D813690B2DCE3ULL, 0x7A6634DB778672F6ULL, 0x659F3DDCE3597FE9ULL, 0xAFDBAC6E181BF430ULL, 
            0x12286A8DC16ECE1CULL, 0x15FBFF24BAAB85DAULL, 0xD309EC0C3F82716BULL, 0xA17AABD679D16F2DULL, 
            0xA58006EC7F556D01ULL, 0xE67B5C5DC9F94F2DULL, 0xE033381C556A74B0ULL, 0xE7E54CAEB5E2E89DULL, 
            0x981F86A43FCCD063ULL, 0xB2D8E06CF19035CEULL, 0xC3184767D840EEB4ULL, 0x4B0ED91F6440844AULL
        }
    },
    {
        {
            0xA6C9A02ED019AA06ULL, 0x7D18C24C46C1573BULL, 0x406A19044A2C41D5ULL, 0xEB14CEC3A8D4DDEEULL, 
            0x6D3C95A1ECEE30D0ULL, 0x243CC402D961FACBULL, 0xA0EBC5E1C6A948F5ULL, 0x7E81C4ACF7FFE3F1ULL, 
            0x1B541CFDB4EA73E7ULL, 0xA90B478A3F8423FFULL, 0x8018132D14C9E498ULL, 0xA284DC94451B222EULL, 
            0x70B5EEAF7AF3C81FULL, 0xFD1C028C5CA845BBULL, 0x502DFD79311F3D00ULL, 0xBC918B10341CA541ULL, 
            0xBD1350109711E0FDULL, 0x42C2DE57421CBB52ULL, 0xB533FDF6580645C4ULL, 0x016B84BE08B9C46BULL, 
            0xDB7DA7184AB3248CULL, 0x604111421AA6156BULL, 0xA337B4EF9118818AULL, 0x7B26F6B5FBF01759ULL, 
            0x5E7C7DED4F37CCAAULL, 0x1365CAFBE7411977ULL, 0x80EE1659645EF965ULL, 0xB56F1C0B88FE3F3CULL, 
            0xDD59ACED2E1CF7E5ULL, 0x910361CB47021F38ULL, 0x68F5E30082408D00ULL, 0x80C3CDF1255CDC3CULL
        },
        {
            0xDD8ED801D1FF4474ULL, 0x2A9F9CF4B5597362ULL, 0xF14FE2474D68E5A8ULL, 0xCF108140EBCE758FULL, 
            0x6F7BECFBD48CF90BULL, 0x699BA1D189932878ULL, 0x65EC91CD85470FC6ULL, 0x2A387B259C092F37ULL, 
            0x6E2ADA4D4240CB14ULL, 0xE5C3D380C8F03FBFULL, 0x545AF6A6F8CFA197ULL, 0x4BBB42B6D685D065ULL, 
            0x5E91C688C0D7C226ULL, 0x1E7C34A44CE984F1ULL, 0xC35EAA37ABBD01F1ULL, 0xB9386C2CFDE53E74ULL, 
            0xFD16787535F0EB5BULL, 0x162C26009E843233ULL, 0xC12AC2882104DF6DULL, 0x7C88FCD52F802212ULL, 
            0xC2ABDFB10E98400CULL, 0x04991B971CBAD037ULL, 0x0F74523637174EB5ULL, 0xCF7811402933C827ULL, 
            0x3042E5528FE25F72ULL, 0x9A1CD93D291A4943ULL, 0xAFDF3F465125DB59ULL, 0x3007ED114D37B18DULL, 
            0xC967156C252CD277ULL, 0x76035CD12035AD00ULL, 0x9250AF4452A029E0ULL, 0x23AD9E8FB1388DB9ULL
        },
        {
            0x4B2B4C3A3EAE76A0ULL, 0x2B19D73A96E68C13ULL, 0xE886DE5FA14A8788ULL, 0xEF363A69392412A0ULL, 
            0x566078C9A7D57172ULL, 0x73EDB24AD739392CULL, 0x1A8CE339ABBAF069ULL, 0x771F195C5F173C17ULL, 
            0xEB294994FE4405E5ULL, 0x26B7146720120B75ULL, 0x94AC84C83A545D47ULL, 0x41587245AD974D82ULL, 
            0x70870F01A6A0B806ULL, 0x2B4B054EDD4563EFULL, 0xEABD86B1661BFB34ULL, 0xB822570D3A1E2AB4ULL, 
            0xD119A91614EDABD5ULL, 0xC6C6A633B7CA11DBULL, 0x9E73FFCDDDF92E4BULL, 0xC740B5594A1E36E2ULL, 
            0x7593B3327E7BDDF0ULL, 0x82845E99310E5AEFULL, 0x79FC0E6426BBD58AULL, 0xAF9AB1E8C1F1CD1CULL, 
            0x819F803382C97FD9ULL, 0xCFBE81FF6606025CULL, 0x6FAAA5230898EE07ULL, 0x43404E5EE1521BDBULL, 
            0xC9085CA6A465BDB8ULL, 0xBCFEA9707B7C85BBULL, 0xA07CCCFA31822548ULL, 0x9F6D9FA64F255B8CULL
        },
        {
            0x3B5FFB3C20E9D844ULL, 0xF99BA6421050B1BAULL, 0xC04F324E1C0D0CD7ULL, 0x84F54EAE1BD7B593ULL, 
            0xD9B3083FC604463DULL, 0x978EFD8EBCDB268AULL, 0x31392C1C21D23E20ULL, 0x8B4C548DA20128CEULL, 
            0x7A8738A0645E9D93ULL, 0xC580FCA5A42E9C34ULL, 0xB362742FB74C8893ULL, 0x53B1B8289327346EULL, 
            0x76B35FFC890819EFULL, 0x4DDAAADC063E88F1ULL, 0xEB4C0C2CC4FAFFDDULL, 0xACCA3F1CD52BE72EULL, 
            0x567F3F9D100B1834ULL, 0x1CA35502CF21ADBAULL, 0x618C0F230BB184D2ULL, 0x6CBDEEEED0D09FD5ULL, 
            0xD1677A3E88B2475EULL, 0x664C3E4979F82C49ULL, 0xA83ED77E50BEB350ULL, 0xCCC312E49BEEA014ULL, 
            0xFF1C0B3BF10D5F9CULL, 0x3F96BA201EBBED9AULL, 0xD5E6C282C9BF40A8ULL, 0xED4EA76995BD7374ULL, 
            0xA4B07A8D6BE20205ULL, 0xD2CCA1EF32EBECEBULL, 0x2949F7F8D3773A10ULL, 0x128A4C7D5E882FF8ULL
        },
        {
            0x616767D1469BA6C1ULL, 0x23036CA3BF2F62DCULL, 0x3046ED8C0EFD6873ULL, 0xB8B7FB40D6B508E4ULL, 
            0x8EAA38867572F95DULL, 0x415116648B995837ULL, 0x20EC7AB229015A06ULL, 0x5D5C6DF049B0A98DULL, 
            0x59FCE433F81C9EC3ULL, 0x361EAA57BC2D8531ULL, 0x81C03A2F69938AE9ULL, 0x650C5ABFD790AA51ULL, 
            0x21143AE7C2E7D2CAULL, 0xB17AADFFE924E43DULL, 0x686BFE0FC76929E1ULL, 0x81A038CBED8FC38AULL, 
            0x65B1AFC961CE5D97ULL, 0xB6473F0A6B9C963EULL, 0x1766D4D8D211DA29ULL, 0x98F927DE6F7C8C3FULL, 
            0x0107C39CC6336E47ULL, 0x7574D64477E50E45ULL, 0x02B8550792380959ULL, 0x57F8B5AF08D8E3CFULL, 
            0x12F8206FAC888AA3ULL, 0x7AC468C8082A1257ULL, 0x0D65E247A06C6D32ULL, 0x6677502628716CC2ULL, 
            0x3425D9D65EFA9154ULL, 0xCB38374965D9D9FFULL, 0x286F1FC1443D7384ULL, 0x4978E804E21CEE2FULL
        },
        {
            0xF486A82D63572AD9ULL, 0xC4BEAA65159BC0DDULL, 0xD2D0CDE324F17ACEULL, 0x99BF678AAA464748ULL, 
            0x75E7BDBFA665E5DDULL, 0x8F4039D787C8A4B9ULL, 0x26731BFAED4D45F7ULL, 0xC34082652EDDAC8DULL, 
            0x067A046527039658ULL, 0x279C0D7E6D97458DULL, 0x48953B52B74103FCULL, 0xA6D945030C456D5AULL, 
            0x6EF3747CCF7C816AULL, 0x7CD9474CC076DA77ULL, 0x1FB19FF342C26B26ULL, 0xA4B727149752085EULL, 
            0x84CDFF4D93BE498EULL, 0x792218585F8B4590ULL, 0x0DF76A0B5C2FFECAULL, 0x8633F29938A10F15ULL, 
            0xF695761AB7B0AF0AULL, 0x4F864CFF332A1E1EULL, 0x05718F14F9CA7101ULL, 0x8965F8C4CFE1AD87ULL, 
            0xB83AA9FCDA203A33ULL, 0xB52A738590E728D6ULL, 0x2DD8600061089282ULL, 0x42E9C5B397C2763EULL, 
            0x4F4E9A5B3B95C5BDULL, 0xEB98B799F3FC7A05ULL, 0x8955133BB9EF2FDCULL, 0x9F9F8247B5DF1A25ULL
        }
    },
    {
        {
            0x6C69739A555BAA7FULL, 0x4447D5ABBBB26598ULL, 0x71394BA122FB1841ULL, 0xD7B511AEE2D5D416ULL, 
            0x08D02A22EB38FBF5ULL, 0x35E074A8489D729AULL, 0x9FA8F4A526EA76D5ULL, 0x2CD10D26A802DD6EULL, 
            0x2727B23B84FC56F6ULL, 0x8B4A82F403E3AF62ULL, 0x9299E9292393399FULL, 0x739D5F784C7EB640ULL, 
            0x39F09976E4775EA4ULL, 0x8BD37D6CA50FBA3CULL, 0xA8A602AFCAA631E6ULL, 0x8D01E0D71ED73105ULL, 
            0x57B41E7F8B222DDFULL, 0x10FF3E476701F90EULL, 0x27E8CD9B2DB35DC2ULL, 0xC41FD3813892AC25ULL, 
            0x893D42915257CE92ULL, 0xF0321727A2D4801AULL, 0xABA883498A94F21FULL, 0xB176FA5F91859BF9ULL, 
            0xEBFA9457B17E671CULL, 0xE47667EE6000DD8CULL, 0xEE3A6B036B1BF75DULL, 0xA224E116EA4D381CULL, 
            0xBE957A072FB1304AULL, 0xEB0CAF83ACCF45ACULL, 0x54879561A487D2BBULL, 0x8729A00D238B6F3DULL
        },
        {
            0x51DAE69A0DC5143CULL, 0x458FDF21D2B4394CULL, 0xA00333A8418BA5F9ULL, 0x1EFEE09F070A118FULL, 
            0xC15560F4DB6D72B1ULL, 0x7573FCD1B4B6D406ULL, 0xF9C26E4D6038CA50ULL, 0x5C4C25C49845031AULL, 
            0x01CF2FBFB161FBBDULL, 0xB92FE3571995A645ULL, 0x1342C99D1DDB4668ULL, 0xA777734362B8B933ULL, 
            0x8FF338050778B57CULL, 0x1145DEB9734D4A7BULL, 0xF0831A2508337E39ULL, 0x3D88FEFA1D1967B1ULL, 
            0x796F764191FEEDC3ULL, 0xBEC213A3E41A0B2DULL, 0xE44E9443EBA13EECULL, 0xC186E1BC49D8263DULL, 
            0x7C75553950A82608ULL, 0x2B5DBFB23CD055DEULL, 0x0653ACBDCF223975ULL, 0xEFDC7475BFA2C6C5ULL, 
            0xACEBDA7A4747498BULL, 0xFB9E6FC1E57732C2ULL, 0x2443EEAADDCB74AAULL, 0x70F1BF922BBDC30EULL, 
            0x2BF2DC93D1E90EC4ULL, 0x9B0CC35D4FEE7959ULL, 0xEFD3FA534C972A70ULL, 0xB61D86A78B69AD07ULL
        },
        {
            0x14C64F89CE0343DFULL, 0x256D991E8F125A20ULL, 0x0F9BE28B305616E7ULL, 0x295DB0AC9383724AULL, 
            0x5F1F3371BD0065DCULL, 0x94EC5CD542B2C206ULL, 0x1F9FBB374C57EB77ULL, 0x6F1C05BED38E7E64ULL, 
            0x3142B4D902E7C735ULL, 0x7A81C99C9B4E9273ULL, 0xE3F0CB620C7A5D37ULL, 0xA1FD1642B781A06AULL, 
            0x97BE431CC5A223E2ULL, 0xDA2808E70864799EULL, 0x813D9D68322F82D1ULL, 0x293D9E9A3B89BF7AULL, 
            0xEB1E31B214E88451ULL, 0x92B9746D28F1EF76ULL, 0x1DA0E395C5CD0DE7ULL, 0x9DE0F392720D55CDULL, 
            0x7A9BFBF64D65066EULL, 0x7C13F47644428151ULL, 0x68EDE88E1E9CB1FCULL, 0xEC181A92CE52E1B0ULL, 
            0x97E84C1A46DC1242ULL, 0x5F357F9CC2CFFDF3ULL, 0x092A23D21D6A762BULL, 0x7AD1903C4E6FD351ULL, 
            0x454D1E581A571B3BULL, 0xAA09362B9460CF47ULL, 0x32B79C9DDF0E40BFULL, 0x722248509E0DF469ULL
        },
        {
            0x0D48B0ECB66EBD55ULL, 0xDDB6AF405D665302ULL, 0xBB71F5ABA69A6184ULL, 0x647FA3A61766CBD0ULL, 
            0x872675D9B8B18D30ULL, 0xA43CD265E67F25D7ULL, 0xEE7223A752C3BCF3ULL, 0xF6F2E764EEB7536EULL, 
            0x62DDBF60E0814B77ULL, 0x62CE4E0E42973957ULL, 0x87092BF0A247D3E6ULL, 0xDDD41FBBB0185615ULL, 
            0x3F6F9B5A64132D8CULL, 0xCEE47DCD0BAB3647ULL, 0xFBDC10418133D633ULL, 0x9188148E208CCE04ULL, 
            0x6BEC8B808A38FEF9ULL, 0xFA4AD98E63627BD2ULL, 0xAEC9BA547A7A116CULL, 0xEC3A93278AE9D8DAULL, 
            0x26AE8C71A7CAE5C0ULL, 0x5CE328A4E632C2B6ULL, 0x4A8197CFB36BAAD1ULL, 0x0959E52E03390EEEULL, 
            0x148987C543D46F44ULL, 0xC7086F507C46CAD3ULL, 0xBAB890D6B2472757ULL, 0x67C102B0AACE0D40ULL, 
            0x3AADB5ADEC3D3A9AULL, 0xC02BC27C59E29492ULL, 0x578BAF02C87FFBA2ULL, 0x008A75D8487C430AULL
        },
        {
            0x1E09624E3DD000C3ULL, 0x06FA5306D40006A5ULL, 0x95BE24CEDA90077BULL, 0x317CDA5B1C70638AULL, 
            0x1ACADDAB8FC87BF7ULL, 0xE8D5989430E6CB04ULL, 0x58789BBF2A0865A5ULL, 0x8A73C859DB6B2E0FULL, 
            0x99A23BF8C4BB54F6ULL, 0x38EC2EE462D1E503ULL, 0xFFFA494E6BAB12E6ULL, 0x72FB3D668C018CE1ULL, 
            0x9606C1E61437618DULL, 0x8F5D355BDB9BF5FFULL, 0x1187CA7EDD144921ULL, 0x0B956A1315BB9C3DULL, 
            0xED87048CBB556814ULL, 0x7C036BCBA4E1C51FULL, 0x07E527EA7E83D7A2ULL, 0xB3A41212B295DEF1ULL, 
            0x8542CFB2E1D98A41ULL, 0x833DAB269162B723ULL, 0x7562E738DBDB6790ULL, 0x581BD437C2B208B4ULL, 
            0x7637DAAEDCDA4968ULL, 0x5262DE9098292344ULL, 0x694EBA3BD250282CULL, 0x809C2A8CBD9CAEBAULL, 
            0x752DD6061FEE4B82ULL, 0x0AECCCD68D67AD67ULL, 0x721608996777933EULL, 0x2A347481D925091FULL
        },
        {
            0x792CD99F38C3F0B7ULL, 0x635F55D04AF4EADDULL, 0x5F1EB3202390A19AULL, 0x3833521300EC3068ULL, 
            0xB7B5B10CC6E25E6EULL, 0x1E91D1C60DF9CDE9ULL, 0xBD9F458BA12952E6ULL, 0x502E5C3F386897FAULL, 
            0x87C36B5F85954DE6ULL, 0xF15A103D8C93AE3BULL, 0x9C71EB9917C5E6A9ULL, 0x6A225F2E794BBBE6ULL, 
            0xC56F0D8E41C743F7ULL, 0x85D3678A36A33188ULL, 0xC7F85347C6A44FE3ULL, 0xDDB90197DF7EB77FULL, 
            0x3498AE9FAF531E1EULL, 0x9CFC95886290ED30ULL, 0x00CBB7F193F160EEULL, 0x83A3802872F582A7ULL, 
            0xFB0D1F3A32DA4D4AULL, 0xBDF7F7962AE00FD8ULL, 0xA6C7B52B55B07DE8ULL, 0x90DCAE4AD5B09C0FULL, 
            0x1EF0B2F0A47BE413ULL, 0xD09DFA6A288B3073ULL, 0xA77E2B6C4DB4F2B1ULL, 0x6EB7402F570DF308ULL, 
            0xC63A5316B08FA34DULL, 0x96033EF4234E5CACULL, 0xAA20783BABAD8905ULL, 0xC3EC1F92601935A7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kTwistConstants = {
    0x8D6504A3EC12BB6CULL,
    0x8014A07AA5388E89ULL,
    0x087CD2216D8BB08CULL,
    0x8D6504A3EC12BB6CULL,
    0x8014A07AA5388E89ULL,
    0x087CD2216D8BB08CULL,
    0x01082A9391C8F981ULL,
    0x1DEFFE25772251B0ULL,
    0x52,
    0xD3,
    0x86,
    0x4D,
    0xB0,
    0x12,
    0x6A,
    0xB9
};

