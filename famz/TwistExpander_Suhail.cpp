#include "TwistExpander_Suhail.hpp"
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

TwistExpander_Suhail::TwistExpander_Suhail()
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

void TwistExpander_Suhail::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Suhail::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA6849E86127B8CACULL;
    std::uint64_t aIngress = 0xD1CD926513A9FFBDULL;
    std::uint64_t aCarry = 0xB939F43110EEC522ULL;

    std::uint64_t aWandererA = 0xEF625B6CDA47AA39ULL;
    std::uint64_t aWandererB = 0xF7515C4B41B0C694ULL;
    std::uint64_t aWandererC = 0xE0B166D19E277B9DULL;
    std::uint64_t aWandererD = 0xD6572827EB99542CULL;
    std::uint64_t aWandererE = 0xEF234C585D581FE6ULL;
    std::uint64_t aWandererF = 0xABFF0733A328F50FULL;
    std::uint64_t aWandererG = 0x925A02BEFF30EBBCULL;
    std::uint64_t aWandererH = 0xE059C9277E362E78ULL;
    std::uint64_t aWandererI = 0xFCA76CCC6762F362ULL;
    std::uint64_t aWandererJ = 0xFF51BAC41B8C1C93ULL;
    std::uint64_t aWandererK = 0x855B3B1FE41EDFC6ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xBDD89891DAFBA5C9ULL;
    aIngress = 0x86B3C62E059A5A09ULL;
    aCarry = 0xB3B9943B1225C181ULL;
    aWandererA = 0x84A92003593A75D2ULL;
    aWandererB = 0xBD7FA1BDEE1D6B10ULL;
    aWandererC = 0xE3649CA0DB94C88FULL;
    aWandererD = 0xCF374E60E26F39A4ULL;
    aWandererE = 0x953F6B5C5FC9EC33ULL;
    aWandererF = 0xC0247CB5DDCE076EULL;
    aWandererG = 0x9ED86A4E0C50A585ULL;
    aWandererH = 0xD8335395ADD849D8ULL;
    aWandererI = 0x93F905C589BFCD75ULL;
    aWandererJ = 0xC235000445D31375ULL;
    aWandererK = 0xAA1804317B6E94AFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xC7F61A717942A54AULL;
    aIngress = 0xA7169562E58B41E2ULL;
    aCarry = 0x86C4FF96CBA320D0ULL;
    aWandererA = 0xE78F5466D58DAA67ULL;
    aWandererB = 0xAEED6E3615BCA259ULL;
    aWandererC = 0xF00202689789FE7AULL;
    aWandererD = 0x81C8C5A165635164ULL;
    aWandererE = 0x98D0BBC0E36BF323ULL;
    aWandererF = 0xA14DEB163C1461C2ULL;
    aWandererG = 0xED4E4CD7C2D83147ULL;
    aWandererH = 0x8D12B1BCFC940D79ULL;
    aWandererI = 0xE698C5E56452C7E4ULL;
    aWandererJ = 0xD8DC23AB19262409ULL;
    aWandererK = 0xF4862D7EAD221C5DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xCCC634E1C4866AEEULL;
    aIngress = 0x86E0A12B64627B30ULL;
    aCarry = 0xC5757B12F3AF0638ULL;
    aWandererA = 0xE23B6F0629866518ULL;
    aWandererB = 0xBA3A045085BCD151ULL;
    aWandererC = 0xA471B79AEEE38F84ULL;
    aWandererD = 0xE668439CB3FA3EEBULL;
    aWandererE = 0xDEE1DBED6237488FULL;
    aWandererF = 0x83E6645C01ACD4B4ULL;
    aWandererG = 0xC72E94EEFB6DB6F0ULL;
    aWandererH = 0xEC7D33DC0F6FA15FULL;
    aWandererI = 0xC20276E457E760FAULL;
    aWandererJ = 0xB9307BB50C0275ADULL;
    aWandererK = 0xD50A01B5DE88AEB2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF9AF8AE2E771B8ABULL;
    aIngress = 0x94413F4EDD1A4243ULL;
    aCarry = 0xF2981D2E8ADE3D84ULL;
    aWandererA = 0xB959AA4E6D4452C8ULL;
    aWandererB = 0xDD103F927633D38BULL;
    aWandererC = 0x83743F878EF6EC18ULL;
    aWandererD = 0xC3C46C66D2883AC0ULL;
    aWandererE = 0xFB2DD6CEE892E4E2ULL;
    aWandererF = 0x9724393E9D7BBF47ULL;
    aWandererG = 0xB24C9C9506C4D3E8ULL;
    aWandererH = 0xE6381512FA1B4F3CULL;
    aWandererI = 0xA06EA54C88E00C95ULL;
    aWandererJ = 0xFB1EC2D82D49A54EULL;
    aWandererK = 0xD4D4F0B3C4635D9EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xBE8974731A38966DULL;
    aIngress = 0xDA545C72E55D0842ULL;
    aCarry = 0x85C287BB1D90978FULL;
    aWandererA = 0xC3F796C7999D9E5DULL;
    aWandererB = 0xC703998F7BD604AEULL;
    aWandererC = 0xB15E435D7E5F5FD4ULL;
    aWandererD = 0x9A1CA259B89A988DULL;
    aWandererE = 0x87760811B10F9B72ULL;
    aWandererF = 0xC77B53945ADCE27BULL;
    aWandererG = 0xA5DCFB59B6EF882CULL;
    aWandererH = 0x8837380ADDF333A6ULL;
    aWandererI = 0xA7F847415E42F5B3ULL;
    aWandererJ = 0xD982DD273947050AULL;
    aWandererK = 0x9BD8065B3E272C8DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x8BDD0AAA122234CCULL;
    aIngress = 0xBA5BC1B136D53096ULL;
    aCarry = 0xCB62CBCBF5201326ULL;
    aWandererA = 0xF22DD39EA142B50BULL;
    aWandererB = 0xA22D7F877349889CULL;
    aWandererC = 0xF23996F1D528A7F8ULL;
    aWandererD = 0xA230DCDFC9310E18ULL;
    aWandererE = 0xE4F82074E9B1E2E6ULL;
    aWandererF = 0xAB2B865CA24F4309ULL;
    aWandererG = 0xE96E0C8E674235C8ULL;
    aWandererH = 0x9F851CF9DDBB5C57ULL;
    aWandererI = 0x937BB25F95DFB114ULL;
    aWandererJ = 0x8578D77AC0D994D5ULL;
    aWandererK = 0xE433980AF845A3ABULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x98F6B376D4A16BD2ULL;
    aIngress = 0x8F1554E0A7371B3AULL;
    aCarry = 0xEA7DDF0B7FBC17CFULL;
    aWandererA = 0xF83FDFC297B97A22ULL;
    aWandererB = 0xBBDA7C43F857AC73ULL;
    aWandererC = 0x897515457548D328ULL;
    aWandererD = 0xA4801CD9822F0D59ULL;
    aWandererE = 0xC1048FB16232C8C8ULL;
    aWandererF = 0xF46A1A18520D5C72ULL;
    aWandererG = 0x9F6AB841C50B9CFDULL;
    aWandererH = 0xDC73A220E84C3898ULL;
    aWandererI = 0xF161580549A8C82AULL;
    aWandererJ = 0xE49ED85D501AD39EULL;
    aWandererK = 0xAB8707476051BFBAULL;
    //
    TwistExpander_Suhail_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Suhail_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Suhail_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Suhail_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Suhail_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::KEY_B_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistSquash::SquashC(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Suhail::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x93D83D4B65EE92FAULL; std::uint64_t aIngress = 0x8F06AE90D994C5A8ULL; std::uint64_t aCarry = 0xC495AD1251AD53FCULL;

    std::uint64_t aWandererA = 0xF01CFC588CE23C30ULL; std::uint64_t aWandererB = 0xDD3E1D6CB87A7C58ULL; std::uint64_t aWandererC = 0x80A655A22F5B0C9FULL; std::uint64_t aWandererD = 0x9AA2F90E58F05F35ULL;
    std::uint64_t aWandererE = 0xAA3794A7607AC5C9ULL; std::uint64_t aWandererF = 0x8C074A0674D1FC8BULL; std::uint64_t aWandererG = 0xDCFE142587D82D0BULL; std::uint64_t aWandererH = 0xD2584192E7828D37ULL;
    std::uint64_t aWandererI = 0xFDA8920DB217DD3FULL; std::uint64_t aWandererJ = 0x8B255C18A16073DBULL; std::uint64_t aWandererK = 0xB7CBBDF90DEE449DULL;

    // [twist]
        aPrevious = 0xF0B8221B6117203DULL;
        aCarry = 0xDCADD81CEEB7ECDFULL;
        aWandererA = 0x8F60A89912DE519DULL;
        aWandererB = 0xB120E2EC523B6BBFULL;
        aWandererC = 0x94FD3D97EAD43BF9ULL;
        aWandererD = 0xC707EBE40651E1A3ULL;
        aWandererE = 0xAD1691AC2A95E232ULL;
        aWandererF = 0xB4829B7788C5D838ULL;
        aWandererG = 0xEC172BCCFDB4F06AULL;
        aWandererH = 0xE5EF4E33B2AD6913ULL;
        aWandererI = 0xF8CE09C3CD17694FULL;
        aWandererJ = 0xE434AB2DA00E6020ULL;
        aWandererK = 0xC73FF2861B8FF1A4ULL;
    TwistExpander_Suhail_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Suhail_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Suhail_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Suhail::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Suhail::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Suhail::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 32 of 33
    // Exploration cases: 0
    // Structural maximin 515 / 674; family total 16551
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
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1780U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 32 of 33
    // Exploration cases: 0
    // Structural maximin 509 / 674; family total 16527
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Suhail::kKeyRotateASalts = {
    {
        {
            0xCD6B4D7223EF5E3CULL, 0x5280DA7B033FD420ULL, 0x8EF778D236997BF5ULL, 0x1C0E2F7D2A6F8E97ULL, 
            0xE348D6BE6DF7995DULL, 0x2B5164598ABB3BC2ULL, 0x8D1850825815461BULL, 0x9A181D44870B2D1EULL, 
            0x92DDF0DAFCF903BDULL, 0x5746CE322ABBB980ULL, 0x2E0584BCB50544A3ULL, 0x4C354884DF59336DULL, 
            0xE9219AAA19E0C148ULL, 0x7E8AA1485F5E2B7AULL, 0x1F3FE2F09FDEBE52ULL, 0xBDAFA360971FA875ULL, 
            0xBB1C852D24503CC0ULL, 0x515FD42F2E80F6DAULL, 0xB3EDA899572B9426ULL, 0x41DE8C1EA5A685FAULL, 
            0x2599AA223A908D64ULL, 0xA2BAE6201B214D83ULL, 0x1D63C4C9380EC0A5ULL, 0x8ACA6E3367A142ECULL, 
            0x0802314DFDF935D0ULL, 0xFB57A2FD72DF58F7ULL, 0x82907E3A5A435F93ULL, 0x3454156C019AC87BULL, 
            0x22FBC3095A81A12BULL, 0x476A89C86A2AD91EULL, 0xE9B79CD88C70B91CULL, 0x4DD627D17A02BA88ULL
        },
        {
            0xB4B8DDDFDF441936ULL, 0x6E9C6A90D2BEEE18ULL, 0xE334BB284D7C41A6ULL, 0xED4CC10CB7D9C7EBULL, 
            0x6A4F615910025BF4ULL, 0x8584B8C0AAFD2C41ULL, 0x7AC84792838F17D7ULL, 0x976A9578E8DAB381ULL, 
            0x28EB157A8D8F6DB9ULL, 0x3DBF1839C2FAB4A8ULL, 0x20D93483C77AD40DULL, 0x7B79FDF2A67DAC9DULL, 
            0x7313EF96A069C278ULL, 0xFFA494304810FCC8ULL, 0xAF59D6141C2F74B9ULL, 0xA404AF15A76CD337ULL, 
            0xDE51899351770BDAULL, 0x19D46C59914C5C57ULL, 0x3F014886C0EBB9BDULL, 0xFA324049C9FB309BULL, 
            0x52C99C30B331120FULL, 0x2E4A8B19EBA1525EULL, 0x6B0B5D2FF99D6026ULL, 0x01EE62353B449D53ULL, 
            0x77816895C580BD4CULL, 0x7B16DFF0EB2C4B07ULL, 0xAC86F57A235E3B5EULL, 0xF7627EAB9BA7927DULL, 
            0xA91228FBC5713813ULL, 0x5E7A1AD6742BAE1DULL, 0x18BF2CEA0055B94BULL, 0x54BE81659A6E9FABULL
        },
        {
            0x44BB7FC0D1DEA697ULL, 0x3AAFC7DE3B7CD3F4ULL, 0xDDE6C9C26B9C5B2EULL, 0x2CA2734CE8D909DCULL, 
            0xA8AB9AE360910FD8ULL, 0xD02BD7EDD7E0ACB5ULL, 0x83554478E282D376ULL, 0x8B0F22C071A4E582ULL, 
            0x8F1BF7372C0492EDULL, 0x299722637CB0AF1EULL, 0xDA8D37E71913C6DEULL, 0xED795E7DB897B72DULL, 
            0x6456705949E015D9ULL, 0xE396B7D3DB69E617ULL, 0xDBBD919D4D40935BULL, 0x19B6F200F9374249ULL, 
            0x05B2E1B5E696E39DULL, 0x18927A11EC356CBBULL, 0x1E8E5FEF5B3E3AEEULL, 0xA9F66CECAC7B632DULL, 
            0x4E99037D79EC39B5ULL, 0xBC1CD1159F5633A8ULL, 0x14EC4EBF166C8F7AULL, 0xC3A7F82AD8174895ULL, 
            0xD2022B7F22710B0CULL, 0x80DEB40AE9C79683ULL, 0x61EE597363C3E6F4ULL, 0x7F708311E5D23D1AULL, 
            0xD1D08787B8A393A8ULL, 0xF9986E5E0020C1CFULL, 0xEDA678EA7D352995ULL, 0x3DBF7184A5B3367BULL
        },
        {
            0x74099CF9FA5F02B2ULL, 0x92EE9C7B63F614FFULL, 0xA447D9F2E3AFCC9FULL, 0x6A39BFE0AF5CE7D1ULL, 
            0x0A69B9565EFDCF77ULL, 0xC610D733116720D1ULL, 0x754D9688DFCAA516ULL, 0x84A53BE1D7954287ULL, 
            0x73BE82CACC71B8A3ULL, 0x26A8C7DA7A4C0917ULL, 0x7B3D0020E894F63AULL, 0x8720D310DB7816C7ULL, 
            0x34C0AFA581A53F8CULL, 0xFC91B5D8597D6AB1ULL, 0xFC6EEAB3C26219D0ULL, 0x302A5FA3FB08485BULL, 
            0x0CA2B4B5589CAE4BULL, 0xD5E981A74AE68686ULL, 0xC87775FA3F720BA8ULL, 0xE6C845BF6CCED2CCULL, 
            0x9DD21593205F04D4ULL, 0x0C2917199F593B72ULL, 0x2A0C9AA894D2B341ULL, 0x87E37843A436C9B1ULL, 
            0x01747C1B09AD520EULL, 0x4535312C4F69C39AULL, 0x2C29AD8434DDF738ULL, 0x85ECA36245D323B3ULL, 
            0xD0B5C23AC85424EBULL, 0x6FD3E6276A449FA8ULL, 0x32BB8673EB400F19ULL, 0x236F3DF23805AF83ULL
        },
        {
            0xCE64A81FCA78F619ULL, 0xCE707C515D09707DULL, 0xE1C44121C82D92F3ULL, 0xD6614005D468DF8EULL, 
            0xA537478F0A44EC56ULL, 0x8B732772CE8D1A85ULL, 0xAF3D3FA59AB5CFC9ULL, 0x33DA01E9E3FF1CE3ULL, 
            0x07438E07C7B6D9F1ULL, 0x4ECF8BEC796318DBULL, 0x73AFC22DF006B531ULL, 0xF8F0C2D3BC5CE609ULL, 
            0xE3D368FEAE22E65FULL, 0x02D32B3E2674C043ULL, 0xD072CA80884035C0ULL, 0x63503F37EF851928ULL, 
            0xA1063AC004BEAFFCULL, 0x66AA3F386A7677DBULL, 0xF3C297936ECF1BB4ULL, 0x999218712952B215ULL, 
            0x980EBCD84D9C2D19ULL, 0x6347A43C69F16C9FULL, 0x23CD0E6B8E5B0235ULL, 0x221ED03F9FB291E6ULL, 
            0xC5C35A8953B6AEC6ULL, 0xDE0A6F0112C4BF20ULL, 0xA00E9B27BDE2084DULL, 0x85F9306147028821ULL, 
            0xC571975DC6D9E888ULL, 0xC7AA7DCC33F6312AULL, 0x8072B862F1C37E85ULL, 0x5F70CEA7B82760ABULL
        },
        {
            0xC624C688E50CCAEBULL, 0x42F972CC9500764CULL, 0xED5DC66D15FFEFEFULL, 0x095A7A9678E082AAULL, 
            0x21CCEE115F6CD73FULL, 0x655AF64FC328F9F3ULL, 0xC7A5C64C40768CFDULL, 0xE6F324FB1C1BC996ULL, 
            0x2AD22A7BC581BC52ULL, 0xD6D1366F3D194BFFULL, 0x287C96D6A9A160ADULL, 0x40609DEEE234B2EDULL, 
            0xE9DE3BC6A174AC07ULL, 0x9A0DEB854D072CBDULL, 0x87F170992F0AB8F2ULL, 0x2C5D20048AE57285ULL, 
            0x2A614D34B42859E9ULL, 0x9B3A52236BC80E5CULL, 0xF778370B9D87B4F0ULL, 0xE832DCB5DF841981ULL, 
            0xE33C5195C9D4656CULL, 0x774826C39A2B7CCBULL, 0xE8FDB8818483CC91ULL, 0x60C2A6E8A816DD12ULL, 
            0xA1B4A0DF33EBCAAEULL, 0x48EE1B25AF47D62FULL, 0x585672F935BFC367ULL, 0xA8FE7EAB7B7AEFC7ULL, 
            0xBAECD7B5A9E078F2ULL, 0x5D3ECB207ECA2D5AULL, 0x075F679E7D2461CFULL, 0x05450FC2B5096395ULL
        }
    },
    {
        {
            0x7B00F893F37DEBBFULL, 0x147A3BF61BD346B4ULL, 0xDC494A2B023DC546ULL, 0xA308A2BF0D390F3BULL, 
            0xFB80886F793AC445ULL, 0x61D252775D0E073DULL, 0x2F10D72C4AD5B7A6ULL, 0xEE34DA9AE6A2757EULL, 
            0x75AEEAAFED67F059ULL, 0x4F202435EC95FAABULL, 0x46615AA369A0625FULL, 0xE7B87BCFDE908ECBULL, 
            0x76D81AC587F02488ULL, 0xEE12CA0410A2A83EULL, 0xB24272C50EA551EBULL, 0x42F6D5F51091482BULL, 
            0x0F16216F82D2E6C4ULL, 0xC56F13ADA97A2110ULL, 0x42CD12EBE85EA30EULL, 0xFD92750B728863C6ULL, 
            0xEB0D067868CDC08FULL, 0xE34F685DF9409370ULL, 0x36A8496A9A3C34F2ULL, 0x24B28920F633FE23ULL, 
            0xA5B9FEC737412AA1ULL, 0x5F3F4D1EABF6D885ULL, 0x77040336C346CBA8ULL, 0x2D8E0B6B38FB57CAULL, 
            0xF8207D1126252E02ULL, 0x2ED2DFCA99914A14ULL, 0x2FDEC99DFAC65452ULL, 0x86761D77FD65747DULL
        },
        {
            0x17F2A61CC7723F7EULL, 0xAAA744B1F513921FULL, 0xE8FB532B0FF68033ULL, 0xC2F689BAB5E654CAULL, 
            0x9E6B285A96CC9408ULL, 0x470026936CBFD71FULL, 0x20CCE67C191D100AULL, 0x5DA51B61C7A6A1A4ULL, 
            0x4A154A341F829770ULL, 0x3D304A092529D2A8ULL, 0xE96C070B68E1086EULL, 0x929A20D5E58315B5ULL, 
            0x382386D8FA224833ULL, 0xA0517D3DD547AAE1ULL, 0x06E836A3D195A4B9ULL, 0x7AD108A5CFF301B1ULL, 
            0x344A9080B5C8A680ULL, 0x9314DB8B821FAF78ULL, 0xD486C16EC51072BCULL, 0x8EB832910D958F5EULL, 
            0x2736EDFC9FA36BD4ULL, 0xB5BF777297951CC8ULL, 0x8C1162478847551BULL, 0x5E2A084D491B8B47ULL, 
            0x6FBCC311AEB321C6ULL, 0x064B4933D2A3C41DULL, 0x4EAADEBE21A40B78ULL, 0x1E9F87345CB3D0AAULL, 
            0xB43ECF034825B1C0ULL, 0x0100BCD7D5BDC4C5ULL, 0x5F14465435336B12ULL, 0x7B3DE665E23BE242ULL
        },
        {
            0x7F55B4246A7DC55EULL, 0x9AD18C829385757FULL, 0xD2523611A5B00A4DULL, 0x09F8FE9F2408E0CCULL, 
            0xC28835EF466945C9ULL, 0x1BF0DFB634A3C510ULL, 0xCF6DDF84B418D441ULL, 0x29DEA0D140617214ULL, 
            0xC6D2D825995F6D35ULL, 0x5F91FDCE65AB6567ULL, 0x50954E1ACDD0D8F3ULL, 0x2B438B0DEF73CB94ULL, 
            0xB55EF436BAC4A80BULL, 0x63FA94B17DD8E234ULL, 0x8843BCF36E52F9C2ULL, 0xA496C0CC01B346B4ULL, 
            0x034A10B4DDEA89B2ULL, 0xBD25A98E4C0DF984ULL, 0xCBD99D59C38C2DA7ULL, 0x4D0C41966396ECC8ULL, 
            0xE338A412E5444C7BULL, 0x0EDBB00DC2597EC2ULL, 0xA5B8618CB063C7D7ULL, 0x8A233C219D343A1CULL, 
            0x949CB1F321E5DE52ULL, 0x9DF402C72FD19842ULL, 0xDFEBC6FC9B94C1B3ULL, 0x39B39A5770FE8415ULL, 
            0x15201A25E14C91A7ULL, 0x3D1A6F93CFFDF1AFULL, 0x0069C3848BA15954ULL, 0xBD343159D981CF9FULL
        },
        {
            0xF24D57ACD785EC36ULL, 0x559D2E8FEC18295FULL, 0x417B5FE97F2031FEULL, 0xAC11427A8FD29B58ULL, 
            0x2763DB653994F2F0ULL, 0x7709FB8C732E93B1ULL, 0x33B0AF8720A6E535ULL, 0x87A1D0E186A4D51DULL, 
            0x3CCCEC3964BA68D7ULL, 0xC441741F2A5A9325ULL, 0x7798E1300590BB2DULL, 0xB2FB9BDEFA6AC87FULL, 
            0xC49B49D4BB275257ULL, 0x74DBCC562E1B81FEULL, 0xBC7719687A6067F3ULL, 0x81AB0B59FC1FFDFEULL, 
            0xF78DFC819EB17FD7ULL, 0x05899645551AD228ULL, 0xCB8BDBB44BB64FA0ULL, 0x73914AAC9D9C9984ULL, 
            0xFEEA922D215C75E9ULL, 0x127F6BBDDD471619ULL, 0xD2C3C6DCF78377BAULL, 0x95E9FF4A7999AE89ULL, 
            0x455BE4A8E2C5ED19ULL, 0x3B30E1C392F82926ULL, 0xC30284848E4DDA4FULL, 0x93DAB68B8A79597EULL, 
            0x89C5E31905B82184ULL, 0x869916189ADCCAA3ULL, 0xA3CAECA833B24314ULL, 0x686686C6EBD69BE7ULL
        },
        {
            0xD3861D6EA1B14FDEULL, 0x5AB9CF451C9A16F2ULL, 0x09C3A1B273720B38ULL, 0x0A69EF0A09AED1C4ULL, 
            0x8DEC40B070987E53ULL, 0x3F4A08715E589AC0ULL, 0x7729A2B479541E85ULL, 0x45E7B05C279A4266ULL, 
            0x24D04DEEFBEB488BULL, 0xF9A7897A3D0072CAULL, 0x9229BE6DF4D0EBA4ULL, 0xC5FC21395E4EF0B0ULL, 
            0x431D81F03FD94DCDULL, 0x458DA9E62CD352D0ULL, 0xE491C52F82CD766DULL, 0x0F68D108AD000A98ULL, 
            0x00F8EA01673A26CFULL, 0x6FD6EEB641A6A803ULL, 0x978F45057EFD0A64ULL, 0x242E3E714F721C84ULL, 
            0x65FE460C35AC26A5ULL, 0x2323AC5E3AFDAD8CULL, 0x6D97F165C5399CBBULL, 0x2A50366DEF2246BCULL, 
            0x3F6929FB1DC5EC29ULL, 0x8EB497F428F3A368ULL, 0x4503F63DDC83689DULL, 0x432D779702D6797FULL, 
            0x90FBE88BF55F6034ULL, 0x5C4BA4E0C66BE258ULL, 0x494663D8309230AAULL, 0xAE249CC2CD9C85CBULL
        },
        {
            0x39EEA447FD2B7476ULL, 0xBAF0C8FF20C7BAEFULL, 0xCE6FCCD7879DCCCAULL, 0x2FE209A0FB89D948ULL, 
            0x3B6F4A013DF7279DULL, 0x45CCF2803DDF6584ULL, 0x0273806CD266968AULL, 0x42080AF0CAE80E2FULL, 
            0xA08702C581A160ECULL, 0xBDE66D64FF9BDA95ULL, 0x028EBFF103C78AF3ULL, 0xC0CB4A801FD94BA9ULL, 
            0xF9103AAFC63538CBULL, 0xD98FAC510F0439DEULL, 0xFF1FE45B1DFA1B9EULL, 0xDCCAC6F14FE4DB05ULL, 
            0x91387BE07AD4EB08ULL, 0xC18093DECE950A8AULL, 0x9772A818D818E6E7ULL, 0x6DB87E64EA410ADBULL, 
            0x5404010C4F0FB674ULL, 0x8B93094E046566DDULL, 0xD05618A8D8B20F31ULL, 0x8CC837FECE1A6907ULL, 
            0xD23F0E5806694ECBULL, 0x7CDCA15E21F8DC00ULL, 0xDC719F5C8D439BD6ULL, 0x2BA75863C866A0FEULL, 
            0xF47A3F469ED657BBULL, 0xE7A96062DC95FEE3ULL, 0x1F946A409597CBD5ULL, 0xA0A5EC3E75314F1FULL
        }
    },
    {
        {
            0x8DD1736D77A3254DULL, 0x3ED54AE1C38D8322ULL, 0x384EE028080C5D8EULL, 0x5EC098BEC17E8D2BULL, 
            0x15520F3CB00494ABULL, 0x3CE6DFBFF74DE246ULL, 0x9BEEE47DD5D2CE7DULL, 0x3105329D905049D3ULL, 
            0xFA110B3CA1119B30ULL, 0x312DDC2623ADDA19ULL, 0x72A834B31BBDC048ULL, 0x5EE265C2DCE852F7ULL, 
            0x44372F55D231A838ULL, 0x6B90AAAE0DF6D3D6ULL, 0xB2BC6F2076F7865AULL, 0xD433A2A33F5765BAULL, 
            0x0F5996CE86BAC54BULL, 0x3B310AC632A37162ULL, 0xA92EE7444E81BCA3ULL, 0x521C0EFA619031F4ULL, 
            0x8F1B37F7C2C7D2BDULL, 0xB7EF89ECDCB56AB1ULL, 0xAFD637F49AED405AULL, 0x070B61241306138DULL, 
            0x3D852E5EB14FCF9BULL, 0xF4DDDD159B6A6513ULL, 0x1B38630EEF9BD13FULL, 0x56D850A0CB3D2812ULL, 
            0xAC47B413F2BEC726ULL, 0x6413EF01723AE6B9ULL, 0x90204491312FEF4AULL, 0x37FC6128336E7BAFULL
        },
        {
            0xF10433CA60DE901BULL, 0x148923B54CF15FB5ULL, 0x11F6514B41D5AFCBULL, 0xEFD4573BC8F417C2ULL, 
            0x7834022F1D5591F0ULL, 0xFEE2731C0FA328C0ULL, 0x07877663D64B35F2ULL, 0x427EC3289007F371ULL, 
            0xEAC9E1F068126E65ULL, 0x1C2CCC3EBB0499C5ULL, 0x4BE5807C96A20C38ULL, 0xD3D9C01FCA66F557ULL, 
            0x6E475FBD4A3E6E2EULL, 0xCC3F4A681A8FE26CULL, 0xC335B9A5DBFA04AEULL, 0x4258D52292A74844ULL, 
            0xFFAC94AA3B27631DULL, 0x2AA4955A80E92E90ULL, 0x58CF5D8C51E1A2A4ULL, 0x4F69B1AB4D7DB53BULL, 
            0x4CF2379302A143B2ULL, 0x2A33341290023100ULL, 0x5DFCE3F4B928E354ULL, 0xE29486F2A4DB5901ULL, 
            0xF2C50564817E538BULL, 0xD5379E503E461DAEULL, 0xFCDB347924D23795ULL, 0xC5557DD82E509945ULL, 
            0xC4815617B33C40B1ULL, 0x123600E2CB8654D4ULL, 0x1441CC144DAFB08BULL, 0xD4A7645EA94DC24DULL
        },
        {
            0x842347FE5AEDFCCEULL, 0xCE93734ABAED68D0ULL, 0x37BB92628E294512ULL, 0x7135F2D93463E416ULL, 
            0x6B24E41093DE8360ULL, 0x2BB873633A7CA881ULL, 0xCE554D7DD04E6144ULL, 0x2EAB27B905DE0419ULL, 
            0x0D2451D494DD837CULL, 0x1EE6BADB1F26406DULL, 0xB2ED834ACD0A75F2ULL, 0x6A1BB343D90D4FFEULL, 
            0xBAB0E15C26AA8FC6ULL, 0x22CEE671CDEEE97CULL, 0x9D6E76F34566F9F1ULL, 0x5906A9E674FDFFE5ULL, 
            0x1EAA8F83BD7203C4ULL, 0xB66858567A0D09FCULL, 0xDA286C14E52AFA0DULL, 0x2118DCDC0C64412EULL, 
            0x70ED03284F25A2D2ULL, 0x00023067D0169406ULL, 0xDA794D4F662131C7ULL, 0xEF05C07BB2815CBCULL, 
            0x1C3B33337AC367F9ULL, 0x773DC8888F130FD0ULL, 0xE3EAD9D99BA7E625ULL, 0x871AE49A2634DCC0ULL, 
            0x2EBC07C7B8D60D3CULL, 0x7AB27B02D80CBE79ULL, 0x6A86E4E30B81FDABULL, 0x80FB0248DA8394DDULL
        },
        {
            0x4DCE177E85CC6D2AULL, 0xCC5FAD552A866C6EULL, 0x0F988816E42DC2F8ULL, 0x4C9E2C5812685A3EULL, 
            0x3C3692FA5D2782FDULL, 0x8466731B27DEE6D2ULL, 0x8ACAA201950DF406ULL, 0x1F5EDAFEFC39EA0FULL, 
            0xE12B37DF716A2173ULL, 0xFCB3B00534AFC302ULL, 0x68A46AB424D0134FULL, 0x6524CD18B4A1F3BAULL, 
            0x53CFE244B9342125ULL, 0x3513327E7B76C318ULL, 0x913DDAEE67F8F97AULL, 0xCE96B9E0D0A7049AULL, 
            0x4A4813B817EDF6FDULL, 0x60EC701E990B69DBULL, 0xA2029E48DBFADD4DULL, 0x960B4B478CA00D62ULL, 
            0xF5FE6D8608CD9281ULL, 0xFA1641A90011673FULL, 0x1DCEFC8FDD95C9B9ULL, 0x87986144996E38F2ULL, 
            0xCB864EA720E3B935ULL, 0x1BC8C1B1E976C376ULL, 0x7A5D7823E7F1E931ULL, 0x64873EFE234A4090ULL, 
            0x0344F08215EF7F0BULL, 0x48C9F20D1AE772E0ULL, 0x6EAACE7E501717A6ULL, 0xEDA90FB3CDF6B293ULL
        },
        {
            0x5FCF81D2135DA24BULL, 0x0D67002361A128DEULL, 0xD174F866DE8931BAULL, 0x6ABB5EFC247B99F0ULL, 
            0xF02D3A55B88C883FULL, 0x2D5CCD20D9C41D5EULL, 0x948ABCCA713109B6ULL, 0x03A1258237FA1D0BULL, 
            0x136B3ACE40D080CAULL, 0x32B238241161B857ULL, 0x3BF377535A15C328ULL, 0x67CDE25D5AC20F15ULL, 
            0xE386998CB6E8D848ULL, 0x471234EB6DD81795ULL, 0x7CDDCA7750D5515EULL, 0x77507DADEBE74FF5ULL, 
            0x48BCFA8385ABD644ULL, 0x44BB096539868375ULL, 0x856AF4C487B98844ULL, 0x3A670F6FFDFFA1F4ULL, 
            0x6DC755AB7F5D7B19ULL, 0xF8BD71D0AD66CEC4ULL, 0xBDD7480C3CA45BF1ULL, 0xD11B1DBE3A13F3ECULL, 
            0x1F1812E029B77B04ULL, 0xDB7CC320CCD77257ULL, 0xD522917F8526DC1DULL, 0x4366C41844B49C04ULL, 
            0xA1B9929A2EE07533ULL, 0x5D45877C55F68259ULL, 0x8DDA903B242D9C67ULL, 0x288B5A6810157832ULL
        },
        {
            0x0B2088DA4C95CBE2ULL, 0x752BE5F52C2B1F01ULL, 0xD3C49A8F1F7B35A5ULL, 0xCD069BBB0D41AF18ULL, 
            0xD3F3C66624C821AEULL, 0x06CE3FCBEA328FBFULL, 0x1BF4D1B46765E591ULL, 0xA8C28BE28EC9328FULL, 
            0x2C4234C55BD7EB65ULL, 0xD23A9373EC23612AULL, 0xD786732A0E993FE9ULL, 0xCF352A84F170702FULL, 
            0x96D3E86964519764ULL, 0x050252A03B14F92FULL, 0xCBB13D8F922EE27BULL, 0x8C2E1A2597FFE92CULL, 
            0x48A0BB6082943AC7ULL, 0x64271CFA5EE5020BULL, 0x432478E60838D800ULL, 0x1C4679D7D53F88BFULL, 
            0x939CA0E674BFF8A3ULL, 0x0CCB0D62A1A6E79AULL, 0xE0A31B17441A5D2CULL, 0x33B85FE37CC5BA60ULL, 
            0x30121130224D891BULL, 0x0D0ECBFE9E082D7DULL, 0x159AF35487CC67F2ULL, 0xD110D62AD521672AULL, 
            0x8BF947476410118BULL, 0xA15026E15AF4B7AAULL, 0x33AF537F44FAE253ULL, 0x6CE0E3F651DB05DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeyRotateAConstants = {
    0x5A7A8873475126B1ULL,
    0x2D978C33B2942604ULL,
    0xCC1A20716190BD4DULL,
    0x5A7A8873475126B1ULL,
    0x2D978C33B2942604ULL,
    0xCC1A20716190BD4DULL,
    0x90429628EEC7E929ULL,
    0x4F75B340B304F92BULL,
    0x0F,
    0xD0,
    0x7B,
    0x7C,
    0x60,
    0x61,
    0x9D,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Suhail::kKeyRotateBSalts = {
    {
        {
            0x9E57B52915D6CAB7ULL, 0x1ACFC79A9736765BULL, 0x517AE4B15F309E38ULL, 0x03EB3ADA0B635E4EULL, 
            0xD1E0E192BA906488ULL, 0x4437C38195DA19B2ULL, 0xEB04C49AA2B93D17ULL, 0x14FE38142C273A97ULL, 
            0xB03357696DCDA077ULL, 0x94F34CFCA20FD5BAULL, 0x2689A82DEFCF449FULL, 0x8E1B9F012BACBE75ULL, 
            0xBF9930D97DA0C304ULL, 0x29D648130F52C633ULL, 0x5B4FC3AF8A729C47ULL, 0xA6EA36E6F69A5D5CULL, 
            0xEAB7D746ED437E46ULL, 0x7643C79481A2F7D3ULL, 0x95721A0CE33A2E99ULL, 0x2AE9F4B5FF513989ULL, 
            0x48B79AB3134A953BULL, 0x667C73F81ADD1C74ULL, 0xBD960041BC58AF16ULL, 0xBF0BF1E43A8ED131ULL, 
            0xDAEE6E9C688C6D6FULL, 0x86424393A52097FBULL, 0xDBD67A4E92E28111ULL, 0x1BD9B7EF2D8E0320ULL, 
            0x2EE33CD8BD8C9EC9ULL, 0x5CA096F9894C424EULL, 0x5CE9D621D3B0C650ULL, 0x85052B60BE943852ULL
        },
        {
            0x0B65E048E317785DULL, 0x7A0BE5B87BA13BC2ULL, 0x36350672EDC4F2CFULL, 0x99BCFE8410216F8DULL, 
            0xCD381B60121DCE69ULL, 0x9B18B20F145AF305ULL, 0x823320490FA9C3AAULL, 0x1545118C23075FF2ULL, 
            0x6FF4FFCA37258531ULL, 0x1007B9EC590097EFULL, 0x07F236BBB0B18F31ULL, 0xBBA5A1BEF01F59B8ULL, 
            0x6C227E8154BD8F63ULL, 0xFF97988576191A9FULL, 0x6388679AB60A4306ULL, 0xBE5E7915686C4F7AULL, 
            0x34AD92AAE263B619ULL, 0x74A9CDF4C813E800ULL, 0x87897DAC295307AEULL, 0x8292B7CA2B4004A0ULL, 
            0xD2AC2D105ED00498ULL, 0x1ABD9262521245FAULL, 0x8A928EDAB12D0CFCULL, 0x444E8D3551999BE1ULL, 
            0x1D9D0C4A2E7D2625ULL, 0x1177FCF38EA754A2ULL, 0x3DF06DD8AB0F7085ULL, 0xCD4F39FEAE69F89EULL, 
            0x57E6139FF6FF8A31ULL, 0xD06A94A83CFAC767ULL, 0xEB47CF4E4084ACF5ULL, 0xAF4AC12D5536CD84ULL
        },
        {
            0x21A5CD8E8DC2C8F6ULL, 0xF1A6676F550028A6ULL, 0x990684A0271CC19EULL, 0x01259B4918E64A74ULL, 
            0x50F49550EE5B6B5AULL, 0xA4F4D3860AD3DBE7ULL, 0x1808B58246E58490ULL, 0x676F60FA51018A47ULL, 
            0x43B1FE8E0BFA68B0ULL, 0x3A965BB755D8784AULL, 0x320161D4E55318B9ULL, 0x9988FCB3582B588FULL, 
            0x76BB1F4116579CDFULL, 0xE44020890E6ED195ULL, 0x635BBB1C1959CEE3ULL, 0x025A68827ACA109FULL, 
            0xAB058B7D43673610ULL, 0xA46666EAF8FC27D6ULL, 0x18F1EA2F9D57FA48ULL, 0x01D212FEB51D6BA5ULL, 
            0x3643058A2EE4E86BULL, 0x02BF8DA995067DAAULL, 0xF0ADE0762A7608A7ULL, 0xCE024E3FF244A7E9ULL, 
            0x268A8AC9CD3D2261ULL, 0x9F833C0C475EDD8DULL, 0x4D3083B97499357CULL, 0x4420FFC1676D4BAFULL, 
            0x37A9739E8D8AFB60ULL, 0xDF398FED6A759392ULL, 0x3D85D7D5889BDDC2ULL, 0x26942683F254BE0AULL
        },
        {
            0xBA4C0748D6E1757EULL, 0x65D7D0771A418EABULL, 0x0C5B0AA4250C0CDAULL, 0x99B0505D57DD7C6FULL, 
            0x82FEB6494B686A60ULL, 0xAAB8C7C28A524CB5ULL, 0x87EEF14F86951FEEULL, 0x236E74A927C1931BULL, 
            0xD9AF87E1B2273772ULL, 0x18994DE24A28431EULL, 0x88E744BBEB6EED99ULL, 0x5E000E40878673A6ULL, 
            0x67B7A0C3C23F5A97ULL, 0x2075BF7615799726ULL, 0x45DE00D74C474D90ULL, 0xCB18B3BB8C887989ULL, 
            0xF13E3660B9B30F12ULL, 0x6A0A08808D7E191FULL, 0x62B543F5C85A7AEEULL, 0x49A57073B4031350ULL, 
            0x841B3A3F72534787ULL, 0x652352E74337CF66ULL, 0x21AD0A6FF0E199FDULL, 0x689EF15786BADC64ULL, 
            0x385D67495F30F7F0ULL, 0x86BA8A101A634E21ULL, 0x020908DAC66BF2A1ULL, 0xE6D7FF16AC44FBCFULL, 
            0x70B63E4126B62D15ULL, 0x05F75BC9E58CF5FFULL, 0x8C4C62F6F27D2D5CULL, 0x881B3E7221E5CDA8ULL
        },
        {
            0xB50415C94A6FEDBAULL, 0xDA50AAFF4EBB973FULL, 0xF1B5A2FBF9AE5395ULL, 0x47241F9012333D64ULL, 
            0xF8C51ABF7ADCC342ULL, 0x3195A8E6EA333758ULL, 0x04DB224EC8E74E07ULL, 0x629467584C6D1637ULL, 
            0xF8F7F2C15F9D75E6ULL, 0x5ED86C0629C49CC8ULL, 0x85B938DE4702BA85ULL, 0x9C536C8CF198D942ULL, 
            0x5B615A3AA5555556ULL, 0x24327675FDBF616BULL, 0x2CEA03425E857DE7ULL, 0x398DAE975490B945ULL, 
            0x528A82A7A207B2FFULL, 0xC7ABE33EE26031FDULL, 0x095934F9C57CCE2CULL, 0x69891D2CC90484DAULL, 
            0x94F1575DD5A14379ULL, 0x5E24F7A9653DC02FULL, 0x119655FFDF985F83ULL, 0x0B661AF31CF7DF84ULL, 
            0x33099CD55B1F1819ULL, 0x958F88D3C1875EBEULL, 0xF6DD11B67E5BD2D8ULL, 0x4CCD1FAE4E999BCDULL, 
            0x2629B85AF21CA007ULL, 0x7006EB00E2924F1AULL, 0x99FB266FE57E0E2FULL, 0x2B14FC124874E254ULL
        },
        {
            0xD9F5265391DB44D7ULL, 0xBDF3B815F4CA1CDDULL, 0x3377019604FE4F1CULL, 0x8809BB66683EA13AULL, 
            0xE717910E9FDED592ULL, 0xBF801CF18372FEAFULL, 0xE3CC189F4680A129ULL, 0x83C0588BF7176B92ULL, 
            0xEDBAD7DFA98ABB15ULL, 0x2493C04FA9E3C589ULL, 0x2FC12E5079773CBFULL, 0xD1757565597F4933ULL, 
            0xFC798F447F597D22ULL, 0xD06956575DE41B5EULL, 0x4B23523054BC8D0DULL, 0x3C0E4E8FEE5E9DAFULL, 
            0x2543EBA2344EB863ULL, 0x397EA22D76A0A5A5ULL, 0x9BF60BAEB29E0E6EULL, 0x9EADAFA590E6D0D3ULL, 
            0x8C92CB8ACA074820ULL, 0xB63508B75700F3CEULL, 0xDBF512D38862360CULL, 0x9D748BF7594730B6ULL, 
            0x9419AE5642380663ULL, 0x6865A88E1BAEF26EULL, 0xD1634854A236C9C7ULL, 0xC3AC4CB94B59FC67ULL, 
            0xAE7916851293873BULL, 0x8811946164EC7E76ULL, 0xE3E8A3AC1427266EULL, 0x88926B28DED33985ULL
        }
    },
    {
        {
            0x5E2C95FEFBA7ECA0ULL, 0x4F4BA50EB37AEC8EULL, 0x38872B6EAA361140ULL, 0x461C2C9D57E80D11ULL, 
            0x6C76CDB162CAC7D4ULL, 0x5C0799E9A6478C43ULL, 0x5A41FD1B9D93B84CULL, 0x437642E821C1D2AFULL, 
            0xDFDF8AC92C66A1BBULL, 0x28E44798091A20B4ULL, 0x66F19A4F8DA285B8ULL, 0x90ADCAC56CE66476ULL, 
            0xDAA203DDBFA6FCE9ULL, 0xF3998E2539A74B44ULL, 0xB524FE1F5989CC6BULL, 0x6FBE08885DB4764EULL, 
            0xA4AAFA5974B90478ULL, 0x3DEE81A302ADCAFEULL, 0xA42FC2956E4E161BULL, 0x0847F6641CE1F4A4ULL, 
            0x27419D4983430BA6ULL, 0x523719916F559E36ULL, 0xD9E1CD710E23BFC1ULL, 0xC13890E386220347ULL, 
            0x94BFDADFEC3F3E88ULL, 0x5FB41E4E210E25E6ULL, 0x1088A121D8313262ULL, 0x7333276F86228A11ULL, 
            0xED603DBCAB0EFA5EULL, 0x199A79C77D5B8970ULL, 0x72BE381DB0E02372ULL, 0xFE21664F1958B3D6ULL
        },
        {
            0x291C318CFC470CF4ULL, 0x820CD2F9A9287344ULL, 0xA4067446AA9761EEULL, 0x5411D62D46EC4C7FULL, 
            0xFC260AEC463C8417ULL, 0x24B7547C930EABD4ULL, 0x3ADE3264EC59FF17ULL, 0x52890B454E80BC18ULL, 
            0x2F0CAD2DE44F968CULL, 0x16C50AFFA696B5E9ULL, 0x7EAC519271D68E58ULL, 0x68C5FD8CBE91CDF5ULL, 
            0x30E92AA4F4BB415FULL, 0xFE177C044C44B543ULL, 0x84AFB391C10BF30EULL, 0x0618AD68160DB05AULL, 
            0xCDC635113D64CCC1ULL, 0x7AA927A555EEDFBDULL, 0xDBD5D9976A19B12DULL, 0xD3FEF3AFC4785F1FULL, 
            0xC0B003C9E4439E6DULL, 0x332B3B23C004DD63ULL, 0xA36A7A6D7DC82E41ULL, 0x02829520D6A10D82ULL, 
            0xA0CF2F4357512CB4ULL, 0x1271E89D7F0916C7ULL, 0x6CC9D9C106CFEA49ULL, 0x21408E65E801B83DULL, 
            0x165690D9EE0FFDD3ULL, 0xF674DA0D59C72EC5ULL, 0xB81AC1907D95E867ULL, 0x5B319D358DDBC5D8ULL
        },
        {
            0xA5357846CFCF2260ULL, 0xEA8D13B4B85864B4ULL, 0x4AB69F18162CA244ULL, 0xBBC79281C6191407ULL, 
            0x279FF0A1C58172E4ULL, 0xB6A3ED05F7D24DEEULL, 0xD8DAC8EB67AA5960ULL, 0x0494DA6FCB8D1F27ULL, 
            0xF631EC54B678EE8AULL, 0x30D1F882BEF77459ULL, 0x6FF37BFCB878BE3DULL, 0xF026D5C305928E94ULL, 
            0x148BE63D3F51D0F4ULL, 0x723C852093FCE4D8ULL, 0x1BC55C01033E4A50ULL, 0x06D5E446B6185185ULL, 
            0x92AADD3618B958CFULL, 0xDBFCEB949CF1F3B6ULL, 0xB6CBC8E33416820CULL, 0x1A7F0EF6EB3DDC3AULL, 
            0xBF8949E424D83D9FULL, 0x022A25FC38399836ULL, 0x6311C99FB52A3292ULL, 0x67D226C957CD90C2ULL, 
            0x9C7051CDA735E815ULL, 0x2B8070B2ECC89B8BULL, 0x7F8CD135CC2C11DCULL, 0x48C6CB29E775E070ULL, 
            0xC2356DB0351BFB89ULL, 0xD5E30C0000FDC7ECULL, 0x166F299A1D12A3D1ULL, 0x172CB88567369072ULL
        },
        {
            0x4AD70E68CBCD14D3ULL, 0x8E1C4AF59DE8F131ULL, 0xC722051B51BE2CA4ULL, 0x9D8D0D377374C868ULL, 
            0x13EA5CBF93B4E92FULL, 0x8F75876289CF8C7BULL, 0xCFCBAA201C614DFDULL, 0xA292443246D394A1ULL, 
            0xD942D41830D979E2ULL, 0xB18F0495409167CDULL, 0x323BDF70D293B3C6ULL, 0xEFDC9AF481F47C59ULL, 
            0x4AD4FFE01D2E2045ULL, 0xBF059E8BDE521E3BULL, 0x8EC670729A3F4D92ULL, 0xD3270C91D3B1A158ULL, 
            0x19B975300EF18517ULL, 0xAB204995C58C6B49ULL, 0x05D41E5CF182F343ULL, 0xEEB6E9A7C96E5554ULL, 
            0x1E1E1C800989FC5AULL, 0xF84B445C154768C8ULL, 0xE3E0F738CEE7E20AULL, 0x59BBCC89C2BE6B6CULL, 
            0xC857D9D3897166CFULL, 0x6B698BF59A83DA82ULL, 0x9DC3105265097168ULL, 0xE4A3C04D7C37C954ULL, 
            0x7B8830D9D9CE706FULL, 0x28309E99267F1599ULL, 0x077ADD080673C186ULL, 0xB14C11227D4F8429ULL
        },
        {
            0x21BDB9E9BB0F335CULL, 0x8C8363B684E232CDULL, 0x520A4EDFC5CE9924ULL, 0x5FB863BEB6FF6988ULL, 
            0x7BF6AD27C1628C46ULL, 0x6319FDFF94E1F711ULL, 0xCA986C78A6C87060ULL, 0xDB7E3AEDC9CEE272ULL, 
            0x1D454F09A9C5F456ULL, 0x71D44C62A35BBBA4ULL, 0x150F40BC5569AAB7ULL, 0xA820169DD0848242ULL, 
            0x6D5EA6079754A957ULL, 0x243E2C7D630AF5BCULL, 0xD7E808059DB83D25ULL, 0x3DF1D675889AD05DULL, 
            0x079C8CC6A781161BULL, 0xF4F47C53350AC498ULL, 0x2095B36696E7E5ECULL, 0x9D6C40697F4516E7ULL, 
            0x76F71E8F14AA5595ULL, 0x0C93E5AC695FA8F3ULL, 0x5548E921549322B2ULL, 0x2391670C3640DA2AULL, 
            0xB76F958A1113B70EULL, 0x9F3026025FB83444ULL, 0x4515361FD3B98801ULL, 0xA1D16B003A2D498DULL, 
            0xC4DACB20F7E0CFC7ULL, 0x443759BD67581C09ULL, 0x1541F91E80BCB346ULL, 0xB69EB32A55115798ULL
        },
        {
            0xE7D50E324A4B780FULL, 0x8F99F62E1A376E6AULL, 0x2DD468DAD143C66CULL, 0x6C25591BB8462698ULL, 
            0x3F0ACF46DA72F61CULL, 0xBE647BF23F7E1B92ULL, 0xC708ACE7E5B65A23ULL, 0x6E3FFA9812414464ULL, 
            0xC6369275B38E917DULL, 0xE5109F4161A8349CULL, 0x37E18DA99E79035DULL, 0x6341E9D88C7EF325ULL, 
            0x91973F20C08ABFF1ULL, 0x9806AEF00190FB5DULL, 0x1B508D907CEFFD15ULL, 0x023F2C44E9AE1404ULL, 
            0xA832CA1AD47BAA2DULL, 0xFEADCDE9F619CE77ULL, 0x2B13C97EC676E623ULL, 0xF7C34BA3E5C58431ULL, 
            0xF16AD616C424B58EULL, 0x4EDEC3283A0AEAD6ULL, 0x1DB0885AA8B32FF0ULL, 0xAC1CD6A24890A99AULL, 
            0x5058A8619268FF86ULL, 0x428484BB8F5ADBD6ULL, 0x43D0290FC540CB28ULL, 0x424AFA9CBF7C793DULL, 
            0xE75F26CD4CB0015DULL, 0xC1C0029378983F5BULL, 0x53772D7D0E418546ULL, 0xAA91FB9C1CDECAE4ULL
        }
    },
    {
        {
            0xA04BD608D3C57E3BULL, 0xBEDE554B5F695E86ULL, 0x5A5ADF253BB334FFULL, 0xA197E91AA9FE7C70ULL, 
            0xF7CEAF6770194E8CULL, 0x6FD600346BCAE71BULL, 0xB9A77F3713B3A69BULL, 0xC8588BB1C94E486CULL, 
            0xFAAC597D37FA4000ULL, 0x5EE3349955055E94ULL, 0xC071A52254AA34FEULL, 0xF8BDD00DAA6DFB6DULL, 
            0xCA038F29F74EAA9EULL, 0xF77B50710479BA74ULL, 0x417EECCB8882866FULL, 0xA69039A529674ACDULL, 
            0x8E7D7604FBDE577BULL, 0xF4E3B65EABF9543AULL, 0xF23462E41E5EBC94ULL, 0x99170005BD3CB451ULL, 
            0xE1D76B26309F7F55ULL, 0xE57A9C2997BB2E5BULL, 0xE65C05350CB36B3EULL, 0x812FD4F9B64ED917ULL, 
            0x770B4D10D2127B62ULL, 0x10D42EFA1ED02F34ULL, 0xA009A31C674D8AA1ULL, 0xD18333524228EE59ULL, 
            0x55632AC27F7CBD9EULL, 0xF7E1BB52A16E6633ULL, 0xD59C614B2D28D286ULL, 0x61F5A423026DD1F7ULL
        },
        {
            0x7F816B03DC18A32AULL, 0xD48023EC8296CB4AULL, 0x277D9375D94292BFULL, 0x4BFBCBC37832BD33ULL, 
            0xEF20CB45F375D821ULL, 0x5BBB7F919A9C031AULL, 0x60910D4DDF423773ULL, 0xE322C1D15F15E511ULL, 
            0xA79E07E961B81B2AULL, 0x3643A20397850A00ULL, 0xA7B2A78254802EDFULL, 0xF2A64E55E53B0619ULL, 
            0x65B3181BB95B610DULL, 0xBDD279F2D8482A87ULL, 0x91FC3ABD0AEBA1DFULL, 0x57E62F103AE273C9ULL, 
            0x10166E6165728471ULL, 0x4BE177DAD929127CULL, 0xB6B110EC4FCF0254ULL, 0x9733B7D9801040AAULL, 
            0x05EF33BAC55091FEULL, 0x728F7F5CCE624B8DULL, 0xA010ABDEE03E81FBULL, 0xF99756B06DCB9F0DULL, 
            0x7F4E0C66DD60A180ULL, 0xCDFBBE62B3AC9B29ULL, 0x8659BB400D05EA68ULL, 0xF563096161FD5173ULL, 
            0x1B485FDA9B60103AULL, 0x46920BD337445856ULL, 0x781F35A942C70647ULL, 0x2A3851993A2B0436ULL
        },
        {
            0x15B3CE4C65A81A52ULL, 0x62FCA4CC59C96BF3ULL, 0xAAA52547D5B5647FULL, 0x0C65A355185C7848ULL, 
            0x8EC2094D35EBCA32ULL, 0x98FC81E41EDC2B6DULL, 0xF7B57B0BA61C4A0AULL, 0xEA49BCB8878F0FD1ULL, 
            0x38334850EB73027BULL, 0xBAAC4AF5C89D5352ULL, 0x9B403CF369FB812CULL, 0xD2185EFBDFFECF3DULL, 
            0x3110768E9406FD6AULL, 0x4F7D39F58370C67BULL, 0x2448EC6BC6EFC11FULL, 0x53900E194D93BED6ULL, 
            0x8FD9723984360226ULL, 0x9837E1E86997499DULL, 0x5CE21BC20494090BULL, 0xE5DCDDD2FBF38146ULL, 
            0x715ABBD43FF43B82ULL, 0x2212077F3DE94A35ULL, 0xD388566E383D30A4ULL, 0xC4C3E8CD80958EC1ULL, 
            0xDC644B5AC5601C04ULL, 0x0F5122DBAB79275BULL, 0x09ED74278AB4DB7DULL, 0xE3170D00965EF5ADULL, 
            0xB0D9BD9101804A88ULL, 0xDB0867B57E9A6C14ULL, 0x25D95AB790E40F0CULL, 0x29ED232466EB51D9ULL
        },
        {
            0xFCA2CA66ADFCFDD5ULL, 0x51A1408335DCA1BCULL, 0xBB7DC116B975C713ULL, 0xF31BD922DBC845DEULL, 
            0xD6C91BC0B10DDFA9ULL, 0x3ACFF0E1439B5F9AULL, 0x6EE48555A8E4BCECULL, 0xC25FD3D3AE2EB636ULL, 
            0x2F4839363FDB6F3EULL, 0xD2871A446B87BDCFULL, 0xB5A6E24E3EBE25B1ULL, 0x25B64BCC85A833B5ULL, 
            0xAF6CAA9262439A7AULL, 0xC85A99A667120E50ULL, 0xBAA386118D9D1121ULL, 0x120CFFEECE8B2710ULL, 
            0x2EB1E6BBEB5B6E0AULL, 0xB5941E7A19EA0830ULL, 0x8A6BDC5EF32F52A9ULL, 0x25F2033307A31CA9ULL, 
            0x5FD3FD52BAB8CE02ULL, 0x27B5A29A4EF19E64ULL, 0xFEA44A60757D8697ULL, 0xF842B3D194E66E14ULL, 
            0x1FDA30B07C0F61C1ULL, 0x7E72C9ED075A4C69ULL, 0xE7B10CEC2829E5B3ULL, 0xDCF45ADD8C692D60ULL, 
            0xA6CEBA70F9AB9DC4ULL, 0x75B5520152737C60ULL, 0x9147AAFF57DB17F7ULL, 0x1CA8CA07DFAE0B74ULL
        },
        {
            0xADCD4EE891ACCE63ULL, 0x4F88DD7FD189D818ULL, 0xC86D0B7764B01E8CULL, 0x2FFF03A0B972262CULL, 
            0x6DA446F4FF06E5C7ULL, 0x3C004702DD548EBCULL, 0x7675F0D619EED81BULL, 0xC76CE9D2979EA2A0ULL, 
            0x60552C41E30C7420ULL, 0x423299C2AA691373ULL, 0xE7AE67806BD90523ULL, 0xFA5ACB786079545EULL, 
            0x8AC879CF410970C0ULL, 0xCC892B0E7C9F9C3CULL, 0xF50C021D2A3188DFULL, 0xFF606104A5F84708ULL, 
            0x3A03D20C4BFC61E9ULL, 0x6A5D7C635D1E1382ULL, 0x7DD75EC556809F99ULL, 0x35A5CC5FB3515962ULL, 
            0xF2E8D84AF04220BFULL, 0x757E52379B88C842ULL, 0x4CD2B18D7996BDE9ULL, 0x5E5F5E33525EC345ULL, 
            0xD17B7C6198BB6546ULL, 0xF9F20BBF8285E0FCULL, 0x4D1A8E6225A58332ULL, 0x79BD0A7BD85DB538ULL, 
            0xC4C3EB52736B9DCCULL, 0x59E6A81C88E9D73DULL, 0xC92F0D49D1B1379FULL, 0x239158D981E32C03ULL
        },
        {
            0x66CD3E6A1CE1FB4CULL, 0xA8708CAC6011E0DEULL, 0xC6FF6E0833C244F9ULL, 0x5C7BE1C28586BA7CULL, 
            0x4506DFC3F42678C4ULL, 0x7C740B71A4A557ABULL, 0xECADFF6989C962CFULL, 0x100DEC986228E522ULL, 
            0xE0C1C1B7B8919760ULL, 0x42BF90F1E5BEDA7CULL, 0xD312EF14C884A3D7ULL, 0x9A199797059454C8ULL, 
            0xCBFE638521742EE7ULL, 0x3F630F9DF1C398C0ULL, 0x7D83E2164E3312D0ULL, 0xE1D407D8995E6EDBULL, 
            0x66844CEA6812B7C1ULL, 0x9CC930C423BBC389ULL, 0x360D1FC1279141C5ULL, 0x5F6E8B221A3AA7E2ULL, 
            0x0D797E0FA03A785AULL, 0x5C78720B73E835FEULL, 0xEC0359943D6EEF56ULL, 0x8969EA1D469F68DFULL, 
            0xDB7A15718B326C92ULL, 0xEB01FA2CEBFAA25AULL, 0x074E16BFA818834BULL, 0x4976A4E91818D324ULL, 
            0xD964E385A9147C1BULL, 0x85353F51690B36E9ULL, 0x0290A9BD24F0D61FULL, 0x9BD5B993C50F3EEBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeyRotateBConstants = {
    0x4B69AD78A14B22AEULL,
    0xF4D29A5C45AFB878ULL,
    0x1E94F680440E117EULL,
    0x4B69AD78A14B22AEULL,
    0xF4D29A5C45AFB878ULL,
    0x1E94F680440E117EULL,
    0x4365467CA9AAFA23ULL,
    0x18B5ACB7EB9AD4D9ULL,
    0x78,
    0x77,
    0x21,
    0x7F,
    0x79,
    0x63,
    0x43,
    0x7C
};

const TwistDomainSaltSet TwistExpander_Suhail::kKeySpawnASalts = {
    {
        {
            0x1694D6B1B58C7464ULL, 0xB436A4330B676FDFULL, 0x6A999E8EE75BE99EULL, 0x92DB4069417A52A6ULL, 
            0x7E03068999D30521ULL, 0x5EBCD6BB4AEC0102ULL, 0x47163B78DA874704ULL, 0x1B0F266179D4C48FULL, 
            0x0B06792D78C916FBULL, 0x0BD93E9DE236BBD6ULL, 0x370EFAFC19CC4407ULL, 0x055863090AC13E43ULL, 
            0x59E3709AE143A0DCULL, 0x1A3EF37E59C78BE2ULL, 0x517827B5691CC112ULL, 0x6BF8A3E02BFF0B63ULL, 
            0xC57F91CD9394DBACULL, 0xEC6DBD08A19F0AFAULL, 0xA8CAB7BCB977655DULL, 0x51D064BDB0248592ULL, 
            0x4369F25D98C8BEE5ULL, 0x67ACA5A8062BE858ULL, 0xDE866AA38609FF77ULL, 0x078376994377D885ULL, 
            0x4036E59225746E7EULL, 0xE19B531165C3BDA8ULL, 0xE608A558AAC190DCULL, 0x7AFCC9349D4D66CFULL, 
            0x31E4435E794A5F4EULL, 0x9CC030D087AE45F7ULL, 0x1496BC366C9A83E3ULL, 0x77534D88A53B7EFDULL
        },
        {
            0x7AABDF27F62A7CCFULL, 0xBCF9796D9D4ABA4CULL, 0xE9784B76A07BDA5FULL, 0x33207C4B7AFAB1B2ULL, 
            0xF0B18EAF52CED435ULL, 0x71808BEFFB6A045FULL, 0xC95E21BF8AA47184ULL, 0x0DB93E05B432C0CAULL, 
            0x36B7757BF69A0A31ULL, 0x11BCC7034345B757ULL, 0x7FAAD0C5090341C3ULL, 0xA21C3DAB86D6EB57ULL, 
            0x79C338D9DC753BAAULL, 0x325363B5F3082653ULL, 0x9AA2489ED980F13FULL, 0xEE3314471DD0538CULL, 
            0x69E5B72B9AD4BA8AULL, 0xFEB4C22D9345D63CULL, 0x59182EFDC2F42723ULL, 0x4EEDCD05B7886CA2ULL, 
            0xC842477D19B2FFBFULL, 0xCBA872428FB576B8ULL, 0xEC00425DB9E21BA1ULL, 0xE2E99AD881E2EE11ULL, 
            0xBC16C5006D26AFAEULL, 0x13B1AE445054CC65ULL, 0x219CA70AE9784502ULL, 0x6DA9DF3D372EBDA8ULL, 
            0x89D146C2BCE55E0BULL, 0xAB83A81AC8DD8DE2ULL, 0x8EE32E6A67E6FE63ULL, 0x53E767C40FEEFD3CULL
        },
        {
            0xE31806B82B96C8EEULL, 0xE86747912F1033F5ULL, 0xAD8DA6CAD804E7E4ULL, 0xD859B1037121EA04ULL, 
            0xEAAED48E0B8BAD96ULL, 0x3B67FE966F6B8966ULL, 0xCAF3DB1127D79400ULL, 0xFFDE9AF8AC1F492EULL, 
            0x94191C56CAF8A538ULL, 0xAE1AF80E9308E19AULL, 0xDB920CA5DB15D552ULL, 0x980533513C32D8FCULL, 
            0x9F90F14A349047ACULL, 0x09A814D8DF99E029ULL, 0x04E2180BE334F1DFULL, 0x67A7CB8A96CFC3DDULL, 
            0xA9953FDA42AC5686ULL, 0xAA65DDFBEE94FF0CULL, 0x536B61603E1A762DULL, 0xB84FCBF27D3D5F21ULL, 
            0x2833F9E85D1B750FULL, 0x4412E646358E62EDULL, 0x15CFB6AEDC49B935ULL, 0x76EA5C4A357B462AULL, 
            0x26C30F3E191ED1B7ULL, 0x1C0784B192B3D607ULL, 0xECAA56A34FBD6893ULL, 0xDD59B74323255D41ULL, 
            0xEDD939071B6DBF9BULL, 0xB5E27537B3575770ULL, 0xA5CEA4E28D55D512ULL, 0xF8D585E63C297031ULL
        },
        {
            0x6F99510189330AA4ULL, 0x66D50BD5B9903581ULL, 0xBE39182A63DCBD06ULL, 0x514911B8BAD88911ULL, 
            0x201BA0A2DF8770D0ULL, 0x67A53AF3377E4F97ULL, 0x11613F40EB895CB4ULL, 0x864B4093C4A49F3DULL, 
            0x1DB653B1B90B7CAFULL, 0x2740094AE12775F3ULL, 0xB55A98B28EF9904BULL, 0xAADEA26EF81C634FULL, 
            0x4B64A85F84D77A57ULL, 0x11CCB477E5B472FBULL, 0x2301B71ECF523E07ULL, 0xC2C7D024D10FBDDFULL, 
            0xE41BF44EE8633791ULL, 0x2CC3C373BE369789ULL, 0x64B74CEB38BE8BC4ULL, 0xCD7BB6FEA08394C8ULL, 
            0x4FA54067A1098E23ULL, 0x05BF6C401D6F3C75ULL, 0x42A88DFF8816EB7DULL, 0x7E2127555E803FABULL, 
            0x69540B6FACEDF1BCULL, 0xE97C52064FA51131ULL, 0x2F66984F73C871FDULL, 0x2AA5C53A786D91BAULL, 
            0x75E68BD1AF999C21ULL, 0x7A2F98D4EDE27D75ULL, 0x7794A2834D2590FDULL, 0xB6DEB6ED17BE20DDULL
        },
        {
            0xA6A635E168A00DCBULL, 0xB742868D4DE4EDAEULL, 0x12987C4C488ED775ULL, 0x988C9AB9BD19151EULL, 
            0x8A074D761D6E9422ULL, 0x6662AE9C15A8F7FFULL, 0xAC3B9FD235B9ADC7ULL, 0x2355E826B276738AULL, 
            0x2AC817E00321A254ULL, 0xA9C9E4B6F8DF7F4BULL, 0xB8303E874693B98AULL, 0xE0D18539198078FFULL, 
            0xD04F7F3C0B21311AULL, 0x03DB3FC1808BA6E7ULL, 0x642259B6A721423EULL, 0x88B1E2F0547A2F60ULL, 
            0x4356A1B407B85D74ULL, 0xC19A48520377D433ULL, 0xD0D76693CCE30528ULL, 0xC3B29DE8CD059494ULL, 
            0x86CF7B5EE0157AFAULL, 0x1E24327455BA278FULL, 0x3FC240E9972DE24DULL, 0xFE90424071A93C0DULL, 
            0xBE67915EF868FB92ULL, 0x2F206730B4B0D528ULL, 0x3C0FDBA5A93E13BEULL, 0x3B6246C6D8EC4132ULL, 
            0xC6FA28F7E7FFB565ULL, 0x20AFD973A6392F4DULL, 0x14A2BBD8B4688933ULL, 0xFA91ECDF7B48D2E2ULL
        },
        {
            0x2D3FBF5236A38052ULL, 0x845DB1FFB9173039ULL, 0xBFD4C971AE8DDEA3ULL, 0x5CE2E6FD61E22446ULL, 
            0xFB30C1DA040CA2EDULL, 0x9B9554FBD6ED279BULL, 0x78B950AAECD8A315ULL, 0x23C1E0CA12E92649ULL, 
            0x41A32F65C4390B77ULL, 0xC25E8C5C23C693ECULL, 0x8467AB07F31353F7ULL, 0xB6460791440CEBD9ULL, 
            0xD92C38584865E0FAULL, 0x8FFC0BA614256592ULL, 0xEBB2C23E3F823A3EULL, 0xDF0C4072BED2C0CAULL, 
            0x6B9D871E35E8F19BULL, 0x5ADE572C950E2EE0ULL, 0xB3B3DB6481EE149AULL, 0xAA1DC5A718F9DDDDULL, 
            0x61EBEBA0BDC73273ULL, 0x5536BB55C7A1AD35ULL, 0x2341A10A094647B0ULL, 0xC792DB12DCF4E8A0ULL, 
            0x53AA3AE907334EC5ULL, 0x91D295172BE6F75FULL, 0x2F95066A1FAD7217ULL, 0xA66B60464A184D41ULL, 
            0xD65FC4460F31BEE3ULL, 0xFFA3485AB97F284CULL, 0x295C22DFA38D9B5FULL, 0x7FECAA6378B737BFULL
        }
    },
    {
        {
            0x9AEAE2DA21D05C64ULL, 0xC3EE85B8BFFD0885ULL, 0x3A47E0FBDAB81AD5ULL, 0xE950DB77BFD6ED19ULL, 
            0x55FD640CD6D33E1BULL, 0xE0DF12297B249110ULL, 0x1459EF69694F1CD1ULL, 0x8E70894DE00AA379ULL, 
            0x31D1FDC7FF3C2AB3ULL, 0xFF0492C755F39A5FULL, 0xD9391FD71C64510DULL, 0xC36410D672AFB959ULL, 
            0x7F87E9409ECB1B3EULL, 0xD8875200004B7A82ULL, 0x5B8E6F469D255D8BULL, 0x9565AC3ACC19BB70ULL, 
            0x9C4AB23DB9112A62ULL, 0x0CD4FC56EC0F55EEULL, 0x8790B02D01F00133ULL, 0x9A44669E8915D60AULL, 
            0x8EAE5BDF6FB301E4ULL, 0x9136F268007EF21BULL, 0x78CA9D670329A96FULL, 0x42DF78AD673A18F9ULL, 
            0xFE5D5255E2C88C4AULL, 0xF33F6D4C2D276B3DULL, 0xEB820414226BDF37ULL, 0x0B65AC94C8A46BC3ULL, 
            0x036865DB5CDAC453ULL, 0x1F7649707CB41CEFULL, 0x6D847149E50035BBULL, 0x0320E6EB5FAFD59CULL
        },
        {
            0x5651C63CBD6E505FULL, 0x90D4539FC419A272ULL, 0x44C4BC6EC3BDBD3CULL, 0xF86D79A756636AEAULL, 
            0xB00B1F54B7A3F600ULL, 0x9497CAD736301EE2ULL, 0xEA3276A9BC56598AULL, 0x8F495E079DB00C18ULL, 
            0x0A6C221A689C13EFULL, 0xEC9FCE772959F116ULL, 0xDC1CF1DDFB115D1BULL, 0x2FC9AE2619120A84ULL, 
            0x7DCFC9C588A094DAULL, 0xB087339DCC4E9031ULL, 0x765AA50BC9CC8B8CULL, 0x7BE637B222F97526ULL, 
            0x53829B1F5067F46FULL, 0x1A8E96E2776643F5ULL, 0x8AD011CB8787BE0DULL, 0x2DD096993D778104ULL, 
            0x0E6EFF57544D127EULL, 0x2AA9AFD9B494DAE9ULL, 0x4F97D928C40ABD95ULL, 0x5AA290BE8DA730EEULL, 
            0x4950A70C1F022A02ULL, 0xC0DF043AD5DC9124ULL, 0x0F68B3F6710F158AULL, 0xDCD595B44022B522ULL, 
            0x79A88718701D4E7FULL, 0xAA9E1A9FDA31733AULL, 0x8E99A8E7746396EEULL, 0x5D78CA40609F8A2DULL
        },
        {
            0x5ACD0F45A09B4339ULL, 0xBB71036454A37DBDULL, 0x9409FEF9FC29F59CULL, 0x73A43DD60C5CA01EULL, 
            0x7DDDBD0B4E0C493AULL, 0xCE2C25835CA14357ULL, 0xB1C521147801CA73ULL, 0x21A928052014BF1EULL, 
            0x8030E8E8AF5AE07DULL, 0x8EC5F2B8015E1132ULL, 0x4B90F6BE8CC38AC1ULL, 0x3D2135023FDAF3B9ULL, 
            0x8C509229676EFCFFULL, 0xE545714481997B48ULL, 0x44F7DE401D2AB3C2ULL, 0xF1D27109504C1C88ULL, 
            0x0D86BADA2DFD784AULL, 0x6E5A42AD71EF5A88ULL, 0xCAB311579828B432ULL, 0xEFB1846F9CAB88D0ULL, 
            0x91FDCF0A8DAC4D0EULL, 0x0C4EE9FE986CDB30ULL, 0x05760D8CE8FCCCF4ULL, 0x091C1DC01B07AFC6ULL, 
            0x4468FB6F03DA3DC4ULL, 0x15B12CC907498E7DULL, 0x5EF5183E876DF2F6ULL, 0xB10F2B69D3E4E542ULL, 
            0x8E933B3C04E7BC90ULL, 0x7190982E020F230CULL, 0xB9CBD14722D4F345ULL, 0x7A8B2FC1E47E0DB4ULL
        },
        {
            0xA0908D8A7673D6BBULL, 0x584F5BA2282E8AA9ULL, 0x102FE8D2D13845C3ULL, 0xA32D6E41AA679501ULL, 
            0x48CF227800CB6A73ULL, 0x1C8BDFC2AE4BFB10ULL, 0xD1E31B757BDC675DULL, 0x31F0F205DEE71032ULL, 
            0x2F60DA4411DC2A76ULL, 0x00119C8D433E48CCULL, 0xA7BECB93694124D5ULL, 0x92EB7B9C8EED723BULL, 
            0xE97BA4DC2C37A261ULL, 0x26A557EEB0B6D349ULL, 0x413617A85058BD01ULL, 0x0116A45EBD1D3F2DULL, 
            0xFFC27684BDD3739EULL, 0x0EA26C3A28D0BB0AULL, 0x9E199EA5AF30AC7FULL, 0x120EEA5B428031ACULL, 
            0x3AF7B26A3AC5CC57ULL, 0xBA3B9681EE42B407ULL, 0x2E80485F4C844C35ULL, 0x346165CF382A048EULL, 
            0x054CFD7D3031DB5BULL, 0xAB8F6ADC4E1DBD77ULL, 0x0BA97FF77D7800F7ULL, 0xABA5DA109AEE31DCULL, 
            0xC513B2B38C79E4B1ULL, 0x8C31E59B331185E2ULL, 0x96ED06C5E3EB687FULL, 0xD52FD910AB667A64ULL
        },
        {
            0x162B362F821C062DULL, 0x2322FD4A27A46727ULL, 0xAFB67D47FC464B8CULL, 0xCC44A4B93E514902ULL, 
            0x07D80C16F4022B8AULL, 0x466F1216F09900A8ULL, 0x9289E069F5532621ULL, 0xAED870B7F9872DE1ULL, 
            0xE565EC00785FE27BULL, 0x587AE05C3D43E21AULL, 0x62374EC206B07EE2ULL, 0x40BF490B8F66F76DULL, 
            0xDF906ED26AAAED2BULL, 0x9A23EE99B03E8212ULL, 0x446C87B519E9BDA0ULL, 0xB67A217DA54FD719ULL, 
            0xCDFBB7DD994BA0E9ULL, 0xEC295E080ABCF218ULL, 0x1C4BACF64E5BBA89ULL, 0xC60F0D96B6FE3ADEULL, 
            0xFDE6A623B750844EULL, 0x12E2A08AFDA19D8DULL, 0x409BB15E596A4479ULL, 0x605A519F47D738F2ULL, 
            0xC6F64E84C96A2AFBULL, 0xFF49F220613F7C74ULL, 0x3EA806C73E493212ULL, 0xBCBBD227A91E5FE5ULL, 
            0x7ABEBEC7453BAC7DULL, 0xD6A5B3FEE34D22F8ULL, 0xC9950E6D02BF96BBULL, 0x9CDF5A87D3DB1275ULL
        },
        {
            0xB2599F60DAD51F0DULL, 0x9F6354BF64A16346ULL, 0x9E346875696824C4ULL, 0x5064C7770600763DULL, 
            0x6C12E037BC1D1D54ULL, 0x921C0D9AFAD27D4AULL, 0x1DF244BE5E0CFBE2ULL, 0xCC3602C1833CF8CEULL, 
            0x556100A0D932B81BULL, 0x8FE57143C0E94110ULL, 0xAA98D5AD2EB58F19ULL, 0x77B709D4B5491435ULL, 
            0x1C444D1D187732F8ULL, 0xF6D4535496C45D76ULL, 0xA8BB1FB8FB2FF2AEULL, 0x5E3807CF34AA8930ULL, 
            0x415DEE7B0EBFE3EAULL, 0xED660CA185CD9340ULL, 0x81509A3BF6379476ULL, 0x176B29DE44CF4EE7ULL, 
            0xBD910A9CF943DEA1ULL, 0xB40498ACCB5B6D79ULL, 0xBF360AD6133EE0F1ULL, 0xB6A2D84B1F0FF377ULL, 
            0xB394CFFF468B54FDULL, 0x24A16AB94B1FAAE6ULL, 0x4221AC64EF095C2AULL, 0x4C9CB7D5C1488864ULL, 
            0x86739BA2AF26A8C4ULL, 0x59EDC9E87C7191C5ULL, 0xA3E65CAF1D5658F7ULL, 0xAE613316D485C8CFULL
        }
    },
    {
        {
            0x59A6525E824CDA21ULL, 0x827AE61232636C4BULL, 0xB0612A0A74D8F487ULL, 0xC30EA89F32E51839ULL, 
            0xC96F66384C7D15A0ULL, 0xA410B72DDCF7AB39ULL, 0xD2D7460C43C6C503ULL, 0xFEE6B4563B045266ULL, 
            0x4F9D7549D4B368FBULL, 0xD6549205FFF9D785ULL, 0x5B4F2AEE0468A009ULL, 0xA06FF637E09BA39EULL, 
            0xBCA14CC5BB9C87D0ULL, 0x2955923905838CA0ULL, 0xFCCBB0BF78386D85ULL, 0x09F862091506BA19ULL, 
            0x2BB4BD0A56528CC9ULL, 0xEBB8D06C4D62137EULL, 0x26A8D8ECC0FB60FCULL, 0xBD1E588F90172CBFULL, 
            0x375898B2361E0D21ULL, 0xDFF5A40C2920CBC2ULL, 0x78B1B29B2506B960ULL, 0x4AF113D008D985A3ULL, 
            0x3263258176FE836FULL, 0x29066BE17926F710ULL, 0x0021AA2959A2EF2FULL, 0x9669B165644D5191ULL, 
            0x191913C647A4E886ULL, 0x6BB113C126230C91ULL, 0x34B96E836E5BB444ULL, 0xF6F22CCB94640106ULL
        },
        {
            0x12E5D034A78DC285ULL, 0x2C1B88511A750BA6ULL, 0xDEDDF9E39A992936ULL, 0x1508A1DE7A8FAC8CULL, 
            0x6FC78679D24E29F1ULL, 0x3674E0DE423F8F91ULL, 0x0A82F10AEAA8D5CEULL, 0x728B980B9BC6675AULL, 
            0x4E19BE3454A17538ULL, 0x315FD40C30E1AB12ULL, 0x3D7DDD34994ADC86ULL, 0xD7B6DFAAEBF6917FULL, 
            0x737A45D397281349ULL, 0xF56FC07AF19C03A5ULL, 0x2E18528C103C08FCULL, 0x62CDECFCA9C7CD07ULL, 
            0xC69AA8BB29649709ULL, 0x03D49C329F511F48ULL, 0xA657C045A0F41697ULL, 0xA7F7DC3BCB0FD82CULL, 
            0x176C16A9FEFE5137ULL, 0x9D137495EF403F81ULL, 0xD5FEC8A4889CF1C5ULL, 0x64E841794ADD521BULL, 
            0x56C5D89852B68D65ULL, 0x4139444C024E1A1BULL, 0xF134E2D9431F1E57ULL, 0xB802893F83A4709AULL, 
            0x3081D3740CE8238FULL, 0x5ADB322832EEB305ULL, 0x5FF547458D2800B5ULL, 0x3B960043A8883C61ULL
        },
        {
            0x37A71F84D228A6CDULL, 0x90082CDFED66D681ULL, 0xEA2FC45687C05BCEULL, 0x24DBB85E95427818ULL, 
            0xEABCF14DE5EDD25BULL, 0xB3A4D42D218BC9E1ULL, 0xA98ED6FEB65EB955ULL, 0x41DB1097FEC4817CULL, 
            0x1973F1A074A548A7ULL, 0xCDA73402CA192CB4ULL, 0x6431DB39074740B4ULL, 0xF13E267D223DC187ULL, 
            0xF52BE4B988DE5E8FULL, 0x28809219908F183EULL, 0x9502D9DF22560670ULL, 0xD35C8BE74271E990ULL, 
            0x3DD82302334F9BD9ULL, 0xE8BEF1A81E612886ULL, 0xE52DEE37CA618BFDULL, 0xA6DC9FC591141452ULL, 
            0x936A7E1BF0BE99C9ULL, 0xF174F1D005F29CEDULL, 0x62CF14499F6C7DE5ULL, 0x5ED7D37DE306131DULL, 
            0xAAF7715EC8610F95ULL, 0xA1CF53544459448EULL, 0xB6D368C662BAC416ULL, 0x70551D58FADF50D4ULL, 
            0xC0536390E1DBFF91ULL, 0x6CD5EC88C6567D8BULL, 0x2E25A023879A5261ULL, 0x8D8A024631D78446ULL
        },
        {
            0xBD9609F5A88CD4FEULL, 0x05A8881219D644A5ULL, 0x8BE43EB5C6DA52CFULL, 0x468BBBF33293F799ULL, 
            0x9CFBDA91D564A7D0ULL, 0x71DBF9A7CB8B03C1ULL, 0x70DE63E84330B74EULL, 0xB39A2A4722206301ULL, 
            0xD4D154AD28872829ULL, 0x321E754B0A940F37ULL, 0x3D1A965EC214B776ULL, 0xED595384E7EADB17ULL, 
            0xA5068EA184B69DE2ULL, 0x33C86A121260CF53ULL, 0x58CD730EEB915C5EULL, 0x2B29E7BD300DBF81ULL, 
            0xBC95EE9D62702761ULL, 0xE2DB134FB50B3F72ULL, 0xBF154ABAC3061AEFULL, 0xB079AC1EC41CB105ULL, 
            0xABEA0ED576D2DFC6ULL, 0x7573B2AE46329442ULL, 0x7A4D2DAD6EDF4139ULL, 0xBD96598CB5944C01ULL, 
            0xEA5518DAC74FD823ULL, 0xF5550B027EDD79E7ULL, 0x883FEA50F4152969ULL, 0xDB7AD0B1FD72018BULL, 
            0x120CA5567C73F2D9ULL, 0x875183B374803F8BULL, 0x173484AC5B8817E7ULL, 0xB11903315C954829ULL
        },
        {
            0x09374645F4E9ACDDULL, 0xCCE1555F5F4E4413ULL, 0x695A0D7F421A8D6BULL, 0x262A6D558BEC0413ULL, 
            0xC4158F013707D00DULL, 0xA81EA9934AFF60F3ULL, 0x7CBFEBDA4C43F0C0ULL, 0x984D89DECE6491C1ULL, 
            0x390A1FD5435E812CULL, 0x4CA4B774F77F1525ULL, 0x14FE9E377DEBF818ULL, 0xDF0E1AAE25A2BE84ULL, 
            0xBD8F87710B14D16BULL, 0x2539753C3C965B8DULL, 0x7DF81AA437750BE8ULL, 0x56CB081117F09933ULL, 
            0x8EB398BBC4BF5F8BULL, 0xA1CDB1F9859A6E5CULL, 0x0ADDDD40FE752D40ULL, 0xE7E8E73DF28F524AULL, 
            0xE07AB16CB9E4F03FULL, 0xFE874E0B5C339990ULL, 0x34C5C70B005F92A9ULL, 0x9223ADB790BD66AAULL, 
            0xEC14CF1E41C960CAULL, 0x2C88957A6CA1358DULL, 0xF532236576B17BDEULL, 0xC83D9BC3D7C5AC30ULL, 
            0xD22372AC67A7A1BAULL, 0xAE03C9273370CB06ULL, 0xCBF76453BD0E7CB8ULL, 0x0618D90E28272316ULL
        },
        {
            0x805BF79D4D49F576ULL, 0xE68C21A7F4E2E2A5ULL, 0x908A867582C05E48ULL, 0x50108E72A92A2DA5ULL, 
            0x7C8350158B165D95ULL, 0x599BA469D2FE8929ULL, 0xCC7B01E7AD85F3BDULL, 0x2E6EBC63D358A503ULL, 
            0x4C375BF261210B1FULL, 0xAB34E424AE970BADULL, 0x1B3AB2A43C817174ULL, 0x3EB9FFC9BC3C3F72ULL, 
            0x4735DA3E45E40D78ULL, 0xC495C74BC5E6E1C6ULL, 0x36B7477E0D1D6808ULL, 0x9545C088C01CE540ULL, 
            0x0C21ED73EF346BFBULL, 0x8F858CB735FE6547ULL, 0xFAA03F9E75DDC471ULL, 0xFDE29448ED335C2EULL, 
            0xD130888A08EC01ADULL, 0x269C0EB1D052CC61ULL, 0xC6E76692810CE080ULL, 0x5C6E74B8E3FF8455ULL, 
            0xECFC9B6B7A701C08ULL, 0xCFD4A262BFAB9246ULL, 0xAD6C0FEC6F203D3EULL, 0x552F0A285E95B666ULL, 
            0x4CE9B2098DB6A13CULL, 0xD4F51528C8316F72ULL, 0xB3C6BD437E1C1E0EULL, 0x1673CEEEBF30EB9FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeySpawnAConstants = {
    0x0ACA349DE9E6F83FULL,
    0x831DCC054C240503ULL,
    0xD1ABE1DC1CA9112DULL,
    0x0ACA349DE9E6F83FULL,
    0x831DCC054C240503ULL,
    0xD1ABE1DC1CA9112DULL,
    0xF42A72F1A28876D0ULL,
    0xDEE57BB7E40338F6ULL,
    0x21,
    0x08,
    0xF4,
    0x8A,
    0x8E,
    0xE4,
    0xB3,
    0x38
};

const TwistDomainSaltSet TwistExpander_Suhail::kKeySpawnBSalts = {
    {
        {
            0xA40204C67C654D3FULL, 0xE3A9391E3C71E9F1ULL, 0xFD115A0A25ABB10BULL, 0x4F1B1A3E24F34065ULL, 
            0xF02847C6EF081231ULL, 0x17BCF1079C7176DEULL, 0x2F14865F2CB29859ULL, 0x4A25FDA3B0DA5773ULL, 
            0x048EF4DA4A2C74F4ULL, 0x5F4529BC345C544FULL, 0xD55BCC790A80C504ULL, 0x1ED57F196C709082ULL, 
            0x6D6AB43BF98114D7ULL, 0x0A105FCBBE0EC04CULL, 0x0E61840CD32C2C2FULL, 0xD8845FF35F641B80ULL, 
            0x7A90555E2AE34D8EULL, 0xE52DCEA998B44131ULL, 0xD05FD9165A7402F9ULL, 0x6A30AE56277560E5ULL, 
            0x3DE7A4586E6AC130ULL, 0x2971F21227089B04ULL, 0x60A4C95896266DC2ULL, 0x4D01F7687051803DULL, 
            0xC24EB3C282849482ULL, 0x22F049A91FEEFFAAULL, 0x47167C4148A61845ULL, 0x4417A3EBCB45F148ULL, 
            0xEE607EEBC57FE28AULL, 0x72A0B908530FBB4DULL, 0xD0CF2CD0329AEDE1ULL, 0xE531B58FD15443DBULL
        },
        {
            0x7D7DB65FD39C37ADULL, 0xB9EDBAF529301839ULL, 0x0C3CA00527AA830CULL, 0x418EC46864738646ULL, 
            0x020CA0B3D4C4D3B0ULL, 0xB3C6076BF1108343ULL, 0x0E65B69F50A6C967ULL, 0x0778EA5E26F42219ULL, 
            0x58E213C34B46BC25ULL, 0x8382AB7CFD9F8192ULL, 0x1221FA379D2A16ABULL, 0x75BEA7791880B003ULL, 
            0xB84C867B358FAE81ULL, 0xE68D9C5811FF5A78ULL, 0x7B285574D7A879E8ULL, 0x429FFD4E0A8D1DFBULL, 
            0x2EA5D09F07382EE1ULL, 0x1B811AD92B734CF7ULL, 0x7FCDD71F09DCD56DULL, 0x245434C63AE23E02ULL, 
            0xA7597966936504E7ULL, 0x0B3F74C55651CB92ULL, 0xE6320875A70D2B24ULL, 0xD88401CFEE7B0DFEULL, 
            0x73F68145A962092BULL, 0x252B609513085CB8ULL, 0x517A385F71F977CEULL, 0xFDE950F1C2619BE7ULL, 
            0x3DFD41F8CB01BEE0ULL, 0xC1FCC0E49F308CDBULL, 0xEAACBAF4E0821913ULL, 0xC8FF7696E764CB49ULL
        },
        {
            0xA483A99B324D5972ULL, 0xBEB717EBEF855054ULL, 0xB79CC8EFA4038769ULL, 0x72FD192902570F0EULL, 
            0xC2F4DB30E2CA96B4ULL, 0x91EF5229CED27B84ULL, 0x53867474F489D41EULL, 0x4F80DEC2B732AF33ULL, 
            0x11D9D869DE878C10ULL, 0x6BD9C6234DCB095BULL, 0xCAC0B1684200DEA5ULL, 0xDD91DBB9D7917E8FULL, 
            0x00418AD824647E32ULL, 0x0C16D12FF414B6AEULL, 0xFCB4279F671266A6ULL, 0x7A6F1BA64EB7CB9DULL, 
            0x2F89C06F84470FF9ULL, 0x2FCE9AFCE5794726ULL, 0x93DA8439A19A55AAULL, 0xB70FF9DE44758F01ULL, 
            0xE5CC7838C5F242D6ULL, 0x6FDF1383694191A9ULL, 0x8487925D9CF70733ULL, 0x101F8C4BA52EDC58ULL, 
            0x51E2E42E0B057483ULL, 0x26E7B077936F5A97ULL, 0x512A21BE6E261983ULL, 0x1588E71D83BF8A25ULL, 
            0x5639F9F8683EC7E7ULL, 0x87F54423E8E46296ULL, 0x556524B32AACB423ULL, 0xE0532FE6E9C8AC76ULL
        },
        {
            0xCE7CA6F6E44746A7ULL, 0x6490EB11C4B264D0ULL, 0xA41D809251D8F0E3ULL, 0x58BEE996A537D537ULL, 
            0x123C838389B48E47ULL, 0x0160636A54442919ULL, 0xCD5D0857B582C639ULL, 0x08CDDEEA47762486ULL, 
            0x967B9C054130D59EULL, 0xCAD8E0B923249158ULL, 0x42687783BB5A2412ULL, 0x203643A44D3F6B9EULL, 
            0xEBC11E79AD11ADFBULL, 0x77A1759ABD396664ULL, 0x08370E28D61E152FULL, 0x9B3617F806A06616ULL, 
            0xCF30CA1CE4032E8BULL, 0x87F0B754FC214A59ULL, 0xA9DAACAA76017B35ULL, 0x263E98E7943E0006ULL, 
            0x2D270ABC572779D2ULL, 0x350C3C7B0D4225FCULL, 0xA620442B18FACF0CULL, 0x41DC40EEBEF36576ULL, 
            0x2F13F91848196FDAULL, 0x93B827B611F8E4ADULL, 0xDB7CEA123EA934DCULL, 0x82C59BBC52E0FCE5ULL, 
            0x2548FCE64CB992ACULL, 0xFD4EA1F3B934105EULL, 0x1B2D28B1EBC6F106ULL, 0xDAC0C24AE555AF90ULL
        },
        {
            0x55CB579AE523559EULL, 0xD89AC19A3F2FD041ULL, 0x1102D45123E42C7CULL, 0x4CE5FF954FB3F8BCULL, 
            0xB9AB591AE64C5B59ULL, 0x984F9328878A90E9ULL, 0x3D55A3FC496D6766ULL, 0x2396A2D0642E1D0AULL, 
            0x4EF5D39A67F8B645ULL, 0xECF48EAB22543E90ULL, 0xBF37549D5E9AE1A7ULL, 0xD232D3F791DD9734ULL, 
            0xBCB4CC1ED334C56FULL, 0xA540A61C1BA7BDE9ULL, 0xE585658F97AD1B20ULL, 0xC3DF6B6FBCCB0ABFULL, 
            0x884F73D7B6EB206DULL, 0xEFB2283D37CFA0ABULL, 0x947489DEBD653EFAULL, 0x324D0AA18DE4D157ULL, 
            0x042283C162FFEBE2ULL, 0x860390BF46AA7F4DULL, 0x0FD04ABA6062B8F5ULL, 0x1B3897764ECC204CULL, 
            0x784816B322F0F63CULL, 0x52516C4295E02773ULL, 0x4A1ECBF67C90C6BFULL, 0xC3EF653484A52200ULL, 
            0x4519322D2F5B1C60ULL, 0x4B88C0B30ED27AE4ULL, 0x4EA9BBC77DA9D4D9ULL, 0x992D4409C01292BFULL
        },
        {
            0x641782477FC373B8ULL, 0xB47E5F3F34EE8AD3ULL, 0xCAFAB4F33E86B5A4ULL, 0x9C7AA0A017DB8136ULL, 
            0xC3E450690A6F1B95ULL, 0xDBACB7B20E4341CAULL, 0x749CF8980A4E50CAULL, 0x42CED2960E261194ULL, 
            0x50F59658FA1C79F0ULL, 0x1F16D3AF2F894C24ULL, 0x81F4309282E8B08FULL, 0x6A57B1CFBADFF5C8ULL, 
            0x51AD1BC78086F150ULL, 0x382C579803161E33ULL, 0xC37B900A040CC4B0ULL, 0x0C8BE6D6BEFBAA44ULL, 
            0xDE905A4D0C84A8ECULL, 0xC4737B43EE1D9EEFULL, 0xEE770F02F2C82C66ULL, 0x9F0D6794830DBFC4ULL, 
            0x410AA5CD66FE8304ULL, 0xC68FB66F377F1F73ULL, 0x09A98702AA5FB468ULL, 0x02B331D1910CA514ULL, 
            0x7B8D932BECB53369ULL, 0xB45822289C2F7E57ULL, 0xE16DEA40F55FC4F7ULL, 0xC1DEE32E4D4E3BA6ULL, 
            0xA74D665A44B34C1FULL, 0xA7930C2679B078A3ULL, 0x7CA1612A57E09CF5ULL, 0xC2A1D4A5BA630AFEULL
        }
    },
    {
        {
            0x5556FEBE97E07473ULL, 0xCAC510C7F0143B1EULL, 0x8808B4E74A8E7A70ULL, 0x2FA82C77775A758CULL, 
            0x772D489198DD5296ULL, 0x36105410B9EF38DCULL, 0x347744314D6EBF10ULL, 0xA277A1CE908BF4BEULL, 
            0xB5E15431087781C9ULL, 0x1FC8D63A606DE045ULL, 0x244CF2DBD153177CULL, 0x91C74ACC7E930819ULL, 
            0xDD4A061A7437E43BULL, 0x0476DC6F129F4712ULL, 0x576822C9B894C321ULL, 0x0F4EFDD84B36B47CULL, 
            0xDF1FED0A183281F2ULL, 0x621DDA24ACEF6065ULL, 0xC8A766AD93F4A7DBULL, 0x3FE223F8331EBD5DULL, 
            0x73DECCE5B9D84C53ULL, 0x0064355DD65828F0ULL, 0xDEEBABCA2272653AULL, 0x4E24D77B1BC0885FULL, 
            0xFE15A48ACA5FC547ULL, 0x8C17FA1E22F2270AULL, 0x1A90A6581C33F5CEULL, 0x60887EC463248C37ULL, 
            0x628B5BBB536BF7C6ULL, 0x1321ADB4D44D48BDULL, 0xFADF5447ACDCF6F8ULL, 0x51EDD732148C44DBULL
        },
        {
            0xEC2E93A2EE31C58EULL, 0xAD5FD9B0AC7EF31EULL, 0x4574F2D44812CC54ULL, 0xF583B99424922AF0ULL, 
            0xD0817F4E08457537ULL, 0x9139703516160A75ULL, 0xF7F5584D38A92FD3ULL, 0x538A416BA89E178FULL, 
            0x718E96C4BADE4863ULL, 0xC1F538D295FB9236ULL, 0x2BFFA5CF8827A18FULL, 0xAEA2971F2C51EA20ULL, 
            0x0072E318E7DCE1ADULL, 0xA5D63C8F2EF8558CULL, 0xBD77639B4161D22DULL, 0x6B0B38A39483D3B2ULL, 
            0xBBDF598BCE9DD037ULL, 0xB9285720EE55D45FULL, 0x2A0B37BD24570B28ULL, 0x3BC47C51A6353B0DULL, 
            0xD587859FFD85D95BULL, 0x0C150F0D742354E4ULL, 0xD9098E574020B757ULL, 0xDAF4412F6EA2F42BULL, 
            0x4BEFA85863F864BFULL, 0xEB3A7C2CDC497853ULL, 0xFE9E58922602D9E9ULL, 0xA8FD648F297306EDULL, 
            0xEB3D232614AC7B81ULL, 0xD2390221A50D9F2AULL, 0xD09E16E8411516BEULL, 0x1E889189EA1D3189ULL
        },
        {
            0x1586A14F83EE851AULL, 0x0E65FD92472107C7ULL, 0xDC769CC9AFFE4D17ULL, 0x9BAFA9187581E357ULL, 
            0xAA55BC38757D423EULL, 0xDDBE39D64291EBE2ULL, 0xD5C64E7406E2CE22ULL, 0xD80790574E4F46EAULL, 
            0x37BDF8BB8A82C61FULL, 0x1B6BA51C2C1D1874ULL, 0xCF6AA7949B2A24BFULL, 0xFD8CEA8ABF0B5139ULL, 
            0xB864F023026F6E30ULL, 0x5EA56059FAEAC6E1ULL, 0x3D5B9A69E14D46C3ULL, 0x3181CADDE81206E4ULL, 
            0xC1B9FEB0E74439A7ULL, 0xF93294AA7DC096DFULL, 0x06A0CD0632A93910ULL, 0x4EB8C6A892823AB6ULL, 
            0x0F2473AD81FC9022ULL, 0x740144E796EAB636ULL, 0xDAA75174246E072CULL, 0x0D96748760833943ULL, 
            0x381695D334DA2559ULL, 0xC95C81D2E6FB88E3ULL, 0xD2217F9D0D7D7F65ULL, 0xA1FA2B22CE0AE9D0ULL, 
            0x4F7CDA7ECC61688FULL, 0xCDDFD3608D8BA706ULL, 0x865BD84DBD220CCAULL, 0xE0558CF2FD8F8B70ULL
        },
        {
            0x8E06E0C14E13887FULL, 0x006659B01E766D8CULL, 0x792126950D0C7521ULL, 0x6867C1D554DAC7F2ULL, 
            0xAABDED9EC56B2B65ULL, 0x6F35018247F806F9ULL, 0xACE38EC76F030506ULL, 0x83A05B2942551CFAULL, 
            0x5C25D2BBB14D9DA7ULL, 0x6388667691627258ULL, 0x124A0267E77DDA67ULL, 0x7B28D6011C7C35DCULL, 
            0x75A898CCC00B4EB2ULL, 0x681CE380ECDA5254ULL, 0x542E987AEC94AA15ULL, 0x5E9C3952197C1AE4ULL, 
            0x591A81DD899970AEULL, 0x0234BAE2A407397FULL, 0x0D46466D78C0BC28ULL, 0x13D6B6860C05EC01ULL, 
            0x42979660B7F5FDE8ULL, 0x0C22CFEDC590A85AULL, 0xEFAA80A5E9032672ULL, 0x1222282A2557C38DULL, 
            0x099BF0F60D207A98ULL, 0x329B5E48E4AFA9E4ULL, 0xB67A00AD185CFB7DULL, 0x8ED7B7EAEB8D5EA0ULL, 
            0x5F4BB9FE6029794CULL, 0x1A240C59FA45231EULL, 0xAD6B30B9F958FE61ULL, 0xAFADA8F8F6864577ULL
        },
        {
            0xA44FB663451B2BF4ULL, 0x45F8BE5E76F97DA9ULL, 0x8D88FDA0F7F81098ULL, 0x5AB1D52294D7B90EULL, 
            0xB5CCF8D7BE1B45E8ULL, 0x56E6EDCDB24A42E6ULL, 0xBA80346E3680FBB0ULL, 0xBA900244567C541AULL, 
            0xCA6927557255181AULL, 0x13B57E1E6476518BULL, 0x11711D0F8C9D7572ULL, 0x3D229C6939B1C532ULL, 
            0x0B51C6C612C64774ULL, 0x5684AF0ECEEFC6CFULL, 0xBC72ED545E6D4A67ULL, 0x017B75E20523E367ULL, 
            0xBC869C7441A1C156ULL, 0x8B22A531A732222BULL, 0x934D25DB72F982F2ULL, 0x07BE5DCC4F1B45F8ULL, 
            0x30624A8D8EA41247ULL, 0xC96D84D78B8EDC7CULL, 0x383EE3F7CBD18DE0ULL, 0x918C7546E8E285ACULL, 
            0xA475B6C7F8C15868ULL, 0xB933F03A0FFD7129ULL, 0xA3065C4C5E1722C6ULL, 0xC44AC0FAD0EEA992ULL, 
            0xF17EE7FB7123205BULL, 0x45F62E12C7F9150FULL, 0xA1030803642803BEULL, 0xCDC32793D700CA7CULL
        },
        {
            0xB629A9B503D4042FULL, 0xFD9AC22AE9AD7BA9ULL, 0x1C5CFF8D96B8857AULL, 0x0F86D759B73DF245ULL, 
            0xFA73F0CCFE5585FCULL, 0xDD153691780BD67BULL, 0x450780B9A680C3B6ULL, 0x6A526189655A072AULL, 
            0xE4608C33F76B9BB4ULL, 0x245CBC2AF0747A50ULL, 0x6ACFCA20B87E6520ULL, 0xD11D87C0F4FE9BB7ULL, 
            0xADEAD56B8DA6E204ULL, 0x887F1F82FC6FE094ULL, 0xD09C05BB7AA7544CULL, 0x28E4762162E05A1FULL, 
            0x0747B4D3F01A7B13ULL, 0x3F47D3F310A0B0C1ULL, 0x0877573001EAA1B6ULL, 0xF6F2FB3B3F6B09A3ULL, 
            0x4326FD8A20E811D8ULL, 0xD6AFB81A71C10B83ULL, 0xB237F503E5E22CE9ULL, 0xBE6426E2D5D79CBFULL, 
            0x55483C52B068DBD7ULL, 0x7B1498A5E4FEEA39ULL, 0x637A230A7C949748ULL, 0x9AF3D8677E22D35AULL, 
            0x75F000FE04A5A4D4ULL, 0x6766A154C55A094BULL, 0x578E54C40BDC0598ULL, 0xC73CA15DE8563475ULL
        }
    },
    {
        {
            0xE93CF8D4217F18B1ULL, 0xBDBEE89C3F05922CULL, 0xBE7DE7DA654AB6DEULL, 0xA4E764231BFA4F66ULL, 
            0xAC6E922F3AE10A1AULL, 0x65E75FB5AFFBB1A4ULL, 0x7E58EBB7A6C08292ULL, 0xE039671EC65EEF00ULL, 
            0x6D4A09B9C4BBA2BDULL, 0xBCF70375F294F538ULL, 0xC32ABF781A234FBBULL, 0x98898D5ED5010F49ULL, 
            0x736114F8FA2AB1A6ULL, 0x44A61563A61F0D01ULL, 0xE6EA8BAEBDCB469DULL, 0x5FA343D28AAFABA8ULL, 
            0x1253B1925EA25415ULL, 0xF473E6D21047111CULL, 0x593E7FB5709907E3ULL, 0xD18D934DBB67C3E7ULL, 
            0x41477D6459214AEDULL, 0xABDD7E1B770D33A2ULL, 0xC5BAD96CBD67B063ULL, 0xA52847537BA98023ULL, 
            0x93E8149F096D6A0BULL, 0xB409A3EE06482BC8ULL, 0xC5DB017446473E11ULL, 0xE1898933ADE55F14ULL, 
            0xF9370A64A4A042F3ULL, 0x5D1E6FD091FBA5FCULL, 0xCE5D99A5DCEE23E6ULL, 0xDF0D96C9E8FA1C7DULL
        },
        {
            0xD06E26DF2B76225AULL, 0x516FCF2F97EC6023ULL, 0xBEA3D9C839337F48ULL, 0xBDEE1E5569F71883ULL, 
            0x4B3F854383C75C5CULL, 0x2C68789A1DE23AF0ULL, 0xBC7B69C3CEA91212ULL, 0xAFA68CC0FE1FC2E0ULL, 
            0x464AF4971B332F5BULL, 0x3C6FDCAE1D77AA48ULL, 0x0D38EC4CA53D2961ULL, 0x610B62EC3B61B53EULL, 
            0xAB6D1B91EC77DEE1ULL, 0x49467688338B3E96ULL, 0xED33C390E27C4C62ULL, 0xD0D07E54DAD36549ULL, 
            0x7D4152DF08CE06A1ULL, 0x2DEE54CA29165139ULL, 0xF9AC122E09840F13ULL, 0xB921638E2ADC0ECBULL, 
            0xBBE9B2174736A856ULL, 0xE6D32DEF6F870EB2ULL, 0x69D7B84D127B48B4ULL, 0x83D4F9A3F068DA43ULL, 
            0xC4D1E666A5BB643CULL, 0x055D84B8D559760FULL, 0x18740EB6DBAD73C2ULL, 0xB17F31F5B05D9A49ULL, 
            0x5DA8443D35B6E277ULL, 0xD00923EF81D16BA9ULL, 0xC5B7381A7688AC2CULL, 0xF6F572AB28916E53ULL
        },
        {
            0x36899FC0EE1C8CCCULL, 0x1797CD4A68C64A13ULL, 0x9CFAB157D428C731ULL, 0x45E3A85EFC062E52ULL, 
            0xCB878F587414D728ULL, 0xAE2B631BBA10D8F8ULL, 0x99E8F45B245DC9BEULL, 0x9AEE83B5CA487E04ULL, 
            0x7A9F588522EB696AULL, 0xE706CE791F7C5D99ULL, 0xD2067CBCCA10F017ULL, 0xFB3422397D3C0573ULL, 
            0xE4930BC7847C1E53ULL, 0xF9F5E678BF0FF6DBULL, 0x79789006D323E9F7ULL, 0xBF03C8244A24477DULL, 
            0x7DB6FD5C5697931EULL, 0x4091CEA9CE054E71ULL, 0x9EE6C4C0386B2E27ULL, 0x5FCF6E84831837AAULL, 
            0x1B107D01ABC73587ULL, 0x7F736784112C9662ULL, 0xF5A895CAEBAD8136ULL, 0x5873A70973B978E6ULL, 
            0x0946FA15EE49C4DBULL, 0x32B84C28C451B3A9ULL, 0xEB2A16A61BA0F11BULL, 0xD096849C8D2C0ED7ULL, 
            0x8FF3DAD875002207ULL, 0x74510C6F8B64C0EFULL, 0x62AB505998125D5AULL, 0x5334B69610512C25ULL
        },
        {
            0x93E3F6FE13EE0248ULL, 0xCFDC659AEBA5ACE2ULL, 0x0F9C7DD30BE5858BULL, 0xE2812B240B9F9053ULL, 
            0x48F3654F1F71C3A6ULL, 0xB1530F8EF7B7D2DCULL, 0xD22E58113D3F09FDULL, 0x5FC22E80C857C394ULL, 
            0xD5F882852DFFE214ULL, 0x23B120A1B07E34F6ULL, 0x2BAB85E9CE0280C9ULL, 0x589A5FCE167B4E9AULL, 
            0xF02573F7C2D76548ULL, 0xB57B33CA9C2DDB98ULL, 0x435FBD01AE8F7942ULL, 0xFB59A053426EA7AEULL, 
            0x4A4A8DD8665F6885ULL, 0xC45D7085E3F0DECCULL, 0x437689A5CB0BABB3ULL, 0xCA9274B805080888ULL, 
            0x7D1F0F183CABC9E6ULL, 0x96B1D43C23D76B62ULL, 0xB9E12F9F86D4A819ULL, 0xD7F13E9F510A2DDCULL, 
            0x6E510A9C42079E0DULL, 0x665BFDCA16EF32BCULL, 0x94BEEF7133D02F48ULL, 0x53F7D7C4AEBEF394ULL, 
            0x5781C6F788C88AB5ULL, 0xBB469565280963BCULL, 0xAEA40FFA24B4C82FULL, 0x1DE7DDE0547AEAC0ULL
        },
        {
            0x88CADA4EA9174349ULL, 0x36245A10689D789BULL, 0x164966E5147DB05DULL, 0xEA2CBA237EA76C9EULL, 
            0x94A1327BCD9761FDULL, 0xA1B8D9913F3D1242ULL, 0xE3A1544102FB7331ULL, 0xBE5A132B0B905E13ULL, 
            0xB566A5CE2F81C3BDULL, 0x14FFC55C50E158F1ULL, 0x1B07F9285C479268ULL, 0x7E609399719EF0CBULL, 
            0xE6C19F0437FBF28EULL, 0x5AE01EC34529F90EULL, 0xCF6ECFCF61DFB972ULL, 0xB862FBEA7BC4F239ULL, 
            0x7F7F1D9D74D28F07ULL, 0x6491FB862FA63FD1ULL, 0x756877EE6326C004ULL, 0x8039D37B716C4805ULL, 
            0xF7A395E9EF4FB729ULL, 0x76B5578CF90D579BULL, 0xD129761BD25CCB0CULL, 0x91861DB7534E3201ULL, 
            0xBF7CFA90D2790950ULL, 0xCBE14DA4296EF450ULL, 0x8B24F7CA43B6E71FULL, 0x0E0CDDAA1B9BE900ULL, 
            0xC8F955BBC3975B6CULL, 0x2EDF8167F7E88CA7ULL, 0xA34D3868802B31A1ULL, 0xE6604DDDDD0D9695ULL
        },
        {
            0xD7C9D59F31E6FFA4ULL, 0x7D4638A504A268A5ULL, 0xA0E8D784F9932CCDULL, 0x8D1CFDDD34FF094EULL, 
            0xD5A5557246DC0F83ULL, 0x6BC6D948F31AC9D1ULL, 0x6AFDABC8E8728FE1ULL, 0x7B3794BB06B33CF3ULL, 
            0x87175D4CECE88AFAULL, 0xB34B7C98A164F0ACULL, 0x132BC731C6960E29ULL, 0x06DB61079E52CDA4ULL, 
            0xE60789FFBB48FDEAULL, 0xDB0653ABD9EDB29FULL, 0x1E32CD03AF61B2ABULL, 0x6106D53F9D90E722ULL, 
            0x45642761BFE8286EULL, 0x3BD263AAF7B7C8C8ULL, 0x16C710ACAFEEE154ULL, 0x612FD28484B3E367ULL, 
            0x741EB8C5E6D20574ULL, 0x23A9AC28A4198F67ULL, 0xE5A2654EAD2704BEULL, 0x18C98206F55C5857ULL, 
            0x2D419156EBA64688ULL, 0x04CC3BAEF276D149ULL, 0x3EF7780A77721A56ULL, 0xBD4644072E47BBB5ULL, 
            0xD495FFE24F2ABC4AULL, 0x393032430760CC03ULL, 0x7FDD09DF013B4653ULL, 0x6F0276A3649BD3EDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kKeySpawnBConstants = {
    0x634114607055B8E4ULL,
    0x3572BFD16CE39800ULL,
    0x943973E998D663D7ULL,
    0x634114607055B8E4ULL,
    0x3572BFD16CE39800ULL,
    0x943973E998D663D7ULL,
    0x4F804A70C9DD815AULL,
    0x15907F712702D043ULL,
    0x6C,
    0x20,
    0x7B,
    0x16,
    0x44,
    0x54,
    0xE4,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Suhail::kSeedSalts = {
    {
        {
            0xCC6B6E02BEAC04DFULL, 0xB33DEDFA550B636CULL, 0xD9F11E25DE961928ULL, 0x445E452C905AA4A4ULL, 
            0x873C6CD9B2D45AB7ULL, 0xF43CB1E28BCD8469ULL, 0xC5C7B16A557D8369ULL, 0x7C3574557DFF005CULL, 
            0xA63BA8C10F09B256ULL, 0xEF3E30F48AA6706AULL, 0xEF25C5C3E8CC3C00ULL, 0x225E59C534D6B07DULL, 
            0x696A94E28153787FULL, 0xA53F3167EA5185FAULL, 0x28BD34A40A8C5761ULL, 0xA7253BFCE4B57B0FULL, 
            0x084CD963E16E1F5BULL, 0x718F776E4D1AB54DULL, 0x6D6FC8D58D079C32ULL, 0x4427C6049C9C4772ULL, 
            0x0EC33A7CD9E92F45ULL, 0xA0A3A899A894F7B3ULL, 0x91812A4B779F3DCCULL, 0xCFD1462F48E40DFAULL, 
            0x0A52DB4DCAE72349ULL, 0xE52D3E44066512FFULL, 0x46C090435754E40AULL, 0x69E3A92DC72863E2ULL, 
            0x8B70A4185AB4E526ULL, 0x5D7E44557DEC1B94ULL, 0x4AD65F68B928E900ULL, 0xEB4B48852738DA1FULL
        },
        {
            0x5E3DFFB317BB2943ULL, 0x77A426A3D9F9E9F2ULL, 0x17CE92DE795AEC07ULL, 0xF3EDD0D99AFF0E5CULL, 
            0x7B7A85176C247CA7ULL, 0x5AA8F052E7111218ULL, 0x9C3B28F7D770A2D3ULL, 0x5AC5D2F87B0E9358ULL, 
            0xB1182230ACB3315FULL, 0xD79290B5EFC09FF3ULL, 0xBC8272B4CA1C46E3ULL, 0xF25DB575D51A7B73ULL, 
            0x6E82571CB7AC49FBULL, 0xC89BF5C37BE8E59AULL, 0xC7A09E91658B3E02ULL, 0xBF0643A5C841DBB4ULL, 
            0xAE40A1A31080B105ULL, 0xAAF58A0014E7DD78ULL, 0xC0C2F776D691F34CULL, 0xB96BFFCCB8E1444AULL, 
            0x8D803036C86AC82DULL, 0xBC350AA022B95560ULL, 0xDD23036F418BEEA8ULL, 0x290CE745BCF87A48ULL, 
            0x6AF8D3274D556F2CULL, 0x067706E310E45975ULL, 0x24648B28745F387AULL, 0xFDFE846CF4C9DF94ULL, 
            0xED7B73CDA2E4D958ULL, 0x3E21C83F1D8E76C7ULL, 0xC29BE80163F18C25ULL, 0x45538351CDA85479ULL
        },
        {
            0x24EC95561A4CDD92ULL, 0x8C155F8C55D9F332ULL, 0x4FE79D57CD7E5C8FULL, 0xCF03C5ECE1266A67ULL, 
            0x0CFD13AAB37B070DULL, 0xCA3762E289FA8920ULL, 0xBC52CC998B271FF6ULL, 0xD5DDA7FE9B7AC40AULL, 
            0x654119F823E2A24AULL, 0xFF7056D2676C0959ULL, 0x95834C08BA386D61ULL, 0xC3B087022B203C9AULL, 
            0xCF275EBFCEBB6401ULL, 0xB4D60CD20930A2BCULL, 0x7D79C2418255D53AULL, 0xA4D75B330D187669ULL, 
            0x68B6E650F7CD941BULL, 0x8DDC74A0705DF92DULL, 0xE747E45E2FF6A6E3ULL, 0x31AF62D022DA2165ULL, 
            0x13B0AE00F6A5659DULL, 0xB7A2C91BE2E76CB3ULL, 0x57EA9277AABC8DDBULL, 0x1AC834C072B6777FULL, 
            0xB9DA66F052D9DAB1ULL, 0xA430472CEC6AE427ULL, 0x4EB8E8458CA131FAULL, 0xEE0D154BD0BE3340ULL, 
            0x8769AAC87EC97FFDULL, 0x6C40727EFB8735C0ULL, 0x4B2E2136D0ABC5ADULL, 0xCF813311F3ABB639ULL
        },
        {
            0xA9DF25D620B22B37ULL, 0xC1A0E50CA2ABE67AULL, 0x263B3D55DBB6CB9CULL, 0x79617A41AA6FD0F0ULL, 
            0x98C1BA32D5125126ULL, 0x38A1843CB848F5AFULL, 0x9AC1034A9D4D769EULL, 0x01880A9067587A30ULL, 
            0x88EB698E35ADD411ULL, 0xF4EF14D7CE8C334FULL, 0x47A145B2968A9187ULL, 0x115F8FF6565F91D4ULL, 
            0xA6CC1C9049D8622EULL, 0x19D7815E4565EE0CULL, 0xE987DDEA31BF47FFULL, 0x3EBB25C02BE4FE2FULL, 
            0xFECF36FA719ECBF9ULL, 0xBDB76AEBC418B388ULL, 0xE28BA603D0C1573AULL, 0xCAA7D02CCFE6D3F2ULL, 
            0x6CCE91FB257FA8B6ULL, 0xA8462D667FB66A9FULL, 0x9673FF75042019E6ULL, 0xB6FD11816ABEB3A0ULL, 
            0xC89865549CD15C15ULL, 0x67AF408281C8BF7FULL, 0xB06FAB651DE5F97AULL, 0xE3A5A3BDCAF1C0BCULL, 
            0x769C69386ADC0DC4ULL, 0xE4A0341C4652EFE6ULL, 0x92B763A03B1BAD96ULL, 0x27AB0E741100D206ULL
        },
        {
            0x431E228C798A9400ULL, 0x9C08A17E209FE6DBULL, 0x14BA9D7B06261F2EULL, 0x63F1340A80BD8CA3ULL, 
            0x897BC1B7BA081C89ULL, 0x2A5A426D52566B9EULL, 0x77B845BE3A21349BULL, 0x3175D5B13EC3C6FEULL, 
            0x17EE6F88D5A82C86ULL, 0x6B8927281078C149ULL, 0xC9555ECA326457E5ULL, 0x8149FABC4C218D3EULL, 
            0x738C24A069B1D104ULL, 0x1E8B4A9C85F85811ULL, 0xC4BC6FC37E8517CFULL, 0x06F3D347D4C3F3E4ULL, 
            0x08BA2D389CC76E62ULL, 0x95659264CDCEFD27ULL, 0x26729924E3EF04C6ULL, 0xC0B5398CB0BB6860ULL, 
            0x81D2DD3C5482C392ULL, 0x53BE1F24D270BFD6ULL, 0x903B21E51767DEBDULL, 0xA66A01973DC72171ULL, 
            0x5DECBF11D74ABF50ULL, 0x81AE12ABFEE89341ULL, 0xD020E393D05DA6B6ULL, 0xBED7547684DD1566ULL, 
            0xFFEA96F0A13D873CULL, 0x5C479D4F3F7486C0ULL, 0xCD6520BBB6A4FD91ULL, 0x502A10107870C6A7ULL
        },
        {
            0x6AA700B9AC7A2EA6ULL, 0x89912304C013D12EULL, 0xC51F5D46EDFDD99BULL, 0x5CBD093E9DEDA5CBULL, 
            0x0FD5C4BF05C123EEULL, 0x7296A2EA4A5C2C62ULL, 0x1ED4A2C8C1513833ULL, 0x6E86DB63D6CBABC7ULL, 
            0x916DC7E57FD24149ULL, 0xB847CAC5751442CDULL, 0x3DDF89A0FD77DD5AULL, 0x090A081268FAC091ULL, 
            0xE65F1E6107A19309ULL, 0x8C99D8EBCA1C407CULL, 0xFE698D5877481C82ULL, 0x9DCDD782EEA91F32ULL, 
            0x9D91E8BFFCA1D49DULL, 0xB92AD6AA0F6ED069ULL, 0x3EFB51571D4EACBDULL, 0xAC6E8C46DB32627CULL, 
            0x2B9CB4917430AFF6ULL, 0x5B5C03554FC9444BULL, 0x5A9428E3A1A7D1DAULL, 0xB95B63D637B54D86ULL, 
            0xFC6EF10A83126CEFULL, 0x87BBC6EB3EB3AF2EULL, 0xAFF6C2A0E807E799ULL, 0xC5ED3BBC2A843C8CULL, 
            0x6D6453B5BF601496ULL, 0x614033240B1DC3D7ULL, 0x6D8F849AB5ADD3C6ULL, 0x3AF2B01A332AC6D8ULL
        }
    },
    {
        {
            0xEB02D981E1C0A70EULL, 0xCE497B5BBA436FF6ULL, 0x46B2A8C08ACC6754ULL, 0x71B4A1B87523FD90ULL, 
            0x23D60E84CEE27D0BULL, 0xD054D3954DAF1B1DULL, 0x1C576970291E691AULL, 0xB3B49AC9C54ADAD8ULL, 
            0xEABE2D7B2A5EE6ECULL, 0xE3849EC6C6F70F50ULL, 0xABEA8553C9D24E6AULL, 0xAA22E38A1695E5B5ULL, 
            0x72634597390BDE80ULL, 0x7D3BE6F3AE5DF41FULL, 0x9A9DEB092137F5CCULL, 0x4755966AFBC2B531ULL, 
            0x2B386509E597A693ULL, 0x253DFF11FD4FCDECULL, 0xB8D76AB8EDEB4C50ULL, 0xAF69E06270768123ULL, 
            0x378AAC9BBA0CAC6CULL, 0x87DE9A0E20015927ULL, 0xDD875062EE121460ULL, 0x3D4364718577EB66ULL, 
            0x2810BBF261C53FCEULL, 0x7A9A5C0FE04B3837ULL, 0x025989A119D13750ULL, 0x3F49EB2AD511FAD0ULL, 
            0x1C3E9D2DE35E8E43ULL, 0xBC88C8EF5FDCAE41ULL, 0x76A38C22654DAE58ULL, 0xE9105D5B31B0DDC5ULL
        },
        {
            0x067F341E9331C2A5ULL, 0xEEE6074AEA9C10BEULL, 0x1E01B5E8EF748AA5ULL, 0xBD4D28E64C8DAD3EULL, 
            0x4F04AC595C6F94E0ULL, 0xA1A14D4C23C5A0FFULL, 0x3172BF5A29368C24ULL, 0x72C9DACC7FF13934ULL, 
            0xB43B7FB6E4D3F2C8ULL, 0xE8C83E776AD689AFULL, 0x967BEB69DE88D9FFULL, 0x037DEABA791F1967ULL, 
            0x804558193C497559ULL, 0xF1E055EB1056046FULL, 0xD00C24545BDC234AULL, 0x7FBF2DDF2B57B110ULL, 
            0x8BEBBAC012DF04F2ULL, 0x28161DCA8E19AB17ULL, 0x682DD60FD6A72F51ULL, 0x68BE8EA6A4927EA4ULL, 
            0x083BF82C51F63E85ULL, 0xA1BF0CF4088C8B26ULL, 0x11177CEE4B6D5C8BULL, 0x598A72003FC6E3C4ULL, 
            0xB480CB9AE5512322ULL, 0xC341318042A6720FULL, 0xA618E1E32A89BBBAULL, 0xDF37A687CA113ADDULL, 
            0xE2A7A4CE65C27264ULL, 0x2369E127001A3EA0ULL, 0x5C35F59B5635C13EULL, 0x4554E00787E1A71DULL
        },
        {
            0xD5F2AD930B16A593ULL, 0xFAF1358701024DF5ULL, 0xD8EDDFEE2099DA2BULL, 0x3158FA25FCD22D68ULL, 
            0x28F7DDCEBD30A478ULL, 0x7AD6C2DCB8AEF1B4ULL, 0xF9F5A7378539B585ULL, 0xBBE01EFE14EDC3FCULL, 
            0x3D270CC2DB243A8CULL, 0x2B197F8C4C94216EULL, 0xD52B51982552422FULL, 0x748A113E0E9B5C6EULL, 
            0x99F0B1071B4A7907ULL, 0xD3BB965585B64F99ULL, 0x9CD49AD2590A6A4BULL, 0x2D93905E3454BE1DULL, 
            0x1BE8B886F25B80C3ULL, 0x41BC0629721B85A2ULL, 0xDEEAB4A3A889024AULL, 0xC1EFD01C8D8BE891ULL, 
            0x1C31985C5A539247ULL, 0x121E8E4685D00187ULL, 0x21D1E93CB0D054FFULL, 0x9B0DA050E84BDFD0ULL, 
            0xA257360972D2F0E2ULL, 0xB3736AC337FA0D33ULL, 0xCAC61D21FEEA0431ULL, 0x42001EFFDDE13999ULL, 
            0x9C2E2CFA92625877ULL, 0x495AA783669328B5ULL, 0x0EE24E2112588BC3ULL, 0x401D102A9CF12AADULL
        },
        {
            0x9FC58BD60E418359ULL, 0x345872D133F910EFULL, 0x9E5FA3F1152229CEULL, 0x37D1F72E10799A56ULL, 
            0xFC4FF19338CEE352ULL, 0xB4F86504D90152A3ULL, 0x8739984596F6358AULL, 0x3C9D6C9B3786BE9FULL, 
            0x738E1C06FB5A584BULL, 0x50E6528261C5463DULL, 0x1BA8B12748EF5D48ULL, 0x29DEA30CFD69591DULL, 
            0x44CB7E2BB81DCEA8ULL, 0x624AAF1E6CCD16B2ULL, 0x10B52B4F9E477012ULL, 0x1138CF788E96715EULL, 
            0x394E27FDDF6CD487ULL, 0xC17D3B8CEFEE9E48ULL, 0x5ACC5811DFCA6D3EULL, 0xB8D708D6C5E4524CULL, 
            0x8BA858156BA49940ULL, 0x3A53C3816852725CULL, 0x3694EEA04BFD650EULL, 0xE9B77B0BD6CA4CFDULL, 
            0xC8EDE3E0DD3FC901ULL, 0x85608A01CD2677DBULL, 0x6949B43A413E8CDAULL, 0xD22DEA38B79988C6ULL, 
            0x3D7BAF3F521C2BACULL, 0xEC765C6B8A0B6496ULL, 0xF07544EF0011644FULL, 0x70200A3DC6060426ULL
        },
        {
            0x7D809A0863E5853BULL, 0x1DADCA891DB8D8CDULL, 0x2BD402F96C1377B3ULL, 0x2F4DD459C2916660ULL, 
            0x2319A79643E0F620ULL, 0x15E84F6B60AD4FA1ULL, 0x13D8805143A3E02FULL, 0x38A3EC282B7B474BULL, 
            0xF37116052AA03546ULL, 0x3A8598AF7FFADAEBULL, 0x8D9C66CB0FE0C690ULL, 0x0E7102793F13F3F9ULL, 
            0xCB5EF6013E1DE00AULL, 0x95C1EB199B176E0FULL, 0x10B167301A44FF19ULL, 0x33683B2C682CF1DAULL, 
            0xD36DABB957D309E4ULL, 0xE6856D65AB6E5903ULL, 0xDC2E1E62848886FCULL, 0x36BEE64FDBB76189ULL, 
            0x80AD8D3E36CD4517ULL, 0xAC8F7E26C60A66EBULL, 0xD2DF32718E5ABBCEULL, 0x623420D603C6EC81ULL, 
            0x1AE4A9257F86AA43ULL, 0x7C4B75D4651CF1D1ULL, 0x7ACCCF93D6626F6CULL, 0x6DE210891F59FE0AULL, 
            0x14783CD25B1F5659ULL, 0x412C5AC7A173E22FULL, 0xF72D13D18508083EULL, 0xA3B108928F4C12BFULL
        },
        {
            0x2280E588636135C2ULL, 0x7539D6F63DA7F8F8ULL, 0x5503FD6C919EE0DFULL, 0xAFB0E237678CC46BULL, 
            0x1B4554F494A1A4EAULL, 0x31C39411F0D70ABDULL, 0x1BEC8778927FF1DCULL, 0x1EC84654DD0A3960ULL, 
            0xD64E00993B06E7DFULL, 0x077434DC358BBCDAULL, 0x5807B40AF43171E6ULL, 0x3F4F1103FE404F50ULL, 
            0x6051131103D23F71ULL, 0x1A7836E838A83BEAULL, 0xAE1B1B2DF541683BULL, 0x2A4BEB78DE2CD361ULL, 
            0x93AE7FFA1D1D0658ULL, 0xBBCA53BC284F06C4ULL, 0x5D3A05365F85ADB7ULL, 0xE13FD0454797FA65ULL, 
            0x47FE2F7A623A6EF2ULL, 0x165121DE7BE19C47ULL, 0xBD374451ECB1556DULL, 0x6C84B2ABC995696BULL, 
            0x73EE5AC90A47C7C8ULL, 0x7D9C8DFB65B77C56ULL, 0xC78BEDA7A7ACD844ULL, 0x9A4594AE1F658991ULL, 
            0x5AD01288BAD71EBBULL, 0x96BE421963130117ULL, 0x2F73B1EBD726DD80ULL, 0x4B664651B9B2E75CULL
        }
    },
    {
        {
            0xFD22AACCA8A75EB1ULL, 0x6A002575A6FB8352ULL, 0xCF00A90312847FFBULL, 0x78F47E8B2F6AB8A7ULL, 
            0x178405DF1DB5E4BFULL, 0x3CE4DB6964053F7BULL, 0x4339935B2B20DE45ULL, 0xE4943A18A5DA292EULL, 
            0x77343705D899A033ULL, 0xFD5AFD03C0E76335ULL, 0xC558661C47E078E5ULL, 0x1F9DDA2C3DE32FEEULL, 
            0x608CAB9CA1DCA9A1ULL, 0xB04BE1DE08AA1498ULL, 0xFF3803005846612FULL, 0xD19DE86589279EC6ULL, 
            0x44B479B939D7A240ULL, 0xC6516164FF8FA76AULL, 0x9FA64BD93EA7E77CULL, 0x8E9E359167BE9C84ULL, 
            0x7E227C46E72F38D3ULL, 0x091EB693AE98FAE0ULL, 0xBB1E4313627EE21EULL, 0xD3E66638372C0A31ULL, 
            0x2F903132E204A609ULL, 0x3FB84C9F768F1FC0ULL, 0xC140FA4936481792ULL, 0x42E0AB57289EB3A9ULL, 
            0xF64276669B826149ULL, 0x5E85B47DBD2A2A2CULL, 0xEDE41355FD877125ULL, 0xF8C4F643BB27E533ULL
        },
        {
            0xA607C674363E9C8BULL, 0xDE9A57F4265C1FEBULL, 0xFFF9A9FD31821C8EULL, 0xA295573E20D6C1B1ULL, 
            0xFE6C52225327FCE1ULL, 0x90DF1FD65A080ECEULL, 0x85A49E513E8F94AFULL, 0xA7B463C64D6E4C5FULL, 
            0xB78289C3B412FD09ULL, 0x03EC2BC125C59134ULL, 0xA3E57B4D78DA7E1FULL, 0x357249E81DFA7D38ULL, 
            0xC3D43BAA3630FA74ULL, 0xED543A3AE874969BULL, 0xB55E4F60789E87E3ULL, 0x955D71B5DEAA1E89ULL, 
            0xAE452BE59577599BULL, 0x3EE3C5B9BECB871BULL, 0xCFCDEDAAA0225B2AULL, 0x7A9055AD08DE7A3AULL, 
            0x74534FDAFCDD3F06ULL, 0x95507F897BE126D2ULL, 0x6D97449682184EBCULL, 0xCBE65327CBD3EE43ULL, 
            0x7367CEE521121260ULL, 0xB32DA3F90C31A7B1ULL, 0xBC1F8128BEB6F31EULL, 0x85FDA6715C2824B8ULL, 
            0x2B02448D205DCC9FULL, 0x018D5B9A8B064CCCULL, 0x6E252A891B725A27ULL, 0xDDC934EC39A2214CULL
        },
        {
            0x7D3AFE870FD5B273ULL, 0xCA1D28D78C9F5C1EULL, 0xF6B325CE7FBD4514ULL, 0x206CEBF73582D03CULL, 
            0x5898D2AD7C4157E8ULL, 0x76D44FF13C2FA17DULL, 0x96D81A7BD89334FCULL, 0x67E4D5B246B9C2D4ULL, 
            0x3A8BDF653A785391ULL, 0x917903A30A0D7173ULL, 0x1521BDA9C8859C49ULL, 0xD24ADC690CEBC2D3ULL, 
            0xCDD1386AB34F1386ULL, 0x51B2A5182F5DA24FULL, 0x3488CA0FE11AFC0CULL, 0xEE7441CAC4B8BF27ULL, 
            0xD301D974B00566FFULL, 0xDCBC0557A35A52A6ULL, 0x6809DC0324D13D51ULL, 0x4AC4567CA241B1D6ULL, 
            0x47358C00607BD61CULL, 0x85843A9D5B4E0670ULL, 0x953F617076C66549ULL, 0x0FCC356399C4B986ULL, 
            0xBB15C536479FE20AULL, 0x9FFFB0A07AEE32C2ULL, 0x2911AC5B2568ED34ULL, 0x10E81EBE12C14FBFULL, 
            0x79BBD85323FFF147ULL, 0x21CFD094075D3578ULL, 0x84465CCF9012075FULL, 0xAE075E6AFB329643ULL
        },
        {
            0xC2D86E1B49A66664ULL, 0x9C17AED97FC954D3ULL, 0x0D65631ADF50C033ULL, 0xAAA20105335AA3FBULL, 
            0x09AF45D03498A094ULL, 0x928A93519943407AULL, 0xEBAE41EB419092EAULL, 0x4C13DF9C38D0CD6AULL, 
            0x66CA6ACB5072AEAAULL, 0xCEF928E559ED4F74ULL, 0x17F604ED0E4D6C01ULL, 0xAC2B685FF7C85241ULL, 
            0xFA034AAAB983FCE5ULL, 0x6DFA05296E0A12C3ULL, 0x5B05617B906B5E75ULL, 0x15E632FDE0AE8BEDULL, 
            0x7F7A6DCA28811928ULL, 0x7ADDFBE8E2C9B864ULL, 0xDBFCB294D36D067EULL, 0x2C4C1E0391D11661ULL, 
            0x5206D1469BCBD7DBULL, 0xB0946A95C117C8C2ULL, 0xEF1A68984031C0F4ULL, 0xC3E872A7B635F200ULL, 
            0xA8BA1D8BB36CDA7BULL, 0x08EFF54E41A3226CULL, 0xE9AED490DA25E641ULL, 0x9F6BD48BF4DF50F0ULL, 
            0x985613D6EC301C0BULL, 0xB2DF3CD2063DF487ULL, 0xC4F18F5468E815A6ULL, 0x196C8AA9E6E82D77ULL
        },
        {
            0xA75DE1CA33BA97D4ULL, 0xF050348C4A7ECC19ULL, 0x0C2C2108A0EF12F9ULL, 0x692E347B364813A1ULL, 
            0xD8D1EDD0E37B2457ULL, 0x45CB74C834C3DE44ULL, 0x466E0084A7D13F62ULL, 0xDE07AC466A19D46CULL, 
            0x80F31F163B15ABC1ULL, 0xE3E878E6FD495EE9ULL, 0x88769B69E14049EFULL, 0xBACFDB87F77CF557ULL, 
            0x75321B34D9C964F4ULL, 0xB4B2850D24196C8AULL, 0x03814202CD32CC68ULL, 0x57B34A1ACA36A443ULL, 
            0xA54FDC9FA0D469DBULL, 0x3E559A62E97F5017ULL, 0x2AAE5BD104B7DA56ULL, 0xB4FD7C4A4A98CE7CULL, 
            0x18A5E0E52BE43B5EULL, 0xBA42DC771FB43132ULL, 0x2065CADE2DEE8DF9ULL, 0xA2BC842FA65B6038ULL, 
            0x3AAA47F600BF8817ULL, 0xF539153575A04979ULL, 0xE51AB2F40B713230ULL, 0xFD2C3D9589CF76DDULL, 
            0x3AB126B2F36C896FULL, 0xF195767078682894ULL, 0xEFF3A56CFC1A2F0DULL, 0xE53B27FD86C5693EULL
        },
        {
            0xEF2A94477CC363C0ULL, 0x1E4F9DA2B71FE73AULL, 0x34703A075CAE0EE8ULL, 0xD6C67D818EDC38C2ULL, 
            0xF9FFBF39B6BA45FFULL, 0x4D6F448D004B8F30ULL, 0x022F8A3A8BF2F827ULL, 0x270AEC9B53489425ULL, 
            0x95506A98540550AFULL, 0x9D7948E9C1357A13ULL, 0xC29AC451BE6348A1ULL, 0xFEF51E62A02BF584ULL, 
            0x2AF78A6F623BB569ULL, 0x18874E3C4B6029DEULL, 0x5C38C74AE653D769ULL, 0xD58C7BBFAE8C55E9ULL, 
            0xE6B77B57ECA23FB7ULL, 0x8C5BA723E541CF2EULL, 0x8806CFDF59C55599ULL, 0x82A1B3B156060603ULL, 
            0x280280BD90822100ULL, 0x79E3DF187704B859ULL, 0xECDB5F6ABF415AAAULL, 0xF5D91737741EF2E6ULL, 
            0xE9AE875601894BFFULL, 0x2F6ACF679AD491ADULL, 0x8DABA938C1E4F59DULL, 0xDE6C5E968F1D1512ULL, 
            0x602C571CDEEC34DCULL, 0xC403D9CC24C91F64ULL, 0x6770589006C6377CULL, 0x2F2A0A1DD2CD3E74ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kSeedConstants = {
    0xC23035D2B9B1249EULL,
    0xDF39D7AEFF51A59EULL,
    0xF85EE68E3D926B34ULL,
    0xC23035D2B9B1249EULL,
    0xDF39D7AEFF51A59EULL,
    0xF85EE68E3D926B34ULL,
    0x199FAC4A30BCD85BULL,
    0x4E3FBC3800AE52BEULL,
    0xE5,
    0xA7,
    0xA9,
    0x9D,
    0x9F,
    0x2A,
    0x9F,
    0x56
};

const TwistDomainSaltSet TwistExpander_Suhail::kTwistSalts = {
    {
        {
            0x81B4920998C31EFDULL, 0x14D6702243A5FF87ULL, 0x8B3155DE4C966E80ULL, 0x5FFACB01C445401FULL, 
            0xE7E035A6A094A942ULL, 0x221D7D83489C4FA9ULL, 0x9A87A55D9B5B51B0ULL, 0x602FC673CE2F0C7DULL, 
            0xFB28018A466882C2ULL, 0x28F9D602FA3425B9ULL, 0x78C7C30B22631BBAULL, 0x1ECC6B66080FA6E4ULL, 
            0x2BDD18B7F28A2DD7ULL, 0x20F6225DB9DD8D52ULL, 0x4494C7C154883079ULL, 0x45871C06F7376648ULL, 
            0x7BCB9EC545C96251ULL, 0x2BB2F4CC06B81BDBULL, 0xDFAA0093A75CE35BULL, 0xA79B342FBA505574ULL, 
            0x5BF40521F9D62915ULL, 0x2C0FFF3EA57662A5ULL, 0x3B8FD9EA98E87700ULL, 0x1B9498F49BCB18A1ULL, 
            0xAF239B354D76C7F7ULL, 0x185262B872FF76E1ULL, 0x2942ED5963F323D6ULL, 0xAF2EE43CC5B3562DULL, 
            0x3D35FDA6002E1F59ULL, 0x4F04683DB035AA88ULL, 0x99E4FAC667550727ULL, 0x7E48DAC619481A72ULL
        },
        {
            0x5F46C7C7AEA7058EULL, 0xD0C20EA6E9CEDA54ULL, 0x6F5C58E48FC1A695ULL, 0xD75750F3FF22AE1BULL, 
            0x293D66298C8D47FDULL, 0x4CF82B2A743D4F1EULL, 0xDF67A246F4233412ULL, 0x5D1C2267E8D6BA56ULL, 
            0x692F8548FC20C726ULL, 0xCA8995E52D654C2BULL, 0xE8DC0BFFACD24664ULL, 0x7E1DA746A4959E17ULL, 
            0xAB3F59E39552F27EULL, 0xB6DE37489C20C8C0ULL, 0xD7C97039C2F425B9ULL, 0xA117F764ADDE69F6ULL, 
            0x7D4B3A4F367A4255ULL, 0x02F27531BC4F07F8ULL, 0x8A66144F55173F17ULL, 0x948B485149FD2E3BULL, 
            0xD088AB68749ECDA5ULL, 0xF27490032B8FCA6FULL, 0x430722A99EFC4632ULL, 0x9ECBD765DE3D339FULL, 
            0xF87BEE7E530DACC4ULL, 0x0BED87EC73FAB6A6ULL, 0xC444EADC7D1FD480ULL, 0xE3D4ED1AE17401DEULL, 
            0x5BEE1544A87109C7ULL, 0x4E01486FD6AC5D38ULL, 0x061B641743B97EE5ULL, 0x0972BF23534D41F1ULL
        },
        {
            0x7A00D1A3DD4EE968ULL, 0x2EBEA1B3C184A6C3ULL, 0xEB4FD438A4C5E59AULL, 0x0F42BF89C61A4974ULL, 
            0xE7A199156DE50568ULL, 0xF3F80FBCAEAA7A8DULL, 0x005519BF28D709CBULL, 0x900FE39EBA792CD1ULL, 
            0x8DDE185AF018EDC3ULL, 0xC60964EF2D0F3337ULL, 0x7CE2F1C3E503089FULL, 0x971EC247E42D99F7ULL, 
            0xD91F7B7E7CCE8440ULL, 0x18E2D5CEEBFE16A3ULL, 0xA7F96F8A7603D409ULL, 0x09376B960597136CULL, 
            0xFFDD876F52832D6AULL, 0xD2CBAD8231213C7BULL, 0x3A8828E911AE3C4FULL, 0xCBB4D90FAF629ACEULL, 
            0x5B287E24D06AFC76ULL, 0x1FC401DA57C656F7ULL, 0xC1F3E7AB22E51C85ULL, 0xB84EC30D35740887ULL, 
            0xEA2E8A0942112805ULL, 0x013CFC248AB2BB41ULL, 0xCACDED6329AA45AFULL, 0xA6D55AC6F9CD107CULL, 
            0x125AEE8B9AC1C937ULL, 0x6D66472F2D990AA6ULL, 0xB78E1D1B5C8951C4ULL, 0x55E2B3D546BAFAACULL
        },
        {
            0x8166FEF462364313ULL, 0x1009A840DE3133D6ULL, 0xFA55D77F07DB5E7FULL, 0x05FFF9134028BAA9ULL, 
            0xD0F3E311C9FFE850ULL, 0x99F6A36C57431AD5ULL, 0xA5370BFE06A86A68ULL, 0x55409C9220CA94BEULL, 
            0xE3417D79B28BF971ULL, 0x5B5A9F6AB094056EULL, 0x771538A001225DA6ULL, 0xCC27484AE27947DAULL, 
            0xEAFA1FC38E52ED4FULL, 0xD8C5AA74AECFF470ULL, 0x03A7F5BBADF4A859ULL, 0x9C0DD08A3041FB6BULL, 
            0xBF7D7479E40D9E2AULL, 0x44A429DA61173AA5ULL, 0xFE8A776F677EBDA8ULL, 0xDB349DFCC085EED0ULL, 
            0xECA4C08630CFCDCEULL, 0x762AD3E79AC2EB46ULL, 0x68261C049D14B002ULL, 0x850A748BBFF35D06ULL, 
            0xF5A66DC77C7E4BFDULL, 0xA2253F9B7950B45FULL, 0xB88404340DECDDE6ULL, 0xF43C67F529C74987ULL, 
            0x9DFF87C51F77EF87ULL, 0xEC5756D1852CE2CFULL, 0x382BCAECEFCA358DULL, 0x9E741DD1B91D7FE1ULL
        },
        {
            0xEC62B61161B1C50AULL, 0xF83250AC96CA4513ULL, 0x217B644043982AE0ULL, 0xBAB24B7469EE9A0CULL, 
            0x82E65D5ECCF813CBULL, 0x553DFF67E21B687AULL, 0x11F50AA2E1FE3B22ULL, 0x91CB5C98E4CC2021ULL, 
            0x6026C13B24D9C330ULL, 0xA987B9FDC71C893AULL, 0xA19A31EDC0D6184EULL, 0xD7DE033F1CF31686ULL, 
            0x3270EBB926D9B8C2ULL, 0x8B29DCEF55E1C07AULL, 0x540FCF60EDFC78B9ULL, 0x46197D4A5F79C19CULL, 
            0x34D6966458355963ULL, 0xDB079F68779CD4D9ULL, 0x5BE0E6F9771000F4ULL, 0xBB6547816EB9DFAFULL, 
            0x48D179547A2CF264ULL, 0xC324EB79A59C8592ULL, 0x58FD042B03D6EF86ULL, 0xD0B79A91FD498FC5ULL, 
            0xCF079A0A12C34298ULL, 0x43F3AF64D39D4C26ULL, 0x70F9B8A5AAA67453ULL, 0x3684B05AD7C23C43ULL, 
            0x45A3A754AC3D94E7ULL, 0xFB0BE0B19E5EE853ULL, 0x1315E6D69E23BE6EULL, 0xFC05B444C9E5C4A8ULL
        },
        {
            0xDA1253587D70A542ULL, 0xBF55B7D23E2FE3FAULL, 0xC74E459CFC6F82C0ULL, 0x3B6616FC7B3944C4ULL, 
            0x7E10600736C88012ULL, 0x89F6F00559E28EA8ULL, 0x84FFD99170B22189ULL, 0xD0DDD4157F4B5A02ULL, 
            0x80F12B830C11AED9ULL, 0x4F4824DA47D5A761ULL, 0x4804CB43CD1CFE00ULL, 0x86F3D5508FB2B9D3ULL, 
            0xD9F533363E9C4EEEULL, 0xD21F40B2C1D6C989ULL, 0x22B8B226E252AF8EULL, 0x8DE2E3E590EE6464ULL, 
            0x959372FA70572652ULL, 0x387680C084BEF36FULL, 0x1C0D1DBE5288FB68ULL, 0xDB94FC2CA4B4F615ULL, 
            0xA7DFE90C215051ECULL, 0x7762444F8415D06DULL, 0xBB7E1017FE49C407ULL, 0x104E2F2B348ED552ULL, 
            0xB42A431B06CBB571ULL, 0x07289B2ED4A207DFULL, 0x42BF6D6B14F7CCA0ULL, 0x2E885ED5BC0AF98AULL, 
            0x26496058A2931AB3ULL, 0x51B1E472ACF305A3ULL, 0xD9ABB078759D5826ULL, 0xE0A7D1A320F566C6ULL
        }
    },
    {
        {
            0xF5165B0EF51A346DULL, 0xCA6CA42C3A93EC44ULL, 0x55CC1C27CFD86AC2ULL, 0x4D7DD924278F46FEULL, 
            0x050052792B5077AFULL, 0xA22EC53B8DBBE832ULL, 0x59441BB150C14C8BULL, 0xD7E0F0A24B8C6911ULL, 
            0xA9FDD02FD5CFE340ULL, 0xD0F831B9C3C544FEULL, 0x551387705BB86A70ULL, 0x96961748C7F2ADF8ULL, 
            0xDCE881AC24FD71DCULL, 0xB4D9AB5E4CB16724ULL, 0x63273966EF43CD96ULL, 0x046650D2A2CA9C7EULL, 
            0x7F433D18706D788DULL, 0x5DF31FAECE9D997BULL, 0x4E64007B16C11796ULL, 0x14CB0020557CE843ULL, 
            0x83A5715EB6C7D9D5ULL, 0xD72FD0DD00FA5CB0ULL, 0x0849D5771B02AF9AULL, 0x27E150B59B9D180CULL, 
            0xF8793DDF279D90E6ULL, 0x59C2A5509E56471EULL, 0x627675741851CE1FULL, 0x50220CDA649A570CULL, 
            0x35A944FBBDE3EB8BULL, 0xDA73FB9BCC775B8CULL, 0x764ADF61B96172B1ULL, 0xFFFB5320F47A5A84ULL
        },
        {
            0xD1A2681C42ABA7C9ULL, 0x23B5472E6E3DB743ULL, 0xE5E24029EE77F631ULL, 0x0990534E1722F415ULL, 
            0xCA1372D1D8A047E7ULL, 0xF438D180AEA0C2CAULL, 0x4A6ADECE10D276D2ULL, 0x620D66DD20E878DCULL, 
            0xC46FB7B04F6F8200ULL, 0x782525F149F222A8ULL, 0x62D6B83DF1B71C0CULL, 0x22EECEEE2007FBAEULL, 
            0x4425A19216B01F6AULL, 0x335B2BBF4AE76BF7ULL, 0xC3FF8DA376269694ULL, 0x7AC22D22B1C4E6C5ULL, 
            0xB79F817CD74B2446ULL, 0x5EDD3A65D5C19C5FULL, 0x29342A8D804895B9ULL, 0x6FC62EC649786ED3ULL, 
            0xABF3F5E980054732ULL, 0x7E62153389DC2152ULL, 0xAFE719F017F0E400ULL, 0x8CD93622A6FB54F7ULL, 
            0x86D866AD914EB2BCULL, 0xE7E9594B492B80A0ULL, 0x99A2D15896B08242ULL, 0x4B697FD9D37EE7F8ULL, 
            0xD84FFBFBA97F721AULL, 0xDFA9729802FEBEA6ULL, 0xA47A99516AF225E8ULL, 0x815D832B968F1C3DULL
        },
        {
            0xAA44C133F84A5A4AULL, 0x9EB0173F5A64D508ULL, 0x1E5ACDC9B12516F1ULL, 0x5D343E74F300A50AULL, 
            0xEC6AB23869CF38AFULL, 0x60FDFC0431C8A9B0ULL, 0x89540681025A8370ULL, 0xB85516941B5F361CULL, 
            0x747DCB8083CF05D3ULL, 0xEFDB12765974E5A9ULL, 0xBF642CC5781A7882ULL, 0x2F85F6E0D2FB65D9ULL, 
            0xAD5966F457DB86A9ULL, 0x67E180B7D488CF3DULL, 0xAE6CEDAF0BC67D88ULL, 0xB62C449DCF6BEF97ULL, 
            0xF506E215F234A96DULL, 0x96C8DAF6FAD8A7B9ULL, 0x77C8AD41BFA88507ULL, 0xF2C4F1985B6FDEDFULL, 
            0x58B419DE04883C0EULL, 0xDF0B9B894DB35206ULL, 0x12B4D6AF6AE213F2ULL, 0x399674B5C5392957ULL, 
            0x1A16C8477D69B944ULL, 0xC577D0B93E54DCBFULL, 0xF6F3302C1249A079ULL, 0x97E793160890D915ULL, 
            0x259DFD6625ADE028ULL, 0x1E932D873D34BE5EULL, 0x23C681727EA51EB2ULL, 0xFE3AAC51CF6D8B44ULL
        },
        {
            0xDBA7F2B466BB54AEULL, 0x170F178F8E0861A5ULL, 0x47B9C14E2B0FEC39ULL, 0x969EA7E268DA58C5ULL, 
            0x7D6E7AA3A3FD64F2ULL, 0x7BF27E980A0335FDULL, 0x691212436F73914BULL, 0xE2CBA1E7560CCCECULL, 
            0x646FCF7E7CDC05E1ULL, 0xF97CC3EF4B79DD9CULL, 0xE2BB0DAA0E6C11D6ULL, 0xA00D072FBB151853ULL, 
            0x05BCB75EE9B4DE23ULL, 0x6585F23231CAA062ULL, 0x40F6BF9E1038A04CULL, 0xB46018CB5E29CCD1ULL, 
            0x1153573BA7E44B5DULL, 0x74996E8A9626240CULL, 0x33740403EA023490ULL, 0xF0F8DEAAC2F2A722ULL, 
            0x9922509605F0997AULL, 0x4F1E1E4C69EF3018ULL, 0x5B1235C6CC567988ULL, 0x0A1FFF87617F18F7ULL, 
            0xDEFDA7C0EBCF298CULL, 0xC3C12B5D56B39628ULL, 0x37A7BEC40639DE65ULL, 0x4E38609BD9BC7050ULL, 
            0xE28FDB58F77F6F48ULL, 0xDFB21F5BB8FEDA3CULL, 0xB0FCE5A212490921ULL, 0xE6FA5A522D79BD41ULL
        },
        {
            0x7F988D6EF4094FF9ULL, 0xD28DAF7FAE8A4A5AULL, 0x5C5EC11D3EBDF7DBULL, 0xDC53029DF18F921BULL, 
            0xC960CA6CCFD950ABULL, 0xF6A2B03E6E07408FULL, 0x11272DBD806D7B77ULL, 0x9DB5746AA3A7CDB0ULL, 
            0xB73E351EF3965E5EULL, 0x3C045C21C97FCC50ULL, 0x5BC64AC432DD80E0ULL, 0x030252934CEF059AULL, 
            0xDCB9B3067A4DEDA3ULL, 0xF74F669D90595D3EULL, 0x2B95288A9456D5FEULL, 0xB2CCC9FE3C215D3FULL, 
            0x4C7E7EE731115B62ULL, 0x325B64A1545E1BB7ULL, 0xA0FE7BA005BABF64ULL, 0xA926802B4ED282AEULL, 
            0x3005B756B040343CULL, 0xCEBE811C9781E9BDULL, 0x6EBC748EC0190CCDULL, 0x355D02797323FB60ULL, 
            0x0C8761395C598901ULL, 0x08464A34EC26F153ULL, 0xB1D9FF9E8D627A4EULL, 0x34DC1CD6335F11AEULL, 
            0xF62B4EA0D30F821AULL, 0x7325CFA32BD504E5ULL, 0xEEFAC2EF1A32F0C8ULL, 0x9EFBAAD06120B9B4ULL
        },
        {
            0x8BE369DBDB86A25FULL, 0x0A87ECDAA2A3DD0AULL, 0x335B0B21C0F7E83DULL, 0x7E5AC58D2F14A124ULL, 
            0x1D6AB254CE300A35ULL, 0x141E5785C2E2F127ULL, 0xAA5AE1E1C8F4A4CDULL, 0x633A55FB6EA84C5BULL, 
            0x2CCC2F1E532B7ABEULL, 0x26E1F7FF12201C54ULL, 0x1F8749B88131D1CBULL, 0x98B568F048A49EF2ULL, 
            0xF62E648E53465860ULL, 0x8A3A6057A6B2D308ULL, 0xD72D0E12EFC3C37EULL, 0x7EA02DBDE35E24D6ULL, 
            0x3503CE9E36AB67B6ULL, 0xDC3FDCCBF95F0AB9ULL, 0x9B83B67C87CEB012ULL, 0x4A5FD997778E2512ULL, 
            0x0B4C899EFCD02263ULL, 0xE60B211393AE0BA2ULL, 0x91670BC5A892DA98ULL, 0x03B335D2AA21D0A8ULL, 
            0x8AE4AF2DD425626DULL, 0x26BD30E6A4A136B2ULL, 0x7302BE64B97908DBULL, 0x668480FEEEE3907FULL, 
            0x646A8D966456D849ULL, 0xB85D823B4681B311ULL, 0x58987635B56C40E0ULL, 0x69D766374218BE8CULL
        }
    },
    {
        {
            0x12EF966ACDA10FD8ULL, 0xFDEE06122E985CE3ULL, 0x27AA0E4941E14303ULL, 0xEA65AAD8A0FBFEBAULL, 
            0x471F5B2CC0993352ULL, 0x12F225F34C36C724ULL, 0x14477130296E03FFULL, 0x561D0D3538B9545AULL, 
            0x38492060956A1583ULL, 0xE1E297F197F98EE1ULL, 0xEE46D1C76187D8A9ULL, 0x31EF35AA4015669FULL, 
            0xF515427BB7D7D259ULL, 0x4AD96D3F1FF180BFULL, 0x2CF6C5421E676825ULL, 0x86A66C278313BED4ULL, 
            0x73BF7FC4C260C120ULL, 0xFE1583E102B86BE0ULL, 0x24BF374715017A98ULL, 0x6B8CD7D74B368CF5ULL, 
            0xC6143F4216FCB000ULL, 0x26277118643205CCULL, 0x8206CBD1E9A25E79ULL, 0xAE2F26691439085EULL, 
            0x5BDFBA04FA92050CULL, 0x202598C988F4167AULL, 0x32E29646214A1123ULL, 0xFBE8AB897B79AA8DULL, 
            0xF754E2870CFC7FA7ULL, 0xA97B94A73744FC55ULL, 0xC92145489CAE3BEBULL, 0xB65608985974A5EFULL
        },
        {
            0xA942FC40D4758C75ULL, 0xA2BA802B2C869B8AULL, 0x4B3BBFB1DEEF5AD1ULL, 0x09C18275E69C522CULL, 
            0x59D31DF67A1E7CE9ULL, 0x42554A47F69C20FCULL, 0x8F2B8999BE61260DULL, 0xC186CC2FFA8D4ED3ULL, 
            0x3AE836C9EE765E1FULL, 0x86A42909924CBCFDULL, 0x56BFFF8D1AA9A32FULL, 0xFDC531EE400E8A18ULL, 
            0x0782F56E8F04DAF2ULL, 0x48BEF197CAA842FFULL, 0x8F1B2647B79D0428ULL, 0x7170743F8CA5CD7FULL, 
            0xF60E2825575EBBAAULL, 0xD92BFD7CC5526A48ULL, 0xCA39111FE5A2772DULL, 0x159E9EC722FD54E7ULL, 
            0x46DF50CE8F924677ULL, 0x6EC835D71D5E9222ULL, 0xB207BE0459797F5DULL, 0x483B30DBBFF75BA6ULL, 
            0x69684080DE3E678EULL, 0x66A1E9A4EB60C2B1ULL, 0xDBFD9990F759B3B9ULL, 0x8CA0AB85BA95E109ULL, 
            0x6E7E03A329721474ULL, 0x22D6CD9C6FE81613ULL, 0xF59AA6C1A0902222ULL, 0x16B8FF9331023930ULL
        },
        {
            0x6AE4903F08363FB5ULL, 0x2905474BC1E7BEEDULL, 0x09DC81D0F40492D1ULL, 0x16E2F40E6018FCE8ULL, 
            0xB3F94C55CCB78A46ULL, 0xB9B2479D25BA6C1FULL, 0xCE8200DD23234AA7ULL, 0xDEE26FBCB6397D89ULL, 
            0xB0925B5C47340D27ULL, 0x8CDDDE03BF809310ULL, 0x11120A9274960488ULL, 0x51251653795A4615ULL, 
            0x7CFDA37C482899F0ULL, 0x5428A603EFD8DC33ULL, 0x636826E91713D396ULL, 0xB06D8750D81F2C58ULL, 
            0xC16E418DDD9CE3ADULL, 0xF261ADB5674AC1BDULL, 0xD05A542945D4EAD1ULL, 0x24A2890429F68F4BULL, 
            0x5F7EB6125BEF7FFEULL, 0x6ED6EF5F0B7F4E77ULL, 0xD579AE0602CCECBFULL, 0x60D9489B40A04C65ULL, 
            0x4BE4B08285AF616CULL, 0xA791541D408CA1E6ULL, 0x14B356A304E30433ULL, 0x36F53FF37249216EULL, 
            0x217F6423A68DB699ULL, 0x5D768D5F7758DD5EULL, 0x0E8BAC5022D2F28CULL, 0x8846EA7EF40A4C05ULL
        },
        {
            0x9C951C3943DEB3E8ULL, 0x61F86EB7FEB8836FULL, 0x796575D8B63B1BC1ULL, 0x65B745F4D80C95AFULL, 
            0xDB466CAC557B9451ULL, 0x0FAD7CFD9876B052ULL, 0x5F4F21E20974F59EULL, 0x415799B5E729ACA2ULL, 
            0x6860B945D0C2FA64ULL, 0x7F8BFCDDC1881067ULL, 0xA73AABB0B1BF5C57ULL, 0x5C4A75A5B7221EECULL, 
            0xE63C8CAAE0720077ULL, 0x40A7F0D027B9DE55ULL, 0x3885443B76191A0FULL, 0xA4381F84538A9E64ULL, 
            0x4BAF6D80A99E110FULL, 0xF6BA66864F773D1EULL, 0x0FA3336CD94A4BDDULL, 0x7668FF78146DF3ECULL, 
            0xACA8108AE5785491ULL, 0xE89EEE30E18FA161ULL, 0x786B9D20E5524F66ULL, 0xBC819282863A292FULL, 
            0x3B35A5595873EE3EULL, 0xA943CCD3E67D2AA1ULL, 0xF033121E82C49828ULL, 0x695AF675E4F440F3ULL, 
            0x35EB8B8E1BCAFA55ULL, 0x320689BFB6498690ULL, 0xEB4B2B51484662D0ULL, 0xCF68DD7715A14423ULL
        },
        {
            0x659458AB9D26EFDAULL, 0x5FF4338919270309ULL, 0x9E90C4CC2DB5AC98ULL, 0xBCF88A6A7AB2EEDAULL, 
            0xE3BE9480A14CE63AULL, 0x34961DA1A57069AAULL, 0xB01C792E87CEAB07ULL, 0x8D503B2892D39347ULL, 
            0x4C5C508B7CF8ABB2ULL, 0x5C3E7A4A78ECD551ULL, 0xDC0A670237C5DB23ULL, 0x46A65DAB1260A04FULL, 
            0x1355B9C7C966BE65ULL, 0xA435AE1563164378ULL, 0xE88223931AFC41B1ULL, 0x06DDDEDFFDCC5329ULL, 
            0x9276CD8634507B9DULL, 0x42EA3906EB0DBC39ULL, 0x3536B8E9791F818FULL, 0xF03E40CCFCFADE68ULL, 
            0x6386C1A0848C4C72ULL, 0x265E02D453A4E1A2ULL, 0xD4C7179E53DF160CULL, 0x52122F8CAEADBA1CULL, 
            0x6F3FA5F740828997ULL, 0xBC580A8AC006FF50ULL, 0xC1F888BA66587A10ULL, 0x81D0E864C319826CULL, 
            0xB76740BAA9B88EEAULL, 0x3E8D8C6B0D956E2EULL, 0xA46B27260BE204D2ULL, 0x2CFF115639F6496AULL
        },
        {
            0xA53CF52FE4E8FF83ULL, 0x29ECFC8324D34DC4ULL, 0xB129B943DC9789DEULL, 0x313CE9E82346C3DEULL, 
            0x7010E9253873B019ULL, 0x1F8997BF8ED83111ULL, 0x6BB57F8605284D4FULL, 0xE9AEB37F68070C7CULL, 
            0x5C7F63E0E485C882ULL, 0xF6E63A5BAD4ECE01ULL, 0xFF453E4817443291ULL, 0x9DEF8B4982335AFCULL, 
            0x76E078083A59498EULL, 0x3D657C069D5E3D3FULL, 0x1BF1094E948D830BULL, 0xC8DA1AB55D77171BULL, 
            0x8898E8857AFB09EFULL, 0xC0F8D39F371E50B9ULL, 0xC4846A83737DD0F3ULL, 0xC180BE93F8DA0C27ULL, 
            0xEB5B31EE92F8818EULL, 0xE9CCA354C9518B35ULL, 0x813473DA47FE0088ULL, 0xF105E6E1209B1D94ULL, 
            0x8D1E5A8704470B10ULL, 0xA880A730B7E3AFFCULL, 0xA5A2A45A22395AF2ULL, 0xCD4E25C0E75D80ABULL, 
            0xC8827AA422E65832ULL, 0xD5294AAA9E4B7535ULL, 0x5C71D5A82974C64AULL, 0xB2EF3D46E041B0A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kTwistConstants = {
    0x1403B6B37321D455ULL,
    0xF017A9D75FF66091ULL,
    0x1F1DBF091E6AD400ULL,
    0x1403B6B37321D455ULL,
    0xF017A9D75FF66091ULL,
    0x1F1DBF091E6AD400ULL,
    0xFBFED598598540A8ULL,
    0xC277FCE3366C9DDCULL,
    0x6F,
    0x80,
    0x79,
    0x96,
    0x3E,
    0x0D,
    0xBF,
    0x2F
};

