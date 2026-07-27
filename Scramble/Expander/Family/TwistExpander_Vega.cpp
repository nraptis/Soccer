#include "TwistExpander_Vega.hpp"
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

TwistExpander_Vega::TwistExpander_Vega()
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

void TwistExpander_Vega::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF116F0B353AD00C9ULL; std::uint64_t aIngress = 0x8192BB64E6448D1AULL; std::uint64_t aCarry = 0x8265EB396E2CCC13ULL;

    std::uint64_t aWandererA = 0xE85FCC7C4944F1D1ULL; std::uint64_t aWandererB = 0x996FBCD8C1EF8838ULL; std::uint64_t aWandererC = 0x94135864B71AF268ULL; std::uint64_t aWandererD = 0xF2F11014737D0627ULL;
    std::uint64_t aWandererE = 0xFE8E075AFDF37CEEULL; std::uint64_t aWandererF = 0xE03AA45133288C35ULL; std::uint64_t aWandererG = 0xE1DDD9CD438C4CFAULL; std::uint64_t aWandererH = 0xFC10754452EE7FDDULL;
    std::uint64_t aWandererI = 0xE3E53ED107411288ULL; std::uint64_t aWandererJ = 0xB721C217A16E8F33ULL; std::uint64_t aWandererK = 0xC1346F6C0AD706EEULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8D6657D25D23CD13ULL;
        aCarry = 0x97381628A9A7DC3EULL;
        aWandererA = 0xA20EB831F165D084ULL;
        aWandererB = 0xBA6130394A0F073BULL;
        aWandererC = 0xE3DF67BB4A9730B8ULL;
        aWandererD = 0xF7BEB05DE2845058ULL;
        aWandererE = 0xBC971A0C6B66051CULL;
        aWandererF = 0x811911D658A8D78AULL;
        aWandererG = 0x9E3B9C126BA4F4F1ULL;
        aWandererH = 0xAF00CB80F3C5B480ULL;
        aWandererI = 0xAB1937D3F5702737ULL;
        aWandererJ = 0xF2F85E9CE69C6582ULL;
        aWandererK = 0xFD6BCBC578A97EC8ULL;
    TwistExpander_Vega_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x851424611ED63BD0ULL; std::uint64_t aIngress = 0x98ED7047C030B70FULL; std::uint64_t aCarry = 0xA17AA2A724C6865BULL;

    std::uint64_t aWandererA = 0x9095A0A7FF3807A5ULL; std::uint64_t aWandererB = 0xB56D1D57B7CC7878ULL; std::uint64_t aWandererC = 0xAF7742EF81A4239AULL; std::uint64_t aWandererD = 0x985E9114037ADB08ULL;
    std::uint64_t aWandererE = 0xC9AAE5C970403EDEULL; std::uint64_t aWandererF = 0xDB5915C8557E0781ULL; std::uint64_t aWandererG = 0xF2098EC68BC2A832ULL; std::uint64_t aWandererH = 0xD02A0A1FBA81EB3BULL;
    std::uint64_t aWandererI = 0xC548BDD961702CC1ULL; std::uint64_t aWandererJ = 0xE768DBCA01D6A028ULL; std::uint64_t aWandererK = 0x99E13A12D92349B9ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA4F0107BD0799697ULL;
        aCarry = 0xA55CCD844DB444E0ULL;
        aWandererA = 0xD7A990933FB827D0ULL;
        aWandererB = 0xA4457DA946091024ULL;
        aWandererC = 0x8E24943D20F94247ULL;
        aWandererD = 0xE96F5FD732E95C4AULL;
        aWandererE = 0xE53E0E01C73B27A9ULL;
        aWandererF = 0xCFE5BAB32B041A0EULL;
        aWandererG = 0xF138451467AB52B3ULL;
        aWandererH = 0x80B1302B306C91A9ULL;
        aWandererI = 0xB433E58283CAB363ULL;
        aWandererJ = 0x941612A5D3C27625ULL;
        aWandererK = 0xB7E5079C40F697DFULL;
    TwistExpander_Vega_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE39B47A3AB184936ULL; std::uint64_t aIngress = 0x95F3C509A1943775ULL; std::uint64_t aCarry = 0xB3424A360554DBADULL;

    std::uint64_t aWandererA = 0xDD775511D52BB07BULL; std::uint64_t aWandererB = 0xDC30A371EEDD55D3ULL; std::uint64_t aWandererC = 0xCDC353B726394A90ULL; std::uint64_t aWandererD = 0xAEB085FFEA2A072AULL;
    std::uint64_t aWandererE = 0x97AD0D72DB34F450ULL; std::uint64_t aWandererF = 0xBEB3E5785B44D20DULL; std::uint64_t aWandererG = 0xC120CEE3BA3F979EULL; std::uint64_t aWandererH = 0xF29C254E6B70DD58ULL;
    std::uint64_t aWandererI = 0xB32C57A6471048A9ULL; std::uint64_t aWandererJ = 0xF5A1DE935DA22277ULL; std::uint64_t aWandererK = 0xFF3049906BAD1015ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDB6FDC2485FC5011ULL;
        aCarry = 0xD645A210D126EF1BULL;
        aWandererA = 0xD5AB830AFB734EC2ULL;
        aWandererB = 0x801EB6F65DB45219ULL;
        aWandererC = 0xD64DA3BF343A6DB8ULL;
        aWandererD = 0xDF46F6BEF7A3BDE2ULL;
        aWandererE = 0xD66320C64C4D9B78ULL;
        aWandererF = 0xDDF0BFF68058EF9CULL;
        aWandererG = 0xBE598D58CD1AA496ULL;
        aWandererH = 0x94F31C9584E84BD8ULL;
        aWandererI = 0xC9333C82906C06C9ULL;
        aWandererJ = 0xA49FB39A16284942ULL;
        aWandererK = 0x994598CFE0E9062EULL;
    TwistExpander_Vega_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCC71B3298781D9CFULL; std::uint64_t aIngress = 0x95FC57A100413B0CULL; std::uint64_t aCarry = 0xB6DC5AEBA1BF72DFULL;

    std::uint64_t aWandererA = 0xE952F3FDB96CE38BULL; std::uint64_t aWandererB = 0xA5AF14D1120B165AULL; std::uint64_t aWandererC = 0xF04B495DA937D123ULL; std::uint64_t aWandererD = 0xF1B2A4335A4DCA3FULL;
    std::uint64_t aWandererE = 0xA937582951F2498AULL; std::uint64_t aWandererF = 0xDAD6AAFB33F1F899ULL; std::uint64_t aWandererG = 0xD5C9515DB34C0930ULL; std::uint64_t aWandererH = 0xA72C5837F42D1884ULL;
    std::uint64_t aWandererI = 0xC31AB8884573B72CULL; std::uint64_t aWandererJ = 0xCC8D92C6295A95EFULL; std::uint64_t aWandererK = 0xA16985BE2983DD75ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE47B6B85261F560AULL;
        aCarry = 0xC658618778C75129ULL;
        aWandererA = 0xBAC2A7B4C8C0CAD0ULL;
        aWandererB = 0xDFE036D5876DFCABULL;
        aWandererC = 0xD5CFB3A3173A36EAULL;
        aWandererD = 0xE1F1686B29A5E771ULL;
        aWandererE = 0xD8A4BA6A64A2E924ULL;
        aWandererF = 0xA43B56970FF50881ULL;
        aWandererG = 0xD0E91158D78F46C6ULL;
        aWandererH = 0xD97C8256FBA3FEE3ULL;
        aWandererI = 0xFAB83BB019E4C215ULL;
        aWandererJ = 0x952613E106D8C6DBULL;
        aWandererK = 0x8DD09183074230CDULL;
    TwistExpander_Vega_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Vega::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF619984685C60B10ULL;
    std::uint64_t aIngress = 0x927CD52C2B2742D4ULL;
    std::uint64_t aCarry = 0xF13143A5A88ED34BULL;

    std::uint64_t aWandererA = 0xFF97704B823BA731ULL;
    std::uint64_t aWandererB = 0xA94B7A93142DEBFBULL;
    std::uint64_t aWandererC = 0xA9E20E4438917CF5ULL;
    std::uint64_t aWandererD = 0xAEF0357632ECD265ULL;
    std::uint64_t aWandererE = 0xC313B55D0F93D385ULL;
    std::uint64_t aWandererF = 0xC79694DDDD298471ULL;
    std::uint64_t aWandererG = 0x8D0F53EE63B08125ULL;
    std::uint64_t aWandererH = 0xEDAD8776FE45D253ULL;
    std::uint64_t aWandererI = 0x90CF6AD4A116AAF4ULL;
    std::uint64_t aWandererJ = 0xF93F348C38D140DBULL;
    std::uint64_t aWandererK = 0xA08A4AAA42F398AAULL;

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
    TwistExpander_Vega_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Vega_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Vega_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Vega_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Vega_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Vega_Arx::KEY(pWorkSpace,
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

void TwistExpander_Vega::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF2CCE4617E318E51ULL; std::uint64_t aIngress = 0xB5425E9887A864CEULL; std::uint64_t aCarry = 0xA42A8EC53A3408FDULL;

    std::uint64_t aWandererA = 0xD636A69F09EE1B47ULL; std::uint64_t aWandererB = 0x824290F96A47B36DULL; std::uint64_t aWandererC = 0x94E58D08C5B4A3D2ULL; std::uint64_t aWandererD = 0xA2B8AB561BEECB08ULL;
    std::uint64_t aWandererE = 0xA3F1B286AA5CB626ULL; std::uint64_t aWandererF = 0xF939B7FE7ADF8BBDULL; std::uint64_t aWandererG = 0x8E9549757F246763ULL; std::uint64_t aWandererH = 0xDB4A5CB852EBC4BBULL;
    std::uint64_t aWandererI = 0x874D22D23124F98DULL; std::uint64_t aWandererJ = 0xF0E74E8693F770E9ULL; std::uint64_t aWandererK = 0xE7E5C31AABB6873FULL;

    // [twist]
        aPrevious = 0xC03682CDAFD04573ULL;
        aCarry = 0xF4F1E2A32E6BA7C7ULL;
        aWandererA = 0xD472BF2BA6F27345ULL;
        aWandererB = 0xF810B4663A79B3EEULL;
        aWandererC = 0xA3B3C2A0A4BA87E1ULL;
        aWandererD = 0xB1381E835BCF201AULL;
        aWandererE = 0xF05543DB92D8B01BULL;
        aWandererF = 0x833BEE5115584514ULL;
        aWandererG = 0xFF2884FB1FE95C5DULL;
        aWandererH = 0xACEC9C938BA62B55ULL;
        aWandererI = 0xE882DE9C75DF821EULL;
        aWandererJ = 0xA3801160A8DF21F4ULL;
        aWandererK = 0x8C8EEA8EB745448CULL;
    TwistExpander_Vega_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Vega_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Vega_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Vega::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Vega::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Vega::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 33 of 33
    // Exploration cases: 0
    // Structural maximin 501 / 674; family total 17165
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1645U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 33 of 33
    // Exploration cases: 0
    // Structural maximin 503 / 674; family total 16900
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 700U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 33 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1042 / 1248; total 34279
void TwistExpander_Vega::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
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
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
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
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
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
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
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
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 33 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1041 / 1248; total 34570
void TwistExpander_Vega::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
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
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
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
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
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
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Vega::kKeyRotateSalts = {
    {
        {
            0xE04B7FFCCFAD5974ULL, 0x007F5F0AAF226CBCULL, 0x62AE4457CC92D953ULL, 0xBDA76385A221384BULL, 
            0x34E3848C2D0C8CB1ULL, 0x690373D3116A8012ULL, 0xCE5E34D6E9B70201ULL, 0xED0048D098BA1727ULL, 
            0x4537D771DFD6742EULL, 0x0181695F3F6FC0A2ULL, 0x8D8C9DB4F1E73E43ULL, 0x0079CB93E0B663ECULL, 
            0xC3FAC2A09494E8E3ULL, 0xF1B947D57D3BFAB8ULL, 0x449C393C0EA5A5E4ULL, 0x43B98F2949EB6657ULL, 
            0xD6F7F3F60A991051ULL, 0xA8613F46E115F054ULL, 0x6CA7867F63D39C41ULL, 0x2C0C794A81D23C92ULL, 
            0x6A29B27018787638ULL, 0x13E8F2693E5A138CULL, 0x155F4D06257C6382ULL, 0xDB972484DB519C28ULL, 
            0x12E0F316AF2C440FULL, 0x00796F0CED902350ULL, 0xB9077446BF046D1EULL, 0x7A1F5C7A4676D9BBULL, 
            0x6F2E4DBB7A057B0CULL, 0x378B0A106FD4B96BULL, 0x787E0386ADA2B65AULL, 0xDD269390CA41033CULL
        },
        {
            0x6842CE486B429776ULL, 0x4AF869C4F58D9C3EULL, 0x38CA2584A47C48D4ULL, 0xC1FC8A7207FEBFF1ULL, 
            0xD9F353ACC20AAE07ULL, 0xF914C0A2C7D372BBULL, 0xDC82110F8F266E05ULL, 0xCD55DF0A716F6C73ULL, 
            0xA368BB4759EED4B2ULL, 0x6EDD8348D31BDE27ULL, 0x0E6F8CEEE3DC74DFULL, 0x248ABD780AD1FF27ULL, 
            0x94415E25159F870FULL, 0x25604055E8B1F1D4ULL, 0x42A21D991570BCB4ULL, 0x2BDFE295239509B8ULL, 
            0xB6F345BCAB129F08ULL, 0x7B00A4C7E4D1DFE4ULL, 0xCBDF38D879CB585CULL, 0xABB15E03F0EAF3DFULL, 
            0x68502EA248201CA6ULL, 0x795D52C40AFEDA73ULL, 0xBFBB8C732860329CULL, 0x0D3B7273B01C69A2ULL, 
            0xAEFE6312F601E2E1ULL, 0x455DF594D1E6442DULL, 0xF33A2DCBC8D5A5E3ULL, 0xA972B18C051B1FF4ULL, 
            0x9752FA5B2694480BULL, 0x12489900AEE45AF4ULL, 0xB1FEC1D42A84C5EEULL, 0x3B93E627ECF0697AULL
        },
        {
            0x8623080A258F2D88ULL, 0x469DB90F8D49CBFCULL, 0x1D29E3094F7BBA9FULL, 0x433B2B47BFF629CBULL, 
            0x610980CFD9A1A118ULL, 0x8509E04635B5F4EEULL, 0x72CF10DEA5277C3EULL, 0xA466FDE784EE3F2AULL, 
            0x12A8BCE6FD09ED9DULL, 0x69AC8DBFA2EF6E52ULL, 0xCFDEC4FBD3A18D76ULL, 0x00601E84499C564BULL, 
            0x583F853B10EE2807ULL, 0x6D14F8DD5A4CDBCBULL, 0x49FEAF0D2FE58480ULL, 0x3A2D669D4D28F433ULL, 
            0xBECD9E6EE11DD6CAULL, 0x1F94539E37813AFDULL, 0xA2E87904EEDABA66ULL, 0x93DA4E95E5B0A5E7ULL, 
            0xA7CFB781159F1A76ULL, 0xDEF3F0B6F3FD7D98ULL, 0x5166594E1C9058C9ULL, 0xCC986EF7AA0C0893ULL, 
            0x31B04AEF3CC4DB59ULL, 0xADDAE76027998FBEULL, 0xC05A642284138231ULL, 0x72686E4443382C78ULL, 
            0xB4394C27291EC319ULL, 0x3E0E987DCA4423EEULL, 0x79EB480407A952F8ULL, 0x14C98043B1485770ULL
        },
        {
            0xC737A1D55DD9559FULL, 0xD046318DF5F6857FULL, 0x5193D39B02DCEA18ULL, 0x59927AD43C885873ULL, 
            0x351D7720EDC289BEULL, 0x4D9896455FEB244AULL, 0x75C5B91467D7817DULL, 0x7EB43DC3B544AF07ULL, 
            0x5C4CA0624DCEAF3EULL, 0x60B64AC4B8D5258CULL, 0x40CC07A5288DC19EULL, 0x691913ADA27233B0ULL, 
            0x11EEF1F85BCA74ACULL, 0x502BA2E0FF65EC94ULL, 0xEF07298F48BCAC1FULL, 0xD65B12600ED372D7ULL, 
            0x370BAE6A2C841F7EULL, 0xE43220B949C2772CULL, 0xE2A7113CFF4A1F10ULL, 0x3107363CC74263F8ULL, 
            0xB18E7652FD662C63ULL, 0x088DF3CF6021705CULL, 0xBCD9A5BECC7E1691ULL, 0x6916773742E0464BULL, 
            0x2199F1B1469DAA05ULL, 0x711797483871FC60ULL, 0x22BABE142D77E147ULL, 0x488D8A02A46ED514ULL, 
            0x508B8E9D51B6A46FULL, 0xCAA7F7347604B940ULL, 0xF6B3963DB7AEA81FULL, 0x5A2257F4790DAAF0ULL
        },
        {
            0xAD5E117E91B334BCULL, 0xC242EF365414B683ULL, 0xA06CBE84E4E57CDDULL, 0xA8DEFD0C47D2EC7EULL, 
            0x245B54AA8ACC783BULL, 0x5BFB8C72492E04B0ULL, 0xDEF0304052585FDCULL, 0x18DA22F84A65E4C3ULL, 
            0x06C93256DAC9FDEFULL, 0xB8A9E19294D7CBA9ULL, 0x304F0672D8734662ULL, 0x8F89C98E8B454375ULL, 
            0x9F545E3381EF07DDULL, 0xD3AEB39193EFFA09ULL, 0xDD60ACBB1996541AULL, 0x064D6AB2F1EAA0D7ULL, 
            0xD4350621824A11C2ULL, 0xD7B2834D89CE8026ULL, 0x6F0B6FF4AEA260B2ULL, 0xE25E5D5057B042C5ULL, 
            0x07526819D814AA1FULL, 0x7BDE0E7C782DC33AULL, 0x927456461FCAC3CCULL, 0xBEB7B72BFE0D8540ULL, 
            0xAD7872DA5011EEE5ULL, 0x87ED58C6D96B4F80ULL, 0x0A09B943E28371A1ULL, 0xF2FA6A2144694CDEULL, 
            0x92E3C607D55000D3ULL, 0xBFAF914CC38613F2ULL, 0xFB7E82BE3E938C28ULL, 0x16FEC7A41574A994ULL
        },
        {
            0x432FBE321424D728ULL, 0xF30ADDF4E6D1E74DULL, 0x508C8BC8E404BECAULL, 0x6AB9C70ABDB1E081ULL, 
            0x6DFB4FD6D17D94E9ULL, 0x70218E8EAFEC1B0EULL, 0x710D00E074ECEF35ULL, 0x3C7E3D25138790C8ULL, 
            0xEDAC83B53D975527ULL, 0x9171715F93F74754ULL, 0x19993622676C200AULL, 0x1CFC4FC1057A8E94ULL, 
            0xB3E7995138297CA0ULL, 0x1C849ED5376ED770ULL, 0xB92BDAE676D47D19ULL, 0x0C622F8F7B6E6D02ULL, 
            0x3DEA7827BE634E71ULL, 0x2E7928054BEA279EULL, 0x3F137DE11F06E346ULL, 0x6F076128FE838FDCULL, 
            0x5110C0437F9FC36BULL, 0x776B48BCEFA614EFULL, 0xB55A1A4D5C2CE39FULL, 0xDE5A00FC8D02E7DDULL, 
            0x80F586DD1A9D08D6ULL, 0x97746B17582063EEULL, 0x93C0AB8214E1D611ULL, 0xC9C7E600F790D70BULL, 
            0x8AF6983A6308BE6AULL, 0x827D0AD03DE73F70ULL, 0x8F65C65F2108D2F8ULL, 0x8F5F5526F83C0F57ULL
        }
    },
    {
        {
            0x89D4415FC714DC2BULL, 0xB793B13F85BE1D6DULL, 0xBE8CABAB086B89F3ULL, 0x3A9D200F1ED38B63ULL, 
            0x914D4ED4412272D9ULL, 0xA72A0BDC4DC671F9ULL, 0x2532FC5893AC9F8FULL, 0xC36CBCDFB345D44EULL, 
            0xFA6C641F73C24CC4ULL, 0xF5B1411DBDE38B61ULL, 0x6A7D7AEDB3A3B6CCULL, 0xE6D08910677275D8ULL, 
            0xC20133E03615EC51ULL, 0xD0886EB2CA440031ULL, 0x79DB5EC7F57D07A3ULL, 0x2769343C4155F356ULL, 
            0x09317EB9D8C094C2ULL, 0xCA9BFB951AFBD1DAULL, 0x5450D84AD13A25F0ULL, 0x21B930B2ACA5E99AULL, 
            0x9E31BD0E2DF0A496ULL, 0xE7185B962770D5E9ULL, 0x5BC923367A1DAA7CULL, 0x00181D2AA733D81AULL, 
            0xF9D097EE41614909ULL, 0xB2B16A42116FFB49ULL, 0x43F03E8AD85DDD33ULL, 0xC740D75A8B5C3D6EULL, 
            0x86050A0EE3F7C9D1ULL, 0x64E7A940015CED75ULL, 0xCB76052DB7FC5CC3ULL, 0x3F00CBA2146695B0ULL
        },
        {
            0x3C02738FFE217B22ULL, 0x6E8AF692C88FD537ULL, 0x8ECFA12C36DABED6ULL, 0x9B052EAF80FE135BULL, 
            0x680E7CE3395493B6ULL, 0xE182195ECA226D84ULL, 0x5E51CA1D80339184ULL, 0x5EDFE2D8AF0E662BULL, 
            0xD319009A879BD1D9ULL, 0xC5945EF7FFDF7CBFULL, 0x3A51A4A2EA1EE4DEULL, 0xF30A3B88D65EFEF1ULL, 
            0xD95F1D0C5B3B2F31ULL, 0x1874640023B9821EULL, 0xC508519AEF625466ULL, 0xB3EC186D1F5CB92EULL, 
            0x41DA5826267EE2A5ULL, 0x2003E63804407FBAULL, 0x89A1E41E4BA5282DULL, 0x28F8A46B9F3FDECEULL, 
            0x802EC0E021AD3C9BULL, 0x8723E1290165FC7DULL, 0x429467B4734EF7CAULL, 0x3AEE111F7DA2D48CULL, 
            0xCD52E0CE2E1AC0E1ULL, 0x685ACB672674AEA8ULL, 0xFF76A9A17D309222ULL, 0xDAA8AB964318A2D1ULL, 
            0xAAF01DAF6BF97728ULL, 0x23EE9961031D6456ULL, 0x55427F24F15E1290ULL, 0x0E85E5C78AC43E34ULL
        },
        {
            0x0AE63B8A0466000FULL, 0xD28F8F6BEF1D1A15ULL, 0x6F548436475E173BULL, 0x0BA6311D7C3B73F4ULL, 
            0x269BE8A9AB74ED4AULL, 0xABA5B656A011FD55ULL, 0x4BF6F6EA9BA7CD1AULL, 0xA34416A6420AC087ULL, 
            0xEAE5D6B44562A670ULL, 0xE7326D3CB2A63F99ULL, 0x7EB2B31DCE816EE3ULL, 0x2F0F3655F53CC431ULL, 
            0x63D0E7B8D466EFFDULL, 0xB1DC0E3546F86093ULL, 0x29CCFCAA2D43F1FDULL, 0x3F0CA2C0A7BB0466ULL, 
            0x04ABD1BEDA4CDACFULL, 0xC7CFE3FEEF620E2BULL, 0x8DEDD7B35B76C065ULL, 0x23D4372E404A8175ULL, 
            0x92C45DCF0449D018ULL, 0xE70B8FBDF1EC7567ULL, 0xCD52B593913154A4ULL, 0x99835F2E4ECB30E4ULL, 
            0x96303E94C7832516ULL, 0xE9DA39385C31C58CULL, 0x0FB76E04E38838C0ULL, 0x4E2C58A419CC8E18ULL, 
            0x2E8993E9AA267785ULL, 0x58F582A4D125A6F9ULL, 0x387DBB0F6BC53FB0ULL, 0x1188131D0B9637E9ULL
        },
        {
            0x7F052270151283E8ULL, 0x8D52BFFF887B6429ULL, 0x2EB8EEF4BC715F2BULL, 0x18D2EA46C472B36EULL, 
            0x29009856C08964F0ULL, 0xA0F1CCEDABAFF039ULL, 0x7733F6C6D442040EULL, 0xCFE93832322C038CULL, 
            0x63E74FB7CEC60CD7ULL, 0x47E6C384015942E3ULL, 0x9DAB24C98506C269ULL, 0x8AEAE554447C4D9BULL, 
            0xB58368AB72261CE0ULL, 0x812CF507F7059D71ULL, 0x1406CA6CEF2863C0ULL, 0x2DCE6063E7AF9088ULL, 
            0x6A65A3338DC93365ULL, 0xED8AB984C68A4417ULL, 0x8B0DB11D7E97135AULL, 0x991B3A2822CEE4D4ULL, 
            0x724677DE2A0D1B58ULL, 0xC62B035C31441F1BULL, 0xA2411017A82DEB90ULL, 0x115454C493321B03ULL, 
            0xC77CEAF6D8D1B51BULL, 0x06712AE2C592DDBDULL, 0x1EB068051830FFE2ULL, 0xF381A34DBFFCBEECULL, 
            0x07805C97EADDF183ULL, 0xE5606FE7C2FDA61FULL, 0x53A3A71070BB2DDFULL, 0x56242C7303E27250ULL
        },
        {
            0xE006A26AA766EFFBULL, 0xDE35958A573C1DADULL, 0xAFBFB967F89A58F7ULL, 0x3B613F25BB8BCE82ULL, 
            0x159BCE7B75DE3737ULL, 0x7B230D335BB77FD9ULL, 0xD1C159040E1E29C7ULL, 0x8D632E7F9769FB70ULL, 
            0x74D08C8A0B748523ULL, 0x8C1BDFFE806A1945ULL, 0xC4358DAC214BFB09ULL, 0xFBAA26CF301177F7ULL, 
            0x57D735F12BE52A13ULL, 0x2C0E8868A2914730ULL, 0xC3B236BE93970934ULL, 0x62097A7BB9DC708AULL, 
            0x016EACD2B8CF391FULL, 0xB8E1FB01F396E3EBULL, 0x52EFD1DD87630EC6ULL, 0x54944AAC34CC847CULL, 
            0x3C7037360E002499ULL, 0xAF1D1B38165E79D5ULL, 0x84E3277B505DE91AULL, 0x4FCE59D73A6C2BBFULL, 
            0x215D4E05B8DC3AC1ULL, 0xD1A64DBDE911B742ULL, 0x247E983AD843C706ULL, 0x6D4074FA49092F10ULL, 
            0x8F767794991FD7F7ULL, 0x14D4357B95D48607ULL, 0xD29E99AC5A8406EBULL, 0x2EED0D24D692690FULL
        },
        {
            0x82928716037AE448ULL, 0x0E96D3539A50C0C5ULL, 0x0DBD98217EE54E70ULL, 0x4973155A9618A0DAULL, 
            0xAF93DFC03024AB98ULL, 0x3DF3FEA1CA2191E0ULL, 0x1B44DF9158E60EE1ULL, 0x4BB32120D4D90111ULL, 
            0x0F901FBAD812270AULL, 0xD649E68E1D2FE6C6ULL, 0xB10851995573FAE9ULL, 0x840928BC69A86EFEULL, 
            0x8FDCBC750F572994ULL, 0xCB10FDDAC5A44F2CULL, 0xF7F0BFAA901B913EULL, 0x52957004DD9707BBULL, 
            0xABD04E601DC22CA2ULL, 0xA5F9D07CBB00645FULL, 0xFC992430C366176CULL, 0x1B3717506EF5A710ULL, 
            0xE5B23197A79D7286ULL, 0x194F8958FDA10CDBULL, 0x11DAFBFF8B04A9D1ULL, 0xBDB4E40FA7501F0FULL, 
            0xE53C2567CBA4C94BULL, 0x57D9A98E12D2BA82ULL, 0x93CF69D6BFF8B248ULL, 0xA5653EE270B93C55ULL, 
            0x9782C49413B51FDCULL, 0x299181FD8F6A1C7DULL, 0xA55929043205CCFBULL, 0x63A3A50CEB1FAD22ULL
        }
    },
    {
        {
            0x18E8ABFF00578C95ULL, 0xC002437FC55BA250ULL, 0x7B7AA330251EE937ULL, 0x4713B6B86548909AULL, 
            0x2CA59F25DD04F56DULL, 0x67E5C6C943987DC3ULL, 0xD384B287625E7D57ULL, 0xE8BE85DD46670407ULL, 
            0x93006C2081ECB6B0ULL, 0xAC81FF508081C81EULL, 0x04B6CDB449756E57ULL, 0x3A6FC916B2351F9DULL, 
            0xA630A9E67FFC4FA2ULL, 0xABF3008D96CF3546ULL, 0x6492EE4FF970EDE7ULL, 0x34DF34EADE3EC281ULL, 
            0xFB84B2914ECDA018ULL, 0x1163EB407ACFD8B2ULL, 0x6554F8EB6BF652F9ULL, 0x669ED2365B3AE72AULL, 
            0x841E7352576AB40DULL, 0x59D828BB6C2DEA83ULL, 0x57D40DFC1BECCE5CULL, 0xB663A2CE2A0A0789ULL, 
            0x5BD21F77C21310CFULL, 0xB535234BF0A06058ULL, 0x8BE1C31D7819C420ULL, 0x328798B317BEEC42ULL, 
            0xF0F037042B217772ULL, 0x96BA9C894F9322D3ULL, 0xB42EEF029A225AB1ULL, 0xE288AD103F703D88ULL
        },
        {
            0xC540955DF839690AULL, 0x5D37F860F172D9CFULL, 0x79ED42F6367BA213ULL, 0x355E88F1078F3CF3ULL, 
            0x21201A69DB3716C8ULL, 0xE873CBF8CE51DFEFULL, 0x6EB7AC161CC2CAA2ULL, 0xF2122D91FCF66FA9ULL, 
            0x8CDFB71E9F972A5BULL, 0x9CF635462E24D9BBULL, 0x1A7E6B8F33B21D9DULL, 0x4659959C5900324CULL, 
            0x9D3BAF6C63862BF7ULL, 0xB98F3B6B286DC8E6ULL, 0xEF60EFD6AA83B45CULL, 0x78CB46B2082CCA2BULL, 
            0xD4D591B592AA183CULL, 0x2DA8FB1069EB5161ULL, 0x26F9AB179B0E4F70ULL, 0xD061999FF0999BBBULL, 
            0x56CC2C53976FEEAAULL, 0x276D135272C5ED5AULL, 0x5669FDE234CC637EULL, 0xE0CAA0621CE9C4CEULL, 
            0xAB8919267F7AC6FCULL, 0x4C09B15ADF4F83E3ULL, 0x77AE7D4DFE4977E6ULL, 0xA610044DBD30340DULL, 
            0x9A0A09E0B897979BULL, 0x70D26F8C430E709EULL, 0xBA283533C48E74C5ULL, 0x03058500E4D4DB25ULL
        },
        {
            0x41A311939B7713ABULL, 0x13A54EA3F8EB6F24ULL, 0x4D57365521DEA0C9ULL, 0x0BA2650A77771722ULL, 
            0x9F569680ABA6EF3CULL, 0x6318900F1DB20FF2ULL, 0x6D68A897A47C9BE9ULL, 0x3CA0EA84918179BCULL, 
            0xF895E45C826FE5DFULL, 0x0935D049ED6F9314ULL, 0x7F06ADA6BA573444ULL, 0xF5470D2E5C937235ULL, 
            0xBEBC41A44CF1B585ULL, 0x07AB1A6B1FA12C67ULL, 0x6A8B9E2675E400DCULL, 0x697236FDAA758C3CULL, 
            0x1CBFF89EC07435A2ULL, 0xFE6C4F17249910E3ULL, 0xDAC20993E7064162ULL, 0xAE6C483A9626DF8FULL, 
            0x2C3A3EBE76FCBA89ULL, 0x69B49177D0FB47BBULL, 0x68F5B0E71BDC1917ULL, 0x439BA01A8664A263ULL, 
            0x5AFFB7F2886B79F4ULL, 0xD562E9F887CC1D37ULL, 0x1561B19E9673C4C5ULL, 0xA9F82A24DF2C139DULL, 
            0x9DC7D338A6CBE263ULL, 0x6645C30ACD54FCB8ULL, 0x4334F1DC194811A4ULL, 0xBEE3E5CC3693B948ULL
        },
        {
            0xF33827C6D6E9697FULL, 0x829CE4925366EB4BULL, 0xE84B35BE37D5F53EULL, 0xF023351A2062AE83ULL, 
            0x3A8F5061B2E9581AULL, 0xAE63DA8018E1AE22ULL, 0xFAF07798AD658EB3ULL, 0x8695396A0D2F62B5ULL, 
            0xEE5AAADC67F6BB22ULL, 0x17A22BE4EFEC4A81ULL, 0xD1144414F4A86A60ULL, 0xFB2F02311A3F536AULL, 
            0x276C7EF7A908A521ULL, 0x037AE933B569B268ULL, 0x1898914F0618BAC8ULL, 0x4F79AFA1E3655479ULL, 
            0xF712DB332BAE9072ULL, 0xCD1445D5EBA7BE6FULL, 0x8674609302E091E9ULL, 0x1515494E4821F4EEULL, 
            0xCAFEF729462FCD29ULL, 0x64AA838117E18FA9ULL, 0xE099C8C26B4FD0E2ULL, 0x23C6F573F656CC85ULL, 
            0x03B58765BEC7185BULL, 0x146D4EB5864E0BE0ULL, 0x01656713761824C4ULL, 0x4E69E74B6B00C0FCULL, 
            0xE6ED2770F68334AAULL, 0x3F527369B64C04B7ULL, 0x1FC4B8284B1526BDULL, 0x15575CA4473F9453ULL
        },
        {
            0xE0B4D3C48138E722ULL, 0xFA7899689A8684BFULL, 0x494CF567A33C4998ULL, 0xD1C5D9848B709B0CULL, 
            0x2D5DD8CFBBEEED34ULL, 0x8C4F022165EAC4D9ULL, 0xAE6C771499232F5AULL, 0x9F32CA62AD2DCBD6ULL, 
            0x241E8B7118D2ACBBULL, 0x565728AB828AE61CULL, 0xB25EFF58F67D815AULL, 0xF99C688FC80F2573ULL, 
            0x6A83DAE0979D7204ULL, 0x2A68E64EE04AC9A2ULL, 0x9464B9552A8A48C3ULL, 0x7A11BBA7F889C177ULL, 
            0x50A3C17DD7247509ULL, 0xE6776653A3140DFBULL, 0x2384B8DDB8693258ULL, 0x62ACB2939A81CB29ULL, 
            0x85B55DDA43032DBAULL, 0x2A81F0047D4E89D7ULL, 0xBD7D518F62F6B807ULL, 0x40F06043F7A3F86EULL, 
            0x99937DAF1381A89EULL, 0xA5DA0AB35FEDCCF7ULL, 0x9F5F8BB6B2ED90E8ULL, 0xEEB1DE6EE6DB9B06ULL, 
            0x96AC705B0334F2C6ULL, 0x7EA1B43D7BAEF5ECULL, 0x7603FE3758E0A568ULL, 0x654F5641FA6F8F36ULL
        },
        {
            0xF913E37C5D50AF4BULL, 0x99DE86FFBE69F323ULL, 0x41AE05FE66AD6244ULL, 0xF2A0EC44AAE2EF51ULL, 
            0xA469ED03B909BD37ULL, 0x80E6F84921AA6042ULL, 0x282EFCD7FF91CADFULL, 0x6EC49BEE77264D75ULL, 
            0x6EAF6431536D2D23ULL, 0x15FFF9CF8534345DULL, 0x26CF7793476FD2A4ULL, 0xC4521F99561881C9ULL, 
            0x4F7916793CA17822ULL, 0x39CA3523395B6182ULL, 0xD8B34E2D73FC13F4ULL, 0xFFFC440C8587FF86ULL, 
            0x611A5B8D9BA8B36EULL, 0xFD878961F85CB89FULL, 0x6821CC26CB388C53ULL, 0x337870F57E6DACD8ULL, 
            0xBE343433B64D9832ULL, 0x519278C5280F044BULL, 0xB5687F4AF277D5C0ULL, 0x90B373264E6647D9ULL, 
            0x806B257B4311D564ULL, 0x19BE379046E36F0BULL, 0xA128187168CF1EF8ULL, 0xE3E14B0AA13CEC4AULL, 
            0xA67EB51E8942966CULL, 0x28F1A522AF08FBEDULL, 0xD40EC7E17EF7C1C6ULL, 0x386665BF95897751ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeyRotateConstants = {
    0xDB2E7A12C6AF2F7EULL,
    0x522071A1C71A8FEEULL,
    0x2C60844292A94A55ULL,
    0xDB2E7A12C6AF2F7EULL,
    0x522071A1C71A8FEEULL,
    0x2C60844292A94A55ULL,
    0xEE26D7A05760C4DFULL,
    0x3972796B16E4F293ULL,
    0x08,
    0x18,
    0x38,
    0x89,
    0x22,
    0x83,
    0xCF,
    0x78
};

const TwistDomainSaltSet TwistExpander_Vega::kKeySpawnSalts = {
    {
        {
            0xE541BF4DDF89C61CULL, 0xB14E3D946C6358A8ULL, 0xE67B921E61F7CE31ULL, 0x26BD7F0A0E3B8545ULL, 
            0xD5E76734D3AFE00CULL, 0x947841382A935708ULL, 0x37DE9148F6820477ULL, 0xE217D480D2CA0CE9ULL, 
            0xF335EC4B0C0A7DD8ULL, 0x07CA96D79772693EULL, 0x6B498C8B2EE5E554ULL, 0xA51B6C629929FCCBULL, 
            0xA97A5F183F63BDA4ULL, 0xCD17CB2118B5BEA5ULL, 0x03D46E96BE99605AULL, 0x8436D47289063B18ULL, 
            0x72E8B6CCAA66DAEAULL, 0xE505C18E70C2B1AEULL, 0x271EF8D7FD7E3BF1ULL, 0x307F12A20B69FD89ULL, 
            0x6D06A2F5BD0161D2ULL, 0xE64E8AC22CDA460CULL, 0x31CB5229D160B8E5ULL, 0x1C4CB44C17B8265FULL, 
            0x7C08D93B2496B6BDULL, 0xA3A98450FC6DBE1DULL, 0x456451190EDB49C7ULL, 0x88E4B38A38482B3BULL, 
            0x3376404FDD14E421ULL, 0xD28B259FD96383DCULL, 0x59D3AFBE26B2C2A3ULL, 0xF77D6060E8757856ULL
        },
        {
            0xA2ED68B6FB364926ULL, 0x06126AB02D5CCEFBULL, 0x06CBCCDCEEF3DD80ULL, 0x5EF15E76B2DE750BULL, 
            0x88EB8ADA45F966F3ULL, 0xD6C7EE6B66B84CDFULL, 0x4A2768FF4169BA26ULL, 0x47F8BB6D1DFE46DFULL, 
            0xAB28B4AAE3963F12ULL, 0x0EEDCAFE461C8D86ULL, 0x5C73C10FD35DBD20ULL, 0x1F79B31920D6CCC6ULL, 
            0xF5CF5BA541C06F16ULL, 0xCDE8C0B46D0EA2BBULL, 0x39A93863ED65C71DULL, 0xDE9E5AB06D63E2F2ULL, 
            0x3DFAF8A0B27B1B60ULL, 0x7903C600359CE143ULL, 0xDCC9FB0CD931CCD4ULL, 0xDD027B8E09F19EF2ULL, 
            0x39D5305002820B58ULL, 0x08F2D6E12EC6A4D9ULL, 0x49CF1C1B3E86AB7BULL, 0xBBA2112C29F8FC5EULL, 
            0x9ADB2C394ED36C34ULL, 0x223B3F8786E29DD2ULL, 0x47A19A53E0A1E822ULL, 0x0A59133C522B64B9ULL, 
            0x80CB85ADC8A2B679ULL, 0x74982F575CDBB0E0ULL, 0x13F46AEB45C63604ULL, 0x33C8A2A12D64ECD3ULL
        },
        {
            0x030BB40492ED9776ULL, 0x1924DD888AC378DDULL, 0x94F07C82B2332F3BULL, 0xF74D7C34BB89956EULL, 
            0xEC5EED1393B1F4DCULL, 0x9AD50538A3C167BAULL, 0x0BF72E972D7AAF74ULL, 0xD9CE5BFAD846F143ULL, 
            0x791689C21BBF22F3ULL, 0x710DA72C75E35570ULL, 0x5296E6511C38FEE5ULL, 0xB50C5B9ECBA5B308ULL, 
            0xC64667294A622ED2ULL, 0xD2163B25C86C7D83ULL, 0x06934189423296F4ULL, 0x5D570F29582BBC34ULL, 
            0x7091F55FB62B141EULL, 0x192D5C357FAF5F40ULL, 0xB741A710E7BA7708ULL, 0x36C1F279AF4946BBULL, 
            0xCA84C39F6B6C7006ULL, 0x1A8FB116A5E13C34ULL, 0xF4875497638C0BF6ULL, 0xAD3EB91A73DAAB94ULL, 
            0x748726EECB5DB948ULL, 0x5BFFDD1ED8BB1028ULL, 0x5E608E3B6041F99BULL, 0xEC38919544BFD35AULL, 
            0xC612AD8430F3B045ULL, 0xEDC01EA591B1ECDDULL, 0xB117DC7EADE373D8ULL, 0x4ACD3F83F0B50E7DULL
        },
        {
            0xC3AB990571EA69D7ULL, 0x244C3A824C5D1471ULL, 0x1164A1C4C1B3B8BBULL, 0xCEE4ED8E196A8514ULL, 
            0x3570CB146F35F3FBULL, 0x7ED1EA14BAFD4CB2ULL, 0x3BFCDB80902C60BAULL, 0x44B62BFC0906A665ULL, 
            0x32BDDFCAFE30FE9BULL, 0x108DCAC9385314A7ULL, 0x63D8C2B5F6ADA821ULL, 0xD3A6F5D75631BDEFULL, 
            0x96BF82FD44FD5CB9ULL, 0x7C6775FD27317E35ULL, 0x5BBE0D22F9009E87ULL, 0xC32FBC09ED5F6D2BULL, 
            0xAE8B19DA7256B8EAULL, 0x8553CA2371FFF1CBULL, 0x1FB363F9CE159109ULL, 0x271AB3AA850ECDABULL, 
            0xFB914D03F109D6BFULL, 0x03910450D9AA9397ULL, 0x518D4985DBF1410CULL, 0x0A81384EDA75967DULL, 
            0x0603F65476A22BFBULL, 0x6B761FB4B95BE075ULL, 0x226CB69F514075F1ULL, 0xDD30B5D286B94566ULL, 
            0xD43072015E2BE770ULL, 0x56C2BC566DC63BE2ULL, 0xEDCF8B5CF490C09FULL, 0x0A463A3974421F0CULL
        },
        {
            0xF153629AE4F29904ULL, 0xA34854CEED04CF5EULL, 0x06AD1BF350324603ULL, 0xC7F7BD8D4BCE276EULL, 
            0x6887127E182684AEULL, 0xF92CDC0B5030338FULL, 0x35365DBF2E813EC7ULL, 0xA78434BCE0F6878EULL, 
            0x713EFB28456AC10BULL, 0xFA0C3FFFD9AC8C58ULL, 0xFD7835BC5A5C602BULL, 0x9AFFD5F4BEBC88A7ULL, 
            0x0240B5EB9FE1EA12ULL, 0x46E405F271B65F54ULL, 0xA3A8FD33D83DD8C7ULL, 0x1B429B342575FC7CULL, 
            0x5DD1E6761576B8D1ULL, 0x678291D946331CC2ULL, 0x2B79D0F0F0BEF398ULL, 0xDBED3CA7E51DCE25ULL, 
            0x5819320342C3760FULL, 0x68E398E4599C7CACULL, 0xC5DD7A24ADCB536BULL, 0x24E3DCAA45E8690CULL, 
            0x5BE2E3C0715E4380ULL, 0xA74B59A3B72A4B9BULL, 0xE61BB5B3BA255AC6ULL, 0xEC77FA3665A4A054ULL, 
            0x3E4A10F70316167FULL, 0xC75503DA5DA8BDC9ULL, 0x7D76C1294BC83269ULL, 0xB2CE6CD661EB8F72ULL
        },
        {
            0x2E94FEE1F3970AFFULL, 0xD61DC8E535AD1C55ULL, 0x2C99DD201499682FULL, 0xBAA8D5FF7FB5791BULL, 
            0x1511FED42AB5CA1BULL, 0x335D90E3917BCDE4ULL, 0xC7CE78E75909A788ULL, 0xC59352B215FADA40ULL, 
            0x1AF39808AD868F6EULL, 0x7EBFA494D68B356CULL, 0x054412733F672E4EULL, 0xB6186809D04C248EULL, 
            0x29C2296DCED46EBEULL, 0xC788E984E1885F7EULL, 0xFE0A1B6BFD7BF193ULL, 0x110544693B1FA0E9ULL, 
            0x3213B299FAFE24E6ULL, 0x32008F9DC19A587BULL, 0x8CE3E8AF150E8BD0ULL, 0x73970ADD6E00110AULL, 
            0x3640238D0BD3E0DBULL, 0x586498935F491BD4ULL, 0xA1C129825223AC00ULL, 0x5981BED21EB5C686ULL, 
            0xAA05C5DD167635FDULL, 0xA45B7D5006FD35DDULL, 0x3AA13C5505111414ULL, 0x6F39F5A9B9BB0BB3ULL, 
            0x249AAF9A5F8B4747ULL, 0x39CCF49BFF649BFEULL, 0xBAE35747C8999F5FULL, 0x004B1C0BBCD28681ULL
        }
    },
    {
        {
            0x7D0882C30191EE9BULL, 0x41C52F7D7203A51BULL, 0x76CDFEEB062AB6BBULL, 0xCDB8667E2EEE3EA2ULL, 
            0x9AD2AE50C18F2636ULL, 0x13981186D5A58A82ULL, 0xDFEF7F1FD9B50436ULL, 0x5BDF5F894050F392ULL, 
            0x9EF6909A11B96904ULL, 0xA4202F1D0F5096A0ULL, 0x610B9F34E1BD53B9ULL, 0x057C5694C914C673ULL, 
            0x421559E030158FD8ULL, 0xADBB7F966BA71726ULL, 0xAF1936F8D35FEC70ULL, 0xAEC271E824875232ULL, 
            0x507F2FB4C4A67981ULL, 0xF528435561B31FB8ULL, 0x2A973C6F6802950DULL, 0xC148E952F2010812ULL, 
            0x341569CD35B069B7ULL, 0xDB06CCB3DC79AE72ULL, 0x4DC3CEBEDA9B7367ULL, 0xA639C739999E21F5ULL, 
            0x2B16FA0CFFDBA38FULL, 0xD5982A1FF1314286ULL, 0xA14FBBCA7DC60808ULL, 0x5EC60C188E36BEBBULL, 
            0xCC8BF3B4C71FEAE2ULL, 0xC4ADBA86148427E5ULL, 0xDFD73BF27C800B2DULL, 0x19EDB708537E3A56ULL
        },
        {
            0x4B5A44F858B43206ULL, 0xD92877BC937B5EA5ULL, 0x99BCD74ECB1101F1ULL, 0x04325C1ED33A2F6CULL, 
            0x5A0AC30C97F7ACDAULL, 0xAB7B41D4573BA042ULL, 0xA4EC4CEE83963C4AULL, 0x1F14321F7709C6A1ULL, 
            0x0A0191F2198B6B74ULL, 0x9B2B23A2AFE55900ULL, 0x8C8F6BAC3CAD85ECULL, 0xA190E23257CBAF08ULL, 
            0x54539251052D67DDULL, 0x84831B1229C76BEAULL, 0x574566CBFFDDF889ULL, 0x635A8718B78FBE73ULL, 
            0x956A1523985AD066ULL, 0xCB1D68BC921BC59EULL, 0xB387DD94A9ECE1CDULL, 0x624EDA1535FC65F3ULL, 
            0x30F45C8A7AADD12EULL, 0xD5B0CE401D834B58ULL, 0x1CA8B68DF8FC0225ULL, 0x1125E4B4F7F18BA5ULL, 
            0xD7F61E86DBFE7845ULL, 0xCBC0B853FC69A5A2ULL, 0x32649D1C848EE873ULL, 0xE972823BF2CFE807ULL, 
            0x9CB2647D5AD0EDB1ULL, 0x7A0433BECEF2CB03ULL, 0xB7B8623B9CE7B19FULL, 0x29DCDAD6CF9B44CEULL
        },
        {
            0xE1082FE7B0F33D9CULL, 0x94CCC6608A8560B2ULL, 0x3F93297A7915A781ULL, 0x87966F40E3EE9478ULL, 
            0xEE8924F3E2E35007ULL, 0x76856965BF087665ULL, 0xADFE5CC6337FCA3BULL, 0xBEDA452D0A8F1961ULL, 
            0xB944A9AC4BEC8828ULL, 0xF355A890C4AD17F8ULL, 0xD9788D7A6A48C92FULL, 0x03F3DA8EB1EA1F6AULL, 
            0xE4BF4B8C0DDD5B14ULL, 0xD81B1504AB2BE746ULL, 0x1407B9B46DD4E70EULL, 0x1DC93BFAF9B70760ULL, 
            0xD3B640A0BB9ADE7DULL, 0xBF79DB122C08FD2AULL, 0x777AAA06E2659BB9ULL, 0x565D61C93B41A42BULL, 
            0x9E8498125C2ECBFBULL, 0x52AC883B9BCE12E3ULL, 0xFDB4529FDF578AA1ULL, 0xB98701589BEB57EBULL, 
            0x28FD094BA994EAE5ULL, 0xB0F87C70BE05B3CCULL, 0x99C0314B1B1A26A2ULL, 0x93FA00426F0CE105ULL, 
            0x9FF4CD75017D4F8CULL, 0xEB08B4ACBD802725ULL, 0xB7B8A5EA8B27ACA1ULL, 0x8D5EB6C59137FBD1ULL
        },
        {
            0xF8CCE93EBAB01AB4ULL, 0x7249F3CC44F063F4ULL, 0x7E6EAC4259C84A5CULL, 0x49537C58A6D6E63EULL, 
            0x1D22EA39A8B2FCB7ULL, 0xA5F5C796ABE03A9EULL, 0x484756EE41D4FC9CULL, 0x334EE2629936D971ULL, 
            0x21CDA5E7C0C02DEFULL, 0xCA173F35C6CC5582ULL, 0x71371C4257AFBEC6ULL, 0xBB31DF4512536097ULL, 
            0x4F9D4C3D1C950FE7ULL, 0xD5CE5795971B4FB1ULL, 0x72C713212AE4DE02ULL, 0xACCDEFAC0E1C0D9CULL, 
            0x48158494AB0F1381ULL, 0x3AE5D34B3C32CB40ULL, 0x2D27EF1E8DDF27EFULL, 0x577B2349187739B2ULL, 
            0x6B00F4C561B4DD5FULL, 0x27EBBA2327D88C6BULL, 0x5471FAD03655B012ULL, 0x6EE13589560E1E28ULL, 
            0x7CF567A6B14D37EAULL, 0x5BFCE0779E9E1AF9ULL, 0xFEFBF2BCA0A2E4A6ULL, 0x8DD8898105B1D6D4ULL, 
            0xED6C3327602B8888ULL, 0x8F1C65F6F7C2C7BAULL, 0xA50E0E753825B6BCULL, 0x00A53B7362E7DED4ULL
        },
        {
            0x0CF061124CEB87A2ULL, 0x92902D39A0EA74A4ULL, 0x56D45ED78B255B86ULL, 0xB9EE98156F9BF657ULL, 
            0x4E6612F7B03E9BCEULL, 0xD59D71799A239C82ULL, 0xF37A6D4792B64E08ULL, 0xD1CC20AECA693FAAULL, 
            0xA87D830652152465ULL, 0x9D1BB01F74B7EFEDULL, 0xD398DD62868DB94DULL, 0x31B05F7435DF6F40ULL, 
            0x2587F169A2D26696ULL, 0xB3C9D001A2B4A6C1ULL, 0x6A481F27E10CBCD5ULL, 0xAA9775F75B712DFAULL, 
            0x224AD2C1DBDD9830ULL, 0xB747CFCB8C3C7A99ULL, 0xD38D8D3392EDB6CEULL, 0xD17FE71C8CA99BCFULL, 
            0xDDF91B81FDBD7575ULL, 0xCCF1F299C3557623ULL, 0xBAB6325E8C34920FULL, 0xE1936D186645D065ULL, 
            0xD2F1E2563641D51CULL, 0x0F808133E7B2A8B3ULL, 0x953C653BE8FCCAAFULL, 0xBC07F3F420D5D4ABULL, 
            0xEEAAA962042F0F33ULL, 0x82BB1B2DF808D13DULL, 0x2C792FCB86FEC476ULL, 0x3F900D3C7DC10839ULL
        },
        {
            0xEF99394C8D7F1ADFULL, 0xABEC6DDFB7A5326EULL, 0xADB3DE7DD9CFA2E8ULL, 0xCFE6BAD8595D07ADULL, 
            0x1624AB2202312C14ULL, 0x2D822A6AF71CEABCULL, 0x8F8575DA89AFCF3EULL, 0x3C26B946AF77EBB5ULL, 
            0x1E9A9C0AFFB961E2ULL, 0x899F3A1F20667301ULL, 0x1C6CD32692BF5976ULL, 0x366BFA5100A54861ULL, 
            0xF602EF77B2A8E9D0ULL, 0x5CF39560F8273EF5ULL, 0x803370B74C66BA85ULL, 0x20D1C1EFA3A57560ULL, 
            0xCC357CC414C6C5E0ULL, 0x006FBD9A964F6154ULL, 0x50E1A1C594A72F77ULL, 0xF8E9B916DFE34DF2ULL, 
            0x41DCC5D83547EEFFULL, 0xA406763F708B9CD4ULL, 0x2D59162963C15B38ULL, 0xB002A3E82860FA18ULL, 
            0x105FDCDCCF131501ULL, 0x5F3426ED3BC38F61ULL, 0xD5ABD5A4C504D590ULL, 0xFF5FAFDD6D0FE63AULL, 
            0x50F2D820489F4EDDULL, 0x77F4EE41D5A1EF3DULL, 0xF09B12A9D20EB6BBULL, 0x97965E19B146692DULL
        }
    },
    {
        {
            0xDCBD34F07A7814FFULL, 0x81DFAB4AB29A894FULL, 0x74A6D9B909833CB2ULL, 0x10CA14A76D075208ULL, 
            0x8CC9F53277761CE1ULL, 0xBCB2530D41836B21ULL, 0x9938E10F8BEC8CE4ULL, 0xF3516F5084FF2B1BULL, 
            0x7321F0C4CF832D70ULL, 0x23FEDA3F6761090EULL, 0x7A35BA91D14BB4E9ULL, 0xABA3F181F6C688BDULL, 
            0xC73E0FAE72955361ULL, 0x247994ECD707D6ACULL, 0x4CB591CAB8AEA126ULL, 0x043E043C8A1C362FULL, 
            0xC8B7F8E0C2442731ULL, 0xC66A3CCAA8486515ULL, 0xC84FD812A25F8FB8ULL, 0x5DF6D4F72D77E894ULL, 
            0x83924F242D6B1A3AULL, 0xD6D4F6BB4E2D8CB6ULL, 0x5865311D8441BE51ULL, 0x16B66E6BA5885709ULL, 
            0x30BADAE5CE192A19ULL, 0x5C5F05CD4E4F61C2ULL, 0x4786AE71339CC80FULL, 0xFF494CBB438627E7ULL, 
            0xD8C3CC00D797AA09ULL, 0x91BF4D7B1836F57FULL, 0xC9EBAF7350C8A054ULL, 0xBA922995E896B043ULL
        },
        {
            0x07F33C8509D31A68ULL, 0xEB44FBA95FBA76CCULL, 0xC932C56FAF52CFD3ULL, 0xB0071AFE2801751EULL, 
            0xD4B1A7486D90D61BULL, 0xB1F34795AED88975ULL, 0xF8C33BE05D8B469AULL, 0x756991C351F23A92ULL, 
            0x4A9EDE7849B5E154ULL, 0xE64F61CB1B9DFB8AULL, 0xBC8F8D7A9315FF26ULL, 0x72B1FA3D5AF60F15ULL, 
            0x6DC183C9D70D6E2DULL, 0xF578AFD3553F97E2ULL, 0xC528E5E94DD00BCAULL, 0xEB18B517EE5833C0ULL, 
            0xFB602ED9FB002986ULL, 0x7A3FC7E0F93C9075ULL, 0x64E7F6B961A21F93ULL, 0x0F982E28EF7E2D93ULL, 
            0xE1AA4F6EC6DB33C4ULL, 0xF39A893FF24631EDULL, 0xC98FD111FBEB289CULL, 0xED60D34C42CA63D7ULL, 
            0x760518EFDEAF97A8ULL, 0x0C51796BAF4C47DEULL, 0xFC03213791D74B5DULL, 0xF7AC1CB3BCE7D41CULL, 
            0x56E07BCE1074D0C1ULL, 0x051B3A65285CC808ULL, 0x19AD4E2F33974A2CULL, 0xF4BFECEADEB8BA83ULL
        },
        {
            0xD62E03433D3307F4ULL, 0xB3BF111684194D04ULL, 0x025E3D7606F13CF7ULL, 0xFA2CD6D0CDB80F8AULL, 
            0xCBAA21A42805C975ULL, 0x4C406629896060B7ULL, 0xCDFFF6A563DEE803ULL, 0xD5838B0F2603CE64ULL, 
            0x13097EA0D73C1A1EULL, 0xACECC4D62DB0A08BULL, 0xAC955E09AD1FD92CULL, 0x75F9C0DC3BC58C4AULL, 
            0x2F570FE190804A5CULL, 0xC621203964F0CC00ULL, 0x84A0C62A59AD045AULL, 0x1E443D4AD267BFF4ULL, 
            0xF23E649B0805FAC4ULL, 0x91E3934BA3C29FF0ULL, 0xFD58D7EB48F706EAULL, 0x0DF489A2857C6022ULL, 
            0xCB5A53146E20E3C5ULL, 0x7CD9D3FA9FA902AAULL, 0x07BE56EB2C8DE5D7ULL, 0x26C169415A474741ULL, 
            0x385D34F2F34BFF4EULL, 0x39D013BDE67D97A8ULL, 0x61AA956CB609FE68ULL, 0xBD6448D7ABA200FDULL, 
            0x5D30A370FF38AE6FULL, 0x522F19126E3FA5F0ULL, 0xEAED4152119DAF26ULL, 0x170D48B272714092ULL
        },
        {
            0x280176F5D422762BULL, 0x26321505BEC15067ULL, 0x18D21BAAD6BFC843ULL, 0x335DFD274BB0E212ULL, 
            0x0BBDBEDA14B27EC8ULL, 0x31402A4F7750570CULL, 0xD2C01F7254C751C8ULL, 0x35BC704252EEF4D2ULL, 
            0x0C120D0E08A58AE6ULL, 0x75090C3565B8BF88ULL, 0x4902D4A8B38F02A2ULL, 0x2332290CC5ABA59CULL, 
            0xC268223C1C5A59B0ULL, 0xF2CE8DD5AE5A0807ULL, 0xA9703812B845FF0CULL, 0xDF90E794344C46CDULL, 
            0x6AF267E60616D93EULL, 0x36E5866FE3CF5112ULL, 0xF193E1450881BDFAULL, 0x58DD8AAE56C1D1C5ULL, 
            0x5EBC5E1F7F6CF2FDULL, 0x6DE5FEAFDFC10200ULL, 0x5C79337C6EF786C3ULL, 0xB85EF34D550EA709ULL, 
            0x6B34B8027E2EADACULL, 0x6C27D851095DEE95ULL, 0x5ACBFFCEBCCD1740ULL, 0x6260A7EB31A2FE95ULL, 
            0x8A0F787FE5C26E40ULL, 0x20F2265F8AA3BDB8ULL, 0xAE2D50E17D8B5CA3ULL, 0xC7C178BC402D4627ULL
        },
        {
            0x36B810EA4399FEB5ULL, 0xA5F708CEB6476CCFULL, 0xD4FDC3FDDB6DB5A5ULL, 0xCF4E54600F293C23ULL, 
            0x3F78173041816D78ULL, 0x47237E7B90B811C9ULL, 0x68204A61E10FCDEDULL, 0xE1B2265A611CE4FFULL, 
            0x453DD85FF08D8290ULL, 0xAEA62FC7B4C32F9EULL, 0xE23639E215178C45ULL, 0x58C769A8A1922640ULL, 
            0x8B652E8CF7215C1BULL, 0x2C0F76C69316C094ULL, 0x76D7FFF89B038187ULL, 0x2F3F8997F8D5FFBBULL, 
            0x409698A014E39E3CULL, 0x53D9048504D99509ULL, 0x05F3441AD99226C8ULL, 0x67B5B65258795AB3ULL, 
            0xB6AC71842D6A03EAULL, 0x44D7E25EB7D71A57ULL, 0x4F4F9A4F568B313EULL, 0xDA35E8DB7BBB15B4ULL, 
            0xB658B42338DC1666ULL, 0x28447351A29AA2E5ULL, 0xEFB3D1CB1D3E7033ULL, 0x5784C57A866ACAA0ULL, 
            0xD382A3D88C0C8470ULL, 0x1B79952F42144798ULL, 0xE630794E15AD56ECULL, 0xBB04C7FEBD0CFA23ULL
        },
        {
            0x0FEC0E88F5032B77ULL, 0xBF1E069604E14912ULL, 0xE45788878677DA7FULL, 0xFB3FF527DA38BA50ULL, 
            0xDB7524DB472D180BULL, 0x586AD6E038C47A8CULL, 0x548429D4DA119E06ULL, 0x01BDE0C1A1453CF1ULL, 
            0x7E0B2BC9FEABA986ULL, 0x035A11F67F63390DULL, 0x3B391F471BEBE2AFULL, 0x5805D0FCD5030E45ULL, 
            0xB00EE61D25C3A8D9ULL, 0xB5B5A48975C8A59BULL, 0x95CD5BF496519869ULL, 0xB0F8F2752603DD2CULL, 
            0x133CDA958F7859EEULL, 0x52DD09B0FC1A9EDEULL, 0x87243223D0338CFAULL, 0xB693A0DB5399325FULL, 
            0x8D9C1736362EBE18ULL, 0x98648DF71969A766ULL, 0xADB782209157BC45ULL, 0x4AFDD970C12AA291ULL, 
            0xC7708E54087C9E5CULL, 0x0EC834CA209B753AULL, 0xAC8508FD1E642D50ULL, 0x6AE2A54660FAECD0ULL, 
            0x52BE5975E2296748ULL, 0xAFD2487B18F858B0ULL, 0x3D595A30C6C4CB4BULL, 0x3F64AF5F93D0A792ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeySpawnConstants = {
    0x7175D2BD09597F98ULL,
    0x45118003AD160DF3ULL,
    0x76A8F1FAE29648E2ULL,
    0x7175D2BD09597F98ULL,
    0x45118003AD160DF3ULL,
    0x76A8F1FAE29648E2ULL,
    0x34997FFBEC2C9424ULL,
    0xD874769852ABCD2BULL,
    0x1C,
    0xED,
    0x97,
    0x96,
    0x39,
    0x38,
    0xB9,
    0x94
};

const TwistDomainSaltSet TwistExpander_Vega::kSeedSalts = {
    {
        {
            0xBAC98867617C36A0ULL, 0x0AB5B1DDDF9A4D05ULL, 0x09E4B2A7C4C3C349ULL, 0x0D1EB036D659638CULL, 
            0x2067483E095EE173ULL, 0x9FC1CE557C87F782ULL, 0x5B2FBDF8DED93F23ULL, 0xC530182DBE94EF29ULL, 
            0x02A9316EDBEFAF56ULL, 0xDB62F4971BA57B97ULL, 0x933BEDABAED30B47ULL, 0xAEF59BC2719809ECULL, 
            0x27728879A2CD48A1ULL, 0x6EB91A0A27A7CCFBULL, 0x4C3134844224F401ULL, 0xEA2A1C7A88794FB9ULL, 
            0x187AC2D1DBC2AD81ULL, 0xD7F6D7884665121DULL, 0xC6416462F120BF66ULL, 0x7FA9B4E77C498949ULL, 
            0x9082527AB3052D28ULL, 0xC74BED370D524104ULL, 0x7CC480C3B58B5E86ULL, 0xFEBF0FE9ED45EA46ULL, 
            0x552A950D6D95A958ULL, 0x776A24684EBC057CULL, 0xF4B7503B8DF87512ULL, 0xD22811E504FD8FEDULL, 
            0xB6238FE0034097F8ULL, 0x93F21C15D04C6984ULL, 0xC9C8A1A97AABC344ULL, 0xE09C3DB2B7507AC5ULL
        },
        {
            0xB824B7B8EF638315ULL, 0x66691A19F6B984EBULL, 0x8F698ECF6D3DE095ULL, 0x4D6CDFB7D632BB75ULL, 
            0xAB3AFA27FE5B0C6FULL, 0x0C38BE095A64806EULL, 0x17EC80EE8474C362ULL, 0x0B8AC6605B9F076CULL, 
            0xED2727F2C4FB9C4FULL, 0x3B03DB6CD20B7448ULL, 0xAF0A1B1A1B1F3FC0ULL, 0xD9D6A59D76E6C948ULL, 
            0x499819D0D664D316ULL, 0x998EA51BE9C95A50ULL, 0x99E3239F72FBE564ULL, 0xDF754E83786E5ECCULL, 
            0xB7BBABC008FC0149ULL, 0x57C69A2C1D6DB895ULL, 0x1758FA09D2C70BF0ULL, 0x9F7E4871179FD8C0ULL, 
            0x0250188AE7FD98E0ULL, 0xDA9CBD8324B5C63DULL, 0x3CD1AC9084359D99ULL, 0x305E27B8BD57C88AULL, 
            0xE62DA7D827C142A9ULL, 0x7795B69498954C9CULL, 0x119959ECE7EAF613ULL, 0x81C140B53E700317ULL, 
            0xF976BA7CFD24597AULL, 0x0420F95784653918ULL, 0x004A8D888142480AULL, 0xD64A5E30AC710026ULL
        },
        {
            0x5B729C744B7D7647ULL, 0xF648D9E37059B109ULL, 0x08A88D294108BFFAULL, 0xA52DA27A362B74C8ULL, 
            0x15C3552302D333A7ULL, 0x28BD71E17FD0A74CULL, 0xB45DFC6C1FD4D42EULL, 0x8C3D2DAD7F794673ULL, 
            0xC90B178834B131C0ULL, 0xB5D5C0F944AAB72BULL, 0x98B071FD408C55DCULL, 0x7B8A69F6FE8B6E6AULL, 
            0xCB3443FA76770223ULL, 0xD63A130705A5861AULL, 0x26B5D996D07BB37EULL, 0xD0D2824A4D4E4397ULL, 
            0x6D62525943C7735BULL, 0xD8AA04001BC9F730ULL, 0x92EB562544FEE550ULL, 0x79AF8DAB0A132B3CULL, 
            0xE7C77DF685EA111EULL, 0xB7C1597C8F91EB5FULL, 0x86DE2F61298621E6ULL, 0x9A46260D6D93D2E9ULL, 
            0xB285F394EE1F76FBULL, 0xE6B5A268E12D0712ULL, 0xE80E54DCF8F89051ULL, 0x0F4BC5CED39E3E79ULL, 
            0x0FDE65DF36FB8EDFULL, 0x6267158230937741ULL, 0xCFBCF5FC81616402ULL, 0xCB34D92FBA21CC82ULL
        },
        {
            0x36F0E26476FA5A23ULL, 0x863946D12876300FULL, 0xDBB6ACEA825F0E31ULL, 0x2B119FD1D41D0737ULL, 
            0x0BF477C85DC9CA39ULL, 0x41DA4A24E58E6D06ULL, 0x6F9A054D2AD0AFC8ULL, 0xCEE0792F6094C403ULL, 
            0x39250256C61033DDULL, 0x4039306767245691ULL, 0xB3719994832AD612ULL, 0x5CA623027BF05EC6ULL, 
            0x9C1E20E4D65895FFULL, 0xED8FEFCDD233AB2BULL, 0xFE0D816E11B3A661ULL, 0x301EE7A0833E0F6BULL, 
            0x7B19403A43AD1C0EULL, 0x7613023E64E4EEC6ULL, 0x8F0D691CAE9E330AULL, 0x6EB4782F0774DD2AULL, 
            0x4E87A97F307BAE17ULL, 0x036048DD01E38D40ULL, 0xAFBBFE1D419A426DULL, 0xFAC5C2D802021B8DULL, 
            0x9F8DC30410FA7465ULL, 0xB2E4398F489AC588ULL, 0xC82576E3F014C95FULL, 0xD0BDB17808A92D9CULL, 
            0x4AD3A57FCB8CAED0ULL, 0x5B5F49B931DBD45EULL, 0x4585942A6995CDC1ULL, 0x806D4EE1BCD2E942ULL
        },
        {
            0x649CEC58BE415BCEULL, 0x9E8A8940A5B8DF01ULL, 0x68F859701435B704ULL, 0x4C95D3FAA84D73A4ULL, 
            0x36DE30A622294DE1ULL, 0x9D63E53A3EB50F43ULL, 0x17C6174E95EA656AULL, 0xADEC77B26D784DEEULL, 
            0xB6E6A1F61A9CB243ULL, 0x85B18401980E14C1ULL, 0x70795331D5526644ULL, 0xD4F6847058C48C1AULL, 
            0x78922E817B7D5163ULL, 0xFFB68C33D2D4508EULL, 0x8A8C50E55DF5FB99ULL, 0x8037B1C9A80E636EULL, 
            0x041209463DBB98F7ULL, 0x2194B221F54A9B90ULL, 0x9616192710C01DD3ULL, 0x368D7D4646B560F5ULL, 
            0x9FFB9DC97D38133CULL, 0xE863AF879588E060ULL, 0xC58593ED4B8B79B2ULL, 0x9835C2BAE662193CULL, 
            0x2D7DD75EB6525ED0ULL, 0x5515BD34845F9871ULL, 0x56B669124CF49559ULL, 0x48E50E4025317BF1ULL, 
            0x3D9F66D12C65009CULL, 0xA7C98127E2FD657CULL, 0x6370D10F13DD2E91ULL, 0xC9336DA48CE1FAE2ULL
        },
        {
            0x126A23DD36F622DDULL, 0x85ADAD6B56E78A7BULL, 0x64C007F924066F68ULL, 0x990C3DBD4BCCBA22ULL, 
            0xEDF15966F91A97E8ULL, 0x1529997D1F440CC4ULL, 0xDB2AD986162EAD87ULL, 0x7DFEEAF47E693383ULL, 
            0x2FFD990495322C72ULL, 0xD7F8EBDF365B5202ULL, 0x7A1F58FD4EF69620ULL, 0xBD145BE7ABA35FF8ULL, 
            0x247415F224F973ECULL, 0xC7900F1DD809672AULL, 0xB7B49989DA130230ULL, 0x82A24E5619C958EFULL, 
            0x314333793E21F3AAULL, 0x73E8EA6358C83732ULL, 0x307F43C1D9346B6BULL, 0xC6A5190BE5A1533AULL, 
            0xAF8758E3F12EE01AULL, 0x8155E7E9880E8B3AULL, 0xC9D59133CBC99EC3ULL, 0x9702396B0F168402ULL, 
            0xB46DDDBB2A2D1223ULL, 0x51A8A89314E2798EULL, 0x529763FDC4A321D5ULL, 0xF258210E25447608ULL, 
            0x19B08785615ED197ULL, 0xB4EFACA3A4B5B269ULL, 0x77555EA5172DD746ULL, 0xB8E322BFA7E7DDACULL
        }
    },
    {
        {
            0x4D1BBAAB38B02E45ULL, 0x42F197353A4C1AC6ULL, 0xC7CC65F4CFF9BCADULL, 0xB96E5CB1A7AEB13DULL, 
            0x2DF840C40FABEB73ULL, 0x1CFBED6E34EF6450ULL, 0xD3D0153B2A9782C4ULL, 0x69FD40360DA97453ULL, 
            0x95C4FF52C601D9AEULL, 0xCEE5CB7CA1AE0B56ULL, 0x07627E29ABA5063FULL, 0xAAD3AA404F850FECULL, 
            0x6813CC9EEA80E183ULL, 0x19201AF0A181A53CULL, 0x1C05AD0A06183834ULL, 0x799A108400F33163ULL, 
            0x649AF1E0914026E7ULL, 0x8A501FD6067F0ECFULL, 0xD52EA717B93357F2ULL, 0x56D7A8E925971027ULL, 
            0xE4E6D1D11919CF20ULL, 0x68739A203D33FCAEULL, 0x931F5E3F92055C6AULL, 0xFC23488A8A065C8EULL, 
            0x96A7F043BB9E578CULL, 0x6F27D5D6A12CD139ULL, 0x93A25A5C273274EFULL, 0xC181ED647A910026ULL, 
            0xB5EEB981D02993D6ULL, 0x42B586DEF3994B7CULL, 0xF341DA91F9334956ULL, 0x49657B2D47EE5430ULL
        },
        {
            0x43828564F48BFF0EULL, 0x6A7CD158B7C1C66DULL, 0xF57F9BF6BF6C7575ULL, 0x73874A3B32B44429ULL, 
            0x28C552A1B73C2B80ULL, 0x541B40B1B974A563ULL, 0xBD45CFBA8B8247C0ULL, 0x9D71DD9C6180A2C7ULL, 
            0x913280560FD502DEULL, 0xA94D054D8EF16E61ULL, 0xFE90489AE0F8DD25ULL, 0x59848D368195552EULL, 
            0x011C9552E8DD8DABULL, 0x34F7309E987CCFDDULL, 0x9430F2D783EDA339ULL, 0x16DFA3B5B89EFFDBULL, 
            0x74181E72EC5809D9ULL, 0xD1582A4EF2DCD2A4ULL, 0xDD65235064729911ULL, 0xE70FF577DCA0E9D8ULL, 
            0x8C9FFB710B5F927BULL, 0x70E2E38303120B79ULL, 0x109C40EE2F8627DAULL, 0xFF5E4408A5570203ULL, 
            0x0AE818DD3F796A3CULL, 0x5A6128F6D6B0339AULL, 0x262B2A834F7D8758ULL, 0xF7D43CD0B4AF7355ULL, 
            0x1F01709E4143308FULL, 0x5B1EE299FE01AE93ULL, 0xE666152581FB619FULL, 0x848739C7E743FF9FULL
        },
        {
            0xB6A66E7BAC8EB557ULL, 0x4FBA3E0FF4811773ULL, 0xE8C3CAB6E595DB29ULL, 0x37A1F753A9ADDBBEULL, 
            0x1CF4EEA18856AA1FULL, 0xD3A05E8E4AB688F6ULL, 0x840E33F41A5CC783ULL, 0x0A84B2B2E4CC872BULL, 
            0xA8114443731CE6E5ULL, 0x24348C4C9DA5732FULL, 0xB134AF88F2679FE5ULL, 0x5C5B949CCA3C1388ULL, 
            0x227AB425AC5333E4ULL, 0xA5C5163B4DD672E3ULL, 0x0AC0BD246C13D296ULL, 0xA6161BF4F800F19CULL, 
            0xEED0EC80FBBA3655ULL, 0xA07CC0049D1259DEULL, 0x653FCE19B31C1E46ULL, 0x14BEC10F3C746AA3ULL, 
            0x3FD179CF764602FCULL, 0x5EE21F1957BF7BB4ULL, 0x86E9713DB8CEFA02ULL, 0x4CA13510D477AD7EULL, 
            0xE4BEC65EEF95301CULL, 0xA87BEE03E988E3DCULL, 0x2888FA2C9EC314C6ULL, 0x4EC538C5A034CED3ULL, 
            0x9D1F93BA29A93495ULL, 0x6F8B563520D703E8ULL, 0xF99B762CC5D237E1ULL, 0x3313D303CFAA1266ULL
        },
        {
            0xA43504A3311575B0ULL, 0x674AF2288BB26669ULL, 0xB334432817D18B49ULL, 0xE3B9A4EBDF4B71EEULL, 
            0x22492D03930DB98FULL, 0x4BAFD2CF6A16A0F5ULL, 0x9B80B7FADC5E9F6AULL, 0x7FFF6389C2B4CC14ULL, 
            0x7A7C797319D866B4ULL, 0x80EF4917518C35CCULL, 0xAD6BC9011EA39244ULL, 0x51507DA21CF19C20ULL, 
            0x9535FE8D131E081BULL, 0xF00235E0DED0A43AULL, 0xAE59A496271F7831ULL, 0x77C2A1119CCE7775ULL, 
            0x2EB0FC372A131406ULL, 0x3B6F19E572129845ULL, 0xE517768F58F5CB22ULL, 0x39064908D90FE368ULL, 
            0x247734E21EC9FB37ULL, 0x3B21ECAEF787F2F3ULL, 0x4B2B0707A27BDD95ULL, 0x7F46AA3C0EF038B6ULL, 
            0x8423FC719AFAD84DULL, 0x4F2AD32E306B73BDULL, 0xBA0CA81FB370A3F3ULL, 0x127B9E375F3B5431ULL, 
            0xE1363D6329320789ULL, 0xD5F272CCD5BCD9C6ULL, 0xC56430E8D21909DCULL, 0x9F3AC59B78772942ULL
        },
        {
            0xAED0A159D783CC4DULL, 0x392F233C6FF5BB8DULL, 0x68E890F7958B4E38ULL, 0x98D1A43AE4DFFEE8ULL, 
            0x1FE691871D7DC31BULL, 0x69BAB991A876C582ULL, 0x55AD6E16F7EBD60CULL, 0x96FFDA1F1709B495ULL, 
            0x7E75551E3C44389DULL, 0xCC522AD174B879A7ULL, 0x6B37602C9555E243ULL, 0xADAAD4FF7ECA6981ULL, 
            0x73BF3DAB848BA69AULL, 0x4FD20BD69486426FULL, 0x20D5E4882736A637ULL, 0x950D8E3E19950BE0ULL, 
            0x03C6C0489B54A8B4ULL, 0x2337934F58034671ULL, 0x25F0D3134DED2C53ULL, 0x1563269E208EA99BULL, 
            0x16CE44A3B3AC29CFULL, 0x2317C1A9523BCECEULL, 0xF2121F4542B02A96ULL, 0xFD7487128D77F923ULL, 
            0x247CDC34BBEC55FFULL, 0x219F219A1940B965ULL, 0xD4BC5B962FA6D90BULL, 0x10DD9ED1EB6989ECULL, 
            0x6CDA14FBCCC66743ULL, 0xC75426EC30B7B113ULL, 0x6F98967CD69F5F56ULL, 0x0CA0BE9695D409CEULL
        },
        {
            0x94803E81A5F6795EULL, 0x4B3AD07532EB73D0ULL, 0x3A4C890B8F7B029CULL, 0xCD1017D7AEA197EFULL, 
            0xC0766BC41489B69FULL, 0x82CE9362B46620CFULL, 0xB051D137E90F6EBFULL, 0x01DC91937C7C1CE9ULL, 
            0x7755297827D11880ULL, 0x0369684323A6ACE3ULL, 0x785D8A59499B2D37ULL, 0xE954A99EFEB6C7A7ULL, 
            0x34BA57C839943ED1ULL, 0x2CD847AB84A1446FULL, 0x3B3912D829838441ULL, 0xE1A83FBE60DD4145ULL, 
            0x552CE848E41935DBULL, 0xD5FC41CA61CE89B2ULL, 0xACC624BC4319724CULL, 0xCDFE50D5CE311A61ULL, 
            0xBFACE8CCE92C135FULL, 0x08C37764A24EC453ULL, 0x775CE7746761C673ULL, 0x53568DD7B98FAB90ULL, 
            0x97F0157FD7978542ULL, 0x1A05EF0B65FC87ABULL, 0xEBC6F06BF641D49DULL, 0x23BDCCE8AEC0289AULL, 
            0xB8DE48F5B79CCB89ULL, 0x3B3A1014DC290B95ULL, 0xA88ADF8A5080CEAEULL, 0xA39FCEEFD0BCE6A9ULL
        }
    },
    {
        {
            0x80FA536D5985C4A7ULL, 0xE27C54EC41E614B3ULL, 0xFB2F4670CAA7B502ULL, 0x9FD162D6ED1EE02AULL, 
            0x640DEFFC6DD8D96FULL, 0x67485227A41008C1ULL, 0x10C84FED396EB711ULL, 0x478A81946DBF96DFULL, 
            0x3EBDF04B4908748EULL, 0xF4BA9E2C2A722C87ULL, 0x54F162EEBB5A5CCBULL, 0xAA38D617569304BCULL, 
            0x267C31AA80CBB24AULL, 0xE3B9612CC5165FB2ULL, 0xEFA4EA54896CCBB0ULL, 0xD8D50D81714ED8E3ULL, 
            0x9A48E3EE7EFFDE91ULL, 0x53BE6D1ED346A8E5ULL, 0x28213C24B39C6029ULL, 0x17CD866C3CEE07EDULL, 
            0xB73BDCB09B0D42F3ULL, 0x73DA94A19E2E5FD5ULL, 0x0DF6E98CA18AB7FEULL, 0x96C50DCDD049E1A2ULL, 
            0xBFAD8D5D00E81B9EULL, 0x384393A2EDDF4D58ULL, 0x736C182A371A81BEULL, 0x732BF2CA7857DE39ULL, 
            0xCDBB1ADF5C0CCA83ULL, 0x30373C102956F7D5ULL, 0x2B05AF7C917FC0B5ULL, 0x065BAEF3A34AB12EULL
        },
        {
            0x6592ADE34F59AC2DULL, 0x5F9175E037301073ULL, 0x256358E0A6F9A3B2ULL, 0x25EA8114B3BA9200ULL, 
            0x6F7CCD53F72EC1DDULL, 0xEA58A7CEF84CC7D3ULL, 0xDDB007208F155956ULL, 0xF2BBE4B41A8A18C5ULL, 
            0x887DA72C957D720DULL, 0x392FC14C9D698AD6ULL, 0x3024AF9F1BC53FB0ULL, 0x593F58B802788C02ULL, 
            0x15D18E43D866AE78ULL, 0x69D05C23FC17327BULL, 0x02FD0CDF6AF0A097ULL, 0x104A3753478DDE0FULL, 
            0xDE2E58BB8A048B5CULL, 0x04EC0233906AC12AULL, 0x305310E6544E38C6ULL, 0x117EE20E058E2C07ULL, 
            0xC727272C97DC1360ULL, 0x7770223C05D9854CULL, 0xB432252699A5BFCBULL, 0x993C96B242EC97F8ULL, 
            0x14DEC36CFF0DDB96ULL, 0xB888FEB6B81E52C0ULL, 0x7917B508B5B56948ULL, 0xBE618BD5A0DB29D9ULL, 
            0x9671F3C25ED5568CULL, 0x800F328425CB1134ULL, 0x9941E7F8F0697655ULL, 0x7FB52975461994ABULL
        },
        {
            0xC7DD3A89AB67D670ULL, 0xC2F75EA3A7CC97C8ULL, 0x5E534CDADB71DCA0ULL, 0x7B43AB808CFD258DULL, 
            0x3133350BA0D6E78BULL, 0xEFF0812C1F689FC0ULL, 0xFB2090CE9D693A8DULL, 0x30316373AB2B18AFULL, 
            0xF3893AB5B56BBF98ULL, 0x2F73B632E30BC07AULL, 0x8075439318A7169EULL, 0x43BDE960E2E203B7ULL, 
            0x7EBE024E7B5CEF28ULL, 0xCAC37366F5FD64EEULL, 0x56B16A73E0B710D5ULL, 0x3ED2A7448964877AULL, 
            0x49CD15FF68B3FE10ULL, 0x34201932227881D6ULL, 0xEC78B92FBEEAEB77ULL, 0x3A523112AA647C2FULL, 
            0x360D93678F4D10D9ULL, 0x9DD797956679B3B0ULL, 0xD8046320112F1A6FULL, 0x2B40183FBB80F4B1ULL, 
            0xB6E4E3A4F93FCE26ULL, 0xD4894B8632FD7958ULL, 0xB71669BE6638A639ULL, 0x214605AAA5C25C04ULL, 
            0xC632ACA467C31A52ULL, 0x5A79276D1137A350ULL, 0x0CFE65DE76EAFB88ULL, 0x9207A66038BC07F4ULL
        },
        {
            0xCB3AD9A8CB8379C1ULL, 0x47DC3A675BD201DBULL, 0xC506FC05A105DD6AULL, 0xDC97B9C2F1139CE1ULL, 
            0xC121384C627D1E82ULL, 0x2056E89249F598A5ULL, 0x5A4920BD05BA88F9ULL, 0xA965A635DAB155F2ULL, 
            0xA95CD8EBDF34434BULL, 0x1693EBD2899688BEULL, 0xD9E78C2D9AA74470ULL, 0x39CEFA6ED5873191ULL, 
            0xF7B7A114A0A1374FULL, 0x1DF7992C1BB4AD50ULL, 0x9FDEAEB659065AB5ULL, 0x62B807B58CFAE40DULL, 
            0x35582D2A592EC7C6ULL, 0xBD1EF5B3EE8625D1ULL, 0x0AA5A8730A33AEBBULL, 0x6907516B28C00408ULL, 
            0x4487CA902BA56658ULL, 0xF0A444A09ADA88B2ULL, 0x290874E6C60E2234ULL, 0xF2D57688A323897BULL, 
            0x38C9DE71E19523D4ULL, 0x1AA622032AFE9D09ULL, 0x0E54A6DD4915F9B3ULL, 0x66CA80277E76B179ULL, 
            0x698D1D25757EEA36ULL, 0x414AF4D05F7B23F7ULL, 0xC553EC1C96D82EABULL, 0x334EB9F682CC2458ULL
        },
        {
            0x222620DE1CC4211CULL, 0x34CF0226C1DF276DULL, 0xE707672CADAEC194ULL, 0x1E91A49DA6BAB33CULL, 
            0x292FCB8A610AF336ULL, 0xCF60520F5F72DC40ULL, 0x663727A3CFB3F512ULL, 0x918F55A484542B8BULL, 
            0xD8D3DB2403F4CC84ULL, 0x8625ED54DB2824B6ULL, 0xC91A2DC66BF4EC7AULL, 0xA038CD80EF3C7808ULL, 
            0x3FEC5EFCAF3EBD0BULL, 0x980BE837BF1E10CBULL, 0x390A4F2797E06A5EULL, 0x956225724FD6C933ULL, 
            0xB48C422764165C4DULL, 0x57D3267EF40413BAULL, 0x85DA478AF788ECB4ULL, 0xEEA32F8F68692DB3ULL, 
            0xFF846A7BD1524139ULL, 0xBD0D10A7B0B9C67EULL, 0x44C753E4A0EAED22ULL, 0x687D03A07F9AF7A8ULL, 
            0x19F9AFA8C0189EF0ULL, 0x1AF1B5B8ADE0AB6FULL, 0xFD3CB8816FC66F5BULL, 0xB43320B9A9E84A2EULL, 
            0x7806F4036F9CB2A7ULL, 0x2C7D7ADB036FE1F8ULL, 0xD1DD07538B02C77AULL, 0x3894366E5D9FF9F4ULL
        },
        {
            0x6745189ABC037116ULL, 0xBB9F62661D441072ULL, 0x3DB759660D55AD72ULL, 0x1E174C6984CCE0A2ULL, 
            0xA811D607BFB1A626ULL, 0xC02CCF80F5338B38ULL, 0xBD837C984F75BDE5ULL, 0x24A04A0AA6003A8DULL, 
            0xF5E54C4F62EA0411ULL, 0x4C80CC4A22554A1EULL, 0x7867715DC4AFEE22ULL, 0x3D350AD0B4074D22ULL, 
            0x3FB587E76D44C0D7ULL, 0x1FA04639E2BDA8A4ULL, 0x698DCA2582B35FC6ULL, 0x1E6ECD405B58723CULL, 
            0x0698468ECE84D749ULL, 0x00DFD42B2FA9CD6EULL, 0x1A935B437F33E90DULL, 0x61CACAA209490DAAULL, 
            0xEA4368B7F41D4DC8ULL, 0xFACB9FF3C960D756ULL, 0x5FE4A1CE206F4BC0ULL, 0xF00F52E20A62C1ABULL, 
            0x8E3393E8C08838B2ULL, 0x2332278BC453B56EULL, 0x63EC0131B7A34D9FULL, 0xA564488200C55E93ULL, 
            0xD4E397798AADE88BULL, 0xA7670D224F4D33CEULL, 0xFB1BF55A258315FFULL, 0xAEE5BF6849380888ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kSeedConstants = {
    0xDE3E4E8B37EA80BFULL,
    0x876CF6F2E69D3022ULL,
    0xDDAF1B2CDC86BEC9ULL,
    0xDE3E4E8B37EA80BFULL,
    0x876CF6F2E69D3022ULL,
    0xDDAF1B2CDC86BEC9ULL,
    0xC7A9E2293B763271ULL,
    0xAFC73356C0160BA0ULL,
    0x16,
    0x82,
    0x86,
    0x56,
    0x9A,
    0x1B,
    0x5C,
    0x5F
};

const TwistDomainSaltSet TwistExpander_Vega::kTwistSalts = {
    {
        {
            0x6525996185634332ULL, 0x9FB7D7E6E0A1B0B6ULL, 0x946EBD8120496879ULL, 0x8F941A3F52462C88ULL, 
            0xFDA26F2496E7AF6FULL, 0x39915834758970FCULL, 0x0FFC88B334B89C58ULL, 0x43445C7C9D404799ULL, 
            0x48BD603F3779CE41ULL, 0x266BA9848793C52BULL, 0xA16C4A12D1F8388CULL, 0x94410E4AA7A4CC87ULL, 
            0x0043704590B6E2A5ULL, 0x3CB31A657AAF5623ULL, 0x1EB45D5521246E15ULL, 0xFC4DC0A82CDF0A08ULL, 
            0x4E396F4CB288DC0EULL, 0x2795A73852623139ULL, 0xFDFA94B107B35EE3ULL, 0x3F482F8A4F0A0739ULL, 
            0x414C77217DEE803BULL, 0xC7D6B409E21DD07DULL, 0xDA0FA9DE5176C920ULL, 0xCB5DBD839249FC81ULL, 
            0x5740AC66051FBB7EULL, 0xCAC7CCE2ADB8BC50ULL, 0x0DE8C8B9B664BFDEULL, 0x46A1439161976EC7ULL, 
            0x716C1D55BC1CB9C0ULL, 0x8BF5F1E4DBD78B60ULL, 0xA3BCE88C5E6CA469ULL, 0x4D18893E9D58C65BULL
        },
        {
            0x0276840F9553A0D7ULL, 0xAAA146CB026F5AECULL, 0x900A5B427A668D57ULL, 0x6EC72E8171B3462FULL, 
            0x61BD2B441DEA3718ULL, 0x6067184C8DAD3EE2ULL, 0x00FB90A58254F9C6ULL, 0x4E56FA914E83C036ULL, 
            0x7A6E34B03BB88C1DULL, 0x7F5ACA652A76D4DFULL, 0x6D02852527E7D329ULL, 0x36B3362B1B1D4B56ULL, 
            0x2A2EDBD2F5E32527ULL, 0x243FE86A0F879A9FULL, 0x823CA084CF0CACD4ULL, 0x2A67628E5849FEF1ULL, 
            0xC80B5043D6B28326ULL, 0x0694204A74E6C22EULL, 0x76EDB8649143F79DULL, 0xCBF6C7D0EA6E7D91ULL, 
            0x69334D9EBA52B843ULL, 0xFD644042820BB317ULL, 0x1080DFD591499BAEULL, 0xDA2E0D39CD386B2BULL, 
            0x0E9DC3668D507B94ULL, 0x3905FB160E891C27ULL, 0xB8336428D5B1F3E3ULL, 0x66DD9F33F3E14F29ULL, 
            0x91D0A4BC886FD227ULL, 0x46D8116A766684B4ULL, 0x0A02EEDD4518485AULL, 0x70C8027930CF4B51ULL
        },
        {
            0xCBE5B8C8D03B9208ULL, 0x0D8B09086197202EULL, 0x5B696E439C72E1DEULL, 0x916E21993EE8EB13ULL, 
            0x561D5C7D662A33D8ULL, 0x3124282BBF82B7AAULL, 0xD0FBB510C97B3362ULL, 0xBF38C64DAFEB13A7ULL, 
            0xB5633A01B7BF8B4FULL, 0xACCC53DA8E8BD93DULL, 0x6B872E4E3CAE4D29ULL, 0x294775777122ACA5ULL, 
            0x22C126B118933DE7ULL, 0xDF8D84560020E44BULL, 0xBAF73BC233F41B2EULL, 0x5B8EA643963D41EEULL, 
            0x4786503249F2FEFEULL, 0x9FB08427D1E075EFULL, 0xE580B793854774E7ULL, 0xE326A8AF31DFFF04ULL, 
            0x4441283BF456CC2CULL, 0xC2E2C15DE6D5403AULL, 0xE24E3C27836F15DCULL, 0x490088E2F874F977ULL, 
            0xE93C52EB778156E8ULL, 0x81F4B9702A15EDB8ULL, 0xFA6E695813A26251ULL, 0x8C5E6610BA98FFB8ULL, 
            0x950A81AADC8B75B2ULL, 0x621B3681B2331867ULL, 0xC5DD9F36DD577827ULL, 0x03AD86AD6C8D92BFULL
        },
        {
            0x494340B3021AC1E7ULL, 0xDDEED3A4AD9635F8ULL, 0x301ACE15ACF0AE24ULL, 0x1396B30875E7CB4EULL, 
            0xC12ECEE54CA92A3AULL, 0x0DB1A9EFE794346EULL, 0x1E097F9E85DB84CAULL, 0x82CE9FC994483E70ULL, 
            0x7B8AFF0A7B365B55ULL, 0x3DD26B5918DBA644ULL, 0x13F95DF5E017D7EBULL, 0x39A2A974FD9C0043ULL, 
            0x7DF90528110F4356ULL, 0x422065E9455F399AULL, 0xFD4E6AD521E0BB7AULL, 0x0D78B972A3513DF0ULL, 
            0x881128980D90AE8AULL, 0xBD8F0A86104887DCULL, 0x0B0103CB5DF0A745ULL, 0x2856473C7648BC86ULL, 
            0xB345A57D5740571AULL, 0x028EA431A218AB9FULL, 0x454343079D0C54BEULL, 0xBF9CD47F36093960ULL, 
            0x908DA9BC4220EA18ULL, 0x0C0293D749AD408EULL, 0x32CD0FB982229C81ULL, 0xA08ED074E05C0E96ULL, 
            0xC59EDCD5E4D42286ULL, 0x5D74AC7A86F2DF65ULL, 0xEAA300FB93E40D27ULL, 0x30443B1A63CEBDEFULL
        },
        {
            0xA1BC92D9A7247445ULL, 0x3EF4F7143DD4100DULL, 0xC285A0507A73C878ULL, 0xD1A0C125ACAD1C8FULL, 
            0xA3807685631A6CA7ULL, 0x63875710EEE79233ULL, 0xAC507EABEE011881ULL, 0x4D06A82D5FF8A1DCULL, 
            0x4FD4AC04984C6451ULL, 0xD5B8CB7394196490ULL, 0xB5ED515B92BA2213ULL, 0x49BB1BEA2A30179FULL, 
            0xFB10C08400DB8727ULL, 0x09ED229BE798B8B7ULL, 0xDF03F2A0CC5DA10BULL, 0xBFD47228AE553907ULL, 
            0x731A6E1104F94A8FULL, 0x0E50DC451508B930ULL, 0xF72822BDF0A17B84ULL, 0x4AECD5C411DB3899ULL, 
            0x47AB41968F14C825ULL, 0xA0ABCE673960F63DULL, 0x32BDDE4C4CC35561ULL, 0x4863941083D77934ULL, 
            0x601112077C608984ULL, 0xFE84CFE61B5BCCD2ULL, 0xEE34D192A113C37AULL, 0x3B7F8928056B1D38ULL, 
            0xEFE67567B0DBCB2AULL, 0x5EED5FB0A9748F90ULL, 0x805A01387E9FF71AULL, 0x524B19E9D4DECC45ULL
        },
        {
            0x1DA5F0F9A6776B4EULL, 0x944263FE732E2AFDULL, 0x54C113F5C310AA39ULL, 0x6371FA41E6B604ECULL, 
            0x6026558DFE7FDCBDULL, 0x1DD5B2D73EF3CA8DULL, 0x17B5BF547EE9C79BULL, 0x4419CABD038576BFULL, 
            0xCEDE81656AEBA403ULL, 0x2C700F62EB81CCEFULL, 0xFD3AEE9299931D06ULL, 0xD40FD2F8790C2279ULL, 
            0xE6548B903C11423EULL, 0x550DE945BBECAAA9ULL, 0xBFDA33BCFF93B6AAULL, 0x8B98531245E5E80EULL, 
            0xF42D5A73A7799D3FULL, 0xE995CDB38D3CFA93ULL, 0xAB35B5278CB290BAULL, 0x84BF537093E1331AULL, 
            0x4FD28393CEFC6502ULL, 0x1A1E20DF7365CEAAULL, 0x605BA19327CEE43BULL, 0x5A1A82F002A731E4ULL, 
            0xA2AC026318105540ULL, 0x2AC601A87D71CBE8ULL, 0x0F97BC164BA606CEULL, 0x427783DA81620B07ULL, 
            0x0561D9B2AEC15F88ULL, 0x1AAF229984B45F7DULL, 0xF35A2A22BA1DC215ULL, 0x1358938C38120867ULL
        }
    },
    {
        {
            0xD0A428D18D96B113ULL, 0xF410F58E5F100D95ULL, 0x00D8F28EEC0D8178ULL, 0x42D9475E03CABAFAULL, 
            0xCF9E6F390BC2AE69ULL, 0xC5A7AB7AD10EF590ULL, 0x1D58AD97CA74EC36ULL, 0x78784DCF9B5D842CULL, 
            0x51CAF89451889362ULL, 0x317F785306B36875ULL, 0x004694F3803D928AULL, 0x42E11D6177F68BCAULL, 
            0x9EC0FFFBCD750F74ULL, 0xA648A673AD85C27CULL, 0x164D87DF03D391E1ULL, 0x5B5203FCC5141D9DULL, 
            0x4B15B7475AD0FF47ULL, 0x735954003E35552CULL, 0xE2200F19A2BF3575ULL, 0x78FC92BF8B0DFC3DULL, 
            0x6CCE071B5417C6AFULL, 0xBF53FD4F82E1EF1EULL, 0x935C10DD0694B2D8ULL, 0x4BA5BD1F41CF015AULL, 
            0xAFC8D6C5D228BC12ULL, 0x2220D30FB5C7D07FULL, 0x8C3D4BF84B60492CULL, 0x24ACAC8049667E49ULL, 
            0xE5F8690174632DBBULL, 0xECE709F9791130E7ULL, 0x8C0B3F3A07D7024BULL, 0xFD228CF2A98E98F8ULL
        },
        {
            0x1BAA487013E11442ULL, 0xA4CC338227EDEC0EULL, 0x7DB38DEB69D9ED2CULL, 0xEE955E8264E6CEF8ULL, 
            0x84378F54B7AFDE59ULL, 0x85CC6E9FA9F03DEAULL, 0x3D3081FFD3B65A5DULL, 0xED20453134954E58ULL, 
            0x4CCA36E1D6482563ULL, 0x38017AF15F6BDD6EULL, 0x602F91ED5BCB4A40ULL, 0xDC858E6B4902C090ULL, 
            0x07823328D3B9BC20ULL, 0x60E62C6E877C491BULL, 0x02C53664FAF806D5ULL, 0xF267B212361A931FULL, 
            0xB1A53FB395F07086ULL, 0xCD8D1BF7CD1F5556ULL, 0xFFDAF83FB2647CD1ULL, 0x670E7DBD28B9CF86ULL, 
            0xAD43D54E175622A6ULL, 0xBA644BE7CCABE2B0ULL, 0xB49125A579DBB500ULL, 0xAE6777EC7B4F5230ULL, 
            0x78DD72CD03F60D71ULL, 0xF403CBCCADF0C543ULL, 0xC11492CC22277B2EULL, 0xEEA65DFFD173A6FBULL, 
            0x87E0088ADB5AF329ULL, 0xF6EDA39B3A91E833ULL, 0x71E7FDAE2B8B22AFULL, 0x59D0D7793783A740ULL
        },
        {
            0x8E2AE8A0B9799C0AULL, 0x4AB20DDD91701066ULL, 0x2938507A11B3B726ULL, 0x83B1040CC1A400F4ULL, 
            0xF644FA557759AF34ULL, 0xA608C4498254CB46ULL, 0xF54F28533E4086C3ULL, 0xE2F9FC343209D868ULL, 
            0xE8CDF2589D7B56F3ULL, 0xDD1E249A5C5D0B2FULL, 0x576AE6F8915E330DULL, 0x418AB9E2F481C53CULL, 
            0x79D2492BC79D4B8BULL, 0xA469CA4235C44181ULL, 0x11784153B680D03EULL, 0x45B1423689F33732ULL, 
            0xBA5FD022944A7D3BULL, 0x36D5D9DDE6A2EAFCULL, 0x49C2D97569A046F3ULL, 0x3A8CC9FEAEAD257FULL, 
            0xAE41C10AFE39B9FFULL, 0xDFD85F2EB66BE196ULL, 0x5067F821AF4D2A96ULL, 0x56082821CD38EF8DULL, 
            0xD02D437A28BC3DFBULL, 0xA86BC39F9336A3E0ULL, 0x89FAB3C2C3C721EEULL, 0xF16AB274D62AA6FBULL, 
            0x8D18EE56017D833BULL, 0x61253D031D0249E5ULL, 0xA8A342D90B26EFA6ULL, 0x67BE5E9A84BEF388ULL
        },
        {
            0x8B2F069D729601B6ULL, 0x72A6CD7D91B3807EULL, 0x71E2C88E59F35230ULL, 0x58E66BF8AA220383ULL, 
            0x5A96DCF0C411FBBBULL, 0xAD03135090BEE874ULL, 0xC3F32C2489C1D723ULL, 0xCAB7E60DB3D6E242ULL, 
            0x1A3D72E299693BFAULL, 0x5314CF595895CB32ULL, 0x026400A589BC1BFDULL, 0xCAC37946003DF835ULL, 
            0x374A970432A43625ULL, 0xE293492704D2A33AULL, 0x791BBCFCF415D047ULL, 0xDBDC3040DF82FDFAULL, 
            0xF9281B1004515547ULL, 0xA0638C45385C29DAULL, 0xFD9BADF672EAED36ULL, 0xA2D62DE1D9708D13ULL, 
            0x4C1561E100E0AD49ULL, 0x0FF9E7D16C4C0F87ULL, 0xB087D1AD5FF24B36ULL, 0x67A50622B6E53FD1ULL, 
            0x6D13EF25FCAA3F48ULL, 0xBEDE86B26E35C510ULL, 0x0C43385F25A07787ULL, 0xA3364A808ADFA816ULL, 
            0x7EE4EAC00EACD6FEULL, 0xCF529C230A37EF8EULL, 0x304C4B3EAD449407ULL, 0x3B1C1DD68F4B128EULL
        },
        {
            0xF1CE955ACDEBD7B0ULL, 0x25AA7C2EB11A48C7ULL, 0x60DFC31E65C47AF3ULL, 0x38D3DD1AE832F723ULL, 
            0x196E5715A6995D05ULL, 0x24285F7045DBD4F3ULL, 0x66BE44C9F6D79465ULL, 0xA75C0127DD11F7B4ULL, 
            0x78C48E1CA6551B86ULL, 0x39A72708C845DB35ULL, 0x122A029FE54760EAULL, 0x3E5B20678F941088ULL, 
            0xAE282FB08BDF5FCAULL, 0xF39DF17C3DC750BAULL, 0xE3E93B94D0FD067CULL, 0x28F98FCABFD8121CULL, 
            0xAE6FC1AE5DD32A83ULL, 0x9252E09A0C3888C1ULL, 0xA4467EF1F6C00296ULL, 0x5F806D3847949A66ULL, 
            0x8BE14730F613A21EULL, 0xFE7C218BDA06FCC0ULL, 0x24742D51A2D5B7EDULL, 0x3CECF2C8865DC1E4ULL, 
            0xFAF64538B58FCFABULL, 0x6343EE0342078917ULL, 0x66DFD63A4D0E1001ULL, 0xC1CC3DAFF2D990B9ULL, 
            0xE3E163CCD19120DFULL, 0x93A6D7D200510F67ULL, 0x85C8E1753EFCA5A5ULL, 0xDFA8E319423E37F4ULL
        },
        {
            0x6D813915E32FB4D0ULL, 0x6E00D5DCA1F9E30BULL, 0x7F1F4DA81B84DF22ULL, 0xB44A999BC7E38839ULL, 
            0x3F1292C0EBB4CB42ULL, 0xF873ABB5DFA30F98ULL, 0xD1BF2D5B02736957ULL, 0x00B7F5A0460E699CULL, 
            0x050D774D47B24DA7ULL, 0x19D7107132D33A9FULL, 0xCFE328714AC9872FULL, 0xF6A3D56A2E5D729DULL, 
            0x70D426319BE1A667ULL, 0x76492C62C1A7640BULL, 0xB57081C7FCC576EDULL, 0xE58C32FA181734F3ULL, 
            0xE98F3B03C1D2760AULL, 0xEB85FA982A130A8EULL, 0x9DB16578244128A1ULL, 0x54FDF60B5D655CD1ULL, 
            0xBF3D92DAC1D2C086ULL, 0x452BF56E04842B41ULL, 0xE6D819AC912A95E2ULL, 0x0DB3B9A30C4213DFULL, 
            0xC03020434647062BULL, 0x7381F7616F2C8695ULL, 0xBC370BD021D70505ULL, 0x6EDEEB1E0BB76990ULL, 
            0x15F204F712D1C0B1ULL, 0x2A9FA438C0199BD1ULL, 0x4DC0EC6B9BB49E04ULL, 0x56C4BAD82F206012ULL
        }
    },
    {
        {
            0x5E06CCA022F42D2AULL, 0x9099CCCCCA1F7475ULL, 0xB74CDB935FA989B8ULL, 0x485A14426306A2B8ULL, 
            0x15ADAE2D417769F9ULL, 0xC895874DC4832647ULL, 0xB1E4BF4C04CF9751ULL, 0x2796CF3EE59105FCULL, 
            0xFC4098769140C411ULL, 0x7A89BA5E40F78440ULL, 0x253615C2C7658609ULL, 0xD4220FE455545940ULL, 
            0x5B46056334051D06ULL, 0xF394A2821EE9DAF2ULL, 0xA8827E4F6863D224ULL, 0xB6B6A271694804A2ULL, 
            0xC83C5D1B5FF0776DULL, 0x7E8374AE26EC98D7ULL, 0x32D67D5D75D9A382ULL, 0xD20CFED20E816511ULL, 
            0x6DDE7581EA75AE26ULL, 0x8E69F150C3390DB9ULL, 0x58E0B41625C74889ULL, 0x1602B75854EDA4F0ULL, 
            0x91236C679E40F731ULL, 0x0BBFBD1C70100483ULL, 0x05FD2F95001A4E9DULL, 0xF929F0A0770F1F7BULL, 
            0x5938F5467F8A47B1ULL, 0xD9159B62A4D75A20ULL, 0x07D4B890C5FB3DB2ULL, 0x671A877038D37BD0ULL
        },
        {
            0xEC4F3F9949796564ULL, 0xD62312CAC86C252EULL, 0xEFC823AF2F1E060EULL, 0x02F71229FFB5BC76ULL, 
            0x66E14E138F0BA6E5ULL, 0xA9D82734B8311A99ULL, 0xC4B5D320BC2C19E5ULL, 0x7FE3FA69ACD315EDULL, 
            0x65FFACB90F927D87ULL, 0x6CC8969C95B365ADULL, 0x518BD35193EBA846ULL, 0xBC7F7D3FD75F165FULL, 
            0xB9DBE10762E1F129ULL, 0x1B412F2C3D3EFFDBULL, 0x4E39082ED3DC6D71ULL, 0x23FD1D739BD31E1FULL, 
            0x1932C312BB4B9C9BULL, 0x4529031967014B2BULL, 0xAC894747C35E7E7FULL, 0x0EBE6A8CDC509F92ULL, 
            0x840907A426D59D5AULL, 0x442F422ABA1B9F8DULL, 0x99C41622E02848AFULL, 0xACC4703B8EC4DE6AULL, 
            0xC8878B576EEDA1A7ULL, 0x28951FD92EA49F11ULL, 0x695F8D31D947DEF0ULL, 0x3F191B826ADF8056ULL, 
            0xF13E1701F4902DC3ULL, 0xEDD698E3F69C7B85ULL, 0x3C6F9FE5C80A7F38ULL, 0xFC61FDFD6C8C2BBCULL
        },
        {
            0x3C0F8923404BFF18ULL, 0xC531210517FF5317ULL, 0x8E77009C77342DC5ULL, 0xFF79DBABFA1997BDULL, 
            0xB29D8BED5E126D54ULL, 0x1DC1D5FDD56CBBBEULL, 0x1F3F125651CA6DB5ULL, 0x0DD1EEF75BFA3FA3ULL, 
            0x6A5958A36DC0B59BULL, 0xEC71F30B98C11CB8ULL, 0x9471F9B3A47D85F3ULL, 0xFAA99B77EC048DF1ULL, 
            0x8175A17E299B82DBULL, 0xE7B4341C9C7863A3ULL, 0xF04A0CBFE7B57250ULL, 0x82D8563709AD043CULL, 
            0xA9B8F69776C2A0B7ULL, 0x30CDB9E960C8F1B4ULL, 0xFE0DC6B4FC6DBF27ULL, 0x619BC743CA4B3446ULL, 
            0x64462C9182C8A0EDULL, 0x2A4EF98917A70494ULL, 0xF57D347B2853836CULL, 0xC7AF2D754B807446ULL, 
            0x3AC1BCEA765A53A6ULL, 0xFBCA5379983A94BFULL, 0xEDE18D6161CC4713ULL, 0xA05B63D80A75A363ULL, 
            0xC3E30FA4E1492FA9ULL, 0xFB279E6EDCE4ED5FULL, 0xD17B6797DF976878ULL, 0x9014612C531CA3E5ULL
        },
        {
            0x7F02440623FE264CULL, 0xB7CC071A6792FF87ULL, 0xEA718581C57F0CCEULL, 0x82A220441DC764EFULL, 
            0x13F0EAECB0AC6166ULL, 0x14453BA70409C0F2ULL, 0x0FC2812E05EBA6CEULL, 0xD8AF81BE96400BC6ULL, 
            0xF5CC39F4B4053FC1ULL, 0x8F8A97B34F7DF5FEULL, 0xA2D05DAE407F2FEBULL, 0x8C4D2079DD04E1C3ULL, 
            0x51EED16B5E88A9C7ULL, 0xD3984717F31B0F34ULL, 0xFB5720369DD0BD40ULL, 0xAD4086C71363828AULL, 
            0xE806C672D76476E4ULL, 0xF973357B4BD9A73CULL, 0xE2C68546BB334DB0ULL, 0x6D20FBB6EEFA5F01ULL, 
            0x43544BACE4D2A688ULL, 0x9DC4F67A56DC9143ULL, 0xA201DCAD2EE28AA4ULL, 0x9EABDF373993CE49ULL, 
            0xA3AC7A35ABE579D1ULL, 0x363C07B39F7ABE4CULL, 0xCAE8008093A48760ULL, 0x78C8E2350707227DULL, 
            0x00A939EC38529FADULL, 0x4FBDC102BFEFC53FULL, 0xAB33FB3EEA80DD34ULL, 0xEB6F2C2A4B1A322FULL
        },
        {
            0xED199B49E1ECE336ULL, 0x6BE1EB839346CA1CULL, 0x6BBC0CE79597FEEFULL, 0x7287E39E8E56BBE9ULL, 
            0x9C603344E1C234C2ULL, 0xF2D8F5EB38427A18ULL, 0x7A2A981CA419A568ULL, 0x5A66C02AD6EFDC9EULL, 
            0xFBBD497B30B4E041ULL, 0x4BA02742D6C54AA7ULL, 0xAE91CCFE1281B1B6ULL, 0x62DB7DEC7C1EA20DULL, 
            0xFA5CF9B1EBE096A9ULL, 0xD23806DE3ACF53C0ULL, 0xCF549DD4CFA3D748ULL, 0x2D4ED7C6DE32332EULL, 
            0x4035EF5B2FB3F47AULL, 0x7C4E845FDA82FC4DULL, 0x11297A8051CB36E7ULL, 0x33812B406CF6359DULL, 
            0xFFEF051BEA1C9CBDULL, 0x5A0A7143F8B5541EULL, 0xC94502000B4C904BULL, 0x167432BF8216120EULL, 
            0x7EADD50F53A8FC4AULL, 0x79156885C8CA6111ULL, 0x8834DF987FBD79B0ULL, 0x40140F14418B2AC7ULL, 
            0x806F38373669064DULL, 0x3D1462E1A15322C3ULL, 0xB8F9E53947D35282ULL, 0x862E9AE38662D12AULL
        },
        {
            0x88C66B9674B9EC8FULL, 0xA7BB76F2A4171197ULL, 0xCD127FF0F7E5F138ULL, 0xC0DBDD1420356A60ULL, 
            0xAD01959E5BC74EB4ULL, 0x7FFFCE7C718F8F09ULL, 0x71EB2B6A0913DB05ULL, 0x2D76C53E21C5AFCDULL, 
            0x0A0CD576FCD37620ULL, 0x57B143C7E6D15990ULL, 0x9FA6EF4B5D144C64ULL, 0x51D1EFBB2B0644F7ULL, 
            0xE29E4768613CD8B5ULL, 0xEF25061C02607162ULL, 0x4BDD6F88389DCF3AULL, 0x8EBE355711AA9784ULL, 
            0xF3160C501EFD12D9ULL, 0xC3619AB903191716ULL, 0x2BE4361E6A234ACEULL, 0x2A3BCA4F5BD83A50ULL, 
            0x3EB37B695DF0223CULL, 0x10A92BAA347A622EULL, 0x1B0CAD61E4BD1B33ULL, 0x567138DBCD838DF7ULL, 
            0x0412347EE99DA0D9ULL, 0x119BB93E95F74F83ULL, 0x1D5302E3F07AAC8EULL, 0x7004295C849E9C42ULL, 
            0x4705B1C4CBA8B1DCULL, 0xAFF2D7D8FE4E1E51ULL, 0xB452DFEBB3E3C4A4ULL, 0x76B8CFD2E7D78878ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kTwistConstants = {
    0x34A4F51834F0117DULL,
    0xD07E58856AC4A5EBULL,
    0x078BB1BC8CE15CD2ULL,
    0x34A4F51834F0117DULL,
    0xD07E58856AC4A5EBULL,
    0x078BB1BC8CE15CD2ULL,
    0x82AE781C142BB9CFULL,
    0xD57562D1C2431B5AULL,
    0x4A,
    0xC1,
    0x8B,
    0x94,
    0x34,
    0xDA,
    0xEB,
    0x5A
};

