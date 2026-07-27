#include "TwistExpander_Gemma.hpp"
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

TwistExpander_Gemma::TwistExpander_Gemma()
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

void TwistExpander_Gemma::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB907FD64487A316FULL; std::uint64_t aIngress = 0x8D1B24B1845F775BULL; std::uint64_t aCarry = 0xFA57521631E1A3BAULL;

    std::uint64_t aWandererA = 0x97D8DEF27CEBA53AULL; std::uint64_t aWandererB = 0x95CFA1573F2D8B52ULL; std::uint64_t aWandererC = 0xD24C31C36B45C28EULL; std::uint64_t aWandererD = 0x81E5717A28CDC1F4ULL;
    std::uint64_t aWandererE = 0xD44F1A803954D360ULL; std::uint64_t aWandererF = 0x898A6986BF53873FULL; std::uint64_t aWandererG = 0xD9606F20C2C26F9CULL; std::uint64_t aWandererH = 0xB386192B3EE32CCAULL;
    std::uint64_t aWandererI = 0xF35105718ED22C59ULL; std::uint64_t aWandererJ = 0xE83A2176BC89A8E0ULL; std::uint64_t aWandererK = 0xCF93B7AFE82FE886ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x891B448CD4FCFE47ULL;
        aCarry = 0xDA35948B86098484ULL;
        aWandererA = 0xE3D820527EC70AFEULL;
        aWandererB = 0x97503712CB8A0E44ULL;
        aWandererC = 0xE6BEF3D29239D956ULL;
        aWandererD = 0xA3454DA6E17970BAULL;
        aWandererE = 0x8C90518551B222CEULL;
        aWandererF = 0x907E58C793864194ULL;
        aWandererG = 0x8C1825A3780F97C4ULL;
        aWandererH = 0xB19C4ED473C14909ULL;
        aWandererI = 0xF20307E4167FC425ULL;
        aWandererJ = 0x99365ED6502494FEULL;
        aWandererK = 0xB89097D5C66697A5ULL;
    TwistExpander_Gemma_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x91FB09415557EB7FULL; std::uint64_t aIngress = 0x8F967BE116289D7EULL; std::uint64_t aCarry = 0xA6C4D97EE5F0CA2EULL;

    std::uint64_t aWandererA = 0xB68D82631393FE7FULL; std::uint64_t aWandererB = 0xDDFBDAAD5D2EB782ULL; std::uint64_t aWandererC = 0xDD692CC20309A7FEULL; std::uint64_t aWandererD = 0x8B457D7B5D7172C9ULL;
    std::uint64_t aWandererE = 0x9FFC46410E28317BULL; std::uint64_t aWandererF = 0xF0624FF3B2C103A2ULL; std::uint64_t aWandererG = 0x87D75A5E5939CF4AULL; std::uint64_t aWandererH = 0xDB163CC7198BB37CULL;
    std::uint64_t aWandererI = 0x95616D99F9FBB048ULL; std::uint64_t aWandererJ = 0x997046F03FD14C5EULL; std::uint64_t aWandererK = 0xB75FF0B54D40E94FULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC766C11883283939ULL;
        aCarry = 0x94B926F30C6E4B39ULL;
        aWandererA = 0xCD37F45FC67238C8ULL;
        aWandererB = 0x973F33F10C2F8877ULL;
        aWandererC = 0x95AADBAD7F924E52ULL;
        aWandererD = 0xECEE159D8067BABEULL;
        aWandererE = 0x843DE8AF0D902831ULL;
        aWandererF = 0xD9ACD62BF6424A12ULL;
        aWandererG = 0xBD5512D1DED70061ULL;
        aWandererH = 0x8DFE68ED52CED394ULL;
        aWandererI = 0xF3EF290F003FAEA9ULL;
        aWandererJ = 0x8CEE00D4228E44E3ULL;
        aWandererK = 0xC3799744FFF1999FULL;
    TwistExpander_Gemma_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF3FD94C37CEEDF0DULL; std::uint64_t aIngress = 0xAD74F36DFED3FCF2ULL; std::uint64_t aCarry = 0xEACE974B6EDBBEE5ULL;

    std::uint64_t aWandererA = 0xC22995C8508E4D45ULL; std::uint64_t aWandererB = 0xF13BA01C563D11E4ULL; std::uint64_t aWandererC = 0xDF268B9F094A4A72ULL; std::uint64_t aWandererD = 0xBCAC51E727A5EE9DULL;
    std::uint64_t aWandererE = 0xF471F4B89D2DA21CULL; std::uint64_t aWandererF = 0xF79793A065135356ULL; std::uint64_t aWandererG = 0xBC71A636731D812AULL; std::uint64_t aWandererH = 0xBD24ACFB6D8AC83CULL;
    std::uint64_t aWandererI = 0xF984AB50BB3F3EF5ULL; std::uint64_t aWandererJ = 0xC5F81BE9410937E5ULL; std::uint64_t aWandererK = 0xAB098711C2AFDC14ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x988D8117EF754B76ULL;
        aCarry = 0xCE22FCDAAB365B79ULL;
        aWandererA = 0xB40C5252AD1B9331ULL;
        aWandererB = 0xC5D3996606A7D918ULL;
        aWandererC = 0x8267FD0563BCB801ULL;
        aWandererD = 0xA27FFAC63EC13309ULL;
        aWandererE = 0x81C3616EADD4211FULL;
        aWandererF = 0xC621DDF567750176ULL;
        aWandererG = 0x80E1CC710D1628E3ULL;
        aWandererH = 0xB0075C89AC56A964ULL;
        aWandererI = 0xA39C561E87CF362FULL;
        aWandererJ = 0xA034BF39B7BF4F48ULL;
        aWandererK = 0xE2E174A8BF38CAAFULL;
    TwistExpander_Gemma_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFF3542F7C4C7B785ULL; std::uint64_t aIngress = 0xADE137873062FAC5ULL; std::uint64_t aCarry = 0xD00C537F78F9774CULL;

    std::uint64_t aWandererA = 0xCDA7D7449BC4A1B3ULL; std::uint64_t aWandererB = 0xD1C36C1E68F726A9ULL; std::uint64_t aWandererC = 0xDE3EC685E0416373ULL; std::uint64_t aWandererD = 0xA5AE0CCEB5045A91ULL;
    std::uint64_t aWandererE = 0x9535893908A67437ULL; std::uint64_t aWandererF = 0xA6E49AD4F895FEB8ULL; std::uint64_t aWandererG = 0x9029408ACCB72D64ULL; std::uint64_t aWandererH = 0xE83C935BA6C34BFAULL;
    std::uint64_t aWandererI = 0xC05963B88488CEBCULL; std::uint64_t aWandererJ = 0x822E30DDC7FCE94CULL; std::uint64_t aWandererK = 0xF8735F2F3162B05BULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD7B8C89E067870A4ULL;
        aCarry = 0xDB176E1F61BAD063ULL;
        aWandererA = 0xBD66CDA30955E90DULL;
        aWandererB = 0xB6EDFB3B91B00107ULL;
        aWandererC = 0xE9AC839AD3878E4EULL;
        aWandererD = 0xE5C62678354422A6ULL;
        aWandererE = 0xAC7B6EC8016458CEULL;
        aWandererF = 0xD9284ACE27F05B68ULL;
        aWandererG = 0xF7BCE37DBC661265ULL;
        aWandererH = 0x937EA16599C84AF3ULL;
        aWandererI = 0xB46423EBFFB1664CULL;
        aWandererJ = 0xF6C99AB0C523BC79ULL;
        aWandererK = 0x9CECA285554E5537ULL;
    TwistExpander_Gemma_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Gemma::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8CD34749BFB7C0D0ULL;
    std::uint64_t aIngress = 0xFDD8D23F7AF9988BULL;
    std::uint64_t aCarry = 0xF9FC9B6DBB67C80CULL;

    std::uint64_t aWandererA = 0xA90E5C3B4EAFD4C4ULL;
    std::uint64_t aWandererB = 0x8A7E029367B1FF88ULL;
    std::uint64_t aWandererC = 0xA979055567EF413FULL;
    std::uint64_t aWandererD = 0xDE507D03DBB00471ULL;
    std::uint64_t aWandererE = 0xF2221A46E2912F1FULL;
    std::uint64_t aWandererF = 0xE666F87A4DA87E0BULL;
    std::uint64_t aWandererG = 0xED05AC658062B064ULL;
    std::uint64_t aWandererH = 0xF01F607198D22856ULL;
    std::uint64_t aWandererI = 0xDC4963BBC4CBE23BULL;
    std::uint64_t aWandererJ = 0xD12B7EFE9BC022D7ULL;
    std::uint64_t aWandererK = 0xDB9DADD5C783234DULL;

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
    TwistExpander_Gemma_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KEY(pWorkSpace,
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

void TwistExpander_Gemma::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8200E05C6D15947DULL; std::uint64_t aIngress = 0xE795EC3A03565885ULL; std::uint64_t aCarry = 0x822D6F3A05DF1A17ULL;

    std::uint64_t aWandererA = 0xF4D2FB15A1720744ULL; std::uint64_t aWandererB = 0xB617B7A81F72C6F4ULL; std::uint64_t aWandererC = 0xCC6868A4A5C5C31FULL; std::uint64_t aWandererD = 0xB5F691AF52A11D71ULL;
    std::uint64_t aWandererE = 0xD3F52B0B857B774EULL; std::uint64_t aWandererF = 0x95959372C8A9AFB6ULL; std::uint64_t aWandererG = 0xB65C7C0D755C9C08ULL; std::uint64_t aWandererH = 0xB6AE5CA55C4F8E5CULL;
    std::uint64_t aWandererI = 0xC7231EB4C3E39ABEULL; std::uint64_t aWandererJ = 0xC5A457EE6267368DULL; std::uint64_t aWandererK = 0xF8EA71462E5DAC90ULL;

    // [twist]
        aPrevious = 0xAFAE9B03BDE13EB3ULL;
        aCarry = 0xE2A6844FDFA5CEA6ULL;
        aWandererA = 0x9E14C3D16F587895ULL;
        aWandererB = 0x94B7CDDE22AB3F28ULL;
        aWandererC = 0xBE85666AB50E3739ULL;
        aWandererD = 0xC22481832EFE4D19ULL;
        aWandererE = 0xBB6BC8D0A889D472ULL;
        aWandererF = 0x80112086BAA19299ULL;
        aWandererG = 0xE16F37BE6127E57BULL;
        aWandererH = 0xE9D5BF58C67ED277ULL;
        aWandererI = 0xA3F082B7BFD865D7ULL;
        aWandererJ = 0xAE2026409CABAECCULL;
        aWandererK = 0xC31DD29FD50803C6ULL;
    TwistExpander_Gemma_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Gemma_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Gemma_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Gemma::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Gemma::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Gemma::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 28 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 14384
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1510U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 28 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 14318
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1150U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 28 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1045 / 1248; total 28950
void TwistExpander_Gemma::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
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
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 28 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1046 / 1248; total 28966
void TwistExpander_Gemma::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 656U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
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
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1849U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Gemma::kKeyRotateSalts = {
    {
        {
            0x8BD505676ECE56F3ULL, 0x43A13741220AE295ULL, 0xA45F46686D0228E8ULL, 0xCE04387E92A76FE6ULL, 
            0xE4B8A28257E4550EULL, 0x3E71D085FB2D1D6BULL, 0x13CFE9FE627D9E04ULL, 0x56724F9F50DDA1CDULL, 
            0x25A571B4B388F808ULL, 0x8149EFF33984C0DCULL, 0x3A94A678F0551446ULL, 0x59CC3575327C5BB2ULL, 
            0xFC08E47F44218662ULL, 0x676B98AAC9FBEE23ULL, 0xFE6531EC3E25E759ULL, 0x897CCE4E41A41952ULL, 
            0x78EFC2BD6431855EULL, 0x2DDA327682473D22ULL, 0x3502EA1136CBF38AULL, 0x9CA3021AB5316B8EULL, 
            0xE482663CA5868F28ULL, 0x0A1EACBB3DD185A1ULL, 0x304CBC649920A037ULL, 0x025A287A3B6BBF4BULL, 
            0xECF15F0793F9D308ULL, 0x5620631FF2027582ULL, 0x40AE2CD114A67D04ULL, 0x4CD7B72D74C8ABF1ULL, 
            0xCB23072685F8CD4BULL, 0x598680B911CDE176ULL, 0x6A8375103CBD73C9ULL, 0x62AF7D7C9EB8525FULL
        },
        {
            0xAFCB36922C55E6E5ULL, 0xE5D56A3ED90C1D4CULL, 0x1D6EA2896A4E1D4FULL, 0xBFB511CBB1337E52ULL, 
            0xECDC1E85DFF3D176ULL, 0xCA757029B6BDF910ULL, 0x962B3D5637233971ULL, 0x94AE8CAE03868571ULL, 
            0xD141A0A50AAC8ADEULL, 0x449494BA634A1397ULL, 0x933758DBF392FE15ULL, 0x2C42CC8CBC427C91ULL, 
            0x7A16FB808D51FE2FULL, 0x6FFC321094F0CE56ULL, 0xCF018FD6B77A61D6ULL, 0xD334F0ED4410F6D0ULL, 
            0x91C14F1B10E374C1ULL, 0x4F9195BC40FDA25DULL, 0x9488EFFB0CFA9AAEULL, 0x1B116F56C8363B8AULL, 
            0x266D45B66B5589C5ULL, 0xA2A8DAB14451AFDEULL, 0x33B9F25809904995ULL, 0x3A9499174EB4B952ULL, 
            0x3EF45A64574A31AEULL, 0x34A67DC551A845D4ULL, 0x9564EDF34D3C2CAEULL, 0x687750068B42D346ULL, 
            0x5E96FEC4DBF38F3FULL, 0xA84B14374D0F8E98ULL, 0xD733B8395888393EULL, 0x140691C381B98ED9ULL
        },
        {
            0xD66C362C2DD37611ULL, 0x0624D7317D6E33BEULL, 0x91291C87C5E1DBCDULL, 0xF718D651A4611625ULL, 
            0xF34F9D2445882D44ULL, 0x18E57A8758E7C343ULL, 0xBDA508245E64BC29ULL, 0xC61CA030E238A263ULL, 
            0x26FAEBB20BC282FAULL, 0x0C964DE521115ED8ULL, 0x2688F3FF1E846562ULL, 0x94FD4CB86771DB02ULL, 
            0x3DF6F7D00420FC11ULL, 0x2B8B5C1AFC9F7F5BULL, 0x3F7CE9132105E9A2ULL, 0x5E21835D3C76FE5AULL, 
            0xB1095712975F5A78ULL, 0x5E5295CA7F405016ULL, 0x7C1C6BEC0D4C56CEULL, 0x2F00F65AE1A330CAULL, 
            0x0D9630DB86223E2AULL, 0x4E37B5D3A05BD3E9ULL, 0x0A99FCA5ED33A5E9ULL, 0xA006C9A68BF56FDBULL, 
            0x2261ABC947E8514FULL, 0x902F8E04F5AD7552ULL, 0x50D97FB7F93C8877ULL, 0x0C360BC84E62CA9AULL, 
            0xC268B6199CDA0B5DULL, 0x980098ACE02A7AD3ULL, 0x9C57AF4CBAAA41A2ULL, 0xE1067178EFDE40FCULL
        },
        {
            0x191C8C58D402D56FULL, 0x09745E755C73B27FULL, 0x45D4F1E7924E470EULL, 0xFEDA7A168696F574ULL, 
            0x2A1A945DB8D8CFF9ULL, 0x5C1E44F17C646917ULL, 0xE387AA4A7105F6D2ULL, 0xA9DF10711DED2F62ULL, 
            0xF7F03DD223867503ULL, 0x024184076397365CULL, 0xAFD5B44103DBB158ULL, 0x92AE3C7491374787ULL, 
            0x441902081C42576AULL, 0x5A817B8E68913840ULL, 0x8EF81F951469AE92ULL, 0x4121443B354058B3ULL, 
            0xD078F3DCD0DCE12FULL, 0x27B170861AA6EC83ULL, 0x51EC27F363E055FFULL, 0xBB1C1035D35F36BFULL, 
            0xBD8889A8A1B278C4ULL, 0x90D94424AAA0A852ULL, 0xF5CFECAF52014E54ULL, 0x743B47F1151295DEULL, 
            0x80CA1D870340C447ULL, 0x197BD11BFBF3F2DCULL, 0x9333AF0A6B991970ULL, 0xE5ED33FF85D333A0ULL, 
            0x35930908D5857CD5ULL, 0x2DA06FBA00BBB014ULL, 0x76181CC16015DC24ULL, 0x748010BA7D5BEC7AULL
        },
        {
            0x7FA37EF95F109A3AULL, 0x12237A5DA94E332EULL, 0x8E309BC3DE676C19ULL, 0xD4E0C65AB66A5A04ULL, 
            0x22419A8F87D63DBEULL, 0x3A09DB1242B66FA5ULL, 0xEBECAED8C937D909ULL, 0xC5B164FDC36A5FECULL, 
            0x48FAB11B641CBA3FULL, 0x762756F3E7739DB3ULL, 0xB61024EE3CA264B6ULL, 0x2D1F13683F1A83CDULL, 
            0xC0A290DA19A8ADC0ULL, 0x40541D05D23A14F6ULL, 0x10081DB702BC5813ULL, 0x4EAC90A683E4C7E9ULL, 
            0x337D126C3F64197BULL, 0xED4EDE24C24B798BULL, 0x4FDE82E09FAC56D5ULL, 0xA4C0C7D59BB1BAF5ULL, 
            0xA3A909EDABB03484ULL, 0x03B7F1CAB0658FDBULL, 0x275C169AB2F28FBBULL, 0x6254EF8C92CEA88EULL, 
            0x094B9416C4D63186ULL, 0xB71C6B1D0CD7C64CULL, 0xF65020BE610B349EULL, 0xD0BD25E877C59972ULL, 
            0xB69DC96BE76DFCA2ULL, 0x85024793F3637E99ULL, 0x7DB8529A9D91144BULL, 0x5F595EFC4A937F5CULL
        },
        {
            0x0BD54A67D324E70FULL, 0x2835AE376567BC88ULL, 0x6F8873B81D41CB5EULL, 0xD338A5A633D3D7B0ULL, 
            0x355C1DD18E5C37DCULL, 0xE15F0232F7EBA966ULL, 0x90112C881D8C8249ULL, 0x4FF01467ACFFA7D0ULL, 
            0x6847755B642D8F7EULL, 0xA362623C0F7DE11BULL, 0x29EFAB2EE3B7601EULL, 0xFC884F586F8340D0ULL, 
            0x2C9622B4C318AD6CULL, 0x86D7279DECBD3198ULL, 0xBBCA4A485FDEC532ULL, 0x9316BC1797E0CEDBULL, 
            0xAA441620220CE3B6ULL, 0xE58CCB400A852D33ULL, 0x5AC5C7E00E364E33ULL, 0x4A3BFE9C90B7CD70ULL, 
            0x8C92D011D23F5469ULL, 0xE15A9434DCABA8E2ULL, 0xA2C917375B1DEB43ULL, 0x65D3954AFB9C0C47ULL, 
            0x2EAF1DD92A7BA21BULL, 0xB46FF79E6D455629ULL, 0xC240797E3DFF94EBULL, 0x2FF25229F233621EULL, 
            0x6CADC866504F15E0ULL, 0x88E04F0E5AFDBA32ULL, 0x24D4931B70C96C6AULL, 0xFD78EBC6F70BC2D7ULL
        }
    },
    {
        {
            0xCBF0AB96035CDEA0ULL, 0x4A6531738D631F19ULL, 0xE3298E30C8300AA6ULL, 0xEAF3874009FD0442ULL, 
            0xBF7837A05F2256D3ULL, 0x6383B65D742D042CULL, 0x24ECC3F3D1C2AB18ULL, 0x35A251997E759F03ULL, 
            0x10F76DBE176C807FULL, 0xC9FB345A076A4D3AULL, 0xBA28C487942B2083ULL, 0x73F06A228762B68BULL, 
            0x7BAB850326B73ED0ULL, 0x0AEB63F45544883BULL, 0x3F0173066E2D0A52ULL, 0xE9B01D644AF9604DULL, 
            0x46CA14478D1A514CULL, 0x7E6D28FB1B879A3FULL, 0x6A1DE2A5DE9B3EF5ULL, 0x7AB6236A95ED788FULL, 
            0xA234A0C8F26A4C2CULL, 0x7E48681F3295E3E0ULL, 0xA17860E79811ED54ULL, 0x75800F52E92304B0ULL, 
            0xC47A6EF724F1E400ULL, 0xEFEBEADF5F0B81CBULL, 0x71C4E0CC31261AFEULL, 0x8E71C81F4C3E56FDULL, 
            0x5DBBC10D02BCD2AAULL, 0xB9A3F754760751A9ULL, 0x1D7701A0D1798296ULL, 0x3D643292CE3B8117ULL
        },
        {
            0x915DB98FC653357FULL, 0x2E6969D55E1D3DA5ULL, 0x0C5813C6626BED35ULL, 0x19808F295234C921ULL, 
            0x7648B05E2E7F7018ULL, 0x093C577BCB856596ULL, 0x63A563E35C0834AEULL, 0x30D6057645095FECULL, 
            0x8033C63ECE427E56ULL, 0x8348197A945A104CULL, 0x410E0070EED11250ULL, 0xF311864EB2CBF94BULL, 
            0xA3585B76EB8C76DEULL, 0xA99E5D21E7619AE0ULL, 0xA9B733E085E2537CULL, 0xA06B7B6B9F310631ULL, 
            0xD6AA65ED2DADF70AULL, 0x127DC186F2AD1763ULL, 0xEBECD4CFF5FF9574ULL, 0x5BC9E750D302B691ULL, 
            0x04203775C5C6E8EBULL, 0x717D3E4E6B5B1BBEULL, 0x81F3D52FD6B846F8ULL, 0x29806A66D93CC7D7ULL, 
            0x67B7DEAD79E442ACULL, 0xD28D96D46CD5753CULL, 0x1962CD39AE653E10ULL, 0x45E2123AF037E93EULL, 
            0x9502E9DD1ED123E6ULL, 0xDFBC22327AAF8586ULL, 0x9E43489998B714FDULL, 0xA06CD2506FB3E41CULL
        },
        {
            0x01513A1FD17F6385ULL, 0xB870E27D4FF58AD1ULL, 0xEEBBB42C72EE9361ULL, 0x41246514EDAD289CULL, 
            0x1CC906915CB5D4D5ULL, 0xAC36F3C3ECC0DD26ULL, 0xB7675046713EF991ULL, 0x91F385E8E0942BECULL, 
            0x94D8465C86D92DD3ULL, 0x9FC64196792A7750ULL, 0x8405C75422220D8DULL, 0x36DB6B1578D01647ULL, 
            0x2BC823550946FA6BULL, 0x874C1D78A922B0B1ULL, 0x90199743C884B4C6ULL, 0xE940D00598BFD653ULL, 
            0xD9EDEE056185A580ULL, 0xEA7E690625AA184FULL, 0x7B38C31524BA2791ULL, 0x7DD06331890A4F1FULL, 
            0x110EBB1B9056A6D3ULL, 0x6281BE78844A82F5ULL, 0x0F81F7B183863126ULL, 0x5F562BFF58DF89FEULL, 
            0x1FF441738C29B812ULL, 0xD028560AF32C37CAULL, 0x4DBE220D68CC396FULL, 0xB9052658A0952133ULL, 
            0x6483253541995CB3ULL, 0xF029373C372601CCULL, 0xC3CAFC344069FA0FULL, 0x25DE9F3865C68392ULL
        },
        {
            0x3C2594BFE6A22270ULL, 0x25CE4C37C5822973ULL, 0x9EAB1E67BA180F1BULL, 0x1D65EA11B4F7CFBEULL, 
            0x4AF637199C36A563ULL, 0x7ABAC101790A5218ULL, 0x795EDB18BB3F5D6CULL, 0xC14A49D620AEB25FULL, 
            0x0E6B42474FEB96A5ULL, 0x67399030F0F4FBD4ULL, 0x332A251B2300E9C1ULL, 0x70C0179A10E7381DULL, 
            0x474F4A28ABF9D29DULL, 0x680E1CE13E6FC202ULL, 0x328AFB55A71E8C0BULL, 0x7CC186A415768A1BULL, 
            0x1CF6D9174C9852B4ULL, 0x302912695EF3B5EEULL, 0xDD909694FF1E3A8CULL, 0xE70623C630DD4220ULL, 
            0xEE315C05045B2DEBULL, 0x8904A79E1C8CC791ULL, 0x2A74F901F34AA1C5ULL, 0x71E6BEE0C42FF72EULL, 
            0x50D2B0050A70709AULL, 0x4C65A6B208B770A7ULL, 0xB99504E69A5F35D6ULL, 0x443F76C3C51CA6D6ULL, 
            0x528D8F463B885B8EULL, 0xDCF295D2DC495F87ULL, 0xFD41C8A37DB1BC5FULL, 0xA0A1CF3C6B229370ULL
        },
        {
            0xC722DDADB1727754ULL, 0x8E140D8D7DD50F9DULL, 0x1414B8D37EF641E1ULL, 0x4E851BD67B483229ULL, 
            0x54AD37BD11151513ULL, 0x748C68D7CB1A5D6EULL, 0xDDAEE9EEAC9A20B5ULL, 0x192EFB45C138DF30ULL, 
            0x7A6E9144D31C07D7ULL, 0xB8755BA349515B7DULL, 0xFEB07DB5FBEC7B22ULL, 0xBD94BFA79BC6F646ULL, 
            0xB0EEA655460D742EULL, 0x545339C2C510A55BULL, 0x4C4F470C23CE68BDULL, 0x254DE12FCFDD233BULL, 
            0x344013FBEBBB2BCEULL, 0xD465FBF06D863737ULL, 0xA2DC83CCA77C1910ULL, 0x62723CB60BD7D184ULL, 
            0xDB1E94D45185F3A9ULL, 0xF7C65077B46D0700ULL, 0xFAA712E6889D0D7DULL, 0x367685F5FC94DA0DULL, 
            0x1987FE1655077E87ULL, 0x9DD0DE86751016C4ULL, 0xA31941A16E96FC00ULL, 0xDB8E712856059E1FULL, 
            0xB6FB62C04C076F6BULL, 0x7E17F63271A79A50ULL, 0xE2BC85D6918B052FULL, 0x023E25B8B84768CBULL
        },
        {
            0x0C0E072472F350BCULL, 0x6631EA85D99C21FAULL, 0xB28EAC6930096973ULL, 0x1CC6064851E1E47DULL, 
            0xC5B536EC608C41DAULL, 0x21838FB68611C714ULL, 0x698983E94F829DF1ULL, 0xEAE12C118031FA7EULL, 
            0xD473BCF752FBCACDULL, 0x69118B68B512B048ULL, 0x65CED200BA78CD8DULL, 0xF86257F7E4166919ULL, 
            0x085343177C1881BBULL, 0xA52D478565632CDDULL, 0x015C3B01EBA4204BULL, 0x155AFD234FC185D4ULL, 
            0x3B60D04E8D4DE755ULL, 0x27A1E1634C47138FULL, 0x2BC09C913D8D1575ULL, 0x74FAC3FA0E845B4FULL, 
            0x42F43087E412A09CULL, 0x9F5BA92FE05CD425ULL, 0x1B1C98CDEAC06024ULL, 0xABAB2C0041D9E2C0ULL, 
            0x05442D5334E5B497ULL, 0xA28203C8653CB495ULL, 0xA79DBC8723B25E04ULL, 0xB7D56054A6E0A5C5ULL, 
            0x911837B103CFE860ULL, 0x1D0A88745D5AE13FULL, 0xBC321B4AD6C517A8ULL, 0x11BC7378C3894A50ULL
        }
    },
    {
        {
            0x055DF1015EF45E4BULL, 0x0C234F8A723C8533ULL, 0x763D0517AF942A6BULL, 0x9F6B6FC8130C526DULL, 
            0x2EE4082D16AA2678ULL, 0x323914D762F282F2ULL, 0x272A340D61963572ULL, 0xAA81E7AD735DFED2ULL, 
            0xE222924823AFB5D5ULL, 0xB6D966B6198EE20AULL, 0xEF498B774074D7AAULL, 0xC7F871AF4A088EAAULL, 
            0x0E4E4E508A69EFF0ULL, 0xFABD5D17E7A1BC6DULL, 0x8A0C527C7A509AECULL, 0xA1C3E95F131A5E22ULL, 
            0x5B1FB23AE7D9B625ULL, 0x5817D33AFAB05071ULL, 0x47C605994CB06FCAULL, 0x938B1024D83AA1BEULL, 
            0xAE33EBCAC910CFE8ULL, 0xC5616760E07B18F0ULL, 0x9D8BD393B6A5715BULL, 0x9C87112CC03F13D3ULL, 
            0x5B250A7F32C454A5ULL, 0x18600D05597AE597ULL, 0x31B9613D195026AEULL, 0x8867714FEE903659ULL, 
            0x54CCE1FACC1D922AULL, 0x1E11E2FB37B5A0E1ULL, 0xB6D6F1DC37DF0DB5ULL, 0xCB85DC2660C3FD33ULL
        },
        {
            0x30E61DDABA3D909BULL, 0x4F682D05C7BD9E7FULL, 0x3E55040826DC6127ULL, 0xBDF7BB76784D64CAULL, 
            0x81554C720232AD6CULL, 0x251C4E331F7C9DAEULL, 0x0CD59A22B8E5BA19ULL, 0x1D640B793857EF23ULL, 
            0x52858D470FA1DC15ULL, 0x97D4A918060F8324ULL, 0x855E439097B61ACAULL, 0xC176146B92E7CA5FULL, 
            0x24C6C7858F482B0AULL, 0x13EB04DB9ACA0DFBULL, 0x2242DF3D4A6A5E99ULL, 0xAB90E05A816D28CFULL, 
            0xF0E34864A4703EEEULL, 0xD2C3C5D16B118C92ULL, 0x1D13144446AF1330ULL, 0xF1E0911A24DB1CA4ULL, 
            0xEEEFD51E3ACA0491ULL, 0xAB6F9881DC7B553EULL, 0x962EF33979ED3C98ULL, 0x1AB709420C36B05AULL, 
            0xE7F63C4D9F225710ULL, 0x2B09A3EBB10AC8CEULL, 0x48BC9B8E6A3582C9ULL, 0x0279A2DF3671BA3CULL, 
            0x51C2758B9F354D66ULL, 0xAAF0359C1FA2A356ULL, 0xD6A285D29353E256ULL, 0xFCE57EFA354D22D4ULL
        },
        {
            0x266FD3FA29D96B00ULL, 0x57821827AF5B5E47ULL, 0xE084989887C027A3ULL, 0x4A48F7F2013493D8ULL, 
            0x6F33F7137E0E5B05ULL, 0x96ABCB6AC6D714AAULL, 0x00CE98EC4C3C58A7ULL, 0x64B5E4FA7938766BULL, 
            0x818D7917923314A8ULL, 0x92796D279E618B91ULL, 0xF49110F20400967AULL, 0x8D530FAAB33B813AULL, 
            0xB4D6A79F651F9001ULL, 0xAA6404D0C2A80946ULL, 0xF685194AF9D35443ULL, 0xEA2D11CD5E2B34C5ULL, 
            0xE4868A605063679BULL, 0x41246CE42259EDAAULL, 0x198059AC73281901ULL, 0x9EFA6697D447C44AULL, 
            0xF751B0D4EE56B02EULL, 0x01B9305EBF814860ULL, 0xB553C46B9AFA2114ULL, 0x07E6888D591C4E12ULL, 
            0xA2157445D9E2DBEDULL, 0x8D0FB4595A007680ULL, 0xC28A9F9223752ABCULL, 0x367665BD06DDFD17ULL, 
            0x780BEE16476F73C4ULL, 0xBF5A1BE22ECB5A31ULL, 0x343A3B6D3EE96103ULL, 0x30DBC1A3DEFF9101ULL
        },
        {
            0xB92FA289FA4B01D2ULL, 0xB2F46376F6571236ULL, 0x471963B0A704C1B4ULL, 0x6C093777C0F65BBFULL, 
            0xD25642F3DC933853ULL, 0x86F6C788D465D48CULL, 0xF17AABB622468E71ULL, 0xC14F225C18BA3AF2ULL, 
            0x9AC980DDC940BC15ULL, 0x42203A92E8049234ULL, 0xE62B288F9BC9285BULL, 0x044C09832A43A10AULL, 
            0x307301E4A54F9FD1ULL, 0xCF7A87D3C5771B48ULL, 0xF67F1E4BEA2A0C7AULL, 0x2123831C78B8DA39ULL, 
            0xC6BC6BAAEA59EE80ULL, 0xAF87F12E55CCC883ULL, 0x49A287DA6C73488DULL, 0xC0CDFBE86B84BDCCULL, 
            0x964940A3A117DF15ULL, 0x96B7A9A45C0086AAULL, 0xD7061B64F3DB2365ULL, 0xAB9380B38056AF92ULL, 
            0x506E17C68331554FULL, 0x32853B3621FFB6BFULL, 0x1B51B6253A6C169CULL, 0x46CC6118B4A12E3DULL, 
            0x4F623191BC788F44ULL, 0x7210B2AAEB2D87E7ULL, 0x4FC05CECE3DCE3A9ULL, 0xC4B1DEEFA58B7A8EULL
        },
        {
            0xF314F383E2973B28ULL, 0xABFA343F8D9D89DAULL, 0x40F11066F451F698ULL, 0xA8ED800D3C497988ULL, 
            0xC6758066B8EE6AB4ULL, 0x7519D20AEA275E50ULL, 0xEF0EC72B09ACCB6CULL, 0x68ED162F9EC53542ULL, 
            0x94FAE361E9034B39ULL, 0x289259CE9AEA83DCULL, 0x038A39350CBE7733ULL, 0xF16D8A25EFC081A9ULL, 
            0xD873570BEE8870A2ULL, 0x3ADD3DCF868D0697ULL, 0x58FB7EA893B03F2CULL, 0xC5733D320699FDD0ULL, 
            0x67233A7B49738D0FULL, 0xFEC612F7F1BF7572ULL, 0x01AD30699DE303A7ULL, 0x818C1819E527A3F9ULL, 
            0x806B4D24D628FD7DULL, 0x948DE81744ABA1BBULL, 0xB4D1496F0D1CE545ULL, 0x616C7A7928C63A1BULL, 
            0x5D402B287474515EULL, 0x7DBDEA9A96FFE996ULL, 0x459A2F959C0E1584ULL, 0xC4FF7356DEE246C4ULL, 
            0x4D564898175DB50DULL, 0x6C65B8FFBA9A4966ULL, 0x9BC71F713CB25D55ULL, 0x113C2C03F59D3C33ULL
        },
        {
            0x2F75BA92760C3A45ULL, 0xD6513B825D9C1E84ULL, 0xAB8820A3D159495CULL, 0xCE560AD2B7A1C856ULL, 
            0xB4E7A104B9D83EE6ULL, 0x16960F3598CB9067ULL, 0xB4F464DFC9052052ULL, 0x8A16E453817FACCAULL, 
            0x16872D18380A9014ULL, 0x7798378885AA5764ULL, 0xE008F1832ECA81A4ULL, 0xDE4CA825162433F5ULL, 
            0xEB9789B9D4B3843EULL, 0xEAFF849AB72E0121ULL, 0x1FDCE1755CC34B1FULL, 0xDEA367C9DD15E3B9ULL, 
            0x2BB6068C3219D0EEULL, 0x93DE3CAB8B5FE88DULL, 0xB201E2BCF8BFB7DCULL, 0xD7F3126AD601BDAEULL, 
            0x28C79CECC44BB2C0ULL, 0x7BDD85A67AC73E14ULL, 0x44E49DF22B57DDCFULL, 0x9FF270E9323A20F6ULL, 
            0x022BCB58B5AF0521ULL, 0xD969112B99021AACULL, 0xB0A7F0F22D02F67AULL, 0x2B68E5F4535ADEC4ULL, 
            0xC2865523C1281DBAULL, 0x2BBD2E31ECF29C24ULL, 0xCC041E2238185615ULL, 0xC485C98BCBB20E8DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeyRotateConstants = {
    0x11E5E85E63050939ULL,
    0x75EB8622ABD36A5EULL,
    0x9AFCA28AA5FFDAECULL,
    0x11E5E85E63050939ULL,
    0x75EB8622ABD36A5EULL,
    0x9AFCA28AA5FFDAECULL,
    0xA567CE5DCCC4A03BULL,
    0xD16ED6A1DE70FEF5ULL,
    0x3C,
    0x70,
    0x65,
    0xCA,
    0x43,
    0x13,
    0x23,
    0xF8
};

const TwistDomainSaltSet TwistExpander_Gemma::kKeySpawnSalts = {
    {
        {
            0x7C47DC13F8ED6B5CULL, 0xCF934C50B13B8EF9ULL, 0x26526C564600CAA5ULL, 0x3E6DB173EE8BF294ULL, 
            0x6804D90F347CCE4AULL, 0x674225B62311B24EULL, 0xC1362D23E1DC8D37ULL, 0x67EC08C062EC57F6ULL, 
            0xD3EB3D18796D9BDBULL, 0x205ABD56DB2BC11DULL, 0xE3D8C534250F094FULL, 0x86E4F328069E0E94ULL, 
            0xDC7F16A87FFABDC8ULL, 0xE7C17FD568432E31ULL, 0xCC68FA6E9FD3C67CULL, 0x71616D614A82E083ULL, 
            0xD3579FD8F367D86EULL, 0xF72AC1D4F81580C9ULL, 0x3F30239612B9026BULL, 0x72C3E184AA23795CULL, 
            0x986D840B94219416ULL, 0xB9EE649264F08E7EULL, 0x3CCB730BCB088CB1ULL, 0xE3A8566D86FE391DULL, 
            0xED78241BE7249A4CULL, 0x31B028313333A4C9ULL, 0x0E7BC440792E779BULL, 0xFABB353D03A0C6D7ULL, 
            0x4F4745247BB445CBULL, 0x3C710BFEB3492AD6ULL, 0x0236D6D78B487546ULL, 0x110E2185F39A4206ULL
        },
        {
            0xDC81B88BE6415388ULL, 0x14C7D4214ABCE6C7ULL, 0x8A038EBBE1C75CA4ULL, 0xD4E4E7C7788DC1E3ULL, 
            0x0010594D3227495AULL, 0xFF7BA47D746B47D8ULL, 0xED9F385CBB96A9D2ULL, 0xA95244491D55D171ULL, 
            0x5AA2CD025419E16BULL, 0x8B020FF05DADAE05ULL, 0xF990B14B5125BB28ULL, 0x93F6493007271385ULL, 
            0xDF683EE91296057FULL, 0x1DEB4FD47412B8B6ULL, 0x2C655B62236BE435ULL, 0x05D2EBDB948EFAFAULL, 
            0x568CFD886B7D30A8ULL, 0xF2C0712579771DBBULL, 0xBA3426B46F813FAAULL, 0xA47439020DC244F4ULL, 
            0xB743B231367CABBBULL, 0x7D116CE728F0CB5AULL, 0x524A59019AF6379DULL, 0xD3FB5204F4FD8F80ULL, 
            0x401051610FF5C123ULL, 0xCC52CC28F55D0343ULL, 0xA3F87E72E8008EE3ULL, 0xC7F3EBFF2F37567FULL, 
            0x995F11F0785827AAULL, 0x9931415C8CDEAF13ULL, 0x219EFD2FD818A76BULL, 0xB989EFD45CD401A3ULL
        },
        {
            0xB928A0224AC956C1ULL, 0xCEFFC90DEF85E942ULL, 0xD81485E0C2FDF15FULL, 0xDE79EBD251A656C3ULL, 
            0x20F20BA4673FC69CULL, 0x556FEDDDCBA4FFAEULL, 0x1253224F4B06E26EULL, 0x4811980D5B84DED6ULL, 
            0xB8BE66AA23B2CB2FULL, 0xE47F0ADA65759296ULL, 0x83DF68E0462E5F5CULL, 0xB61E9FEE4A9B1F79ULL, 
            0xF006B8D40A8B3783ULL, 0xCD9E3C7C08D46B02ULL, 0xEBFB42DD528DA591ULL, 0x2ABB30C2AA7214D6ULL, 
            0xFCAC8C42B6ADA2DFULL, 0x1EF9C7E34F997541ULL, 0x52719127BEA3612AULL, 0x879DD18A73F11B6BULL, 
            0x04BEF20F66D7106CULL, 0xACA74BA6422C6D8EULL, 0x197492140F58C7FDULL, 0x5914867279292217ULL, 
            0xD274D601A0F56658ULL, 0x32575369031F8031ULL, 0x851C31C0B72B2A53ULL, 0x830837FD7292FE19ULL, 
            0x58FBC724661F9B23ULL, 0x4A2902EBA7A0CF52ULL, 0x4837A83B7E155576ULL, 0xC3728F158CB18865ULL
        },
        {
            0x95C968C44D44007FULL, 0xA2EFE6BD7F76F096ULL, 0x89B7285420BC3C4DULL, 0x6B4B5B04B5BE3FE2ULL, 
            0xE167BDE06E12EAF0ULL, 0x16D700F4A5B37577ULL, 0x4F6C86DC05D7AE6FULL, 0x6BB271CFA387123DULL, 
            0x6D7F231BA25F6049ULL, 0x367B6EF7EE5F253EULL, 0xD2BA9250FB766692ULL, 0x8BEF30F3704B2CEFULL, 
            0x9A7CAC9D9EF2237EULL, 0xDC20EAAE427FE41BULL, 0x2AD112FCD1346757ULL, 0x835A8D565AE84BF1ULL, 
            0x8848711BF21840A5ULL, 0x643017A46C37957DULL, 0xF61D93E479DEBC54ULL, 0xB24E37300589E0C9ULL, 
            0xB04852B251797972ULL, 0x3F327F35F0ADB666ULL, 0x5CA8BB0D0707A161ULL, 0x352BD77B834AA407ULL, 
            0xC4021EE9CBFAFA46ULL, 0x922665C5A5F98B86ULL, 0xF15B4573597EDEC7ULL, 0x5A70AB02E0AFF385ULL, 
            0xCE61086A0836990CULL, 0x988A5D1481C7E5E9ULL, 0xD472E30D18E97B95ULL, 0x980BCAEB81718DDCULL
        },
        {
            0xB4F188BE04E60586ULL, 0xCA3362DCAD1F58BEULL, 0xFD509435719BF4E0ULL, 0x50947E53BB098DA7ULL, 
            0xF0F18C1952FAA978ULL, 0x0E1BCE2CD328F0AFULL, 0xA81295325FD93CD8ULL, 0x11C27439B179B987ULL, 
            0x934E1CC8AF73936EULL, 0x2964676F1C07F49FULL, 0x877B587D9548CDF3ULL, 0x4A3AFBC8F0BECF22ULL, 
            0x7A97E8C135F6F88DULL, 0x07C33D7A572AD316ULL, 0x099136EEDE2840FDULL, 0xCB87B79583A65814ULL, 
            0xE0B3BC66FDE2DBCEULL, 0x494370208EDAC1B9ULL, 0x86EBB5A9E951CC45ULL, 0x76CA6A5AF802C412ULL, 
            0xA06B63F24DEC6E9FULL, 0xE921ACF388735A27ULL, 0x106D35E51CDA6AFBULL, 0x8E0D9F0E1B1BD7AEULL, 
            0xDCB2F7675939460BULL, 0xAC427087AE92701CULL, 0x4DB3EF4A87256E0EULL, 0x991829ED56D855E5ULL, 
            0x0F767BB98EDBFD5CULL, 0xC3D22E683C0754F9ULL, 0xFEEF046E45DFAE29ULL, 0x80AB49B9BDD81BDAULL
        },
        {
            0xB66326FCDDF93F54ULL, 0x52546B3497629AC6ULL, 0x5D2CD2CE8FA361BBULL, 0x4CB97AC97511420FULL, 
            0xC40D6918DF1B9E22ULL, 0x9D892AA8DDCCF3ECULL, 0x4A1E47B0809B71E1ULL, 0x99BEFB9746467B67ULL, 
            0x6D0B6A19D780ECA9ULL, 0xC0DAF18CAD1D696CULL, 0xD7F0193B3F531A1BULL, 0x4B480D0B26E60592ULL, 
            0xF2C164E8FE387439ULL, 0xC3D9DEA19ABB68A4ULL, 0xD9BD7F242C4B7D53ULL, 0x182B92C940989414ULL, 
            0x31F76ED6EC3042DEULL, 0xD8D4F0BF36DD4D5AULL, 0x321425F7A65BAA8BULL, 0xE4412164A6F65413ULL, 
            0xAE27B61B4847E39EULL, 0xED9AE939DF39E3AFULL, 0xBC98CBFC5830EBA2ULL, 0x9BDB5DADA06F05F3ULL, 
            0x0734864D74C78C0EULL, 0xE385417DA8BD301CULL, 0x229C60D7477421E1ULL, 0x63C385688269FEC3ULL, 
            0xA6EFA32069080A0BULL, 0xF5CF96A60EADEA81ULL, 0x58BDB2882704CF60ULL, 0xB9548FBD8F84D918ULL
        }
    },
    {
        {
            0x3073D4785F9DBC2BULL, 0x7910565ABBBE1854ULL, 0x68868F4940576473ULL, 0x4A46441C4142C39BULL, 
            0x83480DCF8CDE5DC7ULL, 0x52DF57700639F6C5ULL, 0xA5D9DF1FDB6C39F1ULL, 0x8A5D4EFAD5637925ULL, 
            0xCFDA384ACC902AF8ULL, 0xD546105EFFADFD96ULL, 0x32DE425975B8510DULL, 0xAAA509DA8BBD5B9EULL, 
            0x4F395811B0B9A506ULL, 0xEBA9C32A45813CF3ULL, 0xBF2700EE81E873E0ULL, 0x588FA9E6FFB6378BULL, 
            0x56645E5818E02E2DULL, 0x7DDE59AA09358096ULL, 0x2EABC299C2F3E568ULL, 0x9CBC448A4B1145A6ULL, 
            0x600598C35B3D9FA9ULL, 0x9E68B31EC73575AAULL, 0xB99EB428F9EB2069ULL, 0xC6EC738570872C0DULL, 
            0xE52884EFE5D861D7ULL, 0x101DDA886F6D9CC0ULL, 0x7E58B0A53B69BDF7ULL, 0xC47AFB3615705464ULL, 
            0x6CEE64A5214F4F56ULL, 0x51D8FB09E04E62C4ULL, 0x4D972E94AB3A6FBDULL, 0xD62595515D866C4DULL
        },
        {
            0x086071D3110CB343ULL, 0xA27521237DC72399ULL, 0xA1D7BE774B8BE391ULL, 0xB8F643C92F85A3ECULL, 
            0xA189AEF7A873CF1FULL, 0x13F204706265D6E3ULL, 0xFD8F7E6A95496E60ULL, 0x8A7734BAD0F91700ULL, 
            0xFFB9519A4A8691CBULL, 0x5A51E28F2908E8CFULL, 0x82D41A62B64ECD2AULL, 0x2BD597E30DCC312FULL, 
            0x32F4895C2BE86F9CULL, 0xBFCAF8AFE0952F50ULL, 0xB45F97DA29107601ULL, 0x8484B90766C990F4ULL, 
            0xBCFCFCE5444E1E01ULL, 0x01B724B0F67CF4B2ULL, 0x14EE62C570B85E06ULL, 0x97DFB550F0B8994FULL, 
            0xA55CBA8383C22FD6ULL, 0xA07AB2535F4A0048ULL, 0x94522638C3A36129ULL, 0x34694CCFEA86D644ULL, 
            0xEF1E650F3A1C6BB0ULL, 0x1D5075036C0D7C42ULL, 0x8109743EB9040083ULL, 0x7D3A60A6F269897CULL, 
            0xEEC55D3160EEF3C1ULL, 0xA311B678E29C39B2ULL, 0xE704AB50424090E9ULL, 0xA02F98BDCB0EAB15ULL
        },
        {
            0xB8CA3438457AD207ULL, 0x14FD2527CCF47EC4ULL, 0xB78395D9ED1E779EULL, 0x4CEB6ECA58DF16C7ULL, 
            0xD7535042D362B872ULL, 0xB71EAF26560DA5E6ULL, 0x93F5A0820F5C8FC7ULL, 0x328B226B0504F076ULL, 
            0xD95B5707833A0C44ULL, 0x6BBB894E2CB28805ULL, 0x4D05BABF1AA66FF7ULL, 0x217C97EA4AACBC56ULL, 
            0x4B36C5579E66BC7DULL, 0xC13D5CD420311D03ULL, 0x150914909BAE69B6ULL, 0x879E0320060BE172ULL, 
            0x363E1FF9A2197E1CULL, 0x2B77CF7A20684FE3ULL, 0x3ACBB976CDED4A3AULL, 0xAC1EBD3DE434DFC5ULL, 
            0xC6470D13B9C0E9B4ULL, 0xA8D8C0019C57C11BULL, 0x1D6FFEBCB9919CB4ULL, 0x0642ED949E280370ULL, 
            0x8CDE770944560A31ULL, 0xDC76B69766933F11ULL, 0x510F736B9ED952EBULL, 0x959446A924698EDDULL, 
            0xF0066BB60F0ED833ULL, 0x47F3A20947CA6734ULL, 0xE7B0B114822D3726ULL, 0x6C941A66C5AF2D5EULL
        },
        {
            0x4C1CFDCC5E54633EULL, 0xC5B2FCA37CA3E26BULL, 0x70EE33D2A098523FULL, 0x608F529E02FF03C6ULL, 
            0x707BC2C42200C526ULL, 0xA5BF425C06766394ULL, 0xDF884B9C0898E541ULL, 0x5A9E29E1731892E1ULL, 
            0x0841ED3F79572B91ULL, 0x7269212CAEE3C47CULL, 0xE3AD65E192E7F470ULL, 0x62F23E89F405056BULL, 
            0xBB25E122636B306EULL, 0x906C2F4EF30C15C3ULL, 0x21D41F2BFEE90482ULL, 0x14587BAC62340DB8ULL, 
            0x9A8F1E465F556A96ULL, 0x64410B84B219A5CFULL, 0xF860B525F4C9CE22ULL, 0x3542CCD0F7BF0797ULL, 
            0xA4041F2C1DE4526CULL, 0x2059960C662747DAULL, 0xA4304D2731A7F5D2ULL, 0x8C207117009CBA54ULL, 
            0xE9E5839F8F191F92ULL, 0xDC8A6CDACA421903ULL, 0x071617683008E70FULL, 0xCDFAA4FB763D07FAULL, 
            0xC3F98F3D32AA48E2ULL, 0x385828F9FD648B0BULL, 0xB6E4F3AC896E017BULL, 0x9F06EEAB2363C19FULL
        },
        {
            0x5D9F49486E7B3260ULL, 0xAC025B9640B1402CULL, 0x238C2DFF8D36C4E8ULL, 0xDB5A59EFB73AB717ULL, 
            0x0CF86B0431E695A2ULL, 0x997DB8F4218F6EF3ULL, 0x2F3103AA6590BBA0ULL, 0xD6006C0C431C28DBULL, 
            0x5C7CAD31BB144B71ULL, 0xA1B789904F81D478ULL, 0xD68495498E0BF3B9ULL, 0x2662358E0D5A037FULL, 
            0x80B4EE09B04C5C12ULL, 0x9942E7484AD6C883ULL, 0xD8D97A5EACBAB65FULL, 0x2093010458E6CAF4ULL, 
            0xBA65879DCCE0F2FEULL, 0x3616737E61E932C3ULL, 0x0B27F39A5F6A4278ULL, 0x2BE65050D0739350ULL, 
            0x20A892D728078A00ULL, 0xEB8BA2DFFA7F1262ULL, 0x4F662B7B65B7B7B3ULL, 0x8FC072E628C2FA0BULL, 
            0x9AE75BD37F739FB1ULL, 0x8BF2BACEA58EB9F2ULL, 0xB9B40E8D8E872C3FULL, 0xF3FA60B882F9A35CULL, 
            0xC3E87214B7F48230ULL, 0xFFE4DCCE2DB96080ULL, 0x32F90BCB006253FBULL, 0x6D924BD534DD908BULL
        },
        {
            0xC703EB2898377804ULL, 0x8DE46131E0D97EA0ULL, 0x442603BB750F8A35ULL, 0x91AA7FFCD3884D9CULL, 
            0x7C75D848AE4F3802ULL, 0xDC98FFAA1D39633CULL, 0x73E27B3F0030E950ULL, 0x71CED3DC1482AA44ULL, 
            0xC30E6A97B0ED6E0DULL, 0x9BA4A4118213F92FULL, 0x99F055BB8EA43401ULL, 0xEAC21870FBFB5F03ULL, 
            0xC0EFC57F95616785ULL, 0xACDEC91C6A835879ULL, 0x2C3AF1BDC57384A3ULL, 0x94D01EFF35DA95C7ULL, 
            0x290346DC44BDC2F0ULL, 0x55B71405A128DF8EULL, 0xB77A3D9A0C4EAD5DULL, 0x1A1667E1075AAC1CULL, 
            0xAF92B570AA9F558EULL, 0xB0942CA8FAEC6E7CULL, 0x094C53E39E1F64C4ULL, 0x62501D64160D8BE9ULL, 
            0x7EF78094BDBAE38CULL, 0x8646F6FDBB4AE05FULL, 0x174FBA98E0CE297CULL, 0x925068A4BD51E595ULL, 
            0x4E359611FE286EA0ULL, 0x61B00357B1819EB8ULL, 0xAAA1CDFAD228F06CULL, 0x8FEC07C660098E8EULL
        }
    },
    {
        {
            0xB523C77BAECFAD20ULL, 0x1E3E9667F5F04495ULL, 0x0F4034B99C8E1B1EULL, 0x71CC02C11660E779ULL, 
            0x1F5FA0A2A20FB372ULL, 0x347C9135C63E4EB5ULL, 0x4C6F86338E98125CULL, 0xBCBB8C21E7D97BF9ULL, 
            0x311F810565869467ULL, 0x7B76B580237A9626ULL, 0xF1C10909C4078033ULL, 0xD83BDE8ABB42E845ULL, 
            0x953E98FE7F8A6CD3ULL, 0x2CE9B94D4303611FULL, 0x31A8A6533C2B0282ULL, 0x4CDD8638FBC7DF1AULL, 
            0x23F2C99BBB1DB771ULL, 0x2F03EBD6F0A255FFULL, 0x463D30F86FBD8760ULL, 0xDEFD74EEDF349E33ULL, 
            0x1AFABDE5C21F7535ULL, 0x8D817B5429128BB5ULL, 0x67C5EAD5C98C3AF0ULL, 0xF6CD0FE4BE06CE9FULL, 
            0x7B0A66151C66C1F0ULL, 0xFA2A8955C6FA8D2FULL, 0xC19D84AC55F0B5FBULL, 0x9EFD722A53D17837ULL, 
            0x0EC39CAC4C43D522ULL, 0x7612BB705C0CFDC0ULL, 0x50EFA3F3CB53531DULL, 0xE583DFADA4AA6ECCULL
        },
        {
            0x92B3FC73A4319C53ULL, 0x91A65D9D5572AA55ULL, 0xD54F935B7925F602ULL, 0x621EF9A5AB496C56ULL, 
            0x3289F529A2673169ULL, 0xD74A1E6E49A29A7BULL, 0x61AFA05142AF7198ULL, 0xBEF76E2E6F0D72A6ULL, 
            0xFE76E662042FB907ULL, 0xB256E875B078BC73ULL, 0x9DF6499D3F6FECCBULL, 0xDFFD031EA801A843ULL, 
            0x0D236089597F733DULL, 0xF121BB99C7B6BE11ULL, 0x24A86D911482AE21ULL, 0xD4F7F642BB588406ULL, 
            0x66D0E10F469990BDULL, 0xDAA1B8439AF91571ULL, 0x222F46BF537E83BAULL, 0xB634CE46A380707CULL, 
            0xD04F6B780DBB3490ULL, 0xD1605670E05F0D2BULL, 0xC81AE4413BFF9B0AULL, 0x1EA3B97E2EF2655DULL, 
            0xF76F92522334F576ULL, 0xDE7A4E4221D3C6BAULL, 0x62272BB0F2C5DF39ULL, 0x917B3E876885FF8FULL, 
            0xF6CBDE4C6488D0E0ULL, 0xC848B47DFF8633CEULL, 0x628D7023C36B4E79ULL, 0x33B1ABA080965EA8ULL
        },
        {
            0xD3BBEB132F8DBB0AULL, 0xE0E1F67013EA5E03ULL, 0x8046E850A62D62CEULL, 0x7D17C4E211C0E6D9ULL, 
            0x42557DBE2B929E49ULL, 0x1FEBDF4C99798E2CULL, 0xC5F33C266D25F777ULL, 0x889B96050DE32868ULL, 
            0x81E6F765757F2334ULL, 0x88979BC610325D55ULL, 0x3E864676535A4237ULL, 0x02DABD392E302A31ULL, 
            0x0C1344336A4518DDULL, 0xEB85890153FC1A5CULL, 0x5175C9C3911F955AULL, 0xDB0C5BBEA769F8D6ULL, 
            0x4A7AE95D522EDE50ULL, 0x8B466503B4D1A5F8ULL, 0x307C59D0300CD673ULL, 0x471546CFE8D46A0EULL, 
            0xCB9DE32C925340FDULL, 0x2E213FF4D8CF706EULL, 0xFA84CC0EAA67125AULL, 0xBBA20714C0DD5CE6ULL, 
            0xDE91D3162F56D9FDULL, 0x95C831BA4B939668ULL, 0xDAD686C4EB7706F5ULL, 0x38F3A6F0D75D0585ULL, 
            0x1A94D4E69D6A47A7ULL, 0xF86CC7077AF3A8CCULL, 0x7BE7425A3EAE82CFULL, 0xF022367DCA67A5FEULL
        },
        {
            0x78E7E77D9E67A91CULL, 0x87127D59F11326F1ULL, 0x3082799FFDE7FEA2ULL, 0xA51B1D16631421F4ULL, 
            0x13D6AFE69376D20FULL, 0x970A3E12DA0087DFULL, 0x22F8AB7FAB85BF5CULL, 0xD9F1FBEB62144FA1ULL, 
            0xEB94A7A349E11457ULL, 0x01F17C1F49DEAA69ULL, 0xDEC818050B3859EBULL, 0x4B93E678B2FB5687ULL, 
            0x5CA381FE58AE94A1ULL, 0x17B1039C0B1F31FCULL, 0x7A435C10E98163A5ULL, 0x1F4202685B612BF4ULL, 
            0xC5FDBCEC9644679AULL, 0xF32BEF6AE5AC8301ULL, 0xAE2B0D000C72807EULL, 0x080D3C98FE7904FFULL, 
            0x21362BE6EF32FFC1ULL, 0x9C0AD9A4F8BFFC06ULL, 0xEC56324045BBDC3BULL, 0xA23469761F9DFE58ULL, 
            0x7DC09F99CE9694EEULL, 0x6851376E4BF81888ULL, 0xFFF1F324F1EC71E7ULL, 0x955F43F9BD9B9BF3ULL, 
            0x04BA5A96237B8622ULL, 0xE829ACCC22AA9A1BULL, 0xD0D217CE7D9BE7DEULL, 0x9A5CAECC53AA8D46ULL
        },
        {
            0x7BB2722E63626AFBULL, 0x64BCCCD48BB8B01FULL, 0xC1C1059BF213EE54ULL, 0xC67752D227CA2AC5ULL, 
            0x6B6FB7FD6B83FF09ULL, 0x7AF53D70D0FE20D0ULL, 0x8B349C06430E384EULL, 0x5831D32C41C16173ULL, 
            0xBEAC76A5B9D627AFULL, 0x6C803703AED459B2ULL, 0x86D20064C01D16A4ULL, 0x64DD9C268E690E31ULL, 
            0x235E7C823AC2C2DCULL, 0x178B65AB2049390FULL, 0x351EE90B4149309BULL, 0x83F32ECEDB3922D0ULL, 
            0x72330329EFACD9DEULL, 0xE1B36004FB719D5CULL, 0x36723901C88008A7ULL, 0x559A9B160508FD89ULL, 
            0x73CBEBDB9D059C7FULL, 0xA56717D38762131CULL, 0x4A08A655283941CCULL, 0x927A15862C662A32ULL, 
            0x7266E2558274172BULL, 0x2202CDA7291510BAULL, 0xE36415F191D2EB05ULL, 0x0A2A0560A111D2FFULL, 
            0x170D29ECD167064DULL, 0xD2C53CEB144BF733ULL, 0x0487846C33CD5603ULL, 0x16FA60F6F3FF3847ULL
        },
        {
            0xACB7BCE4214F73FEULL, 0x1F9C40E33BF7D569ULL, 0x73794C133CAB0413ULL, 0xDC491E173C8E469CULL, 
            0x24AD72DCB5E49600ULL, 0x9B9C286E1025F918ULL, 0x5EA376E7C9F1D9F6ULL, 0x6223C4991E30C61FULL, 
            0x6A6BD99209D21077ULL, 0x186654530E348762ULL, 0x135BE1D4515E4897ULL, 0x8F861E56BB77C540ULL, 
            0xDB68E5449597D751ULL, 0x5B60C0B23C10D36EULL, 0x666CE91E0F07BFF7ULL, 0x96A56F7CBE1F6CA6ULL, 
            0x4C26FDB8871481B2ULL, 0xEDAFC17D8A8BEBD5ULL, 0xE73514B9549BC9DEULL, 0xC53BF9A0FAC9611DULL, 
            0x3BDC533B2AA4EAEBULL, 0xA1EC0AB6B639122AULL, 0x27D506A4DD1166A7ULL, 0x2A0FCE3743068ACEULL, 
            0x6A59BA937CE0B4DAULL, 0xF70872128DB9CD2DULL, 0xF59F3D01CCC72ABAULL, 0xECA1EFE4ED3EC629ULL, 
            0x1C1AE5A2B3F32779ULL, 0x563FB5D98C0E0D01ULL, 0x242BF17C5585F5F0ULL, 0xC562B03712E6FF1DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeySpawnConstants = {
    0xEDE6CB79CE6748A9ULL,
    0xD3DD3F35B4F2CFEFULL,
    0x5546A27DB9D924F1ULL,
    0xEDE6CB79CE6748A9ULL,
    0xD3DD3F35B4F2CFEFULL,
    0x5546A27DB9D924F1ULL,
    0x4C814FF0C4341F69ULL,
    0x1F81B1655337735FULL,
    0xFA,
    0x25,
    0x42,
    0x79,
    0x62,
    0x43,
    0x6F,
    0xBE
};

const TwistDomainSaltSet TwistExpander_Gemma::kSeedSalts = {
    {
        {
            0x947A71F7DC4533DCULL, 0x317B0FD3F6676B24ULL, 0x277BEAA20D2A26C7ULL, 0x557C71D1E46346A1ULL, 
            0x4130781E704DF7ADULL, 0x619E6F839F1F9DF1ULL, 0x38644709E2ED9C74ULL, 0x7F9AC5D83F29C0CFULL, 
            0xFBB48BE7E99C3B1FULL, 0x59F2F8E294663050ULL, 0x20A637196B3B90A6ULL, 0x075E496EA4FF3DD8ULL, 
            0x577F8E0AC893B81AULL, 0xD9073505CCA76AABULL, 0xAB10922A13C73750ULL, 0xEAB2352650CB8670ULL, 
            0x99E1908A61AEE63DULL, 0x8DF90DD54C11752FULL, 0x7528DD4155291420ULL, 0xF032474DCA20CE02ULL, 
            0xE7D1A7579DB76F02ULL, 0xFA6F4875B6568871ULL, 0x34B504C83F7D769FULL, 0x7F92DF12C71148E0ULL, 
            0x4D89135BD4B9C134ULL, 0x0659FB1BAA116C40ULL, 0x74F51FC51A1F15E1ULL, 0x68BA4B716350E02FULL, 
            0x737A551512C5EA4AULL, 0xEE154BE77F1595ADULL, 0x85F2203B8DF277E7ULL, 0x0B35633219A8EFCAULL
        },
        {
            0x410543D33CF1D2F1ULL, 0xAE0AE8FE0422C2CDULL, 0x623BF0B387A87B74ULL, 0xE2E9AEF59FD7AC85ULL, 
            0x9F1942E4B4BF6EC4ULL, 0xA95F73CE5A5A4372ULL, 0xFCBD2855AFD29CE3ULL, 0xBF3181754CDE9E9BULL, 
            0x907AC3A013809E48ULL, 0x729EC3067B614F87ULL, 0x1357A5ED17811126ULL, 0x22BD2285A5107E17ULL, 
            0x2C91144659DAE679ULL, 0xF31F2A0A89E301B5ULL, 0x7F2F20E5CC84177BULL, 0xE39122C58E7AB74AULL, 
            0x3CB5918268F9F653ULL, 0x6BAC82E857A824F7ULL, 0x0BF3A552833EF96DULL, 0xA7FDED317B8E79DAULL, 
            0xD53D0C34220F3F5EULL, 0x362FA7576D12C15DULL, 0xCAEE7D96A065AF1CULL, 0x25AEA40A48E0FD8EULL, 
            0xF09CC459BB3689DAULL, 0xF628692A6F5BDB0AULL, 0x7DBFFBD027947554ULL, 0xA076A91F6972C8ECULL, 
            0xF8AD843F8C214B0FULL, 0x96784946B877921CULL, 0x48B9782B52A573E7ULL, 0xB4B5DD3038818758ULL
        },
        {
            0x4D3F4B04853F4780ULL, 0xB2F5F180B353548AULL, 0x5F25309C7EBA6777ULL, 0x95DD981C057B4416ULL, 
            0x7EE8494921AA25DDULL, 0x0C3E8142479A2B81ULL, 0x938D0E9A8F845740ULL, 0x9F237409392C9681ULL, 
            0xBF359AC70AC20AFDULL, 0x4BAD12D8E397B21EULL, 0x31FEB6BC995B598CULL, 0xF6CDF93DAE9F17BCULL, 
            0x3D84E2CAEB8B2B66ULL, 0xF3A55E691F95E09AULL, 0x341F10342AF0B269ULL, 0xA0D6EDEFD86B3A79ULL, 
            0x4C91219F5CB9845DULL, 0x62843BF9860DBC57ULL, 0x639DD4143C32C09CULL, 0x50A6EE06916852B7ULL, 
            0xA14D597D074AB474ULL, 0xEF9452ECD1D74667ULL, 0xBEB55442290E2ED1ULL, 0xB9A855D071CE4BC6ULL, 
            0xFE2BFF2BCE6532C0ULL, 0x3BBFBF0AFABE47D3ULL, 0xDDFABB946169D8FEULL, 0x236B39ADABC00207ULL, 
            0x3C13113E2FE207C9ULL, 0x37B79FD4EBA7634EULL, 0xEF248D9595BEB7F1ULL, 0xFC3D0DA2952994A6ULL
        },
        {
            0xE483F8932A095A02ULL, 0xB328DA4363D824C5ULL, 0x59DFD041605297AEULL, 0x76F6D1754F37C3A5ULL, 
            0xAA6713BED902425AULL, 0x168DE9149DD41DE8ULL, 0x701E6C6C3E19A4F2ULL, 0x68EC83C3CCF596ADULL, 
            0x7157C75D770CB5F4ULL, 0x460927A2C85E8664ULL, 0x9EA71833C3D139AEULL, 0xF3462D9E5003BDB9ULL, 
            0xD7580EF3B500A3B1ULL, 0xAE56A1BC06FD314DULL, 0xB940BB544A0315BFULL, 0x77188CA09F0B5D28ULL, 
            0x83CAAFC12CE5B66FULL, 0xCF36CD390F62354DULL, 0x4E63D75F56D458B1ULL, 0xD8A53FCA17D2E9E0ULL, 
            0x69759CC170A8AF4CULL, 0xF585697B934E1314ULL, 0x2C5CC4A208A272C7ULL, 0xBC43231F90B27891ULL, 
            0x5B6B6AC8D8418BA8ULL, 0x51E56E52193564DDULL, 0xB9B2EE9A713FF236ULL, 0xFFFEC1CB1B2CCAAAULL, 
            0xF451308BB1C178BCULL, 0xDC8E9850C2B2D91EULL, 0xC645ABA51B1C7D47ULL, 0x0AC793BE84DA4BABULL
        },
        {
            0x2E46CB8D9CBA504CULL, 0x3DAFDA6EFF8E86F8ULL, 0x777C85C1BF53846DULL, 0x40CF7F34DF574CA2ULL, 
            0x48C3D63CD3809FF2ULL, 0xF8CEED138997BA10ULL, 0x5512AE97F1030EA9ULL, 0x6CF53F25E88F9ADAULL, 
            0xADCDE2D6F9048586ULL, 0xB17B466A9F1DF40AULL, 0x3ADF05030516302DULL, 0x69638206A5F32D79ULL, 
            0x5417C19EDCC4185DULL, 0x5ED6D6426327BE68ULL, 0x9A2DD82D11BA3B76ULL, 0xC91C7A4735B22968ULL, 
            0x90C1FFD712657A26ULL, 0x006B9EE0573DA8F1ULL, 0xDBD5552D211C3C44ULL, 0xCA7510E4F03BFF6CULL, 
            0x1568EC4587E6C7D8ULL, 0x8735F19488B6CFF1ULL, 0x068187AD700FABE2ULL, 0x38400DDE2F316F9BULL, 
            0xE58573CBD44DD7E8ULL, 0xD0F6B639ED6EFBD0ULL, 0x6C915AC5CB3184AFULL, 0x4F89899059459DA9ULL, 
            0x8BD7DE2AE96464A3ULL, 0x72A541FD7D536AF2ULL, 0xC0BB5B1EF4A2EC9DULL, 0x5DF955FBA5C60E8FULL
        },
        {
            0xAF42DFF9CE5A2417ULL, 0xB2FFD22441F39A63ULL, 0xB80F562B04EBA56DULL, 0xB6A0E5E1A8AC6ABBULL, 
            0x33C4DC6310B80833ULL, 0x2E7757C65FB7F631ULL, 0x1FEF88E2FA04D16BULL, 0xB067896F7A07A078ULL, 
            0x1AD83A6E3B5087FDULL, 0xA8B90A26E855FCFFULL, 0x5A418D4F5CA4A358ULL, 0x8B11DC245C32634EULL, 
            0x01D9E8F47463A62FULL, 0x201AF8AEE1798A5BULL, 0x455192D65800639BULL, 0xBA9E08C586EEDAA2ULL, 
            0xFBA743740FB88BDCULL, 0x9791773C1AB8EE9CULL, 0xF4C89F68C195671FULL, 0x796AA23E9A09B7C0ULL, 
            0x56F273C25698F1B8ULL, 0xE6B57A28DC86917AULL, 0x3D96704B9E82E0D2ULL, 0x3E2944B99CCFDE72ULL, 
            0x5BB3098086668434ULL, 0x5A8A5E3A1EB0CB1EULL, 0xF540DFF51BF1E34DULL, 0x2F1C4600DBAC7F6DULL, 
            0x55108C27E55958D8ULL, 0xC6BD74B195955A72ULL, 0x5EA7521D2372CB5EULL, 0x922071E1FA70E548ULL
        }
    },
    {
        {
            0x78420FFA57649EECULL, 0xA5183D3F806FC6BDULL, 0xB7EF46611140AA96ULL, 0xB75C36A1EF8EA3FFULL, 
            0x9C8953D75FB4743BULL, 0x1864CE02A33E98C4ULL, 0xBD87973B50102445ULL, 0xA6BF12292F96818BULL, 
            0xE5C2B175D8713715ULL, 0x1C0CCEE3A31DCA9FULL, 0xCF71C3615C50C8E2ULL, 0xFDD53E6F65043600ULL, 
            0xAD6722BA1ADAED26ULL, 0x6583D75B28A8EC6BULL, 0xD52EEED3C862518CULL, 0xF403E4A5D2504A02ULL, 
            0x70A756B10F35BB0FULL, 0x4581DB50B3377F2FULL, 0x517B4F4F5CE834F9ULL, 0x10B7590096446265ULL, 
            0xD2070DC5531963D4ULL, 0x399B940FBAAFF99AULL, 0xD95BA85845089A45ULL, 0x8DEE5E7531623281ULL, 
            0x53BED0C28839D4BFULL, 0x251294B730570DDCULL, 0xF45475CC515EFF91ULL, 0xEAAFA19F4E205518ULL, 
            0xB019ECBF00FA14A2ULL, 0x9BA989B7B8744257ULL, 0xD0D60980B03AD649ULL, 0x9513E90B0E05EACEULL
        },
        {
            0x1D896AB8F94624C6ULL, 0x2C7C61D4E3C2116CULL, 0x4C5E52E76D0A96B8ULL, 0x29FDA5466C6FAEFCULL, 
            0xEA96CD98139F8619ULL, 0x7757B5170E2D232FULL, 0x56EC09C6F6E79754ULL, 0xCA72F744D907AA08ULL, 
            0x6D85BB52EF92A137ULL, 0x1BABC5A44A1100CFULL, 0x538C208C4AA4CB7AULL, 0x76B64DC4ED9E05DBULL, 
            0xEA3149BAEFF963C3ULL, 0x5F7425D24535E16CULL, 0x9FB58B9EB584F493ULL, 0x4213B947C17B28FEULL, 
            0x02FCCBEA835CDD43ULL, 0xF144E9D609ABA34FULL, 0x4940CFC85062CBF6ULL, 0x4B497D88B0DA2B38ULL, 
            0xF2C15D7E6C3AD719ULL, 0x3B49AE251578C51FULL, 0xE17557963DBAE943ULL, 0x1A36809311967AD4ULL, 
            0xE9DF2A7C7AAD1D72ULL, 0x5C8FC10917015DD8ULL, 0x12130FC128435A8CULL, 0x0B7BBDD9074B0A80ULL, 
            0xA69E41C9B7CEF741ULL, 0xF487037D1B5E9DC5ULL, 0x6D2B0DB3A58CD02FULL, 0x1D3331E099A7F06EULL
        },
        {
            0x50907859AD6F6F18ULL, 0x6F4BCD647DD48150ULL, 0x9785A4D24E7F09D5ULL, 0x6DBC6590EA747694ULL, 
            0xAC4914FA702808E8ULL, 0x09EBC5A2EFED922AULL, 0xDDCD6F8652F61A47ULL, 0x8763EBC7457F3D3FULL, 
            0x28A7901E7765EE1BULL, 0xEB552ED096295185ULL, 0xA20FC9A26A95EF9EULL, 0xD9E1C15E89869A7BULL, 
            0xBEB94DCB87538BAFULL, 0xB3E8183556123261ULL, 0xF9000DE0C7AD4C79ULL, 0xAD94D3D29637C36BULL, 
            0x48E6456A9E8E7523ULL, 0x7EF09C1C3497D3B2ULL, 0xA2B14E1263BBFCB5ULL, 0x311BCA85B55649AAULL, 
            0x40DC305358314C16ULL, 0xEAF3B6ED9AF8F0ADULL, 0xDBE67862830F84AEULL, 0x9B1552A70402BFDBULL, 
            0x06C8712AE89D4726ULL, 0xB96E55C4C1449C3DULL, 0x5904725EBECE2A99ULL, 0x08B7B24ECD66DE1BULL, 
            0x968EE923F7D32EEDULL, 0x6BBBA68E597D1B57ULL, 0x1791E4EAEBAC9B72ULL, 0x857BFC54DCBC0DA5ULL
        },
        {
            0xEE18315ECE5F9510ULL, 0x0267B4D1FDBAFD16ULL, 0x42703709BFE5BEFFULL, 0x886C1FA68530C896ULL, 
            0x047581E1164320DDULL, 0x5B2C64C328046AB9ULL, 0x42567B1E0900C81FULL, 0xF8487B8EA24D5F61ULL, 
            0x198480B11DEDDD22ULL, 0x4296A2B9A132FEB5ULL, 0xF154C9013FA112CCULL, 0x5D242014D704746BULL, 
            0xB50831C7B07A8B85ULL, 0x181EB88E549673DFULL, 0xA4B24EBE892F1FDDULL, 0x4BE50A7A96EDBF17ULL, 
            0xB888C36F520BC560ULL, 0xD9FC817D31F39BB8ULL, 0x3817344EFCE65B8CULL, 0xD16D139A6F2AE581ULL, 
            0x6F2CAE8599E22FF0ULL, 0xB70FDC595A80DC49ULL, 0xACDEADC03255CD03ULL, 0xF85F0E75F93B523BULL, 
            0x51E364BCD1212EC7ULL, 0x8CC3B6A9EA32EAB0ULL, 0x799E60A9E3559006ULL, 0x45157AC9EA1F036CULL, 
            0x4AD874BCD5F3EA0DULL, 0x3BA0EE0295C2C82BULL, 0x016E8048E3041F3AULL, 0x6EF7DBBC248D5F21ULL
        },
        {
            0x5CFA6F221740DEC3ULL, 0x745486DDF7BA8E1AULL, 0x7638E2A804A8C4EBULL, 0xD9D8BA69150C9BD4ULL, 
            0x9601A14E580AA692ULL, 0xF3DF9A8D8D79FDC3ULL, 0x757EE592A86DFA3CULL, 0xA866931ACD6A6C74ULL, 
            0x8305C8E4BA8098F5ULL, 0xFDA9363CCA57C8AAULL, 0xFB17B78D06DB9776ULL, 0x650E5877C54DB7B7ULL, 
            0xDC04DB71B07F29E8ULL, 0xA293C5595D6323CAULL, 0x0238FAB40F7D0B7AULL, 0xAAEFF9EE4B792EEBULL, 
            0xB3DDDCA70BE8EDCCULL, 0x8680D530A2243675ULL, 0x4F5387098E9B6EC1ULL, 0x87E3BF8708ED8D09ULL, 
            0xB68DE755672D55FCULL, 0xAD4CD44982ED7C3AULL, 0x7FA29F262374BFCCULL, 0xCAD05C33E5350520ULL, 
            0x23F12CEEC10A7FF5ULL, 0xE7F924326BBD5169ULL, 0xD4CB9067D6174482ULL, 0x65AC8254BD539CACULL, 
            0xCEC7F511BCD93DC7ULL, 0x7EF215021181F5DAULL, 0x9E5EC4E6787BB146ULL, 0xFC2444113E04982DULL
        },
        {
            0x80B5E20CDF9E0D7CULL, 0x5EC9BCECE31E7ABCULL, 0xB3351506B5095F4EULL, 0x73DA5A80D6271245ULL, 
            0xBB1982BE8F38C20DULL, 0xDB6F3AFD49F8DD6EULL, 0x64C6F87C56237C74ULL, 0x0D9E42E4B4B49A2AULL, 
            0x6C07A55D0C79CA81ULL, 0xD0AA56FEBE576B53ULL, 0x80EB66F7B7983F6DULL, 0xC013DAE28C0C0C48ULL, 
            0xF324ABA50904F405ULL, 0xDE0B8B5B4F4B978DULL, 0x2556B0712EB6E787ULL, 0xD01E8A405DF09C54ULL, 
            0x433995F50C7D3C54ULL, 0x1C99245AC9EDAB1BULL, 0xF4DA7CCB919202C5ULL, 0x04020881833DBEE8ULL, 
            0x92AD7B989A902438ULL, 0x0038155EE12FA6ADULL, 0xAD55BC5501F2C3BDULL, 0x9DACACF28F98935FULL, 
            0xAE57F575E78737E1ULL, 0x97826837F75E0415ULL, 0x0971EA7951D55115ULL, 0x71A6A995A8D596A5ULL, 
            0x2FF4BCB55D5A33B3ULL, 0xE825335720D2FFBDULL, 0x0FBE219BE216A1DFULL, 0xDC2CF8E388684E2DULL
        }
    },
    {
        {
            0x4A0D5623607DBC63ULL, 0x3D61464DF418B518ULL, 0x8B1DA5EE0D9ABFFAULL, 0x1F5473F160D5499EULL, 
            0x67CF6F22EB600038ULL, 0x058780D7AB78C31EULL, 0x972A6C17BADCBCE1ULL, 0xC577BE227AB06A87ULL, 
            0x839F28D1EFFFE58BULL, 0xCDDCA541820F85ACULL, 0xDA635BE6F61C8A48ULL, 0x428CA42B11383124ULL, 
            0x6AED68E7E3D28795ULL, 0x618F244FF0EB78CCULL, 0xA31645806B3E2796ULL, 0xD2627FD8C1EAEF02ULL, 
            0xA26C2963E525E6F2ULL, 0x0A40482AA8A781D8ULL, 0xF419F81B556AB535ULL, 0x4FFA2186B1F832CEULL, 
            0xB1014C5B556BAA8CULL, 0x71D46E70CAB8E368ULL, 0x7445964B8C01BFD4ULL, 0xE22BF817F23E6596ULL, 
            0x705403A18D993FF2ULL, 0x5EBA97411E99B181ULL, 0xE206D02CDEF3FDA0ULL, 0x1B51B8F7C6674C02ULL, 
            0xA25EC39A5F8EA35AULL, 0x462E4414AE0E5D15ULL, 0xE89D235482B7E558ULL, 0x7FCDEF819C6CC936ULL
        },
        {
            0x6E30528B6086D7E0ULL, 0x5B010FBD8F278B23ULL, 0x518D19F5360D9606ULL, 0xD21A344C9EFF4E07ULL, 
            0x443C098505B75704ULL, 0xCE5855FA0FA4B123ULL, 0x04127692F5F0F39FULL, 0x120CC3330C6C604FULL, 
            0xBFFED17668448B78ULL, 0x79FF25970697E700ULL, 0xA2318676B4B3CE15ULL, 0x03EC128E0FED3EE8ULL, 
            0x3B7CB512EBAB82F5ULL, 0x81C77DE0078E65FFULL, 0xF106CB324A16AB3FULL, 0xFFC413980CA62291ULL, 
            0xD8CE9C585F78665BULL, 0x48AC331B52E47D4CULL, 0x3E39A0BB725674DCULL, 0x6B2DA4A793D8D30AULL, 
            0x66FB667E1DDBD4AFULL, 0x675AFB442579DF71ULL, 0x71BD51BA7DF0F5DCULL, 0x3FDFD62CD4325761ULL, 
            0x1CF0040E0EBE2512ULL, 0xD43D7EA3306472C4ULL, 0xF779A8951312CC16ULL, 0x288E8527756DED30ULL, 
            0x899CBAEF7886F31AULL, 0xC34A5683F9380C0EULL, 0x2254F32A608693E3ULL, 0xA94B5D69C010EF3CULL
        },
        {
            0x45B59B70844CE570ULL, 0xE485868A989EF0D5ULL, 0x4D4374C59CB79D5EULL, 0xC907C39EEE419BF0ULL, 
            0xAEC4B41DDAD7D91FULL, 0xFC8D67F152A23DD1ULL, 0xBCE1B126789FEC03ULL, 0x3C5C019B1F90DB2AULL, 
            0x8FD5D1A9D05FB42DULL, 0xE0684D1FFF0DFE4DULL, 0xE9AF2782482E0309ULL, 0x9891486F16A30F43ULL, 
            0x5700F45F637A1580ULL, 0x977C96F30DFD92F2ULL, 0x863A5EF25A715FEFULL, 0x3457E0E3BB8C7AF6ULL, 
            0x45A56DA1D46FF877ULL, 0x2683363203A6BA37ULL, 0xABCCF788E871CABAULL, 0xD5291667AE259EACULL, 
            0x4E9405AA8F17F676ULL, 0x27ECFB0F72D8195BULL, 0x76058D4D1861EBACULL, 0xBC8F8474C097ECA0ULL, 
            0x2E014B9D0F157017ULL, 0xF4CD7E3AF51224CFULL, 0x80323F41B77E6DDEULL, 0x9E7D00FD71A2EB11ULL, 
            0x47959567CF77D009ULL, 0x2D434A46B52F7C4FULL, 0x94E51E2F0EDA3E51ULL, 0x2221BB30987CFBC9ULL
        },
        {
            0x1140C4D49A52952AULL, 0x094BB599E64E3FDFULL, 0x84AC13F5259A187BULL, 0xFD672BE97463C021ULL, 
            0x64497C8D3DA7E9ABULL, 0x8B9C3DC4E07657B7ULL, 0xA8CEB69677D60229ULL, 0xD566BA2C5E990863ULL, 
            0x954EA0D50BD73372ULL, 0x44DC25F98055DE35ULL, 0xC27D538641D9D73BULL, 0xCF30D73DDF46DA92ULL, 
            0x9F21828C869A142CULL, 0x43B4659BE3C01BFAULL, 0x6016696C0517F637ULL, 0x12585ED5BB8FE2F5ULL, 
            0x29DE524B67E9CE8AULL, 0xBBC8162D9EAEBF48ULL, 0xE2B4314BAB84D7F0ULL, 0xC104F76B3A685281ULL, 
            0xC8CF353DA9440265ULL, 0xB7A20E2FF1D1FA82ULL, 0x5DC1CA1DE8CA0BB6ULL, 0x89B52D9548755887ULL, 
            0xDF78E83DECFF4880ULL, 0xDB0CA990018A5AB1ULL, 0xC3FD50CE9C3DE739ULL, 0x3FB1CE8B841916FCULL, 
            0x40925BE9A199375AULL, 0x9BABAB49E8A1FEC3ULL, 0xB40282495E56055BULL, 0x2D7D4836D4EEB383ULL
        },
        {
            0x723C6C33513DFD0DULL, 0x7B130B33FA09E89CULL, 0x96CC88FCC6F5EF0AULL, 0xCF7B6CF57A6567E2ULL, 
            0x87A286CE0012361BULL, 0x1853FC50C245B810ULL, 0x8099187F8E1DC916ULL, 0x068CDDE9BE50DDA3ULL, 
            0x7D8F63A4E08DB427ULL, 0x632EBD0EB1A0D97AULL, 0x4B3F8380A6D1522CULL, 0xFF07990484DBCB33ULL, 
            0xA9373183835D4B9FULL, 0x8EB87210A2117DAEULL, 0x44F87617A171202BULL, 0x51ECC05BCBF89C67ULL, 
            0x4635E4413B6786F1ULL, 0xBF8E1769638DF369ULL, 0x6F8A6C8E8E804CE7ULL, 0x309CDED30DBEF6FEULL, 
            0x0F974FF6C14BD199ULL, 0x86FCDFF710BB3D5CULL, 0x0D2EEB473E60A2F7ULL, 0x06A17B3ECB42AC6CULL, 
            0x1DD4938E3150A5B1ULL, 0x39A8DE17FB50B6DDULL, 0x767A8A63FDA8117CULL, 0xA7B1127F4DE5F617ULL, 
            0xC1D212F738983823ULL, 0xEBD389D19444871DULL, 0x2AEABE7D43966E00ULL, 0x76F1BB8E15338971ULL
        },
        {
            0x45442A62D415F486ULL, 0x02615322C7C9EFA4ULL, 0x1866137658499170ULL, 0xBA5FA8D9C8C2D1F0ULL, 
            0x42AF2706F46F8552ULL, 0xED53D595051F9FC4ULL, 0xA976208C1ECDF6A9ULL, 0x664EC3044DEDF535ULL, 
            0x30A60E8D24893290ULL, 0xC87F31F42D711673ULL, 0x5F762E196F78283EULL, 0x0A924E24A3B7BB00ULL, 
            0xB86294A94C3B5ABFULL, 0x99521619420D045AULL, 0xBE2D45A3EF0591D1ULL, 0xDF2FCCBC107243C4ULL, 
            0x0F015B47B2D2BA75ULL, 0x40E86402708E8AC6ULL, 0x84278C328A943BC2ULL, 0x46583B4701FEC20CULL, 
            0x559D516624B28069ULL, 0x0176815588D4A3FEULL, 0xEB287FEE6C8F1675ULL, 0xEA84E7F3E4325397ULL, 
            0x9D5574E4982AD64AULL, 0x8D4A68D89A38677CULL, 0x518C57CD97DC10A0ULL, 0xD3D6F4193F0199F5ULL, 
            0x61A76A9BB6135CD2ULL, 0x221A54CFC77664E0ULL, 0x09D6EAE0447CC925ULL, 0x856DDF794A0AEE6FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kSeedConstants = {
    0x5FF044E250D31199ULL,
    0x52876FF12A1CE45DULL,
    0xE19D605CA924A313ULL,
    0x5FF044E250D31199ULL,
    0x52876FF12A1CE45DULL,
    0xE19D605CA924A313ULL,
    0x022C0DB1D81539A2ULL,
    0x3ED8416A1C11A8D1ULL,
    0xCF,
    0xA8,
    0xED,
    0x05,
    0xC2,
    0x8C,
    0x2D,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Gemma::kTwistSalts = {
    {
        {
            0x3D7C95CE0F02D15DULL, 0x7EEA40D60687E305ULL, 0xA8DA2CBFE0F4FE13ULL, 0x7B5BE711195DA679ULL, 
            0xF64595914B12CB41ULL, 0xD66491C9DC0D9731ULL, 0x0974FC111F267084ULL, 0x5901A066A32E633BULL, 
            0x95011A761AEC6C85ULL, 0x6749FD6E7E7AB4A0ULL, 0x055CEDBA26721618ULL, 0x95425CDDE6899708ULL, 
            0x0E61F2A780FE00FFULL, 0xC9900A0E653D9AC4ULL, 0x5E27144BAF19362EULL, 0x8B27AE543B8C7E7FULL, 
            0x3B35EDAD99AB5901ULL, 0x67D9703C633FA114ULL, 0xBB12AFF7F85494DDULL, 0xAA5013B789DE300EULL, 
            0x4FD62637D9593962ULL, 0x0356A0EC15D11E9AULL, 0x89307B14228AFD72ULL, 0xF4DAEC513523DF8CULL, 
            0xBF60A4FD2DA0C027ULL, 0xD3E1A7264345B6E2ULL, 0x3CFC30A8D88D49BDULL, 0x40ECB4BEA9022D7FULL, 
            0x9254D880019C3F19ULL, 0x88976666F453BFE0ULL, 0x76EB537E03C8D68AULL, 0x122CC1299EA53826ULL
        },
        {
            0xFFD8CDD056D73F39ULL, 0xD9DFC96C5A1C572BULL, 0xEAA20B350C9B0EAEULL, 0xE76C6EBB2C48A155ULL, 
            0x3BF02C9AC6386BDEULL, 0xC9A7ACE2A3950A5AULL, 0xCC4047D74C5BF307ULL, 0xEEB9622946AF7967ULL, 
            0xF09417A2F13ACDE4ULL, 0x86893C4CA6EFE153ULL, 0x886E202481A9F3CCULL, 0x5A07FC12154B92F6ULL, 
            0x2CCE6BCF4934CE72ULL, 0xCB4991A4EF82A661ULL, 0xBC7385A4D3C6F2E6ULL, 0x33F510CE887ED975ULL, 
            0x0001A5E022E95B78ULL, 0xB8AFFB8365148815ULL, 0xB2A1555CF826BAA4ULL, 0x41BF9DCF1C91F942ULL, 
            0x2FA7B968B8F758A9ULL, 0xE0533DB153E5D645ULL, 0x859D31BEFEFC8E11ULL, 0xB618B9E415FF9DBDULL, 
            0xE9E5906DA6232024ULL, 0x1937C670CDFC7BB4ULL, 0x98FA70DC7EA1A187ULL, 0x1E96A128305A0382ULL, 
            0xE6E1785105496774ULL, 0xD6294427A9B22730ULL, 0x84B652047B1BDBF1ULL, 0x33605981CEF585DEULL
        },
        {
            0x30E2E4F82B5EB90CULL, 0x7A7460BBB22A0E31ULL, 0x262D34237FC53E99ULL, 0x49CBA18CD9FE4319ULL, 
            0xC20D600F22E2EE06ULL, 0xD48587EB0DCED071ULL, 0xA57A5F4AB9313699ULL, 0x13EC1F1665F75792ULL, 
            0xC0C819475BA57022ULL, 0xF6829668300B0633ULL, 0x4ADBFE905AFAEE00ULL, 0x957E99607D3C72F5ULL, 
            0x59231ABC048A3C53ULL, 0x0D37B8825BFFC0D1ULL, 0x4C4FA84E92107AE5ULL, 0xA096479A4426A268ULL, 
            0xF97B7C804CF53C9BULL, 0xE59AB5B3F1CB65E0ULL, 0x252A121A5C492154ULL, 0x57B6D5B39F351E1EULL, 
            0x918FF27F3EED6DB5ULL, 0x83DF3FBC386CF195ULL, 0x6B764073DC39D7DFULL, 0x6487553DCF748B87ULL, 
            0x2F876E45A8DC8A54ULL, 0xB919B50E232F71C0ULL, 0x542B6F7B0FC86C6FULL, 0x6EC0C9AA4B1A2CC7ULL, 
            0x03A45A571C70AC52ULL, 0xCA241451A91F2C08ULL, 0x4DD7C6C707DC7C34ULL, 0x327B1DD6C2B88713ULL
        },
        {
            0x972BCDE98F80083CULL, 0x38056EBC198A13D3ULL, 0x7299801435DC472AULL, 0x9CC73156EB7528C3ULL, 
            0xC720DEE7564548A0ULL, 0x806F09A259CB52F2ULL, 0xB3E8895471FD9F38ULL, 0xFFCB5F7528E51691ULL, 
            0xE3CAA3092592E1AAULL, 0x086AEAF8DFAC5E26ULL, 0xBAF9D2E93EE28961ULL, 0xA7C33F5F9A9E18E0ULL, 
            0xAB93CE902B8EC3D3ULL, 0xF440BC1F4B58C3CAULL, 0x712E6A5CB86F1CE8ULL, 0x5351D702784101ACULL, 
            0xE76DDE009F890E2CULL, 0xC521ED70A3D4663AULL, 0x9CDFD83368D0A510ULL, 0x01ABFD7A92000553ULL, 
            0x3F44826C4653225BULL, 0x45356308D64E6B90ULL, 0xFFA8A4C3C1F6E53EULL, 0x8CDE2F670DFAF691ULL, 
            0x005FCB97346CD5DEULL, 0xF762C7AA728FFD44ULL, 0xA7D29AC06DA96C25ULL, 0x906D2DEDAA9274F9ULL, 
            0x3A7DA1CDA00D3989ULL, 0x171A6A93E2FBCA8DULL, 0x666A8DB7B8EB902AULL, 0x306E1F29BEFFFE5AULL
        },
        {
            0xF4375D7EDFC889B2ULL, 0x3DC4FDB415F303A5ULL, 0x20E817A8FDA7B865ULL, 0xD7A5B71DEEF8DD72ULL, 
            0x6696BE139D418AF4ULL, 0x7D0833F769EAF8C4ULL, 0xD4E02E1E1E879987ULL, 0x6325F1E5FA0E6BBCULL, 
            0x8B17DCC9AEA4B6B4ULL, 0x92817D86AF455CC1ULL, 0x314727E1D253E3BFULL, 0xAD10060504E7548FULL, 
            0x5B4A72A0082FFEB7ULL, 0x3713174B576A447CULL, 0xC79B01550B9C8CC9ULL, 0x59831B91FFD470D8ULL, 
            0x78C021037925F521ULL, 0x61F682B2F873C6A5ULL, 0xCC7FD1FF7E1CD80AULL, 0xB59E30A5068A68D1ULL, 
            0xA998CF0E9C148A67ULL, 0x5F907B53E9354CB5ULL, 0x22A8D9DDEBE92348ULL, 0xE1765B811F7B29FDULL, 
            0x1E425EC52D0BF976ULL, 0x4ADC8F2D764DC3C8ULL, 0x842D83A561666554ULL, 0x8F1814DD99A015EBULL, 
            0x920FBE52009CBF16ULL, 0xA7F2771C4F85274DULL, 0xF0FF9461B04CA907ULL, 0xD7F5B6C5AFC77078ULL
        },
        {
            0x081A7C5E2CE3D68FULL, 0x2C8DB1BFC9E5E525ULL, 0x1FAA5F7BB1E665BEULL, 0x441674D4B4B165DEULL, 
            0xD69DC8664E259CC1ULL, 0x633587816F4A1948ULL, 0x703A408FE128956AULL, 0xC42E0B4EEDDAED21ULL, 
            0x1527AAE7B7A3FF95ULL, 0x67C80CFCE7A98FD0ULL, 0xEB133D8737D15BEDULL, 0xB6FB63C6405253C5ULL, 
            0xA726D74F65370A37ULL, 0xB1E167F0855FEAA5ULL, 0x3B1F8C98446C4F0FULL, 0x10C2E70DE10CA41BULL, 
            0x55744A9ADCD07D27ULL, 0x965E922373439027ULL, 0xEE61C49458534509ULL, 0xA59DEEDC4817ABB0ULL, 
            0x38484810CDF446D9ULL, 0x095911FC67BF8F13ULL, 0x536043972E107EFFULL, 0xAAEF0E901DE746EDULL, 
            0xE803511AFB964045ULL, 0xFECEF5AA0259BAFDULL, 0xB7644D93D745762FULL, 0xEA95BDB36FD390CEULL, 
            0x2A33398848939BBEULL, 0xB5940A3489D721C7ULL, 0xAAA7827160759DB7ULL, 0x2080AF5741D63E4BULL
        }
    },
    {
        {
            0x1F8925DDB147C174ULL, 0x5825FE8D3D1ED4F5ULL, 0x2383C956D516359BULL, 0xFBAD1C460749256CULL, 
            0x5CAD3BC64255B5F3ULL, 0x63403D462D8B2CD0ULL, 0xADA90C93C4F8AB34ULL, 0xD53E23F8DA2E5DA0ULL, 
            0xC73A5F4079B0F451ULL, 0x28855696752A94F2ULL, 0xE14BB077940EB322ULL, 0x8397C0ED299BAAA9ULL, 
            0x672E0877114DC571ULL, 0x1F08AFB847AD4055ULL, 0x65A3A67094E6896EULL, 0xDBA4951D9CAE514EULL, 
            0x8FD8526632950D4EULL, 0x5A3C1B69227D97C0ULL, 0x7B0481487613480EULL, 0x1D7B49782EDB159AULL, 
            0x6E41A468B1AEFB25ULL, 0x04C127BE7D6C8CCCULL, 0x9493034C24BA4170ULL, 0xD6937AAA95EF8F20ULL, 
            0xA92C9811D89C9556ULL, 0x1D641755667FC943ULL, 0x1BC5382023203707ULL, 0xA612029158B57E4DULL, 
            0x4496B5A9909964C9ULL, 0x5C73D30376659075ULL, 0x3DC2A2BACF6D67EBULL, 0x96D88C834B851D99ULL
        },
        {
            0xC64F9B2B2BBC2871ULL, 0x888219BE3ECA14F9ULL, 0x4ED960ECE12875EFULL, 0x85B3BD67C70C8660ULL, 
            0x8815BFE38E7ADD37ULL, 0x0157A7CD80A92731ULL, 0xDD2EF21FC2ECE86CULL, 0xC0AF37DD826E52D6ULL, 
            0x0D59590A5F6230EDULL, 0xDE227C4DF08A61DBULL, 0xF5B4E5566BDB8F42ULL, 0xD09E72CB815EEE48ULL, 
            0x37DA24331F9DFCC1ULL, 0x9F8CB615BD748903ULL, 0x79B5C21ADE504B3AULL, 0x4C406F9EAEDA05F1ULL, 
            0x3567E03FD3170666ULL, 0x614122D9F58CCC4DULL, 0x4AE392D4CA7FB199ULL, 0xB9C1682DA5E49F6CULL, 
            0xBB5230C50DE12F48ULL, 0xAA4A3BBEAA13B7C0ULL, 0x2885355766F27B4BULL, 0x0D53FDFB94218C69ULL, 
            0x218CF2E70F6DE447ULL, 0x0289003169DD6F73ULL, 0x0054ECD9C6F58C97ULL, 0x4BAC2A36928934E5ULL, 
            0x301A92AB0071C8DEULL, 0x17E3921BCC4DE993ULL, 0x387A61BB79406AA6ULL, 0x4E8BC3183B80E8D3ULL
        },
        {
            0xCA6C6F453F392BA5ULL, 0x4EB88A36AD585B2BULL, 0x3AF6DD8DDDBD3F2EULL, 0x90F5991FEC816DA8ULL, 
            0x319C73680FEB7C62ULL, 0xDDD335BC8911BA54ULL, 0x4242C6C56A1E9780ULL, 0xA440B4076101D23DULL, 
            0xFBE6476A673ABA68ULL, 0xA808D16623A4AD95ULL, 0x692356577472A008ULL, 0x638C7CD0C53019C2ULL, 
            0x2114456A0D0DE794ULL, 0x2A4FF6BBEDA37F11ULL, 0x1D37DC8848E30685ULL, 0xE5FF60719E621164ULL, 
            0x6347E8C076974FF0ULL, 0x446CB0FAB229560EULL, 0xDA0D905AC24D5A96ULL, 0x8A6F28C18B9023B2ULL, 
            0xB1FCC6936985E30CULL, 0xE6245CE958417357ULL, 0x10F6D6203E0177AEULL, 0x465C27305515A94EULL, 
            0xF9BB7E996F6F7020ULL, 0x34624068DB241ACEULL, 0xFAD73FF09C5B508CULL, 0x7BBDF353B6BA7C11ULL, 
            0x44EA50109236E954ULL, 0x6242B5EAEBB2C896ULL, 0x5C77592D57189CEFULL, 0x383FDDC518E3D30FULL
        },
        {
            0x6C8BD48ACF4D124CULL, 0x74DD1A1DA3B4B119ULL, 0x6DD553D85CBAA2EDULL, 0x3307FC5AE1C8E221ULL, 
            0xB862ED5E001D4CE0ULL, 0x8FE91DDC4D4A9A8BULL, 0x22C1490A07CA6A57ULL, 0x068A67288543034AULL, 
            0x10627C5A40EC25D0ULL, 0xF35C55B20931E17AULL, 0x3EA23B0B788D4AC9ULL, 0xADB66E9E7FBA9F03ULL, 
            0x02EE4E3A6754BEE9ULL, 0x4609E38A4CEA9139ULL, 0x702CC6EF8040B878ULL, 0x05D112B3F9AB58D0ULL, 
            0x61CE8273363C6EC9ULL, 0xD16288370FC50438ULL, 0x97B5F33106A9A6F8ULL, 0x79CB73363320E044ULL, 
            0x70B2480A9B72E559ULL, 0x9A849D32911F0DEBULL, 0xE1CCE9E004DBF5D3ULL, 0x16856EFA87D8BB5BULL, 
            0x8618AF358F12BCECULL, 0xDC4AA5CDBF9F6C64ULL, 0x2998E6BBAEC8E758ULL, 0xB4C33F9926FBFC4BULL, 
            0x7E9B03BE393F5DBEULL, 0x7BFF4C19A59076F5ULL, 0xFF6CB1E309F6AA9FULL, 0x2773DD613119E12BULL
        },
        {
            0xC154424A80B5956CULL, 0xA643D0FFCE6237B9ULL, 0x71A22905A49B3842ULL, 0x548F4E5CB1B3A2D4ULL, 
            0x1EEE6A236D4B7FF4ULL, 0xA92F0FE0B649D2BBULL, 0x6B81C33F4DCEE729ULL, 0x5B2D5202C560DDE3ULL, 
            0x508609A4EDD94726ULL, 0xA101DA01219224C5ULL, 0x124C7F0469159922ULL, 0xC9DF8F30FBBF5A87ULL, 
            0xA965BA882E785641ULL, 0xA73BFE3D2FA316F1ULL, 0x7E8AC752FB7ED74EULL, 0x42A4FFCA0FE41C8DULL, 
            0x4345D1F7BA1BACA1ULL, 0x7EC8748430C7820CULL, 0x147F1B26E5229953ULL, 0xD9DB86D4884DEBA7ULL, 
            0x6B36F47028C171A2ULL, 0xB576FC9C599CC2F8ULL, 0x341C857041DA4A20ULL, 0x1F284AA1EF8C49D8ULL, 
            0x4CEE981E690DD048ULL, 0x95658D76D249AC61ULL, 0x29701A096A609FC3ULL, 0xE22D4D7AD113F011ULL, 
            0x01918FF8320EE946ULL, 0xF4A16BABFA75AA6FULL, 0x72EAC8D0ECE3F309ULL, 0x8EDFD7B404DE6C63ULL
        },
        {
            0x281A73628EFD22DDULL, 0x2D09EA6D078C01F2ULL, 0x23C3FAD76E19A644ULL, 0x01B1F9DFF585592CULL, 
            0x1B312B55F7841D98ULL, 0xC2ED5DAD2C8EE437ULL, 0x7779E3D586BD3DA9ULL, 0x1A53C094DBDB48B6ULL, 
            0x37FBA9D8B0F2AA68ULL, 0x67FAAD2426001EB7ULL, 0xC0592FF5A2D333D5ULL, 0xA98DD7707B9F5349ULL, 
            0x6F2CBBC56B79DD55ULL, 0x409D2D93407FA9A8ULL, 0x3D1020CFE38290F9ULL, 0x0B53BDDAA614A5E3ULL, 
            0x676FC04168C562E0ULL, 0x5325A287C4A0B492ULL, 0xA4CC1CCFB2BD46C2ULL, 0xA34CEBA0B16557C0ULL, 
            0xACE6C5EF2E8B378DULL, 0xD0C77C9D5FA7DF77ULL, 0x56826541682E409CULL, 0x86B50B7132029F7EULL, 
            0xB993B46419E84ECDULL, 0x3F73096A2BFB505DULL, 0x9648F2C553B830ADULL, 0xD64ED3E2859855BAULL, 
            0xE0177FBC7B795DDBULL, 0xAE83D0C9C2E22219ULL, 0xDD81DB8C9A8422E2ULL, 0xA5B42DEE52BBA0E6ULL
        }
    },
    {
        {
            0x84D475D5B680C9F0ULL, 0xE879CD2439FE560BULL, 0xB99D2BF726D9BDC6ULL, 0x7C62D1B709DD3149ULL, 
            0xCC447F67D9D85ED1ULL, 0x16B5BA09B1A9C063ULL, 0x4A6C4AC63BC48000ULL, 0x7DEA32B038B61645ULL, 
            0xCFAD5A85A4ED9363ULL, 0xC62B595B0C9BE957ULL, 0x410CC04A9199FAB5ULL, 0xA391757F5ED7AF0EULL, 
            0x194685D4E975FD49ULL, 0x6BF56D8A2AB9A372ULL, 0x8B5C15C242A91EB9ULL, 0x974CF9637A947DBAULL, 
            0x7A7598B92474E310ULL, 0x50C73F4A647744CDULL, 0xAA3DC1CDF913C1D1ULL, 0x147E1D07730CC29CULL, 
            0x39F8306865517335ULL, 0xD009FE3CB382FDDEULL, 0xEB851931320375F3ULL, 0x7F7AAB5CA0CB21D8ULL, 
            0xDE344560F8EA0301ULL, 0x4BACD80D6CA09657ULL, 0x12CA7206D230D0F6ULL, 0x327FC82B42701262ULL, 
            0xE56E5747198EAD3DULL, 0xA210294E574A3FA0ULL, 0x694EAE1E50DEDA34ULL, 0x2B65DDF664DABAC9ULL
        },
        {
            0x47E384AA058E6A20ULL, 0x6441ED1B8CC06FE2ULL, 0x87BE1C71D5CC28CBULL, 0xB83862A4D51835F5ULL, 
            0xAACA8EDC88DC9B4CULL, 0xD356CB9F2B03FF16ULL, 0xA0D9E67E3E65196CULL, 0x7374DC3069066505ULL, 
            0xA84337E0F432AA24ULL, 0x66A8ABD70A1C3CD4ULL, 0xB069C28313FE76BCULL, 0xD2AB02B965834C97ULL, 
            0xCF5A5DD7BFB13F03ULL, 0xCC912D300868C043ULL, 0x7D84B3154085AEA4ULL, 0xB2D6293F1046234CULL, 
            0x576FD220D40E06E6ULL, 0x31CFFF4CECF05057ULL, 0x1B6C9F4FDEB1152DULL, 0x3A3E2D85A52A596DULL, 
            0xC5A328872D4A37ACULL, 0x58493C29A409BE52ULL, 0xAC056F75152C9335ULL, 0x752DFC43E9480602ULL, 
            0x163E9C1DEBD28863ULL, 0xFC995122D6E49F49ULL, 0x61BF4E57B27C34B1ULL, 0xEE59D98BB7765E15ULL, 
            0x020AAC82F695A5D6ULL, 0xB00D86AD236E6114ULL, 0x8C07944BE5184E0CULL, 0x5C42D6E042C83881ULL
        },
        {
            0x27EDF9F246A38DF4ULL, 0xF5A9CB1B8330BCBBULL, 0x8A9A10BBEB0297B3ULL, 0x707F1B9C00143180ULL, 
            0x4B5BEE87FFE222E3ULL, 0x0CA8F8FF7F224364ULL, 0x601B3DD87B8D2914ULL, 0x6DC3983C9D849670ULL, 
            0xA20A57B254420B44ULL, 0x9ABC817012027661ULL, 0x713CCA81EFBDD238ULL, 0xA81499D691D0D970ULL, 
            0xBDECEAC6BFF21869ULL, 0x7DC23D6AF83E4722ULL, 0xCBAE81A0D8460181ULL, 0x775EEFACEE5A2F84ULL, 
            0x300D684BE4E9A0E8ULL, 0xB42EA6723EEB318BULL, 0xE29B2AD4BF210D2BULL, 0xB7CDF4234D28B9CFULL, 
            0x4C0D40489040B3F5ULL, 0x9777EE08FB54FB6DULL, 0xA7E55A30C857B716ULL, 0x9DC02B6362C6AFD2ULL, 
            0x7C5C3525DD18D439ULL, 0xF3ED280EF542A033ULL, 0x9E6384F8746D11C2ULL, 0x034B76647FB99A4FULL, 
            0x253AF73BC6A38435ULL, 0x23DF8DD8FD7E9A28ULL, 0x825FAEBA7DCB10B2ULL, 0x20336AAF8AB7301FULL
        },
        {
            0x7A17E4CB70F9C9C6ULL, 0xE139BD158A1160BBULL, 0xFF0DB71F0F394013ULL, 0xA3BD5B14B425DF76ULL, 
            0x07A9CD31B9E7FAA0ULL, 0x792965350B80ED80ULL, 0x9653215623274567ULL, 0xCE7C9CB9CAA100D6ULL, 
            0xA4BCD3BFF0F335A9ULL, 0xFAD888AE93BF39B2ULL, 0xE1CDC89EDAD02EB9ULL, 0x009086DA66811955ULL, 
            0xF9702A3C8B9A65A0ULL, 0x84F6A349E3C14190ULL, 0x5B5610641BE7F1CDULL, 0x71A7F2D43E144B92ULL, 
            0xAA2BCF955FF6E764ULL, 0x47E1DE6DBC5C582AULL, 0x8D57D72A003BDE6FULL, 0xF7F3022F85C9D422ULL, 
            0x13D5DF21305CB496ULL, 0x13FD786C9790E6FFULL, 0x46D90D6D9275575FULL, 0x033411AD1AF886A1ULL, 
            0xD4070C417FFBB3A2ULL, 0x7D8A2A5C92A212E4ULL, 0xDB70B598FBB0FFCAULL, 0x8791BC1B4E163E9FULL, 
            0xD1F1B2166701492FULL, 0xF505BDF689BE6A41ULL, 0xBC84D66E5C6FEFF5ULL, 0x60E12FCB854DC909ULL
        },
        {
            0x09AED1AC8B45E983ULL, 0x9DF6E9A020372F61ULL, 0xFC25BA477A0CB882ULL, 0x78E3C7402F081403ULL, 
            0x5CF9A12D8F97BBBBULL, 0xD95E0292C7A551AAULL, 0x1CE094E9EDF72A9BULL, 0x287E6A2E25EB985BULL, 
            0xD2A159279276777AULL, 0x64FD56B5A6E97F16ULL, 0x8877E6552316F508ULL, 0x676AE48B3C5270B9ULL, 
            0x7802740AC4308793ULL, 0xFB0604D2595DAE7DULL, 0xB150A9F8F6FDE4BBULL, 0xCF3C533E24E274C8ULL, 
            0x5D6C9F657FEB60A2ULL, 0x3E94B6B44DE71972ULL, 0x87B6CC7BE615D1DBULL, 0x90C648693FDA02ABULL, 
            0x9224562DB41F5B7FULL, 0x7924E717D85AEC50ULL, 0x1A81284E544755FDULL, 0xEC5EBE0AC6D82173ULL, 
            0x49AD8F5C4313F84BULL, 0x3BD495828F28727BULL, 0xC03A2B5564B3D877ULL, 0xA5251A5CA7712CA5ULL, 
            0x70C6E230625ED766ULL, 0x3B0BCBB119F3F381ULL, 0x3F23F28C16949283ULL, 0x9D38F88D116A3B3DULL
        },
        {
            0xCA21E4A3B0641261ULL, 0x1ED1770A95D36E65ULL, 0xEC4CA5ADA310D947ULL, 0x0ACAD0E732DF203BULL, 
            0x31398269E2CE1EB7ULL, 0x0E083059C9066F34ULL, 0xCD80811C7133D8A3ULL, 0x877D762808ECEF1FULL, 
            0x7274F2B00582B1BAULL, 0xEDA6DC2F71270945ULL, 0xAC149FDA5C60CCF7ULL, 0xAB3A7EFFB608AB9DULL, 
            0x5F5B32A5787CDB45ULL, 0xABD65206CD715308ULL, 0x5BF742DAB6576918ULL, 0xAF7BAB5A5760F1A4ULL, 
            0x7A37C90BFED2E60BULL, 0x00B0EA5B6433E619ULL, 0x3513D8C01BF2303BULL, 0x74FC784EC3FF1DBBULL, 
            0x687B3DA5F5617784ULL, 0xE4D598717A56059DULL, 0xFFF330264DE90CCEULL, 0xE7D9AE6B8F4F37F1ULL, 
            0x73D12EFC0135D163ULL, 0xD5944C1ACFADBC3BULL, 0x88ABDC0CD945E28BULL, 0xA186507D05E393FEULL, 
            0xB6875362B45CCE53ULL, 0xA7CC4AF72AC98315ULL, 0x6764FECD3FD23917ULL, 0xC769C675F1DD42BCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kTwistConstants = {
    0xA73ADDB3A4ACBFE2ULL,
    0x134D8EBC8CE81922ULL,
    0x367105BD03891EFBULL,
    0xA73ADDB3A4ACBFE2ULL,
    0x134D8EBC8CE81922ULL,
    0x367105BD03891EFBULL,
    0x4C9EA628E511C636ULL,
    0xC5B71291E49F86BAULL,
    0x60,
    0xE6,
    0xB5,
    0x57,
    0xDB,
    0xB1,
    0xAD,
    0x0A
};

