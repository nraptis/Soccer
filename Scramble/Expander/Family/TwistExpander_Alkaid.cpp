#include "TwistExpander_Alkaid.hpp"
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

TwistExpander_Alkaid::TwistExpander_Alkaid()
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

void TwistExpander_Alkaid::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC3599F276BFA2C92ULL; std::uint64_t aIngress = 0x98542801AEE3D400ULL; std::uint64_t aCarry = 0xFCB626C3FBFBC1DCULL;

    std::uint64_t aWandererA = 0xA30159DDA0192A2FULL; std::uint64_t aWandererB = 0xA46DA481E7F93412ULL; std::uint64_t aWandererC = 0x8E00D1629862B59BULL; std::uint64_t aWandererD = 0xD10E796CE701DD99ULL;
    std::uint64_t aWandererE = 0xA137453399CC6A0BULL; std::uint64_t aWandererF = 0x9F886F113BD6C1E0ULL; std::uint64_t aWandererG = 0x8D32DC725CBC53E9ULL; std::uint64_t aWandererH = 0xBE8489ABB5B4DB27ULL;
    std::uint64_t aWandererI = 0x8B386C8BED6292E7ULL; std::uint64_t aWandererJ = 0xB55C42EE03D25920ULL; std::uint64_t aWandererK = 0xF9957C893FAEC456ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB97718339E55CF97ULL;
        aCarry = 0xAA8F65F48E576CBEULL;
        aWandererA = 0xF194983A86CCD04DULL;
        aWandererB = 0xB5B682946AA1E1A3ULL;
        aWandererC = 0x8A9F4A094C229E69ULL;
        aWandererD = 0x9E3163DE9269831BULL;
        aWandererE = 0xEA7EE1FCDB1814D1ULL;
        aWandererF = 0xA683CC65FBD32D0EULL;
        aWandererG = 0xBDE2094824BB522DULL;
        aWandererH = 0xD6DB9B97D8FFE036ULL;
        aWandererI = 0x852D195DF96B9513ULL;
        aWandererJ = 0xF4A10C034623ADCCULL;
        aWandererK = 0xD177BE7997827B89ULL;
    TwistExpander_Alkaid_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B6DF3A4CED31AE2ULL; std::uint64_t aIngress = 0xCCC662EB43A65F8CULL; std::uint64_t aCarry = 0xD9C50F3BC00B5CF0ULL;

    std::uint64_t aWandererA = 0xFEFAB8DBBBE4E6C7ULL; std::uint64_t aWandererB = 0xC303416BB48CECA5ULL; std::uint64_t aWandererC = 0xA1285AB18D2EB3E8ULL; std::uint64_t aWandererD = 0xAF09F91A32390F96ULL;
    std::uint64_t aWandererE = 0x896C5C1280A1F585ULL; std::uint64_t aWandererF = 0xA2C4999020448850ULL; std::uint64_t aWandererG = 0xD7BBB157143A3969ULL; std::uint64_t aWandererH = 0xB1CE918288CBED9AULL;
    std::uint64_t aWandererI = 0xD10E7D0C44468692ULL; std::uint64_t aWandererJ = 0xA6772161695E2049ULL; std::uint64_t aWandererK = 0xE433DB1C276F4B73ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA9E0217EB7DA4EE1ULL;
        aCarry = 0xB816A63DA2197268ULL;
        aWandererA = 0xB790021B74A84D51ULL;
        aWandererB = 0xF4B9E2D50ADF9D20ULL;
        aWandererC = 0xDBC754735D1B7715ULL;
        aWandererD = 0xFD5A0B941F7DE58EULL;
        aWandererE = 0xDCAA22890D5DE195ULL;
        aWandererF = 0xD64C74656A051024ULL;
        aWandererG = 0xA843F802C8C24AA2ULL;
        aWandererH = 0xA03501BC2E167F50ULL;
        aWandererI = 0xBBD91A70B9EA4367ULL;
        aWandererJ = 0xF91AC2D5FF01B462ULL;
        aWandererK = 0x92ED7B69A351D84CULL;
    TwistExpander_Alkaid_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC9FCE9F6B7AC854CULL; std::uint64_t aIngress = 0xA6FEAED901E62D77ULL; std::uint64_t aCarry = 0x8BE34BC604709AD0ULL;

    std::uint64_t aWandererA = 0xB300651F27BD08DCULL; std::uint64_t aWandererB = 0xAABDC903A63ED29AULL; std::uint64_t aWandererC = 0xBC6E291A2304E5C8ULL; std::uint64_t aWandererD = 0xA542F3A53489A3C2ULL;
    std::uint64_t aWandererE = 0xC6ED3391E69A9193ULL; std::uint64_t aWandererF = 0x854506179DC77F10ULL; std::uint64_t aWandererG = 0xD135A32368842D0EULL; std::uint64_t aWandererH = 0xC3A2D0D4B1030828ULL;
    std::uint64_t aWandererI = 0x87CF3CB7EFA57441ULL; std::uint64_t aWandererJ = 0xFD91CA6C0560732BULL; std::uint64_t aWandererK = 0xB481E56A9C798BC5ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD3415068B953678EULL;
        aCarry = 0x9FA7AA17D3F9F110ULL;
        aWandererA = 0xB840B50A55985AC9ULL;
        aWandererB = 0x8BC968E3F37079EBULL;
        aWandererC = 0x92E705F8D53CEAFBULL;
        aWandererD = 0xA03A0B10AF6912D3ULL;
        aWandererE = 0xDBFBB1AB9D318523ULL;
        aWandererF = 0xD152EBF6F38F028FULL;
        aWandererG = 0xA1740D53157003A8ULL;
        aWandererH = 0xB313D2510768983EULL;
        aWandererI = 0xF31C6BF52C57932CULL;
        aWandererJ = 0x90544EDF1F75AD21ULL;
        aWandererK = 0xCEA29D2E7FA2AE6EULL;
    TwistExpander_Alkaid_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB86E589CD2971B3DULL; std::uint64_t aIngress = 0xB54524CFFA4A1B08ULL; std::uint64_t aCarry = 0xB290556CE4B5830BULL;

    std::uint64_t aWandererA = 0xEDA90FB223DA84CFULL; std::uint64_t aWandererB = 0xD1332702A2082026ULL; std::uint64_t aWandererC = 0x84E2FE44DEC7BB73ULL; std::uint64_t aWandererD = 0xDEA8FCE4CFC039EEULL;
    std::uint64_t aWandererE = 0xE379CB83DA496C26ULL; std::uint64_t aWandererF = 0x9F36B062CFAD8A77ULL; std::uint64_t aWandererG = 0x99744F2CA2DD5578ULL; std::uint64_t aWandererH = 0xDF97F1BE81DF87A4ULL;
    std::uint64_t aWandererI = 0xB6F827D559F930EFULL; std::uint64_t aWandererJ = 0xCBF9CDEF05B21639ULL; std::uint64_t aWandererK = 0xF0E5493C0F4A4477ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFEA5FE2E23051BB4ULL;
        aCarry = 0xB323C3443374B687ULL;
        aWandererA = 0xDAA34BCB3A20AE2CULL;
        aWandererB = 0x84C62AD4C1B8DB75ULL;
        aWandererC = 0xDFBF3C353245BBB6ULL;
        aWandererD = 0xCC7625930CF1032EULL;
        aWandererE = 0x8653184CA39BEA0BULL;
        aWandererF = 0x94B043798EF97144ULL;
        aWandererG = 0xD5803FC9E4536C60ULL;
        aWandererH = 0xFBBDA8CE34C1F719ULL;
        aWandererI = 0xBF616CC4533C7395ULL;
        aWandererJ = 0x812A398E802CAE06ULL;
        aWandererK = 0xAD44875CB862995FULL;
    TwistExpander_Alkaid_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alkaid::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCBEA533F346705EFULL;
    std::uint64_t aIngress = 0xEF352B9EFBBFA3AEULL;
    std::uint64_t aCarry = 0xB9D45982B693BB51ULL;

    std::uint64_t aWandererA = 0xA652073BE141190AULL;
    std::uint64_t aWandererB = 0xDE254CE1255C8CE0ULL;
    std::uint64_t aWandererC = 0x8D03ED3B497A1A62ULL;
    std::uint64_t aWandererD = 0xEAC0EBEA861626B2ULL;
    std::uint64_t aWandererE = 0xF1EA18787CBB77ADULL;
    std::uint64_t aWandererF = 0xE713744BBBFFC621ULL;
    std::uint64_t aWandererG = 0x8F3064509C23B778ULL;
    std::uint64_t aWandererH = 0xE73D05A943B6A26EULL;
    std::uint64_t aWandererI = 0xD91C4FF0D062CCC7ULL;
    std::uint64_t aWandererJ = 0xB20104804684963EULL;
    std::uint64_t aWandererK = 0xABB4D76A3B00DB1EULL;

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
    TwistExpander_Alkaid_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KEY(pWorkSpace,
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

void TwistExpander_Alkaid::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC3B6B3D4F8BC98A1ULL; std::uint64_t aIngress = 0xC6DD8CAD2ECABED0ULL; std::uint64_t aCarry = 0xE7A2B2BE971E7EE9ULL;

    std::uint64_t aWandererA = 0xFF9A1D5BD3A587E9ULL; std::uint64_t aWandererB = 0xC2B80413ABD543B7ULL; std::uint64_t aWandererC = 0xEE64D9197473085CULL; std::uint64_t aWandererD = 0xC026726FEF9FE856ULL;
    std::uint64_t aWandererE = 0xC931256BAE76B5A9ULL; std::uint64_t aWandererF = 0x99C0C94B73598EB6ULL; std::uint64_t aWandererG = 0xDCD17539A4D95769ULL; std::uint64_t aWandererH = 0xCBF20167D726126FULL;
    std::uint64_t aWandererI = 0xE37C0CD8FF416FCDULL; std::uint64_t aWandererJ = 0xA0DDFC750AC3B37AULL; std::uint64_t aWandererK = 0xC059A75C0B13E99AULL;

    // [twist]
        aPrevious = 0xAA5A7F116684082EULL;
        aCarry = 0x84E8EECF9D9DEE56ULL;
        aWandererA = 0xEC2833D0CE384A24ULL;
        aWandererB = 0xF9832693AF0F7637ULL;
        aWandererC = 0xEDEA94037EADF508ULL;
        aWandererD = 0xA98BE4A1C1250D73ULL;
        aWandererE = 0xD75CDC10BA7F9EE0ULL;
        aWandererF = 0xCFCAC450AFD68705ULL;
        aWandererG = 0xAFAABD8CF71A7F05ULL;
        aWandererH = 0xCA34C9C823D2062FULL;
        aWandererI = 0x963BEC739980C227ULL;
        aWandererJ = 0xB693D2155BC4B98DULL;
        aWandererK = 0xF601AD237BC26F44ULL;
    TwistExpander_Alkaid_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Alkaid::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Alkaid::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Alkaid::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 5 of 33
    // Exploration cases: 0
    // Structural maximin 555 / 674; family total 2269
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 5 of 33
    // Exploration cases: 0
    // Structural maximin 557 / 674; family total 2257
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 430U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 5 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1106 / 1248; total 4436
void TwistExpander_Alkaid::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1488U) & W_KEY1);
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
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 5 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1112 / 1248; total 4464
void TwistExpander_Alkaid::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
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
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
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
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alkaid::kKeyRotateSalts = {
    {
        {
            0xEC5BE128ABB8CCCEULL, 0x30CBC1E6834A52CEULL, 0xFC61BAF27C2F9ABDULL, 0xF2A598A035B733BBULL, 
            0xD420538917E6443CULL, 0x5E9C03C337D96246ULL, 0xCDBD64A197D91AF8ULL, 0xDD19EFD35181CE91ULL, 
            0x80EFAA2DAE1A631CULL, 0xF6958D74C9AB0938ULL, 0x4808882DC662C994ULL, 0x7061E54A972A4ABAULL, 
            0x3DE734B6A4EEB775ULL, 0x9659F92B33340659ULL, 0x6354FFDA9285993CULL, 0x31DCF7EBFF844842ULL, 
            0x57ADD8AB1C590BEEULL, 0x37AE57465F797844ULL, 0x30F499F6E43203D8ULL, 0x5C5B4EACA369BD86ULL, 
            0xA1B09A82E4725077ULL, 0xF3E1086899D521E2ULL, 0xFB077064FCD15BD1ULL, 0xA2FC5C6353ED33F7ULL, 
            0xF3EEE709BC4ADD9CULL, 0xFD13DB7964E6D46FULL, 0x2AD564D7F959CEB1ULL, 0x257D089921D458DAULL, 
            0x3D0282F146493EAEULL, 0x2ED9A0837E303689ULL, 0x6FC03F0C5EA43343ULL, 0x896E593E254D70DDULL
        },
        {
            0xE3394417801BA815ULL, 0x492E833A05DBB602ULL, 0xEAAA29EB75331FC5ULL, 0x2E81B6FC31902BD2ULL, 
            0x43E6713B924E5E07ULL, 0xE52E0B1CF556A3C5ULL, 0xF57A7217B45B9AD6ULL, 0xBDF9C3EF4D6E3B9AULL, 
            0xA9081A087123FC5CULL, 0xD8E7CD82344B336BULL, 0xB8C5CB8E1C6145DDULL, 0x56DD5A579F57D030ULL, 
            0x3774F60076B90C11ULL, 0xB62002B8C5B14138ULL, 0x279E1744950C6C1BULL, 0xA62F79D01C9CC3EEULL, 
            0x5DD9CB4CE16AEBFBULL, 0x2A49CFBD0129749DULL, 0x3392034CD9D6148FULL, 0x568570160825066DULL, 
            0x0DE9F8A9AEB5F288ULL, 0xADA6450BDED8DF7FULL, 0xF11B5AB46F23D44FULL, 0xB0A22F756FFADB8CULL, 
            0x99FDAFD7751CC3E7ULL, 0x6DE6A657C198AD6AULL, 0xBEFB0889A9F68CFFULL, 0xBD2A2CC07B23B41FULL, 
            0x14F34C7797C505E1ULL, 0x64A6E7D1DA64F52DULL, 0x60B5485F4FD7B3F1ULL, 0x1E98BA294F8EE2BEULL
        },
        {
            0x8D596CDEAF349CCAULL, 0x2C0E2ADBCCECB211ULL, 0x1D8141614AD1A63AULL, 0xA5063EFF60A48EA1ULL, 
            0x9D7F603A78FA4677ULL, 0x5BED6B63DF0759A1ULL, 0xF1F91E918EA86095ULL, 0x4D5E073FBC9DE577ULL, 
            0x69CBB272641EA85AULL, 0xB805B0E99D5BA53CULL, 0xE96D0D0712D9963FULL, 0xF6BABABB443D9794ULL, 
            0x66E52986FCE0A6EEULL, 0x73990685A7FB58DFULL, 0xBD4AB19303148444ULL, 0x60C84E81EBDCF849ULL, 
            0x0A101336F104BD84ULL, 0x9B18822C1115135BULL, 0xFB456655E30E41B3ULL, 0xF9B9938BCC812BF9ULL, 
            0x745933A870B7E7B8ULL, 0xD61CE9BF1E5B90A8ULL, 0x92AF13D4F238A654ULL, 0xCA1A03224EF27454ULL, 
            0x6A83A492BEDD1B21ULL, 0x0D50C27294BBAABEULL, 0x934AD2FDE9130485ULL, 0xB403260C3FCE3B54ULL, 
            0xB336F3A204A305DCULL, 0x8D8775C66198581AULL, 0x2567F841967D36AFULL, 0x93FD937E2CB6D2EAULL
        },
        {
            0x72F58CD17798BBA2ULL, 0x0B47BE5A46D06904ULL, 0x228F9E23ACCC2769ULL, 0x55DEEDB437521259ULL, 
            0x28AEB26BBEC3D959ULL, 0x1F77456E51D2F1B2ULL, 0x566A5C0778E6C8F4ULL, 0xAF6D5F0D8592F3E9ULL, 
            0xF65D357CF2BFEDCCULL, 0xEA2CE86D3FDBDD8AULL, 0xEFC01215AB182DA1ULL, 0x73208F64579B5599ULL, 
            0xAD38783F27AB5B89ULL, 0x32D184B832BAB3E5ULL, 0xFAF0BB98E9FC8652ULL, 0x63C717C0863BAB63ULL, 
            0xAFCB734656067BEDULL, 0xDB97EB1943CF49D2ULL, 0x9725CED503484378ULL, 0x650738D4A5271CF7ULL, 
            0xD68C037DCD788233ULL, 0xB6F9A18469F0FD71ULL, 0xDE52E10F7669EC3AULL, 0xD0B94391FADEB1B7ULL, 
            0xAA7865BA0FF6B18AULL, 0xB3625143DAED21D3ULL, 0x0D1D53D0AC8C62CFULL, 0xED6D498CB48A7F74ULL, 
            0x57C54D4D9B320CF7ULL, 0x57EE1FA8AADB57B4ULL, 0x81DA55775C80B8FAULL, 0xDB3792AD880439FFULL
        },
        {
            0x94F48A054C7E1B59ULL, 0x03EE48628D9B129AULL, 0xB799BD099C6D21FDULL, 0x8665EE091ACD82DBULL, 
            0x0910A2EBE838DCD0ULL, 0xE8D8B0D3E102270AULL, 0xDF19739850A32A9CULL, 0x16861AF566FFB7BEULL, 
            0x591BB211D034DBA7ULL, 0xAA5E1F99675DA5E4ULL, 0x6611B1F4A8EB4134ULL, 0xBF2ECB28C1987C21ULL, 
            0x2A2CDD8F44418391ULL, 0x3378F59029F2C2B8ULL, 0x5041F5A69407B90FULL, 0x5DDFF9B6ECBBA30DULL, 
            0x776630FC971AD720ULL, 0x1C029BBED89AD30DULL, 0x0C6191E1B9E206EDULL, 0x0A5DCE9F5EAE0867ULL, 
            0x7C786017CE58824BULL, 0xF4B7FDD52DAEC875ULL, 0x8F1375B3BC159DC4ULL, 0x7E882D6E1F7E4A49ULL, 
            0x4615BD06D7D4C40FULL, 0x5BCFA7E594A1F70FULL, 0xC9A6BCD0864A2CDEULL, 0x60DCC5612970BEACULL, 
            0xDD0F71C50BBB9EFEULL, 0xA500A2CA38B54813ULL, 0xF1ACCA7269C6F0C6ULL, 0x491C22E8D844D420ULL
        },
        {
            0xFB8E75791D95530BULL, 0x874F7FEB67DDEF17ULL, 0xEAB5396E45CAD0F2ULL, 0x6B95769EB111968FULL, 
            0x8F0B2B6C5CE30C4EULL, 0xC9520F64C606CFF2ULL, 0x731E433F346F1824ULL, 0x69FAB206F267F6F9ULL, 
            0x3CFD185BF41177B1ULL, 0x4BB386A89B6FAC75ULL, 0x991AC2F045AF48D1ULL, 0x40467AA4BBEE76B4ULL, 
            0x51681C2889F1EC2CULL, 0xF223974E5A138DF4ULL, 0x0B5D042AF35B36C6ULL, 0xF0FD0EFDF02F7BD7ULL, 
            0x61489C3FA6B26320ULL, 0xA835C4FA22B250CAULL, 0x7431F5CD049B310BULL, 0x875F0A5B4515AC2AULL, 
            0x9209A1C428C5379BULL, 0x7D931C930760E8ADULL, 0x5F24BB27EC069C52ULL, 0x6678F3ADFBD59C10ULL, 
            0x00FFC022BD2C5A5FULL, 0x7FB1353A5B89F4DCULL, 0x17A46EF63A80230AULL, 0xEFF057361DD05525ULL, 
            0xF4C96F813B719726ULL, 0xB465A49E1793FE89ULL, 0xA8C0887A8E6B4AA1ULL, 0x8D786B8D8DA77787ULL
        }
    },
    {
        {
            0x428F2AB86AAE1A12ULL, 0xFCE0BE8C6B5CCC4AULL, 0xD2869650E5F34F27ULL, 0x544E7D6C0DE29B71ULL, 
            0xAD5E20F31F73E5C9ULL, 0x55DE13B00C2014ADULL, 0xAAFDCE7FA96C4031ULL, 0xA45CC9D1EC92B859ULL, 
            0x829440D9F686CBB1ULL, 0x86688D0A50B57635ULL, 0x716D644213D693FCULL, 0x3C90D62AB21C294DULL, 
            0x49A1C9E5AF7D4154ULL, 0x506BDDCA6CA8B215ULL, 0xEC28CC55EACE345CULL, 0x14AA7C7258A112CFULL, 
            0x70DBDD0CCAE8078DULL, 0xD9D92C31AABD5144ULL, 0x645FA27635316A45ULL, 0x9C12DD203D7B0B68ULL, 
            0x3C5B475DE3F68ED4ULL, 0xAC2A066142B7B194ULL, 0x21A518352549096AULL, 0x3C278B70DDB2A424ULL, 
            0x631EF3356FBC983AULL, 0x025C22118ABC683BULL, 0x1C1517917E2966FFULL, 0x870FB302DA4CC390ULL, 
            0x8E8A8467D230F77EULL, 0x5F46BC56879E0103ULL, 0x37C3F5A4A47B0BE7ULL, 0x259C732D1B02127BULL
        },
        {
            0x3A698E1F0C4D6E1CULL, 0xBDDBCE75269A7F85ULL, 0x2D6E371B1B986FE2ULL, 0xDD9E8C012A43A736ULL, 
            0xDD19982EF648C811ULL, 0x675BEFFEC70204A8ULL, 0xA5B732076A14DB98ULL, 0x3BC4D7BDF24FACCCULL, 
            0x59EA4FCFBCCD0E49ULL, 0xE1ABE4DC38586C4CULL, 0x93B44A6139138018ULL, 0xDCAC461F512141C3ULL, 
            0x5751A1FE58BE06D1ULL, 0x9E20FA8255D76AFEULL, 0x6285CF2CD5CC9831ULL, 0x0ECF63C67F251362ULL, 
            0xDCAE92100DA0765EULL, 0xFFE649581F37E86AULL, 0x2E56EAAB60D76CE1ULL, 0x29C6E1A16E9D9D1EULL, 
            0x9D8C6BE35806459AULL, 0xE0F6E3E9CA0021FDULL, 0x711DD2983B236244ULL, 0x5F31EA3D6B371AEBULL, 
            0x3277EC424131CC3DULL, 0xDC3DABAFE558CC75ULL, 0xB374BB026C87ACACULL, 0xD4485E1D37E4F457ULL, 
            0x792D31543489A339ULL, 0x185D122FC103D77CULL, 0x32CE219B326FD61AULL, 0x2A6F9102CCBE8479ULL
        },
        {
            0xD61CB4B7945E3EBDULL, 0xC38AA0D27D37CEC7ULL, 0x153B5627104801D5ULL, 0xBDBCACFEF09DA27CULL, 
            0x3EE6CECD00CCBBC8ULL, 0x307FDE272CA8A95FULL, 0x182C3A2F238B8EE7ULL, 0xB69EFF9FDB0CADB6ULL, 
            0x31A42CFF3B933DD8ULL, 0x239A32FD9CFD5657ULL, 0xB1E45E342A277CBEULL, 0x72FF8333D9E68365ULL, 
            0x4D04FB7B1C50D1E4ULL, 0xF058E8E04828CB13ULL, 0xFC35654BCF2EFC0CULL, 0x71CF6C0C6AE69C40ULL, 
            0x395A71F905715EFEULL, 0x21584A99131DFC76ULL, 0x7AA6B3175DE031E2ULL, 0x90CA9B24583468C4ULL, 
            0x67F854FAA2B48E97ULL, 0x09AD38368F406FCEULL, 0xC3BB2CA46E1A2F65ULL, 0x1CF86FF405D13A2CULL, 
            0xD56B79C5AF844FD9ULL, 0xB9B21186947CEC87ULL, 0xD0CE026DEEB52D80ULL, 0x90D8537F2B9E89A5ULL, 
            0xFBACB5E1EC2D2749ULL, 0x6CEDAB780E13B2C5ULL, 0x1BEB8977744E66BEULL, 0xC7F6AABBA603F782ULL
        },
        {
            0xF860A9554146CC70ULL, 0xA90C328A9B428972ULL, 0xF2F3F8D2926B8EC9ULL, 0x05ABFBBE0031F623ULL, 
            0xA95FEB91151E23A4ULL, 0x571BFD9A4E1897FBULL, 0xBB79768F9414BE06ULL, 0x63CE8A2E97F2D517ULL, 
            0x3552B71922FE3821ULL, 0xB814F4329BB4E79BULL, 0xA06BC45A47019609ULL, 0x49ABDF955AB75193ULL, 
            0x5A1B449A11FC002EULL, 0xDA10849414C16128ULL, 0x89A61C58C03104B3ULL, 0x476D490C59EC8958ULL, 
            0x7F379F62FB1B562DULL, 0x520746CD3E082E37ULL, 0xE1AFE630E360CD4FULL, 0x5CBEE7C231AD80CBULL, 
            0x2A7256571AD1E9AEULL, 0x680DCD60FAFED4AAULL, 0x33AFBB7D024F96E7ULL, 0x9276A57A2223C829ULL, 
            0xB2FD4C42C7DA118CULL, 0x77B325F0951EAF11ULL, 0x25D359975113679AULL, 0xDF91BA1C34A36C74ULL, 
            0x16E44FA14C0292D9ULL, 0x3FF5CB1EDB94FAA7ULL, 0x9533C7FF555F4CADULL, 0x7C256C4206099EE7ULL
        },
        {
            0xCCC8F9D34E09ECDFULL, 0xB06D2CAB7F61FDE7ULL, 0x2B230997C4D78842ULL, 0xC8AEE20EFCDA08DAULL, 
            0xBDCD30278DF89875ULL, 0xF9BBCC0588A9A5ABULL, 0xAFF287AF1709F47EULL, 0xEC84F8AB8F7079E5ULL, 
            0x384188D31B2809A9ULL, 0xF89F6933156507CAULL, 0xF0A33169B28BDEF0ULL, 0x92A8BAEC5DC92917ULL, 
            0x78A4253F14744A3DULL, 0x657877033D7C3C7DULL, 0xAF9F17D8676B9AF6ULL, 0xA6618A0EEE362368ULL, 
            0x5D7B494BC98D0875ULL, 0x5C6FEC3645B545EEULL, 0x9906FDAB0316620BULL, 0xE75CB33F015E02FEULL, 
            0xFDDDB0B92C62BDA2ULL, 0xB239C4FA34B80BCDULL, 0x72309AA8F1BA179BULL, 0x682FDF6071CC17CBULL, 
            0x50F9759E20237C95ULL, 0xFE439F43D39D78FAULL, 0x4B7C261619ECA796ULL, 0x40A32199B9AA3F1CULL, 
            0x212DB5865991E69CULL, 0x028E851AB4FB77E7ULL, 0x354D440ECD4DC545ULL, 0x6C101A2E45C2E88AULL
        },
        {
            0x12AC89B10DFE16AFULL, 0xB686CF1E07E61889ULL, 0x26355136771A6208ULL, 0x67360BD6D9778554ULL, 
            0x343BB53E61689122ULL, 0xFEFA32DA42B1B92EULL, 0x0F7B9CD892B61D91ULL, 0xDAF84AEAF5FD92B4ULL, 
            0x40A8E259CE678317ULL, 0x5FF0C51BE4562F07ULL, 0x4038CD40257F235EULL, 0x033E324E09013A8DULL, 
            0x6F8A8814400F7268ULL, 0x634402E150E07577ULL, 0xAE44E197CC885730ULL, 0x1D76AF32CBBC9695ULL, 
            0x873B8E9A18D886F1ULL, 0x7429C5E0162007EDULL, 0xA6C5E153B8846E9FULL, 0xD9BFA7EFEA47735AULL, 
            0x1EFD280B7C63405FULL, 0x5A77CB8998CB29DEULL, 0x66CF6D5C31BCC254ULL, 0x7E2EEFFB75875BA4ULL, 
            0xC64E28544E9092B0ULL, 0x1E8ABF67A72B0BDBULL, 0x92955ED164A83A20ULL, 0x2539441E5E12FB71ULL, 
            0x5E67021A583B57EDULL, 0xDB8A704F44FD6132ULL, 0xFADF9811E20AA21AULL, 0x7FE279C70474A627ULL
        }
    },
    {
        {
            0x47DA8E2524422D9AULL, 0xCA7F7240CA535415ULL, 0xD83424784640B2BEULL, 0x4F9F7084D41AF845ULL, 
            0xC41E75C5D6807D81ULL, 0x92CCDE574A7957D0ULL, 0x7F41384EF5FBCF34ULL, 0x7D08D1BB7F6BA4E3ULL, 
            0x93A56F8F8593C68CULL, 0x526EF53496413C40ULL, 0x774EF9E85A6931CDULL, 0xF8CA90633F30A78FULL, 
            0x10B6A4328ED2FE3BULL, 0xE92A8641B4AAE7D5ULL, 0x2BFC297836A22831ULL, 0x224ADD99CC0978D2ULL, 
            0xDC4D5226A1B9B519ULL, 0xB52112A20F7C3D79ULL, 0x944D9256271852F3ULL, 0xDCC79FEA10102FF0ULL, 
            0xDFCBC7A517F9AD0BULL, 0x83EC4D0F93BC4BC7ULL, 0x814388235F609EB1ULL, 0x682394DE4D132E3BULL, 
            0x466B9726D404F558ULL, 0x04C0E57E2B8D49C0ULL, 0x7ABA21E7C5FFF237ULL, 0xEFE2EB1ACFD34AB3ULL, 
            0xD45E0CD540EFD136ULL, 0xA2669747826A2C93ULL, 0xBDA59EF59A63BE20ULL, 0x40AD22676ED1A7F2ULL
        },
        {
            0x9435526680440EB8ULL, 0xF7B7EFEF6E4C203AULL, 0x35B29CF1133F8526ULL, 0xF61CDF9A67807ADCULL, 
            0xA61B678415AF9033ULL, 0x6B705160BCC10279ULL, 0x424424F0BAAB4E6AULL, 0x6CD46A549C5122A1ULL, 
            0x0A39023D814EC4ECULL, 0x1BF15C59AF3DFF57ULL, 0x40194368A8F7AD58ULL, 0xF933C27819FF8CB1ULL, 
            0x26F6B1059FBB69E2ULL, 0xD4A666F8D3A84235ULL, 0xCF5DEB5ECB245A70ULL, 0x907C097245223EF5ULL, 
            0xEBD9BBC4F899E4D7ULL, 0xC39E493475EEC691ULL, 0x2465E5B52C504535ULL, 0xD77E6885714B374EULL, 
            0x50543C6E8744F2F7ULL, 0xCAF7F0A419CF5915ULL, 0x4802D9DD14D700FCULL, 0x12C7530A503614F3ULL, 
            0x402CA4963D9C4B7CULL, 0x54CC551319AC2166ULL, 0x6875CEB09EE34AA2ULL, 0x0CD89DE2BC7092BCULL, 
            0xFAA44E3747BA3CD9ULL, 0x43D3F7FFB83427CDULL, 0xECB5F492D5911F0EULL, 0xC2E3F0762241FF2FULL
        },
        {
            0x6ABD549B4345EAA6ULL, 0x97C7C199A672FFEAULL, 0x3E57BD1426B6D2ADULL, 0x42984963D8B27700ULL, 
            0x0345976989D2F4CDULL, 0x46D15E6AE77D084DULL, 0x91E6FC602F106847ULL, 0xE82B3CCF402021E3ULL, 
            0xC6FFEBB71C9D7B1EULL, 0x7D7AD51F75A0263FULL, 0xF5FCAAD29F2ABCABULL, 0xC5374035097032DAULL, 
            0x8B4BCD08662B619BULL, 0x44ECFE5F9E8221A1ULL, 0x73B3CA6636BF8FCDULL, 0xD3E9DE3C262F8408ULL, 
            0x5CCAB7657C041901ULL, 0x5D15B1B2449DEE3CULL, 0xEEBC5863C3C5D1D6ULL, 0x6C4D2BCB9125E22DULL, 
            0x87993B67EEA55254ULL, 0x8BCA082C3CFC1863ULL, 0x78ACFA4DBDAE51D6ULL, 0x3DB19F794EA7A406ULL, 
            0x03EA90EAD3140AD6ULL, 0x9D13D0B13AB3B2ECULL, 0xC7E87D7112655BB3ULL, 0xD05A527C1D400906ULL, 
            0x4275660932FE604FULL, 0xD601A4073AE084BFULL, 0xF586BADFDFD17E52ULL, 0x141B71E73FB15728ULL
        },
        {
            0x2730C9146632A44EULL, 0x8678621E299A26D5ULL, 0x2D5D161C76291FC3ULL, 0xDF825FEB7724781AULL, 
            0xC71CB4CAAAAF6852ULL, 0x131767855963A72EULL, 0xB57006CD1FF69B95ULL, 0x1ADBC80D48977486ULL, 
            0xEAEEAE0DEF89820DULL, 0xAEAF4B3E016A2070ULL, 0xB13A7BBAAAE96021ULL, 0x72B73DB51F57E259ULL, 
            0xC299ACB9C80E5B3BULL, 0x444A564785479570ULL, 0x19E43B93A08D0826ULL, 0xE5BDCFA486AC0B6AULL, 
            0x44E54CEEC2F70F3FULL, 0x2D9A8473B6A6CD32ULL, 0x0A540A049385BB15ULL, 0x804084F01CE0F9C3ULL, 
            0xDB4807C82825D69DULL, 0xDED45EE537996439ULL, 0xFEB9D1DCD5D0330AULL, 0x633398C1EEFBF164ULL, 
            0xB98AACBE90EA1E3BULL, 0x06B2518D45CD97F0ULL, 0xABE21927E76D903CULL, 0x10EE14D849358CA1ULL, 
            0x82C30325590EE2FCULL, 0x36E1820D6E456990ULL, 0x9B3FE38EBFAFA36BULL, 0x2C1C088EEA67D2D5ULL
        },
        {
            0x2900C4F4B1E804AFULL, 0x2870CA0C8F1F4357ULL, 0xEAF6F9D92F4DC879ULL, 0xD1BDAD619ACF98B8ULL, 
            0x80BE6CC0F3942D67ULL, 0x0F2AACCC2777C1D2ULL, 0x0AEA7C5BE8DE6B4AULL, 0xBFA6721FAA512DA1ULL, 
            0x73A77AAE80BDA30CULL, 0xB6FF8E4CDEBCFDE8ULL, 0x7BDE4283DAE9CEFDULL, 0x08155E161349954AULL, 
            0x1FA6A43DC35149A0ULL, 0x7D25F62AE44C5B1DULL, 0xA77B1447756AE9ADULL, 0x2B5EE2AE5AB3540AULL, 
            0xCF3F55C62A357B3AULL, 0x31075D04A5FB741AULL, 0xB21E2F43CEE5D03DULL, 0xD66EF8DF227BEEB4ULL, 
            0x08090E3D4FCECC87ULL, 0x435B4B1709E35374ULL, 0xE305D1A3C98E16DBULL, 0xD96CE6C855DCF74EULL, 
            0x8B0F33DE6D6931E1ULL, 0x9405F654FB815594ULL, 0xE22D730751478A8CULL, 0x8D065213C932FCB6ULL, 
            0xAFDE0C014FB28047ULL, 0x10E194A0A772D4C1ULL, 0x4F6FDD7FBC6044B9ULL, 0x17113126A826AD59ULL
        },
        {
            0xA68972499FA5ED3BULL, 0xC3210450BD7E767AULL, 0x6BD7AE78BC89E47BULL, 0xD1A0C2160BC87FA0ULL, 
            0x6A792F96036682D5ULL, 0x2180F3549C15EF00ULL, 0x79733CC37A378533ULL, 0x372048E31D288C5DULL, 
            0xE9A22402A7C78367ULL, 0x1A8C50AC48E5E072ULL, 0x140788032F7F672FULL, 0x599C7DF5849EE554ULL, 
            0x1BC54067A0E13765ULL, 0xAAFE005D72EFA52DULL, 0xA5A915142F14E49DULL, 0x2E4E2C9335F70454ULL, 
            0xE79F959415A4BB12ULL, 0xFC05DCA670B557D7ULL, 0x0EFB43B98646BD88ULL, 0xF02FC5F465E5D6DEULL, 
            0x9B86DAC795C5BB3DULL, 0x0A1DDA52E827C265ULL, 0x3B81CC859A2439F5ULL, 0x0AB908308FF1489AULL, 
            0x19C518976275F33BULL, 0x0D4D9099C73EC38BULL, 0x19A0A259B386EF8EULL, 0xFB993CB6C7D75451ULL, 
            0x813C776AE1C35E6BULL, 0xA925055FB1BF171DULL, 0xDA090C3C7EE90C04ULL, 0x6023033403D4456FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeyRotateConstants = {
    0xC0A908C415C618F6ULL,
    0x1BADD1621577B59AULL,
    0x08CAA80758BCEAA1ULL,
    0xC0A908C415C618F6ULL,
    0x1BADD1621577B59AULL,
    0x08CAA80758BCEAA1ULL,
    0x98A09D353F26209FULL,
    0x1B6C765EF710BB13ULL,
    0x2C,
    0x36,
    0xDC,
    0x46,
    0x51,
    0x45,
    0xD7,
    0x01
};

const TwistDomainSaltSet TwistExpander_Alkaid::kKeySpawnSalts = {
    {
        {
            0x016586A9E4ECC5EBULL, 0x8C0BF9F772978813ULL, 0xEEA57FE5D1B7262CULL, 0x0202490B2DCAB15BULL, 
            0x96EC3ECC5D580CA7ULL, 0xF3E3D0674F033EDDULL, 0x1367AEA1979B6132ULL, 0xFED9695E362C34BEULL, 
            0x76FE60712936A92EULL, 0xF915E7DCCD1C741DULL, 0x06013B6B5E1945AAULL, 0xCBA1863BF3BB61FAULL, 
            0xB35C7E016B25E998ULL, 0xF5F277B5B9EA1252ULL, 0x19DBB624BA2AEE16ULL, 0x7252ADCFA524A7E8ULL, 
            0xF2D15B8513DB6E56ULL, 0xBFF28A478D7CCB64ULL, 0xCD55889363E85426ULL, 0xAC7FDAA5D6414A36ULL, 
            0x9FA39E183BD69F73ULL, 0xA74A71BEE9796E0EULL, 0x728242F2CB1B4A5BULL, 0xE68C556CED6B7AA4ULL, 
            0x09185C3ED9381563ULL, 0x655C8682414BE3F3ULL, 0x4006D90714522E20ULL, 0xA4B34F84674596B8ULL, 
            0x8143EB7DD4D989C2ULL, 0xCAEFBB7F03599486ULL, 0x9DCA368BF33F680DULL, 0x26704F2005E829C9ULL
        },
        {
            0xB8E106BED0B45BDDULL, 0x141FF1816680F51EULL, 0x1A38BF691CA2DB7DULL, 0xA8AC00A16F4B95C0ULL, 
            0x7A67BDE25CCF5FAEULL, 0xE380439CAB9A499FULL, 0xCCC148D29CFC9209ULL, 0xB4FA55B99D85E33EULL, 
            0xEF99066C1AEBEFDAULL, 0x9FC98C2BA0836298ULL, 0xA7A46FC4D6BA58A8ULL, 0xB807656E7DBE7D5DULL, 
            0x31E3F4F505EC36B7ULL, 0xEC6E377F8BE82253ULL, 0x8F1AEB13BB4443F2ULL, 0xD93B023247984DFDULL, 
            0x0C3E7CCEA2711486ULL, 0x9080933DD0B091D7ULL, 0x7744EF4DC9C49458ULL, 0xA9D8F8202A359724ULL, 
            0xB29991605FCD782BULL, 0x7621F4981F73A3EFULL, 0x0EBEE819E32165B4ULL, 0x4F0A0F81EFA0900AULL, 
            0x1D904015EFE8E6DAULL, 0x5B38A07857697888ULL, 0x6608DDE277B68B27ULL, 0x61931A436E00D8D8ULL, 
            0x356EBA4A10F1E772ULL, 0x631ADC810C4AE7ADULL, 0xCE4278AFA4C9BDD1ULL, 0x45ACC96D31633D11ULL
        },
        {
            0x5BF05FD474105A08ULL, 0x5F55AC627E4F0233ULL, 0x48675AB661A52F57ULL, 0x4361336895253554ULL, 
            0x291C3ECC3BA881F1ULL, 0x1947083EC0C1141CULL, 0xC2C3686E23295205ULL, 0x286E2A3AD4B3954FULL, 
            0x6E6BC661507D3C8CULL, 0x7BF2F8BB197668ADULL, 0x031D9D6D72F03BDCULL, 0x6095BB3C94EC73F2ULL, 
            0x50A226E0584A6D2BULL, 0xA25AAB1861C32735ULL, 0xE5D7BD9379AABD4DULL, 0x54DF5E087880B76AULL, 
            0xC01998EFD412E0A8ULL, 0x36C2647B38E76C5FULL, 0x3E3DEC6B1D5C4D31ULL, 0xED2222B99521028FULL, 
            0x0D9627A718C55DB2ULL, 0x4E785A926D850200ULL, 0xE66685BC589FE633ULL, 0x7413663437DFA468ULL, 
            0xAFDF309C75357E13ULL, 0x4DE0120838327EF6ULL, 0x696719FE1424F9A1ULL, 0x56EA4064C1F95421ULL, 
            0x1B0C5C6B29C1BCCBULL, 0x257865A3CD2F8648ULL, 0x3A8A9063D2E45DBCULL, 0xCBF9E50664DA78E4ULL
        },
        {
            0xCA66E667219F1E10ULL, 0x121BA3690C6518D1ULL, 0xDE64719D3A095F6FULL, 0x0C7F76702B3B01DEULL, 
            0xA4096339615259DAULL, 0x37BDFBB9479AD6CCULL, 0xC318E36C57FE7893ULL, 0x8008E9A27B707E98ULL, 
            0x87A0EF2A6E29B965ULL, 0x92FAE7D8BFF9BD1CULL, 0x384A10447185FDD1ULL, 0xD32BA922B5A08617ULL, 
            0x12963D27FABD9759ULL, 0x1DA67F158A133424ULL, 0x01C15C270D305F59ULL, 0x91EBDC14F54592DFULL, 
            0xCC05B37E494EDB80ULL, 0x311FEBE05D1ECDAFULL, 0x98761E48D43A8304ULL, 0xA94E68CBCA5F06DFULL, 
            0xB8306F347976CA4AULL, 0x95BB497A58D16B26ULL, 0xA27155DB9E1B2AA5ULL, 0xBC0772534A03861CULL, 
            0x859278AB416B4232ULL, 0x97E2E9FC3B6D5FDBULL, 0x24B3F5CC241F5179ULL, 0x42231E09D0463997ULL, 
            0x543811676A6A46B1ULL, 0x8AC78D30308BBEADULL, 0x3F8B1B91139B36FBULL, 0x5D0184125A6AEEA8ULL
        },
        {
            0xB8AE287BB6A0C893ULL, 0xEB198FAD984CFE49ULL, 0xA181C61BC1678CCBULL, 0x1B1B926BA002D786ULL, 
            0x8FED2DC9DA1E4C64ULL, 0x5FA49280426B7FBFULL, 0xDA8D192AA627DA6EULL, 0x5F2B57400CF37A53ULL, 
            0xEF993E799B88C4E6ULL, 0x6FAE5BBE96FF438EULL, 0x859A15D35642104DULL, 0x8B0CA579806617EDULL, 
            0x378BD480B070906BULL, 0xFC9C6DD3A911FA7BULL, 0x2A7911403FA309FCULL, 0xAA06BFB6A1284401ULL, 
            0x73EB22506CA852C2ULL, 0xD18BABBCC7CF8597ULL, 0x4E806F2453EF6CDBULL, 0xD056303DC817CA0AULL, 
            0x98B8DB5CD40D3C33ULL, 0x32B7EC6FD96661FFULL, 0xE4F9731A33179959ULL, 0x98CD99406F23A9FBULL, 
            0x204C71D0B6060CA3ULL, 0xB822B4AF1938B4A0ULL, 0x73A172F3473C5EFEULL, 0x79AEF4BFC1CF7BA4ULL, 
            0x0276FC26C7EB32DDULL, 0xAC833124AABB7059ULL, 0xF360B5F335123833ULL, 0x138BCBFA3A2918DBULL
        },
        {
            0xC7CC58C62F7070F3ULL, 0xFC9B071A5F7E1E75ULL, 0xAF42040BBDB18E4AULL, 0x02AA63F54E42AD51ULL, 
            0xAA7F0E8F4207CA62ULL, 0x5B748F8EA4AE1DC5ULL, 0x2399A90847DE0D27ULL, 0x93DF103B6AC2A0C8ULL, 
            0x8340208C3C21B22BULL, 0xF271F09FC2EDB91BULL, 0x81140E19596083F8ULL, 0x323195A17D4157BBULL, 
            0x6802380054DBB22DULL, 0x924D72F232F7E881ULL, 0xB353D377ADDDEDCDULL, 0x428EE1EF32772662ULL, 
            0x0E1EB88CAD38D5ADULL, 0xA9D9DA4FD60C51AAULL, 0x1D3805590E538207ULL, 0x09F7D8B8681A440CULL, 
            0x5A047B71647B5AC9ULL, 0x95F9A560814F7D9CULL, 0xA22ED83331806276ULL, 0xF74D322C2B2D6AC6ULL, 
            0x7122EB049CC62EADULL, 0xD6D7A423F17888EAULL, 0x7EF9B9B651E8B87DULL, 0xEF9085C0E1DD0307ULL, 
            0x1FAAA3D19F521327ULL, 0xC87DAE3CF166A7C5ULL, 0xF5C4650D527D0F7DULL, 0x3DD17680D2F8527AULL
        }
    },
    {
        {
            0x0239BA2D88DA13E6ULL, 0x885E80AEC86A7C25ULL, 0xC150667F75C21105ULL, 0x886E61BA9D7E29B3ULL, 
            0x8E9DE638962F5C2BULL, 0x095DD2A44589368AULL, 0x79E9905B009872A1ULL, 0x294A147BA7237134ULL, 
            0xE99CCD6E7816C557ULL, 0x20950E7D8F2CBB65ULL, 0x521851865C17743DULL, 0x7D3FB2EC849CAF5DULL, 
            0xC5751C144DF788A9ULL, 0x36ABE8CBCCA1F343ULL, 0xA748CB9775DDB6DEULL, 0xF86A708074B60D08ULL, 
            0xE9AEB4512DF475A2ULL, 0x3F7EAF852F2C6524ULL, 0x62BA967030DE79CFULL, 0x4D7BDC5E673B9B34ULL, 
            0x2EC8EA5C7E583982ULL, 0xFBE4F128E669683FULL, 0x76CDCC289845C07DULL, 0xF5E17C5A67DBE111ULL, 
            0xDADCF6CC747565CEULL, 0x86318821CDC2DD1DULL, 0x5D03763F1856F759ULL, 0x7CB89E76DD020DB4ULL, 
            0xF6C175C1B38AE2E1ULL, 0x404262AF58444586ULL, 0x9CC78EC473CE6395ULL, 0xC0DC570FA0CC0F07ULL
        },
        {
            0x277AB4891D3E5A9BULL, 0x0F5E7E1655E2F99EULL, 0x5EAACD857BFD125DULL, 0x278477A69F91335FULL, 
            0x487864F19C66C0C8ULL, 0x32EB0D2D9B4C8E2CULL, 0xD6B09F5B555D7078ULL, 0x79C045B0CA9BCBBDULL, 
            0x212DA90C5E8B212BULL, 0x83609559184EEF2BULL, 0xD24DFF3E6F5D3468ULL, 0xD754DAFA0D8CEE0AULL, 
            0x4C4D8FEBBDADF1C5ULL, 0x23573F5B647BBF2EULL, 0x5EAC11E1B65B6858ULL, 0xAB921851A661D7A0ULL, 
            0xAEB9AFF30F21F7F7ULL, 0x48DE4F2564146266ULL, 0x4F8D765EF4A61C7BULL, 0x683E63E1424810B7ULL, 
            0x75EBCE587B994085ULL, 0x6B7217C40AAB4984ULL, 0xA9C13997BF36AFAEULL, 0x46E7E102D0773635ULL, 
            0xA8C0A5242D956D63ULL, 0xDF3825C656AF350CULL, 0xF24775AAB115C6D9ULL, 0x559C0D6EFDF83FD7ULL, 
            0xF6B93CFD90FB0A85ULL, 0x10E62EC3349D75AEULL, 0xAFEE30A513C62A45ULL, 0xEC238AE5A8EC9B2CULL
        },
        {
            0x8C2CCB7DB27199DBULL, 0x953C8A696B3FCEF8ULL, 0x2007DC3CC1790C79ULL, 0x829AC3812AC86482ULL, 
            0x4DDBA12B8393B528ULL, 0xA88ACDFC6953D49DULL, 0xABC7F2CA570B89B5ULL, 0xCD95DA0A7F90FEB8ULL, 
            0x93ADD72DC4D5133DULL, 0x409981435DB49304ULL, 0x0F87BE8137984994ULL, 0xC385FB51CEF4CE87ULL, 
            0x9FC967C964F6C640ULL, 0xCFCFCD68525B8804ULL, 0xAF00C13735CFB82CULL, 0x98291A4E5DF62794ULL, 
            0x89B2EB7214585CA4ULL, 0x55F519F9E5915BEBULL, 0x5BB12D8052A036A1ULL, 0x65C7235D2DABC181ULL, 
            0x75F38C54B85C0D2FULL, 0x1D6D9C02279E2102ULL, 0x6BEEE201DED28D67ULL, 0xBAE4CCF8949C233FULL, 
            0xF320DD3FDC93C0CAULL, 0x8664F30294CB7A69ULL, 0x93AB01B5D81CC848ULL, 0xA4E27C5016DD82C1ULL, 
            0xF070F5900A03A5F5ULL, 0xDB5B9D622F444ED1ULL, 0x32005687C9D64FB7ULL, 0xF37951E4F47C03B3ULL
        },
        {
            0x668119EC94858F3CULL, 0x51EE7087BC279531ULL, 0xB8E672DB512DDB94ULL, 0xF3EEADD982324C44ULL, 
            0x62965EAEDE9E14FFULL, 0xE97F1C8A0D7EB146ULL, 0xA170C0618F7B1F8DULL, 0x5C75F54C92FD5DDFULL, 
            0x59871DF56213A11AULL, 0xA26039F763182086ULL, 0x473818D87A66BB21ULL, 0x42B7201579C3C0A4ULL, 
            0xCCFF487E149B4183ULL, 0xC5D8508F4F11568AULL, 0x26202F52AD0A853DULL, 0xAE421FFAD0BEB2B0ULL, 
            0xC77D5DAAC285B4F7ULL, 0xD77F0BB39976AF42ULL, 0x26772CB78A8B77F4ULL, 0x1AD912260FA916DAULL, 
            0xCF6714A95BD7CB56ULL, 0x0F9AC4E40B66DADCULL, 0x06338C89E9D69FD4ULL, 0x7B5B0B66B840A228ULL, 
            0x5968C71E064CF71DULL, 0x9E2C9F01A4024AFEULL, 0xDB4F9E68D7666158ULL, 0xC2D90D0B0E4290C7ULL, 
            0x51DE1DF5A89E4817ULL, 0x8DFBED9D687E1080ULL, 0xA2E926FC859FA239ULL, 0x2E1DAD1B9D22E237ULL
        },
        {
            0x76CFCBFEC196EEB5ULL, 0x12D46A8994E1835CULL, 0x0C81DB30AB75DF9DULL, 0x51F32193EAA5286AULL, 
            0xA5FFC8E0E92CC3BAULL, 0x9BB1EAB0FA972039ULL, 0x9D805F2AA24C0230ULL, 0x7F7346D0AE53DFD3ULL, 
            0xE9AD3C7BB43D0EDAULL, 0xC6DE4037B2F70CE7ULL, 0x68EB4A370EF7A3A9ULL, 0xF49E78A0EA58EC79ULL, 
            0xA40DCD6F01C56F6BULL, 0x0B82CCA4CB69BBEDULL, 0x876BEE11EAC44042ULL, 0x0B53CF1323384A60ULL, 
            0x66B74BBD995EC7B6ULL, 0x395646A3C5E973FDULL, 0x367ED2EFE07D5A9EULL, 0xE906C374DDF3C2F1ULL, 
            0xE52220C5CDF1E25CULL, 0x25FAA1057AC33237ULL, 0xD7F3C6968F728890ULL, 0xDE1965FF0753377DULL, 
            0x3915F5A1C1D6C01DULL, 0x4BF9A1BD5F25E2F9ULL, 0x1660C82F91B1C57BULL, 0x61C191D091995080ULL, 
            0x0C89F85E78D33103ULL, 0x8C2CC1F0738DBEE3ULL, 0x9C966A58E9C48EE6ULL, 0x19F6905E8149F89EULL
        },
        {
            0x1B3057EE3B35F6FAULL, 0x38A22F0E4D3ABBECULL, 0x22A4857BE04385DDULL, 0xA14D3B51D3D3A10FULL, 
            0x3C06A895D65D7653ULL, 0x64AAAAF2DD956238ULL, 0x30D95A684D43869FULL, 0x2C4F6DF8126C723FULL, 
            0x43A98BC43BAEF41EULL, 0x3D2D886934D8DFCDULL, 0xF458DD83C0165BD0ULL, 0xE3F0C36887F0754AULL, 
            0xC748749F3DD5493CULL, 0xD28B31BBC2ABE7F9ULL, 0x5770A21FA59BEB41ULL, 0xBE011BFC62FF7ADEULL, 
            0xD49A9C5CB82C280AULL, 0x3C98072D674F98FCULL, 0x0061CEAF5F94EA0FULL, 0x6835440B3B9983F2ULL, 
            0x1A88C6D5BBEA7C69ULL, 0x7D5CDEF7BF7C89FEULL, 0xF5B632E147979A13ULL, 0x81EB97DF8B07B42EULL, 
            0xC1A9DF150678C5C5ULL, 0xDF8A4A8DA43BBB9DULL, 0x3B90EAE765FDB47FULL, 0x377AA3A501490F1CULL, 
            0xF0864AA31868B855ULL, 0x20EA86AF455381E6ULL, 0x9ACEE87707AF9E09ULL, 0x0F37C97FA03738B8ULL
        }
    },
    {
        {
            0x16939908460C6CC1ULL, 0xFFEFB987FA917CD7ULL, 0xDC0BB7421BCB27A1ULL, 0x3CC3FC8AB8C8EA95ULL, 
            0x1329DA1DBC948FECULL, 0x97C09B09797A9A3FULL, 0x29369EDFDCB7315BULL, 0xFEB59B83C83A07B6ULL, 
            0xD5B9EC764CB1DFB4ULL, 0xE5F4AF84B54BF519ULL, 0x9B645D9E0B2D4DB7ULL, 0x19346E4D66A2126AULL, 
            0x764D61B226D05515ULL, 0x615DB40BEE0E14E4ULL, 0x693D34802E36CAA1ULL, 0x9EAFC51C6DBFBAA3ULL, 
            0xA9C643C37B15E57EULL, 0x7CF3A9467BAEDAF8ULL, 0xB120551EA54A7AEEULL, 0x931A0402F07FBCD4ULL, 
            0xDF4706F2DFC25E72ULL, 0x8C30AD62AC417683ULL, 0x3FD7D2E0280F9DF8ULL, 0xF11FC932DDD70F8DULL, 
            0xC72DACFC73BF23ECULL, 0x66A98E481C41E431ULL, 0x43C11E5878CD6868ULL, 0x4540C40614EF7CD5ULL, 
            0xE4865FA191AAFCEAULL, 0xE41497A5BF251D40ULL, 0xDA35285038B7ECADULL, 0xBA82391F77342F5DULL
        },
        {
            0x61C29D7774E86168ULL, 0x8E3EC52A04683478ULL, 0xC209EE65B5FD4351ULL, 0xA488D0F11CA4D2D6ULL, 
            0x0578F672E0DF5E6DULL, 0x79B527E1D8D5AF64ULL, 0xE2AB0ECC4D2382C9ULL, 0x380D44AB44F6A82FULL, 
            0x800D71F17DFAF005ULL, 0x2CE1ED00C8C88CACULL, 0x534D92C4EC38F123ULL, 0xB5A91FBE393B9173ULL, 
            0x1557E40FB81783C8ULL, 0x8F32AC76BBC60751ULL, 0x6BE8A17E94CB0AB3ULL, 0xE8213D6798CA151BULL, 
            0xD98450F6E856D4BDULL, 0x293647D037AC9CE0ULL, 0x58AAD1DE96E34A62ULL, 0x0732DDAC861D5DB4ULL, 
            0x2AFD7A6F3700F004ULL, 0x0F410100E7957823ULL, 0xD8E72FAE25465B16ULL, 0x5DB5C53EA9117EB8ULL, 
            0xF64CCE761BE7C26CULL, 0x263359966EA6E437ULL, 0x51AF652431B6C597ULL, 0xAD00725F116FD3D8ULL, 
            0xAF10FAB6E07D5445ULL, 0xFBCDA3CB25AAB8D1ULL, 0xEBAE4A0237732683ULL, 0xE7450B11430D4CD9ULL
        },
        {
            0xE533CD4AB30FE181ULL, 0xF47A8A781C503426ULL, 0xD6595CD808ADC73BULL, 0xD62D241DEAE03349ULL, 
            0x922E5C1ADDFAE201ULL, 0xD70BE199C15DA227ULL, 0xB2E767460646AFA5ULL, 0x2DBCE64A79832D46ULL, 
            0x65D3018938B526D7ULL, 0xAA8AA9B39593BCB2ULL, 0xFF6B7E8BF202865EULL, 0x673EC7DD4FD658C9ULL, 
            0xC38F0CD229CF4A5EULL, 0x72B9F368560D0D01ULL, 0x744852447FC8BCFDULL, 0x675C421971151152ULL, 
            0x369A92F09F6EDA67ULL, 0x6EFCFC71B909BA9AULL, 0xB851032EFADB21F9ULL, 0x96593BE9E0BFD1EBULL, 
            0x25ADD70257CF085BULL, 0x39A3344583D905CEULL, 0x4AE4B576850BB0DFULL, 0x924E1CF3028BEE39ULL, 
            0xBF4D5519EAF6FF83ULL, 0xBCD08DEDB719DE9BULL, 0xD98425542DB7E560ULL, 0xF32C074B44D27671ULL, 
            0xE5EA02166D52C7C1ULL, 0xE0CCCE27D5C2F9E5ULL, 0xE32C561B461A2EBCULL, 0x9592BF374E62B282ULL
        },
        {
            0xA01F987FFB23A90CULL, 0x2710E661AE51BCA7ULL, 0xABA2DD6842201F7FULL, 0x4C8AFB8C047441D3ULL, 
            0x3622F328DA752EBEULL, 0x27E7C0D74F69FD75ULL, 0x76869F7AF7B63F51ULL, 0xFC707D12A16B6E58ULL, 
            0x76BD205C8BCF47B1ULL, 0x5C1118F9D003A8C6ULL, 0x786A3977003221A3ULL, 0x57372D9F3C4E692BULL, 
            0xC61AE524A3ECBA8BULL, 0xB911B81854579061ULL, 0xA38487F4F6FB77AEULL, 0x0D0C13CDF696B2EFULL, 
            0xB448CFF9EC4BE094ULL, 0x87E5A4038097008CULL, 0xDDBE482B6F06476CULL, 0xCF68AD847A97B230ULL, 
            0xCEA4D941DEA6D33AULL, 0xE4873AD817BFE9C4ULL, 0xB8E428C806C1D9A6ULL, 0x0DC40BA435CA90B3ULL, 
            0x921CEE3569E11874ULL, 0x83238E03BD2FA254ULL, 0xFB100253546AEF13ULL, 0x33CDF927BBA2816FULL, 
            0xF08A8814CBC2C8F9ULL, 0x503DD8100AC8A273ULL, 0x9C519565D0F46A1FULL, 0xDA29A971F50E35F5ULL
        },
        {
            0x9E03118C473C7219ULL, 0x665919C42C4298B8ULL, 0x99A8057E5326FF47ULL, 0xB4982AFB03CBEB89ULL, 
            0x8453CFBA4BEF0CDAULL, 0x3F4FD2111361537DULL, 0x60E48FD42D44BEBFULL, 0x8CF269A39341DDD7ULL, 
            0x071B51C3FBDFFBABULL, 0x4E2C50CCB6152592ULL, 0x4BC6B8D567E90214ULL, 0xB4D681ADBBEC5D73ULL, 
            0x34EE76A2EDBB67B2ULL, 0xBD0BE9B8D3EF1B85ULL, 0x719AAE80EC36BD35ULL, 0xD39C718EFF9D37BEULL, 
            0x35F42A1BF417E8E4ULL, 0xFA109E69A0803850ULL, 0x66538262B4B0433DULL, 0xE2E6EC892D94F3C9ULL, 
            0x0FA3AE0B67221B8EULL, 0xD5E18F654078025EULL, 0x9E59173B531D11F4ULL, 0xFB35BA6C57449ECCULL, 
            0x184802154292A195ULL, 0x7C4E8854269AEF62ULL, 0x76D4785B624B4486ULL, 0x6CB07268FF58F42CULL, 
            0x24D200EB1C2CED49ULL, 0x75C853474CF15CA4ULL, 0x36D5FBA8A822FBCBULL, 0x447E6711408DD4DEULL
        },
        {
            0xC1C6227F5E045A3AULL, 0x159E88BB031A0FEDULL, 0x3CFC3151239CE121ULL, 0x35F8BFB5729D936EULL, 
            0x6E632FCDEC1F2C20ULL, 0xA5B4B4D7E6A60BC7ULL, 0x2D8A25863410DE65ULL, 0xF7C953DB910C401DULL, 
            0x4A736E489CD11934ULL, 0xC71549BD898D7304ULL, 0x91EB3696ED13364EULL, 0x992F8B5AA504976CULL, 
            0x9381C34C992ED3E7ULL, 0xB47FCC68453D402CULL, 0x067FFD9A1D9537A1ULL, 0xB58906C35487B293ULL, 
            0x48CFAE7A7C2607F0ULL, 0x147104FFFA22FC1EULL, 0xE763F378D0C997ACULL, 0x1DC6C2C75C054A10ULL, 
            0x046AD61D96E2F49EULL, 0x19CB26C0A5B6CABFULL, 0x633AD06AB179090BULL, 0x76B733DED5367DBCULL, 
            0x57DF323ACC7728B9ULL, 0xA1B26720884C8A2FULL, 0x58CB39984F063CC7ULL, 0x4865FA1572D8A380ULL, 
            0xA4842DA9238F2315ULL, 0x6E1A7BE82ABB1DD0ULL, 0x761148203029D9CAULL, 0xFE35BD64ACE532B8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeySpawnConstants = {
    0xE5851D26F826E65DULL,
    0xF6E9A216C5F63F2AULL,
    0x7A626EE101115676ULL,
    0xE5851D26F826E65DULL,
    0xF6E9A216C5F63F2AULL,
    0x7A626EE101115676ULL,
    0x353A3F25098DA906ULL,
    0x5D2BAD8AB3C2F59EULL,
    0x70,
    0xD7,
    0x97,
    0xF1,
    0x12,
    0xE7,
    0x3D,
    0xF6
};

const TwistDomainSaltSet TwistExpander_Alkaid::kSeedSalts = {
    {
        {
            0x34F72A3C993A57E7ULL, 0xD9826E7CF4CBA39AULL, 0xAEBB5E8EAEE497F1ULL, 0x91AB118639386A0CULL, 
            0x86F7A5C18B3A9D46ULL, 0x18A5A81A630EFBF4ULL, 0x15A0B8FAFA2C34B4ULL, 0x9EBC506BB26600B9ULL, 
            0x11BD47486DF7E430ULL, 0x90FEC8777AAC4C29ULL, 0xF721860ACF18F303ULL, 0xA6E15B2AC8DCC8E1ULL, 
            0x08372941944FF13FULL, 0xF8BE263D7B97C853ULL, 0x338C80F0851222CBULL, 0xC82107DB48A61BE5ULL, 
            0xB261B76B57408B2BULL, 0x232D2646004FA621ULL, 0x5D2941EC062E7A06ULL, 0x9DF0EA63C583ECCAULL, 
            0xD43CECBD91F28C4BULL, 0xD54DA8C5468AB3B1ULL, 0x34C13418E3A129D5ULL, 0xBEBCEE52FA2C9BEDULL, 
            0x7F52EC3A4F366ED3ULL, 0xAFA4E665CCE3C13CULL, 0x648B6F80B929B430ULL, 0x1F9189E76B6656CFULL, 
            0xA22B4BFD7BCE89A8ULL, 0x48CE5B6421708C43ULL, 0x0DF6F649A223BDA6ULL, 0x83A8E4FAE1970DE9ULL
        },
        {
            0xCC7742C44914B010ULL, 0x3EB952C5608DB5D3ULL, 0xB6AB66943E3F1360ULL, 0x54E27BE35177167FULL, 
            0x5170D151D263983FULL, 0x78A5039CC3A343A2ULL, 0x2F45817BA58995B7ULL, 0xF64D6D8AC9D67E50ULL, 
            0x598C9C8A0538B8C0ULL, 0x806F8CB830EDF699ULL, 0x9CA19EBDC0443621ULL, 0x39CE2110B915216AULL, 
            0x5451C4F300CC6BA6ULL, 0x275E11CC9294B93AULL, 0x15D8F0803A340B2FULL, 0xA2D3288F4EFAEF4CULL, 
            0x142303C512FB7A36ULL, 0xEFF76A2882FEF684ULL, 0xC1006B594DC5D4EAULL, 0xF084B297BA1A979FULL, 
            0x8BEFF001E32C622EULL, 0x13E8E1BDCA08184AULL, 0x98D092F8EAE1D921ULL, 0x95DD7877F29AFF03ULL, 
            0x9876F4C2E012E413ULL, 0x2B5B2C62C1C0E78DULL, 0x466C47079351C632ULL, 0x413ADDC9A50C0F25ULL, 
            0x34ADCEC634DAC9E7ULL, 0xE899473811CAEEF7ULL, 0x5D06FF2AB7C8A243ULL, 0x437E9A7404751DA3ULL
        },
        {
            0x25B0B65DBBE340FEULL, 0x93EC6CF66E28931AULL, 0xB89BA12BAC6664BCULL, 0xC20D9CEDF56283A5ULL, 
            0x8396A9882AD12952ULL, 0x8950E3A7FE48337CULL, 0x7BA1BBEEAD4C1F90ULL, 0x90356D2CC6147639ULL, 
            0x2C2503BBE58F5276ULL, 0x0647E5E52F989FA3ULL, 0x8C20EBF5241FF031ULL, 0x002B4476741B5CABULL, 
            0x38C8A4D8CF6CA754ULL, 0x0B3FEFCE3B1A29B7ULL, 0x6090F4647DDD7B4AULL, 0xEAB1ECE261B35A10ULL, 
            0xE51751240EBDD96DULL, 0x0538C30C4DEC3BEDULL, 0x3E791629DB4E94EDULL, 0x5BD320A6E82DC77EULL, 
            0xCB67BC9052FC17D9ULL, 0x4B183E3DAB2EFC51ULL, 0x63B467FD4091FFC0ULL, 0x603672D4B39C09ADULL, 
            0x5CE405BBB0DDC950ULL, 0x8E186A4B10CF86FDULL, 0xC6B84137B822CEBEULL, 0xF0D45A447B0320DCULL, 
            0xE17E1BFD34D38335ULL, 0x271F631142140395ULL, 0x8889142DAFCE1140ULL, 0x3B16FDC9DC83DDF8ULL
        },
        {
            0x45ED193457D4CC1EULL, 0x68738F9966CB07A9ULL, 0x13EACDEFDB1574FFULL, 0xD1F235BE3A3E905CULL, 
            0xDFD1B330882AFB79ULL, 0x6CCCE5E050F1AF0DULL, 0xCBBFE546EC18E247ULL, 0x06FBD66FE137CE3FULL, 
            0xF4F4E6BEBA71C872ULL, 0xBF42E623A2343ADAULL, 0x22363E4E28774601ULL, 0x4A04317320F9A69BULL, 
            0x4CDB61CEC7151451ULL, 0x2A45CDF078404088ULL, 0x9C8484C2C2E5FA03ULL, 0x62D57CCED8BA97D8ULL, 
            0xDAA6361E24B7FBB3ULL, 0xDD06C3ADA17BEFC1ULL, 0xCB103622309F611BULL, 0x1AEB1858F0A589EDULL, 
            0x05740582AFC0E3FEULL, 0x724155FABB6DF2FDULL, 0x8546F6A72C432101ULL, 0x493C924CA569850BULL, 
            0x3E5303FA4463F4E6ULL, 0xA86A5584FE0D81B7ULL, 0x16004A40BF8E24F4ULL, 0x96B0B0108C98F9C7ULL, 
            0x7C031605A7794BBDULL, 0x961A5AA783EF7C7CULL, 0xA7F42CFC9E1DD67CULL, 0x4841555F9AE7C8C6ULL
        },
        {
            0x93F928CE761D003CULL, 0x801CD6A250E91D85ULL, 0x55AD5029A1E0DEFAULL, 0x455D12ABE0F34E2FULL, 
            0xA497F9F91997374EULL, 0x8FD865721810CFDDULL, 0x0C82E5E036E63DD2ULL, 0x6A46AF7978629FF2ULL, 
            0x85FC9E0E071D65E5ULL, 0x118D5C6CA9C6B81DULL, 0x004F0F90C8531998ULL, 0x97274AE7B81574FFULL, 
            0x1814CF5C64404C26ULL, 0x0B5D923437A8BA82ULL, 0xAB81F4BF7A4D6B1EULL, 0x150455AF6D7DFF0BULL, 
            0x83262BD2D9D8F2BEULL, 0xCF2677EA536250C0ULL, 0x27E4F47C8AE4FBF8ULL, 0xFFAEE66A115AC469ULL, 
            0x9C561856B375BBC8ULL, 0x07F2C918A7D551DDULL, 0xB071C3687FB2C519ULL, 0x92291677EBD185A8ULL, 
            0x072E2A308944CAFCULL, 0x71D6948F15AABFDEULL, 0x34D68001C2DE791DULL, 0x8F7EDCD9D8A1A8F3ULL, 
            0x13087F642F28F2D0ULL, 0x2EA34CE8F015437FULL, 0x5A122864BE3BD31BULL, 0xE82AAFB96424A0F2ULL
        },
        {
            0x6E8B7AF09F8E1B80ULL, 0xE879F4304FCBE210ULL, 0x5D0109DC7493B5DEULL, 0x693FFE834341CF9BULL, 
            0xD9F50C64B82EE536ULL, 0x40F1B64413ED2EF0ULL, 0xCDB0CE9437D06BEBULL, 0x3316B47A2D139F9DULL, 
            0xE7474A7B3B67B96EULL, 0xE6FD6263D8544E25ULL, 0x58D095B89A5F14F5ULL, 0x5B706DEE19CF9138ULL, 
            0xF6981D4F0714844CULL, 0x4C179761E3B0534BULL, 0x25C230B9E9ABB235ULL, 0xD2DD5AF66B8C9173ULL, 
            0xA827EE2F9E7E0551ULL, 0xFAAF3265C6365B78ULL, 0x68D789A7D9495513ULL, 0x16177A7D5ADA66E9ULL, 
            0x37793F2204EC5F54ULL, 0xAAB704D01E20F54AULL, 0x3C7F928D1190C215ULL, 0x221038CF0449F808ULL, 
            0xB0FEBBF99DD0C21BULL, 0x6CA0ACF5A7C30E98ULL, 0x7AEB11F73614B6FEULL, 0xF47819C857B4D61CULL, 
            0xFDE3BDEA174A09C5ULL, 0xB6440D6ABB998A0EULL, 0xDE8C7D44178F85D8ULL, 0x7FDDBA308BD015F8ULL
        }
    },
    {
        {
            0x5C278FC283CF8D47ULL, 0xF43705266D9EE65AULL, 0x36D4C143B17F741EULL, 0xA554B7ABCD3ABE7CULL, 
            0xEB16979CBFFA3151ULL, 0x37A9A2336B908956ULL, 0xA71FAA73267E1E90ULL, 0xB6DCEE28D91E6C73ULL, 
            0x815C28F0054AB762ULL, 0x4CBEA534A3D1913FULL, 0xB3F7AA056763A922ULL, 0x8D7E7E27D56F8E93ULL, 
            0x7AEFD19DF5884A2AULL, 0x02394ACBD98BB965ULL, 0x574ECBA2F2C41BB5ULL, 0x7DCFAA31183789F0ULL, 
            0xE786258A12918E5EULL, 0xFACF34FEDF53EFD9ULL, 0x5E2D2F8052B35D42ULL, 0xBB1A7D42FDE71ADAULL, 
            0xBC3CBCDAF9C60986ULL, 0x7EBC3F8D0D424C1FULL, 0xCA8717464744608EULL, 0x77D70AE653748CE3ULL, 
            0x131A6640051333BEULL, 0x021248A9D2D79AE9ULL, 0x3468181D4F4CE955ULL, 0x04A11EC30B41079BULL, 
            0xC020122D04FF03ADULL, 0xBD05D9B6E0E0FF13ULL, 0x56F405915ED7F85FULL, 0xB711C07331899E23ULL
        },
        {
            0x6A98C7C058AA7410ULL, 0x26481A9FEDA281DFULL, 0x86C61F3CB34618B4ULL, 0x464CAC4514D44972ULL, 
            0x0397E33E30217889ULL, 0xEE1F87FDA8CED542ULL, 0xAD59BEE41ECD7F87ULL, 0xED67C97B9CCF23EAULL, 
            0xB20026E6A9CF3732ULL, 0xB48EFD2B4D071D91ULL, 0x0647C841431670A7ULL, 0x14F14E76DF999F0CULL, 
            0xF6E1DD3836D98236ULL, 0xC10AFDFB2EA04217ULL, 0xCFC90F8ADCD2FBB3ULL, 0x18CA0DA8BED1EA04ULL, 
            0xC16868FF4015ACC7ULL, 0xB33C0C0E47CDC8F8ULL, 0x44C58248BF11048DULL, 0x525F3D6440C6F26FULL, 
            0xCF69977422475D4DULL, 0x61DDF57C5B8128C5ULL, 0xA5EC65F6F3D6E45BULL, 0x175D0DF505E2B1D5ULL, 
            0x1D08727C2BB63CFEULL, 0xB5CD2E2B58424BB1ULL, 0x84B5BCC4059D8809ULL, 0x65DDDE97D9537A1CULL, 
            0x6AB95E715626CF7EULL, 0x45F390CB79C6EA11ULL, 0x1EDE198FC0DC32B6ULL, 0x9D49CA156A77AAE2ULL
        },
        {
            0xCBC1F5529A6A2D6AULL, 0xAB5B5585DD17D309ULL, 0xE2BA97B42E64B6B5ULL, 0x7906689F39B068A3ULL, 
            0xFA5DB1D9AF702EC8ULL, 0xCF9274098690A679ULL, 0x833A8807167BCAAFULL, 0x8C28AE1B10ECCE52ULL, 
            0x56F062975959D5C4ULL, 0x59EC33EF5FE14147ULL, 0xCEC3499718C7042DULL, 0x4CB5F3392FA9CE5FULL, 
            0xCA964BAC9AC9E027ULL, 0xBE1711CDC3197CF2ULL, 0xD83EA88FD008A779ULL, 0xCE98D3A2652CE85CULL, 
            0x7A0E07BA2168735EULL, 0x68CED6302A7C8533ULL, 0x530D53F991E94CC8ULL, 0x58B22ED9847354EEULL, 
            0x756816EBB4D1FC6DULL, 0x088B1623806BBECEULL, 0xF7A9203B66D00761ULL, 0x59BDA5F3E68C9F1EULL, 
            0xA761DBC3A28C996BULL, 0x54C1D4CEC1BE2C3DULL, 0x5414F02BE2A0AD3FULL, 0x1434D4E5BB8988BBULL, 
            0xBC3C41CE63F970F8ULL, 0xA9E068CEC54F41B0ULL, 0xECAC2528E0914480ULL, 0xE3E6DC0A0C1BC473ULL
        },
        {
            0x41EFFA373B183CF3ULL, 0xC23F9A8720A6A30DULL, 0x5CF40361B3D68D15ULL, 0x7BE515280A9762A6ULL, 
            0x5A7EB6C15AA54503ULL, 0x683AA23F2C6260E3ULL, 0x3D5C1DDE7896B341ULL, 0x48D5B8BCE7BD93A4ULL, 
            0x542F853BBA4E7DF0ULL, 0x072EC45B5AE82E5DULL, 0x6E19FE72D6DDC00DULL, 0x13573A8D361013F0ULL, 
            0x0C68BE2149C96DFDULL, 0x4571F6AB9C8C45A7ULL, 0x6FF94F17F619B005ULL, 0xBAB56011E8127070ULL, 
            0x8055D0DD4EBFEBF7ULL, 0xE52FD96E08DD65DFULL, 0x264AFDC5C5D2E700ULL, 0x4573A208FA3DA1FFULL, 
            0xF853602B3EBBDE3EULL, 0xA9861C4D64A4FF3BULL, 0x3101220194213957ULL, 0xF38E1BE0F09A1E94ULL, 
            0xB64567D1FF861EBCULL, 0xBD4B2F58F064EB53ULL, 0xE8EB211AB956C1A5ULL, 0xF44ED8F0D2D59250ULL, 
            0x1ED0C4D0277267E9ULL, 0x83123AA349521ACCULL, 0xD67D84F687853A0FULL, 0x3162C03625F4F1B4ULL
        },
        {
            0xF7346B7338F00D0FULL, 0xE565A5A46BEB51AFULL, 0xB1CBCB3103AA9433ULL, 0xE82F4B8E3E55BC3CULL, 
            0x5EDC397FF86885FDULL, 0xB633AD05379A1ABDULL, 0x519C234E4AECEE04ULL, 0x90DF9073E489F2E4ULL, 
            0x835F969E296455D6ULL, 0xADE3EEB59860274EULL, 0x67C128A40AD58005ULL, 0x42FB5BBB45587445ULL, 
            0x2AB54A5D8559E9F7ULL, 0xE73CA536C01AFCBDULL, 0x530B6FC9A273E5CBULL, 0xFC921D9AC2BF3B64ULL, 
            0x78326287F9283EAEULL, 0x6BA394CADA8CB4FEULL, 0xAB38F763BE2E294CULL, 0xB675D234F7D2A014ULL, 
            0xB15F9FAF87E93B61ULL, 0xA031896C5D310BE2ULL, 0x2131316BD1D7D5FDULL, 0xE2AF3647AB3CC141ULL, 
            0x66293C6DB203CF89ULL, 0xDE23DAF599C9201FULL, 0x9504C748A43A11E2ULL, 0xF6E4D0ECDB3E1A3AULL, 
            0x938A91ABCBD8139AULL, 0xF2DBBB42D63544B1ULL, 0xB30A41FD177C5887ULL, 0x3F2A037F2F6268CBULL
        },
        {
            0x1C47D08588D2A9E6ULL, 0xD987423DE4704344ULL, 0x5CC0EFDEDD5BF1C1ULL, 0x1828FF06E58B4126ULL, 
            0xAFF0E9319507E6ADULL, 0x99DE38A67FC654D6ULL, 0xB4EAC3D10E2768D8ULL, 0x74385BE90D44B270ULL, 
            0x0E8A7B707237A8DBULL, 0xCF541F41C712138DULL, 0x266862CDA12E5E50ULL, 0x98F45FABBDF23F02ULL, 
            0xCC2E3956A3F5A34FULL, 0xD59421F042EEC2E0ULL, 0xDA0086745FDA3933ULL, 0x6F57C7454F752E8CULL, 
            0x87483FA0C05CAE6BULL, 0xA7A7EDD2A22248B2ULL, 0x0DE8261D8349A86EULL, 0x75A857E6D86C032CULL, 
            0x273B9D6F0DF94120ULL, 0x72B627C9663F17F7ULL, 0x1532A026FE4F1FF2ULL, 0x9ABA3D83E4E6A24EULL, 
            0x50C3AFA913BCC111ULL, 0x66C507F501E440F8ULL, 0x3458A47F499FE42BULL, 0xD7A0FD5E93088858ULL, 
            0x8793D4902D887044ULL, 0xFE41DB3B5809AE31ULL, 0x6AA54C3F2E6D6E7CULL, 0xC94A92EB7CE75321ULL
        }
    },
    {
        {
            0x7735695C69832FE6ULL, 0xD1B72809BB8B4AD8ULL, 0x097346D7618F5205ULL, 0xC08E4ED87AD0D9F6ULL, 
            0xF0CA7C57EC569F69ULL, 0x6BA0CE94CC5BA8ABULL, 0x693DC0C5B2B949C0ULL, 0xF65CB7F715B68F9EULL, 
            0xD58B4B300CC9DCEFULL, 0x25F7079FF18851D8ULL, 0xBA597178B26A1C43ULL, 0x916ED69DD67DBEE0ULL, 
            0xEED40D2F6702DC08ULL, 0x78FDE6DD95BA1305ULL, 0x72FF09D91DBCCCA1ULL, 0xEBAE8A6DD30447E0ULL, 
            0x395D74B4C1C24274ULL, 0xD4C0155EF1BBB839ULL, 0x594E6E1FB636889AULL, 0xC150123630C1E559ULL, 
            0x3FB143BA872889A8ULL, 0xF9AC418FE4821E08ULL, 0x8023388FDA8E4F97ULL, 0x8C4C759A5FB1085FULL, 
            0xCCDEDEC0F8EA2696ULL, 0x3FEA069A203E20C9ULL, 0x7C0DA8111711328FULL, 0x7EC3044B9AF4013AULL, 
            0xA539E48CBA40BA15ULL, 0x32000646874235DAULL, 0xDB48E10FE5CBF219ULL, 0x91F4F5CC3096D94EULL
        },
        {
            0x553EEA8519E726ACULL, 0xF9A41160A8FF3CF8ULL, 0x717B5828866C8ECDULL, 0x4AD6B62286A086EFULL, 
            0x5DB31DE1BAB6FB20ULL, 0x355F688E8DAD3957ULL, 0xB432F2EB9150E297ULL, 0xD9E39B1E82832161ULL, 
            0xA3E456E8A71629F5ULL, 0x4C57139490847C27ULL, 0x2D6BAA39AB76A779ULL, 0x4DF2F8AC316EE059ULL, 
            0x4710DF44DAF51302ULL, 0xB0CE07EE0AA2E2A4ULL, 0xE7B94373DEE590AFULL, 0xE29535DB43FFB3D6ULL, 
            0x082EF32B8E9B52E9ULL, 0xB5ACFB3AA803159EULL, 0x1AD75600DF598137ULL, 0x972D2568BB0F9813ULL, 
            0x7DCDE2BCEEE38643ULL, 0xBBE6106F469E8F81ULL, 0x9BFE331F8DE29870ULL, 0x1819B4E840B4B5C0ULL, 
            0x9814C10FC7DFDB16ULL, 0xA6C9025640EFA10DULL, 0x6E96BD49D2CB8FF2ULL, 0x7E47D8F1178AADB1ULL, 
            0x2698CBB1622ACB2BULL, 0xC3B8F51695CA59B4ULL, 0x2116A99B8B4B8E1BULL, 0x157FE888CF85E090ULL
        },
        {
            0x06BA6FD3BC903714ULL, 0x8CDAF145BDABEBD3ULL, 0x2195E21E330061D3ULL, 0x8394F7371DFF2B8FULL, 
            0xDAD04090C8FA993AULL, 0xF7FA83B13316D8FFULL, 0x9FC4CAFA9D98F7B3ULL, 0x5B3C47803A0EEDA1ULL, 
            0x9C51D55E4955F876ULL, 0xE624ED15EF9A4CD5ULL, 0xA2C23D25DBB7D5D6ULL, 0x476D7E5EC1D821DFULL, 
            0x308E72B779B5C72BULL, 0x05D42C8B95F0DD0AULL, 0x9BEE72B4E7A97605ULL, 0x8B7AD07B991B57A9ULL, 
            0x7E259E4BCF451FEBULL, 0xD53BFD6074CC19A9ULL, 0xD748707B09EA14BDULL, 0x1533B018915437F7ULL, 
            0xC736401A4E3EBDBBULL, 0x184810D26EC5077BULL, 0x8E28B8648D1558CAULL, 0x2759E55E446D0A2AULL, 
            0xE2AF10ED554D0D70ULL, 0xF2226481A4E657D2ULL, 0xD500471BF6FF3029ULL, 0x5BE2DAAD5A51A933ULL, 
            0xDD4E3D7ED2F2D5DFULL, 0x2A57820205255514ULL, 0xA0F293C7D716E8E5ULL, 0xBD9C5F0C19952379ULL
        },
        {
            0xB58C33B7F1416B4AULL, 0xCAC68E345BBB4476ULL, 0x8B0699F6ED4B7E68ULL, 0x4480DF21034516D1ULL, 
            0xA8C400FF4F0C5B86ULL, 0x11443C3E48CF21D5ULL, 0xD4747CC0ED3083DFULL, 0x5DC98DFAE95517CAULL, 
            0xD640351AC612CFCAULL, 0x06E592779B99E695ULL, 0xD68F6090993AF3EEULL, 0x5C4231B03727021DULL, 
            0x83E030E3C1727A0DULL, 0x8216C4573E16190CULL, 0xBF19372DCC8B6257ULL, 0xAC06E1AA5B713E24ULL, 
            0x68B86309C7B8C1A9ULL, 0x96AE556FE803B848ULL, 0xB82CAFA2EF4AB4F0ULL, 0x868A42F6FA45812CULL, 
            0x474AEEA79786F0A1ULL, 0x6F63797726237660ULL, 0xE56517B3A4079F83ULL, 0x5A86D724FD0BF77BULL, 
            0x1765E894BD558C4EULL, 0x766EB7E2A94A0642ULL, 0x31F47177C10D51BCULL, 0xB8FED60EE5D1F012ULL, 
            0xB0D4A870C2AA61E9ULL, 0x1D9E74DB3D7FDED2ULL, 0x8D575AFE5C7AE237ULL, 0x7DA25C71069DF867ULL
        },
        {
            0x9F6A8EB16A50F761ULL, 0x0A8C7AA013B4C850ULL, 0x0B79637C11BF621BULL, 0xA8F02798EA8B79B3ULL, 
            0x649FA8B12A4A8BE6ULL, 0x58A33552F45AD712ULL, 0x445F4C57ED62AD90ULL, 0xB72A03AAE9F3D5FEULL, 
            0x9002BFEE1C5BD968ULL, 0x1647094A76CBFC61ULL, 0xD3F1442EB2D85693ULL, 0xF7871B3A27B9D098ULL, 
            0xA359EB76E47A79B7ULL, 0x0EC7AE87E62D1E22ULL, 0x24900A48E3592309ULL, 0x10F32ADA2F4EC880ULL, 
            0xA000899617DE36E4ULL, 0x95ACA9ADFC883D2EULL, 0x19335D4551D7AFFDULL, 0x4B64576395D91FFFULL, 
            0x1C63682569EDE77DULL, 0x73C70AB0AC5D5E17ULL, 0x523A53596BC41DF1ULL, 0x1F1F037CF858BB06ULL, 
            0xE399DAAA45005785ULL, 0xA453ED57D761021CULL, 0xF9753C11A089A196ULL, 0x2B982B49991D3ACCULL, 
            0x622A00FDB8389ECAULL, 0x8BDD66FF2DCA44F6ULL, 0x4CF985698C731F15ULL, 0x547DCE32BE336D65ULL
        },
        {
            0x2A7094C2DF15C76CULL, 0x0B7296795188F472ULL, 0x70CF36990B406D9AULL, 0xB7E606D3B55D0DDBULL, 
            0xA5D2FF45454052DFULL, 0xD138EAC026D8D702ULL, 0x42A159579883B7DCULL, 0x699563A4A7B4806FULL, 
            0x650F5E0082BE425BULL, 0xD320F9395E6A8101ULL, 0x404831E6D3F1CF19ULL, 0x9BFA97715506AEF6ULL, 
            0x2A3F878D909B249CULL, 0x8D85F3B3942A6F55ULL, 0xA9694F28D21B759EULL, 0x87CBB0A3533684E5ULL, 
            0xF9A03FDA3D422A03ULL, 0xA922BF8C6890C7E4ULL, 0x9F0CD3C6D7BABB92ULL, 0xFAEDBEA274F5A9BFULL, 
            0x313EFEA17CD96A3FULL, 0xF5268A8637D8E7BFULL, 0x877A36966D3F30F5ULL, 0xD0FC147ADBE2BC73ULL, 
            0xCF219C21C7B216CAULL, 0xD17971CCB922E3FEULL, 0x6D2D420B8E851E02ULL, 0xCF7CBD1F33E8E11BULL, 
            0x72D40E25FF2C984DULL, 0xE072C28061E3AD49ULL, 0xD922C7189006A140ULL, 0x746AA8116E562F44ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kSeedConstants = {
    0xB8437ADF130FB05FULL,
    0xF191B4C26F670856ULL,
    0xE09F0723EFE73122ULL,
    0xB8437ADF130FB05FULL,
    0xF191B4C26F670856ULL,
    0xE09F0723EFE73122ULL,
    0x82D94011DB5286A8ULL,
    0x9AC3D97A60551FC0ULL,
    0xC1,
    0xF3,
    0xF6,
    0x33,
    0x49,
    0x16,
    0xCE,
    0xB8
};

const TwistDomainSaltSet TwistExpander_Alkaid::kTwistSalts = {
    {
        {
            0x16A6B53A1F555528ULL, 0x9C442F81A27A2940ULL, 0xCD6EDBE57A401191ULL, 0xED8E941639D5668FULL, 
            0xFF66257AE751C062ULL, 0x0270284C99CA914EULL, 0x1547ED81B90B0BEFULL, 0x2B6BD18448DCBF0FULL, 
            0x0E1F0D3CCC13015DULL, 0xABFA742EE6B0A4FCULL, 0x2C467CF95E662B78ULL, 0xA6D06F6ED184D466ULL, 
            0x0C633F3E54482581ULL, 0xE1180754D58B976CULL, 0x81783E7F8F9D0F6FULL, 0xE43A700A00CF2C10ULL, 
            0x2A4AC1D9BEB3179DULL, 0xA20F98F8990A5BAAULL, 0xEF5B445E187C9885ULL, 0x59E1EDE265C42C36ULL, 
            0x9DDAC429925EA262ULL, 0xA469EE1EDA4C62F7ULL, 0x30EA9A817D7F3423ULL, 0xDA78FC5370C39388ULL, 
            0xDF6CE7410726A07BULL, 0x658DC9DCB58AF1AEULL, 0x8FB9CC9B71AF8D07ULL, 0xBFBAEC0A91CAFA46ULL, 
            0x9F436191218B9539ULL, 0x61CA74B8E584842BULL, 0x96C4412FC08E3287ULL, 0x186C89E80007651DULL
        },
        {
            0x87A3BA1A58076C1EULL, 0xFD23D95590950D13ULL, 0xB74CD65897523516ULL, 0xCA2920669122A5C6ULL, 
            0x6ACF9B5736E43675ULL, 0x91205D0D990EBE36ULL, 0x2BF42463659AB402ULL, 0x3AC179E7A39AB778ULL, 
            0xDA6B037D4B229930ULL, 0x292F4524F9744FBEULL, 0x9F093162CAA599B2ULL, 0x51CF171A2CE85D86ULL, 
            0xF0CAFB7D63BFA792ULL, 0x1EBD57343972ECB9ULL, 0x07CAD27A3E36F737ULL, 0xD0A00DC99DDA3D74ULL, 
            0x4252CE83B19762F9ULL, 0x895DC037E2DD33D3ULL, 0x62A2917BB7DFDFD1ULL, 0x7D567F3541242F64ULL, 
            0x4573A1DFC1D8B48CULL, 0xB4904BACCCA27B72ULL, 0x1DDC3D1BB2F1BE9BULL, 0xA1969BEA1DD3064EULL, 
            0x826113A170615075ULL, 0x4151CD49C598B1D3ULL, 0xAEAE3DE1E8391369ULL, 0x9DAD61CF29513326ULL, 
            0x43EC0000822FA7E6ULL, 0x53BBCCD0ED2FFA91ULL, 0x4A5DAADBC721B001ULL, 0xFB82090F2E11C7C7ULL
        },
        {
            0xF0EA7BC3FA9081FFULL, 0x05C5ACCB8C2AA182ULL, 0x553C035904392C64ULL, 0x96AA101BAF6D56BAULL, 
            0x239A6110CBC03DF4ULL, 0xD1D531BB7F10A404ULL, 0xCE46B6AA9E9CAE66ULL, 0x9D1959D4BFA3ECC5ULL, 
            0xC5B5F6F4800C7E87ULL, 0x82231C8E85E2BB5EULL, 0x5E626F31C250E0B3ULL, 0x84AF7DB833582A2AULL, 
            0xFB09BCBFA050E134ULL, 0xD7789149B6D6C4FEULL, 0x17BE3094C64A6B56ULL, 0x20E99770B143658FULL, 
            0xBD515C0003557D32ULL, 0xFEE6A1244E1E5B84ULL, 0x353E683FC330249AULL, 0x2AF275B4812EA0A2ULL, 
            0x7B0061042483FA22ULL, 0x0E8B6D18B005B0D9ULL, 0x66B11DDA40558154ULL, 0xA9D995C0A62F931CULL, 
            0x71CDB228DAD7A8E6ULL, 0x370193057980AAA0ULL, 0x1A7C3346F9057748ULL, 0xA4B40944A990482FULL, 
            0x7BCB65799DFA75A0ULL, 0x0B5965D0B2BD7B76ULL, 0x8A577D0E3B9BEBF8ULL, 0xC89BEC53E2B99F4AULL
        },
        {
            0x311B954D9832D3B1ULL, 0xC89E57BE24462CDCULL, 0x6FBECAB9D7089344ULL, 0x56FF3AF8A8F1F505ULL, 
            0x1F134DAD313A8287ULL, 0x68397EC5BA01BE96ULL, 0x89C61E3BD4951433ULL, 0xF64843183816074EULL, 
            0xECC8AD34902A3787ULL, 0x5BFCB63697AD8339ULL, 0x392702B5F0886572ULL, 0x2B0D2A7F9DF468DEULL, 
            0xAE418775FF300CA3ULL, 0x2D47D1B70054E890ULL, 0x25CE82F427420BFAULL, 0xCC3D585DB57F3CF6ULL, 
            0xE23E1284AFDB8997ULL, 0xC452FEB6BC4A783FULL, 0x924F0D68131436A3ULL, 0xC4D934C167F22BBCULL, 
            0x924EF72526B99159ULL, 0x476F08248395CC7BULL, 0xB2AF918DD3CDA786ULL, 0x9FE98DAD41BE4ACAULL, 
            0x399CEDCB1E83CD03ULL, 0x716B0FE38C03E564ULL, 0x5DE73C89614F053BULL, 0x07FFD65728A09CB8ULL, 
            0x8D5A4C9E80B0BCC7ULL, 0xBD5C9621883A4AE6ULL, 0xAD106EF135A69EBBULL, 0xBB21BDE9D7F29EAAULL
        },
        {
            0x25D89393B62FB1C0ULL, 0x32398D714EF8A463ULL, 0x8ABFCB0B7AC302C4ULL, 0xC84F1C35A9455315ULL, 
            0x17BFA8ACE50BF3EFULL, 0xA0A77A96D2AEAAD0ULL, 0xA46A178D26B8A233ULL, 0x82CF1BEFC91855D2ULL, 
            0x27CEF8A4C1DA6968ULL, 0x6467CA5068FD6EDCULL, 0x0BF019D07026F5A4ULL, 0xC0FE340C0093F05DULL, 
            0xDF024E84314D3746ULL, 0xF6A4BE5E57AB644CULL, 0xD080DE6DA935CBD1ULL, 0xF89C45422CC7D059ULL, 
            0x8426E57D738883AFULL, 0xA72E8AA4CA12B3E5ULL, 0x625267BFD35A578EULL, 0x1A0533A16D079423ULL, 
            0xDBC32DA071A0EE06ULL, 0x61D1F5AADF33D50EULL, 0x0828765AFCABA808ULL, 0xA70AC728B2A26CEDULL, 
            0x3AA4EA2E571AA429ULL, 0x2FFF77607B9129D5ULL, 0x97A8CFAE760A7B5CULL, 0x5521C125851D251EULL, 
            0x7DD655896573E060ULL, 0x931C13EF8D64E1A0ULL, 0x87BFCC429BA6CD27ULL, 0x570B2443831A32ECULL
        },
        {
            0x0E4F60D776B2D883ULL, 0x065B94F41F934A0CULL, 0xCCE479D11234A202ULL, 0xE98EE995B9A0E804ULL, 
            0x242C37411810A16CULL, 0x6345E79DD8B8D054ULL, 0x4FF21C3973A35DB8ULL, 0xEA0CF9ACCF1F35A1ULL, 
            0x80F9EB4283D8C0AEULL, 0x9F8908787811E852ULL, 0x9BEFD143CD72A144ULL, 0x8E55FF9D8DB94BF9ULL, 
            0x20DB2B217E496915ULL, 0xC19D0AD63DB9C41BULL, 0x4477297BB4265E9BULL, 0x3261C41AAE78F38EULL, 
            0xC413641DBC223E2DULL, 0xC9BF8DF586BE806FULL, 0xB27E2E22014FD19EULL, 0x6B4BB24A2482DC0DULL, 
            0x64FF2B671921443BULL, 0x6EDC005B392181B1ULL, 0xBFFBA7D41A450EDAULL, 0xBF51999542621ADDULL, 
            0x068557CD7FF02A73ULL, 0x9B6CE5EFDC61752FULL, 0x03AF756F3D8336D5ULL, 0xA80214C3D680E80BULL, 
            0x892FCBF505D3238AULL, 0xF20AA72706084CD6ULL, 0xF368D8CF1B514BD7ULL, 0x1D4B93D763969C9CULL
        }
    },
    {
        {
            0x6B2FDB080725F4E9ULL, 0x8FE941222158E856ULL, 0x619F2256B3376E12ULL, 0x8C1D7FDD7FB86817ULL, 
            0x4539CD78C05DABEDULL, 0xCAF927D950CDA8A4ULL, 0x9DEDB6E8DC0BC1B1ULL, 0x17CCBC1514EB071FULL, 
            0x2E1D32003AC416C6ULL, 0x7186CDAF1922EC31ULL, 0xB179B6433B54D5A0ULL, 0xDA6E9BDF4A266006ULL, 
            0x28BB3114EF9F094BULL, 0x927A4387082AF7CDULL, 0xCD34E7BD07D0BD65ULL, 0x72CB4CD6C108BE70ULL, 
            0xF9489928A75112CFULL, 0xFC3ECD6C641922A9ULL, 0x6B57E29E3C350B98ULL, 0x20949DE61336855EULL, 
            0x5653EAAB6704EA96ULL, 0x1674CC514EB5736CULL, 0x044EDA906C799B3FULL, 0x7255027997ED0C63ULL, 
            0xD43322837F05C632ULL, 0x44A1EF1A7D7DA0A3ULL, 0x5C7859260A90BA61ULL, 0x798EBC558F36F6DFULL, 
            0x0813EBB545D802D9ULL, 0x1509184DF45B8035ULL, 0x91AC99AE431D1B58ULL, 0x0F1CB0CD71C9541CULL
        },
        {
            0x3A2EF52553D0C6F0ULL, 0xA1BB4264FEAE0F2FULL, 0x73DDB7205EC69DDCULL, 0xC24A95CFCB92C7E6ULL, 
            0xD5406BA59AE0E309ULL, 0x012B1BD6AF3DB340ULL, 0xC49717E4D07CDD7BULL, 0xC5C8B8BB4AE51196ULL, 
            0xF9019945E6DCFAC4ULL, 0x3DBB8770B0D9785FULL, 0x042750B4993589BCULL, 0xC06948A8A4E99C97ULL, 
            0x9E8033631E113551ULL, 0x7155ABECC8497416ULL, 0xF2C57DA18D6933D8ULL, 0x55488E53A7D70446ULL, 
            0x68B8CF81DAE0981DULL, 0xC1E2933E6D44029FULL, 0xECAA68B8F277FF78ULL, 0x9168781AC2387620ULL, 
            0x50244404CAC1EE05ULL, 0x4FAAC823E3482D4BULL, 0xFF3FD3F190EE27A8ULL, 0xB8CF30673C8731E5ULL, 
            0xC3F572640F560265ULL, 0x6A0523BE0055DB9BULL, 0x553E1012304391CEULL, 0x78DE7CED25DFF9BFULL, 
            0xBC42597FE7075D1AULL, 0xB1D5D9258DE1F69BULL, 0x1BB57101EB28D2C9ULL, 0xA770123616B83D2FULL
        },
        {
            0x5C7B92D77C50F1D6ULL, 0xCD61CA769BDEDAB5ULL, 0x7BDA8D35EADE71CEULL, 0x7CCB1185A51AB427ULL, 
            0x99A142BBC33E481EULL, 0xC45E0F69724D6141ULL, 0x7BDE68D224140408ULL, 0xD8E78392F53835BAULL, 
            0x45A74E327567C8E2ULL, 0xA5C579DD7113A95FULL, 0xC5C065DC1D8FB1B7ULL, 0xA48841D297C5E591ULL, 
            0xD6CAE14D37831081ULL, 0x15AEF0BFA21E9852ULL, 0x0D02BC9F141630CBULL, 0x05E624EBFA27899CULL, 
            0x2EBD19C2C36588C2ULL, 0x2B7CE96151B4D188ULL, 0xB83CF7E2B0C23406ULL, 0x15C59F4100774E86ULL, 
            0x3CB2EA9158C10E24ULL, 0x4D634AF433399BF8ULL, 0x8B681E3DC1AE200AULL, 0xD0E961E616D25088ULL, 
            0xA7AC099A2D711C44ULL, 0xA9A632603FF3FDEAULL, 0xBBA1531A2F787D3AULL, 0xCF730C4EAF956539ULL, 
            0xCE3BC048EC01BCCFULL, 0x8997DE11F56C13CDULL, 0x4240AA5D358B43BCULL, 0xEC571409265449F7ULL
        },
        {
            0x4E62DBD47D191E91ULL, 0xFC6368736B7688E3ULL, 0x0F12A2D6F47C83A6ULL, 0x593AB38B87024068ULL, 
            0x5CAA7CED1510F074ULL, 0x51B19AED97268AFFULL, 0x6B10E1DB85FD46F0ULL, 0xC7AF2CAE279E78CBULL, 
            0xDE8CBDCC74FB4F67ULL, 0x88022D86E1C0E984ULL, 0x6E476669E4D72EC6ULL, 0x2413C3D1FE38319FULL, 
            0x1FCBF69A81582ED2ULL, 0x8416D826820CFA98ULL, 0x917271B424834C99ULL, 0x92382563505CFE0CULL, 
            0x9840C8521ADFFCF8ULL, 0xB4CCAA9F8D631516ULL, 0xB5EB7CFD1131246BULL, 0xCF4072F69B7487AAULL, 
            0x175761E86A2B9B98ULL, 0xD21A31DE082FBC6CULL, 0xE3DBD3ED789A9DA1ULL, 0x98DAFBF3BC09CA45ULL, 
            0x9BBEFEB79C1FC9B4ULL, 0x9FF175CA1AEAF3BAULL, 0xCDB50EF51619AC64ULL, 0xE9D26864EBB3D342ULL, 
            0x42CBBE21CB0884E0ULL, 0x3441C657E2E7FCC5ULL, 0x3D8392639F1F96B9ULL, 0xBCC83BBC14EE1338ULL
        },
        {
            0xB65421FDFCA74D8AULL, 0x4E95097FAEA16A77ULL, 0xD98C156E41871890ULL, 0xA802958558339065ULL, 
            0x5BF96C0403A2F201ULL, 0x380E75D525A8DDE4ULL, 0x8D71838EE2C5A38AULL, 0xD7FA2AE3CA7BE4FFULL, 
            0x1C1A1629456536DFULL, 0xD6D768C9C0E7123DULL, 0x59A632DDE16EFF15ULL, 0x93B9A78FCAD88AEEULL, 
            0x58FDFF6E02C9F92CULL, 0xDBBBC3CA3F233370ULL, 0x62F12886E9D7C769ULL, 0x90B98357477A1F8AULL, 
            0x0496D5EF72066240ULL, 0xFBED5181BBBABF95ULL, 0xD3BF46D6C17ACFDFULL, 0x6416EA43176550DCULL, 
            0xA75B1CAFCEDD66DBULL, 0x5A09BD61F372CE5FULL, 0x60D8F8F60776F56DULL, 0xEFD2D5CCF5025202ULL, 
            0x943FB115EB9B0E7DULL, 0x26B306A861DF309BULL, 0xD0CE485F57C71022ULL, 0x3015527624A60039ULL, 
            0x08AE5A5F22706947ULL, 0x37579CA965D20A8EULL, 0x22DDDA62D4366E4AULL, 0x229CA45A219C28EDULL
        },
        {
            0xFE23C9CCCCD95DD5ULL, 0x3B6D5CD06B61D398ULL, 0xCAF41721618A68F5ULL, 0x29811F7F80FCBAF6ULL, 
            0xB8319B359AAB96FCULL, 0x9CD9200AFA35BBA0ULL, 0x50C16CD771E96BA2ULL, 0xFA3C91FADACFEA6EULL, 
            0x0332910B57FFE5B7ULL, 0xF5CC71D06B816B2FULL, 0xFA5A31CB3C9828E2ULL, 0x3088DE03D2EFB3FBULL, 
            0x23473277E905E1A5ULL, 0xBAB58C3977E2AFBCULL, 0xA8241D84F216E48FULL, 0x7325876B94147EBEULL, 
            0x3C56E9A201FD187BULL, 0x1AB023B39E1D305AULL, 0xEB3B2763F08EF1B6ULL, 0x1816796CBB1B9A70ULL, 
            0x3660CD260A4EDC3AULL, 0xEC41B75ACD7F4E63ULL, 0xA61E0641D893ADF7ULL, 0x839D51FB0D0E82CBULL, 
            0x199645F80ABB39B2ULL, 0x8B40CF457284530FULL, 0x82CEEF2B01294A9FULL, 0x074CEB83AA65313DULL, 
            0x0ECDB3FE4B55EAF3ULL, 0xAB8ADD3FD5236A38ULL, 0x80E36D82EA0FA717ULL, 0x9FF8B9A2F59B30E8ULL
        }
    },
    {
        {
            0x8ACAA63A712B6B89ULL, 0xD9B2231B8EA56B71ULL, 0x7FEB793A2810B77AULL, 0x37C3D4D73F5D2F8CULL, 
            0x770C91223CB118D7ULL, 0x1C050AB031E3EE62ULL, 0xB0D0CAB52D329F46ULL, 0xEC2FA24F8A6716CAULL, 
            0x8F7AD9C82C0C4312ULL, 0x170E083037462BE9ULL, 0x275B4319A579ED70ULL, 0x7EE66995A27A5268ULL, 
            0xF868B81259ED3CA7ULL, 0x35744346A01EF0E8ULL, 0x1478EDC9A2DA3917ULL, 0x10A370D1DBA95BA6ULL, 
            0x7E507A154C13EA3EULL, 0x39B0313BA96EC1FEULL, 0x565DDCA7E68F4184ULL, 0x0D8777D424431AD7ULL, 
            0x22F584F71EB09B74ULL, 0x457C369806492299ULL, 0xA37B8FAFAE782DADULL, 0x33A4013F694D90EAULL, 
            0x398D37B503917246ULL, 0x2AE5481E9C8AAE2CULL, 0x959FA99EF787A72CULL, 0x26A07BFE8953763AULL, 
            0x3F3226E32380346CULL, 0xE6AD01803487E8BCULL, 0x7C20A40C054AD689ULL, 0x9C005C062AB0EC75ULL
        },
        {
            0x841B7741F64268C7ULL, 0x1FF63F1D4E64E4D2ULL, 0x40D9824BFAF8C5B4ULL, 0xE574B826CF5E942EULL, 
            0x115FD95B3C73C2B9ULL, 0x0DC43D42C4FBE610ULL, 0xC68D27822DB133FFULL, 0x8F97E79E62AE1B3DULL, 
            0x3627CE60DCA19553ULL, 0xF2569229F69745F3ULL, 0xA04C0F17F54EE7F4ULL, 0xDC9E828BE76A07A1ULL, 
            0x25FDF84253695F74ULL, 0xB960F8D107ACE708ULL, 0x5BD8D3C8290B7EB1ULL, 0xF6A31268B3F95CB8ULL, 
            0xDD9F933DEF81DD32ULL, 0xAA890196C1BCDCC1ULL, 0x5ACEA382619ECD57ULL, 0xEE09E5621C981078ULL, 
            0xF6AD41685BBD106EULL, 0xF67331C35E0E6CDBULL, 0xC612031611E8E88AULL, 0x24A0FDE4FFFD9C2BULL, 
            0xF0D58DADC8BB003EULL, 0xDD0B163AF0564ED7ULL, 0xF214503A5D4E8238ULL, 0xF7B3EDD357BF65B8ULL, 
            0x5C29B0D167073120ULL, 0x30CA6141F147FA55ULL, 0xFE7FB51677454413ULL, 0x94F479791724EE3BULL
        },
        {
            0xB63E92771C7B0453ULL, 0x88B586F912BC854AULL, 0xF4DE47CA533FED2CULL, 0x155FFE63C4DAE50FULL, 
            0x7D7213E2F8AB300BULL, 0xE8B5A181DF7429C0ULL, 0xEE1AD47DCDBE64C3ULL, 0x7368074120F9D15BULL, 
            0xFC4333741C6EE04AULL, 0xC544126DB7E1E2DEULL, 0x7131A7B5B198B984ULL, 0xBB3FAD874186C518ULL, 
            0x8C19F299A5DD6A1FULL, 0xA3C557453ED3F47CULL, 0xB62ED5301BE89775ULL, 0x94A33C2C53793227ULL, 
            0x6EB492B4EF6350C2ULL, 0x4D3284149A583AC4ULL, 0x46EBE324AE704DA8ULL, 0x9BC07C850135905DULL, 
            0xFB73604F70C961C3ULL, 0x10424836F4B40B07ULL, 0x4A1D73C8AB831B3CULL, 0x9769CA46F349778DULL, 
            0xDBEAC359CA02614AULL, 0xEF983DA0873ED615ULL, 0xABAA7E7AC327771AULL, 0xAF47CF5AC3F05888ULL, 
            0xB54941FCC0E87B97ULL, 0xE834565EF722B276ULL, 0x89D338A4C2FB1DBBULL, 0xFAB3001A36408E7CULL
        },
        {
            0x038637B9D612A56EULL, 0x2E7DC8FA06765905ULL, 0x8018AB8D2FE880D9ULL, 0x9E5B1BA0CF66427BULL, 
            0x05713D68913BA411ULL, 0xABCED4CB082237A1ULL, 0x3D2524ED032B1604ULL, 0x19F01093FC9C0DD8ULL, 
            0x9E5FA425D63E921AULL, 0xFAED777CCBFE769BULL, 0x1713025DFCDF113DULL, 0x0AC63B8CC4B75BA6ULL, 
            0x0BFEBCF157377D64ULL, 0xF33EA4F77324815DULL, 0x2C12D4D9007840BBULL, 0x2E19705976511E11ULL, 
            0x71C129737BCA1982ULL, 0x577CE609732EF584ULL, 0x4E8341CAB55D5BF9ULL, 0x9BA18BD8C88FCCFAULL, 
            0x1C345EC400E77510ULL, 0x7BA0D2A4F6C83677ULL, 0xE5C067723A4D6571ULL, 0xDD7C17A24F1815BAULL, 
            0x0B91D349F6DAF3EFULL, 0x6EEB983735BC2054ULL, 0xD200A3E7D145E2C5ULL, 0x8638CD74FD8FCB0FULL, 
            0xA1AADBC7B5360C98ULL, 0xF4F0703E1C976BE0ULL, 0xF4B88D73851AF2DAULL, 0xF7E59F08449851F7ULL
        },
        {
            0x40CF87C0690FCF4DULL, 0x8C228F9EE3B74E68ULL, 0x450F7ADFBEF8287EULL, 0x45A71FD1CB03EACCULL, 
            0x8577EB1877F78753ULL, 0xAB154E21479EF15BULL, 0x3B110BAF49FC709EULL, 0xC78C9A4663AC18E9ULL, 
            0xCE24829FF484F117ULL, 0xC0F44D04A8DDC7E0ULL, 0x6C72F7A892334F1BULL, 0x02D041E61F753B08ULL, 
            0xAF887EBAA8E4BDF6ULL, 0x1DCA5FE1FAFBA609ULL, 0xD6F88B1CCCA5C747ULL, 0x4127659785B65E66ULL, 
            0x95A1303FB9ABD8D8ULL, 0x77C326BECA6A17BBULL, 0x851029252236AAFAULL, 0x08B5609EDC4CF25EULL, 
            0x79D914791363FDCFULL, 0xBFB4BF3A9833889BULL, 0x8E3F28CB15777A5AULL, 0x217E1E3721964460ULL, 
            0xFCD0E60887A3B22DULL, 0xCBC6F896235550B5ULL, 0xAC4C5B915A6AA1D2ULL, 0x86AF1FFF405241B7ULL, 
            0x1B19A5F7FF6EFB91ULL, 0xFB74839B7E23E991ULL, 0x89EDE6B83F744A82ULL, 0x59FD1ABB97F16B83ULL
        },
        {
            0x59BCAF8373756489ULL, 0x2100A1692E32AA86ULL, 0x10D15D8C588E07A4ULL, 0x3A96DF0FDE4B86A5ULL, 
            0x2B5AAE56A000FD7CULL, 0xB3591EDE5BB34A29ULL, 0x1EB2A357C89935DBULL, 0x68417F15F42A83BCULL, 
            0x3846318DE9A42134ULL, 0x67876329432A0912ULL, 0xB2A9EEAC9B8E97A6ULL, 0xB6A1F2F42EB82356ULL, 
            0x0A42A49E29B9DE70ULL, 0xF400FB4AF67C7417ULL, 0x5A6EE1DE215CDF12ULL, 0x65858EA4B1C61C70ULL, 
            0x066FA4BE9AB1D1C7ULL, 0x669FE3013723C2F9ULL, 0xD430B041BA958D61ULL, 0xC438B3EB46AA89A0ULL, 
            0x222DEAC7B964701BULL, 0x47F7AC4BFEFDBBEEULL, 0x8745BD0B856E6897ULL, 0x80B92FCD5ED02B7EULL, 
            0xDF3C6CC77D95FBE1ULL, 0xDE3765229AAEE7DCULL, 0xEB899ACD5DFEEACEULL, 0x0E5647B63E8977BEULL, 
            0x7A26669F84F045D3ULL, 0x1AB0E52CBD2F845FULL, 0x97F4CE22EFE4A02AULL, 0xE6520E5008183AE4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kTwistConstants = {
    0xF9A15EB8C9604A01ULL,
    0xBD5F69B1BC74E653ULL,
    0x13E98B99DBAB054FULL,
    0xF9A15EB8C9604A01ULL,
    0xBD5F69B1BC74E653ULL,
    0x13E98B99DBAB054FULL,
    0x300B3ABA8BB0D588ULL,
    0x90006D9A0E58E0BDULL,
    0x2C,
    0x84,
    0x15,
    0x12,
    0x07,
    0x18,
    0x73,
    0x09
};

