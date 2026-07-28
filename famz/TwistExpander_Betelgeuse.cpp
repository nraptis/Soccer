#include "TwistExpander_Betelgeuse.hpp"
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

TwistExpander_Betelgeuse::TwistExpander_Betelgeuse()
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

void TwistExpander_Betelgeuse::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEA8D6C75D3B72E66ULL;
    std::uint64_t aIngress = 0xC03B698376F70500ULL;
    std::uint64_t aCarry = 0xC7431D99C07AF83CULL;

    std::uint64_t aWandererA = 0xAB59376CBB8C910EULL;
    std::uint64_t aWandererB = 0xF736D9FA9F6B14F1ULL;
    std::uint64_t aWandererC = 0x97DC87E9D2A77B42ULL;
    std::uint64_t aWandererD = 0x8823C2F79A67572FULL;
    std::uint64_t aWandererE = 0x95FA3EFD2C11114FULL;
    std::uint64_t aWandererF = 0xBAE29DF2C84A3D4FULL;
    std::uint64_t aWandererG = 0xEAD1F5F2C6ED83D2ULL;
    std::uint64_t aWandererH = 0xCFDC8A3039365B58ULL;
    std::uint64_t aWandererI = 0xA182AB209AA241D3ULL;
    std::uint64_t aWandererJ = 0xB559F4BF6B52E764ULL;
    std::uint64_t aWandererK = 0xAC5AD7898C901500ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xB2BB6C34208B271BULL;
    aIngress = 0xBD9FDF2DB7ED4AA2ULL;
    aCarry = 0xA98FB0AA60C00296ULL;
    aWandererA = 0xC6E2626FEBEA2134ULL;
    aWandererB = 0xA33F47D7E679F9F9ULL;
    aWandererC = 0xF673C8C12C4E3A78ULL;
    aWandererD = 0xCBC694A3363FA99CULL;
    aWandererE = 0xB74C6BA422D0622BULL;
    aWandererF = 0xA5805886D374DE8CULL;
    aWandererG = 0x824E3BD8DFD11FFCULL;
    aWandererH = 0x92370077F44C2A5EULL;
    aWandererI = 0x85B09324ABA22BABULL;
    aWandererJ = 0xCAC6369C87BAA065ULL;
    aWandererK = 0xF9192484AEC4BCA8ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xD2FE9EC2BA646769ULL;
    aIngress = 0xF778DCD01AF05BC0ULL;
    aCarry = 0xAD81DD0A743D1310ULL;
    aWandererA = 0xC58C057D19952B34ULL;
    aWandererB = 0xEF72DADDF2CA08EEULL;
    aWandererC = 0xD182F730277A2CC1ULL;
    aWandererD = 0xCD0F1CC17FB50102ULL;
    aWandererE = 0xF362775320ED9B32ULL;
    aWandererF = 0x935A367C438FD7B1ULL;
    aWandererG = 0xCC5278E05667051CULL;
    aWandererH = 0xF0BB310A8600604CULL;
    aWandererI = 0xF9266D588D4DE80BULL;
    aWandererJ = 0xE0FE30332B6E8F6EULL;
    aWandererK = 0xAFBD9828D1D378AEULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xDCB84724911ADCE1ULL;
    aIngress = 0xC806723CF47E8D65ULL;
    aCarry = 0xF15DA56A4D1F2922ULL;
    aWandererA = 0xFE5852B47E51D936ULL;
    aWandererB = 0x8210E17340481108ULL;
    aWandererC = 0xA2DDCDC7BDF58093ULL;
    aWandererD = 0xCD9B30B77B1ECDBEULL;
    aWandererE = 0xF3EE0900B8815850ULL;
    aWandererF = 0xFB0C041C3B80D05CULL;
    aWandererG = 0x91747AD20487484DULL;
    aWandererH = 0xCBA7396470C974C6ULL;
    aWandererI = 0xD604F5DC3C8A121EULL;
    aWandererJ = 0xF937646A244AD5A2ULL;
    aWandererK = 0xDEA89188AA9BED2AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x903BDEF94133AF0CULL;
    aIngress = 0xC61BB9D88143C775ULL;
    aCarry = 0xFE3845C8E9607BB5ULL;
    aWandererA = 0xBE01621A44FC57DEULL;
    aWandererB = 0x8A249D0E132976B9ULL;
    aWandererC = 0xF80BAF6A579538C7ULL;
    aWandererD = 0xCBD0DC1118C9DDA5ULL;
    aWandererE = 0xA25132080340F3E2ULL;
    aWandererF = 0xB3FD41D2C9DA16E9ULL;
    aWandererG = 0x9ECED8DB112B1E90ULL;
    aWandererH = 0xB457A420B97D6BD2ULL;
    aWandererI = 0x95B38DA3D7C21C3DULL;
    aWandererJ = 0xC0CD37C8DAC536DDULL;
    aWandererK = 0x8A6102A12ED8BDD7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xFB0A66AC5C488233ULL;
    aIngress = 0xE1FE9D154ABF768AULL;
    aCarry = 0xF340F2B483FBD3EAULL;
    aWandererA = 0xF61B64B351045BB0ULL;
    aWandererB = 0xE4BC89A21F83DCEFULL;
    aWandererC = 0xA0BAF98C8CF0516DULL;
    aWandererD = 0xE6B91121A8001349ULL;
    aWandererE = 0xB0D4FBA183E99654ULL;
    aWandererF = 0xDB8F1A89442FE867ULL;
    aWandererG = 0x961F62D4D15213F2ULL;
    aWandererH = 0xBACE4E5DE49434F4ULL;
    aWandererI = 0xABBA092B610DD9DBULL;
    aWandererJ = 0xFCD4C50C707C9222ULL;
    aWandererK = 0xE10E9212FF04F8BDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xEBA3B2F27D9C39CDULL;
    aIngress = 0x80A5F3C77515EBC4ULL;
    aCarry = 0xE557B5F7C6648A9BULL;
    aWandererA = 0xF831CAB453992CCAULL;
    aWandererB = 0xCB4D86651A0B5A10ULL;
    aWandererC = 0xDC2E4AFEA83499E1ULL;
    aWandererD = 0xFE1D3E71B725947EULL;
    aWandererE = 0x834B829EFB7D9ECAULL;
    aWandererF = 0xAC393AF85D46C800ULL;
    aWandererG = 0xC293573640DDDBC5ULL;
    aWandererH = 0xE94EB371DB997125ULL;
    aWandererI = 0xB6D46435C5C02201ULL;
    aWandererJ = 0xE3BE664E7D120F54ULL;
    aWandererK = 0xE8DC54911CF840FDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xA16ACC5FDC9E6C2FULL;
    aIngress = 0x93054DF290F03C49ULL;
    aCarry = 0x8BC57B9A9DE6880AULL;
    aWandererA = 0xAE16809938AC02D1ULL;
    aWandererB = 0x961B9D88096A09B4ULL;
    aWandererC = 0x9F0A86887977F845ULL;
    aWandererD = 0xE6037CBF6519A9EEULL;
    aWandererE = 0xE3C4DFDC17622FBDULL;
    aWandererF = 0xCB36FBA7C6D5EDF8ULL;
    aWandererG = 0x9111E2BE05B7049CULL;
    aWandererH = 0xA398C14FFE69DB29ULL;
    aWandererI = 0xEC451CC19B72CF3EULL;
    aWandererJ = 0xF302ED3BA6649FE8ULL;
    aWandererK = 0xCC6B7CABE6440624ULL;
    //
    TwistExpander_Betelgeuse_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Betelgeuse_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Betelgeuse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC3D449CF7B0AE6F1ULL; std::uint64_t aIngress = 0x80503030F7BDFBE6ULL; std::uint64_t aCarry = 0xD3DDE6561B09A4CDULL;

    std::uint64_t aWandererA = 0xC6523DA129D8AAE0ULL; std::uint64_t aWandererB = 0x91BF99335BAE0924ULL; std::uint64_t aWandererC = 0xDD9230F61A2FAF33ULL; std::uint64_t aWandererD = 0xE09739F02722FF80ULL;
    std::uint64_t aWandererE = 0x9A16CEA8654AD2FEULL; std::uint64_t aWandererF = 0xE203DB2B21F25AE8ULL; std::uint64_t aWandererG = 0xEC51ADFF16666F42ULL; std::uint64_t aWandererH = 0xC3835C3E00CB5064ULL;
    std::uint64_t aWandererI = 0x8AF233B2BD68FC87ULL; std::uint64_t aWandererJ = 0xEF3C0362749D9EEDULL; std::uint64_t aWandererK = 0xFB93802A95B963C3ULL;

    // [twist]
        aPrevious = 0xC8FD33C21C58D23AULL;
        aCarry = 0x9B5C2AE94B31ADB9ULL;
        aWandererA = 0xBF88B88814CEF93FULL;
        aWandererB = 0xF73D998F12F2F998ULL;
        aWandererC = 0xDF9391BFE039933AULL;
        aWandererD = 0xCCF8162708A937DEULL;
        aWandererE = 0xAAF9303069CA61ABULL;
        aWandererF = 0xE86DD5CF48A4C628ULL;
        aWandererG = 0xB72415062E59F116ULL;
        aWandererH = 0xDB7D86D12970923DULL;
        aWandererI = 0x8BFE5D3465119F4FULL;
        aWandererJ = 0xB24CF9AB5FFEB3B8ULL;
        aWandererK = 0xD85ADEBE13AB118CULL;
    TwistExpander_Betelgeuse_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Betelgeuse_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Betelgeuse::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 13 of 33
    // Exploration cases: 0
    // Structural maximin 529 / 674; family total 6495
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 92U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 13 of 33
    // Exploration cases: 0
    // Structural maximin 530 / 674; family total 6470
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeyRotateASalts = {
    {
        {
            0xE26783F16F1EE3E4ULL, 0xFB276FBCFC290EBAULL, 0xD5B87D8A02DE75C9ULL, 0x8D87F188D51514A2ULL, 
            0x262557B7F50F1002ULL, 0x897BB3120F747F13ULL, 0xD574A9E34A697721ULL, 0x37A32C801650CCFEULL, 
            0xDA81594AD2528DB2ULL, 0x256AD5A33EAF9B03ULL, 0xA0C97593B770EF2FULL, 0x17641066F048082DULL, 
            0xE615CF9489D1D49FULL, 0x22EEBBF109B595E9ULL, 0xE327300B8244BA1FULL, 0xA99F519B1EFC778EULL, 
            0xB2F7F44A42848032ULL, 0xC03414696520677FULL, 0xB13D323AA4B12DD9ULL, 0x68CFFF3ED1C9E204ULL, 
            0x7ED50458905C8E9DULL, 0x94ACDBE76B10CEB3ULL, 0xFCE9D74EC6E03E4DULL, 0x5F9EFD38932EEBDEULL, 
            0xB6491D29804DA03EULL, 0xAA74D5BBD67DD75EULL, 0xF99B07E4246892E2ULL, 0x59A2270FBF61AB0AULL, 
            0xCA61714DABA6B026ULL, 0x5BDEFAF46A828FA3ULL, 0xEAE516141419ECA8ULL, 0xB32A666D046A49E5ULL
        },
        {
            0xC1D176A4F2A03F15ULL, 0x1476FF00F54C8B0CULL, 0x6B412965366D6D90ULL, 0x09A07235CADEF799ULL, 
            0x68FB7008274DB312ULL, 0x648AA495EFBE5145ULL, 0x29766280EBCCB409ULL, 0x32CB9C1BEDB93ABAULL, 
            0xEBEA7E3AE61DA2C5ULL, 0x671DA8F83E2A175AULL, 0x9D8604AF7AEAF10EULL, 0x2C8CE4DF0D4FB2C1ULL, 
            0x35177C4C35272F5BULL, 0x6ABA872919400661ULL, 0xF4F58EAA63C6A8ECULL, 0x62ED889E2AD44EB2ULL, 
            0xA9B91D96B192BDE9ULL, 0x94E52FB0599CE42FULL, 0xEB2142B632F30A7AULL, 0x87C2073CFA4E469AULL, 
            0x82BB6D5FDAFF7DE8ULL, 0xAAB3CC57520FD80EULL, 0x1B31DF1F7BD321A7ULL, 0x2AC5EABBE569A396ULL, 
            0x47080007FCF93241ULL, 0x7F32B90FDB6EFAF5ULL, 0xC296BBE4932394DAULL, 0xB0D8C3A95B2922D7ULL, 
            0x0A53E144BFCF064DULL, 0x45CCD7D954769307ULL, 0xF91486D31C9E6CD0ULL, 0x600840A3BEA0FF09ULL
        },
        {
            0x0B54F73F4369A324ULL, 0xD6C10DE40207D21FULL, 0x80F2772742BF156AULL, 0xE8C12F028C16CAE9ULL, 
            0xE7EA3640C0B9A33CULL, 0xAC6553980B0EDFE0ULL, 0x4862F5177856E5D0ULL, 0x7A65888DA9428130ULL, 
            0xF7FA36D53BCC240BULL, 0x28593FDB658F6E43ULL, 0xF4D2ADF3E3925ED5ULL, 0xB469BFE0B146958FULL, 
            0x68328408E0210B3CULL, 0xF29D245064EFB032ULL, 0x7A4B69BAA7C6BE78ULL, 0x334F8DF423AC7F14ULL, 
            0x098A1DC8347BBCECULL, 0xFC33F3E2E0993A2AULL, 0x6D6518525A0AA54BULL, 0x409F7AAEDD159C05ULL, 
            0x54F167902FC0621AULL, 0x1FFA8E3AA0F5AF68ULL, 0xDE42165C8485F954ULL, 0xEECF939311D229FFULL, 
            0x0021E42C9620FDFBULL, 0xBBBABEACB8E41299ULL, 0x3EFEF4D44CE61403ULL, 0x70BBA91051A7794DULL, 
            0x623DECA42C2DA811ULL, 0xBC4CBD16C981761DULL, 0x59059166ED9D07DDULL, 0x316AACAC3EADCB76ULL
        },
        {
            0x2FB9C9595EC0052FULL, 0xB994747BF63A22B7ULL, 0x002D6795838A5DEBULL, 0xD266969FC225ED27ULL, 
            0x2B93912270623CB7ULL, 0x67CB84DD0CC56FA4ULL, 0x82D20AC5BBCCE7B7ULL, 0x6CB1E242FFDD5B61ULL, 
            0x863B838891123816ULL, 0x5550B9AA7B4DF168ULL, 0x50ED8C6FD0909DA2ULL, 0x3FF17DB0F56B2E59ULL, 
            0x73E2F3958DDA7316ULL, 0x7000C9EF16F08989ULL, 0xBB52D03991CC3922ULL, 0x44CAECEAD4D145FAULL, 
            0xD70C76F5DA489F4BULL, 0x9A0E2C214F30FD21ULL, 0xE40EDF263D3FAC0DULL, 0xD3B5E4BB431883AEULL, 
            0x73272A8AE99C28B5ULL, 0xF51F62AA958A0046ULL, 0x77BFA51C5D0AE55CULL, 0x4576D9CB74AC4A43ULL, 
            0xA2FB70E3ACC8474BULL, 0x840313E5CE18DFFEULL, 0x8A1DC6B313016D91ULL, 0x3B4B7AEE885C64DAULL, 
            0x65D2B58F9887037BULL, 0x6D5DA6DA3B2559EAULL, 0xDCFCE90F3528DC75ULL, 0x4786D545F49678E4ULL
        },
        {
            0x2E7BF477983DDE47ULL, 0xAD9376FB1AF7171CULL, 0xBDEA32B230773B59ULL, 0x5DBEA69E5131D0EBULL, 
            0xDCDDD3AD1C90FE01ULL, 0x61C9B37C912D89BCULL, 0xD43FE616E503D23CULL, 0x69D3F4640CF3E9D0ULL, 
            0x945F81B1C634A0FEULL, 0xA3A1F3BFEBBE6D01ULL, 0x6F5C602D13E04018ULL, 0xFB69780CE96E58D4ULL, 
            0x67A9519EC4F0F54DULL, 0x0447C651BF06F364ULL, 0xFC8AEF3402CE4181ULL, 0xF8AAB3EEE89D9796ULL, 
            0x509092E9DF8BD8F5ULL, 0x755A0A732BB7A4C2ULL, 0x7878BDD4B9C68B13ULL, 0x9713F409A757105EULL, 
            0x6F11101E4CA1E5C3ULL, 0xA53A4B4B3F875816ULL, 0x84FA1B00ADD354FBULL, 0xA63B1EFA3B34D92CULL, 
            0x353AE8FC6B95E12FULL, 0xAAF881BD81B36EE2ULL, 0x010447EC2A5A8D72ULL, 0x96BD4C1DB560C795ULL, 
            0xB20D2CBF21017B31ULL, 0x74FFDE7C8C5664E7ULL, 0xBFFAA6205D157081ULL, 0xF8447FE90D00E3C9ULL
        },
        {
            0x330C1D994CF1D995ULL, 0x3627F39FBDED918DULL, 0x83BC1E4302A5CC93ULL, 0xCFE31A9A44D52071ULL, 
            0x9680531D236BB93AULL, 0x1BA98E3F77600528ULL, 0x5BA0E3788B7F0BB1ULL, 0xE424FB5C074114F2ULL, 
            0x2FB85B536F67B488ULL, 0xB4A31DBA52DBC64CULL, 0x8CA74200CAEADBE1ULL, 0x9FEF1D6BD23AAF26ULL, 
            0x871272F8126C0465ULL, 0x161914EF6B9CD2D5ULL, 0xBDEE8B47A6B67C29ULL, 0x936AF2BB122ABBC6ULL, 
            0xACD56D439982EBF2ULL, 0xD3C27F7EBF9A4679ULL, 0x495171EC910459A9ULL, 0xA62958AD6FBA9600ULL, 
            0x2637262BE79F76B3ULL, 0x820361BA5EE6E67DULL, 0x9F8926C709577068ULL, 0xF85AAC29609AAABAULL, 
            0x100D18EE996368DBULL, 0xE0ACB5E6B9104CE4ULL, 0xACD0B21E4255AFA4ULL, 0x403B17714FA8053BULL, 
            0xF9283E620DEA4315ULL, 0x469776AC06BE06DAULL, 0xFE86F623DE919293ULL, 0xE126DF63EAAB3D85ULL
        }
    },
    {
        {
            0xC13154F639D19F7EULL, 0x718F55D4B9C11BA0ULL, 0x5D42A9C5C5C00713ULL, 0x77296DB891D6384FULL, 
            0xB9C8AD47FD6249BEULL, 0x4E3AEB530829AB1BULL, 0x249589DD466CA576ULL, 0x80073BEEB7524E1BULL, 
            0x47F19E16C6E7DFE7ULL, 0x1320B8B39A52477DULL, 0xDBC73E759243DED1ULL, 0x5277B1DD5B41E1BCULL, 
            0x70A9C91D7F49CEE6ULL, 0x94CF80A8F02A9DF6ULL, 0xB5482F2E6B96F32FULL, 0xFE04A752A88544CCULL, 
            0xAB5E6BD34ADA05B2ULL, 0xFFBC378FDB64AFC7ULL, 0x8EB464CD2E06220AULL, 0x930CEFE7D574D082ULL, 
            0x4A6976B04113A61DULL, 0xE22BECFFF3184500ULL, 0x1D0C3D51CE2CC322ULL, 0x669C89ED087A527EULL, 
            0xE2518B1A37D692D9ULL, 0x3C12A7670CB06737ULL, 0x1C5626EF646E79A7ULL, 0xF59C234B822BD9D9ULL, 
            0x38ABE43B8B412BD6ULL, 0xC7E7D8A77E9FED8EULL, 0xEC3AADB8A13A5C36ULL, 0xC1B66018C9145045ULL
        },
        {
            0xF1489F927203655EULL, 0x6AEBA598572E27CCULL, 0x3E70670CC75F234FULL, 0xCCB274E475241468ULL, 
            0x83CB048AFD8ED5F8ULL, 0x3180D43ED3947257ULL, 0x9B29E9C12CA8C43DULL, 0xCF4170CB8604C40BULL, 
            0xAB3C46CABBA1EC45ULL, 0x1784777728D9C577ULL, 0xF30ED446AFCCF96FULL, 0xF4E49D855AF49ACBULL, 
            0x717E0DA4B15EDB69ULL, 0xD61B233874536FAEULL, 0x0E2273F5E14FB061ULL, 0x3A4A253784D797ACULL, 
            0x1822FF25A9DE4590ULL, 0x6A3A223096FC1734ULL, 0x7B856B4DAC33ED6AULL, 0x993814D806D95385ULL, 
            0x8FD8862EE08BB8EBULL, 0x655333E370ABCF06ULL, 0x58BC7DC41CD83B0DULL, 0x1B4E0BD47D966709ULL, 
            0xFA562E58D56A2823ULL, 0xABFB61DF6F7286F5ULL, 0x999854BBFD17803EULL, 0x02A9AE7F3766AF44ULL, 
            0xF7682F007D08D798ULL, 0x2897AA1E6DA06426ULL, 0xD685B974D90604A6ULL, 0x7190366DEF024FC7ULL
        },
        {
            0x5064C25E34E977DBULL, 0x71DDEF8116A178DCULL, 0x1469FC22B9031EB6ULL, 0xCF307C81A989C7FEULL, 
            0xF28B4B6FBCEB048CULL, 0x6441FACC3D313911ULL, 0x6C0A0C3BA59D9B7AULL, 0x3D8174A404FDB462ULL, 
            0x638AB43310E77712ULL, 0x8F2146E27918E6B7ULL, 0xF450C0C2A69426A6ULL, 0xDEBE0FF0B046CB78ULL, 
            0x043A3A543D273086ULL, 0xE3486BDD9F8A6FCFULL, 0xB9C5ECD0E318D10BULL, 0x174F6B61CB70DBB4ULL, 
            0xF245A698FF7F0454ULL, 0x5B34B3B0EFC390A9ULL, 0xB46007769EA9CF53ULL, 0xC4134A812C251EBCULL, 
            0x4FB8DAF748981A1FULL, 0xC7F0C6081D4CD753ULL, 0xE6060D4504780CBBULL, 0xE94375B915E4D4A5ULL, 
            0x6CEF769B08361B9DULL, 0x71D9007102F157EEULL, 0x6411BB379C1CF9F0ULL, 0x7BAC8A43280514F0ULL, 
            0xE4DE8D5B4FD51ADAULL, 0x4B14E1BFA4D42302ULL, 0xA5DF826895B9FD01ULL, 0x46213A1764752FB4ULL
        },
        {
            0x27321E84337E91BEULL, 0x453FA0BF30917901ULL, 0x2B0589022576062BULL, 0xFABD7574E715A87BULL, 
            0x54949DFB767466C7ULL, 0x1D7E3D674EECC6F1ULL, 0x453FF7398207FC89ULL, 0x41386F4AEC853BBEULL, 
            0x6941A22115A89A85ULL, 0x7BDAC653CEF598AAULL, 0x053F51D79EF42D31ULL, 0xFC53D12594E386A2ULL, 
            0x358F4A384988DE9AULL, 0x0D6015CF4B61FB89ULL, 0xBAA66D0A128367FBULL, 0xF8C7A07DEB2C0550ULL, 
            0xF6958AF906A63E50ULL, 0x90F4D279DE96CABDULL, 0x41E9D639673A0D00ULL, 0xA11AD22FEE4891CDULL, 
            0x1D2BB04D01974686ULL, 0xADA0A3F7E2D0EC31ULL, 0x2D657A6A17411B9BULL, 0x8BC0C217282B7A7DULL, 
            0xF71959820B872F91ULL, 0xBEAF0547C4FA20F1ULL, 0xEBCEBB7A24F21047ULL, 0xF4EC9E9C5A429584ULL, 
            0x5E376EF57D8A1534ULL, 0x7BB2A7CA8DF47BDCULL, 0x1BFC5EAD32857CE9ULL, 0x3F1F989CC63E4D9CULL
        },
        {
            0xC3B13AF667B3AF76ULL, 0xBEA89B4F3D4723C9ULL, 0xAE459C56C0667F26ULL, 0xCB47041790D3CE8BULL, 
            0x04701F26DF20B8BCULL, 0x50DCB1B905E419B7ULL, 0x56FF31EA06A9A968ULL, 0x3C95B6CDC03D9B84ULL, 
            0xE004E68C338A96E9ULL, 0x133DC2BE0EBE568DULL, 0x5822A01C459ACB5AULL, 0x766ED509950E24D3ULL, 
            0x4EDC6B7C7CA65D1AULL, 0x389035EDB208BE2FULL, 0x7CB5EDA37C670473ULL, 0x11E8D8D20359F992ULL, 
            0xBA20E87504FA7690ULL, 0x44F3CF778EE4A451ULL, 0x322DFD1DBA659AF4ULL, 0x13909D8233551EBAULL, 
            0x0575BF5E0ED8C52FULL, 0xD0B5EDFDD133E298ULL, 0xCC53163C003118BEULL, 0x9C29900C658FEC32ULL, 
            0x8475C53668F68478ULL, 0x348B299526B8CB22ULL, 0x5459F82CAF713FB6ULL, 0xF62D04A99CB30B75ULL, 
            0xFC1FEE72DFC110F5ULL, 0x7647857FC7F6EA8BULL, 0xFE8620D01CDA64BDULL, 0xB75E17F4102DD46BULL
        },
        {
            0x85C1D59F719AE986ULL, 0x28B50F53C0643791ULL, 0x4588E537A02AA5B5ULL, 0xF91BA1CDEB8C658AULL, 
            0xACC1761DCBDE18D4ULL, 0x8AA2E83C8DB0160CULL, 0xD9E8052AA68B36D3ULL, 0x188B89A61F7CF1C9ULL, 
            0xFB72999B2593047FULL, 0x78CD4161D0BEDEB9ULL, 0x7CA3A94F2F47D63AULL, 0x5213CED3C09139C3ULL, 
            0x7E8854865451FAA0ULL, 0x361F5197CFA65C00ULL, 0x442EC9CDAB8BB143ULL, 0x67C3065824F7CF10ULL, 
            0xD95C522AD52A347DULL, 0x256BD8EE92D7A408ULL, 0xA67AC96A1EFB6A80ULL, 0x0548D43FEC8B9056ULL, 
            0x1324D3677DF8B6FCULL, 0x82A15A69D83762DEULL, 0x78D98530F372872FULL, 0x012F19520C21ED82ULL, 
            0x7AE2F0235B6473FDULL, 0x0D2E471DC254FBF0ULL, 0xA78C3D532E93E631ULL, 0xF4EAD09C97D574EFULL, 
            0xA27F44D70A7FC5CDULL, 0x766A712990FFFB7EULL, 0xE4B258BCD160382DULL, 0xBB55DB9568BD9575ULL
        }
    },
    {
        {
            0xA33FADFCBF02166EULL, 0x564CD2FF80B87EE9ULL, 0x4EAD8E2DCA7B7FC0ULL, 0x13D5C8AFDF7C9ADFULL, 
            0xAA7D825F3399548CULL, 0x0754E10A8916B73EULL, 0xDE55DFFA03E9B897ULL, 0x429BA556E2011D34ULL, 
            0x93AFFD07370C1432ULL, 0x02C04D0266B2CBB1ULL, 0x32DEC4242618D2F5ULL, 0x2F229F725D7CD360ULL, 
            0x2B02B73F4E65B2E7ULL, 0x94FAB017E0AA6A3CULL, 0xF6881CF91F46E212ULL, 0x058E1274C8852D8BULL, 
            0xC1564646DFA71F34ULL, 0x1B020580AEAC5428ULL, 0x8A85481DC0C2C398ULL, 0x36A610EB3D4D728FULL, 
            0xE25855A9B7BD6EB1ULL, 0x84779600FE1C505FULL, 0x635475CC2EEB23F0ULL, 0x58CC94D0B5779B89ULL, 
            0x7BA6CFA9CDD2B5F3ULL, 0x657E3464326AAFDBULL, 0x7BD92380505871ABULL, 0xDA9FAD6E70EF8DE5ULL, 
            0x6173D3C59C699201ULL, 0x348AD5BC5FA6B177ULL, 0x854EB5C675FC7F48ULL, 0x554A4FFF9717DE04ULL
        },
        {
            0xC6E91FC1252CB2E1ULL, 0x32387D8C90513A12ULL, 0x11B030AAE33E453CULL, 0x020D2671EF36A180ULL, 
            0xE46C7AE90B40E1A9ULL, 0xD9BAEC7CF6737049ULL, 0x412EEE7048EBB0E6ULL, 0xEC1CBAB98138B786ULL, 
            0x0AACB8176FF71A85ULL, 0x72BD75FCA6E74E6AULL, 0x5427D7624DF17CC5ULL, 0xFF8CC6BBC5FB808CULL, 
            0xF9D59920C3AB4EC9ULL, 0xB9FA6662D83A4E47ULL, 0x63764815442DF6BCULL, 0x2010BB51DF7CEC52ULL, 
            0xDF1FB53E00E8E03FULL, 0x6C9ADB18F6F7BFA1ULL, 0x9371FDC314164F61ULL, 0xED62B24B4A18DABFULL, 
            0x50807E3610CAEC49ULL, 0x00A83BF409532904ULL, 0xC4CE3E24E1343749ULL, 0x312A6621144103BBULL, 
            0x91BC1CAE36F03ECEULL, 0xF6C28857FE5869A4ULL, 0x8E9CA70D502EBF18ULL, 0xE90395AB85B6F71DULL, 
            0x36EBC29D8F708DB1ULL, 0x7E60E9C87971EEB5ULL, 0x8495000B8029118AULL, 0x6D5C2A61D3A7EB08ULL
        },
        {
            0xD2FD13194E9C503FULL, 0xFE51607321596202ULL, 0x4697B1370CC9CF06ULL, 0x65A266D70A68E189ULL, 
            0xCE23E685DB428643ULL, 0xAB0AF957E5718237ULL, 0x48C905F3613CB2ACULL, 0xA52F8E01C280C3B8ULL, 
            0x11EF6C49F5C27D57ULL, 0x54AFF73475040CA3ULL, 0x0D1E27137CB12893ULL, 0xD1105FCE15C8C614ULL, 
            0x635F1CBDCC446EFFULL, 0x054F29B529C95B0BULL, 0xCED28A5CDC86A0F0ULL, 0xFCAA4DE79DCA81D0ULL, 
            0xF6F1A15156A79858ULL, 0xA98275CAEFC071E7ULL, 0xA1D525095C8022C5ULL, 0x615CE6F8C2F40F3FULL, 
            0x44574BC77527AD67ULL, 0x2BCFBD8F9C084532ULL, 0x5B35EC79DAB8E560ULL, 0x1A032991A9A02421ULL, 
            0xEEBAE65BD649AD73ULL, 0xB31E6AE861F047B4ULL, 0xD82EB0FFA1523090ULL, 0x50D75E5DB0E3FEC2ULL, 
            0x660281A710677613ULL, 0x70FBF701BAADE314ULL, 0x0EB815D618113DBBULL, 0x4A701A86F555E13AULL
        },
        {
            0x9B88DBF671CE238CULL, 0x06D6450A4DBB942EULL, 0x0B996E21A375AA90ULL, 0xEF6AEF474B878245ULL, 
            0x989B7E15A20DC0E9ULL, 0x375E2668E2629837ULL, 0xD5DEF468ED86B4EAULL, 0xEF64964D2F766410ULL, 
            0x1E108B9ADE298101ULL, 0x38F1FB1530CB67B1ULL, 0xC7BD67A4E0D7BFA5ULL, 0x5696BB03E7A38950ULL, 
            0x654C414B2757A925ULL, 0xA15273B8F6665EDAULL, 0x5CA6E188315FE1F7ULL, 0xD97B37D2A16D782DULL, 
            0x50D2191CB78C380BULL, 0xB8254B34DB9D7DD4ULL, 0xD620816724961B10ULL, 0x2990776489B28B04ULL, 
            0x64535BBDA1358C3BULL, 0x97DB8816EE13877CULL, 0x416A7361AA8DD2EAULL, 0x0DE202C21ACA26C3ULL, 
            0x072F2BBC165659C9ULL, 0x3E92B0669A5D09E7ULL, 0x3DB0B8CC265E1E82ULL, 0xD29955C61CE84097ULL, 
            0x5CD8CCA2E88E144CULL, 0x2860018C94D7DB99ULL, 0xF332DD552C79B95DULL, 0x01FDB89B82B8783EULL
        },
        {
            0x36C31E6FC3241BF6ULL, 0x98B24AB46A034548ULL, 0xF18A59CDC3C59A04ULL, 0x269D5B12F9FD1E92ULL, 
            0xB5B618C382287E5DULL, 0xF886BECDF4AC480FULL, 0xCE0CAC9358FB340BULL, 0x1C234EE86179D9A8ULL, 
            0x4C01DE34A047AA3CULL, 0xB177732B56915018ULL, 0xD9B68D03EDC01E86ULL, 0x7937B23A3FF19AE5ULL, 
            0x7FB7AF6693B17CADULL, 0x9717863B53DBE086ULL, 0xB94EF37118AC10A5ULL, 0xA5817E93C9ED0869ULL, 
            0x7FDFF17F699A361BULL, 0x4EC1E0F8237150EEULL, 0x6F6A7107A5F9FCBDULL, 0x80B676521B9F1004ULL, 
            0x17FEF079C6526932ULL, 0x865EF89F0906A546ULL, 0x154AED9D369A9761ULL, 0x3C1D07B9FB5F8844ULL, 
            0xA8E2014B019B4640ULL, 0xC4DA6CC0141E5E2DULL, 0xF71A4F9E7574B01FULL, 0xAA8B0AA5CF18CA2DULL, 
            0x7016D250A9D9BD5BULL, 0xDE03BF44F154F866ULL, 0xD9EBFD5B108730A5ULL, 0x4A0B45D2772EE83AULL
        },
        {
            0xB73C3205F277DA02ULL, 0x362F24EDCE23D106ULL, 0x03870112A3F4FA21ULL, 0xC6D597B8AE640E40ULL, 
            0x21079C3E98A62BABULL, 0xCF992699C3DE4923ULL, 0xA59842747E7D6B9FULL, 0xD0BADB3B409D8A20ULL, 
            0x5C013024D05095F9ULL, 0x4362F7DC060562B1ULL, 0xD922F782227D0DA3ULL, 0x67C353D0EEFCCAA0ULL, 
            0x0311BA872F4BB35FULL, 0xBFFFBC6F7B547288ULL, 0x308E59614E4F1765ULL, 0x24D047CEB1EAAA9EULL, 
            0xD4938DA6A4510A51ULL, 0x484CF3A266BC3A63ULL, 0x8BEDD77885D63F94ULL, 0xD6B906CCA77F6FB9ULL, 
            0x1C68F42B4D910D91ULL, 0x9EF04AEAE83C6D4AULL, 0xD4C4881CCFC48C69ULL, 0xDD67AF1CCEA34C0EULL, 
            0xB60FF9670FEC6F14ULL, 0xDAE358A8C03F4AC5ULL, 0x0FC11BDC555EB308ULL, 0x6202B147FA8CD2C5ULL, 
            0x4D961DA2DB457D52ULL, 0x2B48059377C14ACBULL, 0xF9C91782A7DAAAE3ULL, 0x533FFDE0B2045611ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeyRotateAConstants = {
    0x9E62E7CCE767C086ULL,
    0x0CE2F0858C0934C8ULL,
    0x88822991CA733361ULL,
    0x9E62E7CCE767C086ULL,
    0x0CE2F0858C0934C8ULL,
    0x88822991CA733361ULL,
    0x8CBA1D923F884BBAULL,
    0x6947D7B40560128FULL,
    0xDA,
    0x9D,
    0x3F,
    0x96,
    0x11,
    0xAF,
    0x1A,
    0x87
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeyRotateBSalts = {
    {
        {
            0xDC77B00CBF0A84B2ULL, 0xBF8ABF34052444A5ULL, 0xCAE24DB50897DF4EULL, 0x715BEF2FF9781889ULL, 
            0x75996A64964B54BCULL, 0x76D6435A49AEDE2BULL, 0xCCB78D203387F002ULL, 0xCD4E3196035EFCF6ULL, 
            0x670AE02627169D46ULL, 0x79DE5F60FC470D53ULL, 0x94A8C0A742AD7B74ULL, 0x8DE734409CD719CAULL, 
            0xE2D556E011906779ULL, 0xF25B3BDC9A621F7FULL, 0x4AED41B01CA2BE2DULL, 0x46A20EA18A357DE4ULL, 
            0xC5FAE20B155934A6ULL, 0x6242F3990EEB1D96ULL, 0x5545B293C4CD977BULL, 0x6521C8C84411DF09ULL, 
            0x21803483408A7A00ULL, 0xF9861AE3FFE8BEBAULL, 0xD72CE1D8B9A96A74ULL, 0x9BCD0565D723057CULL, 
            0x747A40E7F6A5DCD8ULL, 0xCD96A68EC888ED08ULL, 0xE686FDF0DD9E8041ULL, 0x67D4944DA52AB226ULL, 
            0x3F8E85DB1CB05C2DULL, 0x142C70876BAC40D7ULL, 0xC9C5E92C2080D128ULL, 0xC2BF5EACF81D8E17ULL
        },
        {
            0x55A7DDB95F555FFAULL, 0x5C73D7FBE6F6D2DBULL, 0x4BCACE5D1D634513ULL, 0x30436210EFC6E7C6ULL, 
            0xE4556222FEAF86A8ULL, 0xAD9D80B1AA5AC6ADULL, 0x2EC6120CFA5DFFFFULL, 0x6E47E6671E1CF916ULL, 
            0x8F651EF77C4E2E86ULL, 0x331C1A838E604794ULL, 0x28607C9322AC5EBFULL, 0xCA186220B771DAA4ULL, 
            0x3283ED65C7BE648FULL, 0x42984AFD78A939EDULL, 0x114F5E070F5908DEULL, 0x49D14ABAD16EC772ULL, 
            0x4AC67DF200D0659DULL, 0x7E73BAB40B6FA900ULL, 0x6E6E6E6849F0EC51ULL, 0xF3E8DA9B9B281497ULL, 
            0x286C6950C80D22DDULL, 0xF8133B94CEEAD54DULL, 0xFB6F08F4302CD62EULL, 0x0AAB0642E070DF72ULL, 
            0x9BFD11C0ED0AB6C8ULL, 0x8EA6CAB4C61520BEULL, 0xE3F3530F0EF45B26ULL, 0x634A69B65129EEBEULL, 
            0xDEEF1CF6A3B0D412ULL, 0xC3C901E4B77B3D9EULL, 0x991DDAA8587510E6ULL, 0xE6DE3B490D65A5ADULL
        },
        {
            0xA71567DF2238486EULL, 0x5C3EEEB7BF434859ULL, 0x6C1890F2D2742A4BULL, 0xC0AEEC5AA83CEE01ULL, 
            0xAE1EB9FFCAD87D18ULL, 0x77471DD9D192E5DEULL, 0x09B09B32AF220EB2ULL, 0x8A55EB16889FC3E0ULL, 
            0xCE2A88BCCB6BE665ULL, 0x417C569165A9FCB8ULL, 0x673C478D14CD2029ULL, 0xB0D1809CD2642BE2ULL, 
            0x6717C7B5D5B8C542ULL, 0x9108D0BD616E14DCULL, 0x7EFE32E23301CAA9ULL, 0xB6DE2E44E49109B2ULL, 
            0xB590516A52A3C146ULL, 0x65FF73D48B1A8C11ULL, 0x2845CFC4401B54EAULL, 0xAA1BDB1671BA1C8BULL, 
            0xD3E438274A330636ULL, 0x0109522381758201ULL, 0x4DC380134433DEC4ULL, 0x7F90B5DF2FD3401BULL, 
            0x311B06E4C56FB6BBULL, 0x72C5D17374A24137ULL, 0x5FEF1F49ED78628BULL, 0xB280BBC1F715A718ULL, 
            0xCA74EADAEB9E1A63ULL, 0x5642E3819AF7BC1EULL, 0xE0AC27FEC1B87940ULL, 0xFA4DFF128CDE7537ULL
        },
        {
            0x7D6C814879993DD6ULL, 0x9E0E6C8A7B224A8EULL, 0xCA781F0E454804A9ULL, 0x4A0FAC72539426DCULL, 
            0xE9C4458884F3A15AULL, 0xEA593D008E921484ULL, 0x2864EA0E6CACE0E4ULL, 0xCDA47297DC283BF1ULL, 
            0xB57D21C04DE6862EULL, 0xBC4AC2E4AD9F8D95ULL, 0x1732893F0F4D0370ULL, 0x6BEA6A8A3F289571ULL, 
            0x54FDEA12B36E5427ULL, 0xB640FEA49C836402ULL, 0x6482669A14FE0535ULL, 0x24DC24040E24E781ULL, 
            0x56711EB693EE579DULL, 0x16DBF1136EAC5D1EULL, 0x8EC7AD838C231F52ULL, 0xF0582609FBA6A26AULL, 
            0xBF8466C2B24D51DCULL, 0xC357D0249183BE7DULL, 0x726FC7579F92D572ULL, 0xFFDD800414B5BD12ULL, 
            0x22961406DEFD9CAFULL, 0xBE16C973278B1257ULL, 0x188797A00874D4E2ULL, 0xB0128018BC95CC07ULL, 
            0x7500BF73AA4DD042ULL, 0xA3109E82C4B1B4F7ULL, 0x13801F7A5498FD41ULL, 0xDF44FAFEC52FF77FULL
        },
        {
            0x5F0242BEC6DFA40CULL, 0x30408E8EDD310592ULL, 0x149F8462678F7933ULL, 0xD68036603A857179ULL, 
            0x555C6ED6C4F5F08CULL, 0x3BD371234ACEC90FULL, 0xA256614DF5A81AC6ULL, 0xE3524CC88202717DULL, 
            0x18F336CF50A81F90ULL, 0x18B076CAFC52E417ULL, 0x7B5BFF3B7FCDF800ULL, 0xDF16EA539A275870ULL, 
            0x56114A5D93E8B6EAULL, 0xFDD464BB5E818AA0ULL, 0xD3436446F2B8EED5ULL, 0x04473A9F18942BCEULL, 
            0x19DEF361F78E3689ULL, 0xF77049FF5515B588ULL, 0x88C1B9BD3A74565CULL, 0x93D2A0C7B41FF578ULL, 
            0xABD3064D3FBB12BAULL, 0x737FFDB7FB4F3634ULL, 0xEC7338881BE8738CULL, 0x9862FC034240DDE8ULL, 
            0xA9163262FD5645F8ULL, 0x900497AB32279F02ULL, 0xC1670BFFB06A8517ULL, 0x17DF4122DB97F2D2ULL, 
            0x2136BBEF2930DADEULL, 0x941F1013245A37C3ULL, 0x290FBEF5C58A9D4AULL, 0xB8294C8BF5E765A7ULL
        },
        {
            0x09AE9DF571AE648BULL, 0x2B5BC6F0B6F8F0E5ULL, 0x7788196C04C9C108ULL, 0x764EC13F7B1E9D64ULL, 
            0x8D7BD4141A9D4F06ULL, 0x33F26DB7A07C0BCDULL, 0x798AE572FB1F4056ULL, 0xDB38AC920F7AA723ULL, 
            0x6D3ADD5651441AEFULL, 0x8CD3793221EB7404ULL, 0x94DA265066584CA1ULL, 0xB927BA9232087933ULL, 
            0x6B36A299007A70D1ULL, 0x86AA27701C99352FULL, 0xA4BE8E88F910CED7ULL, 0x7758565C22F6E5DBULL, 
            0x2D12AC201D201B6EULL, 0xFEF61F23394C58FFULL, 0xA7F9EE2D0F2D6E02ULL, 0xB4B26354EB74532CULL, 
            0xE55B65331F2ABCD6ULL, 0x274856DF3341F84DULL, 0xF4B6FD2275668C5FULL, 0x993BCA88433D242DULL, 
            0x1FF3D86E24008B71ULL, 0xF7E0D679CD0098BBULL, 0x201593656E1AF0F6ULL, 0x5A1F8A712DB7E4ACULL, 
            0x116BADAD437E6A9FULL, 0x08C2A8ED50F15E44ULL, 0xB50667359DB6E726ULL, 0xE8C14791DB9B347BULL
        }
    },
    {
        {
            0x5AF7B8CE091FDF5BULL, 0x0F47E829ED527C84ULL, 0x911CBC3194C0EEFFULL, 0x73E3B5B700B88D79ULL, 
            0x0C1F09825EA5DD40ULL, 0x6D00934A8A0F7056ULL, 0xB7DC0DC4F6DEC5D2ULL, 0x6A48006F8F598CB7ULL, 
            0x1106943474E4963EULL, 0x695FD7F46F394178ULL, 0x8BBF8CB27E18B646ULL, 0x7377DAE7B3A5A4B1ULL, 
            0x5B2E8FB501E5E4D8ULL, 0x40C3E493473679D6ULL, 0xD45E596A0E36DD50ULL, 0x30430E74CE9146B0ULL, 
            0x443F365934D3AE6CULL, 0xF593C87B82F4B2F6ULL, 0x7AE574A15B597767ULL, 0x625A1FE62803D01CULL, 
            0x10775754E02CA792ULL, 0x349DF20113621C7CULL, 0x580AD423E9684823ULL, 0x3C5E1633CAAA4B7EULL, 
            0xAC56189C2D33322BULL, 0x58EB7798554FDBA9ULL, 0x3F85E2E637B9028CULL, 0x3EF24A3C52383756ULL, 
            0x776D53B11142B10CULL, 0x7666077C6D2CBB58ULL, 0xABFB5E926BB1D7C6ULL, 0x6873F3171D6F81DFULL
        },
        {
            0xF1974F6F6A2CC2D9ULL, 0xBAC09F1C1FF24607ULL, 0xE658FFE57D7E6D44ULL, 0x65C95ADC03F358DAULL, 
            0x51D377430A99C081ULL, 0x07A9F53520C00B9BULL, 0x03753168E0A60D50ULL, 0x0D841F587BA5898AULL, 
            0x576E856BF7E9AFA7ULL, 0x617C2C368888609DULL, 0x1910211EFFC94428ULL, 0x9DDEEB469C248079ULL, 
            0xA54201103364107CULL, 0x32B63915DD8A4667ULL, 0xDB73DC7141CCF725ULL, 0x08B22B54ADDF5D29ULL, 
            0xF5BBE72E67940052ULL, 0xBE94AF1ADBA7A183ULL, 0xC180A297110B313BULL, 0x178999159FB1990BULL, 
            0x96BF7BA9EF6EB363ULL, 0xBAF28BCE1E3EC541ULL, 0x018D032B465B2685ULL, 0xF87723C4058FFC0FULL, 
            0xFBFE4075E265B0DDULL, 0xE7BCA5EC12831DD0ULL, 0x8C5C63C010CB322BULL, 0x5060FF002A7A01CEULL, 
            0xE845A2D88D63C4DCULL, 0x85D6972802B65B8CULL, 0xF261ADB028DAE8F0ULL, 0x5D961979F09E919EULL
        },
        {
            0x186B0B2D42AFC96EULL, 0x34801D3E557E757DULL, 0x875FF0F2F6E74C81ULL, 0x9CBB05FAA22A3D7BULL, 
            0x8C9F0A2FCCB11AD8ULL, 0x46C1474F28B67F20ULL, 0xF7E1A89C9F115542ULL, 0x514203956AC57B72ULL, 
            0xE892365996DB362FULL, 0x01B888B3FF25D070ULL, 0xE6683B51CAB574EAULL, 0x09F618ED08B98747ULL, 
            0x842E4C09E1B22606ULL, 0x66D409891EF4D2F4ULL, 0xC2C0C34E93ED7197ULL, 0xBDAC2D02B206C3FCULL, 
            0x8CB0D4396D6E4D54ULL, 0xDDD26D555FFEC082ULL, 0x3A64274B1110E52EULL, 0xB54E8B7859C484B2ULL, 
            0xC48D4BF34477596BULL, 0xD599DC2EE9D8502FULL, 0x2063BA697523DBDDULL, 0x9EED315BC5CA3DB0ULL, 
            0x3022C0E2CA3DD8ADULL, 0xBAEE4A3B89B3DE6DULL, 0x5F6AF5E5AC545B59ULL, 0x2C1AAAF0F0FEC39EULL, 
            0x4ED6DFE78D90C918ULL, 0x737D971B0D24FC2BULL, 0xC91FFF60B3881C24ULL, 0x532FB8959EA25CBDULL
        },
        {
            0xCB205C57E236FB20ULL, 0xC71773959BC1F2CCULL, 0x2AB56E35F37D6690ULL, 0xB621696DE18CE5BAULL, 
            0x28A961CC7157D3E6ULL, 0xFE6B92EB19552554ULL, 0x97C35E87054AA819ULL, 0xA7CAFDEAF28C7144ULL, 
            0xF146F863BD78A4EDULL, 0x1E9CB29E6028CAA2ULL, 0x13AA6D02BBC34B3DULL, 0x746AD34644BB26AAULL, 
            0x5B037B1D4A424716ULL, 0x6C5D0548C6745934ULL, 0xB4D4020040A10CEAULL, 0x592D764819D8A96CULL, 
            0x25DC92D6C6C8B494ULL, 0x3E2C2056CB2092AAULL, 0x0E5D2093625DFE33ULL, 0x1D9FE75F73B8578EULL, 
            0x79DF33967D11DF60ULL, 0xF256A2FB371A6244ULL, 0x8F0C958326F0437BULL, 0x3B7598E67C75F026ULL, 
            0xD02D54051928A783ULL, 0xC24F011965E79CDCULL, 0xDBC691A02000FF61ULL, 0xF7CC16AD280365EDULL, 
            0x2695227B531831B7ULL, 0x1B5D3B9762DB8C7EULL, 0x52DC08D2A9A50836ULL, 0xF5DD961786230048ULL
        },
        {
            0xFFE93748CDC53698ULL, 0xA93FFB85627CCBC1ULL, 0xD4E69909BE1E5B6FULL, 0xD78B6D84C3F7DAD5ULL, 
            0x092C05594FA85EE1ULL, 0xFC44A686064CAFADULL, 0xAE4099E6E7FFD55EULL, 0xB34C118D1AF75AA7ULL, 
            0x9CE0C19061722245ULL, 0xEB768EFAEFE1B655ULL, 0x86492605ADD65309ULL, 0x8066CEEB46E62189ULL, 
            0x1C91D3808014DB45ULL, 0xB043EDB0977E5FDAULL, 0x053CA437DB517A76ULL, 0x9AED4442FB6ECC5AULL, 
            0xF11206ED9D55CC2DULL, 0x8EB79E93A5F15847ULL, 0x3445B465CC957DDEULL, 0x3CE36AE885D43282ULL, 
            0x437637B86639095FULL, 0xC8282ADEE58BB4EDULL, 0xA65763717609A2C4ULL, 0xB35460BEB76D0CD4ULL, 
            0x3133F920BAB4A783ULL, 0x4B7A518D72BBF410ULL, 0x15023E34F4352A83ULL, 0x997B9D658D5EDFE2ULL, 
            0xB5C72715888208CAULL, 0x7E1CA310FC4A2C84ULL, 0xC4D835A23A204209ULL, 0xB70996A4E3B28F0DULL
        },
        {
            0x7F3FA97CDA3669BDULL, 0xFE0C7B8A893823B5ULL, 0xF8CDD93459D92121ULL, 0x4A9F6E03FEA2C0F2ULL, 
            0x2CBA32C2FDA9A730ULL, 0xC400154EC4B78B43ULL, 0x5AC185A64EAEA2C0ULL, 0x62C63E18D8E867D7ULL, 
            0x3AD40561D1898980ULL, 0x3C536D279614BCE6ULL, 0x8933892D6147099DULL, 0x8346517DE159E1B6ULL, 
            0x94F4702ECDC64117ULL, 0xF770637439519FE8ULL, 0xDAC163B3FEE2EF98ULL, 0xFB81FE7DE0B069B1ULL, 
            0xC24971C04EF82175ULL, 0x49C5A92FA9410AC4ULL, 0x07DCB5FD1844FDADULL, 0x5EB977BFE8B1A04DULL, 
            0x719E3C392E438A5AULL, 0x68ADA2AB5FE04C61ULL, 0x9E7D5A1DD1E4356CULL, 0xF3F2A7F3BA622477ULL, 
            0xB3EB7DAC4D506DCAULL, 0x1CFBC70FCBCD1777ULL, 0xD1F72A7576A07B0BULL, 0x10E654F144E6C845ULL, 
            0x74EE03EEB76382AAULL, 0xC3F4A505720C40BAULL, 0x266479336C5928A0ULL, 0x1D27264D95F2DB33ULL
        }
    },
    {
        {
            0xFA60DF0DDE2DB58FULL, 0x30966F5567A56AE9ULL, 0x5AC3C0E12AD4AF19ULL, 0x602DF2D6682B2DEEULL, 
            0xB3657AACAC6BB117ULL, 0xC10DA0710E51208CULL, 0x9F0380CD9443F4A0ULL, 0xD51D034857FABCABULL, 
            0x9A3A00E6CD3DE214ULL, 0xA6E7D0CBFED300E8ULL, 0x5EC1FDAA4ADB149BULL, 0x41C1F5BBFA2C76C4ULL, 
            0x1D9A718EDD05899CULL, 0xF07644CA3A753882ULL, 0x975EDD97864706F4ULL, 0x6C1A9E44A8877037ULL, 
            0x49131CDF1B137D05ULL, 0x919E79EC029C37AFULL, 0xFD8CD6681004E04DULL, 0xC720D8C79DFBD0B7ULL, 
            0x360A06C681BE8A45ULL, 0x1F169A37F18F453BULL, 0x4623DE750D6E23E2ULL, 0x36D52C6BFF4C0E6BULL, 
            0x3D211192ABCEBFF9ULL, 0xB6FB226DB087C3D7ULL, 0x08AB4E8D6DE7ED5AULL, 0x7A3D8A7709274F0CULL, 
            0x27828BD3993E787AULL, 0x6A108E097D3E73D6ULL, 0x752A0F17D1A7DB58ULL, 0xF53E9175452C0F57ULL
        },
        {
            0x030673FC8CA1FC7FULL, 0xE8689E7E532B6E58ULL, 0x004F9AD660AB7FF2ULL, 0x6A685AC362E2702BULL, 
            0xE6C0E6270C776C82ULL, 0xE407F8EEECE68CABULL, 0x295C8450691B7388ULL, 0x4C5791073AC336DCULL, 
            0xF0481BF8C4F754A8ULL, 0xF6D65B6264AE05B9ULL, 0x4063190EDB26D432ULL, 0xF5E025D5B4B15C25ULL, 
            0x4098828670EED264ULL, 0xB0B412E3FE55CCABULL, 0x18F08DDA2F66E89DULL, 0xEEF30F6EB973EC75ULL, 
            0x102E187ED6DA2F69ULL, 0x469FDC40B6B4E83CULL, 0x960833DDB044B941ULL, 0x8C3203A4E46B2F77ULL, 
            0xD39CAE120E40CC74ULL, 0xAFE97E81E0CAAC59ULL, 0x9AC3874BAD5D0028ULL, 0x20548F18993ADC7FULL, 
            0x8A2015F11E7FF575ULL, 0x1041BB23DF92037BULL, 0xC4D3978E05227253ULL, 0xECC8C9E5DC9F11A6ULL, 
            0x84E54EC98ED7529AULL, 0xDF355D9FF5D5D0E2ULL, 0x783F0281AEACBFD3ULL, 0x7D1969E5CAE61C23ULL
        },
        {
            0xCD24E1DDA4D9D13AULL, 0x138CDA67F9C81BD3ULL, 0xFE00D97437F9A546ULL, 0xCE9C23476478DCCFULL, 
            0xB6AAA14534AA816CULL, 0x72ADC38F0CAD1A42ULL, 0xA9443EE5C9B3A7C6ULL, 0x57977B6FD8D099F0ULL, 
            0x302C5020EAA9C0BEULL, 0x421888104B095C40ULL, 0x2DFEB11FCE2A02EDULL, 0x0DB2FA2D4C261DF1ULL, 
            0x32A4AB250A8D6A0BULL, 0xBFE4FD74811D7E76ULL, 0xCB87311D9C01B954ULL, 0xCA386DA7DEBF2B52ULL, 
            0xC722A7D5CA5AFE4EULL, 0xE4BC0BC1863FD9BBULL, 0x90796C56C0512AF6ULL, 0x4EF6765C186B3D18ULL, 
            0xA8BB7E0BC15754CFULL, 0x884CF9B16A4B08D8ULL, 0xC3FFFE934E01C9EBULL, 0x5D965B0AE7416F95ULL, 
            0x1139E34FEBE45EB6ULL, 0x181FC15D8063CF16ULL, 0x2AE3FA120F912117ULL, 0x372ADA59146BCE61ULL, 
            0xED5B2E7187616DCEULL, 0x765B51497D920538ULL, 0xCE9FC88573420EB3ULL, 0x226E5A8045F7EE7AULL
        },
        {
            0x9AD9460F6EA311B5ULL, 0x58BD4C10C6652AC0ULL, 0x49DFD2C2789DAAD6ULL, 0x3D6BD4F96B56FCD5ULL, 
            0x37D6B7090EEA8604ULL, 0x56505FF0A43F4409ULL, 0x2A19367A084ED453ULL, 0xE172956CFF2739C7ULL, 
            0x29484C6277E04561ULL, 0x7193148FBFB764F0ULL, 0x51782BEC6825B7F3ULL, 0x7A8148428F5DAC1FULL, 
            0x67B36C5D31DD36B8ULL, 0xD321188854D39D11ULL, 0x3CE4B0738E98B7AAULL, 0x761C66B5043CE6CEULL, 
            0xCA1FC7466417D4E3ULL, 0x508FFD0B592D86A8ULL, 0x947C0003F9241798ULL, 0xAD322AE3B62E6C78ULL, 
            0x4809233B578A11D3ULL, 0xACD844F488CBB820ULL, 0xD2C68E33AB40447BULL, 0x4D60661324A7CF2BULL, 
            0xF6B5EA7F45263421ULL, 0x4EF8C27ECFC2C68BULL, 0xDF9F6EC70E49727CULL, 0xE047BF6E90A62133ULL, 
            0x3003B5D721508C72ULL, 0xFBCF1A546250FE46ULL, 0x4AB2346BE9ADE252ULL, 0xB166550729A51491ULL
        },
        {
            0x98371CA8BA06F5C6ULL, 0x11824B06B0B76E86ULL, 0x62B5F2FDCD2BC861ULL, 0xB558D9C230EDB857ULL, 
            0x6C2DD6602AEFAE41ULL, 0x40060BA551562202ULL, 0xD3D5A5E191F3C1DDULL, 0x8DBF4429BC8FA86CULL, 
            0x74C9200A17D44C1DULL, 0x647C409FE00384B8ULL, 0xF168D16962717EB5ULL, 0xCB41EF718E4269A0ULL, 
            0xE2CB85D40D3DAF8DULL, 0x1116B0395AEF2410ULL, 0xF1882D7715787FA6ULL, 0x2242F93F72C03C8AULL, 
            0x5709169291FD1936ULL, 0x127BAE3E1BED4154ULL, 0xC2FE6636C8A80E59ULL, 0x92BC0F1E887C886CULL, 
            0x0F9281938F754275ULL, 0xB3418B0471631822ULL, 0x9434E751F40C2383ULL, 0x6B37651E74F9177DULL, 
            0xDB98FFC35E54251EULL, 0x0433B8658A077712ULL, 0x579310238B697722ULL, 0x8067AF2BEA5B3EBFULL, 
            0xEA34377D1EB07C24ULL, 0x18D81FD05E12F4B1ULL, 0xF0670B1AF3F6FA78ULL, 0x4A5F43C9ABBA71EEULL
        },
        {
            0x3E55328C58D07A97ULL, 0x7B54660006B0F7ECULL, 0xF2BA6CC56A2A6B87ULL, 0x825CE8BA66902423ULL, 
            0x7FE39508227A2DC7ULL, 0x0CD62766A0A3CB29ULL, 0xA9C2873FA619D0F5ULL, 0xBBD8DD6870A5BD15ULL, 
            0x51D594B373086829ULL, 0x17A9569EFFF19B03ULL, 0x53B214FC60FE0BC0ULL, 0xD4357678AB5FBE2CULL, 
            0x8C1C3082D04C8E97ULL, 0x1EA6F52BF2FD4B27ULL, 0xBA87A0ECCC9F49DBULL, 0x58F4AF84BD72348EULL, 
            0x4A9517244C09E3D9ULL, 0x083A72DB58F8A017ULL, 0x4DCC9D0F2847EDE1ULL, 0xE5274CB9E7B19E23ULL, 
            0x32B7C91A6A05D74AULL, 0x3445F2E540959303ULL, 0x4E7859A27AF9445BULL, 0xCD63AC4ED5D2AAE0ULL, 
            0x1ABCD2C94E99364FULL, 0xE28DBEEF1B71A136ULL, 0xBBAB399253E5D6D3ULL, 0xDD06186FE43490C5ULL, 
            0x9D9B72AB276278D6ULL, 0x8A2A1753F8EC3B8DULL, 0xE50FB296900D773AULL, 0x4063B5C194E6AEB2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeyRotateBConstants = {
    0x548B8D7705694819ULL,
    0xCCCF22A4C8E0E12FULL,
    0xD0DA970408CAAB20ULL,
    0x548B8D7705694819ULL,
    0xCCCF22A4C8E0E12FULL,
    0xD0DA970408CAAB20ULL,
    0xCC223E2C9A7227B2ULL,
    0xC69292895F7C8AD7ULL,
    0xE6,
    0x15,
    0xE3,
    0xA1,
    0x3E,
    0x1F,
    0x1F,
    0xD8
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeySpawnASalts = {
    {
        {
            0x7050C7BF6619B4EAULL, 0x8E0A7BB1FA4A47F2ULL, 0x0FFD3F80EFF127D0ULL, 0x19AFAE33134B7A4FULL, 
            0xCFF08F08FC64FD98ULL, 0xE01C8D1366607A5CULL, 0x64A9C1D70E0D600DULL, 0xB5693A285A3B0B36ULL, 
            0x4DA77DA7C58D5FE6ULL, 0x90089AFA7C25297AULL, 0xC08D88585F132E0DULL, 0x9B924896264FF81BULL, 
            0x396EE8AFAD0F487EULL, 0xF8C69122A5F91272ULL, 0x1184153BC6C7B132ULL, 0xCEF604DDA2AA94FCULL, 
            0x2D19C09879C4536FULL, 0xE581FFB49DF4C3D5ULL, 0x70FC0CB850CDA6DDULL, 0xD696038549CED9C2ULL, 
            0x0AD2E4CDD0BDFE9AULL, 0x7EDEB117E24E081CULL, 0x143FD2ECC83F612FULL, 0xEF41256EB66A3956ULL, 
            0xF96490E3CCEF442BULL, 0x9FEFB9BBCD6F86CFULL, 0x4D7BE9B6136E44DCULL, 0x406534CC28475256ULL, 
            0x6611AD24DA6C7258ULL, 0x5C79B977E029C179ULL, 0xCD08F5801DD865B6ULL, 0xB0C9AF4F682A29D5ULL
        },
        {
            0x933C6120EA27ADA0ULL, 0x5571115C0CE91CCEULL, 0x9AE298157F8640B7ULL, 0x1B625A6EE7FCEA3DULL, 
            0xCB3EDDCD09BECC8AULL, 0x886BC49DB241D698ULL, 0xE20C7CADD75C1E1CULL, 0xFFC6B204A5489CE9ULL, 
            0xBEA7103FC67707B5ULL, 0xC81CF24C0B4A3B4AULL, 0x7931A3C4769F6506ULL, 0x3ED61C22B40EC5E2ULL, 
            0x6537157D48679939ULL, 0xF30211F6BC2B0015ULL, 0xE193752C44F1DB60ULL, 0x124975D71938E1ACULL, 
            0x26FA7A9CE10D285EULL, 0xABEC626551B48D6FULL, 0xE2E155948942665DULL, 0x6A6176B5DF8DAB69ULL, 
            0x93DE5F0D29EF80CAULL, 0xE17CB8D71778CC52ULL, 0x08E1BE2F0BE8F910ULL, 0x6F7BD65C9C2EAD5DULL, 
            0x2CF9DA422359D838ULL, 0x11978D45E3653764ULL, 0x40EA816AB3D67660ULL, 0x7B537E43C0618EC7ULL, 
            0x662454E061A258E1ULL, 0x9AFE10A0AD696A19ULL, 0x3E094D6D4C6C7E4EULL, 0xB8328558D6478009ULL
        },
        {
            0xBE25C3F65E47F9C8ULL, 0xA929431F64AE3334ULL, 0x56201D39DE93D246ULL, 0x09275415BAF5C4F0ULL, 
            0xF5B3BE7A9B4A43F3ULL, 0x3C9C98EB0B0DFB5BULL, 0x78BAF39087803C51ULL, 0xD63961191A2FE5FFULL, 
            0x964A0A6911AEBBA1ULL, 0xF58283A81EC7628AULL, 0x901E35E89F1E9C87ULL, 0x372690F041763532ULL, 
            0x33179DC160F49D7FULL, 0xA1D0EA566FB5C607ULL, 0xA1BB6C8B29C0279CULL, 0xAAFE9999E708BAFCULL, 
            0x85E682BFD89C9811ULL, 0x9912A2ED8915C090ULL, 0x1045C5C375CD30E7ULL, 0x629CD6193078FA4BULL, 
            0x585AA8081DA68102ULL, 0x4283FB0023EA52E4ULL, 0xD88657C5ECC2A71CULL, 0xF8FF0D913E6F285FULL, 
            0x0E2DED6E911A84D7ULL, 0xEDECBACCF6C43991ULL, 0x6BEEBC2D036B179BULL, 0x6D723CB9431B401BULL, 
            0x4354E74AF863FC61ULL, 0xD613CAD3672527E1ULL, 0x69F19CD70EAA6582ULL, 0xC56041185350BFC4ULL
        },
        {
            0xD0467361D42F9E74ULL, 0xF5C2DEEEFA449D27ULL, 0xE59FF3EC699EE3ECULL, 0x3D993ACF0E675710ULL, 
            0x9C5B2EBBDB35F54FULL, 0x8CD9337D6462A41BULL, 0x984C3772444C4C92ULL, 0x453F97860BD04962ULL, 
            0xD3BD94F1C41263C3ULL, 0x66F6009033B49C98ULL, 0x580953ADE4C3E499ULL, 0x47CC4FFD3721DDA6ULL, 
            0xF3DF304BAC5BB540ULL, 0x87834CEB5DC5BE2DULL, 0x1D80F205A2A645CBULL, 0xC7E4DDC222AE73FAULL, 
            0x10DCE39ADB3E7C89ULL, 0x9C37256A38303EA7ULL, 0x4979CE9EFA9030B5ULL, 0x9D2AB45E1228F935ULL, 
            0x2B90DF6C6A3A21C1ULL, 0x5A333F57D3AEEE63ULL, 0xD476202B408463EAULL, 0x3027852FB6AA9451ULL, 
            0x53B06A31404A46F4ULL, 0x84700D41170786F3ULL, 0x770078DD3D397DD9ULL, 0x648887A2A0F1414BULL, 
            0x06637F629969FF8DULL, 0x09EB7CDFF19C25B6ULL, 0x402846F579A5000DULL, 0xC24246D6A3401942ULL
        },
        {
            0xA79FDFDE46E5D1EEULL, 0xC3BF7C018F5C19D3ULL, 0x3B4BAA18FE18FA95ULL, 0x0F40A0E975F149A1ULL, 
            0x5E1818110BCEA359ULL, 0x005A584363C2C1E2ULL, 0x87E02FB2BC8F6E26ULL, 0x0E15A593BDFABC09ULL, 
            0xDE59E25B666D7B78ULL, 0xBC72610D5C7837F5ULL, 0x50538A34429B94B7ULL, 0xB5AE33403B644B59ULL, 
            0xC726120787C4BAE9ULL, 0x9317D4FCA065F8E2ULL, 0x034E1311F203A391ULL, 0x02A4C703834B59E0ULL, 
            0x971D73AA398B3152ULL, 0xFFDB506B8EFB94D5ULL, 0xC3B098A21DB45CF8ULL, 0x85C7F46A2CF4E621ULL, 
            0x09B4B4C317FC489BULL, 0xB6995F4B901087C1ULL, 0xA3974634E461E6CAULL, 0x3DD2E5D734D95B65ULL, 
            0x6A053423E846601CULL, 0xCE84B1A7E5DBCB90ULL, 0x983005376873ABC4ULL, 0x27B36FA037F4AEECULL, 
            0xB9F71869618A83AAULL, 0x2546762382511088ULL, 0xBB3B076164A52EDEULL, 0x42DCEDE053EEAAEFULL
        },
        {
            0x718C7534527ECE0CULL, 0x1950B136316B5394ULL, 0x76294EBA78448379ULL, 0xF6EE56DAD644BE50ULL, 
            0x557083F5E89E8E35ULL, 0xD1F06328EE48CE59ULL, 0xFF152E4FB4825CD0ULL, 0x5DAD55B62A568333ULL, 
            0x5F432819EAA2811AULL, 0xB9370D97F5780078ULL, 0xE677F1A5D8B40131ULL, 0xA5F85055F3D36850ULL, 
            0xDF3EDDE7EC0B7AD8ULL, 0x8C2B2AC41560170FULL, 0x204F1AFF964B3381ULL, 0x6EC03E968B30CDBBULL, 
            0x5F670F592003549DULL, 0xF70FB109FAEACF89ULL, 0x9A2F163EEDBDA237ULL, 0x54079AA49FE7BB04ULL, 
            0x2BBC558DCA8F7AD7ULL, 0xFDA555E6FADB4241ULL, 0x8619F8E84BDE1204ULL, 0xDC6C9FAFBF40E90AULL, 
            0x48F0929AAC9C9325ULL, 0x5EE65579D0CE1948ULL, 0xC015C5EC4BEC9CDCULL, 0xA302E55B189F76E8ULL, 
            0xB56F058ADC37B6CBULL, 0x2FD541FE89CAFE50ULL, 0xA7BC98DFA4EFB11AULL, 0xCC0F6B7E6B16C488ULL
        }
    },
    {
        {
            0xDADBEE7DCA3C6829ULL, 0xF196D90B8DCD63FBULL, 0x133E4BFBE5E937FDULL, 0x8027497407B7E506ULL, 
            0x52619EA86DC5812AULL, 0xEF95362361A74126ULL, 0xBF90AABE5D31054FULL, 0x5FD277C83589CB45ULL, 
            0x87F354E8F27A40D6ULL, 0xCD522DFCE2FEBD38ULL, 0x6530BF371FEC9185ULL, 0xFA81B7E2DB153D7AULL, 
            0x7B9DF2632B1D6A49ULL, 0x881BC6A01CF429EAULL, 0x9A94E7501DC14FA7ULL, 0x1C00CBDBB1B314CEULL, 
            0x2A9E6A764A859191ULL, 0x9C578A6B42A6BC7CULL, 0x0577AA39BD13BA92ULL, 0xFA3CCF2FBBF9137DULL, 
            0xDD3A793CA95FCBF6ULL, 0xC28C6B953964106CULL, 0x8D8EBCFFD218A039ULL, 0x065820D205F03299ULL, 
            0x453E2A34EDF76128ULL, 0xB7B40D6AC002D287ULL, 0xCA40588F64B4C49AULL, 0xDAA1F22FEB151034ULL, 
            0x8B8DAA13DB16CAD3ULL, 0x535296CF6BA5DF00ULL, 0x023F553CE3703C70ULL, 0x989561891B68027AULL
        },
        {
            0x05092C30E8B530FEULL, 0x0BCFBF6E962E8F8CULL, 0xFC8395BF2B483B28ULL, 0x3AD5729D8741D78CULL, 
            0xAB1E53074317DF0DULL, 0xD49F33A7778B4A1CULL, 0xA5D87F7A14017C2AULL, 0xEDDFE6F071087DE6ULL, 
            0xF9BDD574278732CAULL, 0x10CD150F880D2C80ULL, 0x2BA9E6E3D29F1E67ULL, 0x9B2545414916F5E9ULL, 
            0x05E3CE3CACC9C658ULL, 0x15B137CCAA63F484ULL, 0x7BD01F6AE029EE7EULL, 0x6EAA7ACA453866F1ULL, 
            0xF373EA6BF95A5FE7ULL, 0xE1E0EC5705695EEAULL, 0x82554BC51BAAD459ULL, 0x5AF26D03B1B77293ULL, 
            0x6799154DE428CD2DULL, 0x88F81E0F22E71DB0ULL, 0x3F2D09B7366FD576ULL, 0x7009B3BFB059DCF8ULL, 
            0x516E61C9830CBEB9ULL, 0x3834895448580F1BULL, 0x5C69532B854935E4ULL, 0x0372D92FAA6772E5ULL, 
            0xE2D4B7FA64CA1EFBULL, 0x12870E7FE9779B31ULL, 0xCCD7CE996B098064ULL, 0x4305C28FC4068F76ULL
        },
        {
            0x4DD63668A029B3B5ULL, 0x26BE030E7BFE27FCULL, 0xA90B45C60246D5CEULL, 0x6237EED52A130F4DULL, 
            0x9D99EAF34341AF73ULL, 0xD837879574B4C1C5ULL, 0xD856C1D840AB0CBBULL, 0xCD6E76B84C8BD32BULL, 
            0x07895D07B8D2D732ULL, 0xC79E1B9189ACEA13ULL, 0xB87C09D582CC3904ULL, 0x3AF77CB4465ED8A5ULL, 
            0x5BBD937A3DE8C2C9ULL, 0x6B2D775342DC112DULL, 0x5A072CD78ED9D346ULL, 0x81CB1F03F32C7286ULL, 
            0x89A84E881389A1F6ULL, 0xC94A5DDA3EA6A56DULL, 0xA113E47D4A3BF6DAULL, 0xFAD484470C1BCA3DULL, 
            0x8D03BA5D86F34975ULL, 0x5DDE82CFCB967D01ULL, 0x327F895B9A0CAE91ULL, 0x7169041A6F358838ULL, 
            0x62BACBA63E830B11ULL, 0xED8ACE092FA9C514ULL, 0x88E9AE07F220122CULL, 0xD99FD52EA96400C3ULL, 
            0xAC000F5A4EDB5C83ULL, 0x7E20DEE6EF8B0BDCULL, 0xDF89EC2D85274841ULL, 0xA04C0E82C21F038BULL
        },
        {
            0xC23D15BA003984F6ULL, 0xF4C039FD4E36F1AAULL, 0xA81654BAD48E1F09ULL, 0xBD51D921C87C3332ULL, 
            0x263B1FCCBA3737C9ULL, 0xC16518D3E5B0F32BULL, 0x1C0AE6E27624A6EFULL, 0xBE4E7A5AA78D2D1AULL, 
            0xA23ED436D219B8EEULL, 0x63B376C4A33444EDULL, 0x064CB8D83AC56B5BULL, 0x7A1F4CDD623CD563ULL, 
            0x90AFC114C7010EE9ULL, 0xD0E3873EC7FF5D68ULL, 0x4010C90A454C57BEULL, 0x42CA860298A26D2FULL, 
            0xD11F8C46742C326FULL, 0xC81255082831BDE3ULL, 0x06B7BEB49D2D3D98ULL, 0x85AA96FFA93A9BC4ULL, 
            0x66D0D471A2224E9DULL, 0xA563E02C100C1D03ULL, 0x7F2B77BF2695829AULL, 0x7819248AF0C9836DULL, 
            0x4783B68CFE597145ULL, 0x64C0AAE95DC275BAULL, 0x1A86AD05C4383770ULL, 0x50AFD38C7DAB8E24ULL, 
            0x1F5E5FC7BC6C906DULL, 0x6056E165A255C2CFULL, 0xC7232FEEB3D1BAE7ULL, 0xA3110671351374E1ULL
        },
        {
            0xE8ED56591B204DE3ULL, 0xBF1FAAC012D92A9AULL, 0x06F799A1443C64C6ULL, 0xEA8632EE28294B0CULL, 
            0x4262F389AEF1D4EDULL, 0xFEDF6445D269B86AULL, 0x1D048AC76D239346ULL, 0x0B8D9298A62843DFULL, 
            0xFA40E412D8727499ULL, 0x97055EFE4F9D8E39ULL, 0xAD6F13E8F3531E08ULL, 0xC7238EB13CB35985ULL, 
            0xB66BB1EF4ABDA7F3ULL, 0xCAAFBE664603CC63ULL, 0xA556BE50E9A8014CULL, 0x90EEB8E546BC64D3ULL, 
            0x07B7B256BC800B0FULL, 0xA923595FEC359200ULL, 0xBAF0042F77A20455ULL, 0x324435F1A181E449ULL, 
            0x82DE95EC7B812950ULL, 0x773DC75E3D1766D6ULL, 0x87842BC0FF3DEEF2ULL, 0x815160E06D4DD350ULL, 
            0x67AD567B17D57BFDULL, 0x796519133D211B40ULL, 0xF09D5801AD18AEC1ULL, 0xB9AA2361F231DBCAULL, 
            0x3E2374D41381B54EULL, 0x067EF65E35377D9BULL, 0x80CA67651A5B9AA8ULL, 0x6A0B3ADD168D4A9FULL
        },
        {
            0x2385EE880B3FAC9EULL, 0xB9CD9D712AE75D63ULL, 0xE36C632FCE7BA498ULL, 0x5768D8BBD19BA2E6ULL, 
            0x097BFBFD0D69D7DCULL, 0xA9B8D9CED8388B20ULL, 0x9557D7BAA5CF983DULL, 0xD7E232C983BA7790ULL, 
            0x67B7901AD6DB38CEULL, 0x551DBB625A0A8AF8ULL, 0xBAD6C6E6CA0B0963ULL, 0x65B94812EF0C4F8BULL, 
            0x8F2258E5A0C6E345ULL, 0xEB09DAE45F3A17C1ULL, 0xC53C364D7060FCD9ULL, 0x911348ABAC09998BULL, 
            0x2EF8C9A3C2DFDD4FULL, 0x46C43C6E78699D2FULL, 0x6BAF089700018146ULL, 0x4D2F74B1BA5BDA7AULL, 
            0x12B3D36584D859F9ULL, 0xFC387321AD77C68EULL, 0xC271AF25DB47BE28ULL, 0x8F757FADA1413B8BULL, 
            0x4D8E1B736E391145ULL, 0x2988C08F8993EED3ULL, 0x13C65A074F4F0C4EULL, 0x429F1B6CE13F8D07ULL, 
            0x97905C5241F1A117ULL, 0x9605A63E087289F5ULL, 0x93619A35E90CD2FBULL, 0x43D7EA5C7F4BC8E5ULL
        }
    },
    {
        {
            0x6EDE40EBAB5FCC50ULL, 0x4120FA4E67034A51ULL, 0xC78B8E0060A2DE59ULL, 0xEDD85AE142845266ULL, 
            0xD37EBF65FA4EB33BULL, 0x17699F423C29E419ULL, 0xE339FBFD31D15B5FULL, 0x5CDFDB084B150BE4ULL, 
            0x4B41631C15064262ULL, 0xDDDD2BB4D255F422ULL, 0xAD27F11A336C0FCBULL, 0x4331336854C549BAULL, 
            0x59B22E039F895694ULL, 0x6C2B58499594142EULL, 0x648F758C3CA4F08AULL, 0x6E910E6CDA1AC1C0ULL, 
            0x1EB21327DBDC8A9AULL, 0xD4009DCF47D11B0FULL, 0xF8DDF3B78BF55F68ULL, 0x5BCE50D9D667EBFAULL, 
            0xC545C9E4963B1031ULL, 0x6CE70D53E2A1FEA6ULL, 0xE02B2E3A0FD8ED7EULL, 0xF678DA469C4E1AA7ULL, 
            0xF1223DED0931419FULL, 0xF2E08F86DAA79C8CULL, 0xD4CF3A46FB4E954AULL, 0x655EE53767341993ULL, 
            0x658F2D78848A901DULL, 0x063FB075FEAF0155ULL, 0xCE9F013199304B05ULL, 0x3A89C491D2693D36ULL
        },
        {
            0xC8A0AB46A495F4F4ULL, 0x5DDCDE624523689DULL, 0x3F3C9B036053B559ULL, 0x9EB4BBA57D5F37A3ULL, 
            0x54B29738BE467959ULL, 0x1789645292185A31ULL, 0x60A90438C42AF064ULL, 0x22AAC3F159D75B2BULL, 
            0xAA861CBEA9BCDD67ULL, 0x56E74CBC11C8D2AAULL, 0xCA459CA2EBE0B19CULL, 0x9E0AADA8635F4B1AULL, 
            0xA745D82BA326B7DEULL, 0x9596339F236E4CC8ULL, 0x258478EFF8C9EABFULL, 0xF2EF50813E5A7A3BULL, 
            0x4BED0FE19BD1824AULL, 0x6D7F8B10E1CA5D93ULL, 0x3BBF7DE28D7317C9ULL, 0x8A1EA834B3681492ULL, 
            0xE3AEF27270A5375FULL, 0x95A22209A1D912E9ULL, 0xBD84B2DD68CBF65CULL, 0x50633D8F5BDBAC59ULL, 
            0x0E5CBB1C469184F3ULL, 0xD920DF8A7B11CB94ULL, 0xE58189D6C0AAA8ACULL, 0xA1A82FE03D4C662BULL, 
            0xCB58ECA00049A84DULL, 0xEC1C3F203C1ABB42ULL, 0x64D98177F3BD2A64ULL, 0x7C2FB7DAA30FB187ULL
        },
        {
            0xE44F050C999D304BULL, 0x3B328A4D90A69170ULL, 0x383AF016567BA74DULL, 0x596CF97FF5C02EE4ULL, 
            0x9FA0C7D14863E3FDULL, 0xA99F0494E1EFC3B0ULL, 0x94E5111240A846D2ULL, 0xE204CC8021F64D17ULL, 
            0x56AF233E4053025DULL, 0x6715FF640A9C920DULL, 0xDD0F72FA0FD20D10ULL, 0x07387C20E3AB536EULL, 
            0x0C0889CF11F2F709ULL, 0x922785F8762080ADULL, 0x6712A097FD27BB17ULL, 0xE58E8665A338919FULL, 
            0xA77939AF0108331AULL, 0xE9A5D22FCB5493FDULL, 0x6F071D2D8CB58191ULL, 0x3440B27956955208ULL, 
            0x382EF1D1B9D4DBD7ULL, 0x52FECFDDA69F3C4EULL, 0xB1EF9E6A3E65BDC0ULL, 0x16482C52361BBBD0ULL, 
            0x2A436DDF84A31737ULL, 0x4A0A28C5F0306E2FULL, 0x7AD0DF790C0D46D5ULL, 0x54CA1F6D900CAA01ULL, 
            0xE43017595FD44A71ULL, 0x84713236BC8C915AULL, 0xC88FABFBECBA2B51ULL, 0x5E22D355F94AB6A7ULL
        },
        {
            0xBF82DB4E8FCE98ECULL, 0x0D8D9294AA4623C4ULL, 0x8271CD477AF18ECEULL, 0xAFACBDD0D1627FFDULL, 
            0xD00DAAD9A8B64D80ULL, 0x0EC18695AB0AC480ULL, 0xE282AE8C7879C7E8ULL, 0x30FEFB6E0AD538CDULL, 
            0x6FD657F7E3C6897FULL, 0xDD3D89F84E4CDBC6ULL, 0x025A43F0D77BFBA5ULL, 0xD32274B16C000610ULL, 
            0x129FE579CAADEF02ULL, 0xC87F311B718E2598ULL, 0xDF9456580029C566ULL, 0xA4C75CAD8A3744F7ULL, 
            0x16DEE7F55B82F30EULL, 0xB970A84EBD1F799DULL, 0x54E48303F9BB3A50ULL, 0xC8E82E299C1F478EULL, 
            0x3325A102CE7BA470ULL, 0x66B772B876B347A1ULL, 0x3278D4793B725F04ULL, 0x6041F0470378927CULL, 
            0x970580494D93EA7CULL, 0x4B0221F133B3BAD5ULL, 0xBEC470BE839A4039ULL, 0x5B2869EF4D159D53ULL, 
            0xE6FB8F7D4476A33CULL, 0x0970070204DC5C7AULL, 0x55FF4DA189B5EE94ULL, 0xF0449B5CE637F9FDULL
        },
        {
            0x9676F97160FD55E7ULL, 0x1D17EB89E9ECBC62ULL, 0xA824D7B8F98D96A7ULL, 0xADB179FEF64193C8ULL, 
            0xC6ACDAB468873F3BULL, 0x72753CDE5271E6CEULL, 0x9F788E15ADE79E85ULL, 0x303157AACE1B93F1ULL, 
            0x41C10FBAE58014ACULL, 0x526CA10584BA1F55ULL, 0xC0BF1362019DC8A7ULL, 0xDC8E4A3F18AD671EULL, 
            0x167C0EFD183D5C19ULL, 0xCFAD91C957DD2D20ULL, 0x8E5CE57438B893F2ULL, 0xE98437D7C0A9E9E2ULL, 
            0x6FFB73266D80772FULL, 0x4D6C8AD372405198ULL, 0xD20528256673898BULL, 0x197E6950EDEBF732ULL, 
            0x859B61F537921345ULL, 0x7580ACE47E8B0ABDULL, 0x9CF5B4788D06861FULL, 0xF090098ED32B16FCULL, 
            0xC7C61BA4EB84FF00ULL, 0xD27827495564BDF4ULL, 0xE44D021714C88F78ULL, 0x1E9269985E755157ULL, 
            0x29F06832161FFF15ULL, 0x72DF259A8BDE8B95ULL, 0xC10B907407F6FCB4ULL, 0x10D5A6FA45868F99ULL
        },
        {
            0xEE477FAD8A7A9AD3ULL, 0xEF9C91F64684B129ULL, 0xC056F266630FEF1CULL, 0xC88D822B3C064FCBULL, 
            0xB2212A44FC171843ULL, 0x550014AAD0784872ULL, 0x1B3E59AE90E6DC4CULL, 0xA8838B91F14C8105ULL, 
            0x69512E46D21DDC87ULL, 0xB20C20FA386AB228ULL, 0x5E91BD5E9B9E5C43ULL, 0x7C49B76622FB797BULL, 
            0x3B2C6F49E2124D39ULL, 0x327F6F8A4E431BBEULL, 0x67FD4F6DD8A77416ULL, 0xA3FAB537908A4EE9ULL, 
            0xEF0706FF863E66A2ULL, 0x7626055D80160296ULL, 0x2AF7F5BBDEC7578CULL, 0x01D5B59180838A56ULL, 
            0x3DC799D9E05FEDAAULL, 0x32AC8D842173F770ULL, 0xE7EDD4988D2F263CULL, 0x9CCE109E3279BFB9ULL, 
            0x17D870D95D517943ULL, 0x24CCD4CF8DEF5323ULL, 0x2811764BE4FBB350ULL, 0x237F1A1E3F332C60ULL, 
            0xEAC3E970DBAEF3E3ULL, 0xA725C4468B99E384ULL, 0xD078174EBA964486ULL, 0x565A16C9D42273CCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeySpawnAConstants = {
    0xE11AF252FA78705EULL,
    0x643BC13B09D1DEB5ULL,
    0x33D6F59CE17215F5ULL,
    0xE11AF252FA78705EULL,
    0x643BC13B09D1DEB5ULL,
    0x33D6F59CE17215F5ULL,
    0xD3E0BB1460E40564ULL,
    0xD5379D6C163CCE80ULL,
    0xCF,
    0x6F,
    0xF2,
    0x23,
    0xB6,
    0x24,
    0x66,
    0xF7
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeySpawnBSalts = {
    {
        {
            0x903BF113F31A7CEEULL, 0xA9EE046A36F62DE7ULL, 0x12ADF05384788240ULL, 0xDF7188ED03E3ED10ULL, 
            0xC49EF475992FF22AULL, 0x2979DFF3CEE8AE69ULL, 0x1F61D080F9DDD093ULL, 0x19F68D79036D5255ULL, 
            0x23764F58F7C81180ULL, 0xD1F980C655ABFD29ULL, 0x804659B0243F244FULL, 0xE61519EC87CE1B89ULL, 
            0x0A19D807063776B7ULL, 0x6BE05A6B4C4A8732ULL, 0xB904437210A4B7F3ULL, 0x87A2B906A5ED7DDCULL, 
            0xDCF6AC398CC24859ULL, 0x000E1D8D19365F07ULL, 0x65F480A4B1217B2AULL, 0xA1C6F60655E4875AULL, 
            0x0A869B2F502E5193ULL, 0x60563B401FB65C19ULL, 0x503AE8C96BB74D7AULL, 0x5759D9FFB9A5AE5BULL, 
            0xE17EC112EFFC0419ULL, 0x60E69F2E529744C1ULL, 0x87C4865331683EEAULL, 0x385D4BB9A7CF3584ULL, 
            0xF0E5E5B4A85E566EULL, 0x4692C1EF601920E9ULL, 0xB15BFFCCF0DC37BEULL, 0x4636E1E467874D85ULL
        },
        {
            0xDD9E4E03254C77CBULL, 0x427F127207F931D6ULL, 0x97453A9147CAE179ULL, 0xEAA04A8035621717ULL, 
            0xB1E6CC84C26A7E0DULL, 0x1AA4D231001BE0EFULL, 0x882D9325832134CFULL, 0x7C42F9AF99BB8054ULL, 
            0x51ED60FF4F08EBF0ULL, 0xCC3D62B00834FEA4ULL, 0xF05473E78FCB16D6ULL, 0xAEB47E872DC543E5ULL, 
            0xD53A00665A3CF97EULL, 0x6F9310C1651C1BBBULL, 0xBDFC17A3863C2FB6ULL, 0x9094C77E6A859E10ULL, 
            0xB6EBF02D2A074999ULL, 0x5EF885292CE111A4ULL, 0xBF624209BD883DF8ULL, 0x2CD0D851A168EF6EULL, 
            0x670E69C8F165E2ACULL, 0xB71E213D771394C0ULL, 0xECD86DCF6BE40B20ULL, 0xA003E7C606F606A8ULL, 
            0xDBE28471715CD96DULL, 0x8927C1D2C770243EULL, 0x5D6AAF92AD982D8DULL, 0x27CEE37148E73969ULL, 
            0x3D2CF905AEB78C2EULL, 0x3B317B7C121D5899ULL, 0xB1D7046517028911ULL, 0xB2214440FF0308BCULL
        },
        {
            0xE69FD46B669CEAEAULL, 0xCCFD4991CF7F8C04ULL, 0x2417EC835C2F803AULL, 0xBF24CC2A5B6317E8ULL, 
            0xA2D7821864897EE7ULL, 0xFAAA6499688F930BULL, 0x5E8F5002381386A5ULL, 0xC55ADEC8BB203CDBULL, 
            0x741CA1957AA913F2ULL, 0x78F16BD5DBAC968BULL, 0x05F99B229D1D85FBULL, 0x79A8AA15D5D58B84ULL, 
            0xD14EFA616853599CULL, 0xC62865215563B08CULL, 0x923F4CC20E97F679ULL, 0xED4C4EA3D05B6B05ULL, 
            0x8FA4378A1609F351ULL, 0x887C3A305794C31AULL, 0x60C6A9E4D4436F7EULL, 0x8A6CD03C9A771DAEULL, 
            0x0A769233F0EAD433ULL, 0xBDDCC3C52A64B204ULL, 0xE5FE68529E782EE4ULL, 0xB68A930D251E1E72ULL, 
            0x9FEA08C7F37FD0E6ULL, 0xA35911E8736148EEULL, 0xA81F4271ACA0E155ULL, 0x080DB65617779D26ULL, 
            0xE554221A4F6318DAULL, 0xA1F0EB673CABB72EULL, 0xF5519E02420FFA25ULL, 0x93F5CE6EBC336D11ULL
        },
        {
            0xB224341209CA7638ULL, 0xD88AF572A6383643ULL, 0xAEEFBD49AF084AE8ULL, 0x1C188208401A150BULL, 
            0x615712C5FD191C66ULL, 0x15E2502C3488FAECULL, 0x8CD3BAAC166A273CULL, 0x5393153939C13DE1ULL, 
            0x04B5D5D341A021D1ULL, 0x4A7B46B730EA1038ULL, 0x83E17E494C1C6976ULL, 0x0FABB90770ADF8FFULL, 
            0x380A4F5DF133EAEDULL, 0x9CC04444269C65E8ULL, 0x753F8A1A7D58C44AULL, 0x885D7E583068CE9EULL, 
            0xBBBF8322338AD108ULL, 0x88D9283C587A3837ULL, 0x15A7BCE9FAE9D7E5ULL, 0x1445A8C72B81D9C1ULL, 
            0xE08A9EE2959B100DULL, 0x9359ECABF71B8077ULL, 0xB42B4A5E53B28267ULL, 0x6DE324BDA966E91FULL, 
            0x8DC86C8876E29E31ULL, 0x8806A8A0DF8FBC49ULL, 0xBD60EA80E9936454ULL, 0x5B67AD3708024383ULL, 
            0x715EF99E32412678ULL, 0xF8B3239C2B459329ULL, 0xFAD53EB03EF69B9AULL, 0x76811AEE242C47E0ULL
        },
        {
            0xF577B3C5DDE748E7ULL, 0x8319D71977447DF9ULL, 0x79428C41984AB17EULL, 0x2A56153CD4383A35ULL, 
            0xEFC0E425AD2BBFCAULL, 0xFFC8A87F57CC5BB8ULL, 0x7F4598BDE6330C8EULL, 0xD53B72642BD2D9C1ULL, 
            0xD3C30FEAD97692A1ULL, 0x94F16B8F5B7D00EBULL, 0x303A603F4AA2166CULL, 0x06FA56630B6E6AFFULL, 
            0xF54F1D4875D4F8BBULL, 0xEA76FD22861B0102ULL, 0x25BB88FDDDB50E19ULL, 0x6EF0BE601BB2E410ULL, 
            0x99234F80380A7069ULL, 0x33E866E969B5ED58ULL, 0xECBFF709EDB57A39ULL, 0x4AC43BC109B4BE87ULL, 
            0x3036D7757265289BULL, 0xCABE763054B82620ULL, 0x8AD82CF4A0E3DE53ULL, 0x27DB12588B4FBA4DULL, 
            0xF323DC9EB4B5354CULL, 0x337A04246122C86EULL, 0x608D23C76A38377BULL, 0x246804C83BFDE7CEULL, 
            0x667BC56ED33D50E7ULL, 0xB6B89C9A67732441ULL, 0xEB4E5CB1AEB11847ULL, 0xA1BFD5B6EDDE98A9ULL
        },
        {
            0x13B85E091587A668ULL, 0xEF9A7A3EFA00AE42ULL, 0xED4908B549741B05ULL, 0x2673B6B749F14797ULL, 
            0xFDE80641C645B78AULL, 0x834E808B0BFF83DAULL, 0x49F6974EE6DF5ED1ULL, 0xA3E44E6054C8FAC1ULL, 
            0x6658E5E0CFA1975EULL, 0x51317F941E5B55AAULL, 0x9783AA32BA2F2131ULL, 0xDD5230C83184C796ULL, 
            0xFBC619E97DCA0B1FULL, 0x90E6959E31145CD8ULL, 0xAE3D5CF209F89F36ULL, 0x7A831BBE2DCBE204ULL, 
            0xDE1BC546D6F4939EULL, 0xCB2912B7DD95368FULL, 0xE2A5597E9305B4F1ULL, 0x245B0B343C5F7194ULL, 
            0xA067192F888836ECULL, 0xF02EE646F3B582A1ULL, 0x8F3E68CD641F214BULL, 0x8FB4A4AB51462AA9ULL, 
            0x264F24515126D6A5ULL, 0xB748F9A0C7476B5DULL, 0x65E6BA842BBE3DECULL, 0xA74FDA49907E763CULL, 
            0xA6DA0DDCA410CD07ULL, 0xC3C5CBC15CA1AB42ULL, 0x6492B489A7A1060DULL, 0xFCEF88B8C92D7B45ULL
        }
    },
    {
        {
            0xC03292EC748E72ECULL, 0xF554C0417DEFD461ULL, 0x7C929A9A430A1E3DULL, 0xBEAEF772CE7D174DULL, 
            0x5F068273A9309F75ULL, 0x33746C540852F68FULL, 0x017B7DD4046F93D2ULL, 0x880B0002CE6D1B1EULL, 
            0x09D4AD809601AEABULL, 0xE2F8130BE989E8FDULL, 0xCB229F201923951AULL, 0xC08A249B6524D7EFULL, 
            0xDCDA5DACCF4ECBDDULL, 0x795057AC41E375FDULL, 0xBBC8B65D53827BF4ULL, 0xC49CD8B32B055DF5ULL, 
            0x45F4A1E620186ECDULL, 0x6FA88B8E2D07ED74ULL, 0x214733F33F7479FAULL, 0xCE65D0A3DB69D08BULL, 
            0x52D42DAB9ED7E1BBULL, 0x41F9AF19C6BF75D4ULL, 0x3ABC4B24413C4ED4ULL, 0x794BF7F7F4A21E56ULL, 
            0x33706A7306D8AD8AULL, 0x70EA6B9AA2D555F5ULL, 0xB1B37285E3E847B4ULL, 0x0269BB508C49B6D9ULL, 
            0x8D0D5D86A6302D71ULL, 0xC45B5B8015F20753ULL, 0x8A8AA4D5E9ADAA68ULL, 0x81AD9C4B05256B3AULL
        },
        {
            0xE54284EFBEB12E2AULL, 0x1F3AB3EE3939C3D4ULL, 0x46C99BA8D903BA9EULL, 0x3DBA249E2C4ABF89ULL, 
            0x11DA5D32CE9B48E0ULL, 0xA5E1DB102931C693ULL, 0xB521BA4CF6E2094AULL, 0x2F417BB1A9F9C880ULL, 
            0xF99966D809F524D1ULL, 0xBD6040A33609EF73ULL, 0xAB3F95A5FA844DDCULL, 0xC112FEA611BCE5D3ULL, 
            0x00FDB6DB515EDD63ULL, 0xD6AF24ECB5272B8CULL, 0xFC4820600412B3E8ULL, 0x4EAFD3DB07EC1598ULL, 
            0xEF087E2D8D43AF4BULL, 0x933EF2395179F74FULL, 0xEEEFF95D21C19892ULL, 0x401355F601E6B78AULL, 
            0x28BF955114FD0EF6ULL, 0x20CA494A388A5018ULL, 0x6E9EB1A14507D155ULL, 0x57EE219A5641F7ADULL, 
            0x3C3FD3CA8BD4683FULL, 0x1ACF69FC0D8422DFULL, 0xCF78C7AF8B6A7B5FULL, 0xA61C466EE4A676A1ULL, 
            0x506739F078283107ULL, 0xEAC42F1B3D0B8D79ULL, 0x4B691F51CCE3CFB3ULL, 0x71CBB447958CD741ULL
        },
        {
            0xFEACE85BF34297E6ULL, 0x1C26D1065EF528E2ULL, 0xB63888C2B3A63FCAULL, 0x26B1FC84BDDC7655ULL, 
            0x4A19DF34D5773CDDULL, 0x2E9DBA8617B0D7A3ULL, 0x17EB4859B8A2DD4EULL, 0xD962C38C0728E63FULL, 
            0xDE09871658FCDB3AULL, 0xA586657EEA815C9CULL, 0x2C690A7FB5B7022BULL, 0x3C31B844BD2373BFULL, 
            0x7D03559E7227BD2CULL, 0x5DD2C6E3398FA7E9ULL, 0xB607B4F5931248AAULL, 0x0AB90CBA1A35B61FULL, 
            0x36294A29A5259654ULL, 0xE716BB8FD38260ABULL, 0x3AE9DDD494C44BA6ULL, 0xC360A11F2A3FC568ULL, 
            0xC9D1B4B8EBD9EA74ULL, 0x426B081109236070ULL, 0xB64384046D8F97FDULL, 0x8B4D2CB0A3878D99ULL, 
            0xDC3379BE153CA255ULL, 0x00C12C4D277822C1ULL, 0x19CA16A6BF55EA73ULL, 0xE2AC2F2E85FEEE5FULL, 
            0x583AC05323CC41C2ULL, 0x3136F21093415ADAULL, 0xB0551E7F94A4A514ULL, 0xFE8DDCF4774CD26FULL
        },
        {
            0x4B61360989AA34B9ULL, 0x0569EA820426A1C2ULL, 0xD861DF55458B8B2BULL, 0x1B5EA6034CE923A9ULL, 
            0xB10CA277AADFF868ULL, 0xF0B5B8FD796FB754ULL, 0xD73C95F65AB366C6ULL, 0x2225801D791636A9ULL, 
            0xBCBAC79B1D59937BULL, 0x804B383838899BBEULL, 0x143F09CD12CDCA59ULL, 0xFD23F809C552D07AULL, 
            0xF08C042DDF040DD1ULL, 0x8185E7D6DB8302EFULL, 0x4DA654974B617953ULL, 0x8BD77C8DD1B38A87ULL, 
            0x6E4898D443498EEBULL, 0x786976E1FE9BA4F4ULL, 0x40DF42927CF5B915ULL, 0x1C574F95FF03258AULL, 
            0xA6E670D207DFACEAULL, 0xB1ADF34E15545F6BULL, 0x04118AA1D5688E08ULL, 0x7D676FCF14A7EA58ULL, 
            0x747F67DF2C5917C9ULL, 0xF8E2544459961F48ULL, 0xA6968675C477CFBCULL, 0xA3D0F78489B56D40ULL, 
            0x9BBB5B11A2FA9EBFULL, 0x450637C3114F36E7ULL, 0xE1002E9467AC50C7ULL, 0xB25042CA05ACC4FDULL
        },
        {
            0xDF47ECB53EC050ACULL, 0xBB24793AE4AA4D43ULL, 0xB8F4BF1EC3BCB5AAULL, 0xC09AD9A2DB4086D7ULL, 
            0xFE1DBF9F6CE32C0FULL, 0xFACC7CCF1FB8F89FULL, 0x81C62C500A99CABCULL, 0xB284B51E876B4582ULL, 
            0x99E3560F9B197941ULL, 0xBE7B58E08F169330ULL, 0x21121CB2B2EE8E4FULL, 0x174A7D5E33B39643ULL, 
            0xF4AFD4F0C7847EBFULL, 0x29109DFC346FF7FEULL, 0x48643671A13A5860ULL, 0x78FFA338DB2EBF8BULL, 
            0x9936C8926F99042FULL, 0x73EB4B9FBA2B7638ULL, 0x3DE0A9944B447201ULL, 0xD1DCE6747D744ED3ULL, 
            0x63BA7179B52E7CB7ULL, 0x2452675EECA9E028ULL, 0x84A1B78DC6FD1B33ULL, 0x8423F5B3E391B3BAULL, 
            0x15EA7F06FD208B88ULL, 0xF15ED05B68882BE2ULL, 0x493CD326D86F5C56ULL, 0x06166A4C858718DDULL, 
            0xCE5C7C9C6E8807E2ULL, 0xBEB7675A0F64244DULL, 0x35928EDF8C29EF5EULL, 0x3D99BE8491FBC123ULL
        },
        {
            0xB50B3A7294471F62ULL, 0xE7DA8C5DDA16C71EULL, 0x31C0AF64E205E0D1ULL, 0x74251A863AB9A1E4ULL, 
            0x8966D7F3DA5199C4ULL, 0x596C6770A80B1CBBULL, 0xF4A305DAB7B37382ULL, 0x5A7CF2741E5A6487ULL, 
            0x17C04BEBA3777F47ULL, 0x7F7CA29E5A76F74FULL, 0xF44E7EE04B1C612BULL, 0x58729C41930FEEE5ULL, 
            0x6793D4F1EC95C16AULL, 0x4A5CB98780DC1E7CULL, 0x96014A0FB9CF3D2EULL, 0x15300577C4EEBFE2ULL, 
            0xC2358F01C1021CCFULL, 0x26A25CE4593A9ACBULL, 0x6BA1E3CD8FFEAC1EULL, 0x54A76FC97272D085ULL, 
            0xE59A684A2DBD3CA4ULL, 0x082C43EE4E61CE16ULL, 0x8972FF20F5672A58ULL, 0x9FE8AFEB2EA4D2B6ULL, 
            0x7FF674EBD5863FF6ULL, 0x2A5A48E41C5A6488ULL, 0x13251C5BE07DCD5CULL, 0x58605EB9CB2F4078ULL, 
            0xE48F36D903EF915DULL, 0x7BB459ECF9244B91ULL, 0xADDEF01C3FA53ECDULL, 0x45BC3C9D21C48430ULL
        }
    },
    {
        {
            0x2171E721E61D9374ULL, 0xE8E0AAAE607C573DULL, 0x4485043474178916ULL, 0x49B1D217F24EF390ULL, 
            0xD11BBD0014C8C8E0ULL, 0x36DE20E8B095D85FULL, 0xE477BC2E24D88E90ULL, 0xB5B7DF5BB4B5B590ULL, 
            0xA419CDCEDD640980ULL, 0x1DBC447E8999FFA0ULL, 0xE3F8E9F6648BBBC4ULL, 0xA03A1A1CA6317A89ULL, 
            0x281BBDAEBFB1E1EEULL, 0xE63DA7250592F8E8ULL, 0x8125DFBFB0E5896EULL, 0xE77994EC9D19F09CULL, 
            0xFFA625FD3C9F9499ULL, 0x1B8DC09415DCE74CULL, 0xBCC2E75C8843C5B0ULL, 0x0257924CCABBF638ULL, 
            0x9AAC1FEE061B583AULL, 0x8DB61D0B69320DEAULL, 0x81FC1A075DF911C6ULL, 0x05AB6B8F1DD482BEULL, 
            0x93CAE89592F6FF89ULL, 0xA39945EA5C26F99EULL, 0x4F745B5E38455DA8ULL, 0xB8AB98DCCDD9224FULL, 
            0xA12E1BB3C916CE1DULL, 0xA68D18BA47E3FBB2ULL, 0xC6395A567CAE09E3ULL, 0x01055825C4263475ULL
        },
        {
            0x2E77E15B1B0B6D4BULL, 0x2366CE509790D99DULL, 0x32E10AF6F66C7A46ULL, 0xB0A5FE21571C3708ULL, 
            0x230FAD7B41FF687CULL, 0x4781C1BCF430D611ULL, 0x59835D3FB47612AEULL, 0xA5ED615C21258C29ULL, 
            0x719930537DB0F806ULL, 0x0E962BA719E98469ULL, 0xDD2B809702A8F440ULL, 0x84A39A1247588530ULL, 
            0xC621E93BE7CD8803ULL, 0x2FFA810597889542ULL, 0x718D80A17A480B80ULL, 0xA6F5CE5129CC46FEULL, 
            0xAB2A3EC683BCA995ULL, 0x8DC07C9CFD8B31D6ULL, 0x0E3E5B1D28E13D12ULL, 0x00BF433FE24C7B69ULL, 
            0x007DC62ADBF2CB5BULL, 0xDE93E20868828BB1ULL, 0x0F7D6A204D154476ULL, 0xD4C261B179502DDDULL, 
            0xBF22A9EDC007549CULL, 0x1E5E79AC1D1E5345ULL, 0xF3438ADE1FC280B1ULL, 0x1C65D3FD7BC9DECCULL, 
            0x418819CD72317355ULL, 0x1B4DA5399EB1B27BULL, 0x267AD2DA18580D86ULL, 0x15F126F236307545ULL
        },
        {
            0xF50081334325863CULL, 0x458BC0450D5D9E7BULL, 0xB526180AB7D23F1BULL, 0x1B761B34880CBF84ULL, 
            0xA059EA65D68657D9ULL, 0x190D6C584FC0E48EULL, 0xD53E0B92D60473DEULL, 0x2B2719D649DA0D71ULL, 
            0x2A736373D422E9E1ULL, 0x2CD007BE42BCC4FCULL, 0x2AF8A569082F567FULL, 0xC55BB116E86249CFULL, 
            0xF11432FCDEF1EF7CULL, 0xBDAA106812720B8DULL, 0xE992EC480E3F72D2ULL, 0x05A4FC4ECB2553DAULL, 
            0x3004AFEFC6D87279ULL, 0xF8465A3BE7F84DDDULL, 0xEDD2D79B2176C185ULL, 0x09EE003F78FD2548ULL, 
            0x4E7C2C730B19F6A8ULL, 0x7987FC62D3019B1AULL, 0x4657EE103B1C5FF1ULL, 0xCFE1351CF71BBF85ULL, 
            0x94B7CC86A30F1342ULL, 0x989E02060CA57A4EULL, 0x50B5E70F6F0A2D54ULL, 0x7B8461372108A07EULL, 
            0x40AB45B18C2D20FBULL, 0xFF9B686BD51E7994ULL, 0xFB2D89B54775073AULL, 0x11CC74C2BC2BC6ECULL
        },
        {
            0xAD3B85B9707F1B9DULL, 0xFE81B95FF32F520BULL, 0x2F7F8670E0A63E73ULL, 0x55D5FA0203AC0F4EULL, 
            0x8E033295A2820017ULL, 0x83FA5A293B037F40ULL, 0x2B9F565BF28685CCULL, 0xF4AF57216094CAC2ULL, 
            0x606AF62692CE6352ULL, 0x8B30963C25E31BB1ULL, 0xA98D4AB5B660BC9EULL, 0x58A02900084DBEA9ULL, 
            0xEE7B70A5288DD2BBULL, 0xD6E214824704C29DULL, 0xB7C3370F96E26591ULL, 0xFA06A362848F6011ULL, 
            0xA4900DFFB05C3A36ULL, 0x76142CEDFF0DA678ULL, 0x9D57468111D1357EULL, 0x831BCB947E12596FULL, 
            0xC4884B48678DC8B2ULL, 0x63F94227C6249557ULL, 0x0DE516684F3F139AULL, 0xFF2F886DFCD7707EULL, 
            0x9DF0A6164C9E1408ULL, 0x5B536BD270AF376AULL, 0xFFDA4C7C9B70786BULL, 0x15E727953E2A9A19ULL, 
            0x82AF315D54453BA2ULL, 0x640D0BEACD77307CULL, 0xDAA02F05BA9CE1AAULL, 0xAB684D842D2D18AEULL
        },
        {
            0xCB1300D2B2CA3D14ULL, 0xB473FC5FE0C68E57ULL, 0x6D6606845AE62DB9ULL, 0xFD7D028A4C2EE4DAULL, 
            0xBFE5C65F18A53C8AULL, 0xC36944A8FEADBF02ULL, 0x134FD8971F9FB703ULL, 0x9D61299A4E2807B9ULL, 
            0x1E044823F3958F18ULL, 0x5B7459398C76B7F9ULL, 0x9B55B1241C56542CULL, 0x12E0921FFF14D9FAULL, 
            0x6A03B21E6DD53C94ULL, 0x32A8631C566EEE1CULL, 0xEA0FFB999ADF71C7ULL, 0xC56BF47C1A87666AULL, 
            0x66A71B823E114CA8ULL, 0x46D8F00227FED4B8ULL, 0x956405CEF5A2E5C5ULL, 0x9C4DA9CC88F67198ULL, 
            0xB787437FDB61AA94ULL, 0x130A27D5ADD0AB28ULL, 0x41F63295322B21ABULL, 0x6A2DE91B8BC2B322ULL, 
            0x872E0AE9D15B6E1BULL, 0x1EA44C99AABC1EDCULL, 0x27C88CB9510E3D0AULL, 0x412DA737412A2620ULL, 
            0xAE4F0BC933424C5BULL, 0x085B09E28D908A73ULL, 0x60B85D3F55E49548ULL, 0xBD8B3269BD4DA20FULL
        },
        {
            0x44EA6AF7697424F9ULL, 0xBE914B9FBE8AC06FULL, 0xD601BB16F386EAE3ULL, 0xE76CEDB2E5D1656EULL, 
            0x627947A2A94F86A6ULL, 0x8EE3F56193C37CA2ULL, 0x753C04F4F21C9FB6ULL, 0xA8544F8D5F23620DULL, 
            0x4F668E9470ACD8BAULL, 0x11B500C30EB00A5BULL, 0x7F1B89A5051252F6ULL, 0xEAEF153292A07BBBULL, 
            0x80C4B4059332F727ULL, 0xBC1ED4DF4BC55ABAULL, 0xA6D0DB7D5AF809B6ULL, 0x3744283C4F14BC5FULL, 
            0x0C6F2CEB19483FDEULL, 0xBE28822670B2CE5BULL, 0x82AAC63C9852F7E2ULL, 0xDD901DFFC0DF430EULL, 
            0xAC53620E2A1573FFULL, 0xA35108DCB168FB8EULL, 0x2AA2104E415FD51BULL, 0x0D4C0F5BD252ABBBULL, 
            0xF1293AAEA53A60F1ULL, 0xF125F587551BF175ULL, 0xF09B62B18A1D4D1DULL, 0x4F9476BA41081A61ULL, 
            0x317077F758B3A6D3ULL, 0xD9A9C480CA7A29BBULL, 0x3B975D36D431FE5DULL, 0xC35A744DBD228278ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeySpawnBConstants = {
    0x7D6900A4E86B4C63ULL,
    0x545DDDB77F34EB7AULL,
    0x89FE09B8B5535F70ULL,
    0x7D6900A4E86B4C63ULL,
    0x545DDDB77F34EB7AULL,
    0x89FE09B8B5535F70ULL,
    0x1C5C97FAEE1177D5ULL,
    0x6042CD15DBE576CFULL,
    0x91,
    0x6C,
    0x70,
    0xE4,
    0x1E,
    0x59,
    0x18,
    0xF4
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kSeedSalts = {
    {
        {
            0xDE4F7FDA6A44657FULL, 0x5D9BE05ED5A92F9DULL, 0x683E80648B5B81CDULL, 0x5558E4EC2223B703ULL, 
            0x2C98A13992743672ULL, 0x37D2E81E32974B72ULL, 0xEB0433F28EC7E75FULL, 0xF9847169EC7A28FFULL, 
            0x473A024D218183BCULL, 0xE96317D8B0F3E51FULL, 0x76671E8CD7A8C080ULL, 0x81AF47751CA962F9ULL, 
            0x33BF32318603D752ULL, 0x264D665428D73557ULL, 0x2EB4964513AEC8C2ULL, 0x29DB2C0B1D576470ULL, 
            0xA7A6EC4C59DF1D15ULL, 0xDCBE6FF025B1DA89ULL, 0x5CF021145303DCFEULL, 0xF8AC08BEF58D92E4ULL, 
            0x1E4CF3FA3ABF5F9CULL, 0xCC5D116CE861D089ULL, 0xB5E236327FDCAFC4ULL, 0x589A537689A04139ULL, 
            0x6F220672DDFC54B6ULL, 0x14D499549C664B29ULL, 0x61324DBFE3B1BB25ULL, 0xCB23D4D07EC48E56ULL, 
            0x0F7D961B55B81A4BULL, 0x082D3A488954D29FULL, 0x3D73F3DE9F130174ULL, 0x31046EB2A5734317ULL
        },
        {
            0x59AD57E80EE54489ULL, 0x4080D1B7DB4A8CDFULL, 0x72AF66BCC7A3493CULL, 0x600A5454BA710AFFULL, 
            0xD87EF9C059C5B60AULL, 0x2D04D41660A74E17ULL, 0x7200D6B9A43DCB81ULL, 0x47F10CAFBD80111CULL, 
            0xE661503EC1F58F50ULL, 0xC045B04DA8B59315ULL, 0x31F7F5EE8CCA51FFULL, 0x228F08EF03069497ULL, 
            0x9E8ED12BEA52C513ULL, 0xFF17E940099AF706ULL, 0x0DD38C8E745344F8ULL, 0x1BB804B466749E71ULL, 
            0xC39AF444A9A12D86ULL, 0x80D6506DD214A362ULL, 0x82DC083245D62528ULL, 0xB6CC1A71027DFDF3ULL, 
            0x627FDF005F5CB4B8ULL, 0xE3AC1DF432433C78ULL, 0x2019060467762996ULL, 0xA3E693C80D863C8DULL, 
            0xA1E3319E0A8EA6EDULL, 0x3F67FF6D4631CC86ULL, 0x972A57F9648D660DULL, 0x16083E13FA87195EULL, 
            0x0807D520854D5C49ULL, 0xCEED980DEAA4C5F0ULL, 0x5E13871F9EED701AULL, 0x8CEC2AB1F3938B4DULL
        },
        {
            0xCE8F949BA8479909ULL, 0xB6FD412CC46B32CAULL, 0x52EF2BA8EF57CAAFULL, 0xFF1F536118AC3C0CULL, 
            0x99A352062DF03183ULL, 0x281ED6152FE6DEF4ULL, 0x2C013553654AAA16ULL, 0x772B267CCC71344AULL, 
            0xDEBCE8F8558334A9ULL, 0xF85329A70097AD9AULL, 0x19EA2501623D293AULL, 0xD9418026958643EBULL, 
            0x5E901BDE731BF072ULL, 0xEFB38E7CB071A024ULL, 0x5E45CF1F2D855D8BULL, 0x1F302B1C4C9B9CF1ULL, 
            0x6D86393F7E3E51EDULL, 0x09314568AA7C26B4ULL, 0x7A46D8EAC61F76A1ULL, 0x9078725C8C92F80FULL, 
            0x61CEA571D64CA3B1ULL, 0xE93631827DDEE778ULL, 0x8663E3C0C153346CULL, 0x9B508C3EC22DB5A2ULL, 
            0xC62F55D05EF421DFULL, 0x6F4A79B75AA7A4C3ULL, 0x505A97C3C87570ACULL, 0xC9F554E836A4A4ACULL, 
            0xA8E1AF34245ED277ULL, 0x270948CF34E44CA1ULL, 0xD0258ED328E19475ULL, 0xFC9FA9CD2CCE9F99ULL
        },
        {
            0x58CC913C36AF44ECULL, 0xD207CAE3CDA70E05ULL, 0xA4E495C949985F0DULL, 0x90C2DD08E79AC5E7ULL, 
            0x1999EFB96092593BULL, 0x7BE4FAAC3956E096ULL, 0x1C0E984266065BD2ULL, 0x603CCB92861A4377ULL, 
            0x141B393DCF7358D7ULL, 0x792D2AB1C5BF1006ULL, 0x57A1853268E155A8ULL, 0xD78570FA2C7CB519ULL, 
            0x37BC6D8779C2B5B1ULL, 0x3EABD8A970311361ULL, 0x33DCB91024864115ULL, 0x3E2091FDFB60CBF8ULL, 
            0x512EA718B4497690ULL, 0xA09E8B9D2A878F90ULL, 0xBA332BCDEBCED6BCULL, 0xE5FB87AEA1AEF9EEULL, 
            0x05F8598395B2C37BULL, 0x542156AE15B8C5FFULL, 0x96BDFAA72002EF37ULL, 0x8D35C783E1DC9CCEULL, 
            0x8517FBF3B3718175ULL, 0x78F375DB8177BAB9ULL, 0x15D9E374E76B5831ULL, 0x2EABEE321F6E7FEEULL, 
            0x9B36F272FCC0184AULL, 0x256949C993120B79ULL, 0x7DF8400C2E331316ULL, 0x576FFF36A4F04F32ULL
        },
        {
            0x2D3959F4BE056718ULL, 0xA656899308F74E25ULL, 0xD64ADE25FF532F4FULL, 0x69558D96CA3E2EBDULL, 
            0xF142B975FBDDABF5ULL, 0xF01F42EFFA07F4F2ULL, 0x285362EE216DD7E9ULL, 0x875DF70DA7AC8DFEULL, 
            0xBC52386E790E26B4ULL, 0x8BF6AFD7470741C3ULL, 0xB24BB80D50450AC1ULL, 0xDCB61C9D156AB035ULL, 
            0xD0007B73DF347D47ULL, 0xF880DAFD2E9CA929ULL, 0x9173390084FB3386ULL, 0xDFE28AD8CC18B3D0ULL, 
            0x25527751B60BBFE1ULL, 0x65AD402A240D07D6ULL, 0xD00CCAD3DE249178ULL, 0x6CA8262234352ACEULL, 
            0x151B628D8C7E8E86ULL, 0x451648237EEEEC92ULL, 0xE677DE4D5F646A27ULL, 0x35DF50FBA6AE920EULL, 
            0x94067DEA4D2E0967ULL, 0x03033ED3AEB84155ULL, 0x0EDACBDCF8F67C8AULL, 0x2A36F28E94A96A5DULL, 
            0x2BB8B1025B90CB48ULL, 0x42FB4211E75275AFULL, 0x873FC9A7B301AC02ULL, 0xE3FFC596B9FE002FULL
        },
        {
            0x332613AF95E9C79FULL, 0x97D0B64CE10CCA48ULL, 0x1EEF36CBC8361CDCULL, 0xBE481A4A11DF4894ULL, 
            0xE79860EF21404908ULL, 0xDBEFE587657775ACULL, 0xC42BC7DEB8319924ULL, 0xC16BFE4EFEFFB881ULL, 
            0xC3AB16012ADCA26CULL, 0xF1ED98709C8C8595ULL, 0x2B750C8615EB3721ULL, 0xA4EB55E1552E7629ULL, 
            0x8607FB744300768BULL, 0x7E1BDD882E4E056DULL, 0x78FAFBF23A0DEA34ULL, 0xD8C17C397AAAE39AULL, 
            0xA8146A4F693E0C65ULL, 0x50CCD17D30724DA1ULL, 0x8B8D446ECC551887ULL, 0x9B2B0AD87A3B1018ULL, 
            0x3B3908D968BFB5D5ULL, 0xA87B22E4611CB008ULL, 0x105D6E70E7C8529FULL, 0xABC6EB6E5DD5F4C3ULL, 
            0x2034216A6DF75F83ULL, 0x0ECEC3AC16C3483FULL, 0x7EA59E106A6FA98AULL, 0xA139D8EE6C6FAA9FULL, 
            0x92F083202482C12DULL, 0x705F51454FDBBF88ULL, 0x158E06A4F80C373EULL, 0x9222B3AE9F157D6AULL
        }
    },
    {
        {
            0xF884AC88AD81F5EBULL, 0x9967790E16C1E501ULL, 0xAD9A422EF43DC12CULL, 0x137D5D06BA05EEC0ULL, 
            0xA7B4447692DF20D7ULL, 0x957B41B9384C2CE2ULL, 0x500E73456872B02EULL, 0xB58268041F5F442CULL, 
            0xF2455370618BF5BEULL, 0x8E875984CB51B5C6ULL, 0xA2F06F54D18898E2ULL, 0x2E2F0AD9798D75B2ULL, 
            0xCA4299EE6AC891D3ULL, 0x0B3C203A95E39913ULL, 0xF00C709F054EFD61ULL, 0xF3E7BC1015382CB9ULL, 
            0x64BB97849D4D4372ULL, 0x739F3F5D301E57ECULL, 0xCFC6FACCD5FCE77AULL, 0x7F4A7FD2035D127BULL, 
            0x987F628833B4BB37ULL, 0xBA9C26F79115664AULL, 0x880C2F61CD21B910ULL, 0xA4D0A8AEDDCEF90BULL, 
            0xFB3C0E250F3FCF55ULL, 0xE0AD1B94941EC6ABULL, 0x3B4A34155562AEA0ULL, 0xCB14205A10B1D83AULL, 
            0xE053CEF62C01ED62ULL, 0xD4CC65D96F780AEFULL, 0x25040886D8154AEEULL, 0xA12C91D0D36BE17EULL
        },
        {
            0xFFB42BE5566174F2ULL, 0xCB4F5F578A904BAEULL, 0xD77B38CFF901FBBCULL, 0x5A1DAA761403B20AULL, 
            0x17BB5A36C5EA0B6DULL, 0x038295BF21D6B00BULL, 0x1ECB2A27B8A18B9EULL, 0x67C318BCCD95DE71ULL, 
            0x5072FAE1E06DCB13ULL, 0xF0916DE042FC4898ULL, 0xCDA28292575E0476ULL, 0x6FE425E1C9AC6705ULL, 
            0xB5D26F557699593AULL, 0x837DCAD119A41DA3ULL, 0xACA148C61738EF66ULL, 0x10FE98BC5979B906ULL, 
            0xB2731044E9AC7B85ULL, 0x4F99DDB5F5F61D4DULL, 0x8BEB1BBF269C5DA8ULL, 0xCA47CCAA23948DC7ULL, 
            0x87BB09A7DF448D68ULL, 0x05F0412067E294D3ULL, 0xF8377CEF3F75E6FCULL, 0x082D6C9B7B18C8F3ULL, 
            0xE70E0A71AC15A3E2ULL, 0x9C312274EBBC3458ULL, 0xF7B3C37D86A404C8ULL, 0x66D3CCB5D9B32BCEULL, 
            0x91BBC3D86BF7EDF8ULL, 0x57B8E4A20D1276EBULL, 0x449D8BD59CA7B41AULL, 0x3D2F2072C18180B9ULL
        },
        {
            0xFB7D6319EF0373C1ULL, 0x2BF8D21AEEBBA9A5ULL, 0xF4905DA1295F730FULL, 0xAEE6C50339C0EB06ULL, 
            0xA81CD8FB81FF67A9ULL, 0x1972C1FDD4AB0214ULL, 0xF761D166D931A2A4ULL, 0xA42EF7831065BDF9ULL, 
            0x5D9D1C898C280A69ULL, 0xDAF670C2FCD9C917ULL, 0x3BD3EA9DD16F4CB8ULL, 0xEA864D4A70D7FF4BULL, 
            0xC8FAF8F4246C9E05ULL, 0xD90F9EED24C6D9EDULL, 0x1243070D510883D2ULL, 0x949E47DFEA9ADC41ULL, 
            0xFAE36444F9DA7C20ULL, 0x34F3998C149AA094ULL, 0xF2BA6F0546107E98ULL, 0x85E3AE7AB1CE085DULL, 
            0xE3A913EB91CD91FBULL, 0xE76F3519D87FC629ULL, 0xF7441E88DB3A59CAULL, 0x8478C0766E935F5DULL, 
            0x84A7956E414E11D5ULL, 0xB8DF7B3E89E2929EULL, 0x7EFDD9374F1600C3ULL, 0xE08CE9B851DF6AD0ULL, 
            0xF30F7DACBC4668BEULL, 0x1D58104E0280D804ULL, 0xCC394777D7888AE7ULL, 0x9B122AF3C782B3CEULL
        },
        {
            0xA879DC671EC046DCULL, 0x37676E59F259E2CEULL, 0xD2CFE450E111CD16ULL, 0xBA7B59EE1D4FDFA7ULL, 
            0xC64B37D8A1E962E7ULL, 0x101E8F884C365D1EULL, 0xC780BEAFA497B2DFULL, 0xF5899BBE7956E4CAULL, 
            0xB9D215AD3C1C6E9AULL, 0x2C3F4BE1DCB62F0CULL, 0x89A9ED3BFD95570AULL, 0xC6F8AEF476EEA4EBULL, 
            0x542CAFE49EFD6ED6ULL, 0x3083F5F900874E62ULL, 0x25EEAFB367DEA6A9ULL, 0xCDD863F97AAEBF0CULL, 
            0x633ADD957F3B634FULL, 0x6FD059E57F37F0A2ULL, 0x5FF9EE1BCEFEF88FULL, 0xAD72E7FA4C820EADULL, 
            0xE66260A255272378ULL, 0x5C914E0A49DF01BBULL, 0xC1870923A37A614BULL, 0x6ED65EE41591FAB0ULL, 
            0x56C547AF693FC5A5ULL, 0x194F817F2F86FF17ULL, 0x19E88E4E75BE1995ULL, 0x941805490304E0BFULL, 
            0x1B6F7D9C9D827CB5ULL, 0xFCA783E655A4E589ULL, 0x24E4DE90D2E40EC0ULL, 0x1C3695D49B906CBFULL
        },
        {
            0xA1A8AFD2232AF122ULL, 0x3E04E74FABFD92C5ULL, 0x41F1CBD09BA5904EULL, 0xA80E75663CA1CA61ULL, 
            0xB6581BD72C856178ULL, 0x1D7F06EA0710A89BULL, 0xB10E6053CB3087A4ULL, 0xB516A23AF7CEDC31ULL, 
            0x09F08EA016B7DCD1ULL, 0x000CA75C70A6A984ULL, 0xED0D286782C9DB7BULL, 0xBB529984D2DEACB0ULL, 
            0x9AA5BB53B1668EEFULL, 0xBDA6E532838C2301ULL, 0x2CBBE57D7EE78344ULL, 0xBDBCBD85D2F5DCF8ULL, 
            0x3F7668C9A2A1761FULL, 0xCF33E83FE297AF14ULL, 0xAB53FEF19B0386A3ULL, 0xD02EE299B3EFEC26ULL, 
            0xF34EFEA43BFB7C94ULL, 0xA0A8AF75D776BC43ULL, 0xAC333C8186AB396BULL, 0x9664739384838212ULL, 
            0xE2A0BA12F7358C10ULL, 0xA0F2EE20F1C9B2BBULL, 0x73A536F58F89493DULL, 0xA42795DB871849D4ULL, 
            0xEC08280F2203F4B2ULL, 0xC3AD76CF980ADBAAULL, 0xB17373454AC0C7A0ULL, 0xCD2C3884C8548F4EULL
        },
        {
            0x9E00F7CDDCDBC365ULL, 0xD5F18CD14BBA4E9DULL, 0x6351439D7A46B220ULL, 0x4CE160ABC237DD62ULL, 
            0x1DC7A731BCBAC32FULL, 0xEB1E40FD581CF19FULL, 0x373DCD1F8BAE74CCULL, 0x6F3345B57EC25636ULL, 
            0x04B5578B123B0DD2ULL, 0xC04D86664809133FULL, 0x86CE59DC18957FFCULL, 0xAB5EBF252828C56FULL, 
            0x41C2918704C8D42EULL, 0x691098B40343E9EFULL, 0xD90FC7C54132B634ULL, 0x38E595032D104928ULL, 
            0x29028C8053410312ULL, 0x69E7E312C05C3218ULL, 0x511DCC9C2A97D6BCULL, 0xC3407BA051C42546ULL, 
            0xDC467001E50BEEBDULL, 0x0E423630FC1537EFULL, 0x919BB36B84D1A3BCULL, 0xF11806DA66B00A7FULL, 
            0x7619AC15C615CEB0ULL, 0xF8EBF65FCC98B185ULL, 0x4BBCDFBE514B3C92ULL, 0xB7FDEA34AB85C988ULL, 
            0xEA91BDFE3AAD9C5DULL, 0x46E7669C5B3F7826ULL, 0x1E8C9BF677FB7646ULL, 0x30EFB1EF2DF9170FULL
        }
    },
    {
        {
            0x50585C115159AC3CULL, 0xDA34939AC181B95CULL, 0x43C5CA8565AA5577ULL, 0x51C81F91732EED54ULL, 
            0x74B6708FD0289867ULL, 0xC20BC4D371BD15D6ULL, 0x9C51FA59B787D93FULL, 0xD418FF170FFB1CD8ULL, 
            0xA0E12F52D6BE48BEULL, 0x49149A890478FAABULL, 0x952DCACEDD5C331CULL, 0xAF11E49A1AAFBEFDULL, 
            0x53528895B29C4BD0ULL, 0xC172B36823C4F09DULL, 0x16FC5D3AB2C5FD47ULL, 0x9C683909462262F1ULL, 
            0xF70F3389EBAA084EULL, 0xBC397157C963FB5BULL, 0x75A73E6F26D49AC3ULL, 0xE74E8B1A7D8C4197ULL, 
            0xB425B1D2A1464CCCULL, 0xC21D12F3C90A4F8AULL, 0x4B462280895C6AFDULL, 0x110185C809F8399BULL, 
            0xEC7A0EEF0F92B7A6ULL, 0xA7B4A1A6623274BAULL, 0xEE29781EE7A81A90ULL, 0xC008FBFB0471DF8DULL, 
            0xBF77581712151A79ULL, 0xCA97E9FB1F88E387ULL, 0x8F110912BC371CBAULL, 0x1CD88E2841084E2AULL
        },
        {
            0x00F80954AA81B043ULL, 0xFCCF85E0697CEC9FULL, 0x7D481DFF934FA053ULL, 0x430488D8F74FE901ULL, 
            0x4957714867D9CB12ULL, 0xBED7A1DA4F3B02D1ULL, 0x4CBE677321CD3323ULL, 0xD1383FA113E5CC42ULL, 
            0xD78E407AB30B426EULL, 0x4A32703E9B3F6CBEULL, 0xC4277E81C3469946ULL, 0x7D69055B9092C7B0ULL, 
            0xA5FCAB5D5B0A8940ULL, 0x5FAC532DC5621F50ULL, 0x231A292A270DAC20ULL, 0x8011723E5D3C02B6ULL, 
            0x6FCD42674569E53EULL, 0x8DB8A5D9B5CD112AULL, 0xF14C33981901A23FULL, 0x4E849E8DF253B826ULL, 
            0x76F577568C0EF26BULL, 0x5A0889DD84F30930ULL, 0x3865F130B1794A99ULL, 0xF4375932864D99F4ULL, 
            0xC28796B2405EE8EBULL, 0x05A4AAE232B8A707ULL, 0xAD3E9EE2E9135EB3ULL, 0xCC1BEF49BAA9687FULL, 
            0x48DC9C3E3D09ADA0ULL, 0x1F1E586DAD6DC7FBULL, 0x34D161C98E14B2A1ULL, 0x2B321631671EB91BULL
        },
        {
            0x9D91297787FBB17EULL, 0x82602AB012FFAD19ULL, 0xF685498D3D2F9B55ULL, 0x1CE0A8E798D4240CULL, 
            0x4E75F5FFB486E178ULL, 0xADF03EDE892E872BULL, 0x675E49BCDAB61197ULL, 0xA969722141ECF329ULL, 
            0x94A103C7C450830CULL, 0x862C87F811F455C2ULL, 0x8CC6517D61640DC5ULL, 0x6FB5CE2482ABAAD6ULL, 
            0xE3100BAF01231E21ULL, 0xB716892DC0525A99ULL, 0x9D87872CFD42C010ULL, 0x9F8C915F0AF0C057ULL, 
            0x87E9A884313697AEULL, 0xF2C3FDC4CAE30ECBULL, 0x93FD5461688D2536ULL, 0x577975AFF80BA419ULL, 
            0x79886AD6B02CECBFULL, 0x4C2A42EB06463DA4ULL, 0xAF2F6012D8AEB240ULL, 0xF6DC71E84DCD9A1DULL, 
            0x6FA50C7C48AF23E4ULL, 0x0C4FD6BB74FB61D1ULL, 0x61C643861228B369ULL, 0xAD38561D35A453E1ULL, 
            0xD71522A80B0E830DULL, 0x29CCFE2A27C99191ULL, 0x2DCE45807D36B704ULL, 0x168FAE7A7D311CE0ULL
        },
        {
            0x4947BEE06B45532EULL, 0xCDEBACCD6DAE481DULL, 0x26F932DDBA8F56C9ULL, 0x363DB55A9F398574ULL, 
            0x80C2F5532AA0F816ULL, 0x4128E1D2B98055C9ULL, 0xCFCE46960E2BA87DULL, 0xB89D95C9EE85C088ULL, 
            0x213F8B1B894BA921ULL, 0x43B72EE4CF36692FULL, 0x267B32909A9984AAULL, 0x4C1D29853B224812ULL, 
            0x5B3DEAFD68789776ULL, 0x8F5081C0C2A4A0DCULL, 0x9ECD424AA0769B99ULL, 0x08F69C6FB299BB51ULL, 
            0x720C93315139942BULL, 0x534CC48D620F8719ULL, 0xB073C0E6480486DCULL, 0x01A3D98E88F77534ULL, 
            0x881B5198A6B860A9ULL, 0x9D1B8C0FA60AC696ULL, 0x3662125D8AECEE41ULL, 0xCE32C0F0C5F4C95FULL, 
            0xE3E160408138025BULL, 0x1210A38818322938ULL, 0x6D1D9CF601B7FCDCULL, 0xB192BF1C64DB9EA7ULL, 
            0x3CD00A8947C9FF3AULL, 0xE5FE71CC049E03DCULL, 0xA79A0BC48A669867ULL, 0x8D9AB3F3E7B3B273ULL
        },
        {
            0x6C2B63D0922BEC4FULL, 0x65F5FCE4153DA5D0ULL, 0xE168BBA0D7B375E6ULL, 0x6A1E2A7EEF034213ULL, 
            0x4994C6869B07B589ULL, 0xECC8351171D19F41ULL, 0xB2B06CB95EBBB3F9ULL, 0x92F3885F1CFD6FF7ULL, 
            0xE03EEADFA5DE6D4BULL, 0x1C8B7C6B2AF43222ULL, 0x9F7A678ADFFA858AULL, 0x52F61EEDA852775AULL, 
            0x11C58FBC40EBC8D7ULL, 0x18E36DFFD21B2692ULL, 0x89A9AA64164F0799ULL, 0x119E2AA58B00EBB7ULL, 
            0x8974D90C1E71758EULL, 0xEB8A748124DE0C88ULL, 0x8026971FED7FA529ULL, 0xD69262B7B9EFD6D4ULL, 
            0xF7F8554CEA6DE00FULL, 0x6CBCECE58F7493FFULL, 0x4F76267BE01DB03DULL, 0xBAB3CB41B311FC31ULL, 
            0x1E110F3A948A1746ULL, 0xEF209D21EB70F76BULL, 0x32292EBF6BBE29CCULL, 0xAAC377219FF64AB8ULL, 
            0x8D1EE1F9B26A86D1ULL, 0x31A3C55A97EB78EDULL, 0x7B35B4959FB12939ULL, 0xE46E5875F5004136ULL
        },
        {
            0xE20F41EBE38B5500ULL, 0xBAB94E95F4E32DF8ULL, 0x9A57DB9BDDF132D0ULL, 0x9C9AD8984E925A27ULL, 
            0xDA381F50B49E5058ULL, 0xE8D7F58CE921982FULL, 0xF51AA0592E84430AULL, 0x6B11B85BAE2A2747ULL, 
            0x27A9FFBDD484BAE1ULL, 0xAF88F635648463E7ULL, 0x2EA2C51AE06D4448ULL, 0x4A1BBD8C8A35EBDFULL, 
            0x957165EC5FEECC98ULL, 0x1DC6B64E0058B365ULL, 0x4ABBF56F09B3AFE3ULL, 0x57234F7A72AED653ULL, 
            0x53BD1AE8AFFC5584ULL, 0x008B86A542FF5487ULL, 0x9B90947CEA153EA8ULL, 0x06EDCB0EA0B3736DULL, 
            0x764750287D9E2AC3ULL, 0x50F08BAFA7962218ULL, 0x3C5280F86AABAE43ULL, 0x24F62D14651B4A01ULL, 
            0xA9EB068D663683ABULL, 0xBE7E0C9D7A04A647ULL, 0x97C6004672E3697DULL, 0x148EA1C2FF41831BULL, 
            0xFC3FC2B77B015843ULL, 0xE000DF51DEB1E8B0ULL, 0xB7E5D9C5774259FFULL, 0xD32F62B47C78F3F0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kSeedConstants = {
    0xF2AC4CF2AD84A1FFULL,
    0xFD950D659FFA226EULL,
    0x663A9EF91AC6759AULL,
    0xF2AC4CF2AD84A1FFULL,
    0xFD950D659FFA226EULL,
    0x663A9EF91AC6759AULL,
    0xE947E7F1766C2FC4ULL,
    0x0809F5030E25C737ULL,
    0x06,
    0x7B,
    0xD2,
    0x63,
    0xAA,
    0xCD,
    0x8D,
    0xFA
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kTwistSalts = {
    {
        {
            0x47415B4BABBCF01BULL, 0x79727E7BB9C5A6DCULL, 0x8AF20F0130C33478ULL, 0xBEC1CB0E9332EFC5ULL, 
            0xB57FA7CD1B737244ULL, 0x7FB71DB378D12D4FULL, 0x33380A841B02EE2BULL, 0xB2BC9A96AA27E4E2ULL, 
            0xEB9297EB05D10AC9ULL, 0xDACF266CF4BE653CULL, 0x5B1D235AD9DDB692ULL, 0x81808230AD159A9CULL, 
            0xDB092D97F2E6E6C9ULL, 0x528677DC5B9CAFE4ULL, 0x99FF438C56ACDFF8ULL, 0x5360B9F067F5E0F1ULL, 
            0x3C6300EE61BAEB9AULL, 0x4BD4957C89B4DC07ULL, 0xBE50DA382FED046DULL, 0xBF4544583A3E25B7ULL, 
            0x3AE7212AFF2546F8ULL, 0x15F20CF775A8A04EULL, 0x07388215D3FAC197ULL, 0xB2575C39FD920847ULL, 
            0x775221842E9F0369ULL, 0xB07EC6D9DA890084ULL, 0xB98C3B9C9D3BC6EBULL, 0x5D4BDD631C6F57F5ULL, 
            0xC11478A6700E9E80ULL, 0x5E3256E81F1E02ABULL, 0x0B995D854E047ADDULL, 0x0590EA801FC694FCULL
        },
        {
            0xB18C800772E47EF6ULL, 0x2AE85BD34E6B4665ULL, 0x513459CECF8E3856ULL, 0x1C07BF510DD435A4ULL, 
            0xE09BCCE4E6C7027AULL, 0x5C1B78F81882507BULL, 0xBE5BBA2C1237B410ULL, 0x021DAD3DEB708E13ULL, 
            0x30D856D096909BA7ULL, 0xC36399EF76F3D8DAULL, 0x96C6408F82EFF3D6ULL, 0xA366951DD7315342ULL, 
            0xF86A9934A6E1F5B3ULL, 0x4074A71CA1EDA443ULL, 0xF022B0EEA72699ADULL, 0x03A392DE08B1DB3BULL, 
            0x497E98FAE9BD2EE8ULL, 0x2F5352A8C60FC2ABULL, 0x55CD0122C3970C6FULL, 0x4971FB14544CF45FULL, 
            0x8F167251186B1353ULL, 0xE4DFB7165585880FULL, 0x0FE2794E59A039A7ULL, 0x78806ED278B9AD40ULL, 
            0x986264330F08BE60ULL, 0xC86AE608BD1E27C0ULL, 0xB1B9F9807A84FE2AULL, 0x5000B1A31078B32BULL, 
            0xD30EE9B068539A03ULL, 0x060F34F31A38A3CCULL, 0x7BEF890A859E120CULL, 0x5BE4319E2D427CA7ULL
        },
        {
            0xBB7C8621ABC73727ULL, 0xB43F410B01003553ULL, 0x046E9A3519C4C98FULL, 0xF6B5D9DA9A80E86FULL, 
            0xE0F26D26CBBE1875ULL, 0xCB60D6E4EAFB004AULL, 0x52603F091E535452ULL, 0x55C269D24E856655ULL, 
            0x58C9EB863C4F0CF5ULL, 0x812BD8E365F430EDULL, 0x81EE54F26350B0E4ULL, 0xE35505FB5C24BE13ULL, 
            0x6BC33C318FC210F3ULL, 0xEC2C6DB265EEE627ULL, 0x2C462AA16943798AULL, 0x1F86C20028162A37ULL, 
            0xD596C8D74BD18AA6ULL, 0x2862D3C7E54F68DEULL, 0x960C2CEB197EBA07ULL, 0x5B145049BBA013BEULL, 
            0xEA28B448B2310CC7ULL, 0x7EAA5997F0A118DBULL, 0x2B11E1A14A870458ULL, 0xB60BD5FD0F6FBB8DULL, 
            0x62B056023CB6107DULL, 0x45D05E4A32C2B02FULL, 0x1032B235C8DC85A1ULL, 0x6380436389A8789AULL, 
            0x326BBAD90B26A4BDULL, 0x06D14EF23BAC653BULL, 0xFB18A5E08C607F57ULL, 0xBA5FD66ADBB1D422ULL
        },
        {
            0x70D3FFE376B4BB93ULL, 0xB6533C47FF2CB115ULL, 0xBC0C42A5B85D64B6ULL, 0x95E8234C29B2D4C5ULL, 
            0x45E8B7C5DE051D1AULL, 0x6B724020E3CD4E7FULL, 0xB82DF60A3835E23CULL, 0x1F9257C495D0DA78ULL, 
            0x8FB7CC9CCCFF833DULL, 0x535835ADA2B13C65ULL, 0xB231545801D826F9ULL, 0xC9DA509EC86CBFE4ULL, 
            0x3FED822510DD5D25ULL, 0xA6DA674A2BF098C3ULL, 0x4BD283333624C89BULL, 0x06206B164873EB16ULL, 
            0x0A17EBEC44505B2AULL, 0xF71E064E5F08E416ULL, 0x6E1000F460567C70ULL, 0xAA34CF57148720CAULL, 
            0x48A778387AE1A223ULL, 0xD87B1C6245007AD6ULL, 0x7DD31C8FD0BF5D19ULL, 0xEE5AB34B9AC59E2FULL, 
            0x2B97636E50118EE5ULL, 0x5DDCF1A4C9B63CE8ULL, 0x6445989416C8779EULL, 0xA1E5B08D20F5055BULL, 
            0x93FB36B2529A73ECULL, 0xC2DFE1507188A2D4ULL, 0x610E00972D2C4CBDULL, 0xCD74D870CE653626ULL
        },
        {
            0x34CEE733390AE3BAULL, 0x8EA515E0B699CCC6ULL, 0x6E20960499D2C4C7ULL, 0xB3C85EA6399E9FE6ULL, 
            0xA7D1255BBBADE75AULL, 0xFEEF0476D810C544ULL, 0x32FD3CC8821F2C8CULL, 0x6C541CA99D76B809ULL, 
            0xF7B67FCD7C35E8DEULL, 0x43642447C08AFF6BULL, 0x9E6DB4497DD6EA36ULL, 0x43DD8EDD36231F92ULL, 
            0xB778CB42522364C3ULL, 0x337890B67A20559EULL, 0xC521FE68CC46B5F6ULL, 0xABDB67D334526F65ULL, 
            0x3273222D01155E77ULL, 0x9A9ECD34000A8A5CULL, 0xA610F95522843990ULL, 0x107853C1561CAA55ULL, 
            0x8CFC203D03EFABB8ULL, 0x4A0F2B8A5A3463C1ULL, 0x65B1859E9A7BEE2DULL, 0x47FA581B94ED863CULL, 
            0xD6E8B5A0D1411705ULL, 0x151D6E18F320A6E9ULL, 0x518EC51135E5A095ULL, 0x155EB59DAB39427BULL, 
            0xBB7A8B0F1F7D6828ULL, 0x36D442AF6447034DULL, 0x8B13EF9E61718721ULL, 0x4F30718F77CFE8E5ULL
        },
        {
            0xB420C6A7A4975D5BULL, 0x846B4002F3E34437ULL, 0xB1A9E32F4613C712ULL, 0xF23BE98894339CC1ULL, 
            0x02D468135CA8B83FULL, 0xE49795418B4A7F50ULL, 0x08AFB63D0BF6A80DULL, 0x4BE1C1B3EE1D6B4AULL, 
            0x33FC96115FCBC754ULL, 0x1F4DC0C3C2154FDCULL, 0xA912617353F0F211ULL, 0x630D681A3C4423B4ULL, 
            0x979293DD79C9DBBCULL, 0x29AF7F0952DF7326ULL, 0x46527D24B8C3799EULL, 0x1F21BC79D2893C22ULL, 
            0xDF5FE9A92228B4DFULL, 0xC140195CB5249D0DULL, 0x4B0B775AEA24A412ULL, 0x505976620B0D26A6ULL, 
            0xF0AF906A64560186ULL, 0x4A38B029BA4129AFULL, 0x0B7213AC71A67E1BULL, 0x626395621A77985AULL, 
            0xC7F69306540DB168ULL, 0xB0571ADDC99D4C29ULL, 0x5151F95166816583ULL, 0x91945FCB2F1C0584ULL, 
            0xB5225F91C9F0F901ULL, 0x0E37B9BB5B985DB4ULL, 0x890EA5990A42B34BULL, 0xF3C58219C40B2463ULL
        }
    },
    {
        {
            0x08D602FA72ED5AB4ULL, 0xB5EEA2D45D586D68ULL, 0x1BB47FED8B2F0A0DULL, 0x7BF671454887ED8CULL, 
            0x083A8E4E145059CAULL, 0x08A121300E26AB31ULL, 0xC389BA572D240590ULL, 0x58A89F9B23451A16ULL, 
            0x8AB50BF4EEDF0792ULL, 0xB59D7B05400685CCULL, 0xA9488ECB5159421DULL, 0xA58BC7BE8669D779ULL, 
            0x1773341A33B93422ULL, 0xB05DA8DAD943AB2FULL, 0x325D8E66EDD1AF95ULL, 0x65227DC8F7B016C7ULL, 
            0x2E679E7FD3BE17B2ULL, 0x117B1D276632745DULL, 0xA997603D9D9AC990ULL, 0x273662B0E873FF10ULL, 
            0x22DDCE7403422498ULL, 0x60FA512EC3BBD14AULL, 0xC1B533863FBB9ADEULL, 0x6D8214723F926128ULL, 
            0x5BF6E5D19F280FDFULL, 0xFF610AE456351051ULL, 0x868C61B93EE50ECFULL, 0xB2748785C4E72D13ULL, 
            0xF5C33DCB0A5DB463ULL, 0x15E4647A7A5E931DULL, 0x1715EA55280DD982ULL, 0x9CC24AF5726DE1A4ULL
        },
        {
            0x6A0F6C0E287C52ABULL, 0xE977814915828AD5ULL, 0x5C1F680B91D347C4ULL, 0x16371998EACC873DULL, 
            0x0A8BC0E962AD9A38ULL, 0x65F2A41F33D03CD1ULL, 0x0A3DF1CE79336278ULL, 0xBD1D8E4C6F28440BULL, 
            0xB691CAA3712A121AULL, 0xD9580BB593A980BFULL, 0x97692135BF0EF390ULL, 0xADB704404BB9421BULL, 
            0x02685ECA4E6D03B1ULL, 0xED5DD2493FE9CE5BULL, 0xE46DAEE53BC13F93ULL, 0x856187948AAEA2B3ULL, 
            0x129435F082798531ULL, 0x65D7ADC6874DB6C4ULL, 0xA348E8D4760FAD75ULL, 0x88DE5BED6F3D93C1ULL, 
            0x883897F3D4C3A5FAULL, 0x1A0F7327EC3FFEF9ULL, 0x58E0BE4C8F9AFE96ULL, 0x8AC94AB29AED1CC2ULL, 
            0x23908F2DA4865C0FULL, 0x2B799A79DF3BDAA2ULL, 0x6D9E4D75CEED4DA2ULL, 0x6EB0D78924C265CBULL, 
            0xE554CEA523A5A65EULL, 0x73E7E2C872D80859ULL, 0x4B5D0BB520B162B4ULL, 0x82D467364FCC73A5ULL
        },
        {
            0x4C3E7052F84D7238ULL, 0x9578CFA88D11CB8EULL, 0x4194832EADBF9E71ULL, 0x5128B53DAB1BB45FULL, 
            0x225C3D8F034DB7D0ULL, 0x2E22BE72058A8179ULL, 0x39DB7768BCC4B274ULL, 0xC094A061E11C4A33ULL, 
            0x4B902860F4AED239ULL, 0x828DF1AB15AB256DULL, 0x37BF1B5C75FBD617ULL, 0x6D0BB24FB94E1F87ULL, 
            0xC02D7D7843DF96ECULL, 0x60CDF059158C7631ULL, 0xC6DEF24A2D6A4A27ULL, 0xA4A4FCBB014F1B2EULL, 
            0x2537F51E1D231CB4ULL, 0x1429491162233575ULL, 0x40C5500F08FD3348ULL, 0x569906EE30658E17ULL, 
            0xC4EE87222473F5E1ULL, 0x67F77F8170E1E50EULL, 0x2F3DE57E07A76C81ULL, 0x2125F05800B51B12ULL, 
            0x996D77938EC7AA47ULL, 0xD0DE450A1B02FE4DULL, 0xEC5C4454703F4858ULL, 0x67F17B020BDE188CULL, 
            0xA3F5A5A73D224D5EULL, 0x02F84B032F0187A2ULL, 0x1009036241F3A066ULL, 0x77106BE518171467ULL
        },
        {
            0x212B123520FB3099ULL, 0xB30C0DB824B4710CULL, 0xE407F05C1B52DCFFULL, 0x7CF1E27DCAAB6AC6ULL, 
            0x79571DAB944308A7ULL, 0x98F055CA44194B2DULL, 0x12EE00DF6BF1D420ULL, 0x713121DE3EF31E94ULL, 
            0x1D0D56495C4A2AC5ULL, 0xCA215319C56B0F36ULL, 0x764130D565AEBCF1ULL, 0xFF26454BD2C6DD6BULL, 
            0xD9FE6B9D0F8ED0C1ULL, 0xAFBFC28745E49C9CULL, 0x9BC7535A9F398823ULL, 0x6DD1B7BFF92DF9C8ULL, 
            0x1B0DAFBD8573F093ULL, 0x2C66AC0C32D73895ULL, 0x24DB24DD00EDC12EULL, 0x962A1A341B0E23C7ULL, 
            0x9BD2D73C11443CD8ULL, 0xC7BDCAD12A390377ULL, 0x2872EE5B06BDD9CEULL, 0x78916A22943E1A86ULL, 
            0xC242524E4FA817F4ULL, 0x3D64AD79CA6743FCULL, 0x2FC5C57DE4BB0E26ULL, 0xFF7A836048829060ULL, 
            0x36767243C1AA56A4ULL, 0x9F4BA778D33F3131ULL, 0x4ED570A1C5E0CBD7ULL, 0x33977A5642F1734CULL
        },
        {
            0xBC4D7FEADF83B059ULL, 0x8A034297ADB7D5DFULL, 0x2C73CF5A3B233797ULL, 0x3F20FDA122DA7F23ULL, 
            0x235BD43A7704814EULL, 0x4186822E20A3161BULL, 0xA7C9B71EBC2B3809ULL, 0x546E5DBB8D8BC5A4ULL, 
            0x26E27400913E98D4ULL, 0x00F2CF0511D8C52EULL, 0xE49F54B2903B068EULL, 0x767D8F89922FD517ULL, 
            0xE8DFA7600E552581ULL, 0x8D04BB46E4370734ULL, 0x8230BCCC005B1032ULL, 0x401395A77D9E109FULL, 
            0xD20EDD722B7CA4DFULL, 0xCD6FEC27AF7A75A3ULL, 0x7CF3137574DDCD33ULL, 0xF38AF44DB51FABC8ULL, 
            0xE79555127574CC9CULL, 0xE8BAA6C45C08CBD4ULL, 0xBA03FA27087C2BECULL, 0xE03890EF578EAD1FULL, 
            0x98E9E422B20776D5ULL, 0xEBA15D2A9F45A5F7ULL, 0x0539890411C35650ULL, 0x7D852A2E3D2822F8ULL, 
            0xFE1643C8C75A7C8CULL, 0xE76C63C22FC7CD96ULL, 0xC8A8D7DA9C9DB985ULL, 0x9A881E4B22357CD3ULL
        },
        {
            0x1A18F54409946447ULL, 0xF77381D60CA083F3ULL, 0xA086198CC0AE7FCAULL, 0x5CC355CA950369A3ULL, 
            0xBDF6DBFA80251B69ULL, 0x1F5CE8D50FDA548FULL, 0xBBDFA7AF2296866CULL, 0x95D48D55E244A7DCULL, 
            0xDFB15C40E8A474F7ULL, 0x66D95854B534B7F7ULL, 0xD14984A99C3DB552ULL, 0xCA1DA63D0C15287AULL, 
            0x78CC8CD84F08D4E7ULL, 0x051E02B7B0DE28E6ULL, 0xAB4AE6ADC1CE8342ULL, 0x8C238308F8CE1FA2ULL, 
            0x1A400855745185C9ULL, 0xB9764027F18BD878ULL, 0x8A81ECCD5C0BBFB4ULL, 0xB478AFD2D82C077CULL, 
            0xE97C06F7D3E73404ULL, 0xA1ECC7AE57404155ULL, 0x5479E3AA8D21FDC9ULL, 0x3EEB77CD33D2A5BEULL, 
            0x7FE803EC11C129DDULL, 0xA598247675011067ULL, 0x7B66198CEDCA8C97ULL, 0xDF86E0AA37ECA7C6ULL, 
            0xE24917AF1CE98F97ULL, 0x036AF439BED18691ULL, 0x63CAD8DDF9B36612ULL, 0x347849B7C5F7065DULL
        }
    },
    {
        {
            0x5A5A769058F3A98BULL, 0xED6BFCBF40FA9B4CULL, 0xAC73ADF9E00A87E4ULL, 0x7190BC2CAC9E8BFAULL, 
            0xB3C802FC0173721EULL, 0xD28F8BF7DA27AE39ULL, 0x5760E60F24B885B5ULL, 0xF8107498BD052E02ULL, 
            0xCAC635B596512176ULL, 0x721563D9AD8F647CULL, 0x906222C5FD80F87FULL, 0x7F2235175E92FB42ULL, 
            0x174B1F29BCA363BBULL, 0x54EEAEE0BA6898D4ULL, 0x04E4AAD4D6F08AD5ULL, 0x009840E7BF381C8BULL, 
            0x71809FC14F578C58ULL, 0x317192AA6FAC48C2ULL, 0xE9396F082756AFA9ULL, 0x1D74B16FAC4D3804ULL, 
            0xBBE0E0A08F69995CULL, 0x73495E4DE95EC5C8ULL, 0xAF6B842FED485A6BULL, 0x2DFE29AE21FC1B8BULL, 
            0x0FF85EF53BB90409ULL, 0x5ED678C746F7D362ULL, 0xD91223F33F96D7CDULL, 0x86EBC8714A47BBACULL, 
            0xBBF16FA245D2E122ULL, 0x73A45B7DBBEBE339ULL, 0x9CD9BD6DD97AD4A8ULL, 0xAB9DE1469670D4B6ULL
        },
        {
            0x61B2ECBC7AE43147ULL, 0x47F219B7DA1A6BB7ULL, 0x3AD4609562F1BDB9ULL, 0xDB7859B02E97C1ADULL, 
            0x456E2F120B3D58F8ULL, 0xB36EE970DE6E8D46ULL, 0xB7C4809FC65FD03FULL, 0x3815444DF0BD4E1CULL, 
            0x8400767E53DDD1D5ULL, 0xB91C7449036C0D77ULL, 0xDE8776FEB4EFDE3DULL, 0x00652AAD928EB17AULL, 
            0xA6E4B6990293D2E5ULL, 0x24B692CA61A65761ULL, 0xC836F1E51565D54AULL, 0xCE763EB6CB248F91ULL, 
            0xC4828EB83BD651A4ULL, 0xA60A1282B65A1A1DULL, 0x5BAF77E4AB7F1447ULL, 0x23AA817BFE430CCDULL, 
            0x7C5F7A8C51759556ULL, 0x24381643E1AD5C41ULL, 0x1C3F88F736CC4345ULL, 0xA91889BE6D6A3602ULL, 
            0xC454C270824DCA10ULL, 0xBE1871D31D3CB225ULL, 0xF087785EB7DA80EFULL, 0x6AB2396F47130690ULL, 
            0x5DE09D350F27D2FDULL, 0x21A89556EF13AD32ULL, 0x53FAE9B69700AC18ULL, 0xAFED1C7418F11002ULL
        },
        {
            0x7D0C1D01AA82A644ULL, 0xC30CE297564FFD89ULL, 0x4FCD7CECB9863030ULL, 0x9789BD3A5BE0A89FULL, 
            0x95F5E3C878072201ULL, 0x8DCC3EFC59EDD70DULL, 0x14FB6C76782CD92DULL, 0x2B83282A7AC8D6C0ULL, 
            0x3C7F378D05D564E0ULL, 0xF67E5A152BB42D2CULL, 0x211FC26D40B5BAF4ULL, 0x06397FF042BE3BB7ULL, 
            0xC7379383FA53C61DULL, 0x114DD42C417ADB1BULL, 0xA4D6B6E4A35544F0ULL, 0x18658A22942A9373ULL, 
            0xE8FF1443C00F7386ULL, 0xD6D3CF87F9DD8A7CULL, 0xD288465085C2850CULL, 0x6F0D8550A8DB90EFULL, 
            0xC0260315AE256A45ULL, 0x736E3824FEFCEA60ULL, 0xE4F5F1CB8C1CA449ULL, 0x1EC19917891618F0ULL, 
            0x3FA308A951C29AC7ULL, 0x85B4618CCD51EE17ULL, 0xFFB528A88996D282ULL, 0xBAB6635B6C4D6B4EULL, 
            0xB26FA128B6D8EF11ULL, 0x7A4AF8E2CD6D32F6ULL, 0xA6206E6FCAA1ABD4ULL, 0xDCAEEF0A20FFB6CEULL
        },
        {
            0xEE1FF73701DD8813ULL, 0x7BB1FD3A281820BEULL, 0x3B53F0C71E9E8698ULL, 0xFCBF84B12D89E0F8ULL, 
            0x9ABD7ED2F87215A1ULL, 0xD1D3B18B3CACDE7EULL, 0x1FEACE24463CF123ULL, 0x541B0DE2FB1A3FC8ULL, 
            0xC6D3E92C03CCF99DULL, 0x1A037468653BF8F4ULL, 0x27536B15892CDD40ULL, 0x0C95B1BB49E734E3ULL, 
            0xDC9D812B49B8A0D6ULL, 0x7DEA44656910FFF0ULL, 0x767E476D26DE2530ULL, 0x686744ADAD159431ULL, 
            0x1D2BBA8EAE86B6A8ULL, 0x763A1CAF3C30466AULL, 0x7862F4BC67192E29ULL, 0xF61299BF54D84F75ULL, 
            0x37EEA8B1E30FDC09ULL, 0x25E478F89A448AFCULL, 0x62D616E9A4AA5C51ULL, 0x3E00A98B167997A9ULL, 
            0x5F7E14596036B742ULL, 0x67FBF2FAB5B6B6C9ULL, 0x850564A757C3372AULL, 0x8C9784C6F143DF20ULL, 
            0x273FEEFB1C52EE6EULL, 0x7EAC12A6131F8DDEULL, 0x0277D8DD85B9FA0DULL, 0x4A7E47DC84E4CAFAULL
        },
        {
            0xE46C7AF490D71F08ULL, 0xBD9B31101023158BULL, 0x892C9EF6B0F69778ULL, 0x0ACDA7D8FC401604ULL, 
            0x291DF2023597000DULL, 0xDFB1E895A4A1773EULL, 0x02D384E306BBE149ULL, 0x6DB3E08EA0F2AF9BULL, 
            0x5B84685549AAD09AULL, 0x86DC378B0C1BD542ULL, 0x4F262ED338945C44ULL, 0xF13BB5B3BCCE08FEULL, 
            0x382845467A767449ULL, 0x6BFA5A956D9339E5ULL, 0x0903207786912C76ULL, 0xE98B1F42FFA14AC3ULL, 
            0xC73CD291DD04DA89ULL, 0x4E5D5319DB2D4F4BULL, 0x66D5493DEDA694EBULL, 0x20D3D26B5E48E2E9ULL, 
            0x8CF59A72B8DF1DA4ULL, 0x8EE0CF7C2F61E10BULL, 0x49850DCB44551201ULL, 0x6E29F0CEA8CF0BCDULL, 
            0x9C77C82D2791C750ULL, 0xECE33E0A7DC185C5ULL, 0x2A6F365780926140ULL, 0x7035E7F2A3524386ULL, 
            0x32336A59FD801534ULL, 0xE636D20A21E04DA5ULL, 0x9F5E25C35B21C58FULL, 0x726F6137E175ECA1ULL
        },
        {
            0x3E8A7EC191699844ULL, 0x94490DD1E7299FA0ULL, 0x2EFBA9D4233C9DC2ULL, 0x61B5F6638618A83BULL, 
            0x5F95F67080C310BAULL, 0xADDCF1D6C99B01F2ULL, 0xFF74FD212362D174ULL, 0xE51B783FC4C02E7AULL, 
            0x05582B71584F85DEULL, 0xE0F69825C9B0E67BULL, 0xA4A72D8E806357B3ULL, 0x30F3C7244FA23604ULL, 
            0x62DA24821F8B48E9ULL, 0xF97CFF1B5FC0BE04ULL, 0xDE10D0411519E1A8ULL, 0xAFA462F2CD88BAE4ULL, 
            0xF2AB3913EFB8D53BULL, 0xBE6556E874656892ULL, 0x2F66B2545C6830F7ULL, 0x5234D0E8002A2296ULL, 
            0x3BAEC75EDCC8F9E6ULL, 0xB9202C86D45AC8EDULL, 0x1E6D6D83846976B3ULL, 0xFDA7358904C3FF64ULL, 
            0xC4A8FBC136AC9E2FULL, 0x30B88830DECCA5B3ULL, 0xF19188EBCAADC6EDULL, 0xD1F7AA53930807F4ULL, 
            0x8B6CD172E4674C56ULL, 0x6FC451D3D99B6035ULL, 0xF62404A60105B51BULL, 0xF8F1CDD24820646FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kTwistConstants = {
    0xC3CC0058AFAFB241ULL,
    0x6501EC3F54D85D5CULL,
    0x0D605B8A3C9D3D76ULL,
    0xC3CC0058AFAFB241ULL,
    0x6501EC3F54D85D5CULL,
    0x0D605B8A3C9D3D76ULL,
    0xE6F0A74FCB34DB33ULL,
    0x3D9F64DD2499FA7FULL,
    0xB6,
    0x0F,
    0x62,
    0x40,
    0x0F,
    0x46,
    0x5F,
    0x88
};

