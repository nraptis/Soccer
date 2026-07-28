#include "TwistExpander_Menkent.hpp"
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

TwistExpander_Menkent::TwistExpander_Menkent()
: TwistExpander() {
    mDomainBundleInbuilt.mKeyRotateASalts = kKeyRotateASalts;
    mDomainBundleInbuilt.mKeyRotateAConstants = kKeyRotateAConstants;
    mDomainBundleInbuilt.mKeyRotateBSalts = kKeyRotateBSalts;
    mDomainBundleInbuilt.mKeyRotateBConstants = kKeyRotateBConstants;
    mDomainBundleInbuilt.mKeySpawnASalts = kKeySpawnASalts;
    mDomainBundleInbuilt.mKeySpawnAConstants = kKeySpawnAConstants;
    mDomainBundleInbuilt.mKeySpawnBSalts = kKeySpawnBSalts;
    mDomainBundleInbuilt.mKeySpawnBConstants = kKeySpawnBConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Menkent::KDF_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnowLaneA,
               std::uint8_t *pSnowLaneB,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pPrevious == nullptr) ||
        (pIngress == nullptr) || (pCarry == nullptr) ||
        (pWandererA == nullptr) || (pWandererB == nullptr) ||
        (pWandererC == nullptr) || (pWandererD == nullptr) ||
        (pWandererE == nullptr) || (pWandererF == nullptr) ||
        (pWandererG == nullptr) || (pWandererH == nullptr) ||
        (pWandererI == nullptr) || (pWandererJ == nullptr) ||
        (pWandererK == nullptr)) { return; }
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

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    TwistExpander_Menkent_Arx::KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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
    TwistExpander_Menkent_Arx::KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

void TwistExpander_Menkent::KDF_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnowLaneA,
               std::uint8_t *pSnowLaneB,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pPrevious == nullptr) ||
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

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    TwistExpander_Menkent_Arx::KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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
    TwistExpander_Menkent_Arx::KDF_B_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

void TwistExpander_Menkent::KDF_C(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnowLaneA,
               std::uint8_t *pSnowLaneB,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_C(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pPrevious == nullptr) ||
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

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    TwistExpander_Menkent_Arx::KDF_C_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_C_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_C_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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
    TwistExpander_Menkent_Arx::KDF_C_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

void TwistExpander_Menkent::KDF_D(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnowLaneA,
               std::uint8_t *pSnowLaneB,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_D(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pPrevious == nullptr) ||
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

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    TwistExpander_Menkent_Arx::KDF_D_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_D_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

    TwistExpander_Menkent_Arx::KDF_D_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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
    TwistExpander_Menkent_Arx::KDF_D_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnowLaneA,
                 pSnowLaneB,
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

void TwistExpander_Menkent::Seed(TwistWorkSpace *pWorkSpace,
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
    mDomainBundleInbuilt.mKeyRotateASalts = kKeyRotateASalts;
    mDomainBundleInbuilt.mKeyRotateAConstants = kKeyRotateAConstants;
    mDomainBundleInbuilt.mKeyRotateBSalts = kKeyRotateBSalts;
    mDomainBundleInbuilt.mKeyRotateBConstants = kKeyRotateBConstants;
    mDomainBundleInbuilt.mKeySpawnASalts = kKeySpawnASalts;
    mDomainBundleInbuilt.mKeySpawnAConstants = kKeySpawnAConstants;
    mDomainBundleInbuilt.mKeySpawnBSalts = kKeySpawnBSalts;
    mDomainBundleInbuilt.mKeySpawnBConstants = kKeySpawnBConstants;
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
    std::uint64_t aPrevious = 0xB15CC4FD2D363C3AULL;
    std::uint64_t aIngress = 0x85B68E50C3E3B422ULL;
    std::uint64_t aCarry = 0xCF8012B741C9E0A8ULL;

    std::uint64_t aWandererA = 0x87F7C3242F3242E5ULL;
    std::uint64_t aWandererB = 0x8F2164FA0A9B6313ULL;
    std::uint64_t aWandererC = 0xBD11EADF58A128B4ULL;
    std::uint64_t aWandererD = 0x86742B0B8702DC5BULL;
    std::uint64_t aWandererE = 0x8AC88E8D16D15479ULL;
    std::uint64_t aWandererF = 0xD205466FF06DCBE1ULL;
    std::uint64_t aWandererG = 0xB62D7773B6A7B32BULL;
    std::uint64_t aWandererH = 0xFF5A1F5C95A30C51ULL;
    std::uint64_t aWandererI = 0x8194F2261E5F49B9ULL;
    std::uint64_t aWandererJ = 0xD36AAAE13D48C3B8ULL;
    std::uint64_t aWandererK = 0xB883F543C89136DBULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xCEA2E783D0B825E7ULL;
    aIngress = 0xD39C1F633AF83B8EULL;
    aCarry = 0xD3C6452C8B99E5B7ULL;
    aWandererA = 0xD07C5B5A1B6A0D0FULL;
    aWandererB = 0xF9A93491309ECA16ULL;
    aWandererC = 0xEA2E56386B33BD23ULL;
    aWandererD = 0xCFCE9EB03D4691A4ULL;
    aWandererE = 0xB908C91D741DD53BULL;
    aWandererF = 0x905C92D15237F5E2ULL;
    aWandererG = 0xCCC385BE1B487628ULL;
    aWandererH = 0xCD7A7863FC456EB9ULL;
    aWandererI = 0xB02A8AC436E87DBFULL;
    aWandererJ = 0xF046215EE6B66AC1ULL;
    aWandererK = 0x8F1CEE996878C16DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // KeyRotate B
    //
    aPrevious = 0xEB5762015B549FFFULL;
    aIngress = 0xBCA6091103C81674ULL;
    aCarry = 0x901B911254AF500BULL;
    aWandererA = 0xB8B09C1A1003E324ULL;
    aWandererB = 0xA2D9E6962BAB6C2DULL;
    aWandererC = 0x8C3A99EA939AC8FDULL;
    aWandererD = 0xABF15128E379ED07ULL;
    aWandererE = 0xAB22F0148C6292AEULL;
    aWandererF = 0x9FE474662DE389F8ULL;
    aWandererG = 0xCD0E9B9B28369A4BULL;
    aWandererH = 0xDBA719557CC34AEAULL;
    aWandererI = 0xF1B5A9CB2C66D047ULL;
    aWandererJ = 0xFD1A1C8454455C62ULL;
    aWandererK = 0x9120F4A48E3A80ACULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // KeySpawn A
    //
    aPrevious = 0xF8B3DBA10855744EULL;
    aIngress = 0xA628ADBFEFB6C920ULL;
    aCarry = 0xC3F1365AA06C1A9CULL;
    aWandererA = 0xD12DF1E098297848ULL;
    aWandererB = 0x9755051B418887CBULL;
    aWandererC = 0xFA8E01B0BC5CAAEAULL;
    aWandererD = 0x87D09C66085A60A0ULL;
    aWandererE = 0xCE47156CB52179E5ULL;
    aWandererF = 0xCC68A364C779595CULL;
    aWandererG = 0xF2D093B93FDB3E1EULL;
    aWandererH = 0xEFEA690CA43A650CULL;
    aWandererI = 0xEFD36D22C3D12232ULL;
    aWandererJ = 0xFC425804FDAD4194ULL;
    aWandererK = 0xC6F0AB72D4A3E57EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // KeySpawn B
    //
    aPrevious = 0xD5546B3010919D21ULL;
    aIngress = 0xE9002E18E8365AE8ULL;
    aCarry = 0xC0BB4CF0893E4AFAULL;
    aWandererA = 0x941F721739FD6088ULL;
    aWandererB = 0xB90EA1DE1730609AULL;
    aWandererC = 0xDC32F163405906CDULL;
    aWandererD = 0xE31EFE26ECFB7713ULL;
    aWandererE = 0xF78CA5EAD0678944ULL;
    aWandererF = 0x9792D61A96390A28ULL;
    aWandererG = 0xB72BD98C5CC88A5EULL;
    aWandererH = 0xEEEE86030CF78A2BULL;
    aWandererI = 0xD3DD5CD6F233D57EULL;
    aWandererJ = 0xDA27327A4545FF68ULL;
    aWandererK = 0xE2E11C9660FEF7AEULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // Twist
    //
    aPrevious = 0xB71BD8F965B45C53ULL;
    aIngress = 0xCF043A14F1AC5822ULL;
    aCarry = 0xF7799A62CE9763E3ULL;
    aWandererA = 0xDBD88BE1E6BD8726ULL;
    aWandererB = 0xC62649A298E2078AULL;
    aWandererC = 0xCF06835086888004ULL;
    aWandererD = 0xB0C0AB78E3FADA92ULL;
    aWandererE = 0xDC5BC9E7950BBC2DULL;
    aWandererF = 0xFDF20A331AA14CA6ULL;
    aWandererG = 0xDA5AF809241294FEULL;
    aWandererH = 0xF875F3CFA63FB711ULL;
    aWandererI = 0x9B36EFD88758FA00ULL;
    aWandererJ = 0xAC96E292679C204CULL;
    aWandererK = 0xAFFFF90AB7BCDF58ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // Seed
    //
    aPrevious = 0xA19918FF88700B19ULL;
    aIngress = 0xC7AC6F0FC74A1529ULL;
    aCarry = 0xE1EB768C4BF9831CULL;
    aWandererA = 0xD0531F3ECFA2A30EULL;
    aWandererB = 0xE9F9337866285B87ULL;
    aWandererC = 0xD1EC3BDD3AAD734CULL;
    aWandererD = 0xB5E0240B2693098BULL;
    aWandererE = 0xFB8BB4B23E89C9EAULL;
    aWandererF = 0x81DCEBE7E1A13277ULL;
    aWandererG = 0xFB1D9E8B04106A02ULL;
    aWandererH = 0xFFA76D88FC5EB902ULL;
    aWandererI = 0xD3F945F31460FCC6ULL;
    aWandererJ = 0xA9D969B6FB52FA84ULL;
    aWandererK = 0xBE65CDA831E1F9F0ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // Seed stages
    //
    aPrevious = 0xF2FAC881C57CC13FULL;
    aIngress = 0xC6E6481CE7252E9CULL;
    aCarry = 0xAAB170D045BA77C7ULL;
    aWandererA = 0xE9258D486F93D887ULL;
    aWandererB = 0x96D966DAF784CAC6ULL;
    aWandererC = 0xBC3884302FF962A9ULL;
    aWandererD = 0xFDD1C3E09AB43DB2ULL;
    aWandererE = 0xCD83206AD1032597ULL;
    aWandererF = 0x818D9CBE61E7B49FULL;
    aWandererG = 0x8972BD8AE748A663ULL;
    aWandererH = 0xC2F8F3C4733B7DEDULL;
    aWandererI = 0x87685B1429129A74ULL;
    aWandererJ = 0xFAD481CC70B957DDULL;
    aWandererK = 0xE2152BC0C3696C48ULL;
    //
    TwistExpander_Menkent_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_C(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_F(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_I(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_L(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Menkent_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::KEY_B_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistSquash::SquashB(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Menkent::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pCrossLaneA,
                                       std::uint8_t *pCrossLaneB,
                                       std::uint8_t *pCrossLaneC,
                                       std::uint8_t *pCrossLaneD,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace,
                              pSource,
                              pCrossLaneA,
                              pCrossLaneB,
                              pCrossLaneC,
                              pCrossLaneD,
                              pDestination);
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pCrossLaneA == nullptr) || (pCrossLaneB == nullptr) ||
        (pCrossLaneC == nullptr) || (pCrossLaneD == nullptr) ||
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
    std::uint64_t aPrevious = 0xF221A8F39258712AULL; std::uint64_t aIngress = 0xAF92E5F9294E2A02ULL; std::uint64_t aCarry = 0x9381A8BDEB607DBAULL;

    std::uint64_t aWandererA = 0xCABFC8125141CBD1ULL; std::uint64_t aWandererB = 0xBA59A708F96A051CULL; std::uint64_t aWandererC = 0xB831DC30643E4DDCULL; std::uint64_t aWandererD = 0xADCA5820F6EAA8B9ULL;
    std::uint64_t aWandererE = 0xDBCA4F0D23D7BEC3ULL; std::uint64_t aWandererF = 0xA3E557E96AD0AEC5ULL; std::uint64_t aWandererG = 0xE77E937DEC803376ULL; std::uint64_t aWandererH = 0xBEA1EEFD330DD227ULL;
    std::uint64_t aWandererI = 0x9FADF8EE2CD65C7FULL; std::uint64_t aWandererJ = 0xFDFEDCEE9F6F0981ULL; std::uint64_t aWandererK = 0xD957364BF82E202DULL;

    // [twist]
        aPrevious = 0x88C073284B6E6B6FULL;
        aCarry = 0xC3864623F7F83850ULL;
        aWandererA = 0xFF48E8F2930596FEULL;
        aWandererB = 0xD46AA09B0D65D336ULL;
        aWandererC = 0xB5AEAE333A07FAE1ULL;
        aWandererD = 0xC6BDB28135439B8FULL;
        aWandererE = 0xEE8DF84C49F9722FULL;
        aWandererF = 0xA4CB94953A16AFEEULL;
        aWandererG = 0xABC92DDCCDD800A5ULL;
        aWandererH = 0xDA3EFB93CCF5AEE7ULL;
        aWandererI = 0xB1A43E6A4B0FA13EULL;
        aWandererJ = 0xEF05DE8D6F36D5B7ULL;
        aWandererK = 0xD92D90463E72930DULL;
    TwistExpander_Menkent_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::TWIST_C(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::TWIST_F(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

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
    TwistExpander_Menkent_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Menkent_Arx::TWIST_H(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistSquash::SquashC(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Menkent::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  MUTABLE_PARAMS) {
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
    TwistExpander_Menkent_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::GROW_A_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgD;
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
    TwistExpander_Menkent_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Menkent::GrowKeyB(TwistWorkSpace *pWorkSpace,
                  MUTABLE_PARAMS) {
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
    TwistExpander_Menkent_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::GROW_B_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgD;
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
    TwistExpander_Menkent_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Menkent::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 18 of 33
    // Exploration cases: 0
    // Structural maximin 526 / 674; family total 9135
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
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
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1915U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 18 of 33
    // Exploration cases: 0
    // Structural maximin 521 / 674; family total 9058
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 925U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Menkent::kKeyRotateASalts = {
    {
        {
            0x0B65F73F017E6CBEULL, 0x2B90198C9C3896CBULL, 0x02E53F1A61134960ULL, 0x2381461AFA4CC218ULL, 
            0x7092BE6AF71E641AULL, 0xEC4C444521354926ULL, 0xB955C385491C6708ULL, 0xC7ECED904577C8EBULL, 
            0xC738849B1198A5F1ULL, 0x5A208AE7A6138A23ULL, 0xAD3BC766CEEF445AULL, 0xB0C492BB81BE4112ULL, 
            0xB563101536E4923BULL, 0x707822AA1B6BAFD2ULL, 0x9E524EDFEB98DA8FULL, 0x1D69130ABC8E0091ULL, 
            0x03CCEF889D058EDBULL, 0x2328B3BC00007DB5ULL, 0x34964095DE6F87A0ULL, 0x81116D4F41FD90C8ULL, 
            0xC59EBE3B0F2DABA7ULL, 0xAF297866756A8C7CULL, 0xC37E0BEE83C70027ULL, 0x2A5C245C01EB946EULL, 
            0x909EADECD079303CULL, 0x7A6F2AB94698D22BULL, 0x3EE4F64C843CE492ULL, 0x6772C8A3722BDEA5ULL, 
            0x1D68D1BBD2A2EC12ULL, 0xF951621FB50C66ACULL, 0x704FE702CFA4D6A5ULL, 0xBBD2BB270B6B683EULL
        },
        {
            0x2FA790BBFDCF5AFBULL, 0xFBC21C154CA5EDB7ULL, 0x09EC9BA93E5EE52FULL, 0xF374CABC900EBEA1ULL, 
            0xAD155AD44802C380ULL, 0xD0BC17ECFEECD166ULL, 0x37FD8C048F2854D6ULL, 0x3B0DDF9F6BC74121ULL, 
            0x420045F1E63C2B9FULL, 0xD769293A25009F00ULL, 0xA92F7104C98659D4ULL, 0x94B2EF20DC52D964ULL, 
            0x6B1930CF967217C4ULL, 0xF11B34CB79529BC6ULL, 0x0A37AAA16F1F50DAULL, 0xCAB89A32651F6989ULL, 
            0x35F5B456B9FAA7E2ULL, 0xD67D91294DB4919AULL, 0xD7D41E21044D47EBULL, 0xABCA558B15AF0162ULL, 
            0xB1E5475EF02641D1ULL, 0xCE6C8DE55D9D8C76ULL, 0xF1BD705EB406686EULL, 0x61C5332302009177ULL, 
            0x76A79B52D61DBD54ULL, 0xA7E55E7CA9AA8027ULL, 0x414C07E92E297157ULL, 0x2AAC35DF161FA5CCULL, 
            0xE60E3C624B1C38F6ULL, 0x25B024D9A9C81D34ULL, 0x976615B6AD466500ULL, 0xF3827E53D312D570ULL
        },
        {
            0xE756F67C06997913ULL, 0x35314ED93EBDC41EULL, 0x6F72B6495718D67EULL, 0xF2B7C4952028C0E0ULL, 
            0x46FB8F9800B7CF81ULL, 0x34A76AEA5EB897BFULL, 0x765352E816563C0CULL, 0x9CDFA4D93099667EULL, 
            0x2E90EFD5224719BCULL, 0xE43A2B0FC01B1283ULL, 0x9BE1D68A9DCB97D8ULL, 0x8D58CC4D69BE9A92ULL, 
            0x7128F8EC053AE608ULL, 0x77CBE012A899D535ULL, 0x43C873430F05BF9BULL, 0x436DDC05C0967E97ULL, 
            0x6A81A37648468E19ULL, 0x8BCA9A872088DEABULL, 0x41BDA62FB5645698ULL, 0x26196A0BACB14001ULL, 
            0x148310D5BA84128FULL, 0xB8F41F34FF8B3EDCULL, 0x91926CD2A94F0C9BULL, 0x2DAEEC27E2704E1CULL, 
            0x343B882D3E448FF6ULL, 0xE4E5A1DD077BA008ULL, 0x5E6BAFF2C22A9CD1ULL, 0x64EC0239AA69C7C6ULL, 
            0x96D5A1EF3E5D3ECDULL, 0x16FFAE89297AF03BULL, 0xB62957B556991158ULL, 0xB2F2803CE5009BCFULL
        },
        {
            0xA21B00DBEDB30A2AULL, 0xC20617D9F254B962ULL, 0x5C981F60026D8DEEULL, 0x9817150ADC3AE7B4ULL, 
            0x40BA5E95CF85CC31ULL, 0x2EA756803BB2B0FEULL, 0x3CA36066617EAC67ULL, 0x13A5D0688A49847EULL, 
            0x9E198DD6727FA1ADULL, 0x1EE9A236F247AD5EULL, 0xA1884391091785EBULL, 0x210ADD8F52BBB8D3ULL, 
            0x4550F2D7BEE21D61ULL, 0xB1AF83E696C5C457ULL, 0xD5C594F1AF5CFFA7ULL, 0x53F5CAB9D8011ABCULL, 
            0x9303EF9BB6991B18ULL, 0xEF387B1F002E2A7AULL, 0x1A1DB95AE63CFC2EULL, 0xC9AAF4BBBE20707DULL, 
            0x5E813B0D3186AE9AULL, 0xB981D24504B1B72DULL, 0xB3502584ED82380CULL, 0x6B05DB2F437F1B01ULL, 
            0x5C1D2359C1F34E78ULL, 0xBA59AD60EEEC9BCCULL, 0xE03C319394F4D036ULL, 0x822EF59C66C1C539ULL, 
            0xCA3C49F9525E4999ULL, 0x664738C798FFF7D1ULL, 0xC1564635CCAD9344ULL, 0xF5369ABF1EA5AA30ULL
        },
        {
            0xE0924DCB802CB5CFULL, 0x5B81314C142D48A5ULL, 0xB76B656B7FCD3263ULL, 0xBCCDD7E0A7CF455EULL, 
            0xB742F77F6F822B92ULL, 0xAC4A4E05B0FA0171ULL, 0x154E087FA0FE6220ULL, 0x8558FD175E625F28ULL, 
            0xC1F873366786AE16ULL, 0x58540A30842D4DBEULL, 0x4F7806632F66B71CULL, 0x89EC12C367EDF139ULL, 
            0xDA1FE2703274F521ULL, 0xF02C4081EE5A8E85ULL, 0x24EF6691130836A2ULL, 0x41969D77B3C9D8AEULL, 
            0x403175BF633449BBULL, 0x61C3720937A353CAULL, 0x157064F72740482FULL, 0xF4F297930D4FC448ULL, 
            0xBEFE4EB4B449D578ULL, 0x42349DF7150CDB7AULL, 0xBEE67E6478DEACB1ULL, 0x18C62E08FA65F866ULL, 
            0x0E0CE1F45F1B302CULL, 0x0288F011E6AA2DB7ULL, 0xFD3BEE65DC438D7CULL, 0xC46E475EBF85C19AULL, 
            0xA9C2880EF1B8C58CULL, 0x290AD65D4EB8F5EEULL, 0xD983F20215511712ULL, 0x6707B6DB10244A35ULL
        },
        {
            0x7081B91A71DDD263ULL, 0x097CFA91F525E738ULL, 0xB20A5E820304C542ULL, 0x587BCEE90736394DULL, 
            0xEEBE732613BCD784ULL, 0xD39797EBA1A18162ULL, 0x7E666E57DA8DA353ULL, 0x4DE8F9D7A0B92076ULL, 
            0xE2D75BC6E0F913ECULL, 0x792F707F04ACD91EULL, 0x1FB2C122A81CA447ULL, 0x014B57CAD23FCF6BULL, 
            0x698D752F67CD70E9ULL, 0xE945E43FE10E69B3ULL, 0x4D9C31419E0796BEULL, 0x248494029482881BULL, 
            0x8477590F2B77F37BULL, 0xD91589750C7FA4D4ULL, 0x50AC33E9DA66A37DULL, 0x8882B7A75E4330E3ULL, 
            0x87DB6FAB08699B29ULL, 0xAD4AFA153BF44859ULL, 0x756D96622C707CCEULL, 0x40224B664605B3F7ULL, 
            0x299F596EA7BB6BD6ULL, 0x0C1A26A4C6298FD7ULL, 0x6E6ED7232CD8EEB1ULL, 0x837727E9AE5D1886ULL, 
            0x92E4B00E760FC30CULL, 0xEDD888825D2A0448ULL, 0x8C9A6EF71C504483ULL, 0xCEF4064811CA638EULL
        }
    },
    {
        {
            0xFEC30AAB42AC9CC6ULL, 0xA32828286F0C62EFULL, 0x069A12FE2213C79BULL, 0xBF2C0161D11570C7ULL, 
            0x955A45A9B26A3390ULL, 0xCEB449B411F9BFFBULL, 0x1E389C6B4CC510ECULL, 0x78B282CC70D48451ULL, 
            0xD95C9B9D591806FCULL, 0x0441B4116832EDCDULL, 0x4ACC4AA7AD953D51ULL, 0x32BE40A7300FCF9AULL, 
            0xD40E1B5537C98CCDULL, 0xB857E3EA6AB072B8ULL, 0xA05AA0C75A4A308FULL, 0xEA2AE486BDB3B1ABULL, 
            0x88CDE937CD0502EAULL, 0x406C548285C89A9DULL, 0x5FFBBC825EDCFB2BULL, 0x12E230127BB237FAULL, 
            0xF4AB2D34EB6C1043ULL, 0x5769C42E4C52B4A7ULL, 0xCA4D866955FF9C2EULL, 0xADDB7EEA8052F0E7ULL, 
            0x8204FFC5E18EDE9EULL, 0x945D3FB2C153BDABULL, 0x4DAC9FCD0A79EFA7ULL, 0x529586C0A3589812ULL, 
            0x26728193D2476FF0ULL, 0xDC712C0A267D935CULL, 0xBDF67B951361D4A4ULL, 0xC6F29D8058341A71ULL
        },
        {
            0xEF125449FFBEE590ULL, 0xF96E70EAFC7CE275ULL, 0xEB3FB883B58DAFA2ULL, 0xC8E91ABFA4B13E0CULL, 
            0x7012F62FEC842112ULL, 0xF5903E262FB0057EULL, 0xCE93CC7D44029B72ULL, 0x34174499C4A2D33EULL, 
            0xD1014EEB9A1E75D8ULL, 0xB85C0CBDE6C3A33FULL, 0xE04BB12746D3AE8CULL, 0x3E1BF7A49BC4451AULL, 
            0x085973A96309DA5EULL, 0x2EE16D4EC33F1863ULL, 0x49B9AC32CEEA3A75ULL, 0x14BAA74FBB4ADB15ULL, 
            0xCBC55EE73AF8C62EULL, 0x5962CD90726207E8ULL, 0xDAB73BF5421BCBC6ULL, 0xE61FECB38A1CEE0CULL, 
            0xB8D067238D46C501ULL, 0x87FE753063CD369BULL, 0x1C9FC13937CD6E57ULL, 0x023363C75FB898F1ULL, 
            0x68B443487CC86BD7ULL, 0xE92D78D2726D3131ULL, 0x548E6669134A94A7ULL, 0x255383EF5273F2B2ULL, 
            0xA3AB11194436A63CULL, 0xBFD42F634F2C582EULL, 0x5525700AD10BEFE3ULL, 0xFAB764410FC64165ULL
        },
        {
            0x950AC29FA692ED5CULL, 0xD16EA44AA6A3D2DEULL, 0xC6073136BEDEB5F1ULL, 0xACB41A91DFE36FD2ULL, 
            0x0D218A1343235DDFULL, 0x3A32F589D8A16EC1ULL, 0x476128E4DB48E47CULL, 0x06F980081FBAEBAAULL, 
            0x8F171E41BABC3256ULL, 0x5F85E089048B4180ULL, 0x3197445ABF85947AULL, 0x3E3E84E312C146EEULL, 
            0x0258F64ABB4E95A5ULL, 0x395FC8A9957C44F7ULL, 0x95AF67A45F66DAC0ULL, 0x5A1E0C2B40BB4A7AULL, 
            0x187F3E47B856CBFBULL, 0x1A8217594A461A11ULL, 0xB2D17A6E6CBD1AF4ULL, 0x687748103E239DD3ULL, 
            0xC2A08847AF80AED9ULL, 0x468BF0E86CC56415ULL, 0x27E1F6D7D4EE2110ULL, 0xB3BC4CD0C75736DEULL, 
            0xECEA5568DA07F8F2ULL, 0xBFECFAC134F3C710ULL, 0x31D4E36E32C896B1ULL, 0x81E50A5F0415EA0FULL, 
            0x6E8B71D1BACA08A2ULL, 0x420A775582F40088ULL, 0x66C4BD49C37E9431ULL, 0x4FB3765678192CCCULL
        },
        {
            0x88A27251E3D7E291ULL, 0xF97E239B9F7FE70AULL, 0x4FCD9393524C1295ULL, 0x200BDA3CD44422D0ULL, 
            0x0F229D0D87FEEBE5ULL, 0x62A9D67C3124D465ULL, 0x10FD80BFE9F6FAF8ULL, 0x3328CF9AEFFC6802ULL, 
            0xFEC78FC237C6FD6BULL, 0xE13373D58770272AULL, 0x83F3D4C849F210F7ULL, 0x2D46EFEB0FE66CCBULL, 
            0xAB21E0FD5FDD9A9AULL, 0x14722F8A490BCDD2ULL, 0xA4514203DE55F024ULL, 0x1819C6452114289CULL, 
            0xAB9BFD66FFAA5A53ULL, 0x5D335F748DE8237DULL, 0x82E500973F32E545ULL, 0xE9BB6F96FDE0B4B2ULL, 
            0xD2622F4C7D9174E6ULL, 0x16D4E4A988022419ULL, 0x2EC706246AAB56D6ULL, 0xE2136D310E60A93EULL, 
            0xB7E39C37F0A842EAULL, 0x1ED3B578CFEE3894ULL, 0x5EA6381DB8B34B10ULL, 0xC47FF12C5DFDEA6EULL, 
            0xA62402D6B94D1667ULL, 0xC4850940CA07EF17ULL, 0xE19CE1C35D716168ULL, 0x064333921CF9F078ULL
        },
        {
            0xD2B592C6F6DC40B5ULL, 0xFA1FD6EC4705F440ULL, 0x4A0C62EDA5C49A98ULL, 0xCB2419D5A1F13530ULL, 
            0xF995A017ACEADE42ULL, 0x3F9C68853D431EC4ULL, 0x6468FB8F1C2465DAULL, 0x1B5201822A27979CULL, 
            0x5C80496C888855EAULL, 0xD3EE63DD5CDE48A1ULL, 0xA9FEF2F992F3FD76ULL, 0x4E78259490FF2443ULL, 
            0x6BB1CC5BC9441B09ULL, 0xDDA2C79F3D8C42D7ULL, 0xBBB7CC20B11E0AAEULL, 0x8DAAB2DCD2E95B66ULL, 
            0xC92ED24B63AB5F67ULL, 0x106E60A4F017D649ULL, 0xD21A7C4B08799991ULL, 0x4E6AF667D85B737CULL, 
            0x96DB346D1F16810EULL, 0x5E993A91CA40434BULL, 0x618390C161D62247ULL, 0x84A1AD17A0B91B95ULL, 
            0xC79D2A0D50D81C28ULL, 0x9F74E4FDA69F26E4ULL, 0xD08F8C4A288E46EBULL, 0x2ADCFC207E965A44ULL, 
            0x7723BFDA769118E5ULL, 0x208BCE8BEBE8C37EULL, 0x85CE02DD6567594CULL, 0x38BA4DB6692680E2ULL
        },
        {
            0xCB21D0C515970171ULL, 0x7C3213058CB7E44FULL, 0x1AC174E6E47F0DEBULL, 0x2C21D5E5814DAEDDULL, 
            0xB8D68E0C187AE9B1ULL, 0xD7BA9A93ADF50343ULL, 0xD5E7075FD2C5001DULL, 0xF2F104B476250B7FULL, 
            0x87AAE9A99A427166ULL, 0xEA9CB143AD4E1CE4ULL, 0x0D9709F0D52FAE3AULL, 0xD3712DFBC960F7CEULL, 
            0x3327C5A71BCFB148ULL, 0x3FDE278DE67F1FE8ULL, 0x0A2C82A99C9C386AULL, 0x7373869DBFD365E6ULL, 
            0xE4DCD9D29DD8F531ULL, 0xDF0152760ABD3E97ULL, 0xAD6B6AEB2606B909ULL, 0x9D42004CB62DA5BDULL, 
            0x0DCFD3A62DF98709ULL, 0x9BAEC27BA6295F5FULL, 0x668AF6194BB66448ULL, 0x5BEDAADD2DA4EB12ULL, 
            0x3FC424822670E84DULL, 0x078001635D150BC5ULL, 0x7B5453BD510E883DULL, 0xA26609E40D814DC8ULL, 
            0xABF506A60E59D11EULL, 0xE93026BA7DE0E7E7ULL, 0x474A1B0D1D3EE7CAULL, 0x1DA374C9E24970E2ULL
        }
    },
    {
        {
            0x21E02CC69D2973AEULL, 0x90DBDBD09D35514EULL, 0x72349DE9EBB1AE80ULL, 0xB3C07F0E6FA50418ULL, 
            0x5412562E7707EE58ULL, 0x8DEE51FFF33F66F3ULL, 0x5C4552F3A7A369EEULL, 0xE05B6C7399DACE8FULL, 
            0xF8AF804611A24926ULL, 0xC4DA0ED134DDE64BULL, 0x1255D12E0FB150CAULL, 0x55CF0CE18D1D2720ULL, 
            0x82898D7473840864ULL, 0x0F061E2137693806ULL, 0x6A48D1DA994F917FULL, 0x451F7741AC65E90FULL, 
            0x1971A7309F85FD1CULL, 0x709AB6AABDBCAA40ULL, 0x58AEED1983EBC50CULL, 0xF9737578878FC3BBULL, 
            0x81A23B53CF18BFC6ULL, 0xECC8763BD8E753ACULL, 0x0097CE441C98BF93ULL, 0x641E2DDEB735C85CULL, 
            0x53E1A82C488BA5E3ULL, 0xD6E4F503B072B1C5ULL, 0xE10D8CD2FF4D996CULL, 0xE88DA5694951323DULL, 
            0xB70499F326A0CB00ULL, 0x428A8F3A83B3E066ULL, 0x16CB749CA693DE03ULL, 0x020E7D9E2CF02F64ULL
        },
        {
            0xB9B9C8AB9BD18FD7ULL, 0x35473BDE6F821F0CULL, 0x3875EA8A42B10591ULL, 0xC0D04483933C53A1ULL, 
            0xFC0DDB31DDD69337ULL, 0x9D3387519D82BCCFULL, 0xA731C5E2C7BD3D76ULL, 0x792337D8E3697226ULL, 
            0xECDEC270792B8161ULL, 0x8DF6061C5E41B3D7ULL, 0xA8B64904D72DEED6ULL, 0x2C71BB592E0B8065ULL, 
            0x87D3FDA5802033D3ULL, 0xC77E413DC3836900ULL, 0xC14C50FE98C26041ULL, 0xFCBC684F411E0FFEULL, 
            0x82DDD47AE29D9A43ULL, 0xD17ED23143FC5A00ULL, 0x1B739A3BD4E3AB0CULL, 0x28AC4B27B6CB9639ULL, 
            0x5EB2B7D480E8A3FDULL, 0xABBC3411F446AC9FULL, 0xA95021301E840103ULL, 0x83D1586C41F6CFBEULL, 
            0x9B097CDF715AED4CULL, 0x1D905AA87438BAF2ULL, 0x089A91D95E3FED24ULL, 0xB9A1289CC84E71DCULL, 
            0x877662852DFBA684ULL, 0xFD4F5780E711AD77ULL, 0xEBAD7F2DA28EE75DULL, 0xA1BBA4BC32ABF848ULL
        },
        {
            0xBB0D55654D7E62A0ULL, 0x94B7A4580B52E863ULL, 0xC3601601C5C6B0DFULL, 0xF03AAFFA34EF2348ULL, 
            0x38C6C83BC5402C0EULL, 0x52998F2819075CE4ULL, 0x51635D51FB8E84B4ULL, 0xBC982F51B79629F9ULL, 
            0x10EE78F01D910966ULL, 0x120CEFD1A4E5C10BULL, 0x5907571FA190D0E7ULL, 0xD4A7CD501E05C476ULL, 
            0xB863A9E9E0617471ULL, 0x794D1AEB3EE2CC5EULL, 0xDD652C06F01C0D1BULL, 0x91B63C0D8DB7F8C5ULL, 
            0xBA1EE6658F695860ULL, 0x093A0D3D6CE5FFC5ULL, 0xE9EB81C0C95AD33BULL, 0x551CD09DCAF23023ULL, 
            0x57F53F1A568BBF28ULL, 0x427089F00467494CULL, 0xF9ACC9D0F2871293ULL, 0x2698251A4432FC7FULL, 
            0xAEB0342ECB27EFDEULL, 0x74D89E2A845EC74BULL, 0xE123249E5F87F3FEULL, 0xC5E3A837129AFCCCULL, 
            0x10353CCF58C3BF37ULL, 0x0EF02055250F07F5ULL, 0x2C74417697590B33ULL, 0x857256D07D17ED18ULL
        },
        {
            0xFFC0D5E315A06266ULL, 0x7B5484E807890C10ULL, 0x532913D8DBBC7257ULL, 0x905DF305A0BC09E7ULL, 
            0x36520558FE1CDE3AULL, 0xD2113C73D754669FULL, 0x40B861FBA9B73BC3ULL, 0x1A5D6B444F37BA4FULL, 
            0x49AAFF67797671BAULL, 0x83661EF4B53DAF75ULL, 0x4850F5E0787080C6ULL, 0xBFCFB4DF12CDA4F8ULL, 
            0x300E489850D43297ULL, 0x3A7BA60E6C51C01CULL, 0x3950A6C734256C98ULL, 0xD3D942B059467F5DULL, 
            0x7EB45BE5A2067592ULL, 0xE0F4144A261CDDCEULL, 0x01F946CE8DF5C770ULL, 0x5D22FB7CF5818308ULL, 
            0xE6F105021A5D2DDDULL, 0x92226BF9B8F78658ULL, 0x59A309E6BD2701A1ULL, 0xEE27D08772B1474EULL, 
            0xBF13AD968675923FULL, 0xEE2CA1DD7B197A32ULL, 0xAB1ACC7DC5069681ULL, 0x620CB3939FB15957ULL, 
            0x1780F06A5BDEFC64ULL, 0x13F7614F03BC4EEFULL, 0xE80EF38BCFD09798ULL, 0x4C0BE79C3008BF89ULL
        },
        {
            0xA42D4C7D4AE80460ULL, 0xF4CB6E646FEDCCBBULL, 0x41648E690D5142EFULL, 0xEF8DB222222CD1B3ULL, 
            0x261EB8B25827B4C2ULL, 0x646E6BC70D954FFCULL, 0x280F3CDFFF1AF69DULL, 0x041170E38B42AD96ULL, 
            0x01FAD28905E4B09FULL, 0x4A8B0AD8BAD16DACULL, 0xE2FCE650FAD97D1FULL, 0x3EDCBDD2FC9B4C0AULL, 
            0xFC6C98802D40CC5FULL, 0x3FAFBEFA4F75F531ULL, 0xC2641F3970495F11ULL, 0x0849288466819B67ULL, 
            0x867973042CDBF28CULL, 0xB47791C839D4682CULL, 0x82B37E5851A1DF52ULL, 0x0BE2DE6CA46FB7FFULL, 
            0x242CB94707082DD1ULL, 0x15F17C98DE93A70DULL, 0x3649685E8D0A0478ULL, 0xE5939C6C0874162CULL, 
            0x9CF86BB61729CD69ULL, 0x31781BA9018F8DC6ULL, 0x1E63EA8371010042ULL, 0x46D5F4466D32CFCCULL, 
            0xD78E9954F88711CBULL, 0xED2BF0743B3F1060ULL, 0xE500745D3A6023E0ULL, 0x05398E12E7696F3CULL
        },
        {
            0x0C1B2911E3C618B2ULL, 0xD4525B101AC5B609ULL, 0xAEC004F228963055ULL, 0x9D2705546C107032ULL, 
            0xBB008273663ACF53ULL, 0x81C49B60E27DD9E3ULL, 0xA02533D75DDC4506ULL, 0xEF850DDE35BAB14EULL, 
            0xDF26B65B94D9C38BULL, 0x109F3A440C017D2BULL, 0xE741F880FF202ED6ULL, 0x8F130D4AEC747926ULL, 
            0xAC44387F6A705844ULL, 0x16637753592BE5ACULL, 0x2AB3B394EF08CF5EULL, 0x5610032AB98388ECULL, 
            0x0FCA80D24EA1E361ULL, 0x514AA0AF752C073BULL, 0x48E1B44F5FE26DBCULL, 0x2228D5A9F1F8DF67ULL, 
            0x5D59E851430EA080ULL, 0x964AE10B4F76A871ULL, 0x70733C45DBD8B7ABULL, 0x4184BFCD4003E39BULL, 
            0xAB05947D3A8ABD05ULL, 0x2D00C4148D9D6443ULL, 0x451D54C54E5B142BULL, 0x0FD30761648A2810ULL, 
            0xABB11EABCFB774FCULL, 0xD4BB489E3E0D85B1ULL, 0x40E951EC0E1D4245ULL, 0x49128E5D66155135ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeyRotateAConstants = {
    0x828A5FEDC2122872ULL,
    0x3631C43ED41FD31DULL,
    0x611FE3C341B53E2AULL,
    0x828A5FEDC2122872ULL,
    0x3631C43ED41FD31DULL,
    0x611FE3C341B53E2AULL,
    0x2F98DDF36871A79EULL,
    0xF6E2859224B9FBC3ULL,
    0xB6,
    0xA6,
    0x5A,
    0x63,
    0x50,
    0x17,
    0xAA,
    0x35
};

const TwistDomainSaltSet TwistExpander_Menkent::kKeyRotateBSalts = {
    {
        {
            0x51F24C318A112672ULL, 0xBEC0E8AEFC92961DULL, 0x80EDD9DEBEBB7255ULL, 0x41FF99AA2FCD702CULL, 
            0x2431EC736666924DULL, 0xF97BB0822B4340EFULL, 0x41B698684481D9FBULL, 0xC9B4E3A2243C27BFULL, 
            0x7AF3E4D83F61DC19ULL, 0x42766E74F4E1F08EULL, 0xD0A402F9AF2117FAULL, 0xDD57DA40D729C6A9ULL, 
            0xCB657CEE136F4695ULL, 0x15559D353ED6EBF9ULL, 0x64A4D737BDA2AC8FULL, 0x87B11DB50FC799B9ULL, 
            0x86376C1689348C2AULL, 0xC9188F106E7ACD5CULL, 0x0EA4D2917EB923AAULL, 0xBA2B82D3033F5EACULL, 
            0x5E86F3FDAC33D98DULL, 0xDAB20AD3675CDE22ULL, 0xA417B62E2EF98347ULL, 0x6726C095508DDBBCULL, 
            0x6ED549583C29395BULL, 0xFAB37D28BB7A7E2EULL, 0x93C9BF2BAAE9BB93ULL, 0xD1A4F6096326A31AULL, 
            0xDD58965D0117303CULL, 0x43607FC400C20349ULL, 0x1418C26662D77F35ULL, 0x18839FE3028202D2ULL
        },
        {
            0x2A7E8DCF9883A8AAULL, 0xE84F2AC850390C18ULL, 0x7A06062A3AB2F28AULL, 0xB21D93F5BA296A58ULL, 
            0xFD5233D0A7C6F67FULL, 0x0768F91D2EF759C1ULL, 0x2E09CDB0FA6C28B2ULL, 0x6F9D2933C7F1AEB4ULL, 
            0xCA6166F0DBCE9145ULL, 0x5424D2A3A6D15C6AULL, 0xAA908727D79B41C1ULL, 0x4B302DDB9ED4A21FULL, 
            0x07EC4A5E10BEBFE8ULL, 0xB85B75C8DFF14685ULL, 0x409132EDDE647554ULL, 0x6C0B30133FD9DDB4ULL, 
            0x1430C711BDB2F6A5ULL, 0x15EA6C7C2D1EE298ULL, 0xE05B24E5C088D930ULL, 0xFA79BB8092D06D2CULL, 
            0xDC2BCD3264221B5FULL, 0xCFE900F399EB4608ULL, 0x96014B676346B49AULL, 0x769DD034EB2FFBF7ULL, 
            0x8501E5C4818385D7ULL, 0xA87D0106279DB0E7ULL, 0xA8D5DDA30A15865BULL, 0x5C5F41B80FE1993CULL, 
            0xC2B4AA7DBFB61427ULL, 0x4E3D28D2ABADE8C4ULL, 0x98D950893F50BF7BULL, 0xFDE706F0BA80B6F7ULL
        },
        {
            0x78D866E21527B6E6ULL, 0xCB9F792C5CAE5579ULL, 0x40A55F1F2A6F1F63ULL, 0xFA75B27BCA596829ULL, 
            0x9E014E1F7ABE97AEULL, 0x05E9B6F5F4DFC148ULL, 0x0D3FF723C2CE0A3DULL, 0x0643FED0A2C80F0DULL, 
            0xCC45755005B97E32ULL, 0xA251DDB93411DB21ULL, 0xA86CF80F68424F28ULL, 0x7B1065B51800BA38ULL, 
            0x98E051FAD5D3B0E0ULL, 0x767A5EF902C43421ULL, 0xECE12EF5AFFAF83EULL, 0x3D6A24AF09201E7CULL, 
            0x17F9C4EF982189F0ULL, 0xFDB3542B29DC99CBULL, 0xBC73B7AF6DDAC2DFULL, 0x894E16279372249AULL, 
            0x54393C5EB3144D07ULL, 0xFDBCEC56A91B2B36ULL, 0x1B2F5916E8629225ULL, 0x356F55AE4941CE2EULL, 
            0x408176EB558FA2DEULL, 0x7D920BFB6C4BFD2CULL, 0xEBD6A5F11E9CA66FULL, 0x9DDED70FCB7C7B43ULL, 
            0x3E28620D3D1B1A32ULL, 0x5D101AAB4E1C6659ULL, 0x7E4CE35B4C0D3A73ULL, 0x309CBB384AD932D8ULL
        },
        {
            0xAE23610C7A5B095FULL, 0xFA2604F42BC5BC16ULL, 0x2A4A0BB0D03179E1ULL, 0x2C3607DBE090DC8EULL, 
            0xFC2C8ADECB21FA19ULL, 0x87A363082B934F04ULL, 0xDB21C291097D0665ULL, 0xEC69DAD1F250F93CULL, 
            0xE9B621F34CC9124BULL, 0xDF3C3CE960804094ULL, 0x4A9A22BB04E6E922ULL, 0x14D3C15CD7F7B4DDULL, 
            0xEC46928C9A8FF602ULL, 0xA645A5622F407B5CULL, 0xB9FC45D65C155F5BULL, 0x41C72DAD7F5784F7ULL, 
            0x232DCB65957118BAULL, 0x2B600415AB729942ULL, 0xEAA296E3F127483FULL, 0x4B9CFC8C717FC012ULL, 
            0xCEF5CBB25824EF0CULL, 0x971B2050C348439EULL, 0xB00391959EB6B094ULL, 0x480246FC3B964ECDULL, 
            0x30B17FF167AEA6D3ULL, 0x1FF9698DB9BCB8EAULL, 0x76F711A4E95DA0BDULL, 0xB659A67798627CBFULL, 
            0x327B39AEBBD3CDC7ULL, 0x99DE9EC0B8B5C0CAULL, 0x1C6C8342A8BE0A8CULL, 0xB6A31419ECD66F45ULL
        },
        {
            0x4F578862A84E512CULL, 0xE6EB93BBBDC3C428ULL, 0x1554558372B3FC69ULL, 0x993A4CF7A5B38C50ULL, 
            0x178B07F2486FE7D8ULL, 0xB738FCB00129C8ADULL, 0x50C097C757629E36ULL, 0x27A5B35FAB654109ULL, 
            0x7F4123AC6C5CD704ULL, 0x598455B1EEF420B8ULL, 0x65354F25780A1B80ULL, 0x44518BE8F476AE43ULL, 
            0x21944AB3291E318EULL, 0x57E32DF706EF5BB4ULL, 0x5A574C8E09CA152BULL, 0x73F77DA3F804877EULL, 
            0xBC25D799333E8C08ULL, 0x9FBEDEE08262B8B8ULL, 0x00DB79161342B12FULL, 0xBE60843F177DD07EULL, 
            0xC1FB8D1067EAFC99ULL, 0x3B22EB5D08CB6C9DULL, 0xEAED9CD47865054DULL, 0x9963C86B9F3CD77DULL, 
            0x521EBAA653751080ULL, 0x78DF4CCD3F68F584ULL, 0xBE580831BE8508AFULL, 0x60A3FBB6A943174DULL, 
            0x213D33C4EAAA584CULL, 0x4DA55BBE9E9370A7ULL, 0x69AF13CDE58AA839ULL, 0x722D072123E8794DULL
        },
        {
            0xC3F63E51409BB036ULL, 0xA4E8C87E03B0DD27ULL, 0x967BB55033BEBCF7ULL, 0x57F263A71FDF6287ULL, 
            0xF7681DBBD41B2CD0ULL, 0xFFB4387182B7C39EULL, 0xFD1005BE607A9229ULL, 0x7437239C2A874980ULL, 
            0x8F0B949FF8827702ULL, 0x08F7E5ECE4EE19D7ULL, 0xC2861D5DAB21C22AULL, 0x99859FDE994DA831ULL, 
            0x539FD62CBB888C26ULL, 0x4F970E77835BD600ULL, 0xFEC00EA4DADC76F5ULL, 0xA5F29DCB07DFF6A1ULL, 
            0x5212A3F4B73BAB25ULL, 0x5E8EE8CA82226BCFULL, 0xE3757ED47D0FFA1EULL, 0xC13842870447940FULL, 
            0x81CFEE85365CAD2BULL, 0x77EA71F9A8EC6923ULL, 0x66C2AE36EF5270B6ULL, 0x62ADEE979C7FE4AFULL, 
            0x8D805722069D511EULL, 0x4F1E1A3238E0DD0AULL, 0x00BCCCFDF47AF0D5ULL, 0xD8AB3189F8B06792ULL, 
            0x9D73E3E4312D098EULL, 0xB195ED863A229854ULL, 0x4276650D411EE524ULL, 0xA9AC8EC716D9E24BULL
        }
    },
    {
        {
            0x8D7B67BB3BDDF8DEULL, 0x16F57D973EA464CAULL, 0xE1040F3603CED1F5ULL, 0xEBBD8C182583A981ULL, 
            0xE53CF0EDAFF09B5DULL, 0x6172438323EDE299ULL, 0xF1755F2F284E67CAULL, 0x453B9749EF5C8804ULL, 
            0xFB529F06DF04E41DULL, 0x5A6A201AAA1F3D3DULL, 0xEDB840BCBD74AEEEULL, 0x5DC5E0832E8FB4EBULL, 
            0xFDDE63BCEB4A057AULL, 0x34A6326CA2D68044ULL, 0xFCB4BA28DB8DDCB6ULL, 0x998C4DF3FA86C0BDULL, 
            0xDDBCFAD616D77859ULL, 0xC76D4857A36332F3ULL, 0xEC538A4D69AAA696ULL, 0x9324EF259E4E723CULL, 
            0x6A4AF7630101CD39ULL, 0x4AFEE90D8AF7DD83ULL, 0x23FE7EF2D4CF1797ULL, 0x33154072308C69EAULL, 
            0x825336AF943F3171ULL, 0x035DAEAE63FF7AF2ULL, 0xA066F57D8F32500CULL, 0x88998D127433892AULL, 
            0x84E57085CABE877BULL, 0x532C05342566A094ULL, 0x0A866F383C264575ULL, 0xB3C60C758FC51955ULL
        },
        {
            0x18B12503BB97E778ULL, 0x221787C799F03A71ULL, 0x18120CF3F404D94EULL, 0xA066F49E1260E916ULL, 
            0xDCFED9A6BD8DBF50ULL, 0x5B0CDB1AA7D93797ULL, 0x5CD4D8CEFB92485CULL, 0x63712D17A33BB4ABULL, 
            0x7C91B3AB58B5FADAULL, 0xF6073AF44FB08110ULL, 0x11DF54F2C6ED1054ULL, 0x84248077E76D882BULL, 
            0x1BEF5A2636AEBA04ULL, 0x51683A37AC2C2291ULL, 0x7390F80A343CEEAFULL, 0x91D1EC96CF09B834ULL, 
            0x18023295B873275EULL, 0x1B7EC975E73C56A9ULL, 0xC3F128D749B7813DULL, 0x3F9D8AC169491E41ULL, 
            0xAEA13653EB5B9FF5ULL, 0xDE1591BE41D64AFFULL, 0xC878E67C3A355492ULL, 0xA214ADE0272DA13EULL, 
            0x0C67EB052D3DAD97ULL, 0xF18BE42CD4AAC503ULL, 0x15A675758193DED0ULL, 0xFD7D0EE14BE0E696ULL, 
            0x6A819A3901729A9DULL, 0xCAAEE7F55A2DEF16ULL, 0x20568472D01BC8F8ULL, 0x07E4592DCC9750D8ULL
        },
        {
            0xB2979071D1976BE0ULL, 0x569E0181C41CFC75ULL, 0x7BEA560050DFCDAEULL, 0xBAF1382051605186ULL, 
            0x97828C739602793FULL, 0xC7AD1E5572BF1265ULL, 0x1D7A6026E88414F8ULL, 0xD0D0B6FB814E0203ULL, 
            0x89E22C01FA448911ULL, 0x86BD23B9EC3043C6ULL, 0x795BDDB6421464EEULL, 0x3C0EA56658D5536EULL, 
            0xE936F241CCC19FABULL, 0xFEB2D379B22EED40ULL, 0xC58886302337C8D9ULL, 0x489E896BEDC3FB22ULL, 
            0x714C2EAA6B6AF6F2ULL, 0x714B58216A1683AAULL, 0x9278285A07D83976ULL, 0x28973099B0F4B82BULL, 
            0x48B59CBE3D741816ULL, 0x5042A9BF7F1FB48CULL, 0xDF8456E70A91F849ULL, 0x0B7C91B356599470ULL, 
            0x7C0AE49C7D598EEDULL, 0x69E30F3582F1B771ULL, 0xB435EE77C70D51F7ULL, 0xBC7FDFA029675EE4ULL, 
            0x917E13BD25515530ULL, 0x5BA57873D280D695ULL, 0x77DCCB1456610DB1ULL, 0xD4119C8B449AD662ULL
        },
        {
            0xAF5FA2426024E683ULL, 0x9C55746C0D348448ULL, 0x3C3BE0DDF3D82D8FULL, 0x4853F1F02B958281ULL, 
            0x4841F85F25C75F22ULL, 0x5F911813F02D4CC1ULL, 0x6A4B34F182D1D0DDULL, 0x4107B071159E5C63ULL, 
            0x24EB4EA9B56928C9ULL, 0xB70CFDEF1D34AD49ULL, 0xFD0332196E8BB9E7ULL, 0xE418A268C671B339ULL, 
            0x6007D5466EEF62E7ULL, 0x863890D5B663AD1EULL, 0x28B36A3C5062BFFDULL, 0x7664876E3456F0E4ULL, 
            0x2025FF0E608D1AF6ULL, 0xCAE8BB55B0717249ULL, 0x4EA1AAE95702DC80ULL, 0xB0C555DD15105B84ULL, 
            0x15AF5295A29DA27EULL, 0x3AFEBA79F56CA218ULL, 0x1DF3A65DECCEC560ULL, 0x6EB6A402F3D58F34ULL, 
            0xAF14A6D1FE6877F9ULL, 0x09E2AEB244D5738EULL, 0x338CDF4FD41DED01ULL, 0x7C19FBD78B06AAECULL, 
            0x744E3977837A4C2BULL, 0x659D8B370681D056ULL, 0xE40412ED7284A33BULL, 0xF77865968E6B7B69ULL
        },
        {
            0x769783A85AFF3FE1ULL, 0x67C108E79D2B7891ULL, 0xB066BFDBB8EDDB05ULL, 0x1A11E292452D96A7ULL, 
            0x3CAE0F1632E02886ULL, 0xCDFD04AC8297D811ULL, 0x2F3BC7D9A85D4EE4ULL, 0x376B2F8DAD9E551FULL, 
            0xF38FE7D090F32A59ULL, 0x198883C399BBC636ULL, 0x3454E52CA9582EB8ULL, 0xE3250505C774FCE4ULL, 
            0x8E23C018E1541E06ULL, 0x34DEA6CE86A1B220ULL, 0xC6FEDF7FE78AD25AULL, 0x9769927BCCADD27CULL, 
            0x34EF7EA172D5258CULL, 0x8487B3F8B337746AULL, 0x860AD373DBD68C49ULL, 0x9CEE17C792F5286FULL, 
            0x807C2CBE7BBC641AULL, 0xAF96B4F4323D4E91ULL, 0xD8CDE922F8978F56ULL, 0xB07C6154B09EE275ULL, 
            0x65BD6450B12A9C6EULL, 0x86A96C28CC30A52FULL, 0xA220BBC3BFDE7FFEULL, 0xAD1BBE9A0BF32B2FULL, 
            0xED26DBD1FE203C6BULL, 0xFFF6A506D0BDA1CEULL, 0xAA968CE6588711EEULL, 0x19A5628F7F0D29A5ULL
        },
        {
            0xE9D4E19357F22491ULL, 0x9E9226B5D91C6C2BULL, 0x72017F8692C1BAABULL, 0x667F0444C292AED3ULL, 
            0xA4FB106FAFCC728AULL, 0xB87FD1ED8D0790F0ULL, 0xE1C060B2B1C14917ULL, 0xE4D4EB6C9B833F80ULL, 
            0x6D9A7349EBAA0F3AULL, 0x6D4B3465CA22FA9BULL, 0x6CABD6C7D064E447ULL, 0x4ABB65F4C1E157DBULL, 
            0xAD8318D284D59A0BULL, 0x24412D241BDE6DFDULL, 0x5BDBC7997F3021C6ULL, 0xEFC0163456C2E832ULL, 
            0xD2BCB5B6DFA58485ULL, 0xC0A0B6DA948B5FD0ULL, 0x41B9DCA6E1BB3104ULL, 0x553673995DAD7774ULL, 
            0x0DAA69CB70625D96ULL, 0x5DB6A88347B1E91BULL, 0xAD5232ABB49D27C7ULL, 0xC3484DADE6AFAAECULL, 
            0xFF0E28AFEF6C422DULL, 0x662483A27281706BULL, 0x63E7802CA121AA61ULL, 0xC61558A9EE874303ULL, 
            0x1529AFF7AE85DA41ULL, 0x3886F150D8DFB5ABULL, 0xF922ECBB15E72B0FULL, 0x5C3C3F97AFD3A691ULL
        }
    },
    {
        {
            0xA29310E34C9DE529ULL, 0x1F97BE9AC58EF77EULL, 0xA326AB39E7516A06ULL, 0x5D13FAECB9F30203ULL, 
            0xB8D920B76F1A76A0ULL, 0x4966AA55A7C04AFEULL, 0xD50A1627320A7F68ULL, 0x125DC5882F1CE588ULL, 
            0x4F4EEA485DF1002EULL, 0xD83F3A769A7DD25CULL, 0x77C9719D98D6AD27ULL, 0x58618141A6BDD87EULL, 
            0x5339EE6727380CC6ULL, 0x2CBAA16779625ABCULL, 0xE2D2FA27FA1E54C8ULL, 0x2D2C1A3C96EF9D3DULL, 
            0x858026526B45DFF1ULL, 0x6AF2A8A093DD8CB5ULL, 0xE91BA3AAA6CEAB67ULL, 0xBF16E3911B143864ULL, 
            0x81891BA4944A28ECULL, 0xE8DB49B37609A9EFULL, 0xEE19BF59B87C3159ULL, 0xFDF243D3371ED5BAULL, 
            0xAF7B3C7E9895DB1CULL, 0x46D260242BFDA888ULL, 0x2BCC8FA2E8B48481ULL, 0x5F037FBA2CC86CE4ULL, 
            0x6E2C8593CE64C051ULL, 0x0DF97021D1BAA88AULL, 0x3870D10CBE908A4AULL, 0xDDA2C731B3376F38ULL
        },
        {
            0x02786824D3A56C8CULL, 0x95D78D098854C631ULL, 0x666B55AB8BBAF2F9ULL, 0x7017F2714A2DE747ULL, 
            0xF04623C4054E321AULL, 0x8E4171E235B46AA8ULL, 0xEDCE7C2B9059AC86ULL, 0x687BB316EDA7CCC1ULL, 
            0xF26A1F5F46B38A64ULL, 0xD642F54759A9B49FULL, 0x820C774B8BA9A3F4ULL, 0xFC55760B3434A450ULL, 
            0x27CD5511FB036A75ULL, 0x63614B25DB74DE28ULL, 0xC4544C9BD537219CULL, 0xD35EFACDC28A8E72ULL, 
            0xECCA3EC3815F64AEULL, 0xFB32C384AB702F75ULL, 0x5909796D6D37F52CULL, 0x4813D8E584474AE1ULL, 
            0xBA583ED64D79F6FAULL, 0x3B6C90B6075B1D49ULL, 0x02B10DA480F031B0ULL, 0x1FEEE06C63A0C8B4ULL, 
            0x1EAFD825BAEDC0B9ULL, 0x21A6246C46266137ULL, 0x9B8436DC1632C7F9ULL, 0x93B43358BFFCEFC1ULL, 
            0x23874274CA397096ULL, 0x6959C5C89EC0228EULL, 0x4566AE41A4513855ULL, 0xBB146DD59B6BD6F4ULL
        },
        {
            0x6DE50EDDF2161E69ULL, 0x3115F0430B0AA528ULL, 0x2BAB4E2A52D88902ULL, 0x603BBC4C08F48C23ULL, 
            0x47FC1BE7E1C514B6ULL, 0xE3F60BE53B1BE845ULL, 0x228AEE4E5632DD52ULL, 0x0AECC2B828D733B6ULL, 
            0x07CBE6094035DBC8ULL, 0x1AAAE27A01ECC9B6ULL, 0x650D6E365DBA0EFDULL, 0x6832621D4A224313ULL, 
            0xA2AAF75BA30CD8F9ULL, 0x7FC89D6C159EE000ULL, 0x264E05EB69FB78FCULL, 0x3922979E02EAFE86ULL, 
            0x9D734AE06AC73C81ULL, 0xA250B8F32E92F2FDULL, 0x01791E7894C255C3ULL, 0x4924A9E8502E6784ULL, 
            0x40F71D8E4151677DULL, 0x9086270A180892B6ULL, 0xCA587137D5A5CE36ULL, 0x8772763EDE684F3DULL, 
            0xF8A0415892121BD7ULL, 0x122EF08EEED9C582ULL, 0x7B6C253F4797FE0DULL, 0x68556065EEA9D5CCULL, 
            0x8A14EFE1C1F00FFBULL, 0x903E1F1F1EF9D3E9ULL, 0x5F4F837B5A745E12ULL, 0xEF8B41DA236A704DULL
        },
        {
            0x8EC9D667878065ECULL, 0xF6B9B0503441900CULL, 0xC8585F1383F86F00ULL, 0xF5DB158681B0C57AULL, 
            0x7BA1757326FB01DBULL, 0x519EF6EB03ACF2FDULL, 0xA1D6DEBC2F2A5897ULL, 0x1405B30B11B952A9ULL, 
            0x853E1693ED82C9EDULL, 0xAD2B3B1948969E2AULL, 0xCF7E7940786D95FAULL, 0xE93EFF881F6DC926ULL, 
            0x1024FA830DAA37C2ULL, 0x7B7ECC3FBD9E3E1DULL, 0xB69AB6907AC218B7ULL, 0x075A6BD42BE545BAULL, 
            0xD3F7D12C4BACADF3ULL, 0xB9FB1744D44C60E6ULL, 0xB7A9A13ACCA2615AULL, 0x0FD057AFF7DD8F48ULL, 
            0xAB6D99E4D23247EDULL, 0x5668A900BFF6354EULL, 0x67C2B390F34D3A3BULL, 0xCCBF3765FEA9F6EEULL, 
            0x42035DEFCEB91FAAULL, 0x695578405DB28D6CULL, 0x52B8E67A88F38D84ULL, 0x11E2DBE7D6AA2B0CULL, 
            0xFB2FCF6B3573E04BULL, 0x68B1B408BFEA4B73ULL, 0xF402F1FE62D31130ULL, 0xACDB4D9D2E143417ULL
        },
        {
            0xB8FC5172CD701F9BULL, 0xAB71DEDE695FF96DULL, 0xEC0956A1711C21A4ULL, 0xE14B798DAF58EC2AULL, 
            0xF64734F673D03242ULL, 0x419CE28A91609634ULL, 0xFC90252449DBF06BULL, 0x61B41D0DC499D9AEULL, 
            0x441B061FF8297492ULL, 0xB60647CB4450E0F2ULL, 0x031524C9E849AF85ULL, 0x27080F55AE41D262ULL, 
            0x77F4E04041766062ULL, 0xD6F73C6CC6E94C75ULL, 0xB70DB7D5850DBE4FULL, 0xED0F0A08ABC8478AULL, 
            0x6AAA612C2D3F3EDBULL, 0x84750DF041782B44ULL, 0x268F457D1164F9BFULL, 0x0A01299EACDDC7F5ULL, 
            0x5D60A5F31EAA5CCAULL, 0x482D74ED81B68424ULL, 0x4C31CEE9EB2C0C85ULL, 0x63B5D5F90BA0AC81ULL, 
            0x2B6F283600F15840ULL, 0xA77D97DF13C0F316ULL, 0xA901023B3B1C0A1FULL, 0x7D66AACE70CAF000ULL, 
            0x7D7FB14A29A14A55ULL, 0xB9D3CE9790439288ULL, 0x8A526E810C29C0BAULL, 0x2130CAE091199EBAULL
        },
        {
            0xA0C1311CE592A75AULL, 0x6FF6352CAC1CEFA9ULL, 0x9B4552EF624631FBULL, 0xC1582CABBC5A59F9ULL, 
            0x5BD20AAA46DF287DULL, 0x3768464A692BCCF7ULL, 0x23004F63E9934884ULL, 0x994A1D5546B7000EULL, 
            0xD1E5869F59909FA1ULL, 0xB7C7216650150808ULL, 0xE5EB2163EC4008C3ULL, 0x36651BBCA8C362F9ULL, 
            0xA7D671DF95BC24D4ULL, 0x8457AD1E35A5976DULL, 0xA5AE831A00A76CB2ULL, 0x3244B1995D9177F9ULL, 
            0xA246AB8D984AF5ACULL, 0xADFAA9D8BCFE47EDULL, 0x9A7E37D5E3664A45ULL, 0x88C05CBD8D05F3DDULL, 
            0xEC2BE5BF7A772AA9ULL, 0x1B2B183E39B70348ULL, 0x0476FDA461D46A12ULL, 0x7E8EF13E2F3BEBE1ULL, 
            0xAE5411DC1DEE8667ULL, 0x5540B50C1636F9C0ULL, 0x07FC8AABFDAACE28ULL, 0xDBDD787268DE8A95ULL, 
            0xB716C787CEF18559ULL, 0xEE8D14137D603444ULL, 0x829D8A9E647DEB33ULL, 0x296D9329F3BD18FFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeyRotateBConstants = {
    0xFD57D984CECABD72ULL,
    0x506AF08F56458609ULL,
    0xBBCAA6D176407E74ULL,
    0xFD57D984CECABD72ULL,
    0x506AF08F56458609ULL,
    0xBBCAA6D176407E74ULL,
    0x08EECD996452334DULL,
    0x4439F1BE024C28EDULL,
    0xE3,
    0x6A,
    0xA7,
    0xAA,
    0xCF,
    0xAB,
    0x2D,
    0x99
};

const TwistDomainSaltSet TwistExpander_Menkent::kKeySpawnASalts = {
    {
        {
            0x0986792FD1CA55C6ULL, 0x814800672DB78D6CULL, 0x563132DC275BB583ULL, 0x7FA1EACE330F208CULL, 
            0xD7E0A18F401D8ECFULL, 0x6F42E67404067DE7ULL, 0x7A19E61FFE7032D3ULL, 0x2E4D0C963088FE0CULL, 
            0x2C23A9F3D555901EULL, 0x3C854571C3103A7CULL, 0xE70A7605FFA052DFULL, 0xAECA8B29B3F4FD3DULL, 
            0x224D234E2A1462CCULL, 0xA9C762043B0CB10FULL, 0xD63268290DF514C2ULL, 0x44D90C8017E2DE17ULL, 
            0x22F118391928AF53ULL, 0x5465640D5C7C805DULL, 0x2431149C7052CD76ULL, 0x064243DA9DD9F269ULL, 
            0xF0C672771893812AULL, 0x98D7210C055DF321ULL, 0x27242FF4EFAD0421ULL, 0x89426EB50F0CD35FULL, 
            0x6170B88DDEE923F1ULL, 0x91B6D226706B2931ULL, 0xC200F87E71F9C368ULL, 0x52A420909EF8AE77ULL, 
            0xF1634D9440A49D04ULL, 0x06A5BCE30BDEC38EULL, 0xC33C8BABE188D92CULL, 0xA303358063893341ULL
        },
        {
            0x895777E24E0B4C2FULL, 0x355356C4C4042CCAULL, 0xB57B84D7AF16F891ULL, 0xD8C722B0D9A09523ULL, 
            0x7F95CFD8C73267EFULL, 0xA083BC842B6EAA14ULL, 0x45E544F96239373EULL, 0x8FCAA316BF5A4922ULL, 
            0x224F7F0B5B7889F7ULL, 0x5C61B5E52A56349AULL, 0x9BF1CE87DFC3F8EDULL, 0x9F3696AB65A1E436ULL, 
            0x42379D0A704CA51AULL, 0x330F3E60C776E86BULL, 0xCB6FB6C0994B0063ULL, 0xE35B51958B97B160ULL, 
            0xC82E87B1580E5648ULL, 0xC49B926900A37045ULL, 0x07205B170B58A026ULL, 0x1EF23CE96317E3E5ULL, 
            0xA8CE194FBBC7670DULL, 0xA8A8C8C70C38CCBCULL, 0xCFD5880B805D42CBULL, 0x9675FC2808A8D71CULL, 
            0x93D668FFD018C187ULL, 0x0073C9FD80FD48D2ULL, 0x3F42664BD616EDFDULL, 0xEBD078CAA49709CEULL, 
            0x48A29B2B05FC631AULL, 0x901648D8676E1906ULL, 0xC397E75F37F6D2B2ULL, 0x1E84E649F8A74ABAULL
        },
        {
            0x76FEF196BF640A6FULL, 0x81FB2F8D2EE09C7FULL, 0xF9E16B062944677AULL, 0x95248F5C1D416108ULL, 
            0xEE3C2282266CFA45ULL, 0x494699745C20F453ULL, 0x53B5C39B3D2737E9ULL, 0x07A12D18162E58B0ULL, 
            0x1026532EA4807789ULL, 0xBBD0AB3C055FC913ULL, 0x7985B5674929CF6CULL, 0x3D908B3D3346BCD9ULL, 
            0x41266CDE34D3D79AULL, 0x0612E56592FA54CDULL, 0xA7B414012DE43B67ULL, 0x1F5D4DAE21EDCDFBULL, 
            0x50CB6596033C86F2ULL, 0x5E72F832F3BAD0F3ULL, 0x593E357ABF8EA146ULL, 0x1C7F37C241B6AE00ULL, 
            0xCDA46F3AEBFCA2B6ULL, 0xCE04DDF501155317ULL, 0xAA43716C7D608E21ULL, 0x4CC39BB401A0BA35ULL, 
            0x333A6FB680616377ULL, 0x730F131118ADD578ULL, 0x5675DA6F06CE8810ULL, 0xA15F4D29201CE3D1ULL, 
            0x9C22BE4D4F1A8BD6ULL, 0x4B78B986ABA72D38ULL, 0xD73EEEFBF0DF7171ULL, 0xEE3E424B47F4B472ULL
        },
        {
            0x7C67A04821EDC0EBULL, 0xE6AA00ED8435EEAEULL, 0x8ADF132C87970783ULL, 0x7DBDF0D4A90C4BC3ULL, 
            0x498E3F89343E3DE3ULL, 0x6E90627D18E14E3AULL, 0x7B745A43A23B1B77ULL, 0x1C91E0779E6D9271ULL, 
            0x38E0F78777E331F5ULL, 0x155722C0B2B4E419ULL, 0x036E1253F048EAE0ULL, 0x8C98FEAD2EAB6FBCULL, 
            0x23974671EA35FBB3ULL, 0x733F178BCC9EA500ULL, 0x67F5313FD42D3756ULL, 0x9DB6A968A61487BFULL, 
            0x2E1932D80AD64C01ULL, 0x3DBACC43F32B052BULL, 0xF3A1F9398DA6C6D2ULL, 0x9441D648DB9FCF8CULL, 
            0xB1557DCA87CF7281ULL, 0x5A0BE9E20602DC25ULL, 0xB33355E5B85B46DCULL, 0xECDB20DAFF7A7A8EULL, 
            0xAC904CC7D0F7898EULL, 0x69BDA27C9ACB82E8ULL, 0x6DA0C484AE8B8CEDULL, 0x9DECBAA9D34476D8ULL, 
            0xBCCFB113C8AB003EULL, 0x411420CEDBA1772AULL, 0x99817FE9B5A819B2ULL, 0xA217DC6D108C1DD0ULL
        },
        {
            0xC89FBC0FF2B8EB55ULL, 0x58F26F695E8AED73ULL, 0x7F10A2313135AA8CULL, 0xA3247E97B89AF6C2ULL, 
            0xA13F6F58A0B54723ULL, 0x049F9A966C7B53DAULL, 0x571C063540DA9997ULL, 0x25F8413F48C069E9ULL, 
            0x2BA8A74C60B6AC32ULL, 0x3BAC2CDA25FF341DULL, 0x98B7C390E3D08720ULL, 0xD9C1D13CBD5C33D0ULL, 
            0x73E8B0CB2ABEFC64ULL, 0x05AF08EC28FC75D4ULL, 0x53BB15AFD038CAD3ULL, 0x69903A44B47EFD6AULL, 
            0x19948AC406C25E56ULL, 0x448C1ED2D6B55B06ULL, 0xED11CD2C6C2931A8ULL, 0xD1ED15783E98BBFBULL, 
            0xF5399D35BD0DD451ULL, 0x60BD04DCDF81C7FFULL, 0x5F22091136BE042FULL, 0x2DE0DD00255066ECULL, 
            0x11D51F5E9FCFFA67ULL, 0x8BEF8B5950FBD29CULL, 0x751A7240A4BE3A6CULL, 0x1291742C8A9B716DULL, 
            0x6001091BA0EC9AD6ULL, 0x71C63A06D81CD465ULL, 0xE3F9C6CBB004C306ULL, 0xC2733E3D0603419FULL
        },
        {
            0x25888ADCC3D2A718ULL, 0x5141A5B8A10ADBB6ULL, 0x8C9F70364F9F37F5ULL, 0x53226FD913F73A30ULL, 
            0xE3A04ADED74F0062ULL, 0xD5508B1C72198BD8ULL, 0x69EFEFB7B7F9296BULL, 0x0CDFE9FA445F5512ULL, 
            0x102DC36E60FCC220ULL, 0x01FFD0A87ECD51EDULL, 0xC92A05497D0B7E0DULL, 0xA6224036DC0BC617ULL, 
            0x47A8279D41FD55C5ULL, 0xF7C690510CAA8EA1ULL, 0xCC799BF60084755DULL, 0x309142583EE4CA4EULL, 
            0x00139C448A70C12AULL, 0x940482AEBDC0279AULL, 0x949B9347034C477DULL, 0x138161D08502F898ULL, 
            0xE194CE37A7A4EC8DULL, 0x59467EA743B45870ULL, 0x29E642F219876B02ULL, 0x09E09FA5CF7529ECULL, 
            0xA5E6E03D0C99B482ULL, 0x760C3B5EE9BB402DULL, 0xFF729A59CF4250B1ULL, 0xBCF91285500E41CDULL, 
            0x7A8AACED5BD1360CULL, 0x01AD9FA72E007F59ULL, 0x818FE8463C4E2370ULL, 0xF7BBB90DC2441963ULL
        }
    },
    {
        {
            0xC964CF5A547C66C2ULL, 0x3D4E45775E43E67BULL, 0x3EE2156E3221566EULL, 0x715C3EE58F2CE7C3ULL, 
            0x7B6D14A61224019BULL, 0x122C891BE40B26F9ULL, 0xC054710E6DEA7FDCULL, 0x6E30CC53066CF5CDULL, 
            0x577672CF583937B7ULL, 0x23D3F901F44D8335ULL, 0x705666F937DD49DFULL, 0x930E9FCFD1F51663ULL, 
            0x531A4582D5A2FFFAULL, 0x5B564FDF6DFBA382ULL, 0x55997386B1FAE48CULL, 0xA67FB8A73F615241ULL, 
            0x137670804EA20A1AULL, 0x5797E81F399FEBAFULL, 0x5E001DF58B1D5B1EULL, 0xAD4729B601972FB9ULL, 
            0xB6DAB4DF3DB54351ULL, 0x0F7AC5A3D67B15D6ULL, 0xD3A0A10F6C7652FBULL, 0x11BEB4CDD25956F9ULL, 
            0x3A22A09FF9691632ULL, 0x2319263857166F48ULL, 0x8A8AA9B3991FC9AFULL, 0x70A2014F9DE1E009ULL, 
            0xF3A1CD4B3A5E14C7ULL, 0x13672C61917CDBC7ULL, 0x29DAF7DAE03AF147ULL, 0x2E2B40ECACC565DBULL
        },
        {
            0x70C062CE8085DB2EULL, 0x3B447A29AC9A3B44ULL, 0x9F82A82FB5B4A0EDULL, 0x32216EBE3761362EULL, 
            0x0B6DA78A729CF125ULL, 0xEBB339EBEB813218ULL, 0x0A3499EDFCBFB4CFULL, 0xE3191455C2F28A14ULL, 
            0x4BDD0EA59A821441ULL, 0x29FDD722F459167FULL, 0xF89F4CCB3099DDE4ULL, 0x6F9C2BFD165B7399ULL, 
            0xA2AA561DF1311DB9ULL, 0x2F08C0FD64E9B524ULL, 0xF0285E9EEC19A0F3ULL, 0xE8DD6DCFC609C2CFULL, 
            0x576C916B9D46387EULL, 0x1DEAE7ED7D52E050ULL, 0x2EC7FD5569D31FEBULL, 0xF1E499EC49777FC9ULL, 
            0x636B990FE7F9BECAULL, 0xCAF5F4855764C52DULL, 0xDF89581159A46775ULL, 0x2EEC86795FEF6322ULL, 
            0x62FDC36894EEFAF3ULL, 0x78501665D710E29AULL, 0xBB56757C44E0B6AEULL, 0xD49C35D18D970F87ULL, 
            0x97413248B368FC3EULL, 0x712080CA2C78C37DULL, 0xC02887E856AD7228ULL, 0x9BF42882B3A80C34ULL
        },
        {
            0x968C9C4017C209B9ULL, 0x0B9D8DA6847F6FDAULL, 0x994581C2EDC67027ULL, 0x202560E033C94332ULL, 
            0x307623BC1C706D8DULL, 0x61C437F6CB81125CULL, 0xCECE4D90164CA141ULL, 0x17EB451F0E5E67C5ULL, 
            0x8DE171D20C314879ULL, 0xF7AC4211FEFB5A0EULL, 0x979BD995F3088EB3ULL, 0x91DBC174B3BE3C0CULL, 
            0x177642489E5EE3E5ULL, 0xFF11D0AD780AFB6BULL, 0x57F3326EC211704CULL, 0x12B62F5BD9F87B57ULL, 
            0x00EDC47936B9C4D2ULL, 0xD03C3BE6F254D697ULL, 0xA5B246008ADCC137ULL, 0x843DD1BA85F28C52ULL, 
            0x9432B2BB443EABA7ULL, 0xC2E55AADE260804FULL, 0x34B35A75FA59D386ULL, 0x798AF7C9CF9C4338ULL, 
            0x28AE4114CDBB7636ULL, 0xA4BFB9436909E0F5ULL, 0x77E91EA5AED8B07EULL, 0xF134C8C99F0A4DC5ULL, 
            0x11FB20F13F503C00ULL, 0xACC6B008670A7E79ULL, 0xC7030206791B0018ULL, 0xB3F25DAC3B6FD4C9ULL
        },
        {
            0xA3547E33DAB2917BULL, 0x26B9DA8F9757F143ULL, 0x693C1ABAB266D622ULL, 0xD29ACF9CE9B0F332ULL, 
            0xEADCA968209F2245ULL, 0x789D9075F3F711DBULL, 0x163D4EE14F4400D8ULL, 0x252CBA590855182CULL, 
            0x92467E0420BCE249ULL, 0x5B480BBFA4AE7F32ULL, 0x1317502720E56697ULL, 0xACE64911EE14ED3CULL, 
            0x5EB79264D036FC27ULL, 0x9618F0FCEA853B7FULL, 0x31C29BCCAA59FEC7ULL, 0x6D8AB0F00587D856ULL, 
            0x2AE3CB4E33008D12ULL, 0x8E2DAEFE5C310EF9ULL, 0xAC8A29E97FBD3D5DULL, 0x5D0E8AA5E44C2C45ULL, 
            0x07B45E212B7E59F6ULL, 0xCD13C8842917B8CBULL, 0xEA4D319F988C30C1ULL, 0x4A7EA8C61FE56266ULL, 
            0x6F929609CDF4A940ULL, 0xC23FDB619C378A94ULL, 0x01592885F9799907ULL, 0x3094179811B7205DULL, 
            0xA14F853A401EB9EAULL, 0x01EE4CEB84BD721CULL, 0xAA1579BA553AF4CAULL, 0x67AB9E4A3CA02616ULL
        },
        {
            0xC4C370F55C428FFCULL, 0x758C8A0D29E38C1BULL, 0x225C2983F3C60A3BULL, 0x5D3987DCAB729B08ULL, 
            0x1D6D6DBA3E803140ULL, 0x0600A68B6DF5EC19ULL, 0x7F9E69975DDE5169ULL, 0x5F702E7CBC8C5741ULL, 
            0xFD0A11136157466BULL, 0xCA559E4CDF081A8AULL, 0x8800C51E585C5BE8ULL, 0xF4B7E529501FD118ULL, 
            0xEA0C6B7AE0826B8FULL, 0xC9CDFE0DD3BFF928ULL, 0xDBA26F0B11268749ULL, 0xF84B11A8CD3FDE7FULL, 
            0x57E9BEA94893FE5EULL, 0xD3446A71D57D3169ULL, 0x381AE9C491D73F37ULL, 0x1274BA5BD927A528ULL, 
            0x86AFD817244A18C3ULL, 0xC0E84720FE959C0EULL, 0x70BDEAFD907D6EC6ULL, 0x21FFDDAC4CB0CC1CULL, 
            0xE20670AD574087C6ULL, 0x93212A02CE5E037EULL, 0x200E899A86A1E92AULL, 0xB7FDA0C80EBB25D5ULL, 
            0x94E13AF22DC6000BULL, 0x9E98004CEE657758ULL, 0x33CDD9C67580699BULL, 0x9EF9B0B5F128B0CCULL
        },
        {
            0x9E24F9B616521FECULL, 0xC87A128355FE4C8EULL, 0xDFC479CB32529BDDULL, 0x3FA7787EFF86B717ULL, 
            0x0A2AA562EE80720EULL, 0x935561900B35E8F6ULL, 0xC2380D291F1B3BF6ULL, 0x6B0506100DD18155ULL, 
            0x90CC7E7EFFD0E9B4ULL, 0xF15F69B70A9C674BULL, 0x2563495A49AAF8FEULL, 0xB235D6FE158DB09DULL, 
            0xA25286AEC588C5E7ULL, 0xC6DFB1E14B1C58EFULL, 0x7F1516839CA3A7B4ULL, 0x25B962CA85E9FA8BULL, 
            0xAB1DA4018A19CB65ULL, 0x968176A0FEBC803CULL, 0x4459191F828A0B63ULL, 0x62B682559911420FULL, 
            0x1516D6D9547105B6ULL, 0x4F393048B1301D6DULL, 0xA6D7805A206A5E38ULL, 0x2A1FA6DA6E443270ULL, 
            0xBD9C6D9C91CF776FULL, 0x42C59E976246CA4FULL, 0x8D25476E25F75284ULL, 0xB8A7EF018B49DC34ULL, 
            0x2CD8859787080278ULL, 0xFB7B8E2B33F85202ULL, 0xEDDC91457834C8D6ULL, 0x498BAE02B104451EULL
        }
    },
    {
        {
            0xC06C12D0E36BAD5BULL, 0x5FD7BA3F7BDA53ACULL, 0x3538A9C14A64AD16ULL, 0xB3FF438118F13847ULL, 
            0x0E83E2541E8A0386ULL, 0x189DCC77E67DC427ULL, 0x6D9369BB52ED149AULL, 0x095788F8DAC8C5D7ULL, 
            0x353CDF043F5FA36CULL, 0x16BC888D166BBD03ULL, 0x3A6FCBD7C0D6925AULL, 0x1176CCF10CAB5D7AULL, 
            0xFDB1813194173CEEULL, 0x618F5E3DD53D92DEULL, 0x117CB95B149B76D2ULL, 0xC28FA5A02AAFD7FAULL, 
            0x9FD0FA1EECF99CC3ULL, 0x01FFC44E19C291CEULL, 0x9244C0AEE6711FA2ULL, 0x9717333DD62F94A1ULL, 
            0xF3396B02A62CE7CEULL, 0x3DE74404BBBE58BDULL, 0xA0EA0614465960E1ULL, 0x5075BE8BBE046945ULL, 
            0x72FF08328CC5058AULL, 0x5E44CF1CD6E6E052ULL, 0xB8E89B2C649C21B2ULL, 0x308457C2A948BC10ULL, 
            0xB6D2D048385CDCA4ULL, 0xEEC7B9A2CD9AE32AULL, 0x35ACDBB33C3573CBULL, 0xF39B6ABCC5C27FB3ULL
        },
        {
            0x2D79AB691FBE20B2ULL, 0x2310F5A41FE31620ULL, 0x1D68A462F7CF243FULL, 0x6EF36AA40157BC42ULL, 
            0xABD2B637E46AC727ULL, 0x7B9832C574DAC71EULL, 0xE6B0144B675AF58DULL, 0xF2F7A28BF79E249EULL, 
            0x1C61485DF72473E7ULL, 0xD8ADA92847393524ULL, 0x81401CD38F8D093AULL, 0x810DD0B14629EB8BULL, 
            0x3417164270C9FD91ULL, 0xE10037D6AA165818ULL, 0xAE60C1E6299ADC57ULL, 0xBBDFA462852EF138ULL, 
            0x55238314D5234D8CULL, 0xBCCE1DEFBDF61591ULL, 0x68EF4FA8526DFBD2ULL, 0xBFE5ED9D43339621ULL, 
            0x27BA86C63AB8178CULL, 0x6B23A8604BBF7F02ULL, 0x0A4AE18F6EE7F216ULL, 0x304CFF8EA0BBFC26ULL, 
            0x105B4FF1485CC5B1ULL, 0x92175385D593A77EULL, 0x5C5B869B2F4C74ABULL, 0x1AF3EF755E36EAFBULL, 
            0x6D72A999C57E7780ULL, 0xE357716FD21CD84AULL, 0xE0B3B8FCE3A2A607ULL, 0x1A67CFFD37E17ED5ULL
        },
        {
            0x95BAFAB7B25C4444ULL, 0x28E6A241751C80D9ULL, 0xC5B44C0B7E4A1ED2ULL, 0xD0152F5CD8B82D34ULL, 
            0x0A1D66A68F2C1BBCULL, 0x691508D1460AF249ULL, 0x8078319094828F50ULL, 0x18D4A66C7D418756ULL, 
            0x77ED70046471FE3AULL, 0x41B672B86C5615BFULL, 0x8C3402D642A8BE2BULL, 0x7B3BF85D1B067F0AULL, 
            0xF53966ED5C1923E6ULL, 0x8937474773928B19ULL, 0xB9ECE48FEB64C913ULL, 0x8B3E9D7495E6F744ULL, 
            0x44775083D2E35A7AULL, 0x90C4C3605DE40AD0ULL, 0x2260604E14C88151ULL, 0x85CCBDBE04B69B5DULL, 
            0xEAF9607145A93032ULL, 0xDD1EB2C17967E81BULL, 0x83E9883FC7B27411ULL, 0x10FEE037E4E3D4F9ULL, 
            0x1263043D5EC6C130ULL, 0x27DBEB19D7680BF0ULL, 0xBC0218A397A2D942ULL, 0xB9F91D6099818B76ULL, 
            0x6B134E998D6716E2ULL, 0x500F396BA1BA85C3ULL, 0xAE71FC27AC44F571ULL, 0xC20F948E338C0D29ULL
        },
        {
            0x6F2FEA1EDD1ACCF9ULL, 0x4519CE6BE7B4E351ULL, 0x9A3EB23005C10B78ULL, 0x44713411E0ED4D6CULL, 
            0x56594CB175FFEB7EULL, 0x7F6A7A33678797C8ULL, 0xCA4AC1E6788AB349ULL, 0x8FA7E3B8162A49A0ULL, 
            0x3E3B51A693380462ULL, 0x2DDFFDBC1515EA02ULL, 0xB8ABA56949CAB61EULL, 0xBA51188A7DE8850FULL, 
            0x3528E5E337599282ULL, 0x80DEDF7BAA63AA00ULL, 0x29225A7FB6C144D2ULL, 0xC1A624133BA86C73ULL, 
            0xDA29B078F9CECE26ULL, 0x71FB79DEB1ED5520ULL, 0x541D5CDEF380002DULL, 0x57A72A9D5FDD8DA0ULL, 
            0x05AEF9B1F429413AULL, 0x4F09D4C1D5E2A8EBULL, 0x9EFA9DBBBF2DAC62ULL, 0xE7500F09577881E4ULL, 
            0x154A5629D1614F68ULL, 0x8D3F0F76EF33BB69ULL, 0x5DD84E3C4D9FA904ULL, 0x748400FB7917A534ULL, 
            0x7685EFCBFE816374ULL, 0xAD0DCB600E2D0498ULL, 0x0E5DCAC9C6F9D55AULL, 0x533A4C9812BFFE1DULL
        },
        {
            0x060FAC7C1D24BDFCULL, 0x931DC2C61B98F9CEULL, 0x241C285ABC66CDF6ULL, 0xF09F2B70D68DFA00ULL, 
            0xC21AA16D04A21D37ULL, 0x3F56688E7CB8705DULL, 0x9A92CF056C69A27DULL, 0x9FADD3903ACDCC92ULL, 
            0x31A7E132747906C9ULL, 0x962988C06D4CD96FULL, 0xE85DA1EB0E826BD1ULL, 0x441ED4331EC2BC28ULL, 
            0xB13887A685926EE5ULL, 0x6BD46537A9834AA9ULL, 0xD16717AA328628F4ULL, 0xB931E1A8C5F5AB2DULL, 
            0x6853222B612DA889ULL, 0x6A35B1BF08EA5A57ULL, 0x66CC2DA0EA301248ULL, 0xE578D83CDD7FCF03ULL, 
            0x51A3B5EDE97077FBULL, 0x2F627EBBDDD2AA5DULL, 0x428926EA8378643BULL, 0xBFBDB8408D217F91ULL, 
            0x9B9BF8855E32D5FAULL, 0x7390B87B699B3F0CULL, 0xB531CF23342BFD08ULL, 0x49E22E7C8834173CULL, 
            0x6F03F98133C5F6FAULL, 0x4A80FDE5F3EBE345ULL, 0x299F5034E19E3D0FULL, 0x7522E19D43FFA420ULL
        },
        {
            0xB9510F7BEE7BE99BULL, 0x206FB7239F09813CULL, 0xDCE4D469BEB429EFULL, 0xFB87C8242BBC925CULL, 
            0x0839DB9DA13F0E38ULL, 0x9A536ECA99179106ULL, 0x81FAB059C42C5F12ULL, 0x398A3FC8393D7617ULL, 
            0xF8FD75689F7B28F6ULL, 0xDBD99369F1B87EC0ULL, 0xE13589DE685C5268ULL, 0x6D0D4D2B4CB8D79CULL, 
            0x1D112A9D103263D1ULL, 0x878649E9022292B9ULL, 0xA7D33F61C7AEDC17ULL, 0x206262FC9C2BC01AULL, 
            0x2AF0E73E2094188CULL, 0x504980DA2FAC8DA9ULL, 0x307492913B3A9525ULL, 0xAB3575EC00369CF3ULL, 
            0x76680D2317001D0EULL, 0x7B2A296543CB8516ULL, 0xF433E38622EDD6A5ULL, 0x8B6DA6981D29CC9FULL, 
            0x8B37B16D9D201AFCULL, 0xA12E69B903893AC3ULL, 0x218B075482B790E0ULL, 0x08D964EB83529689ULL, 
            0x1817BDFE50FE1B3FULL, 0x80F97335401D52ABULL, 0x20994EBBC9C8D6F8ULL, 0xD20C64CAD33117A4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeySpawnAConstants = {
    0x57D9752DD9FC0EFEULL,
    0x2D0808025D5678F3ULL,
    0xBF63243DD5100170ULL,
    0x57D9752DD9FC0EFEULL,
    0x2D0808025D5678F3ULL,
    0xBF63243DD5100170ULL,
    0x3F7CBA025826D199ULL,
    0x1B3CF572115C684CULL,
    0xD4,
    0xB5,
    0xC3,
    0x45,
    0xBC,
    0xA4,
    0x88,
    0x0B
};

const TwistDomainSaltSet TwistExpander_Menkent::kKeySpawnBSalts = {
    {
        {
            0x0701928B61C536EFULL, 0xD93B7A58B0EF2CE1ULL, 0x2DCA493E94034E9EULL, 0x109E67C2D940BD7BULL, 
            0xEB624473D46D0267ULL, 0xB172D1B47E55F7BFULL, 0x3F17752CE2E1E446ULL, 0xB97CFCC8E38036F4ULL, 
            0x6968669672D4D7A3ULL, 0xC3D3D6174CDBA223ULL, 0x335EF670243BD455ULL, 0x9D9A557FA55E97F9ULL, 
            0xA14FB50639157BD0ULL, 0xF9CEB05CFD7493C8ULL, 0x635606028F53AAC4ULL, 0xC72230E4EC7AA67FULL, 
            0xB082C6D0AB22A774ULL, 0x33E0937A07EDD6C7ULL, 0xA35714244E07BD2FULL, 0xA3F73436A93B335FULL, 
            0x2D909F40C2491FE7ULL, 0x3AD7CFE50546FCEFULL, 0xC165BE9483F975CBULL, 0x296B340252E94D29ULL, 
            0x8D4E0649FBC694F7ULL, 0xE0DBE2281A7DD0C6ULL, 0xB74D0479F8EE9549ULL, 0x6690DF743ED6A222ULL, 
            0xCA25C83A057EAEAEULL, 0xAA7342303E5CD4A3ULL, 0xCC7FCD82A24811C8ULL, 0x086E01FD7854477CULL
        },
        {
            0x9862ED1E718D7ACCULL, 0xB186ABD21ABCE2C1ULL, 0x2836F5D4F46FDECAULL, 0xF9B00F97B9F60EDBULL, 
            0xA29FFBA1CCFC8848ULL, 0xFD19AB24316C30D9ULL, 0x1A520C8B3FFB94C2ULL, 0xADA6F787E2315046ULL, 
            0x7C0E083B7650F561ULL, 0x8FB065E11AE512A7ULL, 0x50FCE15251BB9656ULL, 0x52126010773B065CULL, 
            0xA03E924DE98A6993ULL, 0x385D7908BC6F6511ULL, 0xDA3EF2B1D59BEB79ULL, 0x2F8915644DC2CECBULL, 
            0xEBFFDCC8133AE629ULL, 0xC4B847B823EEC4D8ULL, 0x0827D10C31DF6D29ULL, 0x01961F13FD6F1406ULL, 
            0xE2B64AA555F97727ULL, 0xE70B24213AD49177ULL, 0x7FB94C35F9C4B783ULL, 0x895A63D18BEB4E12ULL, 
            0x693399613CAC08EAULL, 0x75119FC3E9074F1EULL, 0x9B98E06B67F44F1AULL, 0x403184D042EEBC5EULL, 
            0xD8507B0B270088B1ULL, 0x1FD44C7C008159C3ULL, 0x843DBDF83D1E52B7ULL, 0x405DDD6235E1F571ULL
        },
        {
            0xDFEB13A7D14C323DULL, 0x371456568CE88AF5ULL, 0x0BBD50254906439FULL, 0x7CB185A4E47621D6ULL, 
            0x8A19452ABD7B46E4ULL, 0x6D0E79596496D65EULL, 0x1501A2EB143A33B2ULL, 0xC174896B04CF44FCULL, 
            0x7C189D04E28DFE5DULL, 0xEF654BBC8A371491ULL, 0x36FC6A692040E04FULL, 0x9AA8AAD65F9B6E20ULL, 
            0xF25D8D3AC64C46B9ULL, 0x39C33486B34666BCULL, 0x8AE6FBE694BF1397ULL, 0x5A74D15B04E938E3ULL, 
            0xEE8BE7DB175503B7ULL, 0xB0388AA900DB31C7ULL, 0xD660A7992C4EF03AULL, 0xA8711DB806961859ULL, 
            0xCED969D054D587DAULL, 0x87562D6290791C57ULL, 0x26A12365BF93D9F8ULL, 0xE4364B0548BC0895ULL, 
            0x23BE3F52669B98B7ULL, 0x116DB3B54C684943ULL, 0xA418CE6CE8CAA1DBULL, 0x65F797600371D097ULL, 
            0x53D4B10DA4A34F41ULL, 0xCBAB18C5A27397ACULL, 0xC98215BDEC450ED2ULL, 0x59BE86EB4B3BD25EULL
        },
        {
            0x8D65D954BF0787A5ULL, 0xC64F3FB54C760E4EULL, 0x22237B10E27A5004ULL, 0xA8E0E1708468349AULL, 
            0x37B806D0631FA0F2ULL, 0x5E072CFCBD9192E3ULL, 0x5D79DF229684EA45ULL, 0x4872348EBF7D361FULL, 
            0x11D578A100BCA61DULL, 0x67367E023D6A2E83ULL, 0xFEE6C16DD42611CEULL, 0xB794EB87975B63FEULL, 
            0xA9473450BC2D0444ULL, 0xA216B8793CA56602ULL, 0x186F2BBA63BD4F93ULL, 0x155A7BAD92B2C924ULL, 
            0xD2051F076208DB53ULL, 0xF53348842E432CD8ULL, 0xDBD0479C9A9E8057ULL, 0x1C7699FD2CA59DBAULL, 
            0xB608005CB35B9908ULL, 0x6B31640CC092AD30ULL, 0x418AAF4E8715121FULL, 0x5AE5FC59F548AC7BULL, 
            0x6CA18D90BA822222ULL, 0x3D15362999462733ULL, 0x6AFE7370B6C29E8EULL, 0x41D5AD7B3AE832BBULL, 
            0x8E1CB1D524B22BBAULL, 0x4A638E20EF0AFC86ULL, 0x647C5E62E5FADEEEULL, 0x56E40FB0D763F182ULL
        },
        {
            0xFBBF794F25B883C2ULL, 0x140820B9F56577D2ULL, 0x1E67078720B6848DULL, 0x25AEFACB0850FF35ULL, 
            0x8D2BABC393EFB3F7ULL, 0xE44EDF26ED8596F4ULL, 0xED25785825AD1F0BULL, 0x8C4DCE08719E6D29ULL, 
            0x1DEEE77C189E9864ULL, 0x61CFE75CE479A245ULL, 0xF3BDC06D2291B5E5ULL, 0x3282ACE0184D5728ULL, 
            0x8A30BE2BBBDE45B9ULL, 0x55E3CE4C11109F4CULL, 0x542624A98EC1ED94ULL, 0xDADDCDC6601C243BULL, 
            0xA1B972249D7CF81FULL, 0xEE4645F749CB3848ULL, 0x85F60945F6C2F532ULL, 0xA4FF23AF4495A125ULL, 
            0x60458FF4C1830698ULL, 0xC9A23532534DF974ULL, 0x975C2543A98D83B2ULL, 0x78342F81AC63487CULL, 
            0x263DEACAF8502E02ULL, 0xD97A0E42998D39A7ULL, 0x39A384483232DA9BULL, 0x19826152A1EA3B21ULL, 
            0x8E8774D6C4F520BAULL, 0xF4B28494A7BDED4BULL, 0x106A0B753CFB57E8ULL, 0x6755DCAC6E32DBD2ULL
        },
        {
            0x55F06AA44DA1D49CULL, 0x94E678AAC016C245ULL, 0x9D8FEDB447E26144ULL, 0xECED1255BB984C57ULL, 
            0x2FA95A97B19116CFULL, 0x54C5461DC33510FAULL, 0xADDB5D799EE6D04FULL, 0x7883C602385F5D3CULL, 
            0xB0D9B2B90678BB8DULL, 0xC344EA83BF225913ULL, 0x6B8D949EA78C877CULL, 0xCA1DA36DB5A8607CULL, 
            0x5F76C903DBC4FBC3ULL, 0xE412849898488D57ULL, 0x84121A387FA44337ULL, 0x9187AF03FCA4BD56ULL, 
            0x36D48BB6E5EC66ACULL, 0x3BA494D279D76EB2ULL, 0x9F58E1A0B6257E41ULL, 0x6592F0933CFDAA13ULL, 
            0xFF3DC40261006CF0ULL, 0x1CA16323B391E83DULL, 0xFC82D7409621D534ULL, 0x03B1596270C3B39AULL, 
            0xAD0A02D07E39979EULL, 0x6FCF96C4EA10C923ULL, 0x6357B600C671A231ULL, 0x980DDB29A8E43F19ULL, 
            0xBE845B8E6DA56CC5ULL, 0x5F299BD12CC6D889ULL, 0xE97B807790C54C21ULL, 0x77821DF7590C5DD7ULL
        }
    },
    {
        {
            0x947F7E8B45C4A524ULL, 0x3341126AFA85885EULL, 0xECED67A06FC24797ULL, 0xD5CA7805E70FF289ULL, 
            0x28EB79551663C5C2ULL, 0x7E09D32BC5AFC353ULL, 0x72635DB3810419F7ULL, 0x51DE571F5B4373E6ULL, 
            0xFAA921C4FA29C683ULL, 0x336CE8B9748FBABEULL, 0xE554654D68AA8478ULL, 0x95A30E1850A5E7DBULL, 
            0x5D1A5FA5F2148BC7ULL, 0x6A5C8A8D2A1ED6A5ULL, 0xAB603D7BCDD89FC4ULL, 0xD0F37C4439BD3DFBULL, 
            0x4345013700A036CFULL, 0x1ECD5597EC410C3FULL, 0x11C48DCE675D76E0ULL, 0xD52A9006E2BBD3DCULL, 
            0x280AD408E1FE3016ULL, 0x6E4F3BE00811B8DEULL, 0x4E917E5BD81CC6EBULL, 0xE30756D15C92F7E6ULL, 
            0xD0E4CD690FB871FEULL, 0xA5318108863DDE96ULL, 0xECA4D8A838CF10A2ULL, 0xF59A073FCD6C2EB0ULL, 
            0xC7C869E4BC358E60ULL, 0xF0DA93BD4E380361ULL, 0x115628FC38A6164CULL, 0x637403D6868680A0ULL
        },
        {
            0x37A8012789485AFFULL, 0x127C9BA99768441AULL, 0xF75C3F73CACA84CAULL, 0xC9BC4E259456EE20ULL, 
            0x8F55994219AD16DDULL, 0x0E42CC0CD5BD01F5ULL, 0x86D1296158F51321ULL, 0x0227595B10F87982ULL, 
            0xE1C86728676ABFF1ULL, 0xDF478E2D0F47245CULL, 0x247AA64BC4177993ULL, 0xC5E5A5D3DF3A79B5ULL, 
            0xF3EE0D47920B9EDEULL, 0x6D26B5E04FF74AE6ULL, 0x4E876D48163FBFFBULL, 0xCE5130A21EF82666ULL, 
            0xA3C66D434E7BC181ULL, 0x9FB386693DF0A8E0ULL, 0xB1712632E5D9D2BDULL, 0xED712F7074DB34EEULL, 
            0x30AD956EBBA14CC2ULL, 0x3E9A26BD8F715A56ULL, 0x0C37625A55C0EEBFULL, 0x368EF7D2C4A5F92CULL, 
            0xBEB403909706B45EULL, 0x1E7DBBCBCF82781FULL, 0xB7FE7CB24685D052ULL, 0x30D5B522793335EBULL, 
            0x7FDB69304BEF2291ULL, 0x7A75DF4E900D7922ULL, 0x9DFB679C5E2D2956ULL, 0x24F1912DD26D8328ULL
        },
        {
            0x217CF32BED652023ULL, 0x8EA79D0292899B79ULL, 0xC7107CCE261CAF7FULL, 0xAD972308CD4D7C36ULL, 
            0x4895921D083C7F68ULL, 0x48A1179E395DA37AULL, 0xB1EA65D907E0245AULL, 0x6A751A86C0C8502EULL, 
            0x1C2DE3E82072D8F8ULL, 0x339A9DF511E9B28EULL, 0x134C2F04CE13D6ADULL, 0x61F66EF1DC08CA13ULL, 
            0x6DB9D13FF2AD2A7AULL, 0xD2E9B4E88210A461ULL, 0x3041C149C3E9D875ULL, 0x696BDCE2420624BFULL, 
            0x421F4560C0593962ULL, 0x8D9AE18DA99F4589ULL, 0xD4EBA9950F9007FCULL, 0x89C4327A83EE8AE1ULL, 
            0xAC237B985099305BULL, 0xDABE7915FF9A3259ULL, 0xE3C683F323D1109CULL, 0x929B4EF613E78754ULL, 
            0x059F4D070ED660E7ULL, 0x4D96253FD7E58759ULL, 0xD493DCF49743C557ULL, 0x19A451952C9AB247ULL, 
            0xB35B30CB07A1F0DAULL, 0x16C6F5FF71EF84FAULL, 0x5C8DF957BE7140DDULL, 0xF4843AE3F30BD994ULL
        },
        {
            0x630AEE71080AD0FCULL, 0x3994BA18BCAC44ECULL, 0xCC651471C670788DULL, 0x98BCE639DE98ECCFULL, 
            0x3B51D2BC4D731BF3ULL, 0x8245968E6C25F5D8ULL, 0xB1A6C9DC7428E964ULL, 0x1BBFDB3A950347AAULL, 
            0x0310016750C39721ULL, 0x39275D714383C634ULL, 0x629F7A2ADBBD1307ULL, 0x33FF47515E969604ULL, 
            0xA80A61863576907EULL, 0xD51D3C359029DB92ULL, 0xA71D2B0B6F4E911AULL, 0xDF92E6BD7BC6B256ULL, 
            0x89F9F7345FC93EE0ULL, 0xB30BFF744543FB46ULL, 0x70692F0B2876276DULL, 0xFE317D0CF3960CF2ULL, 
            0xFA12068F2C1BD39BULL, 0x151610178894D004ULL, 0x6FFFC9A0B28CD909ULL, 0xF8E8BA88057FECEAULL, 
            0xCEF2C1ABA34ABEFEULL, 0x69E147C3E441D099ULL, 0xC18D21629C8F0C14ULL, 0x651C7AF6A460B267ULL, 
            0x4BAF11A6B6A276CDULL, 0xF50D7555DA253499ULL, 0xB1E75F46D79E8137ULL, 0x5EDA822D12699F89ULL
        },
        {
            0x37837BA78E29CEB1ULL, 0x054738CB464E41B3ULL, 0x4F03A27DC29B2239ULL, 0x1D09757FC2AF86DBULL, 
            0x2590FC32FD0E89E1ULL, 0x6272095C2122C400ULL, 0x46344346813D5125ULL, 0x3FB7562E6AD1A773ULL, 
            0xB72244CF190FF49EULL, 0x352F83D4B25EA9AFULL, 0xA8D15853CDB48B02ULL, 0x4ABA2941C55D7845ULL, 
            0xF6A4D0D570D65384ULL, 0xAD645D65F3C65A8BULL, 0xA472BD3F112A2D8EULL, 0xAE536CB8A153DE2AULL, 
            0x74ED436CB251C26FULL, 0xA48DFB2C288511C7ULL, 0x009AC85737CE7CEBULL, 0xDC8C5041879C4276ULL, 
            0x9F5839659D412DF0ULL, 0xF2D046FADC264EF7ULL, 0x27AF01282CA9ED81ULL, 0x3B2F2626A1E83E4BULL, 
            0x1A5F315725556932ULL, 0xD9EA7CE5FC9E7C76ULL, 0x7CC1C7069AB8FA0EULL, 0xC4CBE59E7F0AAC68ULL, 
            0x6C2D860F4201AF5DULL, 0x9AAA1CD2090BF29CULL, 0x32EF81BDD25A8B96ULL, 0x90286F234F8F17D2ULL
        },
        {
            0x9D528E3ADCE29095ULL, 0xCD1DFF4F180EAA5DULL, 0x5538C81EC49F1EA2ULL, 0xCCA380E7E01EB5CCULL, 
            0x507AAB92CCE85FC4ULL, 0x611E1731DE940A37ULL, 0xC2E8B3AB065FB9E1ULL, 0x59FDB833CDB48F59ULL, 
            0x595604CF719C4779ULL, 0xB476A40551F248BEULL, 0x53C47C0022B86B5FULL, 0x86F21C8B22E3A6B5ULL, 
            0x3E5926204686D132ULL, 0xE4137EF79143B41FULL, 0xF9CC84E51CCF2460ULL, 0x4AA4C0F466B04E73ULL, 
            0xA136A36053F75197ULL, 0x972E64B495127408ULL, 0xF66E6195205CA128ULL, 0x8F721C3E88D94991ULL, 
            0x3BE347F93918E5B5ULL, 0x21DCBA2490F97944ULL, 0x5342754A0E4CEAF8ULL, 0x036ED5BAE4793BF8ULL, 
            0xF7CEA2A7063422BAULL, 0x542E64DB1181F6A3ULL, 0xF0896D90896920A1ULL, 0xC188FAE1137D8532ULL, 
            0x7A3E1110B567F562ULL, 0x14095D8ABB67C3CAULL, 0x64BB36F225A68815ULL, 0xA1529C692CA1D2D7ULL
        }
    },
    {
        {
            0x4E981EA813EC61B0ULL, 0x1E5F66DA462CBDDEULL, 0x05D52A230735A5CCULL, 0x800B43AC660A1BE9ULL, 
            0x4490ACD31E8A6ACBULL, 0x4D936A9CDC53D658ULL, 0x1B764F356F1BBECBULL, 0xBD030BDD865A266EULL, 
            0x2F1C90D213A2F5D6ULL, 0xA33F8334CF470D01ULL, 0x7718AE4ACCBB2E19ULL, 0x2A240D86DC2551F1ULL, 
            0x8D922A6B16489BC3ULL, 0x66344C1341EB0339ULL, 0xA44584BCC29FB9E7ULL, 0x7D881F6E849F2E5AULL, 
            0xBFCB23B37ACB12E6ULL, 0x6E7026D2751796F8ULL, 0xF3A148002118034CULL, 0xCF14B09E8E65E492ULL, 
            0xF04CE9579F6952D6ULL, 0x6CD368947ECA927DULL, 0x07CB2D3AB618B911ULL, 0x7BE8538203AA3CACULL, 
            0x04ADB0F28D2C86D3ULL, 0x70A68C054A1E74B1ULL, 0x769B10AA78A3857DULL, 0x36F56EED3E2F6CD8ULL, 
            0x23354AD41B1AAACCULL, 0x7EA6A53C0799F681ULL, 0xEA981AD07498CB76ULL, 0xF8CF1A8C1E774B31ULL
        },
        {
            0xC89821B9F70EF24AULL, 0x5418BE9BD3D1D099ULL, 0x9FDA91D852195EC1ULL, 0x81EF5BAE89107E1CULL, 
            0x3369013A2B4494B6ULL, 0x9661DE2F4FA98973ULL, 0xE21B0BCAA92524A5ULL, 0x95BFCD7A3F01891BULL, 
            0x014B6F43E9B0BA75ULL, 0xC95765BF96A35B2AULL, 0x9463FD18D012EF5CULL, 0x0C7C1F165E63C25FULL, 
            0xA9543E5C2B8B3B34ULL, 0x69141D8BC7F915DCULL, 0x66B243F7469129D6ULL, 0x1A761426ADC1DCF4ULL, 
            0xBCC79F064CF24E1DULL, 0xF623E412DF71E3E5ULL, 0x9448B02B8C9AF9E0ULL, 0x09055F1D0D9B2E21ULL, 
            0xDD5B1082945081FAULL, 0x09EB3763E0FB5844ULL, 0x2D4265F6FA931EE4ULL, 0x8666BC62F7D450CDULL, 
            0xB06CD93BB404E310ULL, 0xBE0B37990FE7EB3AULL, 0x75B2CEFBFAF6DA91ULL, 0x96ED2E317B4B7545ULL, 
            0x45B9778B5A9222C4ULL, 0xB6EF1D0263A61BC3ULL, 0x783620E54B5A7A9AULL, 0x95537AAD34F0D710ULL
        },
        {
            0x4FD377A90B066265ULL, 0x049D7512CCEA89BDULL, 0x3861952A3738ABAEULL, 0x8C7EE27C62114DD0ULL, 
            0x4E2589B541B5EDE5ULL, 0x0D214FA8D584D1B4ULL, 0x2E1F2830B483F7CAULL, 0x594B85D9D45AEFE9ULL, 
            0xE641FEED02CC7FC5ULL, 0x2444B76D7C9A0833ULL, 0x13E41F72C6FBE0A3ULL, 0xEEF836D97649E60FULL, 
            0x05D84A91D905A1E3ULL, 0xC7CB58A59075A8DCULL, 0x08D4CC28EA6B3A15ULL, 0x5563E964BBB1667DULL, 
            0x7C9427DC1FCF9CD3ULL, 0x337D61C4027EF311ULL, 0xEA3007268E35B17AULL, 0xD89CCA367A00E799ULL, 
            0x471130703C8D5FC7ULL, 0x616EBD94EBBD12F9ULL, 0xFB85C126E2D0D31DULL, 0x2420966D07D94250ULL, 
            0xE61EBCA373157973ULL, 0x8BBDAA9D7A70D0D6ULL, 0xC12ACCBFD26C74DBULL, 0x91B4C0184A964EA2ULL, 
            0x4051D9E0B9E14592ULL, 0xE8D9F60A1ADFE23CULL, 0x161A7703A6428673ULL, 0x14423B6A2681135DULL
        },
        {
            0x539E8A2439D3CD54ULL, 0xBDE7C355CF3F7778ULL, 0x5C770E19EB67A301ULL, 0x3158F5B3923EBBD9ULL, 
            0x3D643AF0D55091A7ULL, 0xE371D416B00E4A44ULL, 0xF57BACB15C470989ULL, 0xF8105B56180AF977ULL, 
            0xEF0537080B0E1B3EULL, 0x2F18E59E1BBFAF7FULL, 0xE9284647C31E8AF8ULL, 0x0CD1290D8B743E2BULL, 
            0xE5E0EB6C4A954FB6ULL, 0x4C765BBD2E6E9193ULL, 0x3A04C5FAD6187D24ULL, 0xC0937AEB71CF7E7FULL, 
            0x72B862209E60C452ULL, 0x86ABAF7B99C97B71ULL, 0x499EFDEFAC28AA42ULL, 0x9ED27588F201C8FFULL, 
            0xCA4EA163B996DBC4ULL, 0xD03E073319A8320DULL, 0xA6B403D9917D7F63ULL, 0x0B82E61324149E62ULL, 
            0xFE104C5742F93729ULL, 0xD36AC2D3D518C215ULL, 0x6726BEA193A0F3CEULL, 0x234AF82A5D1AF6B7ULL, 
            0xF7B29EE35D40EF1FULL, 0xA4C64C583259136BULL, 0xFFFCDF78D8F3945DULL, 0x1695BCE5B5BB1F9CULL
        },
        {
            0x1B6A0DF8D5641843ULL, 0x46F83C1271579DBCULL, 0x4B9178CE92FE2B9CULL, 0xF7F4740A8AFE4FA8ULL, 
            0x25B605ECA865BD4DULL, 0x7B1175C58D9AC232ULL, 0xD69E5112FC1057AAULL, 0x067FF6F5E48A0401ULL, 
            0x64682E9623D1E884ULL, 0xE674EDA191C48BCCULL, 0x4E02074DFB036FAEULL, 0x5264A77EC5D9C90FULL, 
            0xB65E13F747E2FB55ULL, 0x535B4C5FD4180D2BULL, 0x4150A196EFE334C3ULL, 0x5312F2D3425581F6ULL, 
            0xC19AA473DF8118E4ULL, 0x9955B926DA85D42BULL, 0x7B13FA0C64F1F805ULL, 0xBD5298155D54650EULL, 
            0xFFA2697903DD687AULL, 0x26627E0829C1839BULL, 0x9A690CDD14D5CA6BULL, 0xFC4ECDB500AC0498ULL, 
            0x09616523FCEE8549ULL, 0x914C1FDF0862233FULL, 0x3D71665635B4AC1AULL, 0x6AD552E2311E6DD7ULL, 
            0x7C1FBD85BBDD3CDBULL, 0x516C6E8CE8E936D7ULL, 0xA0023DFF699315B7ULL, 0x2E4361A9B0FEBDBAULL
        },
        {
            0x89783F956C4DB84AULL, 0x4AF4C085D6AA0371ULL, 0xDBDE6B20C08E33EAULL, 0x4AB440FA9F1378FBULL, 
            0xCB3BC2D6111AA1F5ULL, 0x76481299B83B08F8ULL, 0x1F3496D2D9515839ULL, 0x3B9E566AF0BF34A3ULL, 
            0xA5A8F215A53360DBULL, 0xAE5D9653AD73D7E2ULL, 0x9A7DFADAF0D1F549ULL, 0xCB8B053BCA7E6A2AULL, 
            0x8A94D4053727715AULL, 0x1559B1C5D1BAFFE3ULL, 0xA03ACA301B5996B7ULL, 0xA6176B58AFF42296ULL, 
            0xD5CAC573243126E7ULL, 0x1FFCB5DCB548066EULL, 0x2F703BE15D58B2BFULL, 0xAFA86D57D48F9428ULL, 
            0xECCBD611228C7994ULL, 0xEC718DA95C30F588ULL, 0x7CDC541924440A45ULL, 0x714584E84C0915AFULL, 
            0x0C023621C5B3216AULL, 0xB32274396F790E97ULL, 0x407794013B4E4751ULL, 0xCC663A705364B92BULL, 
            0x40BAAF541C3CFAD2ULL, 0x491CF6C5AAB3610EULL, 0xA85422B9877B5A61ULL, 0xBA1B378C0CB02D26ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeySpawnBConstants = {
    0x957B58DB958AA87CULL,
    0x8EED1FF5958B769FULL,
    0xDB7BAD8458204D00ULL,
    0x957B58DB958AA87CULL,
    0x8EED1FF5958B769FULL,
    0xDB7BAD8458204D00ULL,
    0x268A83286055384DULL,
    0x2E4B36063DE2DE34ULL,
    0x39,
    0x24,
    0x5F,
    0x42,
    0xF8,
    0x05,
    0x0C,
    0x47
};

const TwistDomainSaltSet TwistExpander_Menkent::kSeedSalts = {
    {
        {
            0x2405FAFFF2437155ULL, 0x536E523F2FE8288DULL, 0x9ABE8E978A4A5C2FULL, 0x59364B7E8B358825ULL, 
            0xEB30ADBC0CD5ADC6ULL, 0x17E8B9A31D1EC454ULL, 0xC3B4AC4D685D001DULL, 0x4CFCDA6CEC8E6CD0ULL, 
            0x59E43B4FB32C6B63ULL, 0xF60E2908530FDC34ULL, 0xAB0D6DF0733BCBE2ULL, 0x69021934BCF936C2ULL, 
            0xE36CF1146218ED1AULL, 0xF4A9CBFB46CA9A29ULL, 0xC95AE5C6C8374301ULL, 0x29829CF5EB5ED96EULL, 
            0x47D6705EBE60B9F2ULL, 0x78FCB240CB2923B5ULL, 0xCB1B0C5CA020C43AULL, 0x7389E7A954E6D103ULL, 
            0x93ED882C69B463F9ULL, 0x0C1795AEA25242CCULL, 0x63DA10330C654745ULL, 0xFDAA5AB96414FE73ULL, 
            0x4AB038DD0B15A63AULL, 0x57D239215CC15739ULL, 0x24757E82F8D30FBFULL, 0x351C7C1F07FDEED0ULL, 
            0xB75063CF1BCBD5DDULL, 0x2E1C5E8A0822A216ULL, 0x632542C696038DF3ULL, 0x91053BF8D7724846ULL
        },
        {
            0x8456969D8764F513ULL, 0xBE676C2E68A8B5F8ULL, 0xB21496A5C0421FDCULL, 0x7E1C5D6D9CB61AB2ULL, 
            0xD5A63C9D6755B828ULL, 0x7DB18B8F18C47B18ULL, 0xCB7ABD96EE7C8D81ULL, 0x16D73BBB6C889A58ULL, 
            0x4B2C1B4BEF8B9C3FULL, 0xD6C27C8D1390046EULL, 0x31B3B881F645BB4CULL, 0xECC9F4F48779C7B3ULL, 
            0x8A2F3AAE5A77B2C0ULL, 0x8031813DB9C7B42BULL, 0xFFC8045EF44FF100ULL, 0xC208858C50E1A87CULL, 
            0xED694AB8D1E2DD9BULL, 0x0B25C3FEC981364FULL, 0x34A15CB334AA6487ULL, 0x631690ACC76FDEE7ULL, 
            0xBDA55BAA81B179C5ULL, 0x40C70C7D314A14CCULL, 0xE06E446A7486F764ULL, 0x1AFA558F50568587ULL, 
            0xD291E693138665E6ULL, 0x69AC0E6EED2B5232ULL, 0xABA049E61EA03B28ULL, 0xB16ECAEFBE67667BULL, 
            0x3C02939317DB48F6ULL, 0x5889AF250EC45D67ULL, 0x5C2322C396959597ULL, 0xFC2BBBD339571715ULL
        },
        {
            0xBF350F566B739883ULL, 0xA998262DB53F4B61ULL, 0x44F4243DCF86D21AULL, 0x720691A7D850CB0BULL, 
            0x51E8CEE8017A6CEDULL, 0x33C2BDD0AAB77867ULL, 0xAE20AAC660660D70ULL, 0xD61944C7A11A980CULL, 
            0xA9DCF6A8DFC1DC09ULL, 0x1077D8F82D630706ULL, 0xE99A387B09BB8F29ULL, 0xFFDDB62962A7541CULL, 
            0xED1CD4922D51E252ULL, 0xF252CFFF1E90383AULL, 0x5557779AAB63DBBEULL, 0x62361199494480A3ULL, 
            0xC97DC51BC2C97D1AULL, 0xC3DDAAACBA522502ULL, 0x409BD0F4B121DB16ULL, 0xA9A210335EB9A50FULL, 
            0x6C2D9402B9C52AF0ULL, 0xA23FD6CB5DBCB88DULL, 0xBBC0F8EA2390BB8EULL, 0x8557549AB86BE28CULL, 
            0xD0C42D3BEAEC849FULL, 0x7190CEAAA1A14D26ULL, 0x88CFD3DED11F1917ULL, 0x5B67D18711C1C583ULL, 
            0xEAB904177DD204E8ULL, 0xEF58384F5A7CA236ULL, 0x0F4F1FE2622BF0EDULL, 0x7ACBCE5BA2FBE730ULL
        },
        {
            0x281CFBC1AC926C21ULL, 0xD76052CE5365BEE3ULL, 0x4953BB2B8AC04C98ULL, 0xC9B18C37C9F67159ULL, 
            0x141CB8085757CA80ULL, 0xE350E31AB141497FULL, 0x1EF024AC17742418ULL, 0x89E2A5CC7A0811E5ULL, 
            0x37C5EA2886AF2A55ULL, 0x6E9A69261B56DC2BULL, 0x8818CE13E02E6CD0ULL, 0xE6C076111FDCEFE5ULL, 
            0xC7032E9F254C07DBULL, 0x23360EFBC1F06D21ULL, 0x83781A8766F6BF80ULL, 0xDBB20EDF5F375557ULL, 
            0xE818775936CF304EULL, 0x989FE92DF032AFD2ULL, 0x057C95DCD8E66423ULL, 0xD64CB90F8B0B5965ULL, 
            0xA585C36E1E792F1BULL, 0x07675BF901E646FCULL, 0x9168632C185E9599ULL, 0x2AA4880B8C8D4CEAULL, 
            0xA9D9A8665A30B8B3ULL, 0x97268C88D6C21104ULL, 0xE098B3ABDB542C6DULL, 0x776AA89D214B5F3EULL, 
            0x0DEFD5C853D84D93ULL, 0xDC36C57D310CDE2DULL, 0x6B053853020F3E67ULL, 0xB9333FF6B4F2CC16ULL
        },
        {
            0xF53F2217BC865200ULL, 0xCAE0B239305CE6B2ULL, 0x3D42AB1068DC2236ULL, 0xA420E54E097896A8ULL, 
            0x357065583A256A0BULL, 0x8EDABCBE901165CDULL, 0x8B5713C61F5B38DCULL, 0x070DB9E04DD0B4BEULL, 
            0x59D538EBCF68E1EFULL, 0x8927C1FD96C87AFAULL, 0x1FCB1EDE526ADCA7ULL, 0x7DBF7236D045A79FULL, 
            0xA3CA0DD365EDF6E3ULL, 0x22DE34AC121F0B6CULL, 0x97696AE9E505EE6AULL, 0x1D365AE99D73755CULL, 
            0xB9CB0AC324037854ULL, 0x8A9648FA57BB0C0BULL, 0xBC3242BBCF830181ULL, 0xA21DC19EA60F8D33ULL, 
            0x0760D5787DC5BBADULL, 0xB2B24263804956B9ULL, 0x0D02EE37620ED2F5ULL, 0xC5DD2B37A2385574ULL, 
            0x24DDF0B8AC8F9DB1ULL, 0x2F8CF0DB0DF060EDULL, 0x327AA5F7CD8B9FD0ULL, 0x2D53A026C5B5E5F5ULL, 
            0xA1FC468D4D92AD8CULL, 0x49335D8238182D99ULL, 0x0FA22201B7585C05ULL, 0xB8A38C059AE31EB8ULL
        },
        {
            0x72706F9128B9054EULL, 0x8AC85AA5AE1D602EULL, 0x2362D58726C18DFFULL, 0x5A2DB51455AC9ADFULL, 
            0x38C5CB8C51F6C95AULL, 0xB30540B7A8A81026ULL, 0x349CC4C4B62316F2ULL, 0x98C8933B44166D74ULL, 
            0x4D8CDBB21DB30154ULL, 0x032B3DB4059C0EAEULL, 0xAB060C7A0B712B13ULL, 0x0B3618C83FEFAD22ULL, 
            0xF9FCE41E9A5E1D22ULL, 0x356C6720C843C2E5ULL, 0x629B56315E4177F9ULL, 0xBCE71C9AFAA6027CULL, 
            0x5DF99A784E7D1083ULL, 0x036FF9681C4C00E6ULL, 0x5C2B84CEE7B44772ULL, 0x8089271517F7884DULL, 
            0x16FF7BABCDC559CAULL, 0xFBB5B54481213875ULL, 0x39DE496912351A31ULL, 0x358CE20DA7AB710FULL, 
            0xCA60A5C7642661A2ULL, 0xCB10E9C322037F09ULL, 0x94328FD4E30C0B5AULL, 0x52A81AF1F5733C49ULL, 
            0x904A45626CC8062DULL, 0x2EE6E40DDFBBD498ULL, 0xFD50AA648AEC9FA7ULL, 0x5B0B7FADA10D065EULL
        }
    },
    {
        {
            0x5BF6C726C7CEE35EULL, 0x2BCF9C8A1AB5D7F2ULL, 0x04058C81E3DAFA53ULL, 0x7A023057C4048263ULL, 
            0xA4276F238A367CA6ULL, 0xBADEB1911C8278ECULL, 0x23DC49AEEF4EF610ULL, 0xADA1E8FA0484BE9CULL, 
            0x957ADF63DD14CEADULL, 0xE6194D98EA56E723ULL, 0x36E96F367F04A8DCULL, 0x45F1062F91E5E827ULL, 
            0x4FEAE50C891A3739ULL, 0xFCE8056C2B98ACFCULL, 0x2B4444F41F7DCE00ULL, 0xD53A5E60514B1851ULL, 
            0xC05E6248B726194CULL, 0x9B2EA9DB3C176990ULL, 0xD6A240EA3BCF8353ULL, 0xFE95CBAF90C7C2C7ULL, 
            0x49582DC2BC1573EDULL, 0x04E3127AB8142072ULL, 0x87EB8130F77AC57FULL, 0x987B3E55D8EDEE43ULL, 
            0x58A735A7E909B8B3ULL, 0x1F589451FDE6E80CULL, 0xD270BEDE31A7F13AULL, 0xE22FA9B3F8A540AFULL, 
            0xAA29BC2236D7D93AULL, 0x9A62DB00871BE001ULL, 0x27C5C5E119BAD4BEULL, 0x9628B9CD01D96560ULL
        },
        {
            0x0C691156C6110865ULL, 0xF72B058DFB6F53B1ULL, 0xD5E94B9D2CAC93E2ULL, 0x34B048C112151D8AULL, 
            0x1CC6E5C66EE68302ULL, 0x103E8DB7ECA16DADULL, 0xF3EFDF67C66F5759ULL, 0xEE76909D7CE8C20AULL, 
            0x91967BCB43280407ULL, 0x41F98FFADD998CC3ULL, 0x761D8493D7FAC3D9ULL, 0xB426624157C7C4E2ULL, 
            0x4203EF68770A71A9ULL, 0xD2C4C24315EC08A8ULL, 0x2C77373EA8820F12ULL, 0xC44150AE82AADD33ULL, 
            0xF4B9A66108487E41ULL, 0xDFFC7A421F4C4366ULL, 0x90AC09D5B987BBD0ULL, 0xAA1B733523703576ULL, 
            0xB5EFFF60B6BFC4F5ULL, 0x9DC091BCB00492BFULL, 0x360D70B3C15E6609ULL, 0x27FF867D7AD6FFB9ULL, 
            0xC92D282B0046EDC5ULL, 0x97C56F2334684C7CULL, 0x927B8880CB281E20ULL, 0xB316B41B811D3A94ULL, 
            0xECD85835D1ADCB80ULL, 0xE05A5EB54A7C67BCULL, 0x32DB15AF374273CFULL, 0x0F9ED521ED783801ULL
        },
        {
            0x85F11329B51CB5E9ULL, 0x6BAF8D755E0BDB0FULL, 0x9DF0664100A6666BULL, 0x940638CF7B303F55ULL, 
            0x19A3F12995C33E3FULL, 0x562CF971F3D90A58ULL, 0xC0D05A5427100524ULL, 0x3A3E9B7A0496C52AULL, 
            0x5BDB7794CECA8BE9ULL, 0x0CC9436F3DFF6401ULL, 0xF2F637A910EB01B7ULL, 0x3F494E85EBE8C1A9ULL, 
            0xE25A7C74D5860C62ULL, 0xE65D98EC61DF1270ULL, 0x69A6E854A101E665ULL, 0x47ED79E113435DB4ULL, 
            0x1304F2325ED15FB1ULL, 0x420B717C81A5C6E2ULL, 0x7BE20C0806309A1BULL, 0xB1B9FD078B9DB573ULL, 
            0x8A4936D47120C478ULL, 0x51FE92436DE98716ULL, 0xECEACFF1DD313C68ULL, 0x31BE3A5BDC03E65DULL, 
            0x73F2AB7376AB8EF2ULL, 0x5EF3076295FFF2CDULL, 0x06588156607E77DEULL, 0xD3F783437075991DULL, 
            0x9590F7CF0E693EAEULL, 0xAD0D1B3E1EAC0695ULL, 0xCB8CCA471DD697DFULL, 0xDB737B7979F5B258ULL
        },
        {
            0x47BE70DA39963D00ULL, 0xF8C3C5BFD2137B31ULL, 0x483F7807E721056EULL, 0x4A788B8C22FA70D0ULL, 
            0xEA5CA8D042115284ULL, 0x3B5A9F2BA920FDE3ULL, 0x35EDABD6A88FC673ULL, 0x7A54807DC565FBBEULL, 
            0xD498FC788320C117ULL, 0x95715D617949EA1FULL, 0x626B84D09B0CB173ULL, 0x9612F83A255FF1DEULL, 
            0xF9BAC113F31A2E70ULL, 0x47954E53E003AE37ULL, 0x51E20D8D71CC9B7EULL, 0x72B5ED10262DE931ULL, 
            0x76889D2BBA37A408ULL, 0x404677CE055B9345ULL, 0x4C20F4F406470796ULL, 0xE292D9A6E6B6F605ULL, 
            0xEF9BDD9E4CE5F15CULL, 0xAF71722FD86AD35AULL, 0x7E3348C8A68F097AULL, 0x3F8DBE357AD43F79ULL, 
            0x98E136EB1E438C45ULL, 0x58D0B4F064B438FDULL, 0x4AB836B8A5D6F56EULL, 0xD8EE07E9570244E6ULL, 
            0x3382823161C447F6ULL, 0x34358411349BC705ULL, 0xDF4D964E9D2FB039ULL, 0xF03877E11BCFDE08ULL
        },
        {
            0x8521452EB1CE3ED1ULL, 0xD145BBFB9C088012ULL, 0x41D69B847E4459E0ULL, 0x2A0A8886717FF159ULL, 
            0x43AFB0835F4E0834ULL, 0x3017588E540E026BULL, 0x53E523E24FABF692ULL, 0xD99E20CBE160CD32ULL, 
            0xC99C598AF854ABC3ULL, 0xC8FA480F70E8770DULL, 0x5C6C7C0828BEE474ULL, 0xFE6360CD40C9AE09ULL, 
            0x6980645B9BC466ABULL, 0xA5C94D3B9E7B0B0EULL, 0xC8A12AC33AE557ABULL, 0xB9E8207A677EBBB2ULL, 
            0x870F48C49ED40E4BULL, 0x5DBDC9C23806DC07ULL, 0x3949183E7223408DULL, 0x5CD2DF9928918ED1ULL, 
            0xDA325B27406290F9ULL, 0x76DB1BC32D6902F7ULL, 0x8B9915F2ED618B2FULL, 0xB9807D0782ECCE4BULL, 
            0x2950C210CC9CCA71ULL, 0xA7B3B26E27DD8021ULL, 0x16565D2A7191D76EULL, 0x27BBBE4D084726B6ULL, 
            0x6ACE148526B3A92CULL, 0x0E79551DC048C3B0ULL, 0x7054848EB2BCEF3BULL, 0x70FE1DA411AEAC4FULL
        },
        {
            0xCF353CD1D5737BB4ULL, 0x37B2BB757BD60003ULL, 0x2F8442901B14EF26ULL, 0x5F348E5F32CCCE31ULL, 
            0xB9E65A4A0F5D07DDULL, 0xB2FA9C43F6EB6806ULL, 0xE3FDA34187031D2CULL, 0x7F2EA5FF0AE5628CULL, 
            0x36046815D17C3F64ULL, 0x155952CB18CE2F89ULL, 0x298A0BFE9D81D5C9ULL, 0x1E32E0AF27804AA0ULL, 
            0x30DC2CC3FA35AB88ULL, 0x8981C9C9A6D29315ULL, 0xBFBDF4F2FF9DAFE3ULL, 0x801B9F6549AB2685ULL, 
            0xAB6C1D00DA507A1FULL, 0x1881F5FD42491945ULL, 0x0977E580F58EEBADULL, 0xDF83E2DC1A0499CDULL, 
            0x2468365A4D9914DCULL, 0xDB29287DA406670AULL, 0xD0E5BB7716DD1BFAULL, 0x836CA30B00207199ULL, 
            0xF0718C6DB8E604D8ULL, 0x48A188F42D8F5BB1ULL, 0x8E5539A4DA021271ULL, 0x52AAAAB90BEE62FEULL, 
            0x784E64812FD100D0ULL, 0xE403F71CDFC55CF2ULL, 0x603BE22DAB229288ULL, 0x5C3CFDC0BAE485C3ULL
        }
    },
    {
        {
            0x9A73A81AC0ACFA24ULL, 0x70ABE0C323C6EBE9ULL, 0x9EF26E6782A55C77ULL, 0x7DA82F93A832D6BBULL, 
            0x0A9645AF7480A0E6ULL, 0x46E522FC6B7E4D3AULL, 0xB83168DB21ED47FCULL, 0x88CA6C5888A4271EULL, 
            0x119200E6707BE017ULL, 0x01B4C2658DC036A2ULL, 0x6E3C18C5421498CBULL, 0xBC6BB916527CE502ULL, 
            0xD3C501DC9AE41FF5ULL, 0x5006E9D8E19A3561ULL, 0xE2AAFFE02F893D09ULL, 0xD5874C1DB35BABDAULL, 
            0xBB6A5A9792612A03ULL, 0xC885F8FB6E8449E7ULL, 0x19C4A26AA4E745E3ULL, 0xE220E2007265FF39ULL, 
            0x79C52C39D746EB42ULL, 0xD63B4B1736476247ULL, 0x1B5CC600502C23B6ULL, 0xE854595558B1B913ULL, 
            0xC5B9BE72C7CC301EULL, 0x12B762ED4DDCFF28ULL, 0x2E66496DE545B599ULL, 0x94EF94BBE68514CBULL, 
            0x609EA804C5E4F60FULL, 0x5CE23D50FEB42837ULL, 0x5BCFE41D9CBB2447ULL, 0x5F0D636C5151BA30ULL
        },
        {
            0x80ADD44154CF89DDULL, 0xF9B3DC994C7F1101ULL, 0xE8D69F005B389E5CULL, 0xDC3129533304A0CDULL, 
            0x029FB57208D3CB21ULL, 0xD0A5060DACFB72E3ULL, 0xCA1621515881CD66ULL, 0x28FCA78F0EDCADDAULL, 
            0xBBCA817C4FBE6315ULL, 0x883307E3FB6378B6ULL, 0x632405116F989BA5ULL, 0xC77C7511AE4DFDC6ULL, 
            0xF847D5A7C103E9C3ULL, 0x11C3BF89F685576BULL, 0x477534B9CBBD7852ULL, 0x67014FE25478A882ULL, 
            0xD3A8A786A6BEE6EDULL, 0x1BD139D4B49AA4C0ULL, 0xCA562C4F6E486972ULL, 0xB8C9D13B0ABC108DULL, 
            0x668F844FFDABC79DULL, 0xF940C747FA625046ULL, 0xF508C0237287BD48ULL, 0x64BD35CDD857F6EDULL, 
            0x4803233E9FEFC1D4ULL, 0x686304D085E248A3ULL, 0x20340015EB7FFC5DULL, 0x51466379BDB1028AULL, 
            0xD241F3689E84A871ULL, 0xF01D932BB400F948ULL, 0x535BDF942D43BA92ULL, 0x921827B9B75DA407ULL
        },
        {
            0xD9A16D07A20C7EC1ULL, 0xB22931E7735F8E17ULL, 0x6AA290403A14B225ULL, 0xCAEF988047240B17ULL, 
            0x4104D9DFDEFEDDBCULL, 0xF2D434C138B0EC7BULL, 0x2EA71EB92D1E0E38ULL, 0xE594DB53A08970E2ULL, 
            0x9EBAFE3BCE7C394DULL, 0x8B267C2619ACDF59ULL, 0x7E489B515C758FCBULL, 0xB3597CCC97E1C35DULL, 
            0xB30B32816FB686E8ULL, 0x86327A3BA60A4789ULL, 0xBD13DECC2E836C9EULL, 0x373A406078EC05E7ULL, 
            0x78BB313868596A18ULL, 0x4CBC6313CD223686ULL, 0x533F427F90A1775EULL, 0x155AC405EF286AAFULL, 
            0xB725CC623853E9A4ULL, 0xE649AB805FFA116BULL, 0xD9B179B33AE8B120ULL, 0x9966A9855DF141DEULL, 
            0xFE42502DDF483A36ULL, 0x9B71B03218047E2FULL, 0x7A9055B6F8F91039ULL, 0xAF33C96D665F4891ULL, 
            0x4C1F10AD8D270C35ULL, 0xEF7C4179D9BB6215ULL, 0x17F4B1DDEBB153CFULL, 0x6328C82FDA82D758ULL
        },
        {
            0xCF3056BFFA7B47DCULL, 0xA3AC029EA1A145F0ULL, 0xD54B09219A43DD06ULL, 0xA2D405B3A01B8419ULL, 
            0xC9AF3620D4700874ULL, 0xA6AB76FCC83CEF51ULL, 0x9DD3C0AB422C09F1ULL, 0x4CB259CEB89766F3ULL, 
            0x10C7030383A50071ULL, 0x71CD294A5A43A9A0ULL, 0x2728A4C54F44CA0AULL, 0x050C056360091AC3ULL, 
            0x0BF2670D9F261107ULL, 0x6F62C322A2AEAB9CULL, 0x21CA0571571274DCULL, 0x21BFA95871A1863DULL, 
            0x49ED38525AFCEC1BULL, 0x8415B186C8787D78ULL, 0xB7D70E2B24CF291BULL, 0x72C2657262ACBAF4ULL, 
            0xC7B8BD2724DC507BULL, 0xDB4C015D9EED3467ULL, 0x52787AC712C17EF4ULL, 0xB6A7A301CC83E68FULL, 
            0x70F10DA12CB0A266ULL, 0xF7D528FE8551D8AFULL, 0x8C67042EBFA48E5BULL, 0x0E3DC6A43282218AULL, 
            0xC6DDB37624B794F7ULL, 0x68FD9B9D37A27E57ULL, 0xEADA3738ECF16924ULL, 0x8E51421DA30E8488ULL
        },
        {
            0x7F8974E02E04AE2DULL, 0xAC337A4B83FD7B70ULL, 0x97F2FE3A51C126E1ULL, 0x8E8458182E9F74AAULL, 
            0xD01E455FF275D409ULL, 0xF86DB8F14AC116D3ULL, 0x9D7BA781EED984EBULL, 0x3285926376018FC6ULL, 
            0x0C6B3770A3E371B2ULL, 0x5A9E7ABD058B305EULL, 0x26B07C044F35D017ULL, 0xCAE52F2B53551052ULL, 
            0xF592858A16E23061ULL, 0x568A776BB92E8CCAULL, 0x232A769F2DA2E2D3ULL, 0xD13261077E25168EULL, 
            0x505F63DA698E6F7BULL, 0x0858D1C075FE35BFULL, 0x8DE0784F4B5528C7ULL, 0x2A531890F3E09F8CULL, 
            0x1A124B4FA74D332BULL, 0x70DE1560806DA01DULL, 0x024FE5C25AD4AC97ULL, 0xAB9AFAE71E742236ULL, 
            0x328AD05035607B0BULL, 0xD5DFC14F10AADA30ULL, 0x823CDED32F0AD7A6ULL, 0xAA5AC69FF8852B1EULL, 
            0xCB83FC8632114344ULL, 0xD3A38AD4DEF714C1ULL, 0xE8E4705B0FA989D0ULL, 0xC2357F7E435B0AB4ULL
        },
        {
            0xD298C1692B504720ULL, 0x9FCBB0C66A4661F6ULL, 0x7A4DEAD5B1ABB0A3ULL, 0xF291846A3B06C018ULL, 
            0x0F51EEC9CB5C6673ULL, 0x98BC2359A1E9A587ULL, 0x8853D07542356E66ULL, 0xB1682E2C2BE2C9BBULL, 
            0xB414CE914FDD41B2ULL, 0xCFB5C8ECF1F2E08AULL, 0xD1164FBABF90E83FULL, 0x4CA9304EB59A8313ULL, 
            0xEECB620B64F8D511ULL, 0x8E048BAB63755DF5ULL, 0x4514B5CAB5032A0CULL, 0x96A3126D6CA35F2DULL, 
            0x7E0FA963AFEA9183ULL, 0x0AF981749DE43A58ULL, 0x2660D61CCA01325FULL, 0xA65FE02EDAF7226DULL, 
            0xCF79721D9FCD5833ULL, 0xE0C44EC41E3B0C14ULL, 0xEE49111C237EC9DDULL, 0x02CB7D29BF9DD3E9ULL, 
            0x3FF1ED3085E97A4DULL, 0xB45D668C7D633143ULL, 0xB090BE93534434FCULL, 0xA68DB2ECEB9A1D00ULL, 
            0x8F20E66D5761293BULL, 0xED194D8DA8E3D344ULL, 0x678CD64BAECD35C8ULL, 0x775F62C760338237ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kSeedConstants = {
    0x8F37F96709B330D5ULL,
    0x0D81EA9DB57FF201ULL,
    0x65534B268692B6E5ULL,
    0x8F37F96709B330D5ULL,
    0x0D81EA9DB57FF201ULL,
    0x65534B268692B6E5ULL,
    0x7565B737059139ACULL,
    0xEDF7B256D316AF79ULL,
    0x6A,
    0x60,
    0x3C,
    0x9B,
    0x44,
    0xC5,
    0xCE,
    0x37
};

const TwistDomainSaltSet TwistExpander_Menkent::kTwistSalts = {
    {
        {
            0x04527F50D875AD23ULL, 0x9BF288BCAE19142EULL, 0xBC26F0824A532512ULL, 0xD8B97F67ADC35AE3ULL, 
            0x98826FF85B10321AULL, 0x99158326A4CFBC35ULL, 0x26660706D41D2814ULL, 0xFADC0C70FF87B526ULL, 
            0x43AC267798FA4AE7ULL, 0x63743F27F117544EULL, 0x2BA8A33583FBAB44ULL, 0xC9605D43A74D3336ULL, 
            0xB2A96C0380DD10C2ULL, 0xFA6A961334C15F8BULL, 0xDA9B4694F07723B7ULL, 0x889480FBA6A5234FULL, 
            0x0C59FBFFB5CB0AF5ULL, 0x07E4791BB080F29AULL, 0x29D7669EC9A5368DULL, 0xD47E2916EBF01F12ULL, 
            0x6A336CC6DEE55E51ULL, 0x48D3226DEEBD36B6ULL, 0xBF045F54837D40DDULL, 0x915CA6537D585F92ULL, 
            0x418C6861D7435060ULL, 0x07B1526B73DCCBFFULL, 0x54F04418C5CA65ECULL, 0x1A99E9D29C75BAEDULL, 
            0x0FD8FC663119FF4FULL, 0xEE211C7E7E3DEB83ULL, 0xA9D5F2B8E3DDC05DULL, 0x2E2580165B288C9BULL
        },
        {
            0x3A601302A74E75B2ULL, 0xF05581B171DD566AULL, 0x5E2664FE43B6C381ULL, 0xF92A0DC9BD356CF8ULL, 
            0x88196795937C3F2EULL, 0x223ED5A22FE194BEULL, 0x1A7E0B9ED531AA9AULL, 0x55F6553B48D8DE6BULL, 
            0x2E88C87151BA4ABCULL, 0x11C200682E6A2EB3ULL, 0xA66D43916A6F1C59ULL, 0xE419748C40126C95ULL, 
            0xCBFF8C900BB05A42ULL, 0x64646A0387E7CCD5ULL, 0x4E7D1CB186E8F00BULL, 0xA3CEDE6CDF9B9C77ULL, 
            0x0343F5B203D8C5B7ULL, 0xB74D7A13C5F534FBULL, 0x0F0E5FEE1B51B7E2ULL, 0xB4E5630672225324ULL, 
            0xF5150655F4533AB2ULL, 0x3205F51DF5144F06ULL, 0x217DDC73D86D0CA3ULL, 0xDBF3C5EEE22347F1ULL, 
            0xD6E38AF39A810072ULL, 0xF9EC191D8623791EULL, 0x1840C2096A1FF719ULL, 0x0989B74A19EB265DULL, 
            0xBDAA12C59307A794ULL, 0x06DCA7D464A841EAULL, 0xF25FAE4D913E015AULL, 0x8AAA0AD4EEDC695DULL
        },
        {
            0xA88762487BFBBDDDULL, 0xEAE37836F15F165FULL, 0x57648F175C067942ULL, 0x0FB2D88D710155DFULL, 
            0x61FA2FCA6EC436BAULL, 0x5D109DB4AAB3C198ULL, 0xC003C3C336C56236ULL, 0x8E5B7FD90BB254F9ULL, 
            0x0E4FC2837A382095ULL, 0x3479DBFD30746B99ULL, 0x3C5FDFC0302A440CULL, 0xA66E66B035F09418ULL, 
            0xB89DA3BD399335C7ULL, 0xF25F7C7955DC48BBULL, 0xC700D8B9EA346B37ULL, 0x7608627B42FA0806ULL, 
            0xF2B9DAE2BED6BB78ULL, 0x4EF32EBF40F07BBFULL, 0xFF44F4AA8DA91A59ULL, 0xEB3E400DFB54501CULL, 
            0xACFCAC158D1DC039ULL, 0x17C0AE5F6B90F5D0ULL, 0x030ECCE92C243970ULL, 0xF13024CC562EC48CULL, 
            0x2F95E6AAFC5F0A07ULL, 0x9EDA9CBFF76D5D79ULL, 0x01E22E65A2B6D3AEULL, 0xA8AC08AA70EF99D1ULL, 
            0x9AF52A04DEB270ECULL, 0x9CB2D90DEF4BBDE9ULL, 0x390A1C4DA6F2A26AULL, 0xA6566E80CBAA8338ULL
        },
        {
            0x0D289FD572203EB3ULL, 0x727C0130E683D79FULL, 0x76E3D0ECF6055207ULL, 0xEE2125C3CCDAE088ULL, 
            0x0DDE4DC037489536ULL, 0x480760B100CB66D5ULL, 0xB598B2DACD4F67ABULL, 0x11C3DDDD9AE0E727ULL, 
            0xF0685079BBC70602ULL, 0x13345C4F696FA7F2ULL, 0xF69A8106C6B64AB4ULL, 0xE4C77669DDE9CC38ULL, 
            0x3B62C70248EB77E9ULL, 0x6EF3254BB6EBFDA2ULL, 0xDED6A08B5917D211ULL, 0xDDFCF9FF520BE6D9ULL, 
            0x8716F1BC787E402AULL, 0x97102C5A41D10952ULL, 0x01F040CD32F08889ULL, 0x1971CE9B9CDCAAE8ULL, 
            0xB8BC33D5C634A79CULL, 0xA9B6C5C277DDDE55ULL, 0xC6736641C4693BD9ULL, 0x2DABFD00B3961AECULL, 
            0x40A614C08B8CA9A3ULL, 0xBD5098558FE015FDULL, 0x0546914D33F69D17ULL, 0x3F32BB7D59700F49ULL, 
            0x4C784B4B7CD5B2D5ULL, 0xC31F147722EE0BC3ULL, 0x816CAA16D5E602C8ULL, 0x47741A989F4B5679ULL
        },
        {
            0x5105BB535DEE2C1EULL, 0x87DC4AE0348E94BFULL, 0x96741408D012BDF7ULL, 0x455060028F71C75BULL, 
            0x5A6F6D73BAC04FB9ULL, 0xE155CA2F33D4DF21ULL, 0x933FA264F155B396ULL, 0xD945BA7221B0B045ULL, 
            0x828B601DB3636137ULL, 0xC06EACC9C4B810E1ULL, 0x173F31C268E15589ULL, 0x410912764ECE6D61ULL, 
            0x24EAAFDFE561F34DULL, 0x1F8E358247F6AAC0ULL, 0xF9E2B6DAEC97DDD9ULL, 0xD776A77B03A123BDULL, 
            0x363A4A4AF4739A50ULL, 0xFF4EB4B0EFA71EBAULL, 0x3A51BC2261A82519ULL, 0x90624AD0A93944EAULL, 
            0x08222956DC90F113ULL, 0xDEB1EF60889E23A4ULL, 0xAB9F22A9EBDB4D91ULL, 0x31E9F53F9C45C416ULL, 
            0xF52092DD09C5850CULL, 0x52777F02C7C35CE2ULL, 0xA16ABC04D917EDC5ULL, 0x60E264113576FD4EULL, 
            0xFF65CF19C8BE8C95ULL, 0xF59E2E48B5456A25ULL, 0xC92E79B796EC5C66ULL, 0xD7084E01545CBED4ULL
        },
        {
            0xC2F73D1A11A84553ULL, 0xB296E872AA566EA1ULL, 0xB512DA2E28D5EA32ULL, 0xBD9879E8ECB94FD2ULL, 
            0xCFD198A5FCD8DD28ULL, 0xD996FA076A153DA0ULL, 0x9B35284211618DF0ULL, 0x9FB3235431507424ULL, 
            0xC2D1247EB36D1180ULL, 0xE133E01EF47CD268ULL, 0x1CE7A8F7D071190AULL, 0x9672E1C18FD23C7DULL, 
            0x5A03DDEE000DFACDULL, 0xDA2B523E06D6A40DULL, 0x72EE5842D5865EA1ULL, 0x3FB75128DF8A4DA3ULL, 
            0x036F0DFE39FEBF61ULL, 0xF4657A8EE7DDD210ULL, 0x47340AFDB768B3BDULL, 0xE7E09C5A002D42B3ULL, 
            0xD05B784B1990FA0DULL, 0x5FCBD4362C75EA92ULL, 0xE660F0126092F33FULL, 0x77E429714333A952ULL, 
            0x9C75BB2BBC6FCCF7ULL, 0xC0D689B5580624BAULL, 0x81E74CAAE0FFEE86ULL, 0x5CB888A73B6FE0D3ULL, 
            0x5F567927659DC129ULL, 0x38188654DB8A3497ULL, 0x70CEBBB3DAE25B2AULL, 0x319B82CF329DB4BCULL
        }
    },
    {
        {
            0xA5991393894EB8F9ULL, 0x92C671130DDD40EEULL, 0x0E4EE92DC26827A0ULL, 0x161BB1A5B2B58924ULL, 
            0xDEFA5CB74C2C056FULL, 0x8D4530B651FA09DEULL, 0x0ADCE13B815D4ED3ULL, 0x9D43591D886BBEEFULL, 
            0x705FF2646C80E441ULL, 0x54DF8CFF925E4F99ULL, 0x5760294DCC4EF4B8ULL, 0x0F8D3F9D43272F08ULL, 
            0x981F30358316976AULL, 0x6E0EABB82AB6E039ULL, 0xD6305A412899D6CBULL, 0xDB35403BA8B7B64BULL, 
            0xBE44576040F6A207ULL, 0x1154840FF5266175ULL, 0x2AEB52216F23B887ULL, 0x0C90E54F3C0CF6FAULL, 
            0xFF310C49012260B5ULL, 0xEA1B4E62A1441A2AULL, 0xEE8197500EB05DA3ULL, 0x6758CC070294C343ULL, 
            0x2E112B4C6669CB9AULL, 0xB11B413983E61238ULL, 0x77D9A15B3153A87FULL, 0x44AE7AA5619E66D8ULL, 
            0x90091CEAA4D5590BULL, 0xCB205288576B9A02ULL, 0x2DDF1518BE080157ULL, 0x8987AE51B40B1991ULL
        },
        {
            0x3C79F3BB1076E147ULL, 0x1A16E70A22552A03ULL, 0xC7750AF2C29C5E25ULL, 0x4C5C9F89A7BB6FDCULL, 
            0x1668BD346B3CF994ULL, 0x4230EB6723E61415ULL, 0x59E41539FE66989EULL, 0x0AF44441E0B5A8F9ULL, 
            0xFF74F1955DD622EBULL, 0x2EB1E01CD49CB136ULL, 0xC07056DF35A4C856ULL, 0x78490F62833089BEULL, 
            0x550085FE3899B7E6ULL, 0x71A2E9D9263A49FDULL, 0x5CF8ED384C9FBBF9ULL, 0xD69DF0879B886E96ULL, 
            0xB1A9F6A5467F3A87ULL, 0x59ED6F0C316033F1ULL, 0x0C1471D3A5C64BFFULL, 0x6D4E96E0AAABB697ULL, 
            0xCD7791E335C89E35ULL, 0x676B14CA50500199ULL, 0x8DC7F647AE82C1F9ULL, 0x03F005C7DA2E3F4CULL, 
            0xC0EB73048667608DULL, 0x26CBAF754FB08735ULL, 0xADC3D3EED5E64E04ULL, 0xBAE61B65D5D2830CULL, 
            0x7E6310E45E688BEBULL, 0xB4CF7982EE4276A5ULL, 0x7F5698C8C001982BULL, 0xE0D9CC5388F407F0ULL
        },
        {
            0xBD4BABE292D09EAEULL, 0x2C2C2EF415A8B995ULL, 0x831A39668B2290E2ULL, 0x5C04AB82C58656CAULL, 
            0x47D1E4FB273DA66BULL, 0xD2D4BCA754373E10ULL, 0xD9771F1694842302ULL, 0xCB4205D58B1DFA7FULL, 
            0x4C2981B9164EE953ULL, 0xF4EFAB1B23EE9154ULL, 0x6281DE0B1350790AULL, 0x5E805B9FAB592A44ULL, 
            0x35F698B7200D5C24ULL, 0xE0C9E42EF56F358CULL, 0xB8BDB652C6DC0542ULL, 0x50A93D924B559A55ULL, 
            0x41EB763A1E9F4F1AULL, 0x142DEE8040EE77D5ULL, 0x6B033DE80B2C5BB6ULL, 0x1926E4742DD199B0ULL, 
            0xFA27DCE592847513ULL, 0x733D2D6CAD71D184ULL, 0xF6C32E6794EACDF7ULL, 0x98F172F1177E06C5ULL, 
            0x44BA2E0844056C80ULL, 0xA1BA19FE4CC5F26AULL, 0x3805AFC00D0DA10DULL, 0xD32218CD80B70D89ULL, 
            0x11DA4B9BA652627DULL, 0x533A5280AB522E1DULL, 0x33A12CDB139151B7ULL, 0x51EDDC38053B0D83ULL
        },
        {
            0x805321A446FB8104ULL, 0x7DDDDC0F8F4F4321ULL, 0xBDCA230CF9DE085CULL, 0x39A08081EFD05AD5ULL, 
            0xBA701BC65CD3D5D0ULL, 0xA48BBA4583A9426FULL, 0x3FFA17862C3C346EULL, 0x9907ED96A5B48B2FULL, 
            0x6D9E727C7EC7CC8BULL, 0xC8E3A01E7E59101EULL, 0xDA0A91B1BCC113CCULL, 0xD062BDB57E5CFA1EULL, 
            0xE56C79085821655AULL, 0x007D0264449415D1ULL, 0xF6BF2497C1361532ULL, 0x83E38CAFB6CC53ADULL, 
            0x4E459F5F9427DDECULL, 0x193B980F54313503ULL, 0x8B5FDEEE04BA7628ULL, 0xD943B3A77EA3F59EULL, 
            0x2C2137191F8BC0AEULL, 0x67063424FC608263ULL, 0x303CE33BAD1F0647ULL, 0x97EAB181B41E7F18ULL, 
            0x53CF46CE10B1CC17ULL, 0xAF1EF944A1F8A96BULL, 0x8C18793EB3E88D4DULL, 0x7A5EF4C49C7099D0ULL, 
            0x742BDF552C9B5E22ULL, 0x0D29F940F9797215ULL, 0x23ECC333337D4579ULL, 0x883C16FCEBDAE83EULL
        },
        {
            0x8A651A2CAAAEF5C6ULL, 0xF80F2C5E02481429ULL, 0xDA5F09456D5110FFULL, 0xD53CC7AA7F7382B2ULL, 
            0xCEFD377B39E7384AULL, 0x8FC2681E2F3EE7AAULL, 0x7B2FF36706B07244ULL, 0x9A6FA028820471D1ULL, 
            0xA06E7932B67A482BULL, 0x30E794721D56AB52ULL, 0x27AF2B211F1168D2ULL, 0x4860594A00BF8DFEULL, 
            0x464832A80AE3CF4FULL, 0xF5D8C6CDABA92E49ULL, 0xC74AD888DBA503C7ULL, 0x2B6DC95AEF5872A2ULL, 
            0x0B8C081A5B4E796CULL, 0xA8ABD9A8EC0BCE4EULL, 0xF2AAD37863753FF9ULL, 0x6862A322B9A43056ULL, 
            0xBCCACF9D74E1B9C8ULL, 0x14FF999270A1ADF6ULL, 0x25E4AF4D50B26326ULL, 0x00409ED29AE4EFB5ULL, 
            0x1234C312A7E3A338ULL, 0x60B0888F14C68B56ULL, 0x0DE358CCC1F79340ULL, 0x09F7DA5B18E3036EULL, 
            0x0C1CA185379F5445ULL, 0xEDEB856F971C0FACULL, 0xD778241565C40C58ULL, 0xE3004FAD3F7D4743ULL
        },
        {
            0x2BBD34117DC5BDDBULL, 0xB688AA131A03E804ULL, 0x866FA9BE95AF2372ULL, 0x12A42E863C57B4BEULL, 
            0x35F3F85570A890FEULL, 0x243781823F5A986DULL, 0x214AC1317D228CBBULL, 0x479D991BCAAEEC80ULL, 
            0xA7CD4D750758E7B6ULL, 0xA3982A0C627438C4ULL, 0x9200440507CFD08DULL, 0x472319EC372A59D5ULL, 
            0xAF976F08524B15ACULL, 0x317493738A9770F9ULL, 0x62D59855D679457FULL, 0x15F022910C2ACECAULL, 
            0xDE7FE1A06A4E4180ULL, 0x686BDF95C4E5AF83ULL, 0xD8CAD57E0FCCE5C2ULL, 0x43B390ECEC6DBCBBULL, 
            0x1516BCD52CD43078ULL, 0x80A18FEA401618B7ULL, 0xDB67A435D6FFA943ULL, 0x90FCD7E2124198A2ULL, 
            0x06E2F2B19CD28D49ULL, 0x863A4AE26497FEA6ULL, 0x8F396EE21F8C1320ULL, 0x8FF086D457612CF8ULL, 
            0x7E15FFC5F982E114ULL, 0x488EA4F3643EA555ULL, 0x668E82D4B4B52B6EULL, 0x032394CCE0CF5F3CULL
        }
    },
    {
        {
            0x2982A2326F924E37ULL, 0x6A418B4710536C89ULL, 0x6AF790921A468AFEULL, 0xE2252429A9087E72ULL, 
            0xCFAE29CDC4535924ULL, 0xE77D2F37F6E6D766ULL, 0x54B360A6646D9559ULL, 0x2674092490127817ULL, 
            0x02DD2C4D8B697DD6ULL, 0x3767C0382543187FULL, 0xC61BD32AA106A686ULL, 0xA5FA0460BFD2480CULL, 
            0x2BE1443E0C4C06CFULL, 0xBDFFF4A65BF231E5ULL, 0x0F6E8A2549A01644ULL, 0xFFBC4EBCDD2CC89FULL, 
            0x2985080F48AE2B96ULL, 0xD04FD34F53E6BDCAULL, 0x903189881380FC24ULL, 0x0D8FAA83F191125FULL, 
            0x29AB86940A9C8A49ULL, 0x2797FA8AD46891E5ULL, 0x0AA80177A2810033ULL, 0x1E6B156B4BAF2FB0ULL, 
            0x38A2D6DFFC3BF770ULL, 0xF9AA0EAE7E374411ULL, 0xBED12467F635EC60ULL, 0xA1CF3665F1E0EE00ULL, 
            0xDF992B01B1B3320FULL, 0x311748F92DADD832ULL, 0x486EB042B36EBF34ULL, 0xF4C51206A4BD4CAAULL
        },
        {
            0xC76F9444D150D70AULL, 0x755622AF2E5C3F4CULL, 0x0F92A057F1AD3F75ULL, 0xECBB5711ACB8ACACULL, 
            0x10D2564759E7B671ULL, 0xA23887DA16DA8A61ULL, 0xB04979A5F77210F2ULL, 0x045F0CA899F9C096ULL, 
            0xBA277C48F192FC00ULL, 0xF95317D0DF012399ULL, 0x425AB3DE0EFF2697ULL, 0xD7968E50A064459AULL, 
            0xE2CC64551006D00BULL, 0x3535D43844C63E9BULL, 0x3E46A67663F5C1D4ULL, 0xC0BE3986DC5B978BULL, 
            0x4743C98B6B91999BULL, 0xCABFF3B2F46AEEE2ULL, 0x6EA65D3453B37774ULL, 0x4955B11E8095B564ULL, 
            0x4EFCE72C3F55BDEAULL, 0xAC01605FFB673217ULL, 0x9EBCD9A752770882ULL, 0x5B8550E4A6DCC26CULL, 
            0x1C6D1E2BE8818006ULL, 0x74E16DC025F73522ULL, 0x0EF2C063661ACBD0ULL, 0x659D0A96F48C08DBULL, 
            0xDF282ECCE238A1F9ULL, 0xEEC529506633F0E5ULL, 0xC35F4B286627BC44ULL, 0xD6FEBE2267E632F7ULL
        },
        {
            0xA85B3673F8C6DE67ULL, 0x4604C4B51B225C7FULL, 0xA03DD148578E7D49ULL, 0x8223C6E98F89EB1DULL, 
            0xF1512D43B03518B7ULL, 0x642AEC5CF84E8FB4ULL, 0xF204C622F1F51485ULL, 0x9142F78F189917F3ULL, 
            0xCF822FF315F5B36DULL, 0xD7B423D679C67233ULL, 0x0FCB7477C59AB135ULL, 0x82CCBA67D7C0455AULL, 
            0x66E8839C55444B68ULL, 0x86D20EB70F31A05CULL, 0xDD78E3B03E1A1354ULL, 0x379869E06B6E08B4ULL, 
            0x4FC4A593C91F4E37ULL, 0x8447872A5FC895D0ULL, 0x30F3191D5AEA76DDULL, 0xB0454CD775382B5BULL, 
            0xAC3CF3C26878CE52ULL, 0xAAC5A8EE68CCA201ULL, 0x978B23A15EBDBB16ULL, 0x95B28513D4CAE713ULL, 
            0x6815881CD0E3C93DULL, 0xDCE2C8748031D39EULL, 0x356541F79BC8876DULL, 0x5411489D9B382AAEULL, 
            0xADEC5C25DC6EF20BULL, 0x60AD14CD5C16F107ULL, 0xB2EBAF86C6356ED6ULL, 0xCF47150F808CF48BULL
        },
        {
            0xC07AA384CC47321CULL, 0x1C7E18E6B02BA57EULL, 0x9B7785FEE9DBC18EULL, 0x0E79C5A80B18D9C6ULL, 
            0x62193E199316D885ULL, 0x3AC38953E55CAD45ULL, 0x7CF926B3ADBC6247ULL, 0xB37994D3306F1414ULL, 
            0x9BF731AB843F47D0ULL, 0x455C7E0333B9B01CULL, 0x519A2C1D4B0354EFULL, 0x2395A49AB27FF4B3ULL, 
            0x8A811F94B9EACBF0ULL, 0x910C41F66E03D778ULL, 0x2A228ECB78A367CAULL, 0xCF4DA8D602BE4CADULL, 
            0x6294C707DC4E28C3ULL, 0x5CAE6764E5ECC417ULL, 0x07435881B68604D3ULL, 0x2E722D4778C18809ULL, 
            0x9C8B82D7A60F47A3ULL, 0x5D6F8E836C5ED3B0ULL, 0xEF90F744F324B29CULL, 0x99113F0ECB5620B5ULL, 
            0xC7A87E675B7E6D4FULL, 0x82FABFFA6E25028FULL, 0x808A905EE3FF57B9ULL, 0x1EC7D6B7BE396250ULL, 
            0x676ACEFBE293504BULL, 0x529E0DB699ADB5A6ULL, 0x7A194D5DD8E4330CULL, 0x4382BA6723B70C45ULL
        },
        {
            0x6229256A02A69FB9ULL, 0xEAA9E654F03ABD49ULL, 0x3190CA8D5DB0D0E5ULL, 0x63241A4A392C7C33ULL, 
            0x43EDCDF46CE4D909ULL, 0xAEB97F9A669080DCULL, 0xF046178170AD84E5ULL, 0x403FD08E5975EF34ULL, 
            0xD3DFACEFBD96B686ULL, 0x544E02C03D71B244ULL, 0x81E9C6E7F5853E2DULL, 0x195C5C0365FBD5FEULL, 
            0x047356A3FDE20977ULL, 0x9BD367CB571B2147ULL, 0xEAA0FEE45E7B893BULL, 0x6CB57D338AAF2A72ULL, 
            0x2D27750145DA2D5DULL, 0x06124168B267B294ULL, 0x8139BEC248050532ULL, 0x97A2CD7E20BA089AULL, 
            0x6DFD63C901D16268ULL, 0x07583514B44FBE01ULL, 0xB47583DC185FD628ULL, 0xBE85E6376B724836ULL, 
            0x159F57C2A7EBD23BULL, 0x984DEAB8A820CE23ULL, 0xCCC28DF69ACEE855ULL, 0x92568E2205E45AFAULL, 
            0x46352DB1BD7C7A53ULL, 0x0FCC364D8F1E1289ULL, 0x90342E08180C1C05ULL, 0xDB17D0CD9B32E35AULL
        },
        {
            0xACA7CC8AEE2C1B4DULL, 0x5754341522FEF7A8ULL, 0xE2A93932EA7937E7ULL, 0x791B8AC5D7CBCCB0ULL, 
            0xE4A1489A2011819FULL, 0xDDC6638CB240D534ULL, 0xEB5F51D6BC63C8CAULL, 0x73D228073E304E8AULL, 
            0x3623B0C951493CE9ULL, 0xE2BE50B63B4F7805ULL, 0xDC69E582DCB9CF8DULL, 0x393E2BED0204055EULL, 
            0x710618BA0C2BAB66ULL, 0xDB91D2AF38F93EEFULL, 0x9DCE9FCF2611E2A6ULL, 0x84258615F4654B0DULL, 
            0x42093C759D1641A3ULL, 0x591675ABE9245DE7ULL, 0x12DC488F4E83918FULL, 0x61600CA3A1E2389EULL, 
            0x235D5F0AF01F30AFULL, 0xB34CC533924916CCULL, 0xC1F5B339E227A261ULL, 0xBE215CF2C894ED3BULL, 
            0x4C6EF758BC107D48ULL, 0xB4CE2F05393C734AULL, 0x69D889D0CD62DF5BULL, 0x57CB6A6F7B432533ULL, 
            0x215A045D98E571EEULL, 0x5FA4471F6B4D84CBULL, 0x47C22F31C5604A0AULL, 0x52D40C30933A0787ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kTwistConstants = {
    0xFFC4D4955A64B7E1ULL,
    0x8EDDBD62BA9D82C9ULL,
    0xF4F5FD9EE4D08F71ULL,
    0xFFC4D4955A64B7E1ULL,
    0x8EDDBD62BA9D82C9ULL,
    0xF4F5FD9EE4D08F71ULL,
    0x8E7E3F9C58356F25ULL,
    0xEE8AF8E232702683ULL,
    0x89,
    0x8C,
    0x1A,
    0xCD,
    0x37,
    0x3A,
    0xA0,
    0xB5
};

