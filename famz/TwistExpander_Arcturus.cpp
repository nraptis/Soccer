#include "TwistExpander_Arcturus.hpp"
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

TwistExpander_Arcturus::TwistExpander_Arcturus()
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

void TwistExpander_Arcturus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Arcturus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE2835B35C78EBD5BULL;
    std::uint64_t aIngress = 0xAF1ED07CE2126C75ULL;
    std::uint64_t aCarry = 0x9CDE0CD5FCFD03A0ULL;

    std::uint64_t aWandererA = 0xD5A48A44DD315611ULL;
    std::uint64_t aWandererB = 0xEEEBB61CA1961715ULL;
    std::uint64_t aWandererC = 0xBEBFE158C8540CCBULL;
    std::uint64_t aWandererD = 0x86D4DDA12805FDC9ULL;
    std::uint64_t aWandererE = 0xE84D65883A907D8EULL;
    std::uint64_t aWandererF = 0x984D5868C60867F7ULL;
    std::uint64_t aWandererG = 0xB22E7DD093B26F0CULL;
    std::uint64_t aWandererH = 0xC02AEAA3E04730E7ULL;
    std::uint64_t aWandererI = 0xF3DF80D934F208E3ULL;
    std::uint64_t aWandererJ = 0xB6EE9E52DBF30BB5ULL;
    std::uint64_t aWandererK = 0xC08007E1CBEB4B61ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xA39E569E5F72338FULL;
    aIngress = 0x873D1B5A9507F454ULL;
    aCarry = 0xF15A4545D97BFEEFULL;
    aWandererA = 0xF21B8649CFC55E3DULL;
    aWandererB = 0xA59CF8F70768FFAAULL;
    aWandererC = 0x8AEE68306110B4FAULL;
    aWandererD = 0xC422FCD15C704581ULL;
    aWandererE = 0xEA6411C5F89B98B8ULL;
    aWandererF = 0xA0EFE26BBD0E684BULL;
    aWandererG = 0xA0E0D3EA34EFE882ULL;
    aWandererH = 0xDF0C31E98861B6B3ULL;
    aWandererI = 0xF5E252E9B08FFE81ULL;
    aWandererJ = 0x8208437D1ADB50DBULL;
    aWandererK = 0xE85A967B5C5E3866ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xC45B4B6B3F50531BULL;
    aIngress = 0xF979090C186BEE52ULL;
    aCarry = 0xC693053934E82FBDULL;
    aWandererA = 0x8979497B9E56413FULL;
    aWandererB = 0xBCBA362AB17DA577ULL;
    aWandererC = 0x8FC31204002F1127ULL;
    aWandererD = 0xD1D7EBA3D4C95831ULL;
    aWandererE = 0xD29FBDC3B6AE7CEFULL;
    aWandererF = 0xE4A2B10C0223F53CULL;
    aWandererG = 0xF0937AB943152C53ULL;
    aWandererH = 0xC87A8CC182FC0231ULL;
    aWandererI = 0xAFA4E5C21C1117B6ULL;
    aWandererJ = 0xE062C881AD0B57CDULL;
    aWandererK = 0xCC0C53F5656E0CADULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x8122B8C43879912EULL;
    aIngress = 0xEB8022D2F1D12992ULL;
    aCarry = 0xA3C7746420220E95ULL;
    aWandererA = 0xB4059CA20918D060ULL;
    aWandererB = 0xA339B73FA14F095FULL;
    aWandererC = 0xFCEF5742B38755B8ULL;
    aWandererD = 0xC3BB6FA035B6C95CULL;
    aWandererE = 0xADBA76EFD4D5D22CULL;
    aWandererF = 0x9244595758AAF470ULL;
    aWandererG = 0xBCD2526499059B70ULL;
    aWandererH = 0xCB796A776C50C020ULL;
    aWandererI = 0xE4AF13F0E8163A7BULL;
    aWandererJ = 0xA10A918CFB6A9ED2ULL;
    aWandererK = 0xD9529CA3ACEE204AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD7BE2F0C1CAD6249ULL;
    aIngress = 0xC54CDAB26C0FA0A6ULL;
    aCarry = 0xC77994E359044808ULL;
    aWandererA = 0xC63BC90FA3EE5629ULL;
    aWandererB = 0xC31CDD9C4EA61626ULL;
    aWandererC = 0x96C721F768562FDEULL;
    aWandererD = 0x8C8B619592E08B2AULL;
    aWandererE = 0xAAE6D7B46951242EULL;
    aWandererF = 0xBE31C380191654A5ULL;
    aWandererG = 0x9E99E4806EC95C22ULL;
    aWandererH = 0xD4F9363E6EC5E502ULL;
    aWandererI = 0xCCEF7EC80FDC02CDULL;
    aWandererJ = 0x813AD91F67191699ULL;
    aWandererK = 0xFC137D5A72EF1FA5ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xF8C1046D4F6A7108ULL;
    aIngress = 0xA308AB966F80FA76ULL;
    aCarry = 0xD851BD880A40ED48ULL;
    aWandererA = 0xE38E7D458C326906ULL;
    aWandererB = 0xC429793CA7EBF3D2ULL;
    aWandererC = 0xE3FC1A7092668999ULL;
    aWandererD = 0x8FE8A1F05F49AC0CULL;
    aWandererE = 0xAAC21DC6E5DDB597ULL;
    aWandererF = 0xD8A2ABE7A680F7F3ULL;
    aWandererG = 0xDA36744BCC96FEA6ULL;
    aWandererH = 0xEB85B8CC6072B0E3ULL;
    aWandererI = 0xAFCB8F90F85A7CD2ULL;
    aWandererJ = 0xFF676FACE257DD6CULL;
    aWandererK = 0xD217207A5481509CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xC3E5C6497DBF2536ULL;
    aIngress = 0xC3890E5CC60FE863ULL;
    aCarry = 0x9A1CA0A126476BAAULL;
    aWandererA = 0x865690A8BEB656A9ULL;
    aWandererB = 0x8BF164AE5569AB57ULL;
    aWandererC = 0x85E03ADC19999699ULL;
    aWandererD = 0xA15637211F9C6E18ULL;
    aWandererE = 0xEFC929A5A7216F69ULL;
    aWandererF = 0x96D774E098DB04F8ULL;
    aWandererG = 0xF84D6F8A311D5241ULL;
    aWandererH = 0xD84E53CC5878F0D9ULL;
    aWandererI = 0xAE560BDD3E828A84ULL;
    aWandererJ = 0x8AD8B65F8F5EBBB8ULL;
    aWandererK = 0xB3B911D22EF6A218ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xCB84A7E6D7AFE212ULL;
    aIngress = 0xA32522DFA6943C7CULL;
    aCarry = 0xBB071D0DDFCAB54FULL;
    aWandererA = 0xC4295EED21B0C2B9ULL;
    aWandererB = 0xD75A38FF807BC0BFULL;
    aWandererC = 0xA4439257BEFA5BC6ULL;
    aWandererD = 0xECB51BD7BD2C0CACULL;
    aWandererE = 0xA6A0422F010AB1C4ULL;
    aWandererF = 0x9A81AAADF4F7D833ULL;
    aWandererG = 0xBB807FB8BA34C1E8ULL;
    aWandererH = 0xB87689C32C0072BCULL;
    aWandererI = 0xDA11BAA674F41C13ULL;
    aWandererJ = 0xE0C1AB0FB55E6457ULL;
    aWandererK = 0xA29D938607DD6F10ULL;
    //
    TwistExpander_Arcturus_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Arcturus_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Arcturus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x88CBB399E4165741ULL; std::uint64_t aIngress = 0x86A6CD37F81C5CC4ULL; std::uint64_t aCarry = 0xDD8FE6F70063CE8AULL;

    std::uint64_t aWandererA = 0xC1BA6382465BD78DULL; std::uint64_t aWandererB = 0xDA4072B8284EFF6BULL; std::uint64_t aWandererC = 0xA0FC97C0C4398AC0ULL; std::uint64_t aWandererD = 0xFCAD2259D7F3C425ULL;
    std::uint64_t aWandererE = 0xD9554D0A240AC30FULL; std::uint64_t aWandererF = 0xE0048B8019705A98ULL; std::uint64_t aWandererG = 0xFAD65B426F9D091DULL; std::uint64_t aWandererH = 0x9328EED4D268AED3ULL;
    std::uint64_t aWandererI = 0xF952811624F685F4ULL; std::uint64_t aWandererJ = 0xC4442202EE909DC1ULL; std::uint64_t aWandererK = 0xA1D78B11348265B9ULL;

    // [twist]
        aPrevious = 0xD31227E15A0CD508ULL;
        aCarry = 0xEEE06FC98FC5AC59ULL;
        aWandererA = 0xD54E59CE93648F18ULL;
        aWandererB = 0xAC6C24D62DDF0F3EULL;
        aWandererC = 0xC01DFB3D3D377477ULL;
        aWandererD = 0xB871433A3D74AC82ULL;
        aWandererE = 0xDAE5E7F3D1789E11ULL;
        aWandererF = 0xD2E9ECE7F97593FDULL;
        aWandererG = 0xB3C24ABECE79A5F0ULL;
        aWandererH = 0xF419D8A1BE0F1E9FULL;
        aWandererI = 0x8D6AFC54E8D93D03ULL;
        aWandererJ = 0xE933C83C2A293475ULL;
        aWandererK = 0xFF34D0CAB2F94CE5ULL;
    TwistExpander_Arcturus_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Arcturus_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Arcturus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Arcturus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Arcturus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 10 of 33
    // Exploration cases: 0
    // Structural maximin 540 / 674; family total 4936
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1780U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 10 of 33
    // Exploration cases: 0
    // Structural maximin 536 / 674; family total 4906
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1060U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Arcturus::kKeyRotateASalts = {
    {
        {
            0x9CA5B76B1C507AA2ULL, 0x5F04B8E1FB64FEBFULL, 0x5F740D3EC71FFD6EULL, 0x598B44710081EA53ULL, 
            0xEB3A9480383EB2F0ULL, 0x10FBBA8DAE559031ULL, 0x0BA669E361545A56ULL, 0x88DB3B4FE49D3FE5ULL, 
            0x904744E7DAAB0F0AULL, 0xE45617D65051749BULL, 0x2CF7BBFDEFCF9F1CULL, 0xFEC3B7127520231CULL, 
            0x3C743DDC291FC93AULL, 0x36F02E983330CCA4ULL, 0x819638CF337A642DULL, 0x74EF04ED1EE181D7ULL, 
            0xE7AD5C02326B1A49ULL, 0xEAB7968F6CD4ECEDULL, 0x4CB1F4CD1C4A8D25ULL, 0xA4B693263CADB160ULL, 
            0xDC10A25E2D6CCDC3ULL, 0x8795E538C12B2FEAULL, 0xEAF828FA4F34AE7AULL, 0xE19C387A587966A6ULL, 
            0x8AB7179392AF1C03ULL, 0xC86D8170B33AEEA0ULL, 0x0C5DB9C359DFFF1EULL, 0xC28F62CDD7AE20C0ULL, 
            0xC364C8A88DE55134ULL, 0x87B72AD57E3AEE1FULL, 0x20E19483933FB3F6ULL, 0x622CD83DDA021080ULL
        },
        {
            0x916D9D574200092DULL, 0xDF8457A6E8724F04ULL, 0x574D79293AAB0C21ULL, 0x565F27EF281B8525ULL, 
            0xBD51BC5746A5C8DEULL, 0xFC14DEA5A36E8B7DULL, 0xED966F91C7D4B8D7ULL, 0x06E880858248FECEULL, 
            0xCEA719B75794D319ULL, 0x01FC80358BEF017FULL, 0xCF46A1A5911FA30BULL, 0xE12C3A53FF779705ULL, 
            0x2254D97CCE4AC6ADULL, 0x36CC1021EA775BC6ULL, 0x25DA8CF321F85873ULL, 0x6057767C0229B29CULL, 
            0x839E3E146D58155FULL, 0x2A1977EAD607550EULL, 0xB55B9451AFE2600FULL, 0x9E0DDD4B82067B56ULL, 
            0x1AEACBFF93A2CC72ULL, 0x799E3EF4BB1DC8BCULL, 0x9BA5FE54AE869D0CULL, 0xF727669A332F1483ULL, 
            0xEAF2725F0DCEC7B3ULL, 0xAFA5BFCD80D59F5FULL, 0xB626A9A1C974EA0DULL, 0x06324FA39899837BULL, 
            0x7F0BAAAB239A08C7ULL, 0xA33029AB3C6652D4ULL, 0xF7FF8A5B011A8F68ULL, 0xC3D0E259F35B8DEBULL
        },
        {
            0x12F58D134032964FULL, 0x4691133EAB6EF94DULL, 0x92644B2F369F8CDBULL, 0xB236F8E8F9914053ULL, 
            0x2AE3F7C2B1F8BC9AULL, 0x46ABF8CF7D23C852ULL, 0x439D2E4495354E7CULL, 0x418FC89890AC3FECULL, 
            0x14080869F6992085ULL, 0xBE71B5D91AB43574ULL, 0xA32478BB2BFD606FULL, 0x8BFCC73257D96152ULL, 
            0x0F6510803C3A5D79ULL, 0x8FBB516BF4419ED1ULL, 0x3E232A667808A650ULL, 0xA9E373DB7E9872E9ULL, 
            0x3CCF26D5D0C52C3EULL, 0xCBAC5F251AB806CEULL, 0x7E21C4882C3F762EULL, 0x5D4EDCECACB0ACF4ULL, 
            0xFD4A0A7197EA5F53ULL, 0x3EE16CC7EC6AB7DEULL, 0x7514FC0B729BACD3ULL, 0xEA399264BCC3FC07ULL, 
            0x9F8BE3F1608D7C05ULL, 0xDA542661D21B07A7ULL, 0xF2FBC65CEA65DFBFULL, 0x0E7F084D5F792AC1ULL, 
            0x373DFE8E95B2CA27ULL, 0x7A5605DA6E2C45DFULL, 0x1FB3018D462AC6EBULL, 0xC86BED4E4D006433ULL
        },
        {
            0xD542531D425A3A08ULL, 0x2662E0E3CDDDB4A2ULL, 0xBE03927CF447D709ULL, 0x690F68B5B611D575ULL, 
            0x5DD71EC5FD25ADDAULL, 0x31AC56023CD87904ULL, 0x812505468A317543ULL, 0xBA0731770D922094ULL, 
            0x59158A33D52C73B1ULL, 0xBC2DE0E41ABA76E0ULL, 0xC4176E4D84FF88F0ULL, 0xE6C58EEF1976B425ULL, 
            0x2B78C1954504439AULL, 0xD9E6F81F8FCC01E3ULL, 0xC0F4DFD6638C1788ULL, 0x060404440125D59AULL, 
            0xDBB1A36D72EE2F6CULL, 0x89D5084F6D3DA798ULL, 0x39C7F7CFAE666C19ULL, 0xAF13FC04DEA75FA6ULL, 
            0x3A01B0A2D757658BULL, 0xD6E91D3EB55BDC87ULL, 0xD50656B00E39B8D2ULL, 0x4D980B97D5A9F907ULL, 
            0x41E1D576826F852AULL, 0x90A9520AF9102D9EULL, 0x8D124DCB9C71FB3FULL, 0x561F18ED6F419D6DULL, 
            0x6AAEF902D2F0E5F1ULL, 0x1C62D8686AE120AFULL, 0x08BF001367E4D8AFULL, 0x3816F1BD01649772ULL
        },
        {
            0x406189CF3664D1E2ULL, 0xD17A70FA090C6A33ULL, 0x6E5DAE450CB629B5ULL, 0xE918D4D74B6EDA4AULL, 
            0x16CE0A260557EAAAULL, 0xA7C4B4842F3350DAULL, 0xFAA100A6B72EFF5FULL, 0x0EE9C9AF2BBE5FFAULL, 
            0x71CF7976345FF636ULL, 0x944C14C31D3DEEF7ULL, 0xBC5AAB35FCD41E82ULL, 0x4091A7400DDA6720ULL, 
            0x37C05B902ACA26C6ULL, 0xF3763E18C3450C27ULL, 0x3FB5421F4120DD1CULL, 0xCB44770D133ED6FEULL, 
            0x1827F71754B1A3EEULL, 0x578084DB4ECD0CA3ULL, 0x7265C417BD146850ULL, 0xD11684DEEDAC2DACULL, 
            0xD9DE3F851DB20AFAULL, 0x2E7588685204B367ULL, 0x985A3EAB30A9B800ULL, 0x023776AAEE27F51CULL, 
            0x5B3333B87BE8C59EULL, 0xD543350C60FD2AE1ULL, 0x7CF7ECB1DE5AE920ULL, 0xBB947052A959B2A7ULL, 
            0x1B243C6D07ECC10BULL, 0x6961558E7B1681EBULL, 0x83242BCA42F01386ULL, 0x81F9F5CABCE0B578ULL
        },
        {
            0xAF6B46D9B9B56E6BULL, 0x7569EFC972151B7EULL, 0xE959693F4F61267AULL, 0xC8F424CC3F1578F5ULL, 
            0xB806B121E92CF770ULL, 0x3151E521E1A58174ULL, 0x0CB11A008AABB580ULL, 0x4B3DCA796D9FBB4CULL, 
            0xFE52AEE005721566ULL, 0x7275F1405B04A43EULL, 0xA307E3E847F3DD30ULL, 0x65173AE80AE77FE5ULL, 
            0xE98B33637AA86CB1ULL, 0x65C864CF9EB36E91ULL, 0x5776D1FAEAC3367CULL, 0xCCDD033390BCE61AULL, 
            0xFD00F3AF345053F6ULL, 0xB9D4754EEE432E93ULL, 0x9C3F074B29A7F4E6ULL, 0x5E4E7DDE01343743ULL, 
            0x9ECB53BABDF85EF6ULL, 0x3E19D85B42AE2799ULL, 0x1958E873ACE35BFEULL, 0x0EE7ACC02848198EULL, 
            0xE812526956A8C4F4ULL, 0x936937999C0BBFB5ULL, 0xDEEA9CBC828D3C61ULL, 0xFCBB852FB4C60B26ULL, 
            0x58412B44641072F5ULL, 0xA3EC280038F348B2ULL, 0xC9DF210A5681AE70ULL, 0x2BAA46756CCE7B96ULL
        }
    },
    {
        {
            0x1594C0D1D697BCD2ULL, 0xE1B2D74E65B7C913ULL, 0x77C0D9001A31E09AULL, 0xF7E25D8D189746A3ULL, 
            0x41C3372F9CB1D447ULL, 0xB38D56311BA58412ULL, 0x8E60FE80BE9C24A2ULL, 0x5DF8206FD9A7953EULL, 
            0xAB6698BB322B0167ULL, 0x7CD5A4FC34A51F0EULL, 0xC7C042F5DCD686D8ULL, 0xCBBD6CC0AB343B49ULL, 
            0xCF401EA3FE052093ULL, 0x5D0CB9CD07FA3F8FULL, 0x0ADE3001D98FC89DULL, 0x2562C4C6BDC869DFULL, 
            0x79EBCE55AD6D63C7ULL, 0xD31D8012B513EC02ULL, 0x03D05CB28350D552ULL, 0x5DF25CBA2C512142ULL, 
            0x818ED555E7A24B88ULL, 0x4BD199C941458E2DULL, 0x788296B5386B2E47ULL, 0xA797EEBCA3BA6B4FULL, 
            0x6D04763A7092C48CULL, 0x6F0749E3A1C830E4ULL, 0x1A4A23907DFA1CFCULL, 0xF4AFBBD8699A2326ULL, 
            0x31DF468AB8275F14ULL, 0x1D1405D555F1A2F5ULL, 0x0D58580013623EE8ULL, 0xFF08F965B56CA77DULL
        },
        {
            0xB8498ABD4AFFAD09ULL, 0x06FE3FAB23A88BD1ULL, 0x7F463E07207F39D9ULL, 0x55490EFC93A901D4ULL, 
            0xC97F31230FF383AEULL, 0xAD73C9D9B0DC00CFULL, 0x27B3DF5783E15C07ULL, 0x8A4FF8860B687690ULL, 
            0x455DB82AB5676F0BULL, 0xA38CE0CE4216985FULL, 0x5A828FA72BE59C01ULL, 0xF0B9D60AD83D8938ULL, 
            0xF6B0909F76FA8801ULL, 0x0A177C4A7767087DULL, 0xC33867064E897F3DULL, 0x8A567DD6F27A923AULL, 
            0xC9F5D492E7BE4855ULL, 0x24BD464DE6DD5769ULL, 0x8A6CFDAD81767DCAULL, 0x9C0F434E06461CE7ULL, 
            0x4C548501383B6209ULL, 0x7C5018F58C00B63EULL, 0x2BE72F9969675BDAULL, 0x0948B85150208A2FULL, 
            0x1CC997E706396E1EULL, 0xAF52837B608FB72EULL, 0x38A464994D82532BULL, 0x701A12C33A10A6ACULL, 
            0xB2ADAB6CA7CC0878ULL, 0x935E9810B9E72E71ULL, 0x86FA123A0BC6CB46ULL, 0x63FCE6FDA61074F6ULL
        },
        {
            0x4A8464558C9D8A04ULL, 0x1A17DFCC96D27434ULL, 0xDEEE67247BBCCDF4ULL, 0x37E456215EFC73C3ULL, 
            0xED794512BA2113E5ULL, 0x04DF3DC77DB178AFULL, 0x6AC9713F57D114DAULL, 0x1BA8B0897EF87E72ULL, 
            0x53E03601A7ADE057ULL, 0x89B8F50E78467C37ULL, 0x078B8FF88A896AB6ULL, 0x13E1F253F675D5C1ULL, 
            0x971251FBB3DB68C5ULL, 0xC229F4CFB75DFFFFULL, 0xEA4B0E940402ECEFULL, 0x056BE8527E6B3E53ULL, 
            0x9D48EBFC3A3CF574ULL, 0xB4389EEF3C35A6C3ULL, 0xCDFE6B9F6889553CULL, 0x08016F7C58FC5732ULL, 
            0x5ED0673851BB136FULL, 0x308D6032D68CA409ULL, 0x4D280CC6E3201A06ULL, 0x18CB495B8EEA9C40ULL, 
            0x5CB8CF5C7E11F45CULL, 0xE3B53D7B9BC941C0ULL, 0xAB4E6DD42ACDA5CAULL, 0x08BFE355BE9DEBE7ULL, 
            0x760A6F05B93D5A51ULL, 0xD619E30E9C05FA53ULL, 0xB52534111FE789BBULL, 0x474F15430A474428ULL
        },
        {
            0xCAFA6DCA4D48F948ULL, 0xE4DA3D5CE2A9646DULL, 0xE2AA5B13080A7A1CULL, 0x458FAF697E2229BCULL, 
            0x340C46DE71315319ULL, 0x822D66EF346FDDB6ULL, 0xD5BC00372A891E02ULL, 0x0250EE7F3F5549B1ULL, 
            0xF811407F542F92E1ULL, 0xA7CDDCFBD7EA1E4CULL, 0x0C072BCE734E7CECULL, 0x1660852644E90A4AULL, 
            0x4B235FFC962FDAFDULL, 0xB1E6CB20084FA57AULL, 0xAA9AAD8B439D53D8ULL, 0x5A192C200A0BDA22ULL, 
            0x7B1CDA1A2427C6FAULL, 0xD6C6911022603DDDULL, 0x6C8462D109C284E4ULL, 0xC4E0D684BAA80F2EULL, 
            0xB93129D356DFF1D1ULL, 0x58E6F458E80CE3B9ULL, 0xA3634CFA84F9394DULL, 0x453972C92261D3A1ULL, 
            0x5F73A25DACC5AB1FULL, 0xD5D884498597FAA2ULL, 0x5F194C8A1318938BULL, 0x17ACA9AE212E1FF4ULL, 
            0x428B3E77F0A41355ULL, 0xA533532C97EA0B6DULL, 0x659ED3EABA627D5DULL, 0x88D4E75A7C87B1BAULL
        },
        {
            0xC90F0AF373B7119EULL, 0x9D575F61EAB6295AULL, 0xDC666BD61C93F35AULL, 0x285272BA315B282BULL, 
            0xC5AA0B1157FB4794ULL, 0x55016CC350B72F3DULL, 0xA2FECBBF7F3C9CC4ULL, 0xED5A214156F88E12ULL, 
            0xDBF4EBAEFD05F43AULL, 0xD664EAE13406EECEULL, 0x487CEEE40B81422FULL, 0xAC61C32D83FA12D1ULL, 
            0x070E1A912D2B6769ULL, 0x346107C32B57AB1FULL, 0x9DD2BC367B296614ULL, 0xCA9ED2B1CF358570ULL, 
            0xA428B88C746F1CE9ULL, 0x746CE04808D3AF2AULL, 0x1704828884458717ULL, 0xEE4BDCC028C92267ULL, 
            0xC6338305F1AE27BFULL, 0x5A9422FDFFB2F8B3ULL, 0x810ED9784B108A8CULL, 0xDEAE6D0E0A92E16BULL, 
            0x501BD900F5F8694CULL, 0x3F7AD65173820BE2ULL, 0xC05DB8F6DC006E5EULL, 0x1E75381EE0E78E91ULL, 
            0x2A14A94128EC29CAULL, 0xE3F82866BC7C8F81ULL, 0x26EE959A900C5689ULL, 0xD2D70DDBA63F6047ULL
        },
        {
            0xA63BDE1328434FCCULL, 0x0F2E03ACF7CA6416ULL, 0x150AC6E9AD71CAA7ULL, 0xBEB1AA5BDCAA6A60ULL, 
            0x5090B501FA8AAA3CULL, 0xB7843E6F665B2FE9ULL, 0xFF78A30D1916F46BULL, 0x53D47E0F3908A0F5ULL, 
            0x12A310B175A4BF5BULL, 0x20C790DA8C065820ULL, 0xC1C257A99FDC9031ULL, 0x489C92CC822C72F9ULL, 
            0x709656FD2444BC30ULL, 0x7B24EC7A09F6E5B3ULL, 0x94F8DE698A40BD4FULL, 0xA552D977750AA541ULL, 
            0x15FB0428FC12A254ULL, 0xEE298B3DD25E555DULL, 0x0F2959D8FCCD054FULL, 0x78EDE9A9032A8D30ULL, 
            0x5FE5C114ED987DC1ULL, 0xE601857A75AC793CULL, 0x7D042292D731D626ULL, 0x775A422464F24B69ULL, 
            0x6FA6BF2E9273EF1BULL, 0xA612248117868E7FULL, 0xAE43FFE5ADF42016ULL, 0x1F11F765C355BC12ULL, 
            0x2482AEC2BDC161BAULL, 0xC2C59D683EF448B8ULL, 0x64BEEE0CBF1C1630ULL, 0xC891F930FD903AC7ULL
        }
    },
    {
        {
            0xCBE9DCB2A141886DULL, 0x8C711F5B273194B4ULL, 0xA9BB7AFCA858C530ULL, 0x000AC413AB0932ADULL, 
            0x23EAFCC369D950FFULL, 0xA7C1E20C1B9317C4ULL, 0x9A07F60C0DEAD967ULL, 0xC0F4794658B8400FULL, 
            0x0CAA3C59ED21A10FULL, 0x951F668A090D4E0DULL, 0xF81D41984A443860ULL, 0xA2366A6D5C528CB8ULL, 
            0xAEE54EB7783C81FEULL, 0xF75B60F1E07E2CC0ULL, 0x6C13D219B624E7AFULL, 0xD74B5888C934FAB9ULL, 
            0xDEB92DF5DE059D93ULL, 0xA7F3C9F5F35F0C81ULL, 0x27539F2F6BF9E456ULL, 0xE3AA48771E40D83FULL, 
            0xAA3EB60BA3D31E0BULL, 0x7DA3E2F87EBD6BF2ULL, 0x8B1A5DE86A829438ULL, 0x89A1F7373BB464C0ULL, 
            0x1593F7AA7B9B060DULL, 0x42708DB424D8FD96ULL, 0x49D68177ACDD94DCULL, 0xD5871B803954DE7EULL, 
            0x104B9152B4804682ULL, 0x483E23983A66FE86ULL, 0x1A1EC986EBB93CE7ULL, 0x77B9E152ECB1DFF7ULL
        },
        {
            0xA3EF3C639A700531ULL, 0x1331880ED069922EULL, 0x7BC38371A51C22D5ULL, 0x619FD85E0F29FAB8ULL, 
            0xF4D44DBE97FCD25BULL, 0xE1221A9846A9FEF4ULL, 0x6DCE19D1F144044DULL, 0x6D87685D7823A8A1ULL, 
            0x946EF4D101D6DA97ULL, 0x849C168494D01966ULL, 0xA04B937045BE4FE6ULL, 0xB1F13CD759CB80F9ULL, 
            0x4F0270697AD7F099ULL, 0x8EE50510DF9EE752ULL, 0x1D7265319B713F8BULL, 0x3ED0EF5AE0000AC6ULL, 
            0xA112B584E974E3E6ULL, 0x6C830A8D57E0FB37ULL, 0x15D269937484FA5CULL, 0x570A0762541812FFULL, 
            0x555BB86ED5CAC86CULL, 0xB7941B6D4710581EULL, 0xAA6D5AD3DB27366AULL, 0xA9465AF0D1730996ULL, 
            0x70E387131804625CULL, 0x858D75B43FEA178DULL, 0x9C8582F244A8038EULL, 0x8A166B47A08FE3F9ULL, 
            0x0D16773E03C081ADULL, 0xCE81B2DCFF3F62B2ULL, 0x8AA7DD78C6AAEF4EULL, 0xE16775ADF9EB8EF2ULL
        },
        {
            0xCA1170B6488AD928ULL, 0x651CE93BEA50C45EULL, 0x02973BC7E2270839ULL, 0xEA221520C8E80F71ULL, 
            0xD9D245E5EB58D211ULL, 0x0891C3F2DD8D0F0EULL, 0xF6B8A90C50536F58ULL, 0x0B0BB41FFA8C6DDEULL, 
            0x1EFF3B045A81086CULL, 0xA384DA248AF7C532ULL, 0xD0E5681A1540E8D6ULL, 0x3B4F8B42932A4B4FULL, 
            0xF108210E0DC56C04ULL, 0xD411EC5ED9D6142FULL, 0x34EEEF4840028F2DULL, 0x61CA7E2D54EB34D0ULL, 
            0x402E88951EF2415FULL, 0x1FD083F356DD8DB9ULL, 0xF6B343B4AFBA1798ULL, 0x986F7DEE2C5701A0ULL, 
            0xB985B8B6E6618EA9ULL, 0x29706459E45A6723ULL, 0x916F4FA0CE6DA987ULL, 0xB5B2107832FB2342ULL, 
            0xB8A10AAFD307D0F3ULL, 0x068CB7E92E734C20ULL, 0x247CFD1D101F7961ULL, 0xA3D11273D557758CULL, 
            0xF6F824025B0381E3ULL, 0xFC1687705A34DBE4ULL, 0xA8D2227339F7A58CULL, 0x02230339A467F354ULL
        },
        {
            0x962B7088FC63AB6FULL, 0xB08542BA44417356ULL, 0x40179FB0660E31ABULL, 0xF521B0D493EDDD40ULL, 
            0xF79C2A32FC53925AULL, 0x36901077FA6F7730ULL, 0x7D1D16FBA078C4EAULL, 0xA868082F62E714A4ULL, 
            0x118AFB8048935234ULL, 0xE9E369587108B474ULL, 0x32457E1AE7892C7DULL, 0xB57E90EC24C75EA5ULL, 
            0xF56EB14D1A69FA9BULL, 0x28DBC14CB16AAC66ULL, 0xB474D3CFEAD51A5CULL, 0xC663C4AC5A4742D7ULL, 
            0x8571C64EE3C409B0ULL, 0x2D85978B72CB28A3ULL, 0xDA86839439538C1AULL, 0xCDCD47E9583D2122ULL, 
            0xAA09268A03C3C590ULL, 0x233BD2C29A703932ULL, 0xCF00C80CCF0D6C15ULL, 0xACC6D808746A530FULL, 
            0x81FDC0DCBA201823ULL, 0x834685523E2B9870ULL, 0xD1CA207726374102ULL, 0xC47D76FDABB4919BULL, 
            0x067C94866BDFA0B5ULL, 0x9A9A3EFF67B75357ULL, 0x32D8E91A00F8FD3EULL, 0x2E24969E24196D77ULL
        },
        {
            0x0C246DF9F129197EULL, 0x70E271C1EEEC2B3DULL, 0xAD02BD2F24A1FCBFULL, 0x6549B888328C9E35ULL, 
            0x3FA009C662BAFC0FULL, 0xCC5365D864E8C076ULL, 0x17EAF893BCD0439BULL, 0x07DCF933CC5F1F1FULL, 
            0x5E0FCA30CEF7ACE4ULL, 0xE0E867A2D4244C77ULL, 0xEACA60DF1E72716CULL, 0x3520891931863A17ULL, 
            0xB6AA181DD73A6122ULL, 0x2C11C2DEF5886409ULL, 0xF9F4000749659BABULL, 0xBFA63C1C83DEEC0BULL, 
            0x35CEAA06A8B1262AULL, 0x2EF3D44F20AD0A6CULL, 0x45B4EF4D75CAF04DULL, 0x5456473AAF3B0687ULL, 
            0x7D20229D12DD51EFULL, 0x83BADBDBDDDE0CEDULL, 0x4DA8F1BAF7999FF3ULL, 0xD263F87E4B3E0D66ULL, 
            0x9DCDDEBBEBBC2654ULL, 0xFEE92DF090BC405DULL, 0xB50F2D23833036B3ULL, 0x83236C063520FA42ULL, 
            0x3AACB7444E864248ULL, 0x4895DE4F35D2F533ULL, 0xBBEDAE000E41F7E4ULL, 0x09499654719DE691ULL
        },
        {
            0xCFFEDA0FAF51C2A3ULL, 0xFB361E650284417FULL, 0xE767FD6531E36DF4ULL, 0xB3F3E7D97AF91B26ULL, 
            0xEF2116938DD2C031ULL, 0xC14B318A4DC21E7BULL, 0x69873F151F778AE0ULL, 0xEA7CC1504F247428ULL, 
            0xBD72BDE82C3174CCULL, 0x47875BDB041EF809ULL, 0x77E20328D5EC39B8ULL, 0x76526E097E79FD2BULL, 
            0x1169F6EA61EFCFAFULL, 0x92F75D7937E92060ULL, 0x48E0EDAFB3DFD41BULL, 0x4A5C0ADC0BADF934ULL, 
            0x3D1D754C52F98C05ULL, 0x43A711B0E8B09AF6ULL, 0x1C7318A90F54D87FULL, 0xA5284F4842F020E5ULL, 
            0x7D6AA3D7CC6E022AULL, 0xA743E798F0D1CAF3ULL, 0x21CC87BC06A2C917ULL, 0x84A34136DEF3CA4EULL, 
            0xD08F9FE9FA174BE2ULL, 0x1A9016BDFEABBFF6ULL, 0x12BFF6771650CE13ULL, 0x297A77EDF87E193EULL, 
            0xD0133D5A8BEFF63FULL, 0x2C1F7AE9A58B55EEULL, 0x99B8991F384B21E5ULL, 0x7103F489681E2E46ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeyRotateAConstants = {
    0xC2BCF77D9163B341ULL,
    0x5F1B9E4DBDFE5836ULL,
    0xDA4A9320E4A119A8ULL,
    0xC2BCF77D9163B341ULL,
    0x5F1B9E4DBDFE5836ULL,
    0xDA4A9320E4A119A8ULL,
    0xAA104A8AD8287E1FULL,
    0x3C607CF9FEDBDE44ULL,
    0xF9,
    0x6E,
    0xF8,
    0xFC,
    0x02,
    0xA9,
    0x01,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Arcturus::kKeyRotateBSalts = {
    {
        {
            0x036A7C208674C6B8ULL, 0x4A4EA19FD5388C86ULL, 0xF0075EA2CCEFB475ULL, 0xABDA94C98F3AC38CULL, 
            0xDE402A75F4CC792EULL, 0x73370D6A98781ED8ULL, 0xCE15BB1AA26095AFULL, 0xCD72C9C418D9472FULL, 
            0x1475B40AF8FC140FULL, 0x343624FA13F4B65EULL, 0xF8FC9F0C1C22A2BCULL, 0x95E303DF55D9E987ULL, 
            0x912FCA99EAB958F3ULL, 0xD8726AFA1C8A6B02ULL, 0x399B0FDF561CA206ULL, 0x6D5D6480811F871BULL, 
            0x84109557E2785CF7ULL, 0x2094D5C5DEC07370ULL, 0x64BB84C57C16AF26ULL, 0x6F979D7C341C7CCDULL, 
            0x6F4A48AB4BC20A31ULL, 0x7D525713CB327906ULL, 0xA893CAE063E3CCA7ULL, 0x4AA8BE3726F17A65ULL, 
            0x9502092CAB3692BDULL, 0x384C278271BE1EBFULL, 0x66E666763A6EDBCFULL, 0xFC4680F7356C071BULL, 
            0x54786C25E8D61C5EULL, 0xB767AC89376FB9F3ULL, 0x67E6938F8EE5103AULL, 0x076940AD9E309EFCULL
        },
        {
            0x6340FB294B68BF01ULL, 0xB56B4C019826986EULL, 0x0565D867CD702415ULL, 0xE813EE23AB2FEB23ULL, 
            0x0430DC4A328ED0CDULL, 0xD3755F2CFA1127FCULL, 0x9BEB911DB5369B28ULL, 0xCC943CFDBC890BF9ULL, 
            0x97AD59664EB88EA5ULL, 0x613F3110CC884824ULL, 0xF86286F591BA3978ULL, 0x943A2254E3CBE9ACULL, 
            0x1980BDC25516AEECULL, 0x7D6AE9EDC6861926ULL, 0x4B8A572ADF978504ULL, 0x68943AD2888A5CEDULL, 
            0xA86CAD66A5FA8D7BULL, 0x997DC2703526D41DULL, 0x0A0E3AC853BAC94FULL, 0xBEBDF20847B9E071ULL, 
            0x814878169C7216FCULL, 0x1756CD62A679516FULL, 0x31E56902F13E84D3ULL, 0x1CDA9DB47DB650B0ULL, 
            0x7DF6C7994E745B55ULL, 0x690D969839712978ULL, 0xE0202F479BE2CD8AULL, 0x51BBE38F04F209D5ULL, 
            0x3A0E61E802102B6BULL, 0x6E7411F79AF6E590ULL, 0xA45AE68A10BA5276ULL, 0xB279288F3F15DA65ULL
        },
        {
            0x325230EF5D7A2E51ULL, 0x9DA372B08850347FULL, 0x80274D5F58F2025CULL, 0x9B89A9C366050CD0ULL, 
            0x5F26F84BE54D40A0ULL, 0x586D51244C6E9FA9ULL, 0x863DB84DEB715982ULL, 0xDAD8B2C5CEB89CCAULL, 
            0xA922A32D9F483722ULL, 0xECFCA948BB0AB231ULL, 0x79D95DC0AEBDD889ULL, 0xDDFE27481CABE4A6ULL, 
            0xC27F26B421C2528EULL, 0x98CE9B65B6016BABULL, 0x43DCA29579EF4C9BULL, 0x209F66F51C1A3C36ULL, 
            0xD91249ED5A4CDC6CULL, 0x8929562398FB6164ULL, 0x2B9C519070796A56ULL, 0x4855B1046B65612FULL, 
            0x61A1C4E1537B2733ULL, 0x6C5C0C97D039F43AULL, 0xA2B1631C42335141ULL, 0x2A09F7A989D6E6BEULL, 
            0x10F00E6D530A601AULL, 0x7A4DE020A69025C4ULL, 0x8F3FF077E0909FFCULL, 0xF85693F2209DCFB4ULL, 
            0x607E89FF7113D203ULL, 0x395A0FF07F90B797ULL, 0x42D5A7D811FE4C2EULL, 0xF4BE2C2C3D778217ULL
        },
        {
            0x5DB8A11C73C3707FULL, 0xB3D64AAEDA359DF6ULL, 0xFCB520808989A55BULL, 0x3DAE700FE3A8C76BULL, 
            0x1B9106949945C170ULL, 0x899D79A153D61225ULL, 0xF6AD2687D09B83F2ULL, 0x275091230638A275ULL, 
            0x6D19A502BA409355ULL, 0xF055B2F809EA42B4ULL, 0xCD2927C76FBE2ECDULL, 0x89A7A88582CDAEDBULL, 
            0x9DC1058B7C2A0042ULL, 0xB89F5F41D7D90E1AULL, 0x55FD4029CFB5E856ULL, 0xE01A18A6B03B8235ULL, 
            0xB41D574BE5CAE68FULL, 0xC171E6493BBE7DC3ULL, 0x6B686A2699B18EC9ULL, 0x29C24293F9AC8BA2ULL, 
            0x119E5B898C9535F7ULL, 0x10499C471E401184ULL, 0x438FDEE807071BB0ULL, 0x5761A7A263E46B7DULL, 
            0x48F671CB69D06024ULL, 0xEA4890159FDABC9AULL, 0xA65DF5837F86B385ULL, 0xC7DCFB053D3848A7ULL, 
            0x0F643958D90C49ABULL, 0xE05807E63C790CA0ULL, 0x9915C507C65938CEULL, 0xA6E131FD679A2DD6ULL
        },
        {
            0x0F7DF8449D53831DULL, 0x492C8D41511D4D44ULL, 0xBCBA8C17E86AE93FULL, 0x04BACDC344F0AB21ULL, 
            0x18AE2584B5E7517CULL, 0x1107838B0421A3ABULL, 0x4D975B7EFFD62BF6ULL, 0x92A42873D80F6608ULL, 
            0xA1E42AE6DC4CBB92ULL, 0x633B4594B3D08207ULL, 0x259EF95B4E06DC4DULL, 0x9180CF7EDBC43924ULL, 
            0xC3785C37CBABDCD2ULL, 0xD63E5E3642F96536ULL, 0x4C2A393AA11869A9ULL, 0x45434518B654EDE5ULL, 
            0xE80C568647B91F08ULL, 0x6DD47FFDE9A3D585ULL, 0x33CAE077D35461A4ULL, 0x9095D0A63E64B828ULL, 
            0xFC74E2BF5C40B573ULL, 0xCEAD25A7A8C53B6BULL, 0xF78831807A728C25ULL, 0x275AD82A5EA18B0EULL, 
            0x0BCEECCDF4413D33ULL, 0x18B1E688B89F8465ULL, 0x3530A0051150DE9DULL, 0x0E59FF20700A0F23ULL, 
            0x5FA7335F72EA09FBULL, 0xF0CE9A60DABB4FD4ULL, 0x681FF325780CCA73ULL, 0x199DBF06C06996B4ULL
        },
        {
            0x476EB35FDF61EDF3ULL, 0x0F7A820F0DC8C34DULL, 0x375C6F432E38526AULL, 0xBE660B58F27EC52EULL, 
            0xE67A4786878F50D0ULL, 0x42B820A2C7DF0647ULL, 0xFE3F5EB8F7BD13B6ULL, 0x5D5C210302557B01ULL, 
            0xBC529241F3E7A39DULL, 0x9D7C19C69B64C35FULL, 0xD2325EB878F3F8A5ULL, 0x50E7609C77DB965AULL, 
            0x201D72F7D5FAE288ULL, 0xB03DCAC0F7D5EEB1ULL, 0xB88E601283C45118ULL, 0x76C585E6FE275DC4ULL, 
            0x02DDD4C70F521436ULL, 0xE000E46774DE2B56ULL, 0x0FFFE192F1095634ULL, 0x2BD423EA6128A676ULL, 
            0xFFA21C586B28F93DULL, 0x05BF810C5D90BBF8ULL, 0x5FCDFA685255F80FULL, 0x48CC661D132ADD7AULL, 
            0x203D4FC5F76D72E0ULL, 0xC9F5FAC3125B9189ULL, 0x0C28516276D2E4E5ULL, 0x5321C5C21C5F3AD4ULL, 
            0xE34C7EEBB082A319ULL, 0x0565652FB81877BFULL, 0x7BFA73AC7E6A2ECBULL, 0xCAF926EBE3868000ULL
        }
    },
    {
        {
            0x0CD0DFCDDDE9F49AULL, 0xA6E4304050F2877EULL, 0xFF424F9F3F60904BULL, 0x340C7A261F32B245ULL, 
            0x0BA7ABF9F75303FBULL, 0xF184072F17ED6749ULL, 0x3F86CF2E9CE436F8ULL, 0x1F17DEA656BDCC8DULL, 
            0xE630ECBACAA78808ULL, 0x0DB4446FF3D479A1ULL, 0x09537B8BB295C2D6ULL, 0x90FEDCE5C5829F83ULL, 
            0xD473785990007ABAULL, 0xD6033525E32023F7ULL, 0xA826A5E48F5AE1E6ULL, 0x0E4387CBA74BAB2CULL, 
            0x663796A2303C13A1ULL, 0xD3E8FCE260A1317FULL, 0xE77B62A488E18F38ULL, 0x57BEFFCFB6453DD8ULL, 
            0xF93D93046C3899BEULL, 0x36798E0BD7749B0AULL, 0xED322DDD094A63F4ULL, 0x870C8825509CD6BBULL, 
            0x37AFAD7E70C28C81ULL, 0x3857D49CF37E63FCULL, 0x3D8A6527CD5D00CCULL, 0xC044E4302988B9EAULL, 
            0xB450A299DBD74488ULL, 0x0F13C0ADEE63C9EBULL, 0x0410CF3D96A9E98EULL, 0xF004157E7A7CEE02ULL
        },
        {
            0x9B706FDF6CC83255ULL, 0x2C24A94FA0F7E22DULL, 0xF37F3C10AE2A84F7ULL, 0x10AE9AEC90818113ULL, 
            0x569086D129B3701EULL, 0xB83B2948F5907731ULL, 0x12D7BF613F5FC340ULL, 0x792CD8416B15D5F0ULL, 
            0x6080A3F102291A7BULL, 0x5853F12337847475ULL, 0xAE1F2FBDD2B54BC4ULL, 0x073628F93E4A4F5AULL, 
            0xDB5B219C0C07A89DULL, 0x045C2837EEC76A72ULL, 0x9D0487E759296B2FULL, 0x3C778FF62EC0104BULL, 
            0x2247F52B8FA91B68ULL, 0x13CB50FD321A0FD6ULL, 0x4358E65583AD3D08ULL, 0x1EB134B95CD5520BULL, 
            0xA9607C333B61DC7CULL, 0xF0281EC8BDA1C9D0ULL, 0x9258A308B3DE0072ULL, 0xC0076EFF3F93A1DFULL, 
            0xF7F6F6D936AA9781ULL, 0x266B8CD52A00B9E5ULL, 0xE8724B8EE24FD21CULL, 0x182DE1054DD2BD76ULL, 
            0x756929FD99A03170ULL, 0x087BF1CA1D80A596ULL, 0xD0DD66A9E80F6F2DULL, 0x51F8FC47021740ADULL
        },
        {
            0x954BAA3D10DE587AULL, 0xDC1265B8B018AF5DULL, 0x41CA45D6A25345F3ULL, 0x3CC89815E4621341ULL, 
            0x4CC04A0040EFCBDEULL, 0x57F952F414D6E2FEULL, 0x0AC7FADD234C8825ULL, 0x1F008A162B092E51ULL, 
            0x095BE44FFA8A32C4ULL, 0xE8D5713E1D6EBC13ULL, 0x6E5FBEABDC3771A2ULL, 0x946D761EE61D550AULL, 
            0xEE44142B137EEABAULL, 0xC191A1594A40BE1EULL, 0x4B365A8D5EB545F8ULL, 0xA915630A645BED74ULL, 
            0x33B106ACF43308E6ULL, 0x5A698E410F704E2EULL, 0x46F3F0D4C137A9CEULL, 0x71DA846B9937193AULL, 
            0x1F080E7FC822497EULL, 0xEE964CD4F9744D2AULL, 0xC5673FFA21FDFC48ULL, 0x77FDDA753C3FA8E8ULL, 
            0x9D51F84CAE213453ULL, 0xA4037B05813323F9ULL, 0x6496AD09CCB265B6ULL, 0xCE14CB24F4F5FD35ULL, 
            0x4A23EEED7797D2E1ULL, 0x533C738CB7D074F7ULL, 0x252AD0BC2A0741B1ULL, 0xF7885BCEBF1E7A68ULL
        },
        {
            0x5865CDCE29EF3AD9ULL, 0x30B68F5F97DBD8A8ULL, 0xBB5A30FD835399DAULL, 0x50D2C3C61783B9D2ULL, 
            0x31270D622F2CE8A5ULL, 0x5BDA2808F1E5FF93ULL, 0xD07B17E4DB007516ULL, 0xD49ED279BBC68DC4ULL, 
            0x5AA8DEF006C57716ULL, 0x82FE9DFEFCDD6F2EULL, 0x68E678A10A690047ULL, 0xF9EB1BCB7F7AF69CULL, 
            0x3CDD0B43AB39078EULL, 0xDE2F5443F1D2C156ULL, 0xACB9334E0BB3D76AULL, 0x5F173B6EC3258C8FULL, 
            0x44127EFEF4EA8FA6ULL, 0x16DBAAED620C5B7DULL, 0xD7496049F8DED70CULL, 0xF25B7DB0EDF96F47ULL, 
            0xE48484CA94923011ULL, 0x80FEE4FE458B60B7ULL, 0x8D6C681EFA38BA13ULL, 0xE4A3E1D51153882CULL, 
            0xEDD64530D734A5B7ULL, 0x19CDB4EC43146B4AULL, 0x692A4504771C823EULL, 0x235D02C858D93B5CULL, 
            0xF20CB7A54D3253B4ULL, 0xA68C6F119CA0D125ULL, 0x1AC8A7DC4D9AA37CULL, 0x645E3C0D753C868AULL
        },
        {
            0xF2A6E3EACDFC7E3CULL, 0xA56AC4D74C81B703ULL, 0xAF4888D6852D491DULL, 0xB69EBFEE35B4562CULL, 
            0xE81B85B549C23488ULL, 0x681A578967BEAC16ULL, 0xB15B2E9CDC3685BAULL, 0xA18E6382E95C3E43ULL, 
            0x1F4246748BF7C0FDULL, 0x1841409B2E6FED44ULL, 0xFF0EBD7EB212D39BULL, 0x2D1E2077B44387B9ULL, 
            0xA39E97BB0C9D0E7CULL, 0x8FD4BDA38FB94180ULL, 0xCDC510ABE453375FULL, 0x4DB3528F679DEC4FULL, 
            0xD050E17F12CB8807ULL, 0x8E5F123F512561C3ULL, 0xE96B0227DCE2A997ULL, 0xA0C8E0EFBE861BDFULL, 
            0x73837C494023608FULL, 0x0434247F71FDABFBULL, 0x3385D0069A1F0098ULL, 0x7336FC64D743416EULL, 
            0x2F7FA026F62284F9ULL, 0xB2FDA16F11EA2D61ULL, 0x56C3335EED8CA4E5ULL, 0xC5D43411B3FE08D3ULL, 
            0xDFB135A122380F42ULL, 0xC9C6A8C40DEC6C92ULL, 0xC8608D087A8AD37BULL, 0x691D3CBFB8EC302AULL
        },
        {
            0xD7AFEA2E786A0B1CULL, 0x7D053B6E45C321C7ULL, 0x5761DF1642A59B3FULL, 0xFCFC15406629E0F6ULL, 
            0x39CD1A21ED65B1DFULL, 0x8A534E8436165F47ULL, 0xEA12A1FC592FA88EULL, 0x754A4DA673477672ULL, 
            0x445BCB49DDAD311FULL, 0x82E46146464AFB48ULL, 0xCF7C5D96E43868ECULL, 0xEF88EE5A841A72ABULL, 
            0xF3DF3AE65366307FULL, 0x6F9BDE269DF79B79ULL, 0x7FE0083D387328DEULL, 0x15A43E53B8F55CB6ULL, 
            0xC02C9792E71EA489ULL, 0xF5C50651B3423235ULL, 0x35BE8B7C714FDDD8ULL, 0x8CEB508C3DACF51AULL, 
            0x928B0D05EB7993ECULL, 0x76AEE2158906D211ULL, 0xB7AC16D886897E6FULL, 0x1034DEA6FD11D930ULL, 
            0x33BD927107BBCB91ULL, 0xD234A94593A0992CULL, 0x030D5C849BA9361BULL, 0x5F55988D0001B256ULL, 
            0x40B7A93F1F9595FEULL, 0xA811F9FBCBBF7E16ULL, 0x34974393CAC24007ULL, 0xAC4C0484F1CB2622ULL
        }
    },
    {
        {
            0x8C1F82EB70730947ULL, 0xF1FCF2984C175605ULL, 0x25E60D3ADBBB1EF8ULL, 0x64A4103ECDF6BD93ULL, 
            0x5AB65B74EA38F096ULL, 0x1069CCED039EF8BDULL, 0xA84DF3640B71CF3AULL, 0x41FC7B09D11E788AULL, 
            0xB5909B76E6D23839ULL, 0x63FB4C7A521330AEULL, 0x2D8CFB77BA54E64DULL, 0xD7D604AAFF78618BULL, 
            0xE103D5CD771EF458ULL, 0xECB248DC7F8B86A5ULL, 0x868DBD7DCE254490ULL, 0x935661A1760DD740ULL, 
            0xF7D951183290B73FULL, 0xA854FD12A6AA6D73ULL, 0x63544D8A3EDD5CB2ULL, 0xFE5DED6F3B9155CDULL, 
            0x34B5304A446AEF19ULL, 0x25C4BFC590D584AFULL, 0x36ED802A6DF1F404ULL, 0xAC86952410F389CAULL, 
            0x89B9C8D18CDD2CAFULL, 0xB28E8FA27F43920AULL, 0x0DB0B98156760D7AULL, 0xE446D4C83FEFA8F7ULL, 
            0x0C76E5C4F09C4685ULL, 0x029C9D12E5497020ULL, 0xEC4108B5D0161F99ULL, 0x917F4F43443582B6ULL
        },
        {
            0xB137B2AE4407C248ULL, 0x13A5D115919F2B46ULL, 0xB9D7782BA87D6FACULL, 0x3AAE923BED1FAF45ULL, 
            0xAF5D95940E75D1DDULL, 0x32B9E05FE8E1B55AULL, 0x31885D81D6F91EC4ULL, 0x3D12556BF7412AB1ULL, 
            0x93095D0942305AC5ULL, 0xA7A64B5500FFC718ULL, 0x2834212F6D300BFCULL, 0x2C3A946A531F59EDULL, 
            0x391C447561CC1571ULL, 0x7477B540861793D3ULL, 0xA1D9159188C085BFULL, 0x8B69F3239EAA8643ULL, 
            0xFF2C7FCB43C2CE82ULL, 0x02B7CE895A7E349CULL, 0x36284026D32252AFULL, 0xBC0B2D2666FA014EULL, 
            0x51A61B164F5919A4ULL, 0xCB3559C810607C61ULL, 0x9C76A8C6EAE25B21ULL, 0xAEC3CFCC5C271EE6ULL, 
            0xF3B93EC570195B7DULL, 0x68EB69429420867EULL, 0xB88D96BB87095631ULL, 0x58BE00708C5E348BULL, 
            0x81E43971407068A2ULL, 0x983C479A3948FDCBULL, 0x22FE0F0B15A573EAULL, 0x652484122D5FBD3FULL
        },
        {
            0x37C2054CCAE902A0ULL, 0x5A61E4A616EDF091ULL, 0x8B3094803E5067DBULL, 0xCC2AAC1ED799D7B3ULL, 
            0x877FADF51FAE286CULL, 0x9901EFBDBCDBFACCULL, 0x2C6876DF11A6F6A0ULL, 0xC2CE96D589D9EB48ULL, 
            0x49621FA7AD60276CULL, 0x1C9EB66F46DBBE0AULL, 0x7DEF58EADABA2336ULL, 0xA8C80E4D1B10F9B7ULL, 
            0x75BDD81561FA2261ULL, 0xF3121E64CF82BDC0ULL, 0xFDA40148491CDD1AULL, 0xCC2EEF1CD168A2B2ULL, 
            0x308317654A79BBCBULL, 0xDBE75240CFDC06A0ULL, 0x590EDB2E4D7853F8ULL, 0x073A91FD923CDE00ULL, 
            0x4479C3B5D85C7281ULL, 0x35C4815576C3F72CULL, 0xF49CD4E847385E45ULL, 0x6A75375AE34A15C3ULL, 
            0xC52FA103AE325544ULL, 0x0A8E4C13980AD6A7ULL, 0x1798BC5189E18A5EULL, 0xA8552505657564CCULL, 
            0x70931540211EB524ULL, 0x3A66E9AE89498405ULL, 0xFE9357AC4A631127ULL, 0xE591718CEC6495D7ULL
        },
        {
            0xABC8990BDCD3B4E0ULL, 0x057A3D8ACEC97146ULL, 0x3A8562D809ABA013ULL, 0x04F9540A3B1AE582ULL, 
            0x48E182AF4F95F03DULL, 0x1ED4D5EB72A2B934ULL, 0x2CB06528A180077AULL, 0x31A9E6306939A92EULL, 
            0xE66081FCC5184C74ULL, 0x381417B92107B789ULL, 0x9661ABC5B0115907ULL, 0xC7D35C47F8218031ULL, 
            0xD37576207C11169BULL, 0xE99639C1DC1A29E2ULL, 0xDD4D30D9EAB50D46ULL, 0x299D58D91EE80D88ULL, 
            0x7D10C72AB07DCF50ULL, 0xF946A541811DA190ULL, 0x58590183E4F61A80ULL, 0x4038006C51BD5602ULL, 
            0xE6669EEC22FE378DULL, 0xD5AB00951E85983CULL, 0x7B9EEDEB16F5418EULL, 0x908DA9DF679455DCULL, 
            0xE154D7DFDBF9DEEEULL, 0xAC0D272156E990D3ULL, 0x351B99323DAFEF02ULL, 0xB5D0DAF470C9A8F7ULL, 
            0xB43082010608E366ULL, 0xB741A94E570A3583ULL, 0x7FD4DF2AACB1FD76ULL, 0xAC851F3EC3BF5C59ULL
        },
        {
            0xB0CDB713EEC3279AULL, 0xD48392F164589080ULL, 0x7AF955F91423BB92ULL, 0xDA9935869EE8182DULL, 
            0x64052A9DB9224037ULL, 0xB26B3059EEE88969ULL, 0x7C0D2FC145E77E31ULL, 0xE128D2D89EAA1488ULL, 
            0x2CFBF0D858030779ULL, 0x63C054A7F2EFDB4CULL, 0x619FFF7AFE5DA983ULL, 0x558BB55FE0341E8DULL, 
            0x7A7898D46A542F0EULL, 0xB1E30C6F5941881DULL, 0x8E0196A277A05D58ULL, 0x3A447D86258E983FULL, 
            0xAF9E9D87B3959545ULL, 0x6089DF69BBB07BD6ULL, 0xD7C753C70EC95C58ULL, 0x9D54810B2260376FULL, 
            0xEEFE5E72D1FC2D9BULL, 0x3416BA1EDEBB6B4AULL, 0x09C53ACBFCE4FD73ULL, 0x0DEE396CAB3F1819ULL, 
            0x2B37A92E3D5EF657ULL, 0xC448C858E2A9145DULL, 0x87BF4A9956EF9484ULL, 0x2BC02C133042DF59ULL, 
            0xD9707B6FB77D5438ULL, 0x8EFC10AF9B1D6D48ULL, 0x70F3D6A063D67A2DULL, 0x08FEA6FD245D7538ULL
        },
        {
            0x5297BA161E03E0A9ULL, 0x836A9E822E01A660ULL, 0xE739FB2A7C5A8946ULL, 0x302EF2D773C6C71FULL, 
            0x913165E7BC9D1E70ULL, 0x8A4DA9EC0BD1E34FULL, 0x6FBEAD81CB20C9DDULL, 0x92746269051B9B8BULL, 
            0x364F23371A143CACULL, 0x13874605D88CD21CULL, 0xEE772FDAD155124AULL, 0x22596B749A57C06CULL, 
            0x1BFBEBD6F39D07F8ULL, 0x4517E7DA5133D12BULL, 0x43ECDD2F3A723171ULL, 0xFD7E2B4145D7444DULL, 
            0x476882E1EDF7DDF7ULL, 0xDF5BFE8D633FE39EULL, 0x35DDA37369BF6853ULL, 0x44729ABC33ACD069ULL, 
            0x34467A57EC0A7CD7ULL, 0x77FF2C0AED66A07BULL, 0x77B5FD2C5C89E2CBULL, 0x02ADCA22AA869292ULL, 
            0x78161670AB83DA31ULL, 0x01B3F34E5C174907ULL, 0xA67933D91E461E30ULL, 0x481755117EB42709ULL, 
            0x05432AF21B58A506ULL, 0x408FCA7B72D4DC2AULL, 0x9A980A5558AC61FDULL, 0x7A7FDBCA7F4B15E8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeyRotateBConstants = {
    0xB71062C5CFD376EBULL,
    0xE1D857F3ADB0CD62ULL,
    0x8F2DE37B2E6B31B0ULL,
    0xB71062C5CFD376EBULL,
    0xE1D857F3ADB0CD62ULL,
    0x8F2DE37B2E6B31B0ULL,
    0x114936CA0265560FULL,
    0x9CF5558A66487C26ULL,
    0x83,
    0x24,
    0xC0,
    0x11,
    0x96,
    0x08,
    0x5D,
    0x58
};

const TwistDomainSaltSet TwistExpander_Arcturus::kKeySpawnASalts = {
    {
        {
            0xEFA4E9C53DD30DAFULL, 0xA0D82CE2BF23167DULL, 0x8F847A4E2F1E732BULL, 0xCED3232D25891347ULL, 
            0x3061ED84B8460B05ULL, 0x614D3E96A8F72D01ULL, 0xCF64FF2FD9C9ADF9ULL, 0xA50D639D192FF468ULL, 
            0x0E0284D1848F7FCDULL, 0x08A8B18EFA66B825ULL, 0x2A06B4AD3B81E808ULL, 0xE1819603A7B2E5F9ULL, 
            0x604DCB2D1B6F41F8ULL, 0x92427E0E76C185F4ULL, 0xFADB2EE92733EF4BULL, 0x9CF46634EAE96943ULL, 
            0xCB2F356583F5B63BULL, 0x64B5FC2B364712F2ULL, 0x1B888F6046B9320BULL, 0x4B2541FC841A9745ULL, 
            0x71BC0D0D99ACA4B5ULL, 0x582E64C66B47A5A5ULL, 0x1EC6E9FA92DE2354ULL, 0x54C805ECF98A0B62ULL, 
            0x75BB7FD448BDB8A4ULL, 0x6DB784281F897FA1ULL, 0x919688E4850E4642ULL, 0x19A3BB9F2C7C9A17ULL, 
            0x4D5E519F88CB9CE5ULL, 0x820F181A73328C09ULL, 0xF6018727E015F442ULL, 0x4CF1BEDDE4707BA0ULL
        },
        {
            0x1DC926FCD24926FDULL, 0x3D0E7B55DF0F8A02ULL, 0x690F96BC0A24D457ULL, 0x734316B66773FE78ULL, 
            0x2EF9D7DFD76F041EULL, 0x41753B0BA072C049ULL, 0xC14E0DAB50803C75ULL, 0x85FEB715B6989408ULL, 
            0xD25D7565E433E3EDULL, 0xECF3E10D5CECB65AULL, 0x87B18ED8BF2AE51FULL, 0x01EA97D1CD0118B1ULL, 
            0xD464BB051E579BDFULL, 0xDEF8AD1F183F4112ULL, 0x6F07403DEBF3D3D0ULL, 0xFDB22CB627AE0503ULL, 
            0xB80DFECA2E76D8B9ULL, 0x8792ED8C53961817ULL, 0x5E08F4DC0673A950ULL, 0x02EC632F443B4AF6ULL, 
            0x96D0B94FAAC7462DULL, 0xBC8B67B7BE804C19ULL, 0xACFA616F270F2BEFULL, 0x341DED05B6E70F40ULL, 
            0xB3C279E2C20E6E1AULL, 0xDF38791E7B49C1ADULL, 0xF915988811C73DBCULL, 0x317B0023F6DA5B4FULL, 
            0x3967F49800C3539DULL, 0x2CD4835C2DE062F9ULL, 0xA56E9C493CF99769ULL, 0x2C2ADB3189E5B5F3ULL
        },
        {
            0x6FF8D2F740CA61A6ULL, 0xE865049A392E9080ULL, 0x9E61C9507B4F5E0FULL, 0xB943A4AB0DB12619ULL, 
            0x45CAC3EA342DA276ULL, 0xB2E2B6D4902A0708ULL, 0xBD1806B245796BCEULL, 0xA9CD48334B11A904ULL, 
            0x36918C6CEB803E49ULL, 0x94646E1988FEEEB2ULL, 0xC6F40FADB6960134ULL, 0x56BFA2FC3374ACFCULL, 
            0x30D946F2B260CF5DULL, 0xB2355CDFE32BB574ULL, 0x9FE7E8BF44ECAB7BULL, 0xE70257B5480DD9ADULL, 
            0x676CB77E93546FAAULL, 0x091C166D9F0A371BULL, 0x0D1D69B6CE8F65AFULL, 0x5C45914B24D46BC3ULL, 
            0x854CF45F65AF9B8FULL, 0x420C10C1D5ADB2D8ULL, 0xF8867B9F3978F70BULL, 0x845DC79BB9EB05F0ULL, 
            0xAB9B33BEFDC066B0ULL, 0xA2211F12722D1F55ULL, 0xB18545076CA227EFULL, 0x66092302A5BA6D63ULL, 
            0x2DEC96FC5B6E07F3ULL, 0xBD7A91F21BA0D57FULL, 0x51679389CCDEEB28ULL, 0xACCF4423C6AE2377ULL
        },
        {
            0xC8572339D44AA7DBULL, 0x0DB4443567E0FF09ULL, 0x17CC4F78947A753FULL, 0x6AE2AADB8B2C1485ULL, 
            0x2065C784DB618B9DULL, 0x21C88EDA4DB5F974ULL, 0x613C11299C21967BULL, 0x95E035EC3B407CB6ULL, 
            0x9BB9E9B52D1DB318ULL, 0xB1B97F0876021444ULL, 0x7315D293E15B571EULL, 0xE706E0CEB5616E4AULL, 
            0x591082911D19ABADULL, 0xC2107AD3FF93C025ULL, 0xABFAFBDB5901E791ULL, 0xAEBCE616C4C3F5E7ULL, 
            0xF6828D409085A504ULL, 0x3A6EA370C922D6CCULL, 0x0EC962DBF528E0C9ULL, 0x03898512A6A91EC5ULL, 
            0x1091F269C13536B7ULL, 0xDD71D3BD43F4898BULL, 0x3C4F1FCA176D8B31ULL, 0x2ACBF3FD2A35800CULL, 
            0xCB32FE71EEC4E85CULL, 0x6F704B4E5E4BFE2AULL, 0x0AA25ABDEC164328ULL, 0x2A3FFCABBBE302E0ULL, 
            0xE3EDE1D0AFDC262DULL, 0xE1591FD59DC76179ULL, 0xA22D986F73DCF31AULL, 0xAAF6586FE5B52A3EULL
        },
        {
            0x0B25E53E98B517E5ULL, 0x3659D7450FC570A2ULL, 0x65FC7AAD22F7D237ULL, 0xF58367604AE85015ULL, 
            0xE2AE6997CE7FDF0BULL, 0x964E310C5A744883ULL, 0x40A9EBA8BC93B35BULL, 0x600BA68CC444E42AULL, 
            0x7AF7C7DEE9DD880BULL, 0x44A728F070E15BBAULL, 0xBDAB4C65C2992113ULL, 0xBD6ECAFE42A14BC0ULL, 
            0x36AA6D55B5E0779FULL, 0x2175D9106C890E23ULL, 0x97407DA37706466DULL, 0xF96B7C7EEA6D868DULL, 
            0xD36646511E504BCCULL, 0x8A0ABCF1D533D0DFULL, 0x768F65CB6B5E3D0BULL, 0x35389E3681F893DCULL, 
            0x527F622C3A58D4DFULL, 0xB83A8A74AFCFFABDULL, 0xAB9972B4A2879391ULL, 0x67F6D3DC144CE369ULL, 
            0xBA2E8D2C264F0921ULL, 0xC85F93F92E0F7CBCULL, 0x69A1B87EA2C2D322ULL, 0x8C2A2D9B3795AB4AULL, 
            0x48988E8751451694ULL, 0xC3F2FBDEACF5005FULL, 0x3EEFF71207C10D20ULL, 0xD1DEABB511A8DEA9ULL
        },
        {
            0x2D852246509CF723ULL, 0xA23849E189D31FD6ULL, 0x1C11B7FBDD9F7101ULL, 0xEB0218EFCAB50846ULL, 
            0x2DDE681BE9771E1BULL, 0x8496D275D0286DCBULL, 0xF67FCD0D24362763ULL, 0x6A63E0A46A27190DULL, 
            0xAC2AB9E0310BB2FAULL, 0xCE8F08DAA03820ECULL, 0xEBF9E69D4A608B3CULL, 0x02092164F53DE5A3ULL, 
            0xA5072508A4D84FC5ULL, 0x20C968A5D1D91739ULL, 0xF04920F3451BD90DULL, 0xB5B746AD41E3D598ULL, 
            0x56860E387859CC47ULL, 0x5929950E97358D00ULL, 0x6330502C11B85600ULL, 0x17BD681B76D8DA31ULL, 
            0x7574BD2B521FDD25ULL, 0xE5753ED6EA962707ULL, 0x1EB84C7DDFA0B1FEULL, 0x45171B3D585D2405ULL, 
            0x9D9E60E820A80C0FULL, 0x9DE568EE6520EE55ULL, 0xBBF654D67531EB69ULL, 0x759D3CA7E56D915EULL, 
            0x9E0DC7B02CBE83DDULL, 0x66421C0AF8060E6DULL, 0x746C791DE3F4E040ULL, 0x3E629CC1AC079004ULL
        }
    },
    {
        {
            0x18822F64E805159DULL, 0x1933E42140ED32BDULL, 0xEB07D5D29551C53BULL, 0x92C51A3BB4D062F0ULL, 
            0x081CF4496BDF17BDULL, 0xB26984A61B4EB13BULL, 0x0804D0990E09057DULL, 0x187507F017F91FC3ULL, 
            0xF8549E511944C8F2ULL, 0x37AC862F401C8F2EULL, 0x2E4344C7C2A8CD89ULL, 0xA9453937412E826DULL, 
            0xAC6C85FA7A670EF0ULL, 0x64EF5A4D90AE11BFULL, 0x4C0B948301409006ULL, 0x604E10783B2F05C6ULL, 
            0x8CAEBFA8CF0C7271ULL, 0xB917E07114BCD96DULL, 0x9FD63C7EF140FFACULL, 0xE2634AA275BDF995ULL, 
            0xA9C361EA00E03D55ULL, 0x885E8055CD4AA1C3ULL, 0xCD249E139C595021ULL, 0xBD4DE90F14803FCEULL, 
            0x233E1F87138FEEAAULL, 0xC96AD65F0E952512ULL, 0xDBF7FC58B6765EEFULL, 0x2A4DF80DF8A6E799ULL, 
            0x8C16E36B0741B628ULL, 0x06458FA5F8AABC19ULL, 0x0A8A32894904C156ULL, 0x8A7E83E075DE56C1ULL
        },
        {
            0x447773237BF230C6ULL, 0x5DCA61B19E2F67F7ULL, 0x68CE1ABADD8CDF7DULL, 0x253AC7E4489C08DAULL, 
            0xEF45B12AACCA7C61ULL, 0xF46094A412AE282AULL, 0x5C82EA4A1366E49AULL, 0xA5BF53D5FA56258FULL, 
            0x863309B725BA1976ULL, 0x1DE4DA619EDA9D57ULL, 0x8E03E1B299A7D210ULL, 0x49CDB044893F2CB9ULL, 
            0xA4DF876C44A300A4ULL, 0xD1032F559D78D0A7ULL, 0x76C7357B486568ABULL, 0xDC53C4A45D7B7AD3ULL, 
            0xF6B11B9F6E0610C9ULL, 0xFBEC6CE3FEB4D5BFULL, 0xD878D411B55934DAULL, 0x11B29A0CE5B6A0E7ULL, 
            0xF15D66F7E0D440A2ULL, 0xC6241D4D8A08EFD0ULL, 0xB798378B36D410E8ULL, 0x39BCF7BBA4A8F12DULL, 
            0x0D463351BAF639A3ULL, 0x6EED9E123512004EULL, 0x25E2F9B54622EB2AULL, 0x009A8AC6B92B9544ULL, 
            0xC50E063D852339A8ULL, 0x3FB8AD3679452479ULL, 0x2A9AA5986B3A6BAAULL, 0xC0A688F328587967ULL
        },
        {
            0x710C5683A4B07B48ULL, 0xC73BE7E84B019D31ULL, 0x421F351745212767ULL, 0x68AFA90AC7F563A5ULL, 
            0x0937291606F8E449ULL, 0x515CE6722FAB502CULL, 0x15C8A015E835A9F1ULL, 0x06652C4D339D8278ULL, 
            0xCA483F0107195B12ULL, 0xA719161D2F8D755DULL, 0x3954A8A0872AA66DULL, 0x179F97FB448EF3A4ULL, 
            0xAA6387FED4780763ULL, 0x2B45ABE237CFBD1AULL, 0x3046243C9D1BADF2ULL, 0xE6089523ABBE301EULL, 
            0xF7ED6491BAAB73B3ULL, 0xAA0F90C0811C0247ULL, 0x382B443027B1F693ULL, 0xC92213D1D0936FDAULL, 
            0xD9E8838C6EEDB5F2ULL, 0x625A2330389B795DULL, 0x4D5720FC116C0C4FULL, 0xADEBBCC17047C946ULL, 
            0xC8683913A0891428ULL, 0x15DD4939CD36E2EDULL, 0xBC12198480D2D1B7ULL, 0x4D888DFB972A7FB2ULL, 
            0x6A7C26369C080A6EULL, 0xEB43D3733F5D3A2DULL, 0x3442A2572D1BC411ULL, 0x6D16BCA5F8E87658ULL
        },
        {
            0x92A36EFFEF14F92CULL, 0x900B311E8EF147F6ULL, 0x3D2E764CE6946FFEULL, 0xE40076167F1AF1AAULL, 
            0x75FB5A7524049C8AULL, 0x905D05742335A842ULL, 0x4CE03187069262E7ULL, 0x1414D451FB5DE15FULL, 
            0xFD0D23670137E9ADULL, 0xA39A9156A31CD9D9ULL, 0x5C55AD04F82683DDULL, 0xEFB909DEC151A403ULL, 
            0x1067B20245B295B9ULL, 0x07D81E47024BF285ULL, 0x242F13D9D457FC04ULL, 0x61AF5E5E5F960D59ULL, 
            0x640C65210DBCF784ULL, 0x5D3E6AABC4F68382ULL, 0xD4D593685D796CC3ULL, 0xE01FF70CC02E88ECULL, 
            0x634A51ACD884E9BDULL, 0x0178C29568DF3760ULL, 0x2403187F3977D983ULL, 0x8C97ED65D08EEEF6ULL, 
            0xF48B390AADAA74C5ULL, 0xC58BDDC8E710C0E6ULL, 0xF00A44E01988E62DULL, 0x237CA19D1676DECAULL, 
            0x274E15C13FCBE32EULL, 0x657745AA50097908ULL, 0xD16D9F63A124E254ULL, 0x159A5DBF413FF6D0ULL
        },
        {
            0xE7C2289033EA26CDULL, 0x19B8734592822A4FULL, 0x2BA563DB4E0FF163ULL, 0xD777036B09E230D4ULL, 
            0x2CF8A8DC4055B2EBULL, 0xBC274E3E403440BCULL, 0x9CA319475F9DE4C2ULL, 0x0FA0EE3CC90789CEULL, 
            0x79838FDC3048DAC9ULL, 0x4E4E1EDDD53D6B66ULL, 0x0FE69E189FF58A8CULL, 0xB12AA80200E13A73ULL, 
            0xB978DFBC0C263A4AULL, 0x527D6463793DA88BULL, 0xD74C76AC11DF82B4ULL, 0x51CE8C228054990AULL, 
            0xD934E0BD66B1B193ULL, 0x1BF5F13F3B066FD4ULL, 0x81BF64EEFE41AE99ULL, 0xCDFCD2C5A6E1F26CULL, 
            0x0ECB2A48FCE08356ULL, 0x32B0013B1E613797ULL, 0x2F359F410EBA525EULL, 0x90435B858FC19179ULL, 
            0x60898934C70F4524ULL, 0x01C4104682669004ULL, 0x6E0D3014816B701AULL, 0xC9DDE4E156F1853AULL, 
            0xBC4FC484BA1D5E68ULL, 0x12309DDBD5C8DE41ULL, 0xADDC224155199225ULL, 0x40DCF9705F1B7F9FULL
        },
        {
            0x8005B00AB54C7668ULL, 0x2E9E6EC81DA9D097ULL, 0x20D5190166A1A239ULL, 0xF4E191FC1C49B021ULL, 
            0x34DAE06F86A7C169ULL, 0xE6E16BDA20AAAFD9ULL, 0xA3070897EE077838ULL, 0x23B46359BE14C652ULL, 
            0x47B8B5451EE2FEBCULL, 0x14652E8E1337F505ULL, 0x877BFFD2906421FBULL, 0x254A8EB5473F1667ULL, 
            0x74319CF7165AA241ULL, 0xAEA3D7BAA9B2DF1BULL, 0x5F137547B8CAC73AULL, 0xC37F2B657C16CC93ULL, 
            0xBE3D7187C1570EACULL, 0xDDA8F3049A93F5ABULL, 0x9920B78F8AF7AFF5ULL, 0x61D33CFB69FB49FCULL, 
            0x10772669D2AF6114ULL, 0xAA703E93B691F2ADULL, 0x638828C62DC26BCCULL, 0x0EBA572E19F31FD1ULL, 
            0x425AAE8BD2889FE3ULL, 0x7101D86BC383D17DULL, 0x6BF46610CA8CC1EFULL, 0xA8E3FF1ED21BB470ULL, 
            0xD76B6C9CB67B5516ULL, 0xEE1ACA0AE4E69FE3ULL, 0x10BB85AFD3B0DC8BULL, 0xC34B10A67CBDAEE0ULL
        }
    },
    {
        {
            0xB4A12D218BEE855EULL, 0xC461B3A35D86A65CULL, 0x195177DABAEA5521ULL, 0x7CBB224461654B32ULL, 
            0xD19E6DB2923FEBC9ULL, 0x8555103B93B3EAA9ULL, 0xC69F14B914EAFC0CULL, 0x1DF3ACF0AA89A383ULL, 
            0xCFADB365455DD2BCULL, 0x79845FECB76E4833ULL, 0x7AF2B1C0363AC626ULL, 0xB576E7822ADEC402ULL, 
            0x67B3F0EE2C917AAFULL, 0x442F42721D0361DAULL, 0xAE8C082BFDED79ECULL, 0xDD199E0D1682C2A6ULL, 
            0xA4AE74DA8A918E74ULL, 0x62E944C88F456E16ULL, 0xF7C5BC5C03BC955DULL, 0x0F8EC679AA9BF730ULL, 
            0x58C9319DDE4DB537ULL, 0x2BAAE2A376B7CC5FULL, 0xE7EFAEAF241CF45CULL, 0xA03038E282243D4CULL, 
            0x00B3AC105FCDB789ULL, 0xD320FF7E02A387E3ULL, 0x2C2049E78B7FAFA9ULL, 0xF7B1F5A62D941161ULL, 
            0xCD6C4C0D3F5206DFULL, 0x81AF60C0ED0747DBULL, 0x9E86BEDFEE8E72C7ULL, 0x53E2959AE2F6B480ULL
        },
        {
            0x2B03CB47C3C36B34ULL, 0x9B720182501CF12CULL, 0xCBFCFD38A5FF06ABULL, 0x012A8B42A571B396ULL, 
            0xA791AA2AE6F5FD01ULL, 0x3BFA5A2EB61EA0B1ULL, 0x8460F934C7EB2A7AULL, 0x03000C9B479D3DD1ULL, 
            0x84FEEA6E1890F5F8ULL, 0xCEDEF05F0CF92247ULL, 0x8B54B13ECCD4E52DULL, 0x3204BC6103879A37ULL, 
            0xC3AB2165C8D5B5F9ULL, 0x26D2B6F9FB609A97ULL, 0x61598BCB4F75A9E0ULL, 0xA9F5329905A2B7CAULL, 
            0x6CDF05674335C7EEULL, 0xA2CE213946290FCFULL, 0x5524DA629E4A02A8ULL, 0x22A4E5015762EC8AULL, 
            0xF28CEA86EB1F4F22ULL, 0xD9395B23DEC218ACULL, 0xE90819249DAB1F73ULL, 0x77839E8509A11D3AULL, 
            0x5A5954151552A23CULL, 0x7653D77789E59983ULL, 0x1424CEC8FD56D71CULL, 0x1E90B5C92298A4E2ULL, 
            0x1C1CF4D2DF491FACULL, 0x55CC9A1774162291ULL, 0x760B8ECD21A8593AULL, 0xFFAB49A0513CC27EULL
        },
        {
            0xAE673C4B335831A1ULL, 0x1CAD56C187944E3EULL, 0xE28EC24C9EDB72EFULL, 0xD371590B93731D67ULL, 
            0x483EC9B7F7FB8563ULL, 0xC354E54410FCE0FDULL, 0x4A5848197134F0DEULL, 0xC9BF85DBAA4FEB4FULL, 
            0x9B677D34C51809D8ULL, 0xC7BFB23AA9F1D356ULL, 0x709FDFBC08987275ULL, 0xB2E72C3952EDB8D1ULL, 
            0x436113318A721EEAULL, 0x211EB44856D6C2BDULL, 0x68C21195C0BC5332ULL, 0x7F586026A40483F9ULL, 
            0xC6AEA0210487D424ULL, 0x73F17F174E7F242BULL, 0x37DAE526EA101BD4ULL, 0x3CCA4C8D38343FC4ULL, 
            0x4C7A240A915C6317ULL, 0x8400C6046A0D5150ULL, 0x1884F5FF454C030EULL, 0x8F8DD5E2CBD379EAULL, 
            0x815328212D3F4B02ULL, 0xC0916DDD32115229ULL, 0x0B37F43F610FA066ULL, 0x7D51BFF8F5868C9BULL, 
            0x40524B54B6275F3CULL, 0x612EBF555843E23EULL, 0x7FB81635D6F6C284ULL, 0x0E8C0DF2D819C016ULL
        },
        {
            0x68574012091DF893ULL, 0xF0E314CD754D336AULL, 0xEAF04DC3A0E403FBULL, 0x4A8C65943617D58AULL, 
            0xA1651CA41F05E775ULL, 0x524D6B6BA3B4DC24ULL, 0x69608F7D70F96233ULL, 0x0E72B5708ADFEDA2ULL, 
            0x1C330CDAE929EC2BULL, 0x3A6E2FAFD0BBBA79ULL, 0x05CC23FFD0E9F769ULL, 0xF68E22C2F5F7A039ULL, 
            0xFC7EDF2847C6E4F0ULL, 0x84CCE305EEB0E61AULL, 0x7D9C4A64CD05E473ULL, 0x42FAE698A985DEDDULL, 
            0x4DC6700083F2DDD7ULL, 0x0000ED302756B3D1ULL, 0x5C3FD715FBE43854ULL, 0x4CE5970D25CFF272ULL, 
            0xBC7ABE3F810B95FCULL, 0x38EF36FCABC4E44AULL, 0x1427AAC4A6E4B5C6ULL, 0x8177A9A26E7A582EULL, 
            0xF06AB407B4E49B40ULL, 0xD0FED657C6BE7D94ULL, 0x6D035839B2261EFCULL, 0x139BCE6442F63E19ULL, 
            0x0530B292AAA81EFBULL, 0x659D90BDF4070B6FULL, 0xFDE0C8A5B208B8F3ULL, 0x02225F7003391BE1ULL
        },
        {
            0xEC0C63E0960CA58CULL, 0x1D6BEF6C6E9590DDULL, 0x6CC10804F36E7E4FULL, 0x38BA7CAC775EBB9DULL, 
            0xDE538BD968798182ULL, 0xE9B21BCCE849C032ULL, 0x56FF1725502E5BA4ULL, 0x055CFDD6B61325EDULL, 
            0x74B69A6C8ABDBFFDULL, 0xCB6AD6995CAEEF66ULL, 0x30998CEF03378429ULL, 0xD164D641FC7D0129ULL, 
            0x6D6DA0DE9FE4C6A1ULL, 0x017D7B823FB71E05ULL, 0xE2EA7C7E9AA8033CULL, 0x776744F5EC1CD0BFULL, 
            0x4D370C4DAE9E7061ULL, 0xA36036124F2301ADULL, 0x066CA99D676A76B2ULL, 0x299658D177AF2DCEULL, 
            0xD2FE992803D00B76ULL, 0x71B06A22BF576E91ULL, 0xDA1EFBB5ADC28D44ULL, 0xD1CC52479879AEE7ULL, 
            0x4380486E58128D62ULL, 0xA729DD973D9DFCBDULL, 0x7801EA8F6441C519ULL, 0xBD040116DF8C927DULL, 
            0xF3FC444BAB45E94FULL, 0x43BC315FE0928E09ULL, 0x149559879557C387ULL, 0x9A1473A4AC1DAB5EULL
        },
        {
            0x246928685D9637E9ULL, 0x95A13F64B452750BULL, 0xA7F8CAA3C33E1847ULL, 0x94A6C68DB1BFFEE7ULL, 
            0x794240B8910942B3ULL, 0x7770FFB94AF44C20ULL, 0x79858CB5766A2AA3ULL, 0x99822EA4682E9105ULL, 
            0xFF5D92FEDE3CBD80ULL, 0x3929712F0867AEC9ULL, 0xB0D03615C6BB3447ULL, 0x1812E40CB9F133FBULL, 
            0x7DF0A621D4A52D9BULL, 0xE483BF141FACDDE0ULL, 0x68E961F6F941BEB3ULL, 0x90E1DFF7FAE858A6ULL, 
            0x7B3E8CCC712A47F6ULL, 0xFBE7CFAF2E553112ULL, 0xBB597795B4C1D8DAULL, 0x6E2D9418876C7989ULL, 
            0x5D93BB452086446DULL, 0x297E30E47072843AULL, 0x68AE7FB0FD3218E3ULL, 0x4BF1681C0EC345AAULL, 
            0x6FC44EAB7CD92194ULL, 0xBF02CED49759A1DDULL, 0x37A14A4D2F31CA8CULL, 0xAC19B23BFA346070ULL, 
            0xF1EE0A149FBFE42FULL, 0x64AEA5A6F65E6ECFULL, 0xC9115E6D6C94F12EULL, 0xE25A4A4EBDC4B531ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeySpawnAConstants = {
    0x2A69A8955CED5D35ULL,
    0xB0CFFC9A1AF92C31ULL,
    0xC076CFC94C94DEA2ULL,
    0x2A69A8955CED5D35ULL,
    0xB0CFFC9A1AF92C31ULL,
    0xC076CFC94C94DEA2ULL,
    0xC727DF23D008C225ULL,
    0x669F513C0E418B1FULL,
    0xB4,
    0x0F,
    0x23,
    0xF8,
    0x1D,
    0x1B,
    0xA6,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Arcturus::kKeySpawnBSalts = {
    {
        {
            0xD057322837576742ULL, 0xCCC36D4FB912CD7AULL, 0x2534798A76226E9CULL, 0x71F12354F7467598ULL, 
            0xD8BAB1DEE38B549AULL, 0x375734EC8D6162BBULL, 0xBFE9E23A7F8E4E34ULL, 0xB8E38B994ABF32CBULL, 
            0x80A2C520F3F37BD8ULL, 0xCDCAFA9D5F7F79E2ULL, 0x6D35C2CBF01CC59FULL, 0xC08F2FCEC634DCEEULL, 
            0xE292AAEEAFC20B56ULL, 0x946017D70BA85C9DULL, 0x2F57A6E11D58ABBBULL, 0xC23793F0D9A5204EULL, 
            0x9737AE3BF8DAED58ULL, 0xC723D08A844B8617ULL, 0xA1FF7D52F24F6716ULL, 0xE7C9434917C0EED7ULL, 
            0x8C051FADFE48DE14ULL, 0x7AC26EF0106BC15AULL, 0x98A1672FCBF3EB89ULL, 0x49AA6F4FD3E3E331ULL, 
            0x5501CB453DC1BA83ULL, 0xE4055FB085CC461BULL, 0x1C10FF23CC57B405ULL, 0xCFAF5A366B473622ULL, 
            0x8CDEC7AFB761C4BAULL, 0x7BFF8918627718E3ULL, 0x8713F5C23E82CDA3ULL, 0x25F18D187085F20AULL
        },
        {
            0xFB58BCEEC5850C8BULL, 0x84288880C9298033ULL, 0x5ACC81BA2A1CC0C5ULL, 0xDE14D22705DEFF4BULL, 
            0x97953E818FBE9C75ULL, 0x1CB4B1F6712B49E5ULL, 0x9BACB993FD8E8201ULL, 0x97E739FA7262D4D4ULL, 
            0x009B346EA0497737ULL, 0xF2048BC686A6B1ECULL, 0xE280B05078DA1FFFULL, 0x8DA3CE86C72DFCC4ULL, 
            0x1DB8D738F9B147B0ULL, 0x52B91E8FD2480498ULL, 0xD582E6FA9B865F7AULL, 0x4534641F67B7EDADULL, 
            0xE20175D8DA3EA21DULL, 0xD068ACB45C7BBDA7ULL, 0x4ACDE9DEDF759866ULL, 0x16520DD58F23A1C3ULL, 
            0x7D4B18F8AF7A1D30ULL, 0x9422FC1F2E8734F3ULL, 0xA7D65882BBC2795CULL, 0x281481817D8604DCULL, 
            0x397895F9DEEDBBC8ULL, 0xB96D52EE9C1E1B9AULL, 0xDE8DFCB2141B4738ULL, 0x76CCDB1BC3CCB88DULL, 
            0xF42541D202F8111FULL, 0xB639A820EA31EA4AULL, 0x881C5C30031CFF32ULL, 0xF6892A9B95EF3006ULL
        },
        {
            0x03E35081D44B1944ULL, 0x8603E98252E2F330ULL, 0xEF2779E380437844ULL, 0xEA8E53695780B490ULL, 
            0x12E2F52FBEA42361ULL, 0xAD757F47555F4335ULL, 0xD548F82A05805EF1ULL, 0x6C0B011B7533C58BULL, 
            0xD6962FB3B8770BEFULL, 0x451F8C210CA1191AULL, 0x1AC2A514FC2576C9ULL, 0x00F7E75FD322178DULL, 
            0x827F3A6EBC77D7B4ULL, 0xB5EB0F7DA73D947DULL, 0xD6A793CCB55A9053ULL, 0x85CCD9B1B4594AE4ULL, 
            0xA9AE86FA76065DF9ULL, 0x64C1EC3405A68562ULL, 0x15E63A833C2DC2B3ULL, 0xDC76A2A1A4C8A04FULL, 
            0x55D8D9F3B63D0F23ULL, 0x9DFF56D1919035F8ULL, 0x1F95B14A1F3D89F6ULL, 0xA2550430EEE28512ULL, 
            0xC17A89A03A9EAD7FULL, 0x139143D4CEF3E8CAULL, 0xF2DAFB7E9F067085ULL, 0x4C78FE6982682650ULL, 
            0xC8A87C1B92917F97ULL, 0x2D88BC182A3CD3DFULL, 0x4C1592FF0F013D45ULL, 0xDE6085E8C040A8EDULL
        },
        {
            0xB4D2FAA470329AF4ULL, 0x3F3AF307FEB741A1ULL, 0xAC4BB2CC2778DD6FULL, 0x0D83A04619ED8BA6ULL, 
            0x106CEE4613FFD3FEULL, 0x5A18DBDDF1D1CE4BULL, 0xB1DB6DF1392A8BE6ULL, 0x4296842897E7FA11ULL, 
            0xD8214F9C29D8A2ACULL, 0xFA1818E209626F8EULL, 0x9C6EC387A2FD74A5ULL, 0x935B525FFC3DD445ULL, 
            0xF27F21E89EAF2FA9ULL, 0x987AE86CDF9E9362ULL, 0x2AB050DDDF06432EULL, 0x9AD33BDFB6422167ULL, 
            0x517D7A12E8F75CEAULL, 0xE5C57CF655347269ULL, 0x77C647BF4CF064E4ULL, 0xD808DE71A9402CCBULL, 
            0x9982C801D80F873FULL, 0x7BF2D04BCDCEEBDAULL, 0xDD2D814B34D9257AULL, 0xED2CA632C87E69FFULL, 
            0x12DCF863C1544B81ULL, 0x759D30881BED0912ULL, 0x760BF75E0B591849ULL, 0x5814D81D3DA11EADULL, 
            0x1688797926E48301ULL, 0x76EB5E5D9C9C81A8ULL, 0x9B5910E50B2E4317ULL, 0x292F71E5A50A52AFULL
        },
        {
            0x2DEDDB986CD074CAULL, 0x0B4CE25FE5C05CB7ULL, 0xEF8FB095459857CEULL, 0xE2ECD86BF34ABF2AULL, 
            0xD234B90F3CE92BD5ULL, 0x8BB6327FFC12A467ULL, 0xE79E2E44AF1E898FULL, 0xA9A974BECA7A34CCULL, 
            0x0DA3C29AF41D2420ULL, 0x501F8FAE1889144FULL, 0xA2ACF0440CBA3D05ULL, 0xD4A29D06228322FFULL, 
            0x2380EF5C1A1D0567ULL, 0x053BB04417EE9F20ULL, 0x955E0DAD060E5965ULL, 0xF54F2150E03F1563ULL, 
            0x8F61A6F89E4472D4ULL, 0x417D459F6EEA1F87ULL, 0x4D44B5F1FEDD99C0ULL, 0x059C31699DAF77C9ULL, 
            0xABEA3C603C48E146ULL, 0xBC4C7E9F38A06BE4ULL, 0xCA2458246F366D03ULL, 0x7FF796FD967348E3ULL, 
            0x8C4C7FBD2298631CULL, 0xA7D3AF7050DDA80FULL, 0xB388EEABDDDEC725ULL, 0xCAA10BC2041AA7FAULL, 
            0xC221A91CF947FD91ULL, 0x3CBE083B2F784FD5ULL, 0x3F57A9982B5D8358ULL, 0xA6269005A0601E15ULL
        },
        {
            0x8BA625199142E0F2ULL, 0x28420A1BDDFF571FULL, 0x6D6DD5C4C2E4C4F3ULL, 0x15EA9A7D9530E4A8ULL, 
            0xF58881A20D502B08ULL, 0x8C594AD758118800ULL, 0x0903ACF94F564C6BULL, 0x9091627BF5E375E4ULL, 
            0xA17DAB1A31DFE71BULL, 0x7E6D63DA8AEB7D97ULL, 0x2383CBF2B152E488ULL, 0xB7F47D8E711A2847ULL, 
            0xEA0EE1C2EA258242ULL, 0x2DEC64075BB4503BULL, 0x56DB7BA08CD036E2ULL, 0x33D02C21C84FC77DULL, 
            0xF6DE5DEFD9C1FE3FULL, 0x1B90AC4BB79A0EADULL, 0x78638AEF847B34AAULL, 0x67774E7DD955511DULL, 
            0x2CF8D115ADA61674ULL, 0xF2F9ADB4F0D1B7C6ULL, 0x047DC930927EEAE5ULL, 0x090296CC7B14A997ULL, 
            0x0ADC5BC7872FE905ULL, 0xBA73F7983D3A6FF9ULL, 0x43438975732D0C45ULL, 0xADB3AB485F28ABEEULL, 
            0xF654B473E2AACB8AULL, 0xF6F2A71D5FF3F3C0ULL, 0xD1CB4BEEF422BC34ULL, 0x77D1C3413BB99128ULL
        }
    },
    {
        {
            0x5216A472DA9B4D35ULL, 0xA94087DBF0BEBADAULL, 0xE6FB8C687A6E433CULL, 0xFD2F499744C33975ULL, 
            0xF57029317FC58B0AULL, 0xF68E3C670E6F49D2ULL, 0x3FAB6BF238A1A7CBULL, 0x0297D74002CC0C4EULL, 
            0x6ADA1B323537DB9FULL, 0xD78135417F65A0A1ULL, 0xEB456158341A4337ULL, 0x1A38B1FBA380332AULL, 
            0x9868F303609A1166ULL, 0xE23E7DEBC858384BULL, 0x7065D0C37210AA84ULL, 0x9D5326B8625C8EE9ULL, 
            0x7A7B617096BC7BF6ULL, 0x1CB16BDB7ED94ADFULL, 0x2AD9139183FB84CEULL, 0xE99429FFD7B8EA61ULL, 
            0xEF9467E2C16AA6D5ULL, 0x3B8671C896CE8728ULL, 0xF8CFE14943F1CF90ULL, 0xEC46BAA1403CD948ULL, 
            0x3D31F63E312DEC92ULL, 0xA0C1CDB114C28690ULL, 0xA451184EDD8EC0B3ULL, 0xF6D3795C91EFD1EBULL, 
            0x1B5677BAD5DA2804ULL, 0x961042FB1329CE33ULL, 0x9E6345184ED5265BULL, 0x79F1FD4ADA18A8A7ULL
        },
        {
            0x8551ECC469BB7B6AULL, 0xB7CF1E2127DD4D00ULL, 0x77CDAD80425DB9F5ULL, 0x061B13FA9A01C976ULL, 
            0x86AD334B96654C8FULL, 0xCFCEE79704E86FFDULL, 0xA36F4D8F8A9CEDB1ULL, 0xE94AFCED647ECA4EULL, 
            0x60213D646A9F76DEULL, 0xAC8906A1AB11A8BBULL, 0x7ACC84CEC924E42BULL, 0x0B1AE2F88DFB7CA6ULL, 
            0x58EF8A61D5D18C11ULL, 0xEDD04BB8B6CBA90FULL, 0xEDA5DA08B507DDC9ULL, 0xA9EC981EC0911C53ULL, 
            0x79B7EE8CD65FD395ULL, 0xD1659058CFB9B766ULL, 0x03C4EB2F8FDE064AULL, 0x14E0CF06EB3420D2ULL, 
            0x6739A00B4027904CULL, 0x4E90861B57AE8AFAULL, 0x40AAC46BF18211F6ULL, 0x243D721818E2773CULL, 
            0xB3BD518939FFF027ULL, 0x946A0904F2294676ULL, 0x9C7B9C28637B0447ULL, 0xE9F30E10B5EC4BC8ULL, 
            0x3AAA013AE79CF6A4ULL, 0x3A81BE24F511CDCAULL, 0xE334A9FD80B3BB4EULL, 0x1D19D611B9DFBE65ULL
        },
        {
            0x6F309BDC448E6056ULL, 0x81814231F051F4DEULL, 0x6EE7BC8BFEA803A3ULL, 0xED26E1942F850C06ULL, 
            0xC5D4CB96C8796DE6ULL, 0xF4CC688CDF59746EULL, 0x4295757D8AE0CAE8ULL, 0xB9F58422C0F0AF48ULL, 
            0x664F3738AD026BE1ULL, 0xF3BFF8428A49A548ULL, 0x061F6A19563DA2BAULL, 0x8025958E0B1AC7EAULL, 
            0xEC842A6B9C4EAC34ULL, 0xD842493494022579ULL, 0x0C9BC19E8B86DB5EULL, 0x37E62ABA031AB0C5ULL, 
            0xF899E6A03CDAE8E1ULL, 0xF0A53B93A75BC3B1ULL, 0x252E1D06AE63C8ABULL, 0xA7DE4518B8DA2782ULL, 
            0x59B563A132D79773ULL, 0xD2B15A065FE00A24ULL, 0xA48561D756AA6AF8ULL, 0x693BA816B00411CDULL, 
            0x2BF39A88CD13F1E7ULL, 0x0C922B19076C9E9FULL, 0x9230740F6C2D82A4ULL, 0x33E941A61272B537ULL, 
            0x089920798D559BCCULL, 0x7FB4BB7CA14B35FFULL, 0x63F473AF96D477A7ULL, 0x67B020201F376214ULL
        },
        {
            0x81545FF12A394FAEULL, 0x79186A6565097F66ULL, 0x210781E6FEF04D6BULL, 0x31271E250DD5FBECULL, 
            0x5CB2083145A63343ULL, 0xCD965527E07B80ACULL, 0x564BC0527FED1E50ULL, 0xAF406D58D42CFD5FULL, 
            0x21C2DC939AF4853BULL, 0xB257F668DF472987ULL, 0x1DF5682C295BD3DFULL, 0x9FDF63F60E47E88EULL, 
            0xDB60C62B1FD34FBAULL, 0x4B258C89D210768CULL, 0x3C9CEACD15054DF7ULL, 0xE32B22B882EEC949ULL, 
            0x043A9E103587B913ULL, 0xC2C6AE67DEF3F3B2ULL, 0x9494E12576061E93ULL, 0x8625D2EE6E77663BULL, 
            0xF1EDD515B82045E4ULL, 0x5A90D92603D57E20ULL, 0x4C049ED47494FA59ULL, 0xDCA437BE10327354ULL, 
            0x91FEB31A74A077D6ULL, 0x9613E3EE5F81452EULL, 0xC05902AA70E5D7DAULL, 0x6A3EFB27985CDC1CULL, 
            0x24142E627D1E9E57ULL, 0xB1EC3C740D3FFB2CULL, 0xD000FA6195935E0FULL, 0xDBB0E32545E5EA60ULL
        },
        {
            0x6F487821061DD196ULL, 0x46C5F3BA176E406AULL, 0xF0D12F6FF219EAC1ULL, 0x41AD9054A8F3FD33ULL, 
            0x8FFF397254477CF0ULL, 0x52AED1EBB322C037ULL, 0x706668CABAC1CAF6ULL, 0x4E06C89F1878E7C3ULL, 
            0x4786B5DB8BA33EF4ULL, 0x6A0D15A8D3EAB170ULL, 0x70901FC031EF5001ULL, 0xE3DB8111EE2DE6DDULL, 
            0x7A3B13DEE6B8D718ULL, 0x8211C2032669AF10ULL, 0x7B1BE23A504BB4B2ULL, 0x348C35401E096D1CULL, 
            0xD0E69C72A6BCAA43ULL, 0xD069270597CFE862ULL, 0x94D69BE71E0CBF7BULL, 0x146D9F41DD18D651ULL, 
            0x7B68B1B5ABD3BDA8ULL, 0x3D5B65B400FDC794ULL, 0x76FD55E17B1A0D42ULL, 0xA94608EC4F88EF31ULL, 
            0xE3F6B4D76FBE3E5EULL, 0x39C7BE0241E37CB5ULL, 0x8FE449E77AE3BF75ULL, 0xF09968749857BEACULL, 
            0x4522C82A0F4B7607ULL, 0xD9029D6D815920F5ULL, 0x2DB13AB44A45441CULL, 0x55323098A40810EDULL
        },
        {
            0x86B93A687511E6A7ULL, 0x43F65F2DE208E9B7ULL, 0x460A55451AA4556AULL, 0xBF3B7FCF68656FACULL, 
            0x559F3D46DC9D6F1AULL, 0x10B359F8EE8972CEULL, 0xF6A51644145C07BCULL, 0xE72B1A6FA5C79008ULL, 
            0x1F0A7BB324F21138ULL, 0x01F026091DA5A050ULL, 0x9F246644544B1AB7ULL, 0xCD2D9B347FCC0CD2ULL, 
            0xB9790C8778E6AF7AULL, 0x930706B8609332F7ULL, 0x97422D504D187F7CULL, 0xA12B7E045F98C432ULL, 
            0x510C895B1916982CULL, 0xA57CCC298CCBC1A5ULL, 0xD0EB500A042F594DULL, 0x30FBDCC2A4CB290BULL, 
            0xC5627AC4D38BB7D8ULL, 0x0DAE4D4EFA61777CULL, 0x4CCEA06A12D3AF32ULL, 0xFEBA50DC727DBF82ULL, 
            0xB4A1A911F5103E94ULL, 0xA7941B369B424E72ULL, 0xEEB0B3F719A4E6D4ULL, 0x0D6352C15822B2EAULL, 
            0x029D29667163B8FDULL, 0x029DE7F0B16DC41FULL, 0x2E1004366DC59585ULL, 0x9DC0A2A05BDCC2A8ULL
        }
    },
    {
        {
            0xA5175C379603F981ULL, 0x4BE23AE34E02D2A4ULL, 0xE7609C60EC57A3BFULL, 0x0BF1320F401D90C6ULL, 
            0xE9B737B1B38D1F3BULL, 0x733BBAEB55D3CBE9ULL, 0xD4CB3A4440C247F2ULL, 0xA64F7BDAEE0CF71AULL, 
            0xAD464787177414B0ULL, 0x35AC60C664DF355BULL, 0x2812BC300DACB9E5ULL, 0x162C1FAABF8F0E10ULL, 
            0xC55BAA38FFFBD362ULL, 0x8791F677F345584CULL, 0x9505917D13E13A6CULL, 0xD459AAE50C8758F6ULL, 
            0x2822F4175B1B8657ULL, 0x0BDF49DB4D4CEEE7ULL, 0x90A2A2ED83889930ULL, 0x5B46FB3EBA593262ULL, 
            0xA29F8C51E866467EULL, 0x2363E4A63E930E7AULL, 0x7BE86B34AB623554ULL, 0x7E92B897107CAEEAULL, 
            0xCCD041389DAF1873ULL, 0x1AEE1539F208BAFCULL, 0x9240D95E8244B384ULL, 0x431FD36EDB3F8397ULL, 
            0x29C6E9B376831614ULL, 0x444E700234F84BF1ULL, 0xA100AB00040E089DULL, 0x86599043B4C7365DULL
        },
        {
            0xED88258060C63812ULL, 0x883C2695111A5B78ULL, 0x88EE77A36281A449ULL, 0xB13266F9A1BF327AULL, 
            0xC32A41C74E8544FBULL, 0xBCA7CA66520616E9ULL, 0x2C5BB832087B9AF7ULL, 0x71757D48497C4809ULL, 
            0x659416EA89154E9EULL, 0x3E86DD3EA0368E62ULL, 0x1702C06AB771F061ULL, 0x08AC4331E0FF4E55ULL, 
            0x70DE4A101B2A63F4ULL, 0x5FDE45D8534DD3A8ULL, 0xE9787A57D787401DULL, 0x35007354C3E60415ULL, 
            0xE32CA2BFC66165F8ULL, 0x7A6EBD15DE6DC85FULL, 0x69ACD3921A492046ULL, 0x0D270AEC7DB16E81ULL, 
            0x5E66D5DF30D8CA3BULL, 0xFF3D52C1DBFCAE92ULL, 0x4E2088F9AE2682F6ULL, 0xB39E658D9B48A4BEULL, 
            0x54DAA0541FFBD87FULL, 0xE53C56D7318DF19EULL, 0xE0189940875B2AC5ULL, 0xFE77E0AC0FF0DB36ULL, 
            0x6196869D1DDF567EULL, 0x815CB90BF0AF3787ULL, 0xBEE7F6D3776E90B1ULL, 0xC55A645236FAE3CEULL
        },
        {
            0x8F38562CEEEC6841ULL, 0xA1C5C68911ACAE84ULL, 0x4A9961AD9C078FBCULL, 0x494B24373EFE1951ULL, 
            0x556BB09AE4A1E7BDULL, 0xE7629645326E381FULL, 0xFDCB3A821DE62221ULL, 0x03AFA51D1A29A300ULL, 
            0xC0C83500386783C7ULL, 0xFA08FB1408AB2416ULL, 0x8B901A2D34FD5635ULL, 0xDA79536EF8096E8CULL, 
            0x3AE26753D7A3AC4CULL, 0x93FE926FA893CA55ULL, 0xB997409EF0EB8364ULL, 0xCB74698FA939AB53ULL, 
            0x7BFFC170D6045E1AULL, 0xF562AF2AC8C2276FULL, 0xD995E4CE53410F4EULL, 0x55F986BBF634DB2BULL, 
            0x71FF2198A2057B50ULL, 0xB9730C21B42043D0ULL, 0x8644E4D455077E21ULL, 0x0D53D616745C85D7ULL, 
            0xF951A6B9C580F972ULL, 0x0BCE9A48C0622DFAULL, 0x7A8801EC244394F0ULL, 0xB335098B49B26D49ULL, 
            0xFFE6220696170566ULL, 0xBA67F0E1B38E1557ULL, 0x03A74A052EE9FFAFULL, 0x52C4B2D898D0AE0DULL
        },
        {
            0x62FEAD0342C97E7BULL, 0x1868EA5B19D4BC33ULL, 0xC1B669B24300194EULL, 0x0DE031F0C7C73B2CULL, 
            0x65A8CB4E40FDAA1AULL, 0x36C34F58065051CFULL, 0x27D1BF04313526E7ULL, 0x8191962593C66D5BULL, 
            0xB5A076352221E780ULL, 0x7EB9FDE45CB5902DULL, 0xC339015769D0D14EULL, 0x2E7F4DF67C8F3106ULL, 
            0xDAFBC5832A105D75ULL, 0x2FBCC59543742800ULL, 0xE82527EE9B62F8C3ULL, 0x33DFB4C42828FB5CULL, 
            0x026E1F4917FE28D0ULL, 0xCCD6D573E4594508ULL, 0x711CB7C9178DBEE2ULL, 0xC609C3D35D3A43B9ULL, 
            0x5842A3D2333433AFULL, 0xF2FA558F1E39AE80ULL, 0xCDD0884AC6BFF4ADULL, 0x4702FDC0A61E3E92ULL, 
            0x07D21F8CC9F1D163ULL, 0x1401B89A6B282396ULL, 0x80C1F20906CB46FCULL, 0xD7B7CF76F61E4F60ULL, 
            0xEA7823430AABC529ULL, 0x590757B68016D5CCULL, 0xA518BA874159517DULL, 0xE59A575C3114F285ULL
        },
        {
            0xA4A76096D92081E5ULL, 0x63D13B8779F1CDF9ULL, 0xAD0360CFF68D85E1ULL, 0xE4B0434F2B6B13ABULL, 
            0xAD17F9A45E0891E2ULL, 0x7E7E9E25AC8BA480ULL, 0x318D075DD39EE7D3ULL, 0x10480A604A74CEC1ULL, 
            0xE251B00D1ECA47C2ULL, 0x1B2EEBF6633C1A3FULL, 0x5B3402A18F0B7563ULL, 0x36BDEBF791336F9FULL, 
            0x26C136176EAFB4F3ULL, 0x1A710D806D79D5F7ULL, 0xA843F0F622AA657EULL, 0xB182E0CD1B3FF6B4ULL, 
            0x1FC4BED023761179ULL, 0x58E225042CAAE867ULL, 0x751D5FDAD553C9A1ULL, 0xDE8EF49C9D21B5CCULL, 
            0xB39087FFA0C000AEULL, 0x3B46288AD527DC7BULL, 0x5FA54053D8E08F76ULL, 0x6C2C1FA40F96475FULL, 
            0xBFE3317E88263572ULL, 0xE3FE4CC9B198CD4FULL, 0x6F708FBDF8F469EAULL, 0x78618AB0A29CD4D9ULL, 
            0x75A62EA3E3FE42CFULL, 0xBB9A49E6E2879FA9ULL, 0x8BA057AF95513657ULL, 0x4EE4A4EC28BA4E9BULL
        },
        {
            0x7BD19BCCE5B7E795ULL, 0x072D9FD38A08D8D4ULL, 0xA0C94134F2745732ULL, 0x756511086B4AC20DULL, 
            0x9FABC2F55CD0A479ULL, 0x618A1F813F3FB9F5ULL, 0xA0087F8337B8A108ULL, 0xE6D6801D46F31880ULL, 
            0xC4F0FF7220D0654BULL, 0x4C664F741B320EBEULL, 0x729859F49C1CA5FFULL, 0x9B1D273E717F925FULL, 
            0x082B2B4ABBEAB169ULL, 0x4B6D1CCC77E936F9ULL, 0xD69740DDCC472682ULL, 0x3CF906B04C70F159ULL, 
            0xA4DF12700B67EFA5ULL, 0x116422CCB259DF98ULL, 0xE61D1232CD9E9B04ULL, 0x00FF5E393B9B25EFULL, 
            0x5A6F7C38DE2FC82AULL, 0x3F4170755894D1B9ULL, 0x7540FDE734FD54FBULL, 0xB444592A347EABD5ULL, 
            0x488C7F2687A66468ULL, 0xD99B69ECCB3ACDC7ULL, 0xAC991A4BCA125C49ULL, 0xE5401D2A8A291F2CULL, 
            0xEAD5E3B43C7AD80BULL, 0x9AFE476C208540A3ULL, 0xE82541DD91F23F3BULL, 0xBE19BB44B0BD2FCAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kKeySpawnBConstants = {
    0x008B6461FBADE195ULL,
    0x7B8EACCC228C9DE6ULL,
    0xD5568ADF2B323738ULL,
    0x008B6461FBADE195ULL,
    0x7B8EACCC228C9DE6ULL,
    0xD5568ADF2B323738ULL,
    0x127675DE6E8B9A99ULL,
    0x626B7FC2E036FAFEULL,
    0x4D,
    0xF8,
    0xEA,
    0x47,
    0x29,
    0x2C,
    0xC8,
    0x68
};

const TwistDomainSaltSet TwistExpander_Arcturus::kSeedSalts = {
    {
        {
            0x408F13194555E5B6ULL, 0x673E9B67AA22248CULL, 0x0120D1F3BBD30D10ULL, 0x925E880BC2936C81ULL, 
            0x9E5AA4EDE4E70294ULL, 0xFB0B132BF8CFC269ULL, 0x2FB0C7E5C4086A34ULL, 0xD1F6639711AAC339ULL, 
            0x18F380D2682EAD45ULL, 0x61F41D57E585A637ULL, 0x49515CAB487B875BULL, 0xA40DD908AE19B012ULL, 
            0x2B99B60E11832772ULL, 0xF1897DA47D58A831ULL, 0xB571D49DC63AF8F6ULL, 0xC280B50F61EB507CULL, 
            0x12B3F0C8196E51C1ULL, 0xC3AA97F8B1697998ULL, 0xE58AA59510B54C11ULL, 0xBF0696421F2D542CULL, 
            0xCCE7BC3E7AAC789CULL, 0x28BD5C09E24BB0D3ULL, 0xA1000822120C2550ULL, 0xD0343C9792CEBD6DULL, 
            0xC4DB4184D72AA982ULL, 0xE3C7086137CFE89BULL, 0x098DA3E7581F5534ULL, 0xEFD7913E0F43C04CULL, 
            0x3C8DD73BABE4367EULL, 0x26839612B9AEFF79ULL, 0x45F861D80EB29052ULL, 0x3F577703C6D2C254ULL
        },
        {
            0x9E2D57A596A82595ULL, 0x3CD20F49D432CB9CULL, 0x5E3E7444C23C51A2ULL, 0x41319686C6B35640ULL, 
            0xA0D2188BA19EE345ULL, 0x90038CD645590FE8ULL, 0x43B0F74F00DC37D2ULL, 0xD63A6921BFB1074DULL, 
            0xF7D54C78CAADD11FULL, 0x60804C5AEA929A89ULL, 0xB62E0A306751F283ULL, 0x9CDDAF44DB9AB4BEULL, 
            0xFCC3CD6B596E9F58ULL, 0x2EDABD3DAC0F6813ULL, 0xEEEDD180322A4E4EULL, 0xB9E351A4B50DCBF7ULL, 
            0x43A865E6701D945BULL, 0x2E89E9A5E52376EBULL, 0xDF5482E2CACD5911ULL, 0x186591CA550C721CULL, 
            0x512436FB4DA7DA7CULL, 0xBBE3565E9FCD71CFULL, 0x2B8E0C4AD3781C27ULL, 0x4F8630463B5E4E0AULL, 
            0xABC5161F7212B7C6ULL, 0xA18A69E57CFF9416ULL, 0xDB195D4FC0967C56ULL, 0x2D456D06A71BE905ULL, 
            0x522443C2AAB68BC4ULL, 0xEB2FF00904592163ULL, 0x10A93AAF8666521AULL, 0x6DDA6EAC2E138931ULL
        },
        {
            0x3E8E222170C24AAFULL, 0xAC7084EDB33E7077ULL, 0xEA246B1526C2C7B1ULL, 0x0AF9AADF777BF927ULL, 
            0xC2CA5F78F2671D26ULL, 0x68F6647C80DFD753ULL, 0x0BCFBBDD686621BBULL, 0xA991AF53C6219433ULL, 
            0xF0217D14D221E6DFULL, 0xAEF371C8F2FBBAEBULL, 0xB05F55E8B1310228ULL, 0xEC28658D97FD099CULL, 
            0xC6DFC6A174FC27EAULL, 0x010E08312CF011ECULL, 0x74BBF06BFC652542ULL, 0xD6E1E00A46705827ULL, 
            0x8D9CE94C648770D0ULL, 0x7C9CF282BDF47782ULL, 0x4A59D73A2359EFCAULL, 0xE73226BDC9625A40ULL, 
            0x6A2FB7D88177A593ULL, 0x3B9B92827FCCA29EULL, 0xCA76CAF70A6589ABULL, 0x5597977D7DB63701ULL, 
            0xAE16342FCD257253ULL, 0x454E3D9FF0A8B191ULL, 0xB75DB34EF3856BDFULL, 0xB464F986EC176124ULL, 
            0x29F97D3571836907ULL, 0x2F2468C29BA1AA0DULL, 0x8AD98ECC2E695616ULL, 0xBC4BC8A46CA25A38ULL
        },
        {
            0xEB00796BFB2569C1ULL, 0x3BBF4A1CC2E09839ULL, 0x6127C858DE5A8F12ULL, 0x4BE16DA65700DF83ULL, 
            0xBF062F87102C3B66ULL, 0x356B6C8B0E43A097ULL, 0x02F1CF64A40A36F1ULL, 0xF647C5E3DDAC0459ULL, 
            0x610E909927E066E6ULL, 0x1BEB8065AD06154CULL, 0x92BFD23252DB3049ULL, 0x81FC9CB664002B73ULL, 
            0x822DD0D9D2D46FCFULL, 0x808449C0F1411FEDULL, 0xBA4F65E401CA9ADCULL, 0xF1788DB2A4BA2AE0ULL, 
            0x4B4059C6FD861D10ULL, 0x1852C0B3BD45673EULL, 0x495B4AA03D7CE697ULL, 0x791F67FE817DC0FDULL, 
            0x7DCA0F3DC0164D02ULL, 0xF0A77A0B5D11D0C1ULL, 0x22C3DE14C69EE072ULL, 0xADCF698E5033B15FULL, 
            0xA979DC451E05EDCFULL, 0x35CA06136CAF176CULL, 0xCF0647E583CF2017ULL, 0x115554A3D8355945ULL, 
            0x1A5DD403387A2128ULL, 0x4F8869DA2EDB2AA1ULL, 0x11D08EA474655337ULL, 0x19D2EA99F844E823ULL
        },
        {
            0x388194DD817AAC95ULL, 0x342081E40844C8EAULL, 0xA06836A572AC3284ULL, 0x5E9C0F2BBB761ECEULL, 
            0x24A46C7BB364E74FULL, 0x818609C22FE97305ULL, 0x1C836EFC1DF56123ULL, 0x49C519C48AB0B164ULL, 
            0xD8D81390AE14756BULL, 0x4291F465A35CB8EFULL, 0x56D031EAD0B8915BULL, 0x1FEB8BA5E97AE806ULL, 
            0x878355778AFF0626ULL, 0xC7898E2D1E63D609ULL, 0xEB7BBC65832FE9C1ULL, 0x58DE641B0DB32120ULL, 
            0xDBB591A2C7778737ULL, 0x8ADA86D23DE0C4D9ULL, 0x3EB90483B2D450E1ULL, 0x18CEC5798FC0DBFDULL, 
            0x0FAB7F40A81E4ACEULL, 0x44E68DF18325ED85ULL, 0xBE9C2407C46F0977ULL, 0x91888F3FBD66F404ULL, 
            0xF27E5017217A00E1ULL, 0xCBA0075595556DA4ULL, 0x63BD684498896A5CULL, 0x8667703ED177D29BULL, 
            0xB42DEA819848EE90ULL, 0xA94DE5FE4310C1C4ULL, 0xCBB125F56A0893B6ULL, 0x3ECBBC2EF3D1A911ULL
        },
        {
            0x3B9A6A624B745CA2ULL, 0x559A7C2AB00EC208ULL, 0xF39FD5283C88B6D2ULL, 0x9BA594C75B3DF2C1ULL, 
            0xEC689FFEE7C9E5B7ULL, 0xECC8461C5A636A97ULL, 0x5D619509020FE332ULL, 0x689395E77B0A74A3ULL, 
            0x8A203C27C91C891BULL, 0x2B3E87F2CF8B3CF1ULL, 0x31ACE5EB151E67DEULL, 0x9E60BE6B52A1BE35ULL, 
            0xDAA2D750E4D44A80ULL, 0x5749AE16FAC733ABULL, 0xB3B0438197EF2A5CULL, 0xDE09EAB676CC8BF8ULL, 
            0x2B5496A8AEBF5B53ULL, 0xDF9C17A2D3000A66ULL, 0x65EB746AA5A70148ULL, 0xA799C35BFE0DD017ULL, 
            0xC977BD45FBD115FFULL, 0x7EB855FB35E286E8ULL, 0x7DAC2FED5683DEBFULL, 0xD5EF5FD7CD412A47ULL, 
            0x9EC41F9568BE2C3BULL, 0x9B4B9C57C00FC21EULL, 0x6563B68547018EBBULL, 0xBF24C6BF2414DAC4ULL, 
            0xFDAAA213A6AB010DULL, 0x784C261CB5E0E32BULL, 0xE2F142180112D94AULL, 0x0803A43F67F01437ULL
        }
    },
    {
        {
            0x1B8CC071E7A29CAEULL, 0x1A75D6367B17010AULL, 0x6390AC11BA8C9FB8ULL, 0x19D5850AC49F705CULL, 
            0x80C6739FF87FB484ULL, 0x0FF43741E73EEB76ULL, 0x6DB676BED8ADC4F5ULL, 0x9F29BA13E3EA9782ULL, 
            0x418426382278B065ULL, 0xC5FE3FDFB2C363CEULL, 0x8A3D4F5785CD7DA1ULL, 0xDE9E7FC66A397B9EULL, 
            0x23AEAB3EC0983EB1ULL, 0xE02B6D2B7D5DE199ULL, 0x8851BF975839E42BULL, 0x1040D59F9B6CBFF4ULL, 
            0xBD1341B48BDB5A69ULL, 0x386ED14D0C6FE3E4ULL, 0x0BC78AC38FF245B2ULL, 0x396002C214FEBA84ULL, 
            0xA20A50F876198C6CULL, 0x588C097E567278F3ULL, 0x251CA72CB0AA392CULL, 0x8F008DA0E0039953ULL, 
            0x8B945595C1ECEA8FULL, 0x609F8DDA64690A55ULL, 0x8CE20AEADF95EE05ULL, 0xC28618204FAAEF64ULL, 
            0x286E61265B50BD02ULL, 0xDE98F64D247F7EBAULL, 0xDD7C3A8D7EFA3B0EULL, 0xE460D9B72960B491ULL
        },
        {
            0xC4F5E41645960D07ULL, 0x16A7C70FAFA28DA9ULL, 0xAABE2780CA972C88ULL, 0xB66462CAC41ACA16ULL, 
            0x53E873F8671A3046ULL, 0x9F0C257FE30E71D7ULL, 0xC98EE784D9EDF296ULL, 0x6E5AEB6540121AECULL, 
            0x94D73FA76F4079F4ULL, 0x3191EBAC9B9953FDULL, 0x6A545DFEE07D30ECULL, 0x2B9D7464687B7ABFULL, 
            0x797E8DAA5BA117C3ULL, 0xF983B41BDD682EDDULL, 0xC85F2581BBB5672BULL, 0x40A8E86A52BBBFCDULL, 
            0xD97E53938FDB1283ULL, 0x2D3127F2844103B8ULL, 0xB829E48F3A615A29ULL, 0xDF386C74D703B2D2ULL, 
            0x9E1DCA3701B4B980ULL, 0x63F851A9D2317953ULL, 0xF1B74AAA6D748EE6ULL, 0xFE3DCA47314725EBULL, 
            0xEF06F610F002F604ULL, 0x2F169429D0A5128EULL, 0xD2303E5AD91DC75DULL, 0xAC7D6977E0CC15B5ULL, 
            0x9FCA6E290F5406EFULL, 0xC1395BF14196F2E7ULL, 0x6F23F76F8857CB2EULL, 0xE3F67F4BD9FD7489ULL
        },
        {
            0x69211231F4E5C923ULL, 0xDEE71180A1416671ULL, 0xD163B679DE85ACABULL, 0xC3F9DBB715B42862ULL, 
            0xDCE05F995D78682AULL, 0x0A8B7344705EAB63ULL, 0x98855FED4C595F10ULL, 0xDACD9E8111DD6CB2ULL, 
            0x009FA7F0C557E8DBULL, 0xF52F7FE3B6CF7C05ULL, 0xBED9703D2928C50DULL, 0xAF56B7F29944A934ULL, 
            0xBEBE4357F31458FDULL, 0x681722E475473D6BULL, 0x8BE62D57BCB66F08ULL, 0xA24537DEBF41F72CULL, 
            0xF1C10F8A08B0839DULL, 0x9FC4B1A9077A5208ULL, 0xD6465E492922AC68ULL, 0xE6E23061736CD1AAULL, 
            0x4C723A5BC0572299ULL, 0x488AFF566D9F5C0EULL, 0xC2EC27AEE059A051ULL, 0xE840C565738D6974ULL, 
            0x008DFC3526B17FBAULL, 0x112A6F664BA25C4BULL, 0x26040C34E1EF22FFULL, 0xC82390884742BEA8ULL, 
            0x6C5043EC6CC7F47DULL, 0xB7F2FA6CF3EF2191ULL, 0xFC293B38C2784D08ULL, 0x414EEAD963A19F20ULL
        },
        {
            0x7E238BE684997179ULL, 0x9A3CBCA14EEEF86BULL, 0x81FF6792A78438E0ULL, 0xFA2E774A234F1EFAULL, 
            0xA694EBA7FC1BBFD2ULL, 0x033C449B0DAC9620ULL, 0xDAB15D5938C6E878ULL, 0xCD244DF84C907F75ULL, 
            0x0A8D34FAC723793BULL, 0x3845AA9183201196ULL, 0x770195FB13FBCC8CULL, 0x495060A37E910D15ULL, 
            0x361199A29F26A1E8ULL, 0xAA2D461CE9BDBA99ULL, 0xB3CFD8E6C04F56A9ULL, 0x386FC7A2336D9542ULL, 
            0xB7ABA44D85D0510BULL, 0xD71D9E4CBAC007CAULL, 0xB3F3C6ED66F338CCULL, 0x100486EF86523477ULL, 
            0x2996522837E84D25ULL, 0x0D7D5DFB4B904540ULL, 0xCABAB9E32C73622DULL, 0x207951598B1FBB1CULL, 
            0x3BF1CAAE2261D185ULL, 0xAB0ED9E50F609659ULL, 0x724479645B942F00ULL, 0x5AA7C7960F55B00EULL, 
            0x169D354D4FA64DAAULL, 0x1AEC945AAB380714ULL, 0x5B421576FCE9C1F0ULL, 0x2DC5943BEEB46B33ULL
        },
        {
            0xF9AA3A09DDB9C7F3ULL, 0x9106640A279E7880ULL, 0x488685D487D8B004ULL, 0x14EC7CA8FF91FF5CULL, 
            0x4C7696034018B2B2ULL, 0x618A4906B8363FCBULL, 0x85039B752CB061AFULL, 0x05ABAFC450AC1AF4ULL, 
            0x5AEB95E8CCA20E0CULL, 0xDE90E9943BD55F3DULL, 0x69B48C00A608809DULL, 0xE6BEBAA639B7F05EULL, 
            0x1D4DC5A9E0F00333ULL, 0xB5D5A48371A60216ULL, 0x490B40EAA60BB854ULL, 0x89A47E9D98D067AEULL, 
            0x5EA67535A291EEC9ULL, 0x20AD2CAD80391EF7ULL, 0x3928B797676E3E8EULL, 0xF18D09F06F9DFC13ULL, 
            0x9AF90BF86E2A8C11ULL, 0x3DFEBE97F6B9AADDULL, 0x7F2B3F9505348E13ULL, 0xD514F423DD043175ULL, 
            0xE74E0E764D94A25BULL, 0x5DADBDF9934422ACULL, 0x2A019852B5D445FAULL, 0x255472592BC6A17BULL, 
            0xE59526D57A31F8C0ULL, 0x79FC97C78EF353C4ULL, 0x2FE4AD1AB42C6CB9ULL, 0x9A75BD046BAAA3BBULL
        },
        {
            0xB76F4388C2B2F06BULL, 0x231195BF4705752BULL, 0xE8B3C7BC8DCA19A3ULL, 0x909A2429EAA250D1ULL, 
            0x6353887682BF432DULL, 0x51E9AD83DBE88D3EULL, 0x53D6164821655DA5ULL, 0x6CE9514BFB33368EULL, 
            0x679B8D14E8318E6AULL, 0x86088D5230A3CE87ULL, 0x7D48A82F4E808EBFULL, 0xE7A65CE5D2AC960FULL, 
            0x066351B7F55E0DD3ULL, 0x140A511F55C08018ULL, 0xDEAF0F093D3E3503ULL, 0xED1B3F45BAD1A319ULL, 
            0x193054C389E74004ULL, 0x4A6F778DD2B5D999ULL, 0x3426B0E19D6D775BULL, 0x39BBDC6D4166D05BULL, 
            0x5A9D9604DC7FFFE0ULL, 0x4AE49EF1943F4A1BULL, 0xB6AA17A13693E17AULL, 0x508F765CBF793A3DULL, 
            0xA3C2513B743EC4CEULL, 0xFE7680B7978DE674ULL, 0xC27EF3D89EEC30E5ULL, 0x6C88DE30800771D7ULL, 
            0x7C5A6C10FC96EDB2ULL, 0x090805D287019824ULL, 0x355E9FB04A073AC6ULL, 0xACD6CB8E08C0FB60ULL
        }
    },
    {
        {
            0x3CCC68D4BAC82176ULL, 0x867F66E992E6329AULL, 0x58AD03A3D64A493DULL, 0x16FE6AAA70868358ULL, 
            0xA19B8B6C37DAF115ULL, 0x0CEF75008D934F6DULL, 0xA43F0298D7970BA5ULL, 0x98D2F33486AB7E95ULL, 
            0x28E0DA39CBA964D8ULL, 0x7D876B55E2CDFFC3ULL, 0x0FE11F9B8714C0A9ULL, 0xE62E618CE2D89279ULL, 
            0xB69C3CC43964401DULL, 0xABE53DF14EC4D762ULL, 0xDAEBE3F1BEE06BCDULL, 0xE97CEAECC0D918D7ULL, 
            0xE113AD53D730C5FDULL, 0xA5AF43FA06F8CB61ULL, 0xA6F4D80EACFF5EC6ULL, 0x7A36C7D83B1993CEULL, 
            0x2019D77AC963938BULL, 0xF7A82EB2C606C483ULL, 0x9440608517C3E0F3ULL, 0x90400B9B006833CDULL, 
            0x7A5437E44F5C4186ULL, 0x72670B23E6D19A9FULL, 0x628F19DECF280833ULL, 0xFB3EA5481BC36FE6ULL, 
            0x90D89EB19E8E6850ULL, 0x9FEB3C7DAAC915D8ULL, 0x22A821D40404DAACULL, 0x599573A845D94019ULL
        },
        {
            0x945C1C12EA12C05AULL, 0x565CD61542E829E8ULL, 0xED9F9214093BCB77ULL, 0x3B1F2F25A6D089A6ULL, 
            0x001451FAD560C47AULL, 0xA26A38185BB25399ULL, 0xB92EFA3FC8F2802DULL, 0x16725CED1E3B9621ULL, 
            0x5876FA82455123F7ULL, 0x0BAFC11D45231FE5ULL, 0x1515FAD58D78625EULL, 0xE00C1AA61B65E705ULL, 
            0x2AC8D408A48A4DA2ULL, 0x881B6BEBC02CA047ULL, 0x4EBA3297D60718C8ULL, 0xC3615E26F6361235ULL, 
            0xCBEA83ADF474F1CEULL, 0x7A8B2A660DFC5AD6ULL, 0x9ADF5A6E97A79C61ULL, 0x4984D23D85865CCFULL, 
            0xA8EA605B3CD29E37ULL, 0x4DD942C239E20F6DULL, 0xB750D067CB301371ULL, 0xBA971955E7B006E3ULL, 
            0x8BE7BF035F537FA5ULL, 0x07E1C313A154C98BULL, 0x8672E0AF3A2E6BDBULL, 0x51797FBFA4FCC90DULL, 
            0xAFF5ED7F0C6423D0ULL, 0x07C5A66F490A4BEDULL, 0xEDCBD953A24951BAULL, 0xDB84A2DCB9523BBAULL
        },
        {
            0xE15BE32DB7C218F2ULL, 0xA3756C3548F7EF14ULL, 0xCFB490C385005BCCULL, 0xA2BA6497A7B7DD87ULL, 
            0xB029923913AC42CEULL, 0x7EC21405000289FDULL, 0xE82FE4EE4E37365CULL, 0xADFD4C6A428EC56CULL, 
            0x3F1BCD57B956022EULL, 0xE9F7E0C5111AC320ULL, 0x5362A76960A80148ULL, 0xF20DEF2F7277FDEDULL, 
            0xD2A43C8423D659F6ULL, 0x19B72BB776A6CB3EULL, 0x90A5CDDB8E3DEDE1ULL, 0x729FB8FE240D30B0ULL, 
            0xB19656B2A001EC77ULL, 0xC4D92EBDF8076D2EULL, 0xB5F1DF97BAFE2F22ULL, 0xA92CF3EA663564FFULL, 
            0x0C562F2F69D26DB6ULL, 0x71DF9CB190BD345AULL, 0x26A7ED565B43877EULL, 0x802B259F4FFE4DC5ULL, 
            0xF499067666C9CC49ULL, 0xF622084B0972F388ULL, 0x3A31806938C69879ULL, 0x8DC6C9E6F5E9CFE4ULL, 
            0x982A0EF20A84510FULL, 0x58D299D071FFC656ULL, 0xAB7A381D2FD35809ULL, 0xB2C6B0734A8CF1A5ULL
        },
        {
            0xC3DD0A90924754E9ULL, 0xADDF6389E782CD95ULL, 0x230DE65681E05D59ULL, 0xF9F2202C45AF10BCULL, 
            0x772CBB9FB1E1BAAEULL, 0x667EB0E388EDF425ULL, 0xA3BF62F5BCC13FC1ULL, 0x2374E90076BC7ECAULL, 
            0xB850C43CAAACE21DULL, 0x8D4EAE807C3799C4ULL, 0xBD10A23343207F7CULL, 0x6BB36DF155BDC1C3ULL, 
            0x3415453337ECCEC4ULL, 0x9BEAB70A61122154ULL, 0xB68325A0C3714508ULL, 0x06E75BC3480DDC23ULL, 
            0x184F9858C722F6A8ULL, 0xFD5F1B1E2E0230F8ULL, 0x5EF012E0D80D50C6ULL, 0x8331AB6B56FAC56BULL, 
            0xC5C75BE5CCC28718ULL, 0x059BD32FB86A300AULL, 0x1A9AAA3F2D45B389ULL, 0xE5F00EF16DBE5A58ULL, 
            0x40A9C63ECA7EF0B7ULL, 0x08A16A568F002B28ULL, 0x195BC0EB35616B46ULL, 0xD12D6DCCA8687981ULL, 
            0x0FC98C7AA4EEAFFCULL, 0x76ECF4F41808E780ULL, 0x8CB656AC899C713FULL, 0xB1DB953626E30751ULL
        },
        {
            0x46549AEC9C9D7691ULL, 0x2D90693B87EE14BEULL, 0x1C2874697F7B0E7DULL, 0x94342E0974018D7EULL, 
            0xF2D727FC3EE68ABCULL, 0xCC0F98537F898122ULL, 0x42F453B8F5D790D6ULL, 0xF5A3E4E6079B8457ULL, 
            0x0618BB69A77F7587ULL, 0x8BD7BFF359BC6308ULL, 0x54AD92803BC86F13ULL, 0x3EE6B364CC00A79CULL, 
            0xDA5B73335FF67B1DULL, 0x256EF13E03281ADAULL, 0x00D4F4F62043AFCBULL, 0x23A460E64C1CE6E9ULL, 
            0x338A74F4B3DCD8C7ULL, 0x29EF9BB86F205155ULL, 0x9CA520CDE8D40730ULL, 0x85C0A0589D051CFFULL, 
            0x6962780DE82A799CULL, 0x48CD7B33463F8366ULL, 0xAEDB4835782472BBULL, 0xB9A6F20586514B2DULL, 
            0xC324A3A2B8FB8BD4ULL, 0x589E5677B95AA85BULL, 0x6208ADD328A983ECULL, 0xFD1AC787BE07F945ULL, 
            0xD45DF4BC37DC4C5CULL, 0xF789FC351099AAD3ULL, 0xBB4FF0B968744124ULL, 0x3E0C8DC06E2B01BEULL
        },
        {
            0x99C7EC23EA8EBA33ULL, 0x071435F860786684ULL, 0x723100D966C078EEULL, 0xB2268B7CD0DE66D5ULL, 
            0xE822782589CBE753ULL, 0xC8F0785890BECE44ULL, 0xE0A9A5506FFCDDBFULL, 0xF6E8D2134123680AULL, 
            0x66FB3974585F9FE7ULL, 0xAF64D1D401801E5FULL, 0xFE695BEEA4FAEDD5ULL, 0x2DD4C290823C808CULL, 
            0xF77F2D37B492E75AULL, 0xFAC60AE866062C82ULL, 0xA00255D7A5190743ULL, 0xD2ABB2F1BF95795AULL, 
            0x5E726E36C799FE5CULL, 0x4D2DBDFEDA616EBDULL, 0x62A9235AAB33ACA3ULL, 0x0E57A8F7EDC4548EULL, 
            0x453F7A311D3D34A9ULL, 0x29F9062B96D8F7E1ULL, 0x6FD7C61201572E5BULL, 0x16A21F071E0EB674ULL, 
            0x2DF4373151DB30C7ULL, 0x6284928F265E59E9ULL, 0xF41A7A9264315316ULL, 0xA1CB1E68EC120F61ULL, 
            0x451D843783CC8154ULL, 0x4643F1F8A0ECB8BFULL, 0x82B5446BAE28DA9EULL, 0x794161C32CCBDF1BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kSeedConstants = {
    0x9FC9118A8D692D18ULL,
    0xB0C4A3E6D7BEED8DULL,
    0x73755D40199D0176ULL,
    0x9FC9118A8D692D18ULL,
    0xB0C4A3E6D7BEED8DULL,
    0x73755D40199D0176ULL,
    0xAFF4901ABC01F860ULL,
    0x8E1035EB4EB497E3ULL,
    0x35,
    0xB4,
    0xBF,
    0xE4,
    0x36,
    0x8F,
    0xA5,
    0xA7
};

const TwistDomainSaltSet TwistExpander_Arcturus::kTwistSalts = {
    {
        {
            0x1CE36BA2915BFF85ULL, 0x4287F8B8873A4E61ULL, 0x0D646F1829EEB243ULL, 0xED05773943B05400ULL, 
            0xB3CE6A5164014C82ULL, 0x2F69795D91AB29ABULL, 0x96DC217C0D40AE7FULL, 0x5A6BF9D3962C3001ULL, 
            0x7D321F2090613E76ULL, 0x7910009F5CEAC450ULL, 0x8E29ECFDD4783BB7ULL, 0x292A92B8ACC7C5F3ULL, 
            0xE60BBBB961648C75ULL, 0xF11368BE3C049F76ULL, 0xB42ED995E3134CB7ULL, 0x124B1E1D0BB6856DULL, 
            0x9B8C8185AD8208DEULL, 0xBA98497FD90F2AAFULL, 0xA626F66D39F9A86EULL, 0xDE8A747F254B1B48ULL, 
            0xF4E78268886BD720ULL, 0x7AE863B3D1F362CBULL, 0xF12C4180F28C4824ULL, 0xC69BC33E158AE9A4ULL, 
            0xF4AC87A0A513BB5CULL, 0xF430647FEA4145B2ULL, 0x69EA8E690C255DD1ULL, 0xB794D79125EB54E6ULL, 
            0x7F0C2427EB1080E2ULL, 0x29C541810F45D4E5ULL, 0x4E3B169C110B15DBULL, 0x8A55E716F53939EFULL
        },
        {
            0x4297FCEB2F2990DDULL, 0xC4499F636C9956E9ULL, 0x8630E54A0D42D1A0ULL, 0x213EC08D3A40A102ULL, 
            0x8FC9324E9BF3DE54ULL, 0x258F6D5343F17D46ULL, 0x67D82B0BF25D0E66ULL, 0x69B2B902448A5C42ULL, 
            0x0DF6776AE1466E6DULL, 0x2195CBC7C279264EULL, 0x5B28F11699BA954AULL, 0xE9642AB9F99C9995ULL, 
            0x6C949D72B1A05A6DULL, 0x6BB30CEB2CF04C57ULL, 0xE4ECB2572ED2F42EULL, 0xB772D7271DA8D027ULL, 
            0xB1AA2830ACEF6FBCULL, 0x53275D53946F5119ULL, 0x8C79D9F42FA15BF0ULL, 0x58E147422FBE49E4ULL, 
            0xAE4435527C798EDCULL, 0x5A21E0A4D8E10CC1ULL, 0x26779EFA73B4BEEDULL, 0x72047646E35C47C9ULL, 
            0x746FB6C268F76ADEULL, 0x154B5D5F998A6C8EULL, 0x99CBEA2AFA43D39AULL, 0x87B92BA7FC63DF5BULL, 
            0x4CA9BE3846467513ULL, 0x513A1A930DE0FDB0ULL, 0x8E170ACA473FD507ULL, 0xD8BA8E46EC2E42B2ULL
        },
        {
            0x52A962D02BFF0853ULL, 0x3C565B46DACC4FFBULL, 0x98E4C3EF1B45E4B7ULL, 0x225DD8736912A1AAULL, 
            0x906FAE6FA3C9FE09ULL, 0x5C9A4D5649B08458ULL, 0xDEECDE57C2372C20ULL, 0x5CA04BC51D461D4FULL, 
            0x376CFFC4CE9A8512ULL, 0xB1869C2A72C69504ULL, 0xDA70B0F69CD9774CULL, 0x668B7C4226F822FEULL, 
            0x099031A8D8B8547FULL, 0xB5F27CF28DCAFF60ULL, 0x608B58E881EA2D61ULL, 0x447D15824BC39551ULL, 
            0x71E8FC8B1416875EULL, 0x0337655CC94785C8ULL, 0x58387E62D43C6BDDULL, 0xF0B4870E8677372BULL, 
            0xCAA4872E718BAA09ULL, 0xCD0C739810A2EF71ULL, 0x90CE833E728CF03DULL, 0x76245F2FF8F11D94ULL, 
            0x0BB7A54EC74755F9ULL, 0xF656217BA10D6BE0ULL, 0x2E4124247459D5C1ULL, 0xB6AFA1AF564B938FULL, 
            0x694EC3EB3AF6AA6EULL, 0xF12186AC3AD0120DULL, 0x73C9BE6FC51C3FB6ULL, 0xA7B81C2790C12693ULL
        },
        {
            0x02266F767F1B3092ULL, 0x0215988563CFDCF2ULL, 0xEC45FFEF48C7EEDEULL, 0x7B08B4085065E748ULL, 
            0x77758957AAD70DB1ULL, 0x1992B7A5418FDCB0ULL, 0x488B8C5DD8B057F9ULL, 0x99F07CF022F3F5EAULL, 
            0x40DBB9A287D848FFULL, 0x4D77AA9FBCA0BA73ULL, 0x49317A7BE1992DF3ULL, 0xD32CA560ACC60DEEULL, 
            0xF1F7BD137498CD9DULL, 0xCC7A78802A6061C2ULL, 0x375E9FB5C5D7AE51ULL, 0xEB2C10EAC66974D1ULL, 
            0xD9A84193DE7489F6ULL, 0xBD724E400A1E263CULL, 0x6424185ED0CB6772ULL, 0xE2F18CFCEB932D4AULL, 
            0xDD8580FCC331D5F1ULL, 0x57697EC97F1004A1ULL, 0xF55795A627960ED2ULL, 0xFD4DCEAC948088A4ULL, 
            0x542879B074674DD3ULL, 0x0D2F8C69F8F33511ULL, 0x78AD5E7EB13BC21AULL, 0xD587E35FDB7DF763ULL, 
            0xD9B972BA03C25D8DULL, 0x509B65FBA2BAD519ULL, 0x3A9B71633028DD8FULL, 0x2D023E5966FCAC76ULL
        },
        {
            0xCDF7E6195E3594A7ULL, 0x6A8AA40D3EACD710ULL, 0x7524EC1E83C9053CULL, 0x91A4DD30C5806ED2ULL, 
            0x62B80599D515C10CULL, 0x95696D4FE35FA7EFULL, 0xD38D0467DD308DFDULL, 0x137361614934D08EULL, 
            0x90F4E0E225AFBD1DULL, 0xEAF97CFD514BA16AULL, 0x1428AE283DA974BBULL, 0x3D67E843BD7AA8E5ULL, 
            0x498A3715BF6904A8ULL, 0xC7A5AA44620B77CDULL, 0xD4215F12121CE783ULL, 0xD1DD2D387FA46AECULL, 
            0x126B8AEFFD35CE24ULL, 0x303BEED6E5EDDBDFULL, 0xD4319715467A1E27ULL, 0xF98CC99914BB7DC6ULL, 
            0x3899848BA3C18A95ULL, 0x9052396E6A455D1CULL, 0xD6CF372AD086C42AULL, 0xF27087672345B178ULL, 
            0x82B227A81070BEF1ULL, 0x28F92561D745390AULL, 0x71FAF41C1B765747ULL, 0xD7B1AB18F6B5EC57ULL, 
            0x7A6DA43EE7F1AF40ULL, 0x4DCB5E5F17974B86ULL, 0x54F27C39042539DAULL, 0xEB92618FF79C5A6FULL
        },
        {
            0x31E8C83481422900ULL, 0xBF3ACCE217BFCFFDULL, 0x64A63E6AA69A9089ULL, 0x10C584A9615C706DULL, 
            0x78134CE9F415887FULL, 0x32B07B1800B23611ULL, 0xA51C4BCCDEE7EF6DULL, 0xA47380D00DFE8F34ULL, 
            0x5685225755557F78ULL, 0x932091EF2571D0C8ULL, 0x5FA6031F0875BDE7ULL, 0xD576FB3FD3DCDF99ULL, 
            0xBE65607C59712E05ULL, 0xA4A647C49DCAAFFDULL, 0x2EA2DB654C24E5DBULL, 0x646E76C8A9193330ULL, 
            0x84A0B8B796059442ULL, 0xB9862EE0A9261FD1ULL, 0x3E714650D4AFA909ULL, 0x56F13221B653625CULL, 
            0x12E10C715EE0438AULL, 0x9968B109FCB48820ULL, 0x0A8597FB679DDCDFULL, 0xE36F5475321E5C74ULL, 
            0x363E4902F65D8150ULL, 0x9D7131276F1FAFC5ULL, 0xB5C38D1227647B58ULL, 0xA7D5149B2D3AFBBCULL, 
            0xFE1B095FC8C4C1DAULL, 0xADB3D57D9CB6EF0DULL, 0xC4CA95FC2B78259AULL, 0xB542D6A6075764AFULL
        }
    },
    {
        {
            0x3AEB2F8E715A77E1ULL, 0x7967A49C2DE70C43ULL, 0x5229D04C7E29C262ULL, 0xBFF654DF7E864F1EULL, 
            0xBE435ED13B557859ULL, 0x96042BD7AD11ABC3ULL, 0xDDFD0B4CA60AFC38ULL, 0xC7E360300EA2EE72ULL, 
            0x80F268F8961F46D6ULL, 0x3870A93855D9383CULL, 0x7B562B8849A5DAD8ULL, 0x3895D7E2FC9CF084ULL, 
            0xB9B696D35408E886ULL, 0x65B7C6BFAEF250E8ULL, 0xD0246C9612034E12ULL, 0xD05C2FC4295BD428ULL, 
            0x9C60229035DB463EULL, 0x5A4AB970EE0CE3ABULL, 0x75A2823C61DCD945ULL, 0x6930D980E4C946F2ULL, 
            0xAC7956B3A101939BULL, 0xF0D4B23AEB33D3E4ULL, 0x8A986BDF0D11C3CDULL, 0x2DDFEA2B03E980E7ULL, 
            0xE4A5B8009221AB0CULL, 0x74519B88C49D191BULL, 0xEF4A3D0A4492D9E0ULL, 0x4D99A9C534992408ULL, 
            0x71A3448EC94BF917ULL, 0x626B9A8409257A4DULL, 0x9A582328F8FC885DULL, 0x915FD38DA795AFB7ULL
        },
        {
            0xB1FFEF068BF02EA0ULL, 0xEB7BCE22F5F30EFFULL, 0x9909BE7CBEFCB8FFULL, 0xAE3E7ED5F37040BAULL, 
            0xFDD1E3CA5336436CULL, 0x3AD89A1D81ECB838ULL, 0xB98CF7D6AB88369DULL, 0x382C93694535AD41ULL, 
            0xF66B4C963444E2F0ULL, 0x4756DCC7246AA671ULL, 0xAF497D9DA4AF6EF9ULL, 0x83C484984F04E969ULL, 
            0xC54229B668B4501BULL, 0x038453D3A8F340D3ULL, 0xF8897DA9E3F5D48CULL, 0xC0606B87867F3EE4ULL, 
            0x0661C25F3FA73238ULL, 0xB11EE610FFB7B70EULL, 0xBDB00E2588164096ULL, 0xB94D256B01D5DA07ULL, 
            0x3018A2201A5CFD46ULL, 0x38B914AD4A8560A7ULL, 0xB5E07ED45FF0979FULL, 0xA8A2D22D03D03764ULL, 
            0x412E20DC3D46F4DAULL, 0xF088273888E1A3F9ULL, 0xEE35474D63FB7F89ULL, 0x518E33FB20D14EB7ULL, 
            0xBA6265F609B5396EULL, 0x91666AF2D20E17A9ULL, 0xB4717A20D681AEB6ULL, 0xD8DA847D4A61CB53ULL
        },
        {
            0xC0EDCB12E06C0012ULL, 0x7D6FCA3B0A18C386ULL, 0x5F8276AD272F13EDULL, 0x0D38C08B71B38E1CULL, 
            0x260403C4E9FAE8D6ULL, 0xF8A3A7FF446C0D6FULL, 0xDE587DBD76165EE3ULL, 0xA07C1C11658AC7EBULL, 
            0xC5147B913AD9F002ULL, 0xBDE0F400EA331AFAULL, 0x97E41A9E4732003AULL, 0x51603142B36FF601ULL, 
            0x942FB713039C6BD3ULL, 0xA60A4962890EA4C9ULL, 0xA01F9B8A17F5EC7AULL, 0x5599713AC021916BULL, 
            0xB5D520E81E178A37ULL, 0x024287D35C497E5CULL, 0x830DC8F3C83264B5ULL, 0x22697096A6E1ADA8ULL, 
            0x4028471776BCE110ULL, 0x60096F77A853C891ULL, 0xDD2836DDF8E2951EULL, 0xB771B2FAC6EB34D4ULL, 
            0xA747AD08822E7B22ULL, 0x361276D27F54F271ULL, 0x0C3DAFE6992449C0ULL, 0x8E99395D68935493ULL, 
            0xD39DEC22FAF0265EULL, 0x00AD1BAE221D2500ULL, 0x13BB0C52572483DDULL, 0x2945A917A87D465FULL
        },
        {
            0x36DF66E789F869BAULL, 0x5C9DF76B50F0594FULL, 0x541087770A282D44ULL, 0xF9915FBABB67C181ULL, 
            0x50CB39974B081A98ULL, 0xD8FAB6459F8CEE59ULL, 0xE172D7E0189A8ADEULL, 0xABE2C6E8922FCE1BULL, 
            0x3E89BD295D76917CULL, 0xB840D73EC148A929ULL, 0x634712FA463E1991ULL, 0x1B19CB98A88DEC97ULL, 
            0xED042FC1A32D8A30ULL, 0x2355800E9DCC0086ULL, 0x556E895A7BA5CFDBULL, 0xD0148A1A0EFA04F9ULL, 
            0xCC3521FCE840A52DULL, 0xA708DE1EF6E477B5ULL, 0xECD5D5C22A068BA4ULL, 0x3A5E66C36B669FD3ULL, 
            0xAAE28766E9473C91ULL, 0xACC408AD8F71150EULL, 0x750DF25576A54CB9ULL, 0x247346A46D0F1601ULL, 
            0xF9F96DEBD9806AEDULL, 0xC06D6DAB3F92A6E6ULL, 0x80403D48409ECC02ULL, 0x49A1DE084D7B1343ULL, 
            0x5AB00CF3AC2BF0C4ULL, 0x8FC443F912BC894EULL, 0x06D6D95AC2F34796ULL, 0x5D715276063C018CULL
        },
        {
            0x0AC5F4EC1BCCB875ULL, 0x7E3DBB5519A5342AULL, 0xB02977F09E69D897ULL, 0x3CFE832B094A3AB6ULL, 
            0x91CFACB55EA8A4BFULL, 0x7A441E628DD7034EULL, 0xA708BC0DA5580C90ULL, 0xC7E7724595F75DC1ULL, 
            0xF9412BCB57CD7652ULL, 0x5C0E281B2C318484ULL, 0xF445024F41F14019ULL, 0x0403EEBE5F9A54E2ULL, 
            0x16E19EEF15DC2005ULL, 0x75B7406A016BD3ABULL, 0xB749F4F0D7BF24F1ULL, 0x8CE0CA5E007D8BD6ULL, 
            0x41690F5A2244076EULL, 0xF4D898298FE56C5EULL, 0x2157796995863E5FULL, 0x28CAB27C1A128F92ULL, 
            0xF40A04257E167027ULL, 0xF1C94BBBFA9D09DFULL, 0x5BD47120AFEE8B5EULL, 0x3367B1EC706500D8ULL, 
            0x41AC04AE3A71A6FAULL, 0xCA4E1DBDC6DAA206ULL, 0x3E94D076574A9F08ULL, 0xCE8C3AA544D58300ULL, 
            0x9AB0EF0EBA9F411AULL, 0xC84FA7A1899E28C5ULL, 0xD47F701B647A9BECULL, 0x4C2B88A8D13F9B6EULL
        },
        {
            0x6FB59307173F5672ULL, 0x21E42834F000B9D4ULL, 0x854E48400A1E2C03ULL, 0x4C89090C42E3CDCEULL, 
            0x045DE834FFD39C7BULL, 0x01E236DE6BE1D443ULL, 0xA268840E526FD7B6ULL, 0x258F46B8A5F18CFDULL, 
            0x74D1AD8496BF6EC5ULL, 0x335FF2349183E319ULL, 0x49C2DF02F20791FBULL, 0x53662AA9931FBEF3ULL, 
            0x3E751B92CCD17482ULL, 0x40A83D1FB22072AFULL, 0x77995C99128F0C14ULL, 0x38E0890AB1BD5A90ULL, 
            0x1EDD10B4FB86B2A9ULL, 0x4AAFD0AB22697720ULL, 0x88F6F3C50F7EDF94ULL, 0xCE3291B9D927A7EAULL, 
            0xD5D18CA1B2F35CF1ULL, 0xD284B02EBA3832F1ULL, 0xFCC2088A90AFCC24ULL, 0xD9C17A5EB39C7DC0ULL, 
            0x69949083ACCAEB30ULL, 0x2437B3BDC6A3F172ULL, 0x720E185BEA6DE09EULL, 0x1A4407A1D28E8F78ULL, 
            0xC46D270F49552D5EULL, 0xBE2F322162B8EFDCULL, 0x5B7165966626262EULL, 0x077C536BC0897FA7ULL
        }
    },
    {
        {
            0xB97FA34B436ADAF3ULL, 0xA416252F80F12DE7ULL, 0xA114A833697B0EEEULL, 0x3E3A0E4BA3E7E49EULL, 
            0x6A641D841B298B13ULL, 0xCD5AC262BE35F238ULL, 0x8DA61C7F42F615FCULL, 0x389295BEA0868D07ULL, 
            0x02DB55DEEF5E2E8FULL, 0x667905CE3DCDCEE4ULL, 0x987ACCC64A53F9B1ULL, 0xD012B6E775556A3FULL, 
            0xF75590D763A56023ULL, 0x20BCB319E5858FFEULL, 0xCB438D51154A8BCBULL, 0x466B98A18EB7EAA7ULL, 
            0x8A1287E404A7EB3CULL, 0x0A9ADAA127671E60ULL, 0xF957D460D61CF022ULL, 0x007E32F359EA205EULL, 
            0x60E2B50F96DD9B5EULL, 0xCE920F5DF8CBA106ULL, 0xC75435F0C52F6E4DULL, 0xC31E32BE3FFF246BULL, 
            0x1009161E940F39A0ULL, 0x3458C039DABB93C1ULL, 0x0ACEC9C167056BA5ULL, 0xE53EE9249D825726ULL, 
            0x9EA01442C5E2EF85ULL, 0xC54B538385082B63ULL, 0x24349A6079B391A0ULL, 0x9F57196CE9B631C7ULL
        },
        {
            0xA23E76D2066F64F2ULL, 0x19D1A27542B29FD4ULL, 0x0D6A684E2024F9E8ULL, 0xA1BE1B9AFB258D9AULL, 
            0xD5975253A51E0E65ULL, 0x1AFA2EC53743421FULL, 0x6CC2B37698230224ULL, 0x6681FAF1900288D4ULL, 
            0x3386625D6651083DULL, 0xBD140DC9C08631FEULL, 0x2B330F0F8B1028C5ULL, 0x4E7C18B328A7B1CAULL, 
            0x37998D205DBD55A4ULL, 0x8CB775A8768077FEULL, 0x61DAAD65FBD3CB6BULL, 0x0C65FF2C0A0615C5ULL, 
            0x8E8A67644D86DD62ULL, 0x1EAC43DAF3C41E34ULL, 0xE5E487C2C8092DA5ULL, 0x949A194160524517ULL, 
            0xABDE07CF501474DDULL, 0xDB6D256AB053E8FDULL, 0xE013C335EEEE8A83ULL, 0x13012B5632E1378DULL, 
            0x91A801AF24F894EAULL, 0x82EC1BDE16AFF183ULL, 0xCED675FDD6EF0BFFULL, 0xF67E053BB2EAB9CCULL, 
            0x0307C59AEF1C75B4ULL, 0x841045A97F7A53D5ULL, 0x98443E93CDC7914BULL, 0x68AAD9EE3A913FF8ULL
        },
        {
            0x3D883EBD21C58068ULL, 0x10AD72852794C72FULL, 0x8C3776029C25F3C1ULL, 0xE49BB758ED00C37DULL, 
            0x907EF4E5EA89B2ECULL, 0x4FA6C59FDC4EBE55ULL, 0x447E4F91341A3470ULL, 0x7760F79165CA7032ULL, 
            0x9357FF8386633DC8ULL, 0x501536792100C080ULL, 0x5A32F4BF45F3E8B0ULL, 0x8D15027DBA3F0D22ULL, 
            0x58ED46353CD279A9ULL, 0x3709693A775ACD8DULL, 0xA24D91E756C08C10ULL, 0xD7BC8F22F547F0D0ULL, 
            0x9BD700ED6EAE941DULL, 0x757362DB0B3A7C16ULL, 0xEE11FF010D6B6C82ULL, 0x7BFC15360CCBA51AULL, 
            0x2EEE36F4E1D79406ULL, 0xF4AABD0904A5D9BFULL, 0x3B154CE978626E81ULL, 0xDF1B868B6EE4D5F6ULL, 
            0xEA9D3E7D449B091CULL, 0x825809EBFE4C6FB9ULL, 0xF05148F99E687EC0ULL, 0x5282F096A4739C4FULL, 
            0x7585FFD7CDCB21E7ULL, 0xBD8FA26F891671BCULL, 0xAD55A1E088BE028CULL, 0x7A4A804587721E02ULL
        },
        {
            0x89C1BF46FA078FE9ULL, 0xC36324B6B509B577ULL, 0xD0CFDD19B87ADE54ULL, 0x348CCD6D17B60E67ULL, 
            0x24C5C75924BCE1F6ULL, 0x3C8D0955199720B2ULL, 0xFD43567A2EA66F67ULL, 0xC9A645700FE9C2B3ULL, 
            0x34D5ED7EB233FD19ULL, 0x252198D8D0AE053BULL, 0xD69F63DC901AACCCULL, 0x8A4147489D05B418ULL, 
            0x157EBE4BAF6214EBULL, 0xB31FEAA18CCE2232ULL, 0xE77E5BB162C0BFD7ULL, 0xA76D603D24DC1AE3ULL, 
            0x5E20CC06D0E2E69BULL, 0x5F2CCCC74FAC8828ULL, 0x4AA5926BF328FC32ULL, 0x7BC271406A26E669ULL, 
            0xC4D3C061C7F6D886ULL, 0x84BCEDED66464365ULL, 0x591D52E6A23752ABULL, 0xEE745878E08C94BCULL, 
            0x1BC61D8708093467ULL, 0x9CAA55EB91F906FBULL, 0xD063F4F29E0C291DULL, 0x13191CC62C199F27ULL, 
            0x1344A42F65EBC05BULL, 0x24DECC677C9FF4A9ULL, 0x0D8AE0C80A4781E7ULL, 0xF1CD685D25517B8AULL
        },
        {
            0xEAB7D7B30A8F69CEULL, 0x629C2A58F3A02F74ULL, 0x0C45CEA3CCCF2D64ULL, 0x0FACF3F67F6FBBABULL, 
            0xFC5793C49A2B0184ULL, 0x71F88ED82382DBE9ULL, 0x06D381B5CB497566ULL, 0x3995F299C78D1CB5ULL, 
            0x5FA1553BEE732D00ULL, 0xC978477FC4113804ULL, 0xA995A21ADB85122CULL, 0x4E3D5F4A6EFFE157ULL, 
            0xFD13960B4ECF5903ULL, 0x04B7E26BD9BBDACCULL, 0xD212B1DBD027D351ULL, 0xB8D3FBBFD4228E08ULL, 
            0xC6E6344A8A64BB02ULL, 0x93E2AC6152C87DDDULL, 0x92E0DD1C4BFA8F63ULL, 0x5BBE788C63A0FEC4ULL, 
            0x6914DC23C7D8717EULL, 0xEAFC016411745CD8ULL, 0xD30A29A3D3FBB347ULL, 0xD3C6D95195D3463EULL, 
            0xE544FEF184FD9612ULL, 0x1D3CD624CF1E2BBBULL, 0x97269E0BCEDF3F2FULL, 0x12344B2D93C6F255ULL, 
            0x36687CA93AA0F11AULL, 0xDFC8D5E33121AB1CULL, 0x279815F95A4ECC4AULL, 0x86F2EA2A49680397ULL
        },
        {
            0xAFFC6C293657511FULL, 0x4D4A33A2E5167449ULL, 0xE694BD7939160556ULL, 0x77D09CEE32F5841BULL, 
            0x87AF7FBD9C004F2DULL, 0x2F3D19C3AE765052ULL, 0x0EC27BFFC485A013ULL, 0x6F40F608D0AB51F9ULL, 
            0x5F0C1576EACC5BBFULL, 0xD1070302F82CB06AULL, 0x7136AE5B6870B47FULL, 0x64A283A7776A7603ULL, 
            0xB45ED1B55B840D6CULL, 0x579DC92125E796B1ULL, 0xAF6AFBF3873C81EEULL, 0x96A43502167A1010ULL, 
            0x2A35B55354E3EFB4ULL, 0xC3F2610D722C39CAULL, 0xC033096EE805829CULL, 0xA000318E643636A0ULL, 
            0xC8FC8904E4A8E1F7ULL, 0x6FC716C0788508F1ULL, 0x63EE6D77FE6D3B77ULL, 0xF542A11FAC068D55ULL, 
            0x0C622E6C4A326AA1ULL, 0xB61C55ABEE8C03FDULL, 0xA4D700B33FD0E247ULL, 0x89B74B64471050F1ULL, 
            0xD297FABFBA783483ULL, 0xCD8F00657C3512E9ULL, 0x654055C4F1C80C47ULL, 0x951649165693956EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kTwistConstants = {
    0xC6B92B846258954BULL,
    0x07132329602941ADULL,
    0xF41FF539401BA6E2ULL,
    0xC6B92B846258954BULL,
    0x07132329602941ADULL,
    0xF41FF539401BA6E2ULL,
    0xFFADE3EDD52D1E8CULL,
    0xCD450606A189F184ULL,
    0x6B,
    0x4F,
    0x0C,
    0xA7,
    0x47,
    0xB6,
    0x0D,
    0x8F
};

