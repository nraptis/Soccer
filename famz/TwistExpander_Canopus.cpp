#include "TwistExpander_Canopus.hpp"
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

TwistExpander_Canopus::TwistExpander_Canopus()
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

void TwistExpander_Canopus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Canopus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD3BCB29F77803F39ULL;
    std::uint64_t aIngress = 0xA664353F4EE66ECDULL;
    std::uint64_t aCarry = 0xDF9297D3F5D2E654ULL;

    std::uint64_t aWandererA = 0x98C87413AAE0BD69ULL;
    std::uint64_t aWandererB = 0xBB0766899D8008C1ULL;
    std::uint64_t aWandererC = 0x91B52824C416C77FULL;
    std::uint64_t aWandererD = 0xE0FD7B2CAF0B766EULL;
    std::uint64_t aWandererE = 0x87056A7CABE50131ULL;
    std::uint64_t aWandererF = 0xF111484ED8AD0B1FULL;
    std::uint64_t aWandererG = 0xD0E0FE037853FAB3ULL;
    std::uint64_t aWandererH = 0xC6C2FD0F829DD586ULL;
    std::uint64_t aWandererI = 0xAC7DB829E0ED294FULL;
    std::uint64_t aWandererJ = 0xA494E964E016DA3BULL;
    std::uint64_t aWandererK = 0xE77DC82A9A177B28ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xF1868A0F64CB60D9ULL;
    aIngress = 0x84921DB26EB17E51ULL;
    aCarry = 0x86E55EFF050F865BULL;
    aWandererA = 0x94A9B086C5786B27ULL;
    aWandererB = 0xF7A20C01C55F19B7ULL;
    aWandererC = 0xBC1C0BF37245F327ULL;
    aWandererD = 0xFDD9791940246C17ULL;
    aWandererE = 0xABC26D6C758E2BCFULL;
    aWandererF = 0xD7982CC457CDE9B6ULL;
    aWandererG = 0xD77D59E559350691ULL;
    aWandererH = 0xE8616EC4DE64B03DULL;
    aWandererI = 0xA2D3B3BFB6CB90FCULL;
    aWandererJ = 0xCCD14DCFB1E87934ULL;
    aWandererK = 0x8CBF94D5B14C8D99ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x89A0EAB48C281C7BULL;
    aIngress = 0xB42E92D24D517963ULL;
    aCarry = 0x83266DE7CE0C34AAULL;
    aWandererA = 0xB59D88CA7FD3EE30ULL;
    aWandererB = 0xCFA4FC63C4F84F3BULL;
    aWandererC = 0x9F1771D085BD010DULL;
    aWandererD = 0x881A01123876E7B3ULL;
    aWandererE = 0x9F1AFC38BB4A0CCAULL;
    aWandererF = 0xE1E5C5CCD79D9E9DULL;
    aWandererG = 0x9777D00385683638ULL;
    aWandererH = 0xA4BFFAF57ADE4248ULL;
    aWandererI = 0xBD81AFB324923F2FULL;
    aWandererJ = 0xC6E8695DB61FEA1DULL;
    aWandererK = 0xB6FF6826E2B4C61CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xFF73A95B4F646518ULL;
    aIngress = 0xFD03A2BABE4326D5ULL;
    aCarry = 0x8644DBD0D09D91D2ULL;
    aWandererA = 0x81121FAE8481086EULL;
    aWandererB = 0xF8E61E849DF7591FULL;
    aWandererC = 0x8D1640F10A454943ULL;
    aWandererD = 0x98D5942156FED3D5ULL;
    aWandererE = 0x92BFCD2F391782B3ULL;
    aWandererF = 0xB5E9759DC5C8C2F6ULL;
    aWandererG = 0xABCEBC03900E2B43ULL;
    aWandererH = 0x8851AC2F8C301424ULL;
    aWandererI = 0x82BD08D83A1C4E97ULL;
    aWandererJ = 0xDCDA5C6787FBA4D3ULL;
    aWandererK = 0xF5149F3B98656620ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF1E1A0563784D25DULL;
    aIngress = 0xC4058E79E18A9143ULL;
    aCarry = 0xA1EE8B022BF7950BULL;
    aWandererA = 0x96D5C85B252CD78FULL;
    aWandererB = 0x9C805D4AB528B64CULL;
    aWandererC = 0xAC9C91093D46D9B1ULL;
    aWandererD = 0xAE31E14A5F550AEEULL;
    aWandererE = 0xB9428886EC930261ULL;
    aWandererF = 0xAE4C6EB8F95C9613ULL;
    aWandererG = 0xE8821E9440AEA578ULL;
    aWandererH = 0xCD9688EBF135D600ULL;
    aWandererI = 0x966215AA34F0FAC3ULL;
    aWandererJ = 0x8383319327282929ULL;
    aWandererK = 0x8BFF74680BCF3633ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xF4D1C216AC442E13ULL;
    aIngress = 0xAD541038EC584C99ULL;
    aCarry = 0x9F5D61BAFE7A8206ULL;
    aWandererA = 0xE55B93349A307C4BULL;
    aWandererB = 0xF83EFC73CE333095ULL;
    aWandererC = 0xDED394637023848DULL;
    aWandererD = 0x9CE38980D6F32C44ULL;
    aWandererE = 0xDC1A509B52229ED2ULL;
    aWandererF = 0xD383C1EA4F96998EULL;
    aWandererG = 0xF4A3A85212F29973ULL;
    aWandererH = 0x9D0E58657376D4C3ULL;
    aWandererI = 0xA27A78702DCAA863ULL;
    aWandererJ = 0xA79BAD589CB45D57ULL;
    aWandererK = 0x81DA3C7061558A1FULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xACBAAC530799C873ULL;
    aIngress = 0xF794D22FE4B26D5AULL;
    aCarry = 0xDE2BF60E3E307657ULL;
    aWandererA = 0xA3B2B5AF50932034ULL;
    aWandererB = 0xAAEBA0E30ADDAB99ULL;
    aWandererC = 0xC89AE588A3E2D053ULL;
    aWandererD = 0xEA33E1623EDE494FULL;
    aWandererE = 0xC20563F8951AECF4ULL;
    aWandererF = 0xA4524F6885BD2332ULL;
    aWandererG = 0xD93535E483103C5DULL;
    aWandererH = 0xF8FF9A29A064C8CEULL;
    aWandererI = 0x8FA5C2952EBCE792ULL;
    aWandererJ = 0xB91E728D98B2D9FDULL;
    aWandererK = 0xE6E1965FC1E7A774ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA7E541BE3FC77475ULL;
    aIngress = 0xA91B58F8AD99E2B0ULL;
    aCarry = 0xF8FC53E21098C486ULL;
    aWandererA = 0x9C60F0D12F6852AAULL;
    aWandererB = 0xA1AE226EAB9351B0ULL;
    aWandererC = 0xB2C6E1538628D7FFULL;
    aWandererD = 0x94338482FA85A559ULL;
    aWandererE = 0xF8B93BDDA4D12EB1ULL;
    aWandererF = 0x8DDE15EAEED07521ULL;
    aWandererG = 0xE17705FA7A979F33ULL;
    aWandererH = 0x8848DBF44F365ECDULL;
    aWandererI = 0xAACC5302BA8A2362ULL;
    aWandererJ = 0xFDB20D560AD67C28ULL;
    aWandererK = 0xC0F5486C42D2EA29ULL;
    //
    TwistExpander_Canopus_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Canopus_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Canopus_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Canopus_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Canopus_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::KEY_B_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Canopus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB6C76549D7F554A2ULL; std::uint64_t aIngress = 0x9ECD1CD71AE58287ULL; std::uint64_t aCarry = 0xB1A8A3ABA9308A81ULL;

    std::uint64_t aWandererA = 0xE83BEE793C3D793AULL; std::uint64_t aWandererB = 0xF5BC4CF332DC59C8ULL; std::uint64_t aWandererC = 0xEDAB4DFBD7B2AE46ULL; std::uint64_t aWandererD = 0xEBED7448A5702745ULL;
    std::uint64_t aWandererE = 0xA5CEA0818E10427DULL; std::uint64_t aWandererF = 0xC7E4391DC6B12B10ULL; std::uint64_t aWandererG = 0x8CA1F5C831351BBDULL; std::uint64_t aWandererH = 0xEF908F941ECFD849ULL;
    std::uint64_t aWandererI = 0xA9280A56C15A4EB0ULL; std::uint64_t aWandererJ = 0x81EC742BA99ACA16ULL; std::uint64_t aWandererK = 0x94C61093635AA6A2ULL;

    // [twist]
        aPrevious = 0x8F0341067F6E38D1ULL;
        aCarry = 0xAEDA5142DFF5AFB9ULL;
        aWandererA = 0xC35EF79C701CF069ULL;
        aWandererB = 0x8668A6A93A74512BULL;
        aWandererC = 0x842783A4EE573E04ULL;
        aWandererD = 0xB3CC50760BF7B26DULL;
        aWandererE = 0xE13F8325D1C2175CULL;
        aWandererF = 0xF6B03A4A5BBF0DF9ULL;
        aWandererG = 0xBF4D910A3C181DF3ULL;
        aWandererH = 0xA233D24C6B5ECC85ULL;
        aWandererI = 0xDA9BF7214FB0558EULL;
        aWandererJ = 0xCB8D6A54F02C359FULL;
        aWandererK = 0xE4AD752282283901ULL;
    TwistExpander_Canopus_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Canopus_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Canopus_Arx::TWIST_H(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistSquash::SquashB(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Canopus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Canopus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Canopus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 14 of 33
    // Exploration cases: 0
    // Structural maximin 526 / 674; family total 6935
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
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1735U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 14 of 33
    // Exploration cases: 0
    // Structural maximin 525 / 674; family total 6986
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 970U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Canopus::kKeyRotateASalts = {
    {
        {
            0xEBB95B35216EAAA7ULL, 0x6ABF6EB08B80493EULL, 0x86DB5425206D261BULL, 0x48820E7B34869799ULL, 
            0x685566DD9717A7D0ULL, 0x82796E539E57D4A9ULL, 0x4CF7D77DE997D606ULL, 0xF5739C28ED3A3A77ULL, 
            0x91CD980B35E76010ULL, 0x8161B93519EC31E9ULL, 0x372FD7B5B0975C63ULL, 0x3FA1C40717110AE8ULL, 
            0x96CCA369E459A860ULL, 0xB8DB980ADCBDFE93ULL, 0x8BFA3B08CB6B50CBULL, 0x24C93E44A2E6A36DULL, 
            0x4068FDEAFF8A000AULL, 0x4F9A2DA81D7D128EULL, 0x949947832ED6644DULL, 0x46351DD49D4D3280ULL, 
            0x5BD9091D67920BB1ULL, 0x557D9704AB67430DULL, 0x0C25110EE25EAB4FULL, 0x2ABC062C227E22AEULL, 
            0xBAEB79C893FD2471ULL, 0x55275322B063F5ACULL, 0xBBE064D88D5AC7EFULL, 0xA9AF3B8A1CFC54EBULL, 
            0x7D25B619C83B637CULL, 0x3AF11F1CBF9F024CULL, 0x97A35EAEFC0438A7ULL, 0x39E837FC3CD4CF0EULL
        },
        {
            0xEE4310857BF27C9AULL, 0x161A60DA4C87CFB6ULL, 0xCB647C2536EFAB60ULL, 0x7C2EF0E39C670F25ULL, 
            0xD880162834FE204BULL, 0xF5252365F94BB4AAULL, 0x2D6604383B5B68E9ULL, 0xD0CD9D83A9C01C4DULL, 
            0x892F4F992ED3CF2EULL, 0x5FF91B0B6CCCABA0ULL, 0xDE51F8D26B7E21AEULL, 0x7CCF10E348F70A05ULL, 
            0x15C5D10B29F2413DULL, 0x9E00ED71BC30F364ULL, 0x1AAC0BEA751F6A48ULL, 0xB6D12C2A4C4FD00CULL, 
            0x1485CFCA205349A6ULL, 0xD87AC2DCEBDCB68CULL, 0x33E60A3DAB59928EULL, 0x5A7E7CFCF39ACB45ULL, 
            0xBAEF68AEDD2D3D65ULL, 0x0C86F35E5E45C7E7ULL, 0x69ADF9E0FF49D22EULL, 0x448550712507B9FBULL, 
            0xA0DC39D5904B4149ULL, 0xC0D38A6886174C9DULL, 0x7BC166E86A1C6D50ULL, 0xCDA1E2C566F23898ULL, 
            0x8F668924A8394DFFULL, 0x03ACD565C8C3974FULL, 0xE07FAE179DF37812ULL, 0x7CB5532082276BECULL
        },
        {
            0xA1E183E9585EB8B9ULL, 0x28F5A64E710EA6EDULL, 0x9B558643BE711331ULL, 0xBAED55B196FDBE6DULL, 
            0x3F85B9880D4E9F4AULL, 0x8D299E0C9509E9B7ULL, 0xE081B2286ED0CCA7ULL, 0xE1B3D589E85DD895ULL, 
            0xF799E833674C3827ULL, 0x748CEFD14D7815B9ULL, 0x26F39B904B85F58EULL, 0x0E8A252E0EC5B8A2ULL, 
            0xA8E1D04F412C8329ULL, 0x1D29154476EDE5F1ULL, 0xB6DD3FA63350A488ULL, 0xED2065467A0EC5B8ULL, 
            0x0F0475E503D19C54ULL, 0x97887A4C62B83610ULL, 0x9902FC6296CA0B4EULL, 0x72B020A10C3443D4ULL, 
            0x66859D9B37DD4EFFULL, 0xDFC5382E768C251BULL, 0xB66D2F2F70BA717BULL, 0xE200502F9121E705ULL, 
            0x751E72A3F22F8D59ULL, 0x1BD2F4A34B062289ULL, 0xBC78E4AA61B8A03DULL, 0x021CF3D4EC6D027FULL, 
            0x15926D7F59B19AA6ULL, 0x29DEE5ACF4A39AC2ULL, 0x4D8A22AF252DEA2BULL, 0x07F7CC758CCA4EECULL
        },
        {
            0x023FDD4252B393E1ULL, 0x1217CA0EB3C0286BULL, 0x5CD6C5F14E2F3C40ULL, 0x57078FA898D884FDULL, 
            0x91C2D24813A61CE8ULL, 0x4F1E1A9C017A4953ULL, 0x1D3A81B3590C9884ULL, 0x5F4859653308CFB4ULL, 
            0xD0E0ED55F0021E8EULL, 0x42AFD1108F8AD02DULL, 0x3828DA3E6DD44081ULL, 0x86952ED576864688ULL, 
            0xEC9D7B869729B209ULL, 0x4F71E66D5588CAD5ULL, 0xBF0B270D5ECD4BE7ULL, 0xE67975C48B97D9C8ULL, 
            0x174657C015C544A6ULL, 0x2DEC05732F8AF477ULL, 0xA704428E59D9AE3AULL, 0x59A0F9A28DC8C969ULL, 
            0x9D9370E27833A556ULL, 0xC9444DDA81DE511BULL, 0x859672729E8E4DE1ULL, 0xFF6975D84043C814ULL, 
            0xE67E2338309EB62FULL, 0x18B6B2C12A930B59ULL, 0xF30BAE74003F86DAULL, 0xD1328264C7112FD0ULL, 
            0xB77E1280819EF642ULL, 0x313AC7230A91D2B4ULL, 0x5D3273708E52D201ULL, 0xA2E5A09AD2DB4730ULL
        },
        {
            0xF23F7347765B36B8ULL, 0x9A20920BE2A970D0ULL, 0xE961641610802633ULL, 0x65E522EB38147003ULL, 
            0x5CA0844C54D2D967ULL, 0xB55E588240356B96ULL, 0x50583BFB52AC6856ULL, 0xA359909CF4CD93B1ULL, 
            0x4C11CB483DFE3710ULL, 0x5EAD1880DE5DA464ULL, 0xB5F107482F4A2DD1ULL, 0x7EF7178D7F09DD42ULL, 
            0xC9EC1D8CABFDF22EULL, 0xC21AC6C99E6CF106ULL, 0x85F5364EE268A6F5ULL, 0xEAECB66401DEA8DDULL, 
            0x467ADD09A3716304ULL, 0xE39DE50CBF3B2D3DULL, 0x1E370122856A9A6FULL, 0xC511C248C9AD989BULL, 
            0x4BB3BE7858267B4AULL, 0xCC8D52783D4D9A93ULL, 0xB8340038F52FBBD4ULL, 0xB578C2EB75E9C238ULL, 
            0x22138BFC5B2B90CBULL, 0x170967C0E7CDF79FULL, 0xB679DA3FE8867149ULL, 0xDCBBC863E8B802D9ULL, 
            0xB9DACE32A48BC5FDULL, 0x7D369B2B5EA04C6DULL, 0xA777313074D4C60CULL, 0xA5BB40DF7E5CDF1AULL
        },
        {
            0x2BF9EC2D8BFA9FF6ULL, 0xD5BB45A84F65518FULL, 0xEFE8E7FF86A8BA07ULL, 0xDBB0BCF5D93D7BC9ULL, 
            0x3784B11DED992C59ULL, 0x232BC9B82DE6238FULL, 0x45A5E09E15C3A9D1ULL, 0x4573769AE42E4A1FULL, 
            0x83CA47DDDF6F7955ULL, 0xDCC0513A8EBB9D69ULL, 0xF026EB1E8745F52AULL, 0xD31D0EE8B7A39639ULL, 
            0x80F08F03F1759084ULL, 0x99FFB2E473A70300ULL, 0xAE1F8F567948D6B1ULL, 0x3932B5F46CAD1692ULL, 
            0xF0DF276905A6A119ULL, 0x74D1E3E4A425AE73ULL, 0x7A13CB23CBE926E9ULL, 0xB7FFF22A74348FBFULL, 
            0x1FDEAA93B5B7AE80ULL, 0x7F38524814AB6989ULL, 0xBF58D67F7BF18707ULL, 0xAE5374DEFDA1253EULL, 
            0x16E5A0E0AF720A73ULL, 0xE2867392393F46A2ULL, 0x978C3B3C75EAA4FAULL, 0x0DE78707C224BAEEULL, 
            0x8BC4D35FC4F09BD8ULL, 0x11CB9AA81377C9A5ULL, 0x172AC36C613B010FULL, 0x10EDA8F546CE744BULL
        }
    },
    {
        {
            0x3FD2908C48EE65D6ULL, 0x4C582C0492830473ULL, 0x4AE09B25BB368AA7ULL, 0xA35E14E18009E013ULL, 
            0xDA70F47742CCB03DULL, 0x729630CF3BBEDF55ULL, 0x607B89D690C97D40ULL, 0xC75B2BCCEED62568ULL, 
            0x4268565CDF605976ULL, 0xAE7D853CE063FEF9ULL, 0x262B0860C7E77F38ULL, 0x392A2678C2797DA7ULL, 
            0x39CA35E355081F47ULL, 0x890A6D28CADD4C9DULL, 0x402E0E629EA79CCEULL, 0xA0DF021829ED4B3CULL, 
            0x8655120C0C15A5EEULL, 0xDA4CFEC63E9C9D02ULL, 0xBCE8A152906BCA12ULL, 0xB3AC4840DF911EF2ULL, 
            0x8FB2140634A63AF6ULL, 0x1B955732CA8D6DC3ULL, 0xE2D729880F9C0C76ULL, 0xF5184D2D2739398BULL, 
            0x2CBAFA06E5C8DBD9ULL, 0xB2B0CE5335E1E2DDULL, 0x90A8600E446A69FEULL, 0x7BD9AC19A6752EDFULL, 
            0xA04A3710594B08B3ULL, 0x4D30377A742408F9ULL, 0x892E5E22E9223E64ULL, 0xE456D7377625276AULL
        },
        {
            0xFD1654811D01C79EULL, 0x6D407CCE9F62C94BULL, 0x972879CBC048C02BULL, 0x8C09EFE1815477E3ULL, 
            0x9A3F3FDB589B2B1BULL, 0x26861F00A2C99236ULL, 0x28B3DE44EAB19E5CULL, 0x2C1AA0965CBB8DC2ULL, 
            0x1EDD54E2A53F77ABULL, 0xF3CC40D7B44F4AFBULL, 0x290DF4D09AEF42E1ULL, 0x93CA66E69A0E9479ULL, 
            0x3577C4E250AD01F8ULL, 0xE61FD6B7A65EDF5FULL, 0xBD5734C4CE0CC6F7ULL, 0xF37B37D8582A0573ULL, 
            0x971FEB1AF4526461ULL, 0xB4D8317E6280FA01ULL, 0xCD20495ECCA77A8AULL, 0x160073B7D5CEA011ULL, 
            0x163C65DB153029DEULL, 0x83CAC5C8268707C9ULL, 0x78A657AC85C8E6C4ULL, 0x14AAEC93E45AE65AULL, 
            0x3162A9EF6DBF326FULL, 0xD5DA8850A56B7400ULL, 0xF73C8567DDAA5839ULL, 0xFC9D596B8C06E566ULL, 
            0xA030479126365CBBULL, 0xF0BCECE9D62BDDE6ULL, 0xE21598A1635158EAULL, 0x1CEC8825DDE0FA69ULL
        },
        {
            0x528A9A46960AADD8ULL, 0xCA9AFFC93A2AAA41ULL, 0x4EB1833021078A5DULL, 0x07FD1F8BAA952EACULL, 
            0xCD20874078A8A7BBULL, 0xA493553E2EF37382ULL, 0x6131302809D7481AULL, 0x0DEC2EEE0B84924FULL, 
            0x0C887D77880DC552ULL, 0x908C1B03A8605CEEULL, 0xECCA0A7F5ECC9E6FULL, 0x3C6B60B47CC9D575ULL, 
            0x018989B1B1EAE3A1ULL, 0xACC922735B855DC7ULL, 0x06F8F06F09867F04ULL, 0xEA22885F51B87B7BULL, 
            0x6C8A8327D06E53FEULL, 0xFA62CEFED9A6DF71ULL, 0x6A50C55AF830C91FULL, 0xAF9EF8D6F8614039ULL, 
            0x488CCFE2FA36947AULL, 0x18F7F3EFEB4F4C73ULL, 0xF62A551022A05558ULL, 0x5144CE26D0CFA35DULL, 
            0xCE4E988CD639190FULL, 0x5F6AB62A11C5D6AEULL, 0x662C71E2A4954875ULL, 0x08F26A9083C6BC50ULL, 
            0x91ED80F1D0A8651FULL, 0x5724DE3A4DA645D6ULL, 0x24A815D4FAC936D8ULL, 0x07A84417FE5118C8ULL
        },
        {
            0xE2F34FEC5BDB70D2ULL, 0x84B0E607A0216173ULL, 0x424330100A242A3EULL, 0xB0152A398FE29276ULL, 
            0x543D815BBB378573ULL, 0x766AD40A86A375A0ULL, 0xAAA1E11DD352EDCBULL, 0x5B0D55A134FA4153ULL, 
            0xBEC827F371153792ULL, 0xF92D98DF5716E4E2ULL, 0x6712A9AD14DE3E01ULL, 0xE4ABA17871EB4BBAULL, 
            0xE7722400D8B48523ULL, 0x3AE5BBF8BE4136B7ULL, 0xE4F4154584069EE2ULL, 0x485AA36E4DE2FA80ULL, 
            0xEC8993CEE9D43A43ULL, 0xDEA2E59AB50609A2ULL, 0xC361C552D51E4C2BULL, 0x50B7A3C33C8685B1ULL, 
            0x82BADC1B30B4D848ULL, 0x50D3213F39A1B4D3ULL, 0x1DBA3D1DFDF9C6DCULL, 0x8454DA01F8B72C65ULL, 
            0x60EA864656C9ACE5ULL, 0x730015AC50FC851FULL, 0x0FBA06B85D329C20ULL, 0xE58ED36A2098ED19ULL, 
            0x25449858A66B7156ULL, 0xB23746D05E928BFCULL, 0xA197D477C13657CBULL, 0xF217F85DC3A782B1ULL
        },
        {
            0x4EAD6A32A954B7DEULL, 0xF75B33E829A01C73ULL, 0x2A8C8CCB2318E011ULL, 0x6083501CA64F01C4ULL, 
            0x377368D4788FE9A4ULL, 0xE53348D2A3E7AF7FULL, 0xFB2B5915BC0838D9ULL, 0xEC833816E840F8ADULL, 
            0xA186AACDD0696745ULL, 0x8D93EFF2FC706990ULL, 0x675B59F50D752D41ULL, 0xD89732476E98D9F0ULL, 
            0x8E17B8E79C84ADD5ULL, 0xBF8748494C533A00ULL, 0x44E0E7ADC67BBE36ULL, 0xD493E15ECCF5119AULL, 
            0x6D555402A78E0C59ULL, 0xEA63B1F04149063EULL, 0x7724530BF27184AAULL, 0xB949BC40A9CAF3BAULL, 
            0xF8F39873EBE83097ULL, 0x6A66CCC8ACC317BEULL, 0xEB5F4D65E334C50DULL, 0xBE09C9F18373A8A8ULL, 
            0xEE5D4F84DE6118CDULL, 0x2296C8FA0A6C4F19ULL, 0x88D195FDB2224895ULL, 0x87A0658464C22115ULL, 
            0x046410364ECDC03EULL, 0xC82222DD887A5848ULL, 0x084DF4AEC2538734ULL, 0x92D2BE6E7C098261ULL
        },
        {
            0x6BC559791F831F62ULL, 0xFF7DCDF4370EFBB8ULL, 0xF1C3D93C68ACA2E3ULL, 0xAB029D1BDC6BB480ULL, 
            0x5BB3874EF444DD90ULL, 0x528F47E8CA42F790ULL, 0xFB9691C6C3B357E0ULL, 0x110BF853D807BEDDULL, 
            0x36EBF41060F69EEEULL, 0x6AE3EC0525E9F961ULL, 0x410FF8C55907D193ULL, 0x269BB88C8E1B531FULL, 
            0xAE018E30FC2FF8E2ULL, 0xAC6C58CB38FDB8C9ULL, 0x9AE4D8C97EB9A1EDULL, 0x51249E45BA20385EULL, 
            0x1F6FCCA959F6ACC0ULL, 0x1529EB2691CE5D07ULL, 0x9F4BB5C2800A5CECULL, 0xA85DD86AE95FC040ULL, 
            0xFBD0243724F23D11ULL, 0xB55008BD46962E45ULL, 0xF7FB4AE27B3D9610ULL, 0x601D845ECC22857FULL, 
            0xCA759BECA396AC0AULL, 0x7947D6D68E8E0F4CULL, 0xEA15E861F1FAD77BULL, 0xBD47FAB68BB648B0ULL, 
            0x129CBE5FED7478E3ULL, 0x770C228681026CFEULL, 0x6698B9C1F139256DULL, 0xACB1CE447A9860ECULL
        }
    },
    {
        {
            0x7CBA9F959CC50F2EULL, 0x4438B1288AE10EABULL, 0x685126D9AF9B0D63ULL, 0xAEDBA14D552C902FULL, 
            0x6E463E431CD7F5B7ULL, 0xF1C0D49C5C19328CULL, 0x49A0163FE3E85913ULL, 0x1539476C085A8A5DULL, 
            0xAFBEE2CEB947510AULL, 0x67808E5F092E652CULL, 0xEC75FACDC8A1AEF0ULL, 0xC17B9C9E0ADC2337ULL, 
            0xD01222D1217F1039ULL, 0x9640C1826DA13EA1ULL, 0xDEF1A188EDFF52A6ULL, 0xFD0D1D61E9DA8618ULL, 
            0x925EC2CC1DC819A8ULL, 0xF460AEC2FB1F5689ULL, 0x26F95F7035CCB37CULL, 0xAF5F64C739B11161ULL, 
            0x64A79DF2922D5DB3ULL, 0xC217157C8A838631ULL, 0x33F20B4848ECF8E6ULL, 0x313B24E8CAF551A3ULL, 
            0x8F211D12C32258BFULL, 0x3BE968A205D0ACE4ULL, 0x7B717D8F5BDA53FDULL, 0xDCA06D795FABBC9EULL, 
            0xA5A613DCD6E9A2ACULL, 0x8EF2A5CA54A4D22FULL, 0x69F2468DB2C57A5CULL, 0xF54125F5FA5921A5ULL
        },
        {
            0xBDAF6216D7AA5F2DULL, 0xFF169079B9085071ULL, 0x544E7EF113037FB0ULL, 0x0915C2EBA0C32A48ULL, 
            0x4CB0E02DC6218F43ULL, 0x5668FB084153AF62ULL, 0xDD43F550CCFB075AULL, 0x8472F8001C6449D3ULL, 
            0xF555A3DFEC9F3A5AULL, 0xC9D542976EAFB610ULL, 0xA68F6E9D152F16FCULL, 0xF6A7EF323BA38EF2ULL, 
            0xCFD5CEC9808C7F22ULL, 0xD892B32EC35C4348ULL, 0xA06F2D013FBF1ABEULL, 0x930D94351FBD61FDULL, 
            0x42D235DD87DE801AULL, 0xCE9D04AADD28ED6BULL, 0x5EF89DAFD2AD7BC5ULL, 0x9CEF3D2C34E1DBE7ULL, 
            0xC4BB5D0A0F340A89ULL, 0x40C30079D4018C74ULL, 0xC34287ADB7E892A8ULL, 0xED2F40A1BE7C8DBFULL, 
            0x72597CC36DE58DC6ULL, 0xEF302AEE21F09C9CULL, 0x285A5D0D1631BA23ULL, 0x69FDF2FFF6BA7CD7ULL, 
            0x14779C6FFA8135CDULL, 0x8227751A241932F0ULL, 0x136635AB7650A3BAULL, 0xF979DFC755C24579ULL
        },
        {
            0x163AE3BB7906C21CULL, 0xCE24587FF278F2F7ULL, 0xD1AF91C07FFAA562ULL, 0x472C9E74EE6E29E0ULL, 
            0xE84020C9488A29BFULL, 0x016C9CD78EA8CED2ULL, 0xD31EE335D85D4196ULL, 0x5D9A1C8BA2C8020EULL, 
            0x9E466F56056E28CAULL, 0x7E9D83174FE730E8ULL, 0x7DF8CB9F6F64FB47ULL, 0x3489686A9A599E61ULL, 
            0x695580A294365D46ULL, 0xE5164BD9EFA490FEULL, 0x640FA4F3B9393285ULL, 0xC5F3396F2F4DC153ULL, 
            0x675E90D0DB001F37ULL, 0x31080255AAFA8C9CULL, 0x820A0DEFE0C7B987ULL, 0x822AC033A35C821DULL, 
            0x8D867FADAE925EBDULL, 0x04B79F566B993B6CULL, 0xCD336AB6985C3E94ULL, 0x3AA8BDE10A0EC59AULL, 
            0xC56F53EB5B74AEB9ULL, 0x402634E443EFF542ULL, 0x3984AB5B67DF8987ULL, 0x2F64871C11CEE15FULL, 
            0xE5BE76857AF1CDEBULL, 0xF60971B9B9ABE7CDULL, 0x50F892A0E3A15881ULL, 0xB539EAB961B3F649ULL
        },
        {
            0xD4C42B6F6C9E1B4DULL, 0x9DEC36333F88EFEBULL, 0xE4040A1FEB5198EFULL, 0xD3E18ECB5929262FULL, 
            0xEE4AC229409995EBULL, 0x967EBA25FF275A63ULL, 0x84C803AEC2EE5B36ULL, 0x0CBB6762CF8E94F8ULL, 
            0x0C712E11EB870E61ULL, 0x848807BC9F680D05ULL, 0x7459D4CAB6A9D9DDULL, 0x2C0274FE8263C71DULL, 
            0x28C2F3DF9BC5CB93ULL, 0x6DAE775F9E85D212ULL, 0x429424B44BB748DAULL, 0xF658FECB6C6C410CULL, 
            0x4AE6BD39B85D7D20ULL, 0x3F83D094D402ED10ULL, 0x76BE450271C5FDDEULL, 0xD2F6429BC4FC552BULL, 
            0x66C4DE3A78C432FDULL, 0x20EFB0315F593EF5ULL, 0x25127CF7940424E1ULL, 0x1514982AF595106BULL, 
            0xA8A2FE676953D2E0ULL, 0xB17B3E44D1AA97DFULL, 0x40A047A75A9CAF65ULL, 0x63BF7887247D81AEULL, 
            0x73586B54B5FEE0B0ULL, 0x7D656839F463389FULL, 0x185A92F88618B702ULL, 0x250DBE4AFBECBE26ULL
        },
        {
            0x0BBE39274D9BAB45ULL, 0xD6862B9947165CB4ULL, 0x50F0752B3AF8AA85ULL, 0x2FFA25ECEAA4178EULL, 
            0x6653844BE4BC18BAULL, 0x57456A0CBD5309D2ULL, 0xD2FFA2CC2E503612ULL, 0x3D0622AAD2EE3B39ULL, 
            0x3A2AE3C202C4290EULL, 0x40B0D417E6018B7AULL, 0x944253C3DF7AD949ULL, 0xFABAAD3FCD75532EULL, 
            0x2BAA01388C6FC15FULL, 0xC7C81CF7C076F6A1ULL, 0x6B2153FC92C381B0ULL, 0x4B7828AD34753F96ULL, 
            0x87E46E47E9D5B57EULL, 0x76F4A7AE4820D847ULL, 0xB8DA2FD3C44A6910ULL, 0x4CAD54AB9EA0DB09ULL, 
            0x051315548A447BB4ULL, 0x722159B2C250D237ULL, 0x7D5E41E39653F416ULL, 0x6B63C4B2C1E31DB1ULL, 
            0xEBB13803B8B4237AULL, 0xAE21DFF41CBDBAD9ULL, 0x12A52E55F2C574A6ULL, 0x815571D45B7E7BB0ULL, 
            0xCEDC4EFE737488E5ULL, 0x24BEB071B8A5415FULL, 0x2EEB1AE5FF7AAFE4ULL, 0x33F63E2AD38298EAULL
        },
        {
            0x5BFDED1D983D4132ULL, 0xFD38B546D208E0DCULL, 0x883013219D0CC787ULL, 0x537F4E8A86CAE077ULL, 
            0x488DC28141FFCE31ULL, 0xBBA49042979B9E40ULL, 0xEE202A63713797A7ULL, 0xCB85A80E118E3987ULL, 
            0x85DC9602601A0BBAULL, 0x5FD64C09C3A71F01ULL, 0xB14396237D45D411ULL, 0x72990C0E14DBB916ULL, 
            0x69631182078E81BEULL, 0x0C0EA7364C9DAC05ULL, 0x246F8B2A95032191ULL, 0xFDF4BFCC24207605ULL, 
            0xF649D5AC8A4F4659ULL, 0xB895D10E3A20B2ADULL, 0xAE80D505988316C0ULL, 0xC3F40FAC5C6AFB0BULL, 
            0xFC36854AB51E4AC7ULL, 0xA755FC4EBB8D1138ULL, 0x1C30BBC021400EA2ULL, 0x1E9EDE115CFCEBD9ULL, 
            0xF40BCF1B0FE1764BULL, 0x819D5BDD3FCE2B1EULL, 0x0AAF5018BA13E635ULL, 0x58443720CB2B81B2ULL, 
            0x407F366381D45380ULL, 0xF0752362B2EC90FFULL, 0xE48802BAED1BC606ULL, 0x3EE629B6B25AADD6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeyRotateAConstants = {
    0xE721AA137E69B3B7ULL,
    0x22393FF962F331E6ULL,
    0x97E391552E688C66ULL,
    0xE721AA137E69B3B7ULL,
    0x22393FF962F331E6ULL,
    0x97E391552E688C66ULL,
    0x5B85C72D3487FB36ULL,
    0xD63C786D13E3922BULL,
    0x06,
    0xBE,
    0x9E,
    0xEA,
    0xE6,
    0xEF,
    0xBF,
    0x34
};

const TwistDomainSaltSet TwistExpander_Canopus::kKeyRotateBSalts = {
    {
        {
            0x7D4C837060C37277ULL, 0xC59D78132504DCDCULL, 0x8D1DDB74D23C82B4ULL, 0x4440CDBFBE5DFBB0ULL, 
            0x256442440601FE3DULL, 0x29495151C6E40E3FULL, 0x8D449BF40376E385ULL, 0x5ED48ECFAF8E5D77ULL, 
            0x874C9410ECAB6C77ULL, 0xB0C0D5C8B679DFF7ULL, 0x02BCC67A577A5133ULL, 0x4382DEDC31C288A2ULL, 
            0x2A9C0B994C4E8929ULL, 0xDB924D956F0D7559ULL, 0xCC913C2B5CB85DF7ULL, 0x15604EB9F7D29705ULL, 
            0xAD204CA43378B2D6ULL, 0x1384629B8C4769DCULL, 0x304E237A125284F1ULL, 0xD5338B119FDDD07DULL, 
            0x6AF4D7CE9A489837ULL, 0xBD9A52E1F310224BULL, 0x5884C5AADC23C204ULL, 0x4CBB06F42532DC79ULL, 
            0x75CAAD450E00405CULL, 0xF9EB462A865CA62BULL, 0xBA11812666FBFC33ULL, 0x76AE2C63F4DE0D97ULL, 
            0x40183318E3EC9B4FULL, 0xF5E3D1D4CF9E4BDFULL, 0xDE4DC8B556F1F947ULL, 0xC819187A91BF3C4FULL
        },
        {
            0x1EE4F65D00154659ULL, 0x06929D261D354B0DULL, 0xA454B42BF391734BULL, 0x207719EA4C4A51E8ULL, 
            0xAAF2B4AE90A2F386ULL, 0x9E2F69BA8034BE50ULL, 0x114DBCC631E6069AULL, 0x7A6FF991647541EDULL, 
            0x6000DCF7C542F752ULL, 0x961B48C9EB310A11ULL, 0x2C9493DD701C233DULL, 0xC9BBED1A8F3AAD61ULL, 
            0x7BCAEDBF1BECE98DULL, 0x626EED77BC0E40CCULL, 0x808DC55F8FF2EC0AULL, 0xD090FDDB13101763ULL, 
            0x51D5A55F0595DC5EULL, 0xF9E9266F0EC23FD5ULL, 0x7AB5E2BC56E4C885ULL, 0xA0D67A1438723CCBULL, 
            0x28B35EF02FD1A30BULL, 0x9D1D2008D8574859ULL, 0x33263CE2B36C1CACULL, 0xC814383350FEB06FULL, 
            0x76D6EA085CB6816DULL, 0xF6FE998ED209DD4CULL, 0x225649ED62EF0D22ULL, 0xA09B8F3324118B79ULL, 
            0x43803DC59709D464ULL, 0x8F48E34BBFF93964ULL, 0x20C08B6826489909ULL, 0x5B5213F59E22E7C2ULL
        },
        {
            0xCA5EB3B903E0F035ULL, 0x0477F1A7C7CB9173ULL, 0xA09CCD4134E1FE75ULL, 0x66343642002398DFULL, 
            0x8A83CBE1440DBF11ULL, 0xB0C8D9AC97C4BE30ULL, 0xC37C2DDCB3D303D4ULL, 0x2466882C34E0ABE5ULL, 
            0x9290125377EF5C14ULL, 0x3D2E31561595B53EULL, 0x1D94AFE4499D570FULL, 0x8F4DD90B6065E736ULL, 
            0xA802EE143BDA9240ULL, 0xE537E431635A0C15ULL, 0xE6A2D829FB6E33C1ULL, 0xF4C476DFDB0EDB3EULL, 
            0x21EFA3C57455459DULL, 0xDC9AE16DF345ED71ULL, 0xC81F23ECA0845047ULL, 0xFB9C6DBDE6019406ULL, 
            0xDCF384011179375DULL, 0x9EBED1B9A683D35FULL, 0x449D49934A98FA61ULL, 0x043759D77D0168D5ULL, 
            0x4C49F444A07A32A8ULL, 0x797093CE42DEB6C7ULL, 0x3D788190E87F2E5CULL, 0x5612A056806B741DULL, 
            0x72359CC3B25A8EA6ULL, 0x44A611BCD49F128BULL, 0x21186624907F2E32ULL, 0x49D783AED09B2D20ULL
        },
        {
            0x61A739346D7450E2ULL, 0xB51985F77BBB6A09ULL, 0x0FCFB565AAAE993AULL, 0xBD3C4D71144C3EA9ULL, 
            0xE8596CBB84A57132ULL, 0x49466587C17F939FULL, 0xE15FCF664B1A6471ULL, 0xA90E0BB8A43070F2ULL, 
            0x95B6ACB78347F52AULL, 0x064079EA0A01F283ULL, 0xC38BA5E73520747AULL, 0x50E0087A2614AB85ULL, 
            0x48FA06D7FBFD4CCEULL, 0x60ED07BD54A864C3ULL, 0x5F5C3265134D6115ULL, 0xCF46144E2BD3614CULL, 
            0x489F0B06FC6C95E1ULL, 0xA6AC7CD97705A713ULL, 0x597FA2B6AE7F4547ULL, 0xD4839D15E7F306EFULL, 
            0x3F11F74DF04F6681ULL, 0x44013BFD1CDEEA89ULL, 0x05317DAA44984EBDULL, 0x4298F772521D4262ULL, 
            0xEA619FA3D34A1C1AULL, 0xA4493C2E7EE394B5ULL, 0x95A52A3D6ABC0B2BULL, 0x4BF6AAE7144A72EBULL, 
            0x47F99561073712A3ULL, 0x23DA7E9C6D694853ULL, 0x06604EBAA1219BC7ULL, 0x64408E579ABA9BC4ULL
        },
        {
            0x30355406E8083A28ULL, 0x5DBF60F9BFB55BDDULL, 0x7B5E092C4D58803FULL, 0x947262846286FFB0ULL, 
            0x72BCA1616C713D5FULL, 0x17BB8E0F4F787319ULL, 0x33129AA5227B8EE9ULL, 0x12632CC027AC0C7BULL, 
            0xA14BD67D40A220E7ULL, 0xCEB83D8B64C3F233ULL, 0xE429AD1F18893B5EULL, 0x93BEBB2F5901D35EULL, 
            0x8425502B06D42E8DULL, 0x7CE2ED17869BB561ULL, 0xBA0E4163A37AC775ULL, 0x9B0EEF0E4FDB2D49ULL, 
            0x8B55B513B69E26BCULL, 0xC67F49B3E82F2F89ULL, 0x922B9547A203C98DULL, 0x643618A8B6074F6FULL, 
            0xCF5A08AE7B527744ULL, 0xB00AB166AC83B354ULL, 0x1920AA32D5CBB9BCULL, 0xE6F1567CDFBAC160ULL, 
            0xD75258BAFD5B2A1AULL, 0xD9027A00C78F7A97ULL, 0x59E44B76940C6D4FULL, 0x8B799393A2BC1B74ULL, 
            0x54A8FC28BE5C9FCBULL, 0x094BD91DDED73093ULL, 0x051B3039AA8EC913ULL, 0x4B154D9A73F27AA3ULL
        },
        {
            0x15D6F0036E683E51ULL, 0x69E2FC9A9BA5F87BULL, 0x2B0E1EEB6121C0A7ULL, 0xB4B271CF06473549ULL, 
            0x6EA5B171FB2A3A6CULL, 0xB64421FFAA357E4FULL, 0xC063E1A761EF4FEAULL, 0xCEBBB373DE3AC4A0ULL, 
            0xA4CDF9DC16627B17ULL, 0x57392C9E79CFFE44ULL, 0x12A8218E6529160DULL, 0x08E8D3A2D50976B4ULL, 
            0xD0B5F533D1637543ULL, 0xB5B1B5B894375719ULL, 0xC3DFC42AD5708808ULL, 0xEF473416784D72F1ULL, 
            0x2024396B888B7300ULL, 0x26299D7A6FAD3B30ULL, 0x0C2B558BC4DE7160ULL, 0x911C5650AC85E556ULL, 
            0xE7FAB360FD718BEBULL, 0xA49BFC927D6B6EA9ULL, 0x350087B9A6C873F4ULL, 0x9682FDF66B5F3C59ULL, 
            0x9FEFD11D6537F3DAULL, 0xB12252DB598B743CULL, 0x7EE4FF26552944BDULL, 0xEEB4C76A97852F41ULL, 
            0xA68E120FBC0744DCULL, 0xC7771973767883B6ULL, 0xB3273D532391AF0EULL, 0xBEE951B029942D33ULL
        }
    },
    {
        {
            0xF6B3B80948FB9CAAULL, 0x61C600C064000E14ULL, 0xFBB8876AB30207CEULL, 0x4F1E8F8131749222ULL, 
            0x1DB6CE1C77CBEC0EULL, 0x75BEEEF0DEB087B7ULL, 0x5350CE0CDFE8FC87ULL, 0xF99A047E2BB8EC9BULL, 
            0x0EAA9314CF145B89ULL, 0xEFAC4166EA5C32AFULL, 0x9F90BA35F3CFA752ULL, 0x1070CC27C168839DULL, 
            0x0D89362E0FD0BC24ULL, 0x36DE863248838312ULL, 0x2BF415FCE3E28D0FULL, 0xF540BFCA16FFA01CULL, 
            0x2D0A4FCF85B9FEA2ULL, 0xCC4CE158C8C27EF7ULL, 0x843514F0677F1E54ULL, 0x822DA63839750589ULL, 
            0x99999206B6D502ABULL, 0xF4828BF11B35AD52ULL, 0x166DD1549D87FA20ULL, 0x841F4622CB6F097EULL, 
            0xE9688196BE549FB4ULL, 0x8215CFE1EF749704ULL, 0x34810C6C23833C4BULL, 0x31A61894E9DDE3C1ULL, 
            0xA42B0A7003069BFFULL, 0x57343FA409660E9DULL, 0xF8E81312390CDFDBULL, 0xB0D095E9DCBC70C8ULL
        },
        {
            0xBBE9653F366ED255ULL, 0x2E214B8470C67AF7ULL, 0x4878651B934FDA1BULL, 0xB4025E0AD66F4D7BULL, 
            0x2C0429E2401CD059ULL, 0x11E577FAC561E81FULL, 0x28EAFAEF2510A649ULL, 0xABEAEC214F9AA094ULL, 
            0xE40EC3A5AEFE0EB5ULL, 0x73A1066DABF1EC46ULL, 0x598D46E0150AA54FULL, 0x576C7DFB1DB8D1C4ULL, 
            0xAC12D4428461F4AEULL, 0x65BB34528CBA25F3ULL, 0x71B4EFF1A5B9E841ULL, 0x63E391143A6E8F7CULL, 
            0xF374D96F0D38C413ULL, 0x0758B3301A36891EULL, 0xB28BD9E7074E4435ULL, 0x3296EA10CE6079E7ULL, 
            0x059D0D6C915EDE7BULL, 0xBA6EB7C03D3E2805ULL, 0xEC16117F57440FECULL, 0xF85FBB322CF86E7AULL, 
            0x3484DDFC91D1AB23ULL, 0x24F8789F0743EDF2ULL, 0xB808EB84E17BE568ULL, 0x318EAA481AAFF08EULL, 
            0x05B49467357DFE0EULL, 0x055BA9F6172F8B83ULL, 0x6D0C8F6C821E6205ULL, 0x78EFE23FA84152A1ULL
        },
        {
            0xAFEBABF4180A32A9ULL, 0xE17C07D37655F87FULL, 0xD09AC6C0D050F897ULL, 0x0278F596F403A02AULL, 
            0x1A778A027AD6F14DULL, 0x930D6E34272FB726ULL, 0xDFD4933DEF61F4B4ULL, 0x7FB20A352135E227ULL, 
            0xDCFA884D97278D86ULL, 0x9B5DAEDB00AC3811ULL, 0x01D1302FDCDE59CAULL, 0x86262C8FE223CB68ULL, 
            0x8D0466ED5A2C06F6ULL, 0x7A469382CA8E2A85ULL, 0x711DF109D04034B9ULL, 0xC52CD8DE653C13A6ULL, 
            0x1543CC6F89D320E8ULL, 0x61A0D093FA25210FULL, 0x4F069CA309A8B9F5ULL, 0xDFABEE452B553FA4ULL, 
            0x81F7A60A373DC913ULL, 0x7C30EC14B1F72DEAULL, 0xE6E820CC1E42CD35ULL, 0x451517FE5C3636AAULL, 
            0x02454477095C25DDULL, 0xB7DBE4F0536987B2ULL, 0x0DFE8AB3B12C86B9ULL, 0x5AE45C8129118BE4ULL, 
            0xD901ABA5C3A65917ULL, 0x61FC6FB67E55649EULL, 0xB30F12B065D714AAULL, 0x47117E488B3A8DD1ULL
        },
        {
            0x53AC0248F587C8E4ULL, 0xAF470C5C58C631EDULL, 0x396D0DF6DD5BD5DAULL, 0x1AD5C886B8F6B21FULL, 
            0xC5088FE0B1AE1985ULL, 0x77816FBE42C5590CULL, 0x5F52F6839C41B413ULL, 0x0DC32C0F54C9FBC0ULL, 
            0x8B7D4D3E9ACE8D8DULL, 0xE2110F2ADEA27DB0ULL, 0x7235D27625C2582DULL, 0xEA961882DF6C67FAULL, 
            0x18260F42809FEFA9ULL, 0x06C391B0F5C02307ULL, 0x7DBD010C838C50E6ULL, 0xD9EDCD418731F92BULL, 
            0xBD2784CE503D456DULL, 0x7BD275AE3CB00E5EULL, 0xF719390AEE62086EULL, 0x749B83F28DD61729ULL, 
            0x6843503880ABFE68ULL, 0xED7409BC6C1FD268ULL, 0x621CDD7BF7CCA557ULL, 0xD9A29356DAF68BC3ULL, 
            0x6DF277E3C71CDC63ULL, 0x3F6ED59AA8BF920FULL, 0x0ADF9A3134D3E1D8ULL, 0x3727F12CFF0B8503ULL, 
            0x034E24353279E386ULL, 0x995E90BCF300A500ULL, 0xCF57A2A49022761FULL, 0x14CC5CF706BC6DCBULL
        },
        {
            0xBB198F9A702D8E0BULL, 0x3A12F13D555DCE5BULL, 0x454D8C4112E04AB3ULL, 0xB2C8C9C4ED81C6EBULL, 
            0x902301C16E1E09FBULL, 0x3CC365FD448088F4ULL, 0x89FE708A671E8587ULL, 0x28FF3BE6410411FDULL, 
            0x31C7BB2F16C21A72ULL, 0x8467EA2F6404B407ULL, 0xC053629406FAFED9ULL, 0xFF877FBF67A9F7EDULL, 
            0x749BC7CA0F362A43ULL, 0x56879B59A1A8FE51ULL, 0x4CFB9F931985A8E0ULL, 0xD9196D7B3F6E3E2FULL, 
            0x504F6517FC6E8E74ULL, 0xA1A768D1924B06E4ULL, 0xB85A095A0439194BULL, 0x451D5675752D2C43ULL, 
            0x6ACA922D4549F7FBULL, 0x94B22F0CC29B1420ULL, 0x87A1316D6A06C3E8ULL, 0xC3A0D056B4AC76D9ULL, 
            0x9ED4BC04FA4BA27AULL, 0x5926F159A40B7A15ULL, 0x953C18801F333985ULL, 0xD6D2618E7D7DEE7AULL, 
            0x21E006959ED3D964ULL, 0xB7C82938F5744E33ULL, 0x9655CD9486089339ULL, 0xA7D181476998F5C5ULL
        },
        {
            0xA061DE69B283D41CULL, 0x6B486A73B854AA19ULL, 0xBE307B8BF29E003CULL, 0xD51E55BBAA5E9629ULL, 
            0x92797B810A40AFCCULL, 0x7E78FA5AEC5A1DF5ULL, 0xD26748F2091A307EULL, 0x354FAD35A297C20DULL, 
            0x2196BC60904A9219ULL, 0xE486EE656E597BEBULL, 0x467DD13813831E43ULL, 0xE17226B5270B51FBULL, 
            0x8EE5B33593EEAC7AULL, 0x414BF15EA324C799ULL, 0x2B6A92E1AD59A65EULL, 0xC82301C64717F68CULL, 
            0xAA77B511B763FD1AULL, 0xDFCBADE7CE88CC70ULL, 0xD9051A7D394879FFULL, 0xF1FA24A033323CE7ULL, 
            0xEEF87E20718733E0ULL, 0x4D2847CE9E3B0279ULL, 0x7D9532AB2629A07BULL, 0x7B4731187E3DE970ULL, 
            0x39F7416A434F0288ULL, 0x229C7980C09C6878ULL, 0x67519E983DE77736ULL, 0xFA94700F60359644ULL, 
            0x82D11EEC60108085ULL, 0xA46C20AE4DBAE19AULL, 0xD479182B1081B13AULL, 0x8B69C2DCB65190F9ULL
        }
    },
    {
        {
            0x51B551286F9611A9ULL, 0x7C7906CCA9A26DEFULL, 0x392DDE8A8E7A536DULL, 0xB4B7668C8208BDA8ULL, 
            0x43FA7C4B81F241BEULL, 0x3649B385DD595154ULL, 0x925F2E75EAAD4D5EULL, 0x6A9ED3F8F14DD2ADULL, 
            0xAF61C62E3D46D096ULL, 0x74DA8387BC7AD587ULL, 0x01CE5BE3FA633D8BULL, 0xF7F5BB26B0B5A793ULL, 
            0x46EE96AEF5AE6896ULL, 0x67D8FE24D1442EF1ULL, 0x8BCF532893AEA081ULL, 0x739BFFF86B4AFD52ULL, 
            0x5706EC7CCDA458B2ULL, 0xC4322A62374882C7ULL, 0x2EE63CF04937A899ULL, 0x171AD17B0D47F98CULL, 
            0x640A35702FEAEAAFULL, 0x0368B19D89C9B80CULL, 0xAF3A747894261EF8ULL, 0x9B437B32D4E25AD4ULL, 
            0x78DB4674C9D8A4C1ULL, 0x5E6B08F6231DF289ULL, 0x3C5B68A358C12A3DULL, 0xC8B6016591FAF28EULL, 
            0xEB14E258CBF879D3ULL, 0x50062EDB5348CA66ULL, 0xC4F0308A76FA93FEULL, 0x2D53A7BF5499D555ULL
        },
        {
            0xF91B041B834B2D69ULL, 0xCFC1D21A5BA88C7AULL, 0x2C764A37C7B244CFULL, 0xAB13798E019C04F3ULL, 
            0x7F73C25983C83796ULL, 0xD26D384DBBD51D2EULL, 0xA111E12F5972914DULL, 0xE45D5886C671E26CULL, 
            0x123EA424D1BED876ULL, 0x13C4764D42330DDFULL, 0xA016BBBB8FAB34B6ULL, 0x666208A7ED08C3D3ULL, 
            0xF0D332BDD2EC9D80ULL, 0x5A162773081595B7ULL, 0x83A6D7862990DB47ULL, 0xFE298D8CCFE08423ULL, 
            0x864E427A381C7E8AULL, 0xFA29B3FB569F6F1FULL, 0xCCCA58AC55129BCCULL, 0x31338A1AC78EFC0FULL, 
            0x34F96E5EAC1034B3ULL, 0xA45981503E4560D5ULL, 0xB28C2602E2CA20E6ULL, 0x54CB902FC8984C35ULL, 
            0x8B17160ADF0B813EULL, 0xC3C4BD14D5D10D09ULL, 0x4B98225E93B6A659ULL, 0x2E11A71D4F238A4DULL, 
            0x6EDBB91D79A5048AULL, 0x81CAE6D239EF52DDULL, 0xFC7FD889870C8912ULL, 0xEC1D89162B689BECULL
        },
        {
            0x1AA751AACEB234D7ULL, 0x2B57F1F1BD4ACE41ULL, 0x980EF788FD36156BULL, 0xC8E51DF669B2C483ULL, 
            0x670B3FE9B1A10742ULL, 0xBAB19554F35EE2ABULL, 0x8B4E325607CFAAA8ULL, 0x4ABD4012DE5BDBBFULL, 
            0xD6264236439E1D7AULL, 0x662753F73B3F359DULL, 0xCBB0ADCD56C492D8ULL, 0x61B6E56195844216ULL, 
            0xE724DCD8C6B7FAE9ULL, 0x3F5DD3B716C68D5CULL, 0x92617B844991C0F2ULL, 0xE8FFC0717483C4D2ULL, 
            0xFF18B4728E22038EULL, 0x3D1D61750476059DULL, 0x0C595E8FCA5EC70BULL, 0x82E8D88C1AC88CC5ULL, 
            0xC56EDD802D35373DULL, 0xFEA713E38FA208C1ULL, 0x40095B5AB8718D73ULL, 0x5895ECC74C9BC540ULL, 
            0x1C6EC412600E6637ULL, 0x1A8B955E87CF1ACAULL, 0xBD25A434671AA623ULL, 0x3EB3D418DE016733ULL, 
            0x630F11C0007BE55DULL, 0x758FBA909FFC4B1CULL, 0x902C87BD7DE2875DULL, 0x91F8DB40E07AF619ULL
        },
        {
            0xEC37874A822AC3EBULL, 0x8B715BCA3573A4D2ULL, 0x1CF78B310212F6D3ULL, 0xD0E21ADC58304691ULL, 
            0x7155C738404473ECULL, 0xF62B3E376D52AF03ULL, 0xDBCD9446A77EFEFBULL, 0xCED861AD3346EC94ULL, 
            0x826469FFCD47044DULL, 0x497E81D8118D90BEULL, 0x8ED1816DB77AC8E7ULL, 0x364CB2169281F4D7ULL, 
            0x751F43D5FD6E7C43ULL, 0x059034C402B8DEAEULL, 0x3D2E02BACBD223F0ULL, 0x15E9D80ECEE2CF1CULL, 
            0xE471A689EC7372F6ULL, 0x083AFB75A3DFB0E1ULL, 0xF64B37C9245068F6ULL, 0x7A330DE50FD1737BULL, 
            0x6C0C37B6DE4312CCULL, 0x7FA9843CBBBA0C38ULL, 0x67ADB1E6986FA72EULL, 0xF1DBB49B1C15DB2DULL, 
            0xA77F06AD8B0F9B98ULL, 0xEF35E6E1BC8A63FFULL, 0x10B1AFD046A569EBULL, 0x956B6B607D26A538ULL, 
            0x764D0CF3630033CBULL, 0xC291EA3582720A8CULL, 0x7D7D029E986643B4ULL, 0x99CE80CD3ED945A3ULL
        },
        {
            0x321B6BFF16D38968ULL, 0xD99BD737AC554CF6ULL, 0xC0F85A61428C6769ULL, 0x6890A5D572C8D3C3ULL, 
            0x059B2E6632BD040BULL, 0x5B942C0C86881D57ULL, 0x0B7820E6D4B810F5ULL, 0xF154BE94F2E3CD18ULL, 
            0xAD1D68086728809DULL, 0x4544415EFCD1BD75ULL, 0x940292BE2617DA37ULL, 0xF621C7D6B7741CCEULL, 
            0x733637AD9C367076ULL, 0xFDFC070A80CA9D26ULL, 0x2AED851B049B34E5ULL, 0xAF9A0E9EA6635B46ULL, 
            0x708F4D8D69DEFA24ULL, 0xC8F98044FDCA99C5ULL, 0x981095A6D3254F88ULL, 0x70F96EBD5D22E533ULL, 
            0x0BA201615869AC0CULL, 0xFBD97CA4D0238A2EULL, 0xADD798197000D7F1ULL, 0x9AD348FE63B0BBBBULL, 
            0x6119F45FADBD651FULL, 0xFF4122B25D306F17ULL, 0xF7576005FAC452BAULL, 0xC6504CD0691A5272ULL, 
            0xBB2C768596F30996ULL, 0xA520D41EC4A7EE62ULL, 0xC9F1237434CC9F01ULL, 0xB85C92537FEBAE60ULL
        },
        {
            0x42392054B8428EABULL, 0x33AD0D6B2305BFF0ULL, 0xE6F82873BD62AF97ULL, 0x76996FF5656B1823ULL, 
            0x7ACAB1279CBE7A06ULL, 0x26DEE24A65840458ULL, 0x14CFBCF6784FCD49ULL, 0x59B17A6302FF369DULL, 
            0x246E1035EE48B39AULL, 0x6C522D48C3C3A65CULL, 0xF10951ED3C9B2826ULL, 0x78C374A8CAF117C7ULL, 
            0xD184113D8EB44A6EULL, 0xA8D84EFA434EC763ULL, 0x038469D9B2BF1F6AULL, 0xDA15F63D433DCE06ULL, 
            0xE7E24D0BF25633A2ULL, 0x7BDADCCF448062CEULL, 0x33A9ABC585B45A52ULL, 0x42DC1F5D5DDDD872ULL, 
            0x988D672FAE6DF4AFULL, 0x4C97A4F16329E4AAULL, 0xC9A6CCC79326B3C2ULL, 0x5C81B7597DC32120ULL, 
            0x4A98CC3328BF97FFULL, 0xFFFAE6538B773A46ULL, 0x1E4525CC3B0342B3ULL, 0x3B93AEC18BEE99FDULL, 
            0x1523578020C41D64ULL, 0x5151948E5DBD1916ULL, 0x2376E3E618949615ULL, 0x520DE2163F7EEC42ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeyRotateBConstants = {
    0x9CF0D5EE35164149ULL,
    0xB2E1413EF9B9626DULL,
    0x6C0EC9786084EC45ULL,
    0x9CF0D5EE35164149ULL,
    0xB2E1413EF9B9626DULL,
    0x6C0EC9786084EC45ULL,
    0xFF129CE7F896A9D0ULL,
    0x6CC9421C69D3039AULL,
    0x0B,
    0xB9,
    0x12,
    0xEF,
    0xE8,
    0x59,
    0x39,
    0x4B
};

const TwistDomainSaltSet TwistExpander_Canopus::kKeySpawnASalts = {
    {
        {
            0x3E572CA3C218BDD2ULL, 0xA239B6CE4E14D782ULL, 0x2C844691B5B60B07ULL, 0x944E65827A04056DULL, 
            0xE0A0329BF661B55BULL, 0x62878085435BAC97ULL, 0x89991A06A86E30D2ULL, 0x827EC23FA2627249ULL, 
            0x5A0A0CEBB1A65DAEULL, 0xAC0F6DC04AB70535ULL, 0x4236D227FAF1BB71ULL, 0x905DF1D9872CE722ULL, 
            0xEBEC60A49C965BE3ULL, 0x7AF68AACD4A63367ULL, 0xD97CFFA072127897ULL, 0x118A65FAC3A57B13ULL, 
            0x4179F501FE87F62AULL, 0x8CDB26374C112D15ULL, 0x6B1CD736907531C0ULL, 0xA6BD6E0F57130A45ULL, 
            0xD88C0DC02F7016A8ULL, 0xF72F7B269F3489AAULL, 0x0972A5E6AA882804ULL, 0x00A3C66F8E993121ULL, 
            0x6DD0646F0EA44B7FULL, 0xBB5A65AC1B5D87D1ULL, 0x69D3680659491D91ULL, 0x46FC2536BAF03614ULL, 
            0xD1C08A2D07737CC1ULL, 0x681F63C3F3A4F21FULL, 0x6FFE4F126564A560ULL, 0x3EA6D00BB4289A3BULL
        },
        {
            0xE3AB0838B3BBE5A5ULL, 0x85A2ABCF09DDF35BULL, 0x7E0158DBA3903090ULL, 0x21CAEEDB6BE7BC91ULL, 
            0x25DB49B20365BC50ULL, 0xD48BC4D99EF61FE2ULL, 0x9A337CC7460952DBULL, 0xE3AD6AF6FC0C9CF0ULL, 
            0x267351119AF649A7ULL, 0x67FA6E6B122F83D6ULL, 0x15B5A1161B84A570ULL, 0xBAD0AA3EE1C2B51BULL, 
            0xC64CAFF10AA73948ULL, 0xEAABB42613C6B3FAULL, 0x435E8150EF65A21FULL, 0x21939AC7D009C159ULL, 
            0xF3A2DA7F5406545DULL, 0x956F8B03025FC2C0ULL, 0x00FFA8EA633FCBC6ULL, 0xD0FE920F103B8547ULL, 
            0xBFC817369272DF67ULL, 0xEC08AE5C8B8FC1F6ULL, 0x05A6CD1549F281DDULL, 0xAACCF717A28D607DULL, 
            0x19D0AAAD5A5C1D34ULL, 0x59F3710253314F1EULL, 0x9DF131008A387DC9ULL, 0xBEDAD96020A13269ULL, 
            0x4A5CBBAD145899EBULL, 0xDFD8FDAFBA52796CULL, 0xB703D857069756E8ULL, 0x47072951F13F16CAULL
        },
        {
            0x2C64541B2A5DD881ULL, 0x81464EF83456779AULL, 0x9CE954073A3A1D4FULL, 0x1DC94C50BF2F6A58ULL, 
            0xAA9CE30F0CDA2955ULL, 0xA37E0BA409EA10D4ULL, 0x573C3F49A24447ACULL, 0x7078196F147944F1ULL, 
            0xCEF17E581ACC4851ULL, 0x3BE322A3477A7C71ULL, 0xB95BAA115397907EULL, 0x3E251CE840DF4765ULL, 
            0xD1E4949D7054425CULL, 0xBECD9607619F6BFCULL, 0x8EDFEBA18BAB84F2ULL, 0xD5116FB36CDDD708ULL, 
            0x43179AEEB21BF985ULL, 0x7530A24C4A33B5B5ULL, 0x84EB623E9868F40DULL, 0x233797EE82315F3BULL, 
            0x773B151A4B6023E8ULL, 0x1E49B97DA2301668ULL, 0xFA3FA521ACCF53F5ULL, 0x1F39BB8274770C9AULL, 
            0xE5E3B5DE4630E74FULL, 0xA009113B9B1D9EC2ULL, 0xD90AC7FF3DF26CC3ULL, 0xCBC6A091458544DBULL, 
            0xB20032B4D3C43499ULL, 0x2C0643E269FB9ED0ULL, 0x3FC747804F3DE48DULL, 0x52DEEC23F7CD41A8ULL
        },
        {
            0x0D26C09B9A816040ULL, 0x4D37E810A30B2F78ULL, 0xB6C047C0BE1CC82CULL, 0xF6D762CEFD6AC6A1ULL, 
            0xC4AB909C38E38926ULL, 0x381A92CA86EA81A1ULL, 0xA953989AA2F62D09ULL, 0x81247D529C9E8F35ULL, 
            0x7F272FCE5FDE1DEBULL, 0x9FC9ED327BAA8B3CULL, 0xB8959ED51925CF9BULL, 0x10947790DA8BF0F6ULL, 
            0x4F5F49BF169A52F2ULL, 0xAB3A5419468AFD7FULL, 0x824C0B7BEF33128BULL, 0x6045935B6058F3ABULL, 
            0xAB697F1A7750246EULL, 0x0B11FFBF0A45FDE3ULL, 0x0F700931977BD314ULL, 0xA1379B61FB3DCBD5ULL, 
            0x5D14F55895AB7BA0ULL, 0x66AE2B8A6C6FBBB6ULL, 0x42CE84AF09E587E0ULL, 0x0058D772CCD4B61EULL, 
            0x1C72AEF43D7FC727ULL, 0xB6B5F3D95D9A7BEBULL, 0x25FAA6065638B5A6ULL, 0xC045A937BA0273A3ULL, 
            0x6027026DA406343FULL, 0xD682ADC333F76E00ULL, 0x69F6B99FC1B6C3D2ULL, 0xEE4C6DFB76CC7354ULL
        },
        {
            0xE1A8AC95AF0F5A46ULL, 0x6EA4B6196875592BULL, 0xC2040C9F9EAB8886ULL, 0xDDCA1E7EE92678E6ULL, 
            0x33602D53C91AC332ULL, 0x539BA1F137EFBFF8ULL, 0x554D3C80793F5A40ULL, 0x52FD10D4313D4EF0ULL, 
            0x14A1411DC3E2D06BULL, 0x465B7B082521C267ULL, 0x2A5E2CD37C09587EULL, 0x1804236D2C26E600ULL, 
            0x98D358AE6ED2544EULL, 0x51041DD9FDE059F3ULL, 0x9967ABCEDBD132B9ULL, 0x27C9E7EC919D0897ULL, 
            0xBF459B0DCEF7CEA9ULL, 0x9603B8D8BE24FC0AULL, 0xD2C33092E9DA4FF6ULL, 0x2D267B394A88DBE2ULL, 
            0xFDADC893D624B1FAULL, 0x560D5D91552F9F76ULL, 0xED9B249F531F03E2ULL, 0x9F1DE12F34580C51ULL, 
            0x10244CEF2DDE1EE7ULL, 0x0C916A668FDBA4E8ULL, 0xCF8A04DAA7D896ACULL, 0x03967865CD4F6C09ULL, 
            0x5B79685504436111ULL, 0x77601A963BAB98ECULL, 0xCAED46F987A39841ULL, 0xC60CA212FDFE7BD7ULL
        },
        {
            0xA22E810B06AE7FF6ULL, 0x668351033AF6B9F1ULL, 0xB9E3864EFEA47FCAULL, 0xBE69F5C1BBAF860FULL, 
            0x0B56F0777880AE97ULL, 0xF435AF547B87B739ULL, 0xA64D679F374F7B2BULL, 0xDC29473B701C37B5ULL, 
            0x5D3902E38EA0FE00ULL, 0x03C109B59F41B21BULL, 0x961F61A3EB86702DULL, 0xC6E39F6F504306CCULL, 
            0x5F075E2FBD1CBAA8ULL, 0x8281D20FF72E0741ULL, 0x5A573DDD8BAED57EULL, 0xA31510183566224EULL, 
            0xAD79709407A9DA08ULL, 0x4C9B48A32C2C8DF2ULL, 0x6519A48831A32840ULL, 0x8E037FDAFC794EBAULL, 
            0x9828B0C2C9A17719ULL, 0x19CC25F38402FBD1ULL, 0x1E933AE43B901304ULL, 0x88C8D983E5602905ULL, 
            0x12C43546B4838324ULL, 0xC9CD442781608924ULL, 0xCDD1293B3A1A28D0ULL, 0x10450A122B0F6127ULL, 
            0xE274D24C2C43ED5FULL, 0x889D975F59821425ULL, 0x7E5E9C5050786D69ULL, 0x2BE33662C2286C4AULL
        }
    },
    {
        {
            0x58E3DE06B112DE30ULL, 0x2965613BE8CB684CULL, 0xDDDCDB0EADD28DEAULL, 0x900128ED7686593EULL, 
            0x96D14E400850579EULL, 0xF5F1EFB34F06FA3FULL, 0xA76ADCB4A1B261AEULL, 0x7E9069FDD8E2B07DULL, 
            0xBC1ED8416B346023ULL, 0xB61B8D6D4B7ABD3DULL, 0x30233D607502EBCAULL, 0xE25BF11900EF4135ULL, 
            0x634BF6CA8AF08C22ULL, 0x06F16CA43B45B8EDULL, 0xC3292FEA32599B60ULL, 0xFE8791DC7EA50CA7ULL, 
            0x529850AAC266CCCFULL, 0x0EC2784959324235ULL, 0xCB838BC227445CD9ULL, 0x57D9609DE9FD2C05ULL, 
            0xC788632E6F95684AULL, 0x220F73EFF5E4BF2CULL, 0x69222B5D6DCA0C4AULL, 0x3BEDD1D19D8C6AC9ULL, 
            0x7A5B8CB1660F3EC0ULL, 0x069B9072530ACE19ULL, 0x63E8251B3629DFD1ULL, 0x058DF4D9095D0250ULL, 
            0xA09A8ECFDB48EAFDULL, 0x2A21C32EE8086F45ULL, 0x4E1AFC506C9FE577ULL, 0x3CF8E5F4D8C63B1BULL
        },
        {
            0x2DB602F872CAB213ULL, 0x9D95CEAD7D3238C5ULL, 0xBC7874AED31ADA9AULL, 0x219185FEC6848504ULL, 
            0xA5D1C85266C0BA3AULL, 0x2E748F024AF6E94BULL, 0xE6135E26CF66BCDEULL, 0x292439382A68176BULL, 
            0xE29CEA9E1EA1514EULL, 0x1002B9B5A4DED398ULL, 0xD3AC12DE670E12ADULL, 0x2A3845F881B7E06CULL, 
            0x7EB3C8CD3A3CB614ULL, 0xCDECBF9C75A5B31BULL, 0x354E3259883F66CAULL, 0x4A4555D8C24554F1ULL, 
            0x0174BF706916A0F4ULL, 0x9D3A381E282F9BB3ULL, 0x1E493EDD9933F992ULL, 0x587E20E9C12423EBULL, 
            0x8FDFDCACFE56B5EAULL, 0x414B5BF1689E25BFULL, 0x5B528561F355B037ULL, 0xD25F544251414E1AULL, 
            0x7105063ACFD33ECBULL, 0x61BC235E23A3FBFAULL, 0x4784563FB5905D73ULL, 0xABACFD127D4C1180ULL, 
            0xC28D14003A4706BBULL, 0x15C1A8773409D9C3ULL, 0x2C7A9ABD820D0F35ULL, 0x9F7DB23A72DCE2F0ULL
        },
        {
            0xC8BD5334AA6A3755ULL, 0xA6CC4FB02AE0BCCDULL, 0x79EC3C87D6B38C24ULL, 0xFE4E7741454A46D9ULL, 
            0x35EF3E5C25ED2FE5ULL, 0x0576F44E3DDAD758ULL, 0x920417982C71848EULL, 0x0016A88706FA139AULL, 
            0x7203C28B8A58747AULL, 0x2AEFD1D77A39DC3EULL, 0x9BED1E3E6CBE95BCULL, 0x7D8453F91EEE52CAULL, 
            0x5934E95821773E06ULL, 0x16A7CD1E501CB060ULL, 0xDA675FC918B674E0ULL, 0xB98F39A8B778BAEAULL, 
            0x953597A9DA6C0685ULL, 0xEB949EF09F48971FULL, 0xB2627CF597E49C1CULL, 0x0169149C86F7937EULL, 
            0x9CD194959243A688ULL, 0xEBD57A1827AEA95AULL, 0x97BB0C7D0A055F3CULL, 0xC38A578688839939ULL, 
            0xC5710E14AF8EA07DULL, 0x2EFA7F9B1689AA04ULL, 0x22D2E86910CC5FEDULL, 0xC41926EF16CA76A2ULL, 
            0xE95BCE1F00941D5DULL, 0x5ED501DFF7383297ULL, 0x9805C4D5BD6AC467ULL, 0x288E33269812BFB1ULL
        },
        {
            0x4232F510DB25545CULL, 0x23A4CE2FED9DF9E4ULL, 0x5C793D01FE21F916ULL, 0x2DEB013319D54EC4ULL, 
            0x37FD17A1E682E4B4ULL, 0x5336E2C9F3816A80ULL, 0xA9C23DC3EC49A6B4ULL, 0x2CD7947E745B8C38ULL, 
            0x40315601080FF5E0ULL, 0xA6E069E480C7BABFULL, 0x21FF14FFD0D8064EULL, 0x99FEC275219D11E5ULL, 
            0xE77AC92F5F805D68ULL, 0x78FA4F54FDC62639ULL, 0x4F07684AD7661C2FULL, 0x638A407F3E163654ULL, 
            0x6EE0823C6830C1B6ULL, 0x6200BBFF8E52D282ULL, 0x422A07BA12D9AF89ULL, 0x809C8A2305CC52A1ULL, 
            0xC00E70762A1A36B9ULL, 0xD15F23F757E23BB4ULL, 0xAC456DC6B08CF594ULL, 0x401670DC7C71A771ULL, 
            0xB9754224E92E5FEAULL, 0xC02BEE9F9363E167ULL, 0x74418C5744D59E38ULL, 0x59F53D396C376884ULL, 
            0xFBC52E953CD8313EULL, 0xD37D5F7A7E8F79ADULL, 0x616EF8D44D8AB700ULL, 0x22B2EA9DCDB1058EULL
        },
        {
            0x54D800B52BBC9B51ULL, 0x0603F800CBAA4A5FULL, 0x5CA9A73E8C9578D6ULL, 0x123B1528D2CF71FEULL, 
            0xFC42D4264298113EULL, 0xB5A566C15808821FULL, 0x41BB51BA8BD80DDDULL, 0xB9F620270C328833ULL, 
            0x366DBE55F39F3DB2ULL, 0xDF03C3E312FE04E0ULL, 0xB4F8392086625AA2ULL, 0x00862B9577A36766ULL, 
            0xFC642A24B0897B65ULL, 0xDA4064C47AFAAE09ULL, 0x745DF97788E4E5C6ULL, 0x6E79274FEB6A0250ULL, 
            0x95CA97942B2EE03AULL, 0xF1A4E4B618D65E68ULL, 0x8B7191587A2595C2ULL, 0x1FBB73AE955D115DULL, 
            0xB45C56843F89DB0FULL, 0xCC11834F2C26D2DCULL, 0x450112304A22E6BAULL, 0xAE427A17ACBB49B7ULL, 
            0x7D405C91D1A9B846ULL, 0x0E9B9660AC051852ULL, 0x08759856C8B765EFULL, 0x1BD38EF95A87324AULL, 
            0x5A8FB67C922E4FEDULL, 0x4DBAD770C3BB1B78ULL, 0x873DC22F25FFE18DULL, 0xD80D2522F719724CULL
        },
        {
            0xBC51FD4E9CC8236CULL, 0xF3FFC1DC61D66E3CULL, 0x113D4A966ED80F0FULL, 0x5F9FA80934F43DE5ULL, 
            0x5E640094BBC268BFULL, 0xE6E636EAB4B7AD11ULL, 0x1B09466D4D9F80B3ULL, 0x28FD0DA0A79BCFC5ULL, 
            0xA47CCCD47D262AB3ULL, 0xD7ACA7213DC70E6FULL, 0x62AB626D2CF1583BULL, 0xE2B7AE8C12C9BCCEULL, 
            0x49F3FA33AB32F04CULL, 0x37A1A6A2082C1E6BULL, 0x9333A42E2EF13907ULL, 0xE83E7634486F5317ULL, 
            0x87A8E7C8E8152854ULL, 0xB8E373C0604000FDULL, 0x200B4B3D1AA825DEULL, 0xD64A1D6EEDC0C8E6ULL, 
            0xD91A4C60118FCA9FULL, 0x0CB05D8718414E08ULL, 0xD66D454006F4CB57ULL, 0x29C65949BF2CFFF1ULL, 
            0xAB4B8DE394EBD01CULL, 0xA7E9F4A89FC33C25ULL, 0xD90FD7D25DCDEB56ULL, 0xBB5AD4F769970853ULL, 
            0x7247E774677395F1ULL, 0x9C0FAB8CD7D8B6E6ULL, 0x10B85BDBAA73A0D1ULL, 0xA1744F60A277347DULL
        }
    },
    {
        {
            0xFD7CA14B899D892FULL, 0xEC8A8A2A82BD7A5DULL, 0x10916FF96DF558AAULL, 0x7043E537EDBEF2A2ULL, 
            0x04FF66F7362676D6ULL, 0xB5F9C362E8FE1077ULL, 0x8AE9FA5A8F75EB5DULL, 0x8118A992A4292882ULL, 
            0xBFC6778F8861CC7BULL, 0xC03E3B954CB020F6ULL, 0x26D8BED498BF8CBDULL, 0xE38F85699FFAC219ULL, 
            0xDC2136B2FB46EB30ULL, 0xE7DF04D9A9BCA98CULL, 0x947C547A44D94CA7ULL, 0x152AD6EFC9F203FAULL, 
            0xC8E8601DCBA234FCULL, 0x6E09D89A77DA508EULL, 0x5DE5E7E18D0B3B2AULL, 0xA15235C2C24BD156ULL, 
            0x2F8BB225BB2B1EF8ULL, 0x5F3BB19F6266DF37ULL, 0xB4B5C62F3CF63EB4ULL, 0x8C587257B2D738A9ULL, 
            0x8C1C0D12902F9D67ULL, 0x9267AAEC2C98E151ULL, 0x2CA8F73CF94DC87AULL, 0x54CBF110BC437293ULL, 
            0xA6D63AD7C290EEEBULL, 0x849415BB66B355EEULL, 0x46277905AE04FCD2ULL, 0x17797A6FFD1AC7E1ULL
        },
        {
            0x875DE0EB1D8BC8F5ULL, 0x04C57B27C214AA8CULL, 0xA6E5710D17495005ULL, 0xF49DB4FDA77944D5ULL, 
            0x22E5223DF9ECC01CULL, 0xB1B39C15C3CAF43FULL, 0xE7D08E75B32B04CAULL, 0xAB7689D24CDDF488ULL, 
            0xDB29FFCE5BB9CE23ULL, 0xF0B8F918F3309444ULL, 0x8F1180C20A54BFFCULL, 0x9340292CC2080FB8ULL, 
            0xD8B4F55D5D5C2665ULL, 0xEA8541A129240C81ULL, 0x693A9B34633A1957ULL, 0x9C75F18FF0E851A5ULL, 
            0xC5557F092A08A46CULL, 0x055DC60C3F2C1BA1ULL, 0x2B428F2264B15EEDULL, 0x99585038AD1231DCULL, 
            0x1DD17F7DD8AFDF2EULL, 0xDB31592CC388A233ULL, 0xB5FFD469249268F3ULL, 0x39508B046B553071ULL, 
            0x7D5134402B903855ULL, 0xDD4FC6052763C41AULL, 0x31F3F8C25E70F152ULL, 0x295559CB57605A76ULL, 
            0xF7FD7187BA4802F5ULL, 0x394CE96546446C57ULL, 0xFD48347B7C9DF68EULL, 0x3A68A40D0C7EA201ULL
        },
        {
            0xA2CE7CD5A40C7441ULL, 0x1440210AD9945E3FULL, 0x4D3BA21D3744BF78ULL, 0x6A92810B50A69F2AULL, 
            0xA34EFEFFFA96010BULL, 0xFFE0D3AD9167FBEAULL, 0xBDEA5AF8C2FE2DBCULL, 0xE96DB2ABDD3662EAULL, 
            0x57437803511ECEFAULL, 0x0CAB0253B403D446ULL, 0x43E5F28711A40BB9ULL, 0xCBEC236EF45BD1DEULL, 
            0x79EAE29423E0FA77ULL, 0x4499F95B8274E0F8ULL, 0xA3CDB8A674A4788FULL, 0xD034627CB46737CAULL, 
            0xBA2A10C9AEA48D3DULL, 0xC400AD506F117E1DULL, 0x78EBF70A57980B06ULL, 0x893DBDAFAC39FEBCULL, 
            0xC6FE7CC1E20A6493ULL, 0xD0E319BC818293C2ULL, 0x0B93B1A38244BB54ULL, 0xE218A44C63748EB5ULL, 
            0x889831ED9AA49692ULL, 0xA724144A03B130C1ULL, 0x0654D25752737315ULL, 0xC2E2985826D5F2A7ULL, 
            0xC3C2AB3A6441790BULL, 0x9193C870BCB32B37ULL, 0x6343D9B226959B20ULL, 0xCCBACC965E166BD5ULL
        },
        {
            0x06C6A2D43555B77CULL, 0xE3BD06227040475FULL, 0x8D13944A4F5EA020ULL, 0x2EB5B68019D9DD3BULL, 
            0xA5C718D134EA3B40ULL, 0x8DB2F5418CB8C2A3ULL, 0xA8ADBBB1F52A0127ULL, 0xEC28B016188B51E3ULL, 
            0x047F41BF15B48B1BULL, 0xCFF29D7AD9BC3B36ULL, 0xA7B0B31B132DD443ULL, 0x5F4C6BA631126082ULL, 
            0x00216822B4B94B36ULL, 0x9ED5809A407BE91CULL, 0x1C44F1F893CDBECBULL, 0x72D10D4EFE567C03ULL, 
            0x54C60AF156340728ULL, 0x976D7DB5F5FB64AFULL, 0x6B42D5807AE61B6EULL, 0x569F07E5CFCFDEE7ULL, 
            0x5F588C877699409FULL, 0xD18268797A290B18ULL, 0x10546E2616DAFBA2ULL, 0x3D144E9AE7EDC438ULL, 
            0x2043DB01FD447315ULL, 0x45220716CC886AAFULL, 0x1DC79EF757EBF9B3ULL, 0xC8C6B0034A896A1BULL, 
            0xE965BE37B4109D00ULL, 0x9D3902DBAC462784ULL, 0xDC5B29862FD4F3A7ULL, 0x9777DB86F5D25836ULL
        },
        {
            0xFBC575F7543FA8C8ULL, 0xDAB8D7EC69CCEA97ULL, 0xD3C59A85F66F7789ULL, 0x738ABAB1DFF64011ULL, 
            0x3CBE1B41543ABB1CULL, 0xE9C0A6DDBBE7852CULL, 0x621017C087414B69ULL, 0x79F91C209703B82CULL, 
            0xAA2376161864A569ULL, 0x1E8AE61CE364D117ULL, 0xEC749182CD7A1105ULL, 0x222838C674371C80ULL, 
            0xB190BDDEF40EB750ULL, 0x100CFDA9494161D3ULL, 0x46D762A6BD672CF3ULL, 0x257E1627B5EF7C5BULL, 
            0x747816595AC015BBULL, 0x793F49DE24A272E7ULL, 0xEFFA6CF1E101C3C9ULL, 0x7712C6E4944FD8ABULL, 
            0x0C28B387216B98FAULL, 0xFA0C9E94D84C0244ULL, 0xC0107685B398DCEEULL, 0xCEBA863C617E1C25ULL, 
            0x1B31EF2E0D8DB566ULL, 0x542A4E811DA585B4ULL, 0x5A86046810327A2EULL, 0x493428659A8E65F7ULL, 
            0x5C0C65CB589CB10DULL, 0xF7B9BE7E47B2734BULL, 0x7E65C5B55E6EC0CDULL, 0xF7D6897213DDAD52ULL
        },
        {
            0xB3F056D06651FC9AULL, 0x8A950281DE3369A2ULL, 0x689CB1689ED29762ULL, 0x51DA783EF73DE828ULL, 
            0xC667779B2E52F84FULL, 0x7FA32937814D6A82ULL, 0x2B63B71177ACFD92ULL, 0x22B6AB2E8F0398CDULL, 
            0x29F05324D17BD65FULL, 0x6664B543A06AA836ULL, 0x87537223E03EC94AULL, 0xC6BF449EC079860DULL, 
            0x69EE4CC9D0D0FF93ULL, 0x84E1421F645A5CF8ULL, 0x1426F08DAA827E2AULL, 0x3D4ECD8EDAAEEAA7ULL, 
            0x22753A68797E0B13ULL, 0xA4AA5E55DC42AFE3ULL, 0xFF84C3136AB30426ULL, 0x8D1507631BBDD0EAULL, 
            0xE779E1E294A4C763ULL, 0x25A9EA1858B6B09CULL, 0x960BB6091E860D7BULL, 0x739A91D74EFFC729ULL, 
            0xD923D744C13925F0ULL, 0x01F8DD6AED1AA9E2ULL, 0x6845AFE5045CC435ULL, 0x22842E53308FD8B6ULL, 
            0x27BB100589970545ULL, 0x06149C49838841DBULL, 0x26F833F12AA2919BULL, 0x97D70A0612DC442BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeySpawnAConstants = {
    0xD4C7CC9FEC89F40CULL,
    0x3A3DA8EB8EDCE4AAULL,
    0x44A6576419C5397EULL,
    0xD4C7CC9FEC89F40CULL,
    0x3A3DA8EB8EDCE4AAULL,
    0x44A6576419C5397EULL,
    0x5E71D3EBC1BBDF80ULL,
    0xD8C95450FB97C7C5ULL,
    0x7C,
    0x4A,
    0x33,
    0x8A,
    0xDB,
    0x02,
    0x02,
    0x4C
};

const TwistDomainSaltSet TwistExpander_Canopus::kKeySpawnBSalts = {
    {
        {
            0xF8FDA0B29FE98C16ULL, 0x088CB846F1B27020ULL, 0xC450BDBD3B19C280ULL, 0xC85A115E293D8D5EULL, 
            0x2B1D9558DFCDF83AULL, 0x8E3F446D51F06D7CULL, 0x23A30350A2615C4CULL, 0xE361C1229879BEA4ULL, 
            0x18DF33F8F9587E96ULL, 0x24EC524962154C40ULL, 0xDF7B3187AF326752ULL, 0x20CF09ACB8467D1BULL, 
            0x715603873D9439EBULL, 0x87D0B519AB114BFEULL, 0xE33F8727DEC096AEULL, 0xC88F70BD231DD7B8ULL, 
            0x28186A2AB98E8BD6ULL, 0x52D13402B51B9A24ULL, 0x7BA017D5D07FDC42ULL, 0x0EACBACD79B86029ULL, 
            0x726954E9D29CBEBDULL, 0xB6EA7E40D6E01DE0ULL, 0x1C66E3B9C7DD7443ULL, 0xEFC7B42058815C57ULL, 
            0xE3D923E21ACEBB3DULL, 0x8319B53011424BA0ULL, 0x1E1665E7D27DC4FFULL, 0x86EDB0C2D2CEF18FULL, 
            0xB3558C926B8C1938ULL, 0x1F533DE872B9E23AULL, 0x04040DDD63F15D1EULL, 0x595A6E2528094E66ULL
        },
        {
            0x6B8DB500B5FD1643ULL, 0x6D03F41BDCB3B0A3ULL, 0xC81E0D38F472A178ULL, 0x53A28BFA0B0A97B6ULL, 
            0x1BF56BBF7DA86BB4ULL, 0x58843A654AC006F0ULL, 0x877F6FA22179B5B4ULL, 0x8BAA9CB707ECF115ULL, 
            0x576F99F44D8656FDULL, 0xCF83E536716C286DULL, 0xDCDD53D0331DAE93ULL, 0x45FBFDCF65DA9E5FULL, 
            0x4E2F2C09E9594184ULL, 0xD34A48904EB81238ULL, 0x2695CFAFA64B50B1ULL, 0x8064DD04F30B1DF2ULL, 
            0x63F82AA4D159F3EAULL, 0x218B9E4DC07C5D1AULL, 0xE2F7F5069E43A8F6ULL, 0x072FE7282F098EE1ULL, 
            0x6AC383F9AEF9353CULL, 0xE4B5CFECDF0FE7B3ULL, 0xD175359298AD2361ULL, 0xE6041D389E61473EULL, 
            0x280914BC3A80957CULL, 0xBE5ADBCC3C640A1EULL, 0xB9F762F656BA33CFULL, 0x09CB850DFB954982ULL, 
            0x76619A3A0A6AA5BBULL, 0xFA2A9496F5138138ULL, 0x2D686698AE8F86ADULL, 0x928B2F0B9296FAEDULL
        },
        {
            0x398569217D588174ULL, 0xC4DD351F9A1D6B49ULL, 0x964CCBA613F9ADA5ULL, 0xFD193BBD4CD86B24ULL, 
            0xA711BEA658686418ULL, 0x89DFEEAF0AF7B99EULL, 0x07A6E777D5F4931CULL, 0xF3ECCEC48F31B32DULL, 
            0x6254F33EFDB47198ULL, 0x5FB2B0CC8F564B40ULL, 0xB7E5E078748125A9ULL, 0xD2B172214FDB65BBULL, 
            0xA3998DC6FB133114ULL, 0xE142CF79F7C74E75ULL, 0xFB84ED3DA5AAAD9CULL, 0xA30F3CFDEEA395A1ULL, 
            0xFA86AE9AAF55094FULL, 0x7DB60632698CC58FULL, 0x7EED8ECD4F51922AULL, 0xC439434565BF043CULL, 
            0x4361633A0B98C41FULL, 0x321EC09CCEF6D83DULL, 0x8E2A3E14608330E6ULL, 0x858B9A8C5D581ECBULL, 
            0x034DDA3663F92786ULL, 0xDED26D7FEAC6DC84ULL, 0xC747834DA130452FULL, 0x2A466709B2BAC90EULL, 
            0x87F6B1D845A87DC3ULL, 0xC94B0540E26A7929ULL, 0xDCF49C33AB2A2A7EULL, 0x66A6F774F61E795CULL
        },
        {
            0x63A683579A9DC2E4ULL, 0xC7A90E8B63413BCEULL, 0xE12023A3AC038F60ULL, 0x7596313A820CAFBDULL, 
            0x712A44F714998860ULL, 0x1FD98E7EA85B374FULL, 0x158DECCA21F2AF54ULL, 0xADF6695901EFE814ULL, 
            0xFD7786F48442F0AFULL, 0x41E4B2B6CA02FDA6ULL, 0xD461C58150538ACAULL, 0x09D0C9B2B0AEE4D0ULL, 
            0xE0938A67CEC0A81AULL, 0xCF1670F0F0BAF819ULL, 0x953811D48DA33176ULL, 0xF8FA6DAF145E927BULL, 
            0x5D3160358537CBA1ULL, 0x8A67E3A53FDF1B9EULL, 0x4F96CD6EB9263656ULL, 0x96729608A6F1C4E5ULL, 
            0x98234B4E39DE6D93ULL, 0xDB0418D20FE14746ULL, 0xEE81D6584AD1CFBCULL, 0x4169096E3963A142ULL, 
            0x321CAC0C049D1DF2ULL, 0x382DEC27ECB006BFULL, 0x0DFA94A1D372CBB3ULL, 0x8461BF19C78F274CULL, 
            0x3C343D5D267EC95EULL, 0xCB3FB8C3CF140555ULL, 0x5BBA9CB58B5C60EDULL, 0xA3328329E2C39D9EULL
        },
        {
            0x31E5F266DB49CBDDULL, 0x78CE04742AE7BEE2ULL, 0xA5312A7282EE0307ULL, 0x17A724258F097396ULL, 
            0x54E369FA24845244ULL, 0x3D5533471F46757DULL, 0x49A210E28012C40BULL, 0xA81C19FC24A78210ULL, 
            0x71B2F87E858B86D6ULL, 0x368861FB1438B840ULL, 0xFFD686C357186B2FULL, 0x069FECEFAA6176F9ULL, 
            0xC175F8CA6FA449EFULL, 0xE989B887DF56C0CBULL, 0x7E5061AC4F2C1781ULL, 0x369755F0D0A9FE80ULL, 
            0x2C54E7AD39852FEEULL, 0x92733B09F89FADF6ULL, 0xDF6DDA81F10C9EF3ULL, 0x8CA1457DCD63164FULL, 
            0xB4850006257B482FULL, 0xE03414CF8E5C8C84ULL, 0x6CE1E64A844CB6EDULL, 0x3447BC9258DB6CEDULL, 
            0x6908945BE896513AULL, 0xB244BC752EA7F84AULL, 0x08CC3A0C85F4EA74ULL, 0xBE40785AD79B4FCCULL, 
            0x58A4E07A242E37C1ULL, 0x9FCDE8DE2019ADA0ULL, 0xC0789EC2A711ADACULL, 0x755E40C77172F342ULL
        },
        {
            0x52A226892BE09117ULL, 0x8C54F45B86A313C4ULL, 0x1A6C37B630DEBDA1ULL, 0x3F2591CFCC21723AULL, 
            0x9840057EA6EB57D1ULL, 0x8E4ECE1E3B04E513ULL, 0xCD339A49A2C77F42ULL, 0x126E248C74939A3DULL, 
            0x6E624886745FFAC7ULL, 0x386B86D37F033B23ULL, 0xDD60A117580C2A29ULL, 0x66F4AFDF20FB6294ULL, 
            0x734FF2E47FEF6C3EULL, 0x042F31135B4203ACULL, 0xD2254124A0A007CFULL, 0x890BCE8F059FA75CULL, 
            0xE900EA0136D75835ULL, 0x7EC7150C349849DCULL, 0x42A5345AD47D1FCDULL, 0x4EFF1CD340B75B77ULL, 
            0x46A8D9369B081FBDULL, 0x4A654CC0F3C5F329ULL, 0x2BF440B104DD71BEULL, 0xE25AC3DEBFC1E91DULL, 
            0x4AACFE440D454702ULL, 0x6FD1AFF38FDB8607ULL, 0x0EA26DBDB6DA51D8ULL, 0x27B5153A023EA822ULL, 
            0x55EC5239166A04F0ULL, 0x2EAFDB84DCE1B724ULL, 0x30AC0ECCA62B9E5CULL, 0x0AF02163D2BE5C8DULL
        }
    },
    {
        {
            0x8D5B2ECEF5437DA0ULL, 0x1DCCDFA9335C8815ULL, 0xB2235B44141F9982ULL, 0xCA13FCA94201796FULL, 
            0x3CD535F4E1B4D0D0ULL, 0xE211A38F158247B0ULL, 0xD23E930913155777ULL, 0x9D6A81F034FDDAD4ULL, 
            0xE3248485CB6DF2D6ULL, 0xB443933DE63B4948ULL, 0xC839A23DABB5F52BULL, 0x8ACFE51E26599CA3ULL, 
            0xB54FE86B462E98EBULL, 0x1B59E900DBC9F964ULL, 0x9060C8951B050A0FULL, 0x0967435ABA674289ULL, 
            0xF0DA6044B4DD937DULL, 0x39899FED9D820FD8ULL, 0x107E6D254C3BD4BCULL, 0xA0B0B4A7B3A90A5DULL, 
            0xB44EF1170EB13AFFULL, 0xC23CCCA970241E59ULL, 0x77F23C0026157EBBULL, 0x7F9F64AB82E748C3ULL, 
            0x2D34F95EF3DA3B81ULL, 0x45E385EA3CDB511BULL, 0x43F4980E8145A8A3ULL, 0x0B4BE8D2C9AE87C3ULL, 
            0x77224EAC4FC7FB20ULL, 0x49A940DCFBE77048ULL, 0xF2569E25FD92DC4CULL, 0x800CCACEE442F502ULL
        },
        {
            0x78AAC0FA632C7286ULL, 0x200B741AC534918FULL, 0x0035C33D190A3F3CULL, 0xDA3F67DA7427B066ULL, 
            0xE0481085A572ACBAULL, 0xF43EA5E04E448761ULL, 0x1A9025B42BAC8C48ULL, 0x5D3A79774745D553ULL, 
            0xF89BA8D8EE372FD2ULL, 0x1CED4B59C97EF19FULL, 0x25F1243430AFD47CULL, 0x23A99EFF4E0377DBULL, 
            0xA97A45690224E71CULL, 0xF5D647069C0EFE28ULL, 0x514BE9BD29E3629EULL, 0x969F8FBF12273427ULL, 
            0xB38B2D78CDAA0A95ULL, 0x7AD5E34A54C3F8F8ULL, 0x26F306348A1DA2C1ULL, 0x26EF94CB937EE64DULL, 
            0xA6AE21A167FE48A8ULL, 0xA1C21FD0626CA4D4ULL, 0x24CD679C85987286ULL, 0x0750DE5B2FE8D8E4ULL, 
            0xCEC0D80FF9C1B6F8ULL, 0xC44259A133136D0EULL, 0xEC5D6AE27E9641C2ULL, 0x22B1045996D22E2FULL, 
            0xA72ABBFF3D28D696ULL, 0x2693F8A1F6D0F38AULL, 0x3650D4A866C26D93ULL, 0x4E095144C3A714F7ULL
        },
        {
            0xAF4BA940B3601B69ULL, 0xCAE470F7B2C98D61ULL, 0x6560E252EC88B7BCULL, 0x63E5E73AB08CE003ULL, 
            0xDC04750427574757ULL, 0x19CF46620CE48775ULL, 0x6B1F002E0D837FA3ULL, 0x3CBCD82FE1EF6A61ULL, 
            0xB15782F547CFDB92ULL, 0x3426B000238BD3FBULL, 0xF809F8DC1A6AED7DULL, 0xA6BE4B324388EC82ULL, 
            0xA005FF76A51A38D1ULL, 0x9925180D25F78F08ULL, 0x16311EFF2B069346ULL, 0xD65DD31FEF8153F0ULL, 
            0x031E9E74A8F1EAA5ULL, 0x53807CDB89D0EC5CULL, 0xED7492416171B344ULL, 0x28CCB57C05E6D8C5ULL, 
            0xF761C62C04625284ULL, 0x5351F9D743B78787ULL, 0x84F7CDBE22A83820ULL, 0x8ACFBF3EE88CB9EFULL, 
            0xFA6CE6CE47287E26ULL, 0x5155871FFEBE7D1FULL, 0xB5785C923A3B5B44ULL, 0x03BD9CDE611FD023ULL, 
            0xB14D55776489BD03ULL, 0xDEF2DDBE05525005ULL, 0x1A74AC0264CEDEB3ULL, 0x9DEF2CE0D3F9F792ULL
        },
        {
            0x86305366ED68696BULL, 0xF7E67BDAA8AA951AULL, 0xE988177638E8FEB2ULL, 0x2357D3810B12FD07ULL, 
            0x335BA977D8BBFE23ULL, 0x07589126F60BC3D6ULL, 0x83CA55E96EBF9B86ULL, 0x6578A00BEC11C18FULL, 
            0x54A9C5FE76871608ULL, 0xC9D1744BEA20E45BULL, 0x05DB6B86BE876C78ULL, 0x70AE0B29F2178804ULL, 
            0xE6243EFF34174A62ULL, 0x79C0FAB45920FEABULL, 0xE558FE4D1370DA41ULL, 0xE43393BD18D4776BULL, 
            0x2AE10743D6D7201BULL, 0x79E21656A978CBA4ULL, 0xDEFF794293186795ULL, 0xFFFE6CC0D2C92F1AULL, 
            0x385F44E36D1D534EULL, 0x77A6B8977809AAFCULL, 0xDB62548232847B71ULL, 0xD665D74B59ECEBF5ULL, 
            0x1A5EC0A5FE598A83ULL, 0x9FBEE10F3AF559C2ULL, 0x7D164E495A3D6D96ULL, 0x1A072E31DEB9BE4EULL, 
            0xFCFC213602A187FDULL, 0xC8D5A2E1BB9BFE3CULL, 0x6ADA0F71E5A038ADULL, 0xFC8C959D8E7E2EF0ULL
        },
        {
            0xCF94717EBE0F3A29ULL, 0xB581408CEAB9B72AULL, 0xE9D1095798EA8D25ULL, 0x4297ACB20C1C636BULL, 
            0xAA921B92587081D3ULL, 0xFEBBE200AC35117EULL, 0x71BBB1F509F89AA9ULL, 0x38680783FB276FC8ULL, 
            0x4721A1712C3A0618ULL, 0x5280A5778102E41DULL, 0xC66F3C5A9FA85341ULL, 0x78EFC0798CD984B2ULL, 
            0x53D11A5F14AF8842ULL, 0xDAA10B99A3C5FC55ULL, 0x2BB04BFDE472DBC9ULL, 0x0102B886EAB60FBEULL, 
            0xD321F472756E1487ULL, 0x27EE9187FE84FAC4ULL, 0xF5954C845C52F695ULL, 0x40F298F8016FC365ULL, 
            0x387603AEC3F57B12ULL, 0xB999F61FB6AD6B37ULL, 0x2FEA9C081A4D94FFULL, 0x78BCD089C74D24ACULL, 
            0xFDEAF06AC9A01FA4ULL, 0x5D7101DA42ED630EULL, 0x578E8C87F6969BC8ULL, 0xEB46EB9B675E122AULL, 
            0x017A0B0A01DD42C5ULL, 0x9BEC5C4BA20295A8ULL, 0x30946D00F1C2A6CEULL, 0xDCEF314ED1A339BDULL
        },
        {
            0x1DB757D3DF8A5DF8ULL, 0x8BD7605999B6609BULL, 0x65E6954C3846A0F9ULL, 0x1DB7B91AE496F858ULL, 
            0x460D71330D8C5336ULL, 0x865562E70E711E8FULL, 0x6128EE3AD7C247A1ULL, 0x004DE6A1C282AF88ULL, 
            0x059122DC6F843E04ULL, 0xEB489E757E872F1FULL, 0x89B00D543495F53CULL, 0xF07EFB86E0693021ULL, 
            0x32AC5C78542CAD64ULL, 0x52D6C8C8000ED8C0ULL, 0x3538446C91FEE905ULL, 0x1CB1DF05CC7DE8FBULL, 
            0x855C576BA2C27E8DULL, 0x43C4FAD5CD451385ULL, 0xD246BBA80B93FDB6ULL, 0xE2EDC57BADEECE2CULL, 
            0xC78F208433BD1D56ULL, 0xA6B174353A1E834EULL, 0x65FF290FDFD14184ULL, 0xC5FDBA7D1D036A72ULL, 
            0xF9615EF76E815D5CULL, 0xA6A833005DCB5CB3ULL, 0xB9D690C8A8F1C39FULL, 0xF9F98E2184A60F6DULL, 
            0x032A7CE52F30C776ULL, 0x6C7EF69D95D5D7E6ULL, 0xC900F9C9EC91B61EULL, 0xE740956E0770BA1AULL
        }
    },
    {
        {
            0x31E7417112CD0E0DULL, 0x47D9AA3F93EB4436ULL, 0x4C66181C0E8CE3EBULL, 0x283A36EE059BA1A1ULL, 
            0x1C4863E66EA64CADULL, 0xED99B7C1BCABD55EULL, 0xC1D1675650DFEF02ULL, 0xEA4A02361FCC84B6ULL, 
            0xA03EDFD3A8985E08ULL, 0x9E1C95DA89AA6AE4ULL, 0x76931345601D62A8ULL, 0x42DBF3770F1DCA8AULL, 
            0xEDA712C7960D1926ULL, 0x7FE26F5536F72D65ULL, 0xE997F73A4CA185D0ULL, 0x4F4A12F763778740ULL, 
            0xA07D18B6B05C2CAAULL, 0xF1B8201B6F10F756ULL, 0x32C7AA0BA646859CULL, 0xE9CCE286AEEBE48CULL, 
            0x20E35F1FFB8D4917ULL, 0x5A3BCB2A3D558165ULL, 0xF77FCB9B0FCDB521ULL, 0xC161BD0B0209D450ULL, 
            0xD84309CD6901EE5BULL, 0x49BFF46656619C92ULL, 0x4DDB83EF4CD87690ULL, 0x8850100F72E44133ULL, 
            0xC18324E8F41AF58AULL, 0x88FAC11F7A552DD6ULL, 0x069BCAC67F63AB98ULL, 0xCA46F56E6D076A50ULL
        },
        {
            0xC32D2E8A3AEAD4DEULL, 0x7A271A9FEB8261EBULL, 0x91B9DE836B1A7CF8ULL, 0x7806F9507A50FB89ULL, 
            0x85910513416984A1ULL, 0x6F76E6D2640A27BFULL, 0x2D4735B94C4043F6ULL, 0x551C177567BEBC77ULL, 
            0x614BA17A5F32C178ULL, 0x61C163DC26CE71F7ULL, 0x3E276D2CCCFEF931ULL, 0xA24059BEE295E3A8ULL, 
            0xFA4F048B68B10509ULL, 0x220EFCCA49E803D1ULL, 0x07D6429A1C19F2C9ULL, 0xF3A5F1DEC291ED9CULL, 
            0x13A8D4B709F5D5D9ULL, 0xD9761987BEA0E1FFULL, 0x4DD6B5CFFB8BD29DULL, 0x94B430ABCA048AE2ULL, 
            0x7DD103E8A3D388A3ULL, 0x8426236BE16BEECDULL, 0x18F26651882998B0ULL, 0x665C4451E81C4313ULL, 
            0x38BC642744611A4FULL, 0x6EF63D46A6191EF3ULL, 0x4927CD482D720B46ULL, 0xA5EAE034393C8B8FULL, 
            0x9B6E9CBD93E97B18ULL, 0x6E3C0CB8E38E7231ULL, 0x806DEFFDE10B0F2BULL, 0x44EBCDBC9D1410BDULL
        },
        {
            0x1DA03BF90D3CF510ULL, 0x7654148E4D98F3DAULL, 0x8C855CDD262E7998ULL, 0xFED01FB3416C6C51ULL, 
            0x0D715F852576F550ULL, 0xC6A1C90C16C14B3AULL, 0xDC66576A5DAE007EULL, 0x9CD9DA616F005404ULL, 
            0xD09166602BFB1E35ULL, 0x602E09D0E4C36E56ULL, 0x2C67531D0E334326ULL, 0x89A82DB99B97EFA8ULL, 
            0x22937FAA1996A97EULL, 0xE9B2129B43CF08B1ULL, 0x2C11B46280EB68F3ULL, 0xFF415EE7DDEE3AFDULL, 
            0x826805D8FA6FA770ULL, 0x70EDE84217E1070DULL, 0xE4A4C9E002497AA9ULL, 0xF10AF4CA1C5396B6ULL, 
            0x3D22666604B8DD09ULL, 0x9E7D94F5E1961775ULL, 0x24B1513F69540028ULL, 0xE9EAE95B35E00CFDULL, 
            0xD11C03F306F85A88ULL, 0xBD8F8CD5D7DDD523ULL, 0x4E8CC60B4FC7C6ECULL, 0x5BA2F400DA0DDE9CULL, 
            0x51F4D6FCDC08001AULL, 0xCB2D3A22FB34F5A0ULL, 0xD6259BDB0AE3A5FBULL, 0xAB804D39D8F855D5ULL
        },
        {
            0x8C008E9EE93E6750ULL, 0xA783F2E09E08B2C5ULL, 0x25C3332C6EAD286DULL, 0x24CAC56A6294FE59ULL, 
            0xB8F4364790091867ULL, 0xA591C00C7315EB37ULL, 0x75FCF45236C9B0E6ULL, 0x7C55C8D5F7B61AFCULL, 
            0x633130EA8D5E8D00ULL, 0x598DDA607BA40E9EULL, 0xCAAE7012A62AEE16ULL, 0x5FF1A5701CC80C5EULL, 
            0x62F989B4E7FF33E4ULL, 0xCB37B7BF426FE773ULL, 0xD444B0F2E9F85593ULL, 0x13A3B53A370FFB82ULL, 
            0x451CBF0CCD4872E3ULL, 0x393751DCB0F75475ULL, 0x695FCE86A475AD0FULL, 0x6D05A28DBD3F90CCULL, 
            0xFF7CDBAB843EA7F2ULL, 0x4CCC3BE61AC4E777ULL, 0xC26B06F186EEA726ULL, 0xE43CD4CC384BDE1AULL, 
            0xE39C924BAFFE5D3AULL, 0x566D5A03B91B1C86ULL, 0x398B60A84A540CC4ULL, 0x07D18776255862FCULL, 
            0x89ADCCB8381DD168ULL, 0x28A3872206223B35ULL, 0xA41DE19B21711B13ULL, 0x29105A78BEF1E826ULL
        },
        {
            0x06E61CF9134D06CEULL, 0x42EE9FFD24886D96ULL, 0x69FED9A52ED3A764ULL, 0xE71D407AADAF6FEEULL, 
            0x4E15EE59A1839DD9ULL, 0x07CC90EDF24EA705ULL, 0xEFD2B6A61FA78469ULL, 0xC52E5571BF97ACC8ULL, 
            0xD6A3C8976B8AC763ULL, 0xB9861384829FAFBBULL, 0xD9CFD4368B9A70F9ULL, 0xA3F21FA65507CB5FULL, 
            0x1AC4DEE7474AEE63ULL, 0xF10D75AD3B696FE8ULL, 0xBEAAFEF090952573ULL, 0x331B5A0E7E530203ULL, 
            0xFFE9453DA66B42ADULL, 0x1E77E49F07528854ULL, 0xCD7CE3511B011E17ULL, 0xA701153C16A385F2ULL, 
            0x95031999212ECAD5ULL, 0x3272B86ABFDF66E1ULL, 0x6AD2C8C3C08007EBULL, 0x2C02F0D2B0982C8CULL, 
            0xE0C5F18C051E2267ULL, 0xB9CF2791A05A396BULL, 0x2C622D8BB2DAEBBAULL, 0x2C0598C5B1D3B822ULL, 
            0xB8123DA27C5906D4ULL, 0xA8CF2A4979F97786ULL, 0xB99E7AF77F03B2B1ULL, 0x54417A02551FDFF4ULL
        },
        {
            0x6CF32CFBF49C41AEULL, 0xE8FA9FF62E9A852FULL, 0x4CDB14F53A07D8D4ULL, 0x6D9DE4E1975D851DULL, 
            0x55DC14F69E71AB4FULL, 0x4C17A81344A6C0F6ULL, 0xC4D2872B49846CF7ULL, 0x74055A29C39F5AC7ULL, 
            0x8F504824151EDB60ULL, 0x1DF178186BB2B3CAULL, 0xAE87C298724260ECULL, 0x7F5BFCE5D2188191ULL, 
            0xA5DEDFFE0778C68CULL, 0xD73676C7DAA757DDULL, 0xB23549F0024549E6ULL, 0xBE7C4E20085F88D5ULL, 
            0xF4158D747EB21D10ULL, 0x0B46D86D869A5D83ULL, 0xB3369898332CD676ULL, 0xC044190936A951E4ULL, 
            0x5D21E06678783C9AULL, 0x4F55D186DCAB8AD8ULL, 0x511C175B60A10FA2ULL, 0xFA5B50FF3258CDFEULL, 
            0xE9DE6860757689C6ULL, 0xE8F341CC5A8DA4E5ULL, 0xB142807BA36DE5ECULL, 0x49D93DBC14D01BEFULL, 
            0x6D0799C38D36044AULL, 0x691DBB23DDB0BFCAULL, 0x233C3E0BC07E4FC7ULL, 0xB749D5EEC9999F25ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kKeySpawnBConstants = {
    0xCB31F72327D65F46ULL,
    0x9FD06483C45B52F3ULL,
    0x0693DAC509B9FC61ULL,
    0xCB31F72327D65F46ULL,
    0x9FD06483C45B52F3ULL,
    0x0693DAC509B9FC61ULL,
    0x438F086CB364A0FDULL,
    0x1F713518953CE116ULL,
    0xF6,
    0x50,
    0xDF,
    0xFE,
    0x55,
    0x7C,
    0x30,
    0x69
};

const TwistDomainSaltSet TwistExpander_Canopus::kSeedSalts = {
    {
        {
            0xD26C12E1FDABF4C6ULL, 0x5423FF687246C4E8ULL, 0xB802946F15BA5D91ULL, 0x59CECBF94299D9BAULL, 
            0xD9C35261E7567E2BULL, 0x44D00971E0E3A331ULL, 0xCA283DA88CB9325CULL, 0xF9CDB6307DF2DB73ULL, 
            0xD691E7EEB160DBF9ULL, 0xC9EDF34E4CBD6727ULL, 0x6106967F6199F308ULL, 0x16E9856B7D65AAA8ULL, 
            0x161B5878E95978F8ULL, 0xF802EFD82691D20FULL, 0x3F5484AFD7204066ULL, 0x16126FD114951E65ULL, 
            0x69C8E315E11AE4DBULL, 0xA36500CF77AA49D7ULL, 0xF0A0E6486BE627E6ULL, 0x675188F9B5144C17ULL, 
            0xD3B335E55EC1CCB2ULL, 0x6ED043C07549007EULL, 0x0378CB3FEE0FA2ADULL, 0x8666486DE2359676ULL, 
            0x9FDF08751A9A4C6DULL, 0x710A964A3954011CULL, 0x5F9A180C421F366FULL, 0xBEF7D7243AE34D02ULL, 
            0x6FFBF10C11CE7627ULL, 0x381599CEF8F6BC46ULL, 0x05164E7CD6860530ULL, 0xB594EE2F0AAA94E0ULL
        },
        {
            0x31EBEDDED9FB189FULL, 0x469B6AE48BCB8D50ULL, 0x37515B6FD056F410ULL, 0xD3595AC58DC1FA3AULL, 
            0x473B21C2E6FAB0CCULL, 0xA055D0B6DEB8E1F7ULL, 0x969F5B853C28EA31ULL, 0xEB8AA9CE118DFD22ULL, 
            0x15617F582159B68BULL, 0xA729994904B2A4A5ULL, 0x136FB8F8E080CC82ULL, 0xC7179AAEEBB52C59ULL, 
            0x68E724D45ED6E7B7ULL, 0x806EFA8558F2AD02ULL, 0xF66E22C3BF4735D0ULL, 0xF25AD4EE53D639F3ULL, 
            0x334AF9B24A874DA0ULL, 0xC84B1173F3BF6EFFULL, 0x4AAEE1A165531938ULL, 0x0BB75C04D9F1DDFEULL, 
            0x21B643B8CD309E9EULL, 0x219FD790E1C24B8AULL, 0x522085A26EF46422ULL, 0x2EC0FD2C8796A681ULL, 
            0xAB0DE13520B2700CULL, 0x0377415E1688A3DEULL, 0x1E9E13911D757A75ULL, 0xEB6741C244C0CFA0ULL, 
            0x84DB4FC6C3F7C052ULL, 0xC6F099ADC9BC85F5ULL, 0x12D84D0391A378D5ULL, 0xDFADAC6BB8A2F78FULL
        },
        {
            0xBCF9099AD5B22A95ULL, 0x1A5611A94139F9B7ULL, 0x45DA6D85CD551EB7ULL, 0x441EECDDE1AA8668ULL, 
            0x9C5F5A4C2038761DULL, 0x8822FD078379A2F0ULL, 0x320F18099AE0B344ULL, 0x1FFD9146D30CAE6BULL, 
            0xA7489128180819F8ULL, 0xA0DC273B34F5C790ULL, 0x18338866C5175E96ULL, 0x15AF0A7B30945C46ULL, 
            0x07EA8810E7EBE41CULL, 0xF64BBCCF52A078E2ULL, 0x0336D59908E23A10ULL, 0x311D3B4BAE284E01ULL, 
            0xFDD520FEE121499AULL, 0x8C7D178E83D4CDF3ULL, 0xC0DD37E461F12A22ULL, 0x59E204C0AD4ED9ECULL, 
            0xF1457FDC6FD10FE8ULL, 0x5E7EDB3AB429F0A9ULL, 0x3A0ED8CAD186C3EFULL, 0x3CD9B68294B7490CULL, 
            0xB83202FC5E1E8651ULL, 0x1B9E94C851B58BBEULL, 0xFA720371025B3849ULL, 0x7C2C623361B53B13ULL, 
            0x9810FDC958F12CF9ULL, 0xDC0FBBA4C59C64FEULL, 0x063592A9273C7A9CULL, 0xFEB5854AAA9B8F47ULL
        },
        {
            0x369FB67E15568611ULL, 0xCCE03E17186D3BE3ULL, 0x1B557C15D1BB6242ULL, 0x898BF701E7772475ULL, 
            0xB09A096EC0647AA2ULL, 0x7DEA4AA1A7BAB643ULL, 0x0D347DDD23B623E2ULL, 0x9D224A5EB7236F5DULL, 
            0x797CC6E46D14BBFAULL, 0x3D5F894D0A0B08EDULL, 0xFEABCEBD87C96C8AULL, 0xCB206396B9E5830EULL, 
            0xEAFF6E15C60969F4ULL, 0x2DEE2B25B0403920ULL, 0xC9B25EB6BAB147F7ULL, 0xF3CC399A6DA38A29ULL, 
            0xC3CE91CB2CFD6BB0ULL, 0x6E5E653FF9733141ULL, 0x92D613198ABDA901ULL, 0x601CF1087F6C586FULL, 
            0xB19364320C56CE29ULL, 0x7E5467F973C0BAF9ULL, 0xF8D8A82B4209A6EFULL, 0x7D81347BE35B6CFAULL, 
            0x9119E638407AA601ULL, 0xC1B06BC2F2495A50ULL, 0x3B08CCEF2C72B2C9ULL, 0xF4255984529D334CULL, 
            0x1BA4F887924BE141ULL, 0x117B9E1BA5F52E4CULL, 0xACB17823CC91C687ULL, 0x46881F3F96EE5124ULL
        },
        {
            0x55B100AAA487ADB3ULL, 0x1ED6CA9BD19D7DC1ULL, 0x43AFCB1A2BB6F702ULL, 0xB7EF7F8602285430ULL, 
            0x310E29839795D7C3ULL, 0x6FFDAA1ADB68EB1CULL, 0x68E4E559E090A906ULL, 0x05D28F8445E40574ULL, 
            0x6564D95EBF6E81F5ULL, 0x24CAA9760A02B5B9ULL, 0x7D1703F575C1F4FBULL, 0xA30BBC190C5A7E4BULL, 
            0xB338EABCB6F94621ULL, 0x023378DC555AFA55ULL, 0x8AC57AF697CF0258ULL, 0x11A13A996093E7D4ULL, 
            0xB5EE57C58E1F5690ULL, 0x597D84002561E23EULL, 0x5BF10370D12646C2ULL, 0xA9BEA3F3CE07BEACULL, 
            0x32CA589D4B2E150FULL, 0x12090505DB6E576FULL, 0x85BFE9DB7A16E7F9ULL, 0x23D00319FE1B98D3ULL, 
            0xA68F25E6C8B46FC1ULL, 0xEDE04C1B5AC6118CULL, 0x616497B02F299375ULL, 0xE0A4782CB0EB9AFCULL, 
            0x06F761928E2CFDA6ULL, 0xF3765985A737468BULL, 0x9F2040BCB9C3EA1BULL, 0xC7B8A6216C10232BULL
        },
        {
            0x5A2FC13BC367067DULL, 0x245F510F25593AC4ULL, 0x0C29951146865B07ULL, 0x5C8486FB6E0AB875ULL, 
            0xD58A20C1B583C564ULL, 0xB3F2E85100B8CF06ULL, 0x3C9A6818BC4391ABULL, 0x3AFD7615ADC437F0ULL, 
            0xB0FD0327F5219AB1ULL, 0x9BBD517C5F5E5194ULL, 0x93F0B384A6472F8FULL, 0x68214C85418DAD22ULL, 
            0x558ADD159358B061ULL, 0xE632E7CC9521158BULL, 0xA6B57E209723301EULL, 0x749C77315B40C541ULL, 
            0xDD8988AAAE02C2FCULL, 0xD76EF306342BF58EULL, 0xFF03C2CB44D0A612ULL, 0x63BA73354A20E7A7ULL, 
            0xCE4A2D61929038C5ULL, 0xEF0876E800720340ULL, 0x82C277C130089D86ULL, 0xF3FADBB5C0227953ULL, 
            0xBDA77D4B7F3153D4ULL, 0xCAB7A11E6AD201D4ULL, 0xF8E23AE137AAC974ULL, 0xDD4B9C7720B2AD3BULL, 
            0xF75A38067F0292DBULL, 0x9C888A3D7071E7D9ULL, 0xD672CA38539F5D4AULL, 0x68382B020E70DDDBULL
        }
    },
    {
        {
            0xA6CC560F202D131EULL, 0xFB3F492EBE85C52AULL, 0x20E9B97A6132C055ULL, 0x7F7997CF52CD2D4BULL, 
            0xB2C1E9F0DF0A2111ULL, 0x037C9B240DA1B9A9ULL, 0xA14D50E80F81DC79ULL, 0x4F478CEEAC3DD50CULL, 
            0x1351024F983896B8ULL, 0x37726EF7C06FD550ULL, 0x17B44E50A06F97ACULL, 0x69E0A58E477DB992ULL, 
            0x24005539E31C3C38ULL, 0x048AA94A54C3F0AAULL, 0xCF6943C8E876DD5DULL, 0xE2C241FEEB000732ULL, 
            0x4C5EE8AA5F69810AULL, 0x9D3E5CCF76837881ULL, 0xBFEB36F84AB66FFBULL, 0xC94068C5C0F7B12BULL, 
            0x77CC9D5668A074B1ULL, 0xA30792EC190C2748ULL, 0x5E2EC454C82AAC4DULL, 0xCBCA64F8CAB727CFULL, 
            0xA47CF4E495F5844DULL, 0xD95CE91CFB98CFD5ULL, 0xF4AB456ED80027D2ULL, 0x6CCFC77325BA829EULL, 
            0xF042D8B9E0C4564AULL, 0x91E22596568BF338ULL, 0xA76534ADD5CF37F1ULL, 0xB4502B85AE4EC105ULL
        },
        {
            0x1C5D7937F56A58A1ULL, 0x18545CD7306F30B7ULL, 0x84BFC47F2034A4DAULL, 0xB01F82C9F15817C6ULL, 
            0x28679D1460684B82ULL, 0x93C5EF42BFAB0E52ULL, 0xAEE224D963DF8A3AULL, 0x697E7B223B9542BFULL, 
            0xF08D5101F377EEE1ULL, 0x4E48BB60E068395AULL, 0x35595FF22611477DULL, 0x17719F480185DEAEULL, 
            0xCBC810F6309287F8ULL, 0xBE12AF709DB5718EULL, 0x0AB96FC736BE7163ULL, 0x1C3DA69B15D7493BULL, 
            0xA7C7F0630D1CE4ADULL, 0xB6DDFD505260F1D8ULL, 0xC5B057D67A350FCBULL, 0xAACE72C54D344327ULL, 
            0x1DA4B2DA6F7A5B9AULL, 0xDAE9BA75B4B4EF05ULL, 0x35178E3216278D31ULL, 0x6214B9FE067E92C9ULL, 
            0xED4FC2507BB4FB1BULL, 0xCE33DB1D46D717FEULL, 0x44CF83174F042491ULL, 0x8E09CCD7B201BBF6ULL, 
            0x5BC02008A766056FULL, 0xD5DD42C833F1981EULL, 0x06AEE0C80BF37608ULL, 0x75801FB9E257ACA9ULL
        },
        {
            0x311587EA1A4587BAULL, 0x71433CB7E9EA4A91ULL, 0x5F0A49CD220A4C09ULL, 0xF6A8547D0D3E208DULL, 
            0x1F8F79DBCEFC461FULL, 0xAFED8E94925A3BECULL, 0xA9CF60AFA730FB47ULL, 0xF7B331164C9EBA98ULL, 
            0x0357CF008BBFB32EULL, 0x3C4184DBB0A4695DULL, 0x6189FC3475E6ECDFULL, 0x93C7C9C2BE8DE91AULL, 
            0x0B0EC53B4E4AEEEDULL, 0xBBCDD19C21945BBDULL, 0x56AD24CD8B106A38ULL, 0x507B87A034A6A196ULL, 
            0xBFDF4FA90ECC1990ULL, 0xA748AE23B5D6AB2CULL, 0x48530B5B4C5656DCULL, 0x371DA6A136FDB786ULL, 
            0x81A35EDB1854054BULL, 0xC9DA94BE583171DEULL, 0x4C27C18F3CA0F929ULL, 0xC95CE0D3772C6990ULL, 
            0x148C376297F9A313ULL, 0x9CAAA9AF1F65C50AULL, 0x38929C8CCF2E5C99ULL, 0x68AA26820F5E110DULL, 
            0xFB114FDD18372B0AULL, 0xAB28AFDD7B7F6CEAULL, 0x43C22E00BD9E7F0EULL, 0x6CA3BA34C4F049EFULL
        },
        {
            0x8C1211BF0846FD86ULL, 0x9C5F8E082FA286E7ULL, 0xD03310D7626B5F25ULL, 0x85DD90BC64570294ULL, 
            0x59BF5E68717C49A0ULL, 0xCEEA33FBF4F601F1ULL, 0x42262B2D962875ECULL, 0x39EB894EA9AE11E1ULL, 
            0xA6026EC842371A8BULL, 0x40921ABB7C215F61ULL, 0x4E0FB801E35481A6ULL, 0xBDBAC6C03BC016BDULL, 
            0xD9AEA13AEFB0BC27ULL, 0xE53E1D390D4BB731ULL, 0xEA3569035E7B5291ULL, 0x057DCBFC8B6724C5ULL, 
            0xF9AB8E8E3B985AD0ULL, 0xEE56BAFC3E6BE3B7ULL, 0x74B2E66F90F3EA6DULL, 0x18E6E6034ABB7706ULL, 
            0x4C1728FAEDEDC0F4ULL, 0xEFE1E74D01375402ULL, 0x77505AD0DBD2C484ULL, 0x401D0BCADB9F6E73ULL, 
            0x457F77E9004DDEB1ULL, 0xB71CBD11371182FFULL, 0x47E2F77BB1AA5AB4ULL, 0xCA2EAED8E7840A18ULL, 
            0x24DC76B00315053EULL, 0x7FB2B147C2442E6DULL, 0x2673EB5ABE485434ULL, 0xB499BD213342C580ULL
        },
        {
            0xF6FEE5C159FE5647ULL, 0xB73E3FA0473B5B6EULL, 0x6385836DB906927BULL, 0x1E784CEE8A728D92ULL, 
            0x0624FAB21F67F4B5ULL, 0x3579AFD4DCCAA25DULL, 0x564B45CAA362A1FCULL, 0x10C0A304C5E8DB52ULL, 
            0xC1252CCED895FC10ULL, 0x682E75DE7E3E10BDULL, 0xF7335461CAAF5F93ULL, 0xF617F64BEE1893FEULL, 
            0x15F3368C24C485F5ULL, 0xFD24097D156EEF25ULL, 0x5574E78B60696D6EULL, 0x4BC0E90924023309ULL, 
            0xD7EDFFE491129642ULL, 0xB99F7F217BFC4068ULL, 0xA5B0EC315E8451CCULL, 0xEF432D7787769EF0ULL, 
            0x494F04B5FC94C0E1ULL, 0x1007B7FFD22AF855ULL, 0xA8F342A00B80F4C0ULL, 0xD7F39E10EC0A6429ULL, 
            0xB18ACDE56F28D017ULL, 0xA75F5F6DA77ACDCEULL, 0xCCA3E0646B3C63ADULL, 0x1FF28E3CD97AC89CULL, 
            0xE41FA3AB10B8C61CULL, 0x65A99562BF1A2CF8ULL, 0xD5BCCF8FCDB7663DULL, 0x510E6356AB367263ULL
        },
        {
            0x304C2858B9D5C2F1ULL, 0x9E4E7CFC413947B1ULL, 0x9501E28DD61018F0ULL, 0x7E86C34C6CC3EFE2ULL, 
            0xAD312B3B1C08FD25ULL, 0x638F7B8C202CDD3CULL, 0x424776B26DBF6EE3ULL, 0x2E0346B6FDF65F7DULL, 
            0x59CAA9CD47F1A966ULL, 0x920B719F7A8B3DFFULL, 0xD312E813B0779A2CULL, 0xDC25C20884DEC36BULL, 
            0x6098D721F0264390ULL, 0x8E92815222D6DE0FULL, 0x915988AB0F5A57AAULL, 0x6F0A145238450631ULL, 
            0x79FACDE43C5A4425ULL, 0x56CD701C69F7B138ULL, 0xB28784F1CC59515CULL, 0x87127EA6778D7561ULL, 
            0xDCD9346E66A41BF1ULL, 0x8537984015482FD1ULL, 0x7BDB7F7C094C0E57ULL, 0xDEE835D064E3DB17ULL, 
            0x7E1AE91F8F1DE0D1ULL, 0x74D8142AAE9B70B0ULL, 0x1EED667B16A1685CULL, 0x7D2B2D0354CC8935ULL, 
            0xA12F24D4D0AD9F3BULL, 0xB0090ADF68F82999ULL, 0x098B04EFD1B49220ULL, 0x0EBC18CFF0F8E65FULL
        }
    },
    {
        {
            0xDFB61646E9AA7E7DULL, 0xBFD0080AF4C1C2ABULL, 0xEA4442C4B9A07988ULL, 0x05DCDD8FCBB2C342ULL, 
            0x3BB04B33A930EFDAULL, 0x53BE38C7616D6D76ULL, 0x70146CEF862BEE2DULL, 0x0E6028DE3FAE7D1EULL, 
            0xCA7A2A7252364858ULL, 0x17B5C3B076925F45ULL, 0xAE802694FB8E0FC7ULL, 0xD0F5D65FFD98F217ULL, 
            0xD49184708FBCA97FULL, 0x065A54F6E886C3C3ULL, 0x0852B6AB14D8C1F7ULL, 0x98A419EBF39D8C3EULL, 
            0x98FFC49EA1E624CCULL, 0xB173A5DE4AAF12D7ULL, 0xF63560180D56F8EDULL, 0x5FABF30DDB801146ULL, 
            0x0FE093BC155A2704ULL, 0x67AA64ABA63EDC2AULL, 0x24D1A5D52D071392ULL, 0x81B01D9C419B75C7ULL, 
            0xBD2DD5B023252D5FULL, 0x7274B5BBFDF4D20FULL, 0x6BF9FA699A092889ULL, 0xD09D213E4FFCC985ULL, 
            0x56045A41E4A22B45ULL, 0x07D73BB146986375ULL, 0xBCE0CA30FC426A9FULL, 0xBE278A7352C3FAA5ULL
        },
        {
            0x4DE1C00A5D0984B6ULL, 0x7C98C360356A99E9ULL, 0x5EBCF4C1DA980403ULL, 0x21C78F83CF9C7025ULL, 
            0xDFF09D59B72DEA91ULL, 0xF415CDE3A71C1222ULL, 0x2261E5624CCDEBC5ULL, 0xCFCB01BC604AD6C2ULL, 
            0xD10F4A9299843692ULL, 0xEAA2F69711C7C9EDULL, 0x0B0D5240E62B184FULL, 0x14A2F910FE85A0FAULL, 
            0x866D8D3E043D1AE0ULL, 0x71E0CA87F5A368B7ULL, 0x18FBF8563613E57FULL, 0x0B3939B100FA9220ULL, 
            0xB629CA4EAEAF8E57ULL, 0x1B9D597D6F43B870ULL, 0xC5668F122D8851A8ULL, 0x78F8461F0ED02DD8ULL, 
            0xDA4E20CBEE25A480ULL, 0x9A5F722EADEDA958ULL, 0xA4839A8001FF0FAEULL, 0xC78BFFFF888EFB06ULL, 
            0x8C858E26AD4310A2ULL, 0x233C4E8DAD2A009CULL, 0xF67AB685745DFEA9ULL, 0x5DA0D6190499720AULL, 
            0x38705A735AA31CD8ULL, 0xAB007EB4B3E9E21CULL, 0x5F6F379D9E1AB93CULL, 0xD66060C993CFB7E8ULL
        },
        {
            0xD9474C2484467CFFULL, 0x9404D6781D724AB6ULL, 0x9D952EF1DBBB0938ULL, 0xB7C6356AFC2D78ACULL, 
            0xCAA280FC2A201375ULL, 0x2A3B3BA20C4BE407ULL, 0x0F324C6A51842B74ULL, 0xCB38028F7DEB779EULL, 
            0xA06394162224CDDCULL, 0x618ACF9370DFB85CULL, 0xA87E85CA5149DBB8ULL, 0x9AAD4C6F0FBCD277ULL, 
            0x90D30599C3FB71C9ULL, 0x8759E85FC52B0905ULL, 0x78A7FE517113B686ULL, 0xB644A230C285B6FCULL, 
            0x25D9AF46CEBDB0EDULL, 0x1082981D149F742CULL, 0xDD09688AC8517889ULL, 0x75B35FF0515FE8B4ULL, 
            0xEE53E046B443A569ULL, 0x9FFA4FC5C6FA0FB9ULL, 0x659FE98A4473C870ULL, 0x2BF52A044A2C100FULL, 
            0xA707BB074ADA213DULL, 0xD7A66FAFC5D7CF16ULL, 0x66A31FE54E7D0E91ULL, 0x0342C6F1639EE6E3ULL, 
            0xE664184556554EF5ULL, 0x4922282976FB7DE7ULL, 0x638FC817D688F8F6ULL, 0xDF9AD686E84B425AULL
        },
        {
            0x17E118279F592010ULL, 0xC08A49FEE98F10C4ULL, 0x89BD075CC7E993BCULL, 0x2B7668885B274C3DULL, 
            0x196B4A7F9B870D9AULL, 0x2E5969361719CAF1ULL, 0xF33F8C74B8E6B0FCULL, 0x9B1ABB503FA97DBFULL, 
            0xC25ECED18D92E97BULL, 0x1C1BAD1938B4550BULL, 0x24A6E7A4D45A527FULL, 0x0DA4EC8EBAA46CE1ULL, 
            0x4A596ADDE61E029EULL, 0x377F9D73E6D72C49ULL, 0x6C4B23D708D4B042ULL, 0x539F4777E35EFD60ULL, 
            0xDAA3041739949D0EULL, 0xA1280530AE5C1F17ULL, 0x44BA38DA656CD3F2ULL, 0x7D04F4F9EACC2543ULL, 
            0xA6F4C5414E36B98BULL, 0x7664269A6A3619CFULL, 0xA1C80F1B24F8FA2AULL, 0x7310E59BAF76E6BDULL, 
            0xD99C70481F73F840ULL, 0x96AB8350D11737C5ULL, 0xBABC6D396682AD6BULL, 0x191954DAC462ECC4ULL, 
            0xD433688F50FE01BCULL, 0x7C38CFD5F50EB72CULL, 0x3DA608A460E6F9E9ULL, 0x25E11D93D909EEA9ULL
        },
        {
            0x70F1369099673EEAULL, 0x4AA9342883EF3A0DULL, 0xC1DDEB138B4E2BECULL, 0x83AAD381B03B3BA2ULL, 
            0xF1D58A7CC0611EDDULL, 0xB94E76B1B4A82E0EULL, 0x073E432C1B2FB73BULL, 0x2BB5D0825E5F52DAULL, 
            0xB6FD5907FE2B4535ULL, 0xBDD2738B3C3D0EBAULL, 0xB0866B2E0A645648ULL, 0x3138DFCC97F4119BULL, 
            0xC780B3DE8EBB3450ULL, 0xC308B0F2D12898A1ULL, 0x26F71414A508BF11ULL, 0xAA9A7244D120CCA8ULL, 
            0xC902FD4BF38ED246ULL, 0xFC0F49B9D4A26590ULL, 0xC683842D8AE0AC66ULL, 0x3CC8F07D510BA601ULL, 
            0x3A093867FE99EBE0ULL, 0xC195ADB4139AA531ULL, 0x3D4DCD5C69C2DA3FULL, 0x57FB2DDDEE7A6898ULL, 
            0xB20A66104F60A5EEULL, 0x25CFDE6D7206A4C6ULL, 0xCE903BA39212A4CEULL, 0x536B07F024AA6871ULL, 
            0x688A842985F99941ULL, 0x69856BCF0D5F9EBFULL, 0xBCE18F593A704CD0ULL, 0x2C226742D16ACAA6ULL
        },
        {
            0xAB00FCA96B4542CFULL, 0x913DDF899F7D9FF8ULL, 0x42A162EFE13C947BULL, 0x3A6E95FFEF9B8D0BULL, 
            0x9AA8D44D722A0891ULL, 0x80B48B9BBBD613FFULL, 0x92825AE98D396767ULL, 0x814B875FF9A43D0AULL, 
            0x629B0D0136B68093ULL, 0xF6A1F1B4C00007EAULL, 0x1334E9AE666A4577ULL, 0x93D4876602AD3F9FULL, 
            0x64DB87FE5715B9EAULL, 0x2F1E62FB60FEF93BULL, 0x802F34EB290A4264ULL, 0x2AF69801C1BE9194ULL, 
            0x7FA652F5B852A120ULL, 0x721B97DB631B4E54ULL, 0x7C915D9B39C23A86ULL, 0xC57540070C719466ULL, 
            0x8CAE3F4B020BDC1CULL, 0x6494AA676E023BFEULL, 0x959B096BC7A488E2ULL, 0xF32E1A0FD4A7F93EULL, 
            0x158FF632C48C4126ULL, 0x48319E2ECF40BAD5ULL, 0x8C597C29983E50F4ULL, 0x39845CE80A865ED8ULL, 
            0x9AB5110B0A3D5284ULL, 0x0190EADAF0F3B38DULL, 0xAFD1C4979417F3D4ULL, 0x77BFE07608D0B651ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kSeedConstants = {
    0xBB2673BC376E8958ULL,
    0x2142DFAFC2860753ULL,
    0x5C90719B13D6D8FFULL,
    0xBB2673BC376E8958ULL,
    0x2142DFAFC2860753ULL,
    0x5C90719B13D6D8FFULL,
    0x7B1D1BD197E27C17ULL,
    0x8957D4FFC8D689AAULL,
    0x2C,
    0xA9,
    0x52,
    0xB1,
    0xD7,
    0xA7,
    0x7C,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Canopus::kTwistSalts = {
    {
        {
            0x4173FA5C1A0E0ED8ULL, 0xB81C700B093609E6ULL, 0x73CA446479CA05B7ULL, 0xABD26C80DFFE4F9DULL, 
            0x890410A3717A1A88ULL, 0x554E7E9DA9C95A2BULL, 0x0FC696101876FEB8ULL, 0x0E00EDD9A82EF7D2ULL, 
            0xA307BFFBF4F98865ULL, 0x8BCFA83813F1FDD0ULL, 0x9B94E66A0E3516A8ULL, 0x5DDB4546B77AC476ULL, 
            0xD87AE8CFA718863EULL, 0x14D3F794055E2E74ULL, 0x12FFE5988085AA62ULL, 0xBDC3390107BFBEBAULL, 
            0x2788C2EBAA124CD7ULL, 0x709C1947889BC893ULL, 0xAA1A7A78CD833B63ULL, 0x0223162CC18B970AULL, 
            0x5A1B0F12694E7ACEULL, 0x0AE699DC0C212525ULL, 0xE82F7FDA88109BABULL, 0x69E10EC5850D9C75ULL, 
            0xC8B5507F76973222ULL, 0x9C33E75E771B7A72ULL, 0xAC22F0051A1EAC18ULL, 0x2740FE33AA9384DFULL, 
            0xAB82494628671D7EULL, 0x80E6C6BE50C51E50ULL, 0x27E890D9BD701DE7ULL, 0x4F1664D484C22A27ULL
        },
        {
            0x6CB42E7FB161865EULL, 0x64FB551DA6894742ULL, 0x7304C6ECB6435BE0ULL, 0x0DB02A18E923CFE3ULL, 
            0xD4A6A5A3321168B9ULL, 0x776ADB1F06862A04ULL, 0x1AB724742761383DULL, 0x409601E0FB5BB253ULL, 
            0x4B04525F9B2A0759ULL, 0x40C3C1371A1ECF5DULL, 0x19839E14F45C9FCAULL, 0x6E660E2FAC57FCA8ULL, 
            0x16EA62C22941058BULL, 0x25C6FBDFF0D304CFULL, 0x4254CE5105504BC3ULL, 0xE8EB10BF7ACA90C1ULL, 
            0xA087061A25A762E3ULL, 0xC7C5F100A9F1FEBDULL, 0x52F89F93847ACA79ULL, 0x369A73FB50DAD6C4ULL, 
            0x0E167E92C69C52ACULL, 0xB8BACB3EBB13BB0DULL, 0x0453303AD9FDFEEEULL, 0x9356746EF3B375E9ULL, 
            0xD5F336A4533EB780ULL, 0xF833F8AD34A36189ULL, 0xA07C6074CFBCE371ULL, 0x7D88C96DD846C5FEULL, 
            0x5A82E1D28B842087ULL, 0xA03BBE1AF58DB845ULL, 0x4BAE722DA9358B00ULL, 0x8917C1046B383A2FULL
        },
        {
            0x0E411643AA61CC4FULL, 0x13AAE01D83DF2BF1ULL, 0x72095AF08089A23EULL, 0xFBBA5072DEB98855ULL, 
            0x88F403173F5AB676ULL, 0x997CFAA8DB9A13E0ULL, 0x6BA8E3B540495C01ULL, 0x9CC02CE23453F028ULL, 
            0x1A9341D37EA7A287ULL, 0x9D6271D5055B55D5ULL, 0xA778D7F9ADA6EA10ULL, 0x723E7E2F79195159ULL, 
            0x2FACDF8F8E73A3C1ULL, 0x1662C62A6B9AC718ULL, 0xFB821A4578D2FAEBULL, 0xD018FF3BC1088902ULL, 
            0x8E186A196ADEFBB6ULL, 0x5559B0B27A011C99ULL, 0x2F6EFE75E4B5F392ULL, 0x4BCA6C9DAE846990ULL, 
            0x632880168EDE2670ULL, 0x675A43FD2B7F79AFULL, 0x8D21234E882EC396ULL, 0x99D65E5702F351CCULL, 
            0x1F4C4439BF456696ULL, 0xF8A3BF71DA2C2658ULL, 0x29B5F6A49F38E0E7ULL, 0x8460B9DEE888CB08ULL, 
            0xBC10024236B2DF75ULL, 0xB90C42A641B24111ULL, 0x3C27FAF21E31492DULL, 0x79CC52019E57AEF8ULL
        },
        {
            0xFFEB1F23698A03BBULL, 0x5E43531D963FD841ULL, 0x363B5D13EBCF45F3ULL, 0x4BD891AF472003B2ULL, 
            0x539261730E61AF98ULL, 0xD8D695727E3AB3A2ULL, 0xD337C89BE9284E3BULL, 0xB4182D536FE96633ULL, 
            0x222E40C4137BDC0CULL, 0xF91BBBA2AF6432D0ULL, 0x2D47E4B31F3D8863ULL, 0x0417D614647E8260ULL, 
            0x35067F338F3A4927ULL, 0x6FDD161F74D4BFA2ULL, 0x6296151B3223A58AULL, 0x0358D6D89B70A5DAULL, 
            0xAE79D76417B92859ULL, 0x67C8594C127951D4ULL, 0x5740B0019D9570F4ULL, 0xD07D5706A3BA0D1FULL, 
            0xAA7E0A8AB714460CULL, 0xAC76664AF959CA09ULL, 0x7E64CE1D2B357E93ULL, 0x0510AE77DB9D9B25ULL, 
            0x9878852510C9A6A1ULL, 0x4FB5D4C398F48DFFULL, 0x3DB4C33EF3C5962BULL, 0x024411D079B1D2E7ULL, 
            0xC7F2C934CE48789CULL, 0xBAE350558DC9B7C4ULL, 0x656B62962C5CE053ULL, 0xD0A0DF33BF909F3DULL
        },
        {
            0xF716DE4F283E015AULL, 0xBF86967EFFAC349DULL, 0x3DE6A7DF0F99D812ULL, 0x0C82359EB9DB97A9ULL, 
            0x3E35AEB1A10FC22CULL, 0xBA4A30F5A8DD3E1FULL, 0xF34412F17BAA279BULL, 0xCCC2760FEE15D23CULL, 
            0x8843D88CAE15CB20ULL, 0xD9E7E72E5D72BEF6ULL, 0x1C65DC231F7314C5ULL, 0x2D79ED8EE4FAE370ULL, 
            0xB69C3082E1C75848ULL, 0xFDD735FDEAC9163DULL, 0x4029EC03A749F072ULL, 0x18F0A1A74C350CFBULL, 
            0xA72B9BAFB8065491ULL, 0xB0792CFD64AF377FULL, 0xA267AF97C6619D14ULL, 0x5DA11462AA196695ULL, 
            0x77D653EF03972334ULL, 0x40F935DD6DD14159ULL, 0x2F85E0DFEA4D2A67ULL, 0xABD1AFD09B3B797FULL, 
            0xE461367F0414D78DULL, 0x0D5F25DE01351E21ULL, 0x36DAC52399D541B6ULL, 0x5B173B1B15546333ULL, 
            0x5D1878A2C9AF7AFBULL, 0x7E68763293B3728DULL, 0x799332FE521E5097ULL, 0x38079BF0D292F798ULL
        },
        {
            0x0A085812394E1D77ULL, 0xA63475FD32681918ULL, 0xB9CDAD982EAF9A1FULL, 0x687F9408156AB633ULL, 
            0xF51E9AE3AFD4DB81ULL, 0xCCE4955A925F6807ULL, 0xECC4C6CC4C6693E4ULL, 0xE958E1CB95BC40A3ULL, 
            0x73CF252CE0DB45CEULL, 0x4DC486741F834834ULL, 0x81E3709B96913DAEULL, 0x9AFE64BC9B216BE3ULL, 
            0xA50BF5C0E193A3B0ULL, 0x2281FA93AC80F7FDULL, 0xB20CD5CABC3D51BEULL, 0x62C89B6AB52B3C17ULL, 
            0xD191FE54A090B383ULL, 0x950AC3CCB473C026ULL, 0xCA2CB18F09F3B2E9ULL, 0x7513040769AD235AULL, 
            0xE02F6676C22C9551ULL, 0x23DB121B847F4BACULL, 0x12F7174FCD74ABD9ULL, 0x02D23A743D392BDAULL, 
            0x322351EE4AA2FB1BULL, 0x323F184323CE76E3ULL, 0x5C66B216C7B0B0F4ULL, 0xCD427DEB593C0A9BULL, 
            0x060D6E9EA192DB7DULL, 0x968F560AD96BA536ULL, 0xAE3014D8D22ACD67ULL, 0x6D2619080C23010FULL
        }
    },
    {
        {
            0x3039CBF6DE092A88ULL, 0x4CF6650FEA65BAC4ULL, 0x075B6227BFF14645ULL, 0x31DDD3DA75E27D68ULL, 
            0x726E8D1DB7327C3CULL, 0x0003939037F0CB02ULL, 0x8F2F96C0F1CDE20BULL, 0x86C76EFE21C758BBULL, 
            0xD7DCD9B89DDD38D4ULL, 0x0730BD5357672E3BULL, 0x50BD2EB32E2C6A00ULL, 0x34595CA20A2B15EDULL, 
            0xCA43234544931C66ULL, 0x3E8B913AB9FF955EULL, 0x6F94742C4A4AC75AULL, 0x0A18D1AABFB0DF32ULL, 
            0xACBBEDE2E856C15DULL, 0xB81CF2EEFBF1D3A6ULL, 0xB95ABE41EB4F6CBBULL, 0xE684EDBB8B17F77FULL, 
            0x03E2FEA22033DF75ULL, 0x5749D2621CA76C69ULL, 0x7332B7FF49E93414ULL, 0x2DE59B2E989E1264ULL, 
            0x62F5117281A773ADULL, 0x91FD393F325B50BEULL, 0x22B8113A2951BC9AULL, 0x8DEBB92D0136A600ULL, 
            0xE0BB5A91B2603444ULL, 0x3D20D8BD1A3BED0CULL, 0x676BE3AFCF78E51DULL, 0x4C6F6D504D2A7677ULL
        },
        {
            0x9685080EE5CA4368ULL, 0x5646890991BBB4F8ULL, 0xC9B7E9365FFE57AAULL, 0xD0A2951C841B6F27ULL, 
            0x63254A41B39AF541ULL, 0x05E261E54A56BED7ULL, 0x58C5722C615BF6C8ULL, 0x39027ADB0AB25E2EULL, 
            0x98027A4AF1B8DEA6ULL, 0xCE8D7F5ECE0EF5C2ULL, 0xC0BA16794B0BFC24ULL, 0x5021E7259E82353FULL, 
            0x7FEBB9B7A9C77C45ULL, 0x85B1B7B3C75A599EULL, 0x0B13B17BA3CB1B90ULL, 0x964EF655DD698857ULL, 
            0x0CF90F36D006C6B2ULL, 0xB44A567513D59FA5ULL, 0xEB134C6B493F36CBULL, 0x95F86362390D4143ULL, 
            0xCB236B407A17C9B2ULL, 0x755B7574E0B2BE80ULL, 0x12802F6190BF4EB9ULL, 0xFE5561FFE279AFCEULL, 
            0xA96166CB56672FA6ULL, 0xB7653032EB1BC67BULL, 0xC314377C8748A348ULL, 0xCB493A3BBE0841A5ULL, 
            0x75BD782828D892EAULL, 0x4BA6B66B1AE6AB94ULL, 0x465F6FB9B09DDF64ULL, 0xE94BD9A3C2E296EAULL
        },
        {
            0x73EEB930AB6AD78CULL, 0x6330758D6E6BFD78ULL, 0x2E8B109B6FE07C90ULL, 0x15A5C64F6A32C3CEULL, 
            0xE66AFDE68CA20B37ULL, 0xA0F6646ECFD44772ULL, 0x3BB99DAA2A022AA4ULL, 0x9D5ACD15C137C8DAULL, 
            0xBBDB55B2DF5ED675ULL, 0x5AE2FA6BB1E8D55BULL, 0x453AAD6FB3E53C59ULL, 0xE00B64410E0F09EFULL, 
            0x2EBA354C80BFE546ULL, 0x0126B10C09F83233ULL, 0xB525B6B2C4838B24ULL, 0xFE2C93776CAD4D10ULL, 
            0x927D6781C737A9B0ULL, 0xFB33BCD8867CB6FAULL, 0xC639D3C78AF29401ULL, 0xF07FA10BCB7479ECULL, 
            0x3015CAC1543F352EULL, 0x9D5B00098C844B18ULL, 0x0777D53031823F91ULL, 0xE52D6E4F5DDCD974ULL, 
            0x6197D974222393E3ULL, 0x9E1B498FA87A3745ULL, 0x3241D57AC205C990ULL, 0xE8D4A5FF82D0875CULL, 
            0x9D03CDC58F5C938BULL, 0xFF79044D624CA81DULL, 0xCF47E24F8F280062ULL, 0xB67F24DCFDBE96ADULL
        },
        {
            0xF33CB2F618C6355EULL, 0xB796C67FE8515B47ULL, 0xDE82AFB1CB7C7EBAULL, 0xB0D1FEED3542280DULL, 
            0x1AB4FC2649D5F8E0ULL, 0xCB8FC51F2D614470ULL, 0xEF91DAEE9E7A34C3ULL, 0x3F2B69838E4863C7ULL, 
            0xEDABC0E0BEE51802ULL, 0x7705D3CCC06D9F93ULL, 0xFECE29A0862A6C96ULL, 0xBF1F9C1B9A47024EULL, 
            0x73DEB5F157AF2081ULL, 0x57CC7543BB18F999ULL, 0x2EA028E7BD565B8AULL, 0x908942D194E18058ULL, 
            0x50C61A56C18D73ADULL, 0xA848F203DE99B40FULL, 0x7990F20B0C5E844DULL, 0x1DBE79C08467D3D2ULL, 
            0xD72AB7551E7ADE91ULL, 0x46A5520927C9EFB7ULL, 0xAEC76DE6B116C66CULL, 0x81A9247ABDDCA5F5ULL, 
            0x2DEC01D56A6229D5ULL, 0xAA6BE81462237D5AULL, 0x6DB874BB0B8CA7D7ULL, 0xA9AEB9DAC76DF48EULL, 
            0x6BC985A525992726ULL, 0x1446BE48CCC5386DULL, 0x741CB41B883793DDULL, 0xEA1E95B86B28AF73ULL
        },
        {
            0xD0355E24701FE40BULL, 0xA214208773769966ULL, 0x66A9920B2178CBE8ULL, 0x7840F6BC56A65A20ULL, 
            0xD8D091FB381B5D99ULL, 0x394FCA78B4BD6BD8ULL, 0xAF522A098A23A9E9ULL, 0xF82C8C360D6F416AULL, 
            0xF330C9559DFDF197ULL, 0xB98EE919D15E6DBCULL, 0x14959B4E215FEBABULL, 0xCAF7E1D55474CF71ULL, 
            0x2D8A8D3DA32A07D4ULL, 0x6C98834DE6057897ULL, 0x0B20B9DF6C5EDDEDULL, 0x34542F24080DDCE2ULL, 
            0xF8B0554CEAF52C94ULL, 0xFDCBFFEA50FF62B3ULL, 0x9A037D30E990A163ULL, 0x9DF80657B280F079ULL, 
            0x76D8D09E1CFBD1F3ULL, 0xE3368AEB000018CEULL, 0x67BDC497046FFCAFULL, 0x038514CFD4BC34C6ULL, 
            0x3F4A365B08341099ULL, 0xE315FEF8F493A07AULL, 0x7B6845E29A897363ULL, 0xD7DF4690288BBBB2ULL, 
            0x28C940E11E572B60ULL, 0x489006D18F32E2FBULL, 0xB83C71C786A52145ULL, 0xB3D5C35C3567344FULL
        },
        {
            0x27F75823E8207047ULL, 0x22891F5146620FC7ULL, 0x5B314C9E915C3FC5ULL, 0xB17DEC6C73F17ECBULL, 
            0xAD6E08487E436B26ULL, 0x4FC1280851EC751EULL, 0x6E07534EBFA44DE2ULL, 0xDE45CCD3446A2BB3ULL, 
            0x415DFE72AA680452ULL, 0x54A2B984F5D4A6A6ULL, 0xB97F3E6D99C79C52ULL, 0x53C563A9033900F6ULL, 
            0x08B65D647291412CULL, 0x5C2FC1F46EEC93FBULL, 0x2C4C8841279056D8ULL, 0xFF356BB762090AA1ULL, 
            0x5D3D1379E2F65A37ULL, 0x67F467F5816BF668ULL, 0x3DB606E46AF757BFULL, 0x683B9F891B0F293AULL, 
            0x5EE8EDE89F84C1CFULL, 0xA33F8AD7BACE75A8ULL, 0xE9F247D0880F1C9DULL, 0x9165DD319FCFCF73ULL, 
            0xF594DAC6A6FD5563ULL, 0x98810CF2FF34F1A2ULL, 0x27F1124C3D58EEE8ULL, 0x55AB7364BFECA8B8ULL, 
            0x51AB8D75F9CD13F1ULL, 0x489177DF25DDB391ULL, 0xEFBD5F93BC863D1CULL, 0x0811B313DE6A3508ULL
        }
    },
    {
        {
            0x3F60D4B8BE66AA85ULL, 0x7427B8A90911DD30ULL, 0x7D6F7118D823F71FULL, 0xDFBC73C13AC98C6AULL, 
            0x5B728B82195E0BFCULL, 0xACC2B0C9C0EBFB27ULL, 0x24048F25047E215FULL, 0xAEE270FA27DA2FE9ULL, 
            0x65C914B0F69A42D0ULL, 0x11494AD25F0411A4ULL, 0x23A2FC0F8AD5056CULL, 0x2B42D23B8E34E792ULL, 
            0x217C768390D7D4B9ULL, 0x06E01F7734BB6CD6ULL, 0xE5C474EA2C513734ULL, 0x395C2EAFA51D102AULL, 
            0xF49990611469E5D3ULL, 0x0381CD0F742A5091ULL, 0xC91F8C1D108803DDULL, 0x0271C5857CF2E9C3ULL, 
            0x254EDA9665F3B084ULL, 0x707C9F4CC01A003BULL, 0x0918822ED9149A02ULL, 0xC2669C993C6B8616ULL, 
            0x5E70571C0C0AA942ULL, 0xB77F90612345BE45ULL, 0x1CD09CD9555C423DULL, 0x7288C52518B43696ULL, 
            0xA494AF02BD8DFC95ULL, 0x0F4285EFD9030113ULL, 0x9CCE0BC56FA0A8DFULL, 0xADBE041DCD16C13AULL
        },
        {
            0xDCE57BF950BF40ECULL, 0x4018A5C4B1678B99ULL, 0x93F90C13A3CD5506ULL, 0x60DF05273B32D7BEULL, 
            0x245BC560015B82EAULL, 0x5E436DAAA69A35BAULL, 0xEFFF8817B9B85509ULL, 0x1E8AD1874C61EECAULL, 
            0x4D026C08CFF7DE41ULL, 0x1B9DD0C3BC98D157ULL, 0x42B40720098C0B7CULL, 0x3876B6F830E045A0ULL, 
            0xD88065BCB3A117F4ULL, 0xF2D37689FC92DD6FULL, 0x9E2AA10062AFBA9CULL, 0x2870AEE523E1019AULL, 
            0x34850043890AD063ULL, 0x3FED85B78E302692ULL, 0x00147467875F8659ULL, 0xA8766E2ED69FBE5EULL, 
            0x04D1DC0112CA4295ULL, 0x8DB41F211D15C13EULL, 0xDD50DBFFB6CEF3F9ULL, 0xF4658FACE91AA89EULL, 
            0x62C1B40379141D22ULL, 0x380239F6BCD7B62EULL, 0x0FDB7553AB92F1B7ULL, 0x9242B49BDE1272B8ULL, 
            0x8866A725E3E5FE42ULL, 0x542B787BF4D1E3A2ULL, 0x03BD4DC9689F451DULL, 0x8D944C31D2EBDB32ULL
        },
        {
            0x53F3523C6F06144BULL, 0x1896A0CD03B203E5ULL, 0xC3CFC6801C10DBFEULL, 0x8AE9E13139F75B3EULL, 
            0x1D6159506FE7197AULL, 0x63CDD3F540DD3971ULL, 0x76FD2BE2FEB9CAF5ULL, 0xBD4DCAD27C9114A4ULL, 
            0x7BD712A1682C54E7ULL, 0xC6AD2672CF00563EULL, 0xF695A6EA068FDF8CULL, 0xA076107E2DB7D933ULL, 
            0x82896B994FA71C23ULL, 0xCF0334D917AB138BULL, 0x242AA43121DE5F27ULL, 0xB869CE35666C68FCULL, 
            0x6B2F81ACF89B109DULL, 0xC811F067CA3FAB1BULL, 0x6B0FFB317CFA978BULL, 0xBA0094BB78B8B653ULL, 
            0x12A3F37E9DE0F861ULL, 0x10A8333F9FF120C1ULL, 0x1932C09DB7533E88ULL, 0x8BF64934A7121F0FULL, 
            0x1EB63E69ECE6B89DULL, 0xF1C5E99A47B9A4BAULL, 0x6B63060E285A30A5ULL, 0x844831EA873B6D2BULL, 
            0x7F7A1A425B05F5CCULL, 0x1864D94192399576ULL, 0x23A833D9F7D49147ULL, 0x9D14BAE85E7242B7ULL
        },
        {
            0x9575DC3599A23C1DULL, 0x35508322572A867DULL, 0x3A7E31D12BB2F4F2ULL, 0x587BF87490ECBE79ULL, 
            0xC00DE2E22F375F39ULL, 0x71AE2DFC6011F864ULL, 0x89C9C5D6F2D5A7AFULL, 0x9E0AF5C23899DA6AULL, 
            0xA606D385ABDD3E2AULL, 0x2305BBD09A74CEB1ULL, 0x5E2EFDAA625ED242ULL, 0xFFC991AB112CB727ULL, 
            0x52652854B65EC6F9ULL, 0xE19DD51B736B2536ULL, 0xF52B978DFC9F65D8ULL, 0x30F779F8F921F98DULL, 
            0x1E5F87C54CC98F2AULL, 0xB2C0307E80D52E91ULL, 0x83B5CEF6221C36F6ULL, 0xDD23B83D38D79E3BULL, 
            0xDE72A94574EEB204ULL, 0x1C08BB7982DBC047ULL, 0x047464438318B1C9ULL, 0x53E6A498BD23F458ULL, 
            0x314E4FBDC17CEDF5ULL, 0xAFF7EE600C76AE2CULL, 0xBF63100AD6F88131ULL, 0x7DC5E49C59E37503ULL, 
            0xA0AD32CEAC5E2E1BULL, 0xFFE2D3218FB69A2AULL, 0xCAFE789075473D7DULL, 0xED18DD959911A984ULL
        },
        {
            0xB591A2F3AEC02730ULL, 0x498FC4226CC4BC1EULL, 0x364033487F0EC418ULL, 0x1F959AD1C5ADF8E5ULL, 
            0xC8DB7C305DF723A4ULL, 0x72907867404C697CULL, 0x89CDBEB440093EE5ULL, 0x66DD0DC5BD9E2240ULL, 
            0x9118323469B0D031ULL, 0xD3BFE45FFC0FAF1DULL, 0xBEF114F9727A7D9AULL, 0x5A73EA6E4E12F78BULL, 
            0xAF7D63599C664933ULL, 0xE1DE71A7E2CCDEBEULL, 0x4186082D74D9DABFULL, 0xF057A1CBC813A305ULL, 
            0xB81CCA3DC2DC1C36ULL, 0x19AE338D063C29BEULL, 0xE5CE298E9C8DC3B3ULL, 0x2D587F09D805150AULL, 
            0x40775529590D425AULL, 0x32FF84CEE13152B1ULL, 0x456E2E70747A6AC6ULL, 0xBF316EB95A74838EULL, 
            0xE166996F1E276408ULL, 0x5628F049D37B5CADULL, 0x8D4711855A3DC7CDULL, 0x8866A3A85DC6CA24ULL, 
            0xD4B3D4BF6EDC61FAULL, 0xF59FEF40B3320F84ULL, 0x53E3EF490AD208A3ULL, 0xA2E52CF795B50E82ULL
        },
        {
            0xD6BD07D6D62E6131ULL, 0x775664401DE53C2EULL, 0x849448A48E06B52EULL, 0x0714524E752A093EULL, 
            0x8643E76EE2AE0947ULL, 0xAC61407283C5EFCCULL, 0xC004790626EC205FULL, 0x412EAADE4C20B6A9ULL, 
            0x8EBCFFFEF4674822ULL, 0xE16BEE5018121393ULL, 0xF2903D69C0F6475FULL, 0x141C71352CDFA80CULL, 
            0xCF358AB110FAA365ULL, 0x2E8BCE517DDAA908ULL, 0x7FBF9AE508934969ULL, 0x139F06059F5B5F43ULL, 
            0xB2E9EEE70F181297ULL, 0x610F13AC5896B194ULL, 0x1AC6A7E02CA9C6BFULL, 0x044D40D91946DCA7ULL, 
            0x24C5A98052DBF236ULL, 0x2A018EC044325821ULL, 0x053D99A651327C72ULL, 0x8635B070C0CFED18ULL, 
            0x98666D64A503FFE1ULL, 0xB2358257E403A4DCULL, 0x98C9CB6E4C4278DCULL, 0xD894F37F427172ECULL, 
            0xACC5F8ECF11F7BB2ULL, 0x50BAC6629440BF03ULL, 0xE3495E2148538028ULL, 0x467AAFE174C2159DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kTwistConstants = {
    0xE772591DEE17334BULL,
    0x1107F5901D3916E9ULL,
    0xF09E5813EA33AD79ULL,
    0xE772591DEE17334BULL,
    0x1107F5901D3916E9ULL,
    0xF09E5813EA33AD79ULL,
    0xB1C1940F069AF265ULL,
    0x92BB41DC428A9511ULL,
    0xE8,
    0x25,
    0x22,
    0x6B,
    0x95,
    0xCA,
    0xD7,
    0x59
};

