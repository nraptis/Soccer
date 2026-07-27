#include "TwistExpander_Miram.hpp"
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

TwistExpander_Miram::TwistExpander_Miram()
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

void TwistExpander_Miram::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE0AFE53C4D4D2F65ULL; std::uint64_t aIngress = 0xFDB2589699FF414BULL; std::uint64_t aCarry = 0xB53C18B595BF6BF5ULL;

    std::uint64_t aWandererA = 0xE83F3005C3E480C5ULL; std::uint64_t aWandererB = 0xABB9B6A53230BF52ULL; std::uint64_t aWandererC = 0xAB6C7F8BD13A54A1ULL; std::uint64_t aWandererD = 0xCD3BB69C67B496E7ULL;
    std::uint64_t aWandererE = 0xA99AB1EAF8F221BDULL; std::uint64_t aWandererF = 0xC53E01FCFAD075CCULL; std::uint64_t aWandererG = 0x974DF3BFC64DB1E4ULL; std::uint64_t aWandererH = 0xF19B534F56430CF4ULL;
    std::uint64_t aWandererI = 0xB0780BEB5BEB21A3ULL; std::uint64_t aWandererJ = 0xFF259A447BCCBCA5ULL; std::uint64_t aWandererK = 0x88BD3C716A3F1A0DULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDDADD3371D276100ULL;
        aCarry = 0x88A54A9A8444510CULL;
        aWandererA = 0xF1EB9E0D70620C88ULL;
        aWandererB = 0xF43E735D6C306306ULL;
        aWandererC = 0xAAD766FE7A54D42BULL;
        aWandererD = 0xB874261CB96083B3ULL;
        aWandererE = 0xA52D4815CF0E000CULL;
        aWandererF = 0x9B3BF3608F73362BULL;
        aWandererG = 0xDE7E9C6E64851129ULL;
        aWandererH = 0xCCC0D93308727181ULL;
        aWandererI = 0xC4B6C33F11A276F8ULL;
        aWandererJ = 0xEEE32D25D0C7CF8AULL;
        aWandererK = 0xAE7D244FEA66287EULL;
    TwistExpander_Miram_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBF6490BFC9C5D957ULL; std::uint64_t aIngress = 0xC96F17719C66E7E1ULL; std::uint64_t aCarry = 0x96F649C39CF1DF5BULL;

    std::uint64_t aWandererA = 0xBAD1747EDB01AE9BULL; std::uint64_t aWandererB = 0xF8AC87892F3D64A9ULL; std::uint64_t aWandererC = 0x84D1A4DE66FCF2C8ULL; std::uint64_t aWandererD = 0xC91C8E5D8EE8A768ULL;
    std::uint64_t aWandererE = 0xD79783155B2CA798ULL; std::uint64_t aWandererF = 0xE6064F099BEC215FULL; std::uint64_t aWandererG = 0xB5BD398BD8D6594BULL; std::uint64_t aWandererH = 0x96073EB0E9A63488ULL;
    std::uint64_t aWandererI = 0xBCAFAB76001A8BCCULL; std::uint64_t aWandererJ = 0x9862E43599A6C1D1ULL; std::uint64_t aWandererK = 0xA2FC831EF5D061E3ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFA7D0D2AA5792DF7ULL;
        aCarry = 0xC1DB9F577A033609ULL;
        aWandererA = 0x98D0836E3C9B3792ULL;
        aWandererB = 0xC0BA7B2D0E0D8B48ULL;
        aWandererC = 0xCF91204FA3028257ULL;
        aWandererD = 0xF26B7D826B0369FCULL;
        aWandererE = 0x8B802C4293C5AA71ULL;
        aWandererF = 0xA28D4126E7ACA06DULL;
        aWandererG = 0x9D59FEDB651B352AULL;
        aWandererH = 0x90CCB737FA3E364FULL;
        aWandererI = 0xE86C45EA53CD14E3ULL;
        aWandererJ = 0xA1367D840A46A295ULL;
        aWandererK = 0xBAE4907A51B26EA2ULL;
    TwistExpander_Miram_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA3037E34C07D2BDCULL; std::uint64_t aIngress = 0xF0398C884C110828ULL; std::uint64_t aCarry = 0xB00B80FB792BBBCEULL;

    std::uint64_t aWandererA = 0xA768EA57EEBA4140ULL; std::uint64_t aWandererB = 0x8D2AA24FD2D832B7ULL; std::uint64_t aWandererC = 0x883D65EF4857788FULL; std::uint64_t aWandererD = 0xBD6105ADA47A669CULL;
    std::uint64_t aWandererE = 0x8C0C35F8D715540FULL; std::uint64_t aWandererF = 0xB4EF5172CA6820B2ULL; std::uint64_t aWandererG = 0x9EE94F0F4F0B4172ULL; std::uint64_t aWandererH = 0xBED53E7F732CDD9AULL;
    std::uint64_t aWandererI = 0xA47FC0C2132051C1ULL; std::uint64_t aWandererJ = 0xCB6E2348438BC614ULL; std::uint64_t aWandererK = 0x8B72EDCFAA77BF91ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE6930E292DDA2020ULL;
        aCarry = 0xEA031EDA8F6027FAULL;
        aWandererA = 0xE903016B03369FC1ULL;
        aWandererB = 0xBA077A743914CDA6ULL;
        aWandererC = 0xA8C38D1256C98A02ULL;
        aWandererD = 0xEF2B66B159B20A0AULL;
        aWandererE = 0xE2A0563DA02E2E15ULL;
        aWandererF = 0xD716C56ADE3C3E7FULL;
        aWandererG = 0xAEBEF6CFD357B0F7ULL;
        aWandererH = 0x88F7E8179D1C11FEULL;
        aWandererI = 0xCBF4B6BA2E762951ULL;
        aWandererJ = 0x8EB77AB27FCC494CULL;
        aWandererK = 0xB12A41B1B563E7CFULL;
    TwistExpander_Miram_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE2AB21C850F44820ULL; std::uint64_t aIngress = 0xC6D0C417D5A7EEB6ULL; std::uint64_t aCarry = 0xE53747C25E60814FULL;

    std::uint64_t aWandererA = 0xA641557DEC49B848ULL; std::uint64_t aWandererB = 0xA6F155900D1870C0ULL; std::uint64_t aWandererC = 0xB9CB29AAB500B862ULL; std::uint64_t aWandererD = 0xB2AD46713728AAD5ULL;
    std::uint64_t aWandererE = 0x930079A5F172290DULL; std::uint64_t aWandererF = 0x83C9EB9D7D844801ULL; std::uint64_t aWandererG = 0x9F5C8510C12FCC43ULL; std::uint64_t aWandererH = 0xC276A27C5B6D4C0EULL;
    std::uint64_t aWandererI = 0xADFC8541ED36342AULL; std::uint64_t aWandererJ = 0x9BBED31F6637BA10ULL; std::uint64_t aWandererK = 0xBF167B89DFEC4C01ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCD75EA60511717F8ULL;
        aCarry = 0xAD08FF289A577239ULL;
        aWandererA = 0xA5F4395D6E2F801FULL;
        aWandererB = 0xB19BA204DFD91BACULL;
        aWandererC = 0xA777E856754831F1ULL;
        aWandererD = 0x96BBA252348AA840ULL;
        aWandererE = 0xD59ECBD20698D234ULL;
        aWandererF = 0xA44518AEB76001BDULL;
        aWandererG = 0xAA61D3A2A5D7BA2EULL;
        aWandererH = 0xA57FCFEBEB1AEC5BULL;
        aWandererI = 0xFDDCF4E6BA84520BULL;
        aWandererJ = 0xA7456151B2FBA2BFULL;
        aWandererK = 0xD36FDBC8AC1FD806ULL;
    TwistExpander_Miram_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Miram::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA9BF9B4873CEE00FULL;
    std::uint64_t aIngress = 0xC3956759F023647BULL;
    std::uint64_t aCarry = 0xDCF35A479C72DD0AULL;

    std::uint64_t aWandererA = 0xB90C43D888A65D2BULL;
    std::uint64_t aWandererB = 0xB020494A7C7CEB26ULL;
    std::uint64_t aWandererC = 0xF184D1368E460737ULL;
    std::uint64_t aWandererD = 0xA99A3987FD25C9BDULL;
    std::uint64_t aWandererE = 0xADD6C8F8BC0F4584ULL;
    std::uint64_t aWandererF = 0xCD5246BAE870F0E4ULL;
    std::uint64_t aWandererG = 0xD7D3EAC5B4E1CBF9ULL;
    std::uint64_t aWandererH = 0xE81A6C675BA4EF3BULL;
    std::uint64_t aWandererI = 0xB12D789261E9FF62ULL;
    std::uint64_t aWandererJ = 0xBB894F03B149DE74ULL;
    std::uint64_t aWandererK = 0x911898C87BA2E3CDULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    TwistExpander_Miram_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Miram_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Miram_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Miram_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Miram_Arx::KEY(pWorkSpace,
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

void TwistExpander_Miram::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEFAEF3A648BCB685ULL; std::uint64_t aIngress = 0x97C8D810235C4C6BULL; std::uint64_t aCarry = 0xC573A66A47CA29FCULL;

    std::uint64_t aWandererA = 0xFD02AAD848BF59F4ULL; std::uint64_t aWandererB = 0x8BDC818E4443A910ULL; std::uint64_t aWandererC = 0xC4B1F46D9558E0A3ULL; std::uint64_t aWandererD = 0x9548F9175CC55DFCULL;
    std::uint64_t aWandererE = 0xBC5B0756B7B5C563ULL; std::uint64_t aWandererF = 0xF3AF0A4939026A4DULL; std::uint64_t aWandererG = 0xD7C13AC1D8C7C199ULL; std::uint64_t aWandererH = 0xE8E6DC3A10955E87ULL;
    std::uint64_t aWandererI = 0xA0910A99D86FD391ULL; std::uint64_t aWandererJ = 0x8F0E656ABA525236ULL; std::uint64_t aWandererK = 0xB927A744B9CADBC1ULL;

    // [twist]
        aPrevious = 0xFD46A273FF2FDC5DULL;
        aCarry = 0x8B48A053D8C9DBC0ULL;
        aWandererA = 0xEDAE0688877153C3ULL;
        aWandererB = 0x87C246C9AA745BC8ULL;
        aWandererC = 0xE134ACCFD2168002ULL;
        aWandererD = 0xB536348061B5E314ULL;
        aWandererE = 0xEC05DAA99A8AF9B3ULL;
        aWandererF = 0x82D47F462F82E552ULL;
        aWandererG = 0xBFD472B57896F282ULL;
        aWandererH = 0xE271B8133D165EAAULL;
        aWandererI = 0x9312B9BA48A21B3FULL;
        aWandererJ = 0xC9D78C8ABCAE5C47ULL;
        aWandererK = 0x9D5B6F6AD8BD76E2ULL;
    TwistExpander_Miram_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Miram_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Miram::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Miram::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Miram::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 20 of 33
    // Exploration cases: 0
    // Structural maximin 514 / 674; family total 10198
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
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
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
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1780U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 20 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 10171
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1240U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 20 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1057 / 1248; total 20372
void TwistExpander_Miram::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
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
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1488U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
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

// FoldTwistControl candidate 20 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1053 / 1248; total 20441
void TwistExpander_Miram::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
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
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Miram::kKeyRotateSalts = {
    {
        {
            0x5242216C52AA38AFULL, 0xBFCEC0BE0149A758ULL, 0xC0F942046572BB81ULL, 0x519EC11CE200E5E3ULL, 
            0x115E83EEE4FC46ECULL, 0x08F3A659D6DB08A1ULL, 0x176A349F47C892E1ULL, 0x3254DC3D0B823B4FULL, 
            0x87D60008A897108DULL, 0x2FC72844A70F9ECBULL, 0x89003B00ADA3A4F7ULL, 0x1991AD5560427688ULL, 
            0x16B797FA321DDFFDULL, 0x63F84A90E393E639ULL, 0xA4FCC180515FD0D9ULL, 0x9AAD0881D67254DBULL, 
            0xE6A0A21DC7637DA4ULL, 0x7C03A0E98119EC76ULL, 0x297CF218C256A324ULL, 0x8D14D330CF063E11ULL, 
            0x25144BF1469477CCULL, 0xA64A75252160970FULL, 0xD58E39264A0DF931ULL, 0x9949B91C151F1610ULL, 
            0xDA98EFFAC24847CBULL, 0xDB6BE8027E240151ULL, 0xC2C6E425AD4B4F09ULL, 0xB28CC893F704FAF8ULL, 
            0x10257057B6664A45ULL, 0xD28F1A1933943FD1ULL, 0x0C2482E5BED057CAULL, 0xCA657ECDF3D17C64ULL
        },
        {
            0x8B114164A15F5C05ULL, 0x1F1D596C1CDBFABAULL, 0x4613A7CC9874E79BULL, 0x29AA25C07B4FD2B7ULL, 
            0x9E039855CE139C38ULL, 0xDAF19A80A074A367ULL, 0x020688C2B64CDB83ULL, 0x1912E516CA955143ULL, 
            0x4F54F6C66444F475ULL, 0x509826438C4A43FDULL, 0xEF5D01A4994AE036ULL, 0x07C6941A2FEB9553ULL, 
            0xEB8158BF7CBF7939ULL, 0x82235E2A27218FCBULL, 0xC1CA622FA4E32BE3ULL, 0x2A22B08C58FE8ACAULL, 
            0x7407544A8BC8554CULL, 0xB4C7C4D726526861ULL, 0x533656A0ABD84BFFULL, 0xB6AA98F4D92C029DULL, 
            0xE0668D561F81FCC7ULL, 0xBE40C4468EE7D9D7ULL, 0xC273E23BEC06AE7BULL, 0x6A4951C7F378588BULL, 
            0xB5BA19EE171F8FABULL, 0x1DCF0B8625FED555ULL, 0x65B83469EFC24AEDULL, 0x154E491DD696C9CBULL, 
            0x8C02366424986DFFULL, 0xA9581675290C890AULL, 0xDE21B65ED26B5A1DULL, 0xA95BDDD87BCBC936ULL
        },
        {
            0xF9AB79D739ED9605ULL, 0x58F94B137A3CC5F1ULL, 0x2F51FFC98862BA43ULL, 0x65107BF57E6BBDBCULL, 
            0xF6A0647C789DC35BULL, 0xCA66C5C331B14A7DULL, 0x635457862A329EA3ULL, 0x446CBF6468BEC0E5ULL, 
            0x9E8F746AC6A6E585ULL, 0x9EDF1ED7E028F7A2ULL, 0xBFE2A7A811A380D8ULL, 0xB461BD6D0AC755C2ULL, 
            0xB78C5E9DFE468CA7ULL, 0x34B078E1088A5B0FULL, 0xF627ECE4CA4B6706ULL, 0x90D30CA2E1043C15ULL, 
            0xE7BF77BAFEA38333ULL, 0x4572DF404904DA60ULL, 0x26964EDA5E4C3A51ULL, 0xDA2E55527B769101ULL, 
            0x44777C5B788EEA09ULL, 0x061DD15BD5B456E4ULL, 0x8E29CE9815192CD3ULL, 0x6E0AEB8B487833DBULL, 
            0x2A1937F2AE053A8AULL, 0x7753A8B8DD415278ULL, 0x44DA97778325D4D3ULL, 0x1C92D3E4A186051CULL, 
            0x9A5B629FF48583A5ULL, 0x307D5E780072DECBULL, 0xBC93CA5D934CD5CDULL, 0xAE55563139B9D2DBULL
        },
        {
            0x3D8741A98E2EBF27ULL, 0x4609E7CECCA49BC3ULL, 0xC85CDFC50021514CULL, 0x391BA5693D981FE3ULL, 
            0xA68A49A7E125B50FULL, 0x2D88FDDA7EF7CB38ULL, 0x662F4FE787EA230CULL, 0x99B6182F8E9DD604ULL, 
            0xFF73364BF0569C78ULL, 0xC2C41512C5F60F38ULL, 0xC3D3C843FEAC9FC0ULL, 0x5AF44E8A54EC2BFFULL, 
            0x62412C681DA98D6DULL, 0x384AA03A879E75CBULL, 0x2DD974D1CD8C4AEDULL, 0xFBBF5183D118A11EULL, 
            0xC77CA52D7CDE6055ULL, 0x21007B2AE4ED1207ULL, 0xAB03FCA173326530ULL, 0x3ABB3171A98F5D79ULL, 
            0x139661E79ADFBED1ULL, 0x71111BA0A4B752A0ULL, 0x6B0E99B606ECED07ULL, 0x71FA1D85EC7AD7B0ULL, 
            0x24BB35E06A8F8A94ULL, 0x2A6EEAE8B466B0C9ULL, 0x7AFA17393C634143ULL, 0xCA6D8539FDEDB8F7ULL, 
            0x2E4DE392C3C609EBULL, 0xCD16D37EF48EAD37ULL, 0x7185021E31282112ULL, 0x04E98398FEE12879ULL
        },
        {
            0x2B904D0F25B397D2ULL, 0xBBDAF1773B430276ULL, 0x859A98BFA0569F4AULL, 0x7B0A61EF5D91727EULL, 
            0x5BE4C1E6096FC461ULL, 0x21938170000F0B0FULL, 0x695AF1AEF291B579ULL, 0x87FCF542C9219069ULL, 
            0xFBCD674281FE651DULL, 0x60503FE87EC84AC2ULL, 0x8EAAB0E51C14EA3BULL, 0x7CFCDD3862512892ULL, 
            0x8AA8FFE6F8A7CAD3ULL, 0xF2995FEFDC026AB6ULL, 0x0615328B9F4F2EE5ULL, 0xAA6B1D25EA6AD797ULL, 
            0x8C6FF0827B9173ADULL, 0x6969DB4DE746B8F2ULL, 0xA33FB94CD36D9EE4ULL, 0xF4F0D8387C481D74ULL, 
            0xFCDD4F59F1828C95ULL, 0xBB1270218E895114ULL, 0xBD3B358B94653098ULL, 0x59DC6C296020731FULL, 
            0x3FD9C8A2E6B1F2AFULL, 0xD08ECF14530412DFULL, 0x3EC5ECA845D3ED6BULL, 0xE5610F310B0E8B50ULL, 
            0xB465160B5CE6852BULL, 0xCDA8806F02C2E895ULL, 0x5173DD47D6EAF3EFULL, 0x55CE155CC285A3FCULL
        },
        {
            0x501DDE7B7927FC58ULL, 0x2FD8857FDB5DC226ULL, 0x06B7B5782B003148ULL, 0x91A8139E491508D7ULL, 
            0xFB3D7CD5971F6FD6ULL, 0x480338016E327310ULL, 0x2540133B3E728F26ULL, 0xF8D09E75FD9D74EEULL, 
            0xD9A6BB561259735CULL, 0x5AB4684A9832B1D4ULL, 0x43C768C4DF1AD86CULL, 0x768CD537CE54A07BULL, 
            0xF74CC20E88CC1FDCULL, 0xD3375C365E9A9343ULL, 0x6DAF8055BECB255FULL, 0x37201D839C95A656ULL, 
            0x64E6AA01F2974CC2ULL, 0x04191EC4C9CAE0EEULL, 0xADE051E5DDBBF6D3ULL, 0x823E3BD5B8697B8AULL, 
            0x500679A8748AC232ULL, 0xC87CBA38C925DC44ULL, 0x4C27010274ED4301ULL, 0x46EE4BF6263CD432ULL, 
            0xDEA107CFAC2C47D2ULL, 0x0472DCDAC15D8EF0ULL, 0x1AE9640C06642057ULL, 0xEEACA901B5B02654ULL, 
            0x1CE4443D76E0EB9CULL, 0x03757B1B9C672DB6ULL, 0x5497B341C7B74395ULL, 0x8CACC22522ECB3D6ULL
        }
    },
    {
        {
            0xFB6177E42067A1FEULL, 0x93714D30C66013AAULL, 0xFB27B66604F03DE9ULL, 0xE66D8CBB194E42FEULL, 
            0xBD603CFF749E6473ULL, 0xCD820D98A942D51EULL, 0x0F5DCD7D5EF4EBF9ULL, 0xDECC5EA497BA5912ULL, 
            0x3FE80D92361D2E14ULL, 0x10642D72079516B1ULL, 0x564EA425462E658EULL, 0x7B4843721CE8B461ULL, 
            0x7F0386974ED51A7BULL, 0x7ACE89F84FB1F8F4ULL, 0x6B1A33FD216B47E9ULL, 0xCF2845FE6BE694A0ULL, 
            0xA4E47AD40C9F4C1FULL, 0xD8348D8CC4641FC1ULL, 0x4755632C976D72E7ULL, 0x40D72CA36913C3C9ULL, 
            0xA4772FC0A79BACC7ULL, 0x7ADA17788684FACFULL, 0x84C5256ACA726E3CULL, 0xF27C8ECCAF8B38B9ULL, 
            0x2642EF28D5FCBA5BULL, 0xC17269818B1C44C3ULL, 0x66401AFEE1F04EC2ULL, 0xB4033DC57700A8FBULL, 
            0x9DBC1AD7104B3328ULL, 0xB3472C3EC10A345CULL, 0x1EBAB05DC0917652ULL, 0xA788505E9D2DA349ULL
        },
        {
            0x3324AF42232D4FAFULL, 0xE785F8F2F011E911ULL, 0x609D995C6FB624A0ULL, 0x8E6BFEE8BC3FB797ULL, 
            0xDB39B44610776E7BULL, 0xA6CED9570351FCD5ULL, 0x022466EC597D6EA2ULL, 0xD15A17A948D227B8ULL, 
            0x63CCDBF5AD372A5CULL, 0x36C6F242D318EC0BULL, 0xB5AF717B35AC4D76ULL, 0xEB12C4FEB6A7259DULL, 
            0xB73D9D175FF8BE55ULL, 0x087011EC64F623A6ULL, 0x332585B3DFCC411BULL, 0xBD9107AD94865672ULL, 
            0xEEF7F4F569CBD5F5ULL, 0x9AEE1E868B9C6C42ULL, 0x0866CA1B1C72733AULL, 0xDCF311AA51023F15ULL, 
            0x66E8E52E5EAF8A67ULL, 0xE971EE429DFF294BULL, 0xE08A8A932071BB4DULL, 0x8243A9629057A2C5ULL, 
            0x58C7DAE1533EC39AULL, 0x6ED0A22FBF7AE8F7ULL, 0x35297ADBC6F8A853ULL, 0x4952AFA2D967ADF6ULL, 
            0xFADB0E188D1D51D4ULL, 0x03165AEC72C95F49ULL, 0x1F410E4C37C2C56AULL, 0xDB73388CCB6416D6ULL
        },
        {
            0x54AD18AE46401322ULL, 0x91D8D07CBC241CC5ULL, 0x88932670457A3114ULL, 0x035AC08D8729BBC6ULL, 
            0x4181696237AEE2FCULL, 0x9C5F71E904524C8DULL, 0x38711D5A877BC420ULL, 0xAF7FEAEEB1939DE8ULL, 
            0x9CB5CECB46A9827DULL, 0x7986A8F6B325C0C6ULL, 0xEE101CEBA3658792ULL, 0x3362C55A9D25F5A0ULL, 
            0x36126B724FFCBE04ULL, 0xFDF1DEEFE14B29BFULL, 0xE1A1A31C04C3102EULL, 0x2440830065B5DFF0ULL, 
            0x32A3B0663C0F40BBULL, 0x64918824DDA055FCULL, 0xC579F016B495BDFBULL, 0x45E168408627E33CULL, 
            0x6CDADC9420F8F149ULL, 0x162FED83A816A288ULL, 0x34F5171FEF1DEF7AULL, 0x77C2D6BE83DCFCE8ULL, 
            0xFE80C61BEC98EE7AULL, 0x7EC25608207A9C6AULL, 0x96B33CF3468C4470ULL, 0x6046AB60CC41CA9FULL, 
            0x77078CA35085AAF6ULL, 0x8A2426444D5B2D42ULL, 0xE435CC69D312F23DULL, 0x9FE0FCC29706C33DULL
        },
        {
            0x7099570B83151707ULL, 0x6F31BC10DED14A2AULL, 0x637320BACDF7ECB6ULL, 0xE85B3B54B2C6DF06ULL, 
            0x31E05A1D99386B3EULL, 0x99F1C8ABC0CE217AULL, 0xD5C54EB7BD85029DULL, 0x90341A72E0770929ULL, 
            0xA2B3E8A383C942DBULL, 0x8B79524523C43D02ULL, 0xA0D14F81AC239FBEULL, 0x3A304A11B7859E0EULL, 
            0x1C8BCC450A95B49CULL, 0xA01C90AD22FA0CABULL, 0x2367CFECF3FDBC30ULL, 0xF6AF8B1AFA029E7CULL, 
            0x0DBFEB0B56213349ULL, 0x0E0DAE070058D07CULL, 0xD35BDE82849ED52FULL, 0x345E9B8D75A0432EULL, 
            0x20A32AEEEE5EF32FULL, 0xA8D9D1E3B523ED2BULL, 0x0FAEB8AD7852B15FULL, 0xE09871C060614D66ULL, 
            0xF500F7FFEB79F73AULL, 0x79DCA1AA4B125D19ULL, 0xC8AEEADF50156F48ULL, 0x21572A5D8BA3158CULL, 
            0xCC8E801DDC78AFF3ULL, 0xE993C49F22D766C0ULL, 0x1E95584C7F06D1DCULL, 0x52229562F84C191FULL
        },
        {
            0xE28F0ED547188F8AULL, 0x4E25BB304EE04AA7ULL, 0xFF50D3D668D13BA7ULL, 0x891E80C0C56018FBULL, 
            0x18EA263DF532625BULL, 0x92B567EC092F9EC4ULL, 0xD74EC9D39036D31DULL, 0xA5D86F94AE84F94AULL, 
            0x9D2EF4E3119C1470ULL, 0x17C763A105CD7657ULL, 0x9937D657FD9973AAULL, 0x1C9088116470A3D9ULL, 
            0x3446CD5247CC9A45ULL, 0xFB237378CFD707DCULL, 0x045C4E443945E263ULL, 0xDA3D6A1166AE39B5ULL, 
            0x09541B52F5FCAA03ULL, 0xBBC4C77252676E08ULL, 0xB2F98E308DDD2C4DULL, 0x88164DA22352F453ULL, 
            0xBE876E1270DF9C9AULL, 0x8507FA1DBCE4B56CULL, 0x9C9DFDE514723E37ULL, 0x1095E62A23420EA2ULL, 
            0x47D9C2EA967C9159ULL, 0x24456E978C10EB65ULL, 0xE487FA5C9C39E15DULL, 0xCE5C29A49521374EULL, 
            0x4D2CBBD17A7A1D98ULL, 0x5688DC7744CE3C31ULL, 0x125D4543E73DDB1FULL, 0x74AD20DE05950798ULL
        },
        {
            0xD808A5419357A3BCULL, 0x4723354A7980164EULL, 0xF64B1E4C79880BA5ULL, 0xB6C4D3B56C24ACEAULL, 
            0xE7E3A8892D59033BULL, 0xEC54C6AEA63B6325ULL, 0xE228429FF56B3F2DULL, 0x6D9F2CDBD50D53A3ULL, 
            0x5C74971327377B01ULL, 0xFF82D670FAE905F5ULL, 0xDF2A4A705618FA50ULL, 0x3CDE82024F65F4FCULL, 
            0x1AA3D777359AAE94ULL, 0x9BBADD93C3A127A4ULL, 0xEA0B5FDCAC1970F9ULL, 0xBBB059A703EC761EULL, 
            0x839DF0787AEEBFADULL, 0xAF27D84A105D3BC9ULL, 0x6EEC18550787A5AEULL, 0x9A9399FE2B096FAEULL, 
            0x03E1D0FBA853AF71ULL, 0x418BA2842ACAFAF9ULL, 0xF3BE0BFF80F3AC11ULL, 0xD93407017BB7847DULL, 
            0x9796880D82C2FF43ULL, 0x273C5768A4E95CADULL, 0x310C50BCCC15C365ULL, 0x8EBF34A0E7DEEC60ULL, 
            0x28CC94D4C47AC83EULL, 0x52B3BD117F13BC2DULL, 0x53291C49F8813F83ULL, 0x901965B8BFA8DD87ULL
        }
    },
    {
        {
            0xC8DED31567C348CDULL, 0xDD7F578F8BDF1FCAULL, 0xA60FF5FD30106BABULL, 0xDA3CE0FDCC20B115ULL, 
            0x0AFC8AACA86A3DDEULL, 0xFAE6EB7C04AD23ECULL, 0xEE1E9D543462F335ULL, 0x376EB2D2BA3EBC4AULL, 
            0x2D05FF8A5F4142D8ULL, 0xBBDDB6C9AC842826ULL, 0x60A3E92F1C9F7624ULL, 0x044AF87472CE3BB8ULL, 
            0xAE0F7D96CD063902ULL, 0x680D7BE858A81B49ULL, 0x15A5DDBAC6920817ULL, 0xA438473BB5BD98D8ULL, 
            0x3C03A4384B2D2311ULL, 0x469690080B828F18ULL, 0x38C763A32FA37D8DULL, 0x9E4316972F47BB7CULL, 
            0xB058EE14347683F3ULL, 0x281970879D846992ULL, 0xB9ECAC6140944C12ULL, 0xB2B117461F477FACULL, 
            0x24F81AAB6F839192ULL, 0xFEB98BD5126EF2A9ULL, 0x7592BE8654586322ULL, 0xF6387725DBC687C5ULL, 
            0x73F25597B53B7068ULL, 0xED8F2DF37689D644ULL, 0x59C838D4F3270B96ULL, 0x4E1E7603BFF86145ULL
        },
        {
            0x11CE2183F0CED2A7ULL, 0xA3577141FB3AC750ULL, 0x1DC4012967605DC8ULL, 0x9A519826079F411BULL, 
            0x578C78C29AE80A85ULL, 0xCA2B5558F318B37DULL, 0x3C6F50E6EA036FD4ULL, 0xAEE3EDEA2D857EEBULL, 
            0x756EB40399763E71ULL, 0xAD9DF001500EA20AULL, 0xE10D4E314731828AULL, 0x0640B39073554E7BULL, 
            0x427D955EC46802D3ULL, 0xF5B68FA365A2F884ULL, 0x93432327C9ACB76AULL, 0xA4B8FAA8011C7574ULL, 
            0x460ED2D72F47DA71ULL, 0x3895F0C2B7A4007AULL, 0x393D1946063C45DBULL, 0xE26894D1C0D700D9ULL, 
            0x6540F912B48E7B77ULL, 0xA3E30C40EAF101A9ULL, 0xBF5C034B6F66E569ULL, 0xEE3473D69D0836B7ULL, 
            0x9CE406FE46B016D8ULL, 0x6434D2F525ED733CULL, 0xB55772EE74D813E0ULL, 0x430F01F5AC06CC8FULL, 
            0x1290F9ED499433FEULL, 0x7B96D76F3B89BF15ULL, 0x64CA98034E6E5296ULL, 0x3A88AFF7BBC4D543ULL
        },
        {
            0xEE114D5BBC3EF551ULL, 0x7C323D08954C39FFULL, 0xCD1E7EC9D612FE9CULL, 0x49B7083C34FC40F9ULL, 
            0x151334E69E79D74BULL, 0xA284F6CF4CE134E7ULL, 0x75680AA0007AAB62ULL, 0xA2FB75EFFD434CA1ULL, 
            0xB8E70AF7DAEEC5B3ULL, 0x3DAB28AB9998D445ULL, 0x907DB2DCFD7D7386ULL, 0xC5959E75C02BB9C1ULL, 
            0x2CB140DEBA9BE2A7ULL, 0xB066D9F567BE9424ULL, 0xFBFD9CB85A3B1793ULL, 0xD50556EA6978FF89ULL, 
            0xC6C3170357FB537EULL, 0xE3B41CE122C7DB8FULL, 0x01361E9E47A604B6ULL, 0x261F9467C21BA491ULL, 
            0x4AEF674090A64174ULL, 0xE0AF7BA562371AA5ULL, 0x39F6DB6B1588C4A3ULL, 0x4AF84DB1FD1F59B9ULL, 
            0x062ABC4A4348CD59ULL, 0xBFED5805155E6BACULL, 0xC2E9AA26DA40DCD5ULL, 0xF303AF466544E785ULL, 
            0x41D6C015CD852394ULL, 0x170ED146186481D2ULL, 0x62D6E09D33D71ADEULL, 0x5703FFC3C8FDC7DAULL
        },
        {
            0x084C0DA03AEC634DULL, 0xA945AE8FDDE55AEAULL, 0x3C3EAA7D60AF1940ULL, 0x14A9EE36BB145606ULL, 
            0x6BDC4BCEE2D4E4BEULL, 0xF4049458CD14CE7AULL, 0xBD82F1CCE920B444ULL, 0xC2D90752DF6466B4ULL, 
            0x10E1FF7079393B85ULL, 0x2BE218F0E79B9175ULL, 0x7D342686F2C94A0BULL, 0xD6B4CA74A7391321ULL, 
            0xF937FDFD6566D153ULL, 0x853C87C18F95A409ULL, 0x50E5ACCA98D6FBCCULL, 0x5E3671301D4D4BB6ULL, 
            0x783EBEEE3F66CA55ULL, 0x16483CD725D2EEEDULL, 0x9854A176C7D7F3C9ULL, 0xC28FB1CA7EF44641ULL, 
            0x1CBE260BFC4E9A8AULL, 0x62A7751EE3409C46ULL, 0xE28F2150ED771129ULL, 0x2A48B53DD8A41B2BULL, 
            0x127883B58AB7790FULL, 0xF5A5AB39DC90BBDCULL, 0xDE86620296C086D6ULL, 0x22816FFC41CC9981ULL, 
            0x2D090D6A82C86939ULL, 0xBBDFB29B07BA5747ULL, 0x21AB8B7676430856ULL, 0xF88B9FF5C883EF39ULL
        },
        {
            0x2175BA26628CA209ULL, 0xBCA9513837422E85ULL, 0x9A98DB08A9EAFEECULL, 0xEFD5157D6D74B6BCULL, 
            0x3D34D2F7CFBB0799ULL, 0x3E6C229EFF43F641ULL, 0x186DA2602625DB77ULL, 0xFF7C0DEF55F56F6DULL, 
            0xFDC3602178265733ULL, 0xD2381E2429ADC1DBULL, 0xB9E6F3706BBC25BFULL, 0xC090D9CFB2B7D3B2ULL, 
            0x25E2E388C6460CF9ULL, 0x5D76473D7528291EULL, 0x108A59A2E4983052ULL, 0xE54F1EA1E63E2D7FULL, 
            0xBFE185F51F1B80F6ULL, 0xC7FAFA50ECA2A4A3ULL, 0xD95B5352ECD49417ULL, 0x5892106788686C95ULL, 
            0x747E51613BE35A34ULL, 0x444B3B0E4A50DEE9ULL, 0x29CE41CD257303F7ULL, 0x8EA57D0AEB93B14FULL, 
            0xFFF4B023FF41AE0DULL, 0x5F6900E2410E6227ULL, 0x9BDBD4ABB47DEE20ULL, 0x8BE984464571387BULL, 
            0xDB14680E9ADC9970ULL, 0x7D645B2078E24B43ULL, 0x6CF70FAC0EE1778CULL, 0xF34362D9CC8975D3ULL
        },
        {
            0xED7B509B36122586ULL, 0x7ABC19C3AF79634FULL, 0x9E28EEE5D692381CULL, 0xD5545C3F8EDE2308ULL, 
            0x10D5CC7ED67927EBULL, 0xB9020AAE109AD980ULL, 0xE76B1A38D22FC4A1ULL, 0x82C3BF13639ED3EDULL, 
            0xBB5D223625CBD788ULL, 0xE8DB233A91206450ULL, 0xF5DB3526AC49CE5BULL, 0xA1A8A1BB7A745F47ULL, 
            0xAE82D3FFB378A7F9ULL, 0x252EBD2023E60EA1ULL, 0x4342596FF50D0610ULL, 0x616439006F812ADCULL, 
            0x594BF3A7A4A8B27BULL, 0xC118EDDF42C6346FULL, 0x55BF4F5CAA6EAB3DULL, 0x50BED0CF8EDA0C17ULL, 
            0x36B9731DC7EFCD61ULL, 0x26C5E7FD2882D8D1ULL, 0xBBF012B0C4B7CFE0ULL, 0x71CE08B2AEE7E860ULL, 
            0x3D1E6B710D721A7BULL, 0xC4402F6ABDB276C4ULL, 0xF4F5123351397AD2ULL, 0x9ED97C6727D56027ULL, 
            0xF46113F7CAB7BB2BULL, 0x1E81FACF09BC6EB0ULL, 0x9CA0782BBC3A14F2ULL, 0xC5370D1EEC25820BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeyRotateConstants = {
    0xBA7B096E1BDD13D9ULL,
    0xDAA006584B12F920ULL,
    0x324C8761128E0882ULL,
    0xBA7B096E1BDD13D9ULL,
    0xDAA006584B12F920ULL,
    0x324C8761128E0882ULL,
    0xB5BA1F7FEC3D3D53ULL,
    0x70C1C554ECF8F3F4ULL,
    0xAC,
    0x74,
    0x14,
    0xC8,
    0x21,
    0x80,
    0xBA,
    0x69
};

const TwistDomainSaltSet TwistExpander_Miram::kKeySpawnSalts = {
    {
        {
            0x16D1CE0914275C41ULL, 0xD6098F536D5127FFULL, 0xBA939B60336ACCCEULL, 0x02CF9F228F473900ULL, 
            0x6EE78FA45FE2C47AULL, 0xF2AAF734D93E409CULL, 0x425C78F1EF9491DCULL, 0x4A6C01385BA13DAFULL, 
            0x6C6841ABC1CCE4C2ULL, 0x5F4CFCB02BD7C87CULL, 0xA301E86FDE3943FAULL, 0x119BEE20A8BFB43AULL, 
            0xAB7E29F780183A6FULL, 0x703483118330F7DDULL, 0x1F52AB26047BFF63ULL, 0xA9374B1E084958DAULL, 
            0xEE6BFCB5E4AEA27AULL, 0x79A4DB7459A8E363ULL, 0x07E6FD13AD21363AULL, 0x88AB358F32F4B389ULL, 
            0x56105773265DF558ULL, 0x451F8F5DEAB02E07ULL, 0xFEAB06BDB2DA0D63ULL, 0xD4DBA3F5BF3217E7ULL, 
            0xC97AAE29C6172337ULL, 0x9051323FD5B85021ULL, 0x055A69ED58053A88ULL, 0xB4C1E511DBE05DA8ULL, 
            0xD9F79069EDB3E034ULL, 0xDC36FC67C8EB8194ULL, 0xE56E9620754A24FBULL, 0x9361807A036E96ADULL
        },
        {
            0x08F30E80EBDFB3D2ULL, 0x1A288C675DDBCA63ULL, 0x7F9EE63E34CC098BULL, 0xB1F5BD90866AE9A7ULL, 
            0xFBE8E79B3C811768ULL, 0x4B0A6F01F1BACD0AULL, 0xD9684B37B1C2B91AULL, 0x77C1E20B5EDBA4B9ULL, 
            0x57CB602AF4949D28ULL, 0xDA1DDDB6BDFA5523ULL, 0x1BBDC039778F9573ULL, 0x64E14C2E153121C3ULL, 
            0x5D784650A24A874EULL, 0xF54E55DEA0885AA7ULL, 0x8C1137CC612E0781ULL, 0x0C6DF0D5E8BF8161ULL, 
            0x0D7180F13DCAF391ULL, 0x022431CC5B3B278AULL, 0x8033A91994A250CDULL, 0x610264BA536C3D4FULL, 
            0x009A4628693346C0ULL, 0x9198529D7C93F786ULL, 0xF4077AEB15B97105ULL, 0xB03E89C24069451AULL, 
            0x627AD36D7FAEB03CULL, 0x74A1C56B1A9831D9ULL, 0x3C68D9E1994A1D05ULL, 0x4AC660689B0DE6F5ULL, 
            0x71818B4F7BFA91AAULL, 0xB5D4E180CAC55737ULL, 0x8EC4F616B7AA12E9ULL, 0x504CDEE8EACF0C32ULL
        },
        {
            0xD0CB8959B2959DA2ULL, 0x546D4D20C2D0CFF1ULL, 0xF28D204BFFAA91AFULL, 0x1DC38A4315073805ULL, 
            0x4B58C9CFFABDF784ULL, 0x51A3313CB4733790ULL, 0x8AC36396F637F0F2ULL, 0x12A5AED735F9035BULL, 
            0xC806D1264303959FULL, 0x6841D90581A7DDACULL, 0x5931C02A512774D3ULL, 0xCD1E16A1CCAF7C7FULL, 
            0xA91C5C3CE910C692ULL, 0xDEEE1B6B91BE30EAULL, 0x111C310FF2776B7CULL, 0x4E29243FE28A2F22ULL, 
            0x6FAF0D6A1C89EACDULL, 0x4493DD953D8A5AEAULL, 0x98BA678EC83FB238ULL, 0x58E3F641EFC23DF2ULL, 
            0xBF8FDE2B8659FC6DULL, 0x25D9EDD464EEF1F1ULL, 0x62C1213698FF77C6ULL, 0xBF1427ADD01AFA96ULL, 
            0x22D6EB89CB9E4BD1ULL, 0xC3E3227985C8E723ULL, 0x78DDD8DA40BC88EFULL, 0x5260CCB93C5198BCULL, 
            0x51A86EB48EC11093ULL, 0x3FA565B5E5E4946EULL, 0x58999E90E552EE96ULL, 0xBAECC9E815E19B1DULL
        },
        {
            0xB3E88B8FB102049DULL, 0x1D4CB13CCD08F400ULL, 0x7F2AA6EDB61E2026ULL, 0x3968BE0783B052C8ULL, 
            0x7B372398C5FBC97EULL, 0x63137696CE9AB523ULL, 0xDFE6A29C7D5301ACULL, 0xE4FE56727D4FB350ULL, 
            0xB9F6CAC1ECB37A4AULL, 0xF1BCCCEC3F9E5B1FULL, 0xF3AED36292EDBA98ULL, 0xE5247964B6846768ULL, 
            0x9DA4763D61AB18D3ULL, 0x7AA876B055C5743FULL, 0x2D99C6536B2D53D7ULL, 0xE05702435F9DCB88ULL, 
            0x98A61E251FB257F5ULL, 0x07AF28093CF05EF1ULL, 0x44F4BAC652E11C85ULL, 0xC0B06846C86D7A18ULL, 
            0x0B04A24C7902FB76ULL, 0xE67026AE06497EB6ULL, 0x33950A7AC7B1C03CULL, 0x7B9B9CD1110D5352ULL, 
            0xB38CDBDF91EC0DCEULL, 0xECED3848B84AF922ULL, 0xE77E543A852FC9F5ULL, 0xE1D51F574B91999EULL, 
            0xFA031736147A04B7ULL, 0xDE0F7F36667BED88ULL, 0xFC36588AF265F249ULL, 0x0660505898E5EA2CULL
        },
        {
            0xBE0DE4EA1BB40602ULL, 0x2ECFCF2F9D09B841ULL, 0x04E227F6685161B4ULL, 0x4599D6386562AAA7ULL, 
            0xA5CBE70C0BEA787EULL, 0x4D199FB6B683A1CBULL, 0xEDC2C8BF188D2108ULL, 0xC6783B43D1C7D958ULL, 
            0x6C1F0DCB116910E4ULL, 0x3761808C0686F36CULL, 0x31B2BD7B2FF93776ULL, 0x2FD727FF6957346DULL, 
            0x56E4A9A7F68549E0ULL, 0x6EA7CD937CCF1D2AULL, 0x9328580AB0A69FB3ULL, 0xA902CEA87E8F0114ULL, 
            0xF5265ECC7697B718ULL, 0xC4EF9B75A659A211ULL, 0x860234C42FE0360CULL, 0x6E5938C67E433468ULL, 
            0xBE4FC67E31F8C531ULL, 0x56446C8351F46B8EULL, 0x780D6B8EC9DD5999ULL, 0xB869D1799CDC92BAULL, 
            0x8B088C239535715BULL, 0x3239A174003B7BB1ULL, 0xA1E044D676F5C1CCULL, 0xB3BB2C41B1F192D1ULL, 
            0xB7E402C623EB94BFULL, 0xF85AD377262D1509ULL, 0x3554B232DF87E13CULL, 0x168C4F3A408A79A0ULL
        },
        {
            0x710173D93BFA67B0ULL, 0xE86C98D6B54F2221ULL, 0x36744966C1A5A92DULL, 0x4980EB3F28198FA4ULL, 
            0xB8B8B70FB2D78985ULL, 0xF49DC78135437EDAULL, 0xF232253527981DBBULL, 0x1A49D375A35A22FAULL, 
            0xFFD421723F77CFDDULL, 0x010A6408BB8C4A70ULL, 0x5A9E49F574CA8BB0ULL, 0xE40CC1913DEF7B94ULL, 
            0x271BE167F0073150ULL, 0x3404B58D053CAF72ULL, 0xE95979AB36A902E1ULL, 0x78C665B518C9FF79ULL, 
            0x0E91D6BEF14FAE92ULL, 0xF71E61D34B2AEF38ULL, 0x79B6489517C5ADF5ULL, 0xC8DE1ACF288C8734ULL, 
            0x09D587A2D3F22AE7ULL, 0xF4170AA7EE25B054ULL, 0x4CE5ECB545DDF20CULL, 0x1834665AEACE5437ULL, 
            0x6931E26ABBCF80C9ULL, 0x1B294942653EB1A5ULL, 0xEA64CA530259713DULL, 0x8974051034BF8195ULL, 
            0x4F31CD778127FE6BULL, 0xACB13BAC7086BE86ULL, 0xBD76F543429494A5ULL, 0x471CF00037615A41ULL
        }
    },
    {
        {
            0xF4F85043E31643ACULL, 0xC7A36C99A6332DC4ULL, 0xFAF718BB29FF551DULL, 0x99C943D5414F2248ULL, 
            0x9B9300AB82D0F4FFULL, 0xFFDFCF9E10F3A5B2ULL, 0x8D0EDEB788FF828DULL, 0xE1CE27396076A4A2ULL, 
            0x13D77CCE57C8ABCEULL, 0xE5E4173BFC621268ULL, 0x5AABBC980EBA87BCULL, 0xA1EA98454A4AD597ULL, 
            0x0A53F4DB7103232DULL, 0x675A31F4355F8B10ULL, 0x4B0D2539A57AAE94ULL, 0x0BA9AC3DA5D64CC9ULL, 
            0xBC8C1BDA7565B2B7ULL, 0xA705647CAF04CDD6ULL, 0xAD705E83EFEF67A0ULL, 0x7C5D37DB40914A5CULL, 
            0xDA5F7DD81040AAB1ULL, 0xFF40417530A34A04ULL, 0xECA4865F12842988ULL, 0xF718BC487FF1ADA7ULL, 
            0x2809F4603CF8DBCAULL, 0x3F85329A593DC1AFULL, 0xBBCD293D8B9C79FBULL, 0x9E4C27478011A0A3ULL, 
            0xB356515FB84380E0ULL, 0x5E68D2251AC8C719ULL, 0xE8955D98A3954D35ULL, 0x7207B3710FB3B1F5ULL
        },
        {
            0x638B52EA6C726D90ULL, 0x3C3713CC6683A3E3ULL, 0xC1E17E22F9B4E04DULL, 0x2FF7659A19B3E810ULL, 
            0x288202331C0EB676ULL, 0xEEC240EB06F2FA4DULL, 0xB86EABFFCF7D606EULL, 0x02CF449ECD5FC9DDULL, 
            0x709017C4B9885665ULL, 0x9DDB4BF009E9A03BULL, 0xD2F4B310589245D9ULL, 0xFE4EABBBA267BF0DULL, 
            0x50EAD98634FCB978ULL, 0x8032FA2AE2CAC5F8ULL, 0x548B9600E00C6738ULL, 0x6D0B65F0666879BFULL, 
            0x708A67E334C316B2ULL, 0x87541104379863FDULL, 0x9774EB0E514300ABULL, 0x85B469CB66563A28ULL, 
            0xEF5D167AFC1EE227ULL, 0x2AB0EEDBBBE1EB0EULL, 0x3DF6CC99457BEBF2ULL, 0x1AA9C18F2FDB4FD3ULL, 
            0x1502A2054EA7CBCAULL, 0xF03225E43381A75BULL, 0x666ACEC327493EEBULL, 0xA5658A978E3505CCULL, 
            0xA3386D7E2CF434CFULL, 0xAF6FD46B314EA871ULL, 0x1B3CD168FFA8E0A9ULL, 0x7AE28363C81060D6ULL
        },
        {
            0x925D2BC8DE96EB36ULL, 0x6318778D79E887DFULL, 0xF7343E6ADE7932E7ULL, 0x6A071D4808D032C4ULL, 
            0x1AB37E0B56A3F091ULL, 0x046B4E483654681CULL, 0xAEA1DC2E604D21DAULL, 0xCCA7DB2721FB33EFULL, 
            0xD8EB190FDF18FC98ULL, 0xC1ABBB7219E125D6ULL, 0x59F239A9ADDCDD71ULL, 0x7E568A540F09E6B3ULL, 
            0x203C4E0D929DA354ULL, 0x54C2DA0929003C74ULL, 0x4A71F2930F500EB7ULL, 0x9E5029F8A82D1F9EULL, 
            0x4E1097B90C222205ULL, 0x1AE80FFB4262F586ULL, 0xCDF90D582E400A71ULL, 0x6D2D60C91D023AC1ULL, 
            0x5222E74955B241BCULL, 0x15F60153E928485AULL, 0xBE73AB6FD6387A0CULL, 0x3563F1F211F6A4AEULL, 
            0x9A24C97E38F3D497ULL, 0xC0AF31F53E9B4FA3ULL, 0xBA04C675188AC370ULL, 0xB37D3591D7DDEC6CULL, 
            0x4957710572F5CC7DULL, 0x58B4E830CFE2A44FULL, 0xE3F2254478B383C2ULL, 0x1C151E7CEEACB77DULL
        },
        {
            0x2D34F4E9B1AAEC4EULL, 0xD8B957B79436A1E5ULL, 0x9FC15303A1AD334EULL, 0xBD5E17AE1F0EBCDCULL, 
            0x338C5873C20E9FEEULL, 0x44D3A019B566CCEBULL, 0x0ACA05E1628A4338ULL, 0xA393A35C09EFAE16ULL, 
            0xCE64C7505327A3A1ULL, 0xACA1CC6DB5A384B3ULL, 0xBBB5FD8268A2BF83ULL, 0x3E8D3071B375A93AULL, 
            0x38CBD53F03745C54ULL, 0x2ECAEB895A37B000ULL, 0x738DA575F7940CCDULL, 0xABBC4F340086E098ULL, 
            0x6E175883A15EF7CFULL, 0xA2016BF5773E2539ULL, 0x0558B8084C458523ULL, 0x0CA729AA48E9B4A7ULL, 
            0xC0F8AA083FF95121ULL, 0x6DDC8CC8543B9AA4ULL, 0x1AFC442435FA2092ULL, 0x3255EDB437B47FC3ULL, 
            0xAF0E2384546CCA43ULL, 0x1A4C0B5FAA702E85ULL, 0x2AB328CC9FFD7482ULL, 0xF28725DC5644FF83ULL, 
            0x8F8C207829A175BDULL, 0x4D00A24FD9D647BCULL, 0x331132642865E8ECULL, 0xC2883FC82E503C20ULL
        },
        {
            0xC31FFA7100E4047DULL, 0x63B40739C8148E12ULL, 0x6DA9D065636E8EEDULL, 0x9E864964758A7519ULL, 
            0xCDDF396EA80623A5ULL, 0x498971C84700AABAULL, 0x02C1C0D1C38EC507ULL, 0xE6D8E403B0809DB8ULL, 
            0xA14FE15D717F7315ULL, 0x9095A7F5308B7C22ULL, 0x66077EE590E23831ULL, 0x125FB73BCDCDF3C7ULL, 
            0x144D7C5E28CFC138ULL, 0xDA2FAD4117186B77ULL, 0xE277FEBCBCDD5C78ULL, 0xBB4B6CD7727AE422ULL, 
            0xE0890CD2380D2C15ULL, 0x0A7D104BD2F55BF1ULL, 0xACE87BADC36732CCULL, 0x3D0D1A0B5807D1A2ULL, 
            0xD34ECD6F402F8109ULL, 0x73654540CC9844B5ULL, 0x3BE9728FC455D493ULL, 0x8C0B23344E3189C6ULL, 
            0xC1B773D0046B3466ULL, 0xF91FA9C9365F3102ULL, 0x8482ED8DD1D44320ULL, 0x2FD6D6C5023E6A50ULL, 
            0xE8799A7E91DAE02AULL, 0x68976C42C1DB37D1ULL, 0xFF25618E227FD782ULL, 0x0CE97A57FAE8EC5BULL
        },
        {
            0x2123EB98BA81222AULL, 0x26CF66178B693857ULL, 0x554BCE5DD6ABECB3ULL, 0x11C395FF3F611DD9ULL, 
            0x04D518C026796D75ULL, 0x15102CC8831AA478ULL, 0x9EFB071A61B56F88ULL, 0x9B66A62182ED43E0ULL, 
            0xA353CAC845DC8C53ULL, 0xC739F07BBB7B72EAULL, 0x42C5FDDDC483DAEEULL, 0x92B2A79A0518D555ULL, 
            0x8879D98B882BEBE0ULL, 0x0EB767C4E5E263A4ULL, 0x639912EEF40D39FCULL, 0xCD2A63FFA23B75ABULL, 
            0xA265EEEFA6B8D727ULL, 0x988D1F9462273191ULL, 0xBDC62CB51BB505F0ULL, 0xB5EF172DF5353C5DULL, 
            0x2FE2C8EDA4E44315ULL, 0x8F625B9BDA6AF06FULL, 0x6D030DD13ADB2F2DULL, 0x8BB1776F228CE61EULL, 
            0x9794F5CCE7EA1AFCULL, 0x3A2B236800066B79ULL, 0x85E48BF5BB97F715ULL, 0x2213CC8CD709193EULL, 
            0xEFBF88E74AE43879ULL, 0x237829BDF65B293FULL, 0x78E5F1D0221F824EULL, 0x514116D2A941FDE8ULL
        }
    },
    {
        {
            0xDF02249242CF3232ULL, 0xFA8001FDEAD727EBULL, 0x3DB268D0627C2FA2ULL, 0x10F05BF6F13ECB10ULL, 
            0xE8D72A7B0F79C988ULL, 0xF895389879F04A8EULL, 0x6211CA4903692DB7ULL, 0x249134ABFF8A1445ULL, 
            0x25A666AFE819149AULL, 0x32F0D3792AE4EDA6ULL, 0xC52E15E3C79021A5ULL, 0x4658659C545369A2ULL, 
            0x2DAD57E89BA9C943ULL, 0x6A631E6F83707389ULL, 0xC0AA61CE555B1411ULL, 0xFD419DE502D7C75CULL, 
            0x08C27128AEC0876BULL, 0x897AA7E7926DE4E5ULL, 0xB2ADEBC51D70B93AULL, 0x220CA897FE412C6BULL, 
            0x0D2D977BFD416C25ULL, 0xC47921C5A1919363ULL, 0xAF188D577638DE30ULL, 0xA8F95613B6A32BD3ULL, 
            0x9C93D00B4931BA6CULL, 0x64EDB59540490224ULL, 0xF048E6E0EC0878AEULL, 0xBADF0C9B7BBA8757ULL, 
            0x536DDE6FC90EE141ULL, 0x93A242EC639B9160ULL, 0x14A83A3655B5C283ULL, 0xDBE5E001BBF56D82ULL
        },
        {
            0xB65EB45E2EF0C2E3ULL, 0x2168A3F89CBF10BDULL, 0x41DBCAD4649111B6ULL, 0xF19EBD38CF9DE357ULL, 
            0x635A3A7A3D06159FULL, 0xBEDBE69A0440A1CEULL, 0x17115894E088D970ULL, 0xF3AF3A4CF0EB914FULL, 
            0xA5BE916C3CA0AF9BULL, 0xA5F774B96B8EC7E6ULL, 0xD3DE3B185CFD4B05ULL, 0x578D9E904DEC3764ULL, 
            0x9DC8E9D0F34EDBF8ULL, 0xABC797B77C1DE7D1ULL, 0x53DF1614DA07967AULL, 0x08D0D9E4ACE82DBBULL, 
            0xCE06FBB21C797252ULL, 0x2BA1AB3D450F4A54ULL, 0xD21E62A40CC05ED4ULL, 0x8CE3A2FC45278BC5ULL, 
            0x966AF3BDDD5ABA29ULL, 0x6CE00CF71A4291CCULL, 0x19F616E2C60C5A0DULL, 0xEEA3CA85F078190AULL, 
            0x08C286AA183EEED6ULL, 0x61C2C91BCA4F310DULL, 0xC68DD46C74F3429EULL, 0x19EF6BB02613A744ULL, 
            0xF07C24849433E561ULL, 0xEDC37A683F3A2FE7ULL, 0x843F97172177475AULL, 0x7748AAC11EAA647DULL
        },
        {
            0x51BC8156E7DB6F18ULL, 0xCE617701C6409D7EULL, 0xE1AD24C116601AE4ULL, 0x1985EA5E7E4B6CFEULL, 
            0xD2A034D7E8293D74ULL, 0xE5B3DA0CCBA80643ULL, 0x00C11630DC312BDBULL, 0xACDB7254305A1B6DULL, 
            0xD6BCD64AC640DDBBULL, 0x72058CD68FBC0748ULL, 0x10E0BFCC260B5581ULL, 0x068484778A99D9D2ULL, 
            0x57339AC8C36847B0ULL, 0x8C2544EDAE23B209ULL, 0x90C0939F89177876ULL, 0x227DACB15AC8D920ULL, 
            0x8C2280F0466908F0ULL, 0xCDF7BA6F4CC4B24AULL, 0x08D53E548CDC39CCULL, 0xF2BB8972CC5BFFBAULL, 
            0x31A84E709050A4EDULL, 0x6C692E49D7FEA011ULL, 0xA568A87B935726A3ULL, 0x8750A9DA3421A528ULL, 
            0xA63CCD8BB9F18BBBULL, 0x43F816638E12E787ULL, 0x1A46FF96373009D2ULL, 0xBD9C3993F80110A5ULL, 
            0x2BA4B2E1D34BC396ULL, 0x9741B65527F675A0ULL, 0x0A7899C5DE6BB7EDULL, 0x441EA7EE7AA332E4ULL
        },
        {
            0x675D7E1474D007A4ULL, 0x3685C64D6CADE211ULL, 0x22399067D0A8E68FULL, 0x2A4A7E979927833BULL, 
            0x978366316A0FFBD6ULL, 0x12F2CAB802F773D8ULL, 0xF9588935A0AED290ULL, 0x49E80C63ADCFCA93ULL, 
            0xCCF7C1456F938EC1ULL, 0x3972A6E3C6AA1262ULL, 0xCDB9351B01DA7268ULL, 0x0795556AC27E3CAFULL, 
            0x39F2F61BFA06B081ULL, 0x7E303F3A3897129CULL, 0x8CBB684419C76170ULL, 0xB5FD535B01955B8FULL, 
            0x027FB67E137DAC2FULL, 0x7F51B9FC2A882E80ULL, 0x946E9228EF7892B0ULL, 0x976C13FDCB9ED8C3ULL, 
            0x2C4D0B8ADE427A16ULL, 0x8C696C1CDD144E7EULL, 0x421357788B4EC9C4ULL, 0x0ACD9C03705F2C50ULL, 
            0x447630D739A9AADBULL, 0x504A0C42DA71099CULL, 0x9ED2C0375F3002C7ULL, 0x9FAE3923AE2F65B9ULL, 
            0x0976E93032DC4DE0ULL, 0x8594982B9383F82AULL, 0xB49A74AFE8C27142ULL, 0xAE110F6C9579A036ULL
        },
        {
            0xF4F83F5D5D273ACAULL, 0x0D365049D5CE06E0ULL, 0xA19FB4E1D3378982ULL, 0x600088C3CB08D71AULL, 
            0x0A327A72942C46B9ULL, 0xAC11DFD7719F6104ULL, 0x71313A3547B1B539ULL, 0xEDDAEB421A6D643EULL, 
            0x17E979799C899ED8ULL, 0x78B78024A3DB77D6ULL, 0xE1CE21A8DE378FB2ULL, 0x1036F0B8180B4555ULL, 
            0x41DC9EF81ADD21C6ULL, 0x0D345D27A55D02F4ULL, 0x53228FEED670CB29ULL, 0x39BC588FDF232653ULL, 
            0xC730A1E090B434A7ULL, 0x62E88AA2D7F2164CULL, 0x0089728FD22B42A3ULL, 0x8C494F8FF33431E4ULL, 
            0x761CC8D0F04063C7ULL, 0x2451938DFA205BF8ULL, 0x9C456E8C0A4BCE68ULL, 0x49219096B0538CF9ULL, 
            0xF37DC30BDECCED9FULL, 0xD8C6FBD43C27D0F4ULL, 0xA3B6E29452AA1712ULL, 0xFD86528DF6A6DE08ULL, 
            0x96E74D4891FDD74AULL, 0x0C2A826359687F9DULL, 0x1699ACE01910844AULL, 0x6764BAE74EAE8913ULL
        },
        {
            0xA243B5A25734D588ULL, 0x5FB7CFDD5DB121DFULL, 0x57FBB3D860781A27ULL, 0xDEB27D6E6C612CEDULL, 
            0xA9F33BC6CEFBE0FAULL, 0xB819EDC473421BE1ULL, 0xFE9CC9FE112D7FE0ULL, 0x82E70EE67DD4BF12ULL, 
            0xFAEB00A15D866F5EULL, 0x0835A58F49B617A3ULL, 0xC6820F7DFCECF593ULL, 0xEA40313259D95C04ULL, 
            0x3D3BFFC7EB26F230ULL, 0xD97E231FA3A243E3ULL, 0xE350449224843C45ULL, 0xE3D1D0A351AEF07FULL, 
            0x8CA8F961F6D3A349ULL, 0x67A2584A0C3CA236ULL, 0xE3CDDC87256B863CULL, 0x649367D4DA4260D1ULL, 
            0xE59E483C0594E579ULL, 0xE187DF8C2D903248ULL, 0x82C213A76D225A93ULL, 0x60F037FA25B96DA2ULL, 
            0x0264ACD4861C5C06ULL, 0xAA9A5BE9E950B49FULL, 0x469DFF49F76D6F07ULL, 0xDFE661D24312C0FCULL, 
            0x0E42C25F2C41C4C6ULL, 0xF4988FF1E87E14C5ULL, 0x2C0AA34338D35B89ULL, 0x17400362D9F6D356ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeySpawnConstants = {
    0x46A6DF5550B3F51BULL,
    0x6924967BF18B095EULL,
    0x6A2DA232A7F33CDCULL,
    0x46A6DF5550B3F51BULL,
    0x6924967BF18B095EULL,
    0x6A2DA232A7F33CDCULL,
    0x2A104294D2D1252CULL,
    0xB5517E903471DF84ULL,
    0x8D,
    0x7B,
    0x13,
    0xA3,
    0x5F,
    0xB2,
    0xB5,
    0x82
};

const TwistDomainSaltSet TwistExpander_Miram::kSeedSalts = {
    {
        {
            0x9F249B7B72D88C96ULL, 0xCF1BF7798F991232ULL, 0x458CF3105C896D5AULL, 0xDB822713404B653BULL, 
            0x9D60FDA939FA1AF1ULL, 0x74F56968FE9DE511ULL, 0xAD7708474741D466ULL, 0xD0FCF9FFBA38BCFEULL, 
            0x40C88337166828E9ULL, 0x86D76D7DC7012059ULL, 0x3CAB81786BC16D93ULL, 0xD2B2C05E302BF0A2ULL, 
            0x9D9FB41F892B8621ULL, 0x744B9F1FF2503228ULL, 0xA528702081A381BFULL, 0x073B02BB4750160CULL, 
            0xEB54AFC0ECF93331ULL, 0x99CC995F543B822BULL, 0x220C769A69B084E3ULL, 0xD474D0453CDDBE77ULL, 
            0x613FFCF6A6871FFFULL, 0xE25C2651818CA6E5ULL, 0xBC9DEF0F9E868D99ULL, 0xB23DBED59B71B036ULL, 
            0xA768F6EC3F0BB553ULL, 0xA9778D92281A4F40ULL, 0x4A0875BE08E56C4BULL, 0xFCB9944F24406AD4ULL, 
            0x560E3CCC4B4BBEA4ULL, 0x1045AAEFF5742661ULL, 0xD13D11B48FDD8B01ULL, 0xD9BC73F9A69DCEDCULL
        },
        {
            0x68898B5D69E75977ULL, 0x5DF03486C39A8A2BULL, 0xF21DF7623CD2693CULL, 0x606A186AE071550DULL, 
            0xEF44D186CBB371F2ULL, 0xCC10DD8DFF80CE20ULL, 0x5B48BFEB78692AACULL, 0xCE7BD2586F764402ULL, 
            0xA41664846E3B0C1FULL, 0xD3103342A6805947ULL, 0xB9D641812BE15C9FULL, 0x39D8D44290BC9B29ULL, 
            0x80EC5DE21081EC5AULL, 0xFA605161540C9E22ULL, 0x35A2663516314932ULL, 0x95CF729BF21B09D2ULL, 
            0x821297FA6DEF2C03ULL, 0x65D7DC83CEF51221ULL, 0x8CBB50AB133783AAULL, 0xB841B84A2BD90B26ULL, 
            0xDB7DCEF1C5AC96F9ULL, 0xC90BCE840E186F7DULL, 0x6F1C2D5D1937B72DULL, 0x7BE7E9C7374E294CULL, 
            0xC357B69D0EDBB839ULL, 0x149562B185EEA2C7ULL, 0x380467EB417CBC95ULL, 0xAC241A7180171E6EULL, 
            0x42A9D076F27DC5BFULL, 0x14346B1B31CC271FULL, 0x43561471C4661957ULL, 0xF27EB9E4E28F0EF9ULL
        },
        {
            0x774BF367156392FDULL, 0x39DE88C2D461959DULL, 0xE24A8308A790249AULL, 0x3B7CB5FAB1646297ULL, 
            0x63E64D489399F4DEULL, 0xD68F17286EE33E4EULL, 0x800352D3F50FC858ULL, 0xBE4B51E703430B12ULL, 
            0xABA4477CB679FDAFULL, 0x3A6A65466B9AA781ULL, 0xFFD8B4EAB1D60C28ULL, 0x25C1DDDA06E431BAULL, 
            0x9EC18D2B7097A9DFULL, 0xF3703343C30C5707ULL, 0xB51CDF8B1442F76FULL, 0x88264B7C20B3A12CULL, 
            0xDCE3227F234DF4F7ULL, 0xEAAB111D1E4BA6C6ULL, 0xEE510717D66A75A5ULL, 0xC97FE2351AA3755FULL, 
            0x0FB853F0077EF2D2ULL, 0xF272D32A6A3D7FC2ULL, 0xF54375C83D173BE7ULL, 0x3E16B2E0A0726C68ULL, 
            0xB70E30B4F7EE6C80ULL, 0x9CE48966D01AA993ULL, 0xC629CA1C61E8869DULL, 0x64487DF335D00B86ULL, 
            0x631E0C003D6F596EULL, 0x4049C077D1AE422FULL, 0x126573B7244CA2C7ULL, 0xF6FD1FD5A68303FBULL
        },
        {
            0xC18B5E5550878D5FULL, 0x5A39E4ACE1DD9A91ULL, 0x0DA9A9CB29842C34ULL, 0x005EA6584AC1744CULL, 
            0xAD3A391851BE5DE4ULL, 0xAB11ED18B21BC764ULL, 0xE01EB0E1BD4C77C5ULL, 0xFFE7F9CEFBF72D96ULL, 
            0xC86E28A56F719631ULL, 0xAE7DFB57E4F98FCEULL, 0x238FD6A350EE493EULL, 0xEBCEBBB51819639DULL, 
            0xE3B030890A075F86ULL, 0x9E7FC07AD338AF14ULL, 0x3280F21511808C7CULL, 0xB85495B6219F288AULL, 
            0x3E05863E4749CD24ULL, 0x7F597E23BCB44354ULL, 0x0AE659ACA8E1B519ULL, 0x24879051C7F226FBULL, 
            0x0328AA9514DCC557ULL, 0x4996121E050F3CA6ULL, 0x00F3575167C43F61ULL, 0x1C290C2888BF3068ULL, 
            0x8ADFFDC8B3EC9927ULL, 0xE4B568BCB693C909ULL, 0xFA928A21E50046F0ULL, 0xA1BC4E707EC1270DULL, 
            0xDE7368305FA88160ULL, 0x0332875F11479970ULL, 0x5FAAA0E756459DA5ULL, 0xB950A358C28B1FD6ULL
        },
        {
            0xD2DDADAC550A6C37ULL, 0x878053DBE93265A7ULL, 0x6245727958EC2184ULL, 0x5C8F1D5B350BE127ULL, 
            0xFD92ECAD1CD5DAF1ULL, 0x75ADE535F942E738ULL, 0x08782A8799AA745AULL, 0xC1748B855C81EA67ULL, 
            0x56A35613CF99F896ULL, 0xED05624016CB1606ULL, 0x5F48A4A0C16A0D24ULL, 0xAE0A43B5C00082A6ULL, 
            0x51159EDF7B8BE34CULL, 0x60CFF59E3073A266ULL, 0x1B6C44730BDEF5DEULL, 0xF19BDBB84F6FC882ULL, 
            0x40B2647292A057DBULL, 0x17D9BE5C8DE344ABULL, 0x047B151D0F10C0B9ULL, 0x5094D28CF7DFF948ULL, 
            0xF36B8009C074B44AULL, 0x85302EE3C4AE7043ULL, 0x49A6B714ADAE1B3BULL, 0x2958B61415BE7CDBULL, 
            0x6FB2640502F0159DULL, 0xE80D61369F216991ULL, 0x6757D4AF9E7A3226ULL, 0x01EFB17EAD746AC4ULL, 
            0x58FB0CE5D1CBCE2BULL, 0xB8B128F5843F31ECULL, 0x656D65C1DEE786DDULL, 0xBEC6969B1576EA73ULL
        },
        {
            0x527EAA2C33A6B8CAULL, 0x69AE13A6B0FAAB8AULL, 0xC6F26B929319FD22ULL, 0x844C1DB7974458B8ULL, 
            0xD29B8EDF2EC18B01ULL, 0xF5CA7DE73F8CC5AEULL, 0x1D19D341BA973E57ULL, 0x70D42575BFDE382AULL, 
            0xC342F0AD804F4406ULL, 0x369C4C830E5C7D93ULL, 0x633F27FCB5730404ULL, 0x170F4785FFF513FBULL, 
            0xB70899C9841DE443ULL, 0xA34C93314CB64784ULL, 0x6FB8A08E7B33EEA0ULL, 0x1DF2045A6BE83B72ULL, 
            0xDA6643F0374CA3B9ULL, 0x62C472D50220EF24ULL, 0x5CD81AE682E17BB7ULL, 0xF84D438A6648CFF1ULL, 
            0xA4C7A5327CA02D5CULL, 0x697B53A14BA8CAB6ULL, 0x1263AD0AD59E4D0AULL, 0xC514BEBD69AD8C93ULL, 
            0x3DEAF8469350A509ULL, 0xC0743F5714052E8CULL, 0xB6030AB192EF8EB3ULL, 0x76ED0985A6DEE29CULL, 
            0x06E2CF56BB7F1EB1ULL, 0x1C30C213B12F19EBULL, 0xE8AE6B7521EB69FDULL, 0x27696B180A39B4EEULL
        }
    },
    {
        {
            0x1B7DDE27F892B309ULL, 0xD7DE33911DA9A00CULL, 0x4F715868DB31E30BULL, 0xC727C6DA6A121EE1ULL, 
            0x6AD8FD7371B965F7ULL, 0x617A48BAFBFA32C6ULL, 0x6E52EF3B0733CDABULL, 0x762536D818001552ULL, 
            0x6FCE52FC95C09E87ULL, 0x11FC06C16613EF55ULL, 0x48C9CA621245C3B5ULL, 0x44D09E85E8AA9FA0ULL, 
            0x842DB8104174ED92ULL, 0xD195A4E2B97FBFABULL, 0x6BFAC3351DCCA20BULL, 0xA1FFDF0C0391A3A0ULL, 
            0xA908F864F45856FFULL, 0x00D1EE6FE94471AAULL, 0xFC3BE3B6A26F9676ULL, 0x76072A2FFE247130ULL, 
            0x7BB74FDBE4C7BC62ULL, 0x9A9C178520FAF366ULL, 0x874A0A499DC059D3ULL, 0x6E824BCAA264E3C4ULL, 
            0x01C8D4D4102918DEULL, 0x1BC3AFFE187D08D1ULL, 0xED61BC90F7BC16B1ULL, 0xE37569EC6A26AAC5ULL, 
            0x63198A332FA785F3ULL, 0xB447189D3627DFE2ULL, 0x9C153CC846FC96C2ULL, 0xC016EF812783AF91ULL
        },
        {
            0x63B4486C998A4491ULL, 0x16CB5AEC4C0CA25FULL, 0x6B0902D52F01802DULL, 0xF7945696BC3F786DULL, 
            0x945FF3A8A7439A25ULL, 0xEF0E487EE790043EULL, 0xDBFB185F261729A5ULL, 0x754CCBFA2982F13DULL, 
            0x074749DE55DD5CB0ULL, 0x88BA478D43570204ULL, 0x70DFAB84EC94CA52ULL, 0x13DE5AF211722993ULL, 
            0x74C550B3D5638B5AULL, 0xE423433ADCC13324ULL, 0x537AAF07F7F8C155ULL, 0x117CF03BFAAB3194ULL, 
            0x811D429850418118ULL, 0x49973F8A6B05345DULL, 0x5D2C5144EF74D31DULL, 0xD40EDEE52A1FCF97ULL, 
            0x2175A96315F0E75FULL, 0xB9DA60B6957F2AC1ULL, 0xB83482E776FCCA03ULL, 0x1D2D2B8C80FB24D6ULL, 
            0xA84D38F06AE68FEBULL, 0x8245E0C53CE6F185ULL, 0xC7E2ECA3EE1A7125ULL, 0xA08F962A27F10749ULL, 
            0xD1AC6BAF5D00C359ULL, 0x60AE74910164E3B9ULL, 0xC3A252C09D626F89ULL, 0xDBD488AD43C0108EULL
        },
        {
            0xBB66BE5644244EC4ULL, 0xFAA09F0FF6E91659ULL, 0x617CE0555B4D43A3ULL, 0x7B8101DDBCD11833ULL, 
            0x14400FB4CD56462CULL, 0xEC01533BD3BB5370ULL, 0xC7225CDAC95B6416ULL, 0x8C03C19807FCE8DAULL, 
            0xC17A3FFA03CE8497ULL, 0x4A89224E765EDCFAULL, 0xAC62F09A7BC7EAD1ULL, 0xB3273FA2A67E9B66ULL, 
            0x7C6588F09F04E269ULL, 0x6FAD5AB9DF857C51ULL, 0x8DCF9428FA69AFBFULL, 0xB4B21433D55D35FCULL, 
            0xDFF01D45F66A4A41ULL, 0xED9AFD012C3A6E01ULL, 0x96C6ECAB1B4DA948ULL, 0x892B27E74CEE080EULL, 
            0x0D4C8B39F6B34E5DULL, 0x2E1C90BD81E7702BULL, 0x6DA7A938C1987EF1ULL, 0x2DD4F292D0AFEBBEULL, 
            0xCB636558087081C3ULL, 0x501ECBE5D3090279ULL, 0xDF127BD9E7C58B82ULL, 0xC137DD2A15C18969ULL, 
            0x340E31A941400A89ULL, 0x24CB0F7CC1A805F8ULL, 0x624AEA0518D0E955ULL, 0x2726A3BD82B453FBULL
        },
        {
            0x015882A35EB03425ULL, 0x04B79D04F2D0FA4BULL, 0x116B97A882969158ULL, 0xCA0F60DF90B64A19ULL, 
            0xAF8683BB90063159ULL, 0xD810003681565623ULL, 0xBBCC0864B1855DC3ULL, 0x6AB6305F5D6337B7ULL, 
            0x3B598A8B7847C83AULL, 0xB6E75C32E6B9F62FULL, 0xC0FC5F0FCBB2A55DULL, 0x044816B2DA507A3BULL, 
            0xFB75D291D360F89EULL, 0xFB34502283CCF06EULL, 0xEC86F5579EB4EA7FULL, 0x54845A4996CE4A3FULL, 
            0x68E69EEBA77D6797ULL, 0xED89C809B7EA879CULL, 0x1018B65EA9671FFDULL, 0xC739FA3F8AB8B47DULL, 
            0x0914330630C86CE1ULL, 0x1DCCBC2C9E8235C3ULL, 0x539DBF917473CC28ULL, 0xFB05FAF17F27CD4FULL, 
            0xFF6613225D2318AFULL, 0xAE88717270694D18ULL, 0x01F172F5FD353726ULL, 0x611F51AB20CDFEC8ULL, 
            0xD3C101F96CDF4C19ULL, 0x9C1023B783AAFD07ULL, 0x2F25B7E5660942B5ULL, 0x0E66DA71F11AE52EULL
        },
        {
            0xEBC1B1DE363211CDULL, 0x687F34ABFADF9390ULL, 0x6683264A023E8EB6ULL, 0x7F4DB151D592E6D6ULL, 
            0x8079794F90537261ULL, 0x79C19EDDA65A8372ULL, 0xA122FE542CDD2150ULL, 0xAA9A264A65965F0DULL, 
            0x42A71D0826D2C602ULL, 0x660AD7DE67E2FEEDULL, 0x23DB835951B9A366ULL, 0xB58C41BD2A513D18ULL, 
            0x52B5FA0C4AD3E0EFULL, 0x4682AB10233F8038ULL, 0x4A76AEBC1AD9C567ULL, 0x052FE3B7ECFF6046ULL, 
            0x22478B610B20F8F8ULL, 0x28CE891C4D2EA08BULL, 0x541CD240B5F49C1DULL, 0x417398650C045911ULL, 
            0x56C394DCAD7F568FULL, 0x8432DF5FCFA94987ULL, 0x76369F27842EEDD2ULL, 0xF5CA91E14AE381D8ULL, 
            0x4935FD2AD2A02B2FULL, 0xC822CC51D64CF589ULL, 0x38C386F92D859CF5ULL, 0x197430D96857DC4BULL, 
            0x315E8069E5597C3AULL, 0xC576BCACA03BB446ULL, 0x326804E1A3D79A74ULL, 0x977710CAE30EBCF3ULL
        },
        {
            0x36393EC002EBD297ULL, 0x29527E58432EE987ULL, 0x8274D57675B84E51ULL, 0x6E838763D848A7AAULL, 
            0x094468F62AE17D04ULL, 0x6D5BAE8637109AC8ULL, 0xBAA18746D77A9BF1ULL, 0xF62562005206F8A2ULL, 
            0x1F657277CC54C936ULL, 0xF521E66677520FB5ULL, 0x1D5129A348A7EA38ULL, 0xA63A1BD7DFC65107ULL, 
            0xACD9B38ADEA80709ULL, 0x0A271549BD78A6CBULL, 0x831F90CF987697B9ULL, 0x4C2890FD4ADEE7DFULL, 
            0x2296F6CE7DE469F4ULL, 0xA3635B656529C9C9ULL, 0xAEF0926042B13764ULL, 0x8874C4ABC2DA08E3ULL, 
            0x0FDDE41C072FB0BEULL, 0xCA5411BD74D7CCDCULL, 0x81CE319712FC8ED4ULL, 0x5AB73706AF32EB52ULL, 
            0x23697DD5E3A59EB9ULL, 0x17E38B3540A7C24EULL, 0x48FBF1DC600D90EAULL, 0xBE0A405B0BDB457FULL, 
            0x6C47BF18ABA12F78ULL, 0x7B7E42A39EB7D1C2ULL, 0x56F7CA5CE6A74D26ULL, 0x16E2DFA06F61888BULL
        }
    },
    {
        {
            0xA59D14DC693695F0ULL, 0x3C637F89BDEC74DBULL, 0xB1674C4E4CAD6777ULL, 0xD5570DA0DE6A8959ULL, 
            0xF4F2D498452AEA23ULL, 0xAE86D578CD7B5E5CULL, 0xB2472ADB14A6BCF8ULL, 0xF89FC2B0D6689DA0ULL, 
            0x4B2E4CF6147DB84FULL, 0x78B4E146C9028148ULL, 0x334095F451266D8BULL, 0xCCF5714925A5B53FULL, 
            0xCB9F347A2E7EAFEDULL, 0x94EC08682D9E3EDCULL, 0xFDA27D557677E338ULL, 0xF67361B1A5260C78ULL, 
            0x9A2E21525C80ED6BULL, 0x74E9705F709AB02BULL, 0x64F1A8985010C259ULL, 0x2ACCE6C90A5262F6ULL, 
            0xC1A1DB42CFE189A6ULL, 0x87EAD90E2A0D34C4ULL, 0x186C83E6468A9E30ULL, 0x7E8B91EDF13C6DA9ULL, 
            0x2CD8C706FB1FA274ULL, 0x032B79ED2BF99184ULL, 0x76D04B88109CE90FULL, 0x60DA9D9E40A7A770ULL, 
            0xC023B5946BF2A61EULL, 0x6A7EF59DB99C14EFULL, 0xB00C1167F173D6ADULL, 0x7D6FF6B196288410ULL
        },
        {
            0xAE04D7AFF3652D67ULL, 0xF9BB163C45795871ULL, 0xCFACF2D9A756CC5BULL, 0x99E08CCEEB545830ULL, 
            0xEDFDB096EA90886FULL, 0xAB58DA9616A4872EULL, 0x409BBE9F159034CDULL, 0xAA15833D058BE9BAULL, 
            0x8CDB36067947FB07ULL, 0x0C5F6CB296BEAC0CULL, 0xFFDC91C90314EDD0ULL, 0x270BE6A73AC1DAFDULL, 
            0x30C25228F9614F1DULL, 0xD82396691F8E488AULL, 0xFFCACC1013909F8AULL, 0xB18DA64FA95ACF42ULL, 
            0x13DF8BFDD00DA6F9ULL, 0xDE1584AE693EB4BCULL, 0x6F5D39C8835EAC2AULL, 0xCA16669056D1959AULL, 
            0xDE6546C882EE8561ULL, 0x21AB92CA506F0803ULL, 0xAF0B70A2B72409C8ULL, 0x20F9AF03566742F3ULL, 
            0xA8AC97293A59D8E5ULL, 0x3556F5AA543690F7ULL, 0x234E4F8CF55E5C91ULL, 0x1E360B69F2255C11ULL, 
            0xE6C67B154EE0AD9DULL, 0xF23ABADD964737D5ULL, 0x62AAECB637845C9AULL, 0x2813EE7D5F82287EULL
        },
        {
            0xCD7F822ADAC9B6D9ULL, 0xAC3E591AF666DDA7ULL, 0x4D1451936A63FDD4ULL, 0xDF6679A5190AA5CBULL, 
            0xF5BEE5E850CAB281ULL, 0x868B88FB257E5DB5ULL, 0x55F09FD5F1837BD0ULL, 0xA803F52C5EA58363ULL, 
            0x5AE1EC1264CC0B8DULL, 0x6F6659107FF4E8A5ULL, 0xEED6FFC08199E90EULL, 0xEC99CFE0627B894DULL, 
            0xE6D4E46E5C6153E5ULL, 0xE567C70DC3B70377ULL, 0x630C0ECF7F9DF635ULL, 0xFBC1D62FBC4B356CULL, 
            0x78EDE7107164790BULL, 0x9315B8F041AEB2BFULL, 0x45C4611EC018F03EULL, 0x56EA8C71FBB1462DULL, 
            0x847E6013DF08A8ECULL, 0x8B6705E66ED24119ULL, 0x251F682D77D5298EULL, 0xCC825486E16F6D88ULL, 
            0xB9AC8C4076DCC2CBULL, 0x4C3D9A97A53F3BE2ULL, 0x232C69495C78F223ULL, 0x6D2807C944ACD6B0ULL, 
            0x282A4ABE65A2EE7FULL, 0x3D9FB465A4BE6124ULL, 0x3E4089F8044695C1ULL, 0x87B49144C5394DA7ULL
        },
        {
            0xAD7887464CAAF21FULL, 0x1ECF16B0FFF608B8ULL, 0x0F1F5B0375C84572ULL, 0x025E075551FC69FEULL, 
            0x15F21D82E4AF19A2ULL, 0xB1BFE6A956F116D2ULL, 0x5FEF956F217A7A92ULL, 0xA1DC0FCED32CD9CCULL, 
            0x81F728A325F43B14ULL, 0x64B5F37F1D869CD5ULL, 0x408BE5331AB6FEB3ULL, 0x05005D41D4069BF1ULL, 
            0x4BDD429DA9BF09FEULL, 0x53C1611C5B221DE1ULL, 0x090B38436C709A81ULL, 0xA8AB10C7FF750810ULL, 
            0x745DB0F444C4604DULL, 0x59F8759498C1ADE4ULL, 0x9DB91468F871E3A0ULL, 0x433DF5A184749AE4ULL, 
            0xACF971004314928EULL, 0x1D71147827145567ULL, 0xE8AE398EB351A67FULL, 0x14EE9D3EF8BD0C2AULL, 
            0x90C235537E84E32FULL, 0xC92837A23B1F7F38ULL, 0x425814E633513720ULL, 0x9CFF2429FEEE964DULL, 
            0x8057AD71A0C3567CULL, 0x934E487E72C377C1ULL, 0xB70A7CE8A4B52075ULL, 0xAA0A1832B0781E68ULL
        },
        {
            0x118D5AB66D914935ULL, 0x531666FC16AF3E22ULL, 0x7B811C20BBBB538BULL, 0xA11CD2A6AE224CB4ULL, 
            0xB3BF0D05805B81D6ULL, 0x7BFD5D35BE254B09ULL, 0xAB678CF5061F71C8ULL, 0xDF1ED152A1699DC9ULL, 
            0x7B218212D25E4A5BULL, 0x5F8793365B6AB9BDULL, 0x0E54C24DE4F43550ULL, 0x954E41340A61134FULL, 
            0xDF185CF1F05EC373ULL, 0xAD6C8DB2A0364F10ULL, 0x33B39B00F8B05C6EULL, 0xC1D94BED4F95BAA8ULL, 
            0xADDBC1E2AB6EA075ULL, 0x93FD5EECFFAAB6F7ULL, 0xF38C36D140F82945ULL, 0xE8AFFF7D1C90E022ULL, 
            0xB1E8C8FFF468401CULL, 0xED5C408F6CBB5927ULL, 0x1CED3EFDAD962CCBULL, 0xD96D7E3CAF434511ULL, 
            0x898BD9A67C45AF7DULL, 0x82719A5C6FE6A258ULL, 0x8C6FF621D194F53CULL, 0xF59543E92BBA7AABULL, 
            0x479E57AD09810E4BULL, 0x2568174FE349AF8BULL, 0xA668EC3B84CDFD65ULL, 0x376CF2E614C705AAULL
        },
        {
            0xB888839AF851D62EULL, 0xD46198A25C3F1321ULL, 0x693F8BC26BC61D72ULL, 0x71BB74540BA39868ULL, 
            0x079944BDECAB0DD9ULL, 0xA80DDC0C0E61E1B2ULL, 0x6500E93F11648BD8ULL, 0x037302FEF84BA57BULL, 
            0xC9F8DB56A627727EULL, 0x6A8C4BDFA9E4B483ULL, 0xEE34367337464B19ULL, 0x6501D75236BA4306ULL, 
            0xE66AC7CED1602544ULL, 0x0914414E3655D252ULL, 0x1F7BCB27C6EF0082ULL, 0xCA29155910C48685ULL, 
            0x3F21E5F4428B52EFULL, 0x7417BA591374DD0DULL, 0xF9786E4408BA36A9ULL, 0xD7E4FAB34683AB20ULL, 
            0xA2A9E5CC6AA13C6FULL, 0x9B9D34A64A3C19C3ULL, 0xF0E27D36FABF1E46ULL, 0x660E928A5CB226C2ULL, 
            0xD96C9F1F5E7886F7ULL, 0xA6AE17FCC4EEB412ULL, 0x95FCC61849CC3722ULL, 0xC97A2862300B9CD3ULL, 
            0x27D00E91D0B53C93ULL, 0x1A473E535CECECA2ULL, 0x0CFDFD7B7A09EED5ULL, 0x4BA74B6A6CEC1A3EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kSeedConstants = {
    0xE260E0F5B54CD2AFULL,
    0xF68FC00B278B70E9ULL,
    0x0EDF65DE0C38C294ULL,
    0xE260E0F5B54CD2AFULL,
    0xF68FC00B278B70E9ULL,
    0x0EDF65DE0C38C294ULL,
    0x2E326F5E48ABC754ULL,
    0xE5868AA7B4A3E8B1ULL,
    0x28,
    0x53,
    0x07,
    0x23,
    0x93,
    0x03,
    0x8C,
    0x8A
};

const TwistDomainSaltSet TwistExpander_Miram::kTwistSalts = {
    {
        {
            0x592B935524EFAA34ULL, 0x6BC763FD2C3A1B50ULL, 0xD425C5CB04B97108ULL, 0x4F9FD1E6B8F6E079ULL, 
            0x854E4D44B94308A6ULL, 0xC54E57D880B62333ULL, 0x223BB4EDA14B70DDULL, 0x11A1D3E5DDF8D923ULL, 
            0xB8D374AC404A463BULL, 0x8CBC364B36F3F0B5ULL, 0x019EB7467989DA60ULL, 0xE2609AACB3C8E198ULL, 
            0xB205497B3F4ACB12ULL, 0x39039EBE1FDA076AULL, 0x9B276D06AD3BBE79ULL, 0x9DDB5A99ED795F5DULL, 
            0xA9EFC70177AC11E5ULL, 0xDA16B9818907AE39ULL, 0x12A692C97D76D7E5ULL, 0xAC2E8B6373C272E3ULL, 
            0x0231D40021F7D8C0ULL, 0x92A6606521FBE9C2ULL, 0x8D19C32850FF1AE0ULL, 0x9CBDD48C8C433B2FULL, 
            0x564C8C0F2AD06B43ULL, 0xF58163F5C93DD39EULL, 0xCB8B2861230E7276ULL, 0x994D615B8E62879CULL, 
            0xA4DEA0AF4E83C999ULL, 0xBEE10AF4818A9366ULL, 0x73BBA3EB2CA8C4CAULL, 0x27A62E7A45C7BB7DULL
        },
        {
            0x7331B772986660E0ULL, 0x648FA9B152E03C4FULL, 0x8B224C8E583A2AAFULL, 0x083625303D2460DCULL, 
            0x99F8FD00B1BF8443ULL, 0xE22EF5ECF1E914A3ULL, 0xD50D6D89583E005DULL, 0xF05893115899447EULL, 
            0xBF09F2BA75088131ULL, 0x3ED83D23B46B059EULL, 0x015C8BA0C95E0F75ULL, 0xA6E13011D5AC0115ULL, 
            0xC11A4412417721C4ULL, 0xF7CE6A2FBC73A89CULL, 0xD992E72C1982DA47ULL, 0xA40C4547F094ACABULL, 
            0x0993C59598B43A62ULL, 0x013363C5EB77D3E6ULL, 0x91DBE2F86926B813ULL, 0xFA32F8DDB2449CFFULL, 
            0xC7B266473F86E0F6ULL, 0x8A4F04DF2484972EULL, 0xC8FC1E90625D50E0ULL, 0xDEEDBB42CA5CCE8CULL, 
            0x63A3D03F8F2EA913ULL, 0xD8A32D587424A95BULL, 0x007E3227F12EE36CULL, 0x5D60171FAF23EC07ULL, 
            0x6A76368106414DC2ULL, 0xDBBB8DD1DF94B092ULL, 0x538A362F01C7BB7CULL, 0x765F0202378BB580ULL
        },
        {
            0xF693007A77AE4C69ULL, 0x703C678099A3DB8DULL, 0x1993E35E65925E28ULL, 0xEB41821E4E593DA0ULL, 
            0x857056A63CE3A14BULL, 0xA09AECD7B82C166AULL, 0x9DED8820BF4B45E7ULL, 0x195C166256C5323DULL, 
            0xCA57755909EE0D30ULL, 0xCE99A0707F9BA60CULL, 0xA889930F27D34922ULL, 0xCF9F33F866638825ULL, 
            0xEDA68507BFCB28C7ULL, 0x6F8A7250ADB5375FULL, 0xA6D8F20F819C669AULL, 0xD1E7E390CA996456ULL, 
            0x822AD167F93AC85BULL, 0x0F7F962A82A80C56ULL, 0x135D36A7ECA7120CULL, 0x13014D64603202DFULL, 
            0xBC585CD37B417ECBULL, 0xDEB6A3C9F89050B7ULL, 0xD521BB07F9FAE8C7ULL, 0x9421E869077C8538ULL, 
            0xF38AC2B8364C01A8ULL, 0x8A13C2D69EE92B3CULL, 0x8BCDC160804B701BULL, 0xDF5A575750987B1DULL, 
            0x15BABE7B5ED04679ULL, 0x24E3F51E9DA90832ULL, 0xE6F0E90E94AD84BBULL, 0x27E5C0C805FFB2AAULL
        },
        {
            0x1F00AC63FFFBAE64ULL, 0x8413B3D260C4EE25ULL, 0x4758C88E8928A5A8ULL, 0xCF5DF145FB9A1D28ULL, 
            0x16F2AFDAEE8DE541ULL, 0x91BB027F83D7316CULL, 0x76762E7E2F747DA6ULL, 0x06E80B82FDBF592FULL, 
            0x0AD08F6512895E24ULL, 0x19FA15C7A682CFC3ULL, 0x4ACE57A90899D912ULL, 0x45521FE3DD6E7892ULL, 
            0xED436E9FEA0FC61FULL, 0x3DB4F08F48F23C77ULL, 0xB5A028950AF5F339ULL, 0x52E1074529B24A7DULL, 
            0x8FB16ED847E6803BULL, 0xF0622FD4022755F7ULL, 0xDF70E03B4A4E9F09ULL, 0x49074F8229AC3B1EULL, 
            0x02F15A200741F30EULL, 0x75459CF7EDBDD80AULL, 0x40DD934E0CB0B312ULL, 0x4625C7F381E80747ULL, 
            0x890EF8C7A16F3DE0ULL, 0x0B193752597FC033ULL, 0x9E3785FD7AB53629ULL, 0x74592A28DEC181F6ULL, 
            0xD42BFC2AD0036E5CULL, 0xEB082AC80C22E508ULL, 0x21CF0F4DD4544320ULL, 0x2F605E295E667CB3ULL
        },
        {
            0xECF862A3C018EB5FULL, 0xC18CDD3F40587C6EULL, 0x389805320A6D03BBULL, 0x794DF89367B2C23EULL, 
            0x9BF6401F2834510DULL, 0xDF2F9BDF724224B3ULL, 0x7F0181A0F7C77BE4ULL, 0xA58D204E99CCE278ULL, 
            0xD120F720995ABAC9ULL, 0x43F0235B9E394332ULL, 0x4D42FF0FEEA9D804ULL, 0xFD5305ABF94DC584ULL, 
            0x9B6F2257886700EBULL, 0xB3345D527FD5F983ULL, 0xB2B708EF68D35A72ULL, 0x6F6C3F40CF8F1AD4ULL, 
            0xAF57E00CE6A71037ULL, 0x6E8BD225A1908E25ULL, 0x875063CC1009845BULL, 0x3F3AAD9E2F13B16FULL, 
            0xF2B10000A5FA8804ULL, 0xDDCA8519ED3D5C33ULL, 0x596C5915EEECE54FULL, 0x1A967E1A33440F3EULL, 
            0x96491EE610DEAD26ULL, 0x06E7F77181BEEB34ULL, 0x9374E12DA8EAEC88ULL, 0xB8067F14F9FB7D6BULL, 
            0x5B8B67AE0FF3BD78ULL, 0x579F98ED8889C390ULL, 0x2853B69C25508B0AULL, 0xC3B08C0A11F9FC46ULL
        },
        {
            0xA7DA245ED96A0B8DULL, 0xAE188EEA8B72EBBCULL, 0x764041249AB4105FULL, 0xECEB5B10A1B2825EULL, 
            0x5585A72634879728ULL, 0x805C9C2241E9980CULL, 0x2F8DFC764977D819ULL, 0xA11236F3D90F8D50ULL, 
            0xE652AAD3E7A966C4ULL, 0x474507C0C41B3D09ULL, 0xC80B1F8BF3D35310ULL, 0x489FC681A90E432AULL, 
            0xB7B7902849064C88ULL, 0xBC09CD3A2B5217FFULL, 0xBD6365B4019E3C62ULL, 0x62D53FE7094437E5ULL, 
            0xEA92557474C77900ULL, 0xEE580A34885D7F71ULL, 0xB4F537804BDD7ED7ULL, 0xC967B477B94D3D61ULL, 
            0xD6DE3F31403F6415ULL, 0x8AC2B24715664966ULL, 0x60EFF311FFD26AA2ULL, 0x1422E2F6B6D16083ULL, 
            0x55590E8D987BCED5ULL, 0x2AAFE3D880F8AB0EULL, 0x9C20314134D88F09ULL, 0x5FFC53AEFEE5CC36ULL, 
            0x8B28A606005CA944ULL, 0x84346D65080A6BEEULL, 0xA6AFADF790B1ADCBULL, 0x7A57A7B82135748FULL
        }
    },
    {
        {
            0x70CB2455606072F8ULL, 0x3C6575AB4CE1CBBDULL, 0x1F357BB7D5671F9FULL, 0x897D67C5B5DBB07BULL, 
            0x90774F8A2AFB5506ULL, 0x55D76DC4CD3A0CD0ULL, 0xD291237881184A28ULL, 0xB48D212A3251E919ULL, 
            0x31ABAE547FB24D53ULL, 0x5526E163EE79A111ULL, 0x5CFBA12A180195EDULL, 0x192FFB9BF3BFEA8EULL, 
            0x493558904F69F99CULL, 0x9624178993B474CDULL, 0xC95284FD41CF2270ULL, 0xC469C38979355B7CULL, 
            0xD9769578143D7E5BULL, 0x771B8D486CBD170CULL, 0x8147FCADF85E54BAULL, 0xDE565EC03AA77541ULL, 
            0x12CAF416F3D1416EULL, 0xDB72CCEB77133829ULL, 0x33B16225D6709672ULL, 0xC5ED1854B3185460ULL, 
            0xD519E966493E2771ULL, 0x7D37E1BFCCF105A1ULL, 0x2C15F463C0B79EA2ULL, 0xDB796733001F2A61ULL, 
            0x1AB77621362926DCULL, 0x50EE76AD6FF11AE5ULL, 0xCAF5807544B5FB34ULL, 0x85DCD8963411AD5DULL
        },
        {
            0x9AB3D21E4C1C0622ULL, 0xD3FAB4FB440D2E8FULL, 0x5CDF4EFFA9896631ULL, 0xE45F1CEC0C5B7B8EULL, 
            0x289C797D05D5D0DFULL, 0xB94F8EFF3960DCB6ULL, 0xAC774E1C1374DE2AULL, 0x45BF3D321EF4C419ULL, 
            0x445F6E2CC8ED1176ULL, 0xFD7A2B61246DB5B3ULL, 0x57F8D13BA6A67876ULL, 0x689EF1841ED57FC6ULL, 
            0x81CC49455311E296ULL, 0xE5349A99C5C693F6ULL, 0x3A589B15B669ABA4ULL, 0x5DEE87AE23D6E828ULL, 
            0x0750838C3ACFB0D9ULL, 0x7FFA0C0F20F19E7FULL, 0x1C0E71620F5AEC51ULL, 0xB26C589460BE95D1ULL, 
            0xF36AF6D6620E4BC6ULL, 0xC2D7EB7FCEF66303ULL, 0x5E02B106C78E0104ULL, 0xF6CAC9672F02EF33ULL, 
            0xB14FAD758F2D559DULL, 0x2BD39791858C19C3ULL, 0xA0A923047FDE9E29ULL, 0x016DBCE64BDED63CULL, 
            0x6227393AED1BA836ULL, 0xDED3E29341D12F36ULL, 0x621518C637CD3EA6ULL, 0x1B682A06D9F7BEA2ULL
        },
        {
            0x8C6FF93DCEDE90A5ULL, 0x055D4C9F1FB17696ULL, 0x7F54274506C78D53ULL, 0xCF150464D2974450ULL, 
            0x5211706B4FA803EFULL, 0x7CAFC01DA250F320ULL, 0xB2C0C8C4B6492CCCULL, 0x27983DAD21500974ULL, 
            0xDC306B6391465A06ULL, 0xA07746E01F2C6BECULL, 0xCD7BB2DB946CC6AEULL, 0x2CB9FF046E008DECULL, 
            0x722847964D5BD2EDULL, 0xA7ACBAB9FFAC7E03ULL, 0x879A40B052AB4F65ULL, 0xC859DBB2E3147813ULL, 
            0x4EE861568128F05CULL, 0x7BFB803DBD998DA5ULL, 0x104AEC1D35B9EF58ULL, 0xC9899C33AE3D4FF7ULL, 
            0x3A8FAA92CC8414E6ULL, 0x664929EB760BEBA7ULL, 0x0F68086BB79CB075ULL, 0xA775473CA4DA88BAULL, 
            0xC8545DC660C36A5BULL, 0xEDCFB776FCCCCB15ULL, 0xC630B42C447B8D8CULL, 0x3ABF5D0E7A094DE9ULL, 
            0xDC24B2388A6CFCA1ULL, 0x1679E3037BED0282ULL, 0x44B258D9650C8354ULL, 0x5238588AB54A59E5ULL
        },
        {
            0xCEDF8DC81F0CB715ULL, 0x67D5FA78544DEDADULL, 0x8E035ED38148E5E6ULL, 0x2B689618EF64913FULL, 
            0xDC52115CDE2A0F8CULL, 0xAF12AA56767968A0ULL, 0x785DCFB9A7E8BE17ULL, 0x84408A022711AFA7ULL, 
            0x2B5F3F9A8ED65105ULL, 0x7D44BF23248D12ABULL, 0xD88B93EF2A940FB3ULL, 0x0E831BB6D9D121F2ULL, 
            0x395E35ACB6FFBBB5ULL, 0xF1158C48A13DE1ECULL, 0x8DBD1FE964A74FE2ULL, 0x611AB9663D8CFD43ULL, 
            0xE1782BCC08462F48ULL, 0xB9B1C449D90DD4F5ULL, 0xE981D57629D37EFCULL, 0xA7634E143DB7F0CDULL, 
            0xDB253AC4DDCA3109ULL, 0xA967B2B0433E29C9ULL, 0xDF86481E10EE3C75ULL, 0x9E6F9C53E1B82219ULL, 
            0x6F90EF549D891D42ULL, 0x5259B24F8566F804ULL, 0xF64799940543E570ULL, 0xD95734A7C812F2BAULL, 
            0xE9CBB9F84846B3F9ULL, 0x4C09B628ED46DC88ULL, 0x2E01E469EF6D437FULL, 0x7E863AF39498D159ULL
        },
        {
            0x4B704212383D7901ULL, 0xAD49A7A7A6DE9AA4ULL, 0x30772DAC8138C55BULL, 0xB92648279E1D270AULL, 
            0xE4314D20C89E45B8ULL, 0x1F8AA65DDCB15C46ULL, 0xDB2DF0BA68D76832ULL, 0xDCB3D4D3DE1B1ADFULL, 
            0x66789FDEDD69BABAULL, 0x20B6BE8ADDE0D9F4ULL, 0x264C5BF0BB139C58ULL, 0x26EEDB4D98E8F2F9ULL, 
            0xE21067CC46C8C877ULL, 0x042DD32565944947ULL, 0x2D37F37808C9082FULL, 0x70148A651D64EDD1ULL, 
            0xB6D03B7D41049364ULL, 0x86748DB23B52F298ULL, 0x00601CEABACABDEDULL, 0x032138B68050E03EULL, 
            0x7437F37392989099ULL, 0x3029B2A4ABCCA1F5ULL, 0x71D1E663DD60C17CULL, 0xA269993C8A2F6999ULL, 
            0xB98A376B77FA3C48ULL, 0xA5CCDB6D97F12D57ULL, 0x55DF1A595E29F485ULL, 0x379ED1451349B834ULL, 
            0xD24CFD161D65E75BULL, 0x5C6115923DD524DDULL, 0xFA37DE199DD2D6B0ULL, 0x9AAFABC5189073DDULL
        },
        {
            0xBACF9577BCC80BD4ULL, 0xE60AEC4BD46D60F8ULL, 0x27FC89A72FDF259FULL, 0x740B13FFA0801EB8ULL, 
            0x206CFC0D75EFF16AULL, 0xEB41330322E3010EULL, 0x7C926CEC62BE0A54ULL, 0x080621BADFD4FDFCULL, 
            0x6F034BC9CD762331ULL, 0x1BED7B7B0501CF8DULL, 0x8A2A54CA38110057ULL, 0xAE28E9A817957A91ULL, 
            0x14CBE83BA5F7AB53ULL, 0x1A096BA608DA2B36ULL, 0x8427E9CCF81D698AULL, 0x933AE2DBE8D03A40ULL, 
            0x7A7EE4D83949EF59ULL, 0x3AA5C27C954C54A1ULL, 0x75763A0EF43BA5DEULL, 0xF27C1C54BDE4ADD7ULL, 
            0x0A4861ABFBD23756ULL, 0x366E326D125A95F2ULL, 0xDF0ADFFDA08B1A39ULL, 0xAFBD6A853BF6C0D0ULL, 
            0xBF02404F68DD97AEULL, 0xA8A91D73C94B47C9ULL, 0x76E9E2A2005A8F19ULL, 0xA71D5830C6121BE3ULL, 
            0x64570979C815619BULL, 0x3EAF3209DFA9511AULL, 0x80AF65BEB9D723C8ULL, 0xD71AB133AED30A1CULL
        }
    },
    {
        {
            0x5E61A9AD847783DDULL, 0x80104D7005CC15C5ULL, 0x574700DD3A68E2E8ULL, 0xF8F54F002A00DD8AULL, 
            0x14E6302989A7F4F5ULL, 0x6B5A810C755FC03FULL, 0xA6793AED88B24B7FULL, 0x64BFDA1E86AB4A4FULL, 
            0xA3259A2EA5A32F46ULL, 0x86E85F96ABE9E459ULL, 0xD6C9493F942E128FULL, 0x171363581987F0D2ULL, 
            0x2C41AFA6AA6E44D8ULL, 0xC107A786261EF1EFULL, 0x2B047726C3052591ULL, 0xD99941EA79DA6B59ULL, 
            0x101EF8D6D45947B8ULL, 0x6162EC79DBF1C7ABULL, 0xC8998553FE861A87ULL, 0xE750319EBDA351FEULL, 
            0x559E4C48488148B6ULL, 0x4226BFA8D86395BFULL, 0xF8990B5B467D944FULL, 0x2B780CCD2AB2916DULL, 
            0xE009E5FB749E831FULL, 0x0D9589FC94C639A4ULL, 0xC823A0BDFC65A713ULL, 0xA28DA111F6553702ULL, 
            0x721F118C46AFE758ULL, 0xA1C2B0010FDE13CEULL, 0x9EBE4C2CF6F43ACCULL, 0x9BE73D6D2015A266ULL
        },
        {
            0x519F4FDB00CC6323ULL, 0xF1D676385C63405EULL, 0x70B403374704F88BULL, 0x31F62306C5B0112BULL, 
            0x7B034CE694EDB441ULL, 0x6D838F53DEA083D9ULL, 0xF530F15FB00C6530ULL, 0x9DE79A971FCA5FD5ULL, 
            0x0665AA5321A60E16ULL, 0x994F3825932FBD06ULL, 0xC838FA2BBF62FF8AULL, 0xA41C08FC04C4EA25ULL, 
            0x603DB4E169FD6ABBULL, 0xE6C23F9307A43359ULL, 0x5BDC216EA15E72F3ULL, 0x52120EA4B54953B5ULL, 
            0x2C1BEAAC566B81C5ULL, 0xC9EA66421887ED9AULL, 0x8C8B3EAD46580695ULL, 0xB5A1785FCC7A05CCULL, 
            0x46A8CBB25C36A5B6ULL, 0xDD1AE1E398CFAC83ULL, 0x1A3817F21437AFE9ULL, 0xA5E1B158BFD5A0CCULL, 
            0x9C82EDD36086CC1DULL, 0x2955CB5527233905ULL, 0xDE6BF29D3EB09C7EULL, 0xD6ACDBDFD89B485DULL, 
            0xB1D00AD2BD6D7971ULL, 0xE37931A62F399299ULL, 0x3861DE4C9174B674ULL, 0x6B7EC4F6CD28CC6BULL
        },
        {
            0xEF668DD0D614873AULL, 0x5F55ABD771F706CFULL, 0xA3B42A8C7E922554ULL, 0x9CCFC0716E2506DEULL, 
            0x9C41658ADF4173EBULL, 0x970B1732B66CD32DULL, 0x04532FBCFB6C6702ULL, 0x685B818155125E1AULL, 
            0x3E29882E2EE5929BULL, 0x0EDB24602BA6DF82ULL, 0x190E81EB00F84EDAULL, 0xD383199A52B4167FULL, 
            0xF6AA0A008B4F11DFULL, 0xBAA82C58DA0E42A8ULL, 0x910664DB862046D1ULL, 0x7C34D0721538BB2DULL, 
            0xAFAF154DC5E069A2ULL, 0x1948856DA7C761F9ULL, 0xCCAD8789A4A2B87CULL, 0xE3D6A9CA6AEDABDBULL, 
            0xADE2D87B4CABBF9CULL, 0x347CFCAF873CDC59ULL, 0xB5350B41979A4955ULL, 0x31779D93FC0AC4E9ULL, 
            0xEFB64DD249C52539ULL, 0x2066099671CC7C2FULL, 0x9AD69BBEDE390976ULL, 0x665AADA1F71AF264ULL, 
            0x5EFD8D3DB405AEFBULL, 0x9DF44675DDF4EE83ULL, 0x3CCAF6FA3B47E5FDULL, 0x96AE304BA6C8163FULL
        },
        {
            0xAFFEEE78B270D047ULL, 0xA71C439ADE48764BULL, 0x5E730A1E9BA75624ULL, 0xCDA9E18A69AF76E6ULL, 
            0x724B745E07B22B7CULL, 0x4A2FDF21BDE13C81ULL, 0xA11A05D1085CEF2CULL, 0x83A10833A19DE182ULL, 
            0xA299456E03F465E0ULL, 0x87686B49C0500BF0ULL, 0x8B5A6AC2E5702AE4ULL, 0xEFB0D66B470B5BE5ULL, 
            0x7C150B1AE5C6A822ULL, 0x692906DB305A7CA0ULL, 0x09C8A2334D2BF08BULL, 0x278FA9FAB575CA86ULL, 
            0xF868395C955D23FBULL, 0xD809CCEEE15FEB0BULL, 0xB5906554575BA0C8ULL, 0xEAE05B57F23697B6ULL, 
            0x60BF77322AF7F900ULL, 0x3CDCD9C6B5522EB2ULL, 0xB9DE0C2D1CBD7B43ULL, 0x338BC8441E322DF7ULL, 
            0xDD6C22FD9FB570DDULL, 0x970283422972DF02ULL, 0xCD4779D9CFBA539DULL, 0x66F1CCE031CC3C14ULL, 
            0x705D5FB97CAEFE27ULL, 0x7E3391CC71AB46C8ULL, 0x5763270440265430ULL, 0x63FB86EE26671AA0ULL
        },
        {
            0x012F82E8137AE47BULL, 0x331DE86F62F4475BULL, 0x003BE8844F2D215BULL, 0x89C826CD61EB8370ULL, 
            0x8E7CA47FC69F0E81ULL, 0x83581BABC8512788ULL, 0x311DFA90542A25E7ULL, 0x0DB0C33E975A1215ULL, 
            0xB8FC1C0A442F5F8DULL, 0x3187459982A01DC4ULL, 0xE675A20F7E3F429DULL, 0x74A5C704552CCEB5ULL, 
            0x043C3AFBFDAC4C68ULL, 0xF8636F801C1C6599ULL, 0xB6143A2E45B876BEULL, 0xF69473EC0D9E0CF0ULL, 
            0x6871D83AD063B032ULL, 0x31E561424B8B0502ULL, 0xF4A0BBE247859170ULL, 0x4038EB5F4C21466DULL, 
            0xBCAC0537B3F4C31EULL, 0x97891456F7D8B221ULL, 0xA5BB66A081BA26CEULL, 0x733D76AFA8F8EF56ULL, 
            0x3F6788B244835A4BULL, 0x88D05B8D483DE550ULL, 0xF507D40BA6F53463ULL, 0x7FF49E656239F214ULL, 
            0xA355A5354D32CFE4ULL, 0x501560910D75891DULL, 0x560DC2ECCF2BA524ULL, 0xABC915DEE3519A99ULL
        },
        {
            0x575C89EC7741A56DULL, 0x7D7D35DA82A94420ULL, 0x0F9EF5CD14FE4C08ULL, 0xD038AA3EFA17D71DULL, 
            0xA4D0169809DEF40CULL, 0xFC5F3AD1C927DE96ULL, 0x57C322956CE801B2ULL, 0x2799045AC35C6DDFULL, 
            0xF54D02C960879D87ULL, 0xC6522B48193333CAULL, 0xE2C3742E162E7931ULL, 0x712448C90259F171ULL, 
            0x8C32779F54DFADFAULL, 0xE0B17BA7D3B82348ULL, 0x729CECA5F9F2581CULL, 0xFCE1EFD068C0B093ULL, 
            0xA096EB77B0D68F52ULL, 0xE8A70398CA504C8BULL, 0x2D97DB88F052B621ULL, 0xFBD6FDE705C3E0D0ULL, 
            0x5FFF0549D3FD4A8FULL, 0x29F1736F9C40D9EDULL, 0x1510ED454A3DC0AFULL, 0x850CD1D49D5D842DULL, 
            0x309AB5BBD9A6C120ULL, 0x35EE3F6C330194B8ULL, 0x505B114260B77A29ULL, 0x2CB7100511828127ULL, 
            0x091D289AF4D2C089ULL, 0xBB74FB872FF2EB93ULL, 0xE64296542E5DDD0FULL, 0x99A7EC5840656990ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kTwistConstants = {
    0x61FB550D379EF856ULL,
    0x63553DAC407F1F14ULL,
    0x61EF38034390707CULL,
    0x61FB550D379EF856ULL,
    0x63553DAC407F1F14ULL,
    0x61EF38034390707CULL,
    0x09553147C3D0BEFCULL,
    0x309A1B6F793939FEULL,
    0x92,
    0xA6,
    0x88,
    0x65,
    0xD4,
    0xE4,
    0x97,
    0xA2
};

