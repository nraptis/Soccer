#include "TwistExpander_Mirfak.hpp"
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

TwistExpander_Mirfak::TwistExpander_Mirfak()
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

void TwistExpander_Mirfak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9A44E26C6FD458DBULL; std::uint64_t aIngress = 0xEFB6DAF2074E722AULL; std::uint64_t aCarry = 0xD47377A039DCE6B8ULL;

    std::uint64_t aWandererA = 0xE1AC773C27E54ADCULL; std::uint64_t aWandererB = 0xC7BE64E2B2F7C8DCULL; std::uint64_t aWandererC = 0xF0E83C5858D7F5B6ULL; std::uint64_t aWandererD = 0xF6EF30E0E68C0F0EULL;
    std::uint64_t aWandererE = 0xC530769F08FA1213ULL; std::uint64_t aWandererF = 0xDA2A29475A8B82DEULL; std::uint64_t aWandererG = 0xD94005A2F31A4842ULL; std::uint64_t aWandererH = 0x91F7539B2A355CF6ULL;
    std::uint64_t aWandererI = 0xF578E84A84F57B43ULL; std::uint64_t aWandererJ = 0x97EEE2E49129C85AULL; std::uint64_t aWandererK = 0xE74617220044E5FDULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFA6BA45E185CD6D8ULL;
        aCarry = 0xB839AAF11FFC4E52ULL;
        aWandererA = 0xA78D2334D2527E63ULL;
        aWandererB = 0xC40922AF9FF272EFULL;
        aWandererC = 0xE40F79C121F94314ULL;
        aWandererD = 0xAE9FEC21CA680F54ULL;
        aWandererE = 0xC94FCE293A80B0AFULL;
        aWandererF = 0xB4696BBC841CEA93ULL;
        aWandererG = 0xA53FCF3AE86EEE64ULL;
        aWandererH = 0xFADED52093F97841ULL;
        aWandererI = 0xAD20610740F48FB5ULL;
        aWandererJ = 0x8B2230BC6FDEA0DCULL;
        aWandererK = 0xB6A2CB460D13D5C8ULL;
    TwistExpander_Mirfak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC495FACF1BE41333ULL; std::uint64_t aIngress = 0xF0D2C6BA40BC0982ULL; std::uint64_t aCarry = 0xD9470332F3C4C90BULL;

    std::uint64_t aWandererA = 0x8D0C4667028895F6ULL; std::uint64_t aWandererB = 0xD0E3B6F4EE2BA753ULL; std::uint64_t aWandererC = 0xBF9A6316D43EF20DULL; std::uint64_t aWandererD = 0xE196BDA7C351D189ULL;
    std::uint64_t aWandererE = 0xA7F47B3BCD269B45ULL; std::uint64_t aWandererF = 0xDDB110886C665A0AULL; std::uint64_t aWandererG = 0xD472279EE6F6F892ULL; std::uint64_t aWandererH = 0xB64CC1C6D7E603AFULL;
    std::uint64_t aWandererI = 0xD9D5F0EDA023DEC7ULL; std::uint64_t aWandererJ = 0xBDBB1267C504A430ULL; std::uint64_t aWandererK = 0x93A6A1D45132E254ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDC3EE9EADC042147ULL;
        aCarry = 0xE7EC82DCB19068E9ULL;
        aWandererA = 0x980E0541EB8C6CC2ULL;
        aWandererB = 0xEB3C72E0DFC849CFULL;
        aWandererC = 0xDA3CC8E50BD3BF73ULL;
        aWandererD = 0xBF780117CBA73A3DULL;
        aWandererE = 0xE664BB0F0F7A5077ULL;
        aWandererF = 0xF8116621ACB543B6ULL;
        aWandererG = 0xA370FE5E5B57C738ULL;
        aWandererH = 0xE52DBD9736E29DA0ULL;
        aWandererI = 0x93436074F7824A6CULL;
        aWandererJ = 0x9042900259C2A89CULL;
        aWandererK = 0x827EE3FEA6E1F9D8ULL;
    TwistExpander_Mirfak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEB965B8E55D75698ULL; std::uint64_t aIngress = 0xA2B0E415D79E6A88ULL; std::uint64_t aCarry = 0xC2F9D9A2B33C5BD4ULL;

    std::uint64_t aWandererA = 0x8CA1B37988DE35B5ULL; std::uint64_t aWandererB = 0xADFC8775588A2303ULL; std::uint64_t aWandererC = 0x9EFD62F4F2FE9CEDULL; std::uint64_t aWandererD = 0xABFD7DC43391059AULL;
    std::uint64_t aWandererE = 0xEBF0BE8084CFCCA7ULL; std::uint64_t aWandererF = 0xB98B04A516FC2168ULL; std::uint64_t aWandererG = 0xCA016BCAF45F8D9DULL; std::uint64_t aWandererH = 0x9E3286EE18AF0AE6ULL;
    std::uint64_t aWandererI = 0xDDF0E7AACBA49D8EULL; std::uint64_t aWandererJ = 0x9EB8E3269267D601ULL; std::uint64_t aWandererK = 0x86559E41FFC85EBDULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xACAAF9DA460C04ACULL;
        aCarry = 0xA0D7D660F01075FCULL;
        aWandererA = 0xF7E91EA668F5B4C5ULL;
        aWandererB = 0xCBCAE9BC0933002EULL;
        aWandererC = 0x82EEA6FC439A813BULL;
        aWandererD = 0x80A287BCACA2616FULL;
        aWandererE = 0xCFF68E80B55948C8ULL;
        aWandererF = 0x90E893B996E5D9A7ULL;
        aWandererG = 0xA8B8F9780A387BC6ULL;
        aWandererH = 0xFF4199A8F97B91E8ULL;
        aWandererI = 0xC2099227EA2CD145ULL;
        aWandererJ = 0xC15FDAAE10398081ULL;
        aWandererK = 0xAEADAB31EC0E976DULL;
    TwistExpander_Mirfak_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFE35C45668463D52ULL; std::uint64_t aIngress = 0xAA2F5CD6EB6049D1ULL; std::uint64_t aCarry = 0xFEFED7B9C02FFC08ULL;

    std::uint64_t aWandererA = 0xD91D173555D1A19AULL; std::uint64_t aWandererB = 0x87603A03A0CB058FULL; std::uint64_t aWandererC = 0x807D56A311FE0421ULL; std::uint64_t aWandererD = 0xB9DB4E92F664023EULL;
    std::uint64_t aWandererE = 0xBF3687B3F24DE3EDULL; std::uint64_t aWandererF = 0x846D00D10F4D45C9ULL; std::uint64_t aWandererG = 0xDA56A37668DB4AF1ULL; std::uint64_t aWandererH = 0x9585144157E02F17ULL;
    std::uint64_t aWandererI = 0xD59B81D797646EDBULL; std::uint64_t aWandererJ = 0xDF771BFFA4845F06ULL; std::uint64_t aWandererK = 0x8E86F698826F0B74ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE27038FE41FD1CDBULL;
        aCarry = 0xCFBF652233538566ULL;
        aWandererA = 0xF75C45DE0738F825ULL;
        aWandererB = 0x9D724E5EB9525DBCULL;
        aWandererC = 0xFA19B2EB2EBC75AEULL;
        aWandererD = 0x84B838CE1D986949ULL;
        aWandererE = 0xFEC37A184CA56857ULL;
        aWandererF = 0xC3623FF3C90A146EULL;
        aWandererG = 0xFE0A7077AD6E2E79ULL;
        aWandererH = 0xF026D415F510F4F6ULL;
        aWandererI = 0xD73E458857178893ULL;
        aWandererJ = 0xBBFCEE1B7B34992BULL;
        aWandererK = 0xBCE63F8C0790FBA1ULL;
    TwistExpander_Mirfak_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mirfak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x91DEF1E25ECC91A6ULL;
    std::uint64_t aIngress = 0x8BC4861E205C0FADULL;
    std::uint64_t aCarry = 0xD26740AAD3F30893ULL;

    std::uint64_t aWandererA = 0xD9C28F42D2CCF0F0ULL;
    std::uint64_t aWandererB = 0xB4F061D469D214F5ULL;
    std::uint64_t aWandererC = 0x96F9EA5055725D80ULL;
    std::uint64_t aWandererD = 0xEAB5BD23CA714A90ULL;
    std::uint64_t aWandererE = 0xD9F3A2F81C53AECCULL;
    std::uint64_t aWandererF = 0xFBA04B74B12EBEF4ULL;
    std::uint64_t aWandererG = 0xD570286A902E1FDCULL;
    std::uint64_t aWandererH = 0xFFAF01FEF1CED568ULL;
    std::uint64_t aWandererI = 0xC0BC79140C87AFBAULL;
    std::uint64_t aWandererJ = 0x98824A60301AB9BEULL;
    std::uint64_t aWandererK = 0xCECA6DD9790FCE50ULL;

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
    TwistExpander_Mirfak_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KEY(pWorkSpace,
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

void TwistExpander_Mirfak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8698ACD59F7D6B54ULL; std::uint64_t aIngress = 0xEEA909FE03286B48ULL; std::uint64_t aCarry = 0x8EBA388BFFDB95CAULL;

    std::uint64_t aWandererA = 0xD617B27F316F6AA0ULL; std::uint64_t aWandererB = 0xA2B1B3CA4A250C7AULL; std::uint64_t aWandererC = 0xBB4A4C95EF51B452ULL; std::uint64_t aWandererD = 0x82C455A351F76DBBULL;
    std::uint64_t aWandererE = 0xA94DA86C8593BB9CULL; std::uint64_t aWandererF = 0x87CBE64A4633706AULL; std::uint64_t aWandererG = 0x93D0D006A7241C86ULL; std::uint64_t aWandererH = 0xFC6F81BC35BE2559ULL;
    std::uint64_t aWandererI = 0x87B51679DAF2EEE2ULL; std::uint64_t aWandererJ = 0xA25B8FAC8EEF3079ULL; std::uint64_t aWandererK = 0xD008DF0E49F429C1ULL;

    // [twist]
        aPrevious = 0xF0184F387CCB8819ULL;
        aCarry = 0x97895B6B083A5EEAULL;
        aWandererA = 0x82734A95E61C2AAFULL;
        aWandererB = 0x8D889C55002349BCULL;
        aWandererC = 0x8FCB3530A304755EULL;
        aWandererD = 0xA876CAA7BEABF910ULL;
        aWandererE = 0x8DFBF8A999C94BB6ULL;
        aWandererF = 0x90471523DA251434ULL;
        aWandererG = 0x8F9F655DECADA109ULL;
        aWandererH = 0xBED9C78E1BB17478ULL;
        aWandererI = 0xCDBB381114618FF4ULL;
        aWandererJ = 0x848D4CC610F473BBULL;
        aWandererK = 0xB1F1189DC14FCD35ULL;
    TwistExpander_Mirfak_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Mirfak::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Mirfak::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Mirfak::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 21 of 33
    // Exploration cases: 0
    // Structural maximin 509 / 674; family total 10698
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1330U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 21 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 10704
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
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
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1015U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 21 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1051 / 1248; total 21523
void TwistExpander_Mirfak::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
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
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
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

// FoldTwistControl candidate 21 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1061 / 1248; total 21532
void TwistExpander_Mirfak::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
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
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
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
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mirfak::kKeyRotateSalts = {
    {
        {
            0x2E0515DFF6414C4DULL, 0x5BD60CDE150ADFA6ULL, 0xE124E5D4AEBFC002ULL, 0x751B6619C4057FB7ULL, 
            0xAD769EF9C59BFE66ULL, 0x221706C839AA5FDEULL, 0x885C5DB1BDCA9BECULL, 0x2B6D1542EB089304ULL, 
            0x110EF78EE4F452C3ULL, 0xDB053CB4976F8BAEULL, 0xF46D3DCC1B2220B1ULL, 0x443D0CEF55F60AFFULL, 
            0x072B3087E174FEDDULL, 0x446CAA0BA7582114ULL, 0x3A6335FF40D7BAECULL, 0x343352C97E4A348CULL, 
            0x8CA7A8C2A8654334ULL, 0x565890E545F35BB2ULL, 0x17540F308B9E69EBULL, 0x6926FB2106DD1111ULL, 
            0xD563E8579E5CEF0BULL, 0x06F304120467A8E6ULL, 0x3310B92A6B72C7E7ULL, 0x00714CD7E6B92C6CULL, 
            0x19994A1C3AF6CF7FULL, 0x7D6F04B0202A5475ULL, 0xCDE5AE658264B2D9ULL, 0xCC216F9FAF810A10ULL, 
            0x6C401A81F3459327ULL, 0x31F1394829F2A1B2ULL, 0x6F8A17172C6A96DBULL, 0x5327B1E5D34EA2D7ULL
        },
        {
            0xCDE0696BE6AA9E3BULL, 0x1F7106BD4A26F562ULL, 0xABFF02F04969B4FEULL, 0xA9DF38260EE7E733ULL, 
            0xD6A7E579E543DE67ULL, 0x60BB5871F47659B8ULL, 0xCDC10027AF90018DULL, 0x95AE63DCE4045008ULL, 
            0xB0434F842489821BULL, 0x483837E3EC65BA7CULL, 0xCFF8E5222541A535ULL, 0x44E30C4C8E2586BDULL, 
            0xC53207EB7E1859B3ULL, 0x7E331F0F1DFBDE6CULL, 0x914BAB75A99A5C40ULL, 0x3994875AEA6C7721ULL, 
            0x61E1D925CC74E6A0ULL, 0x7C77CB416894706AULL, 0x5AA3B4CE315839B7ULL, 0xD5177475B1416865ULL, 
            0x9843B87C7E3EA135ULL, 0x89C224647B19FA9FULL, 0x44DB0B991CAF05A3ULL, 0xE56A9C9F69548F10ULL, 
            0xE2F0702396FF949FULL, 0x92870E401694567DULL, 0x98E7E33D2450C133ULL, 0x32889E99F9C37B54ULL, 
            0x8B9E5388A30FB8A6ULL, 0x037524C877AF54B1ULL, 0xE4FC812472806ED5ULL, 0x719FD1AE90199946ULL
        },
        {
            0x2ECB91AF5F167824ULL, 0xF9E76BC8BED25DA0ULL, 0x026FA911C95E59A2ULL, 0x9DF9D9D9EF49D77CULL, 
            0xE7EDF97951667A9FULL, 0x3DDE6270D1D4BE4FULL, 0x12069A3850A24B13ULL, 0x415B193DE4D98025ULL, 
            0xD5508CC5294485DCULL, 0x2C8302E5828B2FFDULL, 0xEFE049868E5E20B5ULL, 0x20CED775234F1030ULL, 
            0x354A68F800644226ULL, 0x28A8060BE83C75F5ULL, 0x9CA3FEA50B799655ULL, 0x4EE662A1D73226F2ULL, 
            0xA6E2D4A8E1822B30ULL, 0x1E3D186327D05B08ULL, 0xA18A20E6FEF9A5C6ULL, 0xD1C389B69967B1CAULL, 
            0xD49BB10D736BFCB4ULL, 0xD9BCEC753EF1B0E4ULL, 0x2DEF6C86D6018AD3ULL, 0x4CB89FC5D64B6599ULL, 
            0x01D82266CEF713B5ULL, 0x77ED8B3CE1127583ULL, 0x2E97CC5DBF332C74ULL, 0xE24D5036A4B6B427ULL, 
            0xE67BB77A97B4F68CULL, 0xBF579DF7E7C5AC64ULL, 0xE105F964F630A69BULL, 0x9222E869CCF793F2ULL
        },
        {
            0x7D7C8AEE0D4A26D4ULL, 0x529255D914664FA4ULL, 0xE22618CA3F3441D7ULL, 0x451BF7A5246DA2D8ULL, 
            0x24CD27A962E5908CULL, 0xFE5B2036AEAD850EULL, 0x24A7FDCA9E56481EULL, 0x0CB83F4B4FFDFB1EULL, 
            0x413CBC35F5A9F128ULL, 0x8EEB797D45AFC558ULL, 0xA4AFC3D3DF260592ULL, 0xD38A29279411A9D0ULL, 
            0xF63B96672A87414BULL, 0xBD259E7EF82B2599ULL, 0xED4796402CB5DD80ULL, 0x8370FE22521ED752ULL, 
            0xC6A02F84E642D582ULL, 0x43D81214A45F12B5ULL, 0xF9EDC829C9045EA8ULL, 0xB035A92114056973ULL, 
            0x7BE5A56871E1F64CULL, 0x11E517C37459B1B8ULL, 0xAE369B1A29265AB8ULL, 0xD38E62C82662AE60ULL, 
            0x98041DA85E6D90D5ULL, 0x1BFF6E773CC7A95CULL, 0x904396B3158D3204ULL, 0x6B43FFA46E6B185EULL, 
            0x5586A7CF37EF9E35ULL, 0xCE58D44C6D80EECAULL, 0xD1FBD5F01D2F57A8ULL, 0x6A574E57984E9FDBULL
        },
        {
            0xD838EC9C50459730ULL, 0x908D06B52C0F9066ULL, 0xF763D805D4B7DD5CULL, 0x2CFC978DD9147A6EULL, 
            0xEDB6863C200A4EB8ULL, 0x4A99AE250A92F0DAULL, 0x0DEE5150BA1A090BULL, 0xBAFE12EDC6BD5A85ULL, 
            0x8883C510DB1ED685ULL, 0x37097B87D76AA11CULL, 0x37A1D84178186B3FULL, 0x1B9905530B7766F1ULL, 
            0xE09FC273E38F383EULL, 0x487D9A9D5F0F44ABULL, 0xB2B4B775650F4C80ULL, 0x1A2E617DCEC86D94ULL, 
            0x33437DB4EA7F66E0ULL, 0x30683D8226AF5456ULL, 0x61B7048BED19C15AULL, 0x450D1B256F10E3CEULL, 
            0xF3C677D746E16734ULL, 0xDEEBED5E7FF982CAULL, 0x9453DEB9064DA4E2ULL, 0x4B5BB5DB817C1B8FULL, 
            0x7D391BFE47677442ULL, 0xF39D0F0C7ED0A103ULL, 0xCEB4825E6A3FC9F7ULL, 0xE04DE25F65F42252ULL, 
            0x386F9D741C6F3CFEULL, 0x714566B813F5C974ULL, 0x8690CA20C36935DCULL, 0x2DBBD79ACFCEC23BULL
        },
        {
            0xCB8A0D18425C4EF2ULL, 0x8BD82FEB8CA79F94ULL, 0x2B4EE13F789F93B4ULL, 0x0A0E784CE1726C10ULL, 
            0x868782D6A755B03AULL, 0xB1E2742572BDDA43ULL, 0xBE5BCED7F1BFB044ULL, 0xACDEF93E4DD36B90ULL, 
            0xF78BB9EC2BB503B3ULL, 0xC15952FD1A7ACF05ULL, 0x431B2799D70D0278ULL, 0x8BFCB600EB79ECE2ULL, 
            0x62D5190B70B94D5FULL, 0x3429419B35CA27A3ULL, 0xD907FD50DCA49F79ULL, 0x6C38AAFEB96DD015ULL, 
            0x6BDDCE01AC3BB57AULL, 0xEF212054399406A4ULL, 0xF391DBFE0C0F3300ULL, 0x2EC8474056AA01CCULL, 
            0x5542F369115C3640ULL, 0xF7336043F737C3DCULL, 0x3CFC69F9567E5011ULL, 0x75BAACFB3ECC0821ULL, 
            0x34E8187A56AF359EULL, 0x2876F0D241BA186BULL, 0xB8AA10A8A330CF67ULL, 0xA1F8CCFD25F67C30ULL, 
            0x3A14218995B94CB9ULL, 0x891DE11EBA2E4BCDULL, 0x61424081B1B2FC84ULL, 0xCC5CD97A59F91FF6ULL
        }
    },
    {
        {
            0xF744D93231B0B6DFULL, 0xEDB81EB80D87B73EULL, 0xDD76A5A82B16708FULL, 0x8E12C709807C8E37ULL, 
            0x5CFFE97C95A731CFULL, 0xCE18A36DBC21D86EULL, 0x509761D0B0A63A97ULL, 0xA8BC463E8FE800DAULL, 
            0x5539C2C44DFB43B5ULL, 0x36E93932F1A72104ULL, 0xCE352FEBB5C13ACCULL, 0x32D9B721CE828F64ULL, 
            0x395BBBA0A7FA1547ULL, 0xD016D10F90B99E8AULL, 0xA56DEC5848792130ULL, 0x1665A01DA61C35B2ULL, 
            0x34629E0A0A1B8EE5ULL, 0x88E1FCF19B6CE4A6ULL, 0x758B4DCD65206B76ULL, 0xDEF638AD1AFBC987ULL, 
            0x4F375AE98FF981CDULL, 0xEC9551F4BEDEABCCULL, 0x91B68CCF8B406165ULL, 0x8D4DC31D8C3EA3DEULL, 
            0x4322FADAC801BEC5ULL, 0x2159D68CD57DFB6CULL, 0x6061C20779BD9A0AULL, 0x32FA8871978043F2ULL, 
            0x8F9A258BAA71E1CCULL, 0x0198EF7DD3CDB0AFULL, 0xA979152C0EDA08E8ULL, 0xF56A397F4CE249CCULL
        },
        {
            0xE4A18A5A2D35298FULL, 0x4D2CDDB1D968E13BULL, 0x17D8BCE17A3F1365ULL, 0x7A41E5B1A97C9E82ULL, 
            0x37A002DE74EE368CULL, 0xAABEE66E456B2DBFULL, 0x3FC409AD32438B99ULL, 0xBB1728EE92A0EEC9ULL, 
            0x50D472718E879503ULL, 0x3B7246061E60A7FEULL, 0xED6077B46E06CC84ULL, 0xD8D47A8F34C9AE29ULL, 
            0x3A4FCBA3B8AE926BULL, 0x09B68257F7D5BD08ULL, 0xBD5A7D4A19F81FE2ULL, 0x9E875AAD7BE1991CULL, 
            0xCF8334217B0C25D0ULL, 0x81ADC305C52AE50CULL, 0xCF243D8D31D6AFA1ULL, 0x878A7A37068DF897ULL, 
            0xB3B9F6BC2DC7BBA9ULL, 0x769745DC485BD13FULL, 0xE9ED3A68DB253EA1ULL, 0xF187A1B2080ECB15ULL, 
            0x8461C1D2ADC35EC9ULL, 0xC4D043A530E8F1EEULL, 0xA9F337CE67D7641AULL, 0x8EE8FC00D0419AB2ULL, 
            0xD69C39908BCE87D9ULL, 0x0BF65928D2307F72ULL, 0x2025EF9DF1AEDFD2ULL, 0x923031A2B89B2AACULL
        },
        {
            0x624BE93E744E6810ULL, 0xC3BA7418F8892639ULL, 0x6883DE023C4C10D2ULL, 0xA08225D01573829EULL, 
            0x26335ABBAB1A9DD6ULL, 0x16776B2C36531709ULL, 0x7CB19BC961F6EC5AULL, 0x37B7D552FC006D48ULL, 
            0xBC4C5B427F41BF1DULL, 0xC75538500CBEE5E4ULL, 0x7C1F9D4B1CB46380ULL, 0x31736DEA33ED46AEULL, 
            0xFE01DF8500B023C0ULL, 0x1805815C87DEA99FULL, 0xB9BA8C443FAC7677ULL, 0x517E2E05F478B2CCULL, 
            0x955A22538F884EB0ULL, 0xB1D2F67D96B3647CULL, 0xC4878323584E2BE2ULL, 0x11F97C9ED629DE5EULL, 
            0x98DC7CA971A71D8AULL, 0x6667B17CEAAEB02CULL, 0x42962F322B6EDC69ULL, 0x2F57F556DFADC8E1ULL, 
            0x4FFAE3A1F49DDB36ULL, 0xBA6492DAA60CC080ULL, 0xCEB9F4527B7AC336ULL, 0x63D8E79D2A563D6EULL, 
            0x0A5A152409B42E62ULL, 0xBF47A983FAFB91C1ULL, 0x1F1C3812B7021091ULL, 0xB1D30E2C615557A9ULL
        },
        {
            0x77C5BF3DDEC21FAAULL, 0xDA1A3F8BE5ACB616ULL, 0x8922FBBEE150ABE5ULL, 0x1E1B230954E741F3ULL, 
            0xC37CF801ADCCEE1AULL, 0x0B65C60F9B05A148ULL, 0x88EB1842D92A7D66ULL, 0x7C9E02A0ED9FE946ULL, 
            0xDA5A3EAB45CF3079ULL, 0xF57AC2863A38C414ULL, 0xEA88550CA615ED3DULL, 0x9C43F533C6AC38F5ULL, 
            0x740C6CC63F492BDFULL, 0xFD4CEFCB6705FEA4ULL, 0x286B3436D76AA9E8ULL, 0xF825EF2FE7067F87ULL, 
            0xCD4D7706DBD6DCA7ULL, 0x3BDAB625A8EBEAA8ULL, 0xCF06760ABDE03ED4ULL, 0x530E620F654AE47AULL, 
            0x9146B0D92E444B24ULL, 0x0E10DDB159591358ULL, 0xE8513BC57DC47172ULL, 0x9E617EA018AB4900ULL, 
            0x526E0685735F3FDCULL, 0x377B583D041F5B2CULL, 0x80EEF4B133B71211ULL, 0xCD08021F286D0E13ULL, 
            0x514CEFE1603DD355ULL, 0xC0809D6EC49C92CDULL, 0x963AC85128E915D6ULL, 0xBDF98EA04A6EBE87ULL
        },
        {
            0x6D13DC35C3AC5BAEULL, 0x1ED5029509E94338ULL, 0xAC1610E00CFC771BULL, 0xD99413BE8B2B9D32ULL, 
            0x62065D71FCD12B7AULL, 0xEF0EAC6678C1216AULL, 0xE3E5094686065361ULL, 0x42BA9EED8D5E45F0ULL, 
            0xF12C56C156EA3F27ULL, 0x4A00E4384E0D12B6ULL, 0x9A1E773691DC749CULL, 0x2A9D30943282171AULL, 
            0xB3F6AEAFF255A6E3ULL, 0x3028321E84C77CF0ULL, 0x9F3BA86F518630B1ULL, 0x9DA3E9D31C650E37ULL, 
            0x996436C491F7418FULL, 0x7335D8C675588D7DULL, 0x1EE57A16A754BB5CULL, 0x4B1E7ABD41189533ULL, 
            0x336E177B8A4A262CULL, 0x26063F9374192B7CULL, 0x48FC90487E600D8AULL, 0xE4276ECF52958BCEULL, 
            0x6CD53331453F5373ULL, 0x39C72922762371F9ULL, 0x8357ACC4DF27D2C6ULL, 0x76DF502733C2ADFFULL, 
            0xBD8246473B69D3BCULL, 0x585EA186205A79FAULL, 0x4F88A4E7069B47C5ULL, 0x5CADC144F99C580CULL
        },
        {
            0x21C9AA9F032AB2D1ULL, 0x54F382F0676150D2ULL, 0x24B03CE4F4A014C3ULL, 0x68D08E257F6224D5ULL, 
            0xCF4677FB9CB3019CULL, 0x4CBDB3C5891B92AEULL, 0x7986E00268E7D4EFULL, 0x13D22E5D82E3F5C0ULL, 
            0xAB223DB60C2B520BULL, 0x8458CA5A65D3515BULL, 0x4E384F68EEA051A4ULL, 0xA2A4807DF71FAA61ULL, 
            0x22032EFC55E12423ULL, 0xAA12AFC30A8F3E69ULL, 0xB48C5A8970B6E975ULL, 0xCCA25E50711B6ABDULL, 
            0xA6D46AFDDAECEAE1ULL, 0x5E09465EAB2FAE1FULL, 0x69FBD910188B45EFULL, 0x62EFA66C200C9D0DULL, 
            0xFC9B2651D0A25837ULL, 0x3AA193F81C290CDAULL, 0xA0F0D99A6453A288ULL, 0x7B0D361C6AD2A6C7ULL, 
            0xA280B930AAA94FBFULL, 0x6638C226AF294959ULL, 0x6A7E7AE53467CAB8ULL, 0x47D71ADF638D5134ULL, 
            0xCD141A50D0ADD7FFULL, 0xA3C3E903ECCC9366ULL, 0xFF1C164054FC64EFULL, 0x00E7B5FE5C723F8EULL
        }
    },
    {
        {
            0x66EC7D1CF36660A4ULL, 0xC40AAA7C9B0233E2ULL, 0xFC6E6D5000BDFE71ULL, 0x812CA939474D040EULL, 
            0x048793E641375D74ULL, 0x48F74651C452DDAAULL, 0x7A1F27CF31F06112ULL, 0x0B1D13B2D58990C6ULL, 
            0xF6081A7DE26E56F1ULL, 0x9457A4F4E4DB3851ULL, 0xDB48B1B11C7E0D48ULL, 0x0C5EFAABF491720DULL, 
            0xC813FFCEEE4501D9ULL, 0xEF9D9517DEC71DFFULL, 0x3C33DC598674C53BULL, 0xEF6CD2987C0A5862ULL, 
            0x81723AF4068D3347ULL, 0x535026CC146873FBULL, 0x46352416E1F0CF43ULL, 0xEA0F6F7D5AC2446FULL, 
            0x8AA574D13F0034A3ULL, 0x36077AF2ABD0390CULL, 0xA895F017DFF0DA30ULL, 0x299031295FAA32A6ULL, 
            0xDBD8B78EC27989ADULL, 0xD116ABC187517D9AULL, 0x600A503060EF6689ULL, 0x288440659EDDA7EEULL, 
            0x2F26CFC6F0C07EB5ULL, 0xD50B748510A9DA98ULL, 0xD54CAF62E5F0A0AFULL, 0x82D8151A4A2DE900ULL
        },
        {
            0xCB7F9B2AE7F23CE9ULL, 0xC23FC72F85749199ULL, 0xD170375B5A3A0E87ULL, 0xFF0BA513E4F4FAA9ULL, 
            0x7304029A88227E92ULL, 0xC2880895C10D5EC2ULL, 0x28570E76015F9002ULL, 0x32D38E994614685BULL, 
            0x2DB12E3697A9E3BFULL, 0xE51EF862A66FBC54ULL, 0xE01F944CB4BEDB30ULL, 0x0AC78DF6D2D2437FULL, 
            0xB3FE9F8D5948FA3BULL, 0xD919216B24910999ULL, 0x1F533D7BECE2BA77ULL, 0x40628B85D350D817ULL, 
            0x9E6621FEA8C091EFULL, 0xCE6AF7E19006533AULL, 0xDC2268125D62D5EBULL, 0xD16C77E198BE73B5ULL, 
            0x79A67E191B0E6358ULL, 0x3AE97BCC93ECA4E7ULL, 0x31989CF4E050CD8BULL, 0x257CB73C6D060CFCULL, 
            0xA513611B84B30490ULL, 0x24782FFE8557CF63ULL, 0x10453ABDA23C487AULL, 0xE584B642068B8752ULL, 
            0xD2D8EA8D46412F54ULL, 0x81E48F493D4F6785ULL, 0x8364A1FAB2919A0FULL, 0x06AD3885D9313368ULL
        },
        {
            0x141EC4A69A38974BULL, 0x8682C4335A3E97EBULL, 0x5317DD6CEC3F7A8FULL, 0x43E78F9597F03020ULL, 
            0xFD36DF2D572670EEULL, 0xF0802113E9FE4915ULL, 0xCD816772A38F1B17ULL, 0x0F6CFA30790061D5ULL, 
            0x8918DB9B61E9D1E0ULL, 0xFC2443D9421C1CDAULL, 0x5AECE1289C171CC8ULL, 0x8EF6064EE180A6E5ULL, 
            0x69F8D3DA3AC436F2ULL, 0x622A5688F9C1F865ULL, 0xCC2BE55F406C971DULL, 0xAF71D998C8C972BEULL, 
            0xAE42DE35FFC44041ULL, 0x23E191E2645558EDULL, 0xDF66CF14B03D38F6ULL, 0x8D804F403361FFDDULL, 
            0xFB3ADD29C07C7AF2ULL, 0x9647B7749D14ABCDULL, 0xE78B0DC2600C9467ULL, 0x355617FD9B45F1D8ULL, 
            0x81E8A108D563BD3AULL, 0xAF836C1FF9B12FADULL, 0xE9C96D926893A520ULL, 0x74581F55626DA9CBULL, 
            0x7A978568A5F455E7ULL, 0xFAA410ABD7C32550ULL, 0x010E6B8BC49F8547ULL, 0xA06C8B87E3338386ULL
        },
        {
            0xBA8C39A501F47480ULL, 0x47F05D7A5CB17F09ULL, 0x2508D2F1A734EB7DULL, 0xA129DC00F39409ABULL, 
            0x4B0E051D35E7375AULL, 0x0368D783189F12DBULL, 0xEB6F6EDCA3AD92B0ULL, 0xB4903CCDD3836CBFULL, 
            0x0F8B13E83F5811A8ULL, 0xC521EAC96CE3C213ULL, 0x430E1A24E2A8A38AULL, 0xED0C45788D9E985AULL, 
            0x2EE9083D1019F7CFULL, 0xCF8E2D77472D5A28ULL, 0xF199E9944818C4C8ULL, 0xDE1B30887BF5CBF8ULL, 
            0x2A8818ED12B0FCECULL, 0x0B6CA98D52DCCECCULL, 0x24F980995A23690DULL, 0x03B46115DAC1F4F4ULL, 
            0x0A4464784D498331ULL, 0xA627002952E431D5ULL, 0x9995545DF3C52539ULL, 0x832804A77ADB24FFULL, 
            0x3F6C5847DF8820CBULL, 0x999E205626490460ULL, 0x5DA16E63DCF155C2ULL, 0x18A9B3BB8788D2B3ULL, 
            0xCC21219E7A2DF45CULL, 0x6FF93DA86F065330ULL, 0xFB92D9328E08CF86ULL, 0xA9F0BA89CB67DFC1ULL
        },
        {
            0x8958B4FF859286BEULL, 0x74C24587C59F2B80ULL, 0x12F01E57CC417D85ULL, 0x5EEE1B7CAD4EF836ULL, 
            0x13AADB67536E9E26ULL, 0xC51FEE5A6688F2B5ULL, 0x18FE452409BDC337ULL, 0x0BBFF1D752CB4312ULL, 
            0x0F4C26E6CA98A08AULL, 0x5000B313EA96528FULL, 0x73A190C877BFB461ULL, 0xB38B1F13532DDFEBULL, 
            0x4C22D99F435A4984ULL, 0x4D6197AFEE24AEDCULL, 0xB298D53D17CD1620ULL, 0x1C4398FF0ED3BA7AULL, 
            0xF0793EDAB98208EEULL, 0xEE5F224D4E2DE541ULL, 0xA16F93150A30CAFCULL, 0xDF969B8FA30C225EULL, 
            0x6617FB4137FD8E44ULL, 0x2C65930E526B284CULL, 0xF8A9408467DAAF13ULL, 0xCC60A8818E7BBCB6ULL, 
            0xC2AE80E15335ECE9ULL, 0x2E13C558D1A0A752ULL, 0x7395B1F33A8AFC39ULL, 0xD6E9C134E3EA296FULL, 
            0xD4A99B0EE5592346ULL, 0x5D4BC012A032CE67ULL, 0x93026BE63FB14A4DULL, 0x331D9A04FDA9E3CCULL
        },
        {
            0xE2E4CD017F6FE09DULL, 0x611AEA46AB38B21AULL, 0x28D26B29DEF59BD0ULL, 0x49296260A4FD9B19ULL, 
            0xB6E2467338263D94ULL, 0x89AC178581AE154BULL, 0x783A79F6756076DEULL, 0x35817CF69BF7CA03ULL, 
            0xBA71A62767A52DFDULL, 0xE204499EC5A0195AULL, 0xAD9068FBCC42B9CAULL, 0x39B8AFEA8845DF2BULL, 
            0xBA5D49661EC84B02ULL, 0xC3FC0F05558996D1ULL, 0x6C082C965DBE14E2ULL, 0xE8B011FC9FECCF0DULL, 
            0xB6A60816D97B4946ULL, 0x9A73210A5B0F7042ULL, 0xF638691898335C20ULL, 0xD06F19798B0CB1ADULL, 
            0x6A14E5865ED2B164ULL, 0xD84CB2FFB5EF6B8EULL, 0x2837A28AD7398DC7ULL, 0x1CE3315708B89552ULL, 
            0xA6381A8DF8C9DA58ULL, 0x4D100CA8A14AA83AULL, 0x76BBF5ABF3207A6EULL, 0xCEC95097018C216BULL, 
            0x15504411557F2378ULL, 0xDEBEEFD49EE3E363ULL, 0xD34ED53F2CBE7DDEULL, 0x0C38E1389DE80994ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeyRotateConstants = {
    0xB8D8DBB6312043EBULL,
    0x8B3BABEA1DCBA1B7ULL,
    0xE4FD3A9FCFB667A9ULL,
    0xB8D8DBB6312043EBULL,
    0x8B3BABEA1DCBA1B7ULL,
    0xE4FD3A9FCFB667A9ULL,
    0x501FF066A3F67F9FULL,
    0x1AB42DA37823141BULL,
    0x4D,
    0x7D,
    0x56,
    0x6D,
    0x44,
    0x2A,
    0xC7,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Mirfak::kKeySpawnSalts = {
    {
        {
            0xFA457E56651B1EBAULL, 0x8AF4C6F23B3EE081ULL, 0x6879BBAE5102878AULL, 0x977F682FED09573BULL, 
            0x49AD36801CECC07EULL, 0x1DDA2E7173455028ULL, 0xD566088C76AA6DECULL, 0x917C9339FB8C6E07ULL, 
            0x7E4332AB742C3342ULL, 0x019473DE952246ECULL, 0xFE2606AC35B5018DULL, 0x0D108318050FA354ULL, 
            0xC110B9019E48D72FULL, 0xA32CF6B9FBD8FD0BULL, 0x384EC735705FB6EBULL, 0xBADF6444F621C132ULL, 
            0xC3BEF5FA6306FF7DULL, 0xADC30400946AA0B8ULL, 0x0B1555D55BE68500ULL, 0x744011C370F8182CULL, 
            0x1B1810F4603D1B44ULL, 0x3BAE1099F467AF66ULL, 0x73AE7DECB18BF841ULL, 0x1023DF9BC080C48EULL, 
            0x89E065BF95B1DA93ULL, 0x4046150B50F7B137ULL, 0x7B4C3B98DB2B6738ULL, 0x66F2415052D3727CULL, 
            0x030F05B23FE21479ULL, 0xB3E05B52E7E2A7A5ULL, 0x00F4F0D0C5DCF839ULL, 0x4B74229DF4D27FCCULL
        },
        {
            0x89643F9CCB418FE2ULL, 0x1B780FC37E8C7E3CULL, 0x51F6F7D514D77D2EULL, 0x510F79DC2690AEE1ULL, 
            0xD83341401A7297D0ULL, 0x69128BFBC297D501ULL, 0xFA68A81CE5EE746DULL, 0xB7E9A9AA0457330EULL, 
            0xD2731BED07DB9930ULL, 0xB4CEDF960795B729ULL, 0xC204954F6FEF3801ULL, 0xD683EEF6204DA313ULL, 
            0x9643CB2AD9C6F93AULL, 0x1F59686D1683C8E8ULL, 0xA207CC27BB438A26ULL, 0xEB873E300A7D5E6FULL, 
            0x2B48937FE7E59D02ULL, 0x347E568202DB5B52ULL, 0x54820805581AC0D1ULL, 0x936F1118B592B680ULL, 
            0x34F4E4BDAC599CB6ULL, 0x78EEEC4A57C39904ULL, 0x248BB68EFE9FEC3EULL, 0x36F2AB7744B9E3A7ULL, 
            0x332153511A284506ULL, 0xD7E3D17AC05A4221ULL, 0x91A62FF887EEE908ULL, 0xC733EF4920FED3A7ULL, 
            0xBE253FE57BB5FE56ULL, 0x9337197467BC1F09ULL, 0x5111A310F6D4B22EULL, 0xA23EA7E256EFD5E6ULL
        },
        {
            0x45E79D5B3BBC6024ULL, 0x095086E2084D9A87ULL, 0xCB444FA094526252ULL, 0x5F68B219C6D191ACULL, 
            0x0C927ED79D145390ULL, 0xBCE025F46F42F42CULL, 0xF357C6241341560FULL, 0x4C4450DE5BFAE568ULL, 
            0x7107DB8DAE65A98AULL, 0xBD7BC84F843ED01CULL, 0x0F7EE5E7F9941BD4ULL, 0xF65A166A8A8E87E1ULL, 
            0xD52454515A4A6745ULL, 0xA830CF6B916A6FCDULL, 0x4AAAC4512A4141F9ULL, 0x05B5139B208D2F2EULL, 
            0xD1A2EC5A8CB208F6ULL, 0xFD865279C69CC4F9ULL, 0x5482E79457198826ULL, 0xA94C615530BACA34ULL, 
            0x85CC9D32D7FF48D3ULL, 0xB194700E6BCE6A79ULL, 0x6E2FADF97368FF73ULL, 0x819FA757D715A600ULL, 
            0x8F6D539719DA72CCULL, 0x51104FBEE98BDCADULL, 0x1D91E2D3B7C5D372ULL, 0xF232E5DD504B90D0ULL, 
            0x35DD450DC8B576CEULL, 0x2B6455EE9F15E304ULL, 0x662D6FAEB9790329ULL, 0xBA43594FD22B7110ULL
        },
        {
            0x9597799C4E3CA579ULL, 0xCD86F804AE21929BULL, 0x27442F5C283A6FBEULL, 0xC9AB1A3CEE02B0F9ULL, 
            0x76E50F04229132B6ULL, 0x1C6AFEC7C855DFF9ULL, 0x4A20E768AEE4B653ULL, 0x29B7FE6EEE47D0F5ULL, 
            0x354C04B447E418A1ULL, 0x1CB291B6E5BA4001ULL, 0x19F0988D93202A48ULL, 0x8F19AB407794E5BEULL, 
            0x71A540FE64B04111ULL, 0xE01CABED6797192AULL, 0x85A5B356B65E887BULL, 0xF1FF86A628A93A63ULL, 
            0x4972C9398A6AAA64ULL, 0x96661A8D79B678E2ULL, 0xA70A34FFD99094C8ULL, 0x42206DD19D08FE72ULL, 
            0x1311EF4DA12100FBULL, 0x5DB3B5FBB11C1FC4ULL, 0x36494A619C95C006ULL, 0xE3ABFC3F5A64785BULL, 
            0xA629C2477B61A414ULL, 0xFE99773E97261A0DULL, 0x97D147BC94C2E687ULL, 0x553032825803E19FULL, 
            0xD326F43CDDDDBDCBULL, 0x82D055A2EA1A2E7FULL, 0x1B487BCA964489D1ULL, 0x5D43AF3C44541A6CULL
        },
        {
            0x8E547BB9BDD89370ULL, 0xDD1037BF0D4230A0ULL, 0x59F5CFCF81AF41E7ULL, 0x0789FFDB0388095BULL, 
            0xDA91B21A13368484ULL, 0xA32D9A4E2F674361ULL, 0x358A80DAA62A8D8CULL, 0x6C6776A58A7F7D75ULL, 
            0xA3E87DF4B48DFA62ULL, 0x5051E90DE7FA2FD1ULL, 0x4734665407F20503ULL, 0xAA3B664FB8450798ULL, 
            0xF15BDDAD2F861F4EULL, 0x6DC3F19F64EDBA68ULL, 0x063392D698143411ULL, 0x421D57E25D33EC80ULL, 
            0x64B3FBF79978BFD0ULL, 0x0F29F57DA98187CEULL, 0xE0B0AC388DBE72EAULL, 0xBCEE29B3A1DEA7B0ULL, 
            0x527464558A34E252ULL, 0x8445CE4AE4D36E93ULL, 0x491C609755365318ULL, 0x3B296F6B5A7AFE70ULL, 
            0x055E309BB2475E10ULL, 0xCDBE2F9CA5A67565ULL, 0x3BB4B6E511DD1657ULL, 0x1DA1C5F617178B63ULL, 
            0x2F4E4B1A49ECA6A1ULL, 0x9E52B3EF66679CE3ULL, 0xCA3855F59908578CULL, 0x1ADA05F232E2D307ULL
        },
        {
            0x5131C84AD5CAB3AFULL, 0x9624CFEA1B2AF2A5ULL, 0x0265FE72AB4D97E6ULL, 0xD0BEC2669C53539AULL, 
            0x615CD2999F24A83FULL, 0xDB0968527A95431AULL, 0x189BAC208ED62D45ULL, 0xFC32AAE050BD70DAULL, 
            0xE237FF56FA01DDEFULL, 0x0D10DC097678469BULL, 0x23503D6EED27818FULL, 0xB499EA35006152A0ULL, 
            0xCB6B24BABB2B2A1CULL, 0xF45027BBA554A549ULL, 0x2FEDA5BC256649D0ULL, 0x578DC73E1086917AULL, 
            0x98A66D1FFC84AE6DULL, 0xF0DF63E402D31917ULL, 0x660B6EA769E979E4ULL, 0x485B357840D399C3ULL, 
            0x1CEE9A5630C0F432ULL, 0x7F542CF8758047FCULL, 0x487FB4ABCB5A111BULL, 0xE69AD0CC366FD7B2ULL, 
            0x72CEC401D2273C1BULL, 0x4AFD0659CD1B3326ULL, 0x7CD3FBA321C3DD03ULL, 0x8D983E478377E7ACULL, 
            0xE450BBB48833471DULL, 0xBC4D2D5F95EEADBEULL, 0x8312B3CE3D8CB1B9ULL, 0x493F15C11E4AC970ULL
        }
    },
    {
        {
            0x27E7335DA5E1CD88ULL, 0x98DE41503483ED25ULL, 0xC6FFE4104AD5B237ULL, 0x8F2DEC1188DB70E4ULL, 
            0x63327F8FA79E2358ULL, 0x05725213B4792195ULL, 0x1E3430B42EFBADE1ULL, 0xD54FF8D21ED352CAULL, 
            0xD562E257E8CEFD5BULL, 0x4B477981EFDE315AULL, 0x9E7EAC0E7493CA35ULL, 0x0E379164C9ADA806ULL, 
            0x3B66FF66138990F0ULL, 0x9889753AB96EF7AAULL, 0xDCB566E6E906D8D0ULL, 0xFFA9EFF3DAB2BEE5ULL, 
            0xE3732E4B6F2ADE3CULL, 0x9331781E8736F4C7ULL, 0x29E9C8B507DAB8B2ULL, 0x4AE5444B78B8CC5EULL, 
            0xF487DC122E5F0F61ULL, 0xA949B398503BD7DEULL, 0x1F9BAE09ABEF3169ULL, 0x9AA5D41C4A2C677EULL, 
            0xBA89F9546446ADDBULL, 0x869BDB1059EB2CE6ULL, 0x85293F18AA8EAAD5ULL, 0xA08C3561075A621CULL, 
            0x686C35918DEDFCD6ULL, 0xD7DC5B3F514A15CDULL, 0x674124D8E4692A76ULL, 0xFC58842DE115C263ULL
        },
        {
            0x47D5101763467CA7ULL, 0x5062C090B48842D5ULL, 0x0A43CA2EC39B80E8ULL, 0xE24AF3A302C1A9F0ULL, 
            0x8004F8CA7413C4ACULL, 0xE8F41D31ADDE660BULL, 0x129890617CEB55F7ULL, 0xE767580BCBBE5C5FULL, 
            0xA4F986C1497B5453ULL, 0xE7C8A2FA6A050973ULL, 0x64200EB0E95B3E64ULL, 0xF0E409F8337DCE54ULL, 
            0xFC6BC49518CDA27CULL, 0x116313B2A53F6222ULL, 0x503167D44A162855ULL, 0x0BCD004AFF46E68EULL, 
            0xF3DBBE87BD293A06ULL, 0x144249A25E730153ULL, 0xD70A729A003B5F36ULL, 0x8FA606E387ED261EULL, 
            0x49C7CE5C041E9DF5ULL, 0xA1113D61C6C198EBULL, 0xB8ED3E09E32B056AULL, 0xAEB0E8716382C67EULL, 
            0x41DB83C4E2060264ULL, 0x45153C9BB340270CULL, 0x9692BEBC139EB03AULL, 0xAE822C216FC77E07ULL, 
            0x918369D08F9656CAULL, 0x397E5C4A48B8B378ULL, 0xE513FAA92D35B40EULL, 0x3569C5EE04C05E02ULL
        },
        {
            0x9DA47A8D5B3E175FULL, 0x3630F0ED83828081ULL, 0xBF435883C95A2760ULL, 0xFB236627CFD78EB2ULL, 
            0x38B9BC14BE2B5D07ULL, 0xC199591173FEEEC5ULL, 0x5FBF12CF17E57854ULL, 0x33BEBC47E060383AULL, 
            0x94CD33FAD987F837ULL, 0xAFDB428A18CC30ACULL, 0x6C061967CDAE51D9ULL, 0xCAFD3854AF3BE921ULL, 
            0x957E02B9234955E9ULL, 0xC903608CA91D4DC1ULL, 0x19A4EDC9C05BEC6AULL, 0x3A604805D51BD86BULL, 
            0x1FC824C226F33D07ULL, 0x6239F9963BB30D0DULL, 0xE13CAC0581A260DAULL, 0x40A1909048E55F86ULL, 
            0xBDDF8230363DDDFEULL, 0x50AB823547473296ULL, 0x905DCD35BBB8B6CCULL, 0xA368C17649AECF27ULL, 
            0x8E50F9BB15D11C12ULL, 0xF215B48F549AC22DULL, 0xAB5853F29C737953ULL, 0xBE8A3467927C3919ULL, 
            0x635AF832A28E4ED3ULL, 0x8CD26ED1DCCCF98FULL, 0x2B6E7765BC32EA14ULL, 0x1AB96C292F2DF1E2ULL
        },
        {
            0x24D1461285D327CDULL, 0x90E74D5A78DE47BAULL, 0x0E21B082806F8BD9ULL, 0xCA1323E2A6F77668ULL, 
            0x45010DA61CEFE0BBULL, 0xC57E7AFCF50983F1ULL, 0x578A4509D05893D2ULL, 0x6A7B359CDBBF2DEAULL, 
            0x9167F45CD2860833ULL, 0x9DDE966C5DD16D23ULL, 0xB4E85E243723D88DULL, 0x13C5FBD0B4627793ULL, 
            0x4713CDDBAA96F9C5ULL, 0x08CBD92C1BC2773FULL, 0x3599B528F4E968A2ULL, 0xE194FB315E73942CULL, 
            0x79B4303BD920F450ULL, 0x6AE3FB8DED0622C4ULL, 0xB9BFC8782D25638FULL, 0x7C6A12A69B69DC4BULL, 
            0xD024CBCEFEB2A7E4ULL, 0x7406C98639261A67ULL, 0x5B51775D96226B81ULL, 0x4CFEFA7B4FDEF76AULL, 
            0x4DDB146890EE79A6ULL, 0x773817CAB2B26A58ULL, 0x41822E9DF32DCA94ULL, 0x77AE6A8F9980EA93ULL, 
            0x7BA7C6183E7F0AC1ULL, 0xE58142EFDB3F9526ULL, 0xA29BB2AF3266A7A2ULL, 0xB81E57F1A4F7791EULL
        },
        {
            0x20406218AB4658C9ULL, 0x131F3D0EE92CC738ULL, 0x2685CEBF0ACE1D5CULL, 0xFDCA812198E132B2ULL, 
            0x40DBEDF927415861ULL, 0x421477A196638FA4ULL, 0x7AB0E061CC57EC23ULL, 0x3B38F06DCFF4BF92ULL, 
            0xE3ACED72AE5F7506ULL, 0xB5114E864F8BB28BULL, 0x1C79C4B805E12436ULL, 0xAED9086015A0D1C8ULL, 
            0xC8FE125F5511192FULL, 0x5B8ABBD5CB268D80ULL, 0xA9495C9B1B78E98CULL, 0x6D49227F03EBA3C7ULL, 
            0x983274891C492D4EULL, 0x39FF9776945C1940ULL, 0x10D3A2632B5B1B4EULL, 0x3F5114B32F8B34BFULL, 
            0xC37B3B3673931593ULL, 0xC241EAC4BC653629ULL, 0x0C6122071C2D4DA0ULL, 0x5A8BE86BB31BF982ULL, 
            0xB14D98D0EFC7BBA9ULL, 0x638981A6F6D910F3ULL, 0x660F1C620FC0750DULL, 0xD3FDC601466D0143ULL, 
            0x3988062898F2F2FBULL, 0x57D22933C504AE64ULL, 0xCB4CA771CBB4D055ULL, 0x5EC467A3FA155B25ULL
        },
        {
            0xF54486F8FAE0EC09ULL, 0x8B87127BA4D21DF2ULL, 0x2CDEFF242CD8F19CULL, 0xC0402F16533C461DULL, 
            0x056282F915BB4D14ULL, 0x5E354C0C8C234463ULL, 0x910635C27EB5F7CCULL, 0x69EAC9DE913FD2CCULL, 
            0xD734D13C9474BBD4ULL, 0x68CA9B393E1C0D68ULL, 0x40E43C968EE62116ULL, 0x5EE147D574518967ULL, 
            0x8B6F4F9E6B2C6C72ULL, 0x5B220BE118DE4C97ULL, 0x51D81117E1EA691BULL, 0x2BAB65A1554C5297ULL, 
            0x321602485E7E8D4DULL, 0x67C53F27A490B28EULL, 0x4350944BE7F50061ULL, 0xB6F884D056BEC2C2ULL, 
            0x60D0268B5079AE40ULL, 0x5C428CA03EC5D065ULL, 0x8E71DAD6D0379F25ULL, 0xDBC049E7F661A00EULL, 
            0xE5F07FAD4F88F4A1ULL, 0xE43E5741EC971559ULL, 0xBB46C17D0124B5E1ULL, 0xFF2555FEA29015F7ULL, 
            0xD8141552C55080CCULL, 0x2702B3863D50FB87ULL, 0xD5BEA9C0901840A3ULL, 0x870C4A68EE4810C4ULL
        }
    },
    {
        {
            0xAA4259041B503B67ULL, 0xDC704110E3C8ECC1ULL, 0x31BABDFBA0019D50ULL, 0x27C7844BC9CFCEAFULL, 
            0x860460B46FD3B5EDULL, 0xDEF163E935962F9EULL, 0x61C07E720FB32258ULL, 0x982DB4A1D91E5DCCULL, 
            0x391B852F0A5BEDAFULL, 0x909AEEB0C8DAF13FULL, 0xB238DCB3101D4159ULL, 0x6E8007D1EC4B2966ULL, 
            0x7154EAF28DF0C0C0ULL, 0x914A1E73EBA22633ULL, 0xD2D84D3D968D9620ULL, 0x72EC8C2485E19C3CULL, 
            0x472BB6182DC8719BULL, 0x5D8196C334C6297EULL, 0xDAFAC56F6C8B4605ULL, 0x21B18B103D5171D9ULL, 
            0xF243E34B5DBCC1ABULL, 0xB4DEEAE411F155BBULL, 0xC4D9496136D6880DULL, 0xEB96657A8AE7986AULL, 
            0x8A2C3D328C7A5AD8ULL, 0x6EEC37F250A695D4ULL, 0x7DF36C1C02002AE7ULL, 0x224692EF4245C008ULL, 
            0x57622AF45D0EB514ULL, 0x1FC4942C7D2A8906ULL, 0x2103ECDE0EBE2198ULL, 0x4ADEEFEA46731EB6ULL
        },
        {
            0xF44B6494D72E6B6EULL, 0xE3745F42EE78260BULL, 0x5A49768EE2780C19ULL, 0xF9BAFD0DC200A64BULL, 
            0xFEB48E2FE8B8633FULL, 0xA312B04878217078ULL, 0xC7D4FACFB45324AFULL, 0x6F4AB2923833AAA1ULL, 
            0xD4D99F0BBC094678ULL, 0xE20F1C27557148AAULL, 0x5C299FB3D7705D9EULL, 0x6BE8DA800D18D4E5ULL, 
            0xBB337AE874AC11F5ULL, 0xF36CFB57F7AF50E8ULL, 0x29A40F4C6967F49FULL, 0x2AF9CD77171DB051ULL, 
            0x97298B66E1248800ULL, 0x2358201348B4431FULL, 0x9B33F73B9137EDECULL, 0x04C60625D6D61E6CULL, 
            0xDF8E09CECAE4CF60ULL, 0xF502A5283B94D126ULL, 0x6FCE38CFB845F206ULL, 0x1BCF35E4B6844C65ULL, 
            0x6C413B58982A293BULL, 0x2CFBFAC8D90D2B9FULL, 0x027403BEFF354199ULL, 0xEFE83006449723B0ULL, 
            0xE3DBE1B12BDDED1DULL, 0x44E5E49C28FAAB4BULL, 0x89BA8D6F47588E7FULL, 0x3EA6F928A04116E8ULL
        },
        {
            0x21294EADC9D82356ULL, 0x95946C418B418969ULL, 0xFF14728D24F68586ULL, 0x88CB611E352E3E2CULL, 
            0x0E78DEA205539288ULL, 0x6C324837CFD78608ULL, 0xF7141D7154B460B1ULL, 0x1080530115257BA0ULL, 
            0x5FAF1262CA8143ACULL, 0xBB6D66EA84D2CED4ULL, 0xBBFE7655F256C9D8ULL, 0x50520C7EDB929C55ULL, 
            0x8F1205987014E2B2ULL, 0xA32F470FA3EA5F0FULL, 0x5B6AA0E04B4DF749ULL, 0xE7D46E96AEF735B2ULL, 
            0x34095C697B8FDF36ULL, 0x9F8C43218B5677C4ULL, 0x60E471467C969225ULL, 0xA871D0D11A1D6FD3ULL, 
            0xD46BF9A20760D341ULL, 0x9C74559BF7B3C20DULL, 0xE1B03B1E5A4DDBDCULL, 0x8498F62248140F34ULL, 
            0x45E012930BCF0B57ULL, 0x2F7C19825547A2ACULL, 0xAA7253C503F9E28FULL, 0xFB46896933AF83E6ULL, 
            0xE94DA41A87CBFE13ULL, 0x89FD6586C9E62F00ULL, 0x02EF47AE2E662393ULL, 0x693B0283FFF92E69ULL
        },
        {
            0x3B92523AA80D91F0ULL, 0xB1AAEFF9A9A14653ULL, 0x5BE8436529C1AF53ULL, 0xB99719F1E74BA23EULL, 
            0x5CDB948EF3C78E76ULL, 0x5617771AC6537CE3ULL, 0x614407C4EC0E364BULL, 0x3B3C615732AF8210ULL, 
            0x462597B8A9479940ULL, 0x113AD6D89EF1EFC5ULL, 0x1CEFE00A6D40AF3FULL, 0xEECF1A94D6F497FDULL, 
            0x755989E84534B8A1ULL, 0x65FF9A40E1A8E977ULL, 0xF2ACBBDFDBB14079ULL, 0x6F9504C71AB65694ULL, 
            0x2E4A9CD1F4E46958ULL, 0x4B51B3CC8C7FFCF6ULL, 0x7FEF462A1D62EB2CULL, 0x2C0895763C7661E1ULL, 
            0x029BC22A31592596ULL, 0x33C99B585D742A34ULL, 0x0A6D5A20D4ABD1F9ULL, 0x6411B976497A722BULL, 
            0x53CE20BE7FDF107DULL, 0x010C021B7B97C72DULL, 0x1BA0F1CF1D6EC0FEULL, 0x8A3FB3CEE93A575AULL, 
            0x6872444EFA05C096ULL, 0xFCEEF20B6D0752EBULL, 0x255FE157E1FFC076ULL, 0x50E67B84C0563B32ULL
        },
        {
            0xE02BDF2C15B9380AULL, 0x31898CA8DE7F7DE4ULL, 0x085E24861CE552F8ULL, 0xE6BF6382ACB62144ULL, 
            0x522AB30D31E165A0ULL, 0x11EDB5C9EA182368ULL, 0x7DAB23596199F047ULL, 0x64F137B462E56411ULL, 
            0xE372CB1AC5159108ULL, 0x7E7CB65F90B5E825ULL, 0x2A8E9F4CEDC219ADULL, 0xC847652D8F931B30ULL, 
            0x2F84C4C20467FEB6ULL, 0x426DD7AB73679AADULL, 0x0196E97F5402584BULL, 0xD8B74C754BFFADCEULL, 
            0xBA12E70CB1394A8EULL, 0x803385A724F9AE23ULL, 0xD2284751300F7BE0ULL, 0xCC77915E2B125566ULL, 
            0x377C5BB29BCB481DULL, 0xBBF9CE40C8205A18ULL, 0x45A1216DB4E6A733ULL, 0xEDD8462CCF412195ULL, 
            0x73120A1D519B5A39ULL, 0x3DD2954E774B6C57ULL, 0xD1F1DA4C1F56DC2CULL, 0x2A74D9D922BF741DULL, 
            0x6880D7433F920705ULL, 0xD10764D5E191F919ULL, 0x4B519D0CC2FC7EDFULL, 0x4DEF6ACB6E4A2AD4ULL
        },
        {
            0x9F1C29DF93F4A05FULL, 0xC6A13449304AC624ULL, 0x6BAB1D0BA6DAC31CULL, 0xBCF426780B2BC591ULL, 
            0x9588580BA1966C14ULL, 0xFF7F428E962745C5ULL, 0x881B12BA7ED5F16BULL, 0x3CA82B932A591892ULL, 
            0x2048833E3A1B04C1ULL, 0x41DB92953B114559ULL, 0xEB901AFC16475847ULL, 0xECC40E268CD3128AULL, 
            0x4C9B8F798C891CACULL, 0xCECB2999A8C2FA83ULL, 0x05A9E5474CF4AE78ULL, 0xF11E5067956D6D32ULL, 
            0x92D65F89CC4BEFE0ULL, 0xD6CAF6EF81E7D513ULL, 0xD2A79410453F1F7AULL, 0x7C9BA54D7A5C4C31ULL, 
            0x0CF110B689FA6E0CULL, 0x4E052BD95428591EULL, 0x026FB45E236B1EBEULL, 0x26E7613194ACF56DULL, 
            0xE7308ACF20CC013CULL, 0x4E2FB0AA69E366F2ULL, 0xE764406EB4C0BF54ULL, 0x068190241D36EB16ULL, 
            0x14A794F6BB2E9FBCULL, 0xF59DB7025CEF05D2ULL, 0xFDE84278092F4991ULL, 0x26FF5651D3E45908ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeySpawnConstants = {
    0x96FDECC30981E599ULL,
    0x7E98701BAEDC9845ULL,
    0xCC01A71ADCF14CADULL,
    0x96FDECC30981E599ULL,
    0x7E98701BAEDC9845ULL,
    0xCC01A71ADCF14CADULL,
    0x755E12A9045E9FA4ULL,
    0xAD6CB50417895F12ULL,
    0x6A,
    0xBC,
    0x64,
    0x6E,
    0xA0,
    0x0C,
    0xAF,
    0xC0
};

const TwistDomainSaltSet TwistExpander_Mirfak::kSeedSalts = {
    {
        {
            0x7BF2326DE14CE075ULL, 0x47725BC0324C6C3EULL, 0x22577669D95CC4E1ULL, 0xCDC3323DA43F8E1FULL, 
            0x1C6896907D4BF512ULL, 0x537857C82A360443ULL, 0x99A06F745D2DBF90ULL, 0x0A2FFD629409F92BULL, 
            0xE21590A394F6428BULL, 0x132BB01A019AE8CEULL, 0xAE32DA0364A70530ULL, 0xEAF3095D41BFE8C6ULL, 
            0x85844688C906E496ULL, 0x042DAF149972B8E0ULL, 0x0996B6C304348B2BULL, 0x7ABF0DC5406A0CCCULL, 
            0xA8E9D51556CFCDE3ULL, 0x47E7485683A47C80ULL, 0x3F9FDE7EB2BE4C77ULL, 0xE46EC446DC0B8338ULL, 
            0xDC50C3EE80DE7FCDULL, 0xA03B8B28A6838C8AULL, 0x98801835461EE039ULL, 0x9F7A0E55438BF710ULL, 
            0xCC4232EC8934FA30ULL, 0xDAAD08EAC9F015A0ULL, 0xB88C95C2D7A101F9ULL, 0x84E73971F2198B20ULL, 
            0x6213C86DC22F60CCULL, 0x6BC97A265C1E634FULL, 0xC6FC21E073AFBFFDULL, 0xCB25C81A3CAE513BULL
        },
        {
            0x1BB32C403B31F2B4ULL, 0xD889530F1327A233ULL, 0x9CA3EEA44FFC5CBFULL, 0xF5E7A3F849D4CF59ULL, 
            0x35452FFDE2C2F12FULL, 0x3A5B993FD1FBF528ULL, 0x572F372F424ED16BULL, 0x36519BB00CE410C4ULL, 
            0xE1BB59E4987BDD26ULL, 0x31F4B4A1C15F81B1ULL, 0x6B824955260FC811ULL, 0xA5DB362F36564638ULL, 
            0xCAF4FDEA3DF8F18DULL, 0xD26E1006D041E76FULL, 0xD2797E72C7AD1791ULL, 0x77CAE95E1A869A76ULL, 
            0x23B70EE666F6F97EULL, 0xBB584655B9AADE5AULL, 0xCFCBEF991D8CA17AULL, 0x2554C539EF11FFDEULL, 
            0x24E4A5CA4662A67DULL, 0xC9552203B19AEADFULL, 0x0808EE4FBB6AF763ULL, 0x2A8B09D1678A85A8ULL, 
            0xFC9BD789D61E44F5ULL, 0x70320BDD66BFECA2ULL, 0xBA3A3850C6448567ULL, 0xA6F70AA17CB84CA5ULL, 
            0xFE436456BADF0A18ULL, 0xB6FE209EB471DA23ULL, 0x9C2D83D0EA932634ULL, 0x77BBC9282A772923ULL
        },
        {
            0x151CBFFA39C156C3ULL, 0x53719A2A6AE4BBC8ULL, 0x85442C2B1A04E3B0ULL, 0x1E01242ECAD9A507ULL, 
            0x44F9943E64433364ULL, 0x276637470DD4C8C5ULL, 0x96A88B2D2E5E7B85ULL, 0x220107A0E4D93118ULL, 
            0x0B040548F22B1377ULL, 0x36F248586B77F3DAULL, 0xB5E040E9DC811F9BULL, 0x8A6B3F2FED3A8781ULL, 
            0xDE4611524D384565ULL, 0xDFA8FD6D3D2AE12FULL, 0x41EB488FEB1F19A4ULL, 0xEDAF3B669F385213ULL, 
            0xA902F7C4F8A15366ULL, 0x68620E85AA946FD5ULL, 0xCD44BA47C7BBE52BULL, 0x4FE75937E4BA932CULL, 
            0x7D48B11245A80A51ULL, 0xE7176813BAA7570FULL, 0xD27ED4FE58E541FEULL, 0x0CA49B2790CE3D6BULL, 
            0xC4C6EA0526F78F2BULL, 0x469A7BB4DD19A6C4ULL, 0x6EAF144C5C18614FULL, 0x020D34079B4D16C4ULL, 
            0x097BB7E1D5B0FE80ULL, 0x6310CEEB738A2EBEULL, 0xACF32ECFFDE31FF0ULL, 0x619FA2D2C3AEB516ULL
        },
        {
            0x1ABA9DE09C42FCD1ULL, 0x4680B5365AC8D8E6ULL, 0x78240017B6774F0AULL, 0xF89D2C8C85D38083ULL, 
            0x87BA123E64983089ULL, 0x8E435B1B81A8C416ULL, 0xCDE422161B04B5C0ULL, 0xBCDA4A4020D98BAAULL, 
            0x13E9F32196391B37ULL, 0xCFD305EF1B9BA54BULL, 0xBBC960C7DDE9D171ULL, 0xDACD41457E1D2490ULL, 
            0x7197E20A6275CC7DULL, 0x94A1B64389288F3DULL, 0x6A5AFEC1A5DCD683ULL, 0xAC3324941F46F20EULL, 
            0x866DEE8785632264ULL, 0xDB594BB64AF7F673ULL, 0xBA80615FFD0A264EULL, 0xCFB947527F55B182ULL, 
            0xEB60668171879644ULL, 0x91DF4CCFD96ADF2BULL, 0x3D7F63C532E60B56ULL, 0x84B4C3EFA0185FF0ULL, 
            0x9606EF6FA3A076BBULL, 0xF236A2D4B0EB9C5AULL, 0x81485702EB7103B9ULL, 0x2BAB06F13C922277ULL, 
            0x4DFEEEAA16D1C0E2ULL, 0x49455F286B98DFF5ULL, 0xBCF891F551B33FCFULL, 0x5B3CB65BFBD3C9BAULL
        },
        {
            0xF1138A936DFD5915ULL, 0x1A50826B903637E2ULL, 0x7321E59A4990CF95ULL, 0x437DD831A38659B9ULL, 
            0x67F18C86581B0C86ULL, 0x588F9530575FB67AULL, 0x67ECCAFBCB572BDEULL, 0x2E41C63CB439B54CULL, 
            0x03150A4F8216070BULL, 0xDE31E46BA6256907ULL, 0xF5B39A30E8C57721ULL, 0x54168220019D3E50ULL, 
            0xBA9AEEB1798C526AULL, 0x2F82B3F57B1AD0C9ULL, 0xB2B10D27CEE4E363ULL, 0x712560324672B629ULL, 
            0x9B9FDBCCF20578B7ULL, 0x634C185E74AA1EEAULL, 0x8A49F822EF2CD8A5ULL, 0x3C5CBC67643CFF4BULL, 
            0x5C5C82137836ADE0ULL, 0xF80C8966318B63F6ULL, 0xE414A52B8CFC3169ULL, 0xEE9DE2773342FD3EULL, 
            0xABE83555F62F2042ULL, 0x7BDA83373792FFEFULL, 0x3BE1781430E63737ULL, 0xE1A8FF07B96D1292ULL, 
            0xAF5F0C25D0EBA1ECULL, 0xCC20AA913E3ABD35ULL, 0x69BEAC8BD03D2604ULL, 0x044ECF4AABACE5A0ULL
        },
        {
            0x733511D3E3B12EE7ULL, 0xDF081F772526CDEBULL, 0xC5DCC5BE405F30D1ULL, 0x203994ADC1CFE191ULL, 
            0x33BE5E97F44B532AULL, 0x4B1275427F8DB7B4ULL, 0x5A0CC3837F3C4B4BULL, 0x1511457397EC9361ULL, 
            0x2B5A6B0108E0F7AEULL, 0x46755BD69D32B078ULL, 0x0C663C808F0BB6DAULL, 0x03F42CA645CCB5ECULL, 
            0x6207BCF7BADDF0F4ULL, 0x194F235DB8ED92F8ULL, 0xB8746F4AC14BE9D4ULL, 0xD3C35A2E4997D84BULL, 
            0x079880032829CEA6ULL, 0xF1CA91F053579BB4ULL, 0xBD6348E79CAD16F2ULL, 0x68469D189B9F1EE3ULL, 
            0xFA8CB124EF8FCB51ULL, 0x0420922A1F641564ULL, 0x80FDF12187683F43ULL, 0x97A90116D79C66EDULL, 
            0x7DBD0E429F43DB48ULL, 0xB69DC4FE25FEC067ULL, 0x7D810DB65125BAC7ULL, 0xB3AEC00E948AAD3DULL, 
            0xA1AF54B003B9C61DULL, 0xB3C76225E65FE7C0ULL, 0x901A01FA6C2A7E75ULL, 0xA74932AC65EC358BULL
        }
    },
    {
        {
            0x261EAAC994D94552ULL, 0x35BF2AEC264CDF15ULL, 0x13770C907EC3ED72ULL, 0x86B960A6BDB02D8AULL, 
            0x402CC21D6BF8B777ULL, 0xC628F5E92A619078ULL, 0x28BBF15B31D2FCAAULL, 0xD03AEA0D38A5D777ULL, 
            0x92BD5DBEFC9E5B98ULL, 0xD51938A68F92A30BULL, 0xF664A8BAA8C4A56FULL, 0x27A8CEEBC4574DA9ULL, 
            0x6906F633436E0D3AULL, 0xA34C949BAD4ECFB7ULL, 0xBBF69B94237B47F1ULL, 0x5CC03FC7D0127337ULL, 
            0x898AEDD82EDA13A5ULL, 0xC77DFA122AEE143FULL, 0x5055EBAD48F8F1CAULL, 0xF8DA657B15285DFBULL, 
            0xAE8AA05C1E3A65C1ULL, 0x0815E73803EDD666ULL, 0x36D1B94A385DE02FULL, 0x962055D8859ADCDFULL, 
            0x0EE262C81D5C38B4ULL, 0xDEDEE21202BD9C6FULL, 0x2F836AD02D684B17ULL, 0x0815935665241DFFULL, 
            0x4C9C11C217D332E9ULL, 0x79724EBF761E09DDULL, 0xA82D8621F0A8BBBFULL, 0x2B8963F76D57C7F6ULL
        },
        {
            0x909486A2074BCB7AULL, 0x31EE73C38A47CCB2ULL, 0x8265FFE7E682AACCULL, 0xDD0E55B62FB69F0AULL, 
            0x578CC693B44228BAULL, 0x8B79E9E8D0FE0EDBULL, 0x3F96E60B5BD8EA10ULL, 0x8CF68D8879D4F592ULL, 
            0x6E6632D3F2E409B3ULL, 0xBCC2349B7F567EA5ULL, 0x2E0938E6C6596C7CULL, 0x3461977B5AB4BCDDULL, 
            0x2191DE68CF82202DULL, 0x9EBB3B93F6ACC95DULL, 0x8DDCA825C063FCC4ULL, 0x324D7E6615D0ABDFULL, 
            0x615475C3931E7FCAULL, 0x3AEA6C218AA7D20DULL, 0xF6CF166D963CEF9CULL, 0x937B8D9D2BF535BAULL, 
            0xA55C682B437B6574ULL, 0x6CF2927E263E864DULL, 0xA6D5BD80F653A6A0ULL, 0x078DAB1604D85840ULL, 
            0x3D372FB0E884DD71ULL, 0x3C7CA4A6DB2816DCULL, 0x2C0EB5997D58B850ULL, 0x222EF4FF19BDC2F5ULL, 
            0x31E635160613B779ULL, 0x620F99D95EEA4C89ULL, 0xD2B3F740BF263D44ULL, 0x73A79A9B3FDABDA5ULL
        },
        {
            0xD09FC32471B05743ULL, 0x7E34E34CD554B434ULL, 0x192455DA0A0DCA55ULL, 0x7F49EBF7A3360080ULL, 
            0x173DB486A5E529B6ULL, 0x24019015BC92C3F1ULL, 0xF53B407E9B704482ULL, 0x74BC068B2D544D96ULL, 
            0xAAC9D9434BADD84BULL, 0x5A7A932C60B8E9A8ULL, 0x1AAD5455C36F3E9DULL, 0xA7E274AEB39F807DULL, 
            0xF0F1712F19053FF4ULL, 0x333775F4B8CEC93BULL, 0x589C18171ED2469AULL, 0x9215BE8E4BA6F2CBULL, 
            0xF7A565BE3C4A5AC5ULL, 0xB5A4AE41C7EE506EULL, 0xED47D2DB68D557A3ULL, 0x52BA255B3A034294ULL, 
            0xFE02D31299776689ULL, 0x7EF86DF9F99BEA74ULL, 0xE6B103841D2874B3ULL, 0x00C5D5017CC87DD4ULL, 
            0xE30742E90BCEA0C6ULL, 0x7D53E8B60A880276ULL, 0x8378715960E81AAFULL, 0xD49EAEF5D6D0EA6AULL, 
            0x3285CBF239D089EAULL, 0x24BB559B1519E557ULL, 0x49AD314201C92D8EULL, 0xCBF38A8839C6DF90ULL
        },
        {
            0x5F99772C1BB31031ULL, 0xFE7F7A21A13605FEULL, 0x8049C4AA02242A47ULL, 0x7A4DA35EE0053651ULL, 
            0x9D0DC11CA674B869ULL, 0x27C2A26FD2ACFD7DULL, 0x67A171F2FDEA869EULL, 0x04D8447ED52F8994ULL, 
            0xED3C06DDE58BF17AULL, 0x09A1E6C99E9F3B48ULL, 0x6322BD5C949DB9D6ULL, 0x812EE722FA2500EAULL, 
            0x93C8CF2FCE057352ULL, 0x525AEA5DE3E924C6ULL, 0xE21697DA6D0A7DD9ULL, 0x53E09353B4ECAFFEULL, 
            0x50ABE6B5CD3079E2ULL, 0xE37A6A53F6AE877CULL, 0xFF7909880B068264ULL, 0x2E5A1EF94C21689EULL, 
            0x807FBEBF37B98381ULL, 0x1DA90AF54D669441ULL, 0x8E16FB1B9F9C769DULL, 0x7DF954AEA145D07FULL, 
            0xEB5AA61225F3E14EULL, 0x204C731A1584AD3FULL, 0x3405E0B41663881AULL, 0xF3AB315439DBBAE5ULL, 
            0x0EEFD2FF59614D8EULL, 0x671D8EA188179E26ULL, 0x1FFE540090D0BBECULL, 0xE9C78C9DB3FC2A7EULL
        },
        {
            0xDA5A70E1B736532CULL, 0xC07FF966475AE79CULL, 0x89E5B1F473A2AF37ULL, 0x4B5D130740D4BE24ULL, 
            0xFBA4997FC1B3744EULL, 0x2DD5CF2658A6C6B3ULL, 0x23ABEA87DC9EBD76ULL, 0x4100EC52EC1F41C7ULL, 
            0x489928F826FD86A9ULL, 0xF3631193B53A3709ULL, 0x4D9BD785AFFE5464ULL, 0xBEBAF5E4A22A268EULL, 
            0xA00EE3D25C8E8528ULL, 0x591C1819663E314AULL, 0x4D1233C7CA72D02FULL, 0xAB012CA87F2DD11FULL, 
            0x3671494BB2C68C08ULL, 0x67641E83BE8A42D2ULL, 0x0DA36C609F7B7131ULL, 0xF0483FE887AA7F74ULL, 
            0x543E3731186B0DF2ULL, 0x52532453A4C7B6CBULL, 0x1895F0A04B70DE0CULL, 0x34865A74150C3617ULL, 
            0xDB9AE7B5F0E65996ULL, 0xDD1E0E0F17F4631DULL, 0x971D0A2D13EB5FBCULL, 0x372DC81DB6C65F0BULL, 
            0x867B05341F9D87ECULL, 0x9EF0AC1053439F9AULL, 0x4E8B964F0686D796ULL, 0x5C1D0D36E1E0AF97ULL
        },
        {
            0xF21659C5ABAAC71BULL, 0x087C3B2B50EAB4CAULL, 0xA946C8577C91C5E1ULL, 0x81600356ED068E64ULL, 
            0x4690A5EBDD41E1CBULL, 0x7E6710AD74D23275ULL, 0xB431744AF93F9D97ULL, 0x1579206B3FAB1348ULL, 
            0x2178C061FC419E0EULL, 0x9B1B42F551E2B7D8ULL, 0xC28B48358207E7B7ULL, 0xE1372534C284009CULL, 
            0xB87BA66208BA04DEULL, 0xC43C905D831312E9ULL, 0x75C632B86A6B08C8ULL, 0xD98513089A96A6FAULL, 
            0xEDD272D71235A166ULL, 0xAC1E2865D74430D0ULL, 0xC8DC393B97B0B6F7ULL, 0x63E4F596AF344E8BULL, 
            0x5C69AB3E034835F1ULL, 0x14EBE7F27AE9069EULL, 0x7A6435D39585BAA8ULL, 0x6F6CAEBB0A58D283ULL, 
            0x75A7DF814668D849ULL, 0xCD86ADCAF0790884ULL, 0xDC8A5DD7B33AF3F8ULL, 0xED199607BEA9F7BFULL, 
            0x00381E1FFA8A31D5ULL, 0x8376B9C97F2EF2BFULL, 0x0BF1813BD72F5F46ULL, 0x23A90B9E7E1BE9A0ULL
        }
    },
    {
        {
            0xFACAEDDC40DE33DEULL, 0x69E690D26A8D7A5DULL, 0x328B05E54C1F7400ULL, 0xF4911AE32112512EULL, 
            0xBD094F3BD86F3356ULL, 0x661F045BA788933AULL, 0x461543402690A1EFULL, 0x5000FFD53F8236C8ULL, 
            0x3FDAC66047B3CF8CULL, 0xCF9C7F374E5F0721ULL, 0x01FB85EAEAF22967ULL, 0xA45AFFE22E754F8EULL, 
            0xA5B15374672FB30AULL, 0xF62AF651F8993B97ULL, 0x2C7DC0560B667D9FULL, 0x0342C20854053D54ULL, 
            0x9D83461CD2E089E5ULL, 0x902936AACCC3A50EULL, 0xDCAF3DBF8D07FC2DULL, 0x8B0616E77BFE525BULL, 
            0xCEDF00401866BE11ULL, 0xFBD0914AD68F5E4CULL, 0x58DCF342DA79D8C1ULL, 0x0481BF255BE04D75ULL, 
            0x292D60484ACFBD0FULL, 0xBE258764624C5D07ULL, 0x7C6F1059C11E9985ULL, 0x7A553E82E1DD28FFULL, 
            0x99A35EF8583F9689ULL, 0x961E8B2626955E88ULL, 0x87DF3DED6C943A26ULL, 0x5A634ECA0EE623B8ULL
        },
        {
            0x04B2C7860F23EC6FULL, 0xBB18B928F5A88D1DULL, 0xE07446F623746F6BULL, 0x5CA1732843BFD497ULL, 
            0x75060A400BE3C38AULL, 0xCFA39BBB18E44F1DULL, 0x862BA4207E8E4753ULL, 0x57E4FC7EE72C0887ULL, 
            0x79A9119F3338CF19ULL, 0xA55D5B939D4D4A37ULL, 0xB8108485F683C32BULL, 0xACE1CEAB14751A9BULL, 
            0x8297BC6B7A5C1859ULL, 0x215D7C1519E69963ULL, 0x5FAA9F5A721E610CULL, 0x23BAAF859FA70384ULL, 
            0xE6C6941665D5021AULL, 0x78E9758568EC54E3ULL, 0x07F2A22A040FDECEULL, 0x3E9077E1529D1371ULL, 
            0x6D0C1552DCD59453ULL, 0x947DB62493111342ULL, 0x402085866C39F18AULL, 0x62C041F22FA56212ULL, 
            0x47194B46E9FA0FCCULL, 0x7EBFA664643A173EULL, 0x7228AD6AC8769C2DULL, 0xF7EA9BF9CD500E33ULL, 
            0x3DC12FA38E86023EULL, 0xEC3814234D93885FULL, 0x1E602A76EFC43543ULL, 0x795036CE1FAB2FCFULL
        },
        {
            0xBF2D7535A6C92D87ULL, 0xB7D8B6A98771BDEFULL, 0x059A6F385DCB0F76ULL, 0x939AEFE5B488983EULL, 
            0xCB2A82C467E2B0B7ULL, 0x93907741392D6378ULL, 0xDD84184F49E632D8ULL, 0xEBAFF2166667121EULL, 
            0x6CD5A03940ABEE4CULL, 0x5B138D4ABFB00A09ULL, 0x6FAEC98E8DC5571AULL, 0x20B5A680270A327FULL, 
            0xEE963E00E293583FULL, 0xDC93D467C79C158EULL, 0xE941215A48601B59ULL, 0x23421571E848FA51ULL, 
            0x08DD72858D7BC05EULL, 0x5C7DC19B33BACDB4ULL, 0x8FBD3860C6EE1D0EULL, 0x87CFE2387276498FULL, 
            0xC28EF2DAB89142F5ULL, 0x9C4EEC34C30B4B16ULL, 0xE63A88FA71BB970FULL, 0xF820C504461151ADULL, 
            0xF8081136A36E9B06ULL, 0x9E8A1A5552208F49ULL, 0x6BF4B921C0379EFBULL, 0x6B0BDBC6C5567C79ULL, 
            0xF49CA1FF90A23EE7ULL, 0x1E874525F5CBDC7DULL, 0x19F903BF02D39721ULL, 0x30B2E6CD99B8E72BULL
        },
        {
            0x1406BEA2AA198366ULL, 0x587968EBD41FAAA5ULL, 0xB9BC841BC81D8DB9ULL, 0xF71434927FDEEB75ULL, 
            0x4A7C300F105581E7ULL, 0x6582D54385E0D049ULL, 0x23DD5E262C733F25ULL, 0x23C28D8084769372ULL, 
            0xE76A3161DE30EFCBULL, 0x4074D8584C8DB6E3ULL, 0x65A7435DAA7A9CD1ULL, 0x398FC68293A5EB69ULL, 
            0xF54E37209B7DEBA4ULL, 0xD2BA494EA81C0E3FULL, 0xBA6491F251BFF6FAULL, 0xE6D753836E15DAB5ULL, 
            0x0D3BEC5B677BBBCDULL, 0xD2D06E716628848AULL, 0xDE1F968544512307ULL, 0x7C0FD3F2A8C18D9DULL, 
            0x2EA99E8DC39880C0ULL, 0xB5563003BCE28DDFULL, 0x9CAC001AABCC994FULL, 0x429134BB3ED87246ULL, 
            0xA77985E5421C8CBEULL, 0x4EC77125264A033CULL, 0x53BDEF150082B5F2ULL, 0xFEE80FA60A66B5C8ULL, 
            0x3B2984BDBEE6D02EULL, 0x0FFFD0364AA98E5AULL, 0x7BBE98D10DF8F070ULL, 0x2DEA7AA495245EB5ULL
        },
        {
            0x7222CF4A3C4C25C7ULL, 0xB9293E69F683A7E8ULL, 0xDC178D4E1E1D4D1BULL, 0xC68F0B844BE34D89ULL, 
            0xA5F806D9462EF07DULL, 0x6641135D52477222ULL, 0x7BB4ADE546843974ULL, 0x401BFF11C57F5D76ULL, 
            0x1EEC796D4CA7C48AULL, 0x27E6FA123D8C3619ULL, 0xA626E9B9EF08A612ULL, 0x33CEE7DBE2ADA781ULL, 
            0x1BC60FD26BFBDC44ULL, 0x6E1AFEB7D2ED3866ULL, 0xB6823BF7EE494580ULL, 0x0DA7FFDA84B44ED8ULL, 
            0xF0A935972F6048EEULL, 0x6B2BE3F9ACF1E180ULL, 0xECFD9B900635A667ULL, 0xC3B2775765162996ULL, 
            0xF7300D81A1C6280BULL, 0x87D50D3C692EDF1AULL, 0xB938EFFF52D1CD9EULL, 0x4DC65D7EFCE1A5A9ULL, 
            0x05BF13BE10236BE1ULL, 0x5691EFB750EDEE9FULL, 0x98F93DA8F8AC368BULL, 0x80A0E192798EF0B2ULL, 
            0x5B857CEFAB4F8A61ULL, 0x653EB48380088DE6ULL, 0xBBBEA1D8F0CB4306ULL, 0x2BA004632AF145B6ULL
        },
        {
            0x496271B27FB6548DULL, 0xF5EFB77BF85E6DD2ULL, 0xDC863536F156B25FULL, 0x89B0D0F0B2E76252ULL, 
            0x58F56E6545B01580ULL, 0x8A8644AAB5E53FF7ULL, 0x0BC742A0F4D46642ULL, 0x9998CB50CFAB6575ULL, 
            0xB618F870BE40B65FULL, 0x3841AD82E13EBEC1ULL, 0x7282CA5BB0B826AFULL, 0xFAB41A773DC9F8F3ULL, 
            0xCF407286DBBB1565ULL, 0x1CE613E21D728105ULL, 0x331CA933C7C8826CULL, 0xB608E1674281EED1ULL, 
            0x288E424540E034EEULL, 0x82C018B169A9FCE3ULL, 0x302657814C8742D8ULL, 0x6D3E01D89A8DDCD6ULL, 
            0x3BE087A2C81365F4ULL, 0xAE91DD296DC50F01ULL, 0xF7A0D0581F895264ULL, 0xFFC72069A8940C4EULL, 
            0xEE952395D875A868ULL, 0xC71CD054D060D33DULL, 0x08D786049D7845CFULL, 0x294ECE584BAAAA68ULL, 
            0x9030FCB062F300A8ULL, 0xF9947DEA9D4ACFE3ULL, 0x75931701D0BC877FULL, 0xBDC4D9C0B4170B6EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kSeedConstants = {
    0xDF57DFC833F62E74ULL,
    0x4AF8B24680C1E66AULL,
    0xC1087B8BAE864E4DULL,
    0xDF57DFC833F62E74ULL,
    0x4AF8B24680C1E66AULL,
    0xC1087B8BAE864E4DULL,
    0x47EE97A885585A9AULL,
    0x903385C831330803ULL,
    0xC2,
    0x4B,
    0x95,
    0xAC,
    0x73,
    0xA9,
    0x3C,
    0xDB
};

const TwistDomainSaltSet TwistExpander_Mirfak::kTwistSalts = {
    {
        {
            0x44EEF3A6DAB77E7FULL, 0xBDB46FD0A1AF0239ULL, 0xFC52998CBD82C487ULL, 0xD433026BD1F0BA37ULL, 
            0xF5C922F0B8F1F483ULL, 0x00AE6E989E6D6587ULL, 0x5E4EE0372AD61491ULL, 0x4E84084534C634A6ULL, 
            0x9D0F7F2B72C1DE6BULL, 0xBD6CBAAFF5FDDF65ULL, 0xFA249EA9CC8C548DULL, 0xB7FA370682F5D429ULL, 
            0x446FCB9F844F3377ULL, 0x23F11331E400A8F0ULL, 0xBBE7695677236C17ULL, 0xDE292319624B24CAULL, 
            0xF0D2FA9AB0A940C3ULL, 0x5516B2C6C72117BFULL, 0xF0C04297F89F0588ULL, 0xCC172E537056CA73ULL, 
            0x89CA8021077E3DD8ULL, 0x9C6637DC2062CB59ULL, 0x69408FF3DC774E70ULL, 0xE826DBF1DA428349ULL, 
            0xEBCDF10471982EA1ULL, 0xEB4BF970BC412BC9ULL, 0x676502905883A353ULL, 0xF771A508ECDAD339ULL, 
            0x8F16EF772730651CULL, 0x6319AA113F292B26ULL, 0x8DE26DBAF9100766ULL, 0x826ECC042B4A6AE1ULL
        },
        {
            0x4099E170E80ECD4BULL, 0xB5A0233F465199E7ULL, 0xED6678BDAC329D91ULL, 0x533F8FB98AB3F2B3ULL, 
            0x5CC61047B6F96CAAULL, 0x59D0B5AF41A43762ULL, 0x14303DBB6DD5638BULL, 0x087CB7FF6BB73A41ULL, 
            0xA5900D0C56EC5D6EULL, 0x782C0ED49BC981FFULL, 0x58DF5BE78428A052ULL, 0xDF8C9CC676D6A561ULL, 
            0xF8A2E2997F963610ULL, 0x9B1BD52223B28187ULL, 0x3892C19E174790E3ULL, 0x7F2EA3AC1EE498F7ULL, 
            0xE97CC301DF6651E3ULL, 0xC6301F9882554C0AULL, 0xBB71299E3A018B9EULL, 0xBEB72685F335D954ULL, 
            0x464612C10DE76315ULL, 0xECEE45ED25962379ULL, 0x234FF26E80AA9FC5ULL, 0x08983D7ED01CA19BULL, 
            0x100C840219561BF2ULL, 0x1AE33BD14A8BA932ULL, 0xD39FE2D822786D16ULL, 0xBCE584603BA5A16EULL, 
            0x5EDD937A308E30C3ULL, 0x4BEE2767899D3B10ULL, 0x5B39D4246EF452FAULL, 0x97E07B408368FF4CULL
        },
        {
            0xA07D99C1C51F2199ULL, 0x24AB01A5265895E1ULL, 0xB4904239EC186B64ULL, 0x9ACA909D7EDDA9EDULL, 
            0x3ACB96F951A8C60AULL, 0x8BEF955B0AB7B737ULL, 0x3B51F1870537EF69ULL, 0x25C0F497CF846C90ULL, 
            0xB559323ABA658D7FULL, 0x444C8107B3F655CBULL, 0xF1FC6C58A705C5DFULL, 0x7181F362974E4836ULL, 
            0x00F70ACD79753AFEULL, 0x2DAF9D48C8B47A1CULL, 0x1D50CC70A62F36EAULL, 0x56C9EAF2D61C3C27ULL, 
            0xDC0F391EE6B6D943ULL, 0x0013707DD0BF613DULL, 0x61A0EC4ECCCF3B5AULL, 0x6D942F37FA787C82ULL, 
            0x052DAA546291DF86ULL, 0x66C93D5E65CDB081ULL, 0x618911E9CC4F967AULL, 0x1DE2195354F9842AULL, 
            0xA0C08A73632400DBULL, 0x2E9767FB15F1180CULL, 0xCD3EA57681A43C8DULL, 0xB54382F46CEF337AULL, 
            0xD89C591613D102E3ULL, 0xB6D57A9943162C48ULL, 0xA80E476229F40EB5ULL, 0xDB6CF377BAE65AADULL
        },
        {
            0xD42BB5DD27C022C3ULL, 0xAC0AC75233DC9924ULL, 0x123F17AA1AC695F9ULL, 0x760CDB83B61EF35EULL, 
            0x331A71C2C54B8662ULL, 0x4260B3317B3ABEA6ULL, 0x122517B05959874EULL, 0x12E6BDC6166AD87FULL, 
            0x2AFAC060E869A91AULL, 0x9405CA90867CCD44ULL, 0xD70CDC88ECCFDDEDULL, 0x3A394F8AA32F2524ULL, 
            0xD33336A171DE730EULL, 0xBF63D4AB9D11C975ULL, 0x622B31FBF2389645ULL, 0xCE385E3D0DDE0356ULL, 
            0x08682FB6292AE3F5ULL, 0xD8E173F9B2E17740ULL, 0xFCA868130CA40DECULL, 0x3D7AE8AA68B44511ULL, 
            0x1B4A51BB0F602893ULL, 0x8CDCDF3BCA393185ULL, 0x52B9B7166DF3AD2FULL, 0x03891387E438A768ULL, 
            0x9831DDF2739557ECULL, 0x275F2C8A7BB56E5BULL, 0x98E41F0A9482DADDULL, 0xBE7B8954C043382AULL, 
            0xD0BB48A53A32D446ULL, 0xF5225B078A82BC52ULL, 0xB782756732D50A2CULL, 0x4D085E9DAE6B37D2ULL
        },
        {
            0xC1BD578536BF0293ULL, 0xC5EE124DD0B3D1AFULL, 0xFA65B55493BF1CD3ULL, 0xE107EB6440C0FCEFULL, 
            0xB94051DCD973783BULL, 0x55DAD7D14B486A00ULL, 0x45344BBC2D102F38ULL, 0x09435EA9822C54BDULL, 
            0x46A938472F6E7B16ULL, 0xB536C7BE940C3BCCULL, 0x034F7F306F4638ACULL, 0x68D1BFF3B1CE8BC6ULL, 
            0xF5731F6F12FCC8F8ULL, 0x4D02CCFF847D2A10ULL, 0x79C146CCA2404BE3ULL, 0x8289966B639DB09BULL, 
            0x2E4D67A62AA1428AULL, 0x2FED8F146DDEFFA3ULL, 0x37B39E5FA0B401F4ULL, 0x60B31430ED72CC21ULL, 
            0x81417DFEB1C1195AULL, 0x16924895AC860A74ULL, 0x2571DD96234D6252ULL, 0x597567F41D5FD952ULL, 
            0x410CB2368EBC472AULL, 0x0B43E98114A4F9BBULL, 0x3B9C6222FE6CE4FCULL, 0x6A8ABB607D1807BDULL, 
            0x31E2D0844E433864ULL, 0x711D7A93BCD71BCFULL, 0x2A9197AE7E42F947ULL, 0x752329F1AD6F10F3ULL
        },
        {
            0x42F4707D585EABD6ULL, 0xCC9C42377B20637CULL, 0x07C0A2CEEC356DF1ULL, 0x0850C93897F4A6B1ULL, 
            0xA478E9D39CED4553ULL, 0x696D6B221DF5263BULL, 0xFCA965F0870788F5ULL, 0x97BC2C8B1160CACEULL, 
            0x0927FE4E26A5CA28ULL, 0x003084F904C79350ULL, 0xBB0CCFF549AD63D6ULL, 0x075CA290DCE68692ULL, 
            0xCCF99BA4482AB39EULL, 0xC3C3F3797B5E3AC9ULL, 0x8FE92F8FA73ACFE3ULL, 0xC275DFBD6AF2EF69ULL, 
            0xED4AC09DAA7C9106ULL, 0xCAF4080E80F3EC71ULL, 0xA0C950A1A8E3DCCAULL, 0xD491B5128BA80EDAULL, 
            0x2661BF97D4ED0F27ULL, 0x45B452D85B3AB2E5ULL, 0xD1D76F99B7FF4A43ULL, 0x51BD971917C96388ULL, 
            0x5CA81D3CCB77F9ADULL, 0x629C235341E01A06ULL, 0x7763497A0CE9876EULL, 0xDB4184BD7AD3FBF0ULL, 
            0xB0B5B7A512A4ECE7ULL, 0x3378FD3B0E6001B2ULL, 0x9A19E891CCBAFEA4ULL, 0x55E78214DFF2BFE8ULL
        }
    },
    {
        {
            0x1FBC44F0D5268978ULL, 0x461BA2CD22EBDB20ULL, 0x68C5888FFBEAAF88ULL, 0x216429AEBE986671ULL, 
            0xEB80EC28AAD9A8B9ULL, 0xBA23565F729BF274ULL, 0x35A28C43C0F3CBAAULL, 0x4DFA7DFA8661E53CULL, 
            0xB45C59D8DE1418EDULL, 0x7942E766843A8333ULL, 0x1FDCC3A4E2A54491ULL, 0x0DC28200740E0717ULL, 
            0x53AFFDDDA10EB29EULL, 0x52CCD3FA66AD26E1ULL, 0xE98CC22AA79E3866ULL, 0x76E7FD45972FA128ULL, 
            0x8F13410AFFFF8482ULL, 0x9382C4FD3C5F2BDBULL, 0xDCFB4FE539032B79ULL, 0x4B2F28A8B9495D75ULL, 
            0x56E890B52818A793ULL, 0xEC04C45A456C1A21ULL, 0x336C2A9286D7BBA5ULL, 0xBCD487DCFE17AD46ULL, 
            0x5A9175EC76C1C4B4ULL, 0xA85C33D8B94A6C0BULL, 0xAE2B20EB8C52EC20ULL, 0x83CD49FDEF17991DULL, 
            0x8D227A41AE552DCBULL, 0x7869CBB069EC06A0ULL, 0x37D70E6C8525FCD1ULL, 0xF779B9045CA4669CULL
        },
        {
            0x42449F4DC02D0015ULL, 0xAE441097FD4535F9ULL, 0x836C49D1D0531E72ULL, 0x162346C2DA4A89F5ULL, 
            0x3FF1B6F47ACA99B3ULL, 0xBF13DC43F350A136ULL, 0xEF021CDB0EB13318ULL, 0x3911D6B813F388BCULL, 
            0x3067407A5933C439ULL, 0xED19E692896A7C5FULL, 0x4E187764AF24D6F1ULL, 0x1537015DDEF77E97ULL, 
            0x152CA73610A092ADULL, 0xD9E386175E26AAB6ULL, 0xF55BAD1AE0FE18F8ULL, 0x40292A4D0320FC40ULL, 
            0x3C86BE1C244764F4ULL, 0x500FDBE22EA83845ULL, 0x3BD7B4ABB2768F27ULL, 0xE0593BD820A4CFB8ULL, 
            0xDA33D9C28BA00064ULL, 0x9142430029E1FD75ULL, 0x53C7A8F0063637B5ULL, 0x9C937938FB297BDBULL, 
            0x57B8CDE5F7891D31ULL, 0xFBB5B4FEB6E9CE3EULL, 0x2779EF93AA5A2B2EULL, 0xF1655F6A80541B68ULL, 
            0x4A81CD6BE8F80870ULL, 0xECAD9B413D2333A9ULL, 0x129D67480C902B5EULL, 0xCD0656BAF06F0F4AULL
        },
        {
            0x49E8D65465E70A48ULL, 0xB2AA589B3625A0E8ULL, 0x12774BE1011FDCADULL, 0xFD603D96B5C4A8A2ULL, 
            0x524CD5CCBD15B72CULL, 0xCA14F4F88D0DD9E2ULL, 0x0D4BD80E2DB49198ULL, 0x62DF3BB91B921A8EULL, 
            0xD580771AAA2CEAE2ULL, 0x0432B4C9DD9BB46FULL, 0x6DF5B30348EA2EFBULL, 0x13EBB23AFF4DAA1FULL, 
            0xFA5643EE6D3AA403ULL, 0xB38BEC996099C40BULL, 0x1156B19478A996E5ULL, 0x148FB7077B6B45B1ULL, 
            0x89E7454BF577C73AULL, 0x6819970A0FE1485AULL, 0x9AC7B842A5566D60ULL, 0x25AF0E004688FB4EULL, 
            0x95CC9945D8C85792ULL, 0x5B75A6EE84EAC595ULL, 0xF8554A5126068856ULL, 0x3239555E88A9B130ULL, 
            0xF70420DA9937329EULL, 0xE195D1E69536764EULL, 0x832932F3A1AF1240ULL, 0x58E13D0B8AA4061BULL, 
            0x4F33334C41031845ULL, 0x0162BC62F7671BF5ULL, 0xF3F51F9D40A1F99EULL, 0xD1FF052D460F8181ULL
        },
        {
            0xF63A1AF1F1D90A74ULL, 0xA7712D111BA33177ULL, 0x1D1D7454993FE45EULL, 0x7E421EACA68D1AF0ULL, 
            0xBBAE60952F172FA9ULL, 0x42ED016ABEE0D60AULL, 0xC9A9CCAC79663629ULL, 0xFE2D3F6AAF389DD2ULL, 
            0xB86759433312ABD4ULL, 0xC5931107F863B261ULL, 0x0E6B43C896B3D9F0ULL, 0x3B57A35B444B6DAAULL, 
            0x14C384A0EDD8C3AFULL, 0x3EDE1A4226638076ULL, 0x35FF6761CCED04C6ULL, 0x29BBCEC15A664C63ULL, 
            0x4F08E6421F0BEAB4ULL, 0x519BF55AAA1349A6ULL, 0x919061F1E3B8285FULL, 0x57BC9414C636D487ULL, 
            0xA651158C27B9A6D1ULL, 0xB266D876EBAB657CULL, 0xFC40A3AAD1CBB53AULL, 0xF6831B3E6ECEA8A7ULL, 
            0x8B2C13C494D28D4EULL, 0xA599C43CC3CCE64AULL, 0xCF510A5209CBFF87ULL, 0xA8D64781476F64D5ULL, 
            0xA4385B8B2746D022ULL, 0xD74190F5B4E7F7E6ULL, 0x04158665EF51846CULL, 0x61E17BBB4CF2CEE2ULL
        },
        {
            0x31CADEE40490B4F0ULL, 0x088EBD79AA7FCBFDULL, 0x7EAA2890D3521F9FULL, 0xAA23F2A16A57AE10ULL, 
            0xC1FD59A41D5179FEULL, 0x1B44F88199651C52ULL, 0x1D76E341DD2CCD09ULL, 0x4EEDFE2076E61EC4ULL, 
            0x77932D02CD128F85ULL, 0x54D89A6BE239147CULL, 0xB8207B5FFC7F6702ULL, 0xBECBBA95E612C986ULL, 
            0xC493E1183BDA434FULL, 0xF05D0ECC7BCA672EULL, 0x457B47683073FAD8ULL, 0x1B9E70BB1282A909ULL, 
            0xD0A63EE3E6EB0A42ULL, 0x50FD97DACFDF4A7BULL, 0x4C6A69DA6B9F3311ULL, 0xD22D88B11BB138AEULL, 
            0x841046D18156C35FULL, 0x66E84139A315E59CULL, 0xCE860601E52801DBULL, 0xE9FD389621C0BE8EULL, 
            0x4296F26574A8864FULL, 0xEF67541915DE59EAULL, 0x5F57A9FD6824DCA9ULL, 0x5EB24369A9D5D117ULL, 
            0xD58A7DBE53179E33ULL, 0x834982FB37700543ULL, 0x4B333D669C36C7CCULL, 0x591ADF62DC9C0AFFULL
        },
        {
            0xA37EE873CEC88814ULL, 0x5CAE83DB4CDBA95CULL, 0x3C0622E5A3C50372ULL, 0x30FF61B3146F7DD8ULL, 
            0xB03A72D28E49F265ULL, 0x0A9846E8FE52E6D6ULL, 0xD72D2A85292D01B7ULL, 0x83972DC1A97F4C18ULL, 
            0x315A5647CC8FAF85ULL, 0xAEBF0A796722A94EULL, 0x014F8A9738DB201DULL, 0x952979DB3C961A93ULL, 
            0xE6F2404C74AB11F1ULL, 0x3F81E2D0992D27A7ULL, 0x03A6CBE545C440F4ULL, 0x128BC6452139519FULL, 
            0x69FA9050B9397688ULL, 0x6C63BE915D9B92EBULL, 0xE7428A13E21A5E7FULL, 0xC8867120A1CF4D11ULL, 
            0x221FEF032BDFCFEFULL, 0x863F5C853CA15561ULL, 0x0C7FEADD981BA6FFULL, 0xA56808845AA8F557ULL, 
            0x2056BCB261B6C009ULL, 0x1838BE3CB5F78249ULL, 0xE0A334698B616232ULL, 0xA57851E3706FC272ULL, 
            0xB0DBB923147F3E20ULL, 0xA910B6A9EFD4EF88ULL, 0x8FE6D8463E20D5A6ULL, 0x07FB9E529AD89C0BULL
        }
    },
    {
        {
            0xA015B97F19B0ED7FULL, 0x2A0164FAB879E04FULL, 0x919D5E441E0C3643ULL, 0xA72EBAE844227010ULL, 
            0x75C55851158FC689ULL, 0x0DA2D7363746ADD1ULL, 0x82A7FB48AE21B63EULL, 0xDB93D1EFF0B13F4EULL, 
            0x28D552D3623B08DEULL, 0xF4B026BC95AE77E5ULL, 0xB66C10D0B2EA14D3ULL, 0xF91544D44C531841ULL, 
            0xBE698C8FDD855DBAULL, 0x65C7CAE107F134DBULL, 0xA7C8D92FBDFEFA85ULL, 0xF5555527403A1BD9ULL, 
            0xBC147DECD078DCEDULL, 0xFBEA1D12877F8DEAULL, 0xE4EBB11EEF72DA41ULL, 0xABF7DB669CA7F531ULL, 
            0xB8546EE94C340DD9ULL, 0x1D18F8A956C81DDBULL, 0x8B3686848F5BC170ULL, 0x2E56CB371E285E84ULL, 
            0xA88D18BDEF82C6BDULL, 0x6A1FD96D5FE70551ULL, 0xA071294A3DEBDC6FULL, 0xC956F568816B2C1CULL, 
            0x640C392DCD5F8284ULL, 0xA60346C589609A4FULL, 0x696F277943653F9FULL, 0xEBFC65422D1D8119ULL
        },
        {
            0xC74CABEED5A0257BULL, 0xD056ABAA752E951DULL, 0xB46F3D1BA81ADD6BULL, 0x90FAD4A4E08F28DCULL, 
            0xAC953B029379D46EULL, 0xE704CD88E27D0155ULL, 0xC05EC39DAB49D3DEULL, 0xB914418813F6F011ULL, 
            0xD568BCD74946DDCBULL, 0x681849748EE835B2ULL, 0xD2B53E93D9E4C8DAULL, 0xF54DB36A97DC6714ULL, 
            0xCBC367FBB7542D8CULL, 0x8AE0F0360B758FBAULL, 0xBA5D2D3C51BE5161ULL, 0xBE3F07EE3529C0C5ULL, 
            0x5AE75AD567C83260ULL, 0x54ACEFE4DEBA410BULL, 0x164F688AFD6C884DULL, 0x79905DB18611C2B9ULL, 
            0x630787462B3C49F2ULL, 0x56B5592C8E9F46D8ULL, 0xB62A29CF49D5B850ULL, 0xB52B7F1757ABE14FULL, 
            0x9F9ED7EC98A759A6ULL, 0x6582409402A97827ULL, 0x9B960F6279E9A98FULL, 0x973CEF85473D9553ULL, 
            0x9568C28CE330F106ULL, 0x62F5859924D048AEULL, 0xBA039B99C724605BULL, 0x2E0AABB7D14DD80BULL
        },
        {
            0x358038DE5A2A4C49ULL, 0x8E2A91A14A85F4A0ULL, 0x4605FDBB0222907BULL, 0x77C87FAC086FEC82ULL, 
            0x91A0E5B76BD1FBC2ULL, 0xDBB5813C52D068C8ULL, 0xFFE371E34202E404ULL, 0x050FA03EE934437CULL, 
            0x5096BBA2FB5B8B76ULL, 0x8AD9A1495CC36D74ULL, 0x6DA292C3999B9915ULL, 0xFDE29F8573607C63ULL, 
            0x6B30B682B4EE5B39ULL, 0x1F5AD2ED3BA89DBBULL, 0xC799B70117AA59EBULL, 0x00BB1E01A13F37A4ULL, 
            0xE91F517588AB78ABULL, 0x44E60A346296BD5EULL, 0x2886F84F21DDE7BFULL, 0x604C065EF155ABECULL, 
            0x6C0CB7282BBDC0F5ULL, 0xE42B93750CE25104ULL, 0x0A2E3B8D1006BE29ULL, 0x2FAF96137900AE81ULL, 
            0x6B8F3B113FA382BDULL, 0x28C94B91BE9A959FULL, 0x8C99502D423643DAULL, 0x8741B7B2D2C04A0FULL, 
            0x7777DB1E4B2C7DFAULL, 0x0F4ABF9B05A039C4ULL, 0xFA26126076EC20F2ULL, 0xDE031691AAB392A2ULL
        },
        {
            0xF74A8E9074535A67ULL, 0xD6F308C734A11428ULL, 0x870D9C51599F184DULL, 0x4BCC2976BC914017ULL, 
            0x3DC12D58192FA901ULL, 0xF186771F75E65D65ULL, 0x96E65E33D4B7A02CULL, 0x3BAF6BB4BE0FA8EFULL, 
            0x0C2771F94A6EA72BULL, 0x4921BDD890FDC8C8ULL, 0x69E5564A7FBC5204ULL, 0xD127F7B4C6993282ULL, 
            0x89285CC4EFB8A897ULL, 0xE02B2FE0DD614EDDULL, 0xCDA7E0A1893B6BA7ULL, 0x45368904342FA97AULL, 
            0x641973C0B72584FFULL, 0xE98CAB0B40F59968ULL, 0xFBB985FA395F0663ULL, 0xFD3958F443776415ULL, 
            0x87D6660EFC483D70ULL, 0xD28981B16C506E74ULL, 0x5CB1F8558ECB4AFDULL, 0xD506056290C2A14CULL, 
            0xF293AEE7C087FF57ULL, 0x86590988075FCA15ULL, 0xD5FE9D3A54BEDB31ULL, 0x3C1AA632750F737BULL, 
            0x8A2118C39E479235ULL, 0x0244089660D0B772ULL, 0x251785D54FA667CEULL, 0x19708CA8D7C8C6B2ULL
        },
        {
            0x2B66E294176798A6ULL, 0x7540E3035C918D38ULL, 0xE499725B13944D60ULL, 0x1C2F36EBA2E07A9EULL, 
            0x81A255D5504DCDF5ULL, 0xE323D5177C1F27A2ULL, 0xA2C325068C06EEFAULL, 0xEF0916711003B317ULL, 
            0x765F61E2374EF336ULL, 0x6921DDEC683A6FF2ULL, 0xC5DD1B68C3A11472ULL, 0xB015E00B0A263C08ULL, 
            0xD3528C108E567080ULL, 0xEE564FD29E5BFAA2ULL, 0x91885D6A52D74E21ULL, 0x2365B8E6DDA2FCC8ULL, 
            0xDCC66C9C55B3D58EULL, 0x097DBC1FB410A204ULL, 0x4DAF0AB4F656C98AULL, 0x75D544912216B7E1ULL, 
            0xF9AB7624D8E3F31AULL, 0xDB6E285D45B32604ULL, 0xA291A4ECA8FAD992ULL, 0xA190EF66F6C78B1AULL, 
            0xCEB4A00F2804E3AAULL, 0x677999B4D161A224ULL, 0x06A69FA7ABF3D745ULL, 0x9488D04635A056A8ULL, 
            0xE9F0A31563845AD2ULL, 0xECFFD4E6B6E2BFA0ULL, 0x41C63F28DBA6E8D8ULL, 0xB808008CE8EC2885ULL
        },
        {
            0x171AB61FD4F5FE40ULL, 0x503EA60D8AB26FB6ULL, 0x43FA9AC76D9A47CBULL, 0x69312107C2225205ULL, 
            0x69965B45BB93E6EAULL, 0xBFDB0A10FB23EBA8ULL, 0xAE84369E0C421983ULL, 0xE433153A648165DCULL, 
            0x6B9D075908D2A09CULL, 0x660FF73B13AB5AC6ULL, 0x0156E234A609F09FULL, 0x3CAB0D7B8D04CAD9ULL, 
            0x3299DE7E173AB320ULL, 0x82AA9E7BF31AECD1ULL, 0x82B587A8C6943E73ULL, 0xD97EA964EC37EA2EULL, 
            0x49C71158793BDDE8ULL, 0xA9F4BFAD8B4D212CULL, 0x2D294CB3FC6721E6ULL, 0x88A24DCD5E50CE25ULL, 
            0x711752FB5AA03988ULL, 0x5DEE9CB8B5089B1FULL, 0x07A4A6FEB88C281DULL, 0x31052661EA22C416ULL, 
            0xC4FF69D7E23D4FF6ULL, 0x549B2987BA4A852EULL, 0x181D80236F42179FULL, 0x35197E55E5D2F8CDULL, 
            0x138538999A36A271ULL, 0x6628676DD44376C3ULL, 0x405458D22208EBE0ULL, 0x9365C5C20C1596F4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kTwistConstants = {
    0x418DB44E3684AD6BULL,
    0x9C63DB92EBD52C34ULL,
    0x0CFE9FD8016AE5D2ULL,
    0x418DB44E3684AD6BULL,
    0x9C63DB92EBD52C34ULL,
    0x0CFE9FD8016AE5D2ULL,
    0x19ECABC65DA7DCCAULL,
    0x4AD866A90EDEE10AULL,
    0xEC,
    0xF8,
    0x3E,
    0x75,
    0x88,
    0xD3,
    0xC9,
    0x69
};

