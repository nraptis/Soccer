#include "TwistExpander_Mothallah.hpp"
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

TwistExpander_Mothallah::TwistExpander_Mothallah()
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

void TwistExpander_Mothallah::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8717FBAB38D84C3DULL; std::uint64_t aIngress = 0xAADDBB7D56E4050CULL; std::uint64_t aCarry = 0x818693B5A6520AC4ULL;

    std::uint64_t aWandererA = 0xC036C21A22810C77ULL; std::uint64_t aWandererB = 0xEE42FED61834BC6CULL; std::uint64_t aWandererC = 0x836144DCFEDF7058ULL; std::uint64_t aWandererD = 0xFA3DF3D660115003ULL;
    std::uint64_t aWandererE = 0xC98699FD3E62ECC4ULL; std::uint64_t aWandererF = 0xD024A84299A7E776ULL; std::uint64_t aWandererG = 0xBDD3AB88E853D2D1ULL; std::uint64_t aWandererH = 0x9E2FB0F55B83C905ULL;
    std::uint64_t aWandererI = 0xA3C3E9F0AC8D744BULL; std::uint64_t aWandererJ = 0xA6DA8C377D771903ULL; std::uint64_t aWandererK = 0xAA1BCA32990B327EULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE45A1D00FD7C480AULL;
        aCarry = 0x917DDF7B9C932668ULL;
        aWandererA = 0xDEEAA63F07041A59ULL;
        aWandererB = 0xE5773B34C0F0C4EAULL;
        aWandererC = 0xB75EC98A9EF23794ULL;
        aWandererD = 0xFF6411F7E28F7F96ULL;
        aWandererE = 0xB153CADD03F3ED20ULL;
        aWandererF = 0xBF0605DC38747005ULL;
        aWandererG = 0x839D63D1C067704EULL;
        aWandererH = 0xEE4C6948F27475BBULL;
        aWandererI = 0xD514311E65937703ULL;
        aWandererJ = 0xB62021C87C34AC71ULL;
        aWandererK = 0xF8B9F1AFCDB119E1ULL;
    TwistExpander_Mothallah_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBBECC938360A7365ULL; std::uint64_t aIngress = 0x947DA058BCCBA3F1ULL; std::uint64_t aCarry = 0xE22C87C178F0A0E4ULL;

    std::uint64_t aWandererA = 0xAA7BBA73D36506ADULL; std::uint64_t aWandererB = 0xD778B5EAC1E7B463ULL; std::uint64_t aWandererC = 0xB8AD54C038C7C0A7ULL; std::uint64_t aWandererD = 0xF5EA5B93378A7173ULL;
    std::uint64_t aWandererE = 0x86BA384E16B6AF99ULL; std::uint64_t aWandererF = 0x9128A51E7EB843CFULL; std::uint64_t aWandererG = 0xB89113296101EF32ULL; std::uint64_t aWandererH = 0x87A649EAEC5898EDULL;
    std::uint64_t aWandererI = 0xD0D2B52F67853AF2ULL; std::uint64_t aWandererJ = 0xCF56853C8068B78AULL; std::uint64_t aWandererK = 0xA76DC5885DC5C3A0ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD4BB4D50B70394DFULL;
        aCarry = 0x85375841C04F4278ULL;
        aWandererA = 0xDE5A7B76BACDC81DULL;
        aWandererB = 0xAB638BC0012A6A92ULL;
        aWandererC = 0x8DBE4F999D4FCB92ULL;
        aWandererD = 0xE33E0C478433D422ULL;
        aWandererE = 0xCD25D512FA4E485EULL;
        aWandererF = 0xD8326D550D4AFF40ULL;
        aWandererG = 0xDB051BFD0F3BA831ULL;
        aWandererH = 0xD1A2BFA3667E4004ULL;
        aWandererI = 0x97612891EA673F10ULL;
        aWandererJ = 0xF7B51B853CA82A32ULL;
        aWandererK = 0x9FAEC3207D1931E3ULL;
    TwistExpander_Mothallah_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA346DFEE61886AA8ULL; std::uint64_t aIngress = 0xB37E10B9213D1290ULL; std::uint64_t aCarry = 0xB4AA49A988DC9CD7ULL;

    std::uint64_t aWandererA = 0xAD156B6594AFC167ULL; std::uint64_t aWandererB = 0x8F3DDF7420B04A36ULL; std::uint64_t aWandererC = 0xC2DCD2994D3EB01EULL; std::uint64_t aWandererD = 0xA5E4A24CF9110040ULL;
    std::uint64_t aWandererE = 0xD0BDECE04DCF9ABFULL; std::uint64_t aWandererF = 0x8706E34CFE98F159ULL; std::uint64_t aWandererG = 0xB710C2995F043D7DULL; std::uint64_t aWandererH = 0x9A5D8739EE1E7B3AULL;
    std::uint64_t aWandererI = 0xBDDB5C88187D6DC4ULL; std::uint64_t aWandererJ = 0xCA1B107DBEA79BA2ULL; std::uint64_t aWandererK = 0x87BD4624C0D0371EULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC8B8BC0335BE273BULL;
        aCarry = 0xC0E7C07AC196DBA3ULL;
        aWandererA = 0x9CCC87D515F7CB67ULL;
        aWandererB = 0xA8B717D9492141DFULL;
        aWandererC = 0xE8F2C7566D54A3C3ULL;
        aWandererD = 0xF6D9B902CEA0D103ULL;
        aWandererE = 0x959AC746A4F93D42ULL;
        aWandererF = 0xA83DF703639992B4ULL;
        aWandererG = 0xF666EB4AF5716DB8ULL;
        aWandererH = 0x9AD154670EEC2093ULL;
        aWandererI = 0x8A4E49E5958D6FE5ULL;
        aWandererJ = 0xF64B0A0D95C2432DULL;
        aWandererK = 0xE311FDC719099FF8ULL;
    TwistExpander_Mothallah_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCE224299CDC36723ULL; std::uint64_t aIngress = 0xE2BC23A564167803ULL; std::uint64_t aCarry = 0xBFC7900576113EAFULL;

    std::uint64_t aWandererA = 0x91089F9F82AA04A8ULL; std::uint64_t aWandererB = 0xD959DA48266B6EB6ULL; std::uint64_t aWandererC = 0xA72B06EC26E23E97ULL; std::uint64_t aWandererD = 0xB8E226FCBF624DF3ULL;
    std::uint64_t aWandererE = 0xCCFA5579BCE6AD8BULL; std::uint64_t aWandererF = 0xC1F52B2DCF8A92F3ULL; std::uint64_t aWandererG = 0xC60E63CD493FE58EULL; std::uint64_t aWandererH = 0x95CCD8885279F023ULL;
    std::uint64_t aWandererI = 0xCD4D073EA05B9332ULL; std::uint64_t aWandererJ = 0xF950397EBEBB7516ULL; std::uint64_t aWandererK = 0xD0AD1E8678538EB8ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB665C1D21DF63FCFULL;
        aCarry = 0xC5AB3FBFFE7A11CBULL;
        aWandererA = 0xBD457F66C839F10AULL;
        aWandererB = 0xCC44D237B77B3038ULL;
        aWandererC = 0xB474FACA7ACAE7C8ULL;
        aWandererD = 0xF2A649215AF7ECA5ULL;
        aWandererE = 0xD7006F519C42C7FAULL;
        aWandererF = 0x801F434AE4F4186DULL;
        aWandererG = 0x8C36E5B8E712E927ULL;
        aWandererH = 0xEA569814C42211BEULL;
        aWandererI = 0x9ED6764486DDA583ULL;
        aWandererJ = 0xD0F5FF8B145C1EB2ULL;
        aWandererK = 0xDF7401ABF2A6F76FULL;
    TwistExpander_Mothallah_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mothallah::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x973EEE77D75933D2ULL;
    std::uint64_t aIngress = 0xAB0DC6A9A32258B8ULL;
    std::uint64_t aCarry = 0xB8A0A1F7DA72D958ULL;

    std::uint64_t aWandererA = 0xB331CB0C1AFC1579ULL;
    std::uint64_t aWandererB = 0xA22A3C16815CCE5BULL;
    std::uint64_t aWandererC = 0x8B8454324C5E535DULL;
    std::uint64_t aWandererD = 0xB65FBA55C693C28AULL;
    std::uint64_t aWandererE = 0x96E2D50643D3EE9CULL;
    std::uint64_t aWandererF = 0xE47C5FD4496485E6ULL;
    std::uint64_t aWandererG = 0xEDD8523FDC216BADULL;
    std::uint64_t aWandererH = 0xB85EFB77C0AFFB1BULL;
    std::uint64_t aWandererI = 0xACC9830370B20FF8ULL;
    std::uint64_t aWandererJ = 0xFD68B12161FFB1ACULL;
    std::uint64_t aWandererK = 0xAF7EAAF23E9EDAEEULL;

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
    TwistExpander_Mothallah_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KEY(pWorkSpace,
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

void TwistExpander_Mothallah::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDDB9328A93F58F3DULL; std::uint64_t aIngress = 0xCC9575AB9AD23617ULL; std::uint64_t aCarry = 0xBEBFC01F74B8A2E1ULL;

    std::uint64_t aWandererA = 0x8BEEEACC0F732CEEULL; std::uint64_t aWandererB = 0xA34B5F8AE29FBBE1ULL; std::uint64_t aWandererC = 0xF6D1C2DF79D8493FULL; std::uint64_t aWandererD = 0xED08AE4A68C96BA7ULL;
    std::uint64_t aWandererE = 0xBB21F796B50CCF17ULL; std::uint64_t aWandererF = 0xEF9199ED81CB7A9AULL; std::uint64_t aWandererG = 0xFD60E8F035B54B9CULL; std::uint64_t aWandererH = 0x905961008CB70F0FULL;
    std::uint64_t aWandererI = 0xC1CE4D09B7828C17ULL; std::uint64_t aWandererJ = 0xBB8F5F9776FBAA4DULL; std::uint64_t aWandererK = 0xBE45A90FC627CBFBULL;

    // [twist]
        aPrevious = 0xA9ED6FD2BF4559F5ULL;
        aCarry = 0xAB461D144AB9584DULL;
        aWandererA = 0x9B49D5473893ECC1ULL;
        aWandererB = 0xC1EC1E60A1CE7B8CULL;
        aWandererC = 0xFC77AF21DA6196D7ULL;
        aWandererD = 0xFD2FFBB2DFA96C29ULL;
        aWandererE = 0x9EC389FA76E563BFULL;
        aWandererF = 0xA388073E3A3F02CBULL;
        aWandererG = 0xCBE66D041B1B6499ULL;
        aWandererH = 0xDFEF7B93935EF9E1ULL;
        aWandererI = 0xCF39A793CDF6CD19ULL;
        aWandererJ = 0xD57D7810535EA3E6ULL;
        aWandererK = 0xEC98A7EAC2E9E9CDULL;
    TwistExpander_Mothallah_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Mothallah::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Mothallah::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Mothallah::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 22 of 33
    // Exploration cases: 0
    // Structural maximin 509 / 674; family total 11133
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 22 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 11179
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 520U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 22 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1048 / 1248; total 22567
void TwistExpander_Mothallah::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 22 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1054 / 1248; total 22602
void TwistExpander_Mothallah::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1534U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mothallah::kKeyRotateSalts = {
    {
        {
            0x56AA9552F80D6E21ULL, 0xF133D14D0BBBFB7BULL, 0x7333BB13019C3587ULL, 0xDFB380711C289185ULL, 
            0x6E81FCFDC342B663ULL, 0xC1C7F64CFBA3F46DULL, 0x7AC23D23411C6C60ULL, 0x689BD6218DD93994ULL, 
            0xDC3206073DCF7739ULL, 0xF1634CBA5230313AULL, 0xADA99AD7C03A398FULL, 0x7199E3FD6C8EF55CULL, 
            0xB58A71B09B25873DULL, 0xB8BC187460808E50ULL, 0xC3F995A71708D446ULL, 0x399E4484E2F28497ULL, 
            0xE011BB56B8423586ULL, 0x5488E628A60C84F3ULL, 0x624E05DB41DE2BFDULL, 0xE625A03DA75B30AAULL, 
            0x33AE3CEDFBE068C0ULL, 0xC86B4AA506F75BB2ULL, 0xCC820A60DFDF8DCCULL, 0x0826CE8CD10B4E5EULL, 
            0xA799B4ADD95D3E6BULL, 0xB9B7FD5F15B7C092ULL, 0x484A50E94FBDF56BULL, 0xBE7B48DBDB10A614ULL, 
            0x74F3D9A46D96A6A2ULL, 0xAB4B45EDFD0C96BEULL, 0xE4F6CDD2BFE6BBEDULL, 0x91922EF465F3D9F4ULL
        },
        {
            0xCFB45C6687A56B56ULL, 0x1280C7333909D49FULL, 0x5FE266E5DCF0C4E2ULL, 0xBEA8566B9DD1866CULL, 
            0x3A078FB6FC95B5BFULL, 0xA908D273CED62488ULL, 0xBA946DAB5DC52186ULL, 0x2BED9712212D7010ULL, 
            0x7B73B7A740031FE4ULL, 0x1B0BE9907CEDACC4ULL, 0x5C0DC6F7555DBF49ULL, 0xC95BC11E309D243DULL, 
            0x32B37B6813A54092ULL, 0x3C2792122D1C7EDDULL, 0x5D2E74280BBC90F3ULL, 0xC244126FCDE0F581ULL, 
            0x3D2F64948584CA1FULL, 0xFE2AE3A7626895BAULL, 0x4F1F5CA8554A0188ULL, 0x24B495E8B24D38ECULL, 
            0x69E90FE4079CCD75ULL, 0xC3D0E0BB9C6979BFULL, 0xB19D23135780C20CULL, 0x11D3DBEB251F4110ULL, 
            0xA04EA9908640FA70ULL, 0xF8C56D9D7DF823F8ULL, 0x751B44DB6BBA4CDAULL, 0xE55484CFB8034BD2ULL, 
            0x02D35AC40969526AULL, 0xAA3F8CC0CEE9B73DULL, 0x311F10FF59C3E436ULL, 0x2C0AD3624575795CULL
        },
        {
            0xFAB344196A6F8618ULL, 0x78785FD1B5EC6EA1ULL, 0x71BA75E2FF4EDDCDULL, 0x128A3BF16A91015AULL, 
            0x31AA4CE44C853339ULL, 0x763CCDE83A26D723ULL, 0x2C5134D0F960846AULL, 0x8404D7425FAE4684ULL, 
            0x8A153F93DDEFDDAFULL, 0xE5C9D1CF7E3E10BDULL, 0xCAC009A2FD40FE24ULL, 0x6808C622CE5BE233ULL, 
            0x6797BB2DFA187570ULL, 0xAC36CE71E506A64BULL, 0x48FA61BDE61F4AE2ULL, 0x33F40311942F6DFDULL, 
            0xA8C548EF6454DB2BULL, 0xF2DD2A05AC24CF67ULL, 0xB5FFFC7EE0CE50CDULL, 0x42FC3274A4BADEB5ULL, 
            0x32DDF445C51195CDULL, 0x79F337F61486190AULL, 0x3EFDFC432208DC9BULL, 0xDE9EFAD9E729BAD5ULL, 
            0xBA0D4DF720CF0857ULL, 0x8DBA9ECCBA7B45D3ULL, 0xEB58E41BA5B63E5FULL, 0x84443867E80C4509ULL, 
            0x4934C0B28C440095ULL, 0x49AE546EB9E4FC03ULL, 0x21B08C3D6FE0CE2EULL, 0xED82A94883300AE3ULL
        },
        {
            0xE35CA7F6349A8111ULL, 0xF1A50210EB6C87E5ULL, 0x4A7E5478ED43A428ULL, 0x9717E1B17C962159ULL, 
            0xEAD7400246D891FFULL, 0xFAB1AB1D25FD0DE8ULL, 0xF7953562718011E9ULL, 0x28F88FAAC88FCA49ULL, 
            0x7B3512436AF86628ULL, 0x4479376BAB20D8DEULL, 0x80611D6C1DE1381DULL, 0xE236225216D77101ULL, 
            0xFAB0204E85270D39ULL, 0x10D6687F4C5B7AD8ULL, 0x6D8634A903D494E7ULL, 0xAF940C4050FC2975ULL, 
            0xC3C7F22E1EBA736CULL, 0xD8F9D29617BA4C86ULL, 0xA91C664949D51A76ULL, 0xF45CE2B75124AFC1ULL, 
            0x26B6D73425486BA9ULL, 0x50500AD505C35C8BULL, 0xCBF1C47DCDF30820ULL, 0x6C38D222F929BE49ULL, 
            0xB28F2EF41E2B145CULL, 0x2E7518D9AF132E1EULL, 0x2DC161EEF2695B95ULL, 0x4D11A92ACBAD4E79ULL, 
            0xBBDAA0F08FF3B334ULL, 0x2120A7D54717AFA5ULL, 0x5CCE470E6931A23DULL, 0xBC08B1EF6FAD6271ULL
        },
        {
            0x90B194494D5AA0A9ULL, 0x1767D43916D17A4CULL, 0xEA4CFD85740D87FAULL, 0x5690C28C7E42F626ULL, 
            0x8363908D5105C619ULL, 0xC48380672C3193A4ULL, 0x92780FD8A56159D7ULL, 0xCC01F8F8A8019CFCULL, 
            0x4C77860F5628255EULL, 0xFEDED161F67A0E38ULL, 0x1F16D8C40D3B40A8ULL, 0x328FB7167032820BULL, 
            0x41B5C073EEA82BC3ULL, 0x3C27A7D0A6B3ED3FULL, 0xA1B7A6DC5D9B46C9ULL, 0xE8B2A4AF6342BE6EULL, 
            0xC68F71E59B8CB42CULL, 0x52BC96324F673A92ULL, 0xD70D24D04AD2C912ULL, 0xCB24226DFCCC54D1ULL, 
            0x0A1FAA1599203CB2ULL, 0xDFE98F0EC7165646ULL, 0xFA0A01CADD9AF2DAULL, 0xFA0670EFE04C4502ULL, 
            0x5E3460263FCF5260ULL, 0x780CA48E54A8433BULL, 0x16E6E74C2391A977ULL, 0x2BF8400BB1D0417FULL, 
            0x73E46CE913E7A66BULL, 0xF56FE25F07578B70ULL, 0xDD63A0608659256DULL, 0xDB764EA1D30A239DULL
        },
        {
            0x9E9A62F2344BD8D8ULL, 0x54FE37B70655EC0DULL, 0xC2E93346A0626A75ULL, 0xBE93FBFFA3712C63ULL, 
            0xACE66C7F37F828A9ULL, 0xD9A76D9CEC3BAE00ULL, 0x7AB2B053D8A819F1ULL, 0x57CAEBDBBE2713B7ULL, 
            0x07F733B6A5FEEA56ULL, 0xCE56694486737AE7ULL, 0x6502F1F3A30C833CULL, 0xEBB270B576AF67CDULL, 
            0x34B5ADF70E31BA0FULL, 0x5D514F32F359A0CBULL, 0x74E7D0594AF88B91ULL, 0xEB5D0983C92A607AULL, 
            0x00690C4827EC4AFDULL, 0x2057B1CB227E6BC3ULL, 0xD3A3569DB5091A1DULL, 0x068F84F60F17586EULL, 
            0xB7AE3C688003D73CULL, 0xAAE1476D2ADCEE42ULL, 0xC9E720C1C7A0BA41ULL, 0xC3E14977DD156CDFULL, 
            0xFA604662FA3EAF10ULL, 0x8FB9ED60EBEADCB1ULL, 0xE300A4030CDDF0C4ULL, 0xA720BE4BF0CFABBDULL, 
            0xCEE7528D38331742ULL, 0xDAF595B70E2A6D47ULL, 0x3630E2ABE379D1C0ULL, 0xFE21FCE476ACAC00ULL
        }
    },
    {
        {
            0xB329B0693A36DE3DULL, 0xCC62B2A30073059BULL, 0x15058BF2A6989DE3ULL, 0xB37A5D7598B681B8ULL, 
            0x272F1C883B956B5CULL, 0xCEAEB146D2100423ULL, 0x9CD1A0BC4524B481ULL, 0x1E9CAA0FA6D00B88ULL, 
            0x576EDF0D4C5D13A6ULL, 0x9F6D294E214E1C65ULL, 0xDF5C8CF28E479385ULL, 0xC508988912E30FDFULL, 
            0x949DB743AA38CFB3ULL, 0x8C5B384B296FFE95ULL, 0x559503240985532FULL, 0x320F0630D1DF974DULL, 
            0x55DEA62C20E97ED4ULL, 0xD412150B00182D2CULL, 0xA263168A40E166F1ULL, 0x8317E78F6D5311D0ULL, 
            0xC9B94B22B336A244ULL, 0x6B39B1CC75582FD9ULL, 0x045EEF7C1F7C5354ULL, 0x297C72576F22A1D6ULL, 
            0xC689BD9019EAB882ULL, 0x0BA9A4684E82F7A3ULL, 0x36A7E1E68BFA0D00ULL, 0xB75DB83B4672401DULL, 
            0x7F5EBEE0CB479F29ULL, 0x69DFBA25B1BD5572ULL, 0x5E692239B075DE62ULL, 0x02F5FCF7D4DECD4FULL
        },
        {
            0xA3C8366803796D6EULL, 0x3CBD26679A657045ULL, 0x09D68F5B2E84069CULL, 0x27ADDA4C6038D443ULL, 
            0x69BE2D9692C5FF36ULL, 0x9F52E2DA352372C8ULL, 0x6A92DFC8E8C072C7ULL, 0xB1B95D90CEF79076ULL, 
            0x0F3B67BB604B83EBULL, 0x672888670EB60897ULL, 0x0B21C5595B2EFC11ULL, 0x0716793CC3AFFEB1ULL, 
            0x9EBF6A6F3431DDC0ULL, 0x4DBFCC813021495FULL, 0xE37B5C19C97F6C13ULL, 0xB9A3DCCBBD8F082EULL, 
            0x1DB494A94F895EFBULL, 0xA6CDCFFD6898C564ULL, 0xB0CC62C58F9FC7BEULL, 0x1D83DFFC680144C7ULL, 
            0x60F2F79910C89B71ULL, 0x7244F57A86B26F5FULL, 0x89AB51AF266DC0ADULL, 0x7DC4FE4D0CD8B9A7ULL, 
            0x6C1107F131E1C0E9ULL, 0x2A0B0FA5DFD27FF8ULL, 0x12C96452B9BDDAF1ULL, 0x24B6228FFB06A619ULL, 
            0xA090A8CD57500E34ULL, 0x701048DA02A03892ULL, 0x0C1782F42CB3D115ULL, 0x7322BB540C474FA7ULL
        },
        {
            0x08BFAF3C562A9DB6ULL, 0x5EE26CA48E1C0B3AULL, 0x4080C82370B08DF7ULL, 0x37408278BC81D33EULL, 
            0x0D3C0AECD14B5071ULL, 0x04E95EFFD9CE2590ULL, 0x4160692BA96739F5ULL, 0x3621AF252114F423ULL, 
            0x8D55299E3B583166ULL, 0x01C1CA5B4B35B702ULL, 0xC1935270684732F1ULL, 0x0262353A2E9819C0ULL, 
            0xBC8E2B5B36C2AF77ULL, 0x2F0075CF6F0CE5D1ULL, 0x697CDCCED089C55DULL, 0x5585EE8429C52648ULL, 
            0x4DD97FEAB7F94C03ULL, 0x6964C8DBAE7A5EECULL, 0x2D1E495AB01FC41EULL, 0xE7DA6EE96DC52572ULL, 
            0x8E78CE144ECC7E35ULL, 0x7835A31029C344A4ULL, 0xEA91D52229CDFE96ULL, 0x8620466BE75DC054ULL, 
            0x83B750BD3E44C2BCULL, 0x2B60A9E78F9E9B4EULL, 0xE0BC063355E27513ULL, 0x87D6E001515CA881ULL, 
            0x2C61DA5403C40F42ULL, 0x28C755EB181639CEULL, 0xEDD74FCA58755D68ULL, 0x4033FFE4CB4F2FBEULL
        },
        {
            0x8CF2A8F72B091489ULL, 0x06C166B41729CC98ULL, 0xDE0382B9C9DAD872ULL, 0xE1EC02D5D67085B9ULL, 
            0xDAE2B1FFADC7971AULL, 0x07776031D0010B37ULL, 0xE585966269395FD8ULL, 0x4F46B04623920027ULL, 
            0x38391AB56568D7B3ULL, 0x269E6AB332D69285ULL, 0x238DF067D391777AULL, 0xC8AB00EEEFDE4C4EULL, 
            0xACBD86E45CC6F7A2ULL, 0x385EB4E5040DF3F3ULL, 0x120194FEF5992661ULL, 0x9460E797659B8C90ULL, 
            0x854303C4B696154AULL, 0x37638FDE80B07FC0ULL, 0xE72017C81030BAC7ULL, 0x23CF20B55522E818ULL, 
            0x45B1C7570F94BF37ULL, 0xBCBDEE72F58B8CE9ULL, 0x3C4EDB5600E2ACDAULL, 0x5CC7842B8B4FE097ULL, 
            0x1D24E81F0EE2EE15ULL, 0x4848DFE984C4C0AEULL, 0x4648E0B234339973ULL, 0x78788EE5641BF5F7ULL, 
            0x8D0F068FA1897C2BULL, 0x30781F9EE104C6C3ULL, 0xA593589EC92C0DCFULL, 0xE9D4E3C731A63669ULL
        },
        {
            0x99F2C4B881990529ULL, 0xF601DB066D00553BULL, 0x4119CC20CB5B186DULL, 0x0BBED123A40E286AULL, 
            0x1DD85EB6C5587899ULL, 0xDF4FAA90B2F50D03ULL, 0x7687D221A1D20281ULL, 0x08A5AE2F337F2AABULL, 
            0xB3C026AF6B9FE246ULL, 0xB04BAA2236C5CE71ULL, 0x3C48A44C6C699AF8ULL, 0xA4063648A2A7FB0DULL, 
            0x824DAC2587833556ULL, 0x5E16788A67289727ULL, 0xD4E22C30499AEDE0ULL, 0xF5AA5D4E13458F55ULL, 
            0xE1C15BF36F4DFA74ULL, 0xE60033D44D2F7533ULL, 0x04E33D182E243448ULL, 0x72C9796649644678ULL, 
            0x9C5EBD89C169CC1EULL, 0x4876FA5144B686C4ULL, 0x3CAE101946C27885ULL, 0x6DBE2A0705447675ULL, 
            0xD02E07FE97896860ULL, 0xD8D21704422A7093ULL, 0x9827A3C4EF987239ULL, 0x3B1303868106E2C4ULL, 
            0xA158625B0B89B510ULL, 0xD8AC02C43D3D315AULL, 0x7644FEBD37074FADULL, 0xDE56F644DBB54C38ULL
        },
        {
            0x895E047436F1E9EEULL, 0xE4494A340064C63DULL, 0x101B03557BE84739ULL, 0xA035A3C6E56E6510ULL, 
            0x28FB35C57EF3090FULL, 0x9FFF4A9F01043837ULL, 0x2C897EACBB9133B4ULL, 0xF92C6A27F6555352ULL, 
            0x7A524D2D3C0B349CULL, 0xFD87136811E1E386ULL, 0xD152C0337701EBDFULL, 0x48425CD424979FEDULL, 
            0x952DE7BC356BB747ULL, 0x2229308813590405ULL, 0x983BB8B02CD9FB84ULL, 0xE80B3F03C6D561BBULL, 
            0xC04A8A9C7C53DE90ULL, 0x556251685E15EE07ULL, 0x128CBA9061157D4CULL, 0x77A598B1A036BE1CULL, 
            0x0FE8C7815A442446ULL, 0xEA42F2561BC7D082ULL, 0x13115D9455DB46FDULL, 0xAD87E7A1D92C9346ULL, 
            0xB273E9C95A33EBD3ULL, 0xD72F2449443EAE45ULL, 0xD165148D276DBFFCULL, 0x97FDA9D483F2CB18ULL, 
            0xE8C78223C4A24891ULL, 0xDD1AE7170775874BULL, 0x6B425AE07825190DULL, 0x9458C80AE3C0BCE2ULL
        }
    },
    {
        {
            0x389088BFEBC6D3A7ULL, 0xB8DDB84A9DEF6EA8ULL, 0x65317634E710715EULL, 0xF6D30AEF195CA748ULL, 
            0x7FB37B3A6737A2AEULL, 0x54EAF7B2F6EDD3BFULL, 0xC819300E69F975E8ULL, 0x7249911262FD9965ULL, 
            0xE9E669608107D1B8ULL, 0xE7DFA583FAABA0A1ULL, 0x6C8D2DD617AE6C71ULL, 0x2DF0073AF6339ECDULL, 
            0x32867613C521754CULL, 0xC5AE1F50F64C5820ULL, 0x163010651DF036B4ULL, 0xDF7FF106B406A45DULL, 
            0xC55A50CA8A6462F6ULL, 0x48C48C56A2DE7C5BULL, 0x044F572FC1994B66ULL, 0x30AC8E278E70D159ULL, 
            0x32F52F420B26AE29ULL, 0xE4FCF2BA76E82EE0ULL, 0x856B1C0A025E8AE4ULL, 0xE34492D958146D27ULL, 
            0xDB0E2041505A46D9ULL, 0x665F1FE3FFD728B6ULL, 0x0A33E7C541BFA7DAULL, 0x87DD30E32D3EA77AULL, 
            0x61B0DB39904F6865ULL, 0x9CD69C9F9616B289ULL, 0x7C9CD5CBFFF20C3EULL, 0x25EB94B7B9B1FFB5ULL
        },
        {
            0x6208EE4CBC81547AULL, 0x5AAE51B781D7D017ULL, 0x3F667D89D03EAA26ULL, 0xEDE97185A62AB0F9ULL, 
            0xA2B3F8DED8FCA5E3ULL, 0xA212AC2523E91491ULL, 0x63F3249D1284784DULL, 0xBCC1C649A8AC3E83ULL, 
            0x4C87395F8D93669BULL, 0x397793492D1D64B9ULL, 0x61741148E5B5C9A2ULL, 0x66362E8E8D186991ULL, 
            0x63348CE2CC9734EFULL, 0x80F77B0741523E1BULL, 0x33DCFB6B9075D5A7ULL, 0x1B82B3FF71ACCBEEULL, 
            0x63F232379FF84F0DULL, 0x13C8049C62013914ULL, 0xE212064BC36FB08FULL, 0x657860FC45D77541ULL, 
            0xA1D2542A2FF73B64ULL, 0x9DA82617072311F9ULL, 0x3560883F52F6BB7AULL, 0xAC53A6D483CDD86EULL, 
            0xA007A8AA27AA7DEBULL, 0x46991CFDC0787AB4ULL, 0xEBC6B48C885771F8ULL, 0xFB57A5247C1D6314ULL, 
            0x397B650688FBD360ULL, 0x5BA5A4973C6D04E8ULL, 0x31789F415C3C0738ULL, 0x155EFF7DFF47B4FEULL
        },
        {
            0x7A20BC178F648E11ULL, 0x3364CB59D1CDA04DULL, 0xC9409402CC0D7C73ULL, 0x7F4E02E08351CAF1ULL, 
            0x33DF82BFC6C2E32BULL, 0x4C86A3B17D75EAEBULL, 0x2B36A9B8731FDCDCULL, 0x0B03EB923B2ECE00ULL, 
            0x874F608D86ADCEA1ULL, 0x87AB7F56C4FC9AE2ULL, 0xF6B66E2A2C42A330ULL, 0xBEC7924F97A2103EULL, 
            0xD75D480A9A664D59ULL, 0x095050D814F0E589ULL, 0x9DC8BADE61A45320ULL, 0xD1B484F61B1C4FA0ULL, 
            0xDA3049A2B29E9948ULL, 0xDE87574052E30698ULL, 0x0F41E097003E5431ULL, 0x7172B102FC7061F9ULL, 
            0xC934F447C5639774ULL, 0xAC0B5BCE8DBDA243ULL, 0x1B0D1AFA7CD17A86ULL, 0x91829FBC15148CE8ULL, 
            0x6488DFE3260C7B52ULL, 0xA7BDD9360C40F0BDULL, 0xBF11BF114BA33E38ULL, 0x47B6E6CE956578B3ULL, 
            0x61480FE4E563EF06ULL, 0x8A857C87EB8B3639ULL, 0x4D61A9FA298CD9E6ULL, 0x2DC990D076619988ULL
        },
        {
            0x803C97ED07A4C11AULL, 0x65ECEC1295ECA93BULL, 0xDE70CC450BEB19DCULL, 0x6D31BF5312F482B7ULL, 
            0x252B98416E86C5A7ULL, 0x32CC164B8A4D8CADULL, 0x0C8FFF1F57149C7BULL, 0x1B693529DC659F51ULL, 
            0x8CED499A86776CB5ULL, 0x85C26690B19F9B62ULL, 0x763240ECE8CAAFD6ULL, 0x3393A1CCDA3F7095ULL, 
            0x3BC14F9A12B1DB79ULL, 0x293D9F4E5539151BULL, 0x9462B841EDC847C9ULL, 0x3249C878F37899A3ULL, 
            0xCFB7838B9FC53ED5ULL, 0x9DBD79BF59CEBE88ULL, 0xDDA96C02ACFB319AULL, 0xEF38801ACFA53A67ULL, 
            0x8E570259F53DAB70ULL, 0x70B1E64186D6D3D1ULL, 0xEE3CB1C37C2DAEF8ULL, 0xD0EA5E844D2AA5EAULL, 
            0x78D54770B880C98DULL, 0xB5246E130D4BFFFFULL, 0x6571A9EC8A84A5F8ULL, 0x1AC0137F5D3E4F60ULL, 
            0xEDE8C04AA03665AEULL, 0xF84BFE3C94B5A050ULL, 0x7E5807BC530D12D2ULL, 0x309F6E237D0BE413ULL
        },
        {
            0xAA4FB5839E13DC1BULL, 0xF4D161A469631E16ULL, 0xE8AEADBE0839E5CAULL, 0xA5F31D53A4AE3CA8ULL, 
            0x8BC7250EFE0A7885ULL, 0x3A3598EDCA60F4D4ULL, 0xB29DD5CE3250C152ULL, 0x8459939E6529146EULL, 
            0xD91B57BC73291ECBULL, 0x82DAD281495A26AFULL, 0x1F3C3726C6647CD0ULL, 0x5088DB90273B597AULL, 
            0x1A566701F0B23751ULL, 0xB47AC46C56C25444ULL, 0xF729BD794AB0002EULL, 0x7EC9E921092D484DULL, 
            0x356BE9499DA724E4ULL, 0x6B91675E1E6024A5ULL, 0x94CEFC1AB3FF0BBEULL, 0x6055171BCD9CC2E9ULL, 
            0x5B3C0E62BF57085BULL, 0x8349493776FC98E7ULL, 0xF9C766B26D3E232AULL, 0x7FC5B3BC5BD69CB8ULL, 
            0x838257FDE854B6EEULL, 0x815554142EADA1C5ULL, 0xEA937E3A07B4BCC8ULL, 0x4183622ECFEB637CULL, 
            0xD7E2E7B48CE3A184ULL, 0x442367CE380EDB62ULL, 0xB00F54FFCE9B66BAULL, 0x7B7ED6232C19D25BULL
        },
        {
            0x7F441E2AFE0F66F3ULL, 0xDE38E012DD6107E5ULL, 0x866B992A4464D6ADULL, 0xDD7E95A7DEBED096ULL, 
            0xF28BA1625FE3D8C0ULL, 0x6045D8C7E8F25119ULL, 0xB23AFD0CDBAA167CULL, 0x6E1AEDA5B9C92977ULL, 
            0xDC1BC6EAFB7E1F70ULL, 0xFA09B4C35EAE4563ULL, 0x55F1D74CD0DBEC8DULL, 0x80B198629C798686ULL, 
            0x8E4A082EC8951B00ULL, 0xD1FA314551B7EBF4ULL, 0x3FAE2950EB6A6C83ULL, 0x7492D54A5071062BULL, 
            0xF7915B6D381007B8ULL, 0x05CD4FB354A2620BULL, 0x09AFF2244F3C57E2ULL, 0xD25076CA7BDAD3BCULL, 
            0x57828EE586B15D60ULL, 0x920A4A3994E7C827ULL, 0xD61B93BD76AA5694ULL, 0xAC02AB531FA5EB49ULL, 
            0x689C3236A6A48918ULL, 0xE2355C27416512DCULL, 0xB29E4916AD81B0D6ULL, 0x69B0641D5F51B340ULL, 
            0x0C91D08C911B34EBULL, 0x4E4A998A607CE33CULL, 0xA41CB86F7A841947ULL, 0x85E4D3966CBBF0C7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeyRotateConstants = {
    0x0AADCA85926DFE27ULL,
    0x8DEE4EF306D3DAC6ULL,
    0xE536FD1CE1503474ULL,
    0x0AADCA85926DFE27ULL,
    0x8DEE4EF306D3DAC6ULL,
    0xE536FD1CE1503474ULL,
    0xF3BC5C224EB0ED5CULL,
    0x2F8B6836EC1163CEULL,
    0x25,
    0xD2,
    0x46,
    0x79,
    0x6E,
    0x5E,
    0x8F,
    0x93
};

const TwistDomainSaltSet TwistExpander_Mothallah::kKeySpawnSalts = {
    {
        {
            0xA7BF99A0C307C832ULL, 0x31EA17D99F4EB977ULL, 0x9610586C6702BD88ULL, 0x38688258C96C8DEBULL, 
            0x313D36ABDC309E6AULL, 0x1A123B19C5A1E93BULL, 0x94858E9F22CFB4FCULL, 0x493A318E00143D08ULL, 
            0x43E4D44A88A2224AULL, 0xF8CA0ADC3B29ED4EULL, 0x49FBBC836E4B7C28ULL, 0xAB68A4C06E383F6BULL, 
            0x52F5CD16BAB21FB1ULL, 0xBAEA0F9B3A0DD181ULL, 0xC437ED4FBDA97C91ULL, 0xB2BDDDFC4E312A61ULL, 
            0xC1B70B2D06BF7139ULL, 0xCB1D6C8EA024CED3ULL, 0xAFA304038C1595CFULL, 0x761B23CDE286EB05ULL, 
            0xE3AB178962CE2E70ULL, 0xE040E0D6CE4899C0ULL, 0x29E647E53DD74AE4ULL, 0x5975FB4D6CED086EULL, 
            0x4A64D3554E4D554CULL, 0x5916460B13B1F209ULL, 0x8E498AEA2E517CC5ULL, 0x8DC7AC1808AFDFDEULL, 
            0x68ABEDD172EBE267ULL, 0x6EFA97F5945D139AULL, 0x96E1060E4C58460BULL, 0x46EFD7D95BF2656FULL
        },
        {
            0xB9A1B1073336D9D0ULL, 0xDC0F8BD4FCF66386ULL, 0x9A94271F6DBD21FAULL, 0xDF40F5B8B18EF214ULL, 
            0x823D15D3D767ADB5ULL, 0x8D63267010244D67ULL, 0x18D2262B809CC6EBULL, 0xF45B9204A4BDDD99ULL, 
            0x27791E73A9B5A0CDULL, 0x69BD0869848E077CULL, 0xA1738C97ED718922ULL, 0x3FD8B55EF7AF55FAULL, 
            0x487DA980D58BCD23ULL, 0x8E2A3C08C07CA79BULL, 0x1A9EB6EE87CDA7EBULL, 0x9BEA0FD1785B821AULL, 
            0x1CD455E5AAB4527BULL, 0x9F988873093D59F0ULL, 0x8A4A3664D6AD6147ULL, 0x12EBAE163BAEC18CULL, 
            0x4E84CC9524923D75ULL, 0x8FB3713A5630BAD0ULL, 0x994291083C5A210CULL, 0x411BD7AE1945A311ULL, 
            0x29E4C74819840697ULL, 0xC4D8E42AA92EBADCULL, 0x3843CC2AF7CA19E3ULL, 0x7F07C46420C4D35CULL, 
            0x0CB4AAAE054358C1ULL, 0xA815CFDA12467523ULL, 0x5CDBF0160AD796E7ULL, 0x7A6789DDC9E2A924ULL
        },
        {
            0x1EB2FAEF02369A8BULL, 0x50259A9175131699ULL, 0xFBC97F58FA7A3719ULL, 0x8EBFD3C2A2744048ULL, 
            0xA7549EC989AB153CULL, 0x46187398DB751180ULL, 0x370A2F384E4C2042ULL, 0xEC00A0BFBD23316FULL, 
            0x858FF8A11F00BE15ULL, 0xC5918C6E76762318ULL, 0x449CC1AAF0A46871ULL, 0xAF82D237A6614354ULL, 
            0xA6C43A7DEE6068FAULL, 0x202DE07BF63C90F5ULL, 0x980E2B01AD155EECULL, 0xDC38C275964DDFE0ULL, 
            0xC05FA7900F02BF06ULL, 0x5430DABE19879706ULL, 0x3C15A1ADBE2B533AULL, 0x3FB47B400371625FULL, 
            0x7F8E22A8FDB50555ULL, 0x83463818175E8807ULL, 0xC722D619D97ACAD5ULL, 0xECE05F4A1E843621ULL, 
            0x471545B2F921CD54ULL, 0xC6F6E33F170E6C38ULL, 0x4D7332DBDFA717D8ULL, 0x677D1A07E589474AULL, 
            0x1115A54D8F6D7B6EULL, 0xF9F1EFEF1F7DB52CULL, 0x6787A8A90A8F942EULL, 0xC8A3E4AAD6EE9E42ULL
        },
        {
            0x7E928B58CDECA706ULL, 0x4F19EA49C45177F1ULL, 0x90AD3939CAFC1939ULL, 0x8B2FC43D23B4320EULL, 
            0x6D86A4E5D5BAD892ULL, 0x451FBD24783BFECEULL, 0x5AE2BC7DA567CB24ULL, 0x6875D2414424AFE3ULL, 
            0xAED789D8AC1A264FULL, 0xF8CC141F42FAED3AULL, 0x497E6518ED5E042AULL, 0x70D49FED58B04ABDULL, 
            0xD0195B4B1009F9C9ULL, 0x945BCB4917D11877ULL, 0x1A6742621A992E73ULL, 0x5849CC39D1900D07ULL, 
            0xBB0D79C5D3FFA426ULL, 0x63F491A490398A88ULL, 0xA3D92461950DD3D9ULL, 0x009AB481D13AE9DAULL, 
            0xCA0F717684FE8785ULL, 0x71FCB24366F1E647ULL, 0x68416F9E6E2EC6DBULL, 0x0F98B129EA257915ULL, 
            0x9229611640A0DA49ULL, 0x9A1F5DE54B053D30ULL, 0x4A3002EFC685B80DULL, 0x486A43161A004D53ULL, 
            0x9F4BA75163651858ULL, 0x2CA8F1A9297941C5ULL, 0x9FAC84F387EA08A9ULL, 0xD207ED1F683B9C0BULL
        },
        {
            0x65747F2C8C13F29FULL, 0x119247ECEA0729DCULL, 0xD8A351E5383213A6ULL, 0x5AD1977B5ADCD533ULL, 
            0xC581334A1F43C123ULL, 0x2011F062ADF997FEULL, 0xD595E91600EA6628ULL, 0x856A0612AEAD0604ULL, 
            0xACF74813635A5810ULL, 0xA001F01E28EF18EBULL, 0x871C4469C219E998ULL, 0x668AF2B993384C12ULL, 
            0xCEC8B93872DFAF73ULL, 0xAC1CC53C783F8F6EULL, 0xC0994A8E255E166EULL, 0xF670E5FFEEB43154ULL, 
            0xC6D79BD664D2AAD5ULL, 0x97A7396062E3B745ULL, 0x2AB1F0B2842EC8B7ULL, 0xB60E048FAEEF2346ULL, 
            0xF50D95B66770CAD4ULL, 0x9859A2B5CEBC2837ULL, 0x07E97491FA07EAA7ULL, 0xF3B45B8B9E841480ULL, 
            0xBFC3EBF5E7041816ULL, 0x7007816B06CBFD43ULL, 0x231B56D58A00B54BULL, 0x7E7B6535FCD4E07CULL, 
            0x4BEA3DF7471B514EULL, 0x973E08648353E832ULL, 0xC6A598F0A3D9C099ULL, 0xFD807650CB7CEA6BULL
        },
        {
            0xA4DDEF215BBBFF7AULL, 0xD30008B36E52FB15ULL, 0x9DEFE67F34E7E944ULL, 0x08680021A3DBDACDULL, 
            0x59E81305DACBFEBFULL, 0x0BEC42870E98C387ULL, 0x131FFF74EA88A29CULL, 0x498D345E737B5EFEULL, 
            0x8880F01CE741C55CULL, 0x589799A43F2F9BD7ULL, 0x0E1E49C93600B486ULL, 0xEB6A82E6A4E0FC52ULL, 
            0x527DDD9C1BD11A15ULL, 0x1E18766775B55B75ULL, 0x2B6521694F7E768CULL, 0xE961DBE17F2CF0AAULL, 
            0xB1B519D0E77B8B4FULL, 0xE6728D06CA50866BULL, 0xDAC45BEB519E8B9CULL, 0x1C7719DE33AA6AEEULL, 
            0xC03B8948A49F5281ULL, 0x6C98E93DC506D5D2ULL, 0xB7C0BF262D03F98AULL, 0xB2093A4CA9667BEBULL, 
            0x239171DA32EB408CULL, 0x491D8A79EE7C89A8ULL, 0xBADCE8BC69322507ULL, 0x67B849C27190968DULL, 
            0xB3B2F7D4AE5ED5BCULL, 0xC8CCE42672B028A0ULL, 0xECDCB7A8DBC947FDULL, 0x3D7ADC8E464686F1ULL
        }
    },
    {
        {
            0x51E4B306CDA599B0ULL, 0xE6AE8C309C7E8B24ULL, 0x4DA3F0E5FA9C1D0BULL, 0xF70A38F4FE9D69DEULL, 
            0x337DA161DC9F44BEULL, 0x94300AF061D03768ULL, 0x31A572B29FEA38E0ULL, 0xDF2C8F17E9D7581CULL, 
            0x8D7D3DBDF0902861ULL, 0x1257F412ABE4CB9CULL, 0x4591759FD13DC743ULL, 0xBEE883F65AE7683BULL, 
            0x59E3744025DC051EULL, 0x4F191BE51E72A66BULL, 0x1347B591EF6524A2ULL, 0xDF92EDA76A9FDD2EULL, 
            0x13F9A9BCE940C46EULL, 0x684A084B8D6F788EULL, 0x15B7144E6DB01870ULL, 0xC22AA45F8C6421B9ULL, 
            0x21BC13BA9BDFAF63ULL, 0x91586C08B3447C9FULL, 0x9BBF526530F89045ULL, 0x8239DCF1FD61E383ULL, 
            0x415DFB52F9FCD581ULL, 0x183B9336CF154E12ULL, 0x161A3B92194B182DULL, 0x35652285DA23F8B1ULL, 
            0x1E26CE80708C47D4ULL, 0x5A4FF3DD932A81DBULL, 0xA9AE9EE2B76497CAULL, 0x51DE266DF9950803ULL
        },
        {
            0xF44599E9DB0675CFULL, 0x84D0BEC82B61C84DULL, 0x07F9B65350D97933ULL, 0x1EE5F6A3A98C9E82ULL, 
            0x4D3A776FBDCF7FFFULL, 0x5CB7954352755ED2ULL, 0x192E822AC146D8AEULL, 0x54A1A40E91AFC512ULL, 
            0x37F4914F0A3C1258ULL, 0xEA86F46510B5F3A3ULL, 0x07C6DD1A42B99993ULL, 0x66C0F506E1ADE2B5ULL, 
            0x6DF029478C6CFBA1ULL, 0xE9204658FFF179C5ULL, 0x033D3FEEB9105C38ULL, 0xC3268A85CD02BF31ULL, 
            0x0A257E59B3750B1AULL, 0xBCC01BFFA21F5D5BULL, 0x2EEA9FB2ABDB9A6DULL, 0x22DB8A842EA1BC38ULL, 
            0x2515114155A39268ULL, 0x7F00B6A58EA11B9BULL, 0xDF4AF69175B59672ULL, 0xC533C1CE8703B932ULL, 
            0x793B6A14B6A659A3ULL, 0xBA0105CE597359C5ULL, 0x217AEC60E8A0C072ULL, 0xA5E3756E92200638ULL, 
            0xB94B86E81F724B73ULL, 0xDAC823F70F8F418CULL, 0x5424F66F2698234CULL, 0x7C1A150EA9ED8455ULL
        },
        {
            0x62B656FCC6639082ULL, 0x5EB2C40BEECF544DULL, 0x263E7452120A840FULL, 0x0F2DAF9F51607BCCULL, 
            0x4CC1FAE4D23516AAULL, 0x851A3CA5E9F13B74ULL, 0x199D5DAF8305D1E1ULL, 0x01A5480F600C3E00ULL, 
            0x4E2D0436C2F2035DULL, 0x2909C5367766F626ULL, 0x847DAF9B04CAFE9BULL, 0xF45BB2C986C89C84ULL, 
            0x7ABA03AFDF9E8B9BULL, 0x787584B6CF5A2BEBULL, 0x518EDB8F335C08E8ULL, 0xE42973456285C67AULL, 
            0xFEC56C356357419CULL, 0x164BDD1862348CBDULL, 0x8444949C0DCE76CDULL, 0x77E2374D1576659FULL, 
            0x017A924B3D1BF0F3ULL, 0x3A5A7085BFEC3DD0ULL, 0x07EE8EE4D0DD9740ULL, 0xA8A5A45431422506ULL, 
            0x07718055E31F5607ULL, 0x2E9D171C89A81975ULL, 0xA58C5BA45EEDE480ULL, 0x99DE16BEA5559705ULL, 
            0x573BC5E48F8AB19AULL, 0x39F09B551926516CULL, 0x22BCF7A5587BC335ULL, 0x7BC4DB7878D9F5DCULL
        },
        {
            0xE974288CE29E5A4AULL, 0xCA57E675D3FBF492ULL, 0x3931F2CA650CFD46ULL, 0x3DE89AC3F4A01743ULL, 
            0xE14F4EA269DF6495ULL, 0x0D57946EB69EE34EULL, 0x808ECB8BBC1AB45EULL, 0x4AE65C73C6A48CC7ULL, 
            0xA95BDE9BF27C409AULL, 0x39576DB9FB7327FDULL, 0x7D109E833C719CDFULL, 0xED3E939F121402EBULL, 
            0x1FEC92F87E1087C2ULL, 0x831FD5459B363290ULL, 0x86EEA6C8CE6B37C4ULL, 0x0FDE9D3DC62D110CULL, 
            0xF7FC5151F1A3BE35ULL, 0xC07641546175FBE1ULL, 0x72158DF9A547AABCULL, 0x77766E5C3CDCFFA5ULL, 
            0xDFEC1378E3B6B66EULL, 0x2FD10B2F4C9D74D3ULL, 0x2AD28D455B5C14FDULL, 0x6C2F226425084782ULL, 
            0xF5F9B9AAC5F793A7ULL, 0xF23794EE122667DFULL, 0xA082ADB89657475DULL, 0x8373183122635CCCULL, 
            0xCD0B7BC9B10BDB61ULL, 0xF676FFE3EF5ECCDDULL, 0xB3D37C7EDBB867D2ULL, 0x51B13577DCE4316EULL
        },
        {
            0x0512DD18C1E8E9EDULL, 0x60B7D65A45B60010ULL, 0x34582D22E5458DD4ULL, 0x727ADD74C7D2E73BULL, 
            0x83C1287B768A4167ULL, 0x04DD36DB6C92F8ECULL, 0x1F4596AB49CDB627ULL, 0x053DE8873E910364ULL, 
            0xFBC2BDA52E44F1C9ULL, 0x3384F68E2D5A89DCULL, 0x47A74B9F2F881ECDULL, 0x60C7101F82E95D60ULL, 
            0x46A6B52D9D189579ULL, 0xCB352D2550284993ULL, 0x46405D57B1F0A0ECULL, 0xA7E7677A18CF268FULL, 
            0x38C33AF530B4BE5FULL, 0x60999680E96059D3ULL, 0x051D3482B63A8D65ULL, 0x56849B24A7CD9459ULL, 
            0x90F3237838F1ABA6ULL, 0x5612C0AC291C920CULL, 0x66F71EFDE4AC0756ULL, 0x188A717BE2D007B0ULL, 
            0x5BBB26D241CA2FAFULL, 0x103E3F19B1BBEF0FULL, 0x1EB1A9686D06822CULL, 0xEDE9C6D121ACEEB4ULL, 
            0x9CD948304E70E1B5ULL, 0x7485FF32E2387621ULL, 0xB595C491542EA4DDULL, 0x0C1D5B48A6AFAF6CULL
        },
        {
            0x99EB5FE93C20A0EAULL, 0x23ECC80D9A606239ULL, 0x76F1237FE3F838D2ULL, 0x1927415D3D81BACAULL, 
            0x22337E953902B79FULL, 0x576DEDABA730FAABULL, 0x068A66EECFD0F040ULL, 0xEC3101CF27CFCCA4ULL, 
            0xDDDADF8D44207786ULL, 0x6CC50733EA9BBDC3ULL, 0x7BC8AF6526B4FD84ULL, 0xBA4AC70B2865A9EEULL, 
            0x523F73D89CEBDC8EULL, 0x868EF1A2A94BEC84ULL, 0xB36DC14B8049CAA8ULL, 0x2E2EABE4732D4713ULL, 
            0x9E2F22714C95D2CBULL, 0xE42E68C27B7F387BULL, 0x5966977967772EDCULL, 0x72F837BBF49BDE92ULL, 
            0x57ABEDF5529DA49AULL, 0xA3B7CACC40069531ULL, 0x923E0142FDAD5630ULL, 0x604E1BA55F718FA6ULL, 
            0xD5ADCF3E74492F55ULL, 0x0048BC5B175D28C4ULL, 0x84571A7023DAEAF1ULL, 0xD15A93D64D13E62BULL, 
            0xA864812B70DD0313ULL, 0x2E15D3F77400899CULL, 0xE3B5C195F7D86832ULL, 0xFB56293C551280D6ULL
        }
    },
    {
        {
            0x454B5A0E625238AEULL, 0x98FBBDDAF04264A2ULL, 0x9C29FA9F95A5BC28ULL, 0x716D4CC08B5030A4ULL, 
            0x7F261ED3D7FCF877ULL, 0xA9F7AC50CF69CA01ULL, 0xEBC815FEBC1296E6ULL, 0x8657BFBA191CFF43ULL, 
            0x335B2BA5CCFBBBEAULL, 0xE35AD1B2F81D9BDFULL, 0x1CE7B4659C24381CULL, 0x5015AFF2DB03B6FBULL, 
            0x84B8B66128519ED1ULL, 0xDC8F7B37952233FCULL, 0x002B21F1C64413EBULL, 0x65B9F870C6D94022ULL, 
            0x8C27BE624A76F63EULL, 0x097AF421B856F6E3ULL, 0x1CDD538A762722FBULL, 0x927AD11D1412E98AULL, 
            0xE14E14D961A62C2EULL, 0x70B1013D87FBEB97ULL, 0x0BE16B04A2A4297AULL, 0xFF84BCA8FAE30530ULL, 
            0xA80768306E50140FULL, 0x41CC84C20C6CB23CULL, 0xE8644141483C0933ULL, 0x747AD22FA73CA4C1ULL, 
            0xC2DE7535A61D3882ULL, 0xFAE7D2FFB8D5C7C8ULL, 0xB98048100002D472ULL, 0x4DF1A1455784C87CULL
        },
        {
            0xE2D2938F77CBA64DULL, 0x621C00F5FAE0B13AULL, 0xB40475DA9D3A77C0ULL, 0xC0F2FA5067306334ULL, 
            0x86AD07A101786AA4ULL, 0x794E770DD30E2C61ULL, 0x141C18250E571AA9ULL, 0x40A24F0C0EAA7BF3ULL, 
            0x458E6E8183792C50ULL, 0x429A7CD72A2AA947ULL, 0x7E635F0D6B5BCF94ULL, 0x0B9A65CE066BEA3DULL, 
            0x610CC9684CFE7DCFULL, 0x6BF8B37F89A99AA8ULL, 0xE22EA8CEC6157757ULL, 0xC4E30DB3090C3022ULL, 
            0xF0CB9AF11A9468B4ULL, 0x6589494B49C7B4A7ULL, 0x2089222F036B6E6FULL, 0xF59675A36532D45EULL, 
            0xB69C22F7C4A70EDBULL, 0x8E497C6C79AB1A22ULL, 0xC0135F2AF55F7DBDULL, 0xFC7C61E3C275454DULL, 
            0xDAA905FFAFF5D0BAULL, 0x03BB960E87399D74ULL, 0x8BDB3298C022D3A0ULL, 0xC4574D27B61CF3E3ULL, 
            0x9C600D5F80A8BDD5ULL, 0xD1B8F6EC5B69F2BFULL, 0xEDBDCE20C924204CULL, 0x99420A7991C40F38ULL
        },
        {
            0x77D7BC4F01E48773ULL, 0x2EBFBDC0153650BAULL, 0xD2BF58D449474524ULL, 0x9044F116098DDEF3ULL, 
            0xA1F1243036029DC3ULL, 0x15B4484F6371EE6EULL, 0x8CC50BC0D3B594B1ULL, 0x8A8BA6CCE3CA898BULL, 
            0x75F0D260A44D9954ULL, 0x7968A4CD283CEC73ULL, 0x9B9F3196D05770BEULL, 0x25550B86E5D0C88FULL, 
            0x9EC234453FF31D4CULL, 0xBBCC4CF80891C78FULL, 0x124418D660511B33ULL, 0x9933AAC9F31A4FBCULL, 
            0x9529DD6A3B0F4E93ULL, 0x90B538BD30C122B7ULL, 0x91944BFCD757F05DULL, 0xCE55B00FF6B6FE25ULL, 
            0x1CAFC2E6CB3BA1B9ULL, 0x9A8DC33CBAA7DDD5ULL, 0x0215705F0BD3C3CBULL, 0x004591DE5252E216ULL, 
            0x4C6843E2B06463DAULL, 0x2BB323FC72D59B6AULL, 0xA609B41946501C91ULL, 0x12378B7D9FF44D50ULL, 
            0x734E1B8EE0B6D521ULL, 0xAB9B71CFA15F6491ULL, 0xCDF9380440E361E3ULL, 0x37AA7295A0C79B07ULL
        },
        {
            0x85E42A074116DE8CULL, 0x4CDDA48B1096C600ULL, 0x7D7C4E347B5F689AULL, 0x6F1C2CF8FF2D5FEEULL, 
            0xCC729253CFC11E4CULL, 0x80A8E9240ED01012ULL, 0x17E5AE9EB26B3653ULL, 0x21C1CFD17F2FB414ULL, 
            0x2141B31063B334F3ULL, 0x483E532ABA87B150ULL, 0xD407CA2AEF2B41C6ULL, 0x1EED73229F228627ULL, 
            0xBD85340729F0C62CULL, 0xB008967674E06AC8ULL, 0x4CDF17921DDBFCC5ULL, 0x061A2F53FAFD84BBULL, 
            0x51D891C976B4875FULL, 0x38B4525977135F5EULL, 0xE6CA93229394FC59ULL, 0x399DBB42DBD2AFDFULL, 
            0x0A92DC88BF7AAA7BULL, 0x7855F92DB62BCF7EULL, 0xB0B71E6933EE7110ULL, 0xFE69EC0D0DC646F8ULL, 
            0x1D4923A54AC657E4ULL, 0x7040C54950860538ULL, 0x0F40B292FC60C5B0ULL, 0x5AFB68FB14217372ULL, 
            0x7B904E433BD3A204ULL, 0x6606FAAE8630E7ECULL, 0x5F98756EC7646D22ULL, 0xD9A857171E17585EULL
        },
        {
            0x4ECEC8FB824B0978ULL, 0x1C5E3E98D74C8585ULL, 0xB9C19B67FE8DF48FULL, 0x0D0526DDE5F876ABULL, 
            0xAF6846794B2D52EEULL, 0xA663D85049FEBEA1ULL, 0xEE193A899E072844ULL, 0xD04102D3E4144615ULL, 
            0xF92381672C17983AULL, 0x1E190B5F571ED0B9ULL, 0xBCE871D822DF421DULL, 0x34A80147CC45E2FBULL, 
            0x646AF388112F64FAULL, 0x63245B0EBF8F03EDULL, 0xE42B9A8A62EF91C0ULL, 0x5F4AC10042AB8576ULL, 
            0x004836703A0E239DULL, 0x4F254E9DE487163DULL, 0x73E07CFDACE5E088ULL, 0x3D573B783FE25DF8ULL, 
            0x27A49BFEF2681922ULL, 0x786BAACF3E7C8DA2ULL, 0xF13C504AADA42D62ULL, 0xF83F7789D559F062ULL, 
            0x99F969D09DA0A21DULL, 0xF083F7C1C91AA19BULL, 0xCCD95992C98FADEEULL, 0x19DCFF0C95B0EB06ULL, 
            0x3964669F903187CEULL, 0x6A832FED1350DC83ULL, 0xECC6A23F7B6B8154ULL, 0x6B818A81A4D21394ULL
        },
        {
            0x94290D84AEE68515ULL, 0x3A8A3744DC371103ULL, 0xF9544A001A5CD7B7ULL, 0xECA52B20C6C00AF8ULL, 
            0x8568ACABA0E462ACULL, 0x7EB3E47904EABC84ULL, 0x51F2BA0DDF761E12ULL, 0x45F5F276BC455131ULL, 
            0x2E3054FAC41453C8ULL, 0xAA40CECC5DC56012ULL, 0x3406FD9E2C705107ULL, 0x4B968D17DCD9917BULL, 
            0x383FDDACEB486C27ULL, 0x4F6B492F9545F6A8ULL, 0x030C72E2652BB9F4ULL, 0xF41F3049848BF8EBULL, 
            0xCC121C0D688D1BD5ULL, 0xD371DADDFE7DD1B7ULL, 0xF6D078F1B030CE30ULL, 0x42EB0C93D4DDA527ULL, 
            0x3F227A11E501F8F9ULL, 0x16B3534437D21D35ULL, 0x1608E43997537DECULL, 0xDE2700050E39A735ULL, 
            0x29739AF346C2B146ULL, 0xF269622E7B568E45ULL, 0x202B26E1118E503CULL, 0x2D412EDBD012EFA4ULL, 
            0x639CC7EFEC76D9C3ULL, 0xFAAA28581BA9E3B6ULL, 0xB53BC51403E1D844ULL, 0xD53F1FCD46E44C64ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeySpawnConstants = {
    0x70B4D43D07BA9159ULL,
    0xE127F6FCB2392E7DULL,
    0x393499C8CD3161DCULL,
    0x70B4D43D07BA9159ULL,
    0xE127F6FCB2392E7DULL,
    0x393499C8CD3161DCULL,
    0xB46927CF2C0AAC34ULL,
    0x3F9A707DDD57192DULL,
    0x13,
    0x15,
    0x56,
    0xEF,
    0x57,
    0x18,
    0xA7,
    0x67
};

const TwistDomainSaltSet TwistExpander_Mothallah::kSeedSalts = {
    {
        {
            0x73B4E83AB6FAC843ULL, 0x57345F699D005A59ULL, 0x330CC64042BC75F6ULL, 0x8DF949F15263239FULL, 
            0xA0897C1925C83FCDULL, 0xE89ED65998446210ULL, 0x6F04B5585E791688ULL, 0x89476BBE13AD2180ULL, 
            0xB5C8C5AA9FA687CBULL, 0x8D91941A9AA62A92ULL, 0x1FA18ED76472FDE8ULL, 0xFC62756DCCAB8E0CULL, 
            0x37927F5B227C0D74ULL, 0xFAEF9B2B880976E1ULL, 0x1DBE937A864E1914ULL, 0x38EB83880931F58BULL, 
            0x9B143638813ECF32ULL, 0x162B1577E9DBB74FULL, 0x266B0F7F62000D74ULL, 0x0B9584F84475ACEBULL, 
            0x109309F9519F4176ULL, 0x80FB4A5B5230C5B3ULL, 0x6F7A6D236317C74FULL, 0xDC64E8118BB5498CULL, 
            0x6E877EBF1E8184FFULL, 0x00B780905A131241ULL, 0x1BE23D1A782C4832ULL, 0x9AE46A10AC70FA5CULL, 
            0xF87BC43311F7A674ULL, 0x1C727861606C52C5ULL, 0xF03DD4A090E813B2ULL, 0xAF80F4164499D46DULL
        },
        {
            0x75C20F0A7CA55882ULL, 0x6D3E9D64EFE0CD32ULL, 0x60D8E3ADE591649BULL, 0xC6E5463066546826ULL, 
            0x89086B7F31CD9DA2ULL, 0x8A36120A9FDA927AULL, 0xA69C53388B01ECB7ULL, 0x0C2AC8A36CD50A05ULL, 
            0x9D571DD12B07681BULL, 0xBE3344B64DA15F55ULL, 0xB400348818F8B4F3ULL, 0xAC601B82C457518BULL, 
            0x5A2CA1A227E16BD7ULL, 0xCE9D338F21024FCFULL, 0xC56B5CAF2B9CF73CULL, 0x7AB8DE1E35A125FDULL, 
            0x4C0133E61B1D809AULL, 0xC032C94B03A6D96EULL, 0x5BBA3042E0E56A57ULL, 0xE48EB205854BD8F1ULL, 
            0xFC14D92CB8979090ULL, 0x9727409BC2BDA61EULL, 0xEC440E29C98B1EB5ULL, 0xEE02A1FEBF41D63EULL, 
            0x682B93502D67673CULL, 0x5F274871FDAEDF4BULL, 0x597D3A16747CE676ULL, 0x4CBDB0BD0B747D7BULL, 
            0xA9677FB353D91255ULL, 0x30ACD18D9A1801F2ULL, 0x9EE3C872FAB8DF40ULL, 0x4880021DAB71B90FULL
        },
        {
            0x40FA8DA0BC489116ULL, 0xBCD88975F4AD6233ULL, 0x38ADE5526D888CA0ULL, 0x4FD6939CEBADFD0BULL, 
            0xF679F87FF7BD14C9ULL, 0x9507B32797DA5B4DULL, 0xB19C1FE2AE5981D9ULL, 0x6728C35EF7C35EC5ULL, 
            0xB38A3DF4FBFC719DULL, 0xAC6FBD0EC85C010EULL, 0x8D64D2FE92418E79ULL, 0xBA3518CD01E6D4B8ULL, 
            0x33293B3A006D9B78ULL, 0x9240F25FCB133186ULL, 0x9895DA530613F6D7ULL, 0xDCAB3B1BCC3FF7DDULL, 
            0x6BAA967C34D7AE9CULL, 0x40FB959B4BD5AA60ULL, 0x91CFC01E8DCF8A85ULL, 0xAD641EFC51B03BA1ULL, 
            0xA74B74311CA75E9DULL, 0xD0B98B89F125B4B7ULL, 0x153315124D2FD5B8ULL, 0xAAD2D91F91945F63ULL, 
            0x82B5A8A8057540F5ULL, 0x0C49454ADEA31746ULL, 0x2F67FC355BECC933ULL, 0x64461BED1328DA0BULL, 
            0x8B92FD0D7CAFBF24ULL, 0x0DB31ABF6275364DULL, 0x75D18A0CBBF0CE6AULL, 0x4B5C28E770856A87ULL
        },
        {
            0x2C1F573AC025C136ULL, 0x7780FDDDBF07BFFBULL, 0xB6F114840412E204ULL, 0x83A49B4B72E682E5ULL, 
            0xC2140C37644B03EEULL, 0x967FE93DDA747CE8ULL, 0x34B50AAF442F4DA3ULL, 0x628D2EBF08D5FC64ULL, 
            0x19BE5984E7E82C49ULL, 0xDF8ABC113A936814ULL, 0x4398F7D8B3E7F09BULL, 0x4B5A1912679D250EULL, 
            0x644496A47FD03F02ULL, 0xAD4B740671E68E45ULL, 0x9E0889811DFB5C03ULL, 0x91DC8DA20ECDD5ADULL, 
            0xFB27089411E068F6ULL, 0x68E0EEFC86AE085BULL, 0x2E733F475A2298B0ULL, 0x8E7EA95A35398E5AULL, 
            0xCC92ED5ED0620022ULL, 0x4F18F4BF8F51DFDDULL, 0x7BBC02368188BF12ULL, 0x74E283C98BD73D28ULL, 
            0xEC2AE41AEC447D3EULL, 0x0C128DA7F9DAD6EEULL, 0x1CD93726AD25670BULL, 0x60BEE9971D271AE5ULL, 
            0xE14DB31B40BC5436ULL, 0x46D44AD0C9003696ULL, 0x5B6A483AE9EEBAFCULL, 0xC3C5165AE9CE56C5ULL
        },
        {
            0xEE90849A72A515E5ULL, 0x591936346104851AULL, 0x841AD1E961D60C4DULL, 0x98569E439FD53626ULL, 
            0x522AB0DEC3688F7EULL, 0x03B2453FA826E957ULL, 0x66EC84BDF5B66D2BULL, 0xFA35CC00D842F66DULL, 
            0xB2EDE8C1D96B4A87ULL, 0x653216417F7618E1ULL, 0x721FA4EEB47E937BULL, 0x6B9B5DA04FC480C6ULL, 
            0xE119983A2D6C6AA4ULL, 0x6B875C20F3D32520ULL, 0x270D809757FFDAECULL, 0x4A47B07B73759136ULL, 
            0x22F8442B11886B93ULL, 0x4D67CD7743D247C4ULL, 0x312C0574E6FF377DULL, 0xCC8F6D6594D49013ULL, 
            0x1DC384D22411DED7ULL, 0x3DD7413AF0606D0FULL, 0x97022CB0B850A50FULL, 0xFA74975090625B2AULL, 
            0x3777B8D612878F56ULL, 0xA0BCBCB03389A576ULL, 0xD10A83083D3B4DA6ULL, 0x533BE9AF32CFC4B9ULL, 
            0xACF67BB3B8D72A1EULL, 0xB3FFB75F102EACF9ULL, 0x26C9B162A2091C58ULL, 0xABA6CB2764C5D179ULL
        },
        {
            0x35B3FAC0532BA567ULL, 0x7CCC15B0E6C52272ULL, 0x9A79293F895D30DFULL, 0xCE593A021464F285ULL, 
            0x3A42247E2FAB4EC4ULL, 0x80A302662F6A1A84ULL, 0x73CC06F39F10F391ULL, 0xE9F409292801ADB5ULL, 
            0xE2FC49BD417E7E1CULL, 0xF99E7392D2881986ULL, 0x428082A50041CC89ULL, 0x9A24A9CE0AFD5825ULL, 
            0x29CB52AC7D9C41A3ULL, 0xDD4F19AECB6DDD0EULL, 0xA58A92BD4131AE3EULL, 0xB6E314B607489B0BULL, 
            0x40EFE2CC32D4C26AULL, 0x57DD86043EA6D2B2ULL, 0x8476FE034307E3C9ULL, 0xFB729B86C5AC3626ULL, 
            0xD392703A11CCB2ADULL, 0x2D60ED3EC2775F88ULL, 0x519362F5124B9374ULL, 0x63A6AB320D73DB01ULL, 
            0x425C49DDE5DE80CFULL, 0x35939217ACADFCDDULL, 0x18A59B17DFB7F7E5ULL, 0x72AE036E270F1DD1ULL, 
            0x927EDFAF4663EE4AULL, 0x44738AC0D32FB7C6ULL, 0x6182B6FC7C96DA6EULL, 0xB4C287577C5E0328ULL
        }
    },
    {
        {
            0xEE7E8C3871BFF01CULL, 0x6F119524B5B4A239ULL, 0x2F452A27CD0F34C2ULL, 0x85C6FF99BFB8FE18ULL, 
            0x164F6DF17CCD9819ULL, 0x0339FE6C2DBEBE4CULL, 0x8D26A527D691E06AULL, 0xC05C8BB2E78671C9ULL, 
            0x1400B837C8604032ULL, 0xC770CD2E4F0C28D1ULL, 0xD5558BC2E1AB04F2ULL, 0x1DB766242E628EA2ULL, 
            0x68913048485A78F1ULL, 0xFD44234B45B185F4ULL, 0x67D13D37BCCA8ACCULL, 0x743A3AF82053F1F0ULL, 
            0xDF9201BAC17E9A43ULL, 0x3EB273595A701E1AULL, 0xB1A81599E72F9C44ULL, 0xC0FF1BD0E2A8934AULL, 
            0x8896D582EAF01100ULL, 0x0FECB0909EC6D96DULL, 0xEB1703305C5AAD4CULL, 0x1A449124AFD990DCULL, 
            0x628BC6A15C2F77A8ULL, 0x9121C859B5895FF9ULL, 0xA7CB230B23F10A54ULL, 0x9EFE6383BF7BC288ULL, 
            0xEED4D82097CA3D13ULL, 0x387FE178F8A09708ULL, 0x63905DBD5401CD31ULL, 0xB64ABDCD3B6CE499ULL
        },
        {
            0xF92C122E4BB1519DULL, 0xD8F61D38396E1A6DULL, 0xA41581F54F0DB8AEULL, 0x20D6A6639F00FA8EULL, 
            0xC0B44697E2351CAAULL, 0x8B3D3421F364A4F1ULL, 0xA64458C82F04F56BULL, 0x24E4CD2C5327967EULL, 
            0xBCAF0EAB494EAF16ULL, 0x23775D4AC91F6A20ULL, 0x8A4C33E8FAB310F6ULL, 0x1DCF612B486340BFULL, 
            0x5AA9BBC6520FCC41ULL, 0x52E06CFC3A916DC6ULL, 0xF015F06A139DB4F9ULL, 0x2DCEDC03592A5ADEULL, 
            0x9AD7162412C4B9A6ULL, 0x7117961E870E8CD8ULL, 0xD1385B832C99E736ULL, 0x9504308DB1C1053CULL, 
            0x99BA6C428E736F61ULL, 0x59E450518C874BFCULL, 0x6F96F16510D1663FULL, 0xACA690D8EB5F60AAULL, 
            0x2F0A340755ABAFC6ULL, 0x2A51E08A4B53849FULL, 0x7B8A149BE011E52AULL, 0x2FE5DB77FB7EF53DULL, 
            0x89CC0A4B894EE325ULL, 0xE21BD675BF88D607ULL, 0x0238B9225ABB5088ULL, 0xE8543A76B9836F8DULL
        },
        {
            0xBA1DBC954E4DDA33ULL, 0x3AA19355BB3B99B1ULL, 0xC1DE07F6ADE971EDULL, 0x7225EB448178F998ULL, 
            0x340558FD02B8CCF2ULL, 0xA2634E55A1C1F56EULL, 0x1D49F564C596092AULL, 0x2A452A4DBE0EC5E4ULL, 
            0xFC6CD8A5C8405368ULL, 0x778F867A7058BBFFULL, 0x91BC43ABA09B1C5CULL, 0xD9297FF67742FBC3ULL, 
            0x17D27741076F2831ULL, 0x101B1C86EB58218CULL, 0x234F0E516118B954ULL, 0x0B25E4239B481651ULL, 
            0x78372253519E900CULL, 0xB9D2FBC3C0F91E33ULL, 0xB6B111B5D7463023ULL, 0xF3821D3A6D53C050ULL, 
            0x41C3095C8AA24707ULL, 0xA55871DE9C0E5BE0ULL, 0x17A961EB5475CD7EULL, 0x17360212F8387349ULL, 
            0x66A7F861D054CD13ULL, 0xACE92195088A977CULL, 0x26A832C769EAD139ULL, 0x9227A926ADBA7C6BULL, 
            0x955B592981FED5FAULL, 0x576187E8116C4932ULL, 0x713562D446390582ULL, 0xC888F5E1258013B7ULL
        },
        {
            0x49BCBC23E1773C06ULL, 0x64D35BE0783C48C6ULL, 0x8004000A1E1CC460ULL, 0x8293239730770B5BULL, 
            0xF46C10155822BF76ULL, 0x060FC43F3A3026B8ULL, 0xF29864D9DE2D0FA3ULL, 0x2EF23A3B7AFFE396ULL, 
            0xC807550E77BCFCB0ULL, 0x36C3E7D8C8D0650EULL, 0xF2962E68BAA8D70CULL, 0x496E113135045ADBULL, 
            0xBDE5FFEAB28FB5DEULL, 0xD026450510865E75ULL, 0x4ED463DDC65B48FFULL, 0x714CFF99CEED652BULL, 
            0x45402ECD1B2CD2E8ULL, 0xEE660447479AF0CFULL, 0x3EA57A0722E6004AULL, 0x23FE14E0C8211CD3ULL, 
            0x709FCE55D9906C6CULL, 0x7B3D7E1EE9C11D09ULL, 0xD17ECCCCF5D6ECABULL, 0x09D88D21F918A593ULL, 
            0x3DFCB395894A4BD0ULL, 0x1064321572D82926ULL, 0xB3EB5D093DAD2BF0ULL, 0x627177A2347F23CCULL, 
            0x8D401E43F12D4BC9ULL, 0xCA04E944DDD5F62FULL, 0xC90D6B3AC68CD5ECULL, 0x9C3508A5EA895CCCULL
        },
        {
            0x619C0BDEE583F235ULL, 0x7357BB733389C8CEULL, 0x1E64F520024EF4F9ULL, 0xCE4E27D9054F7EE5ULL, 
            0x87B5F2109266C418ULL, 0xE34FDB1B6EABECE0ULL, 0xB90582966B5132BFULL, 0xDCA09F29380F5E42ULL, 
            0x5A566A5983A0AC08ULL, 0x8E4FFBA48C947E4CULL, 0xFCC20286E8E67EFBULL, 0x695089D6C545F00EULL, 
            0x7C184D6D96B7F03AULL, 0x3063FD66BF36997EULL, 0x3756D8E4D77DD1DDULL, 0xC5EA9D737D743D66ULL, 
            0x6DDC59ED020160E3ULL, 0x3681A6DC9ADF258AULL, 0x4346EBD84B167D17ULL, 0x90ACB845F5B7FFC4ULL, 
            0x66EF018BF27DBDE1ULL, 0xD8CA9ABA551E3CE1ULL, 0x2B08B20C801DA26EULL, 0xFE129E58F7ACD2D3ULL, 
            0x07CFC541AD6F697AULL, 0x6AC5F1A528BDA8F0ULL, 0x0398EA171464ECA1ULL, 0x843B8A79043D6800ULL, 
            0x108C9610B2053E67ULL, 0xD6210E16CF27C8FDULL, 0xBEB388F39DA092C9ULL, 0x2AF25261BF7664E3ULL
        },
        {
            0x860028B64189778EULL, 0xDC7D5FFC653D46AFULL, 0xD77CC34E0B33EBD5ULL, 0x545C83AA8F897E92ULL, 
            0x5A0D1520DCF69DF9ULL, 0x5BC5367CAB53D2D0ULL, 0x064A564821BF66FCULL, 0x2FACAD130DAFC461ULL, 
            0x91F714A666B986B0ULL, 0x3D8054872CFE0D4DULL, 0x3DA52E31336E4052ULL, 0xD1396D8A05DDF176ULL, 
            0x346EA0CED97EFFE7ULL, 0x67380CCDC0B3E659ULL, 0x81AE9F28BE2702E9ULL, 0x23B6A0E5B2F78D43ULL, 
            0xC554AD1C17EEB6E5ULL, 0xE94E05654FFE988CULL, 0x8D3D5A4B6B289A14ULL, 0xC753F6E8794D6807ULL, 
            0xE160CBEABD4AA116ULL, 0x84C71AA1254247C0ULL, 0x06D78FF2A04824A5ULL, 0xA5D1BE2804B12C88ULL, 
            0xE7B43F1FFC9E5A6DULL, 0x70FD5A3AE74226DBULL, 0xE69E727C37E026F3ULL, 0xF304F35C3B0C7F52ULL, 
            0xD9F5A68EB2BE57BBULL, 0xD5E47BF22191D36CULL, 0xA17514B6D7CE58B4ULL, 0x627C8BB54B78ABE8ULL
        }
    },
    {
        {
            0xAC662850BA6FF613ULL, 0xFEECCED38CA09840ULL, 0x104FDD703ADA2F5EULL, 0x20B0A3780DF4C312ULL, 
            0xA3BE5B3D7C858BAEULL, 0xB45900E5EDC77A98ULL, 0xE16563DB3E0957ADULL, 0xB701906B9AED3A50ULL, 
            0x8D091AC9F833EEDBULL, 0x7523864FF9B62467ULL, 0x55F6E54AC80D1705ULL, 0x983CC3FD41BAD20CULL, 
            0x08AD661E74C7730DULL, 0x234A225E938BB2C4ULL, 0x08B23FCBDE182315ULL, 0x6A619BCB0C86A936ULL, 
            0x7A461EE8B4A3237DULL, 0x4D5DD90DA7BDFF49ULL, 0x9B95F2D6844FCFEAULL, 0xA17FE7137E90A0B0ULL, 
            0x1CACFF5CE4E12518ULL, 0xAF991D69C571D615ULL, 0xA6C6913F9F94A2C2ULL, 0x4605BB0A64AA29ACULL, 
            0xA7CCB808ED4D55FBULL, 0x89FEA316D54C9F31ULL, 0x9F3808BBBDD1C131ULL, 0x7EE272F035F8C842ULL, 
            0x8F8F3B801C9DF1BBULL, 0xE65CE1A3968B4375ULL, 0xB20F471F2AB1B6C8ULL, 0xD2C446AF93036A8BULL
        },
        {
            0x03A1F99E35A15C61ULL, 0x862D299C178F6CD7ULL, 0x93A7FA1F7E23C2A8ULL, 0x0E4EC5E2B05A971DULL, 
            0x6501F01CD34EDA15ULL, 0xDE595D235CEE438EULL, 0xBC23CA9DB3FDF040ULL, 0x4EB653DD618E00A1ULL, 
            0x55E0C6B691F0870AULL, 0x23C09E586BD6ADC9ULL, 0xC7950422E4EB719EULL, 0xD829E951DDF42A06ULL, 
            0x4CC087CFBA6C261DULL, 0x5A59D80F3CD64A4AULL, 0xA95DEBD10AE18340ULL, 0x32093198D80337EEULL, 
            0x3B0556EE32426F33ULL, 0x8FD321C568EC28AEULL, 0xD64BE25F0F194F01ULL, 0x77658CBDDBEA71B5ULL, 
            0xE144CC8A48962698ULL, 0xAF49491BEE3C35CEULL, 0x4C6926E78D90D3D5ULL, 0x00EBBBDE5168207EULL, 
            0xAC5DF742CF9669DEULL, 0x29904AA7B8FCA68BULL, 0xF7BBA4081A5995B9ULL, 0xC4789E1132D3BB51ULL, 
            0x38BE4E484F9AE36EULL, 0x5A01EF33A791836BULL, 0xCBB6838C281CA51BULL, 0x12D0D42BC1D44DFBULL
        },
        {
            0x2F1ADA35E70FDB80ULL, 0x304711126F51E024ULL, 0xE9D1B2DE153BEC7EULL, 0x8E1888F3D93F9A6AULL, 
            0x1AC46A7B1EC7F35BULL, 0x3FF15470001F5FD4ULL, 0xBD909E68CA8FEEC6ULL, 0x101850432B47059DULL, 
            0x928947FCE38BF7CBULL, 0xD47B52458594BE60ULL, 0x0C254FA3AB4F05C4ULL, 0x7C04D12622D963F3ULL, 
            0x19EEC319B6D1DD70ULL, 0x0B1B8E68817DFA09ULL, 0x4DD5C3062476800EULL, 0xC908657EE71207EBULL, 
            0xB145F6DB15DAA82EULL, 0x391BCBACD5B45877ULL, 0x1E7E5E74C5602540ULL, 0x2F28F6F12DDE1383ULL, 
            0x71FDE55134568C9FULL, 0xE42FDF560ED4F2FEULL, 0x7345332EF4F273FFULL, 0xA14CFC957356CC0AULL, 
            0x5BF2CC7673973C87ULL, 0x0F16833D3FE5D6F5ULL, 0x2D91F5D7714051E1ULL, 0x51FD98C93A5D60F6ULL, 
            0x88368247A6019F7EULL, 0xC7948EA4B5FF7F66ULL, 0x10E1D4FAAE6CF049ULL, 0xE8A05F1648D54C5AULL
        },
        {
            0x17E3720CBCFA8AEBULL, 0x64E355A95F96000AULL, 0xC08C48863E800470ULL, 0xBC0C13FBC3F259D7ULL, 
            0x58D6C4D5110126ACULL, 0xC9F07751E492CCA1ULL, 0xFB4DC7D14A4C0D2DULL, 0x1A05B1CD98C088A7ULL, 
            0x6A1D0242D72A0F66ULL, 0x58C63A2F4824535DULL, 0xC6F8DE1453DF42CDULL, 0x3884215EAD9943D7ULL, 
            0xF97693E4DEB277DDULL, 0x3D74D5654943B579ULL, 0xACA36AF741A49295ULL, 0xA80DA8256D4F126EULL, 
            0xA022CFE6856A4967ULL, 0x73FDEE2D525C0EE9ULL, 0x44C1A026C765E431ULL, 0x07B50DC02067F191ULL, 
            0xBEE518E1E3DEA41EULL, 0x0CFA2D01059C7834ULL, 0xE6628C7558BC43ABULL, 0xBBF192A1073A461AULL, 
            0x06A052A84D695958ULL, 0x50F54AA0E7553652ULL, 0x773E25817B8EAE94ULL, 0x2DA722B4CEA4FA3DULL, 
            0xFD8AFC8D0A71D97CULL, 0x540D10AF1FC4827BULL, 0x337111764F141C19ULL, 0x894E6C83379D3ABDULL
        },
        {
            0x34108E71E9E8ADB5ULL, 0xFA8DA731AACB6B03ULL, 0x1D22CB329E7CDA54ULL, 0x177EA056DFC00F04ULL, 
            0x2AF24167880E378AULL, 0x5327EA383AF25435ULL, 0x6984378F52097EE2ULL, 0xE47FE9B8EB172023ULL, 
            0xA7CDAF806CF54C93ULL, 0x4F3218BF6CDFAFABULL, 0xFB70C994423D7421ULL, 0x7BF7E693AE2AB8FCULL, 
            0xCB3601E4AAA43795ULL, 0x20E48EAF0CA68F60ULL, 0x9E664EA6224BE421ULL, 0x6F49844A6FA89964ULL, 
            0xC5DD5C88645C9439ULL, 0x0C918CC66B1DC15BULL, 0xB9E6B08020C518C5ULL, 0x7BC22E2451FF4629ULL, 
            0xAF80D9783401E218ULL, 0x70000F4B64D6087CULL, 0x3DA0F039AB5E55A7ULL, 0x4120F7FE68D76189ULL, 
            0x2E9BA6BBE9B224F7ULL, 0xC1F9376CDD8C8AEAULL, 0x02839F454F67F77BULL, 0x2FFB805E92B20B98ULL, 
            0xB09D34BFF8E3E691ULL, 0x13C7B402B28F01A4ULL, 0x676EC778FB5EDD00ULL, 0x77633990264EC4BDULL
        },
        {
            0xB8A41D069189B39DULL, 0xE9A51C169BBC0070ULL, 0x3D1530DC0BA72B1AULL, 0x5246E96168F90465ULL, 
            0x1233073099D083FAULL, 0xC89BC60941A744AEULL, 0x1AD2A28DC1E2A541ULL, 0xA476411B1D5873BAULL, 
            0x02412FAE86B5501CULL, 0x9AB92E95432DBC8BULL, 0x5D4A210A38B5F324ULL, 0xF40C6CEF09E72271ULL, 
            0x181D76C15CD4E628ULL, 0x1F6C8F7FE7417388ULL, 0x1F2E2486873E4C31ULL, 0xFD4F2FAB5D3A17A5ULL, 
            0x07A6D7F892D480C1ULL, 0x484C40C1598F61FFULL, 0xE221DA238BF5B55CULL, 0x06FFF8CB4C63680CULL, 
            0x5686DA6FCA61D471ULL, 0x8CDA63944D11C785ULL, 0x7CE58B335D1EDB67ULL, 0x93A88BCCF77787B7ULL, 
            0x707B374BE7344440ULL, 0xF4822E5A1E30230BULL, 0xA1701F2538395A49ULL, 0xC27EFFA9DED2A0D0ULL, 
            0xB1F080008028F193ULL, 0x750434BC6FD4EE78ULL, 0xA2D9625D80668106ULL, 0xE9B4E93F9A7A6857ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kSeedConstants = {
    0xCC7502C29E0CC721ULL,
    0x3A14A88281AC70DFULL,
    0x84219DAA74E07A0AULL,
    0xCC7502C29E0CC721ULL,
    0x3A14A88281AC70DFULL,
    0x84219DAA74E07A0AULL,
    0xC7C29194B50E7594ULL,
    0x15B25F3089A0853EULL,
    0x9D,
    0x77,
    0x0C,
    0x1E,
    0x30,
    0x90,
    0xD9,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Mothallah::kTwistSalts = {
    {
        {
            0xC8F535F7B8BC9B4CULL, 0x5D5A3D4ECD3A726DULL, 0x1B1A94169770C5A9ULL, 0x4F4FEA9488317535ULL, 
            0x894917BF85E6DCB5ULL, 0x7466E3ABE055B90DULL, 0xEBA94798E6D64198ULL, 0x51EB7120238E820BULL, 
            0xD920B301BD984FDFULL, 0x8CCB8B884CB6A482ULL, 0x405341E101588B2EULL, 0x3282BDF00AB57F52ULL, 
            0xF7C69D1604C47F3EULL, 0xC0CD800B52B02990ULL, 0x0F7BECBB474C6583ULL, 0x8EADA21C5D0B4CCBULL, 
            0xD91A60010FD47B94ULL, 0x961950707D108FB8ULL, 0xE9F25847EF801D7FULL, 0x32F60DF635081071ULL, 
            0x8E9F625C5DA1F014ULL, 0x8BCB4E4E66B3E64AULL, 0x2B41714BA358A9B8ULL, 0x97FDA58E438EA62AULL, 
            0xAD012BD1EAE12CDDULL, 0xECD1B0DACD290358ULL, 0x6FCC6FB1B56EA1DFULL, 0x2E92089C00A97ACCULL, 
            0xF5F42E3480CA703BULL, 0xF11316D5D82C8E3AULL, 0x1C0766CFB79A3B82ULL, 0xB3DCC6D9D1F00C69ULL
        },
        {
            0x24875FDA05031FCFULL, 0xCF0FECEA12004DDBULL, 0x1676D54EA4F342A1ULL, 0x06CE3AA3E2E0BFC5ULL, 
            0xBC691E94FE88275EULL, 0x33EEAE7F24B47D0EULL, 0x2A3B3B26C9254727ULL, 0xDB5E1A6F2C8A09EDULL, 
            0x8CD63382AA38675DULL, 0xCA48F523EA334436ULL, 0x289D4FEB003B4B3AULL, 0xCAB285B51237B497ULL, 
            0x4A79C554F42A83ABULL, 0x48D7FB4774FC2677ULL, 0x573095489103FD8DULL, 0x9E06914110C7E3FBULL, 
            0xC032D0BA64C6EB02ULL, 0xCE5B60A26A57AA89ULL, 0x71F6DAF803308B5CULL, 0x2AF147783F574030ULL, 
            0x3EB0430ACEA6EE5BULL, 0x395A4A0DA2EE6775ULL, 0x06E91187867865B4ULL, 0xB5D986B28C1E2E91ULL, 
            0xD16335015377D1E0ULL, 0xB3AFBA7D8B09557DULL, 0xC7CA1DA2DA2E7A4AULL, 0x2559941E65D5CA95ULL, 
            0x49F53ACA2F1AD76EULL, 0x3FF4F2DF97F54BFEULL, 0x42E585713F490CF8ULL, 0xFB54D68F60755C4BULL
        },
        {
            0xAC0C65A6BC37A7BEULL, 0x1D548A72E5210152ULL, 0xBFD3B76EA629B300ULL, 0xDAEB6040B16B633DULL, 
            0xB698E625A12AB765ULL, 0x3C2329D66047DC0AULL, 0x943B5AB632ADE016ULL, 0xED60B841AC45A16BULL, 
            0xEB66259C804C7935ULL, 0x002D6746B5AA6065ULL, 0x8D7AB57EBF5EA70FULL, 0xD37C1BE6E47193B0ULL, 
            0xAF43095C415DD4E4ULL, 0x79458DF839709D47ULL, 0x7DA23CB5E1E0B632ULL, 0xF5EA086AD1435A36ULL, 
            0x9FABC49628292104ULL, 0xC8BC1E149DC39DA8ULL, 0x1E9156DB7D243C6EULL, 0xE395AA0245A3541CULL, 
            0xA71A0EF5F8BB28A0ULL, 0x6DCE36FC27A11A64ULL, 0x98E90453ECE8E53CULL, 0x39D0918DB35BCB5EULL, 
            0x696D1A830104B4FDULL, 0xDF8D5C8F9DCA625AULL, 0x698DC18FADF9DC98ULL, 0x31D4F1E08603A1FDULL, 
            0x164988E98AC48F80ULL, 0x6409249CA5AA6C99ULL, 0x73CF16CF6F3EDB7CULL, 0x99A02B73CD265FFEULL
        },
        {
            0x609685419A6D2152ULL, 0xE298D592BC4A52EDULL, 0x76219B74B0E81325ULL, 0xAA45DFC3A5842B3EULL, 
            0xF72A4107C955C942ULL, 0x813B88B1AB7B27C0ULL, 0x878E944504D03D80ULL, 0x7B3E7124457E98EAULL, 
            0x0C33FC4CE1E31DBEULL, 0xCFA3EA45513D6643ULL, 0x73863E002F6CE331ULL, 0xBD7F3B7727091E51ULL, 
            0x90F95A86CE8EE752ULL, 0x36FED846113DE658ULL, 0x537A8DF85A8E536AULL, 0xFE6DB8DBDC97ABF9ULL, 
            0x75AE458EC15C481EULL, 0x52E21918566136F7ULL, 0xE86BAA66CA745474ULL, 0xB39C67E0F8B5C1FBULL, 
            0x68B1B593D4874BB6ULL, 0x1F06A195190512CAULL, 0x2D5BC51D8B0E4236ULL, 0x481D540092A7AB5AULL, 
            0xCF40A3AA945020CFULL, 0x9ED457630F39D5F6ULL, 0x77723FE2626C147FULL, 0xE56732E194AA8809ULL, 
            0xD94267DE6E3B3E97ULL, 0x8A7CB90BFD7DFA54ULL, 0x80211429BB9DFC1EULL, 0xDEFEC44948F0603EULL
        },
        {
            0x7BF8DDBDE7A3F049ULL, 0xFE1A144020C79836ULL, 0xE5D7A23BBF0CABB5ULL, 0x3762413C555B4007ULL, 
            0xEA76DFD2FEF490BFULL, 0xDCCEDF1EBCAD797BULL, 0xD2E5247A00C9F2E6ULL, 0xC73CA12B32721DE5ULL, 
            0xC6EE5CDF9FCA0A59ULL, 0xC01A002D5EFABE35ULL, 0x63D33156805878FBULL, 0x56173FE8641DE168ULL, 
            0x2FE94E8900DCA12EULL, 0x02344A4225CC87C8ULL, 0x62F00942ACCAC81FULL, 0xF37A8CE3AF1A1F21ULL, 
            0x988E0634C5139294ULL, 0x3DCE3685228F4168ULL, 0x66A9ACAB394F6312ULL, 0x01C4C0D11375D8FCULL, 
            0x76F9DD1128BE3D42ULL, 0xC97BA25D2C45C70DULL, 0xB7CAE86413C29205ULL, 0xB2DCAB577BA55D9FULL, 
            0x1A46C4F86A9135E5ULL, 0x8EFE5D14B9C7D71DULL, 0x782D0064570B90FAULL, 0x44CD78D954B95CFEULL, 
            0x39E3D59E4374BD6CULL, 0xFE55B7025160A878ULL, 0xC2EF19DAA6BC24DEULL, 0xF19A71B41A1E7CF5ULL
        },
        {
            0x2525CDAEDBC68985ULL, 0x358AC9955BB246FCULL, 0x50A36A68C0C82078ULL, 0xE575D2CDC0104499ULL, 
            0x7C6571DF38CA3191ULL, 0x2B72C877CAF8900EULL, 0xDAE25B95D2C5FF1AULL, 0x9BCF347F0C968B3DULL, 
            0xA0747F934689C2A5ULL, 0xC0A4C126BF30B5A4ULL, 0xDC444AFDBBCAF79CULL, 0xA4E16747B610D062ULL, 
            0xBE374761DC516A04ULL, 0xE8EC06FA41844368ULL, 0x14D43C3D0FDCD1D5ULL, 0x0FBC5BF9D9F72A29ULL, 
            0xED6E589452C23BFDULL, 0x429A7B9CEC99293AULL, 0xE496549570DAF861ULL, 0x34FB83BB525AD314ULL, 
            0xD0C98BBDF8C9246AULL, 0x7C87DDFAF356F87EULL, 0x9DE528A90B4FCED4ULL, 0x524398BAB4E136D5ULL, 
            0x8FB2DBE8EFC0D00AULL, 0xA01FCC8DFE434EDEULL, 0xB70E3C217D29BBD3ULL, 0xF0D2ABFB3FF4DDA7ULL, 
            0xBDD548B7AFD600B2ULL, 0x5E8F7BE63234D8F1ULL, 0xEEDDF168ED24F49BULL, 0x602995116578C4E8ULL
        }
    },
    {
        {
            0x89324B29300146A9ULL, 0x4E8279565D303AD5ULL, 0x2A92B8FAE93E774FULL, 0xF832B96D6D050713ULL, 
            0xF8E29D7D0246AF5EULL, 0x1FD5D176AB1A37C0ULL, 0x6694E22561B3D639ULL, 0x52D53ABF4D463DF9ULL, 
            0xE6DCFCE76FF7DB51ULL, 0x0D71CAD2C58EE772ULL, 0xD9651C3B2AB6A827ULL, 0x77F84A7C08C62C08ULL, 
            0x0926B841FAE25DD3ULL, 0x1060644AEBEFB223ULL, 0xA4A5CF79357E1572ULL, 0x368D9B594F8E64A5ULL, 
            0x6DD5F94E7F7BA2ADULL, 0xD99883B4A6C251F4ULL, 0xA7D69E9098C53AC0ULL, 0x02F28987867E25F8ULL, 
            0x678882093E2CD3A6ULL, 0x9D50A15DFE9511B7ULL, 0x45298D512CCEC373ULL, 0x111AFE3D831BD00AULL, 
            0xEFE8EF0CAC4773C0ULL, 0x42F9CEB9DCEECCCAULL, 0x7F922F573F720808ULL, 0x27269D04D1FE684CULL, 
            0xD9AACC48E3776600ULL, 0x2E4179520D557530ULL, 0x97F2782CE8DDD269ULL, 0x204F0F8D0739F0FCULL
        },
        {
            0xFAE89953413B92A6ULL, 0x8F703821823913D1ULL, 0x6D115C3A8276AC27ULL, 0x078CED759ACE8699ULL, 
            0x43E70E10B49B96F4ULL, 0x6626A88515B8B8E1ULL, 0x80AD7281B6685D4DULL, 0x8C139FF01636D9E6ULL, 
            0x6F00A6CBCE02DF1AULL, 0x49D7776825D3E521ULL, 0xB201FF544743B582ULL, 0x3DFDEC496A03CF8CULL, 
            0xF82034E41502A6B5ULL, 0x91003C34995D82E0ULL, 0x450DA8C579B44AF8ULL, 0x2357585083DDA302ULL, 
            0x35C64FC4CBE3004DULL, 0xE3E92F4946E088BCULL, 0x085F905B052832C2ULL, 0xCB684EC997F6D86AULL, 
            0xC15203CE4E5095A2ULL, 0x3CEAFEAE162CED52ULL, 0x28ADF778FF6B3E66ULL, 0xB4D1286DCF8D2CE8ULL, 
            0x7B8FCE4F437C687EULL, 0xD5C1FA82A489514FULL, 0x2368661A80DD9516ULL, 0x5180BD7B5FDDF5A6ULL, 
            0xDF45CB1D585EA7E2ULL, 0x3521A4F3A68D80AFULL, 0x55824C5596B6A9BBULL, 0x6C6ACAFDFA74F8C8ULL
        },
        {
            0xC763FA888ADFF9A5ULL, 0x879383CA83A4137CULL, 0xE444383D21A438B0ULL, 0x737CEEA938BF27D5ULL, 
            0x470E9826CB5FE17CULL, 0xE491EC98D3AC904AULL, 0xD4DABC9264F286D2ULL, 0x524D24CD6F3E29B1ULL, 
            0xCF0BD21B4C67DD6CULL, 0xEDEFC2C72956A468ULL, 0x26EBDB93A3EB2B82ULL, 0x17DBA0FDA770F351ULL, 
            0xBBD578605404677EULL, 0xA112238D6EB75294ULL, 0x687DE219DD384D14ULL, 0xAF6C8409C6B1DC2EULL, 
            0x71B75A9577DAEC3CULL, 0x65F1D34E1BE711F8ULL, 0xD7A545B2DC79884FULL, 0xD26EC5F6B24CAB07ULL, 
            0xB88244CE09BCFA0AULL, 0xDE050FCF5DBF3854ULL, 0x517D68D9CD0B31B6ULL, 0xEC7BBEB9A11CFB26ULL, 
            0x94D02C7F8204F14EULL, 0xF033A5A37ADC2CB5ULL, 0x5B69F58EE32F88CDULL, 0x67206148FD65ED37ULL, 
            0xF629830BF7423FE4ULL, 0xB5A87328DCE78447ULL, 0xF53A494AD7E3815DULL, 0xE4E0BDD33465D29CULL
        },
        {
            0x78484CAA3CB16262ULL, 0xD92FE64F47D93266ULL, 0x5EE3D3F6A67D36BCULL, 0x65FAFC428682CE8AULL, 
            0x53AE5DAEDA95F97BULL, 0xB26BF8E6B95713BAULL, 0x369AC3F20F6812E5ULL, 0x1184D99968B6AA7EULL, 
            0x36882CFD84E89228ULL, 0xF8B3351F00D50C23ULL, 0xD0B091AA02BDEBBBULL, 0xDCE5D7A42984568FULL, 
            0x302676EE0D38DB39ULL, 0x1A78643A9444F3C4ULL, 0xD8D611B066052E37ULL, 0x025E4BB3141F50FBULL, 
            0xD4B9ED7AA8AE5C8EULL, 0xF6447F069788F29FULL, 0x8058B7010C8419FEULL, 0x9B2FC87B1B968FBFULL, 
            0xE4DB2DC64B316F1AULL, 0x5D8E7966996BED62ULL, 0xA50E96E88D853C24ULL, 0xD4A33E36613435B1ULL, 
            0xCE41697C14CF9ABAULL, 0x17A5A0078E8EC565ULL, 0xB6B6B397904D6C41ULL, 0x0BF1C0536849AD74ULL, 
            0xABDBACFFA5DAB7C1ULL, 0xDF050B3F49ACA4CEULL, 0x358BF879C3A46E69ULL, 0xA4AF6603484355ABULL
        },
        {
            0x647874C6646B847AULL, 0x3400C5F1D188B11EULL, 0x9739569D5C0C7CAEULL, 0x6DCFDDBA3AF55E44ULL, 
            0xC541D6EFCDEC919CULL, 0xE2B4A00E543417FDULL, 0x69F7684A93D9DF17ULL, 0xE25DB65594BF6218ULL, 
            0x48D0E77C78015E77ULL, 0x5F335A9E9BE118D2ULL, 0x72E5492A3ABDE2DBULL, 0xDC3334A6F5BA1A0DULL, 
            0x8F5C028C6148693BULL, 0xE8E5E78AEDA709F1ULL, 0x7701CCFF37B58C9AULL, 0x83325DEF61C55B0CULL, 
            0x8E4F7F4988C2D8ECULL, 0xAAFAF5D3DCA5AF48ULL, 0x4DB4EC43CC880F10ULL, 0xF6DBADAB255D450EULL, 
            0xACB51615B3C5CEDEULL, 0x60C45B3C41200E62ULL, 0x06522990ACFA13D2ULL, 0x837859938E38110EULL, 
            0x9F1ED2C51D4119F5ULL, 0xB79F122BC23A2540ULL, 0x66BAA86580849283ULL, 0xBEC49DEEA72ACFEBULL, 
            0x3C1698E72486EB36ULL, 0xC932AEE25E766B6FULL, 0x70EF48767B558735ULL, 0x61623962BD6D6B8EULL
        },
        {
            0x9882C2E2B8F7FE1CULL, 0xDA4F063222FC9338ULL, 0xCCC0C4FF56E89AF4ULL, 0x6DD5DA6057B5F5DDULL, 
            0x523CB25CA7303F97ULL, 0xC94951EC63EEB8F1ULL, 0xA271ADC4ECA8D115ULL, 0xBD08FACBDA9FF35BULL, 
            0x355F53E1409ED228ULL, 0xF38C8DCF15C962C7ULL, 0x1BB39A2D8093BFF0ULL, 0x5710247567069145ULL, 
            0xAB88C0556500AA73ULL, 0x4F91A090CC55C002ULL, 0xE1742D575C0FF058ULL, 0xC3E1EE7D3D0DC9AAULL, 
            0xB55110ACEA213066ULL, 0x7D37352AE3BBDB98ULL, 0x03AF66F962A6C60FULL, 0x26B0414DB7747041ULL, 
            0x547D7ABF3F2615BFULL, 0xCB8CC0BEE5ACD410ULL, 0x200D9E32408AEF64ULL, 0x5E7BA073102C9350ULL, 
            0x14333FE864C64729ULL, 0x05082FDA083B2035ULL, 0xD815897E9FD7E01FULL, 0xC756138E4D60F914ULL, 
            0x79B934CF9F5CD6CBULL, 0xFF71EB9D73A2623FULL, 0x7ED3A31524D313F7ULL, 0x23C453F20ADFF7ACULL
        }
    },
    {
        {
            0x4E6FB5DC4FE547CFULL, 0xC2E5BE905BAD6DFDULL, 0x4690969C407E8658ULL, 0x0EF13FA2B6A6730CULL, 
            0x94FE8AE50A92CED5ULL, 0x25883E07C0D35A73ULL, 0x93D427AAF9163731ULL, 0xF783B37E206DA72EULL, 
            0x8321301F3AC45C52ULL, 0x94A7B3659AD0E4A4ULL, 0x028B5FDA0316A857ULL, 0x9D234A6BEAE0C541ULL, 
            0xBF28C72D6DFBA9FFULL, 0x8FCBEA1137F45DD0ULL, 0xC0EFAD5D7E0FDCB7ULL, 0xBF54CC231C0912F3ULL, 
            0xA5755EE67E917A32ULL, 0x369DABFD277B17A9ULL, 0x487862781E7DFED4ULL, 0x83C9293774A493ADULL, 
            0x1FFD36AC024011ECULL, 0x7FF121050712D7A2ULL, 0x584319099AA9B317ULL, 0xACC258E88193EE83ULL, 
            0x48F4A22E73A84C1EULL, 0x935CB6A3E243FBDBULL, 0xD47ED3E7B3739B7FULL, 0x92F5B62E06619FA8ULL, 
            0x290FBF407CA4FD91ULL, 0x9DCEE25C81A28D1FULL, 0x5F15CE25E2BABCFAULL, 0x50459F6FFB6DF68DULL
        },
        {
            0x74D984676882B37AULL, 0x33B9349C58BB8892ULL, 0x7A9E329614C83671ULL, 0xB152788204AE6AF2ULL, 
            0xA46F7F59B8FFA358ULL, 0xD737C0675EA3F123ULL, 0x3C0B6D94B93F246EULL, 0xBCD77B4872E2FB53ULL, 
            0x1834F7BB6E6A98F5ULL, 0x83F8D7CF907C6CECULL, 0x02445ECBDC0ADB3EULL, 0x273978D6C9295884ULL, 
            0xCC161DB54EA6C264ULL, 0x91A9CAC9EF72224BULL, 0x35B168943BA9DBDDULL, 0xA3D1AFA9EDB52AAEULL, 
            0xF8AB8720C18D9844ULL, 0x82020470A95AE3FDULL, 0x3FA4123F15F2771BULL, 0x09D5D599B678AD4FULL, 
            0x12AE138DFBC4E338ULL, 0xF01908D362C554DFULL, 0x528A338D58641F08ULL, 0x65A640D553577F49ULL, 
            0x55370FC2BDEF9031ULL, 0x15D988E71CFDC2EEULL, 0x8F0BBC699A2B481FULL, 0xDDB5640DC47C31CFULL, 
            0x5AF99D28862F673EULL, 0x05EB56561ED193F1ULL, 0xAC5C89174DD8E97DULL, 0x8A707EC16A80D788ULL
        },
        {
            0xCA7CF570CDF7ED7AULL, 0xF8532DD518FDA11DULL, 0x3139B28B859AB2A3ULL, 0x03D84595F60AFDC1ULL, 
            0xB9F26379484A4F3DULL, 0xF561C42320B649B3ULL, 0x3F39DAFDF97923E5ULL, 0x368016DDD8B01130ULL, 
            0x0B6044A9B0DDABA5ULL, 0xE9F47F090C490A02ULL, 0x987A2A638EB371EFULL, 0x84DBCA870463A880ULL, 
            0x4EBA5E071F491CA5ULL, 0x08A7AFCAC407AAD0ULL, 0x0474CC37BF96666EULL, 0x1B62265BB5ECB293ULL, 
            0x4A0352F1EB163592ULL, 0xA042FA17FB647AA6ULL, 0x930275752FD746F4ULL, 0xFDA8FC29EC036B77ULL, 
            0x74331A9B9514E1B7ULL, 0xFAAEF2ED2C86FFB6ULL, 0x5775BC3F9BC3B585ULL, 0xDC2058BE6428FCD6ULL, 
            0x1C4FB4D770887020ULL, 0x85781356F1DEAE2CULL, 0x018BEA78B0FD5016ULL, 0x156B11351D623219ULL, 
            0x74C939FB0375DDFFULL, 0x5D898733C8164863ULL, 0x25CCFE88D23D60F3ULL, 0xAB23A3C4DE515665ULL
        },
        {
            0xD573601934589B52ULL, 0xD40FF961ED00302DULL, 0x8864E2C557C58963ULL, 0xDD0B0510AE1ED373ULL, 
            0xC95F604E5656E5D5ULL, 0xDA0DC5737A02BEDBULL, 0x8428135D7EEEB4B0ULL, 0xE803388023C57070ULL, 
            0x045BD21116BFE623ULL, 0x8C12A334EB97ECD2ULL, 0x17A2DEC24D8E3D7FULL, 0x1227328864F7D354ULL, 
            0x2A565B69F228B0D3ULL, 0x1CEC8A2A216EDF0FULL, 0xB147A5F80D103FE5ULL, 0x14429767FE520020ULL, 
            0x56349E3295933CCCULL, 0x199E240088946199ULL, 0xEF0E24C4561267CAULL, 0x36F7B08B9E214D5CULL, 
            0x5DE0FDE17DB41E6EULL, 0xBE0A170A77FA5BEDULL, 0xC8C17C024329EA11ULL, 0x1E322278AA69FBE3ULL, 
            0xF856538677BA97FDULL, 0xFCE549C164C63AEAULL, 0xE7B5D59CC05E1899ULL, 0x1B66DBD05BD2B532ULL, 
            0xCD44357D9C4FA4C1ULL, 0x70541D3EBB9B0588ULL, 0x722C1F5D5FF52BE2ULL, 0x7DD6B6B94617C779ULL
        },
        {
            0x11F39C3D00AFF084ULL, 0xFED5205F8C3D3A0BULL, 0xB59086892B6E29CAULL, 0x0A800E268C4E049BULL, 
            0xB9A4952952E5BB42ULL, 0x226E0BF85107472DULL, 0x6F585EB4E6F00F72ULL, 0x6CE25797F7A42675ULL, 
            0x234BABD0D606079AULL, 0x48D7264928FA3379ULL, 0x9DB1412F7373832FULL, 0xBAFFEE1135221F71ULL, 
            0x1E206B6CB855ACB6ULL, 0x07FE88511CD3861FULL, 0x63ED8C303193EF91ULL, 0x2985E529E1CCCC5AULL, 
            0x98423DCC95F2BE13ULL, 0x474D9C69D0BB64E9ULL, 0x894123A5551E4C80ULL, 0xC614E10BABB72874ULL, 
            0xFBF4EB4350BF66EDULL, 0xE5857E548B5185DCULL, 0x8BBBF07E4AA5424DULL, 0x010D50F01DEBF5B7ULL, 
            0x88E0799C0D9A254EULL, 0x7CA01E9636B2FB50ULL, 0xAA0988FE6897A446ULL, 0x2E256E303B8E3EF0ULL, 
            0x83CC59B21768EB86ULL, 0x1225606DCC292C53ULL, 0x242DB11E5245CE6EULL, 0xE174BED37285A6A3ULL
        },
        {
            0x0458510ED3E8F73BULL, 0x217425F8240B4FD5ULL, 0xD3315C5E345DC34BULL, 0x75384D481AB1CCDDULL, 
            0x0B6794ED3CC73FDBULL, 0x8A9F22DCF00A5C1BULL, 0x7AB6E2D82CC85F7FULL, 0xC2EE40567E60C840ULL, 
            0x9077A64731A7410EULL, 0xF606443A17FE0A9FULL, 0xE80F0A8E696CEECDULL, 0xA0151B3C1BD50F70ULL, 
            0xDFCEC6FAA603184CULL, 0x0D9A412B4E9ECAD7ULL, 0x40B6C43F5455BB18ULL, 0x800FB980E24D995FULL, 
            0xFA56B996833CDE68ULL, 0xDF37AC341F91F5B8ULL, 0xAC566FDE3D02C3E7ULL, 0x98FBD12C741A94C3ULL, 
            0x0AE741A59F2BEDFFULL, 0xEC5BDFF6E822780CULL, 0x6960D34382250F5EULL, 0xF66F953B0149AF3BULL, 
            0x5EC973DFC27A90B7ULL, 0xCE57D0092C674BD8ULL, 0x08070305EA7C0D21ULL, 0x39F477B37C27FEC2ULL, 
            0xEFD82C8A37718B3DULL, 0xA6DCCF17A99AB73BULL, 0x3764B79E5FA07898ULL, 0x74F794DF4F089EF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kTwistConstants = {
    0x488F8697909022CEULL,
    0xACE8D5C2179CFD95ULL,
    0xCEB25BA72ED898F2ULL,
    0x488F8697909022CEULL,
    0xACE8D5C2179CFD95ULL,
    0xCEB25BA72ED898F2ULL,
    0xA1BF7613E12620DFULL,
    0x5232D4423D230DABULL,
    0x28,
    0x5C,
    0xBA,
    0x44,
    0x20,
    0xCD,
    0x3A,
    0xFA
};

