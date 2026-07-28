#include "TwistExpander_Polaris.hpp"
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

TwistExpander_Polaris::TwistExpander_Polaris()
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

void TwistExpander_Polaris::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Polaris::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Polaris::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC2A773684C947F13ULL;
    std::uint64_t aIngress = 0xAE22697E2EA37093ULL;
    std::uint64_t aCarry = 0x97A7CAA9A200CAABULL;

    std::uint64_t aWandererA = 0x81221DF06D579AB0ULL;
    std::uint64_t aWandererB = 0xE87C34A94A974511ULL;
    std::uint64_t aWandererC = 0xE51EEB5F8774F73CULL;
    std::uint64_t aWandererD = 0xF20060E9480954DBULL;
    std::uint64_t aWandererE = 0xD33A30CBCE0C61AEULL;
    std::uint64_t aWandererF = 0x954806428A22B04BULL;
    std::uint64_t aWandererG = 0xA934283D7E03402BULL;
    std::uint64_t aWandererH = 0x8B4E135209CF218CULL;
    std::uint64_t aWandererI = 0xF9118FCA37982339ULL;
    std::uint64_t aWandererJ = 0xF5F47CB2270543CEULL;
    std::uint64_t aWandererK = 0xF7A4A294DD962ED0ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x9018E70FD2EC861BULL;
    aIngress = 0xEAB25D61D78197AFULL;
    aCarry = 0xEC21AD39AA4A9BC3ULL;
    aWandererA = 0xFC0CB0D9EBCE6049ULL;
    aWandererB = 0x9A30E193A1B8FED1ULL;
    aWandererC = 0xE9AD065FAB1FB284ULL;
    aWandererD = 0xEF0F738992D2FDD3ULL;
    aWandererE = 0xAAE07EC304E50E1AULL;
    aWandererF = 0xFF4F9197437D03DBULL;
    aWandererG = 0xA3CE53C4DE9FD3E5ULL;
    aWandererH = 0xB8C407DB5FC0D2C8ULL;
    aWandererI = 0x9F8186264728BB13ULL;
    aWandererJ = 0xDE26E014C3BC0D7EULL;
    aWandererK = 0x8559E860CCEADDA4ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA81206C8702AE279ULL;
    aIngress = 0x84ACDE7E952E9DE5ULL;
    aCarry = 0xFA3580AAD28CB28BULL;
    aWandererA = 0x8D5009BC69D7744BULL;
    aWandererB = 0xAD22B4BB75794B48ULL;
    aWandererC = 0xBAF88A288CAE0E23ULL;
    aWandererD = 0x8CE71401D5E5022EULL;
    aWandererE = 0xDB1892AF9D4A71E5ULL;
    aWandererF = 0x853112860C23878AULL;
    aWandererG = 0x89C6F1DE50EFD340ULL;
    aWandererH = 0xF98219C287673A8DULL;
    aWandererI = 0xE863454C67B92475ULL;
    aWandererJ = 0xCB22EDF24B46DFB7ULL;
    aWandererK = 0x803BDACB3A7DE9F3ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x9C27FE45F3A867B7ULL;
    aIngress = 0xC4148907A99D8ACEULL;
    aCarry = 0xC929BE4373405667ULL;
    aWandererA = 0x93A3E9406E745FA5ULL;
    aWandererB = 0xD218156E20531BA9ULL;
    aWandererC = 0x82FD2D309025CA18ULL;
    aWandererD = 0x8052E567F01ECD0FULL;
    aWandererE = 0xB97FCF70D9E3F958ULL;
    aWandererF = 0xD497790D72BDE1BFULL;
    aWandererG = 0xCB31C0E1F7E835A7ULL;
    aWandererH = 0xA6215571F4F3E8AEULL;
    aWandererI = 0xA5D271767528F0B2ULL;
    aWandererJ = 0xFD9F70E49CF7CA2AULL;
    aWandererK = 0xF47C4439F1767F6AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xF4D3A06448188A56ULL;
    aIngress = 0xD61EDAA42B461143ULL;
    aCarry = 0x81D6B050CFBA276EULL;
    aWandererA = 0xA67D6B7A1B39DEBAULL;
    aWandererB = 0x8FDC8ADA5A1414E3ULL;
    aWandererC = 0xFFA66E0FF5EF903FULL;
    aWandererD = 0xECAAB83D01EC33F6ULL;
    aWandererE = 0xDFA43205895C444CULL;
    aWandererF = 0xD80553FE6F3EA278ULL;
    aWandererG = 0xC354732CCE4B490DULL;
    aWandererH = 0xD3AF9FC27E5EE148ULL;
    aWandererI = 0xFAF18FCA2158E37EULL;
    aWandererJ = 0xFC3257E5D901D53FULL;
    aWandererK = 0xC73E863A293F4D3CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xEFD65BB569DB17E6ULL;
    aIngress = 0xAA942F8B5934BB4CULL;
    aCarry = 0xD6F585C47D98D4B7ULL;
    aWandererA = 0x888A8633AA0FB65EULL;
    aWandererB = 0xF5B592BBC6AF22B1ULL;
    aWandererC = 0xC51BE98640BFA86DULL;
    aWandererD = 0xE5A807EC534FE3C1ULL;
    aWandererE = 0x9C3CC41E1CCC3001ULL;
    aWandererF = 0xB46FA459C121B5CBULL;
    aWandererG = 0x8347C2C981888AF0ULL;
    aWandererH = 0x9E00E492B3404815ULL;
    aWandererI = 0x822E366E59AB2BECULL;
    aWandererJ = 0xCC2F6FA791E02CEFULL;
    aWandererK = 0xBBBFAF3A851CEEC3ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xCA984998C4244759ULL;
    aIngress = 0xA012E56E5490115CULL;
    aCarry = 0xF8463226C630A4ABULL;
    aWandererA = 0xDBA73CB9DAFA7B79ULL;
    aWandererB = 0xA28569323D52BC32ULL;
    aWandererC = 0x9CAAD1BB259D3DCFULL;
    aWandererD = 0xC1855E3B85D95FA6ULL;
    aWandererE = 0xA4DBB0A77940A8BFULL;
    aWandererF = 0xDB983EB9F04EC8CAULL;
    aWandererG = 0xA2FF98DA5305E682ULL;
    aWandererH = 0xD34601BD147E6435ULL;
    aWandererI = 0xFDD577625F9C7714ULL;
    aWandererJ = 0xFC6FB0D596B3F75CULL;
    aWandererK = 0xCE8884953F2C66BAULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xCC506DF42EB792A5ULL;
    aIngress = 0xC9E7E3FCBED80E5AULL;
    aCarry = 0xFD80ED70088F031FULL;
    aWandererA = 0xCC54EC085BE764F6ULL;
    aWandererB = 0xD148E586F68B21D6ULL;
    aWandererC = 0x83614DF9842E8B94ULL;
    aWandererD = 0xCF47043C8E3385F5ULL;
    aWandererE = 0x910456BE63982224ULL;
    aWandererF = 0xD1F933F783C70EDBULL;
    aWandererG = 0xE12993260CD39E5EULL;
    aWandererH = 0xF25E3D9E31370CE4ULL;
    aWandererI = 0xF92385615C093FADULL;
    aWandererJ = 0xC0DFBE73385811C0ULL;
    aWandererK = 0x870764A7450E8E0DULL;
    //
    TwistExpander_Polaris_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Polaris_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Polaris_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Polaris_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Polaris_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Polaris::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x914FCA8E034BB236ULL; std::uint64_t aIngress = 0x806CF7AFDD8E55D8ULL; std::uint64_t aCarry = 0xA3A4133B8B07341AULL;

    std::uint64_t aWandererA = 0xDC8F4FF1DCF57B2CULL; std::uint64_t aWandererB = 0xE1003A0010C683FCULL; std::uint64_t aWandererC = 0x93E0006B27CC5109ULL; std::uint64_t aWandererD = 0x813A7C8CA13D4209ULL;
    std::uint64_t aWandererE = 0xF9DD590680A241D8ULL; std::uint64_t aWandererF = 0xC6389F1CB1855812ULL; std::uint64_t aWandererG = 0xB8016C76988AA54EULL; std::uint64_t aWandererH = 0xC3880C65C1B7E12BULL;
    std::uint64_t aWandererI = 0xB06FBC8B22421F28ULL; std::uint64_t aWandererJ = 0xA5F52D86DDB881C3ULL; std::uint64_t aWandererK = 0x874AE5F23D859D1EULL;

    // [twist]
        aPrevious = 0xE106DE88D98A0512ULL;
        aCarry = 0xFAC3FF65A21AB7BAULL;
        aWandererA = 0xD017DC7EC02A6DE1ULL;
        aWandererB = 0xF7EBB9F9DF607312ULL;
        aWandererC = 0xA24CFE76F097D7D0ULL;
        aWandererD = 0x9C958391B93457B6ULL;
        aWandererE = 0xF85B41B204283302ULL;
        aWandererF = 0xA7CAEB59BC8FE145ULL;
        aWandererG = 0x98F3D0D617EA32A9ULL;
        aWandererH = 0xD4BC4918185FAE83ULL;
        aWandererI = 0xB322FC49E0EC4993ULL;
        aWandererJ = 0xFF5A91910476E284ULL;
        aWandererK = 0xA6C68EECB698309EULL;
    TwistExpander_Polaris_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Polaris_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Polaris_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Polaris::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Polaris::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Polaris_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Polaris_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Polaris::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 24 of 33
    // Exploration cases: 0
    // Structural maximin 515 / 674; family total 12306
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
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 24 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 12266
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1105U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Polaris::kKeyRotateASalts = {
    {
        {
            0xD97356FF8D46E3A1ULL, 0x2E4EF12EDA4B25F8ULL, 0x797F73FA932C48AAULL, 0x8378726238836889ULL, 
            0xD6C01DD9D9C18B81ULL, 0xE10B0B27BDA6FFA3ULL, 0x54051375E300CD19ULL, 0x6D8F67F544D7C4E7ULL, 
            0x7DE3A50B9F690F74ULL, 0x7D8B20E77416A282ULL, 0x82C30AEF7162A7FBULL, 0x02E997DCE58FEC24ULL, 
            0x10C919B766D25488ULL, 0x98A6507A8399B0D9ULL, 0xD6FEAD840DFDC80FULL, 0x08ADCF50FAB5BC56ULL, 
            0x584FD2F64B61D7A4ULL, 0x26B8CC2CCC6047D6ULL, 0xBFFBA686B3E8498EULL, 0xA73C59AC95218E3BULL, 
            0xB0BF237853789210ULL, 0x2DC7962C116BDA2CULL, 0x68A6A94CDE82EC28ULL, 0xA674ED47E73790ECULL, 
            0x5D06DDB70AFC381CULL, 0xD407C5ACFBB397CCULL, 0xCF9EEDFC5EF36A4FULL, 0xB35D3F02B58E6E72ULL, 
            0x4074BA4232C95362ULL, 0xDA60FF52E8B14C0DULL, 0x887CC293DA7FE58DULL, 0x00FE3DA64D377399ULL
        },
        {
            0x4C0B844E5CE3E7E1ULL, 0x009F5DEAC176FE4AULL, 0x1025F64ABF44BBF5ULL, 0xB577EEC92717B469ULL, 
            0x9231D4AE46B9DBF2ULL, 0x076EEBF892D29F93ULL, 0xD29C72220C95A1F3ULL, 0xE7323FDA23E9BBB6ULL, 
            0xA0E202E2BED6B00CULL, 0xDD7AF90CDC60E7F6ULL, 0xF2AB4E5C3D5D85ADULL, 0x40388CCA108A005BULL, 
            0x430AB9CA196B0C68ULL, 0xF63B22940BA79FA0ULL, 0xD401435FFA6D7E69ULL, 0x1E64680571820D84ULL, 
            0x3399E5AAC1D4162DULL, 0x84007FE828667CA0ULL, 0x80A380C7CDD7452EULL, 0xB1355563EBC63BA8ULL, 
            0xC6E396275D87F770ULL, 0xDCB6AC2D282E2050ULL, 0xC78A5AA50FCF1621ULL, 0xE52B170D7CA57729ULL, 
            0xA2954DC6EBBC582FULL, 0x9DC1C2AE351E2E1EULL, 0x8BE51A1ABC63575AULL, 0x7A7183B493067708ULL, 
            0x02A50065E486206BULL, 0x70A93BB702DB46E7ULL, 0x3DFB58E6B132983BULL, 0x318C4A6ED944ECB9ULL
        },
        {
            0xED6072F418FE141BULL, 0xB3539407D0E9F6CDULL, 0xDFDA5F0FD76EAF39ULL, 0x906A7A07E849779DULL, 
            0xA1CCC9A96613D568ULL, 0x87E7F6798A9914B4ULL, 0x24A4BA7DEE9919AAULL, 0x892ABDA8A01BE563ULL, 
            0x42D491DE517605BBULL, 0xBCC2D67A2FD31B29ULL, 0xCCAFC7D3EDECB225ULL, 0xFC70603775F310DDULL, 
            0xFB8BC8FE70A54D56ULL, 0xFD5DC74CC9A746CAULL, 0x973861F1E321FB4BULL, 0xF38DC376EB4C0FE9ULL, 
            0x65713C9A42688455ULL, 0xAE6D0D6AC4E732B7ULL, 0x31BA3FAD0E0AEEEAULL, 0xE203E9C7625089FBULL, 
            0x3D9F235C4A150F62ULL, 0x22D722B6A27BC198ULL, 0xEEF34BD49870FA13ULL, 0x349367851F4E823AULL, 
            0x8CDBEAAAAB00AB6BULL, 0x396DD4EACD8EE30CULL, 0x14423607511DE22DULL, 0x1A623BF840D5EE5AULL, 
            0x7E8A4843C4C8592EULL, 0xF7CEB47CC60FF30AULL, 0x6FCB1EE79E97B61FULL, 0x2936343EB04CA4A0ULL
        },
        {
            0x410CC04DA097D760ULL, 0x4953E0E802B61909ULL, 0x9880F90F6EB6962CULL, 0x32F7386A8E22F789ULL, 
            0xDB6BD2B184E5806EULL, 0x9AC2DE8FBD7E54AAULL, 0x03814430A87FC693ULL, 0x1F43840B0CBE1C01ULL, 
            0x20508F4273ECD61BULL, 0x29E5F6692C554DE3ULL, 0x4664CCCFA722CDC2ULL, 0x3F4810452C591910ULL, 
            0x4B73FAF50FEC6D2DULL, 0x3420549974586122ULL, 0x5F38D8E76E11F744ULL, 0x41783508009CA6F6ULL, 
            0x9B9743917E365865ULL, 0x3C1EECE069786BCFULL, 0xB9F70BBDFDB1258AULL, 0x7E1F3D758396E89AULL, 
            0x5228873BFCB88EF2ULL, 0x848F1E216104824AULL, 0xD65594317A617C6AULL, 0xB05FEE7879B7B5ADULL, 
            0x49A64A4161B9ECADULL, 0xC8C7EE317A41754AULL, 0x3BDD2AE16132FCF0ULL, 0xA4B512FA42BEC343ULL, 
            0x928DA69B86CF58A5ULL, 0xF19CDCAB5057B8FCULL, 0xFD90C3EB2552D018ULL, 0x9E069547E6FE8C20ULL
        },
        {
            0x753D12F5B1D8267BULL, 0xBB89481E74945E68ULL, 0xF8DBEE37B648E690ULL, 0x0DAF17442AACB8DEULL, 
            0x4F5729DE73E73BDBULL, 0x1A10459BE0355245ULL, 0xD6768B4E94223A54ULL, 0xB33EE0ED79177A55ULL, 
            0x5A3EFFB09DA83509ULL, 0x91E984D316E20A29ULL, 0x5F914EBB4F762C12ULL, 0x5780B511128647FCULL, 
            0xB81ADB8569BB77E7ULL, 0x7020DB89C027F330ULL, 0xD8C6E81832EEBECAULL, 0x56D15943C4032CF2ULL, 
            0x5B8EB727F8A463CCULL, 0xD3825C1D6E996B35ULL, 0x061F91A6DE7EB95CULL, 0x96111A1A1A918456ULL, 
            0x86314EF7F6E278FEULL, 0x14A505E355BFE184ULL, 0x097FC6BF1FC935C6ULL, 0xF3E9FC8FC490D33DULL, 
            0x5143941E3D718D26ULL, 0x82D7F66F0021E6A8ULL, 0x31EF25A8F50F426DULL, 0x11BE37354CE61111ULL, 
            0x73B0A82D58E12CEAULL, 0xD146991F0FEB9844ULL, 0xD6712293B46E41C9ULL, 0x38AC68E1E72745FAULL
        },
        {
            0xF377E07C14DFE22CULL, 0x98356CD78E8A505BULL, 0x0929420DACD9CE72ULL, 0xBED91600D2913533ULL, 
            0x28BB459B261B69ABULL, 0xFA03944A0EC74CEFULL, 0x144E5929AD41BB88ULL, 0x8D8E335C58571D41ULL, 
            0x846844075781BE0FULL, 0xC8447E5852BE6EA4ULL, 0x37368F71FD650F88ULL, 0xC51AFF303C02D8B3ULL, 
            0x143C0AA65FE4DACCULL, 0x4B869F5BCC9D3909ULL, 0x7CE0DF82949AA8EBULL, 0xF25C6A6A4272B6E3ULL, 
            0x4F8A7DFB5BB2D2D6ULL, 0x418504C982ADD7F2ULL, 0xA58DDCE55C1FD799ULL, 0x442BB20B7034FD8AULL, 
            0x01CC72F3F497B369ULL, 0x006FC14FE1546E2CULL, 0x877C58D9E2E4E3DAULL, 0x2E8EB532E195D809ULL, 
            0x398A5C56CA5E4A63ULL, 0x4AFB0C23E2C0B28BULL, 0xA52473691DA56981ULL, 0x843B917BA5283CCAULL, 
            0xB620EC47FC14E199ULL, 0x0559C1F1CC401324ULL, 0xB22BA5FC573B89D1ULL, 0x485871200C295C31ULL
        }
    },
    {
        {
            0x51E762C0C6361001ULL, 0x00571EEBC7BB72C4ULL, 0x92D88C737FC00D7FULL, 0x7EA619D0620E1E1EULL, 
            0xEEBD06881BD5BF5EULL, 0xF66B923AE88F46A2ULL, 0xB8A7B9451B4C1239ULL, 0xDF468DE7B2BCC6BEULL, 
            0x424BCBC20EE3BF74ULL, 0x0DF73B57CB7D0727ULL, 0x9A4C54D220D5331DULL, 0x3A7D878A047CE32DULL, 
            0xFD29BB93CB35E43DULL, 0x77A7A04915717504ULL, 0xBB1A4088F3BD5E9FULL, 0x1F4EE44938560541ULL, 
            0xDD5E52F2D9185DADULL, 0xB0B03C93378F1776ULL, 0x7A55F5E77EEB080EULL, 0x876C2826EA66F7B7ULL, 
            0xE244C5D6E27942BBULL, 0x17C05BF072A2585FULL, 0xE27B13FA3D436E5BULL, 0x8089827384560905ULL, 
            0x35518E0C9488E054ULL, 0x3BF13ACC7B30B730ULL, 0x7225682B47F8CE64ULL, 0x8097599FBC09ADF9ULL, 
            0xF816805B790CA7DCULL, 0x587EEBC22C9EFC7AULL, 0xD1BA79A44FB34530ULL, 0xC2963292EE93400BULL
        },
        {
            0xDD14AC8BEA238225ULL, 0x25074DA6C9CB4183ULL, 0xD15E7B6DF2E8B35FULL, 0x0556DC0B54A07F9FULL, 
            0x538C6D3AC5AD8FBAULL, 0x764DF7C7C677086BULL, 0x9BB80034B0DC56BBULL, 0xFCE80D2BEEC5F4C9ULL, 
            0x1D1F5DEB1539A50DULL, 0x93F9254C97D12A09ULL, 0x4C8DFCC9B8C590F3ULL, 0xB64439B26631C455ULL, 
            0x0D0D657FB8DB60F4ULL, 0x8E1502CBBEA7AB34ULL, 0xEFC39E13F4ADB4DDULL, 0x80871681362584EFULL, 
            0x79B18753C4917F9FULL, 0x26DF7A2EEF851E59ULL, 0xA1E559DE0E6313F9ULL, 0xDEE5C78EE86C4263ULL, 
            0xC3C638691ABA4303ULL, 0xBE10DF06BEC3D645ULL, 0xC7AE348E8CB90429ULL, 0x904654ADBE34B252ULL, 
            0xFADC54A823AE591DULL, 0x3B590CA33D28776FULL, 0xB37FF0A5F7A3AA08ULL, 0xDD01763926643B7AULL, 
            0x31C4209D1660FF59ULL, 0x8A1BFF7D958EDA1DULL, 0xC62CE1498583955EULL, 0xD00F0B913307BA0DULL
        },
        {
            0xC2E0E36D40202D0FULL, 0x7D9D2A6D77A266AFULL, 0x07E0043E3E7FC80FULL, 0x1E240E73C2E070F8ULL, 
            0x4AB89D8698A8CBA1ULL, 0x598E17616E1C8A5AULL, 0xB80027A7E9EC67EFULL, 0xFCE31ECAB7942FB1ULL, 
            0x08E9F728459FF886ULL, 0x99821FDB2C462E9CULL, 0x1C0430269DD68285ULL, 0xDA985097F4813DA6ULL, 
            0xB743FD44D1BCB133ULL, 0x56A5B3A7818F58A2ULL, 0xDBF249797DF9416EULL, 0x9C4EED81D145E540ULL, 
            0x89FF729AE46ACAB1ULL, 0xB560426739A805BFULL, 0x00EC52953A79CF68ULL, 0x6F50D1205D989B85ULL, 
            0x460F182FA2C821ABULL, 0x51ACA5FD9EE51556ULL, 0xAFAFEF99437E8128ULL, 0x9DB2A0394942C65DULL, 
            0x2E63F512BE592094ULL, 0xC5FC37956BB6DF37ULL, 0x6D6936FAA9363C56ULL, 0x96463D22D324EEE4ULL, 
            0x46E2F2BC8EA82D6CULL, 0x9C280007DFA92ADAULL, 0xBD60154149E8B6F5ULL, 0x9E7DD5007C4A13CDULL
        },
        {
            0xE0B2A9120FD2C7B0ULL, 0x77226790A8D15206ULL, 0x27E7BDEF0467D1E2ULL, 0xE163AA74948795DDULL, 
            0x42C54CFEFCEE50D0ULL, 0x81B1F4BFE92E30F6ULL, 0xB290DFB9399802F9ULL, 0x4EA675ED0AEFA77EULL, 
            0x1587FAC2512C5286ULL, 0xF816D3BCCDF7A293ULL, 0x322E44DF15C766D1ULL, 0x9C99133A40D24A3CULL, 
            0x893580F499EF0755ULL, 0xC6E6DC5BB6F748C1ULL, 0xD30DC9432F630603ULL, 0x62E51B83BC0F3162ULL, 
            0x294DA7FC81DF3DECULL, 0x38D6D8B69D4ED406ULL, 0xA8F64FBAB0DAB571ULL, 0x8927227F39AB55A7ULL, 
            0xAE3CACD5694A8B20ULL, 0xAA812B0958583863ULL, 0xC38EAC57F7C33AF3ULL, 0x5AE385C8CD25385CULL, 
            0xB9EAE024FF871FD4ULL, 0xD904A282B82857BAULL, 0x5E3848F7CF0EC466ULL, 0x049CB8B25429A0B5ULL, 
            0xF7228E4879923E91ULL, 0x947896D34695D8ABULL, 0x862603C4C49E5ED9ULL, 0x8394AC50EBF14491ULL
        },
        {
            0x278EBDB9DA7BA6A2ULL, 0xFF604220882D9403ULL, 0x321CFE93FB5FE574ULL, 0xC2DC5D7FB690535AULL, 
            0xC236262B201F4E8DULL, 0x59052B454CA4C7B7ULL, 0x73E7CD1C7407076BULL, 0x2522515EFFEA9133ULL, 
            0x10516E34B2833E8CULL, 0x9B0D65292E5A55EFULL, 0x6027BCF35D2D6D74ULL, 0xCE88E684FBC8C08CULL, 
            0xE5625B43FEE1080AULL, 0xD9C99932978313C7ULL, 0x2762995262A035EBULL, 0x2426EEDE09D2886CULL, 
            0xE299BBCCD0A22C37ULL, 0xCE761DD6A8EA4897ULL, 0x57B22089D853F526ULL, 0x08A392D3A27D0513ULL, 
            0x029D362D01DCF97DULL, 0x61A7CF7AF6D13D33ULL, 0xB1C276AA0FC4AF27ULL, 0xC2082D7B6625FD03ULL, 
            0x08D7714B270730ADULL, 0x73BD49EA3EE31F5EULL, 0xB1046AA727F972CBULL, 0x8613BF3A3F15662BULL, 
            0xB3D37AA1E9C7E288ULL, 0x466CE559CCC4F185ULL, 0x9374E610BE75A118ULL, 0x41E8AC2E7C43CA09ULL
        },
        {
            0x7434ED419DCF0E73ULL, 0xAFDCA18A0F60D809ULL, 0x6DAD8ECDF588143AULL, 0x82B1E264267F4FF7ULL, 
            0x6D40A439708A17E5ULL, 0xEDB20A13FF1CBBD2ULL, 0xB6E634BDCC617551ULL, 0x0CB39C4BB1016655ULL, 
            0x15720608F8A6F582ULL, 0xC8E7936A236ABDB1ULL, 0xEBAE65836E6D282BULL, 0xEB81E6BB369743F3ULL, 
            0x728C555625E8311DULL, 0xD53CF1B48006E691ULL, 0xCEA2E728E1BE3DF7ULL, 0xFA321BBECC1D8CFCULL, 
            0x490ECA2B6CA0624AULL, 0x631DE6C5E7526999ULL, 0x2E94BA805B8E94E3ULL, 0xFD7BF5EE6A466B88ULL, 
            0xA3A8011E4F659AE9ULL, 0xA618E10FC3220E5FULL, 0x4141AC6A2E0A7048ULL, 0x0CC3059C8D0063EBULL, 
            0xC9C158DA37B2AD40ULL, 0xCF219B4DAFCA30CEULL, 0x0290B7F15B03169AULL, 0x50D2547677153311ULL, 
            0x8BDCCCD6450DF777ULL, 0x2864D7702E6C2948ULL, 0xFC56AE5E2558AF8BULL, 0xD52306B904663D7DULL
        }
    },
    {
        {
            0x3EDA0E0149AAC77BULL, 0x91745AA2B6F6E199ULL, 0xF484E75A61391E08ULL, 0x22F346ADD6E5B74EULL, 
            0x9DEF183C643DBB85ULL, 0x97E5F7D225172753ULL, 0x9C2EA33D7B5F1982ULL, 0xAB87E49ED7B44387ULL, 
            0x9ABA68DAE9EE6C34ULL, 0xAC631193BEECE3AFULL, 0xF0494DB101DEB6F1ULL, 0x6ED784A3B5A4025BULL, 
            0x7CC0E54CBE00BAB1ULL, 0x8E16B6D5C17E915DULL, 0xEFF38E47EA1BBBEDULL, 0xC44F7B1707C8C80AULL, 
            0xB189FE122A10D24FULL, 0x52716E2FD7E7FAFBULL, 0x6540AE0E1D4C1CC9ULL, 0xC4EA7314AC36DC1DULL, 
            0x33DA4F3E25C86F07ULL, 0x7AABA5A55CD4F2F1ULL, 0xDA6AEE7F0C47D402ULL, 0x7E14E8F20368C5B8ULL, 
            0x7EBCCD2A92AE19C7ULL, 0x632FDA68FD88D5EEULL, 0x9F4C4CB0CEC8267EULL, 0x0535B842E0109C2FULL, 
            0xD47B48867FC7536BULL, 0x7368DC570837058CULL, 0xCB13A217B9424A7FULL, 0xA8C05CBC10811AF9ULL
        },
        {
            0xCBF7D3571B7F429BULL, 0x450C641176F63316ULL, 0xC44DEB48309346BBULL, 0x4C2ACF10A9C39E9DULL, 
            0xE3FF6404D8414848ULL, 0x246D014646889871ULL, 0x6BFCB2274DEB729CULL, 0xBFF06D9B077E39DCULL, 
            0x4DB614ED48B3DABCULL, 0x4398F9508AD71241ULL, 0x4B7946E252746648ULL, 0x2FADAE13D39E486DULL, 
            0x418F78CF19D1CA2EULL, 0x19A44F0816F42DA0ULL, 0x8FC451CF03F49629ULL, 0x0AE6002D36C5766FULL, 
            0x5112D8141BBA151EULL, 0xD0BADA5E25879FC1ULL, 0xA6B718CE0817AAA6ULL, 0x0A1D19785F5AEB7EULL, 
            0x759E99A2D4B5AEFCULL, 0x3BB1ED2A0BEE1F53ULL, 0xE97ABC802D35D80BULL, 0xF77F842CF16753DAULL, 
            0xD91FABC3CC3D54DEULL, 0x335A9A8DA2AE85EAULL, 0xBF328622F2C21543ULL, 0x23C4FF618214D78CULL, 
            0x402F1D5F3EC40249ULL, 0x8EDF8077825871DDULL, 0xBCD3791C232FC5FEULL, 0xDE6D7807074F1C60ULL
        },
        {
            0x30A79D9AA7EB63E1ULL, 0xEF5942E41D947A52ULL, 0xA6301228883CF4A0ULL, 0x7FC00CDA8667600CULL, 
            0xEC53F1E6BB8DF377ULL, 0x6ADC0338247A2127ULL, 0x375BB2DBD153C8D0ULL, 0x7C21BB808D07EFD4ULL, 
            0xF3282BA20F837EFEULL, 0xAB99A9A5DD6B8EC3ULL, 0xC6F639F65D9A8AB7ULL, 0xBB72ED0A01D83785ULL, 
            0x2B07C5103A5AEFB8ULL, 0x96B44DD0C353E6A9ULL, 0x840383C3756B702FULL, 0x392D3C1DAA477E65ULL, 
            0xF04506E1A5C6F6C7ULL, 0x55F4DCB13E53BAFDULL, 0x93A40AE7FC27C998ULL, 0x43285AB7A830ED9AULL, 
            0xEAAD7AD713AA74B7ULL, 0xE14080C8DDE8FBB2ULL, 0x82AD0A3612C071BFULL, 0x3895F4F6B52900A5ULL, 
            0x01DA70E972A7B1BCULL, 0x5BFC700608A7423AULL, 0xB41AFE8A6775254CULL, 0xC80F3AE98681B7D2ULL, 
            0x553B7F241FBF3999ULL, 0x04B3E451675D7E91ULL, 0x73679E8442972E89ULL, 0xD7DFDFFAAD75D262ULL
        },
        {
            0x4E753A483B2F196EULL, 0xEAAB92B7499FBDE3ULL, 0x27446FB15DA8FE28ULL, 0x23A446A43F4D168FULL, 
            0xBE3FBFB59DBD296AULL, 0x19C516763F72EF0EULL, 0xA473C2995E2E3ECFULL, 0x6A0E6421902BBCA9ULL, 
            0x01C7DD6309D153CFULL, 0x3ECDA57A55A7DA25ULL, 0x82051ABE87B222FFULL, 0x130F2465C08C8067ULL, 
            0xF66CE5816312B22EULL, 0x033FBA3CCBB253C1ULL, 0x71E28AF619EFDD15ULL, 0xA89BE70C6FFDC180ULL, 
            0x3927AD26B281974FULL, 0x153E91929562A0FDULL, 0x293481C708C50972ULL, 0xEA24FA2A938E70A4ULL, 
            0x45297C6F5199A750ULL, 0x962432412A9A516FULL, 0xDA61F3845695B9A9ULL, 0x5B8543FEECD56AC9ULL, 
            0xB2A8CC79066FC9AAULL, 0xF15E3956EF596B9AULL, 0xDC7C7CE38BF2482BULL, 0x7A48CFAEFC11BE4CULL, 
            0xAE021FF76BC826F1ULL, 0xF1F1B37F73FAEE2DULL, 0x1B2798866AB28FA1ULL, 0x663C7A0BC9145DFBULL
        },
        {
            0xDA1C44D6D5115059ULL, 0xB2714D45B5AEBB5AULL, 0x344B1B6D2012D3CEULL, 0x5AE416166453A8FBULL, 
            0xFA01994D187B84F9ULL, 0x1B8EAF0BC1169B72ULL, 0x8685F157A8351422ULL, 0xB6FA1B305477E265ULL, 
            0x85B9401389D62F38ULL, 0xFB4B6E397B0CD31FULL, 0x8877F4BA5C9DFBC0ULL, 0x49EF2582B7A8B6A6ULL, 
            0x5B4E070576CDF6E1ULL, 0x3F80D1528FA3AF6BULL, 0x549996F8634E352CULL, 0x517EC8EECA1D1201ULL, 
            0xB345F88058D35269ULL, 0x9DAFBB9335D7DC1DULL, 0xA2EF8979D15E08FBULL, 0xA27A5F73DA19AFD8ULL, 
            0x8A45AE66D9702EAFULL, 0x26FAA25298B68C33ULL, 0x41CD500DE07F8B9AULL, 0x855DCE05FAA44220ULL, 
            0x3AE6FF60632726C5ULL, 0xA319616A505CF39BULL, 0x6108DA7139269FEBULL, 0x3C42C11445588034ULL, 
            0xC4B1D044C0CB1F8AULL, 0x09013E7E49E674DEULL, 0x2DF86E8303135EF5ULL, 0x914673A423F9F5AAULL
        },
        {
            0x33ADC2B732A23A54ULL, 0xDB2834ECAB623ECDULL, 0x9BF8AA7FE4C247C6ULL, 0x40069B4D125145D5ULL, 
            0x18CF8331FDBD96D5ULL, 0xAC9CDF08911EBD09ULL, 0xEB2904E5F016031DULL, 0xE82F5528EAA21D67ULL, 
            0xB4D1693784CAC5D6ULL, 0xF163FCD67F3AE252ULL, 0x4A484C633E1E39B4ULL, 0x1ABC377071019709ULL, 
            0x009C2888479F5EF0ULL, 0xFBBACF17871E4B14ULL, 0xF429C85A2DFF6A60ULL, 0xC7E32AA56AD3B3AEULL, 
            0x1B41C5DB3370C977ULL, 0xE7EF5882C4D84BA9ULL, 0xFC4FE8E1747FCC98ULL, 0xAE0A4FF1A9CF1C39ULL, 
            0x41E1BC6816C05E21ULL, 0x45DAAE0EF6E29DBDULL, 0x18B4131D177596D5ULL, 0xBB236055FE00BEB6ULL, 
            0x5ACFB484E97B7B74ULL, 0x0EE78CF2CB7FEDE9ULL, 0xE2DE53F9685BE061ULL, 0xDAFEC2A15606BB54ULL, 
            0xEF0D44F321AD7C5EULL, 0x79C13FDD036B6692ULL, 0xB0FC1D8435F7906DULL, 0x516A052C6C7C06A7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeyRotateAConstants = {
    0x65AA84986080AA89ULL,
    0xA196D4C7C395210EULL,
    0x0DF7BA8949FC3366ULL,
    0x65AA84986080AA89ULL,
    0xA196D4C7C395210EULL,
    0x0DF7BA8949FC3366ULL,
    0x44F0597291759E04ULL,
    0x111D6CDD2E8947C9ULL,
    0xEC,
    0xBB,
    0x17,
    0x14,
    0x90,
    0x72,
    0x36,
    0xFA
};

const TwistDomainSaltSet TwistExpander_Polaris::kKeyRotateBSalts = {
    {
        {
            0xDF5BC91D06C99C1CULL, 0x46B9CE3DF1E7694AULL, 0xA4FC008DCB71F1FBULL, 0xE611B491FE540473ULL, 
            0x69A53ABAC6ECA20BULL, 0xEED56671D352BDF8ULL, 0xE65C29590FE1EBEFULL, 0xF0D98D7200C49F69ULL, 
            0x9E6433B7886DD062ULL, 0x2E0AC15AB7E72FBBULL, 0x968D2014BDD1712CULL, 0x7D2B495E0196721BULL, 
            0xAFE683F47A2E898CULL, 0x1CEF6CDDFF87ABE5ULL, 0x457B7151CCF649FAULL, 0xD9015FB17F30B786ULL, 
            0x0D8EB76EB74A775DULL, 0x3CB82D0C6CF5FECEULL, 0x38B240B4622DCF5DULL, 0x3C64E847C3D74F76ULL, 
            0x01FB21AE205B6C8DULL, 0xC80AC707D6F1C595ULL, 0xC34714169BC93A94ULL, 0x7B3D3993CF80A7E5ULL, 
            0x8929B3AF8F88D050ULL, 0xA8DA90FB7694EADAULL, 0xBEBB1FBA5934A82EULL, 0x5AB74C02FF404520ULL, 
            0xD3CB6332C58A9AE7ULL, 0x1C5FD6A4C6F38AA1ULL, 0x1524F396EAF6DBD4ULL, 0x7C5E20E8BF5DF2FBULL
        },
        {
            0x0563838FE2726AB6ULL, 0xCD23DDF778B7B362ULL, 0x1F08F60528BDF287ULL, 0xA26F38A9A3B084D4ULL, 
            0xD203D459F051C305ULL, 0x534811C9DF58CCB9ULL, 0x1A402D898DFE57F7ULL, 0x9C92D6EAB0E2E5C4ULL, 
            0xBD1491597722F81AULL, 0xDF9E955AF545FE6DULL, 0x57725DD5AA19A576ULL, 0x02EF54C9BAE662DBULL, 
            0xCCEB973B997B8FE8ULL, 0x9ACD7599AD36AE33ULL, 0x4AAEDF2842AB6B37ULL, 0xC9F46D790B4F32E0ULL, 
            0x8D980F6984B41BEEULL, 0xD6898538DDF0C825ULL, 0x06E5F54B9226498EULL, 0x75BB94D4DE2A35F4ULL, 
            0x70BF53652840FB53ULL, 0x2C98AEC68B261623ULL, 0x64408C9F446EAC52ULL, 0xE9557D0A4BB013E3ULL, 
            0xD545C8DD14ADDB5AULL, 0x8CDE456A5ED2E8E7ULL, 0x70D99812DFE7DF1CULL, 0x4ECD335065F41917ULL, 
            0xEDE0A88071A1FD04ULL, 0x86EC0013833ED003ULL, 0x808530583D9FB59DULL, 0x347AD403B503CC7BULL
        },
        {
            0x5C66F5127C5ED8D6ULL, 0x5976340943A951C8ULL, 0x456946478787EE90ULL, 0x6A0B00B5BB3B2968ULL, 
            0x942A943386BC1D15ULL, 0x870580E15312A45CULL, 0x374F87927ACDE11EULL, 0xE2D785E1A49D36D2ULL, 
            0xC1C4B9F356A7F8A8ULL, 0x8B2F02A52D997F46ULL, 0xA1EB60CC427B1379ULL, 0xC3C7472986247DD2ULL, 
            0x96A127E021CD0A9FULL, 0xC88C7DA8C0483A7DULL, 0x661B312E3CFC7C96ULL, 0xC75F5C3223AD7C14ULL, 
            0x48F41376B519EE51ULL, 0x17114F0246454889ULL, 0x7B8942091FFC75C0ULL, 0x6AEC923524ED1601ULL, 
            0xA7498CFEBAEDD69FULL, 0x3BF1AFC6FF4D9B59ULL, 0x415EECDB940CE911ULL, 0x3D7A4EFE357E6A8AULL, 
            0xC09CF22C6B6FED82ULL, 0x6A99286D98616818ULL, 0x842DC484DAE2983EULL, 0xE4C30393BCBC1006ULL, 
            0x398386D6E85E2463ULL, 0xDF931B809193757AULL, 0x91B31AE7D3CD4637ULL, 0xA4278F23548E4F91ULL
        },
        {
            0x7207C90940237149ULL, 0xFB6851C0B0BF5300ULL, 0xC9087512A01C6CB2ULL, 0x0FAD70DE1D1CEB03ULL, 
            0xE9DF3D955B0B117FULL, 0xAB7A6D587627700CULL, 0x03D35303E8CCE3E9ULL, 0xE85212229E92A959ULL, 
            0xB8CF3AA895D26C53ULL, 0x3D5D286CEE95AF3FULL, 0xC9B8070B3D7C5AF4ULL, 0x215EB96162A8AC32ULL, 
            0x7907FE8602B5A578ULL, 0x4D54F74D45EA1526ULL, 0xFDF5B31976E5CFDDULL, 0x0E7DFD32F338B23AULL, 
            0x84E862C02DDBE830ULL, 0x6A9C6B1170DEC525ULL, 0xAE2D92598568B761ULL, 0x074D5E644EDA19FDULL, 
            0x38F1FAFA9E57E1C0ULL, 0xFA7E7EAD32F364D8ULL, 0x4CD550CFDE684283ULL, 0x77449B8185FF2A51ULL, 
            0x1D72C2E7A35ED0D7ULL, 0xC11C6E8928A3332EULL, 0x32DEB1C2F538D1CBULL, 0x07EC4C39586F2ECBULL, 
            0xF492A47A2CEC97BFULL, 0x4B6FCDFE1DA73D22ULL, 0x0CDE5DF8D1EAD289ULL, 0x32739905FE37A476ULL
        },
        {
            0x7C4B74736C9F4EE3ULL, 0xED55E20A8EE03A1FULL, 0x9427731ECBC1A7B9ULL, 0xB8E190F53ADBE443ULL, 
            0xC326FC6824F81F02ULL, 0x0FE091F678831A98ULL, 0x7D4A891062953D35ULL, 0xEA3CD96918DDD749ULL, 
            0x356E375CE491F7B8ULL, 0x6018BB5C99F16EF4ULL, 0xA65037647A786E45ULL, 0xB3C8891667E5724DULL, 
            0xE3391769A50143F2ULL, 0xC578F7076482FC2BULL, 0x734F5D91DF4EBAC5ULL, 0xF7C310747A562C8AULL, 
            0x98EC493259CA71BCULL, 0x1BEA3E91327B6947ULL, 0x166C4DFD8121F60BULL, 0x59A0B1D2E03DE231ULL, 
            0xA3A2C94426236EADULL, 0xDA4A19413CC63015ULL, 0x927B033943FCECA6ULL, 0x44D6BBA18928CCCBULL, 
            0xD6F590F5FEDA9FB6ULL, 0xF763594486E699FCULL, 0x62E63189D93F8545ULL, 0x8E8153AA8599526EULL, 
            0x7502B65008B6C6A7ULL, 0x971BE669DEC66882ULL, 0x31E78193C47CF945ULL, 0x39F2287E9A51DDC5ULL
        },
        {
            0x90F6E5260A714D75ULL, 0x1B8F8C3E22B5C48AULL, 0x7E9ADCD3CD88742EULL, 0x38DD8A562FBD381BULL, 
            0xCBC264479010AC45ULL, 0x66A377F3F7E90ECEULL, 0x4134D2C72B488855ULL, 0x8E174EAB0E9AACEEULL, 
            0x7F823EB7346997CAULL, 0x1C31AA405161201DULL, 0x1816B69136F140F5ULL, 0x2F2E78A7021BBB21ULL, 
            0xF8C8C0BB192D8081ULL, 0x42F4A7702CB0982BULL, 0xC7851F561A3CC8DBULL, 0xB58AA7D7DE9DFF1FULL, 
            0x3CD147449425F829ULL, 0xF3FE98F08D3E84A0ULL, 0x70860C86FD56F2EFULL, 0x88A3F514DCC5651CULL, 
            0xBCE1F1B56DAF68CDULL, 0x57FDD47BB41E27F8ULL, 0x3D8B35DBE50569D9ULL, 0xFD39EA092B3BAB24ULL, 
            0x66D072DF942A6FFEULL, 0x7A23BA4D3AC4BDC1ULL, 0x7596C95062168B66ULL, 0x8ABC2095036CA1F5ULL, 
            0x6E737E8B52882FC6ULL, 0x691C28095AB2DC23ULL, 0x41EC89D7568CB67EULL, 0xE96DA10ADC2CD381ULL
        }
    },
    {
        {
            0x26E79613FD816B6AULL, 0x3C3B38833E44FD14ULL, 0xE560D365CF2D848EULL, 0x627C8935019A857BULL, 
            0x3202DF854A465441ULL, 0x6EE4B8EE46309843ULL, 0x638AC116AF7A9064ULL, 0x21708824D8640FB9ULL, 
            0x21EDBC3A20EB9F08ULL, 0xCE795A45AC8C41A4ULL, 0x8D377791F2FDF1E2ULL, 0xCEEC07D894E39F4BULL, 
            0x2605FA9D2BDFFE3DULL, 0x2D7417E7C12E339DULL, 0x406F51DDE1C45093ULL, 0x7357BA73AF7837F6ULL, 
            0x47C76249F903F42FULL, 0xCFE98380FC38E5BBULL, 0x0124F28AADC01EA6ULL, 0x48A114847F902BDDULL, 
            0xE15F16449988F876ULL, 0x01E1F25C24ECCF2EULL, 0x375607E4475D1EA3ULL, 0x4B8EF70F2C539271ULL, 
            0x013B155FD0A18C20ULL, 0x304336766A07D23EULL, 0x47CD8EEBE5F3C81DULL, 0xEFBFE97DF00A8336ULL, 
            0x1E11ED2ECD5E3C64ULL, 0x05DB093D0FAEA376ULL, 0xBE06AF68DFE3BF1AULL, 0xDC210501FAD8C4A9ULL
        },
        {
            0x72302DB20ADDA777ULL, 0xF8BCABD5089AA3A9ULL, 0x06C9A1AB27F395B0ULL, 0x4207EE60203EA208ULL, 
            0xFAD45369BF7F1199ULL, 0x33B2890FFD1E0B87ULL, 0xE81C5664B07BFF84ULL, 0xB64D99C7A3547030ULL, 
            0x3D37C93FEB1F4749ULL, 0xB83CBEAF743A3E48ULL, 0xC15669B86485B822ULL, 0x7BE6A9675E9983D9ULL, 
            0x123A48B6719D9BE1ULL, 0x2291C0698D4152FFULL, 0xB9A57CCBEFED8472ULL, 0x773F7B875FD1BB4DULL, 
            0x0954766E7650F090ULL, 0xDE3609895FD57029ULL, 0xDC0A84A05B004991ULL, 0xEE05495F2D6C836FULL, 
            0xA869029D6DED2D69ULL, 0xED1CA132E9927C31ULL, 0x4074CCD1CD07343BULL, 0xC54D94853F7B9C74ULL, 
            0x26195E37E9B96B69ULL, 0x604157E1E777C330ULL, 0x55C25D31A144F184ULL, 0x7B0A487BFCA28F43ULL, 
            0x6324D0349AF2D65EULL, 0xAC63CEBE98F67621ULL, 0xC5AD1A2842912E92ULL, 0xD4C325119E97E2E2ULL
        },
        {
            0x5BF1200D1903B76EULL, 0xD9C73C89DCC60948ULL, 0x63CF23AB66FFE975ULL, 0x24209F217F816D76ULL, 
            0x9F20237266B70FACULL, 0x47AC7681BBD47F10ULL, 0x932255853FFE7035ULL, 0xDFF3B49EF18B1BE6ULL, 
            0x1BE9A3FA34191116ULL, 0x846F9B6E8EA2914CULL, 0xA85ED8B299A555B3ULL, 0xFBA44023CE1B70B6ULL, 
            0x20DF0B4820434CD2ULL, 0x1383AA0FB0D3BC74ULL, 0x120BEFB6BB484262ULL, 0xE95FC0F9A3701F4CULL, 
            0x6BA802088EAA9E65ULL, 0xEC919FCD792D2FD6ULL, 0x6E4C357CCE92F0B4ULL, 0x6183AA6217E602E7ULL, 
            0xF27C03D58ED4AE91ULL, 0x6A6A7BFDB8BBD4ABULL, 0x6558C40B2773A7E0ULL, 0x14DE4B8D3AEFFBB9ULL, 
            0xA0CF6083416728E5ULL, 0x67C1FB84DBCFCECEULL, 0x9116DC17D91C6073ULL, 0x2C77611249167F41ULL, 
            0x49A249E96EF2F342ULL, 0xDB3A8147E6F4BB77ULL, 0xBFBC6E3EA9159EDAULL, 0x0745D9DDE80B6F42ULL
        },
        {
            0x384A4C52ABD96EEDULL, 0x7B54BE2568DD04DAULL, 0x517B0CC6E77244AFULL, 0xB1ECED8F073F60BAULL, 
            0xC25A497F6551DC77ULL, 0x484046BDAD28EC0DULL, 0x6962D070BCCDF7E9ULL, 0x645016724B4F559EULL, 
            0x8D1EBDB94757F503ULL, 0x8FB359DED19D64ACULL, 0x342D404FD8CD42EDULL, 0xB1A963DBB6F4EBEBULL, 
            0xE72020C32CFFA8B7ULL, 0x5ACAE2CAF9A34D87ULL, 0x31898B94F64221AAULL, 0x830A1FD049245B02ULL, 
            0xF76A03BDD00CCBB8ULL, 0xF3137104745CDEE8ULL, 0x05A36037587FC9A3ULL, 0x947F9532E014F096ULL, 
            0x765C1A564DC138BBULL, 0x01B4E2AD85CF1CECULL, 0x7A4E632B462D670EULL, 0x890C88EA8C51C72BULL, 
            0xFF07C13DBBFDBB09ULL, 0xCDE11AAB0A0408FEULL, 0x60C2083177B1ECFAULL, 0x5B1A4FDE36792C3FULL, 
            0xA66B86A60E38A43CULL, 0xEF94AA614595242FULL, 0x861DC060D8B024A6ULL, 0xCCC93EE381A31817ULL
        },
        {
            0x6A6B5B4D31F48311ULL, 0x9B273371CAC5C9D6ULL, 0xF793198CDFAB4D84ULL, 0x8EF55B05F0AC8584ULL, 
            0x5EC7BE9E4EF0C8E2ULL, 0x4A8220A7B49DB277ULL, 0xCA030C3C218D959BULL, 0x161845B01C6F760AULL, 
            0xF1A89110922F934DULL, 0xE7419978E8431C14ULL, 0x5C36D356897168A5ULL, 0x3CFEB6949E3B0C89ULL, 
            0x0F4A6220750F35A2ULL, 0x062083D9EF8900ABULL, 0xB644A1C6D47CEB88ULL, 0x44FAEDC29F5A6800ULL, 
            0xE13EF48C014BAFCAULL, 0xAB67E9D281A2CF55ULL, 0x73335D5C7E1647B3ULL, 0x8D8078F930EC1A12ULL, 
            0x7C720B2FD2568FC3ULL, 0x419ED6CCC3FFA763ULL, 0xC1C7427AF42C21ACULL, 0x78BD128CD3E1F8B4ULL, 
            0x6F94723025AC1D9FULL, 0x4F2DD24745D44886ULL, 0x80EDD6AE3F43CE18ULL, 0xAE0E7EF0CFC2AC6FULL, 
            0x853CFF14E1C2C7E1ULL, 0xAADCBFEBBD391AE4ULL, 0x83C9E47F17B09823ULL, 0x38F4009E9EADD585ULL
        },
        {
            0x688D3423EA8A6696ULL, 0xEE6F1593C007F22FULL, 0x1D6C4366B65DB593ULL, 0x47FDF99F4BBD582BULL, 
            0xD905C9BC87ED7A9AULL, 0x3D051E40B6B86C94ULL, 0xEA70E1E2D3E0B1B2ULL, 0xB87004BE209122CFULL, 
            0x13D84C2FB8D88BEEULL, 0xD49823D9E4A03370ULL, 0x6CAF5A615B0EED99ULL, 0xCFF896532DEAFA62ULL, 
            0x1A5361265A6F8861ULL, 0xFBA076EEFC22A767ULL, 0xBDF115D301768A26ULL, 0x805B38B0FDB48DC3ULL, 
            0xF620B7275E01523AULL, 0x14572A9B19944B36ULL, 0xB0362A5D651C3E3BULL, 0x87AEF03565B8F775ULL, 
            0x6EE914087BB8FD69ULL, 0xF14C2683C413559EULL, 0xDF2206CC6897DA76ULL, 0xEE59C74AC62E9192ULL, 
            0x061D5E74732A7DA1ULL, 0xB231EE8E7E78F93BULL, 0x3C29727EA499073FULL, 0x55A53DB0F435A89EULL, 
            0x129584185047A899ULL, 0xE5686FFCFB75293AULL, 0xA24EE23F1CE098E2ULL, 0x83946CCFC58BC1FDULL
        }
    },
    {
        {
            0xD4FD7C17451A169BULL, 0x185BA93ACF4AFD82ULL, 0x2602A6DC24688D21ULL, 0x589561B2E72F640FULL, 
            0x33DC40D09DE34D07ULL, 0x0315DE97E74502ACULL, 0x30FECDB8D2BC76ECULL, 0x7F3CFF30E4F4D3ADULL, 
            0x9D07B21A0B9BD55BULL, 0x1CEC481AFE4B1D11ULL, 0xB1A4649CB002A7A5ULL, 0x0568AF824BD26B06ULL, 
            0x0D5122CE10841A1EULL, 0xCBDF00404B330789ULL, 0x5DF10C0263D19DE4ULL, 0xEAF655A7A50A0971ULL, 
            0xDCE86475104B316FULL, 0xE179E047FE028FB4ULL, 0x6F5D694BADE06E06ULL, 0x6F1047DEA6F1A38CULL, 
            0xD1CE128EA5C8FB4CULL, 0x16A8E876BDCC6DA5ULL, 0x672064D5510CD0CBULL, 0xCA283E5D8CD4DB05ULL, 
            0xECA2F3A7F7F973DAULL, 0x4BBA899BCA49FD7FULL, 0x940F04A0F1689273ULL, 0x0F7C9BB4DBD02F9CULL, 
            0xD3CE31C65BCD9D3BULL, 0x38BFFCF6ECA8B6C7ULL, 0x40C79F75C3D3D89DULL, 0xFEF3E799291FD7CCULL
        },
        {
            0xF564BD74F396A944ULL, 0x8A090B463DEA6693ULL, 0x668C012B0573631CULL, 0xF89B62688105BB17ULL, 
            0x1BD8AF0C187857E8ULL, 0xD007A5375F0E9E7DULL, 0x5B865E59A69ED52CULL, 0x273049CD4C65A5C0ULL, 
            0x0A0F5FA3B11B482EULL, 0xBA47B84FF0ABC7DDULL, 0x2098755CE8BE27D5ULL, 0x30E119C97D11AAEEULL, 
            0xFA1E3AAB8F3B2381ULL, 0x82062E219AC01B44ULL, 0x13294D113B3FC612ULL, 0xC0E622388D0F756FULL, 
            0x6B7EEEF091A7325CULL, 0x47F22E46526BDEB0ULL, 0x054397BDA7E4DDC1ULL, 0x2CC52D5650A5920AULL, 
            0x2DB5EF234BE49AADULL, 0x92BFE47EFCFFF99FULL, 0x896D8A0B8422BF62ULL, 0x4B2D2BB1D4891979ULL, 
            0xD7173B58E70539ACULL, 0x7EB76E29BB66FD82ULL, 0xB733EF4B0AEA249BULL, 0xCB11D7EC724A38E7ULL, 
            0x10A3A0736D06C9E7ULL, 0x94334FA3D3C91B9FULL, 0xAF6BA90EF756D853ULL, 0x9AEFBEE8E00C2C72ULL
        },
        {
            0x6622F8066BB1B04CULL, 0x3267F9421395FC49ULL, 0x04949FB4AA045B38ULL, 0x2186555DCBD08268ULL, 
            0xE957B7865783BADEULL, 0xC60E9C95A669A256ULL, 0x75FB0845A1AF2085ULL, 0x5C8D9E9097B9A2A2ULL, 
            0xF4268DD35EB31BAAULL, 0x49EAEDB2A834495FULL, 0x72BB1B78119A6D3CULL, 0xBD55E8176989372AULL, 
            0x25162C71BEAA2642ULL, 0xC491076877A262B2ULL, 0xD071BAC3A708DE8AULL, 0xE4A4147AA804251BULL, 
            0x1F34BE48DF7D5F8BULL, 0x7BDB6DB594868BAFULL, 0x14E02EA767FB70E0ULL, 0xE9F8FCEB2723ABE3ULL, 
            0xF1D64013B37BC3ACULL, 0x6A4B4FD1E24B3E48ULL, 0x68022CFFB6BF4425ULL, 0x6D3FB9D81FDE6817ULL, 
            0x92BB63AD04E9FA45ULL, 0xC132ABE7D4E20C65ULL, 0xFD06E6B6A3C5D75EULL, 0x6BF92F1EE0967770ULL, 
            0xFE96B189E11BDDD0ULL, 0x65BB7E615359AFDFULL, 0xA294F67A1D68FA78ULL, 0x2EC901FC15667060ULL
        },
        {
            0xCA87F745668E0C50ULL, 0x4366952E1ACA36CFULL, 0x732AFF892103F097ULL, 0x44B994B2C4004F98ULL, 
            0x258D23012556F5DCULL, 0x0EF9B8B00861C705ULL, 0xBC065AF11EF24154ULL, 0x553AD17A23386A0FULL, 
            0xA3DE13FE4AC99532ULL, 0xA5A18FF1D229434CULL, 0x4FB1DB157A44A8BBULL, 0xA0A27D88AB51B879ULL, 
            0x7F11E1B92726898DULL, 0x5645EEC4B79350CFULL, 0x7259A1054FF00C06ULL, 0xFB0F73ED77AA80C5ULL, 
            0xDF1839C80159AD80ULL, 0xBC281DFB2693D2DFULL, 0x5F7E2BEF2810EDA3ULL, 0xDABAFF5A9C4E23CDULL, 
            0x06D0921F287B1402ULL, 0x22210D57DCACEF62ULL, 0xDAE98C9AD85E25D5ULL, 0x474DF49668361C9EULL, 
            0xE9A832F9B0C8DA8BULL, 0xF5F1AE156A35BA38ULL, 0x8DF06515F3112381ULL, 0x3A8DB7791C7127C7ULL, 
            0x1360A54F3A2FF907ULL, 0xA206F8D2BED7E30FULL, 0x687DA731F6EE8AA1ULL, 0xBD1ACD032CB68DFAULL
        },
        {
            0x5CAE2C6105B98976ULL, 0x3512625FC3B90C7BULL, 0x2487EB50FD735F84ULL, 0xFAE0400050B12300ULL, 
            0xD14BF7CEA3B3A353ULL, 0x280BFD086B79C9CCULL, 0x14C7DB1B0FBC6408ULL, 0x318D70A0107D6459ULL, 
            0x9B6395C380EED6D4ULL, 0x0F8F7BAFDD64577FULL, 0x1FB807AB6E91EB3BULL, 0xB718DE3A4E75A415ULL, 
            0x31D9F9E91F3CB257ULL, 0xAF03D8FD9DE0844DULL, 0xD3DFD2FCB764C52DULL, 0x949E362A2117256EULL, 
            0x9EE9B6F530A4B40AULL, 0x729588E1145D3A22ULL, 0x466B3C70EFE47A80ULL, 0x4FDA75DD7B4ACDE1ULL, 
            0x383E22AF110EB0DFULL, 0xE114BC769E27DA5EULL, 0xDB940E1278EC95FAULL, 0x463A9E313862E2EFULL, 
            0xA81897CDA0EC1B40ULL, 0x52B7AF792D678F47ULL, 0xDA14042B8A0000AAULL, 0x2889506372B47BD4ULL, 
            0xA60AC738EEEE4509ULL, 0x3520C702DCE3DF03ULL, 0x2664A740D749B762ULL, 0x6824587FCEF70FD9ULL
        },
        {
            0xA2C55D019601C65DULL, 0xC97560AC65A1FA86ULL, 0x6EB35E5DD86F1C2DULL, 0xF91EE82034CE9877ULL, 
            0x74496C11D00029A3ULL, 0x67AF85C2C26BAA02ULL, 0xBAC09F3726DDA5A6ULL, 0x5D17D05C044244E0ULL, 
            0xCED75A93AB4D2BC1ULL, 0x48F010EACD19F73BULL, 0x7AA47D90927F5A4EULL, 0x24E8ED777D9BBE14ULL, 
            0x88CFA44BDCB15DD6ULL, 0x532DB96CF49E0453ULL, 0x5744FDCC3FB72FF8ULL, 0xF9EA43D29EE8F169ULL, 
            0x1A097557ED0F790BULL, 0xA8AC3D2D41AE6248ULL, 0x4E0D3A2BCF4B68E5ULL, 0x295AE090A7A71CB1ULL, 
            0xE188930997BC7D47ULL, 0xA5F13BCBB51FCDDCULL, 0xDB51F1CA1952191EULL, 0xEB911C05E4FAB06CULL, 
            0x322B82A2827E8F61ULL, 0x513C104AF6669735ULL, 0x4766C806D9C20999ULL, 0xE7A7FAC1433900D1ULL, 
            0x49E7ABD6B842E29FULL, 0x8BF9E8CD219714FFULL, 0x5C2DCEE69FFF6E40ULL, 0x82E6E64FAF9EF3F0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeyRotateBConstants = {
    0x1B084C98C92B0B7EULL,
    0x470EC69A52E7F420ULL,
    0xFFCE9F9EDAD762F0ULL,
    0x1B084C98C92B0B7EULL,
    0x470EC69A52E7F420ULL,
    0xFFCE9F9EDAD762F0ULL,
    0x7BC7DD4171E7D8CCULL,
    0xA666E64F5007724EULL,
    0x92,
    0x15,
    0x3A,
    0x04,
    0xB2,
    0xAD,
    0x17,
    0x05
};

const TwistDomainSaltSet TwistExpander_Polaris::kKeySpawnASalts = {
    {
        {
            0x3C94638E98D72761ULL, 0x7E22B5CFA14D7901ULL, 0x689106C4928E1850ULL, 0xB710B7691E4F2A12ULL, 
            0x597E40B284222595ULL, 0xAFDBCAD0B1C5A3B3ULL, 0x8640393AA1336145ULL, 0xE6BCE9F7CF4E4113ULL, 
            0xED57EB82EC50CD07ULL, 0x89A39CEEA21D978FULL, 0x5526D6813D555C97ULL, 0x8B64ACA4598E337FULL, 
            0xFE6C10A1DE73F880ULL, 0xEB41EB0B41183D0AULL, 0xF45AB0DC790BB52AULL, 0xB9950DBFA4B55F44ULL, 
            0xA20F987042D19D83ULL, 0xB48F3053C9C02DEEULL, 0x98C3D1FEBA105023ULL, 0x3284BDD55B55C781ULL, 
            0x21727F423EFA4914ULL, 0xADF63C7FDFFCF78EULL, 0xA5F7E35BD792F9A9ULL, 0x577E0FD9381F913FULL, 
            0x67E7A5217A2A9F44ULL, 0x8573550F22378AACULL, 0xA13FE23ADC624364ULL, 0x0CDB09988DDF91F5ULL, 
            0x67BB2C021C91AD9BULL, 0x2F1D63D6494E29F0ULL, 0x1AE1BF63C87C0BA1ULL, 0x420D8466A3B72131ULL
        },
        {
            0x6DADD9EAA8043BEBULL, 0xBCBCE05E6EC75E8CULL, 0xF173E3C347F4955EULL, 0xF27C59070E995E3FULL, 
            0xC8CADA280C03FFA4ULL, 0x7824D02CA3CD5399ULL, 0x83772A82C37FCA36ULL, 0xE78CB3F363C59266ULL, 
            0x7387EA8FDDC6AB59ULL, 0xA2928BC86F03FAFEULL, 0x617AB74370C0621FULL, 0x9CE8A95262319AD5ULL, 
            0x223ACAA269D71EE4ULL, 0x8A0C7D4CADE679D1ULL, 0x035EADE32213D809ULL, 0xE0F75651496107CFULL, 
            0x30FB363D10BB7A19ULL, 0x3D5CC1C2CBB4803BULL, 0x0598CA057F4952CFULL, 0x8971FDE1BAD2909EULL, 
            0xB6082CC0E708D3E1ULL, 0x5ABD22F7D1CC2524ULL, 0x8294B8B8F0143687ULL, 0xB157CC3DA2774B73ULL, 
            0xC6BF8E077406E9DBULL, 0xF7F1E3AF6B5EB52BULL, 0x13EF3FE3AAC5812FULL, 0xEFEA81055AC33B39ULL, 
            0x8391AC4C33D47073ULL, 0x4C2E473AE02D5796ULL, 0x17E6046FC6DACA35ULL, 0xCA43CF5E3D8CA3F4ULL
        },
        {
            0x1A29E0732C594E42ULL, 0x635AAA0026F8810EULL, 0x367DB2FE800A1B1FULL, 0xD7467E712EB99A5DULL, 
            0x6F5A2288419A189CULL, 0x66C945F4261A3DB8ULL, 0x7B0118A1ED0860C9ULL, 0x0ADB6EB823FF4C0AULL, 
            0xB5B90CF4D80311EAULL, 0xA67575F6CBE66110ULL, 0x1EFBA891C449A312ULL, 0xE5F6ECE6ED99D0C8ULL, 
            0x9B72784EE673FDA9ULL, 0x961E2196900FCF92ULL, 0x1652E14221811F88ULL, 0xFD1A93CCB93F5799ULL, 
            0x245115B4303AFC79ULL, 0x2870B1BDA878B99DULL, 0x26B35D48BC82A211ULL, 0xBE742A0B583DA82BULL, 
            0x00168136E37FE32BULL, 0xEBDC06B0EC749C71ULL, 0x0A275ECB6AFDC24BULL, 0x245F9A1EEA3F5E18ULL, 
            0xCE3EB24491C9178FULL, 0xCB9CAEC03E69A200ULL, 0xC26813AC3053E665ULL, 0xEB1D03CB283217DBULL, 
            0x88E003EC77E14919ULL, 0x36A1F1EFF9643F38ULL, 0xB1770509FE45A105ULL, 0xE86E14C3F6CEFE09ULL
        },
        {
            0xA2B00758B4EDF6ECULL, 0x7E90FA9C578BCC54ULL, 0x2BF43E1B80A3BB9BULL, 0xD9A1E1013586ADB1ULL, 
            0x7B83512305259E05ULL, 0x86BFF1BB77AEE202ULL, 0x961C13122ACE3D7DULL, 0x41DF3B186AAD61E6ULL, 
            0xE30C85F87F886B91ULL, 0x295150EBF479C93EULL, 0xE768758BB2C24D00ULL, 0xC6EEA362DB834C53ULL, 
            0x28AB40CB9F75B714ULL, 0xA2FAFA19D46FABFAULL, 0xBA866E796A40564BULL, 0x95E574984B643823ULL, 
            0xA5B82C05229F70D7ULL, 0x001C3981FB0DA5DDULL, 0x6C76BCD1F5442728ULL, 0xBAF0555A3612F9F2ULL, 
            0xAF8B89F6B4734AF3ULL, 0x11AA282ADEB0AAE8ULL, 0x04BBDB9DB6EC1D0DULL, 0xA35B79F6523A5A24ULL, 
            0x9A033314C973B592ULL, 0xC7D0718E4CFE9E38ULL, 0x0BCD1CA3A07B390DULL, 0x6BD26E89E3A7A80FULL, 
            0xDEDE3139C446DCD4ULL, 0xD80FC0758614773DULL, 0xE90BCCB6445FA32AULL, 0x43A583A4D585F71DULL
        },
        {
            0x8D9EB8EF49435CF8ULL, 0xA022C75C92B593CFULL, 0xB1C236FAB414C642ULL, 0xB294E8E588D988EBULL, 
            0xD8F8E75DF24252D1ULL, 0x6F429126E4652AC8ULL, 0x093CCD75D02DB8F7ULL, 0x6FA7AC765D7D074CULL, 
            0x2A2DFED377D55D47ULL, 0x92E62172053F2DCEULL, 0x7AA9C1E9C6809FDFULL, 0x5371B25D48C86B12ULL, 
            0x7D01B4F51D56AA36ULL, 0x20FF16F4116C7FEEULL, 0x9BBEC25FF4226DFBULL, 0x200FBC9F2396A051ULL, 
            0x3C0696BC44BA4111ULL, 0xDF310E322385E082ULL, 0x788AA80D451B9E10ULL, 0xDB535C8361B7207AULL, 
            0xD4E3B7E71F5F07B1ULL, 0xFF44DAE5D0AC42C4ULL, 0xDBEF1D321A9F41BFULL, 0x1BEE7615CEE06986ULL, 
            0x5FF6F88F7F332A97ULL, 0xFD5A1A988F545E08ULL, 0x04D334EAD180DC44ULL, 0x794CE6E995B92629ULL, 
            0x8A06B902857FD606ULL, 0x1DD65E87F20056CDULL, 0x6797D5BCAD8F9C29ULL, 0x7A2418CFA264C9ACULL
        },
        {
            0x8E029AAABEFBB1CEULL, 0x00CE5BA80BD502BDULL, 0xCE022574079FB82EULL, 0xB138A8DB6C4BC181ULL, 
            0x41A0A02A252CCEFAULL, 0x5598610EB41F3D74ULL, 0x663F5769991D4FA9ULL, 0x6CDCDFC061CD9DB4ULL, 
            0xAB2FBF768B392EE3ULL, 0x7713C2748683DD68ULL, 0xE7A7B356F77E180CULL, 0xEEB998D2D99631A9ULL, 
            0x8E4240F61D148D8EULL, 0xF3246D4202527C4BULL, 0x6F18E038CA1218F9ULL, 0xD233337094A46F32ULL, 
            0xF76A054128CBB457ULL, 0x56CAD5C69CF6CF67ULL, 0x5F1F5B76DABFE625ULL, 0x8A13E579B4C1EB56ULL, 
            0x9A5F28F8DD6C2383ULL, 0x2374B51F7D0F6FFFULL, 0x6496DDED80D1750DULL, 0x8AA94D0DB6A9FB32ULL, 
            0xEA9FC99921648FB7ULL, 0xD5D91E4CB4DBE784ULL, 0xB06B37AD0D60D8D3ULL, 0xADED6B83B664ED76ULL, 
            0xA623A1014D5414F6ULL, 0x769B110CE024C55CULL, 0x2FE0D7FC56F32CCCULL, 0x5B5D37F4208987E9ULL
        }
    },
    {
        {
            0x4FBCE67D585C0965ULL, 0x76008EF90F0EB4F2ULL, 0xE6BF49F7519C82EFULL, 0x26FD4318C2A4ED25ULL, 
            0x6929B53D66B2AEEEULL, 0xE6EDAF60F4588A04ULL, 0x8B0A695F9687C8F3ULL, 0x7B5AB8D290E2530EULL, 
            0x16CCB8A802D9F3F1ULL, 0xD415E0C03877F293ULL, 0xD04B36E2B7BB1F96ULL, 0x3EC4A03DC70D9A43ULL, 
            0x05FA5278E076FBC7ULL, 0xC6B8CD107C9E4CCAULL, 0x7F9B20BE76FD7187ULL, 0x163B22720B028432ULL, 
            0xCEB587E597BF7904ULL, 0xC3E5E71F3D10DF3CULL, 0xA6BBDF79C8485BD2ULL, 0x1F80829A2F1E8512ULL, 
            0x75E75A51260601C3ULL, 0xDAE88F7972B98A3EULL, 0x3890567418915B5DULL, 0x545708CC295E02EAULL, 
            0x06FA66BB3065867EULL, 0xE0AA1E07E7D8751DULL, 0x5EB4D944D165703FULL, 0x7869F2F2F8DC6C10ULL, 
            0x104615EFC1B2DD2AULL, 0xBFBA4C12C2D1B2B6ULL, 0xA792B1D7FF634212ULL, 0x0C71C1121E5DBA41ULL
        },
        {
            0x81D6BF72D4A144B8ULL, 0x53ACEF79A5D4AE56ULL, 0xC5000352050F7AE9ULL, 0x6F142CC5BEA65366ULL, 
            0xA337EAEFC875FA54ULL, 0x0AA0F8128D934E26ULL, 0xA3C64D22D67D07CEULL, 0x1110B80339903EB7ULL, 
            0xCA8147D81133DD7CULL, 0xCDC398361E6E1D05ULL, 0x97161234772386C5ULL, 0x2D3953EC3F9D6ADDULL, 
            0xD4290904F94E1EA7ULL, 0x52525D9C091F54B4ULL, 0xD9672E515EC4DF5EULL, 0x295A5D3AF6803ED9ULL, 
            0x0E41AFB1E1B69D17ULL, 0xFB22D31598E941F1ULL, 0xA9BFD1DE9BF5CAFBULL, 0xBDE230A162D70E2FULL, 
            0xF60BCB8B8B5AC168ULL, 0x065904A012E7A31BULL, 0xBD3B601CADD86EA9ULL, 0x83BED2BEE5817493ULL, 
            0x01A3B0A50E9E8B34ULL, 0x2DA836B30571B22AULL, 0xDF4A68B5E7275C4EULL, 0x08A11EF73D95F514ULL, 
            0xE97ED29DA0524D2BULL, 0x509ACE80829C5576ULL, 0x6492C3CDE1980D74ULL, 0x2681E24ADEDB01C4ULL
        },
        {
            0xEBE681368FE61C34ULL, 0x34606847E7805949ULL, 0x092D53F3F6E81914ULL, 0x280C0CF652617255ULL, 
            0xB5BFDF6FFFD35D4CULL, 0x5192AD117CFCE581ULL, 0x61CEA88EE49E3D6FULL, 0xB5D50F46C149E050ULL, 
            0x997A25F1AAABFB81ULL, 0x1BE32A065D0F97D6ULL, 0x3CE5950C47AF65A8ULL, 0x3837864BB6BC7C11ULL, 
            0x3F384C6ABD9C193DULL, 0x9803093D87D95A33ULL, 0x7EB296B7AD7673A4ULL, 0x03E54575C0B593F1ULL, 
            0x22BE910A153743D8ULL, 0x248F5F5778C0BDBDULL, 0x9BE2B631C1709570ULL, 0x699FEFFE97AB788CULL, 
            0x5B8356E2CC08530FULL, 0xD22B17FB9D64E71BULL, 0x0604304B0564C098ULL, 0xAA44B206EBB17ACCULL, 
            0x9A6718531E3E9548ULL, 0xAA6A3450F4958A8AULL, 0x900C68AFA2BC8408ULL, 0x816E75D9149BEB6FULL, 
            0xD5AA5C91D031CF7DULL, 0x31FD872E0F7DC1A8ULL, 0xAEF9DB0E15F2FAB2ULL, 0xAE847D4524C890F3ULL
        },
        {
            0x18E0E09643B5F83AULL, 0x95B646B74A3CC37CULL, 0x79BCBC08D9E37AF3ULL, 0xA14EF053606811BCULL, 
            0x51CC456AFB2D0A73ULL, 0x6133244ECF27E32BULL, 0x29433CC3481358F1ULL, 0xE5C7F5EF46F26A4DULL, 
            0x48EFB78169EE00A6ULL, 0x45053E9ECE14E377ULL, 0x9347F9EFACE78373ULL, 0x638E84D21BA6DC7DULL, 
            0x9545859481A027E3ULL, 0xAF917E47C32B0902ULL, 0x11BFDBE0E51E9DDDULL, 0xF977273DE482F882ULL, 
            0xE4BE6E265C4A7E74ULL, 0x10F33CCC3EB81FF7ULL, 0xA950061565A37C1BULL, 0xD4D55AA0E6F01FDAULL, 
            0x3A65CB6AAD277B2CULL, 0x95A20D14A1B9CF0DULL, 0x4CA9B278E6165BB8ULL, 0x71189CB557A01073ULL, 
            0xC38B97ADFECECDBDULL, 0xDF3820614D5698E3ULL, 0x59DE74278CF42F25ULL, 0x547E34DE9DBBE9B0ULL, 
            0x9C489F4695C9947AULL, 0x615CEEDED0F33C4FULL, 0xC9477BF8FBA0EB05ULL, 0x1DDAFC3E037858B6ULL
        },
        {
            0x474D14F9E407BF33ULL, 0x62EE80C7984D8FA2ULL, 0x5118E137E37E6E61ULL, 0x7C5EB88FCF10CB1DULL, 
            0x6759C12A99321429ULL, 0x90691431ED779F34ULL, 0x74C7E235C1A96B1DULL, 0xDD289CA7D79A0340ULL, 
            0xDC30E58566E91838ULL, 0xBE2B0A1BD8ED5586ULL, 0x61784088BD255A35ULL, 0xC964382D30E8A008ULL, 
            0x5BC5B715769C802EULL, 0xA14D387D09871F96ULL, 0xE33DF2367E39D4F4ULL, 0x014275C0CDB92A20ULL, 
            0x9C2761B6AD083E94ULL, 0xF35EB4F20CAE36F1ULL, 0x76A5BCEA4F255612ULL, 0xCB94604E9D2A6E3EULL, 
            0xB9A4A6FA0A25A7F8ULL, 0x509C90EBEE152057ULL, 0x4994075E47D83396ULL, 0x4FCE4F938567F511ULL, 
            0xE310E666275C9B4FULL, 0x72E6153FF2AC760CULL, 0x10EE6026D945E90AULL, 0x677275B181A7DEE8ULL, 
            0x89533707E245482DULL, 0x4E681155B3848D0DULL, 0x986EC486CB0E7BA0ULL, 0x49D4339A92E9094BULL
        },
        {
            0xDF20297AA60FD144ULL, 0x420FE24290E1F64CULL, 0xD945E69DBFE7C913ULL, 0x9406B9BA0248E493ULL, 
            0xB955F496B53ED1A9ULL, 0x51165A68FB22ACE5ULL, 0x88D393DF889F8F5BULL, 0x1D2633CC33132A88ULL, 
            0x7E8F91DF9B91A42FULL, 0xDB9ED51A1543E70EULL, 0x37CA07E315F3B1FEULL, 0xE81727D1F313CE4DULL, 
            0x20DAAAEA4AE17405ULL, 0xBFFFEB5F71AF5C95ULL, 0x354BACB7BF7DC6DDULL, 0xC79D76709D3CEF7AULL, 
            0xDF50D1A8C60FD46AULL, 0x1AEAD517C11A4CCDULL, 0x327207084DBFA474ULL, 0x73F826C98207F8D6ULL, 
            0x4CE6033604A0139CULL, 0x05528BE8E9DD57E9ULL, 0x9EE067BA70E6201EULL, 0x3CFCC921E0DD8299ULL, 
            0xB59FFBEBE1612585ULL, 0x48267556A60C3DC1ULL, 0xF669424A04741B3BULL, 0x835E8FDCF5999636ULL, 
            0x4636BF4ABDD3C33AULL, 0xFBA0B64C2E9FA908ULL, 0x448E066DF3716437ULL, 0xE7FC933D7D3814E6ULL
        }
    },
    {
        {
            0xD00F4F5C182C63A1ULL, 0x13240A6D1574AE6DULL, 0x4C9523D4B2B063F3ULL, 0xF4F1606C2B9DBF13ULL, 
            0x7AF3DCACF54C3461ULL, 0xCFE022881CC6B4C8ULL, 0x47B7E90D8381F2B2ULL, 0x67C3AF1ED6226D96ULL, 
            0xA016379DA44902BFULL, 0xC6C42D75FB36CBABULL, 0xAE4C97225EA98877ULL, 0x5250003E67D6CA9BULL, 
            0x531736970254218AULL, 0x4CF28443106FC07DULL, 0xC4A6D4801424BD7FULL, 0xB12855D075F13EB5ULL, 
            0x79B65BEAC315E907ULL, 0x8DF371B9AA0C4448ULL, 0xB900E53DB8C85C5BULL, 0xC3132C1C3177DEC9ULL, 
            0x72B333B9FEEE9CAFULL, 0x54B9AF9263FB7450ULL, 0x87327AD34769CCC3ULL, 0xD9250D669DE9BC89ULL, 
            0xEEA83CE9F6760B91ULL, 0xBD3148CA96539B60ULL, 0xE501DC18287FAD00ULL, 0x07920D41009BAF0CULL, 
            0x4E0096F6647A7955ULL, 0xA21635050048F311ULL, 0xB847594C8869E515ULL, 0x837439EAA63E2305ULL
        },
        {
            0xCF8CBF1A362A44DCULL, 0x07166B674A20C66CULL, 0x80A12499B8B664EAULL, 0x435968F2562485BDULL, 
            0x1374A990CCA6D485ULL, 0xCF83659C02F593BFULL, 0x3B1CCEFFDD78152BULL, 0x176F876FF49A3726ULL, 
            0xE9FFEF46F5730D79ULL, 0xB38024A71A29EEB3ULL, 0xED5B9C3A1C4988BDULL, 0x948DB92F597975CCULL, 
            0xD7AC3392FFCD7310ULL, 0x0ED14C9CCA908ECBULL, 0x026FDD95639AC58FULL, 0x7D58D85A86D19197ULL, 
            0x1BF5FAA82BBE4810ULL, 0x08D44BD3CFD65304ULL, 0x4004ACE6D3BEAEA9ULL, 0x3BAD591A3D39A990ULL, 
            0xEC047B6ACE601384ULL, 0x47D373F0393DD777ULL, 0x3CDFF700F406F73EULL, 0x19B0C4834561FAF3ULL, 
            0xF33247F166C5482BULL, 0x4B878D123A5E2EABULL, 0xCFF28310E8CCAAD5ULL, 0x0E828E64C15EA766ULL, 
            0x1D1CF499A43C1523ULL, 0xBA2881B5A1C01E72ULL, 0xC1D5FDBD37C1746CULL, 0x3E4B89BE738BB240ULL
        },
        {
            0x8B3DD616FE1986C6ULL, 0xF2F6E6D0412AC008ULL, 0x8BBD206C5FA00A36ULL, 0xED98133AB6B9CE73ULL, 
            0x9D635954FD1E8591ULL, 0xD51EFEB377DE82F5ULL, 0x49133B768F1F8AF1ULL, 0x21FD20172AB601C1ULL, 
            0x4E835AC698FDAADDULL, 0xC3A0733AC3414870ULL, 0x7D0253D072CB26A5ULL, 0x5C1D697C4F23C581ULL, 
            0x119F0C777A92554DULL, 0x2012B893E2B31186ULL, 0x9E90F3B45687C93CULL, 0xA8BC8E6E337C6E00ULL, 
            0x2C23EAD36493BDB2ULL, 0xD9B3279DCDFBB7A5ULL, 0x434743751A5BF294ULL, 0xFBF54F6E0D8213EAULL, 
            0xA888E8F903D6EBC1ULL, 0x9F20C5F8B7BDD029ULL, 0xC555AB46B1257386ULL, 0x90EA5A909DD62EF0ULL, 
            0x43CF025623753C61ULL, 0xA92700D9071397C9ULL, 0x75895B09F2A7C49EULL, 0x773D37C35E6D03DBULL, 
            0x9AD18B7C7B40B4A7ULL, 0x0439394717272FECULL, 0x12BF9C44EA0FD6B1ULL, 0x8146F8A976475725ULL
        },
        {
            0x3A7E5936A7B91CC5ULL, 0xEE135BF4255C74B5ULL, 0xF966218B2BFF914AULL, 0x284D94471512033FULL, 
            0x1B387F6679DC3AF1ULL, 0x14150594BC3EA1DDULL, 0x679E608703DE73F4ULL, 0xFF17A0D948103544ULL, 
            0x5B1C68D4557E2B77ULL, 0x00C6ADDE7940A785ULL, 0x7876546B4E40510EULL, 0x6AA712659921028AULL, 
            0x10A8E52783C5A406ULL, 0xB74F366263404C4CULL, 0x9265FC4AA0371D38ULL, 0x7D9B9D1435D7450CULL, 
            0x501CBBE04EA47AF4ULL, 0xA2AE98CB256F9FC9ULL, 0xF7EDDE0231E4C6C0ULL, 0x28314A006921C718ULL, 
            0x2C3D58CEBC42379BULL, 0xB17795401D9113FCULL, 0xCB43F01FD6715396ULL, 0x9CFB8F88B3255C6FULL, 
            0x3308929391941DDEULL, 0xEEC0C56ADA3A02AFULL, 0x7E60BFD8C3073C8EULL, 0x641104BCA9B6DC85ULL, 
            0x02E1131530EC837EULL, 0xEBDF28AC0BB7E95DULL, 0x73145ADA73B04116ULL, 0xEDB75764913972D0ULL
        },
        {
            0xE4E936C884008150ULL, 0x7AA14AC380A9DBEEULL, 0x1CEA6BFC47F0C653ULL, 0xAB5DC5A3A320EEEEULL, 
            0x9B80CF0E36925A9DULL, 0x6EA9A59646867241ULL, 0xE500517DB672C052ULL, 0x23DE06CC475AA0C5ULL, 
            0xA79DC5AC2DE3F0D0ULL, 0x8DC9AA1A4510317CULL, 0x2C6FEB943A4F9734ULL, 0x978D78FC6AADD7CAULL, 
            0xF8F429D2B65AA446ULL, 0xAC97ACCD247E48D2ULL, 0x120286B5DC09744CULL, 0xDE0CDFDDCFDE96C5ULL, 
            0xC8F55650DB42859CULL, 0x1168E8B12EEE5895ULL, 0xFD4C1EDEA51DCE07ULL, 0x845C8ECD4B46D25EULL, 
            0x3B4100A1445E284EULL, 0xDF67E99FADEA602DULL, 0x1D7224905E0F50FEULL, 0xD68E6BB511ED7230ULL, 
            0xBDE32720C4BA6C8AULL, 0x0674D23BD28FD044ULL, 0xD5A158D516C637E2ULL, 0xF69B4A4E6DF80DCFULL, 
            0x8A108E2AA3D7D086ULL, 0x56F54ABB4381B9FBULL, 0xEB307EC271BE3E0AULL, 0x539521E6CCF2952CULL
        },
        {
            0x7A169116D659F89EULL, 0x30A3A51289A21F18ULL, 0x64D13E7F29ACA76FULL, 0xE3BBFF9CD879D951ULL, 
            0x0D77690DDB52E970ULL, 0x09EEBF65DB2D000BULL, 0xAD1D2D685B3E0EE3ULL, 0x892439AA5D1AE7D5ULL, 
            0xA0A400A9F3A990C0ULL, 0xFA40F1E550C47150ULL, 0xC3FE40224381E784ULL, 0x88C01E1B7F80E9A1ULL, 
            0x9A2AA90EDAB69708ULL, 0x92B43703D9EE9361ULL, 0x82E82AAD709141E7ULL, 0xE265D95C205C2156ULL, 
            0xDEB549C358BF29B6ULL, 0xACBD44D007AE66B0ULL, 0x00D41AB70E2A8D39ULL, 0xE6419A5AFB60A457ULL, 
            0xFEBCECE7BD16BEB8ULL, 0x4B4C8559A6DE192FULL, 0xCCBB186B06947F4AULL, 0x0839C9CADD28FC5FULL, 
            0x845E1A45B73CA656ULL, 0x453F4F42DBC157D3ULL, 0x79202AA1F1B12B36ULL, 0x0B3648EE55826A35ULL, 
            0xA7CA63662A69D898ULL, 0xD2400646DFC13EBBULL, 0xD9387B4898E89B80ULL, 0x59091037DB18F655ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeySpawnAConstants = {
    0x544CE406FFBDEC37ULL,
    0x3BBA6067B809346EULL,
    0x557FA1B084ADD818ULL,
    0x544CE406FFBDEC37ULL,
    0x3BBA6067B809346EULL,
    0x557FA1B084ADD818ULL,
    0x80249138750029BAULL,
    0x637246DC988F4E8DULL,
    0x1E,
    0x28,
    0x50,
    0x83,
    0x2A,
    0xEE,
    0xAE,
    0xA2
};

const TwistDomainSaltSet TwistExpander_Polaris::kKeySpawnBSalts = {
    {
        {
            0x802FDAC5B505AA0BULL, 0x1B863B28F80AE5F6ULL, 0x54805904AAB041DBULL, 0x1F3A30D082FDB8C4ULL, 
            0x324186F2345FD888ULL, 0xD2AEC2EC1826E2B3ULL, 0x3422DBC584E8CF89ULL, 0xE3A448BFF7D17C10ULL, 
            0x363E01F9183F407FULL, 0xFCCB8823CC29BF9FULL, 0x78C0C2A52138F256ULL, 0x4C79B416C692B472ULL, 
            0xBDD1CCF37324DF01ULL, 0xDC7C0F7F0ACF8872ULL, 0x879AC09CB91660C4ULL, 0xE9333428D7D2A20FULL, 
            0x3378E48B6AEAC681ULL, 0x833568BB4C4C102FULL, 0x6AAE70BD101B3113ULL, 0x1937FD6E08183AA7ULL, 
            0x334962D41FC5FE76ULL, 0x3BE4F82A7EF24073ULL, 0xD58DF85C9E4E625CULL, 0x3AB2575A42C8625CULL, 
            0x7BBB40D85767FF81ULL, 0x2AF6EB8700A15865ULL, 0xF6386C2BB901E3CFULL, 0x3C42570F603DF962ULL, 
            0x8A8E50995CC80115ULL, 0x01CA7FB7E07E546DULL, 0x890BEF2199D8EE22ULL, 0xF182AB60247F2AB9ULL
        },
        {
            0xCFBF9AD4AE3B96D7ULL, 0x4CD2E07D78FB4603ULL, 0xADD3BF2AE21DAC19ULL, 0x5DB3D094623431AAULL, 
            0xA046FFA97FDC1684ULL, 0x311E319D87B49704ULL, 0x348F4B02ACBB2FE5ULL, 0xF5578773CBD83ABAULL, 
            0x7BADA78E936F125DULL, 0xE0F404144AD06EB0ULL, 0x1DE0550901ADC2C2ULL, 0xDF01B61E27B37E72ULL, 
            0x114CC10F4C064164ULL, 0xCA17664C12DD9EF4ULL, 0xA5DF3D24EC7B6F56ULL, 0x60DDE70AF263245EULL, 
            0xC00896A83D5D2DB2ULL, 0x3C5316AA4DDE956EULL, 0x9AEB56C564D79BD6ULL, 0xD6C84F0EB8C0A7C2ULL, 
            0xEE2C2B9EBDD1104CULL, 0xF6433F5E4B506C71ULL, 0x48FC75BF54273913ULL, 0xA1FEA809B90AB59EULL, 
            0xFCDF186D7A4E94BEULL, 0x9AE9B9F54343C5EEULL, 0xB1856073EFD85066ULL, 0x41CBAACDB3A77A4AULL, 
            0xAC8F47B9ED1F3C39ULL, 0x844FA26F183EA893ULL, 0xCA3160F8891BD905ULL, 0x28DD825601583C9EULL
        },
        {
            0x2640420E9E3B75FAULL, 0x834BAE0BE895788FULL, 0xD27EA7D2DB9D3152ULL, 0x3464BBA85664D52BULL, 
            0xAD8B8E1058ABA722ULL, 0x817FFC0E811EC922ULL, 0x003A124589E1E169ULL, 0x7878991AA53901C5ULL, 
            0xA1124C261271FC50ULL, 0x372D7D08877A7774ULL, 0x841969E17075B5C8ULL, 0x419960DC56AD54ABULL, 
            0x97092433ADE7288BULL, 0xCB032BCB1CC0683CULL, 0x7A0BAC93C191B939ULL, 0x22E7F9ACB0B375BBULL, 
            0x5D81667B10C8758CULL, 0x4BF9FA8AEB00E1A6ULL, 0xC2F5FCBA90B43A12ULL, 0x27C9176B2D2727BDULL, 
            0x9BAD9AEAA206412FULL, 0x66879CECF5D98010ULL, 0x19DF0008D2D1D397ULL, 0xD4DC11D2BFD9E93EULL, 
            0x8354BAFEAFC7DCD6ULL, 0xBB164E5BC1EF513DULL, 0x1556B34C4F8E34A9ULL, 0x4B1A2924EF575D79ULL, 
            0xC8C53BBF8A7938C1ULL, 0x7C6281B046D372DAULL, 0x055CEAB407845791ULL, 0x47664CC8D7ED82E5ULL
        },
        {
            0x5C2E7B4246FF9ED2ULL, 0x6C1EC87A6F9B4D85ULL, 0x061C35746F059DA8ULL, 0x43F0149F26833614ULL, 
            0x3C47758737EAD4E6ULL, 0xBCD31AEA08676FB2ULL, 0xAAF6282B99CE0BC5ULL, 0x8EE1ADA841B5F717ULL, 
            0xB24F5049A515D217ULL, 0xAB87385AD6F72ED8ULL, 0x000FD66B0191A3C4ULL, 0x1D49893BFA77F27FULL, 
            0xC261E5C7C9801EA4ULL, 0xF46C143E1D9CCB88ULL, 0xAC4A1F29329C9E41ULL, 0xA0BFA05641356614ULL, 
            0x455DF75CDF75EAF9ULL, 0xE5DF13153C0C37B6ULL, 0x4371963CFE335BFEULL, 0x8E464D04B009F286ULL, 
            0x8202C062D3E0A8F0ULL, 0xEB4277CE0B9C377CULL, 0xDC45F4977DC6B799ULL, 0x6CF8F982528C21DDULL, 
            0x814040B07CA47A36ULL, 0x5F82B76DF23B5987ULL, 0xD437C20A4560271AULL, 0x25C64534752B546FULL, 
            0x402620C86435CD09ULL, 0x498C4B876A464242ULL, 0xB8A8B20E061B2138ULL, 0x59374AF9D911BBD5ULL
        },
        {
            0xD59913B3CD30D884ULL, 0xC39090306FB146A4ULL, 0xE74B2579EF1154B5ULL, 0x946FCDA129BA7950ULL, 
            0x4FDB78BC3B2B34C1ULL, 0x35E9BDAA0B6438E3ULL, 0xAB423A3041C045B0ULL, 0xFFC3C524556F030FULL, 
            0x483EB506B589FA3AULL, 0xB0DF33404F1524AAULL, 0x73A6EB287EAFC268ULL, 0x748F45AA1A6FBF72ULL, 
            0xDDE4137E11DC7214ULL, 0x6F2996278042E900ULL, 0x6AF314B4EDCF3146ULL, 0x3C064C10E9A9199CULL, 
            0xDEB082B2B7A86C89ULL, 0x402076FE62389A0BULL, 0x3F2EA3E448726DF3ULL, 0xCD5577D743BF16A1ULL, 
            0x067BD5BCABEF6556ULL, 0x128863CEDEEB53A3ULL, 0xAE7B91950493EEA8ULL, 0x760DF748618468B0ULL, 
            0x14D295A64B16644FULL, 0xFF8B689DDB4B3F5CULL, 0x00240D6D6043D1F3ULL, 0x2F422BD3EF7499D9ULL, 
            0x10D5CCF1A00ACC96ULL, 0xC5BC6550BF37D443ULL, 0xFCEFFDF6940055CCULL, 0xC3C0EBF8DF28AACDULL
        },
        {
            0xBBD1F11ECC396B10ULL, 0x7EA001F1ADA91825ULL, 0x983B622B2454CA22ULL, 0x4C09B0D7DCF1A6F7ULL, 
            0x7C14543D5468ABDFULL, 0x150EDB8E6B40A67FULL, 0x9DFD24F70177A437ULL, 0x7D528C3F646C8FCCULL, 
            0x42F1E8BAB10C3E7DULL, 0x8C40E97EF2EC6932ULL, 0xDAC7B9A47D7C4582ULL, 0xBDF9C5C0D30D65B2ULL, 
            0x254E2668CE4B1F49ULL, 0x380E8EA914948492ULL, 0x7A100F4470770D15ULL, 0x0A6ADD63F164DB5FULL, 
            0x7374230101048855ULL, 0x58739A48CC10E070ULL, 0xD075C82CCE9D24F8ULL, 0xDF8B5E385E81E5E2ULL, 
            0x86FD05CF7B269588ULL, 0x60510A2EFF332017ULL, 0x502B9603C25BF122ULL, 0xD6D74E6F54C2BC00ULL, 
            0x1A36B9AAB8367A9DULL, 0xC18778EBB5269C83ULL, 0xB82D8B144C7D0136ULL, 0x0809CF7CE8D8714AULL, 
            0x701534E22F37E112ULL, 0xAD2BD6F272C37AA5ULL, 0xEFD0DD4E74AA7DB7ULL, 0x8A241F9A79E8D71EULL
        }
    },
    {
        {
            0xBA18F027FF3A9225ULL, 0x831AA91B8425CF63ULL, 0xF294970D358C9630ULL, 0x67D6E20BED9432F0ULL, 
            0x53F6E676877E65A0ULL, 0x56FAD326A5D58EECULL, 0x0A424E8FA3AEFA5DULL, 0xD7339FB62405B78BULL, 
            0x7D2B023270C4F7B2ULL, 0xF833AEDFD00BA2F8ULL, 0xFDDAE35E51C23012ULL, 0x9E36CC2FE7249064ULL, 
            0x5E424DE64BD8C0B9ULL, 0x0EECBAF421D861A0ULL, 0x4F02BDACE5E146E0ULL, 0x8F064CAF9595EA8CULL, 
            0x65673F528F089B75ULL, 0xAE919744352AA6D8ULL, 0x54DB6F170F2B2B9AULL, 0x5EA70C73D037DC3FULL, 
            0x10D3EDF305DA7DE6ULL, 0x462EB30D7AA95980ULL, 0x922BB8A1DAFA5333ULL, 0xC00C0860F11BFA4EULL, 
            0xBFBE4CB6C9D6480DULL, 0x40D9EEC57087D21CULL, 0x0D4590DD22E09D88ULL, 0x3125752296C335E1ULL, 
            0xAB9DC721AFA58CA5ULL, 0x84E142F6EFC29A0DULL, 0x835C768CC58A48F8ULL, 0x58103DCEC320F94CULL
        },
        {
            0x9DF3AA0741A117A5ULL, 0x495CA26B2CB5E027ULL, 0xBC49E670AB1B247FULL, 0x6C992C6CA8F898A7ULL, 
            0x45096D5258E1E29EULL, 0x7B5D1C73407640EEULL, 0x4F3040DF6B599D97ULL, 0x51E4691F20B4CD2CULL, 
            0xD6C39165B36E2BDDULL, 0xE112B0C3DE9DE769ULL, 0x0328454094B55467ULL, 0xA0B2433A0F13DCDBULL, 
            0x059BD464270BD37DULL, 0x043E58C52A6039C1ULL, 0xE4E6BB3209075ED0ULL, 0xF285ADF8726E55F7ULL, 
            0x2037A25C48C3718CULL, 0x43747CE51CA53A3AULL, 0xA72A96A9C7337FDFULL, 0xB003708F2E33B02FULL, 
            0x51364DFF275CCA9BULL, 0xE11EFEBFAF69FD64ULL, 0x8BB98F98357AE4ACULL, 0x1A633F46A60D3DE6ULL, 
            0x554B9D841A9E2413ULL, 0xF11D1CC7BFC492ECULL, 0x21A66CF50B7C3D06ULL, 0xD9229C3658B1FDA3ULL, 
            0xF32E000FB09E60E0ULL, 0x49AF870C345288AEULL, 0x77BB70AD0606B036ULL, 0xAF2F4BE5508808C7ULL
        },
        {
            0xAEE7294A76329C7CULL, 0xDD4EA34D9F0BF408ULL, 0x22EC5FE86AF965F2ULL, 0x9AF4DA8E29839F92ULL, 
            0x464336131C1E313CULL, 0x775098CA15DECF50ULL, 0x381D1EF221892E7FULL, 0x67F275ECDBCE47A2ULL, 
            0x3F4673097502DB00ULL, 0xACFD5D040E21F015ULL, 0xF740394BF6CD8E21ULL, 0x5B7D658E2D849C97ULL, 
            0x10401A78DE1536C4ULL, 0x0377B75A45E3BCA0ULL, 0x03BF141A83DFD5E4ULL, 0xB2F9F17E63AEEC3AULL, 
            0x4D21C8AB8C9AE60EULL, 0x77C00B2B504B1614ULL, 0x908FCB3DAF7A1D2FULL, 0x5058D4F28C96236CULL, 
            0xA4AF38D846929D77ULL, 0xF6A5D334A2749B18ULL, 0xFC238C0C3B186125ULL, 0x0427E980FC010836ULL, 
            0x339A302CFFA86233ULL, 0x7E7F29C2A91F216CULL, 0x09DA49FA4FDD1D73ULL, 0x14421443EBFF38E7ULL, 
            0x2429EDA61DC2140DULL, 0x59D90D27841611ABULL, 0xB1B057803E7C8B9FULL, 0x7E26C2181A77828CULL
        },
        {
            0x574BC91B99525085ULL, 0x3C0365DF2B8EAC4EULL, 0x8284D2328808C33BULL, 0x537B57A3201986C2ULL, 
            0x1A2DA0682D01E73EULL, 0xFA1D9CBD5A2D8329ULL, 0x33503883A5E623FBULL, 0x2B550A1DCE78F0DCULL, 
            0x8D26E2F8EE829A14ULL, 0xE1A165E5853AFFEBULL, 0x2111AC6BB4FAA8D0ULL, 0xBCFDB029D78D2F71ULL, 
            0x37EFAF4484C6162AULL, 0xAE1FFCEA70EA5E60ULL, 0xC8FB0F40602E9A0AULL, 0x946FCA20B0ACE944ULL, 
            0x328F51433C912EB9ULL, 0xEE3B15DC5229B7A1ULL, 0x14888F125DA509EFULL, 0xE519BB4F99AE9EF6ULL, 
            0x00DA783437C4E56CULL, 0xEA8CD5F2C1FE41A0ULL, 0x800B38B3C8E8F05DULL, 0x6E9FB4BCF32F460CULL, 
            0x84A7DB59934DB68BULL, 0xA301318889204C95ULL, 0x9EB2041A6B268CA6ULL, 0xE72D0F9A06E0DE8AULL, 
            0x8427B2C3A7B52485ULL, 0xCDDAD78693BA7E3CULL, 0xC3CD776A27C573F7ULL, 0x83936BB9A93C085EULL
        },
        {
            0x8E1F4724CEB3CDC2ULL, 0xA7F623FE4EEA72CFULL, 0xC27691342768F965ULL, 0x85FA8DC366F49698ULL, 
            0x1AA1AFC3741D3289ULL, 0x4112BD409CAEA47CULL, 0x20D8FE41C9E98583ULL, 0xE5C14BCFAB62E7FBULL, 
            0xBCFC9663B6F44B1CULL, 0x87A1CB5FFE8B4574ULL, 0x561657AE87B38B86ULL, 0x013DC427293A11A2ULL, 
            0xE131D7CBCB23D99FULL, 0x34B8301B2C8604DDULL, 0x52F6E64733CB49DFULL, 0x260E56975F363690ULL, 
            0x8B6479E49292DC97ULL, 0x78D3C2C4DF77287BULL, 0xCF2984861EB464A2ULL, 0x4FFB93D995D1E1E3ULL, 
            0xAB8824C272D33D10ULL, 0xFC5175097CCF43E9ULL, 0xD1F81964568A79E1ULL, 0xE6702EBF73B1DC65ULL, 
            0x5DDBA626AEA40972ULL, 0xDC3AE3419BA848EDULL, 0x2FC3835727B889E1ULL, 0x01855500686C2CB7ULL, 
            0x0C8E962A039F3C30ULL, 0x51CF54B74CC1CCCFULL, 0x9DF5D9DD2AE3A2A2ULL, 0x1B5A06FC16DEA3AAULL
        },
        {
            0x9D3D442E12F87BF8ULL, 0x7F5CB9B5445C4A0CULL, 0x46C8BC16558D04FCULL, 0x72A01AEFFDF1863EULL, 
            0x50DA240D886523CAULL, 0x07E856DDC6505231ULL, 0xD546B1DDB19A94A7ULL, 0xD811C2D12D06B62AULL, 
            0x2B338CF444486902ULL, 0x4517E6BB7E2E65BCULL, 0x528B0EA0D24B955CULL, 0x98E60F180EF44C73ULL, 
            0xBF7032779FBCAD32ULL, 0xF1E9DB844677EEE6ULL, 0xBC648E95C4AE7E21ULL, 0x9E552A29BB7A95D3ULL, 
            0xA0F46161379F6C56ULL, 0xE3EEBCA352465655ULL, 0xBFE1D2F3D71D852BULL, 0xD1D77D12BAFF2775ULL, 
            0xB7FB607A12001047ULL, 0xE15E0858C736D5CDULL, 0xE878CAC96EC6FF13ULL, 0x33D84C3738256AE1ULL, 
            0xC923D8D417240CE6ULL, 0x754DAFBC22764856ULL, 0xD91E708703D4D710ULL, 0x884EE152097FB4E6ULL, 
            0x052FC62A729C5FFFULL, 0xDF245870C2FD0E16ULL, 0x2A2834E628080DDDULL, 0xD473D9B77068D5DDULL
        }
    },
    {
        {
            0x2B709097590F0E66ULL, 0x895EAE6F486D8137ULL, 0x9AEC5986AF1E0092ULL, 0x00AC49D390DDA648ULL, 
            0xB00FECDA3BC6D8AEULL, 0xE95BB170B30A1EE5ULL, 0xF24A35B4C74A594BULL, 0x07A896BF0C066A82ULL, 
            0xC2BDD345D69070B7ULL, 0x4CD1116835B7AC47ULL, 0xCB98091F4D434D23ULL, 0x5746CFD78DADF2A6ULL, 
            0x82F0602FC14009D8ULL, 0x700D331CBD7D6D02ULL, 0x5DAAE99892475E96ULL, 0x53715BF21EAE3999ULL, 
            0xF4BC94D13313F09FULL, 0xA184A34351C3BAE9ULL, 0xAD68B879A34B2FB9ULL, 0xCCC7A193406AD0B9ULL, 
            0x89A90387561387FDULL, 0x1536185BDDC058F3ULL, 0xF253098188F78B66ULL, 0xE0097D18381E8D19ULL, 
            0xE7E0DAA330B39A49ULL, 0xCD6EE46E066A115AULL, 0x87D9D4BC92A0D1B5ULL, 0x7DDA4BA88963ACA8ULL, 
            0x77B6AAE6DA4E98B8ULL, 0xE116B797AF83E088ULL, 0x150F270CC5E9B1CCULL, 0x0E732D6C642C39C7ULL
        },
        {
            0x85DB4E9F0507C508ULL, 0x976411D6F750215BULL, 0x6DBE8B6273C5B47CULL, 0xBCB17F50FE110AA4ULL, 
            0x9520669DFFF309D3ULL, 0x7D9556AB08DDBA3EULL, 0xFB4ED29B52D30724ULL, 0x94A7DB7F61CE93A5ULL, 
            0x4D4A6BF17B8FE901ULL, 0x723BC326CDB34ED6ULL, 0xE59784E5F6D09FA4ULL, 0x0F9DFB5000AB01D9ULL, 
            0x7AFACA9F40F6A14AULL, 0x5F6FAD5DFCCE395FULL, 0x5ED4695FB20C8BC1ULL, 0x1A246B8550C1C28AULL, 
            0xDCCE3B05BC47CA08ULL, 0x0577F8138F5F1EB3ULL, 0x5413C3E0784AAF89ULL, 0xCB0CC34DCD55D2CEULL, 
            0xF462BCA11B03862AULL, 0x38973B13B042B571ULL, 0x6796600A70B7FB23ULL, 0x209B0A140AA73DBFULL, 
            0xEFC3CBC050794D9EULL, 0xDA7F957A03456441ULL, 0x22D3BE1FBE5D07D8ULL, 0xD5579533207C32ABULL, 
            0x3E8BAAA6130EF570ULL, 0xABF4E125CBE73E7DULL, 0x51533CBB571B3816ULL, 0xC5CBE1F4ACF44F4EULL
        },
        {
            0xA487349F2E1DBEA8ULL, 0xC1A335A2CC673008ULL, 0x970FEE5F61492117ULL, 0xA3ED2B6CF59F2DE1ULL, 
            0xA76F672AE8422E53ULL, 0x98439B1759BC9932ULL, 0x426ACD15642BB37DULL, 0x95EF65482D0A55C5ULL, 
            0x4F83059E60D354A3ULL, 0xD927C1AAA54F9C65ULL, 0xC04E6132EB9716E7ULL, 0x728FBBDB50307370ULL, 
            0xF9A67A7DBF45D964ULL, 0x4CBEEBA8BFDA6998ULL, 0x2F751DED9EC0C3A3ULL, 0x4177A0747A434FCBULL, 
            0xB8E9E94598E316B2ULL, 0x0FFFF4158A8364E5ULL, 0xB322DD5C7E1EE29EULL, 0xE027C68527920C96ULL, 
            0x5771352797CCD57BULL, 0x56D8E008C8285D54ULL, 0x92224C109EC4F1F7ULL, 0x163267E3B644A9F9ULL, 
            0xF9D067C04EC2C16BULL, 0xB11831A1C3FE9E0FULL, 0xC66D1243E8340984ULL, 0x5246B6A0564FA5A1ULL, 
            0xAF56694840109D47ULL, 0x72913AB936AF14D3ULL, 0x92087E18A03C5664ULL, 0xD34EBA15F0C76F8FULL
        },
        {
            0xAB4F4BE44E08B9FBULL, 0x87916A5374A3C67CULL, 0x3409760AA32693EEULL, 0xD730F86BD10F8C8EULL, 
            0x1D1F8C7D638CF3B8ULL, 0x4E806FE2EFDAE073ULL, 0x37BA70D8E37F7BC8ULL, 0xF452BE8865E5CE53ULL, 
            0xEF1F5471DD574E53ULL, 0x735B31B93CF4075AULL, 0xCA61A6884E4EF9AEULL, 0xF2F87C34B891E3ECULL, 
            0x94373890C820D999ULL, 0x9D36B70BEA345EDCULL, 0x0539D3DE818EAB85ULL, 0x0D72625C06C4161AULL, 
            0x54B43AA1B726BE83ULL, 0xC8050B737E354DE3ULL, 0x46B9F25266BB6BDDULL, 0xA91ECC57DE1E4B85ULL, 
            0xF9A4F018FA6B6093ULL, 0x0398E213E2AE994AULL, 0x2120168474093F01ULL, 0xB3CC1AE521EB9B28ULL, 
            0xE73994EEB3F47ED0ULL, 0xEF86276619ABA79EULL, 0xBC89CBCAEF4375DBULL, 0xB90CB1C330A5DC17ULL, 
            0xEEF4446E3120F93DULL, 0x171DEAEB35AAF8D2ULL, 0xBEFE0C4C26A26639ULL, 0x695B258B130E8A26ULL
        },
        {
            0x0ED53CDDA276D669ULL, 0x48F6A0A4C03396B0ULL, 0xF02A25FD5D280416ULL, 0x1E00267DBE64E560ULL, 
            0x0031F8004E9B0F35ULL, 0x62C0764E1F8F0ABEULL, 0xB609624247322E41ULL, 0x2FFD37454CCD794DULL, 
            0xD82563E39AC68FE0ULL, 0x1F09B6685E1E49B1ULL, 0xEE18301DE801B208ULL, 0x8EAD7B34D345DFEDULL, 
            0x10FA6665F4C6F9E2ULL, 0x58BB3E035E1281B7ULL, 0xF7334FAA3BFD37E6ULL, 0x734A4A09A4DCE7F0ULL, 
            0x6D84760DB0A97109ULL, 0x620C2B1A4AF955ACULL, 0xCAB4D373AA2E0073ULL, 0x323B23973E942022ULL, 
            0xC7E09A477FA06613ULL, 0x36FFA17C3E59F6D1ULL, 0xF75CBFC3E00FCC70ULL, 0xD33DD910CE9B30D4ULL, 
            0x6E1F7B3ACD43F8DFULL, 0xB6A5A43EE7DD6E53ULL, 0x16BAE95AA28E0838ULL, 0x8251E53D32131807ULL, 
            0x9FD6690C0C837626ULL, 0xEB075740C7BA321BULL, 0xE628F800C0C1D97CULL, 0x4BF13EAAB7DEFB5CULL
        },
        {
            0x54F70E9A13A28DD4ULL, 0x1B3A61D2A4F2A5B2ULL, 0x47F33EA7DB7642C6ULL, 0xBB99CA7F825C9F40ULL, 
            0xF91D1C97206817A5ULL, 0x8B435C98A4D1E1B3ULL, 0x530E78FD7A7ECF7BULL, 0x440D8CA798B7A817ULL, 
            0x8B4D9BF2AAB43590ULL, 0xC06F8261F5BE0F47ULL, 0x1071DB1675893E0BULL, 0x76E81A6872EABA38ULL, 
            0xEAFBA4B0FB276CC1ULL, 0x3B257B671534FFADULL, 0x9C640D14663FC8D3ULL, 0x0DA21133DDD6F770ULL, 
            0xBF297283E48435B3ULL, 0x1932F4DF7062B3E3ULL, 0x114C67C13118DCF7ULL, 0x8546F2E9412D797BULL, 
            0xC28560356535E2EEULL, 0x3468985A262958D5ULL, 0x9EF0D02FAE58FAC4ULL, 0x3679CC60A2460050ULL, 
            0x453114B1ABA29F61ULL, 0x154731C0B83927B6ULL, 0x56362F9E3B1915A3ULL, 0x6C3BEAA6D12EF4B3ULL, 
            0x9C2B1320007739D4ULL, 0xC252D7A208CB0B2BULL, 0x9F0FD726478BF4DBULL, 0x88F8E539CDD3DF8BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kKeySpawnBConstants = {
    0xDBA3A2F376246A54ULL,
    0x1EA33ADD973AC7FFULL,
    0xE529DC2AEA36B64FULL,
    0xDBA3A2F376246A54ULL,
    0x1EA33ADD973AC7FFULL,
    0xE529DC2AEA36B64FULL,
    0x531268598239694CULL,
    0x3357E48924E0E390ULL,
    0x55,
    0xB1,
    0xDB,
    0xD4,
    0x24,
    0x78,
    0xF3,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Polaris::kSeedSalts = {
    {
        {
            0x6507D6A5B740BE37ULL, 0x6ADD13480E500755ULL, 0xF72C9EDE891B7639ULL, 0x40780DF1C9E7F75DULL, 
            0x7DDA5FFA8C18627CULL, 0x5FA231AB790C6F3AULL, 0x6C53F319DF4548CBULL, 0x2B6054E45121A5E7ULL, 
            0x3600DA99874AA07AULL, 0x75BD994162DD2A3BULL, 0x7621CAB25C16B18AULL, 0x2A909B99F5B43966ULL, 
            0x9B5625A83315D027ULL, 0xEF3E426D4375DBC3ULL, 0xC4B81E360E90DB4CULL, 0xD40707E7D56A61C9ULL, 
            0x4A3BC00F341D321BULL, 0x3305AFEF5CDD3596ULL, 0x8D39E555B2DCBC4EULL, 0x929F2A092D06BEE4ULL, 
            0x9A6E9F3D1AED8418ULL, 0x1D71FFDAE821D2E3ULL, 0x041C6CD0DF18974CULL, 0xC1F9625C6E752131ULL, 
            0xFC1F69F329220A85ULL, 0x9EB3ED0B04686B70ULL, 0x4F86424BCF711A6FULL, 0xDE823DE2BB09B941ULL, 
            0xEBFFD7C5690AB15CULL, 0x7E1EF87BBEC86FF8ULL, 0x722F0E5CB44FED14ULL, 0x685A1AACE9B20FD3ULL
        },
        {
            0x0E09E831EA5C18AFULL, 0x355665C4B1B5D40BULL, 0xE2EC6DAD74998DBFULL, 0xAA85BCE5E0194E34ULL, 
            0xC5D66F348F4D3B3EULL, 0x235C90EAF923F58BULL, 0x7551E86F3EFD4901ULL, 0xAFC7E23C53F40635ULL, 
            0x2F7FCE424D0D0601ULL, 0xC8A3BB67A13FAC04ULL, 0xEC670B8D13AEA35FULL, 0x49B19CA130260B1FULL, 
            0xD2850C804891F353ULL, 0xC22F1FC1AAC99203ULL, 0xD5D725B52BD008AFULL, 0x5FD71F6B44DDA844ULL, 
            0xA4D9A38923C6E620ULL, 0xFFDEF902D82F233AULL, 0x2D91E9918F845FBCULL, 0xFB38669590C5C238ULL, 
            0x4BBF2F7B544CEF73ULL, 0xD316ADB27FFCE055ULL, 0x4C83B8D8A53C81A2ULL, 0x3FF4C7DD9B706FB7ULL, 
            0x801B247A8B362402ULL, 0xFA19EB33C75126A3ULL, 0xD554E7D2E8EC324FULL, 0x88201891F8AA4816ULL, 
            0xCEB53803E8794441ULL, 0x8EEE61B9F5F5337CULL, 0xC2D2E7F4BEA54032ULL, 0x7C91A372E7FC7BA6ULL
        },
        {
            0x06027853AC0A6C96ULL, 0x6A2BB9468D7BA8AEULL, 0x4F83AD60815FDAA5ULL, 0xD88085EFA33E919EULL, 
            0x435E5D64B77FB654ULL, 0x255B5400404F1457ULL, 0x3F02807D17C42DC8ULL, 0xCFE3C846B984A6EAULL, 
            0x1DE0213157DDCD8CULL, 0x31E812C8395087D4ULL, 0x342D49B4BE650D8AULL, 0xA312FAE07C2F433CULL, 
            0x4C06C178B097BC46ULL, 0x8560C37D472D5C94ULL, 0x230AACEA214B15B5ULL, 0xD6A013D8C2832067ULL, 
            0x8B9CB9B4AD28663AULL, 0xEA3077207E35C9F1ULL, 0x5274B34B19CC3F8DULL, 0xE59BFFE91D733604ULL, 
            0x192A58F01286C6EAULL, 0x2B7515AA709C20D8ULL, 0xD3D1C8AD9609B87BULL, 0xF12C34901F00027EULL, 
            0xE025FC2947D98F90ULL, 0x1C328F77F8010B17ULL, 0x3DAC27DF7AC05891ULL, 0x69255D5099EFBCF1ULL, 
            0xE252F49562BF2943ULL, 0x89E5234790320B8AULL, 0xB4074321B5E128A5ULL, 0x30A1E22E6868FDF0ULL
        },
        {
            0xBA8FA69EA2F64441ULL, 0x13EF68CA06C3B17BULL, 0x49B317D4A4B33784ULL, 0xDDCE2395E8B6F227ULL, 
            0x553ECA69E3C9DC69ULL, 0x40E212A0CEDE0B1FULL, 0x46FD472930585853ULL, 0x6D4B79EF17E0AB37ULL, 
            0xE5CD428718D6693EULL, 0xEB9DB291400EA79DULL, 0x6173B4323579825DULL, 0x56A4C72E484D5B88ULL, 
            0x75D1968EB77028D3ULL, 0xF7435867AE947791ULL, 0xE3076D0D328509ECULL, 0x8A95F5EA1EC43AD0ULL, 
            0x05B3670B199DFB3FULL, 0x984525AB60132477ULL, 0x01CADABBE958DF4AULL, 0x7004188F8B5B51F0ULL, 
            0xBC5D57834724D7EBULL, 0x29A92469011607CFULL, 0x36BCDFA0A23C748FULL, 0xE57AFF497BCB0DE5ULL, 
            0x3A130EB13EE2950DULL, 0xCB794E7ED698C28CULL, 0xC97E0AC0552355AAULL, 0x0528367AB448A4F3ULL, 
            0x652472DEFF0DD077ULL, 0xE5EA05BB6686589CULL, 0x328C2F5C3791AF83ULL, 0x957C7C4FFCD77091ULL
        },
        {
            0xE9D3B35389133FD7ULL, 0x7F04511C656EF54DULL, 0xA9C432EC7026A2B4ULL, 0xF40F0F958A4754D9ULL, 
            0x5FFA39C6A78C1665ULL, 0x53A7C4921B532F7EULL, 0xAB4E951B21D30B10ULL, 0x455BAD73D09A8371ULL, 
            0x2615C571E78E5D1EULL, 0xEFA41C0A55916998ULL, 0x67D58DF4DBD5943FULL, 0x5BEC0CE91BF1F340ULL, 
            0x15F65F3BC4D4D4F2ULL, 0x4ED674A16B08E9FBULL, 0x41C858A74260A3DAULL, 0x7B8F5BCF20EE8A9EULL, 
            0x22C632DD871E80DFULL, 0xC15B2C1EA99C6DFBULL, 0xA92A4929AC1CD675ULL, 0xD10D9BBCD739F34BULL, 
            0xDE9A1DDBC8C6988AULL, 0x06ED4A2C6DE1ACDCULL, 0x7FA3473833813312ULL, 0x80163AC74B91F90FULL, 
            0x538BB62BDEF4CF34ULL, 0xBA87EC855DC1268EULL, 0xC9FE73E91C7B015CULL, 0xE9D2B769BA66D507ULL, 
            0x2C093EF6E2C471F6ULL, 0x23B86F518C41A2DAULL, 0x064FB6F92D151FBEULL, 0xF842E6EF69BA4A6AULL
        },
        {
            0xDD32898ACCF95FA4ULL, 0xACC2469BD9B4FF52ULL, 0xFE94ED1633BB5345ULL, 0x8852BA2CFCB9C691ULL, 
            0x1BFE0C82B279CE54ULL, 0x2709A1920A997DBEULL, 0x9C72616D40B75A6AULL, 0x43DF30CB6E8A342DULL, 
            0x3E8A96B3BF8B80AEULL, 0xC8FFD4427BB431A6ULL, 0x11428EF1715B8D4FULL, 0x5A56B6F5E2F835F8ULL, 
            0xE332660AC680D276ULL, 0x49C39DC143B06954ULL, 0xE19815075F2A5B7BULL, 0xA33DCCE8A5DECE6AULL, 
            0xAE2A6126D629457FULL, 0x76F1355E15124B77ULL, 0xA76BDE0E81F7D9E8ULL, 0xEABE98D587ECD43CULL, 
            0xCBD10EB7763CDF3EULL, 0xF117FF907000D3A0ULL, 0x019C744BCEB5D26EULL, 0xA283BB94E10E64A0ULL, 
            0x9EEBE93FE271D402ULL, 0xE1601D802B8DAAB5ULL, 0x132852442C088ED5ULL, 0x8DFAD7731F8220ADULL, 
            0xE91AA29765BFF72CULL, 0x3F4A1E4F0F58096EULL, 0x0B9602A7AE8BC2E9ULL, 0x2B951FEA5D2F0EF8ULL
        }
    },
    {
        {
            0xFEA4922ABF1022B9ULL, 0x40025497A5A6778BULL, 0x5971DF5199E8DD4CULL, 0xF6C2CD3602277146ULL, 
            0xA618D88A9500CABAULL, 0x844B561F6F851C2CULL, 0xA2126E5D0905E595ULL, 0x10227F5B6DC06E84ULL, 
            0xD5FD400D8A0EC11AULL, 0x5FD7090B40B2B3F2ULL, 0x257489CD2DEA2619ULL, 0xCAF6FBCC2C8A194EULL, 
            0xC02CE02FB300EC6DULL, 0x8D5F7C3B368177C2ULL, 0x0B4DAFCC50BBED07ULL, 0xB3B70C984712F60EULL, 
            0x44B2A86E84E1E5E0ULL, 0x3C7B3B91F4D95F9CULL, 0x7A34DFF8B628D4FCULL, 0x48406ACFC6AEA168ULL, 
            0x2249DC89F7134D77ULL, 0xCB87117C4DCC9E27ULL, 0x4DEF407F3416176CULL, 0xD9410A5080D5BC82ULL, 
            0x2D8EA27125088315ULL, 0x26A6D744F8086EF3ULL, 0x8DE0F5707CA29C5FULL, 0x171AEA9E101ED3CBULL, 
            0xC534DDAF133BD73AULL, 0xBCC9434BBBD3655AULL, 0x3235A9C0CC4D9563ULL, 0xCA05A4372BE940C2ULL
        },
        {
            0x62F234F93EA8588DULL, 0x8C6CB8DE05207968ULL, 0x02F870C0838A5708ULL, 0xE1F2FD8F2548B05BULL, 
            0xEB2AF9E4B69B50BDULL, 0xD10220279A2FE0E3ULL, 0xA33C6E0E802F14E8ULL, 0x0D7C6C73A60198C5ULL, 
            0x6C56A5832EFCDDE5ULL, 0x53CD6A93252856DDULL, 0xC97D1C20D9FB4D30ULL, 0x142F3C402EA79A8CULL, 
            0xB6811D5363C27745ULL, 0x327040803B8727DDULL, 0x9C4DD5790125CBCCULL, 0x14FAC4E84900B0A1ULL, 
            0xECCF570F90AC3965ULL, 0xD0657DFF5D8C52B8ULL, 0x30BC84B1FE8F8C8BULL, 0xA027CE392678B1B7ULL, 
            0x1B8A96EBDAC14277ULL, 0x9DEA8CA349A425E3ULL, 0x30CD93031D0A4888ULL, 0x60D01091C175AC3FULL, 
            0x4073BAF92E159E2FULL, 0x1A4B985ACC4F547CULL, 0xAD2F28B19A046B6AULL, 0x5E31CEDE1519805BULL, 
            0xEF3E7806F52750A2ULL, 0x95E0271F858FFB1BULL, 0xC31BCA472705F3CEULL, 0x29DC75784454DDB3ULL
        },
        {
            0x37CB2976331CFB37ULL, 0x7006B23C9A10BABCULL, 0x8AEE767B9EA56728ULL, 0x82089DF4785231C3ULL, 
            0x4A01B7E63A730629ULL, 0x99AE2EAC1496887BULL, 0xAAD37CCAFA5F55CFULL, 0x56C348D33E8FA5C6ULL, 
            0x0438F1BC5A715EC7ULL, 0xB3635B82F7781B3FULL, 0xCD87464479DDB4D4ULL, 0x152176DF2FFCC227ULL, 
            0x984B1FAE154F7A58ULL, 0x7B7C3AFC3A50CCEFULL, 0xCEA17FA08EBC3235ULL, 0xF3FA3DF936A9FAEFULL, 
            0x1C60FF1999D27084ULL, 0x5FAF17BA0102868CULL, 0x2882FBB06A06A093ULL, 0x3E0EEB8D9DDE1382ULL, 
            0xA41368AB5A1921D3ULL, 0xB9A6852C67F730A2ULL, 0x2CF60D796D97BFD7ULL, 0x2608DF77FA8F497FULL, 
            0xC8A929A37878B780ULL, 0xFCD9F5F4594F420AULL, 0x546F9799BBEF106FULL, 0x8E67127E091D77C9ULL, 
            0xCCBC8E789C199B88ULL, 0x057030275DEF2BA3ULL, 0xB4BB31A04339E817ULL, 0x9564331A9BA681B3ULL
        },
        {
            0xD81C387920A88BA9ULL, 0xC0F579ACF9C9A2A5ULL, 0x326A484ABF890766ULL, 0x3E6F56940C6F1321ULL, 
            0xF639426562BF7C2BULL, 0x1F4FB43D43E950A4ULL, 0x2D7462813AA815BDULL, 0xBEAE47C929CD6317ULL, 
            0x9F221C128DA50C57ULL, 0x414F8B862962E692ULL, 0x44399415E5F5A8D7ULL, 0x558F26C19DA8A43EULL, 
            0x6E4414FF7A5F4C65ULL, 0x982A59D954CB0615ULL, 0xC0E2354607455383ULL, 0x3D41A6BE3C5A6585ULL, 
            0xEBE7CBE10C161A94ULL, 0xC8133874211E3858ULL, 0x53D58F7F29BF012CULL, 0x981B19D0A67ACF00ULL, 
            0x2E886310E64B0838ULL, 0xEA0C1F9CCD2DF279ULL, 0x51776F5A75CF6BC4ULL, 0xCDE6A4E534D21902ULL, 
            0xBB57981B56382D33ULL, 0x01E7C9033BB601CDULL, 0x5AF7AC6C20C1A71AULL, 0x6E2C4D10BB9DE51AULL, 
            0x9AA32D5BAB537D58ULL, 0x15AAC3BEF5BE8A0BULL, 0xB7240F45A5AF749BULL, 0x96CA5B31A9AC33ECULL
        },
        {
            0x286832823C5A2AD1ULL, 0xFD09C810A0E8C512ULL, 0xCF8A86A3766800B3ULL, 0x5DF8652103CC090EULL, 
            0x9DCC92E89D98ED1EULL, 0x79791F06C918995EULL, 0x5602F1BDA432362BULL, 0xA9B851870AA1F20DULL, 
            0xE31D0F758D5CF05AULL, 0x769B413CD4E1D58CULL, 0x48AC7C8735BAD10BULL, 0xFEB03F11AA7AA5A3ULL, 
            0x284CDFF3FCBDAB71ULL, 0xD9D5BB8BDEE59AD7ULL, 0x1E2585AE1B122E08ULL, 0x21F1481F8816E818ULL, 
            0x9C466F1766CC87E7ULL, 0x1D7D6D8D83A06247ULL, 0x290EDC102DA3C55CULL, 0x849D0C7515C79A02ULL, 
            0xA979442AAF994EFCULL, 0x5C2241D581EDBCE0ULL, 0x2AB7AF9BDB624D75ULL, 0x68DD9C8C3CBF9BE0ULL, 
            0xE93997501BCC888DULL, 0x466218AE5573DDF4ULL, 0xAE4116D0E1BED541ULL, 0x3B8F991DA02DBC75ULL, 
            0xD242B055758202E5ULL, 0x7E80F78CC5327960ULL, 0x7E2C112C6E77ED9FULL, 0xE2B99A60714B5093ULL
        },
        {
            0x4E94439914C3442BULL, 0xAE1C0AB02E171AF4ULL, 0xD9C51B96B6031654ULL, 0x79DCD9CBA8FB9354ULL, 
            0xD44AE897BCD9927CULL, 0xC2CC6E85F2FCBA6DULL, 0x3D4E233DEAF790E9ULL, 0x3538523F859B3A7BULL, 
            0xF136175CF36CC7B3ULL, 0x58B60FE1D486C6FFULL, 0xA1E320F4D17F268DULL, 0x27978EF0AC101496ULL, 
            0xC53068608CE0CBE8ULL, 0xFB4DEF8906BF1D1CULL, 0xD97CCE20E71E75BEULL, 0x79CB4B97E64A65A8ULL, 
            0xE130AB9AAF9CDB50ULL, 0x13E27120AC3F62CFULL, 0x698CF7161BCC82E0ULL, 0x093F41A2D5D93F70ULL, 
            0x4AAD94ECFC3BF0C7ULL, 0xFDF77253B9667561ULL, 0x5E37F9B3ECD2B6EEULL, 0xD64CFE71795F310FULL, 
            0x6763ED9DB9471215ULL, 0x3D70065B9763988AULL, 0xDC89F9CBFB268D4AULL, 0x29121D25A3AF59ACULL, 
            0x7F783336B7C3D077ULL, 0xEC0223B894A6E1E1ULL, 0xA204C722A8CD6008ULL, 0x30B4A1F817CB0BD2ULL
        }
    },
    {
        {
            0x9193FC6598855482ULL, 0x95DB8A97DCCD4E57ULL, 0xD1A3456C9021CB5BULL, 0x25C8B39F2D89D95BULL, 
            0x4EAD87E46910D15EULL, 0x89D677EB1A6C7B71ULL, 0xB3C66F24F28AA4AAULL, 0x8A0A3D6619D227F2ULL, 
            0xD1CDD5A729DE0333ULL, 0x9C9916C27D9ADAF2ULL, 0xB7EB24957ADB2BCAULL, 0x893883FEBA8B992EULL, 
            0xD96B2301A0E73FF0ULL, 0xF77CDAC54235E064ULL, 0xDC4B9210529B9E45ULL, 0x680DB2A20AB0C474ULL, 
            0x82AE55C07B88C774ULL, 0x9777944A5A24CDCEULL, 0x717EB604413139D8ULL, 0x2A83ADB77BCDB1D3ULL, 
            0x965DF7F792B46B70ULL, 0xDB1A4223FAC9CF85ULL, 0x47E49C547E8406A9ULL, 0xFB4BB1D690CC0855ULL, 
            0xF81F0BBDCA2A9E34ULL, 0x9C9AE83E547BC00BULL, 0x9B902ECF3C7A7CA4ULL, 0x9BD6779319D07BD9ULL, 
            0x18AFAE1C9ADC0BA1ULL, 0x0FB4798A61FB0976ULL, 0xB7C6ACA24323AFFFULL, 0x9B592BC0D0C9C147ULL
        },
        {
            0xBB1D2134A01CE014ULL, 0x4AF4F64B31441DFEULL, 0x7CBDA19DEBD4F518ULL, 0x0DB882E5D2FF7CC9ULL, 
            0xDE0F6CA05C3EE0EBULL, 0x154169CDC09F1C32ULL, 0x9DB5336A14D3D8ADULL, 0xFFB8399B291BF1C8ULL, 
            0x26F947A0A9D04535ULL, 0x3D331C78C3C51C0CULL, 0x4381983D31F5AFDBULL, 0xFF7D07E52E43D50EULL, 
            0x1DBD9DA97B21F8F8ULL, 0xF840A639B81F9CFEULL, 0x9DCABB4670439A48ULL, 0xDBE05992F30AD7A0ULL, 
            0xAB9ED8F0B4019845ULL, 0xB77C4EA2C01C723CULL, 0x64DC214C9ADB075EULL, 0xF9CA735AEAE2ED25ULL, 
            0x00A52F27D5372013ULL, 0x55DD6C6A7CD4648DULL, 0x4065F6A09C7F4563ULL, 0xB428DAC3951FA97AULL, 
            0xDD479B3E0CC52FCDULL, 0xD835DFD31C4F906CULL, 0x197E3FE58F36CC8DULL, 0x485230700E6F7EC7ULL, 
            0xF727D85E8FB03A06ULL, 0x7FAA462139882E08ULL, 0xA589988A5675D082ULL, 0x5A446D9877E86783ULL
        },
        {
            0x4708DA9018779F17ULL, 0x9478091C8D616B51ULL, 0xE5C884050B2FF942ULL, 0xBEC2C01AFE06F119ULL, 
            0x0B38A0BEEAD72B36ULL, 0x461C25908034C764ULL, 0x4E860FA552F10BFFULL, 0xB111877FC7F38D22ULL, 
            0x0611CDBB165A1AC9ULL, 0xDDF637F699E3E890ULL, 0xFE1933214ECAB0F3ULL, 0xB44557181E0E5904ULL, 
            0xA14A4DEC69865D39ULL, 0x085E7C4DD2BD5C87ULL, 0x40BA02CB88F792B0ULL, 0x8B07CA94519BC1FEULL, 
            0x6721F27DD9FAD25FULL, 0xB251F7AFD84CC627ULL, 0x5A6E653E1F65A1C4ULL, 0x5A92D69D6985461AULL, 
            0x7AD9A572FF8270A2ULL, 0x78635F85E7C7BBA7ULL, 0xED3D146A9581BC97ULL, 0x1D584346D8268ECDULL, 
            0x90C390056600A7F3ULL, 0x0019D2BB58A605CCULL, 0xB62702FA14C3C746ULL, 0x280A8BC25CFB466DULL, 
            0xDC7C61063D780F34ULL, 0x78A5989A91F8FEE3ULL, 0x0A28D31CA708647CULL, 0x441D0E6CE58F4047ULL
        },
        {
            0x4809B6304A583839ULL, 0x91C9AE4859A804A1ULL, 0xB46818B4E9F71469ULL, 0x442F3B00B2BA5B18ULL, 
            0xF5FC6F119F7C2BEBULL, 0x236769E2933F993DULL, 0xCA3071AFDB504C03ULL, 0xE58EEE9C8917CA09ULL, 
            0x61B06E409479FBD2ULL, 0x124247F7A173FF2CULL, 0xA1067078E0A8F9B9ULL, 0x50E440CCA2BAAB3CULL, 
            0x7356854D27DAFCDFULL, 0x154F4FB851491B58ULL, 0xA7B13692FD78AE2AULL, 0xD4C0678F18FFD2ADULL, 
            0xFEF3F148579794C5ULL, 0x5BD4E7344A20736BULL, 0xC2D2E31DDCDFA684ULL, 0x5D7484CB887FDD6EULL, 
            0xB699FA4E5AC2C90EULL, 0x0A73024CAA2498FBULL, 0x2CFA6AF8752A3342ULL, 0xF9B37B57ABE4BCFEULL, 
            0xAE4A285E51079273ULL, 0xEFF3ABC17EB2B18AULL, 0x851DD06A8EBC92F1ULL, 0x690D2490A9A1E8C5ULL, 
            0x558A6360870F68C9ULL, 0xB3B5749323B4E457ULL, 0xD5B7A87EE534CE1AULL, 0x4C0C10579C280D81ULL
        },
        {
            0x12DBE406CD7856BEULL, 0xE9FBFAE91740EA4CULL, 0xF59F3526E282D37CULL, 0x79D5436321B1209AULL, 
            0x7834345F5D0D6AFCULL, 0x6FD142942AB6C998ULL, 0x840B4D364C7D67C6ULL, 0x8FDD1751EFFF3448ULL, 
            0x81BD60BB874E0A71ULL, 0x2DDE79D9C9A7A12AULL, 0x184EC7FEA02F3F6AULL, 0x7888C0F0F3B1E50DULL, 
            0x26B8C128C34DF962ULL, 0x492580B157BB3FA2ULL, 0x316A641BF54CCAB4ULL, 0x92F2BD0D0DCC4A02ULL, 
            0x8D9F7E122743650EULL, 0x80269E5C04987455ULL, 0x35F95989DBFB2D06ULL, 0x758E9797CD268DE2ULL, 
            0x5B1600B8CA13D2C0ULL, 0xB8EDE648FC24B629ULL, 0x3876A6511BF01548ULL, 0x8BC703E668C95CC4ULL, 
            0xBE2D1BE471CF2198ULL, 0x32D9263C22E286F2ULL, 0x5F5B5A45030E274DULL, 0xEDD648C270157EDAULL, 
            0xC3A41BB51D88FFECULL, 0xA093C30F2018EE46ULL, 0x812C09A61A059757ULL, 0x75D3C92E2ECFF682ULL
        },
        {
            0x4563B5E0A1E26FB0ULL, 0x524B812358403109ULL, 0x68B2C1566AF16F01ULL, 0xE63CA151E2C8A2BBULL, 
            0x0D785AC251382044ULL, 0x10CC9F53E0E32BB6ULL, 0x41BA802BA9B1CF6BULL, 0xFE4A5035D0BCBA46ULL, 
            0x776E92642044E27AULL, 0x0220F5CB780E7EF8ULL, 0x35FE53DAFBE3E5BDULL, 0x550D14B7F897B71DULL, 
            0x530579B5800692AFULL, 0xF77C123437DFEFA3ULL, 0x348031E35FF25BEAULL, 0x6B5465485E03022DULL, 
            0x1E2766639DA32E8AULL, 0x05F1DAC6EC88591AULL, 0xD9B89B26105B6BA9ULL, 0x5A1002A2FFBC2993ULL, 
            0xEC816C5DB9E9BC33ULL, 0x4495CC74C3F8D90FULL, 0x8B26F35AD6795FD8ULL, 0xDDF3FE109C604195ULL, 
            0x3A9DB914E9740890ULL, 0x51FC864B52469C9EULL, 0x84EEBEA9AC0605DAULL, 0x32E1C6CEC7F9C9C0ULL, 
            0x1810E58C62B7655EULL, 0xEDDEFF976C692456ULL, 0x073D09BA7C79EF86ULL, 0x58B1CF709E584A1FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kSeedConstants = {
    0xFA18C992A5553D79ULL,
    0x29A2228217407499ULL,
    0x930712E07433A385ULL,
    0xFA18C992A5553D79ULL,
    0x29A2228217407499ULL,
    0x930712E07433A385ULL,
    0x0E1CD96AD50864ACULL,
    0x589D91B4753EB40EULL,
    0x07,
    0x46,
    0xE8,
    0xDF,
    0xEC,
    0x4D,
    0x54,
    0x92
};

const TwistDomainSaltSet TwistExpander_Polaris::kTwistSalts = {
    {
        {
            0xF4D19890B753F952ULL, 0xE9DC7C18F923C574ULL, 0xDB21034D3113A9C8ULL, 0x154FD6EC7F243B17ULL, 
            0xC989FAC2C0C0C93FULL, 0x8D571FB194344F4BULL, 0xB813247C93D83F2AULL, 0x4978C8939CF22B16ULL, 
            0xB25C8B7516BA3478ULL, 0x7C2C6C6C507BFF28ULL, 0xE4A7108D9AEC4AF3ULL, 0xF9F4C0B3D214BA97ULL, 
            0x542645A79B67345EULL, 0x37CBCF1869345928ULL, 0x983D7F346AC74AE9ULL, 0xD7FE349294446345ULL, 
            0x0B27EBBD2C3FE8FBULL, 0x0681B34D7CDEB35BULL, 0xCE06F76200C45DC3ULL, 0xF11A0016EBA56920ULL, 
            0xC266102932DE1C20ULL, 0xBA51562D3FCC0283ULL, 0xEDA8841018295330ULL, 0x607E037532A5EF11ULL, 
            0x2E23AD9E0945BF11ULL, 0xA4B77AD545511174ULL, 0x72C997AAB6EB7692ULL, 0x9ACFFAB19E1AC888ULL, 
            0x24D4808A5D593EDCULL, 0x6FD916C014C1E4EBULL, 0x6B80A6D896B262A1ULL, 0x5A7F8004A2B9DB1FULL
        },
        {
            0xE7354BF7E9AEBE70ULL, 0xF947C63F3F67C2D2ULL, 0x47895806FC39966AULL, 0x32C49F4512F99A34ULL, 
            0xA27D89D8FE53F822ULL, 0x1C9F3013AF267718ULL, 0x7C822FE59390AA20ULL, 0xE8748AD794C156EBULL, 
            0x7CC5B79B678EF3A7ULL, 0x6B2D3D3420623879ULL, 0x820553BC9DA3F02DULL, 0x780014369878EEDAULL, 
            0x3B4200AA76AD5539ULL, 0x7C455E7767D54135ULL, 0x58187408C415AA96ULL, 0x7845A3CABA0714DCULL, 
            0x32D8FAC305E990BAULL, 0x2926C84A575BCF5CULL, 0x086E06CD0D1C0673ULL, 0xFD2E8A543E34DC47ULL, 
            0x9F928AF773251C2FULL, 0x3CEC9C83DB7F1406ULL, 0x36C4A09381CF81DEULL, 0xD830C46148939A64ULL, 
            0x34F24D1ACB661BA7ULL, 0x51E9B8E3D0645BF8ULL, 0xC4D43E683E6E2201ULL, 0x095E0D92261A0F56ULL, 
            0x6CAF26D0CDE071A8ULL, 0x9F258A1B95D5AD82ULL, 0x8F72E1DE45F575E2ULL, 0xA21507EA5DF30F3EULL
        },
        {
            0x0FBD892179187A4DULL, 0x58B004F626472B4AULL, 0xED839C0CB69AD772ULL, 0x11526245527FCC3CULL, 
            0x8C3D237219D1AAA3ULL, 0x336B758DCF49CCDFULL, 0x09D16E6D28BC0AD6ULL, 0x72DD52D96457EF21ULL, 
            0xDFE2896EAEA7D435ULL, 0x544541DE29471D90ULL, 0x9D17E556F4B282C1ULL, 0x2E8D2B531F31E5D6ULL, 
            0x160C0AB9FD0FE0BAULL, 0x367D23EB7433D1CCULL, 0x0AF16DDFDA6BC643ULL, 0xA28523AFD94E843BULL, 
            0x495DEB2EADBBA498ULL, 0xB9D5C113157405D6ULL, 0x5EAF743673E66A02ULL, 0x4BCFEA9D3C2E0970ULL, 
            0xE545068C560F41B7ULL, 0xBA40594FD7AA27E2ULL, 0x512E05A2A38D2E5FULL, 0x2DE93FF137A5C2CBULL, 
            0x1EA25C02BF261E35ULL, 0xE76C4E3A50887F88ULL, 0x7A4AC83488C8545EULL, 0x4B8F7B4BEF676B5EULL, 
            0x54CC72B47B3A293AULL, 0x43F54EB3DFA25A95ULL, 0x44E8C5DCD5AA62BDULL, 0xF78FECF8B2B024A5ULL
        },
        {
            0x72A8B8FE92C260B9ULL, 0x60B806011E7541E9ULL, 0x04B3536E4C1A2B45ULL, 0x0C21241C545CEF79ULL, 
            0xE422A25200AB2039ULL, 0x507EA1B04D64F451ULL, 0x3EFADFC7EAA95768ULL, 0x005D14650571A09CULL, 
            0x6DBB30A16198775EULL, 0x0AACB4B3EA5CB34DULL, 0x8F8AEDE51D3F5348ULL, 0xA9428A53CD9257BFULL, 
            0x0F25FC6977A3BC2EULL, 0x9BA9549585C1AE5FULL, 0xA221569582AF3BE1ULL, 0xB77B49642DB779C8ULL, 
            0x11BB7D8458845BB8ULL, 0x147FBD197422105CULL, 0x970BFB47D7C58022ULL, 0xA2B30B315C507B3EULL, 
            0x95435087E1106C6BULL, 0x11E328FCF73139F0ULL, 0xB012ED4440E32702ULL, 0x040366A409D344B2ULL, 
            0xDD51E9CE9774AEFAULL, 0x7425D8463353EC46ULL, 0x95E5F53C402CBD88ULL, 0x0B9DD96A0B50290DULL, 
            0xC216D694521450D4ULL, 0xA7CFFEFE23C96DCAULL, 0x9CF4434E99D70937ULL, 0x0D6DE42E7AE67C89ULL
        },
        {
            0x80ACA33A39180078ULL, 0xEC6AC5B313734732ULL, 0xB0DA404D53E4A9B8ULL, 0x35475F44A4521921ULL, 
            0x2137684F58118A7EULL, 0xB77AAC9DC126077BULL, 0x3AB2D18DBFE0E0AFULL, 0x48F20FD379CF30EBULL, 
            0x3F83D4B32072D524ULL, 0x44FA0953E48891D4ULL, 0xB97D75D4778E533AULL, 0xDAAF6A4EB961B43AULL, 
            0x70026A20B58E0AD4ULL, 0x08E9BE853C23BFB9ULL, 0x28BBDC2F5F600454ULL, 0x681885F0D9F5A018ULL, 
            0xA65FE4129DED22FBULL, 0x69BF802877B80C63ULL, 0x87E50722F0067D2DULL, 0x6E01BFA27361553BULL, 
            0xFCA77465DEB43A25ULL, 0x95AF0BFA5E0E078EULL, 0x2FBB8E588AD292ADULL, 0x27B085AF53CCA0F2ULL, 
            0x50A0DCC2F5C598FAULL, 0x9F58889079E5DF45ULL, 0xD9D0962B4AC7EE0EULL, 0x42D757A5956E8F69ULL, 
            0xEA2CF907275762A3ULL, 0x199AA69730D5B5E8ULL, 0x59ED346CF5A21F55ULL, 0x07B5D94FE1B6BB89ULL
        },
        {
            0x3F1390D789189F95ULL, 0x39DABEF2A1CD917AULL, 0x1A1CD0C3700CA25EULL, 0xC14FFF8C13562AADULL, 
            0x131643B487C8C6DFULL, 0xD1EEB69676FFEAF0ULL, 0x0A7CFF3642A43BECULL, 0xE4C16B72CB810D00ULL, 
            0x54EF1652AC7FF0F3ULL, 0xFC15EE1A9E22D614ULL, 0xF38A18477F01F39DULL, 0x7A53EFF4AAD5591CULL, 
            0xC81328354C6BDA33ULL, 0x626B188A32BAC8EDULL, 0x2FC3A0073AE9B8D4ULL, 0x2A934EBC28141BBBULL, 
            0x9C6FD5D1C3A6AE83ULL, 0x03B748082F421059ULL, 0x5A9EF87989343750ULL, 0xCA08D76D2B9ED06AULL, 
            0xE964EC28973CF429ULL, 0x1A3463C5ADEC8F79ULL, 0xCDCF3C5EE810FEC7ULL, 0xAF2D14AEE9FD8544ULL, 
            0x8CC5C36997DC9939ULL, 0xFB6A4D311F5D53C4ULL, 0x7427BA15062A4DB0ULL, 0x3A41FCB0E5B5CAC6ULL, 
            0x4691FC5445A0A225ULL, 0xDF33A4418FA36EFAULL, 0xF507ED4AA44233F8ULL, 0x5A8EAF825BE9526BULL
        }
    },
    {
        {
            0xCE92DA619B84B76CULL, 0xB7977E0176BB0E11ULL, 0x2A9790C385B571C2ULL, 0x9C6F358FF0575F62ULL, 
            0xAFB6FE8DC08D07E4ULL, 0x22C6D118F8C87957ULL, 0x386852467FE68E8EULL, 0x6B573597E82D5781ULL, 
            0x8A8B8B0D57F3F7A1ULL, 0xB39FF0BA5191A720ULL, 0x73FF9BED4A14A4B0ULL, 0x53DE3E07610193D2ULL, 
            0x20D83239A03F5C73ULL, 0x0F2CBF8231361622ULL, 0xFF7F850185B0DDF0ULL, 0x83DEE948A5683DC9ULL, 
            0x3EE6AAA46C96A947ULL, 0x7AE076493EDB2588ULL, 0x01FA1BAC5A91A22EULL, 0x3F8FBCA20065AAA1ULL, 
            0x1AC4582CFB9D5C55ULL, 0x0F0CC0413C2F8B74ULL, 0x88699A53A05ABA03ULL, 0x00E47EDA58CB6977ULL, 
            0x9832C8D7F87DC330ULL, 0x106E8A68BA7B3E88ULL, 0x3AAF9DAF5FB54D97ULL, 0x9581487D41219795ULL, 
            0x97DE0B4D196E4A06ULL, 0xAD3C2BF4789D5F7AULL, 0xA8D70D53E54C27DAULL, 0xEB2CC7BD561AEA02ULL
        },
        {
            0x8FB40D9F4C50A3E2ULL, 0x17AE43217D416B11ULL, 0xFB5AEBFA29FF5E42ULL, 0x86D10A3B87D819AFULL, 
            0xCC9E51F86A3013E7ULL, 0x22821559CA216FE7ULL, 0x09C017BEFF3720B0ULL, 0x5A9D0B7641BD8918ULL, 
            0xEF18E1880B6AAE54ULL, 0xC6D84A665EAEEBB5ULL, 0xD2557A0FC3BB635EULL, 0x70DDE2562E78DAE7ULL, 
            0x7DB0A9C0CC66BDD1ULL, 0xE0EDF24F4C58459BULL, 0xEC72596591763EAFULL, 0x26DDB378C4AA3457ULL, 
            0x61F1934947C67DFAULL, 0xC3EE7F84353B8FC5ULL, 0x1C92BACE505E7DD3ULL, 0x2FFC15133C7F6709ULL, 
            0x521062E590C9967AULL, 0xFBD88E3A9842C008ULL, 0x768D467A900F51A7ULL, 0x1A5C0F470C25B2E6ULL, 
            0xBF42A1F7F84F30C8ULL, 0xB61BE071044AA059ULL, 0x2765A450D5C69F35ULL, 0x8DD6F9971A09F11CULL, 
            0xECDFCDFA00F95764ULL, 0x48EFDAAF3773DDA2ULL, 0xE1DC5C3765E2BEE9ULL, 0xE73E3397F147FB45ULL
        },
        {
            0x995E41150347C289ULL, 0xCCAED262866618F6ULL, 0x221235FBDEE61883ULL, 0xE33CD899A0C96C65ULL, 
            0x113A9C6E80BD54DAULL, 0xEC6C780FFE4EC8B4ULL, 0x29471F0B86844BAEULL, 0x06CF6564BA5E61A6ULL, 
            0xCD05A4D82B02672FULL, 0xE4AAE2799D2C8158ULL, 0x31A9D682329E536EULL, 0xF4B2C2B18AB31B12ULL, 
            0x54A8FD6E62988B19ULL, 0x7FAA1EA79286A9B0ULL, 0xED48E7293C412E09ULL, 0x81C215B7F9B6EF9AULL, 
            0x74DF2AFDD210D110ULL, 0x8E423A0A98AE7D29ULL, 0x9F75CC1B0D8B1836ULL, 0x0821BAE6A8E8B89FULL, 
            0x5777088E4BC2C6C6ULL, 0x0EC2BC8C4F236D6BULL, 0xAD234C9544C38D04ULL, 0x83AD70D6DA1B4C3FULL, 
            0x7E0051F30A6EC6E2ULL, 0x5B168D63C258F446ULL, 0x3D43CFF0450F9BC2ULL, 0x612FA96A5ADD37FEULL, 
            0xDC7B10B60BA9FCF1ULL, 0x1DC157BEB959BAA2ULL, 0xA3A515B66924C704ULL, 0x391E7063C03D8D15ULL
        },
        {
            0x02DA32310DDC99A0ULL, 0x5D1EB61FC195710DULL, 0xEE88B477203E3D9AULL, 0xE59F9D5AA931EE43ULL, 
            0xDCA6E389FE1DD51EULL, 0x8898B060B57C5425ULL, 0x81106DA540C42325ULL, 0xB757959F6D0D41A1ULL, 
            0xFB000CB21CB7C11DULL, 0x6B013AE67836E6DBULL, 0x802D8730C460452BULL, 0x9ED9E6617474AA59ULL, 
            0x019C3F6402B44A16ULL, 0x4CF79BE056FE8026ULL, 0xF063B0A83953FE34ULL, 0x5FADB3DA362A8A40ULL, 
            0xA99DFABE21D47E8EULL, 0xAD48DAF6CC4D323BULL, 0x8F90F27603A0325FULL, 0xCCC7756F70848F55ULL, 
            0x33C746574A4A0F73ULL, 0xEF36004E4CABCB79ULL, 0x915AD21260D139FDULL, 0x731CDA4974D11DECULL, 
            0x800FDC85E2D974E2ULL, 0x438F050E58C67D8DULL, 0xD7F25F9E2AF311D3ULL, 0x180566B0F30DA4D1ULL, 
            0xCC0649258C07E299ULL, 0xBFA78CF14B6BFCF5ULL, 0xC73ADA3E55FF54B9ULL, 0xD32B2D92B11F45F4ULL
        },
        {
            0xCCC2D05F1E30C6CEULL, 0xD6BE9EF0D2C49A26ULL, 0x5BABA0905457A6E5ULL, 0x80B4AD4FEFECC189ULL, 
            0x71EEE10A9E8736A8ULL, 0x3BABD2DA1901DA80ULL, 0xED406ED176FD8488ULL, 0xAA6C2BC1201AF2A9ULL, 
            0x01CB6D43BE305A3CULL, 0xFBCBE81C8C0E40F1ULL, 0x3471C6204B9224F8ULL, 0x4E1960B6534B6E32ULL, 
            0x517FDFE15860E917ULL, 0x81BB8D3972E7B1D1ULL, 0xBA18BB3EB3FF3139ULL, 0xC3869A4FEAEB73C6ULL, 
            0xD47B44EBDF0A90B4ULL, 0xA7DBA930E5D663CAULL, 0x214E867658AB726EULL, 0xE505ECBEC6C9A45BULL, 
            0x0158B0200B8EB907ULL, 0x67E7293F90563245ULL, 0x4CB85178A62341F7ULL, 0x877C019B28668441ULL, 
            0x99DF7C7166342A36ULL, 0x75B179240E233B96ULL, 0xBDAA0FD315B03D03ULL, 0xEA9CC225A03F37B1ULL, 
            0xAF0657B35F882694ULL, 0x4CFB32B19477D5E1ULL, 0x671EAADDBCF86DE1ULL, 0x385FD45FBACEED8CULL
        },
        {
            0x8E310B7D1A8AEF12ULL, 0xAED4F1424E3DEB4CULL, 0x16E23FF71BBDFCF8ULL, 0x1C247529CDF21598ULL, 
            0x7A8AF899A9CDE317ULL, 0xAE3E139C41CA9634ULL, 0x21897C522DD8BF0AULL, 0xF6895B9D2BAE7B35ULL, 
            0x21116A75843460AFULL, 0x7C00FD7F3B6A2828ULL, 0x53C160D9981AABC9ULL, 0x4910F6D152397BF2ULL, 
            0xDB234CA1DD0D7ED2ULL, 0xEAE58B0E54E0BAC9ULL, 0x9BA6F3B2E066B2FFULL, 0xF284976762B0E09CULL, 
            0x5DBD8ACFF55928E9ULL, 0x6151F0E8B9D1359BULL, 0xF6E171901100A9F8ULL, 0x974A71EEFEF2DE96ULL, 
            0xCB28AECD1DFAE784ULL, 0xAB7F84A15A329502ULL, 0x21A03631CA5CF311ULL, 0xF58F0F8C68DA8FDDULL, 
            0xFA6117ACB8BC64C9ULL, 0xF5BBD729B6A34540ULL, 0x63BA50C00B76A5BAULL, 0x5679BF2036DB5427ULL, 
            0xE087A80588FE1153ULL, 0x832B30FB421496A5ULL, 0xC7004B048D1FB246ULL, 0x6623E2EF746F73ADULL
        }
    },
    {
        {
            0x85E19CF273913130ULL, 0xEAE7FA45324A8DDFULL, 0xAF2FC4AB85167650ULL, 0x3A69140946E07873ULL, 
            0x20A4F7FF8EE8D5A9ULL, 0xCEC8693D816C6F5DULL, 0xF35069A06C570442ULL, 0xAF568BEEDE07BABFULL, 
            0xCEE68D6550179755ULL, 0x0849D5273140ACB7ULL, 0x63D669B6B071C40BULL, 0xD6FD838C707ACC48ULL, 
            0x118786AF1AAB3CC0ULL, 0x0830469FB30B3689ULL, 0xECE3228CEFE68158ULL, 0xFFF99C090B7C928CULL, 
            0x2CF3829678D13CE0ULL, 0xE09A770C040C56C0ULL, 0xF47B9B3F7E588CBBULL, 0x1F408DF7132F67CAULL, 
            0xA0FEE355E61751C2ULL, 0x5A117262BD1DDAAFULL, 0xB81757C36DEA2CAFULL, 0x1BB0DD9231AF22E6ULL, 
            0xDE8FC92A4905AAC9ULL, 0x5BE79D9EDBFDE217ULL, 0xA10AE4863930ED7BULL, 0x1FE5CD9DDFE57AA1ULL, 
            0xCDE5163707711402ULL, 0x10EF52DB43CF6E0DULL, 0xA060D62316842FB7ULL, 0x13D93F16BEB9F61BULL
        },
        {
            0x4ACF393053D91FADULL, 0x6836AE355512C44CULL, 0xC4DA827D4025D02AULL, 0x1384C1F426642A13ULL, 
            0xC9461F43DEEDC93DULL, 0x7DB7617C0A3FC7B8ULL, 0xB0BBC255C447CB89ULL, 0xB0B743D859A3A696ULL, 
            0x0B3E8B7B3A7EC38BULL, 0x8255A3F110D8D85CULL, 0x9DFF8854088D2EE3ULL, 0xC7FA3969EAA57495ULL, 
            0x7EE8F75731F7E0F3ULL, 0xFCD804115149632AULL, 0xE02C5B285DE2CF59ULL, 0xB0046A1CBA3A0812ULL, 
            0x89E7C6B65D38F9C7ULL, 0xD44A8EEB885FC6C8ULL, 0x2B944640BD14A7C0ULL, 0x6928A9534CEC97D8ULL, 
            0x6BA769D86C1044F0ULL, 0x161CBC99E9A77FF7ULL, 0x4984C303E1E86758ULL, 0xAC7D8156B6AD94DAULL, 
            0x08386B9561F5093CULL, 0x473360FA26F8B823ULL, 0x803998CB56499A2EULL, 0xEE6BE54316E276C2ULL, 
            0x1BB64D569AD10C4AULL, 0x81C2E5BAC45B6EFAULL, 0x374CF6BD266D8B51ULL, 0x342A275C0AE22255ULL
        },
        {
            0xCC6EE3910C651A8AULL, 0xAC78FDC597029DD8ULL, 0x9D8EF4650D292759ULL, 0x5DE68E8C914DE07FULL, 
            0x615890A02401BD52ULL, 0x9EB7954A0964A574ULL, 0x1913EAB0C979B597ULL, 0x557FE62A3903E653ULL, 
            0x6826B703D079DE8DULL, 0xA60B36F0C5D2EB9DULL, 0xE447F22F66A70EE8ULL, 0x43C5BB524E8C1C10ULL, 
            0x5466F3E285DDEFA2ULL, 0xAA19FA7276C7124BULL, 0xFE72ECBDE4F8944EULL, 0x5AE6019FCB93299BULL, 
            0x542055E0272B4DACULL, 0xD4E0FFDF335D103EULL, 0x7CD7CA63BCCB69EFULL, 0x4AEA0E27144C1FDEULL, 
            0x5717B0843E978629ULL, 0xF2D75980A07E4462ULL, 0xC5AB8D73B5F60AE0ULL, 0xEF9A436032723B90ULL, 
            0x36BB62B1FB4A3775ULL, 0x83EDFCA91C01EDE3ULL, 0x9B948BFF859F4E9DULL, 0x9B3B5736562DCB6BULL, 
            0xAA24106911D4F058ULL, 0x98CA3161E2DFD255ULL, 0xAE509E848D49B97BULL, 0x2EF9A19D63AF5EE2ULL
        },
        {
            0x94810521B47AD7C1ULL, 0xB66C43503618923FULL, 0xFCD4BC6F47CF6EF9ULL, 0x92903FD5BEBCC5F3ULL, 
            0x1265B9E1E632D2A2ULL, 0x59C81D56FA2769CFULL, 0xD6BDDED1BB86A5FFULL, 0xBD709EF3C0410197ULL, 
            0x72D6378FCDC68E31ULL, 0xF6F408F072CECBFFULL, 0x0DB5AC99C04A2B6DULL, 0x0EEF81659A29A1D4ULL, 
            0xF5D4969BF234F584ULL, 0x08D7E5F74FFB581FULL, 0x2B5A00D677999B52ULL, 0x4543A8EE52EC6137ULL, 
            0x9340479CDAD452D3ULL, 0x80DA7F3DCA5D691AULL, 0x6DA48CC47406A373ULL, 0x60D7E842820338CDULL, 
            0xF2F49939CC93BD5EULL, 0xA4E55E92D351A3EBULL, 0x2CA05533BE0D9F50ULL, 0xD0902E0BD0B70BEDULL, 
            0xFB67123B1F69F8E3ULL, 0x5587E1710C781B48ULL, 0x5C4DBB7085D2633AULL, 0xB56C3FA8B4A3D6B8ULL, 
            0x57729E1110D1E4AFULL, 0xAE8ADCDB48D0F2F3ULL, 0x5480809803945BCDULL, 0x7CA26A061552058FULL
        },
        {
            0x620784CF87877182ULL, 0xF83BF510AA6DC057ULL, 0xA27EB7491B565FD3ULL, 0xCDE463B460EC9739ULL, 
            0xBAE5260FB9A5658CULL, 0x129663FE0BA09E1DULL, 0x8D670EC7DFD452E5ULL, 0x607C2FCD0FEFA13CULL, 
            0xB230FF755A5E9CD6ULL, 0xBD61116FFED5DEA8ULL, 0xD3942787CCDAAFDDULL, 0xBD1FAEEDB5936CE1ULL, 
            0x7C14FC636E6E7500ULL, 0x78C03226C90D78ECULL, 0xB17009D6F40263C9ULL, 0x65D75636EA24CA5BULL, 
            0xE004F877496A6AFAULL, 0xAE4760E8C262A204ULL, 0x20F11FE78919360EULL, 0xB53C72D482259601ULL, 
            0x1C2492C8576132CAULL, 0xA0BDB268937C82F3ULL, 0x398675C1CB1D9A6DULL, 0x0160759AD452A9F5ULL, 
            0xF693AB5589F02A8BULL, 0xAD126CE5C1FA1AF4ULL, 0xA298D798EABBA191ULL, 0xFDD724625BEFCAA2ULL, 
            0x02EFBF83B9F06591ULL, 0x8527D8CDAEABFA7FULL, 0xAA7908F9232D4ABEULL, 0x2C1CD4ED1FF26C12ULL
        },
        {
            0xBE9D989378EAE31FULL, 0x1D6AC52B125C623AULL, 0xCFE38D71CA970593ULL, 0xEA5CA100C6123A82ULL, 
            0x17CAAB8F9EA508C6ULL, 0xDBC076EF88CBEABCULL, 0xDFA7BFC4C5E94664ULL, 0x7DAB429E8CDBD018ULL, 
            0x032967B412F1AA5EULL, 0x2F5982E05B9C1FE4ULL, 0x095DC56BEA5D6FC9ULL, 0x88E203E20F093DCEULL, 
            0x66180C286694F672ULL, 0xD86BEC31F9146FE0ULL, 0xB9329F5E645AA791ULL, 0x6756D6DED75174C7ULL, 
            0x71366418A93B35F2ULL, 0xF45E55E3857143C1ULL, 0xBC1551E2222693F1ULL, 0x8FB2978D57401E29ULL, 
            0x257B93922A0E89CDULL, 0x261721587EF9CD32ULL, 0x1D4516A83018D99BULL, 0xAAC39D459D33D69BULL, 
            0x49B7CAF02F6DF9C7ULL, 0xFE182EAF1F9870B5ULL, 0x58D3F3E79B7B2527ULL, 0xB0A830CBF1AE3A3DULL, 
            0x2508C630F88D0160ULL, 0xB8719C2E3DCE4DD6ULL, 0xBB6991211FF197E0ULL, 0xFE3BECA3A16292ECULL
        }
    }
};

const TwistDomainConstants TwistExpander_Polaris::kTwistConstants = {
    0x4B964988415700D6ULL,
    0xA89FD0398024F6D6ULL,
    0x70D66391DE69B781ULL,
    0x4B964988415700D6ULL,
    0xA89FD0398024F6D6ULL,
    0x70D66391DE69B781ULL,
    0x422A05DC5F3B5AB4ULL,
    0x2477FC7616C6D658ULL,
    0x53,
    0x1D,
    0x26,
    0x6E,
    0xEF,
    0xA1,
    0xB1,
    0xA8
};

