#include "TwistExpander_Ankaa.hpp"
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

TwistExpander_Ankaa::TwistExpander_Ankaa()
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

void TwistExpander_Ankaa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Ankaa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEF1FEFDDE720BD6CULL;
    std::uint64_t aIngress = 0x91CC281B6D866F2EULL;
    std::uint64_t aCarry = 0xD4DB061F0ABF3391ULL;

    std::uint64_t aWandererA = 0x873C4E71A03897B0ULL;
    std::uint64_t aWandererB = 0x8EA4CB462758F782ULL;
    std::uint64_t aWandererC = 0xBE61059D5D1F092CULL;
    std::uint64_t aWandererD = 0x925C45041215E26EULL;
    std::uint64_t aWandererE = 0x8B4EBBF6A3FCC4B1ULL;
    std::uint64_t aWandererF = 0xEBDA174AE9B52FB4ULL;
    std::uint64_t aWandererG = 0x8133701EEB71F4FEULL;
    std::uint64_t aWandererH = 0x916540FBB063D7C8ULL;
    std::uint64_t aWandererI = 0xA9054EBC9187565AULL;
    std::uint64_t aWandererJ = 0xFA2F6FE1AB887A36ULL;
    std::uint64_t aWandererK = 0xA44983A06006721CULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xAC7D38B55C52286FULL;
    aIngress = 0xE0743BC7DBDC7C6BULL;
    aCarry = 0x8516D3BF2F8B4A0AULL;
    aWandererA = 0xB872EA74239F95C1ULL;
    aWandererB = 0x9D0C8148ABA152E3ULL;
    aWandererC = 0xAE54F7AF61249702ULL;
    aWandererD = 0x84D2BFFD3A61B0EAULL;
    aWandererE = 0xDA2056D35D1BCFC4ULL;
    aWandererF = 0xEB3FCF684F097DB8ULL;
    aWandererG = 0x991C2A1A10DD3102ULL;
    aWandererH = 0xEE32141BC0283FB4ULL;
    aWandererI = 0xFDD58DB05D78348DULL;
    aWandererJ = 0xE85029E18DC2B3BCULL;
    aWandererK = 0x9D08A22524AD089EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE286DF55FABA325EULL;
    aIngress = 0xA20A37A216F6B724ULL;
    aCarry = 0xEE40311423009318ULL;
    aWandererA = 0x8D1A922FF38A5E6CULL;
    aWandererB = 0xBD972C4BE8630A50ULL;
    aWandererC = 0xF5B76B59B1D70016ULL;
    aWandererD = 0xCECB923AD092524DULL;
    aWandererE = 0xC41D5A1A50822C14ULL;
    aWandererF = 0x927E64C1EC8E4CACULL;
    aWandererG = 0xE1E6F493EB0EC960ULL;
    aWandererH = 0xCCDA9F68017691B9ULL;
    aWandererI = 0xF7E9173264DC1478ULL;
    aWandererJ = 0xF8D24B64B2347B8DULL;
    aWandererK = 0xC472B86B4E755124ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x9507D44DCF4896C7ULL;
    aIngress = 0x999B2BF34C9F32F3ULL;
    aCarry = 0xC4F4055DB33E910FULL;
    aWandererA = 0xC5D48D0B2E34589DULL;
    aWandererB = 0xC31F7B85CB626201ULL;
    aWandererC = 0xA076E837FA9BFE67ULL;
    aWandererD = 0xED9857A14E89D1DCULL;
    aWandererE = 0xF3D714CE0CF53AAFULL;
    aWandererF = 0x958366665281A50FULL;
    aWandererG = 0xFD51865A5E0DA207ULL;
    aWandererH = 0xD73B53F650149828ULL;
    aWandererI = 0xD333B448442B9FCAULL;
    aWandererJ = 0xD5FAA3B68715A512ULL;
    aWandererK = 0x938D425A2D7C47CDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xEFB3DF8A86860D09ULL;
    aIngress = 0x98C5649B269F8973ULL;
    aCarry = 0xCDC3B549723524C4ULL;
    aWandererA = 0xAF37ACC9642A86D0ULL;
    aWandererB = 0xD6A4B9E9ACE66CB6ULL;
    aWandererC = 0xA4A4654D35294090ULL;
    aWandererD = 0xC61A2830E3D30757ULL;
    aWandererE = 0xC00FC4CE05193C49ULL;
    aWandererF = 0xE20E20F3B0072D95ULL;
    aWandererG = 0xA18001938CA5E056ULL;
    aWandererH = 0xA460F2906529A39FULL;
    aWandererI = 0x90F9DAA9542B437DULL;
    aWandererJ = 0xC21DF41AA1764000ULL;
    aWandererK = 0xBD9AA91266520A45ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE694E24C1B861E7EULL;
    aIngress = 0xF0BBDA09BC49DC82ULL;
    aCarry = 0xFF2190DF2AB05F29ULL;
    aWandererA = 0x9FB2907A15EF903EULL;
    aWandererB = 0xB4619566841BE520ULL;
    aWandererC = 0x982D43333CD1CCEAULL;
    aWandererD = 0xE610576967CB1680ULL;
    aWandererE = 0xEE3E5AD61F06D5C4ULL;
    aWandererF = 0xEFA84DA4D95102C4ULL;
    aWandererG = 0x91242D49D3667AFBULL;
    aWandererH = 0x9693A5DC06022338ULL;
    aWandererI = 0xC3AACF6909019FF9ULL;
    aWandererJ = 0xAFF4CBF6D4969D2AULL;
    aWandererK = 0xF5F3D396902D23F4ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mTwistSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD71D01B22ECB12B5ULL;
    aIngress = 0xB71A5DC0B7311517ULL;
    aCarry = 0xF0D950C86CD8BC17ULL;
    aWandererA = 0xF8D181898F5E4F01ULL;
    aWandererB = 0x8E93BB8EFA683C02ULL;
    aWandererC = 0xCDDF63E618ECD360ULL;
    aWandererD = 0xFE58A009A2C3D1EEULL;
    aWandererE = 0xEB1FA40707A9730CULL;
    aWandererF = 0xCFA6C0B0237E740DULL;
    aWandererG = 0xE15F6E8E8626CB66ULL;
    aWandererH = 0xAAABC157EE9AA286ULL;
    aWandererI = 0xEAC8C11CA3B398CAULL;
    aWandererJ = 0xC079CB43192FE9E6ULL;
    aWandererK = 0x95376F5E68215324ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xE15D2F0AC58D5E30ULL;
    aIngress = 0xC65459D93C2D1F3EULL;
    aCarry = 0x907164C1B7688138ULL;
    aWandererA = 0xA771644B8F9F7DDBULL;
    aWandererB = 0xBA439952E242D346ULL;
    aWandererC = 0xD61C3724065FCAB8ULL;
    aWandererD = 0xB8A333201D3BAE9CULL;
    aWandererE = 0xB73C2A16AA50D24AULL;
    aWandererF = 0xF78DF14C66C57D8AULL;
    aWandererG = 0x9E2598E13A677774ULL;
    aWandererH = 0xED3BC5A1DECAAFC1ULL;
    aWandererI = 0x866D527BA23A00BFULL;
    aWandererJ = 0xB7BBA2DD9A1B7E93ULL;
    aWandererK = 0x8278284EF12EE8C6ULL;
    //
    TwistExpander_Ankaa_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Ankaa_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Ankaa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x904996C5C8A952BFULL; std::uint64_t aIngress = 0x865A50580CD6CFDAULL; std::uint64_t aCarry = 0xDCE63696C5C06FECULL;

    std::uint64_t aWandererA = 0xD5762493EA71FE78ULL; std::uint64_t aWandererB = 0xF66C5759B861B8B1ULL; std::uint64_t aWandererC = 0x93820940D36096BDULL; std::uint64_t aWandererD = 0xD542FA36F46EA1D9ULL;
    std::uint64_t aWandererE = 0xFEFDD6C0A6460107ULL; std::uint64_t aWandererF = 0x805069D5D3E7BBF6ULL; std::uint64_t aWandererG = 0xB99AD25C40217456ULL; std::uint64_t aWandererH = 0xA22218187EC7AB66ULL;
    std::uint64_t aWandererI = 0xB373E0C59BB2F489ULL; std::uint64_t aWandererJ = 0xCF0848A2E68F47E9ULL; std::uint64_t aWandererK = 0xCD1625E820B62E3CULL;

    // [twist]
        aPrevious = 0x934AF107E2ED3392ULL;
        aCarry = 0xD9DD80E89818CBB1ULL;
        aWandererA = 0xC78C52DB64B0FF9DULL;
        aWandererB = 0xDBC463744EF951EBULL;
        aWandererC = 0xE1B0B32F489A37EEULL;
        aWandererD = 0x9DA09C696710331FULL;
        aWandererE = 0xEEC54021951DDD0CULL;
        aWandererF = 0xEEFAB54DC1C4A924ULL;
        aWandererG = 0xBAE7E0F88405A1EBULL;
        aWandererH = 0x8F808BEE9F248041ULL;
        aWandererI = 0xDE59A4C174C2D626ULL;
        aWandererJ = 0xE27C80341626ECA1ULL;
        aWandererK = 0xF0C3B0F6BD0D9C50ULL;
    TwistExpander_Ankaa_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Ankaa_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Ankaa::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Ankaa::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Ankaa::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 8 of 33
    // Exploration cases: 0
    // Structural maximin 544 / 674; family total 3835
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1375U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 8 of 33
    // Exploration cases: 0
    // Structural maximin 543 / 674; family total 3846
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1285U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Ankaa::kKeyRotateASalts = {
    {
        {
            0x862A6D1DCE11D969ULL, 0x85AA1DA700DA483DULL, 0xC65A6B278FB48B85ULL, 0x83A9903F9C21E2ABULL, 
            0x723DF0B31BFC9DB1ULL, 0x20D704F9E39FDE34ULL, 0x2CA60DFF33AF4BC9ULL, 0x6B40E4257B45F66CULL, 
            0x210A0B60810DA188ULL, 0x48D66A884F03D797ULL, 0xCBC083FE01DA8B22ULL, 0xE651005E051B4D86ULL, 
            0x2E85012192B8FED0ULL, 0xCFD53E70C91301BAULL, 0x4115FF1B07D017CFULL, 0xC36FDA7EC7EAB18FULL, 
            0x475190D432D11D1DULL, 0x3E118C663F216F35ULL, 0xC3E5ACA944EB87B3ULL, 0x77B4D82ECA382758ULL, 
            0x9DFFCAEAE100EC0CULL, 0xECF58174D04E025CULL, 0x4FC31AFBE58B88D9ULL, 0xAB7F4B9989E65348ULL, 
            0x5206B4F7F3EB35E2ULL, 0xD88698F38C114551ULL, 0x72C6AC25637F5BABULL, 0xD6D9D33D11E7E399ULL, 
            0xB29CCD469C0D580FULL, 0x03C8B352ADD70C14ULL, 0x6EE142DAEAA6141CULL, 0x3CDCBD98F261FFE8ULL
        },
        {
            0xD2F50D82F4059675ULL, 0xCA88969681011150ULL, 0x97D0EE481CE3D552ULL, 0xABCB0CB6FFADBB55ULL, 
            0xF2BA183A7C8512F2ULL, 0xC2995A95929D1CABULL, 0x48FF1C7011AE3942ULL, 0xCD9AA58C53F34ED5ULL, 
            0x16B9AE046310F71FULL, 0x4DE304B12979A61DULL, 0x28F54B170A6EEB1AULL, 0xB3ECE5A71F292563ULL, 
            0xBA2018C79A489011ULL, 0xD2645918DB1D5A3BULL, 0xDD69899AD619F883ULL, 0xBA91A5D5A16A0D65ULL, 
            0xA12617A1CB1458FAULL, 0xABCFE1D6DF47B7B2ULL, 0xCD66CEB2A63FDE9BULL, 0x134FA4AE103E81D2ULL, 
            0xE707A26DE6C8902FULL, 0x3ADCBE788F5B61D5ULL, 0xB943E7BBDCF3D501ULL, 0xB70ECA893AE6FB57ULL, 
            0x67549C114DC55B45ULL, 0xF73018C5893EF2A7ULL, 0xBF70AC6B7D1D6D9DULL, 0xA702BF7BC14FD765ULL, 
            0x9FBAE7BB4D3AADE9ULL, 0x63052D9793923D18ULL, 0x5D735BB6C860E91CULL, 0xAE96A5073CFF4AA6ULL
        },
        {
            0x3C387B1A39461C80ULL, 0x665ED5B47E898F81ULL, 0x19A21A90C38FEFC5ULL, 0x481CEC12F2171DEBULL, 
            0x1B6967714D685C03ULL, 0x2C0C28813F0F8DC8ULL, 0xFE94C59EA1F35DD7ULL, 0x48B6DFBA957AAA98ULL, 
            0x74E941A8F39F3A16ULL, 0x9137810D1CB7B89EULL, 0x203063BEE0A4DA75ULL, 0x518D7BF8D6FAC0BBULL, 
            0xC9C7FFCC2083663EULL, 0xC8F4AE58DC6ABB67ULL, 0x1621E9BEAB7BA252ULL, 0x76E8C11C9F9EFDC6ULL, 
            0xAB9C65C6B9CA8725ULL, 0x06AEF86073DEEB2FULL, 0xED0FE6998C05C816ULL, 0x94B7E14D939F9BA0ULL, 
            0x81719D961B7B6F57ULL, 0xAC299A7DA62696D1ULL, 0x018309BE27B32A43ULL, 0x215BFF25A9099019ULL, 
            0xF95C4FBBE83A8265ULL, 0xE670E743A207FB8AULL, 0x8F90F34A8E7FB03DULL, 0x04D2A0808BD643CDULL, 
            0x9F379A6414C47BD7ULL, 0x3CFFC1C330924CD7ULL, 0x982AC59599A588E4ULL, 0xEC1137436FC5E7AFULL
        },
        {
            0xBC70BD649CB2869AULL, 0x7C65A73500846D48ULL, 0x1C51B0C5B5E2C9A0ULL, 0xF95DE33FA2C6A4EAULL, 
            0x8898D101858DA54EULL, 0x047E91DAADA580D5ULL, 0xFB0BA510F0BE3887ULL, 0x27682421B45FEF7DULL, 
            0x9D3036EE25601F74ULL, 0xB7DEDDBBA1F77F1AULL, 0xF0A98991673B75A8ULL, 0x491C2A073BD26843ULL, 
            0x46A533B81FE49391ULL, 0xE7E920A63DE0413BULL, 0x91A1564A9B397714ULL, 0x86DEEE65174D32A6ULL, 
            0xEEB0B7D2B415091CULL, 0xDB93ADD16FDAB7B8ULL, 0xA6013DFA05933B1BULL, 0xD78751535FE30F07ULL, 
            0x64A6A5165C809306ULL, 0x56A9D7E45B2AE23CULL, 0x757943F1EDF9BD6EULL, 0x2C2394109DE15352ULL, 
            0x925F0BA098E6B75BULL, 0x349C98722CD25A23ULL, 0xC956615F91BAA2A3ULL, 0x19A99ED53F79E23BULL, 
            0x39F8BBC28C1F8E21ULL, 0x7FB42CB298801A11ULL, 0x87BE6CE145EFE460ULL, 0xF4E6A251D7F69CB9ULL
        },
        {
            0xC2BCB639F953DD16ULL, 0xEC0E02AF8A5A2AF9ULL, 0x55D0D00119A01C41ULL, 0x71437DA07D1CE3E8ULL, 
            0x8FCEAAB96782FE29ULL, 0xD904FA5B9A450259ULL, 0x896A9459BAE730B7ULL, 0xA1F9DEEA50FA48B8ULL, 
            0x257EB996C0074E9BULL, 0x2DD444097DFA5277ULL, 0x1189E3927F376A86ULL, 0x6C7450B0F9EABC68ULL, 
            0xF8D498B49FE02CAEULL, 0x0087B1D522DD6FDCULL, 0xF840A785AF785657ULL, 0x2772A6C0DACA095AULL, 
            0x7F5BCB5AD35652A3ULL, 0x6A2DD19CD3499A0EULL, 0x99822E60E25B9B2EULL, 0x01DA90A75305B890ULL, 
            0xB7BE7F7A70614CD9ULL, 0x9EEACF508ACF4281ULL, 0x4945FDE6A222A999ULL, 0xB0E7AD54503D0D3AULL, 
            0x9771DB2BB014400CULL, 0xCF7534ECCC41867DULL, 0x30C450281E0A33A0ULL, 0xCA3D742BECC9DB7CULL, 
            0xCFCDFA20A9206DABULL, 0xE832CA5BE8A5ABDFULL, 0x1BFC57E196632111ULL, 0x9E12290D7B38C50DULL
        },
        {
            0xCD0E7BCE0B6B8A0AULL, 0x46367D7CD5233B05ULL, 0x36C688B76A1B8E36ULL, 0x147FDD7DE847DB18ULL, 
            0x0E5A5BF54E5BE593ULL, 0xDC0BFE5D9883019AULL, 0x3BE0E58CB7AEAC56ULL, 0x9CB24EAE39FBA91AULL, 
            0x5257698A466A2EE9ULL, 0x9868DB2F0E6DD76AULL, 0x69643C68A5AED185ULL, 0x7BFB4AA20A86467BULL, 
            0x422019DF983085D6ULL, 0x73C3207AF9F5DB52ULL, 0x1BBBF33E52C89B61ULL, 0xB3BF73487360F3FBULL, 
            0x0B3BE11166933F27ULL, 0x7CD15998B0D09A3AULL, 0x8F40DDEAE53D672CULL, 0x9A251AEE7F2113F6ULL, 
            0xAACA51DC42BFC6D9ULL, 0x590C757E40087207ULL, 0xD5B18AAB190C5D95ULL, 0x4B08C85EEA36C941ULL, 
            0x370A43B6ADB002A3ULL, 0xBC433DFFB8B0E20EULL, 0x50AA984086854561ULL, 0x778EDE757D759048ULL, 
            0x93B16D3430C6CFB9ULL, 0x33156B1903D23607ULL, 0x804583E8FFB7DA7DULL, 0x5D97E6A8943E5ACAULL
        }
    },
    {
        {
            0xD874CCE2F3ACE832ULL, 0x9818C2F83ED325ECULL, 0x56D375DFDB2ED1E6ULL, 0xC48A9F3EFE2263C7ULL, 
            0xE3E3BD896F247A5BULL, 0x450AA9FB4E5BF982ULL, 0x14F8DAFB132908B5ULL, 0x88AC4DF2D52BCDC7ULL, 
            0xBAAD9945C1DEBBB8ULL, 0xD5DF18E6DF366458ULL, 0xB25C231450807EADULL, 0xA296F89BBD3CEF88ULL, 
            0xF056B2B9140807E1ULL, 0x45D606FB7C86BF06ULL, 0x650DDA025B5F6C51ULL, 0xC53C2BF69B5F792EULL, 
            0x0A08CFE7B5D62A0CULL, 0x9CCC5180B82FBAF2ULL, 0x1F8A22A3148883C7ULL, 0xF6C72E7D14FDA184ULL, 
            0xE20C48C43B9B3D67ULL, 0x3E61CF37B65DA216ULL, 0xD142E632C8804D29ULL, 0x4E853AE5AE759628ULL, 
            0xBF4CBE95E4AA75C8ULL, 0x7ECD92CCFD08932DULL, 0xCC961D9862AF720FULL, 0xED1F55FAAB7ED80AULL, 
            0x2A6FA28821701C62ULL, 0xC228F1A5E35E6895ULL, 0x68E6203E6A7C9E2FULL, 0xF140D8A009F77346ULL
        },
        {
            0x469505D5424A8852ULL, 0xC1DF643EB0EFE035ULL, 0x7AA43F8480375CE0ULL, 0x264C3BE8A1FDEA8EULL, 
            0x89DFB1BED3E477BEULL, 0xC4FA6B3498CD198BULL, 0x5CF2E9F54BE3A3E1ULL, 0xFF342F938527A207ULL, 
            0x507A096EFF3BE061ULL, 0xD6F4420EAB7495B2ULL, 0x5901FE35A7A6D3E0ULL, 0x85E10A15F2C2223DULL, 
            0x37D2091711451E07ULL, 0xBBF2481E4A4CD0C6ULL, 0x370D88118283B408ULL, 0x7AC80B5CED72A686ULL, 
            0xA39ECBC1792D7AD9ULL, 0x0579D98AEA955019ULL, 0xE647F1708563FABBULL, 0x73978DAEDEA0655AULL, 
            0xC97189C96D0E75B2ULL, 0x76BCC0D5E3DE3845ULL, 0x5DC6A76A42DC530BULL, 0x93A9902FA83F3991ULL, 
            0xF10CBBEB93B2BBA3ULL, 0xC3A3EB7E280D58DAULL, 0x477E685F8F65AFE0ULL, 0x687A797B9DCF28CAULL, 
            0x4DD52DCBC0F9D512ULL, 0x13813B4FC2AE6D18ULL, 0x92FAE76BF884EF44ULL, 0x9DE1BF781081455CULL
        },
        {
            0x76859EE85B2ECC01ULL, 0xFD2DD46405C49637ULL, 0x93641FFE2279A1C2ULL, 0x2541CA77C609BD98ULL, 
            0x42F04910840D7C5BULL, 0x07BD742C8155C6C8ULL, 0x89F987A0003A5654ULL, 0xE832F47D82AFE6C1ULL, 
            0x141988BC88A81E3CULL, 0x61734B84B1804DC8ULL, 0x6AFB171CD74C7E42ULL, 0xC370C54FE90B5820ULL, 
            0xE383612297E3E5E4ULL, 0x9DE0A212440BC689ULL, 0x75858EE132588567ULL, 0xE6A828C2CD44C4E3ULL, 
            0xDD61104C58783A4FULL, 0x8F58DC96412BDA63ULL, 0x47614CCCEE31BA75ULL, 0x2245FFDB8851B791ULL, 
            0x2F4B5794121E5F4EULL, 0x155AB35E25342DC8ULL, 0x98D20DCC50665B66ULL, 0xB30F6F14323412FFULL, 
            0x16FF7249CD55200AULL, 0x2DA525E3D73E972FULL, 0x6102964643C4CBAFULL, 0xF6B6F7AD1A0B50F7ULL, 
            0xB2935DAE6EE0D770ULL, 0xDDE7ABCBB03B4C9BULL, 0x3ACA5E9098398F84ULL, 0x7B533EB7AE4E7119ULL
        },
        {
            0xB660DE1CDB76C911ULL, 0xD2EF8C74DC5D0CD8ULL, 0x614FA762A53F5B64ULL, 0x3F39C1E7F039B479ULL, 
            0xA6E9ACC624BFE3A7ULL, 0xE2E5870C31213C94ULL, 0x313E3D4D5CCFF1B2ULL, 0x70A9F43139A5AF5EULL, 
            0x3480CC4F17E00728ULL, 0x3F8D6B39251D636FULL, 0xF30769D2F1BE5707ULL, 0xF1F4A32281A58B08ULL, 
            0x38E898EAE3099FE9ULL, 0x4BE5558AADB4558AULL, 0x3077B32D514EC7F7ULL, 0xF56843FAF3F2D2FCULL, 
            0x116F2B70EC2B50C5ULL, 0x12781CE9EFFB0A5BULL, 0x9A169FF3CF20A735ULL, 0x4F88E4DD1BDCAAAFULL, 
            0x299E535D06B21D0CULL, 0x671798F49E9C6A33ULL, 0x63F7284FA314CD8AULL, 0x07D3A3B04EE72E34ULL, 
            0xEF69DE2CB8A14F1DULL, 0x1DA3247AAC7DCA70ULL, 0x64A3F04FCC36F7A3ULL, 0x5A2B230D1171C41BULL, 
            0x0F244DBA49E5743DULL, 0x85CCBE869FDA9A1FULL, 0x24A55DB87F37ED8CULL, 0xC07DF9368C8469A5ULL
        },
        {
            0x74FF801FE553B797ULL, 0x0F8B0E2FFEEF4ACBULL, 0xD54BADC49D8D4A75ULL, 0x3239FC3952A57F05ULL, 
            0x746880338C1A2199ULL, 0x32867CEFF1A81E2FULL, 0x2E6514D1BDE2768CULL, 0x63F37978F6D1A85CULL, 
            0x14B86724E45D1811ULL, 0x948FA51325CF0E32ULL, 0xFD0D07DE8DECA0F6ULL, 0x48CEBB34293F5B91ULL, 
            0x487242E704AAD248ULL, 0xC44F747EED22E6DFULL, 0xF73EBDBBC1415CBEULL, 0x6A05337AB82D2402ULL, 
            0xE0A1E3F775007008ULL, 0x4EC8AB641ABFAF70ULL, 0x140EE4E14E8DC649ULL, 0x7CE5EE6BC90EB97AULL, 
            0x603E617BA36377A8ULL, 0xA27A312B91F00231ULL, 0xC89CD13A6A846200ULL, 0x70C77FD52098EC65ULL, 
            0x3277E0787A554E36ULL, 0x7690FB8168B32179ULL, 0x151F14E733A5E201ULL, 0xF87922293C18C917ULL, 
            0x3DA114237D4B98E0ULL, 0xC5B3D91D13708F6DULL, 0x729994087AEAF18FULL, 0xF2AF8C0048849D52ULL
        },
        {
            0x7A96F085558840EFULL, 0xC0A2E6A5B0C0D983ULL, 0x3989279E32967EBBULL, 0x0EBAE94D01954CCEULL, 
            0x26A9ECFB7E4EF72FULL, 0xBC8D6FE403C0D01FULL, 0x10E03F10F5A5CF5BULL, 0x1F73C4523DD455B9ULL, 
            0xE035471ACD1624CEULL, 0x39F4C943ACB182A7ULL, 0x8BB4529974E8883DULL, 0x9EC07AB30922F9C4ULL, 
            0xC5FAE8E614009DB5ULL, 0x8CBCE3EB27B44950ULL, 0x25726CF4C1035C21ULL, 0xE366AB9B04E5BF92ULL, 
            0xDED085640A67AA56ULL, 0x8735EC56F3CC1A30ULL, 0xE1B2700FA286F09DULL, 0xD6EE3688EFBAEC30ULL, 
            0xB16D5152B2C68427ULL, 0xA492210DFE0C6CB8ULL, 0x1F8C869932E511E2ULL, 0x587FC62DD80F358EULL, 
            0x3932A03E3D561B88ULL, 0xB1923205FB7B5910ULL, 0x338973AD758691E2ULL, 0x9A03B8846A183A96ULL, 
            0xBE2AF13B407379F9ULL, 0xC7B85D877F4A7A07ULL, 0x78963F755789B981ULL, 0x4C4A6586A09EC01CULL
        }
    },
    {
        {
            0x86899B9080C64A23ULL, 0x86FD1D31ADFC9E21ULL, 0x3B1E7E8EB5186816ULL, 0x455D64B46691AD01ULL, 
            0x0C4067F7EE0D6828ULL, 0x89E81B71B140612BULL, 0xF76EF93C0037F283ULL, 0x84F8544D3EB79A41ULL, 
            0x4DCF531984A3C15BULL, 0x58ED561474399496ULL, 0x4B5E724BAF013BA3ULL, 0x3B330EFD0202B55CULL, 
            0xE149D4D80F3F041EULL, 0x0070323340627A46ULL, 0x66EB0C0C1120A75BULL, 0xF6AE6FC1CBECF6C7ULL, 
            0x806EBF6D5223591DULL, 0x3C1146EC5461188EULL, 0x8472773DEE3B47BBULL, 0x69E596CEA4DF119CULL, 
            0xF2D027D95F3881F5ULL, 0x9BF106F1518870B0ULL, 0xB6E8D838FA919653ULL, 0x4DCFDB8C85C661CEULL, 
            0x2E5F48179D8E3B31ULL, 0xDD7CFBD6D8AFE9EAULL, 0xAB5F0DFD74D0A4F7ULL, 0x3D7DF09A6274B691ULL, 
            0x8DC4838E688D6F54ULL, 0x8356ECC4080335A9ULL, 0x0BD437D8CDF727DDULL, 0xFE2CF2418C85DBF0ULL
        },
        {
            0x1366E3A2C54CC4BCULL, 0x869D5742E7ABCB40ULL, 0x19B47514433D3023ULL, 0x368CD1D9874A7CEEULL, 
            0x5661011E96C86C19ULL, 0xE80A321AD48EA688ULL, 0x2AE61CE69D9FF656ULL, 0x778912942BFBB52EULL, 
            0xBF7A40CDB2AE1897ULL, 0x6B6301F042668B5BULL, 0xA9098EF85E494003ULL, 0x6894E497594AA13DULL, 
            0xF68F7399E355EB05ULL, 0x2BDCBFC61975B4F1ULL, 0xEB07A00F2BAB4540ULL, 0x92D0BB52944EC4ECULL, 
            0xBB7923FBB413701DULL, 0x77F76641D33AF658ULL, 0x9D8ED349E528B26FULL, 0x55F990A46D0910A3ULL, 
            0x9B0B5ECE829DFB21ULL, 0x8D87320885DAFE1CULL, 0x258319DEF0A5B463ULL, 0x8A935B09278A5689ULL, 
            0x7DD473C8AA3B64EBULL, 0xB27FA1C0E35CB24BULL, 0x7E2D4B43EA5B7CD4ULL, 0xFBD49B25EE194DDCULL, 
            0x0521F9CB4B2DD4B1ULL, 0xF66D87E4E13AF5EAULL, 0xFFF5F92C6011B729ULL, 0xE6B6491754654F1BULL
        },
        {
            0x184E1F74AC078C5DULL, 0x7EB8F45178189F0CULL, 0x373012E2B9853CC6ULL, 0x6CE8DDDB05D8C67FULL, 
            0x46FC6CF2B27DB557ULL, 0xDC1A68BF7F627CA5ULL, 0x25B5029EDDEB253FULL, 0x50CC472FD38DC7BCULL, 
            0x18CC8BFC9F27A532ULL, 0x3106BABA0714C1FAULL, 0x548F842DCF17581CULL, 0xAE88EBE8D31EFB97ULL, 
            0x542E131CD65D886FULL, 0x02BAD5F7E8943CF9ULL, 0x2039AB997852B6FCULL, 0x408B852E93B71124ULL, 
            0xE71A8AEE112CD189ULL, 0x2F3D22F1DA88F2E5ULL, 0xE2CA71EBEADE73F7ULL, 0x102563237659090FULL, 
            0x86D0E2BC8B3D4C34ULL, 0x9E320228DDC4E300ULL, 0x7A9B973CAE931660ULL, 0xC4FE3371CCF1738FULL, 
            0x00D5182A7D260C57ULL, 0x503CEA7E5BAC95D2ULL, 0xA32AB929008705B5ULL, 0xB89DD4685943D53DULL, 
            0x02866129D8AEE495ULL, 0xD55CA4638E31259CULL, 0x2AC85EB0C5A26BC1ULL, 0x20AD00BF492B51CDULL
        },
        {
            0x0D256930D031BB9CULL, 0x27B669DA41750720ULL, 0xEF49041D6B514E75ULL, 0x2486123135227DA4ULL, 
            0xA9393E4A09F566AAULL, 0xE8AEBE64B8D9981CULL, 0xEC939978F7EA1F18ULL, 0x8A6BCCFA88FF7FEBULL, 
            0x900259FBE6E4D270ULL, 0xD649C01D676B3D3AULL, 0x5A05BFDFC9F0590EULL, 0x38E1B3734A181077ULL, 
            0xFE60F39C2AAE7D38ULL, 0xEE3A25494EB67A40ULL, 0x0C7E458C55997C14ULL, 0xF2DC70E8103C94CEULL, 
            0x1B10B536F28F7978ULL, 0xBF20D41B6B6B2A5BULL, 0x7C87369BF731F409ULL, 0x8511CEF439BEC6A2ULL, 
            0xA33F13F697A5D548ULL, 0xCA61970D917B3D48ULL, 0x76C9EFBFA8ADF487ULL, 0x5104DC9514C0DC89ULL, 
            0xB8D4537E56D53468ULL, 0x6DF673E283A156E0ULL, 0x9B588D11FDA06BE5ULL, 0xB865495FCC9A3E52ULL, 
            0xF2B9307E7C72584CULL, 0xC21A692B0745FFB2ULL, 0x3901873D8F3C1196ULL, 0xC40B81CDFE74E9C8ULL
        },
        {
            0xF12C9A002C9F5756ULL, 0x89A7661027602E2DULL, 0x07FE4B76074C1534ULL, 0x88239956153827C9ULL, 
            0x2825203A1102DA66ULL, 0x85DDB65A81C9DD67ULL, 0x24419EDAFFAB34C7ULL, 0x16224D6BE2724FE9ULL, 
            0x158F2108E580CDD9ULL, 0x213421B60B9DEC1AULL, 0x33D2C8B49387DB3FULL, 0xF07E637D7DBF96B3ULL, 
            0x2441D80793FE94CBULL, 0xEE232A26E0A66899ULL, 0xC19BBADB39977E47ULL, 0x4ABA6BEE9960D878ULL, 
            0xD50DBCECE2151DB6ULL, 0x7A67B7C696500804ULL, 0x284AC84312DDFBBEULL, 0xAC19ED6605E323E6ULL, 
            0x0208BF393189A129ULL, 0x7CC064C1B18E7AADULL, 0x5AE0D6FEA532A0F9ULL, 0x118C8FE91A404D8CULL, 
            0x6FA426E57E3E34F1ULL, 0xC6F2DCCEAAE7B180ULL, 0x426176B5F718A712ULL, 0x1EF6257A8C84267EULL, 
            0x38BAC6FE1C586FF2ULL, 0x12C19E6439AF714FULL, 0x4498A294FBB6C42FULL, 0xF78B718BCBE4927FULL
        },
        {
            0x3AEED61177AEE9A7ULL, 0xF39357BE8D1EBA6CULL, 0x471329C8DEFD8F66ULL, 0x3FCFE1E8BF8BA94FULL, 
            0x1B71CFA9CF334EFAULL, 0xE06AB7019DF6976EULL, 0xF57D4DAEF0F535E6ULL, 0x8F3E27E3B4298F88ULL, 
            0x7F5D2EE28A165EF6ULL, 0x3E328141B7522A6FULL, 0x42C1EF130753C9CCULL, 0xB3CA08D8B447FC73ULL, 
            0xDD241B86E0CEBE1FULL, 0xA59ED8395CC998ABULL, 0xBA679687036401BBULL, 0xE6B42F1EA4C09AE8ULL, 
            0x9D30469E00755564ULL, 0xFFF112CF3FB29A7CULL, 0x7A09C59C3488D26EULL, 0x993C5BB22E4A7685ULL, 
            0xD88A823E6C9996DBULL, 0xAA9ADD7A24156559ULL, 0x218A290FCE490D76ULL, 0x019E9A4660A3321FULL, 
            0x875A155AA19ED5F0ULL, 0x91F347EBDBD09288ULL, 0x237C1B167C59DCF5ULL, 0x74ED1E3117732F51ULL, 
            0xCBDD993EDC354733ULL, 0xDF911B59A98242A0ULL, 0x8162C5A56BF0935DULL, 0x3644F3139922ECF7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeyRotateAConstants = {
    0x34BB9F002E68FE31ULL,
    0x5C40D52D855E007BULL,
    0x3C10131B2EF293C9ULL,
    0x34BB9F002E68FE31ULL,
    0x5C40D52D855E007BULL,
    0x3C10131B2EF293C9ULL,
    0x7CF0DBA0E916E239ULL,
    0xC7A04B52C3C1878AULL,
    0x36,
    0x1D,
    0x0E,
    0x7C,
    0x6D,
    0x0F,
    0xA8,
    0x0C
};

const TwistDomainSaltSet TwistExpander_Ankaa::kKeyRotateBSalts = {
    {
        {
            0x57FC88166CE05FA4ULL, 0xE431EF90535B70FAULL, 0xD3A2090328B28C18ULL, 0xF5914978A1659319ULL, 
            0xDF7ADAFD04AE6886ULL, 0x5333972DB2F2E8ADULL, 0x954805C2FAC0212CULL, 0x43549A47C2EEFF03ULL, 
            0x476FF0FE704C1333ULL, 0xFA5103C9B31B1A41ULL, 0x44FC602C6D563058ULL, 0xFA2057586F1E0379ULL, 
            0x6209410B1B5988D1ULL, 0xFAD601CEE51A4E92ULL, 0xFC6EBE9F72DC49E9ULL, 0x21F028487512DBF2ULL, 
            0x7FF22AE7025C5DD0ULL, 0xEA80503633B1BA5FULL, 0x8595194FED7B9A25ULL, 0x92EBDA43C81E0976ULL, 
            0x7F6EE100F9F1500DULL, 0xD1650DEEE5188BA2ULL, 0x25382FF3EDCCBE49ULL, 0x974120F953517AE0ULL, 
            0xE3ACF0B91E23FB00ULL, 0x0083799FEA13E91CULL, 0x91EC6E0DD125D8FBULL, 0x7DD714E2216C65D0ULL, 
            0xB0D45276AFBEC676ULL, 0x893988DCF7724197ULL, 0x9CAEA266F615A1F2ULL, 0x4DE57D6F75033642ULL
        },
        {
            0xC0C38EE8C3B35D2EULL, 0xF8DF00DE2A3948A9ULL, 0x53EA9EBC913B9E00ULL, 0x8AD836516D5ED818ULL, 
            0xC9AF75CF1990FD0EULL, 0x49DE67C64F447956ULL, 0xBF380E3F036A3E0CULL, 0xCA5DBAE069979231ULL, 
            0xA809558AC9A7CBE9ULL, 0x0933B7E241CD1E26ULL, 0x242B68D1F12C358AULL, 0x4BD3C14EB9A4B5F5ULL, 
            0xCFE3AF5DD2D8ED63ULL, 0x84699EB45A490E98ULL, 0xCE644EB75EDA8B34ULL, 0xF35A3768D2427DEAULL, 
            0x64DE16A9E84BADEBULL, 0xB9E9296F68B90DB8ULL, 0xFBB670E182859CB0ULL, 0x8E9A22B9B6DE1EE9ULL, 
            0xAF24C5DF1A830796ULL, 0xF77FB3CF5DC3E20EULL, 0x65330FDF9A3B87A0ULL, 0xBDA96497170563B7ULL, 
            0xB0A898BCD846B96BULL, 0x61659EF211516C7FULL, 0xB44754377202B057ULL, 0xE63A4AFBFC2B0F4CULL, 
            0xD40E5E0A92EB65A5ULL, 0xD9E4D8868004413AULL, 0x0DE5D38A26271637ULL, 0x805BD60D3A24AACAULL
        },
        {
            0x6EB486795A4E2548ULL, 0x7183D08C0E5F4F54ULL, 0x0C334DD313864490ULL, 0x4884961D2A3F2023ULL, 
            0x73C1DF664CA9228DULL, 0xA49DF3CA97E3B24AULL, 0x4BFA76917E35E30DULL, 0xB941464E0B755293ULL, 
            0x83137595FF7DCBBAULL, 0x2597B71780DF7FF2ULL, 0xD2E7EDF94A9DF586ULL, 0x92012CC1913755F6ULL, 
            0x9AA1CB9A8C9B90D3ULL, 0xD3236E21BE6B1E3BULL, 0x52577635EC7A58B4ULL, 0xB969B5E076A108C6ULL, 
            0x80007368CACE353EULL, 0x28038A7FAF16EEE6ULL, 0xCF275E464E5279F5ULL, 0xB84D590A3BD4D1A7ULL, 
            0x4EE98D2AFF0106C9ULL, 0x47B942DCD0EAE9F9ULL, 0x661EB76E79CD6254ULL, 0xD2FE76B9B5E17E22ULL, 
            0x9C4D447E64552B0AULL, 0x2F9C92AF24A2414BULL, 0x9561781D1F253803ULL, 0x7A177DADA9CF6D0DULL, 
            0xCF3781A0B8924C02ULL, 0x79023C368D3118ECULL, 0x3F1E28F132567390ULL, 0xB917A68D1109C6A5ULL
        },
        {
            0x240833B884FA0D5AULL, 0x86587E489136D85CULL, 0x9F3AEA94A0F18E2FULL, 0x192D791EC9FECF70ULL, 
            0xEA2823FB6A1CAA5DULL, 0x8949D863E9721EAFULL, 0xD084CA47E459373CULL, 0x89C2C4292756ED37ULL, 
            0x2A0599AD97E79185ULL, 0x615DC48913E58D37ULL, 0x5298D22C0328F0B7ULL, 0x6A3895C2874E71C7ULL, 
            0x63B3BA3B04C5ED83ULL, 0x85B122603FCB5E1BULL, 0x433016635ABA7C77ULL, 0x961381E1DD7DD8FBULL, 
            0x32C2496CEE4295EBULL, 0xD2CD181FD369D8F7ULL, 0x2E6AC18E1F28D0EAULL, 0x5F9074B832352D39ULL, 
            0xF97475E378624E92ULL, 0x536520B50A89EF07ULL, 0x951C938A9FC47D03ULL, 0x1302AED543712531ULL, 
            0x519D4040B2E98784ULL, 0xFA4F466D9711D7F2ULL, 0x3A8508D49B5C3FECULL, 0xEAECF601F630D67EULL, 
            0xE7448FCFF63BBCCFULL, 0x289AAACE30257889ULL, 0x8A333A35337AD896ULL, 0xD32DCBE2ED5FB8C3ULL
        },
        {
            0x464084BF74C6EDC2ULL, 0x97EB9F921FBAE123ULL, 0x54BA02BC5024552DULL, 0x6A4837C52D8E6AAEULL, 
            0xBAB6136406808730ULL, 0xE127645B26B7C213ULL, 0xE73F2B5C1DFA7021ULL, 0xDDAB18A6CE4EEA01ULL, 
            0x3A39CE42698860F2ULL, 0x5E88DD6F0641D584ULL, 0x87CAB577A4A85A49ULL, 0x82F850B5E90ACEE3ULL, 
            0x560A70AD1B6EE07EULL, 0x5F0510028F1358E1ULL, 0x1C1C5E9942E7209CULL, 0xE50FB080A0B4E9A6ULL, 
            0xD99326C44360FC01ULL, 0xEA0F86280E6529F4ULL, 0xE2D630F7DBF08CDBULL, 0xE10B499C84EDE2C3ULL, 
            0x7662A35670775CECULL, 0xD32642F15E68BCEDULL, 0x81EE7975AFEB9A3CULL, 0xE9E31E593723C013ULL, 
            0x689A79D3C70E638CULL, 0xE997A619201DFA4AULL, 0x8BDE2CAA6CA739DDULL, 0xEFC14EDAA0C1AC92ULL, 
            0x881F7A448261787AULL, 0x3CC1A99B528585DAULL, 0x25E5AB133CE74980ULL, 0x7BADA3A619CAC568ULL
        },
        {
            0x685CD6FC31833666ULL, 0x2758F7AB2E74C1E5ULL, 0x802275388381EDCEULL, 0x19861882D252988FULL, 
            0x4DA555F965DC421CULL, 0x33A130DE5C4E4563ULL, 0x673F20E0EA6BA7BAULL, 0xEBD13DE2EB0E473CULL, 
            0x28F578A1679C4662ULL, 0x54628D19B6ECD05DULL, 0x19CB5E96EB4463CEULL, 0x4A8C3B6016562057ULL, 
            0x1BFC24FDD067B622ULL, 0x3400AF2688BF80E1ULL, 0x95C7A8784A42A922ULL, 0xAEFB0420B667ABFAULL, 
            0xD0D109CB8BED1243ULL, 0x6FC67A9592CE72F5ULL, 0x36A017AC8EA6A8C7ULL, 0x764120ECE399A451ULL, 
            0x85AEADF61A470F16ULL, 0x3AAD82C7102E7B44ULL, 0xBD4D6B2E58FBEC3CULL, 0x4D500279C15B99C4ULL, 
            0x7967E4973D0CA406ULL, 0x8D44A12B17EAD875ULL, 0x19813875E40D35B8ULL, 0x96DFB733F486CF4CULL, 
            0xD2D44258FD7E6986ULL, 0xC686861D4A91A0C7ULL, 0x964452A23BCADC85ULL, 0xC0C49CFF95A6AE3CULL
        }
    },
    {
        {
            0xF8A97CF80D6B4251ULL, 0x5BADCEAB2CB6AB30ULL, 0x78BA18915C5641C3ULL, 0xF97981FB704A6C71ULL, 
            0x016A5BB1337B5FF9ULL, 0xB46224E5CCAD2CE2ULL, 0x0163D6556EA90875ULL, 0xDC68E5788702011BULL, 
            0xBD5AB2A99678CD01ULL, 0xA826AF8B2B656087ULL, 0x3D90AF7A3B82DA38ULL, 0xD4044AA15AA387DAULL, 
            0xD99FF4D036E1569CULL, 0xFA8ACEDB6AFF9E86ULL, 0x12CEEA5BFBBDF683ULL, 0x7018CC16F3AD2C4CULL, 
            0x76DD8C62E0F68AB4ULL, 0xC5BA990E0BAB7A2DULL, 0x6ACCE07980454E6DULL, 0xB92134D04421FF8CULL, 
            0xFD96EA9755204F79ULL, 0x7A592FE19B3C9476ULL, 0x3AB445CE3B3DC6F4ULL, 0x78BD20ADCFD7FA5DULL, 
            0x9CD8DB8091FA94AEULL, 0xF76F5DBECF43DC1EULL, 0x50D4DB7E4F0EF406ULL, 0xE2D288304ECE50E8ULL, 
            0xF556156C882BB9C8ULL, 0xF6D0FA151DED7CCAULL, 0xFCD5C4C0C1DEEBD8ULL, 0x24A0C65E49C60700ULL
        },
        {
            0x25855A6E575C26DDULL, 0xDEABD12476AD5C5DULL, 0xEC4E0FC1E0134759ULL, 0x22F0EF6874A47684ULL, 
            0x9ACF00EE024F35BFULL, 0x9FDD17DDCF69E273ULL, 0x27F9DE5F66700DECULL, 0x58EB2E34E3E80717ULL, 
            0x99DC4226FF872D4FULL, 0x4E85BA369FA6190DULL, 0x941793AE1C943E79ULL, 0x6828BDC01CE1827BULL, 
            0x1FC55EC8A8998079ULL, 0xCB87BE4966B71514ULL, 0x0B236750D552717EULL, 0x0741A8987F46C44FULL, 
            0xBF422E7E6A9C9070ULL, 0xCED1D041213CDB63ULL, 0x69B58DE115B69110ULL, 0xD72E2551F021FA9DULL, 
            0x45995AF4E7594C9AULL, 0x755A15E055B3E833ULL, 0x4F284B3A5AB5070BULL, 0x208B1EFBA87D874AULL, 
            0x1B9E55C3278B4125ULL, 0x07EEA768CF0A6471ULL, 0xC91D2C14A9536E09ULL, 0x655605DA191724CEULL, 
            0xDD1DB467DA806617ULL, 0xA7BEEC1F4190EE9BULL, 0x5EEF91209DE5EF5EULL, 0x0FA2D59C8A72FCF3ULL
        },
        {
            0x0D54145FDF173AF3ULL, 0x9AD51D987B0965EAULL, 0x32058A5D1EBA0A97ULL, 0xF2897AB4CED9E6BAULL, 
            0x71873A8ABB9DED88ULL, 0xBC37AF498B7D19EBULL, 0x1C43F4112EE76E45ULL, 0x01C0FD567371531AULL, 
            0xE0590DCBDF00B2E0ULL, 0x0B0E48A3DB8BD092ULL, 0xDA91C6B950778275ULL, 0x6FB1A1860C267E72ULL, 
            0x09FCF41FE589A4F8ULL, 0x48AB4358291FF05CULL, 0x396BEAB95CE4E4D9ULL, 0xB004802BC35127F6ULL, 
            0x5FA123B158A28E49ULL, 0xAD1CBD2217939863ULL, 0xA0A33C29684C63F5ULL, 0x3BEFBB90A1508F5CULL, 
            0xA0A2175EA87D14C4ULL, 0x44BD1DE8790F503EULL, 0x10D1F4F2E185EA3AULL, 0x4E6D86CA999064DBULL, 
            0x2DDF250FF5E62CC2ULL, 0x401E55BE09A1FA7CULL, 0x731E3D80E5F88BADULL, 0x12B680358E319256ULL, 
            0x0FC42829A235CB74ULL, 0xE8ED8F3E3CD283B6ULL, 0xD2510AF2C70BA698ULL, 0x47DB07431CE32AFDULL
        },
        {
            0x032146ADAA565D36ULL, 0xA2E5C4DA73B3AE09ULL, 0x264B720278FE1D4AULL, 0x5B03152DCD297C54ULL, 
            0x6566A3312065C66FULL, 0xC300D7C6CEAF7E93ULL, 0x4E0BB3F95230F778ULL, 0x422A96ECBF944F52ULL, 
            0x5B6F99C821E13E75ULL, 0x99063AFA6B63A79DULL, 0x92DDC4FE5B497388ULL, 0x006AAAF252A11650ULL, 
            0x85F87DC766DC54C9ULL, 0x21C98D09F1EE0E9CULL, 0xC47F0A59C9A5BBE4ULL, 0x6C5D85DEA0245A2CULL, 
            0x07D1B99A19639A09ULL, 0x056D2699092E1D2DULL, 0x8A151A9B6648A6B3ULL, 0x40300DC8C2D8C96FULL, 
            0xB9B12A77663B8E4DULL, 0x2E4463AD5BB7B518ULL, 0x1AB80C33AC7A1ADAULL, 0x5C4CBF98A7E15B6DULL, 
            0x29D2325AECF8DC35ULL, 0x67D0C1F2DFAACC25ULL, 0x49AD7938374A5150ULL, 0x3A1A179AB9D388AAULL, 
            0x428F5808F1DD7EBAULL, 0x0F8C419DB43BD8CCULL, 0xA7D4C099B70FEDAAULL, 0xBDAD9DAC8B91B72EULL
        },
        {
            0xB580AAE7C150ADECULL, 0xC6ACB129664BBBD0ULL, 0x27609A7BE656BCF5ULL, 0x6A5FB2B3BF7967D2ULL, 
            0x813772C69271B45AULL, 0x1DA561148741EBFFULL, 0xA8CF15A7E7FD62E7ULL, 0xF2E66760B19E7919ULL, 
            0x8E4DE3E3019D3F92ULL, 0x1BCA652D2804CFE8ULL, 0xA12A30A24CF7D97DULL, 0x7CD81AD583405BE0ULL, 
            0x7C1CA3D5E575E62CULL, 0x82EE678583C70685ULL, 0x8E34779893028720ULL, 0x74CAFCB5C8DD0808ULL, 
            0xA01B2C546A372946ULL, 0xEA91FD8CED11B8C2ULL, 0xA1B3283D32B05C95ULL, 0x4D90625F83077D17ULL, 
            0x7E1DE2087C214056ULL, 0x1D9107E0B1CD2DF5ULL, 0xD8B1FB9830EEE7CFULL, 0x26F351F7C2CBC412ULL, 
            0x72CE13662CBB88C2ULL, 0x717E1E52DDCCB85EULL, 0xEE9A59DB47B8E919ULL, 0x14920B07D41F9ED4ULL, 
            0x0A6E0618E5ED1793ULL, 0xC9E7D6AAF8F3F8A6ULL, 0xCA43F48D5D358FD8ULL, 0x9D3A136487C52080ULL
        },
        {
            0xDE0461463C796667ULL, 0x6CA63152F8BB63E7ULL, 0xE4FAC159DA9AEFD3ULL, 0x3A1B85278B8549FAULL, 
            0x5951958D121FC40BULL, 0x3921B96EB4409E9BULL, 0x135F6567EE555081ULL, 0xE7A55742CD6BB908ULL, 
            0x2586EBF0B2F67D61ULL, 0xA0A8B8AC4008EE60ULL, 0xEBA31B93316A02D6ULL, 0xEA0B96D778EBFD63ULL, 
            0x975E1C880B049471ULL, 0xBD77BB07B6A7A4FEULL, 0x570774ADAB478662ULL, 0x292A04BF1E594B38ULL, 
            0x84EC7F26E728AC98ULL, 0x0DA2C3221028F196ULL, 0xC546B7FFB6BFF57BULL, 0xEBCBEB24E695390EULL, 
            0x879A5675A2C5DA58ULL, 0x19C4349A82847CBFULL, 0x94385707BBCF9256ULL, 0xC4A05BA07EC7AAC2ULL, 
            0xF2D354B471124BA8ULL, 0x74F922E928DAD4B6ULL, 0x37BFDB940E179BE5ULL, 0xF2BD4126C46454EDULL, 
            0xCE20DD5198D99376ULL, 0xC77C8E4279D980BDULL, 0xA5AB50CD42EAC54CULL, 0x7D911E828701DAF6ULL
        }
    },
    {
        {
            0xCB09E6CF63FC2B04ULL, 0x207DF19613C34966ULL, 0x0390845A9AB0F789ULL, 0x1AAB2B44F6C5D0A1ULL, 
            0xF483D00357DDE316ULL, 0xDF0BB5466B8F5AD1ULL, 0x5F39F2D142A8D581ULL, 0x58C8322D35BF6580ULL, 
            0x717F431C6015EE04ULL, 0x959144DB276913D1ULL, 0x11BF4F852DE1D1D9ULL, 0xE07E10F0FED34AA8ULL, 
            0xA22D93004EAE0D23ULL, 0x267283DD46401162ULL, 0x09EDD38784448AAEULL, 0x504F0C8918BD284BULL, 
            0x8F19BF14BC10DA0AULL, 0x4CA3D7C5937EB3AAULL, 0x41165792470E7444ULL, 0x296465B02728E35EULL, 
            0xDD82792CBE0349DDULL, 0xF479A8EDF84DA0C4ULL, 0xB09F4A16D1B2C8D2ULL, 0x52BAEE41005B28A6ULL, 
            0x25A29A1F1ED636FAULL, 0x9A929E6BBABE01CFULL, 0x0FC4250CABADEE68ULL, 0x6B31D0117F0642B3ULL, 
            0xD8A499BF1168C91BULL, 0x243C7EF73179BD8DULL, 0xD2A162BCABD7C808ULL, 0x116A5F39F53A0D7AULL
        },
        {
            0x17B66D845E571851ULL, 0x8005EFD327DF95F9ULL, 0xFB7EBF45A603E0A5ULL, 0xBB0F89D6C2F00132ULL, 
            0x7591B0C79E5739B8ULL, 0x98EDA278F355FFE0ULL, 0x86664EC2E2197B8FULL, 0xE729D2C956888487ULL, 
            0x1DB42D7594795FB7ULL, 0xDA7F514268BEE990ULL, 0x1A774709DAB7EEBDULL, 0x440A6B9C61C1D546ULL, 
            0x55D1509FE086F5DCULL, 0x8BA99542AEE58AEAULL, 0xADBC8F5C6567A2BFULL, 0xFF4115EBAA31CAC9ULL, 
            0x5DC1EB87B08A70C4ULL, 0x93BD676B3647FDDFULL, 0xFB7B5B16BDF43E29ULL, 0x71125F04E7F14764ULL, 
            0xFFD0D9FC21944598ULL, 0x5DAF3DE8201E14D5ULL, 0x435252F3844D0874ULL, 0x316917023258528EULL, 
            0x00A60A2FD218D2FAULL, 0xFFA0262F7A92639AULL, 0x16521CA230DC072EULL, 0x28B9CDFF9ED1515CULL, 
            0xC046CB3AFBF03FEDULL, 0xC2C7F9045176408AULL, 0x4620CCC9DA9A2C99ULL, 0x91A3B0F8DD536FECULL
        },
        {
            0x0CD600EFFE71BB55ULL, 0xFCDC1FE3A65A1FD7ULL, 0xB8C7A69EF68E9543ULL, 0xBB4FF8FD5615A911ULL, 
            0x4B0077EA841082F3ULL, 0xB89E0E4B986FA2A8ULL, 0xF4C416A604A31EF3ULL, 0x8DEC5A6653A69E0FULL, 
            0x740053F71ED8C70CULL, 0x29B60AAAF38926FDULL, 0x6B6DC60E4B8A9ECDULL, 0xC1CE2140CBE8FB91ULL, 
            0x1FB28DBD5BF1542AULL, 0x6774BB14871F8F00ULL, 0xD2E2CF16B781248DULL, 0x6D16A1091B362B3EULL, 
            0x3DA53B086A20250BULL, 0x7D56A243A5E89C6DULL, 0x859341E88EBD9861ULL, 0x721A0B66D1ADE8E7ULL, 
            0xB8265285EF5FF29BULL, 0x14F2FD4FA7AB7AEBULL, 0x3E07E49F5FF9C82BULL, 0xC23217A932BA05CEULL, 
            0x29EFB9EBAC8B962DULL, 0x5E3C93271496DE1BULL, 0x224D4292B78150E6ULL, 0xD7A51315BA9A44ACULL, 
            0x48CD7BBA801F5DC9ULL, 0xFF7574E3E93BA82CULL, 0xDBEACE46DA6AA1DCULL, 0x1A579794D7DC7ACBULL
        },
        {
            0xC5963914081B9314ULL, 0x5169DF361C3BA06DULL, 0x46B69610652042D5ULL, 0xFE35EE876586E441ULL, 
            0x2576A38E37DBAFE1ULL, 0x0022C7C54257F467ULL, 0xB8E3D96979A6018CULL, 0xADA872CA95AE0734ULL, 
            0xB9001F1018008271ULL, 0xF4C1AE546C0CB7C0ULL, 0xE05FB3AF461BE2F3ULL, 0x6842BD3A19F0745BULL, 
            0x91834A98E801A73DULL, 0x43EB9649542843F7ULL, 0xADAD66C492EE8855ULL, 0x71BCABB185548BDDULL, 
            0x6B5C11AC81290E1AULL, 0x09EB8D3AEAC0EE70ULL, 0xDF1760F8DAA70F78ULL, 0x696AC4BB25B32CBBULL, 
            0x04C803B9FB7404B8ULL, 0x15C21D426F4246B8ULL, 0x2B6B85B2878A6445ULL, 0x50CBEA1707C8E7C1ULL, 
            0x199CC8BA1EF98443ULL, 0xCD6D04004E71AEEDULL, 0x5251576374670DC6ULL, 0x834ADDAE74DF6715ULL, 
            0x878191B5ADEA7C17ULL, 0x98AF01EC9E90953AULL, 0x50C4BA417CFEFAC2ULL, 0xB2E5118F6E217F1FULL
        },
        {
            0xB030EE0D1F1C515EULL, 0x703D335A436CA47BULL, 0xCC57BEA2E2893AD9ULL, 0xBB0BC57661DCEC0AULL, 
            0xF1D2C6CBB38D70ABULL, 0x0005EBE6C23B559EULL, 0x7F3795B7FA931B68ULL, 0x05AA0510B5D61A79ULL, 
            0x9BB0431136DFEDC6ULL, 0xF72C7B1B7C6B25EFULL, 0x67B6E492DAA7345CULL, 0x99AB667C8FAD4C7FULL, 
            0xB7BE1BC2C04D1FCBULL, 0xDD27BE13B6133ADCULL, 0x06E5FB852DF194F8ULL, 0x7139B01C47168698ULL, 
            0x8F9BAEB1131F3B42ULL, 0xAE677F254F037991ULL, 0x6CB85651A75F9BF8ULL, 0xE048F837E5570559ULL, 
            0x27DA4CDE5426FA25ULL, 0x65FDCEBD2E40D171ULL, 0x220827E40B24474BULL, 0xC549AEF77C048E0BULL, 
            0x48A5F97304AD9303ULL, 0x1CB354AC86E37EC2ULL, 0xF9C8C4E8487B4457ULL, 0x366665894B739BC7ULL, 
            0x32A2A8F1E4AAE877ULL, 0xE454CC6CBD416617ULL, 0x812512F2CB131FE9ULL, 0xD2BBD67A9DE04EA7ULL
        },
        {
            0xE809E06520BE3033ULL, 0x617FCAD8A7D94C3AULL, 0x9A146EDF0A6DB938ULL, 0xE21A77AE4466EAADULL, 
            0x038B8C7D889FA421ULL, 0x31A4BFC2F8A95BCAULL, 0x1C8B0B835FFDD6FDULL, 0xFDBB6810A0C057FCULL, 
            0x4B5CAC9A90FFE39CULL, 0x6E77181A5BE3D972ULL, 0xD1DF0335900F9F6AULL, 0x36204C20D3888BF5ULL, 
            0x81B004B8733C78A1ULL, 0x623854D435BE7D2CULL, 0x6E5F37925920065DULL, 0x357341639DF96970ULL, 
            0xF8E7EB61FE96251EULL, 0x9C7717221B48962CULL, 0x15346C88F23C3BD3ULL, 0x47DD21531F65DD3EULL, 
            0x1049E178AC2EA5AFULL, 0xA074D37C7151BC9BULL, 0xE8663DBDE02C1D01ULL, 0xBBB758A566AAFCDBULL, 
            0x73E2B3A2DB8BC1B6ULL, 0x5C437AC3B79876BDULL, 0x7181A2132DAE7373ULL, 0x71DA71BBFB78A342ULL, 
            0x626A0CD844F6D8BBULL, 0xBDCF83EBF33ADACDULL, 0xCB78C879E52FCE7EULL, 0x32B2688AB14B5E74ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeyRotateBConstants = {
    0xEF7D7FF035F85BF6ULL,
    0xCDF735493FC1E7E1ULL,
    0xABA255344AE8B4B1ULL,
    0xEF7D7FF035F85BF6ULL,
    0xCDF735493FC1E7E1ULL,
    0xABA255344AE8B4B1ULL,
    0x0A3582049041D482ULL,
    0x7113094E019347FFULL,
    0x86,
    0x3E,
    0xA5,
    0x65,
    0x05,
    0xD8,
    0x3E,
    0x67
};

const TwistDomainSaltSet TwistExpander_Ankaa::kKeySpawnASalts = {
    {
        {
            0x6AF002D21CDF1E8DULL, 0x1AB1B80C7A1BED70ULL, 0xCDF70734FDA22950ULL, 0xB6FED82256568549ULL, 
            0x07C2BEC4E1752FFBULL, 0xA9C8DC6C0066B7A2ULL, 0xAB3F24F9BB2C4D88ULL, 0x37DB626126B8B1B8ULL, 
            0xE326C766FBE6C86DULL, 0xC30C0A1CC33BCF9CULL, 0xAE8FE5FD3291B9DAULL, 0x280F7DA2E45A63F5ULL, 
            0x20E2589868F5F6B5ULL, 0x1DED055C59479269ULL, 0x81DBE5878E9EEA7EULL, 0x5D1DE63A39C9609DULL, 
            0x4410BA01570D3B72ULL, 0x6A1953CBD106755EULL, 0xFF50C374ED9E3565ULL, 0x0AA3B7A841E2FB63ULL, 
            0xFCF500E49075F51CULL, 0x27A0741D90D90899ULL, 0x39D41A8C0A5A6BF4ULL, 0x298BBC862682B6F1ULL, 
            0xFAD9F5162E335317ULL, 0x03DA7679DDF4D107ULL, 0x7720DB9DE60DD9D9ULL, 0xFD02C080F3DA9D1EULL, 
            0x9EDECF1D62CB9AFBULL, 0xB7994031B1343A86ULL, 0x4728127017FE406BULL, 0xF93A4EEDD4883364ULL
        },
        {
            0xC30BC16B71273F72ULL, 0x82C3FFBBDF9BDF67ULL, 0xCAA1CCE0780E47C0ULL, 0x6526E470FFE1B585ULL, 
            0x11F536D1C251758EULL, 0xF63C7BFEA5B9E4B6ULL, 0xA9839AC5644B340EULL, 0x7C97898C135CA6B3ULL, 
            0x3FEC66AB1EF9CD2BULL, 0x60D1D757D62A62DBULL, 0x808011D2DEFF4429ULL, 0xFA0E621243FD7D38ULL, 
            0x05296A599DA2CF0EULL, 0x70CF5E91C2602940ULL, 0x56547EC6C8387CD9ULL, 0xB4C4EA29781EB7A8ULL, 
            0x6CCCB66A99B334F1ULL, 0x9128C79359EACB52ULL, 0x994C48EC3782E9EBULL, 0x8E5C97FFFD4E0D96ULL, 
            0xE734576A039A5C12ULL, 0xCFE1EF45B8C69FB7ULL, 0xB68D6ACB53F53F4EULL, 0x973DE999E9D3F25DULL, 
            0x7A0F11A6471A5DB5ULL, 0xE086A6611D3A1B27ULL, 0x2FD1EF32F1419F98ULL, 0x8638262F79F5384FULL, 
            0x829577CDD3271E43ULL, 0xACDF407EDD9DB96BULL, 0xCF113411DEE68A63ULL, 0x6E7392C9FF8B894DULL
        },
        {
            0x979AB253CB81C067ULL, 0x0A81018BB212C53DULL, 0xF0766F0C2D34491FULL, 0x2FC1FF73ADE7EC80ULL, 
            0x0F0903F30A51DF92ULL, 0xC9FCC770477CB9C6ULL, 0xFE8217F3ADF4F6A4ULL, 0x9C25F8547B048F88ULL, 
            0x579D1665C94CEAF2ULL, 0xCB8F94788BF7EB70ULL, 0x8953579223BFD1DAULL, 0x93C1B52D2D14F149ULL, 
            0x5934360BB1797547ULL, 0x491B6534BD0140FEULL, 0x7C4A8EE328D6C209ULL, 0x25C2EDFB228DB8E2ULL, 
            0xD0809EEA9B082827ULL, 0xE3D4EB1B1474E515ULL, 0xC6616349E40B3C2EULL, 0x0007E410E9B46C21ULL, 
            0x96FBC5481D1D618CULL, 0xE2C0DF7E2B19DDA7ULL, 0x6F6D16F59E1CFBB6ULL, 0x08A4FA47CAB6EA7CULL, 
            0xDABFCBD48AF8B699ULL, 0x1716BC38D30DB182ULL, 0xF8F3A9FBB216DFE0ULL, 0x086650EA8C9F9CFEULL, 
            0xF184232872CDEA74ULL, 0x6E22277CCA057731ULL, 0xB7248FCCA51EF924ULL, 0x4058E7FCBBA3E617ULL
        },
        {
            0xD9858AF33F4A4D1CULL, 0x0BBEB63B7DAF0772ULL, 0xCF542AA7B4F8D516ULL, 0x5B75653A929F75FEULL, 
            0xB208FCC58DCCA1F4ULL, 0x901905130871F983ULL, 0xC5F96095EEBF051BULL, 0xD2222F92B24839A1ULL, 
            0x3BE4AC62582AAC5EULL, 0x1EA74BE87A90C9FFULL, 0x92127C1A0883BE79ULL, 0x4C27713152A7F088ULL, 
            0xE0890654745D6123ULL, 0x0094B83519EB56EAULL, 0x2ACE2A15ACE66E41ULL, 0xEEF64EAF7C30F153ULL, 
            0x7BF579FD442F9517ULL, 0x2A0A4C54B201DC51ULL, 0x00247B4A489B9805ULL, 0xD57C38E4AF222732ULL, 
            0x424D50476ECCB119ULL, 0x27E72A81486AD671ULL, 0x527EFA28C4B0587FULL, 0xB00CD5CD41F539B4ULL, 
            0x351BFB8A46D92BCBULL, 0xA39FEB0D677D38D9ULL, 0x97F3236E7A0C5D55ULL, 0x4EBB5A2166E035BAULL, 
            0xAAED97D605812E92ULL, 0xFE53B7E7DCCA337FULL, 0x1746EF0B0FFE2029ULL, 0xC0C8D0047F55D5ACULL
        },
        {
            0xB0A6FEB12127C238ULL, 0xA9AE793E92B6F9CFULL, 0x21F05E1185C2CD1FULL, 0x81DD67D47459A1ABULL, 
            0x33452268C56551C0ULL, 0x7F9E6C7A418A415AULL, 0xCA6CE096F0E37DCCULL, 0x88755B8A85F47040ULL, 
            0xA8E269C77EC7CE6DULL, 0xF0CDFEA2FDD56B5FULL, 0xF76357E6F28120C1ULL, 0xD92F8423C2F5E797ULL, 
            0x4BE908752E33F824ULL, 0xD0BD116C45DB220AULL, 0x558CDAE9567ADB26ULL, 0xB07327CE0E97F6F0ULL, 
            0x47EB20948FD2C1FBULL, 0xA91217928F964E86ULL, 0xBCBE165E87CD6409ULL, 0x5D6D18A27D282C1EULL, 
            0x46AD2C01B3241C01ULL, 0x4C5D16CC6C4B0E69ULL, 0x545DC93BAF7E813BULL, 0xB0A322854F71FE34ULL, 
            0xB40898AAF4C4E361ULL, 0x3AF61D21C5242DDDULL, 0x6B4945C6FABBE212ULL, 0x2184E34EAA67D648ULL, 
            0x06F5A9A05314E55CULL, 0x090F3CCFCBC82CD0ULL, 0x1CADCAE78FFC8D4BULL, 0xF0C118B2976154C0ULL
        },
        {
            0x7AF8B20EE9D12579ULL, 0xD85F27F9E55F2F65ULL, 0xA22DD3C379A0E602ULL, 0x1ABD2199DA45D76DULL, 
            0x8436FA069445F13EULL, 0x6240A0AEC47B9F12ULL, 0x2193C85A66198659ULL, 0x7B18FCF9BE7ED4C3ULL, 
            0x78DC443DD27297A2ULL, 0x50E49FCC9D0D42E1ULL, 0x4E0C7D77463E1B49ULL, 0x46A231EC377804F4ULL, 
            0xC9D1B0FD46627CE5ULL, 0xC6D7B3B3EC6C90CAULL, 0xD88A48A01F74C526ULL, 0x0B7C3070E5B237D3ULL, 
            0x3AD6C043AF1C0892ULL, 0x4DC89C7E7759FB6CULL, 0x66A05D7ECE91B2E1ULL, 0x8E22BAF7F52DA25EULL, 
            0xB13A5362303E594AULL, 0x873769AF4CEA43A4ULL, 0x8C8D2B233662A00CULL, 0x00274C83267BF671ULL, 
            0xB60D512AFE6DAD95ULL, 0x9C2272FADE9F62C4ULL, 0x6C9367081CA0FF16ULL, 0xA4DC4A8830869787ULL, 
            0x0A079C5A611E1658ULL, 0x3DFC8D36D1B6591EULL, 0x9570CC1736ECFD47ULL, 0x695B2F95F0C87E1DULL
        }
    },
    {
        {
            0xA3DF94607EAD58F8ULL, 0x03E598CD9206785EULL, 0x6DEB7DD30EE9187BULL, 0x8EDC563B32BE0144ULL, 
            0x97900CA66CE84C9EULL, 0xD092E81741DB0580ULL, 0xB5C152D34D4A661BULL, 0x67559ADBE19F48D7ULL, 
            0x111C7F0FEC3D8AD5ULL, 0x37AE0C9F6309DAB0ULL, 0xE9AE893155C0AF5EULL, 0xF00F5F3D8570DF5BULL, 
            0xEB3A808FA3E24C0EULL, 0xC6AC32761A17CCBFULL, 0x9E1A84D0FAA2EF86ULL, 0xE5E764C2C968CCFFULL, 
            0xD15EA73090AA25D4ULL, 0x4B91F14F76661FCDULL, 0xA6754053127F3541ULL, 0x1CE75DBFCA08D8BDULL, 
            0xF007EE7EF9B56B54ULL, 0x6C1E2274A808E346ULL, 0xE01CCF44DB4E376DULL, 0x647B43ED9F96AA19ULL, 
            0x7AC00CFECAEE207CULL, 0x4DD3CB98F2B77171ULL, 0x5573D486DD18291AULL, 0xE9A70E0F994D00EEULL, 
            0x34686F1200175AA6ULL, 0xBF055E1F0A3B9FE2ULL, 0xFD29693034572F83ULL, 0x01657685EBDFE6C7ULL
        },
        {
            0x632F4D0FAECF5ABDULL, 0x0462DEDA03105D49ULL, 0x827FDA991FC1F133ULL, 0xECBA56412293CBA7ULL, 
            0x94E2127435A3DD3CULL, 0x3A327EA7A2DA3B41ULL, 0x253626844109F6D2ULL, 0xFBE900814F10C486ULL, 
            0x2797899966B0FFEEULL, 0xA503ACB52476B834ULL, 0xB7527BFFF9C62784ULL, 0x594F425E968E5A2EULL, 
            0xF2707716C6E4FD1DULL, 0x72D9DF7A473984FAULL, 0x8B38B886FB9DF32FULL, 0x066251CA6BA7111EULL, 
            0xC5500CE3F8FC15DAULL, 0xD69622D0B6209025ULL, 0x4CA97AB04E97F57BULL, 0xDA30EC3F090BCC36ULL, 
            0x0ED8FEF62A0A1BC1ULL, 0xE88BF2E5EAEF8755ULL, 0x697AAFD403DB1DD1ULL, 0x1D75CA25B3BA1006ULL, 
            0x7B7AC1716D9191F4ULL, 0xB199EF8DFC2F4073ULL, 0x17D1D22F074E197AULL, 0x13496E638214CB20ULL, 
            0x285F2D333FCB8054ULL, 0xD378610F3F045CCBULL, 0x5F840CAE1AD275F8ULL, 0xBC7B679D217316E4ULL
        },
        {
            0x7CF688D116AB55F7ULL, 0x1DD8399A554E820DULL, 0x56B39198062040B7ULL, 0xABAF58ED111DFE4AULL, 
            0x025835F9133CAF85ULL, 0x3C0D72D2206DD616ULL, 0x4DB2EC4C408C86C1ULL, 0x016848172179C499ULL, 
            0x799A729AD7F94F8EULL, 0xCC0457F9002324B0ULL, 0x240B94E6F0E81173ULL, 0x7F9766B1DB535CB1ULL, 
            0xD49CD5CACF206FADULL, 0xEBE02F563F9B0A8BULL, 0xA05392D57C6C6F96ULL, 0x089DDE3A27DA6907ULL, 
            0xF11448DCEE790066ULL, 0x2BEF8711C5CE9A75ULL, 0x652B8DEB0B89020FULL, 0xD66525C0BDC2F9C0ULL, 
            0x339BD29CC1E06830ULL, 0xDD32EB8C48FB043AULL, 0xD9BEF52D024A0EEDULL, 0x0FCF1A94E5933334ULL, 
            0xA80487B80B810881ULL, 0x5A6842235750DE02ULL, 0x8D945B6DEB27C0C1ULL, 0x61B45490CC83EB77ULL, 
            0x611D3BFC6C2B1277ULL, 0x540633CE23FA4D9EULL, 0x8EA2E7DD1775EF61ULL, 0xFA2AEE0076A7CB40ULL
        },
        {
            0xFF9E93B66708BE31ULL, 0x4DE4B643656D6E3EULL, 0xD508D53B8A88570BULL, 0x21120425485B3652ULL, 
            0xDBB69740CA7F17A2ULL, 0xF586C0D1D01C9216ULL, 0x09A821BA3D7B0D61ULL, 0x740E5E9F05927056ULL, 
            0xEEFA19AFD8E807ECULL, 0x74211DAB78D89AB0ULL, 0x98EEA544B93349A6ULL, 0x82B73D47AF8F009FULL, 
            0xA2E9FCE17C24513FULL, 0xC252D94D8C182D9CULL, 0xF8AAFC9EC7B353EBULL, 0xAC6961A65EC31CA9ULL, 
            0x43816A23220EFA58ULL, 0x0A9B4A8B80E8F37FULL, 0xA31162EBE2E64D29ULL, 0x1BA6C32F18B054D4ULL, 
            0xD3FEAB676FE56BADULL, 0xAFEF037F66DC98B5ULL, 0x24E4091C04B928FBULL, 0x9593FA456EC7B7EAULL, 
            0x1CC1634E88BA9D69ULL, 0x227348701A6554A6ULL, 0x9C9366BD05233933ULL, 0xE0D0B24973969642ULL, 
            0xA2A4300786D8C285ULL, 0x4E141AB93BFDAF25ULL, 0xEC7E7A47DF6603ABULL, 0x3151AD6360B04A2DULL
        },
        {
            0x17B77137CCBA90AFULL, 0x331DFD01D64A20EBULL, 0x16E205DF4D5FFE9BULL, 0x26B28B181ECB2240ULL, 
            0x268320CB117910EDULL, 0xABE411977DAAB1D3ULL, 0xCE21C5837FCE7AC4ULL, 0x8CEC91628CB2C9E5ULL, 
            0xE527961F4D1DE576ULL, 0xDFA616CE60F5739BULL, 0x5DD66E21138CF00BULL, 0xD52F87FE76FA04E6ULL, 
            0x88D444F9197EDDBCULL, 0xF71610A6A964FDC4ULL, 0x9C556CAAA41DB633ULL, 0x13B3C8EA07CE3A5CULL, 
            0x6E5862387230622DULL, 0xE08F46FC36167ED9ULL, 0xF61619CCF4425390ULL, 0x08019F9D6E32F583ULL, 
            0xA50C6693DB659E32ULL, 0x285A9F312816D661ULL, 0x9B1230F66275FF67ULL, 0xFB0E7E1BEC4E6144ULL, 
            0x52564C898661FEF4ULL, 0x8D7AD5CCA3E83696ULL, 0x9237FA914594A582ULL, 0x1D7B94E059E3FE3DULL, 
            0xE73CF7ACA1B9F7D8ULL, 0xC52E2850A0C77D87ULL, 0xBEE4A266AC1D29EBULL, 0x5FFCF646A8A3A951ULL
        },
        {
            0xED24144E08C98657ULL, 0x4B2B43993E1CCD66ULL, 0x5C4B5078321DBBFFULL, 0xD0DB92E442048D51ULL, 
            0x75CB3E69B16D2844ULL, 0x5FD971C4D88EC647ULL, 0xE59616F399D3E7A6ULL, 0x4ECA39BF37F3224FULL, 
            0x86E7715CBCE3B861ULL, 0x2A0F261B299457EEULL, 0xE6F9AF5567DC6983ULL, 0x6B00ECE57C5689D3ULL, 
            0x33F6379862580DCFULL, 0x17EAA798E69C2C36ULL, 0xD08EE5CD37F8E625ULL, 0x65691F14FC3D7CC8ULL, 
            0x0A4CBB05689F8C9AULL, 0xF4F441077DD82E74ULL, 0xEDC4ACE7D93376B1ULL, 0x53A07B4F02A6B760ULL, 
            0xFBA9AE951F2E3A17ULL, 0xCFC2D0AE6035E00AULL, 0xC383C3CE9F49C4AFULL, 0x10E86BFF579840E9ULL, 
            0xED1F5DFEDDF0939BULL, 0x5CF16431306DD7FFULL, 0xF7B41089B14269D4ULL, 0x6F380063613F3C2CULL, 
            0x91AEF39480E7EAECULL, 0x3C397AE4A8574FE3ULL, 0xE68FD02F4FA17B8BULL, 0xB0AE5525A723DACAULL
        }
    },
    {
        {
            0x692B76B873B96BC5ULL, 0x1D9F9BA34E5655A1ULL, 0x036834F3B0356567ULL, 0x90A0439BEBB562A6ULL, 
            0x084B683EC1423E3FULL, 0x8EC5E54DAA210A42ULL, 0x0469D8C77EF6E4F9ULL, 0xDD2BB1AA790E7A60ULL, 
            0x9E198E3030B2DEB4ULL, 0x838FDD5E10D8D56CULL, 0x9F7F31B2F1D44C6DULL, 0x3335600340F1BDC5ULL, 
            0xC5D0D9ADCBC444C5ULL, 0xD34A43EE2ECF9472ULL, 0x2DAB83019D357406ULL, 0xF89C5B7E42A89DC2ULL, 
            0xA78C4DA8EEE94EE7ULL, 0xDCF0AB93344A6ED3ULL, 0xE55DC739A32A349FULL, 0x570A18021E6A65B0ULL, 
            0x9F5CBBE6A61AA3ADULL, 0xDE6090136B9D42AEULL, 0x2E795A7ADEB2F14DULL, 0xA43A3F8163388315ULL, 
            0xA9EA01B53F4277B7ULL, 0x82175C43458671DDULL, 0x04B3F88436B67317ULL, 0x8A4F8A5027DB9EE6ULL, 
            0x5D6126A4EA0E9C5CULL, 0x248C641176E45A54ULL, 0xB3DA68B2EBF3A46AULL, 0x23FEB234B0CEF101ULL
        },
        {
            0x893A0FBF86F90D8DULL, 0xA7D5D1D544C685F4ULL, 0xC6C943C1488D8039ULL, 0xB387639AA838534BULL, 
            0x098CF22AEC3E0754ULL, 0x51C4E40C29A669F1ULL, 0x0A7A102A7C7052FEULL, 0xEC12888C2D3B8370ULL, 
            0xF06D9EBE15E9ADD1ULL, 0x19F7B2BF9477746EULL, 0x7DEA7780E4B0DA39ULL, 0xB6A93D169D4C4217ULL, 
            0xD6895714BB1CE136ULL, 0x18A5A8FBD269BB27ULL, 0x72A789A1D8B61FE3ULL, 0x8FFFE9B701BF8AE9ULL, 
            0xBB89CB3B6EA2F87AULL, 0xF6D98F3B632D8A44ULL, 0xBAA790E874E3A9D8ULL, 0xDBE8230DAC7F65E7ULL, 
            0xDD9D198223CFE82DULL, 0xCC90842777F3515AULL, 0x4913DD4A1648B644ULL, 0x2033279B10F90F14ULL, 
            0xCC0EF19B0E5A76DCULL, 0xF19B2E964EC610F5ULL, 0xCB3F1B8C7B11690FULL, 0xC017AEDC0DDCCCFFULL, 
            0x3AEFFD8F08800A7FULL, 0x90A0345E124A3A40ULL, 0x5459C43AE5E05AA4ULL, 0xFBC223C820C72D4AULL
        },
        {
            0x5FC7035BD4B4D84DULL, 0x12F69D806C6EF422ULL, 0xB1768E276D8DEDC4ULL, 0x974CCC03C38C3317ULL, 
            0x32990BEA42A97E74ULL, 0xE75A0DF9AF5EE3E2ULL, 0xBF331D5DED0137CFULL, 0xA530920B204ECFA5ULL, 
            0x76CC3FF68A2123BDULL, 0x9AE36DAA4B320031ULL, 0x4AFC085CD34F728BULL, 0xE6801DDE468589A8ULL, 
            0x6CFB7A50783DFA72ULL, 0xF9B506D873A39632ULL, 0xDC6837D140122DC1ULL, 0xD58852D07112B87DULL, 
            0x27C1520E46786449ULL, 0xB0EEA4B39C118C9EULL, 0x51F462E8EDA4CF26ULL, 0x8BB6D6FF3E8D2DE0ULL, 
            0x99FA74A5D42B0FAFULL, 0x819A0B6926AD4EEDULL, 0x136E430C0619CEEFULL, 0xE7C27644E75C0CD2ULL, 
            0x7391B51D9F66E543ULL, 0xC81D970C408638DFULL, 0x6BDDB6EECEAF1ED2ULL, 0x6FCD1CEF9E3C19B1ULL, 
            0x317F836DF5CF28C2ULL, 0xBA5172B996908DAAULL, 0xDBF31CB80EACEE39ULL, 0xA4D7E5D66B8AFFDFULL
        },
        {
            0x7A4573A829CA28E2ULL, 0xA7C56FC32F5E424DULL, 0x96511B2BCCDFF8E3ULL, 0xB47570C972E94608ULL, 
            0xB4D52DACE5D07E99ULL, 0x2CA26953F92854C4ULL, 0x5A45ED92B8F4E369ULL, 0x2BA852953D14B326ULL, 
            0x065613FEC237DA2AULL, 0xECE26B4CDA8359AFULL, 0x068D242089338AD7ULL, 0xDFBFE9673D0CABA1ULL, 
            0x17474011C90251B6ULL, 0x155A1487069EE09BULL, 0x57C621662A1D6979ULL, 0x143D3F922ECE7CD3ULL, 
            0x0D1EF65B747692E8ULL, 0x78E1C85357D14165ULL, 0xD856D60710E86A3FULL, 0x8C0B4631FB69910EULL, 
            0xF1AE9949CE6AEB36ULL, 0x5EEDC43F2A8999E4ULL, 0x0F8F643F95CBA29DULL, 0xF35517ED7A8A4B9FULL, 
            0x69F2FDE8630E17DDULL, 0xA043A10F63075895ULL, 0x5E30542042A0A8ACULL, 0xB9B5F60D0D1F9100ULL, 
            0x3B52D6B19C0FDB18ULL, 0x7835DB9EA73966D9ULL, 0xDD0E4A8039F55A3BULL, 0x10DF4B79DA957F72ULL
        },
        {
            0xF13880A30948DD68ULL, 0xBFEF996C200F431CULL, 0x55374B74972710A0ULL, 0x2FE423BC51816BEDULL, 
            0xA9CAB3CB2205BE45ULL, 0xECA8784855ECF789ULL, 0x23DF55311816167BULL, 0xFDCFEFEADC609F0BULL, 
            0xEA52A259F11F50F3ULL, 0x1AAC2723CFFAA5FAULL, 0xD582D21F7F05C1ACULL, 0x385CA97D12FA9382ULL, 
            0x1E3CBC815822F1A6ULL, 0x7F85337A5952362DULL, 0x0EED0D630BD6BD45ULL, 0x93570259B9AD7916ULL, 
            0x9D4DE51827EE022AULL, 0x0D1F2F224837B2D9ULL, 0x84F3307D2985F023ULL, 0x61561B2D15141FEFULL, 
            0x8FB0EA9DCB8297BCULL, 0x7BB9D0EBFD124B1AULL, 0x69D25B9430D17440ULL, 0x8650B689E2619D69ULL, 
            0x65C687896C2E1888ULL, 0xAD2333352FD51424ULL, 0xDF8B2C59869F30D4ULL, 0xE8345ECC7B45C5EBULL, 
            0x0E9AD858B78835D6ULL, 0xC044D6EDED99F08FULL, 0x8679D34B4B8ABD00ULL, 0x549854AD8A884572ULL
        },
        {
            0x2551882BA460984AULL, 0x97130CAE56D26E76ULL, 0xE684737CC0AB8F43ULL, 0x36665E47908761AAULL, 
            0x070F504617A27AD3ULL, 0xCEAA190F45FF6CE7ULL, 0xE8A970C3CA9B43B6ULL, 0x03D080929AAFF7AEULL, 
            0xEEBBBE11E29C6891ULL, 0x0F0B70E97A8E32F7ULL, 0x458EE2C670FBA95CULL, 0x54184534BABE8579ULL, 
            0x9842557C88C96D85ULL, 0x3714C356048376BDULL, 0xFCE03E230F88D02AULL, 0xAE67AC7163450D62ULL, 
            0x5A31171804E0FBB2ULL, 0xD40D985F6F7D12FAULL, 0x4C0A695C25EE52FFULL, 0x02BD86A882014EFFULL, 
            0xC8466F1854F1999BULL, 0xC00EE6E0C77745B8ULL, 0xB07BCC70B32D13CBULL, 0xC3FA3213B9AAAB26ULL, 
            0x76028A58A68BC00FULL, 0xAD23E04597EE9DB4ULL, 0xB79C36CCEF4E214CULL, 0x47C75C9D07754E0EULL, 
            0xD991B980FB4952C6ULL, 0x09CCC7725D005040ULL, 0xAEF80B001042D019ULL, 0xD4F9F9BE20706062ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeySpawnAConstants = {
    0xA9E436A8F598995BULL,
    0xB6C3F7D799BF794BULL,
    0xFCFCFAA90523A388ULL,
    0xA9E436A8F598995BULL,
    0xB6C3F7D799BF794BULL,
    0xFCFCFAA90523A388ULL,
    0xFC4A98D0712D7656ULL,
    0xC0CC825E1D59E1D2ULL,
    0x58,
    0x7E,
    0x8C,
    0xF3,
    0x1F,
    0x2A,
    0xC3,
    0x39
};

const TwistDomainSaltSet TwistExpander_Ankaa::kKeySpawnBSalts = {
    {
        {
            0x477E2E1458E46EB2ULL, 0x402696BBA38E1635ULL, 0x999184809161365DULL, 0x5B903893C98DEE50ULL, 
            0xE3206ECE25648CF5ULL, 0x0A13B7D97448D960ULL, 0xB9F393FD8BFA258AULL, 0xEA2396FE0161CD0DULL, 
            0x7C207ECFD3CFEE10ULL, 0x229EAB89B3AD7F92ULL, 0x421AD57396D21480ULL, 0xEA75ECDEC2765B64ULL, 
            0x432914216EA8FF62ULL, 0x8CCD158BBCC758DBULL, 0x205996BB298775D8ULL, 0x84CC34EE381000C9ULL, 
            0x1A521F2A591160F3ULL, 0x137BA5F5D3E6766FULL, 0xF6FD6F8653346942ULL, 0xBE5C17856703ECA8ULL, 
            0x2886D0EC7B9293B9ULL, 0x430469B929B3B53AULL, 0x43A851ABE5FEFDC9ULL, 0x2E0B3FE2B0053788ULL, 
            0x7B45871F1F7114D5ULL, 0x49554DBDE883081AULL, 0xCA36E8B39DB20B65ULL, 0xBDA8A4E4772572C6ULL, 
            0xBBBBF3F0B517BAFBULL, 0x572A96E2CF0A43D4ULL, 0x5B9903A8E5958740ULL, 0x74F0D4D5A962625BULL
        },
        {
            0xF4C22F89FBDCCA56ULL, 0x407B793AF32EEF7FULL, 0x0A4181BA49DF26E6ULL, 0x76FC1EA3DEE5006DULL, 
            0xD84C0ED72CD4EA52ULL, 0x1BA305F07095A782ULL, 0x5A36548B3D013FF0ULL, 0x55F849541EAC39C1ULL, 
            0x7C9880E50CCB497BULL, 0x7784882BAB4978B2ULL, 0xDB38241F0A44159CULL, 0x36DD1AC19909F96FULL, 
            0x5D8F4788B08E57B6ULL, 0x54A3566F1AE09460ULL, 0x1F56BD1649E32CB8ULL, 0xE6B9DC81CA151101ULL, 
            0x4B331B4EC119DEE7ULL, 0x19491232DF374F59ULL, 0x9F86633666BD2147ULL, 0x9ED6798F1E327949ULL, 
            0x335ADA946EA0ED03ULL, 0x2802CC2D47949408ULL, 0xF83722783CB7A409ULL, 0x214B160F800304BCULL, 
            0x350CDA4D3E9F0CDDULL, 0x5571FE8F51C25D90ULL, 0x4B620AF7A8805C0CULL, 0x62392B360B2C0EB6ULL, 
            0x07E0EC3E26BB264AULL, 0xB63D83CB83DF0ADAULL, 0x4CCFE6DD7FA2992EULL, 0xE8E843E219B40575ULL
        },
        {
            0xA9B725D04443EAEBULL, 0x38D3C1C4943D782DULL, 0x7EA9473718828E33ULL, 0x523A712EF3092BA5ULL, 
            0x4C67CEDEF2D4F058ULL, 0x2E724ECE7077A241ULL, 0xE8EC953D87849AD6ULL, 0x296B813FEA45D00BULL, 
            0xB6AB535D5C478225ULL, 0x32AA325FF967688DULL, 0x90A8B0746570C3BAULL, 0x93678BAA884ADA73ULL, 
            0x53C4ED6A94F9C66FULL, 0xB197AD509143A6B2ULL, 0xCAAB58906C647DB7ULL, 0xA2C4E9471C0E40C2ULL, 
            0x3801D950F3A0E455ULL, 0xCC9BDC80EF1329B5ULL, 0x80D15144571A30ADULL, 0x7EB3A4026361385EULL, 
            0x61B68202EEEFBCECULL, 0xB04DAD99A14E42F9ULL, 0xDDA3C36E99E8A9CDULL, 0x79049017B704E942ULL, 
            0x1DC5E148DE96C50EULL, 0x1CA4E0FDCA7F180AULL, 0x1CFE62752E3B73BCULL, 0x236FFB22CF5D5880ULL, 
            0x1707A190EC740610ULL, 0x74BFB3F21E504AAFULL, 0x99366AC3BF49B415ULL, 0x3A79EB199404C4A2ULL
        },
        {
            0x7FED7CCAAAD62B84ULL, 0x08A41CE0DA57A7DDULL, 0xDEF79FFB3423D6F8ULL, 0xA2A388ECE3D35401ULL, 
            0x468B19BC2E5A8C4FULL, 0xD0BBE3526AD1F175ULL, 0x5752D6E0329058C4ULL, 0xFA99F8E03045D88AULL, 
            0xFB0B56A5E9DC6692ULL, 0xD321F4FF0C8B8889ULL, 0x522B9AFE129881B3ULL, 0x1592F90EDC954190ULL, 
            0x8B9A746D5C31796EULL, 0xA035A982CC4B875DULL, 0x7FB38C55404173A2ULL, 0xC896BBB24A338A60ULL, 
            0x35C619E562FB7F07ULL, 0x08884639F7A5A72FULL, 0x5472987958EBDF88ULL, 0x7C77E561965970B9ULL, 
            0xA31507E903FB6568ULL, 0xD1A80B56ADB2D66EULL, 0x5C24E5DA656971C0ULL, 0xD0234D18BC2AECA3ULL, 
            0x943C2B01FED7F445ULL, 0x7F28A9A8B0F81040ULL, 0x0D16DC48B636B049ULL, 0x6883157640C2C1D8ULL, 
            0x0C5388A0152D2A3BULL, 0x9976CB747210756BULL, 0x2E7995E851195622ULL, 0xDAD77CE69DC968AFULL
        },
        {
            0x79CC9DE1F7C401D2ULL, 0x836DCE986D9F5362ULL, 0xEF14F5AE2F6E6CF7ULL, 0xEFC6EDB5189F4B5FULL, 
            0x1DFA41487AA52A51ULL, 0xDAF6E9BA4B2F9F32ULL, 0x00DB3797A451B2B1ULL, 0x6E37EBDD967F85E0ULL, 
            0xE512AF236D6E81BFULL, 0x69960ACC121F4C3BULL, 0xBE1AB579E1BD7C9BULL, 0x612546B0A71A546BULL, 
            0x939FB32E572985BDULL, 0xE89F43B926BB8D33ULL, 0xD523E6287AA09553ULL, 0x3C4AFB9CA4CBCC0CULL, 
            0xEFD57ADE31501496ULL, 0xDD86FC7C42434A3DULL, 0x674877D7650462E5ULL, 0x5FB8904A7B4C442BULL, 
            0x6B60C5ADA1FDEB84ULL, 0xA913F0C0D0A08831ULL, 0xFE39585E0FA53D7EULL, 0xE155032DBEC019A6ULL, 
            0x3041D1E8BBC30B2EULL, 0x800691C64B1B7B0BULL, 0xBB977D577A92B6F1ULL, 0xE7992E3F5D58B4BCULL, 
            0x21587CA6B06106F8ULL, 0x01BDAE7700068C2BULL, 0x99A98B9BB5397480ULL, 0xB7E7AB21ED02EDA9ULL
        },
        {
            0xE721C5B3DCE2FE21ULL, 0x22050A2FEC995F62ULL, 0xFDEAF5A2D44C764CULL, 0xC706141AAA790B1DULL, 
            0x4B92CF37142B3C3EULL, 0xAEFBC9A3B94A9CCAULL, 0x59B2EFDF17EFA031ULL, 0x38ED653A73646465ULL, 
            0x24A5267A43203AC6ULL, 0x639B73C558CD4CC6ULL, 0x7FF1EB0B1009B9ECULL, 0xE040EC80FC46C46AULL, 
            0xC320AC18ACCFF321ULL, 0x9AEBF3A0391D3547ULL, 0xAE142C74A2749B5CULL, 0x3F15FA57E3EEDF17ULL, 
            0x1C9D3E542E26CF31ULL, 0xFFF4E19BE5413DAAULL, 0xE707DDEC257D463AULL, 0x2B60703A1FB231F9ULL, 
            0x2BC02648509258B2ULL, 0x8AC2A30F90F68D05ULL, 0x449214194BD8E00AULL, 0xCA35F44F7297B399ULL, 
            0xB6E451C2BC52A0D1ULL, 0xB37FB7DD42E76181ULL, 0xC426815EE008E733ULL, 0x10B399A38323F3C1ULL, 
            0xFADCEE6D2DFAF317ULL, 0x58E675041B5F4644ULL, 0x1AF4F34F7F943985ULL, 0x353677D8B5B1F8B0ULL
        }
    },
    {
        {
            0x3C442CFE3ACA2321ULL, 0x46AEB0AEBC02D4ABULL, 0x32491D40EDD31B3AULL, 0xFE236F4649BCDE0EULL, 
            0xAC34B9B65B652F3CULL, 0x656F50ECB338A3FAULL, 0x0828CB5D3A84D0EFULL, 0x99CEBE96DCF00839ULL, 
            0xCF83BC7232AB0336ULL, 0x0A3B5F014240EE69ULL, 0x95FCB28636815644ULL, 0xD56767159996C0EFULL, 
            0x15A8E98C24CEB0BFULL, 0xCB65566E59D75489ULL, 0x08AD0AD05B6C3AECULL, 0xF1716A88D1DB9CF3ULL, 
            0x8B42EC76D9AA2AC0ULL, 0x48EDD929DDECE5DBULL, 0x85C07672375B67CAULL, 0x0AEAFE8BC6E1588FULL, 
            0xC1657AEA2FB3C673ULL, 0xDB031B9FDA498F7EULL, 0x865A37F7696942D4ULL, 0x1EF0CA1106FDDFC7ULL, 
            0xF1DBF2A81DF6EEABULL, 0x75AE54B70CB82177ULL, 0x5072C6F86BCD64C1ULL, 0x4FD896EED250DC62ULL, 
            0x3C8224E1DF8CA0E8ULL, 0x2B784F7C6741ECB1ULL, 0x54BA9252154367DCULL, 0x2F62AE5114426C60ULL
        },
        {
            0xEDAF8038B6A8FAE4ULL, 0x3562BA29998C4E47ULL, 0xDCDB9A665F031746ULL, 0x32A53FA67706791AULL, 
            0xBE4E2053729F20D0ULL, 0x8641FEF3472A55CCULL, 0x01CBA0028C02EB0EULL, 0xEC8E4CB2E39EFB50ULL, 
            0xAFA0719E355D4985ULL, 0xFA98D5F1E672FE70ULL, 0x0E3C136D059C3524ULL, 0xA72BB1932CC3A696ULL, 
            0x4EBCACFAC6ABAADBULL, 0xA02279B88070111CULL, 0xE49DB8CD60C6F609ULL, 0xED17391408B66F14ULL, 
            0x5AF74D59482FA88FULL, 0x115652204D3572D0ULL, 0xF3F1CF323214237EULL, 0xCB5C47C09D138D35ULL, 
            0x76B3862776E50279ULL, 0x866787479ADD1846ULL, 0x66AD3A673F85EC73ULL, 0xCEA517626C08E808ULL, 
            0x3D9C9789BE33FEB3ULL, 0x8371B582A554BED9ULL, 0xC4FBAEDF68A0176FULL, 0x61EE69E2B7621C2CULL, 
            0x71572080A6BF6169ULL, 0xC251A73ED237A266ULL, 0x8CBAFDF91FDAF989ULL, 0x14A726131DB75A12ULL
        },
        {
            0x769CCAB58E1FC3A7ULL, 0x233E78D2AF95B13AULL, 0x94A619DC55702D82ULL, 0xC14EFE12D33E6AD2ULL, 
            0xE33B33742CAA8043ULL, 0x42DADF1181AF870BULL, 0xA4631AC8A6452755ULL, 0xBB886F785F249894ULL, 
            0x3C172416D2C91316ULL, 0x528DDC8E73121342ULL, 0x422FDF6C941224D9ULL, 0x83050F3F082C81FCULL, 
            0xED8DC6E804AF5B3EULL, 0xFBE0D5F4338A05E0ULL, 0x5D46DBB53CF157B4ULL, 0xC5E6BD0713984FCCULL, 
            0xE8356CBF4708AA3AULL, 0x4923C686B2B0363AULL, 0xD6ACC80180B95A4DULL, 0xDF81F30F4F72CCC5ULL, 
            0x1E1879170E236C1EULL, 0x6979B94F0E5453B3ULL, 0x3F8A5DE3F4F42E78ULL, 0x2A47DD8C818B9671ULL, 
            0x666DC330C582A1EAULL, 0x7EA93CDE21939ACEULL, 0x0FC93C9AC1A8C24FULL, 0x653EE012553A2004ULL, 
            0x61B61B6AFEE503E3ULL, 0xCCA663FB44E21D12ULL, 0x247ABBCB349221E1ULL, 0x3D4BF73E4F54AA7EULL
        },
        {
            0x311B08A6C693A292ULL, 0x0240E779006BB234ULL, 0x9A6E2C2496D60AD3ULL, 0xE82A4BD85585590FULL, 
            0x2DEC87B5BB2B6230ULL, 0xC5BF2ADB9B368230ULL, 0xA12CF2095D0D845FULL, 0x80077B8E70E3B2EBULL, 
            0xE4C4EF7C255DD521ULL, 0xA73E0F9C7580D426ULL, 0x52F61FBDC4D9BC86ULL, 0x357CC943BD528965ULL, 
            0x19E45395F1E74F1BULL, 0xF5C5375A4333423BULL, 0xC8D005AC1E4A8D58ULL, 0x4F71FF8361782311ULL, 
            0x1BDAA1519E6D4E37ULL, 0x1E3FD44FC7474FD0ULL, 0xB3FD5B2005F3A3ADULL, 0xB8B9475F688D0748ULL, 
            0xF487AE001748644DULL, 0xBE812D58F82EE3F3ULL, 0x557241EB4490054EULL, 0x542ED3321A884FCAULL, 
            0xCFF3D6BCD289469AULL, 0x9233A376BF1865C9ULL, 0x1F3790B6C6BE8AC3ULL, 0x5860C22674143FB0ULL, 
            0x54CE1AC8E9B2E73EULL, 0xAE1AE8D239EBD45AULL, 0xE5831C0B28B2D6EEULL, 0xC7579D1FA70BCA55ULL
        },
        {
            0x1DB83170E6ED747FULL, 0xA031E26B3BA4D099ULL, 0xCDADB26B43CEC925ULL, 0xE0DA9D03E2E21A58ULL, 
            0xE6103DCE60289499ULL, 0x7C0E653F2BBE084BULL, 0xF52D0F13FED98E28ULL, 0x061BA2AEDEB5FF79ULL, 
            0x8FCD5746DBD27B3EULL, 0x0720A1061FC93D5DULL, 0x320704E610C0D48BULL, 0xA1075C570A310B0AULL, 
            0xF7C260D827AD1E4BULL, 0x0D7928FA015274F3ULL, 0xDC18BD11EADC264AULL, 0x25B36D13720F94DAULL, 
            0x7B335D6C85660B45ULL, 0x53A3EAECD85A437DULL, 0x83810EEDAC2B4408ULL, 0x264535F83B0DC9F1ULL, 
            0x26DEDC3A92F8E484ULL, 0x9F79EE45DB707FBEULL, 0x3BEFF339EB0B0834ULL, 0xC8F8FBA2CA7605EAULL, 
            0xE9E9D2E27EC434A1ULL, 0x520D1BBA75F59520ULL, 0x35C2432A4E040C91ULL, 0xB790C22E8E73F6F7ULL, 
            0xC87F718452403433ULL, 0xAE90258F042FA351ULL, 0x48A32D2103ED8604ULL, 0x1ED64DBFA06934F7ULL
        },
        {
            0x9D8427FF69D1E6AFULL, 0x427EADF12A4A4F94ULL, 0x1170C0417827589FULL, 0xCEC342186EBACCC8ULL, 
            0x84475A741D6D3FE3ULL, 0x299E15DBEA673B39ULL, 0xE98C0495FDE979FDULL, 0xB03801715E7C6415ULL, 
            0xF3332174A505D6FFULL, 0x55F795664BE6E339ULL, 0x1D28FFE6A100D771ULL, 0x0011D2780728254EULL, 
            0x0299E8AF7E60FC57ULL, 0x566110D88A854EBDULL, 0x0A026DF8985C7973ULL, 0x3716A4BBE6BFFC6EULL, 
            0xB0E7532435AA582EULL, 0x44BB6788D4DBC3EEULL, 0x88BB84D24E60C61AULL, 0xD1101BEB03ABB7BAULL, 
            0x2DC03445C288BA2BULL, 0x98160421A016CAB2ULL, 0x7EAB802EC4892516ULL, 0x570C656172E210E5ULL, 
            0x93082CB4284A7CF4ULL, 0xE1F8485617050EBBULL, 0xCB992513FC2F651CULL, 0x2CA56AF1D7ECF196ULL, 
            0xB187CE805E846997ULL, 0xAAD35C334F385562ULL, 0x2E1816CE3B059773ULL, 0x70645CBD3177685EULL
        }
    },
    {
        {
            0x7D2A078A9933588FULL, 0x2BF8D2A70E3D1703ULL, 0x59B82ED7B85BC480ULL, 0x23163A3B227EF8E5ULL, 
            0xA79E68D76674A970ULL, 0xCEA4B8DA26859923ULL, 0x8DCE7009EEB6AA50ULL, 0xC994D4466B3B9890ULL, 
            0x579481B36E460FDDULL, 0x99B01AD5E7F12BABULL, 0x4A06DD3520506756ULL, 0x03B8F1729C3BA683ULL, 
            0x98BE18874229EBC0ULL, 0x35C07858E8C93713ULL, 0x8899529355CCBF4BULL, 0xCC7AE67FFFAE13CDULL, 
            0x8300A108F574BB0DULL, 0x1002B108CF8A29D3ULL, 0x7F3AECC629B68817ULL, 0x7D29840B0AC54D02ULL, 
            0xDBDDC523C94E326BULL, 0xD8E8CF83C6176C5CULL, 0x0543AB181371F277ULL, 0xDD27EAEA38BA6971ULL, 
            0x499DFF120715D157ULL, 0xC649617BD727E3BFULL, 0x079E678F19A1E02FULL, 0x0271623C3419856CULL, 
            0x4666A97F6B7D669FULL, 0x0C2060733EB00708ULL, 0x8EDE8C2D41C0FC89ULL, 0x11891ECE95CD7A57ULL
        },
        {
            0x9D7446F6FD005CB0ULL, 0x2A2621263F7D5ADCULL, 0xBB9459155FE40BA5ULL, 0xDC83BD73243E997CULL, 
            0xDEF79E0C593CB278ULL, 0x3B185F292A1301D4ULL, 0x62DB50D340A8EB5DULL, 0xFB40AE20B8CE3DB9ULL, 
            0x5B26DE1781B63220ULL, 0x395940A9BD5BD765ULL, 0x6F797D0DD8422FE7ULL, 0x56B7B7A8F686FA1AULL, 
            0xF94CEBCC120C304BULL, 0x64523878CB861E35ULL, 0x429F363547F84BFCULL, 0xF8B80A3F81A04594ULL, 
            0x5BFBDE5EE8F18D18ULL, 0xC628F4F9DB50802AULL, 0x68E0D80DBAC1755DULL, 0x6B2BDD2355315F44ULL, 
            0xB082121D85242C12ULL, 0xD645D65EF9EB6406ULL, 0xC0790246CFCCA9B6ULL, 0x2BCA65A2DBECFD2EULL, 
            0x50F9D20F9C2B4E02ULL, 0x823FCC714DFB588AULL, 0x71E91EFE6F328E7DULL, 0x45FAD55138818D7DULL, 
            0x50077BA7D2650EB7ULL, 0xA8558C3D97D91B2FULL, 0x7B161C993210D64FULL, 0x5B11DB2F6FBE0C98ULL
        },
        {
            0xB504E82B5803F6DFULL, 0x3EB1232A64E76D3BULL, 0x96452BF6F98728B2ULL, 0x713E3FC8374E9107ULL, 
            0xA268A5C90928F4CEULL, 0xDFE7B5726A64ED92ULL, 0xA1EE3B2D6A7D1843ULL, 0xBE32F82F1E408E35ULL, 
            0x579363F52EB365F7ULL, 0x6E4A035E69C0AEEAULL, 0xA28B18975C23AB12ULL, 0xF20CD919317CCE88ULL, 
            0x9CAA71384116E3CCULL, 0x6D69EE06A88C0517ULL, 0x2B20386DAD24017DULL, 0xFF0548D77BB22859ULL, 
            0xEF4925FDAEE1CE0EULL, 0xD4E7946840184E3FULL, 0x1407E33770A39656ULL, 0x5E78223D69A184D0ULL, 
            0x85661CAE8640752EULL, 0x655408E04D809F86ULL, 0x1B34F85C937DD432ULL, 0x2A6B31453FA8A5ADULL, 
            0xB6B9F23A36698835ULL, 0x3C870CBF630374F6ULL, 0xF83A57EFB14A9CEEULL, 0xFC1B5FC829998565ULL, 
            0x00511AC821D0B20CULL, 0x213698CB7A695A69ULL, 0xDA73BBFE008D269CULL, 0xE344492E34A25FD5ULL
        },
        {
            0x6A114FC6D64D316FULL, 0x10471A1FBE6BA977ULL, 0x8790F4A85CF37D5DULL, 0xD46ECA7A06F020F2ULL, 
            0xCD61A374C16309E6ULL, 0x6F8A97D954A1A014ULL, 0xD03A870D69618437ULL, 0xD4622200986C31EAULL, 
            0xF871DE0B5DB53911ULL, 0xD57D6D007DCA8DE8ULL, 0x12E2DD82EEC8CD83ULL, 0x4F9BD2774D1A7DAAULL, 
            0xB6485BCC6006292FULL, 0x31CD4781518672DBULL, 0xDBFBB995B2C048EAULL, 0x2F7C9451050F81BDULL, 
            0x3FD3A2AB8E6DFE51ULL, 0x93407B8D53B04A6AULL, 0x5F409B398934F1E7ULL, 0x006E214456CF6440ULL, 
            0xD76195D46B76218BULL, 0x1540AC1778A6EC25ULL, 0x5C6048931AE66835ULL, 0x2A9926613563230AULL, 
            0x54675E15F6C570B9ULL, 0x993706BD590B5040ULL, 0xE7FBB9A8670F1A87ULL, 0x605124E04C961F82ULL, 
            0x6D5ED5C22117E41CULL, 0xEF313480343FA6D3ULL, 0x160F373099E06C3CULL, 0x9213B5474097BB34ULL
        },
        {
            0x9B4E9AFFEF467E0EULL, 0x46C3FAC51B2825F3ULL, 0xC5DC9509F32294DBULL, 0x14EE406E3DA92E94ULL, 
            0x126233A93F26B511ULL, 0x6B7D2361D890DDC5ULL, 0x0AE2AE767EF88698ULL, 0x334B962A906DF012ULL, 
            0x006A0157B1128D24ULL, 0x54356620EA7A1EDCULL, 0xD8DD0188B47504B8ULL, 0x1E89C4807D60C03BULL, 
            0x36C48929D59451E2ULL, 0x7A95E14BAA7A44ADULL, 0x15DBA9C604585B3DULL, 0x66E0C2CEA949CD85ULL, 
            0xE44612B2AAA287B6ULL, 0xDF4346631C981E5AULL, 0xA3E4224BAAB21335ULL, 0x6835B430A4EBA6E0ULL, 
            0x268AFD5AAA23D21BULL, 0xD6776F4377C2AC79ULL, 0x03DD7EAF59104B11ULL, 0x502A1AE40600743CULL, 
            0x81B945809DB18A8AULL, 0x8552C963A42B812EULL, 0x7CEBF6D29CB50EDBULL, 0x2E1072BBE5D4F303ULL, 
            0x0194B9DC616F909DULL, 0xB724AD86D83F40B6ULL, 0xECF6870CB0414BDEULL, 0x88907D5761FBB7ABULL
        },
        {
            0x1BFDD282D7FA6C98ULL, 0x495E634EB6C4D44CULL, 0xECDDD6DCF291D5BBULL, 0x414C22663AD674FDULL, 
            0xA282D9FADDCE11E3ULL, 0x9B1064942B8D233DULL, 0xECA79A0E1F13B911ULL, 0x63CFFB9A23C1598FULL, 
            0xF63FE1374523BBD3ULL, 0x6B54FA2F74BB9774ULL, 0xF879C2E506BAFA65ULL, 0x59D2353E159CC4C4ULL, 
            0x257D015A70715DBFULL, 0xEC3046A383E45357ULL, 0x197C99D1E51A7289ULL, 0xC48E26E00B9F0719ULL, 
            0x9F6600548387D0E3ULL, 0x37FD294186D3BDD2ULL, 0xB3FEB287D0C7C648ULL, 0x74F695236443B575ULL, 
            0x1B4E0C7017A97D8CULL, 0xC61D7EA02E8ABECCULL, 0xEE7313275721EAF2ULL, 0x611412CF399A4EBBULL, 
            0xC862B96B5EC858FBULL, 0x31E433D03929E67EULL, 0xF467ECF40ED1DF5AULL, 0x6D1BA80867512C5CULL, 
            0x08E3D414F67DDE2BULL, 0xA4F7ABCA60C1FF59ULL, 0x282227AFE7C0227FULL, 0xCF00463C6B599FACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeySpawnBConstants = {
    0x447E410EBDB9719FULL,
    0x157E5DAA6ECCC093ULL,
    0x7FB44A5FD99FE6EDULL,
    0x447E410EBDB9719FULL,
    0x157E5DAA6ECCC093ULL,
    0x7FB44A5FD99FE6EDULL,
    0xEF9AA435DF5A883AULL,
    0x69FCFF2227CDD903ULL,
    0x89,
    0x16,
    0xC8,
    0x13,
    0x74,
    0x54,
    0xF7,
    0x2D
};

const TwistDomainSaltSet TwistExpander_Ankaa::kSeedSalts = {
    {
        {
            0x472BB5F91469BC0DULL, 0xD6EE9FCB296ED081ULL, 0x193D7AA21E57B01DULL, 0x24EED7AC0DD38F05ULL, 
            0xCADD72A1CCBB6B34ULL, 0xEB56588C1E34E72CULL, 0x0500D3D40397FD0BULL, 0x157E0A33B9B4A51CULL, 
            0x4EABB7C26A9F8B50ULL, 0x90C818C6F8E7A4CDULL, 0xD5E42478646B54A1ULL, 0x3DE366CCB42F1B86ULL, 
            0x538C86F52BC068C6ULL, 0x4058D527ECE50E45ULL, 0x83CDD41B00720B56ULL, 0xDB6B664EDBB2D608ULL, 
            0x9384902C24CD9476ULL, 0x56E1CBA02E4260C0ULL, 0x7C2D8BA5EF10627EULL, 0x2341A9C14A1340E3ULL, 
            0xDC9051BA56CDB1F9ULL, 0xDA2CDD71DD3C716EULL, 0x5966DCA133CD0D29ULL, 0x3915BDC2E9BF98C3ULL, 
            0xA0D699392EAF2732ULL, 0x97E3154A856378EBULL, 0xFE4346AE77047EADULL, 0xA7026CDEDEF927FBULL, 
            0x39D87AE04CB93C8AULL, 0xDC8925869BA76E54ULL, 0xD353F253D73C59D8ULL, 0xEFA3BA6396AB490CULL
        },
        {
            0xD437ED4ADAFB91B9ULL, 0x6913941B3C824E41ULL, 0x1E3E1A8BEE53CDEEULL, 0xF7A89C09E513A39BULL, 
            0x552A28730570A52CULL, 0xBE842EE25BABFBF2ULL, 0x5CEF28FE4804A199ULL, 0x05A1D9423BE35019ULL, 
            0xE3BA09A868DA27DAULL, 0x9FCC5EB572AC9EBEULL, 0xFB5880D846DB0D18ULL, 0x7DB731494A84E27BULL, 
            0x521EF9456B078B97ULL, 0x54A7A7801DE9EEEEULL, 0xBAABECB3B8AC82EAULL, 0x869EE3B0FD5A06F7ULL, 
            0x14A32F1312A06E53ULL, 0x575D0CA41CF94D04ULL, 0xF6822B4DE930502FULL, 0x2FDDBF6B1FCBA1F6ULL, 
            0x96722A54AF99244AULL, 0x93E66267F52B5994ULL, 0x8BB97531A607B41AULL, 0xACACFC99B2C151ABULL, 
            0x70EE98E3C89A7BDAULL, 0x773E7638AE2ECE5EULL, 0xD66247E679650A87ULL, 0x85A209AEA2951807ULL, 
            0xEB689DBFBBBDBA7CULL, 0xF5BC6E414875C7ABULL, 0xFF67CE2F62099855ULL, 0x3450220F69DED15FULL
        },
        {
            0x591A8D97A803A8F7ULL, 0xD5611D5A84A76434ULL, 0x4663FD47CF05BA59ULL, 0x25838117E45F7E24ULL, 
            0xECE232C62577D742ULL, 0x437BC9599DB4A0DDULL, 0x5CFF44BD9A799D9EULL, 0x7F5AD369F62CEF50ULL, 
            0x8B62F93370F41597ULL, 0x421D0F4C59F1CDC7ULL, 0x8EDC80C46ECDB654ULL, 0xE0FDDB8858A2ECD2ULL, 
            0x547389FFAA9CC16DULL, 0xDF160083C59C8F16ULL, 0x50E6C003F0AFDE5DULL, 0xD6F8BB7155E92F61ULL, 
            0xB0F0083FCFC6E96DULL, 0xB7B1D18FA44741C2ULL, 0x15D7ADCDA8D8CB55ULL, 0x84F51423AFD42520ULL, 
            0x86708C9F9AD8A720ULL, 0xC2B649D59BFC8D35ULL, 0xE61FD785EAF26F34ULL, 0xD7C815FF19F7289DULL, 
            0xC513DFDA00D06D07ULL, 0x40999F4E7566A698ULL, 0x5B1C91718267750BULL, 0x6D127861FD85ECE4ULL, 
            0x5B1A97C43E122048ULL, 0x206565DD708207EDULL, 0x25A48CAA93012791ULL, 0x3EE96ED2716E0020ULL
        },
        {
            0x691A6090BD54F7A5ULL, 0x0D0B757FD1EC8D1AULL, 0xFE5A1E4BE5B78DD2ULL, 0x2E7AEEFF5AAD1B51ULL, 
            0x36D21DA151B45311ULL, 0xE772B9BBB7CDE4ABULL, 0x838FA99EE9709F5FULL, 0x9AA5EFB68154D895ULL, 
            0x8CA4B131F0ED5F26ULL, 0xFFC8FEA681B91F38ULL, 0x644F59B1A74BF8CDULL, 0x9EE0EF66A50043C6ULL, 
            0xDF1808747CDC6A05ULL, 0x66CCBC5C6127E0FCULL, 0xFA8E70CDF27C580EULL, 0xA3E348A1A4177B0FULL, 
            0x9B938DE20AB51B73ULL, 0x7E189F1F967C97C9ULL, 0x11B3F70BB4B1ECF6ULL, 0xBDDA7D9C34BD293FULL, 
            0x1156E86135A92AF2ULL, 0xEB8D6EF215687FDDULL, 0x5262089E3AD3D17EULL, 0xC61B5755C8F6C167ULL, 
            0x6F1106ACAF18D2A1ULL, 0x03CFA1A8049D5D89ULL, 0x627E91B226AB2576ULL, 0x85E4D1B82085B27BULL, 
            0x5D9CDE4A4722D7A7ULL, 0x352AFD4E89F9399BULL, 0xCB640BEB038AB8B8ULL, 0x19C6F0C18C0CBB61ULL
        },
        {
            0x9DC241F56C6FBCABULL, 0x9E128EB3CCD8604FULL, 0x8937589DC5D40BC6ULL, 0xC8EA27C6002635CBULL, 
            0x9EC6DC406EB0E82FULL, 0x2FD7A046E5CB9959ULL, 0x9483BED6FED0D760ULL, 0x4215928D93827766ULL, 
            0xE65B046FFEA9AEA2ULL, 0x104D0BAA0D96D42BULL, 0x71F29C124BCF59FAULL, 0xCEC8229091A8F9D0ULL, 
            0xF7252CED5A1B1F2BULL, 0x2F43ECCDAE252E95ULL, 0xC78A716DAB934675ULL, 0x2B885166E24BFCD4ULL, 
            0x916F4CD3EB9F64A6ULL, 0x780571DA39D04DCFULL, 0x77A611BDF100C221ULL, 0x8EDC6183D3E17963ULL, 
            0xD90C0D7FDBCDAC55ULL, 0xEB4B53930A6754B4ULL, 0x02347BED4BCD2EB9ULL, 0xB58AA803C4E219BEULL, 
            0xDC84ADEB64F8623BULL, 0xB34EDBDCA4C4D49BULL, 0x916D0DC7EB9C75CBULL, 0xCE4772C74A1E1A37ULL, 
            0x5B74E19ACDFA9CE1ULL, 0xDF0824294B306C5CULL, 0xFC97EF440B41EF53ULL, 0xE0EDC8942167E3B3ULL
        },
        {
            0x41B2646C5F238EA4ULL, 0x5DADDE0185BC4845ULL, 0x2453FD60EE2F235CULL, 0x612873F06E10BB03ULL, 
            0x61506ED2F148E97AULL, 0xE27D5A255DE27D50ULL, 0xF9FA48DE52E29E03ULL, 0x9E9FB37F1EDDF785ULL, 
            0x2EFF3AA10C539AC2ULL, 0x78EB487AFF94BC6BULL, 0x890FECE382A51051ULL, 0xCE500F846166A97CULL, 
            0x4FA2513C7523F09CULL, 0xE40A26181CD69AD5ULL, 0x71D597B18D9A29EDULL, 0xFB557F165DA12586ULL, 
            0xB3D85D3C64885848ULL, 0xB71D09E88B50164BULL, 0x0AE54A5C1C24E102ULL, 0x2960BDB7AB2DEF86ULL, 
            0xA420C0854FBA8C1AULL, 0xB7FEBFEC31AD4123ULL, 0xC74784884DCAAB77ULL, 0xAD399D0E8C0CA502ULL, 
            0xF2269D6621882A51ULL, 0xB4A07396CF10F2EAULL, 0x125A04045E1EB5D5ULL, 0x57989C10AA2802E5ULL, 
            0xBF106E7A557F8811ULL, 0x56959EA0E19DB078ULL, 0x04163A2FD9A2D372ULL, 0x754D85F0235B2D90ULL
        }
    },
    {
        {
            0x99063891C4CC103CULL, 0x6302C97F34B31C1EULL, 0x30F9D8E56A52F832ULL, 0xA6627918A3B9BD45ULL, 
            0xA64FF7BFDE7302A0ULL, 0x0C4853603928752FULL, 0xC6D271DA20338665ULL, 0x3193E55F4D9380AAULL, 
            0x354CC8ED988FF942ULL, 0x36F31A3F65E4A7D1ULL, 0x13D53EB2121142D2ULL, 0x3C1E1823317FAF5AULL, 
            0x9CB1035F6C777EC5ULL, 0xF02A70C778EAFC3EULL, 0x50019A1537471C3FULL, 0xB2841D1F08112438ULL, 
            0x8A30BD6031AF970CULL, 0x32371D5997BFBBFCULL, 0x584C9232FB383D31ULL, 0xF1841E885E5D46B3ULL, 
            0x90A1822BF24718A0ULL, 0xE1251A1245571AF1ULL, 0xD7323DA8730370C6ULL, 0x56CE34CD0F85DEAAULL, 
            0xDDB05A56DFCB1EF8ULL, 0x100FDD4233CB8361ULL, 0x25BD55E716662FC6ULL, 0xD4B7A5396FD726A3ULL, 
            0xD95156ED7F76663FULL, 0xCFA46478CCBF84F9ULL, 0x4665546BD44F0239ULL, 0x6A89D9B40A580797ULL
        },
        {
            0x4C709A6398AB4F7CULL, 0x5775040D234A63E8ULL, 0xCA69731A96B78A66ULL, 0xEE6DD217E259D65AULL, 
            0xD95947A7C21F2C37ULL, 0x032EEC510444F553ULL, 0x1D11E8424D3EE3E0ULL, 0xBFBD550BC906B095ULL, 
            0x636E35F8C5E252B2ULL, 0x9791D734D460F9ECULL, 0xBC46AA068C6A07D0ULL, 0x1F1D709C084F5DB8ULL, 
            0x2B6673C7893A6865ULL, 0xF225FF22044055F9ULL, 0x276DFC2DA0336D64ULL, 0xC29F7C69312CDCE4ULL, 
            0x7EE198A7FF1E9974ULL, 0x42B48A771989B5CBULL, 0x8D8F5F1A14BEA4B9ULL, 0x71C241B7121AA397ULL, 
            0x014B02A37389EA0EULL, 0x7F9307081874F659ULL, 0x34CB3D8AC0C7A6DDULL, 0xAC3945B9C5A85F0DULL, 
            0x162C8F986E7FC123ULL, 0xD5C9F4E529157BD2ULL, 0x2970D92CAF8713EBULL, 0x7022B325880D0189ULL, 
            0x4FA8115C9CC3AD94ULL, 0x4BBCDEA8072E861DULL, 0x3CE2CF1CECD64F31ULL, 0x24C6862B7A3D7A94ULL
        },
        {
            0x0F0E2A9BBBE8A1A6ULL, 0xAA1A591C0E89F8DAULL, 0x164D7972B5148481ULL, 0x76B8293F9D9918D6ULL, 
            0x3D33ADF625046BAEULL, 0xF1E15EB1AFDE65F5ULL, 0x26980C8E171B27BCULL, 0x9652368713304A76ULL, 
            0x28B6DC9E49B58CEEULL, 0x1E56C6788828777AULL, 0x5F147EBBDD678D02ULL, 0xC53F75CDB8268319ULL, 
            0x2E4A2A2FA806A677ULL, 0xBD81A7E65DB805ADULL, 0x854B80741DE372F8ULL, 0x2511C082607B0336ULL, 
            0x3E28FCD34A8F300CULL, 0x319298B20E50184EULL, 0xDA259CAAB008065FULL, 0xE285F9B067CCB025ULL, 
            0xA635373E33DF8A72ULL, 0x14A57054F802BE9DULL, 0xDAC76DE2ACE8BC83ULL, 0x6F3E668380DF5C9BULL, 
            0x8393CAB89C954D00ULL, 0x1FFC3A15FD53F67DULL, 0x12208EA2BCD877B1ULL, 0xDB46F67A2DD9E37CULL, 
            0x6E5A72696174E041ULL, 0xB5AAD4F57D375310ULL, 0x9EB65ACF68FBBD75ULL, 0x342E849A153246D2ULL
        },
        {
            0xDC106E9BFE85330CULL, 0xED76F23B2B670654ULL, 0xE5EC1B4125D0E0AAULL, 0x16CCAD248E832585ULL, 
            0x080FC097B2A944D4ULL, 0x7976DFD2A2B8273FULL, 0x907EF695BA6CB001ULL, 0x4B163F614C33F2B3ULL, 
            0x463881CFF157DB2DULL, 0xB902FD84DCD29267ULL, 0x2A36C7B6EF96C632ULL, 0x899C82DAF1578370ULL, 
            0xE71649875C6B3642ULL, 0x9EF469786ED19873ULL, 0xC91942F92F0D4B6EULL, 0xE43A0C5E40C85741ULL, 
            0x4CF4A3BB81673619ULL, 0x36F67CB30ED4FEE9ULL, 0x6B6200A2F3ABEA65ULL, 0x3FA16A0D60B43ED8ULL, 
            0x569F979D80A12BF1ULL, 0x3FD107B899CFEC7AULL, 0x2FF578E7A407DC98ULL, 0xAF43CD6E031787C4ULL, 
            0x608319B83321F804ULL, 0xA4C7C952B21CC46AULL, 0x0153A75A1E8E59CEULL, 0x13137EBB8D7896FDULL, 
            0x2C68F7936EEB0701ULL, 0xC0D464251D317ED1ULL, 0x5EEB5C5A4C8BB8C5ULL, 0x8C66B172399EBA8CULL
        },
        {
            0x7FFD8169DEE291E9ULL, 0x4410F25585478E1BULL, 0x8262F266C028B0BAULL, 0x3096056CCE918119ULL, 
            0x952ECF02C26E0309ULL, 0x86E4DBEA30E5B2D0ULL, 0xFA4F7DFB1EB5B475ULL, 0xB33A6FA7C55EEA12ULL, 
            0xF11167226DACF351ULL, 0x29BD3ED105D57EE7ULL, 0xF4412F3108250C3FULL, 0x48A36977FBD56340ULL, 
            0xB300A3E049B7DF7FULL, 0x150653C35960B6A9ULL, 0x0D7FAC377F6E13A1ULL, 0x3F8FF1C1A39E5D88ULL, 
            0x9424A6A983A94E59ULL, 0xC0AC0CA2C8CFBEECULL, 0x2EAA77C95C46986EULL, 0x32CA40BA33BBD224ULL, 
            0xD1C4AAAE4297980EULL, 0xA1FCE490DF7744CAULL, 0x23FA7FA9BFDE9228ULL, 0x5C84A7ECDF815FE8ULL, 
            0xD6726F14738566BDULL, 0xD23D9E6A8CBE2934ULL, 0x924EE2654CD4A293ULL, 0x2041FC56C93DFEEAULL, 
            0x5D2AC75FAD9A1BA1ULL, 0xE65F08B0C62F8163ULL, 0x21C64F031CE42BD9ULL, 0x79442597EC11D772ULL
        },
        {
            0x83B18CEE7EB7F018ULL, 0xEB90654A17E8D2A1ULL, 0x9AFFB1E0F85DBB47ULL, 0xDB7DDB69054C0067ULL, 
            0x9E46DBE640EBF8A0ULL, 0x427F7113EA685F4DULL, 0x1AEF680C6F6FF3F2ULL, 0xA290157781DE165AULL, 
            0xFCDCE7F9F2C4701DULL, 0xA0B39D67CFADAE50ULL, 0x30A357353A3DB2A4ULL, 0x7C30C3FB5A6264ABULL, 
            0x208D2DBA2FB95D14ULL, 0x159E5CA09D72F8B5ULL, 0x828943F471566011ULL, 0xD3C3B30C3B5021B1ULL, 
            0x0843125F98EA22C6ULL, 0xA93AC0FC30DF1EFCULL, 0xB3E84630D86D5CECULL, 0x88C17179D302F2E2ULL, 
            0xC752919199147C95ULL, 0x796833E3772FA27FULL, 0x91EAC42228CCD8F8ULL, 0xD6BBB8F27B1B518AULL, 
            0x8CC81803D0FC42BFULL, 0x223B54AF72A78011ULL, 0xC145C90671A11BCCULL, 0x25972699D443BCF6ULL, 
            0x07CD9481BD789DC1ULL, 0x34DD389230A51623ULL, 0x2EFB976BEC79E4BCULL, 0xD9BE185D6FB51015ULL
        }
    },
    {
        {
            0x829B075FA30E77D1ULL, 0x1831339C9613983AULL, 0x68DB96E4DDD60EFEULL, 0xAC43061A1E0D2EFEULL, 
            0x4CB1D0A6B844D9BCULL, 0x4300E90D41B2FF2AULL, 0xAE149BE91E5CC8DFULL, 0xD6A448188A0644A5ULL, 
            0xBE5B61D604D3F1C8ULL, 0x37EED8C6C488FD58ULL, 0x048E2556C6CA4921ULL, 0x29AAB42957FA9B69ULL, 
            0x5409BBF3CBDD0B8DULL, 0x92B9682E8EA53B19ULL, 0xC85A55E48271EE49ULL, 0x246E9B5FDBA7C46DULL, 
            0x35C20CA99375B946ULL, 0x97FEBCDF1DC733D5ULL, 0x38FCBAF74515445CULL, 0x9EC29AF8C96AF372ULL, 
            0xACD56FF38EA45FC9ULL, 0xD80E018E73C6C297ULL, 0xD3E703EBE8665F46ULL, 0xAF4166712D638167ULL, 
            0xD2350A4D565CA01EULL, 0x5818A8606CC1DAFEULL, 0x349F8BCE5AB914B2ULL, 0x8494F420533A35AAULL, 
            0xF13FDB8F6258DF38ULL, 0x4BF42FFCFD2BFB72ULL, 0xCC7A0ACA89734F2AULL, 0x5BB794A844D48182ULL
        },
        {
            0xD189A39E45EE93C0ULL, 0x5E00CC18A488DDB4ULL, 0x8210DC0CD64152F9ULL, 0x5D1D6A7818604A32ULL, 
            0xC4D65A7731EEF2CEULL, 0xAD407967B40C64F5ULL, 0x7177FC4749B38169ULL, 0xA94FB534102C062FULL, 
            0x2C2B5043788E1B28ULL, 0x97E384000FDB4F44ULL, 0x4129CF7DB6FFDED0ULL, 0x04B5027B480DEE51ULL, 
            0x32557F0CBFB52D27ULL, 0xB79EF06A7D64724CULL, 0x7F4BF46198FA1CE5ULL, 0xC62CA1EE3D4FB701ULL, 
            0x49D60B335AFAA776ULL, 0x6D571A2DEFE9215AULL, 0x4D01BECE3B090ACBULL, 0xC06AB24E66E3608FULL, 
            0x423D13B1FE81FA5BULL, 0x16907350F5DB0240ULL, 0x6225B7C500DA3210ULL, 0x65A4CD4AFF976D60ULL, 
            0xD67AAEA5D7BA8E42ULL, 0xBE8DB364B3CFF29EULL, 0x70630697B30ED6E6ULL, 0x3B935497427E7C31ULL, 
            0x582455EBF3DB4388ULL, 0xEA8A5392FC304C95ULL, 0x6834FB8080E9BD06ULL, 0x8851A39264ED8E54ULL
        },
        {
            0xA91D8D116F35BA2EULL, 0xD1AB9C7385CDF7A3ULL, 0x7BDC8BB661E88950ULL, 0xCCB90419EA1E70F3ULL, 
            0x505CBEEC47D22DE8ULL, 0xA5226494CAE12966ULL, 0xE9394012045320C9ULL, 0x432F6E957672BFF0ULL, 
            0x8A3C256399E23777ULL, 0xC2FB2A70A3F9BA0AULL, 0x8F66FE6437D0ADB1ULL, 0x905125691CE3A1D9ULL, 
            0x85C09FFB8C75C0B3ULL, 0x81A7E2003577E8EBULL, 0x0DA31227391B7ED0ULL, 0x9B734414854F8E3BULL, 
            0x6A9136B3E3E9BC11ULL, 0xC3878476E0C15A7BULL, 0xE3B3F9615F82788DULL, 0x88B8A7F45274B762ULL, 
            0x6D0E7198F51029EEULL, 0x265C7A4175D02478ULL, 0xA9E9C76B25CEFACEULL, 0x6EEC4EDBFAC24D94ULL, 
            0xAC2EB51F1D233BC5ULL, 0x227EFB791D54E075ULL, 0x4E8A8618125F0DE1ULL, 0xB46C81DD21F9C912ULL, 
            0xFEC05540FD86C6E7ULL, 0x0D05BC6E1406C78CULL, 0xCE04F803C0CFB0CAULL, 0x995CE33126B2A062ULL
        },
        {
            0x6B3EA50E15F5503EULL, 0x245EA4D3AD6A72C8ULL, 0x7249222112D9CD90ULL, 0xE87DB85013369CE2ULL, 
            0x9888FB341A552916ULL, 0xE2E9CC705F5B8D3FULL, 0x4BCA97CED0DEAD79ULL, 0x6A0FCB0732327713ULL, 
            0x4E661A81BF70F3C4ULL, 0xDF594DF334AE569FULL, 0x8D6BA01A240AF0DDULL, 0xE99BC1AFC4D7A880ULL, 
            0x6E5873BFD55F4BBFULL, 0xF50C9738C3A11F88ULL, 0xA38D9EB3A0EA1BCCULL, 0xDC3251EBC36E9830ULL, 
            0x7B2D7C570A9BE615ULL, 0xA8146D398E26F3CCULL, 0xC0F6E49ADD888B2EULL, 0x60639E4766DFFFB1ULL, 
            0x834920ED6F95C378ULL, 0x1162FF6EE8BD7346ULL, 0x5E72911243D493E1ULL, 0x065ED54F0CF384E9ULL, 
            0x251057B41DC2756AULL, 0x00006148B4CF1DFBULL, 0x8A67FBA62B84BE65ULL, 0x2B3864F1C4961CAFULL, 
            0x95633E7C1DE371FAULL, 0xA7890B6B3088BA14ULL, 0x1461C363C65280FBULL, 0x781F07A2DD7EE65CULL
        },
        {
            0x1B151A33D67BAFCDULL, 0xADE5FD5DB8F2C5DFULL, 0x0DF89A9BC9C57623ULL, 0xE170ECF805DF8091ULL, 
            0x5EF598C66A91BAC0ULL, 0x27122A7D97953187ULL, 0x005EA40FAA5119C2ULL, 0x7DA0C3DC2CF7D0CBULL, 
            0x4E57C4E9CE00639CULL, 0x4082F7028CE3E16DULL, 0xA9094B0BC2FBA3EDULL, 0x6AB8DE67626E7B18ULL, 
            0x2C953672618EC018ULL, 0x0723A0CA0474B038ULL, 0x8262462835EC217EULL, 0xD0E8C43A1305B844ULL, 
            0xE31F3B5C8D2C8174ULL, 0x3CF58F41D5D91B49ULL, 0xB30655B44369921AULL, 0x7F183D1B9EEB6B6DULL, 
            0xBE702F1024455C52ULL, 0x6FCC0CEA7DB788A8ULL, 0x1A162BED0BA4E560ULL, 0xC4F6FAC728DC90CBULL, 
            0x17852BF0A37586DAULL, 0xAA40A201E9B6831FULL, 0x519884E52F294D33ULL, 0xF8538C02FC2986CBULL, 
            0xBA0A692E88706C15ULL, 0xC8D67F41643A2E04ULL, 0x04BA3F9F20A52EEBULL, 0x7D9CF8F65EEA3B50ULL
        },
        {
            0x9DDCD9F597CA7204ULL, 0x042C23E0BA179F2DULL, 0x50F4D7E2AE7430F0ULL, 0x8D08952A8BA4A342ULL, 
            0x9ABFC83AEA515C18ULL, 0x549F4AF1E0337890ULL, 0x67A60F2CA36E2EAEULL, 0x3E338834912ABE80ULL, 
            0x40807A6970897E1DULL, 0xA6EF83FAD28721F7ULL, 0x6519B9C28C33A615ULL, 0x8F84C7FC93B0ADD6ULL, 
            0x7C61280E51332B12ULL, 0xC1734D4B9FEBD554ULL, 0x1E8EBAE30E9779C4ULL, 0xF9429B08C5507801ULL, 
            0xA72E8EBED71E35EEULL, 0x5E267624E11A58C9ULL, 0xE470E9143B735799ULL, 0x0A3593D4C091692BULL, 
            0x8E823898D54022D8ULL, 0x9C2B2B9669E349A9ULL, 0xA0F798E9D9C41611ULL, 0xCD7920AB6C1E7EF2ULL, 
            0x789E6E5F7E72BE8FULL, 0x0AC9883C292FE975ULL, 0x9FD06DBCE3F21755ULL, 0x539AFA8675C7F94DULL, 
            0x136199DF98D0300FULL, 0x0ACD5723CDE493AFULL, 0xEDDDC86CF5808427ULL, 0x761F17F241DC447EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kSeedConstants = {
    0x829A1F4E47064920ULL,
    0xD78261B3AB952CB1ULL,
    0x415BE4AD2A724A91ULL,
    0x829A1F4E47064920ULL,
    0xD78261B3AB952CB1ULL,
    0x415BE4AD2A724A91ULL,
    0xF2E18941F2CBD57EULL,
    0xC9EA356BEB6C625DULL,
    0x43,
    0x8B,
    0xF5,
    0x92,
    0xA8,
    0x1A,
    0xC0,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Ankaa::kTwistSalts = {
    {
        {
            0x29A96B205FEABA64ULL, 0x67EDC4DF18D1950CULL, 0xB7826C53EB8C0D27ULL, 0x8B4798237E8171E0ULL, 
            0x4B8FC9859A251558ULL, 0x283CCF34EC93F1CBULL, 0x567A89A1654D6ECFULL, 0x5F39E645CA813746ULL, 
            0x5D8C56A6F3BBAD46ULL, 0x08D101DF03C0D778ULL, 0x9A17CF5A657C403BULL, 0x60A4C0084E290CB8ULL, 
            0x004C86888672B8CAULL, 0xB46881ED236A8802ULL, 0xF334150939F934FAULL, 0xAF24DB913E22C329ULL, 
            0x880BE4C7C2463CC4ULL, 0x6AD28A542450916DULL, 0x1A4C7288C98F4882ULL, 0xF3840973FBFA2040ULL, 
            0xEA5158BA56A3F7F3ULL, 0xDEDC7C3CE83CBE1FULL, 0x49AFC326D61E165BULL, 0xB8855FCB412B23DBULL, 
            0x0EA17A682C3BB63CULL, 0x1FB45A4F2287CAD0ULL, 0x1AA269A468345A5FULL, 0xD78D24E5CA05B92DULL, 
            0xAC11E1AB6A0F2A44ULL, 0xE0C11F3071A067E1ULL, 0xBE5868FF91689BD6ULL, 0x1078EA36CF2FBD7FULL
        },
        {
            0x0B0851764DBD3103ULL, 0x4B9DC8D875D1FFF1ULL, 0x8E292BD39853B63DULL, 0x4B1816995E8E981FULL, 
            0xA620EB842C63B96DULL, 0xAA8EC27A24AABCF6ULL, 0x911D2E031D89E963ULL, 0xADDAA69B15D03E67ULL, 
            0x5524ED75B3D4A7D5ULL, 0x8D7DBDE3BDDA60A2ULL, 0x396952B278E8A0E2ULL, 0x3D77AA0D40224AFBULL, 
            0x091A5BE67E111241ULL, 0x4A7EFC0E069EDF31ULL, 0xC73A0052DB0CF704ULL, 0x3F9EC5C780C70079ULL, 
            0x187BF3D1258EE11AULL, 0x597167AFA5550C6AULL, 0x385F1EFD1532445EULL, 0x7CF26F8BEF2C5512ULL, 
            0x1EB071DB0E31D112ULL, 0x29F4661F3F154399ULL, 0xFD5C5F6BDDAE4E05ULL, 0x009121A83BB6FADAULL, 
            0x29B4AC8D77C4A729ULL, 0xF6AA6786E42F3119ULL, 0x63C79CBD979BD990ULL, 0xE632C0D4B7FFDE90ULL, 
            0x09C35E57C63F5435ULL, 0xE052EDED6E05FB98ULL, 0x899ACD913B622031ULL, 0xF7718CC1E0FD51A0ULL
        },
        {
            0x1EB8FE94B9856E1CULL, 0xAF2589561E0D7B5EULL, 0x2609B3DAE385B4BBULL, 0x73DCB4E4D34FC923ULL, 
            0x427BD8A3B143A685ULL, 0x309E0F1FAA384952ULL, 0x3BA3BBA183909478ULL, 0x1CD42FF175638AA9ULL, 
            0x6D204B4D211FD109ULL, 0x3EA59E0871F7CFF6ULL, 0xC3A968DF457BBFB9ULL, 0x3BAD351DA5BFD212ULL, 
            0x7EB4C52EA1857A55ULL, 0xDC84474B9CCD5EBEULL, 0xD95E86901B6CE723ULL, 0xF32858E39F79C63FULL, 
            0x1E096FECEDAD5C44ULL, 0xC3B93492B44C284EULL, 0x6380C22495BEC33EULL, 0x33957B4B53341974ULL, 
            0xCE15881E53362882ULL, 0x5FC8BDBFC056D1C9ULL, 0x4E58E25094559BEDULL, 0x36E6F9FDF21DC0F6ULL, 
            0xA75A2AFC25FFCD78ULL, 0xFEDBFBD4AEBDECB8ULL, 0x971188A17D896C68ULL, 0x42CF5F8F66C3D49DULL, 
            0xE928F2D56C459D83ULL, 0x77C33A53DCE0F83EULL, 0x5AC7C152A385E3D5ULL, 0x421F528D92FAB18AULL
        },
        {
            0x72CCB32990975EC6ULL, 0xA2C3460483FBC50BULL, 0x56E979B90C8DFDEDULL, 0x31D7C30909AAADADULL, 
            0xDC84743F891E1591ULL, 0x9BA125399880EDDEULL, 0xB6DBB366AE20F819ULL, 0x7ECB6A9178D30683ULL, 
            0x123298FA1467B1B4ULL, 0x6B7932FCE0986B9DULL, 0x8649770754F7EE9FULL, 0x8723F31E4240B8A8ULL, 
            0x67195DD7172C8DD5ULL, 0x56A96EDD5678403EULL, 0x6D6849C6C57BD624ULL, 0x1D699D4502193D98ULL, 
            0xECC3BEC7024263C3ULL, 0x8A3ED9798452A319ULL, 0x6AED4A18F58AB926ULL, 0x259741A0A3E772E2ULL, 
            0x9DB368E59274D68AULL, 0x21DAE6B41E14022DULL, 0x952FA6C21888484EULL, 0x572F415B5BEA0BA4ULL, 
            0x273170B94F51D9ACULL, 0x88A8C69F34EA8416ULL, 0x2BFB6F7938989B45ULL, 0x5B942F7704DF9A13ULL, 
            0xC4A6D926FCB0F7FEULL, 0xFE605F2D7758A61FULL, 0xB6A65222279BE0E9ULL, 0xEDE8E7F7D11FFB67ULL
        },
        {
            0xFC2F53B62686B637ULL, 0x1CCCE389919B1C6EULL, 0xFA29AFDA5C66206FULL, 0xC460C786ACE63A0DULL, 
            0x309F887354A927E2ULL, 0xBE8BE97EFCAE12B5ULL, 0xF8D4ABA0AFBE334AULL, 0x4EB6B69E9DCFE91AULL, 
            0x8AFB3DF02202FCE4ULL, 0x733E94097B62410CULL, 0xAAC201666F5B3228ULL, 0x894838BC9181FE0AULL, 
            0x814D414B592B222DULL, 0x17CBDD253BB07D01ULL, 0x22FE526F72EB19DAULL, 0xCDB19093C0F65280ULL, 
            0x89895C4F494A841FULL, 0xB67B32D448165AFDULL, 0x3E654223815BD95BULL, 0xE6532D5274D67889ULL, 
            0x3DBA79141FB5D786ULL, 0x07E4A58259CDCD6EULL, 0xD40D19993B1D3E01ULL, 0x52B4B732A145332BULL, 
            0x5512EAAC0EF340BEULL, 0x8EEB9AC68A433DF4ULL, 0xE198543861A1986BULL, 0x643EFC3693C91DCCULL, 
            0x61EB10227B67146CULL, 0x638B9EE66B4D0780ULL, 0xA0A85384ED32209CULL, 0xE667B9A0F848C2F6ULL
        },
        {
            0xADB6AFB8B34BD52BULL, 0xBA440839BCF5D266ULL, 0xB90342CBE0BCB3CCULL, 0x22AFA4320F454161ULL, 
            0x6C627A2AE1A334F4ULL, 0x833B192C6B6CFD8FULL, 0x9821FA4AECCEC4F1ULL, 0xB825BEFB0C2DDE42ULL, 
            0xBD847498B1D06CBFULL, 0xC11E1402B2F6FE52ULL, 0xB31B349E5C9C8D50ULL, 0xF4D284FE20210574ULL, 
            0xAD7EDC1587C844E7ULL, 0x1FEB96BF6FC5E267ULL, 0xB959AD415B95016EULL, 0x82580363538B8D70ULL, 
            0xFEAA89CFE7F4F393ULL, 0x89C57D8CCE806DBEULL, 0x02949288EA6AFEADULL, 0x46B6A9A36CB4395CULL, 
            0x343DE023FABA298EULL, 0x58821F7A5914277EULL, 0x677475F1F85FA90DULL, 0xF3A3A70F543FC89AULL, 
            0x42DE2E61E29597AAULL, 0x0CEF11C0F2FC426FULL, 0x6FE79033884A4723ULL, 0x076B3C50BDEB8277ULL, 
            0x5AFF0B5FD44ADCF2ULL, 0x277A472E4E82BEDDULL, 0xC194532AE951DC3AULL, 0xF9BEADD3407C48E8ULL
        }
    },
    {
        {
            0xF2B8A54B11A2FEDEULL, 0xF0E395762E9EB36EULL, 0x9A9EDC58A5B88C6AULL, 0x69EEB1AA81D738E3ULL, 
            0x057CD0464BE1E47DULL, 0x61D6671B0961E1A6ULL, 0x81B7B814331CF225ULL, 0xA34CFC3834BB2A0CULL, 
            0xD0A05245EB5BB120ULL, 0xC8BC1719AD901E8CULL, 0x24834DF21750C197ULL, 0xB3E63C79DCFF1C2DULL, 
            0x3361BB21AD29B061ULL, 0x04CC5A396861E31DULL, 0x2292BFD055C5970AULL, 0xEC6FDECF06B859FBULL, 
            0xCEEA3DC7C5E849B4ULL, 0x16C68D67A79A2A82ULL, 0x1674E1E8C1B8517AULL, 0x72B3F8CDC5BD41D8ULL, 
            0xEF11E485E93149C7ULL, 0xE726B04AD13FDACDULL, 0x4F4DE1713F182B14ULL, 0xA767B11EE47EA025ULL, 
            0x3134C70C56011D0EULL, 0x6C0404D5FB893B10ULL, 0x0EAD066679C9A84FULL, 0x561DBBDE1379BC82ULL, 
            0xFE8DC51117789D8FULL, 0x0433E35F490F48C7ULL, 0x68D894649911F08EULL, 0xBAE4D6341FF20F34ULL
        },
        {
            0x044A7FEAB3A546D9ULL, 0xF63BD4CB70B24741ULL, 0xC3CB474CA851E542ULL, 0x1D4C18633786B089ULL, 
            0x809FB761416FE82BULL, 0x5FBEB8F944A9CA13ULL, 0xE83D2BE5D28B37EAULL, 0xB26B2ADF08068037ULL, 
            0xC67B6CDE36FE46DCULL, 0x8FC4B6502EC22569ULL, 0xE2AF0DD66FC2AC68ULL, 0x284E36209CD90437ULL, 
            0x3B37BD45F6D068F7ULL, 0x97569715ADE86DDEULL, 0x89DEB4AE6C307399ULL, 0xC10785C3FF550418ULL, 
            0x50E3D2737F1D4E02ULL, 0x41B799B3EDB9B8FAULL, 0x3FE1C8F2273C6028ULL, 0x4299E122930E9B09ULL, 
            0xD58AAA09E56C82F7ULL, 0xF26C935E45F59512ULL, 0x811705825DE66B67ULL, 0x87466C3869798CE3ULL, 
            0x96D897554420DA14ULL, 0xC440E1F3481274DDULL, 0xB5D7D3EF06A061D9ULL, 0xB58E3CD7B1E15060ULL, 
            0xE4D17A20682C9350ULL, 0x79C0190985163AD2ULL, 0xE9E8D59437E4D52FULL, 0x946DC4A062DBB6A1ULL
        },
        {
            0x251EB6DBF682903DULL, 0xAC5609372347195BULL, 0x6C08E07B6223EC64ULL, 0x1A458105AF6811B2ULL, 
            0x1562DC52AF725588ULL, 0x97A60474FEEF3AF1ULL, 0xFF46295420E20E8DULL, 0xE57F8B8F9698760EULL, 
            0xEAA01399C8DCC3EBULL, 0xE29374BA5B3270F3ULL, 0x48E4D05DA7C0C204ULL, 0x0AD0CF1308ED5265ULL, 
            0x63B458BF15AE469EULL, 0x3FE89B83D124B562ULL, 0x6E249392C4FE6386ULL, 0x22F608DB7EE7E4A3ULL, 
            0x2B2D5DAF62AF3687ULL, 0x93DEA4E5E0610496ULL, 0x250AB50DCD43C9C7ULL, 0xCD0E4B6DC4D8690DULL, 
            0x648C9BC5713481ABULL, 0x6217E304E53BB421ULL, 0x40F59795C5B5271DULL, 0x944688D807757276ULL, 
            0x1D257F608301A192ULL, 0x4C2CB589CC1BB120ULL, 0xEFCA387BA711956DULL, 0xB34ECAFBBBAEAC0AULL, 
            0xB76EBE2CE444990BULL, 0x204089CC94AD7E72ULL, 0x1F1E87D9D2802C7CULL, 0xA4DF4C5B79D56EE4ULL
        },
        {
            0x62EF1AA3E0D7B5F2ULL, 0x3E9D8806A98F4B69ULL, 0x7D72EC53D1C090C5ULL, 0xCB8AB4A4D720E806ULL, 
            0x517046CA1EEA3C98ULL, 0x887006BDEF66EEFDULL, 0x50280D76DF0A9FBDULL, 0x99914E699BBEE6E8ULL, 
            0x3D116859C6E534A6ULL, 0xBEEBB958916B04C1ULL, 0x479652C9505CEBF8ULL, 0xF7C2E4CC89A4CA3CULL, 
            0x0C28CF83C5B6BC8FULL, 0xF69FAD4BE1A5137CULL, 0x2947999E136DD8D7ULL, 0xC291DB12BFDBD7CBULL, 
            0x5740F1C7E79DB11FULL, 0xEB93CF66A90192EBULL, 0x39D39EBA87A3B9CFULL, 0xACA286F9AF79C46DULL, 
            0xC901612FB2A34B85ULL, 0xFFD17FE79F251261ULL, 0x78B02572B6E73A84ULL, 0x7865F3CCC544A66CULL, 
            0x7EFADDFD8F575046ULL, 0x3F2AA522A90F6CEDULL, 0x8862B8C464AA2D6BULL, 0x34523897933920FDULL, 
            0x57925C180D0EF3CFULL, 0x56D1A4CC2C54CBA0ULL, 0x80E1C6C8851559B6ULL, 0xC7456CF260604BC6ULL
        },
        {
            0x64234E6FBB5CD6FAULL, 0x02E233F15CE12C33ULL, 0x7CCA13B9B97AD7C5ULL, 0x8EE90D301A4BCE13ULL, 
            0x20EF0F4FA51CBFC1ULL, 0x7ADCDAA4146C7B04ULL, 0x456E8757BFA971E9ULL, 0x1FC7885BDB32ACE0ULL, 
            0x74B72A1CC74F695CULL, 0xD66332A4C4CB764EULL, 0x907C50C9C92CBC5AULL, 0x6999737717693D7CULL, 
            0x59D3EB4803A63B86ULL, 0x8ADDD68318C5F790ULL, 0x2E0270DC7DF1A230ULL, 0x99D4CFE18724BC7CULL, 
            0xF1B7750B478E71EBULL, 0xFFB68CB90C5C333CULL, 0x3135088697E24873ULL, 0x37E4AD87BA85D8D1ULL, 
            0x20101493A8AC03AFULL, 0x50663023F844459EULL, 0x3A8E99D733886F25ULL, 0x0456A70B975E6570ULL, 
            0x913C5D51F45F7DDDULL, 0xF1B1BB104AEACB12ULL, 0x83DAF16B68928AAFULL, 0x912E468C50AE4E78ULL, 
            0x035F4247C81D6B53ULL, 0x10DA0B8925E5DCE1ULL, 0x67CC7B1E6E579F24ULL, 0x04085AA33A522AACULL
        },
        {
            0x9110DB6E13452340ULL, 0x430EA1B12E5A9734ULL, 0x7EEA5EFA8F3CF9B0ULL, 0xFC08C77C42626A8AULL, 
            0xF8D95C4B6DA285CFULL, 0xA64FBBDE398E71B0ULL, 0x766834C3345D73B2ULL, 0x5F2FEE9354B1DA4CULL, 
            0x499512744E86B742ULL, 0x329EE0BAC00BFF42ULL, 0x3060CC60FB65EE5BULL, 0x968CEA042DBAC8D3ULL, 
            0xCF3F52060A9B6F4BULL, 0xE6EB67159CF9D83DULL, 0xB6521E0F915452B7ULL, 0xF027B0EE39DB317BULL, 
            0xB6ACFF87BCFC4EAEULL, 0xF2EC5A77F92F1F8CULL, 0xB96512AEF47E724DULL, 0x5B12041E16E98C9BULL, 
            0x25628E0B0B0FAD4FULL, 0x6DF3A50DD8DF2168ULL, 0x4529CDAD07F968A0ULL, 0xC28CE1C8F0669BB7ULL, 
            0x0FE3CEA79AC9E802ULL, 0x7151D7B8E7DA55B6ULL, 0x461AA63012B83403ULL, 0xD3302676A71E0237ULL, 
            0xDFEB725982EF468DULL, 0x4D47F52B2AF3E838ULL, 0x03EDBAB9B15604B8ULL, 0xE292E54536B96F13ULL
        }
    },
    {
        {
            0xC58522B0BA82E32EULL, 0xF85A704F612B52C2ULL, 0xB20FDFAE9A578A00ULL, 0x418ED8AB18D99C94ULL, 
            0xD853AF5E3BF8B732ULL, 0x32D5CEF546D66B15ULL, 0x35FB1DD9BBEA51B4ULL, 0x933EE09A9CD6CCB8ULL, 
            0x7F545F69CB783B55ULL, 0x3D55774D69D8BAB8ULL, 0x5D1C4478E23EB07DULL, 0x498D38186E917AE6ULL, 
            0x2B1D2CE86A190078ULL, 0x8C99712B40909937ULL, 0x92698AADBCA8CA44ULL, 0xF3F9F74EEAC188C1ULL, 
            0xB92952EF744A1372ULL, 0x60DB1FF3D65FA7D0ULL, 0x72F50F0E3CFACB28ULL, 0xF6A24FCE619D06E0ULL, 
            0xED9A5B0A5D8705EEULL, 0xBAB30A935E8F32FBULL, 0x7FB0862FA8369A09ULL, 0x55CC496BFD83C136ULL, 
            0x9AA0BDDD8035F92DULL, 0x77BFD5A911E64BE7ULL, 0xC00407EE333BAF84ULL, 0x875891467BEAA10CULL, 
            0x31822E4EFC736375ULL, 0x86B1DBF144091061ULL, 0xA6A312CF4F44A365ULL, 0xD74DC094ACB204B6ULL
        },
        {
            0x67C4BE672F3F2A5EULL, 0x88FA7D101934978CULL, 0x8E93133EDDB21ADBULL, 0x24064F18B3C96536ULL, 
            0x8DCC3A76E5CADA1FULL, 0x6F2286F3C0474B43ULL, 0x888C3DAAEE650F6DULL, 0xE5CFE4D8CD0A8BDCULL, 
            0x1633E2596A2B504FULL, 0xBEF714A6CE12AFC4ULL, 0x4EF4666C87A82DC5ULL, 0xB34DAEE1527B7BC3ULL, 
            0xFCF8A441EEC366EAULL, 0x88BFA241C11D6F48ULL, 0xF2F01964E7853094ULL, 0x0485AC3CFD570B55ULL, 
            0x5C69870E2D9F8DA0ULL, 0x178928F9C82E275DULL, 0xDB4FABA3456C6E2DULL, 0x8520F234E8C087FBULL, 
            0xBCC85DD56EE370BBULL, 0xA964A417B8871222ULL, 0x1D2459E5B597164AULL, 0xA9C01EEBD80D5754ULL, 
            0x29B9616DF10FA4A4ULL, 0x415D6BAD975D6294ULL, 0xA7CCFDAC6BE1A657ULL, 0xD7D45238B865BD6EULL, 
            0x0F32E1AF88C9B09CULL, 0xBAD8D50DF0932C1BULL, 0xF17AFD0D53C56DB0ULL, 0x444B28BB0934D161ULL
        },
        {
            0x9BF7FAE5C2D16D0EULL, 0x67FE2C21EDC9606DULL, 0xE07AE55551F6127CULL, 0x39BC4B37CC60FC91ULL, 
            0x42626A7B2885EDF8ULL, 0x9B67D2C0D5DD6BA3ULL, 0x93A6D22A9ED38DC7ULL, 0x124C6F831F648C2CULL, 
            0xA6DB9C4F366CFF0DULL, 0x1B42148D12F685C2ULL, 0x4782F6CA2E632BD3ULL, 0x4C0304F6D59B7B85ULL, 
            0x4AE378A7D1E73954ULL, 0x963F1ADD55D82766ULL, 0xBA7ADEF28ABABB6FULL, 0xAAA61DCFFEA72736ULL, 
            0xF47C0A693381143FULL, 0xF51DBA08DF645866ULL, 0x5650EAA8FDA5B718ULL, 0xE0C28A1966BB5684ULL, 
            0xA1F366520D7720A8ULL, 0x942A0DAC9C7DAD9BULL, 0xEFD9F3EE37290750ULL, 0xF2C02C4FB1F0EAFFULL, 
            0xCE3AB5DCD2010DF5ULL, 0xD6B9C723AEA6E7A2ULL, 0x4024FD92EB968916ULL, 0x49155E0D8E45B3BFULL, 
            0x6611B04EE751BCB0ULL, 0xDF347E7B5A89EF04ULL, 0xDBEB7B7DB9B516F7ULL, 0xF61D03C5B7C64C73ULL
        },
        {
            0x1D5CABDD3315674DULL, 0x4026FE9C0DC1ED2FULL, 0x137F1156FA5C6C35ULL, 0x035BF3D2AC127E1DULL, 
            0x268ADB627C6A6E2AULL, 0x89F3B3302854B6ACULL, 0x5108F3579695A62AULL, 0x70641D436605DB15ULL, 
            0x06BD6653AE5B72F8ULL, 0x054521FACB24833CULL, 0xB8AE23D374001136ULL, 0x9667D8C2B2C698E4ULL, 
            0x2E19B93B9DD00F9AULL, 0x35BBA045942CF08FULL, 0xF709CDAFA0F772D1ULL, 0x0181F6F21809FCB3ULL, 
            0x5C4D8B75C92B6C97ULL, 0x7562D629CF65162BULL, 0xE51E9F4B47CC6126ULL, 0xB34E33ECC0A9B07AULL, 
            0xDD906CD7765AAE6BULL, 0xBEE93F18E0F2ECFAULL, 0x32BDB834E0380E09ULL, 0x92E7A57FA6C0370DULL, 
            0x89B0A9FECD5AA357ULL, 0x32E6F60A8052C385ULL, 0x8EC8E5F42F35B032ULL, 0x3345B695691B94D2ULL, 
            0x61B07B454AF7BC0EULL, 0xA691618AAB05FAEFULL, 0xED3F9229D22B8821ULL, 0xE07881355E7EBF53ULL
        },
        {
            0x7EA526229F674A2CULL, 0x2948F54178FA25F3ULL, 0x0DBCEE3B17F86429ULL, 0x6867D5C8FD0E33D6ULL, 
            0xE32EBCFBB736ABA5ULL, 0xA0F0FC1F42495225ULL, 0x373248453678F102ULL, 0x7B117BDB049C654EULL, 
            0xB9D53D4EC8B0A0E1ULL, 0x88CA721BBBA92ACAULL, 0xFD30D38EAC8C80B7ULL, 0x1358F888067B7EDBULL, 
            0x28F63E35B69A6ED4ULL, 0x1D1952D19DB61CAAULL, 0xB1DAF057F8F1551EULL, 0x6BA45715A0AD2355ULL, 
            0x0B4AD247AD01D304ULL, 0xFB5687C281974107ULL, 0x86455D57F6F24E4BULL, 0x4D7E00A5E9081C3EULL, 
            0x79DFB00CD46A9328ULL, 0x12A268AD570F850BULL, 0x83589D9C2A402D3DULL, 0x47B580A4ED0D73D0ULL, 
            0x324B3BFC9455A530ULL, 0xD4905DB5217BC56AULL, 0x65C4B681393941E0ULL, 0x480929C36AF2C86BULL, 
            0xEED098998012C49CULL, 0x2C233BC733C62C95ULL, 0x537F15EB478FD666ULL, 0x0EEE5A8F4BA7D793ULL
        },
        {
            0xC60F13016982418EULL, 0x43234E2A8DC0050CULL, 0x4F3AACCF23519BA3ULL, 0x7B165F503921BA7CULL, 
            0x481C9AFD75A906FFULL, 0xE8A5C2A4C523CEE9ULL, 0xE5FF24100C8CACB5ULL, 0x6FA93ED2A8864AFFULL, 
            0x58AA7749019BD4ADULL, 0x4640B40C92D4D503ULL, 0x7A3345C6732D3C4EULL, 0xFB492EA216CA1A38ULL, 
            0x347978486427814EULL, 0x13ED531A562E4419ULL, 0x8E7525E49546B6F7ULL, 0xE89F657201C042BEULL, 
            0xDBA35EA737AF956DULL, 0xBEAE9460658EF9BCULL, 0x311716CE79550E03ULL, 0xBF5C0FAD0ED1D102ULL, 
            0x6CDCA636F205CBDDULL, 0xF9045E91E3FD40A7ULL, 0xD1B8F45F9934050EULL, 0xD553BC48699120DAULL, 
            0x8F57BCBD08AEC986ULL, 0xD3C086657ABC1332ULL, 0x78BAC7DB35D8B9A5ULL, 0x9EC7ADD1F0AF8546ULL, 
            0xC791A1793FC7D60DULL, 0xE4B3D51B2FBB20DDULL, 0xC6B6ECF62C3D87F5ULL, 0x30E09EA2AD60E5BAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kTwistConstants = {
    0xBD5489916B4872CCULL,
    0xB348CB49E37A3490ULL,
    0xFC009C40CC00271FULL,
    0xBD5489916B4872CCULL,
    0xB348CB49E37A3490ULL,
    0xFC009C40CC00271FULL,
    0xD3C7C1B1FCA851C8ULL,
    0x333FC7F651F128D6ULL,
    0x88,
    0x93,
    0x09,
    0xBF,
    0x53,
    0x16,
    0xBA,
    0x10
};

