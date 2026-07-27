#include "TwistExpander_Sirius.hpp"
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

TwistExpander_Sirius::TwistExpander_Sirius()
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

void TwistExpander_Sirius::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBE6BA20B24E62141ULL; std::uint64_t aIngress = 0x9AC4B96C7650701BULL; std::uint64_t aCarry = 0x888BED63C87686AAULL;

    std::uint64_t aWandererA = 0xF6DF497469994963ULL; std::uint64_t aWandererB = 0xF25213FB3220BE2CULL; std::uint64_t aWandererC = 0xF8EA3A8F27DD5892ULL; std::uint64_t aWandererD = 0xDBC2306BB4070CC7ULL;
    std::uint64_t aWandererE = 0xC54C9B1996857BBCULL; std::uint64_t aWandererF = 0xDE05773E1743E676ULL; std::uint64_t aWandererG = 0xA44CDFF13622CACBULL; std::uint64_t aWandererH = 0xBA0D30DE38B79F11ULL;
    std::uint64_t aWandererI = 0xBDA0962CEBF78636ULL; std::uint64_t aWandererJ = 0xA2E46C7B28E6C253ULL; std::uint64_t aWandererK = 0xF26C8948CFAED5F9ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x84EF84FFA7327617ULL;
        aCarry = 0x8428C4B5F8679253ULL;
        aWandererA = 0x9086D7EFC2DFF58AULL;
        aWandererB = 0x98765603C5C1B53BULL;
        aWandererC = 0x8F53273A8F507B79ULL;
        aWandererD = 0xAF88256A6822262CULL;
        aWandererE = 0xD3846DCEFF9D1966ULL;
        aWandererF = 0xB13285C4CC61A01BULL;
        aWandererG = 0xBB6372049C9B4AA4ULL;
        aWandererH = 0xE3170ECBE5487566ULL;
        aWandererI = 0x87BD51651A1327DCULL;
        aWandererJ = 0xC0B25495C291B54FULL;
        aWandererK = 0xAC85F99068AFF686ULL;
    TwistExpander_Sirius_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAB3C66D5DE6C9983ULL; std::uint64_t aIngress = 0x9440FD081FC8BE47ULL; std::uint64_t aCarry = 0xA1E8FD5AB5C80366ULL;

    std::uint64_t aWandererA = 0xF16FFD6BFF92F52EULL; std::uint64_t aWandererB = 0xDDAAB6795E8473B5ULL; std::uint64_t aWandererC = 0xA5597C66379F91CDULL; std::uint64_t aWandererD = 0x8DDA89D63C870384ULL;
    std::uint64_t aWandererE = 0xE5EB6DFDED2D84F5ULL; std::uint64_t aWandererF = 0xF13DC77AB4E2624BULL; std::uint64_t aWandererG = 0x93DB4AB0F65D61C4ULL; std::uint64_t aWandererH = 0xA0EB583130DD5DAEULL;
    std::uint64_t aWandererI = 0xB45E410A359225E6ULL; std::uint64_t aWandererJ = 0x96734614E5C1D41DULL; std::uint64_t aWandererK = 0xF6F18BBD11981291ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF3F3E1F40AC417ABULL;
        aCarry = 0xADE7FFFC855C7FA3ULL;
        aWandererA = 0xE0978A7375DE44CBULL;
        aWandererB = 0xAC9C72E2A77E8DF9ULL;
        aWandererC = 0xAB5E7EABB05C5511ULL;
        aWandererD = 0x91F9DB8E503B698EULL;
        aWandererE = 0xBA42503856CA7035ULL;
        aWandererF = 0xDB51F22CBB7587C6ULL;
        aWandererG = 0xE0A4508D2E577EDDULL;
        aWandererH = 0x96B4F6B269FA8D88ULL;
        aWandererI = 0x92CB3C0C55C098ACULL;
        aWandererJ = 0xBC766AE014FAEA9CULL;
        aWandererK = 0xDB52CB34CDC0ABB5ULL;
    TwistExpander_Sirius_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFE90539CF75B4856ULL; std::uint64_t aIngress = 0xB8A49266EE2DCD86ULL; std::uint64_t aCarry = 0xB04DED4663DB076FULL;

    std::uint64_t aWandererA = 0x826AA3A369409491ULL; std::uint64_t aWandererB = 0xD2CC7BEC5ED101A1ULL; std::uint64_t aWandererC = 0xB9000EC0F56C3244ULL; std::uint64_t aWandererD = 0xE487A200AEADE987ULL;
    std::uint64_t aWandererE = 0xBFDAFE6B82585DB2ULL; std::uint64_t aWandererF = 0xE0B7333C1E0A278AULL; std::uint64_t aWandererG = 0xC99A4B7A2205D76CULL; std::uint64_t aWandererH = 0xF1146FD31A3BFFD5ULL;
    std::uint64_t aWandererI = 0xDDBF056CBBC45059ULL; std::uint64_t aWandererJ = 0xA68505F52AAC3165ULL; std::uint64_t aWandererK = 0xB7A611CD0132E144ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x844E27B95945226EULL;
        aCarry = 0xD7211503799AF883ULL;
        aWandererA = 0xCDAACD617277C068ULL;
        aWandererB = 0x874A59B1FE261CBFULL;
        aWandererC = 0xE85E44555A25D050ULL;
        aWandererD = 0xC3BD452F5394A60BULL;
        aWandererE = 0xC9CBB5C4DCFE5515ULL;
        aWandererF = 0xE958761FB0D30B8DULL;
        aWandererG = 0xA0D1AADB2AFC40D3ULL;
        aWandererH = 0xB9058E0D8E6A5AC3ULL;
        aWandererI = 0xBC31164C11717CF5ULL;
        aWandererJ = 0xBEED817746ED5014ULL;
        aWandererK = 0xC351F8728FE30DFBULL;
    TwistExpander_Sirius_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAB9AF16FA2E936E5ULL; std::uint64_t aIngress = 0xEE6E182450304389ULL; std::uint64_t aCarry = 0xBC9F514EEBFD9F94ULL;

    std::uint64_t aWandererA = 0x915CFA113D090136ULL; std::uint64_t aWandererB = 0xDC790F6A68BB74BBULL; std::uint64_t aWandererC = 0xADF04A8FDCFA9E1CULL; std::uint64_t aWandererD = 0xDA166C9CA69AC44EULL;
    std::uint64_t aWandererE = 0xE0CE71494BE13FC7ULL; std::uint64_t aWandererF = 0xD42E205CA2300378ULL; std::uint64_t aWandererG = 0x9BBB7695CA4A3D11ULL; std::uint64_t aWandererH = 0xF9C2C2A3E34E00C8ULL;
    std::uint64_t aWandererI = 0xCBBD6685978DA194ULL; std::uint64_t aWandererJ = 0xE7F26C8771380EFEULL; std::uint64_t aWandererK = 0xCB468189780DBC14ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEAB6A7C85440C312ULL;
        aCarry = 0xC42B1923A4CAC628ULL;
        aWandererA = 0xFAAE82AF2712F8F3ULL;
        aWandererB = 0x92650262D3B144A2ULL;
        aWandererC = 0x9AB3052859881332ULL;
        aWandererD = 0x9349D16485697C82ULL;
        aWandererE = 0xCDDA5A37A81B8A3BULL;
        aWandererF = 0xD6AE2042DC9D3830ULL;
        aWandererG = 0xC54924C2922DF6A1ULL;
        aWandererH = 0xD7461B41BF14A223ULL;
        aWandererI = 0xC58067B7EEFE3A72ULL;
        aWandererJ = 0x83763CEAB9CC9F52ULL;
        aWandererK = 0xDEA928E6849D9509ULL;
    TwistExpander_Sirius_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Sirius::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x86C7DA44E3FC8745ULL;
    std::uint64_t aIngress = 0xA1E86E0A9A2F6D86ULL;
    std::uint64_t aCarry = 0xA2D023E55552F5C2ULL;

    std::uint64_t aWandererA = 0xC772446F886FFD98ULL;
    std::uint64_t aWandererB = 0xE9DDB941EDA7DF26ULL;
    std::uint64_t aWandererC = 0xF46A66879E078163ULL;
    std::uint64_t aWandererD = 0xE2FB17048836105EULL;
    std::uint64_t aWandererE = 0xCA940A47930FABE5ULL;
    std::uint64_t aWandererF = 0xAB6575874F395FFBULL;
    std::uint64_t aWandererG = 0x8E41934F003A55F2ULL;
    std::uint64_t aWandererH = 0x8D71B92F50E64956ULL;
    std::uint64_t aWandererI = 0x9B0E3F7675A72F4AULL;
    std::uint64_t aWandererJ = 0xEFE68B7D4A4CE523ULL;
    std::uint64_t aWandererK = 0x89636B01B0C1DB72ULL;

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
    TwistExpander_Sirius_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KEY(pWorkSpace,
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

void TwistExpander_Sirius::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB72E446E8CF6A7E9ULL; std::uint64_t aIngress = 0xBCF75C0B02A0C5FAULL; std::uint64_t aCarry = 0x8412BB8BD8793E1EULL;

    std::uint64_t aWandererA = 0xD7FE9CEF23EE4CA2ULL; std::uint64_t aWandererB = 0x8B9F33660B7D04BAULL; std::uint64_t aWandererC = 0x8B2449E69EE86E9EULL; std::uint64_t aWandererD = 0x89F9D319F003F831ULL;
    std::uint64_t aWandererE = 0xAF35BD4DEC18D53AULL; std::uint64_t aWandererF = 0x981FEE85D3F0B282ULL; std::uint64_t aWandererG = 0xE0E578EC4E5D6BFFULL; std::uint64_t aWandererH = 0x9342B9537FC43728ULL;
    std::uint64_t aWandererI = 0xB431B3D2C29E42CDULL; std::uint64_t aWandererJ = 0xDF7BDF9D53B93139ULL; std::uint64_t aWandererK = 0x99963A6C33ADCBAAULL;

    // [twist]
        aPrevious = 0xBFD21B53DCD21DC3ULL;
        aCarry = 0xCC4B633E73FB497CULL;
        aWandererA = 0xBBC3141D1B63D5FEULL;
        aWandererB = 0xB5BCFC2F42F4883DULL;
        aWandererC = 0xE93FB0575244C06EULL;
        aWandererD = 0x87234BAAF21161FBULL;
        aWandererE = 0xAA5573F01E6B06C7ULL;
        aWandererF = 0xD9789B6A2EBBDAC4ULL;
        aWandererG = 0xC2879D53C330BBBDULL;
        aWandererH = 0xBE20181A0777165CULL;
        aWandererI = 0xFBFBAB905DA4891DULL;
        aWandererJ = 0xE7A82483F8638C1BULL;
        aWandererK = 0x80C1064F454A6E9EULL;
    TwistExpander_Sirius_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Sirius::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Sirius::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Sirius::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 31 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 15815
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1510U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 31 of 33
    // Exploration cases: 0
    // Structural maximin 503 / 674; family total 15812
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
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
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 31 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1042 / 1248; total 32216
void TwistExpander_Sirius::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 295U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 31 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1043 / 1248; total 32219
void TwistExpander_Sirius::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
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
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 656U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
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
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Sirius::kKeyRotateSalts = {
    {
        {
            0xB153D84F8C2908F7ULL, 0xE708E975F3F4485EULL, 0xA7F71315C1FEB0B2ULL, 0xD3A0D905E388BB84ULL, 
            0xAB5E287FA8DD8DE9ULL, 0x9C13566A85A72081ULL, 0x2CE419CE9CA69FD1ULL, 0xA0A232D24B75F36DULL, 
            0xEF7FA627097977DDULL, 0xB40FAD1842955D34ULL, 0xF80DB7669E735B3EULL, 0x114603F3665C147BULL, 
            0x7F0ABF8F91699664ULL, 0x66D07AED42D51E31ULL, 0x05D56415C2BFD5A1ULL, 0x6C1C2FABA1BE113EULL, 
            0xCAD3BBCCE725886BULL, 0x1517545A53BD0268ULL, 0xC81C5F0BC49D3218ULL, 0xDCDE5C3FC551A428ULL, 
            0x10AE879D730299FBULL, 0x99578E4771B7F650ULL, 0x48B073C445BAA7CDULL, 0x9137E9865E9107E8ULL, 
            0x860B22A63BAE1141ULL, 0x5A405C2A2C12F314ULL, 0x0E237DF186ACE729ULL, 0x6EC2B957B0372091ULL, 
            0xB2B210DAB39BFE98ULL, 0x33DF9ED5E44FC384ULL, 0x1392FE6B76DF20FDULL, 0x28AC21C8D8DA9464ULL
        },
        {
            0x7058732A18CF739BULL, 0x4EA6ECD600503E1CULL, 0xA86F9A11A85F584FULL, 0xEFB3B1C21C9FDCCDULL, 
            0xA80502B5526AEE1CULL, 0x53A477726436257EULL, 0x768FDED4B4FDDB9BULL, 0xFA08FFED033FA026ULL, 
            0x433917D2A42B4948ULL, 0xFAEB3509F9CC093DULL, 0x00B3FE8511893AFBULL, 0xDC3FB9084E65B6A3ULL, 
            0x7DC1145FCFF7B7C7ULL, 0xC33DACA34F81581AULL, 0xD502E10340343FA9ULL, 0xC852852BC551BCEAULL, 
            0x7389C3E4F4F46530ULL, 0x45183199A39AE0D4ULL, 0xCEC93586C36062B9ULL, 0x7F7F4E7CC5F4F42FULL, 
            0x7EACB999D1658BE3ULL, 0xD1C71F44ECB2E805ULL, 0xD906D266CD0F346CULL, 0xE39EF4CCB37B8D87ULL, 
            0x14266FB774690A3DULL, 0xC6E5B97E06C4F4C2ULL, 0x60B31016FB0848EAULL, 0xB5D97DA2B5BF6EDBULL, 
            0x4AFD770DCF823B21ULL, 0x643424210449A0CEULL, 0x1668F37A13FEFDF7ULL, 0xDD177CDD0B5824EAULL
        },
        {
            0x6D7975DA9DA9D98EULL, 0x3F4A497FB1D41D47ULL, 0xD6238542FD372674ULL, 0xC38404CA4E699461ULL, 
            0x00A86EEFE50FF8FDULL, 0xCC1B09C9EF96F4F8ULL, 0x10314A01FF6EB4F2ULL, 0x6BD242640404A7FFULL, 
            0xEDFD4A429E0DE71BULL, 0x0BF796988FC00C45ULL, 0xC56E2F4A3FAC30B0ULL, 0x58721D9101BC464DULL, 
            0x49080412002B5664ULL, 0x713EEDC92257CD66ULL, 0x0DAF96EF92653F8CULL, 0xCDF637FE5F078F61ULL, 
            0xF0B1093B1541F47FULL, 0x258A030164E13A53ULL, 0x601672E5A5229607ULL, 0x7C39100E7E499352ULL, 
            0x8A5C6F2798F606A7ULL, 0x8BCD74E3B1033004ULL, 0x98ECCFBEB7C3A1E7ULL, 0x3E76F2CE1648FF46ULL, 
            0xBE4BDB2DFA49A7A2ULL, 0xAC7C5B96541FD775ULL, 0x8E371FCCBF2C9608ULL, 0xB67B5B2FC0B96B88ULL, 
            0x3476AC5FD7CC586FULL, 0x20BB2B68F25C1C72ULL, 0x53B70AC1D4E1239FULL, 0x0C1A1F8EC34C9E3BULL
        },
        {
            0x81625BDA1AFA0FFCULL, 0x09E881342F6AC1E9ULL, 0xB9D6C852D8A91879ULL, 0x8FAB5FE5C4794AA9ULL, 
            0x46E27D61D521D63EULL, 0xBD3F54953B0BABC8ULL, 0x9E9FBE389E60C218ULL, 0xADE7782E1D76674BULL, 
            0x4ED855D58978012AULL, 0x61448ABFFE9970DAULL, 0x4BB5AE65AB5AC325ULL, 0xD9F98FB6543297FEULL, 
            0x76207AB55A4772BEULL, 0x156CDD3F691AD922ULL, 0x90C90141A57E4FEAULL, 0x079E4461E39DD5C2ULL, 
            0x22261361164A86A0ULL, 0x6424EC436D255DDAULL, 0x2FC0B333C9452B8AULL, 0x5C72AFDE2B58093CULL, 
            0xA06A415AF73901B9ULL, 0xD0332536F85D51ECULL, 0xA571C03A3192A251ULL, 0x6FD5F6E12AFFD6EBULL, 
            0x5B7C2EC92C4FCEE0ULL, 0x6DC1444BF4845DDDULL, 0xA2304302E917EE21ULL, 0x551038E3DEECDA49ULL, 
            0xDD41DD626CBB564AULL, 0xDA003E780F7EF50EULL, 0x9328FAE4BA88FB90ULL, 0xFA8674615083B524ULL
        },
        {
            0xCC0C496BD59C9E8CULL, 0xF04CE191F0017FD6ULL, 0xAC08010BA2823F15ULL, 0xDDDA3DF09A3C488AULL, 
            0x6880B49ECC581C10ULL, 0x8F2A5AFB3F22084AULL, 0x30B74AFDAE6C48CFULL, 0x61BE1CAE3A6FF5F7ULL, 
            0x3F4338FCC57935BEULL, 0x092D47955FC340B8ULL, 0x6DBF85A86BC0CACAULL, 0x08C13512D3A039ACULL, 
            0x7A303ACB62D4EB3EULL, 0x5354EAA4DEB95B96ULL, 0x66FDFF110E7A2BCDULL, 0x0CADBFE8939B0942ULL, 
            0x85D01925F730FCE3ULL, 0x1E72C68062559569ULL, 0xAEB7E839EB4C8493ULL, 0xF993DE1F747D9859ULL, 
            0xFC4D917C197A108BULL, 0x3F0A6ADC40A03527ULL, 0x506470BCB52032E4ULL, 0x3646B8442F70B1ADULL, 
            0x4B7D6B012138D755ULL, 0x8A5E15B52EFB11FBULL, 0x6157F74E4B60D5FFULL, 0xF6FB8A096CA1D29FULL, 
            0xD81CB59B33C1EA90ULL, 0x994AFCBB83ACDA3DULL, 0x3CF98032767BD371ULL, 0xFE854EA3CAB1896AULL
        },
        {
            0xACEEAFCB0065938EULL, 0xBD3DEEDF65046567ULL, 0xC1E9118EB7869622ULL, 0xFD89C6858CC75F8CULL, 
            0xFCBE1000FE4C6003ULL, 0x06BE1D214E524C82ULL, 0xA034A8FE17612414ULL, 0x83354041B919523FULL, 
            0xAE7D1C487769EA67ULL, 0xE4EEC245CBD01317ULL, 0x52CF033B3CF72AAFULL, 0xB995F7563E0CDC30ULL, 
            0x0393698C767DBDA6ULL, 0x51266200D3FEBC9DULL, 0xF08CE374ADA7C4B6ULL, 0xBD9F2D150224AC4AULL, 
            0x9219F704007571C1ULL, 0x4F216D918CC5289EULL, 0x621D79C20C302818ULL, 0x0EAA8BD179DF9F6BULL, 
            0x2ABBD542591D9C94ULL, 0xB644DEA0D0E4DD8DULL, 0xCC9F0D33DAED18FEULL, 0x875476EE958C9E2BULL, 
            0xCDC51186C672F388ULL, 0x9B6CCC45495516ADULL, 0x760BBF3D36C71E30ULL, 0x19B1C4CF71F364A5ULL, 
            0xA1634F5A6C9C49DBULL, 0x4FE83001319337E7ULL, 0x9F7D0D368DA41DD2ULL, 0xDE0825D773DCCA8EULL
        }
    },
    {
        {
            0x554CEC3BEC23AA99ULL, 0x5434ED3EBC23255CULL, 0xDEE26E201AAC3B76ULL, 0xF6E07FE57D0253A8ULL, 
            0x25C5C4CD0550503AULL, 0x1772579A5B04550FULL, 0x31B33E3E6DD97F99ULL, 0x24CCDD59863364EFULL, 
            0x46844ABE7C87CFF9ULL, 0x630E7D24B398AD08ULL, 0x35BDF8F61AEB7290ULL, 0x5A0E5BBA1A2D2DAEULL, 
            0xB4788A42056FAAF1ULL, 0xBC0A5B6FC1938606ULL, 0x7755398F71581E96ULL, 0xA77914AD4D88601AULL, 
            0x4F59413F27F8A077ULL, 0x478F523AEE1C1DA3ULL, 0x110DDC65B28856EEULL, 0x7444D80978C61E16ULL, 
            0x3125942DCB8D2150ULL, 0x5724536C89B0E085ULL, 0x174E04480C9F98D2ULL, 0x218B1736995C18B0ULL, 
            0xA5EFEF1661282BBAULL, 0xC57AA3D87E3A6BABULL, 0x284A366D09EC9689ULL, 0xE044863408D9132EULL, 
            0x86229D587C38E4BFULL, 0xE99EC7B5937A469DULL, 0xBA56A117A8E4F070ULL, 0xCA14B64B8CD419DBULL
        },
        {
            0x531509F1B213D068ULL, 0x393138BE97F34F15ULL, 0x7D3F7BE403239BBAULL, 0x08EE4A2F98BA59DFULL, 
            0x7FECB4C60E6C049FULL, 0x459032E5F75DBB4CULL, 0xF53EACC80C468FDFULL, 0xD550C8CA259A1DA8ULL, 
            0x81DBEE5ACB6C7F7EULL, 0xD9C8775E2A3314A6ULL, 0xFCCEEC01265B624AULL, 0xC30F9360A2359DD1ULL, 
            0xB02ADFF53B4F80ABULL, 0x783FB35A072F7A4CULL, 0xEFC76925F9AAE8A8ULL, 0xB4494F350F578336ULL, 
            0x85CB8C82960BC2C0ULL, 0x47A21C8A13D42F22ULL, 0x94346608101C2AC2ULL, 0xC2B8EAC4D2C2A887ULL, 
            0xBF980E7CEAA22968ULL, 0x593DF13419D62612ULL, 0x226C0FA5E1B29A83ULL, 0xADD9AB23F4099FCAULL, 
            0xB16F0C92C517B69CULL, 0x956A833D343BC9D9ULL, 0x72E56097E1F0C30FULL, 0x6DF2FC30E4588B99ULL, 
            0x93657D943EB870B7ULL, 0x820E93D5A25BC266ULL, 0xED3B615BC6BB15BAULL, 0x70DBC245CFACA98CULL
        },
        {
            0xF05A36278753D1A6ULL, 0xADCE8EEB42D2AF75ULL, 0x0EAAC7487035224AULL, 0xED254B6BEB241013ULL, 
            0x66DF053C165A8366ULL, 0x03140B6CE628FC0DULL, 0xF12F5B390E289829ULL, 0xB94CFF0C93587426ULL, 
            0xCAB93626F4FF6FB4ULL, 0xD355CB8515C51499ULL, 0xBB62B9BFED36C066ULL, 0x668707BD0E8F3F3EULL, 
            0x4120475EB629287AULL, 0x0E47A4138D2B61B6ULL, 0x45DC2AFD2CCD6406ULL, 0x06F5D0AFEFC22C94ULL, 
            0x50CD45B2A2CF3774ULL, 0xABEA83FFA51F5A73ULL, 0x8292075FCF128788ULL, 0xB20048E3B391271FULL, 
            0xBDE008FA0CB6C0A5ULL, 0x7173BAE21A93083DULL, 0xEE8BA75F8C050DB8ULL, 0xB0B8E221CF456355ULL, 
            0xCA9E4431CE9082FDULL, 0xE8C866CA4A7BE62CULL, 0x432CDC853E24B1B4ULL, 0x02DE4D03652A3C04ULL, 
            0x88C8D55A2ADAFD74ULL, 0xBECDD0D19C0B3B43ULL, 0xEA9D22BFDFCF9935ULL, 0xD245970D36CFE2DAULL
        },
        {
            0xD74A95537B234F84ULL, 0x18066C3DA076F4B0ULL, 0x29F47C6858B669BAULL, 0xE4D02512291A8C15ULL, 
            0x8106D5BAE3A06539ULL, 0xC635B7361CFDD713ULL, 0x4AB1D5A12EB13C06ULL, 0x7B188692EA15FF5CULL, 
            0x8F9D410344202DA3ULL, 0x57727CD026E88E64ULL, 0xF378126747FF9FA3ULL, 0xEA7D5C7E5651B2C6ULL, 
            0x0E587E1E1797E2E0ULL, 0x31B275E17BC7E03DULL, 0x3897B7AC03498E4CULL, 0xFD9B3C9B2660CE78ULL, 
            0x5C91C9E6E16683F5ULL, 0xCD9A4DBDBFE97DE1ULL, 0x2E8A96B3045769BAULL, 0x9B955312C626C479ULL, 
            0x4DB3A67724BC6C93ULL, 0x3A4C07218F7BB477ULL, 0xE338C25750A577AEULL, 0xA40280E6A915C0DBULL, 
            0x74601A823C3A12BAULL, 0xDA65230791F44414ULL, 0xAD5E63E2BEA2DAF5ULL, 0x260C05F63450D194ULL, 
            0x662F4210F768ADEBULL, 0x6339F70E2607DDB7ULL, 0xC86786459E2E1EC7ULL, 0x1DB73EEB7D9CA063ULL
        },
        {
            0x32E9A6AE9281F5E6ULL, 0xE158F569878AFD27ULL, 0x8FB5EC57AB70DF5CULL, 0x1CFC2BBDF76F56D1ULL, 
            0x79C4871BCF66A2DBULL, 0xBCBAA76100C4D22BULL, 0xBFB5DAFA1D06895FULL, 0x6ED3C8614FC9A54AULL, 
            0x9F1B7125D7FCE64BULL, 0xEFC611568B6D5D73ULL, 0x8F6397B2B031398AULL, 0x971D93674BAEB473ULL, 
            0xA0EA36FD000EE320ULL, 0xDD79D72D6DF41592ULL, 0x88A21535D8E80CAAULL, 0x15A5D94F5AFEC504ULL, 
            0x2C31FA73AE059840ULL, 0xCD709AE5C805DF87ULL, 0xE32F23E4D6663A75ULL, 0x92FE949188D9D66DULL, 
            0x45F3EA0947AE3D89ULL, 0x8B23D8E46AE24878ULL, 0xF03DF32D2BB32FABULL, 0xE1C9A94953A97360ULL, 
            0x5DA5ECCB356458D3ULL, 0xE71502F42E93A694ULL, 0xF987B23FD81D4229ULL, 0x4698B2AA2B27BEE5ULL, 
            0xFBD85584BE1AEBF9ULL, 0x5F98C5B69CE201BFULL, 0xD95C2AF158B43247ULL, 0xF5C79282BA259FBCULL
        },
        {
            0x885EDA645AA3C581ULL, 0xA193CCBF044AE7E1ULL, 0x725E7F4ECC4141F8ULL, 0xDE492D5A0FBE8A8BULL, 
            0x30A9269ED8FCD8CAULL, 0x6FE593EF061D70FFULL, 0xED6F3B3F4A8D59DFULL, 0xC484E6516878FBCBULL, 
            0x84E3222D0ACA455DULL, 0xAA5C2178CDC4D2F5ULL, 0x74E5F739B1D22DC9ULL, 0xD835FDEED4DC6C1DULL, 
            0x2DCB362253A4EC10ULL, 0x4AE53FCF8C95D710ULL, 0x5C32BE6D19EF66FAULL, 0x88FE5541FBE14AF5ULL, 
            0xFB9623535EF23877ULL, 0x5265536755EA7221ULL, 0x5658ACC8425055B1ULL, 0x441DF51488E1AAE4ULL, 
            0x59C8988B71EE9755ULL, 0x164695F3A32998D1ULL, 0x9FBB018783F13A63ULL, 0x779C02B394FC781EULL, 
            0x6A5FDD48AF18B4B3ULL, 0x215B35CB375508C8ULL, 0x494B791AEBE0CB4CULL, 0x611193B217E4BBDFULL, 
            0x634D1DD4B8BFD85CULL, 0xE58C534EF11A1D46ULL, 0xF43051AB457AE602ULL, 0x5813B26A2CEDD9EBULL
        }
    },
    {
        {
            0x50DF1079354D3978ULL, 0xD160FB2A1EEB9E3FULL, 0x7518DFBAB2BA9B16ULL, 0x919E13A8002CCFC5ULL, 
            0xB5412BDBF9FC0C1DULL, 0xC5BF2A0C8A368792ULL, 0x42DACF2CA5526E2EULL, 0x8634B4163A88C94BULL, 
            0xF2D1E537017743E6ULL, 0x1D1D8E5307DF1D30ULL, 0x7ECD67AB5C4D6568ULL, 0x6C2CF8E791406A41ULL, 
            0xB9D786E647136B96ULL, 0x9CDEAFEC4C203676ULL, 0xBE1C712A8D8C0B3CULL, 0xA4125BFCC22E593DULL, 
            0xAE7CC78676FBB283ULL, 0x5C5D653A688B9DC1ULL, 0x2AE14C15091A942FULL, 0xAAF726BFFEE766A1ULL, 
            0xCA4D8F89F27CE4E7ULL, 0x7A9BC64FB3886131ULL, 0x1D3DB9AE08920D93ULL, 0x6810E0F51F4EF377ULL, 
            0x931F067B01C28837ULL, 0x0710E15F66928317ULL, 0xD2B14894EEB78DF7ULL, 0xFB724024078F74C7ULL, 
            0xDFE32D0FA725A893ULL, 0xBDDF365A185CF13AULL, 0xB9E4A2F9A64E3839ULL, 0x6B5D67969D9234BDULL
        },
        {
            0x1F3E062782C95760ULL, 0xC668D640208584F7ULL, 0x35FDBA8FAA00FDFBULL, 0xDA557B35EFCC56E6ULL, 
            0x97156012E8E92A51ULL, 0x6495138F4D8B97BAULL, 0x21C2EB2B6F1BB1F6ULL, 0x7EE9419A6FB4771FULL, 
            0x3DFD7E3BDF4C5E37ULL, 0x62B934B0836DCA19ULL, 0x41076B261957FD87ULL, 0x2669917E1F5A131EULL, 
            0x6041A013E8B3B700ULL, 0x7D4EB3F11CDB2F54ULL, 0xA2B76A90D7EC8065ULL, 0x63B3C77C706B0250ULL, 
            0x576C933CE604C27AULL, 0xEDDB65CB2EEE4D91ULL, 0x35C49E3E29F1FD08ULL, 0x57CBF57FD4DCBF96ULL, 
            0x282CD43FAE9BC6D8ULL, 0xFFAB6501A49F713DULL, 0x1C2D321434D3FBC5ULL, 0xDE40436F7ACF1635ULL, 
            0x838024715F59AE89ULL, 0xBCDFC292F52B4035ULL, 0x202FEEB504907727ULL, 0x3D54EF11532B0A2BULL, 
            0x19BA8576112F9C98ULL, 0xBD13428B1B272A35ULL, 0x840571F730B2F4E7ULL, 0xDD8C3AC30FB85890ULL
        },
        {
            0x3931727D77C7BA0EULL, 0xA571EC59CE3EF618ULL, 0xE754DA6A52C47FD2ULL, 0xA34D3F802988C62FULL, 
            0xF2C4289E66E2B40EULL, 0x63625A80B4B3427BULL, 0xF3E8FB11918A8871ULL, 0x0AE7E457E49C6555ULL, 
            0x30F1E109B2565CBCULL, 0x88133F065EE40E82ULL, 0xD5E2E7E1D2DA2C72ULL, 0xB0209184A11641C7ULL, 
            0x336AAAB9C2723492ULL, 0x47B0A0F93C2B53C9ULL, 0x64B6C9BB0A9D39A3ULL, 0x2C923D3FDDED7EBCULL, 
            0xEE9EE10AA3098D65ULL, 0xA9AE44518EE9385CULL, 0xB90A8215BB710354ULL, 0xAE2639F86E91D758ULL, 
            0x75321E9472679A80ULL, 0x67ADFC591BE8A883ULL, 0x4972D66EB871CED5ULL, 0x2290E2A088746D5CULL, 
            0x562E835B132BFFDBULL, 0x8CFD525A18468A1AULL, 0x93D6987F528E1A54ULL, 0xA6ABBA54789EB7F7ULL, 
            0xC78E53D0F49281F0ULL, 0x6810E34F16AF9117ULL, 0x49E67E7F9018BCABULL, 0xEA8BDBD683A2E300ULL
        },
        {
            0xBD5E6969211A24CBULL, 0xA3A32D9E14D66C1FULL, 0x3EBF92B34A9B3967ULL, 0xF7D182AAB2F6BC9BULL, 
            0x09E70229C877F1CEULL, 0x72877F60BE0F7C3BULL, 0xF0CB9C20FC2C80BAULL, 0xC06CEFEA116AC7B6ULL, 
            0xFCC4D0B3A7CE2A1FULL, 0xDB58CD165061D7A9ULL, 0x8457AF5D396CFD44ULL, 0x83DA5DA027EE8242ULL, 
            0x3F6DBEF125AA0744ULL, 0x2E62DE1738F43D82ULL, 0xA6C667DA272A3DD0ULL, 0x0CD262687D017D7AULL, 
            0xE58EBBD9D4DE8ADAULL, 0xF5D7879D05706BF7ULL, 0x98324B3FE1431CC9ULL, 0x9DA1D58222439F94ULL, 
            0xFC6891D12FF01712ULL, 0x63511048A1BFF0D5ULL, 0x6437F768493ECCE8ULL, 0x89776E7DC3D58E1CULL, 
            0x9A335C2A440CDE12ULL, 0x94D315DE443CD3FAULL, 0xDA192C40EE9621D2ULL, 0x115C31D427BD54BBULL, 
            0x43DFF70C4F9BC481ULL, 0x5DA64AC39F5EA7A4ULL, 0xC63A0895D9307B93ULL, 0x014D9EB235A67107ULL
        },
        {
            0x25E8D8742472A918ULL, 0x3CA01084F66FFC54ULL, 0x3BDB84BB732F9F9AULL, 0x1598AB79A98AA710ULL, 
            0x3FDAA02F3B7C2669ULL, 0xB076E057463ABB9FULL, 0xFD4D415AD1E9C478ULL, 0xFC0B7BC58E7C55ABULL, 
            0x6E3329A7A23A57ACULL, 0x82DE4E1CD39283F6ULL, 0x3F18F267ADC71011ULL, 0x9DC3A979CDD2A00BULL, 
            0x4BC213DBC06BD7F6ULL, 0x4EC0A38D95A03C44ULL, 0xA2416B49EB8CE798ULL, 0x719C3E457A18541AULL, 
            0xE816168E5CF8E816ULL, 0x37DE1437BEB5DA07ULL, 0x9FCF42D890D10285ULL, 0x8945371D6A7081DCULL, 
            0xF70AD5E967C6A716ULL, 0xD964F571DAF49319ULL, 0xA0495E556F84EE0DULL, 0xCEBBE1ABD12796D3ULL, 
            0x903D4AE0F84E2FB9ULL, 0xE6C3B031493C02A4ULL, 0x28A6CE7EF61D947CULL, 0xF2815265884EA14AULL, 
            0x7A4BF195BA5D49E9ULL, 0x09CEC80311EEDC72ULL, 0xB6AC0329149F6DEAULL, 0x6DD18EB461B7A9FDULL
        },
        {
            0xF121A4A0FE8432DCULL, 0x21E44C2F5E9ED669ULL, 0x99F2EC3BBC408148ULL, 0xCA119A5DD0D598C2ULL, 
            0x9465F6EF8ECAC037ULL, 0xE5260974551CAE18ULL, 0x0896E6D00C891E54ULL, 0x5B9585F618DFBD00ULL, 
            0x852EB34BDF6E9FA2ULL, 0xBB2CFDC3F9EE3030ULL, 0x3666B0C0E9DADD95ULL, 0xAB6533BFC68AC33BULL, 
            0x052215CCA30AA2ECULL, 0x7263E019FBA80272ULL, 0x6346D5815E01FFAAULL, 0xABEFFB7F8844AA3FULL, 
            0x87F74981E6C471A3ULL, 0x094CFB541F8129DEULL, 0x9BABC3983836A8C6ULL, 0x9C4547DB36A612FCULL, 
            0xDE8148A060BE3D56ULL, 0xBE29E070D43050B1ULL, 0x1C8DDC32D9FA1CF5ULL, 0xC075D9E4BEECA8EEULL, 
            0x930FA53ED7B19737ULL, 0x36A06BEA9A1270E9ULL, 0x5FBFE36868E0C9C3ULL, 0x8C61EC983DE5E5D5ULL, 
            0xD2A3A8D2ED74911DULL, 0x341EE4105516F547ULL, 0x706AD2D04B73D26AULL, 0x78466E8F393FC708ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeyRotateConstants = {
    0x88BDF97A722D65EBULL,
    0x9A6552560AA3A907ULL,
    0xEB8CED55440B6560ULL,
    0x88BDF97A722D65EBULL,
    0x9A6552560AA3A907ULL,
    0xEB8CED55440B6560ULL,
    0x7A04373C5F9D9CA7ULL,
    0x5E3E50755E836B39ULL,
    0x4A,
    0xCB,
    0x4F,
    0x9B,
    0xDD,
    0x71,
    0xDF,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Sirius::kKeySpawnSalts = {
    {
        {
            0xC99CE47AB1D5BFFFULL, 0xE5DA04CC08FC9D2EULL, 0x36A49562EC67FD38ULL, 0x02672BCDE0E5B213ULL, 
            0x3820F298F9377D84ULL, 0xCB96C9328209FCB1ULL, 0x2804EFB4FE12BC4BULL, 0xDDE8A1DE5BBF164AULL, 
            0x4DF8E71FF56E1699ULL, 0x613E71D896047DF1ULL, 0x30511625387CC063ULL, 0x6676C1D55A33DE6CULL, 
            0x79C6E9E211F9FAD9ULL, 0x64CC6F532EC1F8EAULL, 0x6E7381D66E9C1ED1ULL, 0x7A4253731E7838A9ULL, 
            0x62D56913CEC7E5D4ULL, 0xFA8AC9E15757F6F8ULL, 0x5B6755CE6D47D8E1ULL, 0x43689DC8CB072DF2ULL, 
            0xE93EC04F2BC5F54AULL, 0x95F72DDCD59B0F99ULL, 0x028BF2443234E526ULL, 0x5E40C7984C61651DULL, 
            0xE598A026D6236B8EULL, 0xE2FDB052F5743906ULL, 0xC01FA265ED9B3F2AULL, 0x5EA1F09D4F8E09F5ULL, 
            0x5821994C9AA1B1EEULL, 0x7EA10A1D2C0A33B4ULL, 0x75572C2F8A764D4CULL, 0x9F06F7C38BF6973FULL
        },
        {
            0x2010D330B1F67F7FULL, 0xFD1033C36830F0D6ULL, 0x5E0908C65F33DC8BULL, 0x35D1F2788484F2A5ULL, 
            0x4D03BFB4EFB338C5ULL, 0xE44C09ADFE7A3B46ULL, 0x7D32D9A517C6B127ULL, 0xC35BCABF764BBCECULL, 
            0x96703CB2616CA97CULL, 0x1A4FC08215BE1AADULL, 0x0A245A151B189DFDULL, 0x178CA4C1F1EC1B70ULL, 
            0x5F57184F3935FFDAULL, 0xE2EB82460E832A6AULL, 0xF83837696C06350EULL, 0xEF523018E333369AULL, 
            0xDF366F596467B686ULL, 0x26B616E832FEE863ULL, 0xBF6356AA7D71036FULL, 0x086E5ACE10AE0EE7ULL, 
            0x723F15A0CA8E1060ULL, 0x2E2B5386EAF32339ULL, 0x0A34E1A0E7AA8BE1ULL, 0x5A191AA4933C8D2CULL, 
            0x46F857A55D68223EULL, 0x41861D3496F0F72EULL, 0x6F39EBFD2CA7C66FULL, 0x3712F5BF7C09E2CFULL, 
            0x4A3265F23477B1CCULL, 0x56E18A9B97A331C2ULL, 0x53E5E73CE20E2053ULL, 0xB5FB295E03F1A44FULL
        },
        {
            0x316C761CB0B91B36ULL, 0x2A94AB32483A6688ULL, 0x7F37DE6B55AA83C0ULL, 0xE92C61738D342C6AULL, 
            0xA12CAB23C8E66ED2ULL, 0x21A8067C25EBD9D2ULL, 0x2DF1E937C0E30117ULL, 0x3C8470A7228C6603ULL, 
            0x1BC755E02F73FAE7ULL, 0x2702D2E8E4CD3C88ULL, 0xDC5D2644EAD894D6ULL, 0x98B9F1C65DE5F7FDULL, 
            0x2EC64ABE2E9EB4CAULL, 0xB83B248D9BA7B068ULL, 0xD36F0CDC88732A4DULL, 0x6A93BC38198CF380ULL, 
            0x7CBF01277724DD33ULL, 0xF0C412756F00F800ULL, 0x03F6490A70E6D471ULL, 0x56A0BF5EBB17263DULL, 
            0xC70A7576265A3F1CULL, 0x3B48394D824A2484ULL, 0x4106C1CA4387FD8DULL, 0xC3ACFC9222127428ULL, 
            0x895BD4A533E447F2ULL, 0x052812CE162FA60DULL, 0xCCE680DE81EEC109ULL, 0x3AEA61500E3AEAC7ULL, 
            0x8B0B13B9AB97D0E2ULL, 0x7F1E29969DBE7E99ULL, 0x3593C3E31719A01BULL, 0x5188B2C0464FC314ULL
        },
        {
            0xF84600A0A23B669AULL, 0xC83BD77EF87E14E8ULL, 0x4C20767A63476E24ULL, 0xFE3BF63FF76B7308ULL, 
            0x0A1EC827B368BD58ULL, 0xEDA1FEB1D741A94EULL, 0xB8BF9C97E89222D2ULL, 0x0AACCB5DB3FB8653ULL, 
            0xA56FC9E220632C14ULL, 0x5CB91F0ECC2387D7ULL, 0xD17124E5E5868D9FULL, 0xAF779A7D54545520ULL, 
            0xB5AB9DCB8B25C9BBULL, 0x5B233C52DC664BAAULL, 0x6D8F6D11C7676187ULL, 0x303C6CB6DC986B63ULL, 
            0x64268AA41586BBF1ULL, 0x516780636E090217ULL, 0xBC302314C2FDE1A9ULL, 0xDBC0EE39602EF968ULL, 
            0x9B37A4C54B4A63BFULL, 0xD447F0A706F3E12CULL, 0x735DD8B6E845E749ULL, 0x42C01BAA70C09AFFULL, 
            0x816DD0165B0DA2C7ULL, 0x8B476D56734B0419ULL, 0x31C993817A5AC1A2ULL, 0x010C376189E2B741ULL, 
            0x7ECC18F982BD1EB1ULL, 0xF96CCB3ABFA297FEULL, 0xF0FBFDD300E9B81BULL, 0xEAAF16C5F9057938ULL
        },
        {
            0x04E05709BAC5E130ULL, 0x14C0DA746085FA6AULL, 0xE357A094087EF69FULL, 0xEBB76A54255353EBULL, 
            0x340217F0BD073AD5ULL, 0xAD3157C39C3131E0ULL, 0xCCABDB7271E713FEULL, 0x33551D03C30C25AFULL, 
            0x18431E690FE915AFULL, 0xB16CEABE75B9CBF7ULL, 0xD4479D94AAC3FE2AULL, 0xDC5681BDD0F6D581ULL, 
            0xEDE8C94B6F75BFA4ULL, 0x038E30718FFD9CD1ULL, 0x1E55B0CB9A4EEA87ULL, 0xA55C346277247D05ULL, 
            0x6D81B0B474F20777ULL, 0xE0A3DEC46109D3EFULL, 0x68ED48FC5124FCC6ULL, 0xDAB9E70EB5C10167ULL, 
            0xBCD586EE6F9FAFF3ULL, 0x54B0939C2BB649F0ULL, 0x3492A7C016033A97ULL, 0x33889E7D347E4113ULL, 
            0x795EE8FCA2689CF6ULL, 0xC1235205DD22B0BCULL, 0x98565EE8BB8E45A1ULL, 0x57B874E0A21C8B1FULL, 
            0x9CF59DA7E16127DAULL, 0xFE64756F32A0D539ULL, 0x50B7B3D19F9A9B5CULL, 0xE0F92677333F8542ULL
        },
        {
            0x287F44345D51DC1EULL, 0xD70D85C43BD404ABULL, 0x293A2F195E283D6FULL, 0xF2A7213B30AC85B8ULL, 
            0x5A65902E555F96E3ULL, 0x2F9DC4CC72DE9782ULL, 0xD8FD18EC95173C98ULL, 0x90867723A8746E39ULL, 
            0xF44BBB534EC7C9FCULL, 0x6F879FEB00E8B860ULL, 0x10A5851C2F90D07AULL, 0xA27A446FEBF28A26ULL, 
            0x0847BBE278F44528ULL, 0x4467F2C4D473B8C5ULL, 0x4B6366D78AA83202ULL, 0xB1FAAE25604D01CFULL, 
            0x8DE30355BD6A8649ULL, 0x32CFABE864BABAD4ULL, 0x357602134A07B075ULL, 0x93B1528545BDEE80ULL, 
            0xE5D44B77435EF1DBULL, 0x27B9ACA1EC6C4F42ULL, 0x521991A83E4AE257ULL, 0xEB0663E15999EC03ULL, 
            0x220665973BE2E8A3ULL, 0x54AD2C2D8D49DBE4ULL, 0x617876A15BAB867EULL, 0xF773AACB6EEDA878ULL, 
            0xCA8CA0B75D8D725BULL, 0xF69BC8E5673BCD63ULL, 0x1E432879484E072AULL, 0x668B7C5AF1BCFF37ULL
        }
    },
    {
        {
            0x4C10E40790ADBEC5ULL, 0x034715F4DE956ED0ULL, 0xB03F64123E9C1951ULL, 0xA0FBF1F10E2916E8ULL, 
            0x58895D720BBA0583ULL, 0xF9B5DADFBB2DBAFDULL, 0x2C5E12A61654328BULL, 0xC7E7778F2801AAF9ULL, 
            0xD78A22828A3A669BULL, 0x870A343FDD0BDC3CULL, 0x813687D91D648B6CULL, 0x9865399D115D9976ULL, 
            0xC65E47DE5C80013CULL, 0xEDDA6722E9B2FCD6ULL, 0x6A732BA3ECBEC6ABULL, 0x2F0104E944514B0FULL, 
            0xB2B7DFEDFD8C2317ULL, 0x3F01E6638EF20DD2ULL, 0xF63ECAB4C5A10195ULL, 0x41461EDC470BD477ULL, 
            0x8A8BE84D2F0FB840ULL, 0x515E5E361DD2CD4DULL, 0x826B745315024886ULL, 0x7A6E96C0F3C5C951ULL, 
            0xEDFF37C95FF4FF1FULL, 0xEE7779FE8C3C01F8ULL, 0x9AD18EF0DE3A1804ULL, 0xB56BA181AD4D10F7ULL, 
            0x3D71FCD60C13E957ULL, 0xC80AC85846868FA9ULL, 0x7D4B364AF4A4F94DULL, 0xC24CB365D9B6C43DULL
        },
        {
            0x85FBF94EDE4D1B89ULL, 0xD75C32BAEEF23ED8ULL, 0x6898A76914B10378ULL, 0x3FC39F98BA47C4B8ULL, 
            0x192F94C868F1C119ULL, 0x6B8A1A97428A2CE9ULL, 0xB38C32FD94449E66ULL, 0xB95960F1CFE3F10FULL, 
            0x15E6C9742F60C901ULL, 0xE847A3B484BF3327ULL, 0x1240A9A8F89782D0ULL, 0x78162BE370918CA5ULL, 
            0xD25D1DC7FA466C03ULL, 0xE7F32C2C9800AB52ULL, 0x1748B9E1666D4896ULL, 0x9326F93EAC8AB94FULL, 
            0xC58BD2E60ED32364ULL, 0x1CDF4B00BB81963FULL, 0xC236410761005E97ULL, 0xB3DBE2C60A71D8F4ULL, 
            0x469FD2282A1F64F0ULL, 0x112E26BEA23AFAC1ULL, 0x27D068CEC975C88BULL, 0x48DD46DC1D30BDA8ULL, 
            0x19A28B223BA7FB77ULL, 0x24C8FBD138ABCA89ULL, 0x50B5289F26F35463ULL, 0x480891015F2571E7ULL, 
            0xD7201D0D4CE2969EULL, 0xF872AA713C75EF70ULL, 0xF80F8E61FF1D15C6ULL, 0x74D6B3B8D5CDB487ULL
        },
        {
            0xB8B79388491F4A9BULL, 0x2B235025D7AC5BEBULL, 0x72AA22DF0C519734ULL, 0xE7FA462AE0F1C23EULL, 
            0x7E0FE2E2CC022CADULL, 0x660AD195E950F841ULL, 0xF3FFAF15CFC8CF16ULL, 0xE8A7E6035E853778ULL, 
            0x83FC63D97FD6D610ULL, 0x0ED94BDB736AFEB9ULL, 0xD1EE7A1451AB2BA9ULL, 0xFC33BF9B3B9C011FULL, 
            0xA9444C792C1E7B9CULL, 0x7845EBCA1109137FULL, 0xA943C6D518E08AA0ULL, 0x24C2ED41ADC3A5B0ULL, 
            0x2D10ACB688D62F6AULL, 0x846003D8E19EDAABULL, 0x68F8CA65A304102BULL, 0x8D912C0D456B142DULL, 
            0xC44E1EB318740CE6ULL, 0xF57595C8B95F31EEULL, 0x83CA554094CE5F4BULL, 0x543528E7146E2529ULL, 
            0xC10EDD4FD5547E73ULL, 0x246CF21582C8DEB6ULL, 0x7107E49AC4880477ULL, 0x764FB8F394C94B13ULL, 
            0x65D3AF2D64882DC3ULL, 0x75BBA4476C038464ULL, 0x9796B1F3A8E3CE1BULL, 0x7351EB3CA7D02242ULL
        },
        {
            0x9FF03E49549D916EULL, 0x46A8F811A03C020EULL, 0x97290E6A7814F014ULL, 0xA0680D2C3D549D1AULL, 
            0x4C8784A514A9486EULL, 0xE39429DE8E2CAAE0ULL, 0x57306192C3D8A84CULL, 0x04DE4AB3668DE8C7ULL, 
            0xCDF248FF4139A090ULL, 0x0DD4F0C14D30B444ULL, 0x4E7119FA0C053907ULL, 0x52DDF76CC90860F5ULL, 
            0xF5E1975BF70860CAULL, 0xA89C36E6A0AE286DULL, 0x5A7C1D9975E82D56ULL, 0x9F2123A822530DCDULL, 
            0xCD878C69A7538DD4ULL, 0xD1F7A88D43CE8F4CULL, 0x4E4117D5B6A3CB35ULL, 0x76AE7D8C9C714F47ULL, 
            0xCE3D270C4ADBB6F4ULL, 0x32C4DE1209AFD18AULL, 0xECBC80807C167B33ULL, 0xF204FCC4B8CE5AAAULL, 
            0x52927C4E3148BAF7ULL, 0x2DB7FEF4299DCF8AULL, 0xDC387DA1689D8D2CULL, 0x828DAB884914EA0CULL, 
            0x2C75BD90D35942B2ULL, 0x58950601CA6EC263ULL, 0x9062E5BED3FDE91AULL, 0x2E6ACDD637B52C82ULL
        },
        {
            0x84BA57447D9881D7ULL, 0xA1C378B50364A542ULL, 0xA7AA7196A944EBF9ULL, 0x181E307DDDA20549ULL, 
            0xE9FAD32B0D105E36ULL, 0xCB68AB50DC2AC5B9ULL, 0xD61A507CB647FF7CULL, 0xA343C618BFF1F52DULL, 
            0x8371FF0A2E72F637ULL, 0xCA7C5C2485BBE307ULL, 0x1D8C7C4C5A142B8AULL, 0x1EB5C3C23046145FULL, 
            0x87E1A6BB300D8055ULL, 0x7D69CA5C3CDAAC49ULL, 0xA52C04D0F9C68AF9ULL, 0x6F9C0AFC67D2484CULL, 
            0x015DF777DE8719C6ULL, 0x72A8BAB59E90598DULL, 0xA47E81EF14D7CD61ULL, 0x3007CC891E6743C9ULL, 
            0x183498281388AD0BULL, 0x78674CD837C6A198ULL, 0xCB7A5DCDE8D32629ULL, 0xA353E046078BC92FULL, 
            0xDEA4ADC9DDDBEC96ULL, 0x75717EB97190140BULL, 0xD082B0F2816ACBFEULL, 0x238E1D0EA7F32ABFULL, 
            0xA878C70727FEFC6AULL, 0x03E2FD76B7EDAA4BULL, 0x48B19AF18076BFB3ULL, 0x9A2C12C06ED23C08ULL
        },
        {
            0xC6C3710068FB529EULL, 0x6E247630A601679FULL, 0x72BE20643C5ED08EULL, 0xC9017063ACE613CCULL, 
            0x8F3A3CF1106E5B4CULL, 0xD17E9DD85B426A4CULL, 0xCC94A6DFFA439243ULL, 0x10EF5CC67C322089ULL, 
            0x03B8A8732BA2C138ULL, 0x6FF385566A104E94ULL, 0x869077117008D49CULL, 0x10E0E1C7C9CCB90BULL, 
            0x4F01D439AC6B87DDULL, 0xCC5431F43C28AE5FULL, 0x95D24FBDD8B96A49ULL, 0x76FF484108EA3A2AULL, 
            0x3800EBC098FB45D6ULL, 0xA3A39E3A1E823EBBULL, 0xB91883FC6BB173E2ULL, 0xEF0E73A57721F028ULL, 
            0x6A0A67444F99FA3BULL, 0x304803456A6859A2ULL, 0x2F1FB882E91A1994ULL, 0xB5BD3CDDF82C2E98ULL, 
            0xBF24D31F19BF0F60ULL, 0x0E2B76348EDD61E0ULL, 0x2C7A395A2954EF40ULL, 0x26B09DDF1831F933ULL, 
            0x894B4B7ABBAE615EULL, 0xE58C6DF19E7410EFULL, 0xD8645A2E9EF327C5ULL, 0x63E3E67721103326ULL
        }
    },
    {
        {
            0xAA6601B562B74585ULL, 0xE68C73190A090484ULL, 0xD227AD71C2CDE157ULL, 0x4A1D9C189F73E2A1ULL, 
            0x1EFE6232DB71C350ULL, 0xBD762CB420A37B5BULL, 0x7730049B7032CAFAULL, 0x31A46071EF266D0CULL, 
            0x92FDD08A3DC45D74ULL, 0x740297C4D2EDE9BBULL, 0x8D3D508D88E54D0CULL, 0x57F2F932CCEE6AF1ULL, 
            0xCCD21E89A40D752AULL, 0x725CBF08E56D8F10ULL, 0x04F5695FE6D3E516ULL, 0x070E1FCBECBEB55AULL, 
            0x05D95449064524C9ULL, 0xAFDC889D90C5F493ULL, 0xAB27D533438D09DAULL, 0x6B71DCABF19804E0ULL, 
            0x720EB0DC02DA7193ULL, 0x942D434046901369ULL, 0xDB85C137E7DBF80FULL, 0x413763EA6E630928ULL, 
            0xC3685A49070FC6C0ULL, 0x86E25ADDDF71F6CAULL, 0x76AC217100FBE065ULL, 0x48AD9C62BF5A44CFULL, 
            0x86AF2249F99EB6C0ULL, 0x4D506E3F18A499A8ULL, 0x23F88A804B4496D9ULL, 0xC8845EED5835E570ULL
        },
        {
            0x7D6D6B921C1F3EDAULL, 0x3C7ACD826CEEB4F6ULL, 0xA046BBD3D34B1DD0ULL, 0xDA32E34D803BD6E6ULL, 
            0xF3768EF724553477ULL, 0xF6735BE91840009FULL, 0xE94AA862ACC738A1ULL, 0x91F515E4BE0A13DFULL, 
            0x60E3C0D20D9482B6ULL, 0xA1C608448C789B68ULL, 0x23FFA4EF9E7785B3ULL, 0x6659D21A9D6DA312ULL, 
            0xA559FA48743D1787ULL, 0xD6AE67A8D2231D37ULL, 0x265DED55AC215708ULL, 0xC1955DAAF3880339ULL, 
            0xB3B037B981D6E8FEULL, 0xDD6FFC747819C764ULL, 0x444A9BD59202FA1FULL, 0xD040334192E8130BULL, 
            0x00A0921B76F5EEC1ULL, 0x40DAF76CF43F7D8FULL, 0x65A84B295288ADDDULL, 0x2705668E0FD6BC25ULL, 
            0x2181EE25B5D7B5D8ULL, 0xC9C79F86BA689FA0ULL, 0xB0ABE89006C62173ULL, 0x7DE50898E4415F73ULL, 
            0x77BFFE3112025DD5ULL, 0x20FF815DA50619F6ULL, 0xA8EDBC4760C72552ULL, 0x27A22FDEF422B4C4ULL
        },
        {
            0xD4039858AB4AE625ULL, 0x7DBC17DDF84E0F7BULL, 0x3BA380265E875863ULL, 0xC48EC035017F9638ULL, 
            0xE3B43CC440907E07ULL, 0xAFB858D31C29DFE7ULL, 0xB796B1DAB34C47FCULL, 0x59DB51C32893387EULL, 
            0xD5F8121BA2EDE5DDULL, 0x950FF9E20760C891ULL, 0x77381CD8D5C511E6ULL, 0x8239A992CE68AF2FULL, 
            0x3F7FF1E91BF23269ULL, 0x228B691EAB61A263ULL, 0x84C7C20FD44DD312ULL, 0x1857C88C8777D614ULL, 
            0xD159D442E7F61BF4ULL, 0xFA3302B2F5E0258DULL, 0x26C556F55B0170AEULL, 0x7E92594D27615DAEULL, 
            0x43E7E9377D822C95ULL, 0xAD0FCF9D6ECC2624ULL, 0x66DBA0FE2FCC4696ULL, 0x8645057A827B59D8ULL, 
            0x225C7E38D221205AULL, 0xB56C4B530DD4CC46ULL, 0x699EC08D9A21268EULL, 0x18C3E5CD8271CCCCULL, 
            0xEF6C19B6140DC552ULL, 0x8B905E663DDF890AULL, 0x903931756EB24481ULL, 0x97A91CA6B7762046ULL
        },
        {
            0xC28D8723FC56ACC3ULL, 0x748D7C9398C63B57ULL, 0x0F693E97CC2F589CULL, 0x981CE29697D18B49ULL, 
            0x18B2A3657E2B1116ULL, 0x3F66DE563DC90680ULL, 0x68D35D00D6A6364BULL, 0x0C8AE0C451577237ULL, 
            0xB4184E349F62D0B5ULL, 0xE811DDAB1E7CDE87ULL, 0x2712B146ADB554C1ULL, 0x7F522CDBB9D3AD7AULL, 
            0x76B8197FAE3A64B8ULL, 0x422CB5E50C4F8CACULL, 0x6BD311A989435405ULL, 0x06758DC0FC8890C3ULL, 
            0x2EE941BE28ABBFB3ULL, 0x8816A01BF2D67E3AULL, 0xAA635BE84E344533ULL, 0xCBCB601C640E2AB8ULL, 
            0x7243E1571A210862ULL, 0x0B942B87BC46467AULL, 0x2FDA1E0ED20A829AULL, 0x407DC20CA758BDE6ULL, 
            0xAC86074A8EEF9915ULL, 0xDA51C522605CAF97ULL, 0xA4C08DC954F0ED56ULL, 0x731893827393518BULL, 
            0x3CD6C19004DA27ADULL, 0xB791839F1DFC7E40ULL, 0x6A07D8184FEF699AULL, 0x594C7C4C60A28225ULL
        },
        {
            0x8711DB6491E30B4DULL, 0xF685101D71A4EE93ULL, 0x6A8122F0199B64ACULL, 0x2B7DDC59537E9C4BULL, 
            0xAC96273B85C7D6C2ULL, 0xD8C06D15E61BB388ULL, 0xB41448435EF22E72ULL, 0x1D98169C139F5D4CULL, 
            0x95BF68CD51FD27D3ULL, 0xB1EE67957FB65366ULL, 0xB2702973013E9182ULL, 0x2E9F6AF4828001EDULL, 
            0x6FB127C30A297AD9ULL, 0x967A1B0A346B052EULL, 0x31B68AF65D4358BEULL, 0xC4358D95C8E35F87ULL, 
            0x0BBFAB0DCCFD54CDULL, 0x831596DF3FCF63ABULL, 0xE59FBFED6076F618ULL, 0xA5127CC26AEDD310ULL, 
            0xB033A22E39CEF129ULL, 0xC1993B5D0794D780ULL, 0x3304BEC86328CEAFULL, 0x90BA99F5CA2ABA8CULL, 
            0xE6E5E89A23DFE30DULL, 0x820C5DDC990C2FA6ULL, 0x8C3987F1A050A206ULL, 0xFD3100A6EFB52D87ULL, 
            0xBF78F5CAFD7A21B5ULL, 0x4FD61B4D1145CC85ULL, 0x656A1C3B71898754ULL, 0x6758D4543F4A82E6ULL
        },
        {
            0xEE119370E3D3E48AULL, 0x2C40510B652FD5DAULL, 0xC327035A62655397ULL, 0x905F823288BAB464ULL, 
            0x0E992E90A3D84BFAULL, 0x02CD0DC894D1EA19ULL, 0xE7F6CE037BF60BBBULL, 0x63311F7FEEBA912BULL, 
            0x89845A47AD0AB0EDULL, 0xE6C8C3795F81BC05ULL, 0xBB337F2CDB004B8CULL, 0xF7823A29F0A39E25ULL, 
            0xC7F2482F22FAC45BULL, 0x1F5E672268538CACULL, 0x6E502CB0BD72C671ULL, 0x3A17267506D3E9F1ULL, 
            0xD1993945B1333526ULL, 0xDA750C6CFFA5A93CULL, 0xEE967243F08CACF6ULL, 0xB305FF6574D1E35AULL, 
            0x51F4538DDB56FC71ULL, 0x4CBD10454F09E779ULL, 0x73944AC561F4CAD6ULL, 0xDA64FA422766B0A2ULL, 
            0xFCD5276F4643183CULL, 0x2E7FD0A4D2994951ULL, 0x0ADB9D3AD52B37F3ULL, 0x1E36451D61F5E1AAULL, 
            0x45F340D0DB0CFD72ULL, 0x3D4305BE461B029AULL, 0x55229EBD65AF8C02ULL, 0xFA6061D2CBA3773FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeySpawnConstants = {
    0x60B3BA6D10BDB98CULL,
    0x6F5371E870BCD700ULL,
    0x1307D82B0906982DULL,
    0x60B3BA6D10BDB98CULL,
    0x6F5371E870BCD700ULL,
    0x1307D82B0906982DULL,
    0x8AA38BE36F5F0D9EULL,
    0xEA45AC64BFB2D930ULL,
    0x5C,
    0xCA,
    0x26,
    0x80,
    0x85,
    0xBF,
    0xDA,
    0x3E
};

const TwistDomainSaltSet TwistExpander_Sirius::kSeedSalts = {
    {
        {
            0xADB45D5ED3FDEFB7ULL, 0x06A9500D0B051DD9ULL, 0x7079B6B252341996ULL, 0xF8CB3CBA0AFBC892ULL, 
            0x54E22267EFB1170AULL, 0x02643DBC782545EFULL, 0xFC273D0D7559D9E2ULL, 0x8291BB986C834EA8ULL, 
            0x229A89C3C1C5D300ULL, 0xDEB07B7F12D373BBULL, 0x4294C4B2EFDB3A1BULL, 0xCF5DA76AD48A9742ULL, 
            0x3068D235064DD744ULL, 0x55E234D443AEA5E3ULL, 0xACA165588FECA853ULL, 0x804CA1E9A0D55FD1ULL, 
            0x3C996CFD0A0081D8ULL, 0x2D986B02FD3B40D0ULL, 0x09DAFB92ECF823A6ULL, 0xDC491D659E9EC481ULL, 
            0x28426022B3A4BC3CULL, 0x2AB06BC4867C77F2ULL, 0x4B63009A6199704DULL, 0xCA02D8068B7841B6ULL, 
            0x3B8CF42BE9590766ULL, 0x3E5A7FC468C2AB27ULL, 0xC8AFDF834312920FULL, 0xC5BB10EE5050305FULL, 
            0xDE0E791E0755926AULL, 0x761EF5A05AFE0DC0ULL, 0xC60401E357CA99A1ULL, 0xDDFD308072DF9809ULL
        },
        {
            0xF4BF682C1C0AF4B9ULL, 0xC86C903BDBC322AFULL, 0x79B77A73417DBE9FULL, 0x6D3BE683E9793516ULL, 
            0x350A0D64CA7847FEULL, 0xEB87863083897F41ULL, 0x9D4C39DADFBB364CULL, 0xD48C5BD2B64DC20DULL, 
            0x2FC18D1B8E0B9539ULL, 0xF1AF9F2FCE511DA4ULL, 0x16E60CB04FB97738ULL, 0x9E8D87B256A18E9EULL, 
            0xCE25B80DFDFBD015ULL, 0x6C953983349AAAF8ULL, 0xCB4C70C3516A3122ULL, 0xC91D4CB6B5724BDCULL, 
            0x7C64BD920B2DBB68ULL, 0xF40973F3ED1FDDCDULL, 0xC749C25F063AA9F8ULL, 0x84F11FD2A2F5BB31ULL, 
            0x5968BBF65C2D8407ULL, 0xC27FD0A8B033C185ULL, 0xFC2B7F0434097BA3ULL, 0x931B4465E8216FBAULL, 
            0x79B3EF15BA486FC6ULL, 0xAEABDBC3F9488E37ULL, 0x2205D911E85D5FB4ULL, 0x0AA62E18AEF25357ULL, 
            0x0A9565041EE900B9ULL, 0x5CEB80A771541829ULL, 0x83699D1CDF98EC20ULL, 0x1FB99DCCD526F4F7ULL
        },
        {
            0xA5ABA006735CFC73ULL, 0x547392BCF47CF7A3ULL, 0xB23D772B526F5F0FULL, 0xF7109B512AD4A84CULL, 
            0x7164D2C8FF634189ULL, 0xEEA04E9B655DCFFFULL, 0xCBB90BE5042862C3ULL, 0x81E3C9723BBC452DULL, 
            0x34A01D7FA8F85EF3ULL, 0x1A1D1B7DA8615EC7ULL, 0x1D159E88C3DCB89CULL, 0x226525B41F74169AULL, 
            0xE53EC3546B122168ULL, 0x2A2BB413D927C824ULL, 0x13B2E07C05473EC0ULL, 0x096AA4BF19AAAFB8ULL, 
            0xBF8155F812F35D2AULL, 0x0041171F68FAF28FULL, 0xB668F5213C57355BULL, 0xCC7ACB4AECE246DDULL, 
            0xF66E5D0C5748D554ULL, 0xDA9CAE32E0E221AAULL, 0x84846DE5E6C478B4ULL, 0xE56EA42B3BE08B48ULL, 
            0xC6EFAC9F4B4C4071ULL, 0x50159559ABF7E642ULL, 0xA7013AEF4DD9B3ABULL, 0xE8D6B54113A3168BULL, 
            0xCD69FC28EB6A0825ULL, 0x5EA5291D54DA8526ULL, 0x21274A208EA70525ULL, 0x9D4A70F2275916AEULL
        },
        {
            0x30BF475A783D4412ULL, 0x8657D7DE5BCF445BULL, 0xFDB572A103F2DB2DULL, 0x000381C69B0E799CULL, 
            0x3A840940E22AF09EULL, 0x03F3E5A536F842E7ULL, 0x9959A353304ECF6BULL, 0xE6183ABD0F694520ULL, 
            0x77F80701FE81CF71ULL, 0xDB3DFB5A13B7F213ULL, 0x66D2DD9D5F48FB4CULL, 0x82AA93EF1FB22FD9ULL, 
            0xDA76A35873F75995ULL, 0xA32B6D433B9925D9ULL, 0xF9E1A5C9B767802DULL, 0x28D06BB73AD7D490ULL, 
            0x1F528F8055F943D7ULL, 0x86441E387DD50287ULL, 0x03E9496165F97491ULL, 0xFDAE9AC42DB22C76ULL, 
            0xFF6835CACC19CB70ULL, 0x85169560E9083572ULL, 0x84AB3A4EED67228AULL, 0xF67E6161AB02A144ULL, 
            0x4D3BCF7E6E18AC05ULL, 0x7E4B2F6E9E6C4994ULL, 0x567CC2ACEBE34709ULL, 0x0D47AAD44C1FE87AULL, 
            0x5E83C6B5110E81C2ULL, 0x09CEA00F022FF1C9ULL, 0x355B9E27C1F5CFE8ULL, 0x4D853EF2CA8350F8ULL
        },
        {
            0x2720D9FDEFE81FF7ULL, 0x459EA79B429AF151ULL, 0x5A17A2CF9011171FULL, 0x7CEB90509B6CE8BBULL, 
            0xE2176B5DACBD2CEAULL, 0x31361D20C2BEB639ULL, 0xAADBB9FCF0C03A45ULL, 0x4DFA3D4FFF7B421EULL, 
            0x8381ACC653CD105BULL, 0xECD308B8D246BCEAULL, 0x499A81D6B773B617ULL, 0x44B5885EAF106557ULL, 
            0x10EA2F9C9102D83BULL, 0x982C0FB2CEDC9DE4ULL, 0xA79FD659AFBFFD85ULL, 0xF2AACB339E84BCCFULL, 
            0x2AEB1AE4F4DF8D2DULL, 0x8EE8D7D08BBCB6C6ULL, 0xA63FA21C5CFD585BULL, 0xA7073CA961F79B2EULL, 
            0x028D5F46039BBF58ULL, 0x0166FE4D64A62DD9ULL, 0x50D3AA08A1E389E4ULL, 0x008DF0332CE6FB2EULL, 
            0x3C26DB08A67AC501ULL, 0xD1EA668F92672AEEULL, 0x78C2DE3A1F6C3B72ULL, 0x09B25D6C69C2E6D6ULL, 
            0xE13731BF72902C77ULL, 0x9ED4332A98731707ULL, 0x3A35BCE50FDF8E50ULL, 0xF1D4064B186EAF30ULL
        },
        {
            0x9EE4864E1451B9AFULL, 0x030B574386D3DC2CULL, 0x20785150132DD9C6ULL, 0xDBCC29D4D10EDBABULL, 
            0x3F5295D35EBC8EA7ULL, 0x5598A866AF5B77FCULL, 0xBE6067472BA7A4A7ULL, 0x8820C7782CE1D939ULL, 
            0x805F32BF8B96C50FULL, 0xFDBB0202B0BE9C42ULL, 0xD52513CD9A1FA985ULL, 0x5D660AEC8E3F31DAULL, 
            0x9F1294A9128CB8E4ULL, 0x22A1AC986DFD6169ULL, 0xF6A43F73D28C47E8ULL, 0xB548A1F87BFAEB9CULL, 
            0xD2CA6D3E83FD1DD0ULL, 0x66D2E3C47B994D94ULL, 0xAF35898FEC618976ULL, 0xC28E243F029A75AFULL, 
            0x644EF80F556A2561ULL, 0x16234C0F95CB3C3FULL, 0x12C708F581E52C13ULL, 0xDC034F0E76F7F4ADULL, 
            0x52D8AB2453627482ULL, 0x177A9481BA5C9A1FULL, 0x32DA7AEC3F6E1FE6ULL, 0xFC465C0C65D844F6ULL, 
            0x9D30C7FAF87176A3ULL, 0x1280C0E28FAB4751ULL, 0xFDAA603D4787E413ULL, 0xA7427E9FD6ED2F5AULL
        }
    },
    {
        {
            0x6FCBF6E627B617F5ULL, 0x3224282E6A6D04BDULL, 0x37822B8F2EE7831CULL, 0x0F80058FE71D99C6ULL, 
            0x54C84D7231F51C1FULL, 0xBB0A4FB293659266ULL, 0xFD04296C710A4824ULL, 0x7D9AADE4554973BAULL, 
            0xD67B684CF79E30DBULL, 0x4150D18CC70FB01AULL, 0x048BD99D310D0A6EULL, 0x475998F0C6FADE94ULL, 
            0x652D88BA8306A259ULL, 0x8CC2B16084C20AA3ULL, 0x6F2834A4ABE4C230ULL, 0x51C96F3B9097E6D0ULL, 
            0xDEB940ED89CF17B8ULL, 0xB7C96A94C57F41ADULL, 0x670A0A66992ED49DULL, 0x6F5D0AD8C57B9F86ULL, 
            0x9C7B6FCCC928FCC1ULL, 0xC5048C02987D2BE2ULL, 0x1998D216F634156EULL, 0x2414617290B3AA73ULL, 
            0xBD2A7E822DCE0E61ULL, 0x8D9FC69862E77160ULL, 0xB64AC03C5A0C4100ULL, 0x9965412837FBFF6EULL, 
            0xCE675D32FF9CD9E5ULL, 0xC18AC8F08F0BAB0BULL, 0xDB113AECAC501D85ULL, 0xA34C7F402434710AULL
        },
        {
            0x76A1FE66F4286A76ULL, 0xDC7CD6770731FDA5ULL, 0xDBE2A03C797C8854ULL, 0x9092BDF58F1D5904ULL, 
            0x5B9FE62827824D8EULL, 0xC5015B72A830C924ULL, 0x5FEC91E5EFBCFEADULL, 0x49E21EC920D24F41ULL, 
            0x5E998805B921DC3BULL, 0x3BC57B12C0DA9961ULL, 0x965D9FEC89F47C70ULL, 0x0D6668B2DB71D502ULL, 
            0x8CAB693C357765FFULL, 0xB55ED9502528FE3AULL, 0x84048A650A203802ULL, 0x455A64BB86B67831ULL, 
            0x79A110FA12C9A006ULL, 0x1F9EDE8CE6E014FEULL, 0x84B7A6A0D9075ACFULL, 0x750E6CDD12400683ULL, 
            0x3B7636BA37BD4C88ULL, 0xFBFA582B6D066396ULL, 0xBB27CBFB381C1CEEULL, 0x0133825F72D804F5ULL, 
            0x8C8F1E0296757A09ULL, 0xD325AEB175A57D6DULL, 0xA715A01A8968F6EFULL, 0xBB090C6D50DEDD43ULL, 
            0xBFF3327E01125889ULL, 0x08EA805BF7B36447ULL, 0xA061CE79B8F2C107ULL, 0x6725969241CCF6CFULL
        },
        {
            0x2E7AEB34F2F86B44ULL, 0x9EC02C824F1735A2ULL, 0x1B84017455669314ULL, 0x126BA9633ADEA049ULL, 
            0xCDD34BEB9D606615ULL, 0xA68ABCF3F71FCD9BULL, 0xF3D46B4C5C748BBBULL, 0x15F8D555ABB49942ULL, 
            0xDA1E76DA9170FE6BULL, 0x25B210A8F1E69417ULL, 0x92ED7A262CD2E28FULL, 0xCE64A3B9EF409A30ULL, 
            0x67BE10B3F444E49AULL, 0xA44CD7BA1AAAE769ULL, 0x895BA63DCE5733C3ULL, 0x3C7D87F2526B256CULL, 
            0x8363BA911B0642CAULL, 0x42CEC6A4629019AFULL, 0xD9EBBF7221B6B7F6ULL, 0xB64014ED4721687DULL, 
            0xE4107B833A538E11ULL, 0xA510B0A54E4DC521ULL, 0x008A66F2136BDE31ULL, 0x81C4DB68AE1BF0C0ULL, 
            0xD41BE6DCFFE65685ULL, 0x785F99ED62874922ULL, 0xFF0A6ED115576256ULL, 0xB2BF9385621D3D03ULL, 
            0xA38F66AD1668C9A7ULL, 0x3352F29E3FE7403EULL, 0xBD6912CA7A63AC2EULL, 0x292BDE38F9C8C800ULL
        },
        {
            0xE76CFDB7B7BCCF04ULL, 0xF40AAAEF9C1513D7ULL, 0x04B0FF0160ED7700ULL, 0xD883236ECB352D2DULL, 
            0xB043E54245601C17ULL, 0x00E775DBBB7719AAULL, 0xA57D20AFAA7EC186ULL, 0x61AD7FA25144F211ULL, 
            0x1E23D9FCCACCD68CULL, 0x68240FDB0DC48ADDULL, 0x4541817E743CE4B9ULL, 0xD6103EA888BCF1C6ULL, 
            0x45046692F64E3623ULL, 0x7B09446AB6288E10ULL, 0xB72853B192C905F3ULL, 0x95FF942726723D07ULL, 
            0xC0C364CE05198432ULL, 0x6BEEF5D2ACD15288ULL, 0xD76D54213DE98571ULL, 0xD75C8830548F1AECULL, 
            0xA3891FF75CE17949ULL, 0x9D6323426C2A9126ULL, 0x5E3D9497386C41BCULL, 0x8B73FB9ED90DEE9BULL, 
            0x21B6BD242CE9252CULL, 0xE9723597850E0A65ULL, 0xF5C3B09ADACCE54FULL, 0xAD48E17D027DAAF6ULL, 
            0x9664AA4A20D1A68CULL, 0x80FE539E4423D6AAULL, 0xD013BF8F581E0951ULL, 0x4B13DA72B43CDF34ULL
        },
        {
            0x7A36E9916E6B8A7DULL, 0x29937F98AB6B364AULL, 0xA2C7013F9A4B9CB0ULL, 0x8341EB4D16321DA7ULL, 
            0x0CF4E3F630065750ULL, 0xBB05F20AE45DAACAULL, 0x010DC584F325754EULL, 0x11FA60A4070DB638ULL, 
            0xEF736C583929E656ULL, 0xC9B77087733AA4CDULL, 0x8DC78203A2162EDFULL, 0x0A49FCDF88296F50ULL, 
            0x4B81612F7A85EE23ULL, 0xDAF41DAF62850459ULL, 0x988E5AA8F3DAA2CEULL, 0xB07FA04F451292F4ULL, 
            0x99AF48CA24275CFFULL, 0xB0250A16D221D835ULL, 0x1411D06CCB2DD1CCULL, 0x01A20D1ECED1917DULL, 
            0xEB5092481DD92013ULL, 0x19B5D1A70A6C6DD6ULL, 0x51AA12C968DF79ABULL, 0xB8C448E13BDAA27CULL, 
            0x09F6E4DCE9690364ULL, 0xA09C02BE06F6396EULL, 0x2EC89E35EE3CB29CULL, 0xFF264D8F5BF3B5C2ULL, 
            0x2653C4A648CB199BULL, 0xDED4C4B6547D6574ULL, 0x42056EBFE8CC9519ULL, 0x3D429255B6C4D3C8ULL
        },
        {
            0x82C060B152C1C27FULL, 0x945FE9F836EAA64FULL, 0x1C808D083476F595ULL, 0x2CA50A8002296EA4ULL, 
            0x8D94347BC6109726ULL, 0x97AAD393815FD0EFULL, 0xD6773118A7247270ULL, 0xC4066DD9943759A4ULL, 
            0x91DAC5AEAA57D141ULL, 0x006AC163ED1749BAULL, 0x59BEF8E829045878ULL, 0xECC9086978C70768ULL, 
            0x7B41FCC5A0DD768BULL, 0xE4B5AD1B163A78E0ULL, 0xAEE0B44F071632E2ULL, 0x3354E2AD9801CA8AULL, 
            0xD327D603FF946E6FULL, 0x39EEFB235B379315ULL, 0x7ED2EA6CC8B5D5C0ULL, 0x9476A3759F1F9E7CULL, 
            0x28A1C1F7DDD17CC8ULL, 0x1B5DA70555D3B66BULL, 0xA2D355B835F3D946ULL, 0x01496CB2A24100B1ULL, 
            0x0A2C97CC672ED48BULL, 0x063A01074ADE5241ULL, 0xE08F5A98D02EC594ULL, 0x64530D15DAD06830ULL, 
            0x03895575E68667EDULL, 0x8D701FF74AC1889EULL, 0x0FF49F73EB1D2585ULL, 0xD98182A9F088082DULL
        }
    },
    {
        {
            0x60F4C8428AB97A99ULL, 0x4424F3E34B8CFFDAULL, 0x6F45CC1522E57B49ULL, 0x1FEA4A3506DCEA8DULL, 
            0x0BB5B944F8CE1809ULL, 0x6D8E3BB98BC47AFDULL, 0x91872DFAF5587AEBULL, 0x60FD72A410E6A2DCULL, 
            0xFF8BA680ADDDC613ULL, 0x4384273F53E00D22ULL, 0x41433512C094B308ULL, 0xCD3DB893DB452514ULL, 
            0xB1DB4F911C156340ULL, 0xC6E64939C5BF94DCULL, 0x29B2FEB8AB30476EULL, 0xB60190B40B96C2CFULL, 
            0xF8200A945007862EULL, 0xC20DFA0628950AA1ULL, 0x7747FFB6785C54F7ULL, 0x64A194E7A8ABE406ULL, 
            0x3071E609BF491F16ULL, 0x3B0CAE3385822372ULL, 0x5F1B3ACC541004CDULL, 0x8FF28D84094D93DDULL, 
            0xED6F2791B66A5925ULL, 0x9AE814ADE1195229ULL, 0xD5BE6E528C2F21B4ULL, 0x5DAFF47F14F073FCULL, 
            0x99A1C188033E5274ULL, 0x937038B34C531289ULL, 0x4B016A6E94357ABDULL, 0xC3451B7819A0A8FFULL
        },
        {
            0x148C341E3E7513E1ULL, 0x4A5C5F2E4C6C396FULL, 0x2CD1351B43CF6479ULL, 0x054E1D55AA37F8C9ULL, 
            0x5239685A86C6739BULL, 0xCF8B34B15B32806EULL, 0xDC69E1DD860FED5AULL, 0x81FFB52B896F8FC1ULL, 
            0xEF45A1569967B031ULL, 0x7E7495B3E7FA84D4ULL, 0x481FED1D48FB556BULL, 0xEF35175C4A7FA115ULL, 
            0xC0F6EC8D15168F5AULL, 0xBBDDF3A0F7B17038ULL, 0xCE2754CD0D248383ULL, 0xD20794B0436A0236ULL, 
            0x787B6248C6E74B22ULL, 0xB975699482B616B4ULL, 0xEA24DFE85C5C7E3FULL, 0x2E7A8CB2432BFF16ULL, 
            0x97C33A279746C938ULL, 0x9129BE53F846A835ULL, 0x44793D4AF2E20CF1ULL, 0xD5E7D317BF6B7FECULL, 
            0x54612B7DCD96E8D9ULL, 0x2FE85233999C939EULL, 0x75255B4944FE00FAULL, 0x2FBA9518F95A9A29ULL, 
            0x320A7520A52FE374ULL, 0x23E9466A5FCD8A85ULL, 0x7C2EBA63860281DCULL, 0x1284A04E86DE00F9ULL
        },
        {
            0xDD600252E815ECECULL, 0x588AA4F7226596D4ULL, 0xF15CB3C2AB5791F6ULL, 0xF4C7990174AA4EA9ULL, 
            0xEF903A4AA82CE691ULL, 0xBBE28873AFC90AA7ULL, 0xA068DA8782D5B760ULL, 0xD1BB8586E6AA3168ULL, 
            0x84543383314B458DULL, 0x8C88A7CE500863C6ULL, 0x21F43B0AB1429446ULL, 0x5AB6760DF361CDB4ULL, 
            0x89DB399F22C48CD6ULL, 0x223DA87ACFE578D7ULL, 0x109568409FD84009ULL, 0x5FF9DDB4505423E5ULL, 
            0x42C6630B9276A832ULL, 0xE496CC0B31309E02ULL, 0x44E3DF607B0CF183ULL, 0xFBF0DC22A1149011ULL, 
            0x4E6B511442931741ULL, 0xA00F078EEA8C15A1ULL, 0x904616C6EA001E8DULL, 0x3CA0C6A8ECCE3B79ULL, 
            0xE1052F1822A380D9ULL, 0xC02F08740DA76DA9ULL, 0x79133D9BFD0F55ECULL, 0xAD77C091651EAC2DULL, 
            0xE50A1729A6B92D87ULL, 0x4AE25643DB5E0B9DULL, 0x81DB332E8F6215ABULL, 0x39FDE16689481A63ULL
        },
        {
            0x1215D507BCE02140ULL, 0xF50DF9B4058FBED3ULL, 0xBD9AD25D83A94B8DULL, 0xDDD089E10E7AD55AULL, 
            0xDA0C57251A058A9CULL, 0x629AD8F24D9D1C37ULL, 0x6F0E75C40AF064B4ULL, 0x3D668A94A38EFEBEULL, 
            0xAFE06038AFC7EDB6ULL, 0x2083B3A20B36896BULL, 0x49D7F1FAA355A718ULL, 0xDA7591B2078B5CA5ULL, 
            0xEA1E580C8187DB24ULL, 0x19FFF1B9810B4F0DULL, 0xA7248EA546EECBDDULL, 0x0A199E0777690AD7ULL, 
            0x1E85E3374BEB7E82ULL, 0x5FCE89C57E129F9BULL, 0x61057E7AEF5EDE19ULL, 0xC234561BA1153BC6ULL, 
            0x75B1B39A68BE7C76ULL, 0x137FF1A3EF894129ULL, 0x387B7E37F59E98C4ULL, 0xCC2E2F4318D78ABBULL, 
            0x7B82CFC642CB20B5ULL, 0xCC680398BDB0D07AULL, 0x8E9AE18FE7AF5830ULL, 0x56FDB6C2F34BE24CULL, 
            0x9D5A60683CB8F924ULL, 0xD1F04722FA8F5E17ULL, 0x27454627CE6868BFULL, 0xECBD0701CB17747EULL
        },
        {
            0xC5972AC69CBAF410ULL, 0xD9F30C6305B2F924ULL, 0xE7A8E1C7B7DF0090ULL, 0x841570C783E0E769ULL, 
            0x84BAF700F19864ECULL, 0x203B155FB6E1F689ULL, 0x5EB7B488F7631BB4ULL, 0xA130394C1F673209ULL, 
            0x19784713FE7AB227ULL, 0xD0462CC55ADC6B07ULL, 0x1CB71F13CE417118ULL, 0x92979449077F275AULL, 
            0xDAC491DD4143EA7BULL, 0x34FC38645B989015ULL, 0xEFF7625375ADED00ULL, 0x8CCE2858BFE2ED68ULL, 
            0xF0A84AE28D2C7479ULL, 0x6EAC6FEFCCDD6270ULL, 0xEB9F3467CA0F68C8ULL, 0x6E08F91DB51CA4A7ULL, 
            0x2DD2CB5B93A80821ULL, 0xE7881598D36C0F63ULL, 0x8FB9DDAD9E41E14FULL, 0xA5FC083298E1904AULL, 
            0x5FE8B13F9466CF39ULL, 0x8DA3B77006B65AB4ULL, 0xEEA4A5D3FD6E59A6ULL, 0xDCECF362DBA10051ULL, 
            0xD8C8F242D36D73F4ULL, 0x57CAAFEB49746BC1ULL, 0x3310176D04D63B70ULL, 0xBE959B2788D06C91ULL
        },
        {
            0x7F4189CAA56F896EULL, 0x032068469E808215ULL, 0xB09187290952F5D3ULL, 0x96173409BAC13398ULL, 
            0x8AFB7BCF3DCF7C1EULL, 0xB0FF1A57DD90DA57ULL, 0x856BF7860C9CEBE3ULL, 0x8FEEE6F897738C4CULL, 
            0x294296E3ECE946A0ULL, 0xA15AB8D850491C4FULL, 0x74A06D6E7E6FB408ULL, 0x9A6545E2CB4CBC08ULL, 
            0x40EDEF24ECF67FDCULL, 0x74B2E565FC18BF9FULL, 0x94733C4222016A7EULL, 0x001ABCA9D8F8E758ULL, 
            0x2B05455C626B622FULL, 0x63164755B58D5B13ULL, 0x33F243E14ABA5E65ULL, 0x064D05930E26B246ULL, 
            0x53B2C8AC9CE7934CULL, 0x0667DE11C276BC1AULL, 0x38B40B868FFAF307ULL, 0x52BCC5FB5ED4D0B0ULL, 
            0x3ACF9282C8F350D8ULL, 0xB4D6AADE891AD4CCULL, 0xE46E28BD3D225BE3ULL, 0xE035DEDCDF9468C1ULL, 
            0x59417C6C4E3601E4ULL, 0xE658AA387BC651B7ULL, 0x386C682ADBE872C7ULL, 0x89379EE7059FBB80ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kSeedConstants = {
    0x9A67782715C4022DULL,
    0x613F01BC9D4E32D9ULL,
    0x6761913F5E38BA13ULL,
    0x9A67782715C4022DULL,
    0x613F01BC9D4E32D9ULL,
    0x6761913F5E38BA13ULL,
    0x241B7081405197AAULL,
    0x3AEC9B75C19A6004ULL,
    0x3F,
    0x30,
    0x60,
    0x0A,
    0xBC,
    0x7D,
    0x7D,
    0x38
};

const TwistDomainSaltSet TwistExpander_Sirius::kTwistSalts = {
    {
        {
            0x0D4A5E0BF890A85EULL, 0x48695FCFF25FD312ULL, 0x0C4011C6949DFF6FULL, 0x5F6AF27B3352807CULL, 
            0xB5EE7AD1060C2942ULL, 0x0F73D7BF7E21669AULL, 0xD5E11138125E9C27ULL, 0xFB9D0AF8A1E169F1ULL, 
            0xEE0C74A2734EB0F7ULL, 0xEE2E6445B5A70142ULL, 0x220A87D96BECEC70ULL, 0xF7F29D88EC4D9908ULL, 
            0x91411CFA947F11A9ULL, 0x460DA1F981B9B9DCULL, 0x7B2B9BD2688AD3F0ULL, 0xC092BAF197596E03ULL, 
            0x0461B044B66A8184ULL, 0xA8946CC38C9E241DULL, 0x7EB44669AC0C5B52ULL, 0xBCA1F9FD6950C449ULL, 
            0xEE0D22635B0B8DE6ULL, 0x3E491ABE2B75DD96ULL, 0x1E8DA248092E56D5ULL, 0xA861E29F3F7FBA75ULL, 
            0x248145614C3A01B1ULL, 0x3EE1B9B4393DFA3AULL, 0xA23C0F30549A0185ULL, 0x2B489A9B0E8B0E4FULL, 
            0x3B2B6B7C9CA87D70ULL, 0x4F45F5739C3E856CULL, 0xFD5FDFED313C3C85ULL, 0x421232831ED7B721ULL
        },
        {
            0xF33E84E52AEE0CD2ULL, 0x92E775E687417C78ULL, 0xA3A8659F64F6AAF4ULL, 0x7C36B773C7F4648BULL, 
            0xF4F5141E6DFE8038ULL, 0x42A1B480BF4B12E1ULL, 0x42EB713D751A0125ULL, 0x63C377825AB15041ULL, 
            0x653D8D6C6C742D44ULL, 0x70B9F94B4075C59CULL, 0xFD0BFA0A1C7E414DULL, 0x9E5112B6A0ABCEDDULL, 
            0xFAEF54CFA4BD3DAFULL, 0xD179940E5D4E9939ULL, 0x01613E3A18EE1061ULL, 0x77EDECD2F9E3DFCBULL, 
            0x7580ED613154000AULL, 0x94401EF9139BED8FULL, 0x9EC569F4CA9CDE27ULL, 0xA0F2B373CA1591C9ULL, 
            0xF8C1D9689E342ABAULL, 0x17A3F6A9BE52370FULL, 0x5E9DE8C1B2BD2093ULL, 0x20BCBCF63E5D839BULL, 
            0x823726B8F35A5557ULL, 0x308F0BE5B3EA8073ULL, 0x1B6B08101BA55EF6ULL, 0xF70502BD82F18BBBULL, 
            0x8519B0D5B198D15AULL, 0x06C4DC6F50495593ULL, 0x98814EECD7772824ULL, 0xA99ACA856BE1B76BULL
        },
        {
            0xB47BF971241447ADULL, 0xAA8153D45D642DE5ULL, 0xBDDDB5C11A64F081ULL, 0xAA36D4F458213764ULL, 
            0xB53F8C39ACE9C89DULL, 0x59793B15F26385BDULL, 0x1344CC82B9E73447ULL, 0x06EB5A96A2647E1AULL, 
            0x32B4CC3A58B8F33BULL, 0x339AD1A1B59EE84EULL, 0x496ECD4DB442EF21ULL, 0x60BF7EE2835F090AULL, 
            0x23E23F2611C2A86AULL, 0xE1AC3A7C763EF223ULL, 0x8FC263BBD54CDC00ULL, 0x79AD0389E26FE021ULL, 
            0x5D610A84ACB15F5BULL, 0xCFD8739255523B84ULL, 0xE6295227A0481935ULL, 0x5A698C43023DE23CULL, 
            0xDDF5ED77340B75E7ULL, 0x4CBB41E11B2BFF04ULL, 0x4A13B1F0ECBA47ACULL, 0x7183CEB583EA5F27ULL, 
            0xD8E40D2091684B3DULL, 0x5B46AD0517754A35ULL, 0x4A666F50ED9FEB59ULL, 0x140DAF49C764E8C5ULL, 
            0xC397E0B67FFE191BULL, 0xBC019282B8F20356ULL, 0xA15A8ECCDB1830E7ULL, 0xA6C52B178262E5E9ULL
        },
        {
            0xA0E61F62BC2E5AA0ULL, 0x3A946349CEB4E880ULL, 0x4CE4D2CE72B8AC21ULL, 0x4909CC35CAC47DAFULL, 
            0xCF04C1EA3C6E9B30ULL, 0x876760253E9EAEDBULL, 0x62B86934F33F6B8AULL, 0x2C34679ECCC90836ULL, 
            0xE845B1B988B752DCULL, 0x6D1D779E6E069C89ULL, 0x020ECEB1C3B736CCULL, 0xBD66EEAD140B875AULL, 
            0x8B6964ADD4426053ULL, 0x5F73EE5017A76F66ULL, 0xFD5BD352C5E27DF2ULL, 0x35BA55B87A592D3AULL, 
            0x407487DE56BD1C1BULL, 0xAAE2439BB1FA0EF5ULL, 0xFED88A4D87077D50ULL, 0xAB00DADAA5C91191ULL, 
            0x60981E139F2AB606ULL, 0xE68323320898BF15ULL, 0x7F395380652EA6F4ULL, 0x38E8B69CD4C6E396ULL, 
            0x87E08A79A817D852ULL, 0x2E8E1A14AF9A814DULL, 0x13C7B8AA1634BBBDULL, 0xD16A2FBCE831EBE5ULL, 
            0x0BE328F07DD7AF9EULL, 0x79A834FB3B0AC4B1ULL, 0xCFFF744B202EA6E9ULL, 0xAEB8B469E97A1667ULL
        },
        {
            0xC8A32798A63CDDF4ULL, 0xF9DB3FE3264E9218ULL, 0xD1852CCB104F7D76ULL, 0xF20C955F3FF33AD2ULL, 
            0x58CE05EDE23F857CULL, 0x3718981EB4D18DD0ULL, 0x176BE153FA6278A0ULL, 0x1410EA3E88463317ULL, 
            0x9DCAFD2FB6BF0899ULL, 0xC32F3B94DC7F91E1ULL, 0xC00C2E8848C4D1A6ULL, 0x2E4C893B54BD1AFAULL, 
            0x1D6C0D549A331218ULL, 0x8951BDDE2584D71BULL, 0x4D64956FC9973A9BULL, 0x7EB659752A0E5345ULL, 
            0x0843D1B1A5041F6EULL, 0xE679E5EEA811B784ULL, 0x2FD7C5EC73E3956FULL, 0x6C7095F7B87B49A3ULL, 
            0x775FBF7230EEF238ULL, 0x3BB3E8141309C23AULL, 0x0AB135A9FE7C3E61ULL, 0xFC0ADD1E25453EACULL, 
            0x5A116184D43507CCULL, 0x10D2E3A47E2D632CULL, 0xAFE24CED96E681EEULL, 0x1582EADB33A77783ULL, 
            0x2EBD1AD48ED66620ULL, 0x736B6FC2D866D699ULL, 0xAF7CB26211317A14ULL, 0x2DC25C31D1D91C81ULL
        },
        {
            0x4FDC7B5EAA0AFB08ULL, 0x0F77A1CDCC1CAA6FULL, 0x39DD98BDA9FF0C00ULL, 0xBB36817E8B94A71DULL, 
            0xE8CFA3DB15E4E4A9ULL, 0x8297CADFCBF607F4ULL, 0x86A6068DC56F85B6ULL, 0x49D5F6BC839FA0E2ULL, 
            0x00DB6D90F30DBCF9ULL, 0x0A1B7AB5492B0942ULL, 0x0D34F17C411C71C9ULL, 0xF9D0C0352B646190ULL, 
            0x54A3B48100BD93ECULL, 0x87C6C793A6FC65DCULL, 0x99698FC7B7CB1299ULL, 0x9DA4E1F2955FD3E1ULL, 
            0x76A86757BF5C3863ULL, 0x2140BF382D77A18BULL, 0x71C6BADA97574348ULL, 0x5010B2FBB3D61CF8ULL, 
            0xFE9EDD6EEE7112FFULL, 0xFEA6EAD75CD16644ULL, 0x47F2E083CE5FF973ULL, 0x5217CE77D311A1CCULL, 
            0x61F44F89C1EE2015ULL, 0x280A1FE98E8EB2C8ULL, 0x02357B8F0DE7DADAULL, 0x6270AE44EEAA8BA7ULL, 
            0x5AF5548174D9328EULL, 0x55C6B09D04A2ECD9ULL, 0xEE5DF8273B821907ULL, 0x519ADE0139F14D08ULL
        }
    },
    {
        {
            0xA3006A42E30ABCCEULL, 0xFC112BDAB8394EFCULL, 0xA8360D2FA461038BULL, 0x5D6F31810BE639FFULL, 
            0x9758E4D75DF148DFULL, 0x0C9AD61DBA243425ULL, 0x27E0D11688490B64ULL, 0x47AF08F166ADD1EBULL, 
            0x71C2B119499F027CULL, 0xDDF42B7273DCE0F6ULL, 0xF5861F26F5D97634ULL, 0x4DC266E74C39F0A0ULL, 
            0x18946B42FBC50223ULL, 0xCC20C96FE1F375A3ULL, 0x41D4F788FB6867F6ULL, 0x4660546F6F7D03E4ULL, 
            0xCCC0414E00463958ULL, 0x4BB5567C0051330CULL, 0x3FC841E881E03232ULL, 0x85562F244F6249E7ULL, 
            0xC2A4EE0C55773ABCULL, 0x6DE3B910C1E247B0ULL, 0x40354BB8C54EDAF5ULL, 0x0079BD246FFA573EULL, 
            0x8DE3BC965383B70DULL, 0x893F520D045CFD42ULL, 0x7D622A397FC00402ULL, 0xB4C115D5F3D1DC43ULL, 
            0xADED12E55AA900DBULL, 0x39627B2398FA56C9ULL, 0x04FBED7A8A40720CULL, 0x5FE1C11036EFC848ULL
        },
        {
            0x44F2BCE90982DD5CULL, 0x40AE12564AA39FE5ULL, 0x47E39B9374B62131ULL, 0x6EC7B11DEE33C7CDULL, 
            0xD99857FBFFCEBBDAULL, 0xC69DD9708156CF7CULL, 0x6B955851CC94A4C4ULL, 0x7D4574A1B3B4E43FULL, 
            0xD43CD9281232179DULL, 0x3D9A1ECFF5703761ULL, 0x9041F8823727E7F0ULL, 0x498A1E490A572393ULL, 
            0x3AFC09C8856D777BULL, 0x090E7F2CA1788831ULL, 0xF21CBF0CA3BAC0ACULL, 0x144BE094345501BEULL, 
            0x721CAD6F4AB7439CULL, 0x16D40478D77603A9ULL, 0xE2559B4FCAC73667ULL, 0x70FF9A81AA6E5D19ULL, 
            0x4B0A1507C9B06B37ULL, 0xBA32A0089086BB7BULL, 0xA513CC5C7FAA376FULL, 0x34A1DD44E36D9C1DULL, 
            0x6F9EA9D0D61CD3EDULL, 0xA0E28EFBDC5A0728ULL, 0x50E18B495D9E7BD2ULL, 0x739D8363033878B3ULL, 
            0x7B5A03164E87114DULL, 0x70E31B6FC8AB5CB3ULL, 0x0BF11C496208B4C5ULL, 0x074D7BA9A0623ADAULL
        },
        {
            0xF62C403EF0680FB2ULL, 0x5064514C92E3EB59ULL, 0x8C544A13D393194AULL, 0xD00ABD196A88F6E5ULL, 
            0x9B6E4E28EA20CD3BULL, 0x10D2095BEDF0D732ULL, 0xE297535504CD3D00ULL, 0x79CDB053E3FB9E6CULL, 
            0x63C9C2A120EB2E23ULL, 0xC8F0858477CF2A81ULL, 0x447EA142D8684CAAULL, 0xF7F35B3472EC5949ULL, 
            0xB011B403FC629C62ULL, 0x2CEE7FD5771342F0ULL, 0x42D11F01308173E5ULL, 0x57CEBFCCE8DCD4CFULL, 
            0xFE518F19ED15C9B9ULL, 0x5ECACBBC265A1F6FULL, 0x7EBE6B6D964F409EULL, 0xE4BAFE7CD23E9A32ULL, 
            0xB3FB28B828E2652DULL, 0x4B88556B989409DAULL, 0x08A17B78381D492AULL, 0xFB5B19582EA88E9AULL, 
            0x687EE6FB56BE2A13ULL, 0x3804FA9EB5BABFCEULL, 0x0654AF937527AC95ULL, 0x324AC2B31DC458FEULL, 
            0x844C708C4DC62E2FULL, 0x7FDBE1658B07ABFBULL, 0xE311899A3AE0CCDBULL, 0xB46C6FE46E2BC4C0ULL
        },
        {
            0x1170EBD304B0AC5CULL, 0x17660224B5EBCAACULL, 0x498024948445685EULL, 0x1705387FF309742DULL, 
            0x7923873E2B05DD23ULL, 0x7477B0B5D80FA67BULL, 0xF121DCFA680CD525ULL, 0xA576B2FAD279B6F1ULL, 
            0x4E80EB0063F0BEB8ULL, 0x9DC1F738F7E733C8ULL, 0xE7408B66E6638AE8ULL, 0xA539D169B6997F27ULL, 
            0xE1AAF0584C801758ULL, 0xBFED99C40054B745ULL, 0x85D814762518BB0CULL, 0x00AC3232E9137ADFULL, 
            0x87AF9F2DE0C4D54AULL, 0x9A8F6A8260A787B7ULL, 0xFF298265E2BCC353ULL, 0x5746EF112EF1AB19ULL, 
            0x0B00CED3CB15A24EULL, 0x6F9DE1FC70B0B09DULL, 0x0AA41EAAA6D3C217ULL, 0x3AA56B216C48DD0DULL, 
            0xD3BBE632138DB6FFULL, 0x21F87B053C5638B0ULL, 0xE110649914848A95ULL, 0xFB5E37A564F7DAF2ULL, 
            0xD2E1FE52D6326766ULL, 0x0660E493C58737ADULL, 0xDA120B89795E07A7ULL, 0x3911320BFC661ED4ULL
        },
        {
            0x2BA63BC80ADDFDD5ULL, 0x2A4336144D82826CULL, 0xB9424A04950B0899ULL, 0x135889CCEE358DD0ULL, 
            0x4D60C81771DA0A74ULL, 0x7C1662232B6D9D81ULL, 0x0A7D675875C4249FULL, 0x75AF51D0F7B03D47ULL, 
            0x34863FD4D3FBD597ULL, 0x8EC8E6AAF65902C2ULL, 0x59008B94C0C65C43ULL, 0x73851F22696A3B30ULL, 
            0x96FBB58FA814578EULL, 0xD04663935E5071BBULL, 0x43A7CCF72D6E9021ULL, 0x00F6ED5D0C84E247ULL, 
            0x5D0BAA11D783F1C4ULL, 0xBDA629BA243BDAC3ULL, 0xDA01E77C705CD714ULL, 0x41FA9DA7092812B6ULL, 
            0x26701A8AB7938E5CULL, 0xAD4E8C22C5D720D0ULL, 0x3E021AB69D48C221ULL, 0x81D5D283389B5C73ULL, 
            0xD937958669421152ULL, 0x5A9BC8EF9B48745FULL, 0x5C901FF63BAB460AULL, 0x1A5DE96CCD2488C6ULL, 
            0x932B473E3EA827BBULL, 0x373C5D34A44BFFE9ULL, 0xF52A801B146650C3ULL, 0x2790FB841E1EE997ULL
        },
        {
            0xCBA6450584CF5DEFULL, 0x5D9B95AAF294AE16ULL, 0x10DC8E75AB29EDB1ULL, 0x59617A3E668F9D41ULL, 
            0xEEA6EF480C804AEDULL, 0x924EE6BB7DE52692ULL, 0x2DDD734325C8BFB0ULL, 0x16A8071560A6F9E6ULL, 
            0x04A680C887261888ULL, 0x71E74159383A0D4EULL, 0xEF985D61FB45109AULL, 0xAD8BC9E38EF9CF15ULL, 
            0xAA02377B7D8BB1A9ULL, 0x4248D61BED682F28ULL, 0x8BBB30F9585CF73AULL, 0xE8C6E17A179E6B20ULL, 
            0xC100DAE2727F8275ULL, 0x0F3C24C78C247CF4ULL, 0xE12638E329214A89ULL, 0xE3F3CFB850010C8BULL, 
            0xE9FF021085D9959DULL, 0x273934395C331850ULL, 0xB5A3088760A2D4B8ULL, 0xF69AA6AED9FBE8E6ULL, 
            0x5C07FF3197DE4010ULL, 0x950F16AC640F65DCULL, 0x88DF5DB7B6499B9CULL, 0xD98F5B85C22D8722ULL, 
            0xC81FECD144756770ULL, 0x09D022A190D0CC83ULL, 0x8B5F6EB1EBB462DAULL, 0x89DF85676C5183A5ULL
        }
    },
    {
        {
            0xFF6C5DDDA55222BBULL, 0xF94016C16B43E849ULL, 0x20B475B0DDF08DB8ULL, 0xEAF7702C90459928ULL, 
            0xEEF3C96657C73106ULL, 0xF04F9AFBF244A9DAULL, 0xE21D6E493FBE29B2ULL, 0xA6596523151B737FULL, 
            0xE744C766E3293026ULL, 0xBBC6C9E988A46CD9ULL, 0xE65C43F38BCE6888ULL, 0x8F928B45420E6A8DULL, 
            0x014F70BAF96FC0E2ULL, 0x3689D2800785BD21ULL, 0xBBF3E39BDAD9ED33ULL, 0x7D5B2344AF261569ULL, 
            0x9DEFB3BE53C316B3ULL, 0x63C5A8A64747DA29ULL, 0xEF139E370317C2BBULL, 0xBC675FAFD350BF6AULL, 
            0x0F190B3F670E3F7FULL, 0x834C3B7C61633E21ULL, 0x57CA638B5B90B0AAULL, 0x76BAE4E0BB69287EULL, 
            0xBB9CA285A5D72EE7ULL, 0xE3860347E6F2B461ULL, 0xA9D4453A9CDC4B42ULL, 0xD4F0FCFAB8A8869AULL, 
            0xF3E04404A1D19918ULL, 0x12B2D3B702D83734ULL, 0xA98CE804773A1551ULL, 0x4D07BAE671C03A44ULL
        },
        {
            0xA9E4CB8862438869ULL, 0xE29832F9C9A641D0ULL, 0x8D9CEE4D5E98B365ULL, 0xA5F07BE6775512FFULL, 
            0x10719EDB6A4F757AULL, 0x0DA4431CDCA31ECDULL, 0x0EC02164467B33C6ULL, 0xBFDABA01EE206133ULL, 
            0x2385C62B7CB911FAULL, 0xF6BD34334E5BCDAAULL, 0x455832F472D92EA5ULL, 0x96E57D3121078449ULL, 
            0x785A25FC39B4FFBFULL, 0x41F399C71A8D00C6ULL, 0x950E46D1A13E7462ULL, 0x41C3F8CB3D78D97FULL, 
            0xF3E1A624E2FE8892ULL, 0xEE4C54E08CDFDC67ULL, 0x75024B1417E170CEULL, 0x9441C3BA795F2EB1ULL, 
            0xE3CF0E6A041704A2ULL, 0xB21BA69A1620F3ECULL, 0x3571C80F0DC1A22AULL, 0xE4E795A7BDCE00A0ULL, 
            0x9F3552315EAF6FD3ULL, 0xF00B015600173565ULL, 0x0BA531FC3990AFFAULL, 0xDCCED4D0E036AC96ULL, 
            0x3551C6F4CA1BBBBFULL, 0x16F3B035CC008BF5ULL, 0x6CBE8CE9B674469CULL, 0xD1F22FD3822FB9EBULL
        },
        {
            0x7BBCBC7C2B132D5AULL, 0x387EB71A9057B598ULL, 0xC6C662B536080DCFULL, 0xC6744B7D4F196C16ULL, 
            0x9B3E116E5754CA46ULL, 0x26654E24AA37350CULL, 0x7EF518121C8108FCULL, 0xA10797BF01960946ULL, 
            0x52E4663005CFC106ULL, 0x249509B5F74CD9BBULL, 0x6C2AB289E4FB7D69ULL, 0xEB417D24654C6D27ULL, 
            0x22119E8CF62AB978ULL, 0x73EF63D885B44AECULL, 0x40DC7CD6F72E9C6BULL, 0x471BCD3429F56EA0ULL, 
            0x034781D41A3E282EULL, 0x8EF38FD1EAB946BEULL, 0xC427D010E57AA57BULL, 0x4B9F1D8167BCAE5DULL, 
            0x917AF881A315BCE0ULL, 0x25F984788305CF12ULL, 0x02D5A88541366211ULL, 0x97A31E5452A1634CULL, 
            0x8CF8BBB0607FAE42ULL, 0xFB4224F8240B63F6ULL, 0x0BE1D102E56E476BULL, 0xC99F0204A94F6702ULL, 
            0x758BB56449B78DD0ULL, 0xBA36E4D839AEBA70ULL, 0x429373AFA65962A6ULL, 0xE9A571F69F8BD3FFULL
        },
        {
            0x1CC5A843F632D914ULL, 0xF93576DF8DD93304ULL, 0x480B2B6DAFFDC2BCULL, 0x8C7A83E1A94BBF53ULL, 
            0x358FD3B151CF172EULL, 0x3FDDF40F4A7E8112ULL, 0x926B1D0D82A7E4CAULL, 0xA7DDE3109A2B746EULL, 
            0xE9A66163115F4BE4ULL, 0xE0B6C93A8DF89750ULL, 0xDFDF26FFD07089C1ULL, 0x56EF8F65E711AF2CULL, 
            0xD7F00C3927EFBCB7ULL, 0x0C28ACFEC5154572ULL, 0xAC7A46C040BE6C4DULL, 0x7DD00B01B9B1ED1EULL, 
            0xB836F1512BD56B63ULL, 0x204AB18BB77D7132ULL, 0xD010360D6EA361C5ULL, 0xF0B1E48EF25A8057ULL, 
            0xE78F5C6EB13A5BB4ULL, 0x99CC98714989EED7ULL, 0xA6D1E91208FD1B5FULL, 0x43F24574884B954FULL, 
            0x6DFDD3029C80D632ULL, 0x2CFB8F34FEC2A9B9ULL, 0x64D1FAD8A3ADDD31ULL, 0x9E1B4FB281095066ULL, 
            0xB8567BC9E79EAC31ULL, 0x17FEDD037444940FULL, 0x3A5226B99BA507B8ULL, 0x6E0CA38220728D55ULL
        },
        {
            0xE7340AECB2E8A2BCULL, 0xEF6FA5ED04E0B0ACULL, 0x3D86148B742EABC4ULL, 0x093038D8DA9CCAB8ULL, 
            0x593DAE3279853E6BULL, 0xB02D16EA3434DEEBULL, 0xD8ED84C9343ECF3EULL, 0x53A2F8832F111242ULL, 
            0x260B521527BB72A0ULL, 0xB0C10B3F14C4A4EEULL, 0xB482D9FD274FD74DULL, 0x0E9C8D515C268F49ULL, 
            0x06371BECBD8D6752ULL, 0xA75B504AA4B0429CULL, 0x5DC1D76D9B929DBAULL, 0x3C024FF2FFA18580ULL, 
            0x961E71CB95328950ULL, 0x080BAEF067D688D8ULL, 0x7C5B54D2F603794DULL, 0xE3F9760EC3B30209ULL, 
            0x7B195D6D7131C44FULL, 0x1AAE5B4F20D664AEULL, 0x2C7F135375E52DF7ULL, 0xEC424BBD60A137C7ULL, 
            0x993CB90C7101684AULL, 0x333269B4731C0A7EULL, 0x7541CD37DE77E150ULL, 0x2C09C61F4EB3382AULL, 
            0x5878EFCECA9FBDE8ULL, 0x6A1E2073A03013AEULL, 0x33933C742DCA792FULL, 0x4E5FA4402BD5B952ULL
        },
        {
            0xE5CE2C206BD82BEAULL, 0x682AF76F74814E1BULL, 0x711582F0A96BE257ULL, 0x8F7C71A1CB633B4EULL, 
            0xED13E66844BC12FCULL, 0xC934870BCF20AE1DULL, 0x676518DAEDB18147ULL, 0x0CE28300F171ECB7ULL, 
            0x7D883FF11359AEC7ULL, 0x9B7229CEC8EDE9B7ULL, 0xF1D0E756AC426BDCULL, 0xA45790DD1808294FULL, 
            0xC1E408964FF1D088ULL, 0x0E5BC590C25E0170ULL, 0x8C960D10E697D8A4ULL, 0x6C47068E8A3090FFULL, 
            0x23900654418A43A9ULL, 0x4FD80A2A7676DEE0ULL, 0x62986F3129492AFFULL, 0x6C836DB9FE7CE4C0ULL, 
            0x76D53521BAD759E3ULL, 0x5D31658B7966D13AULL, 0x3FF67AB151C4334AULL, 0x47173C66DD8FE7AFULL, 
            0x223512BC0DA482BCULL, 0x837B7886E1FF0ACDULL, 0x3853DD92E7875C90ULL, 0x444814D9148EF4E6ULL, 
            0x1AFE4E46B964C62FULL, 0xD6B044BCAB6CDA7CULL, 0xFC28FCECB3F40CC4ULL, 0xE39BB1555071B8BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kTwistConstants = {
    0xC399E78FBEBC8AFEULL,
    0x99AD2ED488631620ULL,
    0x860F1657AABB49A8ULL,
    0xC399E78FBEBC8AFEULL,
    0x99AD2ED488631620ULL,
    0x860F1657AABB49A8ULL,
    0x908AC3B4D36C4B2AULL,
    0x39B186480B0355F0ULL,
    0x3F,
    0xB3,
    0xA3,
    0xA5,
    0x3C,
    0xF4,
    0xCC,
    0x57
};

