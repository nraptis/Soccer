#include "TwistExpander_Mimosa.hpp"
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

TwistExpander_Mimosa::TwistExpander_Mimosa()
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

void TwistExpander_Mimosa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB5966B7422048A8BULL; std::uint64_t aIngress = 0xC800EA40A8CA98E0ULL; std::uint64_t aCarry = 0xC194CD021D6D6990ULL;

    std::uint64_t aWandererA = 0x986CDE84B9C35902ULL; std::uint64_t aWandererB = 0xB344A2DE529DEE1CULL; std::uint64_t aWandererC = 0xA8615115E356BDA1ULL; std::uint64_t aWandererD = 0x8FCF1017B93B5FBBULL;
    std::uint64_t aWandererE = 0x8D1472DE502299CDULL; std::uint64_t aWandererF = 0x8A9312E72555609AULL; std::uint64_t aWandererG = 0xAAF8FEEAC890B6BFULL; std::uint64_t aWandererH = 0xCF59F16CA2966D3FULL;
    std::uint64_t aWandererI = 0x841EF934FEC0A520ULL; std::uint64_t aWandererJ = 0xC95BFA7C0CF4FACBULL; std::uint64_t aWandererK = 0x80EA9030E4E34A45ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC77FE5AFC19CC0A7ULL;
        aCarry = 0xD9CD90AEDDA41AB3ULL;
        aWandererA = 0xA528CE37E7AA2A37ULL;
        aWandererB = 0xE7ADC634932EACA0ULL;
        aWandererC = 0x9B293103F26662C7ULL;
        aWandererD = 0xAFEEDCC2BEC0F6DEULL;
        aWandererE = 0xB9A5C82FB0239052ULL;
        aWandererF = 0xC3F1FDA5B9304BEAULL;
        aWandererG = 0xB759363E6C146718ULL;
        aWandererH = 0xA30A4FC69F13CFCAULL;
        aWandererI = 0xD874A4AD2235917AULL;
        aWandererJ = 0x80C2B24F5ED98885ULL;
        aWandererK = 0x9205B782DDF2EC93ULL;
    TwistExpander_Mimosa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAF0B829683D23510ULL; std::uint64_t aIngress = 0xB4CFF2793099EF19ULL; std::uint64_t aCarry = 0xC4827E5502D108CBULL;

    std::uint64_t aWandererA = 0xAD113FB954F387E8ULL; std::uint64_t aWandererB = 0x895ED6417EB2F907ULL; std::uint64_t aWandererC = 0xF490003A983F3E0DULL; std::uint64_t aWandererD = 0xE8394FF5F9154F74ULL;
    std::uint64_t aWandererE = 0xAB25E75CA62E31B1ULL; std::uint64_t aWandererF = 0xD5D8052FEF520A3AULL; std::uint64_t aWandererG = 0xA637962BAB4463A1ULL; std::uint64_t aWandererH = 0xEAAE7B3A0A73E24DULL;
    std::uint64_t aWandererI = 0xA8D0A534A8C05A4BULL; std::uint64_t aWandererJ = 0xDD4EE0C65E8BA39FULL; std::uint64_t aWandererK = 0xD768875D850C78F4ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBA2B0CA0E78EA78AULL;
        aCarry = 0xC9F477E1FA4921C2ULL;
        aWandererA = 0x8D4A6020188C5B09ULL;
        aWandererB = 0xCC57E6208405B60DULL;
        aWandererC = 0xCCE0B2FE6F5C303FULL;
        aWandererD = 0x9D9C968AA14006A1ULL;
        aWandererE = 0xFE24D5A7D17E95F7ULL;
        aWandererF = 0xFBD8D9074A7C8E82ULL;
        aWandererG = 0x897C2FAFED01F542ULL;
        aWandererH = 0xEAD007B0547EB84EULL;
        aWandererI = 0x963C1D2DA089F287ULL;
        aWandererJ = 0xF11326894C60C5B6ULL;
        aWandererK = 0xD272832716B3D5B3ULL;
    TwistExpander_Mimosa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x940D62CBEAC3370BULL; std::uint64_t aIngress = 0xA71678691F728DE8ULL; std::uint64_t aCarry = 0xCE0C2134521348A3ULL;

    std::uint64_t aWandererA = 0xD99B2ED273B6C78DULL; std::uint64_t aWandererB = 0x917CB7FFA8FF8669ULL; std::uint64_t aWandererC = 0xD2466362E73B1A41ULL; std::uint64_t aWandererD = 0xDF0F1340F0A18FE5ULL;
    std::uint64_t aWandererE = 0xF91F82C454FC4A0AULL; std::uint64_t aWandererF = 0xDEB6CCC686485093ULL; std::uint64_t aWandererG = 0x9F49EB36C23AD1E7ULL; std::uint64_t aWandererH = 0xF5A349A1211D7BD9ULL;
    std::uint64_t aWandererI = 0x8C5CABC639C2A0ECULL; std::uint64_t aWandererJ = 0x94A7A27B5DF60D33ULL; std::uint64_t aWandererK = 0xF837328E0EB6A445ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEFC2649E37E506B3ULL;
        aCarry = 0xE42D0FA74F6D01FEULL;
        aWandererA = 0xF2F9A17C2B5ED61DULL;
        aWandererB = 0xF7AE64753D065769ULL;
        aWandererC = 0xFC8902A6FEDEF0E0ULL;
        aWandererD = 0xC59497656BA521E0ULL;
        aWandererE = 0xBF8307B2725485C1ULL;
        aWandererF = 0xF9020DAED5488258ULL;
        aWandererG = 0xB8D5ECB396210BF2ULL;
        aWandererH = 0x9E180F5880AA6A13ULL;
        aWandererI = 0xA63259E424347303ULL;
        aWandererJ = 0xA7AE7AFABF2F4CCCULL;
        aWandererK = 0xBFC1CA88C4894489ULL;
    TwistExpander_Mimosa_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFD164EFC698CB6EEULL; std::uint64_t aIngress = 0xB3C436E7BA531A21ULL; std::uint64_t aCarry = 0xB2391008DCC0EDD6ULL;

    std::uint64_t aWandererA = 0xE02EC5D2E9D850DDULL; std::uint64_t aWandererB = 0xAC1D15B3EE14C130ULL; std::uint64_t aWandererC = 0xE1E75FD1F5CEA2B1ULL; std::uint64_t aWandererD = 0xF0DA7D6989B3AF26ULL;
    std::uint64_t aWandererE = 0xB1E2A324A3F75537ULL; std::uint64_t aWandererF = 0xF2B678C47A99CB42ULL; std::uint64_t aWandererG = 0xC6DD0A32980AC121ULL; std::uint64_t aWandererH = 0xD791A52DC58B33B5ULL;
    std::uint64_t aWandererI = 0xB9FBE352C81BBECEULL; std::uint64_t aWandererJ = 0xA0B4BC407C169F17ULL; std::uint64_t aWandererK = 0xB1C2925F8D11CC25ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x85ECC612A153BA93ULL;
        aCarry = 0xCE3CE0646DFF0E6AULL;
        aWandererA = 0xEE27462B6C10A1BBULL;
        aWandererB = 0xCC8035F8405E774AULL;
        aWandererC = 0x9E859AB7336C16A0ULL;
        aWandererD = 0xD56157B5D2A9995DULL;
        aWandererE = 0xD57C0D305D7B3E34ULL;
        aWandererF = 0xC79780C8C2B7FD33ULL;
        aWandererG = 0x9615E629B8153463ULL;
        aWandererH = 0xDA8483621E528DEBULL;
        aWandererI = 0xCC477F5DBE8A5012ULL;
        aWandererJ = 0xC9324BEC4D1EA262ULL;
        aWandererK = 0xA52BD336C04A5505ULL;
    TwistExpander_Mimosa_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mimosa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE80FAE906043B9CBULL;
    std::uint64_t aIngress = 0xC00184B43F036F23ULL;
    std::uint64_t aCarry = 0x92BF3DBFA121BAF4ULL;

    std::uint64_t aWandererA = 0xC47E7FEE96C012BEULL;
    std::uint64_t aWandererB = 0x982C397FE224257CULL;
    std::uint64_t aWandererC = 0xE2DBBE1209623BE4ULL;
    std::uint64_t aWandererD = 0xB0E57E9361E784EFULL;
    std::uint64_t aWandererE = 0xE30CDA208AD75152ULL;
    std::uint64_t aWandererF = 0xFF78C945A49F4EA5ULL;
    std::uint64_t aWandererG = 0x8C6B7F395D121FDEULL;
    std::uint64_t aWandererH = 0xE0B23E0EFCA69FB4ULL;
    std::uint64_t aWandererI = 0xFF3A0C77BB8E36E6ULL;
    std::uint64_t aWandererJ = 0xFF42BF6616F2C783ULL;
    std::uint64_t aWandererK = 0xF06C925D1C2793B2ULL;

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
    TwistExpander_Mimosa_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KEY(pWorkSpace,
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

void TwistExpander_Mimosa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF3494BA0E9A3B22EULL; std::uint64_t aIngress = 0xC65A8BF83701F2C8ULL; std::uint64_t aCarry = 0xDC921730670F5E80ULL;

    std::uint64_t aWandererA = 0x85430902440C667FULL; std::uint64_t aWandererB = 0xE10B9748F12EE247ULL; std::uint64_t aWandererC = 0xF56E3D20C6AF5000ULL; std::uint64_t aWandererD = 0xC3DEDB4E9F0F24B6ULL;
    std::uint64_t aWandererE = 0xDE46F37644816FE0ULL; std::uint64_t aWandererF = 0xD0232F9CE05D5990ULL; std::uint64_t aWandererG = 0x8400874682489632ULL; std::uint64_t aWandererH = 0xC8344DC2BFC93F02ULL;
    std::uint64_t aWandererI = 0x9903C18DAF0AAAF6ULL; std::uint64_t aWandererJ = 0xF79BF174F7FABAC3ULL; std::uint64_t aWandererK = 0xD6B323DC15628892ULL;

    // [twist]
        aPrevious = 0xACD7DD42DFBAB601ULL;
        aCarry = 0xDD785165955CA6FAULL;
        aWandererA = 0xFB7262D34111CC7CULL;
        aWandererB = 0xB4BCF8F0F68B98FFULL;
        aWandererC = 0x9D1521F9E2F9DA1EULL;
        aWandererD = 0xDF70E8BF2B052033ULL;
        aWandererE = 0xF90F515FA3D2A71BULL;
        aWandererF = 0xA9F14420CFDFBCA7ULL;
        aWandererG = 0xAD938228583F134AULL;
        aWandererH = 0xC4624BB2BAE9E883ULL;
        aWandererI = 0xBD4C771D78E47CD4ULL;
        aWandererJ = 0xD4688BCCE2D0A309ULL;
        aWandererK = 0x8C57A7FE80263D5AULL;
    TwistExpander_Mimosa_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Mimosa::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Mimosa::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Mimosa::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 19 of 33
    // Exploration cases: 0
    // Structural maximin 517 / 674; family total 9564
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1465U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 19 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 9562
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 925U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 19 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1054 / 1248; total 19521
void TwistExpander_Mimosa::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
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
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 903U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
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
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 19 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1056 / 1248; total 19488
void TwistExpander_Mimosa::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 814U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
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
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
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
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mimosa::kKeyRotateSalts = {
    {
        {
            0x2F1A9AA0155B268CULL, 0xE25BAC8C2B4942A7ULL, 0x63CA3759E3362728ULL, 0x81ADD0E6050D490FULL, 
            0x89333C5D8CC9549AULL, 0x5A713CD51922A037ULL, 0x3870A2B905C54803ULL, 0xEDB30D693B4F1AD2ULL, 
            0xBC973E161FC0E1EDULL, 0xA0E7924494E769BBULL, 0x116B0C7A761917CBULL, 0x5272C8F93E78C1E0ULL, 
            0x3D7FBF167F556A34ULL, 0xDE5886E8F5049389ULL, 0x79CF43BA8745478BULL, 0xFCA9BF9C6A20DF28ULL, 
            0xE5EF3A1C9CACB0C0ULL, 0x1E39A9145041A85BULL, 0x6DD7CAF2A02C677FULL, 0x9A810EEF5DA35BEDULL, 
            0x15D98A9FD275538DULL, 0xEBF4A4073CE9FB4CULL, 0x5FD1F2ACE8D1324DULL, 0x5CABB95164F9FF78ULL, 
            0x53EE3B4D943DB604ULL, 0xC0D341BFBB712521ULL, 0xEB0E388EA5ABF672ULL, 0x3050C316CDD003C4ULL, 
            0x74D42DB5BD9CDB02ULL, 0x0E595EFC4D92DA1AULL, 0x78D65D4276F4EAF0ULL, 0xF83FE020BCFA3DE0ULL
        },
        {
            0xFA54DB2838D4EBD5ULL, 0x8DFA3FD460AEC8CFULL, 0xB30AF7B0E761CFA5ULL, 0x6B6F1246723989AAULL, 
            0x97F398EFAD46205DULL, 0x1DE3FB7C60B1B51EULL, 0x9360DFF7A96B6595ULL, 0xE2DFD30CC5ACF36DULL, 
            0x251B1CC79A03C76CULL, 0x22B1C047BEF2E10BULL, 0xFE49F67DF4EA9505ULL, 0x1E4A82B026FB445AULL, 
            0xA2286F136BDC31EBULL, 0xECA1AD02EF798831ULL, 0x68EA8EFE523BDE0DULL, 0xB3FD741BC8315225ULL, 
            0xD12A2A57B9DCFE98ULL, 0xDE868B53A346D3EAULL, 0xFE0DC1D6F841610CULL, 0xB25D132F5CBCB6D9ULL, 
            0x7A5ECFE10A3E1EEFULL, 0xB8DBE786D3AB1E45ULL, 0x130EC7DF7CE7FC51ULL, 0x1BCA8E21CCA1D942ULL, 
            0x9D69469C1037DE3CULL, 0x4AE2E4421A709CCDULL, 0xEDB56ED227C03597ULL, 0x6575F1223FD9D380ULL, 
            0x8D972F4A66AD688AULL, 0x1A50308D7BD5AF95ULL, 0xDDEE35CE617DA9A2ULL, 0x6A6BD6024731856BULL
        },
        {
            0x0E7EF762A6B1BC61ULL, 0x4293E2C8F9BA561BULL, 0x7C30655A97A6D0A1ULL, 0xABE377CC13B357B1ULL, 
            0x13381D7E61BBCE86ULL, 0xC46B35501375AAD8ULL, 0x09778DDE2D990C3EULL, 0xD7FF587D9CFD9797ULL, 
            0xBB637AABA08C2FC4ULL, 0xB0503541DA48CADBULL, 0x764DD82A0AD07BE6ULL, 0x8B5D01A4A25368F5ULL, 
            0x9FB95083012761B1ULL, 0xB0DB77A90E820345ULL, 0xFED7ADFDFA47FC37ULL, 0x0E023FB7C255E89CULL, 
            0xF5097E9CF142B367ULL, 0x5416E72A0C79D09CULL, 0xE0BC48AC829DC65DULL, 0xE0C75C0CC59ECE2BULL, 
            0xBD37FA0932F0B8ADULL, 0x5D4F617CE118BD3CULL, 0xAAD3726D5570F751ULL, 0x9325386933D90A96ULL, 
            0xDDE968DE69C592DDULL, 0x94D9897BE57D9164ULL, 0xCF5B973DC2CE5DC4ULL, 0x5F5AAE04888CA0FCULL, 
            0x2882E29885314FE3ULL, 0xFFB77A4D9A266193ULL, 0x03037B4B64329C2DULL, 0x7A1189F7E27B239BULL
        },
        {
            0x1679CAD28FCC0209ULL, 0xE6BBE438AF31114AULL, 0xF71B7E0A18D42743ULL, 0xB25C708A39FBB865ULL, 
            0xD2E2DB2170542AACULL, 0xFDF70FC19809C610ULL, 0xEF1A79C92127A8F6ULL, 0xACD5BEA4599D329EULL, 
            0x6A11E4C69B70718BULL, 0x4B6E8F93EB3C8E54ULL, 0x3DEF042E6DAF93AAULL, 0xD200660B5DD2162CULL, 
            0x250DCCE730BA2E89ULL, 0xD24A978399D80047ULL, 0xDC9B64E14E963F45ULL, 0xF6BFB160D0A662E4ULL, 
            0xE1C3445B99719DD7ULL, 0x02163D4006F95AECULL, 0x67F0E703EEA364EDULL, 0x615253B56A985A69ULL, 
            0xBAF722E5036E7E16ULL, 0x5AAC245E8DB92442ULL, 0xDA81BF953E9FA01EULL, 0xF78E1EA871433C97ULL, 
            0xB6078AADB5A6854AULL, 0xC2EEDE44613716FEULL, 0xE948B8D5031CA38BULL, 0xBFCCBEAF3C728A0BULL, 
            0x49A61C6BB6BD4DCDULL, 0xA12F9D8E9DB6883AULL, 0xA51292C1E8CEBD57ULL, 0x2CE85BEE6784D158ULL
        },
        {
            0x41E63FFC3DADE90AULL, 0xC441B4DED4150CAEULL, 0xD39EC90D4C733FEEULL, 0x5DF7B2732A40C5EEULL, 
            0x3A03B8782DBD06D1ULL, 0x5B7A1A2E53B8FD4FULL, 0xCA917B22CDA7CE43ULL, 0x08A520B12B53D69DULL, 
            0xCB9CC617EC885B9DULL, 0x6C39332128F5DB3CULL, 0x6CABC7F7F6C75A2EULL, 0x4CBF8E7AB574307BULL, 
            0x950611F8BCC4B692ULL, 0xF9CFAE24EB578A5AULL, 0x228160727AE5990AULL, 0x5B83DF574A861315ULL, 
            0xF99F30A155CA8DE0ULL, 0x55FB22DBF60F3B3CULL, 0xB6E6A6DDC136BAB7ULL, 0x329458EBDD52F324ULL, 
            0x6A9424B388B359C4ULL, 0x06C6BC8F2374C270ULL, 0x73F93E8B521D2087ULL, 0x9F011F379B9C7198ULL, 
            0x4683A66B794E8D90ULL, 0x02574F8636853C20ULL, 0x0BDF1B476528AD31ULL, 0xEEDE73BFD6F42984ULL, 
            0x1E542E41C831B8FFULL, 0x550E94C403BA7B5FULL, 0x4B798CDCF0C106F0ULL, 0x009FE82A5B33A8F2ULL
        },
        {
            0x84ADD8D75E6C9D69ULL, 0xD407FFF11B44C935ULL, 0x22FB742E1FA27774ULL, 0x3E63F8C8A081756AULL, 
            0x155790A8933BBFD7ULL, 0xD51BB1586C6256B9ULL, 0xF64688CD053EF71EULL, 0x226CCE70E451384EULL, 
            0xCA6372B023985CBFULL, 0xB7FA55BA6F488FADULL, 0xAC265192F487ABB7ULL, 0x727C3E00F582A942ULL, 
            0xD10D6CAAEE0032CBULL, 0x472E35CE2DEAC93DULL, 0x62F7BA03D9473878ULL, 0x37ACA71B0A4E01BBULL, 
            0xA2337C491201E6CAULL, 0xF840AADC888BA1D7ULL, 0x07F5DCC83521EE51ULL, 0x2E88D0F7CED35D57ULL, 
            0x0EBE0825FA34295FULL, 0x8ABE95E79C64330EULL, 0x3E5F56CAB71276F0ULL, 0x36A09A386D4DA459ULL, 
            0xD1B243397CD4FA29ULL, 0x57B731B7106B1D6BULL, 0xB321441326110D4BULL, 0x932A69E0D3A0BE0AULL, 
            0xAC48F151A76210A4ULL, 0x8171240BC0377D63ULL, 0xCE89926C2CBB9BA4ULL, 0x9E99BA4CA85FA1CEULL
        }
    },
    {
        {
            0xC9550313FA9E598AULL, 0xC8DCA2A553406CA3ULL, 0x5AE604E89E0FD8ACULL, 0x93E5F385B6ED41F4ULL, 
            0x3035B268656434A8ULL, 0x91C946C0254C45DEULL, 0xD1A4E480091B934BULL, 0x276F4974C82BF1BAULL, 
            0xAD50A58BAE68B399ULL, 0x95E46F249D28842CULL, 0x58693EEB875B8951ULL, 0x89E08A51E2388065ULL, 
            0x0760AD4274E4231DULL, 0x0D35B388467F8401ULL, 0x817879FB763BE5D3ULL, 0x2351540703DB12B0ULL, 
            0x5E6DAF71020A1402ULL, 0x396D6E9795E65D57ULL, 0x23234989CC341757ULL, 0x0F9C26577B94681AULL, 
            0x3359333ED9BA40EDULL, 0xAF32ABB8D2B83E61ULL, 0x7AD25A1D9D78BEB3ULL, 0xF57039F7C8C55063ULL, 
            0xD58297B3BDC9F17CULL, 0x93AFF17F16F0FEB1ULL, 0x0927BCAF8DA4D863ULL, 0xC2C6B4F3CA0DC92AULL, 
            0xE73D3778DF6EFE3CULL, 0xC68EFA7A94D99FE6ULL, 0x51A2AE94AC80EC18ULL, 0x77CF8B19AD15B084ULL
        },
        {
            0x00BAD0499FE162C3ULL, 0x1AF52401E0BA8AE4ULL, 0xD3846C6F1DD65121ULL, 0x0E38497323CF89D1ULL, 
            0x749FA9201E2E2D66ULL, 0x4978B4A6368A9E48ULL, 0xFACF6D6225B3E9A5ULL, 0x7B8ECA2E336384AAULL, 
            0x7EA2250EDDC523ACULL, 0xE38FCA589953B8B7ULL, 0x0A3FDFADFE5006F2ULL, 0x779CD7643697331EULL, 
            0xCBE9084197FDA80DULL, 0xAAB9B176CC623CF4ULL, 0xAE2B17F40CC2CBE4ULL, 0x6C73D780512DF4C8ULL, 
            0xCBB14710CC44E524ULL, 0x214F1EC2F6BA080CULL, 0xC96E2AF6EBB30BB3ULL, 0x5B660C51561823BFULL, 
            0x0907A02BE6A4286EULL, 0x63E2CEA0ACE24D99ULL, 0xA0A0D5E61241FAAAULL, 0x12C0539E1E66FD5DULL, 
            0x0462BFF5F9E0A2A9ULL, 0x278F260C87876466ULL, 0xF31C8FD2923E0EDBULL, 0xD064D0FAED48F4BEULL, 
            0xC597A43DC8A1A442ULL, 0x88F894191A3246F6ULL, 0x63E2EB2F5C43DACCULL, 0xA1D2D9A584146664ULL
        },
        {
            0xEED0F39029D72979ULL, 0x155233DB21CF58B9ULL, 0x2D8215A2E18D5F30ULL, 0x0BC4BD7C9889FE89ULL, 
            0xE85A152826860C41ULL, 0x6AD55D8A5EF779DBULL, 0x9C8752FEA421F216ULL, 0x03241A4B205EB7E1ULL, 
            0xE88C181400C2CBAAULL, 0xB89CA4EB5F6CE2F1ULL, 0x46227D764140CB6EULL, 0x966654C62B21CF92ULL, 
            0x7DE3C8543B498F35ULL, 0xEFB34DA11618ED65ULL, 0x138F77612BD5CE93ULL, 0xFDF696F461285644ULL, 
            0x112C45DF38AA28A0ULL, 0xFA308D6F2F3FC56CULL, 0x1BA1F3FD980C5089ULL, 0x687A3D380BAD257FULL, 
            0xC13CA8ABD7CBB215ULL, 0x8915F16BE74DA3C5ULL, 0x5D836F274F91384AULL, 0xA4D7870C5F889DC6ULL, 
            0xE15D741F691B38D8ULL, 0x0256A8D7B2B726DAULL, 0x3A37236CE8788A06ULL, 0x166824D4596A77B8ULL, 
            0xB786FADA162B9EA7ULL, 0x036C5A1FCA324C90ULL, 0x687043C2B8FE3F95ULL, 0x33A4886B496513DEULL
        },
        {
            0xA44B29EC057F6A20ULL, 0x051E6424EB3E9423ULL, 0x4B0AE6490CDF484EULL, 0xFC74E37E77A234EFULL, 
            0xE37D9320389C1958ULL, 0xC5776B3A6B032023ULL, 0x7BFC41BC35B800CBULL, 0x4A7078589D6096D2ULL, 
            0x1B4F27C86873329BULL, 0xF6C34150B286A26FULL, 0xE46F6DC5AFF443DDULL, 0x98E2436EBEB8CDF1ULL, 
            0x634F28E798C72BD3ULL, 0x126A141DA4589B72ULL, 0xBAA29890D35F1323ULL, 0xF7FE9C815C6F4C58ULL, 
            0x4A93808B074FB303ULL, 0x49EBFEF586D6DADDULL, 0xFB2C5FDCBD748C7AULL, 0xD0BC45FF9D0325DAULL, 
            0xA2C6901820D3F2D7ULL, 0x020C952ABB3E8036ULL, 0xB3AD8C748B253B61ULL, 0x196BA59CF59C94A7ULL, 
            0x09510A38A028C904ULL, 0x3B5791FD1E36652AULL, 0xB8FA9C47985F4D4FULL, 0x764D63B985D2C995ULL, 
            0xA531EBC62D29826EULL, 0x4F1F1071CE3E111DULL, 0x6D0B78A96F9137DAULL, 0x2315F57775743808ULL
        },
        {
            0x35981756A81D7A83ULL, 0x0176F5EB19BB5ABEULL, 0x25A43B9F0C4DD72EULL, 0x22DC7806D5154032ULL, 
            0xCD236569BBEFFB6DULL, 0xDD8084129A1081D9ULL, 0x0ADA0170149488AFULL, 0x905AF02924703D24ULL, 
            0xE97B8B7262E7BDE4ULL, 0xC495EB23E5178983ULL, 0x9BE9A5E007E6C83AULL, 0x2BFC51FCBC5FAC5FULL, 
            0x594FB96CD5E646DCULL, 0xD3717A6ED4C0B9C2ULL, 0x6C54D921748BCA5DULL, 0x9EA77068366AE212ULL, 
            0x3C5F0774BF0F7D8EULL, 0xE6EDE0E9CF8F9DD5ULL, 0x538024F742E5DACCULL, 0x6DDD09A205419D03ULL, 
            0x2BC9D82EA36DBD83ULL, 0x903FAAE1F8B56433ULL, 0xD2EF60EEC20F05CEULL, 0x64A8F814443DB759ULL, 
            0xC602D0A8B91C276CULL, 0xEB91728FC7FFEC81ULL, 0xC9E3EF9A51597340ULL, 0x01C395A071B53949ULL, 
            0x53CE1D717CD09308ULL, 0x5704230EE09B5706ULL, 0x3A25B00E6E14058BULL, 0x5FCAAA14AEF98BCEULL
        },
        {
            0x65106248D78DD091ULL, 0x461761F9288F75DFULL, 0xB2BC237F603E70E7ULL, 0x785730CC11F97132ULL, 
            0x6CA6ACC8B4FE4074ULL, 0x2FB020DAA0A538E2ULL, 0x9FBA385FBBF916C2ULL, 0xB93E1376EA199EB9ULL, 
            0xF9A6F9FDFE73FD51ULL, 0x93DEE9C6AB068A95ULL, 0x5155EAC749652D55ULL, 0xF3A07A794243779DULL, 
            0x2B3E093C32D3A2D6ULL, 0xD7861C2BD0BCE97CULL, 0x1ECCEC350876C9C9ULL, 0x1DA2704E3929C353ULL, 
            0x48C83EF872A6238EULL, 0x2FF49BDAF39A2FC7ULL, 0x96A557B6C00E5D75ULL, 0x1C4006DCDD949A12ULL, 
            0x95947B0ABF71DD01ULL, 0xCDAF5488AADF216BULL, 0x4B67C99B122721E5ULL, 0x457B9F3AE0E3603DULL, 
            0x63301D9247DFE366ULL, 0xB8990F2E971A34C4ULL, 0xFB0064621E104121ULL, 0x107F745C5FA4347BULL, 
            0x8109543F7D197FF1ULL, 0xBBFE72EEBCBC03F7ULL, 0x1C86673721158B62ULL, 0x8034CF95294DFA35ULL
        }
    },
    {
        {
            0x47D0F09EBA5EC485ULL, 0xB7D58E742030514FULL, 0xA8448FA5299E869AULL, 0x624DFA8CD6ECBEDAULL, 
            0x8E891B554EE19ECEULL, 0x517096825EF22BFAULL, 0xFC4984787AE1F262ULL, 0x9F29AA2EE96234B9ULL, 
            0xDC4162259A7E66B4ULL, 0xD16BF039474E0F7CULL, 0x7E7A1E001A67B56FULL, 0x0BE0A48C370BDA5AULL, 
            0x0170E7ED4AE0DD0EULL, 0x90C231E78F92DFBFULL, 0xB6823E26A9D36970ULL, 0xA5ABD55C1A4252E0ULL, 
            0x168ADFF3987136A3ULL, 0xC8B7E5A9AD4A3449ULL, 0x7DD0B9E993CC881DULL, 0xA42781B0B12ACD56ULL, 
            0xB0CEFD2DD78A5C78ULL, 0xD4E426CF9235ECECULL, 0x0448E95EFAFCFD50ULL, 0xC2E5BF303763BD8BULL, 
            0x5FCF0939EBCBEA89ULL, 0xBDA5972570DDEF16ULL, 0x35D6AD20551E5D06ULL, 0x61999C20314E04D2ULL, 
            0x665F23A454DF543CULL, 0x19BBC741C9963F2AULL, 0xE7940468FC7C4C7BULL, 0x37A9389862197049ULL
        },
        {
            0x9C279E77AED08F3BULL, 0x66B79123D300CED7ULL, 0x803D1255B9A02E94ULL, 0x7190864BDA5B8AD9ULL, 
            0x070A378E5F243AA1ULL, 0x0450162F4DD1D400ULL, 0xB7F63528893F961EULL, 0x947A11258A02CD9EULL, 
            0x92ACE1D5B19A4C86ULL, 0x5CA88C316D5DA191ULL, 0x2A05E54621D0D1E2ULL, 0x153DF5C23160D4FAULL, 
            0x7B617D333A3088B6ULL, 0x665DBC7ABB3825A9ULL, 0xB86AA7462020E47CULL, 0x20B9FAB68E508681ULL, 
            0xBC3790E2D654396FULL, 0x515AD670FD2063C6ULL, 0x1A9CDF93833F5E90ULL, 0xE5A8CD978102FAF4ULL, 
            0x1FE2943E8F29B326ULL, 0x40D62B6C42F7E866ULL, 0xC5CFBD9433D12402ULL, 0x78C6476E19A86B88ULL, 
            0xE896B367BAEB4CD6ULL, 0x6E52AF544DF88D51ULL, 0x0DBE7C53CDA3BC02ULL, 0x0E357FAB97DAE7D7ULL, 
            0xCA9329493B2C2BDBULL, 0xAC749F7A0D980CFEULL, 0xC167B41B1FDF6217ULL, 0xCEC57859684AEA86ULL
        },
        {
            0x3D54B2409BDFF3B8ULL, 0xAA6221397210902FULL, 0x47F15AF0A7580A19ULL, 0x7B22F2CE990FBF53ULL, 
            0x906A752173D757F8ULL, 0xD4D977B3B3FFDA84ULL, 0x80138EBE8B7D7193ULL, 0x0373B69495556BA7ULL, 
            0xFBF53A81FEB63CA4ULL, 0x25A99DCABCF6669AULL, 0x5936B9C76BEBE0A6ULL, 0xFFAA1B4FC48690EFULL, 
            0x005AC56E92A71EE2ULL, 0xB97FE1B5C7F33EA2ULL, 0x56EFE9A839648D89ULL, 0xA183791D9416D9F8ULL, 
            0xAC88A5FBCA66D5B8ULL, 0x7D02A6C294CAC971ULL, 0x14FCE95AA640815CULL, 0x29EC6F8C23C0F7A9ULL, 
            0x2A68924A1B91F203ULL, 0x1A14A028345855DDULL, 0x1AAFF79EF2285C7FULL, 0x31F14E75A14FEDC5ULL, 
            0x28DAE73478992DDCULL, 0xAB1189D7487F7835ULL, 0x4B23FD67C913437DULL, 0xF7854395600B5564ULL, 
            0x69283EB3D5E21E9EULL, 0xA8EFA38B79B5C85FULL, 0x55D083CDBEA705D1ULL, 0xE92066002829C76AULL
        },
        {
            0x057081606BF84E4CULL, 0xCEB8D50F8B6484F9ULL, 0x892342B09ABB2082ULL, 0x407AB57ABC8E42F0ULL, 
            0x6C47FDC32609B0F4ULL, 0x330B33102FF36B3EULL, 0x411AFD541C677011ULL, 0xE6C279AC114E6FA9ULL, 
            0x5777DC8D3723184BULL, 0x064F8CF4340BB04BULL, 0x5A10D132C83CEA4BULL, 0x25F0A3A29FAF0A96ULL, 
            0xE00D94688DD29BD1ULL, 0xDCB72B3FC8A5D558ULL, 0x54F31E7E60B323B3ULL, 0x25FEC606C3C43F61ULL, 
            0xE7BC7ADFDB3DA798ULL, 0x1E23017F4760B784ULL, 0xE4EB20D24DFD5FCDULL, 0xBD594090BFC73598ULL, 
            0x3F7933EACD814D8AULL, 0xA799A1487C970218ULL, 0xB739F28997930CD9ULL, 0xA036542D34289E3CULL, 
            0xBA0A2325F8C8BBE0ULL, 0x612BC20CEE2ABAF1ULL, 0xB16718A3BAE671F1ULL, 0x24646F6CD31341D1ULL, 
            0x7A1826680555BCFCULL, 0x57EE8AAEE09B9502ULL, 0x98BDA5B5CAABC3ABULL, 0xE1AE029099E761A4ULL
        },
        {
            0x92840EE005AF234CULL, 0x92F8BF89B2F5FFBFULL, 0x2B4F8CCA48F8BD74ULL, 0x1CF2AE7523111D1CULL, 
            0x889E3A2634680F1AULL, 0x60739A436AEA3851ULL, 0x9B429AF57369D2E8ULL, 0x7A5DEC5756A680B9ULL, 
            0x142DF2E42A0B47AAULL, 0x79E43B58CD4DB011ULL, 0x9263D89B7FCDA7D4ULL, 0xB687BD17843CFD4CULL, 
            0x4A312FE99950C3CCULL, 0xBF086A0BE8B08130ULL, 0x6FFD4689DAA3F9CEULL, 0xB5B67FE2381BBB2AULL, 
            0xF6CD6EFF40831930ULL, 0x81626B01462CA65AULL, 0xE59752C4D1584970ULL, 0xEDB84AD584083CD7ULL, 
            0x2A47E84C9F3CC750ULL, 0x290DB7ED2A3A4F1BULL, 0x6118DA33CF52426DULL, 0x7504FD78525A2ECBULL, 
            0x623A13695FBFC475ULL, 0xD7B121043DA3187BULL, 0x6392116C78C0AD27ULL, 0xF6AD6D9E1A8E42B5ULL, 
            0xC2E73BF0A1562FD1ULL, 0x120D3E99244F7E7AULL, 0xF7A8C7D65F04A5EFULL, 0xA7A760D27483704FULL
        },
        {
            0x390DDBFA82DC4D91ULL, 0xAB1F74C7E3658BD2ULL, 0x68559EF988237C3FULL, 0xB8DAF9F62F5D7E20ULL, 
            0xF1D347F48C0094BBULL, 0xB608A178625FCB29ULL, 0x3FC2BD21F83BAC97ULL, 0xC8EC8C7FCDA4C9C0ULL, 
            0xE0870EBFF7542F22ULL, 0x7E4288B15B850A54ULL, 0x17CEAEEB577A7CA9ULL, 0xDE6FFF8E97425148ULL, 
            0xBDF740EC8FEF957CULL, 0x760C3BEAAA0EA4FCULL, 0x9065B3594F0CE619ULL, 0xCE11BF12BD2B97C0ULL, 
            0x5514DA01DE530B73ULL, 0xD6E588187E384FD0ULL, 0xC61C4ED5578463F2ULL, 0x0684AAD8B8AA3B9DULL, 
            0xD90C44ACFD47966EULL, 0xFBB5DDCA3CF85CC9ULL, 0x84AEA627E9A19FC6ULL, 0x555F09AFF99570F8ULL, 
            0x032659E364BA5E29ULL, 0x31ED22CDDDA20038ULL, 0xC78AE6353E1EA261ULL, 0xF1DB4FAFD6C4A3FFULL, 
            0x97098CF2599F5BD3ULL, 0x39373A3617E1D3E4ULL, 0x464D41769A719BC4ULL, 0x22B0B6AFC88D9D76ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeyRotateConstants = {
    0x777B6BA2C68ED4AEULL,
    0x91AEE1202EBE0E2CULL,
    0xBEF705F4B1F88C08ULL,
    0x777B6BA2C68ED4AEULL,
    0x91AEE1202EBE0E2CULL,
    0xBEF705F4B1F88C08ULL,
    0x01B4FB3E923842E7ULL,
    0x0CCC9EB0BAD34BDFULL,
    0x33,
    0xCA,
    0x16,
    0x74,
    0x82,
    0xE1,
    0x9A,
    0xD7
};

const TwistDomainSaltSet TwistExpander_Mimosa::kKeySpawnSalts = {
    {
        {
            0xC1CA1B67737EC14FULL, 0xAC05FADE77BF8AF7ULL, 0xF7973B87BB61C570ULL, 0x88418F318A0209F9ULL, 
            0xA510A044AB1ADD87ULL, 0x644B323B87DD690BULL, 0x490E131E3AB2DD68ULL, 0x77FA4604BD118FAFULL, 
            0x02991C2D655D1154ULL, 0x59BE9DA38A2A3CD8ULL, 0x67E5F74BDA1B3EFFULL, 0xB2B8BEFC8736F576ULL, 
            0xA929ED94C5DF9E9BULL, 0x40912A7FA4EDA2ECULL, 0x1BE7E07A505FB948ULL, 0xF562FA978AB96074ULL, 
            0x1CA1F04401760D80ULL, 0x5FFD4D91785464D4ULL, 0xBB50ED7178B3AAE2ULL, 0x878A9A56A9E83579ULL, 
            0x139054C28A52FC46ULL, 0xFBFCC46520B70CADULL, 0xF6BA262ED44059E0ULL, 0x54F213B19613F0CBULL, 
            0x95641AD6B87D583EULL, 0x977F90AD6D674609ULL, 0x9ABBE2552F17D886ULL, 0x476119AC69A3D782ULL, 
            0xADDF1957B698C6D9ULL, 0x3DC23458A294688BULL, 0x1E346CAEC802486CULL, 0xA1875FE47B3346E5ULL
        },
        {
            0xD18C1139C2E0E61BULL, 0x45EE2058272CA7ECULL, 0xFEAEAE663426B1A5ULL, 0xF02BC91363A586D8ULL, 
            0xA02341A162D6D26CULL, 0xEB907B3496F0EAACULL, 0xE7450D4A4E8D002BULL, 0xF04B5811EF8837DAULL, 
            0x4697DE65191DAAB7ULL, 0x78F1BF7F5147F47FULL, 0x7FA1FF05403CE0BDULL, 0x38DD2851E31F4116ULL, 
            0x595FE74B624B41A6ULL, 0xA97EE2AF2B7644B2ULL, 0x868C758FD7CA64A6ULL, 0xB8FAD53FEE358B63ULL, 
            0x78EA7EDF88B31BF0ULL, 0x4A5918E0F7243008ULL, 0x51C5EEB77EE11FC4ULL, 0xCF3EDFC97DFF34DCULL, 
            0x9D7CC012DCF2D01DULL, 0xBC919B6C02F0DEACULL, 0x89E26477A57F35D6ULL, 0xF306ADA974F220E4ULL, 
            0xFC9B890966C1DECEULL, 0x86119321141FCBB8ULL, 0x65231E0727A22ED9ULL, 0x2AFA437B32FF06EAULL, 
            0xDF887C9FF1329218ULL, 0xD9F3768931A728E1ULL, 0xC94C12EBA81D08EDULL, 0xE98A8A127EE2F613ULL
        },
        {
            0x5FDA97DF2A6EE829ULL, 0x123A61E4375C409CULL, 0xAA563E9312AEBCF2ULL, 0x76C82A41FBEEEBE5ULL, 
            0xF69CD565858990E5ULL, 0x540D843816BE19ECULL, 0x56A8A16E59363DF8ULL, 0x75B698133D6EFE39ULL, 
            0x9DEC9CB31B166351ULL, 0x298287BE65D1F10AULL, 0x9F91ED99C6BCA8FEULL, 0x540BFD62F56DDD89ULL, 
            0x9C80644771F02D6EULL, 0xF4EB0ECCBDAE1926ULL, 0xF945979EA6A08BA7ULL, 0x20C20FBF125CA5A2ULL, 
            0x3A1FCAFCC0EA866EULL, 0xA3FCAD592F0CB6D7ULL, 0x1FCA51947DCB9004ULL, 0x9477B477820961B1ULL, 
            0xBA02E7BC59B6CA60ULL, 0x4C6AFF90B0D4A641ULL, 0xC5AFADA64B459130ULL, 0xD5250855DA5392E3ULL, 
            0x460E9572B30F46D7ULL, 0xFC3AE8DC1B513953ULL, 0x3B6613C9D7194C70ULL, 0x590342F0E92C7BF0ULL, 
            0x050713ABA89FA3A5ULL, 0x1B21ED6D9CE7B2FCULL, 0xFDB5824977C58DCBULL, 0x9AFB6AA78A38068BULL
        },
        {
            0x842FA049B7820476ULL, 0xD966BECF7B0F9001ULL, 0x79A27AB0FFD6612BULL, 0x3687A55A91FA0985ULL, 
            0xA14FCA3FA2AC88B3ULL, 0x567E474C48F2E541ULL, 0x10DA8D78B98BEF78ULL, 0xEA9D69ED622585D3ULL, 
            0x72E636616276BEC2ULL, 0x2378720A1C298072ULL, 0x33C13810593D8B0AULL, 0x032DC23228F37EFEULL, 
            0xA8CE995090DFBD78ULL, 0x6F43FF884C22856AULL, 0x5631FB0E94EAB6C8ULL, 0xE45576DA097C01B1ULL, 
            0x95158AB1FB6B848EULL, 0xE978ED62415517CBULL, 0xD100ACDC906B49F4ULL, 0x70D65B8F3FF895DDULL, 
            0xE68110F6B3818612ULL, 0xEF258889C0AEA0D6ULL, 0x0510331CDDDA709DULL, 0x8887C9D00395C855ULL, 
            0x5A4FA916A35C8645ULL, 0xA767AB220D1B3D2DULL, 0xCDC9AAE38A6952A6ULL, 0x0548A7B9EA364ACDULL, 
            0xC6DE75904308E3F7ULL, 0xDAE1F205EA2CDA43ULL, 0x9F98EA77B49BF116ULL, 0x4AA96DD06279F95BULL
        },
        {
            0x05B0C0E10AD22197ULL, 0xBF945D6CDF589A65ULL, 0xCC184EF36F7B4FADULL, 0xE379FA0AEA38DB90ULL, 
            0x83FD0614F8BB62B6ULL, 0x63F349E7AD2B493BULL, 0xAC044372731EF3E0ULL, 0x45A7BB8E5E958883ULL, 
            0xDBCC41029ABA8E7CULL, 0xAB5171E25C25D5DDULL, 0x875D4E82D534F23DULL, 0xF3B88419AF76A39CULL, 
            0x52D24431176B9B67ULL, 0xA9CC9C24D4C4296FULL, 0x80FEC16326146144ULL, 0x20781E419B7EE75EULL, 
            0xC224C0FDA597D07DULL, 0x3595B3AAB18185E4ULL, 0x9AF327CC7037215BULL, 0x7EDB5C795896996FULL, 
            0x0D82F3BEAE6856C1ULL, 0xEE46EE13BB2F4EA7ULL, 0x31129B6BFF048066ULL, 0x94A43E9E3AC1E76AULL, 
            0xF66929E1837BADF1ULL, 0x9047BE57C51EA894ULL, 0x1513E41CC48FB600ULL, 0x4C103399A46713C8ULL, 
            0xCE04A7383A14A1B6ULL, 0x9A8FA8F9A1BC939AULL, 0x6D9152CA00D31BCEULL, 0x60BFBB9D3D737446ULL
        },
        {
            0x3622BC528368D009ULL, 0xD91F36E2F7526F57ULL, 0x11C2F236967B0C15ULL, 0x238D68B6FD0B94E7ULL, 
            0x4C59133F9EE4CA4BULL, 0xC73C01CD15F1941EULL, 0x855DE9D03BAA54E3ULL, 0x1D1D683997E21795ULL, 
            0x7F523AA5CA1D8BA2ULL, 0xE71CA18631D17679ULL, 0xBEE155E50981B8D3ULL, 0xA5669DFD12798BE9ULL, 
            0xC93D1D5AB04484C6ULL, 0xC93E57C09DFAE23DULL, 0xFEE149EB6D00FE60ULL, 0x1D175938AE6004CFULL, 
            0xB15EAE190FD0A944ULL, 0x6DA46B8DC7A64E92ULL, 0x4D0F43C77A5F57F7ULL, 0x27547B4A0E1FC206ULL, 
            0x79B3F937874A06CBULL, 0xF3E38788E0A9E0FDULL, 0xC92058F174F6C193ULL, 0x7EC07723EB8EE13EULL, 
            0x946E19195DBB84DEULL, 0x676594649C972381ULL, 0x7EFE1A64AD18972AULL, 0xC010661CF7ACAA5BULL, 
            0x01101571F4BE2EAAULL, 0x6BF2BBED5215A847ULL, 0xAB4D3703FBF13BF5ULL, 0x308A385C693B1839ULL
        }
    },
    {
        {
            0x42251BA23BE3D9D0ULL, 0x72F9D859505A1DD9ULL, 0xB9F03BAC75464915ULL, 0x7559421FEC2E43D5ULL, 
            0xAAB54D97B8DC2D59ULL, 0x02F626EFF5E9344BULL, 0x771F3966F4085BE3ULL, 0x008D196E7F20AC10ULL, 
            0xA008E0CB5DAD81F3ULL, 0x3232C6C6453A1F2EULL, 0x2A49421965951BEBULL, 0xD96CBFD0AC28CF7CULL, 
            0x77A0D701308D90ABULL, 0x56F0DEB1E159F219ULL, 0x76CEB4A53D4834C8ULL, 0xD4D607B35F83338DULL, 
            0x53A5EB15ACEBAADDULL, 0x58237472EAB0FE55ULL, 0x480AE4FF47937A3BULL, 0x90F81F6FA8F0A435ULL, 
            0x35A6F7430E0BDB0EULL, 0xDB8DE1B7F3526335ULL, 0x7906C52A43168E03ULL, 0x5B8C761831AB30CEULL, 
            0x8E478AE8632D1BA4ULL, 0x232CB4979FD02B3DULL, 0x24674AECF305C74FULL, 0xA9BD4196EC11ACC7ULL, 
            0xAEE66E25B82B6C8CULL, 0xBF873C2A2F38C22DULL, 0xF2FFCD7B21951D44ULL, 0xAAA1E2220DDC149BULL
        },
        {
            0xD816831485955EBDULL, 0x2D5CE8E994A74B20ULL, 0x4F34DCEE8E437AF9ULL, 0xE223EF1D4CD4C0A7ULL, 
            0xC786EF9084288B15ULL, 0xF4DC01DACFB25648ULL, 0x2A1EFA9FD6889AA9ULL, 0xD8193826D80773C0ULL, 
            0xFDD006DE5DD3340BULL, 0x1A0D86AA11200503ULL, 0x72CD3D10793B6B91ULL, 0xEAF75B8637389B5FULL, 
            0x7E61298E6202BCE1ULL, 0x889104B087AF9903ULL, 0xC14A6224B676E391ULL, 0x004FCE7A3F7093BAULL, 
            0xDA04B8AE4E006A5EULL, 0xEC7D5527B76A9D08ULL, 0xAC931FFC2696B321ULL, 0x2976F728A8CF24E7ULL, 
            0xC9B3692E4BF28B0FULL, 0x8964C0137BFDF5B1ULL, 0x7190B59D23E14577ULL, 0xBA9988D2F8C735D1ULL, 
            0x05D0419065239779ULL, 0xA2D1A9D381CD68FFULL, 0xCF0EC0E3A0CD6ADBULL, 0x573CCC177DF02A91ULL, 
            0x4F5A16569D7D74B7ULL, 0x39DDBB47357914D7ULL, 0x7EB45052B36AAD8AULL, 0x02C5C41EF4275908ULL
        },
        {
            0xB6BC884DF0676D1CULL, 0x58A01A1130D22D17ULL, 0x861D25CE36F46C23ULL, 0x89A01AC736EB3400ULL, 
            0x403898448B4129E7ULL, 0x7A17C1A328182C79ULL, 0x46BB05DA8570B2FAULL, 0x90785910CD2D463FULL, 
            0xBA41F7BA206956ADULL, 0xF8638F77E544D2ABULL, 0x0DFD0BE8ECE5CB4AULL, 0xCBD6384C84CF679AULL, 
            0x1DD4DC78CBC854A4ULL, 0x3B7866157147A42BULL, 0x3DB8545F08235F2EULL, 0x6F17000E6627F850ULL, 
            0x79C7C55D93B47D04ULL, 0xA0DD004B541DF80AULL, 0x988759A3E3F1DE94ULL, 0x2BC00374FE3D1D71ULL, 
            0x2C7716B52B527329ULL, 0xB49F0DB2B8668278ULL, 0x1F02AB6C06BB61F9ULL, 0xF3ADAAAEA8B67140ULL, 
            0x86758EF525EC00F4ULL, 0x540188F0679D996FULL, 0x84393D838BB926B1ULL, 0x5919B7BA0261057CULL, 
            0xC76ED9D552A7D50DULL, 0x36B75F223DED7881ULL, 0x3B133DBC291B09DCULL, 0xB4A2DCDEFEBD0A68ULL
        },
        {
            0xB0B602962D671C8BULL, 0xC643387951FF3058ULL, 0x2EA99E1228D730E1ULL, 0x11AC2DAC92FAE57CULL, 
            0x6E296D8CE37258B5ULL, 0xEB286C05AB6BF7EAULL, 0x2641CB890E8710FCULL, 0x98F72CD3D68C08D8ULL, 
            0x15B2081FC6F458F9ULL, 0x79FB913D43764FFAULL, 0x68F42A24071D9C02ULL, 0x63D7521C4E40DD85ULL, 
            0x1473BC2B4012D8FAULL, 0x0E8C64539B2F48F5ULL, 0x71028A3D4AB1969BULL, 0x9771BD4E072F8B11ULL, 
            0x07E2143E20848ECFULL, 0xD3465A6403323090ULL, 0xC90F91948042B863ULL, 0x3931487CA63C1A05ULL, 
            0xDE19C98EDDE3D474ULL, 0x57501BB0A2A0D41DULL, 0xF3C0179D6D1AD555ULL, 0xE464F659C07F7659ULL, 
            0xD6897E5AB7AFE7CDULL, 0xFA348649C756FC15ULL, 0x5B9ED0684819E25FULL, 0x8744A96EE76FEAD3ULL, 
            0x9ABD2B54CDCDFB07ULL, 0xA72FACF4A15D3759ULL, 0xF84DD753192AC90CULL, 0x659846B52F28ADA4ULL
        },
        {
            0xD599EADC9187330BULL, 0xEC45C3F4F0CA7AD8ULL, 0x43A855145738FF17ULL, 0xA076BA5844235E32ULL, 
            0x4FD771012A644065ULL, 0x9ED0A907F92813A0ULL, 0x10C8A40EF074C884ULL, 0x9548FA7A6C8C5379ULL, 
            0x0BDD8671777B9BDAULL, 0x3D7745597CCBA734ULL, 0xA5C29FFE5642B0F1ULL, 0xC12278A28D341B84ULL, 
            0xA23FA7E60695069CULL, 0xEA579F86E7D704CFULL, 0xA60D86AF27699055ULL, 0xD5A68C977CE75FB3ULL, 
            0xAA150FF3FDDD5E4BULL, 0xF56AFD5D6B5D8CB4ULL, 0x7AAD02FC03FE340FULL, 0x57BEF27506FA4B97ULL, 
            0xF70F2B8C6ED2D4F3ULL, 0x722FA27BF359D1CFULL, 0x6154D58784FF88A1ULL, 0x2515377FEC707095ULL, 
            0xEC9A7065674CC0D1ULL, 0x4E3199A375334B8FULL, 0xBCA7A390397E1C25ULL, 0x99B1A23C82D83D87ULL, 
            0xF8F2F1F0F87EED40ULL, 0x08D0198E663BFCA4ULL, 0xE12D7199FC67B91DULL, 0x9172E6901BA2706DULL
        },
        {
            0xB7E9083FB63B48C1ULL, 0x62799DF1DB2A487DULL, 0x9352C4CB02853555ULL, 0xA7B21EC10FC3951AULL, 
            0x44AD10F26DE9A434ULL, 0xC8DEC4A1548BFA6AULL, 0x73C7CE5A67DE1C51ULL, 0x4214B80CE95AB1B1ULL, 
            0x7A1F0672B2A303BFULL, 0x08334ADAEC124703ULL, 0xF65EE070C704C5EAULL, 0xCC5D9C190E08DC21ULL, 
            0xE310AB7E718B2D50ULL, 0x6382B9E93526F38BULL, 0xE2A2FCD91DC0357AULL, 0xA60019EEAF7B5C44ULL, 
            0xAE117BF248209B31ULL, 0x940D92C00BA95C4AULL, 0xC95786235220DC31ULL, 0x9B90D1D1DCFF323AULL, 
            0xDE222B5F76756D18ULL, 0x8F4A3E435AA7A682ULL, 0xC3FF10E725AA4E45ULL, 0xC7F0AABAA67E8D2AULL, 
            0x6D1BC28E02577A3CULL, 0xDC82F502BC139BA6ULL, 0xA5966E98A9E8BD1FULL, 0x346A4BE9765A504FULL, 
            0x90EF47FFF6917E36ULL, 0xD14D5CD36AFF2095ULL, 0xAB3935891CAE12EAULL, 0xBBA4D26CC5F68D0CULL
        }
    },
    {
        {
            0x56C46C55A0F2A6DFULL, 0x5CD9A7E44CF4B3BBULL, 0x63DAF081905AE540ULL, 0x16DC52477EEDCF9FULL, 
            0x55EF8FB9A01C039AULL, 0x4C6D1347F3D09C3DULL, 0x66304EB783E3A536ULL, 0x12DAC456E00BADFDULL, 
            0xA4F0D7A20EA19962ULL, 0x4072ADD0FDC32709ULL, 0x59C328BED19FDCAAULL, 0x34B186AD2D922A8AULL, 
            0xD3D9917EE7F63DDCULL, 0x0A0E49F51831C856ULL, 0x05BD94E09F11E2F9ULL, 0xC885D6681FF55BBAULL, 
            0xB018A3CB840CB6FDULL, 0xFF29F3D2B74114DDULL, 0x573CB0BC6177B1C5ULL, 0x74354FAD0D3C640BULL, 
            0x22025B74210E57EEULL, 0xC5F752D410B65678ULL, 0x04FB8B2099E6AB43ULL, 0x3F34632F78AD8483ULL, 
            0x69CB49441030BA6FULL, 0x1C1B2A2119A314C8ULL, 0xCE9BB012C460EA11ULL, 0xA9F48A998C148F51ULL, 
            0xD7F9C15C60ED6E5FULL, 0x2DE6629661136F17ULL, 0xFE6E0B32C939BEF0ULL, 0xB53CCBB1C9CB9B04ULL
        },
        {
            0xDE73863DA64949CBULL, 0x2F494833AA6AE1D1ULL, 0xCB924F3FD638BFCCULL, 0xC00BB3CBF4FC9943ULL, 
            0x9999A4EF2635C438ULL, 0x7CABF4038C4B97E4ULL, 0xD5B95D75A2D2A8C8ULL, 0x767C2882270FF6D1ULL, 
            0x92D84BFC741C34B1ULL, 0x30DCE1956C0C73DEULL, 0xFE5B5748163C1453ULL, 0x878A65514847D150ULL, 
            0xF0CA79A2CB0130D3ULL, 0x816D7A1B8C409B3BULL, 0xBA9DF793333BEEFDULL, 0xA7F2ED1209897146ULL, 
            0xA986288D264A385DULL, 0x29961BC5C0550F79ULL, 0x65B5C1C9C1273F8AULL, 0xD97B7D43F0B30737ULL, 
            0xBF65A5C7115BF1A0ULL, 0x1812D6B6233F2F48ULL, 0x61E22CF3C2311B4AULL, 0xE15BA6723E953F9DULL, 
            0xBA730117282EE412ULL, 0xBDD7E26FE6B83E03ULL, 0xE28B72C448196017ULL, 0x1294B6BC8B2B5F95ULL, 
            0x4131607E2C1818FEULL, 0x3483EFBCFB01225AULL, 0x300779D55E92D549ULL, 0x87563F1797AA6A0AULL
        },
        {
            0x20B70A52A321A691ULL, 0x4E2E923D00FABC3FULL, 0xCF30EED2AF9B29ECULL, 0x14872A6E32D8FEF6ULL, 
            0x3791F9B3F784EF1DULL, 0x48C39FFE51BD347EULL, 0x4F9FB8A4F234F096ULL, 0x344C2A58E6546BF5ULL, 
            0x77894CCDD4C265E1ULL, 0xE210AC15C5F2C3E8ULL, 0xF85693CEC30A2214ULL, 0xD5B40A94E9DB6054ULL, 
            0xE9F98C4DFCADEF3FULL, 0x28E41721688C5B97ULL, 0x954A87972A1A4FFEULL, 0x9B2134E3C6292513ULL, 
            0xEFA0E25DEB5BCC6CULL, 0x6DE2EE4CCA1866DAULL, 0x4F0D289EB6F89727ULL, 0xF7FCCB7A5C866D65ULL, 
            0xDF4FF699488F8F94ULL, 0x3B9CE1CBEFB0B404ULL, 0x8E8B84C019FD094AULL, 0xE98AED9897AC1BB9ULL, 
            0xACA6EE596D81B09BULL, 0xD173341C3235E132ULL, 0xF7AFE89553B76D53ULL, 0x8B762B0B5EE1913DULL, 
            0x09584B52BC40E5FAULL, 0xD3766CFB6B449FD6ULL, 0x9A73D28ACAFBA2FAULL, 0x34E1440F614ACD99ULL
        },
        {
            0x3B13820CC41A6348ULL, 0x7A8AA9DE6FA0C788ULL, 0x1380CD912245F4E8ULL, 0x63C54F5535ED3BDBULL, 
            0xAE1E6D63C2ED32FDULL, 0xD7322BDCC279F78EULL, 0xD986C1D2A0A1F020ULL, 0x77441F86AA39A1A6ULL, 
            0x98EE97CD47D38E8AULL, 0xDC59B236D89DF044ULL, 0x5FED233448F71952ULL, 0x19754494A965CD27ULL, 
            0xDA5BBA53E676F9BBULL, 0x064956BC5CEC9291ULL, 0x5B6A2E553F43315CULL, 0x9836D7639C103A3BULL, 
            0x20F2487219B51361ULL, 0xBE92AB6BABF2C828ULL, 0xFFA857846A092487ULL, 0x306DF4583C993462ULL, 
            0x661AA81A88B2D317ULL, 0x175A9B369DD722BAULL, 0x33DD23CC12F0F59BULL, 0x82652EDB90FF20DAULL, 
            0xF0EA381897971B9DULL, 0x8FF41CBA1F6B7EA7ULL, 0xC6A3C139F0469E67ULL, 0xB4EFCD056DD3A21FULL, 
            0x104F98F423B8AF90ULL, 0x84C12BF8D8959579ULL, 0xD9EBB1884A6BF8DBULL, 0x4044D54A85225417ULL
        },
        {
            0xFF5810017B04D3B9ULL, 0x58110F699192260CULL, 0x6DED9D8F3BF946CDULL, 0x04FF22A0A6BAF2DEULL, 
            0xFE88B29DF98CAD5FULL, 0x27361BBE3380CD67ULL, 0x1A281B1389C5F3D2ULL, 0x197C5F01C2EA3AE2ULL, 
            0x6B4F9C58E14A9E8CULL, 0xF01248121F408D03ULL, 0x785F2DA476043169ULL, 0x2C42FE4B2A5089ECULL, 
            0x6113FEE18ABD01F0ULL, 0x03390558EA60503FULL, 0xD6F8080C8F407389ULL, 0x960FC6553F7B3E22ULL, 
            0xB8B80AEA39555D84ULL, 0xFFA053164C3AA26BULL, 0xD1FE481B85EE554CULL, 0xA50C6D2F1E18F384ULL, 
            0xFD523BF243A1E143ULL, 0x19BFB73ACD03DC7CULL, 0x158AD2AAB2728FE8ULL, 0xD5AD69E98F62DBF5ULL, 
            0xDD3A2214B2C6E3A0ULL, 0x52E3204F6D8B0723ULL, 0x9C42E0A46EE5FABDULL, 0x2D0D7EE4DEF8240CULL, 
            0x4344B769AA1398CAULL, 0x8496A80DDD24D694ULL, 0x496960A6CA402D9CULL, 0xE1DB00095CAEF47DULL
        },
        {
            0x1B50429635BC1F90ULL, 0xAC23CA05F5AC0B69ULL, 0x9E26FE861E6CD9D1ULL, 0x870285ED1C155D14ULL, 
            0x227C165CE4B526D0ULL, 0x1E343270C3313F43ULL, 0xDE21121E01F8A9F7ULL, 0x6FC0A5CCD5571695ULL, 
            0x0E6D83088FEEC1A3ULL, 0xCA5E635235828486ULL, 0xDBCEB9B507A6DFB1ULL, 0xF53977257BEB9C51ULL, 
            0x1A84D62B29730B86ULL, 0xC9F249E8A6511EADULL, 0x734CCA6171C04150ULL, 0xBACBA102B93C0585ULL, 
            0x7774B2A60039A169ULL, 0x28B5AC4A96E5D497ULL, 0xBC63B116B90E68D5ULL, 0x0D47DCB714B2A65CULL, 
            0xF5A04C462F234423ULL, 0x8DC0B3F00D5040E1ULL, 0x5EFB9C70516C7C2DULL, 0x2652A356FA56B056ULL, 
            0x6407A89F7567C473ULL, 0xB44F79279D9A5A81ULL, 0x800144BF96DE1A1EULL, 0xA5F2C1DC3278F809ULL, 
            0xD4A4000AEB5ECA32ULL, 0x35C96A828CBECEDCULL, 0x1B38B6598AAE2CCDULL, 0x766FF6232F75F51CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeySpawnConstants = {
    0xC7E8F48A116A7C00ULL,
    0x7CE3DCEB9F4DEB0DULL,
    0x3E6B1687AC25DF5FULL,
    0xC7E8F48A116A7C00ULL,
    0x7CE3DCEB9F4DEB0DULL,
    0x3E6B1687AC25DF5FULL,
    0xFB361AE9822E54ECULL,
    0xD08376D18718E4F4ULL,
    0xDE,
    0x31,
    0x53,
    0x11,
    0x52,
    0x8C,
    0xE4,
    0xAC
};

const TwistDomainSaltSet TwistExpander_Mimosa::kSeedSalts = {
    {
        {
            0x8D061C16F765CB5DULL, 0xEDB70A17F8B0316AULL, 0xF4C745015A937D54ULL, 0x903F90A2B2056F22ULL, 
            0x5CC2997F4683CA49ULL, 0x1355C9F443B335B4ULL, 0xD0FB1AB39766D01EULL, 0xAEE42F696AEB5B8BULL, 
            0xDA3636B252C51B95ULL, 0x197A8FD6C82B27C3ULL, 0x70E9EBE7E4B9E6F7ULL, 0xD8B3CEE5898A5A0EULL, 
            0xD960BE20C94CC4A4ULL, 0xD216065B0EE2C71FULL, 0x07077946BEFEF326ULL, 0x7C4D9F6DC28A440BULL, 
            0x622EC83CD04276BBULL, 0xFA45DBD7E62268F3ULL, 0x7832D5F577C37E26ULL, 0x9B8617D707DBAC98ULL, 
            0xA2C9ABBCCED16B9FULL, 0x40865F3FB3BE6A86ULL, 0x1965345D31107019ULL, 0x417F370C3BA5279DULL, 
            0x12A47F1CC02090D6ULL, 0x7B07FE6E8CC68FB3ULL, 0x6D816C4536EFA193ULL, 0x1E5C914B7C1687A8ULL, 
            0x78F28D3500EF0351ULL, 0xDFDC8E23326C8669ULL, 0x552CA963F8A4418FULL, 0x5A412BF2E042DAA4ULL
        },
        {
            0xAB0AEEAFC8EC01C1ULL, 0x2494643A2E8CA4DFULL, 0x70D7AD1D56B0AAE4ULL, 0x6DFFDFE1C1F92402ULL, 
            0x3917298680C7FA01ULL, 0x4AE572DBBA8C3251ULL, 0x7A3CB85B2A547ADDULL, 0xEE355220FD323114ULL, 
            0x3BC6D341ABA8CB8FULL, 0x6089E2C2759F20C7ULL, 0xDF0BE2927B096E73ULL, 0xD63C29B2D8ABF9F5ULL, 
            0x63C912A805C4CA6BULL, 0xD18EC71505C2F9DEULL, 0x3425E60FE1DF3E28ULL, 0xF5A2A4C75C4D6682ULL, 
            0x2F5FCDD437FA6C8AULL, 0xFD0D47BD705E8D02ULL, 0x48A58C5A14EED549ULL, 0x6B36479A1578439BULL, 
            0x299FFC50001DC2F5ULL, 0x8403AC89ADB6B052ULL, 0x08906F1E180E7B11ULL, 0x989905E05956AA49ULL, 
            0x39CA02516C8D62B2ULL, 0xA9473B531BD84FF2ULL, 0x0E7ED524B03CBF1CULL, 0x475EADE2685F6990ULL, 
            0x1C451C3EE66AFDF2ULL, 0xEEFF296FDDF78486ULL, 0x937129724DED6F8CULL, 0xD259FCA2FAD40E18ULL
        },
        {
            0xAC17615D440ABF5BULL, 0x8FEDF3657CC1EF3BULL, 0x71EBED45BC988E5CULL, 0xF7C1342F26ED19E9ULL, 
            0xD151B93878A16E68ULL, 0x72D2D6549B7C3F52ULL, 0x85092E9DCCE1BBE8ULL, 0xF0C4ED1511EC8498ULL, 
            0x7C40E2993B8E5920ULL, 0x6D94785DCE077A58ULL, 0x65AF2CAD73236164ULL, 0x5A36B4BF1F46DF81ULL, 
            0x4EC4E274E335D037ULL, 0x568A7510AF3D1E9AULL, 0x08C03D10A36D19C1ULL, 0xBDD3E6C9CD921D00ULL, 
            0x1CE8C3F8E8677229ULL, 0xAA8648BDD0339619ULL, 0x81113974CF1B907EULL, 0x1F471988642B7314ULL, 
            0x7BE606BE93E68946ULL, 0xD3A5D833B87FFF41ULL, 0xDD80481D51E333D0ULL, 0x47A8C79A79848B50ULL, 
            0x4E03C27F67BEECE6ULL, 0x907321AFDF2A9F69ULL, 0x1E34CA3E2C8F352AULL, 0x0E8BB638D3035146ULL, 
            0x09137CBAB3809FBFULL, 0xB2FD8FC25FA43F4BULL, 0xB08BB95E0AC2B375ULL, 0x60DEF399719F4419ULL
        },
        {
            0x8D49669FC06E763CULL, 0x37B7B591E16D9472ULL, 0xA2CE38DA26A5A214ULL, 0xDBE1C6F1A20FA5E4ULL, 
            0x9CA291A4875B150EULL, 0x5C6AB3FD216FDF8CULL, 0x919D19EA46F11D0FULL, 0xF0C398BA438EC81CULL, 
            0xAE9975ECA7ADC733ULL, 0xE9FF1C5EAE89AB2BULL, 0x29A414C5163F67B5ULL, 0x851413EEC067B33EULL, 
            0xE4FD1DB63FD7CEFBULL, 0xC6917F8A4DC8B862ULL, 0x7188F81368628794ULL, 0x4E24F843EEE2E2ECULL, 
            0xB064AD3109EA487FULL, 0x829B5BEE8BE4ACDAULL, 0x0DD6D89EA95C715AULL, 0x474F2152F82E882DULL, 
            0x10B87D6932AB4822ULL, 0x464C198DD6510330ULL, 0xB1FD632AE8869A04ULL, 0x554106BEA8812F2CULL, 
            0x929650A7277F4970ULL, 0x24CB2040D27C02FCULL, 0x689C0BF97C1E0023ULL, 0x93BA32E023B2654BULL, 
            0x84A5D6598A0FEA39ULL, 0x60DCB1CEB335E3DAULL, 0x2CB15BBE772F92E9ULL, 0xA7C83E9760059158ULL
        },
        {
            0x015D6158EFDB93A4ULL, 0xCD11FFC3B4A3C802ULL, 0xC013D19070AB36A2ULL, 0xCB778A150FEBD607ULL, 
            0x0A65E4CAEB1FFE7BULL, 0xB300025FB951DA73ULL, 0xC9C1BDE94BF5247DULL, 0x8CF50BC51819FB11ULL, 
            0xA75314361FEA8945ULL, 0xF639C53468BCDC9EULL, 0x7C6B529EB06A1AE0ULL, 0x587C17CDEFC4AFA8ULL, 
            0xA16DEA85C8115A6BULL, 0xA43842B6F48A19D6ULL, 0x8511B95F37753A84ULL, 0xDCC35D166D034592ULL, 
            0x30E39913D5DAFF5CULL, 0x7FE647E05CDD050DULL, 0xC99070C27E9DC22AULL, 0x448547E6BEEE9F3DULL, 
            0xD99283B74A55AF7DULL, 0xB450E789DDF82213ULL, 0x06D3F54ECB4A9C80ULL, 0x465FB4DD40A9E7DDULL, 
            0xA311AAB171D105A8ULL, 0xFBA4F90B7BA30D63ULL, 0x205C09CF212ABF21ULL, 0x4E67B34A544E9DABULL, 
            0xADBDCE9CBCA861CCULL, 0x0686E8275D724B93ULL, 0xB2F19F29829C1935ULL, 0x28CA6218BB77FC4AULL
        },
        {
            0x3084FCCE09BE8FDAULL, 0x162510C748CC5FD2ULL, 0x83FEAA80B9C2FF31ULL, 0xF26A1D72C5BD5987ULL, 
            0x7EF1E9EEDB2C8245ULL, 0x136D1C014DF964E8ULL, 0xAAD91C25DC8B90FBULL, 0x09CD571F9E5D2F32ULL, 
            0x76DE5EB7ADD991D4ULL, 0x167E6DBE056238CDULL, 0x6D2D121F23BA6C8BULL, 0xEE3B8A7E629A1963ULL, 
            0xDBAAA8937CB799C0ULL, 0xE0E247F881E9D1FAULL, 0x8AB1E1B76AD29525ULL, 0xD9369361703607C3ULL, 
            0x1940ECB9D4D5AFB0ULL, 0x069F1BE9124551E5ULL, 0xB987FD4F8FD42E2BULL, 0xD2AF127A41939516ULL, 
            0xE57A2B540A5F8C72ULL, 0xD9CFB64F4DF869B2ULL, 0x6903A342D873EFEAULL, 0xB00748EE9D64A7A3ULL, 
            0x4B0BB8334EDCA3DCULL, 0xF2F9BACDD6261395ULL, 0xCD176F4EFFDDB142ULL, 0xF7002FDF20EEFEA4ULL, 
            0x764A50BBF6778F69ULL, 0x8938F00BFB2709F0ULL, 0xF7B7B6915C2B061DULL, 0x90DF058F2E1E8260ULL
        }
    },
    {
        {
            0x0DA8F92E65254706ULL, 0xDC943F38119F8136ULL, 0xCCEBA99697F72AFAULL, 0xA38FC2E206334E3FULL, 
            0xAF9711A584398948ULL, 0x0BDCF40EA7C7056CULL, 0xF433920C1F73A36CULL, 0xAEB608BA3CC4ED81ULL, 
            0x400E4E60AC66CB16ULL, 0x01134E3E6264C253ULL, 0x213162F4A0160900ULL, 0x04BE4504C51F6A0FULL, 
            0xB349D4C3A39E15AAULL, 0xA8115778689A6F5BULL, 0xCCD0E6B963346445ULL, 0x85621F7D7F3F1A9FULL, 
            0x6B69E0CB199D30C0ULL, 0x9D68811D7AD9DF44ULL, 0x730DA22E88CA8583ULL, 0xAC5B6DEC3E4CA0ABULL, 
            0x0A215507FD9B387DULL, 0xB6233A05695D9171ULL, 0xAA522D15E93C31E4ULL, 0xBB2BA726698E7846ULL, 
            0xDEFB39D13F8886BBULL, 0xC2EC52112980A09DULL, 0x7A9E562675EE93D9ULL, 0x2D8881741E17EFB9ULL, 
            0xD8B09664B70930BDULL, 0xDAEC76D381904CEBULL, 0xE8129E91A8935689ULL, 0x1116CB453C3765E7ULL
        },
        {
            0xB787F1A8533332DDULL, 0x3B14037FBCA69368ULL, 0x6545F1C4755D8574ULL, 0x53AE395466AD3462ULL, 
            0x014AC60B9BEEA9E0ULL, 0x2CB6F9C9C8674C29ULL, 0xA50D5DAE59EDCBE1ULL, 0xB0504556F34516E9ULL, 
            0xDFB537C3209E18DBULL, 0xACDCF2D7F89CCBF1ULL, 0xC5CC780EB41FC22EULL, 0xF9801D1CA5BE2A92ULL, 
            0x4F5270748BF880B2ULL, 0xA7FF749DD2AC0E87ULL, 0xA123BFFC93406FFCULL, 0xC7B3CFF8C8ECE2F5ULL, 
            0x02D6AF01796174ACULL, 0x47765B8B5502C814ULL, 0x43E3BBFBDB225E73ULL, 0x84D98C2F7847D886ULL, 
            0xF7D1C5C003456374ULL, 0xF9F829751F95C3D7ULL, 0x4F0147D80CF6D11DULL, 0xE77228134EDE268BULL, 
            0x32FC49598EE82D43ULL, 0xCC3DAD019C6A53D8ULL, 0x4493DBC3804F5E9CULL, 0xDE25289D4BDD3B38ULL, 
            0x4DF07749C9749559ULL, 0x5528C09358E57857ULL, 0x19C891139DD4F4A5ULL, 0xEC8EFE5120EB83DDULL
        },
        {
            0xC34C2B24D9166806ULL, 0x39F9518DEC34AE29ULL, 0x28CAE44F8149CEE1ULL, 0x38E7EE0964BE5E43ULL, 
            0x880B09139C27C928ULL, 0x5229B2C47205B30BULL, 0x71C2926B141DA1DBULL, 0xB59443D3962D5F2DULL, 
            0x8D5C9E23F7B1E56EULL, 0x57D8BB534C76BF0CULL, 0x0D32879C9EC56C67ULL, 0x42AD5EF8DF7A89B0ULL, 
            0x7C5C42B2BADB8AEEULL, 0x20AE148A445E510EULL, 0x3A7939804863D5FEULL, 0x36360730B4EB6615ULL, 
            0x9937F54BC1860017ULL, 0x00E8F2AE559B8813ULL, 0x95E1898CEC2EC01EULL, 0x1E9B494268491245ULL, 
            0x71F9522C642C9578ULL, 0x21F2172FEB09490DULL, 0x0CD0996A68C5FCDEULL, 0x6BBE79FFC809EACEULL, 
            0xF6B43C782EF68B32ULL, 0x593F34AE084BC2D6ULL, 0x7F310EF830F57B48ULL, 0xDAC35EAD0DE22E08ULL, 
            0x26CCC222F59073B5ULL, 0x7B4D84DDE331F398ULL, 0x99BF54A459D12C2FULL, 0x79B340159E4A5302ULL
        },
        {
            0x82FEBF9F848183D1ULL, 0x0A371002687F1784ULL, 0xF573F34F439452C9ULL, 0x3D56904429941E2CULL, 
            0xC60E815CCADA40A3ULL, 0x78721E2B72C2E388ULL, 0xE96ED0FEE60E74D4ULL, 0x63785AC45C5ADA9DULL, 
            0x60D80A97058F3187ULL, 0x24B19FFA5108D2EAULL, 0xEAD46CFB71891582ULL, 0x7860DFFE0FBF4761ULL, 
            0xAD36FDC352E23DA9ULL, 0x22F0EE7F216EBD36ULL, 0x6A59741AD3C217C5ULL, 0x7D01BB54FBD5A428ULL, 
            0x676C6AD03404557DULL, 0xE3B3334E357A4FD0ULL, 0x88F75BE15647853EULL, 0x44D9EEB06C204D39ULL, 
            0x0EB46A55C768D258ULL, 0xB3DCB1313EFFEB1AULL, 0x6C6B54601B2882F5ULL, 0xAFC35BCDA4E63906ULL, 
            0xE8EC402AF6227E6DULL, 0x7A5FCB782694E241ULL, 0x6CD5CB441E77D5E0ULL, 0x962DDB7E94E6A1C5ULL, 
            0xDCB8ECD11A61E0D1ULL, 0xC91040B07FFC636BULL, 0xFA1B7B091F7D51BAULL, 0x25E7C193659A72B5ULL
        },
        {
            0x30E7ECADD35245B0ULL, 0x12DF2B43857921EEULL, 0xA2524185BBE4C610ULL, 0x41360875A706D3CBULL, 
            0xCD76A0652E9A09E3ULL, 0x33FAA18CFF670AB2ULL, 0xC2A59A898DF7EE79ULL, 0x769FB68DA73821D9ULL, 
            0xA610485E853F470BULL, 0x76485D347264E4D8ULL, 0xC2630FEF3146F027ULL, 0xC871F70CA2887DD1ULL, 
            0xB9C58369DD402382ULL, 0x372A5894359703B7ULL, 0x59451B136A92D93BULL, 0xC5725BE0910B941EULL, 
            0x10360C1B95F89D74ULL, 0x03C6186A235C3207ULL, 0x11A01564106460D6ULL, 0x570BFE4838A7F984ULL, 
            0x632AEBA2FE57F983ULL, 0x1AFA67219345E806ULL, 0xC7ED6318D4A66964ULL, 0xB7332274EA9B0E55ULL, 
            0x00C8B2D7C4054C82ULL, 0xBE7C3E2B428C074CULL, 0xA80814250E80458BULL, 0xAF175D9D954724A1ULL, 
            0xD9A97EED3619CE0EULL, 0x449A8C5098676414ULL, 0xED204432C2D0477BULL, 0xCDEEE24D7F06CDC2ULL
        },
        {
            0xC63E1B10817CD8B0ULL, 0x76CC1B349EA0EAC2ULL, 0x62F2EB127E0979E5ULL, 0x843DEED3F153C439ULL, 
            0x8E4377A6973C67D2ULL, 0x8B895DBD8C5EDA78ULL, 0x2F5D5CA9674497B3ULL, 0x2E14A54B98B04B73ULL, 
            0x207BA9FC87868E6EULL, 0x4C18C7F8D8A3FC2FULL, 0x7A3C3642A68BCCAAULL, 0x8C50E5C060186614ULL, 
            0x797EE32733377116ULL, 0x3B1A6EF0DDA7542DULL, 0x311029DA982BC344ULL, 0x319CEF7F2AA5B714ULL, 
            0xD038D1E897EB0C7BULL, 0x39D76D19ED298DACULL, 0x1BAC6E00B4315675ULL, 0xBCC3275DFB13D125ULL, 
            0x6D65AFCEB7BE7022ULL, 0x47E3DFC5642CFE24ULL, 0xE570ED091F0A2C48ULL, 0xF722E9BDBE64A47CULL, 
            0xCA630C82C4D469CBULL, 0x0ED93EC958BBCE1EULL, 0x1B1F015355EF9FD1ULL, 0x9110BECE388F2286ULL, 
            0xE38508913DCE8A24ULL, 0x5091C3FBA2289507ULL, 0x788B976B20ADD055ULL, 0xD6BB5E19B1DCA03BULL
        }
    },
    {
        {
            0x349D2672AC9936FDULL, 0x69AB76DDBFF44EFBULL, 0xFDE151909B30236FULL, 0x78D015C8FAC7E963ULL, 
            0x36C996AC1CE10138ULL, 0x3F9FB10AFC0DED06ULL, 0x52077D41E0AEEF84ULL, 0xE8B77DF1CA2EDB8DULL, 
            0xD519BB3A5EE57E84ULL, 0x57A58D64E7A19452ULL, 0x3D6B9420D268E0CEULL, 0x8ABC0473CF286967ULL, 
            0xF1096DD25BF71516ULL, 0xB71A1C019479271CULL, 0xF8FA74A2EE1C7754ULL, 0x6215080136A0EDEAULL, 
            0x66F8B95A291B3754ULL, 0x4E879EF436C214D5ULL, 0x053B9BB74D260F22ULL, 0xFF57A49FED46B961ULL, 
            0x537B19004D010FDEULL, 0x607A6570326CB0C9ULL, 0xF8FEBDF350E252F2ULL, 0x2159D7730BC9C93EULL, 
            0x84B87DDA05D0256EULL, 0x39835DD4A2B333A6ULL, 0x4825D62E15716071ULL, 0x9411A602FC72716EULL, 
            0x7FE12179C41C080DULL, 0x1518F967A590F6C5ULL, 0x5D1C626B92F2DB0AULL, 0x4101A21DFFF8F862ULL
        },
        {
            0x4EAB6324A2012EA6ULL, 0x8DEFCE5363AE1801ULL, 0xEDF55A6500CD1092ULL, 0xC39013C20E311B1AULL, 
            0x4D12E74607E0BA81ULL, 0xB315382E553193C9ULL, 0x6520D05644A13E62ULL, 0x6FED3020834EC949ULL, 
            0x5F72F35ADFC61BAAULL, 0xAC5F218A70053738ULL, 0x6ABA78F7FFE0622BULL, 0x06554C221F664ACEULL, 
            0xC4AA5C4637793DDBULL, 0xDE8EEF39F5F2E81AULL, 0x020851D66AA2ED77ULL, 0x943DE591A86B8190ULL, 
            0xB879927D89704E7AULL, 0x065603D48A7B5FB9ULL, 0x9C943CD691342F6BULL, 0x7682B48A5C53B17AULL, 
            0xA837F0348E596218ULL, 0x641886812294BD42ULL, 0xE21998C720B0330FULL, 0x2F1A0C10BF861B86ULL, 
            0x75F2B8E43A9A81E8ULL, 0x5FDEA21127648A66ULL, 0x76172C961ED9F3B6ULL, 0xB1AB9BD02977DEE0ULL, 
            0x7EEEE52E4AB22E78ULL, 0xBD59B85EEDEC50FCULL, 0x91C136EA22B11020ULL, 0x84A34AB980F62911ULL
        },
        {
            0xB7949ADAC13DE39AULL, 0x0BBBF4154F095E1EULL, 0xB441F396FF876C71ULL, 0xF7D7446E4473D8C9ULL, 
            0xF6A010A75667E098ULL, 0x582D5F6B901B9E75ULL, 0x0FFA61911108379BULL, 0x7F7B67F3003949A8ULL, 
            0x9FBCF022059B60AEULL, 0x59B9E1D56E203F99ULL, 0x322C79A7CF756E56ULL, 0x3DCFE7C880B5208AULL, 
            0xD6122EF5D105609BULL, 0xAE759A138373A5D3ULL, 0xA2792D3D51849C85ULL, 0x69C6974751B5F4F1ULL, 
            0x41FC9BDFAF1C3E5CULL, 0xA49B57B7BCF710A6ULL, 0x7570A5049F4092FDULL, 0xBA852A1A35B0D2C4ULL, 
            0x3215B5B8EF804FACULL, 0x8A85BA8AB5866E63ULL, 0xD07D4A9223E0AF89ULL, 0x3271681C1A539099ULL, 
            0x1A114986556A4665ULL, 0xBF2D034431064FC9ULL, 0xFC9D05CF7F270019ULL, 0xA4B6001E01E75AD8ULL, 
            0x2F570C60F37F12E4ULL, 0x4B20BCD2032B3243ULL, 0x0997888C2BADDE3DULL, 0x661A4384538F6ABDULL
        },
        {
            0xC5560AD0BC66562FULL, 0xFFF8879844E87F51ULL, 0x669056259800C93AULL, 0xFDDB6DB4C8C7CCF4ULL, 
            0x32CD19FD3D27586CULL, 0xE64165F4821975EDULL, 0x9252ECCF604F467BULL, 0x19D2EA2DBD493C20ULL, 
            0x1B2C71AEA9C07B62ULL, 0x5A9D9A9B1A4E5A5EULL, 0x01882C24E9E8375BULL, 0x975AD272A486E7DCULL, 
            0x544CC8D0FD23DCADULL, 0x9208ED66DA36D050ULL, 0x56F74B4575E387F7ULL, 0xF6C166D8E96996F7ULL, 
            0x8708DB8EA5B884F5ULL, 0xD522539B505D11C4ULL, 0xB11025AF11575DDAULL, 0xCE2678666D117DE8ULL, 
            0x2F9F2095B9A68E3FULL, 0xDBF6E394028FC703ULL, 0xFC20B0359EC4E1CBULL, 0x6E8E1E3A1577B1B1ULL, 
            0x695FA6AA95A9BBA5ULL, 0xB9A6E19B01831497ULL, 0x6A3A7610AF36E2FBULL, 0x8F2E27B298502C97ULL, 
            0x9CA67CE270BFFF69ULL, 0x06B4A6F0FCC101B0ULL, 0xE7BB1ADA9CE8FC8EULL, 0x26935227834BD19AULL
        },
        {
            0x195DF1167F632FA9ULL, 0x0864FE53E2C2FE7AULL, 0x1D7BC93D759F1846ULL, 0x160FA338D92BE167ULL, 
            0x2AA6E3CF7AC586B3ULL, 0x7975D141CF7D1489ULL, 0xB8A0674A55D54687ULL, 0xA954A2A2499A3D89ULL, 
            0x3CC92DA015AF33A7ULL, 0x7DF8108CE798C1B3ULL, 0x090A917BB61C2093ULL, 0x64F97F7FD16086B1ULL, 
            0x34A3E206DFE9E4B3ULL, 0xB7E56E391E6977D3ULL, 0xB87179E311AE8212ULL, 0x24FB284444C56E78ULL, 
            0xFFE83423E69FFCCFULL, 0x15E2E867CDA4DFE7ULL, 0x652208B5A9CD98F2ULL, 0x1CF27028AEC036F9ULL, 
            0x83EC307A0F6197F9ULL, 0xE83FF4BC70DCEFCEULL, 0xA952931A40A75B4CULL, 0x5D9633379BCA4200ULL, 
            0xC96321BE2F455549ULL, 0xA49E7E1DE22FB9D0ULL, 0x366B6862DC752D84ULL, 0x6385165A5C5B345AULL, 
            0x1FE6DD76704C813CULL, 0x64633B2D472BF111ULL, 0xD6A676995ABD3139ULL, 0x00DC55CC547E11DAULL
        },
        {
            0x7BF9B62FA0A78B6DULL, 0xEC4C54C2B271DA56ULL, 0xFF447106D4596823ULL, 0xE433DC386525E0E5ULL, 
            0x1F0EC0FDEB15DB55ULL, 0xA49942D40E62949CULL, 0x8B94568CB1AD13E8ULL, 0x0648ED1CA844FA71ULL, 
            0x68771BC8772C5E11ULL, 0x741B5A3B12530EC2ULL, 0x5F2A99F46486CD38ULL, 0xFACDBF1D1486DDDEULL, 
            0x98DEEECE21BB613FULL, 0xAABFEB74A14AE7B1ULL, 0x953D5E40901DAEF7ULL, 0xC8AD51D4ADEE15D6ULL, 
            0x6B73C67A9053E658ULL, 0xB2A73A5B76FC98A8ULL, 0xEFA9ED9D191DCBDFULL, 0x091B45DCE84BA78EULL, 
            0x495C264757CDDE50ULL, 0x7894707221F1DD57ULL, 0x460179B3DB79F2BCULL, 0xA8CC7AFCF5F8EFE7ULL, 
            0xFBFF338B74BDF7EAULL, 0x65789E15B626DB14ULL, 0x8B82E3BE9EC55D6EULL, 0x19EBF18F9C9BD366ULL, 
            0x4095FD1B7057EAECULL, 0xC08DD79F1E0077F1ULL, 0x60209700F9550422ULL, 0xE48172A20683AC9BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kSeedConstants = {
    0xA59BDCF8BC4F914BULL,
    0x144BF74A03028605ULL,
    0x09FA840CAE6AC1C9ULL,
    0xA59BDCF8BC4F914BULL,
    0x144BF74A03028605ULL,
    0x09FA840CAE6AC1C9ULL,
    0x3B90E58310070B62ULL,
    0xEE6BDD25C2C55822ULL,
    0xEE,
    0xE5,
    0xAB,
    0x9F,
    0x44,
    0x27,
    0x67,
    0x37
};

const TwistDomainSaltSet TwistExpander_Mimosa::kTwistSalts = {
    {
        {
            0x4E0126A6A9A65868ULL, 0x9B5D133B0932C26FULL, 0xB91695A92CB56062ULL, 0x58B1BA2B6FB40D80ULL, 
            0x87ECD6F88AD48BEBULL, 0xA48A04BAE06990ABULL, 0x824BFD302032A5D7ULL, 0x506851C72D52F1B6ULL, 
            0x3B669D6E2E79D6FEULL, 0x435BA02EA000D7BFULL, 0xCF93D192677268ADULL, 0xDDB09E54CF2525F5ULL, 
            0x2C80E436F39D9A24ULL, 0x0C28A7B47B6FF4AAULL, 0xD999CA218C24DEF4ULL, 0xC75FAC253F46CAEFULL, 
            0xCCF7054F3D8E037FULL, 0x270AD9F2F95B697BULL, 0x46624865834B7B10ULL, 0x625152CF5976BD18ULL, 
            0x57813F01F8905DF3ULL, 0xD2DF59A7B43749ECULL, 0xA0C5B24E85F6D717ULL, 0x7E7EE0F60FA87A11ULL, 
            0x959A9F0BD7EAB311ULL, 0xA48C57EC45E1BDC6ULL, 0x3504327973904B2FULL, 0xDD21BBEEF3B4F006ULL, 
            0x1638FF5D715CD548ULL, 0xC8824C9A5B42B249ULL, 0xFC872459609C38DAULL, 0x4AA3AEF46AAD6D8DULL
        },
        {
            0x4FF319B6F32879E6ULL, 0x3F7F48E2DB6D966AULL, 0xE8869A55FD688A30ULL, 0x73CC9202A392C5F6ULL, 
            0x3A324F9522A0A04BULL, 0xD203D96547350E45ULL, 0x8A9B44ADE16F33CBULL, 0xE95ADE86FD651C04ULL, 
            0x5C98580F40DCE87FULL, 0x12FDD673C7074CFAULL, 0xECAB8FDA54DC01E3ULL, 0x823CA159D03BC78FULL, 
            0x8ABA19FBADF35AD6ULL, 0xAC6BB7323799E2AEULL, 0xB0F5DAD91A3585FCULL, 0x4CF6C228B26BBCDCULL, 
            0x952A57FC449FDA0FULL, 0xBDC98C0CD0DC9372ULL, 0xAC1703E6597EC360ULL, 0x0B02D2D139D124BEULL, 
            0x60B620F3A32CD853ULL, 0x579DF585EFCAEA12ULL, 0x8BB98BE5276A30E5ULL, 0x9F2887D167E806ACULL, 
            0x3097D56E460AD29DULL, 0x7F98C11FB11F2E90ULL, 0x1E865B964AABEAA4ULL, 0x6C55F0D6E9D8D82FULL, 
            0x18AE186DE4077B72ULL, 0xF8D770C2F1652AF8ULL, 0x7BC02ECE5FD58E03ULL, 0xBAABBCDBCFD557C5ULL
        },
        {
            0x3B2C564C740A1962ULL, 0xBAC03D41C7FA252BULL, 0xC6C235E8D7B0A86DULL, 0x6DA4490F3C7126AEULL, 
            0x7761957D34FD29A8ULL, 0xBE880C5D05F4DFB0ULL, 0x8329731C6DE7E7A4ULL, 0x05D2E866DA5C4BFDULL, 
            0x3E26AE469FBA8E2BULL, 0xB8C8DBAED7693402ULL, 0xEABAFEC91CE9896BULL, 0xA5CED2092F79DA5DULL, 
            0xC686DBD620E7C719ULL, 0xE25F3D05B0448850ULL, 0x237B823D50AA5AD4ULL, 0xF6122234EB60E37DULL, 
            0xEA2304AC8FE996FDULL, 0xECB59E22B4CDAB69ULL, 0x911D1C3B5432C500ULL, 0x9567C151CFE6D9A5ULL, 
            0xEF0C158E3BD3EEBEULL, 0x691D5C835726440AULL, 0xE4D74A51CCA20791ULL, 0x10D8882DF58408E8ULL, 
            0xCD774094CD08C33DULL, 0xD7B870D824AB7DD5ULL, 0x30FEBF49351D3D9EULL, 0x0D9CA3D285B60F13ULL, 
            0xAF8E573BC56BDCEEULL, 0x0F3F72D4344672C2ULL, 0xAE2F2225B41A520EULL, 0x6952304C7A67F27BULL
        },
        {
            0x4FD7F4675A91792EULL, 0x01BE6E630450791CULL, 0xA89C990430A90147ULL, 0xA32B2607F4DAF1FEULL, 
            0x693053C882B0E1A0ULL, 0x4B341F457913C246ULL, 0x5CAF5CB5A53058CAULL, 0xA06B5DA71EBF35F2ULL, 
            0x1C405762EA71D1B1ULL, 0x3684A8D89B46E63AULL, 0x5A1494EF6332779AULL, 0x13A5C218055FE677ULL, 
            0x674ECF13C18D10A9ULL, 0x5B8CD181E09921FEULL, 0xDE030B3691A947A6ULL, 0xE225D2A41A15A7F7ULL, 
            0x7675E8F1D2FEEAFAULL, 0x0BB2C2ACE7BADCB1ULL, 0xED3743622D017985ULL, 0xC257A5D8DB8F6302ULL, 
            0x202EBE8CDA5D474CULL, 0xB11825CE70D459AAULL, 0x68AE78059DD7041BULL, 0x425862C387748EDFULL, 
            0x55C28474F7AD5863ULL, 0xC33D60DF859DF2A0ULL, 0x7422DDB58A86762CULL, 0x9E4D52E724FFF0E7ULL, 
            0xE2C1FD5DBF054F73ULL, 0xA5E94D716EFDB08EULL, 0xED28F434E01268A8ULL, 0x85650896E3400C66ULL
        },
        {
            0xDCAC78AA53B537E8ULL, 0x5D5FBED7F2F53665ULL, 0x4E7633CFA3F5CF92ULL, 0xE6BC00695465A90EULL, 
            0x51C27D409153AF8DULL, 0x04C951CD87BF9534ULL, 0x71B86DE8B286247DULL, 0x66BD438E072C8135ULL, 
            0x4AE14A0E44C7D239ULL, 0x647DF671C35CDFDDULL, 0xFF85CA7564D5ED89ULL, 0x8895345CFFB0E925ULL, 
            0x2A22BBB9492EF023ULL, 0x232C58E31EE7CE91ULL, 0x9D4CB9789FCE8BF2ULL, 0xFB999FD8F85544A9ULL, 
            0xBFBE7FAD5058A712ULL, 0xA38B000C04485F9FULL, 0x455B6BB5CDD1027DULL, 0x86B0EB9B926ED1CEULL, 
            0x6CFA70FDCF40AC3DULL, 0xD31FA0E62E700C71ULL, 0x239ED0A2560AE828ULL, 0xF156D139EEF8560DULL, 
            0xF81045F6E3F3287FULL, 0x71A79907B559521BULL, 0xA9024D1592E6F1C5ULL, 0x30F3DAAE7A7CB41AULL, 
            0x37C0BAB194635960ULL, 0x75BA5A0722284FE9ULL, 0x07388565734A9670ULL, 0xB544CCCCC6438DDAULL
        },
        {
            0xCAFADA4FA7986DBBULL, 0x116B94C4D3FDD8B0ULL, 0xAC45D1102233BF53ULL, 0x546E7B500824AB92ULL, 
            0x4EC4699D3CEA84D8ULL, 0x52F8DE3FBFC39E70ULL, 0x3CEC469D0804BE9AULL, 0xE9474F3DF39420C4ULL, 
            0x6750A44625AFAEC5ULL, 0xE4E17C4DDF5B7718ULL, 0x0554CB7214DDE0F6ULL, 0xF1C40A0E1FE0AD56ULL, 
            0x4A3D208F29A40429ULL, 0xE505A87DC95CC770ULL, 0x9C7A2461F1BD9546ULL, 0xF0FEB479638B09B1ULL, 
            0xB06BC9BA3A56D34AULL, 0xE529E6476D3C2584ULL, 0x16B08B862A7F6022ULL, 0x41716E1E2390D4D8ULL, 
            0x6747E228B3D6000CULL, 0xE8F36C12E5F59C5AULL, 0x5D9DCAB435603F80ULL, 0x79414EEB906B5ABDULL, 
            0x26BEFBFBF6A34F22ULL, 0x5A36E3ED8F4CC381ULL, 0x6E2B1F43F265BCF0ULL, 0x7B0763B8CEEB3991ULL, 
            0x5820AFA843840556ULL, 0x9F222ECF6F74CDA8ULL, 0x8F5664A051B243BFULL, 0xC54D3F709DD02CC6ULL
        }
    },
    {
        {
            0x7490CE34EAC67E68ULL, 0xE30791CFB942398DULL, 0xB18941A5DA872251ULL, 0x9C2E96FAD24A46E3ULL, 
            0xD8D2AB5C867E5242ULL, 0xC1D433E73A50E8BCULL, 0x90EC4794EECCA649ULL, 0xBB129AF8AFE9313FULL, 
            0x3D958AA92F983EB1ULL, 0xB270B45BBB7108BCULL, 0x7D56A8514F4C0E52ULL, 0xD8A84901A63F1745ULL, 
            0x4E9D1B49D7D015A7ULL, 0x11B8C84D9E53875CULL, 0xF318B5F7DE8F9BC4ULL, 0x8EEB4650FB129C62ULL, 
            0x784ED27C72ED76ABULL, 0xC744DE01AD69CD35ULL, 0x15F6E2494DDF2BA7ULL, 0x53E576B421B1EF2DULL, 
            0x55D492DC217B0969ULL, 0x013AD7CB66202048ULL, 0x1618ED1D49F7CA63ULL, 0x8A636311546E6781ULL, 
            0x639F942E53111962ULL, 0x5D6EC7534D2CB680ULL, 0x7830E610834C6F49ULL, 0x7CF2C0CFD1625B3BULL, 
            0xB29A75EBBF253112ULL, 0x5A65A450672275F3ULL, 0xE21496EE01B9CF4EULL, 0x953CA1E6013DA3ABULL
        },
        {
            0x2EE834465E1D603AULL, 0x9609C778F7166ED6ULL, 0xB063E047715511C1ULL, 0xEE6C7E142808BAD0ULL, 
            0x5105827F4E872359ULL, 0x83157F0713127FFFULL, 0xE370DFDEAB92F04BULL, 0x2BD15AF1C23F1F14ULL, 
            0x236E5C61F88AF5FFULL, 0x61A11B17C6125FA7ULL, 0xAB9940B595FF0E7FULL, 0xF274876FEBC5C92DULL, 
            0xC4EBC95D9DB4C14CULL, 0xEDE8E41F7CA41733ULL, 0xF5A4676C2C993B6BULL, 0x0CB1F074B38334B3ULL, 
            0x29B94A45D76C8EEEULL, 0x1F70B3B5EA05637BULL, 0x457781F98489254AULL, 0xFEE7EBC9D7D257D1ULL, 
            0xB8725C06E5E8996DULL, 0xA52BD6227CF64D76ULL, 0xA4E742DD0C4AC92BULL, 0x1099A5EE477B173BULL, 
            0x94B862A383CA03E7ULL, 0xC23266167D6E31C3ULL, 0x88476A32450707F9ULL, 0x80CE1B956CA09065ULL, 
            0x350A7B497C054B37ULL, 0xC37F3C2D3579D7BEULL, 0xBDF07599208AD99DULL, 0xEA09C60367AF6F91ULL
        },
        {
            0xA5C415C8CDD8FFFAULL, 0x677A32DB7D2193E8ULL, 0x4A1A274A61704ADEULL, 0xC930C56B14E2BEA5ULL, 
            0xFC67672840FF0921ULL, 0x3FD749C60FD3D792ULL, 0x55736DCAF3CD9870ULL, 0x5462B77510029B6BULL, 
            0x97324E0B5148A001ULL, 0x6968BCB2A87E51C2ULL, 0xE2326AABCCE6D4D1ULL, 0x0F3E724801239FCEULL, 
            0xA3324D08C4CBAFE0ULL, 0x74EB016E71AFEC99ULL, 0xDD3BF1AC442D97F6ULL, 0x4A4058E6652BAA27ULL, 
            0x41E246BAF20D464EULL, 0xC093CC373B798170ULL, 0x19F61CA59E7EC925ULL, 0xE9520B8C9AA15C65ULL, 
            0xF7897D72D28A3EF4ULL, 0x0FF2B305D4D5B478ULL, 0x60738C803CA37030ULL, 0x0B9DFA28ACB32A55ULL, 
            0xF872CEA11ECB9976ULL, 0x64BB25850968978EULL, 0xC501948B17E05E2FULL, 0x32740B32F02ECB8AULL, 
            0x1313EAD556D3E3E7ULL, 0x6DB13E1022CFF580ULL, 0xD76C8CF30B5C0914ULL, 0xB3955B4EDD6E3F97ULL
        },
        {
            0x3C41280E409DC00DULL, 0xB63C14EBF3F58F03ULL, 0x989C2D7F760F978FULL, 0xED663286F19D2F7EULL, 
            0xE9AEAB4143B4EE0AULL, 0x93725A498F5F6F90ULL, 0xFF5E299632E8FA38ULL, 0x561BF5C761231319ULL, 
            0x197B00F8774511CEULL, 0xFF2E985BD6851336ULL, 0x1BFD8FF820429FDDULL, 0xE979DEA02974C17CULL, 
            0x03A547A5A1DCA6C1ULL, 0xF51DB3D21FB24BA3ULL, 0x8EB17EAB9629BD11ULL, 0xF3A48AF8A92A43AFULL, 
            0xD4B745205782BABAULL, 0x8CE68EB879AFE452ULL, 0xB297F442381E1D0AULL, 0xF8085EB8130BF0D2ULL, 
            0xBB7E47DCE613D6FAULL, 0x394F898995C09F8DULL, 0x3AA4513F503CC806ULL, 0x33A7FB5B2DE7D0D3ULL, 
            0xA46457FFDA7C27B2ULL, 0xEA4D90EE331C9326ULL, 0x0BF8CB940FA2C522ULL, 0x7B4ABC1F803B7E15ULL, 
            0xAFF41303ECD39CCBULL, 0x1FBBC5EBB0731C55ULL, 0x3D0EC1CB288171A1ULL, 0xB63063F910E92FE1ULL
        },
        {
            0x4F54CCFC029E4E1FULL, 0x3FA8B3C43DB521F4ULL, 0xD1A36B759DE9A79DULL, 0xE4E3B97D35F92C28ULL, 
            0x0234A75F4C69674AULL, 0x89AA079CD86F3B14ULL, 0xBBD847B8FCA0CBADULL, 0xC6678E3E2E5AB2E4ULL, 
            0xE48F79F7D7ACB90AULL, 0xC3FE4FF58A3AB0C4ULL, 0xE486D9CC56A53ABDULL, 0x45C98D9A3FE097C2ULL, 
            0x104F775E992A7BE1ULL, 0x6953F7386CBD0AB9ULL, 0x59EB775771BC5578ULL, 0x686B7A3650D1CAC2ULL, 
            0x781D1EC2F2D0C832ULL, 0xEEEE6463ECA38E46ULL, 0xDDF86EA82B80561FULL, 0xD8860F6BC129FFB9ULL, 
            0xE93824B030D35D33ULL, 0x4B175C052BADD9B2ULL, 0xCC274D453EB318FCULL, 0x668C4BE8FFD5AB6CULL, 
            0xBBC61DBBC09116C8ULL, 0xBB58B32F6183DE67ULL, 0x84887263F32337EBULL, 0xD6CBB69D2D1597E9ULL, 
            0x7DEDC6D08C6BC285ULL, 0x2FAEEBC3E8DE15DBULL, 0xE5216FC5CB3B1BC2ULL, 0x4BB56660690FA4E8ULL
        },
        {
            0xF47A55DFF1054065ULL, 0x1E89BF727C43B188ULL, 0xD1963149ADF9E417ULL, 0xFBF57B8EA0E7D024ULL, 
            0xDB98F398BC0E018BULL, 0xEFCD91735F341799ULL, 0x271B6D8576DF6D56ULL, 0xB8AF4678F6FA2196ULL, 
            0x10C30F00483C072BULL, 0x7FD923FE52AD3239ULL, 0xCAC8BE8D80E27B4DULL, 0xE9D735F2629D2CA2ULL, 
            0xDEA04FA0C20E7C36ULL, 0xC8E81C98875E0010ULL, 0x37CDD8DB1036F0F8ULL, 0x1A92C601D961BA82ULL, 
            0x1C99B8A396CA7C4CULL, 0x7FA47D3D3FDC7BECULL, 0xD9910F324D44533BULL, 0xF9C56A7C2672DF0EULL, 
            0xFA6481FFAEFE439AULL, 0x90D08EA402AF21B8ULL, 0x983147CDB3E69FA6ULL, 0xB1A58F3FFAD25919ULL, 
            0x741853F302425AA0ULL, 0xA2322166DD9D9DEEULL, 0x476D2EEF005F075AULL, 0x219F38D6D3CF2B68ULL, 
            0x84E2CC1A2F3B3083ULL, 0x80556CC8368F74DFULL, 0xE525842481C3BA77ULL, 0xB9CB3EC37FEE9B3BULL
        }
    },
    {
        {
            0x1B22631180B14947ULL, 0x21BC32BEA9C759C1ULL, 0xCDA6E755C79FFF7BULL, 0x2274C230B1658EACULL, 
            0x0C4D7735BC7F8993ULL, 0xB64739E07333B030ULL, 0x55B4452CB50E4DCBULL, 0x88C55B2051CB3DFAULL, 
            0x6F1D0CF0FD17148EULL, 0xC8EBFEE0E2F4A38EULL, 0x1433E7B04B04F7D4ULL, 0xA8AC3563C86F0BD9ULL, 
            0xA96F651E00A2D22EULL, 0x406ABB6F72557E74ULL, 0xF4AC693C2C5C333BULL, 0x214DE8FA7EFE6EF2ULL, 
            0x3C29824D9F9B56DEULL, 0x6E8AF8A35741B29CULL, 0x3F3E57A0CE2EAD5EULL, 0x6BAC3B29C60F81CBULL, 
            0x1FACC6EA0C04383DULL, 0x3D22EB9636F5262EULL, 0x88B3FC56834D8BEBULL, 0xA93AE6378F66C8E0ULL, 
            0x227B46460AF72758ULL, 0x3F61C576BB07745CULL, 0x245CF1235202B4A7ULL, 0x1199CE6DC5604450ULL, 
            0x406C1FF9E47BA212ULL, 0x675AE0BF96E4E964ULL, 0x84012E34614FF2B4ULL, 0x2F8E7F6CFAAD257BULL
        },
        {
            0xE4EB2CE9ECCFDC20ULL, 0x260C3630BE76462AULL, 0x5BE93DB8D176B556ULL, 0x97656C17ED3F43F0ULL, 
            0xD536634BCFF31F38ULL, 0xD898E8B3066492C4ULL, 0x17FFDC42E0DFB33BULL, 0x556A4BA5476A8205ULL, 
            0x1024A12B4C3494B5ULL, 0x8DA7F57ED3B680EDULL, 0xB17BC5A8972031C0ULL, 0x5BDE2B9DCD7C8E03ULL, 
            0x9CB64CD5DED7ED72ULL, 0x84B456DE5D625763ULL, 0x441153BF9F382023ULL, 0x88A82034A06A288BULL, 
            0x70B659D44FE6FA50ULL, 0x77D376A1B1C89570ULL, 0x1755562A4336A225ULL, 0x05E56AC1C2C014A5ULL, 
            0x15771AF5528DFFB6ULL, 0xAB16B4DF8E2F42C1ULL, 0x4207F1CD2BD0AB74ULL, 0x5D8772CB51B7E029ULL, 
            0x32A9BC7FFAB43287ULL, 0x090081CFEA354291ULL, 0x4CC76ACF0E514B86ULL, 0xF779CD2D98F4C176ULL, 
            0xF9E65E1D243FA8AFULL, 0x98FCA675C59475E5ULL, 0xB4CB3E13BC641B17ULL, 0x9AAC7EC4BD40FD2AULL
        },
        {
            0x69D160025C857022ULL, 0xCC830E1DEDE33967ULL, 0x8508C0EC1F5D386CULL, 0xCB199A79AFDBDB2EULL, 
            0xE87395F7110497F9ULL, 0x83DE2457E1BF136DULL, 0x4592646E2E085287ULL, 0x492708C55C33BB10ULL, 
            0x1680C04195D18C49ULL, 0x771353A18987D1EBULL, 0xDE6809CD7D705265ULL, 0xF5834C9E1B8805B5ULL, 
            0x6D0A973DCF748CB6ULL, 0x8E8E110F10F4ACD3ULL, 0x6AD89CB97D3D6F42ULL, 0x9B9E5A4561666DBAULL, 
            0x24EC30F31E71BA44ULL, 0x0A1B32A96A9ED1ADULL, 0xA725FBEEB140EE1EULL, 0x16323C5F1233A925ULL, 
            0x5E4467B142E1DBB1ULL, 0xCBE318C85BF1D57FULL, 0x979FF6D8B875A506ULL, 0x7539F05D3920C7B5ULL, 
            0xEF7552D28ACA1072ULL, 0x2F26A85144A8C5BFULL, 0x0D86ABBD277B8A4CULL, 0xC919572AD55C7D20ULL, 
            0xCDAE10AE4FBF078DULL, 0xC38745F59AD3B0BAULL, 0x3D92B067B0F5EE58ULL, 0xDAD58D9FEF0BFE5CULL
        },
        {
            0x9F1134862064C001ULL, 0x2618478DAE69E4B6ULL, 0x6FC915074A7C8DB2ULL, 0x3860801EB6FC6288ULL, 
            0xDAED074A8594FF54ULL, 0x6FF63A7F32C6D1FAULL, 0x73234CD759E64EA8ULL, 0xECCDF9FE235EEEE9ULL, 
            0x3B9B486C4C2C5D38ULL, 0x88CD971DAA2E5DB8ULL, 0x54392AF4F4A6859CULL, 0x481F3FAE3875674CULL, 
            0x7957D023732C3586ULL, 0xE8520111EB075402ULL, 0x654EEED25390B09EULL, 0xABEB4191EA0F957EULL, 
            0x531CEE96A4B21150ULL, 0xF5F3E0EE9A5EACC4ULL, 0xC5ED05AD82A6AF4AULL, 0x4768459D7869F798ULL, 
            0xE30D3888555B05A3ULL, 0x3B9E2D647545FEBBULL, 0x404CF762813D0F84ULL, 0x1E1AF19C1D1A3772ULL, 
            0x8EE244EABC0A2E49ULL, 0x51C0ABD8769B44E9ULL, 0xB78D32F7E91EC6FFULL, 0x64097BD85DF03BBDULL, 
            0x878BF6C4BCD13C8FULL, 0x18133CAD02A3B198ULL, 0xB59AD42CDB6EC24AULL, 0x9B7C164AED20FC7AULL
        },
        {
            0x4E93A681141C08D6ULL, 0x192C65AA30E93038ULL, 0x8CCDBE6C2CF14442ULL, 0xDAB05481D6524B69ULL, 
            0xDCE183C889B57179ULL, 0xDC7493C806043B30ULL, 0x0FAD0BDD9CF2D622ULL, 0xEA9ADA3D2722C55BULL, 
            0xD97A526106BA1F25ULL, 0xBD7EEF42531CB487ULL, 0xBE9ACD5CEB4F19DEULL, 0x1CEB9CCADE94D461ULL, 
            0xCE37E2DE9E847952ULL, 0x45ECF056FFA01294ULL, 0x12D4A783C6EBDF5FULL, 0x593838F536A9989CULL, 
            0x7E0154F73DF324DEULL, 0xE3A6E7108A782882ULL, 0x66D315BEEC7A539CULL, 0xA58940CD1AB6706DULL, 
            0x3B447969C8711459ULL, 0x58356E669869E2BDULL, 0xCCC2295C409140D8ULL, 0x650F69AD5616DEB3ULL, 
            0x6102AE479E029B60ULL, 0x608E77F2A5AF5A50ULL, 0x4E58DA5BF8B6D039ULL, 0x2D041836D0EAFB68ULL, 
            0x72BC60FE649AFF02ULL, 0xF9C00A0684C97B04ULL, 0xB6D09BA34A8220DCULL, 0x72ECB04301FC772DULL
        },
        {
            0x7709A7D9BBF04A1EULL, 0x9080F8B27F2CAB80ULL, 0x8921408C633022D9ULL, 0x114FC8D376134175ULL, 
            0x9C3CD8FD62C0DACDULL, 0x20F661F7CA0363A6ULL, 0xF69B6D30BA5FD0F2ULL, 0x4690490D1E92466AULL, 
            0xDCE8002E786D1379ULL, 0x51BD6882E9DF300AULL, 0xEB3057BD7C7D1A46ULL, 0x8363901E77FC3867ULL, 
            0x94271AD2B668C747ULL, 0x1E33244864971FBEULL, 0xF367B26B43FAB0EFULL, 0x77D4567485D22DDCULL, 
            0xD72B87199CF1E1A6ULL, 0xD1DB39A088EC385FULL, 0x71AC0C04E2490DC0ULL, 0x38CBACE44391E76FULL, 
            0x348D9A9B96F10245ULL, 0x483C4B6C77C50A61ULL, 0xABB866AE17297741ULL, 0x531ABE6761CFAEDBULL, 
            0xFB8E07D36874A0D0ULL, 0x56AE0F0ED5B1A923ULL, 0x6A26B922AD74F20FULL, 0xAAB8D43DD9BA5B76ULL, 
            0x0489E5BB7E0AB573ULL, 0xFA09F080A72CFAE4ULL, 0x46E3DA2D8248314BULL, 0xD0E9C92D954BDE66ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kTwistConstants = {
    0x157EA5F9261F70CDULL,
    0x8A22F9D617928BA7ULL,
    0xA5FC4FA91400777DULL,
    0x157EA5F9261F70CDULL,
    0x8A22F9D617928BA7ULL,
    0xA5FC4FA91400777DULL,
    0x6176CC5073DD85E0ULL,
    0xCC28D478E6F12DCEULL,
    0x68,
    0xC4,
    0xE8,
    0xB6,
    0x3C,
    0xB0,
    0x53,
    0xDF
};

