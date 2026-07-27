#include "TwistExpander_Alcor.hpp"
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

TwistExpander_Alcor::TwistExpander_Alcor()
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

void TwistExpander_Alcor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA4F3A3947288A915ULL; std::uint64_t aIngress = 0xC22C0528B38BCC16ULL; std::uint64_t aCarry = 0x823B0DD8DE8D5D1DULL;

    std::uint64_t aWandererA = 0xF0B509E9E19B40B8ULL; std::uint64_t aWandererB = 0x9178E65D7A60205AULL; std::uint64_t aWandererC = 0xEF861175901F74FBULL; std::uint64_t aWandererD = 0x9A4C33D64D582D36ULL;
    std::uint64_t aWandererE = 0xB8978252851EA608ULL; std::uint64_t aWandererF = 0xB62627B31E861BC0ULL; std::uint64_t aWandererG = 0xDBDE89447732790BULL; std::uint64_t aWandererH = 0xA0E07BA5DBC4B3B4ULL;
    std::uint64_t aWandererI = 0xA2B7FE94C10BE771ULL; std::uint64_t aWandererJ = 0x9A0897237D192D59ULL; std::uint64_t aWandererK = 0x8F882BF2216243A9ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x92EE2635D0D5A295ULL;
        aCarry = 0xE4441788ECEBC42CULL;
        aWandererA = 0xD1F1AF8B31184341ULL;
        aWandererB = 0xBAB833450E5CB136ULL;
        aWandererC = 0xC237176921E1361FULL;
        aWandererD = 0x8B7C8221E1F561DBULL;
        aWandererE = 0x8495FE2AF7860E91ULL;
        aWandererF = 0x9618097A067333A1ULL;
        aWandererG = 0xB5ABC29B61D5759DULL;
        aWandererH = 0xC26BAE67FD844A04ULL;
        aWandererI = 0x80E35497B193436EULL;
        aWandererJ = 0xE611EF39AC92D9F4ULL;
        aWandererK = 0xCA4A169BC07CD8F0ULL;
    TwistExpander_Alcor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE5C595F1606F5867ULL; std::uint64_t aIngress = 0xC3DE139CD8C19D42ULL; std::uint64_t aCarry = 0xF482C997806DA305ULL;

    std::uint64_t aWandererA = 0xB9D7FA113058D33DULL; std::uint64_t aWandererB = 0xA479CA4352310B50ULL; std::uint64_t aWandererC = 0xEF79F962B28FECFDULL; std::uint64_t aWandererD = 0x9F8E69043A241238ULL;
    std::uint64_t aWandererE = 0xF16B1981119BDBB5ULL; std::uint64_t aWandererF = 0xECAD975FA0136468ULL; std::uint64_t aWandererG = 0xD12F14C95F575109ULL; std::uint64_t aWandererH = 0xA1D652B9155648D0ULL;
    std::uint64_t aWandererI = 0x9EEA602601E0EDBAULL; std::uint64_t aWandererJ = 0x8EC5CBCBC0491892ULL; std::uint64_t aWandererK = 0x88C6F4C9269D310EULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAC3A3653852BE6D4ULL;
        aCarry = 0xC7EC5BE54E291431ULL;
        aWandererA = 0xACC8635BB9427137ULL;
        aWandererB = 0x8B28C5F1EA1BD8A4ULL;
        aWandererC = 0xCB62C171E95588AEULL;
        aWandererD = 0xB11A7ED7B901FC40ULL;
        aWandererE = 0xECC3C4E4D781206DULL;
        aWandererF = 0x862FF9E952ED7909ULL;
        aWandererG = 0x9CE8C20B33BC9598ULL;
        aWandererH = 0xA5E0FFCC06B2B479ULL;
        aWandererI = 0xBA67D6B6F3025F3AULL;
        aWandererJ = 0x8B5D0345EC337880ULL;
        aWandererK = 0xFDF2BB1B9A6F0C3EULL;
    TwistExpander_Alcor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCCC880CCA44B9E35ULL; std::uint64_t aIngress = 0xD54BC6FA400AD216ULL; std::uint64_t aCarry = 0xBB034CE23DD93663ULL;

    std::uint64_t aWandererA = 0xE35478A024B9964FULL; std::uint64_t aWandererB = 0xD39EA2CEBC18A671ULL; std::uint64_t aWandererC = 0x8BE104E2920A5E1FULL; std::uint64_t aWandererD = 0xD900930EFC5C7C55ULL;
    std::uint64_t aWandererE = 0xBE571001C88C91F0ULL; std::uint64_t aWandererF = 0xD371C2F52E614B24ULL; std::uint64_t aWandererG = 0xEEFAE6A9E3D01A5BULL; std::uint64_t aWandererH = 0xDA3072CB2F77EAB1ULL;
    std::uint64_t aWandererI = 0xB832D03A8270B25AULL; std::uint64_t aWandererJ = 0xE24C66C6AB37C8B7ULL; std::uint64_t aWandererK = 0xE81F462D6C4A6C9AULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD6F1BA9A93F7FF2EULL;
        aCarry = 0xEB5A29C403375DA5ULL;
        aWandererA = 0xA591A60436E514B4ULL;
        aWandererB = 0x99E56CAD71AF49FAULL;
        aWandererC = 0xE1EBB1BA583BBF10ULL;
        aWandererD = 0xAE1AD56CA7DD1B72ULL;
        aWandererE = 0xD8FC1A8A33F43108ULL;
        aWandererF = 0xEEAC6DA0C5FF87A1ULL;
        aWandererG = 0xFD420C8781424285ULL;
        aWandererH = 0xF63D991627E9771AULL;
        aWandererI = 0xF3426B2C312FBB62ULL;
        aWandererJ = 0xA4C6E1F1AA9CBF58ULL;
        aWandererK = 0xB969BC5F15E3D153ULL;
    TwistExpander_Alcor_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8DD18B32E410F673ULL; std::uint64_t aIngress = 0xE70C502519BD6ED4ULL; std::uint64_t aCarry = 0x8F5CA92806642B8EULL;

    std::uint64_t aWandererA = 0xF8862769736E1C8EULL; std::uint64_t aWandererB = 0x87EF5CA7279FA753ULL; std::uint64_t aWandererC = 0xFF6300D340BF627FULL; std::uint64_t aWandererD = 0xFA2438B21EE11387ULL;
    std::uint64_t aWandererE = 0xD666EA15DD2DB7A0ULL; std::uint64_t aWandererF = 0x833B0633278CD4F4ULL; std::uint64_t aWandererG = 0xFC0B9417077C9D5AULL; std::uint64_t aWandererH = 0xC04996D8C5F0C1F9ULL;
    std::uint64_t aWandererI = 0xF846D51CEC1FD757ULL; std::uint64_t aWandererJ = 0xBD747CA482891061ULL; std::uint64_t aWandererK = 0x9CB3C4F5FBBA5A63ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9C598BC28FC9EF53ULL;
        aCarry = 0x900771A16A6BB918ULL;
        aWandererA = 0xEF0C9C091137EFD4ULL;
        aWandererB = 0xB34621CC581DAD8AULL;
        aWandererC = 0xCF58CC57EEF26557ULL;
        aWandererD = 0xAEC99984BC879DD1ULL;
        aWandererE = 0xFC180948663BEB99ULL;
        aWandererF = 0xE81E46F0C5DAA7D1ULL;
        aWandererG = 0xF8936BBF3267B74AULL;
        aWandererH = 0xE43AA0507265434CULL;
        aWandererI = 0xBC47160FECAF6E54ULL;
        aWandererJ = 0xF424CB8809A64E5EULL;
        aWandererK = 0xED823104C6195008ULL;
    TwistExpander_Alcor_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alcor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAC9849E78BC32268ULL;
    std::uint64_t aIngress = 0xF6DAA322E306C0D9ULL;
    std::uint64_t aCarry = 0xD1886015F1A7468EULL;

    std::uint64_t aWandererA = 0xD7B7610CA12B84D1ULL;
    std::uint64_t aWandererB = 0x8C624467085240ADULL;
    std::uint64_t aWandererC = 0xC71E9F6099EBA4B3ULL;
    std::uint64_t aWandererD = 0xFA13B611D5FF1AC5ULL;
    std::uint64_t aWandererE = 0xCA569F352EA1D9CCULL;
    std::uint64_t aWandererF = 0xDF567CF5803E0EFBULL;
    std::uint64_t aWandererG = 0xD7D598768173E441ULL;
    std::uint64_t aWandererH = 0xE8D54BEBB3741AEEULL;
    std::uint64_t aWandererI = 0xA2669908A3C4B714ULL;
    std::uint64_t aWandererJ = 0xCCD15C92FF8D964DULL;
    std::uint64_t aWandererK = 0xB2258FDADC36C259ULL;

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
    TwistExpander_Alcor_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KEY(pWorkSpace,
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

void TwistExpander_Alcor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEC99BE079ABC593EULL; std::uint64_t aIngress = 0xAAB032C466150523ULL; std::uint64_t aCarry = 0xA5D6BD710B1F427FULL;

    std::uint64_t aWandererA = 0x9A394F4A8E056019ULL; std::uint64_t aWandererB = 0xED0C3B0869D5D57CULL; std::uint64_t aWandererC = 0xF2F47E1B0E25BBE9ULL; std::uint64_t aWandererD = 0xE525F711E2CDBF4CULL;
    std::uint64_t aWandererE = 0x95557D6A10F66C7EULL; std::uint64_t aWandererF = 0x9CDF991E0304C5E8ULL; std::uint64_t aWandererG = 0xA9B711C9004A42EDULL; std::uint64_t aWandererH = 0xD8FD459E7204EC43ULL;
    std::uint64_t aWandererI = 0x92A622D70CE24FFAULL; std::uint64_t aWandererJ = 0xF0A6BC7DDD143642ULL; std::uint64_t aWandererK = 0x9936455E496F111BULL;

    // [twist]
        aPrevious = 0xFFD54C9B2CE65A3EULL;
        aCarry = 0xB3B9FD9AAA050736ULL;
        aWandererA = 0xB98AD9D9DFB63D76ULL;
        aWandererB = 0xFC38442D311D19E7ULL;
        aWandererC = 0x86DE9EC16D10CD87ULL;
        aWandererD = 0xEAC8F2F81A9D1F73ULL;
        aWandererE = 0xCBAA7C1517CA3276ULL;
        aWandererF = 0xE3F51F3A9B224EA9ULL;
        aWandererG = 0xAD2029077F0D26DFULL;
        aWandererH = 0x8B48F78ADDAD4360ULL;
        aWandererI = 0xB620E3E120FB0FF5ULL;
        aWandererJ = 0xB1CB66C489F2CB7FULL;
        aWandererK = 0xF6867D6D2D2BB1B1ULL;
    TwistExpander_Alcor_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Alcor::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Alcor::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Alcor::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 2 of 33
    // Exploration cases: 0
    // Structural maximin 640 / 674; family total 640
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 2 of 33
    // Exploration cases: 0
    // Structural maximin 644 / 674; family total 644
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
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 565U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 2 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1200 / 1248; total 1200
void TwistExpander_Alcor::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
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
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1488U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1781U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
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
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 2 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1187 / 1248; total 1187
void TwistExpander_Alcor::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
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
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 386U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alcor::kKeyRotateSalts = {
    {
        {
            0x61DC48EE26A2BD38ULL, 0xA46AB040C7D078B0ULL, 0xA63356DBB789D8B5ULL, 0x4E4B9E9739185251ULL, 
            0xF7F133D4EB42C66EULL, 0xBE7A59114C1C0819ULL, 0x8B276F5052D28AE8ULL, 0x6E1FB10CEF7D6ACAULL, 
            0x8BFCA229017B2A65ULL, 0x601CDE160731DD30ULL, 0xFC5C1D2037197093ULL, 0x7F3195E2673D84ECULL, 
            0x166983ADC93E7DCFULL, 0xBC58AEB5D3D6946FULL, 0xDDC5488642ABF30CULL, 0xA0A644ACB9FC4FE2ULL, 
            0xF3D387F3A874673FULL, 0xB6FE69091B647B3EULL, 0xDE4DB22F7AFF3983ULL, 0xE2620903BF7619E7ULL, 
            0x2E56F4BFC24437B1ULL, 0xB6E0A6C69FBD9A7BULL, 0x1B24EF65EEFA1778ULL, 0xD9AAD312F9F20CC4ULL, 
            0x7EB866218668DDADULL, 0x2EA5AC5EBE4A412EULL, 0x4AC94F2336AE5772ULL, 0x68AA2DAF7FC22E6CULL, 
            0x1155C91B5BACA3B6ULL, 0x753A6AB2E5A6BC81ULL, 0x2DA627A3894D0F47ULL, 0xA1D4C06E5A710976ULL
        },
        {
            0xCFDBF58B1E74564EULL, 0xBF01E0891904A91EULL, 0x38EA42EE50CBA5EFULL, 0x3598638AD06D896EULL, 
            0x28A8BC6F3D19F9AAULL, 0x69EAA0296F2D6E34ULL, 0xFFC49FDFAB3F612AULL, 0x8BCF73C78A754252ULL, 
            0x5F30FBB760ACA2C7ULL, 0x1339B090A751BA34ULL, 0xEEB8BB7E3B2FC1FDULL, 0xEB42D8BD8B8BCAB8ULL, 
            0xA5B88CDEDC980C19ULL, 0x9DE06EF084A79BF3ULL, 0x9123B0DC435E81E7ULL, 0xB2B5A147E95B33F3ULL, 
            0x2086F3510FA34463ULL, 0xB3D5ADA9FE2EA191ULL, 0xD4AB1C7B58214B3DULL, 0xA30B89FF44E1622BULL, 
            0x33058D651C505C45ULL, 0x4D2F46E155DE5B91ULL, 0x9691CD651046B808ULL, 0x34C39209B922C529ULL, 
            0x2C48E2CB834C4981ULL, 0xC5FAA09DEA25717AULL, 0xAB0C959723802064ULL, 0x1CE36D1627498DA4ULL, 
            0x897BCED976828DADULL, 0xCF2AFD8A3968BF3CULL, 0x79271A2371A2A298ULL, 0xEB3E51E43B282C61ULL
        },
        {
            0x1A5939C5E52A1FD5ULL, 0xB96242126B632BC4ULL, 0xB5814498AA5E4356ULL, 0x6EC57C5204AE5A51ULL, 
            0xDC961049EEA92C54ULL, 0x99D27BACDA266841ULL, 0x71CA75E3FDD5D8BAULL, 0x184C1D21AC0EB9D7ULL, 
            0x8F898844396C568FULL, 0x32616A7348B99CCAULL, 0x91772B835DE175EDULL, 0x8B1C96AFE4886070ULL, 
            0xF45BB39B2B04DCDEULL, 0xBE0557F5C9F129CFULL, 0xB291B4C28384F254ULL, 0xF0A13D1FD2270F2EULL, 
            0x13D674EC625B5C99ULL, 0x6BC7B48617228053ULL, 0x94EB4CF98CF7A37FULL, 0x05A7B8A45C80D0DAULL, 
            0xC253343ABE27D6C2ULL, 0x1C45F96AF0E510E1ULL, 0x57525AB19FE2900FULL, 0xAFE5B4CF134A972BULL, 
            0x9F06DDB1E1ADD30BULL, 0x60AE6EB793D6B579ULL, 0x142B6B009331C715ULL, 0x1A565D382493EFFEULL, 
            0xB88ECB52BF7D3165ULL, 0x0899A0CE375FB69BULL, 0x998A53641957CF4FULL, 0x269AB2D4BC236012ULL
        },
        {
            0xE14F0E6E44A59D65ULL, 0x8A9413A83DB50B07ULL, 0xB04C8B9B7A89E528ULL, 0x8E8C07E6F97AD42DULL, 
            0x2384287E3DDA8E20ULL, 0xAC4A487E25C92C3FULL, 0x6FD922361B639144ULL, 0x90ADF283C13E563BULL, 
            0x3A7840F356050733ULL, 0x875DDED18D6F3219ULL, 0xEE51B05E7B6691ABULL, 0xA0B5E62FB18A0C28ULL, 
            0x6B10696A1E8AB3F9ULL, 0x16EE7C2199ADE94AULL, 0xBF0CB059DD707C50ULL, 0x571A723438F39B83ULL, 
            0x231AA00145D1C1DFULL, 0xD7448B4CCAA75908ULL, 0x16A3D856D878F9DDULL, 0x81F779C86D06831CULL, 
            0xF1B0DC9342C1E0F5ULL, 0x285726BE4DF2E027ULL, 0x393A760D45446F1FULL, 0xEB639848B695C718ULL, 
            0xC2A263655F7916DCULL, 0x028F53A7F66334F3ULL, 0xB8E9F6B9F3C66802ULL, 0x78C888C978FAB3E4ULL, 
            0x484E829A6CEF01A3ULL, 0x471876C6FCC3CC59ULL, 0xBB956E62A46F0A40ULL, 0x3A9F8E8D1F17446EULL
        },
        {
            0x8D70598380FD2402ULL, 0x3F8B7277E305ED9DULL, 0xA0915BD5DE4445D8ULL, 0xF7DC1EB38233B5B6ULL, 
            0xC30986F5B2EB6491ULL, 0xBCEF05293E1DB5F2ULL, 0x024BF2698B4FC4E1ULL, 0xC6F572682F21A4F4ULL, 
            0xF90A5CCB6840074DULL, 0x8FEB200748969819ULL, 0x2A5A55F3359AC469ULL, 0xB625F33A77D27E8BULL, 
            0x39D2F06AAE58223EULL, 0x49BDA3094494A7E4ULL, 0x45468D717E96FE44ULL, 0xB20462518737E21BULL, 
            0xFB2058BD85AF0389ULL, 0xCEA37921D4AC53E5ULL, 0x6A5EBF7D900F49F7ULL, 0x4A1D7C0578AE6B9BULL, 
            0x8829C09B2524FEA1ULL, 0x690D6658AC215422ULL, 0x791499C3F8311BF4ULL, 0xE2EF647D80AB7316ULL, 
            0x8ACDDA5CA1378C9CULL, 0xE334A2843E483673ULL, 0xCDA5EFE308EA3258ULL, 0xF566BDD360A01815ULL, 
            0x1B1B3B0F9199D578ULL, 0x87FF3C34B86A0507ULL, 0xD27916261BD90F00ULL, 0x6E97E2190CE10017ULL
        },
        {
            0x06E35C11FC68329AULL, 0x6E85C9A0BD0A2F29ULL, 0x32F0BC110845C09EULL, 0x4FF1A1DCD3084D77ULL, 
            0x5D1EA058134807B7ULL, 0xD23EFE3A56811106ULL, 0xFF7C14EFF1083A38ULL, 0xE1CADDC09B2D6B62ULL, 
            0xDE6B021C45007956ULL, 0x191E0F576385686BULL, 0x0968654C80CCBA70ULL, 0x6E24549A4D2D7682ULL, 
            0x6E318A54165FF99BULL, 0xE14C60FC61A09C86ULL, 0x4C8852CC2F111913ULL, 0x68B85C78BDCA9E7BULL, 
            0x976546AC8CA0F3E8ULL, 0x08764210635C0EB9ULL, 0xB27C72FC380F305CULL, 0x633BE4DD11EBBCBEULL, 
            0xB38312DB17F4075EULL, 0xED3353BAC08EE8FAULL, 0xAC41A66FD1605565ULL, 0x9727D5972695E29CULL, 
            0x74ED01F3D7191AEFULL, 0x572A40CD753ACEABULL, 0x55E5EA9E62BB8FA6ULL, 0x50E623C110717C25ULL, 
            0xC29BCF261F93C5DBULL, 0x81F02D731C1015B5ULL, 0x12F312E10B1F494EULL, 0x35ECF33E3E3C51D0ULL
        }
    },
    {
        {
            0x64249A7C9BFE7EA4ULL, 0x148F042A1269A62AULL, 0x44ACC22B6C42C216ULL, 0x9DBC8E545476D83FULL, 
            0x21D256858E945559ULL, 0x883A2BBC6527F2E6ULL, 0x2D3CA4F4F0C723BBULL, 0x8F8BC80C5241A5E7ULL, 
            0xD0C4069D9110E614ULL, 0x91939E1B94C41606ULL, 0xE9B671762D79B9C1ULL, 0x18A2BD9BEA985898ULL, 
            0x2746A1C4DFED901CULL, 0x9455309E1C47244AULL, 0x9550215A96423690ULL, 0x8D8E9DA958F1CDA5ULL, 
            0x06E6D1F1CBE9124DULL, 0xEDD4A1A65880183DULL, 0xF81550CD85D0A692ULL, 0x94E3FBDECC1BAA3DULL, 
            0xC1C3C0EC386F9121ULL, 0xB27D34B3086C831EULL, 0x7CD7369B872D035EULL, 0xCEA2D87B7C183F9AULL, 
            0x1E7FE4B591A79045ULL, 0xE95F9298F4306656ULL, 0xC15431E3ABC75989ULL, 0xCD5F147450D24B94ULL, 
            0x401272AFBE448718ULL, 0xC84C722DE8C517D2ULL, 0x5015CE24A7102988ULL, 0x3C482A7E6BBD9174ULL
        },
        {
            0x1EC8C9375FFAE28BULL, 0x773E3791D9E4F1EFULL, 0xF071CE6FF9711315ULL, 0x2036FBD50F7B353BULL, 
            0x790B73196B40EB6FULL, 0x0DFDCD9B28C9A59EULL, 0x6E19EF5D807B0FF6ULL, 0x54679E838F9A01A6ULL, 
            0xB52B81FCE76B0220ULL, 0x7BEB565CB3C5AD71ULL, 0x2A74FE74E87ACB04ULL, 0xA30D4EF7393855DBULL, 
            0x6B9E6D0E8FA69A02ULL, 0xC1EFCAC21F42E23EULL, 0x48EEA2AB9E38E7D8ULL, 0x802AC0549CE95634ULL, 
            0x8549DDC186186094ULL, 0x7F1ADB92FDE41AD6ULL, 0xF4A9B85A2A26F128ULL, 0x04F359752EA22468ULL, 
            0x986AEDE58C87B2E4ULL, 0x165FCD1354A8E4A9ULL, 0xBFDDB8E697A2E986ULL, 0xA808C81DD234C607ULL, 
            0x0E8DB47FD717677DULL, 0xF0C7A135618A59DEULL, 0xD4046DCA22716094ULL, 0x212F91B77910113DULL, 
            0x9D5F28784EA5E29EULL, 0xB875AEDCB373AA26ULL, 0xDC6E106B596721D8ULL, 0x4691CB9334FCA2C7ULL
        },
        {
            0x980AAB6E334C871BULL, 0x14606C1500AF20EAULL, 0x52D914C222AFE9C3ULL, 0x5D8F0280B3B9D58EULL, 
            0x144FA90F3B0F9762ULL, 0x2222168AABAB8A85ULL, 0xD74684480F0D7735ULL, 0x9FA20BEDB7B90111ULL, 
            0xD46067A903D62957ULL, 0x3196A46A1B529437ULL, 0xA055054868E3A67AULL, 0xB6C05DFE884DDDEFULL, 
            0x55FD3ABF0C597B5BULL, 0x36D71366529B17D9ULL, 0xB43DD3E3444F28A3ULL, 0x4E6A38514E4F5E22ULL, 
            0x0CC6AA0DEAE340DAULL, 0x7495020F2B2BB52AULL, 0x9E6B2BCB638E7620ULL, 0x6A12958FC5F72EB4ULL, 
            0x1B0288D787CF2892ULL, 0x92D80D3EF1068BE4ULL, 0x4C148A051524C2D7ULL, 0x96E6F732024490BCULL, 
            0x149297BF54322AC7ULL, 0xD30E486B6C4B88E0ULL, 0xC51C0C689F4A6B30ULL, 0x3A3A574A314E1D3FULL, 
            0xDA4EBF73AE113866ULL, 0x09FAE1F05872271EULL, 0x12E0363BEC49527AULL, 0x26079E3B05885E72ULL
        },
        {
            0xCB598E484434174DULL, 0x87EC5DA4661971AEULL, 0x74C476726944B1B9ULL, 0x7DF9DE99D890E949ULL, 
            0xE59D0B78CC4598B0ULL, 0xC0FF57D70ED180E7ULL, 0x53D2121B05924B10ULL, 0x4DD17E3F4285AA3AULL, 
            0x0F5FB5293E208676ULL, 0xD0C7CB4B002F616CULL, 0x5CC396B3E9F242D2ULL, 0x813C95B095F52860ULL, 
            0x90A7B2372FA770B2ULL, 0xA42618D2027C0776ULL, 0xD93580DB04FE5D43ULL, 0xEEF579A15B1AB0A0ULL, 
            0x03FC4EFFE332E8A3ULL, 0x16CF71CF39F4C342ULL, 0x055FA53D34498B9DULL, 0xE287BD0EC6236E09ULL, 
            0x8D8A5392E7C6FF70ULL, 0xA671E38C9E3C0896ULL, 0x8506800B58AEAF09ULL, 0x3515F11DB2CCD2A3ULL, 
            0x54A77B5ED01B6736ULL, 0x98D4C4941D18A921ULL, 0x5C4AD99A559F352CULL, 0x1666129CCF923323ULL, 
            0xB12A4E2DF7E4D19EULL, 0xBF9A2A6EE36C8EBCULL, 0xA32B0ED3719CD32EULL, 0x7FA6AAD7D5061592ULL
        },
        {
            0x23CD698E06333230ULL, 0xB3FB1869B930C5D8ULL, 0x257F1D725C37DC72ULL, 0x855D10F56D4EC1DAULL, 
            0xE272737454DF815FULL, 0x4F1059C7386C2E25ULL, 0x608DE8E87E461678ULL, 0x2AEF3D75184D41E3ULL, 
            0xE63544FBB0409FD5ULL, 0x9465DCAB3BC2C3F9ULL, 0x75BED115F8B1BCEBULL, 0x5CE0530A637B2708ULL, 
            0x76E2DC87EA23E9EDULL, 0xF30059D2A0384724ULL, 0xBAC1E85622A6C9B9ULL, 0x7AF15E6AB22566A6ULL, 
            0xE19BBAB79F48AA7AULL, 0x83686BC906DD94B7ULL, 0x6D0C097B751C503CULL, 0x11F270C0E241CE93ULL, 
            0xEAAB9DF11A22A87CULL, 0x06D061342BE5C57AULL, 0x4714EF29C8CBCA57ULL, 0x2705ED72FFE2C562ULL, 
            0xC24839298620E2D9ULL, 0x13D47FD1E148F517ULL, 0x1ACB46FAE5709765ULL, 0x6F3F07E00C3EC9DCULL, 
            0x600A7C8FDD692CBFULL, 0x8D56F1C15D82C5A6ULL, 0x87C12422FACD0076ULL, 0x0EC2CD7D57D2C937ULL
        },
        {
            0x76E40C65A2D02848ULL, 0xABBDCA663CC3050AULL, 0xA53AA84E91783E9BULL, 0x395C273E54058E78ULL, 
            0xF809FF77F8BD4CE6ULL, 0xE4B8303E5664EFE2ULL, 0x170D97F5C73079DBULL, 0x4FD5BB180048A071ULL, 
            0xDF5725B3AE802BAFULL, 0x19C3BCE5A9CA8B1CULL, 0x775FE72CC627179AULL, 0x2E23B1A76E9D1640ULL, 
            0x0E4B5625D593C64DULL, 0x69CA3CB7948168FEULL, 0x7EF6D52B7C8B4540ULL, 0x9A8CB23907231A50ULL, 
            0x181976B973434DFCULL, 0x68E3D282B1B0DA3DULL, 0x57DBB76CA92FD3F5ULL, 0x637E1563CC0C0EF2ULL, 
            0x5C8FF3FD97FEADC0ULL, 0x24B2348D20D65962ULL, 0x1B17D6BFEDA0F91AULL, 0xF96F2DBB75A84B22ULL, 
            0xCEDAF5C29EA85CA2ULL, 0x616C383D47D02D0DULL, 0xC85385020A16E69CULL, 0x2664813D3F445E68ULL, 
            0x7E9A746E72584FF1ULL, 0x44957B122707C4E8ULL, 0xC84764A542807A7CULL, 0x15686CD86708AB30ULL
        }
    },
    {
        {
            0x85CD51F7DA915E5DULL, 0x6F0C569459F2191BULL, 0x7C6473D75D47674FULL, 0x34D0F52FA9907666ULL, 
            0xEE121A2C3C66DEE5ULL, 0x9E0AA2035AFFCD9BULL, 0x2C78AEA4E24D27E8ULL, 0xE3DA696D64583F3AULL, 
            0x44F60E6A41901A1FULL, 0xB1CB8A53E5FC5CFDULL, 0x8D3B91A429C630BFULL, 0x39881664FB0D6025ULL, 
            0x664996DC921E3AE8ULL, 0xF14931C94F11DDBDULL, 0x6552AAA932778334ULL, 0x355ED176A2572B46ULL, 
            0xCD8325BCD8C08033ULL, 0x4AB590328BE6AFA8ULL, 0x0B519F2574C7B79CULL, 0x41DE2C9BD10B5C96ULL, 
            0xB1953FAFE0786E6CULL, 0x60D8C8E866B5840CULL, 0xF7F3CE6785E5A784ULL, 0x213B79057CF8F570ULL, 
            0xD8332836C6D38303ULL, 0x4205DA0A0E63B2D7ULL, 0xF954452F4FF14146ULL, 0xDE2A56625D8E60CBULL, 
            0xC8979F4C6F2E54CCULL, 0x3AA74E27C118211CULL, 0x38EAE32774D0AAC9ULL, 0xADC40E74EA8E999BULL
        },
        {
            0xDEAF293E9F7D1A73ULL, 0x650432F2C70AC587ULL, 0xF6F8832611FB5553ULL, 0x5E59D21028FF4027ULL, 
            0x34FBBD4B2F957C26ULL, 0x33C9C55B836F067AULL, 0xB298E133AB451218ULL, 0x19592339C66D8B26ULL, 
            0x146ABC3F4E42EC7CULL, 0xF8E86D41CA4A72C4ULL, 0x00FE8EFAC84C0B57ULL, 0x80D9D41450847376ULL, 
            0x3337A42CB8FD2CE5ULL, 0x7E7265DDE6CF732CULL, 0x72703C6C8B760397ULL, 0xC6EBD66A0AC2AB71ULL, 
            0x26E494BBDD3B1442ULL, 0x1CF24E16762E3907ULL, 0xA803F8FB4A6B99A1ULL, 0x831FE6E933A95A5CULL, 
            0xBFD6FF41F177C1A2ULL, 0xCAC35B25AAFC2E5CULL, 0xD869698DD91AF90DULL, 0xFA2AB1B53FA1B689ULL, 
            0xC43730A2D6F93A27ULL, 0x61D13B42A07FC27EULL, 0x512A7EBFEC065D10ULL, 0x90420ED4D83EBF5CULL, 
            0x5EE4194BE286BD78ULL, 0x5A10F561036244C1ULL, 0x353DCC06E290800EULL, 0xF182FF5C539DB23FULL
        },
        {
            0x788F5362A77B8CBDULL, 0x15E1D609880CE71EULL, 0xE3686756E58DA6F3ULL, 0xFC2BB1941A6A29DAULL, 
            0x4CF07393B0EDABC3ULL, 0x667C51BEF0EF0DB4ULL, 0x4369EF1B07EC2011ULL, 0xC056A8513F6B5F7AULL, 
            0xDA05577C73C0145FULL, 0xE57A0DC4CF04E1C6ULL, 0xB8E743BF7E7D31F5ULL, 0x8245E844E320DF1BULL, 
            0x0BADA43055B9348FULL, 0xE81D6B80AD982481ULL, 0x3B5598EFC8FD2B05ULL, 0x924DDBD32FA7CC58ULL, 
            0xB53AB5E9F84043EDULL, 0x7321DF95B38DAAA9ULL, 0x6BE66A685C69E524ULL, 0x6C32C953A3381297ULL, 
            0x9994D1AA68D986F3ULL, 0xEE3D5E94C061765AULL, 0x1B8057F892CDF63CULL, 0x1BC298BAE8B45939ULL, 
            0x1D9B62B3EC1AEF81ULL, 0xD40C45C310DB1FDEULL, 0xF7063D13A29FA371ULL, 0x6F4B51A57447056BULL, 
            0x86098EF18F23E6F8ULL, 0x848D71BF7BCB13D2ULL, 0xF9FE007056BC346BULL, 0x5DFEAFF78F0C9137ULL
        },
        {
            0xAC3405611FB9FD9DULL, 0x0347A3D844AA9243ULL, 0x912AED9FB8AA5A16ULL, 0x285363EC87D8B0F4ULL, 
            0x99F7FC5411CF5F82ULL, 0xC956CE9FCB1C041FULL, 0x1EC2087D6EE97B91ULL, 0x410B42C2C208721FULL, 
            0xE507D675CFFF6A6BULL, 0x656794564AF559B0ULL, 0xE43495066FA3597FULL, 0x567D863E5FA4B785ULL, 
            0x9C70DF61444574D8ULL, 0x086AA9C0E7449F31ULL, 0xD243DC624A07DB50ULL, 0x2313F975B5A2D6C9ULL, 
            0x8677A338E38AD813ULL, 0x2DE16FB7A4A54204ULL, 0x1B31EF509D4B7CF3ULL, 0x9B97F1DB82769CD3ULL, 
            0x3B8F0B3DF08AF6AEULL, 0x1FDA7E2A501FBCD2ULL, 0x71B22CDC1764C4C2ULL, 0x67B9B3089B0ECFE0ULL, 
            0x194FEF63BF2F463AULL, 0xB6BE8C6D0FBDCE65ULL, 0x7C40CF7C5123674DULL, 0xC4873900115F386CULL, 
            0x4F9C3346F0188437ULL, 0xF47B6554A26807F5ULL, 0xC4604A28FDD9FD21ULL, 0xC892F2FF057E6CC5ULL
        },
        {
            0xBB478B38BA024DBDULL, 0xCB220315403A6688ULL, 0xF92440F42A6C5057ULL, 0xBBD42F2037132FBAULL, 
            0x68BC9AC200B5828FULL, 0x191D5DF249D3318CULL, 0xB94FA417E2A5AADAULL, 0x7A8038533AD2F694ULL, 
            0x17749A8F7EF36CC9ULL, 0x35E53CD2A0000E87ULL, 0x6B56720D25F96E0FULL, 0x3742443DBA2EB751ULL, 
            0xA836BFA7ABFEF457ULL, 0x1C6D7F7300D112E8ULL, 0x94B8B4FE2C57F507ULL, 0xAC9209155C500129ULL, 
            0x8064467182CA6D66ULL, 0x5AEA7A1F8C34FDFFULL, 0xABF6663DB61EC50BULL, 0xA15046CFC4D32C78ULL, 
            0xD296D81E50A7B445ULL, 0x8ED489B0787C09EDULL, 0xC7D9240CDE0E5608ULL, 0x3A09B28C78D2A5DDULL, 
            0xC628D038E00E219EULL, 0xED239C6AADE082C1ULL, 0xAE478FCB714F4896ULL, 0x8C89D40E8301AFB5ULL, 
            0xC591F3EAA4B5A544ULL, 0x4323CFB67752F5E4ULL, 0x14E2F374FC5BA9E5ULL, 0xCC63B4114100A522ULL
        },
        {
            0xFF9884A1C8AF8451ULL, 0x2F5719DC5B73A894ULL, 0xF407FF859AF960C2ULL, 0x1A9ECF073EFA5F79ULL, 
            0xBDA4FB967CBFD96BULL, 0xFDD7254815239D45ULL, 0xC89DBC9EF8911C34ULL, 0x5FA8595F0D778A6DULL, 
            0x876EA73F4D8185F0ULL, 0xDF22BA258C808E6BULL, 0x26AC227481C3F47CULL, 0x6621E1D5B2147E34ULL, 
            0x1C4BC8106E0E079CULL, 0x418DEF5DFB9069BAULL, 0x109CE7411C2654E0ULL, 0xD3A0EE93AD7F71CBULL, 
            0xF2434620D7F6E4E5ULL, 0x8FEA6D010EF67AEBULL, 0x6A9A68A8CBC9DB24ULL, 0xECB3E74DB8FCAA54ULL, 
            0x64605D26A8421587ULL, 0x451F41DC9594A9C4ULL, 0xB98BAAA8FB073396ULL, 0x3578C553017424C0ULL, 
            0x47782CA5B2E5601AULL, 0xF6EDB1AE3F3FE753ULL, 0xA77B6BD5DD507A2AULL, 0x1BE10E9A68FB5783ULL, 
            0x801B6479C0FDB152ULL, 0x11953DCE3A5947FFULL, 0x57204697DC4294F8ULL, 0x98E894EDF1ADE827ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeyRotateConstants = {
    0x1D9B8ACAD8760CE4ULL,
    0x60CDB3A067D299C2ULL,
    0xF47B8D139A88DB8CULL,
    0x1D9B8ACAD8760CE4ULL,
    0x60CDB3A067D299C2ULL,
    0xF47B8D139A88DB8CULL,
    0x9593598D79A45DA4ULL,
    0x0606538A0773923FULL,
    0x7E,
    0x34,
    0x0D,
    0x5C,
    0x99,
    0xEF,
    0xC9,
    0xE1
};

const TwistDomainSaltSet TwistExpander_Alcor::kKeySpawnSalts = {
    {
        {
            0x8012AE18F75060C8ULL, 0x42AB58AB5233C8B3ULL, 0x677469D9411A8599ULL, 0xDA80C4616ED4E596ULL, 
            0x542B4FD3F9F52C41ULL, 0xEF704B65DCE26051ULL, 0xEB8BFD0E50111F98ULL, 0x26B5F27C27DDBA67ULL, 
            0x684AA9EE3E834D8EULL, 0x09719AD13A1540C2ULL, 0x38F8D6DD56237EFBULL, 0x118E801C649B4967ULL, 
            0x5ABF38DC032F5AFAULL, 0xFF15F386ACFE9F20ULL, 0xE559260DEE42B31DULL, 0x5E1C6A338C82186FULL, 
            0xB4D077ED600321EBULL, 0x9DC670388FE909D1ULL, 0x4F20EA9E88542032ULL, 0xDF1EEC91126431E8ULL, 
            0xAFD7FE385F3E7A7EULL, 0xAEE2373C8FA4930EULL, 0x303B2D966E858E61ULL, 0xFFC1A21451D2E603ULL, 
            0x0ACE1128ECF42E44ULL, 0x765E07F40CAB1A3DULL, 0xCD194ABDFEEA4B74ULL, 0xAD139C2A38FEF2F4ULL, 
            0xC0654297E9014361ULL, 0xC05094BED390DE73ULL, 0xE9C068E1D33BE89DULL, 0x780E43AAFA95414AULL
        },
        {
            0x75649B0AB8B6275DULL, 0x6F9BCB20020D72ACULL, 0x62F571C4F1690C31ULL, 0x0853ADBACE786722ULL, 
            0x2F9E1D5F0A71AE4BULL, 0x921C43C6BCDDD543ULL, 0x90FD754057AE952FULL, 0x28A3411160AD61E1ULL, 
            0xA81589935C96845DULL, 0x9F45AC79BF7052C5ULL, 0xAB3720E51ACE24A1ULL, 0xC78A11A0AF15EF71ULL, 
            0x46F6E98B2501E34CULL, 0x290B343E33AED782ULL, 0x076C3A04789FB3D0ULL, 0x48DACD48459F121AULL, 
            0x8C3A3931FBD61095ULL, 0x902DA071D1FE639DULL, 0xAFDBDACDCBD1CF8EULL, 0x0F7072A3BC405FCDULL, 
            0x02AAE7ABEDC44A21ULL, 0x0A980DEF14E068FAULL, 0x17DD1EB4FF934264ULL, 0x29C86AB08D798AC9ULL, 
            0x5CD165348D37EF16ULL, 0xAD2878BC98F42C02ULL, 0xCEA931C69D27B6E9ULL, 0xD1408C1AC80FB8DAULL, 
            0xDE12B525FFC444E2ULL, 0xD5870DF9D7AE33E1ULL, 0x7ACBB4106E5CE360ULL, 0x37293B17608AE8F5ULL
        },
        {
            0xA62B4C87A47F94EFULL, 0x3DE1D521C2EC1DAFULL, 0x45191761BA26F4D3ULL, 0xD3E276D4A81D7029ULL, 
            0xE9EA4285461AB65EULL, 0x0DD5D9E500DD9646ULL, 0x927B8CF569879440ULL, 0x35DFD07159FA59B7ULL, 
            0x4B2EBA3EA37F385FULL, 0xB27022BABBD793D0ULL, 0x1BE7E4C11092E64BULL, 0x7EE10CDB6A9C52D2ULL, 
            0x6D63FF87941AF89CULL, 0xDFBE0CCB8321BBF3ULL, 0xAD611B590AC132FBULL, 0x73779F338A777D26ULL, 
            0x5A4C2D50300B5D33ULL, 0x3D0350E3B59AB920ULL, 0x4851A496A059FFD9ULL, 0xEDB1DE1A985EA978ULL, 
            0x0ED9B54651902962ULL, 0x6557B03BB8616D4DULL, 0xACBFD25A8E169B54ULL, 0x66A59240909373ABULL, 
            0x00D194BBB290C831ULL, 0x848EFC62523279B4ULL, 0x4612D273B0C55CB0ULL, 0xA139B0A87D38DE4DULL, 
            0x307AD792B69AF9AAULL, 0xF68330BA297A157EULL, 0x134507C2FF7077E4ULL, 0xCD0B3820E796B464ULL
        },
        {
            0x4752947BEAFCF19EULL, 0xB59174BB405FE619ULL, 0x14384265F604A465ULL, 0x148161FB4626A092ULL, 
            0xFF0DD83C322A17AFULL, 0x43A92DE2E044290EULL, 0xA4CE48119731F7B8ULL, 0xD6220BB56F2B8E79ULL, 
            0x5BB541F4F381252FULL, 0xD4A653A308CDF9A0ULL, 0x2C18FE604399CD62ULL, 0x718287735F104D31ULL, 
            0xD44248C5788BF04CULL, 0x63C4C32C6CD1E230ULL, 0x9F552D25F2319B10ULL, 0x779EA4690EDF82A5ULL, 
            0x8096E826EA69A562ULL, 0x15B218A35662F52EULL, 0xD93BE2755B1DE78CULL, 0x07BF28FF229A56C4ULL, 
            0xACAEE09CE3186F89ULL, 0xDACA97DC1B3B5D7FULL, 0x7CA736C9D806D370ULL, 0x6F54EB81C846D39BULL, 
            0x9EB32402D82E11D7ULL, 0x208734260493736CULL, 0x5ADEC638C9DF266FULL, 0xB5F908F0D4AB37CBULL, 
            0x55112B8590D69297ULL, 0x6EBA8184922037AEULL, 0x95508672EBD47A0DULL, 0x75575FC778103902ULL
        },
        {
            0x0F6C7BD46D1B6217ULL, 0xD97C41C2FE081E07ULL, 0x82456F2A8C252D7FULL, 0x59BFFA9FCF816CF4ULL, 
            0x0C756739A011E648ULL, 0x9163543325676AE4ULL, 0xE85E33F8B6412DE7ULL, 0x94A1B5634D1DAED6ULL, 
            0x02515347AA7D3F3CULL, 0x0973E4F54010D9D1ULL, 0xEC5457699E534168ULL, 0x7B884705C2E163FDULL, 
            0x0A90DC0BDFCA254DULL, 0x842E5D46858D9518ULL, 0x0FAB2247FCAC0C41ULL, 0x9746904DCBD26717ULL, 
            0xD494CA3A868E4FB5ULL, 0xC2D3E43964148BD4ULL, 0xA4A22806F07A281DULL, 0x69CEC83924227C8EULL, 
            0xB76D01574C0C5BB7ULL, 0x40DFAF1A4D1E3B4AULL, 0xC42D200C80EDC63BULL, 0x14A5E3DB124B22F3ULL, 
            0x1E7734825A079407ULL, 0x218B97CF3D7E6CEDULL, 0x79EF3872A99D9069ULL, 0x7379335870945D7EULL, 
            0x772CE60C713D7050ULL, 0x944EF29427EC79D4ULL, 0x413A89D92E0BD8D6ULL, 0x7F3040D2A7757DCEULL
        },
        {
            0x7A544BCD7007D69FULL, 0xAE684A3C43594E2AULL, 0x16304E0BC7E38098ULL, 0xE26B0D0DE38529BAULL, 
            0x55E832C2F293A09CULL, 0x37365C54E7AF2E81ULL, 0xCE0E3D929F0E9E12ULL, 0xAF72229798A2DB67ULL, 
            0xD495F59C9330E20CULL, 0xAF0EEB19B6D5DC2CULL, 0x2166B73397DC42AAULL, 0xBF405CB3FD2E19DBULL, 
            0xC117BA2992CCBD30ULL, 0xE8C6F3E6F1CD7015ULL, 0x0BECD608AB72E72CULL, 0x06B61CC572D757CEULL, 
            0xB8438F500B07E564ULL, 0x72E2FD557EC876FDULL, 0xE6A8241655C448BDULL, 0x28AB30883BB0F0B5ULL, 
            0xB1BC5DD2BD2F95E4ULL, 0xE423EBCE800A326EULL, 0x561B60D514D33BE3ULL, 0x370880410976A690ULL, 
            0x975A14AC70128229ULL, 0xB0F9D67C7A54AB1BULL, 0xA5BF8B5B97500DD1ULL, 0xC17C8C26619BD08DULL, 
            0x632B7BB411270F1EULL, 0x9186F4739B5D0808ULL, 0x84B1DF54413F54C8ULL, 0x62EB7AB74F196265ULL
        }
    },
    {
        {
            0x2BCB49AB1A82A33BULL, 0x01E788C63EE28CFBULL, 0x6F89A895C3BCA1CCULL, 0x26F363D65E436E26ULL, 
            0xAA65A8D42DBBC18EULL, 0xF909D77E44385378ULL, 0x150F66ECBAEB6F81ULL, 0x44530E8A0ABDC4FFULL, 
            0x3BCEEBE2E5382C3DULL, 0x3365D107DEED7A6BULL, 0x4A6E1CE5AACB7047ULL, 0xA0BB968D3041B2AAULL, 
            0x9AB088774F20D162ULL, 0xB8A6F92178E32E7DULL, 0xA2253DEDE8458905ULL, 0x86CBD99C4626D2B5ULL, 
            0x42BA66F54332A2BCULL, 0x4B6E7EDE55EDF2E8ULL, 0xD76A6FF9C87189B3ULL, 0x92DDCA5AB52279C6ULL, 
            0xC58DC452C1897B4BULL, 0x6223187ADAE7AC6DULL, 0x750B3F93DAF029DFULL, 0xF7F98E4AB0EA1F05ULL, 
            0x9D3E6C19334DA13CULL, 0x4E501FCDF0559B63ULL, 0x136A21F4A144C03AULL, 0x065BE16615905030ULL, 
            0x1EA70B38AFF5948AULL, 0x6495C2F41087517EULL, 0x356A4306033BF044ULL, 0xC079556A068F68E5ULL
        },
        {
            0x805B4B3DEE4D7DB0ULL, 0xC8AC0A6F982F96D9ULL, 0xB85FCD6F9607E70DULL, 0xA733568B892EC029ULL, 
            0x3D27EC05B26BA511ULL, 0x499357100AFFCA28ULL, 0xB2690C0C8DEB646CULL, 0xD172A3636E29F3E7ULL, 
            0xCF3ED0F9F084D94DULL, 0x2B3BBA3D84BA94BEULL, 0xE7E962AE646A491EULL, 0x79C740582BD8D7BEULL, 
            0xCD555BF5CA59D6A0ULL, 0x9B03B2281C2B0364ULL, 0x57C7C937CA5BAA76ULL, 0xD270DE967AF58FE6ULL, 
            0xAD6E9DBD05161847ULL, 0xD812B033813512D9ULL, 0x36F7A3CEBE87AFB0ULL, 0xB2F7961EC19996A1ULL, 
            0x9F472A8396FB87D9ULL, 0xC64EB998B1A2C56DULL, 0x3ED97DE01119B46BULL, 0xE1BEEEB54E9F42F3ULL, 
            0x1EC6FD811C705723ULL, 0xF5AA43D93926A521ULL, 0x41A997318A60FF28ULL, 0x743107F8E5753B44ULL, 
            0xE0EB0BAF7BA5FDEFULL, 0xDD9F82445AE39FB5ULL, 0x425AE3C585BA1BE7ULL, 0xEE82A0CC94940CE5ULL
        },
        {
            0x6CD1F22B814A34F9ULL, 0x12FBD1E8C9EF7C05ULL, 0x708E99888F1A43C0ULL, 0x2624A6F973F7FEF0ULL, 
            0x12462675352308A6ULL, 0xF60F042B2D225930ULL, 0xC256E45D4D40EFA0ULL, 0xE9126F9A41C0209EULL, 
            0xE1EA375B19C36CE3ULL, 0xA14C50EFBABBED8CULL, 0x9C3B8FF0DE2812A4ULL, 0xD1CBF3AF1C460FECULL, 
            0x58757873493ABB3EULL, 0x7BD80ABB917C2C68ULL, 0x22D0A342CC213E4FULL, 0x1D06AE97882D8AD9ULL, 
            0x8370F63ABD066606ULL, 0x0F9A7134251256DFULL, 0x643A02C6E8F4ACF5ULL, 0x341255449EBE5064ULL, 
            0x961471F660AC2DE8ULL, 0x0C1BD28CC4DECFA9ULL, 0x9F46624EB56ED9BDULL, 0xFDA2DF3F9150575CULL, 
            0xA55B8C3C7BA3A16FULL, 0xD975FCB0A2EE83C8ULL, 0x00DE6555FA08AFA3ULL, 0xB8430A1849BF7F6FULL, 
            0xD05DDAFEB80DC625ULL, 0xAFC25F017898AD7EULL, 0x741CC7091881E821ULL, 0x3FD840D064938B37ULL
        },
        {
            0x4AF9695E7C4212B7ULL, 0x14AD1DDEB90D7F8EULL, 0x5BC7143AA644F006ULL, 0x1EBFD7231496C8B8ULL, 
            0xD9D917422C39B447ULL, 0xC9F08C2A4C61935DULL, 0x17122466FADD026DULL, 0xA9B1AD9BD4B34778ULL, 
            0x8F6144CBCA4AFCBEULL, 0x1D9070C525CAC71FULL, 0xF93592C1BAB14C95ULL, 0x3B8E05AA56906635ULL, 
            0xC98E31EF59854E25ULL, 0xF9BE3AE655C94D32ULL, 0xC9BF3218CE93EA51ULL, 0x60A7B20EEB613961ULL, 
            0x351C2EDADE7A9B48ULL, 0xEB61E7F558066F20ULL, 0xD93ECACD00B5B79BULL, 0x08E0DAE654965594ULL, 
            0xA01F52CAE8B38CFCULL, 0xCD79F0F6F3CC8D68ULL, 0x9E2D48F890EF5AA9ULL, 0x2D0486936BDA9CF0ULL, 
            0x3C959BEBA7EFC745ULL, 0xCD4766C856244794ULL, 0xBB5A8810260837CBULL, 0xFBC89E3A64387245ULL, 
            0xD6365F3E0DCF5DB3ULL, 0xCCBC993AA6FE5646ULL, 0xC3E88969B40D3A10ULL, 0xC0BE5DDE81F0FABDULL
        },
        {
            0x40780ACB408BAA75ULL, 0x857CD0E445D01007ULL, 0x7A90503A31BB0EE8ULL, 0xC89579F09EFC79A2ULL, 
            0xE95F32DEFD125122ULL, 0x23772F7698EFDA78ULL, 0x926235EE96369248ULL, 0xEFD13E082B399281ULL, 
            0x52DB2999DD698E9EULL, 0x32CA18703573F5B7ULL, 0x87A8AF4B39370236ULL, 0x9D8AFD3D0A82920CULL, 
            0x3FEDDB63A00C6043ULL, 0x67836341529623AEULL, 0x76D34B8BB74C6D20ULL, 0x0EF57B80E9E82DE1ULL, 
            0x75FDAF5D298DB4CCULL, 0x7BAFB83BCF54A45BULL, 0x6AB2BCEE8BEAAEEFULL, 0x34277CCBFF3100F4ULL, 
            0xE03EBEC3083874DEULL, 0x466FA097417037ADULL, 0xB5A39FFFCFAE9505ULL, 0x041E603C17FF295AULL, 
            0xD76981BB2C74D8F0ULL, 0x03E8D05B38585D51ULL, 0x8469F44B64D580E3ULL, 0x1098C0E8CAE2DD4DULL, 
            0xE0F151C4386D3C8AULL, 0x16CD76D50CE62F6AULL, 0x3817DEF3997900A7ULL, 0xD5EAB3F078AF8D82ULL
        },
        {
            0x4DC35F41D3DD7306ULL, 0x267B3948BC79EB20ULL, 0x63D88833B8731D6BULL, 0x847E5A3CED758B37ULL, 
            0xE120FCB159921EF5ULL, 0xF90E38812BBD0595ULL, 0x1B6FF30A3488EEDAULL, 0x9C1010D8E3A7CFE8ULL, 
            0xA2FE6514958EB888ULL, 0xF4C5912889CDE453ULL, 0x1C31B5F45D6CDF9DULL, 0xFF5927443171E195ULL, 
            0xFF7716B2BA3CB430ULL, 0x5DC8C6B72BD9B188ULL, 0x420065F144175709ULL, 0x322FAA31FC5DEC0DULL, 
            0x20A49F56E59EB232ULL, 0xF4C1FE1948D4FC07ULL, 0x772FC3848A382BCCULL, 0xE60C7977CD20FC2DULL, 
            0x352E39312DFB6314ULL, 0xD0100A95BFCB59FAULL, 0xACC416F2D70EA4F8ULL, 0x17C4CC47D8D632C7ULL, 
            0xB3C61B47BF296F2BULL, 0x5DEC1FBA104E0F39ULL, 0xC38980A5F4A7C814ULL, 0x1401461B5450E27BULL, 
            0xD517B22ACBE8101DULL, 0x18A3886B04DE60C3ULL, 0x56E747A65F72282FULL, 0xDAF959F7F34808E1ULL
        }
    },
    {
        {
            0x06F169D926DC4954ULL, 0x3E74493DA85EE24FULL, 0x23604F0DF9BC341DULL, 0xB1A895D70C7BFA21ULL, 
            0x889FB04B087970D0ULL, 0x3530EFE8B5FB13ECULL, 0x75468D51793FFDD8ULL, 0xB6BC1D16A18361E6ULL, 
            0xCC3547E7C776BAF9ULL, 0x8B9AF8825F23CB5EULL, 0x632866F95508EEA4ULL, 0xA50D927677DEDDCDULL, 
            0x82427C7D0AFCBCD4ULL, 0x0D4DAD56EC653328ULL, 0xB2D6FF248FD321F3ULL, 0x51C73871C2513A5DULL, 
            0x1AB178DB10AFC65DULL, 0x67B0B3147A74CD2BULL, 0x13A4BE2E6D7F4001ULL, 0xFBEAF48353EE2154ULL, 
            0x760BAFDA2D2020D9ULL, 0x251AF91804819774ULL, 0x749A4DB38753F295ULL, 0x86756A5241A935FEULL, 
            0x43EB79EA8431F8DFULL, 0xD7AB109D98CFBFC5ULL, 0x70D32DF8D01E0DE4ULL, 0x0FA0F5BC30A918CEULL, 
            0xB3268EAF1515D16BULL, 0x51DDE9FA9CA1F51AULL, 0x8E9690E873AD5EBAULL, 0x3CD2471FD3E33FAFULL
        },
        {
            0x44E31D4217F753C0ULL, 0xD1A86AB26B5BDBB1ULL, 0xA04266EFB283A063ULL, 0x4C92053A2ABE563EULL, 
            0x9DDDFB45E1C6CB00ULL, 0x92692E2284B26F8CULL, 0x584B38703D6DB425ULL, 0x5988056C610A36B7ULL, 
            0x07F07C043E76A612ULL, 0x8E5CCEA0C6EFF9BCULL, 0xF170A8A49750D277ULL, 0xF5F8FB55C554F359ULL, 
            0x73D5F89A2824FE90ULL, 0xE5D90744120B3775ULL, 0x570BDDDADCD8D15DULL, 0x0FA61F73022AE05FULL, 
            0x4A4B85F266BEF026ULL, 0x1F1863321A26D2B3ULL, 0xB11A65CDD19E51DCULL, 0x086C44C858518D9CULL, 
            0xA626D7E0C04572DDULL, 0xF647A4AAE3E65C2AULL, 0x28A8630F0D014C28ULL, 0x5197710CE89681ADULL, 
            0xF9D52A1F6E7E79C1ULL, 0x35413E3FA2EE7A1DULL, 0xA287775CA6BC5309ULL, 0xCC13F156F47E87BAULL, 
            0xF563B33FB43A3F77ULL, 0xD9491CEBFDAEFF04ULL, 0x051F006A163976ACULL, 0x4D3D66CA7FBF754CULL
        },
        {
            0x7DD3E3B85D9772DDULL, 0xFE68AA3AAB4F6972ULL, 0x3E97ED0F772DB589ULL, 0x8834FC08FE06641BULL, 
            0x4A7BFB552DD1EF62ULL, 0x59CB0262138FFCC5ULL, 0x5A102BE34A9F525AULL, 0xC422D9CD98255129ULL, 
            0xAEE4CE269F36CF89ULL, 0xCB2102253E3B1373ULL, 0x4839F8A023A4C189ULL, 0xCD48BA2D07E32AA3ULL, 
            0x7D0ADECE5648C0BBULL, 0x47154E15419933E2ULL, 0x86D248E03CFB3FC8ULL, 0x5F4E8EA9640E654BULL, 
            0xBC17652E2699FA8BULL, 0xD3695DA27EAB7FFFULL, 0xD5D1D21F14DA480DULL, 0xB63D960273F9C0E0ULL, 
            0x94817EEB520A29EAULL, 0x3FD85BDFB6D39C13ULL, 0x5160A6E7CA907881ULL, 0xF3E9C1F178FD008CULL, 
            0x2780C46318F2C6EBULL, 0x9102DB6E50D78956ULL, 0xC8A789EB5A76D203ULL, 0xF0F9F1D788F17EB4ULL, 
            0x61F8F0A601E632E1ULL, 0xC1FFFFB362D7602FULL, 0x9B4C0D61E4C39A5FULL, 0xAFF1591E9ACB73FDULL
        },
        {
            0xDB98C5B5E1AB53FEULL, 0x201C8FE3A94B9939ULL, 0xC9B317ED80856814ULL, 0x47B903CB256D5455ULL, 
            0x22E3A7AB6DF05E17ULL, 0xB9E0548689931FFAULL, 0x642F45974934FD68ULL, 0xCB0CE306853599A9ULL, 
            0x999C7A19DD3415EAULL, 0xDB112C813FA495BEULL, 0xB5C98DD502E46FE0ULL, 0x00BF19C060610DF2ULL, 
            0x5B3925AEF5219687ULL, 0x6C6BA6B989E46BFDULL, 0x98E3C39112BB2A87ULL, 0x9B71CC15AF796226ULL, 
            0x7B20EA448F2F241EULL, 0x45CF310A431999AEULL, 0x4B1E21ABD393AB65ULL, 0x010497804821D254ULL, 
            0x34388089189F11A2ULL, 0x1EAFABE7DF6C9B0BULL, 0x62A8201859F51539ULL, 0x966E02114F450459ULL, 
            0x14B21C422FCE0A3FULL, 0xCAF3B154572A9502ULL, 0x3E52E604FE82F678ULL, 0xD5BEBEB7DB38DA6DULL, 
            0xAC8521B572D1E41FULL, 0x4EE9034FDEC65335ULL, 0x8587721459C2FF39ULL, 0x28EDBD1744B5F591ULL
        },
        {
            0x1E98AF5C7E445C9CULL, 0xCF3B642BD1A54E98ULL, 0x0A469517290A2636ULL, 0x9F0173F439207BA0ULL, 
            0x0081DEAF3FABCEDAULL, 0x8BD316A64435694CULL, 0x58F9300097487CCAULL, 0xC1ACF244C1FAE94BULL, 
            0xDC841D4EDD95CF62ULL, 0x12F47049F92A3D93ULL, 0xAC1F7EC6FECA6DB4ULL, 0x6502B342A2C03144ULL, 
            0xD6A07D410E5F2EDEULL, 0x20FA6385A31A3036ULL, 0xD5F37EF9506FB5C6ULL, 0xC82E18AC1C7A2D96ULL, 
            0x94285A4DEB06FD3AULL, 0x221D4EF8184EA43DULL, 0xD608C2B8E54BBAEBULL, 0xD32BF2F58B662699ULL, 
            0x141C8620687943C8ULL, 0x07B9D40C3684CB99ULL, 0xE6110CB646B5F04EULL, 0x7222C4C13DAA00CDULL, 
            0xFF25CE4CF068032BULL, 0xC55F9E6364BEE29AULL, 0x8A64E38B941AFD5DULL, 0x88FA29F93723E41DULL, 
            0xEE56F93170C2ECDDULL, 0xB8484C3B4D71065FULL, 0xA018895DC9D40B4BULL, 0x8E2CFF856A3479A1ULL
        },
        {
            0xDE5F0189422DA3A8ULL, 0x6CCE3D357EFDF51DULL, 0x230914D598E56E6CULL, 0xB5F2B843827F8E54ULL, 
            0x712023AEFD4106A1ULL, 0x710380FA61752A76ULL, 0x57148EE98D07D796ULL, 0x7757468A8CE45032ULL, 
            0x8C8F0ABA6347DA94ULL, 0x98AE6872DB1D374BULL, 0x9F9D026EBEEBEC0EULL, 0x160C451E79847480ULL, 
            0x5709DA230829A8E2ULL, 0x087A11F724367567ULL, 0x445265D70BDA6B92ULL, 0xCE0990F32F50B4FAULL, 
            0xB3EE6A3AAD89574BULL, 0x45C21174E5528A1AULL, 0x1AA622E078DCE417ULL, 0x10BBB3FE8E51821DULL, 
            0xD423CAAA63EE1ADDULL, 0x7D1227F73759A651ULL, 0x9D2AD746EED60F8CULL, 0xD14FE560EF0E1B84ULL, 
            0xFA1501F685F06B57ULL, 0x57AFD0BCB6C52873ULL, 0xAC6DAE043FB9D48BULL, 0x2600AF248ACDF179ULL, 
            0xA42B0421B6CADB4BULL, 0xBEA1156346BFAA42ULL, 0x3DA3C3ACF4790498ULL, 0xA598ADEFD6C32982ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeySpawnConstants = {
    0x396C779168D45CC8ULL,
    0x31BE99CBC39A3259ULL,
    0xD3DF73BF5C9778C7ULL,
    0x396C779168D45CC8ULL,
    0x31BE99CBC39A3259ULL,
    0xD3DF73BF5C9778C7ULL,
    0xD60551539B6531A8ULL,
    0x7CB2EEBA0B10E127ULL,
    0xDE,
    0xA3,
    0xDB,
    0x5C,
    0xA5,
    0xE5,
    0xD6,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Alcor::kSeedSalts = {
    {
        {
            0x8606F2E688D5426BULL, 0xD6407A90A3B5A946ULL, 0x4D670939758CECE0ULL, 0xEF9789FC28C4E95EULL, 
            0x9B0B897E7247FE52ULL, 0x48B6421DF3B57966ULL, 0x315473B87080E407ULL, 0x9D6D0A9A051BCC0AULL, 
            0xE5955EB864CF84B0ULL, 0x69948BDC6E52FB33ULL, 0x75027621D689D135ULL, 0xCAC06AF67962ADA4ULL, 
            0xD3CD89808F6BDA3AULL, 0x7AA74B1792761E2DULL, 0xB570A7F927664F77ULL, 0xAEF44734520E4478ULL, 
            0x66F9D170771FE63BULL, 0xF8220CC7FAA6AC23ULL, 0xB1A9BB5423A24FBFULL, 0x772303F66E9B7926ULL, 
            0xB0BE4D4511F44650ULL, 0x540CFE715AE4B94AULL, 0x6488DA70A4078EE5ULL, 0xA7BB79C73B1F1D32ULL, 
            0x98529C55EAA61E2FULL, 0xA98B009F508B3B4BULL, 0x86AC06A3CDB4D6E7ULL, 0xC7CE90C08E3E3DFCULL, 
            0xA1178BBFC228309DULL, 0x2B6380E935B96F39ULL, 0x99E1CA2FB762F39EULL, 0x628B0253BB6E3691ULL
        },
        {
            0xD5AD5BB28FF03343ULL, 0x115A44EE113F8D95ULL, 0xE979270BDCA4A9C4ULL, 0x8A643781B1787B97ULL, 
            0xFE2E44CA5E25BB57ULL, 0xA9CD5AA618F013EEULL, 0xCC35A94ECFBE2C3AULL, 0x54C3B427F2CDDBF4ULL, 
            0x7939ACA19071CC39ULL, 0x5891E01710AAC5FCULL, 0xFC14E111FB72888BULL, 0x16869A0F6DB47AEAULL, 
            0xB10927E3E4ADF6B2ULL, 0xD57AF7E2A82FABD8ULL, 0x745192DA0C46433FULL, 0x3E218BBA2CEEDCE0ULL, 
            0x015C729FBF6BEFD5ULL, 0xBF2F9CA042DBD20BULL, 0x84075B6153484891ULL, 0x6BDD72EDE28445C5ULL, 
            0x7546854D7C6D8CFBULL, 0xBF8EF44B85690425ULL, 0xC466DABB0534CA95ULL, 0xE1294811AAFFBB7CULL, 
            0xBB9F18CAEF2FFC90ULL, 0xA60B8221991633BEULL, 0x059A9A778C3A5CFEULL, 0x9AE36BBB5BE22C2DULL, 
            0xC399E42229B45BEDULL, 0xA7272570925507B5ULL, 0x4D170F32CB6445AFULL, 0x19C0801B111A0DDAULL
        },
        {
            0x978384C414410278ULL, 0xB4436F8FD7373995ULL, 0x785648F49B80D64EULL, 0xFBF7EC84301EB664ULL, 
            0xCC1AD7D00FE7872EULL, 0xFBFFB38995300BADULL, 0x2169AF8888C5B611ULL, 0x52AFDBFD5761F5BDULL, 
            0xABED0AB1485E6CF1ULL, 0xAFF6FEC0262B2ECDULL, 0x62E158C3DE0FEBFAULL, 0x98BBEE6036B2FF7BULL, 
            0x32892A35717FB117ULL, 0xE9EDB7D0F0E8C8ACULL, 0x3BF6068DBD1A4E82ULL, 0xA9B7975F80556A0BULL, 
            0x4B9FFACDEB0B18FAULL, 0x41001129A9C5395AULL, 0x2DA7B1FD2CB77E96ULL, 0x4A2A77A03CA36ED6ULL, 
            0x7480A8FFE53DB2A1ULL, 0xD7BA2B0500DC3AF0ULL, 0x40028B3B0B65D007ULL, 0xB663627D43DB2BA7ULL, 
            0x58EF32379B386DD8ULL, 0x77204D11A748E437ULL, 0x4DC9EA80F9D43858ULL, 0x220C25AC869349DBULL, 
            0x30D5835191B87332ULL, 0x071C1D8D654B2277ULL, 0x873FF3F931432887ULL, 0xB4679DB1A843D485ULL
        },
        {
            0x1F859679FB5A565BULL, 0xFA38D1C722FABAB8ULL, 0x7FA5E4402DBDF4A4ULL, 0x16303805998197C8ULL, 
            0xB5E26563C64794BEULL, 0x09D4DC2362B356B2ULL, 0xEA5C1ABD4AE3760FULL, 0x84E6986AABD59E84ULL, 
            0x62CCC96EFE7E08F0ULL, 0x62F57146DEA2D09EULL, 0xC4C919C9917B668FULL, 0x246A44690F4496E1ULL, 
            0x7EF0F585346780F1ULL, 0x843A58296D66A8C2ULL, 0xE2F1D2D442F8F793ULL, 0x00BB6C21814D1F21ULL, 
            0xBE1084513CC9046AULL, 0x519E4182BE2A6E0CULL, 0x95A2F2F38AB90C19ULL, 0x535BD1F31A2059F0ULL, 
            0xC9B3337285C97ED9ULL, 0xBF8D99EEF00EABB9ULL, 0xB9B0BC9E46107FEFULL, 0x5F293F87334BC9A1ULL, 
            0x7E6774C73B707713ULL, 0x9C8DA33A3DE592ADULL, 0x2FF4C166FAB7DC1EULL, 0xFE9404BAA3FC1E61ULL, 
            0xEE9FDF54A141A5D4ULL, 0xE90B6519D394D76CULL, 0xA1498D7B5A245C97ULL, 0xEE6E0448A705CBDCULL
        },
        {
            0x0D88642D27ED924AULL, 0x377DF252C51101D7ULL, 0xD3F3D81D69DFE2F7ULL, 0xA4340F9780A80B96ULL, 
            0x81CE377BD69D2E33ULL, 0xEE0AB1FCD6FFBFECULL, 0x4ACDCFAB9618BD20ULL, 0xF8E5FE16F4D0DD24ULL, 
            0x2BAE49FC3EAD490EULL, 0x824C98D81106D031ULL, 0x5090F329C9B34DC6ULL, 0x1600656223A63DB2ULL, 
            0x07D3C14BD042FA08ULL, 0x1F96FA4732D524C7ULL, 0xDF61C546B09F3ABCULL, 0x2AAB922EE6C93BC7ULL, 
            0x30188A15DC285C3FULL, 0x540EACFF91D06772ULL, 0x66F2B91120765FC1ULL, 0x61E0E5234776F95CULL, 
            0xE79E74B7EBB00229ULL, 0x601E7FC7F71FF638ULL, 0xE7EB6F77D3F32AE8ULL, 0xBE769A43EB24D4AFULL, 
            0xCE77948C6A0863F8ULL, 0xF93F98AA31E51204ULL, 0x10FC4BFE0644C0DDULL, 0x2BFC2DC0133A4EE7ULL, 
            0xA6498FE5A2E22779ULL, 0xF65A2F9DB7E71FFAULL, 0xEF1784EDA6EC8D6DULL, 0x68AD0C8F2374BE8EULL
        },
        {
            0x3C9A4F34E2BD4404ULL, 0x1DEEC3E35DE24226ULL, 0xA8FC67A27651F989ULL, 0x95E2537739909BCDULL, 
            0xC85B466F90B3986AULL, 0xBEEC6824333F98FFULL, 0x2B4DAC93208BDEB3ULL, 0x9C4B5B8CAF980BBBULL, 
            0xF9227BDA4E668DD7ULL, 0x62E7B7778213FA58ULL, 0xF6E245554CA6E00AULL, 0x159B2C21F253AC41ULL, 
            0xBDE5D3FCBB45FA3CULL, 0x06514E54EBC0EA5EULL, 0xEDA951BC355B6D39ULL, 0x272588B0348C2EBDULL, 
            0x3C97305E3FDBCF66ULL, 0x0BA5EB864F0A5E33ULL, 0x0197F292E25343E3ULL, 0x7B487E5D95A16036ULL, 
            0x06CD871EC466F896ULL, 0xA58AFEF094B444F3ULL, 0xDD484D8B2BBAEAA8ULL, 0x0B53E4CE9E07B7B2ULL, 
            0x271E34B892388C28ULL, 0xA0BA2BAEEE82AB0CULL, 0xE6833E77C45CEF05ULL, 0x545FA88EB4E9466EULL, 
            0xE9F008C7E4138859ULL, 0x56DCDCEBD8C57503ULL, 0x7C8CB0237F337894ULL, 0xAF190559343AA090ULL
        }
    },
    {
        {
            0x684319F21D3A744CULL, 0x980631340797AE35ULL, 0x0E9AEC8867EA9B15ULL, 0xECA1E425F0A7AC84ULL, 
            0xCB39ED95D97CC90AULL, 0xA301A87ECE5A8DBCULL, 0xE2E7ADDECBF38790ULL, 0x07F03405AA6A0BFEULL, 
            0x9E0FBAF90AF2C0B8ULL, 0xECF278DB1DE81B24ULL, 0x8EE69A305BE27D11ULL, 0x6D239FA2258BBF97ULL, 
            0x7DF192AE0D254187ULL, 0x8CFFE3F3402961E0ULL, 0x6AE6A57E6AD40039ULL, 0x80ECABF6F3DEE983ULL, 
            0x6137D69565B567D1ULL, 0xBC2770C1F9A6F666ULL, 0x1A290E4F1F4602B6ULL, 0x3903A9B4D4B94EFDULL, 
            0x159D1C7530C60169ULL, 0x7C678B44F7AD1585ULL, 0x599DB3D7AA50A45AULL, 0xB5D10339F8A4E7DEULL, 
            0x4DAA71D5561D4AF3ULL, 0x5B5B32C24930FF9CULL, 0x2631E87D3BD91624ULL, 0x4313D87FA4060A92ULL, 
            0x3C647259E6999103ULL, 0x7E64464E5A70733FULL, 0x2F59865072CB3A9BULL, 0xD69EFA047F5074AFULL
        },
        {
            0x15B9AECF66315B30ULL, 0xD20ABDB9F34E52EEULL, 0x85BF5EE5E822A7BEULL, 0x8FE58BBC7F054A09ULL, 
            0xE1A83D543D4F698DULL, 0xB162654EB1E5D1BAULL, 0xDDCC948103BDD7DAULL, 0x21EC72332FF25A11ULL, 
            0x69203907A9DC75C5ULL, 0xF640DA314553ABC8ULL, 0x9B0640DCDB80D201ULL, 0x8994ED2BE0ADD897ULL, 
            0x47EADD2FF1FB44FEULL, 0xCAD6896EA2D110F8ULL, 0xDCB53ABAB37A473EULL, 0xD0A39526D6009D93ULL, 
            0xE9E1B1D5A784F616ULL, 0x68FED20F8C9379A0ULL, 0x918B901BDF0F5547ULL, 0x6D9DE7BDAC4833CDULL, 
            0xEB54C3BFEC46D0CCULL, 0x953638893E6A1462ULL, 0x11123B7FC7A72D0DULL, 0x97E68EA3F2845935ULL, 
            0xA4BEA406662817F2ULL, 0x596450F8DA91523FULL, 0xD446A08671A45726ULL, 0xEC67A5F9A3C4FEC7ULL, 
            0x10DC07EEF1DE6967ULL, 0xDB1C789C0B52A21BULL, 0x33BEAA700DADFB2BULL, 0xDEFAF8FD80A72374ULL
        },
        {
            0x17A66386805A8D1DULL, 0x8FADC745F8BB91E9ULL, 0xF029DC961136F2A3ULL, 0x0F72C4B176847EAEULL, 
            0xB21C81C376058607ULL, 0x5454FF2886C6D4FCULL, 0x5BCE0FF535316ACDULL, 0x3C4463EC8BEF08F0ULL, 
            0x5502282291EE5E86ULL, 0x29A7863A540170ABULL, 0x4B4A3EBC106131E7ULL, 0xF75380276B04D88DULL, 
            0xCC12DAE1DF76AF2CULL, 0x61FD518CDD65A63FULL, 0x4D7921FFEEC52029ULL, 0x1AF779ADA2D02D0FULL, 
            0x58567CF099AD5376ULL, 0xC8AD5C8C46DC4DAAULL, 0x5D05252F86E5E023ULL, 0x4E8EA35ADF2ED1C1ULL, 
            0xC0F263B5F901648AULL, 0xF9E836AC718D1C90ULL, 0xF152FD7DAF32765AULL, 0xA6BD23E8CF128F1FULL, 
            0xD37DAB543F73A1F4ULL, 0x511C1A0059856BACULL, 0x035F425A8C3EF84DULL, 0x484EB3B06F71C45EULL, 
            0x70381A51449E21FDULL, 0x3D4CF3D3DE44DD3FULL, 0x2F2AEBE2BA16DD95ULL, 0x194A8E0CC40F27DCULL
        },
        {
            0x22E0FBE710DF7284ULL, 0x9A343ACCEDEA1402ULL, 0x5487CC448CD7073DULL, 0xFF534AC99EC9619CULL, 
            0xFE7CCA192AB73B78ULL, 0xA6F3ECB91DDBB929ULL, 0xE712B5822BCAA6BCULL, 0xEC31251EC8D03B2BULL, 
            0xAC573CF54B1489F5ULL, 0x5157E35E0BEC8BD2ULL, 0xE868012FD45AB911ULL, 0x1D466F8727F76A12ULL, 
            0x65CF8E12D875BD4EULL, 0x72F27B3E5CD6029DULL, 0xCD30BB246F095DA2ULL, 0x5E5057670306B78FULL, 
            0x40F60A5EA031AE5BULL, 0x1E318ED2AD046843ULL, 0xD77C1C7E3723A18AULL, 0xCB6D56E89A577C67ULL, 
            0x90621D87C68DA6C9ULL, 0xB0D39FB5CD694980ULL, 0x420651E570AB938EULL, 0x6A1430B2F2EB94BFULL, 
            0x9F80B88A3AEAB8E9ULL, 0x132F57B0D3E13CAFULL, 0xC640466D93B5A060ULL, 0x92BAF184346027D5ULL, 
            0x4279C6FE72333E5FULL, 0xF174FA7F30334785ULL, 0x71A7FF4C4D0A0A38ULL, 0x75AA4138C164E3CFULL
        },
        {
            0xED37E4852FA80B04ULL, 0xF423973666FFAF46ULL, 0xC0FD5E55A2077DAAULL, 0xE31CEBDDC6832B41ULL, 
            0x7202BE5B8B3AC76AULL, 0xB037CC7C714A06C6ULL, 0x7A5859E2FB53CF47ULL, 0x2CE772B0A63952B8ULL, 
            0x8B38CD06BB0F63D4ULL, 0x5EA9DD2DC5254A75ULL, 0xD8468D7BEB543A15ULL, 0xEFE3A7CF7218488AULL, 
            0xD22392489E91801BULL, 0x2D7E5F8D93D34DD9ULL, 0xBB621F17E2CD6983ULL, 0x2D27D0D34F498199ULL, 
            0xFCB6CC2F0228AD6AULL, 0x1BD50DE5E7B68404ULL, 0x4233FD07127B2383ULL, 0x4DE24709FBB555B2ULL, 
            0x5FF7E0E7FDA63E4DULL, 0xE971C1DBDEA3DA1FULL, 0xD27DC4963AD4866FULL, 0x8816F4A93FA60112ULL, 
            0xE52FB1D330C3AE94ULL, 0x16733F0BA179FB50ULL, 0xD35E286B1A370CD5ULL, 0xBFF615C0A6285B4AULL, 
            0x2D26314BC1EB77AAULL, 0x1FDB2FDD8A8D9E19ULL, 0x1D43AD9E08485C83ULL, 0x411DA354CF0A3A61ULL
        },
        {
            0x204175162AA3F681ULL, 0xE790AC9ECE73134BULL, 0x45BB96A6DC874DE2ULL, 0xF70A01BE6746459CULL, 
            0xE0A760398DEB4F8AULL, 0xD715CA3B4D979BA7ULL, 0x0FAE1619E28E16B2ULL, 0xA75BC0AADAFCD26FULL, 
            0x08B49031460ACB37ULL, 0x416E35DE1AF6EEFCULL, 0x46FD0CD67919ABDEULL, 0x21F7376EC38B59AFULL, 
            0xA31AA9F8CC827655ULL, 0x9F4C1838D2FD1FC9ULL, 0x9A2E190B753924A6ULL, 0x6262DA84F75EDF8EULL, 
            0x283E5E9EDB5A9DB0ULL, 0xD46F106EC6BDD1F4ULL, 0xC28FA1086C66F74FULL, 0x1EA928F555A04335ULL, 
            0x1BBB2E2F2DCF7C88ULL, 0x8482C5A46EDBC815ULL, 0xF1AECB070FCB07E7ULL, 0x6B4B648B5BBB3954ULL, 
            0xA14D89C06DE429ABULL, 0x0D913599B8960474ULL, 0xCFACEF90A607CB21ULL, 0xBEE1A3841884E161ULL, 
            0x9B1D901A59BA8706ULL, 0xA29D59C30C73269AULL, 0xF09FC08BF9B6F54EULL, 0xDF4934525A191A54ULL
        }
    },
    {
        {
            0x7E9EA8674410FFCEULL, 0x56873613FB8799E2ULL, 0xB8D77B54329CF898ULL, 0x22327621CA99D7FAULL, 
            0x8AA620646E7DD90AULL, 0xBE55910D53F0C925ULL, 0x8913507D2C704B25ULL, 0xD9EFCEFC0D5719A5ULL, 
            0xECD36AE9AE22A33BULL, 0xFB2737C3A47758B9ULL, 0x823D4604A6D6C289ULL, 0x2EA7F0B78BBB7697ULL, 
            0xFBBBC0F2D770586BULL, 0xC7FE6819B14A103FULL, 0xFF9821E3FD9F825CULL, 0x3E79F6040090A1F1ULL, 
            0x29BA8E3CFFAAE409ULL, 0xE4A11990E7CC36D8ULL, 0xA247FDE81EFD5FA9ULL, 0x65CE44C6E4BBC11FULL, 
            0x5FD34D34494EFB86ULL, 0x3062EAD8BAC8907AULL, 0xAEEA2B535E8FC10CULL, 0x6312B13BA9ED6F6CULL, 
            0x7F2A9B534493BAF5ULL, 0xED185FB41E7C0FE7ULL, 0x5769DE667F195DCAULL, 0xD6487BB4148F7AC9ULL, 
            0xCFB2EF775B69CA02ULL, 0xF27C26EB09F24C84ULL, 0xB869BFC4D0BD7342ULL, 0x6E97F6D791C2316DULL
        },
        {
            0x74AF932B192E4E1BULL, 0x83AE28EC6A6D2608ULL, 0x41DDEF0C311554B7ULL, 0x9064FBA0A4CA89F9ULL, 
            0x5C719A4A6675A2D6ULL, 0x25491C8ADECE1EA7ULL, 0x11C9944D59D39984ULL, 0x221D862451ED1C54ULL, 
            0x5E3DBF408142A743ULL, 0x04184868E11D9352ULL, 0x0462FFC8127D6E87ULL, 0x42E78682EC26909CULL, 
            0xA1D8BF91CB62F453ULL, 0x47E7EE3145E3F5DEULL, 0xB21164A8713AC4F8ULL, 0x6DA2881F9F847284ULL, 
            0x6F14A5EBD828072BULL, 0x29F05C31DDA93BB7ULL, 0x0EF55CE4739F9993ULL, 0xF71252C96E905BB8ULL, 
            0x615A64F7EA3F3873ULL, 0x5B370901B63F8BF9ULL, 0x8A2887F72CA2DA53ULL, 0xC98CCE12757B6579ULL, 
            0x43FFD04A3C7220C4ULL, 0xEE1F1881AFA0144BULL, 0x8817D3DB813A3BF1ULL, 0x95397AA472582AF9ULL, 
            0x45E4B611B5912FEFULL, 0xE8556BBF35FD83FBULL, 0xE51E0C82AD31D261ULL, 0xDBF6628E7D16D0FAULL
        },
        {
            0x1BB6682C61F1036DULL, 0x78914CB17C677FD1ULL, 0x3C60380023C1351DULL, 0xBB7FF9DBEFB9C0F0ULL, 
            0x9550D5F250724023ULL, 0x3D4E9C6BC5032412ULL, 0x2ED9EB599E944539ULL, 0x0E13A2038276170CULL, 
            0xF3C07C6AB3EFC34FULL, 0xC19A85FB5FE93B21ULL, 0x18371A7FE63BC6D2ULL, 0x40B5F8B48471B20DULL, 
            0xB80EF09956C0E842ULL, 0x6DD00E591B3C70BCULL, 0x0D81A2FD011473FDULL, 0x5A9C7BBEB2044F3DULL, 
            0x46AF37C1A6281AD4ULL, 0x1E90C22C7B4E7EEFULL, 0xD9D9A2D0A37CA3EAULL, 0x4AF3187C240DC107ULL, 
            0x09B0398AD85CA59BULL, 0xCA9A0434AF861B0AULL, 0x8F686B0A163444FBULL, 0x32DA37C6FF3727E1ULL, 
            0x81FD080D5ECAA038ULL, 0xBA7D4C1EFC9177B1ULL, 0x7ADA4F70C3F519E7ULL, 0x652A85857709EE58ULL, 
            0x9DF7C10C3985821DULL, 0x8CF9895CE5E34740ULL, 0xA4B6D4E3E143B230ULL, 0x8E265B0591E6A0A0ULL
        },
        {
            0xC03439C4F7FAE137ULL, 0x79AE35B85DAA82A7ULL, 0x175F3A1C534CF773ULL, 0x3EEFA178029AFCB1ULL, 
            0x9BB090DAA7CC74E5ULL, 0xD45A4DE284CF4911ULL, 0xF625574BA7854EDBULL, 0x9E3D62EE9897C763ULL, 
            0x5F877B380F0213B5ULL, 0x0B218412CAFB486FULL, 0xF4ABF7FBB2BF46C9ULL, 0xCB25B15E4147425EULL, 
            0x08359449A06AC556ULL, 0xBDF6598759333DE7ULL, 0xEBC65FC28A56D0ADULL, 0xB7E95FC5D333A598ULL, 
            0x866234565BDBDA4BULL, 0x0FC4CB34CCD79D8FULL, 0x1670D5BF22DE61BCULL, 0xA77BBE64B30DD0DDULL, 
            0xF2BFC0DCE5116ABAULL, 0xBAA275035C7C46DCULL, 0xB60EEEC0CDD7631EULL, 0x4445672F3EF2469BULL, 
            0x36FA8309C4E5E9E9ULL, 0x654B7CFDFC2148B8ULL, 0x504AFAECC9D4AA9FULL, 0x369FBF060A25EBE7ULL, 
            0xE87AAC849C5E6568ULL, 0x91F341DC7902BD22ULL, 0x757539A1F7380750ULL, 0xB9DA5CB4F780B271ULL
        },
        {
            0x922F003B257CECF7ULL, 0xEC11E8BB59EE670CULL, 0x2D1AF792C3C7480AULL, 0x4CC84EFCBD28692AULL, 
            0x54AF233E932E1E58ULL, 0xB6704FC26CE911ADULL, 0x6F84A131CF5D00E0ULL, 0xE456F824CF6FF57EULL, 
            0x5F44526F18EB9997ULL, 0xDACE59D43F23C467ULL, 0xABE9827F31A1C8A0ULL, 0xDB8C495F05E86559ULL, 
            0xDADBC7B93A2B905FULL, 0xD432E77E0BAF5B8BULL, 0xAC557F88E1215918ULL, 0xC20C08F340C4DB1CULL, 
            0xBB595AE7CA1303F9ULL, 0xEF795041BDCCE34DULL, 0x11684838131D73FEULL, 0x197ADA6C6CD93D3BULL, 
            0x1C0F479647872F86ULL, 0x799E818614C40540ULL, 0xB060D8896B8A0EA0ULL, 0x91AB4ABE5490A5EAULL, 
            0x9C59FC0FDB276526ULL, 0xDB4BCAB7CF416538ULL, 0xBBDF3FAD9FEDD5D3ULL, 0x471EAAD29619D36EULL, 
            0x032B84A2C478297EULL, 0xC40128F0E9279164ULL, 0x232AD3845C7ED071ULL, 0xB9A4D6B692C191D1ULL
        },
        {
            0xF1E81B21DFA9E557ULL, 0xB1A48F40640D09F4ULL, 0xD12A2C6CE87F8913ULL, 0x25F1C7F738B7DA55ULL, 
            0x33B470F1D3CA79B5ULL, 0x73852C067955358CULL, 0x1CC30F1AA5F1422FULL, 0xDFB35B8A102C6365ULL, 
            0x1BBF05439C07DCFAULL, 0xA0D640B8F251B16CULL, 0x22DE5A174754E571ULL, 0x15B6842B9A778A30ULL, 
            0x50BA66EF6132CACCULL, 0xB858C9EEDE3F52D0ULL, 0xBB45EDBC2524E7F7ULL, 0xE16611AC1001B6ADULL, 
            0xD3858359F48CBD72ULL, 0xF851DACDA33ABB2FULL, 0x213A190E2DD364BEULL, 0xEE250C1351EF3A69ULL, 
            0xDE0F0341D5A2DB65ULL, 0xE7C5682953C62E68ULL, 0x013ECD01EE9F91ACULL, 0x659BECD0EA1AEEB7ULL, 
            0x4B380FA4DA7C46DFULL, 0xC5CAC91806711ED3ULL, 0x7BA391F2277985DEULL, 0x51C1B5B854E726CCULL, 
            0xC1541C61FFD33CE1ULL, 0x6B55AFC8F6DD0827ULL, 0x6A54F882E1EADFF3ULL, 0x67410F64F5403CBCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kSeedConstants = {
    0x20E5683C358417F9ULL,
    0x3E68460D6A21A2B4ULL,
    0x4E0F25936E394727ULL,
    0x20E5683C358417F9ULL,
    0x3E68460D6A21A2B4ULL,
    0x4E0F25936E394727ULL,
    0x3368178905B9A17FULL,
    0x5A7E36946D6110D0ULL,
    0xDB,
    0xBA,
    0xD4,
    0xD8,
    0xB5,
    0xD9,
    0xAB,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Alcor::kTwistSalts = {
    {
        {
            0x1E5514DD11DBA5C7ULL, 0x30A133D89659D402ULL, 0x1770BC66BCA43A73ULL, 0x33DE20B37112D22DULL, 
            0x08D31F2C08C1E668ULL, 0x571A431EE9D7148CULL, 0x61D96645844BAB42ULL, 0xC5906546B8ABF177ULL, 
            0xBF946A2275954A95ULL, 0xE997DD1FC452A415ULL, 0x8BEC8815450094E9ULL, 0x510EFCD011C3ED95ULL, 
            0x42386ECD9E77AC7FULL, 0x44B2112A89E67666ULL, 0x492BAD0D344192C2ULL, 0xCEB240B3585ACCB0ULL, 
            0xCD17D8493437BCD5ULL, 0x840484CD6F106670ULL, 0x1BDFF22181658A84ULL, 0xF88EFFC59FC719ACULL, 
            0x606918E77EFF8F40ULL, 0x851A08732E43EBD6ULL, 0xD4CED1065FE7B810ULL, 0xF0D8D7706192A561ULL, 
            0x8B80748E5C907C23ULL, 0x51D4477239306EE3ULL, 0x945FD8060FEFFABEULL, 0xC15D336A8F86465FULL, 
            0x57873D040BC17E48ULL, 0x6136FE7A3D50CD6AULL, 0xC415FDE13985756DULL, 0x8FB05737E6B1D340ULL
        },
        {
            0x8AB22A46EA3D77E9ULL, 0xAF5409E3311613F6ULL, 0xBF2D1E42D7447189ULL, 0xEC21268AC83D2919ULL, 
            0x3BADF8E83EA5C5C0ULL, 0x7AE8A1D3A67BC64AULL, 0x3C2853260B821A49ULL, 0x7A55C4DBFB988219ULL, 
            0x7C7772AEAE8681B2ULL, 0x2E21DCA33EA61650ULL, 0x04B1EFF849D6430FULL, 0x228F2F9E63AF8B0AULL, 
            0x6950EE1E919D44ACULL, 0x0D1449E2C622C886ULL, 0x3605860C4BC035E2ULL, 0x98C00D07C0908CE8ULL, 
            0x4B4D36ADEBA99D82ULL, 0xCF0ABC5BBCC4EB31ULL, 0x683783AD4F633BC6ULL, 0x71468CEC1C984B31ULL, 
            0x39F83DC4C5BD6C11ULL, 0x1EA12B4F1721E346ULL, 0xB99C043FC330824FULL, 0xE3EFD6E63C7F9386ULL, 
            0xBC932EBC84518419ULL, 0x8D471E1C5A8B1DB4ULL, 0x7F7DCE2E8D4AD36BULL, 0xC8E526FFA9B5B8F9ULL, 
            0x9EEAC8054BBB555AULL, 0xA8331886FBC0869FULL, 0x7EBAFD8EABAF3AEFULL, 0xFB949E402E68BEEAULL
        },
        {
            0xCEB4A782DB0C40FDULL, 0xEF54B071D3C495CCULL, 0x03919A2AD3C52F98ULL, 0x8134AA558708BBC6ULL, 
            0x5ED902107EC20828ULL, 0x058C9954134697E8ULL, 0x09B719CD47C3F770ULL, 0x54328B4690A7E4EDULL, 
            0x4EB47628796F0E83ULL, 0x4FF02F4435CB714EULL, 0xAA46CBBF0C554EB2ULL, 0x9DB1BAB2CE6AE5ACULL, 
            0x30C6425D0F2C5A31ULL, 0x3702A39A193ADC80ULL, 0x7841A4AF16A19A62ULL, 0x41655C96786755B1ULL, 
            0x228988529B4A308CULL, 0xE98E7CC3522FE83DULL, 0xDEE77C933034D214ULL, 0x4CD27CBFB733D201ULL, 
            0xFE616D66BA28BB7DULL, 0xDA72F004EB6C9327ULL, 0x696B0ACF63426061ULL, 0xEB739730BAD7806FULL, 
            0x28D3F8CA2D2AFA8DULL, 0xA79113A5768FB55EULL, 0x8F55B9DF424D80A4ULL, 0xE134006D357D8F3FULL, 
            0x5468A14607B74AA7ULL, 0x8C2D5EEC71F7C857ULL, 0xAD77B06E9F5D582EULL, 0x5BC407E04F41BCD7ULL
        },
        {
            0xEDC4DFA5D90CF673ULL, 0x45C44A2438A6CDE7ULL, 0xFA9578E5E04F521BULL, 0x60A2B78ACADFFE91ULL, 
            0xBCBB76D2F771E00AULL, 0x356C3DBCF9DFC700ULL, 0x5A4F17984F675116ULL, 0x12C2C502A9BF0DBFULL, 
            0x0F391D14134114B4ULL, 0xD019409883533FA0ULL, 0x7000ABE02ADD69C5ULL, 0x5700921625BDE88EULL, 
            0x0063805C688ED24AULL, 0x7832BC5B14E82E51ULL, 0x328A13DB2D788DA3ULL, 0x480BA91AE57457C9ULL, 
            0x5A1F82DC0328EF80ULL, 0xC75CAA4DCA9A5F0BULL, 0xC6256D1DE5AAE268ULL, 0x183C861664F9D1D1ULL, 
            0x1100B9CBA0B9013FULL, 0x2EEA99ED0B856E5DULL, 0x399476929E766BF6ULL, 0x8986E181B2451F0FULL, 
            0x564B3C893C0B6759ULL, 0x601FD6A81B469E02ULL, 0x28AD5E497A4A0A12ULL, 0xD5BFFE683B0D4E80ULL, 
            0xAB19C68030F27C2EULL, 0x29412BA1DCEA8FE4ULL, 0x2F7CE19327BBDDF8ULL, 0x29E73C9E86DFB93FULL
        },
        {
            0xC7F167A4C285D20EULL, 0xF6BC9E708C1CDB52ULL, 0x0B32E86BEBC8C3A5ULL, 0xC25B3F34D0B4540EULL, 
            0x5E84FB11F8313852ULL, 0x23FE0A918A66F2B0ULL, 0x2DA2A63B797B411FULL, 0x645476D41F28004FULL, 
            0x30EE7364CA10E169ULL, 0x696408B934C2AD8FULL, 0x1957414BB0C959E3ULL, 0x3EA4CA68C2F30A69ULL, 
            0xFA1F9E07426F7BD1ULL, 0xBAD9189969F0C198ULL, 0x5CAA28561C6F7640ULL, 0x875F186A0C9A4B92ULL, 
            0x088006B3A49BF756ULL, 0xECC8D64CDC4F560FULL, 0x22FB9AFCE4844358ULL, 0x254061017EB3A115ULL, 
            0x73B78C6402530CE1ULL, 0xA13FC2084F30791BULL, 0x06B59578C255DAF3ULL, 0x543315B0C4B48C31ULL, 
            0x93436D398E1ED4EEULL, 0x5B1FF110556E4A11ULL, 0x6757067C03ECE6D6ULL, 0x91F56423873A152DULL, 
            0xD114CBCD71425870ULL, 0x6230327961CA324FULL, 0x100C700795C59CEDULL, 0x5EE6D5DBA83191A9ULL
        },
        {
            0x142C465639A1FBB5ULL, 0x5404708BD2EC62D9ULL, 0xB5FAA72B528E7B98ULL, 0xDE98EA58ACA7E44AULL, 
            0xA55559FAA4D616DBULL, 0x1B7C91E53ECCEE78ULL, 0xDBD81E5BF974469FULL, 0xE798234064B45435ULL, 
            0x5E003719DF24AE87ULL, 0x0E50F4115FFD7DD3ULL, 0x8C0FC4C51E477E78ULL, 0xA60BBB3C9C019C95ULL, 
            0x7E95A20700C62632ULL, 0x0876F86DFA8912E9ULL, 0x3765E097E83ADD28ULL, 0xB3DCAAE659BD351EULL, 
            0xF5EA8B62BD0623EDULL, 0xE6145CD811EEBB9FULL, 0x17155FFD6597E350ULL, 0x696451050CD257DEULL, 
            0x2C86426D03C560F4ULL, 0xC363E2A89249432FULL, 0x199563662010F88AULL, 0x6FE87A12E4CAA536ULL, 
            0xA9DD09F5B127DBFCULL, 0xDA1C962EDEE01FBCULL, 0xFAA08CDE58101907ULL, 0x815401C033090269ULL, 
            0x6513FB2DE049E9DCULL, 0xFEACCAD3F71E99C4ULL, 0xE744A1A300052995ULL, 0x73E7A57D7282C6A6ULL
        }
    },
    {
        {
            0x5BFFFCCF87DB3E08ULL, 0x7E5ADFB286823DB3ULL, 0xB392EA8EFCF66678ULL, 0xE91207B2A01890C9ULL, 
            0xB3DA19A75C4252AFULL, 0x00DC70B873FFCB70ULL, 0xFABAB2814F30ED7CULL, 0xE6E8898124CFB0DDULL, 
            0xABC4A79319D0021AULL, 0xC139200A280C2EA8ULL, 0x4C8EBC9C096350FDULL, 0x724BCE99E58EDAC7ULL, 
            0xA3BFD98F3EAAEA9CULL, 0x50270762FAB5FE8CULL, 0xF4CEE54AF607E5C9ULL, 0x1407403D357D2F31ULL, 
            0x7CBD9F7353EE6C9DULL, 0x69A0DCA61E8F61F0ULL, 0xE62082A469F33A80ULL, 0xE64754DE5EFFCC87ULL, 
            0xDCDC806A8F3A7D28ULL, 0x39ACBEC7CAFF904CULL, 0x984C5047BA311217ULL, 0xE41D09A910D4A688ULL, 
            0xD173F8B31D822703ULL, 0xF298862E4DFC0B20ULL, 0xA0714C71D4FA5C82ULL, 0x7D698B24FAEF5DCDULL, 
            0xA832105A834C10A3ULL, 0xAFDFE8FC4FF738A8ULL, 0xDBD9F4E12E7E9E3AULL, 0x0E00A463007853B2ULL
        },
        {
            0x29232DEF85DEB46BULL, 0x5F3E23364165D9C0ULL, 0x0FA2CAF0F564646EULL, 0x5A7ACCED53DD057DULL, 
            0x329EEEE7F375D2ADULL, 0x846C9621B46D4C20ULL, 0xF67F7A1E3592B95BULL, 0x9E34DFC5A37066FBULL, 
            0xC32F03463D40E4FEULL, 0xC15173270BBD2A3AULL, 0x19E5ADADAF45F76BULL, 0x8D4AAAAAE8F92777ULL, 
            0xB84D38F88A69E3B1ULL, 0x39D879E7B143379DULL, 0x457FB67A330DAD27ULL, 0xCD1C1E0B853E90C7ULL, 
            0xF1AB4CF0D21AC74DULL, 0xFEB1C7E608F0F35FULL, 0xAEB152631DE9FEEEULL, 0xDF256C523D8DEF36ULL, 
            0x1850A14A7823D7F4ULL, 0xBD787CD193B00265ULL, 0x36128047677D1E8DULL, 0x1ED76243B3E40BF8ULL, 
            0xAD4BC1D668EA83E8ULL, 0xAF56DB330CDE3E07ULL, 0x3D4C77B2DAA1FAA7ULL, 0xA6E0D00783F6A138ULL, 
            0x953EB841F8728B88ULL, 0xE3744400AF80F4AAULL, 0x99785037872DBF44ULL, 0x82F4CB19ACDF92B6ULL
        },
        {
            0xEFFA609013DE00C3ULL, 0x09A071B4C0150774ULL, 0x78BD4F8D68D279C2ULL, 0xE8AA3884BA9FEEDEULL, 
            0x34261994855DC2C0ULL, 0xC40A7657A5785310ULL, 0x845209368415208FULL, 0x3B44165260F9EAFEULL, 
            0x883DD15F8C489AE1ULL, 0x90CF2FDF7624EF72ULL, 0x0ED2A572A7A44253ULL, 0xAAED7111E75445CFULL, 
            0xD7C74A64FEA019F9ULL, 0x1D1D44892C078E7EULL, 0xA7D2D691490A8008ULL, 0xF6E4CBFC8789E9CFULL, 
            0x3F00C5D24577F56CULL, 0x79F90F13333CDA2EULL, 0x829DAA7B1381771AULL, 0xB7F54A3797B7F30DULL, 
            0xDB43FB8CDB1E7AB6ULL, 0x6AC4610630A36AE0ULL, 0x93ADBA016A3AA5C9ULL, 0x74E354781F6C903AULL, 
            0x7A12D9D8F5774AF6ULL, 0xA1C7C270D286A3F3ULL, 0x4076CC9C0B88B0C3ULL, 0x2F2AD5EA7A3507A6ULL, 
            0xF192583B208E0A5AULL, 0x803EA01BFF09A6C6ULL, 0x25764CBC2FC970B3ULL, 0xBCA4EB048C410483ULL
        },
        {
            0x095190801B20642DULL, 0x483C18B0B303F91BULL, 0x12589620D89A866BULL, 0xDC19D017CEFBBC20ULL, 
            0x34C6851C752782A3ULL, 0xC5C9D48913434E6CULL, 0x4BCA4E214FCF8EDEULL, 0xE5AD23AACB928394ULL, 
            0x4027637A04A03B5CULL, 0x599FB9D3E501D02BULL, 0x278CA7381742DA56ULL, 0x48D1443AA40F11B2ULL, 
            0x5F8329FAC467F6FBULL, 0xDAE297EE76B6549CULL, 0xC52B9CA8C37AD0E2ULL, 0x94FB6761FBC36730ULL, 
            0x7AA8EC9EE0F7B79BULL, 0x8A375F4D66BD4FB5ULL, 0xB0F95528BEDABED5ULL, 0xD5F7937634C98E5EULL, 
            0x6A4F9A79F0BFE77EULL, 0x10588ACEDAAE814AULL, 0xD091DFC5F5FD6A92ULL, 0x0734F5D78D916E8AULL, 
            0x60014852BB3316B9ULL, 0x50D5326EFCD81B6CULL, 0xF569F50FE7B93966ULL, 0x5C3E243B9371356DULL, 
            0x895997EE61412061ULL, 0x7AB29673B1BEF51DULL, 0x8B455E245FC10858ULL, 0x51028FFAD94BE80AULL
        },
        {
            0xA8B1EA9B04EC9E20ULL, 0x83C473952977B319ULL, 0xED1F413794262FC9ULL, 0x49BE0E540E3FF76DULL, 
            0x82A70608DCEB6171ULL, 0xA4E246BE58A3879DULL, 0x4F9E1539B8C3E9D4ULL, 0xA4F5176C5DB75DBDULL, 
            0x83CF2B6BC9364A94ULL, 0x57C41735F4D2F3FFULL, 0x2CBE242615B0328FULL, 0xD0A2F8308F35B7B1ULL, 
            0x710D340AA2BAFC04ULL, 0x0A1751430DB04FC2ULL, 0x3E454D7C404D591FULL, 0x49D2D2BB89ADAD2AULL, 
            0x0B0E682412A6280DULL, 0x496D3AEBF9964535ULL, 0x65AEE56BE7D3DF4AULL, 0x135B3A0999D2BBC6ULL, 
            0xA20840E3E0A5D422ULL, 0x657C3CB9404CD984ULL, 0xB8B47707150269A6ULL, 0x78295EF9DFF434CFULL, 
            0x0C45EEAC563A4D50ULL, 0x1F6CA833474469B8ULL, 0xE94768D8F6D0CDB4ULL, 0x36AE9D41E2674ADCULL, 
            0xC85B6F3DC8691CCEULL, 0xF6AA480D4D08F6E8ULL, 0x691825850EF30B6BULL, 0x7EBFEC62A62B8ED0ULL
        },
        {
            0x03B499BB52EE6961ULL, 0x7EB5DC8CE24FF3B5ULL, 0xA0BF77481A2D731AULL, 0x2E17B38BC41D6363ULL, 
            0xAB75395AE333AEAAULL, 0x46DEB3F88EAD0AB8ULL, 0xBF986F50881F2441ULL, 0x0E1C92E6D638E2B5ULL, 
            0x9B9100CE7D66B870ULL, 0x683A5446EB7CB693ULL, 0x33CD8770787C882BULL, 0x79FBA68A8A8BB340ULL, 
            0xD39ACCFDCA798827ULL, 0xBFCBAD079A7152C8ULL, 0x931E36B00910005EULL, 0x1F8A1023AD7DDF5FULL, 
            0xEEC128FD90A17E69ULL, 0x33201385AD7C45BFULL, 0x2B382F2FED86CE16ULL, 0x840DAD821401B862ULL, 
            0x61E3476CD3CF9D3BULL, 0x45781FB231765471ULL, 0xE26B56BA60B0908CULL, 0x261D9364ED92030FULL, 
            0x5E9BF1B008B50504ULL, 0xF5AACC0E1B022DA2ULL, 0x067FE6EAD4AD39DCULL, 0xAE1E18C8393891A4ULL, 
            0xDD02D2956C9B0B71ULL, 0xC7518DFBFE0470E3ULL, 0x0ADF5FC521DE4011ULL, 0xB18003C8333B129BULL
        }
    },
    {
        {
            0x6B6BF2B0C67FC7D3ULL, 0x4BBFB03A89727EC0ULL, 0x0A7480623BB0CC4DULL, 0x3E907E4471C2E6B7ULL, 
            0x1FB62450517804BBULL, 0x10EE7CB1EF16E501ULL, 0x83E299253654F1B7ULL, 0xD0082B30A90D28DCULL, 
            0x6D357846015AFCF9ULL, 0xD32F09DD8848EA22ULL, 0x20D745413A99E5B5ULL, 0x4C9F046BD47254EBULL, 
            0x0CC1640239040A75ULL, 0x3CE08CAA253D8AFEULL, 0x66CF30EC2289CCAEULL, 0xD7AE1617C776730FULL, 
            0x2367884498227B9FULL, 0x7EF6951760D247BEULL, 0x1672CB44BE6B34ABULL, 0xE18CFD161187B4F4ULL, 
            0xF61908E0FBD46851ULL, 0x5A8487889B977245ULL, 0x0F7DA8B2A9D9F199ULL, 0x189808E3BED43DBBULL, 
            0x7A46D8F10479A658ULL, 0xE7E7B6A8A59955D2ULL, 0x9E9971B13BBE5D6CULL, 0x75351B3F0B1D4259ULL, 
            0x1AC5A1598D5C8933ULL, 0x9503453A7547277CULL, 0x815631D1A99B6703ULL, 0x7BE493E06496A736ULL
        },
        {
            0xC95560A2B225C413ULL, 0x9C1795A5986A2CB9ULL, 0x33F2E1040E6928D2ULL, 0xCD072E5597BEB248ULL, 
            0xB95B1CADA90583EEULL, 0x341B84308A8690FAULL, 0xE2ECF5C1DC29673BULL, 0xAB04ADBAEBD10FDFULL, 
            0x8182A034625E0335ULL, 0xC828DF27974945BCULL, 0x67C7908A4A0A635EULL, 0xAA35812E9E60DA52ULL, 
            0xCAF89554E7C6EE79ULL, 0x61DC5EDB955F054DULL, 0x5E6A85DCB901B8CEULL, 0xA5276F9B6E4315EEULL, 
            0xABAB9A7C9243D1D9ULL, 0x6BFF2FE17ACA7FC2ULL, 0xFBAE1C84B1C733A5ULL, 0xD420D506406C6BF4ULL, 
            0xF80835F2897492F5ULL, 0x83D712713E28803DULL, 0x09DDB27E11F6A26AULL, 0x6270593FDFAF0EAAULL, 
            0xF8D03AA7662D0524ULL, 0x624227BC6F343C6DULL, 0x139B15FDFBBC43C1ULL, 0xC2715C8848D52DC3ULL, 
            0x6C778B8C711E961DULL, 0x9AC5DE4E13320C2CULL, 0x9D8694508839D4F6ULL, 0x11D14451328D3846ULL
        },
        {
            0x8010A0F11B2C056DULL, 0x28D523D27469A97DULL, 0x98612134876ED7CAULL, 0x4F45FE65757BEF87ULL, 
            0x61A79EBE6E5FBB73ULL, 0x1C25E1D56E6E91A7ULL, 0xC73AA51091BAD3BBULL, 0xBE3B2EB0B501F0D3ULL, 
            0x1CFB1820EB11B1D2ULL, 0x7CDCA67B6D9ECDF2ULL, 0x58CFA9C49BE90777ULL, 0x538F3F324AA2C912ULL, 
            0x5FEC8B20E4394772ULL, 0xDC981CC1540872FBULL, 0x6EBDB1B77B54F5D2ULL, 0x5C74FA7B2365C54EULL, 
            0x0E65C80D099174A5ULL, 0x4E52B3D6F90E4AAFULL, 0x001EB0BF5AB135CAULL, 0x8305C28728E47680ULL, 
            0xEADCD0A6C3236C06ULL, 0x9F85E3FA7509015AULL, 0x4C4DCF61082842B9ULL, 0x345739DD9BEDCD40ULL, 
            0xCC02AC01ED088EC3ULL, 0x70FD4D0578B1514AULL, 0xCEEB17B4C97C6432ULL, 0x03241BF63B5EF22BULL, 
            0x8D8EE79A21792A2DULL, 0x4CB15FFA9C81A379ULL, 0xE0CC0A5E4A753726ULL, 0x34ED8050631B80B9ULL
        },
        {
            0xF56CB0A57B4D225AULL, 0x73B05BC5084E0065ULL, 0x47856DFF7FC6F43FULL, 0xA668E1E48D58959BULL, 
            0xA3B5269FBBB53D48ULL, 0xCEDD49609FF1BD75ULL, 0xDDA5E62FCC3E08D8ULL, 0x56793E3D48C19395ULL, 
            0x767DA0480684BB96ULL, 0x2F4FEDBA2265582DULL, 0x02B03AAC0839D10EULL, 0x1A325985432C572BULL, 
            0xD7C1B94548306916ULL, 0x6E384625492DED0CULL, 0x0CDE3FF96A57FC00ULL, 0xBBA559A77B3EC2B2ULL, 
            0x9CA594F4141E5E90ULL, 0x9FAB7E95E7217323ULL, 0x1E4D71F3650AC5B8ULL, 0xC7F2E69A3BF0FB91ULL, 
            0xE9474C58CC4199AFULL, 0x6C9D774929519C65ULL, 0xEDF2162A84954DD5ULL, 0xFEA8F1B7428767B4ULL, 
            0xFF747F5193852406ULL, 0x362C6BB0D0CB4FDBULL, 0x3C0FB469FDA2D76BULL, 0x43DFDCBD31E22802ULL, 
            0x1BEDDF1457A9719AULL, 0x617FAE0A259D1774ULL, 0x864D251F257A6658ULL, 0xB56BE3F7320A4303ULL
        },
        {
            0x4F33DF40E01A7EE6ULL, 0x28233DD26DA4CACEULL, 0xCFFD2CF3AB393B6CULL, 0x6B9AD3891B8C9110ULL, 
            0x10EF567B30AEDD7EULL, 0x8FFF1D5E5E044F43ULL, 0xD0F6F7FF443364B4ULL, 0x7B208B959AA13C8AULL, 
            0x22FDC9F1A0E1EF78ULL, 0x40C2167EA9316952ULL, 0x8C46B47AA0C76F25ULL, 0x4F94C56072231FE6ULL, 
            0xE1CA570E33284813ULL, 0x3EC731D8ED5718ABULL, 0xDAB6A7D1E7BBCFBEULL, 0x8F26CE67036EF07DULL, 
            0xCF14B6FE15635B03ULL, 0x910A13EDB64DD58AULL, 0x64226BF3B03699CFULL, 0xBCD5628C5A39518BULL, 
            0x1493BA1219CD0367ULL, 0xCFC00340A0733F94ULL, 0x4EE65EC296231BE1ULL, 0x6AE3BD6F5B6134B5ULL, 
            0xE750968729A4ED56ULL, 0x631EAC6A02434B4CULL, 0xC2F008C08D05C70BULL, 0x87635D8586D52A8FULL, 
            0x0D6E4B7B854DD451ULL, 0x3584887BE56EAD5FULL, 0x469FA659F61EC451ULL, 0xC20E874BDD0FA729ULL
        },
        {
            0x588396DBF70F3484ULL, 0xC33958364314AC88ULL, 0xAC99826458E1A23FULL, 0x26BB7A92994F396DULL, 
            0xD4B3BA12B8733A65ULL, 0xBD6879D3F6E96463ULL, 0xE734648F78F6E7FEULL, 0x2B04F79A1BC11ABAULL, 
            0x5E4D228BD9F01608ULL, 0xA48A0AEC0856251AULL, 0x9C3A91728937B4F7ULL, 0x36A690403093B787ULL, 
            0xE1DF20F5A6F05A88ULL, 0xE8D4EB4C30E7224BULL, 0x564A7F86E2389399ULL, 0x7989E1C32DB60621ULL, 
            0x2394EE58A8F5DC6FULL, 0x100C21DE04056525ULL, 0x6FA925129193A66FULL, 0x31834E78FB61FD80ULL, 
            0x4E67C938E0542C5EULL, 0x15DA13032A0CF2B5ULL, 0xC9EBD45AF2EDB53BULL, 0x29BA4CC289AE8FE8ULL, 
            0x97844C25B3F37837ULL, 0xD7EE02BC7943817DULL, 0xEF2BB061188E8696ULL, 0x9DE7327DB3B18C8AULL, 
            0x785A9D85F26EC4DBULL, 0x7FEB8BA5C431739DULL, 0xF944D7F78B3D9B5FULL, 0x42D81B9416B009C0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kTwistConstants = {
    0xB678064B20834925ULL,
    0xD3DC3ED5D545142CULL,
    0xB7F41E05DACC9314ULL,
    0xB678064B20834925ULL,
    0xD3DC3ED5D545142CULL,
    0xB7F41E05DACC9314ULL,
    0x297068AE9AAB97BCULL,
    0xC8F695794818A497ULL,
    0xBF,
    0x8A,
    0xA0,
    0xBF,
    0x70,
    0xC0,
    0xCF,
    0x39
};

