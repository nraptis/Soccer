#include "TwistExpander_Castor.hpp"
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

TwistExpander_Castor::TwistExpander_Castor()
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

void TwistExpander_Castor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD9461040D8BFE784ULL; std::uint64_t aIngress = 0xB6FF3AE95FDE1C81ULL; std::uint64_t aCarry = 0xADEB94B4D0BAA538ULL;

    std::uint64_t aWandererA = 0xC2084186B3F744E8ULL; std::uint64_t aWandererB = 0x90E53F4529AAD0B7ULL; std::uint64_t aWandererC = 0xC14F317F25B8D014ULL; std::uint64_t aWandererD = 0x940C999264699A45ULL;
    std::uint64_t aWandererE = 0x8A494983BCA9FA2AULL; std::uint64_t aWandererF = 0x82B680A9B65182DFULL; std::uint64_t aWandererG = 0x9B895EAA8CF993DAULL; std::uint64_t aWandererH = 0x97F12D1E6C2D0130ULL;
    std::uint64_t aWandererI = 0xD95AC2C04E6BD11BULL; std::uint64_t aWandererJ = 0xE34AFFB965940C0EULL; std::uint64_t aWandererK = 0xE1829030FC7EEDF3ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF2D683F4B66BD732ULL;
        aCarry = 0xFF3B5721F5840FF7ULL;
        aWandererA = 0xA25DE5F826DCC78AULL;
        aWandererB = 0xB86F9211FEDB72C6ULL;
        aWandererC = 0x84090A9FA77536D4ULL;
        aWandererD = 0xE14F21B1D06BA36BULL;
        aWandererE = 0xAEF9C59458E8403AULL;
        aWandererF = 0xD16584D132FB23C3ULL;
        aWandererG = 0xF77D942AB8734CFBULL;
        aWandererH = 0xD75B15E7F284E4F0ULL;
        aWandererI = 0xA2B88BC69A550CECULL;
        aWandererJ = 0xA86FFB5EC4C8D253ULL;
        aWandererK = 0xD8C7DC614A6F274BULL;
    TwistExpander_Castor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x84BE0941FEB8F0FCULL; std::uint64_t aIngress = 0xB5E0E25D3BD43922ULL; std::uint64_t aCarry = 0xC2000542E96CA1BCULL;

    std::uint64_t aWandererA = 0xE33F3C6DA40E3E80ULL; std::uint64_t aWandererB = 0xBDA9B14AE8229B1FULL; std::uint64_t aWandererC = 0x85DED1665AF91795ULL; std::uint64_t aWandererD = 0xB929BD86B77331A6ULL;
    std::uint64_t aWandererE = 0x9EAC1635ABA0A76CULL; std::uint64_t aWandererF = 0xBE271ED703C133F5ULL; std::uint64_t aWandererG = 0xD72310A16F00F0C9ULL; std::uint64_t aWandererH = 0xD89AD65B0DD876F7ULL;
    std::uint64_t aWandererI = 0x910D987A716570C8ULL; std::uint64_t aWandererJ = 0xD95CCCF1B35BAA7FULL; std::uint64_t aWandererK = 0xE1646D3474FBB55AULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCFC19B335FEAC096ULL;
        aCarry = 0x9860C128414BF196ULL;
        aWandererA = 0xD980B997690E9CE4ULL;
        aWandererB = 0xF256E1878C5515F2ULL;
        aWandererC = 0xF1C812010FACEABAULL;
        aWandererD = 0xB10F95E37A020FD4ULL;
        aWandererE = 0x93DC44CE3692BCB6ULL;
        aWandererF = 0xD22B1EFC68F29E5FULL;
        aWandererG = 0x8062A325826693D9ULL;
        aWandererH = 0xE1FEC26A7213A52AULL;
        aWandererI = 0xE9357C56277B41E8ULL;
        aWandererJ = 0xEE01C18CEDB4E934ULL;
        aWandererK = 0xF1F8A817E2DE768FULL;
    TwistExpander_Castor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x91049A0F8F9BD38AULL; std::uint64_t aIngress = 0xE5AC7F8D1A9C5DB4ULL; std::uint64_t aCarry = 0xAFDC7F3019FA0D43ULL;

    std::uint64_t aWandererA = 0xAFB4C9B5DE2E0932ULL; std::uint64_t aWandererB = 0xFF1D41F70ED2D0C5ULL; std::uint64_t aWandererC = 0x8B80C37A5ACBB7C5ULL; std::uint64_t aWandererD = 0x9DC1C832EFFDB6C3ULL;
    std::uint64_t aWandererE = 0xE042F5683B9F1EA5ULL; std::uint64_t aWandererF = 0xDB28268B69C2373AULL; std::uint64_t aWandererG = 0xBC5572C6CBF813C7ULL; std::uint64_t aWandererH = 0x8DC5818071676B9EULL;
    std::uint64_t aWandererI = 0xC8054DF4FE56D707ULL; std::uint64_t aWandererJ = 0xF2EB5D8E7B3C4E89ULL; std::uint64_t aWandererK = 0xE870F7BFE851E058ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF3B01CE0A31808ADULL;
        aCarry = 0x8BAE42AC2B81556FULL;
        aWandererA = 0x8B653B2DFA038A84ULL;
        aWandererB = 0xCC99FBE2921C0AF0ULL;
        aWandererC = 0xAE3952337A7532C5ULL;
        aWandererD = 0x8E85BAC4958B5D32ULL;
        aWandererE = 0x8AB64A028B9C1FF9ULL;
        aWandererF = 0xA413576BD770CEC6ULL;
        aWandererG = 0xF3D9377A20748E5CULL;
        aWandererH = 0xA919275E17614D66ULL;
        aWandererI = 0x9DC2B56FD35DEAEAULL;
        aWandererJ = 0x947388ADC525F7D7ULL;
        aWandererK = 0xBD7ACC0356403573ULL;
    TwistExpander_Castor_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAA5E1F4C05A34F02ULL; std::uint64_t aIngress = 0xCB4C74AD0A01F788ULL; std::uint64_t aCarry = 0xB906421001078747ULL;

    std::uint64_t aWandererA = 0x8514CB21ABEC0A67ULL; std::uint64_t aWandererB = 0xFB04A192DEDE1B8CULL; std::uint64_t aWandererC = 0x83C27A6104B70918ULL; std::uint64_t aWandererD = 0xD9ECB8750FB40F1DULL;
    std::uint64_t aWandererE = 0xCB810502399AEC75ULL; std::uint64_t aWandererF = 0xD09EA48F3FD47159ULL; std::uint64_t aWandererG = 0x8D98E0ACA2CA3D0CULL; std::uint64_t aWandererH = 0xA06371915982D2DCULL;
    std::uint64_t aWandererI = 0x9694EF372BF2594AULL; std::uint64_t aWandererJ = 0xD2CFE7B020A0D035ULL; std::uint64_t aWandererK = 0x8726B268FCE622A9ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB5BB79DD853064E8ULL;
        aCarry = 0xBC06F5C47565957FULL;
        aWandererA = 0x99A5A559CAD0C5FEULL;
        aWandererB = 0xE16876A508C291C8ULL;
        aWandererC = 0xCFE5A79DA697D2C6ULL;
        aWandererD = 0xD26E289E47EA1006ULL;
        aWandererE = 0xCC5E017EFACC4CFAULL;
        aWandererF = 0xC20AEBA73AB0CBFBULL;
        aWandererG = 0xDF0F45912C2C6B7FULL;
        aWandererH = 0x90BB4BF90CB49674ULL;
        aWandererI = 0x87B59F02B5DFA782ULL;
        aWandererJ = 0xC3476DD11AB1849DULL;
        aWandererK = 0xAAAC2779913B85D8ULL;
    TwistExpander_Castor_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Castor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFCAA444974E636BBULL;
    std::uint64_t aIngress = 0xB4614D51964804ABULL;
    std::uint64_t aCarry = 0xF5F3ABD8527B5854ULL;

    std::uint64_t aWandererA = 0xE56FD731B67129CFULL;
    std::uint64_t aWandererB = 0x97F463A66AC00A34ULL;
    std::uint64_t aWandererC = 0xF335F0C3EECF8322ULL;
    std::uint64_t aWandererD = 0xBE1E74B485E7C8E4ULL;
    std::uint64_t aWandererE = 0xD85A93528054C461ULL;
    std::uint64_t aWandererF = 0xB89D289CA0366BE0ULL;
    std::uint64_t aWandererG = 0xAE896AFE9ABAC35FULL;
    std::uint64_t aWandererH = 0xDBEA411ADC023945ULL;
    std::uint64_t aWandererI = 0x808724962AC5D06BULL;
    std::uint64_t aWandererJ = 0xB578AB852620071DULL;
    std::uint64_t aWandererK = 0x96586ABFFB4D64C2ULL;

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
    TwistExpander_Castor_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Castor_Arx::KEY(pWorkSpace,
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

void TwistExpander_Castor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x807F23DD390DEC5DULL; std::uint64_t aIngress = 0x84DC61A067A6CE2BULL; std::uint64_t aCarry = 0xF57CA56AA467838FULL;

    std::uint64_t aWandererA = 0xF1630A2456DBDBE9ULL; std::uint64_t aWandererB = 0xBB908C4904AB2D13ULL; std::uint64_t aWandererC = 0xFFBF550BE736F91BULL; std::uint64_t aWandererD = 0xFB141145B50D9088ULL;
    std::uint64_t aWandererE = 0xE75EB70AFC20188DULL; std::uint64_t aWandererF = 0x97DC070864CAC4D2ULL; std::uint64_t aWandererG = 0xDF04FB920E75D5AAULL; std::uint64_t aWandererH = 0xF22B43064002AE89ULL;
    std::uint64_t aWandererI = 0xD7642358EB35391BULL; std::uint64_t aWandererJ = 0x9FEDB9495F64E2EDULL; std::uint64_t aWandererK = 0xAB2E8CE1387226B7ULL;

    // [twist]
        aPrevious = 0xDE24FC9DB4C01463ULL;
        aCarry = 0xD20FF0FDCD68B70AULL;
        aWandererA = 0xC04E6A65934B7DBBULL;
        aWandererB = 0xE3E2A3B1D08FA3E7ULL;
        aWandererC = 0xFBBC20B5A5302356ULL;
        aWandererD = 0xD2CEB373406C1AE3ULL;
        aWandererE = 0xD18C926C16ED85B5ULL;
        aWandererF = 0xDD2039176629CC91ULL;
        aWandererG = 0xFF7A65D473C333B6ULL;
        aWandererH = 0xA3A07B99908B777DULL;
        aWandererI = 0xFC4BEE75803E0440ULL;
        aWandererJ = 0xF4FD63C61E391D34ULL;
        aWandererK = 0xE4B0AD7A1792BD78ULL;
    TwistExpander_Castor_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Castor_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Castor::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Castor::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Castor::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 16 of 33
    // Exploration cases: 0
    // Structural maximin 515 / 674; family total 8059
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 16 of 33
    // Exploration cases: 0
    // Structural maximin 520 / 674; family total 8146
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 16 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1062 / 1248; total 16253
void TwistExpander_Castor::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
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
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
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
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 16 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1060 / 1248; total 16179
void TwistExpander_Castor::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
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
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1061U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
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
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Castor::kKeyRotateSalts = {
    {
        {
            0x0A37BD90D40CF0E0ULL, 0xB9675A399FC46182ULL, 0x5A32C3C40062F23EULL, 0x68473F23D1C644F7ULL, 
            0xC7B6FAC328D2112FULL, 0x573A6C4C9ADB27B5ULL, 0x002BBDE8B713A9D0ULL, 0x5AAD7F7E2723E9DDULL, 
            0x35BE101FD71EE1C7ULL, 0x6FB283A338B5D7E2ULL, 0xA33DCF2DAF4388EEULL, 0xAA33A5872C55DDC4ULL, 
            0x5ECE5E4C85F27544ULL, 0x83FFE28EB130FA92ULL, 0x0575B1F48C0FE61FULL, 0xA1529D05650BDC61ULL, 
            0x994ED257C7832394ULL, 0x4BB306DC40C0CF5FULL, 0x02A965B09C0818A3ULL, 0x27DCF136CCD3F155ULL, 
            0xD20FCA247BD8DF74ULL, 0x045E6931097D4ED8ULL, 0xB2422ED9FF089032ULL, 0x85EF0E010B8297F2ULL, 
            0xB4507F663AE62945ULL, 0x878E23C082CEB883ULL, 0x44B237808434F447ULL, 0xF45D5901943C922EULL, 
            0x87B0CCA5201F1BDDULL, 0x29C772A8EFD04B9CULL, 0x7D51BDF955A6D2F6ULL, 0x48E155CBDCA0963CULL
        },
        {
            0x9B44A516E8C70798ULL, 0xD5D87C35782F0605ULL, 0x86412311C91C2DFEULL, 0xC754651685FCA429ULL, 
            0x309E72C864FE5BB0ULL, 0x7357D13D19B3C033ULL, 0xB5D04D1E28207ECCULL, 0xDC9F575C7CD6B403ULL, 
            0xA36D9CC7B6C2F337ULL, 0xBE42104539E43695ULL, 0x263FA08E4B7268F5ULL, 0x6EDBE7A476D0A61DULL, 
            0xABF5556C57C1F82CULL, 0x7409F361D0D0E3ACULL, 0xA12ECFA12172189AULL, 0x3FFF07AF21661C14ULL, 
            0x1838FA7B1FA995EAULL, 0x070993E4EC6AFC25ULL, 0x824CBEA6C0C37179ULL, 0x69CC67804BE4735EULL, 
            0x8E88415DF09DB506ULL, 0xD1799D1FE576A78CULL, 0x86A6D858D3AEAECCULL, 0x9E21B2BDDDF17183ULL, 
            0xB465CECA2AE84703ULL, 0x2D9E0242B9CA466BULL, 0xA6B45EB3F168E590ULL, 0x7D25332F6C99E269ULL, 
            0x221CEFFE96B23049ULL, 0x0021C2C6A0971F1EULL, 0xB5399185D432B238ULL, 0x03B5312B4C3FDE49ULL
        },
        {
            0xD271F7594F3E242CULL, 0xD048020E1414D015ULL, 0xBCB0724E22F76D8EULL, 0x61298D6A0118C906ULL, 
            0x7FB8F5010F6A6426ULL, 0x14AC6A455E585295ULL, 0xAFF8DAFC7713EA34ULL, 0x2B014264DB5C28AEULL, 
            0x103431329B9838C0ULL, 0xB9ABE28B091614B8ULL, 0xADA14F05D9A0F4C0ULL, 0x3F73C217C82CCE55ULL, 
            0x5B861FD233A1F013ULL, 0x5456DDFFE7A4A6ADULL, 0x401B1C461FC06F8BULL, 0x5E0AAFEF4E912EFDULL, 
            0x11398444CCEA4837ULL, 0x2EA725EFFDD89C23ULL, 0x57A2E8F285E737A6ULL, 0x53B58EAC26070640ULL, 
            0xCBEDB6EFC8A08ECCULL, 0x1035236989B1371DULL, 0x9F0BD77F4D80A8CFULL, 0x4BEB3E8E984FF27BULL, 
            0x8C14AE62EA843F44ULL, 0x398BCABBB4223B33ULL, 0x5325C64E781B70E2ULL, 0xAB1DDC678A8C9DC4ULL, 
            0xD9E99EABBD5A8C75ULL, 0x1443FF42FF344763ULL, 0xCDB8EB37B8944CACULL, 0x48F5E096A1F185D8ULL
        },
        {
            0x7571F1AA753E618FULL, 0x99A318C5D46F165DULL, 0xB0EF2FE32D0E9F59ULL, 0x4A23784022C6EA00ULL, 
            0xBE7C467C7FD2FCD7ULL, 0x0E5C2E8E690B5C6AULL, 0x24E02F4BF992E9F0ULL, 0xD02E09EA7AD8D85EULL, 
            0xB0D18567EACAFB05ULL, 0xA7325F7725EA8FCDULL, 0x7304819CBE25FF38ULL, 0x7C60438517AF2041ULL, 
            0x90950449A7933448ULL, 0x37FB72CE1AE61DE9ULL, 0xA2D0346428C63EDAULL, 0x57AC54CEEC834A89ULL, 
            0x695B3E20372C8AE2ULL, 0xD0A1ED0E84EF39A8ULL, 0x0AAD2FBEFDFDD6EBULL, 0x224CD2B3EF47961AULL, 
            0xC9BFE03DDD51C50AULL, 0x99AAD0F85EECFF8CULL, 0xE2788CB69D32D4FAULL, 0x723583738C5A8A86ULL, 
            0x0DD4F498D20C3ACBULL, 0x36776C8703D19D78ULL, 0x916AFE80741BD0C8ULL, 0x9EF661C729AF4B1FULL, 
            0x839A2684C52A12A0ULL, 0x2FCC8CFF13F10465ULL, 0x10F202C61ADD1876ULL, 0xF80958ED8475831AULL
        },
        {
            0x6CD9424E6E1EC8A7ULL, 0xF8F9C2F0171F20CEULL, 0xEAB283554E3ED5C0ULL, 0x0F4FB964006037AFULL, 
            0x5C2F4089309F598CULL, 0x8C5C04030AC2AC23ULL, 0x9895A3903F8945ADULL, 0x8290BEFE2DF8A1AEULL, 
            0xECD9DDA21E8C7546ULL, 0x6ED974C8CBB717BBULL, 0xEA9555FDDE577901ULL, 0x8DAD29F77F779C58ULL, 
            0x2AA29F1B34121E8BULL, 0x404449E6A542F532ULL, 0x08CC831CD37B04A8ULL, 0xC67FE411CDCF105BULL, 
            0xE2DF65E148A2DF0DULL, 0x3B755DBDAA785D1DULL, 0xB0281F8999543EA2ULL, 0x85DC5632E28C3A25ULL, 
            0x9C1B648035F5DAF9ULL, 0xE5A213B848C7E3E6ULL, 0x9744B3984CCBAD44ULL, 0x165DDF266357F222ULL, 
            0x33C7EDAE8D2E3EDFULL, 0xE3BEDFEC7B42ED00ULL, 0x2BF8CBF6FC224F6FULL, 0xB8075FB9CF12AA5CULL, 
            0xCB63A491D4BAE7F5ULL, 0xB89BEBAA7DD90D98ULL, 0x315EC45A40D3A610ULL, 0xC8A8FDF15537FD0CULL
        },
        {
            0x9B0A765CBB6DA4FFULL, 0x09CB544156FC6A90ULL, 0xBF82B4DCC6EC1155ULL, 0xAE486164C5598340ULL, 
            0xE4FECB074986F473ULL, 0x7F69E7140D89210DULL, 0xE30F2507F321810CULL, 0x49E9AB7E9C1EF2E8ULL, 
            0x5811B38FD8A86E14ULL, 0x60D26932AB28D60EULL, 0x10DD8998F1EECFEEULL, 0x63E2EB884C953F0AULL, 
            0xF091D92F3BD44073ULL, 0xE8C29315C6DF03D7ULL, 0xD638F1B37A82F110ULL, 0xB83378CF74863089ULL, 
            0x98D558B05AC090A0ULL, 0x05EC7B70FBA9F60DULL, 0x81720EFEFD7864C5ULL, 0x63C3931D09E8A600ULL, 
            0x256770999B0554F2ULL, 0xFBC779F14AFF9F76ULL, 0x37F5D6B3B2FD2882ULL, 0x112EF50A56F50B8BULL, 
            0xCFB9CE628C7E8D32ULL, 0x8EC9F655EF3AA955ULL, 0xF2BF0D33AEB75C9CULL, 0x89A1F7C6D612E4BBULL, 
            0x879C1D10F5CF41ABULL, 0x38E66E036A4B4982ULL, 0x06BC162224EF0E7EULL, 0x87C4C4A60EA34FE2ULL
        }
    },
    {
        {
            0xF8B2B39EF7D21FB0ULL, 0xDF27E9F783FE07EEULL, 0x27E249D0990FED69ULL, 0xC57804506CC2F7CAULL, 
            0xD43470A8246B4FF5ULL, 0x5062A223DCEC7856ULL, 0xABB9056FA9DA6BE8ULL, 0x3F063A2A93125E44ULL, 
            0xE37A7A5282BE8515ULL, 0x1C0C376F1CE1135AULL, 0x1A91D9177D183F26ULL, 0xCD81EBFD93728877ULL, 
            0x534D561D0B1C51A1ULL, 0x613868F51CC9C7A7ULL, 0xCA9805E337BB1DBDULL, 0x9F719B39D0A8E5F0ULL, 
            0x1156AEF0CFB597B7ULL, 0xFB33519474783BF2ULL, 0x16D9493F6EC0510EULL, 0x5D06E7869514D15EULL, 
            0x69E782645AD73C38ULL, 0xC2CCA05D9E21898BULL, 0x28ABF563549F7C42ULL, 0x7F47C5EC22D0E3ACULL, 
            0xD69FD92E163D7203ULL, 0xFE9A95A3B07ED2A7ULL, 0x54EBAE596EF9B686ULL, 0x39577C8854091AA0ULL, 
            0x69038DD93AB1FA8AULL, 0x03234F5D0AE79D85ULL, 0x614A35C174799CB5ULL, 0xA4E8352A71954BF1ULL
        },
        {
            0xBEFCBA58AD07F195ULL, 0x12DC14D04FB070B5ULL, 0x0F079D585DAC37F5ULL, 0x4D514550AC60B234ULL, 
            0x532613B1EC1DA66CULL, 0x2DEDF13239B2C680ULL, 0xF5AD3F65493D1240ULL, 0x1C1C6203FEF7EF69ULL, 
            0x4EA3D421E37755C8ULL, 0x4AA53345A8C5E20AULL, 0x352DB4A74DCB506DULL, 0x37A5C20ED014F9E6ULL, 
            0x1475CFF0D83E60D8ULL, 0x7F040312F8925F35ULL, 0x65E80F60467DEE3DULL, 0xF50D40734E641C4AULL, 
            0x69B831907DB138E6ULL, 0x3C01A956067247CFULL, 0x5E0DFFA92F59A8DBULL, 0xFEBC178D3745F4E8ULL, 
            0x4C0CAB4886DBF306ULL, 0x6D6CFD1111E4E45AULL, 0x62D774A7D9EBD439ULL, 0x996BEAE8427F8777ULL, 
            0xEA94972B2523984EULL, 0x0CE4B3F0AF52D350ULL, 0xDB79844A8BF3FF41ULL, 0xB926F16FB93CCDADULL, 
            0xCCEDD68E36EC0175ULL, 0x29EF6FC09093922FULL, 0xD4D1F069D553DF37ULL, 0x2072037653775A1BULL
        },
        {
            0x4D3276B920F9C1F8ULL, 0x818D78D2FE072A23ULL, 0x43D47A149AF71814ULL, 0x72A3C010449AF675ULL, 
            0x388218CCA803A62BULL, 0x5CF4C6DF622133F4ULL, 0xA1374A7270F8EE19ULL, 0x22B7D8574B54516EULL, 
            0xA88C57005BD8C094ULL, 0x25CF6D6F5B302E40ULL, 0xB3D8E00003F73C03ULL, 0x443E933BBA846103ULL, 
            0x64D7458670045326ULL, 0x2066163ED8DB12CFULL, 0xBFF8DD3FDDC03F49ULL, 0x878A5FF7092F1D9DULL, 
            0xDA34E1FEF3FB1CE2ULL, 0x9C7473EA15A5B2FAULL, 0x1C24A6C3B9EE07D5ULL, 0x2B798ADC8DE88324ULL, 
            0x1F22A3F2DD5014FCULL, 0xE0E9629B27FC4F82ULL, 0x7423F824921FF743ULL, 0xA817744144D9E809ULL, 
            0xE4D1B9CC0C418F39ULL, 0x777015A108258FF6ULL, 0xACEC28A0353F4EFFULL, 0x6288EBEF933EB603ULL, 
            0x20256E36FD12572BULL, 0x6181A27CEBC3775CULL, 0x0F0319BE351E44BCULL, 0x118F4F5EDA92BC84ULL
        },
        {
            0xE85C9F4852F41EA3ULL, 0x724690E836492081ULL, 0xBE7555296F207156ULL, 0x02B6FD5EBE2B8A88ULL, 
            0xBD89253836C4DD15ULL, 0x5519F1639F30628FULL, 0x561E72E736C04229ULL, 0xBF76D559EDA0AB96ULL, 
            0xADF9787F7F77B76DULL, 0xA3A54A3B6C4DC6C0ULL, 0x62DCE99C4CA01BB0ULL, 0x34750D2CFB24C46FULL, 
            0x6EB4296F573D918CULL, 0xA399A03A2B1DD3FAULL, 0x7D6D5D7E96A7AB1EULL, 0x6DFB4B5F0F7395D8ULL, 
            0xFBB5BE2F9AB43CC1ULL, 0xB6FFA70DA408B5C7ULL, 0xB5286A80E6F68EE4ULL, 0xAC8543E46D06CA40ULL, 
            0x17B7BDDB3DE32635ULL, 0xB40BD0A4E64C3D6FULL, 0x9581630DED8DD4F7ULL, 0x6D8EF5109781606EULL, 
            0xE2FDCFDB9F61697BULL, 0xFB1108188B6A0EDEULL, 0x1568B4B9035E502DULL, 0x1A60DE6FB2EF7AB7ULL, 
            0x6E285B2404891446ULL, 0x6395A212676CCF22ULL, 0x427E79926A74408BULL, 0x106E9DA2DC2FD89FULL
        },
        {
            0xD5A52259371A878BULL, 0x428911EB500BEF02ULL, 0x9C4A2EB3E1C6BB07ULL, 0xC52EDCF58A87CB37ULL, 
            0x6A200229BFDCE3ABULL, 0xAFB6DF13D5C31D5AULL, 0x3DEA65A907E84870ULL, 0xD290BFE256F03CD4ULL, 
            0x6A2B6CE9568D7496ULL, 0xE34967B8FD8DDBFFULL, 0x27F6A7644351F4B5ULL, 0x3810B618B4EF9982ULL, 
            0xE2254E3F286C90C5ULL, 0xF18BDCBF008FAEA6ULL, 0xF1A253C265F2824FULL, 0xEA7B735FFB00072FULL, 
            0xA2898517AD873B6DULL, 0x5A8CC68DB89801E5ULL, 0x5B27E8C9A7728D14ULL, 0xB0ADDB9E9C4C3470ULL, 
            0x72F26AA7477267D8ULL, 0x41A425520A74E9E3ULL, 0x3F188CA4C70EAE81ULL, 0xC4C9D66FD1991D17ULL, 
            0x0E3C6C9D427F6EFFULL, 0x755746CEA39578D6ULL, 0xF3B217944FC23DBDULL, 0x8BC8B783B434778CULL, 
            0xA199B28E09EE6431ULL, 0xCEBEEC0B02B042ABULL, 0x15648DCB6AC65F65ULL, 0x0161129D06110E4CULL
        },
        {
            0xF31431FE286D4438ULL, 0x88FCADAA1B922CDBULL, 0xAF96BB2C116FDCA4ULL, 0xAC77D3FDA5BD3C87ULL, 
            0x1E4DAAAC8948DD31ULL, 0xC75DB904565F50C8ULL, 0x78F2189E1584773FULL, 0x62AF2449D13C5B41ULL, 
            0x943D8F026D9166FDULL, 0x7FF19376086599D7ULL, 0xD88D13B63D2EB43AULL, 0xC2A8F47BFA24BA1FULL, 
            0x46185A19F2C4D240ULL, 0x01593A2EAC313140ULL, 0x0B87B7C05B32DC1FULL, 0xD3F58B5888D083F0ULL, 
            0x4F5B1EB151035EDCULL, 0x4782FF47CED0D359ULL, 0x01182FE57FD34DB1ULL, 0x1A20BE76B35001B2ULL, 
            0xBD4C4C3A8769D5C0ULL, 0x9C8AB469CAE461FDULL, 0x9D87B07573A99D32ULL, 0x8F5D38C6C315EDB7ULL, 
            0x7C489E7E660F2612ULL, 0x8484BC953EDF5C54ULL, 0x1450A518334821B7ULL, 0xCF5E50391EF14229ULL, 
            0x23A5C32046BAE68BULL, 0x2595375272788812ULL, 0xAC3299A99D3B999FULL, 0xF1748E08B1DAF143ULL
        }
    },
    {
        {
            0xE3D5325E23FD0EDCULL, 0xC53F161AE3F1B99FULL, 0x143187774C92A704ULL, 0xADD819AED777553FULL, 
            0x5037AEFC7097AD91ULL, 0x777E470F9AAD8661ULL, 0x2E556C6BD3F8B135ULL, 0x42D65B2A9EC1501FULL, 
            0xD9C21D1695622AC8ULL, 0x2ACA69AD237EA54DULL, 0x465D27CA7D328880ULL, 0xFB0E2F3CE4E413E0ULL, 
            0xB12BD1B4A0E56DB6ULL, 0x42AF185A2C0AED65ULL, 0xE78D5D23B3464D5CULL, 0x7C4AAD18F4AAE230ULL, 
            0x46F4E78C8B2BE452ULL, 0x9F5FB9AB39D7FC80ULL, 0xEFD7C1B322725C43ULL, 0x99B79102919DEB5FULL, 
            0x17B6232A5D1ECCDDULL, 0xF43BA88441B88506ULL, 0xF051A1B4B1DF09C2ULL, 0xBC5B04DBC91D608AULL, 
            0xA941E547F5272151ULL, 0x694E26B26CD28739ULL, 0x7BD4E165894645A6ULL, 0xBB6E4237D0048BF7ULL, 
            0x6CBF0BCA36E38BD6ULL, 0x05FFD68ADB67ADD2ULL, 0x95FA17BF1245BB5EULL, 0x436318CAB86EC0B4ULL
        },
        {
            0x273FE264E0DCDC25ULL, 0x45804002579FF001ULL, 0xBF4A7A866E71008DULL, 0x28105620ACC9566EULL, 
            0x9968BB826A84CA88ULL, 0xD22BD09872709A51ULL, 0xB8DCC19D8189E4ABULL, 0x70D739EA35BAAEDBULL, 
            0xA232AB07E9E2C8E2ULL, 0x32DDBE87A87AF5A7ULL, 0xEE1D56C3FBDCB6A5ULL, 0x3B091B9D051E8EB6ULL, 
            0x1918CE8BA376AA21ULL, 0xEE5EECB16B414B2DULL, 0xF035A6CC52661F56ULL, 0x0D7105D24CFD6C35ULL, 
            0xFCFE5C9EA29FAA8BULL, 0xA5BE096ECE2370E0ULL, 0x642AF44CD244C02AULL, 0xCB8795384B3C93F5ULL, 
            0x40762BCAD69EF459ULL, 0x1D20612A3D6461B4ULL, 0x1C4EBCBAB7CC7F1CULL, 0x5BF66C05148D8515ULL, 
            0x05C7D828097D23A4ULL, 0xBE1A613DF63513C3ULL, 0x930E5E9F13BB505FULL, 0xAB5499F6F771744EULL, 
            0x3FE4B88C971F8428ULL, 0xB450A416FF04588DULL, 0x54D55A367B5DBEB4ULL, 0x8B4B1E580F99691EULL
        },
        {
            0x93E64AD0BCCBA473ULL, 0x8396C6CA7227AB5FULL, 0x2DFAC3CE79228805ULL, 0x3B3C39AC8015BB32ULL, 
            0x3D60347FE4FCD458ULL, 0x4A28B5AF63256454ULL, 0xEE7838F525F01C57ULL, 0x2804D3E689A2E11AULL, 
            0x6961E5FE0FC2D216ULL, 0x1DBAC02C04D1C06CULL, 0x4D6DACBEFD5CBE5EULL, 0xFC6E239344786C23ULL, 
            0x9AE8C6C52A178C62ULL, 0x416B7C0D8CBFDC83ULL, 0xD849E45F4A7E87F5ULL, 0xCC487CB7EF84101DULL, 
            0x1ED4989B71509789ULL, 0xE2220AE357EEA2EFULL, 0xE487552B4A609602ULL, 0x009271ED58332036ULL, 
            0xE1EE9D6400CF3129ULL, 0xBD3D3A7C867974D7ULL, 0x5575BFE0A16BCAE5ULL, 0x9C92C7BAFA6CCF29ULL, 
            0xA05BFB6EDAC53878ULL, 0x89A0B2648E997A09ULL, 0x77033D6E32CDA426ULL, 0xDC74A8ECE98D9868ULL, 
            0xC5B46F0C40CB3232ULL, 0x35BB2786CB21E5D1ULL, 0x0399324D4E79F9FBULL, 0x0DE164DAEAD2ABE3ULL
        },
        {
            0x0FAD70074331FDBAULL, 0x9FB2F2B44C2F8EEAULL, 0xBB10B420A3BA714AULL, 0xAB715698415619E6ULL, 
            0xA692EB3F075BD0D0ULL, 0xAFC43D2278CB73A2ULL, 0x36DA114C3EAF3C28ULL, 0x36AFB4CE8BE54819ULL, 
            0x7824CF615A393D72ULL, 0x905FDD6456921A0AULL, 0x8973CD5C30ECBC3EULL, 0xE910FFD157A5C198ULL, 
            0xAFCDD334F7982876ULL, 0x4817EAF21782AF64ULL, 0xB47505A703A7CABEULL, 0x88C72B0C21E2D358ULL, 
            0x00E8524FAF67AC96ULL, 0xB4A68F901B435906ULL, 0x59F084A9ED6D9CB8ULL, 0x2C70E3DA3AA5A2F2ULL, 
            0x70EA496C6755DD46ULL, 0xDBF83CB1AAC99216ULL, 0x2FE1053F1B763B9BULL, 0xAEE9B0AC1399A4FFULL, 
            0x5C60B89908F567CEULL, 0x32D3D81C8206B64CULL, 0x9ACE376414BF5563ULL, 0x5614957FB6DDC0EFULL, 
            0xE07DB936C6F5EE1BULL, 0x2DD62F568C6E905AULL, 0xE80C7EFEE557FAD8ULL, 0x64D06B5EFCA26D51ULL
        },
        {
            0x8E7C27E3FE90C192ULL, 0xA46BE4B293B9B36BULL, 0x5223FD0F44655E05ULL, 0x36C1EFC388E72A7FULL, 
            0x0476D9683EF0AD94ULL, 0xC1DEFEF5811837E4ULL, 0x4D7C6F92E00D793CULL, 0x1E43DC96C9F88003ULL, 
            0x73E4BE85C78E06FFULL, 0xFFFB7E28EAA7CB5AULL, 0x37CA771B8A45347CULL, 0x9C9610D6D42BCC50ULL, 
            0xE03556FD2A1BC625ULL, 0x7A3663F468B2AF90ULL, 0xFBF941115143CC1EULL, 0x18C7617C6FBB1500ULL, 
            0x4D8D371A2EC42818ULL, 0xF16C83D7FF67BCCCULL, 0xAECE1B77D649F5ECULL, 0x7FCF522E4CAB18D8ULL, 
            0x1353584F7CF6C059ULL, 0x067658BBCFCDEFCBULL, 0xCB4FFF1A97A83761ULL, 0x26850FBA841DE1C8ULL, 
            0x2E0B0E24DDAF101CULL, 0x146E4131D4C4016EULL, 0xEBE12721ED7D426EULL, 0xC8CBE56660879F37ULL, 
            0xEAA6B8EABF30C2F0ULL, 0xF707207B750BAFBCULL, 0xB68B3FC1649ED54BULL, 0x11A03082ED9B6F89ULL
        },
        {
            0x11026DAADDDED2F9ULL, 0xF71DECEE421FB000ULL, 0x4C5428B73190AD86ULL, 0x5DD127322109246BULL, 
            0x3A0BF45CA72ABB34ULL, 0xA7183A2DC82815BCULL, 0x6D1563F303F23C3EULL, 0x52D0E6B219FC54E1ULL, 
            0x027B31DDADC98C0DULL, 0xAF6FEE1E052CAA40ULL, 0xB110A5D49DA91ADEULL, 0xE34B31C48FF4C28FULL, 
            0x43FB09ABEDFCFB11ULL, 0x9E1BFD5318B64340ULL, 0xB152BA90E2A64320ULL, 0x454DC973B5FF871BULL, 
            0xA5E3D2506932DA59ULL, 0xFF65D82CD2FD6B2BULL, 0x331A8E5CAB9796E9ULL, 0x930139FF4F10F58DULL, 
            0xC5BBC50F30D3F063ULL, 0x624D413F0F0FF482ULL, 0x6FC2FC65CB7E8F8AULL, 0x2B733E83F75FBB88ULL, 
            0x6AD4269A283EC923ULL, 0xC9486B96F3BF5A35ULL, 0x1E923674EBDAF54EULL, 0x1AEA5C952A296830ULL, 
            0xFD0E777080E44E54ULL, 0x703486367BB194ADULL, 0x03CD105C7E789F9DULL, 0xBA190261AA69F04DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeyRotateConstants = {
    0x36445F134EBF2989ULL,
    0xEC8EC207CEF6C225ULL,
    0x0EF67703EE586503ULL,
    0x36445F134EBF2989ULL,
    0xEC8EC207CEF6C225ULL,
    0x0EF67703EE586503ULL,
    0x4F3896F59581B9F7ULL,
    0xEE5502F2C637034CULL,
    0x66,
    0x62,
    0x57,
    0xEF,
    0x8C,
    0x0C,
    0x7D,
    0x48
};

const TwistDomainSaltSet TwistExpander_Castor::kKeySpawnSalts = {
    {
        {
            0x24C62A49F5565DF5ULL, 0xF461BB84E6860211ULL, 0xA468D33C27898D6DULL, 0x56EF9B48B9D9E5A8ULL, 
            0x226E6428FADCB1BBULL, 0xBDCA99C417E730D9ULL, 0xF78856A7D1818264ULL, 0x8F450A7F6A4B2DE5ULL, 
            0x71193519F7D395B6ULL, 0x3A87DB30FFAF2B57ULL, 0x038AD613EDDE522EULL, 0x56C5B38394F3BDD3ULL, 
            0x0D026E56FEC34DC8ULL, 0xA012B71973E59D6AULL, 0x1BCF105319F0F321ULL, 0xEBA9E007441D53A8ULL, 
            0x668F48E28698E671ULL, 0x6B0143819AD102CFULL, 0xB01C6B4E0C46433EULL, 0xA28457E45929CB5AULL, 
            0x14534DC131E21E2DULL, 0xC2BEE82B638A7937ULL, 0xE71F6AC58E16244CULL, 0x8A3D8F4913D0EC08ULL, 
            0x0C2CD91042950E6CULL, 0x796D2DF11081C237ULL, 0x766B4FE258E9D64EULL, 0x7E3350156FB39E6CULL, 
            0x2B114E6C8B2DE026ULL, 0x1FA4F16243963C66ULL, 0xAD6C504222CA5508ULL, 0x2E64666E12359EA4ULL
        },
        {
            0x633BD8E747E732FEULL, 0xA68A212B99C51CE1ULL, 0x225353ADB6840D19ULL, 0x2091C317105A9A09ULL, 
            0x74B4BB36675ADC90ULL, 0x8131AC02A1FE95D6ULL, 0x072671ABE7DA07B0ULL, 0xF135E28995F991F7ULL, 
            0x763CFE47B95E7E45ULL, 0x6C5E14E50FC130D0ULL, 0xD0D1DEE655C158B4ULL, 0x9A672E923ECAC08DULL, 
            0xAC50D25A1E32923DULL, 0xBBA619E9869B1E4FULL, 0xFCE64179479E0B29ULL, 0x1F26B97D880D07B2ULL, 
            0x907F14B18F53BD16ULL, 0xF9C8CE069529B6FBULL, 0xC26196DAB58195AFULL, 0xCB2B142F38C4C041ULL, 
            0x1821A21BC82D5D1CULL, 0x4F2B4A17C32F2E73ULL, 0x4028FEAB235710C9ULL, 0x9A6FDD26F7AC200CULL, 
            0x877C44BEE0A7A94DULL, 0x74F59538D5C9A1F5ULL, 0xC2A743DAEEB6A6B7ULL, 0x406CFC4F5B52FAC8ULL, 
            0xCC52721F07ED599BULL, 0x0BF8947EFF8EF02DULL, 0x672403E9AC712287ULL, 0xDD6796F63189C658ULL
        },
        {
            0x338A4FA5ADEC3E08ULL, 0x8A730291F8551B3BULL, 0xA781E780D5DF3059ULL, 0xBDCFD7616A0606A5ULL, 
            0xD6CEAA31D0095E61ULL, 0x672D6048B89C6965ULL, 0xC6514CE83938E002ULL, 0xB1B0C0A70D1CFE3DULL, 
            0x38070A02FCAAEB58ULL, 0x1A21617AB1967431ULL, 0xC268102E29171AE1ULL, 0xF3A8DDAD1896B207ULL, 
            0xC1EBEF36A3F765B5ULL, 0xD90252725F9C061DULL, 0xBA9359A6220DA98FULL, 0x6F1C9DC8D94E4F88ULL, 
            0x41A058C0D049A979ULL, 0x0FF486A8E8806F5AULL, 0xD4AC1D1A2DEC523BULL, 0x8AEC768A550571AAULL, 
            0x93EFD7A67A8BA6AFULL, 0xEFED4C3964A44ACFULL, 0x815A8C2B21EB93A7ULL, 0xC7AC38A4BA91E65EULL, 
            0xA4B276617FFD4194ULL, 0x65E38E710C6EEF8FULL, 0x0AA3427698434D3CULL, 0x65E4FC263E517873ULL, 
            0xB2775A5EB1B8B23AULL, 0xD85261043A4ED793ULL, 0x3923922B2B11E695ULL, 0x9491729AFC16D2DAULL
        },
        {
            0xF98899BF442A6A43ULL, 0xD5D069C96A300973ULL, 0x9321B84F09ECD149ULL, 0x0ABDCF3B8F42858DULL, 
            0x64279BAF5B4BE0DAULL, 0xFDB726F3D2BD886AULL, 0xC2F9FCE9E9434F5AULL, 0x2F1E645B6FB6928CULL, 
            0x2331735F06700C5BULL, 0xA6420031B675CD97ULL, 0x619340ABEA612FFBULL, 0xF0E765E266681040ULL, 
            0x4CBB5FEA34AF7A33ULL, 0x07684EB9D03897F7ULL, 0xE8C60F432ABE2C0BULL, 0x43794DBD99F784B4ULL, 
            0x637191B4B2950974ULL, 0xAC85995165B0FBC6ULL, 0xF5841ACFC46A5E34ULL, 0x93733470CE897CEAULL, 
            0xF09A130D49CF40B2ULL, 0x8F117C1453149368ULL, 0xA380B2CC816763BEULL, 0x5DBBBC1B982ABEEAULL, 
            0x79616ECEFA56D0E3ULL, 0x543CFAB0B9B93632ULL, 0x11B00A125CEB97D5ULL, 0xB5D81093D01CD391ULL, 
            0x31412E580F38F9B6ULL, 0x3D2349F92A8CF7A0ULL, 0x81E1169B670BE338ULL, 0xA1A6AC0A7B26B521ULL
        },
        {
            0x9F6B7E0B4A2B7CE5ULL, 0x10A0AB513EFAD942ULL, 0x0A0E77B04CDF97E4ULL, 0xF1E160DD6D5A9A1BULL, 
            0x265195965F74D3D4ULL, 0x06EE516461A083E5ULL, 0xDB4CDC4D10C3C17CULL, 0x20161CF6952D4799ULL, 
            0x4B98300534FABB6FULL, 0x9554EC4FACE45A40ULL, 0x0C186FECF611901DULL, 0xF81A46946FE1D5B1ULL, 
            0x921757A1FB5C3769ULL, 0xCFE59576D45460E4ULL, 0xC57B219686DB1147ULL, 0x66370105BBF43396ULL, 
            0x074D080899E6A4E3ULL, 0x3E5945406253857AULL, 0x777C067AAB10878FULL, 0x0A5A6FB3606843F8ULL, 
            0xC5BCF2986E94E426ULL, 0xFB9E26D46B63AAD0ULL, 0x55EFC992ECC64398ULL, 0x0021D215E3D37CA5ULL, 
            0x310E57E924AF8D7EULL, 0x24A334640B1C1927ULL, 0x482B4EEE9240C998ULL, 0x9081D2A641FE1D7DULL, 
            0x037FBF36A17CF982ULL, 0xB9F221D73E10E5BFULL, 0xB2CE0E56EF4EAEEFULL, 0xD29F5FC4A885A183ULL
        },
        {
            0xE79571F4E57C8076ULL, 0xCC2515C7C4871248ULL, 0xD895F8ACCE322BB0ULL, 0xCB6F34BA940EBFA5ULL, 
            0x7DF2464DC30E54DAULL, 0x981320F295BC8FBFULL, 0x388FBD54AA49C3F8ULL, 0x83C24A107F5F231EULL, 
            0x9B49A4F476F2F486ULL, 0x78330854A1F478EFULL, 0xB8431DE4BCE5E46CULL, 0xF56659EC9628FF88ULL, 
            0x9314E85E7C4378AEULL, 0x602800177899EFDAULL, 0x8D95AC373961112AULL, 0x714EEF3CD764D362ULL, 
            0x6A21E2FB020FF774ULL, 0x0F5B98813F49C372ULL, 0x96E002E1913E3A8CULL, 0x70F7D428DA58B0BCULL, 
            0x69DB4A0C6786A560ULL, 0xBE9C06D8AD697ADAULL, 0x0C93634B12D17761ULL, 0x20419D74082E6A22ULL, 
            0x5ABFE4D17565DFBAULL, 0x8D0F509EB91FED4CULL, 0xFE2896638FFD1D08ULL, 0xCC0D73AB480C410EULL, 
            0x24013AEF1DB0AB5EULL, 0x755A108021928EAEULL, 0x0FDC8468E70FF21FULL, 0x2CF51079E805FE9DULL
        }
    },
    {
        {
            0xC71FBC050064F7D2ULL, 0xDCFBC5509291632EULL, 0x055EEB3081127BEBULL, 0x2FAA74FC1C6ED800ULL, 
            0x3EF9D9F20FD8F556ULL, 0x4EC00DAE8906243DULL, 0xC32B8911289828E4ULL, 0xCEC7DA81B154702BULL, 
            0x52889E02D7A9D88CULL, 0x4EE4B3DD97826FFEULL, 0xE1108D0B19E14959ULL, 0xAB82B280ADC692FFULL, 
            0x0FB9508DED5965F8ULL, 0x825C5A9BA827FEDAULL, 0xC5B886A35AFD0838ULL, 0x813FC88C09FE03EBULL, 
            0xD89583C0E6A2C05CULL, 0x5CFCA8B11BDDBF61ULL, 0xD15B671DC15F0DE2ULL, 0x9FD4450AA9379228ULL, 
            0xDF2EF9F5C73C6F52ULL, 0x55D9ECA239B7A930ULL, 0x33D3A285587B0377ULL, 0x04BD0E40FE89E7BDULL, 
            0xE0AE48D2496C6470ULL, 0x454E7D60BAAF4B64ULL, 0x183C6C18F3AB1B2DULL, 0x013F81FF15FD0B7DULL, 
            0xEF6274246245B01DULL, 0x0F1AD007766436BCULL, 0x7AE4DBAD125491D4ULL, 0x6D34339BF8388172ULL
        },
        {
            0x11B499FD1874A477ULL, 0x5559DFBB3BFA420AULL, 0xA870D5E14CC02FC1ULL, 0x9B7767867B0A24A6ULL, 
            0x9AD3D3E3DABB2844ULL, 0xCAC232DAF4F372E7ULL, 0x498E441B533B941CULL, 0x9E12862A6AE95A44ULL, 
            0x22FB379B024B5946ULL, 0xBAC65F04864F15EAULL, 0x0DC264D0BBB1C7F0ULL, 0x3DB8CB0763B39EA4ULL, 
            0xB858FB9651507B33ULL, 0x392E430282EF74F1ULL, 0x2FD9C85921F90113ULL, 0x3BF7EE12911DCAA6ULL, 
            0x3CA916C2C78B80A1ULL, 0x67C57568D74DA8F9ULL, 0x9C3AED3DEDE21024ULL, 0xAC5D99ED745BE485ULL, 
            0xE2A5AD5E243C0EFBULL, 0xC28D4C1F1114601AULL, 0x3E84DEC13E486F8BULL, 0xB90648B618EA5F04ULL, 
            0xF7737DD027E7F7D5ULL, 0x11773D7DBA5E5FB0ULL, 0xC9752D0BADC98AD9ULL, 0xA04E6ACB7FA510C0ULL, 
            0xE3750E56ECE3B52CULL, 0x343D2D7FE9E0D193ULL, 0xBC898C02646048F8ULL, 0x919C5E7026B459A0ULL
        },
        {
            0xF448F1062AA7EB33ULL, 0xE439F23EF8637DA1ULL, 0x76002D62AAC158E2ULL, 0x885D92D2C45CA4D9ULL, 
            0x4A2872D7297D760BULL, 0xE8C3FED62082D6EBULL, 0x24BF29D48FE61283ULL, 0xB2351419E7C62C9DULL, 
            0xBE362C37AFBBF060ULL, 0x22275CF2E21874FAULL, 0xD0CE2075033138EEULL, 0x51DE0F214ED37B57ULL, 
            0xCAC5A2D5FA0B7F0FULL, 0xACDA67F06047ADEFULL, 0x71D437F050E2F396ULL, 0x12951195F35AB8ABULL, 
            0x7051556CA61BBC23ULL, 0x3078A70E6161E506ULL, 0xC413666FDB9560DBULL, 0x1337308EA3AED8E0ULL, 
            0x9155A67C58C70633ULL, 0x4647CD5E07951CEDULL, 0x4B35867BAB280154ULL, 0xD596432F862AEB54ULL, 
            0xDFD8DCAADA82021EULL, 0x5D7E65613AF50721ULL, 0x6FFA4F1186317011ULL, 0x07B3D300D4343AAAULL, 
            0x0C4F10B36A4F903DULL, 0xA1F843898D3BECC7ULL, 0xF5B6E71873A3F978ULL, 0x93688724C2DA92EEULL
        },
        {
            0x51462E0E6AE00A02ULL, 0x3F3C4CB8A54AE012ULL, 0x5CEB9B58C6227B27ULL, 0x7AD3FB0AA9FF4B84ULL, 
            0x96AD01F87932F66DULL, 0x18BF7DF812449546ULL, 0x545761737BA4BD39ULL, 0xF3075D805AFE75C1ULL, 
            0xE9EE0685636DD85CULL, 0x9C66121034C4412FULL, 0x7378870BEF34ABBCULL, 0xFBA678AEF6047FCAULL, 
            0x46D70325B724F281ULL, 0x2B4DD1D6133BD4BEULL, 0xCE0466811238D073ULL, 0xC4ACAB686B50690BULL, 
            0x941EA1CD8668BE73ULL, 0xAB8973B356BAE698ULL, 0xB351D9FCD487D3E0ULL, 0xFB67675F1FEEAB92ULL, 
            0x0B113DB36A907EF2ULL, 0x4B9C58AF3AB44DC3ULL, 0xD0AEFEA8CF3AA7A6ULL, 0x72C0A8B2C1FFB2CDULL, 
            0x0ECAA39F5D6C1375ULL, 0x88A6AC7FACE30857ULL, 0xD0A936B38FBBA6D9ULL, 0x185A067D1CD1F2A3ULL, 
            0xA376CF85655823F4ULL, 0x731D53154B8A2A50ULL, 0xF90C2073A752CF8CULL, 0x4ACC91DA70B798CAULL
        },
        {
            0xF76D6DCF959EA613ULL, 0x490A051E767AA320ULL, 0x9B198A24EE2DE6C8ULL, 0x3644067D7FF14D75ULL, 
            0x648EA70FEFB1390EULL, 0x76788B9BC5FED235ULL, 0x5BC051C28739E865ULL, 0xD109BC51C9BA73A7ULL, 
            0xAD060E020643D47EULL, 0x4CB21C025C1D0D28ULL, 0x80A04D669433860EULL, 0xF069B592EA658673ULL, 
            0x94BFE7F055E4510FULL, 0xDC3AB5BB090E8A1CULL, 0x124B2790AB72B7DBULL, 0xC8F31409567B0344ULL, 
            0x18755570A9739CC3ULL, 0x0AC35FE09755B46CULL, 0xA559E1D7366A5668ULL, 0x0C7182912064A1F2ULL, 
            0x58C5D202E58023A6ULL, 0x69470B5293697A88ULL, 0x7EC0F5C2F0BA2C60ULL, 0x11E52DBCF48E105BULL, 
            0x1C075C49876DE28CULL, 0x056474EA34E89E6FULL, 0xDDB5CCE5DACE845BULL, 0x68EB5148527F57A4ULL, 
            0x02E55F8AD5719341ULL, 0xCA287D5EE60E75A1ULL, 0xA88C3C2F6BBC6F2CULL, 0x51DFCB6AC5A41280ULL
        },
        {
            0x8925CC5A0FF50281ULL, 0xE01953D9AE3E7BD0ULL, 0x1D0609759142F07AULL, 0x759613AC028B7F82ULL, 
            0x288F7C0B8DFF90A9ULL, 0x5CA632099B4ECAAFULL, 0x606C431B37A36AD0ULL, 0x839575CE79F7C498ULL, 
            0x21A3B1BFD8494639ULL, 0x565D32AA66D249D0ULL, 0xBE8B57561B4CD6E0ULL, 0x93711CDF04DF9D8BULL, 
            0x1B34617E021EDC04ULL, 0x712B9C452E76DDB6ULL, 0x2840AA103D0DB63BULL, 0x243A8F38AAA02E8FULL, 
            0x9F04D81C5C5B04C0ULL, 0x5D5753E48609AFACULL, 0x604C666A62B1050FULL, 0xBDAEA0B679D2C08BULL, 
            0x0FFB27D61D3CCFD5ULL, 0xD4B025D9857D3747ULL, 0xFF0DD23D672A1CB4ULL, 0x399139926E360F05ULL, 
            0xDB66565E053AE5FEULL, 0x10E79C7C35FCFA49ULL, 0xE220A73F1B0EA7CAULL, 0x322B1CB5103D5768ULL, 
            0x2ED395CB2BF616BFULL, 0xD5C5E1039BAA4D5FULL, 0xBD0FDF8315E5CB44ULL, 0xEBAC68CF5AE5AB73ULL
        }
    },
    {
        {
            0xD4D2AA6970F788BCULL, 0x600DBDF28549CFEFULL, 0xFF6DFEDED9F9141BULL, 0x8F8F6C7726BC46AFULL, 
            0x7E91C2E3689CB82DULL, 0xDB84C7FC8DC6FAD1ULL, 0xA8714074B4C9D7B7ULL, 0xBD1EE52C914E0E16ULL, 
            0x58A504EA3AA04803ULL, 0x588FDA55ED159344ULL, 0x26188C32ADD14FF5ULL, 0x92086835F01340C8ULL, 
            0x18C261EFE7323AE0ULL, 0xEDEF71E22C43D59AULL, 0xD214BDD7CEA0A638ULL, 0xF212ED9886C8414EULL, 
            0xDD0CDFA6A530AB8EULL, 0x56E71248107FC436ULL, 0xA01FC8489B9F8A80ULL, 0x650B7047236662D4ULL, 
            0x7BD88686C48C7FC1ULL, 0xF35FC56EEAB9F53BULL, 0xACE731869BFACADFULL, 0xE44DDBD240FB0B2EULL, 
            0x3CC6E8CDD9668C10ULL, 0xF66B360865C80398ULL, 0x76C4FF9CFD4D4051ULL, 0x3F4D842E7637CDB8ULL, 
            0xDFDB1314CD63AE54ULL, 0x16F0EA521924BB87ULL, 0x1F732FC390DBB1B0ULL, 0xCC3A537C8EC1EEF2ULL
        },
        {
            0x8999B1DDE4A90B96ULL, 0x4FC1110EEC91DA71ULL, 0x584E17AD540F1C7EULL, 0x02AD6557208ED65EULL, 
            0x0B6A9FFAE71A27F1ULL, 0x01A774CF786DD8D0ULL, 0x3AA5554DBFBD2300ULL, 0x67EF68BBE81CA898ULL, 
            0xDECFC71FE1009AE5ULL, 0x742E16A7853792ACULL, 0x7248A695D900E31AULL, 0x6BCECF7E2F57AAE7ULL, 
            0xA531399FD5D6B2E6ULL, 0xE73C56096F3541BFULL, 0xFA5796EBC2315616ULL, 0x74F9E850C4CBA443ULL, 
            0x0ACF6C3F026C1311ULL, 0xB00F22111E878B48ULL, 0x69A1FCCB7594616FULL, 0xE1ED83791589409BULL, 
            0xA409AA9F907D47B9ULL, 0x668650357A5A0EC9ULL, 0xB001AE421607D152ULL, 0xB9A1BEEF217E2143ULL, 
            0x7B099609E5097AD5ULL, 0x25D9FB3D4BC90A23ULL, 0xF4988D015CF45EDCULL, 0x384C94C939D63D7CULL, 
            0x71A513658DDAE1BFULL, 0xCA4BCA5B29765D0BULL, 0x245121DC10B5748CULL, 0x0A8B40C5F2DCD4C5ULL
        },
        {
            0x5FCACF6AE9488907ULL, 0xC6FED2002269DB4CULL, 0x7060BC7003210F4BULL, 0x881126ABB3258C2FULL, 
            0x23CFAFDE70A7D79CULL, 0x51C9A9E6CD3A0EFFULL, 0x25E711709A4976F6ULL, 0x2ADBBEBA27030DD8ULL, 
            0x6E1CE79C6A639793ULL, 0xF4F57E59D0F32787ULL, 0xF42F77C83184EB4BULL, 0xD239414422D894F3ULL, 
            0xE0C1F7ABC674F24DULL, 0x8F5A5C10296B0A8EULL, 0x602E2B2927CEEDEEULL, 0x8BF3A6D6EF5A2627ULL, 
            0x86451CE4813B82DBULL, 0x6FA314E34FA5A986ULL, 0x52DBCC8F432009F0ULL, 0x84F14093C9008437ULL, 
            0xAAC1F6E6AC9783D8ULL, 0x82CA28A6EDCD5C5CULL, 0x9E569DAAA39C93F1ULL, 0xBD8670B2064F9126ULL, 
            0x62D09028502A0878ULL, 0xF7A8BB37FCB3C6BBULL, 0xB44473BAC440D2B6ULL, 0x3E7CD7E8516EC2C6ULL, 
            0xAEFBF795CB20F6E3ULL, 0xA6DE6B9C4096ECECULL, 0x5E1A15F8B3EB6AE1ULL, 0x9AA4E88ECAC827F8ULL
        },
        {
            0xD8BD740DE66D27B7ULL, 0x52BE0C26C31A8165ULL, 0xEF99AB3961D9C7F7ULL, 0x5BA71641E813D5C8ULL, 
            0x207BFC7277CB0B6CULL, 0xA87B585136F5153CULL, 0x70CC33691808F6DBULL, 0xD17283904CFC1D12ULL, 
            0x5888937D722B7612ULL, 0x02E06B9C3DD496A6ULL, 0xE86E1691AA018129ULL, 0x3EF9511490D3EE1DULL, 
            0x355DD8AA5ACCF1C0ULL, 0xBF1DB8A86DED397CULL, 0xBAFCF68E25FCDD42ULL, 0xB71414083F72B888ULL, 
            0x471FD53104DAE36AULL, 0x9EF27F533BC75449ULL, 0xD2ABB1D67D6C11E4ULL, 0x4AB2409B59D435C5ULL, 
            0xE92398ED6055D6FEULL, 0x628903FFE309D80AULL, 0x3050D79D4C91C559ULL, 0x51D169F4B8B5D98CULL, 
            0x5C48C8DF8221FA9AULL, 0x36F00254CFE206A3ULL, 0x46FC81FA48F53F59ULL, 0x7E372F3BEB304EEDULL, 
            0xC18C1E9F3C9B3B48ULL, 0xA815BEBC0130D74EULL, 0x78C8B87BBE25F3A2ULL, 0x0686811B862FEE5BULL
        },
        {
            0xDECF69E24F99C6A0ULL, 0x38A51D8FFEDAEE76ULL, 0x7D976B40CD34DF84ULL, 0xF0F3F6E0299D9563ULL, 
            0x76326E5BB6860F98ULL, 0xD85C69B6D0B9DF53ULL, 0x0E7A1E89DB81403DULL, 0xA246A997E35F77F6ULL, 
            0xD0960408F097EC99ULL, 0xA2F72BA45DCF7643ULL, 0xF35898F0EE9096CCULL, 0xBE0CCE5633C2246CULL, 
            0x80A458B01C301AF3ULL, 0xA75E9A93562517C6ULL, 0xA17267ECE0326E2BULL, 0x50BD36705F584435ULL, 
            0x96A7E9D17E2EE232ULL, 0x6C8B2FE0504BCEDFULL, 0x07FD70CFDEE588BCULL, 0x794761FED9EF3E1BULL, 
            0x49BB97CB4B827E1CULL, 0xB7EBB230A2B58CFDULL, 0x809C79BF4DB81DC6ULL, 0x3FA07B15894D09E8ULL, 
            0xFBB79AF86B8DD8F3ULL, 0xD814A43D41768518ULL, 0xB57FC04220AB7BA1ULL, 0xE764D9109570F4A9ULL, 
            0xEF875B14F2FE6F11ULL, 0xED9C7A8D73EEB850ULL, 0xA209DF2271A94D87ULL, 0x2383222765D11FB1ULL
        },
        {
            0xBE02E9068237FF36ULL, 0x508B01A32CAA65C2ULL, 0x7920BECF03EF9472ULL, 0xA8031B21DCC2D5B0ULL, 
            0xE76876DE746A0B88ULL, 0x6DC1F6FC9BE63FCAULL, 0xE237BDB907AAF6D1ULL, 0xA201F7E48AF09B7FULL, 
            0x3C2ADE73AD9FD5B9ULL, 0x81A91A6CC68DFAD5ULL, 0x7ECF18DE61EABD3DULL, 0x50513931E20704DCULL, 
            0xA3CCC5C051DE4A0AULL, 0x7F5A009574D92345ULL, 0xE34390CAE9B8E15BULL, 0x97371A41072D20E7ULL, 
            0x52C565EB90E76D8CULL, 0x833062587D3ADFE4ULL, 0x2B81DEB074512C36ULL, 0x1D53EE970CDF2D5BULL, 
            0x36F59A0DA1743731ULL, 0x837120423B094ED1ULL, 0xC6E613BB04D361D2ULL, 0x4902E4E745103E18ULL, 
            0x744F58E1558D826EULL, 0xAA7A3457A137B085ULL, 0x8495B34A6DC72FA2ULL, 0x22DA53FC9B05E00BULL, 
            0x593F80FF0B9AC326ULL, 0xEFF13AA1571CE927ULL, 0xDD980A736042A357ULL, 0xCCA6F7A14A6B5E29ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeySpawnConstants = {
    0xF77ED64497D3DAA8ULL,
    0x89445DA81305427CULL,
    0x3E78D9D83D6F042BULL,
    0xF77ED64497D3DAA8ULL,
    0x89445DA81305427CULL,
    0x3E78D9D83D6F042BULL,
    0x712654BE9D683F33ULL,
    0xD170C9F149E55524ULL,
    0x30,
    0xD1,
    0xF3,
    0xB1,
    0x7D,
    0x69,
    0xA1,
    0xD5
};

const TwistDomainSaltSet TwistExpander_Castor::kSeedSalts = {
    {
        {
            0x669DF1F0BAA08C15ULL, 0xA79B84761837E5F9ULL, 0xCD3DA9F7F3AF22BDULL, 0x02C2795F2EF5545DULL, 
            0x30A8BC6C17D1B259ULL, 0x0A0FFA7811810CE9ULL, 0xE77E5BB3D3463B80ULL, 0x26797161A42EB852ULL, 
            0x51DA4BFC21DAA566ULL, 0x598C729D859EEDDFULL, 0x717C082F5DAC4D7CULL, 0x762488943E529D93ULL, 
            0x085CC3516168B1D9ULL, 0x3CC97A5569EF4F98ULL, 0x59ABD99772BE76A9ULL, 0x2789C3311C75285FULL, 
            0xAA9BCE180511ECFCULL, 0xA30929D0B023EFF6ULL, 0x2C7C330BFD2345C6ULL, 0xADD88343D0FF5310ULL, 
            0xDD1D4FDAACF1B5D3ULL, 0x140863FFD67C7FA4ULL, 0xE52636268566C241ULL, 0x7F232868A2CAF3A6ULL, 
            0xBAB24E681A0DDB84ULL, 0x9FCF60DCDFE991F6ULL, 0xEE1341A33586DE22ULL, 0x5B61E76BA59FAD42ULL, 
            0x1309DBF5ED4287F8ULL, 0x38DA5739A6DAF64EULL, 0x78F5643750D0235BULL, 0x647BA6E53EC50F11ULL
        },
        {
            0x6685ED25FD3432B4ULL, 0x60AF5CC4E0FFB1B5ULL, 0x9FBF7A4383E391B0ULL, 0x978831C6A676215EULL, 
            0xCEF7AEE6C13B7414ULL, 0x95B01B20B6AD5EC1ULL, 0x9A29DA897B17BC7EULL, 0xB25A780CC7E33335ULL, 
            0x7439E6EE64931D56ULL, 0xD5B0DAA0AAB2F3F5ULL, 0x37FB6E686D006806ULL, 0x54EF15F16EFD4A9EULL, 
            0xFE76F0EB57FB3DA1ULL, 0x9CD33DA8E96A4F02ULL, 0x9D63159A62F54B27ULL, 0x9961CF147CF48908ULL, 
            0xD6DCD9E7B64F718AULL, 0x103F6A87BBF26FECULL, 0x104ABE7512EA8A68ULL, 0x3220B291937710D1ULL, 
            0xE3B9B3461A960C66ULL, 0xAA48492A3435FE20ULL, 0x43EE393708FB224FULL, 0x0063679F711AE243ULL, 
            0xA167387D98038812ULL, 0x48A0F9C7A77C4C4EULL, 0xC16157C978C88434ULL, 0x7CAB34C21585CFD2ULL, 
            0x37F326312A791B17ULL, 0x82DFC69D55BA1BEDULL, 0x041C53B22431F6D9ULL, 0x9F0C1720FD71341BULL
        },
        {
            0xC960136A4D5C68AAULL, 0x788424FF6CAB1FC5ULL, 0x5408E0F8C2113850ULL, 0x4025F4D16978A496ULL, 
            0x5797F048A81B9349ULL, 0x08B489CDC1D42992ULL, 0x78AAE6E6219E4471ULL, 0x20FF4FC29A7D7440ULL, 
            0xE50E1A2D0CF3FF2AULL, 0x31F7FE48D8EFF47BULL, 0xCCA1C29D4D918657ULL, 0xB96ABE67EE9E3B46ULL, 
            0xC8D25196977A7FF8ULL, 0x932F65A66AE8342AULL, 0xA6E846D50A59832CULL, 0xE77A5B2BADE2C89AULL, 
            0xB2099E30F848A326ULL, 0xE97C311F6C04618BULL, 0xDD4FF946E824BE9AULL, 0x9A8081658CF0B40CULL, 
            0xECAE23BD6339FF93ULL, 0x38FAE591CBE4E0A6ULL, 0x04FB5A995B3B7F51ULL, 0x0157C49456C5DCD5ULL, 
            0x83DF912AF212D4E0ULL, 0x1468C830A871969FULL, 0x70081CF59894AE80ULL, 0xEC2B437E69A4CFFFULL, 
            0x96FA10A681D43DC3ULL, 0xCE416062E2B99A81ULL, 0xF03CC2BCD36637F8ULL, 0x01F3C95F4D62BC97ULL
        },
        {
            0x53F834BC7EFBFBA6ULL, 0x83828A74D8188102ULL, 0x173BE58DC7D84E87ULL, 0xF0C9B856BAD2BABAULL, 
            0x99CB5A1FB8A74728ULL, 0xC9C325E7D2F22D44ULL, 0xD8004C835C826AA6ULL, 0x31AD650D5A0C2D10ULL, 
            0xCE868E8D7FACC2CCULL, 0x2E3E0AC7528DF476ULL, 0x8C09389007300F9AULL, 0x42A521A879C35A51ULL, 
            0x65EC50D567220CAEULL, 0xA0745B2B9AE5650DULL, 0x7BF83C16F5FF115CULL, 0x8342834B9EBDDA11ULL, 
            0xE38C70416B5185F3ULL, 0x329E1AE07C3E4735ULL, 0x14E226574373D225ULL, 0x039886A43BD787DBULL, 
            0x61BD146A425CC5A2ULL, 0x094F878E321AD5BBULL, 0xD70EB51BDA2C9403ULL, 0x4E11E915CA02FE96ULL, 
            0x7EA78C3B5BDF2000ULL, 0x680EB251DCC8CEC7ULL, 0xBB660103565C9008ULL, 0x7217E6ADD8E85D96ULL, 
            0x814A20BC0CA615B4ULL, 0xD48D436A98785624ULL, 0x3556B6A18A3151B4ULL, 0x3351973FE572EFDAULL
        },
        {
            0x0B4B26B6C5BAE527ULL, 0x5CC7A86D5880AE6CULL, 0xCD943628B823B156ULL, 0x84B389EA2F214755ULL, 
            0x2FE43633EBB0D2BCULL, 0x8EB1EDFBF888AB2AULL, 0x0D3E2DEF8E8FCF22ULL, 0x9BD0B79901949CF7ULL, 
            0xE5D26FDC11D73B42ULL, 0x11D5848F6AB42EF6ULL, 0x20CFA7DF9F48DC0EULL, 0x9A824BC87294CBA7ULL, 
            0xEC27B7AB76432339ULL, 0x33D323593A08E936ULL, 0x893A4D9A026AC58AULL, 0x4314A0C05591DDD2ULL, 
            0x65FDE8E74FAE1D4DULL, 0x30BBF494BF4AC8AAULL, 0x8FE55AE6C72786B6ULL, 0x611060D1650DED40ULL, 
            0xC97680D871A330EBULL, 0xDA7AAA5589CD34B5ULL, 0x311E320A284C7CC5ULL, 0x9418D58D0D8F7F7CULL, 
            0x54131F0346E88EF2ULL, 0xF2A1658C302D5526ULL, 0x9CE4650354FF006EULL, 0x62D62360ABF5E55DULL, 
            0xD1F924943AE9F0F8ULL, 0x4A174683D7610619ULL, 0x78A0966887667B34ULL, 0xFEF9B1966D218C6BULL
        },
        {
            0xD601513D41E635E2ULL, 0x8FDA771A0C4AAC36ULL, 0x525EECE510C2ED2DULL, 0x506480E470BD6416ULL, 
            0x34140EC9E9EA1234ULL, 0xC6A2B89E552B697DULL, 0x6E2D98018A04FC8CULL, 0xF2487324838182F7ULL, 
            0x39DA2910A2CF0E38ULL, 0x3B3202540EFE9AC6ULL, 0xA087C06A68C5800CULL, 0x3017CF4A31F35ABAULL, 
            0xF96B00729CA3D810ULL, 0xDBC475E9C9290124ULL, 0x615814D4AD348D56ULL, 0x1B57F91A9D3C629FULL, 
            0xBC79F93A0B336304ULL, 0xB976FEB7710AB0EAULL, 0xA30383891E174C20ULL, 0xE15F18E2F9198ABBULL, 
            0x01CA649C67178695ULL, 0x7058397F874D279AULL, 0xA0C566F8B2AA47F6ULL, 0xD38D3E2FD300DBF1ULL, 
            0x09370FBA1651F4F3ULL, 0x8BFB22E22618D493ULL, 0x095219199FE21A97ULL, 0x0922FEDEEF5CBC01ULL, 
            0x7A3039437718FAB2ULL, 0x65FB6E8283D50BDEULL, 0x7045C46BFE8302F3ULL, 0x0BFB6C4D2268DD9AULL
        }
    },
    {
        {
            0xD7F81B073B270538ULL, 0x2387443CFD2057C9ULL, 0x6DAE379CAF124E5FULL, 0x4FAAF580FB065BECULL, 
            0xA3427BF349B9C0B1ULL, 0x57A3D08731EC541DULL, 0x71F19D975ED2199BULL, 0x113D2ED20B56AD80ULL, 
            0xAB9739E465D21957ULL, 0x71FDB28BB07AAB72ULL, 0x628FDF9AEC46700CULL, 0x9EA5E445D6F4BE52ULL, 
            0x01FCFF2A8FCE6E66ULL, 0xA08B3E33FC8C9ED8ULL, 0x0A39635AA8465444ULL, 0x08E57A2509E2392DULL, 
            0x01F12AA6815AF174ULL, 0x68C6AAF456597A62ULL, 0xDF5FB22DAD21CAA4ULL, 0xD6317A0DA1FA2C28ULL, 
            0xAC0B72D8F5F888BFULL, 0x4192884C2E543907ULL, 0xF5F93ED38FDD9A24ULL, 0x43ED19CAC107F33DULL, 
            0x61027C2492A7F677ULL, 0x4039A38049702681ULL, 0x6A5A697EDDAA18BAULL, 0xF1E45E2B0B4AA452ULL, 
            0x94CF158006513005ULL, 0x21232F8EE4B3F942ULL, 0x34BC3D86BB92154EULL, 0xFFAA6478DF98BF99ULL
        },
        {
            0xD0FA59FAE305B09EULL, 0xA72A67373AE1A36BULL, 0x7DCFA9231D0DF220ULL, 0xC9024968ECA115ABULL, 
            0x8FCD165EDEA5C782ULL, 0x1A550FD9CAE773A8ULL, 0x05B0404DA6DCEAE8ULL, 0xBACA40CAF8BF8179ULL, 
            0x977E62FBF0ECBD54ULL, 0xDF1B9BD61D40F826ULL, 0xFD1FEE0B605E25CDULL, 0x0405B69009DEF1F5ULL, 
            0x544592073004A9D2ULL, 0x2EA8AB5946330722ULL, 0x8C051B010A23AB05ULL, 0xF76F2C5110E3ADD1ULL, 
            0x6243BF8422AF293CULL, 0xB95C2AB3E25BAF3AULL, 0x3E9ADFFA3C7B18CBULL, 0xCC26969FC8A4F181ULL, 
            0x678A2D39E5AA4AF9ULL, 0x8A3AA6B94FB3DB99ULL, 0x043A92C51544DEF9ULL, 0x979D496F1DE80BD4ULL, 
            0x01CE6D13E8512D48ULL, 0xB552FF62FDA0E847ULL, 0xC89852DDB0FDB056ULL, 0x3975D4B6A6B0B70EULL, 
            0xC32D1B5033DBFA2CULL, 0x8E94F8BAC9F3C322ULL, 0xB18DF4193FF6FA6AULL, 0xE54BBA512684B550ULL
        },
        {
            0x77B9D8E3626E28CFULL, 0x0F187AB1BDDF8751ULL, 0x2103356430D670E9ULL, 0xA4C0FA6AC31273CDULL, 
            0x98B8AECC081F632BULL, 0x9EF989C11A1D94DCULL, 0x4CB997F3096BEAABULL, 0xDD64588B0F14142FULL, 
            0x496A4A7442F6E3CCULL, 0x6A31AD023F5B07D1ULL, 0x3BBFBF69ECCAD806ULL, 0x44D066C49019CDBAULL, 
            0x26B557F7D3BC92FDULL, 0xF06713861F68ECD6ULL, 0xE517420F462F1578ULL, 0xCCE780C6C9C2E808ULL, 
            0xA809937EFF96B556ULL, 0x8E69224DD94908D9ULL, 0x5A0C1C684239AF24ULL, 0x50E59CF908D21ADAULL, 
            0x5FE4E05FC2051767ULL, 0x5283196096F47BFCULL, 0x0E1E276FDB9CC5ABULL, 0xF23469092F4F6978ULL, 
            0xCC32589BAD41BC6BULL, 0x099FF4087231787FULL, 0x812567B101E086D3ULL, 0x85AD0788F105E045ULL, 
            0xE44002BB69E55D55ULL, 0xD0D862C8C5DA0D55ULL, 0xF3812E494D7609E5ULL, 0x040E65F90A61D793ULL
        },
        {
            0xE909CF97A84C7DE3ULL, 0xC0CB5B010DB940B9ULL, 0x5F0A4245A447274FULL, 0x1BD25B4BE306E0B1ULL, 
            0x3BCCD36E96A6FDD5ULL, 0x8FCE86571D27896AULL, 0xAB539643651968B0ULL, 0xC634151A934F15EAULL, 
            0x0F34A076979F5C5DULL, 0x5879C57137FF0B4DULL, 0x29A8CF04CD4426A6ULL, 0x4BC31DB8D1791659ULL, 
            0xCBA945A37E08CD97ULL, 0x38941B13AB3455E2ULL, 0xDE1EE344BFA48448ULL, 0x6D49378B16967620ULL, 
            0x192164113953B97DULL, 0xAED8996A67F2BD14ULL, 0x160414B5D78237FEULL, 0x116EA3BC91A70EEEULL, 
            0x2D183E6AFDBA9809ULL, 0x53F22998AB883E72ULL, 0x4799776B6403D8CFULL, 0x89B6B89C8658B601ULL, 
            0x6E1C461452CC1FFEULL, 0x80BEC95BD3158DC2ULL, 0xB32FC40D69012850ULL, 0xED32CDA9276F3B53ULL, 
            0xE6EB0689A3F34BABULL, 0xE72D7633C51F724CULL, 0x39B2307C97F8061FULL, 0xDD3308AE3D0041D0ULL
        },
        {
            0x9CDA6F1CD0797870ULL, 0xFA7B1B3FFF8E874DULL, 0x0B10998E7533106DULL, 0x888BB86B5B0A86F6ULL, 
            0x6ADF48BECF700982ULL, 0x6FC77047FF98CA14ULL, 0x82C9589629AA9140ULL, 0x8E870B6CC3B6BB1DULL, 
            0x87BA5531A0CEE4F7ULL, 0xB667C6FB3985A60DULL, 0x7463442D10CBCADFULL, 0xD00B2ACF2DD1E0C7ULL, 
            0xF8BA4165EA24141EULL, 0x295B22A7F33820AEULL, 0x52BF4B4500E103DCULL, 0x331F9646B7500E0BULL, 
            0x1DD82D43AF876D8AULL, 0xAB68037E0435E97CULL, 0xEE227C7EEA681C8AULL, 0x80959A01D2B5EECBULL, 
            0x8CB71F4ECBF9F371ULL, 0x7A9557D5B9E1C76FULL, 0x608D5F016D28951FULL, 0x9CCE30BDBC038C2DULL, 
            0x42C776B309924897ULL, 0x19443B234AAB6D24ULL, 0x91BDFA66F2A072D2ULL, 0xA8610A002F93EBD5ULL, 
            0x30FB28F748D8BC49ULL, 0xFB61F1DEE9275257ULL, 0xF4D5F0D67198A4BDULL, 0x735EB34EA77744A5ULL
        },
        {
            0x92506DDA9FA6740DULL, 0xBB4F2B2D1E4B62BAULL, 0x733BF74E39A94341ULL, 0xBF634DEBFE798825ULL, 
            0xF1D848EC143239E2ULL, 0x15AD404B14057586ULL, 0x779D6EDBFC272E86ULL, 0x72933BAEB1471582ULL, 
            0x9838358EB91A1DDBULL, 0xD8918D0929986828ULL, 0xF1FF2B94006DE429ULL, 0xF0B6089359911A56ULL, 
            0xFC8B21AB4DE7D717ULL, 0xE02AF15F49DDB093ULL, 0x0CAACBEEBC596179ULL, 0xE739ED6A4D986386ULL, 
            0x7A7D95D3E9D9E569ULL, 0xB9C298CE66C8730EULL, 0xD7E369C587D47576ULL, 0x21DF056AB7FD24ADULL, 
            0xA4A8EC56EECD47AEULL, 0xB241C7575BD382EBULL, 0xDC405D1287F75350ULL, 0x0D3D1107D57FBB74ULL, 
            0x6BB523FDD97F5A45ULL, 0xE1473DF18B078BDFULL, 0xB3E869D70B8EF4F6ULL, 0xB2474F318B57C049ULL, 
            0xA3D61E4A303CB891ULL, 0x5EEEB197FDD68585ULL, 0xAC313392A50ED529ULL, 0xFD61E1186BB392D0ULL
        }
    },
    {
        {
            0xFE9492B01D95EFACULL, 0xF17D2FF9D543928EULL, 0xE2D8A26B83A42E64ULL, 0x86C50DC97D11DACDULL, 
            0x0E7A8B03FB477585ULL, 0x2A7D08D4026AC432ULL, 0xEB463A101E67299CULL, 0x53ABBCB36B048C22ULL, 
            0x0143673C67992D96ULL, 0x5A314543B77B4D4DULL, 0x2BBD5467D798FDEAULL, 0x9EAC6EF974C02856ULL, 
            0x7E06ACC82E4372A9ULL, 0xF9DDEAE822419F20ULL, 0x35C19EA835AC5562ULL, 0xCA436900C4CB8DA1ULL, 
            0xFF65239E65BDF5CBULL, 0x67BB32BC7209E7DFULL, 0x09DF46BDFC0D3606ULL, 0xC14F301D83C9FFE1ULL, 
            0xC1814FE7D79DCC1FULL, 0x31F350B200A4338FULL, 0x316DB042AB7BD769ULL, 0x1F678B36E448912BULL, 
            0x555F90C52834F2C7ULL, 0xF5C05A0CA313FD80ULL, 0x9FC619940DF5B087ULL, 0x36E62B569B41EC48ULL, 
            0x47779A724BFBF64AULL, 0x15AC3C034635B23FULL, 0x30955B9B175CAD66ULL, 0xB06C66D0FF8D35A4ULL
        },
        {
            0x85C97482002F4D6DULL, 0x13164EE79DD064A4ULL, 0xE337CCEE47603690ULL, 0xDA67061225BA9DAEULL, 
            0xDE5C62DF7344F9FBULL, 0xDDFE96E2CCE7BCD2ULL, 0xD9CC1C11C36A83FCULL, 0x0C83946C5B6FA58CULL, 
            0xCE2BBCD35CFA6A55ULL, 0xBD01250EE814481BULL, 0xBFB9E043D2DBEB1AULL, 0x5A30CEC6EE02B261ULL, 
            0xBDDBB0FAE3E237B6ULL, 0x2A4BA31BEB0BFE49ULL, 0x25746E67DCC621E4ULL, 0x1A2EC99251CD048EULL, 
            0x84D3F7C9359480EBULL, 0xC85B4F0FFBFF0E68ULL, 0xC2C27E06BFF69D63ULL, 0x3B29C2E798A35EC3ULL, 
            0x94E00C83C39EB841ULL, 0xEFB9BDE57E88EA0DULL, 0xF4F2EB256E29134AULL, 0xCCFB9D336E840108ULL, 
            0x8BD78B69FB8F3C75ULL, 0x4FB5E5DA449F5C5AULL, 0x33DB5F7D28C02BDEULL, 0x941BE9284A584814ULL, 
            0xBAC9EF8C6B59E5A6ULL, 0x54C09F20E887800FULL, 0xAFA617B8AF6D540FULL, 0x2F7516B118493C8FULL
        },
        {
            0xB5B15538D225E4D5ULL, 0xCF5900D0A3B3E6C4ULL, 0xBF79B2B3923A97ABULL, 0x08019C028E95D525ULL, 
            0xD4D74286A019FD6EULL, 0xE063FD923643C7CDULL, 0x7DFF99ECD7C1C624ULL, 0xFCC9ABCB1DBCC68FULL, 
            0xA6D3F2E99A3DE1E3ULL, 0x1FBAB98C222B9A65ULL, 0x406C8877D9C90676ULL, 0x8A871901269EEAE3ULL, 
            0x745C3F251D783800ULL, 0x6B98C7B0AE58F3F5ULL, 0xDB819E89E3E463CDULL, 0xFB5AD0A9AA1E9A2BULL, 
            0x523B51429F239C9DULL, 0x4705EC5DCA7BABABULL, 0xDFA35F59CE4F0E74ULL, 0x4C8436025B437EDDULL, 
            0xCD401DA8ED9F7F60ULL, 0x50B001E6AF4C4132ULL, 0xD90F92C45EABC6F2ULL, 0xE5B52E032DFB2E07ULL, 
            0xFA6F81AB1468B950ULL, 0xFEAA25786788FFCDULL, 0xEB61F97C60DE01B2ULL, 0x8D96000844379891ULL, 
            0x0CA738959EB12304ULL, 0x9D901C029BD5B320ULL, 0xA69EAF7D4D152034ULL, 0x5120FFEFD69D1A17ULL
        },
        {
            0xEF74DBD0F2804E6CULL, 0x8DDE90E869D832BAULL, 0xEED18D10AE48DEF6ULL, 0xECEF4A328D94157FULL, 
            0x7D9C4D5B936840ADULL, 0xC82441595ABF323FULL, 0x8A1C382797A26D52ULL, 0xCA46D3A6A390142EULL, 
            0xEF15A432670F0F7CULL, 0x930410307522EA42ULL, 0x31DEB1546313AE2CULL, 0xF4FCB20997965A6BULL, 
            0xA648F0DD63D74EC2ULL, 0x784C126776499250ULL, 0x87C99504E1AB4F85ULL, 0xFFA8065CDA7369D6ULL, 
            0x9C2537F3E4AA4653ULL, 0x53AB74E8ABEB3E15ULL, 0xD556EECEE355280AULL, 0xC1EAA91DF1EDA37CULL, 
            0xEFE92BC26BA29205ULL, 0x99B965E5BCD9A2BBULL, 0xC9DE318B353CBAC2ULL, 0x27664836741E0358ULL, 
            0x3BEDE99D093A6B5BULL, 0xB4119D0230DCBB1CULL, 0x374B27B1D6EE9A10ULL, 0x971D7B0351E8F428ULL, 
            0xF5433D0F8A1D9BF0ULL, 0xD05F4D6F423A9218ULL, 0x9C268067B1E44B89ULL, 0x4B9316CDC25DC08EULL
        },
        {
            0xEDEA32B171BF8319ULL, 0x04459AF2A4742FBDULL, 0x61765E8BC0569492ULL, 0x2C95F68E084B364FULL, 
            0xB0CD29A4C7C496B2ULL, 0xD290E8926F215506ULL, 0x6A4C74FDD12F7C78ULL, 0x3BD8D4BAF66A0B57ULL, 
            0x21AF2772EFB82960ULL, 0x4DD3278F311E216AULL, 0xDD907AF82378566EULL, 0xDB96D8E88F01B4BEULL, 
            0xDB98371269352A91ULL, 0x68019C91B5B0188CULL, 0x8BD2716B3CC876E8ULL, 0x9127213BE70A98C3ULL, 
            0x1DFDD19FEF7CBECAULL, 0x1D1EB7D7AD562DCDULL, 0x631F5CC1AAB12554ULL, 0x5120037F44463262ULL, 
            0xB93BD44BA29030D6ULL, 0x641FA09F280574FAULL, 0x653A1D1000F5E078ULL, 0x4DEC83D7DFE0D389ULL, 
            0x31EA96B627C30AF3ULL, 0xD2C7E68AEB50B6E5ULL, 0x140AC7DF3835DD24ULL, 0x9C849D08D727E83BULL, 
            0x12EF013C9B0A7DCAULL, 0x26FA00674878D49AULL, 0x69C57164332BACF9ULL, 0x725AFA7AF75AC907ULL
        },
        {
            0xADA32D7CBA7AD6E4ULL, 0x8AD7DE0255C41F9AULL, 0x1A64932545E4DF71ULL, 0xEEAF39E5FCAD88DFULL, 
            0x2203B0B89AE753EFULL, 0x8E0D7173AB5C0C99ULL, 0xA11DC5AFADAA32ADULL, 0x14A01B51CDB49EE9ULL, 
            0x1CAD5534211E3EBCULL, 0xA16F09A0BA3D04DBULL, 0xC76E4BEB810C6251ULL, 0xABCC82257C0CD23AULL, 
            0x45DBDE5E6260BD44ULL, 0xAAC28CCA0CEE0EFAULL, 0x949A97BE9FA36A48ULL, 0x65FFEE5222DC317AULL, 
            0x47C48A16EA7FB268ULL, 0xF3AC28B0143C91ACULL, 0x51560FDAA2082BFAULL, 0x5F09602D26AA8C34ULL, 
            0xF5B25953A8492AF0ULL, 0x855367B0F8FE3440ULL, 0x201C8F49A7B1591EULL, 0x8560A7E003ADE7D9ULL, 
            0x57D6B0E456F1A45DULL, 0xFBF0D8D321A15630ULL, 0x8516737962C99434ULL, 0x757446724B10E655ULL, 
            0x2244B69FC7615D3DULL, 0x54EBBD734399BF24ULL, 0xC356F2DE70F3FD2DULL, 0x6AD0EAE3C49A3B72ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kSeedConstants = {
    0xF70261BD446B14E1ULL,
    0xE5ACCAEE44D9D2A9ULL,
    0x97EC6DAA20632FC1ULL,
    0xF70261BD446B14E1ULL,
    0xE5ACCAEE44D9D2A9ULL,
    0x97EC6DAA20632FC1ULL,
    0x62B32B817763A961ULL,
    0xFD237DFB19AE1852ULL,
    0xF4,
    0xFB,
    0x36,
    0xCC,
    0x73,
    0xEC,
    0x5E,
    0xF5
};

const TwistDomainSaltSet TwistExpander_Castor::kTwistSalts = {
    {
        {
            0xEF685A4B2CF5DF02ULL, 0xC80F60A087DF631AULL, 0xD2D4E723FBBD1AD3ULL, 0xA4A86A0D8626BE2BULL, 
            0x03A9BC3358E1248CULL, 0xC96129BD448DCC37ULL, 0x33EFEB89314C5071ULL, 0x3FD79618CB65965DULL, 
            0x610F959146AEAAAFULL, 0xEDF39B5D3A15BFBBULL, 0x6A0C7531B14BD32EULL, 0x98D9A865633E3734ULL, 
            0xC082D9A5B4F4DCEDULL, 0x833857B535E1B807ULL, 0xA23401E27931E872ULL, 0x4224AF5F4E3C2F49ULL, 
            0xC7766736C49FC385ULL, 0xD8D9F392AACB0EC2ULL, 0xB0ACCB747FCF5513ULL, 0xB2F290C33EA263D0ULL, 
            0x5D4B956A3C684537ULL, 0x01414B07E5F1611FULL, 0xB38C13BD90A4D0CCULL, 0xF53915B7366208F7ULL, 
            0xF3FC2BC0D25C08AAULL, 0x54EB80DC3CE8F98CULL, 0xF7E1FB8F679FFFDFULL, 0x3B9026DDC9B4A375ULL, 
            0x30EAA36FE233D115ULL, 0xD6F4068071BD6C66ULL, 0x6BC0EF7566F2BAF6ULL, 0xF516BFB481EA2E7FULL
        },
        {
            0x187FC13DB554A4DAULL, 0x413600D8F7D7C3C0ULL, 0x08F0046B1EC0E91AULL, 0x421AA1744768347AULL, 
            0xA9577E6C5E325807ULL, 0xE2F8FC776FA050C1ULL, 0x089D8E3B38DF44D9ULL, 0x52173A78666BB8ACULL, 
            0x657880A1A5BDA662ULL, 0xC8BE212D26068DF8ULL, 0x9CBA6E6114124AACULL, 0x3C8404C456E33CF9ULL, 
            0x1BB6B712A41A080EULL, 0x9AE25E7F2D17825CULL, 0xABAED44565AC7311ULL, 0xBC91F4C8EFA5CA09ULL, 
            0x6D01F416DE3B92C4ULL, 0x38CE160CD264B057ULL, 0x5E9DAB57942A5549ULL, 0xEAE5A69A424CB4D0ULL, 
            0xFEBDDD2B74A895C5ULL, 0xBF452A2519C58FFAULL, 0xA70AB63FB08B05B0ULL, 0x5F2A260184AC8364ULL, 
            0xF382D442D1A3BA8FULL, 0x1B58F85A64222C22ULL, 0x3D8F028DC64702BEULL, 0x9360BCE48F701035ULL, 
            0x4D5E59B2021B46B6ULL, 0x6F653BA822BDF7E3ULL, 0x917CCDA45AEBA7E8ULL, 0xCE1C1E59CE930F62ULL
        },
        {
            0xC57725D88962EAA8ULL, 0xB36299F54C89FB6EULL, 0xAD82793FA62B5D13ULL, 0x2C58D346A9A9B7F6ULL, 
            0xFD56A4A53499CE27ULL, 0xC2E1C832F0AE9C01ULL, 0xB047CA1DBB46DA85ULL, 0x498DD6AB0FDFCE3FULL, 
            0x8EE47662CA025B9BULL, 0x772EE92D05735E11ULL, 0xDFEC41235E6CF1D4ULL, 0xDABC7095AD1F4866ULL, 
            0xC4025C16B5C90987ULL, 0x279461AC8FB8D3F7ULL, 0x8B7A632C59236926ULL, 0xB052312B1646C393ULL, 
            0x3112634315ED946DULL, 0x63EB7F1297B7FA74ULL, 0x09BF6DB1E38BF6B1ULL, 0x25A979DB6EF70E33ULL, 
            0x898AEAAF599D5AC1ULL, 0xB5FCD3253F32A047ULL, 0xD020A339B88D3D6DULL, 0xBC25EE82FEED6CF2ULL, 
            0x4B43FE7280C62DBBULL, 0xBAD8F5924B04096CULL, 0x07D777700570BC85ULL, 0x90E749CBA950CB82ULL, 
            0x084891B0D9740222ULL, 0x4AF4772A825CCF84ULL, 0xEFE041B1BDA57F41ULL, 0x5AD3BE6A5BC06422ULL
        },
        {
            0x82E4933F2156BB31ULL, 0x6B87913273094B3FULL, 0xDC6E0C04717E477BULL, 0x96494601D68B1040ULL, 
            0x4B74BDEF65A1B23FULL, 0x28E144CDB3D573B7ULL, 0xF04CB41794184955ULL, 0x958033D6333AAA59ULL, 
            0x09FB8C931D57E907ULL, 0x4F5FDDC1FEE730A8ULL, 0x64B45DED0933F1B7ULL, 0x8AAEE7C1225D88BEULL, 
            0x490A85750B0D3D4AULL, 0xC4F0A4CB6B183661ULL, 0x94D23B467452EFB9ULL, 0x2A86211435DE44A6ULL, 
            0xA835B59C84A36C03ULL, 0x0D8734287B14D36EULL, 0xEDA671ED1BD67C91ULL, 0x1442E658D8604189ULL, 
            0x85BB8417E5C3A865ULL, 0x0A8DCD35F1B351D0ULL, 0x019B09CF4539C64DULL, 0xCF1D2CC1F4A226D7ULL, 
            0x2763CD4F25FB4A8DULL, 0xEEB7F5729EB97A3FULL, 0x0E931663A5701802ULL, 0xD1F10EDD4AC5BBB3ULL, 
            0x2D3F779A202AA948ULL, 0xAB4550BFF3128EC9ULL, 0xFB216E783997C4BFULL, 0x21F99D1C89D106DDULL
        },
        {
            0x9E758C6A44446498ULL, 0x19FCB2FA5E3C87AEULL, 0x5308FD8CE6C70BCDULL, 0x5C82580771D4F9F5ULL, 
            0x839B29CBE1CDA181ULL, 0xA5BB7154D7E4A36EULL, 0x7AEFC58EAFAA3DAFULL, 0x67159FA7D64BC8B2ULL, 
            0x9670744CFABF5FF0ULL, 0x92E93DC00C0FD472ULL, 0x8824DC6FDD327A2EULL, 0x9B1F9C1CDC838536ULL, 
            0x89C1346EBB032C15ULL, 0xE9BFB33D3C2B6C43ULL, 0xB240FE28682FED5FULL, 0xA8B6AC2871AC7774ULL, 
            0x5EFCE885994DF8FFULL, 0xB88040154D0DF7F8ULL, 0x4BBA9B88A18EECDEULL, 0x3FA42144068688FBULL, 
            0xAB055B7E83A8996FULL, 0x999AFDB143ED7DF8ULL, 0x8F91D8EF257E810AULL, 0x05976A64205E41CAULL, 
            0xEA81EC94B0B0A8A0ULL, 0x7F5C963013FF257BULL, 0xCCEAAA69908A2371ULL, 0x56BBB8F0980319E0ULL, 
            0x896F74BE410EABEEULL, 0xC774989672CE1BB7ULL, 0x3D704626003D79FEULL, 0xFDB1B9B28D51C8D2ULL
        },
        {
            0xC2B1382D5B1EA7FBULL, 0x37BF3AA2836110AAULL, 0xAC02BC90DAA68199ULL, 0xF4B1072F52189896ULL, 
            0x537B44E658742A1AULL, 0xFCA09369732446BBULL, 0xB31066C6C01154A2ULL, 0x5FBFDBA44C93107BULL, 
            0x6A6227FDC65DB4F6ULL, 0x92A8FDBF800B0076ULL, 0xCF157E22CB574C83ULL, 0x99704A300FEB9076ULL, 
            0x6EDCF3EEF159D632ULL, 0x4AC30E900C50EA94ULL, 0x6CF62A25B92D2DE0ULL, 0x6DDA260A8B418B32ULL, 
            0x04C4C0D1E3F569C9ULL, 0x6A8F2ABB064A2E1FULL, 0x7ADCE4C7759CA6C4ULL, 0x49DA3D748138C312ULL, 
            0x8ECCA85D42455152ULL, 0x9E4CE51FC46210B3ULL, 0x60A3FDFAD3ECDAA1ULL, 0xA130D2C14D02359CULL, 
            0xB641D27338F13989ULL, 0xE2848D274CAA8E70ULL, 0xC873DB1988FD5CA5ULL, 0x9EE03A74432082DCULL, 
            0xB4E8294503548C6CULL, 0x6A2AF8BD9ECCEBD8ULL, 0x68F2C278AFDC0D43ULL, 0xB72F948E872B9C6AULL
        }
    },
    {
        {
            0x6BFFB208F12A08E0ULL, 0x5998B9E6CFB34A13ULL, 0x0CF28BA26B136608ULL, 0x94D1762A4DC84BD2ULL, 
            0xB25FB6C31150AD64ULL, 0x6B1017B4718629F6ULL, 0x6BE33F10D32C0887ULL, 0xAE11D0A4AF4D0504ULL, 
            0x3355D2D82822305DULL, 0x4E16C65B12773473ULL, 0x172EFA4DF23522AFULL, 0x3928446D61CA4D4AULL, 
            0xD27F80DA2757E5A8ULL, 0x58ACC3C943AF19FEULL, 0xFB99185253F731CEULL, 0x3E76D982C21A6E52ULL, 
            0x94EE9E1A4163C59BULL, 0x3A7F69EF0B45A551ULL, 0xE1BF1FBCC14A3BDDULL, 0x342359D503C01BC8ULL, 
            0x66390FFC9B7ABDA6ULL, 0x1D40CB680AC7B742ULL, 0xB291DB2017F1BC25ULL, 0x3CDFC19126CD2833ULL, 
            0x0D64B6327D4DE611ULL, 0x530C389685B1C2C1ULL, 0x79E13AB00376639FULL, 0x63F9A812323E681EULL, 
            0x609703CAC1CD6B15ULL, 0x447F946B0A6FC9DBULL, 0x8D2D29868B4702FDULL, 0xF81E7222992DE321ULL
        },
        {
            0xE0FD6351659534ADULL, 0xFEAB2DBCFC6C9665ULL, 0xF187C057B68613EDULL, 0x4F85E0E297D3B7F1ULL, 
            0xBEB2CF2A549F9AC1ULL, 0x9F7B962123451115ULL, 0x73FC2FD49198FE76ULL, 0xDB7A0CD3192E5375ULL, 
            0xF347E65CCE76E630ULL, 0x6B92074DFAAAFB76ULL, 0x7B0612CAF4AE0A9AULL, 0x405CBC7AB4ECF364ULL, 
            0xDFA95060CD0AC2E5ULL, 0xF3649F5E2357EFFEULL, 0x00205A25CDBE9F78ULL, 0x98748B2068C28308ULL, 
            0x50025BDA0FA37804ULL, 0x940BC92A54C73E2DULL, 0x05FCA344CE8B677EULL, 0x4A289C861F9BAFF2ULL, 
            0xE5543FCBB77E62D7ULL, 0xF1E207C03C8FF092ULL, 0x5C43C10DDDC2EE14ULL, 0x96CFEE596FC1F184ULL, 
            0x5551EE604F7C19EAULL, 0xBE500CAA643085D7ULL, 0x9CB2B74E1BC3B659ULL, 0xAD5589619250D953ULL, 
            0x3EB7C8FCADA131EAULL, 0xB648747BB38408D7ULL, 0x882F86C808626776ULL, 0x0B2691B2D4C13840ULL
        },
        {
            0xC6F773998DE29416ULL, 0xFC0D4CC163BB93E8ULL, 0x88D1F79AB7AE5EFCULL, 0xBCA5019FDB10A47CULL, 
            0xEB160C7611A385AAULL, 0x9C4DE49477A70CC8ULL, 0x225B3420881B64A2ULL, 0xE75B2FA1F644DCA6ULL, 
            0x6C43B15AC860EB59ULL, 0x295E0006BA9994D6ULL, 0xF7ECC400E6078E3BULL, 0xECB09072E2303E47ULL, 
            0xD3BE3B9AC5ABFFBFULL, 0xADCB5F79FFE9CE1CULL, 0xE832E0589DA07730ULL, 0x162C3C3D467B8877ULL, 
            0x969483954B16E6D7ULL, 0x37D06D74F3D80D9DULL, 0x2299F4232406423BULL, 0x67298EC6E3F21FDEULL, 
            0x5FA18FBEF36627A3ULL, 0xB643375CA4650B7DULL, 0x71A2CA0543204739ULL, 0x410C531F82FF1D98ULL, 
            0x2F1CC02756351B13ULL, 0x2D3DD78434C93A77ULL, 0x504FB09A8783F618ULL, 0x838A4AE056A5ECB4ULL, 
            0x59094BB56C813641ULL, 0xBCECABBB34D1DB83ULL, 0xC2FBE3C1DC51A019ULL, 0x443DAEE4A8AE2139ULL
        },
        {
            0xCDB3CD3B1576E227ULL, 0x8176BC38C8D6C658ULL, 0xBCF38EB5E4829828ULL, 0xC93515A9CE7260CEULL, 
            0xADEB97E80B1BD901ULL, 0x4E7603B5717360AFULL, 0x6630159A19279324ULL, 0x2B8D916740A3EEFBULL, 
            0x9F33E3DBD1849587ULL, 0xB4A57EA96EC444F9ULL, 0x3E2B8B2FC3E6AAF7ULL, 0x7C050A03DF2C8C77ULL, 
            0xB3E74FA01690435BULL, 0x9231D72D4B99894AULL, 0x49128322EE70E986ULL, 0xAAA69B2FC953E57DULL, 
            0x5FF720CC9A7D6241ULL, 0x7B89E275F7BC6111ULL, 0x00D6360F0977863EULL, 0xE261573FABCEFFD4ULL, 
            0x823AC5FFC33DB3FAULL, 0xC60691200F55EB27ULL, 0x981D6D5D4708BABDULL, 0x01831CD1A0668C80ULL, 
            0x6B2E6B6202F54756ULL, 0xA95DD18C16124974ULL, 0x3248F89080EBD69FULL, 0x88524DEF60EACF8BULL, 
            0x8BFA6A7F75C4EDD3ULL, 0x65F3EC204FF0DDF0ULL, 0xBC1F26F5C97123BDULL, 0xA6099AD245155C20ULL
        },
        {
            0xC9529B6A1BBD59DDULL, 0xD32874736B007A98ULL, 0x51E5006F62A2702FULL, 0xD3E8806DCF893F5FULL, 
            0xCB73DC5C3F407BF0ULL, 0x26CDE141A8D1F9CBULL, 0xF62A51547E38962FULL, 0x0C23EB01590D6E07ULL, 
            0x1302D16CE86D8FACULL, 0xDECD2C3F982B3F70ULL, 0x903717D0D9B3911EULL, 0xF730E5CB8519F359ULL, 
            0x8B1528F2D5477D8FULL, 0xA154D8115282176FULL, 0x3F2DB3801C6D1C04ULL, 0x5C94B37C53C9C1CBULL, 
            0x0178D0777D19FD5CULL, 0x1A7B9A0C85A382FDULL, 0x082348D7ED47D9D8ULL, 0x353EA4A103EF01F1ULL, 
            0x278DAA2C58F980B1ULL, 0x9A3D7F65824F0CBFULL, 0x28105A9B84AE8FB8ULL, 0x29D9D27ACC8861F3ULL, 
            0x86A5DD01F2A02A1AULL, 0xE44E5D76B063E0DEULL, 0xCEA0F39A08B473F7ULL, 0xD4FA437DD0D9B6BAULL, 
            0x052489512C030A42ULL, 0xB5919705A77F9205ULL, 0xC30FB8C4FF8B236EULL, 0x76418CA537A9A2ABULL
        },
        {
            0xE49A1491AC112F84ULL, 0x8860514059174F27ULL, 0xB9BD5362568B7E82ULL, 0x7E459D989AC575EEULL, 
            0xAB1AF388ED3F5B41ULL, 0x83885F14A011C9AAULL, 0x383C63219F26657AULL, 0x135934E7ADD6DC63ULL, 
            0xDDF79C193E045458ULL, 0x0E038C7098C8B2A2ULL, 0x0A2D1D96AC54609CULL, 0x273CDB5B3317EAEFULL, 
            0x1293305E4772F9B9ULL, 0x1812FB98CFA82784ULL, 0xFE0996DC24A6D6E3ULL, 0xC3A3101912EF832EULL, 
            0x18BCCF2DA2520D75ULL, 0xD4B6B25725D91F0BULL, 0xB0D28BF88A085B19ULL, 0x71944EE4414D68C8ULL, 
            0xF1405482BB6EA78EULL, 0xC0BECD240F211288ULL, 0xC47A1866B9C1761AULL, 0x3699619D91810D44ULL, 
            0xE7CF8A0E08A65FBDULL, 0xAB50FB77A4F2C74CULL, 0x9FBDBAFE39BD0D89ULL, 0x61C675898F0F700AULL, 
            0x72681081C2060C49ULL, 0x8D3DA77DB716C14DULL, 0xB4964C9A263B3D01ULL, 0x1668FE653BCC01BDULL
        }
    },
    {
        {
            0x5471F4BA557C157CULL, 0xB34B669643990C43ULL, 0xB23CD3B21309F660ULL, 0xC7C45CDACA2F432BULL, 
            0x709D3EFAAE366D18ULL, 0xB500CDE4758C4E38ULL, 0x93D6C17CCCC54E98ULL, 0x31B1B27904021BE1ULL, 
            0xD9B489F8801BA7B3ULL, 0x4E4303574337759EULL, 0x00EE09926B23C2DCULL, 0x893B749E5F887DFCULL, 
            0xFBB5FFF7021AA271ULL, 0xA894EED83F68E022ULL, 0x4A52D85377C61DF7ULL, 0x305B3AE22FABDFF4ULL, 
            0xF48AB39C84A026B2ULL, 0xF20567DFF93AEF5FULL, 0x6C7ACE3418F08C95ULL, 0xDD555F989FDF6C02ULL, 
            0x3E861ED8791707C1ULL, 0x7BBB837D578575B2ULL, 0x9F9D5153584D59A3ULL, 0x650C8BC01F691F55ULL, 
            0xE9966922ECD01A5AULL, 0x71831CD0586A386CULL, 0x7FF3AC441D5A92DAULL, 0x8A0DF6FD8C6903EDULL, 
            0x15A207C562719349ULL, 0x9050AD4B1FEC5793ULL, 0x70A632B5EF96957CULL, 0xA04B07C9DEF218F1ULL
        },
        {
            0xC5E9A4989DB75D06ULL, 0x73F5EBA642480671ULL, 0x905C3665F3CFD68EULL, 0x097A271A03470AE8ULL, 
            0xA085162A5A5C11B7ULL, 0x346380279AE9C36CULL, 0x084F5B70E079BF40ULL, 0x305421F2A8DD5790ULL, 
            0xEC70BDA387DA8E3EULL, 0x38CD9B36D2517235ULL, 0xB01FC7F262C8567FULL, 0xB669306E8D3232E9ULL, 
            0xC0ED9FF84D1F5040ULL, 0x42F1672739CFD2FCULL, 0xD121AEFC5CA19E56ULL, 0x6F63ECFAC372080EULL, 
            0xF26C59FA911F5250ULL, 0xC339E9865C2F5230ULL, 0x01AA84261249E674ULL, 0x41D47808ADB1206FULL, 
            0xABEE8F7F88D6AD5DULL, 0x967748DF3EF0F1DAULL, 0x47697070DFA35DF8ULL, 0x705821F3B6ABAE55ULL, 
            0x5D7A2AC2D391A62BULL, 0x87523F82232E1314ULL, 0x7BF62CFE22A68B9EULL, 0xD5F59890AA7539E8ULL, 
            0x24E65B9F8B5FCF6AULL, 0xDA9D494E631DBD2BULL, 0x3E82A128FE2FCDF9ULL, 0xCF1272D5D68E4B33ULL
        },
        {
            0x4EF6C72C12DFEA28ULL, 0x1F8B2944BCE8FA3AULL, 0x9B644D62C1F82C5DULL, 0xA9D7B0EE364F87A6ULL, 
            0x797AD3A578CB6FE1ULL, 0xB7796BC631E0D18CULL, 0xDFE65B0C363031BAULL, 0xB083C3818821887AULL, 
            0x1DF3CC52EAEDC69EULL, 0xD877BA3392DE2AC5ULL, 0x200B681894D88996ULL, 0x4052DC78797222AFULL, 
            0x338D0733B77F6AFFULL, 0xFEB0CD558E799823ULL, 0x3E8270C56E217FADULL, 0xD8CC8E0027F1D1B5ULL, 
            0x2EBD84D5B4762D52ULL, 0xDB4F82C4B9B7A787ULL, 0xFAF2E7E68D51AFCCULL, 0xD4942F0F7C19B19EULL, 
            0xE5A4A128F257EE38ULL, 0xD731309EDC5C421CULL, 0x04C7F8302F73F120ULL, 0x49FC49DB5A3A2278ULL, 
            0xD38C8C41AF934898ULL, 0xA63BE5587A85870DULL, 0xE05F2F801919BA78ULL, 0x1C3BE2A6A3722EF9ULL, 
            0xBE52DEDC5DC8F6C1ULL, 0x283B54C88937B234ULL, 0x6125BF7DAE675BCEULL, 0x700248BA19C638BFULL
        },
        {
            0xC81200ED4D6966BEULL, 0xC1F45BA116FE25BDULL, 0xEECB21F0D9286C0FULL, 0x24635DDBF9AD647EULL, 
            0xC0E92FCCF858107AULL, 0xA66C9589788D0EECULL, 0x80981F66407971AFULL, 0xB0A455899AD579A1ULL, 
            0x29360EBE704DF111ULL, 0x6088F7C0256C44CCULL, 0x4A69801DFC8D5CCAULL, 0xCEE9F5B843AFEE56ULL, 
            0x6CE6F4834097F0B0ULL, 0x66B1A0F2F193537BULL, 0x9CEEE56E7DBB52E6ULL, 0x79CD54C466441944ULL, 
            0xEF18A3776FDCEC46ULL, 0x44E6EDD3633133EBULL, 0x796ECDC0F2B7DE80ULL, 0x8FB7098DB027A59CULL, 
            0xD03D1F145A7646ABULL, 0x1150B081378F3ED9ULL, 0xCA7C118D1FE69509ULL, 0x9D75A3668ED7151CULL, 
            0x4779453B782054F3ULL, 0xFD16A0EBCB3DF4C7ULL, 0x6083D08988A6253BULL, 0x22EF149CBCADCA14ULL, 
            0x1F4081CD07543C19ULL, 0x9C1DC906760C1BBFULL, 0xDF7730EE2C28392AULL, 0x934E5A4405689DD3ULL
        },
        {
            0x3FE7A358FDAFE451ULL, 0xED893BF36B472CF7ULL, 0x4893373870ADB579ULL, 0x69786AB79DEACB07ULL, 
            0xD8FC76270EA29CA3ULL, 0x94712107E7A846FDULL, 0xCBBBE4F215E0D935ULL, 0xE53276EFFDF15AF4ULL, 
            0x0258EE6D2828FA30ULL, 0x1F67E332A2A89DEDULL, 0xF2D592B91DA12551ULL, 0xE452AE1B63D03809ULL, 
            0xD9F2BF96C41B32C1ULL, 0x220573A29BEBA2ECULL, 0xA310377FA2DA5C90ULL, 0x0812F1B5A22D70CBULL, 
            0xB1E25ED44EED3AFEULL, 0xBB44898ECAABE22BULL, 0xA42A0998F3473EFCULL, 0xBF2F9F3025BE0DF4ULL, 
            0x917873DC8A1F9C64ULL, 0x8647B7E9689083B8ULL, 0x5EF480910E9D6E5AULL, 0x84CBE6C94D1A82B9ULL, 
            0x202EBF8F4869ABB5ULL, 0x15603802CEC96FF8ULL, 0xEA69ADD1D8B56482ULL, 0x569CC9B9C68BCC89ULL, 
            0x37B3862D82E4DEF0ULL, 0xFC4F6037C2DF896EULL, 0x4603C48686C21C10ULL, 0x396E443201FC5A5BULL
        },
        {
            0x283DE7FA635BCDEEULL, 0x9839E162C88A2551ULL, 0xD35DCF624EE50641ULL, 0xD0BAD4D832218DEEULL, 
            0x44D2AA0188FF4411ULL, 0x295D1F2D563DD3E0ULL, 0xE26C658E83EE4CACULL, 0x1376019E5FE648A9ULL, 
            0x02DEE61A90EDFE54ULL, 0xCC6FACDDE80A8919ULL, 0x017AD8CD684ED490ULL, 0x7086E743E3F742E4ULL, 
            0xA9CD1A45AF45232AULL, 0xDD651122B79F359EULL, 0x4249940D08967E34ULL, 0xBCE7F336EC929281ULL, 
            0xBFC0E3D5354543E5ULL, 0x7C85A0B5773F0032ULL, 0xC100FE095FCA94AEULL, 0x02D41EDE33120156ULL, 
            0xAC82D8051336B82CULL, 0x6916B193B99ABA48ULL, 0x466EA52B61869264ULL, 0xF952EDCF25F3D595ULL, 
            0xA5EEDEA708B51FBAULL, 0x179C9B47D53BF91FULL, 0x00AE1D16A32AEB90ULL, 0xBF2243113AA6B1DAULL, 
            0x047A464D2A662ADDULL, 0x861835C030B334ABULL, 0x7BC079543D7055A4ULL, 0xF93334F721F86B45ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kTwistConstants = {
    0x6155A7C6333225ACULL,
    0x319AA466B32C2EC5ULL,
    0xCA394A84F572D51AULL,
    0x6155A7C6333225ACULL,
    0x319AA466B32C2EC5ULL,
    0xCA394A84F572D51AULL,
    0x04FA9A9804B96C4BULL,
    0x2B9C0A0FE23DFCE6ULL,
    0x2E,
    0xE6,
    0x25,
    0x2A,
    0xF4,
    0x6E,
    0x6C,
    0x63
};

