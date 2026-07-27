#include "TwistExpander_Achernar.hpp"
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

TwistExpander_Achernar::TwistExpander_Achernar()
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

void TwistExpander_Achernar::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x914A0A3662B063EFULL; std::uint64_t aIngress = 0x9B9E60173102C077ULL; std::uint64_t aCarry = 0x96E3401D3D3A7560ULL;

    std::uint64_t aWandererA = 0xED80F26658DF2E9BULL; std::uint64_t aWandererB = 0xC7A1CBD24E5276C0ULL; std::uint64_t aWandererC = 0xD702BF227B91B559ULL; std::uint64_t aWandererD = 0xC4DEF81B55484912ULL;
    std::uint64_t aWandererE = 0xA1911032F0EEFD22ULL; std::uint64_t aWandererF = 0xBA217787D9829899ULL; std::uint64_t aWandererG = 0xC3AE7AA3936843E5ULL; std::uint64_t aWandererH = 0xA93A89A3B670B5D0ULL;
    std::uint64_t aWandererI = 0xAF7ACF33AFAB201CULL; std::uint64_t aWandererJ = 0xC891984B7833C8CDULL; std::uint64_t aWandererK = 0x891B27583F420412ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC9491269E6135A09ULL;
        aCarry = 0xB2862593B403A467ULL;
        aWandererA = 0xFFAB56AED92A2DB6ULL;
        aWandererB = 0xB5BAE308DFA8D5ADULL;
        aWandererC = 0x84B82539A4E902E1ULL;
        aWandererD = 0xE919736880CE3C55ULL;
        aWandererE = 0x95BB699E69A0766EULL;
        aWandererF = 0xDA7EB5AEEE9D47E4ULL;
        aWandererG = 0xA84E6FB4DF97F93DULL;
        aWandererH = 0xC3FFC4020CB6D914ULL;
        aWandererI = 0x8FB3936F56906985ULL;
        aWandererJ = 0x88CF3645D9E0E7C4ULL;
        aWandererK = 0xEB154A2A94FAA09DULL;
    TwistExpander_Achernar_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x98E7FDD60A552D7EULL; std::uint64_t aIngress = 0xD1F7DE86B19F9F4FULL; std::uint64_t aCarry = 0xB2A40034FDD4A6CCULL;

    std::uint64_t aWandererA = 0x8940B59872D2B098ULL; std::uint64_t aWandererB = 0xE12E80C70E0AD559ULL; std::uint64_t aWandererC = 0xCE12C376202D8E29ULL; std::uint64_t aWandererD = 0xC8507343BDA174E3ULL;
    std::uint64_t aWandererE = 0xE1B8DD7EAEB723C8ULL; std::uint64_t aWandererF = 0xE50AD246E75060F5ULL; std::uint64_t aWandererG = 0xAC3DE1CCA2F80008ULL; std::uint64_t aWandererH = 0x91EC59D80B798493ULL;
    std::uint64_t aWandererI = 0xD7998752B151FEBDULL; std::uint64_t aWandererJ = 0xCB4AB630FD9BDFFBULL; std::uint64_t aWandererK = 0xF3562A23E7CA7EA6ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBCE2A462A52D8A1CULL;
        aCarry = 0xE3355E51E41AF7EDULL;
        aWandererA = 0x837425366AE8C5DDULL;
        aWandererB = 0xB395153803065313ULL;
        aWandererC = 0xE67434C27F4FD75CULL;
        aWandererD = 0xE4B8CAA11945F6F7ULL;
        aWandererE = 0xB49593F2695037F6ULL;
        aWandererF = 0x9C8714F3EEC92A95ULL;
        aWandererG = 0x8ACEBC8C4EBD8C51ULL;
        aWandererH = 0xF2B2C91C7909525AULL;
        aWandererI = 0xB217FEE394272914ULL;
        aWandererJ = 0xA16019821ED119A8ULL;
        aWandererK = 0xA6652F9AC2932C62ULL;
    TwistExpander_Achernar_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFC8271992C6F66E3ULL; std::uint64_t aIngress = 0xF87D7D37D8C38FD0ULL; std::uint64_t aCarry = 0xD651DF3AFA9D1F2DULL;

    std::uint64_t aWandererA = 0xFA95A758C5FA2E7DULL; std::uint64_t aWandererB = 0xB365FC9620A3EC9DULL; std::uint64_t aWandererC = 0xC700CD20D2C62B3DULL; std::uint64_t aWandererD = 0xA4DCE567E212E4ACULL;
    std::uint64_t aWandererE = 0xA076F4F67FC2E7A0ULL; std::uint64_t aWandererF = 0xE02CB4FE3E4F8489ULL; std::uint64_t aWandererG = 0x8109532FCF178E8FULL; std::uint64_t aWandererH = 0x9E5A7C8FFFF6FECFULL;
    std::uint64_t aWandererI = 0xDC6BEDA6451F3E3FULL; std::uint64_t aWandererJ = 0xCD01CC4E1D0D92F8ULL; std::uint64_t aWandererK = 0xD95ECA27EB8633A4ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE5E13A3306EBF8E9ULL;
        aCarry = 0xF6AD5B40C8AE63A3ULL;
        aWandererA = 0xDB1A45DAB1E5780BULL;
        aWandererB = 0xA3C7DC5016188851ULL;
        aWandererC = 0xE2DDC79D19D63618ULL;
        aWandererD = 0xFDBFCE168053D92DULL;
        aWandererE = 0x82A237C27A393FCCULL;
        aWandererF = 0xC5310D7475C1BBEFULL;
        aWandererG = 0x84F211F1AE5488E2ULL;
        aWandererH = 0x9817466E68438009ULL;
        aWandererI = 0xF5C3AA5D05D80A0EULL;
        aWandererJ = 0xA11FCFB6088F6A09ULL;
        aWandererK = 0xED7BE37E3330A6B7ULL;
    TwistExpander_Achernar_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD052714024ED7648ULL; std::uint64_t aIngress = 0xFCAB2A059CC694B2ULL; std::uint64_t aCarry = 0xFEDBEAB4D60EDCFCULL;

    std::uint64_t aWandererA = 0xE54E28931AF5BFC2ULL; std::uint64_t aWandererB = 0xCD041694B341360AULL; std::uint64_t aWandererC = 0xF7963D51BB77EA96ULL; std::uint64_t aWandererD = 0xFD4051C97596F5CFULL;
    std::uint64_t aWandererE = 0xF434A0EA2E906F21ULL; std::uint64_t aWandererF = 0x9E06C879C89E5D20ULL; std::uint64_t aWandererG = 0x9D081FDDCD11881AULL; std::uint64_t aWandererH = 0xADFDFB0DFDD06277ULL;
    std::uint64_t aWandererI = 0x86E2093E6B884162ULL; std::uint64_t aWandererJ = 0x996F595BC6265364ULL; std::uint64_t aWandererK = 0xFE06027A62ACCF61ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD01121754747D31EULL;
        aCarry = 0xBA4509FD1E128912ULL;
        aWandererA = 0xF5C08FF648C7A43FULL;
        aWandererB = 0xB671E142805F854DULL;
        aWandererC = 0x9514A4CA3B2AF3A8ULL;
        aWandererD = 0xF45F25215CC9C11BULL;
        aWandererE = 0xD177E89F4FCB5C6DULL;
        aWandererF = 0xE43E7615F3A21438ULL;
        aWandererG = 0xCAE795A08F23F074ULL;
        aWandererH = 0xACC3649346196486ULL;
        aWandererI = 0xE705312C0E7C8151ULL;
        aWandererJ = 0xA03EF4E23E86B0A6ULL;
        aWandererK = 0xB859D857E37C0956ULL;
    TwistExpander_Achernar_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Achernar::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x930F33B8D76C18FEULL;
    std::uint64_t aIngress = 0x9365CC550A9495AAULL;
    std::uint64_t aCarry = 0xE7851FC6919AFE55ULL;

    std::uint64_t aWandererA = 0x8E76C5E4379D23A8ULL;
    std::uint64_t aWandererB = 0x9FA6D6AD7C87C474ULL;
    std::uint64_t aWandererC = 0xB794A9C6A8283D02ULL;
    std::uint64_t aWandererD = 0xE05F36A70C334915ULL;
    std::uint64_t aWandererE = 0xC8601CE4E28FA3B7ULL;
    std::uint64_t aWandererF = 0x8B46EB93701D56ACULL;
    std::uint64_t aWandererG = 0xC618CE10F2CEBCB4ULL;
    std::uint64_t aWandererH = 0xAF5E463146A8BA36ULL;
    std::uint64_t aWandererI = 0xDC89D8166F42AF22ULL;
    std::uint64_t aWandererJ = 0xC928193619F9B149ULL;
    std::uint64_t aWandererK = 0xC88C533AA485D6C7ULL;

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
    TwistExpander_Achernar_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KEY(pWorkSpace,
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

void TwistExpander_Achernar::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC1B1693D8B8D0859ULL; std::uint64_t aIngress = 0x8CE0DB0145B11400ULL; std::uint64_t aCarry = 0x8ECDE7FB43B7979BULL;

    std::uint64_t aWandererA = 0xE0CB7294F2528536ULL; std::uint64_t aWandererB = 0xAA0E194292A73C45ULL; std::uint64_t aWandererC = 0x913096D931A14800ULL; std::uint64_t aWandererD = 0x97F7F24F8E35F962ULL;
    std::uint64_t aWandererE = 0xBA6CA73AF2BE8588ULL; std::uint64_t aWandererF = 0x820C7AB9956B94A2ULL; std::uint64_t aWandererG = 0xDB3278CB19FF83D4ULL; std::uint64_t aWandererH = 0xFC27D6C8CF02703BULL;
    std::uint64_t aWandererI = 0xC1C6CC4E671F9389ULL; std::uint64_t aWandererJ = 0xA296678499466FFAULL; std::uint64_t aWandererK = 0xAE6B5AA7C17FCAF4ULL;

    // [twist]
        aPrevious = 0xD62F29DD9CCE8989ULL;
        aCarry = 0x9B7CEEF301011503ULL;
        aWandererA = 0xACBD27C0030654C8ULL;
        aWandererB = 0xFB1925B62AD3967AULL;
        aWandererC = 0xCB919475DA1F2790ULL;
        aWandererD = 0xE071D8AB054A17C9ULL;
        aWandererE = 0x9B80203D0B4672CAULL;
        aWandererF = 0xCAA5835C93A21D47ULL;
        aWandererG = 0xE59A7FDC0670A9B9ULL;
        aWandererH = 0xB3114D977E762416ULL;
        aWandererI = 0xBAE4A498AB1A53FBULL;
        aWandererJ = 0x94D2531D20FB4B8CULL;
        aWandererK = 0xAB3D59ADDE63F035ULL;
    TwistExpander_Achernar_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Achernar::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Achernar::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Achernar::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
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
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
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
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 1 of 33
// Exploration cases: persisted candidate
// Structural distance: initial random-shuffle baseline
void TwistExpander_Achernar::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
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
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1488U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 1 of 33
// Exploration cases: persisted candidate
// Structural distance: initial random-shuffle baseline
void TwistExpander_Achernar::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
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
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Achernar::kKeyRotateSalts = {
    {
        {
            0x94F3A718882948F4ULL, 0xB7DCEE7ACA0B97B4ULL, 0xCE885DBFBA0F2541ULL, 0x95CFBC718B84016EULL, 
            0x6C1C4974F5AAFBFBULL, 0x6C53EC30A744F5C9ULL, 0x77BE5C721B7D9E14ULL, 0x6DF8E344B5DF3462ULL, 
            0xECD33BE8887728C8ULL, 0xF2FBC9A48366A64AULL, 0x52A3C6399EFD34FBULL, 0x35E9809954DA09CCULL, 
            0x61882ED0F13F0F7CULL, 0x56653441333627E5ULL, 0xE2A71BB032D13C9EULL, 0x6D4E3374E4DE79EBULL, 
            0x28CB16C6C0EAB110ULL, 0x07C0199E25D93C0FULL, 0xF3A7416EDA056E42ULL, 0x8E1954FBB41E2E55ULL, 
            0xAE503F7459F8C93FULL, 0x1C5428E3F339336CULL, 0x49D8F449BE0B56A9ULL, 0x1511E378BF55C131ULL, 
            0x97B08BA95395DC31ULL, 0xFACB07F1DF1ABC2CULL, 0x0600D5652F39D1ABULL, 0x46A52E482114D40DULL, 
            0x4F689E6AADEB04FFULL, 0xA7F7519A142EB068ULL, 0xC4CF5A802F43B611ULL, 0x1B1AD79AD52527BAULL
        },
        {
            0xE344B13DB9DEFEFAULL, 0x3D146E3C6D5108ABULL, 0xD45CBC4943C93656ULL, 0x5E8E8F79C8D53822ULL, 
            0xB8AB698FCFC6CAD4ULL, 0x9902F94614091327ULL, 0x5FCF2DB78A43360DULL, 0xAE9B68F1468CE8F8ULL, 
            0x9FA0A77ED9B5C191ULL, 0x5A391D28C0C58E0EULL, 0x38C2FD2A87FF7607ULL, 0xD28D37285A2179CAULL, 
            0x2F23589200830C47ULL, 0xE380AB6B147927A1ULL, 0x6ACA2E7F6E89C3DCULL, 0x7E1740B4DE385615ULL, 
            0x77CDF93229F9B08EULL, 0x53C46508E9F5CA6EULL, 0x7CC8B76FD2BB4326ULL, 0xD891774721CA39BCULL, 
            0xA3236663930AB012ULL, 0xA0F7313012EF46CEULL, 0x67624AFDD8E57172ULL, 0x720709D9DA883270ULL, 
            0x912AE9670FFDCBCFULL, 0x90DB1E6548C71C57ULL, 0xE4A17DBE17A133A4ULL, 0xF9685BD75B304229ULL, 
            0xCAA1288E4D282F2BULL, 0x46BCC58782C2C8D9ULL, 0x0DE55B9F89BC112FULL, 0x6B221282475B25E7ULL
        },
        {
            0x1ABE4E6D33B43D48ULL, 0x60CE78525B101AECULL, 0x5E2A4312FFA3BEDAULL, 0xA0F5072F08505939ULL, 
            0x1F8764AAAA282B96ULL, 0x3CDB6A72546F2100ULL, 0xF46264B4A9A05465ULL, 0xA68EECF601620FAEULL, 
            0xC75BBD950EBA354BULL, 0x317031096322ECF3ULL, 0x5F7DD0CE81312C45ULL, 0x73C024C2640E5F39ULL, 
            0x2F273DE2DB97F775ULL, 0x73E7129267C3E51EULL, 0x5A30B85981D390B8ULL, 0xEB44914B9A3AE9A5ULL, 
            0x6D3E99CEB6410817ULL, 0x3FD60BAD1859AC59ULL, 0x2DA13701D46F1B39ULL, 0x3A0715BBAE6B09F1ULL, 
            0x38C27A5AA019B17AULL, 0xB0683FF9219D2876ULL, 0xD276C7B594BC91BBULL, 0x40ECB5A82B130156ULL, 
            0x3C565C78569868C3ULL, 0xE38910298E3562FEULL, 0xA2033E547A412FCBULL, 0xF7E84607DF895D4FULL, 
            0x018A6D229F9E516BULL, 0xB724651F21BD03C0ULL, 0xAAF814D09D614CA8ULL, 0xB96D2FBAB2AB2BE9ULL
        },
        {
            0xA49ACB338AC6B0B2ULL, 0x92B269237924332EULL, 0x96ECF2EB8AD5CC64ULL, 0x52FA1BA722E538F1ULL, 
            0x963B7E865B20AEFCULL, 0x25D0D237110FA75DULL, 0xE5A4A6CC043BA96AULL, 0xDCDDA1D4E5A7E517ULL, 
            0x03BEEF0302351AFDULL, 0x8A23ABB8933787A9ULL, 0xD8DEB9E828F1B5B6ULL, 0x28050A50C6C8C860ULL, 
            0x1AC65FB4964EA7A3ULL, 0x9EDDCC98A8335F94ULL, 0x779D525B130BBDB4ULL, 0xE065D11F331CDE3AULL, 
            0x1AD1292D5DC5ADD3ULL, 0xF043040D2E555A43ULL, 0x188FCCEB2EAB349EULL, 0x6DCCC5EBE3B41796ULL, 
            0xF49814A750077018ULL, 0xE3AA2BD5553225F5ULL, 0xC6DEEA679AFB1185ULL, 0x5B916622B1DB7CE1ULL, 
            0xC13A9AEA9E9B5048ULL, 0xD2A4C9A6D654B60FULL, 0x8473ACB7BF337244ULL, 0x1C7447B8581BA742ULL, 
            0x985662A7E6B80E76ULL, 0x713B8C9A3E240028ULL, 0x6AE52AF77A2BCB7AULL, 0xEA9A62D9FD7816C8ULL
        },
        {
            0x6FE70DBEBB9631FAULL, 0xD5003554C18B3122ULL, 0x39C2C8288EC0F4F0ULL, 0xD2BC7799C3ACDF27ULL, 
            0x2A38A06B30E9CB60ULL, 0x5F1C254E3F22757CULL, 0xFC7876EAF8982A39ULL, 0x1895B55E21D73EF0ULL, 
            0x2AF6CDF4DD793925ULL, 0x5365E0445BEA13C7ULL, 0xF35F75481BAAC2E4ULL, 0x3547F86889C74C94ULL, 
            0x96BB4BBFC8291EDBULL, 0x9008870A96AB43DEULL, 0xED36A3782FDC5362ULL, 0xE2232893496BF785ULL, 
            0xC158FCF7110937B3ULL, 0x6FFF565CC7A65D68ULL, 0x04AB8F42F2D5A458ULL, 0x08EAEF04BBB523E0ULL, 
            0xDE2293B3847D7B32ULL, 0x844C2B2DE9BDF29CULL, 0x73530B4ADD2FB2FEULL, 0x6007808470B5AD2AULL, 
            0x282A83AB4F08EE7CULL, 0xFF86EFA9D2ECD6CFULL, 0xDF0EBA497F0D77B6ULL, 0x42A76787585E51E1ULL, 
            0x0C2B6DFEFD6D62C3ULL, 0xB0DD926A8350D70DULL, 0x048811A2F0C59DF5ULL, 0x26E83A26236A6796ULL
        },
        {
            0xE1668F465D705773ULL, 0x289BCCC1DD9BDB18ULL, 0x5FEC81D79BFF2758ULL, 0x3D24465AE9CD7888ULL, 
            0x5F7C1B7E5D5EA7B9ULL, 0xBCE4B0A3C6993CACULL, 0xA98BED1B01CC9CFCULL, 0xE646356AD4FA1523ULL, 
            0x63798AEE548F4435ULL, 0xA0FF0BB21A88ADC9ULL, 0x6983EB761F448F87ULL, 0xC8E054468421CDCBULL, 
            0xBB46D7F8D4358B90ULL, 0x74DBE44BCAF68FEEULL, 0xD0643C48EB7FD562ULL, 0x1109CF1A6EF2FB78ULL, 
            0xE28CC2AA87BA96B5ULL, 0x99976EA8A975EFD7ULL, 0x5401A0296442CF14ULL, 0x79876C26C5F9E7CEULL, 
            0xFC80C19EDC092620ULL, 0xB0EDFC709117AD51ULL, 0x87D3D48F9AC225CAULL, 0xB83BB28E30817177ULL, 
            0x98AD5F09044D6CCEULL, 0x54D9B704714D20EBULL, 0x48B18E10E303054AULL, 0xBEED4E70FC7B6B57ULL, 
            0xC9804EA40928B9C2ULL, 0x2C6733BC65DD6538ULL, 0xCD053335E8FA096FULL, 0xDD43DB78912AA3CFULL
        }
    },
    {
        {
            0xDF1C7B8C2960074FULL, 0x2768BB12627EB2BEULL, 0x91A11F3A0EB53F9BULL, 0x4BEEFDEBB72848FEULL, 
            0xC7858C3BE6ACBFBBULL, 0xAFBEC869C54B7741ULL, 0xA3C4E2A10D1D524AULL, 0x1639CE63AFB349FFULL, 
            0x8AE05D2B79C34DF1ULL, 0x9C77659857E13A95ULL, 0x02BF98FD62BA937FULL, 0x50261DE96FF6CEF9ULL, 
            0xC6EE1E9D134F143CULL, 0xEC1E888C578255BDULL, 0x6F66F82CE39A7218ULL, 0x9ED9E53805DF8299ULL, 
            0xD9BA136F3DC30894ULL, 0xF6EFA8A1D4EFC8DCULL, 0x5B96B952F12798A5ULL, 0x76255F4A1BFC0D56ULL, 
            0x07309210C5363743ULL, 0x5B4E8CB929E5414CULL, 0x98C1F54E1597CACDULL, 0x1F6F602C771A569BULL, 
            0x197B430FEC8404C1ULL, 0xF82B10728AB0B255ULL, 0x7898A80F90A91C84ULL, 0x60D5F2938399D50EULL, 
            0x23B2A86394F083B3ULL, 0xA9C84C33A227B53BULL, 0x9EE5479135CFB8ADULL, 0x60DEC4972493BDFBULL
        },
        {
            0x5E184D2A712AC534ULL, 0xF82388563CC54320ULL, 0xF1D1296FD54DCC5DULL, 0x1F1E50F720971C89ULL, 
            0x5FD95F16693010E7ULL, 0xFE9219036011E48DULL, 0x92EEFBC3CC35CF0DULL, 0x7E1E5A1EDEC4B942ULL, 
            0xE917C1DC406E016DULL, 0x42FF06CAF855770DULL, 0x425D111AA5866DA0ULL, 0x4CA2FA9103C70D42ULL, 
            0x9C17773B31F78683ULL, 0x9AD929AF92607249ULL, 0x89F38286AA3190D5ULL, 0xFE8DB6467AFDC6B1ULL, 
            0xB9F9CCD02265BB78ULL, 0x435FA93FC4ADBA00ULL, 0x1A6004E1E8EACE22ULL, 0x1E1D257C1196F6ABULL, 
            0x5A10D33E71E5CBEFULL, 0xAADA0E844871815FULL, 0xDA29812AB19568A8ULL, 0x32F02FD9375F1F0BULL, 
            0xB1737BEC71811A5DULL, 0x4AD72B33931A978CULL, 0x33A421F97032B131ULL, 0x608E67782C170774ULL, 
            0x50ECF524069E95AEULL, 0x6DF05C5EF922062CULL, 0x5EE6DF2FA28F2CC5ULL, 0x3623A075ADDBCE95ULL
        },
        {
            0x1F88EA8DB7B34FD1ULL, 0xA5013B5B6DC5483AULL, 0x791F5315E20F7459ULL, 0xE8EED3102DE82B99ULL, 
            0x42EF507785282624ULL, 0x831DBF750565F649ULL, 0xEEF7E32B46D47BDDULL, 0xEC3C285EE31EBD9BULL, 
            0xBB934F36C70AF0C1ULL, 0xDEF2F0079D72230BULL, 0x2B61116565E9F827ULL, 0x0A51E106559CEFF0ULL, 
            0xEFF104CC80AD43AFULL, 0x551840F43B51B78AULL, 0xB1DD8CF416233C06ULL, 0x3838ECA015774199ULL, 
            0x59A7C74DE87EFC8CULL, 0xE4740B1BD27DCA6CULL, 0x4F33102EE428FF88ULL, 0x7D2D2F75B4A3CCDCULL, 
            0x8A06FB00D1D8479CULL, 0xE7DC1BA36A93D15AULL, 0xB4C5B6C25C206AE2ULL, 0x557155EFD55693F2ULL, 
            0x152455DA28F3C82FULL, 0x2119C4FCE0642A22ULL, 0xD3D0307F578D9238ULL, 0x91D70C47C6E27313ULL, 
            0x04B1780376FAA99AULL, 0x8CA34C86AD01A678ULL, 0xDF9966CA967DB607ULL, 0x72ECE85BDB43FF8CULL
        },
        {
            0x8EA82F92C3AB89A4ULL, 0x581B62A0129FFBA4ULL, 0x9665D00DCDAFBA35ULL, 0xE227DCDD58C743B0ULL, 
            0x1446891A33C8D93CULL, 0xD2C1FCD64529398CULL, 0x417CD0C3F6DA4749ULL, 0xA6279AB8378AED87ULL, 
            0x4871477F0DD5EF55ULL, 0x4C7E60D4509C8AA7ULL, 0x6B39D87FEA5B3C56ULL, 0xA6B3C1571AEFD34AULL, 
            0x9DE6A1996FAF2B4DULL, 0x00AD4B7D355913A7ULL, 0xB1150618907AA951ULL, 0xDB97F813B0E6E4AFULL, 
            0xE1B4E7D960244C7AULL, 0x96A0C88A649DCE6BULL, 0x36241C93405BDCDDULL, 0x19F51E71F0809037ULL, 
            0x33446683DEC90F78ULL, 0x1DA6C86653E59B7EULL, 0x2C41BCD61F203D2CULL, 0xC4CC51FEBFA4C930ULL, 
            0x6B2373046BDBE109ULL, 0x133C709C128DF93FULL, 0x59EB66DF15C3BFB1ULL, 0xA137C13EE0337A77ULL, 
            0xEB2A3F4C25DAA5A0ULL, 0x88B7A6CC072D67B1ULL, 0x384B90DB319E867BULL, 0xBD8EEC24B0203ECBULL
        },
        {
            0x8CE9EDC71154E994ULL, 0xF1A2EC126B98677DULL, 0xEEFB52B84BD7E0E3ULL, 0xB820CE01F7E015EAULL, 
            0xB825E6C610A3E297ULL, 0x8465E9CE405B03E7ULL, 0xCF10EBE7FEBC4057ULL, 0x45E72D15D8DB3B57ULL, 
            0x63FFAF78558A38B6ULL, 0x49C914F8567AF6C4ULL, 0xB32F308A3D1D2AA0ULL, 0x7A7F85BE7CDC3AA5ULL, 
            0xA92E78FF9749AAD1ULL, 0x507F951DEA9A8142ULL, 0x708DCA9E7D3DB909ULL, 0x70A5C6A40D1D29D3ULL, 
            0xB12ECC45D1F440CCULL, 0xD054E3E3B6028A15ULL, 0xCC613B545DA1E6B0ULL, 0xBA4F3BC31222DE13ULL, 
            0x1BAC451CA67DD2F9ULL, 0x1824B34D1238B4E1ULL, 0x7E89D3FBE263D0D7ULL, 0x2CDE924D1DC3ADCCULL, 
            0xB17C7CFEDFA504BEULL, 0x787298C057799B55ULL, 0xD0629167FA00F8FBULL, 0xA4B0121F9C94E399ULL, 
            0x71DDB6A4A461993CULL, 0x43D9DE91188FEF67ULL, 0x5AFE2C67D0263E40ULL, 0xC83952402D420516ULL
        },
        {
            0x38A72A0E7E999BBFULL, 0xA0E9E7D9C597AC3EULL, 0xE037507D60091F64ULL, 0xAF8DE3DEEC508134ULL, 
            0x8B69031EC7DB9002ULL, 0x0C1DD9CE4835B461ULL, 0xF11D3B58C0B31659ULL, 0xBBA5F9FD0A196D67ULL, 
            0x2E38DFC8BB8010D2ULL, 0x6CAF08BDFFD1F286ULL, 0x0339C6B5F06EC87DULL, 0x1494A4E528248AD1ULL, 
            0x5D053D2B41DB8763ULL, 0x837AE375DB5FDB80ULL, 0xBF3FEDA53FB3DE3EULL, 0xBA0C5F5499CA02C6ULL, 
            0x815B42E5B809F259ULL, 0xFC0ED8374AFA048DULL, 0x2314A3EB708166C0ULL, 0x1CB820F81822D6D7ULL, 
            0xEC3135AD1272D221ULL, 0x625DE359691C52BBULL, 0x0A28DDBEDD1BA7B8ULL, 0xACB73216FC88AE42ULL, 
            0xEE354CA77ABAB8C9ULL, 0x70E35BE4CA01A3BBULL, 0x9C8A14B498AA9432ULL, 0x4804018995359CADULL, 
            0x7D7D6B601EE5AE2EULL, 0x203D625C213A720BULL, 0x89DDB47E8EA7ADE0ULL, 0x4D7DE9AC7E09AF3EULL
        }
    },
    {
        {
            0x46C1AA433B2248B0ULL, 0x5C0CCAB7EC0C3C7CULL, 0xAB3E5AEEB7F642DDULL, 0xDEC6E383C0259409ULL, 
            0x0FDB3E026E7D16FDULL, 0x04DC4AF2A9F8B043ULL, 0xAE5BEA89274192DDULL, 0x0A6FF756AECDAA6FULL, 
            0x194BE37C649C0A33ULL, 0xDF58557F52AE5493ULL, 0x62B411901850DEDBULL, 0xD748488EC1502177ULL, 
            0xDD1B0CFDDEADB7AAULL, 0xD56013E6368F3D04ULL, 0x111019F782BB2017ULL, 0xA3739B5DCB716FA0ULL, 
            0xDC3B75F8FB0C0900ULL, 0x6B429EA1112FB122ULL, 0xEB2EC060196258E0ULL, 0xB0C1678B608CA5B5ULL, 
            0x4BEB9B6E731C0712ULL, 0x10E122ED638B0C6CULL, 0x5D00708300E75C42ULL, 0x09FE7B3B380699EFULL, 
            0x77B1CA85A1C38A37ULL, 0x2D175F3418CF8964ULL, 0xCC379EF956F3D54FULL, 0x7D537E1618ED9513ULL, 
            0x54EC2F1922B848ECULL, 0xB46C608167A2BDE6ULL, 0xFFFD9EBFA1804DB0ULL, 0xE4C1E93D348B19C1ULL
        },
        {
            0x8394C4548FBF6560ULL, 0x5114F56BFFE1BA29ULL, 0x0A12B4616BC47E70ULL, 0xBBA862FB2FBCDBECULL, 
            0x903A055A1FD72285ULL, 0x3E9068DB0937FC49ULL, 0xECA1D16D26750A20ULL, 0x811FA7072932370DULL, 
            0x0C1F66301D2275ABULL, 0x52AB2903F83A7BB0ULL, 0xB71660998481FC99ULL, 0x257DD44B511E8957ULL, 
            0x901A2687AA14829EULL, 0x5307529B0DDBB3D1ULL, 0xA0AC7637AEC23064ULL, 0x906900559654315CULL, 
            0x60655590FF5997D1ULL, 0x22C29BFA366EC7F2ULL, 0x59726BD22743653AULL, 0x6F8E954E1275E193ULL, 
            0xB820A369430F6C9FULL, 0x52FBAFC7FD4C6361ULL, 0x20D2D148459B7F33ULL, 0x4F21E8DA2D92D3C4ULL, 
            0xFADA5DA6FD56C406ULL, 0x292C5DD6C6ABA34CULL, 0x4FF69EDC0F367930ULL, 0x791A926886008ED4ULL, 
            0x9920B3B140DF0BE1ULL, 0x2FA4EFCCE80A4206ULL, 0xC32551FC95AFD600ULL, 0xA3706BE6E63937A9ULL
        },
        {
            0xABA89393B2C26308ULL, 0xEDCA7A25B0CC098FULL, 0x694992CCC0C74CA5ULL, 0xBD3BCF2EF09B7AD9ULL, 
            0x19AF4987E6093E2AULL, 0xE8C0D7CB0E61F397ULL, 0xB85AF7E9FEABC5A5ULL, 0x26A2DA348A4C512BULL, 
            0x5EA136B17D50E776ULL, 0xE7244F12FABD1E7BULL, 0xF42741E3D9DF4B72ULL, 0x6E20692E280E60F4ULL, 
            0x3CFA66AEADC9FA01ULL, 0xA63DE06381444E18ULL, 0xEA904F8091980AF3ULL, 0xC51599FDE043CB1BULL, 
            0x41E29B63F6BCE651ULL, 0x82650A45A5ADD90DULL, 0x1A98E96F86300E47ULL, 0x5D099D25C2E8FE11ULL, 
            0xE231B3C8CE453210ULL, 0xC46F4D3E16D3D2C3ULL, 0x3CC433AA41CE0ADFULL, 0xBB06A75EFACB637CULL, 
            0xDCA3D9CAFC554F14ULL, 0xC0F146883CC2F28BULL, 0x71D59B55F4AAA938ULL, 0x521F7C2EC8A64AB6ULL, 
            0x91D1308B6806027EULL, 0xD8FACC9F07CC0954ULL, 0xD174D32A1A653616ULL, 0xDFAF1CA45B5C8471ULL
        },
        {
            0x7DB255C452C066E1ULL, 0x3A9A09F97068BDBFULL, 0x4C8EF0EA6C2914ADULL, 0x18AC71B7BD26A06CULL, 
            0x9EB7E4158D414FAEULL, 0x775CAD8AC50B76EAULL, 0x97701DF326EC20A0ULL, 0x7D099BCA1E98F25EULL, 
            0x1752C4699369FDFFULL, 0x1A9446F70866AE84ULL, 0x8F24B900710B459FULL, 0xE2F436B6CA590EADULL, 
            0x58B6DFC864010F9EULL, 0x5BF62D2155C41105ULL, 0x15079DB3A68A57FCULL, 0xC82F89EAEF441799ULL, 
            0x4FE0E702ED87B6C3ULL, 0x3C34F4A54CBAAB50ULL, 0xB37C653A5986C5E1ULL, 0x6E752D64AC91C95EULL, 
            0xDD6B577C072E6DA8ULL, 0xD42BA4A73934B036ULL, 0x6CA9BEAC2FC9FADBULL, 0xE81F6BBF0D384ACAULL, 
            0x2941BD0E081E386CULL, 0x0ABE3E7019845168ULL, 0xA1D0686A0A704859ULL, 0x6FFCF415849FE5AAULL, 
            0x8E526AE4B7CB344EULL, 0x86EC04C030078228ULL, 0x0AC3819D91B0010FULL, 0x2DBD38C69C561C7CULL
        },
        {
            0xDE6C515DD6D3515BULL, 0xBBC99A77B72C81EFULL, 0xD2B03B0EB11FBBCDULL, 0x38B446959D22C11DULL, 
            0x8C0DB6871C24965BULL, 0xEAEECDB0275243E0ULL, 0x3228D50E98FB9DD8ULL, 0x41220C20629417BDULL, 
            0xE5676A4B1961016DULL, 0xC91D2DF563912002ULL, 0x1D00D98ED597D5E6ULL, 0x3BC5E93C3E3C6564ULL, 
            0xC3C1950BEE1E3B05ULL, 0x6EE85A9BE756801DULL, 0x573425BB7D582DA3ULL, 0xED580BCD4BE8ACD7ULL, 
            0x1ABA24FBB57A9AD3ULL, 0xABE03F7A87D86E4BULL, 0x00B0F108C26B3C11ULL, 0xCCDA4EF6B3554097ULL, 
            0x29732E369BEB3C42ULL, 0x8BE3F3AFE720FBB1ULL, 0x784C10CE8939ECD8ULL, 0xB061B9D4313EB4F2ULL, 
            0x1EC043C9A98BA279ULL, 0x776197EF6DDB76F3ULL, 0x9777872A2481F88DULL, 0xBD4E24F7472548C5ULL, 
            0x030F7DC0D96E1A2EULL, 0xA82C3876FF863C1AULL, 0xFBA26FC74D1DB174ULL, 0x766072548E43F978ULL
        },
        {
            0xD91521A502684CCAULL, 0xDF72E6CBBC704493ULL, 0x458408B748001C41ULL, 0x56A2339E6827A7DBULL, 
            0x3FA19D014A9CDB87ULL, 0x723A91F4F432B425ULL, 0x54AE02CE48775B2CULL, 0x1087565E9C58C286ULL, 
            0x4CB178ED1C46C242ULL, 0xDEE324FADE161F06ULL, 0xFE69D5713551E477ULL, 0x8D1B4800ACE51ECBULL, 
            0x3A0B9C0EFD63753DULL, 0x56F445B00A47A84BULL, 0xBBF42FA01A0EFF22ULL, 0xB926CE0AE4139071ULL, 
            0xEA0741D4B569EFCCULL, 0x80421D6AD7C992E4ULL, 0x287B8194F1BA50FAULL, 0x70E731CC6C56394FULL, 
            0xFAAEEA882DBE6DBCULL, 0xF716F817F40791A6ULL, 0x36BB836EB4AA6EA8ULL, 0x4EFE49F10428D045ULL, 
            0x6FC97AEBB63F19EDULL, 0x3EA5A6767FC066FFULL, 0x69D0CC55FE2D856DULL, 0x35FF8A453AED062FULL, 
            0x85416A71B309CD8DULL, 0x12E7FFA64A71EA93ULL, 0xCBDD1954B4A2E40BULL, 0x6A2693160331C208ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeyRotateConstants = {
    0x82FF703D871D008CULL,
    0x7EF9DE90CF6F5396ULL,
    0x525F3C388427A071ULL,
    0x82FF703D871D008CULL,
    0x7EF9DE90CF6F5396ULL,
    0x525F3C388427A071ULL,
    0xCC08EBCEE37DE605ULL,
    0xB922218FADF76FE0ULL,
    0xDA,
    0xA6,
    0x8F,
    0x9A,
    0xBF,
    0xB9,
    0xFC,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Achernar::kKeySpawnSalts = {
    {
        {
            0x7DB4355D2C0045DBULL, 0x32BEBCCD7046E7ACULL, 0x3E2E113AEBBDB7F8ULL, 0x3D375FB3A4C7109EULL, 
            0x6465D810F3B97AC8ULL, 0xBB93A7E59FBFDD7EULL, 0xCCDFF2DAE8014039ULL, 0xEB866820C46713B8ULL, 
            0x9BB03DB10191D445ULL, 0xDA7A32CC5DC67600ULL, 0x587DFB307FA01B7BULL, 0xB7CCFE86900A0A60ULL, 
            0x839928C4A6F1AE33ULL, 0x6A08AB83A1029795ULL, 0x744371A343F57D90ULL, 0x88239E977EE797C8ULL, 
            0x5564DA146035331AULL, 0x7243CAD77F750FF3ULL, 0x3FD313CF6EEDDE30ULL, 0x54B6890C592B20F9ULL, 
            0xBDDDA246135218D9ULL, 0xE519217BF3B1E02EULL, 0x3BB8345F53CE8AA2ULL, 0x2D6812FCB00FF100ULL, 
            0x045E0256FA8318CBULL, 0xB0E2AB39E9635986ULL, 0xF0E2B04B317D8814ULL, 0x09EB8022FA5E6216ULL, 
            0xAFECB663139C55A5ULL, 0x8BB9FB91AD0FB625ULL, 0x4806E2CF6ED4BA0BULL, 0xFB66FEFEFD7A8D3FULL
        },
        {
            0x5029DD612054C883ULL, 0xB53598B456629D58ULL, 0x103A699341595FDBULL, 0xC5D2B8558D62AB9CULL, 
            0xDAE4C938A86BCEFBULL, 0x520064BD0A63B167ULL, 0xFE4F45115F289CF8ULL, 0xD30CB5961A7E1139ULL, 
            0x0F247C1081362FA3ULL, 0x7445D202514DE378ULL, 0x3623B37DAB37CC10ULL, 0x21161C231C451EAEULL, 
            0x03AE0357F4962340ULL, 0x030298D669A607C5ULL, 0xED16BF884D470E40ULL, 0xD0DD8E6CE3718D06ULL, 
            0x9E3CF621EEB59594ULL, 0x701D1CF76CD2111DULL, 0x236961141C510116ULL, 0x88259B74845FD6ACULL, 
            0x836EF5CA7F8C2187ULL, 0x2CBFC1120BDE0EFAULL, 0x854D526E5A18399EULL, 0xD65A6C6B43D5FE1BULL, 
            0x3F7CCFD409D833B3ULL, 0x44A5CAA7639B54B3ULL, 0xFD605E1EC38C6D29ULL, 0x3D96BEF190D7E626ULL, 
            0x897FB7EA338C8BD5ULL, 0x9854E75502D90459ULL, 0x7E2AA965DDA3903AULL, 0x66B503932D981D29ULL
        },
        {
            0xC0E7897F7C2E5B99ULL, 0xABC35E72AD3B08DEULL, 0xBF7B390AD088BD3BULL, 0x650C53424BC806D6ULL, 
            0x8D956F2884799259ULL, 0x0763040950BE034FULL, 0x19BF459998499DD8ULL, 0xBB6FEAD40117E7A8ULL, 
            0xD9AA59708A2F9437ULL, 0x1D12CC2D45964AFEULL, 0x8FA81D1676FDAE0BULL, 0x8FADD6C4A14CAD44ULL, 
            0x6EC0BEF05DB481D2ULL, 0x50A9745C3A9C232AULL, 0x57983643BD214B76ULL, 0xBA3694E603615EA1ULL, 
            0x0FBB50FACCDC7BD9ULL, 0xF3F9C1581C0F2268ULL, 0x1832C5A9DB6D19A7ULL, 0x04AC07C31C14513FULL, 
            0xE8CF78165D78999AULL, 0x9C174AFD400241D7ULL, 0x8340B4C93128DB6FULL, 0xDF729875C70427DFULL, 
            0x4A29A106A33A8A8FULL, 0xDFFB52F031DD9C60ULL, 0xF900E3AA58B542B5ULL, 0x5C33459CC8F2BC8CULL, 
            0x7B33FF6CE8CB0BA1ULL, 0xCD2E59CB5A2BD8D3ULL, 0x98B4830A5D28FD2FULL, 0x64CDD22C86A37C3CULL
        },
        {
            0x12EA5C333A2B3169ULL, 0x27336B0E1043337FULL, 0xD0C2760F5648681EULL, 0x42DD81A0ACD9184DULL, 
            0xE92ED6BE3EA08B93ULL, 0xB2C20547A2012056ULL, 0xE15A405FF3893B71ULL, 0xE01DF2C68A5EE810ULL, 
            0x506766052E1D21EDULL, 0xCA2F84C0DC606C57ULL, 0xA9EA0E2B6367C8DDULL, 0x7568C40E10CA3473ULL, 
            0x0386B666EFE1A57FULL, 0x2620555F87B64CA2ULL, 0xF69B18EE8F366778ULL, 0x91C55991BED532B8ULL, 
            0xB9EEBC4E54488DC7ULL, 0x6AA300BD7580EF92ULL, 0xC130598305299875ULL, 0xBD16521017D6244EULL, 
            0x6D07C0685C8F63C1ULL, 0x334D172507A1F95AULL, 0x720843313EDE0E70ULL, 0xEF65C1081BEB9DB4ULL, 
            0x58A4A72BFC3F8EA1ULL, 0x1EFEF59EB8F22EF3ULL, 0xB9A7A14244DD24E8ULL, 0x100058D6A6C07399ULL, 
            0x05F67C3DE2E9BF14ULL, 0x78CD719E0964906AULL, 0xBCD534382D3117D9ULL, 0x9A135E631C976337ULL
        },
        {
            0x01282092864DB9FCULL, 0x2816EE48C86A8476ULL, 0xFE6049BD01651DAEULL, 0x6059CCAC6A01943FULL, 
            0x74A57F456E6D9F0FULL, 0x11EF820D9B492F09ULL, 0x95CCD902C89AD789ULL, 0xD3E377FF17C4ACFEULL, 
            0x78D99EA4DDA39DF0ULL, 0xDCCF85F37CDBEA29ULL, 0x0989D4D02212CA3DULL, 0x70F5F4800B65953FULL, 
            0xF33D0641CB6E9F61ULL, 0xE755F92A11442A39ULL, 0xB503787D27CC2231ULL, 0xD59D0F19E3F615CEULL, 
            0xF5F13C9535564B4DULL, 0xA1ADFCE9647E87FDULL, 0x596C35B36D29C2EEULL, 0xF18AF629D77E61D1ULL, 
            0x6E8EC7172C87331BULL, 0x14A563DDFD4608F7ULL, 0xA296E51F392884DCULL, 0x02D5EDDB1C08F354ULL, 
            0x7E606DB6DCDDF374ULL, 0x6E08C44C2DD95277ULL, 0x2EFD20ECD8C0F614ULL, 0x4A2DFCE966849175ULL, 
            0x62B834BC80D077D8ULL, 0xA813BD4355B0E3BAULL, 0xF352D3F7FF64258DULL, 0xCB401D82E52F89C9ULL
        },
        {
            0xE40389BFB0A5EE38ULL, 0xFFE65D1CB79BD1CAULL, 0x192CE7D9D2BFD5A1ULL, 0xD787C99C48A82588ULL, 
            0x52C2178A7048EB7DULL, 0xD66A20F442FE1AAEULL, 0xBF8EB03863085AC6ULL, 0xD7AEDCF9313EF7ECULL, 
            0x419F9AB1106F0F85ULL, 0x652BBAF88858A4CDULL, 0xB49C196AD615830BULL, 0x296F43E79AF13BBDULL, 
            0x626F58A2C3F56A32ULL, 0xA7CE97034B6B0619ULL, 0x7B356B72DF2DFAA6ULL, 0x3B72F38875A33B5AULL, 
            0xE48B5C994F1E5E8CULL, 0x7EE54E806EB71CFAULL, 0x9784BB3E05B18711ULL, 0x493606BF1720D75EULL, 
            0x843414CD8D86541EULL, 0x937B257001DE62FBULL, 0xDA387F39E07FAA9BULL, 0x57A69164F00EDE05ULL, 
            0x2C69280B5E6DBB15ULL, 0x732625B16F57A9D6ULL, 0xFB9C7B4EFF1970F1ULL, 0x0CB999B1415A382EULL, 
            0x24BD69DBCD3D404EULL, 0x7985963C46A39139ULL, 0xD7F8AAB7CF7BA2F2ULL, 0x02E35CD56964492DULL
        }
    },
    {
        {
            0x8F5A4CA62BC1898CULL, 0x956E3B86ABA2EC03ULL, 0xA8E04A5F31D2C00BULL, 0x0DDB61029C5D355FULL, 
            0x520DE9DCCD92A245ULL, 0xCADEA1EC2DEE39ECULL, 0x09FB686DFEB19C3EULL, 0x0C2786C9C6E1AE3DULL, 
            0xCF9FE963F4DDB537ULL, 0x56BAFA02A989310FULL, 0x7569FDA7A8D04CFFULL, 0xB964B1A303688095ULL, 
            0x6AD28723AA815DEAULL, 0x85C1FEB374A49637ULL, 0xF930E7372E2A5E8CULL, 0xB7638009707C6040ULL, 
            0xCA2EFC0749CF726FULL, 0xFF0D518AD0EC6A35ULL, 0xCA9EF42613FF4B72ULL, 0xBB9E331FD560023BULL, 
            0x750A6124E6FD0422ULL, 0xB9F6A55B3EB0024FULL, 0x01A0705785470EFEULL, 0x43AD41DB977D85B7ULL, 
            0x64373E6837E46A39ULL, 0x84BEACD6DC830A69ULL, 0xCB793951E2C68467ULL, 0x3564A8CE75952A58ULL, 
            0x75F4B190FD9E42EDULL, 0xDD24DD3DF4E6A734ULL, 0xE3F1C9192B99EA7AULL, 0x1C5B4705ABB146B1ULL
        },
        {
            0x2FF6466F953C8530ULL, 0x049341E58B06F19FULL, 0x8284B01EDB7D5561ULL, 0x61AF2793B2575DF9ULL, 
            0xED8CC2785547A490ULL, 0x24CD03CF94DAA946ULL, 0x0B7909C0B4E58339ULL, 0x12FF83DFF213CB18ULL, 
            0x40F18B1C02FCE975ULL, 0x7C341C379294ECFBULL, 0x99024830ABA7C35BULL, 0x5C8BAB05681C8CB9ULL, 
            0x39F5FA1645EF9799ULL, 0xCDC004BA49D66C89ULL, 0x4A517CF45246D9FEULL, 0x71BD3205255F9744ULL, 
            0x634D13C49C4EF171ULL, 0xB10BCD7EE82915A7ULL, 0x3B1357122186A6A4ULL, 0x83CA7254120C7E8DULL, 
            0x9315FF0AC203A508ULL, 0x581007342FFDE182ULL, 0x51F01395E8D41554ULL, 0x7F046DC7693E8816ULL, 
            0x9120043420678C4FULL, 0x6D80AA6465439471ULL, 0x685D5299A1B98996ULL, 0x11B6788768C45653ULL, 
            0x92770DA19AB81022ULL, 0x2F8E02323E73F7FCULL, 0x0D213429D6FD5CBEULL, 0xFA44DE2519A2671FULL
        },
        {
            0xD05D251AB053CF33ULL, 0xF1D79957A4543BCEULL, 0x4CAE7101D6F08629ULL, 0xEF03235391049BD6ULL, 
            0x554E21FF0766A7A9ULL, 0xFA1D1E260974E467ULL, 0x806680C1371AE16CULL, 0x38BF7627E9E19AE4ULL, 
            0xF56EEC09E437EF90ULL, 0x8803B65C4D2F424AULL, 0xED6E62AF51D4B505ULL, 0xBD03F9A9A996E46DULL, 
            0xAD3B7C283A96ED30ULL, 0xFCDF3C08A675846CULL, 0xFD86D985E2B361EAULL, 0xD282B6C2EEB55BDBULL, 
            0x7240F6DED1C58065ULL, 0x95FFB31B95A406B2ULL, 0x23C34964CEC8F353ULL, 0x46344EB725ADC811ULL, 
            0x19E1423D660BBC49ULL, 0x7A1AB691C582C53BULL, 0x04BB617C9BC9DCA5ULL, 0x8A9EB9031A1BCCD7ULL, 
            0x7DBC49FAF32B95FDULL, 0x0F4EB5439AB1DB4EULL, 0x09BAC3E0CA96F9EEULL, 0xF7A05CDE9C2178F9ULL, 
            0x617285DC68B854A7ULL, 0x8E04D3554CAF3BDEULL, 0x048203107F332E87ULL, 0x0334C4026F4D8B6FULL
        },
        {
            0x38AC0C2FC91372E1ULL, 0x37BCDCA2581B82B1ULL, 0xF29010CE630E4076ULL, 0x01B8F8F3A5B160C5ULL, 
            0x410D4F9581147696ULL, 0xF5751E906D96FEEAULL, 0xB2894CC2506A55D6ULL, 0x83071715CD50D87CULL, 
            0xB70BB121D2978F4CULL, 0xB9649EAEB3A98D69ULL, 0x65E82D2F963401DDULL, 0x0357663C34A191D2ULL, 
            0xB31ED2394BA3532AULL, 0x3EFD1D6847BBFF09ULL, 0x386B6491ED54277FULL, 0x9290A5F786C4AB63ULL, 
            0xCEB7AB839A226ACCULL, 0x79E0F3E283C4186EULL, 0x6A14097063299907ULL, 0xBB150334B1416A79ULL, 
            0xD97A38187442C963ULL, 0x2A049D96B7B085D3ULL, 0x4EB3F40B8AACB295ULL, 0xD1803CD8CACDFBBBULL, 
            0x3C9AD3771AB01111ULL, 0x4872AE8D909AE122ULL, 0xCDF6FCA83E33D04FULL, 0xFE8AC61FBC151D65ULL, 
            0x4186904D40063845ULL, 0xC647019DEDA67D82ULL, 0x61D22AE7D98D8187ULL, 0x4661CDBCD6CF36CDULL
        },
        {
            0xAD8B04103DB742A2ULL, 0x6914C69DE4F13078ULL, 0x577E8820685C172BULL, 0x215271ACC1352D7FULL, 
            0x97B3A6D9DB5DB630ULL, 0x2DC89A34C5908DC3ULL, 0xA902160F1D119DC4ULL, 0xBEB5115490858BDCULL, 
            0x2749141A21728904ULL, 0x880E5114D281245BULL, 0x6A356F748F3B0903ULL, 0x0081744839FC12DFULL, 
            0x38C206A6C05A6389ULL, 0xFA52BE3BEEE0078CULL, 0x8C9763F3012B735AULL, 0xE2F240710033FA1DULL, 
            0x03B55F1911EEC0F8ULL, 0xFB698E9004E8D38CULL, 0x56C147BF6E36AA41ULL, 0x646395FDF787FB11ULL, 
            0xC6E39DECBB8B9CA9ULL, 0x2A3060EE1A237106ULL, 0xEAF20F8B3FDBFBD8ULL, 0x914091423F48935BULL, 
            0x833C15760B9B2E99ULL, 0x1F8D0FC541565A19ULL, 0xFD63BD1A51D428A6ULL, 0x151831F33697E954ULL, 
            0x2DDA3694068F7EF7ULL, 0xF6DA90C3CB2FB5A7ULL, 0x7A57651AD95C5451ULL, 0x694F947C29F7E6C0ULL
        },
        {
            0xEAA6C3AC7B5C77B6ULL, 0x0007CA8878E05366ULL, 0x30A568B60E592C8BULL, 0x7997AAF40BE39061ULL, 
            0x17E6E0BA24006234ULL, 0x1DDED9A4ADAE6F78ULL, 0x126C87C9FCD35725ULL, 0xCDF3E3FAE040DF12ULL, 
            0x4A94C83C010C911EULL, 0x41B194E00FE41751ULL, 0xF9B5EE99472E9E3FULL, 0x792AF12F4637CFD3ULL, 
            0x6DB939AE39F12A2EULL, 0xF81CDA8A6BDA6421ULL, 0xE6C2BBB9D8F8F3EAULL, 0xCE010248D1F96394ULL, 
            0x303B72C14653532AULL, 0x9BFA16B7A099C5FDULL, 0xEA8B7F1CDCEFC0A7ULL, 0x8C56A3FE1F2B858DULL, 
            0xC7FB468D74804016ULL, 0x134E0171E643BF27ULL, 0xF320F7C66D1265D5ULL, 0xBD562361AE949415ULL, 
            0x204A7CF5B0E7A643ULL, 0x60E4E67515B44B30ULL, 0x6F506BA3EDA68FD6ULL, 0xA2E83659BDE5945BULL, 
            0xA4D760FB4AF70530ULL, 0xACB4C2BC736971ABULL, 0x352DD12D7F9A19F1ULL, 0xA42D2D50186A0DF6ULL
        }
    },
    {
        {
            0x349B66AA2CE67CDDULL, 0x8C6AF9E9E487D9BCULL, 0x75AAD3A2A9DA53FCULL, 0xFA2A31B4AC995EEEULL, 
            0xC40C19B1FB5D859DULL, 0x2106F85BCA5BC634ULL, 0x3F9E4FE73FA6E05DULL, 0x30423C2153ADAEBEULL, 
            0x66369E95076C0AB0ULL, 0x6AD7160E372F4592ULL, 0xC842728724BBB649ULL, 0xE49C2D8D1C68650CULL, 
            0x09736E40EBD01EC8ULL, 0xCBE14D925DAB077EULL, 0x17644D78189F9C7BULL, 0x8409B1DDAD70CDEAULL, 
            0xA8E4BB387B03EC26ULL, 0xED634530C872C334ULL, 0xF15249E69DFDC441ULL, 0x1B6594635FC8769DULL, 
            0xA52084C2A22EBDBBULL, 0x07D6AC4D8F15B2D3ULL, 0x66D17D42436A4F79ULL, 0x2006749AC96996E5ULL, 
            0x19F5B6EB2790CC52ULL, 0x11696D2147C62DC7ULL, 0xC198E281D59310BFULL, 0x27A432B7BB0B5478ULL, 
            0x6B3626CB4AC52BD3ULL, 0xBC528AF80C1CA1CCULL, 0x3879BB5DA2604870ULL, 0x8A6FC036539D4A5FULL
        },
        {
            0xF0FF3DC32FC5A2AEULL, 0x507E1FD94149934AULL, 0x442263B6FF050F0FULL, 0x3A1E9929333E0166ULL, 
            0xC000DD490F7FA290ULL, 0xDBB3E2877655210AULL, 0x8117C86B8909E8E4ULL, 0xA10480FE120D652BULL, 
            0xC6161E679A78BAF9ULL, 0x388F2DD5041B4319ULL, 0x594B82E6DBF29717ULL, 0x67375CE6427358F0ULL, 
            0xD31274AE469EC06FULL, 0x0949513B2AC57AEFULL, 0xB11416B9F010FBBEULL, 0xB65106994324CAC0ULL, 
            0x5F6805E2A06FDC47ULL, 0x31FF149578C9F5ECULL, 0xF3E09BF8486FC95FULL, 0xB61A8DA2D41D5DA2ULL, 
            0x248834EACDC4F36AULL, 0x593CC88C928F815AULL, 0x0A7F753DB0E23193ULL, 0xA67B8843A7DFA310ULL, 
            0x50C5A96FBF266E3FULL, 0xA64546AAADA6AC4FULL, 0x5321DD739D14CF12ULL, 0xB0A2A2DBCA13280DULL, 
            0x6DE15F6713C031AEULL, 0xDCC678C8D3A85031ULL, 0xD753FA4DDD52381EULL, 0xC5EFDBA5AB559D7BULL
        },
        {
            0x054E53C5671E51F5ULL, 0xC697B5FAB6D380F0ULL, 0xA1CF4E36D227ABD2ULL, 0x26F8D64E01D506DCULL, 
            0x9425A5E8FE151273ULL, 0x1EF8238BB239B096ULL, 0x7F886FFED81326EDULL, 0x16F3F7932C2DC89AULL, 
            0xEADA352DA0FE778EULL, 0x6329F27B3BE9C115ULL, 0x484765041729BC9AULL, 0xFD1F7204503CE66AULL, 
            0xBEE9812F8E1B28ADULL, 0x99C1E2DCC1E3F640ULL, 0x6B282B3C65ED4F58ULL, 0x11370E007344130FULL, 
            0xD43D2819F3529604ULL, 0x0BD51696B22958E4ULL, 0x4562CE16EF69BBAAULL, 0xC28756D923ACD973ULL, 
            0x49C481595912A1BEULL, 0x85BA31895346971CULL, 0x55F1AFE3DAC8983BULL, 0x5D128191E55A5E43ULL, 
            0x8A578AA681F0A946ULL, 0xBB6168716C5A0EEFULL, 0xF5897D1B8FAA19CBULL, 0x311DEB4D8B7F9344ULL, 
            0xC9E698C9B8C4EAC0ULL, 0x2E491BF0C0850509ULL, 0x62CFA7E1620FA9F8ULL, 0x7BECF60677F46B6EULL
        },
        {
            0x32032905AD135A01ULL, 0xEEE11F979CC67C84ULL, 0xAC4C690A9503CCD9ULL, 0x9968AF4724A1893CULL, 
            0x17AD34318BDD27C2ULL, 0x98191C1C6B8035BAULL, 0xDC0C5CE079480516ULL, 0x0DFFFF0C90E7CF62ULL, 
            0x5003AE8310729BD6ULL, 0x0AD85C0BFE1EEC09ULL, 0x646B74167C65BF09ULL, 0x5F44B0F550E566F0ULL, 
            0x0BBFB7D4C30B06AEULL, 0x140D2867AD537FD3ULL, 0xE37E891338E9CF74ULL, 0xA5094B83A63115E3ULL, 
            0x3E2116D0D701ABAFULL, 0xD8B87E753FA0A217ULL, 0xC65AB33993EE7E63ULL, 0xC068B811E69FC10CULL, 
            0x3B46D5266A45FB24ULL, 0xFD587E32E78A28E3ULL, 0x53CE5CA50117CC7FULL, 0xA33582786976B469ULL, 
            0x630E3BCEEA56238DULL, 0x708BDD7109DF26C8ULL, 0x8127226DB06729C0ULL, 0xEB14AE2E82E1E05FULL, 
            0xA80AA38A8CBD56B8ULL, 0xC1579BE571F807FDULL, 0xD8B54D40840F448BULL, 0x2B772279053EB15BULL
        },
        {
            0x47774FA37CDC8703ULL, 0x8AFF765AA2F2C3E5ULL, 0xC96449D4D3707321ULL, 0x358DCF936A83C428ULL, 
            0x172BAF0A1DC1E9FBULL, 0x34E2555520B6AC3CULL, 0x7A4331E2B19F00C0ULL, 0x79F12903FB68323AULL, 
            0x1D562524F816C60FULL, 0x481CF59EEA333D17ULL, 0x67DC8C2FE4A5F830ULL, 0xBA89B539CB4F8229ULL, 
            0x6A7381D722B1A709ULL, 0x06BECEC30EBAAF45ULL, 0x18A358367E6A52DCULL, 0x0D3C0082E93398C1ULL, 
            0xAD95E074F782670CULL, 0x6EA92B90847288BCULL, 0x225D786A26FC40C7ULL, 0x3F965D1790592A59ULL, 
            0xC93BCD343DBBD169ULL, 0xA8F799F02BA1E761ULL, 0xF029B9333B27F79FULL, 0x128977E3BEA0DCAAULL, 
            0x720BA0524CD5F029ULL, 0xC1D6AED512D20264ULL, 0x749373DD99284601ULL, 0xF132B82673B27A59ULL, 
            0x62693765B22C2DC9ULL, 0x25C0C6D9F3D66CDEULL, 0x3DA22D4BD0FD29E2ULL, 0x66FAF1F029D5EBD5ULL
        },
        {
            0x6AFCEAD4081D5474ULL, 0x99547D396AD98127ULL, 0x8010477D24CDA193ULL, 0xA2EA89C49AA9D9FEULL, 
            0x4D72B5F69752486BULL, 0x1DFC9DECD61C65BBULL, 0xA6C1CC362AEEEB2BULL, 0x91F1DEB012B113F2ULL, 
            0x420DEF1751017B73ULL, 0x20BF7794B0E2131DULL, 0x584B1E17410D8FECULL, 0xF8A0CC38445203CFULL, 
            0xFF939764EB6AD6EAULL, 0xB223C51014A49CA1ULL, 0x17D5971194B6B057ULL, 0xEE08100F3A26FDA4ULL, 
            0xF407EA7594A9CF44ULL, 0xA6C44ECFB4E0795AULL, 0x9CF47A72EFFF0C36ULL, 0xD21AC776E7E298C1ULL, 
            0x329290A1F0A1315DULL, 0xA50FB7FE313F6C9FULL, 0x30F7749BBF853D79ULL, 0x4742619AA613019CULL, 
            0x01D0186A5359529EULL, 0x4FBD5FA148D76B75ULL, 0x2EC6557F2A07351AULL, 0x870BA3C068E8A85CULL, 
            0x8B5AE70E6B509C54ULL, 0xB8390C483CD85B52ULL, 0x911DA0506AC608EFULL, 0x004850C6C9882FA2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeySpawnConstants = {
    0x3ECFE2C130D58066ULL,
    0x5C4FE52114930BE0ULL,
    0x4AADECFF7728D361ULL,
    0x3ECFE2C130D58066ULL,
    0x5C4FE52114930BE0ULL,
    0x4AADECFF7728D361ULL,
    0x597499B462AC7C6FULL,
    0xF2C94095B225967EULL,
    0xC5,
    0xD4,
    0x9F,
    0xAB,
    0x45,
    0x78,
    0x52,
    0x42
};

const TwistDomainSaltSet TwistExpander_Achernar::kSeedSalts = {
    {
        {
            0x6F58AEBEC8B4A563ULL, 0xC9A31470CAB691C1ULL, 0x09C5312E39576EE6ULL, 0x79C56A149E0895F5ULL, 
            0x6FE1E470870DC2E8ULL, 0xF8FC6D0B891A9B19ULL, 0x807EE4B0A31B7FB5ULL, 0x2D281ECCCC042088ULL, 
            0x760EA93795779C54ULL, 0x147975FC89F41C8EULL, 0x8CE0B4B869A9A88CULL, 0x0BA370B75CC4F782ULL, 
            0x0D945CF75F98ED61ULL, 0x17362C61F01533BBULL, 0x948A7E4539BC88CCULL, 0xCB826A1CF802BFCDULL, 
            0x05E7E07C44DBCFD3ULL, 0x3403E3D4E1289DC7ULL, 0xB556355F7FFE23ADULL, 0x15FA4F0278BC1939ULL, 
            0x6DE9A33DAB0C802CULL, 0xA210FC90EFF3CA65ULL, 0xFB89A24E5BDF9D8AULL, 0x40BB4C12A4E9CC83ULL, 
            0x8E0465FA71C7ED69ULL, 0x2A4D9FB3C14EE6D4ULL, 0x35AB23FB5C00D586ULL, 0xA8368113A662551CULL, 
            0xDD34FC75E5FB96B2ULL, 0xE26BFF25D8137A16ULL, 0x0DFE8F78D1CAA452ULL, 0x69B9A8902F1CD167ULL
        },
        {
            0x840A3D3E2ADD6577ULL, 0x8C774CDF40760207ULL, 0x5BF4C0D3F3485A06ULL, 0xF1643A4A20BA392FULL, 
            0x8C1952F9FD3AF996ULL, 0x331DEE189D3B0F93ULL, 0xF2F12AD2911F2C95ULL, 0xCBA4199C160F50C7ULL, 
            0x794C5615B3E9C39EULL, 0xDA7AF57ED790C61AULL, 0xA82CD31D92C44CA9ULL, 0xCC97896B9D590999ULL, 
            0x276A63D542AEA74AULL, 0x3528435DC4673F80ULL, 0x2B4F52445AE7F86BULL, 0xE70AA443D87B1A56ULL, 
            0xA85D1D7B751C631FULL, 0x1444B26974070CEEULL, 0x05E60A3D1DA9A4ACULL, 0xFA3CD967BFB77DA4ULL, 
            0x5CC17A46E3813AB6ULL, 0xEFE2691A25A4B177ULL, 0xE8C094EB16D7B849ULL, 0xB2DF4E43A38850B9ULL, 
            0x5AFB7D279AD7305DULL, 0x6E930E7C0090BE15ULL, 0x53387CDB355CAE16ULL, 0xE440F41A324BF40AULL, 
            0xAB10F1E2918E4A1EULL, 0xBD3558968AF32A2AULL, 0xCA7EF43AC18E5401ULL, 0xB9219C59846116F1ULL
        },
        {
            0xC7A56564547510A8ULL, 0x209A683071A868F0ULL, 0x88AC029BB54BD236ULL, 0xAE0A01EBC9418869ULL, 
            0xFA373436CA29CF4CULL, 0x9ED1E0F7AE48C4CEULL, 0x9C49A096711EF07EULL, 0x720C874021EA424EULL, 
            0xFCA18DBD890EC37EULL, 0x0EC3C2976FDA231AULL, 0xD79414542C639E59ULL, 0x00AE3061AC1F412AULL, 
            0xA1E7C55E5A4AF0E7ULL, 0x0B2F2E4134DC61EAULL, 0xE489C0AA72A43EA2ULL, 0x6F6F6D70B594DB69ULL, 
            0xE85B36CF54E7F019ULL, 0xEB0CE553E8B1D319ULL, 0x3ADAC4738664C29FULL, 0x29F2C73C7C5F03D2ULL, 
            0x8D473DE699A30082ULL, 0x5C703F03C4098523ULL, 0xE33B47E879B2ECACULL, 0x100DCDAE345B42D3ULL, 
            0x0AC06FE3A906E290ULL, 0x5415CCB733C392F9ULL, 0x62348401E5CD565CULL, 0xE8569F264DBE4DD9ULL, 
            0x027F1E4E9CC1E880ULL, 0x99403044F6B05ADAULL, 0x3B56A70387FB6708ULL, 0x3577321F757CCD7EULL
        },
        {
            0x4AE993B5F55BFC23ULL, 0xA1040E0C8E802B23ULL, 0x69A460434068B19AULL, 0xDA2239DAD9948207ULL, 
            0x5B9A3707F77E4D91ULL, 0x8AB467547E66970DULL, 0xC188FA61F5FD9F67ULL, 0x9A71A108DB9940F5ULL, 
            0x8217F76A9ED33938ULL, 0x4BADFB4DEE0C9C22ULL, 0x89CA40C62C50FC6CULL, 0x072BE8F4A42DCDDBULL, 
            0x9865DFFA3B711EF1ULL, 0x86D3338EC5B0C81CULL, 0xF7756F16B5D1B192ULL, 0x9358EC74B1D29346ULL, 
            0xDBD4FDD9AFBA3EF9ULL, 0x7BC034DD58FC2AB2ULL, 0x75537F7DBB98A1C3ULL, 0x55A7F6F0A51470B3ULL, 
            0x3888BD3592C1A0A2ULL, 0xA80779F0690946FCULL, 0x62BB23F7EC1F1F1BULL, 0xA8DEC96F4ADB5F56ULL, 
            0x70B5894A975049BEULL, 0xF6521F9388F17978ULL, 0xD3990852147C75BDULL, 0x7C5CB19E58F59180ULL, 
            0xBDEC60EC974C845DULL, 0x14129CCAB30319C0ULL, 0x14173857EE7887DAULL, 0x511B67D91155F804ULL
        },
        {
            0x9FCC4C8A294B7546ULL, 0x6EE535EB4BEACE13ULL, 0x30C972A74D5D5203ULL, 0xE6156A9F53C7662DULL, 
            0xD2C2209E1DA0FE11ULL, 0x4BE5704588F73A1AULL, 0x108EBCB0C3BECA7EULL, 0xF70C46F8081A3D7DULL, 
            0xA835A44183CC10A7ULL, 0x7DFCC43338ED2C0DULL, 0x5B945B58B3EE44E4ULL, 0xBEEE2F79F26B901BULL, 
            0x18C46A4433B4213DULL, 0xD55061E4BCBC3A7BULL, 0x1854B47E0F1508C1ULL, 0x6F6A832BB498855CULL, 
            0x5909E970A4671083ULL, 0x60AA65A74FAE1850ULL, 0xC63BEE2B48703F0DULL, 0xB9C8856F0B26369BULL, 
            0xE79A891046F25ACDULL, 0xFA8EF810E69E7E78ULL, 0x5740D41327D5AD8DULL, 0x6F59623B05AA6504ULL, 
            0x9F2AAFC4023702BFULL, 0x526151CFCFA40F77ULL, 0xA941A052009439B8ULL, 0x46067DB12491192BULL, 
            0x03ED7E4AF65CB472ULL, 0xAB0BC9568FAF23C2ULL, 0x777B60CF3F3E435EULL, 0x639BFC0908303593ULL
        },
        {
            0xF50B0181ADDFE0D1ULL, 0x690A47374E20178CULL, 0x5066E0D5824CDF07ULL, 0xD97E7C97A48D1ACEULL, 
            0x3CDBA2AA8B39C862ULL, 0x2D7A8AD95181FD73ULL, 0x6657299487AD8460ULL, 0xC6FBD90F0DA6823DULL, 
            0x55611A810370D9FEULL, 0x0C7DDC943737DD99ULL, 0x873C348965B68CFDULL, 0xAACCDCF58397C68DULL, 
            0x89FC5E89F34DEDBAULL, 0x3259725E9FEF667BULL, 0xBB5DE5FD57AB0043ULL, 0x8890524CF8E29E34ULL, 
            0x2BBB1A334C4E7F9AULL, 0xBE6C0D6719615011ULL, 0x0DC7A522E75557EEULL, 0xA8265021440005EBULL, 
            0xF8329E109570166DULL, 0xFA3270290534345FULL, 0xC4FF021902E941B1ULL, 0xDA5015B8F17DEE72ULL, 
            0xFE9FD481A406CDB3ULL, 0xBB2E9F6BB076A318ULL, 0xB55BBADDFF9425C4ULL, 0xCBF3AFE2772015EDULL, 
            0x9DF55BD7326D04B6ULL, 0xF2D421D68AF617B3ULL, 0x7957A12FA1292EB6ULL, 0x98EEC8C1820EA496ULL
        }
    },
    {
        {
            0x302B519128BF30A5ULL, 0xA66F6BF59A464180ULL, 0x960248A48BD1A6A7ULL, 0xDEB244114AE7A53BULL, 
            0x03896253D0B9DDE4ULL, 0x210C339C03FDB1C4ULL, 0xEB632DBF13C552A3ULL, 0xCEC8A47570149253ULL, 
            0x4A2ACCC2E7C398C4ULL, 0x205C1EF2933226B5ULL, 0x6F4A98968D759070ULL, 0xC070FFEEE7464F11ULL, 
            0x9197C3E0C6E36D99ULL, 0x1179BE2629C9B061ULL, 0x48D00F2EB0AAF15BULL, 0x1A41951432860B5DULL, 
            0xDAFBCCAC0BDD71AAULL, 0x1C6115F1611EF2D5ULL, 0xF7DEB2493EC5A099ULL, 0xD307C1BD605B26C6ULL, 
            0x100CE98682739741ULL, 0xC8DE50DC5CA83676ULL, 0xAA36060172F88CBAULL, 0xB1AD50148B09F764ULL, 
            0xCEA67453F064E9A0ULL, 0x8F5100C14FD1C20DULL, 0x41EAEA27CC9AFDA2ULL, 0x56F788987B78A10FULL, 
            0x8AB89D37F1319E02ULL, 0xCFEDE88D96350DBDULL, 0x493587B7C1C8ECC5ULL, 0xAFBA0565081DE784ULL
        },
        {
            0x8DA04851E0536404ULL, 0xA9BFD19F4CAF00F7ULL, 0xC9972641561B3DA3ULL, 0xD75044D8450DF281ULL, 
            0x8C316EFED6999A58ULL, 0xA6070DDCF9B15C2CULL, 0x52E557AE1B3AEA62ULL, 0xB29BABCE0BEA0183ULL, 
            0xEA45556235B3D246ULL, 0x0C456D432B86D421ULL, 0x193A90D51900FD8FULL, 0x01F52AAF12B427C4ULL, 
            0x08317CAB35B8F6A1ULL, 0x5BDC7E0054AB8AB3ULL, 0x540EABA86620B2A7ULL, 0x63D0F1B62A94F1BBULL, 
            0xA951D024DBB4172AULL, 0x47CF6A197184185DULL, 0x3CC23941767F182BULL, 0x2364509FF33168D2ULL, 
            0x3316B6B102E678FAULL, 0x62386E23833F5972ULL, 0x597B63010FEF8807ULL, 0xD1FBBD3E6AB67350ULL, 
            0x8E76885E8FABC7BCULL, 0xDBCB0454F0A7F13EULL, 0xBA740566FB8C2C57ULL, 0x53300D55A864E1B9ULL, 
            0x9123F065F225CB09ULL, 0xBFD043306DEAC749ULL, 0xBBFF4D4AE046D905ULL, 0xAFF7C92C8AD7F456ULL
        },
        {
            0xD6C1901FEB6B51A8ULL, 0xB0EFE17E7B2F3226ULL, 0x2F084DD2E6987915ULL, 0x5A4FE7B292A9F4D6ULL, 
            0x59A4FAEC1B50B636ULL, 0x55999C2EEA0330D9ULL, 0x056FD7EE8AAA5BF8ULL, 0x5D59CA854B67290EULL, 
            0xB95A236BFBBFF71BULL, 0x48D3A2572B8B8B34ULL, 0xE7F5BC7DB5DA98C4ULL, 0xF0E487E13A60BCAAULL, 
            0xF073241021E3ACBFULL, 0xA815FDBD7BC74C28ULL, 0x3DC9FE96A1606924ULL, 0xD9D71878AF6EAB59ULL, 
            0x7FFD34B4D1D9B21BULL, 0x64844E1DC880A3BEULL, 0x3A848F2B2D2E263FULL, 0x389536986897DF07ULL, 
            0xB22399512295CDCFULL, 0x3595C5D0471BA936ULL, 0xBDDF1E5D795CF134ULL, 0x5CDC6D57DDDC7D7EULL, 
            0xED5AF7C847AB5235ULL, 0x966A873BD194D23DULL, 0x1ECB27412CEBC739ULL, 0x287D576778E4E27AULL, 
            0x5228C586ED6846A4ULL, 0x0E66ACD0B637BC67ULL, 0x0A10626E2ABD1584ULL, 0xDABF5D247FF73ACCULL
        },
        {
            0x7E05AA9E14F7D2EEULL, 0xAA0D65827B7BF827ULL, 0x502645623B25FA37ULL, 0x518B5D4F127AFE66ULL, 
            0xFF79D5CEB51D24F6ULL, 0x06BA600DCDE19E30ULL, 0x8FAA1D44802C57E9ULL, 0xFB9906D2633AF74CULL, 
            0xE1D9013AE76E87D8ULL, 0x062AEA6017418D9DULL, 0x26FF3B86051A167EULL, 0x839571FAE6C09500ULL, 
            0x2EA96E704D391073ULL, 0x966D9FB3CE9875A1ULL, 0xC921CDB244A385C2ULL, 0x8FDFA7FAB0CA8ECEULL, 
            0xC31D2805663CF5EEULL, 0x9AE48F385D43A862ULL, 0x3A051A73BC5B09A0ULL, 0x09D3FAD02BE0D229ULL, 
            0x2109C277BE79D189ULL, 0xC3A19F1A027DFD91ULL, 0xC83607C09261F41CULL, 0x877ABDDDA7DC0AEEULL, 
            0x681E4051A57B002EULL, 0x70214766D04AB3D6ULL, 0x100CF579CE79E866ULL, 0xFB5B81099E3EA79BULL, 
            0xC2B56188707439B0ULL, 0x983DBA742A54A668ULL, 0x1684982968C5B6C5ULL, 0xE6F91218AF85CA43ULL
        },
        {
            0xF537D28280BDAF77ULL, 0x25580395C4BF0976ULL, 0x8F38B7D352FED8A0ULL, 0xB73B31CF84BFF7B6ULL, 
            0xB89B27EBD526C6FFULL, 0xEB3EE95D26188C8AULL, 0xB23C4F308932C025ULL, 0x2EC7909D80DB1598ULL, 
            0x0AEF1E28152EE0CCULL, 0x7902C5450D8AEDF1ULL, 0x5C90184D8F01ACE7ULL, 0xB55730FB0BF1ABADULL, 
            0xD5B2220FB2533395ULL, 0xF8D45667E25F3186ULL, 0xEA4438E6C287FB9FULL, 0x25A5887EBCD6427AULL, 
            0x1DA9E12D26D9902EULL, 0x3F359884BF742A7DULL, 0x241C6873065DF8CEULL, 0xE3FB41D7FCDF2AF0ULL, 
            0xA4BA6BA653095423ULL, 0x5B35A069950CA2D0ULL, 0x4A767E790C3A9598ULL, 0x9138C3EA56D37936ULL, 
            0x7ECE627BE553618EULL, 0x930368DFEF00C3B7ULL, 0xDA37FD92E3BF4182ULL, 0xE4C59F593357ED1AULL, 
            0x6618454740F2560CULL, 0x902B99E9671564A5ULL, 0x4DFA650A8C08A8CFULL, 0xAD689A6BC7D85A6EULL
        },
        {
            0x0A67F7F581F0D307ULL, 0x870F530F42B3B190ULL, 0x6AE52E50C6BA9778ULL, 0x9032875B1A73171FULL, 
            0x00D6A13C16222934ULL, 0x578C9E1AC8E6B43AULL, 0xE008807175804A46ULL, 0x5A1E330FC19BC610ULL, 
            0x1BC78A1440DA7550ULL, 0x40157CE38D3E3E9BULL, 0x4CCE314BC66F033EULL, 0x2DF764D69E216CBFULL, 
            0xEBA2FAAFFE4F3A0CULL, 0x0DEE8A4A886059F5ULL, 0x92899D32839D29A6ULL, 0x584E69D0395BCABCULL, 
            0xEB5128B544BE6633ULL, 0xF5DAC43AEBE7A090ULL, 0x42625A788024385BULL, 0x12E6CCA2D4801B1BULL, 
            0xAED86F553A2B9B01ULL, 0xEFDBD840A95054B9ULL, 0xAD3A094ACDBBCC30ULL, 0xFE004D372D938970ULL, 
            0x4BE7FF049CABEE82ULL, 0xA656B74A91636486ULL, 0x1267C8A9136E07FCULL, 0x5EE6D529AB497F8DULL, 
            0xC2B52A347AFF97F4ULL, 0xB819965A71DCAAA0ULL, 0x3D054EB63213046CULL, 0x60D4CB63A092442DULL
        }
    },
    {
        {
            0xE203CA8793AE6857ULL, 0xBCF9CDF38EBDD647ULL, 0xF035AE4E24F6127BULL, 0x40EB93B7F2B165E4ULL, 
            0xEF2D97D929B9CFB5ULL, 0xA6B91C3C453F0585ULL, 0x6967160019B73342ULL, 0x5D8BEF22972422E5ULL, 
            0xCE6332DB0AA3005AULL, 0xDC5CEE16D68BBF5BULL, 0xBB682C4B172916E1ULL, 0x5BCCCF613DFF8FD7ULL, 
            0x4C250A2831738953ULL, 0xE7E3F9708AD4BE66ULL, 0x71FC60E903DA22F8ULL, 0xE5644EA3E8200C2FULL, 
            0xA572CA00A6ACBA49ULL, 0x059CB305559B7EA2ULL, 0x407D37ADF0B388DEULL, 0x222499BD8AF8EB15ULL, 
            0xFEF644650AC390A9ULL, 0x14C881AC67733989ULL, 0x1B470B4984F76E96ULL, 0xDF3365D5AA05FA76ULL, 
            0x82BA615B45E5E0D4ULL, 0x74A8DB6A9E9990F3ULL, 0x28BFFBC9FA648777ULL, 0xF5F96D53C5B4554EULL, 
            0x3BEB2E0FC37DFC67ULL, 0x85851234D8A7EB78ULL, 0x50BAFA7B85E5B069ULL, 0xD92CBA00F1CAAF2AULL
        },
        {
            0x9C08B60FC4F1D091ULL, 0xD8B3D866D2C9893DULL, 0x794D170C2DD62387ULL, 0x74B3CA3A6A1A39ECULL, 
            0x172F9A6097E39192ULL, 0x90C125776E8B009BULL, 0x0B08BD13BCD34F1FULL, 0xB7B7DC364B9D79B4ULL, 
            0xB7A5D5A84263D821ULL, 0x7C421E95656B277CULL, 0x448F497C8ECD17E0ULL, 0x7256B18C09EA5979ULL, 
            0xD24C433E00B8A960ULL, 0xA990ABF967E99134ULL, 0xCE467F77F36653ABULL, 0xE6FC401BAA1B8D66ULL, 
            0xF0D60551DACA4A72ULL, 0x2A8B90FB7062CEB9ULL, 0xA2A7B8985A28D0FAULL, 0xD337FE8095E393B9ULL, 
            0xBE9D0542B132A64FULL, 0xE5AF7C580B788183ULL, 0x367CD4420F502EF1ULL, 0xEC5E3CC99BDE1901ULL, 
            0x5917F99C313696C4ULL, 0x7AFBFAA7715CCFCFULL, 0x3DCECEABAD993A66ULL, 0xE40B8A1748C74B12ULL, 
            0x1AC0324E4B166953ULL, 0xFA18B30AF91F368EULL, 0x6350EAA5F19A389FULL, 0x72472B719A288DBBULL
        },
        {
            0x0457C134AAB5EEF3ULL, 0xAC578498E1FDAAA3ULL, 0x78C612044BE6482CULL, 0x4DBB5BC7C4BFFF88ULL, 
            0x5CBBA8ED4BD1F140ULL, 0x5565E26F9EE5238FULL, 0xD7550A7EBC99A1F1ULL, 0xA05A3A40A7F76A8AULL, 
            0x112DA2F1549444A2ULL, 0xC481297FA4E912FEULL, 0x1E291869AE42F9B3ULL, 0xEDDE8EBE0AC52580ULL, 
            0x14B34AB9BB3DED9FULL, 0x601E342EA675839FULL, 0x40AEA6B9B69633E9ULL, 0x30684F1F120A183AULL, 
            0xB928F0315008001CULL, 0x3F9C631EC283ED04ULL, 0xBEEF5D8D19CF87B9ULL, 0xFCD39CEDC9FF3323ULL, 
            0x8DEDEB46443EA741ULL, 0xBDC25CF1C02135D0ULL, 0x57287A8B2F6B5FFCULL, 0x6FBF515FACA895F1ULL, 
            0x3D7B5933DD9EECF4ULL, 0xEA98FAA0E989F61AULL, 0x46B9E6B746C88D69ULL, 0x6E50DC363CB400B9ULL, 
            0xE7761B2B63611EAEULL, 0x2E98CB903F1534FFULL, 0xAA87C0EB5622F056ULL, 0xD7106F72BB0F596DULL
        },
        {
            0x661845EE63994AADULL, 0x379738DD93169E7BULL, 0xFB114A5573FEF36BULL, 0x7221CF2146090C0EULL, 
            0xFF82E4BB9AA10759ULL, 0x6F5507A6CA75DB9CULL, 0x5DB02F11F7C1452DULL, 0x15F8423724D4EF90ULL, 
            0x3BE90C3F02DFD43DULL, 0xE268206A96699952ULL, 0xF190737884254A29ULL, 0x4232170C1140D5A4ULL, 
            0x1CA0E242BCFBB732ULL, 0xC734EC52F31E6EF5ULL, 0x6D7650E2E558A36CULL, 0xED4AE0BA75F0CF9BULL, 
            0x8D757BFE22D77A22ULL, 0x5AD3741D6B5B2F03ULL, 0xA4F722A8A89E7A2FULL, 0x049CE2013F45768AULL, 
            0x46DAD94EEADBE189ULL, 0xCE17ACD15287D7D4ULL, 0x6839CE5DA1354056ULL, 0x42D9579228CE4D84ULL, 
            0xFCC500CCD952857EULL, 0xD8C895EDD381FE25ULL, 0xEC3F4772123CBAA1ULL, 0x87A4FDBB7CA98494ULL, 
            0x3E955B21DAFA5D0CULL, 0xA4BB2BB204EC4455ULL, 0x03761E9F3EBDA206ULL, 0x3021043F61E4C737ULL
        },
        {
            0x982BBC71BF7AAA01ULL, 0x3DDF0DFDD0DF9019ULL, 0x85F17C9936765073ULL, 0x8338FF15AC5EE6EFULL, 
            0xA08A08ABF0DFE3CAULL, 0x6A8D6B4D61D1C111ULL, 0x7031DA0E6ED5AA7AULL, 0x21C3FDA350C77AD0ULL, 
            0x593514EA345A32B9ULL, 0x20968ADE88515759ULL, 0x96FCB1F1E918AC4EULL, 0x1504E9505C692387ULL, 
            0xD9910FC4CBD4E9B7ULL, 0x47799B3BC5344D78ULL, 0x0FDA1B271759D4F5ULL, 0x90F7EAE42435AA64ULL, 
            0x3D8FBC847711E5A6ULL, 0xAB9A14C51460F788ULL, 0x59755AE5E2CB8D3DULL, 0xABB1AFF758EBEC0DULL, 
            0xE774FA02C239C963ULL, 0x93B884B7996D1607ULL, 0xCAE88350D5F0176EULL, 0x60B1A6075B50D92DULL, 
            0x3AD08889081238AFULL, 0x15E621E6BE0AC45DULL, 0x2232E000B68C346BULL, 0x29AE0E2F1EED399DULL, 
            0x49D604CE4011D0D3ULL, 0x98A59DF471321B40ULL, 0x2A3FABED52E07B5DULL, 0xA5900F2113425AB8ULL
        },
        {
            0xCFECD0FC2CE90F1EULL, 0xEC0600C791F01405ULL, 0xC123F903AB0E5167ULL, 0xD2DA41593DB928A6ULL, 
            0x8603589661043216ULL, 0x5777D691F6FFCD79ULL, 0xEA4EE3DD09859B9CULL, 0x83756409BC0DC218ULL, 
            0x077D2E0F4C591D7AULL, 0x475CC58E48B99597ULL, 0x42B628CE522516E0ULL, 0xF7188898A27A97D8ULL, 
            0x216A970A9865EB9DULL, 0x41062D537E2CC359ULL, 0x9502101E992B574CULL, 0x98081803C360B376ULL, 
            0x143785D14D07246BULL, 0x19A45CDCFD4B1AF2ULL, 0xBAE1FD7F6A362774ULL, 0x69FBA2C29AAE8AE0ULL, 
            0x98037E484B4BF7B4ULL, 0xADE87B8B60E7C4CFULL, 0xC6EB855B92BF82C6ULL, 0x5D2B49C4346960B0ULL, 
            0xDA698BD29AE686A4ULL, 0x57E5EE75D7C9E7F1ULL, 0xB4255D928F599F89ULL, 0x765A91EC4BF36F55ULL, 
            0x29A9E238BB21C051ULL, 0xBD9843AF6049EFF3ULL, 0x6F194197A677CBB7ULL, 0x46B564A33B440CF5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kSeedConstants = {
    0x4268FB8E725A708BULL,
    0x8DDE84760EF7F788ULL,
    0x5321260DA031AE76ULL,
    0x4268FB8E725A708BULL,
    0x8DDE84760EF7F788ULL,
    0x5321260DA031AE76ULL,
    0xB9654FAFCC9C0477ULL,
    0x0A19522BE7595CB6ULL,
    0xEB,
    0x63,
    0x7D,
    0xC7,
    0xD2,
    0xAC,
    0x71,
    0xCF
};

const TwistDomainSaltSet TwistExpander_Achernar::kTwistSalts = {
    {
        {
            0x1C9F7E1908E7D397ULL, 0x88E203B59CDF6219ULL, 0x5B0A6C79E49032A1ULL, 0x15FF590C395D9E57ULL, 
            0x1B564F76B3F2D8BCULL, 0xDAB59F2B21021A15ULL, 0x97D4B0F55EFF2658ULL, 0x311E67F9DA4A848FULL, 
            0x49621445DD6C373CULL, 0xBF75A3F9C75E5CAFULL, 0xD131F38246C1A207ULL, 0xE4FFBDDBDB8F2E3AULL, 
            0x6A3FB31E060C49C1ULL, 0xF84A7515094B8CE8ULL, 0xAD3B37FC6C6FE779ULL, 0xBA6E2225A44EAFDFULL, 
            0x1FA7FE6CBB197C45ULL, 0x5DDACB8794D9C51CULL, 0xD6C78EAC7DC14897ULL, 0x18D1BA603B84B27DULL, 
            0xC162FC5CD178F31DULL, 0x58BB923C818C0722ULL, 0x6F5A2C24063E7AAFULL, 0x7FC1011CB04B3D96ULL, 
            0xB716B6686C87239CULL, 0x8C34DAA561D649FEULL, 0xBBCC4D9221515760ULL, 0x006774E187025778ULL, 
            0xEC312DC321055FD9ULL, 0x18B936375B49B405ULL, 0xED812C3C9D4E53A7ULL, 0x3F4F2DD5CB37D834ULL
        },
        {
            0x98044C2918D54BEFULL, 0x28E90B6F551EFC15ULL, 0x1B6643557D9C6DA4ULL, 0x9AB06539113369DEULL, 
            0xC0BD59B87889F858ULL, 0x61D72E97C2304D2DULL, 0x3BD69219F8C12403ULL, 0x7601EBE7523D4A36ULL, 
            0x344CFB16EDC8217AULL, 0xFECAE07920289E9CULL, 0x031C90450A0B4EADULL, 0xA5B522AB44FCCEBAULL, 
            0x19CEFCC094E383F8ULL, 0xAA961D00E36DFBBDULL, 0x21B3AE3BBC4D703AULL, 0x4F427B3FDD3050DBULL, 
            0x60A47783DFA0A912ULL, 0xBE1AA3A77B01FD3AULL, 0xBF126B75E9D48A15ULL, 0x26391F74DBD64697ULL, 
            0x2BEDC16C6E7B3099ULL, 0x1C4EBE46265ED0D9ULL, 0x439E5D349450FC93ULL, 0x5E74ECD4D83FBDB9ULL, 
            0x17E2F2FC897B1E0BULL, 0x4920868C2C74BDCEULL, 0xA2D1C99661F135EAULL, 0xC71EC1B09F1C301AULL, 
            0x274EE6A3FB7FCF6EULL, 0x4949D90A2A48A209ULL, 0xABA67AF59791FF6CULL, 0x1486E95ED7DABEECULL
        },
        {
            0xDD2401E9258A5D79ULL, 0x76F67666E769AF49ULL, 0x0DC0119C111D14ADULL, 0x7E82D228A5D52C0CULL, 
            0x70870E65FB463F0DULL, 0xB4790016F1D38048ULL, 0x43E7E1779F8EC25FULL, 0x2220FB1BC6F74373ULL, 
            0xF4DD9E1FDFB9674FULL, 0x60BED8C3F48F34FEULL, 0xBD8BEBADAEA99BF4ULL, 0x6FD9AB567BCB041FULL, 
            0xC7CBD118EF7AD673ULL, 0xCCA7B2881AB88299ULL, 0x2998EBAC884899BDULL, 0x3599BE54E799308DULL, 
            0xE4E87FD50F5CF4EFULL, 0x6D379EE0EDEC93F8ULL, 0x77F53E896C8D7048ULL, 0x2494D9406D8F5D05ULL, 
            0xFDF9DEF4848EBC99ULL, 0xF37151B3080E924EULL, 0xAD1EF67AB2AE5039ULL, 0x22E9AC2DB89999E8ULL, 
            0xC456BCD2BB30E517ULL, 0xD2B5F3994C42D860ULL, 0x425876BC6E8A2175ULL, 0x2694FE818655DE3CULL, 
            0xBF9C0B4C2F351ADFULL, 0x2871CFAF78A74FFEULL, 0x472B898EFC0F8926ULL, 0xEF06AA83F8EF2C0AULL
        },
        {
            0xB04913767A0407AEULL, 0x563C2BDBD705F60CULL, 0x40E1A62D4B4F9981ULL, 0x3E4421EFFC1FDF7AULL, 
            0x8331F6632DB6FA79ULL, 0x74357E31896DE0ABULL, 0x40F4F063858201CFULL, 0x427377155343039FULL, 
            0x50D085B7BA40F3E9ULL, 0xE2343FA230FB74D8ULL, 0xEB999A74D1288B23ULL, 0x5B1509023627FB34ULL, 
            0x7C822B99311A2E67ULL, 0x7B25937222788289ULL, 0x5EBA4CA203BE82B0ULL, 0xBC64D7F9008686A0ULL, 
            0xCACA2B432E35E8B6ULL, 0x1B1C50EE9B582574ULL, 0xA426D28126311338ULL, 0x9453AD4D55E78E5DULL, 
            0x6F0AA83CECA0B6DBULL, 0xF4107C3052B8CB1BULL, 0x232534A02624D023ULL, 0x427B55BA032E1329ULL, 
            0x5945CAD5DF40F232ULL, 0x7690F60E1A45CE89ULL, 0xD3BBD871C2E183F4ULL, 0x5A1CE02EEC7FA7ECULL, 
            0x3CDA6B407C144BE6ULL, 0xF60549566C06F349ULL, 0x23449B6147CBAC7BULL, 0x519096E64A0F4A29ULL
        },
        {
            0x1F8E99AA36C6F359ULL, 0xC2A74C8A7BC0BEA2ULL, 0x4E9B4458BF1A7D9DULL, 0xDF14B6C47BBE70BEULL, 
            0x946DAD0A5352B92AULL, 0x0C81B84F9D8DD7C2ULL, 0x91011D3ACD1E98AEULL, 0xC74BF86AD9322F48ULL, 
            0xB956C447FBEE83BDULL, 0x651E64063E3480C6ULL, 0xC9F5369AD7B0E7E0ULL, 0x82BE2A5AAC4E6328ULL, 
            0x8784DCF075CE5285ULL, 0x8497401790784F72ULL, 0x15CA114FB28C73CCULL, 0x6AA4751996CE7EB4ULL, 
            0xAE988E4CE51C5B92ULL, 0x47F0297C10349D84ULL, 0x16DEA9D24AB81971ULL, 0x6467122DA4CB8B29ULL, 
            0x7993B3679F6492F5ULL, 0xF281A7A9EFD5BA42ULL, 0x3F16A5D44FDFB9D1ULL, 0xE70B1E59F3E5BA24ULL, 
            0xD5E6B097D84E14C2ULL, 0x5ACA1810896410D7ULL, 0xA303A96F7F38A3FFULL, 0x126362BB9B43D69DULL, 
            0x44EF8D443A37D7E3ULL, 0x1BD98CA2EF43D9B6ULL, 0x4B2F153B84148A71ULL, 0x1C7EEB6022E1423CULL
        },
        {
            0x4C9F81925483093AULL, 0x8EA483D26F2267E4ULL, 0x2CA1389652EC24B1ULL, 0x47174B4442617472ULL, 
            0xCDFCC7C8A595166AULL, 0x4AC5CFD259412992ULL, 0xC813F40463B3578CULL, 0x1DA577BB6FAE169AULL, 
            0xF3804EC4D29D61E2ULL, 0xFDEAD3EE7DDA842CULL, 0x807380F44BB3265AULL, 0xB1BA14BF1211A5E7ULL, 
            0x50B13FD5C2E65565ULL, 0xF4F80E39A29270ABULL, 0x1F2FF0F91BD1CDF1ULL, 0x0F54715A8490F3ACULL, 
            0x575F86A40C840B46ULL, 0x25E8F182286871B4ULL, 0x574269125F80CFBCULL, 0xD184E83969436AC0ULL, 
            0xDC14EB4DA519DA16ULL, 0x9ED1DAC6EF51AA5EULL, 0x3E70ADD973C42F13ULL, 0x7C713316475AB651ULL, 
            0x940C192CA5711510ULL, 0x469E171C14983534ULL, 0xF7EF9B17C1871D66ULL, 0x305B0D96D9DD1589ULL, 
            0x1B4E0E1CB0DBBF46ULL, 0x05B5BF19C272FD92ULL, 0xBD1B616209736673ULL, 0x339B451BD3E8FA05ULL
        }
    },
    {
        {
            0x45754868D0F334EDULL, 0xFC3EF47C06775D35ULL, 0x3FD37A66F5D4F8AAULL, 0x5CFD861AFE1F8900ULL, 
            0x873E26B5A7A68F3FULL, 0x81401E64DF0056B6ULL, 0x0D6290A60EE7A7B3ULL, 0x0F254058B2EB0323ULL, 
            0xD956EF6E6D712493ULL, 0x65ABD6E029E6BB34ULL, 0x9E946B809D55569AULL, 0x3C848C9F30AE7850ULL, 
            0xDA616E46966D534CULL, 0xEF10B6AB0B9B7A2AULL, 0x83A5D03983F51EB0ULL, 0x8E37004506C025CFULL, 
            0x9CA9409D27A9E949ULL, 0x9CB4D115CAE72923ULL, 0x2674A0498D4717F1ULL, 0x53814F2B30DDCD24ULL, 
            0xB85C38958D620C12ULL, 0xED790654D4A72031ULL, 0x27115754A6CC96BDULL, 0xAFA57DC7060B763DULL, 
            0xA0DF60F28668D614ULL, 0x020B55348041B93BULL, 0xEDAEE6C731206CB7ULL, 0x20C349D817BA9FA5ULL, 
            0x66D855E2FE2A1A2CULL, 0xBD31C4472BBDB49BULL, 0xCDD11542D57D17A1ULL, 0x623D3255D4827A3EULL
        },
        {
            0x6D8D0A4E14D131A8ULL, 0x48119CE3D8D732FBULL, 0xF83F559B6B5C5B5FULL, 0x7404CD39123FF046ULL, 
            0x397FA953B0825B7FULL, 0xEC0E41F827E322A9ULL, 0x96B69F2643E76F79ULL, 0xCCF9CE76555A554AULL, 
            0x2504AE2C846EB663ULL, 0xBF68744A055A6836ULL, 0x6FCCF0F959CC06DEULL, 0xD3F97AB9DF579574ULL, 
            0x411F9AF6C035830FULL, 0x14CC09D7E9DBC2C7ULL, 0xCB279F8748F748C0ULL, 0x04DFD6798F1BA4C7ULL, 
            0x23B21B5B847C64ABULL, 0x18A06718E4918640ULL, 0x1EF59AD24DC57230ULL, 0xDCDD9825E65A4975ULL, 
            0x544A8CEC32731F90ULL, 0xA5A3FC82FF4016F9ULL, 0xD0F261DA07D877CBULL, 0x5182FA13FFC51576ULL, 
            0xEF8DCC2E6919C8B5ULL, 0x39B0781782D0C5FBULL, 0xD6FD18C5E51AE2A1ULL, 0x2EF3316D20759C32ULL, 
            0x6B0C51FE6A06AD73ULL, 0xAD5126F9B1BB49EAULL, 0x6D5C6F0B6D137E1DULL, 0x7BC8182D1C5CB7DFULL
        },
        {
            0x853D4AACA2A2049FULL, 0x889B28BC9CFD7D0BULL, 0x6BB83AEDA4F66183ULL, 0xABC7DC9EC0C135B0ULL, 
            0xF30AC4EE861CB387ULL, 0x5D9376D430896A14ULL, 0x21E05732206227AFULL, 0xACD12E057F36E87CULL, 
            0x31AB01B9463B8BADULL, 0x46526B8393F01BB1ULL, 0x1A3F25554B5F65B5ULL, 0xA698F4F7BF3C5580ULL, 
            0x5CA2334510F59453ULL, 0x689B0CA076F79A11ULL, 0xF2AF76BF2B329E25ULL, 0x3D65C186ED078F1BULL, 
            0x69E4E386907B5E42ULL, 0x3C3020DF28F77390ULL, 0x53B2A8A85681EC83ULL, 0x2842575375C3C4A1ULL, 
            0x7CC5A0558676D41CULL, 0x8AF36AD7E1F731A3ULL, 0x4636515B83542BE5ULL, 0x15858142B8C50A55ULL, 
            0x719B9A599FAE9837ULL, 0x07C33F746F96374AULL, 0xAA3E94CBB5334958ULL, 0x879B1B0C2EE8F191ULL, 
            0x3CC8207ACA7BB5EAULL, 0x587E699A78F92FA0ULL, 0xA6A7453F43355BF7ULL, 0x52E6DDD4677270FAULL
        },
        {
            0x6D021CA4BB71FDE3ULL, 0xB28532607C8F8510ULL, 0x541D3B61D3DF3ED9ULL, 0xFD6866B39086BBA8ULL, 
            0xFA884990FA469C08ULL, 0xCA51DDA4CBEDE6AEULL, 0xA9CA2BD95CBD8861ULL, 0xEC24B2C4286304C1ULL, 
            0x741F24ADE11248DFULL, 0xDEE1B15F698BA8E0ULL, 0x2A0BF3B357EC3D51ULL, 0xA2FBE27CF66FCFDEULL, 
            0x184A45AA9C67234FULL, 0x7FC5341C1258E12BULL, 0xCE886F97175C21A8ULL, 0x474BDD6747D997E1ULL, 
            0xD103A122D981A492ULL, 0x62FA6DDB86D4BB49ULL, 0xE5A632D7C7DCC4C2ULL, 0x56FD6F9543491777ULL, 
            0x0FD9F192C94BC4DAULL, 0xD77F5358F807FBD8ULL, 0x0F53611B9544DC81ULL, 0x3F3617274EFF3625ULL, 
            0xA8B9DD5B92CC676FULL, 0xDC3537968452897CULL, 0xC455313893282ADDULL, 0x712646EE3256EBA1ULL, 
            0xB349A5D18CAFED56ULL, 0xC98385538B0B9539ULL, 0xE1D6C6435855B53BULL, 0xE077ADA9333D1BBBULL
        },
        {
            0xD8272562FBC56BA1ULL, 0xA64DC18A286722EFULL, 0x822036E86B117CBAULL, 0xD393DE48F264CB94ULL, 
            0x9465483ED098FCFFULL, 0xF0124C2B7ADD7471ULL, 0x29CA5D3CE9E41BAFULL, 0xFBB0830CE9669987ULL, 
            0x5F34FB6D2F87353EULL, 0x3ED58BBDAAB19877ULL, 0x1F33C4277A290CF9ULL, 0xDA13C3267BE8D80CULL, 
            0x40DFD36E8B8F89BDULL, 0xE59610651C794840ULL, 0x1230F1791FF7E725ULL, 0xFF263AF9C53E6A3AULL, 
            0x5B6D170C8C6AF0A1ULL, 0xA2AE7564E77F44C2ULL, 0x0354A5D97A1636CDULL, 0x81CDED0AF465EADFULL, 
            0x1D96860F57F3E84BULL, 0x8B1BA30F52B590CEULL, 0x7E8791E5454DC956ULL, 0x2DFAF93AE0054470ULL, 
            0x6F93262BF41BD15AULL, 0x1D4CB01F02FFD6E5ULL, 0xF7B1B908A4ACA621ULL, 0x872E2CFA5E690BD5ULL, 
            0x238BC068ECD21BB7ULL, 0xA84D234B0D219D60ULL, 0x91C6CE3E1D79321DULL, 0x175DADB24EE2C20FULL
        },
        {
            0x426B6B262B1FC144ULL, 0xEFAC888C0C78768EULL, 0xBB5F38AC17045DDFULL, 0xD654B85B73AA0C4FULL, 
            0xBB1E897F076EA8DEULL, 0x92D4235CAB4FAB99ULL, 0x3A88670349169DE8ULL, 0xADE91EB481C88F1BULL, 
            0xA0A444CBAFECC536ULL, 0xCEBF3CB8D6C5367EULL, 0x9B814D57B5C60540ULL, 0x8DF0285307337C11ULL, 
            0x850ADDDC31446289ULL, 0xC548A057458ABAE0ULL, 0x155221F4E1E0EDC9ULL, 0xFF59F4A939FE4732ULL, 
            0x11150AF4C6D9733EULL, 0x3FB7F1ECFD797DD9ULL, 0x5FBB7D8220BD411FULL, 0x16D30309F441D5C3ULL, 
            0xF052304DBBD2CA2CULL, 0xF1EC7BF566AE5BEDULL, 0x901AFCE38DE9F8B8ULL, 0x5FBFDAE6CFE6C4A8ULL, 
            0x91F8B0A43B226356ULL, 0xFC62047266B5352FULL, 0x55235661E68699C9ULL, 0x83052EB9037427E9ULL, 
            0xE7A3F3186B97C86CULL, 0x2F521D0E24E035EEULL, 0xD7FD9FC49FF138F5ULL, 0x1985DD32E6CFB094ULL
        }
    },
    {
        {
            0x1855E9B6C6F24979ULL, 0x2C575A5AA665C38CULL, 0x0BF6726B384CC1D5ULL, 0x59207AEC03F64103ULL, 
            0xC38E4209EF307A4FULL, 0x6D16961BCD8D3CB0ULL, 0x30FB68796D3B408AULL, 0xB5348DFC2B16CC11ULL, 
            0x78386E62B118E07BULL, 0x19C0DFB923BFEA87ULL, 0x64404A166D94E868ULL, 0x850BF0A0F3D0BD53ULL, 
            0x23E943A3DAFA8035ULL, 0x29829EDDDA97340CULL, 0xC407C0F3CA187DDCULL, 0xE8BC35B16D7A65F9ULL, 
            0x470A69B43DFF117AULL, 0xF11A0E343192F0BDULL, 0x909C92A868D1EEEAULL, 0xD3AC4D0B7534B365ULL, 
            0x12A6F8028F86981DULL, 0x0A5CA25A9EDC5247ULL, 0xDC49B5D2BA0E8545ULL, 0x24517E03C857CCD4ULL, 
            0xE42EBC45EFA69B54ULL, 0x88057E2F0CBD6FFBULL, 0x55727840E85853CBULL, 0xFF35D19A66B9983AULL, 
            0xBA8498790D66B6EDULL, 0x3A7A5CD0CCF9D2B7ULL, 0xAC3DD6BB9FCC2B6FULL, 0x0B23613D55767112ULL
        },
        {
            0xEA4D93E6159821AEULL, 0x8035657087241B9BULL, 0xE65057646878B6E3ULL, 0x5D322A1743752E05ULL, 
            0x830DE99974B630B4ULL, 0x9AC8DE73EE1D3F46ULL, 0x25E4BAE0D113F9D9ULL, 0xAF7F69B02352E17FULL, 
            0xFF0597E19BA38A43ULL, 0x14D67702F5F1A2E5ULL, 0x6283C436686E6830ULL, 0x28B3C0B8DF072125ULL, 
            0x205E98D0002A783FULL, 0x90BA81CF3BBD1714ULL, 0xA3E08238BF07CC6BULL, 0x3AE75BC6E60BD609ULL, 
            0xEE9C5B5F670D6C42ULL, 0x8B7C081AA56CAD11ULL, 0x1B89ADEF1B53F773ULL, 0x7BD72E98E87674F5ULL, 
            0x771EA9C6458B7D8DULL, 0x00C9E90FA56277DFULL, 0xF873EC7CF0E39F50ULL, 0xD800C6BF1036F35FULL, 
            0x19B40502CF2B6D38ULL, 0xE99F1C68F4F1B24AULL, 0xB81ACB656907B663ULL, 0x96B84083C44C6F15ULL, 
            0x0951FC3997CAD4D5ULL, 0xCBC53297D4A50A9EULL, 0xDAB33FD7F69F38BFULL, 0x05C0A75B2D9D44CEULL
        },
        {
            0x2DE8DBB5D513EB0BULL, 0x620601AD7747D221ULL, 0xC8CAFBD7E51EF98CULL, 0x9E815C83B621670AULL, 
            0x5559B06E0E03D1E7ULL, 0x30E31B6B8866DAD7ULL, 0xA7F5E9DE3291C30DULL, 0xF7E97B6932ACF4A4ULL, 
            0x4B43A1374703F872ULL, 0xFCC7CB2AEEDCE81FULL, 0xA06FC4775B7C0602ULL, 0xF492F0D9F17A833EULL, 
            0x752A802A216B6BB6ULL, 0x5B79827450982BCFULL, 0xE771E204C0BF8F41ULL, 0x1E75D9AAFFEE7BDDULL, 
            0x38905052577EBC7BULL, 0x9FF1F6ABA0064038ULL, 0x5D988CF388F2513AULL, 0x3EE9C5EF85369DB8ULL, 
            0x16E9E4F5E78CEADDULL, 0x464D72A4E93D0049ULL, 0x195B81B88EFC907AULL, 0xDD72F3BB4DE912FCULL, 
            0x33D109750B4E4F26ULL, 0x12DC51070BD75F64ULL, 0x60307CB845F19B20ULL, 0x4F383619F259835AULL, 
            0x19354B6E4EE9923FULL, 0x3B5C8DA61BF24DB4ULL, 0x699F4C40F0915BE0ULL, 0xD351560AC194DE69ULL
        },
        {
            0x734064F50377102EULL, 0x8E8525F2BDFD403DULL, 0xCDC0DB0F8C7EBD86ULL, 0xDD7712D846F6B0F9ULL, 
            0x1A22CACD4E033FFCULL, 0x1359E36E7E00B833ULL, 0x8B268972AF8A4E4BULL, 0x6A852570A6B8B437ULL, 
            0xD0BBC0EEDFB8C051ULL, 0xDAB8B208DDD311A9ULL, 0x5EAC3D14B7273BCFULL, 0x2F9D61F675213C9CULL, 
            0x6AA3099A1060B9CCULL, 0x5B8211EE671B6AB6ULL, 0x49970164EB0209E8ULL, 0x4F3B8BE15B6DB72DULL, 
            0xB458C1B9E0F35A2BULL, 0xACB49F9913EE43FFULL, 0x6AA30A4F0C8DF189ULL, 0x32CC213DC15D2D33ULL, 
            0x44F838BB078D1A45ULL, 0x47D4372D1172FF45ULL, 0xCB906F0E20EFE2ABULL, 0x84ADD37D887C0CB4ULL, 
            0x4C740145F526E030ULL, 0xFFF58A10380D0C1DULL, 0xC0BD8602D7735310ULL, 0x61CBEFCE578C7DD8ULL, 
            0xE92D1F114FE03227ULL, 0x81C5BDD932ED7023ULL, 0xD678A710982BF25BULL, 0x99FD57AE8C40ACBEULL
        },
        {
            0xE3D7D43EBE5F6089ULL, 0x7879ACC72C5A460DULL, 0x3DF09183A20A3C8CULL, 0x449D413FA73D1FC5ULL, 
            0xDA725CCEA6130F10ULL, 0x50A891DB7FB32ED0ULL, 0x0F7B701F6364C681ULL, 0x95B5C0272B8BD381ULL, 
            0xC85B8215B11E6308ULL, 0x9E7E671D6334D236ULL, 0xAFC3D4B9F26071CDULL, 0xFF3A10977C453823ULL, 
            0x983B4E5E94E84907ULL, 0x47608DBE99D27872ULL, 0xAFFEBB4A5DE54AA2ULL, 0x79CA075A3F955EDDULL, 
            0xAD99ECA61063107DULL, 0x7836F78000A4AA94ULL, 0xBC2377A3977B7171ULL, 0xAD4ACEA733C129BAULL, 
            0x8E01A4A22129444BULL, 0xE9236F876059E007ULL, 0x5FA3E22B75F4B4FDULL, 0x7D76AB78071725A1ULL, 
            0x0AF44B9D65A90292ULL, 0xB2F7511484D0D413ULL, 0xDA9397CF41F8927FULL, 0xB896FC0A20C4B9BFULL, 
            0x03E06DE6C0440F1EULL, 0x0FE0A4AC9B312EA7ULL, 0xB4888041CAC941CBULL, 0x093A7D060361BD21ULL
        },
        {
            0x2508BE735D8D0DA0ULL, 0xDF5DC7F5FEA09C7DULL, 0x77C5E0A701E27C81ULL, 0x2AFE6DBA3F42DA28ULL, 
            0x87B2BBBEA88A2C3FULL, 0xA9210FC85A205A74ULL, 0x7B0213989AE95314ULL, 0x58FA60C31F0558C6ULL, 
            0x3DD581EC1E2D361DULL, 0x671A012D06699E69ULL, 0xEA1C51774BCD5745ULL, 0x38559BA1F5802111ULL, 
            0x7A6125FFBE15DDCAULL, 0x6046B1E981663EE7ULL, 0xE4AAAC8A7695267AULL, 0xFD64C4B81EAE3ADBULL, 
            0xC9ADA20EAF96284EULL, 0x0EEF446E9EE20A45ULL, 0x4BAEFF7F4A1D490FULL, 0x86147614D0B689CDULL, 
            0xF495CD92FFB454F4ULL, 0xD10E8B83C9A7F9B6ULL, 0x8163C460BE022CA1ULL, 0x4658570AC2AC1CD8ULL, 
            0x64D5D1F5ECF79AB9ULL, 0x40B88DC42EA107C2ULL, 0x089C316E4B96C125ULL, 0xEAB495F46352B01AULL, 
            0xFB9EE76D52A6174CULL, 0xDEC619C7446C7D36ULL, 0x2BEC94F57A17DBADULL, 0xC74F24B985C7177EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kTwistConstants = {
    0x8B7CB9441DA8AFC4ULL,
    0x356F08444068F56CULL,
    0x7E658D24290E87C6ULL,
    0x8B7CB9441DA8AFC4ULL,
    0x356F08444068F56CULL,
    0x7E658D24290E87C6ULL,
    0xBC14798974F12066ULL,
    0x96663CCFE2D6EB06ULL,
    0x3F,
    0x5C,
    0xFC,
    0xC9,
    0xC0,
    0x70,
    0xEF,
    0xD9
};

