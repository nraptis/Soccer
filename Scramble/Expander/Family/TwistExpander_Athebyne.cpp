#include "TwistExpander_Athebyne.hpp"
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

TwistExpander_Athebyne::TwistExpander_Athebyne()
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

void TwistExpander_Athebyne::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE880DD48017DCEE3ULL; std::uint64_t aIngress = 0xCB8A7F29EE13A24AULL; std::uint64_t aCarry = 0xB3BBAC189E08A797ULL;

    std::uint64_t aWandererA = 0x8B45BA6FC95E4799ULL; std::uint64_t aWandererB = 0xD376AE2D97288723ULL; std::uint64_t aWandererC = 0x90D8E579F1B87E1CULL; std::uint64_t aWandererD = 0x928DC3F17A678350ULL;
    std::uint64_t aWandererE = 0x9AD1117789EE7D03ULL; std::uint64_t aWandererF = 0xC8ECC63F314B4C73ULL; std::uint64_t aWandererG = 0x9D6E749B87B28503ULL; std::uint64_t aWandererH = 0x9AA67DA97A811E95ULL;
    std::uint64_t aWandererI = 0xEF2DF6F626394917ULL; std::uint64_t aWandererJ = 0xCDDB756B7E450B8AULL; std::uint64_t aWandererK = 0xDEE4C93BCC0C0BF0ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA52B6BB00CA6DFF6ULL;
        aCarry = 0xEB0700470D9DF5C0ULL;
        aWandererA = 0x876EFA126501349CULL;
        aWandererB = 0xF696B8C880514F69ULL;
        aWandererC = 0xD2AAC79BF81600C8ULL;
        aWandererD = 0xB9F1D4D091012D51ULL;
        aWandererE = 0x9B82ED0E86911757ULL;
        aWandererF = 0x8F328274BD63530EULL;
        aWandererG = 0x854D0054AAE1DDB4ULL;
        aWandererH = 0xE365EB7FB72BD15AULL;
        aWandererI = 0xC8C8B48ED4651F5DULL;
        aWandererJ = 0xCF1DB16B70BB7762ULL;
        aWandererK = 0xD70852498A84DFA0ULL;
    TwistExpander_Athebyne_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE06D0918BD822785ULL; std::uint64_t aIngress = 0x89EE82F4F501F503ULL; std::uint64_t aCarry = 0xC272AD758F92D1EBULL;

    std::uint64_t aWandererA = 0xA42B7F232AF64A29ULL; std::uint64_t aWandererB = 0xDDCD8F7097EF4931ULL; std::uint64_t aWandererC = 0xB6CF7BF64482159BULL; std::uint64_t aWandererD = 0x9A0982B7C92A6EDCULL;
    std::uint64_t aWandererE = 0x8DC0D822EF90309CULL; std::uint64_t aWandererF = 0x81499C1250079177ULL; std::uint64_t aWandererG = 0xBA8D6017B3B9E620ULL; std::uint64_t aWandererH = 0xA96A9BABDDA4A17CULL;
    std::uint64_t aWandererI = 0xF31383BC4561E8A5ULL; std::uint64_t aWandererJ = 0xAB2E86320D89ABDCULL; std::uint64_t aWandererK = 0xA5A45727AE3F2E28ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA51BEC1D26FDAE16ULL;
        aCarry = 0x97E72B29A30CCEA6ULL;
        aWandererA = 0xE49EE387C9FB05D6ULL;
        aWandererB = 0x848B623972786E2AULL;
        aWandererC = 0xBE5D638C685CBF62ULL;
        aWandererD = 0x8FE141C22BA44FB0ULL;
        aWandererE = 0x858CD25B5BAFF80EULL;
        aWandererF = 0xC2DFA81C95E0813DULL;
        aWandererG = 0x9D486D9632BBC522ULL;
        aWandererH = 0xA43EF07482065EC8ULL;
        aWandererI = 0xC266F7648D506D47ULL;
        aWandererJ = 0xEDE4C7BDC25FAFF5ULL;
        aWandererK = 0x8C44C6E6959707D8ULL;
    TwistExpander_Athebyne_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9F13EEB032CCED0EULL; std::uint64_t aIngress = 0xDB91F1F731F6B92CULL; std::uint64_t aCarry = 0x8E0055D61FBE8CFAULL;

    std::uint64_t aWandererA = 0xB2C918925C67F749ULL; std::uint64_t aWandererB = 0xF43740655258A435ULL; std::uint64_t aWandererC = 0xDFEB9445A6B6B56AULL; std::uint64_t aWandererD = 0x9D216B098241A3CCULL;
    std::uint64_t aWandererE = 0xDF57DA5DF590494BULL; std::uint64_t aWandererF = 0xDD4CEEEA57142512ULL; std::uint64_t aWandererG = 0xAE956F25F257A692ULL; std::uint64_t aWandererH = 0xDAFB242EF7EC00BBULL;
    std::uint64_t aWandererI = 0xE8DE6CD4BBCA8B91ULL; std::uint64_t aWandererJ = 0xC268CC269D4BDCEFULL; std::uint64_t aWandererK = 0xCB02D09A9D03E0A4ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8CEB440A1A86F6C3ULL;
        aCarry = 0xCB1F6BC68148E16AULL;
        aWandererA = 0xBAF017376A18B92DULL;
        aWandererB = 0xD5F13AE11615898FULL;
        aWandererC = 0xD250E957BCA7A5F3ULL;
        aWandererD = 0xE7B873A56B43405EULL;
        aWandererE = 0xAA819D9278AA41DBULL;
        aWandererF = 0xD5FAB16776527D5EULL;
        aWandererG = 0x99AE53D88E61B5AFULL;
        aWandererH = 0x81A93AECD3C14C18ULL;
        aWandererI = 0xC26FBDEF81B36551ULL;
        aWandererJ = 0x819977BF5F85917AULL;
        aWandererK = 0xDCC8C1552D68F573ULL;
    TwistExpander_Athebyne_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD5F2579CEAC05F20ULL; std::uint64_t aIngress = 0xB227E7E5F7E60FF9ULL; std::uint64_t aCarry = 0xA3CD43431DE8CA58ULL;

    std::uint64_t aWandererA = 0xB07BA323517042C7ULL; std::uint64_t aWandererB = 0xC6D7865F63C31362ULL; std::uint64_t aWandererC = 0xAB3379E730191BC9ULL; std::uint64_t aWandererD = 0xC3796BA6D9D8B89DULL;
    std::uint64_t aWandererE = 0xA2AE22382EEC823CULL; std::uint64_t aWandererF = 0xBA7278569E731704ULL; std::uint64_t aWandererG = 0xE8E2FA1A74A542ABULL; std::uint64_t aWandererH = 0xD1BDD8894FF85EB8ULL;
    std::uint64_t aWandererI = 0xC8E5EF7A0BFCD4F2ULL; std::uint64_t aWandererJ = 0xB4BC16012DBB135CULL; std::uint64_t aWandererK = 0xF325700B26C8A43BULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x98BC7C5CB8E45EB3ULL;
        aCarry = 0xA08E95FE04415478ULL;
        aWandererA = 0x86CF4BAFE3522DC4ULL;
        aWandererB = 0x9C555384E3BB121FULL;
        aWandererC = 0x9D85A9F51A0E7059ULL;
        aWandererD = 0xB77242F7B1050A20ULL;
        aWandererE = 0xB82AF3E2017EDEABULL;
        aWandererF = 0xD21B9875523DB26AULL;
        aWandererG = 0xBAC6B2E45E6D97DCULL;
        aWandererH = 0xE5834F61AC20B1D3ULL;
        aWandererI = 0xE6560F5620BA7A4EULL;
        aWandererJ = 0x913934F6409C1B45ULL;
        aWandererK = 0xA22418BD8B662758ULL;
    TwistExpander_Athebyne_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Athebyne::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC310E52C773ACD37ULL;
    std::uint64_t aIngress = 0xF8BDA486C696121EULL;
    std::uint64_t aCarry = 0x962C8D27F641D984ULL;

    std::uint64_t aWandererA = 0xA7EA604488BD3E16ULL;
    std::uint64_t aWandererB = 0xF718C541F05EFB19ULL;
    std::uint64_t aWandererC = 0x923030299947158DULL;
    std::uint64_t aWandererD = 0xED02B8289F5E1004ULL;
    std::uint64_t aWandererE = 0xE4168CAFBED203C0ULL;
    std::uint64_t aWandererF = 0xD13F5172A9F8C4E9ULL;
    std::uint64_t aWandererG = 0xD2411D7AD4D9EC78ULL;
    std::uint64_t aWandererH = 0xA37F6264CEF72C3BULL;
    std::uint64_t aWandererI = 0x8D8D4F1922255CEBULL;
    std::uint64_t aWandererJ = 0x99BDE45B18276F7AULL;
    std::uint64_t aWandererK = 0x87B65DDE826CC8B9ULL;

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
    TwistExpander_Athebyne_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KEY(pWorkSpace,
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

void TwistExpander_Athebyne::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF2038DF5607DAFE5ULL; std::uint64_t aIngress = 0xFDB4FA073CEA234AULL; std::uint64_t aCarry = 0xE1491A78F1D4248FULL;

    std::uint64_t aWandererA = 0xD38656B09A0A4FD9ULL; std::uint64_t aWandererB = 0xA5DA8140E4D27A0AULL; std::uint64_t aWandererC = 0xB2F4682DA522782EULL; std::uint64_t aWandererD = 0xB167D6F831C745C8ULL;
    std::uint64_t aWandererE = 0x9BF4F86A8D0FC075ULL; std::uint64_t aWandererF = 0xB41319BE7F6B08C9ULL; std::uint64_t aWandererG = 0x900CB3AC953E2A6AULL; std::uint64_t aWandererH = 0xFF6B009743A5FF61ULL;
    std::uint64_t aWandererI = 0xD018996342271813ULL; std::uint64_t aWandererJ = 0xFD10912BAB38CB7EULL; std::uint64_t aWandererK = 0xDF19A3C0884CC54EULL;

    // [twist]
        aPrevious = 0xDB7AB83D47820A79ULL;
        aCarry = 0xD6940DAA4316158BULL;
        aWandererA = 0xD224454D0A1E0BFBULL;
        aWandererB = 0x975AAEDD784CBD2AULL;
        aWandererC = 0xF4E611728DFFD946ULL;
        aWandererD = 0xEA9DE4785BD02430ULL;
        aWandererE = 0xFE52B83C5B0F2E37ULL;
        aWandererF = 0xDD5121E4BD001D65ULL;
        aWandererG = 0xF59CE11C8C94EA27ULL;
        aWandererH = 0x9FC300B0A3325846ULL;
        aWandererI = 0xDD8C52467FFB94A1ULL;
        aWandererJ = 0xB5984ADDB4832460ULL;
        aWandererK = 0x93B070A7C829FE5EULL;
    TwistExpander_Athebyne_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Athebyne::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Athebyne::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Athebyne::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 11 of 33
    // Exploration cases: 0
    // Structural maximin 527 / 674; family total 5463
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2005U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 11 of 33
    // Exploration cases: 0
    // Structural maximin 526 / 674; family total 5412
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1060U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 11 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1070 / 1248; total 10843
void TwistExpander_Athebyne::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
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
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
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
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 11 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1076 / 1248; total 10867
void TwistExpander_Athebyne::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
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
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
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
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
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
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Athebyne::kKeyRotateSalts = {
    {
        {
            0xCDA6E8BCE052DE96ULL, 0x7B0BCB20AB8A0AA2ULL, 0x1ACDBE43BC7B2C81ULL, 0x98968D9659549C5EULL, 
            0x05B4088DF42AE659ULL, 0x4E85BF32BF7D55F4ULL, 0xE5C40651FD480D95ULL, 0xA506DA13F7A47BB6ULL, 
            0x424BC2F551E375AFULL, 0xC7DF9913339C699AULL, 0x2DE119E6B12E02ECULL, 0x85537F31859ED910ULL, 
            0x5738DE111DE12169ULL, 0xDF10B8CF43F8574DULL, 0x0F850FDB13351E8AULL, 0xCED22304AAD5B3FCULL, 
            0xEA6CE75E4A6EE7D7ULL, 0xAE00423F4DEBF946ULL, 0x22DF64B8D8D86949ULL, 0xB2F71A53E5354DE4ULL, 
            0x16FC096342E3D529ULL, 0xC767D0DC63F6A709ULL, 0x1E793C54CF4BC8DEULL, 0x86B96B132DA5C183ULL, 
            0x23C0033FB5F23BC5ULL, 0x2F1A7F49EC7EF4DDULL, 0x40DEABFD5FC19148ULL, 0x6D5613BD21CFACD5ULL, 
            0x75FFC72759705AC4ULL, 0x22E4CA1C8DFB9770ULL, 0xC8E44F1DDA67DE10ULL, 0xD3E4C484301411F6ULL
        },
        {
            0x6319FA6831751DF5ULL, 0xF91526D1BDF349B4ULL, 0xDCD780B66A7AAEF2ULL, 0x8AEE7611796D471FULL, 
            0x3C0DDFED5C78A75FULL, 0x937954AFA11453E2ULL, 0x973DCB6D76FF8B4CULL, 0x51BF33AD78E1BEE1ULL, 
            0x93ED5CB326459DF1ULL, 0x87B4D539060027ACULL, 0xA2C268BAA6DF115BULL, 0x17507EEC9A597D22ULL, 
            0x0A660169D5FB5B17ULL, 0xC922CEBF3B0AF35FULL, 0xA174EF8BE695CC26ULL, 0xC4A273CFC48A8916ULL, 
            0x2FADF881B23AAF71ULL, 0x70FB0113E67D331BULL, 0xE2CF1059851B5A11ULL, 0xA24B8AB3873FA397ULL, 
            0x8E600FFFA97FAAE2ULL, 0x705494C49594D24EULL, 0xFAA40701F86DEAA0ULL, 0x2A0A6653781ABF30ULL, 
            0xD25C86A10E8FB281ULL, 0x003A33C82CBC72A7ULL, 0xF376D0A491DBAE09ULL, 0x9571620ADEA2819FULL, 
            0xB5FEFD1E23623C9DULL, 0xF5FB712A7B4F6AB3ULL, 0xD265B86A5BB8CA8DULL, 0x1F2CC1620613076EULL
        },
        {
            0xAA5F0111D4A299E9ULL, 0x12045945E8B7DA85ULL, 0x16D7B4494DB455EEULL, 0xE9B4C3F8802F6AC9ULL, 
            0x4C3112C7AC7F2B58ULL, 0x3FCBFE1E4A3EF172ULL, 0x0E215819A2C01143ULL, 0x01ABE347CEBA5B23ULL, 
            0xAA638AA5487E7023ULL, 0x40637EBCB8FF8F12ULL, 0x4C240C9F85AB2139ULL, 0xA824FBB7EB92462FULL, 
            0x0F0B0F8E0DD7B8A3ULL, 0xBC385BB0EB7BF577ULL, 0xF4A117B75ADC3D19ULL, 0x7AE77FE8BD93BC35ULL, 
            0x70C157777136B0A1ULL, 0x81E5EB7668391E4FULL, 0xC1ECBCDD5281E054ULL, 0x2DCC06EFD5CD0EC5ULL, 
            0xA00FF03014781C90ULL, 0x5A9EE6505E94CDC8ULL, 0xCED07CDF2C96C89EULL, 0xC1F308F1203A7488ULL, 
            0xA9F459F0B50F0C5AULL, 0xBACAB500AFD46283ULL, 0x3FAD5D196C0AD211ULL, 0x1CB514072BDAA6C0ULL, 
            0x1779E37C7438EC24ULL, 0xD7AF31B58F44F0F8ULL, 0xA373D1D118DA4862ULL, 0xC015F70782E69855ULL
        },
        {
            0xBACF00BF6195C4E2ULL, 0xA049C5815139C444ULL, 0x9DD533702DB573E7ULL, 0xE48D7E930202F6E1ULL, 
            0x427D8489F826694DULL, 0xA6CE09B400228456ULL, 0x4686BE106B0B26AFULL, 0xC70C0772CBA578CCULL, 
            0xC0D6558D56EB5D36ULL, 0x5012271FA6B2013DULL, 0x668D25E85883443AULL, 0xCFB43E97363D8BE7ULL, 
            0x987D87164965BC1DULL, 0xD560350683DCB5C6ULL, 0x2450137F5A15198FULL, 0xA608EFAEC7884AFDULL, 
            0xC1242579C4BD2F2FULL, 0xC2412ED01F119687ULL, 0x59144BD988E6BD4AULL, 0x19568F5749164B68ULL, 
            0x4BD3EA1E90DB554AULL, 0x80D67889820F3D07ULL, 0xB05619AD6B2F13A1ULL, 0xA859E3E356E73506ULL, 
            0xE1E9748F78703F2CULL, 0xE3048863FA203245ULL, 0xA676F12A8C275DB4ULL, 0x7752092074F2B544ULL, 
            0x7093B42AAF920BC1ULL, 0xF8A2DF32AF906B2DULL, 0x62AA880FA43430D0ULL, 0x8B3FD50CA5B2A81DULL
        },
        {
            0x339E1E24FF6D9BC0ULL, 0x7C439D509D555B57ULL, 0x311A6DE725069114ULL, 0x4823DB3FBD8497C6ULL, 
            0x5751CC97A2A1EFF5ULL, 0x4AFCF9CED77A84E3ULL, 0x052F77A7D65E01F0ULL, 0x636A30FC615959E0ULL, 
            0x279C56AA01E102D1ULL, 0x040181EBAF241204ULL, 0x0CF34ABB0566FE06ULL, 0x7B5D718BCA7AE110ULL, 
            0xF5B4801FEB1A4780ULL, 0xB8BFC0BE01CC1B62ULL, 0x3EA408107CE03F79ULL, 0xBF85127EC9018645ULL, 
            0x8ED16C14F3C05759ULL, 0x30235F0E928A1D16ULL, 0x5C5574DFAEAFB936ULL, 0xFEF2677F29F6B6F2ULL, 
            0x3C0014BDEE054501ULL, 0x3DE781FF0C8AF419ULL, 0x513C19AE3303D835ULL, 0x2541765F2FC8EBB3ULL, 
            0xEE0C812CF411C8EEULL, 0xAC7B3877F74C0E24ULL, 0x0A284A106E5676B8ULL, 0x11327AF74D12A625ULL, 
            0xCE24C6308F79B856ULL, 0x39DDEAB971B97722ULL, 0xA5B6EDD1C1FEEEDAULL, 0xB97BAB7F8E74A249ULL
        },
        {
            0x8B12846D2D145464ULL, 0x0745948BC604B5A8ULL, 0x32EE80FAAB79B8D6ULL, 0x10B4B4225A0C0788ULL, 
            0x0363B9D93987EE8EULL, 0x689FD3BC9A0B89ABULL, 0x02948657306A06B7ULL, 0x9F819686433F73D9ULL, 
            0x6CABF3220A0F8348ULL, 0x2F165DF70E080C25ULL, 0x48721E7354D84C0CULL, 0xABCFB1EA800A590AULL, 
            0x4B88CA81E2158B0FULL, 0x7B4672E9D0C38C50ULL, 0x7DE83681B03B5850ULL, 0xE6B6858E5834E3D1ULL, 
            0xDE44091D3F4A2AB9ULL, 0x65A5C1A7F7A46D50ULL, 0x7D5306167441F261ULL, 0x8ADE63B958596A14ULL, 
            0x400EE12CC4534910ULL, 0xA1C48CCC2BBE8774ULL, 0x729223B19F17377CULL, 0xC015F37DA1B5792EULL, 
            0x23E37B0B1DAE2501ULL, 0x8DBC07AEE173FC64ULL, 0xAA82557FEBDD1651ULL, 0x4505F49DE6821B18ULL, 
            0xFF1033B23ED6AFD6ULL, 0xEE558DFD75989B3DULL, 0x99669A8CAF2B378EULL, 0x9C771F524E8D7E90ULL
        }
    },
    {
        {
            0xCA682B98A77831CEULL, 0xDA9AFFE52EC47B1FULL, 0x8106653C675B3209ULL, 0x7DBE881BC3AC0A3CULL, 
            0x439C67E55DB57BB1ULL, 0x4878BE1F10060A69ULL, 0xBC2EE0AB8EB01ACBULL, 0xC15D46A152B82BFCULL, 
            0xC6B6D2AFE3C167DFULL, 0x90F9D559EB7B1DDCULL, 0xF3463CC179DB6693ULL, 0xB3F58B68CAFA2C51ULL, 
            0xAABE1CF21C56CA5CULL, 0xE666DF1977189F33ULL, 0x209101A86468A8E5ULL, 0xF71899541691BAD5ULL, 
            0xCCA0A8943ED61B5AULL, 0xD94D7B7292ACA1DEULL, 0x00462FB9B659260DULL, 0x667585E97CF93624ULL, 
            0xA4710CB8B1C70216ULL, 0x9AD1467C0DFA0B86ULL, 0x297441E8B48A0E14ULL, 0x41423762356C9BECULL, 
            0xF5A214B3E553A9B9ULL, 0x4BB42C0B95937339ULL, 0xBD4257855A200EECULL, 0x0F1200DD01C86152ULL, 
            0xED8A2021F8FE740AULL, 0x23AD168F71A11BD3ULL, 0xC7C49C27D558A7A5ULL, 0x2F1B110C2BD9CD1CULL
        },
        {
            0xC65FC6AA5BDAC2BEULL, 0x6DE8B4621E3E1555ULL, 0xAAE57166632099DDULL, 0x9F439BB2FB268B7DULL, 
            0xFD0101932D99EFC5ULL, 0x626E0E7CBF0815F9ULL, 0x6CCDCEEACC71893CULL, 0x72A65F2ACB3D1702ULL, 
            0xA8EE10B414B08182ULL, 0x5D5133206934251FULL, 0x72D5658D14570FEDULL, 0xFB227E695AB7B544ULL, 
            0x3E0E952EA098E91BULL, 0xCE6DD3F6B4DD73F2ULL, 0x610344312018D573ULL, 0x8A68C85D15D5FC88ULL, 
            0xB634928673B308C1ULL, 0xB3CE2FA7A12F6E0CULL, 0xF3AC91A0AB74F8CEULL, 0x6BA683EFEFC1FCF2ULL, 
            0xBEA459FDA1EB8439ULL, 0x0DFB8C0DE4218ACAULL, 0x3E40C279D3C4753CULL, 0xB7B2C2936EE8C4CDULL, 
            0x0179D33295ACE537ULL, 0x346F3656B7FD3DDAULL, 0x7C6BE0AE73A080FDULL, 0xF48A251A13C9B142ULL, 
            0x81CAAA9774F8614BULL, 0x8413B953DC5661D1ULL, 0x46E3A74B1D182DE1ULL, 0x136323DBCFED511EULL
        },
        {
            0x4932A5E7FC9AE3B0ULL, 0xFE671E55F56CDDAFULL, 0x8363F5E42A0CCA4CULL, 0x95DBA30EBC0E97FCULL, 
            0x4E91B649D2BC51B4ULL, 0x2C85F8559CAED7C3ULL, 0xB54C2CA9B4B71CEEULL, 0xE9BEC891683C9346ULL, 
            0x21D2DD9C80000576ULL, 0x65F67743DB1A5C5CULL, 0x2B40EF30089546F1ULL, 0x8526F0643FDA1CD2ULL, 
            0xAF230E6370002E8FULL, 0x0FCE651AFEFB59EFULL, 0x82979644F6BB133BULL, 0x0E2C42D5D4BB51B7ULL, 
            0x5F60360A53658391ULL, 0x8F255E1DA02FBC3DULL, 0x73448E868035C694ULL, 0xD41AEAF021890739ULL, 
            0xC348B8AD8B3A354FULL, 0x5526D719DB68D456ULL, 0xB930AB0B8BFA3494ULL, 0x9FC2178C6AA0FC2FULL, 
            0x41E4C923FC944333ULL, 0xFFEA9DE0810FFF6BULL, 0x80C8E46B4D9DE79EULL, 0xD589D4D1A83D11C8ULL, 
            0x7F1DBB58A0F2C049ULL, 0x93558A80D0663CCAULL, 0xE4467B259505FAE4ULL, 0x5CD5ADBDA4FDF36AULL
        },
        {
            0x317AB822A79B001EULL, 0xED792CDE5D41B4C1ULL, 0x81FB15A604BDCA62ULL, 0x0D4272464F575C63ULL, 
            0x004F2A12C31F1A45ULL, 0xC5AF50AEB50BDCC8ULL, 0xC3973F5E41158FFFULL, 0xB1092C6A9879F107ULL, 
            0x161656C8897EBEC5ULL, 0x393D92B5005B605EULL, 0xED6DDF996FBF9110ULL, 0x37588DE9B6FB988FULL, 
            0xC99991E94182710BULL, 0xB61C52FF6388A43CULL, 0xB42A6E12129FB5D9ULL, 0x804F3BA47173126CULL, 
            0xA0FD5675C62958B5ULL, 0x13A1307D45CF59D6ULL, 0xEDC5EBDBD514E969ULL, 0x91DBB67E801E62C2ULL, 
            0x94A38DDF57BF6BF0ULL, 0x500ECA5A37E90070ULL, 0xCB87616AFD6AD302ULL, 0x49F3240EE437EA88ULL, 
            0xF357FE38E0DA2D86ULL, 0xD7B633F168A8A3BCULL, 0xFC8760F3277B2178ULL, 0x507C2807714F7ED3ULL, 
            0x479EFFD57FCF26CFULL, 0x31083704175F95B0ULL, 0xAA3EB02D95F15972ULL, 0x25CF196065BFA9CCULL
        },
        {
            0x03BE4F8E5C370E96ULL, 0x7D454673F4FC98B8ULL, 0xACA61AFE513FCA0CULL, 0xC2A7B350E95B44DCULL, 
            0x30DEF446B8185642ULL, 0x8FA7420DB0305480ULL, 0x55C3CD3860AD4861ULL, 0x546F158A704039E4ULL, 
            0x904477EC65B04E18ULL, 0x7AF98195F4D1D0BFULL, 0x8ECAD61B8093283DULL, 0x0D76EC9035718657ULL, 
            0xFD0C546C4DD7ED22ULL, 0x4C440D65F329A1AFULL, 0x96D9B51ACD873A07ULL, 0xD3D437B1C7613CC0ULL, 
            0x86959A6C9614F5F6ULL, 0x5601B3A3AD5085CBULL, 0x9A696B828242463CULL, 0x9AD7B70905F02C0DULL, 
            0x1C19B38ACC414B40ULL, 0x91A9FAB59D677F32ULL, 0xAA6726ADCAA2BAFDULL, 0xEC514D34D90EADCFULL, 
            0x3B7994067278A9C0ULL, 0x3DCE0927B70A0E1BULL, 0x346C5DDBF1F43D31ULL, 0x8E4B6A6107BAC042ULL, 
            0x974075FC5B0CDE8BULL, 0x549F23EFF3E39F4CULL, 0x517A0EB512974F16ULL, 0x694DA5FB2D3DE234ULL
        },
        {
            0x82EF5C9459F2412AULL, 0x2006740B3ECBA894ULL, 0x4E0E2EFDBED965B4ULL, 0x50940056921D7F9FULL, 
            0x57236D242BE9FA44ULL, 0x75F122DC22F15515ULL, 0x62696E72A8FD64EAULL, 0x118CE2BEE577C6A4ULL, 
            0x60C3437E270F7BCDULL, 0x4853CB6B717EC6FDULL, 0x00E84845877ADF9EULL, 0x34CD9D62AC1480D7ULL, 
            0xFB2183213F59E846ULL, 0xC1DC6A2A3F44D15FULL, 0xB638D9F1B1BC067DULL, 0xF8176F1F4A97A1EFULL, 
            0xD2B3F1DC6DC3DAB6ULL, 0x9514158FE8549998ULL, 0xE57E961CBFC50119ULL, 0xA4F669B82ACF09CCULL, 
            0xBFE3C04F69300591ULL, 0x393EAC17EAAB2BDBULL, 0x55B2405451ECED96ULL, 0x733C488D7E9C3A62ULL, 
            0xA1C6BC7A36B1D70AULL, 0x8BF584EFFDB626DDULL, 0xAF70B881CB754458ULL, 0xE99F5C374497E290ULL, 
            0x5EDEE2B4B5056A7AULL, 0x008197A345675601ULL, 0x6AC6EB552D871FB1ULL, 0x122243708404C8CAULL
        }
    },
    {
        {
            0xAF9CF946F130FD6BULL, 0xB08E55A37A977185ULL, 0x995DED7AC9D4B114ULL, 0xAEB5828E938FFE43ULL, 
            0x29F1F196D13FE363ULL, 0x939E1B2E17B497FBULL, 0xB298EC9E3D9981ADULL, 0xDBE9A44590397B8DULL, 
            0xD73129F443EA75B8ULL, 0x811292A9D321B6EEULL, 0x9D0F5E5FFEB13AE4ULL, 0xEAA790CC7CF20D77ULL, 
            0xD2D8BE5295D5C229ULL, 0xB844914E55DC9A1EULL, 0x2E471CDF537D7A5BULL, 0x3FA54A3FA68A6976ULL, 
            0xAC44083278BAF786ULL, 0xEB2283FC9AF06112ULL, 0x6AE3BFE093F26E45ULL, 0xAAC22FDD9A83E902ULL, 
            0x398CD962DE9F226EULL, 0x3B38E0EDFCA5938AULL, 0xE358051F6EFF00B6ULL, 0x83EE06485011ADBBULL, 
            0x3A74F15054B7CFF1ULL, 0x73FF3642D3C82B4FULL, 0x6404CAFA318577F0ULL, 0xEC8A90F7A8D6ECDBULL, 
            0x4444F6FF77A8D4B0ULL, 0x7E9B988553E3C68CULL, 0x38F66669B401B581ULL, 0x91CC07322BD89F55ULL
        },
        {
            0xE6A8FD7F77D265BCULL, 0x9D483CFEFCDFB30BULL, 0xC9F5942D437518FBULL, 0x78FEB1DF124FC3ABULL, 
            0x6A38DE27C8F77DFDULL, 0x62DDE02335A838F4ULL, 0x01183B5AFEACFFA6ULL, 0x9A748C634E6A8466ULL, 
            0x30FCC69573E0DF32ULL, 0xEFC8C8F916747809ULL, 0x0C33663860B5F510ULL, 0x9578DE63106DED87ULL, 
            0xB62804BC16F5FFD4ULL, 0x97928F0DD45A0601ULL, 0xEB60657BA63F465AULL, 0xB9F4F26DF5B0F7B4ULL, 
            0x26402B3B5C68B7FAULL, 0x5A968FCFBE6B22ADULL, 0xFF2A43F1D9792588ULL, 0x27AC34E6DC34F306ULL, 
            0xCB0166A9A1E341F8ULL, 0xC8E0BF13400EE574ULL, 0xB79B8F4B796D11B9ULL, 0x4C255D8B56E200C9ULL, 
            0x56FAB1A556CA468DULL, 0x67E5708993DFAA64ULL, 0xE36289B07CBE8203ULL, 0xCA04A7CE719EA36FULL, 
            0x8543CBA8F6B70398ULL, 0x585D2E843150552AULL, 0x156FEC7E95AA0436ULL, 0x8313D737F794B4E5ULL
        },
        {
            0x4A8E49B53A49D661ULL, 0x4D076B12506D3164ULL, 0x8A600BC0FA8ED6FAULL, 0x7F99AB943E8DA2FAULL, 
            0x1FCE1C8E4D700408ULL, 0xFECA35E550609B42ULL, 0xE380E5FC34321321ULL, 0xB4FCE097E6F63238ULL, 
            0xCDB57B5E72778EFBULL, 0x80777160A91880EDULL, 0xAF721067AD9E872DULL, 0xF4EE00DB840CF4E3ULL, 
            0xD235B1CC9D997145ULL, 0x26606D44F2BD6525ULL, 0x3D385A5964C8859FULL, 0xBBE1FFD911D1982EULL, 
            0x5356B95F8A20DAC6ULL, 0x2717CBD7ADBA2E82ULL, 0x801599340B0E1BD5ULL, 0x2CD50853D89D5B9EULL, 
            0xE6E23892FBCDAE82ULL, 0x515C3CF4270A775DULL, 0xD768B0A12E424588ULL, 0x9E09C073C01CCB80ULL, 
            0x7A43BAE917E4BF63ULL, 0x1312D488C19D2369ULL, 0x44DD79682B196F35ULL, 0xB05E45867AD7E82DULL, 
            0x9FAB81BE0099D248ULL, 0x0E450A9FAC724438ULL, 0xE0F7EEDEE7D57C70ULL, 0x2D7D819DC9A5B402ULL
        },
        {
            0x537A1BAF199BD5CFULL, 0xF2772F7DDA3C7B42ULL, 0x0C4E63EE5BD2482AULL, 0xA60244FFC94C2B3CULL, 
            0x8F2F8924290D35B6ULL, 0x91A75F12304B4D5EULL, 0xE9D9D4ACEF077C1EULL, 0x5574DA9F653AC348ULL, 
            0xF109A8626A63BC8EULL, 0xE0FD6BA0A2A14117ULL, 0x0E7BE871C31009C4ULL, 0x2832611F6B16D3BEULL, 
            0x19855B07BCEC6B91ULL, 0xB6ED2F58BEB6E421ULL, 0x44FB74343B137A8CULL, 0xF40E285FD6B26696ULL, 
            0xB5FD881A3E01BA42ULL, 0x7700F8A3EC0A2C16ULL, 0x6CFCB55FCC861306ULL, 0xE73BADA754E37F77ULL, 
            0x3A8B0952491C0BB7ULL, 0x558C2DF3297979E9ULL, 0x4BB188DBBF1A8941ULL, 0x30B6CD9D3EEC21DEULL, 
            0x039E46B4CDDD6F4BULL, 0x21C1802A63EEA107ULL, 0x7A58C853017BCADAULL, 0x5044E3E33B7E9229ULL, 
            0x72EF03DC473E4335ULL, 0xDA46ABC4C7CFC15EULL, 0xA47CCDCC41B6C383ULL, 0x278693D33B09023FULL
        },
        {
            0x33A20416E5D099B2ULL, 0xECC53EC7A80CC95DULL, 0xE76DF85DC2E638E5ULL, 0x8B1DEC8103A2EC6CULL, 
            0x87F9601D8CED10FCULL, 0xD148EC06A1855DCEULL, 0x04DF779A83DE1378ULL, 0xEC3AB4B4701C89A6ULL, 
            0x06A6E3A4F69D8792ULL, 0x8D31F92607ED4664ULL, 0x6C03899182005181ULL, 0x89B54EA0A7DBB3B0ULL, 
            0xBB30B8A365AC904FULL, 0xA1DA4A2712462DAEULL, 0x073DAA4815D3C9ACULL, 0x9E0EF58D427A2B98ULL, 
            0xC9A2BE5004188AC7ULL, 0x88448F517C5FBA28ULL, 0xE742609185B56E91ULL, 0xE62A601F869D6F7CULL, 
            0x8FD51C092CAFE7D1ULL, 0xF705EFA5A8B644F9ULL, 0x7C29BCCC8EED7AF8ULL, 0x4DC4757B81825366ULL, 
            0x5819CA929B50E9FBULL, 0xA7E54DABAA317E00ULL, 0xD7A76DCFA55E1113ULL, 0x1FCBE63918FDEF2AULL, 
            0x1665C2BF71A5E5CAULL, 0x0FB3586021A6C5C5ULL, 0x4A87CAA7ECDAA381ULL, 0xA5ACF8C3A2753D3CULL
        },
        {
            0x1A433D7F0EDFB541ULL, 0xECBD89AB09454299ULL, 0x0847C2A07F4B02C1ULL, 0xC8295AFED0DC2B17ULL, 
            0xE5F15B63C00AF613ULL, 0xA8BCD4579BDF7101ULL, 0x9EE0A01A6193C493ULL, 0xB8C9E0B9FD0322B8ULL, 
            0xA79CB65515BABEA1ULL, 0x97B828277DEDFE82ULL, 0x5F18B848E364C6BEULL, 0x1D415FB09AE3B5C6ULL, 
            0x2037C44626AFDA73ULL, 0x3D4BF3BEA8471532ULL, 0x63D64BAD2939D498ULL, 0xCF61C492096D014CULL, 
            0xAE8EA941B0C086E6ULL, 0x3F25CC6DC3CFB24EULL, 0x684A3E8AAA156FBEULL, 0x34874559B2EBCE90ULL, 
            0x0624F719E6E7D501ULL, 0xAEA6EADC179DB847ULL, 0xE10F4DC4D6CF58A9ULL, 0x71DB63BBC4554165ULL, 
            0x136CBA583E8E8716ULL, 0x0599DF43BB23B44CULL, 0x0AEE034376658EDCULL, 0x48F5FF4018F1B560ULL, 
            0xC3F462717659DADDULL, 0x6A1043D66A7F1582ULL, 0x2728CF0E8503F580ULL, 0x70B792AEF8306C93ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeyRotateConstants = {
    0xF046058BCB96797CULL,
    0xDB43947F51AC7B36ULL,
    0xE3616A0F9C3FD2ECULL,
    0xF046058BCB96797CULL,
    0xDB43947F51AC7B36ULL,
    0xE3616A0F9C3FD2ECULL,
    0x93CB81E1D07357B9ULL,
    0xE917076C77D11E2BULL,
    0xEA,
    0x7B,
    0x67,
    0xDA,
    0x77,
    0xED,
    0x29,
    0x52
};

const TwistDomainSaltSet TwistExpander_Athebyne::kKeySpawnSalts = {
    {
        {
            0xA71B01F0C219A3BEULL, 0x40BF7268E64A986DULL, 0xE0D6976C86BC0E96ULL, 0x911EDC770157B21EULL, 
            0x9CD5C439E5452ADDULL, 0x9C13B2724257B09DULL, 0xE64A2F224C893A2BULL, 0x40CA833570B114EAULL, 
            0xD80B524AFC2D4332ULL, 0xC10B509851110B62ULL, 0x4B1D05BB86582225ULL, 0xFA9FA2271A7C70D1ULL, 
            0x3178F00402D10BE7ULL, 0xA5CF43CA382B496DULL, 0xDA7E7A4E1965018DULL, 0x7F3C549B881148D2ULL, 
            0x363E03236B22FE03ULL, 0x7E3199ACC68E5486ULL, 0x617656962E781E46ULL, 0x57AB20534EA41D3AULL, 
            0x042673C4659EC3E9ULL, 0x2B96FAAAF4C96720ULL, 0xCB9FF1CFC2176E24ULL, 0xA103DA15066ADDECULL, 
            0x89CC54B28085AE37ULL, 0xCDF313C2217718A7ULL, 0x37513B9C1CE375BEULL, 0xBDA8FF03F1AA136DULL, 
            0xFB2D00A6306EFCF6ULL, 0x1F619AF8B641A101ULL, 0xCD055723266D493CULL, 0xE0F37A542567614CULL
        },
        {
            0x44B9BB6B09F79988ULL, 0x1B6BCF11624978F8ULL, 0xC12FF05A4D9F9947ULL, 0xFCFDEBC425ACEA3EULL, 
            0xBD3DBC6BF3DA8BA3ULL, 0x81A47E5AE0E13FDFULL, 0x506081346136DD2BULL, 0xECCE21D88CCE68D5ULL, 
            0xF3CD240AE4271591ULL, 0x899248E9A347A011ULL, 0xB4AA46C30F75D05CULL, 0x370C9FE6634BA41DULL, 
            0xEDC69774717EBF84ULL, 0x4B3E065D5368708FULL, 0x4A11A9EB86D57B2BULL, 0xDCB5B51491E2BCB1ULL, 
            0xC999E370EDEDC1EEULL, 0x740925A8D53494C2ULL, 0xB2D84D2EC625C32CULL, 0x7E9B4A0AB310D2D1ULL, 
            0xE81F18D86A862A0BULL, 0x8354A2CE41F0CDDCULL, 0x6179747068A00281ULL, 0x3ED56238D1644E22ULL, 
            0x37E807D2CB418507ULL, 0x433113AC3724DE47ULL, 0x0F09B0F9E2A9B81EULL, 0x55EF876558E3819AULL, 
            0x88624982AC41C10DULL, 0xDD3E3E40F2CA2C3EULL, 0x264CD4FCF9FF3A73ULL, 0xBE338E2896903AECULL
        },
        {
            0xC93D99296174C132ULL, 0x922167AA83F81AF3ULL, 0x9CFD92AFFAFD6752ULL, 0x9F6DCC80EA6FC87CULL, 
            0x227529F26FE99149ULL, 0x0A272F443BDE0896ULL, 0x9C42DCA5A0497073ULL, 0x27EBE3C08A2D1F9BULL, 
            0x7DFB496DC5765CB5ULL, 0x9C08AB56A23D1422ULL, 0x35DCE3A20F4C7DCFULL, 0xCF4380E42A886081ULL, 
            0xE2C30105AFB45C45ULL, 0x0EFF8240484EEB67ULL, 0x3D790084543927BEULL, 0x5BB7F639D1F89E83ULL, 
            0x8044F41C7C815A5EULL, 0xB591C9886BA3ADE5ULL, 0x5A7AE3F3C00A920FULL, 0xFEF124C4C2201B35ULL, 
            0x6545466FA924B1F4ULL, 0xC520267BF0863BF1ULL, 0x82203A214FD14E56ULL, 0x1532C18C03ED3EFAULL, 
            0xC3DBE4C8C6B2DBCAULL, 0x6B4FA90511785640ULL, 0x7CBC6D3FF5805276ULL, 0x0D764DFF51363DDCULL, 
            0x5582D5CCC0E57FC6ULL, 0x77477054BA850797ULL, 0xF175281CDE1EF2ACULL, 0x0728EC8C4EE3E86DULL
        },
        {
            0x340D24839608733AULL, 0xB46486DC5A18B242ULL, 0xC9C91F35B3A54108ULL, 0x3F5743D8AAC5438AULL, 
            0xAB5B866FBAEFF984ULL, 0x68B2F35A2FEE8E6AULL, 0x5068D41D16F3150DULL, 0x670CCA2E4EE14C13ULL, 
            0xB14FE1E4632331CEULL, 0xEFE91A7B48BD386EULL, 0x0BA2A5E7878FA3A9ULL, 0x4D8CEFAD4521846FULL, 
            0x20DF71874B8DC5FBULL, 0x62885A88196ECB98ULL, 0xEAC46C697F92EAF5ULL, 0x36863E73D5C1CAF1ULL, 
            0xB7466AED80E1330BULL, 0xEFF30209E148E235ULL, 0x5BF54DF43E5223F9ULL, 0x0F73E2A7C295EB77ULL, 
            0xA530347DF43B3C4DULL, 0x2F97F3D821FA20F2ULL, 0xE357BF0E24033534ULL, 0xAB5DBC373917E0C7ULL, 
            0x26A1CCBEFB51AA28ULL, 0x0576DBA3E25590DEULL, 0x78F8172F2878C530ULL, 0x857A3339F6DDFDCEULL, 
            0xF72D4DC71E7C4917ULL, 0xC3E7A1E2191D77D5ULL, 0x5C565430BF6526E9ULL, 0x48D399E0C7608881ULL
        },
        {
            0xC2931F0161F35E34ULL, 0xE6B16108ED6D7698ULL, 0xA979401CEAA5767CULL, 0x59AF68809E0EE4C3ULL, 
            0xDEC1BDFC669714E6ULL, 0x0801FE59D3958C9BULL, 0x7B6CCC22BB4A7887ULL, 0x20F1B754DE5F2107ULL, 
            0x87D259D568E43730ULL, 0x62B9839D142BB412ULL, 0xC43E7D37BC78C576ULL, 0x27D1D3AFEB61022AULL, 
            0x162146D1AE7E4EEFULL, 0xE6D65F60765C456DULL, 0x607231ECFC8CE438ULL, 0x6F0819BE3F7AD085ULL, 
            0x8E9F038FA5C2C55AULL, 0xD7D2F2661CF95CF7ULL, 0x7B43147EC397A607ULL, 0x27AAC60C88D5D4AAULL, 
            0x8659540077C804C4ULL, 0x87D698BC4DB788EFULL, 0x5623868EABEB449CULL, 0xF02F789E6041944EULL, 
            0x2E89B595E98C9CF2ULL, 0xB7C48E0E8AEC69FCULL, 0x62BBAC70200E4C62ULL, 0x72EA979984F4D876ULL, 
            0xEA7A6F2F640CD1B6ULL, 0x5C85B2B17B00BDE8ULL, 0xC30579F7AB7D149AULL, 0xDDE058519E2CFBCFULL
        },
        {
            0x0C00D33CBAA4B47BULL, 0xC752C44B677FF871ULL, 0xCF412A39B22F1AC0ULL, 0x140F142F350F697FULL, 
            0x19F9A111FFF51C2AULL, 0x2D287D35C1FD14AEULL, 0xF044804FE557CDA2ULL, 0x505CE8CA8A46FED5ULL, 
            0xAC13E510C32A6418ULL, 0x3F940A3894532479ULL, 0x664EFAC8E650ECCCULL, 0x853E91C611D8D7A2ULL, 
            0x04F3DC3E024FAA92ULL, 0x4582DB376F479F5BULL, 0x091BD6C94E3F0D7EULL, 0x9D8128A5D3ACB0E1ULL, 
            0x3B3784E091485FA0ULL, 0xC2575425FC10BC9DULL, 0xBE3B83B21F23B3C3ULL, 0x6CD12256E019E1A6ULL, 
            0x0850F5897D00BA1FULL, 0x014EC9D5C981AB6EULL, 0x9E8A5561F24EE045ULL, 0xB0C064EDEB9F97B9ULL, 
            0x91ECD3950EE1B58FULL, 0xD22047CDFA952131ULL, 0x52EBFE6044E94F23ULL, 0x8799CEC30997A7CFULL, 
            0x3335709DC56C82BDULL, 0xADD440E7680D07D3ULL, 0x0B67FDD6B10BD08EULL, 0x1241B8723ECDA5B5ULL
        }
    },
    {
        {
            0xD14B5450442D6537ULL, 0x1B8DD56790C99B59ULL, 0x7DF7481F9AC86282ULL, 0x405656EA4E56A64EULL, 
            0x9BB16B5FBB1F8C16ULL, 0xF4F74DBF00057BADULL, 0x0AD851EC5A38DF86ULL, 0x4A0C0A4A9A5BB5B9ULL, 
            0xE78E5D948D7EFBE6ULL, 0x9188B7A5052C64E7ULL, 0xDA894D589A6091E9ULL, 0x7850413A041F5653ULL, 
            0xF94FBD2A7A6E211EULL, 0xF0DD3D6ADCDA8DA9ULL, 0x18657C65A58F6F78ULL, 0x7EAD8B6B45767A4FULL, 
            0x7E69A410E073DF1FULL, 0x609595A2E20CB3C8ULL, 0xB50B3009F46DB076ULL, 0xA0471EEC043F9E82ULL, 
            0x5D6F220CEFF0EC0CULL, 0x7EA504DD99C31D6AULL, 0x8ABB695CFE8273ECULL, 0x9B314D36C330DD69ULL, 
            0x7EEF385989FD497CULL, 0xC8A16C7E15109BDDULL, 0x4C0175E37C98E798ULL, 0xE2FA4616672BF4C6ULL, 
            0x58F61E6765ECD1ABULL, 0x8F5F70714818E505ULL, 0x2D61129F968C0848ULL, 0xA821DA122EEA5196ULL
        },
        {
            0xD87F9D40482493F4ULL, 0xF217AEA7110E3F66ULL, 0xB126DA9C6A502CC8ULL, 0x35BD6776079B2A76ULL, 
            0xA68738128E69115BULL, 0x58D1EE5688E028B3ULL, 0x3EAFEDFF4F62FFACULL, 0x080D06BA94819CC6ULL, 
            0xCDDDDDCE061580A9ULL, 0xF4724422CC80982BULL, 0x036070BF6BD1AD51ULL, 0x0C23FE1083785E91ULL, 
            0x87B90968C36F8CC7ULL, 0x3583E263F24E40F1ULL, 0x417F404CD428D7FFULL, 0x9CDE82243866594FULL, 
            0xDF1E16A7BA2AD1B6ULL, 0x75557B1E7917C1DDULL, 0xC52F04F97BFF388EULL, 0x431C7F602C4F12E8ULL, 
            0xDA2C66610CF41240ULL, 0x0015EB15FFB7A7DDULL, 0x901A3D110A68BD7CULL, 0xBF9F45DCB5203E1EULL, 
            0x30E7AFA7D67F35B0ULL, 0xFB16EA15F49083F4ULL, 0x30AA4F4444CEEEABULL, 0x48DD44CCCBA21E8DULL, 
            0x0DA68695703D3E07ULL, 0x5216A14B0987B384ULL, 0x4D1BB1F4755C0F8AULL, 0xF9CAD1A71110F823ULL
        },
        {
            0x44EFE5AFCA1DF9A6ULL, 0xC6987D7D95CB636DULL, 0x129A5BD5BA19ADD4ULL, 0x3AA27018DF22E798ULL, 
            0x73720D07A5A31842ULL, 0xCC92AAF76AF78805ULL, 0xE7FA77479B2712C3ULL, 0x3367E12D35BDA1FEULL, 
            0xF7F6B4FB9DE71135ULL, 0x38DCB2A69C3E570AULL, 0xEA7E29E402616D35ULL, 0xAE4287229EFC13A5ULL, 
            0xBD262DD5D91A7C5CULL, 0xCC1EF3737EE24141ULL, 0x4B88CBCB1E481486ULL, 0x72F2AFC408D97B29ULL, 
            0x5520C91397C24669ULL, 0x82F6B32E6AE9A293ULL, 0x41B4F1B95D0954ECULL, 0xCB7DBE56316C9E23ULL, 
            0x5FC4CB7599F07EC2ULL, 0x394642719FA04498ULL, 0x17990EFE607961BEULL, 0x13D344A7AB21F22EULL, 
            0x1232925F039C16FAULL, 0xEB74FE78E12C254DULL, 0xB2E67A8A66F06478ULL, 0x416155275992681BULL, 
            0x9068F2D52F8D9589ULL, 0xCCCD7480B4A07538ULL, 0x052E7208482FFE4FULL, 0x0D8EDDC0E740640FULL
        },
        {
            0xB2E7A7FF64448238ULL, 0xCFB633B956E18912ULL, 0x4250460A5FE19EE9ULL, 0xD157EAE54B0B5CF9ULL, 
            0xAE32DC945260F886ULL, 0x73FD9BC47ACE53B3ULL, 0x5D8E207E3394BDD3ULL, 0xDD8E319D4963876DULL, 
            0xC4675625FF430338ULL, 0xB6557F3A5390B23CULL, 0x7A324ACCB67A1222ULL, 0x6A5EDEF20D0C2FBBULL, 
            0x040D2BE5E0A68E2EULL, 0xB6E5F5F2C7FF8F2FULL, 0x04647E03DBA64CAEULL, 0x2E70F286AADFFBD5ULL, 
            0xE0ACF77403325A14ULL, 0x5717EFAC796404A7ULL, 0x4325A41F688E1403ULL, 0x9F75BE214B4744F0ULL, 
            0x71BF4C8D390D384DULL, 0x7F3C72BB47DFC319ULL, 0x4BBCE9B5701EE6DAULL, 0xC59CD4282AA43F0EULL, 
            0xAB00A22088A7B02BULL, 0xDC28917C14974F9AULL, 0xD19AC48C0498C4F8ULL, 0x7873B76E5B962584ULL, 
            0x6A836C1F3BE35721ULL, 0x4EAC64B3295CA8F5ULL, 0x4D9F50B30423BE4BULL, 0x827E8E7C1378023AULL
        },
        {
            0x50CD6EC722AD6C08ULL, 0x4F1E8E7B90123649ULL, 0x25CB490EEDBD47CDULL, 0x11F61FABE4E0F3FDULL, 
            0xB10119F6D929DAEDULL, 0xD4EC1EDD4EAF316DULL, 0xF1964AE4F4691B99ULL, 0x2DE8CBBDFD1A261CULL, 
            0x7B41F4F5DEF2D776ULL, 0x94ABA509C8C829E2ULL, 0xE47AF63BBC0294B0ULL, 0xEDD350459F5E9044ULL, 
            0xA0FCB6EEAAAFC532ULL, 0x58383970193764DCULL, 0xFDD220BCC709F69BULL, 0x4022EF4E207C68A3ULL, 
            0xEF71F9371C2B2EADULL, 0x7FACCD30A327F023ULL, 0x3001B2C939139541ULL, 0x069E497ED3CEDCCCULL, 
            0x9B04E559782E19A3ULL, 0x242C3364D88CA24BULL, 0xD3CC352AA6729E0FULL, 0x10D7028C0A83F30EULL, 
            0xFEDAEE1C5B0E3310ULL, 0x19F50BB214BD831DULL, 0x429972FFE0EE2569ULL, 0xE81ADD4AEE7BD29EULL, 
            0x5A8C7E5FDE097D00ULL, 0x0CA1506097637C3DULL, 0xC27A9BF4BB005A23ULL, 0x568C496C47E20C20ULL
        },
        {
            0x7DD16E8F4739F43BULL, 0xB77CA166F262636EULL, 0x14E0C04386912E8AULL, 0x026D5ECE2A4CCC05ULL, 
            0xF46B7789B8AC98ACULL, 0x00429057D0E23EB9ULL, 0xA6486E896857AB73ULL, 0xB874109FC8697322ULL, 
            0x44F34A5E542C4655ULL, 0x9F1D4AB382FD3307ULL, 0x1C3A9C99FF35F37BULL, 0xFAF8B6452F540AB7ULL, 
            0x301F1D79E84625AEULL, 0xF60FE4D3EDCAE6F0ULL, 0xCE6267A9FF2BB096ULL, 0x93A7C87F11ECB206ULL, 
            0x2A9904E4AD8FE276ULL, 0x6FAB87632E493F9BULL, 0x623F0931410C28D6ULL, 0xE48A05BB6CB4374DULL, 
            0x3744EA40AC4968E4ULL, 0x7DD6A7C9F6C4994AULL, 0xAC9950909D0D6A1BULL, 0xEE8905C7F7B159FAULL, 
            0xBC15901BB24B8AACULL, 0xCB482BC462DCACEBULL, 0x7239A04B7E7E02DBULL, 0xBD8D18140139B991ULL, 
            0x0D1B8FBB7157E43EULL, 0xCEB9D1061473AE8BULL, 0x989A82A17DD0385BULL, 0x01BD8841651F9BEEULL
        }
    },
    {
        {
            0x4A30BB485735C32BULL, 0x57BD64C6CF08939AULL, 0x1A57EC3266B71D80ULL, 0x5F57BAEA4C38959FULL, 
            0xB1C0A327EAC0341CULL, 0x25CC8C902BF521F5ULL, 0xCFE5E21EC3CDAC0BULL, 0xA08176E0FDAF45F7ULL, 
            0xA8A98429EC30205CULL, 0xC977E71AB1B0B775ULL, 0xC638B1008488F7C7ULL, 0xE528FA8681AF6ED5ULL, 
            0x13106BD433016F38ULL, 0x3F1169397F088634ULL, 0xA0C3D82DE3B53E02ULL, 0xF351A82C6EF379FBULL, 
            0xBD3A0C9604491895ULL, 0x760F4714DF2760A5ULL, 0xF76114280A35756CULL, 0x86BF2B06E7AF6CD3ULL, 
            0xA493D791FD517871ULL, 0x5177A3565FA7B30EULL, 0x5F5900553DE57E8FULL, 0xB472373F83975BAFULL, 
            0x9FFCFC859844E000ULL, 0x5F2B87D28719792FULL, 0xB1AA4F3FA76BED04ULL, 0xEEA59BC4D36B1EFEULL, 
            0x895F71243111A6DFULL, 0x0DBAE49A78999450ULL, 0x93979071CBD39435ULL, 0x8FE8D27C933D6E0DULL
        },
        {
            0xC7901FFC660396E4ULL, 0x4DE7F68CFE0F5A70ULL, 0x9DB06B963F8A325AULL, 0xD516E9990B6D7A23ULL, 
            0x4D02D38F233B0688ULL, 0x753B23E896826FAEULL, 0xF125615466257FD3ULL, 0x7D03911ADCC61627ULL, 
            0x3231A9A08D04440AULL, 0xB53571DD1607FF7AULL, 0x0DE5852351E6B59FULL, 0xE7E5D33EA9D55365ULL, 
            0x7A3D78A5CCA4FC01ULL, 0x23F090A31354AD25ULL, 0xD5B0DA3DE5266CCEULL, 0xC9C0B4105B0F083BULL, 
            0x1316227BA3F71DFFULL, 0x3B20C9468FC16A96ULL, 0x26E5443B04BF0322ULL, 0x70618ED445686B10ULL, 
            0x750BE9F8EBE8BCBCULL, 0x7C18FA5282973A38ULL, 0x9C68CC61D215F724ULL, 0x0389FDB4649C8A4EULL, 
            0x5D8267A08CB42B50ULL, 0x62B44ED0C492C575ULL, 0xFBA43387B29E4E22ULL, 0xFD3C242FC9D28122ULL, 
            0x7ED9417F5D359394ULL, 0x58B1E2641566CCDFULL, 0x5773ACCABBED7B19ULL, 0x55CEB08C8FAB2F1DULL
        },
        {
            0x1757386751EC6512ULL, 0x108A5DDADA68F07BULL, 0xF97F33F9680EE38FULL, 0xD1CCAF72F56E30EDULL, 
            0x3C10EDA93DE8EF87ULL, 0x84D4F957B21D0A2BULL, 0xF34A25C7409DF9D0ULL, 0x34308B87DC84A317ULL, 
            0x0E52A5E08CF9405AULL, 0x2A73730EFAB038B2ULL, 0xBE2DB30B45774941ULL, 0xA9911F5B5EBDAFE3ULL, 
            0xA677AF5A34B54F90ULL, 0xEF43899FB86F29F2ULL, 0x8F5C59FF9E534225ULL, 0x36E70D8A7A6A677BULL, 
            0xE21B703B97095BFDULL, 0xB4C64EBEEF6F3428ULL, 0xB2C5CFC614F0AFD7ULL, 0x7786C71A7D801A12ULL, 
            0xAD268567D54081BDULL, 0xED65E21D686D2C51ULL, 0x65E6A6D9497B9A6CULL, 0x528044A77B7BE03EULL, 
            0x9F74DF8338EB2B83ULL, 0xFF74284E11AA3BABULL, 0x52E6D35120A92A1DULL, 0xDCFDC6325DFFB4B5ULL, 
            0x2EED8B56707BDE80ULL, 0x124505249DE8C8E9ULL, 0x966E0957909C20E3ULL, 0xBB5E9BF0B459C368ULL
        },
        {
            0xD5BE19DCCA4ABBC2ULL, 0x636BB3AED9634F4DULL, 0x59D8929A8C423937ULL, 0xA7E49770965A8F3CULL, 
            0xEE7EE615AB9EEFF1ULL, 0x98A671ACC0E9DDB2ULL, 0xCBEF3DDBF0B452ECULL, 0x0BC88140FA3CB8C8ULL, 
            0xC185A3C862052DB9ULL, 0x633CA607D84ACEA4ULL, 0xA1DD39A0B2224C8CULL, 0x4FF9C79121B4D81FULL, 
            0xFD62718E807C9E15ULL, 0x4CB4DEBF855F3DB6ULL, 0x32D7052EE82A6EB3ULL, 0x9AB4E42FD7854CA0ULL, 
            0x514229AECCE0A778ULL, 0x329BD9E217E1B8EBULL, 0x226C15A31F9BF2C4ULL, 0x5FA6C401E181D39BULL, 
            0x694E221E7603DA7EULL, 0x583EF5987BB36A76ULL, 0xFFC623845EA0BB73ULL, 0x9887990C853916F3ULL, 
            0x558A1D3EB1BDF033ULL, 0x9DD63CBC20F4A1C4ULL, 0x9FE0C97089CD9248ULL, 0xBDFE1C274824DA27ULL, 
            0xDBBE931D7BB1A310ULL, 0xEDAC9DB00B911C23ULL, 0xCC865BDEA7FA8409ULL, 0x13CE12765B194582ULL
        },
        {
            0x5CBDE6E400DBCD7FULL, 0xC771DBECF7BDA210ULL, 0x72E4D5ED229E2FA5ULL, 0x793C52407DCDB28BULL, 
            0x17F5F24C4C796FF6ULL, 0xF543E96E8273E53FULL, 0x57AEDE429F0C3A7FULL, 0x8E62EFC4ABEBA839ULL, 
            0x06101A70263DF2A1ULL, 0x461B1BF75407B937ULL, 0xF69B736D3CC27EB1ULL, 0x9B6767A9ACCEAEB0ULL, 
            0x3AC8B07CDB62661DULL, 0x37F3E5BB000DDB7FULL, 0x117063BF7ED36475ULL, 0xF28EBBA31063DD65ULL, 
            0x82070E6B32448AE6ULL, 0xFE4FD42A163EF90DULL, 0x1B4F80B68E464AEEULL, 0x37EB9957E0240E3BULL, 
            0xBE0757A3C8677E6DULL, 0x6CD952F224197834ULL, 0x73A97A8A59AABF9AULL, 0xC479794992D3AE93ULL, 
            0xEEFF9AFEF337B8B8ULL, 0x13F91F316AA8D4DDULL, 0x5A2C3AABEFB3EB06ULL, 0xF9F7B7D65DB1104DULL, 
            0x6C3E714BFA2AB5EEULL, 0x675AC997D16C8C68ULL, 0xFA2A6DC25F633620ULL, 0x537E6D51172E87D3ULL
        },
        {
            0x327FFA22AA85BF51ULL, 0x5C5BC6EBF1EC4DEAULL, 0xCC9792ABB03F3E98ULL, 0xE89939E3AA8C8E23ULL, 
            0xA0BD0289E107AF11ULL, 0x70E329BD793A419BULL, 0x73127809E631E437ULL, 0xEC4B106028158A7BULL, 
            0xFBA57FDBECD6AE59ULL, 0xD479EDB57FD2F02EULL, 0xED9FD4C23FFA6418ULL, 0x6AACCFCC2A9B1BF5ULL, 
            0xE56EE59E79D0CF35ULL, 0x2CD17B1ED8407444ULL, 0x6A59D17816ACA74DULL, 0xB95A21136BAED9CEULL, 
            0x72218749C1871CDDULL, 0x361660B9EAD6B7A2ULL, 0xB85C92DA3C699E80ULL, 0x62408E13238A2E87ULL, 
            0xB35E1EF37DD2E85EULL, 0xDCF060F4E3D910CEULL, 0x90BBB84927C1F5EFULL, 0x477CFA3B9C07E5A9ULL, 
            0x858D863AB3E4B62DULL, 0xAF2F1C584E388A4CULL, 0x667B8BE1CFD6A107ULL, 0x470CDE0D4BCF85A3ULL, 
            0xFA0370F24528FF4FULL, 0xAC40D5862D75B403ULL, 0x75EF97CB293BC853ULL, 0xB15F4ED5F1B6FD83ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeySpawnConstants = {
    0xDD4E29BD938B6B05ULL,
    0x01FC2521D1BF802AULL,
    0x571F218556862FC8ULL,
    0xDD4E29BD938B6B05ULL,
    0x01FC2521D1BF802AULL,
    0x571F218556862FC8ULL,
    0x5C92E6BD23778C68ULL,
    0xCC3DF19C7E3B06D5ULL,
    0xDF,
    0xAA,
    0xD7,
    0x0A,
    0x06,
    0x29,
    0xE6,
    0x57
};

const TwistDomainSaltSet TwistExpander_Athebyne::kSeedSalts = {
    {
        {
            0x040BF397D717C1B5ULL, 0x008FAF96038D5C0CULL, 0xA25A82598E00EC7FULL, 0x9A0DCDA986C7E7BCULL, 
            0x4E653FA5F514EA34ULL, 0xF25CB9EB86E79D3BULL, 0xC888477E2135C8D9ULL, 0xDCC81C1BCCC597E5ULL, 
            0x3CF9B9DB79510ABDULL, 0x813F03BF31D81A05ULL, 0x0FD313D07CEFDA98ULL, 0x1DE9BED252E0E6B7ULL, 
            0xD0D6F4BEC2E62909ULL, 0xF27DC658DB8902ABULL, 0xE0053B6CF59E8230ULL, 0x9389BB916BCE7AC6ULL, 
            0x421EEC65A3283592ULL, 0xC83F26AF52A528AAULL, 0x78B38B31ACAC8104ULL, 0xAA869EC3D3EC5824ULL, 
            0xC1275068A80FD1FAULL, 0x9A36F475263FE67FULL, 0xC70E63EC2126AD49ULL, 0x213FED91E1C61752ULL, 
            0xD85AE08BE579A219ULL, 0x87CD02A62ED483CAULL, 0xC5CD9EA1BFEF50DCULL, 0x8560FF8597D8E870ULL, 
            0x4657FBB1D74FBB57ULL, 0x9D5D51578193BC8DULL, 0x717EEAF5EF9335C7ULL, 0x1D73452A9ABA4E9DULL
        },
        {
            0x4744DB670D44DFA8ULL, 0x2AAFAB5217334F16ULL, 0xF3E203D593189FFEULL, 0x58FDAD61F5F185F7ULL, 
            0x24374B226B89B724ULL, 0x8B001B7757CB6F3FULL, 0x09A70F865D245CA3ULL, 0xA8828D1E962C5B24ULL, 
            0x5EF9F48228137BA8ULL, 0xB2E3F577BCA6ED39ULL, 0xE96D8D3E47D2723FULL, 0xDD6CCAB6AB4C2035ULL, 
            0x6BE29801302AAF4DULL, 0x2734B4405519C172ULL, 0xC9D980AAF29B766DULL, 0xF229D385C27AD00FULL, 
            0x89F3458CD0EECFABULL, 0x17B50D04ECFCE69EULL, 0x5635FCD4014A9D40ULL, 0x1071DC86460FE3B3ULL, 
            0x5D812B4E30AD1B93ULL, 0xB7D3876EE8317377ULL, 0xDDB8AE24D4DD7273ULL, 0xF005A920FADDD0E1ULL, 
            0xD3BB98E40395BDF6ULL, 0x621CD333E4BAB2F0ULL, 0x719BCFEEA011E0D9ULL, 0x5F0DB47855310CEDULL, 
            0x35510722C02383CAULL, 0xDEFDE04487769CA9ULL, 0x1AEA724E3B30C3A3ULL, 0xB978C80F1343D4B3ULL
        },
        {
            0xBD7DD04D42BB020BULL, 0x75CF903F2A81A55FULL, 0xEBA27673BCCC2E53ULL, 0x6AFC95765D96FB5FULL, 
            0xF41E85204FEA04ACULL, 0xA089DE61B3330B51ULL, 0x30834D5C9F6D4967ULL, 0x8D1C33FFC09D8611ULL, 
            0x86EB884BC5E9E023ULL, 0xE34D03065F4F2867ULL, 0xCB3CAB0925A2AD52ULL, 0x53CCF64ACC2F9909ULL, 
            0x3F581739F6412084ULL, 0xD929733386C80FFBULL, 0x9ABABB21963949DFULL, 0x4EB703355CB903EEULL, 
            0xCB58A4B28BF017CEULL, 0x5640BA01DD689530ULL, 0xBA50C6F8305DBD27ULL, 0x90C64A14EE9976BDULL, 
            0x769E87391E4091ACULL, 0xED4E71C5F58B5DDFULL, 0xAC687A915749C0E9ULL, 0x1406404F81D36E3DULL, 
            0xFEADE5ACD3439CBFULL, 0x444F62246CD2DAA6ULL, 0x97A20DD27782F25EULL, 0xB0293E056A1E228CULL, 
            0x96F941AB96794C2AULL, 0xA2D82EE40A042718ULL, 0xC9B5C224C2B6D0D8ULL, 0x7FA92B36DB24058AULL
        },
        {
            0x04C32A475698F98AULL, 0x0D347698C4D37A88ULL, 0xC2EABFDA92F3E817ULL, 0xE823A8C2851FAF98ULL, 
            0x595D337F12795AD5ULL, 0x9F5BC6F8A46B1CC7ULL, 0x62B7729A5621B138ULL, 0xBC5D9BA2AAF45469ULL, 
            0xD1ACBA334B569102ULL, 0x25007E6FB9ABF7B6ULL, 0x2B2601BAECE8E3A5ULL, 0x7D32EC084A8CE787ULL, 
            0xFA339CE6A51348D7ULL, 0xBEE38799A9A67355ULL, 0x3CB95BBBFFAC1412ULL, 0xED4A4239A0BD8371ULL, 
            0xD161BD2A27FE816EULL, 0xCB58707AF5F209E6ULL, 0x654D87DA392081B1ULL, 0x62AF322FF5684744ULL, 
            0x53D70DD6625716BDULL, 0x4E57A19E5274B388ULL, 0x4B886EAD68BC3100ULL, 0xE745906BC7C1A22DULL, 
            0x547D166E17FAA0E5ULL, 0xB0293C8E17B85110ULL, 0x43DFF056804EA3C1ULL, 0x7B3F02CCADD5B2F3ULL, 
            0xDB5350FA617B3947ULL, 0xD8D90903A7152CC2ULL, 0x4541A6762EFA2725ULL, 0x9705588F00908C9DULL
        },
        {
            0x177227E4C538AAAEULL, 0x39230CED71165C3BULL, 0x0791F747AE9AC9CAULL, 0x9E1B6747D85B7F59ULL, 
            0xD4618A4D226D8CE9ULL, 0xA38C00BAB990D330ULL, 0x34716E9AD21D34C6ULL, 0x4803F17B1248739AULL, 
            0x9C62D2B99D90BA9CULL, 0x6C27B10BC8152161ULL, 0xAC379A917F3D33EEULL, 0x7675FAC5A27A5768ULL, 
            0xAD0D4BE6A8A67FB4ULL, 0x6C3D342EC3AAAA9CULL, 0xEC17F7C1A2CFEB49ULL, 0xDFC8E9D1387C3529ULL, 
            0xD29159A69D6E28CFULL, 0x01191A31A656807FULL, 0x2F0540E688B9FC3CULL, 0xE4317938A9BE2D61ULL, 
            0x949B5F6CEE84D276ULL, 0x2BB0E301E6DFEB41ULL, 0xC8D4358862B95F94ULL, 0x5B0134953B8ECC73ULL, 
            0xC714545DF779A5A3ULL, 0x0AEDD916D2DF15DDULL, 0xF3EC4461FC1A3F79ULL, 0x44CC7E8F6300297FULL, 
            0x2E084620B80CB134ULL, 0xCED41DA125E74037ULL, 0xC668821AC7A62E42ULL, 0xF03730D878AB53B3ULL
        },
        {
            0xD785D163AFFEF52DULL, 0xDB7E8CF286A141F4ULL, 0xD94FD757EDBF133AULL, 0x595B04C070277978ULL, 
            0xFC3B0399F91BC6A9ULL, 0xD21AAA3D23F22DC7ULL, 0xDB87F9E12416A6C3ULL, 0x0727931F976A623FULL, 
            0x4CB34DA62596A24CULL, 0xE9BC3AA95BFE8DFCULL, 0xF124FD1141EE15DFULL, 0x2D724DF56837169BULL, 
            0x180C23FB9B6E99A3ULL, 0xBDD03EB3640B7028ULL, 0xC104758631D95949ULL, 0xC2D16DBF10288F9EULL, 
            0x006D278E901077AFULL, 0x135A36F9CA0EA72BULL, 0xC5082E7EBD2307C9ULL, 0xC48B7E82B9FB3306ULL, 
            0x3DEB12F46DD83B8BULL, 0xA1E1BF648D1DB73EULL, 0xFB7186DE946955DBULL, 0x5801FCEE6C806066ULL, 
            0xA57BCE38E0771294ULL, 0xEFA7C47234BD0972ULL, 0xD7E15940BF138979ULL, 0x7F256E129B7231B9ULL, 
            0x31B6B4C8D20349C4ULL, 0x4396BB788FA2C644ULL, 0xA44D8F1C94A94588ULL, 0x88FE365B2716B499ULL
        }
    },
    {
        {
            0xCC7688238D02C6E0ULL, 0x4F0482C2209C01D9ULL, 0xAA5ABC55759FA5C0ULL, 0xDF6439D1B3F480F6ULL, 
            0x8D0FE61DABF78691ULL, 0x73F18087C084B23BULL, 0x4DA297550566601CULL, 0x569E04EA9B0062F3ULL, 
            0x2A42563B2CBC7D78ULL, 0xBA082A2416AB7441ULL, 0x159D879087E4360BULL, 0x150E34C198AB4276ULL, 
            0x580987831511C5E1ULL, 0xF3233FAED3F028A7ULL, 0x9BE3CD852A5E7AD2ULL, 0xC20561B547F9A0DCULL, 
            0xA5783C97547F880FULL, 0x0F5D28D8D9BF1AD6ULL, 0xE44B184CD0E96874ULL, 0x66DED6348CF46CAEULL, 
            0xDDDA513E78EE5518ULL, 0x6E3F3DE805565E76ULL, 0x2B6B8705C8F2459DULL, 0x054273610DDD7048ULL, 
            0x8B04449C0928EB03ULL, 0x6DE34EA61B3D4CF4ULL, 0x3E303373A4CF409BULL, 0x3C2858C0F06EBCECULL, 
            0x881F96DC60B3A236ULL, 0xA5C6B892FA9ADD67ULL, 0x933273B5A269EF19ULL, 0x20437B3E5BD354A0ULL
        },
        {
            0x9A6807D91EA34883ULL, 0xDFB7BD94B6AAA06EULL, 0xD2F5CEEB737D6EF3ULL, 0x9AE67974AEB5073FULL, 
            0xE66FD7F930ED04F7ULL, 0xDC5F43737050401AULL, 0xE107BD4E05E3346AULL, 0x4B939F7F807CCADBULL, 
            0x014D8FBAE28F0EA0ULL, 0xCB60C3569E057E0EULL, 0x5D7CF2F0865B7F7DULL, 0x62CDC9261A4B75B5ULL, 
            0x0DD1E117572E21B1ULL, 0x3D776C4920DE93A2ULL, 0x8CE0B5AB19B40C1CULL, 0x0AA100A70BFE6B7FULL, 
            0x343DF91B52A6922DULL, 0xD6992445D4915167ULL, 0xCDA47E854C60A50EULL, 0xDD66B4853F317132ULL, 
            0x3590F93C193994CCULL, 0x11AB989288FDCD29ULL, 0xCE503FC755A21E91ULL, 0x80AC6B83AC106184ULL, 
            0x5D8B94CC532A32A4ULL, 0xBB8809FD833A63DCULL, 0x75775E16D2102DB6ULL, 0xC6BAB82C2929C439ULL, 
            0x429B9DC93F482EADULL, 0xA8D280F0B2C480D5ULL, 0xF16D8289D1BCEB54ULL, 0xC6287EE6A1BBB30DULL
        },
        {
            0x75A2AE76A698515FULL, 0xF13F3BA2CB637B66ULL, 0x072C1A956DDE9CF9ULL, 0x519E62C569748F23ULL, 
            0xBE5EAAE67B2B0DB6ULL, 0xFB86207B8D8A2A46ULL, 0x1EDB148F5DE11A06ULL, 0xD8BCE5C702B04766ULL, 
            0x14E26A19A21C6B1CULL, 0x5F4A352B0309D153ULL, 0x007D5C7AA923AE5BULL, 0x3D63BFEC0851B9C2ULL, 
            0x4B9B3CC24BFD7E5AULL, 0x57E093B2C1583333ULL, 0x867F2E623BFA3D52ULL, 0x741596DF6D8E9962ULL, 
            0xAC041FEC9B37E10AULL, 0xE77B458230E6B08DULL, 0xBE5B687E79F8BDCCULL, 0x267A91949FA395D9ULL, 
            0xC31B6082E5F93F85ULL, 0x1E6C1BE1A587D5BAULL, 0xEAD602642B97F903ULL, 0xD60C5A269AE56D80ULL, 
            0x3B3636CF78F10E6EULL, 0x79119CBFEBE57CA5ULL, 0xD14A814648F43C68ULL, 0x8C143BBEAFFBB349ULL, 
            0x3DD787AA523FB6AEULL, 0xB02EA6FA9B7B55FEULL, 0x12E6AB2FE16C034AULL, 0x71023994CFCADC58ULL
        },
        {
            0x435CE50B1B63816DULL, 0x691DDA4BE3835B3EULL, 0xA7DF727FF191E9FDULL, 0xE24FF97FAF57F8F0ULL, 
            0x4F9290511DD7AA6DULL, 0xCD744278FBA71273ULL, 0xF63C15A88F2188CAULL, 0x07A69A560F5AF778ULL, 
            0xF6EE465C871E0074ULL, 0x15DF22B840469632ULL, 0xEF4BBA8523EBC31AULL, 0x52A52D56576A7FB2ULL, 
            0xBDF7634CDA72BAE1ULL, 0x2F05BBD48E4BD721ULL, 0xA02FBB337B0D2F89ULL, 0x061B731621FD1F82ULL, 
            0x6EF87966319A57E9ULL, 0x507191B3554842E8ULL, 0x6F081998B57AA9AEULL, 0x9CD29A1062C3F4FCULL, 
            0x26168DBA4C07DD86ULL, 0x15FEBF81482046F6ULL, 0x2803158C8DC7C5C8ULL, 0xCCB9FEEF5C715977ULL, 
            0x4CD781B644676B73ULL, 0x0E89F41AE185E795ULL, 0x7578A27A5C241EBFULL, 0x37610008353AC0B4ULL, 
            0x7C334D22C7EECC7FULL, 0x538295C547444D75ULL, 0x086F953231C4974BULL, 0x2F6D6BC5FF986BB6ULL
        },
        {
            0xA8A0E46040529FABULL, 0x71D34D8EF489570EULL, 0x125C2A88754F64D4ULL, 0x70AE1AD0C86A7E52ULL, 
            0x043BF2BF99C67AE5ULL, 0x0C3358B41217500AULL, 0x2E07BA58D0178F00ULL, 0x3D9196A519D3EAD3ULL, 
            0xF1B87C37438E9DB5ULL, 0xED74B24FEFFA0800ULL, 0x3249ECB4BBDEBDD9ULL, 0x1AF79988A987D0F2ULL, 
            0xB12D3CA72C4B8543ULL, 0x626C098ADC9D9AB0ULL, 0x4F5938BE65BB9AB5ULL, 0x0411B6CABF0D4315ULL, 
            0x9EBFEA4DA0C8D963ULL, 0xD3B4B4EBC5CB6D1BULL, 0x8A66EF3B6036DEFCULL, 0xF64A7505427B2BDCULL, 
            0xEABFEA39294C4DA9ULL, 0x066EEED88994F18CULL, 0x3DDDDE5C270FA409ULL, 0x7C497159280F8395ULL, 
            0x7581E35EBE6FEE1AULL, 0x900B194113EFCC9FULL, 0xA7F66A05A133F859ULL, 0x3EA30C54BE15F558ULL, 
            0x39272F43CE4B56E1ULL, 0x32DE0155482ED261ULL, 0x929CBABE14316F2FULL, 0xA740E3233037AAB6ULL
        },
        {
            0x8BB30C0636B9DD78ULL, 0xC2601AE80A992903ULL, 0x8608D99427A06E91ULL, 0xF7B1DB662527279FULL, 
            0xDB64441251813790ULL, 0x79C9087902711EC4ULL, 0x27F9583383175032ULL, 0xCC1D595498FF910AULL, 
            0xD777D6F0AB526599ULL, 0x39E30EBA59DEE799ULL, 0x3CAAE9664CDE46FBULL, 0x25358D137240DBD1ULL, 
            0x6810E97861651DF5ULL, 0x7E0ABF68ECF68705ULL, 0x46C8650C52F82BCBULL, 0xB482A7F2E870DAA1ULL, 
            0x8FB6A3A84817A482ULL, 0x72328079105752B4ULL, 0xC4E2BC5E3BE2BCF5ULL, 0xD0A16DE8AC9251B2ULL, 
            0x2F3E9D55B1FA9C12ULL, 0x0416F63739589BD2ULL, 0x2EE518AB1389C065ULL, 0x62D527B075CC8C2AULL, 
            0x62031E5E3711AD6BULL, 0xF4EBB17BF8E2343FULL, 0x2171BEF0C655AB9EULL, 0xD71130C07242284DULL, 
            0xCACC5E88A5C22AC4ULL, 0xC6B7FB61DFAA3371ULL, 0xA36074AC39743B97ULL, 0x6B434DFC1982D800ULL
        }
    },
    {
        {
            0xC1EE07383AB294DAULL, 0x65C2F88470D9DE65ULL, 0xC589B35CFA8C4B12ULL, 0xF07F4027E0BFF01FULL, 
            0x58A7D2214567D7B0ULL, 0x9BF421D994461277ULL, 0x782722989C646BA2ULL, 0x4F22E066A731A434ULL, 
            0x12F5F03A3AA5B79FULL, 0xFF01EFC889020DC6ULL, 0x8CD15E595574BB19ULL, 0x0058F2A9646BC915ULL, 
            0x72BCEA52F46CBD6FULL, 0x821A4E13A6A9C33DULL, 0xB425AD61B8890EA4ULL, 0x43CA855E4EFE1773ULL, 
            0xF9CC07F3ECC8DE7DULL, 0x294440727F0D59BAULL, 0x4D5B8139D7B53104ULL, 0x1DB019C91EABFFAFULL, 
            0x1CEEB84E62213117ULL, 0x73FFBDBEAC0FA1BBULL, 0x03D062550F15F5D6ULL, 0x76AFC9A8A1CBABB9ULL, 
            0x99EC5D64852766C9ULL, 0x64B2277FA5DCAB15ULL, 0x5529EA89B6222A5AULL, 0x3E4D6BA30C011BCCULL, 
            0x7A1CFC1ABED9C965ULL, 0x81501FF214651CF9ULL, 0xB0BAA2D836EC2696ULL, 0x6B617E0393301669ULL
        },
        {
            0x0BAC535CE5D8DDF8ULL, 0x46D934B0710E8D68ULL, 0x4AE55ABE12C5A915ULL, 0x0E59158BEABD8CBAULL, 
            0x144AEF767FDE26ACULL, 0xEC44F67603187936ULL, 0xDF1D47CE2716D2ECULL, 0x8E743ACD990E7B96ULL, 
            0xAEFE95747DC44900ULL, 0x67348341C54F5AF7ULL, 0xDCFC2AA128C552FFULL, 0x21EB9A7FAA55BCB1ULL, 
            0x0FD4DA1425E3AA85ULL, 0x74E6021302F73CC4ULL, 0x7A3C9E42C8E872DAULL, 0x6497E2B2512E605BULL, 
            0x4EA184D91F17F9C6ULL, 0xE053329A9C37A113ULL, 0xFA862E2A0CA9A52AULL, 0xDAD2D4987F1CFC20ULL, 
            0x2FE148571EBB824DULL, 0xAA7A3D26A82D0485ULL, 0x240020B851FDE2CEULL, 0xF44995B8C4C388AEULL, 
            0xA9EDB11024BC0D57ULL, 0x1E43FB390F5A321DULL, 0xE7C4D8B31224BFFBULL, 0x9D193DA59435369EULL, 
            0x297BA9744C80EA90ULL, 0x004BBF4BCE6A4E90ULL, 0xD931AE7BD15A202DULL, 0x7C1DA721E5FA14E4ULL
        },
        {
            0x0AD426E60C87ACFCULL, 0x75CCC12B1AE09A0BULL, 0x7A8B938D0984B760ULL, 0x5B4C22ACA4B77150ULL, 
            0xF94333CC0C8A69D6ULL, 0x038D41E2B768ED09ULL, 0x4FE7EF44FC793BC3ULL, 0x8AF7C88012676BBEULL, 
            0xD9760508CC552C5CULL, 0x0A418925B4098D82ULL, 0xE2A91E2A03CF0A69ULL, 0x7AB416FDE699F4A2ULL, 
            0xF7E408FC776F6674ULL, 0xCE2CEE10A1931ED8ULL, 0x093FC868177C397BULL, 0xCEF3CA26C0845472ULL, 
            0x9CB163133BD327F6ULL, 0x6EEF63E4CD0CCC56ULL, 0x299867AA9A3BFA52ULL, 0x7B2F8BC3254E1041ULL, 
            0x433EA7D4324EFDB7ULL, 0xC796CACE075B9B39ULL, 0x7F81050B7CA6E29AULL, 0x0D6CE8F8F515BB2AULL, 
            0xF53EE71E91F0E4A8ULL, 0xA43AD5398E4C62C7ULL, 0x5EBA9921FBA050ADULL, 0x7B17F32B41264E05ULL, 
            0xB936A89986805F14ULL, 0x2F8AF8D80CE9C47FULL, 0x8411A7652315A224ULL, 0x78C26CDB06BDB1DBULL
        },
        {
            0x393C5DD60A77F125ULL, 0x7B9DACDDB5AEA8A0ULL, 0x20A800DC6B940B4DULL, 0x497B9ABC5F650B4CULL, 
            0x9EEC414FF55543C7ULL, 0xA9A1724CF75C3CC5ULL, 0x335D675F8910E6A6ULL, 0xFA3C4137BC555E50ULL, 
            0x37AE9C5BE6E6E328ULL, 0xBFA085EC9F956F0FULL, 0x94E23DED8E501053ULL, 0x8E0C5F9BD1BBC0B9ULL, 
            0xA832AAD0A87464A8ULL, 0xB4F14ECFF14E223BULL, 0xD4CB07F55F6690ADULL, 0x969B327969DB64F3ULL, 
            0x199751903128DB21ULL, 0x6E4815187D3140CEULL, 0x9A2F21E5876D9AA2ULL, 0x8C554A1D59C826C6ULL, 
            0xFDA05E5339F48848ULL, 0x2DA11CCF45FD900EULL, 0xC9CF16DC5DEFD2C5ULL, 0x859257C630792A69ULL, 
            0x21356A11782F3592ULL, 0xAE1C63BB86DA7F12ULL, 0xCECA8FAC00BCB164ULL, 0xC19883BD17011350ULL, 
            0x62264CAEE34A43B8ULL, 0x9341FD10025E0DECULL, 0x7BA87559BB536691ULL, 0x31EC51D95715E65CULL
        },
        {
            0x02597795FB18B9C8ULL, 0x8FDA07AD68AFDE51ULL, 0xF723892EE8EE4155ULL, 0x80CB05AE4EB58C3FULL, 
            0x2E0423FECF79A14FULL, 0x9B5F85A24AD53032ULL, 0x786C050877B060B8ULL, 0x3A202475F51D7C4FULL, 
            0x28928E9D21CBF75FULL, 0xD3042081A70BEE53ULL, 0x56AC5E8B77511B61ULL, 0xDC201F0857496E6DULL, 
            0x6D7D2E4742DBC52CULL, 0xD369E57738050B4AULL, 0x72E0AA90D37DDB62ULL, 0xBF364F1FEAF06935ULL, 
            0x66B8212E38480D66ULL, 0xB7C5BFE0CFFC46B9ULL, 0x3B075F8657D4A0F4ULL, 0x1D0516152E94CAB3ULL, 
            0xF5CD7955A1BDBFCBULL, 0xD8C5FDF06D042163ULL, 0xCAF04C38B8E2DF6CULL, 0xFA2832DB7D54204AULL, 
            0x7E40D7457B7DBA5CULL, 0x1CC4FBD7A8909699ULL, 0x11A817C77D0C54C0ULL, 0x5332A844193EB80DULL, 
            0xDA49078C55449535ULL, 0x8CA82A8D4DB65ED5ULL, 0x2E799322B018F164ULL, 0x3514FE3CA7EAC0E7ULL
        },
        {
            0xB978C4AF1FF1DAD1ULL, 0xB90432BAA189025EULL, 0x2DF2C887AFD637CCULL, 0xE111DAB7AB299574ULL, 
            0xFCF41FD180D31792ULL, 0x4A834E527F303518ULL, 0x49A1B2E91B307D4DULL, 0x0DE423CAFA159968ULL, 
            0xF5EC900E4726238FULL, 0xA3E5AEC904F0EF3FULL, 0x005204CB6F0DE43FULL, 0x97C2ABEE965AB4F0ULL, 
            0x0492FC321CF56000ULL, 0x4EAFED8A7E5752CDULL, 0x9FEE043C4D61FB83ULL, 0x8E6BED3DACDBEC02ULL, 
            0x9F58487DE200969DULL, 0x9A33503B583A7C4BULL, 0x8DAC17DC47D314AAULL, 0x87E4CCD54E615FDCULL, 
            0xBB6963BBB2304C04ULL, 0x5D3C203C81B2D30EULL, 0x30DC41AB766EFA61ULL, 0xDC14BB542A1F56F4ULL, 
            0x2F79B25D616A89EBULL, 0xE247181127E69903ULL, 0x1B6CE7FFE0B1990FULL, 0xAB377BDD8CD98D9FULL, 
            0x01B3200E860BE7DFULL, 0x8717627D920CD00EULL, 0xFFABDC37F6318113ULL, 0x3A31B3E7BA2F2798ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kSeedConstants = {
    0x692161766E22BF91ULL,
    0xBB6B2DC97D5A75ACULL,
    0x8D58025F0E945C25ULL,
    0x692161766E22BF91ULL,
    0xBB6B2DC97D5A75ACULL,
    0x8D58025F0E945C25ULL,
    0x875D8D11E13A76ACULL,
    0x9FD6D47E48AC6393ULL,
    0x37,
    0x78,
    0x7B,
    0x39,
    0x63,
    0x26,
    0x79,
    0x68
};

const TwistDomainSaltSet TwistExpander_Athebyne::kTwistSalts = {
    {
        {
            0xDDEAC76F6CC54E77ULL, 0x936AE92BC368724CULL, 0x4AE178004A16B4DBULL, 0x7E5F6E1B9EC80401ULL, 
            0x1FDA71F39E5656E0ULL, 0xF17C23071C28BE1BULL, 0xC6C3118802E4DA19ULL, 0x4B5E0BC6FE5B9991ULL, 
            0x61AA5051C4CDFE89ULL, 0xAC63D81EE32626C2ULL, 0xEAC9E8BDCB566B12ULL, 0xC153D22BDB92F5D7ULL, 
            0xDD55439E9D814156ULL, 0x9F177BF31ABC849DULL, 0xEED2B80209B62522ULL, 0xC77FC13F93521095ULL, 
            0xAD3169A30FE49075ULL, 0x443FEF3F25DA801EULL, 0x9A55A1A9FDAE3852ULL, 0xAF9304C0DF2DA130ULL, 
            0x1C5484107D74EA58ULL, 0xB04DA4F725C6981DULL, 0xCE6E456DCC0678E9ULL, 0x82E86D4FFD9B0822ULL, 
            0x477463A78F0D230DULL, 0x763C0F2D2AA10B90ULL, 0x21901A28A099A441ULL, 0xC8EADDA77D23C9D0ULL, 
            0x62B7C463DBA1E8EBULL, 0x86E503D6B4286D7EULL, 0x64042561CDA6DC67ULL, 0x06A8551BB324EB96ULL
        },
        {
            0x04D6C924B92D631FULL, 0xB1365C43FB5CEA42ULL, 0x8C6022B4B0E1524DULL, 0xDADBEB19CD938AD9ULL, 
            0xAF8647A29579DA9FULL, 0xFCE1D88B79789AF0ULL, 0x429F089AA7C0B1E0ULL, 0xD77A66090DEBB32CULL, 
            0x417719D611735BE9ULL, 0xA4F23156B171D91BULL, 0xF653BAC7BDB62BFDULL, 0x1223E92B6131F883ULL, 
            0x53BABA2D1DEDB341ULL, 0x8C30FAE3C4D4C75EULL, 0x5731B7CE1B99D955ULL, 0x3B80F690F02B3571ULL, 
            0x34589B9912BDEF8FULL, 0x77BA5A8EC73636CCULL, 0xBB8C9CF1B566794DULL, 0xFA476A3CE7FA9D08ULL, 
            0xB718776C3A9D0279ULL, 0xCD08CE93E9223090ULL, 0x51227F6312A39A06ULL, 0x4683C1067437F1CCULL, 
            0x4C5284AB7B6500E7ULL, 0x2E6015C5A29C2943ULL, 0x0E6223EF70F0908DULL, 0x9EB6F75EB891C75CULL, 
            0xFD3686DBF3E7D4C1ULL, 0xFCF1711E4D3131F1ULL, 0xA979522B18FE723CULL, 0x29D7305E86271983ULL
        },
        {
            0x57A016615887A890ULL, 0xF0518900FEE97B60ULL, 0x3EC2D3D7B96C509CULL, 0xEC5C2730B3E714ADULL, 
            0x7F3257843CF4CAA6ULL, 0xF45205B0770F8A4CULL, 0x12B9D5F5D3710D1BULL, 0x556D560086D7600FULL, 
            0x34B047E14051C5F2ULL, 0x980F4B10CC541C50ULL, 0x3F73CD0CA96216CFULL, 0x25586639B7194B63ULL, 
            0x5D0EE32999EFD1B5ULL, 0x36CE1B3707B8CDF1ULL, 0x0DD0C231AB225E4BULL, 0xC22398AF30DD4E91ULL, 
            0xA1DA76A5107992ADULL, 0x220E640616EFFEDFULL, 0xEF1B2E0FE227A0D0ULL, 0x6DD2109F70B01EA2ULL, 
            0xCA8CF8129E08697DULL, 0xA61F42636E1089D7ULL, 0x36C18C81CBFD041EULL, 0x009D8122607E7341ULL, 
            0x9E7956DDD86851D9ULL, 0x668CD42A3557ED42ULL, 0xF6BAEC7AE1EACB5BULL, 0xB2642AB27280B3BEULL, 
            0xE91F58739BABA036ULL, 0xCD9604A551CBD01BULL, 0x0D5AB6F35FC90EBBULL, 0x943A5BEBC118BE4FULL
        },
        {
            0xA830708ECC0A7417ULL, 0xBA2BF074BE971A5EULL, 0xD02426AD8560CC91ULL, 0x5D42D7680008EDA9ULL, 
            0x9438FF865A66C5E0ULL, 0xCAE6DD3671C83D39ULL, 0xF6E58CA67065CF16ULL, 0xFC2E85705A82D37EULL, 
            0x2FF35124F990D97CULL, 0xB3E5FDF0FB2978B3ULL, 0x3E0DDE5F5334F48AULL, 0xFCF63E460912E06BULL, 
            0xF66620DDBBE0B7E0ULL, 0xA79D733C5C916E8AULL, 0xA07A46796D5B6D2BULL, 0x4F4064B072DCF2B5ULL, 
            0x8875F4CA8144D2BBULL, 0xF8C76592EFFC1B6EULL, 0xA4D63BB9BE6219D7ULL, 0x88D25F504FBD0758ULL, 
            0x834DFCD85FBB1FFDULL, 0x52E2ABC034ECD0EFULL, 0x64926121BF661F69ULL, 0xC0D2FC3D9FDEE65DULL, 
            0xC7817FAE4D779AE7ULL, 0xD46E1554907F9EB9ULL, 0x83CC3C96ABF5CA94ULL, 0xEE34D1DDDB938E14ULL, 
            0x0DF83597F2425B53ULL, 0x50467906CB5BB7AFULL, 0xA6897885D50EB8DBULL, 0x5998A0E6EEBD7EDEULL
        },
        {
            0x151DDD0893C5C0C7ULL, 0xF9D4016484BB6133ULL, 0xC5E63F7659BF489DULL, 0x1A83272A06412A1EULL, 
            0x1F5F1F6AB338364DULL, 0x86C3DA3E5EE8E212ULL, 0x670CE76214998400ULL, 0xC46FFCE0B0432B37ULL, 
            0x7DF47A012BCF1663ULL, 0x0047357CF95AB224ULL, 0xC3A0C5D5FC654D48ULL, 0x71A1DE48380D64FAULL, 
            0x70110BA398C5FAA7ULL, 0xE160BA10B3E59041ULL, 0xD992C44712840E3EULL, 0xD1E5A0EBBFA75F0FULL, 
            0x782CB6F042573A29ULL, 0x80B23E849306ACEFULL, 0x0180860C2058FE3FULL, 0x60BCB2B5AB3B12ABULL, 
            0x8B5D1A5B4009B975ULL, 0x919DAA6E887B9265ULL, 0x1B5293F3C5BC4738ULL, 0xCF7A7E5C544D5318ULL, 
            0x377892E6769EB544ULL, 0xA922302B318E8941ULL, 0x14591A3271D11F7FULL, 0x381EF78AFEB355E5ULL, 
            0x6F1AA6D3B85F7FC2ULL, 0x774313CE73ABA4ACULL, 0x1B1D133AED8D2F34ULL, 0x382EC2CC41042C6CULL
        },
        {
            0x06EA5C1BFDDC6B9EULL, 0xA2A7A88670B42536ULL, 0x5AD14692D2B16E0EULL, 0xF3EA806BE0131A84ULL, 
            0x53F22B2DA5F4EF25ULL, 0xA2C1B4DA31DD05EBULL, 0x820E7FBF9D968872ULL, 0x3ADA6B66CE246B39ULL, 
            0x53CDCC02266964E3ULL, 0x4269D9BD1CC62960ULL, 0x16295FD4396B3C3FULL, 0xAB491447321CBAE8ULL, 
            0xC3A4E51B226207E1ULL, 0x42384D92308E1E0BULL, 0x8ACB6CC5A3E1E280ULL, 0xF67C4E3796C16322ULL, 
            0xA1589A59623E820CULL, 0x661E05768D61E790ULL, 0x81D00047DF6F586FULL, 0xE9C4AD8EE207C1E9ULL, 
            0x7BC00500FCF3654EULL, 0x4542A15CC0B2D4D2ULL, 0x33976F64D05AD3D5ULL, 0x3A816832A35A01C4ULL, 
            0xBB0A985010D9DCFDULL, 0xCC950D7A4ED082BAULL, 0x51893F69DB9E1555ULL, 0xE2BAEAA986ECF2D0ULL, 
            0x6EC28F095F767998ULL, 0x0E94DBE8852597B1ULL, 0xC789C32C9A7F8697ULL, 0x0277FE61CF9FE56FULL
        }
    },
    {
        {
            0xA919A5279108AC79ULL, 0xB555CE86A4476DC5ULL, 0x69737160356F8AB2ULL, 0x2F09FBF2B30A5CC4ULL, 
            0x6368BA78A6C7A46DULL, 0x0392A42952E89591ULL, 0x35F4E9D7A8044E25ULL, 0x1E1163C8D45CF1EDULL, 
            0xA43C1922CAC29860ULL, 0xF7442F62FC49A490ULL, 0x8205102CF4E37216ULL, 0x4AB8F67171D6BDABULL, 
            0x3C3F2F9643E03423ULL, 0x0035A55302CE2AD6ULL, 0x2E7BD8984EDDF8CFULL, 0xBBB2CD48B2926876ULL, 
            0x34252BC15E1C6E02ULL, 0xF4EB9090ECAE73DAULL, 0xFE7037A9CAD71593ULL, 0x2B90EA32822592EFULL, 
            0x3CC8167AAEA97C08ULL, 0x9A8F61989DE0E859ULL, 0x82013FF2D622963FULL, 0xBCD7E45C90E8C831ULL, 
            0xFF57EB60CE2B6AEBULL, 0xFF04B081FA0F77EBULL, 0xBF125D0D26876CE2ULL, 0x1976E63809495406ULL, 
            0xF71B38AF2EF0A959ULL, 0x2EA0996663C27D89ULL, 0x59848C03C98215C1ULL, 0xD2A3CA3AA865FF88ULL
        },
        {
            0x103D31E8506B4615ULL, 0x6DFE4878FECA1488ULL, 0x929DF69D67B9F3DDULL, 0x3C9F0CCA2BE44AE5ULL, 
            0xFDB655221B60CE9FULL, 0x9C08267900144D27ULL, 0xCBC41C84F863590CULL, 0xBC3F363ED898E04DULL, 
            0x9E94031A8CC914FAULL, 0x794054BC24526BB2ULL, 0xDFF26FF4677D5E88ULL, 0x13B6FD305097F860ULL, 
            0xDF2EA8ADC1E28BADULL, 0x80313C94F4734AB7ULL, 0x3A368FD9FDBB3F52ULL, 0xABFEB70142614C6DULL, 
            0xD0321294738428DDULL, 0x595DDCCBB121538BULL, 0x62D0007121E4B20CULL, 0xF1CA0F61E459B6E2ULL, 
            0xDAF40C3D08B69920ULL, 0x5D573AD587DEB9C9ULL, 0xF1E55EDD8CE0806FULL, 0x3F7541EF7D35CDEFULL, 
            0xA6F426911A7CFCB3ULL, 0xB04B233B2312BDF1ULL, 0x81420E37FC362BA5ULL, 0xC8A0DDBD34EF977AULL, 
            0x19D89A5A93430DFCULL, 0xE47DC4F32F118100ULL, 0x39FB9F94A7B383E7ULL, 0x4E2C5E4B7D6C4FD7ULL
        },
        {
            0xD5499E63475F4742ULL, 0xE730D731FE686D9AULL, 0x8DB28E3D1F6B1215ULL, 0x56007299C4D6A073ULL, 
            0xA651758A4E48684BULL, 0x883B041B4A8F9E1EULL, 0x07505404A2E88933ULL, 0x86325C57071DACC3ULL, 
            0x1B101892EAA07F90ULL, 0x13836DB7554CD693ULL, 0x8845D6C7BC0D3C55ULL, 0xBF688FCF1738F5BDULL, 
            0xB26F1398FB4BAD20ULL, 0xC45869A7AAEF8287ULL, 0xEF28D44A8CC46D29ULL, 0x4788AEE0A7ED95B2ULL, 
            0xD2120210B3963557ULL, 0xB70E14A0D58AAE6CULL, 0xD5CF5166506342B7ULL, 0x9DD9736A654D120EULL, 
            0xF7931925EAFEBEF2ULL, 0xC4CFAD2ED283744BULL, 0xE8D6E97785CB96B0ULL, 0x43B068C419ECBF32ULL, 
            0xC0F7C8256BF85104ULL, 0xE13843B155EA3852ULL, 0x76701B493C218947ULL, 0x4A1F4C607FF9A04EULL, 
            0x91D9EB17EE67EFE0ULL, 0xCA703C7B96FC4B1BULL, 0x40924293A87B9D32ULL, 0x709703030DE6B7DCULL
        },
        {
            0x0683D998A95EAFE7ULL, 0x68AFF6E1D6451C36ULL, 0x941615629B17B629ULL, 0x96B44311EE3FF176ULL, 
            0x9C318A3726184F5CULL, 0x21D1BF55B34D90C4ULL, 0x694E5D5D1628C576ULL, 0xC200601B44E7B6A0ULL, 
            0x23EF99504DF4F564ULL, 0x8EC09297AE48CCE4ULL, 0x61A0612E5088F00EULL, 0xAF02B25428F7B3CDULL, 
            0x36D5834E69646F6CULL, 0x91658A718AD60CB3ULL, 0xCDDABB29FE474C1FULL, 0x1DE84335BFCF45C6ULL, 
            0x42CF3D852F354772ULL, 0x76E5FDD54AA788C3ULL, 0xE8E9F125F4EB33B4ULL, 0xF40B9581B76E008AULL, 
            0x24E75AF2A091672BULL, 0xD88DDCF99BC8721BULL, 0xBFBCBE2248529EDAULL, 0x08C440E6C8AAEBE5ULL, 
            0xFFD520BC8C0F2EB4ULL, 0x27A9EC69E670E661ULL, 0x4F5A15C337E6F7E6ULL, 0x01A2CAF885CEDDF6ULL, 
            0x026BBCAA9B85C292ULL, 0x19909CEDA3308A10ULL, 0x5435BB228FD57353ULL, 0x65C056ABE7FFF6ECULL
        },
        {
            0x71171D29ABF4CC9BULL, 0xCB4A72A6FC39DC6FULL, 0xD6307A6FABD45287ULL, 0x990D1BAC3FBC488AULL, 
            0x4B16A160390B3C36ULL, 0xC259864AC8718816ULL, 0x7E63476277C01725ULL, 0xEC7BC6065555332AULL, 
            0xE69D9CAA67442358ULL, 0x61D9C3F570036DF7ULL, 0x0B95F0CCB3B50D41ULL, 0xE0DFC89243E9E8C1ULL, 
            0x0EB7E3207A6FEE98ULL, 0x0A22BD5B257B3B7CULL, 0xCA615547056AE95DULL, 0x5CCB8F39D67A2DC3ULL, 
            0x99A4427BA32696E8ULL, 0x3AD8C00BFE8724BDULL, 0xCFA77A8512CEA533ULL, 0x585E889A5D742FADULL, 
            0x62100598ED1952F9ULL, 0xC160A6EA78695B26ULL, 0x1229432BA50B0974ULL, 0x4C52D947786A4AFBULL, 
            0x758668AFFAC53D1FULL, 0xCDC48E15E4D5F042ULL, 0x547CA92A17B0555EULL, 0x46451E8BEF8526A3ULL, 
            0xFBAE9505AE860D11ULL, 0xC2FF1EB846B7C820ULL, 0x84B9415D4F6FD702ULL, 0x5C93D03112792A9EULL
        },
        {
            0xB5405A4AE7BA4E29ULL, 0x421354E975E915AAULL, 0x7F9A3D1B238A657BULL, 0xE0A0B93AFDBDF000ULL, 
            0x87F5705538DD2303ULL, 0x9E827F3085F2BBEEULL, 0x219458E2C22B9C71ULL, 0x12FEF223BA96497FULL, 
            0x3E6D92CA41E9A59CULL, 0xF3A13A85B2FBA626ULL, 0x5FE64FE476B2ECF8ULL, 0xF60EE54111D58E54ULL, 
            0x004F6742CBB3AD0EULL, 0x1AD25AC79960271AULL, 0xE3B34BC2DD0CB5FAULL, 0x8DE740DAFBB8BA04ULL, 
            0xDAAD39855733CEF3ULL, 0x82444BD752A3194EULL, 0xE4FB62884DD56542ULL, 0xD8038679043F4F11ULL, 
            0x42F3BC3E9AD65908ULL, 0xA2EE162982C4C556ULL, 0x307FD3462C5EEB4EULL, 0xA34D0D7A05C26848ULL, 
            0xBA26B7EC694C475AULL, 0xF7B6141232342A9FULL, 0x27C068B6093874E3ULL, 0x7F72DDE0996675F6ULL, 
            0x92FEBA46BFDBB049ULL, 0x03336A3833EB85DEULL, 0x0B756986B92FB740ULL, 0xE13431112670F6DBULL
        }
    },
    {
        {
            0x0ADC013D9DEBADA4ULL, 0x183D6B3A799CC069ULL, 0x8CBA4D073FEADF6BULL, 0x3552A59CC1B631DAULL, 
            0xA4632D9F8D351DA4ULL, 0x7C6E25CBB1B930F5ULL, 0x0A1C72A522FB8E90ULL, 0x0131D69522C04142ULL, 
            0x80CFA3D6A8A28B9AULL, 0xCBAD5B27946720C6ULL, 0xE247AF42C2542F69ULL, 0x063534F75277766DULL, 
            0xBE102ECFA8C76656ULL, 0xFF5626159D958CC0ULL, 0x3B5357F26AF79207ULL, 0x930E7B8101B02967ULL, 
            0xD42F57BF38FC1195ULL, 0x8344F239E772934FULL, 0x1A79B60A09641DE0ULL, 0xD23ABFFD3D52BE34ULL, 
            0x12160C524CC78DB0ULL, 0xE59728C943397436ULL, 0x8C8CD6B086CEDAE2ULL, 0x6CAE8475F9B4CF82ULL, 
            0x5E33DE77FB6007C0ULL, 0x7FDBB91EECF0087DULL, 0x5B3A2A8F916A846DULL, 0x7BBF6A7651524590ULL, 
            0xFCD9C9899B02583AULL, 0xDDEDED69211770F4ULL, 0xEA849FB3A903AE76ULL, 0xBD471893BF530F72ULL
        },
        {
            0xC8DFDED1E527A23CULL, 0x00859FF96C6EE38BULL, 0xE406E0CD0A90A606ULL, 0x696858E0D78F70B9ULL, 
            0xED78763E58E38439ULL, 0x78CDEC6F62C7C2E8ULL, 0xCCC468DF64C2A674ULL, 0x4D6CEE3ED2979B80ULL, 
            0xF89769404E18D0F5ULL, 0x4E612B6B38F8648AULL, 0x1033CAE3B42A4CEDULL, 0x825330B7EB38E177ULL, 
            0xA140A1DAF5EB0652ULL, 0x8688EEF95D5994B1ULL, 0xA1DF973148EA4A92ULL, 0x1F1600303FF1A70AULL, 
            0xA0426A7675E8EEFCULL, 0xD8A9C2410CF5E05AULL, 0xEA2E811489D7B22CULL, 0x83DD2AD89D82DA6AULL, 
            0x894C82CC4849537DULL, 0x6530529AC4486D56ULL, 0xF84E69FDB57B168AULL, 0x346E09654F15B377ULL, 
            0x37499273EB0BE1AEULL, 0x1781697C81D11B4CULL, 0xF9A7E2BE9652494FULL, 0x0682B70B802CB4B2ULL, 
            0xD6A2EAE207CE8AC6ULL, 0xC6EFA59974A5CF33ULL, 0x27F47AB6CD97203BULL, 0x74D6488888E0C03AULL
        },
        {
            0xEABF7D0C301F64E6ULL, 0x31569680256F5FA3ULL, 0x4BEDFA2EF5FBF1F9ULL, 0xD58F3EE58049DBB3ULL, 
            0xCC8B150B10130F65ULL, 0xF2728183A92B078AULL, 0x9B451B1A8F5FE74BULL, 0xCE2EB410C41BDC19ULL, 
            0xC2DE574CE18926DFULL, 0x0F29E5871A4E6A5CULL, 0xF8439EA8C833D7F0ULL, 0x727DAE7C4D9B8040ULL, 
            0x9ED0F2A562FBDE86ULL, 0x64FEC5E4B588EA4BULL, 0x12DC123B354A012AULL, 0x5D76D4AD767BBC25ULL, 
            0xE53ECAD8C52BCBC2ULL, 0x77FE5F35F69F3715ULL, 0x55F900995FD06EEAULL, 0xF6B64A63BFB09AEFULL, 
            0x782FF06E1D24B40DULL, 0x3543C73F6B75EE5AULL, 0x5F6A8416FB2DAB1CULL, 0xBC8444D7B8949897ULL, 
            0x4624FDCCE6548A21ULL, 0xB4D50FA6707CDAB5ULL, 0x3952DF37DCCD36E6ULL, 0x05122AA23EBB0F05ULL, 
            0xB255C52D1A1A1106ULL, 0x2C6EB114B49C0CADULL, 0xB294482CCB8E583FULL, 0x4C226A70895CA7F6ULL
        },
        {
            0x0544F4040BFB8A39ULL, 0x3D75A5F6BA9EDD72ULL, 0xFF054215D177CC9EULL, 0x7D6E2550005CFBC5ULL, 
            0x5FF1AF0877E95F68ULL, 0x3B08A7E3688A9812ULL, 0x9880C63E7E4ED571ULL, 0x10FDE6B35F900470ULL, 
            0xB4E36FA630A158F3ULL, 0xE3BD4194C88FCB05ULL, 0x986C4E2F59824E77ULL, 0x6EC774A24DFA4172ULL, 
            0xADE1CB0AE6EE50F8ULL, 0x83AE3D37BBA71BD9ULL, 0x1A0CA27EAEAD7891ULL, 0xED674BB65349FC0CULL, 
            0x92DA1F3B2E11A4ADULL, 0x95EF1591D8878BC9ULL, 0x36009A9D4AE4B8EBULL, 0x1061CE352EF0D66EULL, 
            0x63F40C2EFD4926BDULL, 0x64274917E9F8FD3EULL, 0xB8E45867B49DF3F9ULL, 0x6EB892362D972780ULL, 
            0x62DD04E31E220775ULL, 0x322D14764B4DE764ULL, 0x26D0D59B46FA5533ULL, 0x483D7AEC916D55F8ULL, 
            0x333E0FE6A0226E4CULL, 0xDBC1FC9939B51263ULL, 0xB5C0725D91A3EE63ULL, 0x268089FF1FB94DEBULL
        },
        {
            0x1076B63FDFB7F749ULL, 0x255368E0F05C1EA4ULL, 0x66D36DADC84B61C5ULL, 0xBF65EA645605C650ULL, 
            0xB91CDBF933181CEDULL, 0xF7265A78EDB04076ULL, 0x2E0CE10FF1E46245ULL, 0x2CBE616CC3F4BCA7ULL, 
            0xEEC6C2C6E5451F2CULL, 0x9E92670FE8353BAEULL, 0x54FB42DA78BA1AC7ULL, 0x4245D664DFAACAA1ULL, 
            0xF1AED2DF5798918FULL, 0x81FF5D433BBD4EB1ULL, 0x4AB4FC5AE190425EULL, 0x0482B3B43BF798D4ULL, 
            0x398D481B1A01C359ULL, 0x966A493767165C0DULL, 0x6F75D23D3866E097ULL, 0x0997BF7D3158D639ULL, 
            0x9A7BD5D8A66F4BB2ULL, 0x931688C2B142D424ULL, 0xDD23DFA3502DD62FULL, 0x44283A633BADBE68ULL, 
            0xCD4F1955778C4BAEULL, 0x654A568126298A99ULL, 0x9033B8DF8D9444EDULL, 0x6DB44952873EEE7AULL, 
            0xFC816DE610499F82ULL, 0x5299C9A415D3A6F5ULL, 0xD5EECD2141FB2D18ULL, 0x0D9F649CCA84D38CULL
        },
        {
            0xC3A99E9F3A612454ULL, 0xD7C67E6C5F4CC0FEULL, 0xB39A12C019019AE5ULL, 0x01B302EF2EA469FAULL, 
            0x1F1864F2CCAF90B3ULL, 0x927F64967F63A06EULL, 0xF4A023C6DAB4AC90ULL, 0x8E286D09824E1727ULL, 
            0x9DC1379665FEA83CULL, 0x7FF13EE3FB8D697EULL, 0x107C42E675984E50ULL, 0xDC35F94459AE1E2CULL, 
            0x90F262BA65FED892ULL, 0x94BBD5CFF66C73C0ULL, 0xF912A9D7626388E5ULL, 0x465A1642667F338AULL, 
            0xD50E979B45C23676ULL, 0xEBCB162B5ADEEFDFULL, 0x1FB37281A3EC87F9ULL, 0x25A8160FA5D2F964ULL, 
            0x2157375E7EC41B18ULL, 0xD6E44C45ABC2D0C6ULL, 0x5DFEDA693014455AULL, 0xE53D0896C26E5E04ULL, 
            0x11C7C8F180822970ULL, 0x295997426E4E765CULL, 0x41FC3BDE0B6712F0ULL, 0xCBAE399587B5DFB2ULL, 
            0x939EF6CE3422D78DULL, 0x8E1152454543B285ULL, 0x6E1B5718336D12C7ULL, 0xB10C831C4E9CEE15ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kTwistConstants = {
    0x9F71DEF06A8A1FCCULL,
    0xDC7136488A503DCFULL,
    0x5502E7E794EBC89FULL,
    0x9F71DEF06A8A1FCCULL,
    0xDC7136488A503DCFULL,
    0x5502E7E794EBC89FULL,
    0x642E258449CEAEE3ULL,
    0x17404C2B15A6E704ULL,
    0x88,
    0xAB,
    0xC8,
    0x64,
    0xD4,
    0x03,
    0x88,
    0x69
};

