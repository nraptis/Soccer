#include "TwistExpander_Naos.hpp"
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

TwistExpander_Naos::TwistExpander_Naos()
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

void TwistExpander_Naos::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFF4B2854F6070502ULL; std::uint64_t aIngress = 0x8E9FF41C6FE7B634ULL; std::uint64_t aCarry = 0xA5D1EACBDB201BC1ULL;

    std::uint64_t aWandererA = 0xFB4C4410C67F156CULL; std::uint64_t aWandererB = 0xA097E5FB21F20456ULL; std::uint64_t aWandererC = 0xAAB3F1369010534CULL; std::uint64_t aWandererD = 0xADE6B3F2BC74C924ULL;
    std::uint64_t aWandererE = 0xCAE94A8BDCF7A0A3ULL; std::uint64_t aWandererF = 0x9847C2748CF85033ULL; std::uint64_t aWandererG = 0xF85530103B69AC22ULL; std::uint64_t aWandererH = 0xA08603BF908B8AD6ULL;
    std::uint64_t aWandererI = 0x844722DEEFAA986BULL; std::uint64_t aWandererJ = 0xBF39A0F51AFD9A0DULL; std::uint64_t aWandererK = 0x97C165BF192F4DF3ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDBC307E7EDF01DC1ULL;
        aCarry = 0x8DBE51406D58C51BULL;
        aWandererA = 0xBFD85966176768E1ULL;
        aWandererB = 0xBE38857478A4FE79ULL;
        aWandererC = 0xA81C6E0E678C6C34ULL;
        aWandererD = 0xD21B4F9271B64A84ULL;
        aWandererE = 0x8C9F4165BEA0A2A2ULL;
        aWandererF = 0xF6B0129AF4B70327ULL;
        aWandererG = 0xCB5FEBB07B57EC83ULL;
        aWandererH = 0xD8BAFA76A8C5229FULL;
        aWandererI = 0x94304B903B8B7A0FULL;
        aWandererJ = 0xE180AA4D859BC8CCULL;
        aWandererK = 0xAE322CC6B95EB5F9ULL;
    TwistExpander_Naos_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9E6619B3830EE5F4ULL; std::uint64_t aIngress = 0x924376DB24A0017EULL; std::uint64_t aCarry = 0x965789E2E0420DD8ULL;

    std::uint64_t aWandererA = 0xCEC1A87DC226D122ULL; std::uint64_t aWandererB = 0x9BADAA9ED5023462ULL; std::uint64_t aWandererC = 0xBBBE9FC292F5555EULL; std::uint64_t aWandererD = 0xE37E253CD2CC3714ULL;
    std::uint64_t aWandererE = 0x8C5E02AA4C808353ULL; std::uint64_t aWandererF = 0xF858A83431EE587EULL; std::uint64_t aWandererG = 0x999490C6C8AEBB93ULL; std::uint64_t aWandererH = 0xE794E37C1A48ACE2ULL;
    std::uint64_t aWandererI = 0xCB517A349E93B67DULL; std::uint64_t aWandererJ = 0xE8522EE1A1961219ULL; std::uint64_t aWandererK = 0xFF92C0ABCDC09882ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD11A4EE1DE6DD5CBULL;
        aCarry = 0x92F7632C0118DDD8ULL;
        aWandererA = 0xE21AB24B7CCEA5EDULL;
        aWandererB = 0xCE34CB6513A6A305ULL;
        aWandererC = 0xF9B23B7A5E6FBDCFULL;
        aWandererD = 0xD5D665378693A393ULL;
        aWandererE = 0x8E4BC2694486128DULL;
        aWandererF = 0xE83EFBFE668124C4ULL;
        aWandererG = 0x834BA99E875E2E17ULL;
        aWandererH = 0xF693D93809AE30BDULL;
        aWandererI = 0xA6BADCFE23A3ADD7ULL;
        aWandererJ = 0x94C55ACD78870D87ULL;
        aWandererK = 0xE59EA8344BADF5AFULL;
    TwistExpander_Naos_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9E1793B276B14DB7ULL; std::uint64_t aIngress = 0xE71E2D1C3554C53EULL; std::uint64_t aCarry = 0xF975BCF714A74D9AULL;

    std::uint64_t aWandererA = 0xFD6DED9104EB1F2DULL; std::uint64_t aWandererB = 0xC1D339CE16DF8841ULL; std::uint64_t aWandererC = 0x8BF11581D80FF361ULL; std::uint64_t aWandererD = 0xEE49B89BFA947B4AULL;
    std::uint64_t aWandererE = 0x9F8472094DDB8785ULL; std::uint64_t aWandererF = 0xDD3F3D219B139469ULL; std::uint64_t aWandererG = 0xD14D80055DFEC8C9ULL; std::uint64_t aWandererH = 0x8ECA94002F04E8CFULL;
    std::uint64_t aWandererI = 0x93785CB1FEAC64E0ULL; std::uint64_t aWandererJ = 0xCD02F775EA98DF81ULL; std::uint64_t aWandererK = 0xBE3BA243E5570149ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x91964CCA11803F03ULL;
        aCarry = 0xD30B7842FC4374D6ULL;
        aWandererA = 0xC391A401B0B964E4ULL;
        aWandererB = 0x8D9C822DF552011AULL;
        aWandererC = 0x9E3A351034265B49ULL;
        aWandererD = 0xC7C26BE3A42ADF5FULL;
        aWandererE = 0x92FC8E48660CA61BULL;
        aWandererF = 0x85734478A9A3469CULL;
        aWandererG = 0x87F34E7AE43D6AFFULL;
        aWandererH = 0xDF9B4C60A80D6C29ULL;
        aWandererI = 0xFF21EA1271214B31ULL;
        aWandererJ = 0xC0E20C469F9184B4ULL;
        aWandererK = 0xAC07AC2D9477296DULL;
    TwistExpander_Naos_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9C4D085DE3B89C8AULL; std::uint64_t aIngress = 0xC8BFFFAE69C141A3ULL; std::uint64_t aCarry = 0xE4FE1BFF87701E4CULL;

    std::uint64_t aWandererA = 0xF67081EEEAA5BF34ULL; std::uint64_t aWandererB = 0xD1F6F3738BE5175BULL; std::uint64_t aWandererC = 0xE19310AC4046DCDAULL; std::uint64_t aWandererD = 0xF62ECC0B73875436ULL;
    std::uint64_t aWandererE = 0xE9CBD88A1AEFA0EFULL; std::uint64_t aWandererF = 0xD5C4DB922F12BDA1ULL; std::uint64_t aWandererG = 0xB3225BBB9F503805ULL; std::uint64_t aWandererH = 0xAF769AD090202D97ULL;
    std::uint64_t aWandererI = 0xB76C43F71C38A10BULL; std::uint64_t aWandererJ = 0xC79202B62FE20E20ULL; std::uint64_t aWandererK = 0xDBCA5ABCBAA957B2ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD508488EC7E8CF76ULL;
        aCarry = 0xD6C0C05675F4A7C6ULL;
        aWandererA = 0x84997123BCCAA898ULL;
        aWandererB = 0xDF62FB67D6EE2854ULL;
        aWandererC = 0xBB501688291AC079ULL;
        aWandererD = 0xF6553AC0B2A4135AULL;
        aWandererE = 0x8D8CDC4774DB3FEEULL;
        aWandererF = 0xC41915D223BA8753ULL;
        aWandererG = 0xA6609164E333B609ULL;
        aWandererH = 0xC3F2CE3FA286B1E9ULL;
        aWandererI = 0xCE3989CD53141F32ULL;
        aWandererJ = 0xD3D05BD173444FADULL;
        aWandererK = 0x86A59874E0A5AA64ULL;
    TwistExpander_Naos_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Naos::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE3CFB5F3F10187A1ULL;
    std::uint64_t aIngress = 0xE42E544BA933B1E4ULL;
    std::uint64_t aCarry = 0xB2D44535C252E829ULL;

    std::uint64_t aWandererA = 0x9A381FEBA754F41CULL;
    std::uint64_t aWandererB = 0xDD6AD8A38626CC0AULL;
    std::uint64_t aWandererC = 0xF05E6E060D9E0E63ULL;
    std::uint64_t aWandererD = 0xEA45B34906387DF1ULL;
    std::uint64_t aWandererE = 0xE098BD223F6E5677ULL;
    std::uint64_t aWandererF = 0xB173E4390E7448C3ULL;
    std::uint64_t aWandererG = 0xC438FF263C3D6D0CULL;
    std::uint64_t aWandererH = 0xF996958AAB2A83C1ULL;
    std::uint64_t aWandererI = 0xC757B18615783FD6ULL;
    std::uint64_t aWandererJ = 0xAA8324B4228BB015ULL;
    std::uint64_t aWandererK = 0xEF3A67C0FCD5AE08ULL;

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
    TwistExpander_Naos_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Naos_Arx::KEY(pWorkSpace,
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

void TwistExpander_Naos::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD24C7484332B888DULL; std::uint64_t aIngress = 0x932B35F94F901CBEULL; std::uint64_t aCarry = 0xF24F556748F71A3CULL;

    std::uint64_t aWandererA = 0xF47A602B9A4800FCULL; std::uint64_t aWandererB = 0xF2F1B1910F132ECDULL; std::uint64_t aWandererC = 0xC5D95C9C4EBE4481ULL; std::uint64_t aWandererD = 0xE23F336780CD573EULL;
    std::uint64_t aWandererE = 0x9403AC5D13159B7AULL; std::uint64_t aWandererF = 0x99D037E0A6BD9131ULL; std::uint64_t aWandererG = 0x98D7EDF93A513629ULL; std::uint64_t aWandererH = 0x9BE489DC7922B36CULL;
    std::uint64_t aWandererI = 0xE7140671C472C0A9ULL; std::uint64_t aWandererJ = 0xBD6AEA9EB8FACD9FULL; std::uint64_t aWandererK = 0x87F1A1DE1D936206ULL;

    // [twist]
        aPrevious = 0xD6FB9923CDC6F60BULL;
        aCarry = 0xA8C494A8D004ECE0ULL;
        aWandererA = 0xAD29AC48461B4FB3ULL;
        aWandererB = 0x99B43BE0D1F6A1D9ULL;
        aWandererC = 0x9FBDBD9264CB7CD7ULL;
        aWandererD = 0xE45881C3EA6B833AULL;
        aWandererE = 0x90AAAA764D59A63BULL;
        aWandererF = 0xFE0D8026681C7E0BULL;
        aWandererG = 0xDC49C9B2000F6CC7ULL;
        aWandererH = 0x8FDF13B668F58D28ULL;
        aWandererI = 0xB2E524A8447E421AULL;
        aWandererJ = 0xC35EA82F3E7AEF8FULL;
        aWandererK = 0xAD1721AA3B5BE19AULL;
    TwistExpander_Naos_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Naos_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Naos::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Naos::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Naos::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 23 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 11886
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1375U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 23 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 11702
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 23 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1051 / 1248; total 23663
void TwistExpander_Naos::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
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
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 205U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
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
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 23 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1049 / 1248; total 23529
void TwistExpander_Naos::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
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
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 116U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
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
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
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
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Naos::kKeyRotateSalts = {
    {
        {
            0xA9C4082AD18CE99AULL, 0x85F71C04A11A412BULL, 0x33A374A363268744ULL, 0xC0021410CEB92330ULL, 
            0xD7F406A116C9ECA6ULL, 0x5C54A4BA0671C702ULL, 0x135F62384A1F3E8AULL, 0x3F30C31C93C83993ULL, 
            0xB48AE76029F66B14ULL, 0x613394020F7D2938ULL, 0x9B36CD6786A6A397ULL, 0xAE24D5D5717B243CULL, 
            0x583649DCBEC91B89ULL, 0xB428C3AA77BF7BC3ULL, 0xE1A879E6DFBF26C9ULL, 0xA46C1692415F3B66ULL, 
            0x059CF65EA8877F9CULL, 0xFCE5BA535F4D8107ULL, 0x21D95CFDB9723983ULL, 0xECD3FD616D21AA90ULL, 
            0x4A9FCC1FA9CFA628ULL, 0x654337F35F3382ABULL, 0xE34BD10AFD95B77DULL, 0xD8C307B5B0959C48ULL, 
            0x1861249068534005ULL, 0x7E4427F060CC4907ULL, 0xC2F2496E8FB686D5ULL, 0x9A7EB7DD25B460B9ULL, 
            0xB2DDFBA4DDCDBFADULL, 0x99B529D1C99C0469ULL, 0x752441EBDBF503CCULL, 0xB75E88487FB613D6ULL
        },
        {
            0x0ADF158F8DEFA3F3ULL, 0x068E352B20706224ULL, 0x578C654903A9583AULL, 0xFA2DD86FD178C65EULL, 
            0x1D653E647393CE38ULL, 0x7151B201C9DC3B05ULL, 0x67F21AFE47A8879EULL, 0xC8825F3F7C55E87CULL, 
            0x332EAE69C4A441CBULL, 0x2CFDCEDBEB5756B2ULL, 0xF53FC94F4E2DF91EULL, 0xB80ED90241575ABFULL, 
            0x0AAF712637BAD5B9ULL, 0x2734C00730F78111ULL, 0x7756A97FDB2CFC6FULL, 0x249382B7B8CE09DBULL, 
            0x1BE1AAFF2FD649C2ULL, 0x91FF9E0A2995FE18ULL, 0x428507618B7AFBA0ULL, 0xA026BA4A9F47143CULL, 
            0xC8AC654532E02BCFULL, 0x2D3A0C79DBB05114ULL, 0x96C182E816F19F5AULL, 0x2869BB244D6ACC9CULL, 
            0x35600CC1CE2ED76EULL, 0xBD42921CDBDF700BULL, 0x179F8A105F7BCF53ULL, 0xFF115C444D7A3AABULL, 
            0xCBD2DB55F1C2AB55ULL, 0xD0AB7211A5E69BD9ULL, 0xDB8D0C2279D15722ULL, 0xDA573B4EB8E474EFULL
        },
        {
            0xE7ABC2C2732137BEULL, 0x308FB6498C132769ULL, 0x3A834AC5427FE425ULL, 0x6BDF0FD90DDCE527ULL, 
            0x3BC9789EA7C056ACULL, 0x0FEF034F4A20B812ULL, 0x9846A1F3398DC136ULL, 0x94EF72D8071808BEULL, 
            0xF3572455263A138FULL, 0x79767EA796837053ULL, 0x09FCA4A2D4839EBCULL, 0xE2A1BC7CA0F4928CULL, 
            0x52341B1D866C758AULL, 0x4B32F0219617573FULL, 0x17313A45013D14BBULL, 0x815470456F504F08ULL, 
            0x5EDC650294A1FFBFULL, 0x52D670A2BCC26CDAULL, 0xED29090E83BA9682ULL, 0x998D82397F75C144ULL, 
            0xCFE0020DB06040F4ULL, 0x6BB4840F3D1A248AULL, 0x8F11F9CF2002256BULL, 0xD4076080D13211C1ULL, 
            0xB0A8BDB1EE13413EULL, 0x846FB31ABB3BDE35ULL, 0xE8F6A2B893B131BCULL, 0xC596C066BD89F27BULL, 
            0x589DAC72D58A1FF3ULL, 0xC18C1C67778819A0ULL, 0x457B02B63C0B1B9FULL, 0x08E1C46E8E57E150ULL
        },
        {
            0xB95083E00F1D247CULL, 0x65F71D9106D99777ULL, 0x13C08CCA227CD1C1ULL, 0x97FE006711D871D4ULL, 
            0x527E4636338CE7A5ULL, 0xF48B6A2E42BA703EULL, 0xA5CB41252125DFFCULL, 0x9B12E988E4475BF4ULL, 
            0xCA4373D21FE4E5FFULL, 0xA4089FE74B327C3BULL, 0xFA76713DDFED952CULL, 0x6A6C9B01199D4201ULL, 
            0x44E68972E0BA0EC1ULL, 0xADE192DC251924B7ULL, 0x4D74375A71B8ADAAULL, 0xE701D316D5438295ULL, 
            0xD6F1F57546BCFD02ULL, 0xF61E0508EF3F464DULL, 0x8F11BE7165248367ULL, 0xF66BEAF5400A8678ULL, 
            0x80D913F32B4733A1ULL, 0x813A8ACCAC839634ULL, 0xD6FC7726FCA46931ULL, 0xACB7D791D0349CCBULL, 
            0x211C3C65CF335E7DULL, 0x91C5A6D5514F3D08ULL, 0x02EB9170C6F20AFAULL, 0x030BA56877FEDE53ULL, 
            0x16C1E99C29C4D6E4ULL, 0xC25852A26307E9ACULL, 0x2EA7BB1FCC69402BULL, 0xF1944FDFFE8BBE25ULL
        },
        {
            0x7E60520588B1998BULL, 0xEA562871286DCB6EULL, 0x0A0CE7836CF73D22ULL, 0xD4B2B82D942FBFC3ULL, 
            0x65EB3C0A9E2FC22FULL, 0x48881B80E12744AAULL, 0x0B26545E57BFDAE2ULL, 0xA7A92CD98DCF6740ULL, 
            0xB25E5F1E33B0ED97ULL, 0x8ABBAE744D41A0FBULL, 0x78557928E94C8A5BULL, 0xD1C75F206D16E381ULL, 
            0x2CF7C6B8634B4692ULL, 0xC2D7A960C8AC2C22ULL, 0xA847EF8DEED0011FULL, 0x85BDE0FB4F64A019ULL, 
            0x4380694AA2DC9087ULL, 0xA943E28753043539ULL, 0x5FF5A079DB02BC49ULL, 0xBFB34C0423F8D741ULL, 
            0x2582D342D697E11AULL, 0x84F405BC5280536DULL, 0x9C8A65FEE4B7476DULL, 0x96B0C7015B007C5CULL, 
            0x3EE00C0931F6BB52ULL, 0x068CED341F7D7D28ULL, 0x80119C3899EBD036ULL, 0x7D809E70AA6694CDULL, 
            0x6C2845B8E6882E27ULL, 0xE965A3CD12A1369DULL, 0x416F35E5684DF022ULL, 0x67DC451A05F8356CULL
        },
        {
            0x01F0BA6F26DA62D8ULL, 0xA197A384D734CF6DULL, 0x370C7EB85DF76F33ULL, 0x498033E349190DB9ULL, 
            0x1A9D5D38C44FE17BULL, 0x880B4475CFDE9B16ULL, 0x9CD2E9D6EA7FCACBULL, 0x0BFEC01F6CA38BFAULL, 
            0xCFB0BE5CDB38659CULL, 0x224D046B20F8EB96ULL, 0xFC39B67A1DF00A28ULL, 0x0A431B12FE47156AULL, 
            0x2E5EDAFDE3B5C518ULL, 0x98A2DD36B967AD3AULL, 0x3B13FE74D698B426ULL, 0x245A2D44608298D4ULL, 
            0xF2F34A52481E1FBAULL, 0x9531FCBD23BC3EAEULL, 0x57916A100A5E3BA8ULL, 0xA275E5AD0ECB0BB6ULL, 
            0xCE71D085C3BDA1EEULL, 0x86B8AD699BBFE297ULL, 0x5A261E3883D21C47ULL, 0x5C9702FF6E2A6B07ULL, 
            0x9BDF39847B3D43CEULL, 0xB70AC4E83EBFA711ULL, 0x4CD2587B9261C375ULL, 0x034B05918B9A5CEAULL, 
            0x142603C726A8D5F4ULL, 0x9AB35C2020091718ULL, 0x82FB28908DD76E2FULL, 0xCA85842D66A17C04ULL
        }
    },
    {
        {
            0x93A1DC03A66BC6ADULL, 0x808DF5D83A7D5B84ULL, 0xC5B41DA73046823BULL, 0xA3FDC4A3308F117CULL, 
            0x90AF200E740FD400ULL, 0xE8AC224349F6844AULL, 0xD7D6E88FE0BC64A8ULL, 0x0716C8CE103585C8ULL, 
            0xD681EDA49D88AE89ULL, 0x9384A5B3D39FDDF9ULL, 0xCEF0834AA470F00DULL, 0x39C7B35C6C28426AULL, 
            0x6679169FF9132826ULL, 0x87C8344C7925C8B8ULL, 0xADDA4C355C7193AAULL, 0x5EAA7C359C35C0E4ULL, 
            0xFF175B69DEE42ED8ULL, 0xF6894DED64B96865ULL, 0xFDAB73104D72F618ULL, 0x9A91102E85D6D535ULL, 
            0x6EC8D64A2C9E391EULL, 0x83E438DDCFC08D3FULL, 0x86C95AB84E969AB3ULL, 0x5E2FF3DEA4E1261AULL, 
            0x35D0DC0263FD5BEAULL, 0x05825738838BF6AEULL, 0xBBEE2AA05CB5F622ULL, 0xB4C5484589D32E18ULL, 
            0x625EA498AAAF20F5ULL, 0xA157609F26CE6B2DULL, 0x76CE0A27F493CB6BULL, 0x4CBF4BB7C9C93A0CULL
        },
        {
            0xE43A005CA90E6111ULL, 0xD3C342855D24103EULL, 0x1287B75914F9B91AULL, 0x8DA9BC88F59BD9C0ULL, 
            0xBE9B151311B8B225ULL, 0x869517651DEF462CULL, 0x934AF3380C810244ULL, 0x0630A3648C013036ULL, 
            0x8C0947530ABEFD73ULL, 0xFD34BEA251986CF8ULL, 0xC9D3ABFD08D3DF2BULL, 0x6EBCE0DE9EEC689CULL, 
            0xAAA96E3399B1EE7DULL, 0x9C096DB8C2D0429AULL, 0x3DA02EAAA9FDBC2AULL, 0xFE6FB1F534CC4635ULL, 
            0xAB1D6EB1185110C5ULL, 0xFC599F577AA76FE8ULL, 0xBA54ABF360A36379ULL, 0xAD0A147E291B3EC0ULL, 
            0xBC95A2E91BD05954ULL, 0x4F0F1C1F08E5E724ULL, 0x898554198E0A9922ULL, 0x01CE1C2BDAD58F76ULL, 
            0x4005AFC48AF39BEAULL, 0x123CB81550B1E948ULL, 0xFBDE8F24A0A0DF54ULL, 0x6C1EE90654D4B593ULL, 
            0x8801962672C89E14ULL, 0xAFDF9D91E8BBE015ULL, 0xA147EA23CE191D13ULL, 0xF59B4CCC7D31D125ULL
        },
        {
            0x193FACDB4742C5FBULL, 0xAA12BC82E5403145ULL, 0x7862BDEF4E511183ULL, 0x75217D29423052BEULL, 
            0xF1E8B7EB6B631CB9ULL, 0xC8F267C10417800EULL, 0x38336E8278EB9848ULL, 0x0EE6F1DE68D55E60ULL, 
            0x395F8B7AB7AFA65EULL, 0xD04ACA64F6E80865ULL, 0x43FA0A6123D68DB0ULL, 0x9071B28846634998ULL, 
            0x1E73D4FF1AF23C35ULL, 0xD0D3CE2D02232B10ULL, 0x382535D2DC6A052BULL, 0x97FACD40C9177DC0ULL, 
            0x0BE7E7D93CF67A4DULL, 0xC1B26C49DB3D2791ULL, 0xECD30AD87B9309EAULL, 0xC4FB4C7A33638A08ULL, 
            0x4ABC46913E3D0954ULL, 0xC2109A5AD95DB8E6ULL, 0xC6C0C59536E81330ULL, 0x44C450753F3B576FULL, 
            0x083D0FCDED99E2C0ULL, 0x8C9243FD18550CD9ULL, 0xFD1D690392B2F7BBULL, 0x9B54DA7701F4F39AULL, 
            0xCA1A26613AFCB17AULL, 0xFAF2510A4F57E1E8ULL, 0x8E4133EEED25D22CULL, 0x7AF1F791EC3FBDEFULL
        },
        {
            0x9B84E1AFEEC1E7FDULL, 0x3B016B3E8D9EF0F5ULL, 0x4B6A568B98CC0FCCULL, 0xD3EBF054B47A4A21ULL, 
            0xAC6DC09CE5049CD3ULL, 0x1348F9D0F6717A39ULL, 0x22848E97CF00D60EULL, 0x98CB82C2528FBB02ULL, 
            0x62CDB0A5C2EE649FULL, 0x251FB4C103DBA344ULL, 0x4061278B947EBB69ULL, 0x136DCE0006034421ULL, 
            0xF2A28CDABECABFE8ULL, 0x142F684AAEBE795BULL, 0xECBD29ABE3F434DCULL, 0x3AB2A6E9C5A0DF75ULL, 
            0x6DDCC3CAEE7FE8D2ULL, 0x8674603B4E9249D4ULL, 0x4836390D964BA35CULL, 0x93B333576424139FULL, 
            0xA3E1C65F271EA34EULL, 0x0A431E6CD8F1ECD8ULL, 0x8704BC104A2469CEULL, 0x90265F7BD484A708ULL, 
            0x805C8173C98912E2ULL, 0xEDF359B91223644AULL, 0x1322EA6FDE26B486ULL, 0x60364B1C91C0FE7BULL, 
            0xF5E4B57CC9A5B436ULL, 0xE580537ADDA8B51BULL, 0x6F79CCB47165932EULL, 0xB5732E489BD9F327ULL
        },
        {
            0x1CE01FA92F947BE0ULL, 0x28789AB05DF4B3D3ULL, 0x889CC583D422F676ULL, 0x48144DB25576A4DDULL, 
            0xE4533FE436BC8CE1ULL, 0x8A08AB506D40AD33ULL, 0xF203750123627796ULL, 0x025F060B4C7FFE72ULL, 
            0xA1460018DEB8D5DEULL, 0x3CAF042BA7228C8EULL, 0x2F194E8DB6FA077AULL, 0x0E59B5B12775F765ULL, 
            0x42FDF6C41EA14E39ULL, 0x675C16A0BC67E7CFULL, 0x733BE3E3A4948B8BULL, 0x996CC595B749E1EDULL, 
            0xE1466D750D953F7AULL, 0xB6C91E720195D1D1ULL, 0xD715CE9E940C9888ULL, 0x38B7C2B745BD37B6ULL, 
            0x62C63AAEA34A410BULL, 0x93A5DB930CE6790CULL, 0xD2BFF142AD52353DULL, 0xC12E9A38BB7CDEF3ULL, 
            0xF3091B4CFA63DDC7ULL, 0x4FD8E9D69EBD5A9FULL, 0x51E5D6B727B90DCFULL, 0xA8517F73998D8BC7ULL, 
            0x67E60AA9738522A4ULL, 0x75294B3A0C2781D7ULL, 0x2FCC8D6084FA9298ULL, 0x63400742BA3F7D31ULL
        },
        {
            0x4C626B261D46A9ACULL, 0x261C0FA08DD52DA5ULL, 0x6BBD836DE9A228E8ULL, 0xA1BED8F6B1FA1479ULL, 
            0xB1B06833E4EB2C2DULL, 0x051D7EA36D5C8E1DULL, 0x37E644CFB811570AULL, 0x6268D7739CDC8E63ULL, 
            0xB3992A1673166FFDULL, 0x1D283AE560B94AD4ULL, 0x7DD224A2A8330711ULL, 0xB08D67E0F9B69DA7ULL, 
            0xF51CD07FCD0DA7DFULL, 0xEA522181BF2B8C5CULL, 0xC7F39A67EEE1F8ECULL, 0x5E1F2F99DE771C4DULL, 
            0x66CD3815E001BEF3ULL, 0xBD2C870AFB656BF9ULL, 0x7BDBB1F430B3FDC9ULL, 0xBBDD3265FB8BB26FULL, 
            0x7ED0AE0C1F5D64BBULL, 0x59F449DF10213C83ULL, 0x86D42F40EE65E688ULL, 0x11CCCA65AE86DB50ULL, 
            0x11D976B354D17E56ULL, 0xA85F140ECA3EBB9AULL, 0x02F684124B5822ADULL, 0x8C5E8558A6C72FBCULL, 
            0xC133255628454200ULL, 0x72830A29E1099AC3ULL, 0xC34E6D511BB5318FULL, 0x7F94B75DEA457109ULL
        }
    },
    {
        {
            0x7DA36C5F1F84920FULL, 0xC87F2209BF1195B9ULL, 0xD65802A21AF2004AULL, 0x7BD8B119011F812BULL, 
            0xA793E544945CF995ULL, 0x1A01C2FD471982C7ULL, 0xDBE5247777DD5B67ULL, 0x9BE4B36028731425ULL, 
            0x08F95C63642364B5ULL, 0x177C48954A272141ULL, 0x87892AA93E2542F9ULL, 0xD1AA6053B2359E4AULL, 
            0xF6042053B1331204ULL, 0x6518A263500D6920ULL, 0xF2E7A5F39EAB1FC2ULL, 0x8C8BD5138D8A6AA6ULL, 
            0x7A34C1A3AF52A969ULL, 0xC53D8A2BB0C1CD60ULL, 0x51347FB470323B36ULL, 0x80C98AD0E3C13443ULL, 
            0xF15FC522812D0F6FULL, 0x7EB5175A79E51FF4ULL, 0xE4FAA07AB97387BAULL, 0xDE8D6E6C2BB95256ULL, 
            0x581A4DDA1D744D52ULL, 0x245A5C7B32EDA395ULL, 0x8297D844D7D91488ULL, 0xE6C43382938082F4ULL, 
            0x7B871A362846CD83ULL, 0x89712EF349F0D549ULL, 0x0C8906910064F53CULL, 0x6F9CE23A9C6C4577ULL
        },
        {
            0x35FB77960821402AULL, 0xCB455B7A22990BF7ULL, 0xD1D41F4FB4954780ULL, 0x548C421AF52A98E2ULL, 
            0x21B99CE6E7BE7D08ULL, 0xABD1765EEA3679B1ULL, 0x5A8074B899BC4C33ULL, 0x9B66233E547BD509ULL, 
            0xA86E82C6FD727BC4ULL, 0x124058A282AC113FULL, 0x09C794D540AC68D7ULL, 0x331BE34A7FD7BC03ULL, 
            0x08B3E2239CDA5778ULL, 0xB3CBA3360BAF3B8BULL, 0x41E29C0C2A04AEECULL, 0xDBA7109906451527ULL, 
            0x9CFB2A29B0E3F908ULL, 0xD8D682A2E777831CULL, 0xCBE8045999F8114EULL, 0x52BE82B4D77856B3ULL, 
            0xF95FC648140E5989ULL, 0xBF114FE406DD659CULL, 0xFBB41523671DBB0EULL, 0xC49E136D9A082FBBULL, 
            0xB8FB63A4C5C84BE7ULL, 0xCA685453B1567AB1ULL, 0xF0310D13DD0E2D95ULL, 0x3EC696FA78DD4CFAULL, 
            0x9846634B4217393EULL, 0x62FA55FE476E81F2ULL, 0xAB97325231B3F186ULL, 0x2D1C0BCAF57E9DB2ULL
        },
        {
            0x8F57C849C0C1EACCULL, 0x019832AF532DAEA4ULL, 0x87573057D2A0101DULL, 0x098AA2D1A2D943ECULL, 
            0x417312044D670CD0ULL, 0xAD87F98EF2E7EE63ULL, 0xC10EE54DCAA87E4EULL, 0xED7912A8CFBED736ULL, 
            0xE27BD7D38A7ED587ULL, 0xBA527CF89EC581A7ULL, 0x086A18CAE7A635ACULL, 0x4EA159CD02BD6C58ULL, 
            0xF597C1E28898DF72ULL, 0x74720D1F9DC25A11ULL, 0x413C936592F5BEA0ULL, 0x233F042E6BADAAF2ULL, 
            0xFD3B4BDA0B380E55ULL, 0xFC1A529C69496962ULL, 0x7D266AEB74A071D2ULL, 0xEFA9A28D5EABB0DBULL, 
            0x4ABB0B5E0B3C7BEBULL, 0xCBE7D73BA71D3F0BULL, 0xB4E6900615BF36E4ULL, 0xD571A8720623C240ULL, 
            0x290933B6929E5D16ULL, 0x7FC372D6839D308DULL, 0x6C53E9F0AF2BCC2AULL, 0x60E325A5D294B10AULL, 
            0xB151F993A82E737FULL, 0x7A2F97F039865C70ULL, 0xA4A2AD815319BD68ULL, 0x4476DA86075557FEULL
        },
        {
            0x7F0EA313A02A8C5BULL, 0x7B0A6142FE4A1997ULL, 0xB93B33702A5B9D08ULL, 0x6AABD35D5E6A6951ULL, 
            0xBF76B5653C4C6E15ULL, 0x6E565A41DCE313BEULL, 0x80F7A847C365CA6EULL, 0x55C6042FD2F70DBBULL, 
            0x9DB3C1EF28AD329DULL, 0x8D255C09BA2D58C0ULL, 0x81012D235C23E203ULL, 0x720E0DF3B58A4FF2ULL, 
            0x92166C4E88111D0FULL, 0xDD9E9DFE5D53A36DULL, 0x52D0B3A998BEFB19ULL, 0x64B2EDAF742B2510ULL, 
            0x42D1F81A466854DFULL, 0x5343DE0D337301DFULL, 0x394458925B84CD44ULL, 0x4525871076E879D9ULL, 
            0xF50B4F20D04E734EULL, 0xC710D25FE75CC2A8ULL, 0xD449100A0906CAE6ULL, 0x4DB14D40E7FF5838ULL, 
            0x8A82A326AC9FB4B3ULL, 0x39AF4B69D8355017ULL, 0xC32ADFA8A8872BAEULL, 0xD6CB23CA22E75CFBULL, 
            0x257F1F8A7FF8DF7DULL, 0x98795609A1A233BCULL, 0xE25F057AEA00E8B0ULL, 0xBC7622824609F04BULL
        },
        {
            0x9A39409229B9CF2CULL, 0xF90E7184D40EAFBBULL, 0x421E41EE2E4DB680ULL, 0x2BDD3651515D40FAULL, 
            0x1FB8BE40E61D8182ULL, 0xF6842DC16C45DBBCULL, 0x7F373C80ACC447A0ULL, 0xBD16407ADE224026ULL, 
            0x674D821DEFDC9257ULL, 0xA3F2E24DB80E5B50ULL, 0xC6E3E2FFA7D427FCULL, 0x9E279463DA15CD18ULL, 
            0x8E187E15EF92F8A3ULL, 0x7B370CABA2586091ULL, 0xCE0A8E08EF8DA737ULL, 0xA4AC6A97A9AE081BULL, 
            0x29B77416183305E1ULL, 0x5884EABFB1C6C67EULL, 0x74DBB75A416076C2ULL, 0x5744E778F66A0351ULL, 
            0xAEB02CF0247556A7ULL, 0x6D38888CF0720DE6ULL, 0xA2FDDE864D354E4FULL, 0x320812A931F27F10ULL, 
            0x6AC7CF437FA59FE1ULL, 0x971121918C708DE2ULL, 0x6D732C33935F87FDULL, 0xF63D3337EE65CFE4ULL, 
            0x25D0A0C738D6E3ADULL, 0x9F972B2BA2F19884ULL, 0x907054B5CCC3A64AULL, 0x2BB816DDBCC02A52ULL
        },
        {
            0x1B38C11AB7661E31ULL, 0xA74D1E780C10F549ULL, 0x514E9DB40910E1A7ULL, 0x0D6D8D363E5AB9C2ULL, 
            0xC3E80A18BC74AE41ULL, 0xC0EC730411AE3180ULL, 0x1BEE4049E3F8FD0BULL, 0x31E7686B36D2C4DEULL, 
            0xB848DB3EADF125E5ULL, 0x76B9DD9766E7EE4EULL, 0x867075D18F8DE57FULL, 0x6B17886739AC8525ULL, 
            0xC5DE0F95DC3B16DBULL, 0x9E1DC20699AF6DEAULL, 0x6B2C0A9F033011D6ULL, 0xAE74362D087AE920ULL, 
            0xC6D32119EBA5C765ULL, 0xBEA9A2CB9F31077FULL, 0xDDEB87925AC55BA7ULL, 0xEA26252813C71B55ULL, 
            0x55AF8C4016E580DCULL, 0xC9EB32AF30A1B9C0ULL, 0x65980E4609CE8371ULL, 0xCF67CBE6F2BD1151ULL, 
            0x6AE98098EE849707ULL, 0x2883C19EEEF1E161ULL, 0x7D6B6B0AC554620BULL, 0x057B258086FBFBEDULL, 
            0xCC7647AD3000FDA3ULL, 0xC06FC72EB59D8C86ULL, 0x86453781C65E05CFULL, 0xB2A859909C515B1CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeyRotateConstants = {
    0x675594CD23AAD592ULL,
    0xC27BBB8D2CA0F5A7ULL,
    0x776EE05A9A75BDD3ULL,
    0x675594CD23AAD592ULL,
    0xC27BBB8D2CA0F5A7ULL,
    0x776EE05A9A75BDD3ULL,
    0xC32FBF567D020EAFULL,
    0x8AEFCA7159813FBEULL,
    0x1F,
    0xD9,
    0x11,
    0x0B,
    0x79,
    0x5D,
    0x72,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Naos::kKeySpawnSalts = {
    {
        {
            0x61FA5D3D9BF0F973ULL, 0xB33B02DB39DF5F0DULL, 0xFAC15736AAE1EC2FULL, 0x50A79C3C0B43A8CFULL, 
            0xC618EAA3127CE063ULL, 0x8608E9C8DE6DA74CULL, 0x24FC28647F933F0FULL, 0xD0CE6D1D0945A83DULL, 
            0x282AB1FF09A498ADULL, 0xF21975FC03A92671ULL, 0x23D88ECBA8F5272EULL, 0x237410D6418B8310ULL, 
            0xFABD9371FA0398F6ULL, 0x934784F9730F9C95ULL, 0x106EDDD40E1A22FAULL, 0x1B42D41058E96FFFULL, 
            0x08E9556CF407FBE5ULL, 0x4C8ABFAA028D93A1ULL, 0xB9D9768D4A3647A5ULL, 0xA7CE92BCBEC65A26ULL, 
            0x1B6CEBD90A030615ULL, 0xEB19C14552E4C58FULL, 0x33C82DC14A15FD80ULL, 0xE272328831DD3DB3ULL, 
            0xB24485BE6B1A1C6AULL, 0x991040E31A4295CDULL, 0x0B7FD618085AA9B3ULL, 0x52FE161D20C9687BULL, 
            0xC9809A7CB3F39D75ULL, 0x6D3225013DA97534ULL, 0x2207223EC0730628ULL, 0x2E349A2A62574A84ULL
        },
        {
            0xD93F67318A203414ULL, 0x7EBDC194B293DDD7ULL, 0x1F20550D5AF1C7F7ULL, 0x32159DAD863B872FULL, 
            0xBD57119AB3249EFAULL, 0x90E22A449CE1C3AFULL, 0xA604767D3C48F4F2ULL, 0xFAFE5FF4AF935004ULL, 
            0xE97E4F7424B92106ULL, 0xE6226AFE41E48B22ULL, 0x528A779164E53149ULL, 0x086671B5EAB2E1D0ULL, 
            0xFE35176A0E8541A9ULL, 0x5994422CBF036316ULL, 0xE5BC81F8C6961A60ULL, 0x80F0FDE347634F60ULL, 
            0x601250D7F2477DA8ULL, 0x38693EE93371AEECULL, 0xE3F5B8487BA1084BULL, 0x52BEB756A41BBB8CULL, 
            0xDE6930D84C97BB29ULL, 0xE63A792527C7D073ULL, 0xFE1DEC5B15AC51A5ULL, 0x360D360B16BFCE6BULL, 
            0xBEDF41FF27C4626DULL, 0x9AACFFC26FF4AB68ULL, 0xBD64E833E2C86D0FULL, 0x29A0588CA858DDA2ULL, 
            0x5CC21C84A7C5838CULL, 0xED07747D6863B024ULL, 0xB0CA54AD92A3C5C0ULL, 0xCE834AA317EA1AA5ULL
        },
        {
            0xBFCCD4F1E207CD6FULL, 0xF262134C324D8FFBULL, 0xE6656F3DC1A469DBULL, 0xFF17C7A777E5CC88ULL, 
            0x5E53103F7A7D98DCULL, 0x420C8C559F1171F4ULL, 0x650B6DD3B78DC7E8ULL, 0x73A0EAFC4EC3A858ULL, 
            0x17BC6004670F1CE7ULL, 0xA77FAF39897E3CB9ULL, 0x8EF7DBB9177BD51CULL, 0xC8D40CCD495F1AE8ULL, 
            0xF828807870A7EF0AULL, 0x4900C8BD84391BDEULL, 0xF43241384F0F7BFFULL, 0x4422C02541F04AB0ULL, 
            0x376190771530A516ULL, 0x6A05E1FFEDD734C8ULL, 0xFFAF254F4FBCD6B0ULL, 0xBC743509B6FAA938ULL, 
            0x9CBA3CAA4A4289CEULL, 0x166D4699A0B8D4C8ULL, 0x7A05AB8B39196811ULL, 0x06F5F12F14A97EB4ULL, 
            0xB0B388200B1C86C5ULL, 0x522EDD8CA4B39DD4ULL, 0x1FE296036B364A9AULL, 0x533D9D5036309BC6ULL, 
            0x00D7C93112D85407ULL, 0x08DBE5B97EDC3A5CULL, 0x463478BE8FE2BA85ULL, 0xA69793B03DCDFDBFULL
        },
        {
            0xF59AA9DABADDB5CCULL, 0x6BD53219A88C0A79ULL, 0xD68B7747CF3666CCULL, 0x8AAB7E53E0CF5EB5ULL, 
            0x841869E1CC7FF0B8ULL, 0xA3F5E9C42E5C5C94ULL, 0x1E69E4C3F4F212AEULL, 0x52A76E0839CC7531ULL, 
            0x429EFCEAB49A20DBULL, 0x2BED079AB0FE4746ULL, 0x3D5721964CAAF2EEULL, 0x560381F837B32D4EULL, 
            0xAA9DBA26F5B6C331ULL, 0xF289A60271DCB061ULL, 0x7DD245F0EE97F6CEULL, 0x57C8FD4918352B04ULL, 
            0x9D04FC975FA6CC21ULL, 0xFEAE052931338AAAULL, 0x28C79F1375F84206ULL, 0x1DDB5AE5F42C9692ULL, 
            0xD8D4B1EA26246589ULL, 0x2ADB3A6E3276DFB1ULL, 0x9C99CFFD7128293EULL, 0x99AFD822435FDED6ULL, 
            0x133111D4FD58A01EULL, 0x910BED7923560801ULL, 0xF5ABB694EE35CC3AULL, 0x548851C8069068CEULL, 
            0x725BC9F0E3219473ULL, 0x02E5D14EB21DB3C5ULL, 0xE28B871BB8C78BFAULL, 0xA4B5867118FD1903ULL
        },
        {
            0x15714A02426A9547ULL, 0x170F5E6CB54AE181ULL, 0x8A476F1D5B965747ULL, 0xF9F21559C5A4AAB0ULL, 
            0xF6CA0793BE1CEBD7ULL, 0x38AD566BF26A3A7AULL, 0x47F73D7A7F568F91ULL, 0xF04986192752BC42ULL, 
            0x6DE197398E40E783ULL, 0x271F402AA9A7FA72ULL, 0x5505F04A6F576212ULL, 0xFE96159003774E9BULL, 
            0x93DCB3228DB98E5CULL, 0x9E0C11CD938AF686ULL, 0xCF2F7FC861BE4928ULL, 0xB1CD788EE86C50AAULL, 
            0x50B68F91E51C14FCULL, 0x8521CA40C5A55689ULL, 0xDA165CFA017AAF3EULL, 0xDB0DB251DD4D2662ULL, 
            0x6CF81D96D0AC13C1ULL, 0x33BC3469268DC593ULL, 0xFA61FF6B3E629AE9ULL, 0xBDE5A08AD8877E42ULL, 
            0x12D98323037F1F20ULL, 0x98620030C7603EBFULL, 0x03E3C6A8BC4BC11AULL, 0xB55CD5AB6CDD5385ULL, 
            0xB07661F02613F628ULL, 0x46D3CA7336CD4953ULL, 0x7D5CCB971FABA192ULL, 0x635E74FC42655FD4ULL
        },
        {
            0x5B8B634D3475E67BULL, 0x4A6EAD375B141646ULL, 0x286EF99CAF198DCFULL, 0xD6EC0791FA26383FULL, 
            0x5B7D321DD3B9C878ULL, 0x2AF6A08586616559ULL, 0x05D4D4AEB16D4985ULL, 0x39CED6E70AC458F0ULL, 
            0xD1864F64D0A9EDECULL, 0xA81E6C29AC4F4967ULL, 0x3E0FBF779936647AULL, 0x6FAC8DEC090BCF79ULL, 
            0xE4CCB4F3659CC04FULL, 0x7F98C4EF86514D94ULL, 0x3F48BFFB0E6A47A2ULL, 0x896DFD318A92D5C5ULL, 
            0x4D99117B5DB07B51ULL, 0x601708951B56EB95ULL, 0x7AB53D442FF9FC7EULL, 0xBA8FD71B457550E8ULL, 
            0x3191C9CB2C009D0AULL, 0x1F45986E2A17354DULL, 0x6C1BED795437CB6EULL, 0x71D5AC4F06A6FDBBULL, 
            0x410ACC34ADEAEFEDULL, 0x68872E72FC5C523DULL, 0x190541EE71BD7261ULL, 0xE4AD03AE9F43B72AULL, 
            0x6E78901A9D7D283DULL, 0x38E8C1A4DCEBD386ULL, 0x54BEAE28514BA403ULL, 0xDBF86E7A7D90971CULL
        }
    },
    {
        {
            0xB51845277260F830ULL, 0xA429ABC4246253DFULL, 0x01C6E81CC2B45FB7ULL, 0xC2DFACBAEDA62E58ULL, 
            0xBD96E735C8CA4CF8ULL, 0x8C768FFFCB54624AULL, 0x95B4C858046C78A6ULL, 0xA317D86733945826ULL, 
            0x67B4016E1E86480CULL, 0x8FE7D33AFDE06D07ULL, 0xB5E1A9EAD8CF5B62ULL, 0xD261906423AEADE4ULL, 
            0x20C2C9A8305C7055ULL, 0xB897DA2173C37EB9ULL, 0x7A578917782B6B89ULL, 0x6130A3D4B8616A67ULL, 
            0x780A7884C663C9E3ULL, 0x9DFA7D962CA2D88BULL, 0xD433B72BDD98E5C6ULL, 0xF25495DA22B09B7AULL, 
            0x403CC11506D49AD3ULL, 0x94569A5D171A81B6ULL, 0xB71FA3E8650D0336ULL, 0xB17EF270ACA915CEULL, 
            0x39E1AF34276EE34FULL, 0xBDC204214D8F8D2DULL, 0x067A9A6589DC8A91ULL, 0x12AB785D539D461BULL, 
            0xFDD0B813A0D9FB1AULL, 0xCACA7EDD415DF279ULL, 0x6B0C48945281291CULL, 0x6A530117F1E3E5C1ULL
        },
        {
            0x93175B64ACD69E29ULL, 0x984403B0FBFA9FD2ULL, 0xF7655EDEF73FAA29ULL, 0x4732A9BDEF206EC1ULL, 
            0x6D459592AF636417ULL, 0x537C5B03F4F49128ULL, 0xE4D7192A7DD8C899ULL, 0x17E9E4BA410B391DULL, 
            0xDE26C5FE3D03F405ULL, 0x693EB799C2A4A5B2ULL, 0xFF76892128A77AD5ULL, 0x0A19DF8618597BA3ULL, 
            0x7751CF8B38BB1123ULL, 0xEB96E36EF19C3809ULL, 0xCC60DAD20641377FULL, 0x7CF5A0A426F13BB1ULL, 
            0x0182D5B51CCF4152ULL, 0x394270FEDDFA2954ULL, 0xCB8A3CD2F3F85D42ULL, 0x28C02A713DA3D17DULL, 
            0x7E6A06392E9F1C5EULL, 0x8B1ADE0D73570789ULL, 0xED017FF8DC849A09ULL, 0x4A42138564E022B0ULL, 
            0xA021B3DF33A36A44ULL, 0x099BC0598019D757ULL, 0xC6D2546C0E65A3A4ULL, 0xA927C70AB644F55FULL, 
            0x8946DDF51DBDBD83ULL, 0x71A38CE21C00A09DULL, 0x888F9E7BC66C844FULL, 0xE4517CA31E078C2FULL
        },
        {
            0xCA2EA8AD97B68D93ULL, 0xE86626A0AC516F70ULL, 0xD8003588516F0BA9ULL, 0x4D1DF714EA69F5C1ULL, 
            0x376CCE5035649566ULL, 0xB268257A1063F0A4ULL, 0xAD229EFDA368ADC9ULL, 0x634355D99589887BULL, 
            0xC59B67E65E48E103ULL, 0x4E60184F92D72822ULL, 0xE69FB5008C7CC4F7ULL, 0x3D57DDA30D9D06AEULL, 
            0x11D871F22D2150FEULL, 0x36A269F4002FDBF1ULL, 0x9F2C0DEF0DC8FE86ULL, 0x429A8BFF7FCA4494ULL, 
            0x9DD961F8ABA83D73ULL, 0xD78B0C8ED11E90F1ULL, 0xE80494D859FEA4ACULL, 0x5D7581FC4A1CEB2BULL, 
            0x64E38E307A3917B9ULL, 0x58953F05209BBD38ULL, 0xB843A198C2A6CDC6ULL, 0xD87C47AEB3DE0C57ULL, 
            0xAD210C18283541CCULL, 0xB250452344704011ULL, 0x99788CB7D5FC27EBULL, 0xED28D50B1D10E9B2ULL, 
            0xE1EAE4D245638E1DULL, 0x04643476868A9433ULL, 0xCD54B095F28FBED3ULL, 0x70C10111CAFB4E9DULL
        },
        {
            0xDC61F06F19F84B25ULL, 0xEC576738A8642F4FULL, 0x964DB3D0968DFA4BULL, 0xCB278DAC7D33AD4DULL, 
            0x713EE2CFEA553E49ULL, 0x1393F58B3D83C554ULL, 0xB8696516D65998DCULL, 0x093DA98A027C8698ULL, 
            0x3D1B23C9A9CBE216ULL, 0xE6FD99B03FAAEFEFULL, 0xBA702DEC692D4B29ULL, 0xD0097E597B08BE97ULL, 
            0xE4813A3AB17C7018ULL, 0xD56849EF9780482CULL, 0x1774C4583C707269ULL, 0x7B9B5F7FD590605BULL, 
            0x0980148D3559EC2BULL, 0x31BB598FF41EB187ULL, 0xDC0F3EB7FB333A76ULL, 0x423430A0C7E142C9ULL, 
            0x3A85909285AB8FF1ULL, 0x82B6C14E4285115CULL, 0x08291BCE46EAD34AULL, 0x0E8F16FA1C9327CEULL, 
            0xA491FE5C3BF41FD2ULL, 0x11EB8BD3D18FABFBULL, 0x152950C53BCCF9A8ULL, 0x30D6445017F4FCA1ULL, 
            0x31B81A8CDD35117AULL, 0x683A5F708B3C255EULL, 0x2DFED2EB1D4E6325ULL, 0xE9A94093A0FC0FFAULL
        },
        {
            0xD739AE3F47D8AB71ULL, 0x64622E91ECB8262DULL, 0xAEC1F2EFD99713C7ULL, 0x899EE0F2E39BD066ULL, 
            0x23BB6C36EB707FAEULL, 0x411D574F7AC8966FULL, 0xA97ACDE5B40F4FADULL, 0x5B27414306014286ULL, 
            0xC4351F54F805F935ULL, 0x8CAA1905E13AAD87ULL, 0xA3066E483E3E5ED9ULL, 0xFDD84049D4B26E5CULL, 
            0x244A8064755D67C4ULL, 0x276DB7D78930B0C2ULL, 0x53C0010852F0DE1AULL, 0x080AE99C6F7FB17CULL, 
            0x4C9884AFFF1FF3A0ULL, 0x99CDFC16916DD043ULL, 0x3F59930580F31304ULL, 0x3AD722A03C4602ECULL, 
            0x39B5B3C708DA1866ULL, 0xF1E972728C93046FULL, 0x73FA381A96193D2DULL, 0x83C0C7C016E46976ULL, 
            0xAF5B33423D134685ULL, 0x02BBB33B8990153BULL, 0xE6D0461073CF3658ULL, 0xAA647434A7A8FFF6ULL, 
            0x3D74CDCCDE83B5EAULL, 0xBE9F3CD630AF3DBFULL, 0x306D98530841CC9FULL, 0xFE7CC5A7C768B171ULL
        },
        {
            0xF20F6B6E115D0B1BULL, 0xA4BAF75E13849DF2ULL, 0xF1473DE6645F96BDULL, 0x94AD42E586BC305EULL, 
            0xAEACF90DAB85DBBBULL, 0x36CC3400CB79C3D0ULL, 0x1E2CE67691DABB3FULL, 0x7F25E3DED78BAF2CULL, 
            0x406A20CF126293C3ULL, 0x283B70CB2032B1D6ULL, 0x3B6484AFB8DA47AFULL, 0xD7A5FFB4B2E284A7ULL, 
            0xE0248757BC1E96F6ULL, 0xCE92FD078FF13599ULL, 0x1581D6448F125D50ULL, 0xE6473ED1A67CCA5EULL, 
            0x988383794D9ACAB1ULL, 0xDA82DB6CCDE244FBULL, 0xB031D02E3C078F37ULL, 0x1A7A310DD0E42913ULL, 
            0x65779C3D1DA119F0ULL, 0xE5F68DB5736CE41BULL, 0x0F348E099A2693CEULL, 0xD2F4E98E0F94B79FULL, 
            0xAA84905138C2A71EULL, 0x95F921E972519E6BULL, 0x03A2EC98A8B932CFULL, 0x72E6E695ECC093EEULL, 
            0xF40040C16D8D0139ULL, 0xE9C0C4992AF72AEEULL, 0xA4AA4AAB0314EDDAULL, 0xFFB3ECBCCD13BF25ULL
        }
    },
    {
        {
            0x6833F3A2340054AEULL, 0xD08B6E6641533802ULL, 0x2D92BD8D1B6B2821ULL, 0x1E2B2C143C3C5AC8ULL, 
            0x8B11C21B502282EBULL, 0xAB38C29A36A93BD2ULL, 0xB9C66893A172B4CCULL, 0x24E7259B5CD2AB9CULL, 
            0x0B44F34BCAC435E0ULL, 0xFF5E211A6E6343AFULL, 0xFB9B8FB7BCC1456FULL, 0xA17DE27D40DB6C0FULL, 
            0x1A64FBDC5E66DC08ULL, 0x53DF2AC2795A94F8ULL, 0x2CE445B04A89C61DULL, 0x3AAD3C66E75EB435ULL, 
            0x53C430EFA7E1DA28ULL, 0x230435814E13645BULL, 0x0C9C79CE2D2493E1ULL, 0x161A3DE9A348368AULL, 
            0x4113609BAB529573ULL, 0xE47E5B694364D98EULL, 0x13AAA890D2452823ULL, 0x1DF02F7E81723D51ULL, 
            0xC2D07966B49F2E0EULL, 0xF2D1C782BA29D9C2ULL, 0x72F2E954625FD5ACULL, 0x3D9AD3D46B815728ULL, 
            0x01EAAA8DE0CF4668ULL, 0x31ED6E7972547B75ULL, 0xAC2F493628CF7F66ULL, 0xFAC6CE0A4336FA9FULL
        },
        {
            0x0394E4977A6696BAULL, 0xAE733E8AC0D7B442ULL, 0xC6418D924F751CE1ULL, 0x6341F0AAFCCD914DULL, 
            0x128E4FF76DC77E88ULL, 0x57612E72E27E4AE3ULL, 0x89265F0E62A1C5D9ULL, 0xC0073B8F3321F873ULL, 
            0x798CB7054EB6A64AULL, 0x4263B224DB2E9CC4ULL, 0x6F657E902A851AC4ULL, 0xE03B6FC00E77AF5CULL, 
            0xBDFDC29E7EFA9407ULL, 0x6AA1403E7C1F02ECULL, 0x7BC4C91CA9064152ULL, 0x7B9F7ACA1250BFFBULL, 
            0x55E8E52397294F3DULL, 0xEDC8EC14DF531B1BULL, 0x3C92469F6EDA81F1ULL, 0xB98A2F28290490A7ULL, 
            0xA03DFF1F78DD6360ULL, 0xF174709D93161F9CULL, 0xE826BEB88C2E2322ULL, 0x76EFC1DC22B173B2ULL, 
            0xD793D3E0DA6B1BB0ULL, 0x7726DFC32B1DDFB4ULL, 0x6727CAF48469825DULL, 0x3FC9CAAA9359C07CULL, 
            0x65B9BCB44C6E62A5ULL, 0xD1B1F8819AD7D00FULL, 0x3B8AE407842D3808ULL, 0xFD9523BEC84B0DF3ULL
        },
        {
            0x7EE88C093A6E4786ULL, 0xA1BFC1A8799E3E2CULL, 0x3ACF5CA4BEE7ED13ULL, 0x62E3204576564154ULL, 
            0xDC9F88EF85987EA2ULL, 0x6681676B4D84C5A8ULL, 0xE6908B48DE9844C2ULL, 0x90835FE6856C5C37ULL, 
            0x45C1DB25AC22AE75ULL, 0x917961AD95647D72ULL, 0xE9F6A60C0E9EA770ULL, 0xAF5B93C86409B18FULL, 
            0xA70CC62871F891D1ULL, 0x5EDDE3F6C8F20E36ULL, 0x89691FDF7688BA2EULL, 0xF039EEFC7791385EULL, 
            0xEE2C49079B1B67D2ULL, 0x257DEB3B44EAEA7FULL, 0x49E839B7A1120027ULL, 0x36395F0B3D0BB9C1ULL, 
            0x655E29CBEACF5DC1ULL, 0x4CF5D84EB24276FFULL, 0xB5CDF82386DB70F8ULL, 0xFEEA46A11F8630A6ULL, 
            0xEB15B3FC72F504F3ULL, 0x15F05049AD3BF886ULL, 0x0E5D49D7892D68BDULL, 0xA6E0D78ED903A612ULL, 
            0x0AEAE17A19E27334ULL, 0x6364BBB8DED24637ULL, 0xA16724F3DF0B04FFULL, 0xA982518FD1D550AFULL
        },
        {
            0x9F105D42804F5AEBULL, 0xB8EF3C179B8D1060ULL, 0x83EE268353344AA4ULL, 0xF00B90478AFBC287ULL, 
            0x869CD9F49E8BD2BEULL, 0x3994DA971C1B0C2FULL, 0x1A079D7F0E5EDFC0ULL, 0x226AE569C6CABF9CULL, 
            0xCFD4ED46CA928E44ULL, 0x2439A159801014F6ULL, 0x61003FDC742118F4ULL, 0xAF6B2900DDC78AF7ULL, 
            0x93F3EAA869B60D07ULL, 0xACA5460DF6B31330ULL, 0xD0DFD498BD7ABA6AULL, 0xC62D0B88952E1327ULL, 
            0x905B32168D0B27C9ULL, 0xC3D45BF0A2AC9F22ULL, 0x2ADF9DF29C228449ULL, 0x1E102C848F1F96E4ULL, 
            0x1AD2E88F7F3AE62DULL, 0x4B6548080F697A24ULL, 0x62478C9E559BE648ULL, 0x7E1A7C06DEFA5FEBULL, 
            0xBB7DBD6D5F5AB04EULL, 0xF421657001F1A3DFULL, 0xBE2B1A060AA166BCULL, 0xE0DBAE66BE964C2FULL, 
            0xF4C2C1ED619D9AC8ULL, 0x87D0564017F3EBCFULL, 0x55F2FC5C3A111442ULL, 0x4DB4930B13358C02ULL
        },
        {
            0xF868DDE77B8EA340ULL, 0xBCC65E054F212257ULL, 0x1E4E2709CFE0061EULL, 0x8F0B37C7D75003A2ULL, 
            0xEE8DCAED3AE82FF5ULL, 0xACA7ACB5106C7EADULL, 0xA4087B7479EAF288ULL, 0x659A67E2B908F098ULL, 
            0xB0ED544F0AEFC0A0ULL, 0x7BDDE2B0ABEAD93AULL, 0x3D7F04E1C7C298E1ULL, 0xC9732F91FEC2DD39ULL, 
            0x18761E6EE201E7C1ULL, 0x5D18548B448B324DULL, 0x910DA326035EFA11ULL, 0x24487D6B9D5C3904ULL, 
            0xECD4359CE613EDFBULL, 0x769922F2CE4FA507ULL, 0x76E2E790D6984B5BULL, 0x8AF735C726AC3D14ULL, 
            0x17123AE13A2B7348ULL, 0x9E6DE0FE2CD3F9D7ULL, 0xA7FEC9FAE7DA5413ULL, 0x30DC60FAB96895DEULL, 
            0x49CEA152182702CBULL, 0x2607A8BB106171E4ULL, 0xF5CD4CC751E601ECULL, 0x413FA973EB81EB97ULL, 
            0xC703963CC379618DULL, 0x32E96F145AD374B4ULL, 0xC938D95A374298CEULL, 0x74CD601562036997ULL
        },
        {
            0x2C97752CB9818B91ULL, 0xF1EB6E5EFB90FDDBULL, 0xC5D739F30D97ADDCULL, 0x97EE88C90E0A4B4CULL, 
            0xF99299CA0E816C6CULL, 0xABF1C28AE3EE154AULL, 0xBDF553FCF6593369ULL, 0xE97CBA91894DB89CULL, 
            0xEBF3ABBD257CB5D7ULL, 0x8B8F4D354F308745ULL, 0x7782348026E4B895ULL, 0x9655BF0F1D906A66ULL, 
            0x053906E717BEACDDULL, 0x08AD86E4CEBE0605ULL, 0x0046A4F371D69B08ULL, 0x3D3E80F13A7A03CDULL, 
            0x808E22FD6B329C53ULL, 0x55747FDA070D130BULL, 0xE2812D40FF288DBCULL, 0x7C80AAFC5D939843ULL, 
            0x4D8D4C991D19B970ULL, 0xB834B52F9EC4B77DULL, 0xE0BC2AC3618B137DULL, 0x85D29148F99BCC8AULL, 
            0x15B4E1334752C558ULL, 0xD7F02C6E7F7B64E1ULL, 0x5A09BAB512ACB149ULL, 0xA8E9D3CE1EF44FF8ULL, 
            0xEC75C3BE6C372A13ULL, 0xC7E50C046CBACE8FULL, 0x8B129C2A5D4791B3ULL, 0x101DC0AF4F2F40D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeySpawnConstants = {
    0xCDBF8B77059B3591ULL,
    0x1403131AB01AA3C5ULL,
    0x1D4826B124A26A2FULL,
    0xCDBF8B77059B3591ULL,
    0x1403131AB01AA3C5ULL,
    0x1D4826B124A26A2FULL,
    0x0BFE844B513F5CFFULL,
    0x3887F600E1657DC8ULL,
    0xC5,
    0xB0,
    0x1B,
    0x45,
    0x95,
    0xAB,
    0xFA,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Naos::kSeedSalts = {
    {
        {
            0x233A79D604D50821ULL, 0xD6F8455EAE9FA92FULL, 0x6CE8E71BCE6E7E77ULL, 0xEA022AD35D3AEB6DULL, 
            0x072D318677716AF6ULL, 0xA624A3B137DFF029ULL, 0xC0CAF2EADB7FB957ULL, 0xB9DC1B0EB1A6006AULL, 
            0xDD026F67B3FE82BFULL, 0xE2FE92FE7BD65BBBULL, 0x69CE1067CF6C8216ULL, 0x4B679432852DCCC0ULL, 
            0xC9616DCF63C3136EULL, 0x0F275F198E49A893ULL, 0xBF528AF7B6110238ULL, 0x4166B09A89CE62D9ULL, 
            0x308658B26DE12E40ULL, 0x0DA6FFFCE15F615BULL, 0xD6EFFA13E2464582ULL, 0x24623E5A66ACA46CULL, 
            0x6E6397A07F7D06ECULL, 0x0069C6E642ECF2F6ULL, 0x268B9B89DDAED204ULL, 0x14A420D31C422DAAULL, 
            0xAC860E3D9F43B9A4ULL, 0xF33A865E4FEEB3F6ULL, 0x5D4848251FC5C50DULL, 0x0180F3C7459460D1ULL, 
            0x8AB579FA304FAEFAULL, 0xDA0A9C56A64E5330ULL, 0xD1A895C3E51EB914ULL, 0xDE8AF2B11000F0D4ULL
        },
        {
            0x0532B0836E3400CAULL, 0x85BBC6C1FE1BD7F4ULL, 0xB5CE67BD888FB903ULL, 0xC15A2368AB97B514ULL, 
            0x9313C16C5A4CA3C7ULL, 0x7E583FF89FB062FAULL, 0x0D9BB4CB0A6868A3ULL, 0xA7CD659153389148ULL, 
            0xBA55F3F82FC146BCULL, 0x8A8E641E13CEF478ULL, 0xD806AD77AAA5BBE7ULL, 0x27F347D60D9B2859ULL, 
            0xDFAAF66BC0AC6300ULL, 0x4584E24D686D1B92ULL, 0x3CAE62AC42500507ULL, 0x13732B014896B4CDULL, 
            0xD279DE075F35935AULL, 0x2A1F89E043B1CF5BULL, 0x980EE78767EBDA64ULL, 0x345502A536C0E716ULL, 
            0xBCE6FE353CF60F69ULL, 0xFC7AABD3CADCEB29ULL, 0x61FA3DFABF3983F2ULL, 0x5F314C246F685E24ULL, 
            0x4A6D08BB6A4CF64BULL, 0xC562C286F889BC9CULL, 0x9D313B4FF56D1DEAULL, 0xF385BC2004C87C2AULL, 
            0xC0A6E4247A1127A5ULL, 0x4693AB4686081E31ULL, 0xE375F7323BAC1D6BULL, 0xA1E2E8BDA6227D08ULL
        },
        {
            0xFAD8D210AD6A03DEULL, 0x77C96BE2DF935853ULL, 0x27DFDE6E10AACDB6ULL, 0x86F9F76990319342ULL, 
            0xF349108F275DF0D5ULL, 0xA259749FD03C09D6ULL, 0xD0CFB69725C28FF0ULL, 0x86E2A234E54881BFULL, 
            0x142234CB646B9D9DULL, 0x32AA34AA6AADBCD9ULL, 0x83D381ECC3C0F6AAULL, 0x12DF9F2C8CEA71B6ULL, 
            0x6543FD2E98112BB7ULL, 0x38D1E606217BB00DULL, 0x45C229AC64F1FCDDULL, 0xDD3EBEEB9023793DULL, 
            0xBFC863CCAF55E245ULL, 0xCE2E57FC2B61506AULL, 0x906BABA50021F8EDULL, 0xA858459F21435CBDULL, 
            0x7D981BD572048543ULL, 0xA51F0001210E8115ULL, 0x8156C414AB4600B5ULL, 0x02F179E7898BB266ULL, 
            0xB6FD7DA1ED478B12ULL, 0xEF077CDD33AD1F24ULL, 0xABC30306B3B6FBC0ULL, 0xA8E2F1DD8A232609ULL, 
            0x50E4554C0BC2ED62ULL, 0x6C64251B20A826B6ULL, 0x2B43717691E0646CULL, 0xB7A70F99A85F391AULL
        },
        {
            0x99E545A09253F9FFULL, 0x5F7A7D8B01AEDCEFULL, 0xE1A0AB87758F5E91ULL, 0xD64A4660D6B2D35EULL, 
            0xB213CE06FFC80333ULL, 0xC8381EA09D2C07FEULL, 0xDA6778864D7F31E8ULL, 0x2064F833F8DDEFE1ULL, 
            0xAD9F1B33D50B5113ULL, 0x08A36F0DFDB7C8B6ULL, 0x0CED6E77F3B57296ULL, 0xB5721D320D7D4694ULL, 
            0x59C94F6FA4B80A8FULL, 0xBB22B9D4E96199E4ULL, 0x4C59ACA6DD5C10F5ULL, 0x26F8BD466C7D5279ULL, 
            0x35BDE2B421576F26ULL, 0x85F57F4428396343ULL, 0xB38EBB73CEF1E6C4ULL, 0xE2C46CCA93984EEAULL, 
            0xA79D598E29165C14ULL, 0x751AF3792DAE1D65ULL, 0x9F412C797E57C41CULL, 0x225B4823E7598376ULL, 
            0x15CF8F541638C8CDULL, 0x240FD8B911237A2FULL, 0x7ED79070B04EE75CULL, 0xDCAABC4980700CA0ULL, 
            0x07FB49D62891FB7BULL, 0x871D542F678D231CULL, 0xBAC9A7B92A0684A3ULL, 0x49B2D9EEC7627589ULL
        },
        {
            0xE93242FD30037912ULL, 0x3672333F58BB87DAULL, 0x542B433CFC46BB5CULL, 0xDE5933B3703278F8ULL, 
            0xCF04A33BE2A98DD5ULL, 0x8927D1CAB5579CEBULL, 0x467772A5AA35F90DULL, 0xDF3020C9AF948ABEULL, 
            0x51D1809D51B13997ULL, 0x05DAC7E89BBBAB82ULL, 0x293A1DC7DE4D9445ULL, 0x3866D0D3F605197BULL, 
            0xE95723609884FF6AULL, 0x986CE4BAFA5E3FE6ULL, 0xE8AB55969242CCF6ULL, 0x31BCF9D8A7BC7B5AULL, 
            0x96ADC7293067DA48ULL, 0xD2E997B3FB28C2B6ULL, 0xF46776CB0E8614A1ULL, 0xFBBC9B0991277D0AULL, 
            0xD5D2BBC722C7CA40ULL, 0x70D1D56D7A680D73ULL, 0xB6C0DBB5BE5BB487ULL, 0xDAF63A4739FA0E7AULL, 
            0x05EBE25E0AB9F6D8ULL, 0x5B40B1F85F285120ULL, 0x2305FE5D045C2E15ULL, 0xC98FB354C2B8FF66ULL, 
            0xF583F3E7C9F52128ULL, 0xF4A0FF782B7728F6ULL, 0xFF0516970946BDA1ULL, 0xE506E84B2C60705CULL
        },
        {
            0xD69CEE83D349476AULL, 0x6EBA6FB8F8AC0C19ULL, 0x80E35A74F68D11D1ULL, 0xF6D1BF40EC0B660AULL, 
            0x69CCA29224058568ULL, 0x0FC3AA43D5BF55D9ULL, 0xFFE0D9D89316A440ULL, 0x3890F13682AB8535ULL, 
            0x4BCB8F4F565C3570ULL, 0x327C67EE2108A551ULL, 0xF8A56E1F78EC5E50ULL, 0xB57E403CCC77C8E6ULL, 
            0xA080218219906F15ULL, 0xB767D142FA00E4FBULL, 0x44AB82303B00FB92ULL, 0x70AB4C877A0470D1ULL, 
            0xC5DC2BA665D7AA12ULL, 0xFD69C7BAE3BF198DULL, 0xFCAE021F5CD19BDEULL, 0x77577918F9CF50E3ULL, 
            0x2093CE4EB95E484BULL, 0xF53286A9A5F6EDD0ULL, 0x67C77E91230AA28BULL, 0x22D9ECAA3CEECF4AULL, 
            0xC184671AC600CC16ULL, 0x119ACDA03D40A346ULL, 0x03E40ECF10F5A16EULL, 0xB5C8F37A36E8FFBBULL, 
            0x14A106A06912E8D4ULL, 0x9D839A67D884EAC4ULL, 0xD1F3B842FD5A1B72ULL, 0x98039CE67D8E3F09ULL
        }
    },
    {
        {
            0x429375CCBDB1F825ULL, 0x2DB41FDF2AF43B04ULL, 0x72418CA3A7AB3E4DULL, 0xBCB750CFF0FBC718ULL, 
            0xB5580CE3693156E2ULL, 0x33E498DB9971F532ULL, 0xF1D69AE0D78A3DDFULL, 0xFBE30F40DA03119CULL, 
            0xD08A311436098F2AULL, 0xD989268E5143B66AULL, 0xD01BEAEE5FC069CEULL, 0x46E635B4B198B1CEULL, 
            0x7AAF2DAEDAB59932ULL, 0x18D498019D7D8E78ULL, 0x076DD2AD08D6DC8BULL, 0xE75FE6710B9AEF0FULL, 
            0x4A0BEFDFF66432B1ULL, 0xDEC60B66710E78E0ULL, 0xF776DEFDA2DB17A0ULL, 0x24BAA204F2A0AE13ULL, 
            0x5A278BE196B42BA5ULL, 0x086824320E584027ULL, 0x542D9C3C8FEA74DAULL, 0x16953F4D43DE1A85ULL, 
            0xD9230E8DEC30A009ULL, 0xC8F93545D43A6F5DULL, 0xE99ABA46A26B0500ULL, 0x7CCA3A07EB75A9EBULL, 
            0x9B7767CD6E7C9DA6ULL, 0xEFEAAD31EFB38E6AULL, 0x4061BFA4881FA24CULL, 0x0AC69179D3AA58F8ULL
        },
        {
            0xD5EFF76CA050764BULL, 0x205EEE29857DDEA5ULL, 0xA29BCAE2581BAE92ULL, 0xFA24B3F8277EF0B9ULL, 
            0x9A81A047A8CF6DF1ULL, 0xDC496F9B2CCFDD76ULL, 0x7D6DAF0B7C4D50A6ULL, 0x281A19F61231320FULL, 
            0xA3EBA105963896D6ULL, 0xF3E9045B75E1BE48ULL, 0x8E144568918362B8ULL, 0xBE68D86CBFD40DB1ULL, 
            0x00C2A9E992A460E5ULL, 0x6BFBA106D4414B72ULL, 0xDEA85ED0C9141ED0ULL, 0x99F622A856E1E236ULL, 
            0xA727F6E283CC6347ULL, 0x258F7B23052403BAULL, 0xA03714F9CFC7BC23ULL, 0x54F226D0413C4CC9ULL, 
            0xAA4B20681AB4A727ULL, 0xFA837496AD4665B4ULL, 0x3622FEF39667CDAAULL, 0x0FF139922FC17BF1ULL, 
            0x7437AF75D705B7F6ULL, 0x3480DCB5EC57A68BULL, 0xB3ABEE4869A25E40ULL, 0x999B93A2396AFF84ULL, 
            0x4D8CBEDCA1F030C7ULL, 0x99325E929BB2D3B7ULL, 0xF11B6151223B09BBULL, 0x740E2265A2C723EBULL
        },
        {
            0x0FAB121A32BCB36BULL, 0x499B568588F8F5E7ULL, 0xD3690B29334EC2DDULL, 0xC224647308A1F6C2ULL, 
            0xAD454B1EA1C515C7ULL, 0xBBDCDC8981BD1102ULL, 0x44FE09DC9E7E041FULL, 0x800CE2C8A64725ECULL, 
            0x72BCCA9DCE2B020EULL, 0xC674963B65439D20ULL, 0x09D8C98364A90568ULL, 0x5D4F9FC091664996ULL, 
            0x218C77DD153C59AEULL, 0x509DE09431ABD343ULL, 0x3617B664764ADF44ULL, 0x09516440E550B6C9ULL, 
            0x9A436CEE2C879D20ULL, 0x57205F59DF1FB678ULL, 0x4001136E6C955C1DULL, 0xF79DEE83105C9545ULL, 
            0x45ABCD22E26ADED3ULL, 0x85AE7896E3BF659EULL, 0x2BC95428C7BCC623ULL, 0x80257F758ED3A566ULL, 
            0x415CE1E88A9C65B6ULL, 0xE2914A1F993003B5ULL, 0x2C66A6DDA96259B4ULL, 0xFCCCB5596A56DDC6ULL, 
            0x43B1CA2E7F764FEDULL, 0x243607AA847CA39DULL, 0x4D1E58B8DB1B5F1FULL, 0x653121F8F936070FULL
        },
        {
            0x1B6329DE7655C2E8ULL, 0x4AF4768420749C96ULL, 0xCD56D64EE519AFD1ULL, 0x044F23264C53B919ULL, 
            0xAED336FCBE2510DDULL, 0x632D644433145A6AULL, 0xA2D24F8A35F216CBULL, 0x96BCE8AF9F8552F4ULL, 
            0xAF3EC75D6A18DC6FULL, 0xE63D8A9B03AB8E40ULL, 0xA3B9CA30142FEC8BULL, 0x10F7B2E7071F7E71ULL, 
            0x139ECD1A4031CB82ULL, 0xE7934C87E00B7318ULL, 0xD4A0CF917BC9EC31ULL, 0x7E0A1C311C2D4526ULL, 
            0xAA0D67DE4030D5E3ULL, 0x0C426A8CBF21EA60ULL, 0xEB87907C887CD929ULL, 0x25BD15D1C4A982E4ULL, 
            0xF6B1D37826821859ULL, 0xA410DCE8CB797D57ULL, 0x5607858251CB6441ULL, 0xB580A3DB1BC8AD2DULL, 
            0xE4EA0B092681529FULL, 0x1831BD66B57E5A6FULL, 0x943A28B2FF01A3FEULL, 0xC75AD992CF1A5CBBULL, 
            0x0831456DC978046EULL, 0x03726DB022B7DC09ULL, 0x979C45927102904FULL, 0xBDA570F551381A0AULL
        },
        {
            0x7A1EC5642297E22EULL, 0xD0BE899F0B48E183ULL, 0x09374DA69EE79C5EULL, 0x4B6F0665E6D52A41ULL, 
            0x35974CBE68764912ULL, 0xCA81CB76D083C026ULL, 0xCFF84B39D22188D2ULL, 0x8A5DC7573ACF5ADAULL, 
            0x09C802AF8436A6DAULL, 0x89D6C7CC328A20E9ULL, 0xD01BFD99BE0D6667ULL, 0x03C98309406A9CC0ULL, 
            0xBCE5C8D5B6A3C8DAULL, 0xC3E58259F68F635EULL, 0x0B2D832A4C2C56EEULL, 0x048602AD7EF03548ULL, 
            0xD8D9177C8D1C581EULL, 0x32A7ED9D55951132ULL, 0xF0AB163E584D0DDAULL, 0xF980B3EAE097DC7CULL, 
            0xFADD282B7D5C870CULL, 0x6D7450E0454A57F4ULL, 0x4DE58422262A6D47ULL, 0x45A3B8F8B181CD28ULL, 
            0x3A1E6546BDA9E5BDULL, 0xB6852994817A6F36ULL, 0x237683B4E8ECD6EEULL, 0xAB5AE141FF54C2FBULL, 
            0x11EA0CDD41D2C3CFULL, 0x0FA07B12C9806496ULL, 0xF495E4A4151BF2C4ULL, 0x01276C74D427CB7CULL
        },
        {
            0xBDF6CC216DE0AB40ULL, 0x4236A1160B3755D5ULL, 0xE0D721D39F7CABEAULL, 0x3656FB5E5E1A3F0EULL, 
            0x1BD27ABB65805AA5ULL, 0x531F3EC0107AAB50ULL, 0xA6962F76722A25BFULL, 0x4FC9A9E5232419C6ULL, 
            0x78219FEFDF02F591ULL, 0x6804BAB9147E3B56ULL, 0xC8FEB5A8DE9B44C9ULL, 0x92E0CAE36FD060EDULL, 
            0x3D338571384FE85CULL, 0x42B58D44FAC32003ULL, 0x2C990C22FA012CA6ULL, 0xBD0B50F9A77A4D86ULL, 
            0xBA5296E4503F29C8ULL, 0xCAB950009B43BB08ULL, 0x64AAB0BDD132DF14ULL, 0xBDC7F5CCB13A623DULL, 
            0x1AFBB24DE48AD2FBULL, 0x3BD3ABAD0F3B6652ULL, 0x958DBABB479D401CULL, 0x960F503F01CA827CULL, 
            0x10739158FA36AB69ULL, 0xA09EABD7F3CD9F56ULL, 0x09D9F5B11200B3ABULL, 0x4D593AAB81A0F198ULL, 
            0x32ED39D9203B98E3ULL, 0x9A060A8119BC97D4ULL, 0xABD4363C3FCB2217ULL, 0xFA1FF84AF75E100EULL
        }
    },
    {
        {
            0x580CB8EFF493469BULL, 0x378E2534AD7ADA88ULL, 0x3D94AC1CA831B4D9ULL, 0x3512ACA6D192A3CAULL, 
            0x9F96F39EFBB68439ULL, 0x45184B67ED18F429ULL, 0xF4FFB0BE95830861ULL, 0x51715D27B48E415FULL, 
            0x9CCAF5ED2BA9E619ULL, 0x0BC22062778EFF41ULL, 0xB4A1A6724F19E66AULL, 0x7DA3D492DE208A8DULL, 
            0x5C99E284D841AF22ULL, 0xBACDE6709B62F165ULL, 0x125078920C92048AULL, 0xBFCE11E02F3DC0D7ULL, 
            0x89CB4CD87D4342B4ULL, 0x92BF7595E15A368EULL, 0x4DE6BB3B08D04C29ULL, 0x8894286AB87AA02EULL, 
            0x577D72F1AA76D436ULL, 0xAB66D3A523FE24F3ULL, 0x8F4195B3DFBEC482ULL, 0xB3D2240CA43D1614ULL, 
            0xCA619F61D6722CCFULL, 0x88E94B1B32C8F8BEULL, 0xDA18E9C6A1F4E303ULL, 0xCF5B615FF2AB3F39ULL, 
            0x2D3B5F30F8283B77ULL, 0x7E93C80A46C005CAULL, 0x78A99C6822A67A1EULL, 0x1852159F83BF78BAULL
        },
        {
            0xF76B64D297105646ULL, 0xA9D8ED6A2631CA40ULL, 0x4C4959787BC60D1AULL, 0xF078B490D33BEA92ULL, 
            0xD12EA386060CFD93ULL, 0x9567BB97B5CF1A3CULL, 0x57B8BE54D5BC6375ULL, 0x6B000DE72C117482ULL, 
            0x373B4856FE355200ULL, 0x9FED5867FF98A978ULL, 0xAE3C0154A76BD34FULL, 0xD14B011BF906AD5CULL, 
            0x36FA7F410C511433ULL, 0x72FC4FC5084289F9ULL, 0x28415D7241F6838BULL, 0x3CE706DBF1A95900ULL, 
            0x518C0FF9DB2A37BAULL, 0x13B45AAD0C563C3FULL, 0x19CBCD2386CB2045ULL, 0x862CF9F380E0C5D1ULL, 
            0x38BFCFE8FBBA1A0EULL, 0xA076D454123EF229ULL, 0xE849684869E0B191ULL, 0x9D165C56F332C143ULL, 
            0x984D3F27F5E19219ULL, 0xC5BEA0737F25C0B0ULL, 0x956DD42A3C0B153FULL, 0x882D3D486EF4BA2CULL, 
            0xBE0B9073BB13E622ULL, 0x30928E6E63DD1BCCULL, 0x5E1C3A7B94FC571DULL, 0xF73AA6A7C7BD6F16ULL
        },
        {
            0xFF6D73BBE08406FEULL, 0xD0B591F3F3FB751AULL, 0x89CFA5B0B684722CULL, 0x6627CDCD576B1FD1ULL, 
            0xF1479FE89EA2E71DULL, 0xBBDC89E8A0E034D8ULL, 0xF506A3A0CDDA9AE2ULL, 0xF9075B9637637DC0ULL, 
            0x03A474B1546A03BEULL, 0x0DA85C6D85F7A23EULL, 0x63354FF2E4EFA3F2ULL, 0xD2DD1816DCDB6B0BULL, 
            0x15719609E3064FBAULL, 0x598D140071E0733AULL, 0x19DE4E087AD4BB49ULL, 0x3BA6E9ACB7118C5FULL, 
            0x1E28D4606AA9F027ULL, 0x79E215746ED4B5D1ULL, 0xEC5783FEB857E3CBULL, 0x6C672765636C0F00ULL, 
            0xE4549DF45D923166ULL, 0xC8CE0BAEFD9E71ADULL, 0x870066F1FB10230CULL, 0xA33798F2ADF8C714ULL, 
            0xC55652E2BCB48A1FULL, 0x5BD8DB2B921FC664ULL, 0xB29E552461BD8B8CULL, 0x665A4245A8182EABULL, 
            0x0976C13A42268421ULL, 0x1DF073AD15EC3384ULL, 0x77F05CB8BEC2468AULL, 0x5E0F937988C7C898ULL
        },
        {
            0x3F4C9D9ECEECFAEBULL, 0x40C305A14508138EULL, 0x1B001D9D110AE1B7ULL, 0x0CFC62B3E8A5FA18ULL, 
            0x690E2D8B4B757845ULL, 0x1F9240F585A92F71ULL, 0xB6DF14D6F0630059ULL, 0xDA7D64487040FCE5ULL, 
            0x503DAB2A492130A5ULL, 0x6CC2594F03CE9F22ULL, 0xABC7975A464B1EB1ULL, 0x83AE1A0A37AF4DC2ULL, 
            0x4640CE8C2596AEBDULL, 0x70578AAB18A9D004ULL, 0xA86CB67177717CC0ULL, 0xD7A7FF3664B0923FULL, 
            0xDF51390773420A13ULL, 0x667F041F65E34489ULL, 0x6BB05F0BE79CEAC4ULL, 0xB97C22E661A792E1ULL, 
            0xBF373E3C0F404A4DULL, 0xAB28260CE88FE63FULL, 0x84287DF907972B57ULL, 0x0E678D387C8E17EDULL, 
            0xE123D4A4FCB667D5ULL, 0x6E91348F1B6C9951ULL, 0xDA54833625A4AEA3ULL, 0xFCA54395425563C3ULL, 
            0x17B574F1A898F5D9ULL, 0x27966056BAB02ED0ULL, 0x631445BD6B2BCD0DULL, 0xBC0D4F19446032BCULL
        },
        {
            0x47DE102E773069C4ULL, 0xC84B86458CC2F527ULL, 0xEF1776B523CCD84EULL, 0xCC6DB4E0CB979423ULL, 
            0x872090DF5AD5277FULL, 0x03A0CA0EFB718E62ULL, 0xB498CA29BBDA1AC4ULL, 0xBD834111E26A68FEULL, 
            0xCD5691CC55C995CAULL, 0xA6F1C0AE48EC15EDULL, 0x0DA0D44AE0B4366DULL, 0x8F527F525734DBE0ULL, 
            0x28E2B43B0B88C65DULL, 0x5FFE6D82143747B8ULL, 0xD08FE0A690E5D537ULL, 0x88F0DC8D7B784A44ULL, 
            0xAC3079F862ED6BA4ULL, 0x495F8CF872F7F081ULL, 0x81B007F72DC567DFULL, 0xCCD473347ABC6C83ULL, 
            0xA93120471C1798BCULL, 0x87A83D5A34613821ULL, 0xAFD36036EEEAD4C3ULL, 0xD88718D9A0F3319AULL, 
            0x381AD8E27E1B8FB5ULL, 0x83ACF5B06C59FDA9ULL, 0xB29CE106335EA269ULL, 0xF3165088F9CC0474ULL, 
            0x9A7850CFC0A7B8C9ULL, 0x8EE3482B2E5616C4ULL, 0x4F9E1EDF495D1E23ULL, 0xB371A09481569431ULL
        },
        {
            0x817450417709F564ULL, 0x5DC00138A5363458ULL, 0xA06F18EB25869EF7ULL, 0xE61A4AA8762559C2ULL, 
            0x4F30C8EBC0E626A0ULL, 0xC389A606EBB0454CULL, 0x58FFB3A678D4A127ULL, 0x8DFCA455904B0F06ULL, 
            0xAB11CCF0E68B3202ULL, 0xF43980B120A711C5ULL, 0x09AF45414BA50EE4ULL, 0xE4E0C5EF58DE706CULL, 
            0x878D18B5866FB6FFULL, 0xA33D380E82413340ULL, 0x5F2B3A1303D2DE45ULL, 0xDD0F8C52E775C041ULL, 
            0xC269145FA0F18190ULL, 0xE5E2857484337329ULL, 0x1114E92BD743FF46ULL, 0xE052492626A5FBE8ULL, 
            0x5B4CF2F212E42F2FULL, 0xFCAF9A08C225232BULL, 0x7E5D20117557FE26ULL, 0x440B9C234A1FCF62ULL, 
            0xDDDFE001E89DADD2ULL, 0x643CD306CED0273DULL, 0x6D35C5EEDE28B453ULL, 0x56EF89A408DDBDE7ULL, 
            0xEF34A8552D0405D9ULL, 0xC3ECF89877C475C5ULL, 0x04990F6EDAD16E5EULL, 0x0EB00E6F1FDA6ABEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kSeedConstants = {
    0x4CC9BCB9FF070927ULL,
    0x1ADEC997F3A817F5ULL,
    0xF18483E6B4A9BEDAULL,
    0x4CC9BCB9FF070927ULL,
    0x1ADEC997F3A817F5ULL,
    0xF18483E6B4A9BEDAULL,
    0x31644C7EFC0437DDULL,
    0x3F70671C39F4F8E3ULL,
    0x18,
    0x05,
    0x4F,
    0x65,
    0xA0,
    0xBA,
    0x97,
    0xD6
};

const TwistDomainSaltSet TwistExpander_Naos::kTwistSalts = {
    {
        {
            0x00856A6148B24678ULL, 0xD540B9FA41E2708FULL, 0x1AA792CA69038260ULL, 0x11C7C525E7FA8CFCULL, 
            0x619FE8B16E55A996ULL, 0x73F56186FB5FC340ULL, 0xED7DF24DBA10176CULL, 0x984B32DC44360288ULL, 
            0x7C5BA6FD112F28ABULL, 0xCEDC4B63FADBF3BEULL, 0x1CBC5C0329FD23CBULL, 0x6A44AE23DB124FA1ULL, 
            0x59AA79B9B9D692CBULL, 0x5CDA0FBE5CB914EFULL, 0x590943AA98B66A6AULL, 0x5498DF489A808155ULL, 
            0x28549D6E19CF0DBFULL, 0xBD73001FB580E695ULL, 0x6AF35BF0B8539B97ULL, 0x91B202991D645BB8ULL, 
            0xBDB6CAD78B87ADB6ULL, 0x7269F11BFDD03EA4ULL, 0xBC9E0CF6D1F61A0AULL, 0x9FA879D36EC4E3DCULL, 
            0xF8678F491B4E0EF6ULL, 0x7A93C1D1DED81866ULL, 0x6453DA699234EF43ULL, 0x1B98D6AA3C654089ULL, 
            0x721C790BCCA67FA9ULL, 0xF77E3E3BAD536897ULL, 0xCC4245208AD32213ULL, 0xD5E787B8C883EADDULL
        },
        {
            0x6416A457FE558D8BULL, 0xE59DE936592A7019ULL, 0x571DD07CEB7F83D5ULL, 0x5840F73821C80516ULL, 
            0xA16140DF2CBCA757ULL, 0x036648A7D297402FULL, 0x3CF87A0D8C5343BFULL, 0x9E6C8C04208B3FA1ULL, 
            0x3887152774A6175BULL, 0x301F638BAA785CFFULL, 0x38DC1AFA50147486ULL, 0x973E9AFD689AD30BULL, 
            0x3F664EF5E4504871ULL, 0x95B5CEBF45E61A97ULL, 0x22F494ED006C2276ULL, 0x014FA1CE2E693AFEULL, 
            0x8C42C9EC0F7A36FBULL, 0x3823F903CB4CBEAAULL, 0xA4011483F39C13E1ULL, 0x37E7DAE6362C0FAFULL, 
            0x8A02AF0DC22AA751ULL, 0x4FC044AB935C0C33ULL, 0x40B99B41712B1D8FULL, 0x6AAAA391DBD30F03ULL, 
            0xA9AF0740FA7F3247ULL, 0xA4973D113E5CCC8EULL, 0x474E28E3AB7C9FB3ULL, 0xE0FB13A3933BED8FULL, 
            0x7E62803B4C007028ULL, 0x33A418D29DEA3DEFULL, 0x0786E451D664C9F1ULL, 0x6AF0C252C7AD7936ULL
        },
        {
            0x5F00C817E795C8BBULL, 0x02E2E7346043834AULL, 0x84D78C9DEA0D5FEEULL, 0x7C7A497D69CE2276ULL, 
            0xC04CF20FBE811214ULL, 0xF1FCAB671233CADAULL, 0x159EF8E5F5B18E80ULL, 0xF90FB02DD4F60619ULL, 
            0x5DA6605C9E7D57F2ULL, 0xC625ED68E1E2A1E3ULL, 0x09AA4E4584E36919ULL, 0x3ED25B761A6B12CCULL, 
            0x01AAA76E86924815ULL, 0x2D6AD69EEBC7F52CULL, 0xFC1B458881FC1650ULL, 0xE76892311EC59407ULL, 
            0x60C289D630026561ULL, 0xA3B5666F385ACB43ULL, 0x3C67137B857280FFULL, 0x940DF31E93A8652FULL, 
            0xB0FEFC6D11077823ULL, 0x1459244CF4361D1FULL, 0x9CA0E8BC6892D570ULL, 0x78D724F784BF05D6ULL, 
            0x3694F0C951912EB4ULL, 0x45AD169B1BA4583FULL, 0x738B5CA5B5A01626ULL, 0x9D4AD5D3698E3588ULL, 
            0xC2B11C66BD930233ULL, 0x628FA779ADA23C74ULL, 0xF25C4DCDFD8CE726ULL, 0x4D14C4C81B36CCB9ULL
        },
        {
            0x49F70092D938ECC9ULL, 0x4A338CB9E59C6331ULL, 0x8E35EE00D016E61EULL, 0x6ECC94FB37185E05ULL, 
            0xB9458E0F2B803295ULL, 0x07BA851782EC499EULL, 0x0AB9F53D166A629DULL, 0x75B9191887FA2E54ULL, 
            0xF8568DDC8A1448F7ULL, 0xEC8D60D3299ABB4DULL, 0xC3295D419F8DDBACULL, 0xB21050E2BFF9ED54ULL, 
            0xBCC260710DC50116ULL, 0xE4A561D09D85F3E9ULL, 0x8D3CF3FEEDDD8CF8ULL, 0xF9F84FDA3D6377BCULL, 
            0x84B19E9C85C869A1ULL, 0x2B7C624E5C7C3FEAULL, 0x2F3C4EB02B74734FULL, 0x05AE08677B61B01FULL, 
            0x1387196F5A7203D0ULL, 0x9BE9E97E2D053372ULL, 0x39FE9DDB79297934ULL, 0x07D31D1157F5EEF0ULL, 
            0x1938C3399563AD63ULL, 0x634FFAA08F27C624ULL, 0x3CA079694A60AC35ULL, 0x601E733959155E38ULL, 
            0x13EDE87F13AB97B6ULL, 0xD28ABCE4EDC294D4ULL, 0x9DB5819167587A00ULL, 0x4EBB00AAEFCF4AE0ULL
        },
        {
            0x1E13503EEACF85E4ULL, 0xC81C78A288BB75ADULL, 0xB10138E737C37C4BULL, 0x9D7CC0A690334E01ULL, 
            0x6043396842C84EBFULL, 0xC25E906D1F215B8CULL, 0x4EB7A27DC451F2F1ULL, 0xCE71A39002DE1F5AULL, 
            0xBF759AC6E49110D2ULL, 0x0717B93A873B37F9ULL, 0x6F04BCAAA18BA8A5ULL, 0x897B73BD23A53B11ULL, 
            0x1BD9124EB6017A59ULL, 0x0151570069469CFBULL, 0x9AF3AC62DE99C5B9ULL, 0x06AF852C79E222A8ULL, 
            0xD683D447B792E5FEULL, 0x7FE9D80BAB150473ULL, 0x3244CED3020848D0ULL, 0x1654B39CFC1FC44BULL, 
            0x957AAE9A3ECF5EC7ULL, 0x4EE2E0BD4DDF1C7FULL, 0xFA436FF077D326EBULL, 0x67F16957BDC47141ULL, 
            0x89BCA935F0051EA1ULL, 0x4552013BE38FED74ULL, 0x8ABF0BC0C6F693AAULL, 0xA2F1D8FF39F0F300ULL, 
            0xE518C92A4055895DULL, 0xF40B6C7F0511F1FBULL, 0xB94BBD0069FD6C86ULL, 0x5788F5F1518EE894ULL
        },
        {
            0xE7011149796EEA36ULL, 0xA801AF6C1389F7E0ULL, 0x23B3124D6BC88816ULL, 0x3B40D8D0B8FE5561ULL, 
            0xEFD72C7D478451F6ULL, 0xCF31FAB0D71336E9ULL, 0x7D181376C0589A26ULL, 0x11E49BFDCF4B4EBDULL, 
            0xC01265DEC25CBA20ULL, 0x8E1F32C04BDF56E0ULL, 0xCBA52C17FBCDD4D1ULL, 0xA31C477C906393E5ULL, 
            0xD312F4B570806A5DULL, 0xAE9766C54493F637ULL, 0x26F3F597D1403E11ULL, 0x0E4E012CF45FC02FULL, 
            0x064ADDBBBCD7212DULL, 0x84E715D937DC9FA9ULL, 0xADF5D1A8E9743A4CULL, 0x65473E5742AB05B5ULL, 
            0x639C6403261368B8ULL, 0x34AA04F057F52D9FULL, 0xCFF808CBC544EC5FULL, 0xFF56AE98771C4AF8ULL, 
            0x7CEDC6EB699C8F95ULL, 0xA08C1DC17990AE55ULL, 0xD73530E7F59ADAFEULL, 0x3331197D90F5CD7AULL, 
            0x0B714D80021BAB81ULL, 0xE0A5690BB3928690ULL, 0x9303BF42182B5DC9ULL, 0xFC16C0849FD7B810ULL
        }
    },
    {
        {
            0x0C5E11EC91AE7A5FULL, 0x7B69DFB215E6B350ULL, 0x692BF695B73BF1E7ULL, 0xF66F0E1B8467D67FULL, 
            0xFFFCDA57910DAFCEULL, 0x5E2FF08B8E08EAA3ULL, 0x856FCF1C2E8359DCULL, 0x707522D8C801FD87ULL, 
            0x30AFE15534C689F0ULL, 0xB2788E264FD47506ULL, 0x3EC4926BDACF2481ULL, 0xD51EA02233BB8220ULL, 
            0x0A07514932EA5BFFULL, 0x1F25071D85C652E0ULL, 0x8FE73AA91EA266B9ULL, 0x21F5557584864065ULL, 
            0x47DF13A11F86B92DULL, 0x7C4CA87FFA59BC35ULL, 0x10FED20FBB0CA296ULL, 0xB2F07BE283493A93ULL, 
            0xE47D182FC51506E1ULL, 0xCEDDBEF9ACEFAE01ULL, 0x2523CACE4C799018ULL, 0x1C205D0C8B3364CCULL, 
            0xC005554162A22663ULL, 0xDF8FD017CD2A8350ULL, 0xAE56C5F3F23DB7D8ULL, 0xEC495F6C6DFFFFE2ULL, 
            0x0CB076275BED001FULL, 0x8A8E6AD47FDB347EULL, 0xA6706656193C2BD5ULL, 0xBE44EB706104D65FULL
        },
        {
            0x9F757FD6D3559475ULL, 0x0423F76C0B91067BULL, 0xF42391DF3AD0AB19ULL, 0x2A8633349E3BB15EULL, 
            0x691064CBC629D9E5ULL, 0x5745EF0CCF514F12ULL, 0x55AA1B8B9576D0EAULL, 0x76D3445895D9F291ULL, 
            0xEAFD089EEC5A98EDULL, 0xCD0263EAEC9E6D8AULL, 0xD9F82828F50FE9B8ULL, 0x9B565A1FC0BE4541ULL, 
            0x026D82E03A75F7E3ULL, 0x779676FCDD095754ULL, 0x249AA1B00A291DAEULL, 0x3385D461701DA4BCULL, 
            0xAF441D9817A9D144ULL, 0x4B39A3F04C93ABD0ULL, 0x229B80E1BE55AFEBULL, 0x3ACA32537214DC5AULL, 
            0x184DDCE2307BE3A1ULL, 0xB6A9CFB306CFFD58ULL, 0xFCC8B6A456CA0A03ULL, 0x073D07BDBC5DA36DULL, 
            0x851E499D329B5E99ULL, 0x1DBC9B8A8767558DULL, 0xC923654B292077E9ULL, 0x2E082AAA4AC737E7ULL, 
            0x931D02D1AF05830CULL, 0xB18F711C75BAE79DULL, 0x227C8D40F6503325ULL, 0xF23EAFD87AA02583ULL
        },
        {
            0xA84B6DBEAF3F7570ULL, 0x5E5BED43E343A1DEULL, 0x43BBC64E777285C6ULL, 0x6DB4BD15A3E4F570ULL, 
            0xA90A97094E581F3BULL, 0xE27B3839411CDE3BULL, 0x22924E03776E8E5CULL, 0xC5A1EF6D7AC7F172ULL, 
            0xBB78BAA00FD4B59BULL, 0xAD50F2BFA70B00BDULL, 0x6084448DD786BFCEULL, 0xC5D0EC5071E3968EULL, 
            0xA15D68BD0F8BABECULL, 0x3E89E08A0931F33CULL, 0x21DBC7A6DBDB32CEULL, 0xA8F7CD997779BD46ULL, 
            0x514A0FC9AE553BFAULL, 0xEAAB4E37EBC00A82ULL, 0x29CFE3BD9141CFE2ULL, 0x668359278B6B02D2ULL, 
            0x48574DDB0C348AE8ULL, 0xB4199734D28C29F9ULL, 0xDDEDD0BA93C1B688ULL, 0xBB4925B0D0F7FFDCULL, 
            0x147FDD3E89E3FCFFULL, 0xCBB7BBF304BE1F9FULL, 0x2C0FDE8BAAA750A6ULL, 0x1DC0B692E1709486ULL, 
            0x6D6BCD4161137FB5ULL, 0x308D25B8A832E4A4ULL, 0x04A01C9652FBB186ULL, 0x69CEF4007F99C4E1ULL
        },
        {
            0x5A002B0F06F40A5EULL, 0x6BC2065B791ED7B9ULL, 0xBDFB3A686D3E2C62ULL, 0x4EEE54DB502D9230ULL, 
            0x960894AFF0A2B997ULL, 0x1CC59247789C9F5DULL, 0x4F3D22C27A8E0C57ULL, 0xAC81C274F5884C4AULL, 
            0xC92D7FC7F243346CULL, 0xB034B865BBB863F0ULL, 0xA68ABB5BD867C310ULL, 0x2B89A9143FB353CBULL, 
            0xAF3F03C6B1403947ULL, 0xF14AEA9959940A73ULL, 0xF018C34E01B58792ULL, 0xCFE40299D95B486EULL, 
            0x07CFD1C20AC8D52DULL, 0x8EE23A399313B228ULL, 0xE73ACA96FF214A3BULL, 0x42EFB0FE8BDA0A31ULL, 
            0xE87F474A392D306FULL, 0xC6E9AC603AD86579ULL, 0x31D22E48B4DE0D56ULL, 0x92FE30EF269535FEULL, 
            0x48C93DF54E253FEFULL, 0xE474A65141E17FABULL, 0xA521DF51BCC5DCF8ULL, 0xED79A103C1953BEAULL, 
            0x7708D1678B791F45ULL, 0x10ED814F9B217573ULL, 0x4F6A85AAEE012238ULL, 0x311F6CABF259184CULL
        },
        {
            0xD8E52C943BE4D7F4ULL, 0xA5544EA6ABD0413CULL, 0x7176F389E3C2D469ULL, 0xB5A20882FA4C0D76ULL, 
            0x6106E712D4A8AD03ULL, 0x43743228D137EC61ULL, 0x497C716A1B5076F9ULL, 0x6FBFE44B79F08052ULL, 
            0xEDFA5ED1EBF02067ULL, 0x1C2DF9112359D49BULL, 0x850CF0AB73B9D67AULL, 0x24A014C07BD84EEAULL, 
            0xBD6EAD24323BE855ULL, 0x30BE35311118263DULL, 0x435B8DF3072C0A71ULL, 0x45C4E883D47B6D9EULL, 
            0x36ABAA3F32E33BB6ULL, 0xAAACF542C747340AULL, 0x2297D032AF7E6984ULL, 0x335A3919A348CE37ULL, 
            0xED36600B1A314F86ULL, 0xDA53F7B1C05C6763ULL, 0xBD651DFAA9CF4C66ULL, 0x4576ED9EF11ECA75ULL, 
            0x656C83944726A9F3ULL, 0x3FEA8183EBBF0545ULL, 0x85ADADB9B6A7B132ULL, 0x7A56FF2E4ED4333EULL, 
            0xB34EBAFA4F4A7533ULL, 0x32B0BBF148C592EFULL, 0xFCB9BACDD500FE0DULL, 0x7538DFA4FBEE2F01ULL
        },
        {
            0x60E7DDCBA593E99AULL, 0x042672C66B9360D5ULL, 0x00E128078A483C14ULL, 0x61482AF69CACCE8DULL, 
            0x3F58F86DEA28B014ULL, 0x699D88EA07C9B6D0ULL, 0xA1EB47A797CDBC10ULL, 0x8D4B303A38740F6BULL, 
            0x911E78CDA3C451CDULL, 0x62A7503490ECA4E5ULL, 0x1CFDEB95DA832722ULL, 0xE72013670FF3434AULL, 
            0x75D49F4375C49F40ULL, 0x5DD6E0D1D109BB22ULL, 0xA0F311361FAA797EULL, 0x0440CFD001C5660AULL, 
            0xD8D4DB639116C7A9ULL, 0x794CB9BF1A268116ULL, 0x44F19355947405F4ULL, 0xBA53048DC39E62D1ULL, 
            0x804658CC1AF71549ULL, 0xC40AAFA888C58777ULL, 0xE186C0B8F0FB3926ULL, 0x44502D10A9CEEC24ULL, 
            0x32CC8E7E518811B0ULL, 0x9026142383EA090CULL, 0x717AC905FB2997A1ULL, 0x358BCE5E9D8244B9ULL, 
            0xADCBA5AB95A11628ULL, 0xDEB812DD5703B4D9ULL, 0x295AE07383923D78ULL, 0x95642503D64E19A1ULL
        }
    },
    {
        {
            0x74D3D1E146C78DEFULL, 0x598C863C874F094EULL, 0x3436C7D808CD7217ULL, 0x7D08C7388CBB17F2ULL, 
            0x29D3759E66085B75ULL, 0xF123F022D4DADD73ULL, 0xFCDD1624483C661BULL, 0x083E3B4B9C3E448DULL, 
            0xC8F45C315939EC89ULL, 0x7CD9027301C633C6ULL, 0xDC7F6AE1DF79C0CFULL, 0x2504EB05ADCB29CDULL, 
            0xB844B444C6E81BA7ULL, 0x0CCC713E621D2100ULL, 0x165EBD4765A77BECULL, 0x63391BE433B5F448ULL, 
            0x170D10446D9B833BULL, 0x761BE45D0A794B36ULL, 0xD419C0E5D84007E7ULL, 0x1F5673E33B417F27ULL, 
            0x7FF67717CDF1F459ULL, 0x3E91AD05CF41DE0EULL, 0x9D9FD95692A226D5ULL, 0x06B36590568A37B9ULL, 
            0xA78FA8AB6E9EDCDDULL, 0x455335C76109A140ULL, 0x109BC1749AD4CE36ULL, 0x537F0C9E730B50F2ULL, 
            0x30FB694C8406E697ULL, 0xBF8C94D0A799A427ULL, 0x5E9C7B1125CF2AE2ULL, 0xE066561CC73BAA30ULL
        },
        {
            0xAD8379472DDB5BABULL, 0x3C92008707A03C60ULL, 0xBC17AAAB57329F8BULL, 0x858C95ED29B17F47ULL, 
            0x16C4B9437C95B175ULL, 0xAA75124E53F90250ULL, 0x8D7E8424352C8340ULL, 0x540E46EDC321396DULL, 
            0x588A30773BD1D402ULL, 0xF32D7080DAFF5F75ULL, 0xDCD63C10940D1309ULL, 0x032B9643A3F01728ULL, 
            0xD6952D1EB32390A1ULL, 0x2071F5BED61B108EULL, 0x0B1974DCB1A022A0ULL, 0x84C3731B512BB3B3ULL, 
            0x39B46D88455FB0FEULL, 0x3002F9C10A427C3BULL, 0x2E922997BF7E5B3BULL, 0x0EA4691E9B1239B7ULL, 
            0x8113FCE84109B958ULL, 0x8AC7348BCA085383ULL, 0x159A224E7D4CF437ULL, 0xA34A03FEC6794DC2ULL, 
            0x701D41FD41EC6719ULL, 0x4ABEACCF1B2B965BULL, 0x9B0042042A67BE42ULL, 0x1F9E1D5EDCCBF3B6ULL, 
            0x95FCE7B491685200ULL, 0x71008E069D855450ULL, 0xE066F257DA0808E6ULL, 0x6A103EE3F2B0B6D8ULL
        },
        {
            0x5ECAF6C1B66834BDULL, 0x1B7368006FD0D04BULL, 0x17A99C5539DA0014ULL, 0xB0F3CF839213EC88ULL, 
            0x01D26896BA1A10E5ULL, 0x8E5340C3DDB6E662ULL, 0xC39D0D78A9ED78B4ULL, 0x3EAF048B8D395E77ULL, 
            0x7077F51C7FBCAC37ULL, 0x1F10CE4F4E54B9C2ULL, 0x7484B2BF247C105EULL, 0xE0647C47705BFDFEULL, 
            0xA249C129558E48B1ULL, 0x0333036C0267F201ULL, 0xEE8CDB5272D53AEBULL, 0xDFD14DC4FA3BF0F9ULL, 
            0x794FA01FFD750FA8ULL, 0x69DDB22DCBFD68AFULL, 0x97B7833E9B87F08FULL, 0xD4A58E5272583E5EULL, 
            0x5A79D7B9A7E35549ULL, 0x72E037BD434BCD37ULL, 0x5D49CE7BD3FFE24DULL, 0x06B25CE4EA58DD9AULL, 
            0xEA404CEBEB63C8AEULL, 0xD50C92F62DFC1BECULL, 0xEB444674378942C6ULL, 0x5F1ACF38A29929A4ULL, 
            0xAF0B3EFEBF1C5D43ULL, 0xC5A4C495509600CBULL, 0x6A88E2F3982E7E6EULL, 0x590EB25B54834D83ULL
        },
        {
            0x5323B73A97B05680ULL, 0x0DB3CA519FBF9428ULL, 0x9303EF7166495556ULL, 0xCBCBA5BC19DD96CFULL, 
            0x76ABBA781E1CE7FFULL, 0x9B9292C0F17A56C4ULL, 0x972F16E5643330FAULL, 0x85C32B4A6C4C832EULL, 
            0x028997B5E05441A7ULL, 0xBC0E67ACA87C3269ULL, 0x1361B8C5E302F8F4ULL, 0xC3816CFEA05B509EULL, 
            0x281E6517038179ADULL, 0x37D9DE75CEC7BDB2ULL, 0x1981B4E4DEA68F4AULL, 0xA0D532BFB6A425CCULL, 
            0xFD8646C00979C741ULL, 0xCDFC897353D12236ULL, 0x05FC1843D4311EF9ULL, 0x8D6D8642B12EC6D3ULL, 
            0xFA9E09E7C3858214ULL, 0x4DA3860AED7CBC0DULL, 0x0F396D74778A570AULL, 0xF29D362A5D87757BULL, 
            0x3F2DD39575DFEC83ULL, 0x4E0D59B9E62D46F2ULL, 0x586E7661964909AAULL, 0xB70A66969E226BBEULL, 
            0x26CD899780B81B7EULL, 0x2E0D87888FEB2F62ULL, 0xCB6DAAA63BD52EEFULL, 0xFDD05E5432E9F23DULL
        },
        {
            0x5FCDD7DCC56233EDULL, 0xF72DC17C92D4C477ULL, 0x63A33C20C9589BC3ULL, 0x44A9C25742E170A8ULL, 
            0xD10E52001064917DULL, 0xFCE472B2AB852ECCULL, 0x32A30DFD3A266A89ULL, 0x999815309B5538F9ULL, 
            0x0F3E12EB97037D21ULL, 0x05A397C0D07C9AC6ULL, 0xBD76DAB93FE96D5BULL, 0x607C278A7551E7FDULL, 
            0xC56CF3CA392423FDULL, 0xF158342EFD603C14ULL, 0xA35A17FE636CE354ULL, 0x967952A5ACD01941ULL, 
            0x7FF44E5957A17BF3ULL, 0x047C8B5C022BA6F5ULL, 0x7C574CFB6E3822F2ULL, 0x8B793800C5D6B832ULL, 
            0xFE5A06A1B79993B9ULL, 0x21CDF6829A920C57ULL, 0x351E9FA2F1D00D5CULL, 0x1616316BC43936E1ULL, 
            0x9E4F26A75F1FA3E7ULL, 0x04CDD2471B7E098FULL, 0xA43BD4E48A075A4FULL, 0xE55F9A5A6F132939ULL, 
            0xA57F4A762996C9E2ULL, 0x863EBB5F630BE395ULL, 0x8A3F76387183CCEAULL, 0xDE27F4055C5E6499ULL
        },
        {
            0x6602A8B36B4CD66DULL, 0x198504CA529B0179ULL, 0x2746B6E06AC6D68EULL, 0x7986BEAAFFDB8D77ULL, 
            0xE0106466CDA68305ULL, 0x808777B9CC35CA04ULL, 0x5399F71D80C094FCULL, 0x8D3F6E6E37C32BA0ULL, 
            0xD12B30BA0EFE45B7ULL, 0xF27A5DCDA2248D9BULL, 0xA9469D67EB2925ECULL, 0xBC36AEBA48EBF1C6ULL, 
            0xB57740B67F6AA981ULL, 0x07D81E8C8FAF595CULL, 0x83167F69600DBFA4ULL, 0xF67E3E9FCE6FF382ULL, 
            0xE05F771A9F335F52ULL, 0xF9A9B60E16D02139ULL, 0x2B6095DBE70C3318ULL, 0x323EC5651C2AB8C0ULL, 
            0xCF402311F0F75F8CULL, 0xFC1BF41913E1EB21ULL, 0xB1F64B63A4368494ULL, 0x9052F4AEA52D9FC1ULL, 
            0x9AD9A5510FD174F0ULL, 0xF94BAC41B737F9E9ULL, 0x272C5C9D8E8B6BD5ULL, 0x23DA75D2E27E56D7ULL, 
            0x065140AE61C6E66DULL, 0xFFE65B04019A936FULL, 0xC58CA2DC2E3B504DULL, 0xC3DCA20959609946ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kTwistConstants = {
    0xCFDE81C8E830CFDBULL,
    0xDF30DCE10B5D3EB3ULL,
    0xB69EFA2722D2D1FAULL,
    0xCFDE81C8E830CFDBULL,
    0xDF30DCE10B5D3EB3ULL,
    0xB69EFA2722D2D1FAULL,
    0x3E3B955F65113171ULL,
    0x9C481A44E69D6ED1ULL,
    0xFB,
    0xC6,
    0xCF,
    0x9C,
    0x61,
    0x78,
    0x79,
    0x45
};

