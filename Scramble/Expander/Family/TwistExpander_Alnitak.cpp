#include "TwistExpander_Alnitak.hpp"
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

TwistExpander_Alnitak::TwistExpander_Alnitak()
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

void TwistExpander_Alnitak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC3F5C55869A3E907ULL; std::uint64_t aIngress = 0xE7798A53E77AAC02ULL; std::uint64_t aCarry = 0xCE0F54DAF3EECAD6ULL;

    std::uint64_t aWandererA = 0xF62917559E615BC3ULL; std::uint64_t aWandererB = 0xE31A250ACC28A42FULL; std::uint64_t aWandererC = 0x8CD703B4CE94EB2DULL; std::uint64_t aWandererD = 0xF59CD7FA9AA079F9ULL;
    std::uint64_t aWandererE = 0xC394D6629110958DULL; std::uint64_t aWandererF = 0xA6DFFC3CEEE27D26ULL; std::uint64_t aWandererG = 0xFA911B86123F10B0ULL; std::uint64_t aWandererH = 0xA2C788FE0E721986ULL;
    std::uint64_t aWandererI = 0x9EF126AB203680F0ULL; std::uint64_t aWandererJ = 0x83CDAE6973FB886AULL; std::uint64_t aWandererK = 0xCAE956956BE352D2ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAF36796304E9F289ULL;
        aCarry = 0xD79796FA78C61811ULL;
        aWandererA = 0x8BCD83D1FF73058BULL;
        aWandererB = 0xB307A3044DB8FB64ULL;
        aWandererC = 0x88D1A9C6477A22D3ULL;
        aWandererD = 0xF1FF2AF93ACB397CULL;
        aWandererE = 0x8710B195757CC8FAULL;
        aWandererF = 0xFC2D2C0A253D57DAULL;
        aWandererG = 0xF47BCA454649D35BULL;
        aWandererH = 0xF2CCA47743DDB53BULL;
        aWandererI = 0xCB8BBBAAC924BDF5ULL;
        aWandererJ = 0xF1BBCFFDC668052DULL;
        aWandererK = 0xA97CB54C2B60A468ULL;
    TwistExpander_Alnitak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD6B830292620C722ULL; std::uint64_t aIngress = 0x92CEF4A8C9D1A887ULL; std::uint64_t aCarry = 0xBCD1AA87E3C48CF6ULL;

    std::uint64_t aWandererA = 0xD8A081D8C652D4EBULL; std::uint64_t aWandererB = 0xF10F435C26E2C4D3ULL; std::uint64_t aWandererC = 0xB4AB4E08987476CCULL; std::uint64_t aWandererD = 0x9B28DED459ED6FBEULL;
    std::uint64_t aWandererE = 0xB636AB8D8D8E16A2ULL; std::uint64_t aWandererF = 0xCCC6E131C24EBE95ULL; std::uint64_t aWandererG = 0xADF1A174B672BFCFULL; std::uint64_t aWandererH = 0xA88C345F1284F236ULL;
    std::uint64_t aWandererI = 0x9ED26C7F4D022123ULL; std::uint64_t aWandererJ = 0x886DEDC2E6528838ULL; std::uint64_t aWandererK = 0x980A26D7C858C6C4ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC59C08EF19ACA561ULL;
        aCarry = 0x8D0199CC1BEE69A5ULL;
        aWandererA = 0xF91B1EA8D082045DULL;
        aWandererB = 0xDD717DD3DCA5BCA4ULL;
        aWandererC = 0xF8C8C57D17DCFA1AULL;
        aWandererD = 0x94F9EA0A42D48024ULL;
        aWandererE = 0xAC8A9779EED34BA2ULL;
        aWandererF = 0xCDB9FEDE9EFBF5E9ULL;
        aWandererG = 0x97DC8AC6373FBA98ULL;
        aWandererH = 0x98F071A4F5DED52CULL;
        aWandererI = 0xB92641725B240688ULL;
        aWandererJ = 0xC62258BA6D548A5EULL;
        aWandererK = 0x80D3997A28786A4DULL;
    TwistExpander_Alnitak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFEF56ADF9E55DAA4ULL; std::uint64_t aIngress = 0x9CAEC94F03BC36EFULL; std::uint64_t aCarry = 0xA86B5921FCB1107AULL;

    std::uint64_t aWandererA = 0xD4F6739578730454ULL; std::uint64_t aWandererB = 0xB5AA8AE6A828FDCEULL; std::uint64_t aWandererC = 0xD7C97863D48812C2ULL; std::uint64_t aWandererD = 0xAF7EC92800903918ULL;
    std::uint64_t aWandererE = 0xD2926C97766334C3ULL; std::uint64_t aWandererF = 0x9002EAA7AC41D75CULL; std::uint64_t aWandererG = 0xA42BC9CE0939D028ULL; std::uint64_t aWandererH = 0xF4E13711A3FDA24EULL;
    std::uint64_t aWandererI = 0xAFA3992D8DDDDB9AULL; std::uint64_t aWandererJ = 0xBC77A513DF16C9D4ULL; std::uint64_t aWandererK = 0x9EC746FAB33049D3ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC94773A31F1476B6ULL;
        aCarry = 0x99EB3D35FA84C6DEULL;
        aWandererA = 0x8EB3B535687C9FFBULL;
        aWandererB = 0xF17AC86D638E2293ULL;
        aWandererC = 0x95C65B248A55D6B8ULL;
        aWandererD = 0xF33170EE5170704DULL;
        aWandererE = 0xB3EF48B4CF627C32ULL;
        aWandererF = 0xF2F17197C64B66A2ULL;
        aWandererG = 0xA43F9FF8F6B4E941ULL;
        aWandererH = 0x828E7B6696563153ULL;
        aWandererI = 0xF4A6EC9A1D6E230CULL;
        aWandererJ = 0xADCAD9D2FF3BA4FEULL;
        aWandererK = 0x869C1245EC049B2FULL;
    TwistExpander_Alnitak_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA38378DF36373CF6ULL; std::uint64_t aIngress = 0xE96D3F88393B90BCULL; std::uint64_t aCarry = 0xFED715E437E60DC4ULL;

    std::uint64_t aWandererA = 0xF2DCD951BB6D4CFAULL; std::uint64_t aWandererB = 0xCEACB81893AE8DF5ULL; std::uint64_t aWandererC = 0xC9AD06725ABDECD9ULL; std::uint64_t aWandererD = 0xA194E23BB480F8B2ULL;
    std::uint64_t aWandererE = 0xC5BBAEAD342CA8BFULL; std::uint64_t aWandererF = 0xE1603DEF5E47C2D5ULL; std::uint64_t aWandererG = 0x8EE11112F8DB1C3EULL; std::uint64_t aWandererH = 0xE0AB42E25C029077ULL;
    std::uint64_t aWandererI = 0xEA614E82D101E379ULL; std::uint64_t aWandererJ = 0x97AA8DA31E229E56ULL; std::uint64_t aWandererK = 0xD91798D963141C43ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBD82D66C3868CF0CULL;
        aCarry = 0xBDE60AE4F2707704ULL;
        aWandererA = 0x9006A2476F7EEBBBULL;
        aWandererB = 0xC93FEAD578C55F4EULL;
        aWandererC = 0xE2CE47B297C1AEF3ULL;
        aWandererD = 0xB072761482211B07ULL;
        aWandererE = 0xD7A5AB862245E8B5ULL;
        aWandererF = 0xC8856F2613D650D3ULL;
        aWandererG = 0xFD85FB8F5CAE7369ULL;
        aWandererH = 0xE7DB776F78A77176ULL;
        aWandererI = 0x9036707E83A10053ULL;
        aWandererJ = 0xB279A533D1284001ULL;
        aWandererK = 0x83286A4B5A1CA3BEULL;
    TwistExpander_Alnitak_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alnitak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8C0923146002C027ULL;
    std::uint64_t aIngress = 0xAAAE45DE85EC1272ULL;
    std::uint64_t aCarry = 0x9AED2A7F780B0DE1ULL;

    std::uint64_t aWandererA = 0xEEB25B5D30A58EBAULL;
    std::uint64_t aWandererB = 0xAB331480F9DB0C77ULL;
    std::uint64_t aWandererC = 0x940786E45EEAB748ULL;
    std::uint64_t aWandererD = 0xF2B08350E809993BULL;
    std::uint64_t aWandererE = 0xECDE17F07187581EULL;
    std::uint64_t aWandererF = 0xF17EF3D7444B13DCULL;
    std::uint64_t aWandererG = 0xA3BB513D6452ADBEULL;
    std::uint64_t aWandererH = 0xF768F43C30C7155FULL;
    std::uint64_t aWandererI = 0xC8CA3D032ED2F03DULL;
    std::uint64_t aWandererJ = 0x8D0121FB734EDFE6ULL;
    std::uint64_t aWandererK = 0xA9F10B07AF1C0618ULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    TwistExpander_Alnitak_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KEY(pWorkSpace,
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

void TwistExpander_Alnitak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF3A1C17D7F055FF5ULL; std::uint64_t aIngress = 0xEF203AFD34816C1AULL; std::uint64_t aCarry = 0x9613B3B835A0A3D1ULL;

    std::uint64_t aWandererA = 0xD8BE106DB79B866FULL; std::uint64_t aWandererB = 0xA5DD2F113E6D3C6BULL; std::uint64_t aWandererC = 0x84DD3F8307D069FEULL; std::uint64_t aWandererD = 0xF145925526B61465ULL;
    std::uint64_t aWandererE = 0xE2FBBD6BF57ECBFBULL; std::uint64_t aWandererF = 0x84CB66CB9598823DULL; std::uint64_t aWandererG = 0xB9B38355E9EFC7E6ULL; std::uint64_t aWandererH = 0xA101B74569045A79ULL;
    std::uint64_t aWandererI = 0xCFD28E8536258E57ULL; std::uint64_t aWandererJ = 0xE98565A551E2707BULL; std::uint64_t aWandererK = 0xC004A56E49F825D9ULL;

    // [twist]
        aPrevious = 0xDBF484B07AA99861ULL;
        aCarry = 0xFDEAE14A0EB532F6ULL;
        aWandererA = 0xEF9A0E84B4DC60FAULL;
        aWandererB = 0x93B5672CB070D27AULL;
        aWandererC = 0xFDB19C99E24515C0ULL;
        aWandererD = 0xD2A8E37704644891ULL;
        aWandererE = 0xDEF326C64D386273ULL;
        aWandererF = 0xFBD5D843E1853285ULL;
        aWandererG = 0xF20E688C86416B67ULL;
        aWandererH = 0xAD53E8561BC388DAULL;
        aWandererI = 0xC51A96A2ACCF8818ULL;
        aWandererJ = 0xCEEBD30CE8956BF6ULL;
        aWandererK = 0x8CCCB6C9CBE2ACB8ULL;
    TwistExpander_Alnitak_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Alnitak::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Alnitak::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Alnitak::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 6 of 33
    // Exploration cases: 0
    // Structural maximin 548 / 674; family total 2812
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1825U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 6 of 33
    // Exploration cases: 0
    // Structural maximin 556 / 674; family total 2820
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 565U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 6 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1093 / 1248; total 5506
void TwistExpander_Alnitak::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 6 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1100 / 1248; total 5532
void TwistExpander_Alnitak::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
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
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
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
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
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

const TwistDomainSaltSet TwistExpander_Alnitak::kKeyRotateSalts = {
    {
        {
            0x30AB13A41174ABCDULL, 0x6C202D126E688A2AULL, 0xBC3E3DB0C5EA1B0FULL, 0x5047D63E097E9AA6ULL, 
            0x5220D839B1B3774CULL, 0x3B8D3C34EA024A65ULL, 0xAAD335D1C053C3B2ULL, 0x8B5BBD778E5604E1ULL, 
            0x7253B3070C4CE44FULL, 0x9BDE80EFC20E0649ULL, 0x695D6CE6C4EA5AB1ULL, 0x95103FB5D7CFEFB6ULL, 
            0xA5D0E00AB2C5AB6CULL, 0xD41ED90B322735D0ULL, 0x8004A7DCCFE2A6B6ULL, 0x1B48CAA269C61372ULL, 
            0x32FA16C53C4AFC13ULL, 0x49873CC857BDEC50ULL, 0x3528328F573FE23FULL, 0x7F1001C1273D2D41ULL, 
            0x95D75B2D8EA65DACULL, 0xDA1F459F752F07D9ULL, 0x2D6399AA01FCEB9AULL, 0xE2B882F57E5F56D2ULL, 
            0x46C903BC535D087EULL, 0xC358576A1BB6C8BAULL, 0x75A060B9E6CFF06EULL, 0x761A704DC35393F9ULL, 
            0xDDC2732DC55017AEULL, 0x0ED42127DDB325C0ULL, 0x82FA2BFDC85D2712ULL, 0xF5458731F0DCB9AEULL
        },
        {
            0xDB47E3681FEDC840ULL, 0xECE319BF5B27B486ULL, 0xFF956A00D359DC57ULL, 0xB0582F1E2A835322ULL, 
            0x9FBFD5035FD8FB29ULL, 0xF00F62E56DDD4078ULL, 0xE25C15BDDD64D03AULL, 0xF0F2752CF94FCF37ULL, 
            0xD4BE3A84510F7159ULL, 0x48CE5A2AF3443B1BULL, 0x654AFCA28529B78BULL, 0xF8D06E03601F2099ULL, 
            0xFA0B14715E5B7198ULL, 0x7D674A7FB804658BULL, 0x6D287ADC5A07F948ULL, 0x84F5E8F4BEF78DB8ULL, 
            0x18DE4F8F88AD0F44ULL, 0xAEB5A1C2289FB574ULL, 0xC47688B0622ED2CCULL, 0x808718BE5CAF35E1ULL, 
            0x9E251ED2F825F349ULL, 0x601F9E58CCCA32AAULL, 0x99E4432A7A8FD7ACULL, 0x1D4B41F44CAF926CULL, 
            0x7BE4EED79DB2FDCAULL, 0x88457793967873CFULL, 0x737E9D19FCA5C173ULL, 0x5B57D3BAB3B9C8BDULL, 
            0x7A0ABEBA0B48C801ULL, 0x04AA9671382CCD47ULL, 0x895AAA2C7DBA2443ULL, 0xD1CCA663C75DEADBULL
        },
        {
            0xCB014ECE75C6F509ULL, 0xECE57E39AD734980ULL, 0xED668C67F09BA31FULL, 0x848B2BA350C95430ULL, 
            0x49ED837BFF3BC3FAULL, 0x7EDE996C93BADBC0ULL, 0xF2C764BE98B37958ULL, 0xA51FB33588036770ULL, 
            0x495F882C21D38DDEULL, 0xE7DBA544486F408AULL, 0xF0FDA7141550E838ULL, 0xC764C4F9C6F8A335ULL, 
            0xFC76E72BF33A764CULL, 0x29735D6727B88F9DULL, 0x010BBA3D3580AAAEULL, 0xB3CC46D756BF0DAFULL, 
            0x758BF78AEE684F6DULL, 0x05666C0350D2C4F5ULL, 0xB7208A5834188D72ULL, 0xE5F311688D10075EULL, 
            0x44AB1AC08E62CF51ULL, 0xB7B911C003EAFC47ULL, 0x7E5B750CD92268FBULL, 0xDD5B4D1C4330E650ULL, 
            0x392D8509CEF05A8CULL, 0x176F01FFF5649B37ULL, 0x4D4A2946EED36457ULL, 0x4A135A86647AFDF5ULL, 
            0xA1B6DD764615EB60ULL, 0x8FB3E30081C25CB6ULL, 0x79B91862E65E6D78ULL, 0xB6AAE4B05B4362A6ULL
        },
        {
            0x2A2B24CE7BD45F01ULL, 0x37FD320CCC78CB95ULL, 0x1EE662A5341B0C49ULL, 0x6AD7863C7660D289ULL, 
            0xED3CC6AB1F38DE68ULL, 0x3FA88F228AB097A0ULL, 0xB3E0B19CB0D507ADULL, 0x9360166C30E4320BULL, 
            0x3A47E264B35C2343ULL, 0x64D08A5F61135C4AULL, 0xEECAF9CCB9D8FDC4ULL, 0xACBAA694A90159F6ULL, 
            0x4DC38331D7FEC28DULL, 0x5222EFB40B4020B3ULL, 0x496159BEFBACCD2AULL, 0x91921717C64540D0ULL, 
            0x873BD78FC3C357BDULL, 0x1CD5EEF496760DB9ULL, 0x5FE5D2EF2408C582ULL, 0xB4EAE3D962C5CB41ULL, 
            0xFA656C7D30B89530ULL, 0x91CA8B989781D585ULL, 0x1283608098F77B14ULL, 0x79FE78E16132D410ULL, 
            0xDBE92BED8F52426CULL, 0xFAF330A2EEED848EULL, 0xD7973D42740035DBULL, 0x69E93CB2B4BECD29ULL, 
            0x05306ACB332C43C4ULL, 0x8765479378E8B6D9ULL, 0x6E56EC14BF2FD207ULL, 0xF1254A2642C55AA9ULL
        },
        {
            0x1516D634744EB0FEULL, 0x95B4B7E63A193C79ULL, 0x4297AFEA3D29C197ULL, 0xFDF99332BD94F675ULL, 
            0xC2B5B7AAA54FA680ULL, 0xF16C53FFEBE45D6FULL, 0x8D58EBEDB9897E92ULL, 0x82DDE4E706B51984ULL, 
            0x072C01399D0990C9ULL, 0x919C2E2F3090C7C8ULL, 0x7A1C4FD4AEB1039FULL, 0xDBF1121B2D4A55A7ULL, 
            0x856266DF8FC1F07DULL, 0x2C84DFE0C9509B49ULL, 0x81DFEB80810E07BFULL, 0x86075FEFB8DE61C7ULL, 
            0x03C6BA9D35803E5BULL, 0xE0561049AB4E0B63ULL, 0x715BB21232CDA57DULL, 0xD88A9856C8F07141ULL, 
            0x0C005298EE9982E2ULL, 0x30CECF1E65E15F58ULL, 0x5AD931489E3C807EULL, 0x51BB6580065735BFULL, 
            0x30A10CBBCF67B9FDULL, 0x3666AF6308F6E78EULL, 0x8717314CFD5BACB6ULL, 0x003F99C7B4BDD31FULL, 
            0x626066095D529E71ULL, 0x2C091AC08D231F66ULL, 0xA944FD44F9E26FD3ULL, 0x3AC4F51A0EE4418AULL
        },
        {
            0xA26912B5FEB037F7ULL, 0xB17D4055305A58F6ULL, 0xB42CC8A54521E2EBULL, 0x209B181975D6977EULL, 
            0xEFF8D159328F6D9DULL, 0xECFCF1BE0E89BCABULL, 0xE713AEA8C4051EEDULL, 0x3EC1C39AC0E2B3E5ULL, 
            0x8F23E892FBE1500CULL, 0x1BC059BDDAAD6EB1ULL, 0x832B57B13378A759ULL, 0xA7530C8D9CB49AA2ULL, 
            0x2B671241489045F4ULL, 0xB34D2C3FD5ECB030ULL, 0x9313EB6C0F770518ULL, 0x2F20DB7228806D87ULL, 
            0x5F7179977E6437F3ULL, 0x547B5FA456ABE8D9ULL, 0x5AD92216628F72A7ULL, 0x7CF9A04588B4AB68ULL, 
            0xEACEFFE6D6D404FCULL, 0x01ACD567190E43E5ULL, 0xA07F983917878791ULL, 0x20592A06B52D9FA9ULL, 
            0xFFFB2FC253AC09A5ULL, 0x43F03708CB5A73D6ULL, 0x64959E5A3E38D7B3ULL, 0x9E3FB42FB6D87A28ULL, 
            0x78D85AAB8788FA23ULL, 0x5A9F1D49F5671D39ULL, 0x3C84DBA111A76AFAULL, 0xEE991D05B65AF4DBULL
        }
    },
    {
        {
            0x085798E6B406743BULL, 0xE97172F84B181DB1ULL, 0xDFCC3E7539B2F954ULL, 0x9F5CE0D8C5F7CA92ULL, 
            0x6A5884C44E038B41ULL, 0xFEE571E907D5AB96ULL, 0x9E5D0EC10400D692ULL, 0x65338AB029B35CFEULL, 
            0x1BB3CEFEA6BDF2CBULL, 0x87A01CDB701C2E77ULL, 0xA338A36F3C0A6E97ULL, 0x0A759381D987D113ULL, 
            0xC8AD498C36883BD4ULL, 0x88E1E5585D87F2A4ULL, 0xDE1D8097CC066438ULL, 0x943A01D7758DACAEULL, 
            0x3340A11D51228F72ULL, 0x6CDFF57499A5121DULL, 0xAB19C1C5EF8F2795ULL, 0x2FBA83F72E8BF802ULL, 
            0x0BE0F0104CA9986FULL, 0x1D4CAB20FAD5E69BULL, 0x75D1F28360A30FA6ULL, 0xAD435A0F4936658BULL, 
            0xD5257F15274D069BULL, 0xDF445B03207665DEULL, 0x2FF58C19BF1EC065ULL, 0xEB357B0A055BD92BULL, 
            0x29F977B700ADFEF8ULL, 0x4A485F42C891667EULL, 0x2AB89650404C2F4CULL, 0x18FBDCDD2EE49AB2ULL
        },
        {
            0x85C15E3096C2DB89ULL, 0xAE069516D76BA509ULL, 0xB51F7FA0EC276F53ULL, 0x74B0CFBEA0D42596ULL, 
            0xC980672E053ACE7CULL, 0xD39739B73F8EDC12ULL, 0x7E65120BCDE7798AULL, 0x87D1EF10C2780277ULL, 
            0x7952FD34F80479F8ULL, 0xD338BD3A6896C3F2ULL, 0x86DFC01927FAD6BCULL, 0xEA17B87E43632286ULL, 
            0xEBE506D4224C24EEULL, 0xB2B2EFFC24A621E1ULL, 0xD3C829C2F70D7834ULL, 0x6634FA50EAEAD63CULL, 
            0x90F10C8E3E4903FDULL, 0x9C8993EC306FBCC2ULL, 0x61F68646A35E4642ULL, 0xACC077B998126AE2ULL, 
            0xC1F36F86D318CC4BULL, 0x30A82AA8DC23F269ULL, 0x96C2EDDAC6C8F84BULL, 0x0BC9DE72DB8AD3E4ULL, 
            0xD3ED1C4A6A2A6835ULL, 0x76F7F8BE525DB6C7ULL, 0x68ECB4AECC026408ULL, 0xCA763059EDD8E06CULL, 
            0x3866C9B2CBA435E5ULL, 0x12893F5C516AFE7EULL, 0x9BD53FA9CB3CCED7ULL, 0x145949AA7BA7911AULL
        },
        {
            0xFD4C2D063322082FULL, 0x747FAAABAF407A8DULL, 0x2FD1915CD322D0E4ULL, 0xCCC128E18A57EC6AULL, 
            0x9F2A5A56844874DDULL, 0xFA98BE2F0741D226ULL, 0x4B726F6205AF93DAULL, 0x0F443E3CDF3B09B3ULL, 
            0x09E774911A1A063FULL, 0xBE65156ED54EDFD4ULL, 0xB715A0AE103AE13BULL, 0x87AA0F506A8BC623ULL, 
            0x1A1DAF48382652B0ULL, 0x23124A2329AE8D72ULL, 0xCA7328E821D9B3A6ULL, 0xFA4602DF718C015EULL, 
            0xC6CC087CD96C0D73ULL, 0x5E6EA3B8DDBB2B52ULL, 0x08BF0A51DC618D50ULL, 0x4523A36EA72C770DULL, 
            0xE538A8C9930E6100ULL, 0x9DF045B16041C595ULL, 0xA7A2C49E765E9F59ULL, 0x57AAA3C69081F076ULL, 
            0x3BA26BF959456EB7ULL, 0xD324493DA20058D6ULL, 0xF682F58FD296B208ULL, 0xDF5021397CAF2EDDULL, 
            0x15BE33DD65F77F99ULL, 0x83214A14EFCAF129ULL, 0x1DC0F8C7092B9E8CULL, 0x1C0B824A9D4D3C8CULL
        },
        {
            0xB24AD5CE7160B5CDULL, 0x899ADBAB985CC6E6ULL, 0x157CE906EB356AC1ULL, 0x462007A82FFBEC34ULL, 
            0x2C32376A7938D183ULL, 0x4CC4BDD827C915DAULL, 0x4DAE2C78E1FEA65FULL, 0xCE1D66E422CC178FULL, 
            0x9AC31DAF8C8C69C3ULL, 0x8FAC992EBC049FA6ULL, 0x9322BB7D1037302DULL, 0x19DB59D042FC1867ULL, 
            0x6DAE9AA5E361C0FBULL, 0xF95358F364F2C3A7ULL, 0xFCE49D32FD9B1BCBULL, 0x91FEFA3038274F6CULL, 
            0x676C3936BEA83AEFULL, 0x95558B665C4C333EULL, 0x485A3486FB2B383FULL, 0x163335A698EB57E4ULL, 
            0xA8C3AE46FD5B1573ULL, 0x53377D5F27CBFDD2ULL, 0xD06733C752104DF4ULL, 0xE8016E2E0D8A492CULL, 
            0xB428AE47D1EB48FFULL, 0xEE5380CEB1EA6694ULL, 0xEFD9171460F4A83BULL, 0xA28FEDE58481EDA9ULL, 
            0x1B9225A13BC69C13ULL, 0x92CFFFDFB769844FULL, 0x4197B98B97F015B7ULL, 0x25512BCEE7C41ECDULL
        },
        {
            0xB3DD9FB47968FD1BULL, 0xC72A2D419954AF90ULL, 0xECDA256D97FFCBC8ULL, 0xF7333C6CB6B147E5ULL, 
            0x08FFCC2FC910C698ULL, 0xA3311F7008B55062ULL, 0x9BA81F3BF1EB53D1ULL, 0x09A0AFCC6D02BC3AULL, 
            0x6FC9250842A38630ULL, 0x175FACB138CA53E9ULL, 0x964EDE50794A5679ULL, 0x3B7B7476E286A0BFULL, 
            0xA99208703FBAA7F6ULL, 0x032EDEFEE76FFF6AULL, 0xB31891ADEC89C00BULL, 0xDCC869341904DDCDULL, 
            0x42694D01448381BEULL, 0x1C1DB91065EA705DULL, 0x00A4FE14D7A65DF0ULL, 0x1B3E9D0812DD2E81ULL, 
            0xE637098CEF3CE5FCULL, 0xBBF0FF8213E7056AULL, 0x2E000B81034BB455ULL, 0x3AA01E3ECAA4B868ULL, 
            0xB3D1D8AA91A5ECC5ULL, 0xEDAEAA4D5A849249ULL, 0xB14152ED09B94875ULL, 0x77B6E396BC6D4331ULL, 
            0x874F82FD979EF540ULL, 0x5CEC7FA08763444BULL, 0x8BA74F79F389EA18ULL, 0x7AA5978168F326D5ULL
        },
        {
            0xA2980754CAD6CF07ULL, 0xE274DD67C9CF7DEEULL, 0xF929929B1DE2880EULL, 0x717EE866432B8C1FULL, 
            0x4D15EEAC8E30C23BULL, 0xF8DEADDFADAE6661ULL, 0xACA9CF7C108EBFB8ULL, 0xA2E3C8449CFABF26ULL, 
            0x01F5AE3958D840ADULL, 0x57441F227AD33442ULL, 0x374C0E1B53F653B2ULL, 0x407C7DB2CB9B3288ULL, 
            0x6138C4988B406EF5ULL, 0x47E5C0F0D7C06EB5ULL, 0xB554D62027F82F0DULL, 0xFF46EAEDF593C532ULL, 
            0x116647B17F12E713ULL, 0x3C17819B055E31DAULL, 0x012A9AC5EFB1FFE1ULL, 0x51E715DFA8B0E509ULL, 
            0xADB1F61223E463C9ULL, 0x3C6B6DDE4833B076ULL, 0xACB347A241BC2F41ULL, 0xA04B7C029E079238ULL, 
            0x875A34FA32A535EAULL, 0x6C70C6E2DF54CCDCULL, 0x27EB54F461BAA198ULL, 0x60C1CB3E3B2BCDF1ULL, 
            0xD2196DD8FCA4D4CFULL, 0xC539C576D4696C96ULL, 0xC8E5951B912B29EFULL, 0xFDE041E05AFCA499ULL
        }
    },
    {
        {
            0xE90B7655489D65DBULL, 0x6166482F95BE3CC0ULL, 0x79ADEB3BCB8E416CULL, 0x85C57DF8B04067F0ULL, 
            0xFD23DBB71E53228EULL, 0x26C81C4FA2445793ULL, 0x317B48C04476222EULL, 0x7077E9D859B2A125ULL, 
            0x5D7861C19E141575ULL, 0xFB24F55C1E122530ULL, 0xA3C0154ECB98B161ULL, 0x394CB4CF781AEF84ULL, 
            0xBE717C29FC3FD098ULL, 0x7CAA80AC8FDBFA8EULL, 0x97143E23F381A119ULL, 0xD3CD71297CD9439FULL, 
            0xEFA133C1E9BD397DULL, 0x8A5C692544BDE1CEULL, 0xAFC75E634B071C6AULL, 0x171BF97A31D51BB6ULL, 
            0x9E4B4F41F46B03C6ULL, 0x24B8A249ECBE9EFCULL, 0x40922327D1C44C0AULL, 0xD93743C2032D4361ULL, 
            0xE09D7EA587161BEEULL, 0x75D5A025548B9FD3ULL, 0x626944C292B7F468ULL, 0x4F21D774599481D6ULL, 
            0x66BEFA4451B6AE14ULL, 0x224AAFAFA65C493AULL, 0x36DA31E49AD791D0ULL, 0xE7C79D2FD70CC722ULL
        },
        {
            0x02ED191465B74857ULL, 0x664440C5AC6510F3ULL, 0x0B73BEFE1628E191ULL, 0xF4F324DE6C8E15F1ULL, 
            0xBCDC31D8B4C79E42ULL, 0x203347FCA1BEDBF6ULL, 0x5C18F34CE5548638ULL, 0x848C88E32BB14473ULL, 
            0x12947B2FA1DAB950ULL, 0x19043A2A37250179ULL, 0xBDD434FED498074DULL, 0x3E3D7FE42F40DA3DULL, 
            0xB9C6C7CE0D9B8615ULL, 0x3F5B2EB8C1C75071ULL, 0xAB9FEE188AE34147ULL, 0x98B4BAE1AD4D3060ULL, 
            0x115257C0B32F85C0ULL, 0x137EA41CA5CE8631ULL, 0x3E89F394BC1EC69FULL, 0xCDE7BFADEF232C76ULL, 
            0x9B4359A68507ACDBULL, 0xBA60375503A51EE4ULL, 0xAA3642742D2D8586ULL, 0xD60428B95B87C886ULL, 
            0x053FC8459A62FB13ULL, 0xEC5CA87E697DCD70ULL, 0x0E029592975AAC7BULL, 0x50911FFD00F12B24ULL, 
            0x35F9F608F31624AFULL, 0x0D659EDBCB21A263ULL, 0x3CA53C700D8103ACULL, 0x8490D369ADC73698ULL
        },
        {
            0xE13E6FC74E06921EULL, 0xC78CCED580F7FEC4ULL, 0x26E64EB384E43C0DULL, 0xFD564966E2F8AABDULL, 
            0x9BC57C5C00777D69ULL, 0xCACADF8215D87C57ULL, 0xE7ADE82D312BF80EULL, 0x3022F7BA64F8325DULL, 
            0xB398920286862270ULL, 0xC1EFAC8C12D19047ULL, 0x0EC4A4CF8C013098ULL, 0x1059754F94E9FE33ULL, 
            0x788AECE79323FF6FULL, 0x26DDE307DA5DD5A2ULL, 0xB8CCBE1C093F0BD9ULL, 0x9FDD5D135185607AULL, 
            0x3541F6F442D4FA87ULL, 0x701400C04C9C8B45ULL, 0x37A4863C1ADF432DULL, 0xA475635FBC01BDACULL, 
            0xEFBA05145BAF5757ULL, 0xF4F12D0C2A3684D4ULL, 0x0E8FB486D4159E3DULL, 0x27381E91D661B9DFULL, 
            0x13E60A1695CE8572ULL, 0x00DD033DDE557813ULL, 0x1CB98AEB1E8F76C6ULL, 0xEF8CA20EA8C203A0ULL, 
            0x0209290C0BCD5FF9ULL, 0x6B73CDCF884096C3ULL, 0x895130AF47301A11ULL, 0x59554C171F2A9CF0ULL
        },
        {
            0x4C409ED0B357BBB9ULL, 0x3E288210E53E51D7ULL, 0x52544A32F3DB2D46ULL, 0x9060696298917F1EULL, 
            0x8504FF90A32A1CDCULL, 0xAF30DEC15B3712F3ULL, 0xC4E03001453812ABULL, 0x6A4A231B6CF84636ULL, 
            0x0A83925A2C778967ULL, 0x949A3CC51547F2B0ULL, 0x1BF70724B23A3722ULL, 0xFBCBC79703C331AFULL, 
            0xEB42E1C4CEEE4B89ULL, 0x2182754A2975698BULL, 0x495F633F899A0091ULL, 0xA3B8AB857BA7B803ULL, 
            0x7B96FEFAA6632F59ULL, 0x382BCEEB8A159B1DULL, 0xC96FFDE5D76756CEULL, 0x7286CA2434C6427FULL, 
            0xBA6A56B4187E07B4ULL, 0xE2BBA0797AEF7F61ULL, 0xEE9D97B9F2C09EF2ULL, 0x2B6D8B570C83AB24ULL, 
            0x1F6957F7AE824535ULL, 0xD889B9136F6C2053ULL, 0x76E54F34696E1486ULL, 0xB14A57C87C304653ULL, 
            0x496EE80A6DC131A4ULL, 0x0D3456F82AE0B70CULL, 0x78E5A22E01A428BEULL, 0x9E125226FF0AC660ULL
        },
        {
            0x843737A269F8A176ULL, 0xE5081F2D10833484ULL, 0xA3B5D5790A6305FCULL, 0x4C09E5580F5134ACULL, 
            0x2A64349393DADEF7ULL, 0x891B34A1AFDC3C0CULL, 0x553E5D106531999EULL, 0x0D029CE1D266F3DCULL, 
            0xE9177AC221A1B1FBULL, 0xDC8FB7D4B0AE3F3CULL, 0x91BF61876C0D4006ULL, 0x9CF2E43FC89A9A66ULL, 
            0xFFA0B2A33B3D21E2ULL, 0xDE0A4A66E4187C9DULL, 0x27D80FA028082555ULL, 0xFD9240FFC4B3FDCCULL, 
            0x5BC8F694302BD21BULL, 0x0D9D3311506D0383ULL, 0x77FEEBE3B677DC50ULL, 0x054B1EA00EDDD192ULL, 
            0xC71627D48BED6E2CULL, 0x1423E23EB3A04227ULL, 0x4982C21A4F8446F2ULL, 0x7B3B3006FDF6013AULL, 
            0x277D3CAF2700C117ULL, 0x592729B5A3596F15ULL, 0x9CCAC8F21CEF484DULL, 0xB994D6B9A740F8CBULL, 
            0xD045E1E735DA3B2EULL, 0xEE0EF3875907B033ULL, 0x344BB13D95E5EFCBULL, 0x4B02B836259952F2ULL
        },
        {
            0x9B185D9E1A80AA53ULL, 0x5C5654CC0E06E194ULL, 0x9979A4F4D8562EDAULL, 0xB785EAB7BB8F6546ULL, 
            0xE7A9C45F96A3FF84ULL, 0xC717965E45970684ULL, 0xB52A6AA87EB22BD1ULL, 0xA2B7453CDFA62767ULL, 
            0xFB5FA349245B722EULL, 0xE899A92B64EE107DULL, 0x5A8EC85EF6780264ULL, 0x547963F56BEFB822ULL, 
            0xECF4F142A7342993ULL, 0x62B876CE3B8DD560ULL, 0xA4F829D4E8B22AAEULL, 0xC29518ECFB801DE5ULL, 
            0xAEF37DAF46E05B49ULL, 0x0B09856923C63AC3ULL, 0x81B9B0F8E0381474ULL, 0x69582603804C4563ULL, 
            0x636EE00C5A70CC7BULL, 0x22F8FDFB51C65115ULL, 0x7FF9B53BDE37028AULL, 0xF0A97163EB712B02ULL, 
            0x96D3BDE10794F376ULL, 0xED33BB709C845A20ULL, 0x3DEA5D747E4EA927ULL, 0x5A22367829F3F100ULL, 
            0x0F748580563856A9ULL, 0x3DBD89EF6C740D53ULL, 0x09B8811AE5033C28ULL, 0xA0666AF03FA63E96ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeyRotateConstants = {
    0x209E1F19F0713FCDULL,
    0x6959EBE75D247396ULL,
    0x928A2F0986297AF0ULL,
    0x209E1F19F0713FCDULL,
    0x6959EBE75D247396ULL,
    0x928A2F0986297AF0ULL,
    0x3409FC9E84D9499FULL,
    0xA7FD9FE5A7354F10ULL,
    0x70,
    0xFA,
    0xFD,
    0x91,
    0x8F,
    0xC4,
    0x8B,
    0xB0
};

const TwistDomainSaltSet TwistExpander_Alnitak::kKeySpawnSalts = {
    {
        {
            0xB70B1757505DD931ULL, 0xB0171619AAD474C7ULL, 0x7EEE919972B0096BULL, 0x19EE5E62EB994639ULL, 
            0xF72258F546D5540FULL, 0x1BBD09E3E08B9298ULL, 0xDBF9470A6CE3D3B8ULL, 0x2F0FFCBB0F124440ULL, 
            0x9F0D7E4D5B3B4180ULL, 0x3167DC78EF7F2814ULL, 0x02E62864DD343CD8ULL, 0x0308A21EB99E4030ULL, 
            0x29FD3898456F5174ULL, 0x5F4D3A96B3F94870ULL, 0x581468B2CE3BE0B9ULL, 0xF23DE427B12F9207ULL, 
            0x061F2EEA8FD9B344ULL, 0x97B7958B84C63F21ULL, 0xE0408CFBB3C8A03BULL, 0x869415E4BBA8E2EEULL, 
            0x609DF31F74B818A3ULL, 0x7637F77340B0FBB4ULL, 0xE8B6773D1C81E8BFULL, 0x97435AF81F1140ECULL, 
            0x42E5A99B23BB54A5ULL, 0x6BCCD174439A57A5ULL, 0x38BD339BD03C2BBFULL, 0x375B2F2F64D7FE62ULL, 
            0xBEF69FC8346BB082ULL, 0x182D508F5A85009DULL, 0x21A6C986D4947E22ULL, 0xE284C4DB8787ACC7ULL
        },
        {
            0xBD07C5A9D4D0B7DFULL, 0x20D8BAF6BAB1B50CULL, 0x71FAF910257E03C6ULL, 0x0A180988D892839DULL, 
            0x3E4CEB830775F23CULL, 0x9477A3536F4BF95FULL, 0x0B3BA063D8AECBBDULL, 0x1B2D86D5AECAA0E3ULL, 
            0xE9D52BDAEA1E06BFULL, 0x72BF0CF6901F74A4ULL, 0x867871D79E793A33ULL, 0xD87647E31052A09EULL, 
            0xCB8B6BCBDC1C03D6ULL, 0x6DAC20B0D8342987ULL, 0xA044C0D372A19765ULL, 0x93835B060EC6698FULL, 
            0x91B3DD6EA1E3867DULL, 0xECF795A74E0FD9E3ULL, 0x01A53C35D6E1E3AEULL, 0x1F1F32B4C0DF1651ULL, 
            0x91A99BF71DA75D79ULL, 0x529DDE72906BAF8CULL, 0x9DA2C0806D049B25ULL, 0xAC66462131739814ULL, 
            0x7686F23857560699ULL, 0x3C61B68DE03FE735ULL, 0xD6A1B4DFDF7660CFULL, 0x0D387A375F655CCDULL, 
            0x0C20B4267249D581ULL, 0x225E6B7B426A3E75ULL, 0x58E15BF0B17AE83FULL, 0xB28A304609F3AE6BULL
        },
        {
            0x62D0AB3B2B1D7893ULL, 0xF7120D17B26EBC21ULL, 0x956B331F3D4C5A23ULL, 0x019522A07EEB86ACULL, 
            0x21717B6438E248B7ULL, 0x99C015E578E70767ULL, 0x2493338C7060AEE9ULL, 0xF45B7785DE0B7C3FULL, 
            0x9BDC53CB53012FF9ULL, 0xBE4468F6A82A2EF9ULL, 0xDAF0B52E1F22AE21ULL, 0xD4FAA3A15EE70509ULL, 
            0xA2514DDD44617C60ULL, 0xE5D1ABD780359B37ULL, 0x9777FE7019BC5F66ULL, 0xD5291C21E34F680FULL, 
            0x11EA6069A425F371ULL, 0x68741B3833C5777AULL, 0x1152F60D2125C4A5ULL, 0x03633340E651D5DFULL, 
            0xAE30FC2B0B0CA70CULL, 0xA1A90195F92F4925ULL, 0x1833C5211B29E28FULL, 0xDD8E45C889A73FCAULL, 
            0x525FF2A0CF8B0E62ULL, 0x6AF36D0041AF358BULL, 0x155106E13F145DF8ULL, 0x405787EF952D74F2ULL, 
            0x8B8357A5A6AB6430ULL, 0x7FDC6CACA6B1B6CCULL, 0x590AB667F67CCEA8ULL, 0x06225F4BE29D39ACULL
        },
        {
            0xB58F2A803878FB9CULL, 0x2C8070DA30E5DF76ULL, 0xCA8A04254BAD4DBAULL, 0xB259A792A2203134ULL, 
            0x133967B3BA022019ULL, 0x20AD823BFCB00EB6ULL, 0x87F8CD99DA1EE0CFULL, 0x99F978244A14E981ULL, 
            0xEB4C46B255B0B5BFULL, 0xA1A1F41A1066DF02ULL, 0x686F7B7B8948ECC1ULL, 0xA75C609417A30317ULL, 
            0x16B746B61D3223C8ULL, 0x414C067B73C9628AULL, 0xD9E0EAD18764F0A4ULL, 0x690E7C953BC47869ULL, 
            0xB5FA8081B098D744ULL, 0x70041192257A7E7BULL, 0x295FB4710224E780ULL, 0x310995DCDAA52FFDULL, 
            0x16ECFD0E538A1AEBULL, 0xB3223B7CC0F885DCULL, 0x14382DD53CA90336ULL, 0xE7C544649A9AE591ULL, 
            0x629F08804D97633DULL, 0xDB6C6ADAE3CDAB0AULL, 0xDFFB38B227330BD0ULL, 0x4CEAF03893CC00EBULL, 
            0x41FF999244AB7670ULL, 0x078A4FF0E7E88EE3ULL, 0x7846B4ECF9916289ULL, 0x59E4CD06319A886CULL
        },
        {
            0xF6A682FF05240AB9ULL, 0x448BBA07C8F62B5BULL, 0x8964CDF7F39C3AE2ULL, 0xD8E84415CE11CD5FULL, 
            0xD32E563C87C43DCDULL, 0x33FE37E22866284CULL, 0xE46D46A48365E295ULL, 0xF518B17EB87552F2ULL, 
            0x4A4FB074D35D787FULL, 0x4F1FA7C7CCB27DACULL, 0x4E092DCAF9E94413ULL, 0xDCDFCEB257A7AEDAULL, 
            0xF0E09816CE34CD58ULL, 0x89B189BFCF979E0DULL, 0x51954C6EEFF48B04ULL, 0x3C350D74F70AC45BULL, 
            0x68E9B55A121F5612ULL, 0xD6D078E0BD9DEA8AULL, 0x0445680FFA8F694DULL, 0xDC8850CAB3DC674FULL, 
            0x0266657661F73B75ULL, 0x24C0A187FCF8423CULL, 0x7208627E41DB58ADULL, 0xB5A8A7D7CE6B4C91ULL, 
            0xBA66435005E453D4ULL, 0x7C3F5475B34C862EULL, 0x7BED01B14C2B8CE0ULL, 0x2DA7E11FB1FA6B5FULL, 
            0xB0FC2B9266A1F872ULL, 0x363408870DC80FF9ULL, 0x5CA7E77CF98201E0ULL, 0x66161C7AE62A7B19ULL
        },
        {
            0xBAB3A3AEB9069FD5ULL, 0x99F2F011AEF66615ULL, 0x91B0FEA70089C728ULL, 0xA62A907B47C9C900ULL, 
            0xA355E284DDCA0D1DULL, 0x72DBE8E88D92E2FDULL, 0x2CBC344243F8C6ABULL, 0xEAD3F759CFFD98F4ULL, 
            0x7AC912C69DE8B018ULL, 0x282FDF971EF0D374ULL, 0xDAF95F5D6E6BDFC9ULL, 0x7FA9EF97A9C257C7ULL, 
            0x1AA22BD7CCBDD9EDULL, 0xEEE6B0876543DC5DULL, 0x2B20395D7A789B76ULL, 0xFEBEF736D5376B29ULL, 
            0xB838B06A3197708CULL, 0x613B25A5EAC6EC88ULL, 0x8503E7569EE5251FULL, 0xB1AB7FC133761F25ULL, 
            0x7DFDF3358B43BAD1ULL, 0xA2D04B20FFE4533EULL, 0x64AA0C370B82DF9DULL, 0x2D50D14F2D3C9292ULL, 
            0xE2313F3EA68E2BB7ULL, 0x97B82EE3B54535B2ULL, 0x816ABC63C02C2DA1ULL, 0x9FDEBABFF28DB611ULL, 
            0x31355EE4F9F2EF99ULL, 0xA72ABF31AAC9B962ULL, 0x02A6BCD53B3997ADULL, 0xDC4317A72C93E4D1ULL
        }
    },
    {
        {
            0xDD395271F026E8D3ULL, 0x4D51E6DA8E1F0B7DULL, 0x28ED126FD0C6A14BULL, 0x67655CF347DEC1E0ULL, 
            0x48D9CA57DA151B97ULL, 0xC7563810FC52DE4FULL, 0x8625B1117A25C7C8ULL, 0xB54BA3EA01816DF3ULL, 
            0x1B1BD76F75C8189DULL, 0xBA4B592B26A70FADULL, 0x34419A18CD0299C2ULL, 0xDD09A01FD8ADC8E3ULL, 
            0xED775FB193F744FEULL, 0x87E9BE95B03D2308ULL, 0x44FDEC639F4BD382ULL, 0x0E1F96A69FE623BDULL, 
            0x75FFEAE05355C140ULL, 0xC60E5C10F1503F61ULL, 0xD67D6B20E7C252BCULL, 0xB5B00DDE909FD5C1ULL, 
            0x84AB10834BDA769FULL, 0xCB144C8000BFA52AULL, 0xF6944748D060FBF8ULL, 0x59076C7F54D7C245ULL, 
            0x996B8052A7DA22BBULL, 0x028EA0B867C3C39AULL, 0xB61D341165FAE55AULL, 0x987E21C6844A3ED2ULL, 
            0x2DD79BDAE08DE039ULL, 0xF48817E1A268DE8AULL, 0xEC775120D0CE1207ULL, 0x6797413BB893141BULL
        },
        {
            0xCBC1B9AA4EC70065ULL, 0x4D2F26A0C0B36283ULL, 0x9AC7F7B00A16A0D9ULL, 0x81DFC0E01525B321ULL, 
            0x344D8A79BEF8B940ULL, 0x61B314BE6DD5E62BULL, 0x4F15B1244EBA7948ULL, 0x80C9125826C72CB5ULL, 
            0x56FAE1AB5A6D391FULL, 0xF1DC1456EE66C170ULL, 0xC1EE2A1B7459E01FULL, 0xA9A4416A13BC5C1DULL, 
            0xE60E4B4EFAC82633ULL, 0xBA7CCC14AC1F5F2DULL, 0xE16B8F2D62E14305ULL, 0x97FC87A99E4CCD7CULL, 
            0x6E94CFDF59F08780ULL, 0x1279F44191BAEE8EULL, 0xD99D2AACD57856B1ULL, 0x163C714E7C295100ULL, 
            0x206E25B05D03BE04ULL, 0x6FF6880D77307A24ULL, 0x0CEAF5E5DD162C3DULL, 0xC6B36DBE1E0B45AEULL, 
            0x2076549EBCD3287CULL, 0x84D088B45FBA09E8ULL, 0x3519EF2B48B65063ULL, 0x0017D907979BC69AULL, 
            0xEBEA4ABABDE485A5ULL, 0xE10CA1CB33A6B223ULL, 0x13A2B4399DA051C0ULL, 0xC102D070BB73BEF1ULL
        },
        {
            0xEB4E268F8E3D24AEULL, 0x013C5D0CA3C95EE3ULL, 0x8FC65038F435509DULL, 0xEF7E7B8D234644B1ULL, 
            0x2696145CE209CB9DULL, 0xF4316DAD7B177A61ULL, 0x697061A693DA8B9DULL, 0x35AE2EA1A03B0EE0ULL, 
            0x3206E5C6A56BF195ULL, 0xDE69AA3B3805AF7FULL, 0x11257308A6A7C420ULL, 0xFD74B8EEDD8A4319ULL, 
            0x0492A761D731628CULL, 0x9DD6D15E29EC5197ULL, 0x7FC66BAA038D5EABULL, 0x75C1CCD39B4B2CD0ULL, 
            0x3D8446A9318991DDULL, 0x36C1C154A005BD6BULL, 0xF9557A725E38CB2DULL, 0xDBE8563CA979E170ULL, 
            0xF0A5BE8D4A86990CULL, 0xD0504443CE492A0AULL, 0x0A84D4D13F81AE07ULL, 0x48FE95CBC45524F5ULL, 
            0xEFE2F57C707DE032ULL, 0x692437C2B754B769ULL, 0x7FE976BC3D328BDAULL, 0x63D898FBC008D42FULL, 
            0xA6292C9703A1C273ULL, 0xC7AFD97FC26E4BECULL, 0x5AAFFC7C59937BDCULL, 0x6D0683AB0662A4F8ULL
        },
        {
            0x8F1A8846EA4465F3ULL, 0xDB030ED79FDDE14AULL, 0x6D97EE46E3B6F5D4ULL, 0xE14809B055DFE51BULL, 
            0x014946FB3C08228DULL, 0xEE5D17638541A058ULL, 0x68BDAD5659B6C419ULL, 0xBE069D2BB4CEE9BFULL, 
            0x0AD68B26FAB6076BULL, 0xA5F31781604FB756ULL, 0x80CE98915C80426FULL, 0x35CA3B058B2B4CB5ULL, 
            0xB36521FE469E7B2CULL, 0xC8BC788516DAEF43ULL, 0xB22012B28D0496E0ULL, 0x5D3B572E095CEA25ULL, 
            0x83FBC1EFDA796446ULL, 0x957A331AAE137C7EULL, 0x52608E1EC9355872ULL, 0x3E8B7270C165E693ULL, 
            0x2521125D89703541ULL, 0x1E7C258E5A08F9B7ULL, 0x8727E5CADE11DB53ULL, 0x809B1AE37F86544AULL, 
            0x1C2F4F721A0C0ACDULL, 0x4514C25B587A1074ULL, 0x6BD38852793EBDD3ULL, 0x38E34BFE3C8FC094ULL, 
            0x870EF9A4BACE2E0EULL, 0x54D970F6B8C97A22ULL, 0x73371C82FA850284ULL, 0x2C9D7631F746A276ULL
        },
        {
            0xDCF5C3A3E71478B2ULL, 0x75947899ACEE5621ULL, 0x64D1C6852D5C7F16ULL, 0xC3A406204682EC5AULL, 
            0x10DAFBF8FFB3B4DCULL, 0xD336ED116B280FA1ULL, 0xDBEADCFDD7D20F56ULL, 0xB1CB83FC2C9D5AE2ULL, 
            0xBF1E7B621D757B8DULL, 0x6A4DF615E5488710ULL, 0x025909A852C198F9ULL, 0xD2AA5924FCF3512AULL, 
            0x9B4512E364687A31ULL, 0x13A98FF3B8B81667ULL, 0xBAC7D1FE4EA6BADDULL, 0x2D5A7F50DC6EE3C7ULL, 
            0x90A88F5FBB61BDBFULL, 0x99AEFFA0C14C449DULL, 0xE7E71F32193FE933ULL, 0xF5C122FEF1063576ULL, 
            0xA1830D85F43F5251ULL, 0xD2E1F0BDA59549A9ULL, 0x8E6DEF6472F14A5EULL, 0xE80A5166A005345DULL, 
            0xC67251549804FBA2ULL, 0x7901AE41B83CB1ABULL, 0x01A97FB1EFD9F17CULL, 0x54B36724E9F6E2D5ULL, 
            0xDE843303203FB2A2ULL, 0xEE4788027E2E7EF5ULL, 0x4AD5100909D6F27EULL, 0x0C4E00186B100CD4ULL
        },
        {
            0x1A04C242AE9FABF1ULL, 0xAD82347F3281EFBDULL, 0x421784B84931A1CCULL, 0xF3AF68FF4FB122B4ULL, 
            0xF67F2A9F4E29E598ULL, 0xCD5FCC1DEB413773ULL, 0x4203FA28F417DAA0ULL, 0xE5FA7996BACE8D3AULL, 
            0xF1BDD48DB2F0B67AULL, 0x84255F44B5B0DC26ULL, 0x44195A02E5001F37ULL, 0x8A16AC4E4EFB6864ULL, 
            0x06C9417477197472ULL, 0xFB5240DA5C2D3816ULL, 0x883BC9FEC32D1814ULL, 0xEAE2A886EBA48B1CULL, 
            0x141BA069DD2B563FULL, 0xE89E5AC12AA8F748ULL, 0xA0AD8794B4CA405BULL, 0xB811901342A1EF69ULL, 
            0x1A94A9CB143BEA99ULL, 0x34D3FE305E240447ULL, 0x564C72FB828261EAULL, 0xCB77BF18F07DDAE3ULL, 
            0x910D45787638F71DULL, 0x66CFBC57D758CE71ULL, 0x3CFE042A7B53DDF5ULL, 0xAFCDD1188D8F9C08ULL, 
            0x54174E54001EA870ULL, 0x20D46C2B501FF72DULL, 0x19971A1CBBD3110DULL, 0xA43E5E565F66EC61ULL
        }
    },
    {
        {
            0x91CD266AEB44293EULL, 0x5A5C80A86FB8A202ULL, 0x93E36897B0C2148AULL, 0x950CA37269DD4492ULL, 
            0xE61727D161F18E74ULL, 0x72AC74215327FC0FULL, 0x5B1C9F9F42591C77ULL, 0x1F92A4F17FEDBD38ULL, 
            0x312EAB0F30C0B57BULL, 0x39629FC463F77FC4ULL, 0x22BD725651B84A21ULL, 0x9B2AABD7CB4FCE21ULL, 
            0x3F6D725BB21FA247ULL, 0x21316DA32C698279ULL, 0xAD99D5F73810317BULL, 0x912ECF2A9877CE49ULL, 
            0xF040C1C0A772E0F5ULL, 0x8FF44D87BC38AFF7ULL, 0xE1613EEF9A07E0BCULL, 0x47CA6B84C55E22FFULL, 
            0x0668043687284326ULL, 0x6C9312858E36E0ABULL, 0xD140CDEB45D8A27DULL, 0xE5F9E63D1B8DFA55ULL, 
            0x9BE7383B61344A90ULL, 0x5B62372CF244E1BEULL, 0xA81470DB58D46B7BULL, 0xD0F3C062F22AA0B0ULL, 
            0x4097FF9CB0A478EBULL, 0xE6087596425A5D2AULL, 0x1741ED96AA2CF219ULL, 0x5274B01770991519ULL
        },
        {
            0xD7CAB9C7E69EE764ULL, 0xF6D3F4678A05B981ULL, 0xF8C0453D436DFC31ULL, 0x9A36D955FDE3AC90ULL, 
            0x2470F6674B95B3C5ULL, 0xA7206D06992E3A99ULL, 0xC21648D24542F424ULL, 0x461FCD2D7FCD32C0ULL, 
            0x6264A2B9C1415C40ULL, 0xD44F17BD4A12F5B2ULL, 0x92002FDEFCF7D1D8ULL, 0xBA70443E300D4402ULL, 
            0x25794E894AA9BE41ULL, 0x9A198A72A1674AD9ULL, 0xCAFC477D1D12A5D2ULL, 0x9F5D1CE07A25CE34ULL, 
            0x1128017853791BD1ULL, 0xEA589C566D233FEEULL, 0x162C15FF364E9022ULL, 0x1D23C06AC9D55A2FULL, 
            0x8310BB1B78B6786CULL, 0x0C17B61A269378D1ULL, 0xCB3DDBEDAFA9F77DULL, 0xD727D352808D7F6AULL, 
            0x99813E17D930FD00ULL, 0x9A2F0A570D93ACBEULL, 0xAA0A51DA811C344BULL, 0x8D9F8AA4B1F9F0ADULL, 
            0x7F3A7C5688B31212ULL, 0xD396EBA7A1A8C6FAULL, 0x05D688AE57920B9DULL, 0x6FC4CE8EA7027EE3ULL
        },
        {
            0x4651BED75A98DD2AULL, 0xE84B722358241703ULL, 0x51F2825AF2148267ULL, 0x3206C567E74AC639ULL, 
            0xE42CFBFCAF79AD72ULL, 0x479C206567424EF9ULL, 0xCF172DFE1FAC0F7DULL, 0x0E01821C732FA6DDULL, 
            0x8F9D0CA7ABBA9AF5ULL, 0x2D2660CD595B1EE3ULL, 0x80B2E2E5BD37B2FDULL, 0x757FADC2D3A1D235ULL, 
            0xAA48B11597AD6EF4ULL, 0x4FA31604665652BDULL, 0x82DDA39B79DA2163ULL, 0x0D1F910B3F73F5D3ULL, 
            0x4BA0DF6F76E89E43ULL, 0x0F51B355ECCA6EC2ULL, 0xF3CE7BBF81698B13ULL, 0x094AB3E451106C1DULL, 
            0xD4A495F3FE5C0D84ULL, 0x6D6B83EDAB35B36CULL, 0xF026DF84F8218C6AULL, 0xC4B596C48F2A497BULL, 
            0x1191FCCA3905CCCFULL, 0x6E25ECA5FCCE5018ULL, 0xD9273438CA4F046BULL, 0x54B666F50887002BULL, 
            0xD67CC6DEAA86F4FEULL, 0x05FA91C95213521CULL, 0x4A6C481FC0BAD60DULL, 0xB77DF4274183C65CULL
        },
        {
            0x62686818D7BB0EAAULL, 0xDD58CABD289873EFULL, 0xC9D5CFC16737882DULL, 0xFBD9FE4B32A0B413ULL, 
            0xF24D08D92156D0CDULL, 0x164C4B3A63387E84ULL, 0x16576DB8DCA9C440ULL, 0x043E9D503426C7BBULL, 
            0xB55EA8A5F3B9AADCULL, 0x30ACECB346F2B615ULL, 0x89031ED961126241ULL, 0xEF211CBC10986961ULL, 
            0x252A783D88B00A34ULL, 0xE5952F6DDACFBDC0ULL, 0x059AC471EB8C0C88ULL, 0xFB49796D4BEA5024ULL, 
            0x4AE5F3F011256B4FULL, 0xFB9F119BB9C36F95ULL, 0x1D29D31F1C547948ULL, 0x0C7CEA7FD65ECBB7ULL, 
            0x11E7588176BB7FA1ULL, 0x0B2D3A211A350F0AULL, 0x6098AB56E22ED9EBULL, 0x77D2790AE8AFBB16ULL, 
            0xEAEAF1D2D3A53F44ULL, 0x9F42CF016208F15AULL, 0x4B4C8BEBB5D94162ULL, 0x2730023B688E9978ULL, 
            0xEE941D9C32CA29D1ULL, 0x39B9E05F5B2538E2ULL, 0xC52271839DE84691ULL, 0xC4B160F6EF21C370ULL
        },
        {
            0x5054C7A82F3273F4ULL, 0x3A5E42E65BDAB294ULL, 0xEB2D7C51D64F1CFCULL, 0x28BF641DF60005C8ULL, 
            0x3BEEBAC896E417D4ULL, 0x370DAAC2BACFF82CULL, 0xDEF11F531B6C25BAULL, 0x88C7C6699D55CB9AULL, 
            0x21360E03D926E9F8ULL, 0xA36E5EAA2D261E3DULL, 0x12B1169389599932ULL, 0xEFC10AA59F0437DFULL, 
            0x300CB158148BDA7AULL, 0x847098C74FA09B5AULL, 0x135C4E68410D697BULL, 0x6B1560EDF805E168ULL, 
            0x4473ACAF83C34FBDULL, 0x19BA084907E393CDULL, 0xC5945AB3A6DAE2ADULL, 0xE53E0C3BFD9BC466ULL, 
            0xC4DADA0CDD7328E1ULL, 0x03EBE4B6E8F9F9DEULL, 0xF4EE3E0A38AD8404ULL, 0x42C03A0BE3367267ULL, 
            0xFD8F4BF6E48FB49BULL, 0x01FDD26A1AECBC31ULL, 0xD140A414B703DFBCULL, 0x29950D47169F0212ULL, 
            0x24A8D80B8EEA9BBEULL, 0x1A5540D847EFCCFEULL, 0x59FB635974C2B5EEULL, 0xA0B5406DD973A624ULL
        },
        {
            0xF1C025774DAC3041ULL, 0x9B99813959136155ULL, 0xE98300624437876BULL, 0xF5946390E461D0F8ULL, 
            0xD715E0E1925421A6ULL, 0x25E72D0E7A214564ULL, 0x1477DD39D853D750ULL, 0x682D4759A9B124D0ULL, 
            0xEF8367CCE3B242A1ULL, 0x23265C32BC852E94ULL, 0xD1E25E2485F7A8DAULL, 0x71437698B392E7DFULL, 
            0x23D0223DE67749B1ULL, 0xD349D16F9513F439ULL, 0xF8DC98E681F7A9F4ULL, 0xD71CF8CCB907DD90ULL, 
            0x1D811BD43D3CC48FULL, 0xF63B55DFDF294A91ULL, 0x9C5972689BAAE165ULL, 0xA179A40B0B6C56D2ULL, 
            0xBCF9C8B832B07AF1ULL, 0xB1DD5F37486AC6DCULL, 0x1D7E28CE504A30AEULL, 0x1DD827A91DD1A420ULL, 
            0x9C4ACAF8E28C3BF6ULL, 0x88DEC2178DDB7720ULL, 0x4B3DFF8C71063459ULL, 0x6B71F957F0D2E0ABULL, 
            0x282EA7FBC4CDDBE3ULL, 0x507C61F60A2CFA37ULL, 0xB580E7B586D4E547ULL, 0xE849F4D1E64D7919ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeySpawnConstants = {
    0x448A2E01C692C02CULL,
    0x8B1EBCE756C2E34BULL,
    0xED987A697089C7D8ULL,
    0x448A2E01C692C02CULL,
    0x8B1EBCE756C2E34BULL,
    0xED987A697089C7D8ULL,
    0x08D1CB4D33F4C967ULL,
    0x6C24C20246CDB27EULL,
    0xB9,
    0x6A,
    0xDF,
    0x22,
    0x12,
    0xBB,
    0xC9,
    0x54
};

const TwistDomainSaltSet TwistExpander_Alnitak::kSeedSalts = {
    {
        {
            0xBF1D38C743420CDEULL, 0x95D43D9AE2EE366EULL, 0xAF6E2E467CFDC249ULL, 0x371CBC4D8F2C437AULL, 
            0x050B4E5029E340C5ULL, 0x78376706F58BBF11ULL, 0x4D44E41A81DA3523ULL, 0x7AC19DE2ECE9A5B3ULL, 
            0x2CE5C814A821F262ULL, 0xF6C6FCD6DDF2F412ULL, 0x7EB86A8A9E5C3BDCULL, 0x579155A80746A195ULL, 
            0xE0F192004E877812ULL, 0x7CE6E13D9BC4B234ULL, 0xF4963FEF051FCFEEULL, 0xE5B67AD5D6901066ULL, 
            0xCF294106A4C9A442ULL, 0x84419BFAA2D8F89FULL, 0xEE8B69007B4E495EULL, 0x74EFB8D6A47E56F9ULL, 
            0x4AF8C0FE1C4624C8ULL, 0xA9D5C892B71EB48BULL, 0x632091E783039FE8ULL, 0x93D7497F8028A9FFULL, 
            0x732ED2D8951F22ACULL, 0xBDDFA7E4DF215015ULL, 0x06391BA81064BA93ULL, 0x6C1CB6E5465E8A2AULL, 
            0x1D78887B5DD55C20ULL, 0x4FD0D716E83EC9A1ULL, 0xCCF805294D9D08B5ULL, 0x75A87F23CB2F5973ULL
        },
        {
            0x2B301CF890754EA1ULL, 0x14D6F4EF218258AEULL, 0x197F15428CAE230DULL, 0xD7A8718C4708CB8DULL, 
            0x65CDBD4675C3C9CCULL, 0x0A6C6DA7B7A1EA0EULL, 0x9BDA0C12E09CADC2ULL, 0x1DEE6583CB01E8CCULL, 
            0x8128358650D71B6AULL, 0xE3AD93139B47482DULL, 0xC483EC41630896BBULL, 0x113A3504702105AAULL, 
            0x542E642AF4921D5EULL, 0xBC2B85F864F73294ULL, 0xB70C14D8A7FE10B6ULL, 0x4959691059D743BCULL, 
            0x7F1D33841BE10C95ULL, 0x8ABA0CA6644B1EA1ULL, 0xB6357F1684172899ULL, 0x753D1CFC01373358ULL, 
            0xE608AFAC05370384ULL, 0xFF69153709712967ULL, 0x9CF502DCFEBCA25AULL, 0xEE76BB14960F4091ULL, 
            0xE741EEAFD8205A82ULL, 0x66CE496972F5023FULL, 0xB674077DA291A4B4ULL, 0xA8E77B059805DE6DULL, 
            0xCEC9B765E793C015ULL, 0x36EEF0F34B481253ULL, 0x8CB80F7ACB1415ADULL, 0xF5C14E9256D74A21ULL
        },
        {
            0xF1B84410298153C5ULL, 0xB8E9A37B9A496E45ULL, 0x43E54BC2260C61F4ULL, 0xB1C8F1879F1CA962ULL, 
            0xFCCAD8D76A6BAF06ULL, 0xCA68D34A3ECCA82DULL, 0xD4C9DFCC19B130C1ULL, 0x1DD5D15E29C2D8F2ULL, 
            0x57F4ADA07DC7DE40ULL, 0xA006DDBE7991EAE2ULL, 0xE4816CC18E6AFB80ULL, 0xA8F8396AE1C3C21AULL, 
            0x4D74C8978F3417A0ULL, 0xE525AC6A43FE5FC8ULL, 0xCC4E53CEF798644AULL, 0x64F89169572AF78FULL, 
            0xB3643AB3003AB276ULL, 0xA5254277F1E8BBA2ULL, 0x9A47F17FCE7D4A36ULL, 0x0B284B98061AB741ULL, 
            0xB7373FCD32C16C60ULL, 0x1155DF619950CE1EULL, 0x373AEDF292FB569BULL, 0x092D36B2ED19349CULL, 
            0xF3F9DF990BDFEF59ULL, 0x4963242CF9DE19EBULL, 0x809EC31AF2E58A6AULL, 0x0584796BD0CE4234ULL, 
            0x52C95BD5FE99A501ULL, 0xD82A2FDF5148CBE5ULL, 0xDF34713F2E765EBDULL, 0xC65E2D1A669E887FULL
        },
        {
            0x2B06EDBDE31568AEULL, 0xB4E6B8F756797908ULL, 0x47B5AF8485B5E7D3ULL, 0x28072ECA20715211ULL, 
            0xD855027855C39AAFULL, 0xEC2DF5FE8C88EA77ULL, 0x8131FD6C2AF365DFULL, 0x84DA4E480E19C763ULL, 
            0x43CD213BB4217576ULL, 0x1CB0795B8FC7520EULL, 0xA5A663FD74B79145ULL, 0x58DD7DB5A78485F1ULL, 
            0x8FECB07FED738B04ULL, 0x744F3EE64A2601F2ULL, 0x760593949D8CB4EFULL, 0x0234A4F26BB10085ULL, 
            0xFB4A869ED6E318BAULL, 0x1FE674324E41938DULL, 0x79E1E53E78B084D9ULL, 0x90ABE286DD0502B2ULL, 
            0xD84B4CBAB492673BULL, 0x12007593BBA95AF3ULL, 0x00F5A9FC7F3E8D70ULL, 0xC24C9983CD387E92ULL, 
            0x34E105C813FB9D7EULL, 0x08BD86DFA8A68B11ULL, 0xC1E3DF069649EB62ULL, 0x35668E777119649EULL, 
            0x47310A9C6A4D3ED7ULL, 0xC613766DBAADBE03ULL, 0x7C649F74A595D0FDULL, 0x043432D6D98FF9DCULL
        },
        {
            0xA9146224042FD406ULL, 0x1B24EAABCB353E30ULL, 0x1A66EBC58B30F0D4ULL, 0xE2A1C4166F5F6445ULL, 
            0x03B47E10A6A4DDECULL, 0x0654ED27E04B81C7ULL, 0x958D68570691DCFFULL, 0x6A59E2D046452CD2ULL, 
            0x37E0FF56686E8EBCULL, 0x0E4A1C8116FC271FULL, 0xA0A3334338071FDBULL, 0xF174EB29D28F9F5EULL, 
            0xF04EBDF70463FA36ULL, 0xB14F3E1C96C06F5BULL, 0xC0E3C207CA715D6EULL, 0x3E45E6B5728508F2ULL, 
            0x20229DF104C33FA6ULL, 0xFE88B7E2B71FB43CULL, 0x9C1E725724ED1649ULL, 0x813D58C4FCC4E3BBULL, 
            0x0D693112190FCB68ULL, 0xD2880DD4E3525447ULL, 0x586A1D5FB3BFBBDDULL, 0xAFD27D0895644788ULL, 
            0xD10CC367E7B08B44ULL, 0x28EF079698841383ULL, 0xEF8342CBE093272EULL, 0xE1898C0C5413D766ULL, 
            0x1C3663F8916B28ADULL, 0xFA44CB6B6208F7F1ULL, 0x51EE568031A35C51ULL, 0x06EA07E77746B49EULL
        },
        {
            0x569A74B0D41F4CA4ULL, 0x730354F41DA08658ULL, 0x160009A4FD1ED21CULL, 0xD058F85CFCF9437BULL, 
            0x5F6E5803BED8D750ULL, 0x2CAB03DC8EDBA403ULL, 0xBC773F0388407137ULL, 0xBB9F7A0FAD3FB743ULL, 
            0x832B3622903A4C57ULL, 0xECA2C57B76FC1788ULL, 0xC714D24E4F22F083ULL, 0x63EEB1F48F952F14ULL, 
            0x3C811D94ADD5F9F0ULL, 0x8CB711A9106D59D5ULL, 0x3C5920FBBDC99660ULL, 0x43501F1076DD15EDULL, 
            0xB333C7F0363D3FD9ULL, 0xD2D8C425EBD95497ULL, 0x5DCA39E97935778DULL, 0x98949E307475AE0FULL, 
            0x670E262A885B2A56ULL, 0x7556C544BC4CDB56ULL, 0xA11D577AFBD35F40ULL, 0xE55372A5F881B6B3ULL, 
            0xCDFE063238B1D611ULL, 0xEC64CAD11EE1EEE4ULL, 0xA342E96288ABBCF6ULL, 0x5983632B0AC06D9FULL, 
            0x79057A1223693A81ULL, 0x4B3F0D50958F75EEULL, 0xDE81CE2F783FF1A8ULL, 0x2E28B6CAE8D32DABULL
        }
    },
    {
        {
            0x1FA249561787692DULL, 0x584BF02726A46617ULL, 0xF314ACAC620FAA62ULL, 0x14F703276375E44DULL, 
            0xBEFC54BE0F166349ULL, 0x709273D356146838ULL, 0x494F6901C53D336FULL, 0x261639B5D4ECC0A5ULL, 
            0x1666D2D4E472F5BAULL, 0xDB7D637B9E29FC95ULL, 0xFF8D1AEE50504414ULL, 0x4DE7404836E1D755ULL, 
            0x85C01E10533C767BULL, 0x01AB3B116AFF505BULL, 0x0CCB0B3B73411243ULL, 0x8C7696A920504053ULL, 
            0x00278F3DCA48E83FULL, 0x9F86C1BE1D0A119FULL, 0x739C6EA7B8BD5B22ULL, 0x30C9DEF3457DE6FEULL, 
            0x6750EEFFCEB33918ULL, 0xF508023B07493313ULL, 0xEE47F9244E9B03DAULL, 0xDA797814DDABEB9EULL, 
            0xC88A10EBE4495F83ULL, 0xDBFBAC213138317CULL, 0xA94546413E0206BFULL, 0x426E223B20A25DFAULL, 
            0xFDDE5CCAE686CDB0ULL, 0x2636F17596E9FC08ULL, 0xA76FDC476C56C23DULL, 0x16B73C24F37C73CFULL
        },
        {
            0xA1FC81CE8ABE7DB7ULL, 0xC68E84F5DDADE18EULL, 0xEDFD668FA6C7D465ULL, 0x5B778AD91DDBA2BBULL, 
            0xD79129FA85BFF387ULL, 0xD3BAEA14F4047D76ULL, 0xFDA53FA8153B133AULL, 0xDF40B958A44BB1E2ULL, 
            0xBA6953440032FBAEULL, 0x5E5603F6683FF3EBULL, 0xFCE7CFB55D37F4E9ULL, 0xD56C6F6E0887941BULL, 
            0x600924C0659BB6CDULL, 0x2A88F14A1DB04636ULL, 0xBDC171BBEF720C67ULL, 0x66032C1D23E4B974ULL, 
            0x1C3F8F5E0321C082ULL, 0xB782E313D35BA684ULL, 0x71556BB9D2F630E6ULL, 0x3C6841E3EFA5BA19ULL, 
            0x793D85A136EEEE1EULL, 0xA6407323CE7D8AFDULL, 0xCB501716BAD33F7BULL, 0x0663C4305A70332DULL, 
            0xFA456066222D08C0ULL, 0xBAB8B7B148F16BF7ULL, 0x69E581097A6C9FA5ULL, 0xA667BAC65F4A7EB7ULL, 
            0x253768E62C7D7E6DULL, 0xC20BFC2E4A8FE469ULL, 0x6055476A47249128ULL, 0xE739205D7EA50B81ULL
        },
        {
            0xCAEFB4F26601F226ULL, 0x1A32FB1D59229AE6ULL, 0xCF97A7F53B67551DULL, 0xE6CB64AB30DBC6C9ULL, 
            0xD4730F92CEFF268EULL, 0x99287782DCCA25B5ULL, 0x09BA7AEA8158DF80ULL, 0x205C9E4183749E30ULL, 
            0x19F2E7FD0E4F0C3DULL, 0x4A34F5CB40343CAEULL, 0x72E53B8A0099D396ULL, 0xB4CDD05E64CB0F57ULL, 
            0x2570FBE3D96596BFULL, 0x507EF8F8DEBBFE78ULL, 0x0863B6DD44254B9EULL, 0xADEC7C436C02F31BULL, 
            0xEAF4CE4154669CF2ULL, 0x61607F8058FA6E43ULL, 0x7EFEB21D4EC21820ULL, 0xAAE91CEF038BC8C2ULL, 
            0xD18DFE58FF8E61E9ULL, 0xA1F639B2E1D7BD23ULL, 0x9593C56078B01677ULL, 0x6875FC2243AC326FULL, 
            0x0E495A44812507BDULL, 0x70CFC8254F8D664CULL, 0x72ABC7D728F379EEULL, 0x18BEFE40B852091FULL, 
            0xB7642CA04ADE3F34ULL, 0x746AF722080362C1ULL, 0x300ABC01655D5CF8ULL, 0xEEA4E14D881A106AULL
        },
        {
            0x2825BC4C6B1B6BDEULL, 0xE6EBABD2C7BF8141ULL, 0x44D41B66F444BF16ULL, 0xFF0A13063DAC8CCBULL, 
            0x4BA4E8D5F5FEAC9AULL, 0x73EC021553DD7835ULL, 0xC4E2C0EC235E9701ULL, 0x6D581E2CE6971F17ULL, 
            0x83ED8106903DFC0CULL, 0xEA7CA6985985CB65ULL, 0x4EEC6058F29708F2ULL, 0x86A813647252B162ULL, 
            0xCFE74235609F1379ULL, 0x52E1AB0165F57EE2ULL, 0xADC4FA751FD47387ULL, 0x5C277E43A851C7DCULL, 
            0xA494E43032976076ULL, 0xEE14D300E00821E0ULL, 0x09128935F9612101ULL, 0xB2B139E620F298D9ULL, 
            0x5DE1CA51F7634910ULL, 0x2E4544FB368EFF3BULL, 0xE35C5C4B5D6D4B20ULL, 0x820BBDE38DEB6DA7ULL, 
            0x4E2AB1894298F958ULL, 0x8BB374C9884DFD28ULL, 0x77B852DFC7436BA6ULL, 0xB259B2358EE804F5ULL, 
            0x1CA5912290BE5764ULL, 0xF7078C7763B8B05BULL, 0xC4431D7C08788E7DULL, 0xD8FCCB8480EF529AULL
        },
        {
            0x2FB1F572C7810CF8ULL, 0xF85D4527F64876DBULL, 0x5158A569447A62D7ULL, 0x6F761F8BD861D69BULL, 
            0x913778E9438874F2ULL, 0x982BAF17BE3E74C1ULL, 0x5D72AF99E25A0527ULL, 0x08C0EFCC800CECACULL, 
            0xA98FA42B5EE945EEULL, 0xF6F5602102AC6396ULL, 0x3950775407E9681EULL, 0x739AF63EE82997F2ULL, 
            0xD835DAA1B60E26CEULL, 0x43EC09823672B3A4ULL, 0x0BB9E31B1395D25BULL, 0x70038F5B5505B718ULL, 
            0x45D542BF54CAFF1EULL, 0xF1F97F31F965C8E1ULL, 0xD0B896BA78D090A8ULL, 0x7CB0C32434F33E78ULL, 
            0x767258BD86E88445ULL, 0x8B7210C9C139D061ULL, 0x49D34ACF89AD8123ULL, 0x1C7A8EF705846DDBULL, 
            0x1CA98D378598953BULL, 0x27275AC2DCBB66D2ULL, 0xDB3552FF8F9BA8B3ULL, 0x6BF28DE12CF493F1ULL, 
            0xA0215D603A839E5BULL, 0x3B91A4BB1D5B19EBULL, 0xE2403A0162D1D910ULL, 0x3C0D44955795EF45ULL
        },
        {
            0x061C0091FB96A1F4ULL, 0xB8B6D66EB3F093CFULL, 0x5709B95C494D9109ULL, 0x080B53518D09C903ULL, 
            0x6EE809FD841A9095ULL, 0x3B7B60D339E066ECULL, 0xDD917EAA39406372ULL, 0xD77F81A13A8012D2ULL, 
            0x63C31749FF65874EULL, 0xF030FA89C7C2E9D2ULL, 0x027B4B713CE66595ULL, 0x4FE39313CEAACE00ULL, 
            0xEC95D33CCA786E60ULL, 0x2CF122EB1125176FULL, 0x9B59CCF5E736229BULL, 0x3100DDB19BF77799ULL, 
            0x978E8B191BF66237ULL, 0x0C2CA559EB78C307ULL, 0x285DBA8E413EAA36ULL, 0x33BE6B59A93D33F7ULL, 
            0xC4900AA8861A397AULL, 0x04BAE57CA8DFB448ULL, 0x681202F013804EF5ULL, 0x0835A61D66386764ULL, 
            0x3907DCA46F8F08B3ULL, 0xD2540117BCF96BEBULL, 0xAEED0507E85375FFULL, 0x7B6EABA69B936814ULL, 
            0xDB8930C63F0FB2E4ULL, 0x62152F7BEA1EF477ULL, 0xACE27DF6E3CFFB01ULL, 0x67035E9247FCF058ULL
        }
    },
    {
        {
            0xABE2B8301F2863C6ULL, 0x2BFA5F1FC35F1D4CULL, 0x496395785AF37944ULL, 0xEB7BEFEAB908A33BULL, 
            0x53F9305D6EBBE1B8ULL, 0x2C381EB3D70CB34FULL, 0x932A9E994BF6E35CULL, 0xEC9A9B0EE94B6822ULL, 
            0x24D4647AC1F5CEA1ULL, 0x813DAC25098B33D3ULL, 0x26B37069808305C5ULL, 0x8DE3119ADB31BACEULL, 
            0x483ED1EAA4D4FDD9ULL, 0x1C29ADC23AE99A19ULL, 0xF4AA2E6ADAECF19FULL, 0x0E8284AF1684C3E0ULL, 
            0x8C14941C33F7ADA8ULL, 0x6FE82BF39B8EDA64ULL, 0x9E7D020D0B5AAB13ULL, 0x49E921452384B1F4ULL, 
            0x617923CD92DBB953ULL, 0x8455C9FE10EF782CULL, 0xEEC31BDBC9AD00B5ULL, 0x71B04B6926069BAAULL, 
            0x105C6DD5E72E5A8DULL, 0xC79FDABEE84D0209ULL, 0xABF36D2324BB06E2ULL, 0x494347207D4750FCULL, 
            0x376D963056D58597ULL, 0x27994F4ED2A77F8BULL, 0x094631F2BCC6DB94ULL, 0xBCD91B9C54E01AD8ULL
        },
        {
            0xD5DCDE8C6D9BF0C3ULL, 0x579BDCF2965A64C3ULL, 0xECCA138A5ED9FF2CULL, 0xF36124ECEEB6A64FULL, 
            0x317FD987593761D9ULL, 0x1E5777F0C98E9C0DULL, 0x7CFB12F80513ADCCULL, 0x3C878869B588421EULL, 
            0x2B262D780BD6F86AULL, 0x93F3FE9586BEFFEAULL, 0xE662DA69A1E2A1F4ULL, 0x2EA03FC4172FAEC6ULL, 
            0x3C73C709C90933B7ULL, 0xEC4E6106D9E2FBEAULL, 0x60064CA875C4488DULL, 0xFDB19A962704DEECULL, 
            0x2B32A4A6CC54795AULL, 0x48BB4B25E4126E19ULL, 0xDC2D7679EBEE7A41ULL, 0xAABE8F6D7F162954ULL, 
            0xF5C6EA8293B5A88BULL, 0x442BEC82F4177352ULL, 0x66B77ABD3F6CF8DCULL, 0x1AAE5A70A9FA6C8EULL, 
            0xCC17A161A25EE71AULL, 0xA89EC719D9F6FAFCULL, 0x2128B3734AA03B1EULL, 0xA504BD05454E13E2ULL, 
            0x4C9F3A35D1F2EA42ULL, 0x1B7813C7FC3235D8ULL, 0x455F5996BA1D0483ULL, 0x14EDC6689A7EDEE8ULL
        },
        {
            0xAAF70DF6647C1015ULL, 0x49CA992114BEA560ULL, 0x70D158A8993A0062ULL, 0xCCD3F01FD5DD98C2ULL, 
            0xC1CEEBB45ABC5C55ULL, 0x57EC5CF7C72A0EA9ULL, 0x30966D32E0089842ULL, 0x9B5CE72890110E96ULL, 
            0xA1ED31A2FABE70B6ULL, 0x523A322F9A99BE0FULL, 0x9E7CB977DE3AD611ULL, 0x3C6373CDD7EAB61FULL, 
            0x8E322EC6FF598D77ULL, 0x58677898B6D90D5CULL, 0x3A6C82DB451D3587ULL, 0x9EE1B4E33066C11EULL, 
            0x6AB2B92A8A5D0E1EULL, 0xF94231D5606A5A43ULL, 0xC2F7B314EB8804C3ULL, 0xB6A62DA19FCBE747ULL, 
            0xCA444930237E0E02ULL, 0x35DD978F79332496ULL, 0x687E6ECC2B76945CULL, 0x1F64AEE6AF18D6A5ULL, 
            0xB3D4563FFE08723AULL, 0x7FBB5C6EF4173BB2ULL, 0x03142F4B304B41B3ULL, 0x34021BBE5B34FF01ULL, 
            0x6C74D0E8B4925529ULL, 0xFF216C5E375BB651ULL, 0xA0FA80E72E3DE3DBULL, 0x829A699708D79FABULL
        },
        {
            0xDFDA968839CA35CBULL, 0xC3A8C7504C7918D9ULL, 0x1FEABE94AC5C5890ULL, 0xE22F8FDE9D6B661DULL, 
            0x794C466A10A9AABCULL, 0xF38DBC3D3DACF170ULL, 0xA762F2765609847DULL, 0x6792DC8DEC7D3CD3ULL, 
            0xC483DA9316DC9283ULL, 0xAEAD510B52E7B2E0ULL, 0x17D6E22984319C3CULL, 0xA0B6E7769292A5C5ULL, 
            0x6A663EBA52C81628ULL, 0xAA5655988684A6E7ULL, 0xE86AD413070FF9D5ULL, 0x3DF78F1CDE75EB31ULL, 
            0x4C3B96105A02FCD8ULL, 0xD3BD3C82B056F2CCULL, 0x58011200873031CFULL, 0x966817369FBE2FD0ULL, 
            0xB8865C9B0CE52ACDULL, 0x2D6448BF6DCE984DULL, 0x04D0CA27BE1842C9ULL, 0xCF26AE169C5A6161ULL, 
            0x330F577716767615ULL, 0xFE6EF354852B64ECULL, 0x66ED44614E655EA5ULL, 0x73F9932BB152026CULL, 
            0x62360A8AAC3DE6A5ULL, 0x803F0D23A592D6B5ULL, 0xF8F57850117BE0E9ULL, 0x0837260731944E94ULL
        },
        {
            0x6FFADD98D66A3D4BULL, 0xA2AB5E6EC65A6069ULL, 0x61230696CD0EF546ULL, 0x83AE83DB4286C5EBULL, 
            0xE1946517DA163F38ULL, 0x19BD609CDCF2FDC3ULL, 0x1AB573A4C3A6AA4EULL, 0x5A3A1F7E1292B0E4ULL, 
            0x539BC8EB69A04AABULL, 0x6BF4ED7810050A40ULL, 0x97E114295E27C80DULL, 0x928D988682B77235ULL, 
            0x3B52E6F90BA8FE1AULL, 0xB788F87D72EBF44FULL, 0x69D5A0E1FE79D764ULL, 0x937923CC532E62E8ULL, 
            0x8CF19FDF09C6A377ULL, 0x92C269659883F96DULL, 0x83EA9A08C4332F65ULL, 0x60D5D54E5957705CULL, 
            0xCD793B0E565785F1ULL, 0xE47061C0D75F55C5ULL, 0x01527E995AA075DBULL, 0xB5B0F026473CC94EULL, 
            0x38F8E777AAB9F5C5ULL, 0xF35EE317DD8057A5ULL, 0xCCD75A10470A1C36ULL, 0xF975075D3DD4E37CULL, 
            0x222F2515EE9B91DCULL, 0x5DAC560A92C05084ULL, 0x16F6214CFBE08372ULL, 0xDC263B9D896A27A2ULL
        },
        {
            0x55C4A8AD2FD34226ULL, 0x11D2AE6E3851E112ULL, 0x9791E05C99D7D628ULL, 0x2BF0B5C996F3306CULL, 
            0xAF6FB4EEB32B57A0ULL, 0x9A4F421E39A91044ULL, 0x54053C8664E8BE7EULL, 0x173837FEF2CCBE55ULL, 
            0x8599D75F71BFCA29ULL, 0xA08BF1148F22E945ULL, 0x745236FC67B9A9D4ULL, 0x373D8EF37B694A9FULL, 
            0xC1649EE7D0E44FA5ULL, 0x5EC5FFFF7E80E031ULL, 0x3361C264EF71A3C3ULL, 0x7779C6842AFF7A92ULL, 
            0x9FFC2DBC0BDE077AULL, 0x3BAA7E2796C27358ULL, 0xCB67374BB1EAECC1ULL, 0xFE325037D635B3EAULL, 
            0x4F6B2E684F066ED6ULL, 0x9AB90A01363C4F22ULL, 0x495C6F5B83519259ULL, 0x5855E83FB7C11229ULL, 
            0x9A8DF8754E8EE44EULL, 0x4B0337B9E780E3C1ULL, 0x34C51D5F7C8ADB79ULL, 0x8E2C1EC5CFE26EB7ULL, 
            0xF41EDC4F9C5A2E58ULL, 0x96E6204725100B2FULL, 0xA6D7E42C4103D7F2ULL, 0xAF95114CBF0FD9CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kSeedConstants = {
    0xCFEFEC79F89EF258ULL,
    0x5594BD9A3B20FD9BULL,
    0xE612C6C09D38E756ULL,
    0xCFEFEC79F89EF258ULL,
    0x5594BD9A3B20FD9BULL,
    0xE612C6C09D38E756ULL,
    0x11444B5BC29FA285ULL,
    0x000D9BCF054A989DULL,
    0xD2,
    0x44,
    0x11,
    0x39,
    0xDB,
    0xFE,
    0x59,
    0x4D
};

const TwistDomainSaltSet TwistExpander_Alnitak::kTwistSalts = {
    {
        {
            0xD57CF699322022D2ULL, 0x8C72B813884B9ECCULL, 0xF8C867107AA8240BULL, 0xFC6B9EBE2505EA09ULL, 
            0xB0A3B6DF977EF7C8ULL, 0xD0EC0AE3D8C787DDULL, 0xBAEAA9784A39F1C7ULL, 0x8578983898FC69D0ULL, 
            0x9E1FEB11F04F99BAULL, 0xD7D781BD6A3FF2F9ULL, 0xDB29D12D48518BF7ULL, 0x5D95460D0A3F2DD2ULL, 
            0xEF3E13256EDD703CULL, 0x011A9ADA29053ECCULL, 0x3D29CBBF6C5EB0D9ULL, 0x7AF70650E2FC7608ULL, 
            0xE054F6EE0B70567DULL, 0xF0C3EC5036C1529EULL, 0xB8992630EE6DC907ULL, 0x481358CA0F3A2676ULL, 
            0x7BCB42FD6DD7B035ULL, 0x13328308AF443D06ULL, 0x2FB8E2B78ABC0E1FULL, 0xF6F38FDD2B7C89E3ULL, 
            0xECF0BE3A66DCD385ULL, 0x3155C3604808AD07ULL, 0xB4D08C60DE9FE67DULL, 0xB62CEE26C5C037DAULL, 
            0x74C6947DA21D9FC3ULL, 0x15234A8AE93C1FBEULL, 0xC79525D60AB6A048ULL, 0x3B9D7038D6D0DBD7ULL
        },
        {
            0xD0ABCFFDE948AE6EULL, 0xFB6E1EB371897B5FULL, 0x1D8ABA736B3D6F3BULL, 0xF78842AA69CB257EULL, 
            0x18051406BB52CB09ULL, 0xB3C863B03F731B5DULL, 0xF0E83BB7DD4A8511ULL, 0xBD0E706A495E7C30ULL, 
            0xA75DC4A16C75C3C5ULL, 0x1933373C024B024CULL, 0x779A53D1929F68B7ULL, 0x48C1B7AC5E5C3856ULL, 
            0x8CAD6C777358AC8FULL, 0x86B7BB42445F6AEAULL, 0xBE68C5067451A986ULL, 0x504B00D9EC1DBACBULL, 
            0x3B02180913582C32ULL, 0xA1F934DB7F5BA90EULL, 0x2360DC3FB83E8AE0ULL, 0xDAE987A68B9A9659ULL, 
            0x1553310F59CC6850ULL, 0x8D0C64C05220E4EFULL, 0xD56E4D36DD3C263FULL, 0x10A4571B607B79E9ULL, 
            0xE10EA60793983770ULL, 0x4041C922EA5A4264ULL, 0x9BD1B4E2A60586B8ULL, 0xC7E7E0566FE67F9EULL, 
            0x229DF9B4B5AF02DAULL, 0x2652CA57A4156050ULL, 0x31E672E8F49FA3D6ULL, 0xAE198C9D82DE5597ULL
        },
        {
            0x5503C7FDC4835F10ULL, 0xC025EEB0FED0C7B5ULL, 0xBB429A22FD657597ULL, 0x66F51FB54E270429ULL, 
            0x6160350323A891A2ULL, 0x9F7F2A5D4975F3B9ULL, 0x946EA81155929927ULL, 0xBB4E65E7C491A043ULL, 
            0xB1C1E9EF892B49F5ULL, 0x354B24CBF4E22854ULL, 0x8002B23CB764D0F3ULL, 0xF72A4B8CD8CB7317ULL, 
            0x0106BE484B68B43AULL, 0x37BBD873721DD858ULL, 0x9A6943E6EB1BC4C6ULL, 0x50E6EB71159C7D11ULL, 
            0xEDA3212C2720A607ULL, 0x0A3081DF2537A305ULL, 0x6EDF3114809A1B65ULL, 0x4DED525927670CC1ULL, 
            0x623CD2A9DD8B3A35ULL, 0x78B2F7F11FBCFF76ULL, 0x67961D30F2196693ULL, 0xED90C36F485EFADDULL, 
            0x37DB032F7EF1D0D2ULL, 0x06031B760F04612EULL, 0xF1574D658CFE8BADULL, 0xF4D47DF90FBE49C2ULL, 
            0xBB1DE5EF9D7AA335ULL, 0x472F42F76A2A6291ULL, 0x77D8D4BE09EF7FFEULL, 0x8696B0C46210BCB6ULL
        },
        {
            0xB94856D9B68753E1ULL, 0x29E4A6A0D6D229C8ULL, 0x6BD8A49B987A92E3ULL, 0x529A96E25E93B33AULL, 
            0xA5C45C859D21D647ULL, 0x4E0D77F7D14626FCULL, 0x30481B9F537A3F40ULL, 0x7132778180603DBBULL, 
            0xFD1E8C64CFD1F61BULL, 0xE379D1EE27A28EA9ULL, 0x292F7848DC617847ULL, 0xA2A99B55D3839411ULL, 
            0xA9D6519063761291ULL, 0x376419C27EE194D9ULL, 0x52B2E7D36B82C327ULL, 0xA31B46670D556478ULL, 
            0x6586D16335F2B810ULL, 0x9F99D20AEBB76F49ULL, 0x28C8753ADA77E673ULL, 0x30243EC4CBC91878ULL, 
            0xC6A4D977DE83905FULL, 0xB27EF99FC07AB77CULL, 0xB712C6C8FEE570A0ULL, 0x8CE48B7396B0ED34ULL, 
            0x57AAAC2F263D90B7ULL, 0xD502A844E0C97498ULL, 0x9255F89A6A8F015AULL, 0x423DB0EA08E45D22ULL, 
            0xC77AD88BFCBCEB8BULL, 0xFD636B4FC39E4CA2ULL, 0xCD79A3BDE849F867ULL, 0x058ED101B997B4BEULL
        },
        {
            0x4510A0A7A8B54A0EULL, 0x851AD63344C9B73DULL, 0x54BD395639CFEF73ULL, 0xB72B147DE6BA810DULL, 
            0x3BF9C90B2EA139DBULL, 0xE27659DAE08DD04DULL, 0x0E70325517DC47EFULL, 0xD6676EBDD1706DACULL, 
            0x7BBB523562BF3130ULL, 0x10FFE6EA4008E62DULL, 0x8C2116B4B1E3D978ULL, 0x2A8194D2B3EF8FC5ULL, 
            0x132600F4ED1A2341ULL, 0x34B7C27B1A04040CULL, 0xA06D256F0058C599ULL, 0x9F22D40351AA54C2ULL, 
            0xD044961D6E5857CAULL, 0x2866F7306FB6699CULL, 0xEBC3D49424D26506ULL, 0xA4A3BDD092DDFC10ULL, 
            0xE562C16887A70455ULL, 0x622BC2B74B42F161ULL, 0x74C9BCCD4C5C84C1ULL, 0x4063A177BB0092E3ULL, 
            0xB21D8F9227C248EFULL, 0x45D71266D2F66A17ULL, 0xBBC2C854060FADD5ULL, 0xA4831AF79305233FULL, 
            0xB5DC1D5F50AF266CULL, 0x869E635AFAB99C54ULL, 0x5C9C079E9ED04573ULL, 0x6B7E1419571BAF85ULL
        },
        {
            0x1B3393DD112AD3F3ULL, 0xF855B540FFDDEE77ULL, 0xF1B9FD7CC5DBC5EDULL, 0x4F40D63A051D2F12ULL, 
            0xF6A1609D2E7479A9ULL, 0xC6BF7F8287A1613DULL, 0x117FD5C2BCB7BB1DULL, 0xE60BE5E4C08EF5E9ULL, 
            0x87DABB2B83EB3760ULL, 0x2125481F62A35CD4ULL, 0x40FD22F60ECCBC98ULL, 0x84D638837FAC8150ULL, 
            0x94450771D0C6BB42ULL, 0xCAC44ABDD32BAFFDULL, 0x249B8D871AEA92C5ULL, 0x1631760BE4F43754ULL, 
            0x558790FA5996D8A9ULL, 0xDE5D7DD6E63C6090ULL, 0xD893888EE67A7BC0ULL, 0xCAFC6D0087783E9DULL, 
            0x51B2BBF53EBDDFE1ULL, 0xF227AA5E2A4D166AULL, 0xDEE3411ED1809BAEULL, 0xA637B989625B7E5FULL, 
            0xE915075C39C22606ULL, 0x5D2485D5468C40C5ULL, 0x0099FD1AED32BDD0ULL, 0x7A115E79E012A363ULL, 
            0xA7D26AD85DDA4161ULL, 0xE3B26134857C6FCBULL, 0x0CD643F3B9E02AEEULL, 0x8E2020AA39E2F6CDULL
        }
    },
    {
        {
            0x5570A9D8401BE723ULL, 0x3FF45126B4973836ULL, 0x00BDE90027B943E2ULL, 0xA0F4E11ECEBD26C8ULL, 
            0x75B3AB6F2BC66E32ULL, 0x9A8DB8399A5FD42CULL, 0xDCDDEAC342DDDF78ULL, 0x46E7617E789EA188ULL, 
            0xECF28B2C9C1609C1ULL, 0x8F85204FC634564CULL, 0x047835702419F556ULL, 0xCE3E72793B8B6360ULL, 
            0xD4BD7603C239DC77ULL, 0xDCA0DE8AF3C93844ULL, 0xAB3E03ECA534913DULL, 0xB9C773891D187436ULL, 
            0xB8704D02AC18CE67ULL, 0xB8D0FEB441F5D548ULL, 0x704A85F9322C9BF5ULL, 0xBE36CBE42862C99CULL, 
            0x640314A815248606ULL, 0x18223DAD7F17AA44ULL, 0xA821C4C477D2F765ULL, 0xF0B247C8803D59E3ULL, 
            0x6FA882C6FBC40F64ULL, 0xFB84C9A2C53FDC7BULL, 0xE80EEEE7D1CFF9CEULL, 0xA1681193767F0497ULL, 
            0x87FF6C5C262AEB56ULL, 0xBCB17856055C76ACULL, 0x7909FF74FA92927CULL, 0x8A3BC4021F2035B4ULL
        },
        {
            0x279A74056E2CAF52ULL, 0x8AD2095FEAA9C1B1ULL, 0x626CB3A688222F22ULL, 0x30C48E2BEE34AD51ULL, 
            0x6B29FE1B82CDECFFULL, 0x21CC0462B6675B03ULL, 0x924E8AA77B40E095ULL, 0xA6051B1C1DC13818ULL, 
            0x78DF7135C07A874EULL, 0xC42F01FAB2EE7765ULL, 0x77AD83B4E5AB2875ULL, 0x8F92ABBA1D25B9EEULL, 
            0x287F5637D445F75EULL, 0x5813A3DE7C44A83AULL, 0x072A53283F68557FULL, 0x5FBAF65BDC50FAFFULL, 
            0xFD6A33511479E4B0ULL, 0xD9F8E3ACCD6E7707ULL, 0xE45C6F7EDC6A9560ULL, 0x49CA4471063B6AFDULL, 
            0xBEC953F1372295FEULL, 0xC22E340DCA090EF1ULL, 0xE998E5CDB19FC19FULL, 0x6514770C2959B250ULL, 
            0x14AFC6C82ABB9120ULL, 0x9A6ECAEBCEF89332ULL, 0xB1CBA562F611A478ULL, 0x01C6940EF28028A5ULL, 
            0xA9A255B25224A120ULL, 0x8E9B19B9FB56A03DULL, 0xEE8260EFC2388A13ULL, 0x136F479693CA073DULL
        },
        {
            0xEE49549A1D651FA7ULL, 0xE149D8326629EF92ULL, 0x52BBCB82028D4C19ULL, 0x0D3C72DF094B3DE0ULL, 
            0x723DCE6E9C3FE71FULL, 0x43809C8677B98744ULL, 0x02BE4DA21BBB6EB0ULL, 0xC85D1CE13911A72DULL, 
            0x9856F9D466893254ULL, 0xD98A1BA00C2C88B3ULL, 0x14F086EE2ACBFFE3ULL, 0xC949B540E6224F61ULL, 
            0x3927B3A78DE617DBULL, 0xDA137AB1A07CEC38ULL, 0x237858C0F9F44D0FULL, 0x03C5DBD96C50AB8AULL, 
            0x9C04C3E470811D84ULL, 0x717BFA4A99F80F7EULL, 0xB0C150C864CEC0E6ULL, 0x1DB827CD58689A69ULL, 
            0x9B6DD03E37CD1BCCULL, 0x7F727B1E39157B69ULL, 0x6F6FD07E6F11451EULL, 0x914E7FDC38F1922BULL, 
            0x4D904AD5831823D0ULL, 0x1B60F6C196C44EA1ULL, 0x9B4A34088CC40D97ULL, 0xB11FA44EC6BF5630ULL, 
            0x54094BBE16C7CF58ULL, 0x3AC14BD1196DE47BULL, 0xB558838F653A46F1ULL, 0x5163D16AAB2FA688ULL
        },
        {
            0xDA963F0B559B57D8ULL, 0x8446A17DF6E8598FULL, 0x430BDC449E9D305FULL, 0x419059FFB8A18D73ULL, 
            0xCC03C240B2D99CA9ULL, 0x20400AAA08A128E2ULL, 0xCAD33F03F61742C5ULL, 0x73F1A204B20C9114ULL, 
            0x0D267F512B6F7943ULL, 0x82DB3E1D1FEF6681ULL, 0x9D7C52F0C647261AULL, 0xD6178B24C3FB0948ULL, 
            0x7BAD5F53BFDB131CULL, 0xF4E631BF4CAFFAA1ULL, 0x1DEB2791A3D179EFULL, 0xB776EF9BAF83DD21ULL, 
            0x68AC38C81F8DCC17ULL, 0x80748FFFC7C15BACULL, 0x6F5A8AFF8B23C08AULL, 0xF615FA23B398E72FULL, 
            0xBAFB1313A5926BB9ULL, 0x2BCF4A431A8E778BULL, 0x9442C6D86B10AC2EULL, 0xA269943DE218997AULL, 
            0x8D24697DD3C6CBA6ULL, 0x176B2A7EAF5BF2EFULL, 0x9381C51E6F7A1D44ULL, 0x6B5D79CDFB3005BEULL, 
            0xED8371F3A543F3FEULL, 0x8156431F487DD43BULL, 0x33EBEC7CECACF6EFULL, 0x25813C485DE0465EULL
        },
        {
            0x99835D4A4E8FAE55ULL, 0x3B2496ACF96AC575ULL, 0xDF12B9F2673B282EULL, 0x75955D18F084B0FFULL, 
            0x928B51E46ED91A03ULL, 0x59A7DD37609D500BULL, 0x237EE93F1F11E31EULL, 0x5637F1EF4F8057D6ULL, 
            0xA3910AEDED82509DULL, 0xB35DFB8F7C6C2513ULL, 0x7590DF5AAF9F6166ULL, 0x3641C80A71F1AC2BULL, 
            0xED1FAA84E9DF4C21ULL, 0xAA22F18CEAAD006AULL, 0x76CBA684C5384CAAULL, 0xC5AC2F525BFEC98CULL, 
            0xCEF6D101769E268EULL, 0xA1484C10ABD26F04ULL, 0x80632B0565287F3DULL, 0xC4A5C3AA25C5F5B7ULL, 
            0x1379E59E23A399F6ULL, 0xD3AA797F142783FAULL, 0x2A197813202D3BA6ULL, 0x91120751DA4876D8ULL, 
            0xFDD43078097F2303ULL, 0x721C2ED94A002D44ULL, 0x98BABB05015EA2FFULL, 0x44E92E884F68A03BULL, 
            0xCF5F8B5B9ED46D7EULL, 0x4D1B70F91229E0D9ULL, 0x950D29992AD18552ULL, 0x9BF9D8AF128933FDULL
        },
        {
            0xB7775790A1202320ULL, 0x1177E31C908BE7E6ULL, 0x313118213FE668E3ULL, 0x1CE7FC42DC816760ULL, 
            0x6536E4636B80DE16ULL, 0xAE2440B03352CCB1ULL, 0x989BCBD71A0D745EULL, 0x5E91F54DEC86B426ULL, 
            0x3758DA57F72E8D7DULL, 0x7A880E087CF8D0BDULL, 0x6FF928B8F6858307ULL, 0xAE2908C1DD4DB5DBULL, 
            0x98AC1899F3F2E7E3ULL, 0x0DF24355F5C12765ULL, 0x7AE5FDED01655B4EULL, 0x969F13C23B86D0D7ULL, 
            0x342B67BACD16722EULL, 0x0A9F7C67E2563C53ULL, 0x17FBF46A0239268AULL, 0xA28C808D00990C8DULL, 
            0x405A35EA54331ECFULL, 0x010343C702BF4DBCULL, 0x10685E6D55FAB94CULL, 0x0A045C0C8B018FF7ULL, 
            0x5EA86962234D5333ULL, 0x964BB03F88EC56B2ULL, 0x0F66519FC4C09DD6ULL, 0x2E614D85C7443800ULL, 
            0x8C0B5C787C6977B7ULL, 0x66BD1B1C051A4EC0ULL, 0xF50452C01A4EA4B3ULL, 0x27329981CE486237ULL
        }
    },
    {
        {
            0x877DDEBC796BBE3DULL, 0x8E024B027FE91A8EULL, 0xCB8CB86C1246AE9BULL, 0x97B4B8ABA20EE8C4ULL, 
            0x46E038D7C785729EULL, 0x2E51C6ECB81E0395ULL, 0xF426251D4B5C6E3EULL, 0x2A76EB9E03D7CD77ULL, 
            0xE82E3BB88D1C5648ULL, 0x3076A8B746C9239AULL, 0x200D12FF56F96E4DULL, 0x19B8AF7A31C1DCACULL, 
            0x49907E8C199115DBULL, 0x02DD80FB4AED17F3ULL, 0xD316E4E7A2B51046ULL, 0x22F5FB7257E8563AULL, 
            0x72D4C23962D7CB60ULL, 0xE6177A1DF8F39DC5ULL, 0x73F0FCA82FBFCD8CULL, 0xCA1521D36BC9034CULL, 
            0xBE8D3701AA5C2454ULL, 0x7F93C2715562C9E9ULL, 0xB45BD8003ECA430BULL, 0x020F2BE197FA687AULL, 
            0xF0E908D1F66E765FULL, 0xC764FC5DB2E014DEULL, 0xFC7A44462A1E712CULL, 0xBC10F45ACFE8715FULL, 
            0x00FCBE26A785B9F7ULL, 0xFB07F43B46888739ULL, 0x74271E76C53C2119ULL, 0x259DC2046EB1C785ULL
        },
        {
            0x01A6B0B1D1C0C0A5ULL, 0x431F50BDAB84B8A2ULL, 0x7669B17A8B1CB66CULL, 0xFE9AB4A510830C11ULL, 
            0x0CD7340673B1196DULL, 0xF4B1C8397E93B1F6ULL, 0xB46CCFEE0470545AULL, 0xE158169FE85AF214ULL, 
            0x7FC0B5F231A7EC9AULL, 0xFC6D80A1FDDB7FCEULL, 0x2862B9631EF17EFEULL, 0x82511AEF6CEE7995ULL, 
            0x07EB1A575AD62F44ULL, 0x81E5481721DB0AC3ULL, 0x43116973C26768B0ULL, 0xE8FFA778B210B6B0ULL, 
            0xE568D41A253F35F9ULL, 0x3CD216F75EECBA92ULL, 0xE66241B8917A9969ULL, 0x56555B03FB7C3137ULL, 
            0x92A541CE50A51689ULL, 0x6B4C2393A4A24CF9ULL, 0x0F614619BBEB099DULL, 0xBF82BA6E9CA10E5DULL, 
            0x743E82BC7F9B1B33ULL, 0x0665D08EA6A8EA38ULL, 0x12F928BBED7FDD69ULL, 0x85A374F9B3E989EBULL, 
            0xD6DFFF0927D27158ULL, 0x16E2757BAF85ED2BULL, 0xB5EB9ABCFAF91A36ULL, 0x067D62FEA9C1E464ULL
        },
        {
            0x72B202F562FA96F1ULL, 0x72FCE7AC22CCDF83ULL, 0xF601342E91DB2A69ULL, 0x3035485C15E1BE54ULL, 
            0xFB078F668C935DBDULL, 0x5312CB96E8F7B4FEULL, 0x8CEB79B228A05B78ULL, 0xE3852A7EC3EB3E67ULL, 
            0x7A82FBA852B2C539ULL, 0x905463F4984ACF12ULL, 0xA897E01F2F2C0E7EULL, 0x7CC9C80F1BB10FD6ULL, 
            0x5AECB7DEAC788F46ULL, 0xA59B4C5BC35E31FAULL, 0x489772B02B7292F7ULL, 0x9EEE8100FE88EA0BULL, 
            0xFD029E91E1E94A60ULL, 0x0E8F038DFEE03EE9ULL, 0xD770A5DDE4728685ULL, 0x942AFD894EF0C18EULL, 
            0xE6247853D13B6CB4ULL, 0x7058BDD81E23B956ULL, 0x42D6B74F8CEC68B1ULL, 0xDCEE703008A1FA1BULL, 
            0xEA5310DAD7E64FB7ULL, 0xD250592E8B99CA7FULL, 0x9E9AC065934D4C92ULL, 0x10945D552E387BCCULL, 
            0xA1625A7FC3AD675CULL, 0x6052BA713307BB23ULL, 0x0BEC416A0416279AULL, 0xC8285C01D744185DULL
        },
        {
            0x7EADAFFE46D48A05ULL, 0xB64415146412D515ULL, 0xD2E8936AE29A7DB3ULL, 0xB8342CCF3C005F3CULL, 
            0xA9041937BBDAEE19ULL, 0x8EBC2D9E34D10541ULL, 0x26E89FC382891F7BULL, 0xE2696AC992EBD898ULL, 
            0x4CD01501C87929BEULL, 0x9388E1AD3E8DD657ULL, 0xBA556163350673AAULL, 0x1CB109215E462D92ULL, 
            0x2A8B77F57DA7DF89ULL, 0x0630263379146FE1ULL, 0xB7903DB787B42DC1ULL, 0x846FA58F83F5B825ULL, 
            0x7510665B1AD696BBULL, 0x9DCEF507A089095CULL, 0x0D54977271F82FCBULL, 0xFC21389A4D4CA98DULL, 
            0x2782C4F9B98222D7ULL, 0x5A3A228034484D5FULL, 0xB59B39142B7B061AULL, 0xE8E4A1EFFC6C375FULL, 
            0xAC344A1D30BF8F4BULL, 0x042187E429220554ULL, 0xDB79873A5B20CFC0ULL, 0x738E40EFD4568FC4ULL, 
            0x311D4E018A0B58A2ULL, 0xFD804C201E98622BULL, 0x92EC13D0BC1D3E71ULL, 0x79CABE9E7A38F39BULL
        },
        {
            0xD4D7C99FF98AF6D4ULL, 0x0048FE9AE0D28142ULL, 0xC47702FE38CA1B3EULL, 0x9AFB46D2DC9E7A33ULL, 
            0x14F74CD98AC9FB31ULL, 0x1DA89C24B4438C4DULL, 0x659695CF487A50DFULL, 0x462EA20273E50E8AULL, 
            0xC3BEEE65120C04B6ULL, 0x7BD4A5AB680A9376ULL, 0x868403314A28CE25ULL, 0x51F80BA950FF8589ULL, 
            0x401F806639886983ULL, 0x4EBE660D6939F911ULL, 0x85A8FEB2C654340CULL, 0x91E1A37B2165EA68ULL, 
            0xAE20B405D2E430F4ULL, 0x6266A60BF8FC405CULL, 0xE7C60C68FB8E447CULL, 0xFFCE092D37D55391ULL, 
            0x5628FABF8E1C87A2ULL, 0x26C004F726D799DDULL, 0x6560B94FD4C62D4DULL, 0xE1929AEBC64CBDB3ULL, 
            0x5EE8EDCA37448165ULL, 0xEF7ACCFBE56D3CE5ULL, 0xDEC5E25CD5851E80ULL, 0xE570ACC9ABB8EDC4ULL, 
            0x17CBAA05CEA8BC17ULL, 0xE6C2EE9664E2A692ULL, 0xD0AD72D4E24924DDULL, 0xEBB5ACD1A0692266ULL
        },
        {
            0xCE9BFF0676594E5FULL, 0x230BD147559D3D12ULL, 0x916AFAC501182835ULL, 0x7D884781E709F5A9ULL, 
            0x7D3F450499024AAFULL, 0x5E6DF0E40E1FBC71ULL, 0x29FD15B97CA3A3CBULL, 0x0C5A1727F7FBF1B1ULL, 
            0x0CEC7A2661CE0164ULL, 0x644030754CB502CFULL, 0x8F149C5FFB3C4FEAULL, 0xE593DB9CBBAD7C37ULL, 
            0x75DCD8F4FC35DBFFULL, 0xA5DCE48F3C85ECD4ULL, 0x3460E922B3140E26ULL, 0x265F22F70FA0A3CEULL, 
            0x5F95393898F983B3ULL, 0xB99AF7BCFC7C90D2ULL, 0x06C4A5A444FE1B62ULL, 0x2A7AAE92CF4AC9F2ULL, 
            0x4A70122B88AB7EF3ULL, 0x27B7ADE6C79693B1ULL, 0x8FADA302D111C564ULL, 0xF778A1230FECF4C4ULL, 
            0x502EDB563B563213ULL, 0x7870AE48FD233545ULL, 0xDA0441F2DD9DA642ULL, 0xB53D77131FBBF274ULL, 
            0x070E3C2181E5565EULL, 0x0987E6C614362A20ULL, 0xCBA37C8C1F53DF5EULL, 0xBA629989D959FF79ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kTwistConstants = {
    0x6DC285420038B26BULL,
    0x342FD812B34517FDULL,
    0x469E8FA387EB6C09ULL,
    0x6DC285420038B26BULL,
    0x342FD812B34517FDULL,
    0x469E8FA387EB6C09ULL,
    0x0D1FC1BCFEA2F499ULL,
    0x74760B19131A7F1FULL,
    0x70,
    0xFD,
    0x10,
    0xCB,
    0xF7,
    0x70,
    0x19,
    0xE0
};

