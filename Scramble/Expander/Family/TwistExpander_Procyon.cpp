#include "TwistExpander_Procyon.hpp"
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

TwistExpander_Procyon::TwistExpander_Procyon()
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

void TwistExpander_Procyon::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8C7E05637DD3C5C8ULL; std::uint64_t aIngress = 0xA15BEC100AA7A774ULL; std::uint64_t aCarry = 0x9F0B691C844BB524ULL;

    std::uint64_t aWandererA = 0xBC7E90354E35B9D8ULL; std::uint64_t aWandererB = 0xB2B6BCDCE3C574B2ULL; std::uint64_t aWandererC = 0x9D933D0770EB40E8ULL; std::uint64_t aWandererD = 0xBEF5935D17541D2DULL;
    std::uint64_t aWandererE = 0xC849345F4B2E3B06ULL; std::uint64_t aWandererF = 0xEF4CC07AD14CEC26ULL; std::uint64_t aWandererG = 0xB531F1D11FE05139ULL; std::uint64_t aWandererH = 0xB36A6766DE540C92ULL;
    std::uint64_t aWandererI = 0x8679161BDF7FA974ULL; std::uint64_t aWandererJ = 0x8D75D04D9B2C9461ULL; std::uint64_t aWandererK = 0xBE4C8A6305D01334ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA558C21C942CB2FCULL;
        aCarry = 0xA094DA8B93909816ULL;
        aWandererA = 0xE72091332B138DD7ULL;
        aWandererB = 0x95D38D4F50F4152CULL;
        aWandererC = 0xF92120E2B9DF3608ULL;
        aWandererD = 0xFC98D25F68EB1A76ULL;
        aWandererE = 0x888E6F28E28832ACULL;
        aWandererF = 0xA9B16B5CB400A661ULL;
        aWandererG = 0xB36169D858C099FAULL;
        aWandererH = 0xF573F7FCEF7AFEFAULL;
        aWandererI = 0xAED06D282301DBF6ULL;
        aWandererJ = 0xB7F8CF20BC37FE76ULL;
        aWandererK = 0xB752756A8CC7C719ULL;
    TwistExpander_Procyon_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA51704EC55BA8D68ULL; std::uint64_t aIngress = 0x867FAC8E2ECC5496ULL; std::uint64_t aCarry = 0x99657812056C27ADULL;

    std::uint64_t aWandererA = 0xAA9E135551617DB8ULL; std::uint64_t aWandererB = 0xBA4C147B589AEF79ULL; std::uint64_t aWandererC = 0x9EEB641CECA516F4ULL; std::uint64_t aWandererD = 0x9BA40F2BE5C40D67ULL;
    std::uint64_t aWandererE = 0xAB0A21BC63CC1354ULL; std::uint64_t aWandererF = 0xDE824E0F84DBFBB5ULL; std::uint64_t aWandererG = 0xC9E82AB6DEA2C386ULL; std::uint64_t aWandererH = 0xF40D11E3325F0578ULL;
    std::uint64_t aWandererI = 0x97152DF29D50675BULL; std::uint64_t aWandererJ = 0xCF4B4CD149C64972ULL; std::uint64_t aWandererK = 0xECE9853FC74DBF00ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8C15095C381C58FFULL;
        aCarry = 0xBD8A3B16BAB71368ULL;
        aWandererA = 0x95C21533324A7950ULL;
        aWandererB = 0xE4EEB5EC4AE24128ULL;
        aWandererC = 0xF6F7639203D5C011ULL;
        aWandererD = 0xADCCA4DE5EE17122ULL;
        aWandererE = 0x834B08DD068CA883ULL;
        aWandererF = 0x965F60FBD6EB665AULL;
        aWandererG = 0x88ADF4C67BF76C42ULL;
        aWandererH = 0xC7C9F09EB744E081ULL;
        aWandererI = 0xDA41DDA34792FB2BULL;
        aWandererJ = 0xB0A6651ADF9E7D9DULL;
        aWandererK = 0xE35DE974CE678FBAULL;
    TwistExpander_Procyon_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x81355E1EACC812C1ULL; std::uint64_t aIngress = 0xC0DDD8A0534DCAA8ULL; std::uint64_t aCarry = 0xCB31DA2BD5F8BEADULL;

    std::uint64_t aWandererA = 0xB384AF236533C257ULL; std::uint64_t aWandererB = 0x98BBBE06AA049811ULL; std::uint64_t aWandererC = 0xA237B2706DF8293DULL; std::uint64_t aWandererD = 0xAA9E7C6D030D140DULL;
    std::uint64_t aWandererE = 0xC37214AC581D3C35ULL; std::uint64_t aWandererF = 0xA7A7A0730ECCCE70ULL; std::uint64_t aWandererG = 0xC124B6B5B240B0F9ULL; std::uint64_t aWandererH = 0xCF5A1B98925C532FULL;
    std::uint64_t aWandererI = 0x9A06BF5894CE25D7ULL; std::uint64_t aWandererJ = 0xC09D3F830C9E38E0ULL; std::uint64_t aWandererK = 0xDDB5440705D329E8ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9C3965034BE99E50ULL;
        aCarry = 0xE27A8EDA2D3AC8AFULL;
        aWandererA = 0xAA8E28706B576B86ULL;
        aWandererB = 0xA340D2EAF8594A70ULL;
        aWandererC = 0xB2149AD81E11E528ULL;
        aWandererD = 0xEE21BE03E9A5403EULL;
        aWandererE = 0xCD0A85835D4330BEULL;
        aWandererF = 0xB9CF77803EA96475ULL;
        aWandererG = 0xD739591803B4BBD4ULL;
        aWandererH = 0xAA63B0604E1DC38EULL;
        aWandererI = 0xF8F6709123B42F8BULL;
        aWandererJ = 0xD0EB62FD2EC54FEAULL;
        aWandererK = 0xCCF9880A95A6681CULL;
    TwistExpander_Procyon_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x85C4A28F285D02DCULL; std::uint64_t aIngress = 0xC0D7535E6C7389EFULL; std::uint64_t aCarry = 0xA1FCD095C4FE3E3CULL;

    std::uint64_t aWandererA = 0xBFE0D2C1009BEB35ULL; std::uint64_t aWandererB = 0xD38975615E5CC1BBULL; std::uint64_t aWandererC = 0xF172F690550C33DCULL; std::uint64_t aWandererD = 0xDA59732678A4F342ULL;
    std::uint64_t aWandererE = 0xFA9A69F0613B5467ULL; std::uint64_t aWandererF = 0xCD3C85CAC15745F9ULL; std::uint64_t aWandererG = 0xDAED78C7F63816B9ULL; std::uint64_t aWandererH = 0xB44489BED196F53BULL;
    std::uint64_t aWandererI = 0xEDEF0DA688BEDC46ULL; std::uint64_t aWandererJ = 0x95376B767A9EDF05ULL; std::uint64_t aWandererK = 0x973E4BAE69D9C812ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x86CA94971B9A2B37ULL;
        aCarry = 0xAF2B8D719A359B5FULL;
        aWandererA = 0xD3E11D24721BDBC5ULL;
        aWandererB = 0x8C7270CC4AD90F38ULL;
        aWandererC = 0x9F93E68129981E47ULL;
        aWandererD = 0xC220788CAD2245F5ULL;
        aWandererE = 0xE66DE0C08E796C16ULL;
        aWandererF = 0xFB90DECFA41F9831ULL;
        aWandererG = 0xAFA6BADDEF18D7C7ULL;
        aWandererH = 0xB5C39A8D1D586E73ULL;
        aWandererI = 0xE72B03ACB8E17D65ULL;
        aWandererJ = 0xCABB9E5D2FB35FE1ULL;
        aWandererK = 0xE4ABFDB12C0E208BULL;
    TwistExpander_Procyon_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Procyon::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE6A6E2EB37C799CBULL;
    std::uint64_t aIngress = 0xA766587A380F970BULL;
    std::uint64_t aCarry = 0x88F2C092C45C4563ULL;

    std::uint64_t aWandererA = 0xCE27B472448B4D9CULL;
    std::uint64_t aWandererB = 0x8312C958ECA79873ULL;
    std::uint64_t aWandererC = 0x9FB363AC719A6405ULL;
    std::uint64_t aWandererD = 0xC2631CF300042EFBULL;
    std::uint64_t aWandererE = 0x9168E716E7A09DA7ULL;
    std::uint64_t aWandererF = 0xAAC0240599E40AB3ULL;
    std::uint64_t aWandererG = 0xA7FB903B90664FCAULL;
    std::uint64_t aWandererH = 0xD0604536CFC760B1ULL;
    std::uint64_t aWandererI = 0x96649A87D69F5135ULL;
    std::uint64_t aWandererJ = 0xC349BE1F9DBA6B1FULL;
    std::uint64_t aWandererK = 0xECD6BD10E6106FACULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    TwistExpander_Procyon_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KEY(pWorkSpace,
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

void TwistExpander_Procyon::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD0649E68BDB93484ULL; std::uint64_t aIngress = 0xB2CFCD8F736D4C37ULL; std::uint64_t aCarry = 0xD638E55A95E65B6AULL;

    std::uint64_t aWandererA = 0xBACED598AB1E81E6ULL; std::uint64_t aWandererB = 0x8646595B45B68E42ULL; std::uint64_t aWandererC = 0xB2A9FC88A5B59660ULL; std::uint64_t aWandererD = 0xAFBD7A91197BB47EULL;
    std::uint64_t aWandererE = 0xB9C8EF537EE36BF7ULL; std::uint64_t aWandererF = 0xF7E728BD0FCD5651ULL; std::uint64_t aWandererG = 0x88D77BE39E4FEF8BULL; std::uint64_t aWandererH = 0xF29E5D9F8A53A4D0ULL;
    std::uint64_t aWandererI = 0xDE4C994C54008222ULL; std::uint64_t aWandererJ = 0x9EE82EAE4FDF5774ULL; std::uint64_t aWandererK = 0xDAF0E526E6BAE9BFULL;

    // [twist]
        aPrevious = 0xD50CA73FCEF9F16AULL;
        aCarry = 0xA2463BC5FADBC5F6ULL;
        aWandererA = 0x9D287A79F318CC10ULL;
        aWandererB = 0x895C511C17DD92FEULL;
        aWandererC = 0x886F97D2D3CD6878ULL;
        aWandererD = 0xB8170E637FB3DFE4ULL;
        aWandererE = 0x90B0B01559C6DE83ULL;
        aWandererF = 0xD13B99F7D3D0E1C4ULL;
        aWandererG = 0xD1DC5A7B63F0485DULL;
        aWandererH = 0xFD4329C2322BD066ULL;
        aWandererI = 0xC525B74E6DFA0AD5ULL;
        aWandererJ = 0xF45208B2917F19EDULL;
        aWandererK = 0xD599785B97D2024BULL;
    TwistExpander_Procyon_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Procyon_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Procyon::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Procyon::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Procyon::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 26 of 33
    // Exploration cases: 0
    // Structural maximin 508 / 674; family total 13401
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
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1960U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 26 of 33
    // Exploration cases: 0
    // Structural maximin 505 / 674; family total 13363
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1240U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 26 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1045 / 1248; total 26944
void TwistExpander_Procyon::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 295U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
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
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
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
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
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
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 26 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1049 / 1248; total 26991
void TwistExpander_Procyon::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
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
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Procyon::kKeyRotateSalts = {
    {
        {
            0x6741F943E8FE0298ULL, 0x3CE9B0E6750AA753ULL, 0x8813D9B39F6FB925ULL, 0xC6522BAC1153F799ULL, 
            0xD174B48FA37C3F08ULL, 0x1A94BBFAD961BC2FULL, 0x967B97E62797A209ULL, 0x76C00B9033CBE82DULL, 
            0x554407D136BF68C1ULL, 0x4653B4CE2A9F7D99ULL, 0x39C4C64FB13FDF1CULL, 0x4533A3C6B51F8C4DULL, 
            0xB07AE2D7510CE94AULL, 0x6A61DF6F574E8587ULL, 0x6E137A7279F4AE3CULL, 0x4BDA9696D07B70EFULL, 
            0xB5B5A0CC5763E582ULL, 0x3D9AE62C5A9FC8BFULL, 0xFF972B180A1A995DULL, 0xD2EDAB7F1B00D10FULL, 
            0xB0CE3BB40EFCE874ULL, 0x0F313B5A69B6B794ULL, 0xB40E286E17F8A1DFULL, 0x422C00D4029E73BEULL, 
            0x779180FD02F3EC55ULL, 0x70EE1FD8F4C20121ULL, 0xE50F8EC4F899356FULL, 0x1FB8FADE6129C83BULL, 
            0x292C5CBECF9DC6F7ULL, 0x84D55004419EFB04ULL, 0x7601760F8F876AE8ULL, 0x0927DDE8ADBEF327ULL
        },
        {
            0xFA46618C98D95B80ULL, 0x7A045EBE747B278CULL, 0x7B27303892B6C7A1ULL, 0xE8DCF4AAFFE5113AULL, 
            0x3A835BC3961E7727ULL, 0x7CF7E5681E7A03EBULL, 0xC93E4A9BDC91A485ULL, 0x701AD94A0F156BE5ULL, 
            0xD6EDF394BFA1237AULL, 0x9494E8576AEED45DULL, 0x7AF8FF6FEE22BA71ULL, 0xC80710BB27018354ULL, 
            0xAAEB79F76F1934A8ULL, 0xCAF4B433E4C0CE1FULL, 0x2CBF8E127FCC663BULL, 0x582261392EED88EAULL, 
            0x57B8720559C908B7ULL, 0xC2AF1795C107BFCBULL, 0x0BA8A1B101A8104DULL, 0xC7C982E8C1CFE52AULL, 
            0x9FBEA487801881ACULL, 0x4B60C726AA26B9DCULL, 0x694755AF8DE8180EULL, 0x681DFF818C804AF5ULL, 
            0x9B80B24B6420231EULL, 0x9298718365ED74FFULL, 0x9C7274AEC7D5C623ULL, 0x2A5A6493D8FA2892ULL, 
            0xF722E68072CE64F8ULL, 0x9A103FE4CBF6C86CULL, 0x7E4AB3AB45BECBD3ULL, 0xE58BBAE379073AC8ULL
        },
        {
            0x115232F73B314E79ULL, 0x45DC62B8D88D0F27ULL, 0x1C3F97024B9F61A1ULL, 0x03BABD4DA9EDBFEAULL, 
            0x1AA129A95D203F12ULL, 0x79857DD626A02B82ULL, 0x5CBF2247373638B1ULL, 0xE62C3C7E75E4736BULL, 
            0x6E2AA9C09E317B41ULL, 0xAAB69272705B6C10ULL, 0xE71B3E12941C4D02ULL, 0x5392B2DF059EC75AULL, 
            0x35418A18417A6105ULL, 0x71609908AA8DCFC0ULL, 0xED99591DA3D5DC02ULL, 0x75923FB4462E3466ULL, 
            0xC8327AA641E118B1ULL, 0x52DA61101C022EB3ULL, 0x725C64132D828E43ULL, 0xD961082E1FA6EE4FULL, 
            0x8B1DD850118CC81CULL, 0x0117CAB0086BDBD1ULL, 0xC8672ACDB7198274ULL, 0xAED9BE2F442B91A5ULL, 
            0x1827111256121A66ULL, 0xF188379A46FF6C0FULL, 0xF9F631B1EEE9BBA3ULL, 0x3F04EA665929D3E3ULL, 
            0x29A916FA136855F7ULL, 0x700CB3F0588DDBF8ULL, 0xE3275D8D7502EDF3ULL, 0x1081B361DCE7D831ULL
        },
        {
            0x78F05DA448A90760ULL, 0xC646B064B1B33CF6ULL, 0xAC9606DE2DA367DEULL, 0x661A58EFE4CA5554ULL, 
            0xFA78F3780BB6151CULL, 0xC4E072BBA073E237ULL, 0x10248B18ABEA4C11ULL, 0x5C77B0C3460C23FFULL, 
            0x892844FE89E3EDBBULL, 0x1B6127EBBACF0FDFULL, 0xB78BFDBB0D5D9ED4ULL, 0x3348257494B31749ULL, 
            0x2DB8D198219C0830ULL, 0x469AAADF87D7E393ULL, 0x246C0413EA3CBA5DULL, 0x650E109D2B10A43BULL, 
            0xED459BB2F22C57F0ULL, 0x41E7A3943F3A44A1ULL, 0xD5CE6780F072E62DULL, 0x47164A2D1B7B7091ULL, 
            0x8B733DD3049D077CULL, 0x7A9327FD96EF2BCBULL, 0xC9636ACCC3E015FEULL, 0xEAEC37F957B66D91ULL, 
            0xBA05BDACCDF00828ULL, 0x6F13F48938A5B624ULL, 0x3EDD85DCD097DF12ULL, 0x722384D39A744198ULL, 
            0x0E9E42D633C664CDULL, 0x4C57B70D5307D8BEULL, 0x5252ACAC7503711FULL, 0x4E6346980A862767ULL
        },
        {
            0x6447D5336B6D7705ULL, 0xB4B075D0E4F09049ULL, 0x42D9231758F4B63BULL, 0x08B87491FDEFABEFULL, 
            0x3E0796DC49CEAB2CULL, 0xD597A1A4971D9B7AULL, 0xEFCB8F24150C2997ULL, 0x0FE793C9B51037A3ULL, 
            0xFEC7AF7E5962D12BULL, 0x97CB02D4CBB19986ULL, 0x98D136B0688A77A1ULL, 0x0363E45F272F413AULL, 
            0x85B11F2CA3829032ULL, 0xC1865429E7F82E22ULL, 0x669FBEB74CFED0FCULL, 0x37A8E3234272A589ULL, 
            0x681E1BE50C9585F4ULL, 0x403058C2A68A51F4ULL, 0xE89E2E63EB18DF15ULL, 0x1200C22EEB29C4B0ULL, 
            0x2AB91A12791E19F9ULL, 0x21689A0FE81477BAULL, 0x57EE51B2C1A01B0BULL, 0x3892AECC058BAF66ULL, 
            0x33D4FC98B8F660BEULL, 0x4839E8B0773E3783ULL, 0x2F92FE8692D44623ULL, 0x034C4F259834946EULL, 
            0xFB00550F59414D0DULL, 0x25BAD76C5491BDB1ULL, 0x6F2B1A4B626410B8ULL, 0x08E1A459DD68E808ULL
        },
        {
            0x890653825207A97FULL, 0xDA2DE37346DDB626ULL, 0xB3AD62824ED9B2FEULL, 0x8B64477CCB5AB195ULL, 
            0xEACF5DA4BA9E6DD2ULL, 0x543E991B959BDFE3ULL, 0x5C29637217C09BFBULL, 0xB4B6580B2C62390FULL, 
            0xF44ED61EA5E71F69ULL, 0xD81216C8B3650AB1ULL, 0xFD6FEB7001B4B1F9ULL, 0xCCDF69AB9DB07DA3ULL, 
            0x31311BB5F6EE6CC9ULL, 0xD2618BD6EAD67AD6ULL, 0xA27E46302F31CEA3ULL, 0x6D704843996B4287ULL, 
            0xFBEC2FEB84C22DEDULL, 0xFE939F748412FC7FULL, 0x28C638C6C0070A55ULL, 0x5E2EDCBE6DB1DFBEULL, 
            0x7E06680A7AD4861FULL, 0x27836FCE0EAB8DAEULL, 0xEF8CAAF72F0BADCCULL, 0x9F3F73CF037EE977ULL, 
            0x6AD6A314D0E1888CULL, 0xF3C35B1BCBE55B65ULL, 0x4A04BCA95DCBFCD4ULL, 0x0C547667CD4EDCFEULL, 
            0xE79CFC8445DDF2AEULL, 0x2BFE4B85B5414035ULL, 0x205E5CBAAB8BEA63ULL, 0x7FD548C893B858A8ULL
        }
    },
    {
        {
            0x3AB91DD51393EED6ULL, 0x6F96A411E53ED247ULL, 0x802B935D4450AA85ULL, 0xFF9E3ECE70E0CE18ULL, 
            0x0BCB46AD0F07E059ULL, 0xB0587A0C31184A5EULL, 0x2E2E34E72FBF0E0FULL, 0x05337DD1A0928FD2ULL, 
            0xB8FA131945AD279EULL, 0x629CEAEEC195A4ABULL, 0x0F494CAA87A6B258ULL, 0x245B8DADFD406AA2ULL, 
            0x078140C3ECDFB4C5ULL, 0x7EAB4300775CA24EULL, 0xB73A4EFE0092058CULL, 0xD791C71DA78118E3ULL, 
            0xE951A447E63054EAULL, 0xCB83E83893AC4D06ULL, 0xD2539BBF6ABB085AULL, 0x1AA9D7DDAC7A7EAAULL, 
            0x688F202F42C75C04ULL, 0xFCFD22A548C5EC0DULL, 0x9CD89F078AC519B3ULL, 0xA94C22714A9FEFC9ULL, 
            0xE83178F90AC9101EULL, 0xE7EAE2CA07CEC7C6ULL, 0xA54EC2BD99BF6D96ULL, 0xA2645C60E31AA481ULL, 
            0x17310E1E9734E92DULL, 0x4D0F83624B4318F1ULL, 0x269C628A2E3D7329ULL, 0x2A2D3BBAAE6400A8ULL
        },
        {
            0x80D57C624E65FC22ULL, 0xEEB4D7E2AB24D01FULL, 0x0919D5E22F261D7DULL, 0xE6690CD19804D5ACULL, 
            0xC4BE1E9C0FBE1D4CULL, 0x1A4D636004B9F0F6ULL, 0x13B12586915EC6DBULL, 0x3D0D4763205A8AB9ULL, 
            0xD21FABA646292E7EULL, 0x53A7BC7D26441906ULL, 0xB108DF28F9651E37ULL, 0x1F8601541C6A842EULL, 
            0x3F54DA64E3995F85ULL, 0xB20E13E1996F0EF6ULL, 0x2D4946DED38363ACULL, 0x28B9106E539968DFULL, 
            0xDACBCCF06BBC27DAULL, 0xF113B2411788877DULL, 0xDFA38DC96BEEAEA2ULL, 0x3C31AB07038F03DAULL, 
            0x83E172BA2A9A067EULL, 0x87AADC4E462FB2C6ULL, 0x76CFE11FAC693795ULL, 0x7939CAB39ABAA8CBULL, 
            0x0806E7EBB1B7B56AULL, 0x8BB9A826C2A09CB5ULL, 0xB0DF094BDE7EF824ULL, 0xF3346309F2CFF53DULL, 
            0x811D67D1226B2C09ULL, 0xF816BA92BABEAE49ULL, 0x3CA3B747E3C64968ULL, 0xACD5FE36CBE61288ULL
        },
        {
            0x388B882D0638011DULL, 0x011D297C59CDBF4FULL, 0x66518021CE2BF988ULL, 0xBDFCA6A2EA54D86EULL, 
            0x61179B7C1BC735F4ULL, 0x494A83A11F5E3CBFULL, 0xEA74683DF8832991ULL, 0x2246193126D9C49FULL, 
            0x6C74FC8CD19FCC21ULL, 0x054C4EB9D1FED205ULL, 0xF5782AAFF21AD1A0ULL, 0x9F2A67638E5550E8ULL, 
            0xC503D2FF8A66B240ULL, 0xFB591908766B0950ULL, 0x66984E5AD03AE48EULL, 0x9D8CBD42BE69F980ULL, 
            0xD29EF4BEED8CBAD4ULL, 0x6919B02A359B7537ULL, 0x55D34DDA759666F4ULL, 0x5EDAE416CF718EF4ULL, 
            0xD03C518EE5FE1567ULL, 0xC32205E3EAA1E5DDULL, 0x7F5C602FCC68C1AFULL, 0xFEBA9215E619FBB3ULL, 
            0xCD81F9F53F92A759ULL, 0xB3E044B4EB61E4D9ULL, 0x15288D5A8D98209AULL, 0x5191D3A237BDF411ULL, 
            0xBBC92F09715C8A9EULL, 0x5E551D472E45E6ABULL, 0xDABCBEA9AA4137A8ULL, 0xEF778C398D25DCD5ULL
        },
        {
            0xACEE855AB4C62113ULL, 0x6DE4328EF31D3E76ULL, 0x4A201ABDBF7EB1BBULL, 0x3F292755777DC87EULL, 
            0x34595725AC2CA5D8ULL, 0x09B8D2863AE09589ULL, 0xE5D9A442D4FAF428ULL, 0xD6E289FD21F6684CULL, 
            0xFB8AEB32FB4C73B9ULL, 0x46C5038C64F466E2ULL, 0x875A2C4958687CBFULL, 0x2FC204BF67941322ULL, 
            0x6F640C87FE6F0696ULL, 0x27CA6F88227A9DABULL, 0xBD5104DAD7D82FEFULL, 0x51C37B38DCF2E81AULL, 
            0x3DD7C85711B6675EULL, 0x74E14F6249CB1BF7ULL, 0x47A0B9EEF8928E38ULL, 0x852907262BF45BF6ULL, 
            0xB363E2788C163426ULL, 0x6DD8717D2B8C1DAAULL, 0xF53B752475F6EC2BULL, 0xD4B122594CE1DA8BULL, 
            0x7A0093FA7C88C24CULL, 0x1B17E85A5FD2080EULL, 0xD129D66CB35C8986ULL, 0xFEFAFAA4D255BC3EULL, 
            0x02A3A9E62F56BBD0ULL, 0xA0DF9A6ABE45A839ULL, 0xE0C4209517D91D4BULL, 0x5E1E784BC8239AEAULL
        },
        {
            0x179A46B9DD3F35ADULL, 0x2B00D034C38618E0ULL, 0xE160ECFF88C72BA1ULL, 0x8152CC9257CCDC24ULL, 
            0x5FA76951A194B8C3ULL, 0x40B29C8C98795E59ULL, 0x80538DFEA587837DULL, 0xBD58EAB18CFC63FEULL, 
            0xEC9D628F4B986AA4ULL, 0x986B0501C6D64DB6ULL, 0xEFC3792A68742DCBULL, 0x9D433B7B044662C5ULL, 
            0xC79FA3C83FD33F62ULL, 0x7FD3388C5059D1BEULL, 0xF6AC8CCCF1494000ULL, 0x3B0269CD6FC5C1EFULL, 
            0xE834D45A37B0CB9CULL, 0x1E1C2F2704213A4AULL, 0x7906F1D19610FDAAULL, 0xD307DA0F69764648ULL, 
            0x16861638CB574476ULL, 0x1A6C64487796DF2BULL, 0x858BCF8E0ADFDD29ULL, 0x3F4EDBFDC943F671ULL, 
            0x081A446928C3C698ULL, 0x8617155DCDECD851ULL, 0x4415C3F9E8161933ULL, 0x83F9F13B79787FFEULL, 
            0xDB64896E3099E18EULL, 0x6D9E7C5D3E7C7281ULL, 0x9FA9ED9AAA6E5A7EULL, 0xE43D96FAF4C4247EULL
        },
        {
            0x04BBF572D36E08C3ULL, 0x4C079BA223B3F1F6ULL, 0xADA565056A1FB775ULL, 0xC7F138D50BB3FB9FULL, 
            0xA6453942AAE9E392ULL, 0x3A08C3E708EFF853ULL, 0xE44EFF8AE40D3B7CULL, 0xDF8DCD8E99BA27F4ULL, 
            0x10FB5E4C532FE286ULL, 0xF562CBFA5D37E3E8ULL, 0x9A128B220549581BULL, 0x2446B551CCE34865ULL, 
            0xE6499EA21C4A3AE5ULL, 0x0CBB99573534DE55ULL, 0x7ECD039144CAC286ULL, 0x5C1B1B00FB18C6C5ULL, 
            0x7BA3B87C3CB462FAULL, 0x09994D088048BCEEULL, 0x4F36FD70C39567BFULL, 0x6ADE1A165E0C0A19ULL, 
            0x510F4607D6278448ULL, 0xC7902DA8FB3CFC0CULL, 0x5F25ED11ABE9E19EULL, 0x85822ACA1BC3749BULL, 
            0x0361C981D3571450ULL, 0xDCC429DEC9070607ULL, 0xEC5B11268785EDCAULL, 0xE8E2DDB285D3CEF5ULL, 
            0x48920A5A9B8A97D7ULL, 0xB90B5342F206907DULL, 0x2D567FB25F26CA3EULL, 0x23535B0E34E0698FULL
        }
    },
    {
        {
            0x0706729F4C8C5FB0ULL, 0xF6480F5E843C7140ULL, 0x3792FDEE2E6A589BULL, 0x08CEA10AD714FDACULL, 
            0xE595FC7C40EC3B04ULL, 0x966FC0CB18E60E7BULL, 0x13F27E5861ECC044ULL, 0x398AF8A397B168C1ULL, 
            0xFBAC25F79D585A8CULL, 0x6C1F3BC97F15DD8FULL, 0xAC9494FEE7C3F8D1ULL, 0x72564F6907765DEDULL, 
            0x5A59F1D1CD925EF7ULL, 0x2C952DE1BE4C36DDULL, 0x6C002C28550E4380ULL, 0x3F77E0892C7514DCULL, 
            0x2218D597B039FE4EULL, 0x4A9386592BBC9875ULL, 0xE9FCDDE10149EB0CULL, 0xCE346A28BDD0ADA9ULL, 
            0x6B5737DD9001671CULL, 0xBB49263D98060333ULL, 0xE5811761F270F6A7ULL, 0x2490DA88FFBA752DULL, 
            0xD951EFBF77DC95C1ULL, 0xE0F6CA0CCA069A25ULL, 0x4F9EE332EA992264ULL, 0x39270B080C516593ULL, 
            0x848C5AB2EF436FD8ULL, 0x08AE88E787F9DDC5ULL, 0xA4211628FACC1BC3ULL, 0x479C73E295B25570ULL
        },
        {
            0xA048DB7560ABDD7BULL, 0xC49FA5FD4FBC96FDULL, 0xA9CF15D481144763ULL, 0x89A5CD4E80A81918ULL, 
            0x761BB0356C6821BBULL, 0x7EBCF8BEBD184085ULL, 0xCBDF61FB0F817413ULL, 0x6B9F3C9384FE7A25ULL, 
            0x7235478977730776ULL, 0x007FC415CBDC4A3AULL, 0x13841AE3B99BCEEBULL, 0xB3F0E029DF2DAC58ULL, 
            0x850FE30B23CEB440ULL, 0xCDDDBF352FE669DBULL, 0x7464E8FAD42FB1AFULL, 0xAFC8C5D597633458ULL, 
            0x43A8D137B2DEA0BCULL, 0x747E939958223FE1ULL, 0x84C4281ADC07339AULL, 0x03E7C623765E8DC9ULL, 
            0xC569565D8D08662BULL, 0x5C658F208E7097ABULL, 0xEBB5CDC53EDEC170ULL, 0x6B4591A1721BAA5DULL, 
            0x262AEBC448A8EF4AULL, 0x22CFCDB742169114ULL, 0xE580E24BB5C90A99ULL, 0xC56F56FDF8EC094EULL, 
            0x7F8E15AC5491D897ULL, 0x90E58AEC5A57E34DULL, 0xB21B265D857B1840ULL, 0x18B12822AC20082CULL
        },
        {
            0x6159AF11E5A1261AULL, 0x9402DA093C06C1B5ULL, 0x847EDC88116F19A2ULL, 0x9A870FF7052AD08EULL, 
            0xC332BE691608958BULL, 0x392D6C29D432476FULL, 0xACCE902A1CB20A8FULL, 0x0E49FFDE81E34CB9ULL, 
            0x97BB48BD77823E13ULL, 0x047296CEF32E93D9ULL, 0x2948D965250588F1ULL, 0xE72791509A71B25FULL, 
            0x1FFD48A21D154B48ULL, 0xCA07AE42EA1884CEULL, 0x0011218F85A97B49ULL, 0xEB972D4D6EE2DB12ULL, 
            0xE02054FC31C164CFULL, 0xFDBF30D72614A6E7ULL, 0x8D6BD3181B0DA1FDULL, 0xC479A516D2DB4268ULL, 
            0xC113408BCA131F1FULL, 0x4F83E2592581F902ULL, 0xF909A7BDD7B55A6EULL, 0x64FE0464C8D5230FULL, 
            0x902B31B21BBCF60DULL, 0x537461CA96599F66ULL, 0x685EB713F3B66294ULL, 0x95B15590904BCAB8ULL, 
            0xAAE19497DF49E3DFULL, 0xD006CE8647C25443ULL, 0xB91AC7FFD4AFBFFAULL, 0x27B5EC07BD1BFC96ULL
        },
        {
            0x10DD7C029B4E3C75ULL, 0x2825D1E795A8908DULL, 0x8F5144CA62698CDFULL, 0x24605156437D0988ULL, 
            0x9908E25B5E4F9906ULL, 0x8AC2E1627AEEEE3BULL, 0xDC18FE536F34ACE9ULL, 0x31BB23B47FCE1546ULL, 
            0xDEE4AEEE55E9CA01ULL, 0xEF3BE5219ABF560DULL, 0x81A5A0F0B436F913ULL, 0xA777E5E57D3618C1ULL, 
            0x5E705EFDBD9D88E3ULL, 0x1FFFB91EE89EABB4ULL, 0x16843BBA281204E9ULL, 0x0E2345385730ABF8ULL, 
            0x5E281E89C705DE76ULL, 0xB50CE1ADED064167ULL, 0x2252EEA9C35A582EULL, 0x2732D5EECD9937BEULL, 
            0xE14530EC31EFDD56ULL, 0xE3875D17B652AAD4ULL, 0x0317043AE9CC3BBCULL, 0x6F9F709A33CC45AEULL, 
            0x23F47068346B1F7BULL, 0x2AAD2F9792672E59ULL, 0x878FCDFFC3403701ULL, 0x324C53DE396521EAULL, 
            0x90C171C5F0A5F095ULL, 0xCC82A78382AE5940ULL, 0x756134A01EACEC6BULL, 0x24EE5643D4B1EA27ULL
        },
        {
            0xD6E024B4D30250CAULL, 0xDFE19D4E8A775BAFULL, 0x80E4465051AA64F9ULL, 0xE6D4218FD3486E99ULL, 
            0x74F40A0E7D4D7C7DULL, 0x4C5C1065C5637BD5ULL, 0x49684D8CAF6655B5ULL, 0xC708354961E88748ULL, 
            0xF936279B05FF0311ULL, 0xE20B711AC929048BULL, 0x579D8DF288F4C23BULL, 0xCB7C5F0D1EC8C69DULL, 
            0x9B7FA86CF0B529FEULL, 0xD50421E522EDA601ULL, 0xB0389ACDB6742A7EULL, 0x1FB216DBBE69398CULL, 
            0x037BE42749E44876ULL, 0x8450F5404A9E4337ULL, 0xF6144122F4F39D1FULL, 0xBE4C8444E1E11DF2ULL, 
            0xA84A605222F2E179ULL, 0x306726060324005EULL, 0xC9B7127594B21A42ULL, 0x250D4C5EEDE28DDEULL, 
            0x924FE03548C4AED8ULL, 0x8B54A6C890A834AFULL, 0x2FCC7EA13A23C4E5ULL, 0x93A57164DF8D463DULL, 
            0x05C7A1267F5D1C77ULL, 0x5260C5E45279AC4DULL, 0xFC46407A55B7A685ULL, 0x186A3E4F347094BAULL
        },
        {
            0x51A9BA8A9DAB861FULL, 0x6494BB88C9FDAE28ULL, 0x5C332878D60B4604ULL, 0x43BA6F9A33A52623ULL, 
            0x97DBDBABCC9EE0D2ULL, 0x69DE9FA0D4FC8D44ULL, 0x273B9D9E516517DEULL, 0x1A8103976AE46A19ULL, 
            0xC090910399F432D6ULL, 0xFE91F96D07109F34ULL, 0x8BEA838A63B5B2A1ULL, 0x58EE9EE633F61631ULL, 
            0xC07922CA848C7D1EULL, 0x99FB66C492E53ED6ULL, 0x55AE1FA4BB9CB52BULL, 0xE13786F9E9F24BC3ULL, 
            0x865890029A71FE52ULL, 0x594519F96A7D4E21ULL, 0xDD44F656C56C8FBCULL, 0xF730DF05B1A3ADD8ULL, 
            0x3CC857FF84011EE3ULL, 0xE429772D2D7E128DULL, 0x7F680903C468AAE0ULL, 0x540AB08F09D9C03EULL, 
            0x884A3995027D3BCBULL, 0xAC603373E9767E41ULL, 0xBA6A138781BE0CC9ULL, 0xA8ED3D2B2E713395ULL, 
            0x1D89D152764358FCULL, 0x8C62C16D851D7762ULL, 0x2B84E0EBCE49C3B9ULL, 0xBCA5037B20CEB028ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeyRotateConstants = {
    0xA91BA8CEA4E19648ULL,
    0x6DDEF281524BFB62ULL,
    0x96CB9DC6393DBAD0ULL,
    0xA91BA8CEA4E19648ULL,
    0x6DDEF281524BFB62ULL,
    0x96CB9DC6393DBAD0ULL,
    0x3DE6D7E3BCA991B7ULL,
    0x69E264FB5AA98F64ULL,
    0x8D,
    0xE8,
    0xFC,
    0x4B,
    0xF5,
    0x6D,
    0x08,
    0x4F
};

const TwistDomainSaltSet TwistExpander_Procyon::kKeySpawnSalts = {
    {
        {
            0xB249E5C192EA4D9BULL, 0x7BEF75FE05BFF797ULL, 0x6D5B58EB9BEB884CULL, 0x616CCCAD2B1D75A6ULL, 
            0xFFD717D97E49D116ULL, 0x3F7A945D71795F8BULL, 0x412DF8D80871B614ULL, 0x5D55AFAF12273F13ULL, 
            0xC7DE8F01AA7E712EULL, 0x39C857F6CF7BF132ULL, 0x80223946FD067687ULL, 0x4F2DD6546406A078ULL, 
            0xA64142A54588AA8FULL, 0xF6E48F5DEC9BF3E3ULL, 0xA373FA38F1A1955DULL, 0x5F3D02E67373D995ULL, 
            0x6F5FB898D38BC7A1ULL, 0x9D8DE89F10B6D181ULL, 0xF0073059446AAC6EULL, 0x137C9E6D05AF06AAULL, 
            0xC03A8C0416176479ULL, 0x33FD41992A6740C5ULL, 0x3EFBBD676A756E8EULL, 0x539BAC0CF872EC19ULL, 
            0xD449A4EBDF1C1BE9ULL, 0x2F6281D0FE43390CULL, 0x6AD56DF22A5EA94CULL, 0x260538DF69AA8610ULL, 
            0x1A1986C45E985CFDULL, 0x60844EE444CBC37EULL, 0x2EEDE7C8FFF04940ULL, 0x618EDE0D6EFCE0D3ULL
        },
        {
            0x30F2C05BC049E679ULL, 0xEE1AD31ADF5F8032ULL, 0x7B1D835F4B1D18F8ULL, 0x8B3EBE61344A75B3ULL, 
            0x8ABD11DA8723AB0CULL, 0x6EDE8A09EB53B95BULL, 0xD353229EA3E9A3BAULL, 0x9E2BDAE14393C847ULL, 
            0x8582ED49F90F34DCULL, 0xE14F8AAE66DB7CA2ULL, 0xDC441A3685A50F9FULL, 0xAB34BD1CBAA563E4ULL, 
            0x86620D298FF2D463ULL, 0xD74870D02A457348ULL, 0x155FC9BC0F7D8FF2ULL, 0x34EB5D2E40CDAB14ULL, 
            0x45BDEC713B443CEEULL, 0x9794D87DC45EDF7BULL, 0x362CC77E4CE1E519ULL, 0x0BAFDBE76703B791ULL, 
            0x32BE54907721FCBDULL, 0xCF75C2C37E267265ULL, 0x0C7EB68DAFFE52A5ULL, 0x263C6D52AD2A7DF0ULL, 
            0x33D9056F52AB6CA6ULL, 0x924248807C38C207ULL, 0x7C876D0FBA951694ULL, 0x93F02D958A684B4FULL, 
            0xD9B710A04A331EFDULL, 0x4B55E57A3871E494ULL, 0xB200DA24A5F4B375ULL, 0x3D77F0403ADA63E4ULL
        },
        {
            0xF3CDE3551DEC2D2CULL, 0x6BD04FFEAF0AACBCULL, 0x88F424157ED7DA93ULL, 0x255E64AF753473F5ULL, 
            0xECA61A71DF8D54BDULL, 0x16882AE02A22B51BULL, 0x3D4AEDFDE9D5C1D7ULL, 0x18CC11A4A38ACA95ULL, 
            0x49AEC14A9D058AA9ULL, 0x056AF336EF4A9AD0ULL, 0xDB5067267CA2ED32ULL, 0xA6EC59629B190F60ULL, 
            0x70B4D7EB38590330ULL, 0x5AA270CA52DDA279ULL, 0x341AC955BB66454EULL, 0x23F39C692CAB21C5ULL, 
            0x9D95F28434855281ULL, 0x3371B1B4D093C063ULL, 0x67A97246ED722699ULL, 0x6657411928EC64D4ULL, 
            0xD6677A048F65FCAEULL, 0x44FCD405483AB0D2ULL, 0x9638669C90457029ULL, 0xF42118A6FB9FEACDULL, 
            0x461C02CFB5400EDFULL, 0xA955965975C48E21ULL, 0xAAD1691A868589F1ULL, 0x20760CFD72A4FE8AULL, 
            0xDC98E91FB701E5CAULL, 0x31174D02751B6BF9ULL, 0x355B0E9B4B567E9CULL, 0xBAEB4F86BACBCC2FULL
        },
        {
            0x4EDF556386E9F654ULL, 0x847F9C2037DEF72CULL, 0xAF371982C4498E14ULL, 0x9F33A838C9BB9282ULL, 
            0xD97F76B2CE650943ULL, 0xB39A39231E6733D6ULL, 0x7837EA6310B8670CULL, 0x1A15FB8B29406733ULL, 
            0xD6C732A57B9A7DDCULL, 0xAF94CAC93BC92F85ULL, 0xBC7AF6229DA73385ULL, 0x968B7744AE47B75CULL, 
            0x6A655B3504A92DB0ULL, 0x2F6E3DC1DF753653ULL, 0xA749EC0130EDD90EULL, 0x7377925ADB79CECFULL, 
            0xA02F8D0BC415C8E5ULL, 0x86F6F95DC5823CC5ULL, 0x27B536116AF10D96ULL, 0xE7A018C3543F45A3ULL, 
            0x89E95EDF22F889BEULL, 0x1B0762BE71552020ULL, 0x9CFD62ED9F2FC665ULL, 0x321905EB1A5DD249ULL, 
            0x38BEEBA363FF38F6ULL, 0x743B677ED0D1DC69ULL, 0xC8D219EB51715CF7ULL, 0x794B8237C37290CAULL, 
            0xB63B554A51EFCA3CULL, 0xFED52B4FCC40DD67ULL, 0x61651A930EE8AD23ULL, 0xD4ACD00CE802DF3AULL
        },
        {
            0xFD13DCD0EE7E6E1AULL, 0x8AA5A4EE237E872CULL, 0x20488DDC8A6F90A8ULL, 0xC94AFF3336A3FCB4ULL, 
            0x31EC261B74C6DAD1ULL, 0xEF3D1CE4D77F41A7ULL, 0x1F13874CC9ACB7BDULL, 0x9A80C10CE391B270ULL, 
            0x16FF63CE564411D9ULL, 0x4015F35BD4255E0BULL, 0x608EB00A98A49C0EULL, 0x517CB149CF22BB4DULL, 
            0x46554CD6E1DCDA97ULL, 0x65B3CAC5EB57D6C9ULL, 0x4C37CC4E02600433ULL, 0x7C83A5EB5031643CULL, 
            0xDD8C2B7D3339279CULL, 0x6243D1F181FA890BULL, 0xFD5F052900E36904ULL, 0x6962C80E73A547ECULL, 
            0xDE49E7356D352717ULL, 0x92EA5633DED934FDULL, 0x9E55D9B970EFCE17ULL, 0x5D1BCF48C6781694ULL, 
            0x6D2E8BFDD87EFA7FULL, 0xEF85AD25C38CB965ULL, 0x6EEA7B0D22C223A9ULL, 0x1440D3EF770E9026ULL, 
            0xFED186BAFD32A965ULL, 0x04E38728E75B1C7FULL, 0x2BD56351E35E991DULL, 0xA85E6A6F29D4142FULL
        },
        {
            0x6E4A4EAF6ECFA272ULL, 0xC2B65B20A554CA5CULL, 0xCD882E0DD237E5B8ULL, 0x3AA17A9806E50865ULL, 
            0x4DFADE9A0D114214ULL, 0x4489569096D369A1ULL, 0x84607CAED5A9319BULL, 0x7670039B123547F4ULL, 
            0xB8A17B3A786F8875ULL, 0xA9185949D3DD9E3EULL, 0x680A13214B4F2918ULL, 0x7012665256A2413DULL, 
            0xE83AB149CFFBBE06ULL, 0x5432102920431A7AULL, 0x1869E2231FEDEBB0ULL, 0x7874D183FDB0EBE2ULL, 
            0x64655E71BCC5C75BULL, 0x025F137DDD96B6D6ULL, 0x0A98B9C0746E4FD4ULL, 0x1780BD4D54F20EB8ULL, 
            0xC417115BC7EAECA6ULL, 0x247C4E2D982AC989ULL, 0x602C62EBD0EAE903ULL, 0xC012FAE53996B83FULL, 
            0x29E88910C740341FULL, 0xB4490DAE6AC95ED5ULL, 0x7B7994C5C046906EULL, 0x31827ED5C1F01638ULL, 
            0xE65177B2AD8ABA0BULL, 0xF4A25652714DF6D2ULL, 0x36E78F7B7E1F8BA7ULL, 0x3EED1E373BBC0CBEULL
        }
    },
    {
        {
            0x998A026EA40DFA54ULL, 0x8B9604B3465D6140ULL, 0x8F8D44F40B6E4211ULL, 0xB067C11ED9CF2D95ULL, 
            0x18B9B7B89BEC8819ULL, 0x5FFE6F1DA92327A6ULL, 0x27A93886AB053509ULL, 0x139BEECF2AD38BBCULL, 
            0xCBB0EE2DE0B41E4DULL, 0xA92095CA201B93C9ULL, 0x30868BB23ED07840ULL, 0x7B58F238AA1EAFD7ULL, 
            0x2C6C21666438D50AULL, 0xE84E6CFE1E3412A6ULL, 0x018B3712FE522DE8ULL, 0x8CBA32557E7C829DULL, 
            0x3398E0478D7B6B5AULL, 0x924BCDF9DB143EADULL, 0x33C8BD9E445B55CAULL, 0x7F9C38BE2051BB14ULL, 
            0xC4C669A02836FDD1ULL, 0xCDE3FDB39AD7B03DULL, 0x0040D50F608CE0A7ULL, 0x178D9E3383D73222ULL, 
            0xDD95762D82D811F9ULL, 0x295E8370C7EB2065ULL, 0x0416A99021BCED90ULL, 0xCEB14589AE4DD5CCULL, 
            0x7D941038D3F93A2DULL, 0xED8E4C6EF72313A3ULL, 0xFD9F44887E53D79FULL, 0xD991D436826BC337ULL
        },
        {
            0x3583FCEF991F0050ULL, 0x61A9EB4F7C44ED5DULL, 0x5BF202EEB7A8617AULL, 0x28C021D5EA7DC987ULL, 
            0x91D8D2C8DB97AC5BULL, 0x7AC4BE7BF7CAA423ULL, 0xDF368C1DBBDDC36EULL, 0x7060A582B23C97B5ULL, 
            0x284A62C2EE437546ULL, 0xF6FC94D744A95F5EULL, 0xC0D99219EA1B6D0DULL, 0x6CABA246AC4BE217ULL, 
            0x2BCC31BD51C2FA4BULL, 0x8E090F9998D00E48ULL, 0xDCB4DBF6FF7EA046ULL, 0xC17B02BA00663A39ULL, 
            0x2D36D22E74D880F3ULL, 0x60880060558888BFULL, 0xCE53C1BEF630A4F0ULL, 0x3F0D415D8F241DE2ULL, 
            0xA6598319B159AC3AULL, 0xAC7DED250221C119ULL, 0xE9085E5D0F687F51ULL, 0xC20A8CCD1868DECEULL, 
            0x8AC4EB12CC2AD9D0ULL, 0x15B9BC88FFF210EBULL, 0x385B3C98553D96B6ULL, 0xB5A0F50E5C2477FBULL, 
            0x0AC3FC8E6F59B4BDULL, 0x17120A87B37FB370ULL, 0x51C119988C11BE0FULL, 0x74C5B9B9A3ECDB5CULL
        },
        {
            0x8568AEF4AD24BE0EULL, 0x4ED72DC84F83D2DCULL, 0x351C0BB25EB95240ULL, 0x09E4AEB2EE50A877ULL, 
            0x235A67FC6C141A54ULL, 0xC1FB3B3FA70547A4ULL, 0x229712776399A427ULL, 0x743CC9F31D3918F5ULL, 
            0xB9BBF2A90EAC0832ULL, 0xEFB2839A4E6E9743ULL, 0x414323EDE7B86A4FULL, 0xEC8C06B63AB8FB4EULL, 
            0x62B2958A4617669BULL, 0x8E5F0A1206B0E142ULL, 0xC2BFEBF5C7D4C245ULL, 0x494A0F0DE4A137D4ULL, 
            0x9F35EE6952D5B274ULL, 0xBB1077ADCBA7F43BULL, 0x3C07BF60AC0002F4ULL, 0xC036F7A9ECF48F9DULL, 
            0x960D05CD230FC77DULL, 0x39A8EB266284F75CULL, 0x2BADA67C8AE22337ULL, 0x18492116840038DEULL, 
            0xBB910015F09A424CULL, 0x5292E194C3A02415ULL, 0x7F7C5E9BC2AB1C5BULL, 0x1E4E084EDEF81246ULL, 
            0x96621D845FF30A69ULL, 0xBB8670C8F31F043BULL, 0x3B6F6EA9FCE186BEULL, 0x6A7E33A4435A802DULL
        },
        {
            0xB9E7F1B464F0C95BULL, 0x8B3A1860083B77D8ULL, 0xE03FF123F6B2AAFFULL, 0x56AC9C8DFD5DC899ULL, 
            0x225BC3E8F59BAA35ULL, 0x4E0B62FA137B4618ULL, 0x07C12FF7037E2E8EULL, 0xF1DBA0C7B0272028ULL, 
            0xD3338C456F7FCA7EULL, 0xBAA2A476D592E005ULL, 0xE91888F547DD0DA9ULL, 0xA145331E58C9C6BEULL, 
            0x0E2FE2E8C5C89F26ULL, 0xE3B9653488014D66ULL, 0x993B02CBC7D7FBA8ULL, 0xBD229F2DA481B683ULL, 
            0x59F0C739207BEDF0ULL, 0x635F5559B39720CDULL, 0xC77F8BDFBA9BA349ULL, 0x4DD9D0080832C256ULL, 
            0x8F89397D32198F4FULL, 0x3FE27119899F38C4ULL, 0x7306D2F8DC17EAB0ULL, 0x2624C72B622388A0ULL, 
            0x2E7CB12F61BB41D2ULL, 0x822EFB7910DD2795ULL, 0xF5D74FDC949CB3F0ULL, 0xF12139F38D4138ABULL, 
            0x32EAB109A3E65AB8ULL, 0x6B4009C0BC4BDCE9ULL, 0x3006512C859B6305ULL, 0x574E5FD1AB93C82FULL
        },
        {
            0x1EE4095B314AC5A5ULL, 0xF50CE6CCD167FD6BULL, 0xE9D4EBE0F2F6B69EULL, 0x03B10CAA5CEEB676ULL, 
            0x0DE6CA51871178F7ULL, 0x39B5A4DC1B259D88ULL, 0x3848C28F6E2E930AULL, 0x999D46895557E984ULL, 
            0x99DA45BEC164BACFULL, 0x08A4156B5FD4C905ULL, 0x6758AE5FD61FFA3FULL, 0xD3BD322247FC3142ULL, 
            0x8A8C6D517A6550B9ULL, 0x67D232469B459A73ULL, 0xBE9EA414C705D8AFULL, 0x3CC96475934E89CFULL, 
            0x9778C331FD4B3565ULL, 0x5F989337A575DF2BULL, 0x973FA7176ED5A40DULL, 0x58CBF0FA064D4388ULL, 
            0x7923D5C6FA7CC119ULL, 0xCB08E3B98E9C9A19ULL, 0xEC57E3D8F8D1EDD9ULL, 0x2595A501354059B4ULL, 
            0x3C78892FACA18E37ULL, 0x6ECF824487BE67D5ULL, 0x9559128BCB36F061ULL, 0xD4F6827896127D77ULL, 
            0xD4CB90D0F340BB3BULL, 0xE3C4494D1394B40CULL, 0x9995BD8E80CDA69BULL, 0xC82D7BE0185FB9F3ULL
        },
        {
            0x46D5358E2F608639ULL, 0x1C1E4137330E62F3ULL, 0x5E893B582E77FE4AULL, 0xF8655283460D5EC1ULL, 
            0x7F9BB67EE2476E33ULL, 0x27266680B1F634C3ULL, 0xBD919383FED8EBA8ULL, 0x2F4746256265857BULL, 
            0x9FF5D07003F29591ULL, 0xDA6AC48F6F1E8150ULL, 0xE9D2978DE7F90068ULL, 0xD0DAFAFA614D1AC0ULL, 
            0x20E79AF2D1732FE0ULL, 0x61F4BBCF4846054AULL, 0xCA207CA4B27E7A73ULL, 0xA912FA68523BF93BULL, 
            0xA7091523655D391BULL, 0x80D4BAB52656176CULL, 0xBA69383F8CAFF45DULL, 0x3E4376D285F18338ULL, 
            0xD1180634F3A817FAULL, 0xF107EBD4F2CBB52DULL, 0xF812CE707B2F9CCAULL, 0x7C37AB67A818FE69ULL, 
            0x0181BE204C65E172ULL, 0xA0DEFC886D7AAA2BULL, 0xBCAEB3C487DD4A02ULL, 0x77760E7063C7BA45ULL, 
            0x9D4E6D0005EA87F9ULL, 0xAEABD9F67CCDE4E5ULL, 0xDE7A1747A07583AEULL, 0x6D15893791FDE5DAULL
        }
    },
    {
        {
            0x1F34ABDCF0057BF9ULL, 0xE38E3C765350ACE0ULL, 0x91C546279E178AAEULL, 0x97A92D62E7A0BEACULL, 
            0xA8DB752D72CFF234ULL, 0x5F7FFE1369059A70ULL, 0x232899CF1135F815ULL, 0xF3048A033A9A14E2ULL, 
            0x32368FBEBFC73499ULL, 0x770FB4A764EF8FB0ULL, 0xA6D2D68B28FA8891ULL, 0x5B1FBECA29A78EAEULL, 
            0x991ACC58EB61E7E0ULL, 0x6825B1D6A15F09F6ULL, 0xC0FD039E53AEA1B3ULL, 0x280B9FD7EB0A6EB3ULL, 
            0xB6F9AE607A750E97ULL, 0x440E75873D1A4688ULL, 0xA8D5870AED4C28B5ULL, 0xA59CDF6370B569F9ULL, 
            0xC5105F00CAAA8323ULL, 0xBB51B20A0584ACACULL, 0x06B95D8DB48C2058ULL, 0x49F5BADE5604110DULL, 
            0xA04BE7CDF1197957ULL, 0x181C976450DC761FULL, 0xFC3371D8E220AF79ULL, 0x94F095B384C6CD7FULL, 
            0x82DE83119A2E37FDULL, 0x2C3AECA3302201B7ULL, 0x254FBA5FEBAD880CULL, 0x7E543053989B63E3ULL
        },
        {
            0xCDC5CD4F9029CCCBULL, 0x1EC81660D1528646ULL, 0x4AA7AEC0F9878089ULL, 0xD146AA7216BBE922ULL, 
            0x22AD11B23C2ADAFAULL, 0xDF2D51BFD1750D55ULL, 0x9714677883AD5512ULL, 0x5D561E39F54AB360ULL, 
            0xDA3EFAFF980540BEULL, 0x4D62D608FA9548A1ULL, 0x51CCE095A4FB45DBULL, 0x4BCB1B5FF94CCB83ULL, 
            0xD054062AC472F0E7ULL, 0x17D0DBD2D9C97307ULL, 0xDFA7FCC40B2B72C9ULL, 0x96C0F38AB2E9D3D8ULL, 
            0xF2FF763135D80DE4ULL, 0x92073923306A6A82ULL, 0x3964CF67EFBE7D56ULL, 0x7FC985582ABDAE8DULL, 
            0xC9D2378DCD7DA358ULL, 0xE4827063374CDE0AULL, 0xC931A793C3B17BDEULL, 0x557588C02A468DA4ULL, 
            0x595332C52E7ED56FULL, 0x2AEC1FF3F2F6AC35ULL, 0x769FC2D5243B0078ULL, 0x9DF9F28E7F9A6718ULL, 
            0x3419D9904588B752ULL, 0x72C9457F2B1D4233ULL, 0xCEDA747040FA1310ULL, 0x4C7B1DADF642967CULL
        },
        {
            0xD66BB145F9DC5E49ULL, 0x6C1E5B164E5D14B3ULL, 0xE0C1AF94438FBCF0ULL, 0x7B3049B9C74EC504ULL, 
            0xF2824E6CB5574ADCULL, 0x3BDFE9C78715112BULL, 0x689A097FA654E41FULL, 0x9D192DE6E79BF6FFULL, 
            0x1A577AA5D0710E7AULL, 0x07466B2842652B56ULL, 0xE0AF2BDC10CB5852ULL, 0x901FD9D74C3FC747ULL, 
            0xDABB2C456338C2AFULL, 0x744A483A12AE0A26ULL, 0x27C5475FCB3B6926ULL, 0xF7A3858A930342F2ULL, 
            0x1340D99604EC3B4AULL, 0x1BDE3709A8D9B5D1ULL, 0xF5A0215CEAFC6D65ULL, 0xE721B802CAB27332ULL, 
            0x1217CE91715CA96FULL, 0xA9152BD0AA78AD54ULL, 0x2C31E66803047CD7ULL, 0x7B52C0573B2DE89CULL, 
            0x446FD61BF76BB524ULL, 0xDD89ACBF7E1225D4ULL, 0xEB62A56CFFEE85C1ULL, 0xE3E595B745F57806ULL, 
            0x8DDC9A2F6212A7EBULL, 0x2C8A3AC3981A3866ULL, 0xA199E4757D948D29ULL, 0x81B86F40E2B64230ULL
        },
        {
            0x3E98E51245CDB60AULL, 0x3C996D8AFA1BB9D9ULL, 0x9C226E5FC0634F48ULL, 0xA5328DEB134D2DC4ULL, 
            0x3FFCF63606704B03ULL, 0x21F50E97EE4A8555ULL, 0x64CA2F6130889678ULL, 0x18493DB59C27554EULL, 
            0x46153AEE913E78A4ULL, 0xF2DA3DEB2544F4B2ULL, 0x9255BD1082B33EA4ULL, 0x6F12CE77C659245BULL, 
            0x34229461B2D3332AULL, 0xDD13717DAA455BA8ULL, 0xD497480D6B1A9D9FULL, 0x9D8EBB0CF21B90B9ULL, 
            0x3266F15B176D3BD9ULL, 0xD0CED305B5349788ULL, 0x77EDECEC59864D9BULL, 0x849775004A57CC74ULL, 
            0x7A9256F5B285AAA5ULL, 0xCAFB811052FD77E2ULL, 0x68245F7B1768B072ULL, 0xB09DFDD32820DA41ULL, 
            0x4B5A27DEB4AE06F8ULL, 0xD2DE50A7D914A16BULL, 0xDB147864066515F3ULL, 0x9A33BEDADD7075C5ULL, 
            0x350350E1C28E0DA3ULL, 0x1B90B5BC1014CBF4ULL, 0x42444303B47F078EULL, 0x3187EFBA22DAEA82ULL
        },
        {
            0x10D555AC39461161ULL, 0x4C64BC38E49BD755ULL, 0x40F030B8BF004350ULL, 0xB4E7CA3993446B28ULL, 
            0xB7002EA83934276FULL, 0xCE6389FB93DCD165ULL, 0xA84CAC56FB3D315FULL, 0x0912F3BC1CD4FDD6ULL, 
            0xFC9EAFFFCBBAE2B9ULL, 0x16C0391380E011D3ULL, 0x4DE545138143F031ULL, 0x2D5311EC8A417DC4ULL, 
            0xEC1FE03850A8BB88ULL, 0x4B375C3B01746292ULL, 0x6907B8269A23C559ULL, 0xC64CC485D81871B0ULL, 
            0x0A6385361A6E95CFULL, 0x4E9F3C78A5B8337BULL, 0x814C1E81E8EF4E0FULL, 0x9F2993444D6BFF94ULL, 
            0x27ADDC60A271A449ULL, 0x23D79DA01C1AA244ULL, 0xAE093A42144D9D2BULL, 0x1DCF092E00B40225ULL, 
            0xC80D4AFAF92C6540ULL, 0xE1A30CD6CC11587DULL, 0x6A62306CE7B5A76DULL, 0x98006C2EB9D83647ULL, 
            0x4B3E1E61E8B1E1ECULL, 0xA20B60BB23679540ULL, 0xA6D6F551C360B3B5ULL, 0xBD7058416FCB0E8DULL
        },
        {
            0x59FA5FF858DFB463ULL, 0xE70CCE45A2B23A14ULL, 0xB74B3086082D16AEULL, 0xAD8AAE861A5DB82CULL, 
            0xE1E135A2341B0409ULL, 0x10F7749C2E191BF4ULL, 0xD4C4194ADA6C84AFULL, 0xF7CF10C2D5207BEAULL, 
            0x6A2CAA4CD8E5DC09ULL, 0xBDEA7768D375D9EFULL, 0x09A964993C49DBD7ULL, 0x31D9B194229B4E6DULL, 
            0x2B0A2E1CFA5BB1CEULL, 0x09AE6E348C722A31ULL, 0x8195BD1D926B5575ULL, 0x8424F06654E20068ULL, 
            0x6B8C09005027913DULL, 0x439E037B2EBD3C57ULL, 0x1ED3AEDE45041555ULL, 0x5805C052A6693790ULL, 
            0x2F9199B445C76513ULL, 0xC0C148CC2820FE72ULL, 0x1126EF40B8594F5AULL, 0x5821616580A96D01ULL, 
            0x15CB5A6035FD475FULL, 0x52C3A790FD4D4193ULL, 0x535B76014338267AULL, 0x46515EDC16AF56C8ULL, 
            0x3ED1E72B5F829EEAULL, 0x11B3AC652F77119DULL, 0x8F830ABA7A30D7BAULL, 0xAC930AD83DF6E8BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeySpawnConstants = {
    0xB3D14F3FA392DE49ULL,
    0x0C7A67D3690A3BF3ULL,
    0x8766D83274E0A222ULL,
    0xB3D14F3FA392DE49ULL,
    0x0C7A67D3690A3BF3ULL,
    0x8766D83274E0A222ULL,
    0x181B38BEDD21499EULL,
    0x7DE2D57E6D0A3F79ULL,
    0x73,
    0xA1,
    0xBA,
    0x1A,
    0xE3,
    0x39,
    0x81,
    0x19
};

const TwistDomainSaltSet TwistExpander_Procyon::kSeedSalts = {
    {
        {
            0x1FE9856054064AEDULL, 0x6BBD01BD29ADA1E7ULL, 0xEC58B6047D61E190ULL, 0xE264F7E985331BD2ULL, 
            0xDCEFFEA233A432DAULL, 0x3F8234D1A0C19650ULL, 0xA22F743C5AFA1136ULL, 0x0DB12B50BBC6A607ULL, 
            0x507274C9ACE0395CULL, 0xF28C2DC78B54EDAAULL, 0x5C61DA41B3818A27ULL, 0x4E139703004C758CULL, 
            0x5B1E1A976AE620D2ULL, 0xE0EDC9147B0E9A96ULL, 0x915DF1F7A728B65DULL, 0xE9568DAFB058BD44ULL, 
            0x1A0FBFB580EEF7A4ULL, 0x67345E7FDFD173FFULL, 0x4DB1E1F284C74BACULL, 0x9B1D6E2FAA367254ULL, 
            0x9CF3A241DAE8F45CULL, 0x1AD05FFF3BCF3DA8ULL, 0x54D6F4E96DDD71F0ULL, 0x0642C7D4264C5B4FULL, 
            0xB0ED523B40864771ULL, 0x2F979E2A50513171ULL, 0x46483F6DDEF02EE6ULL, 0x0A03AB0E691D68FAULL, 
            0x60FCB23C8B518ED5ULL, 0x4ADFF5B7820F1EE3ULL, 0xAEEA902EB5CB396FULL, 0xF3E8ED9F244145C8ULL
        },
        {
            0xF5A79BF06E2571C1ULL, 0x7760BA05120AC7F7ULL, 0xF565742CD123867BULL, 0x36F713E181BACEC9ULL, 
            0x61B64DB4562E6164ULL, 0xC77BCBDB604CD994ULL, 0x0E0DBEDF27734D72ULL, 0xC9F8A1BD9FB17FABULL, 
            0x414E8179E1B56AD8ULL, 0xB2D34AECA4CDBDDEULL, 0xE5CF0A3147C6AAA4ULL, 0x0158C5B7667E6702ULL, 
            0x73C4CD32686096FAULL, 0xFE3684C3E79DAF7AULL, 0x314AC3142ECE40F5ULL, 0xDA5B294D4F6A666EULL, 
            0x14408B779C0E5346ULL, 0x2DC8F49AD0E8CFD6ULL, 0x8A2D6B538C5FC1DBULL, 0x14367F84238F3D51ULL, 
            0xF76CB91F49E16CEAULL, 0xB65447E49062F684ULL, 0xF6B9B81D73470BACULL, 0xB18AF206C02CE569ULL, 
            0x996FB7FB53044E65ULL, 0xF1C1BF34B635D861ULL, 0x66EAA353933EC9A8ULL, 0x43ACA3613D93A924ULL, 
            0x38E183D78690989BULL, 0x167EFA795AABF4E0ULL, 0x10DDC1BE1097AB8DULL, 0x755485327963FD81ULL
        },
        {
            0x4483FE9735D1DF00ULL, 0x00F3187570F732A6ULL, 0xE316BB24AA8405F6ULL, 0x0DA1103B71BCCF5EULL, 
            0x5CF3004CA54074ABULL, 0xF809FE9453433275ULL, 0x9981C892F65CDDC3ULL, 0xE5759A99185CD291ULL, 
            0x102716D0759B2FCAULL, 0x4434CA66088B2E8BULL, 0x94F806F943E303FAULL, 0x577DF16C6C9868DBULL, 
            0x94792A8F2FCD0EA2ULL, 0xB0EC952DCEBE6A57ULL, 0x0494F818A9CD73B6ULL, 0x0E00E203147BFA21ULL, 
            0xECFFCE990BB5716BULL, 0x217370EC8071D9BBULL, 0x7C11D297EEDDC642ULL, 0x403C0BB607AC2D1CULL, 
            0xB2E0F2498E8156E0ULL, 0x73B1EF9B57201B10ULL, 0x8BFAE1A3A6A759D8ULL, 0x6CDB2DE68C4F0E16ULL, 
            0x2894C5F38741962AULL, 0x8CE1D0AB84411043ULL, 0xC4770364217F8DAAULL, 0x2C241E906131EF40ULL, 
            0x07399EA487DBDE49ULL, 0x3E106D7A35F5FCA6ULL, 0x9AE09285E9F6C78EULL, 0x1CFD1BF83D8AB70EULL
        },
        {
            0x7D3F38698A1DB54DULL, 0x3A511798FBE80A3EULL, 0x8C812626C72CF22DULL, 0x2A890380D49755B0ULL, 
            0xF0EC9C03732BDF4DULL, 0xDA6FDD3CB7970325ULL, 0x5C4FBCEFFF2BCCBFULL, 0x17A1CA0E99624EBFULL, 
            0x78D8DF4D356A5E0EULL, 0x900B92B179C9E27BULL, 0xE055E6BD759959CAULL, 0x5DF1C472A5909E37ULL, 
            0xD3D470F7F40A7AABULL, 0x92DC56243D9A7008ULL, 0x964418540B799E3FULL, 0x25B714C956C8F521ULL, 
            0x2F7D1FCAA6750A78ULL, 0xA74895EB9AB79B46ULL, 0x42BF2E9FE1536B64ULL, 0x5331F3C570683491ULL, 
            0x5EE27966A81AA80CULL, 0xDB99B552C35CEE13ULL, 0x50BC8A67D6999319ULL, 0x25D9BDB929E27A53ULL, 
            0x76AE1821DF7DD35EULL, 0x2BCFDF2D3D5AD002ULL, 0xCB35F048AF5CC9D9ULL, 0xC7F92272ED8CE1D7ULL, 
            0xA36A1D43587D0742ULL, 0x507DADC37747694BULL, 0xB22ADE370039F0A3ULL, 0x303B2D8D6BD4037BULL
        },
        {
            0x8E141B135F42348EULL, 0x5CCEC6B81D7C5526ULL, 0x817C9263FA99D933ULL, 0x342710E1E0653489ULL, 
            0xEC0DF975E03F3E2AULL, 0xE20A9208B843B538ULL, 0xF7317E163C27ACDCULL, 0xB8186233867B55B6ULL, 
            0x30EE463A44A24EB8ULL, 0xA06609EC26C1E047ULL, 0xB430D94703966DB2ULL, 0x240820133E92179AULL, 
            0x6BA61DD92E9519A9ULL, 0xBB7D3A003C31BFE0ULL, 0x25D36E88C84B412CULL, 0x0332E3BA57E7B10BULL, 
            0x3F582EF27DF67EFEULL, 0xAE8937C97B804591ULL, 0xEAAD6F7C58F4C933ULL, 0xFED20CE93FAF2B9DULL, 
            0x5D3E79C82493E7FDULL, 0x850EF858E653FCB1ULL, 0xEEE532A9C11218BFULL, 0xF3A4ED46135B7885ULL, 
            0x1F809E8329D14470ULL, 0x31E46B83D1A3ED25ULL, 0x0E569A8A25924CC2ULL, 0x11F1C0815FEC927EULL, 
            0x48569626F202B043ULL, 0x5C6AF4FF7D7157BEULL, 0x85FD7FB14088A835ULL, 0xA37F144B2AB95E7FULL
        },
        {
            0x2BAACDAC3D01C4D3ULL, 0xD72DBBF122F3E17DULL, 0x4B2D9AB6F5D926E1ULL, 0x997E038D904F8044ULL, 
            0x17E9DD1019FC83A9ULL, 0x31AB741C6B0248B8ULL, 0xBE32CCBA203AA2BFULL, 0xD892972438AC4F54ULL, 
            0x5263CB07B27D17CDULL, 0xA0AEF86A467D38DCULL, 0x71E0F3945448AFF1ULL, 0xBCE205183C4B9A96ULL, 
            0x1307B71FF1A5D7FEULL, 0xC5C26B21D0ECB416ULL, 0x53028CADAC832D11ULL, 0x195CB4083A92903FULL, 
            0x8F9722A63FB39D69ULL, 0x279F9479FD85A2DBULL, 0xB075E554D3804814ULL, 0xB77286B1246B4FB9ULL, 
            0xB57F97EE78A7BF42ULL, 0x9D8B0DFDEA4F7892ULL, 0x053410A29EC4BC0EULL, 0x1FA4650FD59163AEULL, 
            0x3613F68EE9E8770DULL, 0xCD57D7BA06D752AAULL, 0x9ED810B323D83DE5ULL, 0x406A8FADC8443064ULL, 
            0x07C654D512224156ULL, 0x0B71883CB45B052BULL, 0xE6491BD008756120ULL, 0x2238959AFC4A32C0ULL
        }
    },
    {
        {
            0x281D17922064AA71ULL, 0xCD034C4A6DCC086DULL, 0x1EB8FB79B245DE76ULL, 0x6C062A8986E46B73ULL, 
            0x6A771AED7532AE7BULL, 0xD5E343B12C91F19EULL, 0xD3E57F733F1007C9ULL, 0x3F00193BEBF89518ULL, 
            0xB764E0238395FE50ULL, 0x1A4CCE0B7266EB73ULL, 0x08F631EE6F8C088DULL, 0x7B3E09F48B390134ULL, 
            0xC1390E6E3EA72BB4ULL, 0x003CFD77EF10B308ULL, 0x2142AEEAA613F5C3ULL, 0x84E6EEBB5F652C5BULL, 
            0xF50D15E4AE2661A1ULL, 0x014B673431EA96BCULL, 0x6A26699C074B5CC3ULL, 0xA0F53EA06231E53CULL, 
            0xCDE7FC872053C492ULL, 0xDA6763EE5CF21BF0ULL, 0x424C6077CFEC38C2ULL, 0xC4F16AB27BDE7955ULL, 
            0x28D66EFE870B2B2BULL, 0xAC4F607B9702BD11ULL, 0x9018A095DAEF4AF5ULL, 0xFF1075FD6C32C08EULL, 
            0xC1A3696A3780A0A3ULL, 0xA794958A9615ED0FULL, 0x8356B28794BD09B4ULL, 0xE81CEC3F55E094CAULL
        },
        {
            0x09A1C09DFB4A3067ULL, 0xB86F165043AE442FULL, 0xADF73D1B856419E5ULL, 0x58F8FABF0EE80EECULL, 
            0x78B3E4863AE12C0AULL, 0x921F596E4BEF72F4ULL, 0xB9CD71C35E5D41AEULL, 0x408273CA9644C9B6ULL, 
            0x5A1E83A8BAF69689ULL, 0xC74F3BDB11AB599CULL, 0x8B58A9BA08257C0BULL, 0x2DC679C807C6FCACULL, 
            0xB9D7822A202CC569ULL, 0x915DB7F93BB6AE4DULL, 0xCB6D38FA4085CDD0ULL, 0x83DAC57EB5902C32ULL, 
            0xB8B2D8CFBB17A970ULL, 0xF7EF19AB1CDA85A4ULL, 0x727FFFBC0B425A37ULL, 0x8C159F145D22DFCEULL, 
            0x2DFF152B39A6A753ULL, 0x435AB2B4016CE10DULL, 0x98E691A9B6ACF131ULL, 0x8ECF2BF35F95AFCDULL, 
            0x8C72EE9C98714DBDULL, 0xC3394F0762DB042DULL, 0x0EFDD507D41FFE4BULL, 0xC5AFCBEF89435C62ULL, 
            0x6CCC9AC4F546A2BEULL, 0x8B944BB09355DDC4ULL, 0xD50E93C530EBE6D7ULL, 0x7FBE0D560FFF1826ULL
        },
        {
            0xACC149BFEBD1E11DULL, 0xCC94A57035FBF8E1ULL, 0xCB9401DACD82BD04ULL, 0x441A89417B0E18A1ULL, 
            0x737AB6D2DF23D60CULL, 0x5435B4D7B0E38B7BULL, 0x9E2C8B6A35A704AFULL, 0x86FDE17171E370F4ULL, 
            0x2BA86DD34F72FB74ULL, 0x2C247268E56ACD15ULL, 0x63FBE70C1AC0A814ULL, 0x2EBFA2098146812FULL, 
            0x16B98E4069ED07CEULL, 0xC19427423C88EE11ULL, 0x71EDB373C3E91E8DULL, 0xBB2BA153D3535E18ULL, 
            0xE75A8B21A9E3F72CULL, 0x2E02DBB8C5592B36ULL, 0x57D5B747530AAF58ULL, 0xDA98E15F9A250872ULL, 
            0x2A5FB289810F7AB6ULL, 0x2005FFC4441298C8ULL, 0xDAAF9F138BCADDF4ULL, 0x9E3B2E7BBE630486ULL, 
            0x851BA471D8E851B8ULL, 0x923153C79D0E06AAULL, 0x1CE4385C85C513ACULL, 0x19C603BAAC8466A6ULL, 
            0x3A936A607A0A3B0AULL, 0x1D09B77BD0B2A3C8ULL, 0x83BF7BB92163C15FULL, 0xC2830AE04B190F04ULL
        },
        {
            0xD1C067B9E31C62C9ULL, 0xEC4906BA2E11EB7AULL, 0x65123480E0AFFD5BULL, 0x651B8D0CF5526267ULL, 
            0xC75E85C8D6103B48ULL, 0xDB54558740D6834DULL, 0x57C6B87CE5D171D0ULL, 0xA16BC27AD249E3BFULL, 
            0x4C6949A368E381C0ULL, 0x10E916B82318CBC5ULL, 0x7269375E5A37FE0DULL, 0x76E8183A9C4A194FULL, 
            0x905187F064C6D5ADULL, 0x310B5E890066C1F2ULL, 0x82C8EF2F010CE2FDULL, 0x3DF8A5D395A5087FULL, 
            0x2AD6E9CFEF8A7006ULL, 0x05FD3425ED6643B2ULL, 0x35C7F5623C563F2DULL, 0xF6A94700D43C5980ULL, 
            0x2FCA98F54B855AFBULL, 0xC1A015AA0B0148A8ULL, 0xDD8682090FF7C0DBULL, 0x65C4FF2286E7B756ULL, 
            0xF74D12ED4C574056ULL, 0x401BEE767E0EA107ULL, 0x33D60122F0080A08ULL, 0x604497648CF6097AULL, 
            0x9987613E780F5190ULL, 0xC9AA38730B2A59E6ULL, 0x5E3D833F4FCC7E8EULL, 0x036131B77EBDF44EULL
        },
        {
            0x1E478E2FAA10B521ULL, 0x9E2DBA8E6A263098ULL, 0x280A674E11F30F70ULL, 0x1C9C482968A18152ULL, 
            0x5558F888CE8751E8ULL, 0xB9AAF3459F0818EEULL, 0x164BF51BEA7F7312ULL, 0xE27A1719F9EF2A32ULL, 
            0xB3B0200FE9E95FF0ULL, 0x73239A0FECDB7116ULL, 0xCA13AB197968A890ULL, 0x67A8D763B66AC555ULL, 
            0x7E5642EF7737C185ULL, 0x4AB57C222ED72EC5ULL, 0x78A51ADFDCFA1392ULL, 0xCCD8EDE4A67B2966ULL, 
            0x2FB2328E0931EBC1ULL, 0xBDC14EB3DAA295C7ULL, 0x25A0F8D82D5543EEULL, 0xD12FECE5205271C1ULL, 
            0x4FFAE90E082A7117ULL, 0x85E6E18B80CBA371ULL, 0x910EED59BC779E3EULL, 0xB12D6BDEE4394964ULL, 
            0x7551F28ACD359D72ULL, 0xD5846CE0750A1F0FULL, 0x2AF993D4A279EB8FULL, 0xA0759F39B3EBFD1AULL, 
            0x3CB226946AC3DB3CULL, 0xE59FF30CC353A207ULL, 0xB02DE02C21D9AE6AULL, 0x457CB5B6BC9E2762ULL
        },
        {
            0x223F1E4536365614ULL, 0x02C2C6152EA393BBULL, 0x800868769F59C13CULL, 0xEF3845FFC20D7A7AULL, 
            0xB0D9369DB04BCD37ULL, 0x3620A80EEFA0DEF9ULL, 0x881893F11889D08DULL, 0x65B910507912B2ECULL, 
            0xCC2A6A7A00067867ULL, 0xD5FE5BF77933E2DAULL, 0x8D54CE035585E79DULL, 0x8A10E8D051973F95ULL, 
            0x0093243DC860B857ULL, 0x1C1E0835C5014F1BULL, 0x05F0C1F338673046ULL, 0x023E9802DA800182ULL, 
            0xC7721E428889406BULL, 0xFB68C6FFCA43A3B9ULL, 0x2C87079BA6013B5DULL, 0xAC9D8BBC8BCAB0F9ULL, 
            0x17407E9AF4ADD103ULL, 0x888F7655AF9F1255ULL, 0x39827D58157FB8B1ULL, 0x1E944BD4A26B14C7ULL, 
            0x6511C934F315CE90ULL, 0xF39A67F04401F294ULL, 0xEF365D1B805A9FD1ULL, 0xCBDF31524B9DE571ULL, 
            0x3E97773A294D9C1FULL, 0xE8088427ACB3D545ULL, 0x0382702CEABC1FDCULL, 0x38D98715EFA9A603ULL
        }
    },
    {
        {
            0xA8482A18FAD2E9BDULL, 0xBC67AE2863CF2D8AULL, 0x1505505D5B8A9909ULL, 0x85B9D7126C3A4D21ULL, 
            0x622AB55038CAFB79ULL, 0xD28AFD3310890196ULL, 0xDB5DC2C0D3A135B5ULL, 0xA14809A8F1577BFEULL, 
            0xB7168549C1B78BD9ULL, 0xEAB6DA385940B5B8ULL, 0xF00DD491482F3DFBULL, 0xAE9CACB808799031ULL, 
            0x91E2A26EC00D4BE2ULL, 0x54BD28FDB1FD4691ULL, 0x800A55DAA87B96DFULL, 0x28EA718EA1F5D4D0ULL, 
            0x4C063543689D8F52ULL, 0x9EF5DC31C4308A6EULL, 0xCE421F46C0D6C2B9ULL, 0x021702E56E513FF6ULL, 
            0x53E52E8CE7209DEFULL, 0x07A7F4169DE16B30ULL, 0xE80D8AB7AB84A0EDULL, 0x06BF64EDDF6F94EDULL, 
            0x88DB7F3084324D04ULL, 0x03F7DF18CA9F5181ULL, 0x8A1C5CF191D1D8A1ULL, 0x748652E9D805A7D6ULL, 
            0x9707E40D7E475BC4ULL, 0xF396BB701878A1A4ULL, 0xA1DEC9BC1B8D17F0ULL, 0xD56C53077DFF04A1ULL
        },
        {
            0x5C646B0201250D66ULL, 0x39B3C05AD986FD5AULL, 0xBE64DA7C39EEE390ULL, 0x6EFE295129F2DCA7ULL, 
            0x457E5DF8B85E7F23ULL, 0x3C19ED319CD710A9ULL, 0x36D0D84910499096ULL, 0x31FC1138DCA392FEULL, 
            0x81302BF5C195D021ULL, 0xB879B440E9ED1CFAULL, 0x2E7254A8BCE221DDULL, 0x540D46F08B248099ULL, 
            0x87883BFFA9EF461FULL, 0xD953662E2744EE23ULL, 0xB8A7ADE50C179E35ULL, 0xDB2C873A8741A3B0ULL, 
            0xCE59DAB6A254E9D1ULL, 0x4A7E7654DD6281D7ULL, 0xC400296AE4225970ULL, 0x9719CD8AD2747B5EULL, 
            0x13FD51B50DC382E4ULL, 0x50EB77D8F7DFC08FULL, 0x7936FD981605DC6EULL, 0x0D4B81B16A5D7E1BULL, 
            0x0804EC6B730FF531ULL, 0x360F80EE8397247AULL, 0x0020F80AF20A6C13ULL, 0x9C73A5D07E65A8B3ULL, 
            0x9A3506B66A0B2878ULL, 0xA5FCAC0E3EF3A463ULL, 0x697A6F148B27A3E8ULL, 0x2811DB3FEF4E7785ULL
        },
        {
            0x6E1EE452920DDDC4ULL, 0x72288A2A7BAD6EE7ULL, 0xAB12A2211D9378DFULL, 0x0710847F3341677CULL, 
            0xCEF7FEB470E1F503ULL, 0x1AD192E3704EE1D4ULL, 0xA67F7075629A2C49ULL, 0xF1844576B97BF541ULL, 
            0x471A9433A9F17CB1ULL, 0x7E783665ACAF5FB8ULL, 0x91611901862DF17AULL, 0x093F275093967D10ULL, 
            0xE5211ED30B1278B6ULL, 0x59362FF8A309DBDDULL, 0xFEACF49B341EC90EULL, 0xD20A486C3EBE15E3ULL, 
            0xC1B675891CDDC66AULL, 0x6BCF16751425D93AULL, 0x925B292FBDA284F3ULL, 0x709A4ADAF3DF7CBFULL, 
            0xED4CD54C93709560ULL, 0x634A6B8092A73560ULL, 0x929EDC032D67CF32ULL, 0xEB04E54E480B511EULL, 
            0x3594D5EA6D86DB1EULL, 0xD96E2D09C7C87DCAULL, 0xEF43107FC69249D4ULL, 0x1DF6E9DC0D2600E3ULL, 
            0xF09EC47BF34CE063ULL, 0x9815C48590BCB61EULL, 0x13BB877BF16CE524ULL, 0xA45A07955D26471FULL
        },
        {
            0x77A29475F479577DULL, 0x97965DD3795FC64FULL, 0xEC48B772C6F0A805ULL, 0x356F3E90D8D6ECD9ULL, 
            0x3B4987E36D19548CULL, 0xE3A8D220C8BFF197ULL, 0xCE6146D3EE00440BULL, 0x87A00DB8CFF307DEULL, 
            0xC2333869E2635AE3ULL, 0x4AF3E15AE7D96122ULL, 0xD7CB4DB7E5ACA24CULL, 0xED1E4CA80CEFC967ULL, 
            0x530BEFA7787AB2E1ULL, 0xAD4F748649E197DCULL, 0xF77220F825924255ULL, 0x82FB36140E738C4FULL, 
            0x53FFCACB8337735DULL, 0x82888DB8292EB66FULL, 0x1FDE13117137EE34ULL, 0x1679202FBF4ECBDCULL, 
            0x8DE6AB19A0EAACFAULL, 0x63305896B01B39A6ULL, 0xF322F2257FC1FBFAULL, 0xA5DAEDE98AC11371ULL, 
            0xC9837345E1DC7AD7ULL, 0x48B0E606016DA6F5ULL, 0xE56DF331714E6439ULL, 0xE47EBBA4A3CBED70ULL, 
            0xA66F2FE24BB71138ULL, 0xC680515D8DA8978FULL, 0xEF81C373B1307D8BULL, 0x6967BC0C0005B07BULL
        },
        {
            0x4D66E14354A6A3EAULL, 0x2566F3F1A06AF11DULL, 0x62D684BD74273579ULL, 0xA484305781AD3FA1ULL, 
            0xC4538214CA18161FULL, 0xC9CFF71B04725039ULL, 0xE8B896D312FFF4E5ULL, 0x7746030C43BC6983ULL, 
            0xF07E6BCE64B665C6ULL, 0x3628B10D88135BC0ULL, 0x92CF292322896511ULL, 0x36FCAA5369233C6AULL, 
            0x821A4BA81BDE1DBBULL, 0x8CD852946A2C28D1ULL, 0x31927A7A60FA4929ULL, 0xEB3F50978DC1E3D8ULL, 
            0x2D5F79C69A67E348ULL, 0x0C7DEE68974E3C7AULL, 0x921F2465D51EA75CULL, 0xDCDF40445ED958C5ULL, 
            0xF2B084E572D307DFULL, 0x0559DDFD0738576BULL, 0x94359AD8A1913A91ULL, 0x4DD6F4C909ADD43BULL, 
            0x4397FA23DFB8B471ULL, 0xE73B27B497609CBFULL, 0xF0D820625A0F060CULL, 0x808740A09F8732DFULL, 
            0xD387A2EA36FF99DDULL, 0xC518938FAA626438ULL, 0xB3D4D06AC3CDB3D3ULL, 0xFBFB8C5E0444092AULL
        },
        {
            0x9181D1C82D0D3CD7ULL, 0xF4C29B1DCE918D11ULL, 0xB28ECBBECFEF3B15ULL, 0x0A0AEA9D26A45338ULL, 
            0x855AF022A63B9D82ULL, 0xD65853C849D52C85ULL, 0xA1FEF3DFDE441ECBULL, 0x967EF587557962ABULL, 
            0x3EB3C5ABAADAEAB9ULL, 0x0A089DF12843E028ULL, 0x59C2F422EEAE9C17ULL, 0x604D65FB7B227DE3ULL, 
            0x54F05D0011E71CDCULL, 0xD15E723E542C5A26ULL, 0x707389CAADA4272FULL, 0x8006116B6861D8CEULL, 
            0x122D804F2F076232ULL, 0x0EF9C4A72C09EE3FULL, 0xBB3836650C91E9DAULL, 0xCFA7EFB28DF5CEBEULL, 
            0x54C024BC0FEC47BCULL, 0x126D6CA501495C21ULL, 0x6785897FD80D45CAULL, 0xFF67E57EA8D04492ULL, 
            0xEEB6B48D025CB096ULL, 0xB17F3ED7B60E08C8ULL, 0x2BCA39A8448BEA3AULL, 0x64E58F30C4BD6C60ULL, 
            0x9BA8A65F09476BCAULL, 0x7155443A0246B25BULL, 0x80AE7649AAA9E14EULL, 0x22D9BAF85DFEC161ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kSeedConstants = {
    0x99F02F1281618850ULL,
    0xA5CD16EBC6E66D78ULL,
    0xE4BBCF705D5CB638ULL,
    0x99F02F1281618850ULL,
    0xA5CD16EBC6E66D78ULL,
    0xE4BBCF705D5CB638ULL,
    0xAAF358B918FAADD0ULL,
    0x0C7953BD06FCBD9DULL,
    0x7B,
    0xAD,
    0x9F,
    0x4B,
    0x85,
    0x32,
    0x88,
    0x52
};

const TwistDomainSaltSet TwistExpander_Procyon::kTwistSalts = {
    {
        {
            0xB097865BC1D2963FULL, 0xA95A60BEBCC0133EULL, 0x4B474BDB0A0A6AFEULL, 0xE7BD11D0AFA77B1EULL, 
            0x38E63839B22FAAC2ULL, 0xD135C9D353058EE5ULL, 0xE6CB69C82A548B41ULL, 0xBE1BA297508D4655ULL, 
            0x1AE1ADE1ADC55824ULL, 0xDF849C297D847128ULL, 0xFFDEEDF50D4E60C2ULL, 0xD3BA9699164F4E71ULL, 
            0xDD6B00A29C9C0433ULL, 0xC599D0C209C9E899ULL, 0x9601137518EE7695ULL, 0x845B4BDC3ED4381BULL, 
            0xD47F35BDA62BBE9EULL, 0x04CB1C026DC13A2BULL, 0x0446E560AE600588ULL, 0xB5DF84BC7D6E56D0ULL, 
            0xD41AC5341B2E773BULL, 0xBE627BC591A05916ULL, 0x549AAB3BEF0830F5ULL, 0x58B02E0FB8991922ULL, 
            0x74650B4215128FE7ULL, 0x018B1DAFD74DE10CULL, 0x360EF58C60101085ULL, 0xFF43747118D6470AULL, 
            0x3A90184911F825C2ULL, 0xC7B2ACE12D27A2A4ULL, 0x0EE46478FC0B3E21ULL, 0xB265D214F741A3AAULL
        },
        {
            0xED8D4C7517BAA2BEULL, 0x3BE33A80368B1628ULL, 0xB7FE6CD33682FBD7ULL, 0x520E722468474680ULL, 
            0x937E3336D4A5A1DDULL, 0x7F32222CF07FC82FULL, 0xDE0C98F706B97C4BULL, 0x9229284BB941C3CAULL, 
            0x8FE01F144340A602ULL, 0x9406D74DB2CFD152ULL, 0xAC276C56E60B12FDULL, 0x3C84CC103BD47A80ULL, 
            0x93D5D75F3BEFBD1EULL, 0x18FF6E9B45612481ULL, 0x898DACCF49B14A9FULL, 0xA4810E9FFB916550ULL, 
            0x081C8047B1AFCA4DULL, 0xA5C569398451F109ULL, 0xD43CE1B545E8120CULL, 0x64C8835B3984C491ULL, 
            0xB68DA430C36859C9ULL, 0x8C7F10DDA7EA8619ULL, 0x3302F0F23E71E77DULL, 0xA63C47E7BCF0A0A5ULL, 
            0xCD14453F51684F19ULL, 0x05D91BA7235150B0ULL, 0x6405DBC9EA94A9E4ULL, 0x9F40DF25536D83C3ULL, 
            0xBF61F7959277C20FULL, 0xFB98021F7D76D41EULL, 0x29FEDF3F393864CAULL, 0x7105FB28B35512BDULL
        },
        {
            0xB8B095F2576A59D9ULL, 0x8789710A66701009ULL, 0x08C61DCF34588547ULL, 0x7588FEDE7CB6F39AULL, 
            0xD5E0F5DFA2863436ULL, 0x3D6AB6781C2B884AULL, 0xBE7084ADA5AF3CECULL, 0x3660E35758B456AFULL, 
            0x42E1477879149162ULL, 0xB2AA833BAAB60E94ULL, 0x8F6F208A3A5BEBF5ULL, 0x3B2A8268DE740ACFULL, 
            0xB68D84E424C7CBE0ULL, 0x1BCA0FC971C79B1EULL, 0x5E182D53B83B9C9FULL, 0x3FD2BCA4F4B8587EULL, 
            0x5D32DC4492820188ULL, 0x62CA04A523D806A2ULL, 0x1904E914C132C96DULL, 0x5FF34F48826BAF49ULL, 
            0x5EE152A964B5499DULL, 0xC8D00D4AB5A59221ULL, 0xFA0C5DF8293E926AULL, 0x628D367C8F71BAADULL, 
            0xCE7BF3A718C9CFF7ULL, 0xD7A0DFC1A6EAD969ULL, 0x3E1C4FE189865348ULL, 0xE674799965DED10EULL, 
            0xECF5752C4B6924E3ULL, 0x4FCFD5F4BBC26803ULL, 0x57D7FE367ABDDBDDULL, 0xB0B129C4791891FCULL
        },
        {
            0x94E04F94587645DAULL, 0x2F5A879CCDF83063ULL, 0xA1C19866188E6FC5ULL, 0x513750514D4DA294ULL, 
            0x6994A319496926E8ULL, 0x74DEFA3E263A8048ULL, 0x2D6B297E80D9FDFDULL, 0xF90AA9A1A2DB1FB5ULL, 
            0x21E0DDEAC0FF9AA9ULL, 0x9AC1C3A4F8074AAAULL, 0xF5FCBCEF26BE4DEEULL, 0x70BAA06BBE35297AULL, 
            0xF64A08815D090855ULL, 0x5A8B8AA92EB7E0C6ULL, 0x61337DF5B834B5E5ULL, 0x09481A354529096BULL, 
            0xBA9ECAE5C118D5EFULL, 0xC0C4C47D889687DCULL, 0xE779DE559B7A8338ULL, 0x33C3127CB030967CULL, 
            0x44AB36F0BA9ACC54ULL, 0x935E716BF0AF5B98ULL, 0x619CEB2BD8FCE93BULL, 0x3B4998908C24C2EFULL, 
            0x5BF809610C5100FAULL, 0xAE04B4F4E8115DC6ULL, 0x5740B485BE7D0F22ULL, 0xE97BB28211CECCC2ULL, 
            0xD25BBB4231721A6AULL, 0x4EAB2CCC38293E73ULL, 0x5E41B714BF9108ACULL, 0xA6636C794EA22232ULL
        },
        {
            0xCC8151E8CD15F0D9ULL, 0x74D787CD647B8E89ULL, 0x9C8E06B5B820AB9AULL, 0x97B37B0BB74F24ECULL, 
            0x85DA326B90302263ULL, 0x90728D7CD90DEA22ULL, 0x3FF532C032485834ULL, 0x87252E286A0A2E18ULL, 
            0x711E6019AD429214ULL, 0xF66650112C440A90ULL, 0x9C1D84DAAF4EBE02ULL, 0x9B3E3191E9868E9DULL, 
            0x6A15B409ADBED6D6ULL, 0x5EFCBECD5AED153BULL, 0x963A59047B10846CULL, 0x377D05F317165F45ULL, 
            0xD0B14235AACF9E3AULL, 0x42E0B148C7BA4C70ULL, 0xB9CCE1E08FC5927BULL, 0x6BD605BC14C26D41ULL, 
            0xA91C996D3EC49C94ULL, 0xEBE2D07EB93344F4ULL, 0xCADFD9E81416AC00ULL, 0xE062072710E4DFDAULL, 
            0xD12117C1DF7ABB19ULL, 0x4FC5DED2230EBACBULL, 0x9DC059A35DD12E65ULL, 0x11D3ABD039CFA731ULL, 
            0x066DEBA875454210ULL, 0x2183C81DCBA844DDULL, 0xB3C9DF19DE5CB42AULL, 0xF10FF4CECE41AD37ULL
        },
        {
            0x71F24DD8878AA02AULL, 0xF75B91FC71744BB9ULL, 0xA33945C2F72696D6ULL, 0x7A47604193DFD7B8ULL, 
            0x465F40B69B37B6A4ULL, 0x5F78999ADA329B02ULL, 0x1B1DA54E2E9C9D49ULL, 0xB0D6292E85BCA9EDULL, 
            0x82D821494936E5C5ULL, 0x1930FC86A358F976ULL, 0xCE8FB889E066D164ULL, 0xCEC995CF214AA54BULL, 
            0x388F5F0703FDBD6DULL, 0x7E91199FB50D0E5BULL, 0x92682A4886D9D1DAULL, 0x535D2D73A3881BF1ULL, 
            0x23030DA7B5909FEAULL, 0x9495A581AB36CC86ULL, 0x2FD1CB29063641D2ULL, 0x79788589FFC7100CULL, 
            0x3F47331B99BA117BULL, 0x53DD0DFED3DB6545ULL, 0x448AD7BD2850D510ULL, 0x45CBBC5C1C3CC023ULL, 
            0x98704B113E1E767BULL, 0x3F5C261B5A248F91ULL, 0x25E4A96E67E3DD30ULL, 0x92330D257D50A075ULL, 
            0x1690B1D0CA6DAA43ULL, 0x23EB1615CB1A8CE3ULL, 0x8B3DAA4C808E247AULL, 0x99714B9F6E2AC733ULL
        }
    },
    {
        {
            0xD13628D55641A004ULL, 0x19B4C58177DFF1A5ULL, 0xC32B79E30322A24BULL, 0xDF69E6D00B7B4A74ULL, 
            0x73D98AF01FB462E4ULL, 0xBF88217308B43760ULL, 0xEE426E0115CC755BULL, 0x8145F5B4EC29B444ULL, 
            0x670B1339F0FC677FULL, 0x9D6DC1F0143DF0EDULL, 0xA50AE43E4160E4C0ULL, 0xA7E2377134139368ULL, 
            0x63768B6CB06BAD27ULL, 0x6A5B1D666B085B61ULL, 0x1B4EF3B01CB44AFFULL, 0xA981BB21B6E11894ULL, 
            0x7FDC2375682DE393ULL, 0x3698420FD2034C95ULL, 0xEC1F9534AD07B7CDULL, 0xC9092EC1700EDEBFULL, 
            0xEA7BCECDD2EA42B7ULL, 0x9E0223888A39E8F7ULL, 0x241B2DB4078961ACULL, 0x4DC8BFE0BD15DB6FULL, 
            0xE6E99F1EAC065587ULL, 0xA069F98F6C3BC5ADULL, 0x71BCC9423AB7B15EULL, 0x1BB48374752F8220ULL, 
            0x1286AB7D2739AF99ULL, 0x6AEA0D0E15BC314BULL, 0xF30FBFB1C87606D7ULL, 0x2F0F60D282836A69ULL
        },
        {
            0xD1D02E287F8EFB97ULL, 0xB5A24258485C8DF3ULL, 0x4853803DA10BCC12ULL, 0x237A8C1B55886E3DULL, 
            0x38555910CC03B705ULL, 0x3E68F59847A0F173ULL, 0xCF84A1BA788DF479ULL, 0x73A3E88D89DAF72DULL, 
            0xC6F19BD6C2AEE0C7ULL, 0x25BB9A2E8AC82819ULL, 0xE810C20A4B98321AULL, 0xF6A3C33059193551ULL, 
            0xF937B77625F11DD2ULL, 0x13886674A7530650ULL, 0xD621DC65D77295FFULL, 0x5A71A8AA7CC1D6C2ULL, 
            0x6C04D0811EEE21A6ULL, 0xF7AA7CF06C8FA8A2ULL, 0x5941AC649C6EA4AFULL, 0x745C63D4C8634884ULL, 
            0x70D9564581F285CDULL, 0x057160658FFA8DD8ULL, 0x325A47215212FFE6ULL, 0xE172BB5EB0791FD9ULL, 
            0x3E9BB7E316657134ULL, 0x4705384D9D36BF72ULL, 0x23C5A9DC545E05F6ULL, 0x0AD845953CFD3BD9ULL, 
            0xF5E35503EF10E82CULL, 0x01A7E2535A7F2030ULL, 0x036BECE29AF24E70ULL, 0xBB55DA8C4537E321ULL
        },
        {
            0x97665E487EEBA8ADULL, 0x26D16CC56F031EB2ULL, 0x90511A1527C8042FULL, 0x9DE75CBC36E78FE8ULL, 
            0x2626F04E30BA1987ULL, 0x03A7C4F21015D204ULL, 0x0C1E8453C7EAE31BULL, 0x374DA0AA6A9B9A80ULL, 
            0xC7AB33E6850F2115ULL, 0xE2E3D9C29FF1B90EULL, 0xCD090933958700F5ULL, 0xEE6B5D3F4CD318C4ULL, 
            0x1FEEBB9E45334EA9ULL, 0x9C4D810157CBE142ULL, 0xE9ADBA23E8143678ULL, 0x9B2F3CF00BFD3F21ULL, 
            0xA3A0CF517B77A6BFULL, 0xA42D9B7D55E64A67ULL, 0xA7FDF8CD5824B21EULL, 0x6ED26DDC8C04DDC5ULL, 
            0xADEDF966274C3430ULL, 0xAC350FF4739C380FULL, 0x177708A2E83D7D88ULL, 0x63DB815795322234ULL, 
            0x9995C79926EF116FULL, 0xB58FBFBF44A1DB16ULL, 0xAF513000294E92DCULL, 0xF45DDE500291C7CDULL, 
            0x1013087393AEAD03ULL, 0x30E3C0378D0B37AAULL, 0xA6DFA7574A08302CULL, 0x93B31208B48261BCULL
        },
        {
            0x3DDE43331C9CFA67ULL, 0xBD9E02C7D3FF0E1DULL, 0xDB2D69053E51560FULL, 0xAF65B6D7F32585F3ULL, 
            0xE36332DAA3E2B4BCULL, 0x91C0694F057ACF8CULL, 0x23377E9051C42DAFULL, 0xE1383D6601DE2058ULL, 
            0xF09D8F991D5764C6ULL, 0x429B0BB630357E99ULL, 0x05D20C27C7520D4AULL, 0x642323A8BFCD8D5CULL, 
            0x548988D31225DE43ULL, 0xDFDAB8B9724FDA1EULL, 0xF058128FAF093149ULL, 0xD99E55D76C0BE758ULL, 
            0x7968DF11EA98DD66ULL, 0xC3F86758F862DD05ULL, 0x4A6957356D38E2C9ULL, 0xBC6FB9D69DAAD6BAULL, 
            0x52A6E67DF6813C1DULL, 0xF43EFBA150DF6F1AULL, 0xD27909B0EE7C5298ULL, 0x958CE2A2284B6F6DULL, 
            0x81CAB0B27B03B40DULL, 0x3FBCB9BA4ACB6519ULL, 0x174B670A390F06D2ULL, 0xB0DC2B13D10293C6ULL, 
            0xD67A77072C303170ULL, 0x794DAE5D985BCC0CULL, 0x63C547EB92B81687ULL, 0xB3E33BB01E0BD17DULL
        },
        {
            0xEAF74603C4EF5673ULL, 0x6823637EB5C4D73DULL, 0x2E718102CA5F21D7ULL, 0x1318BED7203B493AULL, 
            0x5808E5AFEA8DED6AULL, 0x4122D1A37DB1A7B7ULL, 0xDF6E625B1667D572ULL, 0x22E72BA25AD1115EULL, 
            0x8D774BADB2199509ULL, 0x74B3F5DEB531BDA4ULL, 0x328FDE38153D9768ULL, 0x89613633CBEF25D1ULL, 
            0x846A58609331F7AFULL, 0x42293A2C3F8E20F8ULL, 0x299838D7EF904E1BULL, 0xD6947D64CEA7789AULL, 
            0x53A051F4CF147855ULL, 0x02650D8A37C2E54DULL, 0xF453CFA02EDC20DFULL, 0x9CD2047FBDB7B15CULL, 
            0xCF7CC92101888DCDULL, 0xD0EC16BCDBD66EFEULL, 0xC70C2927B7948A02ULL, 0xE01BD6B55DFB29F2ULL, 
            0x8BB6613750486CBDULL, 0x2B1F0F51EF30AFCEULL, 0x8DF55836BBCD1781ULL, 0xA1E650B62629DA7AULL, 
            0xAFC6BE8FA68BB640ULL, 0x0FED200FEF885DB7ULL, 0xC94906E5A6A06AACULL, 0x14CEF6F5FDE81344ULL
        },
        {
            0x6D5CE1855EE014CAULL, 0x4DF60DD28074D9C5ULL, 0xEE5B7427F75F7310ULL, 0x4C9D0CEF6450790CULL, 
            0xF55CF736FFB77A42ULL, 0x803DB2EFDB171D49ULL, 0x506D5C4EC4A28ED8ULL, 0x61275E1F3E93F413ULL, 
            0xA17086B996C145F4ULL, 0x76B11ECE3B5C41FCULL, 0x52305608B8C4C9E9ULL, 0x8BF1598537031A07ULL, 
            0xD1A12C2559C3B3C5ULL, 0x7D8B641780277435ULL, 0x547C41A977EBE57AULL, 0x9418F57EE7C1D207ULL, 
            0x302F90022E399BA6ULL, 0xAEA627BDA429BE3DULL, 0x849FB3DCD625EF5AULL, 0x3B6AA26591B02C9DULL, 
            0xC435EDF823C135FAULL, 0x5013EE14A9665A1DULL, 0x6283F3872983473EULL, 0x87CB2FC6C32B0F6CULL, 
            0xF45DA77DEA8995D7ULL, 0xBF056D90234BEF62ULL, 0xC3B7204BEE63DB6FULL, 0xD9F1D37C014813AEULL, 
            0x0E33B9623FF78287ULL, 0x854DE5552BCEABB6ULL, 0x85BD942CC12BB020ULL, 0xF1CCE694D809F2F7ULL
        }
    },
    {
        {
            0x86EB3E3A6620A085ULL, 0xB836971A22551957ULL, 0x02A38C44424C52A2ULL, 0xCFCAE7D823B786C2ULL, 
            0xCD7BE8FAFF3B2A83ULL, 0x97C940750F11E045ULL, 0xAECCDDB98251529CULL, 0x8977E40A008E94CEULL, 
            0xF7C76A87DB6BFE7EULL, 0x31AEFE4FAE354706ULL, 0x719C1DAF0C167ADFULL, 0xBA009F458978E399ULL, 
            0xE3819D9658C45865ULL, 0xE4128EF1E6E3A5EAULL, 0x669CBBCA2DB3EA75ULL, 0x5864FCFECB657296ULL, 
            0x94A95230A6AB5560ULL, 0xF5F0A627F9873540ULL, 0x5E3186DD27A8AC4EULL, 0xF5111502BAF44754ULL, 
            0x669E3B831AC9DC7AULL, 0x59515EE0201B4C06ULL, 0x765F55AA04BE5162ULL, 0x9292FA81995D2CECULL, 
            0x49268266E1C290BBULL, 0x52F6AAC97B5BEFB0ULL, 0x3F7DD7840386978EULL, 0x9E6C523369DD3E0DULL, 
            0x185A572384F96058ULL, 0x85E700060928C46EULL, 0x3C10F9BAC4F8F6D1ULL, 0x51A299E135CF2313ULL
        },
        {
            0x322D9510C886FBDFULL, 0xBD2B6AED5F05A2F8ULL, 0xCB46B88449EAC8E6ULL, 0x93F6460BE14583F1ULL, 
            0x167B2A91ABF30E24ULL, 0x2596E8997E267CE5ULL, 0x301F2488A2C37BDAULL, 0x9DA4DEC095A27C18ULL, 
            0x05FE5C197BF83642ULL, 0xD4DDA1549D8283A0ULL, 0xA3E6276F7331D6F8ULL, 0x180DECA82A81BBCBULL, 
            0x64FC853B29D6BC3CULL, 0xEC33E73B3BCB0228ULL, 0x3E68ED0B158B6F47ULL, 0x676DF321F87AA307ULL, 
            0xCC03B0275CDEECA1ULL, 0x749867B29C5C230CULL, 0xB468FD11D790337CULL, 0x4646D4E9F61F38EFULL, 
            0xF45088A3B2195592ULL, 0xD053610E8B99FBE9ULL, 0x3AC2CCE3F7A6EB51ULL, 0x80582F9AE00C4FD3ULL, 
            0x9BA62B468B63FA74ULL, 0x53295FBC392C0338ULL, 0x32A339242D5D8055ULL, 0xA80B768EE712CB11ULL, 
            0x36CE33E60F394E79ULL, 0xFD90105A66584C49ULL, 0x2D9EE1A22D1584A5ULL, 0x053D3527AFE52382ULL
        },
        {
            0xA9168F1FC21AAC4FULL, 0xD722FB6F863EDD39ULL, 0x616DF8BAFD46A86DULL, 0x90EE7C08AEFD243AULL, 
            0x348EB7C132E0C103ULL, 0xC162A58C75D5D985ULL, 0xD2DB07F55EF33F50ULL, 0xDD8BF1FA394E0172ULL, 
            0x7145B3D225626C48ULL, 0x2F73C6A81F22DD03ULL, 0xD46558B4BFA0DCC2ULL, 0x68CD7BC1823ABDA5ULL, 
            0xB67A0DCC9DA58A59ULL, 0xCFC88FF7E664371BULL, 0xE4E2D7F94F33E152ULL, 0x42F6B174807AF3BEULL, 
            0xAF20F38216AE0E4DULL, 0x2E0E62F0F6CCB2DFULL, 0xAC5A52237748DF19ULL, 0xFAA809F69A064493ULL, 
            0x12B2B2EC3161AFBBULL, 0x800F3C02883FCFFAULL, 0x4EB49C4BCE3D60DCULL, 0x3D53BB5B39C43333ULL, 
            0xAFCEE25ED02E6EA2ULL, 0xD7B36A760A6E3879ULL, 0xCA6A69CF2AE0AADAULL, 0xF9CD222F46A62E66ULL, 
            0xD6C50AD12DAEA4B9ULL, 0x736DF21AE55A9F1CULL, 0x5AA9E021FE4BDE52ULL, 0x6A860A12367B4725ULL
        },
        {
            0x479D909D6D821E7BULL, 0x2843F739C3EC8E33ULL, 0x78E85B92DAF8A2F1ULL, 0x4FB239BD9A231C6FULL, 
            0xB96904D19DEAE032ULL, 0x5C735F49480A55F9ULL, 0x6282D428B8672FDEULL, 0x4079D62EC967FE8CULL, 
            0xA83E1641FA62348DULL, 0xDCF776AA90B557D7ULL, 0x814BF79E596ABEF0ULL, 0xE94D87FA69F65864ULL, 
            0x033BFE211023BA03ULL, 0xF19B554F3BB7B8F0ULL, 0x66D0E744FCF8743BULL, 0xEDE301C8C6CAE7FFULL, 
            0x28AF9D8E651B1168ULL, 0xAE2A549E9BFA2F42ULL, 0xC87802BEE14FF120ULL, 0xBCC448215E8DCEB5ULL, 
            0x0BF8727FE8714E27ULL, 0xD0761BE444C3E184ULL, 0xDFA0766009C084F0ULL, 0x94B21F001D8A1112ULL, 
            0x2684AA42BD478814ULL, 0x18A3E771157BE1A1ULL, 0x4E35A0135E63A488ULL, 0xEA0FC9892029D648ULL, 
            0x902E20A85468C3D5ULL, 0x7791C86A71599124ULL, 0x6C5EE6BC42834514ULL, 0xF8B0DEA262BDDD5FULL
        },
        {
            0x3C23CFF36C04A544ULL, 0x239BC49A7E9C64C8ULL, 0xC0C414AB0BA54084ULL, 0x350DFD2102DEAB5BULL, 
            0x5A7BABB6CB267C7DULL, 0xA0A6B32E10132A71ULL, 0x353866477E8E5EDDULL, 0xA504FC2F89B1341FULL, 
            0x767211FD96306647ULL, 0xFB1CBDEFCA511A14ULL, 0x6526DCF54B06D665ULL, 0x161C0A2F50DA45D1ULL, 
            0x814EC79AD0E3B248ULL, 0xE01CDC8E496EC7DCULL, 0x541FE82BCCDFEA3DULL, 0xF96CD1B071F5E78EULL, 
            0x84B4D2B7A948D70FULL, 0x31C97FCDDF00C508ULL, 0x9F8D35CA92813DC7ULL, 0xE2B0AC799FB6B085ULL, 
            0x4853C5ED47FC29C8ULL, 0xC9DFEACA524B6BD1ULL, 0xAB2E3D099795DAD3ULL, 0xFF57D3555BA98BF1ULL, 
            0x0638A82981D174CAULL, 0x6BFFC4364C8E5107ULL, 0xEECCEBB7479B0413ULL, 0x5D0C09F7359C3FDEULL, 
            0x91EBDAD6A1B1AE86ULL, 0x925DA64B510A1F42ULL, 0xDF56CE5122259F06ULL, 0x5F5DDA4CEBBC1593ULL
        },
        {
            0x81A4B8946CA0DF7AULL, 0x7FD46C841BC7EADDULL, 0x8D4665F1EFB66B66ULL, 0x911A288B7EEF2EC2ULL, 
            0xCFA610351AB9BE2FULL, 0x2DF8B2717035D9CAULL, 0x25BED6420F1CC8ACULL, 0x6149DFE84D7B18D9ULL, 
            0x0FB54A964351D81BULL, 0xDC08B0D95E3EAD3CULL, 0x4A53A23C4C8F3FA5ULL, 0x27F8D58E81161EC8ULL, 
            0x618FDB4C73A54B56ULL, 0x577C6773B6394F3EULL, 0x230C3890A93B005EULL, 0x0248DECD522DA568ULL, 
            0x32BAA9D3A300D46CULL, 0x73E395548437F698ULL, 0x40A2352CFE53FDF9ULL, 0x45DCAB2DC6A1182BULL, 
            0xDB93DF02BCE88D3BULL, 0xBB9546B0726977F3ULL, 0x9083195A0231EF75ULL, 0xD67CAC82C5E583A3ULL, 
            0x2945A3B17E8AB738ULL, 0xCA2FD149F68A4A7FULL, 0x5D9DE485FE06EF38ULL, 0x5D7ABCCC3AA754EFULL, 
            0x39E3E574A3CF8815ULL, 0x3890EE91E76AC9B3ULL, 0x8AD16800C4BD42F7ULL, 0xFFB2D6F1A6706BCBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kTwistConstants = {
    0xD88070C396AE0B7FULL,
    0xE0FFA1B035D51142ULL,
    0xA4F0006430F9FFB9ULL,
    0xD88070C396AE0B7FULL,
    0xE0FFA1B035D51142ULL,
    0xA4F0006430F9FFB9ULL,
    0x525D6B97BFF17849ULL,
    0x648AE08BD9F9F21AULL,
    0x3A,
    0x09,
    0xAC,
    0x73,
    0x91,
    0x8A,
    0xA4,
    0x2A
};

