#include "TwistExpander_Saiph.hpp"
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

TwistExpander_Saiph::TwistExpander_Saiph()
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

void TwistExpander_Saiph::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x92DE3144E6923D22ULL; std::uint64_t aIngress = 0xC0F1F07D2D9EA59EULL; std::uint64_t aCarry = 0x85C011C9F3A3FA39ULL;

    std::uint64_t aWandererA = 0xED73037B02E0CF55ULL; std::uint64_t aWandererB = 0x85B341834494BBF0ULL; std::uint64_t aWandererC = 0xDC61AC010B159ED4ULL; std::uint64_t aWandererD = 0xDB572B763A586646ULL;
    std::uint64_t aWandererE = 0xDC313FC52614CD1CULL; std::uint64_t aWandererF = 0x8B6F8248CDEBFF99ULL; std::uint64_t aWandererG = 0xA44A7A1829D10237ULL; std::uint64_t aWandererH = 0xF9866F67F47C1AA1ULL;
    std::uint64_t aWandererI = 0xC53DC8E00CD47201ULL; std::uint64_t aWandererJ = 0xC32D923C77631938ULL; std::uint64_t aWandererK = 0x8E18B2D1E09130FCULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8E3A57FAF778751DULL;
        aCarry = 0xCC8B3FA0C43DAF6DULL;
        aWandererA = 0xADEBDBA8D6E7205CULL;
        aWandererB = 0xEDA83138F00C9EEFULL;
        aWandererC = 0xADFDC5FF03551797ULL;
        aWandererD = 0xD5555AC3B8DC6819ULL;
        aWandererE = 0xCAAB6137A0C0A615ULL;
        aWandererF = 0xFEF85CC2A14DA5DEULL;
        aWandererG = 0xAE0834A4D4E8210EULL;
        aWandererH = 0xBCA28B40CE783479ULL;
        aWandererI = 0xCF2F96776E62F728ULL;
        aWandererJ = 0x8E69380387D4797EULL;
        aWandererK = 0xFE6A05F24D11B0D4ULL;
    TwistExpander_Saiph_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEBC9CA3433ACD4C2ULL; std::uint64_t aIngress = 0x9F15C89D7874AAF6ULL; std::uint64_t aCarry = 0xD617792C60AABD67ULL;

    std::uint64_t aWandererA = 0xAE56B30768E08B6DULL; std::uint64_t aWandererB = 0xFBE41032BB1E656FULL; std::uint64_t aWandererC = 0x90B6760D4037719EULL; std::uint64_t aWandererD = 0x8CB8075F556F977BULL;
    std::uint64_t aWandererE = 0xE306F22817651CE6ULL; std::uint64_t aWandererF = 0xF404D904B1BAE39BULL; std::uint64_t aWandererG = 0xED138409168F4DCBULL; std::uint64_t aWandererH = 0xEA324EA3D87DB518ULL;
    std::uint64_t aWandererI = 0xA52045099B32C35EULL; std::uint64_t aWandererJ = 0xE2F24FA45C59B0F4ULL; std::uint64_t aWandererK = 0xFA43CD2D1B7AEDCAULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFC9724D34D32EED8ULL;
        aCarry = 0xD8B26748148C31CDULL;
        aWandererA = 0xD65C7FC2018D9882ULL;
        aWandererB = 0xC730D6C90851CEC0ULL;
        aWandererC = 0x9E2ED1A7ACA8006FULL;
        aWandererD = 0xD59B85B5D459F3FBULL;
        aWandererE = 0xCCF9E23DB0F18782ULL;
        aWandererF = 0xB0AFB307A048FEFAULL;
        aWandererG = 0x83DF6DBDEA1C80A3ULL;
        aWandererH = 0xEAC783260C11A45AULL;
        aWandererI = 0xBA9994995F21A057ULL;
        aWandererJ = 0x8E0C7F792ED0BDB9ULL;
        aWandererK = 0x813F324D109B012AULL;
    TwistExpander_Saiph_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x93DDAEAF4DAA836DULL; std::uint64_t aIngress = 0xAAD4DEE21859E912ULL; std::uint64_t aCarry = 0xED97880854A2D386ULL;

    std::uint64_t aWandererA = 0xD6283A533F1FE3D5ULL; std::uint64_t aWandererB = 0xDA7CAF9097BB5BC4ULL; std::uint64_t aWandererC = 0x8B09ED0B901EE755ULL; std::uint64_t aWandererD = 0xF9FCF592EC5C669CULL;
    std::uint64_t aWandererE = 0xE28BC3E2AC7770B5ULL; std::uint64_t aWandererF = 0xE6323EA4608958F0ULL; std::uint64_t aWandererG = 0xEF78A7BD800D9A42ULL; std::uint64_t aWandererH = 0xD146A304C6876233ULL;
    std::uint64_t aWandererI = 0xC42095E78562E8BAULL; std::uint64_t aWandererJ = 0xB043F8C3E48AA848ULL; std::uint64_t aWandererK = 0x9357F5819A59B8E7ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA71EFE2C65027B23ULL;
        aCarry = 0xE4F6E35679FA38E6ULL;
        aWandererA = 0xD8D2E1A5675ABCA0ULL;
        aWandererB = 0xA23C8FE2CE46143DULL;
        aWandererC = 0x800487667F10157CULL;
        aWandererD = 0xA1680A0EE1356B43ULL;
        aWandererE = 0xA950DADEA89D7BE7ULL;
        aWandererF = 0xAC9E8F8F0707CFA8ULL;
        aWandererG = 0xDF3AC5DE77EA2CE8ULL;
        aWandererH = 0x97173262F32F7BC3ULL;
        aWandererI = 0xBED2AD340F80F88DULL;
        aWandererJ = 0xF6D3F023B628D4B1ULL;
        aWandererK = 0xE3648D942327475CULL;
    TwistExpander_Saiph_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD98A2ADB000AA3E5ULL; std::uint64_t aIngress = 0xD5CED2DCC8BC14A9ULL; std::uint64_t aCarry = 0xE03F8C1FFD41D9CCULL;

    std::uint64_t aWandererA = 0xC9B441950A314281ULL; std::uint64_t aWandererB = 0x87F2389EEABE08D6ULL; std::uint64_t aWandererC = 0xE2396A69D7C5B7E7ULL; std::uint64_t aWandererD = 0xA81CCBB3148D69F3ULL;
    std::uint64_t aWandererE = 0x8657EB8C737BDE9FULL; std::uint64_t aWandererF = 0xA977977ECFAFCC7CULL; std::uint64_t aWandererG = 0xC2AF601985790712ULL; std::uint64_t aWandererH = 0xFF401C5DA8A573BFULL;
    std::uint64_t aWandererI = 0xA356CAD9AC0133D9ULL; std::uint64_t aWandererJ = 0xA0E136A8FB3A5E33ULL; std::uint64_t aWandererK = 0xA0128D4B173D848FULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x995D8D50FD582423ULL;
        aCarry = 0xA01AB47152FC3959ULL;
        aWandererA = 0xCF30BD4447B8BF91ULL;
        aWandererB = 0xBAD030A4EAEDB9FEULL;
        aWandererC = 0xC49B108D7F416EBAULL;
        aWandererD = 0xD33B59E8075FDEDBULL;
        aWandererE = 0xADDF7F2BAF946E16ULL;
        aWandererF = 0xDB591CC70CCD589BULL;
        aWandererG = 0xD42663EB4B21813AULL;
        aWandererH = 0xD87D74EB82EEA028ULL;
        aWandererI = 0x9AE9BBCD54E40C9CULL;
        aWandererJ = 0xE9BE79419C901C7EULL;
        aWandererK = 0x8113BE72119DC268ULL;
    TwistExpander_Saiph_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Saiph::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDD72AB5D0BD0735FULL;
    std::uint64_t aIngress = 0xA8D025BD6851F7F0ULL;
    std::uint64_t aCarry = 0xED3060009F6A3635ULL;

    std::uint64_t aWandererA = 0x9A216FD07399B2C8ULL;
    std::uint64_t aWandererB = 0xE83C4AFA7A47567CULL;
    std::uint64_t aWandererC = 0xA2A05A7E377C0CC1ULL;
    std::uint64_t aWandererD = 0xA47BC7C014540793ULL;
    std::uint64_t aWandererE = 0xBF8D6DF6CC5BECE3ULL;
    std::uint64_t aWandererF = 0xD3244B415362E2FCULL;
    std::uint64_t aWandererG = 0xA9E9DDDFACC31250ULL;
    std::uint64_t aWandererH = 0xC74026ECC76948E8ULL;
    std::uint64_t aWandererI = 0xEEB0B844EC1FD65CULL;
    std::uint64_t aWandererJ = 0xAAD95958DEEDA2F1ULL;
    std::uint64_t aWandererK = 0xBC6421A0AD74B6EEULL;

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
    TwistExpander_Saiph_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KEY(pWorkSpace,
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

void TwistExpander_Saiph::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA5E51D411A5AA486ULL; std::uint64_t aIngress = 0xE2445A22092F7C44ULL; std::uint64_t aCarry = 0xC7D65ADE37BA20B4ULL;

    std::uint64_t aWandererA = 0xB840BBC09930BD22ULL; std::uint64_t aWandererB = 0xC2AD636E3712EAC6ULL; std::uint64_t aWandererC = 0xEB573B5A869A22D8ULL; std::uint64_t aWandererD = 0xEE96833753DC5414ULL;
    std::uint64_t aWandererE = 0xD734E1377EFECE02ULL; std::uint64_t aWandererF = 0xDF89587982C4D79BULL; std::uint64_t aWandererG = 0xD5271B04F0B12ECBULL; std::uint64_t aWandererH = 0x85AD07CE359151CEULL;
    std::uint64_t aWandererI = 0xEC16C7B809521D9FULL; std::uint64_t aWandererJ = 0xDB4B48078A6466FDULL; std::uint64_t aWandererK = 0xAB6235CC6EC3E72FULL;

    // [twist]
        aPrevious = 0xED304B9CF24B28C6ULL;
        aCarry = 0x8516EC55788A7387ULL;
        aWandererA = 0xE959E391AF6F6248ULL;
        aWandererB = 0xA150434915B73AACULL;
        aWandererC = 0xBC7B73D336E2B9B3ULL;
        aWandererD = 0x98B6A618DE7E1124ULL;
        aWandererE = 0xA0E760ECCEC6AF05ULL;
        aWandererF = 0xC439FB54976722D8ULL;
        aWandererG = 0xB3497661459E0B2DULL;
        aWandererH = 0xC74E0CDB550CD839ULL;
        aWandererI = 0xE88CC077A45AFBC7ULL;
        aWandererJ = 0xEB980E8B252CDE5CULL;
        aWandererK = 0xC9B50FDBEC489860ULL;
    TwistExpander_Saiph_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Saiph::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Saiph::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Saiph::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 30 of 33
    // Exploration cases: 0
    // Structural maximin 509 / 674; family total 15505
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1555U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 30 of 33
    // Exploration cases: 0
    // Structural maximin 504 / 674; family total 15494
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1150U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 30 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1044 / 1248; total 31237
void TwistExpander_Saiph::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
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
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 30 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1044 / 1248; total 31190
void TwistExpander_Saiph::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
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
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
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
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
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
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
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
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
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
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Saiph::kKeyRotateSalts = {
    {
        {
            0xC99429EDB3CFAA0EULL, 0x30FA156C6972D710ULL, 0x537AF814DA0B6639ULL, 0x9F15D3218F279C36ULL, 
            0x933892009F96AB7FULL, 0x52F9B961748B2ACDULL, 0x42E702FBC8411213ULL, 0x569F320B86C2D296ULL, 
            0x29CFF057401235BBULL, 0x965BAB8F2BCD78EDULL, 0x62056BD06D03464EULL, 0x83E188B579490B33ULL, 
            0x3606D2638F687861ULL, 0xEDF8DB4530096EC9ULL, 0x1E4E7D74AF717C56ULL, 0x99748F5707D7D98AULL, 
            0x5C1DC91D989EC60CULL, 0xF162D9D89D2DA46DULL, 0x1B554EEFB38F8421ULL, 0xE62835F3FCE6B44CULL, 
            0x64BE67E67B3F2F93ULL, 0x338352ABD3DDDA69ULL, 0xF017855747B63817ULL, 0xB89E5690927BEFC7ULL, 
            0xA0061DCEE86E000CULL, 0xA7909599FFEDA4AFULL, 0xB53CE3881F19FE82ULL, 0xD94F81A88B5BBB49ULL, 
            0xD119E297BD9CA130ULL, 0x7C645A48C4870F18ULL, 0xD1E9B9E54AD50301ULL, 0x0B7DEBC90941F088ULL
        },
        {
            0xFF99A6EC62D70421ULL, 0x4B8C4BB79AA86BF3ULL, 0xEB9F1F43DCD3CAF8ULL, 0xF21173EF83A41B3EULL, 
            0xE6154AF0D0AAC07CULL, 0x5ED51704661289DFULL, 0x366BB670CABF81E3ULL, 0xC57F82E5C89CDD02ULL, 
            0x9271C45B93875549ULL, 0xDAE19D0B7B213AD1ULL, 0x4286FCCB6F22C470ULL, 0x7A3F8A5287221711ULL, 
            0x7812B90B8CAAC6DBULL, 0x6A8F2215A521429AULL, 0x25E9D4EC880ABC23ULL, 0xE68FC11EA878B736ULL, 
            0x729D86A24E673F3FULL, 0x458F76CAE8A53507ULL, 0x4BD51057C7C799B3ULL, 0x95775FFEF85B4807ULL, 
            0xEFFC182A117622CFULL, 0xB5634FFAB2129B60ULL, 0xECA08CBA8EA8E5D0ULL, 0x5F49BF9299A0C4ADULL, 
            0x9CE3902C24E3E4AFULL, 0x2674237F2AB7C667ULL, 0xB6C17BF2990B6722ULL, 0x6CFBB16064FCB3BCULL, 
            0xD6BFF827399289F9ULL, 0x7E075DE903C30429ULL, 0xE55884C99607EA33ULL, 0xBA1C656837BF0E59ULL
        },
        {
            0x4541BD74D51C69C2ULL, 0x6C914D3C40799649ULL, 0x2CEBFD8B16422824ULL, 0x576C9D0C21333D16ULL, 
            0xB00C2919155B22F8ULL, 0xCAC9DE8720AF0101ULL, 0x9248014D650FC59DULL, 0x78AD87CB1857A3D9ULL, 
            0x283FFB6D9330581DULL, 0x866778DFA368E498ULL, 0xB7A16833625D5805ULL, 0x0BBFD2DC016CE63EULL, 
            0x615D62C6E324D073ULL, 0x74CE846CE0406885ULL, 0x8CD90F747263E31CULL, 0x4658C28C595AC1F8ULL, 
            0xB981399928037A59ULL, 0x3303052770C42A91ULL, 0x0E433F6E534F369FULL, 0x3CBD2617A032746DULL, 
            0xF8AA0871D39C2DEBULL, 0x9DDE593CB5CF9996ULL, 0x0AC13A646DA79C9EULL, 0x0AA3303A451F5D5EULL, 
            0xEA4BD9EA29E61E30ULL, 0xEA676D834604E96EULL, 0xCB376C15FC1550CEULL, 0x66C837A829582B01ULL, 
            0xD012A30FF945A518ULL, 0x26E11D17BA894A71ULL, 0xFC48F82136D76DE3ULL, 0xFE586FFBDBE3CB07ULL
        },
        {
            0xD62D745F863C16E5ULL, 0x582915464147638FULL, 0x4EFD97F3492B1D56ULL, 0x3B58E3880DE8E4BFULL, 
            0x97DB77E6077A36A0ULL, 0x97716AEA972AC950ULL, 0xDFF0DCF862A1195AULL, 0xC0DA8DBA57C5676EULL, 
            0x649A5254955907AAULL, 0xBDDD31789037EB58ULL, 0xA686562F46DFD3ECULL, 0x354A3CE45086D2B6ULL, 
            0x2EE405D95967F24BULL, 0xE1DF9917A5FFF668ULL, 0xC0D4BDA714D3D6DFULL, 0x380234A273F38816ULL, 
            0x26586DDBACCDC70BULL, 0x6181628CBA960E0CULL, 0x21981579E3CFFD7FULL, 0x6FFBBC91AC7B0A47ULL, 
            0x6C0ED78632DABBC3ULL, 0x54ECC12668AC3BB9ULL, 0x8BAB32F22CC98FEDULL, 0x682BDD56E6DBE3B6ULL, 
            0x5DB15A20F842214DULL, 0x3E9498E5A2B36858ULL, 0x601A3C8D2CA1D316ULL, 0x1641CD9CAD480BD0ULL, 
            0x0C4506399C3C4C43ULL, 0x4B4A3047C1CE9363ULL, 0xAED6A7E9FD045EC3ULL, 0xE2F11B50479F6807ULL
        },
        {
            0x97B8D6D73D982C9BULL, 0xD2DE404ABC1B0CA1ULL, 0x64D015F9ACDEEC6EULL, 0x85C3059BF8463784ULL, 
            0x9FC21159F5120B32ULL, 0x2CD76BA2562B2ABCULL, 0x715B6E61A50CE07BULL, 0x20FF74E29AA51E2FULL, 
            0x707242CB25D9303CULL, 0xD4E7374936E1C1C7ULL, 0x0A37E90B7D046195ULL, 0x008FD4CF383E7420ULL, 
            0x099398F282CEBC69ULL, 0x704F49695B238044ULL, 0xB2F444EBC1CED64BULL, 0x2734A0D9A079C60DULL, 
            0x677C5C8B27C1A088ULL, 0x1D873DDF4C4BBD79ULL, 0x540706279F107F2EULL, 0x8A593F62A314D74DULL, 
            0x150B1AACF3C40C60ULL, 0x68E91F2CBFAC18D4ULL, 0x6A55ECFA1796E074ULL, 0xDF4A5FB8AD0F634FULL, 
            0x319001B6D4BC5E17ULL, 0x3A2470758FA649CFULL, 0x2CC10FBF2F120F70ULL, 0x707EDF82A54A7F28ULL, 
            0x1E74F3E8D9408FF1ULL, 0x4A24C771FFCD2196ULL, 0xEAC32CFDB894D11AULL, 0x3E12620D722850A2ULL
        },
        {
            0x32F2AD5FA1ABCE66ULL, 0xB4DA0B01C7E89D4CULL, 0xA6378879DD06707EULL, 0xC3ED358918357C1FULL, 
            0xF82E3D50CDF2B76DULL, 0x5BE65DCC26E229EDULL, 0x38D22C3831E7D8DEULL, 0x677D726AC1498989ULL, 
            0x405B4E4F2EEC2603ULL, 0x24F7893C69588697ULL, 0x8027FEB10DB6B1BCULL, 0x956C7B06C8027E96ULL, 
            0xBAEFB52546948906ULL, 0xBFE29B7F1E57DB02ULL, 0x36BEE0378D197274ULL, 0x05240533BAE4A21EULL, 
            0xE7390E7FBC2DC242ULL, 0x64E185BF114C4A24ULL, 0x417541D7B028BCF7ULL, 0x1F920146CB7734F4ULL, 
            0x25E1539CB3C32DB7ULL, 0x92C9E4A2D544CBAFULL, 0xF2DB2EE73F3CD92DULL, 0xA3274FB22667D4CAULL, 
            0xD64FAFA025E0A49DULL, 0x102F7BC76B4DF8BEULL, 0x6FC310AF5EE6D7D6ULL, 0xF38D3A688E2A8EC6ULL, 
            0x00EE25EF6742DB13ULL, 0xF74A3DD5BCE502E6ULL, 0x22082C2BDD33551BULL, 0x0CE0409B4AB7D97AULL
        }
    },
    {
        {
            0x1CBEFBCB335FA692ULL, 0x430706BC9EF13FD8ULL, 0x87F8BBF9CCF296CDULL, 0xEC3AB5836D7BDD06ULL, 
            0x6BFCAB11AE82400EULL, 0xC8D765808AEB1F0BULL, 0xB7B3FFF962F1B5ECULL, 0xE0095651B585610FULL, 
            0x5BE2D1AEBA302BA7ULL, 0x3110C8D5285DA659ULL, 0x25926FA2FA0AE0A9ULL, 0xD65F6EF209B1A9ACULL, 
            0x5ACDC753368DD048ULL, 0x2F6BDCF6B369AECAULL, 0x5086897FC29BFA1BULL, 0x73D6AC686A6C1C8FULL, 
            0xC0680C171B8C881CULL, 0xF6FA13AFE2544027ULL, 0xEFE57DD17905A5AFULL, 0x4CF07A7632571C63ULL, 
            0x92809CC4641FA26AULL, 0x7F1C52194FCB63FBULL, 0x699262AA34E43F18ULL, 0x830608B8FF7661BBULL, 
            0x9BEDE235D3D6A9DAULL, 0x37B4E0048C829AAEULL, 0xD2B7E06C463BE043ULL, 0x8490DD92F39963FDULL, 
            0xA721D26D3BDD2CFDULL, 0xDCAE3434D2BECE40ULL, 0x697689AF6B3CA0B4ULL, 0xA2C15BF9D3CBEBAFULL
        },
        {
            0x83CFB0434BF61FE1ULL, 0x4EE968E6D5BF56EAULL, 0x75BDDC0C735B5459ULL, 0x5A087C1F6902CE6BULL, 
            0x886409288B00F1B5ULL, 0x15F6EB220CCD00C1ULL, 0x2F6CF821F320FAD4ULL, 0xA05F606F1DD48CB7ULL, 
            0x3629D5224CC6E957ULL, 0xE6BD065AD1D54CF5ULL, 0x908A734E9A1FB365ULL, 0xAC367C9B4E484419ULL, 
            0xF48839172EF40F79ULL, 0x1AAFF0A349AA1ECAULL, 0xD47D92D4567B600FULL, 0x63DEF8436C778AC4ULL, 
            0xAF27FDD09562C77DULL, 0xAFDFB6721B055C5BULL, 0x944796532460912EULL, 0xD1D89747C6FF96F5ULL, 
            0x1B4407A68A877193ULL, 0xB539205A5E91B8E0ULL, 0xA57282FCB30B86C2ULL, 0x51AF012D844E15D8ULL, 
            0x2C627CFC935F86E7ULL, 0x98DEFE1883DD0716ULL, 0x47F8D78A7E9B94F7ULL, 0xEDE8FBD8D399EBA6ULL, 
            0x798DF9DB56C43D44ULL, 0x3F0559AE47758230ULL, 0xC8DFF024025097ADULL, 0x08D118174A96A11CULL
        },
        {
            0xFF7E6B2AAB57B4AAULL, 0xA093FBD92B6D7688ULL, 0xD17E26D223F4DB40ULL, 0xC1934B05EB077BC2ULL, 
            0xA6481C7381DE2456ULL, 0xC317157018F346B5ULL, 0x11AD43EA2F3CAFC1ULL, 0x6F8F1159FE329DDDULL, 
            0x9178C82CBABB67BAULL, 0x64217BBB9867C294ULL, 0xB978553B2C2D66C3ULL, 0xA8190602B5697485ULL, 
            0x4538D9D21C53B9CBULL, 0xD6B4A16EDBCC5B72ULL, 0x066C61AD0B0CEFF5ULL, 0xD154EE6F044AA3E8ULL, 
            0xE6EB3022FF3D5D3CULL, 0x2B1808D0EAD46C21ULL, 0x68806E4930AA3F48ULL, 0xF2B0064A7A5914D3ULL, 
            0xEA2A0D62A65A5A74ULL, 0x73F312077BC85733ULL, 0x09EEBCF98253390EULL, 0xB17A525F88F20A46ULL, 
            0x0B2FA31DF04A8518ULL, 0x47E57A1789F73C83ULL, 0xD63FCE9AEAFE21EAULL, 0x6B4DEFFB57D8F407ULL, 
            0xEEF21599083BB522ULL, 0xC7EF3955E51A5337ULL, 0xFEBFC3DA2A6A687AULL, 0xB121F99FDE76B232ULL
        },
        {
            0x6A6C30033D594477ULL, 0x48C73AF5193B86F4ULL, 0x303A61D3F8F50AE7ULL, 0x129A21A493BE4DC7ULL, 
            0x5122C80074731B6AULL, 0x2768B7CEBE82694CULL, 0xD803EE643C3E7831ULL, 0x46F42409378793C5ULL, 
            0x020A3536DA5D1055ULL, 0x3AA76CA5E845E783ULL, 0xEED0A319A57C1AB3ULL, 0x5719554BD83C52BDULL, 
            0x3771B6D24DD1D136ULL, 0xDCB2563299D7AFB4ULL, 0x43B9879CC6C888E2ULL, 0xF1C4B30C22D6F047ULL, 
            0x17745781F58ECF92ULL, 0x6AFC7B2D58198C46ULL, 0x5F547495DCBB464DULL, 0x0D72859C8EF52B2FULL, 
            0xA113C4C2BFB54C46ULL, 0x1496F1967F5ADB6DULL, 0x75E808F0B9FF9B42ULL, 0x40FBAA68591F2555ULL, 
            0x09ED5FC01AF91039ULL, 0x9BAFF9E5BF0714C9ULL, 0xC3ECF02766944A02ULL, 0xBB66DF8391259884ULL, 
            0x54BDE9296EE2CEBEULL, 0x00F4E0704CBCB39DULL, 0x690782E3B6353235ULL, 0x6D5FAEBA5D8A495BULL
        },
        {
            0x626442C4A755CF75ULL, 0xAD3205053D9A5C0CULL, 0x2B5B269BEF5527B8ULL, 0x853B3ECE03334626ULL, 
            0xFEFFA64037777091ULL, 0x184818DE3D6AA87CULL, 0x1734307878018688ULL, 0xF3D10050D1001AA8ULL, 
            0xA97054185F3162BFULL, 0x79CA5188D26DEEA1ULL, 0x192067B87C3D31A6ULL, 0xB0ADB40686CB68DAULL, 
            0xE690086DE63ACA37ULL, 0x91FD1947D2A511F5ULL, 0xE24BBC711C9FAF03ULL, 0xA256B0C665B22377ULL, 
            0xF07E8A821A55C08CULL, 0x8A70264119C6E6E1ULL, 0x2220FE78248A6F7EULL, 0x3F474FF81D1E73CAULL, 
            0x31F0D8C6EF00E88FULL, 0xD522D79A3C0CB731ULL, 0x326F5537AC98FC94ULL, 0x13E1C899679B32A4ULL, 
            0x6D742ACEAE29A59FULL, 0x4B5B8A280A1B8B3CULL, 0xBB6572E8E6639228ULL, 0xEC3E10F7F88EC75BULL, 
            0xEC0FFEE33A309180ULL, 0xB3AC840BAF5E29ACULL, 0x043C2AB314107D2BULL, 0xA2C1F49B57AA8576ULL
        },
        {
            0x2272012879E3B592ULL, 0x8EE58F57690797D4ULL, 0x254778ECCB26C568ULL, 0x9EFDB28DED009DE5ULL, 
            0x7365B5E8D1001378ULL, 0x985F04E605DF8E3EULL, 0x57901AF15EB3EBF0ULL, 0x190D354118241B9DULL, 
            0x1F3E33A3D2C2F6C8ULL, 0xC54DD47C892B0497ULL, 0xE3C7C2DB44B6C7D7ULL, 0x703764C966BA0D16ULL, 
            0x1BBC1FF2969E2C47ULL, 0x5BFEF62612884C2EULL, 0x5342762D3D000C02ULL, 0x8475A7C517A7B59FULL, 
            0x83EBBA05241E87F1ULL, 0xBA42D0228180DCE9ULL, 0x78283751EFB84A42ULL, 0x49A42CBF99C99F5BULL, 
            0x1C5A4D873A1E129CULL, 0xEBF27CBF05C50F25ULL, 0x9A9A7C3878431D93ULL, 0x2A371C1687D75113ULL, 
            0xF212B7BA2DA82413ULL, 0x372BEA83AF822DABULL, 0xB6A0BE02586FC20DULL, 0xFFF018FB9D5CD2ECULL, 
            0x083D4D90F9429E14ULL, 0x2371B1BF5CE9C997ULL, 0x485AD0982BB2AE08ULL, 0x5FC06453CC0EB1C6ULL
        }
    },
    {
        {
            0xF26AB9A6CFD62B78ULL, 0x2057407F18982A96ULL, 0xAAD492AECA051D5FULL, 0xB6C7340C8D361E93ULL, 
            0x73402A3CCFC02BE0ULL, 0x3C858191B49DF2B0ULL, 0xA4552BB4D59756C4ULL, 0xD81B659A555E782AULL, 
            0xD03E7D5E8499FD4CULL, 0xD4C80C7B7E808CFEULL, 0xC55659AC43FAF400ULL, 0x8CFCC047FF9B6872ULL, 
            0x178A9B1CEC970F09ULL, 0x3E20204CDAFAACB0ULL, 0xDCD4F02E2C7E8DE6ULL, 0xC298473D4158959BULL, 
            0xFF6DA8F6FEC75C32ULL, 0xA79882E1FADB551AULL, 0x41D1BA0152B93DC2ULL, 0xA14C2DC94558D973ULL, 
            0x76446B84AEBB4C33ULL, 0x603C9A8468FE3E99ULL, 0x597683EAEEA5A9B7ULL, 0xBB3238F087930B67ULL, 
            0x8D73E2A32E217C44ULL, 0xF01AAE5CABF55E86ULL, 0xB8E630939F4CAC69ULL, 0xFEB1D2A38E468AA4ULL, 
            0xFD6C43BE969757DBULL, 0x3F868FDA595762BFULL, 0x9C11C889A39124E1ULL, 0x50E73596DD5D9925ULL
        },
        {
            0xAE4811372D547B32ULL, 0x84059E5171E1259AULL, 0xE7F4B9F20D20F8B2ULL, 0x532E4E482E63A494ULL, 
            0x0A9DDFF3CB515904ULL, 0xEA1A55D3493186E3ULL, 0x2D1BDC64F186AF4FULL, 0xA9A9F4DC671BF2D3ULL, 
            0x8208BEBE72D7D9FCULL, 0x0E95B796371C1AC2ULL, 0x2960020EB5789576ULL, 0x19560E415619C78AULL, 
            0x18E39D074F8B54ACULL, 0x4653297A79B74A9FULL, 0x20E7A2B70697455CULL, 0x055EE76DED85C6ACULL, 
            0x62408849A08FF06DULL, 0x215106ED9D9D82FAULL, 0x7AA426406E928488ULL, 0x665A08120E6E6B87ULL, 
            0x0D8BE11A95DBEE4DULL, 0xEE5603471BC11D67ULL, 0x3EC8AF6A58D72DB1ULL, 0x3BC576C69493C3AEULL, 
            0xA0D7C70524219446ULL, 0x9D54E05016B8872FULL, 0x8F47652ED44F7571ULL, 0x8AC8ADFCAB9FDD90ULL, 
            0xAF4D53533A836C8CULL, 0x7FE10BFC68F7AF23ULL, 0x69D3388595A85648ULL, 0x9173BBF75162210FULL
        },
        {
            0x11755DAC330003A0ULL, 0xA1E1E4EDB66200A4ULL, 0xCC163BD4C55CCF9FULL, 0xA0CBF04410B46EC5ULL, 
            0xEBC411945A48A00AULL, 0x488A806B847CADF6ULL, 0x3930F9B1CA8625C4ULL, 0x6C342D0FCF872122ULL, 
            0xDA47CAD1AC6B0298ULL, 0xC3B0930494824861ULL, 0x560DA15F92717297ULL, 0x292533A4D2F3FBC6ULL, 
            0xE39972EC02FC91E2ULL, 0x7AB7740184F79378ULL, 0x140690FDFCB139CBULL, 0xEE1216CF203F964DULL, 
            0x859C72F043F1FA80ULL, 0x34FA7F10AD201D83ULL, 0xDC8D3D24D464E184ULL, 0xEB3D881F9820EC65ULL, 
            0x606F75B58BFF8CA7ULL, 0x2C53BAB939E8B6E7ULL, 0x469E7FCF324C14E0ULL, 0x9F0EBDE7404FD4FCULL, 
            0xBC9D2B670C631FAEULL, 0xDA7744AB4A2E3EBFULL, 0x6824F9A2F04C90A9ULL, 0x82E8E48F4D12EE15ULL, 
            0x02391B215709F99DULL, 0xACE31E85896B3F44ULL, 0x6B3AAD1D210ED0D2ULL, 0xE1B5B357ABFC9670ULL
        },
        {
            0xBAB53780009A4FBBULL, 0xEC3C45A9F44B1A59ULL, 0x5A3E2863582AC37FULL, 0xB14BFF1EBEAD1E58ULL, 
            0x4F6D6600CC3B3C79ULL, 0x12F534B996306641ULL, 0x564086C4C764DE81ULL, 0xF5EBCDFCD4EBB6BEULL, 
            0xEA731C8F8C98A9F6ULL, 0xB05AF9418F758783ULL, 0x15BA480E9A9D4C42ULL, 0x619DBD8C25BBA150ULL, 
            0x7BBA0A9F57C0A2F6ULL, 0xBF96C746549ECE37ULL, 0xED7CECF959EFDB8CULL, 0x1EFAC19807860BB8ULL, 
            0x2D83B68CDD68FF06ULL, 0xEF6187838FE307D9ULL, 0x4E6B6A56FC604361ULL, 0x5D6C51C978B1995BULL, 
            0xEECBA4EC35734A17ULL, 0xB1D4A28C68149E7DULL, 0x38D3A0C3AB47D687ULL, 0x26763F81D4CF98EEULL, 
            0xE1C17F00DB29CC9CULL, 0x436019EC5B3F1827ULL, 0x9F63F1AD9497FA04ULL, 0x8303FDA07F765397ULL, 
            0xCAA7932ECB3E7A71ULL, 0x3EADE30129B96F69ULL, 0xABCF4047B59F99CAULL, 0x6181D57BAD73D658ULL
        },
        {
            0x1334C42A1D6EEBC2ULL, 0xF79872C9DC312277ULL, 0x54D32DA05D9525B3ULL, 0xB1F5E72FAC9A593AULL, 
            0xFB92E89E46523765ULL, 0xCA136E7B707CC720ULL, 0xA17843BD09EA42CDULL, 0x1D914B79D4C8F397ULL, 
            0xED81AB9BAD1DC282ULL, 0x5BB0984A0B22D574ULL, 0x853C6300DCE2EA95ULL, 0x080FBF0D19435690ULL, 
            0xD7688DC57CB14194ULL, 0xC42792A1EC7CF21BULL, 0xA757BC30944E8415ULL, 0x1990CECEA9B2C5E5ULL, 
            0x8686FF03B41BC56CULL, 0x95EF7DC8874959D8ULL, 0x12640B33CF754A3DULL, 0xA7743CC8E1EFD800ULL, 
            0xAD1974307ED07BFCULL, 0x0913DC357AF1C04BULL, 0xED31F482AB9C32B4ULL, 0x5ADC9C61CD146747ULL, 
            0x1FC73B95E34962FCULL, 0x6F9E6269C4F2658EULL, 0x582F0403CFDADF40ULL, 0xD4E94EE1BCAFE595ULL, 
            0x5D05280C0DFE4ACDULL, 0xBAE0A1EBB64C6F9BULL, 0xC34EF1A7688E3141ULL, 0x014A84735D120B5DULL
        },
        {
            0x29BDF410AA8B5587ULL, 0x185CFD1E54DD40F1ULL, 0x1F60FEF7358C4999ULL, 0xD81A654F65587BD6ULL, 
            0x7ADA38A083513EBDULL, 0xFBB93D17FB761886ULL, 0xE4B20E1223648506ULL, 0x022C50BB9F5171E6ULL, 
            0x49F24BD59EEADC51ULL, 0xA50C144FE53AD2F3ULL, 0xEF1BA516F330F239ULL, 0x01F0E8F278E43465ULL, 
            0x46BA2922D58F669EULL, 0xE498FD14E11A3A2EULL, 0xE272202DBDE670F9ULL, 0xC819D0D163319A34ULL, 
            0x760A22B05720650FULL, 0xDF0567DA9E662234ULL, 0xD9E86E1B05564499ULL, 0x5E14701E4714A111ULL, 
            0xAE4432CC2B1ECEABULL, 0x2E20AC0C9BAA792EULL, 0x8DB09B5A4A320273ULL, 0xA296A3AB7897FBCDULL, 
            0x4579ABDF4377ED10ULL, 0x9B3B4F77B83FC580ULL, 0xA6B30A70DDE931A5ULL, 0x7EEF67213149D19DULL, 
            0xB31AE8978562A112ULL, 0x318371D4A8A246DDULL, 0xE785565528AD6D11ULL, 0xA199616BCDFB6FE1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeyRotateConstants = {
    0xD10B2CF358E244DBULL,
    0xC8A0FCC7FE62F83FULL,
    0x16E8737D18606B3BULL,
    0xD10B2CF358E244DBULL,
    0xC8A0FCC7FE62F83FULL,
    0x16E8737D18606B3BULL,
    0xEDF0677402C8FDC5ULL,
    0x39702A66A1C9CBFAULL,
    0x1E,
    0xEB,
    0xEA,
    0x01,
    0xF8,
    0x70,
    0x25,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Saiph::kKeySpawnSalts = {
    {
        {
            0x7A3286C26332826FULL, 0x96C45F3C40708ACAULL, 0xB5EB79BC384FED5BULL, 0x7CC16C6408E97F7DULL, 
            0xAA4A4EED520CB69EULL, 0xE2BCB76E8C56CD55ULL, 0x1ECA47A99190D092ULL, 0xE31CD8E0B80F75FEULL, 
            0x5AAD0FE835B3A548ULL, 0x39C6A0C601B878EFULL, 0x568E50EBF847F775ULL, 0xD23F5BA9AF7ED7ECULL, 
            0x24BB684DDC0F5478ULL, 0xAB1F1A59E71E8D05ULL, 0xAA2C4433FEA495BFULL, 0x5DB6D583D62FDC2EULL, 
            0xD5C76EB673D6D93FULL, 0x109F01BC6A054AABULL, 0x7EB3F11CD56B6EB9ULL, 0x4FDF8A76A17B1E2EULL, 
            0xA4AAB50857EEE0D3ULL, 0x05FAF410F065903EULL, 0x57EC81E55712FD04ULL, 0x1FB6971BEF40B374ULL, 
            0x6181C92C1FDC87C8ULL, 0xDDDF4B51C101C4D8ULL, 0x9B798A1D408BE891ULL, 0x217F14067A94E3B2ULL, 
            0x16927B0912003FC7ULL, 0x1987857241F814C9ULL, 0xED35C5C28BAAAAFDULL, 0x7D7142A45FC247F5ULL
        },
        {
            0x23D92E0906A4250CULL, 0xF657ADB16F2350D9ULL, 0xDF661A5BF7B0954BULL, 0x1B93AF46A640E67CULL, 
            0x66689A833CCE9C14ULL, 0x90E470113C3594CBULL, 0x26DC9697361D3EFCULL, 0x5B1AE26E5B4FBB09ULL, 
            0x48FF44911BC09077ULL, 0x57317BE47BF8473DULL, 0x39C05B1D4FB60CFCULL, 0xAB7819B90E1629E3ULL, 
            0x346048D1792E5580ULL, 0x56FD18C948A70010ULL, 0x97BDE8B08424F6C6ULL, 0xF56F1A0896BD2214ULL, 
            0x6EE1DE2697C1AD38ULL, 0xB707C7844D9A4D87ULL, 0xD89C81EBB2DD8D29ULL, 0x89C29F27B69338EEULL, 
            0x6DF11690F7B37498ULL, 0x237993EA71C4CFB0ULL, 0x6B939C3CA8E955F7ULL, 0xCECF011DACE1EA13ULL, 
            0x4468C0E73D3BD5D0ULL, 0x7108A4EEB4D85056ULL, 0xFDD0C4E5D24F07AEULL, 0xECDAD7C577CDE392ULL, 
            0x9D622AADA8C394C9ULL, 0x1F23FA2283B63815ULL, 0x0CD1298E8F9B2EAEULL, 0x3B6483DC189B127FULL
        },
        {
            0xEC59C94774DD6D2CULL, 0x661B541E0B46E924ULL, 0xE624B1F87A1D3DE4ULL, 0x1292DA6ECCD00FAEULL, 
            0x2B541C4C5A10E76AULL, 0x7F1CD651165FB398ULL, 0xE3C98920C7AF099AULL, 0xA94AED616681305DULL, 
            0x47E7A6FD72A827DAULL, 0xD6BED1126CCB8AAFULL, 0x49208BD0F8D413F7ULL, 0x5D13D36855533286ULL, 
            0xA7D024CF8AD1DFA7ULL, 0xCE64FD25D517D6C5ULL, 0xA307E144D8EBDBECULL, 0xFDE466885AB16A67ULL, 
            0xD4A6238119336B87ULL, 0xA815EA719E4323F5ULL, 0x10A008A18655CD65ULL, 0x0C577E375550B721ULL, 
            0x7CD51E78335C84BCULL, 0x756FA1C9A6311759ULL, 0x73FF9F49890E9638ULL, 0x53F02F9838CAD75AULL, 
            0xA02057341B8EA696ULL, 0xC868F49029FF3B6BULL, 0x1BD95C264781E800ULL, 0x7B41E90CC160870BULL, 
            0x7D22E8B9BED9EE62ULL, 0x6D721DB46A419F3BULL, 0xCB2D144BD8CEC37FULL, 0x2D44920CB18650AEULL
        },
        {
            0xFB7EA5D57D4C61BBULL, 0x0CC5CB86AC826D09ULL, 0x4B85410661637016ULL, 0x71FBCC3CA7EC6CF5ULL, 
            0x5FC685BE9E490892ULL, 0x823494AB159C39B7ULL, 0xF149BB501B1E1F13ULL, 0x18AC29711E4D281EULL, 
            0x759D2E3BF99B5343ULL, 0xF48046C3A1F6C8F5ULL, 0xA14B26A94ED14E80ULL, 0x9FDC5C492BA3543EULL, 
            0x0875D725D739457DULL, 0x22AB2536BBCD3166ULL, 0x100CE670D17C85F0ULL, 0x7D631811DD922DEBULL, 
            0x9E041D177EBBC6D4ULL, 0x02765EDD67A68E12ULL, 0x803B415D7E3FC7F4ULL, 0xA82FCC1A150D6BC9ULL, 
            0xAA7A7CA59FB2F24DULL, 0xAF02EC8ED5708BC2ULL, 0x395ED831906F1202ULL, 0x4BC563D75B5B7699ULL, 
            0x585377568ACD5A2EULL, 0x335E31C5D4F8326DULL, 0xE46946EAE35C8A72ULL, 0x6492CC334BA2942CULL, 
            0x31B877D814047FE1ULL, 0x14BBE7DD85805DF0ULL, 0xB4ECF05A9EF308E9ULL, 0x8A07B32D070D6A55ULL
        },
        {
            0xC5C1CF52F89DB0B3ULL, 0x84F16A6C3C9505C4ULL, 0x4731985755BE0A8BULL, 0x353654272556A463ULL, 
            0x16BBA8E11B91AAA8ULL, 0x6CB10D6304DFC0D2ULL, 0xA4C78198213AA500ULL, 0x044B605CE13BA4ECULL, 
            0x6AECD764E18B7DDDULL, 0x55E7E0A63511ADAEULL, 0x612A4F52A500825EULL, 0xBF0232E7F5376761ULL, 
            0xEAAC17451356999AULL, 0xE3AEE201CC4FDC3AULL, 0xDB80C316792463A2ULL, 0xB3657332B0270C00ULL, 
            0x9936C03BC6F61CB7ULL, 0x93F79C5E5E5EC84EULL, 0x8DE927BDC9B28819ULL, 0xE9F4788D219C56B3ULL, 
            0x24CD2F41A972886FULL, 0x2396A9A172E9ED3EULL, 0x4DEFEC442AE9EAB2ULL, 0x7458463FCF11AD8BULL, 
            0x4E1E8AE748B906E2ULL, 0x3698C7839C20FF65ULL, 0xFDF7DC2CE961487FULL, 0x55D4FE2190528AE0ULL, 
            0xC28A7C448F0C8F6DULL, 0x5A2372FB7995D026ULL, 0x88FBA49EE4281547ULL, 0xBA74B226C760A192ULL
        },
        {
            0xE73566E6491EB89AULL, 0x47503B655CF4206BULL, 0x4BBA4F36121B519FULL, 0x3939AF651640D1E2ULL, 
            0x888771B0FA0E2D41ULL, 0x7E8234C38EEB63F9ULL, 0x09400E25937B44BDULL, 0xCB1816D580CF56D2ULL, 
            0xA54B746BC3E9B612ULL, 0x50B6FCCFAA27FC52ULL, 0x98B5E2014134BC03ULL, 0x121B15B877577996ULL, 
            0x4D17FBB15C03DBA9ULL, 0x80B57ED73024AFFBULL, 0x83B0670616971599ULL, 0xD7F52C30BDAAF621ULL, 
            0xD704EE4DC305AEE7ULL, 0xF619D2BB8895179BULL, 0xF5E3DC8224A0D05CULL, 0xC2414AFD7FA8D260ULL, 
            0xECC53ABFAC0067D7ULL, 0xC6C6FB9EB7B4C891ULL, 0x704EE40F1FD657AFULL, 0x73467F1BE9906E63ULL, 
            0x9DEC50EAB1374508ULL, 0xDE25E88597E19B98ULL, 0xF908E3F54712B843ULL, 0x886A7AF9965795A8ULL, 
            0x1ABF7A7CDF130B89ULL, 0xD232B45D805194C8ULL, 0x9076E63CE953BBA9ULL, 0xDCBA002E6C7203A3ULL
        }
    },
    {
        {
            0x3F26A98316E39004ULL, 0x922A8122B3C8FC79ULL, 0x7B2C8FE333AD24B4ULL, 0x5546BA399D6AD058ULL, 
            0x67CCAD4EF0C7AABCULL, 0x7CF6BC9A2D3243B1ULL, 0x3EDCE07C8967BD70ULL, 0x7019D480818AADABULL, 
            0xD7AB555B8F9446DBULL, 0xA6B92B6BD98BD14CULL, 0xC02A466677B686AFULL, 0x9A131F4AFFA52CF4ULL, 
            0xADF393B2ED8325D9ULL, 0x195DC2C08CC455DCULL, 0x2DD2948BEF19D869ULL, 0x2209B2D94EB441E7ULL, 
            0x0ECA20342E728373ULL, 0x6D2AAEF1239FC20BULL, 0x3EB7F8BB500AE79DULL, 0x1347E4090078CE7EULL, 
            0x4DED4145409F9A2BULL, 0x2CA8D1340A9BA479ULL, 0xAE13B308C8243F80ULL, 0x232A824B50EE8668ULL, 
            0x70823415E888AEBAULL, 0xB75E21DECFEA0151ULL, 0x0410BFE9ED91FC39ULL, 0xBF4C65779737A762ULL, 
            0x8037ECE866FE9594ULL, 0x53227245F953B36EULL, 0xBFF2EB8A8F13B44FULL, 0x5D6CB4E44A05DB1AULL
        },
        {
            0x88DB57AB868C9E41ULL, 0x8ADB47E370D4DBB1ULL, 0x3365684696BE94C0ULL, 0x56B86DD67DF8B5A9ULL, 
            0xA74886BD82DF4932ULL, 0xBE4980DDD1C7AD19ULL, 0xC64545709C61C117ULL, 0xE77713F996A91D9AULL, 
            0x9919BC259A59BD2FULL, 0xA33D1153D5E136C9ULL, 0x3E7B67D4B0F45B1DULL, 0xFCDE426EA9B433B5ULL, 
            0x0FD049393216199AULL, 0xF222D4704290E649ULL, 0xC99871E53B8A2863ULL, 0xFF24A3AB01076317ULL, 
            0xC1B86C6054E3C3ACULL, 0x32CFEEB862992E39ULL, 0x72FD38EF16EEAB11ULL, 0xCED9F136ED72F89FULL, 
            0x26979E52F350A7C6ULL, 0xF5ADE62985A62A40ULL, 0xCB8A173E0E5E470DULL, 0xABF7E705840ECF9FULL, 
            0xFC49EB6E96302DEFULL, 0x18ED15959E1FC144ULL, 0x00B03068B6440F3CULL, 0xE1B18C013E46A5A5ULL, 
            0x37A90E55E6B34C6BULL, 0xC42D4CC75F7A703EULL, 0x8DF3E7E0A76378B1ULL, 0xBA32A9B54FD98DFBULL
        },
        {
            0xA9B2F856C83DC3D6ULL, 0xB1ECA754AB5B0663ULL, 0xFAABA5B4983E8C85ULL, 0x08C6EA58C84ED974ULL, 
            0xC44C8D3C3C74A580ULL, 0x2E4B7E3C65416192ULL, 0xDB8D417F26DF3370ULL, 0xBC6DCE11E6F91926ULL, 
            0xC42AD308F9EE01FEULL, 0x40693AFA221EE0B3ULL, 0x08EE376F3FFF4165ULL, 0x3A3E2C305D9530E1ULL, 
            0x14537E933FCA56C5ULL, 0x782099FC1B6DF62FULL, 0x6FA666C793BC80B8ULL, 0x06AAC7BECB6D415EULL, 
            0x6722C9D1548C0AD4ULL, 0xCAA13F4F30225EC4ULL, 0x7850988B5E81E60CULL, 0x2CAB282533FF979BULL, 
            0x1AF6E2668B3E9413ULL, 0x7DA114256759D911ULL, 0x5EF5B2DD825FD0BCULL, 0xAB4DE3ACB174B206ULL, 
            0x29061AAB6347DA11ULL, 0x34C7FBFA635662E7ULL, 0x8E118492068C258EULL, 0xC1DA45B0255EC7F5ULL, 
            0xE316BD26BE804380ULL, 0xAEA2DD7963A3E3FFULL, 0xCD797CCC3082F5F3ULL, 0xA8BF9EE718242365ULL
        },
        {
            0x7C937EF7E5F6637DULL, 0xE58A8EA62A3D9DD6ULL, 0x79BADC280FB492B5ULL, 0xC0578077BE7B0D59ULL, 
            0xA5A391D7A239A937ULL, 0xC50A0835858487DAULL, 0xE31317CFD9946428ULL, 0x463ABAB724069178ULL, 
            0x1753F468EA4FFE4AULL, 0x14EA14564D983F46ULL, 0x0461101F0517A112ULL, 0x7D2F7795C028FBFDULL, 
            0x5737A23C6D8DD2D6ULL, 0xBCF3E3E40A9DE7DFULL, 0x668F08081EA561DBULL, 0x00303B07BDEF30F4ULL, 
            0x0EE2D53D29872C7EULL, 0xB4EACF5E66760FD9ULL, 0x54FB6B66DF83C139ULL, 0x92E8176CDB201A52ULL, 
            0x9B9A9038A505D7EDULL, 0x8113C466558E613CULL, 0x9B65D4189818D896ULL, 0xA66258988F73675DULL, 
            0xF0854C8DE5418FD1ULL, 0x8E6977870E47310BULL, 0x4181A54B494AB3A3ULL, 0x91426797E553A6F2ULL, 
            0xB8B4E45B10FBA02FULL, 0xA46E0E904F377BF2ULL, 0x40A27D9C4608A8CAULL, 0x51B964FDD0BEDAA4ULL
        },
        {
            0x4A9903E1BAC77200ULL, 0xEF32262E348278A2ULL, 0xCB6A3B26FEFB4D45ULL, 0x0509D397ECDC868EULL, 
            0x14BA92DE2B6B8E0FULL, 0x5465BD47CA082B98ULL, 0x18FBC6C7D3D5E9C3ULL, 0x84EE7C0B82C8E788ULL, 
            0xD955C278058D90A1ULL, 0x79F90D5D2BDA8008ULL, 0x1A4C1E735F957E06ULL, 0x6380CB260275C434ULL, 
            0x353664618FF48B0FULL, 0xBE0ACC2C10602461ULL, 0x8942C6D946A95642ULL, 0x0F0398B1BB11CB33ULL, 
            0xD771D7CFE75D7824ULL, 0xAF736175DD5C03F2ULL, 0xA2B22DE657865B08ULL, 0x6D1E228998FA31B9ULL, 
            0x84EB8615FCF4D9BAULL, 0xE17556787E30F419ULL, 0xAF29AC55E20253E1ULL, 0x12C790DD25A9354BULL, 
            0x82061F2B40D708B2ULL, 0x34FCBD41A6E367E6ULL, 0xB391A4937839C3ADULL, 0x2E2F25A05D40CA84ULL, 
            0x39A46D87E737D30BULL, 0x6C059158A514B9FDULL, 0x9D00A3BA9B5C27CBULL, 0x3C9E542631043E35ULL
        },
        {
            0x5B7385A3D5AEB12FULL, 0x5F49B2BD016107E8ULL, 0x0719E6AEF50C61E7ULL, 0x00CCACDDC9376D04ULL, 
            0x463B19A4CD7361EAULL, 0xC2061A8CA7484A26ULL, 0xDBFE65D2203E1A57ULL, 0x45C20E2DCC8E70A0ULL, 
            0x71AF07695F6D2D1DULL, 0x00D3201ED1D10E2FULL, 0x61CE339DF997DBB1ULL, 0xC61E90181A322034ULL, 
            0xE4E159CCCFEDF9C2ULL, 0xE40ABE8B49B31E04ULL, 0x76CA444338158BBDULL, 0x0D1F92FEA576EA12ULL, 
            0x7D0709881B14BBBBULL, 0x3C8F176E9B573B91ULL, 0x04DB87ADC2B85020ULL, 0xEEC44849D6FAC81BULL, 
            0x88C3E373885E490AULL, 0xB7DE015A8BF767F9ULL, 0xF5A1E2EE7F264DF8ULL, 0xA4D5B873BFD0F8B7ULL, 
            0x87ED355472F65657ULL, 0x5DAE92ACDCAD83B8ULL, 0x3B5901AB63401149ULL, 0x34A420B8A1655B71ULL, 
            0xE83282CE209D4A67ULL, 0x427269AABE7863D4ULL, 0x646378225A9BF9FBULL, 0xD23AF86CB600D93AULL
        }
    },
    {
        {
            0x0ECEDFAFA9612A52ULL, 0xD7197F4D325A4B56ULL, 0xF90EF171B1991421ULL, 0xBC51EC5E68FE596FULL, 
            0x52CA678DEF989D3DULL, 0x9F7AC179297DFF28ULL, 0x18C12A19833527B1ULL, 0xEA6AED92BA58A813ULL, 
            0x69EC4ECC001955C7ULL, 0xDCDA4DC56FF30F15ULL, 0xE9462F15947BB9CCULL, 0x0C672BDAF39D6F51ULL, 
            0x1C4E07459A21758FULL, 0x96E3FF4C3A1B42A3ULL, 0x35D2865E1448EE03ULL, 0xF2279CEA5160F2F3ULL, 
            0x31D9C6531EF412C1ULL, 0x5527EF3419237FEFULL, 0xAA25F76AD8EC2D41ULL, 0x729BC13D1DCEAB67ULL, 
            0x7772964B4F46B2C1ULL, 0xCE8A056C8DB3D02CULL, 0x10FCEAB514959773ULL, 0xE773332FA44F6D55ULL, 
            0xC9CF21FBD4E111F6ULL, 0x3A43FD546050DD85ULL, 0xA26BB367BE685E8FULL, 0xA23958491A6276B9ULL, 
            0x93D5599FEE1F4ECFULL, 0x87ADD2D0DB80A0D9ULL, 0xB1C614C91717149DULL, 0xBA8E491FEDFA5CA5ULL
        },
        {
            0x57070F0D8006F8DFULL, 0x27F3E6961BFA546CULL, 0x7CC588521AF2E48CULL, 0xADB4AF69CFB010E0ULL, 
            0xCB1B67CE9EA0B396ULL, 0xCD0D0D4AA66D03FEULL, 0x612930C104FB2C55ULL, 0x7B58B1439210FB5BULL, 
            0x7D3F50128AE1E313ULL, 0x9395BCAB44F2A4B6ULL, 0x5AEB93B630C7A1C4ULL, 0xDA179D0EE260415CULL, 
            0xA21CA8F8B284806FULL, 0x292B99F0E312C8F4ULL, 0x6251C86C032FD409ULL, 0x8ED8E76E36110C9BULL, 
            0x3AE613E214F7FA57ULL, 0x70F65A054FB333C5ULL, 0x3DF39DCE00CD37FBULL, 0xD90866C8C6071696ULL, 
            0xC5B7AD09FCCD4AECULL, 0xF14724EB63FD1F82ULL, 0xE63A04A34EB30FFBULL, 0x29665E2AA000022CULL, 
            0xE5D895D18396343BULL, 0xDF37D58C6A2F55B9ULL, 0x2DD4208F868A7CD6ULL, 0x8526F17ABF0A510FULL, 
            0x5C7508BE2D3044ECULL, 0x18A69D236087EF76ULL, 0x0888466AA74EACABULL, 0x0924AD9A9EB7BDD9ULL
        },
        {
            0x46A12326934F3BE0ULL, 0xC9FD126875F4964DULL, 0x8C403820C8CDA7C6ULL, 0x7CA27CCE1CC898B3ULL, 
            0xB30303B8A3FDDC7FULL, 0xB9F610852E04A1E4ULL, 0x0FF6356F85E4E23FULL, 0x79BDD215B1EA67C2ULL, 
            0x14D6E59E9D5DC19AULL, 0x0DBA804DDC8C6846ULL, 0xA63EAED53E917B5BULL, 0x5CF25E3FCBCF989DULL, 
            0x569A44DF59654E68ULL, 0xD2DF030852C33B2BULL, 0x7D2C1356E81591DCULL, 0xAB72AC2F70B3059CULL, 
            0x9FD51E46DEF4CAC0ULL, 0xB1528C1AA0009D56ULL, 0x47CB492FAD26C076ULL, 0xE8A92EF0BEECB588ULL, 
            0xB805C5281CF35936ULL, 0x8AEC08D30BCAD1A8ULL, 0xBE36E4BB93F1D41AULL, 0x15300FFD4EE1A8CFULL, 
            0xB7BB39C192B818E7ULL, 0x0F119F95FD3EEA91ULL, 0x80A11B930B8E0F5FULL, 0x9CE0F54197C638A5ULL, 
            0x1CCE401FCC9BDEA4ULL, 0x9A630CF851501860ULL, 0xC812D501060F3BCDULL, 0x0FF99096263591EFULL
        },
        {
            0x59F2E67530849F09ULL, 0xFAE9618F3763C57CULL, 0x1919A15158497D01ULL, 0x08E67B4FA52CBC94ULL, 
            0x6336E6DA148E3917ULL, 0x786FE53EA5FC846FULL, 0x090821EE4550BB3DULL, 0xF8FFB746B3A1F9ABULL, 
            0x69B8783B1DACCBD3ULL, 0x3B8D00B92CB35C8AULL, 0xFA44429BA1B610E5ULL, 0x113C8A30B5924E42ULL, 
            0xA8FDE679669771BAULL, 0x16052A054CFBFCCFULL, 0x8061EE4434F7FB6EULL, 0xC33D5A00A9C53EC8ULL, 
            0x9B7FEF86C9455E77ULL, 0xF073ECA3E6B19BEBULL, 0xD2147EECF450DC9CULL, 0x436B234256AA785EULL, 
            0x3652E15F30699365ULL, 0x1276C78C04924F39ULL, 0xDD585344D6943523ULL, 0x2726187E3459BF63ULL, 
            0x70A4E0F705C56AA0ULL, 0x30829B2FBD33B757ULL, 0x1EB055E6671890EBULL, 0x99EBF583BB3FD383ULL, 
            0xACB0F86737AE8D89ULL, 0x25C59D7D0A4E1367ULL, 0xC5FD154DAFCFF652ULL, 0x90BAAF758FF6E1B7ULL
        },
        {
            0xBA0FCA12D433DBA6ULL, 0xE97AC9ABB6E9F0FAULL, 0xAE9EF569FA970E32ULL, 0x15A7EA4A28743C37ULL, 
            0xB90D5189D8C8620BULL, 0x987B321D5D68A3B1ULL, 0xF86C2AB0DB1A6EC0ULL, 0x7D7E98EE30CFAF5FULL, 
            0xE1FB8F560E157F03ULL, 0x11790490B0D153AAULL, 0x0019633F4F4FD12AULL, 0xED4F44A8895A9FC5ULL, 
            0x1341EC45648797FEULL, 0x2A0B4BB72D51BA05ULL, 0xC050610870B0E227ULL, 0x9CA26E078E311BDBULL, 
            0x05446B3A34DC2050ULL, 0x3BFCE3169288E5C4ULL, 0xCB7823CFBE6F8D37ULL, 0x75727A090CA91032ULL, 
            0xDDB2CBD22E452F85ULL, 0xF1C5602B087BAC27ULL, 0x94E8D99411CAF830ULL, 0x558A12B29830FA34ULL, 
            0x218C24656D25F157ULL, 0x3D16DB599E5F6C66ULL, 0xFFCF52FCEF6935B9ULL, 0x5019E354223BA821ULL, 
            0xE2161B5C010558D0ULL, 0xEE103A81C9169094ULL, 0x03E5DACB2B413A1FULL, 0x7A99AE1F115BF58AULL
        },
        {
            0x0E19CF0EEF304737ULL, 0x1FCA2C4AB7FB5533ULL, 0x566FC4C600F2FB9CULL, 0x6E9DE7B0893E41C5ULL, 
            0xA227E32A00118A2EULL, 0x1B564FC126712427ULL, 0xB2A69A1FD505260BULL, 0x44F647A80A6362EDULL, 
            0xF8AC76F4ECCA0569ULL, 0xC24DC824291C38E5ULL, 0xC0828DA8C80CAAD1ULL, 0x89F25E78C8081002ULL, 
            0x15E1FEF1C948F9ECULL, 0xC21A08CB0B074D54ULL, 0x52D2AB570FFAA52AULL, 0xA92305EEAFBCBE2CULL, 
            0xEC22B403ADAE2129ULL, 0xEE1804B4539CE9A8ULL, 0x687C388852E3B920ULL, 0x84E6247887D84BC2ULL, 
            0xF95BEB0B4E3A5156ULL, 0xA952D848C9884369ULL, 0x7558A0EA4E2D1537ULL, 0xD2473DF6A51C7501ULL, 
            0x0D67D6DB8F62A69AULL, 0x440F7A93FC26C3A2ULL, 0x817BD68C3CEAD030ULL, 0xDAB051C8C123ECB4ULL, 
            0xD731A0B6A85FCDE8ULL, 0xA7B005BC43540548ULL, 0x6F345B6783ED3645ULL, 0xF9CF76F3B57669BDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeySpawnConstants = {
    0x0BF10C1E98CFD434ULL,
    0xCFE2177F56182B03ULL,
    0xB4678842BA3BF2F4ULL,
    0x0BF10C1E98CFD434ULL,
    0xCFE2177F56182B03ULL,
    0xB4678842BA3BF2F4ULL,
    0x838F70B75D680EECULL,
    0xC48A473306C8C348ULL,
    0x52,
    0x39,
    0xCF,
    0xEA,
    0x5B,
    0xBD,
    0xC7,
    0x89
};

const TwistDomainSaltSet TwistExpander_Saiph::kSeedSalts = {
    {
        {
            0xE106BADC7FF2E817ULL, 0x8F545E793453AA00ULL, 0x5C5EE54A96700D07ULL, 0x8C78682983540B56ULL, 
            0x65231927310A0EA9ULL, 0x30542FFA0A892055ULL, 0x1C1778C2DB1DBCCFULL, 0x70AB415681F6D092ULL, 
            0x49DBCBBDA316BA5DULL, 0xF9869874B2DDCB69ULL, 0x7B51FE10D695E369ULL, 0x4CE2504413C53AC4ULL, 
            0x818777CC858D871CULL, 0x5FDB18900168467EULL, 0x63D8DE0B396BB85EULL, 0x5273DF986F4D5BB6ULL, 
            0x886A5ED1B1F93428ULL, 0x0C644D3B8557529BULL, 0x5281666A72814698ULL, 0x1712FD3E08CA5AF9ULL, 
            0x29CF1595934DD676ULL, 0x37D947F6BAD881E4ULL, 0x8487FFE825C6BB4DULL, 0x0060156742D36FFCULL, 
            0x770D86465B70AF81ULL, 0xB7FAA9893A09480FULL, 0x131E78228CF47010ULL, 0x97CC2DADA03327D1ULL, 
            0x105943E50AEE7F36ULL, 0xE119872D1B18328CULL, 0xDC370DD2F23576D2ULL, 0x24D3A1316D123F8AULL
        },
        {
            0xAE3F67542B295157ULL, 0x201A5AA3DB5D1D91ULL, 0x125371DA823E0CDCULL, 0xF15FF68189FE5962ULL, 
            0x0E17BF7D0CD0A047ULL, 0xD296DAA89C5E9E5CULL, 0x19984AA6B3A5EE24ULL, 0x783773D7A4604A52ULL, 
            0x051483F381AE22B0ULL, 0xA382D3B59074A7FBULL, 0xB0F83E03AEBA83EAULL, 0x2F6E184D52CB43DCULL, 
            0xB6588DCC9D995D51ULL, 0x43C43CC66103EB09ULL, 0x1CA1070E88FBD431ULL, 0x1CB8BEBBB722CFD6ULL, 
            0x77D39A2B85A5885AULL, 0xA67B5D49FB12E8B9ULL, 0x7C18CDC94EF71327ULL, 0xD39742D04256CEDAULL, 
            0x76D3AA552736B474ULL, 0xA6F4DB90F4691B94ULL, 0x7ADA844ABD49788EULL, 0x416AA20D8E244AE7ULL, 
            0x046D1D8BD97286DCULL, 0x8620E35ED4C9F309ULL, 0xF162029AFA7C0BEEULL, 0xFE92EE3D405189C3ULL, 
            0x0DD813FCC52A7A6CULL, 0x75C34548DB752D6EULL, 0xE1B2EEB47E10B954ULL, 0x1D73715EDFA8F742ULL
        },
        {
            0xC63FC90B8E0ACD20ULL, 0x682F857369D2CE11ULL, 0x8E8ACC61E24E8F0BULL, 0x0DA9A2372F31C04EULL, 
            0xADCC9DFFBE770CF3ULL, 0x9C19DA09251B492DULL, 0x38F58A35B7EEA5D7ULL, 0x7C57FC0AA774047DULL, 
            0x5E1E5A13EEB666FEULL, 0x4743CC23571EA4E1ULL, 0x39A7B964B1EAD8F8ULL, 0xF8FB7EA4C3A1E27CULL, 
            0x304055D10DC782A8ULL, 0x73440115C8B51369ULL, 0x8FF3C7217E992ED2ULL, 0xDB63C11ABF209814ULL, 
            0x379B80E8F198D6A0ULL, 0xAB36272B3ED17D5DULL, 0xF05DFB2FA03473BCULL, 0x6A6EA05FE998796FULL, 
            0x476680634236947BULL, 0x70EBF2527E3021A4ULL, 0xEA83A473E01E9852ULL, 0x11ACD6A37040B188ULL, 
            0x157375BE42F7BEBFULL, 0x2A80828BEBD2EFD7ULL, 0x3740B7F032E0D581ULL, 0xC401B299F7CF2565ULL, 
            0xE7D28B08728A6107ULL, 0x0F60BBC0D7312ADBULL, 0xFEEE6414EEADF6C5ULL, 0x3FB45C1C578CB9EBULL
        },
        {
            0xFC835DDAC73BF2CBULL, 0xFA25B9291727E528ULL, 0x0353A097A9437438ULL, 0x915366A1898F4C0BULL, 
            0x62EE8CD10E13D438ULL, 0xD365E8DD76DFC34FULL, 0x5F1CF9B6C173A54AULL, 0x6C7B8CFA05409144ULL, 
            0x128559E17C0282C5ULL, 0x339C32598CBE1382ULL, 0xE6BE9DDF8BF455D4ULL, 0x92123D0B479D4945ULL, 
            0x0FB02DA5933033F1ULL, 0xCC8FA41522DB8D14ULL, 0xDBE219F43AF76AA3ULL, 0x67AD8E603A0433E3ULL, 
            0x804C56D20E393E99ULL, 0x1E90F9D3D8D55F1BULL, 0x36591107D245CF35ULL, 0x0F4D789705379157ULL, 
            0x74151503D09D36C4ULL, 0x0EBE21448406D16FULL, 0x0BBC8DEFFC8092B2ULL, 0x5C30C251CA894E8EULL, 
            0x8E0E169BA7C11249ULL, 0x465DEBC17C00C50BULL, 0xA927CFBAD890F3C6ULL, 0x22E0CFEA7CAB8BEFULL, 
            0x815223973B893244ULL, 0x4D8C82C7F79CCBB2ULL, 0x0D0034BEC3D0A4EAULL, 0xC74722CD2BB28025ULL
        },
        {
            0x3766A5317F0F6175ULL, 0x59E559DB4B1B23A7ULL, 0x4633D05EBA10764EULL, 0x00388F9C42746757ULL, 
            0x9D618BB6C381380BULL, 0xCBA8BC7681F7693CULL, 0x7B4E78A6EE634552ULL, 0x8868EE169D6760C9ULL, 
            0x57A0EAADC60D197DULL, 0x8F59BE02E73BEC58ULL, 0xA6A3236F4DBA8561ULL, 0xDDBC24F208301CEBULL, 
            0xF82CFDC70A28B119ULL, 0x5FE447AFC0709BE6ULL, 0xFE4C93E5C10CD100ULL, 0xB0FABA36E688E9FDULL, 
            0x196E57946B97490DULL, 0x4ABFA7C4AE27CCDEULL, 0x1D59F4B5EF170235ULL, 0xF41B2D377C0D7DE5ULL, 
            0x3298668FB09B6398ULL, 0x896FA4911739C075ULL, 0x50131796F6E0F6E4ULL, 0x78E33F21C1A80A98ULL, 
            0x97077DD01E098456ULL, 0xA0FD9C110CD7070BULL, 0x5FEA94F917D65489ULL, 0xBEFED0FD4299854EULL, 
            0xBFC2D2B21DF0CF74ULL, 0xA16EDBDEA5E0820FULL, 0x552C4379ED870E6FULL, 0xC6201A249B364A7BULL
        },
        {
            0x3DC6BD0A1760BAD7ULL, 0x851CE947CC3FFB0AULL, 0xA10E2A4AC03A53D9ULL, 0x1EE0AE393CF03ABFULL, 
            0x272631D9A3D68950ULL, 0xC0D6384AD6FDE9B6ULL, 0xD98069C93D363840ULL, 0x3F2197ECBAB6EA2BULL, 
            0x92D465EE5C0BBB64ULL, 0x86EF18C4E32ED1FCULL, 0x46C3EC62CA2F5BACULL, 0xD4896CF760550FC9ULL, 
            0x92CB0D97ABF26AB8ULL, 0x5B6FBD72B73C8B23ULL, 0xF757F12E228186F9ULL, 0x6025D59DA4B11D16ULL, 
            0x8629DBF1C77EB0C9ULL, 0x9CB15C4E04C95FBAULL, 0xDF7F7914F665B72EULL, 0x6505FAF864EE6980ULL, 
            0xD0F97D03F8759860ULL, 0xCE1FA68DE0947467ULL, 0x53CA84EC64362550ULL, 0xACCC5F5F45DECF76ULL, 
            0x209A7689F66182A4ULL, 0xA148C62562147A25ULL, 0x1A4E6C1D6E4EB7BCULL, 0xB0C3BE742CA2377FULL, 
            0xD8BCBB1F8C36667AULL, 0xA96678D66C7405FEULL, 0x771CF139B51F0C0CULL, 0x34BF60D2F5AA0E69ULL
        }
    },
    {
        {
            0x2D442779B1B30313ULL, 0x020A7CAA0BFC044EULL, 0xF9875A58C7DE9DC0ULL, 0x2D702F818DC27319ULL, 
            0x50F00CE0E0B67484ULL, 0x0014FC7BB1CB5961ULL, 0xC63D7C8FC5BEADB6ULL, 0xFA87C7C9EB481C04ULL, 
            0x9E7A825C7C8F80E4ULL, 0x60C1564274DAE04FULL, 0xEA5128C7247AD0F2ULL, 0xA0669B786EAD2F61ULL, 
            0x1C886ECAC8CA559AULL, 0xB62AAA8890CFFFF2ULL, 0xF37063B3C563EEA7ULL, 0x21E79735E7F011EFULL, 
            0x81FB63035C24E2FDULL, 0xEB293C525C65F42BULL, 0x0AA868505E19AE0CULL, 0xF94837F525D41F6EULL, 
            0x5370D565FF2740D0ULL, 0xBCECFE85219AF966ULL, 0xC9EC3DD69BADA332ULL, 0xDD82690741FE02DFULL, 
            0xF529C02A010B75DEULL, 0x9E983A4AD6961237ULL, 0x0EFBAE50AAE0B60BULL, 0x2FE4710DA555CF5FULL, 
            0xFD4FFF4360BD1D2AULL, 0x9E5473366DB71428ULL, 0x86DCF650E25E8083ULL, 0x5956AB4D1AF4EF19ULL
        },
        {
            0x85B1C7707B59E0A0ULL, 0x68E3BC1D5BF302ACULL, 0x454A880D43CEC257ULL, 0x759D3FB9D2A971FEULL, 
            0xDE297A180BF263FCULL, 0xD3A46AAE2C079AE3ULL, 0xA3B405BB7EC73171ULL, 0x558F8DF9C657B1E7ULL, 
            0x6F034036E8123891ULL, 0x06312638F2148A26ULL, 0xC9C6F4334049E77BULL, 0xDD14E783C94C1A30ULL, 
            0x9CA6F40FB8D80A49ULL, 0xF1712570F3C2CB4DULL, 0x0842710E94FD66C8ULL, 0x1B3982FE94A0DAEEULL, 
            0x9417390A3E9FA56AULL, 0xD74BA711D07B05B8ULL, 0x97C8776DF54F5B7EULL, 0x065858903A2B79E8ULL, 
            0xF725873606F5D97EULL, 0xB2532C4FD99B0FCAULL, 0x93831C7885D37A04ULL, 0x156EB97D0C6E9776ULL, 
            0xA5A651FB52DE099DULL, 0x5DF786695D505D13ULL, 0xE0245AA3871154F0ULL, 0xD9257612002DA64EULL, 
            0xE4C6E3035E03CE16ULL, 0x9636235E36323369ULL, 0xEC10B97C873F3F80ULL, 0x86405EACD8383EAAULL
        },
        {
            0x591FFB585DAB4C9DULL, 0x24BC2138536E581BULL, 0xB679B998ED7A9E7AULL, 0x44AC51E86010E1A8ULL, 
            0xBD5CB1B8D2E3E300ULL, 0x8AD3D691715E0FD1ULL, 0x7DFE02B31DC4E783ULL, 0x54B459723449BCCFULL, 
            0xB85CE88FC993ACE0ULL, 0x75887951B671104BULL, 0xB95E001284C903B5ULL, 0x0E1B462101EC20FDULL, 
            0x9A0E81D990912E76ULL, 0xD762FBE285BB1E65ULL, 0x290587A60864C73BULL, 0x335FE8D708910D48ULL, 
            0xE56E4D4563878D33ULL, 0xBB11E6904236E9E2ULL, 0x517DE542A76D553CULL, 0x92249747F00102A6ULL, 
            0x787E1E7109407128ULL, 0xF8FA746C19E44317ULL, 0x204C6335872D28ECULL, 0x79DFE069E8F1180DULL, 
            0xF4F86DFA911F1E3DULL, 0x7791C12DEAB2C8AAULL, 0xCC76C4ADA69550E8ULL, 0x6600B5997406766FULL, 
            0x183C44FD2BEBB5A9ULL, 0xC62F07BA012CEAF0ULL, 0x31B1C47DB2100F95ULL, 0xCF777347CBF13508ULL
        },
        {
            0x6EDC50FD5745A274ULL, 0xD17FA3BA6C7E4355ULL, 0xD004434B8E1EDADDULL, 0xF0E4C3CA10A363D3ULL, 
            0xE621EC714E843F2CULL, 0x1D3A1B07895531E7ULL, 0x4CB433AB0836D78DULL, 0xCFECD979324DC676ULL, 
            0xFD5A002A116F6663ULL, 0x8F07FD92738997C3ULL, 0xDF227575A1742ACBULL, 0x8208C84385C9B3DEULL, 
            0x523E3E1CABCD2D7CULL, 0x99A8324E0BA54860ULL, 0xA8A3C8F8877B87C0ULL, 0xCB45395CAE6A6258ULL, 
            0xCB050892D7D5B527ULL, 0xB60E313DF67FE7B0ULL, 0x50FE996E75B4E3F1ULL, 0xE9B6ADBCB3F3792DULL, 
            0x1090723227B95DF4ULL, 0x36CBF01069971B9CULL, 0xE5966A4C750FF2FEULL, 0xAE67F2F9051DCC20ULL, 
            0x17EE38C58CC94C85ULL, 0x8FA5E60F8B4B2177ULL, 0xC898AEDEF21BAB21ULL, 0x65EDD5A92DDFD99FULL, 
            0xBB797122A6EEAB45ULL, 0xBD14B42334EBE2BCULL, 0xEAF075B57E6481CEULL, 0xBE51D98700B67632ULL
        },
        {
            0x2EC1BB0B08E100F7ULL, 0xA207280BDCC69A6CULL, 0xCEE104552CF35898ULL, 0x4DA3E3F32EDEA9F5ULL, 
            0xC5B46D67C35DBD64ULL, 0x879267E4EBBA3F94ULL, 0x361D90838B9AEBDAULL, 0x9EDD7020AFA827AFULL, 
            0xBB10715DC53573B7ULL, 0x2AE54B4626C142EAULL, 0x396AEBE79843D8E4ULL, 0xDE74FAB7C922F5B5ULL, 
            0x55D4EACEC1635013ULL, 0x9FA8C70960EFC376ULL, 0xC753596B3135A38DULL, 0xE9C468F1D3BF90CFULL, 
            0xA5BB4F0A43BA2816ULL, 0x3059BD8EBEC7D6E0ULL, 0x4B45CE16CCC87BAEULL, 0x312355EB4E6A7E45ULL, 
            0x16741506182524D7ULL, 0x6E442E26FD940FBDULL, 0x070C585BC11B2A57ULL, 0x93BCFDAA8B9A046DULL, 
            0x806A06570D9CB0BEULL, 0x81D630A69FC58233ULL, 0x125281DF7089F676ULL, 0xD8156AE17404F469ULL, 
            0x8B3A83492625CC26ULL, 0xFAA7B842A63EBBDBULL, 0x2AF41443B573BCF9ULL, 0x0380C2A15B0A45F3ULL
        },
        {
            0xEAC02862CF62E8DCULL, 0x49D1F3DD187D58B2ULL, 0x4BC3C6292A2B28F2ULL, 0x78C086DFFBB4CF6DULL, 
            0x60E2D8CF51D5FE8BULL, 0x32C947AE7758C6F8ULL, 0xDA5962CE852ABC8DULL, 0x6FD29580F1DA0603ULL, 
            0x2F751B7C5622FA06ULL, 0x7A029E969FCDCC7BULL, 0xEAD08CF0A274FDBBULL, 0xBDC4052B83E1E632ULL, 
            0x8A30050F340816E4ULL, 0xADC514B5AB969FE2ULL, 0x5F8FC30690E8C033ULL, 0x412314649AEB2554ULL, 
            0xBC43C905DD8D30B7ULL, 0x0444A3E58AF5FA9FULL, 0xA6BAC0D71EDE2763ULL, 0x8F34DFBA1B87A34AULL, 
            0xF2422EDF2C88B6C3ULL, 0x21EE3F7F595DDE2DULL, 0xA076A029F8847B9CULL, 0x53B7C0D46106338BULL, 
            0xEF475BCA6B351667ULL, 0xABB147BF9C8D34C9ULL, 0xD5F5AB0A14CFA095ULL, 0x5141A14F935075FFULL, 
            0xE202ED693F92D801ULL, 0x9CBC414D50969B35ULL, 0x5A8A8BC85A4FA400ULL, 0xFD6B2BDFAB4EE1C5ULL
        }
    },
    {
        {
            0x13D8134F4893E1EAULL, 0xD5974738CBFB1825ULL, 0x73CBB33F9CAA6E8DULL, 0x72C54B4406D4A53CULL, 
            0xB642E89AA892ADB5ULL, 0xD047657D0BA559B3ULL, 0x31CF679125540735ULL, 0x2FF58B7E8310D0A4ULL, 
            0x4555EAC8F91B56A9ULL, 0x2DFCFC4E7C54A1F0ULL, 0xDB4FE0D3F756AEA8ULL, 0xB35FD3F4817A2F8AULL, 
            0xFCB98267E299208BULL, 0xBEC5DD103CE587D1ULL, 0xD490D2E806DB8C54ULL, 0xF30E52E52B43DD5BULL, 
            0xF043CE3BC78DBDE7ULL, 0xAA156A580204E260ULL, 0x64CE9F9FE411316EULL, 0x737919112FA7C025ULL, 
            0x29EEB39276BEFCFDULL, 0x7412B1CDA4C4FFDEULL, 0x9E41F4319356171CULL, 0x98AF01F28DD60A10ULL, 
            0x35F0C71BBB122DD6ULL, 0xCDEE7423AAC4CE2EULL, 0x6F21B96F1AB63A7BULL, 0xA502222FDF9CF28FULL, 
            0xB0225DDBEF86D386ULL, 0x4A105CCA519BCF51ULL, 0xF5F9E9B077890A44ULL, 0xCC41DB15F566F0B0ULL
        },
        {
            0xC467C0D4806DD551ULL, 0x83E2D769A316FA25ULL, 0x763709AD54386B80ULL, 0x6D0A270299079183ULL, 
            0xA6CB3F3388197047ULL, 0x627555EFD6B557F0ULL, 0x9DB13FC095FEDC1AULL, 0x5C921B333E86C565ULL, 
            0xA6D0C4DDAB735650ULL, 0xF181C9FA0D22C831ULL, 0x95E15F40074A32E1ULL, 0x2C67BF2867EAD61FULL, 
            0x05390E0DAED789E8ULL, 0x83317628B8FE3D81ULL, 0xF95D01CB78D3893CULL, 0xBDEE565ACBD4D7BFULL, 
            0xAF066172A949CDB7ULL, 0x490B777D013B7258ULL, 0x4DB850616DF2E4EEULL, 0xDF980510325113F3ULL, 
            0x9E571FA5B6790B5CULL, 0xAA5E15A07D2F7EEFULL, 0x57208EBB5E87421FULL, 0xE9C417A4DCCADDC4ULL, 
            0x20DE8AA4B8729BBAULL, 0xFD432836CF1C2918ULL, 0xB96B88C627916577ULL, 0xC1822CECD1FCDDA4ULL, 
            0xA069D3821C55CA1CULL, 0xAC5C442F463BA806ULL, 0xD8C3153F51B4C528ULL, 0xB9B4C4C155BAABF6ULL
        },
        {
            0x160C0D7979390FABULL, 0xDF656134278E50A5ULL, 0x967801098B71A8DCULL, 0xCDE1D48CC551BF71ULL, 
            0x61C176B38D2195BAULL, 0xFE218C1DB1FE5BB9ULL, 0x9FBE0F5C37BA18A9ULL, 0x2C7EB7405F55895EULL, 
            0x97548EE3283A53C3ULL, 0x201416A26661707DULL, 0xB1B5DC2769070E81ULL, 0x11E598A3F937D47EULL, 
            0xBB710050BDFE7BB9ULL, 0x2CB371B86621897BULL, 0xAF184A31ABCF750DULL, 0xAB77BB3E7189F466ULL, 
            0xAD824E7020072266ULL, 0xA102F29D477052EAULL, 0x05DA9A929CAED9D9ULL, 0x30051E6353B48F76ULL, 
            0xD369A56C1DD4A931ULL, 0xD3D533BC1F890F30ULL, 0x41319E68660D62ACULL, 0xBA322FA3EB942721ULL, 
            0x0F81F3F6DD69661FULL, 0xEA91F40B59C300E7ULL, 0xA79E8B875F1D6863ULL, 0x7223798292F89215ULL, 
            0x36EF120C4715DA9BULL, 0x776044098E97107CULL, 0x0B29284C43C19619ULL, 0xEEA6A8D3EE9D4039ULL
        },
        {
            0x7DA641F6E7BBD616ULL, 0x90197683D050C6B4ULL, 0xE5A354C32470B5D9ULL, 0xA1DFA587D1380C62ULL, 
            0xA862A4FDA2838A09ULL, 0xF03231612F41414FULL, 0x5699695F8D6C8A3FULL, 0x4A1C5A8A76E93A23ULL, 
            0x4C8ECB08D6BDC091ULL, 0xAC115CEE73453A19ULL, 0xF0FECCE9E02808F6ULL, 0x1A9247A09E2D961DULL, 
            0xD01A53666B25D6F9ULL, 0x0BA94D75789FB6E3ULL, 0xEAADFD9E5C6138A2ULL, 0xC878984B99921FE7ULL, 
            0x6E96657B96A50614ULL, 0xF2CA8C483AA9133FULL, 0xFCCF541A436FAAE2ULL, 0x8F5E348705B11027ULL, 
            0xB6A0F8F1AB95F2FDULL, 0x1F511FB81A53E281ULL, 0x9147EA9AFE3060ACULL, 0x5E52FA2FE0A56AC4ULL, 
            0xB5C172CE64402D07ULL, 0xE50783E414748B8BULL, 0x4740D0043D25ED14ULL, 0x0C6D258C09952CF4ULL, 
            0x8CC63D48591CA686ULL, 0x4523356F824515EBULL, 0x9DA1DE231C319D9CULL, 0x83615D2EF2B74226ULL
        },
        {
            0xDEBDE21760643417ULL, 0x5870FA2B3174DBDFULL, 0x73326BDC7BD6E2F3ULL, 0x13C0F092A713FAC8ULL, 
            0xF309B93CEB716541ULL, 0xFD760D33D787E599ULL, 0x00123000541EF21CULL, 0x85BD9D69E9709559ULL, 
            0xA83325D75E86898BULL, 0xD5DE1D1D4D4307A5ULL, 0xA252F81E09524B38ULL, 0x04B4B3023DEDE483ULL, 
            0x9E77191C534A6CF5ULL, 0xD0449CA6126D2241ULL, 0x2995819E5EFCE653ULL, 0x8A86FC8C8FB75B51ULL, 
            0xECCC39FA5EED9802ULL, 0xD97EE89999CDB1ACULL, 0xE2C370C3C2B5974CULL, 0xED6C099C13A899C8ULL, 
            0x7CB90C71DF184EF7ULL, 0xB1E293F376522400ULL, 0xEA71D1813DD75C2BULL, 0x7CBC3FF006746C5DULL, 
            0x025192208B9E53BDULL, 0x6DB4596633631BB6ULL, 0xF37F674CCAA00EBFULL, 0xED8E709F0B6CB7D5ULL, 
            0x96A691E125E5F274ULL, 0x9996CE579F4A357AULL, 0x622AA91C25960028ULL, 0x860478765D055F81ULL
        },
        {
            0xA70ABF298E320ED2ULL, 0x6505FF5DD2CE744AULL, 0xD410D57021FC7440ULL, 0x82F3DB96765597A8ULL, 
            0xCD60A407F3A35F39ULL, 0x2B302DE5FAF2C3AFULL, 0xA310109FC92A0397ULL, 0xB95A866799FED1C3ULL, 
            0x43518BAE23CDD897ULL, 0x15074A6B95251A8AULL, 0xD858AA26321DC482ULL, 0xE01AEBE09E42E95CULL, 
            0x86B6A8A47B6D742AULL, 0x649508A37B7DAB23ULL, 0x36683449A30E032FULL, 0x354A5502A735BE54ULL, 
            0xB91B58594D422C62ULL, 0x73A2EE24E4F29ADEULL, 0x81C140A123A51E0AULL, 0x3ACD04F74D1F2E4DULL, 
            0xE7B5F0E7EF1C17F2ULL, 0x8E0754DF84B6F8B3ULL, 0x1DFB28D185FB3190ULL, 0x6FACCB1FFB421320ULL, 
            0xABDD6D9AD02432C7ULL, 0xA709DCCB0BFB52C5ULL, 0xC0AD24762AAB4655ULL, 0xF21EA6EB76154C3EULL, 
            0xB6A69734F07DC367ULL, 0x3793311488AA3F8FULL, 0x6B1B63E4F7B30F25ULL, 0xF3E2E67E6BA70715ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kSeedConstants = {
    0xA30F2276D68A206EULL,
    0x9B03E8956360E79FULL,
    0xC65D0D17C2B5B30EULL,
    0xA30F2276D68A206EULL,
    0x9B03E8956360E79FULL,
    0xC65D0D17C2B5B30EULL,
    0x2E90A4700F990849ULL,
    0x88648BE5C8CBC91EULL,
    0x25,
    0x25,
    0x45,
    0xC2,
    0xDC,
    0x5E,
    0x93,
    0xB8
};

const TwistDomainSaltSet TwistExpander_Saiph::kTwistSalts = {
    {
        {
            0x37A8842470606F30ULL, 0x28212868FAF72009ULL, 0x472D97F7D9676EDAULL, 0x77DEE27BFD38ED8CULL, 
            0x13E88F77C3A1149AULL, 0x0997CA200B095DD1ULL, 0x881BC398914838F8ULL, 0x0BAB8E38F9573F4DULL, 
            0xE126AD803F9875BAULL, 0xC09671C2F5A72165ULL, 0x789DABB94856B1DAULL, 0x9253914C6132E576ULL, 
            0x02E1E333A2F4597DULL, 0xBA8D78F59CC12DECULL, 0xEB194B83A92C2FF7ULL, 0x5D024AE3CAED4C9BULL, 
            0x4386A6287F316560ULL, 0xBEC4112561DEBC96ULL, 0x809BF05AD80E5BC0ULL, 0xC602722031E0A9FBULL, 
            0xA3944741406A834EULL, 0xCD1860948153C08AULL, 0x12D784E92CD36D07ULL, 0x6019311E4CC30343ULL, 
            0xD2CE2ACD18F4E010ULL, 0x89290B3AC4C91EEFULL, 0x324687F7E9DDB7BAULL, 0xBDE5EAAEBA4F35E8ULL, 
            0x2632F1D78118402BULL, 0x4F2DCDF084382B60ULL, 0xC561DF21A8319F1CULL, 0x20C59F30B29318DCULL
        },
        {
            0xB568098B92CFA59EULL, 0x6207EA62B61187D2ULL, 0x4A4563F8D7BC11F2ULL, 0x5B737EE811E892A6ULL, 
            0x100774865083B79EULL, 0xDE65C8DE6D7BA73EULL, 0x45EB9516281FC5E6ULL, 0x63A5472A5DCEA427ULL, 
            0x0A0BA2F3070F0099ULL, 0x0F1A5E8F745FF6CCULL, 0x9AD48539047B2BC1ULL, 0xB75CE258ABC45122ULL, 
            0x2225822B59FBC2B4ULL, 0x66169B104E410C1DULL, 0x49D0F7D6A520F521ULL, 0xFDB9EE90F6A4C6B7ULL, 
            0x06A2C481D798EBDAULL, 0x75AC3D355F39AF87ULL, 0x22A19BA25E84495FULL, 0x8FA59C7D26781713ULL, 
            0x0924F63EE96F432FULL, 0x70861CAEF8B29E1CULL, 0xB6E45880E1FBC0FDULL, 0x5F9D550B64CB183AULL, 
            0xD9B056DBA6516941ULL, 0x588C6C28A507E1DDULL, 0x353963526882C12EULL, 0xBEF872B1D5AE7048ULL, 
            0xB94303AFE27D2F4BULL, 0x3F2F4CD1827192C6ULL, 0x7FA481339D030BC9ULL, 0x9AD0D35BEEE037C0ULL
        },
        {
            0x69CF4DE870CC8AEFULL, 0x476ABC424087416DULL, 0xF1F51FF2799B5A15ULL, 0xA36C711CD4F6B2CBULL, 
            0x39444154F14A90AEULL, 0xC579950997DEB2E6ULL, 0x5390CD4A54B7B3EBULL, 0x1223B29EF4ECCE97ULL, 
            0x3867561AF37CCEAEULL, 0x855AD834D5CCD2B0ULL, 0xFCB493B635DC58C5ULL, 0xD84950B25FBDD473ULL, 
            0xF10E2AB9547A4DCDULL, 0x28746F70515318E6ULL, 0x4C5DABAD94CFC273ULL, 0xAD4139C8B87F28DAULL, 
            0xDCEF585B036B5081ULL, 0xEC827BD79AFF1367ULL, 0x346437EE8063C81BULL, 0x02C5A1F7F6353167ULL, 
            0x1FC51ADAA37E6A0AULL, 0xFF36FB5F1D5F4206ULL, 0x95C0BA6EA8F3D850ULL, 0xF42E0A25D084684CULL, 
            0x069058351D9B4F7DULL, 0x5F3D736BF656F506ULL, 0x3CEBDF98409197A1ULL, 0x4D23C9DA5AE2741FULL, 
            0x7812E041A637E652ULL, 0xE183DCB21A9B1A62ULL, 0xC7AB8A7EE2F8E153ULL, 0x8ABADB4CD6C21F12ULL
        },
        {
            0x13CF98DD9E4807E1ULL, 0x70DD5186BD13F0C8ULL, 0xDEB846006C80CD93ULL, 0xB24BF0E242A239C5ULL, 
            0x8CCBFD13EDA48A7AULL, 0x7EAABA694CA592F0ULL, 0xE13905994D500AACULL, 0x5527843FE1009073ULL, 
            0x446BDA08082407E0ULL, 0xE4E3BC58FC04F33CULL, 0xD2859C1C88DDA495ULL, 0xC04E91468A9A3933ULL, 
            0x092FFDA26944824EULL, 0x64670E56F76AE4D1ULL, 0x0B41DEEA7A7EC567ULL, 0x3428617A2D6CB377ULL, 
            0x6086CF2884D34673ULL, 0x71C91423644C2367ULL, 0xE8E35731F4D60012ULL, 0x7D7874D486A6DF98ULL, 
            0x9CAF804407DC7B7FULL, 0x778E3DFFD79FF92DULL, 0xE3A7C440B48EF3E5ULL, 0x1026D45CB6D0CE48ULL, 
            0x53373A111D33D0BDULL, 0x7056F5A259519FD6ULL, 0xE2F6CFE0F882839DULL, 0x4C86DC642A6797BFULL, 
            0x492E0082E0EF9773ULL, 0x8745D40109CA20D7ULL, 0xAC13F244E8B5916AULL, 0x932716244D1434F3ULL
        },
        {
            0x788C9E1EDF970521ULL, 0x62024DB26FBA201DULL, 0x097154B87FBE1D1CULL, 0x6525023A26399703ULL, 
            0xC50E6A8F06C470E0ULL, 0x343A07FCD108CCF0ULL, 0x4AE7D8929968CE0AULL, 0x232C7947FE46F1DBULL, 
            0x8029AEA8FAC49ACAULL, 0x6515E712570AD742ULL, 0xFD819E86385545A4ULL, 0xE1EEEBC913CA4E95ULL, 
            0xFD5662E1751E4A4FULL, 0xB84F688046998DEAULL, 0xB1F398C364A92BAAULL, 0x7F4D7EFFB13073E2ULL, 
            0x4998D28182B31827ULL, 0x900D6C497C122932ULL, 0xF3F6BAAC2A7A98D2ULL, 0x5160C4442C53C452ULL, 
            0xC9789B4C08517873ULL, 0x034E8FFCA75453F4ULL, 0x48E8D2A22100715EULL, 0x3C58AD55655D3AD6ULL, 
            0x40CF84BCCC37132BULL, 0x8347A5DDBC00EB4CULL, 0x28A9985D210E433BULL, 0x0075EBF9728414A2ULL, 
            0x7DDF8F4BE1116301ULL, 0x272F638459479B8CULL, 0xC584944C1A80456AULL, 0xCAD260A9A88CDB18ULL
        },
        {
            0x2B32D0A39C254AAAULL, 0xF875038788BC887BULL, 0x14628050CEB9D4A3ULL, 0xC3E216A4FD319F4BULL, 
            0xC982DF1EBA02106CULL, 0x9653D559DB1D194BULL, 0x77E0932F83D5519BULL, 0xFD7D8D32929F9EBCULL, 
            0xB970EB2FEC03F76FULL, 0x5AA2053E5D1DA30DULL, 0x76665AC85EE46A68ULL, 0xCB93F7D79E94FC4DULL, 
            0x2B0DE3716F427B59ULL, 0x5F83F52F6D299B9FULL, 0x5445D9CFA5ABCF13ULL, 0x99342C1B121CF1D7ULL, 
            0x8F61DAEFE60859D7ULL, 0x64959AC7545E037CULL, 0xDA81A2C05CBD3425ULL, 0x4E9F12324DE463F1ULL, 
            0x0828E687F9D0146EULL, 0x976EF473FA6A2FA8ULL, 0x8F9D7482DC0BFF56ULL, 0x9A3F4699C2CCDDA6ULL, 
            0x4489F4DCC164233BULL, 0x0EABDCDDD139DE6EULL, 0x6ADA3686C402F61DULL, 0x8F412CABE4C2F658ULL, 
            0x92A699D971BA9A08ULL, 0xD9195EF3A6AD5524ULL, 0x6A82C0E4A61991C1ULL, 0x96BC1C2FDDC686B0ULL
        }
    },
    {
        {
            0xAE8A5467519C75D1ULL, 0x23B78DEDC3226E30ULL, 0x876DAFBE609AE3C8ULL, 0x38F995B3ECD4E6B7ULL, 
            0x52ADB0C7AB603CD1ULL, 0xABE42D48738EE6F3ULL, 0xC0ED694BA1120B59ULL, 0x59B8EEB1C0491BD7ULL, 
            0x2B05033DA5A11C5DULL, 0xA4C725E961AA554EULL, 0xB4863454B2E063DEULL, 0x622211352DEEC116ULL, 
            0xB87060A3EB722BB1ULL, 0x7F480C98390CC7DAULL, 0x199BCC21A6A1DD6BULL, 0x41D74C501DD99D62ULL, 
            0x534C7AB8C80DAE74ULL, 0x169539FDFBB7677CULL, 0x38FCD1E1B7DF2365ULL, 0xE69B67A2043DAC94ULL, 
            0x134FC013221F2B90ULL, 0x76542B1043FD3FAEULL, 0x39EF5F2F03D69B19ULL, 0x4C99BCAA4C3E9AE9ULL, 
            0x793B7E71A0EC8B31ULL, 0x27D71C88A37378ECULL, 0x4E13CFBCC5D41546ULL, 0x97A8954EC6CADB72ULL, 
            0x01BC760A4FBAADF1ULL, 0x9A621784C6090F73ULL, 0x584932BE3BCA0E37ULL, 0x871A7C2ECA1CBB21ULL
        },
        {
            0x92A34C99D8D25550ULL, 0x307BEA8ACDE6F86FULL, 0x465C2615B0611A1BULL, 0xD75E8C8E454247D6ULL, 
            0xCF07E58FBA6EC667ULL, 0x855BDD9D9629D1D0ULL, 0x12C6545AF0EBF559ULL, 0x013A0A766F56D4FCULL, 
            0x5DF03142E3ABBC31ULL, 0x73D8C7353148E723ULL, 0x29096A7CD4C69301ULL, 0x2F820F8FA15878D8ULL, 
            0x5B401DD47D2E2076ULL, 0x077D740E5B180B19ULL, 0x4F569DD6D0ED0B7DULL, 0x2E7AC3350D635206ULL, 
            0x02D7CC011161F7BDULL, 0x867A53F6B69B2403ULL, 0x7A5CCC2FE1E487EBULL, 0x0D5956C19FA13A62ULL, 
            0xC6DF9875648C6726ULL, 0x7D4829B6E92D854AULL, 0x98D1D558E2CD3C5CULL, 0x4F535DD8D9C057DFULL, 
            0x0C6C04C90BA2282AULL, 0xC077CE905025A28DULL, 0x522782D584BC2333ULL, 0xBDAA005AD1108BC5ULL, 
            0x2CE399EC2AEE8752ULL, 0xBBD7F2651D3477CBULL, 0xB5B7C0A093B45DC7ULL, 0xF866D0281B7F16D4ULL
        },
        {
            0xE79FA3F36AC28F96ULL, 0xE3A5572C4C31ABA1ULL, 0x1D3EAD3C17BC7796ULL, 0x75AA7A45DEC2D07BULL, 
            0xE00C6244496917E6ULL, 0xFE486D7F11317A94ULL, 0x2DB13F25D52CBB92ULL, 0x3AD55A04511018CDULL, 
            0x3D56EB79193C5BD5ULL, 0x6195E3E42EBA824DULL, 0x514AC8B16B73AD61ULL, 0xA5213F3F1DA1CE65ULL, 
            0x091CC8DD894D79C5ULL, 0xBCEC356C5E1BA207ULL, 0xEFCAC272FA497C7AULL, 0x3E1A58FDF9AC8971ULL, 
            0x451BB9A98EEEE646ULL, 0xA05CD861415CB8BFULL, 0xA5F46B357C1406C1ULL, 0x404D7EEED2641771ULL, 
            0x308EAAA3E121F94BULL, 0x192ED881CD9C423AULL, 0x5272ED165C2B4640ULL, 0x0CB9FF48FB430776ULL, 
            0xF7E973A130618FA5ULL, 0x8679DFABA2593BC6ULL, 0x231506DD435B999CULL, 0xC5D674A148FE10D3ULL, 
            0x793BD7F8EF9E13CEULL, 0x8865743A603C8C69ULL, 0xDA0D1226C43EB86BULL, 0x5C9408624586959DULL
        },
        {
            0x45F79E3E8B040147ULL, 0xC5B82893C698A865ULL, 0xF5A92847B04C08C3ULL, 0x47CD296C27FC1EBAULL, 
            0x001CC0DBCAC1B748ULL, 0x05BD0E844A77F8E8ULL, 0x8D7503D5512D1B91ULL, 0x24C4698D79E82C1AULL, 
            0xE4711717CCE77A56ULL, 0xB635E584CBAE0FD1ULL, 0x23B19E66D208BA86ULL, 0xD3ACD678D94DC278ULL, 
            0xAB80151E4FD9031DULL, 0xC7E92A2668383FD7ULL, 0x848CC93E12FBC8E2ULL, 0x75137765F61D12B2ULL, 
            0x63DBDD9FA4CD0809ULL, 0xD60B08C901779241ULL, 0x7783BFF8A7B193E3ULL, 0xF5705F39132BB378ULL, 
            0x8FA277C307C9D6FAULL, 0x13D9DD5462DE8134ULL, 0x99F0427680D72842ULL, 0xD2C504D3BE97BC10ULL, 
            0xE76AD100F798F3D4ULL, 0x2ECE8A7A7D4960C2ULL, 0x25FC6B6ED74C4621ULL, 0x4B85F56B077CC2A1ULL, 
            0xD2F3CB0B1B0802C3ULL, 0xBA7FC25CBB52841DULL, 0xAA98D107AD560094ULL, 0x992A81A87B9AA672ULL
        },
        {
            0x4E106CBAB2AB342DULL, 0x610C84C9F6C64AAFULL, 0x3F2C506BAB261AAAULL, 0xBB8A3AB27EA5F73CULL, 
            0x6F6F15EA859B28CDULL, 0xD8BADEBCB22F77D9ULL, 0x91ADF59F10AC02F0ULL, 0xC75E76633FB29B87ULL, 
            0x01648F6AA338DB17ULL, 0x43B86FE7BB3EC993ULL, 0xF6DD8C2C47A8D854ULL, 0x45FAA71B48EF4C73ULL, 
            0xF9DED7E82B348A0BULL, 0x17C6B61ECAC2D75AULL, 0xB80EF92162F4B07DULL, 0x10A18545724BC108ULL, 
            0xF65DE8FE3140E307ULL, 0xA00A6317F99655D2ULL, 0x1045CE26C97464BAULL, 0x2CBBFAEB78DE31DCULL, 
            0x34639236D52D86DFULL, 0x8A5C9DE9DA346438ULL, 0x3B964F0D39803E20ULL, 0xC77FF3EA54FCD7ECULL, 
            0xEC324191B60AF9F4ULL, 0x9F7978BB9CE66CA9ULL, 0x2462B3788FA91290ULL, 0xBB6842FAD4A0152FULL, 
            0x3E7DBB6F4759AD53ULL, 0xA1FED484D79ACAC1ULL, 0xE645F34CF15D0FF6ULL, 0x516EC6C313651E43ULL
        },
        {
            0x6E4098E08BADB5AFULL, 0xA1A57EEF5E0E357AULL, 0x1340D3B962F127DAULL, 0x17693F74F3D1500BULL, 
            0x520334DE0FDA9A25ULL, 0xD7DD9B8B33AA6EC9ULL, 0x44A30ADC3DAD4677ULL, 0xCA4602AA60202F91ULL, 
            0x28E0426CD5507D85ULL, 0x3DD71B27A0CDD54AULL, 0x3C7AC42F81745F1AULL, 0x265F49024B7BFB48ULL, 
            0x7BC9F3AE5EC6B3DEULL, 0x93246B59FC508334ULL, 0x88E0414CC644CC6CULL, 0xA4EEB5440EFE9363ULL, 
            0x0F4DFAABC7B46B11ULL, 0xBE5A415EBAB952E9ULL, 0xBE378475400289B6ULL, 0xA06E6C21E73FF25AULL, 
            0x8B7DBB1826E4D36FULL, 0x7B15CE41044A87DCULL, 0x4E58BD1F2742D34FULL, 0xDDFB06B1173B3F2BULL, 
            0xDDB2CEF80C22B465ULL, 0xE36543B56829025BULL, 0x3B82F0FE57EB3152ULL, 0xC5A64B412C413642ULL, 
            0xCCE0CD8F6860187EULL, 0xAD9BAC98AD96DE77ULL, 0xF2C7C5BC0B3E7584ULL, 0xB3FA003FE1959EF3ULL
        }
    },
    {
        {
            0x79405A447E3732CCULL, 0x3B6F85DDB0FEE2CAULL, 0x5A6AB420C6ED63F8ULL, 0x2C717C47532AAD9EULL, 
            0xA6C8EF82D9F8C22CULL, 0x3F22408D8E09A5FBULL, 0x1A25BA2CB8D52071ULL, 0xCF29DBA267149D6EULL, 
            0x78F6830DBEC60C3FULL, 0x6E3FC0F32CE89BF6ULL, 0x18040622A505424EULL, 0x6A972DAE3F33C7D4ULL, 
            0x8B8F3F6036FD8DB2ULL, 0x8E60E79940EBF8B4ULL, 0xC895613B8C9F6795ULL, 0xC887F87D1979D9EAULL, 
            0x96B5A47FE0858DA1ULL, 0xE74F89B8FEE77E3CULL, 0x184108EC5C0D3A6CULL, 0xFCAD3639DE999394ULL, 
            0x81675D7ADB09A63AULL, 0xAD1847DD1046A57BULL, 0x773927DB3A1CDCABULL, 0xFCB94F55CC5010D0ULL, 
            0xA9455A643F49A970ULL, 0x8F2C1664EEB670BFULL, 0x5B624CE91368A4BDULL, 0xFC17FA7BD07C7773ULL, 
            0xF3028329F1DA1AFDULL, 0x1E9FCC9E9682FF9EULL, 0x5111C3EA6B82C312ULL, 0xA43145F47BE45025ULL
        },
        {
            0x17D361342B2E7897ULL, 0x8F5D09214F3C6C58ULL, 0x6A44AAEF8CB1D4D8ULL, 0x52D89D5AD79DC1A4ULL, 
            0x5A52946CFD61DDF1ULL, 0x1674FFBC1A080EA3ULL, 0x63DA9A74E42AD52DULL, 0xD113400C4E0B9CBBULL, 
            0x8A452E51C4C2F7BBULL, 0xEB1578BA62B2E80FULL, 0xD044C8EB050B69E7ULL, 0x461429DC8E57727DULL, 
            0x60E898BDAB70F20CULL, 0x2CAF73978A62CEF4ULL, 0x3BC744C24EC2213BULL, 0x57E2AC29CA3C8D25ULL, 
            0xF11188878333FFD5ULL, 0xF33B79DF58F86DB8ULL, 0x16E84FBFDABD34F6ULL, 0x2D974A7E0E43C4BAULL, 
            0x1493E8FDBA4567A2ULL, 0xBD1C4BB2521135C2ULL, 0x8CCA7BDE2D8D9E19ULL, 0xCC74495E5BD22FAFULL, 
            0x7847BAAA43097FA1ULL, 0xDAA1FCEF33F725E5ULL, 0x5160791915DA8EE0ULL, 0xAA699A6CB88F00B6ULL, 
            0x150D4C72DC1D5EDAULL, 0xA8CA11EB60901247ULL, 0xAAF606E95C47A23EULL, 0xDFDF4DA36AC1917DULL
        },
        {
            0x41F9C59DD2CFCD8BULL, 0xC2985B11F7E00CECULL, 0x2C3FB30505D9064BULL, 0x25E6C99DB8C89CB6ULL, 
            0xFC41F5A9AD9427E0ULL, 0x88EB7B9B735C18A3ULL, 0x13421E1D0E7FEEFAULL, 0x88339DC3302D7759ULL, 
            0x426A7526926E9B8DULL, 0xC0532BF5A2B68FB0ULL, 0x5F29875842C642B3ULL, 0xADD564114270E17EULL, 
            0x942A97C933554D00ULL, 0xE17A81B3E71C8CE1ULL, 0xEEFCC46025AAB880ULL, 0x2E2836B5D92008CDULL, 
            0x3192A4A2491EEE6DULL, 0xAFC3F7F60E266AB4ULL, 0x660204F4E4E7FE25ULL, 0xF63F6614D323D0D9ULL, 
            0x6F018BEB6161D130ULL, 0xD9BBCBEBED5357F4ULL, 0xC813F928E05DE475ULL, 0xB0E36AD104BA3203ULL, 
            0x5402F3067B9AE9BFULL, 0x0EEB2CB1657B91D3ULL, 0x755D768B9560BEBBULL, 0x3CBBB05539B66B45ULL, 
            0xCCD49EDF8A74606FULL, 0xD0B268FB0A16FF61ULL, 0x929F29537C1DCB64ULL, 0x74FAECB772A96956ULL
        },
        {
            0xC1A9D1A70FEF81C9ULL, 0xC9D2472242886CF8ULL, 0x23650FE3D67EC1EBULL, 0x80E70C296D236F4EULL, 
            0xC87E17789E3170DFULL, 0x834369DB496F6ABCULL, 0x961D67AD1EF2223AULL, 0x1945B1E99F2AEB3BULL, 
            0xF1EC20AC7BD02D0CULL, 0x9326AF88A1F06335ULL, 0x3242A0F6B623EE87ULL, 0xB1D41DF0BCBCC083ULL, 
            0xCCA421F445C45BDCULL, 0xB4D56CAAD5F6098CULL, 0xA30EB4CB2760F060ULL, 0xD5EA494842A16B5EULL, 
            0xCBD242B2F30BB596ULL, 0x4ED7770CAAE2DCD5ULL, 0xF6692F9E8CE03EDAULL, 0x1E83DA78EA3C388CULL, 
            0x211B88BE3112CB8DULL, 0xFA224DD2C98BE42AULL, 0x40CAC0940D035391ULL, 0xAF5563FD81D04205ULL, 
            0x98D3E998C88251A3ULL, 0xD612269A9C152D87ULL, 0x72F20E2A76E09455ULL, 0xA3956707EB0A96D1ULL, 
            0x22CB983E5BB0BE7FULL, 0xC9DD0495D591F6EEULL, 0xD785E1F64A6FAFC6ULL, 0x62B336BEB3D604ECULL
        },
        {
            0xC53CD76CCCAB7FCBULL, 0x8182B4D9053BA30EULL, 0x2BA06DC576F039BDULL, 0x2BA2CA86819786B8ULL, 
            0xEB73654547DA73BCULL, 0x9639ABDE7F4B17BBULL, 0xF832849097DEB20CULL, 0x190E6A18C530F840ULL, 
            0x578F640839E5ACDAULL, 0xEFB9647E6FDB87BEULL, 0x882C872CB1C3B11AULL, 0x0B9A5AA3FFA151D3ULL, 
            0xCFA70B38C3C2C323ULL, 0xDEF92683D3C78DA3ULL, 0xBFA678914E183B6BULL, 0xA8BA85E9D20FE16BULL, 
            0x7FAB407E9B7D2D01ULL, 0x5C2A2114E924FDBFULL, 0x7818A3279CB5D9C5ULL, 0x38BCCDE5142EF270ULL, 
            0xEC3C987F0086D03CULL, 0xE6B91E8E06B9392BULL, 0xFF7FD12677866474ULL, 0xF5A600EC26442F94ULL, 
            0x8C5D4C487B707FB8ULL, 0xAB29C803FFCBBEE1ULL, 0xCB4767DF4A09D82EULL, 0xB87E95284447BA98ULL, 
            0xF0AF3C86D81A70ACULL, 0x22B872D8FFAA32A2ULL, 0x3C49845EA4272044ULL, 0x58A883C3ABD5D0F7ULL
        },
        {
            0xDBB1BD592EBE1EA3ULL, 0x7F07B71659F0A33CULL, 0xA580688614421F82ULL, 0x494CA1E280CF0966ULL, 
            0x163403F3FDE61718ULL, 0x1B28D711D69DDB40ULL, 0x3BEC31ADD96C78C8ULL, 0x5724D530E8A3F420ULL, 
            0xD6CD4BC0D39763FFULL, 0xC3C001690C77CAE7ULL, 0xC48E59FE67C8B9F6ULL, 0x2026A6CDD91A3E9FULL, 
            0xB5AF20EDE0B8F993ULL, 0xCB2AA0FA85C92046ULL, 0xA3105B5A4C077B9CULL, 0x6342EF221FF9AC3AULL, 
            0xE313BCA7BE0A7BF4ULL, 0xEEB8E3B18EC185C5ULL, 0x3819D680688B67BEULL, 0x37D11F33DBF082D5ULL, 
            0x7DDEE459D025B6A1ULL, 0xC170602191EE1C07ULL, 0xB2443182A18A85BAULL, 0xD43DCA54519E8339ULL, 
            0xADE66516EE9D2E94ULL, 0x5123FA3C78D2B898ULL, 0x03B59226E32582DAULL, 0x807681845D7DDC0CULL, 
            0x635780A2B4085754ULL, 0x82B26558A7860502ULL, 0x96463DAE734793C6ULL, 0x2BAEE236A1B425FEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kTwistConstants = {
    0x720BAE33B542424FULL,
    0x7FCA0C903F94E40EULL,
    0x68B81D14952AD266ULL,
    0x720BAE33B542424FULL,
    0x7FCA0C903F94E40EULL,
    0x68B81D14952AD266ULL,
    0xBE85C333F4D341D9ULL,
    0xC50998E3EE04E094ULL,
    0x32,
    0x3B,
    0x9F,
    0xAF,
    0x6A,
    0x83,
    0x8C,
    0xCF
};

