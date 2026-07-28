#include "TwistExpander_Aldebaran.hpp"
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

TwistExpander_Aldebaran::TwistExpander_Aldebaran()
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

void TwistExpander_Aldebaran::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA1EA33A4DF09F1FCULL;
    std::uint64_t aIngress = 0xE308EA13B6E725B3ULL;
    std::uint64_t aCarry = 0xC4FB29180B71747DULL;

    std::uint64_t aWandererA = 0xE85ADC032504B3C5ULL;
    std::uint64_t aWandererB = 0xF948BBB5F6FD2942ULL;
    std::uint64_t aWandererC = 0xB644F15655653F3DULL;
    std::uint64_t aWandererD = 0x9D1336C693B12D95ULL;
    std::uint64_t aWandererE = 0xD85D9B29A061E9A7ULL;
    std::uint64_t aWandererF = 0xFAB5052167DCBF0BULL;
    std::uint64_t aWandererG = 0xF08513B2DCF3AFB7ULL;
    std::uint64_t aWandererH = 0x8CF0B116EEE0D70EULL;
    std::uint64_t aWandererI = 0xF062903964CE416DULL;
    std::uint64_t aWandererJ = 0xA8DA1ABB1B3EF381ULL;
    std::uint64_t aWandererK = 0xBE911D0309AB26E9ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xB54652D2361DB541ULL;
    aIngress = 0xDCD4FCA3D08CEC3AULL;
    aCarry = 0xAE8C699877C63E18ULL;
    aWandererA = 0xFF2D73EACA0D16BEULL;
    aWandererB = 0xA1741418170F3714ULL;
    aWandererC = 0x80430EBF2D53E256ULL;
    aWandererD = 0xE32A6F560F001A2DULL;
    aWandererE = 0xB58617FE03A55EF7ULL;
    aWandererF = 0xFF2CF6D1D9067AD8ULL;
    aWandererG = 0x8A6E8BBA59076744ULL;
    aWandererH = 0xA07174B3985E2056ULL;
    aWandererI = 0x944A5876AC90BF8EULL;
    aWandererJ = 0xA614D1BDFF456AE9ULL;
    aWandererK = 0x80B1E042708D5ABEULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xB5D42680DEC30EACULL;
    aIngress = 0x936C7CD38BAB389AULL;
    aCarry = 0xE7C56143133323D5ULL;
    aWandererA = 0xA7B8D032C4BA9367ULL;
    aWandererB = 0xFE8620A9D25F5F79ULL;
    aWandererC = 0xAA0E4F66DA8ACE48ULL;
    aWandererD = 0xCC13176104326237ULL;
    aWandererE = 0xB0853607E9DC43C8ULL;
    aWandererF = 0xF500E545BD5A1A53ULL;
    aWandererG = 0xAC4A9ED7FCC0307FULL;
    aWandererH = 0x9E1D822A97793338ULL;
    aWandererI = 0x86C2A72550F2A3DDULL;
    aWandererJ = 0xAE7EDA49C66E05BAULL;
    aWandererK = 0xE7E33D807A132ABBULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xB794AA4ED7C422F7ULL;
    aIngress = 0xB83572ADA3140B11ULL;
    aCarry = 0x96672C68DB2FB0C9ULL;
    aWandererA = 0x9E2C68EDD25A342EULL;
    aWandererB = 0xFC3F0CD55A291D20ULL;
    aWandererC = 0xEF5D930410F4B94BULL;
    aWandererD = 0x81135356E8661CD4ULL;
    aWandererE = 0xCF3332D903A8E392ULL;
    aWandererF = 0xA2CB1E24691A1CBDULL;
    aWandererG = 0xD94C03E789216D39ULL;
    aWandererH = 0xEF5459CB8ABFD4E6ULL;
    aWandererI = 0xC533A883DB094B92ULL;
    aWandererJ = 0x8EA0A49ABB290349ULL;
    aWandererK = 0xA9C5F77F8D08A4DFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x81DFFC91FBF245C3ULL;
    aIngress = 0x9051E0F790152ED3ULL;
    aCarry = 0xE17DE0D4A2B77D58ULL;
    aWandererA = 0x9236EF0B558CBB40ULL;
    aWandererB = 0xBF523183E97E3533ULL;
    aWandererC = 0x81D8F3C2A4B4DFCBULL;
    aWandererD = 0xA5A8CB8E89F14A1BULL;
    aWandererE = 0xD668C19555B2DC5FULL;
    aWandererF = 0xE869B6D2D5A9D936ULL;
    aWandererG = 0xEC99173306BCE2ADULL;
    aWandererH = 0x9EE545DA8A141D08ULL;
    aWandererI = 0x8F526EA86ABAA744ULL;
    aWandererJ = 0xCB00A16B242B47B4ULL;
    aWandererK = 0xF6B3A25BD3DFBCC9ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xF398C6088BC6ED15ULL;
    aIngress = 0xA83352680BA85340ULL;
    aCarry = 0x8E4958B3E8CC6385ULL;
    aWandererA = 0xFB5DA8C470B3EFE2ULL;
    aWandererB = 0xC64BC28BCCDF1AB6ULL;
    aWandererC = 0x9FB5D0241A70A292ULL;
    aWandererD = 0xC7D879F4B6D62122ULL;
    aWandererE = 0xC70839AA7EE3A401ULL;
    aWandererF = 0xE782B317ED48507EULL;
    aWandererG = 0xB8D3CDC4EFEFB514ULL;
    aWandererH = 0xE3600100368117E9ULL;
    aWandererI = 0xE70CBB37DA42693AULL;
    aWandererJ = 0x96DDF3CBB231AAA5ULL;
    aWandererK = 0x990FCBE973438557ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xDE9CA0686AEE8C7DULL;
    aIngress = 0xEFE30CA7F9F1A8D2ULL;
    aCarry = 0xC1AF89208473F31EULL;
    aWandererA = 0xCA72AAE4E456B2CFULL;
    aWandererB = 0x856EBBABF2383894ULL;
    aWandererC = 0x913DA06C1394519EULL;
    aWandererD = 0xF90FCE9164B81A64ULL;
    aWandererE = 0xBC7D157C30EEFD57ULL;
    aWandererF = 0xC175BA990128D354ULL;
    aWandererG = 0xF0A4662A097248E9ULL;
    aWandererH = 0xF6B1CF3E6A67C444ULL;
    aWandererI = 0xF75B971E90DC2733ULL;
    aWandererJ = 0x90BCAEB5456058BBULL;
    aWandererK = 0xC23D5CB9C06D51F6ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xEC41AADB906F1B95ULL;
    aIngress = 0xFDFD433CEF48005AULL;
    aCarry = 0xDB141E6F37883510ULL;
    aWandererA = 0xB7E070ECDC5BBC97ULL;
    aWandererB = 0xACAB002C9D98AF63ULL;
    aWandererC = 0xFD92384740E50B74ULL;
    aWandererD = 0xF09043B23367F7EAULL;
    aWandererE = 0xFECFBED3F84D89A2ULL;
    aWandererF = 0x90F2969152D9E124ULL;
    aWandererG = 0x8D55C0CC5AE1F35EULL;
    aWandererH = 0xE2C97CFB2FC99BC0ULL;
    aWandererI = 0xB2E3778171B1CAC5ULL;
    aWandererJ = 0xAD186B0D3F0738DCULL;
    aWandererK = 0x965CC41EF03838EEULL;
    //
    TwistExpander_Aldebaran_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Aldebaran::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB3EF981A0B42766FULL; std::uint64_t aIngress = 0x9F29E45996F7DC81ULL; std::uint64_t aCarry = 0x894EF282184F9B4FULL;

    std::uint64_t aWandererA = 0x88EC55360B143D73ULL; std::uint64_t aWandererB = 0xBD459AAB8A944FC7ULL; std::uint64_t aWandererC = 0xDFE9037E7A6051A4ULL; std::uint64_t aWandererD = 0x87CA1D92E8AD3733ULL;
    std::uint64_t aWandererE = 0xD00A296F7A438625ULL; std::uint64_t aWandererF = 0xBF154BBCCDFE1B42ULL; std::uint64_t aWandererG = 0x992DCBB0D8570D05ULL; std::uint64_t aWandererH = 0x8D27FFF78E1FA875ULL;
    std::uint64_t aWandererI = 0xA3F62529311ED247ULL; std::uint64_t aWandererJ = 0xB1819930A43B0D8EULL; std::uint64_t aWandererK = 0x9144C8B14071E087ULL;

    // [twist]
        aPrevious = 0xDE47B4D88F71E919ULL;
        aCarry = 0x9030405ED8388F78ULL;
        aWandererA = 0x9BF2A7D8D10ABF2DULL;
        aWandererB = 0x9E8DA726A94939E7ULL;
        aWandererC = 0xC08A05C1F93C7B7BULL;
        aWandererD = 0xBAF03A0FCA2BDB29ULL;
        aWandererE = 0xB636333A3454456CULL;
        aWandererF = 0xF26EB79533EB4561ULL;
        aWandererG = 0xAE2C8E44B6BF56C4ULL;
        aWandererH = 0x8CEC6F38306AF1B6ULL;
        aWandererI = 0x8CD2D0F239B1F291ULL;
        aWandererJ = 0x9F1FA9B86923672DULL;
        aWandererK = 0x95A4E5A45E4D09A7ULL;
    TwistExpander_Aldebaran_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Aldebaran_Arx::TWIST_H(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Aldebaran::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Aldebaran::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Aldebaran::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 3 of 33
    // Exploration cases: 0
    // Structural maximin 614 / 674; family total 1233
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 3 of 33
    // Exploration cases: 0
    // Structural maximin 614 / 674; family total 1237
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 565U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeyRotateASalts = {
    {
        {
            0x75BA8C65A2C091A2ULL, 0xB0146B35BB458F09ULL, 0xFB5191DBF023AB1CULL, 0x6D698B34F972052CULL, 
            0xC65DBA134585B99AULL, 0x1B357B92E1D2666AULL, 0xEDA5C9C9621CE4A8ULL, 0xB830212F0E24ADCDULL, 
            0x949B62E9650F374DULL, 0x61C361B399FEC94EULL, 0xFEF3CB26EDA47C31ULL, 0xCE9AF3C647C87436ULL, 
            0x781EC1E24ACE9097ULL, 0x4CB6DB520F5B17A5ULL, 0x01B1AB8DD9649500ULL, 0x67813EA6C4C9192FULL, 
            0x074FB7A1E7AABA37ULL, 0xFBC218FA6CC493D7ULL, 0x18025AC1DA1A144FULL, 0xC5D0FCB8A303B94BULL, 
            0x47F215CEB1A7B623ULL, 0x948BA587897D8EA2ULL, 0x23F1A9C4310F9BBCULL, 0x778EF6FA8310AE5DULL, 
            0x3DB61CB9B29224CDULL, 0x1D1484F024E9C4BBULL, 0x7ADBCDBA60A76062ULL, 0xA034612A4B5EB13FULL, 
            0xAE7456B313D933DFULL, 0xE0EC7B9AE798F945ULL, 0xE429151408BE2FBAULL, 0x3CEC94ECE1913F39ULL
        },
        {
            0x1E0FE013723B691BULL, 0x98F8B7DB59ED8969ULL, 0x7E05D93230207708ULL, 0x2D053FF7AEDCC625ULL, 
            0x714FA6186FF18D05ULL, 0x93D366CBB6B830CCULL, 0xDF0A9495F32D8A7AULL, 0x1F678E9E3FD0C01CULL, 
            0x0D515BBB104D769CULL, 0x7A37CC8F7F2FC2FAULL, 0x30FF958CFB8DD15AULL, 0xC8E1299E02BE0DF9ULL, 
            0x0C449A921BAF9390ULL, 0x56A0676141B4B7B9ULL, 0xC51BA0A13B39EFCAULL, 0x5AF732F219C7C265ULL, 
            0x82C0EB4B29139145ULL, 0x60704B4598FCE432ULL, 0x07084BB620CD8618ULL, 0x972E1A9BF3EAA4EBULL, 
            0x410FA4B14B0091F9ULL, 0x00FC28D917D63571ULL, 0x94DDD6014DE5927CULL, 0x81BCDDAB02B96AC2ULL, 
            0xFA4DAE37FA045C3FULL, 0x413D052CDD1F451AULL, 0x8E4BAFAEF7507612ULL, 0xBDD3E4F1B99E0372ULL, 
            0xA91AE1E6B87ECD3AULL, 0x6B695F209D230257ULL, 0x7B253E79E764E2B6ULL, 0x722E83A93B5A18B5ULL
        },
        {
            0x1CF2EF7C2095DE5BULL, 0x16BBD7AEE85730C3ULL, 0xD57DC44169946D7AULL, 0x6ACA60954E3F484BULL, 
            0x650356ECD85AC816ULL, 0xFBE92756B7E5FB77ULL, 0x129FF58F4EFA25DDULL, 0x4F3924F5A6B5383BULL, 
            0x6C17DDB63B65F248ULL, 0x80FAF2344730743CULL, 0x038A5C799E65FEEAULL, 0x52B8B0B27BFABA03ULL, 
            0x529572481432647FULL, 0xDC440B621CA27232ULL, 0x0A6EF8548B4745A3ULL, 0x9415BBB0B49E928EULL, 
            0x4083002830AE0059ULL, 0xBEEEDA2F0A41A7FCULL, 0x7EECE5489BECCCE4ULL, 0x138BEF65F41492E1ULL, 
            0xF483C1E4E2A809C9ULL, 0x783ABF323975F2F1ULL, 0xDB8EB7BF5D63ADCAULL, 0xB00D822ED9DEBE34ULL, 
            0x4CAD462CD7EAC034ULL, 0x83C4508CEA747827ULL, 0xE9B59FB53105F171ULL, 0xCAF546282C8F2633ULL, 
            0x7F1E08AFF5944B58ULL, 0xD301286C64C3850CULL, 0x453813F623573CB9ULL, 0x6240A5F2914ACB31ULL
        },
        {
            0xEC86936E3A35D8F4ULL, 0x0FD496F4E2A399EDULL, 0xEDE628435D1EF91BULL, 0xA0CBE0B2B890C9A0ULL, 
            0xC1C91CC1D28E9BBDULL, 0xAA31F2F4EABEFA3AULL, 0x41FD88B283F3809FULL, 0xF42BBA0844294863ULL, 
            0x2A3970DC996F3CA6ULL, 0x0EB9EF9F475042B0ULL, 0xAD41DE29ED458327ULL, 0xC3130EADC91F3E81ULL, 
            0xFBF144DFD517F546ULL, 0xC0EA5C537F409C28ULL, 0x5A3E1500A2A4ABDAULL, 0xBDD5702E22C38B5DULL, 
            0xF5225C6C49A4EAF3ULL, 0x2351EA2A2E715ADDULL, 0x3B01D6C18798AEA8ULL, 0xA860BB5A1D0AEE46ULL, 
            0x03D70B46D44D06B2ULL, 0x32D395DCD25CE7F4ULL, 0x0F42E3AB92897E2CULL, 0x8F83494A548EEC8AULL, 
            0x098343313613C546ULL, 0x021BAF543235F525ULL, 0x14B5191D947805B6ULL, 0x157146DA508E9222ULL, 
            0xD78D836EA9B75BAEULL, 0x036B0A7AAF1B01D4ULL, 0x7E5C060718E882A2ULL, 0x7684D9E2EF3B8D2EULL
        },
        {
            0x98D220E8C9D63E66ULL, 0xC7524DA0E1BF495EULL, 0xA202B115C13E2A9AULL, 0x8AA962120DDFA511ULL, 
            0x99DBCD80F59E878DULL, 0x2410F6BF754FCC84ULL, 0x2D408E1A1EAAA62BULL, 0xED64A7C5AB360D96ULL, 
            0x56FDBFA1CDFC799CULL, 0x15990FD34C94165DULL, 0x5BF7E21C1D1F2986ULL, 0xDA95CA7B9CEF8761ULL, 
            0x40CEA83113278944ULL, 0x70956004229467F2ULL, 0x7B0B7B3395C59727ULL, 0x8512ADD788AD7F26ULL, 
            0x8E102B6F27C1CE11ULL, 0x978190584771662DULL, 0xCA6DA7169938C796ULL, 0x81CD292952930542ULL, 
            0x223CB626568AB502ULL, 0x9ECD8988C3ED5B3AULL, 0x06DB066D7A1C58EEULL, 0xE293DA382FBF7CCDULL, 
            0x1A66CACBF4AD784EULL, 0x093DBAADDCE28843ULL, 0xF701A18ACAF5B622ULL, 0xCA843AE80AB49304ULL, 
            0x2D37281E0BDB9D2DULL, 0x962F648FC1BF33BEULL, 0x282E4E45C5FD74FEULL, 0x2F8DE90A37D749DCULL
        },
        {
            0x28D612241FB1EF55ULL, 0x2057495340E6A73AULL, 0x55C837F0540DFF50ULL, 0x7E7C57CB660C70F3ULL, 
            0xAB73D194EE0F1A47ULL, 0xCAD3E37B98E29ABAULL, 0x7C9EE4D80F1CF202ULL, 0xDF9FBB59A4EE2E13ULL, 
            0xEB6B8676C3008088ULL, 0x9989CB059A83594EULL, 0x7DF392D203387ED5ULL, 0x559DC4A69D3853FEULL, 
            0x4E76696601200438ULL, 0x00AE361747BD04CFULL, 0x081C828038093D69ULL, 0x9A233B36C0FC1308ULL, 
            0x18E43F6DFB6DA7E1ULL, 0xCDA1ED9CE8D1E889ULL, 0xB62C11B5334486C7ULL, 0x5795E9C10DF9D446ULL, 
            0x7D378A1899E5E107ULL, 0xEE116520C826591FULL, 0xCC1C3D1977141D35ULL, 0x824EE22F12089314ULL, 
            0x4F8DDFDF9B08E3FDULL, 0xB5E50F686F3DC0A8ULL, 0x992B899024A64868ULL, 0x9C1FB1F8D279C4BDULL, 
            0x340898DBBC479E55ULL, 0x3075EF88BADE0681ULL, 0xA2D3100D76225F54ULL, 0x9212952B8D471AA6ULL
        }
    },
    {
        {
            0x03DA0BF15A53582FULL, 0xA7BB07C85FDA1D30ULL, 0x5484C2C65618FE63ULL, 0xB98249C6723B7F71ULL, 
            0x3BE5C0E5D38CC4D6ULL, 0x8C13A3ECFD3159B7ULL, 0x6E8DC21617D3AEB5ULL, 0x4C08F4A4957AD95FULL, 
            0xC1D89967161D3C2DULL, 0x203B79E44A941BC9ULL, 0xF5DF71E8299EAFD0ULL, 0x5A381937436659A7ULL, 
            0x7EE156FE58DC9AB9ULL, 0x32DAEA2E25BB8AC5ULL, 0x22DEE8E15564D20AULL, 0x057526A9B28CFE62ULL, 
            0x95E05FBA07B6B4B5ULL, 0xE3ABC2B83E88E3A4ULL, 0x25AD50D3A84C0910ULL, 0x93DE9B881531D19CULL, 
            0x4534971300E465DAULL, 0x7171769BC2C6B815ULL, 0xBC8224FDD11D2411ULL, 0x794B54D8E1811F15ULL, 
            0xA8DFD25F5672114CULL, 0xD6DC49B91728E2A5ULL, 0x1EBEEA78E2962A08ULL, 0x1E518788F0BD015CULL, 
            0x820C7352BBA757D0ULL, 0xD55E899DC73B11F6ULL, 0xFC4C5DBC2161AF21ULL, 0x18DDBD5BE784D278ULL
        },
        {
            0x9E64B5603AEA56A7ULL, 0x2A25613AA7DD0131ULL, 0x31FB69E070CF92AEULL, 0x9F8C7320CF01FFBFULL, 
            0x28900451B2154D84ULL, 0xFA943D7BE7F299ECULL, 0x6BBCF703ED4118D3ULL, 0xC8762B781D06F110ULL, 
            0xCAF3021A0E07D2C6ULL, 0x06EA5DA0C9CDBCD1ULL, 0x8075DD783514F3D5ULL, 0x5E96DA321A83B727ULL, 
            0xF81D6A48658E4C80ULL, 0x37CB099A68BA378DULL, 0xD005EE0230DF91A2ULL, 0xBDE0ACCC0B7FF7D4ULL, 
            0x186CD7F45B841EB4ULL, 0x09BF5B1EDCEC2D13ULL, 0x77FCA03064DA171EULL, 0xFD234E232BF9405EULL, 
            0x5B7FBA25534206FDULL, 0xBEF659666D195D2CULL, 0x3678B4B3B0B15C1FULL, 0x7A23CD7CAE7E981AULL, 
            0xB1FBF7EEB2B64BE9ULL, 0xB329A58B205B9CD0ULL, 0xCBDF4C82A556EEA3ULL, 0xBE3D6A5AC17A955CULL, 
            0xCB69038D96FA5832ULL, 0x8920E185436FFBA9ULL, 0x1FC867B286E59BA6ULL, 0xBFD38ACD58ED831FULL
        },
        {
            0xAE1DC3406DEFA01BULL, 0x8351FA44551C9BB2ULL, 0x5FB497E3F35BD5B7ULL, 0x98DA52D8EACFDD63ULL, 
            0xFD84F743A8AD7A67ULL, 0xAFB69A073D3EBB18ULL, 0x24468000225C438AULL, 0xD69D849CDAFBA66FULL, 
            0xB320D407974FCB70ULL, 0xD0B838781F12AD12ULL, 0xE1DAF831486C0E48ULL, 0xA1F520865580C1BAULL, 
            0x87FCB27D826B00FDULL, 0xC373C24A9FC20E1BULL, 0xC0D18F9E605EC208ULL, 0x34859FDF6DF322CDULL, 
            0x51FE5406D7A5921AULL, 0x27A72FC193BC1BE2ULL, 0xD7ECAB62CBF786EFULL, 0x547D2686BCA801A2ULL, 
            0xC7D4CA77355D0D54ULL, 0x4F6F75B164EBA07AULL, 0xED1943C6BF1E7558ULL, 0x25F03D01EEF83B55ULL, 
            0x738A9E704C724589ULL, 0x2AECF70CC72751B7ULL, 0xD0ECD5078A4A4AC4ULL, 0x5F792A2A613A9315ULL, 
            0x785CDF41327EAD80ULL, 0x7AEDB289BF2F1658ULL, 0x6D1275D49FD8CF61ULL, 0x9200D1B670BD8630ULL
        },
        {
            0x8926CD1ABA7C8B3CULL, 0xCF1D45CC77DFF74FULL, 0x3EE6F5B6C2FD270DULL, 0x4E352268D07A12F3ULL, 
            0x1F829CE935FE236FULL, 0x888F508A298CD684ULL, 0xBD0FDA012826BDF7ULL, 0x6D23B394C14081B0ULL, 
            0xC35BF7C4621928EDULL, 0x041D1802EC2B8527ULL, 0x609D032ACAF84D9FULL, 0x60A847F3E4A13960ULL, 
            0xADF2FC6BF7E47FCDULL, 0x1218BDC3992C166BULL, 0x8C6F0011E42D9294ULL, 0x42F069F5C41374F7ULL, 
            0x15A6CED2AF2F4A35ULL, 0x7C595CFD4774B6CAULL, 0xFCC8C5325CD63A57ULL, 0x0C04242FA4A261A4ULL, 
            0x2787212EEF9DE3B2ULL, 0x3EBE5C0265852A98ULL, 0xE3B74B64900AE28CULL, 0xEB9EDB5D86D5613BULL, 
            0xBF55943EB4F32B75ULL, 0x6BB7CFF21F62B621ULL, 0xDB7A52359D0D1793ULL, 0xC3E3CC772FC512B4ULL, 
            0x8685CD0748DB932BULL, 0xBE169119D3F3767AULL, 0xDC99A752842ED061ULL, 0xA3E3772588D06532ULL
        },
        {
            0x53C6C3AF2E017ABEULL, 0x1B6C9ABEA51D1729ULL, 0xA80D995B2C6962ADULL, 0x395522B0E2521CABULL, 
            0x1D1C248F004BE956ULL, 0xA347EAA1585EAF8CULL, 0xEAF5C31F0F0BB44DULL, 0x2611632B2F74E6B6ULL, 
            0xDB213CF435EE3794ULL, 0xF625A957EA0FBACBULL, 0x745B16231F9DDAFDULL, 0xB7CB68B5399615AFULL, 
            0x516E5E662E9C4FC3ULL, 0xDF63C7824689B6D8ULL, 0xE31327460F3FCEAFULL, 0xD9196D4241E1A88AULL, 
            0x280A405BEE4C699EULL, 0xF119A8454E229E96ULL, 0x4454D929712DB7FBULL, 0xBB7E49AB31F6D197ULL, 
            0xFC2492F1527CCA74ULL, 0x97A7353DDE493F03ULL, 0xD03693BCD2ADC523ULL, 0xC2C22DCED4186EE3ULL, 
            0x194CDD1652EB05BDULL, 0xC3B5A2688A2413BFULL, 0x67F30DAA4110D4AEULL, 0x52D1D9E4D3068942ULL, 
            0x9EC063826C9EAF74ULL, 0xE6DAD433FD91CE18ULL, 0xA6D34EB5939337FEULL, 0x2D15F9EC9632A38BULL
        },
        {
            0xE55C2A0CA9E96A69ULL, 0x40EC5DFF16CDB8C2ULL, 0x174F4CDA27D09F67ULL, 0x613BE9EB7CAC1784ULL, 
            0x8BAE2C4868373C2BULL, 0x91B5B81A804615DFULL, 0x5E5664E70F6A02BFULL, 0x47896F5AAEAD59CCULL, 
            0xC4BF7BEB7F865714ULL, 0x9ECC35C30321EDFEULL, 0x48D3CBAC98A723C3ULL, 0x5E9F41D016EF3DDEULL, 
            0x87AD6FD3A848668FULL, 0x55CD82F6BA39F890ULL, 0xE7AB09537C6E81B5ULL, 0x505DB2704E7473FDULL, 
            0xA42071FB5405D089ULL, 0xF2D1319B7E004F36ULL, 0xF5DE67987DD3F908ULL, 0x6FE007F30C0A236DULL, 
            0xA961AE4C00979A65ULL, 0xA9013FF178E37203ULL, 0x50C47E9612344373ULL, 0xB89AE5F60FFADF98ULL, 
            0x01CF32CADFD4E326ULL, 0xD6CB2296103329A6ULL, 0x59278C88D149CCA5ULL, 0x028E19590E486B29ULL, 
            0x437024FECA7769CDULL, 0xBBA4EDCD0D66167FULL, 0xA395FE2F8D09B4DAULL, 0x4D6E18C7CF8294C8ULL
        }
    },
    {
        {
            0x1E7749D55CA7CD5EULL, 0x9FB19E62C700884DULL, 0xCAECC16B4EDD5DEDULL, 0x2477CCD4913730ACULL, 
            0xA87DC54B113C01D3ULL, 0x3DEA22A0570ADC1EULL, 0x3D482B1D2DB214BDULL, 0xBB6566CF7F61B005ULL, 
            0x661E4374158F2D4CULL, 0x4C9FA38579A9861FULL, 0x193B0D3A2718ABB5ULL, 0xB4455F154888BFE2ULL, 
            0x5FEB3E2110E3C69FULL, 0x66DA888A6B69492EULL, 0x1C3139B3BEDF8C27ULL, 0x4898BF3F117BA1A1ULL, 
            0x646EA72CF538EF45ULL, 0xAD59C24DAFAFCBA5ULL, 0xE61ED48798268FC8ULL, 0x568889B41F5252ADULL, 
            0x0104758404034844ULL, 0xFCDA186C7CB5FDE7ULL, 0xD1A4DDD8D6303E27ULL, 0xF1CC86DED6D9F400ULL, 
            0x4A8002F28BB0C760ULL, 0x9B4BDEBC9E3D8469ULL, 0xD5792687647130F6ULL, 0xD1B84618134A4EC1ULL, 
            0x476A085CE68CB066ULL, 0x4A3236D3FF47FABEULL, 0xFD8AC6F74BEAC7C2ULL, 0x08C0008EF0BBA6E2ULL
        },
        {
            0xACFF58516A45B806ULL, 0xC3077F9101D7AF0EULL, 0x6FB33C50A25577B5ULL, 0xCCAE4960071EA5EBULL, 
            0xF1662201542E23DBULL, 0x91980D89E3B40199ULL, 0x25B04A94535963FBULL, 0xC071B01812EEFBA6ULL, 
            0xDB830A2F3274AC9CULL, 0xDBF455E73B027DA2ULL, 0x481B859A1EEFD853ULL, 0x5D389228BBC185E9ULL, 
            0xAC10A798BE00892FULL, 0x49914EE33CA8915EULL, 0x68E0FB0398BAFE97ULL, 0x0CD0004685B56A7AULL, 
            0x72F698D4D8CF6D6EULL, 0x314D6B3DEC7494F4ULL, 0x0A98A0D28233784BULL, 0xFC8CA9B8752DBB63ULL, 
            0x8B6DE663B6E19E41ULL, 0x11F512351138CD08ULL, 0xBFD1FA55CB58EAC7ULL, 0xDD0EC3DEB3B43F84ULL, 
            0xECA9E563A13E959FULL, 0xEAD63DFF29332E4BULL, 0xBBB1BB447BDB8322ULL, 0x97E1199C5FA9C1B0ULL, 
            0x87CB6ED8503F27CEULL, 0x07AB05AFADDEE972ULL, 0xD1F7CE089CA7B1BFULL, 0x9F368AAF92AE83F8ULL
        },
        {
            0x6498BFF863637C90ULL, 0xBCF66A87FE1F1920ULL, 0xC88A3984205730E2ULL, 0xC067F04A65376ECBULL, 
            0x9A99BA1C883E4D8AULL, 0x4142FD83547B2D17ULL, 0x6A4CB7D056954993ULL, 0x35B19A5357BFC274ULL, 
            0x973304A47424115AULL, 0xF54C9919C00D903FULL, 0xA5DC79999F0DAB50ULL, 0x229F5EE513A9F895ULL, 
            0x8BE02F701DB8E7E8ULL, 0x6C24A922E992DE1FULL, 0x8BCC7AEBD5C1742CULL, 0xF720D83524811E5DULL, 
            0xFF161522F71BCE43ULL, 0x2319E139E8149BC5ULL, 0x8DA9525EE53329D8ULL, 0x3AFE7AA6910DCA23ULL, 
            0xF97DCA9BA22C8B96ULL, 0xCDAD6D66886F878CULL, 0x1E34C7BB5EC5F3A4ULL, 0x5156BBE54F0FDD12ULL, 
            0x2598D87A5A946B59ULL, 0x38D0A9D7BC283766ULL, 0xCC463F74526860D0ULL, 0x84AA83B752C3A43CULL, 
            0x0BB7FBCBEE597283ULL, 0xB416A0A955ADBC23ULL, 0x328D25E60F337A27ULL, 0x531DF11379FA5F96ULL
        },
        {
            0x62A4A49D3C7887EBULL, 0x016E8C8FBA862CA6ULL, 0x20F65266B9C6E928ULL, 0x67BDFA247ADD1F12ULL, 
            0xED0D36015040B717ULL, 0xE60118C65B5A8E8FULL, 0x36E71A273A3F7EA9ULL, 0xC14C0074339E0D8EULL, 
            0xD6B4564974D54536ULL, 0x0C9D526A329488BCULL, 0x54B6E4A0C1DE6242ULL, 0x8214D1DF5E9632A5ULL, 
            0x29F67FC6D2A2F013ULL, 0x1380D05CC0B14D2DULL, 0x56E7E85E2F71C6D1ULL, 0xCA060D4C3574D9D1ULL, 
            0x185534724C7C0972ULL, 0x18E9679376BA4649ULL, 0x0864346FF9962E07ULL, 0xB958ED04185243AEULL, 
            0x60C588D04879423FULL, 0xA02BE3F6F602F388ULL, 0x680CC1C2AD73352DULL, 0x86FC3A8E39F62FD5ULL, 
            0xA286246C0B039C05ULL, 0x934C5C52452C2B76ULL, 0x054E78A7DCB415ACULL, 0xBED3F62DEA98B98EULL, 
            0x350B63FC07C41701ULL, 0x6F56E5279F1CBC65ULL, 0xB479D98727FA8963ULL, 0x63D3ABEDF929685DULL
        },
        {
            0x9F1F55FD059CF385ULL, 0x20A284DFDFA35621ULL, 0xF06EA16E9B234B47ULL, 0xC81622FB9259FF8CULL, 
            0x9C0D825A7C7F7A05ULL, 0xCFE220658264D91FULL, 0xD8007308502453A5ULL, 0x337693FF991032E4ULL, 
            0xF69D0F4B3BA774FEULL, 0x005A4DA488E65812ULL, 0xCD133BA65AE796ABULL, 0x013B33735E906660ULL, 
            0x9CFBB983D5E9258EULL, 0xDC0E4DD78891E54AULL, 0x6CB09F708438445EULL, 0x415873B8860482BCULL, 
            0x17F749E1A2AC68DDULL, 0xC3DD43664074C66AULL, 0x8F3454CE0F17588AULL, 0x4D393FED77CD6EF8ULL, 
            0x15609B3883F391A6ULL, 0x5DEFAA72465FB640ULL, 0x5174A80822F3F570ULL, 0x46DE5CB00A78BD64ULL, 
            0xD24311BB934AB3FEULL, 0xB2910DCDE42AF6CCULL, 0xE24E50632B5272B7ULL, 0x0EFE44133509B465ULL, 
            0x6E40E456FCE3C5F2ULL, 0xF0D7AE30E4B63A69ULL, 0x4D7D593B4FA7579FULL, 0xD7CDAC2CB43F53C6ULL
        },
        {
            0xAB6C3EDC4FB5F463ULL, 0x0C0544B0B20C8A9EULL, 0xBF6F84118082B2CAULL, 0x0169E41046C89232ULL, 
            0xDD4E88C2134179BCULL, 0xE5F4F1AD88BD6535ULL, 0x4FB02676B4B18DD7ULL, 0x9E7D88104F9F3512ULL, 
            0x34BA6290CB8C20A3ULL, 0x1AA1778CF4C0D1DEULL, 0x9434D988F88BD43AULL, 0xAE8586A5E3B45EA3ULL, 
            0xC30A37BF99849BE8ULL, 0xA79336CD9A6EFE11ULL, 0x30DAB689F7650821ULL, 0x713DC60AA0D91E80ULL, 
            0x15671E8A5157B62EULL, 0x8D4C6CCD61091FA8ULL, 0xE08F866703A2DA91ULL, 0xC827F0FD1C463C78ULL, 
            0xFEFACB65ECD7D8CFULL, 0xF1AA288BD66CA679ULL, 0x87F4E00077509F4FULL, 0xD65ECB6847DC51F3ULL, 
            0xC92824CC8172AAA7ULL, 0x6D700BFE372001E6ULL, 0xA4BD8E99B208A737ULL, 0xB90564C890B91940ULL, 
            0x15A38A6A17D3D6F4ULL, 0xA0E143D66EFFD7B7ULL, 0x30A353EA532DB2FDULL, 0xF4E4589D79B640B5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeyRotateAConstants = {
    0x282E8DBC6D80CF63ULL,
    0x43C3AA64EC4DE2C0ULL,
    0x342A5F5A79923976ULL,
    0x282E8DBC6D80CF63ULL,
    0x43C3AA64EC4DE2C0ULL,
    0x342A5F5A79923976ULL,
    0xED842C87635AA3D4ULL,
    0x6696848C2063D858ULL,
    0x7E,
    0x02,
    0x77,
    0xED,
    0xF7,
    0xE4,
    0x9D,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeyRotateBSalts = {
    {
        {
            0x5DF1A6FA01F4229EULL, 0x5118CB82EFD2EFEEULL, 0x75B3476C88503E05ULL, 0x2A7531770C670C07ULL, 
            0xC6BB9ABA83861750ULL, 0xE68BD4B356605394ULL, 0x7E68521459D34BC4ULL, 0x31EBAABBF5FE6327ULL, 
            0x9D4441AC28B2B64AULL, 0x2AF539007618C071ULL, 0xDB048921D50DD091ULL, 0x7EF59FF197DDF340ULL, 
            0xEE556B5A774BE02BULL, 0x86905190EB5D9976ULL, 0x53BC98E38F320965ULL, 0xF9C5F411906E89F8ULL, 
            0x3F7D73DFB442D412ULL, 0xBD59474943B1EF23ULL, 0x0933C9E6D34154B4ULL, 0x40017A44C61B2D4CULL, 
            0xD6D987D83FBF8CAEULL, 0x050758D5D4175B73ULL, 0x06BCA33D43302433ULL, 0x9A80FFEB325038B7ULL, 
            0x9DAA3FBCAD41E1F9ULL, 0x5D0803B55BA1C23FULL, 0xF8C655DF5F72F523ULL, 0x156E71F2AA1FC3A7ULL, 
            0x520500446B8EDC24ULL, 0x0641058D117B5A11ULL, 0x3E477FEC7222300BULL, 0x1EBD3770E2E718CBULL
        },
        {
            0xD430CB461113EBCDULL, 0x3022872E43CF6206ULL, 0x36EB5072F8D56E4DULL, 0x9E20FA2EA651DDC3ULL, 
            0x228EEBFE1B58E2ABULL, 0xCBC89853A468346CULL, 0x04D9E32536474003ULL, 0x2E9DC9B092EAA3DCULL, 
            0xC0565E35205485A6ULL, 0x951FFCAEFBC802D4ULL, 0xAEEDB03F3138746AULL, 0x458CF6511C30A4FBULL, 
            0x9DA753E512CB85B2ULL, 0xB1EA18A6CAD98DC2ULL, 0x9826D3944A3D4A8CULL, 0x6D32AFFCE4F65116ULL, 
            0x11754E27B0B70F37ULL, 0x4B72947FC90307B3ULL, 0xFD5B43B7C1596A30ULL, 0x4050F91EF6300710ULL, 
            0x082FC773693A030FULL, 0x146D33EFE22B0B09ULL, 0x10FBE6B656778FA5ULL, 0x90191A1164DE6286ULL, 
            0x27B4D21E0DAF06BBULL, 0xABF494DEE973A8D5ULL, 0xC9D9E7E5819D097AULL, 0x431E64D7A36FA94AULL, 
            0xEBA94273AD8EB2F9ULL, 0x803C83B4B57F09DAULL, 0xD30E5C5E7BA0ED0BULL, 0xFB789597DC270C98ULL
        },
        {
            0x52E9279312020B0CULL, 0x5058069217DE87E5ULL, 0x925B2250258CFEE4ULL, 0x32DCCEB588D670E2ULL, 
            0x65A8C3358D615279ULL, 0x9EC181B93DFAF2EEULL, 0xE2A1ECDF94CCF1C3ULL, 0xD6FAB9E231310A0DULL, 
            0xE00ED53AF6F2D14EULL, 0x4A95E3E8F532B7E7ULL, 0x6CE4CC74B43424B4ULL, 0x59F3499CD1B0DA44ULL, 
            0x6B99CE8631753931ULL, 0x6C491C0DB19358D0ULL, 0xCE6CA12C51A8565BULL, 0x20A7DE4B83DF6C6BULL, 
            0x902DCDEE5872A14CULL, 0x345FEDAB21B10C22ULL, 0x382A722C8930F660ULL, 0xCC9F216C83DB96D1ULL, 
            0x344B20B7F4799A74ULL, 0xA64C9909422A6484ULL, 0x30A3A35C5AC852AFULL, 0x122C479F9CE4C023ULL, 
            0x7E4C5C824447D7F4ULL, 0x74FE06A70C6BD531ULL, 0x58A5D5F5487323F9ULL, 0x9D34BB24DDBEC7C1ULL, 
            0xEF205E31D95F65CAULL, 0x579CCD348D366855ULL, 0x0A5D3EF49D967E1DULL, 0x6AEF708C30077A30ULL
        },
        {
            0x3AEEDA3FBED50488ULL, 0x7290625ED1733456ULL, 0x1CE55A4BD3C6F72EULL, 0xD29F225741ABC32CULL, 
            0x10B9BA2269F4AEFFULL, 0xE03DCD090C8AB1FDULL, 0xF13B1F7779EE8540ULL, 0x805A39A4461CA879ULL, 
            0x35D3FDD89070C3FCULL, 0x5C1366AB03760E9DULL, 0xC06F9EDA21C901D1ULL, 0xE9281235CC3CAB0EULL, 
            0x3CA44010F257E243ULL, 0x07A16F08DE24BF61ULL, 0x50EA4A18380FA304ULL, 0x666902CC77CBE785ULL, 
            0x1AB6F53DBD3577CBULL, 0x4F931AE589DCD909ULL, 0x18F4C2550A33DE1AULL, 0xBB5D716D343239E3ULL, 
            0x1E9A340E03537117ULL, 0x556116B2DDB33B23ULL, 0x15BAA5966751B7B3ULL, 0x9EF16419BB059A58ULL, 
            0x29548C97717963AEULL, 0xA5BB8AEF7A6F9A27ULL, 0xE81653A11A39B403ULL, 0x47F6DED92120B858ULL, 
            0xE307A04199C6F056ULL, 0xC703FBCC4FD64421ULL, 0x0B349A41DAB6C0D1ULL, 0x6F173D390C4C9C4FULL
        },
        {
            0x7B96639D45ECA744ULL, 0x57BDEBBC960636C2ULL, 0xBAF360265DD32EA9ULL, 0x1CA343425AB6A502ULL, 
            0x069D295320D6F9B7ULL, 0x1833F7656BD29EC5ULL, 0x1F7F0F85E7CACDFEULL, 0x659F90AB77A980EDULL, 
            0x320848266084C92DULL, 0xC5D9B671991FBF29ULL, 0xBC691C9E9A473869ULL, 0xB152536A4F1EAC20ULL, 
            0x8A635FE4C8205522ULL, 0x4BD53B4FA7F44B61ULL, 0x732AB3F308E90A2BULL, 0x62F64DE7FB9DD5DEULL, 
            0x61D8D435581E5E9FULL, 0x9F7534093FAF0428ULL, 0xA8CB3AB74CCAF71CULL, 0x01E11E419E0AB1F3ULL, 
            0x276E3D1D3AEDC941ULL, 0xF9121BFEA3E67831ULL, 0x23EE8EC809AB7EFEULL, 0x293D6F19FAE24C3EULL, 
            0x495511A861A3A892ULL, 0x8A874667B6431993ULL, 0xDC831A6784F0B3DEULL, 0x131AE4F691F93C1EULL, 
            0x52138DAE66942675ULL, 0xAAF20D832C792D9FULL, 0x4C9B54BBF01D2027ULL, 0x4937691C21015527ULL
        },
        {
            0x5B0783CFC1A9CF40ULL, 0x313C99C203C64E19ULL, 0x05508C2E44D868BCULL, 0x25DDEE6671D4A9ABULL, 
            0x09E147F38DB7DDC1ULL, 0x47D134BEF48E1C91ULL, 0x33F874D7F1C566DEULL, 0xB8A13B2017172356ULL, 
            0x684AFDE82919B1E5ULL, 0x331239683B645351ULL, 0x37EB463900A6CDE0ULL, 0x24829FFDB6ADAF21ULL, 
            0x5B173A251CD4CF85ULL, 0x4286AE80C3528E30ULL, 0x4DEC344736FD122BULL, 0x28661883097FAE5CULL, 
            0xED7C314726A99154ULL, 0x27AA5DAFAD5959B1ULL, 0xB518A4BC387F4059ULL, 0xFB65C3763A019273ULL, 
            0xA236E4D4F4C21518ULL, 0xA885B24D6322B083ULL, 0x4FD8826595866B31ULL, 0xEB33077713AE0590ULL, 
            0xD6663F44B78545FDULL, 0x0CDBBAEE304DBFE4ULL, 0x5DA426970A7C7690ULL, 0x140C5EA7D1147327ULL, 
            0x83A770AE9F767A21ULL, 0x638BC6B86A0F7706ULL, 0x64BEDFC7BB3FD933ULL, 0xBCEB707E286B7BFCULL
        }
    },
    {
        {
            0x5F05E159AA5D839DULL, 0xDA0CDBFC8290C52BULL, 0x60D48CF3DD89F19DULL, 0xFECDAB6C6DCB267CULL, 
            0x667CE2BA3E68C2E7ULL, 0xC3D5743E75BF441DULL, 0xBC26BFD2F1098A9EULL, 0x789B3BBDA6EEA406ULL, 
            0x6D44B6DC3E413039ULL, 0x058EBE186E725794ULL, 0xA5D8F6C22B2EBBA2ULL, 0x260775722069180FULL, 
            0x783223F7D8FCF526ULL, 0x026A2BCA2FECAB72ULL, 0x64FCDC890DB85A0CULL, 0x5F76C5F3E9975E3BULL, 
            0x18A4B1292C3C84BCULL, 0x8B7BF1DA34F3F15BULL, 0x313FA309B4340F37ULL, 0xC242DF888D78DF68ULL, 
            0x6DA196CE7EF0D068ULL, 0x5103BF543059B2EEULL, 0xDD57AE46DE5F8AE8ULL, 0x1ECC8E28A2F2AB6CULL, 
            0x24FFB04410E41727ULL, 0xE2F13BCFA98CB2EDULL, 0xED27F1BDDB5E32E3ULL, 0x45CECC123E82A91CULL, 
            0xDD2AAFD1D3FD3FFBULL, 0x27A12E3C7502DB96ULL, 0x880DD8B1E9B6C9FEULL, 0x7CF73883BA255778ULL
        },
        {
            0xC1D771F3D18AB7AEULL, 0x8904DE4AAED5E5FEULL, 0x2DF914DEDF552959ULL, 0x3032CF210AF4B97FULL, 
            0xC1469FB289955643ULL, 0xAA2C9621E848D937ULL, 0xED59C43A37E6F5CCULL, 0x93B29386B277F68AULL, 
            0xF69CF6F8D3803239ULL, 0x7D18929B69471506ULL, 0x6179EE108D55C5CDULL, 0xAF694212C83AD414ULL, 
            0x85C7A511BFD78D2DULL, 0x2400F71D02976DF0ULL, 0x6657F78B8F0B4166ULL, 0xEA953BA9E22A792CULL, 
            0xD314131F408A2F00ULL, 0x00AAA5C99D83EF5BULL, 0x9D36F51BBD255102ULL, 0x079CF3E18106E5A7ULL, 
            0xBF83B21DE120FC05ULL, 0x6139AAFC5C651C56ULL, 0x0CDC3359A1EE228BULL, 0xB839A0249DFB3A50ULL, 
            0x35B0A93B2E1155D6ULL, 0xD51F73BC166FA661ULL, 0x7A924ECAA6EF38D7ULL, 0x8BE24DA1AAE1FD8FULL, 
            0xABF76202C65EFD9BULL, 0x6D3105782DB729D5ULL, 0xC31EC90E61B0482FULL, 0x374156B2AB8F7BCDULL
        },
        {
            0xC9A60A592F4E573FULL, 0x1A27CBA8DDD278E1ULL, 0x1D50FE9422A3EBB7ULL, 0x2BDAD6100B9FA1F9ULL, 
            0xAF34611F3A9F373DULL, 0xAFEC7D2669E923E3ULL, 0x01F8D1D4E8FB6A80ULL, 0x7EC36A4135E74348ULL, 
            0x02B505B3F6DCA0CEULL, 0x72F06B02C83644D4ULL, 0xE0AFAD0EE841AB59ULL, 0x4C1F8931D03A00F0ULL, 
            0xAF58AADE4B265199ULL, 0x364BB782134E00D2ULL, 0x5379889962F0F45EULL, 0x4D7D0BB73CCA8150ULL, 
            0xF52749293EEFB4C9ULL, 0x746C7437F0133539ULL, 0xC44C9F3B80816A5DULL, 0xEFA07278FC457DD4ULL, 
            0xF047826DA7F24CF5ULL, 0x6CCC5DE2B2038E9DULL, 0x428594068F82CBDCULL, 0xFEE3CE351693F40FULL, 
            0x09B96EAE75FCFF34ULL, 0x784E15AF5E9962A7ULL, 0xA7CCA367CE3B6F18ULL, 0x808BF7CB641148B3ULL, 
            0xD405B93A8E49FBDFULL, 0x64EB035F52A95C42ULL, 0xDB475B0CE127C16CULL, 0x26515C44E8D77BD4ULL
        },
        {
            0x3D3E8D49ED7D7668ULL, 0x7092900F1E63B496ULL, 0xB119BE820EC176D3ULL, 0x67E639BCEFB9D08DULL, 
            0x8276DB7D6EE52BF5ULL, 0xA656DCEAAE47916BULL, 0x4EC341FC4ECCE0C2ULL, 0x409FE9069DD052FFULL, 
            0x285115BA19CF6C92ULL, 0x34EE4CD563A2A416ULL, 0x4522D3D23F203462ULL, 0xE4C0904ED8AF8928ULL, 
            0x4150DD4308107211ULL, 0xA071F3400DA75461ULL, 0x1019888516CE4725ULL, 0x7B8D066140497AE6ULL, 
            0x19FC5CB36BEF30A5ULL, 0x5A3BE6F22AD6D8DFULL, 0xAC8FB66023E17FB2ULL, 0xDF197F479DE2E198ULL, 
            0x91C79DA902917704ULL, 0xF732D9CBED3B5658ULL, 0xC3936DB55A217A90ULL, 0xCFFFB4AAE7A5EC74ULL, 
            0x87B77C482E044A85ULL, 0xEB870CCE7DB00083ULL, 0xD182E152F031995AULL, 0xDA4F6A9F00304B5DULL, 
            0xDE75A39CBF45419AULL, 0x6229999C7FEC07DEULL, 0x21027D1ACBC51D4AULL, 0x0E5854984751EF12ULL
        },
        {
            0x43A45D16D833B908ULL, 0x134555095AE3547FULL, 0x1B3CE19CDB00D722ULL, 0x67E687B665352BE9ULL, 
            0x46325ADB479A6AACULL, 0x1F07A2AA5D7BFE17ULL, 0xEE2ADDFD9C510405ULL, 0x60FF2C3B64384A8CULL, 
            0x60434623CDBA215CULL, 0xEC7F18366F114B36ULL, 0x60C9E1619E7256A9ULL, 0x70B05A036E2E3520ULL, 
            0xCE0DC1B9CFB82D55ULL, 0x90E77FA45435083FULL, 0xAC9BDC6BD96AF085ULL, 0xEECB4B110E0ED84BULL, 
            0x7C807BFB33E1A3EBULL, 0x727F1B76466CACE2ULL, 0xE573521997613CF9ULL, 0x099A65DE0B9804ABULL, 
            0x6F572186DE95EB95ULL, 0x6731EC5AD177BD8AULL, 0x29F381784585D13FULL, 0xD552DF341832D451ULL, 
            0x1CBD7AFB2DF95604ULL, 0x4A8D42461FD5B8CCULL, 0x85711951A8E4B5A8ULL, 0xA78D84F89B8C3D68ULL, 
            0x3F9C777F90262436ULL, 0x8F7A3BFE70826F1BULL, 0x0128D1131F008BC4ULL, 0x4B1C924A89209D3EULL
        },
        {
            0x7746D7997A72DF70ULL, 0x8C03FC2639C90E6AULL, 0x0C550025E179C2AAULL, 0x4980B97B8E5C34E2ULL, 
            0x3038C1ACCCA4BD88ULL, 0xB66A3801F4BDC082ULL, 0x81AAF5AD7A246D5FULL, 0x8468E300DD6E872DULL, 
            0x1A7744E7B4DC851EULL, 0xA084F690B9CE2D70ULL, 0xFAD3381DCE685110ULL, 0xC866C3053EEBD0CEULL, 
            0xCF5F37B676CC0CD9ULL, 0xC4A334D74ACA9874ULL, 0x0ABCD9972643CA61ULL, 0xD0D956F72F315A2FULL, 
            0x98706404C8FEBBA3ULL, 0x4FC654ADABF575A9ULL, 0xD4B71DFA95F0360AULL, 0xFB37530E25CFE2BCULL, 
            0xB94DD26818577EB3ULL, 0x320373570F0F2A1EULL, 0x081EA4291B438DB5ULL, 0x51571782124C0557ULL, 
            0xF27C9E49BBE84925ULL, 0x868AEA7826468A98ULL, 0x815E0E82E27AB3EDULL, 0xF25FC6292DF1B10CULL, 
            0x7AED0AD13A8A620CULL, 0xB0CC3A3787AC356CULL, 0xE6CCD9BB73CDD7B2ULL, 0xC952996FD762BBF3ULL
        }
    },
    {
        {
            0xFFFA56784E7598C2ULL, 0x4E1DCBC9F9C0AFE2ULL, 0x46CD78A5811C16C6ULL, 0xC95F39531A75F512ULL, 
            0xD09689546E41C5BFULL, 0xADB51C7CB4F0F4FEULL, 0x6FB45904C59BBC13ULL, 0x86BA4773CC9B1932ULL, 
            0xDD7CDBF2C168FAC7ULL, 0x0A3B96199D658DD5ULL, 0xBB6E6E4AF7202070ULL, 0xF3DE6F787A9C0DE9ULL, 
            0x884E954935315E2BULL, 0x5A2A0643A34C6943ULL, 0xDF3164A4B3020A82ULL, 0x1536A66D175FD60EULL, 
            0x86E367E47780B03CULL, 0xD88AD7A746BF9C3EULL, 0xB2E3E013E366D74AULL, 0x225216B1C56E7099ULL, 
            0x0C42E1364D00C5D7ULL, 0x209A181B85950E4DULL, 0x2D9230EE253F59CAULL, 0xDBDE85D16B6B1DBFULL, 
            0xE770FBCEEEDC4FC2ULL, 0x081D6ECD632AD90FULL, 0xBD475A29FF5CB5E2ULL, 0x5944C712A2B47DD2ULL, 
            0xC4956C2CF074C21EULL, 0x4DC2FE2D9EB348A5ULL, 0xDA438B97D273B706ULL, 0x913DBD118916E5D1ULL
        },
        {
            0x417C659D33E6E347ULL, 0x7D0D2DB668865CEBULL, 0x679908E484359925ULL, 0xC485C9150194845FULL, 
            0x4E4D914E0C794A1FULL, 0x14F7B64E63F9B3ABULL, 0x189D09CDB3F7A708ULL, 0x8CDB232B09E3A2B2ULL, 
            0x8A3213B868CCED74ULL, 0x8A0B8D0AC039A3E0ULL, 0x4FEB058C6B814433ULL, 0xE7FF35CE057915EDULL, 
            0xFFC2C7ED1D9172FAULL, 0xD320144CB5E6F19DULL, 0x5EEA1EF8A23C73A5ULL, 0xC38075A35A4F61D5ULL, 
            0xB7AB7718CF3FE1CEULL, 0x486C56F4C47229DFULL, 0x2964C6F492B80E86ULL, 0xF8F6D02B5915E1F0ULL, 
            0x8A5ECD45AA319C90ULL, 0xDBCC405889FA4834ULL, 0x4FC8C167035C1E4DULL, 0x84F35A34FCE69138ULL, 
            0xA2FB13FF5114F777ULL, 0xB2A1E9A79442D805ULL, 0x5ACF0FECC3B2FF92ULL, 0xC53B766EF27B3B5BULL, 
            0xE380874627068BBDULL, 0xD1B7DB12FC05C95BULL, 0x3CCADD0D88481DBDULL, 0xB78F8C6229FF4F28ULL
        },
        {
            0x3FD40D297A4C2DCFULL, 0x676BEDDAB4B12C66ULL, 0xBA9A78E9DA6774DCULL, 0x6910E8DE029F88ECULL, 
            0xF3F4159171EFA182ULL, 0x8988C129C551511BULL, 0x74B64B3D95820E56ULL, 0x3AAB0EB47F303853ULL, 
            0x0B1E09E170A97881ULL, 0xCECF7ED207F39166ULL, 0xFC60E7C6086EB89EULL, 0xD0AD56584181F0BEULL, 
            0x3ED7FC79760DF6FEULL, 0x43F296C5BB096B7FULL, 0x7E83227643DF4EBAULL, 0x66E34C587DDB4682ULL, 
            0xCA52EB7392C85DF1ULL, 0x94C7938B86D34483ULL, 0x5049EBD025D8986AULL, 0x2DE457246AD2A867ULL, 
            0x8267C46A85ADF2E8ULL, 0x24B805CD32DAA035ULL, 0x182A2A4BAF085491ULL, 0x9F96DC2BC69096E7ULL, 
            0x7EDA91E8C536C32FULL, 0x89F6BAECE0C3F0B7ULL, 0x8EE1CA03D51A37DDULL, 0xA41C5599DCB9C743ULL, 
            0xCC04791D8E8447C3ULL, 0x9E9C2C553ACC37CFULL, 0xB64B3F58430312E5ULL, 0x4C4F4630175472CDULL
        },
        {
            0x67D8E33FEDBDA2A3ULL, 0x98985D06DF24351BULL, 0x7C8743A4ADD38A27ULL, 0xE4844FF4B0491FCCULL, 
            0x306BF494F78CB2DBULL, 0x7A463657A101F74AULL, 0x3306342B8F9B032FULL, 0xCDD5E2085523B325ULL, 
            0x3400F24EA5036E3EULL, 0x02EB17CEE8728B54ULL, 0xFBC7042CD9E832E0ULL, 0xE420C0F151230876ULL, 
            0x2C889D48EBF7D0A3ULL, 0xCA05B610CAC9A099ULL, 0xB11A3812BEB56D54ULL, 0xEB11542BA31A0813ULL, 
            0xAC33B3C38B3AC13BULL, 0xC149F6940585D009ULL, 0x55A753A9C251F734ULL, 0xB2121E6005B98069ULL, 
            0x7EA5E6D8DA46A4AEULL, 0x5BB7B09A7013C9E8ULL, 0x1AFF520D25662609ULL, 0xF32C3C65759176A5ULL, 
            0x66D2D6E31A109B8AULL, 0x307A47ADBC846020ULL, 0xEB4ECB2C16A4543CULL, 0xB3B6B1636EF5431EULL, 
            0x0C12FB295D57A5BCULL, 0x8744C231D3939E97ULL, 0xE0918E1DF4B25688ULL, 0x9D7F35144D3AFFFBULL
        },
        {
            0xEA200EED58757780ULL, 0xC4D77D84CDEE1A0CULL, 0x63E74F35978310F0ULL, 0x17994A544B148FC2ULL, 
            0x14D51344006DDD1FULL, 0x74A718568B868FC3ULL, 0x6FEE98A4F69EB5DBULL, 0xC6FEE39D066D4142ULL, 
            0xF3721E8C24229821ULL, 0x00E0D4B8517BBF90ULL, 0xE0568AAB3616BE79ULL, 0x0D3EB1F3958A722FULL, 
            0x08A10406A01E0F2AULL, 0x4B08F4B253C553D0ULL, 0x4D78EF8D42056036ULL, 0x01705ADF372DFEDEULL, 
            0x027D209916E2CBF4ULL, 0xCAFF6620E5AE03A8ULL, 0xBDF329D9AACBEA2CULL, 0x2568D2AF85D91884ULL, 
            0x378DC2087BD64F21ULL, 0x3E9D534DAAB75C85ULL, 0xA72A71D99933EE3CULL, 0x23461E6D2C06B6F8ULL, 
            0xB5CF818D7AE180ACULL, 0x6668AE8B54017874ULL, 0x6B2394150599592DULL, 0x6DE0B31CDB218CA4ULL, 
            0x308A84F2D883718FULL, 0x0658E9FE5183A3D9ULL, 0x7A28C5474AA41451ULL, 0x59B88192E246E3C6ULL
        },
        {
            0x2F710F96E255E603ULL, 0x9297A82B5D99E2C0ULL, 0xE89C0424556A0FE7ULL, 0xE56D372A3730D760ULL, 
            0x75C0440F376ADF67ULL, 0xDB59FA82D56C3813ULL, 0xDBAFB22919038902ULL, 0x417E1094194A2244ULL, 
            0x226D6915D6BCD38DULL, 0x9CE7C906ABC2D269ULL, 0x3B499D0BECF98B23ULL, 0xB619E49D1AAB1715ULL, 
            0x26752382A4027627ULL, 0xD9AB0A5D27939792ULL, 0x76BCAEAA22F5C68EULL, 0xEFEF05045D9CA881ULL, 
            0x65A3A84B4D8EC29EULL, 0x5010B56A905452D0ULL, 0x57AA0C4D80CAF339ULL, 0xE8221A0630C5283BULL, 
            0xC15BCB77E9E997E3ULL, 0xEA54501432981661ULL, 0xF546DCDFD65CAD46ULL, 0x90D08C09EB8B9C90ULL, 
            0x3CD71074C9CE8F3CULL, 0xFCB64D05E2F49949ULL, 0x0BA2A336101BA92EULL, 0xB23A60C5D1919566ULL, 
            0x600A0C21CD9127A2ULL, 0xF343C94DAE5D41D8ULL, 0xD80DCA3677A095DDULL, 0x2E629CCB10645EB0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeyRotateBConstants = {
    0x815FA56C5386F9E4ULL,
    0x3A7271D0D4C0FB66ULL,
    0x27007F5BE89D4508ULL,
    0x815FA56C5386F9E4ULL,
    0x3A7271D0D4C0FB66ULL,
    0x27007F5BE89D4508ULL,
    0x1CA2BD0CA138AAABULL,
    0xE167BB5BC800C84DULL,
    0x0E,
    0x88,
    0x79,
    0xA3,
    0x84,
    0xE9,
    0x11,
    0x98
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeySpawnASalts = {
    {
        {
            0x3D67F0E59C5648D5ULL, 0x07043695BBF1859BULL, 0x825973A2C34A373AULL, 0x522E977D6B7A24FBULL, 
            0x5E9B4C350C040BB7ULL, 0x696366843E72658BULL, 0x363E6DF079F254FCULL, 0x59700756F84A806AULL, 
            0xC7CA5C049CDA1821ULL, 0x8B9B0F471BB9466AULL, 0x9CB078661F2AEAC9ULL, 0xF628F44093664478ULL, 
            0xB41F16EEDB22D435ULL, 0x68EFF6083E784E29ULL, 0x864E7695A4C27FEAULL, 0x1AECB228DB082774ULL, 
            0x836B23CCCEE145FDULL, 0x9E4F4ACE68E8BA85ULL, 0x87877E67056AEDF7ULL, 0x8C01982889D08B61ULL, 
            0x2C6C719C6A1DA51DULL, 0xE368F0F39E5D92A3ULL, 0xC08F7A2D26A25D2AULL, 0x83300F6BB5577B04ULL, 
            0x4FB20F3CD746BC03ULL, 0x620704D1CA1703FBULL, 0xFB9328320BBEC8FFULL, 0x6F1B77851B9A1F49ULL, 
            0xE29D0EB7F4E1F3ECULL, 0x8D9B08C62EF490AAULL, 0xC5C6B4E3E866027BULL, 0xF24A2B08A026D2C1ULL
        },
        {
            0x14DB7C8E703D45B1ULL, 0x2E02D8A7E2786497ULL, 0xE1E987BBC38F9F9DULL, 0xC0948F6994376359ULL, 
            0xCCE895039C1B93EAULL, 0x76AC4DD99995FF0AULL, 0x4B62C685CC6149E3ULL, 0x8ABA9F8C9ED843B8ULL, 
            0xEB7C74EF50B1639DULL, 0xB3616A7B196079DAULL, 0xAD64B0E01FF2B027ULL, 0x5109246D47E4B7B4ULL, 
            0x4D1B95E95F0170D1ULL, 0x0C85605A7718D364ULL, 0x27E0FCD782DFD9BBULL, 0x456C19DDCA965647ULL, 
            0x7CCB7C2D3A6ECBF3ULL, 0xFE3E0B9E390FD729ULL, 0x4C9BBFDC65D52E58ULL, 0x44CAF409382F8943ULL, 
            0x87AB50B07B66920DULL, 0xFD6594438E562D8DULL, 0xEEBB2EB1CE8123C4ULL, 0x5B0693452E22032CULL, 
            0x6A0E0505FA42AF2BULL, 0xDEA1EC498AB46784ULL, 0x5294DA5DBD4EFBE8ULL, 0x849B5D2A5C5BDEC1ULL, 
            0x3EB8A20BBF995ECFULL, 0xF4E39A5B41D3F8ACULL, 0x1DE6F33FCFF8B8B7ULL, 0x1D833CBB88BFCDF5ULL
        },
        {
            0x55F4593323D1132AULL, 0xA7D3EC68C9D26F5DULL, 0xFABE554D325E5793ULL, 0x3062428E260079BEULL, 
            0x0DD01FDA4A4609C9ULL, 0x530DB0EA19031B40ULL, 0x927568617E2E7B30ULL, 0x72D74D6C08711862ULL, 
            0x2064330FF52C5BBBULL, 0x5875A7CF11990120ULL, 0x6D95EC0292E81BD6ULL, 0xD093114927C83C10ULL, 
            0x991E7257707EC194ULL, 0x06A5BC7B1BBF41A9ULL, 0x7269308C126CC41EULL, 0x4ED43B06D453796EULL, 
            0x980834575C71A72DULL, 0x52B2E5A6BDA92622ULL, 0xD56C5079AB90643EULL, 0xCD92937DBDCCF1EEULL, 
            0x6C76E42AB7456912ULL, 0x66D47CC35BEB2A0EULL, 0xE22B9D61638ED72EULL, 0x8FF0F2A302DA87C5ULL, 
            0x27A5634FCFA8A677ULL, 0x74C75A4F8337EB84ULL, 0xF6D1A08A31453B5EULL, 0x1111CA77A2EF4AD1ULL, 
            0xEB7C291754574297ULL, 0xF2FDC762CCDCB0B8ULL, 0xED35BA8B52CC17C7ULL, 0xFAB33CC7674C3676ULL
        },
        {
            0x43B9711D98D38101ULL, 0x533AF854AFF9A060ULL, 0x1F28BF6BA619FBC0ULL, 0x679D26FC42DA3C6BULL, 
            0xA110B0BC38F756BDULL, 0xC72A116A0167910DULL, 0x0912170A55463899ULL, 0xA283555B59AB96FDULL, 
            0x17859A8B39A4BBB9ULL, 0x8AFE34E0F04459DFULL, 0xC7EF381C73865062ULL, 0xBFED3D297B33B7C0ULL, 
            0xA6E2EF599A38C67DULL, 0x3E8E50122C093DD7ULL, 0x6CFC0EEEBB50F3CFULL, 0xAC2624E77B282077ULL, 
            0x8651DC4E15E7EAB8ULL, 0xB1C3F3E7887F193FULL, 0x555B16FD279B1140ULL, 0x2088DD6C9AFE23CAULL, 
            0xF3D77FD9D0FF2D64ULL, 0x08CCD5F29D9A0B8DULL, 0x81FA0C7A64669C7BULL, 0x71721D431E10AE16ULL, 
            0xB5FFAC39F3B7AC98ULL, 0x6C7EBFAB495F0776ULL, 0x9A01ABD4551689B0ULL, 0xD35C457CBB4FCE4BULL, 
            0x6F8A099A29F22F9FULL, 0xA364F5692E7353CEULL, 0xCE497FDBC6FE4847ULL, 0x0DB7132CADC97B23ULL
        },
        {
            0x38FFBBC09DD91F11ULL, 0x828EC0359DD5F966ULL, 0xB277FA575C44B189ULL, 0x73AB71D6E431AB20ULL, 
            0x10CCCA00E17C4A5AULL, 0x2E2680512B8BB2ECULL, 0x877AEF05D6386C23ULL, 0xBAB504255E3F5BBEULL, 
            0x0B25555DA4F2BF50ULL, 0xFE2A5A6DBF443CDCULL, 0x066687567C90546AULL, 0x1D90CA84BBDA2D71ULL, 
            0xEAA9AD1A963EA742ULL, 0x7A4066C48238FA98ULL, 0x6DA7F67DA7836E23ULL, 0x9116000961B1ED50ULL, 
            0x3FEECA25816B7705ULL, 0x2D3A57BEED9CE486ULL, 0xFA267DC59630EDD3ULL, 0xF8D025E3CC963D1EULL, 
            0x6DF518121C27638BULL, 0xED80DE750A29EAA6ULL, 0x496C4E185D85FDB5ULL, 0xD622F35D302EEC54ULL, 
            0x5146D70BE806B314ULL, 0x28B4889B2389A8DDULL, 0xB304E386FD00B7C3ULL, 0x16AAF31DAD35C203ULL, 
            0x4FA302C3AAB19DADULL, 0xFB815DD2C888DA7AULL, 0x4EE969D9D4885650ULL, 0xF2B81C836ADA84FBULL
        },
        {
            0xC5539ACEA665708DULL, 0x497C84D7FDF830CAULL, 0x725AD5DE59CBF46EULL, 0x17136BB39FD4172FULL, 
            0xADA3217CF8FEC271ULL, 0x3FD0AF34B1951CF2ULL, 0x5BDFAC9ED6C7FDEEULL, 0x6E9C8C2449DD028EULL, 
            0xA9FFD23C7B4C7216ULL, 0xD41F1D02D4F6CE09ULL, 0x593C5AE385ED06EAULL, 0xF72845EAE8680FA0ULL, 
            0x4B6F1242DB4DE4D7ULL, 0xF12664DF7F5FA7BDULL, 0xC91BDF77F966F860ULL, 0x722048634065C71EULL, 
            0x07507EE236A42839ULL, 0xA8BD16B3DA593FF5ULL, 0xD1AF28983D5DD0DCULL, 0xC8030AC504DC843EULL, 
            0xA3DF92C38C0E3B58ULL, 0x488204E2BD88782FULL, 0x2057B3B93965772FULL, 0xD4077CD1849AF98CULL, 
            0x51FF42868D112DA4ULL, 0xC83E9DA28ACCC767ULL, 0x3264714238A53CD9ULL, 0xF5A568C514A58B34ULL, 
            0x42D4B9C71C77408FULL, 0x73E9D1339BD9A388ULL, 0xF6D04B604EEC09B7ULL, 0xC4FF411E3C80AAF9ULL
        }
    },
    {
        {
            0x27F3630B130CAE6EULL, 0xEFAC28101748075FULL, 0xD004689F6AD804BFULL, 0xAFAAB913516AF22EULL, 
            0x5D8FB45E412E8169ULL, 0x710B872E828887C5ULL, 0x45BC91335FB331BEULL, 0xB3379716816DB83EULL, 
            0x4AFC05322B515BD6ULL, 0x8A05F52CBAF87DBDULL, 0x4BFEA76FB684B538ULL, 0xDC443A3B6F0FD153ULL, 
            0xE79254A00F550984ULL, 0x2DE900F276C3ADA7ULL, 0x63F220EC5FCD0226ULL, 0x6BA7A6A1B02B02F0ULL, 
            0x2C0AC7C18808D7AFULL, 0x05940866E8F61F40ULL, 0x86C615440C2743D7ULL, 0x2B06DB53DC9DB008ULL, 
            0xCB7F36397685A8DDULL, 0x22397F2718A9802AULL, 0xB8B45E6DDB1A190FULL, 0xAC73F0F7822ECDE0ULL, 
            0x22704785E02D6BF7ULL, 0xE9AD4608051E0B94ULL, 0x3067FF65ADC04896ULL, 0xEC0B95E019AC93B1ULL, 
            0xDCE1A665ACD7D5E6ULL, 0x66D6CD153E05CB9BULL, 0xB7AE6E368F3EE4A9ULL, 0x310F4BD4C5CA5934ULL
        },
        {
            0x1060842E08A6DA84ULL, 0x30DEA80B1954AB96ULL, 0x4CB262D19E75991CULL, 0x8A7A83CD04BC879EULL, 
            0x3997FF01653B5C9EULL, 0x4129BA20D8538DD5ULL, 0x190AD36B61E64579ULL, 0x3F9351035994C78CULL, 
            0x1131EC3E8F67576AULL, 0xF09FE0248942C667ULL, 0xEF387BCCB3AF6BB2ULL, 0x8ACA9EDE58269366ULL, 
            0xCF2EFBD10DDCC8AFULL, 0xB35CE34497916EFCULL, 0xD6B56FF573272F53ULL, 0x97C79A5654F761F0ULL, 
            0x4E319F79CB3614D7ULL, 0x4EAA2DD7F2123520ULL, 0x829C417EC2106AA8ULL, 0x8DFBB30D6C5C7F89ULL, 
            0x4915925B05414A70ULL, 0x94DBC5CB6E059666ULL, 0xE665EC7AD1B9E485ULL, 0x950B33F0D6897529ULL, 
            0xD43B4459C4111456ULL, 0x6681EEEAD1D9F421ULL, 0x07AC1E5FE7EBA510ULL, 0xC318B62BC58F2BC4ULL, 
            0x35C1D69FA8EBF713ULL, 0xCDB0B731A1A77A27ULL, 0x77F2666AC013BD49ULL, 0x6760F4B7418258C3ULL
        },
        {
            0x93E027000ED66D74ULL, 0x953F6BB45C7E0D16ULL, 0xBF4813180BC99A37ULL, 0x0E2DDB3170898C3AULL, 
            0xEEA349AB25FEC784ULL, 0x90F21C7A16F1A40DULL, 0x95FF1AC0C28056AFULL, 0x795FC8C014A9D497ULL, 
            0x8CC953DADD885551ULL, 0xAEE12C16BEBAD50EULL, 0xDE9379DB15BA4D48ULL, 0x2B35943229C934F8ULL, 
            0x1D911770876F15C4ULL, 0xE7975DD0D23926D4ULL, 0x3E912E48BA04BD36ULL, 0xA89C269C4558AA03ULL, 
            0xA93A0A813CDA9B6AULL, 0x01587B6DD2446425ULL, 0xE318ACD4ED44ACFDULL, 0xC6F7AB9E036D5BD9ULL, 
            0x1E6BF9ED2C412E22ULL, 0x042817565EC3D131ULL, 0xEF82FDB20EA33992ULL, 0x9FB806B501F9B310ULL, 
            0x986587DEC3B4588DULL, 0x015B2C1189D4C727ULL, 0x79B3BD612DC3DCFFULL, 0x0BE6817E367B8AB4ULL, 
            0x02E10D483EE6B81DULL, 0xC02442EADD3576ECULL, 0xF9C538F78C9D8210ULL, 0xBC8E49885B337815ULL
        },
        {
            0x7933D9BFEE7AAC52ULL, 0x0181DA7DEEAB4253ULL, 0x7A0694EDBFC5CFFFULL, 0x5132C3D72B6B031AULL, 
            0x47550A593BAAE791ULL, 0x185A81C18BC2D40CULL, 0x5A430FCEFD69E4ACULL, 0xEA975466B1FBA8D1ULL, 
            0x0380370632F690F2ULL, 0x89A2AFE0B272B333ULL, 0x42E1C25B8833AEBBULL, 0x6D06A164BD4EB550ULL, 
            0x3503B9E2A846A18DULL, 0x463AF6A50FE72B8DULL, 0x9D6288591493C7A9ULL, 0x1A04E793E454D92EULL, 
            0xF61D45FCBCA4EC9BULL, 0x430D47AF271E24B1ULL, 0x9A813CF86A9B55E0ULL, 0x832037C87547DE2AULL, 
            0x9EEE6F2828A310DBULL, 0x2DCB188E87FF7209ULL, 0xA06F9076E3BAF084ULL, 0x37354C03F4CD9AE0ULL, 
            0x14A86DD5B860C9C1ULL, 0x4BAE9715D769F78DULL, 0xF22FE98F1140E60DULL, 0xA1D190B15EC6F4D3ULL, 
            0xA04CC48D87BBDEEEULL, 0xEDC508C89BAA2D23ULL, 0x823EC9784F0F15FBULL, 0x2F1D4F44E89EE740ULL
        },
        {
            0x8CA3AF725D79429EULL, 0xC6E32D792482461FULL, 0x443739490F954D11ULL, 0x526C52FD8CD7876DULL, 
            0xFC7EC690B39CFD0BULL, 0xFD91E9CBC2969632ULL, 0xA9E7E13EDBAB746CULL, 0xC519CEA7D49DED35ULL, 
            0x4D6818517CB30FB3ULL, 0xEF97A112B5340E8AULL, 0x9A1EF67CE22008D3ULL, 0xDA9B50E9902C1A68ULL, 
            0x2183B38AD5E23CC3ULL, 0x47682C0882DBDB58ULL, 0xC6DC01B0FC12B159ULL, 0xAEFE5E5F4045B43DULL, 
            0x93C57B1BD8017B93ULL, 0x64709E68F33B14F7ULL, 0xC0EAA5604B2D4304ULL, 0x566CE5445012ED94ULL, 
            0x7A0797326FD8490CULL, 0x30494A4B703F30BCULL, 0xFD6C26D6746973A1ULL, 0x87189128624B4335ULL, 
            0x3131F2C0C254452AULL, 0xE9661881424A5584ULL, 0xB1BC21341C38D3C4ULL, 0x872BF5095E38A553ULL, 
            0x9E9FDAADDB9DF390ULL, 0xA9503F2572FCB942ULL, 0x64659500431F6241ULL, 0x4D366519828F5E98ULL
        },
        {
            0xB7F4C3FBCAD51DC8ULL, 0x1CBF3D831BFC4C46ULL, 0xB9CBD3F1B2B244B1ULL, 0x7D7AFF14727AD4E6ULL, 
            0x8CF3AAEB0D81DAAFULL, 0x1CC06DDB3A607AE3ULL, 0xB1B6BC4840F81527ULL, 0x9D65895A2165E350ULL, 
            0x0D913192F5B4E989ULL, 0x98C22A89B49A8DCCULL, 0x7D9750B59432E0E7ULL, 0xF2C5F2CF608F2B63ULL, 
            0x16133EBDDB61FBECULL, 0x3B09E14D64E270E0ULL, 0x1DB08A09380E4E7DULL, 0xAF09ABCC1E96D4A7ULL, 
            0x6276B2B86D228764ULL, 0x1994ADCFB2484724ULL, 0xF6CE61B6DF166131ULL, 0xAEB8ACA4A760C682ULL, 
            0x83BD6BD4934AF2F8ULL, 0xE0324E9EF4020D20ULL, 0xFED3441B307E5FF5ULL, 0xEEB57C5B92683BC1ULL, 
            0x2772B827A118736FULL, 0x735CF1B3C41F4721ULL, 0x02EE825A3E5D5419ULL, 0xDF60990F957414E7ULL, 
            0x02CE3B91018C7389ULL, 0xC6A230E591912A90ULL, 0xE967D7D92E908A61ULL, 0xD60DA996CDCA63CFULL
        }
    },
    {
        {
            0xB6977DF2BFACAA14ULL, 0xC3B951125E62E176ULL, 0x8D21DC826273D032ULL, 0x2A3AB62A468BF69DULL, 
            0x9BD0F9BC0EB2FE89ULL, 0xF350D26AE7098CDEULL, 0xDD385A84D93265BAULL, 0xEABBCED16DD32B4EULL, 
            0x1AADA654B4E3733FULL, 0x7DB86EE06FFCA0FBULL, 0xD7392DD8249764A1ULL, 0xE1D5318E8B7DE45DULL, 
            0x47EF26F1A724E4A5ULL, 0x610029EAC773DE36ULL, 0x02535066730A4C43ULL, 0xA8F8956BB8F3F1BDULL, 
            0xF24A03224F84E1DDULL, 0x4B32BCF50B5D697EULL, 0x74F0418EA52D709BULL, 0x58836A5FE409089AULL, 
            0x984CD43C91EDF9AEULL, 0x77F321F075170B46ULL, 0x39CE063B43DF7A10ULL, 0x9B7C0D8C47B62746ULL, 
            0x37E3ABDE30559020ULL, 0x8DC948FB17BF8B18ULL, 0x24121259F999E48FULL, 0x2A066B028551C25EULL, 
            0xBB7BEBBAFC957E88ULL, 0x6EFB07BFD8AF34BEULL, 0x0945FD3C524802ACULL, 0x207DC3B286AF5FB4ULL
        },
        {
            0xB1A0115F8978BCEAULL, 0x0E72F3EA91F4F7E6ULL, 0x309058CB307795E0ULL, 0x7A2E742D16285FA2ULL, 
            0x11D45A9944E2D653ULL, 0x6B0A12FDEBA8CF04ULL, 0x217EB88079DCE120ULL, 0x47E4E5ED54E69638ULL, 
            0xE82B970EC47E92F5ULL, 0x5D3046020EEA9E6AULL, 0x5D0D5C28FC709E0BULL, 0x91D555D451DC388AULL, 
            0xBBDD963CA42FDCFFULL, 0x97606D6349C7D9E0ULL, 0x11EC11F3D9BF8C11ULL, 0x578023320733C451ULL, 
            0xA3E06E56B8347707ULL, 0xADBE5EB668CC2CDEULL, 0x17EC046AE94457DDULL, 0x07473FE52E17F11EULL, 
            0x7C5FAEAB06C4AD1DULL, 0xC2353D2C6844E8CDULL, 0x7A31FE9E7AD33F0BULL, 0xB7D623569BDA2A17ULL, 
            0x3465F5C74E9AFB87ULL, 0xC93138C660A78E2CULL, 0xDD5CFC5568A8F97EULL, 0x750A941F11DC32F2ULL, 
            0x6956D34370A82F5BULL, 0x9C9DB2A12723051CULL, 0x4B4F2E4F8BF16792ULL, 0xF093486BCBDCA329ULL
        },
        {
            0x55DB0E7C054456C2ULL, 0x1BD6F9159C49DAFCULL, 0xD77D53F4E7158BF9ULL, 0x5A71FE9E5473529CULL, 
            0xB196AECB51EDE744ULL, 0x74E18E34F23FFBDFULL, 0x14B14B88167A9850ULL, 0x304D85045D5B4930ULL, 
            0xEFBAFA7C69EBAC5BULL, 0xCE9E34120F36AA6EULL, 0xD2730C7F93123570ULL, 0x9684F078D2677267ULL, 
            0x9877DA6901965404ULL, 0x5290C381FECAA9D7ULL, 0xFD9828AE0BBD3D7CULL, 0x6A71C27398BCE2C4ULL, 
            0xA6351ACE62E99DDCULL, 0xE86EE111A3EA5C00ULL, 0xA8B8DA08B8FD3E80ULL, 0x931D875E2C31FCB7ULL, 
            0x0E76D559283760F7ULL, 0x2CE909DCDC5B8266ULL, 0x2A31D759491DB02EULL, 0x490A79AC07D49FB4ULL, 
            0xB8E192994880989CULL, 0x5CCFBC54D7E6AE30ULL, 0x787FCF0F899782EFULL, 0xAF7783E10923CE0BULL, 
            0x125D66DF7DCEE8A5ULL, 0xB7DB0F81C24D8406ULL, 0x9AF74D4456A49D8CULL, 0x19A1FAAB0BE89389ULL
        },
        {
            0x608B6A8147D9EF41ULL, 0xB49AAE07B826BB16ULL, 0xABAE9324A7BB9072ULL, 0x34AF9D568E49B1F3ULL, 
            0xF3EFB63D6ABDA1CDULL, 0x206F8B2903E0F65BULL, 0x2510BAD800B80C8FULL, 0x1D8718A278F4A486ULL, 
            0x9E43B1C7C8DB8F74ULL, 0xFFC2C1C489AC8491ULL, 0x524B76DECE78C2D2ULL, 0xD3F5A341C4B317C5ULL, 
            0x72036B1329858117ULL, 0x29D6080ECBB49061ULL, 0xB719662D2B9BC415ULL, 0xF6AAE468F39AAC9BULL, 
            0x4BB7BBD0EDFDE111ULL, 0xF98E1E55B73530E0ULL, 0x7C13340533D4753CULL, 0x3CEEC4D9FEF04F55ULL, 
            0x8FAF022151998572ULL, 0x028D8CB4CB8F7C25ULL, 0xE54D5E9A11C29E4DULL, 0x5DB8B4D6B56C1AC7ULL, 
            0xEF0F5D9C2312421CULL, 0xCBBC826B0EB2E9E6ULL, 0xD7226134619DAD70ULL, 0xE30186FF66356B4DULL, 
            0x71BD9AD8FEF8C50BULL, 0xC9DACB76D7736ED4ULL, 0xA46C822C7502AB63ULL, 0xCC3F1E8228C52215ULL
        },
        {
            0x0C737674D376327DULL, 0x64CFFBC40EFA5EF8ULL, 0xFD70954B75A26326ULL, 0x332ABF003AC84C25ULL, 
            0x2A7C2F0EA7C0A240ULL, 0xAED1321416E22F90ULL, 0xAB96E95DAD4FC842ULL, 0xD9BF6093899566CAULL, 
            0x196C7C1952841C0EULL, 0x548D08AE3712D9C1ULL, 0xACFE0FBE97A1F71FULL, 0xAA85A1C9483D3912ULL, 
            0xCF2DF146EA8B0AA0ULL, 0x4FD279827481D06EULL, 0x6D4595FADF682953ULL, 0x370C74410EB8D3EFULL, 
            0xF932B189A2BD80DCULL, 0x4C9BEFBB10874334ULL, 0x281DA56866DA4CBEULL, 0xAC244056B77A993BULL, 
            0x1D2DA482C017D223ULL, 0x56DDCC01EDB9F83CULL, 0xDF4C9EC8A2C5FDC8ULL, 0x061076B3ABF1BD33ULL, 
            0x75AAC43E52F0260CULL, 0x4C405AB563D03386ULL, 0x482DC9AE4E3A1FE0ULL, 0xF46D60F121FC2F64ULL, 
            0x402E1CCFBA741993ULL, 0x48ED2903DEA23A88ULL, 0xDB90B4D60FDC5D5AULL, 0x754F7543AEC731A2ULL
        },
        {
            0x7842FA7525E77C15ULL, 0x5F68B793B98B9482ULL, 0xE9EC39703E786307ULL, 0x38FBF8E5A466715FULL, 
            0xF3A6BA0350265A11ULL, 0x8080969350B5CCEDULL, 0xD144C89335B0EB05ULL, 0x26CDF34DB86AAB2DULL, 
            0xB7FEA4FDEC4576C4ULL, 0xEE379717FB5E7EA7ULL, 0xC85496CA4369D315ULL, 0x20BB16F2406FCE02ULL, 
            0xCEA0DB7CA7B42344ULL, 0x7C2B944193F17666ULL, 0x9190FADEB7BABF7AULL, 0x6879EFE55F61D63EULL, 
            0x3A2B6B07A37A3866ULL, 0x31521E0422417E4BULL, 0xCD35A7E749FEBA77ULL, 0xCD3BE845D60054B1ULL, 
            0x7B9621D56E9C724AULL, 0xEE19C4110B75771CULL, 0x1585CF054E7E9119ULL, 0x07A29F1009B9F1F0ULL, 
            0x863D746840A49AD3ULL, 0x3FA281672D698645ULL, 0xDEC52454C946E722ULL, 0xE23B36C79DA5B3C9ULL, 
            0x2B370DBBBF337F78ULL, 0x9FD470393DC4773EULL, 0xABA4955DC16B485BULL, 0x37DDFB5285A7A53BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeySpawnAConstants = {
    0x77ADC1F2C1E36C87ULL,
    0x20671F06B24FF34BULL,
    0x92908DD93EAC0167ULL,
    0x77ADC1F2C1E36C87ULL,
    0x20671F06B24FF34BULL,
    0x92908DD93EAC0167ULL,
    0x98520BD8836D977AULL,
    0x894A962205C9A7CFULL,
    0x43,
    0x63,
    0x4F,
    0x03,
    0xD5,
    0x28,
    0x24,
    0x4F
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kKeySpawnBSalts = {
    {
        {
            0x2CA0335551CAF454ULL, 0x7D7A59D9A117E7B6ULL, 0xA068640414535292ULL, 0xFE52EE0DCF735A0EULL, 
            0xD289CA70D401427AULL, 0x7C4BEB9B1F1C5BECULL, 0x2CA065D05176F820ULL, 0x96BBAFC67E5D5522ULL, 
            0x4E70A0FFBA92BD11ULL, 0xA25537EAE0372D6AULL, 0xCA28C1B4D8A7970FULL, 0x9D52269096C4D075ULL, 
            0x80CE27A403E58BEBULL, 0xC384229C1D3F2C80ULL, 0x600BED878355B7D2ULL, 0x8FAD00A33919448BULL, 
            0x221367640B648986ULL, 0x30F6E634B198EA4CULL, 0x6128B066668CC43AULL, 0x6B3B621EEF7F0613ULL, 
            0xA619227789B79D84ULL, 0x17734A85BEA11304ULL, 0x85D6B664567B7681ULL, 0xD99DB707A9EE25F4ULL, 
            0x952C7525028D5A60ULL, 0xD6366C3166463DFDULL, 0xD75EFDCEEC5749C2ULL, 0x4E5B2A82B1440D8CULL, 
            0x912D0BEC96AD9E0EULL, 0xEF0C8BDE7667AEA1ULL, 0x34D742DB49B92E39ULL, 0x21C253B82F100492ULL
        },
        {
            0xCAB6A0390A42DE01ULL, 0x6E755F503952DAC2ULL, 0x7C641332E232B52FULL, 0x1BBA575976BF71E5ULL, 
            0x953FA8EEA6E9ED21ULL, 0xCCD4266924FE4418ULL, 0x5DA87AC90F85CA01ULL, 0x1B41CE25A3644082ULL, 
            0xC01B40B1E459CCC1ULL, 0x8C337D26FBF00E2EULL, 0x1CD351AF3EDFA126ULL, 0x51DBD7330031CEA1ULL, 
            0xD2770FCD3A21BBE8ULL, 0x85FB3C18349FE6F9ULL, 0xA1F137FC642CD3D2ULL, 0xB6F3F1B3076FD029ULL, 
            0x63B108B67FA78596ULL, 0xD42B82E1FC6E695CULL, 0xF780E71B846AE7D8ULL, 0x852442B7EB7C36F3ULL, 
            0xB1C0BE4B0EDA2433ULL, 0x93C5B1C3D3C93189ULL, 0x6FF1E3EBB3EAEA16ULL, 0x639459114D981AB1ULL, 
            0xC72B74AB6079AFCCULL, 0x66E47FA643BA5E45ULL, 0x3B383CFC25EC2A8BULL, 0x14131BD4B7336747ULL, 
            0x74A366743FE0DF0BULL, 0xBB3E815C37B0E0AEULL, 0xCA70099932491E5AULL, 0x7EF93FCDF21392E9ULL
        },
        {
            0x06D3122C3731BA6CULL, 0x74D4D14E9164F731ULL, 0x16AB55D8D96DBA8EULL, 0x498922C3BB54C348ULL, 
            0xBB59A09852146BE6ULL, 0xCFC1E25C70345F2EULL, 0xFB80E9896E3CECFAULL, 0xF381C765C2D35775ULL, 
            0xB8F7D748FD9F927AULL, 0x41907658BA0D928CULL, 0x27BFAF3729249F33ULL, 0xA190E41B46FAF7EDULL, 
            0xA13976FB330AA93AULL, 0xB8507F917DC20352ULL, 0xA628C8F17610CCD0ULL, 0x1235D0883DF6BC29ULL, 
            0x90FEA8CAD3F0D038ULL, 0xB7DF730B8CCA3EF0ULL, 0xCA070676A82E37A9ULL, 0x964691AF8918877FULL, 
            0x9AD5AF19CB851BA3ULL, 0x5B5CC8AB845D7B90ULL, 0x99BFBF243A0B7F74ULL, 0xAB2833017CA3BA33ULL, 
            0x5FC55942A1B7370BULL, 0xDD053B3664A31010ULL, 0xA06D6DFDC30A2199ULL, 0xE7A3DF2D4B5A4FADULL, 
            0xD83954D4ED7940FAULL, 0x0314B27BE6B6E381ULL, 0x3C215AA67F047B51ULL, 0x429B4465C0406998ULL
        },
        {
            0x74FB8A17E99D99FAULL, 0x23F607907DFDAECDULL, 0x27FB1309D2D783E0ULL, 0xA8A28C3501965623ULL, 
            0x422339D231FFCE63ULL, 0x8FFE9B7D5EE3062BULL, 0x272933C7127FEEB7ULL, 0x6DB8A347A90A2774ULL, 
            0x1B3AACB07544E900ULL, 0x621A989325F3A410ULL, 0xCD267957AFAB9083ULL, 0xC57CAE8C1B62EA8DULL, 
            0xC951E3A81F141AA6ULL, 0x7316C9DB62883D35ULL, 0x325180FFEC48CBA7ULL, 0x15397F916120DC3FULL, 
            0x696DC0AE19918688ULL, 0xDD8CD878CCE3D02EULL, 0xCD4282B91EC78504ULL, 0xD62819A90687911BULL, 
            0x1BF03C384B1D5788ULL, 0xDE0433612DAC7DBEULL, 0xE91C9B23919F0A2AULL, 0x879931F96B1C3106ULL, 
            0xBB4EBA4B74690CB0ULL, 0xF6B277A039D2E1EAULL, 0x7EA6BABF6FC4888EULL, 0xD658A0058C9F5D10ULL, 
            0x3FFE8D67BEE5C9FDULL, 0xAF3B643DF4060AD4ULL, 0xF19EEE7BD6F51EE0ULL, 0x1936E9C3F74BB333ULL
        },
        {
            0x913566834A777859ULL, 0x0AAE99CB94BFF038ULL, 0x97C237DE28FFE40DULL, 0x3CEB82524EED4D2CULL, 
            0x24F3EA84271BD3E9ULL, 0x7D015FA4F8033BAEULL, 0xA57BFE219D8774C8ULL, 0x627DA4960085990BULL, 
            0x5A00C4EE35B13464ULL, 0xCF5A2758C78563C0ULL, 0x3338C8B22BE5DB07ULL, 0x9C683FD66DDE0710ULL, 
            0x3CECE749D0DBFCECULL, 0x9313BAD70E0AD40CULL, 0xCF0BE50953342881ULL, 0xCCF63AE70214EFDFULL, 
            0xAA9B5F19FD17421BULL, 0x410304688AEAE196ULL, 0x791F6EDE1B559B9BULL, 0x35BDF0FDBCA898C6ULL, 
            0xC2BB1A09B9A42699ULL, 0x8479362FE4C3D49DULL, 0x09F29BE8344F2135ULL, 0xC6B8F3409F11AD01ULL, 
            0xC61465F1C90027C3ULL, 0xEDAE3AF6DA471A58ULL, 0x78D42EDC336B4047ULL, 0x629B137BF92F32A3ULL, 
            0x3024D53D549EA7E1ULL, 0x5C6CDF0264DC8B99ULL, 0x0C485179D3BDD8BBULL, 0x74491D915E016960ULL
        },
        {
            0x0000FD8776337EF6ULL, 0xA2D3321B61F6C897ULL, 0x9440BEDA2B500FC3ULL, 0x3ADE75293D44DC71ULL, 
            0x1977EDF38F7FAE7FULL, 0xD7739A554556519CULL, 0x51602F813BD4B157ULL, 0xD7EE58EAA3C0CB5AULL, 
            0x634E590FC3A1F902ULL, 0x84714BB6D5A3AFB5ULL, 0x70DE49D7C2F3FAD6ULL, 0xC8A1822122FDFD79ULL, 
            0x8CF1474F705C7B6BULL, 0x96F8CD468637F49DULL, 0x795BC1A85917ACFCULL, 0xB982F5926E062066ULL, 
            0xF225C6824AFDFE64ULL, 0x46686F879D878468ULL, 0xE6AFE462888E8845ULL, 0x9A2D46F778C2218EULL, 
            0xC6F6B37CB7958D4BULL, 0x23BD229D1A20AE0FULL, 0x49355EC1989DCDB9ULL, 0xBFDBBF571522A951ULL, 
            0x63485ECF0B00A61EULL, 0xAE251ADDCB3D24ABULL, 0xC2F2BFC65E30DB82ULL, 0x40A4831DB380B899ULL, 
            0xD82AC4061A0A41F3ULL, 0x2A6F74C335B1A5C9ULL, 0x92E413C039BDD3C6ULL, 0x05013C9BD999601AULL
        }
    },
    {
        {
            0xC42D3DDA0EEA8C83ULL, 0x5C7A09A575FAFA14ULL, 0x173422EDA7FF5E6FULL, 0x445DCB859A1D97ACULL, 
            0x8FBEBC5D66198B07ULL, 0x92D6CF5F1C00C655ULL, 0x87512DE8A34A327DULL, 0x7FC2AF3821CDFF4EULL, 
            0xAEAEC67715BD7D49ULL, 0x452404BD253EF149ULL, 0xB3488B98C248DB70ULL, 0x5D90D8E58CB27BAFULL, 
            0xAA71EC661CCCF58AULL, 0x7C366D781CABEE01ULL, 0xC22F5F1B18779932ULL, 0xB56E08E9C2777C32ULL, 
            0xD318C220480B5847ULL, 0x45B49D93DA67721DULL, 0x5191BEFDB45C330BULL, 0x8AEE963AD084E6EBULL, 
            0xAFFE318BE74C782BULL, 0xAACF50D703048966ULL, 0x0B2DAC20A00EEAACULL, 0xDE1568D8ED733237ULL, 
            0xE379E5B7321BE60AULL, 0x1DCCE331CB57B050ULL, 0x85A75D832B87DBC8ULL, 0xF408C372C315B148ULL, 
            0x8066C9AC3477B3D4ULL, 0xD9BDBC12A743F68CULL, 0x3CAC83C9A7DB6D58ULL, 0x8EDE5BC97EDD24F5ULL
        },
        {
            0x8D11AEBFF72B6FFFULL, 0xE37908140CDD8A96ULL, 0x9110CD1814A49156ULL, 0x6A8FFE382C8F7E2EULL, 
            0xAA73E713EDC3B72CULL, 0x769EA2C09861A9CEULL, 0xD353CE97D5F3D371ULL, 0x957F26FD0BCEFC03ULL, 
            0x27754E7CEE5B2E3EULL, 0x1B5E9F6442AE4D49ULL, 0x370946795F1A9FB0ULL, 0xA9029AD5B1498776ULL, 
            0xFACC65890E0E6793ULL, 0xD195821434367808ULL, 0x9D11D95598BE9AAEULL, 0xA968ACF5FA4D275FULL, 
            0xAAEBFB86FB145F65ULL, 0x93B04344A7511010ULL, 0xFE09DE56BBB26061ULL, 0x6E01C432249E88F2ULL, 
            0xD594DD08D78E783EULL, 0x6A7E4DAAF5A184E8ULL, 0x8C9F72E9F477E579ULL, 0xF43165E1290F526DULL, 
            0x35747D2AD3E395ECULL, 0x5D98EDE02AD81987ULL, 0xD2A9798FAC558ABBULL, 0xD584A94FF937444BULL, 
            0x0E88A34CD91F284BULL, 0x28DCE28FE4B42109ULL, 0xD0701C2B22A1CE77ULL, 0x1BF3E70F8C519F5BULL
        },
        {
            0x1524ABA8E0BB6501ULL, 0x72BB0408D8E5FF69ULL, 0x31FE129996C9318AULL, 0x340880E565927D13ULL, 
            0x8333A0787157B8ABULL, 0xA405F57BA8D2D4FEULL, 0x1599DF338A3AF605ULL, 0x69DC4D3409E39A34ULL, 
            0x3F978044D6872189ULL, 0x7061DC5622E9F8EDULL, 0x9D85320ABAF22137ULL, 0xE437D3CA67D60AB0ULL, 
            0x7C7C25A461A0C8E7ULL, 0x5E908976CB55DA4FULL, 0x572F8C81B6E0DFE8ULL, 0xCDD8FF99F268BEBEULL, 
            0x399DF1894B80B8BCULL, 0x7A6EEADDD23AD34DULL, 0xBBC92E0D8962B1FDULL, 0xB49035DF72B4899BULL, 
            0x3FE46B4307D4F13CULL, 0xFC93C15FFF1AFB36ULL, 0x2BE414816C65CDAAULL, 0xD82A7E09CCA6005CULL, 
            0xF8C44835DA12A615ULL, 0xD9150C64AAF243F5ULL, 0xAE805F0E4FD3A356ULL, 0x2B67A01F01344623ULL, 
            0x69E9F68E93BB7DC2ULL, 0xA951BDA7DBAFF92AULL, 0x51A94F985A3BB35CULL, 0x9ACD25966153C62DULL
        },
        {
            0x13101C817AF5113BULL, 0xFFDE829F736F3668ULL, 0xD22FA92C815AC821ULL, 0xFE9C92A140CB4E6CULL, 
            0x190B5F50CA513AB5ULL, 0xA188EE09E3BA57ECULL, 0x637B14695A94CECAULL, 0x1CE596D13BA02B47ULL, 
            0xCF8913669E472205ULL, 0x0E50DCD392636925ULL, 0x70C5B3BE16CDA54FULL, 0xA3E56C3B82D0D62DULL, 
            0x8237919EFE0477E9ULL, 0x276CFA12CB08D219ULL, 0x78143FA962D92F29ULL, 0x9045048EC4DEFFF4ULL, 
            0x8E9103CDD2BE74FFULL, 0x9F408CDF1E4DF2ACULL, 0x117E1219CE76B611ULL, 0x6D1E49CA98BD8A64ULL, 
            0xDD70A8FD87CB78E0ULL, 0x02FF3DA8D5A5C32DULL, 0x3CD3D7B51584042DULL, 0x2F82787A53DD929BULL, 
            0xFD2D46CD6A9CF5FAULL, 0x34A0F02AA66322BEULL, 0xA39E9489D1AE78D1ULL, 0xA1120D5A895FF0FFULL, 
            0x1E16337E681F3D8BULL, 0xF0BE4E428B7B8A9EULL, 0xDF7C359D3BC60F24ULL, 0x16007C1B3B3CB0B8ULL
        },
        {
            0xFA33F7F731E1FBC3ULL, 0xDB1F6C4812D7F9ABULL, 0xAF736F841021A039ULL, 0x2CF1396913D5BFD5ULL, 
            0x7C5E308D34C712DEULL, 0x5F3C7DEBAFD77B39ULL, 0xDC437845E67EA568ULL, 0x39E11E6C0FD20D91ULL, 
            0x95A7497011F8F01CULL, 0x201A345F16140849ULL, 0x802A65D34B125D65ULL, 0xAC9ABDA4F18F61FCULL, 
            0x5837A6124ACDF3DEULL, 0x1079A0CC5E2B94EAULL, 0xBE46E6E8CC53818BULL, 0x32A161E74B4CC5D3ULL, 
            0x246FD6D75D9EA454ULL, 0xF16CF4867E4099E6ULL, 0xBB330AAA0D277C4EULL, 0xBFB3C49A4E508CF5ULL, 
            0x35F1413B1D39EE22ULL, 0xD6B02D77671DA06CULL, 0x6C8E945AF86AD63BULL, 0x9FF7E33D92571301ULL, 
            0x44DECEFC420C0BD8ULL, 0x1608EAAA445DF771ULL, 0xE279D7D7C5B4BA0AULL, 0x803716F6B70ECA13ULL, 
            0x9DA2DA02DFF32A90ULL, 0x5A5E508D4BE2BE1EULL, 0xB70D61EF8720D376ULL, 0x9F2640B313879D69ULL
        },
        {
            0x461F3679627894B1ULL, 0x21A6CA9A569B6233ULL, 0x718CDD6C2FF0B2B6ULL, 0x895E0C3DC8A078E9ULL, 
            0x01C55EAEE6BD6704ULL, 0x41200B9B2BF3EF48ULL, 0xA91982E2CF8F07EAULL, 0x8AA0F4B0C03067B9ULL, 
            0x96577ED1DF73DB0EULL, 0x2E83D5FE23FC591BULL, 0xE5FC49678B2F9FACULL, 0x9BB7A64D470A4B4CULL, 
            0xCFDB9ABD55B21BECULL, 0xA556869D09AABBBEULL, 0xC6CA54012A47832EULL, 0x6C63C9D34A747402ULL, 
            0x844131C900ECBE8BULL, 0x768D5107504D076FULL, 0xB1B488544E104E3CULL, 0xA750ECE9261E42BBULL, 
            0xB34893DA010C8149ULL, 0xDEE20DB8726B2025ULL, 0x3C147C7C0EEAD62BULL, 0xA5466715AC24D14BULL, 
            0xAD0AB94A16CE6DA5ULL, 0xD74A3EBC44F82553ULL, 0x131771E151DD7584ULL, 0xD5ADC85573D31C9BULL, 
            0xB9175FEBAC2661B8ULL, 0x710100DCE11DEF8DULL, 0xCB919EB48F1B6E8CULL, 0xAF3F08C18753D090ULL
        }
    },
    {
        {
            0xCE15576797B14001ULL, 0x498694E2E683A8E2ULL, 0x1A71B2133018DEB1ULL, 0x0F535F69B6D2DC14ULL, 
            0xE7B0D64BE3248907ULL, 0x4D6C55125FDD3A89ULL, 0x8E286A711ACD7B1DULL, 0xE36F812660106A51ULL, 
            0x03F77A8B2D9E920DULL, 0xE7702F1FD7F5851AULL, 0x73DEC7152CE6C019ULL, 0x75236C66FD5FE513ULL, 
            0x5884CCFB42B729BDULL, 0xC4464E45154C543FULL, 0x3E09E2B4366DDBF5ULL, 0xCA020C2CA80FB9A8ULL, 
            0x35DD98A222E07E6AULL, 0x63DE91107D4DBB34ULL, 0xE05805C408F8103FULL, 0x75B58A9F47A77E09ULL, 
            0x35C21D44D92B9A8CULL, 0xD6D2CDD8BE4D63AAULL, 0x33AD715BABEF3179ULL, 0x88726BE9AB412F76ULL, 
            0x2112EBB5B3693FA4ULL, 0x55575A3981EAB432ULL, 0xD74AADDF0983BF26ULL, 0x85B6F22EF4818BB0ULL, 
            0x94C832D63CD6B5F4ULL, 0x3423D8AAB73D01E1ULL, 0x83B1F350CBDBAB76ULL, 0xFD955D8160EE0DEDULL
        },
        {
            0x53AC8F60095926F1ULL, 0x500785724D69BA65ULL, 0x1DE2199DA275E355ULL, 0x94191BD564B7556CULL, 
            0x68890ECBBB9D0CB7ULL, 0x690FFA469CBC03DDULL, 0x97EB09DE3E6828F4ULL, 0xE4484AA1F23AFDEBULL, 
            0x76A152FB2C4F1518ULL, 0x1D4E9C125B16E870ULL, 0xC846A21BBDAEEF38ULL, 0xEA7CD2818CF0265CULL, 
            0xA6FEAEE2B63080F2ULL, 0x4CBECDF43EC38201ULL, 0x8C7D74F3C8E873D9ULL, 0xA91DF5D408BEEF4FULL, 
            0x710D980ADC73E98DULL, 0xCBB5A1CCE26937AFULL, 0x92B5EF86DB1DC6E8ULL, 0x1DD79EA10C5095C7ULL, 
            0xBBB2D1EAD9312A97ULL, 0x5A2EF79E3B74A9D6ULL, 0xCC5DC5A04F3189B0ULL, 0x76DD692FEF70115CULL, 
            0x041701740F3525C8ULL, 0xC9F16AED25395656ULL, 0xA34A305954246335ULL, 0x4245A7A75FA7CDBAULL, 
            0x289C99DDB17F2505ULL, 0xAB5C2EEF0B085347ULL, 0x4F2267652F06427EULL, 0x081FD3BDC7B26579ULL
        },
        {
            0xB459FE15C7EF7967ULL, 0x1913EB78B8B33AC2ULL, 0x7FDA0D34AAEAC529ULL, 0xC7594317B7044D25ULL, 
            0x2509BB8DD597287DULL, 0x2CF861D5879EAEA2ULL, 0x0E74D517C6D483AEULL, 0x387A5CDC1D549719ULL, 
            0x6DA9975C7E5D37A4ULL, 0xD8B2771F156DF8C6ULL, 0x9DAB769051EBE797ULL, 0x9492AD9D619A897DULL, 
            0x03883BED4CA8A97BULL, 0x7B396872C2DB4978ULL, 0xCAF3DB2D758596A9ULL, 0x8949A5747195C57AULL, 
            0x4975AF24E29E873AULL, 0x0A5E9BA9BD999E33ULL, 0xA0B4B421D74B4BB3ULL, 0x712B26DBB9C0623EULL, 
            0xFBD983ED9A2EF07BULL, 0x8E6E9DDE9CC5A1CAULL, 0x4A628E7E22FA9720ULL, 0x799C0432409FA098ULL, 
            0x6647DC3AE7E13A39ULL, 0x11FE814A23912750ULL, 0x790F515157E5CE5FULL, 0x227E7E78BC2FFDC2ULL, 
            0x472237902DC7C91AULL, 0x6D1CBB58BA3FB13FULL, 0xAD700829CFB90EE5ULL, 0xE2B8FF82597BBC7EULL
        },
        {
            0xA82E3F0797A3333AULL, 0xD58A6B1D405BCFB4ULL, 0x17FB84DBF3091DC1ULL, 0x10964A946D6E6CFEULL, 
            0x83DD370EFE73CBE2ULL, 0x5749E436FB8CFAB9ULL, 0x0F1483A7197BC547ULL, 0xA36BC68934C55495ULL, 
            0x693682111BD6E786ULL, 0x7B939EF75FB2E6E3ULL, 0xB83FF0E837DBFC22ULL, 0x723BC5E84696FADEULL, 
            0xE3B4508A5CD6EFEEULL, 0x69EC327E28E3FC69ULL, 0xE8951CB2F3FC76E1ULL, 0x842B2A785D8E99BEULL, 
            0x64504B7643EF112EULL, 0x74E2C3886DBCB6E3ULL, 0x4756CD48E0252CBFULL, 0xE545DD9818E9A731ULL, 
            0x312051FEF2B76F66ULL, 0x4808CABC88CB81D1ULL, 0xB79259A0A1924722ULL, 0x7C1771B1B76BB20DULL, 
            0xA93D1E3962E3E0AFULL, 0xD3E53435E27A5C43ULL, 0x4090CCDEED002FF3ULL, 0x74D5E903E7BEA333ULL, 
            0x8E8BC020542AC27FULL, 0x41265B611E522D21ULL, 0xB5A0D181662BE41CULL, 0x8245065C4E968719ULL
        },
        {
            0xE3D5F29EF945E62CULL, 0x2CE47023889981CEULL, 0x4C6A5E202934994BULL, 0xF7535F4D0A316F54ULL, 
            0xB6AF74C2BE0A5826ULL, 0x1B301B8BC03ECB86ULL, 0x54B2AC079ADF7B05ULL, 0xF620B07962F7ACE4ULL, 
            0x75F771B940F97642ULL, 0x5F99D580AEFB5CBBULL, 0x1B52473155E36128ULL, 0x912EC165B2D7E590ULL, 
            0x82132B528EE3240EULL, 0x44F15AB958EAEDFFULL, 0xE615F7B45F1500CFULL, 0x2673A610A8DBAB1DULL, 
            0x9C0340AB87D4E86BULL, 0x8A12B46783D994BFULL, 0x21A74D95E996A88AULL, 0x2B885E98679198D9ULL, 
            0xE81B03A2D4BB6AA7ULL, 0x7327F516146E8831ULL, 0x0B2935BC71FCE887ULL, 0x194C37EDD98002A6ULL, 
            0x0B4A817B62FCFAA0ULL, 0x635FD3D283E9B871ULL, 0xD0A9FC20A6559107ULL, 0x327B6C257CAEF49DULL, 
            0x7B75F102F85C3537ULL, 0x929A788D72B73758ULL, 0x2830EA58D1E73E7EULL, 0x3CFBEEE866E998D9ULL
        },
        {
            0x81CB16634E047DD3ULL, 0xA10B9280BBA51D1CULL, 0x503DB31451890A75ULL, 0x7BB6A246C9983AEFULL, 
            0x083253E17CB93C63ULL, 0xED078367E943B763ULL, 0x7C0DD37EB941E8C5ULL, 0xBBAF11A92CE490F0ULL, 
            0x780262C928FE64CCULL, 0x097EA1FE4FD71BD1ULL, 0xECEE70C7E4E8D82CULL, 0xEEFBB8181C1CFF3EULL, 
            0x3F89A9EDE2BFF95DULL, 0x8A8C620A16385F92ULL, 0xB816D1923E85C2D1ULL, 0x05C2566861F758E5ULL, 
            0xAF52EF445B92A3A1ULL, 0xC318E1FE3E33C19BULL, 0x69CA54558075DCCCULL, 0xA7363C01A4B3ED0EULL, 
            0x6E61AACCAC3A3859ULL, 0xA6958F7C02EA426EULL, 0x989EA9C91591B7B9ULL, 0x40AA8E7CB3FB7D81ULL, 
            0x01BD33403B08E981ULL, 0xE7FF15EC74150008ULL, 0x3E4B550ECB856F04ULL, 0x34BE021336D42450ULL, 
            0xF012571F52B008B9ULL, 0x4AE68DA2FC7C4DC3ULL, 0x27DC86565CAE68E5ULL, 0x74C495F9912EEF0FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kKeySpawnBConstants = {
    0x6FC5DF6D32BFDE0DULL,
    0x1416A1208C2A85CAULL,
    0x4CC5B5E4EE33E4BCULL,
    0x6FC5DF6D32BFDE0DULL,
    0x1416A1208C2A85CAULL,
    0x4CC5B5E4EE33E4BCULL,
    0x3A611FC57CC4BF3AULL,
    0xABA8D2FD7703EE5EULL,
    0xD8,
    0x6B,
    0x68,
    0xD6,
    0x9B,
    0xE4,
    0x6C,
    0x12
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kSeedSalts = {
    {
        {
            0xD1CD12EF6CCC57BCULL, 0x241F08B852DD8786ULL, 0x8B6447A3DADAB0BCULL, 0xBE751F1B0165A237ULL, 
            0xD27F5D3DB972A97AULL, 0x38033202D3B2B7D7ULL, 0x7649C65BAE5DCB56ULL, 0x7BB12A9628F25830ULL, 
            0x89E9D00CF52D0203ULL, 0x6D9A05CC0D086B6AULL, 0xD3158AA59D337D77ULL, 0x60D1A14AB71C081BULL, 
            0x90E0D798A7D699ECULL, 0x0AA6B7CCC195AE4CULL, 0x0DFD5038E14FA670ULL, 0xF4609F8C538A931BULL, 
            0xB2181C08F36252F7ULL, 0xB37CE5E0821BAA67ULL, 0x7B12307D8C0CA976ULL, 0x902D8601272C71A6ULL, 
            0x1FCC570F9EC6E0E6ULL, 0xB4FBCC671AA8E7AFULL, 0x9CEF9E84DCAF4339ULL, 0x0595F62F6C0D7D5CULL, 
            0x30B4318C048BC2A8ULL, 0xED3F88061FA10043ULL, 0x7F5BDC9805275492ULL, 0x5FFF9D816E956ABEULL, 
            0x61A78BCF44AD7E05ULL, 0x58329ABDF302EB98ULL, 0xDE774FAFBABF0171ULL, 0xBBD753C548C7090AULL
        },
        {
            0xE910C2ADCCEAE418ULL, 0xA7D5C1ABC4C9D25AULL, 0x45CF8B55150C8D3DULL, 0x9A44775D8AD703E1ULL, 
            0x8D7C4EC47780B600ULL, 0x0966050ECB9D0789ULL, 0x618461E7FE3D3F76ULL, 0xA58E6770F47E2DF9ULL, 
            0xC243160B1F900228ULL, 0xA6EE08C6AF46FEE8ULL, 0x601F5D9528C229CBULL, 0x294FA491EBBDC201ULL, 
            0x30859E2112A5E871ULL, 0x015D8958E8BC518CULL, 0xB689F8EC93DD61A6ULL, 0xBF076091DEB92005ULL, 
            0x104A60F144E726CDULL, 0x1479DD68B61A3783ULL, 0x9C1458999F1BEA3BULL, 0x5BA574F4AF10E2DAULL, 
            0xD8CA7B7E88BDE414ULL, 0xFDCA1948165E5ED1ULL, 0x77CC69C16B70ED10ULL, 0xA6F25FD894FC73B3ULL, 
            0x30FE7EB4A3D75EF5ULL, 0xE23E41B0A9BCF2DFULL, 0x42D9FC6EB12C62BAULL, 0xA347A2614236002AULL, 
            0x5B4168093DF09F3AULL, 0x4BD0669407C72D10ULL, 0x5C16C0829645B1F3ULL, 0xB1728C9BFF9BB8ABULL
        },
        {
            0xA36954B9C34A3819ULL, 0x379411E5E7353CFDULL, 0x2E08AA1F764FA1A5ULL, 0x20F3E789E3A5B738ULL, 
            0xDCFA4DE35A12B8BBULL, 0xBBAE2574F30B37C3ULL, 0x017AA84D3E6BED02ULL, 0x0052CAD069089420ULL, 
            0x11BEE5C4D76BB83BULL, 0x3E4821EC0AAAFE6AULL, 0xE0CDAC6598F6C27CULL, 0xCAAB502DA6462E4AULL, 
            0x1C7C7B413886CC44ULL, 0xAD2330FAB3FF4FA4ULL, 0xEFB953618B1D4903ULL, 0x1E4473D3C04F546FULL, 
            0xB37D3B107CF0D8A5ULL, 0x35D952AAD0D43D7CULL, 0x6CB42BF79AA81ECBULL, 0x895FE3C149F81122ULL, 
            0x240A1AEF466E3CEDULL, 0x721F26D9202C0335ULL, 0x10F294A202A8F8E2ULL, 0xF9A87B1E89EC2ACAULL, 
            0xE6642F1895F70502ULL, 0x975D9A494C783218ULL, 0xD9A5785C0D7BEA09ULL, 0xE2FA8B8E4DB16166ULL, 
            0xFB8E87D58EDCB6D9ULL, 0x446D8E5F9E0D137BULL, 0x2F25BAE2C3C487ACULL, 0xADC4DF814605EC88ULL
        },
        {
            0xC0469D8D4688A97BULL, 0x754225DE982121C8ULL, 0xA9F236D368293137ULL, 0xC0454CAE73B8A9DCULL, 
            0x8E54444F2C5F4FCAULL, 0x1C7D7B1CC3F7955EULL, 0xAD5DCA89B1B968ABULL, 0x16CB4058E327223AULL, 
            0x10DB60D3C1F0D078ULL, 0xCF12CEE34E48F0E4ULL, 0xFC37E4A1A75AFABDULL, 0x16B4126330C6791CULL, 
            0x205673DDA5FFA89EULL, 0x9A328EA4F9AECDACULL, 0xCF56CB13008FD98EULL, 0x5FE82E1B5F2B3DFCULL, 
            0x5B1518905E1171C3ULL, 0x8C92A8B7B662F1A0ULL, 0x67380738499CF78EULL, 0xC4E61002A5F355E3ULL, 
            0x7166C9DEBD01F297ULL, 0x4ED497138D04B4A4ULL, 0x422CA642F9EB37A6ULL, 0x15E379E1C4B51F0BULL, 
            0x23B2D72B5946CA35ULL, 0xD16B69F28EE4CE25ULL, 0xAC493AED6B58360FULL, 0xCCED7858C1C1BC5EULL, 
            0x4FE6D355A0A4629BULL, 0x448FED64752E8D42ULL, 0xB8E80823AED6BFC2ULL, 0x2C31457E05FE9828ULL
        },
        {
            0x3C13470C55924891ULL, 0x1EB5DF3171E80442ULL, 0xC9BAD244E1BF5CE6ULL, 0x4D0D981AA32369A0ULL, 
            0xD676A435C0544864ULL, 0xFFB83EC16C52179BULL, 0x0F8E4BA3F5C2B9BFULL, 0x4E9C7B03F68533E5ULL, 
            0x309D16D39598A075ULL, 0xA9DD3506C4F77F07ULL, 0x46F2406B3F0069CEULL, 0x22C52C010D22854AULL, 
            0x319BA3CEBCC99394ULL, 0xF2A9716DF7511156ULL, 0xA18E5402B074AF7BULL, 0x2FA11BBC13A041E7ULL, 
            0x38FF9088BBB746E6ULL, 0x17258382BD18BB0EULL, 0x2907ADA66762186EULL, 0x324115059FEBDF81ULL, 
            0x444187E4B2E820FDULL, 0x64C0FE1639DC8DFDULL, 0x4E7BC19BB86EED8CULL, 0x979E6F048787A3FAULL, 
            0x3758269A5AE12B77ULL, 0x21660152AA218641ULL, 0x8186A6328D6355A2ULL, 0xB695CE1B1F7E8E2FULL, 
            0x53BB1BB4E941B7FDULL, 0x43EF1B168EE57E9CULL, 0x350A3717B784F911ULL, 0xEBF3DB8A57A3CE67ULL
        },
        {
            0xF7742506B9EC8F75ULL, 0x900AB30DD68837FBULL, 0xF7C16D1F78C07358ULL, 0x04E37595A4DF44CDULL, 
            0x6AF365174BC1DD14ULL, 0x961D8B0BED1D1605ULL, 0x49D4168F6C0C57B5ULL, 0xFB19253B2CE3EF8BULL, 
            0xF5CD157F963CE33AULL, 0xB5943D071AE181F9ULL, 0x47882D6466AB3C99ULL, 0xC71C1039EA1D53ADULL, 
            0x61236843CA2C30D3ULL, 0xBC59B3C763368198ULL, 0x690C7AA489C3F0C1ULL, 0x9C4B6151A7763FC4ULL, 
            0x276C72A3B054652EULL, 0x68568C25826F6A9EULL, 0x5DC3A2D031D981D4ULL, 0x23F1B43D5DE1940AULL, 
            0x564FC1B73EF8D226ULL, 0xE14A8623FE9602FBULL, 0xDFCED563FAE8B0D6ULL, 0x9A39490B07A86E93ULL, 
            0xB48D9977965180F0ULL, 0xD6E49D678C306A5FULL, 0xA14EB153AC653488ULL, 0xC9B3C48E3729CF76ULL, 
            0x39661E0CD03EDC87ULL, 0xC45422B40076DBEDULL, 0x3D767C6761ED7308ULL, 0x8BA23D278D5C0E40ULL
        }
    },
    {
        {
            0xEEA0D01FFAF28BD8ULL, 0xFFEAA2ED7D287851ULL, 0x6DC7072525006144ULL, 0x9A66DE9CF38520B4ULL, 
            0x48ED85AB5A966D6CULL, 0xC04EF39402A26BFCULL, 0xDAD3BB6CDA94EF09ULL, 0x20329B667AA712A4ULL, 
            0xCCB716D40D480D57ULL, 0x0EA5DA342E837375ULL, 0x0FA0A1A01FC2A7CBULL, 0x2D1ABB5C9C4B7CACULL, 
            0xA830C0D6A329391DULL, 0xAE72AEFA06CF82F5ULL, 0xF1549BA73560F9D7ULL, 0xA38BFBC505BC36DBULL, 
            0x7A97B2AAE80E09A4ULL, 0x33E65FDC68F69045ULL, 0x4856436F281F7BC6ULL, 0x497C35C7A22B94ADULL, 
            0x77054A16057F8F9AULL, 0xF008F687F0B472A4ULL, 0x1120FB78094EC033ULL, 0x35EC3EBBA2EEF12FULL, 
            0xA450005184EA4005ULL, 0x4B12CBD175FCFF08ULL, 0x62E8744896DACCE0ULL, 0xEA868E57DC886A76ULL, 
            0x11C2DDBEB5C70EFDULL, 0x8EC10E90FA57891EULL, 0xDE4F8DD99D343415ULL, 0xDEC85989E9D35F0DULL
        },
        {
            0x0578C551B1C8919EULL, 0xE3C4007245B2DC50ULL, 0xCF916FC4F95BAA22ULL, 0x5C5F03A139616AA9ULL, 
            0x9C612996FEB1BD97ULL, 0xEF8B8C49467C8624ULL, 0x365D91290B166B26ULL, 0xD7756466687BA8F3ULL, 
            0x43119270C6282689ULL, 0x6B131523DD939B0DULL, 0x957DB3624D20761CULL, 0x67DDF9C2B83D4044ULL, 
            0x10A605A3948DFD6AULL, 0xC89EB5502B61EB8BULL, 0x042F30F4B1A7A62CULL, 0xD6CA96578BD2521BULL, 
            0x341F794A106CD7EBULL, 0x356E1548B2DAAA57ULL, 0x71091F16B857A64CULL, 0x5419508717E17069ULL, 
            0x3CFDE8ACA2A4ACCAULL, 0xDBD24687E042DAAFULL, 0xFA2D163E407C2EBEULL, 0xB903B8AFAC87C6C8ULL, 
            0x8974F38ADEC7A1FDULL, 0x7BB58B3A0E4DC908ULL, 0x4954D7121F1BC60AULL, 0x150BFC3BF610BC01ULL, 
            0xD68C84CEBE828376ULL, 0x76416BD333B01FB5ULL, 0x292FDE0913AAC014ULL, 0x960A4C75422D4CAFULL
        },
        {
            0x132A841717396DDBULL, 0x6B7C752B715A0F43ULL, 0x32D90F646109D02FULL, 0x85F45799391A0685ULL, 
            0x6AFEB879E61687E8ULL, 0xCE497B0B29211DDBULL, 0x8B32BAA5CFFCF327ULL, 0x597ADA99AE79E24FULL, 
            0x41A9ECCEA44841FAULL, 0xF286D90451E0AF80ULL, 0xEE47371248620EB5ULL, 0x3DDF6021F1661D2FULL, 
            0x2DAA40C17C591E43ULL, 0x021077C8446D574FULL, 0x6EED74B6E99F73EDULL, 0x3984345F78C2D25DULL, 
            0x2DD0DCC347236F87ULL, 0x9BAE2CBA34A75622ULL, 0x8705DBB257E7F6CCULL, 0x239FA5A336B146DCULL, 
            0xD64D083F933CBB9CULL, 0xE453ED4D35125CEDULL, 0x01295839DD40639BULL, 0xCF345D6EB95B6858ULL, 
            0x9C2D5761905BF272ULL, 0x97A3DEF25C592A3FULL, 0xF6A74AE6399AD262ULL, 0x02BF779ECA9C9215ULL, 
            0xB5FE97308901E435ULL, 0xB838BABE0592E059ULL, 0x797B933AFE8EB37CULL, 0x5FB299B39B14CB7BULL
        },
        {
            0xCA3567B65367DEB3ULL, 0x6C0A390ED6F20E95ULL, 0x5AC775A24FF90C40ULL, 0xF3CE6F84D335FA20ULL, 
            0x80C07F4049B397FCULL, 0xF9CA78181A7F41CAULL, 0x737476FA3B22194CULL, 0x6EA17AD4FAD241DFULL, 
            0xDD4003A188E857D4ULL, 0x0B188CC5E742D292ULL, 0xCF365FB105FDC625ULL, 0x6100025162472771ULL, 
            0x20A6336B9461FE35ULL, 0xEAA1A95FDA631162ULL, 0x908D494198B64979ULL, 0x7F5B50DA494793ADULL, 
            0x0A8454F89F7FAC49ULL, 0x6B354076463FF778ULL, 0xB43595A32EF3539CULL, 0x70F0890ADEDC601BULL, 
            0xA6A73F80A535E8DDULL, 0x17181B8495CCDCBCULL, 0xB61CFB458EA3861BULL, 0xBDA6D9BF9B2A6F5DULL, 
            0x7F889A94A4727B50ULL, 0xB9ABCEAA7D6B9901ULL, 0x05D996C6DF37D4C9ULL, 0x4A79821F60D78457ULL, 
            0x4E3178D32AE8A1AFULL, 0x008075B08C814F84ULL, 0x9367E9FA3D8AB4ACULL, 0xEA8FE537813B0010ULL
        },
        {
            0x650BB9FDC03DB4E0ULL, 0xDBB4860ECED2DAEEULL, 0x41D90D12C955F588ULL, 0x52FED612069B29ADULL, 
            0xEEB22A31D795F6B8ULL, 0x1C37501096A1E5ACULL, 0x4D60A7B7BBA8A76EULL, 0x4B654CB10FD26335ULL, 
            0x5148ABF0EC8D93E6ULL, 0x050CBC6CA8A3ECC5ULL, 0xD63336893630C947ULL, 0x83E79DFA204E7979ULL, 
            0xC573519D62B3C479ULL, 0x02B4E59957A884C6ULL, 0xFEBBCE0939AFF680ULL, 0x6A2DC188BF06A581ULL, 
            0x689E98006ACEE8E9ULL, 0xB3CEDC8B4637E7C9ULL, 0x61D6699314FDC2EEULL, 0x05D28F4E925183F5ULL, 
            0xAD6A8FD121C2B3CCULL, 0x86C527D7CA2A39C3ULL, 0xCC445326BBB07C0AULL, 0x1513CE65AF11B417ULL, 
            0xD58C83813A735291ULL, 0xC65F6AD323B63056ULL, 0x6E6B048B01FEB246ULL, 0xF17B210F1635E774ULL, 
            0xC6F4113E297BEE50ULL, 0xEEE5AEF455B26D84ULL, 0x1718CF1E7D849B6EULL, 0x45577F06B23C011EULL
        },
        {
            0xA068BE93BC416E89ULL, 0x1A9E6196910A4081ULL, 0xD258EFFE18D3985AULL, 0xA452970D7ED848F8ULL, 
            0x19138B211AF0B6BDULL, 0xB0EB0E39A3AEE5DAULL, 0x66134CD41E1D8AFEULL, 0x748DBC071BBE56BAULL, 
            0x5614D2A649657793ULL, 0x422E349BCDC2D36CULL, 0x33DAC80471A3BE79ULL, 0x45951371176C7A3FULL, 
            0x351C9578C6C144FBULL, 0xB38B0FBF6FF2DB26ULL, 0x8DBA93B4F503FE8CULL, 0x42B7BE83AB4C2196ULL, 
            0x56B00481856E89C7ULL, 0x1B0C7C016FEF7B09ULL, 0xF8283FF7AB6765EAULL, 0x436642C179D7B838ULL, 
            0x3606C252D507F46AULL, 0x27C346CA2E62DF61ULL, 0xD0A451A11B5409C3ULL, 0x4753FEB10BF57FE4ULL, 
            0x57F49E11A17A576EULL, 0xFA893CDCEB8C56BEULL, 0x5ED8F3451F11DA22ULL, 0xDEACBA71622B3341ULL, 
            0x98C4E00F8727DE14ULL, 0x892F1089BD1390F6ULL, 0x4D7DF9FC3E874785ULL, 0xCC9E0BA18FF3EDA2ULL
        }
    },
    {
        {
            0x35857C686FA19299ULL, 0x8ED3A36D59776AF3ULL, 0x656697CF3C427621ULL, 0x12C1065B5440D762ULL, 
            0x255705C9396C772CULL, 0x8A227DFD2DC531C3ULL, 0xFE11E42E6BF8CBB1ULL, 0x0D7F8015BCC841D3ULL, 
            0x370D1905CC1CDEDAULL, 0x6333B3D1E7D4E2D1ULL, 0x44A353D07C077110ULL, 0xA8525CB4BEC6E24EULL, 
            0x405424F866EF0652ULL, 0x0419E789808DEC8FULL, 0x5D04575C1BEAE4D1ULL, 0x91EA23CF1246661EULL, 
            0xFEE28113A7DA2F2FULL, 0x84F3E9FBE8D81210ULL, 0x4F73686DC02872CCULL, 0xFC764C2EE00764EEULL, 
            0xEF73B7A2E48754D2ULL, 0xB8E9FAD9E1DF6BF6ULL, 0xF510D5DA8B234CD7ULL, 0xAFB13AA07DE9DDF2ULL, 
            0xCFF6B4FD8E6902AEULL, 0xAEC9FE26A8C0581AULL, 0x4B832AC23072073EULL, 0xDC99B926C780769BULL, 
            0xB081489EDC1D966BULL, 0x2F513591D3335EFFULL, 0x6FCEDD065D6C8F3BULL, 0xCC208F04A7C33E3AULL
        },
        {
            0x0EE533541037E676ULL, 0xE6F6907D28DC6A48ULL, 0xB3342CECBFE00AE6ULL, 0x14FCE1F2E958E263ULL, 
            0xFBB5F9489A4DA24FULL, 0x3CD93B0D8618BAD6ULL, 0xCFC8B2212571CA80ULL, 0x3A7B3EF9CD308C9AULL, 
            0x23DD39921E755640ULL, 0x16968A0571B1D46FULL, 0xE5576947A30295A7ULL, 0xAA7FA80C76C56519ULL, 
            0x2104A6F2B9D1CDA0ULL, 0xD3E0FCE7C75D615EULL, 0x839DC2CBACE4365CULL, 0xC7DC0A7DDFD49872ULL, 
            0x6FA18F2E4B02C060ULL, 0x28167EB40DF3A9C8ULL, 0xFEEC6F8EBFB92117ULL, 0x2C902FA2453656B6ULL, 
            0x5E628C79AFEDCCA2ULL, 0xC39894FA20161874ULL, 0xF58B7AC1031DB599ULL, 0x897FA809D5A1CB22ULL, 
            0x6B39A01CE64E5D49ULL, 0xB6E05F35EC1D87BAULL, 0x8B5F4757B1B0F03EULL, 0x1403DD9C84DB27EAULL, 
            0x9E5ACC0B15A4FA2CULL, 0x0108680DD837D454ULL, 0xCCAB203A60DBDA47ULL, 0x6D0DF18492AA98E7ULL
        },
        {
            0x7432092DBF5F7C6DULL, 0x8E38D29C10DDF740ULL, 0x304AB1F6CD2D0BBBULL, 0x8C09C2907B7DFDDCULL, 
            0x61F435476D85F8A8ULL, 0x6FD1D7BD44859F3AULL, 0x5293630A55C03B55ULL, 0x2D6280F2A1E4A2E4ULL, 
            0xDD5BBC04AA8D9696ULL, 0x5B4AF9040F4A57E6ULL, 0x486931F8E06D8DCDULL, 0xF0D7C17E764BA8F1ULL, 
            0x2E5734C03043767CULL, 0xBC82377F0D1725FFULL, 0xBF7EC0B6F294DABDULL, 0x3F39F80489B58F70ULL, 
            0xF954A90AD699EDBCULL, 0x04594911433A8B5BULL, 0x6F1A83CE971AC1CEULL, 0x00D2B1020B6CBEE3ULL, 
            0xE49434695B98F6E4ULL, 0xE2DE5775D6322161ULL, 0x249C4E98B226FE77ULL, 0x99931D06CE940D1DULL, 
            0x895391F1819E1CC7ULL, 0xA7BDB307DF8F5B77ULL, 0xB67DCAA345EF45FFULL, 0x2C280831408C6CF9ULL, 
            0x5809CD5BDD5272E0ULL, 0xF127FEC46ED9D035ULL, 0x42FE0A7E6341C6E8ULL, 0xA254B2B9ECA168FEULL
        },
        {
            0x0632643F0BED7DD2ULL, 0x4F00DC746B6AC036ULL, 0xBC376ED60841DF63ULL, 0x77075D53CDC59052ULL, 
            0x4E633DA8C44B0B93ULL, 0xE21A7734906373D5ULL, 0x4B62E9F5CC4E4F47ULL, 0xB5E93D2E7CA0D995ULL, 
            0x90F71B8B566DF55EULL, 0xE7C877965C74E2E4ULL, 0xBE268CE8AD8ACC79ULL, 0xEA9272B9BFDFA19DULL, 
            0x38D9071AB6BD77EDULL, 0x55454C911143CB7DULL, 0x2C688C63C391F15CULL, 0x61899F03BBCB6E1FULL, 
            0xD03C9A9FA4B3C8DAULL, 0x80F38EB90EF2679FULL, 0x8FFB7B8243A49D0DULL, 0xB9ED2DEC6BB607DDULL, 
            0xA69882C342FC09B6ULL, 0x88125FA505900BFDULL, 0xE15305FE1146851FULL, 0x5B21366F80C78434ULL, 
            0x045FF543FDEC946AULL, 0x666A443BA022DA84ULL, 0x9EC3097EE1E7AFE5ULL, 0x265326D76F640C6AULL, 
            0x01383C5732504484ULL, 0x72CEEF4EA5614BBEULL, 0x23EC10CA0814EEEBULL, 0xB3A2BA953AB0BAB8ULL
        },
        {
            0xB13D7512AA6008F8ULL, 0x1F46F15C3D17827BULL, 0xEB923D82257D9F4BULL, 0x47B32178A3D4F5ADULL, 
            0x4E428B8B90E23179ULL, 0x60D65450F8080565ULL, 0x68A41B528C812B06ULL, 0x6FC106BB97645467ULL, 
            0x4235B8DC3DC3D6E5ULL, 0xDF79C5401C80AF2FULL, 0x7C4A49B02B1877A0ULL, 0x0990E9444C8D1735ULL, 
            0x1AC772D8F2B395F3ULL, 0x704D011E2ECF6321ULL, 0xF8AAA7E344A1703FULL, 0x12D87B49BA0F7086ULL, 
            0xFE8D587900EE9B88ULL, 0xDA711F27FA2180CCULL, 0x7DFCD0133BF52632ULL, 0xFDEC401F561BD3A0ULL, 
            0x3A632038BB627816ULL, 0x1E653E2FBB38E9FBULL, 0x3BF7A6F8FAAEBA77ULL, 0x2458BEA4DB23A0DBULL, 
            0x386348FA8FD55A6DULL, 0xE091DD32D8DE298FULL, 0x385840B6668F996CULL, 0x08AC55D8E58AEC35ULL, 
            0x4E95694D3984FA2DULL, 0xC4116FF2759BDAA6ULL, 0x03BD26A10E8E299EULL, 0x7B091411B588199EULL
        },
        {
            0x8AA31AAA43372EFEULL, 0x2A023D8D8528AC64ULL, 0x8F08A588A2239139ULL, 0xED45E6FE8CD351CEULL, 
            0x9FD4E191EFF0AE9DULL, 0x68F21999F7DDB592ULL, 0xCFBEF49AAEF0626AULL, 0xFA089984D13AB14DULL, 
            0x004AABFE0F9915E7ULL, 0x3843BBA2FE2641A6ULL, 0x33EC3B6987390217ULL, 0x89CAAC3F5CAA15FBULL, 
            0xE7A3E6BE22AA319AULL, 0x0EE03127F1AB2C6FULL, 0x5A5B4E2A67D87F48ULL, 0xA76046EB090D21FCULL, 
            0x82E87DB61150C99EULL, 0x548C23E6D0D4B685ULL, 0xE133A9CFF69C3485ULL, 0x2C15189EFC1082D6ULL, 
            0x30404D0A7B3D954EULL, 0xF22347354970F577ULL, 0x5C7B1A8765231654ULL, 0x4BF39CF81179FF26ULL, 
            0xD017B2F410CDBA93ULL, 0x4B7B45313264E23DULL, 0xA98C84E838604E2EULL, 0x97DC9414AC7B4A2DULL, 
            0x692C7A8ADD57D478ULL, 0x4378B0A074027989ULL, 0x459A311C7B2B2C60ULL, 0x18C59C4EE09D99CCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kSeedConstants = {
    0x76FA15EB8095D5F7ULL,
    0x854635AE497E8A47ULL,
    0x0F21F20806E8D1C0ULL,
    0x76FA15EB8095D5F7ULL,
    0x854635AE497E8A47ULL,
    0x0F21F20806E8D1C0ULL,
    0xF2A1F26C7032ED8CULL,
    0x2D2BA9931F8BD478ULL,
    0xB5,
    0xA8,
    0xDF,
    0xC0,
    0x1C,
    0xC1,
    0x6D,
    0xE9
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kTwistSalts = {
    {
        {
            0x86B9B54837E1B80EULL, 0x1FE932EE43E3D549ULL, 0xB5C0CEFEAA95E0DFULL, 0x16981BFF295913E9ULL, 
            0x509233B407EFAB41ULL, 0x1900A22DF6789F7FULL, 0xE363B0C06F55A3A7ULL, 0x5CA5EC6F202C9C35ULL, 
            0x797D133C0F8FB7A3ULL, 0x55CA14BEE822B19BULL, 0x3DA0114E6649704DULL, 0x2174515896A390B0ULL, 
            0x6EA054380D86E5F7ULL, 0x5B733C19960EAA62ULL, 0x4396141E24C14157ULL, 0x1C0584027E154299ULL, 
            0xD6D926146EAD5131ULL, 0x7A43D903F58B566AULL, 0x440AF57C8D1A6779ULL, 0xE55FD901FBCC1C11ULL, 
            0xF8344C4F5D8BB9C3ULL, 0x0A7970BB68B06141ULL, 0xF026F1AD05BEC0EEULL, 0x9D74979B75344362ULL, 
            0x131BBDB199016D1BULL, 0x7521AF270F92BDF9ULL, 0x3EFACE36816C1FD3ULL, 0x1EA185D90A14E032ULL, 
            0x9FBEE37B7533D3EFULL, 0xADFB201121EA98C0ULL, 0xC8618FB898DA239DULL, 0x75B4B950050CD700ULL
        },
        {
            0xFFE5312D72644F86ULL, 0xDDAF04C14BDC0B61ULL, 0x4B6F28F899AD9166ULL, 0x4B4F43238B6649DBULL, 
            0x5AAA18B5827D12C3ULL, 0x26B602D85784E446ULL, 0xC103F58D13D46175ULL, 0xF4EE343A80895CA2ULL, 
            0xF3C400DC00A2D9D5ULL, 0x10BB42A77ED9E733ULL, 0x7C44DADD54DFBB75ULL, 0xF98CC143476F01DBULL, 
            0xD9BCEF7FFC87B48FULL, 0xA513EDF0459137B3ULL, 0xD6F71C8DC69BAFC5ULL, 0x49F5E561E88723B0ULL, 
            0xF421A092CDBE5396ULL, 0x79C1E69E909AF2B9ULL, 0x2A1E6906971019BCULL, 0xFFABBCF4C90F8557ULL, 
            0xF0F7FD4812F98685ULL, 0xF3608493F90D0FCDULL, 0x705FA230FAD596EFULL, 0xA7D5DAFBA28B74B1ULL, 
            0xF3697621A29986A6ULL, 0xF09673FEB91B8B9AULL, 0x43E1A58E9ADAAAB0ULL, 0x16A3333A64C71F67ULL, 
            0x6EF3F3336CD70738ULL, 0x6A3FC88BCE5B7F34ULL, 0xDD7FABDB7C9FC750ULL, 0x48CEA4D745B2E240ULL
        },
        {
            0xD9ECB3F5FDC883F3ULL, 0x350BDA939C52AB95ULL, 0x8D308F030D6F6F29ULL, 0x38A07593ADBA7F78ULL, 
            0xC26CDA34E90C248CULL, 0x4A06A71F65F70A09ULL, 0x66A82521CDC14654ULL, 0x3BF69274C64BA03EULL, 
            0x797650D554571E3AULL, 0xAB7CAC291CD89E28ULL, 0xA56D742528206C07ULL, 0x46B014903A0FA17FULL, 
            0xF5B515A7A9D40320ULL, 0x0B4AEB555645C4FEULL, 0xC378D13DD8269962ULL, 0xF3D8932C216D3508ULL, 
            0x88CBF7F8FD721AFBULL, 0x556CD2995B207186ULL, 0x86EEEDFBFAAB3F97ULL, 0xF8741E7D500B99B2ULL, 
            0x48B763201E93B753ULL, 0x1F8DEBDAA3A74A02ULL, 0xE3D3739E4E1BDF74ULL, 0x5BE1BF7509C38C8AULL, 
            0x801201B5C0893E1FULL, 0xC762E39837ABC9BAULL, 0x4C603C9DF68A8E27ULL, 0x0955551E069B1A44ULL, 
            0x93EFB1C8FC93E173ULL, 0x500FDB5302843BDAULL, 0xCEB320EA0E42B909ULL, 0xB16C76206D2429D6ULL
        },
        {
            0xE38ABFCFA1EDAE5CULL, 0xBD60471713671C20ULL, 0xAC93E13330AC7E02ULL, 0xB5421FF8F359BB2DULL, 
            0x8F37FB363BEA17F1ULL, 0x516E42DB0BC10D7DULL, 0x816B1406E8443CC5ULL, 0xA912C7891A73416AULL, 
            0xA396E9D4B309623AULL, 0xF88D06007465908AULL, 0x696ED4AD1F1DF350ULL, 0x62A81593DF9F14C6ULL, 
            0x7C421102A590D466ULL, 0x4C59B86BDB4E0FBCULL, 0x0CC23FEE303AD41AULL, 0xB73BE375E634DDEBULL, 
            0x20BAC5BD9D49EE84ULL, 0xF8C290890B9BF069ULL, 0xD687D5CDBE4E1E58ULL, 0x2B847BE9B28BB5D3ULL, 
            0x1440BD374F0F0B86ULL, 0x4A3066E1BAA2DCB6ULL, 0x330CA84AC8BCB1D5ULL, 0x2C5A39DDBA537815ULL, 
            0x719010CFB07D49EFULL, 0x901F6A481D89004CULL, 0x59B119ADEF5B960EULL, 0xBCD7A9D20633F605ULL, 
            0x6EE81064D743C830ULL, 0x3FC173073F9EE289ULL, 0x867F62782CD8E4CEULL, 0x653910C66F62499FULL
        },
        {
            0x3F6B4E76339E2649ULL, 0xA75E6A3D8A67D7C9ULL, 0xC0E2C54EE976BBE2ULL, 0x60803E5998011E8AULL, 
            0xCC42B4A417EE13D7ULL, 0x2420B1322F7F857CULL, 0x9052A83D90EADF09ULL, 0x0B3595C10A95C868ULL, 
            0xF2A5BD04B692EADEULL, 0xF95DE4E1146AD103ULL, 0x6387AAB0210A5094ULL, 0xEF0176AAFA634487ULL, 
            0xA9EF5CB59E4DAAD2ULL, 0x01DCD377758B981BULL, 0xE0C3E81E18C23E17ULL, 0x9A802B08A3374178ULL, 
            0xF9D1A379EDD6BED3ULL, 0xAE872D93FE165ADDULL, 0xCDDB0D2B5619BC57ULL, 0x43AEC0C9014F095BULL, 
            0x2F91BAE28054920DULL, 0x95E8E284BD73CD18ULL, 0xC83490CA7607909DULL, 0x06A40049320FBA24ULL, 
            0x6F55726FA50007CAULL, 0x959E70E5E7F6D1F8ULL, 0x91B2A7E5C66D2D3EULL, 0x7105430A624853F6ULL, 
            0x854B350C57CB7297ULL, 0xC017D9C42DD78668ULL, 0xACC06C2772553F3AULL, 0xD1AAF7852B113524ULL
        },
        {
            0x774541E545D661BBULL, 0x12F5B4BD19185442ULL, 0x1A268D1830611EDEULL, 0x94A0343292837AECULL, 
            0x3B139A7556298AC2ULL, 0xFB015E1C175C235FULL, 0x943F455ABFB7A58FULL, 0x9B573EA8F58A2EE1ULL, 
            0x4E241AC12C32C46FULL, 0xAD0A47E4D64D83B9ULL, 0x4EB93F04879257FFULL, 0x9E735D1B672C9088ULL, 
            0x76CDA17A05ED0132ULL, 0xFC01A5CFCA782D79ULL, 0x309FD2CC861CDC43ULL, 0x090B8B5A764A834FULL, 
            0xAB12644E45187BF1ULL, 0xB8D5C8431273C31AULL, 0x43F19996EB31053FULL, 0x182C13A0D46B5BF5ULL, 
            0x08B7C6C51E39D680ULL, 0x2891FFF3B3A397ACULL, 0x813C318342C7BB43ULL, 0x25E015B5ACF95B14ULL, 
            0x6205AAC1CB1A0FCEULL, 0x2E6A3D381F7F02E7ULL, 0xA6127A3F90DC868CULL, 0xA05F0D4FD839362BULL, 
            0x4FDD17B408795FBCULL, 0x406C0C0D743622E8ULL, 0xBE4D1DB7D6694E12ULL, 0xC3384282F1C797EAULL
        }
    },
    {
        {
            0xC6E430E6653BFF68ULL, 0xAD06EDCB3FB65D82ULL, 0x2714A24039D22647ULL, 0xD8453D3539B75F77ULL, 
            0x82C745E073ED9031ULL, 0xCC19F81896AE9712ULL, 0x519EA033F4F5284FULL, 0xA34641523D69E31FULL, 
            0xFFDFB978594F4C0BULL, 0x457C86550556D6B9ULL, 0x2565EECCD5515EF2ULL, 0x815798B7842EED62ULL, 
            0x9DB4DCBA38D3895BULL, 0xC7F00D4691A0E9B9ULL, 0xDE369C792F5F3AA8ULL, 0x3F3D7BB5E548DF76ULL, 
            0x8609114B53E23575ULL, 0xCA0A95B5C37BAD3DULL, 0xDABB703F56E23B8EULL, 0x2EE1BD2E287671C2ULL, 
            0x62E612C0F9A048E3ULL, 0xA886712B0787948FULL, 0x15759C4682F145FFULL, 0x0AA18AAF6595C4D1ULL, 
            0xCAD039B3EBF6A87BULL, 0x3FA87A05A76E468CULL, 0xE9F7CD38E8B603E7ULL, 0x74A09C61D41D19A7ULL, 
            0x75001431B0A948C2ULL, 0x52BA4B8EB7DD83FBULL, 0x8FF8656CA7472662ULL, 0x4C66BDF3AA2185D5ULL
        },
        {
            0xF857C6A2519C83BEULL, 0x79705484FA4D9FA4ULL, 0x669FD679FBD55E89ULL, 0x3A201E5FA89D15E6ULL, 
            0xB9D3A30B8917B6DEULL, 0xCB49C447CF7C1A25ULL, 0xE8FEB2D5F2BB51D5ULL, 0x4855E29761EF6D79ULL, 
            0xB0680821373A124DULL, 0x37224A3020F3B649ULL, 0x38B7C9F488243186ULL, 0x9DD8E0E5F7B93565ULL, 
            0xD265F2E2943DB144ULL, 0xF3D5D74E4680AC51ULL, 0x3FA657757C016943ULL, 0x7F3B4803243C9329ULL, 
            0x7C1301306585C167ULL, 0xA55E623C1023BEE3ULL, 0xBE78B7463BEA2A56ULL, 0xA6066879732F857AULL, 
            0xC64BF2A1E91B08D1ULL, 0xAE7E3E03C89748FDULL, 0x1C63F03DB23E1F56ULL, 0x288D2607FF1AE0E6ULL, 
            0x09DC20A994072613ULL, 0x23CB41ACC10680A4ULL, 0x750A419D1AB89859ULL, 0x80880E4753B9E51FULL, 
            0xCEB2CC6D09EBF664ULL, 0xE785F2B811639C02ULL, 0x94A48BB5987524B3ULL, 0x2B11AD9A03068E02ULL
        },
        {
            0x5C25F7D1BFA357D1ULL, 0xD71E9BECA0AA46BDULL, 0x1478B815270AB2C1ULL, 0xDAD52A1B36AC6251ULL, 
            0x318C85699B5FC5E4ULL, 0xDC449DD49C0CA32BULL, 0xD316EFDBDEAB9E43ULL, 0x3ADBDD25FF19B1C9ULL, 
            0xA04938377392E242ULL, 0xC60BEF4574DAD3F0ULL, 0x41B8BA86369E2D21ULL, 0x5F75DEBABFD48E02ULL, 
            0x32E67F3DF86D1702ULL, 0xFFFC28B7F6BDA1B2ULL, 0xB1DFE9FC2CACB13BULL, 0x452DD01264A1DAC6ULL, 
            0x76B82A83CAE50EE8ULL, 0xBDD4B5B5E2DD46D0ULL, 0xE70EF828EEB377F0ULL, 0x172D1E8D1F164922ULL, 
            0x429FB245B6EA8AF5ULL, 0x02580A3679DE9060ULL, 0x51A641BF0B41745CULL, 0xCA0BDF723C9A0F30ULL, 
            0x654593AADD03199FULL, 0xF9C544C46E5A7DC4ULL, 0xBFFDB1A50D634A73ULL, 0xC045E039972890A4ULL, 
            0xBDBD84CAAD1AECB1ULL, 0xC2D9BD0521DEE77BULL, 0x7883320222B475FAULL, 0x182E07162AF27B14ULL
        },
        {
            0xEB4637CB8B340342ULL, 0x4FE587EB02957A62ULL, 0x9D771A020B811B25ULL, 0x43C5A54FB09C5776ULL, 
            0xA9FBD475E5DBF00DULL, 0x27F5A5186B1AA006ULL, 0xD1A6EA035E030A00ULL, 0x68A2BED92DA23819ULL, 
            0x2370245D34F4260FULL, 0x35CB954D2BB74865ULL, 0x7F1FDAE884C80044ULL, 0x27304623CD189C78ULL, 
            0xD28EA8C87F157C68ULL, 0x0F921945E0EF74A1ULL, 0xFA7BD3F8389E0DC1ULL, 0x378041C76A5126BDULL, 
            0x44C1203C9C68FE63ULL, 0x2A14FA4BC8EC2198ULL, 0x969315377AAF4DBCULL, 0x11CF9A2742E285F6ULL, 
            0x7A38AE25E6F8935EULL, 0x7305948695803D18ULL, 0x2CBA2D1244241FE8ULL, 0xF89816D6F6619742ULL, 
            0x415893F7C59C9D0FULL, 0x18EF659DBCAF1E26ULL, 0xF4944DC751B1B811ULL, 0x1F895AC341170EF1ULL, 
            0xBDED0C36FDC4E903ULL, 0xCE95CC8643E371F6ULL, 0x2E7B7F26C35AB667ULL, 0xCA5A0B2308AFF9F5ULL
        },
        {
            0xAE9F9A1C9E756E51ULL, 0xBC8387C4B3DD0322ULL, 0x4AC0390205B3FDA4ULL, 0xBD1FEA91C470F4E0ULL, 
            0x51657708C423B210ULL, 0xA2E64DEB313FB64EULL, 0x1548B76A45897143ULL, 0xD99A632B66628706ULL, 
            0x0CCE389CF2700722ULL, 0x3264467CC6FE9F22ULL, 0x3A658F445AC50979ULL, 0xCB8BCA5B47682086ULL, 
            0xAF19E3E5D4786C52ULL, 0x6AF66EBF82193538ULL, 0x4D46E5CB3C57E44DULL, 0x0F91824D79EAB565ULL, 
            0x1EF9BE841EFB1D49ULL, 0xD4420813984D0EEBULL, 0x7144CC1065D3499CULL, 0x4695979F490ADDDCULL, 
            0xAC77DD963D14B7A4ULL, 0xF8C78A4C6D3B48A3ULL, 0x00C962B5DACED00DULL, 0x7FB98C790951D6A7ULL, 
            0x896453C54C727B5FULL, 0x0FA6FC33567335A6ULL, 0x8B7C2347AB2FBF98ULL, 0xAE9B980BB334C1E7ULL, 
            0x8007D4037DC179ADULL, 0xD9626CFC0DCD6768ULL, 0x19B8C69A5A75E29AULL, 0xE16A16404CD4161EULL
        },
        {
            0x7847706FA7A9DEF2ULL, 0xDDCF7912BD7BA79AULL, 0x327AAB92DC1EDFD0ULL, 0xE4CFCEF4D584293FULL, 
            0xBF64E5EAD91A4C44ULL, 0xD14E7BD192630339ULL, 0x0A961C5A90312D74ULL, 0x5A12AFD317A848DAULL, 
            0x02D6C09E2DE71B86ULL, 0xC9322EF88104BECBULL, 0x95473CE8C0272EA2ULL, 0x2CE96D431452FF86ULL, 
            0x65581F5984E6470DULL, 0xD515C9EDAC2D2175ULL, 0x8B5472E94BDF3570ULL, 0xE022E804AEAC3FF0ULL, 
            0x0D4E19FCC4A87BC1ULL, 0xD639B605161954FCULL, 0x9012F979B75D5EDEULL, 0x010EA77846A1329BULL, 
            0x866EB8AC1CA04372ULL, 0x33AA8D9D9BBE3014ULL, 0xBFEC61E3696AA8F4ULL, 0xE03F0B1D2ECB8A6BULL, 
            0xC847CA720D2B35C3ULL, 0xD35E6B5EE72D27FAULL, 0x2845E997F067D158ULL, 0x88A53F685330402CULL, 
            0xAB106DC82D83B4B6ULL, 0xFEB61086A845E2A2ULL, 0x321812ED20B68423ULL, 0x4B0F818E15D740BBULL
        }
    },
    {
        {
            0x49670B324685292AULL, 0xC5F4C34580CFDEE0ULL, 0xE15D63844D94A068ULL, 0x21FECE14954AA3B4ULL, 
            0xDD8345843E540604ULL, 0x5DD3C1911C15633BULL, 0xFA51852145125F1BULL, 0x3F8406352E36E3FCULL, 
            0xA336339C2E035C7BULL, 0xEA2583C5CFC3F9ABULL, 0xEB0F57C6876C2C8DULL, 0x9AB2504BD8CDE501ULL, 
            0x08395CB113FC3B4CULL, 0x205E8505DE5652E7ULL, 0xAE8D0E8057DF11DAULL, 0x8C56BD942620E06BULL, 
            0xBB1689BBF441A0F8ULL, 0x5E97D9F0368C131EULL, 0x640BE804AAECA7B0ULL, 0x16E7450321D28E8DULL, 
            0x6980D1B17EBE9F39ULL, 0xA8EA495392692545ULL, 0x924EF44A36E7958FULL, 0x1E8DB9A30523C1B2ULL, 
            0xB9D8946813D7BEB0ULL, 0xD27E830C4BE3063DULL, 0x0C6CC1411F6CF46CULL, 0xC67438912F4231BEULL, 
            0x6DE73F32610F2F33ULL, 0xF7854F7A52A46AC6ULL, 0xCDC41F8337162645ULL, 0x436B82E19E1D1C23ULL
        },
        {
            0x9F31942D2808113BULL, 0xCD2051DB25F6D0B2ULL, 0x83EFA96F0ED6C9F2ULL, 0xCE49FDC9BA9C74BEULL, 
            0x2EE00A7942FE79FAULL, 0xF5D3B6C1DA80254CULL, 0x42C3795A49858166ULL, 0xC277D9BD94040500ULL, 
            0x3AFCF1A07944B00EULL, 0x94AE90476BA8D668ULL, 0x33ED812777FE3FF8ULL, 0xA448A9C827FD6E10ULL, 
            0xCA84F0D2911C6F0DULL, 0xE9F536F4AADE2D19ULL, 0x48430455C51EBE98ULL, 0x9C531E0E70A2290FULL, 
            0x0133533375BEAF31ULL, 0x408A55CF8D9A61C4ULL, 0x403097DDE06FF2CDULL, 0xDDD4BB7ED1794B8AULL, 
            0x557B85DBC51FB2F2ULL, 0x5C93E76FAB756BC9ULL, 0x6031B4E2780FCD6CULL, 0xA8927EDDFA4A20DCULL, 
            0x768F70269F4C35A0ULL, 0xCA20DA338956F5D4ULL, 0xFB664A74BEC2533CULL, 0x1B785D8348FD2E53ULL, 
            0x733E51E3584B9602ULL, 0xE73602FCBA297F68ULL, 0x0EF5FC976FC22268ULL, 0x37D3ECF5E770CB95ULL
        },
        {
            0x3B85DA7F7B547B91ULL, 0xA4DC8704F8781FDAULL, 0xE9B86353A3FC5EFDULL, 0x0985FBD6B50D1A5CULL, 
            0x1527A339A1267BEDULL, 0xAFC0CB02EE081E0BULL, 0x63ACFCD56B43A9B1ULL, 0xD4FC620DC53868A3ULL, 
            0x3E5931AF6BC9BD8DULL, 0x6F6099A6A70A88C0ULL, 0x7418B1969B4080A9ULL, 0xB28F4BDCFBEA4B23ULL, 
            0x63D02FB1537D35A6ULL, 0x35E6184BD7B132DDULL, 0x00BA97C54C777831ULL, 0xDE74F4F9B92D29AEULL, 
            0x9EB588027B135753ULL, 0xBC182EFA81E3D279ULL, 0xF9F38BF0D84CE1EEULL, 0x4BB8DD4DD8E3BAE2ULL, 
            0x8082FD837E89F842ULL, 0xA2B27FD740B8809DULL, 0xD64C1697513BFF20ULL, 0x2CDF1181DAC15552ULL, 
            0x98CB78BC3548ACEBULL, 0xF7D973DB95FBCEC2ULL, 0x7406E6596443E065ULL, 0x97F864F9FEF1F66EULL, 
            0x18A9F08B019F1D04ULL, 0xACF4530AA13F2ECEULL, 0xEA16F273326B1355ULL, 0x1A8B90632DDEA0FBULL
        },
        {
            0x33ECAEAD2833DCAAULL, 0x94AF39C6D9B2006EULL, 0x4D81CBBBC5891704ULL, 0x19DF70E9D20B6499ULL, 
            0x6C8E302EDEF70534ULL, 0x440A4BA4025D4B7FULL, 0x029B2F4A101A9114ULL, 0x43B500C1AB2A8A40ULL, 
            0xF917BFE58924299FULL, 0x7D6EB7859E886D05ULL, 0xF55980A1ECF489EEULL, 0x8B3EBF4C3472A296ULL, 
            0x9E4B4AD31A0AF753ULL, 0xF158A90AA3438C6BULL, 0x13921BED7E4BD077ULL, 0x5109E710913F1581ULL, 
            0xD4BE8C00D41D21EEULL, 0x763CB1D05FD3CF6EULL, 0x4EA2E452F9258F89ULL, 0xFBB0330E36DD9D56ULL, 
            0x6F3DD1ED20A80FABULL, 0x24FF51719969467EULL, 0x7E3BEFFB86BE1B74ULL, 0xC7E5C052F8FF9101ULL, 
            0xA53C44751708A89CULL, 0x5A1103009479FD35ULL, 0x4C9968993FA2D2DBULL, 0xE670AC036E0FB439ULL, 
            0x7FFBCAEB4861B50BULL, 0xA0D67D98DD7F9EF4ULL, 0x79331AFF9272CE9FULL, 0x69FA047A5AC39C5AULL
        },
        {
            0x65E7335E6FC1A420ULL, 0x49C5AE9D3BE43023ULL, 0x5AD149EF0E5220DFULL, 0x0877D3383169E77AULL, 
            0x56EF51274D8477D1ULL, 0xDBE3D889ED92F66DULL, 0xA22568B687BC1463ULL, 0x5107324A73DA504FULL, 
            0x66377BB0E18C711FULL, 0x67B88FDDB68A51B5ULL, 0x46819BFF095BFB7FULL, 0xC344F96006055B15ULL, 
            0x2AB5E2A91C57BA06ULL, 0xF6A96CD63AA5FF6AULL, 0x05ED8DC5C9553EE0ULL, 0x4C4D779912A17564ULL, 
            0x03F36B2A86244BB6ULL, 0x4A6DBDCCF208F3A6ULL, 0x669F68D80E610DB8ULL, 0xBB292AD990425F71ULL, 
            0x611380CDA12040FAULL, 0x94EC512BE1E63913ULL, 0xCD1398B2EFECA28EULL, 0x9B05E6D74195EF57ULL, 
            0xA93D591963136A8DULL, 0x952AB9FB97C87200ULL, 0x01B77E2C5337D474ULL, 0xCD086C37B11BA9D4ULL, 
            0x9B73A3829ECC25B3ULL, 0xE57AA1EB9FE30DB9ULL, 0xAF1C6A9FF7B9A15CULL, 0x6E473B8A65398566ULL
        },
        {
            0x95DA3FBF4F7B8184ULL, 0x55F820022CF52685ULL, 0xAB10ED4B4F1D752DULL, 0xC987B815DDE47EAEULL, 
            0x7A2F5B210D20357EULL, 0xE8572474DB1F2E9BULL, 0x968544DC4DACD58EULL, 0xA2F66E66965184E7ULL, 
            0x7337A6D9497FDB56ULL, 0x513D5A5EE7AB18A1ULL, 0xAE3A964D1EE3DACCULL, 0x19C6BCE698785D95ULL, 
            0x0C9879D81AD86B99ULL, 0x588EA2504F1E88C4ULL, 0x1BB61B5CED82BED4ULL, 0x6FC6905EE79C078DULL, 
            0x584CC36CF7065B58ULL, 0xE71486FD59511D60ULL, 0x6F753AFA47BB88ADULL, 0x477D17CAD7239E1CULL, 
            0xB849F16CCF3ADFCCULL, 0xC327B4CCE442982FULL, 0xD50EC79058E6C58DULL, 0xC630EED0BF455A5CULL, 
            0x0B98DE3A17117222ULL, 0xC6422FA9A450B030ULL, 0x56989095656AFFA5ULL, 0x412A09445E73BC0CULL, 
            0x8A402D72657D623BULL, 0x96BBC5D19528477AULL, 0x8494FBAC70D5F6D2ULL, 0xD8828564EC79DFDDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kTwistConstants = {
    0x78533BC43122DD7DULL,
    0xCC33444CD0DF6FE7ULL,
    0x663BC47AD36BB2ACULL,
    0x78533BC43122DD7DULL,
    0xCC33444CD0DF6FE7ULL,
    0x663BC47AD36BB2ACULL,
    0x5B70E025F94BBC05ULL,
    0xAED5C6F9FCD6DAFEULL,
    0x42,
    0xC0,
    0xD5,
    0xE1,
    0x83,
    0x5D,
    0x0E,
    0x49
};

