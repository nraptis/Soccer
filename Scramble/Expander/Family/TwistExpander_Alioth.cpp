#include "TwistExpander_Alioth.hpp"
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

TwistExpander_Alioth::TwistExpander_Alioth()
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

void TwistExpander_Alioth::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA7E3D33BEC5EAC6BULL; std::uint64_t aIngress = 0x97A7A483BB42B2CFULL; std::uint64_t aCarry = 0x96CDC44A30F4DE4EULL;

    std::uint64_t aWandererA = 0xD2D66203149A9875ULL; std::uint64_t aWandererB = 0xDF6C35EA99408487ULL; std::uint64_t aWandererC = 0xD14C7F97D498D657ULL; std::uint64_t aWandererD = 0xC3A0701D414FFAA5ULL;
    std::uint64_t aWandererE = 0xE4A1178EFFC5ADBFULL; std::uint64_t aWandererF = 0xAAD5169E984A18EFULL; std::uint64_t aWandererG = 0x9DE69EF8D8DB7509ULL; std::uint64_t aWandererH = 0xAF1383984A1F8ED2ULL;
    std::uint64_t aWandererI = 0xB9342D91829DDAADULL; std::uint64_t aWandererJ = 0xFF4B9EC8E3D3F0BAULL; std::uint64_t aWandererK = 0xC9A14F9CD7C356ECULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC6E782BD0A20EC43ULL;
        aCarry = 0xE3AEEED91F0D5F94ULL;
        aWandererA = 0xAD47272E419A866FULL;
        aWandererB = 0xAE2AE0DE63581B40ULL;
        aWandererC = 0xBFF445FF0291D8FAULL;
        aWandererD = 0xF1ADAD7665DF4E57ULL;
        aWandererE = 0x8D3D38240F7847A2ULL;
        aWandererF = 0x95D71E0670324F92ULL;
        aWandererG = 0xAC6795916F20A853ULL;
        aWandererH = 0xCB692E7608371BE8ULL;
        aWandererI = 0x894D98EBF5D1F10DULL;
        aWandererJ = 0xF14589FAC2BCC756ULL;
        aWandererK = 0xA6E148C7853AF297ULL;
    TwistExpander_Alioth_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8FDC66D213F53EB9ULL; std::uint64_t aIngress = 0x9D9B20B6581C2FF7ULL; std::uint64_t aCarry = 0xAB56586EAEF85B55ULL;

    std::uint64_t aWandererA = 0xAAC3488E5D1D06F7ULL; std::uint64_t aWandererB = 0x85393036EFCCCD53ULL; std::uint64_t aWandererC = 0xB3D11FF23C1841E0ULL; std::uint64_t aWandererD = 0xFCE238131CD082C0ULL;
    std::uint64_t aWandererE = 0xD6A33153EDCE2D6BULL; std::uint64_t aWandererF = 0x82E80551547DCF21ULL; std::uint64_t aWandererG = 0xE42645935970204DULL; std::uint64_t aWandererH = 0xFAA035623308E791ULL;
    std::uint64_t aWandererI = 0xE31000F7393AAC73ULL; std::uint64_t aWandererJ = 0x8C377623052876CDULL; std::uint64_t aWandererK = 0xFE062F4542A753B2ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8CD471A862F019D6ULL;
        aCarry = 0xEB75829A4E2CB18FULL;
        aWandererA = 0x963AEEBCE3298CADULL;
        aWandererB = 0xFA31D4554828E4EFULL;
        aWandererC = 0xBA04D0BB744F286CULL;
        aWandererD = 0xA834BE78806AFA95ULL;
        aWandererE = 0xC53A698E7631C64EULL;
        aWandererF = 0x9D7979CCC4C60E39ULL;
        aWandererG = 0x9A8FA6ED97F0B45BULL;
        aWandererH = 0xD59C6B299D5E4E47ULL;
        aWandererI = 0xDF6930F9BB430AEEULL;
        aWandererJ = 0x84A382D03A47EB6BULL;
        aWandererK = 0xF182CDA69495F7E6ULL;
    TwistExpander_Alioth_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE29AB359E834BE57ULL; std::uint64_t aIngress = 0xF3BD91E6594C00E6ULL; std::uint64_t aCarry = 0xE72BC2B0BE0D8B9EULL;

    std::uint64_t aWandererA = 0xB273511845887CDAULL; std::uint64_t aWandererB = 0x89F7D66686308224ULL; std::uint64_t aWandererC = 0xF195AC13CBCD9F35ULL; std::uint64_t aWandererD = 0xEAAD169EAB312033ULL;
    std::uint64_t aWandererE = 0xD86DD51EDA70F14FULL; std::uint64_t aWandererF = 0xE3CCF6763F59130EULL; std::uint64_t aWandererG = 0xCFD1243358F2FC3EULL; std::uint64_t aWandererH = 0xC818440020C020E2ULL;
    std::uint64_t aWandererI = 0x9ECD757B554EC0F1ULL; std::uint64_t aWandererJ = 0xF4C45E781FF7218FULL; std::uint64_t aWandererK = 0xF8476D98F5525A92ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x919CCA81DE49EF8BULL;
        aCarry = 0xF215CC840D2C86FDULL;
        aWandererA = 0x9D26C1EE095BAEBAULL;
        aWandererB = 0xA63C7FAEE800F5D0ULL;
        aWandererC = 0xA8F24E9FA1AA8922ULL;
        aWandererD = 0x893ABC3AC5DEF7EDULL;
        aWandererE = 0xF2D738A9C657AF00ULL;
        aWandererF = 0xC45C2853E1560941ULL;
        aWandererG = 0xDDD5557360288335ULL;
        aWandererH = 0xCD69F2B6BF83DADEULL;
        aWandererI = 0x818DA066C5318B48ULL;
        aWandererJ = 0x8D3132E0D493B2FAULL;
        aWandererK = 0xE2ACD848718CD75EULL;
    TwistExpander_Alioth_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8D685CE15D203A13ULL; std::uint64_t aIngress = 0x9391FA9664CF7403ULL; std::uint64_t aCarry = 0x85C09E53969EC4A7ULL;

    std::uint64_t aWandererA = 0xCBCEE87CC7F2B115ULL; std::uint64_t aWandererB = 0xDA29B472C70A7043ULL; std::uint64_t aWandererC = 0xA38731492F46F1EDULL; std::uint64_t aWandererD = 0x8EDFAC3D83236509ULL;
    std::uint64_t aWandererE = 0xDA9A0A287FC0588DULL; std::uint64_t aWandererF = 0xF252727555CCBAE0ULL; std::uint64_t aWandererG = 0xFBD359112F2E20F1ULL; std::uint64_t aWandererH = 0xE2910356BFB774DAULL;
    std::uint64_t aWandererI = 0x829B80A07E2448DFULL; std::uint64_t aWandererJ = 0xEC234480969C3093ULL; std::uint64_t aWandererK = 0xF6B3961D07F4ED25ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCD882FEEE5FBD211ULL;
        aCarry = 0xF54D7047BF58A6A7ULL;
        aWandererA = 0xCAFAB304F08D1053ULL;
        aWandererB = 0xADEB845FB4773202ULL;
        aWandererC = 0x9DF31973BC21A955ULL;
        aWandererD = 0xCB0821C2FA8A0A03ULL;
        aWandererE = 0xA2EB431736FFB061ULL;
        aWandererF = 0xA37159FA4E3021B2ULL;
        aWandererG = 0xD724920BD4D04589ULL;
        aWandererH = 0x89BEE8045C0E7BC3ULL;
        aWandererI = 0x92FB4F4C4FAAB3DDULL;
        aWandererJ = 0xDF9F1ED19193552CULL;
        aWandererK = 0xE82C246DFB363D4FULL;
    TwistExpander_Alioth_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alioth::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCA43D1F1270FDBC3ULL;
    std::uint64_t aIngress = 0xA317B59819A86B7FULL;
    std::uint64_t aCarry = 0xC30D8C640CC93683ULL;

    std::uint64_t aWandererA = 0xD8C7453843F99A06ULL;
    std::uint64_t aWandererB = 0xEA4C080B7BAEE5E6ULL;
    std::uint64_t aWandererC = 0xD7F5E2B862B3591CULL;
    std::uint64_t aWandererD = 0x85530D42AFAF445CULL;
    std::uint64_t aWandererE = 0xD80FAEC082B8D912ULL;
    std::uint64_t aWandererF = 0xB6BFA3093900C410ULL;
    std::uint64_t aWandererG = 0xFC09312AD8AF811CULL;
    std::uint64_t aWandererH = 0xEEE9140D27E24873ULL;
    std::uint64_t aWandererI = 0xB0DBF73C05E9114BULL;
    std::uint64_t aWandererJ = 0x9AF6F7AF4BDF5764ULL;
    std::uint64_t aWandererK = 0xD1A23F23606CA9D7ULL;

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
    TwistExpander_Alioth_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KEY(pWorkSpace,
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

void TwistExpander_Alioth::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD846E92611495E3EULL; std::uint64_t aIngress = 0xBC7729FF182F94C5ULL; std::uint64_t aCarry = 0xEBD6BEE78BED5E7DULL;

    std::uint64_t aWandererA = 0xE74BBA3A2E0B3EA8ULL; std::uint64_t aWandererB = 0xBB7470149083229CULL; std::uint64_t aWandererC = 0xAB448C1CAFFE9CD2ULL; std::uint64_t aWandererD = 0xC4DDA4830FB9D266ULL;
    std::uint64_t aWandererE = 0xDC5BF438845C598CULL; std::uint64_t aWandererF = 0xA9BC31C9393192D7ULL; std::uint64_t aWandererG = 0xD787E2D2464FCFC0ULL; std::uint64_t aWandererH = 0xCFCE77384BBE60FAULL;
    std::uint64_t aWandererI = 0xAB88EE15756AE481ULL; std::uint64_t aWandererJ = 0xE8AF6D1E035191D9ULL; std::uint64_t aWandererK = 0xD7DC64379D675C82ULL;

    // [twist]
        aPrevious = 0xED3C532BD8F2F21AULL;
        aCarry = 0xB4FF030495B8A40AULL;
        aWandererA = 0xB80ACE7B5882E44FULL;
        aWandererB = 0xD704EC2521E26FEEULL;
        aWandererC = 0xC05D33D4D7D81D09ULL;
        aWandererD = 0xB2079C59EA4B09A6ULL;
        aWandererE = 0xE5643ABFBE07EAEFULL;
        aWandererF = 0xED9381B4CD5AA0C1ULL;
        aWandererG = 0xAB14152D1F3B224CULL;
        aWandererH = 0xCCD5B9AF84F3A71BULL;
        aWandererI = 0xD0A416D208D1AD12ULL;
        aWandererJ = 0xC998A5502B109946ULL;
        aWandererK = 0xB95A2378D999282FULL;
    TwistExpander_Alioth_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Alioth::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Alioth::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Alioth::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 4 of 33
    // Exploration cases: 0
    // Structural maximin 572 / 674; family total 1723
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1915U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 4 of 33
    // Exploration cases: 0
    // Structural maximin 576 / 674; family total 1746
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 4 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1122 / 1248; total 3380
void TwistExpander_Alioth::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
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
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 4 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1125 / 1248; total 3403
void TwistExpander_Alioth::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
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
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 814U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alioth::kKeyRotateSalts = {
    {
        {
            0xC72807511016578EULL, 0xA447B40B7A927F79ULL, 0x6A6B832623438AFBULL, 0xAA09DC3CD8B32ACBULL, 
            0xF21CBFFEADBBC340ULL, 0xC3FE727B6814BFBFULL, 0xCE2C4A1BFAB5A7A5ULL, 0x6BB264EE6F48AE1BULL, 
            0x6FA3281F766F7C5CULL, 0x9854094C6F43F57BULL, 0x9C0EF17B7B81CD7DULL, 0x7D2BDE611A1D1301ULL, 
            0xF16A36363B3725CEULL, 0x4BC5E1EFADD77B35ULL, 0x291C1008711135F6ULL, 0xDEAFA219E967B9D6ULL, 
            0x6740CEB7D8B0840BULL, 0x58704433B23DCB3CULL, 0xF15EF3736D12A361ULL, 0xC2AC02B209944D33ULL, 
            0x23753F547BBB30FEULL, 0x017107B39DEDB230ULL, 0x1808C65A74FA9083ULL, 0x54B98BF1026DEEC0ULL, 
            0x9BDBF10D52555291ULL, 0xBD650BAEF29F37E8ULL, 0x9822CBE58F508247ULL, 0x78472BEC2269F74CULL, 
            0x0E794D88D7395CBEULL, 0xFCD8B7B0DA127236ULL, 0xC6307080D8281571ULL, 0x3BDC13B7D9C88C5FULL
        },
        {
            0xF886A9055984608DULL, 0x0D1ACEFFC3BF5178ULL, 0xE000BD0F468E5B67ULL, 0xDA2E5CF5EFC97CB0ULL, 
            0xEA0AB8D6CEC7C023ULL, 0x15D1188667C74AC8ULL, 0xD8505E1C8637A9FCULL, 0x90DA0EE785B6DE71ULL, 
            0x856B9B1C5313E191ULL, 0x7782ECA3EF3DD739ULL, 0x7185F03F4723E357ULL, 0x14A388FAB3CCBCF4ULL, 
            0x1A98B22CD026F684ULL, 0x4DD1E419100DD27CULL, 0x0ED99CB60BD277A0ULL, 0xB4A3CF662D3A69ADULL, 
            0xB06A8CD4F680BB10ULL, 0xFC345D58A0DAA425ULL, 0x118F03FC9059B8FAULL, 0x255F24732CC129E1ULL, 
            0x6A9C20BFDEAC96D8ULL, 0x4A91FB1F976BE9A5ULL, 0xC12300E8AE884782ULL, 0x0AD3358EF3132961ULL, 
            0x66CB1BD68C824DA3ULL, 0xF15704BF8B96F9A1ULL, 0x3C4B27A43B85929AULL, 0x3BEEDD24701B8642ULL, 
            0x644BA20DE18FF13DULL, 0x6510048847254681ULL, 0x9D682479831CA570ULL, 0x2857CB2E9ECDE663ULL
        },
        {
            0xFABE6A74FC65BFAFULL, 0xFA902BA3D980970AULL, 0xE8C1466B55DE3B58ULL, 0x3E6C223AD7C57C45ULL, 
            0x0C08F0147F890575ULL, 0x5D7DB48D968FD8E0ULL, 0x0242E75D0169403CULL, 0x0DEE71874FB3B2E0ULL, 
            0x6EFC1283FF82378EULL, 0x2BE4ABEAA2CCF57EULL, 0x78B7A195BD45A845ULL, 0xBAACD567EF09E92BULL, 
            0x9A7B14743446C688ULL, 0x14EAC090221FB1A4ULL, 0x8B3831CEAAEE0B6FULL, 0x4075498C92E60A9DULL, 
            0x5DF55C31CEC9CFCAULL, 0xAF539D29B626ED33ULL, 0x53131BC91A30E845ULL, 0xE693BB16E36AE968ULL, 
            0xCD1C45CCC874D6CCULL, 0x44432B95A830F7BDULL, 0xCD82B7676C1AC7BCULL, 0xC08ABE4D65A81611ULL, 
            0xC6C169A393FD0D72ULL, 0xFF3DA97B088DC3D2ULL, 0x618FC7397B22EEBCULL, 0x603E493DBD00B8F4ULL, 
            0x3A91D514A902C7A9ULL, 0x4CF03EF29E10B374ULL, 0xA6CC0A7EA01E0F74ULL, 0x6EEBA684AB87D12BULL
        },
        {
            0x2BEA70046E58F60CULL, 0x66148ACA00982245ULL, 0x7B40F09A34A74C42ULL, 0x24B3BFFD1325AF0BULL, 
            0x3625009B7CCBAF28ULL, 0xBA20481757B2EDEFULL, 0x82C0747A88342164ULL, 0x2280CAC5C1CB51CCULL, 
            0x301EB1190E9B099BULL, 0x233F74AE8D241D9FULL, 0x24DEF8C942958DFEULL, 0xEDCB1ED03C69D965ULL, 
            0xD3D7CE91749D2261ULL, 0xBBD23057FDE3B1A4ULL, 0x1839BCA984B3FAB4ULL, 0x4EBB1096530DD61AULL, 
            0x2DF3B92C64900DA4ULL, 0xA20DAE8580750AD6ULL, 0x3658E89E0F5ACB7AULL, 0x77C7F346B09DA874ULL, 
            0x28F21C22D70BD1E4ULL, 0x778692793FF20E30ULL, 0x9FD4E9B72AF5A559ULL, 0xF8291CF0501BE6BDULL, 
            0xE7C7F67C2917DEB3ULL, 0xE729C2101860255CULL, 0x7F0CA5BF2F2D1367ULL, 0xFA626F0A37A65D60ULL, 
            0x01033EBA0E34EC55ULL, 0x5267E1801FA4EB79ULL, 0x04543F8203776C78ULL, 0xD2BEA5E8B5A1A917ULL
        },
        {
            0x742B21CBEC11855EULL, 0x49C05B64FDF67DDFULL, 0x35C29CD4891EBC53ULL, 0x06B29CA6E6D892A3ULL, 
            0x9A46B8529312C6ABULL, 0x8090FBD8481183E7ULL, 0xF71592DF1D6B9E0DULL, 0xC8A946DECF16AE45ULL, 
            0x5A9309BB75E6D05FULL, 0xB3124C4017793771ULL, 0xBC1052F4511FD044ULL, 0x5515AC4DA3B04800ULL, 
            0x01A8CAE00FD8ACF9ULL, 0x61D32D1C0700B554ULL, 0x60C2C8C821277698ULL, 0x12D1BA79CE1DD238ULL, 
            0x65C512FFBB1BA805ULL, 0x8A8D448C27BA29E8ULL, 0x8BA78287B88F6AF3ULL, 0x943793FDC902C82EULL, 
            0xBA0F56436E200717ULL, 0xFC4DF309ACB13825ULL, 0x790AA5011FB247C6ULL, 0xA3650499C71430A1ULL, 
            0x5F0CA646B20DC4BCULL, 0x7FDAA63DC2C46C3AULL, 0xF97F41B86AAC5B9BULL, 0x2BC034F2850E8F15ULL, 
            0xAB1AE02C52FFA6F3ULL, 0x9014445A319FF38BULL, 0x9B96463FB5FA4831ULL, 0x6A932D52236DC9DFULL
        },
        {
            0x86DC5D7603C452EAULL, 0x4503E943AEC44285ULL, 0xCA1AE62997C45F27ULL, 0x2D4BD91EF1951AC7ULL, 
            0x23B10A647AF33779ULL, 0xCD61C592FC9249F8ULL, 0xCD3764DF39D90AE7ULL, 0x85E02A6B0961EC2FULL, 
            0x8140850C3D2EE6B3ULL, 0x6F96C61C08B905FFULL, 0xE18C06DF46B5298EULL, 0x6EFAB7583F1F8D86ULL, 
            0x1DA4941B857993BEULL, 0xCED0A7BE8990F9B4ULL, 0x26B568DFFA14947FULL, 0x2E3047A8C6DB14EEULL, 
            0xE44AF945E44812B7ULL, 0x61F40B7FD5217198ULL, 0x3392FECEF564E836ULL, 0x1218A8DEB48F2602ULL, 
            0xB7594AF1D4D5ECA3ULL, 0xACD92019848955E6ULL, 0x942B4FF092C6E700ULL, 0x8D1FAC1CB2E70407ULL, 
            0xEEC103C27A709673ULL, 0xCD603B5EDB1138E9ULL, 0xB87C89E5AD2D0F3BULL, 0x018C3198907E11D2ULL, 
            0x81A055CFBD462CF1ULL, 0x65CC5D55F977C324ULL, 0xB3F3D40E243559BBULL, 0x7FF4722A617E4C20ULL
        }
    },
    {
        {
            0x06EF15B324D6F2AAULL, 0x92B9EDD772EA417CULL, 0x122BD34017D89B39ULL, 0xB8CAFBC5956CF26CULL, 
            0x773DB073039091A2ULL, 0xE72426AF2CCBB0ACULL, 0x58F77324F1287281ULL, 0x10588D24187E57DEULL, 
            0x1CC517690001C666ULL, 0xA5A31D5A190E0E92ULL, 0x4F08EB3A159A4568ULL, 0x20B837B7506CAE4DULL, 
            0x0DEE0D6735DD9BE4ULL, 0x45FA825E28029DDEULL, 0x3E5F463B0687F64DULL, 0x663BF7EBABA97621ULL, 
            0x85FF3525D48782A0ULL, 0x84142F90403E7A2BULL, 0xEF4A0CDEA6E91E08ULL, 0xBBBB1D64421E2BDCULL, 
            0x4564009784F12A38ULL, 0x642C9CB5133EB025ULL, 0xCB0BD4ED256E11C2ULL, 0xE89F0E9935A6FF2EULL, 
            0xAF721E968757FBF8ULL, 0x925F212BF74D2B21ULL, 0x752754C069C980E0ULL, 0x7C0ED343A83F8DE5ULL, 
            0x3D1A41DEBC73A012ULL, 0x0B83E422D001A798ULL, 0x81D1DFE6437EDD3EULL, 0x487C75D9C0EA89B9ULL
        },
        {
            0x29FF521D53B536DDULL, 0xE7E610B0172F7EDDULL, 0xCB37C93A5AE442F7ULL, 0x8F9CA772BE44D177ULL, 
            0x7FB5BC1F3A3F0526ULL, 0x91EB93342E1DAB04ULL, 0x24F13AC44CDB4565ULL, 0x3BFB2513CB90AC19ULL, 
            0x9C2B10685DEDC546ULL, 0x8D6957288AE22DABULL, 0x0C8232A06771A45AULL, 0xF9CA7D30778E0D1DULL, 
            0x21E7657F502E2E42ULL, 0x88ADE7DB1ADB1301ULL, 0x24F5B8BF541867E6ULL, 0x06968DB8CB304BD9ULL, 
            0x70B2C85BA6ED299CULL, 0xB210A3C84DD49143ULL, 0x0E36B9BDBDE009FFULL, 0x8FAA03C52E53DB57ULL, 
            0x8107266F889BEC77ULL, 0x1597BB92B29E3236ULL, 0xDAD284CF3DB04599ULL, 0x2B7B6ECDB4BF2924ULL, 
            0x075131298BAA5355ULL, 0xE5C8000ECE840C4BULL, 0x18A551CAEE7852CCULL, 0x8F5EFA53E6CA103FULL, 
            0x9D7B40039CED3B7AULL, 0xFFCE409027066D1DULL, 0xAE1BE60248E8F3EEULL, 0x0DDD7499181B6196ULL
        },
        {
            0x2DF133FC8C164484ULL, 0x56389995D2B12209ULL, 0x391EBCC74CEE43FCULL, 0x75CC20EE83701934ULL, 
            0x8EE2FDE13DD81FB7ULL, 0x4B6AA0E8D434420FULL, 0xEF7089FA2BC4F2E0ULL, 0x8BB46BDB8B63F30BULL, 
            0x2BAECAB16B89AC31ULL, 0x2EA7E2D15669995CULL, 0xC4824514E40AD415ULL, 0x858C9841D3C78A64ULL, 
            0x70DCB1FE4A88364DULL, 0xF7E9F918193C1C18ULL, 0xFD967970177A8AB6ULL, 0x19BB597E20F0C135ULL, 
            0xCCC6DABCB26877F7ULL, 0xE048958EABE33856ULL, 0x38DE892B62859D45ULL, 0x7E23BE97BF5A8DE1ULL, 
            0xEF2269F2F8256E11ULL, 0x28D96699CD5D4B0DULL, 0x4E136E2A35B92433ULL, 0x2E99EF5433C257DBULL, 
            0x30F9AE7C6C7B714AULL, 0xDCCEA6DC13AF42E4ULL, 0xE0AA053048A5A722ULL, 0x28BF5D8274F3AF00ULL, 
            0xE8F6F161645CB93AULL, 0xBD19C87D99808B0AULL, 0x77F2989B774767FAULL, 0x7A548EB33F9D914FULL
        },
        {
            0x08F2B8B843D6331DULL, 0xD1D5CFE3B6BF1653ULL, 0x6E3842CC6C6A43CCULL, 0x2FFEE5F3742A1320ULL, 
            0x299F995E6FC67F6AULL, 0xD5D6A3B6444750C2ULL, 0xEB53837848B844FAULL, 0x20285EDDBA6A6C9AULL, 
            0x361D323DDBC56BAEULL, 0xEA2E6A6D14D4952AULL, 0xF7924F79CB270668ULL, 0x440005F5BB493F21ULL, 
            0x8A70CDE94052FDD6ULL, 0xD50B49DFFDCAD0ABULL, 0x2D3708738E85D15DULL, 0x6C3F39334D0E067DULL, 
            0xF2B69889086D473BULL, 0xEDAEDC67DC57D9E2ULL, 0xF0600612B55B4C4FULL, 0x1D9CAC10DE53A2B1ULL, 
            0x59F8502A7764FAC6ULL, 0xF4A1C406C704253BULL, 0xDC86D2C074975EEEULL, 0x7CB520442B4C793DULL, 
            0xDDE9241B0D044595ULL, 0x1E833035B3199C04ULL, 0x55FF2647BA1646DFULL, 0x9A35B9DFABEDE67BULL, 
            0x8DA471A75D552459ULL, 0x52318C9A0F555E14ULL, 0xC9233A4579BE3B23ULL, 0xEDD8432A112FD15EULL
        },
        {
            0xFBA4971B1F43B05FULL, 0x2BD207E46A6B02EDULL, 0x242625713A4B270EULL, 0x7F4281B82117716CULL, 
            0x5C26D70E4FD19F35ULL, 0xCBA2C2F564C39665ULL, 0xEB1D03C2128BBB4BULL, 0x005E4F056F332D2CULL, 
            0x7C99A02CEE1627D3ULL, 0x3865941FB16814A1ULL, 0xEA55AB5EB39B0B21ULL, 0x5F5499B37B0F761AULL, 
            0x64A154D9E23A57D6ULL, 0xB55424366DE0BB46ULL, 0x5F734665B00A68E7ULL, 0x1011ADDB3CBC84ECULL, 
            0x0E4C989F198E16E4ULL, 0xCBBFB9DF83F457ECULL, 0x41435521EB16B33CULL, 0x0406ADADA8F0E118ULL, 
            0xA60AA637C63CDE6DULL, 0x9019ABA17270F404ULL, 0xBB787CB76AF1DF6BULL, 0xD160F923B32D2374ULL, 
            0x75BF01C890C7AEB8ULL, 0xB561E269FB76DFEEULL, 0xFDA72045C9D35C44ULL, 0x090EA9AEF5775C5EULL, 
            0xB03FC0C9EDA36E30ULL, 0xE6650D967906C3CFULL, 0x4EA15F1323EA2DF2ULL, 0x2B9455B126141C81ULL
        },
        {
            0xD9F37140FDB754B2ULL, 0x0AF63BAF8490BC94ULL, 0x3510F5680679555EULL, 0xC2DAC70DD938C975ULL, 
            0x7A8FD78E66FD6600ULL, 0xC877D10EBFD5DFC9ULL, 0x68AE9A49B437B089ULL, 0x7DDAA7DF1EF188A2ULL, 
            0x46224E448FEA4C44ULL, 0xF32214A96C9E4EECULL, 0xD634BF2206DF2015ULL, 0x7E60D671B64C4E52ULL, 
            0x532749FFB95FDEDFULL, 0xC622B37B829EFCAFULL, 0x6C60686BB43F67ABULL, 0xB12BF45872AC0B3CULL, 
            0x84EC9AD069CA961EULL, 0x8D3D113120E99D6DULL, 0x97D7D73766E43256ULL, 0x7BE6994BDFB25415ULL, 
            0x3D8DD7C21F6B27F6ULL, 0xC2C87203E4F73977ULL, 0x37329207C3BF9A2EULL, 0x624027C66C7DF269ULL, 
            0x6CA72BCA6A2CAF62ULL, 0xB9F8C7762C85927DULL, 0x9FCFB960D0E36779ULL, 0x944CE43F1311AD31ULL, 
            0x5A68C2976FC1FFEDULL, 0x19C7055B2A9C0884ULL, 0xD767DE282E02C4FAULL, 0x8A456317C7D02EB9ULL
        }
    },
    {
        {
            0x594144EEF38E17F1ULL, 0x9749C8CD9C2068C3ULL, 0x8CEEACE3E10A7B49ULL, 0xD39AB1791FD14DB3ULL, 
            0xB1B1B27EBB32B70EULL, 0x7D823A07FDAA9F46ULL, 0x96CFE6FBCC6FA5D6ULL, 0x57EEF64D2A1F11C9ULL, 
            0x39AFA2CC72355116ULL, 0xEF9475FDAB719F18ULL, 0xACB045C64198A2BFULL, 0xFE53448E7BC36C26ULL, 
            0x40AF6D0874C0A55EULL, 0x2C2FBACFAC756513ULL, 0x3696C6ED0B883C0AULL, 0x8AFE4A225C8E5AD1ULL, 
            0x01B0C021564F714CULL, 0x38A8AF4304918036ULL, 0x4A98834E341D2D20ULL, 0x8C2731EC8E27A6ACULL, 
            0x9CA54E7A6B49AECFULL, 0xABDFF9BAE3989BC8ULL, 0xF13ED7CA135F131EULL, 0x38C2FF464D735261ULL, 
            0x38974F0AA5C0171BULL, 0xFA60CDFD00C42DCEULL, 0xE68C6B4E6AD5E28EULL, 0x8CEF33CD3BE47608ULL, 
            0x4A9F6EB66FB7D159ULL, 0xD9028078C8CB1ABDULL, 0xBD44964ADE54BA2DULL, 0xC7D608A0244F7EC1ULL
        },
        {
            0xCBC30EEFF65E9770ULL, 0x9030CCD4FBDEDA21ULL, 0xB9F1AE25C7901A4EULL, 0x032F1278ED883A4BULL, 
            0x64C13590CD730AC6ULL, 0x78AC349EBCA7A737ULL, 0x8C5E238EA7F1A37DULL, 0x59981B574D42D370ULL, 
            0x1D25BCFF2EA3CFF4ULL, 0xB0152A506FE7203BULL, 0xC349C01CF8A0DF77ULL, 0x52A6E81695C18909ULL, 
            0x4C0CB95132A0C27FULL, 0x0CBF7A516D1C55A3ULL, 0x12036B24561C2AFAULL, 0x08087208EEACECAFULL, 
            0x3133D393F184869FULL, 0x8F95E26456E1D023ULL, 0x2E8209028EB2592FULL, 0xB70707874178124BULL, 
            0xF67ADD416BB6EA1BULL, 0xA09A1181568A7E15ULL, 0xA22E345DD9809E99ULL, 0x9E7C32CD02676D78ULL, 
            0x6713B29CBD2CF905ULL, 0x86ED9FB216378CF0ULL, 0xFA7A9AE4456B221EULL, 0x30EC0E95D61D0AEEULL, 
            0xD70D204C53B03BCCULL, 0xC11BC545147F19CCULL, 0xF5D3CC043C6D7A93ULL, 0xE3CA8FC405810703ULL
        },
        {
            0x9CBD9C6734B39970ULL, 0x254D0947D0DD3EEAULL, 0x7B6804F1722D2BBBULL, 0x556BEBA48E05BFC2ULL, 
            0xD52F053872591EA4ULL, 0x6EEFA1E5833B94BEULL, 0xF7EBFB4A54154B38ULL, 0x642F5E6A81923AFDULL, 
            0xAC5D2B0D5A8BA1B4ULL, 0x5454EE6EBC43A864ULL, 0x10ADEF844248D394ULL, 0xC9FBA61D62AA6B11ULL, 
            0xCDB941C89BC5CDD7ULL, 0xC13596ABCA942A92ULL, 0xCFD0CDDDFE353733ULL, 0x75C09BE17C9BDA74ULL, 
            0xC678ABA7807BBBE6ULL, 0xD6BD630576DAFF94ULL, 0xE439EBA9892ECDE7ULL, 0x8DECE204B004D508ULL, 
            0xBDD046390F32D743ULL, 0x9604726E6F799AC8ULL, 0x5DE4886FA8352B13ULL, 0xD07B9EF7CA5FD0CCULL, 
            0x1EC95099BA3D910CULL, 0xBCF25607E0E0662FULL, 0x39AB782E8029CDE2ULL, 0x3C0C2464504C2CB4ULL, 
            0x7C6709477D5C653FULL, 0x655CF260F639E609ULL, 0x473292571F69BB9FULL, 0xC30701CE9C49714DULL
        },
        {
            0x352FAF0CAEB0DB07ULL, 0x796B67C0C683F1EEULL, 0x1AAFE123346BE005ULL, 0x1F1CA6A9937236EBULL, 
            0x44A38E4604F483C9ULL, 0xC43CB4C697850E6AULL, 0x97B24FF39371390AULL, 0x061B2D1CD2208F28ULL, 
            0x698AF615FE5A3128ULL, 0xE84483D19EDCAFB7ULL, 0xEAA475318606137BULL, 0xD695BD9248BEAEDAULL, 
            0x1C267459C8E7F9E9ULL, 0x7DCFA0A5A5B716F0ULL, 0x27A1152CD2EBB855ULL, 0xA07CFBE97E1E110BULL, 
            0x872C9BC1CA136E24ULL, 0x8D4EB4B007539BA8ULL, 0x20D5760098A3D181ULL, 0xAB3CE2479EC3EDD8ULL, 
            0x5079BBB6552002E0ULL, 0x74869023F72204AEULL, 0xF15746D718B16830ULL, 0x2C421641409302EAULL, 
            0x113851A00106753AULL, 0x8AACF72EEFA96C7DULL, 0x6E55D683800D6830ULL, 0x5F8B718BDDFA903BULL, 
            0xF42761EA69136603ULL, 0x5EABC125C4ACEAB8ULL, 0x2ED60303B18EA722ULL, 0xBB86875BDC293470ULL
        },
        {
            0xA43DC4DE39E8E1B2ULL, 0x354B7F6DF1650789ULL, 0x8C67B932E6413C94ULL, 0xFEE18A14D18072E6ULL, 
            0x06B49984A9341A70ULL, 0x9C33B1C98535833AULL, 0x3667C29A43E7990DULL, 0x6C2F76C752638FBEULL, 
            0xEA80041800AD6E48ULL, 0x942E774D0AC372A3ULL, 0x0B984D763527818EULL, 0x903F76FB77A6EA63ULL, 
            0x64AA76B1E9690627ULL, 0xB302070194579538ULL, 0x2A801D79EC7C89D1ULL, 0x9CA0DB1DFEB29F2BULL, 
            0xC5A0B1912AD62C73ULL, 0x37749A3EB1B9B8B7ULL, 0x3B916CB456A97275ULL, 0x10DF0A66CC7BE22AULL, 
            0x0522E4E0B44E0B2BULL, 0x6C7F7F6739959109ULL, 0xFECC5078216ECEE8ULL, 0x5C4BC8E260CDA0BFULL, 
            0xD97211840B293481ULL, 0x921E10BAEAC2DAFFULL, 0x448EC79E85E019C7ULL, 0x173AEC7C661A4B59ULL, 
            0x378254952FFBE9CCULL, 0x4C5993C790988684ULL, 0xC7202CA6833C2571ULL, 0xEEF2113EAEBF9007ULL
        },
        {
            0x61702873EAFFFB73ULL, 0xDA5726D93313CDCBULL, 0xEB0C6F987B4DDBD3ULL, 0x589AB8077628CBA8ULL, 
            0x427F0C0EDD90607FULL, 0xE6BC751CFCFF37B4ULL, 0xE5407E665B2FE990ULL, 0x272ED9C1D9A6C7A6ULL, 
            0xC5FA16E82D293332ULL, 0x2D00EAF5698B6B28ULL, 0x44A6AB9007737C1EULL, 0xA0A1F8FE786643C2ULL, 
            0x13CF4332357C4D14ULL, 0xAC57D6E3E5392726ULL, 0x264377A3BA230269ULL, 0xA4C5A50B77E54D73ULL, 
            0x0E27139D8E479547ULL, 0x4A90161C814257D8ULL, 0x92DB335465CC8413ULL, 0xA753ACCD5FB1C88AULL, 
            0x406FAE18EF345E19ULL, 0x3794FBB6571113C3ULL, 0x90DAE15364C9B31BULL, 0xB799885A128A6043ULL, 
            0x1C817F254C64DD72ULL, 0x8DF1028A30766C9DULL, 0x360D735127EC3F02ULL, 0x323AFE1ABB7C73B1ULL, 
            0x25C39EB34F6AD258ULL, 0x7CDD81F3D03F2146ULL, 0x17BE813A07D9CBACULL, 0x3B86922741168AABULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeyRotateConstants = {
    0xB547272FC9C7A38CULL,
    0x6BE6BBE5E1AEF44FULL,
    0xAB430B1B3B488C8CULL,
    0xB547272FC9C7A38CULL,
    0x6BE6BBE5E1AEF44FULL,
    0xAB430B1B3B488C8CULL,
    0x74EB2234A50D7D10ULL,
    0xA87433572EB73D6DULL,
    0x5F,
    0x1B,
    0xAB,
    0x66,
    0x26,
    0xBD,
    0xB2,
    0x82
};

const TwistDomainSaltSet TwistExpander_Alioth::kKeySpawnSalts = {
    {
        {
            0xFDE7FFE8FC062E41ULL, 0x31B3CBFB0989ECEFULL, 0x0A43FB8D46CBDE89ULL, 0x35C55641D8CAB2CBULL, 
            0xF3F292398610F771ULL, 0xDA0D00E8C5A0915AULL, 0xD009C2568BC93168ULL, 0xA229FE2D484D44BAULL, 
            0xF0EF40D82F620831ULL, 0x22DC6C513BEB7DA3ULL, 0x182E8A6174DE3E59ULL, 0xE84DFEDB3DA71D31ULL, 
            0x12BB02301E5A0A14ULL, 0xCD8D0623BD2A8C4AULL, 0x4CA91AD848F0B0EFULL, 0x70555E45FE8E0DF9ULL, 
            0xDD2BCF4B9C5323A2ULL, 0x6F548BACE90B31C7ULL, 0xD61190F1E9FDAD44ULL, 0x7F35186CAFF76A5DULL, 
            0xC20E689B8BC5E033ULL, 0x1F0DAEFC01E39C8CULL, 0xF2249BC97BE96B64ULL, 0xA0A6866BA2E7DF47ULL, 
            0xB1640879905EC6DCULL, 0x1FD69A8A646FF057ULL, 0x949A571736F3AEC3ULL, 0x2ED7ADB78A5F747CULL, 
            0xF503C80CF5821505ULL, 0x16B7CF98F9CBB87FULL, 0x764443F1E8634437ULL, 0xD0D68A2521A4C1DAULL
        },
        {
            0xE048A705FB234154ULL, 0x7B8CEF121C1901BEULL, 0xFC6BDAA579AA9BB5ULL, 0x1BF90C5A74AD5AC8ULL, 
            0xFD97318FC7FD3887ULL, 0xE565324A4199BBD5ULL, 0x8791BA82D9E7C611ULL, 0x36199B73EBAEDDA1ULL, 
            0xA947F95477CBC4C9ULL, 0xAF42FEC7CB56D711ULL, 0x886A4CC904FC3B60ULL, 0x9A4A2D8F7F725EA8ULL, 
            0x76CC9FEDBA0407BBULL, 0xF4E71F1506F05E38ULL, 0x218314D2F6546E68ULL, 0x2809C9E44E7058BEULL, 
            0xDE271BEEF061671CULL, 0x54303FA37AD51062ULL, 0x6CECB27C141CE66DULL, 0xE5B20038E8FBBA35ULL, 
            0x08B9D1A6A5EBEAA5ULL, 0x5032DFB40CAE64C8ULL, 0x8F5F16A6DD78754BULL, 0x020973BF6BBB4032ULL, 
            0xDC2D5BD245042C41ULL, 0x77C40E459A24F401ULL, 0x9B797494D4CF334EULL, 0x5ED84F76D1FB448BULL, 
            0xEF71BE9F9FD76292ULL, 0x2795A46D4D5C5D5AULL, 0xDF2A5F4E9BE54245ULL, 0x11860CACE9E92374ULL
        },
        {
            0x4BF81F390A7C5051ULL, 0xF67C340803E605FAULL, 0xA8C49E07645C4652ULL, 0xE7DB33F4296A8735ULL, 
            0x2983C04DAA2A6641ULL, 0x2C4E2CAD995CA049ULL, 0xED2C008C9CF7D140ULL, 0xE44D0F6B356EB029ULL, 
            0x360AF499BA9B9ABAULL, 0xFB6D68394EED061FULL, 0x297422478BF7D2E6ULL, 0xB2DE52AB583DA0F5ULL, 
            0xFDE42B2EE70E666AULL, 0x2C74CB4EFC48D304ULL, 0x206B4FA5F3CF3279ULL, 0x4DC2DF10CDDA410CULL, 
            0x1854DDD63B933699ULL, 0x2A1E843CBC17047CULL, 0xCCA4ACF08FBC3606ULL, 0xC3A78939056746D6ULL, 
            0xB6242D3A11BBED13ULL, 0x9CB918B570AE462BULL, 0xCE650A1B5B8EC93DULL, 0x27678E598AD840C1ULL, 
            0x852BD79576D2F33AULL, 0xD2E0804139FB06D2ULL, 0x81D666834AFB8E3EULL, 0xD4FC8BC91BB612C5ULL, 
            0x22D15261FC447FD6ULL, 0x6B91FA98D42293EEULL, 0x70376C77B2DE56FBULL, 0x6138AB81DD135247ULL
        },
        {
            0x3D6010F3C235657EULL, 0x0C934E3D61CF392DULL, 0x27141F20240EA00FULL, 0xE7792AD446C077F2ULL, 
            0xF9C9EFC866783716ULL, 0xAAFAD134216D1521ULL, 0xC4DF05EB05D8C904ULL, 0x90B185A01FDCEAAAULL, 
            0xA8B6FE58DC3932F4ULL, 0xA3A73B17F30C8039ULL, 0xD3CF5FB3BC54968CULL, 0xF01E61E0F0BA0B27ULL, 
            0x3B771A16FBA53B32ULL, 0xD1FCEB0E88A9BDB7ULL, 0x0F520AF5F4B9898EULL, 0x493A2342640F69FCULL, 
            0x775CD1FD66D2371CULL, 0x8895965D639102DDULL, 0x310D608626E2454DULL, 0x775E7F8F5C2A024FULL, 
            0x44D54CAD9E4CC72AULL, 0x58EBBF7F5E0DE935ULL, 0x738ECED0FE982612ULL, 0xF259076F35175485ULL, 
            0xC68B05AC36868E9DULL, 0xA529170EA7918144ULL, 0x15D1E558C5DC4BB8ULL, 0x8DFD5EA2E43E5131ULL, 
            0xB45941F915E6CE03ULL, 0x8DD2BB7BB8E39664ULL, 0xA3653A8F9FDF7E49ULL, 0x569ADF8E3F422874ULL
        },
        {
            0x0A30A1545EB993D4ULL, 0xFB417828D01B57EDULL, 0x5DB211B8D1756E6BULL, 0xBAED28EF3EA23009ULL, 
            0xD1BC7BF00EFEE8E5ULL, 0x4357AC02CA3F765FULL, 0x78B47076247C16DEULL, 0x734B21A3ED6D63D9ULL, 
            0xEAA6928E8878778FULL, 0xD7A8F4F445B0102EULL, 0x9BE6B8C8343326BBULL, 0x7A6C1D58373A0DD2ULL, 
            0x94F10C8B73FF7424ULL, 0xD6BF6B9D41C94886ULL, 0xE54A0FC488A3F3FDULL, 0x0AF0D4B539075917ULL, 
            0xD6E93CE4BDF576DBULL, 0x4D2BBC8767F5C4A2ULL, 0xBF73FEB62BDEC76DULL, 0x54B81DC164D1E0CFULL, 
            0x2A34560199DBDFABULL, 0x0A79CFA3BE6578C8ULL, 0xCB6E7E45E2D07FB0ULL, 0x90C8DCF6B212C167ULL, 
            0x6E004C16E069EC90ULL, 0x35E8F60D8BF7475BULL, 0x25A59DC204F99E85ULL, 0xDA88C8701B0F7BE4ULL, 
            0x796E02B3C10ACD06ULL, 0xB61309EEF87EACE5ULL, 0x250D10F1E280E08DULL, 0x72CC869708BDF9AFULL
        },
        {
            0xD675CFB8EB0B4190ULL, 0xB81789FD68966EE8ULL, 0xAB6218B903A6F948ULL, 0x0AABD813E5D7A14BULL, 
            0xF1AA45691167EFF5ULL, 0xFC72F3142FAB261CULL, 0x3CC49D067667DB16ULL, 0x956610FFEC68F0CBULL, 
            0x8999FC8FE748FA87ULL, 0x8F854E0AAD25B0B2ULL, 0x352424A727B09607ULL, 0x22616510320AB33FULL, 
            0x715FCC9C14207F15ULL, 0x13A0C5E5C9BA7436ULL, 0x6FFBD1C43F0B56B8ULL, 0x5BA2D48B9C64244CULL, 
            0x6D953B8F8D7333D9ULL, 0x3671F24EFAB444DEULL, 0xBA27548C4C9ACD5DULL, 0x0C6928F18321AD56ULL, 
            0x039A5EFF85E94936ULL, 0xD9CEBC928800F32AULL, 0x2E9CA00B8F77C9A5ULL, 0x3C20C9CB24D3D118ULL, 
            0x0E2946F8DB68ED33ULL, 0x009CB79E6DFBAD74ULL, 0x8C1E8C42E964C94FULL, 0x8F2C610698F976DFULL, 
            0x11AF3E85DD9A2AE4ULL, 0x7DDE1A7F53EA263CULL, 0x146DDB768177D53AULL, 0xC66C92F11B5D3F85ULL
        }
    },
    {
        {
            0x58FD21E9A2B72651ULL, 0xAFC8048C215A64DAULL, 0x48E2557B35CD2DA7ULL, 0x07F79F1C30555EBDULL, 
            0x46E16062F55DDA62ULL, 0xDE334C80969CF35BULL, 0x69D28FECC690B2E6ULL, 0x52EF49F623DB80E8ULL, 
            0x61E2E7DCEDDAABDEULL, 0x4E9A3F9763F09917ULL, 0xB3A1A83363A66355ULL, 0x3C2AC51B7EF39E34ULL, 
            0x94066A9D0F830295ULL, 0xA4ADA84E8DD5A7CFULL, 0x665EC01E75B0D20AULL, 0x1BD86DC4A88A2032ULL, 
            0xE9C06FB0DDB48B39ULL, 0x0F9900BE35A83EACULL, 0xC16D8A41217C2CCFULL, 0xA5615EF34A880C46ULL, 
            0x88B42A0D0771BC76ULL, 0x91C4AB3A300D3E9CULL, 0x109D3EC0A84E7EAEULL, 0xB1918B36CC54F498ULL, 
            0x863E2C1C9F60FA15ULL, 0x91FD0C2933A18C9CULL, 0x3180B02592E3A4D9ULL, 0x8A3CEC87966467ECULL, 
            0xB984725A0DF21AB9ULL, 0xD85AFC0996EE71E3ULL, 0x4CAB4AD5C4B00E96ULL, 0x7392C96666339D2BULL
        },
        {
            0xD6B20349395584A5ULL, 0xAE7AE7DEFA5255C5ULL, 0xC1EDCCA0FF9E3916ULL, 0x609D39E40167B678ULL, 
            0xE0C01F1071CF9748ULL, 0x9E28B59AB28937E5ULL, 0x0E3555DA9E7C0B6CULL, 0x7471A548AEE3231EULL, 
            0xA149F071EF0C610AULL, 0x2E8077694801ED45ULL, 0xD7BBACC578103C61ULL, 0xDEABC5E3C0163BE2ULL, 
            0xA39D6B47735C0FCDULL, 0x6A214EBB1F044A5BULL, 0x782E144CF0FFB3B3ULL, 0xF1E09252EFD9B4CBULL, 
            0x8891A7FEC7A2E6D1ULL, 0x2D21C04570563458ULL, 0x9A029C0E18604F46ULL, 0x84AD5AB3188CE20AULL, 
            0xE2021753D008E973ULL, 0x659E094DCC6803FFULL, 0xAA1AD1E30611411AULL, 0x9B795B8DBB8953C4ULL, 
            0x177FACED8F269B72ULL, 0x08765828E1FA0F14ULL, 0xFAF09FC2F14EDA6FULL, 0x8B430ADC483005EEULL, 
            0x8B74C94B8F6E457CULL, 0xC3D390E7BC33774CULL, 0xC5A9C0A41807F155ULL, 0x7787CC090D7064B6ULL
        },
        {
            0x2F1933E80F52FAABULL, 0xD6A27BB6292E24A7ULL, 0xBA9D07D4A43DED3BULL, 0xFEC6C3EFC4FC6450ULL, 
            0x52C2007C75AA2E45ULL, 0xCBDCE828FF4E052DULL, 0x5C15312AFC2A6AE6ULL, 0xCDB3B4BEBA301A18ULL, 
            0x76CCFA2D1F850112ULL, 0x8631D131FC138B15ULL, 0x6EB353F6D65D6C93ULL, 0x29213088175E2F3DULL, 
            0x7350B7E08B3D729FULL, 0x83BE44169F82D254ULL, 0x83369D9E5DF9F9C0ULL, 0xBFAB6AF73C944D9AULL, 
            0xD6BA4B5FFEEC798FULL, 0x98E2EFC3C5A8A368ULL, 0x4AA45F59A5053D58ULL, 0x2A87B6DD17404E49ULL, 
            0x95ABBC766A20DDCAULL, 0x9E1DD3B6B431E217ULL, 0x915F26D3E8A3275FULL, 0x099162D192327EF3ULL, 
            0x61055A1D1CF481D3ULL, 0x8262364DCB8DA83BULL, 0x6D33E417812D8DC8ULL, 0x72C60F2671FA13BEULL, 
            0x05ED4C70E796318FULL, 0x1F99A4969D206AEEULL, 0xE3AA5DAB4FED5282ULL, 0x59B1944A8DA78FF3ULL
        },
        {
            0x4C25EEAD28E408CCULL, 0x1512E839A0795150ULL, 0x20E64F0B8ED9060EULL, 0xAFB64E5F81C3B4E5ULL, 
            0x6D17630FF5BC65C1ULL, 0xB2C2E56C6EA79117ULL, 0x47278B6698DF3F3AULL, 0xDE71E6A1FCB999B0ULL, 
            0xF363B1F558D921ECULL, 0x5A405F0CC8A1C15FULL, 0x800484D9D6D6FE25ULL, 0x35C871206B4735A6ULL, 
            0x4EDACDD0BDA5EAF3ULL, 0xCC0F116F0665D34FULL, 0x065F2975AE6FA000ULL, 0xAC1AB83603C09B6BULL, 
            0x0C49C7DA1157440DULL, 0x31DC36E3A52FEB08ULL, 0xB46B3837F32FAA05ULL, 0x237638090794E8A8ULL, 
            0xEC60A9F7CBD449EEULL, 0x24846B236145B294ULL, 0x58EE197295150BD0ULL, 0x12715038BEF96440ULL, 
            0xF474C6538B4AD7D7ULL, 0x0D07AC7151E3F98FULL, 0xB1D922AEC82260B4ULL, 0xE892C129B1131C8FULL, 
            0x893B7A94495092CBULL, 0xB32A54B29896272CULL, 0x4C97B8E95400774FULL, 0x9166B64060D8F719ULL
        },
        {
            0x5D5FEF14F8E43DA5ULL, 0x24972AB9FCB0F6DDULL, 0xE56D041F635C07DDULL, 0xBBCABDDCAE89A7C8ULL, 
            0x13E048A1F107C6FFULL, 0xB7A7D7350D7D6EAEULL, 0x113D77E251AA4AD6ULL, 0x0AAB8458E9432E17ULL, 
            0xD21AF2405FA4FAC8ULL, 0x9895E321B72027CBULL, 0xF014869F1810EA20ULL, 0xB5D182B0B4FF958BULL, 
            0x0CFFA3BEADA2455FULL, 0x35AFCEA000298EF8ULL, 0xF7B9C7A8A6EA910AULL, 0x3A59152BCF4804CBULL, 
            0x13580DF85E579BB6ULL, 0x8BC8B063897F88D3ULL, 0x8E5879512A644D07ULL, 0x67E5584A6DED4CDBULL, 
            0xAB38AD2AD631E7DEULL, 0x6A9CE781C308B6FCULL, 0x0065D6C4730D98DAULL, 0x383610431CBB1437ULL, 
            0xFF6A87167905B73FULL, 0xD80C6FEC466959E5ULL, 0x2B65B2B89EBB760CULL, 0x8255C3B421931B4EULL, 
            0xCBF59A655E67DDD1ULL, 0x620D58353A4B8355ULL, 0x0A47474ECF421EDFULL, 0x97DC34A412489387ULL
        },
        {
            0xBF50C99ABB13D99EULL, 0xBA5980DF767208A1ULL, 0x93087B9ED77F515EULL, 0x89B87B5C717E4716ULL, 
            0xDE854AFDE2E04CCEULL, 0x572CF33D33BC1BCDULL, 0x0EC9D7B631E7C9FDULL, 0x612F68C51606DA93ULL, 
            0x77EF9844CD379751ULL, 0x543F90AD540B20C3ULL, 0xF1CA3CB709BBF82FULL, 0x14B4EA91836770BDULL, 
            0xAC672362CED231B0ULL, 0xE4194BFC6282D156ULL, 0x587B16C0FCF0FBA1ULL, 0xBA59FDC012BD2ED6ULL, 
            0x817F1A3F41A42BD9ULL, 0x802BA5B16F32E4D9ULL, 0x07E5D89FECEE700FULL, 0xF087BC76700BD1CFULL, 
            0xB71BF4708FF97DEEULL, 0x76E1946A31E42280ULL, 0x0B078F41102EB2A0ULL, 0x92C0BEFA33D07DD3ULL, 
            0xA1237D135BD06FC0ULL, 0x9B76BFD52FCBE9EDULL, 0x562338641D5B5748ULL, 0x4880BA551715F8CEULL, 
            0x4AA11CB50353D355ULL, 0x9E1745B76ABFB0E6ULL, 0xA79DAE34B79BD6AEULL, 0xDF8AEBA3006F973EULL
        }
    },
    {
        {
            0xF0FF24393209AAB0ULL, 0xB31C1D1A48C8304DULL, 0x85D2C6BE52256B14ULL, 0xEC61A9E790E7936FULL, 
            0xDCC32C875B235A16ULL, 0xD1EF69FDA6831B60ULL, 0x0444739B825B1D8DULL, 0xABA75BBCFE75EF46ULL, 
            0xDA774348A16EBD2EULL, 0x3E8EFFDFB44AA377ULL, 0x0A8731166F534407ULL, 0x7B061B41886106FBULL, 
            0xFDB8F5647B2F11CEULL, 0x04D2BDCC4A9A728FULL, 0x9A6D8C574D08BEC1ULL, 0xADABFF1118DB191DULL, 
            0xE6B5BF04150F75F6ULL, 0x14D00E2D0F14A4ADULL, 0x5241CFF323BC54CEULL, 0xE2CCCA58933E5E95ULL, 
            0x6643D101C9279FD2ULL, 0xC346CF7E43369C20ULL, 0xDC4644E23ABD7A54ULL, 0xFB50C6C1D75B5DB7ULL, 
            0x693241D8DE9F1C44ULL, 0x02D5AA78EE6C59A8ULL, 0x5BE20E48D28C9BD4ULL, 0x1E93310DD792AEECULL, 
            0x4F1501CA0356E800ULL, 0xD3943B648EAAFAACULL, 0xCF234E098D6A084DULL, 0xDBA5A7AD0DFE64EAULL
        },
        {
            0x4A29B2FA396C69AFULL, 0x04D9EC03DB44AFD9ULL, 0x6A577B10A1C15DEBULL, 0xAD540AB6E216C650ULL, 
            0xD32CCDD9D583F1E2ULL, 0x49FD1007184A83FEULL, 0xF25345A87B92FDD4ULL, 0x2C6974DAC18D391BULL, 
            0x0B75FE2F2850661BULL, 0x3D2547FD174BFB71ULL, 0xA676F9BAFB2A896BULL, 0x6FD42339E7D18C61ULL, 
            0xBF717320A7B013FDULL, 0x2D3ECC28A72AA22EULL, 0xD6B2E96A0043ABECULL, 0x5A4697CA608FEEC5ULL, 
            0x791C9B324F521931ULL, 0x93577986073E10F9ULL, 0x6C6D9AA86FB765ACULL, 0x638130E5711D9F45ULL, 
            0x12E85A4438585FBBULL, 0x2D69446C8FD7C14CULL, 0x06A2A7A39B21F508ULL, 0xEBCC33EDF67EF5EAULL, 
            0x859516D17F6F36F7ULL, 0xC6DC3AC8D9352827ULL, 0xD928B959D04E1318ULL, 0xEF80056E089419C4ULL, 
            0x4F77E6EF96A3C98FULL, 0x70895C73CD44587FULL, 0xCDD8E13C1DDC2EA7ULL, 0x702D4BE02672A490ULL
        },
        {
            0x3FE8A66C293069E7ULL, 0xE442D8006C81F2EEULL, 0x58E9F62300C94B62ULL, 0xA9749A08D8FA1268ULL, 
            0xDABF588731FCC870ULL, 0xBA337A11B6900514ULL, 0xB159538AC7A4A77EULL, 0x98713F4DE4E75990ULL, 
            0xAA9B3A84D6048157ULL, 0x06885ABE0B41A516ULL, 0x12D1C841FFFEC2D3ULL, 0xF9AB54383B77E92FULL, 
            0xF9932C31B07E5144ULL, 0xC8544BA34BBA1B43ULL, 0xC1F9EA7F1677B50FULL, 0xE16BAACA016D89B9ULL, 
            0x52F393DF10268BD6ULL, 0x735EA1C3220F5B44ULL, 0x0FBCC2B83CB20D86ULL, 0x62483ABAAF299364ULL, 
            0x6EC62A5F45BB64C9ULL, 0xD464B25A4F220E9DULL, 0x13AA11923E979BA1ULL, 0xA79F6446913D52D8ULL, 
            0x918BF97754B2EC60ULL, 0xBB03F7316A531513ULL, 0x9733D07F7F00E4CFULL, 0xF2D609BC2F766A84ULL, 
            0x641890B0E70723B6ULL, 0x28FE48DA96091C56ULL, 0x7F18CFF5E4987A79ULL, 0xF519D1D692815ABEULL
        },
        {
            0x8031F1DA8CD44472ULL, 0xD90F714E615C6285ULL, 0xA4A3E9482EA7D4BBULL, 0x4D1546A09AA300B0ULL, 
            0x69159E7A2E729583ULL, 0xBE9ACFD99B54F9D9ULL, 0xF7C895B06716AC96ULL, 0x27DFC91D7F0A0C74ULL, 
            0xBDB275AC30515F88ULL, 0x2B8574A26AE5DADDULL, 0x1797077787FF1F21ULL, 0x323FB147C20A7D66ULL, 
            0xB2628E9EC8F595D7ULL, 0xFC0D1863366E8456ULL, 0x542302DD60260CF0ULL, 0x876D50AD039CF1BBULL, 
            0xD7610BD605423D18ULL, 0x800862335C1DC1F0ULL, 0x07BEABAD4FA24C2EULL, 0x5D0B8FE9ED1863B7ULL, 
            0x99D7D0152356F344ULL, 0xA088BB2DD285FA7CULL, 0x350A8F5A040714ADULL, 0xD42E1B300C7850BDULL, 
            0x27E33FEB392C10E6ULL, 0x1AE15104C24371DBULL, 0x97C3B5709167894DULL, 0xCD19F5760532D47BULL, 
            0x930DA42CAE67D3B1ULL, 0x11BAB1222BA788BCULL, 0xB49D1E0C4CAE4A3BULL, 0x301D360715B78D89ULL
        },
        {
            0xE853F496DCE2CAA2ULL, 0x9F933FED938D6858ULL, 0x7C9FDC4E6E07CDD2ULL, 0x04D0719DC3F34EEFULL, 
            0x6D4594119158A109ULL, 0x71E5527E15644BAAULL, 0x054B4F777687E7EAULL, 0x8C3C49FB2E95E8F6ULL, 
            0x34B04D6A2EBDCF4BULL, 0x5942583A11189F5AULL, 0x46B605544C2DC03BULL, 0xF77634CCF024CFD3ULL, 
            0xE5BA7EF4E8CB5D58ULL, 0x3820523A12B9E3DEULL, 0x7CB7FF0E01A431D0ULL, 0x066F7F10302F6ADAULL, 
            0x392C8BD42A306258ULL, 0x78A2CB3B092E38D8ULL, 0x6CFE49879C33E614ULL, 0x82B1C8B27E2F2DDFULL, 
            0x0294E899213E434AULL, 0xCCF0D6B0D48FCCBEULL, 0x76D2852593576E26ULL, 0x8023558ED18D335AULL, 
            0xCB05417626793163ULL, 0x5AF9E59F3B8E718FULL, 0x3ED8A4F303B667C9ULL, 0x01CBA70A86A6220BULL, 
            0xBBEBDF3714A2C6AAULL, 0x21ACB6EB1D4ACFA6ULL, 0x002115596EE61B15ULL, 0x2122E3D09091DD09ULL
        },
        {
            0x378719CE5ED71E16ULL, 0xA837ADE7D0780756ULL, 0x830A5FD282412C9EULL, 0x160844C2B4BDB33CULL, 
            0x66F02D7DEA75411EULL, 0xD5BD59FADC3307C3ULL, 0xAA0773DDA38B5437ULL, 0x1CA6185F47A76E55ULL, 
            0xAC7D38849A942986ULL, 0x32436FB396FE8139ULL, 0x8458FE5439E2F457ULL, 0xB9D231C3B41F8412ULL, 
            0x875B22B790C80AF2ULL, 0x6D5ADB95989FFC97ULL, 0xC781FD8B1C821715ULL, 0x5A02B3248511AE53ULL, 
            0xF903AD7CF16A4DBBULL, 0x376BFC7A5052CC9EULL, 0x9FA0E79735AFDE85ULL, 0x33D6D06B67EF7B65ULL, 
            0x37B6A52D8BDD4C71ULL, 0x313BB9F7F3F042FAULL, 0x582A5952078E1420ULL, 0xD176F51E0A91EB7AULL, 
            0x443AEEF3A7457E1CULL, 0xF67DE31C3A69E5F0ULL, 0xF6DA0452E941EB1FULL, 0xC92130E3294E150AULL, 
            0x4A65EAB188A4E27BULL, 0x2C1B60EBA5027592ULL, 0x8E32F1A2B1C7CFA0ULL, 0x3C3CC46D3E3AAD4BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeySpawnConstants = {
    0x10477646A461AEEEULL,
    0xCC4EB9169A8E1954ULL,
    0x95A494FF2FBFC1FBULL,
    0x10477646A461AEEEULL,
    0xCC4EB9169A8E1954ULL,
    0x95A494FF2FBFC1FBULL,
    0xD0D6CD0DD1230C88ULL,
    0xE9A8045473DD99DEULL,
    0x41,
    0x55,
    0xBE,
    0x4E,
    0xB1,
    0x06,
    0xE2,
    0x7A
};

const TwistDomainSaltSet TwistExpander_Alioth::kSeedSalts = {
    {
        {
            0x10D744E95F905719ULL, 0x56495E37C980C6E0ULL, 0xF2303DBE62D4957EULL, 0x7315CFC2B290D063ULL, 
            0x4C0737D746A74105ULL, 0x073FB1D79B20BCF9ULL, 0x44A265D4BD83DDD9ULL, 0x82BD69BBE46AFEEAULL, 
            0x644C5B4CB049E7B8ULL, 0x52824275D3DB0F46ULL, 0x7C883C4FB0B409FBULL, 0xAAE827B9E0614A8CULL, 
            0x414C57F0303C4660ULL, 0xD28379C49D69E724ULL, 0x4EE63A2AEDC0F62DULL, 0x71AE4B16FDFC8E21ULL, 
            0xD0E8D879D3165E12ULL, 0xA0A22617DBB3B65CULL, 0x4876464CDE85D572ULL, 0x7BED12586E598564ULL, 
            0x85301734747074EAULL, 0x82700C5B8D965BA4ULL, 0x110EBA58DDAB00EEULL, 0x365F7B3D5AEC3147ULL, 
            0xC67F88B8A22F9C73ULL, 0x3B47533C8CCE9090ULL, 0x5CB0DB10C2465C47ULL, 0xDBB5E62C126C8A7DULL, 
            0x4E6F838263997C3AULL, 0xDC1FE78E10E05022ULL, 0x3465F1EDFDB75752ULL, 0x8818BBAB9B58E4DDULL
        },
        {
            0xB9D32C50E4163D5BULL, 0xC94BEABB92356DD8ULL, 0xBE924E21863711A8ULL, 0x50229C51F9624363ULL, 
            0x2904362A08436565ULL, 0x1485DC747BAF68CFULL, 0x855970BEFEDC8E64ULL, 0x4B8C1FCB1F8EFBADULL, 
            0x8420F876E99A95C6ULL, 0x97704B4A6DBEF6D7ULL, 0xB58300FE6B56311AULL, 0xC0BA329314D1D9F2ULL, 
            0x9AA19D10983C1012ULL, 0xFE6CD7E3D2A098C0ULL, 0xF84F26B38CABB0E5ULL, 0xA5FF7499DF37A566ULL, 
            0x4B7DC80DA217FBF8ULL, 0xEC2B6A8D6EE571FEULL, 0xEDF4F9DECA08BC81ULL, 0x6B23A8EA0D684B00ULL, 
            0x26373622833ECD2DULL, 0xFBDB092F4B1DC68DULL, 0xCBD6B3BB53A64CD7ULL, 0x48AFF4DC1DF15DEFULL, 
            0xCD3EB9FDF3548726ULL, 0x993FE3A524EB3525ULL, 0x6F65B7EE933F333CULL, 0x34B18EAA4A6B9426ULL, 
            0xA0A3945581199328ULL, 0xB870555E03F2C750ULL, 0xCCC7669F9D11642FULL, 0xAB3ABD1F8B894AF7ULL
        },
        {
            0x4DB9DB8607474E18ULL, 0x8102D831277E75EDULL, 0xCC0196F10F05EBECULL, 0x56F1074FD69ABE79ULL, 
            0x18BC134CB5EE7EDEULL, 0x4F11F954FCADFFB3ULL, 0x9109B86D6B2C279FULL, 0xE741F9F139021BF9ULL, 
            0x939B0F2DD7A35A4BULL, 0x4E952ECF0E0027C5ULL, 0x7334EBA45FCB487CULL, 0x5CAF3B36330A756CULL, 
            0xC446E636F5F38DB3ULL, 0x30D7068C8405DBF0ULL, 0x5BFC7A0E419C120CULL, 0xF59406BE4AE29B4DULL, 
            0xC003745D34895FEFULL, 0xE4E5C9248D9ED0AAULL, 0x9E1091E95EA02AC5ULL, 0x7E936CDC0C2B68AFULL, 
            0xFBC656CA5F846BC7ULL, 0xDDDE39723935E615ULL, 0x77439D4A93CCEEEBULL, 0x132D94891BC078B3ULL, 
            0x0A09111921A408AFULL, 0xE1F6DA58DC6FAE82ULL, 0xD6A686A55B18D90AULL, 0xCC7C01EC372CFF9DULL, 
            0x0CDB11470F17D352ULL, 0xBE20B2EF6196AF73ULL, 0x9A752373AA2A14E0ULL, 0x65AC7FF9C91E96CFULL
        },
        {
            0xEBE1A38BD46D8960ULL, 0xAA43670C2AD1548AULL, 0x34ED747062EE2219ULL, 0x55A981D18D2E27ABULL, 
            0xA2FA80C72459A03EULL, 0xD444DB9EA7FFDBB9ULL, 0x9E7B0AF43CBC5CDAULL, 0xAB96AD90937462E6ULL, 
            0x1726986D6AD38709ULL, 0xB4FD6FD1768FAF1AULL, 0xA43A3DBB64321B4CULL, 0x5E02A82E493BD6B7ULL, 
            0x40F6C1EB0FD3B5E6ULL, 0x6A043A9EDB902A17ULL, 0xCA7C6205979C4EB0ULL, 0x4FB52E2A2DEBE3C4ULL, 
            0x5EE256113028848EULL, 0xC5748F8DB1B0EE29ULL, 0x346E47BC7FEA7CFBULL, 0xECB2B2971A76FD92ULL, 
            0x232072D628A1761FULL, 0xC5440674B7FEB6DBULL, 0xFEC62176F7F28C73ULL, 0x3CE65EFBE8E2FB80ULL, 
            0x73CAA3D6E1A5A534ULL, 0xE3DDF5F3EED2B891ULL, 0xCC381EA2F3F0163CULL, 0x5B9AA44EB819F36AULL, 
            0xA46C67F54F2EF1E3ULL, 0xB7639DDDD1C565F1ULL, 0x0BC60A70AA92F5EDULL, 0x0AE20D830C3926FAULL
        },
        {
            0x75E9F21C56A23536ULL, 0x383E9EDE9CFAA33FULL, 0xACAD5697432BDB15ULL, 0xBED2AA74C8270911ULL, 
            0x77ABC7BC1AEE0660ULL, 0x758DEA874303ABE2ULL, 0x7E31BF20CA30FEC6ULL, 0x9F9F1021EDCCFAD1ULL, 
            0x5A4462A8499C248EULL, 0x13F3077B143958D5ULL, 0xD96C5BE2A5590AD1ULL, 0x7E3301FD6431E3BCULL, 
            0x965866451A57F663ULL, 0xAEA3ADCCD958BFCBULL, 0x630066BC053CA5F8ULL, 0x21FA304229F963F1ULL, 
            0x2E3F0E5EBCA91D2DULL, 0xABD823D8186605BBULL, 0x0816350CC917EE13ULL, 0x64ABEC23966C356FULL, 
            0x58B7E0B75FE0F589ULL, 0xA6F5E7195D59ABB8ULL, 0x99F82DBEAA542925ULL, 0xB58C9F8F20C8EDDCULL, 
            0xDFE4E89ECE78791AULL, 0x185FF1A2FB39AAEEULL, 0x99559C10F962FEBDULL, 0xBF2128ACFC47EBEBULL, 
            0x8AF1175C72F9D9E4ULL, 0x9C63C36006A91195ULL, 0xFE9E2B0434B55625ULL, 0x5923CDC9C7976994ULL
        },
        {
            0xD3705128FE3B2187ULL, 0x5F1CA27D1505E541ULL, 0x3A255B11C9901F48ULL, 0x9725905067DBECE0ULL, 
            0xFB378585F7884222ULL, 0x6B6F94F14A85D021ULL, 0x9094600A4D8EF0C8ULL, 0x43927301A51BEB65ULL, 
            0xB5E93F78E66261ACULL, 0x12D5FC02C5CF9D24ULL, 0x472CF8359D0A7E41ULL, 0x6C79D5D6FF7B78B2ULL, 
            0xDD7FCD60FBFFAD80ULL, 0xA0DD27276594934DULL, 0x1706E0761F2DDEA6ULL, 0x0F974007EAEADAE0ULL, 
            0x2026B416777B7265ULL, 0x63112AAAC68B9DEBULL, 0x5E5CA05C939F0CE1ULL, 0xF5D0F98A5E658DDDULL, 
            0x3094770EE752E50FULL, 0xC055590902FFD3C7ULL, 0x6027B480BAF9410CULL, 0x5F8184A5EBD19DE5ULL, 
            0xFDB5C9D557EC8333ULL, 0xB9060203E435E70AULL, 0xE8734FB7D8671A66ULL, 0x8BB519104EBF9F12ULL, 
            0x2AE9F5C9C644A73FULL, 0x5C60CB0C9F376EFDULL, 0xC1797D58C7B6E82EULL, 0xC5392B62BB80FD5CULL
        }
    },
    {
        {
            0x14DFB34A37749E8AULL, 0x932D9BE600B8AC7CULL, 0x5A7C3A8B4E356639ULL, 0xE00E539F46A5AE04ULL, 
            0x561B12D577114BCCULL, 0x4C842F04DB945803ULL, 0x9327656EDBDFB485ULL, 0x2135A10B44516367ULL, 
            0x65C8FB7287796108ULL, 0xE459B89057363DBAULL, 0xCE59B3451514C291ULL, 0x343944EBA1D5846EULL, 
            0x8FBC4F2DBAC0DD94ULL, 0x767D88D245065B37ULL, 0x6C34545DCDAEF99AULL, 0x9F4CFB471A7C2E77ULL, 
            0x8818EDDC97F0182DULL, 0xDAE00A1FC8F0FE9FULL, 0xA43CAD60AB39A014ULL, 0xAC1509FF4C59E925ULL, 
            0xBD119728C8E2E949ULL, 0xBF31D9EEC1E1C05AULL, 0xE44DA4AB70337C5AULL, 0x41F8AE9F6E68966EULL, 
            0xFED52EC1538F62B7ULL, 0x98DC7B35BBE9609FULL, 0x5CAB24B2082CB0ACULL, 0x0E20C364B340C4C4ULL, 
            0x18843CB9A574F5C4ULL, 0xCD37C6A0F84E4CB5ULL, 0x1A8294DFD59FA187ULL, 0x480ECC3A86D87EF6ULL
        },
        {
            0xD2B285D67A825F85ULL, 0x711D4DDB0FDFF159ULL, 0xF240FB376EDFFE9EULL, 0xCAA923336B9E4398ULL, 
            0x854B7DC29F76E082ULL, 0x537ADC809D5163BCULL, 0x54D7723A8D18BAAFULL, 0x0814E01253E4CFABULL, 
            0x6A0C83CD6C6226CCULL, 0x6889FD12C8978A35ULL, 0x3383AE3F53EAAD86ULL, 0x4AA24CC1F5844DF3ULL, 
            0x7859D5E453646CBEULL, 0xA59B869507C7AB6CULL, 0xF101515701C7C92DULL, 0x3F47E2D92B3C0A65ULL, 
            0xBF4069CDDCF5D5BDULL, 0x7D628D4A27AC8768ULL, 0x5BBE1D19408648FEULL, 0xCF46C24EDF7A2EA9ULL, 
            0x7FB983BAF09325FDULL, 0xBEA0255FB5639F18ULL, 0x007B424A49C94522ULL, 0x118091E9E558CC44ULL, 
            0x5DA22173511910CFULL, 0xCF3031F93C03C24BULL, 0x121E962B9BF24ADCULL, 0xA2BC3A1B6B6B3B48ULL, 
            0xEBDF850BFF4D1104ULL, 0x9F80DDE3799A76BAULL, 0x1A2FBF433F695157ULL, 0xEF533EB13EA3559DULL
        },
        {
            0x27DE8FCB873195EFULL, 0x04F3FE22890B729AULL, 0xB4906A3039B0B91FULL, 0x047088A484A0822FULL, 
            0xE56336BCF2738650ULL, 0xAF11D1006DC26B31ULL, 0xB359757012084DEBULL, 0xAC0B08122FD4F1B6ULL, 
            0x85DA893C047A7903ULL, 0xE2EF4738312E85FAULL, 0x52A8AF01D500C1B6ULL, 0x186FDC8A4A992AB3ULL, 
            0x1BF3A33097214B1EULL, 0x5E066AB4B228E6EAULL, 0x01516CD6B8D96EABULL, 0x5A8A7A0E31AA9D5AULL, 
            0x474D5E697D0E7BCBULL, 0x97F3AA4EC54A5B6EULL, 0x13040C3CCA2FCAA5ULL, 0x627845504BA7E7A7ULL, 
            0xD23EE8AE9AECA2CCULL, 0xE8C85ECA6B390BA7ULL, 0x4C08055F320AB11FULL, 0xED943B2F8F874307ULL, 
            0xDD051DE22C3B8EE7ULL, 0xCB0AD974B70B6619ULL, 0xDC958C8509C8EE58ULL, 0x0BED0CE93BF2BE3BULL, 
            0xDFA8BA8BAE4E80DEULL, 0xA04AE35147E1852DULL, 0x2A922C8D15466BE5ULL, 0xE4B6A0B10A8CDCA2ULL
        },
        {
            0x463D02BE203183EDULL, 0x2E0283406F7CFBFCULL, 0x894F0BFF33F21875ULL, 0x33B240873A4434AEULL, 
            0x199BA9F12644C3C0ULL, 0xD1C7935FB47A7E4FULL, 0x5BDB0816D1964215ULL, 0x2EC5D316CF6D04BDULL, 
            0xBAF0DAF8A1630B4FULL, 0x9FD22256152E6D93ULL, 0xEAADDB53DFCF52F8ULL, 0xB65A6A55B7F79458ULL, 
            0x1B76E95ADB91D030ULL, 0x462871B5D7A37E5CULL, 0xA3B89D027E5360E7ULL, 0x1758A306524AEBBBULL, 
            0xA8CC3A8EF0E937B2ULL, 0xB6F418E10FDB4B32ULL, 0x2A6E85AE6F3D0E7DULL, 0xB6AC8F83B2E5F61DULL, 
            0x5313E2EA16E9DBF8ULL, 0x6CD60832E1D1EEB7ULL, 0x41C622BD907AB333ULL, 0xC659486C031EF4ABULL, 
            0xE54401154EDAC748ULL, 0xD10EB1972D3A3233ULL, 0x54586EB2334E51E2ULL, 0x2A2BC6C5A9EC5F4AULL, 
            0xA4C0A929F6A1BC0BULL, 0xA82676386DB860D7ULL, 0xEE8AE5877CCBF2ABULL, 0x9A2CE13891176616ULL
        },
        {
            0xFBFB83BFFD31F0C0ULL, 0x60AFEEED8B5C553AULL, 0x36BFC81BFB9EFA5EULL, 0xE7DFFCEC8E65DE89ULL, 
            0xB132C73C27B23722ULL, 0x0F97808378E1FB87ULL, 0xDC563DF15116C709ULL, 0x5511BCA449592672ULL, 
            0x0FB34DC446AB311EULL, 0x317CD1F733F2154CULL, 0xFABC6641907B9875ULL, 0x57C5A8320B7D3871ULL, 
            0xC90A19D8E70C5C05ULL, 0xAB0D3A25A990291CULL, 0xA16756B4CF7287A3ULL, 0xD8B02D457D9C339CULL, 
            0x90687BBB0F138C4DULL, 0xEDD0D0D0B68EEF2BULL, 0x4B8925EA8F0A668CULL, 0x6F309C5919561821ULL, 
            0x50F7CF11C14B6992ULL, 0xA04BC8743EBD59CAULL, 0xB42CA08ABEFFC323ULL, 0xDEA9873FD9A31867ULL, 
            0x33854F2760342E36ULL, 0x490A4D547BCBFB00ULL, 0xA5694FCBC98BFA65ULL, 0x94180875B5EFD9F1ULL, 
            0x8D443F40D9780D6FULL, 0x68843DBF75FD2262ULL, 0xD3250258A793E5D9ULL, 0x98DD798009E9AAEFULL
        },
        {
            0xDB14B3616BDF065AULL, 0xE7B2FF9637101CBDULL, 0xC5719FD4A4552B73ULL, 0xA3FC85ABC9B017FCULL, 
            0x42426F913BAC77D1ULL, 0xADB33243CBF9C5D4ULL, 0x02FF6F8EB4774695ULL, 0x9AB19AFFAAD77602ULL, 
            0xC85E5B8B1A3D384BULL, 0xEF7E7C692FCB2EE2ULL, 0xEA6F92B7F126C049ULL, 0x8C015A2325834919ULL, 
            0x3C77FA9A3D09D87FULL, 0x7F547C9DBAED6586ULL, 0x94BC6C58E9B1910FULL, 0xD69AF5D5FAA55929ULL, 
            0x30F11F7300B28FE4ULL, 0x2587794D8F32DF50ULL, 0x162D8814D9906B0AULL, 0xC4628A0EAE1CAEEFULL, 
            0xAEB53633D581D522ULL, 0xE1F7855C76AB901DULL, 0xB3284CF44E9849FAULL, 0x6A0221F143C0D41FULL, 
            0x1F3D3E05E4662D38ULL, 0x5FAB292BEE42D46CULL, 0xA794835024E806E9ULL, 0x45B4ED8F920C1A65ULL, 
            0x4FBB954938F72084ULL, 0xBC4AC801529C5D95ULL, 0xAA4F68BE8C114AECULL, 0xFF78365EE1FC1A99ULL
        }
    },
    {
        {
            0x0101C83F2D4E5AD0ULL, 0xC499599908EE61E7ULL, 0x09B221D79958A26FULL, 0x9989987C6A71F94BULL, 
            0x27C994F83921A23EULL, 0x550CDF01145438ACULL, 0x5745C9FECBB8BF1EULL, 0x18339DD289370203ULL, 
            0xB95AB439A4FDDED9ULL, 0x042329D052450269ULL, 0x219060B2FA9D2B10ULL, 0x41ACACDDCC261041ULL, 
            0x111C2540CD841106ULL, 0x79CAFF704C8DDBD5ULL, 0x204AF9BC4D5A7895ULL, 0xC13400CCC44B77C9ULL, 
            0xA0BFC487972838DBULL, 0x5AB9A3639570AE83ULL, 0x744E249B1E515098ULL, 0x2D371AD4286784EBULL, 
            0x405614A914C61E02ULL, 0x2372168346E05164ULL, 0xF4FADB0B6CC3E00BULL, 0xBBDAC21B453FDDAFULL, 
            0x9EECE1CF2CF5B537ULL, 0x5774CAD6C3DA70DAULL, 0x43A037A78A0CE844ULL, 0xB1180AD1BA0FA4A9ULL, 
            0xE0280DDF18DAE0D1ULL, 0xA5A98D86B55CE742ULL, 0xE7BCBC278C9A25BEULL, 0xD98380704F386D7DULL
        },
        {
            0x973FD33D0A454A0FULL, 0x2D88053397631C3CULL, 0xA0F8C90EF8EEF561ULL, 0xA3A05FCB3562A920ULL, 
            0x3D5334B53D9388A0ULL, 0xAC60187F3ECF3309ULL, 0x0C9C180B01B47BB3ULL, 0xBEBD0792CEA26BC4ULL, 
            0x1A3037050D93EEF1ULL, 0x6666A0445A761630ULL, 0x7EE2CE665E83AAB4ULL, 0x593FCECE83E109C8ULL, 
            0x6BEF3AE17630C310ULL, 0x1FEBEDE4F9A300E5ULL, 0x70A3E43E4E45A64FULL, 0xB177109D189778A8ULL, 
            0xAD0E9DCEE57B8497ULL, 0xDC278C0A0CBC01ADULL, 0x034B7C18EFC76F6CULL, 0x472D61C859C42C60ULL, 
            0xDAE0504BFE907589ULL, 0x3B0B5AB0FC49040AULL, 0x692F42BA1727FF1CULL, 0x8ED7D1ED9B7412F9ULL, 
            0xFBE40F88B9553FF6ULL, 0xD0DB546D3E822DC4ULL, 0x84FC319FC2950034ULL, 0xB3C7368828C3807DULL, 
            0x3EBB7189A9CC4B8FULL, 0x00727801E7A3B07EULL, 0x0E5CA83281C200C8ULL, 0xC8B7C211AA4385CBULL
        },
        {
            0xEA2F14710C609868ULL, 0x566FFD9FD2F2EB05ULL, 0x42212A12C8A2887FULL, 0xA19FEE6E0313F81EULL, 
            0x87DC9A8C08764A3CULL, 0x8CD027C454D990A8ULL, 0x4DE77A6998CC871BULL, 0xC6B2D1BEE4E78266ULL, 
            0x1F912E849868C8E1ULL, 0xC919BF67E626C642ULL, 0x4411F174561ADCD0ULL, 0x04EDDC1EDA9AF2B1ULL, 
            0x71954594F4927F73ULL, 0x850D75398F4541F1ULL, 0x88BE9022B1FFCD34ULL, 0x51DAF42E182FCF09ULL, 
            0x40A73A7A44BB55B4ULL, 0x5677BA32BA1DBE6EULL, 0xDDFCA9EB39277B32ULL, 0x19394B3DF97F8BD5ULL, 
            0xBB8BAE4AE35B3F72ULL, 0x389DF16B577C03B2ULL, 0x71B42DF1D8ADC990ULL, 0x85667B67ADEC197EULL, 
            0xC65F7E6002621071ULL, 0x79EDDE6E4293E56EULL, 0x3631F8EBC6262CD9ULL, 0x4413A05C75C57A0CULL, 
            0x5FF6BD137A6E9F99ULL, 0x450F778825F889CCULL, 0x213093232D42A8E6ULL, 0x4F22098A709E2DAFULL
        },
        {
            0x03478CF8905FB08AULL, 0xECCC7AC1EA30A790ULL, 0x8683B40A67587EEAULL, 0x91EA13C2973E7F3AULL, 
            0x0E83C85079B5588CULL, 0x1FC1EDC5E0E30E0FULL, 0x187375EF566CEDF1ULL, 0xD67E8FBB67DF16A2ULL, 
            0x94ABE9FC34A41B16ULL, 0x930C1D894CDB7583ULL, 0xAFC8A3545AF0D8D8ULL, 0xC440BB9E830BA5B9ULL, 
            0x4019C810BBB6BE79ULL, 0x28CE132F37A12B3CULL, 0x33CFC72ABC43C087ULL, 0x00A76A0CC8779DB6ULL, 
            0xB86CA82CDC478658ULL, 0x55A5A0498A2D97B6ULL, 0x0F8A917FA965888FULL, 0xE69288C0D39A17B8ULL, 
            0x63F33857F39E60DFULL, 0xF2D5BFD7BB043D66ULL, 0xDC9299E98E536891ULL, 0xB31C85CEC2C16603ULL, 
            0x757CA0D9C475AEFBULL, 0x98F8D6CCEEED0613ULL, 0xCA41D10499107D00ULL, 0x5E10A9A022671E7FULL, 
            0xC6B541D2A744E0E0ULL, 0xDD58EC4653DA85B0ULL, 0x7B16698D677A5DAAULL, 0x53D2B11F96020D36ULL
        },
        {
            0xAA893CF875C20AC5ULL, 0xFFF5F87E12F9943DULL, 0x7EFA33701DC5E9B0ULL, 0x9A78293F12A7BE46ULL, 
            0x4F644C3C81E6ED27ULL, 0xCAD6A13C577EAC14ULL, 0xCA546558443970EEULL, 0xC386B8839BA366AEULL, 
            0x1B10A338DF5530DDULL, 0x30A0DC7762690C3BULL, 0xD1E13CB0D88540CBULL, 0xA9DD0AF2A3AAB48AULL, 
            0xD408AD8210242D96ULL, 0x8FA69C48508F4CC3ULL, 0xE8DF26F163DC4470ULL, 0xE3C3E9900201262AULL, 
            0x208D572587CB5E89ULL, 0xA8B2460CC60FBD59ULL, 0xF3D580C163175CA1ULL, 0x77ACA42DE81EE350ULL, 
            0x337BDE2F627A5B90ULL, 0x434869143175705EULL, 0xD0C0F5276C3DF41BULL, 0x5D708E645C92BAC3ULL, 
            0x7AD0E433418E4AF0ULL, 0x4945DF0BE7A78A69ULL, 0x36A883B8EA111193ULL, 0x0448D3F9ABC165F5ULL, 
            0x244DD1376247181EULL, 0x417ED809D3E83155ULL, 0xF53C068F616CA0BFULL, 0x0815C37D24538483ULL
        },
        {
            0x25A56383CB9AA903ULL, 0xBDD9A73087E9A6D1ULL, 0xF7F426555A2C390EULL, 0x08A187E7A2F3D29BULL, 
            0xB8858ABDB08CADC6ULL, 0x088EC076260E88B9ULL, 0xE7FEFE104209A479ULL, 0x807E3074476C52A2ULL, 
            0x9B1B05AED43CC3EEULL, 0x5396AE6CA1F6B40BULL, 0x5A35D1119CAE11F1ULL, 0xD0B87C261935B551ULL, 
            0x4840701AED8E6EDDULL, 0x5D05A9429FA2359AULL, 0xC71B4C76EA85C0CBULL, 0xD6C5EC9FC35DEFB9ULL, 
            0x32B27DCB5BC14A02ULL, 0x0867C6E42C6723B0ULL, 0xF2D169627E1A8BE9ULL, 0x4F0814A9708140D1ULL, 
            0x49957D916348D80AULL, 0xC998B6AA404D65D6ULL, 0x50C4990B575E5185ULL, 0xF57D586A9367EF81ULL, 
            0x3C750046CD9D824DULL, 0x4AC4C5C6CFE98A90ULL, 0xEE7E0EC962781A58ULL, 0xD99A14CE8E17014FULL, 
            0x4F0387484152F02FULL, 0xCBA694FE66BF9117ULL, 0xF6B1A6EBA2571496ULL, 0xDB3274489565ACCAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kSeedConstants = {
    0x5C0494C1B237478DULL,
    0x65BB3D16F341E2EBULL,
    0x8E58B3529326A92CULL,
    0x5C0494C1B237478DULL,
    0x65BB3D16F341E2EBULL,
    0x8E58B3529326A92CULL,
    0x391FC6FDEA765468ULL,
    0x5C80AF77BC0DD6A2ULL,
    0xEB,
    0xC3,
    0xA3,
    0x08,
    0x49,
    0x6D,
    0xCB,
    0x37
};

const TwistDomainSaltSet TwistExpander_Alioth::kTwistSalts = {
    {
        {
            0x9B32C389DB4B0041ULL, 0x766364513AD705B2ULL, 0xC9466C0E4F73B187ULL, 0xD513EC4FCA170F36ULL, 
            0xD4CA10B63E71EF93ULL, 0x4C1580C527182E7AULL, 0x028BA0FCD5E06146ULL, 0xB38481A82763738CULL, 
            0x7613E702FB609C12ULL, 0x8CA15EBF9C03AAAEULL, 0x42E25F34F99CAB55ULL, 0x4F616E23B338D750ULL, 
            0x6D801FA0AE1A40AFULL, 0x136F8739E5A89B7BULL, 0x716E6EFEB2102402ULL, 0x89F86DAB104EA124ULL, 
            0x159D6DB8493E2833ULL, 0x4A81129827D76AB5ULL, 0x7A8DCA6F9932998FULL, 0x7CB9F05E7C6FE9C5ULL, 
            0xC99753085D18B19AULL, 0xEE7666F297A3E8FCULL, 0x1BD3F2770F6672F8ULL, 0x856A610A60D368C7ULL, 
            0xA1B35EC5B222157BULL, 0x44578D317671629DULL, 0xCC8C54A8D4E90F79ULL, 0x9EABC2CD81A60A44ULL, 
            0x8A5C2BB7C0DB611EULL, 0x99C2C33357AADC17ULL, 0xEB47067063D40562ULL, 0x4B6CF64DD7F008CAULL
        },
        {
            0x3DF9C61B65B9301CULL, 0x3973BDA8BF5EBE04ULL, 0xD01F348DCAD9DB68ULL, 0x73F5245F0C37DAD8ULL, 
            0x69A78BDEAFFC2A38ULL, 0x5ACBF1DD3339C1FAULL, 0xA4427AF9281910F2ULL, 0x24F3D3E2625E1B1AULL, 
            0x740D31276CE800DFULL, 0xA9DAA13DC9B707CEULL, 0x8953FFB3665F1426ULL, 0x913C98E7563342D7ULL, 
            0x92B84F047ACF2A5AULL, 0xE44597F2AF8E8938ULL, 0xDB3367C76BA116EAULL, 0x849CAC4DB4ECFD45ULL, 
            0xBC63CAB026BEBDF2ULL, 0xBB39DE6CE2619FCEULL, 0xB640AA310E5E9BC8ULL, 0x740B671F817159F7ULL, 
            0x411E25BF9A2BAB36ULL, 0x7EE638A8B60B17D4ULL, 0x79AC0E1EB793A086ULL, 0x188EAC25A926ACF3ULL, 
            0xF432C572127FA1A2ULL, 0xA0E8FB090E3F7370ULL, 0x5677D17C394CDB82ULL, 0x58F053C7DE59D555ULL, 
            0x0C9C06B14C5B924EULL, 0xC060A96552E7F001ULL, 0x3ED98BFF425BDBBAULL, 0x5439F68E8950C870ULL
        },
        {
            0x9DCC3B76559645FFULL, 0x613B436CD88159F7ULL, 0xF69330B0D1613515ULL, 0x9BB9F929F29CFA25ULL, 
            0x31B5EE85EAA5D941ULL, 0x5569D7EE0BAABDB9ULL, 0x68624D7B019022A4ULL, 0x488F1641CF1D5C0BULL, 
            0x469E3057682BF182ULL, 0x7C6F0361FBD95702ULL, 0x79C3734CCA740DE3ULL, 0xDC736333CEF5C425ULL, 
            0xE70561D227047125ULL, 0x9738214D6049FDAFULL, 0x006678D28BC3FAFAULL, 0xFE8C527AD952219EULL, 
            0x1FD704D408833B76ULL, 0x90E9C444FE86993EULL, 0x52CC21E2AF8EB4D1ULL, 0x194E4810C44B9434ULL, 
            0x7EE281855A51120AULL, 0x5A533FC2B5F0FE90ULL, 0xE61295E0BF5C4795ULL, 0xF137C9BC015A2B25ULL, 
            0x35B554AA28469C1AULL, 0xE03BA7FA040C22E3ULL, 0x29E0C9EDB81E37ABULL, 0xAFDD03CAA465F3E5ULL, 
            0x0C201D2A4EE584F5ULL, 0x7A4A6F8011CE25CBULL, 0x1B858B3F25F67BA9ULL, 0x4407C98BD7E31561ULL
        },
        {
            0xA81F889F19FFA767ULL, 0xE66DFAEF4B696DB8ULL, 0x7E507090AAD53634ULL, 0x7DDEB07C7A4A8D2CULL, 
            0x6C1BCB933BDFD117ULL, 0xB128D0C9A7B45683ULL, 0x1DFAEDB8AB147EA5ULL, 0x1260B37DECEF7EC6ULL, 
            0x914C8231C798AA87ULL, 0x49E68C9634B2AD16ULL, 0xB7B89AC540425BCAULL, 0xEAB8230D150671EAULL, 
            0x4129E586A5D66BEAULL, 0xE8F6A3FF7AB67252ULL, 0x8476E4220ACA7440ULL, 0xA04556E2A3985440ULL, 
            0xE4367FD37660F314ULL, 0x05C915D2A154D037ULL, 0x79600DDFE70BD2EDULL, 0xE58D003736A0C54EULL, 
            0x45C8AC3C7B22C237ULL, 0x75B2AB93CF972D8FULL, 0x46F4B578E1EA44F9ULL, 0xBD00D30F9D3609AAULL, 
            0x69E78FBF49232A80ULL, 0x5C69FF671E735BA9ULL, 0x77A6EFB4F99535E1ULL, 0x24BC6917D2390714ULL, 
            0xB9291B4B55BC4C7AULL, 0xE15BFC2836EE2F06ULL, 0x7F13D4C60005CE25ULL, 0x312C07F1786702CCULL
        },
        {
            0x2455DC45B898E72EULL, 0xA38059862FD84B14ULL, 0x94CE3319E059075CULL, 0x68637A396455E98FULL, 
            0x31F7DE7589018E14ULL, 0xADAF21B9E7A0CE1CULL, 0x6534D2D80F88B23FULL, 0xBA52729594651013ULL, 
            0x253C9B897D22A044ULL, 0xBF9ED1D1675E8571ULL, 0x063D9CEB8083A909ULL, 0xC3AF0CBAEA560F55ULL, 
            0x83C35B0CC15E7547ULL, 0x4A9FCF10AAD6F274ULL, 0xCD34B97F98DACD6CULL, 0xA7EF69A07A707383ULL, 
            0x9BEF013AC1ED58A4ULL, 0xC06F751C0AAA2ABCULL, 0x4A7D1ACF5BD6162CULL, 0xF4A9D03FE338577FULL, 
            0x241F4C0C2104AA86ULL, 0x127D6D58B2C4FA5BULL, 0x4B10270C08A80EF6ULL, 0xEE447E8B13CD3787ULL, 
            0x97BC95E7CD201A84ULL, 0xB86CE7EAEB1979F2ULL, 0x1B049142CED17CDDULL, 0x2BC52621C677E702ULL, 
            0x6BE0A7237792EA12ULL, 0x7BF97799CA46AB26ULL, 0xA1167BA9F9657F7CULL, 0x56B29149609AB7DDULL
        },
        {
            0x5A17DBC644416916ULL, 0xC17D50ED5632CAF7ULL, 0x9BCF4D7F4516CA4FULL, 0x3966CAD7532B2FA0ULL, 
            0x24EBA8865C239337ULL, 0x35E851106C02528DULL, 0xA417B359579D618FULL, 0xC3D569FBACC9274AULL, 
            0x775778FCDFACDAF1ULL, 0x900A7E72F6472B6AULL, 0xEE811D9BDE34D475ULL, 0x96B0C99745C6867EULL, 
            0xF8AB927481540102ULL, 0x1F56F3628A91ABA2ULL, 0x054644856EEC909CULL, 0x99936BA6792122A8ULL, 
            0x6BE9051E88B4D592ULL, 0xA403455FC46263CFULL, 0x71217F65C45F473CULL, 0x4D886D85956B8E5FULL, 
            0xC6E9C98FE33965A2ULL, 0xF420E075F47640EBULL, 0x6AD316C9B79A03FCULL, 0x073A3C8DEC3BA9C4ULL, 
            0x05BB2FBF844E96E4ULL, 0x54FD556C36AB3697ULL, 0xE607C8404C2DBD1AULL, 0x40C93C5A6BC6232CULL, 
            0x0102143617FD9514ULL, 0x93CFBAED7B8588E7ULL, 0xF9E5D2F9FC3FD31DULL, 0xFDD7A446532FEDFBULL
        }
    },
    {
        {
            0xCB091158D5F3ED04ULL, 0x472643328D6606E6ULL, 0x7A1A0AFD52B067D0ULL, 0x41E9601DFF422E42ULL, 
            0x4F357624B3B7248FULL, 0xECE3A0E2AB9B066DULL, 0x7D8518A37879EFD9ULL, 0x6333BEEF0F474A90ULL, 
            0x4B5FF72D21858567ULL, 0xF14035EF89BB30EBULL, 0xDEA36B1AA8AF34CAULL, 0x68D15706E83C78AFULL, 
            0x0507E8E2FE28B544ULL, 0xF7E7E64C056539BCULL, 0x21BCD7596B4252DCULL, 0xAD5A7589C6296A64ULL, 
            0x365CED7E77BBEB06ULL, 0x9A9F5A0006D48C1CULL, 0x4093819734CCA559ULL, 0x3DFA73A92B6F7ED9ULL, 
            0xA51B78A383880797ULL, 0xCAE51D6CE6913D95ULL, 0x392A3CF03689D766ULL, 0x9067DE347F43A87CULL, 
            0x32072F436123C8EAULL, 0xFCEB85AB3633D72BULL, 0x0EE113F8815373EDULL, 0x20552E45D76C0BB3ULL, 
            0x8DA9FD6A560FC31CULL, 0xCE426A99D31F665AULL, 0xC3CA773CE4D29B1BULL, 0xA0431F2D037F612EULL
        },
        {
            0xDC9E7AC9A44B2A38ULL, 0x28B0CC48E7246944ULL, 0xB3A6A8CED5B70557ULL, 0xAE4DE3EF7CBA716EULL, 
            0x501B59345D34C3C9ULL, 0xF98D4AC92096D706ULL, 0x27D1331AA46590EBULL, 0xD7CFAC39AE40E070ULL, 
            0xFC3E93BC418ED3DEULL, 0x06C93B845B9E326DULL, 0x6BBD32EE80B0177EULL, 0x63C3CAD38FCD7905ULL, 
            0xB4636E750FD3F01EULL, 0x28E26D5917DC8FDCULL, 0x1BC41E5C6000A05DULL, 0x29AF0EE04EAE589DULL, 
            0x6ECF1B9EEF81F1F3ULL, 0x937BB73E938C722DULL, 0xAAD3F0C34B846B81ULL, 0x452233AC9893F099ULL, 
            0xC6985A7EBDC66D10ULL, 0x42237035635DB8C9ULL, 0xE13ADB579D29D2B3ULL, 0xAA514886198AF27EULL, 
            0x23CCF6B0ECBB0313ULL, 0x93A9C7398C85BCB4ULL, 0xCBCB283CFE40080EULL, 0x32857F52C0CDEFD7ULL, 
            0x7B03CE1C7843FD7DULL, 0x818AE9A9E1BD4381ULL, 0x5F7CAB7C3802FDC0ULL, 0xC6632A1A840C4BD1ULL
        },
        {
            0x5C0B8663E6EC73EEULL, 0xAE27108421E3490FULL, 0x28BCF74AC0B250A6ULL, 0xDDBAE126927A8C1EULL, 
            0x93C7D290E4DE2BF6ULL, 0xEDAA4C64AEBB6343ULL, 0x8E250431465F565EULL, 0xC81FF2B226443F57ULL, 
            0x35C5156BFDA83E06ULL, 0xC451127B9B11C85BULL, 0xEFB43E91C65D809DULL, 0x8E6D78E227A8E19CULL, 
            0x0DCD84EA55F51715ULL, 0xA0ED0502D02135CDULL, 0x2F87380AB7E1EE15ULL, 0x36B0C365405BB6CEULL, 
            0x61D2AEADFD387622ULL, 0x99539E17FE09BF25ULL, 0x29C2AF9345190D32ULL, 0x097E05495440351CULL, 
            0x40340A499516ABEAULL, 0xE2D468F44847C472ULL, 0x5D6DB2C6D0CB55F0ULL, 0x3BB6291C3D56DB04ULL, 
            0x1D6E1ACB4D4E86AFULL, 0x8E12748B6A9131B4ULL, 0x9D3D2B8B002DF6C1ULL, 0xADE367D71CCD38C9ULL, 
            0x95B32535E8F5DD4FULL, 0x34727BF3E8AAB5ADULL, 0x02459A18FF82147DULL, 0x4C681E360695FD19ULL
        },
        {
            0x84244E750DD17B04ULL, 0x356645217C85408AULL, 0x96FC8AA355917C48ULL, 0xAE5E8FE560C54561ULL, 
            0x904BA91AE4B956B9ULL, 0xC5D936C1AD9FA050ULL, 0x915CDF09E894DBBDULL, 0x1536DD8F475AB660ULL, 
            0xB5DB0A29D31B9409ULL, 0x665C0B1BB3C1B8C7ULL, 0x03B8B71C050A48DCULL, 0x327692E01A41FC8FULL, 
            0x87AD4E30468BA9C1ULL, 0x073C56DE10AFD0B6ULL, 0x037B7A7A509F6B1AULL, 0xD2046CE6BDD1C795ULL, 
            0x1C1287F163C1E6B1ULL, 0xD3E3EB2A164B9D75ULL, 0x86CE68E888B37BECULL, 0x1A25BD2036109E87ULL, 
            0xC044A56A78DF2DDAULL, 0xB51509C0B8B61CA4ULL, 0x9864DE3292EB4286ULL, 0x25865D9F8F54C8C2ULL, 
            0xE77D13A930E53E63ULL, 0xF522659831FB8975ULL, 0x7A9BCFE96563A19DULL, 0xD2BDB2CA8C5A65E0ULL, 
            0x8365A35263896084ULL, 0x6D60085E5C280062ULL, 0x96DED4953D1A183AULL, 0x03F92ADBC309BEF6ULL
        },
        {
            0xED2F8D395ECEB052ULL, 0x9855FD43F81A06ACULL, 0x2B7A5134B45A7DDEULL, 0x255D0CACAAC07544ULL, 
            0xA829410A76D0578EULL, 0xDAEAFE65EB48F8DCULL, 0x026BBA33AED450C9ULL, 0x3CD18CBCCC23FEEDULL, 
            0x9BEE8C5CEDE3458DULL, 0x35BEC28449B8A776ULL, 0x3DFA74A3CEADAB7AULL, 0xD2B0B2D84960D49AULL, 
            0xCD2B64CE054A4316ULL, 0x2C1469B2525D32C0ULL, 0x5807126C8DE84EC7ULL, 0xBE9F264E28AB2852ULL, 
            0xA44E57C949F4D06FULL, 0x359F83F03A56B314ULL, 0x4D3A0E5227EBA4F4ULL, 0xDF22DEABD1CE4F74ULL, 
            0xC5E7DAC7377FD141ULL, 0xE81834987AC24ABCULL, 0xCE98C6414A35804EULL, 0x515106F2ECC6BC54ULL, 
            0x3A60FF3D36C8D68DULL, 0xBC1B1316607CF947ULL, 0xDA8E8BDEE1D7925DULL, 0x8195A30E4727D57BULL, 
            0xB754DD27B5D1D0A5ULL, 0x99F074508BA07670ULL, 0x607A16F28C65A06DULL, 0x2E4D44148CC2F28FULL
        },
        {
            0x49CD5C41C7F59C1AULL, 0x93604D61EA0B3195ULL, 0x1ED0BA9AFFF91C08ULL, 0x7CA5854C64A06C07ULL, 
            0x0EB38EAFFF97FA6BULL, 0x3963E051F48EB9E3ULL, 0x2A40FD201722945DULL, 0x6DD7A342471514FBULL, 
            0xBE53FB26B2FD9972ULL, 0x17F503A01F9E7C11ULL, 0x97F453A05D4C16E4ULL, 0xD635E041358E73F3ULL, 
            0xDD4550966612EF55ULL, 0xAA65B1010163CF65ULL, 0xE30EFA4FE127D160ULL, 0xEBFD2E3F1C72911FULL, 
            0x386DF4C10A59592FULL, 0x9B48CF28ABDA0FF9ULL, 0x9C3637D363AEDD24ULL, 0x44FDF8CDBD3D934EULL, 
            0x68DC0AE480B5CA96ULL, 0x9DCB95CE94ADF868ULL, 0xEB8744FBE0418E3DULL, 0x98ECF0DC21D314B6ULL, 
            0xF090B0FFDDBE9DE9ULL, 0x90284F1369CCB9FAULL, 0x891E3DE544062F91ULL, 0x201E29129AD28546ULL, 
            0x9AC5EE760213485CULL, 0xDE7C4F04BDE5C1A2ULL, 0x13964A1FBC34E8B2ULL, 0xED3F31E3B2028EF0ULL
        }
    },
    {
        {
            0xC6317A53E0550AC7ULL, 0x63C7854845D44B46ULL, 0x7873EB589E6AF579ULL, 0xFC29BDB4E4DD8E17ULL, 
            0x2C076F51955C7FB5ULL, 0x656CD30DDBF19AD8ULL, 0xDB51E1924CFF4E66ULL, 0x70B60F9593489416ULL, 
            0x13AF7B015697560FULL, 0x99083A61D606FCE4ULL, 0xBE30A4F30D0C46B4ULL, 0xF9E21F65481F489AULL, 
            0xFC86DDEB994F488BULL, 0xD303BA85CA08EC24ULL, 0x3DF4287FE33B1F9EULL, 0x922DFC3593662CE7ULL, 
            0xEB1A35EA110107CEULL, 0x65AE4214215BEDE7ULL, 0xB1C9F69E8FB1323CULL, 0xD7188FFBF97E39B4ULL, 
            0x6399F1A036F340DBULL, 0xADE584FCB1C1CF7DULL, 0x7CFACF56E3B8F08AULL, 0xA54171585C3976EBULL, 
            0x4BD47FF33959EB53ULL, 0x0D0318A7216BDBFBULL, 0xF5BB9D3BA4026023ULL, 0x71D7BB3FE346218DULL, 
            0x11982236E73C7943ULL, 0xC0AA91AB794204EEULL, 0x37379BF532CE8ABFULL, 0x45EDF5507A09E19DULL
        },
        {
            0x1B87EAF7D0E09F60ULL, 0x33E566AEF40FE000ULL, 0x6058DC40E690AE6EULL, 0x18A0A9B34840916CULL, 
            0x349C1FCFA716B623ULL, 0x8980766E294F6D81ULL, 0x5B43BE6C32BB4393ULL, 0x400683B40EC90DEBULL, 
            0x483C5BA8F0CBCEC5ULL, 0x56AE069A5BE0EC7BULL, 0x7CD8A0EB7F386AC1ULL, 0x00AD339B67490767ULL, 
            0xB847F0A3AFEC7882ULL, 0x4C1FA624EF058DF0ULL, 0x33977728836D5F16ULL, 0x0E78782E25518631ULL, 
            0x1B099D40F0FFE5FBULL, 0xA6BF493F7085BA5DULL, 0xDECC9D05B7CC8BACULL, 0x4D983F0B0CCC987BULL, 
            0x8B30111064F209A7ULL, 0x8C6FBFB3A72A5963ULL, 0x091A2808C2DCAFBFULL, 0x65B8AFA0AECA9364ULL, 
            0xE8DDBEA871D9BDE3ULL, 0x8E5B6DD370D42F2EULL, 0x324F9ADD900BB7D5ULL, 0x824D3D85A366512BULL, 
            0xC57CE59EDBDB6DC8ULL, 0xFDAE1DB7BAF0467DULL, 0x63CE3B70ABD99752ULL, 0x0CC176E04F3644D3ULL
        },
        {
            0x56F43E525C6C5C1DULL, 0x03F301D0F41AE0FAULL, 0xBD96A2B57E8D8A47ULL, 0x6C1F88E50963F101ULL, 
            0x750D2CD80D4D9811ULL, 0xE499B1F942EAB78DULL, 0x34EB5FC16E49748AULL, 0x0BE278CCB8EE0F86ULL, 
            0x2FCD297FCA851516ULL, 0x6DC593B588C122F4ULL, 0x8490344B94DA23B9ULL, 0x14CD6CA8BD05A5BFULL, 
            0x56963EEBFB58C5EDULL, 0xE26DB79778933C49ULL, 0x7CBD8C658DC0BE1CULL, 0xCEBD484779FD6651ULL, 
            0xC7940282124EAFC8ULL, 0x2A0DF655E354CFC6ULL, 0xE404FB751B3BEF19ULL, 0xDA0013667AD9CA7DULL, 
            0x1BB21FBA94B21B7AULL, 0xC81A01347C9DDD35ULL, 0x0A01376F01172AF0ULL, 0x514941665E10507EULL, 
            0x1EC5B89B36AC6E13ULL, 0x1C3B9E96C146E6CBULL, 0x4154D76216936BC1ULL, 0x1D1B908A6D6C1933ULL, 
            0x12DFEE00BCD8B2A6ULL, 0x15D0AC687BF3C93EULL, 0x855053089D4A44FBULL, 0x143750DC3A90B608ULL
        },
        {
            0xEB3DA639CC7C3DC3ULL, 0x7B956013F8890D03ULL, 0x54E068FA3C782309ULL, 0x811FF485C3977628ULL, 
            0x85C8A8B3E5C4C3C6ULL, 0x30AEB79991008047ULL, 0x6A3E97434C94E052ULL, 0xC6AC0D8215F7FA53ULL, 
            0x329CE59E64EC55DBULL, 0x90DBFC21D78FF790ULL, 0xFEEBD99567401DD9ULL, 0x0E2B6B314FE7F6F8ULL, 
            0x7AD195CA287BE605ULL, 0xA2F0AEE60043EB0FULL, 0x2B4B0F5C7FC0A084ULL, 0x24F5BCA16BDF64D0ULL, 
            0xF5826299944DEEA0ULL, 0x27F74BFCE879C7DBULL, 0x9F46D74AC9483514ULL, 0x48CE5226242B1989ULL, 
            0x7A49FC13918BDBEEULL, 0x28F3F12CCCE7B707ULL, 0xAE2D0F1B727AC640ULL, 0x8B2E70425A7B8878ULL, 
            0x7DA981684DB45E0FULL, 0xB26337BF88161C95ULL, 0x36BC072B8DA5BDF4ULL, 0x881B2C97BF95EFDFULL, 
            0x8A3B36B95CFEA6D6ULL, 0xB7BBCE411E2998D0ULL, 0x71C79E8599EA50E8ULL, 0xEF237E2E0B76CBCBULL
        },
        {
            0x14AC074C130138DFULL, 0x77A0E8EFF72BC2CEULL, 0xDC75B8AA8A15B36EULL, 0x04E4162C74437E74ULL, 
            0x682E3A17529217C1ULL, 0xF1DEE00766F8DE21ULL, 0x91ACAFEEC0965BBEULL, 0xB54F752ED60AB9B8ULL, 
            0x3B12A37D49BAC169ULL, 0x37D775B4380C1D1FULL, 0x8EED8783D21CB6A8ULL, 0xF2CD70B03AAC8F2DULL, 
            0xD44F46B1BB43F4BEULL, 0xF396E3D5D8C4953BULL, 0xCC679064C38F61F5ULL, 0x3FC43ACDE8756374ULL, 
            0xDB3AD3B2FB950094ULL, 0x58A8439DC69CB8AFULL, 0xD4F5C1B7F263CB7DULL, 0x72A0363ABB04EC85ULL, 
            0x53011A08F5DB7E3DULL, 0x4F61749A5013AB77ULL, 0x0FE53E541AFA8547ULL, 0x565445CF64F3F464ULL, 
            0xFA66D6A567D480FCULL, 0xDD5EBB4AEB1CF61BULL, 0x2B0FE6963AD7E605ULL, 0x05B30B5A365159D2ULL, 
            0xAE6AC8AA2CF5117EULL, 0x05B261D87D354392ULL, 0xA92E9B1A7A49CA34ULL, 0xBC9BB533957C679EULL
        },
        {
            0x02D52BFCF03E8884ULL, 0x572A941F6E966150ULL, 0xC7F66381BB0BE256ULL, 0x53DC972D7B441B8CULL, 
            0x0B4D2415C9A7522CULL, 0xDFE817764301823FULL, 0x4638B7923008BF3AULL, 0xAF789E2645FB9B6CULL, 
            0xE78F7DE6B24D1E6BULL, 0x6BF45F76046B1CE7ULL, 0x47C1CAA68A7D080DULL, 0x75BF50D856514565ULL, 
            0xE198E993AED99116ULL, 0x5E0759C47F4F9ED1ULL, 0x6B6E55AAA482D645ULL, 0x9C37D76985587236ULL, 
            0x867506A98FBE21DFULL, 0x3CE51FBFF2052380ULL, 0x02A921D4962327F7ULL, 0x1B66BC05F56DD7D7ULL, 
            0xB1098560C0F68623ULL, 0x6D516AF83D0A770BULL, 0x4E8B48DC207BD335ULL, 0x8560CAFC650F8D41ULL, 
            0x71BA7E265FFB0F98ULL, 0x9D0F73E982781EFDULL, 0xDE139CECCC59AF5EULL, 0x0C41C7E2696EEED8ULL, 
            0xA61FB1E1518F96ABULL, 0xFAB393B684E7DB07ULL, 0x7E174C6FBA6267A3ULL, 0x5269A39945BB971EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kTwistConstants = {
    0x725F03B1096759C9ULL,
    0x2FAAA865ECAE139EULL,
    0x5D238F457E87F305ULL,
    0x725F03B1096759C9ULL,
    0x2FAAA865ECAE139EULL,
    0x5D238F457E87F305ULL,
    0x10C542F725B88B3EULL,
    0x523CE3722C0F393FULL,
    0x03,
    0x0C,
    0x6E,
    0xEA,
    0x73,
    0xED,
    0x7A,
    0x35
};

