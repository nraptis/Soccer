#include "TwistExpander_Altair.hpp"
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

TwistExpander_Altair::TwistExpander_Altair()
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

void TwistExpander_Altair::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD4308ED36C6ECA02ULL; std::uint64_t aIngress = 0x8B5F93B0037E73DDULL; std::uint64_t aCarry = 0x906E023E3E149C61ULL;

    std::uint64_t aWandererA = 0xA3965022B601E55FULL; std::uint64_t aWandererB = 0xD4B2A30C37C95E2CULL; std::uint64_t aWandererC = 0xED41239E0C31AC5FULL; std::uint64_t aWandererD = 0x88F8E27D959F4476ULL;
    std::uint64_t aWandererE = 0xA9BF13F8C81B3850ULL; std::uint64_t aWandererF = 0xC88CC467790E8128ULL; std::uint64_t aWandererG = 0xCDA467D131A24821ULL; std::uint64_t aWandererH = 0xB26C428A75164252ULL;
    std::uint64_t aWandererI = 0xD2D417E33BE77597ULL; std::uint64_t aWandererJ = 0xDA7826FD8F3E59ACULL; std::uint64_t aWandererK = 0xD648AC63CEAAA50DULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x91C674FB392E4719ULL;
        aCarry = 0xAA071C500AC24C8CULL;
        aWandererA = 0x93596C769D827ACAULL;
        aWandererB = 0xADA404604AC23239ULL;
        aWandererC = 0x8809EE108854051BULL;
        aWandererD = 0x83B587F5446E36B8ULL;
        aWandererE = 0xC1F7E0A1B616F624ULL;
        aWandererF = 0xA2818E3047973BFBULL;
        aWandererG = 0x895A1AB23809A05DULL;
        aWandererH = 0x85979806178BD527ULL;
        aWandererI = 0xB8BDA44BDF033CC0ULL;
        aWandererJ = 0x9B0406A19CFFDD46ULL;
        aWandererK = 0x99FD182F5ECC1862ULL;
    TwistExpander_Altair_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD063A0EC97AA77B8ULL; std::uint64_t aIngress = 0xF85F7FD69462507BULL; std::uint64_t aCarry = 0xCB278C0C54A4C0F9ULL;

    std::uint64_t aWandererA = 0xD1D02BB6B5FB3DE5ULL; std::uint64_t aWandererB = 0xF16F16F0D95F3F7EULL; std::uint64_t aWandererC = 0xDD46E70921587A6BULL; std::uint64_t aWandererD = 0xFB7185502F6F1469ULL;
    std::uint64_t aWandererE = 0xE85D1AE57F3EC1EAULL; std::uint64_t aWandererF = 0x95C73ABBF474ED49ULL; std::uint64_t aWandererG = 0x9B99CCB591D9FA72ULL; std::uint64_t aWandererH = 0xECAA8455482C7BF0ULL;
    std::uint64_t aWandererI = 0xC839CD0568DE4A5FULL; std::uint64_t aWandererJ = 0x95AAAB65DD87BAECULL; std::uint64_t aWandererK = 0xC9C654066B910283ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8AE5A4E5172187C5ULL;
        aCarry = 0xFC398EDEC9444C7EULL;
        aWandererA = 0xA83A3ACAF914C7AEULL;
        aWandererB = 0x94BFFF00926774FDULL;
        aWandererC = 0x90C5C9515ADDE711ULL;
        aWandererD = 0x9B6454A801F4239BULL;
        aWandererE = 0xC31C6B136FC51716ULL;
        aWandererF = 0xD07A1FCE9725A82AULL;
        aWandererG = 0xD2FA4DE83BA27DD2ULL;
        aWandererH = 0xDEF19E15CFDF5194ULL;
        aWandererI = 0xE707E343A0067090ULL;
        aWandererJ = 0xCFD75F6739C6F450ULL;
        aWandererK = 0x8E716C00089EAE3FULL;
    TwistExpander_Altair_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE3B1B12B6B8A7127ULL; std::uint64_t aIngress = 0xB6EAA64EBE99629BULL; std::uint64_t aCarry = 0xD1955411382A4A1DULL;

    std::uint64_t aWandererA = 0xEA5A0847586C5895ULL; std::uint64_t aWandererB = 0xF3E8257E9ABF8DF6ULL; std::uint64_t aWandererC = 0xCBDA3F6577730E54ULL; std::uint64_t aWandererD = 0xB6246EC7F6961AAAULL;
    std::uint64_t aWandererE = 0xD4761F228D63ABA2ULL; std::uint64_t aWandererF = 0xED8B2612F456AFA6ULL; std::uint64_t aWandererG = 0xF35FDE6B5340A827ULL; std::uint64_t aWandererH = 0xB05A105DD10B380AULL;
    std::uint64_t aWandererI = 0xA7564A3FDA75AF51ULL; std::uint64_t aWandererJ = 0x9AC5792CE186B3B4ULL; std::uint64_t aWandererK = 0x8A544E4EEB7DA7A9ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xADFD4358BFA126BDULL;
        aCarry = 0xBF366B555CA099D0ULL;
        aWandererA = 0x95CB81548DC54A6BULL;
        aWandererB = 0xDA88F1F984BB3E5EULL;
        aWandererC = 0xE40B3ED2C98800D7ULL;
        aWandererD = 0xCA99B7D0B4C80E2DULL;
        aWandererE = 0x9B4D42D44F55ABB0ULL;
        aWandererF = 0x8F6EA4F14AD028ACULL;
        aWandererG = 0xF6986F683E0B62D6ULL;
        aWandererH = 0x8D6142036C0F61E0ULL;
        aWandererI = 0xDDF01693C36B25B1ULL;
        aWandererJ = 0xE8062C550816F5F5ULL;
        aWandererK = 0xBAAAA5124888E2E7ULL;
    TwistExpander_Altair_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFAD77A36ECD0D0E2ULL; std::uint64_t aIngress = 0xAD2CED40C3807A17ULL; std::uint64_t aCarry = 0xFDBABB5C77306EF3ULL;

    std::uint64_t aWandererA = 0x88C139E2FBE5BAECULL; std::uint64_t aWandererB = 0x83941169D3E0DF8DULL; std::uint64_t aWandererC = 0xB23F88462316F6EAULL; std::uint64_t aWandererD = 0xB9E95C6FC2CDB107ULL;
    std::uint64_t aWandererE = 0xA918918A3ED0A593ULL; std::uint64_t aWandererF = 0xDAA4FAAB53D4BC89ULL; std::uint64_t aWandererG = 0x907D21D24621CBC3ULL; std::uint64_t aWandererH = 0xF2E2875031C586BFULL;
    std::uint64_t aWandererI = 0x8A0134553FD4E227ULL; std::uint64_t aWandererJ = 0x9E2032D8DC37FA7EULL; std::uint64_t aWandererK = 0xE3BE09F98B264D7BULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x95100414271AA784ULL;
        aCarry = 0xB53AB29A6C8F60ABULL;
        aWandererA = 0xEE192B948DB3D3EFULL;
        aWandererB = 0xF4E89A2F0A9D8A3EULL;
        aWandererC = 0x8F4BD0C438802BE4ULL;
        aWandererD = 0xF6A15B3CC801BFC7ULL;
        aWandererE = 0xB560AEDCE2EB80D5ULL;
        aWandererF = 0xBCD08574ACF43E6CULL;
        aWandererG = 0xD1DC2710F6DD26E1ULL;
        aWandererH = 0x900A8C13EA0BB598ULL;
        aWandererI = 0x81CFF1A62A785C11ULL;
        aWandererJ = 0xF9C00E0853C714E2ULL;
        aWandererK = 0xCA5DB7D50ED00815ULL;
    TwistExpander_Altair_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Altair::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF3EF0651E45F0BCFULL;
    std::uint64_t aIngress = 0xD3041E23857E9068ULL;
    std::uint64_t aCarry = 0x859264E440002D62ULL;

    std::uint64_t aWandererA = 0xD537FF2FB79E519FULL;
    std::uint64_t aWandererB = 0xBE8D8D8EBF7F5B32ULL;
    std::uint64_t aWandererC = 0x8BEC875F068D2561ULL;
    std::uint64_t aWandererD = 0xE1B2619DAE5968A8ULL;
    std::uint64_t aWandererE = 0xCE0C900B02E58B18ULL;
    std::uint64_t aWandererF = 0xACE4B3650DE91CAAULL;
    std::uint64_t aWandererG = 0xCCA6881959103210ULL;
    std::uint64_t aWandererH = 0xFFC46A1EE53D89FDULL;
    std::uint64_t aWandererI = 0xDF9D9C59A76F612CULL;
    std::uint64_t aWandererJ = 0xB3D4202F916BF742ULL;
    std::uint64_t aWandererK = 0x91552274B8F03DB1ULL;

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
    TwistExpander_Altair_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Altair_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Altair_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Altair_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Altair_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Altair_Arx::KEY(pWorkSpace,
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

void TwistExpander_Altair::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF9736A14BCF88272ULL; std::uint64_t aIngress = 0x82E32E3AF97B7EC2ULL; std::uint64_t aCarry = 0xB17159749354CA0EULL;

    std::uint64_t aWandererA = 0xF7110BBC229FD696ULL; std::uint64_t aWandererB = 0xA27CAF4A94E0AA98ULL; std::uint64_t aWandererC = 0xCC3B107E6AD31E1CULL; std::uint64_t aWandererD = 0xEA96C7BD442CE65FULL;
    std::uint64_t aWandererE = 0xD30B04280F6DE38AULL; std::uint64_t aWandererF = 0xECFB603D50ADE4CBULL; std::uint64_t aWandererG = 0xA056E56BF2328C4FULL; std::uint64_t aWandererH = 0xDFB7C5E2C43ED289ULL;
    std::uint64_t aWandererI = 0xB6C8775D4DD08B93ULL; std::uint64_t aWandererJ = 0xF0B684DD5BA4E1BBULL; std::uint64_t aWandererK = 0xCCA1D391B069B9FFULL;

    // [twist]
        aPrevious = 0xDA96A7763704AF8CULL;
        aCarry = 0x95F31E37EE7FBD1AULL;
        aWandererA = 0xB6FA2B6DC11962C9ULL;
        aWandererB = 0x8311C0CF8FD1693BULL;
        aWandererC = 0xC2FF222FB6B9F8ECULL;
        aWandererD = 0xF3A8FB6BD22EFFC2ULL;
        aWandererE = 0xD1FFCFD9660BCF3DULL;
        aWandererF = 0xD36CD01B2414BA9BULL;
        aWandererG = 0x97C4942EA4B0A2C1ULL;
        aWandererH = 0x9E3C5B8E0518FDD2ULL;
        aWandererI = 0xFDABD564AADEC54EULL;
        aWandererJ = 0x870F495DA5825CE2ULL;
        aWandererK = 0xD0F2C9FDC4C5598AULL;
    TwistExpander_Altair_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Altair_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Altair_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Altair::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Altair::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Altair::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 7 of 33
    // Exploration cases: 0
    // Structural maximin 540 / 674; family total 3293
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1510U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 7 of 33
    // Exploration cases: 0
    // Structural maximin 541 / 674; family total 3280
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1150U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 7 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1087 / 1248; total 6611
void TwistExpander_Altair::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
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
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
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
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
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
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 7 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1081 / 1248; total 6562
void TwistExpander_Altair::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
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
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
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
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Altair::kKeyRotateSalts = {
    {
        {
            0x0CA0162A41382B6AULL, 0xBA24B54C5AC1310EULL, 0xAECA9BC26363D4CDULL, 0x545869C787160046ULL, 
            0x9A0A05711DBC7F71ULL, 0xE6FD1C0152E790ADULL, 0x6BB19AB5E78D2645ULL, 0x38B1DA0B5AD7E10EULL, 
            0x3B7EF9DFDA449533ULL, 0x37D148DF92D48273ULL, 0x4A21A0F9FCD63A13ULL, 0x826F3DE51DAF0A93ULL, 
            0x82FCBE8AA8E2E0ECULL, 0x348314904BD119C4ULL, 0x1B09A08CAD60187EULL, 0x707785E1D6EBA771ULL, 
            0x894BFE7B4D23F0E6ULL, 0xB21DB14F3C107F71ULL, 0x1A3DE4F2E17B65B1ULL, 0x0B7561E319A8CAF8ULL, 
            0x046CEE8B1534A627ULL, 0xC62FE8B8AEE25095ULL, 0x056632D62B4840B7ULL, 0x8D72BF6528DCDD0AULL, 
            0x806F7B837886183AULL, 0x242F637E9770F93DULL, 0x5BC2A8ED9E034232ULL, 0xAC3D2F1ED3A297D1ULL, 
            0x39B36BC5AC0C3F36ULL, 0xB42893E62793A455ULL, 0x604F4788DA327AF3ULL, 0xD361CA7AB81C2E05ULL
        },
        {
            0xADC5B194964A66C4ULL, 0xB01997AAC3513F73ULL, 0xF1F7E122B7505BA9ULL, 0x648ECBCDD322ED21ULL, 
            0x362D62F0918EB752ULL, 0x8C3B12DAF9FAD82AULL, 0x1B93B6D82705A2DEULL, 0xD20C7743B3F1B2B9ULL, 
            0x512AE175DFF22562ULL, 0x3A861FBCC4093066ULL, 0xCA79F2E24DFBE01EULL, 0xAA37BEAC0254610DULL, 
            0x2EE4A26CD9B245C8ULL, 0x996E70A31A91A37CULL, 0x1EF2ED5BE0F55AFEULL, 0x7E766ECA6B1A00C6ULL, 
            0x617D9BA57781ABEAULL, 0x35DE064B5BEC344AULL, 0x65A5EEE1D57EE060ULL, 0x44995D97197B2C4DULL, 
            0xAE5603CF8920458AULL, 0x8B48799860F1699AULL, 0x6560030CA8D72EFAULL, 0x2E68F2BE88297C1EULL, 
            0x31E7760C6E207B8CULL, 0xC2655B6563138C0BULL, 0xE903DBBB8EEE3F82ULL, 0x3AF886AB8C22AC10ULL, 
            0xE961BAC9B96FFAAAULL, 0xFEC0C9F627AA21CAULL, 0xC53ABCC5BAC10698ULL, 0x29D9A7C1836A0B5CULL
        },
        {
            0x21110C30E33910DCULL, 0xCB9BDCF34552D47DULL, 0x687B870A6ABD7263ULL, 0xD20FA137B11804B3ULL, 
            0x40972D0B29D8B105ULL, 0xD79CDB67F5252295ULL, 0x64C4FE2EDF254B56ULL, 0xBF203211508ABDDCULL, 
            0x0108DADD1C1C3614ULL, 0x0B3F9ADFD50417AAULL, 0xF1AAD6D4CC597506ULL, 0xEBDA0B379E3976F1ULL, 
            0xA05BF2E2B9D0021DULL, 0xAD63CF073FD8BB0DULL, 0xC083A4DD1BFC9E82ULL, 0x3952C7ED4B8634DBULL, 
            0x97E123BCDF37E41CULL, 0xE5B3283CC6FA6160ULL, 0xDAD9AC7895790015ULL, 0x5A0037085A8246EEULL, 
            0xB5DFA330B8FB2D31ULL, 0x837920B0CB9B770BULL, 0x9F3832E40C823072ULL, 0x6C1CDED59EA13D00ULL, 
            0x218B733F476BFDE2ULL, 0xB4A65871F6982B67ULL, 0x90821AB3449C38BCULL, 0x233FD2C1F078F0C7ULL, 
            0x9ED02B3AA9853623ULL, 0xC8E49CBD0BDD6C6FULL, 0x1262B7856BD46AFEULL, 0x86AAA1C67A9A799CULL
        },
        {
            0x1C07AC19188BC170ULL, 0x66873B71F67AB682ULL, 0x51837D45F8A6B52DULL, 0x2D1C5C5A9C1E126EULL, 
            0x4EB113733681E3B3ULL, 0xBDB785B16A943301ULL, 0x15289153D6CEA753ULL, 0xE6559DE76DF9539FULL, 
            0xFD8A6082E302649BULL, 0xA647E8959245D19AULL, 0x4DF573FE441AD8D0ULL, 0xD6BCC610F7EC8FAEULL, 
            0x483778B27B931461ULL, 0x3997ABF9CFEDB867ULL, 0xF16780E2A2C38B61ULL, 0x2879E4DD4710DFABULL, 
            0xEFFCCB18F5F5DB8AULL, 0x2744ED3E92BFFF8BULL, 0x6B1DDD74EF40DB70ULL, 0xC7CA09F94619B1BFULL, 
            0xFF773EF8F1D3DF62ULL, 0x115C562CC47B3605ULL, 0x5FC2CCD2DC73B3B6ULL, 0x45151DB779072D5BULL, 
            0x9B2326D46D0F0F4AULL, 0x19912042C122755EULL, 0x853656F7AE76445EULL, 0x3D0D67741840760DULL, 
            0x291C9C1B3F1CE5B9ULL, 0x05A9C5E1BD2A9847ULL, 0xACBC038AC769C4E0ULL, 0xE4F7B87DAB21FE91ULL
        },
        {
            0xFF089C5D8FAF2243ULL, 0xBF74475055B21B36ULL, 0xF96FA6AAC1520DE9ULL, 0x94D5FA71EDAAD910ULL, 
            0x7E11E325D2FAA8CAULL, 0xD7C7BF5546F47055ULL, 0x41B9507850BE417AULL, 0xA5DBED6C312D1D3FULL, 
            0xABD85A662081BCF6ULL, 0x94FACC95F8922FB5ULL, 0xA6397CFE419D7E6FULL, 0xD2D78C61983431F3ULL, 
            0x97E00A8D6795847AULL, 0xF5593A29F1507E1AULL, 0x1670B945DC03E1DFULL, 0xA39887A68B28D19FULL, 
            0xEA33CE15436E2338ULL, 0xC662B43A1129E4D5ULL, 0xDF402E332F2C980AULL, 0xC96659A0E415CF9EULL, 
            0xC02E19CFB54F3428ULL, 0xD67CC70CE0933A8FULL, 0xF68E09703DE3F879ULL, 0xAB53ABE802915995ULL, 
            0x7A0181802E9C0C8FULL, 0x3ACF57B182E466AEULL, 0x52D4EFD80210CCA9ULL, 0xF2609AE78FD2A905ULL, 
            0x122DC1C8D071CD59ULL, 0x3DC8B3A7FE87487AULL, 0x1E4AFC742AC597FFULL, 0x242F45460EB7DEB5ULL
        },
        {
            0x5D0ED6DE8AEA17EFULL, 0xBB73F008D5DB3CB0ULL, 0x0B94E46640199326ULL, 0x5244781482924CA9ULL, 
            0x4512E32F269CFC3CULL, 0x58E7B622546E1926ULL, 0x8F2181CCBEA15A3EULL, 0xEBF4A1D7FF152587ULL, 
            0xEBF2672B34F11A46ULL, 0x363B9C8D2BC5233FULL, 0x50D06BB5EF795C0DULL, 0x9FA75E19CA38B1EFULL, 
            0xA0CE44AABECA3D0EULL, 0x9BE3FB4DB6256F24ULL, 0x6A10C90E9726BC89ULL, 0x9715C1853769D387ULL, 
            0x8B5860504A02BBD1ULL, 0x5A5245940EF0F2DDULL, 0x6B850D860DB99F51ULL, 0x9E98279AC2E6A3A6ULL, 
            0x725FB5587F6CE32CULL, 0x12E91AF0FFA04A53ULL, 0x150CBE07F258BD4FULL, 0xD535DF1501E533CBULL, 
            0xA73E2845A0140CECULL, 0x684F06BE9A148B82ULL, 0x46C2E14932C5D549ULL, 0x0CD182828EAAD042ULL, 
            0xBD54B3B34441EC03ULL, 0x169DAB551FEF3A1BULL, 0x6241FCAB4F21B9FDULL, 0x15EABCD2BC9893A6ULL
        }
    },
    {
        {
            0x2AF33DF2C6E3869CULL, 0x3136DD6F0109A756ULL, 0x194DA7FE2A0E37B1ULL, 0x82941ED1788628EAULL, 
            0x6B0DCCCC4BD57E03ULL, 0xD8A90EAD7B45C35CULL, 0x78C8B6C7ECFD98B1ULL, 0x76886F812DA887B4ULL, 
            0x7CCA46CB012D56A8ULL, 0xAEAE58EEBE1B9105ULL, 0xFAB6933A90521333ULL, 0x422032697ED47F26ULL, 
            0xD62FFF5F362CEA76ULL, 0x5E6D720BC3D47C7DULL, 0x0E0EBA17C79B74E1ULL, 0x13CE655E15D94337ULL, 
            0x7D8944F4FBC40D83ULL, 0xFB4E17D5C6FDF15BULL, 0xC3AC0E720FF26B69ULL, 0x52D6C83C70BBDAD1ULL, 
            0xA661EFB59083FC3AULL, 0x6E1C0865971233F3ULL, 0xEDC706C63DEA9EC7ULL, 0x308D33FBE035199AULL, 
            0xA55E6B64DDEC2DC3ULL, 0xCE0BA91DF3497B0DULL, 0x363E58A1CF6F2EECULL, 0x78B8837603AB1A69ULL, 
            0x9DAF715F97D06E8EULL, 0x40DEAAA8497F11D4ULL, 0x723AD0C7040B767FULL, 0x35AF6F394805E61CULL
        },
        {
            0x747DCE91A62B7D8CULL, 0xB67D1C020733578EULL, 0xB4AD5A835EEB83CBULL, 0x16B9CCCF7C711EBAULL, 
            0x9A9400C943030C57ULL, 0xEDE41F37B0CABC7FULL, 0x70F97501C59978E4ULL, 0x122259B63EF7D9C7ULL, 
            0x629C65215514E58FULL, 0xCD0D8B5BF48E2C58ULL, 0xA5945F49FB9F3677ULL, 0x96DA463E9EAC6A17ULL, 
            0x7243AEF895291D97ULL, 0x8291A3FFF0862386ULL, 0x60DE0EF839A18836ULL, 0xC936B8BB3FB56540ULL, 
            0xE79C377BBE955682ULL, 0xD5FFC86C71BE89AEULL, 0x13CF89A2A0079437ULL, 0xE0002A88EEA871EEULL, 
            0x27948A0D62F4A3EDULL, 0x69F8907CF163ECB3ULL, 0xAEFC587C33875789ULL, 0x865AA72D32C09008ULL, 
            0x602756B44A894558ULL, 0xA567214AA25467F2ULL, 0x5D226ABD968DC0F6ULL, 0xA1E4CC90C306D98AULL, 
            0x23C894BF50AE2BA8ULL, 0xEC9E7C3B7275FC09ULL, 0x46624A72408EAC55ULL, 0xC00C44908DD47616ULL
        },
        {
            0x0225AA3FB484CA7DULL, 0xCFF3E67A8E90B7BDULL, 0x5761A84B9C60552FULL, 0x0ECD3E3E1DAE9972ULL, 
            0x73CC57C0763ADCD9ULL, 0xCBB0500EB7514042ULL, 0x86FE95B8636552C0ULL, 0x69A7839494E881ACULL, 
            0x4044AE7A8E7907DFULL, 0x41DB9F2287946B83ULL, 0xD43A9FAE1195CC56ULL, 0xC262014743ED005CULL, 
            0x17E28244FBC758EEULL, 0xE1B7CA7DC91BEC43ULL, 0x62EDC7F7F3C08A53ULL, 0xF170DD399B311CF5ULL, 
            0xBE28696FFC785C17ULL, 0xD33640FE33C4757BULL, 0xFB89FF3F477735FFULL, 0x5E9BCB411E916F42ULL, 
            0x75ADFBCC89D476BCULL, 0x58F98060B4062A75ULL, 0x74AC279109F2384DULL, 0xE4B7513B606F0FCAULL, 
            0x91BC50B5A01F58C2ULL, 0x31E7DE13537F9022ULL, 0x3DA119BEA026DA57ULL, 0xDE2BB58008A29835ULL, 
            0xC12136C229FA861EULL, 0x1F27316DE0799D79ULL, 0x614B7F57685A8786ULL, 0x7A76380948727D9EULL
        },
        {
            0xF94B7C1E8F4D0E37ULL, 0xF0592F3D6C9677F8ULL, 0xA8DE7FF10590D9DAULL, 0xBCCECDDD82B355B8ULL, 
            0xD12DB13D680F718DULL, 0xDA2BEF8E2453E65EULL, 0xFAD64336ED4508D0ULL, 0x8762F5A957B40108ULL, 
            0x6601D59064EE3C5AULL, 0xA3DDBF71763062B8ULL, 0x29D47EB9335A5505ULL, 0xF883DA96D46F35C1ULL, 
            0xA01C6B01D63799D6ULL, 0xE9888B8671BBBC2DULL, 0xEA3388029C9B8EB4ULL, 0xEB884877ED9561F9ULL, 
            0x6391946FF5AD2B18ULL, 0x3A198F672E18F44FULL, 0x64CCB5C2BA5B3875ULL, 0x4231C8A68E3759EFULL, 
            0xA789D574EC17FAB5ULL, 0x00E814F784E6B2C0ULL, 0xCD589707CBB46A43ULL, 0x9FC79DE4CD717A23ULL, 
            0xB73722B12602DA01ULL, 0xACEA86DB924BE8C5ULL, 0x0448EBCF404EE657ULL, 0xFE47DCCCB9FD0D26ULL, 
            0x0D79745B3F8FEDFEULL, 0xA0B9F9EDD41FCCE4ULL, 0xC9322D8E2137788BULL, 0xF6298CC39F36FA43ULL
        },
        {
            0x7F65EC483BD7B68FULL, 0x709B99215C6C490AULL, 0xF0E58BFAB45294E0ULL, 0xA9E28D6FB2E4EB0AULL, 
            0xBC56D7C50D77E3DDULL, 0x3790A08306C27B9DULL, 0xF3097CAD29B79DF3ULL, 0x4C786EB772C390E4ULL, 
            0x9BE517C51214101EULL, 0x1370E7646DAF23E4ULL, 0x9F359D0CB48E356FULL, 0x3E5138A7C8A53EE4ULL, 
            0xDF1B5DD3426504BAULL, 0xD7CE9F3E09A609E6ULL, 0xDB041330DFDB58CBULL, 0x01F68FBD1FEF773AULL, 
            0x9138762B672EFED0ULL, 0x3BA9F57C5B60CDBBULL, 0x297C011B56343470ULL, 0x48DB8972FB557ED6ULL, 
            0xA13E96429AADDDACULL, 0x3DF675337F1C2C9CULL, 0xD56DEA81AA7FD03BULL, 0x7A66340707171A87ULL, 
            0x95C5F79E01DDF54CULL, 0x909876CA91772289ULL, 0x1C9F97668ABBF6DBULL, 0x4382C7D9D7CD0ACFULL, 
            0x6E67F3C09582500DULL, 0x7639DDCF809E0062ULL, 0x7B52FC0218DAA3B1ULL, 0x5DB3281CCA320B35ULL
        },
        {
            0xCCB919F9F9747648ULL, 0x33C0DB00B022BDC9ULL, 0xAFCE73209062EDF8ULL, 0x60D623BCFD500124ULL, 
            0x6BA9F474376D4F17ULL, 0x75F7EEC446FB98FFULL, 0xF497C93165793D74ULL, 0x6B56062982E80E0FULL, 
            0x813AB5C1022A8BD4ULL, 0x1B54740751198AACULL, 0x4B773B2B203CCF10ULL, 0xF234720F81243324ULL, 
            0x95EC91728A359B62ULL, 0x0110640EFC1356E5ULL, 0x437763A9D3694FBDULL, 0x261AED883378CAD3ULL, 
            0x84D68BA577806EC1ULL, 0x58E54ACF29FA8849ULL, 0x2A0113A57D9046A4ULL, 0xA5B31EC15198FC85ULL, 
            0x3A4371F3FDD0C1B4ULL, 0x48F60B31F3664FE4ULL, 0xC48FE0DB2CF2F4D7ULL, 0x48788FF8035CC604ULL, 
            0x772457A05EBEF80EULL, 0xC67BDF127ABD3C8AULL, 0xFF943949075BF9F1ULL, 0x70999F510E7DFA3CULL, 
            0x9D5FCBF06DFDF008ULL, 0x3D1E1C8827D128C6ULL, 0x40A5BE966911B769ULL, 0x13712B7D6DBBFC40ULL
        }
    },
    {
        {
            0x8D365EBE5FE63E02ULL, 0x6F490A02A8E7D35DULL, 0x368F7101855931EEULL, 0x03AEC4521A84F0D4ULL, 
            0x96967C61AC9B4E35ULL, 0xBDF5E0E0E5F9B674ULL, 0xCE73DCECDF20613DULL, 0xCE8179A8F31BDEE1ULL, 
            0x760A316F2381B7B9ULL, 0x3EE2D7EAF33D7EE6ULL, 0x85F932911AE8B3DCULL, 0x27A38727CACC9B4FULL, 
            0x5C0D34C006132682ULL, 0x2F04C7995F09CCBBULL, 0x2FFF39E9006B0608ULL, 0xA5594E18F68F9E72ULL, 
            0x75F79F2ADCC1221CULL, 0xE386A3637AAEB0FCULL, 0x52E17C415F7EC8A9ULL, 0xAADAA2211A3744DCULL, 
            0x488026F037ECAFA6ULL, 0xD7F47599EB546C3EULL, 0x781FE3B8C8F06C1FULL, 0x451334E69055A9DDULL, 
            0x0B1AF09DDD8EF9EEULL, 0x834F817AF8D6AA62ULL, 0x544D4253E835C88DULL, 0xCB56A8C7D85D9B90ULL, 
            0x951BFA0F289E3EC8ULL, 0xF2F6F392889E90DCULL, 0x4B2C5A2DAF4D6F96ULL, 0x1ECC20CF4679B617ULL
        },
        {
            0xC33F6B27AB7D9EE7ULL, 0xC04326B1839F0AF6ULL, 0x4DB468209C58625AULL, 0xF8A19D7AC58F4F3EULL, 
            0x26C0170F3755AA7FULL, 0x5AF9BB35A90D880AULL, 0xE9C2AF3C9FD87D28ULL, 0x68CB3C064AD260BFULL, 
            0xD2BC02862C389694ULL, 0x00E1CA07C138EEB5ULL, 0x87885BB20D5A0724ULL, 0xA88BE27FEA4A78D6ULL, 
            0x4C5B84DEF7E23F8AULL, 0x0A430D38637C943AULL, 0x5A8BE5CC2B9C5A9BULL, 0xF65C0DBB9EF97100ULL, 
            0xFBB4982CAB71CA29ULL, 0xB2B228A64D9A4FD5ULL, 0x0ED5D4EF3C462877ULL, 0x95223196E021A6E7ULL, 
            0x9C5C1D27D0FB3CDBULL, 0x98BEA671252C10DFULL, 0xD17F13E6BB4D572EULL, 0xDBCD73C42D5A586AULL, 
            0x4F3242B4AACF3E90ULL, 0xE6756A2404F95849ULL, 0xA2B7799DD650CAD9ULL, 0x5E74A3DDE940D014ULL, 
            0xA78596ADB4D52571ULL, 0x36EFFAC413EF9E03ULL, 0xB57FC5FBC0CF112DULL, 0xDD8DC08AC857016EULL
        },
        {
            0x3E1F2F9D1C77D54CULL, 0x94499073F4815933ULL, 0x2F2C8B359DFA746FULL, 0xD1EE51AC87C3A51CULL, 
            0xB3324C3BB390FBE0ULL, 0x9A10A4545FDDB732ULL, 0x073A3F6160723703ULL, 0xCB10EB913F5C6649ULL, 
            0x58266A8746719E2EULL, 0x07F9C7169121099BULL, 0x0FA44214EAEBCC38ULL, 0x59A0AEC27997BDF0ULL, 
            0xE0096AE955831603ULL, 0x3C72598822593513ULL, 0x66B3254F197326D6ULL, 0xA6C1D86541E6B9A0ULL, 
            0x12A009FCAB558283ULL, 0x84F35C8B9891BCA0ULL, 0xC80EDF5624CEFA10ULL, 0xC8094879A089D176ULL, 
            0x9DFDCA27691EBD80ULL, 0xFD5AAD8AEDC85CB8ULL, 0x393055259A69A72EULL, 0x2B86C0B339CED039ULL, 
            0x82A979FDF949F74BULL, 0x12E1C246E5249C18ULL, 0x3D00A904751A6EA7ULL, 0x551449E115584870ULL, 
            0x477C3B321C060A9CULL, 0x13A608CA04808D5AULL, 0x1350989AB2783E0AULL, 0x375F2FF571E7DFF4ULL
        },
        {
            0x4234A76C7424BDC0ULL, 0xA8C042C5019EA946ULL, 0x8D5F617A5E7590FAULL, 0x99202E8A0817450FULL, 
            0xE0D052AF59B2224EULL, 0xEF7D741E80CD33D5ULL, 0xC04F9AFD5A659385ULL, 0x38032C40A4DAFB4BULL, 
            0x19DFE8E59B2ADCD0ULL, 0x06D15833890D2368ULL, 0x22892A58A725C9C0ULL, 0x8C437EDA2D85CC12ULL, 
            0x27311ADD25345AEDULL, 0x7E0B9CD1F71E9AE4ULL, 0xFE537AF43C80D4B9ULL, 0x98B7B91555E16CE5ULL, 
            0x5A6CC73AD870D2EBULL, 0x8381A60286B1DC3FULL, 0x74F4A6D5E1378312ULL, 0xCACA7B42884C7560ULL, 
            0x97704E43F96E2300ULL, 0xF872CB3CD70222CAULL, 0xF1B01339B7FB8BECULL, 0x5664D1DCFE498188ULL, 
            0x07E208840797744BULL, 0x25AE0F19196858EAULL, 0xFD5CB3908AAA54D8ULL, 0x38D425B10498EBAEULL, 
            0x625F58E363A319BEULL, 0x010EDF5E3D9E0B63ULL, 0xA9DF58FB6B4DAB89ULL, 0xE52AA4257D01A1C8ULL
        },
        {
            0x06808C1B3BB86C99ULL, 0x070F32534BF6286AULL, 0x704C5D0CBFB502E5ULL, 0x52E762F5F47C8805ULL, 
            0xA7A9A67BDF0DD437ULL, 0xCB11DF5A13BD57D1ULL, 0x7DFF9EEE2145B515ULL, 0x360C2CB3D57546B8ULL, 
            0x691DF455C35695E6ULL, 0x5A895EE36D71B3BBULL, 0x778AC59A6ABE7941ULL, 0x85C4740CC4F1A321ULL, 
            0x614E559C249922E7ULL, 0x93377FA1D2F0BE45ULL, 0x8443187510322CB3ULL, 0x796D0EDB91598612ULL, 
            0x80B097C59878437BULL, 0x049EA9D518AFA3FAULL, 0x121A57E3901168FEULL, 0x17A846CC8004E23CULL, 
            0x20321642F834C38DULL, 0x2BCD0C5C8972F752ULL, 0xD812820637CB20C2ULL, 0x7D64E2528756D6C5ULL, 
            0x6774C1C304618ACBULL, 0xD71AB29A1BE35C17ULL, 0x71DD1DB4A1CF4B7DULL, 0x7DB71152C73F56A8ULL, 
            0xFA459F1C50822E6CULL, 0xEF3259BDEE5847EDULL, 0xBBC9F7A0B2CC3872ULL, 0xDBF073EA597F6553ULL
        },
        {
            0x296D0B4A20366D94ULL, 0x48675F7A4485C52FULL, 0x79B2DC2742378AD3ULL, 0x47ECD2631951682AULL, 
            0xD93A724ABE998E89ULL, 0x1C659578A91D9FB0ULL, 0xC28439DFB09EE868ULL, 0x9A2551DD2D9FED3DULL, 
            0x5C2AA3E52CA60524ULL, 0x53D2609A8723E43DULL, 0x607F9FC2F31AB4D6ULL, 0x00A923CEB8A231DBULL, 
            0xA87E73137EE2330DULL, 0x6F9A78F703307328ULL, 0x0CC90AA0639ADD36ULL, 0xD9B35071BBE594A8ULL, 
            0x6B11630342E610D9ULL, 0x9B7792007F86F9CFULL, 0x42F4CBCBF3E7AEC0ULL, 0xA4C2803CE71A0475ULL, 
            0xC0F2C7F83DC930B0ULL, 0xD40B26B27427B5F2ULL, 0x2285C68F89F7B1E6ULL, 0x3172054C5B956921ULL, 
            0xCA099A6A907EC15BULL, 0x01CBBFB499105547ULL, 0x1DC1CBD7DFDD0AA4ULL, 0x2F47624D5D88C0F1ULL, 
            0xF97FBD853EE3ADC5ULL, 0x710F35D03E32EC83ULL, 0x2E4BFB8CE87CB1DCULL, 0xD1F580EA3A5EF3A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeyRotateConstants = {
    0x38B000188EA43629ULL,
    0x04A807472BD498A1ULL,
    0xFA27F27AB3A370A5ULL,
    0x38B000188EA43629ULL,
    0x04A807472BD498A1ULL,
    0xFA27F27AB3A370A5ULL,
    0xADDC83A5A11FAE30ULL,
    0x3EB87E6897C8DCEFULL,
    0xCB,
    0x65,
    0xDC,
    0x29,
    0xA2,
    0x6B,
    0xB9,
    0x14
};

const TwistDomainSaltSet TwistExpander_Altair::kKeySpawnSalts = {
    {
        {
            0xC94E4E04F5317181ULL, 0xD0FA55574DC684F4ULL, 0xB21ABD4F5E1AE00FULL, 0xA9583DCC95AD4163ULL, 
            0x24898D2C2ECD3C23ULL, 0x77369F20E470A2D7ULL, 0x02B1103C8B307983ULL, 0xA46396C6E5E0BDE4ULL, 
            0x89BBCFC3938AAF8FULL, 0x23F50C5FE43E4EC9ULL, 0x25BD25E58C298CE5ULL, 0x9E8F2C834DC8F2B9ULL, 
            0x859F1AE31E006D03ULL, 0x0202BD56C5C87D5BULL, 0xCF5CAE58DAE1E97FULL, 0x3EE151BA9436914BULL, 
            0xA77A16E4D8BE5EF3ULL, 0x28916CA43D4C37BBULL, 0x56B311EEB1CE2CA2ULL, 0x81429C632D092A4AULL, 
            0xD9945DF0A5C001BEULL, 0x97FC805AF32ABF38ULL, 0xBD0279FB29A362F6ULL, 0xEA61BC50438EDE36ULL, 
            0xAFF534CDDBC8DB41ULL, 0x150AF4E7A2953176ULL, 0xF866150AD3667686ULL, 0x7577B74E7E838F9CULL, 
            0xD33C1060BBBB72D1ULL, 0x4C738CB513E77581ULL, 0x81AFA219BD8F2049ULL, 0xCCD88C600848FB2AULL
        },
        {
            0x804B249336369751ULL, 0x6C2DD83DBBB8FD72ULL, 0xE9F39C22FAA00623ULL, 0x3F230AE89DCD0256ULL, 
            0xB7232FF283C8695AULL, 0x570BC30F4B1924B6ULL, 0x1FF64B782A08C3FAULL, 0xC3DDD0998F298F28ULL, 
            0xE9D8004F253AED7BULL, 0xA69F375A855F0F9BULL, 0x618734D3CE9DCA54ULL, 0xBDB81F95C4444277ULL, 
            0xCD397CA9C4D11B5EULL, 0x90C1A350F5D5C9C3ULL, 0x7369591CA5F8E631ULL, 0xBF78BBE1E8C3924CULL, 
            0xCD781A383F2616F0ULL, 0x384A874E6C7807ACULL, 0x2538AD5A9E76D574ULL, 0x2F3BF22F0569B9A7ULL, 
            0x18B1E222103DE3B3ULL, 0x05D0E545E6F9C430ULL, 0x1D0BB2AC6AA32131ULL, 0x828525334B28ACDEULL, 
            0x4F8F343F505A394BULL, 0x1076641F858EB332ULL, 0x2C3041FCFEC59659ULL, 0x7C8749B10BD455B7ULL, 
            0xF680990422CF6D42ULL, 0x83ECB5FC47B81EC8ULL, 0xC5647E77A060D2FCULL, 0x9B7CEB3A8D77551BULL
        },
        {
            0x564CA1186DABB6B5ULL, 0x34C29AADAB55F88EULL, 0xFA816DD95CC7900BULL, 0x883F98D92267ADF1ULL, 
            0x4EE39EACD1E4E3EAULL, 0xB4C9EC7E75E83BC9ULL, 0xCA98DBA20E3EC1EBULL, 0xB24ECA74FCB87BD0ULL, 
            0xADF64B7829CC2EF5ULL, 0x1FF118CDF73F850FULL, 0x1A3EBF844C0721FFULL, 0x2F52E6BDD82E0E25ULL, 
            0xE9D6D072070E5778ULL, 0xD1344AFA18D592FDULL, 0xB8AC555676F7A13EULL, 0x4587E26C1882D648ULL, 
            0x4D3D0302ECEC8778ULL, 0xD5ACA65EEDC8C96FULL, 0x8478923F46BF3BE5ULL, 0x6DB5B29E4FC9F45CULL, 
            0x3E7720D04B5429E5ULL, 0xF457DF17FA78654DULL, 0x0F6B9B4ACC1ECA89ULL, 0x8FE76DF2F392408EULL, 
            0x47189448AA132BD0ULL, 0x6D3A4ACF832E44B1ULL, 0xBCA84798AA1A5F77ULL, 0x74FC5152607E6B85ULL, 
            0x9571689E5357120BULL, 0xAAD72E17FB0A9F67ULL, 0xDB12FC2A024AF3ABULL, 0xC739F012FA612E7BULL
        },
        {
            0x6375F138EBFEB476ULL, 0x9103286907F1DF36ULL, 0x5685D264C4043FB8ULL, 0xF057F5EEAF60B4A4ULL, 
            0x4A7101272B744A99ULL, 0x9E1CAA21BB613CE0ULL, 0x14DE695AD2C91242ULL, 0x581CFE56F672919BULL, 
            0xDC5014BBD1929132ULL, 0x6FCB38E153B2C1DFULL, 0xB4279C265CE236DBULL, 0xD82C64D3044051B9ULL, 
            0x412313321818518FULL, 0x0A68509ABAC4CDCCULL, 0x92EA109412419C38ULL, 0xF3CF9ACF5C0ADDBEULL, 
            0x149AE892363554FDULL, 0xE82AB59BDAD27EF2ULL, 0xFF53D76004EF2F1BULL, 0x4BA962636D2D7820ULL, 
            0x1D9E671B6DFCD7F2ULL, 0x934BDD762B01A0E9ULL, 0xCC3CAC4BA929A6DAULL, 0x4019FA1EC423331AULL, 
            0x5D0E0DE9489AA5C9ULL, 0xB2447EAB15F797BFULL, 0x6A859029426C903FULL, 0xCD7421D57C63221EULL, 
            0xD497C9CB953674FCULL, 0x3632D4F8CBB86BD0ULL, 0xF6DE0CF50FBD5A8FULL, 0x8BF0D8F143C2D3DBULL
        },
        {
            0xDB70725EFBBD4B37ULL, 0x190534E6CED53854ULL, 0xA0D001C6BA71C6E4ULL, 0x6A1B7D005E4E42B3ULL, 
            0x08A0C662B4A38547ULL, 0x855D1F3ACE7DA462ULL, 0x388A6BBDC6D01E12ULL, 0xF85AA9FFCCEDD633ULL, 
            0xC9F8ED280E9F409EULL, 0x331D63596AFA766EULL, 0x5A74E1BA02AFE0A2ULL, 0x833F0891D788B7E3ULL, 
            0xB4D2A5ABD13D9D34ULL, 0xD220302D8960813DULL, 0x106222E38B9CDFEAULL, 0x7A1AD80DBA7BBE7FULL, 
            0x9E57AE003E633A22ULL, 0xA0681495D00E4B74ULL, 0xFA6958F86656483BULL, 0x6D11D646124E7897ULL, 
            0xA7A571CDAFAB81D1ULL, 0xC896D75753B8C4E0ULL, 0xA318B84F562AEF75ULL, 0xA744608373AF8504ULL, 
            0x9BA7A2B74CAF552FULL, 0x24D163655E1532F6ULL, 0xCD542B2A8A35CE27ULL, 0x93047C7183DF2458ULL, 
            0x8DB10C119FD7616DULL, 0x5827E20175E3A280ULL, 0x1FF572EDA7E5F47AULL, 0x3733BBE6E4CDE715ULL
        },
        {
            0xDC4AF41805F40FD0ULL, 0xFFA256E3A6EF7EDFULL, 0xD801327C67B66364ULL, 0x37B3D5079F45A3EEULL, 
            0x83DFE325119569B0ULL, 0xDF802E5301590961ULL, 0x193097D1B4F8E89CULL, 0x1E2CE83BB0C3C750ULL, 
            0x173C7C6C29DE97DFULL, 0x7B2B6E2667889A9DULL, 0x1F31E921BB5CCDE2ULL, 0xE69757741DF65D80ULL, 
            0xF8800C34520171DFULL, 0xF63A8E3CCB48C73BULL, 0x9C85F1AEF21BD2DBULL, 0x71C14B1EDDE3F2C6ULL, 
            0x335BFED99FBCA97BULL, 0xDBB9CED65EF9A053ULL, 0xE214D722D029997FULL, 0x30C4373D2E87A887ULL, 
            0x891BEE2B3382516BULL, 0xA4156CC5C31F8682ULL, 0xBF4EA22F2FF01B2CULL, 0x4FF8ACB1DDDB5777ULL, 
            0x0174FD9051BDEBCEULL, 0x04CCDCD0DC17991DULL, 0x8E77E6836B465B17ULL, 0x5C7A09709097AA9CULL, 
            0xB82EDE490393E104ULL, 0x49C21EC81A2BD66EULL, 0xC17BC120B472BB05ULL, 0xB083B3C66D29AC37ULL
        }
    },
    {
        {
            0x54E52E92EDA09FF9ULL, 0x9A2A41B4B96B147DULL, 0xC9575B4F5D045A3AULL, 0x9927F0BC5DC83467ULL, 
            0x52854C0E16987B2FULL, 0xF806D34BA74558BEULL, 0x040F97705E1B6FAEULL, 0xEF51A38A0E797CEFULL, 
            0xA22552446E146371ULL, 0x0F09CD8FEDEEBF07ULL, 0x7AEE01B4BBC0FF7CULL, 0x65FBECD70373DD56ULL, 
            0x53F3EEDD78590F3BULL, 0xF6BC1F3DF1188F07ULL, 0x9F32051737394749ULL, 0x437D5FE6F7984EF8ULL, 
            0xAB526E52F90DDEB7ULL, 0x09517F7E0597CD2FULL, 0x244B0E930A566F65ULL, 0x2DC447F21F3F2BBDULL, 
            0x73AF07BA838E357DULL, 0xA37E225E74EB92B1ULL, 0x25DE3F0318E3DF77ULL, 0xF5D47432E9E1E8CAULL, 
            0xDFD7195AA6EE463CULL, 0x3ED3B9A62D121172ULL, 0x0958ACC96B51ED10ULL, 0x374A02AAA9E2AAB2ULL, 
            0xAF1716845850C668ULL, 0x64EB3F9B5120BF80ULL, 0x4921D829AFFBFBD6ULL, 0x72AA6BAA0D37B09CULL
        },
        {
            0x67866E37B1821DC4ULL, 0x361237F24931F7D6ULL, 0x12166EF705F2704EULL, 0xD8DFD717E89A8546ULL, 
            0x1CFA1645FAFF3EA7ULL, 0x92755B6C0DB669E7ULL, 0x23E6C26FE52ED487ULL, 0x08108BF189180982ULL, 
            0x99024B4797F427EBULL, 0x2B16DD674873C87BULL, 0x055C8BB7E6FA9990ULL, 0xA19FC7706F07DED5ULL, 
            0x9C096DF1F7046E40ULL, 0x456320E3AA7564C9ULL, 0x1B3FA818D7518D62ULL, 0x6F5C0F94FE397016ULL, 
            0x4AECC0B72CF8E774ULL, 0x50E0B7F66BE1D5E8ULL, 0x55C1BEF3DCD24C62ULL, 0x066BFFB39CAFFE6DULL, 
            0x09B575634E50B6AFULL, 0x1F9AEEBF89A3A72DULL, 0x5B359EFB893A6B12ULL, 0x1FE2D86C5655D60CULL, 
            0x6963546F543594A2ULL, 0x095471854F7734B5ULL, 0x448C87F2EAD38B5FULL, 0x662C31D85BBDD6E4ULL, 
            0xD50AFAF88A76DB56ULL, 0x8AC2E7C3F55B837DULL, 0xB4EFF46A3C4F3A72ULL, 0x9B2BF3488CB9984AULL
        },
        {
            0x81969F0019463266ULL, 0x4631AF32FFA65987ULL, 0xBBBCA22E2FE93585ULL, 0x29DD6F92C3CD045EULL, 
            0xCB590A491C931F11ULL, 0xFEB235C7844F830AULL, 0x7AA4AA55AE579608ULL, 0x0F13409C6B7F89E4ULL, 
            0xEAA8BF9FF6D0A8BDULL, 0x788175FF7BA48A59ULL, 0x601660A59DEA11CAULL, 0xB1754FA323A5400BULL, 
            0x0F4D78F7D5B41D52ULL, 0xA30E5594D97DBF57ULL, 0xA663CFF3931368D2ULL, 0x02051DCCD7997A75ULL, 
            0xF1706063F1751C92ULL, 0x6A8D83172EC0533BULL, 0x2DFBF78B55180F1BULL, 0xE9A49D7FF1BC2AD5ULL, 
            0x340393B00FC1AC6AULL, 0x4AB0FF4F346F170FULL, 0xB96B6B34E95B3C9DULL, 0x21D8688E2609BBD9ULL, 
            0xE98CB448F0D7BB67ULL, 0xBC8476A982C36F6BULL, 0x9BD61DB801F1686EULL, 0x014E10FD84921EB1ULL, 
            0x7983F9AA687E676BULL, 0x787E1C6A835A9669ULL, 0xA235F0F4988D36F2ULL, 0x74160567302DC636ULL
        },
        {
            0x6C0E4275CBE44A2CULL, 0xAC770A854193AE68ULL, 0xED92927E245B5744ULL, 0x085CACD13B976B5CULL, 
            0x904E946B5903E0F6ULL, 0x96EFC9544141A731ULL, 0xF56608120E8B08E6ULL, 0x54802315438E91B5ULL, 
            0xBF14E28E6005E6D6ULL, 0x1F60FDC5F618179CULL, 0xD1E424D58A81B8CCULL, 0xB5F1D29441987522ULL, 
            0x304C7FB9494E2554ULL, 0xB534C56D04F8FA82ULL, 0xAFBBB6B66EC9E26FULL, 0x37E456BEF5ACC7F4ULL, 
            0x20210E70BC765D07ULL, 0x66A7FA11A1E03B29ULL, 0x479A8EEBD2B365D4ULL, 0xAD204E3F1539A7A8ULL, 
            0x3D7629B3BF40C6C5ULL, 0x6CB0062EE679E6A8ULL, 0x50D56C02136BC2F4ULL, 0x34E79E3C896AD453ULL, 
            0xDF8C7898E859B2D5ULL, 0x9F6D86E3EFACD0F9ULL, 0x2C9A2D0EDAEE5719ULL, 0xAA16C013E2DDDBA3ULL, 
            0xD567BC7B1D826F00ULL, 0x9EC7AB1DCE5503A4ULL, 0x3D43B37692D32A4AULL, 0x64FF7A45FBEB892EULL
        },
        {
            0xDE5185FDDD82D014ULL, 0xF8D0A58558182D04ULL, 0x49D564331289B638ULL, 0xE36CE8BB4A2ECF4EULL, 
            0xAA2ECD1F32DAF12BULL, 0x4A6B433B0DB9477BULL, 0x2F66A944CDF723C7ULL, 0x310B2A9F83EFE716ULL, 
            0xBB4EF2EF48102CF2ULL, 0x7AD9389E08C001F4ULL, 0x3887010D6C095BBFULL, 0xE2DF564D46057CC8ULL, 
            0x662C0DE3F6FA68C0ULL, 0x06475CBDB94A02C4ULL, 0xCAEAA47322C6D2B0ULL, 0xDA350FADDCD7C678ULL, 
            0x5DBC2F3D252A03F2ULL, 0x9EEC6A857A364F4FULL, 0x7F8052A9E65CBB05ULL, 0xC8BBA9C9D5EF65F9ULL, 
            0x6196553EAD5A99B1ULL, 0xC018E72F82938F20ULL, 0x4125B8D71AAD943FULL, 0x815F0A22036D8227ULL, 
            0xC7859080165FD64BULL, 0xAEBCCCE72A99588DULL, 0x73198549C59F57BDULL, 0x66AB944F2C387532ULL, 
            0x2B4694D00D783753ULL, 0x86B5A03EDFE31C88ULL, 0x70BE02D545446F8AULL, 0x181024B5A0295FC6ULL
        },
        {
            0xAC44EFFEE32254F3ULL, 0x4CB95F686A4FB3EDULL, 0x727CBD3F48486080ULL, 0xF9E6CC253A79846AULL, 
            0x38EE4A594BAB30D2ULL, 0x3F0EE0F541AA121EULL, 0x40A8DF56C8A55B13ULL, 0x7CC24477960AD262ULL, 
            0x810379326DA1D9D4ULL, 0xB3C5627AA1860B18ULL, 0x2A7D6685FCDBD4AEULL, 0x47950F29E02A54DCULL, 
            0xA1A7603165A4C32FULL, 0x58FB929B253573B2ULL, 0xE1D675C691C49EBCULL, 0x0F836CAA7270D98AULL, 
            0x4628B119B4F5D482ULL, 0x7FC476BF0DAF916EULL, 0xB4021F151BA6DCE7ULL, 0xA20059B8F8F760E1ULL, 
            0xE649BA913759238FULL, 0xB098BB12E2E81ADAULL, 0x417A720E7290DB76ULL, 0x5DA87A5A444DD96FULL, 
            0xEB86CE0802AE1F51ULL, 0xACA162B506D70C0BULL, 0x45D4760EFBEE30ACULL, 0xE143141DF97D70C5ULL, 
            0xE6CB2C86F64BB430ULL, 0x918F7F3BF2CD1838ULL, 0x3C65380EC67A1273ULL, 0xFF7B7A98BD4F0926ULL
        }
    },
    {
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
            0xC763A61671D68A85ULL, 0x2DCC552998DEC20FULL, 0xF9C6E817E5192284ULL, 0x8B3EA4D1054009F9ULL, 
            0xC3B882386886710AULL, 0xF1E27B4C273CEA70ULL, 0x5C03519450DDE33CULL, 0x5386F7F80E0FA2EDULL, 
            0x2294B6194F46048BULL, 0xB1B1F0CE68994150ULL, 0xD5E4EB06DDA2B244ULL, 0x9477EC5F7858234DULL, 
            0xCE8AB3261D4AF722ULL, 0xB6D5138A4D864AB2ULL, 0xC888CD9A7F0FFA0AULL, 0x947795DE7C8AB52AULL, 
            0x82CE5229F442BDA0ULL, 0xC5377C5A18803450ULL, 0x9B15660EB4A600FAULL, 0xDE79A1470C0494F4ULL, 
            0x0722B94DA72FBC00ULL, 0xB59E1157E528263DULL, 0xE680AA5EFB165536ULL, 0x3AFCA0E6A7622D7AULL, 
            0xB6328B9D01248738ULL, 0x02F7F9EBB540192AULL, 0x43E218358099B016ULL, 0x527E0621A0AFEE80ULL, 
            0x95A92E85C3B0A1A6ULL, 0x587D5CEE22E7B847ULL, 0x24618601A3CC4976ULL, 0x92D5CC67B51C2686ULL
        },
        {
            0xBCAA2E440901A018ULL, 0xD76BFACC24235424ULL, 0xD69583E8269C3F96ULL, 0x55EB41E78524AEE9ULL, 
            0x628BEA9C8DF46D56ULL, 0xD78C31812A2653CDULL, 0x906943078A2FF6BCULL, 0x890ADE5BBB9C7377ULL, 
            0x13903F45E465792DULL, 0x8F5B01481BCF2AC8ULL, 0x3C38C3A4A679FF1CULL, 0xAAA8BD247FDD9838ULL, 
            0x1FECCE50059B2AE6ULL, 0x976B62B10CDDA438ULL, 0x1E7C7B6BF15AE59CULL, 0x70EE13EFA23D43CCULL, 
            0x1B077A734B587977ULL, 0x9310F12DE102058BULL, 0xA78300C47C635C25ULL, 0x9CACCB28C4F0D8FBULL, 
            0x8ACE600A65B41814ULL, 0x83AB45DEF91C8547ULL, 0x6E3C9D08067BA3BEULL, 0x28CBEC70AA4FF922ULL, 
            0x45E106BDE4D8F663ULL, 0xAF00FFB01C4DE8C1ULL, 0x245F3BD1EF8EC464ULL, 0x52CD79A87CEA397EULL, 
            0x24380811F7E20A92ULL, 0x425A3A8197BDE2B4ULL, 0xD95934E83F6A3D2CULL, 0xFDFD62E8C156879AULL
        },
        {
            0x3A4AEC6ECFA4D906ULL, 0xDDABE705B559FFAEULL, 0xEA5734CFEF49FB82ULL, 0xD9845737F52AAA81ULL, 
            0x28A1FE588011CC49ULL, 0x525DDCBF28F84805ULL, 0xCC810A92139874A4ULL, 0xF74B8FF517DD0DFAULL, 
            0xD0FBF797E572F819ULL, 0x4AD10397CD46DB9BULL, 0xC443BB63D615DE28ULL, 0x7EBAE7267E2D5C98ULL, 
            0x50B9CB76CE5D0E49ULL, 0xF6CE42523CFF6942ULL, 0x3BCA93A2A0B1C2F1ULL, 0x25AD2AFBBAA2C548ULL, 
            0x78F212F4F743B7BCULL, 0x222478A4EBDFF9F6ULL, 0x6BD948557FEBF11CULL, 0x29125B0E9E5545B2ULL, 
            0x07000B4AE66663B4ULL, 0xC30BA5C4424704C1ULL, 0x4B0B63D5E15F3FB0ULL, 0x2CF05331569DCAB2ULL, 
            0xCCC8B990C218177EULL, 0x0064EA4CB3EC4234ULL, 0x32513FC5EA34BE03ULL, 0xA07918009171EAEDULL, 
            0x68FCAAC4A09E56DDULL, 0x3070D57CEA6F8E8CULL, 0x2402FBAB0A622C97ULL, 0x19B736EE18F0D29CULL
        },
        {
            0xF14DEDCB5AA8D5D7ULL, 0x02931396044F6A88ULL, 0x4FCACB763E265B4BULL, 0xA04FFA0809B6F753ULL, 
            0xCE0A124DFB5A6554ULL, 0x0C74873C174B2987ULL, 0x11DC2F3A365F332EULL, 0x47DFD2DA4C6BF1C2ULL, 
            0x3A00AE4619583C3BULL, 0xD41FBDAC4DBDB354ULL, 0xE35CEAE7E704D181ULL, 0x6A11038197D9231CULL, 
            0xCCAC3205C7E8D981ULL, 0xE5CFAD33C25FE5CEULL, 0x882C909E470F7543ULL, 0x2548631B859E71DBULL, 
            0x8EE8500319C2C91FULL, 0x227A39023C4AF036ULL, 0x2E8D3657A04ABF53ULL, 0x15CD92AB4B674FCCULL, 
            0x8FBB5B4D3FC2ECE6ULL, 0x3EB8C8548E647E0EULL, 0x17D5FCE59484C528ULL, 0x53277986FF3F7004ULL, 
            0xA466F791BF2E6AA2ULL, 0x9D481D6D31D1D531ULL, 0x0F3D050E8E1F7CB3ULL, 0xE87E768B1CEFD0BEULL, 
            0xEBD2E435ABA40ACFULL, 0x9BE8C7F9F6AD9509ULL, 0x351BF1ACFB58218FULL, 0xE335C85CDE285DE7ULL
        },
        {
            0x58B9C6446DB51E9FULL, 0x20B83C2560B1261FULL, 0x7FC7FDA1DA14C6CBULL, 0x286D3A8EC898362BULL, 
            0x0A63B2B8EAD72438ULL, 0xF33F59DBFC546266ULL, 0x507EF1640FDB26A7ULL, 0x033017FB79DC7051ULL, 
            0x50F76F782B14F50BULL, 0x07ACC4F47BCC812BULL, 0xE1AFC72FB2230AF2ULL, 0xBCE11EF214961CF3ULL, 
            0x6E1459F2AEF8181FULL, 0xC4E55095CBD325A5ULL, 0x1B39C8DE5B35C138ULL, 0x41FCD61BC1929961ULL, 
            0xE730C14F09AAE682ULL, 0x57180B1F280461E4ULL, 0xD66E732E00392BE5ULL, 0x6A6A934944323343ULL, 
            0x126DA85B1E3ECA65ULL, 0x2660B00AAC0B2414ULL, 0x9C7DEAA5DF4303D9ULL, 0x75AD6BE69BCCD52EULL, 
            0x04EA68CEF90926B1ULL, 0xD35D281707CCEAF8ULL, 0x236A227E2336DBA4ULL, 0x6D09B7CFFF7F4E11ULL, 
            0x2103A5288327E92EULL, 0x587BD7447CA6085DULL, 0x6045A05F1621FBF2ULL, 0x154010078621FCC4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeySpawnConstants = {
    0xF44667DF2A792186ULL,
    0xA4149C19AB70AAB2ULL,
    0x218FDCFDDB8D7901ULL,
    0xF44667DF2A792186ULL,
    0xA4149C19AB70AAB2ULL,
    0x218FDCFDDB8D7901ULL,
    0x7046A5D7FC279055ULL,
    0xA9D467F5E39D8A85ULL,
    0xB9,
    0x20,
    0x91,
    0x0A,
    0x6B,
    0x6E,
    0x0D,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Altair::kSeedSalts = {
    {
        {
            0x7AE2CC20E98E8E01ULL, 0xE5672C2E1D65A410ULL, 0x71B53DE069C7FB76ULL, 0xC2AF507DC1955307ULL, 
            0xD83351B3C767DE9DULL, 0x12EA17DD088BE298ULL, 0xADA00BE724A7A8C8ULL, 0x611B9A81EBCD7AA4ULL, 
            0x8562B1352DF0E398ULL, 0x879DF13915ABE5ADULL, 0x58730F3C7F58EDD9ULL, 0x03119D8A750B353DULL, 
            0xCF03754F8B82E6A4ULL, 0x6CD54B101B80EF80ULL, 0xDC1EB6988E9AFA56ULL, 0xBD363F29F1CB1C3DULL, 
            0x4ECD396CD7A8767DULL, 0x891C664C5FBDDCF5ULL, 0x04B6C0D1531D26C6ULL, 0x29F1987BF4D8138FULL, 
            0xB5EE2D646A8BD650ULL, 0x4C3868F0421C9038ULL, 0x1C56994816C09E7DULL, 0x79E2124975B4EB6DULL, 
            0xB5D9EE3EFEC5582AULL, 0x0D5F2188AAE309A8ULL, 0xE79A985B98E05B9BULL, 0x318503C5A1704DC4ULL, 
            0x0EAD896A507EDB85ULL, 0x6F97A8FA099FE1F9ULL, 0x15A6F9807E3CF221ULL, 0xACFA2013E5FA0C53ULL
        },
        {
            0x27AC43E1DFB6A8A6ULL, 0x524407E8CDC2FFFDULL, 0x525997D8DF968DA0ULL, 0x09FB1813E2004A41ULL, 
            0xEEE3E682D6F1A4A4ULL, 0x8B87B2D58703BAF4ULL, 0xACB3ECCF34564629ULL, 0xD91DE40E0DDE0AC0ULL, 
            0xE10BA4C6B36F2DC3ULL, 0x4588096B855D4AAAULL, 0x0BA1530533658903ULL, 0x7667CEE562BF5EFBULL, 
            0xF8D5D00C87F6633FULL, 0x8E8ED7F2ABE324F8ULL, 0x529A0764E3A4D320ULL, 0x421CACE5012F94C4ULL, 
            0x0D9B494ED3A45C3EULL, 0xB85F107D7CEBDFBFULL, 0x1F80D19503B6ABE1ULL, 0xF06FA49638B2DE86ULL, 
            0xB30B79973E63C68FULL, 0x3488CD7DB661B286ULL, 0xB54430A09F4029ABULL, 0xAF3086CD1954F6D8ULL, 
            0x3512B36C54C987FDULL, 0x86F0F013188F6CD9ULL, 0x2D3453B485F8C463ULL, 0xE32381CB455F654AULL, 
            0x6C3AE41C4A540D01ULL, 0xBABDE6E928F22CF7ULL, 0x906985C486D0E450ULL, 0x2848E974C7C56A04ULL
        },
        {
            0xEEACB1B7F66B660BULL, 0x7E78AF49FEB7DBB5ULL, 0xA1A724AB70C78FC3ULL, 0x827B389A5BB31285ULL, 
            0xA74861C511FD4097ULL, 0xCF927ADECCA885A7ULL, 0x7E3FFF7F37F8E906ULL, 0xE47D2D4A648C0559ULL, 
            0xF8D8A88A8C1530BCULL, 0x04C8293C235D81D9ULL, 0x13E7713C73C9F8EDULL, 0xA807157840C58FCAULL, 
            0x872133D85624F4E6ULL, 0x72F902AE110055C5ULL, 0x3EB11C6ED1A31C37ULL, 0x8C22F1E0F456EA36ULL, 
            0x2726C881ABC5A8AAULL, 0x18F658C729A4DD11ULL, 0x9812EACBEFAFD1FFULL, 0xEB79E51B7C40189FULL, 
            0x8AF987F9126517B4ULL, 0xDAA7F0CB4DDF7C03ULL, 0xB5608F527EC7D4B1ULL, 0x219A6CFC91306390ULL, 
            0x33452D5C066DEB74ULL, 0xF73FAC1496A3D4CAULL, 0xD2324A4A50B3FAD9ULL, 0x66FCF7E2D8B795ABULL, 
            0x932402C3E2F261C6ULL, 0xD00A3DFBF520FF54ULL, 0x484A2F323AAA4D19ULL, 0xFE72D013B1EF8A69ULL
        },
        {
            0x77A0479C381F6B7AULL, 0xB940D7DFFC2D4484ULL, 0x1CBE3B3A6C845F29ULL, 0x34CB6EB4D4EA072FULL, 
            0xAB7C290A566B2B19ULL, 0x0D0FCC8CCC6A6E59ULL, 0x5B608016469C73AEULL, 0x18C2A2BC08AF9AB4ULL, 
            0x6A93EA7188B2AF43ULL, 0x61F4E3ED325D89C4ULL, 0xB956C8F9FA6D2E98ULL, 0x160B53EC910226C4ULL, 
            0xFBB86DB6C310FB69ULL, 0xF7784F92356E9AF7ULL, 0xC42B5C454206D887ULL, 0x8572048B7753BE15ULL, 
            0x6962B1B42437E0A6ULL, 0xDB8D2946DB727F65ULL, 0xA922D455670FAEDCULL, 0x0F9BF7E5C861B4D3ULL, 
            0x7D22ADF1CA689662ULL, 0x366069873F18D830ULL, 0xC515B38C75385715ULL, 0xB0CE0744AD8EB2BEULL, 
            0x52DD14D358E9A7BCULL, 0xE1E0FA8F34F8223CULL, 0x6E6FB8F28B8EE26BULL, 0x9F3824693E968C20ULL, 
            0x7C4FD13359231F91ULL, 0xBE3337DDA01AAAD0ULL, 0x9782CC019CC30B84ULL, 0x29B669A900F491C6ULL
        },
        {
            0x400AF206EA7602A1ULL, 0x826CE2E52DA5716AULL, 0x6EF21CDDFEF218C6ULL, 0x08883959861943C6ULL, 
            0x1C8CBCA627C2D4F6ULL, 0x83541653A1D3CD96ULL, 0xF4843E86C93DF124ULL, 0x26CE7850F493F5BFULL, 
            0xEB1DDB917DE40B07ULL, 0x618BB1F367253693ULL, 0xB28782E7C9F361AEULL, 0x6AA7A12E19EA91CEULL, 
            0x6EFE29BDBFAE4989ULL, 0x6510D9395484F638ULL, 0xC430CDF0021BCCE5ULL, 0xA141C08492FE7568ULL, 
            0xD1B5A18779F06273ULL, 0x1351E1D2AB18F556ULL, 0x1C3649F4E652B8AAULL, 0x755201F7B97A995FULL, 
            0x1FCBD7340088C9B9ULL, 0xD161B0D6488EEC30ULL, 0x0269224C75698F51ULL, 0xF1E3ECC126A7C12CULL, 
            0xB658BE639B2C4486ULL, 0x183CEAC214F5A20EULL, 0xD654C72A1A73E370ULL, 0xF51792A7F1F0649CULL, 
            0x254D937169A736E3ULL, 0xB4A2E7812DCCC55CULL, 0xCBAC622120DFBF70ULL, 0x5C7C9AB8F6B01F6EULL
        },
        {
            0xDA5FE474CEB3077AULL, 0x4E9057E0F000A6A8ULL, 0xF86E5F89E2FBD384ULL, 0xCDAD2C3CE52F87B4ULL, 
            0x6D9EDB36DBFA3B5AULL, 0x916678122646C369ULL, 0x20F9550E3B607E4DULL, 0x08C820329D6132E5ULL, 
            0xD7095221C99D2C0FULL, 0xD7B67DB4AFCF520BULL, 0x5D58641CF6316052ULL, 0x1600076FF65ECD21ULL, 
            0x6CF1523E5D528596ULL, 0x4C58A9587829992AULL, 0xF2C00E1238710A8DULL, 0xD674FC17A51FBE46ULL, 
            0x7290996006F3A395ULL, 0xCFAB671777D82E69ULL, 0xF90840325543B3E0ULL, 0xC9C35DFA0653BF5AULL, 
            0xC2CBBBCC430F1815ULL, 0x728E1C7742A1983FULL, 0xA3546CBF7CB30B65ULL, 0x7D418BE0C5B306F1ULL, 
            0x324840AAD07DCA0BULL, 0xB50B931B997D76D3ULL, 0x6DEF511C1BA75863ULL, 0xCE93DD8EE8BBFAB3ULL, 
            0x44A9ECA06432C722ULL, 0xDB20DA664F240692ULL, 0x90DA6C54D858268FULL, 0x3745174234A7AAE0ULL
        }
    },
    {
        {
            0xBCAFAD3EC41988B7ULL, 0x606EE92229C96C7FULL, 0x80D25392C90CE99EULL, 0x573CE6EFEAB2B3A1ULL, 
            0xD6D0A5145F42A3CCULL, 0x26119C56BD775CA1ULL, 0xCE4FFFEE1BE0CB84ULL, 0xA37BAF6D71F1B6D0ULL, 
            0xD6E6744240BDD457ULL, 0xBBEA764184BA67ECULL, 0xFC648AABD5CC41A7ULL, 0x380205AB7B2C94B0ULL, 
            0x3F6271AF997F8011ULL, 0x409671480336B4CBULL, 0xD91A64CEA2C22193ULL, 0xE46808E470931737ULL, 
            0xD0E0087AE913C387ULL, 0x01DE6CEB77C56B0EULL, 0xC80664981717D723ULL, 0x0068367E2E5806DAULL, 
            0xF4F7C800A2B95BA9ULL, 0xDF5D893C357176D4ULL, 0xFFFE7A2D231DECC7ULL, 0x856F293D3BB36602ULL, 
            0x75A634827950BA1BULL, 0xD691EC02204262ADULL, 0x05999B0CE374B873ULL, 0xBBA9DA28262A86AEULL, 
            0x08CB2D9F1DF1A0DEULL, 0x9365CFFCECE1FE6CULL, 0x2461F0549D0B1202ULL, 0x1446D877CD9ABA29ULL
        },
        {
            0x0948C4AC579B2876ULL, 0x93F37396F745A12CULL, 0xC272943F83F83F16ULL, 0xCE7ABD7F8A529450ULL, 
            0xA0967573110FEA48ULL, 0x2640ACA802EE0EA0ULL, 0xF7060444EC7EACDAULL, 0x2A29FB6A0E6671CEULL, 
            0x3FADA3D3E8558B62ULL, 0x183D56060C16EB79ULL, 0x308761B97216416EULL, 0xB6D6F0EBC4A367C0ULL, 
            0xE4C2E76C031B72DFULL, 0xABF2BE481E7E5DB7ULL, 0x8D3016765A92B93CULL, 0x4CA384216733BE99ULL, 
            0x1427D8AD846B9A41ULL, 0xC068EEE2F0617B09ULL, 0xC000300DB2715A7CULL, 0xDE7BA88A8C160B58ULL, 
            0x380C9A54FCCB7E75ULL, 0x25B6599F061D22C8ULL, 0xCE920A86327566A7ULL, 0x401AC545947E1A08ULL, 
            0xF50E1723E51952EFULL, 0x3C7222FEE0ACF96DULL, 0x5DDE4DC25C24DE3EULL, 0x1C149A81A6E1EF6CULL, 
            0x61B626778C852F04ULL, 0xCEE2C130FBCCA68FULL, 0xC004FE1E1433F280ULL, 0x7A3BAE36F2229EAFULL
        },
        {
            0x5FC7F5F3918F6C8CULL, 0x28E5EA1FDAFB45AFULL, 0xDF57B6655C6C25C2ULL, 0x34947978D3274643ULL, 
            0x28B743669E53DB79ULL, 0x4AB4AEA28B68BC4AULL, 0xBC79A27F85FD262DULL, 0xE82158D89C7EFABEULL, 
            0x4305246B030653CAULL, 0xEBA2137E5303F1F8ULL, 0x4C0D76847F11F4C9ULL, 0x4DA8F50632586290ULL, 
            0x1CEC6ECA556D7659ULL, 0xEBBE47494CD26261ULL, 0xCE2B1050F4033AD6ULL, 0xE61C8356365C129CULL, 
            0x85DB57449456068EULL, 0xD6F1960D9CD69319ULL, 0xA13BCEFEA0716F75ULL, 0x2650B3D9FA799B39ULL, 
            0x6A5D665EEBB792D2ULL, 0x34150D33360022FBULL, 0xBD16822963817BD7ULL, 0x8B423079F4EE86A6ULL, 
            0x1EA02A2DA52013FBULL, 0xC2C630767C6250FAULL, 0xA44A1C585B61BA72ULL, 0xD0922C24996FDA81ULL, 
            0xA9779775237E2ED1ULL, 0x9902A64AB32E824AULL, 0x1EC39A574F6F0C62ULL, 0xFF46BA0E0701AAFDULL
        },
        {
            0x835682C32D03C1FAULL, 0xBCEC0126805C2244ULL, 0xA5C47D73267AD443ULL, 0xCA059683E05B8143ULL, 
            0x5DDF7670D58EFFD6ULL, 0xFEC566B745A614E1ULL, 0x7E45064DDAE0CEF6ULL, 0x15581883FB5CAB31ULL, 
            0x91D49C9BF820AD5EULL, 0x623C73E70216E7FFULL, 0xF547BF41521B4CB2ULL, 0x79F6FCA8CBE4F000ULL, 
            0xE67B193B5F855AA8ULL, 0xCFFFAA5B7C12B6C4ULL, 0xAB49819A95E44F90ULL, 0x08A63EE32776676FULL, 
            0xE3C216E7E692626DULL, 0x8E64D4E3BE4D3056ULL, 0x35AFAE1BC6326610ULL, 0xB07A5AE634FADDE9ULL, 
            0x5310201144A38B46ULL, 0xC59DA5A2387E0865ULL, 0x09F13E8334385316ULL, 0x06440656C1B871DAULL, 
            0x762C4E68C5A14829ULL, 0x958D2D8D4A6EF8E9ULL, 0x3AA8ED0364DE47D0ULL, 0x3E10902351666BE2ULL, 
            0x892CA88E8414C56BULL, 0x9AD96297EA285825ULL, 0x979CEC1A7019F79AULL, 0x28D3CA17D20BBB08ULL
        },
        {
            0x2D09F2E44D8083B0ULL, 0x63E08560959621D8ULL, 0xDB9D027E8D3ECCA8ULL, 0x992CE77C3184ADB6ULL, 
            0x7C2A61A5F326302AULL, 0xE48EBC270F47AB03ULL, 0x9523A0961DE5F67CULL, 0xD8B41E0226F82D7AULL, 
            0x5699F2FD8873C9D4ULL, 0xC49EC9F206BA3857ULL, 0x21B5BBB18190FE51ULL, 0x419BFDC86F934073ULL, 
            0x38A8441514C17BFBULL, 0x41AB74101557F855ULL, 0x710CC5605A1B0E62ULL, 0x23A982A55B6EDC91ULL, 
            0xDBD5FBF02FF59057ULL, 0x0DCFB1332F40EB53ULL, 0xC154A2C884986180ULL, 0xCDE878656BEC073DULL, 
            0xEF1440C049B6A3C3ULL, 0xCED3D1733AB70AAEULL, 0x6456ED449DAF6EF0ULL, 0xDFD6B33B7820ED6FULL, 
            0xDF880A5EAA758E53ULL, 0x578377F42025E1EBULL, 0x6EE2416780FA49CFULL, 0x27C17471F5FF24B5ULL, 
            0xB7DB25597D2D27D6ULL, 0x55C291633265671EULL, 0x769FCED841B70D56ULL, 0x4FBC59216B62DA73ULL
        },
        {
            0x1B6873CA8716D57DULL, 0x6321B81DF702CEA3ULL, 0xFFDC2F9145CBDA00ULL, 0xBF02B4DD5BFF42D5ULL, 
            0x8CEAA101F81AE23DULL, 0xFA738EABF0017F96ULL, 0x1306CD343749A09DULL, 0xC61CABD6278B192DULL, 
            0x92429797AE908DC0ULL, 0x259657F39BDBBD62ULL, 0xD707CF93366CFB6DULL, 0xA7A20849117A1F29ULL, 
            0xA3F5EE6F8CDCDBBEULL, 0xEDC8AE8749720719ULL, 0xE501CD65DD46F32FULL, 0x73AF28FA9C9BAF2DULL, 
            0x8CB9C39CEA1FA96AULL, 0x9212D259D3514973ULL, 0xE9A692B73B479A85ULL, 0x4B27442B5CDACE0BULL, 
            0x4768858B07449EB0ULL, 0x3C47640C46DCB224ULL, 0xBF1DB4E7D4ECD0C2ULL, 0x6DCBB60EE59CDB7AULL, 
            0x4749AD61762F798BULL, 0x1AB8C63254BF0620ULL, 0xB3A6FF83E06D6D3EULL, 0x27585B7A80A971E2ULL, 
            0xADE82F14E193BBE1ULL, 0x180BBF65A3199BF8ULL, 0x487286264A1609DEULL, 0x2E9C2083577C5B0AULL
        }
    },
    {
        {
            0x6B2E1FBB4F1C8D85ULL, 0x2241974B5A02986AULL, 0x7265B706FC7805C8ULL, 0x39D10224A37F2B86ULL, 
            0xEC32B3F6E199B29AULL, 0x974927DFA25C9FD2ULL, 0x479A8D2AB18D91F8ULL, 0x8C285D33860B444BULL, 
            0x90912ACDDE544139ULL, 0x00BA20B1680DA68EULL, 0xB784E0CCE59BD863ULL, 0x48C63DA4F495918FULL, 
            0xC790C6782DC3C35FULL, 0xC8B8BF753A69D7E7ULL, 0xDA957B13A5C9097CULL, 0x923CA3A304932A3DULL, 
            0x646DDBA282912313ULL, 0x48A8E58AFB585132ULL, 0x181E9A24B5FF9AACULL, 0x97028B801D0DBFABULL, 
            0xCDA3393CB5D4D48CULL, 0xAEBFDA78DDC49138ULL, 0x9F31E5060A581F51ULL, 0x2BAE79D5483697C8ULL, 
            0xAF77E3317BDA4000ULL, 0xDC31DA5EECE61AB4ULL, 0xBE869EE7D640D747ULL, 0x8DFEA6A1CB63CAC1ULL, 
            0x53CFDBA145C8220AULL, 0x5081F3AD78695473ULL, 0x9F72ABA888A8E804ULL, 0x8906B9D36EC01A86ULL
        },
        {
            0xA6FD6D8627CD0914ULL, 0x714A4B0C36CFC6F3ULL, 0xFE49D779C05929E4ULL, 0x6CB146EAD5BC5489ULL, 
            0x62FB21222204620CULL, 0xA533E9DAB5C206B9ULL, 0x80BF9D06A94FCAFAULL, 0x1A4D1AB482E33B9BULL, 
            0xF30CF61186FC0FF3ULL, 0xBE9097FD7AE8366FULL, 0xEC90B28E2272D653ULL, 0x044414D1C77B21C5ULL, 
            0x0E6DF957B104F0B5ULL, 0xE25677CC7749EF9CULL, 0x331ACEE6D0A6FDDFULL, 0x40CED7F74112BA5CULL, 
            0xB6392914EB4867DDULL, 0x25147BE7BE2227BCULL, 0x35C941748D6C9F7DULL, 0xA5A13C9F88EAC842ULL, 
            0x6A7120AA14DD7059ULL, 0x270343874D5CF143ULL, 0xC51EA8A4A788D8CFULL, 0x52D09AD27686F866ULL, 
            0x0081F377B0A5A449ULL, 0x3D57B9995036DCBDULL, 0x4FEADE764AEB7052ULL, 0x0A35FC446A9485CAULL, 
            0x4BDFF97B0D48B865ULL, 0x27E9AB8FC4EB1609ULL, 0x2BC86F09DEC4E365ULL, 0xB810B54A4550232CULL
        },
        {
            0x4A6F04D44A32B4C0ULL, 0x24A91F42BACB32C9ULL, 0x1B254921209B8CB4ULL, 0x6BEB6287D036CD39ULL, 
            0xE2F03FA27BFCC66EULL, 0x6432710900D79B2BULL, 0x1D01BA27BE1BB82DULL, 0x90F74C01B2868F5BULL, 
            0x0AFE560B358684D7ULL, 0x8975DFA3FA60FC62ULL, 0x1F2971B6E737D651ULL, 0x506BE86180A35430ULL, 
            0xD63000158C0BB87EULL, 0xB5B8C10D09B11BB1ULL, 0x418EA7CD381D7E77ULL, 0x0A943D704F6C1DE7ULL, 
            0x03FCC097CA79C4DDULL, 0x60E61F375D9FF71AULL, 0x77528E21AB78026CULL, 0x362C1EB4F4AAA82CULL, 
            0x4BCB27BACC95E93CULL, 0x357E7593F5546CCFULL, 0x378A3860AEA2FBEFULL, 0xC7B5C1D05B659EDFULL, 
            0xB90EE5A8BA8F9091ULL, 0xD2CFE3314374F89AULL, 0xEA280F92E6D1655BULL, 0x593E0F0500C71D7AULL, 
            0xE59B1D2D11108CBCULL, 0x0C339BEF7CC5123DULL, 0x86CB347CC92627AEULL, 0x1AE5CA9C74A91D2CULL
        },
        {
            0xA957BB6067505C2BULL, 0x6540A359DC1987E4ULL, 0x2281AA6BB721BAD8ULL, 0xED66BE4769771569ULL, 
            0x7C0C932D42D55F81ULL, 0x06F14FCED771D168ULL, 0x072024DBEDE6DEEEULL, 0xDA61F156CC13420EULL, 
            0x4ED10CA80D778624ULL, 0xC4EB366B6BBAC0E4ULL, 0x0E6EF7825E44AC5EULL, 0xAB0013BEE118AACAULL, 
            0x3DDAF1418F554882ULL, 0xB79A70D1CF3D6792ULL, 0x24184A3182886E4BULL, 0x9420CD64A75AAF16ULL, 
            0x452C68E98A1A081AULL, 0x0D10F33BE4D98095ULL, 0x881A1909E722DE63ULL, 0x85D2B731B666EC39ULL, 
            0x46B97F5005901E8DULL, 0xEAA50D5090897D10ULL, 0xE0A5F141F3D6ED89ULL, 0xBEA2B40DD4E312E2ULL, 
            0x66553EB8252D13CFULL, 0x01AFDA7CDEC9730DULL, 0xD7299D082082563CULL, 0x6972FCFFF275A1A8ULL, 
            0x3F2962921FDEB9CBULL, 0xB0C0EC317E4E56DBULL, 0x1672443EA041A6C1ULL, 0xC51DB6F0338E9C56ULL
        },
        {
            0x3D9064E5F60CD7A5ULL, 0x8715FD3781F8F2B2ULL, 0x2FACDF545B4BAD5BULL, 0x71AD5A5594BE3EC1ULL, 
            0x497B22BD58759C4EULL, 0x9FF121AA2F542222ULL, 0x9CD0828CEF2B2A8DULL, 0x12C2CE0E43EF59E2ULL, 
            0x682AAFF73A431154ULL, 0x66085FB08E6C4C89ULL, 0x6C5F123E4C1A440EULL, 0x998448A156624163ULL, 
            0x05E4C3F3D51951B8ULL, 0x05B7C3A776CDE339ULL, 0x6C10CAE70A38810AULL, 0x6B55E1AE16ABBE4EULL, 
            0xFA7329C1913689EFULL, 0x1CC257A7EB8354FCULL, 0xC8AB285246E6CF50ULL, 0x29C17A1B88586377ULL, 
            0x5134CE9167C9EACBULL, 0xA5874A020A4AA381ULL, 0x45B8DF2FB62513E3ULL, 0x07EC532DEDF8FC2AULL, 
            0x52B95EBC6CBCFD13ULL, 0xDBF41ACE87818209ULL, 0x1AAE4664A003FD86ULL, 0x5B37633D8A95E4A7ULL, 
            0x50C9BB790CC5DFB9ULL, 0x13CA6FAF5708D917ULL, 0x7B78D78A4378C839ULL, 0xCCF0955EDBCBB958ULL
        },
        {
            0x9197B91707357B9BULL, 0xC1A0094B8D41A39BULL, 0x1FC93E29F3DEF9B8ULL, 0x2CA492A291BE094DULL, 
            0x7B054654B229E0DAULL, 0xED56ED3C6CA96EF1ULL, 0x762ADF3797322358ULL, 0xDA6A0B541464BB2AULL, 
            0x3A24B8D6C5AFA431ULL, 0x9BDEDD47D073EE1DULL, 0x492EE642745494B6ULL, 0x58D3E70CD14337FEULL, 
            0x90AADDCD4370873BULL, 0x7AC98ADDA45A88FEULL, 0x931EC1D37A167DD3ULL, 0x1B925F32388C54E2ULL, 
            0x7CC53ECCA2D70D59ULL, 0xEF091B7AC1AC4D96ULL, 0xB22C9D1C02831D88ULL, 0x85BC219F26320156ULL, 
            0xBF96ED7FE2D25D67ULL, 0x7FB02F65F91DB55AULL, 0x69B122A71C4A4BEFULL, 0x4887806F1CABED8EULL, 
            0x1FE543782910C006ULL, 0x08E39811CBAE2C7FULL, 0x863BC6289742DC2AULL, 0x2F5664FA482788C6ULL, 
            0x834C3CE89714013EULL, 0xDC9F921EBE83CE59ULL, 0xF0C4917D702300A9ULL, 0xACA18402753F2A8EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kSeedConstants = {
    0xE32D3C7989A2E541ULL,
    0xE74ABEAD71BE3C6AULL,
    0x60095AD4E6A9AC0AULL,
    0xE32D3C7989A2E541ULL,
    0xE74ABEAD71BE3C6AULL,
    0x60095AD4E6A9AC0AULL,
    0x2E5C238AAF032390ULL,
    0x52FC578F3D6F52FCULL,
    0x15,
    0x64,
    0x63,
    0x45,
    0xF5,
    0xDD,
    0x42,
    0x85
};

const TwistDomainSaltSet TwistExpander_Altair::kTwistSalts = {
    {
        {
            0xE07606515BA29F73ULL, 0x4166273955D9EEE4ULL, 0x8F1BEEED50FCADB0ULL, 0xA18F38D95F781267ULL, 
            0xFC6B34C4BE4A20A8ULL, 0x245819E1985C752CULL, 0xE79BA3183B064655ULL, 0x77EB3465790D4F13ULL, 
            0x3D380D6AE569F885ULL, 0x27F300515CBA3B48ULL, 0x65543CFD2FE6E0D5ULL, 0xB6EF3ABE24720437ULL, 
            0xB99CDBB7158F1082ULL, 0x4019B442A7E8B780ULL, 0x07C1DB4FEEB2FE61ULL, 0x9CF2D0B2A53E2B17ULL, 
            0xF50C44C802559727ULL, 0x714F9E2F6F75E05DULL, 0x173DDDA64F7E9A4AULL, 0xA9488B62639D0E4BULL, 
            0x66686E881CC5C4D5ULL, 0xA6ABA714A5977310ULL, 0xBE64CE7E245D2A9EULL, 0xEF4D885C8F8A722FULL, 
            0xD634DC0692B64E51ULL, 0x5A15A154106B32EDULL, 0x33A489D250EB124EULL, 0xF555DCD9C86A606AULL, 
            0xE333CF838E6CB77BULL, 0x708EF5C2D2AC81CDULL, 0xA8B32C45CDDCC751ULL, 0x99073ED1A84C3CE7ULL
        },
        {
            0xE7310F81F278A58CULL, 0xFD0DF19D95D9086BULL, 0x07F2ECA11221883CULL, 0x2B1E1B8C43B1C42EULL, 
            0x6E8AAE2C2672B9C6ULL, 0xE233C756D6C359ECULL, 0x7E7B4AAE3506909BULL, 0x51F5ECA6F57A5859ULL, 
            0x4BC88D428EFCBB8DULL, 0x5816D8F5885475CEULL, 0xB86FBE342F828E18ULL, 0x8F9E3E9D3E066835ULL, 
            0xA433E69BDA137138ULL, 0x263FF7354BADE50BULL, 0x875535A4AE2F27AEULL, 0x1EF5ED726D242C75ULL, 
            0x9DE0B94D525CFB8BULL, 0xAEDD0DB17027FD73ULL, 0xEA37FA2F5C3EE12EULL, 0x9B513A6BD9D7F066ULL, 
            0x859E72E22E65E190ULL, 0x6D05492DD7EEB76DULL, 0xF0FD075E89E8C17EULL, 0x69FED2B5672CC370ULL, 
            0xA38EFF0F80B795C5ULL, 0xFA6307B7FDCE3BA1ULL, 0x53CCB945CD9E0FFCULL, 0x54B7D90C298B6B88ULL, 
            0x3277F4397A8872DDULL, 0xC7702D2E3BB9927CULL, 0x6848727D3780AAB4ULL, 0x49E0CD69E11039BBULL
        },
        {
            0xC422D17CB2C7E67BULL, 0x07D4D42CDA994AFCULL, 0x2AF68D5D4358B48DULL, 0x5AA177FB1C3589F7ULL, 
            0xA0CC89DBE7983B2CULL, 0x87C528D864EEB0B4ULL, 0x1885A0FF88CF63ABULL, 0xC882F35C94A29EFBULL, 
            0xFB32FD3CBE1880DFULL, 0xCBC22B547AC14B1CULL, 0x38B1F0EF2C2DED31ULL, 0x92240AD85ADA402BULL, 
            0x501B91411630A670ULL, 0x56DEEC104DAEC93EULL, 0x42E09BFC100B9A6BULL, 0x0FB647E2D7A04342ULL, 
            0x1F8E20B6C101B5BEULL, 0xACA72442B703997BULL, 0x8604039FACDB4EA7ULL, 0xE1DC2FB57B9278B3ULL, 
            0xF32080B4D5972665ULL, 0x5B2AE69F16A13CC8ULL, 0xE96570F74DFAF78BULL, 0xCBF0768D91BA3366ULL, 
            0x3C68E7855FA2EE47ULL, 0x40A3273253F2E0C3ULL, 0x586534F690BE8195ULL, 0x250B143D499372E2ULL, 
            0x641851D99A6A5237ULL, 0x0FC6680E5885482AULL, 0xC1DDE6F38AEC19C1ULL, 0xB17673B2232D7437ULL
        },
        {
            0xA27AD8B9FF203234ULL, 0x810348BE0B561CD2ULL, 0x5B5A57FE55D2F32CULL, 0x688EC7F890B01BC1ULL, 
            0x7DE4022B5065FE32ULL, 0x346636B3914D430FULL, 0x195B4FE8C5C32CA7ULL, 0x16EFBF630AFD2010ULL, 
            0xD8E8F3770156F3D4ULL, 0x2CF6BFE5E42AF815ULL, 0x0834E33EFD4F034BULL, 0x3B10EB97F54105C4ULL, 
            0x70A946DF37E1DB5FULL, 0xF4350FBB4531E94AULL, 0x4D812B42D4E1CC2AULL, 0x8B23F4D3A84E84D3ULL, 
            0x0C3061B5D194D098ULL, 0xCF2DD2406FE4A4BEULL, 0x97F29C604B9DCCBCULL, 0x2A4A3789E1CEFC2BULL, 
            0x4937F5B9591E22FAULL, 0xC2C04D6252387536ULL, 0xB0402A1868E2906AULL, 0x5AAEAF709260875EULL, 
            0xAF91C9C6B82B22C7ULL, 0xCE74B369713A086AULL, 0x3897E1BFACC3F338ULL, 0x03E0CDE1CAFB3BDEULL, 
            0x8E12840225DF6679ULL, 0x35A68C06751A8CF9ULL, 0xF41D3FCF5608138AULL, 0x90CC2050F5C41F94ULL
        },
        {
            0xA3B120E063710C2AULL, 0x15B2DCA667F0581CULL, 0xBFBCA8E19E5B4D8FULL, 0xC4E7B6717C41FCE3ULL, 
            0xF3D58E725BD14DF2ULL, 0xD0BD5A2FCB367B59ULL, 0xD03EEA782F588D9DULL, 0x87EAE967FCFCB1ADULL, 
            0x8DB3004F0B419693ULL, 0xD2936C70B31A7A04ULL, 0x4D1F5FDB5FC9417BULL, 0x271D44B9FAC0C9D6ULL, 
            0x9AD6929B5A28141AULL, 0xFD0396825E35F615ULL, 0xA91B2F5B1286443DULL, 0x3EC8F68C72F8D6EEULL, 
            0xA650588F4706C79FULL, 0x66DABA793F8A59BDULL, 0xFB1F53ACB1B92526ULL, 0xE7C6EDA6F0BAD4C0ULL, 
            0x456694E2BA8FD0DFULL, 0x39C380E9FF17B4C2ULL, 0x84C9BF8CD3E3B304ULL, 0xFE6724A45373DC0FULL, 
            0xEE7FCD256341299AULL, 0x6966FCD7678B1CC2ULL, 0x5C21B2434AFBB3B3ULL, 0x8ADAF2F1C8C7A675ULL, 
            0xBA560D5293A88DFFULL, 0x53B3A3F87C93D200ULL, 0x3D14D1C5F3226262ULL, 0xCA7115DDD5DD7E45ULL
        },
        {
            0x6611DB8E4166009CULL, 0xB749DB498BCFE26BULL, 0xFDE7C05925704146ULL, 0x47E72D5ED80351B4ULL, 
            0x17CCC6C8A4829FA0ULL, 0xDB69F5C00F38ECBEULL, 0xD473828FCB692019ULL, 0x3222F9C6282E97A8ULL, 
            0x61CD6F25A4DEF00DULL, 0x8161317D8816423DULL, 0xDA51735FA5084668ULL, 0x7B7970DAFB190DF5ULL, 
            0xFF2BE72517712891ULL, 0x13D22D8D958CC766ULL, 0x02ABDFE4627236AAULL, 0x08ECB5015F0FE025ULL, 
            0x1D98C4375570DA70ULL, 0x6E727110B9F3DBC7ULL, 0x8E6443AEC87B921BULL, 0x2F14965C7C22AC0CULL, 
            0x529E5F9A7D55D4D2ULL, 0xEC9D13D0C41BF898ULL, 0x9DE0765081F41AB3ULL, 0xCCE25ECBE2D6DCA3ULL, 
            0x8E5BFAF401C2380EULL, 0xCE4E80A3E1DFB90EULL, 0x0A404460D56C9F70ULL, 0xE960CEABF8E89B9CULL, 
            0xF1386061F4B39FBDULL, 0xF60B5E5537FF6D92ULL, 0x0E61C41256005D90ULL, 0x7E8D912DE74062E8ULL
        }
    },
    {
        {
            0x721570F69522DE31ULL, 0x2B7F2585E44FEB9FULL, 0x9AF81B01EA1D279DULL, 0xAABA1CA1E965807EULL, 
            0x7E98762B981A964DULL, 0x736EAE8531DB9189ULL, 0xB4164957455522BBULL, 0xF4794CC93946273EULL, 
            0xA0A843DB010EFF1AULL, 0x4A25E9D0DDA00007ULL, 0x7A623D408AF777E0ULL, 0xE25C6248D7AD2D46ULL, 
            0xC0FFB1B922A05DCCULL, 0x2F39F79BAA6316BFULL, 0xEA956B5BEA0A3E43ULL, 0xBED4314D5CA1FDBAULL, 
            0xCAF6A39652F295D5ULL, 0x87FBFFE1C4F0FC11ULL, 0xEA801CE7C3E14514ULL, 0x252400D99A19759DULL, 
            0xCDFDE55D1164DF7DULL, 0x07F8AA0C604C1059ULL, 0x7C7CB4127EBEFB67ULL, 0xA1F73B71B7AE5BBCULL, 
            0x073F81B3D3652B3FULL, 0x4C072B69A0B4EC1BULL, 0x0F0710300D131E61ULL, 0x72E1811D042B874FULL, 
            0xB259061D2C81CFBEULL, 0x5F158949BE8EEBC3ULL, 0xD4F26CC64777B985ULL, 0xD7DDFA212A05D652ULL
        },
        {
            0x1D66BE456F89D864ULL, 0x9EDEBBE68029FAFEULL, 0xBA3E1E36FBE2C2A0ULL, 0xC678A853762B5DF8ULL, 
            0x9C3E8B2976D025A2ULL, 0x06B53F2FFCDAEF49ULL, 0x6E4C792843C3293BULL, 0x401BC2A68CF55AABULL, 
            0x76B1A486382A9203ULL, 0x1AB78DC0E780175CULL, 0x8FF8A124ADF62F79ULL, 0x53B586DF801529AAULL, 
            0xC926291CEEBC4EDAULL, 0x83B3E290B060F01AULL, 0x769DA4B758A9B134ULL, 0x9FD1A103F563432CULL, 
            0x9856E0C628C4A6C1ULL, 0x30AA2CDE2CD3FF3FULL, 0xBA263E6D0EAE1BA1ULL, 0xD10347112B957FCFULL, 
            0x3F3F43B6EC4172C0ULL, 0x0CC535817669A3BCULL, 0x9AB6A3AA1DC0826EULL, 0x64058B3B0795D188ULL, 
            0x4FC8D6928C8E6A97ULL, 0x0FDA76060121F083ULL, 0x7EFD7A6C3AB15314ULL, 0x05F3A21E12E2DD3BULL, 
            0xBEB87731A4C5D8B1ULL, 0xE65FA75FCD723D9AULL, 0x9E90DCFA76478323ULL, 0x33F30BAC30377E82ULL
        },
        {
            0x1131AA7A643A8733ULL, 0xC52C4FC11AE562B5ULL, 0xBA737118F7D472F6ULL, 0x4276720967CB3041ULL, 
            0x47E9038921C8B0B2ULL, 0xBCCF2120F7E6A85CULL, 0xED739B913A4C0F7BULL, 0x92C53A8158CCF0BEULL, 
            0x1759A8878F10C8AAULL, 0x5917048833AEF024ULL, 0x49A13BCF1125B894ULL, 0x049BD261FEC3078AULL, 
            0x9FED50281810446DULL, 0xBA82F58020812133ULL, 0x7445B9338A195BFCULL, 0x2905C1B55CC945CBULL, 
            0x7F97175FAC422D19ULL, 0xF3D2DC76B5AFB0C4ULL, 0x99A4A94A7A099052ULL, 0x9B5D0BEC2AA36787ULL, 
            0x8E6B4D58A455AA9BULL, 0x510D47D43F5D6E71ULL, 0xF073D1E9DD424B5AULL, 0x6F05DE474ABE0AAEULL, 
            0x33893137FCBBD7F0ULL, 0x7D32685A04A48461ULL, 0xDFC83F2C4687B6E7ULL, 0x2026662A41B39800ULL, 
            0x8F5EAFEA469C42B4ULL, 0x8192F99FD595EC65ULL, 0x559225B3E5B5C2BDULL, 0x1C9EC717BC50CDE8ULL
        },
        {
            0xD48DAF80090D8A31ULL, 0xB6769D467BEC1B24ULL, 0x12D7BB74F6E3662BULL, 0x3259375C2EFB650EULL, 
            0xB14463EB51CEA017ULL, 0x5FF3424B82C810ADULL, 0x79D074F29A77E439ULL, 0xEB318832926D6D13ULL, 
            0xCA23129C32691A61ULL, 0x39852527C997E1A5ULL, 0xC4A7FC5846CD939CULL, 0x7E5630509E2F0536ULL, 
            0x31A23B59C7DFE8FCULL, 0xD879F8631FA5E7F2ULL, 0x71AB5BCE4E5DE0E0ULL, 0xC7F19E03CBBD63A1ULL, 
            0xA93B3D77267F1EC5ULL, 0x120E65A7E9110922ULL, 0xFC5E957347E0AB7FULL, 0xE6801823F398F896ULL, 
            0xE11EF0517666B2EFULL, 0x9DB52A273288A27EULL, 0xEDB1527444CB8209ULL, 0x081D472914AE121DULL, 
            0x275FB1D9493F19E9ULL, 0x118CA0BE9E4ED1EFULL, 0x715C3A2CBCCCC96DULL, 0x0359FF9CD9280EA2ULL, 
            0xBAA0607C2CD25390ULL, 0x2B7D4FB2CC56BC63ULL, 0xCFDB5EC742E4409DULL, 0x8890434A13609237ULL
        },
        {
            0x7EA130ED06ADDD6DULL, 0xF68A412F19EFC496ULL, 0x1A0FB85C09A23B7CULL, 0x78F6E1AC17B06F1AULL, 
            0x3FE075265F5CB0AAULL, 0x90FADC1CD999042CULL, 0x9037F428619C04DAULL, 0x5BB92077AF6363B8ULL, 
            0x8BA7BC3301BEC45AULL, 0x90306FA2772D09BCULL, 0x57064BFEE47E879CULL, 0x9B89613DDA1414CBULL, 
            0x95D4FD2FECCF8F1DULL, 0xE718E4F13AD996DDULL, 0xB6F881CF279843C5ULL, 0xEC84F35C96454FD2ULL, 
            0x389C706D661C5B78ULL, 0x5D718F1BE6410102ULL, 0xAC7DE3792023AE4BULL, 0x35D67B504EE352AAULL, 
            0xBDFE408EABFA68C1ULL, 0xE6661F99757BD794ULL, 0x1C92F00702D32F13ULL, 0x0B8E3913B4AFCAAFULL, 
            0xEFCA7A4D636F5B92ULL, 0x9D71B5DEDB9B8E7CULL, 0xD9F60C1DB4177141ULL, 0xE1287B781E214EA3ULL, 
            0x7034D515CD39A256ULL, 0x18CF66632B59024EULL, 0x79B092EABF04E01FULL, 0x30DAC05E0E3BE54BULL
        },
        {
            0x3B60DEB318BBF850ULL, 0xA367F2A95541D2B8ULL, 0x7A40E93EDB9E983BULL, 0xE21C8A4A559DB352ULL, 
            0xB369F9B8B0E42371ULL, 0x2647CC91BCA7C148ULL, 0x4C305F261D9311B3ULL, 0x40D63181FD923577ULL, 
            0xBF67631F8DD0BEE6ULL, 0x8206632816CC218BULL, 0xE9CA6251086F92F1ULL, 0xAD41EB08F382D8C3ULL, 
            0x80F130F781D3FAC4ULL, 0x43226195F1A872D9ULL, 0x1BA1A7B7B68C5257ULL, 0xFE4BABC5B65B0E70ULL, 
            0x15D77DF768C27EA2ULL, 0xD01081B40049D92DULL, 0xDAB0E45AB1BD8C48ULL, 0x963FA9D336342550ULL, 
            0x7EFF506B78636022ULL, 0xD47C969869FBCCF3ULL, 0x0CF582D8E2347549ULL, 0x16D5CBE04960CD0DULL, 
            0x7AEC4B9A638D2574ULL, 0x71CCF7216835F945ULL, 0x947DF12016DB98DDULL, 0x38BDA5C441FD3CF7ULL, 
            0xB08F2DFB6CED735AULL, 0xC957FF318C77761AULL, 0xE5F6401F89B5B142ULL, 0x16F8A895044A3B84ULL
        }
    },
    {
        {
            0x19FCD1F7F9789A0AULL, 0x82084FB0A0065284ULL, 0xEA21DAC98E9F6993ULL, 0x40C848F068625670ULL, 
            0xBB7BA3840A857AF5ULL, 0xF4B22B0B1C55A308ULL, 0x9643A9894C2F6FF8ULL, 0x1C88F6637B1FD16BULL, 
            0xCAA5EF69E9462D1EULL, 0x907D1762846F12B5ULL, 0x58CE517D936E4E73ULL, 0x9C2B0FB72453FD4CULL, 
            0x9B8BC0B01AF952AAULL, 0x3E73610E1E732090ULL, 0xA3E2363760CE8F95ULL, 0xF7BE741D36BE76D1ULL, 
            0x4035F6F2F85202EFULL, 0x23BD798E347E1AB4ULL, 0x2363B2F82AF7CAB4ULL, 0x0FF34775B79A360BULL, 
            0xF367EA4D92816488ULL, 0x27B8A7E375F88AEDULL, 0xE13219F43D0DB456ULL, 0x484398204CCFD6CAULL, 
            0x050AEE4878B0B462ULL, 0xB0D65BDE44A69486ULL, 0x5B5355EE829BBDE9ULL, 0x632D9F18DF1BBDEAULL, 
            0xFAE9B8EFF84A8153ULL, 0x1E4D47885142FD25ULL, 0x3D38F60505FC723AULL, 0x36B6A9999140D9FCULL
        },
        {
            0x738C35A8D4237036ULL, 0x15EB93C919EA1C46ULL, 0x60FB6ADEE487C91AULL, 0x6F1383832035F121ULL, 
            0xA8F203F5C11AFEB9ULL, 0x235BB208CFA0F854ULL, 0xEEF784C0C099865BULL, 0x55BF1C3A62729685ULL, 
            0xC3CD5D2A1822B624ULL, 0xD259E69CD22EB3AFULL, 0x4B768BE08EEF13E5ULL, 0xBF7EF8632A4A1B67ULL, 
            0x09EB973E51B903ADULL, 0x18E4534323936873ULL, 0x2CB087932C8351A9ULL, 0x0D1B166450166115ULL, 
            0x058068D996F77E7DULL, 0x9B508F0F0F4C0FC1ULL, 0x90E247C4292108EEULL, 0x8ADC7CB698D214E3ULL, 
            0x5B67E8B956A6902DULL, 0x51101E36840EB42BULL, 0xDF83E0912C25ACC0ULL, 0x8A29877D8406B789ULL, 
            0x76ED6F9086F01869ULL, 0x7A3D215C234CCDE9ULL, 0x0F6A0C2CFB5BD195ULL, 0x5E146B7B6290AC4CULL, 
            0xA38E800746294437ULL, 0x17F878F55F5374E5ULL, 0x7AEEA9B81F37EC94ULL, 0x80F414B60C40CE08ULL
        },
        {
            0x3FE2F02D20D6590BULL, 0xEFC390980A001BFAULL, 0x794310A3D24712DCULL, 0x7AAE3B350B9311A5ULL, 
            0xAF0EBA6CCAAF7246ULL, 0x110DC924EE5E5C7FULL, 0xCD8D1C7CD9FDE7E8ULL, 0x55A4BE89EAEB008AULL, 
            0xFA2D25CB9EE640B7ULL, 0x4CB559AADDDB69CBULL, 0xE65520806E5C3162ULL, 0x4DA0C920193B1129ULL, 
            0x521843F6A12A56D9ULL, 0xCBA3700F3B1EAC21ULL, 0xCF8ABC9DEA700763ULL, 0xBBC655133487D854ULL, 
            0x33DFDF9BC0B37E05ULL, 0x69C496E8023FA5F8ULL, 0xEF92AA492E049E0EULL, 0xE725D20F30A374FBULL, 
            0xFB4E65AC0C7727B2ULL, 0xF0E87A68D7324343ULL, 0xF8AE694904A85216ULL, 0xC6F2850CB87ADB22ULL, 
            0x74E3721290B3DBFBULL, 0xB5057DBD27C221CBULL, 0x3D8D8E6D15066311ULL, 0xECFC833DF6BBA586ULL, 
            0x66A15B348D93BEF5ULL, 0xF80A9BCFC0BB29B0ULL, 0x12563188F6BC29EBULL, 0xE4D228E8FE6EA9A5ULL
        },
        {
            0x0086DA6AA7D8F741ULL, 0x558B81C3F484FC2CULL, 0xA72A7EAC533F4678ULL, 0xB193909ADF38F174ULL, 
            0xFE20EAD32A81C806ULL, 0x178256E551CCC198ULL, 0x415F905754B7F5F5ULL, 0x25BDC9369FB481F5ULL, 
            0x5A73C34641613511ULL, 0x2EE6DEFF772B3C8EULL, 0xA46B47DC8D4DC745ULL, 0x3FF6092B21A5736AULL, 
            0x2B8BEE15865AC67CULL, 0xE3ED187924EF275EULL, 0xC2266196CABCF485ULL, 0x4A7CC869AEC6F1CCULL, 
            0x7CB66B8406BE9D90ULL, 0x3C8D214F46B8360EULL, 0x52C24515187FAC93ULL, 0xF19157DDF87D6466ULL, 
            0x150F89BA66D9A483ULL, 0x19174343DF841229ULL, 0x262428C4954945D8ULL, 0xD68739387B5DBE34ULL, 
            0xA951667B54367DA3ULL, 0x87256AF79C35A689ULL, 0x055C5BB27302E911ULL, 0xA769843A5687972FULL, 
            0xEF292640B1486A6FULL, 0x8317BA4DFE2391C0ULL, 0xC2B76DCD262C2B00ULL, 0xDD307AA92D899E63ULL
        },
        {
            0x28A5EB1364DE0FAFULL, 0x0172C99ED4B48F57ULL, 0x7CABC4EB1AB7A7BFULL, 0x887372DDF9F8F848ULL, 
            0x5F69055C5320B116ULL, 0xF69092A53439B946ULL, 0x71CC9B5D9696A07CULL, 0xF6ADE39BBC63179FULL, 
            0xB97AD839F57A57F3ULL, 0x0F0B44C2FCE4B532ULL, 0x1C7571A712CBDEB9ULL, 0x286308E37534B397ULL, 
            0xF612CE66511DEAD9ULL, 0xA13B93E5F986078DULL, 0x432B833E9049B8B8ULL, 0x33922751620F3FC2ULL, 
            0xC3FB8B26D00B022FULL, 0x86BFEA43C77E439BULL, 0x38AA73989CE7EA76ULL, 0xF0A8EA653EF807FCULL, 
            0x22B60DF7733B2FABULL, 0x90DF98CEB52D6193ULL, 0x21B5849A12BC7BDEULL, 0xE4DD15521BCB3FC3ULL, 
            0xA47CC25119233A5FULL, 0x9E49EA678228415FULL, 0x2A6FC9C2CE991E5FULL, 0x0B10C93F30D1EA2DULL, 
            0xE338C42F96A2C035ULL, 0x0A395ACFD5E8FC89ULL, 0x0225C239ED2342C0ULL, 0x5525AF59333B7EE7ULL
        },
        {
            0x6441A331A7587E44ULL, 0x00C7DA73E37EB229ULL, 0x439D271D1F2B9FC2ULL, 0x3CE6F742D883639EULL, 
            0xEC79A2992D1AADDFULL, 0x8C2C01C9F818CECFULL, 0xA7B2F2648D3A7AFBULL, 0x6D8727E567386B5AULL, 
            0xB997FEDCC5C6C53FULL, 0x7B568965FB15E0BDULL, 0xD384A632DA46707CULL, 0xF4BD373FBE51526BULL, 
            0x353314D36D14CE8BULL, 0xE54DDC80FA38EE0AULL, 0x91CF12E14A28756EULL, 0xE7DE262FE4DE8017ULL, 
            0xD8F4C6FB094A8A4AULL, 0x1B7B1085727146EBULL, 0xD81DB292DF561C02ULL, 0xB5F96F88696C6A00ULL, 
            0xAC7C96469A923E9CULL, 0xE81DD095C0FF43DFULL, 0xA80C901F14D85332ULL, 0x0B8A76BD7D703653ULL, 
            0x5AD075C413D876DDULL, 0xEE5EBF394DAC5670ULL, 0xBE3E0CA22CB3FF77ULL, 0x141883D93E6BA6C3ULL, 
            0x508945F70429F72AULL, 0xB86A782C28BBE1EEULL, 0x9C5C970AB21D2B71ULL, 0x0842284784A43E92ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kTwistConstants = {
    0x608F7AAB822F03F0ULL,
    0xCC0DED6C5130778CULL,
    0x19E52DCEDD6EE1D0ULL,
    0x608F7AAB822F03F0ULL,
    0xCC0DED6C5130778CULL,
    0x19E52DCEDD6EE1D0ULL,
    0xFDC698DFD0CD29E3ULL,
    0x0F71F211D248775BULL,
    0xBF,
    0x11,
    0x8D,
    0x36,
    0x34,
    0x18,
    0x94,
    0xC9
};

