#include "TwistExpander_Arcturus.hpp"
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

TwistExpander_Arcturus::TwistExpander_Arcturus()
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

void TwistExpander_Arcturus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC37D838119E1B1BAULL; std::uint64_t aIngress = 0xE1130A00C5BC7F86ULL; std::uint64_t aCarry = 0xD034DA460691697DULL;

    std::uint64_t aWandererA = 0xD673974CAE1712B3ULL; std::uint64_t aWandererB = 0xABF21DFBD84A5EE2ULL; std::uint64_t aWandererC = 0x84A79CAC819D0200ULL; std::uint64_t aWandererD = 0xEE5A33A1155F20BCULL;
    std::uint64_t aWandererE = 0xD8BBE8079A3E2E58ULL; std::uint64_t aWandererF = 0x8219CB2444734CE2ULL; std::uint64_t aWandererG = 0xD9DE77F96A4DF36DULL; std::uint64_t aWandererH = 0xB861EB42386274DFULL;
    std::uint64_t aWandererI = 0xC3ABBEEFB53AE0E0ULL; std::uint64_t aWandererJ = 0xFDCCA03B8FB514FEULL; std::uint64_t aWandererK = 0xCF733A5097790EE2ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE6D022EA48D7EEC1ULL;
        aCarry = 0xF7231C627E71EE45ULL;
        aWandererA = 0x8A9307DF6EE98D20ULL;
        aWandererB = 0xB9CB71EB47D20BE0ULL;
        aWandererC = 0xFA636E029A1F5931ULL;
        aWandererD = 0xA04329E4AC946B96ULL;
        aWandererE = 0xCDBC63A4ACBE6299ULL;
        aWandererF = 0xDCF6D91B8784F123ULL;
        aWandererG = 0xBE9B8583BCFDE84EULL;
        aWandererH = 0xDE52100E397E46B2ULL;
        aWandererI = 0xF0C55C20D46B850FULL;
        aWandererJ = 0xB1A9C6D7B854A45BULL;
        aWandererK = 0xB780ABA49439512DULL;
    TwistExpander_Arcturus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE042B701CC3FA73EULL; std::uint64_t aIngress = 0x97480CD5CC5D0913ULL; std::uint64_t aCarry = 0xC5EB8684670D77B3ULL;

    std::uint64_t aWandererA = 0x9850FF7F51AAA014ULL; std::uint64_t aWandererB = 0xEEDA02722D590D83ULL; std::uint64_t aWandererC = 0xD44BD2F97C7285A7ULL; std::uint64_t aWandererD = 0xA1EE429974AA2116ULL;
    std::uint64_t aWandererE = 0xBDB7B089833CDA5FULL; std::uint64_t aWandererF = 0xD396D40A21DBA28DULL; std::uint64_t aWandererG = 0xD299B4B06C5F2666ULL; std::uint64_t aWandererH = 0x9BE875E64CDA7675ULL;
    std::uint64_t aWandererI = 0xAB4D28C12B0D1916ULL; std::uint64_t aWandererJ = 0xF68396B9F9330BE8ULL; std::uint64_t aWandererK = 0xA20D81F889C9C13DULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9166AF44964FDE40ULL;
        aCarry = 0xA7966FE8A8DE6727ULL;
        aWandererA = 0xAF4CF761FF2D8E89ULL;
        aWandererB = 0x97D12E07EDEE81E9ULL;
        aWandererC = 0x8150B28255ED09A7ULL;
        aWandererD = 0x87DF97C22EC6086BULL;
        aWandererE = 0x9EC662B66B3B82D7ULL;
        aWandererF = 0xC0026B8A643B87AFULL;
        aWandererG = 0xEEF4C7A8E63B46FAULL;
        aWandererH = 0xDA549D65097C1079ULL;
        aWandererI = 0xC35DD917964D75E4ULL;
        aWandererJ = 0xF6F80C546283D905ULL;
        aWandererK = 0x92A7B5833921FB95ULL;
    TwistExpander_Arcturus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDDE2D4E46FC95986ULL; std::uint64_t aIngress = 0x936AF1C4DDCE7141ULL; std::uint64_t aCarry = 0xA5D55F0F7C8C3723ULL;

    std::uint64_t aWandererA = 0xEE380CB7A2D6261EULL; std::uint64_t aWandererB = 0xF581BB50C7CAF5FAULL; std::uint64_t aWandererC = 0xE4D6D1E422DAC221ULL; std::uint64_t aWandererD = 0xEC5A367A3BD95E43ULL;
    std::uint64_t aWandererE = 0x8DEE83531CFF92BDULL; std::uint64_t aWandererF = 0x909B5B4E1DE60DF4ULL; std::uint64_t aWandererG = 0xEFA15DC7A14BBEE8ULL; std::uint64_t aWandererH = 0xA9CBBED62140B526ULL;
    std::uint64_t aWandererI = 0xDE98549647988019ULL; std::uint64_t aWandererJ = 0xD1B202D9DD17DDD5ULL; std::uint64_t aWandererK = 0xE2AE4646C5F6BF79ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD37AA75FDB8D567EULL;
        aCarry = 0xE4D59A496BD4D198ULL;
        aWandererA = 0xBFCE7D3BA7FB9DEFULL;
        aWandererB = 0xCB95F7BF4F57D703ULL;
        aWandererC = 0x8D30C95F8D96AECEULL;
        aWandererD = 0xA2FCCD4B2C1EBA84ULL;
        aWandererE = 0xA9BD53B9BB1CE460ULL;
        aWandererF = 0x9574A87B230D723EULL;
        aWandererG = 0x86CD2242115934ACULL;
        aWandererH = 0xFAC16A6889081CA3ULL;
        aWandererI = 0x99A1B35E61E7C026ULL;
        aWandererJ = 0xB0BACC7178E3715EULL;
        aWandererK = 0xAAF319120630AD6FULL;
    TwistExpander_Arcturus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE91E560486DB3145ULL; std::uint64_t aIngress = 0xF3B340BB344DBC40ULL; std::uint64_t aCarry = 0xB38202097C2345FDULL;

    std::uint64_t aWandererA = 0xF46E426B894B4ABCULL; std::uint64_t aWandererB = 0xB87C4AE49B744A71ULL; std::uint64_t aWandererC = 0xC52450C7B9B82147ULL; std::uint64_t aWandererD = 0xF45C4E4CA449FBD7ULL;
    std::uint64_t aWandererE = 0xCBB23DC45E644E5EULL; std::uint64_t aWandererF = 0xDCA0A640E7F9F8EDULL; std::uint64_t aWandererG = 0xA1ADBDAFE7B61A1EULL; std::uint64_t aWandererH = 0xC5672E2A864DF25CULL;
    std::uint64_t aWandererI = 0xF50D00D35D2020FFULL; std::uint64_t aWandererJ = 0xFF0CE031D8BDDEEAULL; std::uint64_t aWandererK = 0xA7D3ABB28D95A229ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x80F3DF4DEEC765DCULL;
        aCarry = 0xC747F5E6E402E07EULL;
        aWandererA = 0x9082102244525E90ULL;
        aWandererB = 0xAE2B116220C1432DULL;
        aWandererC = 0xD002ED4E44D8C160ULL;
        aWandererD = 0x8942547CD2B42CD7ULL;
        aWandererE = 0xC14D0569BF9560F1ULL;
        aWandererF = 0xC9954746BE922834ULL;
        aWandererG = 0x80F208F27802A2AFULL;
        aWandererH = 0xC521CFF20D3883BBULL;
        aWandererI = 0xD80DE46B53C98C86ULL;
        aWandererJ = 0x9B8CF72E5E8A25B0ULL;
        aWandererK = 0x82A4D2245BF12DCDULL;
    TwistExpander_Arcturus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Arcturus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD26F12FE2A60E481ULL;
    std::uint64_t aIngress = 0x849670A72155D373ULL;
    std::uint64_t aCarry = 0xA89B4253C0E585F0ULL;

    std::uint64_t aWandererA = 0xEFC69A35DC63ED77ULL;
    std::uint64_t aWandererB = 0x995A5FDC9FA24575ULL;
    std::uint64_t aWandererC = 0xBCCD8604B0A5071FULL;
    std::uint64_t aWandererD = 0xB63523DF823C76C2ULL;
    std::uint64_t aWandererE = 0xEE3529CC620919CBULL;
    std::uint64_t aWandererF = 0xF3760B32C25409BAULL;
    std::uint64_t aWandererG = 0xAA1D11F897F88098ULL;
    std::uint64_t aWandererH = 0x9077B4AD368A9A82ULL;
    std::uint64_t aWandererI = 0xA19420AE3C454426ULL;
    std::uint64_t aWandererJ = 0x9DD7F5C6E2641EE8ULL;
    std::uint64_t aWandererK = 0xDD1F1D9200478EFCULL;

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
    TwistExpander_Arcturus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KEY(pWorkSpace,
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

void TwistExpander_Arcturus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x851B8DEC3E2963B3ULL; std::uint64_t aIngress = 0x99FD0502E65B1B3EULL; std::uint64_t aCarry = 0xD5B37EADA0810AF3ULL;

    std::uint64_t aWandererA = 0xBD777E24190119FDULL; std::uint64_t aWandererB = 0xC03C990E9C1DC2E6ULL; std::uint64_t aWandererC = 0x94DA1967A7C6CDA3ULL; std::uint64_t aWandererD = 0xE559457AF8265E85ULL;
    std::uint64_t aWandererE = 0xA7CFCF87EEB75C79ULL; std::uint64_t aWandererF = 0x86259BDF1EFDB4B3ULL; std::uint64_t aWandererG = 0xBC37F1E311C9C5A7ULL; std::uint64_t aWandererH = 0x87A92C7D3ED84B8AULL;
    std::uint64_t aWandererI = 0xDAF54B81DCC4B44AULL; std::uint64_t aWandererJ = 0xFCE0E69C9FE739D7ULL; std::uint64_t aWandererK = 0xBD759CF02F726032ULL;

    // [twist]
        aPrevious = 0xDBAD72BF2B7B493FULL;
        aCarry = 0x8C673AB90943DEF3ULL;
        aWandererA = 0x977C689CADF449DFULL;
        aWandererB = 0xF69B58099FD80F25ULL;
        aWandererC = 0x8A371DCBF6321E37ULL;
        aWandererD = 0xE9ED7FBB2F392B44ULL;
        aWandererE = 0xCE7AB3AD9AA5A032ULL;
        aWandererF = 0xDCCE5BFF39858232ULL;
        aWandererG = 0xD8DC3940714F17C4ULL;
        aWandererH = 0xFA423B76C721E41CULL;
        aWandererI = 0xE6C65F7CDE01CB82ULL;
        aWandererJ = 0xB1805C83EC5AAC2CULL;
        aWandererK = 0x9777C3559F07AACBULL;
    TwistExpander_Arcturus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Arcturus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Arcturus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Arcturus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 10 of 33
    // Exploration cases: 0
    // Structural maximin 530 / 674; family total 4932
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 10 of 33
    // Exploration cases: 0
    // Structural maximin 527 / 674; family total 4912
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 10 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1074 / 1248; total 9815
void TwistExpander_Arcturus::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
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
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 10 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1076 / 1248; total 9832
void TwistExpander_Arcturus::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1016U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Arcturus::kKeyRotateSalts = {
    {
        {
            0x71A6C5810FAF3F96ULL, 0x9B6604374E3AB44FULL, 0xA031ED32583705E8ULL, 0x09D42EE952931143ULL, 
            0x7375956D9FF8BE11ULL, 0x8226C7FCC222744BULL, 0x2C1C32B349120ED7ULL, 0x78BC4E0E30A1D997ULL, 
            0x384D84E6D03EAC83ULL, 0x7A99F3D2250C8B7DULL, 0xA8716F00624A41D7ULL, 0xD3A454C06D90E8C9ULL, 
            0x0D8B98C484FC0F38ULL, 0x8246170C51205E8CULL, 0xDFC412895EBC5321ULL, 0xC87A6FED4C116E12ULL, 
            0xC0583073FF37E2EEULL, 0xA18C2A992F7DBCD6ULL, 0xA52FB50D6EDC2269ULL, 0xEA2B314E063032F5ULL, 
            0xD1616E6A63046B9FULL, 0x2D5F5A3B393E10A6ULL, 0xB21D7ADAAFB0E259ULL, 0x42EF5F9D91C06A21ULL, 
            0xFA43A9F363DBD077ULL, 0x6FD19FE3EDA42214ULL, 0xD53A50F24FBC3F78ULL, 0x2A51F5B6F217D86DULL, 
            0x83014396A0A6ACFCULL, 0xA603566C77DBCEE1ULL, 0xAB4AA3E57E09D117ULL, 0xDBFE96B2236F4AE0ULL
        },
        {
            0x121B6CCCA3674D25ULL, 0x59A421D1EC48352BULL, 0x053464D2F27C0BEAULL, 0xAFAC8C38170D5888ULL, 
            0xB2992FE4ECCF0172ULL, 0xD38FCA5DDE2B2CBAULL, 0x05E70DC4F7D26EC1ULL, 0xB480D3DDF72EF858ULL, 
            0x6F5BA1FE98162A44ULL, 0xE79018FA390E5B18ULL, 0xC18337DBC6D2A897ULL, 0x205D04488B9BE8A5ULL, 
            0xF786B862FCAFE1FDULL, 0x218ACEC48D7E49E6ULL, 0x543ED4838D47A6FEULL, 0x7206421155F6F9E2ULL, 
            0x8053B20433FF6756ULL, 0x9528B096C50F7F87ULL, 0x0A0E1089DA83719BULL, 0x2198B338EB1C69C3ULL, 
            0xB1CC59BB04A033EBULL, 0x280AA9C93C2C3310ULL, 0x5AC7C318A8426998ULL, 0x62FD2ABB1493A1E5ULL, 
            0xDBD70A585E8EA630ULL, 0xCEB70175C893A712ULL, 0xFAACEA13A4CA60ABULL, 0xE195E9B09B691CD5ULL, 
            0x6826E9EE971409C7ULL, 0x3E673E8368406037ULL, 0x0ECF7F26DA67DEF4ULL, 0xAB170A2348C8CF5BULL
        },
        {
            0x9B750417367C5208ULL, 0xB35E0FCCAD79E673ULL, 0xA5C1197DC28025A3ULL, 0xE95C21C23B72784DULL, 
            0xD05DBD35B3FB2725ULL, 0x05872725A2F8229BULL, 0x7FF019254E546317ULL, 0x86962E1F2C4AC000ULL, 
            0x94B90B86D1C78F6FULL, 0x10EAB6F07BC60FF1ULL, 0x4B021355542C9255ULL, 0x814E2DDF3488F550ULL, 
            0x5F001399B83C0E3BULL, 0x53CE80BFA1544901ULL, 0x34F18DB0DA8AFA72ULL, 0x5B3AC8D9624A1F81ULL, 
            0x7221E599CA3E2B4EULL, 0x78CF281D0D8D697CULL, 0x1EF16942208380F0ULL, 0xBCCEBA1BB13F4621ULL, 
            0x69A21CF8A321E9E9ULL, 0x2F94B3A5DE8EED5CULL, 0xA92D29902C7A375BULL, 0xCC5593C3EE7591C1ULL, 
            0xEC8B66ED69801D24ULL, 0x3362281701A8BA68ULL, 0xC7A046F25FCDB5C5ULL, 0xB4287C735FC08C37ULL, 
            0x9F5CA8063C379DE9ULL, 0xEAE18CB9F6F8D2D7ULL, 0x3A539B84170184CBULL, 0x6C73E3EF439B9C69ULL
        },
        {
            0x2682F38444AD6EA0ULL, 0xC87B4196EAF3EB3AULL, 0x2C5B2D2EC5AC45A3ULL, 0xABC47E76A7EC97B4ULL, 
            0xECBE115B9DD11D5BULL, 0x5F60F3F8FB315282ULL, 0x8CC31EB84FC548F2ULL, 0xE2F944456C6EE520ULL, 
            0x032D76C366CEA192ULL, 0x26B0F531FBCAE1BDULL, 0x496412A0B960BA02ULL, 0xE9E2937E7F8EF182ULL, 
            0x4BC6549D0388D6A8ULL, 0xEB9CA51C674B8484ULL, 0x0DDD81CF11EAD2BBULL, 0xF51140BD36C924C7ULL, 
            0xE7C75A4AA84F925DULL, 0xADA42F42BD328C85ULL, 0x06B4DB1F9E41B1D5ULL, 0x17D3ED9FEBAB46FEULL, 
            0xC836DCEE24C8DE69ULL, 0x357F474CE17317E3ULL, 0x14C7619EB642C9D6ULL, 0x3FE82490792469E4ULL, 
            0x6BB96AC1CF9C775EULL, 0x2B4CFD58C8FC7C99ULL, 0x0A2E5B63A9AB81D1ULL, 0x89899BB0067A751AULL, 
            0x542C3B33D58B58D6ULL, 0xA0B75ACECA23C04CULL, 0xA0482D9DAF943283ULL, 0xF4E350106AF3837AULL
        },
        {
            0x8A29251450EC8F1BULL, 0x42538FBDA0A1DFBEULL, 0x3210A03021DB56B9ULL, 0xA1B5C3775DD2A28EULL, 
            0x595940718A0E86ECULL, 0xC16C9893511733BFULL, 0x452AEDADB8DF48C3ULL, 0xB9A3F21DC492BDEBULL, 
            0xE38F0D75A3409C0DULL, 0xED2663230FC19841ULL, 0x8AAA4E720D709B9FULL, 0x8234E1D3CFC1A45DULL, 
            0x680F5562689FCB6AULL, 0x6B1CB327E13699BCULL, 0x588A74EF026B1E3CULL, 0xB7D19C7E25F04EEEULL, 
            0xC26AC52A66C6A14FULL, 0x69778013CFF2B633ULL, 0xA0A34DB0339026ADULL, 0x45E51317136EC0F6ULL, 
            0x099B678977777637ULL, 0x8BA13CBE3B43F21EULL, 0x29C9CED0A8073847ULL, 0xBA320DB256068DC8ULL, 
            0xDF8EECEB6F35B459ULL, 0x42377602E1A72668ULL, 0x5A08CD02ADC4CC13ULL, 0x54A53A2A62B5C276ULL, 
            0x15A3AD3CDD809724ULL, 0xC85C7A7E91A464CDULL, 0x3F95623132152BDDULL, 0x360EA219AF3C92CDULL
        },
        {
            0xB34B0D50D92A1F30ULL, 0xC406F836D071BD83ULL, 0x6C9F0DEC7F017413ULL, 0xC5BEF1634FF5FB77ULL, 
            0x4A7E096496C891FCULL, 0x778E7D3ACE0B9255ULL, 0x09F0661436A8DA43ULL, 0xEA8C2C1DF32E20E3ULL, 
            0xF9EF8A1B6D5FF19FULL, 0x850A3E93D06F997DULL, 0xAB008CCC34F3F9EBULL, 0xCB6BBBCCC4273B4EULL, 
            0x7DB2B078166D96CAULL, 0x27F44EFF5DB431E0ULL, 0xF09412C137C35687ULL, 0xA6998385BBEC1156ULL, 
            0x1DDA824BE7060E92ULL, 0xEAA1FB137F9F414BULL, 0xEDFE5BBEAFC48DD7ULL, 0x3AF242F038A3BB24ULL, 
            0x1E33AEF8B4A7BD13ULL, 0x48C6BC178A1CC401ULL, 0x8FF2CEDD2A0CCCC5ULL, 0x68AC495047D7B445ULL, 
            0x605B3FF0A16A496FULL, 0x0A0015113171437CULL, 0x30E0D61F379D73BAULL, 0xBC1BE237B70F6E76ULL, 
            0x37A612837FCB7A95ULL, 0xFFC890E0EABDAE9EULL, 0xD7A66CCB6983A0C6ULL, 0xB7BC63EA11B06BA7ULL
        }
    },
    {
        {
            0xE356B70EB7B48D81ULL, 0xCA5F8895C6C41113ULL, 0x611779A07F6DE938ULL, 0x8C4141161E56A500ULL, 
            0xB39DBA9AAB0EDD99ULL, 0x9F9C90AB40A49C33ULL, 0xDAB09760A6E0181DULL, 0x9A59C8AD97F275A5ULL, 
            0xDDAED3C345661F76ULL, 0x60B7C98852618803ULL, 0x000380178C063139ULL, 0xA85E07425BCD0F5FULL, 
            0x1535497522C65340ULL, 0x0A93FF6E7D558283ULL, 0x1728ADB910A47D7CULL, 0xE4DA23854F0EE7A7ULL, 
            0x2DFD1F72505E9C36ULL, 0x745BC8DB46BCB771ULL, 0x1CEDEEA9C1ABCB8FULL, 0xD6EFCACAB59FF964ULL, 
            0x73777AE84491871BULL, 0xCCB490F18544C971ULL, 0x00D5D7009472C559ULL, 0x5A2B06F069427FF8ULL, 
            0x297E8CC6679DBF27ULL, 0xE8E431B584CCAA77ULL, 0x1CF5C67BC1BB4F76ULL, 0x4CC56E4616259387ULL, 
            0xEEC9D177C0128D85ULL, 0x53E0D58B6A3C1929ULL, 0xE839E7698AB96723ULL, 0xD6E01F905A2B5787ULL
        },
        {
            0x502AF4FE9A72FC96ULL, 0x8C09BD858B74C84AULL, 0x2F65A9855D3B2DB1ULL, 0x781EF0A8DF9AC7CAULL, 
            0x47CB199324566C2EULL, 0x80E7A4BCE4BECE0CULL, 0x4B5D64F0E0800BE5ULL, 0x6E7E95C7416549B6ULL, 
            0x9155A18ECC54E919ULL, 0x1781B744679307CAULL, 0x83A52A171468AC5FULL, 0x8CB0CEAD47E0128BULL, 
            0x025491E3E3367853ULL, 0x5A6C625CD38CFD1FULL, 0xDE39954533455263ULL, 0x464C73A048FFE923ULL, 
            0x5E7CA9DD7663700DULL, 0x24DDA88E94296571ULL, 0x0C91EB6BD8BE68F6ULL, 0x5822F39CFDBF7F33ULL, 
            0x59A84A7BE234B02AULL, 0xE46B76EB55DFADBCULL, 0x81D68880E34D38D1ULL, 0xFCDC3EC3D72758D3ULL, 
            0x80A8D1CCD31FBB72ULL, 0x6FCA4763EF53EAA0ULL, 0x23363B97D64C2F64ULL, 0x948DEA579EA39348ULL, 
            0x8E2E26E640C0D7E5ULL, 0xE6BB5E96C06F7A52ULL, 0x22541EAD0F72B588ULL, 0x0148F9554A14899BULL
        },
        {
            0x01BF0E22CFB32248ULL, 0xC220C02B7EEB31D5ULL, 0x372940E0AB962955ULL, 0x63BADE9A46685D30ULL, 
            0xC526A497A652971CULL, 0x607CE1D000589F4CULL, 0x832760C3616E90DDULL, 0x8B59B6C3A4E4DC25ULL, 
            0x8C0F2162ADE8115EULL, 0x07E436941A93555CULL, 0x576EA18EC16CB10EULL, 0x30284D73C91BB5E2ULL, 
            0xC1EB02428CF77415ULL, 0xC855DB4322C2445AULL, 0x9D8D158576DA18FBULL, 0xD8CE4E80A60C4A6CULL, 
            0x0FD8506A1AD578C0ULL, 0x3584A547E51777C1ULL, 0xC200223659B23A1AULL, 0x7B8257E9AF143203ULL, 
            0x3742A3806C658940ULL, 0x641BC6E4EE316351ULL, 0x8341ACF5CA41CC34ULL, 0xABE99A32262A2869ULL, 
            0x12699DCC12357E5AULL, 0xA1DA88F3642AE2BCULL, 0x85C1F49BB0AC84D0ULL, 0xCDADFD12E5482C8CULL, 
            0x610DA6E1DA75465BULL, 0x63EF614F9EB5EC18ULL, 0xA79FFB365B3D4D7DULL, 0x0DB5E15B8349DFEEULL
        },
        {
            0xC817ECFE8BF55671ULL, 0xC83714CD4E96CCCEULL, 0x605BBC5AD2441411ULL, 0x23F5EC75AF5FEB7FULL, 
            0x7A82D7A7520FF5AEULL, 0x980C507985266B31ULL, 0x0DFEC0F9E7C370E5ULL, 0x15634CFCF2726066ULL, 
            0xAF1825DA0D6DE9AEULL, 0xB504872CECFB9CD2ULL, 0xF6BCD3D9BC19AB3FULL, 0xA4B7055A2205CD45ULL, 
            0x58DF1070D38CA48FULL, 0x1D4A1C0261B00F17ULL, 0x25C79188CBE9BEDAULL, 0xBDCC09A0F7E7EF92ULL, 
            0x60B9A03727E92FAFULL, 0x6AA17A279FEB358BULL, 0xD3ADBE271FE2FA3BULL, 0x81AC26FADD6AD554ULL, 
            0x379A58181DD802E0ULL, 0xCFD396EED7172BB5ULL, 0x1B082E364C3D4041ULL, 0x7FABD446FA6DC9A9ULL, 
            0x9F535F456A761C82ULL, 0x56875179D2B8DEAFULL, 0xCE0257A87815A1FFULL, 0x50EC116A7CD4B8E9ULL, 
            0xE26E13338B7BF6B6ULL, 0xF2990737E0A22482ULL, 0xC016D7A846D3160BULL, 0x83ED07E2AD55FE2EULL
        },
        {
            0x0AFBC5DA30B8DC17ULL, 0xFB3E86D72876098DULL, 0x652BD4FE75D9829DULL, 0xB5D856FF932DC0C4ULL, 
            0xAFC53B1BA51BED89ULL, 0x8B9F7F466FA8EC74ULL, 0xDB8A48819B6D292EULL, 0x8E9E7010A20E7FBDULL, 
            0x744596614C45A0D7ULL, 0x0F786466800B9E72ULL, 0xB643F7678CB85417ULL, 0xE5592941E6BCF0BDULL, 
            0x56D183BE2B572F39ULL, 0xCA7CD8DBB748E33CULL, 0xBF1A2FBE614EA94AULL, 0x5026A6E550392A49ULL, 
            0xC93FD1B3BFE03305ULL, 0xD2F349D16B235BBFULL, 0x20516B475BB023CDULL, 0xA71FFAA539E8F476ULL, 
            0xF84ADAD10834E3F0ULL, 0x0B0B273DC29DCBCAULL, 0xCCFF4B6B11B4BFDDULL, 0x0AF9EB946B97719DULL, 
            0xBEBEFDF48C2B5C4BULL, 0x5601ECE50DD1D482ULL, 0xAB738239C57670BAULL, 0x676924CC14FA6075ULL, 
            0x698AB53EEB0A276FULL, 0x62E17DF5298D93B0ULL, 0xCD35C53ABA3CE2E8ULL, 0xEBE28E76907498CCULL
        },
        {
            0xA0CEA63B471FFADCULL, 0x5C9405EAF6477505ULL, 0x601CD2CD919982A8ULL, 0xA1EAA23C3EC07B93ULL, 
            0x2DBB2CF263CC50DDULL, 0x947C239BBC40A546ULL, 0xD56F01D9CA1B1588ULL, 0x9B21F4CD7B57C959ULL, 
            0xD0AAB64A3FA48FAFULL, 0x75980D62A79F17F3ULL, 0xE232160F10AB330BULL, 0x5EC832270DC1FBE6ULL, 
            0x98C980A1FB049385ULL, 0xB5226B8391A688E8ULL, 0x879A4FE72F9D70BAULL, 0x711C21F4F210242AULL, 
            0x9F030EF0419F2D50ULL, 0x0A0D125FC009757EULL, 0x2F9433E7C2120A6BULL, 0xB60A527DB4A9604EULL, 
            0x01FD67D35EE399C5ULL, 0x767148B66A5A7812ULL, 0x710F2B7E75A03716ULL, 0xE972B9B1321DE1E4ULL, 
            0xB66221FF594A1F4CULL, 0x93CF39F6CF094A9AULL, 0xBC2081E124FCF235ULL, 0x2C8408A7FA8FDF89ULL, 
            0x0122E18A44F8C738ULL, 0x56C4E9613A869021ULL, 0x296AC9583315CAB2ULL, 0x9C6CF4F8F77BB76EULL
        }
    },
    {
        {
            0x718577C674ACB311ULL, 0x429446BD0CA38AF3ULL, 0x54EA1A05AB7BD63CULL, 0xDF0B6A24594710B0ULL, 
            0xB9007C92E3922F78ULL, 0x3A9E2AEAA63AB3DCULL, 0xED2DC80B4C03C19AULL, 0xAA5FD940E33098C8ULL, 
            0x2B12D8F6C09C86D6ULL, 0x0D0B34CE1483F38BULL, 0x8C241739B70832A2ULL, 0xF34D27A62DFBEC58ULL, 
            0x207A9557718844CFULL, 0x1B51D8E46AC387D5ULL, 0x0DE834F30928CD96ULL, 0x670B0AAEC4B28608ULL, 
            0x8BCB30DE2B56B27EULL, 0xCCE720935B384ED9ULL, 0xC8137600E5137819ULL, 0xCAEA09CC912D4E01ULL, 
            0x95EADC35CABD54A9ULL, 0x5AAD51EEF8F2876CULL, 0x20D86FE02F30FAB9ULL, 0xBA222F85F22A2D27ULL, 
            0x2CF40CD2F7F324DAULL, 0x1C82EB124A392665ULL, 0xB736A733C0E83181ULL, 0xB3CB47070D81453FULL, 
            0x9CF0243856E2DBE8ULL, 0x69E3141459E313A7ULL, 0x075574FD3370554BULL, 0x16BB0DA3E8A73428ULL
        },
        {
            0x494C8AF620DCF8D9ULL, 0xC161C6C8120C46E8ULL, 0x2CAA400CAF7C6A96ULL, 0x530F4EBC0CF746A7ULL, 
            0x10D92CD1FFA64598ULL, 0x6D482E4F0FB5FAFBULL, 0x65538A2334934F2FULL, 0xCA3AC833EE684756ULL, 
            0x85FF644287D0217AULL, 0xF67DD9053B6E8EE4ULL, 0xFB1CE1F08DD0FABBULL, 0x9F5837EDE092D0E0ULL, 
            0x39A79CF0E7989D81ULL, 0xF468F8594C5BEA82ULL, 0x5DA3D9500E7B4D9DULL, 0xB51E0C7D7766BE44ULL, 
            0x0FEAF108DBB124B5ULL, 0x362FC169DB7B1541ULL, 0xAB7DF0A4460FA892ULL, 0x581FF01456BF76F5ULL, 
            0x9F998E06028BB003ULL, 0xE50104B90DFD5183ULL, 0x20E76195C7FCB5F3ULL, 0xC9068F24710A6321ULL, 
            0xDCFA2D651A0AED86ULL, 0x99DE23B5B40C0963ULL, 0x29B3892847FEDA7CULL, 0x360202F23C7BC78CULL, 
            0x7BE78CD9C704269AULL, 0xA017B944F4A60795ULL, 0x33287D653CBFBBCDULL, 0xFCEC88057F7021EEULL
        },
        {
            0x2EA19C7E2986DDFAULL, 0x763586C939C29834ULL, 0xBA4BCB02896C4A06ULL, 0x83347C92E25BA4A2ULL, 
            0xB9FD80B608B60E37ULL, 0xA6B18579A179104CULL, 0xA8311199B62ED357ULL, 0xDFEDABFC90EE5C01ULL, 
            0xE9F61B4DAF680EB3ULL, 0xA4F99B82F39AFB3FULL, 0x7D98A217A2868EFDULL, 0x2EDD84AFF1F9024BULL, 
            0xA16245BA0B4C8C76ULL, 0x18FBA05E9D3B85AEULL, 0x4F65FC7B809D0731ULL, 0x463EAF4D6227C077ULL, 
            0xBD0C27346A44EB8BULL, 0x0C687DD1DB28746DULL, 0x7DF2A286BA94A3EAULL, 0x678D64EAB228720DULL, 
            0x7541363EEAFC829AULL, 0x1EC6A90EC85D5D87ULL, 0x2F4A07BC2819C1EDULL, 0x183E7A58F57DB029ULL, 
            0x2554F91B897C8FD3ULL, 0x17A69E268C3C1E5EULL, 0xE02317C1B3CFFDCAULL, 0xF53E24FD5E5EC7F2ULL, 
            0x002D9EF70A214FCFULL, 0xF83E7470C14C92ABULL, 0xA694B8CC489FD2E3ULL, 0x931EC8B963679BF6ULL
        },
        {
            0x33190BDB0256A76DULL, 0xC71DFAC91DF322BAULL, 0xAB6E6523FA6536A7ULL, 0x895306D210B61D2AULL, 
            0xAA849087974826BBULL, 0x004666EEFEE07CBDULL, 0x624143D2B3262ADDULL, 0x502C9ED75DA1C52AULL, 
            0x1F850C6D18A8CA67ULL, 0x51432E18732DBB7BULL, 0xAB26CF873D1FF6CDULL, 0x1DBFE95F6914A5A5ULL, 
            0xD5DEA1E9E2CCD335ULL, 0xCD2A10B8FC5C2B9CULL, 0x7DF8B3981C1ABA12ULL, 0xEE2AF699532BD31EULL, 
            0x3731B10E43788A49ULL, 0xD2251278FE0EF668ULL, 0x32D9AFDAE5E8D01EULL, 0xF16308A7A75CEC46ULL, 
            0x1FD47EE2FB73ABE0ULL, 0xF84D923AD9764EECULL, 0x8C78166321AEFB69ULL, 0x46C550BA983FB365ULL, 
            0x4E5F785CA96346B2ULL, 0xB9BA281501982D3FULL, 0xE87F2BF5468D158EULL, 0xAE4211D9956539C7ULL, 
            0xFCEE721B70B4FD55ULL, 0x6CCAD70C56249A34ULL, 0x10B9A0FF9F87571DULL, 0xE69983985775EFE5ULL
        },
        {
            0xBB9679905CB6CFFDULL, 0x2800B7F520711253ULL, 0x243A2C2AF2FC19ADULL, 0xAA0F35B3D8B03D25ULL, 
            0x1EE0CA4A1FDBD762ULL, 0x75A39347DF7CAF27ULL, 0x682EDC005E9BED07ULL, 0xE2F3195BB03BF1CBULL, 
            0x103F126CBBE99F77ULL, 0x6153A296F2D91284ULL, 0x50C0E29271220BCBULL, 0x9AAF09A1216C19D8ULL, 
            0x99E1EC1459F84E55ULL, 0xF2A1B6DE5F7E0D33ULL, 0x11E06A3D4BE18D8BULL, 0xF9567245928DF2B3ULL, 
            0x94697F10E7EE9874ULL, 0x9A4BC90FBD47AFC4ULL, 0x429751DC4402F18EULL, 0xB9C9EFB2A4240C13ULL, 
            0x11B7035C746AD9BDULL, 0x04E1EE1CB493806CULL, 0x7D3501D143A660EAULL, 0x3D163ECD178C0466ULL, 
            0x2777F711E557CB50ULL, 0x120AA524E214FB8AULL, 0x9B084DA4EB9537D0ULL, 0xAFCF3DB950AFFFA4ULL, 
            0x67F53340045A9826ULL, 0xC16689A42FE58A2AULL, 0x64164EB39567D3C7ULL, 0xDDE27F271DB03948ULL
        },
        {
            0x098214AFDE37F1D5ULL, 0xC081D7EE55329590ULL, 0x438CC2DC1E551366ULL, 0x83EA4EAC2B47EB68ULL, 
            0x8C80DC62C811CB3AULL, 0xBD2D1AC820741BC7ULL, 0x00637A22C516AB1FULL, 0xD93D177641046F37ULL, 
            0x6D4A394439B7E758ULL, 0xAC0E0ECD7B7FF1D6ULL, 0x8F5A43337FC4A545ULL, 0xD3C6FA911CD64EA3ULL, 
            0x5342295190BE33EDULL, 0x32EE07AE99E648C1ULL, 0xA276583212928B20ULL, 0xA92D32D7AC04B143ULL, 
            0xE2827BE4B627FCA0ULL, 0x7ECFF79A2EB73D43ULL, 0xF7628A1F82F20744ULL, 0xAC55D478BB239A85ULL, 
            0xE59C1FBA57DDB9F0ULL, 0xE89EE289D9390E68ULL, 0xBF41CB690A4ED99EULL, 0x4DC1D6724C8134FBULL, 
            0xDBDFA7030D3FED3AULL, 0x47E57BAA113E710CULL, 0xFE3C843912C9939CULL, 0x8812E7E63C0C1F27ULL, 
            0x095F90159E1567D1ULL, 0xB34E214EF540D3C6ULL, 0xBA3A937F0AB0AE73ULL, 0xBB9AFCA4C2C549D1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeyRotateConstants = {
    0x7173B918BA083686ULL,
    0xFBFD1455B541539DULL,
    0xF3F7306686B69A56ULL,
    0x7173B918BA083686ULL,
    0xFBFD1455B541539DULL,
    0xF3F7306686B69A56ULL,
    0x6AAD6683DBAA5ACCULL,
    0xF33EBBC19867BB07ULL,
    0xF8,
    0x6B,
    0xA9,
    0x91,
    0x0B,
    0xC0,
    0x3E,
    0x65
};

const TwistDomainSaltSet TwistExpander_Arcturus::kKeySpawnSalts = {
    {
        {
            0x4981EA09CB414591ULL, 0xC30E1B0732BB101AULL, 0x4029C3D2E15E9EBFULL, 0x3DD42AA62E7E66B6ULL, 
            0x93DEF1ABB06010B6ULL, 0xE09A347700448F4DULL, 0x3853E45363636728ULL, 0x738CB276A1011B8FULL, 
            0x41B33F4D6091FA9CULL, 0x54DA934A69B33281ULL, 0xBE530FC64A9A171FULL, 0x9BBFFEA4E9D9A821ULL, 
            0x616351A13FB195F9ULL, 0x31EA3E174B6FB468ULL, 0xAB9482D7DFE7E626ULL, 0x6CAE18B0B8308443ULL, 
            0xDCBC007BAD879360ULL, 0x941443D0F29BFA99ULL, 0x1D3D2F79CA75B778ULL, 0x8B76F13A6B446F6CULL, 
            0xDD5E312C131C941EULL, 0x96F2646666556130ULL, 0x5497E1B0B620AF91ULL, 0x50D0485D80AAE48CULL, 
            0x3DC57506A1B3997AULL, 0x39F1AA5FD7A13439ULL, 0x264230B9D2842D80ULL, 0x78B1639C4BC5B74DULL, 
            0x49E26C18832C1AA7ULL, 0x33B4E1B3B2B6235FULL, 0x778AF146BE4C9B42ULL, 0xF258DDF4C223AD7BULL
        },
        {
            0x4E4894253D152FB5ULL, 0x9C2D4A5296BB51F3ULL, 0x284ABEA1B4E0C57EULL, 0x4F0346C4C4FB6321ULL, 
            0x6BDB35111192AA8EULL, 0x4410FE0FF393C0EDULL, 0x623CF395D938179EULL, 0x2245AB80DD115A9FULL, 
            0x13304A6A54D175E2ULL, 0x1C1A9C29EB771540ULL, 0xC96087B541D11D12ULL, 0xF837A57749C708BFULL, 
            0x8813FE0700F1B454ULL, 0x6602538E684EDFFFULL, 0xE3FCAD1AFF0BD732ULL, 0xC1EEFC0855BDCBC0ULL, 
            0x5377013315EF8403ULL, 0x70A02939C89045A2ULL, 0x4E7DCC504947C55BULL, 0x3A3AD89E45009C62ULL, 
            0x2EB66C7E99944951ULL, 0x1DB9F8730FB656F7ULL, 0x43B160F83B27B752ULL, 0x6E367D56831FDA05ULL, 
            0xA58C6B46E7A1F06EULL, 0x0F59A16BE3D07A89ULL, 0x4613008E4E74000FULL, 0x95B3DDC049BB90E3ULL, 
            0xED4E79F89C74BC90ULL, 0x188D223129F94F70ULL, 0x2FF8DF8D426F74A7ULL, 0xBF51564D0DAC0677ULL
        },
        {
            0xE6FDEB526589708BULL, 0x88906AC70CB97F93ULL, 0xB7BA91E659FF8F87ULL, 0xA97F891889FCC33DULL, 
            0x58061CF89A825743ULL, 0x44572361F5B5B7DAULL, 0x8FCCD3383A6B4EEEULL, 0xCB782FCB3A63BEEBULL, 
            0xB75E20E8196D24A9ULL, 0x740FC6CC9107BE11ULL, 0x541553FFFBE898F2ULL, 0x0C7902BF503DEEF6ULL, 
            0x75414B2D70B3B11DULL, 0xEC48A8F2D06777B0ULL, 0x7002F1BDFC13CE1BULL, 0xC9D7574128BC170BULL, 
            0xB2062A4059E06492ULL, 0xC09AF0C0BBB556B2ULL, 0x64268727473470E4ULL, 0x11C5B0459A9B3D14ULL, 
            0xC6637647F06CEA81ULL, 0xEEC9D4501395E65BULL, 0xE0DF929217DFBF41ULL, 0x4E595C58C6B43B33ULL, 
            0x479209C3CDE404EEULL, 0xD3934897E81B19BEULL, 0x77DF1232931FB738ULL, 0x5EF5957C7E65357FULL, 
            0x7B7942AF221C1095ULL, 0xFFE6CCE68FF98396ULL, 0x3D4B261A9C7D5146ULL, 0x7255E600199F9965ULL
        },
        {
            0x7652AA2000DABDF4ULL, 0x015C6F7D4765434DULL, 0xEB4C6603FA2931ECULL, 0xC07342939C7D272EULL, 
            0xCE3F6296A28B7FD6ULL, 0x871FEB20A02CD5A7ULL, 0x6EFD14393DB0E1A1ULL, 0x14DA5F72FB79F1B9ULL, 
            0xF5BB6F973CD9D9B7ULL, 0xB737238B4A1CC755ULL, 0x8014BA73ED4D9603ULL, 0x4800B67008C990B0ULL, 
            0xF3C7DA7AF6C7EA31ULL, 0xCACA5021C7496625ULL, 0x0B0EB8F9EBA6BE72ULL, 0xCAB9AD7F2F71E711ULL, 
            0x12E6CBF32374CF17ULL, 0x85016E5E40C78446ULL, 0xA67B2A21180A464BULL, 0x0C4BD1A87CD05FB6ULL, 
            0x31A46D024D86405EULL, 0xCC465448A4D08067ULL, 0xB14491D01BE3DBAFULL, 0x7E2BFC34092FFAFAULL, 
            0x78A0268D428DF1D2ULL, 0x32D60E837C3A8212ULL, 0x8913B3F1BD839752ULL, 0x9F633DC44DAAD490ULL, 
            0xBA1A4BD62E8F75BDULL, 0x4F93BB068BE7F591ULL, 0x763F6049BEEB6E2DULL, 0x20B2798BE183D468ULL
        },
        {
            0x3160B4E0C716F81CULL, 0x540979EDF37ACC0DULL, 0x293A2913D4FC1A01ULL, 0xED387D03D699A219ULL, 
            0x852260587339383EULL, 0x27F9F281D1C4CF5DULL, 0xB168A44CAAADAC38ULL, 0x6A439530E33F6A82ULL, 
            0x97FCD774732CC966ULL, 0xB29833DCE1CCD6C2ULL, 0xCE3E39D4313FC9AAULL, 0x12C3B65CB4399D14ULL, 
            0x719D91943A701278ULL, 0xE8D50F252450D071ULL, 0x2CD45A90791BF4DCULL, 0x7AEE0ACB8B64DD2BULL, 
            0x153019A2F674A312ULL, 0xD94D7ADE0C6AFB79ULL, 0x17915696FF510045ULL, 0x0AAEDB2AFF82CC74ULL, 
            0x239FD107A1314DC4ULL, 0xB6A84836575E43ECULL, 0xAAB9004DFFDA0341ULL, 0x831CA2797C4D0F3EULL, 
            0x9F7674ADEDDAE390ULL, 0xC2D0940F2F21DCA4ULL, 0xCA0F1D554B10AD2EULL, 0x1B0134CAE496BFE8ULL, 
            0xD5BE886AD2B4748EULL, 0xB7F2DADFEED14916ULL, 0x3C3E8738ED803F65ULL, 0x6B8C70F8434C3DE6ULL
        },
        {
            0x94FACD86A4C0B34EULL, 0x0B2957D603A0029FULL, 0x729B02D1966C13B0ULL, 0x45CFAA723FD57E48ULL, 
            0xC0D490A6E3165A71ULL, 0xB7D86558B9DA74CFULL, 0x4ABD48F4A136B86EULL, 0xEFC48EAB140A9192ULL, 
            0xF441B2B47928CCCCULL, 0xFDC803BB8A28125FULL, 0x78EA3C3C3249ADF1ULL, 0x6CE3A93A2ADDB140ULL, 
            0x9978ED7CCD810E80ULL, 0xF9CB2948BFDCB3EAULL, 0x99CBC7A9B22D5D77ULL, 0xCD7A3C7ADDD95953ULL, 
            0x5E4EFE9E467ADE60ULL, 0x5E82FD69E2F37D94ULL, 0xDF7AE50E26A3AF6DULL, 0xEA930E5AC4C61BADULL, 
            0xB5828AFAB2CAC07CULL, 0x824F4094BBA2B549ULL, 0xCC9837722150F272ULL, 0xBFE33134E6DFCE8CULL, 
            0xE1DE16EA615D344CULL, 0xF452895D27B63A2CULL, 0x06B1BB240173531AULL, 0x514A04926B1A76D8ULL, 
            0x6AA964DFB5DF3C54ULL, 0x9021C8D82180711CULL, 0x2F5EAEA5EC26092FULL, 0x7189B2B832B27BDFULL
        }
    },
    {
        {
            0xFDFC15ACA38C00EBULL, 0x45B5FBD192253B32ULL, 0xED1A797754A51614ULL, 0xF420BB6CFB6AC2CCULL, 
            0x071255D1BC025AD6ULL, 0xE959F0934BE3F783ULL, 0xC1AEAC3988BCF051ULL, 0x1D6EF562555DF43EULL, 
            0x9663C36EAB7E218DULL, 0x57B0220103A3D709ULL, 0xD0BD3A506828E6FBULL, 0x22A8C6A7EBAAB181ULL, 
            0x210FD8FEF8F4DB77ULL, 0x4B1905B635D11969ULL, 0x35B08889D77DB8C6ULL, 0x8C99DCA9DA8FC3CFULL, 
            0x684B87E31DA111ADULL, 0x4E8BEC112FEFA480ULL, 0xFA16C5D4F2F5D54FULL, 0x9ADAB766BC68B306ULL, 
            0x63DE4A106B8943C2ULL, 0x184E46AA0C5EE4ACULL, 0x592A5C710E1EC2CFULL, 0x3AEAEBB1D7EEC189ULL, 
            0xD770ABDCC195516EULL, 0xC3BB37301549DA92ULL, 0xF9C2CA72838B5C25ULL, 0x43016B3C6BBF78DAULL, 
            0x72B4E66C682B376CULL, 0x3A589DAE4DAAB217ULL, 0x920DE0365ECDB3C2ULL, 0xA11FF99492464272ULL
        },
        {
            0x17956DCE7EE676C1ULL, 0xA567211C55F2D55CULL, 0x4B129BAE6153C982ULL, 0x71D50FAF690EA986ULL, 
            0xBE1E8583CB39A2C2ULL, 0xE8A9926B51591922ULL, 0x4D56EBBE50A6BBE4ULL, 0xFC43B8ED3E46C396ULL, 
            0xDAC05DFB50F9C51AULL, 0x8BDE1BC088946290ULL, 0x293A392ACBB0275EULL, 0xB30799DC4FA2C2B2ULL, 
            0xC191D6538D1A7944ULL, 0x49A72FDF5A1613FAULL, 0xFCD7AED5BF8574A9ULL, 0xE44BD1FDCECFFB40ULL, 
            0x9153AB708E06BDC7ULL, 0xAF3F2E4738BF3949ULL, 0x8EAF61355F8D5942ULL, 0xFEF8A4664449672BULL, 
            0x72AC72858DEE860FULL, 0xAAD0171D2BEF36F4ULL, 0x73991A26292FCD5BULL, 0x836594781E0F9CD5ULL, 
            0x92BA5611AE36053CULL, 0x6B9255E17E0DEBC0ULL, 0x0EE422D2BBB8AF47ULL, 0x75A632B5AB46F47DULL, 
            0x04E3D79DB65465C5ULL, 0x96D775CFEDE9F8C1ULL, 0x0103207F2BBC448EULL, 0x97DF73EAFC95A1FAULL
        },
        {
            0xECDE3A38F2861DBAULL, 0x656970280F4DC4A4ULL, 0x817155585C13E2CFULL, 0x02FDA52DAD644B87ULL, 
            0x37F0554BF1838C8BULL, 0x6E0A22E7E4C69B48ULL, 0x44C13F9FD83C1289ULL, 0x60F5BB345671CFB1ULL, 
            0xE3023A30D26F72E3ULL, 0xDE2B2E96556B9454ULL, 0xAE56C4661F29112AULL, 0xF6738400BB8685C4ULL, 
            0xF508345B77B5B389ULL, 0x18EC3464A553687FULL, 0xDB52D55710E9C9FCULL, 0x068E12B8CA30D988ULL, 
            0x0BEA79C04A19F843ULL, 0x94AB09BB0565F4EEULL, 0xB11676C4B3C745FCULL, 0x75F2ECA4E985FF34ULL, 
            0x89A5A69CFF1BD328ULL, 0x5B01157810DA22CBULL, 0x393D2B41FC5400FDULL, 0xD6056905E9B4F81EULL, 
            0xDAC211556A9FFCFFULL, 0xA47C3FC5D16C48DFULL, 0xC71A47E3F0B7526DULL, 0xEEEEB52DA51110BBULL, 
            0x245B955133AB2594ULL, 0xC72A8FAC0DCEFBC7ULL, 0x6F0B3389AD73C670ULL, 0xE75AA45AC6A8308FULL
        },
        {
            0x5EDA41C3E2F1D512ULL, 0x560CCD32FC92E722ULL, 0x1D9E4956F732F041ULL, 0x1E8879628CC5E184ULL, 
            0x28F3FFD11ECD44B9ULL, 0xECF8E19E9DC01B92ULL, 0xBE31B6CCA4936A93ULL, 0x6281F63562047006ULL, 
            0x622D1D60D4227E45ULL, 0x9FC6203C07F6E287ULL, 0xA5E97F4624CE24E7ULL, 0xD4766024039BED8AULL, 
            0x9711349BFA951332ULL, 0x899B801143E2F905ULL, 0x81E66061F5F61455ULL, 0xD0B689EF03A1D2BBULL, 
            0x4E24E6B0C06778F8ULL, 0x3FDD6F748BC0C0F9ULL, 0x6DDB9C09F88F9268ULL, 0xF4CDC4BDDE5E1164ULL, 
            0x5B49E70734E7E6BBULL, 0x06218993508944C7ULL, 0xF7535A2E35BC3131ULL, 0x16A307F2599FDD91ULL, 
            0xBFDCA5F2BD671829ULL, 0x76CA017625ABE7BDULL, 0x50DB55C89C937A87ULL, 0x695AA7FB78735FFDULL, 
            0xF06A936BC8D06C6BULL, 0x0962AFAEC48722C2ULL, 0xFCD119E6900EB520ULL, 0xC283F783320D52C6ULL
        },
        {
            0x00BAF47E749EFBB6ULL, 0xE18FB84DC799134AULL, 0x3B721C7A46CE0652ULL, 0x243497FB6B2F18C5ULL, 
            0x606058F0BAE64700ULL, 0xA836D1C300C6B983ULL, 0x4F63B412AA30F526ULL, 0x313A56EBAF55A450ULL, 
            0x6C29387E4E93E4FAULL, 0x6CD4A453EEFC7B3FULL, 0x5DD3F03E58E6337EULL, 0x6C6BC0B4401D986DULL, 
            0x5D3F42CDAAFF0CE3ULL, 0x07A3C19F851FAAD2ULL, 0x35C8AF38AD87ABF4ULL, 0x28E6060AD32B748AULL, 
            0xE7FD6145B22C92BAULL, 0xC21D92FB20B43817ULL, 0x0B7B991F04E0EE0BULL, 0xEDA0F610756D6317ULL, 
            0xCD60130236ECD586ULL, 0x6C7D19538D77E614ULL, 0xE3356A7DD8D72F1EULL, 0x8D2834D45ADBDC95ULL, 
            0x7E443EF543862B8FULL, 0x6C2788EDC90FD40BULL, 0x7142AD0FD853D804ULL, 0x8A8640EAF2ED33D4ULL, 
            0x74A2832C1B077AB1ULL, 0xDEDBC0DD880CE8F6ULL, 0x5632CEA3B818DB55ULL, 0x5D56CB0006E0FE3FULL
        },
        {
            0x75E1ACEFCCA8BA37ULL, 0x5847CB634AA5D8E5ULL, 0xBF2569EB9333A0D0ULL, 0xFB6D5557615F97D2ULL, 
            0xC0CB6E216AAE3494ULL, 0x0DD34928EAA86403ULL, 0xB5B0C6FB2596699AULL, 0x84846589A77AFBABULL, 
            0x4A0C1DA928216139ULL, 0x2C7BD28842F2A915ULL, 0x80FEB0199FC75430ULL, 0x11F9D7663C1512B3ULL, 
            0xE49BB36ACDED77FEULL, 0x30B9D6F3DD01D393ULL, 0x6D73EAD04AB976D6ULL, 0xD157BE53996AF64AULL, 
            0x0FA5388C9D8A6860ULL, 0xC4E5DC09EA6A5320ULL, 0xDE87AD8FF5CDAD9DULL, 0xA0F04D0233A5ED7DULL, 
            0x0C2C3B2D1954995FULL, 0x852BD6ECF77088A3ULL, 0x81E5C3EE7EA8EFABULL, 0x001D3833537A653BULL, 
            0xBE5CE6CF02C7413BULL, 0x154E2DD1D566282EULL, 0x11ACB19476E70AA5ULL, 0x582E9A0CDEC8B783ULL, 
            0x2589E6F6E53B20F6ULL, 0x7374E03323BEFF76ULL, 0x6A864D7DF3073143ULL, 0x08C8623C766CDB23ULL
        }
    },
    {
        {
            0x85A532E8B55A9D75ULL, 0xBCCA52433F1210B7ULL, 0xFD2A8CDBD2CD7D3BULL, 0xC78E37851A7316E2ULL, 
            0x2982F069D6C2EB8FULL, 0x2FB226D307B45546ULL, 0xE3A3A78B7F0EA397ULL, 0xF7B323DE9E304C57ULL, 
            0x2C0B4B41CD084AECULL, 0xB58AB2BC6A07E886ULL, 0x6E02BFFBB6ABAE9EULL, 0xB63324E94370DD07ULL, 
            0x43BAF80FAA4232A1ULL, 0xF7892FB179495A04ULL, 0xFE8D8FBB72231A3FULL, 0x5E92022DCA2B58EEULL, 
            0x72B59A0B09A4FDB9ULL, 0xB3466730EE5DB4CAULL, 0x37F27CCC92DC5A26ULL, 0xCE517126B6129B82ULL, 
            0xABA7A19794A2F4E1ULL, 0x95B1D34D31DED492ULL, 0xE0C652DCFE016154ULL, 0x46417980839BD202ULL, 
            0x380678A66FE0B6E9ULL, 0x9D5BFC32D6BB6E58ULL, 0x336D487BEE7145FCULL, 0xA8E43DA5CAFBD09CULL, 
            0x2E69CE110403AE75ULL, 0x8BA56EB1CCB45B3DULL, 0x47021638D16823EAULL, 0x4BB17487D124C797ULL
        },
        {
            0x99FF4057B522EE43ULL, 0x46E54CEE5960E455ULL, 0x8A4A0EF9AE42B319ULL, 0x6CF173ED90950020ULL, 
            0xC278BB9BA5DF62A8ULL, 0x474E393A31C4E2C1ULL, 0xD67CEC7D618B7829ULL, 0xB9CC3FE1B7829150ULL, 
            0x31BF1764245E44B0ULL, 0x717ED06C07CFBACCULL, 0xB449E9EB29CE83B0ULL, 0x25D82F2325837713ULL, 
            0x85BE4534D068A196ULL, 0x01D7B1319C266FBEULL, 0xA70E124873518AC1ULL, 0xD0D4675D1203EBD0ULL, 
            0xBC71482276B41B7FULL, 0xA7917D4BD53D3F5FULL, 0x86121D9BF9201F9DULL, 0x92BC2F2EC5FE589DULL, 
            0x9D99368208C40555ULL, 0x8A8D575CF6122262ULL, 0xB2DFBB22C990B352ULL, 0x6F3EE6FCA49E9212ULL, 
            0x14210C44E3A14EF5ULL, 0x5AB0127D206148E2ULL, 0x36EBFD1BCC138F35ULL, 0xCDBC8F5B22E50D50ULL, 
            0x270BD89A54A51FE3ULL, 0x876786806BE3DBC1ULL, 0x9FDB3C3567F59F56ULL, 0x4E3EF21A0CAE3CC6ULL
        },
        {
            0x861063553426CA9FULL, 0x8B24DF3B0D00D1E7ULL, 0x78E8B98653E97CBAULL, 0x4B398B9305399A93ULL, 
            0xB967D53B171D9156ULL, 0x4224DBDFB72D5B7AULL, 0xFA8965B14E2C5AD5ULL, 0x278E3615D52F83A8ULL, 
            0x3E64F86C0035E0EDULL, 0xE411BB05FF0425BFULL, 0xCB40AD6239F154A2ULL, 0x3BE160513D624ADAULL, 
            0x0B3C3C9F52264FABULL, 0x448AFD1739106A17ULL, 0xDDA6FAE5D65A9C72ULL, 0x847495E8D502B5E9ULL, 
            0xEA56AE19A9765101ULL, 0x1A5B007B08D3046DULL, 0xA1B4BCEF14BAA3EAULL, 0xC45F7C8FAE4C8FAFULL, 
            0x470FC2CBC243190CULL, 0x04410196EB99ABE4ULL, 0xD5A7B481C4D631B4ULL, 0x796C003C7C0DD778ULL, 
            0x7B4FDCE9369E2785ULL, 0x682E687927E63C78ULL, 0x3C9BBBA38EB74307ULL, 0x20C6900A4B3D8FE7ULL, 
            0x92CB8E120974C466ULL, 0x6416E898457AE519ULL, 0xCBE192BCC158381AULL, 0x29886BE5E2F6383BULL
        },
        {
            0x1773F39E2EF10329ULL, 0x532AC88A938EB1F5ULL, 0x4924F7EF3BF7C935ULL, 0x294F7291CDD2316CULL, 
            0x8B596DC9B694DC89ULL, 0xD0329CC076F25668ULL, 0x6595123E4E6D9817ULL, 0x57536C84D3F5F12BULL, 
            0x1F6D2471FF5FCFB6ULL, 0xE6213490C60EAB98ULL, 0x8B0EE52067F18E19ULL, 0x267FCA69206FFF05ULL, 
            0x2B35B51F5C168256ULL, 0x5E60AB9F030BF636ULL, 0x7E9944844F49A042ULL, 0xC0E366DB3E15BCD9ULL, 
            0xACFB8BAA7367DB8BULL, 0x65A7CC94C98C2AE4ULL, 0x572375CEA85B67E6ULL, 0x0270C08210006342ULL, 
            0x4812469897C098EDULL, 0x6D5B733DDD2385A6ULL, 0x545FD4FDB8917670ULL, 0x6585E476BB52330EULL, 
            0x2E35A6C37649C831ULL, 0x49EC76931937A9F9ULL, 0xBF54A3348DEAB3BFULL, 0xC91BD3D0E03F344BULL, 
            0x871F848B8BA55895ULL, 0x09C7017CD500F076ULL, 0x503A7BBF9EA1465FULL, 0x672B45D96B437AF1ULL
        },
        {
            0xB7F4B0586EF3F91AULL, 0x2F89748537EB79E0ULL, 0x0E823C237719A2B4ULL, 0x57F29941370B60B0ULL, 
            0x0EE54BD1AA6DB08CULL, 0xEAF19BCB1D7161FEULL, 0x6B761C2890DF5150ULL, 0x7DFF868AE2C51FA2ULL, 
            0xB7C06EB0B66785BEULL, 0xB7284C98CC5B58AEULL, 0x03286673B23AEF8DULL, 0xF457C8C036C30229ULL, 
            0xB00B58DA71D20AA4ULL, 0x01D7263D5C37A6CAULL, 0x9EA3BCF3942AD324ULL, 0x9438C5D6CB096F4CULL, 
            0x14FB00F3F28A1044ULL, 0xAEFDFA809B28A831ULL, 0x237ECD7BD32051B1ULL, 0x92EC832542B02B35ULL, 
            0x448C7BCAF7BFAB88ULL, 0x280B6A069501B0C7ULL, 0x6BEBA7F1B3338957ULL, 0xC6B2B715A024339FULL, 
            0xAAAAFAE02ADFAC8CULL, 0x408E70474F5CDD48ULL, 0x8BB87CF7992C24D8ULL, 0xD0522E621C2039C5ULL, 
            0x5609FF2D21325222ULL, 0x359095DDFFB7A824ULL, 0xB81CBB7CB9C6CA5DULL, 0x46F0B729B20D62C5ULL
        },
        {
            0x584F40A77A63370CULL, 0xC4127ECACCB01CABULL, 0xEDA0451C79399869ULL, 0x4BDE7E472E75C1E2ULL, 
            0xC42DEE113028DB1BULL, 0x66D1750947B0CC64ULL, 0x3EE4D6C78AC88E15ULL, 0x2B24CD2EF0B69AB4ULL, 
            0x34C5BC8477DCD255ULL, 0x118E124E086378FAULL, 0x43B46FA982878422ULL, 0x40832F9CB3B011EFULL, 
            0x8AAD69A53FD97012ULL, 0xC8D21FE35C22BF6EULL, 0x7A5886E5EE240893ULL, 0x8A8E3ADC5052BC64ULL, 
            0x1FE970DD23554581ULL, 0x0DB34E77E867C089ULL, 0xC506CA174EFDB30AULL, 0x61C7D8D84F0E1374ULL, 
            0xF84ABE69EB445B3EULL, 0xFAEEF9319FAE0C8CULL, 0xD2548E40A3C67258ULL, 0x4C2B1FF616BE0EBFULL, 
            0x8B4CF4D6A59A59DFULL, 0x98E26DA889D23D71ULL, 0xC5F9BDE6A99E0D53ULL, 0xA468A958DC2195BDULL, 
            0x0893D7D1E283640CULL, 0x339A0382E128E6F6ULL, 0xC22796BB22DB1D18ULL, 0x8ADD1BC0C4E272B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeySpawnConstants = {
    0x299802FA602E7F78ULL,
    0xA5C87D2BD736EB75ULL,
    0x2B9992C7EBF1DFB2ULL,
    0x299802FA602E7F78ULL,
    0xA5C87D2BD736EB75ULL,
    0x2B9992C7EBF1DFB2ULL,
    0x03B15D64EB4298F2ULL,
    0xDA5B8B25A90A1833ULL,
    0x59,
    0xE4,
    0x75,
    0xEB,
    0xAB,
    0xAA,
    0xEE,
    0xB0
};

const TwistDomainSaltSet TwistExpander_Arcturus::kSeedSalts = {
    {
        {
            0x81D0151FD4AF5B31ULL, 0x5202F022F2B90839ULL, 0x1076DCBAC4001612ULL, 0xFE028262D9E6D576ULL, 
            0x6E7EA3D6FB4F6C57ULL, 0x311222BEC39F3591ULL, 0xCC3C29450D68B7D2ULL, 0x1A5957429F3E138BULL, 
            0x1D3FCE5FD1C94B65ULL, 0x198E88896FA82A87ULL, 0x951A9781D6FB6EE5ULL, 0xF1D383DAA6A876DFULL, 
            0x8489741F0754A9D9ULL, 0xBA4524C72E07E04EULL, 0xC6A830059DEA10BDULL, 0xF0B4F269BBF1967DULL, 
            0xA74643341201A4A7ULL, 0x66A6376048006887ULL, 0x0B1216791C949519ULL, 0xF6D48FB5882347EDULL, 
            0x010C821792913056ULL, 0x1B52B169AC5BF71DULL, 0xD7A1B71696541FA9ULL, 0xF51BD7C739DD58E7ULL, 
            0xA4C7F175D5B78983ULL, 0xB5EDF96B1BFB956AULL, 0x8FCAADABD5131919ULL, 0x7F7B5261FA52FEF6ULL, 
            0x54888A9908FC9DFCULL, 0x485C775995B0B278ULL, 0x6A2781E07EF71C88ULL, 0x8D373F6B8B329561ULL
        },
        {
            0x8C981803EDF81B21ULL, 0xEABBDC77008B8DE0ULL, 0x8928E4B118591C0FULL, 0xE8743F84201225A7ULL, 
            0x249CC8D0B7FBF9ADULL, 0x24F8EAF65561B71AULL, 0x02C35FBFA630FB7EULL, 0x50CD629CF6139CA3ULL, 
            0xFE0731446F8E949CULL, 0xCAEE72A80EA1984AULL, 0x361A51B0E15E7977ULL, 0xFE45AB2733FC1EA9ULL, 
            0x9DB3FF6A8F0682B6ULL, 0x9B4CFC66AB67E186ULL, 0x0EFDAD13611E35C3ULL, 0x72717AE41F8FD5A8ULL, 
            0x2CBB39BEF03EB0C4ULL, 0x6361FFF87FB1802DULL, 0xB4E5BD2A496FD59EULL, 0xD3E5D0FC0CBCF88FULL, 
            0x0350AC8D60F8274AULL, 0x0D5669A84A076C72ULL, 0x3246489D56A4B122ULL, 0x50053938511F6231ULL, 
            0xE554C66DB9CCCCD0ULL, 0x73CD876AD3C7874AULL, 0xA336181DCAA7F120ULL, 0xBBE6C07812CDA9CBULL, 
            0x36880F997C2A0013ULL, 0x4AC6385EEA547A8BULL, 0xB71664855B314360ULL, 0x5D484D707BBFF74EULL
        },
        {
            0xECB824CFA7E98657ULL, 0x9750D78865F4C3B7ULL, 0x9D65C8BB0C1A5006ULL, 0xC0BE4580883DF53FULL, 
            0xDEB51617476C044FULL, 0x9EDEEA251977699AULL, 0x1BB55C1281D2928AULL, 0x20B6BA610D11B364ULL, 
            0x8A2DDAA026E88651ULL, 0xCE60858FF0B6F8B4ULL, 0xBC395707D0A94DB5ULL, 0x27815529CD562E72ULL, 
            0x2141AC87FF8F19ACULL, 0x4715818BB2AB2947ULL, 0xD196F7ED5290B85FULL, 0xBF28E61BD90923DCULL, 
            0xAA55A090CA04121FULL, 0xFDDF684E7C9F3DF2ULL, 0xB86E5F7908DB5C2AULL, 0x18DBD86FEA6A13F6ULL, 
            0xF2F6FE4884A8DC1AULL, 0xD3E77682E14630DFULL, 0xFF2C6EEC9B52D023ULL, 0x60B73B5B8EE1B303ULL, 
            0x89A2116437214C5DULL, 0x2608F639BFE7E254ULL, 0x15A5CFAC31B4C9E7ULL, 0xEA86C93BDCB5DCEEULL, 
            0xCBE33CFAB0BBC3DCULL, 0xEF0D9E848739D3C9ULL, 0x4C8AFD3FA01BF00EULL, 0x73BA2B970B54FB27ULL
        },
        {
            0xF8CD993CEFA12F18ULL, 0x3A6E5C4979433E0CULL, 0x6C35D2577CD9E288ULL, 0x491F13AABBA6CCCCULL, 
            0xA81F42806B9E4D46ULL, 0x9D33BEA568ED9BB1ULL, 0x7F1DCF5F68B46B21ULL, 0x296CAC54C70C22B2ULL, 
            0x5801F0EAAE73ED6CULL, 0xF68BF8D4578BBC22ULL, 0x370740C6A7168984ULL, 0x7B8D3F117850C267ULL, 
            0x73A8AB64D3ED2CE5ULL, 0x2721DA7A9B3CF2B6ULL, 0x61799D6BFE571A6FULL, 0xF3ABA7248618F0D3ULL, 
            0xA48C8033687D6EE2ULL, 0xF4FA3D7E5F049F31ULL, 0xD6B8E589245A223FULL, 0x7E8D55082A612A40ULL, 
            0xD49C8EDF6EEE7CBDULL, 0x792A019FAA20A4C2ULL, 0x83D84653B723FB94ULL, 0xDB78C41BA6C80023ULL, 
            0x9D0DEACAA1F9EDDFULL, 0xA09665A4DC0F846AULL, 0x90A79E865A418F4BULL, 0xEBF7DA0F14709834ULL, 
            0x272671801B0F115DULL, 0x34186A1077164CF6ULL, 0x5DC1F629942AFF1DULL, 0x0F00D3E9BBA103F2ULL
        },
        {
            0x13B86B8391807EE2ULL, 0x85DCDE07636C8A24ULL, 0x48D636DC633AA6BBULL, 0xD83B46C7E2728E48ULL, 
            0x6A42E734A8F63B23ULL, 0x936EB9DE5C0B9BE3ULL, 0x8F51B313F5CCC325ULL, 0xD867976A19DE622CULL, 
            0xBF19B1A25DD63D8CULL, 0xC04CD9ED9A1D00F5ULL, 0x9CD5CDCAA8E6FF17ULL, 0x7EC7D43E6044B0C5ULL, 
            0x6F99DDA0F9BEDDAEULL, 0x5188D7AE4CDED6CCULL, 0x494370C8C65A1D00ULL, 0x1DA2A3A48B6FB273ULL, 
            0xC356DB839DDBCE16ULL, 0x49830FBD4962D4E3ULL, 0x5F4B605773DA79D8ULL, 0xF0080EE05E029AE4ULL, 
            0x1248243B4A9E1857ULL, 0x0F766C0D8A1022BFULL, 0xC6B16DFAF5E3F4E3ULL, 0xE65D3682B01433E6ULL, 
            0x7A3F5FF725EA33A1ULL, 0x19416C6A0DA0A686ULL, 0xF1EBE804FCAF5292ULL, 0x222AD47D831C3937ULL, 
            0xFB1AACF28BB9ED2AULL, 0xA044296B7470BAF1ULL, 0x77CE68459A8434DEULL, 0x28DEFA7E36ADABE3ULL
        },
        {
            0xFDB4F5517B2D7EAFULL, 0x58A984A64D644521ULL, 0xC44BA6E894E5CB74ULL, 0xED0BDA88A92B98F7ULL, 
            0x0248C918B5B70668ULL, 0xD632FB97E8807C21ULL, 0x0A887CA52DA0099FULL, 0x0FD88C9973CDDEBCULL, 
            0xCD37C2CC06D2FF34ULL, 0xDECCA07F0723FB93ULL, 0xD8C3050271D06742ULL, 0xCC0D084D070FFCBEULL, 
            0x51C4E646D8B89810ULL, 0xCE9EA902C9A034E4ULL, 0xAE21F4F06F1E8766ULL, 0xAA74201C85AAC171ULL, 
            0xB306473C629F1861ULL, 0x7DB84622F0C46DD0ULL, 0xE9B5004203CABEE8ULL, 0xB456312240E1CA71ULL, 
            0x776FD6CE5977DB15ULL, 0x97B261BB4CA90E78ULL, 0xC9E3A79D6CF8F05BULL, 0xD5D9E74827EFF3BCULL, 
            0xA5929052A588551EULL, 0xD61BF569F6F0F1F3ULL, 0x794BE78724ED0C2DULL, 0xDA4ED4F0AAA639D7ULL, 
            0x42C86AB5D571424DULL, 0xFCE8A452C9448914ULL, 0x1AB4C60728EDF06DULL, 0x34E34BBB100A0F9EULL
        }
    },
    {
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
            0x6BC95A898B897424ULL, 0x61E908DC23D8FE9EULL, 0x926B3FC7B023BB77ULL, 0xE6B99D3452A0189FULL, 
            0x7B36F08A39BAE0E4ULL, 0xFF6019FFF6A3363EULL, 0x28CFDDE547AC6367ULL, 0x5C1AC7364AD457A7ULL, 
            0xC9AD39D9D440C2ACULL, 0x92E36AC093C554D5ULL, 0xD8FD35A15FAC1A97ULL, 0xFBD841CC99861B5DULL, 
            0x2EB431B042B6C29CULL, 0xD6979BE6523AE44BULL, 0x6FEA4BB20FBB7240ULL, 0x004B8090CBA960F6ULL, 
            0x6429B7D61BC0C58BULL, 0x304C16EA5EE0DD92ULL, 0xCCC39BEA22DE43E2ULL, 0x74276D34C2414C50ULL, 
            0x7E5F99126EFFB914ULL, 0x6E37A195BBE40FBAULL, 0x4890C1F6CC739ACFULL, 0xC50F6E9711CAF5C7ULL, 
            0x237D89DC162F947FULL, 0x1AD123B057F235B7ULL, 0xCEA50C9F414EBC46ULL, 0x4A349AB6790AC8D1ULL, 
            0x7E7EE47122EF37C9ULL, 0x2FA7AE21E6708857ULL, 0x1CA6DBDB8D130615ULL, 0x76192C34229DE858ULL
        },
        {
            0xD3623A1130976073ULL, 0xEC523EDEFC220E77ULL, 0x9E7CB6BE578CCCEDULL, 0x1C8C60A232AF2348ULL, 
            0x75B5FE215048C145ULL, 0x199B44A2ADD99064ULL, 0xCE9734BC3CE67AD8ULL, 0xDF9949C931E1CDCDULL, 
            0x3B1550CCC7F9301EULL, 0x702B4778747AFEA6ULL, 0x01326391479299E5ULL, 0x0044A8C6DC2EA9B7ULL, 
            0xB96703F606C823B7ULL, 0x599805FDC0A38219ULL, 0xFD78C5AE6AE13ACFULL, 0x4E2B6958F6CCB1E5ULL, 
            0xB39210673E7E498FULL, 0xB399B4DE8682553AULL, 0x47A7E6CB599CF774ULL, 0xF08082EA7E0D651BULL, 
            0x74498202114E1893ULL, 0x35447FDD48A99E93ULL, 0xF8C5FEC541371B80ULL, 0xA273B55D64DAD933ULL, 
            0xBEF00CC1DEFBBF5EULL, 0x2D3BC28DF1694C84ULL, 0xC5821456FCA8D44FULL, 0x5D33F85FB18CA74FULL, 
            0xAC165088D699C6ECULL, 0xB01D70B91F1FB245ULL, 0x91D3D492D461C19AULL, 0xD833F3AA2A6013AFULL
        },
        {
            0x93560EFCE91FAC58ULL, 0xB02E44958090873FULL, 0x918B323E2BD4A321ULL, 0x6F902B17692AB47AULL, 
            0xC7B584D970E701F4ULL, 0x9FAD777CF3020218ULL, 0xEAFBD97A54F3CD4EULL, 0x4D65F6C27611FAAFULL, 
            0x36C468DE5A50EA85ULL, 0x787AF0BAD207B967ULL, 0xA845797E71A6BB17ULL, 0x266C190596A90EA1ULL, 
            0x9BA9D4C64EC789BEULL, 0x36EEAB97FB6D1DCFULL, 0xFC6137C7E476CB91ULL, 0x0D36A25CA89197F1ULL, 
            0xBE796567B38EAF48ULL, 0x29817350B878975AULL, 0x57366F4DB7BA7C4CULL, 0x67AD3DC7013F1E05ULL, 
            0xA937A460587DFB34ULL, 0x204247A52A8F40F3ULL, 0x99A03AC1C00A7ACEULL, 0x0C4846D283F6240AULL, 
            0x72B2856B55E91DA2ULL, 0x8A310A15CFF6D333ULL, 0x88615D8E31C5BA9DULL, 0xE6CEFC1687645030ULL, 
            0x0AE6EE78A239733FULL, 0x6279415F160CAAC3ULL, 0x78E9BA2FF5B40582ULL, 0x973D285B11424A99ULL
        },
        {
            0x0E393B26B22A827AULL, 0x70AC86615A2FCA74ULL, 0xE6E0FC4675E0E6DAULL, 0x1393B15CEA83D71BULL, 
            0xF16D8F4492818DDBULL, 0xE1264A061EF0A3D8ULL, 0x5A3CDEB0CD086451ULL, 0x8AB8A48B66238BEBULL, 
            0x4895558D344E5A93ULL, 0x6D284915563EECEAULL, 0x63A497EA3815D8B1ULL, 0x40AE41E43A584677ULL, 
            0x66C46085043AC77AULL, 0xE62A427E7DBFEBFCULL, 0x315D806781DC3662ULL, 0x2C32BB4C4443B0B8ULL, 
            0xC95346370111FE67ULL, 0x22A835E535DED818ULL, 0xBF230D0869E92E40ULL, 0x6CECE17D0990FB21ULL, 
            0x9FF99A258F343DF9ULL, 0x43BF982E3E893128ULL, 0x10367507A1A7859FULL, 0xD33A890CA8B6F4E2ULL, 
            0xA2ABD79E97087C50ULL, 0x0AB97B2A1823267FULL, 0x7D6435D856711E65ULL, 0xA0EB7C77352CE8B4ULL, 
            0x4AF01E52762FCD38ULL, 0xE3AE941FD7B99BC9ULL, 0xCA15B251E6C1BDB9ULL, 0xA832E424DD08B297ULL
        },
        {
            0xACD77A686486E5C7ULL, 0xFFED3CF60902C6CAULL, 0x080081F737ED4594ULL, 0x4D056878602B7BD1ULL, 
            0xBB0FBED665DA3DBDULL, 0x40DB4F8C19ABCF2FULL, 0xF85B3AE65545EBE7ULL, 0x03551E7C8A652475ULL, 
            0x816E81227659017CULL, 0xFA872B69549C2EDFULL, 0x0FF77A294FC8C1A2ULL, 0x73C4051A3318BE7FULL, 
            0x80D676FAC93DB28AULL, 0xC65DB6B7D13B5BF8ULL, 0x14940E2AF0C6999EULL, 0x6CD0BECE38100B39ULL, 
            0xCEB6B72E7EA80011ULL, 0x89C86DAC70FF9B88ULL, 0xE840A03BD854063DULL, 0x421503D360EE4B64ULL, 
            0x3862ABF8A264F322ULL, 0x87BB3A7A05DFC712ULL, 0x8FCCDF2E8A28BE8BULL, 0xF1F299A131667D17ULL, 
            0x6396119979CAF59BULL, 0xE4928E28BA696F1FULL, 0xEA2E6AC01A3B3117ULL, 0x46F782FCA9D09821ULL, 
            0xC4A32B6995EDC3F6ULL, 0x2E41B5E0DB4446E1ULL, 0xDE120FCFAC69F81EULL, 0x8899AB6A1F5A50B3ULL
        }
    },
    {
        {
            0xA77C2C8D6D91484CULL, 0x3ABA59B74DA152A0ULL, 0x06694D32994AA185ULL, 0x7E92301957FB6486ULL, 
            0x26542934D67801B9ULL, 0xE0B74F59B15EF9C2ULL, 0x7832ACC6258E8EFBULL, 0xA590286899CFFC31ULL, 
            0x6425F6CD675BB393ULL, 0x0738605E8B110652ULL, 0x289F43DD1DC68509ULL, 0x288128C3F9B4610DULL, 
            0xA699E95F0240362FULL, 0xA90020AF76E1559DULL, 0x299C7BDBE3A6A45FULL, 0xAA04E36EC42A2D24ULL, 
            0x67B5D8F3E390DB10ULL, 0x644490FCE2717C82ULL, 0xA89D81CC9C17FADFULL, 0x0A26796866335774ULL, 
            0x185BBFD486DCC6F9ULL, 0x2FF08B05A4186547ULL, 0x75DA82D2C45B1C9CULL, 0x5590B759B2DE7EF0ULL, 
            0x4B8EA0BCDC2CE4ECULL, 0xECFCC3411860A581ULL, 0xE7F252EBCA9E3CBDULL, 0x3F7D133D21B80819ULL, 
            0xC20DC84DA2EA293DULL, 0xE80DD9AACEB64DA5ULL, 0xA5E3B180E50AAEBDULL, 0xA07A7B5D84F5B5FDULL
        },
        {
            0x913EF629B22E391AULL, 0x659F886BE2C35ABCULL, 0x1CC80EE7AB23220CULL, 0x9A6B231E3FE1916CULL, 
            0x2ADBCEE72AF42913ULL, 0x5D9BD51CA7D8C1D9ULL, 0xC18EACBCEB5226E3ULL, 0x749C667FE4C67601ULL, 
            0xD0D3F44364226291ULL, 0xB3A3EE4BB9302AEDULL, 0x49E37EB9DA6AF461ULL, 0xFEC708F67ED51742ULL, 
            0xFCA65B898EBBF93DULL, 0x87FEDE4655586C90ULL, 0xAEF79ED41C953583ULL, 0x851025FD2AD39A7BULL, 
            0x09BDF86D08E764C6ULL, 0xED6D92868BE40757ULL, 0x4124112090E751DAULL, 0x21751088E5B87919ULL, 
            0xD9AFCE8E2EE8138EULL, 0x76C8B177600878A4ULL, 0xC109D11B2D59DF1CULL, 0x65E298182D3FD986ULL, 
            0x18B25C67427A3354ULL, 0x48767C535C78B6C5ULL, 0xB72B315F39E4B263ULL, 0x04430A675A863CFBULL, 
            0x1DA30EB451D136CAULL, 0x7D2ACCB2C2F428F1ULL, 0x19A55A48C44076F9ULL, 0x036D6A76B74A36B5ULL
        },
        {
            0xD926526F7BB338C8ULL, 0x38AD03F51294550FULL, 0x14874E4CCEE549B1ULL, 0x9427A4C89C1F3DDBULL, 
            0x80FA62127B174842ULL, 0x2D2472FDFD4048F1ULL, 0x2452D696A8E52AC7ULL, 0x3C224B7F4A262451ULL, 
            0xC0E2E5D92A084CA8ULL, 0xE0F29FCB21F294EFULL, 0x237455208E7BD16CULL, 0xBE20A385CF8040D3ULL, 
            0x106CEBFD8255B62DULL, 0xB9BC39DCC053337AULL, 0xA1900CCDD5658295ULL, 0x5D7D4C56315F3CC7ULL, 
            0x7B4ECEEF3113E138ULL, 0x00970F810E9FFF40ULL, 0x4BFDA26B0A65AB13ULL, 0x1AEA07A9588A271AULL, 
            0x291D92B6528AD08EULL, 0xAC99925716343C77ULL, 0x8D73F19CCC4D9FE6ULL, 0x653C9AAB24FB3FA1ULL, 
            0x3BBA772D44D7C28AULL, 0x7875C9CBD7260DC1ULL, 0x6A41F522BD40B863ULL, 0x788567364C54FDEBULL, 
            0x3D44849C415D7095ULL, 0x6DE1DE89EFD10110ULL, 0x18F41453C8195C93ULL, 0x5F8ED8A876C917C7ULL
        },
        {
            0xF82A4E3C471551EEULL, 0xFEB92D23672EE95DULL, 0xC06EAE1CC7E9DFD0ULL, 0xDE5D408420EB5AC5ULL, 
            0x20A1BA371DE15B4FULL, 0x45250062A05E7618ULL, 0x6B39862C025EF3ABULL, 0x032A4E821B1DA6E9ULL, 
            0x4574881292DFA01BULL, 0xFD7350E56ADC2068ULL, 0x903543950BA6188DULL, 0x49D37786E6310FA7ULL, 
            0x4F7BB4D758418E67ULL, 0xAAA721EBB1496EE4ULL, 0xAE8CDBE5C5AB8A08ULL, 0x053A43985E43625FULL, 
            0xD4EB9D2A5090C6A7ULL, 0x225557E4562F81F4ULL, 0xA1726FDDF5EAFEF0ULL, 0x39BA60F35B17F74FULL, 
            0xA6E69B6AAB2ABD3DULL, 0x46997412B74531B1ULL, 0xA721337F2157B17DULL, 0xB08ABFA9303C97D5ULL, 
            0x7C05F13C4C0FD351ULL, 0xD3BFEC1D18031924ULL, 0xE78A2B9CE8FCCAFBULL, 0xBE4DAD8FCA7A390EULL, 
            0x9AC5F35417CEFA72ULL, 0x4BE757888EF5CCCBULL, 0x1A26E8E7FF9CC764ULL, 0xC9B60C44E6D27306ULL
        },
        {
            0x7D5D659CDED054ADULL, 0x49DDCF1E9E849492ULL, 0x8A1C568593DA0D69ULL, 0xDDF02E209D065B2EULL, 
            0x05C679B631612097ULL, 0xA4D05DE71E3523A7ULL, 0x1EE775DBE9BED724ULL, 0x61EB6B069179FB64ULL, 
            0x2274098EB1BF0E7FULL, 0xA02BCFBF5E58E769ULL, 0xE6AD4EECD2DFAFBCULL, 0x634B8BD9798A8480ULL, 
            0x0E86F2F51F87488AULL, 0x704AB958592F626CULL, 0x13DBD6FF6EB0287BULL, 0xBABF369B4AC59B39ULL, 
            0xC400A0AB191D56E7ULL, 0x982A015C7D5D9C8DULL, 0x133DA79F9A3D9662ULL, 0xBDA577F1D52C2325ULL, 
            0x0099E3A4A239DBB3ULL, 0xE08189FB7E05D49BULL, 0x40EA721F3435AADDULL, 0xC3BC5BF01E024A1FULL, 
            0xB173FFC6199B861DULL, 0x578251EBF170D429ULL, 0xE66549E91ED6F9D3ULL, 0xAB99BE52BEC2BC06ULL, 
            0x64E41F74DC464972ULL, 0x5FDEF22B6CDA813BULL, 0xA4744F6E36EF436AULL, 0xC2CE694A321B53DBULL
        },
        {
            0x7CD086E373D0A237ULL, 0x06190FD908CE371AULL, 0xB7CB30624C09A276ULL, 0x14A54302BDDF7ED3ULL, 
            0x58EEBDDA37158659ULL, 0xF499186C91B8997EULL, 0xE8BCF8E89A70F158ULL, 0x9DDEE3282C77F356ULL, 
            0x912BF31A9AE94721ULL, 0xA7877D4C7C2CB60AULL, 0xA34DAE4F84B6A03BULL, 0x70E92A7673587808ULL, 
            0x8DFD8BFE71B650B3ULL, 0x5D36EA3D891DAA6CULL, 0xFD32EF3C9C81B2FFULL, 0xFD5A0B188B490766ULL, 
            0xA99479B4EAA3919EULL, 0xE6AC73C5F957B871ULL, 0xCA48F756D00ED7B4ULL, 0x9ED1EF53E7E6932FULL, 
            0xDD06DAAD16937A9EULL, 0x6532DF44DAA80CABULL, 0x97FCF3440DBCD748ULL, 0xB8CFDF5C83D48807ULL, 
            0xE7A720CEEDB76467ULL, 0xC5C08926B8E3B1E3ULL, 0xEA4D0823D25D373EULL, 0xA756DC944A9D60FAULL, 
            0x863C2CCA76EE7A04ULL, 0x42075A98CD9D6D6AULL, 0x92F6F640A209F4EBULL, 0x551614AB22A47E32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kSeedConstants = {
    0x9109980C4BEA74FFULL,
    0xD5F62E5A0E329009ULL,
    0x14C9A19D2E86E2B1ULL,
    0x9109980C4BEA74FFULL,
    0xD5F62E5A0E329009ULL,
    0x14C9A19D2E86E2B1ULL,
    0x1E78A954FD2D09C5ULL,
    0xFAB2385E63E90CC2ULL,
    0xD0,
    0x85,
    0xEA,
    0x31,
    0x61,
    0x14,
    0x7C,
    0x65
};

const TwistDomainSaltSet TwistExpander_Arcturus::kTwistSalts = {
    {
        {
            0x9686CC5DAFDA0AB7ULL, 0x46283465246BED56ULL, 0x8EE8657D031B0C08ULL, 0x50F4F22098F74CBCULL, 
            0xED6227D6B5D9950BULL, 0x53196FCDF041DA69ULL, 0x74079D3F33376E15ULL, 0x2893261B97ED7F6DULL, 
            0x3BCF7E0BDD42D5A6ULL, 0x65332B855E5C3B81ULL, 0xA3509F3BD318A6E5ULL, 0xC7B4E331469E856FULL, 
            0x7259082FDDD03949ULL, 0xBB40FA22A2A77399ULL, 0x0AAF7D0A03951EF1ULL, 0xE5500B2DF465F210ULL, 
            0x54319979083BA86DULL, 0xEBC457989BC04E63ULL, 0xDA6F6D13381BF518ULL, 0x063E4A67B0031E4DULL, 
            0x8D104F2286D89BA9ULL, 0x69A249B4CE4C420DULL, 0xE668B48F71861860ULL, 0x98C56DF8C13C49D9ULL, 
            0x89ECC9300B1F7836ULL, 0x11238B25E698291DULL, 0xF2B0F6D0166294F6ULL, 0x46048972BE359548ULL, 
            0x3D555E7D334310BEULL, 0x4F18122659F835D7ULL, 0x62A951F5126DF579ULL, 0xCEC26D41DBCDC6A5ULL
        },
        {
            0xBB072E7B8566B513ULL, 0x97B6B35814F90052ULL, 0xFC2CD8D4F1F933CAULL, 0x13ABD70CAA7E89E1ULL, 
            0x6FB088DADE800E4FULL, 0x7B5056519CABB557ULL, 0xDD4239E135B33F0BULL, 0x156BBBBFED847543ULL, 
            0x33572C03E0EC9C5FULL, 0x1FBFBECFD633321AULL, 0x4B2FDD8459E1C374ULL, 0xBBB26B0C18A2773FULL, 
            0xABD1AD7D936295D5ULL, 0x698571B2ED09B877ULL, 0xA6C9D3145CA36033ULL, 0x7AC33928DAF64B79ULL, 
            0x756BE601B7C6303FULL, 0x6BEE590D00A3356CULL, 0x4CA1063C0E5FC931ULL, 0x9A1679399D3CA1E8ULL, 
            0x647AE360BA10AEA3ULL, 0x84BE26A3E40E4717ULL, 0x31582A24A8F9A8E1ULL, 0x4F5FE54B7C935082ULL, 
            0x36DB11A32506ED56ULL, 0xB3D2CDE98369EAE7ULL, 0xC5116708F2E0E5FBULL, 0xF5C8A27CE1AF8DEAULL, 
            0xEA2567435D54E30FULL, 0x0A978D1CD44D6E2AULL, 0x62BAA0B57A757DABULL, 0x35F55A6D2538A82AULL
        },
        {
            0xCD7F61BCD71A58FEULL, 0xD250F83D282AD292ULL, 0xA7D8D6C4C7ABED0AULL, 0x9FEDABCCF2DB1097ULL, 
            0x5E3A0E23733F91C0ULL, 0xB328B96031CB0A64ULL, 0x33BA5F0988CC3DA1ULL, 0x8F2EC53F05AD4278ULL, 
            0x146B1FF156C4627EULL, 0xF1AB8FF428B69064ULL, 0xAA423D2785C1ACD5ULL, 0xD248F3DC871AD5DAULL, 
            0xE155068609A5D6A4ULL, 0xE2D31B8F26A19407ULL, 0xA815EAADF71B626FULL, 0x73E1F31B033CE53DULL, 
            0x78951AB47031CCDBULL, 0xFB82AB86B8B2DEBBULL, 0xAF3ABE80D9455F7FULL, 0xC9823356B0D790AEULL, 
            0x74EBE9ADC8E0DBCAULL, 0xC71C4DDEFCE722C1ULL, 0xF66EBB72C22812D4ULL, 0x7DB70237BB5AC5ECULL, 
            0xE6B014E30EDD22D0ULL, 0x605FD1C4C19953EDULL, 0xF39159EEA2CA86D0ULL, 0xD95030A61D617B11ULL, 
            0x9E946B260416185DULL, 0x1B26853D3D5D6B81ULL, 0xD938480E5EA5F825ULL, 0x027A62DF0B820F1AULL
        },
        {
            0x886A0F21177409E1ULL, 0x72CA473C78AB9ACFULL, 0xE1D262235328A3F8ULL, 0xA57E7C4B1BCD491FULL, 
            0x039A1E497725CDE4ULL, 0x5D05A5A0DEAC00E5ULL, 0x6517812EBA084D06ULL, 0x04477D51B3924E5FULL, 
            0x3394E37A0DFEDE28ULL, 0xEC985C58299D3640ULL, 0xBFC75BCF0CF8B70BULL, 0xC4052D2649C4E0A2ULL, 
            0xC48037A323524756ULL, 0x2FFE6E9BBBEC060EULL, 0x3F245FAB3936F5CFULL, 0x1806BE092444AB9FULL, 
            0x077006419BFA7D5AULL, 0x7E6F99C33880AFB0ULL, 0x780C958A01FB028EULL, 0x663BE72020A939D5ULL, 
            0x5DE3505770ED93A1ULL, 0x4D041C1AA946C8D9ULL, 0xAD18470BAA11AB9FULL, 0x56F8B748E3C9ACA3ULL, 
            0xED1F35914AF90145ULL, 0xB6C2D91F1D994DDCULL, 0xBB5B0ACB84F1E88DULL, 0x65BD43A434149F9AULL, 
            0x44B40F75D0D98600ULL, 0x6F4273A6B84C033EULL, 0x450A710CF9A49731ULL, 0x31AB8FABC414D3E4ULL
        },
        {
            0x2B2E0B79527FF2ADULL, 0xE04499C045425760ULL, 0xFEA3DF3220581242ULL, 0x92F6CD144B6AAC1FULL, 
            0x0089D4D64C75F844ULL, 0xDFDDAF969156A650ULL, 0xEEF7D80CBD4E6143ULL, 0x004F37F0DAB2E6F2ULL, 
            0x5FBD4FC751A751A5ULL, 0x1187148BE4DC3C8EULL, 0x964D374FFB94C9BDULL, 0x45E602257B83FC57ULL, 
            0xDE8E601AC4B45CC8ULL, 0xCD455AAE54EEE4EEULL, 0x23CC5FC174453250ULL, 0x61D76BD382B3B205ULL, 
            0x90FBA9C0522459B6ULL, 0x3DA628308F9A8472ULL, 0xA2F6CE31939F3176ULL, 0xE74590B40944F317ULL, 
            0x2B35B2B6AD266628ULL, 0xD5BA948CD367A21EULL, 0xC61F28BCCB3ABCC0ULL, 0x3B5FD3F0F10D94B8ULL, 
            0x9A10BEC913EEBEBEULL, 0x5F7D63F149317F09ULL, 0x814602B1E43423C5ULL, 0xC5100E29F5340EAAULL, 
            0x6EA8CA74E283FB58ULL, 0x92D9DFA44C059CB1ULL, 0xAB8F87A10637365AULL, 0xA1C3F8D684CF8198ULL
        },
        {
            0x8D7EFFB36E5A7727ULL, 0x9CC5E573792D3E1BULL, 0xC04CD0BFABD163B7ULL, 0x7888A9BCB397F4CEULL, 
            0xA54791540DCF01F8ULL, 0xBA8D89ABAB030207ULL, 0x404D7E179A06D498ULL, 0x8CD9BDF24AB3E941ULL, 
            0xF244E42ACE587305ULL, 0xFE9F1F2DAA3B3D7DULL, 0xE4C6EACE53C2850FULL, 0xED3DEEC6157AB6E1ULL, 
            0x52E5474BD9CF474BULL, 0x0E5A6FECF671F971ULL, 0xAC8F3DB33785F144ULL, 0x7758D566CAE541AFULL, 
            0xC2A5301D79F94251ULL, 0x08769BA5491F6C7AULL, 0x711B1258D0BF1ED7ULL, 0xDACDAA66F7DB8DCAULL, 
            0xD9D12FB8B3149DCFULL, 0x6AC35DA2F9F63F7FULL, 0x5DCC76525C584BCCULL, 0x80DC4AC6F6C39161ULL, 
            0x360C30C45AD6B9B7ULL, 0xEACCA8C6AB98DC6FULL, 0x8995634514C633E0ULL, 0x15AF4333FA10D3D2ULL, 
            0x7E816E0CB61D5FBCULL, 0x93B0F6F1E80A511FULL, 0xC79D359466CABBA1ULL, 0xB3D3736191293C05ULL
        }
    },
    {
        {
            0xE49937E49A6B1B2EULL, 0x0B178A08F57C26CCULL, 0x147DC3AF0FE63AADULL, 0x989E3FE1F8C44706ULL, 
            0x33198FF13443EB9BULL, 0xA27B1051BDC65D0EULL, 0x7A95FB92474B9CFEULL, 0x39099C3896E08897ULL, 
            0xCCD5F36C9BB7758DULL, 0xCC656BE448A18EC1ULL, 0x391B1A92FFB56B2BULL, 0x3731075D9F525190ULL, 
            0x23CBF3CD2B124D7BULL, 0x18B48AC807190046ULL, 0x5941B96327AE82BCULL, 0x2F33587A85738A76ULL, 
            0xE8C34894B9620CAAULL, 0x88076D4EAD619352ULL, 0x20D41CA68BA9A71CULL, 0xFC1F2EDF9C15EB1FULL, 
            0x6A6F94B466FEA46FULL, 0xC7406A4226EE10CFULL, 0x0335038145589746ULL, 0xAB5AFDE8A3EB9196ULL, 
            0x8AA48E254ABB8A3CULL, 0x4BD44E92B26FE1AEULL, 0x04798C0E1A67FD2BULL, 0xC3D08572C3D0B59AULL, 
            0x46F93CDF689B32DFULL, 0xE1FDC223E914BF21ULL, 0x1A87397D41593187ULL, 0x6465931B70FE8AB2ULL
        },
        {
            0x404B4BA0EAE1E7D9ULL, 0xC401AE9BA15EF1BEULL, 0xF2E3011C2895E2E0ULL, 0xF275817CE95E2E2FULL, 
            0xACF6A148C738F8C2ULL, 0x4F0C10371ACAD5DBULL, 0x4D1C74CF508AC353ULL, 0xD2DA3D496657A15AULL, 
            0x460E44246E0D4A4CULL, 0x241DA1AC8A61B93DULL, 0xD7E5A7A4BA618817ULL, 0x1A552B491C0CE9F2ULL, 
            0x7E3D46D9CF63D398ULL, 0xCA8A8A74B38F580EULL, 0x518BEB97425DFF3BULL, 0xC58D25A373997C20ULL, 
            0x802D49B322B379F8ULL, 0x8851B442F6B702D5ULL, 0x0221800CF4D8FBFDULL, 0xB6854676515BEB81ULL, 
            0xF794A07711B785EBULL, 0x00FF26C78C3B2B1DULL, 0xC791459F69E475DAULL, 0x1805C89BDAE0659BULL, 
            0x6AACA4D0027DB392ULL, 0xDF7253C37ABD365AULL, 0xC5BDBC044B9D6AFEULL, 0xDCDC38281FAAE07BULL, 
            0x60538850AA1A7102ULL, 0x4DBC1E876DE04330ULL, 0xBF21E44EA896D054ULL, 0x521116183DFD705BULL
        },
        {
            0x304D3A0117B3EA14ULL, 0x484EF577437F669DULL, 0x99C8248681D53645ULL, 0x47525FC4040ABA35ULL, 
            0xAF13F68289A6D1F1ULL, 0x4904A875D6755B56ULL, 0x7D4C74212774B8F9ULL, 0x36C5C67B2C41C3FEULL, 
            0xA5638FF932E5B43BULL, 0xA3FEB2F07C1A8901ULL, 0x4BA338FBFC346CA2ULL, 0x73C21FB9F45154A1ULL, 
            0xB1B478E1ECC52B32ULL, 0x14C067AF0DA06BF5ULL, 0x53A5F49F540A8D7BULL, 0x9339D1A56FE1EBEAULL, 
            0x940CEB5DBA95C13FULL, 0x23915751B655EC3AULL, 0x718FF5891E44F717ULL, 0x8F1D2A8740836BD3ULL, 
            0x2BB8285D8EEA09B2ULL, 0xDDAA8EE57DC4D797ULL, 0xB2960D8BB47DEC0EULL, 0xA27038DE8DE1B39DULL, 
            0x535CE6C39C0EA179ULL, 0xF9AC799439D07767ULL, 0x538F9763874CAFFCULL, 0x48DD996898C89916ULL, 
            0x4E41C33B702481AFULL, 0xB0AD90610156A190ULL, 0x9370225F8F807EB7ULL, 0x77774C9BDAFAAE43ULL
        },
        {
            0xE7E89E5E26C7EB23ULL, 0xB2F30E06F0450899ULL, 0x8E9B7CB807EB9265ULL, 0x4A43261A53B81069ULL, 
            0x93DB02E52C5C677BULL, 0xC22EE61B719D57EEULL, 0xD77630EDA8B5F8E6ULL, 0x6C52808AA96B009BULL, 
            0x299DEC53273FA037ULL, 0x9EC986C063F37F15ULL, 0x38D1B7EA14C8F75FULL, 0x9497CAF70393BEA4ULL, 
            0x0EECF2B4EF0FDA47ULL, 0x5B42F4192AD9BED4ULL, 0x65AE05501B8E0AFDULL, 0x66120CA492B380E1ULL, 
            0x4511D7E15B3E00A3ULL, 0xA4BF0A03AC5F2CC1ULL, 0xB49FEA0B35D09CE0ULL, 0x6A6191B6D3AE0D34ULL, 
            0x517F66CDD7C58436ULL, 0xCE6F2027C04C7BA4ULL, 0x32E255D189EF7D3EULL, 0x63A73D17DC600D58ULL, 
            0xBD2DD4093FCA7427ULL, 0x7EB379BB8A894EA0ULL, 0xE0CE12A35613B31AULL, 0xEA1A9724936BB19EULL, 
            0x7CD6A656978B2B12ULL, 0xD550392523A54E39ULL, 0x7A34FA11B1029F97ULL, 0xF0BDDFDEAE7F78E5ULL
        },
        {
            0x671334E3A39BA788ULL, 0xE0B5DA84EAC0A48EULL, 0x0C6E571BE6B23CE7ULL, 0xC4C5D5F65FEF1F25ULL, 
            0xF215ABA995E79884ULL, 0xF23450EE9B4ED039ULL, 0x90C11272F271DE95ULL, 0x03CC2629AFA6F427ULL, 
            0x83452B1CBA6449FDULL, 0x7076BA879826DC42ULL, 0xDFE7D5553AD16F93ULL, 0x37BC37449630AE1BULL, 
            0x6880113B80002253ULL, 0x10923E44769DAB2DULL, 0x414B119C5B58FEAFULL, 0xE56AAA44B42D8092ULL, 
            0x2072C0633BCEDF45ULL, 0x4505232832DDD0F9ULL, 0x6F55A1C849371017ULL, 0x69DC3E347E922F96ULL, 
            0xCC86566F658874B4ULL, 0x598AE1B6D8EE697BULL, 0x79E65D48E4FE2849ULL, 0x85D10079EF9A4B08ULL, 
            0x5E0BEDB37CFF53A7ULL, 0xDBC5F38D6444A70EULL, 0x8F7B1E681AF47839ULL, 0xD5DDD64FA46F4DDBULL, 
            0xFFADEC8B04E9C72EULL, 0x8CBB349AA31664FEULL, 0x8691DC16E63CAFB9ULL, 0x58B7BC831431C8DDULL
        },
        {
            0x0B1612FDC3BFE959ULL, 0xF35D7F124055B627ULL, 0x10065A7BC1F941DFULL, 0x3ECEE875EADFCB8AULL, 
            0xD2EEBD40BDA5F4E2ULL, 0x09171A0EE5F36FF2ULL, 0x8821C3F45AFC98B9ULL, 0xF68BA8278AE4B3F1ULL, 
            0x69F86C004C23AE6EULL, 0x6204F095488C092CULL, 0x9A22C9AF6B7ECCD6ULL, 0x64CBBEA4C62A051BULL, 
            0x4BAB04994ECBD5D5ULL, 0x366FFB40F80E1402ULL, 0xD3BB6A2958FCA075ULL, 0x8A13B584A65A92DFULL, 
            0xEDCD14B03B06E976ULL, 0x2EF12F2FE135E2D7ULL, 0x5C80C3F1ED6C6DF1ULL, 0xA77FBF5673D7FD2FULL, 
            0x53D7694244D0C6D8ULL, 0x1C88BD28AB04EB13ULL, 0xA44341A8A9B43642ULL, 0x39DC23ADC1008888ULL, 
            0x540E3E32FE238B08ULL, 0xF6D67A57695947E3ULL, 0x8950E7734E6AB21CULL, 0x955596A78BEC6961ULL, 
            0xCC9D91FCE6909400ULL, 0x160E6D92A56D3DE7ULL, 0xE19FC1FD5EE1136CULL, 0x68AFE2442E5DDAEAULL
        }
    },
    {
        {
            0xE2C4560258780B5BULL, 0x00097392A82F989DULL, 0x7E30E2FDCC7B6DC8ULL, 0x9F9E7889FB6E1F61ULL, 
            0x504379C5E0DA6C61ULL, 0x565E978E2A14B3D8ULL, 0x5F04DB0B8EDB6B05ULL, 0xF805359A10E87BA9ULL, 
            0xC0E022E56F4040EBULL, 0x9B65EBF5A85817E6ULL, 0xD843620F011D469EULL, 0x115BAC943AFD46DFULL, 
            0x43EC66C3B3E9F1BCULL, 0xED6FE13A72B56DFBULL, 0xA3D517AE877E7C8FULL, 0x4E67E80030E86B23ULL, 
            0x4DE5F864378BBC28ULL, 0x8EF579FD1149E9D8ULL, 0x660C00B2491A3072ULL, 0x9BF7656B3B1F93A8ULL, 
            0xC813544D27CB4F99ULL, 0x9F98DE9529BA7781ULL, 0x666ACF40B07F8E52ULL, 0xB6087F96739EE72FULL, 
            0xE17FF8CB06BBDDCCULL, 0xEB780F7E46C6322CULL, 0xB6B711870221F329ULL, 0x8E5ADA2E6110F692ULL, 
            0xDE9464CE3BBE1CB8ULL, 0x35259EDD732B3150ULL, 0x558C236054FC2F97ULL, 0x887F721EFA979148ULL
        },
        {
            0x16171E93EE660CCBULL, 0x014BA27B643F23C1ULL, 0x66BDFEC7AF29C5D7ULL, 0x9FB89B337FA49034ULL, 
            0x0AFB766AB5341C1EULL, 0x26BB05CC8F2DB924ULL, 0xC1202EA8146ED9ADULL, 0xBF4989D01BEE0E79ULL, 
            0xBDE213E711B1FC99ULL, 0xA1D1D7C7AA14779CULL, 0xAB21CBCA5F0796F6ULL, 0x19B7F6A143A86F5FULL, 
            0x169513BE4624934BULL, 0x463932AB31218C1FULL, 0x27184B7FB0F5AEB6ULL, 0x5444758A26E958DBULL, 
            0x7FE8F8E4B28A6A0FULL, 0xCAC1CFBE321E0D01ULL, 0x71FD9C2D64B91ADAULL, 0xF106BFD0AC6B7D45ULL, 
            0x55D76F868BEA4CAAULL, 0x6268C90D9A8DFB3DULL, 0xCF5AF72630B06A60ULL, 0xA8906B0AC06DAB60ULL, 
            0x01CE84C1848B503AULL, 0xD946D8695A836596ULL, 0x4357732327B14119ULL, 0x7ED9BEAF27473349ULL, 
            0x9D757097983206BCULL, 0x3CC90A576681311CULL, 0x152EC194B65267C3ULL, 0xC7F09046A0DC560AULL
        },
        {
            0xFB3A35F67BCD3F77ULL, 0x2EC2FB466AA0E2F1ULL, 0x10AC0F722D39A595ULL, 0x8EDF941322BCB6CFULL, 
            0xA50D4B9CB18B5466ULL, 0x792BFF7B027F5143ULL, 0x89F4D9DD0A9B19DFULL, 0x33772DF37E32EF69ULL, 
            0x0F78C119F3A64E71ULL, 0x9457F470837A9BB7ULL, 0x9C9777B3D19CF887ULL, 0x4F95694886F92BB1ULL, 
            0x37A430BCD02CA85DULL, 0x282454203437BB92ULL, 0x7B2737F0CDFA2C0BULL, 0xDF45DEADCEDD0BE2ULL, 
            0xFE8F2A26B5ED30B7ULL, 0x7E31E2819508DC00ULL, 0x65497D7596D51F60ULL, 0x180935B5E8B7FE4AULL, 
            0xA1C8878FA922FB01ULL, 0xE85A0AFDF5C36551ULL, 0x8DCE07C34BF595A6ULL, 0x37176AC34AFC674BULL, 
            0xFE334217060C67AFULL, 0xD444E509ED43F5F0ULL, 0x1C082FEDAE05E2BDULL, 0xC6231880F6CA811FULL, 
            0x38D9E772FB74348AULL, 0xAFAB68DAD9EB9146ULL, 0x28A17746F6CD15DDULL, 0xCDFFC9F07A64E38BULL
        },
        {
            0xB54917E0FF612010ULL, 0x595E6B1F070001F7ULL, 0x7BAB9311ADE4C75BULL, 0x8B51BB776F1CB09BULL, 
            0xC3F5B87136421C1FULL, 0xCFFD703F7E9FBF39ULL, 0xCE103A73C5D06054ULL, 0x58BA2A97CF9EF56DULL, 
            0x1F118F90C55169D7ULL, 0x0715E1C18BB8A08FULL, 0x2914FCAC788F0A3FULL, 0x81B82CF1AE560519ULL, 
            0x57C0337432BD7810ULL, 0x1CC5D94B00242200ULL, 0x9EB841AF1BC000A4ULL, 0x118BB787BB39A618ULL, 
            0x29B3AEB075A8D908ULL, 0x11913101082BD3FCULL, 0x1BECCDA0D1AAAB50ULL, 0xAAD65BB4C82336A6ULL, 
            0xF0A7BDD830263B44ULL, 0xB99D80BFB6DA3B06ULL, 0x0140941403B1C49AULL, 0xA5C6A30A8CCFEE49ULL, 
            0x4BE392FE89844A31ULL, 0x15646B72F16751F4ULL, 0x5A701EB2D343453EULL, 0xEBAF2E9FAF4199FDULL, 
            0x16BEA59C9A0D58B3ULL, 0xCF356A7ECAA0DC5FULL, 0xBB60FC278883760FULL, 0x3B3AA45CAAF38098ULL
        },
        {
            0x573A2078323028F8ULL, 0x18E153E0876B19A5ULL, 0x8B79CD60EF5D81C1ULL, 0x575782A4A867B25DULL, 
            0x0967E4D6E58CC50DULL, 0x8565EA20C0699A5DULL, 0x541BDFA7C0082DD5ULL, 0xEE6D8D4244602478ULL, 
            0x177FA3C9A8FC526CULL, 0x3254C4AF0D3298D2ULL, 0x2CC26078D8E1B265ULL, 0x5CF61BC67E1091ACULL, 
            0x2BA51811EE6824DCULL, 0xCE00D120DAA7590DULL, 0x6A4D521AF8BE32EFULL, 0xD3894562C1FB5AE8ULL, 
            0xE479F24E1309DDDEULL, 0x17F50F4BEAA53A88ULL, 0xF463D262D77D8AAFULL, 0xC68A28A1F9D63632ULL, 
            0xDE721EE2EB9AC50BULL, 0x63AA2E135D5FA61CULL, 0x60EFE863E180650EULL, 0xF3BF9CBCC57BA5DAULL, 
            0x410A4E2F1541946CULL, 0xCAFE2BC83FE6E519ULL, 0x105FF33FA7F33B0BULL, 0xB4C3A931F82F4DADULL, 
            0x8B7EE6D8CD696A95ULL, 0xD27942B897265FE0ULL, 0x3C6AA9273F7CE733ULL, 0x4C9B171B0A2F33FAULL
        },
        {
            0x93CD852BEE6E22A7ULL, 0x978675AD54F283BAULL, 0x6240924AA0503124ULL, 0xB3F5758AEA540A89ULL, 
            0x53847987C6F39651ULL, 0xE8B03754EC9CB22DULL, 0x27A9C94E0ED6DFDFULL, 0x3289D96D6D1085FDULL, 
            0x1879E68B4C8351FDULL, 0xE413EBC03B4B56BCULL, 0x842BA386010DD75DULL, 0xD66DABF90392B38FULL, 
            0x845393837A417D84ULL, 0x5C841EE7FEE2456AULL, 0x18A8716A72D82E6BULL, 0xF35D211FC96AABDBULL, 
            0x5BCCBC55E5396122ULL, 0xCC1A0FAC50A823DDULL, 0xD910EF39057A31B5ULL, 0x054842DAEFBC4F50ULL, 
            0xD445BFD0A67F9FC2ULL, 0xD98F8A14D386B83FULL, 0x1A613411885F2818ULL, 0xC5E7864172BDB241ULL, 
            0x09E0C95AD3C609DEULL, 0x405A5FD674ADF78EULL, 0xF9714D119B946AD0ULL, 0x68A2A7D056729F7DULL, 
            0x635D1812007A15D0ULL, 0x6EC585FCA1E5DB08ULL, 0xDBBBDE96F86DC72DULL, 0x5C49E7F3A68CB0FBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kTwistConstants = {
    0xAEC51CF8387F90B8ULL,
    0x601CC108D474A79BULL,
    0x193DB753E8D9502EULL,
    0xAEC51CF8387F90B8ULL,
    0x601CC108D474A79BULL,
    0x193DB753E8D9502EULL,
    0x38B66D7D03D2888BULL,
    0xFD2BD9613DE8914EULL,
    0xAD,
    0xF2,
    0x03,
    0xD5,
    0xAF,
    0x5F,
    0x9A,
    0xE2
};

