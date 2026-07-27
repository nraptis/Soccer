#include "TwistExpander_Rigel.hpp"
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

TwistExpander_Rigel::TwistExpander_Rigel()
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

void TwistExpander_Rigel::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD71CC7DDA4B266A9ULL; std::uint64_t aIngress = 0x97FE925C9492C888ULL; std::uint64_t aCarry = 0xFC81D2669D0A1E7EULL;

    std::uint64_t aWandererA = 0xFFA9DCBFD6D59F7BULL; std::uint64_t aWandererB = 0xA81264DFA3818E01ULL; std::uint64_t aWandererC = 0xD9BBF7EFF8F1D2EBULL; std::uint64_t aWandererD = 0x8F1B4AB16854665EULL;
    std::uint64_t aWandererE = 0x9DD8F1CE43B89A73ULL; std::uint64_t aWandererF = 0xA529DAA3ADE6D63FULL; std::uint64_t aWandererG = 0x9063F988EE37173DULL; std::uint64_t aWandererH = 0xAC42E142E28B1374ULL;
    std::uint64_t aWandererI = 0xCBF2703F48C6DCACULL; std::uint64_t aWandererJ = 0xACB64E76DE30D0A9ULL; std::uint64_t aWandererK = 0xB403A42A691C4895ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9BBB6F77559F2505ULL;
        aCarry = 0xEDAD226ABAAB9A33ULL;
        aWandererA = 0xDE31ECAEF974CCD6ULL;
        aWandererB = 0x8D8C7840D9B2E330ULL;
        aWandererC = 0xDCB1BBD0F1073B2BULL;
        aWandererD = 0xE27F71E205DCA872ULL;
        aWandererE = 0x996FC0AAB8454E6DULL;
        aWandererF = 0xE2E89D2AC3693AACULL;
        aWandererG = 0xD31AE5734B087336ULL;
        aWandererH = 0xAA0247D69493ABFFULL;
        aWandererI = 0xD8C06286BF83019AULL;
        aWandererJ = 0xE449EA9D0A285124ULL;
        aWandererK = 0xAA0FBB872E35493EULL;
    TwistExpander_Rigel_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC7914FAB60AAA366ULL; std::uint64_t aIngress = 0xAD55E6FC28E2BF58ULL; std::uint64_t aCarry = 0x9939D2D057E991D3ULL;

    std::uint64_t aWandererA = 0xBFB6FE5EC8C822A1ULL; std::uint64_t aWandererB = 0x8D2A106639281D5EULL; std::uint64_t aWandererC = 0xB3B941BC7C6D4F17ULL; std::uint64_t aWandererD = 0xCA2D31D6EA483B99ULL;
    std::uint64_t aWandererE = 0xDBD952560533AA60ULL; std::uint64_t aWandererF = 0xF860A37C46D4F2BAULL; std::uint64_t aWandererG = 0xECBC5E9F8513304DULL; std::uint64_t aWandererH = 0xCF68030DD1907611ULL;
    std::uint64_t aWandererI = 0x8EE171E536C705C1ULL; std::uint64_t aWandererJ = 0xDFFB8BD1AFCB2725ULL; std::uint64_t aWandererK = 0xB93886BCF49C2721ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x81485AFE80AFDE75ULL;
        aCarry = 0xCA55DD25383FCB9AULL;
        aWandererA = 0x9CA5ADFC4B9F7779ULL;
        aWandererB = 0x966C691C6E40F230ULL;
        aWandererC = 0xF0E85D51E80545F0ULL;
        aWandererD = 0xE28991EB029CCDDDULL;
        aWandererE = 0xED83D5162D45681EULL;
        aWandererF = 0xC6A1691EA7142770ULL;
        aWandererG = 0xDF82771C1B061DA2ULL;
        aWandererH = 0xD863AAF61FE7CF72ULL;
        aWandererI = 0xFCFAFCC904A3AB5DULL;
        aWandererJ = 0xA15C667EFB9D4C6EULL;
        aWandererK = 0x9D35F6EE505BD7B5ULL;
    TwistExpander_Rigel_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBFCF6BB1FF4AFF1AULL; std::uint64_t aIngress = 0xE6B3993E43F4DDF8ULL; std::uint64_t aCarry = 0xC8475A041647AC16ULL;

    std::uint64_t aWandererA = 0xFCD9DC49D0EFB3F0ULL; std::uint64_t aWandererB = 0x88301E0B0C36E6D6ULL; std::uint64_t aWandererC = 0xC60FEB5C9BEB135EULL; std::uint64_t aWandererD = 0xC7B8098EA888F0A8ULL;
    std::uint64_t aWandererE = 0x9FB3C43D7B10D988ULL; std::uint64_t aWandererF = 0xBA704A43199359ADULL; std::uint64_t aWandererG = 0xAE8D5111D93F51D5ULL; std::uint64_t aWandererH = 0xD3E70FEDD7C74949ULL;
    std::uint64_t aWandererI = 0x996FDAC21EBF5F2BULL; std::uint64_t aWandererJ = 0x94997048244D53F8ULL; std::uint64_t aWandererK = 0xDC37A975A63FC5B9ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAF32ED6AD078E823ULL;
        aCarry = 0x9F66ABC9D9FD72D2ULL;
        aWandererA = 0xB33F39FDD5D0F7E9ULL;
        aWandererB = 0x8E72100041CD199AULL;
        aWandererC = 0x9A96945236315B48ULL;
        aWandererD = 0x831BBBCBA88DC3E5ULL;
        aWandererE = 0xC51F40420ADAA17BULL;
        aWandererF = 0xA859AB1C8ECFFD8BULL;
        aWandererG = 0xBFB548CC09726039ULL;
        aWandererH = 0xB638E6736288ED53ULL;
        aWandererI = 0xA6EA14ED09C1F47CULL;
        aWandererJ = 0xA3907ABB710FFE58ULL;
        aWandererK = 0x8CCA0B3FE4785708ULL;
    TwistExpander_Rigel_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF722593E6FBB8CCAULL; std::uint64_t aIngress = 0xB633E4841E7D2DB6ULL; std::uint64_t aCarry = 0x986AF6A35090E71EULL;

    std::uint64_t aWandererA = 0xC13CDFBDC259F256ULL; std::uint64_t aWandererB = 0xE760C1C92B913F9EULL; std::uint64_t aWandererC = 0xE606D4D821A17789ULL; std::uint64_t aWandererD = 0xE78C42A87C801F77ULL;
    std::uint64_t aWandererE = 0xC3D7E1E97F5A1900ULL; std::uint64_t aWandererF = 0xDFB7C09C016F0AA6ULL; std::uint64_t aWandererG = 0xB4C53A655973C24DULL; std::uint64_t aWandererH = 0xE43CA722A55B1007ULL;
    std::uint64_t aWandererI = 0xEC2047FCF7BD5C01ULL; std::uint64_t aWandererJ = 0x876713B14BAB4D88ULL; std::uint64_t aWandererK = 0xCA3ED8F42EB4BE6AULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC28A90CB50F96409ULL;
        aCarry = 0xE736F726D05D3674ULL;
        aWandererA = 0x834B50D6269066C2ULL;
        aWandererB = 0xD5C8D4D698D1FA5FULL;
        aWandererC = 0xBF6F43BD4F652219ULL;
        aWandererD = 0xE3098CE5F705AA0DULL;
        aWandererE = 0xDBA4C6428440F0A7ULL;
        aWandererF = 0xF7FC467AAC3B4D54ULL;
        aWandererG = 0xE00420436A4CF5A6ULL;
        aWandererH = 0xFDCF652F93AEA6C6ULL;
        aWandererI = 0xECCC59DE1EA29B92ULL;
        aWandererJ = 0xD47DCFD44E21531CULL;
        aWandererK = 0xC7EFDA05340C5BBEULL;
    TwistExpander_Rigel_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Rigel::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB5E8BCF6038A82DDULL;
    std::uint64_t aIngress = 0xD618E6584CEE34EBULL;
    std::uint64_t aCarry = 0xDE8F302BE58D89CDULL;

    std::uint64_t aWandererA = 0xF57F0FAE36195169ULL;
    std::uint64_t aWandererB = 0xFA218C247F322BD3ULL;
    std::uint64_t aWandererC = 0x95D0148A7E24607DULL;
    std::uint64_t aWandererD = 0x8D450BDB0ABFA364ULL;
    std::uint64_t aWandererE = 0xB9ADCE5E6BEE9D59ULL;
    std::uint64_t aWandererF = 0xE7CFE53D1FF5ABDDULL;
    std::uint64_t aWandererG = 0xCD9154B902CA6533ULL;
    std::uint64_t aWandererH = 0xCC1DD5E53BC96897ULL;
    std::uint64_t aWandererI = 0x9681F62FCDEB749FULL;
    std::uint64_t aWandererJ = 0x99A9545507377F57ULL;
    std::uint64_t aWandererK = 0x9D2761B583377D00ULL;

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
    TwistExpander_Rigel_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KEY(pWorkSpace,
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

void TwistExpander_Rigel::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9B12AD36610A1783ULL; std::uint64_t aIngress = 0xDAB740830B558F50ULL; std::uint64_t aCarry = 0xD058ED6E7EA94B8FULL;

    std::uint64_t aWandererA = 0xA4F0AE9285B552EAULL; std::uint64_t aWandererB = 0x843565A538DFA534ULL; std::uint64_t aWandererC = 0xBE33A052266CD2B5ULL; std::uint64_t aWandererD = 0x902DF72E45027B3FULL;
    std::uint64_t aWandererE = 0xC02E812C5F85CD0CULL; std::uint64_t aWandererF = 0xCB1D3456F14BC856ULL; std::uint64_t aWandererG = 0xFE0FCD36ADB79A5AULL; std::uint64_t aWandererH = 0xB2EBE93E8E1FF0BCULL;
    std::uint64_t aWandererI = 0xC92AD7588361256BULL; std::uint64_t aWandererJ = 0x81ECDCDB5F566C6EULL; std::uint64_t aWandererK = 0xC94477AD8F26AE75ULL;

    // [twist]
        aPrevious = 0xC2E40835DC3AE62EULL;
        aCarry = 0xB6C585C14C00E435ULL;
        aWandererA = 0x859C89BAE49F509FULL;
        aWandererB = 0xAF63AD498BE91734ULL;
        aWandererC = 0xA489B2A1E93B857EULL;
        aWandererD = 0x80DBBB46AD0CBB5FULL;
        aWandererE = 0x9E77981C9CC59A9FULL;
        aWandererF = 0xD51DE04E07A5CF97ULL;
        aWandererG = 0xB86409FE96F485A4ULL;
        aWandererH = 0xF00978D72DF18C38ULL;
        aWandererI = 0x8F81AC1F6C0914F3ULL;
        aWandererJ = 0xAF86A09D94F677B1ULL;
        aWandererK = 0xB9B0644CF949151AULL;
    TwistExpander_Rigel_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Rigel::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Rigel::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Rigel::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 29 of 33
    // Exploration cases: 0
    // Structural maximin 505 / 674; family total 14987
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1645U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 29 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 14929
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
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
            const std::size_t aFoldIndexA = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 700U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 29 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1045 / 1248; total 29965
void TwistExpander_Rigel::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
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
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 813U) & W_KEY1);
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
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
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
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
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
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
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

// FoldTwistControl candidate 29 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1047 / 1248; total 30204
void TwistExpander_Rigel::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
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
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
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
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Rigel::kKeyRotateSalts = {
    {
        {
            0x3B3A57A64F06E2BCULL, 0x28F13451D0C65F94ULL, 0x58A54B77B620F158ULL, 0xAB37226AA4619635ULL, 
            0xE9DAE3D5578A3F32ULL, 0xED7DC9816AD9F6D6ULL, 0x54A7A0C99798656BULL, 0xD1936764BAE6BB20ULL, 
            0x7B4A288030F28884ULL, 0x885CE92E5E9BEBBCULL, 0x46C785722F7C4B1FULL, 0xB8C469B91CCA6F0DULL, 
            0xF0A5645009C38801ULL, 0x89753906A3A628CAULL, 0x14596C0564CD9C48ULL, 0xFE495C3CE3AA1BB0ULL, 
            0x67B3F5FBFD2ECB63ULL, 0xAE63207E3AC61F7DULL, 0xCA4B49A8B19E4716ULL, 0xC9E228150D8BEFB2ULL, 
            0xDF436EB402932E9EULL, 0x498CEE4BDAF09973ULL, 0x9A9B55A8385A5E89ULL, 0x9F5DCD41FA78D027ULL, 
            0x4D4BB609A9EDA76EULL, 0x3781C11F4B1D6F58ULL, 0x8C15875B74BC6F96ULL, 0xDC61582DA06CC9C3ULL, 
            0xCA51782F26D34DBCULL, 0x22541CBCDBF9738EULL, 0x4632AAE92592B826ULL, 0x29323C6D6BF7FACFULL
        },
        {
            0xBDF2776D945DE1B9ULL, 0x2A62075FBA1DFD05ULL, 0x566136A40B66102AULL, 0x441BBC21103EF6EDULL, 
            0xFA3DFEB0CE626C32ULL, 0x898094B9B6969650ULL, 0x869CCE2322B1F6C2ULL, 0xBB2BCAF41B7ACED9ULL, 
            0x9BBB213312E08710ULL, 0x50C9C305DE7BB4E0ULL, 0x3E4E137EFE1AD395ULL, 0x3EE0FA941C020248ULL, 
            0x1E855CA30FD3A2AEULL, 0xC109F611FC850AA7ULL, 0xDDFECC346326EC24ULL, 0x8DE6CF550550195DULL, 
            0x1F4B77920BF0A056ULL, 0x106998006B4A8377ULL, 0x602B62D3F6A8191CULL, 0x67273C9684DDE786ULL, 
            0xCC47626F33D5AF75ULL, 0x6FD576825C50B659ULL, 0x071E6453E97A0036ULL, 0xB9EB9575C52C0B65ULL, 
            0x65F2A863EBF4FBF2ULL, 0x49E7A1E77F8D5A55ULL, 0xA0BDCC41C354DD39ULL, 0x77A1050CF44012ABULL, 
            0x47D11336170D3A93ULL, 0x3422D146DC057833ULL, 0xF4448CB676F33E87ULL, 0xA6EB9F8C61EF1D55ULL
        },
        {
            0x4ED2ACF23151BDBAULL, 0xCE0847179A18B497ULL, 0x5B991A4AA34372ADULL, 0x8EF3C4E59D37D4B6ULL, 
            0xB2D513AC4D2C9C1AULL, 0x3AC327E76F583D5CULL, 0xC4EEF5D0880C0776ULL, 0xE4E9F2091C0E0C19ULL, 
            0xCA924F7193192E40ULL, 0xF7E48484A67D608DULL, 0xC411776655016CEAULL, 0x68FC5BA64E63D89FULL, 
            0xB7C1FD90B42C784FULL, 0x3EEEF70C82C9C44CULL, 0x0371FA4C1ACB0D91ULL, 0xB6730F5EA3754294ULL, 
            0xB411DA28EEDE773AULL, 0x5F1DAFBCEADF4AB1ULL, 0xE92120A35591F04CULL, 0x5CF7E28751EB9906ULL, 
            0x1158BAA8909991A6ULL, 0x4A5A69F500BCE1B8ULL, 0xAE680F93DDBFEBFCULL, 0xF92F2DD4C6D4696AULL, 
            0xCA9346BB580A7B17ULL, 0xE26B3E621FBDCC24ULL, 0x3BB3A17384FF936EULL, 0x2912FB70A6F56FEAULL, 
            0x0339AD5DEE90D9C3ULL, 0xDC3F8D88817A7599ULL, 0x24CCD71F48C8A588ULL, 0x52D18424053575F2ULL
        },
        {
            0xA6348DD2A1967628ULL, 0x9BFB49D78AC9E8E1ULL, 0x5A61CEB5EC29ECFEULL, 0x9DCDD1FACC3EF50EULL, 
            0x5D0092A8FFB62A3CULL, 0x64A9B37BBBBE1A55ULL, 0x21E00D841721D887ULL, 0x1DF3DC1D5A3F6335ULL, 
            0xE530605D71E84060ULL, 0xFB9204D2A309104BULL, 0x8C72240C2408185DULL, 0x7E1D7A2BCC426942ULL, 
            0xFC426D7A386F44EDULL, 0x1AB5716F7BF87039ULL, 0x96039DDF30BC737AULL, 0x4AF93DBCE181B9E6ULL, 
            0x7ADABC8C0D738BE4ULL, 0xF9882E415762D511ULL, 0xB54D9441099BA15DULL, 0x550610AA2718EEC3ULL, 
            0xC52AD58F85D3F992ULL, 0xD8D4A783C68B6577ULL, 0x22E8BA750387B65EULL, 0x13C6CE192D4C1DBEULL, 
            0x6E0F3CA9D91895CFULL, 0xAC117453A406F1ACULL, 0x28913B2A8C82CA12ULL, 0x5A0149D9A99B8BAEULL, 
            0x8E684D6D4B4B6028ULL, 0xECCB056902BF183CULL, 0xE2B1E2BB48E2B65FULL, 0xCA4048EC3C7DEDA2ULL
        },
        {
            0xF8A6B475ED56BA28ULL, 0xB05CD8D9152487E9ULL, 0x9A3224A8F6676B40ULL, 0xAAB3A4B065CE8D7CULL, 
            0x5BDB41EB7D2E4436ULL, 0x4F57AEE86AB7B526ULL, 0x596847FA6AAA0761ULL, 0xAFE616B3E062A845ULL, 
            0x7D9E2A9B1AB7210CULL, 0x361AF90C052339D0ULL, 0x4E3804B00CBB1DD8ULL, 0x62EDA1D2B1209139ULL, 
            0x8148D8EB74470125ULL, 0xF6561D0BA8EA14C6ULL, 0xBEBB4E097CE8F771ULL, 0xA0F8D0424028B1AFULL, 
            0x6ADB2C85AD821686ULL, 0x94BA41F34BB4CCD4ULL, 0xD0E5C42CB334C231ULL, 0x2C329838486764C3ULL, 
            0xD51BD49B3E1DBAFEULL, 0x8E75AC619FF52785ULL, 0xDF609DEBDF9B55CDULL, 0x50E0BE7234E64851ULL, 
            0x1BD30BA65D9D8167ULL, 0xF000947A25A5DC1DULL, 0x4CB96AD29F40241EULL, 0xB15A9F578D210F6FULL, 
            0x511BEF7801D49CD4ULL, 0x52C999C108802F52ULL, 0x5813B7BCDF96A739ULL, 0x8B322BDE09D20000ULL
        },
        {
            0xE37B958BFF0048D1ULL, 0xA42FA8045DAE6DD8ULL, 0x1E1D7D92E1707F6CULL, 0x196C0C373701356DULL, 
            0x850FBF486ED54AAEULL, 0xFAB54A509E317693ULL, 0x44853D2B6EACD158ULL, 0xE18FB0D9F5C46DCCULL, 
            0xAEF1747F336DFC44ULL, 0x6E6C1790BF2252DFULL, 0xD999DBAD00BF0757ULL, 0x550A920C6264844DULL, 
            0x1750EBC2A7BE68C6ULL, 0xB101D21565A85061ULL, 0x87DD0CE8B5D5C9B5ULL, 0x0831D7328D104D4CULL, 
            0xB95FEF4FC9EF1D66ULL, 0xA45F3ADEDC96B443ULL, 0xE780B7A71E0F3FA6ULL, 0x20661B9883F9FDC2ULL, 
            0x877ADD5DE60F6E63ULL, 0xD10869C88170C450ULL, 0x11EA575645996869ULL, 0x8A57E1FF2AD2E542ULL, 
            0x5AEF191C18A30538ULL, 0xFBA1A8D9AE66C566ULL, 0x63AF2A0FC9B5E108ULL, 0x7233831FBFBC9504ULL, 
            0xBBEA3B4090EF4938ULL, 0xDC031E8DE76CB4EEULL, 0x8232928B8E613B4BULL, 0x9DA27A4DDA05BD4DULL
        }
    },
    {
        {
            0x0A76237D1E2AF86EULL, 0x75D1DA0631D628E1ULL, 0x29B8BCAC51439C52ULL, 0xDD544D3AF9CF74DFULL, 
            0xBCAC4DB5CAAABB11ULL, 0xB11A8059A6FD756CULL, 0x60694B7F4AACC0F5ULL, 0xA2DD90FDBDC94633ULL, 
            0xB2B1AB2C96E1A70EULL, 0x7C00B7B9F2E9E884ULL, 0xD52F53F51DD2814FULL, 0xC6EAEA5734A179FFULL, 
            0xC336DFF59EA3CE96ULL, 0x519E3A0D330ECC17ULL, 0x7DBFB6C7F4C6D9D5ULL, 0x0EFFDDD1ABBEB3CCULL, 
            0x06CE08B63B2335C7ULL, 0x51A360A5DB88F43DULL, 0xCB2057C755633368ULL, 0x5ACDDDC6613BE721ULL, 
            0x70FA551E9ADBBAF8ULL, 0x89B98E18277BCAD7ULL, 0xED4A056805FFE7E1ULL, 0xC6B80F18135149EBULL, 
            0xF334D46CE95E9858ULL, 0xF89979331E1EA806ULL, 0x0E147C7920576DE8ULL, 0xF2F70D13C29A82D9ULL, 
            0xBDF4A562F91AB92DULL, 0x86DE8ED05CA29BEAULL, 0x1E4E218EA36122E4ULL, 0x6DF708C2BEA4F642ULL
        },
        {
            0x8B9462F8990E3670ULL, 0x0113D742C8C2BE8CULL, 0x80B8BEAF7F8DCEC7ULL, 0xDF1A00E0D6E3E157ULL, 
            0x9F7502CD80A7C4B3ULL, 0x0D680381D13E5AF5ULL, 0x46F414165F7C32E4ULL, 0x476448D190C3C29EULL, 
            0xA1B29649685FEC95ULL, 0x567C0C80106E3510ULL, 0xC5CCF61332CA5CC8ULL, 0x57C596540FC99664ULL, 
            0xBDF6AAE05B58E984ULL, 0x566E308274F01700ULL, 0x31FE52324D0F3157ULL, 0x08BBC6CD84EBDDF8ULL, 
            0xCF75D011EFD55B65ULL, 0xABC5C501D0A7B239ULL, 0x3F7133E0A0AC4B5FULL, 0x108C1C5695F0A6BCULL, 
            0xEFB33E486401ABD0ULL, 0x742EF878B318A9AEULL, 0x046677430A2D2272ULL, 0x2807542C1A4F2140ULL, 
            0x6AD9E90AC7798178ULL, 0x0772301D39904A6EULL, 0xF313E71FCA6F8A8DULL, 0xD4A7A17F257DFE60ULL, 
            0x1D4BFB7676106154ULL, 0x457F58E1C164B815ULL, 0x0FDB458DA48512B7ULL, 0x7890DDF66237E54CULL
        },
        {
            0xE8C08C977986772CULL, 0x39088419A022B820ULL, 0x8F5814D4E6084801ULL, 0xA5DCA11DA7668E22ULL, 
            0x63E09FAA3393D269ULL, 0x0A96AA821AFA69F8ULL, 0x8B42729B90E58A11ULL, 0xD58DBA88F26ED77BULL, 
            0xBCB88BE30001C688ULL, 0xAACE9707F613EFB9ULL, 0x530DE48B447E471EULL, 0x73C3BA882717EC3DULL, 
            0xDD128DA6472E034DULL, 0x05C2BE9E1219A3AFULL, 0x98D093D7B6038DA7ULL, 0xAC656F68E0FD983EULL, 
            0xE4CA033A42C6F66DULL, 0x1D8BFE427CE99122ULL, 0x95A6B6C8E3943E86ULL, 0x2DAB9DE7EAE7084FULL, 
            0xA6081432EDE72CD2ULL, 0xCAB3C32A80371FEEULL, 0xCB7B899EA22F7F25ULL, 0xA20410368EEF3E39ULL, 
            0x2382CD5848478726ULL, 0x70F0089FBA377905ULL, 0x84D557F5E11BDE75ULL, 0x12C898A3CF7A7FEEULL, 
            0xF6C47950F4AC5AD7ULL, 0xCF729C608D73B512ULL, 0x4796358C61488F3BULL, 0x7CCC92D396AEB14CULL
        },
        {
            0x929F1F46CE95518FULL, 0xD4F2E09AA26D2787ULL, 0x6AEAE996129ACFA2ULL, 0xA65062FF8D4E19C1ULL, 
            0xFD59CED0503C7215ULL, 0xDA363D2D16E38391ULL, 0x208D26AAF908880CULL, 0xD59420ECC2FA74FCULL, 
            0xF2BEE8178006A1D3ULL, 0x75060BD629674199ULL, 0x434C67AC83334875ULL, 0xBE2D345FF91F4AACULL, 
            0x8210EA3463AB08D3ULL, 0xADDB50A1DF8B09E0ULL, 0xBF790B4132C25428ULL, 0x717AA798E3CA1D1AULL, 
            0x2E9C790AFF35A4E4ULL, 0x38A8E4F165A7F81CULL, 0x1A845CD4377D3D3DULL, 0x9AA6E660E83F3127ULL, 
            0x541213D854D416CCULL, 0x98F23FCF5CC64595ULL, 0xC4B19C7194C86C44ULL, 0x1AA7E612D3E1066BULL, 
            0xE24B9E1EE0B4B7D4ULL, 0xC4B5425F94CD5502ULL, 0xAE95E564C106471DULL, 0x181391BACE8A5947ULL, 
            0xCCF882B70A0C5172ULL, 0x17E3760BDF8A434AULL, 0x9BDA7914149951C5ULL, 0x84DB3AFAF5229EFCULL
        },
        {
            0x2A03DC5683B22FC9ULL, 0x90A7D2666A83F9FCULL, 0x09D5936218A5A5E2ULL, 0x041008A3C037CCD8ULL, 
            0x3D9B658555C0ED16ULL, 0xC02062883A46007FULL, 0x4840C890E54EC324ULL, 0x46EA2BB556D4C784ULL, 
            0xF957C3741EFF34F2ULL, 0x8F9065BAE1FFAE7FULL, 0x62E916B2F68A2516ULL, 0x6DEE6498928E74DDULL, 
            0xF045E6FBBA86E86FULL, 0x489D3E0125C889F2ULL, 0xBEBA0C7A2B16C7DCULL, 0x1D50AE9AB0A7C375ULL, 
            0x38B138C8759F017EULL, 0xC657C4F0C7AD5388ULL, 0x4F183553A25B6AEAULL, 0x9CE8AB26FE72B930ULL, 
            0x4DBDB3E0DAA9A0C4ULL, 0x9493ABF687088C56ULL, 0x79EBDD5A5890E500ULL, 0xD781361CFA404672ULL, 
            0xAA57B4B3F7D24293ULL, 0x798F13743BD3DBCCULL, 0x02581C49588FAE0EULL, 0xEEF3FED0D6180C5CULL, 
            0x7E405E484019DA3EULL, 0x0EB8DC1893C4083DULL, 0x066A8697E08B942EULL, 0x7BD8A6A84A898D40ULL
        },
        {
            0x0DA77E9F1B563FC1ULL, 0x6558CE8AE9F2C903ULL, 0x03F75AA289036E6AULL, 0xD25EDC9DE84DA4C2ULL, 
            0xC457BDD19780088AULL, 0x644175F6DB38D81DULL, 0xE61A78D79DF8301BULL, 0x24C5FE4A53D34919ULL, 
            0x17112702DD14448FULL, 0xB60A385F277C873AULL, 0xE1647C2C56622E8AULL, 0x672D7425F82F2E66ULL, 
            0x84CDDE510B0321A6ULL, 0x86C5D5907DFC58D0ULL, 0x25A6F19633A7602AULL, 0x09FBACE72EDEE4F4ULL, 
            0x820B4120C35E6B2BULL, 0xDD7D215705158A4FULL, 0x3F55B2DEF49A6CE7ULL, 0x6F6D993BBA257D72ULL, 
            0x9EACB614A6E0F318ULL, 0x0CB85BCBBC679EB8ULL, 0x732BDA17FB3903A2ULL, 0xF508ECA1095795ADULL, 
            0x5B42737C59755345ULL, 0x77A457AA1B48DFB4ULL, 0xBE3D204F408C43CEULL, 0xA56589C3B67FAB20ULL, 
            0x20B25950767183F1ULL, 0x239E4A7CE8A6D998ULL, 0xC3BA27E7479225C8ULL, 0x08A46A83AD9CE9B1ULL
        }
    },
    {
        {
            0xAF78E6CCD55BFE85ULL, 0x5E68C99DA1752D9CULL, 0x6D86E9B0373524C7ULL, 0x529D5805AE9D149DULL, 
            0x5509E9597D4AF36BULL, 0xF0EEA6D3E5C00D67ULL, 0x6811E7776406DE5EULL, 0x6392CDB6E40DDD84ULL, 
            0x183211EA81F521A9ULL, 0xEA8FA516E259DA00ULL, 0x6517B56456D25967ULL, 0xF05365CD8F761EB7ULL, 
            0x990F60030B0F4EA9ULL, 0x8344AFEA33C5371BULL, 0xF2E8DACF2E605B71ULL, 0xE27A85E2C270EAD7ULL, 
            0x4519DA968893BC06ULL, 0x8E44B2DD0E4EEB74ULL, 0x8711B63E408815E2ULL, 0xE45533843C2757D5ULL, 
            0x8ED53BF76CE71C57ULL, 0x8944B3DBC9CEAD9CULL, 0x54BF94AE59696BDAULL, 0xC5EE7A0A37BE3936ULL, 
            0x90A861C65B2884C6ULL, 0x3F9262273FE3AF23ULL, 0x6C439DAAC03F08A2ULL, 0x325596634BB92745ULL, 
            0x621EF9EFE091422FULL, 0xD97CF30B2094BB6FULL, 0x83AB908A658413E2ULL, 0x4BA44E01D7A2376CULL
        },
        {
            0x78C7C79A4E4E4758ULL, 0x4E194FB10EFE6B93ULL, 0x62C26976221831F6ULL, 0xD9334E034DD5584FULL, 
            0xF67CE6DBDC874591ULL, 0x5C9062D43AFAA605ULL, 0x7A79F0BAF30E8D14ULL, 0xE9FDE6A2C4803367ULL, 
            0xF8930A5E79A78EBDULL, 0x07BA8AF0A5BA5775ULL, 0xE660AF9D4BCF03E5ULL, 0xDAC94BC088826901ULL, 
            0xA56D4536821D1D94ULL, 0xDF915ECFFD8A7EABULL, 0x867279C159C972F7ULL, 0xA600DB7EFB27B743ULL, 
            0x309631CE112C0134ULL, 0x00DC45B23377FC65ULL, 0xC94EF30B5528E9D8ULL, 0xA0F6CAEB5A8953EAULL, 
            0x256EA6FBB4E9B56EULL, 0xAA688C6B201B958CULL, 0xCD6BE2A9B3B5F525ULL, 0xE5000D9E9D9EA3E2ULL, 
            0x9C2E60CC3C728AE2ULL, 0xC6058C4A58583116ULL, 0xF40A338F15EA5F2EULL, 0xD34D6A0C77B60F25ULL, 
            0x2A1BB31CF1634019ULL, 0xCF44073A0C736C97ULL, 0x293DC9A0E44BE376ULL, 0x176E940DFDF36EA6ULL
        },
        {
            0xBB82A315703AF11FULL, 0xF22AB945D1156157ULL, 0x5635CF14597E9EDAULL, 0xF464D4AE4D051410ULL, 
            0x1D2785C41ECE4817ULL, 0x9142CD19E109D727ULL, 0x0AF062732A3BD713ULL, 0x2A5CC13EAFAD0934ULL, 
            0xE57FFCD7623AE024ULL, 0x50D5D7EB7A501DAAULL, 0x00ECA2F0891DD565ULL, 0xCF319456BE42C027ULL, 
            0xC4B20071206DC675ULL, 0x6AFCC2E7FDD4916EULL, 0x6BB8EB3631DD4B6CULL, 0xD1DEEE7DC45820BFULL, 
            0xAD9F180555353EF4ULL, 0x9D68BE64CBBEEEF4ULL, 0x769CD4E1E06AAFE6ULL, 0x8B5E906A278D66D8ULL, 
            0x1614F6DEF8EA88BBULL, 0xFB2C8F6EF7DE2BECULL, 0xF4799D259EBD906FULL, 0x03FEED8BC95B9565ULL, 
            0x7C988626BA0D7003ULL, 0xCF2ADFBF55B4F6C1ULL, 0x37404EFD5A2E2A25ULL, 0x343038C4BACD6F8AULL, 
            0xA4B5F25EADD7B687ULL, 0xD146E8FCF2EE315EULL, 0x7156440AF1D6DD54ULL, 0x58BC2D4313707B80ULL
        },
        {
            0x9785A87FFE587447ULL, 0xC8667281A6500F07ULL, 0x56259209DC0AA794ULL, 0x71FFF2C1A3FBAC1DULL, 
            0xC113E7D9FC7F8FA9ULL, 0x944F3BADBA14F314ULL, 0x308447C61CC84CEAULL, 0x8ABEBCCDEF27515AULL, 
            0x332CF071378B9FEBULL, 0xEAD0F3AB004A5E92ULL, 0xEA4B2690745FF3BDULL, 0x263F453DD5149199ULL, 
            0xF552BF84BAE72573ULL, 0xF818E9E4EF23E31CULL, 0xDAC40B16831E5462ULL, 0x52F8CD8901E77CB6ULL, 
            0x00ED80F385A2CEF9ULL, 0xA5DF7AF8AF117510ULL, 0xF1A9E3EBB5A57E84ULL, 0xE47862D9F763A983ULL, 
            0x86FDB1FEDE9E3EFBULL, 0xD448D691AF251679ULL, 0x53E167C0EABB027AULL, 0x5AA2B411777EDA81ULL, 
            0x0F14C2E8D0431AD6ULL, 0x35AB60C45C8F8517ULL, 0xD4D25624A01ADB80ULL, 0xDA71E537267608C9ULL, 
            0xAA0EE51367350C07ULL, 0x6F57E8870322FD92ULL, 0x3DF1E04A62B33B66ULL, 0x91F067827D5FEADBULL
        },
        {
            0x486B8A864DE56159ULL, 0x65EBA64C1A69C91DULL, 0xA28605EA8280FE83ULL, 0xED088377614CF298ULL, 
            0x5169E1F44B0B0499ULL, 0xED3F0734AFA6362BULL, 0x0BC6B5D7B0723772ULL, 0x1A3E517893B0CA82ULL, 
            0x15FB710A9D8BA569ULL, 0xE7D5CC882518E800ULL, 0x37449110A724117CULL, 0xFC993445D99C03EDULL, 
            0x2ADA434045EA0277ULL, 0x999216D205426D0DULL, 0x6FA6BF432971400DULL, 0xA023E2FBFD896460ULL, 
            0x6C7850EEC5E5A127ULL, 0xE60DD2D69861E0C6ULL, 0x602EB8730B20E31CULL, 0x56C82E06DBB46F35ULL, 
            0x8FB4DEE89CABC8B6ULL, 0x50EFF7D98AF52176ULL, 0xC1A621AE7867FAA0ULL, 0xA9ADC8BD5EB4E11FULL, 
            0x94635684A2C0C98DULL, 0x08C041F7013445BBULL, 0x1FA243B905E240DEULL, 0xED96DACDB1C2E331ULL, 
            0x32A0F58C535E9F35ULL, 0xCA11627F1CAE5E5DULL, 0x4982B589686AA6AEULL, 0x02303AFEF8C424A2ULL
        },
        {
            0xF5B94ED42CDB8088ULL, 0x7643C8051E1A7C6BULL, 0x5E8872F5AB9DF4EDULL, 0xE51D04C6BF70D3A6ULL, 
            0x6720B2B24C45968FULL, 0xF823AEA06F88550CULL, 0x0780FBD6075340F4ULL, 0x86742CF0CEEC3213ULL, 
            0xD7798ED26D38D194ULL, 0xF09DB6E82B61CDCAULL, 0x34BA6822AA8B3766ULL, 0xD86056CE262DEEAAULL, 
            0x5C3CC848D964961EULL, 0x716CB91FA15CD72CULL, 0x2A3F7FA950BAF76FULL, 0x5F083997D1D09A2FULL, 
            0x147C063DD7DC89ABULL, 0x1296F6A737997B9BULL, 0x0CA637584C46C8FCULL, 0x90BEC3FD5138871AULL, 
            0x58DF5F98005B3CC3ULL, 0x10EA8F34655D6BF1ULL, 0xD9C55AD7C1A4BC76ULL, 0xCE8885BBD408C97EULL, 
            0x7E31BABAACF345C3ULL, 0x339D6EA344E67663ULL, 0xEB983D1DA8F13D2DULL, 0x0DCF1F94E011B21FULL, 
            0xCC95AC89130D54FEULL, 0x612F407D230807DCULL, 0x992D7EBD82E9E350ULL, 0xC90638ABE83B6CE3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeyRotateConstants = {
    0x62BA7803826C1CA6ULL,
    0x751F9AFA134E8AB9ULL,
    0xA64947923BD9C9FDULL,
    0x62BA7803826C1CA6ULL,
    0x751F9AFA134E8AB9ULL,
    0xA64947923BD9C9FDULL,
    0x3A9A595BB58A7EC1ULL,
    0xD237F9F9A23C04B6ULL,
    0x7C,
    0x93,
    0x97,
    0x70,
    0xDF,
    0x76,
    0x90,
    0x2E
};

const TwistDomainSaltSet TwistExpander_Rigel::kKeySpawnSalts = {
    {
        {
            0xE2608F956E370803ULL, 0x1844EF44CF03537BULL, 0xD3902BB3FB4B39F8ULL, 0x59CCED2A3AE7EB7CULL, 
            0xFADBA4326708562AULL, 0x985B7422B0C52579ULL, 0xC87F7C96062C4618ULL, 0xCF19C3E61DA9442EULL, 
            0x55C7FAACF2C762A1ULL, 0xC309FF02BFD1FC93ULL, 0x093F06E2CE4D36F6ULL, 0x3F50D6DE85E69AE6ULL, 
            0x7022FCF5BA74D85BULL, 0xF4F552781CE49797ULL, 0x80F600B5F38CA007ULL, 0xC9D745152976B770ULL, 
            0xBA43A6D7A2430578ULL, 0x5F396D3ADCD9E9C2ULL, 0xC4A401E491BAEB8DULL, 0x83C083D0624C4288ULL, 
            0x661A2548949D12AFULL, 0x0146B0A35F9404EFULL, 0x8C588386C9FFEEF1ULL, 0x5D720EB9A17A23ECULL, 
            0xF5D1F5CCCC1F2ACDULL, 0xC5EBBF0509FC32EFULL, 0x4CDB606CE91FC056ULL, 0x0599685E3F87573EULL, 
            0xF0256EC6C08F6AE0ULL, 0xFB0B2D63A4954A4CULL, 0xA110AC338C318051ULL, 0xF7757932D85ED479ULL
        },
        {
            0xB8670A2DFD8E4EE6ULL, 0x00B8A676C50846E2ULL, 0xCB0E70BE53D5C677ULL, 0x12EF7E7EC0793C29ULL, 
            0x47B5ECA037588AF7ULL, 0x094A0E1660A34872ULL, 0xA0ABBED18F0971CCULL, 0x232CBFF9937CF947ULL, 
            0x4902E8BAB849304EULL, 0xCB8F85F9F2287EA4ULL, 0x5D5916AF64F7C91DULL, 0xA31AC57207CC788DULL, 
            0x66CF2A0901BB39CAULL, 0x48A07D39250FA0C9ULL, 0x09D90F2E823A47ECULL, 0xA522DE9BF8D608AEULL, 
            0x5DDD09AEFBFE47A0ULL, 0xADACA010E251B6DBULL, 0x127FFBA7F1C38F8CULL, 0xB2B8D57DD1A6B566ULL, 
            0xE838F042DCB0D421ULL, 0x8E33E4C7D0269E27ULL, 0x6B1D5071F77A4F67ULL, 0xCA4DCD4B825DBF66ULL, 
            0x48EED4D848A2434AULL, 0xA5B23DA1B427C546ULL, 0xBEEF8D7B03DFFDE8ULL, 0x3C1B4467EF478330ULL, 
            0xF3674E0B4ECADB20ULL, 0xCB1B95CE7DDF01CAULL, 0x6B913F72B65BE750ULL, 0x4AE85EA366D60AA5ULL
        },
        {
            0xE781018F4FA2BD74ULL, 0xE5E222D3CA8039A4ULL, 0xCC328B7C3BDED056ULL, 0xA57716DEED4DA907ULL, 
            0x1DB110A66A89EC5AULL, 0x767B011887083968ULL, 0x793DAFA9242E20DBULL, 0x8A52CD3AED3349BEULL, 
            0x49F92BE070CFCC8BULL, 0x04D6A3A7C9C03250ULL, 0x1941F67FC13CEFE2ULL, 0xAC97BCB9176EC57AULL, 
            0xDF028A815AC15A5CULL, 0x8F6F77CFCAA72BFDULL, 0x1567F13772FB1AB3ULL, 0x3F5122FB7B207227ULL, 
            0x131B6CDB655DB17EULL, 0xC2DAAACC7A5FF58EULL, 0xCB9BA4D176E988A9ULL, 0x390FA08B2577D98CULL, 
            0x0722EEEF8010359EULL, 0x027FFAF2501F84AFULL, 0x8E711506E8CE02C0ULL, 0x2D8BDB504FF178D2ULL, 
            0x3D1996435CE65617ULL, 0x952A0F72D7D5D215ULL, 0x7C99292E4083C439ULL, 0xDB800977CE87BBEAULL, 
            0x66CCA09B4BBE66D9ULL, 0x38E8AC8FFE8223B8ULL, 0xE46E71F8A5698093ULL, 0x2D2A2FC1C82BBA12ULL
        },
        {
            0xE5336AE54FA23510ULL, 0x95DBE114B6495F02ULL, 0xF5585C41D09E9207ULL, 0x96E4D2C32CC59F68ULL, 
            0x8D130CB7B3C1443EULL, 0xCA78C5DD6D0DD5DDULL, 0x00712B73402E899CULL, 0x03A38EF3D97FB6E7ULL, 
            0x4F7FBE21366DB03CULL, 0xDD4A9781925E58A9ULL, 0xEF65B6842AEB04AEULL, 0x7E26015337B9CC25ULL, 
            0xD2E1D06353E6E379ULL, 0x3A40D51947701349ULL, 0x7BAEA6CC137567AFULL, 0xE85C943607F7C78EULL, 
            0x244A7AE1FB610631ULL, 0xA6112A9DD178527AULL, 0x86A8014DC0D8CC11ULL, 0x808025CCABD9336EULL, 
            0xE8B95B94B06DA156ULL, 0x1A1FC5456163F3B5ULL, 0x4D368D38B2D96794ULL, 0xA9FDF3B00CF6D7FAULL, 
            0x7FBAC3A3F0089609ULL, 0x060D713F0477210FULL, 0x9D21F4E51F658C8BULL, 0xDE957531F44820C2ULL, 
            0xE0AD9A9D6E3C9673ULL, 0x0D9E2CFF0F30BC77ULL, 0x873EFC72563F7589ULL, 0xBEE42E0744F53293ULL
        },
        {
            0xE16EBD1840308566ULL, 0x367EF1FA9C303675ULL, 0x6A3B09B276189575ULL, 0x0F10FB825BCD2D3FULL, 
            0x0C5FF0F870E05691ULL, 0xC06F9F84D8F549FCULL, 0x724229624AD34E48ULL, 0x8E03F26AF4C277BDULL, 
            0x341D77F5D01B1132ULL, 0x5C9515AE44203194ULL, 0xD6E80FAB4612B746ULL, 0x9C932EF5720AFDC2ULL, 
            0x6C70661E70D68C77ULL, 0xAFB5C9A159413986ULL, 0xCBDC3C894C6C92C0ULL, 0x92984586E02C565AULL, 
            0xA84C65BC1BE1D37CULL, 0x69C234DE6D0F4317ULL, 0x2986838E3FD77D72ULL, 0x036A4FCB099C86BEULL, 
            0x5885C04010E3A4F8ULL, 0x81D5E04C1FB29C93ULL, 0x579C5BEA577974C2ULL, 0x8B11E1BDAE115F57ULL, 
            0x97D0B63F53E1C838ULL, 0xB47277AEB07DE5B1ULL, 0xE226B39C60BDC98BULL, 0x61C22EED8CF7FBA2ULL, 
            0x2235139AC6E3BD9BULL, 0x736FAE7EB81F9BEAULL, 0x75CC888206E58D33ULL, 0x21E7F50E17D8B044ULL
        },
        {
            0xE20F43747CC8F3C1ULL, 0x094BB37890AC470AULL, 0x43F3478AF926FEB0ULL, 0xEF88BB6A8675B28DULL, 
            0xC79636D03F4E1585ULL, 0x1DBC7AD490DFEA40ULL, 0x745412A8ED04789BULL, 0x739047038993CD0AULL, 
            0xE8B7ADF101403F3AULL, 0xE7FBD21E85675CE3ULL, 0x3679C52CAA7521F8ULL, 0x68C7C9FDAE648302ULL, 
            0xD936BB968AAFC0DEULL, 0x392773DB533A73AFULL, 0x09E5EBDFDFD433A0ULL, 0x70D67D1BB813520FULL, 
            0x41B8A08DB5F9DBFDULL, 0x20B84ABDFDAEEA3EULL, 0xD44BCA1E7C0DF0CAULL, 0x1CA85D1391431EF4ULL, 
            0xD9378D3DC0A3CEF6ULL, 0xF761611CF6A3DF70ULL, 0xAA7FB9D8C3E62D09ULL, 0x6C79B4756FA3E6D9ULL, 
            0xEE2ADCDC079C0132ULL, 0xABC56B3ACFA71CC8ULL, 0x95B1703B728F6D7AULL, 0x52ACCD218A89758EULL, 
            0x5AB6A38B7FE70114ULL, 0x6ABCDDACEB3BBCA5ULL, 0xFE398E4FEC12E9FEULL, 0x580E951B07469CFDULL
        }
    },
    {
        {
            0xF20FEEF75300A5B2ULL, 0xB62E5D5EF347716CULL, 0x6033BDB69D760BF0ULL, 0x8128AF5965F0293BULL, 
            0xCFED0CA9CAF21AA6ULL, 0xB365E7405982F163ULL, 0xF664CBF95FBEA5C5ULL, 0xC7A9CCC2A21D05ABULL, 
            0x1FC252BFE54A3999ULL, 0xA1E06AD9340CF889ULL, 0x10EF1AF689B9DAC5ULL, 0xA705494FDE499197ULL, 
            0x2367C955BB372B2EULL, 0x4C85C8C124C03BC9ULL, 0x08CD604D67710391ULL, 0x34888CC60A7C71B8ULL, 
            0xAD0856F0133DE21CULL, 0x5347E711BA7EB9AFULL, 0x3DD68956EC3CFFA7ULL, 0x2224F559F84F5B54ULL, 
            0x38B0B3ED3AA6664FULL, 0xEA2646112039E110ULL, 0xDFF759F138EF3D0FULL, 0x52304E9447CE2624ULL, 
            0x293C57784B60FC0FULL, 0x43C3194200368D4AULL, 0xD0B57F71D6018FAAULL, 0xBFD24CB5BC035FE5ULL, 
            0xC59F85F9602F6B28ULL, 0x0B2F91D18E44E78FULL, 0xF6A3832167362250ULL, 0xBF881F01F32EA631ULL
        },
        {
            0x449459FF0AC07E13ULL, 0xC9FB40AD260C681AULL, 0x3AAC882540F5F497ULL, 0xCB108158024C200FULL, 
            0xC037C5891BFAF1FAULL, 0xF86C8E2FB8623D3AULL, 0x2C585EA4FF742524ULL, 0x33BD625A41FFC7C3ULL, 
            0x4120238FCB37E967ULL, 0xF094E94DDE05F688ULL, 0x732EDC41EBC7C43EULL, 0xE16BD4BCE45DD1A9ULL, 
            0x48E5AC01963F6307ULL, 0xA2D826C947FE8BAFULL, 0xFAFA5728C17F988CULL, 0xD387D1FA0EED6272ULL, 
            0x06FCA4E87F4392FAULL, 0x11F024682E947C05ULL, 0x363284D12676C287ULL, 0xF919606C3507FA7BULL, 
            0xC76ECE0AB5CE7202ULL, 0x8C39D41D7B849204ULL, 0x2ED5082482B4708FULL, 0x64548F1A0AE23B8AULL, 
            0xB145F13E7101C414ULL, 0xC65753A4BE9F2D2CULL, 0xB285A3AF077365DAULL, 0xDF094F2E38069D5BULL, 
            0xB7D31ED080BBE673ULL, 0x1B85DCAE27450269ULL, 0xD824454993E359DEULL, 0xC0A582F6F1457039ULL
        },
        {
            0xC932202FC5EB4703ULL, 0xAFF9FEB2639B9E28ULL, 0x518C60D8F1730FABULL, 0x33C44D4B5AB2070CULL, 
            0xFB7D28CB7C2617A7ULL, 0x95C739D602B01027ULL, 0xD389EBEA6FE6E180ULL, 0xA123F2D25313F1D0ULL, 
            0x0FF2DC287EEDC614ULL, 0x906C8B0D6A589F2AULL, 0x719EC8AF20A9DCE0ULL, 0xCDE9D33CB461A196ULL, 
            0x73126722754210C8ULL, 0xD4DD83DB7BAD078DULL, 0xD18E7EFB301D7A7DULL, 0x21DDA8BF9B18B1BAULL, 
            0x49031C9D98D79F49ULL, 0x0412443B0C37C002ULL, 0xF47C3B9D32D94F5DULL, 0xCCADD8A6F5AD193EULL, 
            0x58B64DEDD09CFBB1ULL, 0xF33AFFD437A323ADULL, 0xDF62E3272FEB313AULL, 0x772FA943414BA083ULL, 
            0xACF42F1DFE82E4E9ULL, 0x64A798DF7264EB24ULL, 0x971A8B8C117510F8ULL, 0x3CDB1D7293B04A46ULL, 
            0xB6970470D667A1B8ULL, 0x5C88EB9F5325956EULL, 0x9BB1F50AA6E3D05DULL, 0x31A45357F502412BULL
        },
        {
            0xB20AC1F437301D9BULL, 0x7ECC396B509325FDULL, 0x99826DF34D563C13ULL, 0xAB5235A5C4DA3A82ULL, 
            0x2F9B49D33C42091BULL, 0xDFF1C195C19C8B6FULL, 0xB21D10A0DA7FF600ULL, 0xD067D0711BFD2C8DULL, 
            0xE3EDA82AFD8C89C7ULL, 0xA9A625A328FB064DULL, 0x2DC14347EF4E344AULL, 0xA434BAFC98154631ULL, 
            0x747CA5EF2B1C9D81ULL, 0x39BBCA690FA0D440ULL, 0x292BB4C4F40439CDULL, 0x5925018EFAC2DEE4ULL, 
            0xC419170CAC7839B2ULL, 0x94E6FED8EA0836D6ULL, 0xE718B3E073888D38ULL, 0xBDE1016C1D346FA3ULL, 
            0x936AE399635E0883ULL, 0x0BD323653B420638ULL, 0x6BBF070C5E73041BULL, 0xD00898120BFAA66AULL, 
            0x3A5B7FE014E09321ULL, 0xAE4E7A03CFFA7642ULL, 0x981B854687736524ULL, 0x21B352AAF9F21513ULL, 
            0x67F420AECF45252FULL, 0xDBBDBEC94ACD078DULL, 0x982E1FC06E456753ULL, 0x84D669D91694EA54ULL
        },
        {
            0xDFED5DD224261333ULL, 0x1007DCEB614944B8ULL, 0x229963E7B932AAE9ULL, 0xCA884F76C46C23EFULL, 
            0x6A3400D2AFD490D9ULL, 0xE77A1F0DA5988336ULL, 0x8BFF0FBCFFF66F23ULL, 0x2530CDC80AC4B76AULL, 
            0xA30099FEE6CFC1E0ULL, 0xE535CC16D450B326ULL, 0x49047FA87028F45FULL, 0x803DF2A3DF20A542ULL, 
            0x7D5FC9E87C721D0EULL, 0xF539644A278A9E52ULL, 0xD60535CFC2FF02B7ULL, 0x0B9DF826A46DE2FDULL, 
            0x09DAB9EFDEC6248BULL, 0x4EB168E8E3E9D13BULL, 0x129545F72DFE1B25ULL, 0x9224C2D0472D532AULL, 
            0x99D3A40BB932A34EULL, 0x2FC1AEB12FF1278BULL, 0xFE7D50D684D72F1DULL, 0x966C3EEFB3A4FACDULL, 
            0x3D02A7CD2815783CULL, 0x446975033F1DE13CULL, 0x3A9BAE3DB5FE3630ULL, 0x9F8AA94D0D682559ULL, 
            0xAB535BEB388B9BD8ULL, 0x007C12B1C3216FEAULL, 0x41CA8285C002D7BFULL, 0xFC6EB9518E82ACE8ULL
        },
        {
            0x401B9B60134BAD2EULL, 0xC0B12CB7A50C8367ULL, 0x60663BC343199DE8ULL, 0x2935927337BFEF05ULL, 
            0x42DB1F55E7C3E740ULL, 0x7908B4673D6240FDULL, 0xF9C35BF8AD4C95F4ULL, 0x45F67A3BEBD53912ULL, 
            0xF8EA696D1ED2601BULL, 0x3782E4473D590781ULL, 0x33F9441276716297ULL, 0xE163C50B70721B6AULL, 
            0xDB7A4121675AFE4BULL, 0xAA7BAA89DA623A00ULL, 0xCBD60E2CAB24998FULL, 0x219401010DA38400ULL, 
            0x3F10F705611867AAULL, 0x054F248B61191838ULL, 0x2940EA2FF22365B9ULL, 0x4054C37FBCCDF1EAULL, 
            0x5CAA8D9DABB065D7ULL, 0xACFC53DF278AA3BFULL, 0x1B4114DA3FA106E2ULL, 0x9213090B9AB54455ULL, 
            0xAC79C3761ADA6313ULL, 0xE9D93E3B9F70EF52ULL, 0xB28733461C727C36ULL, 0xEC5946F6FB274B6FULL, 
            0x49A99646E298A85AULL, 0xB97B67959D11A13CULL, 0x820AE35B2014F61AULL, 0x5B369F894D63A5E3ULL
        }
    },
    {
        {
            0xDADFA7D0B9E01729ULL, 0x61B844BFAA7CCFA6ULL, 0xD7998A333338B4F0ULL, 0xDA0BFF280C38239BULL, 
            0xF30A75C801D04E9AULL, 0x9B91BEDEFCBB6E87ULL, 0xF18C7ED6D12D6E4BULL, 0x3CD13961F1E40D5FULL, 
            0x5AB12E0F22EFB86EULL, 0x9AE0A175DD833667ULL, 0x0BB45A7D401B0419ULL, 0x536DEBBDC67EABD5ULL, 
            0x4A2FB9E4210C5BE6ULL, 0xBCB18912868BA92AULL, 0x08ABC666BD186B98ULL, 0xD420CD2B78343A44ULL, 
            0x647FF1D7A82E2330ULL, 0x9E867E25CC7837FFULL, 0x303B377D850E6CA6ULL, 0xB7302329AFAC0E6BULL, 
            0x733DF9771FAAE4DAULL, 0x1541165700B8ACEAULL, 0xAACD184FE6A47974ULL, 0x45AEB4ACD53DB225ULL, 
            0x7BEECD5E227618C2ULL, 0xFD904E775D5FEB3CULL, 0xF779C7BC0BE9439AULL, 0x9801E2CF071AB8A6ULL, 
            0xB10584E51C5E4C3CULL, 0x1F6287BF0DFF8E3AULL, 0xFE70E5DAC17527B1ULL, 0xA625A13DC973221CULL
        },
        {
            0x272931102FFF0C34ULL, 0x91357E9926EF8C4FULL, 0x1DEA3394FDD458F1ULL, 0xEB21838109E686C1ULL, 
            0xBE1A1AF919F591C0ULL, 0x5173B874732E9FECULL, 0x69F56E901B064E13ULL, 0x32D3C5B942EBC9E2ULL, 
            0x63184AEA99F61226ULL, 0xFF0F68C4FBBDC0D3ULL, 0x2167DCAA6D2A3AA2ULL, 0xACCC85A5C57C7070ULL, 
            0xE842BC215FBB7FDAULL, 0xDD5E0B58D6D2425DULL, 0x2C5019A41199BD40ULL, 0x3B48FF6317908C5EULL, 
            0x345B11007437A5B4ULL, 0x2E72F4B848A2864AULL, 0xA2137BA38856EB12ULL, 0x443DC075C71EAFEAULL, 
            0xDAAD8CB6AC2763BEULL, 0x9F5BBA9C35626E20ULL, 0x899B98F0F8D92100ULL, 0xFAFEFCDF73E02ADEULL, 
            0xA24AB3EA353451D3ULL, 0xDCEFB5886BB9FCCFULL, 0x600B1F0567F66988ULL, 0x003C6AA1AE024389ULL, 
            0x5CE8953D93B33D7AULL, 0x800F805AEB14B7E1ULL, 0xE849293B7DF627DAULL, 0x004E6F179374AFC2ULL
        },
        {
            0xF4EBE446850EFBEBULL, 0x1FEE68A6FE5747F8ULL, 0x7BE0EB6CA8DAB5BEULL, 0x556C5EECF1DAA303ULL, 
            0x58319CB344023A5DULL, 0xF9DA82A56D8555F0ULL, 0x9B0D4F73A71E186BULL, 0x4BB2C08D74423513ULL, 
            0xEA300D88446B4C94ULL, 0x47444EEF0E595B6FULL, 0x73FBD2074A6DEA9EULL, 0x371783DAE36C05D7ULL, 
            0x18AB18011A14C677ULL, 0xA8FDB22D70D57F03ULL, 0xDCE213C44E05C125ULL, 0xDE034808CF9DDD2EULL, 
            0xEA731B9D7DD5D753ULL, 0x1EC13BC31EECA58FULL, 0xD0C1F5FFD9189EB0ULL, 0xBA4B263657787AA3ULL, 
            0xB9C06903AF6D2962ULL, 0xC7668BD79C5444A1ULL, 0x234A2F782F71944CULL, 0xF5CC086600F1C282ULL, 
            0x473C1B83E37EDBB8ULL, 0xC62FBB27EF4EED91ULL, 0xB2C3B7F6ACA9EA8CULL, 0x618FF488856EF99CULL, 
            0x4724FC5DBAC6B2E5ULL, 0xEA5098EA34FADD73ULL, 0x33FC8CB007C0D92BULL, 0x3BFF4D4F8D9A91A5ULL
        },
        {
            0x248992B90DF6626CULL, 0xA474679827F2BFF7ULL, 0xC9119F07F546DE68ULL, 0x18BA23F29333F19CULL, 
            0x8819AD231F37C6F7ULL, 0x689FDC24B01FE938ULL, 0x46FAE51F82E7C826ULL, 0x4C4D205885ED275FULL, 
            0x450E613D37CDAD85ULL, 0xE0EBD16D6D7ADCFCULL, 0x8885328DF87E9786ULL, 0x348C5CE63CD3CDCEULL, 
            0x370CE9DDDF02CA77ULL, 0xF2C7BFB901057704ULL, 0xF191FFC264E81324ULL, 0x38D2A2988E380483ULL, 
            0x5AD1D6074E4686C3ULL, 0xE42EFEA6989B5224ULL, 0xDCA452AE7F96B29AULL, 0x631A712B20C325E0ULL, 
            0xAAA795D3749E721CULL, 0x38061785A9EE19E4ULL, 0x4D84DAFFADB5ACB2ULL, 0xCE5C57121E02179BULL, 
            0xAC79D040CAD07ACBULL, 0x6A19FBD15D263C94ULL, 0x2EC823E164A2862EULL, 0xDE5E3DDCC363EC7AULL, 
            0x91F3182B9D045C86ULL, 0xD641680BA17598FFULL, 0x59B6568760D9A0A3ULL, 0x87EDBD199924DC63ULL
        },
        {
            0xBB08F6B217A91523ULL, 0xDC75289AE4FABCFFULL, 0x25C310014C073114ULL, 0xE67E8AFD0FE1792AULL, 
            0x9B7C16E71913F2F5ULL, 0xF466F31D2C4C9D1CULL, 0xCF1689CAADAD1DF2ULL, 0x4058B1182AD39885ULL, 
            0x0DE8668796B26B68ULL, 0xB385B5A23160F0C0ULL, 0x7EEEFE70400338E7ULL, 0xC0EA1E9302E50605ULL, 
            0x15D7C9D17037E6D8ULL, 0xD29236DF9E5E634EULL, 0x4991641237D35BE7ULL, 0x33C64E94B4703141ULL, 
            0x75D6C06E1CA9A039ULL, 0xFB943A82F04F2620ULL, 0x6091721C65C066EBULL, 0x42D41A024E07A96BULL, 
            0x1684C3A91B54E061ULL, 0xEA5648A71F965CDAULL, 0x0508F750625EC021ULL, 0xB683098BC9CD8A03ULL, 
            0xA020A77AFCFA5548ULL, 0xBC8BF92BEEC23F33ULL, 0x59AD0084B01768F0ULL, 0x4C8C3CB43BA4AA04ULL, 
            0x033FB61DF7135989ULL, 0xB5FC2AD06A9B90C7ULL, 0x2A230E4D4F6FFD23ULL, 0xE9929AD29F8C4D71ULL
        },
        {
            0xC79D3F65B33ED6EFULL, 0x3A36C68F6B777629ULL, 0x874B727FF635D4E5ULL, 0x4F413C24EC3EB578ULL, 
            0xBA633DB22BA1F919ULL, 0x864F6FB9F1B31880ULL, 0xCDD237C505B8C092ULL, 0xFC7E8CF115519346ULL, 
            0xDCC02F3A3D1423ACULL, 0xCD7D5B889297C4FAULL, 0x98E465D731D636CEULL, 0xC937D0DF565FE4FEULL, 
            0x4ECA23FD382248F1ULL, 0x926989375532AB2FULL, 0xD545D99940118590ULL, 0x0FEC40601129E5D5ULL, 
            0x52E32910F0CF624EULL, 0x3D889F4D842E5320ULL, 0xE22040E41FFF06CAULL, 0xA996F80F1AFAB515ULL, 
            0xC2B4CF9E9E5B7F13ULL, 0x224AADACDF7E09B1ULL, 0x198666EDDB73767AULL, 0x95F4D689F8B61F0CULL, 
            0x11675A89981D9C5AULL, 0x3E00DA8946AB2CFDULL, 0x63F8B04035B09D5FULL, 0xCB5E631976EB96C1ULL, 
            0xCD915460935377FAULL, 0x98C2E259F1329AC2ULL, 0xD96601B56D55D3B6ULL, 0xBC9A068413D5FE2CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeySpawnConstants = {
    0x5AFFEE3E27B3D19AULL,
    0x312A358327B60D43ULL,
    0x2D0465127FC56631ULL,
    0x5AFFEE3E27B3D19AULL,
    0x312A358327B60D43ULL,
    0x2D0465127FC56631ULL,
    0xBB049320931C07EFULL,
    0xFD2034E192270061ULL,
    0x9A,
    0xDB,
    0x05,
    0x31,
    0x02,
    0xBC,
    0x9A,
    0xA0
};

const TwistDomainSaltSet TwistExpander_Rigel::kSeedSalts = {
    {
        {
            0x1691938A7CF46640ULL, 0x20DD4FE8C0CB345BULL, 0x730F8F0DCAA28614ULL, 0xE1AC557D4660FA27ULL, 
            0xCD9A3800CB79F1D9ULL, 0xA6190618786D2098ULL, 0x800865E5C364C7D1ULL, 0x3833C308C2180BF2ULL, 
            0xE34EB9D6579B3DA9ULL, 0xB78BD65D8499F803ULL, 0xA4ECBAC3D0F3035DULL, 0xE32DF0CE96D3EC76ULL, 
            0x3578364FCC7DAEA3ULL, 0x0D39C63652A73947ULL, 0x7F6EE031F7895700ULL, 0x17B7FC0B624EBAA0ULL, 
            0xE69910B4CF646450ULL, 0xF6F808816EAA06E6ULL, 0x024FB6D9A1B273F2ULL, 0xA91AA3712252ACD6ULL, 
            0x5BAEC5BCEFC56625ULL, 0x21DC4E35198330B9ULL, 0x0DFEFF4E7F369E4EULL, 0x2228EF822F9615C2ULL, 
            0xFAB361A0C7FC5E85ULL, 0x578529F81FEA118AULL, 0xA8880DA92D0AB0E3ULL, 0xD8552F300B7A71B1ULL, 
            0xA408503F1C460E32ULL, 0x00E4F03B750B2769ULL, 0x25436B52B60AFCD3ULL, 0x8EC2158494C633CEULL
        },
        {
            0x52ACCA6C54F03B66ULL, 0x20B2A05C1A28322EULL, 0x0DD1220D96385E03ULL, 0xD56ADA6767DC5338ULL, 
            0xB773E354997C4C3FULL, 0x052BD8A9DE01546DULL, 0xA2D69CED891DC5BBULL, 0xC5565FEA2B20475CULL, 
            0x8DDCC252BB036BA9ULL, 0x9DFD8106DE46E697ULL, 0xA8CE5B0A957BEA97ULL, 0xEB6A9F74214DB4E5ULL, 
            0xA8E32D5DFA637C0CULL, 0xC0B00D5586B34757ULL, 0x0AECE1F6383EA080ULL, 0x1152B42D24F9BA98ULL, 
            0xB8C72FE5C63601FDULL, 0xCA4E07650B95BF6EULL, 0xD6160F76AA88723CULL, 0xA633ED205C3FE24FULL, 
            0xD8779E1C13DF3047ULL, 0x5DBB9CFEF61112DCULL, 0x5D929C6AECB5A38DULL, 0xFA4D844FBF4BC194ULL, 
            0x92D3D85532749775ULL, 0x8E87BB49BB783FE9ULL, 0xC9A284C10C1B466CULL, 0xAEFE23985C40D50AULL, 
            0x76DF10F47BCD78A0ULL, 0xB08B87734599D5FBULL, 0xBDF80023869A4410ULL, 0xCAF8F0C947F0BCE7ULL
        },
        {
            0x99ACA5899E20D24DULL, 0x6D6CE27339F50DFFULL, 0xB0849338F9C530C6ULL, 0x480571415CB25FA5ULL, 
            0xEF6392D1B3D4BCDFULL, 0x05DA1DA899B01240ULL, 0x23734D3E11F89942ULL, 0xA4781BC5C41AA038ULL, 
            0x62EA06EE46E4A7D1ULL, 0xECDD2D99445C1F85ULL, 0xBF6482FB98E6285BULL, 0x3F7E8D729A12C04CULL, 
            0x1AC4A5191B118D6CULL, 0x6B0B6744BF77903CULL, 0xF09087DE843AAA20ULL, 0xA298BAA539281D06ULL, 
            0x6448B5A9C639E555ULL, 0xA8001FF2288E0382ULL, 0x1CD1D2BBF5D8F50BULL, 0x385EF287ECBB88F2ULL, 
            0x9E328DF9D696639DULL, 0x6468819AFE6C869CULL, 0xAF600D0C767B1801ULL, 0x9530DAFD63D30D1BULL, 
            0xF928E31C4EDA3861ULL, 0xB9A4C613DB20806FULL, 0x09B0AB31FDC18739ULL, 0x1E2F7D70292D63BDULL, 
            0xA9938D66307ADD94ULL, 0x3CE337289CA9CBA5ULL, 0x536FD47C3BCDFF35ULL, 0x9990C3D4CD529863ULL
        },
        {
            0x41DC533BD61CCE85ULL, 0x70A879E3124CD686ULL, 0x96994FF030A7C10AULL, 0x74FBCE6876254BDDULL, 
            0xC32426E7DE6EDA2FULL, 0x2B534490B5F9E531ULL, 0xE84080595B9D05C2ULL, 0x3BFBD206B8623601ULL, 
            0x64B281597E23B7F8ULL, 0x7307AD82D9A1EDB3ULL, 0xFF39E30661DEA31CULL, 0x7CF2884636E74911ULL, 
            0x4E81CB0D7E79B547ULL, 0x3187952D913FE367ULL, 0x91315B5B6FBB36EFULL, 0xB27F983A4822FF7BULL, 
            0x7BBBDDD581592ED9ULL, 0x41B1D01868AC93CAULL, 0x5EA47FAD9E8FA852ULL, 0xA553610212FC9805ULL, 
            0xDC4FA1D905DB9415ULL, 0xAF7A4B346AF8DDC1ULL, 0x1A7CAEBCAC54E1B1ULL, 0xCB4AF96E81BDA95BULL, 
            0x2F3594D16A067560ULL, 0xAF6F160732ADDB92ULL, 0x955B4FB9EECFBC75ULL, 0xEC6D3DDCDE5D9989ULL, 
            0x0EC59A16373E8B4EULL, 0x3775EEA4611EF348ULL, 0x97BF3B04E13A0D93ULL, 0xBB0FAB35267A1068ULL
        },
        {
            0xD09E1B1DD2BBFC8AULL, 0xD5B675C9E801E8BCULL, 0xB8238469D19BFCA7ULL, 0x1B87524503D6264AULL, 
            0x45495546BABFFF54ULL, 0x9740B1F7B137B91EULL, 0x663BE637E57DE37FULL, 0x7BD5FBC4BB4814ADULL, 
            0xE60EDA64BE0C04FFULL, 0x41B0D736CFC9CA45ULL, 0x96C9D7AEB3B4B2C8ULL, 0x19330F834542B307ULL, 
            0xDFFF9C91D35C64FAULL, 0x504C7BB4EC195152ULL, 0x63D6716DE8389496ULL, 0x61A26EAF978B6482ULL, 
            0xCC1C2E03628EA057ULL, 0x7F43720A3C5C243BULL, 0x56C228043A1CF780ULL, 0x72ED68BE6189203FULL, 
            0x2D9E10E6BB19E05EULL, 0x339668861231F25BULL, 0x314DAEA4E722F1F7ULL, 0x43DBF4EE7539388AULL, 
            0x35170D185F1B12BEULL, 0x5E4AF605FA65FE0DULL, 0xD4D75D8B817AFBD9ULL, 0x405D540ABE49E948ULL, 
            0x4E436171D8B8A441ULL, 0x14FA82C2A26B19F4ULL, 0xE48866529D277B47ULL, 0xB650F04287BECE48ULL
        },
        {
            0xAEEFD930B3305DFFULL, 0xA8E66DBE49675DB4ULL, 0xD22DFCE30482A84BULL, 0x1DFC9911C97DBA24ULL, 
            0xD27A3D5D3948AE85ULL, 0x93FAD5BA9A835A40ULL, 0x6F695404B3B8C1B2ULL, 0xD1A07321B0DAB84FULL, 
            0xE99AC2BDABF3A018ULL, 0x059EA233FCD7A222ULL, 0x582F74B72D19C1ACULL, 0xE50C1324C2613A3BULL, 
            0xACFF80B1D8A3BECEULL, 0xEFD8E702360FF6E9ULL, 0x53049C5BF5C7A910ULL, 0xB3C58716356C622BULL, 
            0x34C4CB86DA700C69ULL, 0xB889CA6E48A1012DULL, 0x60EB281605E6FE9EULL, 0x30160C086AF0ABBEULL, 
            0xA100B2A29E6D9502ULL, 0x1191B8BC19AF11A9ULL, 0x2703BE76CEB9856FULL, 0x2A972BA909E6751CULL, 
            0x53158E991C466CDEULL, 0xEBCD2C5A55884E90ULL, 0xC5567E67CF5B9DB2ULL, 0x19055F3E8A4B5259ULL, 
            0x5509FF1D7926A61EULL, 0xBD9671358FD34558ULL, 0x7DD8F487A89B46CDULL, 0xAF5E7AE5B643811DULL
        }
    },
    {
        {
            0xBFAE98FC4054C826ULL, 0xB078BA8823FAE2DFULL, 0x7399109F3640459CULL, 0x26D172CDC9318E91ULL, 
            0x02E73F06788075E2ULL, 0xCB549625D077E1E2ULL, 0x4E580E0F1A7D113BULL, 0x26EF6E41B4693F68ULL, 
            0x97AFD086A3E7B53AULL, 0xD46D650C0DB6AA28ULL, 0x5B0F9A1311FEEFF1ULL, 0x7544EF3E3ADB1FA2ULL, 
            0x0BE7182C7C33F2DBULL, 0x632EE5F3205BE776ULL, 0x0FE9D08E6275F501ULL, 0x17E90C9125FE07D4ULL, 
            0x5AA1F718C6F53ADCULL, 0x6978E1616D97ABE3ULL, 0x685DEA8EDF25DD3BULL, 0xC11969287AEFA6FFULL, 
            0xB810A34A73393CE2ULL, 0xD00A2818E221A5CBULL, 0x69E4C286DC1DCD37ULL, 0xB3F7FBDFB7C41401ULL, 
            0xE33258F2793000D1ULL, 0x228D7D03BC9B70DDULL, 0x12861C456580FCA1ULL, 0x7FBFF588BE6A2232ULL, 
            0x14DBFDB390BF3A5BULL, 0xE3E3EE4A0D728360ULL, 0x24C41D18D8D472E8ULL, 0xAD185E019F262332ULL
        },
        {
            0xBCF0E14CBCFCF7E0ULL, 0x34C247E5C0A03E49ULL, 0xB8DD201C6620809EULL, 0x35F2136B395ADBC5ULL, 
            0xBA4CD81022E98F68ULL, 0x57190021C83BF03EULL, 0xD5D956385D904C4BULL, 0x16A8FEBF8C4D0EE4ULL, 
            0x1F6AB71FE8E0F735ULL, 0xC72C075F1C931929ULL, 0x980A456DC2C99FA9ULL, 0xF9B88AD66D4958E3ULL, 
            0x32650295D4209B13ULL, 0xF8FA67E009F2610CULL, 0x66BD18CA7A1C5D42ULL, 0x52C921AA29116483ULL, 
            0x3E520423AECDE533ULL, 0x39C3BE37C4C54240ULL, 0x9620FBC3D4168ABBULL, 0xDAC7206F50DAB91EULL, 
            0x8A2EA6C3FC3AF452ULL, 0x63BD10AB3DEAE108ULL, 0x8E28046E519A95FDULL, 0xC704B6C605BF4DFEULL, 
            0xB4911C04A7B27E4FULL, 0xD55613F7CAB73518ULL, 0xD95522C557251F40ULL, 0xCCD3EE46F868914DULL, 
            0xA38B019B9CC57F04ULL, 0xFDFED1D9F0C4F2A4ULL, 0x15375CEBF999FE06ULL, 0xE65709DE495D3A54ULL
        },
        {
            0x118DCE97A0D65F2CULL, 0xDA94F29421E874A8ULL, 0xC8E4D39179C027C8ULL, 0xADFEB811EF547935ULL, 
            0x502D0D3623735C5CULL, 0x9C348F9DE3B9EEEFULL, 0xEBE29FE92DB7FE78ULL, 0x010842EE09674175ULL, 
            0x899894A69A2DEF10ULL, 0x2850F814F706D56BULL, 0x822BA2F0DAB10375ULL, 0xC41024B05C79B801ULL, 
            0x75F5170E1E520E43ULL, 0x332F79B5821E0796ULL, 0xDF1D51EA5C3361EAULL, 0x307173759AC2AB31ULL, 
            0xDD16DFA3264DD740ULL, 0x0174AE616727B47BULL, 0xC0A5C6B87A15B98FULL, 0x3DB091189A06A9D6ULL, 
            0x1E8799036D94A113ULL, 0x933A71D48E862D21ULL, 0x609CE98C2984C055ULL, 0xDD1DF63DF2934BE1ULL, 
            0xBF438E70A671A774ULL, 0x56B7146869212DDAULL, 0x316CFED7036F530EULL, 0xD4DF073FD555811BULL, 
            0x74DC73FACA8B899FULL, 0xB1CC76AF3AF907ABULL, 0x0F7D60E41455AB37ULL, 0x5ADB707C15FEFD93ULL
        },
        {
            0xF94CD3141A5B0821ULL, 0xA249AE6FFBD62B43ULL, 0x809FB4EDFC32CB3CULL, 0x247FAB9A501E3338ULL, 
            0x378FB78C1926407AULL, 0x756DA421CA78B036ULL, 0xBFF81072C6F0BEE7ULL, 0x5715D9E9B6030861ULL, 
            0x202D40BBE3F14C5EULL, 0x51441641C2F2CDE7ULL, 0xC5796F7FF10FC50AULL, 0x78E46A573B993BA1ULL, 
            0x0002D83F8C69752CULL, 0xA89FFA00829B66AAULL, 0x25031F8A62462881ULL, 0x39ED057DAF2746ECULL, 
            0xE918AEBE371B183DULL, 0xED1B850D3D578B63ULL, 0x5087C80540663E17ULL, 0x19ECD11BCC5F7A0EULL, 
            0xF26F89B48D466978ULL, 0x16C17FCC1BA2E607ULL, 0xC01E32B7DBEBC801ULL, 0x77EA85750336CA69ULL, 
            0xD5B99D88F1EE0DC0ULL, 0x6C3EB486C9809C92ULL, 0xB17831C379F697C5ULL, 0xFFD9080E7C387500ULL, 
            0xC6DCD19F55D1F6E3ULL, 0xD9F9C02EEDE2D98FULL, 0xF82CF9D0F5BA88A3ULL, 0x7EC9791DF4D831CCULL
        },
        {
            0xB62C0BEE834BC700ULL, 0x87E6A1A8C7927C48ULL, 0x610277A9060FE54BULL, 0xB06BB4FD0DC7E604ULL, 
            0x9FCCCB660A50BDFFULL, 0x2527A3C12BF5BAD5ULL, 0x9F2F3E60A4BBE684ULL, 0x153771D1DEE86BB2ULL, 
            0xA271418C879F9323ULL, 0xDAC51549B8D3FA78ULL, 0x70F4C1FE2187ED3FULL, 0x8BDD85BCB2DE5E6BULL, 
            0xA42A9D5E11430ADFULL, 0xFA1F898A2111E4E8ULL, 0x3285E2CBD03E6975ULL, 0xDE1ADAA08D5BDF98ULL, 
            0xD37A9A156B0B5660ULL, 0xCB1D7763D8C966A2ULL, 0xA4E1F66BF4BA20B3ULL, 0x2956B814B7C20169ULL, 
            0xEF3036599E10EB47ULL, 0xD3E5437F32D31262ULL, 0xAF867421A73D4B3DULL, 0x5CD3F0D79CC43B73ULL, 
            0x6CF67F32A0619C7BULL, 0x62F051158F3EFBE2ULL, 0xCF77318D0CCF6AB3ULL, 0x0E71F09156F45C44ULL, 
            0x0B40A199B51140DFULL, 0x466004BD4A2F3D55ULL, 0xBE4E3C877B3AEC9EULL, 0x8D7FC9197F60D91DULL
        },
        {
            0x158FACCD437F931FULL, 0xD0FBDD74A7D83987ULL, 0x702B7EDE71A5C076ULL, 0x40073B5AB358F10BULL, 
            0x37D00B5DE24F9871ULL, 0x529AA5D65F9B8077ULL, 0x84685908EC6A2442ULL, 0x425E2B0877384033ULL, 
            0xF148C30CEF64605FULL, 0x4AFAF3DEB0D8152CULL, 0xF93E0F69A0BEC657ULL, 0x38494BA9E9459CB7ULL, 
            0xC1FB3E1B3094EC7FULL, 0xC79A199592A14366ULL, 0x9E1E864C3974AD7BULL, 0x1C9C3C09E2371D36ULL, 
            0xA9C1D8FA400272BFULL, 0xEE335CA4BDCC5EB1ULL, 0xB02F5DD334CE78BAULL, 0xF3985314F7C496A4ULL, 
            0x351F512939CCB40BULL, 0x3B3794B910A34407ULL, 0xF7977F0B2C974679ULL, 0xC49EB31999748890ULL, 
            0x765E808A1EE2BB89ULL, 0x1143F63CB72BFEBAULL, 0xF36E632554CFA989ULL, 0xED7EBFD1C3527374ULL, 
            0x9EEC3BFA20EEBA3FULL, 0x5B342773EAE4E2EDULL, 0xA685BAADEA263F48ULL, 0x355C03D936CD43FFULL
        }
    },
    {
        {
            0x217533EDFB914D28ULL, 0xD3524576C9F9A588ULL, 0x48DAA55FF549647FULL, 0x4AA8A353E1AA8B39ULL, 
            0xE42FFB7181A6C292ULL, 0x3D21884F9DBB89E5ULL, 0xA072E58B00D2D64BULL, 0x74D81AA3E95A2BEEULL, 
            0x35CE9BAF6B260FA8ULL, 0x7FECC705488F92F3ULL, 0xA5EE494C1F63FF0FULL, 0x50E89525B5B76FB4ULL, 
            0x771E9D6771E9D79DULL, 0x8B9A44BC78B8145CULL, 0x91DD9476E5E80AB1ULL, 0xA0F0E61BFA647194ULL, 
            0xCD4014008966C29DULL, 0x2B45B40CEDB6C4F7ULL, 0x5BFB9C6FF0FDD60EULL, 0xAC7652F27843CC7CULL, 
            0x58EDD6894F4B3A27ULL, 0x09ED49C965BC6A1BULL, 0x57B5EDB674838443ULL, 0xA1ABF68C9EC75FB1ULL, 
            0x25EA8DB037035DC0ULL, 0x74593BE82602E22BULL, 0x2AAC45E886002C39ULL, 0xB79E1A6CA0057344ULL, 
            0x7126574CEE899857ULL, 0xC4AE676A66BFFA94ULL, 0x67F1722F0038D5D2ULL, 0x5A84A235C4597C74ULL
        },
        {
            0x7D3FD1F3EB9DBB36ULL, 0xDC016BE4244F232CULL, 0xD8DFEC84B7015758ULL, 0x90198D421F1B0D36ULL, 
            0x61214771EA95BFBFULL, 0xF87B9705873230D6ULL, 0xC9E2EEBA5F030829ULL, 0x9136E89D40E88243ULL, 
            0x952A1364BC8CAAC0ULL, 0xF3E33B86185C1D0CULL, 0xDCAD3E66F938D052ULL, 0x7CE97077435F4AFDULL, 
            0xDFECDDEE50A6DCFBULL, 0x8D42B09E5BFE81C4ULL, 0xC36655897B1F4EA8ULL, 0x0A7B81C6C261C141ULL, 
            0x39E8CDF1D399FB19ULL, 0x295448A4D54EFB14ULL, 0x17C65D05EC70BEA6ULL, 0x4FE6C1E7866AECBCULL, 
            0xDCCAACCB385C7AB1ULL, 0x3B06315A0BDBCD8DULL, 0x195C6421F3357E46ULL, 0x50AAE0745F0BCC4BULL, 
            0x041E685AD27C505CULL, 0x2D25EFCA4C5B0BB1ULL, 0xEA64F146D2E716A2ULL, 0x041D69047FF16C26ULL, 
            0x4B1EB00D4AFA303FULL, 0xD99D26BB4C932669ULL, 0xF9F4DE040E479698ULL, 0x5368598141E5DEF3ULL
        },
        {
            0xF6F14F9F7064A412ULL, 0x15F807CC58AC2F6BULL, 0xA96F40E6F58C6E17ULL, 0x27B34BA34145DB86ULL, 
            0x5588C903ED55397BULL, 0xB3B0EA8C7920A780ULL, 0x51462EFF5D641137ULL, 0xEADAF33F18347240ULL, 
            0x3E9624270663D376ULL, 0x8D11C8AE44C78359ULL, 0x44612D005E78FEB1ULL, 0xA940BEBE92E53D0DULL, 
            0x543D86D60B7C16E6ULL, 0xC7D37F564C2AC83DULL, 0xF95FD59DE386D5E0ULL, 0x12BF98EF56A9CBD6ULL, 
            0x4E594C8EC61CCB40ULL, 0xDAE6D48667CD9BA7ULL, 0x6315E0A1A04E238FULL, 0xC1E343C57D265EE8ULL, 
            0xA7BD60EF9D85333EULL, 0x2D85BEB1983DE972ULL, 0x50F0B45B2A64DDF2ULL, 0x57E3BC52AACD6B60ULL, 
            0xECA302B30290CCE5ULL, 0x98CF0C4199D359DEULL, 0xF9A3DFCF20994B2EULL, 0x84A708B5D6024ECAULL, 
            0x6420311A79513035ULL, 0xD1D98E2EBB7E92B5ULL, 0xF8EF2D3C8762FC84ULL, 0x118CA88D46F5CB99ULL
        },
        {
            0x9BB1FD0D57D265CAULL, 0x8B423FE7A4D05501ULL, 0xD9ED804EEFB7B34FULL, 0x6B6E0F0E74CEA3C8ULL, 
            0x643CFEFEF5AC5D0BULL, 0xE9ECB985B753CEDEULL, 0x26D57BEEB21B53AEULL, 0x3EFDE0A8DE334C54ULL, 
            0x9041E1E7B20CCFC0ULL, 0x62CF88FFA3B32F7AULL, 0x6656C4194BC87ED4ULL, 0xCD2EC0E8AB8166FFULL, 
            0x7DB164112B069F90ULL, 0x2B18A7D478BFBD48ULL, 0x8B0309DC045C09DDULL, 0x4C2FB9EDC34DE485ULL, 
            0x294AAA63B7E5D27FULL, 0x08D231FF27845B97ULL, 0xA73B2D2114BEE87CULL, 0xF26D766F5EAE3279ULL, 
            0xA591CD8C61322809ULL, 0xDEB300A6DAAD2DD2ULL, 0x8C5ACD71DDEBEE6FULL, 0xD71C95058FD661DDULL, 
            0x4C034A22B82F529FULL, 0x9EC501659674B5B9ULL, 0xE8FE6387B3C1D2B3ULL, 0x05E2C1236FBE087DULL, 
            0x4E40B4633A86F744ULL, 0x85CC1C7B2D5093F3ULL, 0x64D1F4A35D14905EULL, 0xF56BEE0A224CFA11ULL
        },
        {
            0xF81C0A733B7F8698ULL, 0x55756F64B949A587ULL, 0xFADDD5AF4D108B69ULL, 0x8C808D5143005B61ULL, 
            0xBD5F43F7658BC93AULL, 0xAE2856345DD8AE76ULL, 0x4C1892BBD9177A41ULL, 0x80C3995812FBA91AULL, 
            0x92B21E0B83412C9AULL, 0x2F42AE6A67346264ULL, 0x9AFF99DA8F3644ADULL, 0x4C770AC66F0322E6ULL, 
            0xB7B9135A37A126C0ULL, 0x40EE5196C4584BD7ULL, 0x2B43706417B1F010ULL, 0x7C2B85F4D0A970DCULL, 
            0x9458F59FFC9EF388ULL, 0x8D27D664C0F7CB72ULL, 0xCCF19976D29C2164ULL, 0xCBBE5FA510BA5C34ULL, 
            0xB2C68360852D60C1ULL, 0xE028004557CA78A4ULL, 0x4CBB9A6885FB5031ULL, 0x20EF727D5A8FF1D3ULL, 
            0x4CB01FFEAB7558B0ULL, 0x96CE51ABF12AE6D1ULL, 0xBA7F2DA984BADCB4ULL, 0x0479853FCBEA2052ULL, 
            0x6ACCA22B8624158CULL, 0x94E95E8D130731D7ULL, 0x34195DF5E6374381ULL, 0xD8C65254F96A969EULL
        },
        {
            0xD68709ADE2AC1701ULL, 0x7D59B53C29519103ULL, 0xDE8AAAEC12403F0AULL, 0x4672E9736BA4C7FAULL, 
            0x87CB224C3FDA147EULL, 0x2A2B85E3E96794C8ULL, 0x897BC71BCEA261E3ULL, 0xF13A13ABAE173DC8ULL, 
            0x2C64C2046FD5C41EULL, 0x1D47553DAC689C26ULL, 0x705DA0538A99363AULL, 0xA7D9227B317A9A46ULL, 
            0x475514554C6BE68BULL, 0x3F2225803D5A84BCULL, 0x6B9131C0990CEFD9ULL, 0x727832EB20F0173EULL, 
            0x6E354D63DD96870DULL, 0x1E9556C9B2CBC1B8ULL, 0x57C9B0B39C8C2B15ULL, 0xE0682F97CA42048EULL, 
            0xB3AB8CF8EA050F98ULL, 0xD5F29BD698C49B7AULL, 0x0B014E3CC4DA72E7ULL, 0x05E3F7002AE073BBULL, 
            0x3A9F4CAB35345279ULL, 0x3B77A119A16D0B72ULL, 0x85A02AE20F7B25BEULL, 0xA1E2870741CBD1A6ULL, 
            0xAD967D8CFF05EF77ULL, 0x780D714DF3F8EE93ULL, 0xC7EC71627001124AULL, 0xE8B44A100320DAFCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kSeedConstants = {
    0x323EA8C749BEF654ULL,
    0xBF4688A58F45A3F6ULL,
    0x3F02C5B87FD3CB14ULL,
    0x323EA8C749BEF654ULL,
    0xBF4688A58F45A3F6ULL,
    0x3F02C5B87FD3CB14ULL,
    0x0780574BA861BA72ULL,
    0xBF8BB68014D4F40FULL,
    0x67,
    0x53,
    0xB2,
    0x4C,
    0x22,
    0xB7,
    0xAD,
    0x91
};

const TwistDomainSaltSet TwistExpander_Rigel::kTwistSalts = {
    {
        {
            0x2337A8C2524C1800ULL, 0xE09C81AEF711ABA6ULL, 0x085BDD0FA5A4D77BULL, 0x2205E97DCEDCA71CULL, 
            0x8336D40E3B681567ULL, 0x51A661219C341022ULL, 0x6390733CDD20EA63ULL, 0x42E13226A454AF7DULL, 
            0x6CC7A460D0CC655CULL, 0xFCF72512954FA43EULL, 0x7DD61137486988B7ULL, 0xD1964978013CFBBCULL, 
            0xA550B9790BC4DC9FULL, 0x0B82C4E7268B1EC6ULL, 0xB36F025437F8E155ULL, 0xA48330D7A580007BULL, 
            0x174A70A64DF3C2B7ULL, 0x6F4FEA7FF484459DULL, 0x4294ACF2B0F850A4ULL, 0x41499D162AD8B33AULL, 
            0x048A36BB330FA599ULL, 0x88307B4BFB30CD01ULL, 0xEEFF9B678C1924D4ULL, 0x1FB7794B01D401BBULL, 
            0x1C9C8C59120BF736ULL, 0x8DF8C18620BB83D5ULL, 0xFD93720B271BAF93ULL, 0x90776FA8A4CF5230ULL, 
            0x10D5FDAA601336CCULL, 0x0A0B4219F4762D74ULL, 0x98A08DE082F828ABULL, 0xFC716CA34720B167ULL
        },
        {
            0x9B157CE4C15897F4ULL, 0x3B903337C4534D8EULL, 0xA2F977FBB3A0AB75ULL, 0x6746396BC6A40036ULL, 
            0xA76F4E296B873CA3ULL, 0x4A5BFEAE8D033AA1ULL, 0xE9EA595D141EE238ULL, 0x542C7F28E7195C79ULL, 
            0xD88509476E3846EBULL, 0x40ABA20CFBA38F3BULL, 0x4B6E767ACDEA43E0ULL, 0x93D926C2FDE15E27ULL, 
            0x156FFC77E4D0AD4AULL, 0x4A83CF12D94E4B01ULL, 0x0053FB11B56DFA0EULL, 0x6A41318BA990334AULL, 
            0x19D612D7833BE8BEULL, 0x60C5C33200817A9DULL, 0xFDBFBF590EDA5E76ULL, 0x97EC1BAAFEBEB112ULL, 
            0x4228E95A1E70B63DULL, 0x7CA5CCCA728CB926ULL, 0xDC940F922359810DULL, 0xD304125215428B7BULL, 
            0x9D3BDC781A7C0E32ULL, 0x3EEE8DB2F7627688ULL, 0x7357407B4A251840ULL, 0x8C4F8B8ACCB887A9ULL, 
            0x800897CB8D300083ULL, 0x278665EFB09349EBULL, 0x6CBBFBD025F9C8ADULL, 0x2F8D90A78E04F7F2ULL
        },
        {
            0xD3766AC1378A0F96ULL, 0x4EBE4CB9C9395E04ULL, 0x487199FC15C03066ULL, 0x03FDE8611596A9CBULL, 
            0x90D05773C8F0F875ULL, 0x7738BCA56022BD8EULL, 0x15CDCC2882609485ULL, 0xA442AB94EA7A09D0ULL, 
            0x01D512D4E6A6367FULL, 0x610C72951B8C5273ULL, 0x9A4079B145409EECULL, 0x8B404396048534D2ULL, 
            0x58970A0BA87B002AULL, 0xAD82D5AE5E3C4EBAULL, 0xDD8948258750E961ULL, 0x5AA704F2E1D88A01ULL, 
            0x069E2E2AC6241F15ULL, 0x6FB90B5161EAD562ULL, 0x48FC741AC8313C68ULL, 0x3AB63C76B2D9B6A6ULL, 
            0x2449D8BABE4942CAULL, 0x52C3B000442761E2ULL, 0x2DB70851B24A403DULL, 0xFFF6D62D8C597770ULL, 
            0x3AB1E270BB5E0554ULL, 0x52A8D0A9CD52AE65ULL, 0x0DB308AA27C4542FULL, 0xD72E3E42E3905C74ULL, 
            0x739A2A69562DD142ULL, 0xB0A9E846182C2D82ULL, 0x102D059554BBF43FULL, 0xA5C0761B42072455ULL
        },
        {
            0x2D0A484D19D3F2DCULL, 0x61D27C469EB2328CULL, 0x8D53F6C87D6D4897ULL, 0x18C1CF053D55A699ULL, 
            0x0F2738E09F15A41DULL, 0xBCF76A796D301EF6ULL, 0x7FBA56DF0BC7E6AAULL, 0x6A59ABA8A166823CULL, 
            0xF002C97078AEAAA1ULL, 0xB77AE023F0A30964ULL, 0x59E7CDEE779321DFULL, 0x364922496C9325B9ULL, 
            0x52BE9E783902B615ULL, 0xA848BD11334C4BA4ULL, 0xE11C3B2C25C5DB8FULL, 0x16B2EE20DA2F02F9ULL, 
            0x22B26DEC620D63F4ULL, 0x37E14C198A311920ULL, 0xD055254017D4A7F5ULL, 0x131344BDD5451B4BULL, 
            0x31128751A9331B9CULL, 0xE64DD61F3811DBD5ULL, 0xA70A82A509831C25ULL, 0x753AE675FC58121CULL, 
            0xDFD2CBA3474368CBULL, 0xA72B89831234ED0DULL, 0x6425768C24BD5ACDULL, 0xA6CFF7300C35BD94ULL, 
            0x35A5BD05A6C807AFULL, 0x5B102687BEC72FFDULL, 0x512719F65529897EULL, 0xE84B6FD018951A9BULL
        },
        {
            0x93D98DF463A17367ULL, 0x4702DA02AD2B8DD9ULL, 0xE8EE31328BB1E7E0ULL, 0xEB87A754B4CFC349ULL, 
            0x90DC2ECE63AD1555ULL, 0x0A8D150CED499DD8ULL, 0x16F18E4512F3D60EULL, 0xC96E8250B2D52E02ULL, 
            0xE8A024B99DE66195ULL, 0x0E7EB8D0EC403386ULL, 0x59492D54611DA2A9ULL, 0x6ED357D7A9EA5560ULL, 
            0xAD6F9958DF38E69BULL, 0x4F37E1574B18B3F3ULL, 0x87F8E46F60587F31ULL, 0xC3C3C17BACA7558CULL, 
            0x26C27F997186E7B7ULL, 0x7801F7C5AE02EDC9ULL, 0xA65BF9ACB94D93CEULL, 0x7EB593CC6DAE91C3ULL, 
            0x8B445C07F9688366ULL, 0xFEC35513CC51756DULL, 0x054FFA36E5D226E5ULL, 0xBF2E9DD375EB700BULL, 
            0x422E2F62E12B5C61ULL, 0x83C4D12C42265E52ULL, 0x5628C43E162C2AF8ULL, 0x03CDD6902AD09957ULL, 
            0x43098AF4574BD312ULL, 0xA0FC4066FBF64674ULL, 0x81B40EB1347D81C7ULL, 0x4B0E6F52B60238C1ULL
        },
        {
            0x90EC092036736D67ULL, 0xEFD9D0E5E976C35FULL, 0xF88B82E407D8F60FULL, 0xE24AE5AE2F2D0EFDULL, 
            0xD59B5E57C754BCDEULL, 0x7D87D3B51222CF08ULL, 0xC24EBA115E31335EULL, 0x726A0F1CAA50F731ULL, 
            0x42FDF89847524EFAULL, 0x94EAC8B938B3B4ADULL, 0xB9395C43E5A3A73FULL, 0xD454F3AB5D9A1EE4ULL, 
            0xB9035FEF7781556DULL, 0x354174EFA28AA406ULL, 0xD88B9E62F71B5927ULL, 0x99ED52C889E0CC78ULL, 
            0x3A588BB9581C1242ULL, 0x75C98A2000838189ULL, 0x18E96FDBCE953331ULL, 0xF3DCDC61A20CF6A2ULL, 
            0x0EACBA6793BD6212ULL, 0x5BEF14B918E2A48BULL, 0xE85DEC0F7F3B72CBULL, 0xD8A8CBC076585A88ULL, 
            0xBE045293047E737CULL, 0xB19CD843BA020A71ULL, 0xA84237F7B7EFAFB5ULL, 0x1CD4FB8FB04D3757ULL, 
            0x346EF6860DF6AE1AULL, 0xCF3CE13835B5F91EULL, 0x101D28C7C806ED44ULL, 0x662AD3CC9287866AULL
        }
    },
    {
        {
            0xC05E3F44F168D0F5ULL, 0x8DEEF92FBA311DB8ULL, 0x22551006C81F329CULL, 0xCA711E1FE0A3E651ULL, 
            0x7E51CF50635E1825ULL, 0x01AF889637510375ULL, 0x82C5EF9B07C4EF61ULL, 0x2B903DCBCED31F42ULL, 
            0x338BE47094E59D2AULL, 0x54B79505ACAB3E16ULL, 0x781957C312E1A294ULL, 0x1CF38760B8AB95ACULL, 
            0x2B3BAB49CEAA28F0ULL, 0xA8F002A561E2553CULL, 0x379B3165C3063068ULL, 0x7B2A7A625F458619ULL, 
            0xE0779C26CB947274ULL, 0xCD1B9709EA391295ULL, 0xC576D443128EA1D2ULL, 0x967C43A2F398B256ULL, 
            0x0E8EB4E5CFD0B848ULL, 0xDF47380086DD1F1FULL, 0x70F6F31B17796E8CULL, 0xAE928B0F1E82BEC5ULL, 
            0xB9EE4B630510F5F5ULL, 0x579EC86FCB1D7FE6ULL, 0x0777D80B1E09E3D2ULL, 0x2AE885D0ECCE795BULL, 
            0x7141E1DDE04BF28BULL, 0x2EE7B77BE2E31133ULL, 0xAA5AA4743BFE07EDULL, 0x1A7D2D1A857E9DE1ULL
        },
        {
            0x94E0F883F00B5416ULL, 0x1C0B067C306B45DCULL, 0x4DABAC825B52E584ULL, 0x31C1251BDEC5657FULL, 
            0xD4845D2A4661879CULL, 0xE50B6BFE32D3880AULL, 0x3BFDF124B1658EF7ULL, 0x612AA83D92B4FB80ULL, 
            0x16F0DB915EBCFEE0ULL, 0xF74C2EB098B5DFA5ULL, 0x23AE50D8658DA5EAULL, 0x01A1B6B242E3FBDFULL, 
            0x43FF9F6FE4976EDCULL, 0x9D4BDE13CF1EFB8FULL, 0xE5675F26865B2AACULL, 0x8D7289AC4D29F574ULL, 
            0x4987180C5215EEA2ULL, 0x4354E4386555CC48ULL, 0x2DCD894D050315B7ULL, 0xF98D429655E46712ULL, 
            0xD8807BAEEEDE63A3ULL, 0x77EBD72E21C5014BULL, 0x750CD946F5E179A0ULL, 0xA50F58585DC52482ULL, 
            0xB29240B8246C2216ULL, 0x6018CF14923B8791ULL, 0x35C7773B213046C0ULL, 0x4989E701A4A22DC7ULL, 
            0x955B4FD95AD31027ULL, 0xBC162E2C4DB2A9D4ULL, 0xC0FE38F8EE0C3860ULL, 0x76F65418CEF445FFULL
        },
        {
            0x7C61C3E69CD3CE26ULL, 0xACD95756F2A527A6ULL, 0x6277886B8D765A4AULL, 0x6198959BE1E5F2BAULL, 
            0x4CCE4F7B540F3246ULL, 0x85C4F9DA9FD3B7ACULL, 0x0C3ECF96AF9FF88CULL, 0x78C45361DB9A2127ULL, 
            0xDC8BA07B6D5969A7ULL, 0xAB49AAD8E7DC0EC4ULL, 0x1B61D7E2A8727435ULL, 0x0CE43127AEF38E74ULL, 
            0x6D12CB733785CC9DULL, 0xA3DBEB48502A2289ULL, 0x4DB1A97AB06F1A81ULL, 0xA20378B7B4F5E953ULL, 
            0x771378A5C56A8347ULL, 0xA928621B0066EDD7ULL, 0xF23DCA697F6CE402ULL, 0x1DE86FC58F8546EEULL, 
            0x4AE6C3FE2AE2856BULL, 0x569BD9606473CEC3ULL, 0xE0D625D9E84CE456ULL, 0xAB9D40E0B2AC0C0AULL, 
            0x2BDAE45B9A1DE5ECULL, 0x182971EF162DCC3EULL, 0x1C6235A3A516963AULL, 0xF27C5FF256D0D755ULL, 
            0x727B1C74160E31C3ULL, 0xACE024F73F022E47ULL, 0xFFE3808835C260F2ULL, 0x14E5DD7E57878011ULL
        },
        {
            0x702B2057CF11CE0CULL, 0x64F778E52DC82DD7ULL, 0x1FE4676BD45B0FCEULL, 0xF0E5BA1D4864EA87ULL, 
            0x9321DAFC80862C1DULL, 0xE568361ACDC1700FULL, 0x6A9EDEC36A626790ULL, 0x1BF991E0D169D35EULL, 
            0xF8CCD2DA9B7BA376ULL, 0x918ED94C73FBE0E4ULL, 0x375ADB3E4A83EF9FULL, 0x4018CCFAB6BA2CE3ULL, 
            0x575714C32E8F63EAULL, 0x548577E5489D7042ULL, 0x5864926C331C3846ULL, 0xEC30D92783AB962BULL, 
            0xAA805A281B574F9CULL, 0xCA70A5A48C6F66DAULL, 0x120A96D7B25D9A46ULL, 0xA054D745CD6C6207ULL, 
            0xD047BA6BC0589D9FULL, 0xA407227FA5A0AE59ULL, 0x70F0467317164D22ULL, 0x7B8B240F06FB05BAULL, 
            0xE54C137E828ADA86ULL, 0x9B32C26E16549FBEULL, 0x70C65E3CA75F0CEFULL, 0x1FE4B1ED923074CAULL, 
            0xD2BD7DB44F263A2DULL, 0xFB3C2E633B35C27CULL, 0x3C4B7740AFEAA76FULL, 0xFF34F572ACC328C2ULL
        },
        {
            0xB7E1396493882733ULL, 0x76A3F110E77FDC68ULL, 0x45FA98AEC421E1E0ULL, 0xABC345FD48A7BE2DULL, 
            0xED964D4450941656ULL, 0x6E2982CC147F03EDULL, 0x7AE0ED3FCF4ACC3FULL, 0xC9E4D9B0E2AC8CB8ULL, 
            0x95F30D6AD042B0CAULL, 0x8E21B9F54459FC27ULL, 0x9FD46AF7783BBC6EULL, 0x8E9A6FC4916BFA9BULL, 
            0x37ED9DE4D469C7E0ULL, 0xF27827C2CFB8D767ULL, 0x5A28143FDC5950A4ULL, 0x9AB13FAC98470B61ULL, 
            0x62AC6705D944B59FULL, 0x0265436C2B1DE0DFULL, 0x04F7FBF3D905A2AFULL, 0xEDE579E47C1008C7ULL, 
            0xFD4828AD7F55247AULL, 0x05592C54C4E78D58ULL, 0xA53E71AD96AAA20DULL, 0x0CE398951C7BB8ACULL, 
            0x42FABF1BF6AB668AULL, 0xF43FCE121F0FDCF4ULL, 0x0C962E78B0DB1DA9ULL, 0x409516F39379F4C0ULL, 
            0x6BEF17872449EFFFULL, 0xDF03678C4D7298B1ULL, 0xBF967045C48AB5E7ULL, 0x8A007328ADB54DA2ULL
        },
        {
            0x77BE08BB588749EAULL, 0x6155E044992A6117ULL, 0x824D3D3BFA227DD1ULL, 0x14283A284A3C607EULL, 
            0xA8732C29B17A6903ULL, 0x92FF7218E788B519ULL, 0x00D5CBB88E536E9DULL, 0xBC518A13B8195AD4ULL, 
            0xE93F5DFDF11E5D7DULL, 0xA9F52F35FD2940D1ULL, 0x2EF3984FD604060EULL, 0x704ED9B57EF9A598ULL, 
            0x3C5F8AA858B888A8ULL, 0x2C8EE6CE10069647ULL, 0x5C133FEBCB79D6E7ULL, 0xD35CBF0042118C52ULL, 
            0xF5B2951AA7CC178BULL, 0xCAD2C7F3DA71E913ULL, 0xB780EDAF63167F3BULL, 0x36B2E8E57F14A120ULL, 
            0xC530E55BF6742A6FULL, 0x08222869240A1D41ULL, 0x82A9B8530515C2A4ULL, 0xAC2385E692B95A00ULL, 
            0xB6575B17A2C51960ULL, 0xE06F64980FF3CE21ULL, 0x22B32535328BAEE5ULL, 0xF3B8712D8EE2CA61ULL, 
            0x68A6C604006F0E51ULL, 0x66C25B067E06EC91ULL, 0x6B7080EC8C9F84EEULL, 0xABDFFA93A41C07DAULL
        }
    },
    {
        {
            0xA7A8DB44EC432231ULL, 0xF1B14384516AA4C4ULL, 0x6DA27D1727440F84ULL, 0xBC0358FE34F4FA09ULL, 
            0xFDAC00DD7A0E5C87ULL, 0x1149C46D34DD35EBULL, 0xA709A94C74A1FFCDULL, 0x46C8D3EFC0C424F9ULL, 
            0xFB90C484CFBC3F74ULL, 0xDEA802E37EF7E60CULL, 0x898F2165830786DBULL, 0xD6488AFD45D58DCEULL, 
            0x0A679F1C5D77C510ULL, 0xD534FAE8D78D5772ULL, 0xD15FC0C963A7655DULL, 0xD46DCC8DF3F57AD2ULL, 
            0x14F82310998C77B5ULL, 0x5B519EEE33E1845AULL, 0x8BD1A5E43CEF9432ULL, 0x93BF8328CBF153E7ULL, 
            0xF377AAE0A4B2E73EULL, 0xBB24375CEC975C5EULL, 0xE3DB746FAD674DF6ULL, 0x128BB18B455C8922ULL, 
            0xAAD57100827AC994ULL, 0x9A5488DCB1DCD631ULL, 0x2574A653D6A48E7FULL, 0xE20852F3FE35C4F2ULL, 
            0xA66FC5ADF14C7070ULL, 0x2051C0D8516B7C01ULL, 0x4A065C13C5F80EE8ULL, 0xD320887FEF843773ULL
        },
        {
            0x39AEDF2EE4B3D2D0ULL, 0xF292AED53A96364CULL, 0x5C4ACFF6163EB885ULL, 0xB6D062CA60FC9FDAULL, 
            0x6E0A060060CA96A6ULL, 0x6BCCFF79294FC020ULL, 0x388E3D2C63AC3BDEULL, 0xAB18F8BEE7021C4FULL, 
            0xCD06E99EC9022BFCULL, 0xEF2EA24B3E423874ULL, 0x9A5DBB9979ED4621ULL, 0xE06DECE0E8CE44CFULL, 
            0xE2072EDEC9196CF5ULL, 0x6973CECAA5C37EF9ULL, 0xB0CA3F7BD696A971ULL, 0x219B20C8C9C7AB3DULL, 
            0x0905BEF27B0BBA02ULL, 0x91B36E9439C95A63ULL, 0x63AAC55CF5F53ED0ULL, 0x622A577A370DC194ULL, 
            0x02B2A5EA2EF0B265ULL, 0xB4DD4F6D9AF1B061ULL, 0xAF2BA4B5A6BD4F29ULL, 0x1C19D60CFE3D5A8EULL, 
            0x1AAB4A6DA6ADFAAEULL, 0x84B4A3EB76845EE6ULL, 0x90D0806DF47BDE64ULL, 0xEB9D3D0B76CCC7FCULL, 
            0x9947B60DD933CBFEULL, 0x33AACB85DE580D79ULL, 0xBA8AABAF50D99BFFULL, 0x20DB8B47D39BA3EEULL
        },
        {
            0x2552357E920CBF34ULL, 0x783AF1381A7D56E5ULL, 0x7BDAE0AB31871FC2ULL, 0x8C9EFD9A5DCD7E19ULL, 
            0xB24836C46BC70BEEULL, 0xF9CE6C008CB45627ULL, 0x8F5AA7EA340AD8FAULL, 0xCCFB97B16B3EBBD5ULL, 
            0xF82771A9B2755D29ULL, 0x975FDA47FEA241DCULL, 0x64DCC3FB06D03339ULL, 0xCE6D70CB140D31C4ULL, 
            0x5294214168E3F978ULL, 0x4BA3B4A557912039ULL, 0x9AA95345DE8B1CEBULL, 0x854C10C346F24714ULL, 
            0xF6B2BAAE089CC573ULL, 0x74EAE9BCE218D1E9ULL, 0x1FFE3361F97C776CULL, 0x02F02332ED74258BULL, 
            0xCCDEE3CAE2CDA80CULL, 0x42B5437E1DC18643ULL, 0x7EBBED89342B9086ULL, 0x349D3C23C8F19CBBULL, 
            0x92825F7E5EF0D8DDULL, 0xDDC0F19FA2D79950ULL, 0xEC6528DAF7F97029ULL, 0x3891B301FE43E82AULL, 
            0xF1333176C11B67CDULL, 0x5483BC472632BC15ULL, 0xAEB51C1946401E96ULL, 0x81D25C7C39816584ULL
        },
        {
            0x8098D5B34F02DD3FULL, 0x4D13D278D32EEBADULL, 0xBD2C26274844C02AULL, 0x8A5EB22B85A0A12AULL, 
            0x4B1603CC3036B68DULL, 0x2FD1B0800F5F3E23ULL, 0x81DA49A55678D577ULL, 0x6C373ADE9C22DDE4ULL, 
            0x7E78DCAF0F95BBEAULL, 0x8C8FEC8E0F16735CULL, 0x5138F21395BE56A1ULL, 0x739D401ED0D1966CULL, 
            0xBADD99B35733DB35ULL, 0x1A431F5783A1B641ULL, 0xE8FE09FD688D4262ULL, 0xB32FFE1D4267EBD8ULL, 
            0x5D46B7F21810CAC6ULL, 0x11C561C82472938CULL, 0xE8C695E16A8854B0ULL, 0x9A8E48590CB7100DULL, 
            0x508BE554198361C1ULL, 0xCB6947E33A7A18F9ULL, 0x6ABC4E1AB10935ACULL, 0xCF93FF8FD5C2E65BULL, 
            0x7F27096BEF112CA8ULL, 0x179E0E48374EC5E4ULL, 0xCD92716D5F6DAACBULL, 0x8465EE5D7CF1F5BDULL, 
            0x1F5B72DCE1155E42ULL, 0x23468FAF6F7668C1ULL, 0xBED21F0541946247ULL, 0xB89663E772783CE8ULL
        },
        {
            0x060A573D93018FC5ULL, 0x173F302903349024ULL, 0x355FB8F2E93C0FCFULL, 0x4BF635E3C046ED59ULL, 
            0x843F340005D85757ULL, 0xCC7276FE84FF726AULL, 0x0741EBB7347FA60EULL, 0x8BF51AE46878B761ULL, 
            0xEEA7B734542E1A7AULL, 0x84F5E893FE61B47EULL, 0xFB6E17C77E365431ULL, 0x6710606765E21E4AULL, 
            0xD2EB0ED0A6D2DA7FULL, 0x61DE887AE770140AULL, 0x3EAF88954CE786B1ULL, 0xF72AB789C3311186ULL, 
            0xDC0D29F3C5555D5CULL, 0x08C91E511156D591ULL, 0x2ECD82AE24C466BCULL, 0x2F2FF5248697B062ULL, 
            0xAA17C409AFE3D502ULL, 0x3072FF40EDF1282FULL, 0xE1932EFB2BA169D8ULL, 0x7688305E7C9B6044ULL, 
            0xD9E7E3C9BBADD33EULL, 0x5A811847C417F8B4ULL, 0x1AF61DB61009D68BULL, 0x470C11392ACB9D79ULL, 
            0x17ADDD6FFB6BE077ULL, 0x2650C962F341E710ULL, 0x79D415508F6D10AFULL, 0xA73D9B8D98D87DE4ULL
        },
        {
            0x7EF3AFCA375ED75BULL, 0x3E657CDAE60455B1ULL, 0xCA16A7D7EC1389D2ULL, 0x8F00E783B778D0DDULL, 
            0x6662A5515496BDD5ULL, 0x6B3DAC2EC19B7779ULL, 0x75AF23994F48CDB1ULL, 0xC0C7348AB4DD8B3BULL, 
            0x4472CB56601CAE29ULL, 0xF5C22B18256998EFULL, 0x49687EBD2AB2096EULL, 0x26F54D942A8A7353ULL, 
            0xB296CC26DB14F5DBULL, 0x1620CEEA20AF4706ULL, 0xECD2332BEF65DED6ULL, 0x9F440EA5D38374F3ULL, 
            0x35297F02EF8E5D1AULL, 0x225CB0535A2CA5C3ULL, 0x1FA33BB10F86E4ADULL, 0xF2CE7AA7344331ABULL, 
            0x308C1AF18466DFF2ULL, 0xD588EDF60E8896AEULL, 0x4F26BF58AB05A3DBULL, 0x1A143D86F603EF4BULL, 
            0x63A5C502A6AAC569ULL, 0xE8265CA725871392ULL, 0x334B0106D2D7956FULL, 0x6A21CABB1C7E754DULL, 
            0xB7442B39692FF789ULL, 0x991464227B6CBE52ULL, 0xFC819E536E3102D2ULL, 0xEF2F67440DDCB567ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kTwistConstants = {
    0xC1BBA227E964E2BDULL,
    0xA0C03AC994F95C8CULL,
    0xBCDB4539E0A66EBCULL,
    0xC1BBA227E964E2BDULL,
    0xA0C03AC994F95C8CULL,
    0xBCDB4539E0A66EBCULL,
    0x4A79B86532C48AFEULL,
    0x5FAF67CF8DD28CF7ULL,
    0xC0,
    0xD1,
    0xF6,
    0xD9,
    0x9D,
    0xEB,
    0x7B,
    0x6D
};

