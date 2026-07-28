#include "TwistExpander_Pollux.hpp"
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

TwistExpander_Pollux::TwistExpander_Pollux()
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

void TwistExpander_Pollux::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Pollux::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDBBCBBBDCA040818ULL;
    std::uint64_t aIngress = 0xA1D8C2CAF3EF5BE3ULL;
    std::uint64_t aCarry = 0xB18CE357DAD25C7CULL;

    std::uint64_t aWandererA = 0xABA442436B16DFC2ULL;
    std::uint64_t aWandererB = 0xDBEAB14388081A2EULL;
    std::uint64_t aWandererC = 0xD8D25476EC529BBEULL;
    std::uint64_t aWandererD = 0xAD2A15645EE0CBE2ULL;
    std::uint64_t aWandererE = 0xB17F061372114564ULL;
    std::uint64_t aWandererF = 0x81BCD98E11BF4097ULL;
    std::uint64_t aWandererG = 0xC495B1D4CBCE7B6DULL;
    std::uint64_t aWandererH = 0xFB6FFF22776C623AULL;
    std::uint64_t aWandererI = 0xB0EF8E2D4D8571F5ULL;
    std::uint64_t aWandererJ = 0xFB4900870AB3E0B1ULL;
    std::uint64_t aWandererK = 0xF3554C3EAA12ACB1ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x89381C2753C3576FULL;
    aIngress = 0xBF81019EB99E5E98ULL;
    aCarry = 0xEC744167A45E23EDULL;
    aWandererA = 0xBD0C639D4231E59BULL;
    aWandererB = 0xBD13F563C14A4C40ULL;
    aWandererC = 0x80F7B18306823596ULL;
    aWandererD = 0x8139DA64DCB2BBE8ULL;
    aWandererE = 0x99AEAA42A23DEA37ULL;
    aWandererF = 0xE96EFAE6BD174DC7ULL;
    aWandererG = 0xB7086A850907CF86ULL;
    aWandererH = 0x9760F979DF080756ULL;
    aWandererI = 0xA8316F824C441D08ULL;
    aWandererJ = 0xAB8880BDB0DD39C7ULL;
    aWandererK = 0xB933045EB070B365ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x912612D9A108F231ULL;
    aIngress = 0xAD5DFCC7BA070881ULL;
    aCarry = 0xE3E42E6115B2F376ULL;
    aWandererA = 0xC2CAE5BCDC5F666AULL;
    aWandererB = 0x85263DAA95499806ULL;
    aWandererC = 0x92312E2772DF9AAAULL;
    aWandererD = 0xED39E6328BD72A36ULL;
    aWandererE = 0xD6DCD668023DA68EULL;
    aWandererF = 0xF06E6B76AE278664ULL;
    aWandererG = 0xDA9B188998E9712DULL;
    aWandererH = 0x990ABBA4049A910DULL;
    aWandererI = 0xCDBA070B402E4E5BULL;
    aWandererJ = 0xC0B66E239166F17EULL;
    aWandererK = 0xE8937D8926FC414AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xEE2F1A184D9F0217ULL;
    aIngress = 0x83146781EC03F9BEULL;
    aCarry = 0x80920C613C2DBFFCULL;
    aWandererA = 0xF7DCE6415217860BULL;
    aWandererB = 0x8055C9FE3E20C225ULL;
    aWandererC = 0xE9E3E413EA903814ULL;
    aWandererD = 0xA9444E6A868BE751ULL;
    aWandererE = 0xA1DCD6A55CEAE7E0ULL;
    aWandererF = 0xED030BB8E5206D46ULL;
    aWandererG = 0xA354A5A36BEBF40FULL;
    aWandererH = 0xDA63C9B25A7830A7ULL;
    aWandererI = 0x807E00AAEDF823FFULL;
    aWandererJ = 0xEAFEB76AA2EEDB75ULL;
    aWandererK = 0xF6C391CF1D550B27ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xB5CA64C2A08BF067ULL;
    aIngress = 0x8C8E089D97EA04F2ULL;
    aCarry = 0xF248B4CCC5823231ULL;
    aWandererA = 0x8369BAD46D40DD40ULL;
    aWandererB = 0xF182CDB74918A858ULL;
    aWandererC = 0x89EF78772CB67059ULL;
    aWandererD = 0xF567840B605E5D70ULL;
    aWandererE = 0xE58811035349B673ULL;
    aWandererF = 0xE37F5C9B985CDE4CULL;
    aWandererG = 0xB0C0566572AD0325ULL;
    aWandererH = 0xEE10D9FE265A20C5ULL;
    aWandererI = 0xAFA5637A67C71327ULL;
    aWandererJ = 0xC8413273398E3849ULL;
    aWandererK = 0xC18CBD33AB9C206DULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE5B43FE414B979B8ULL;
    aIngress = 0xF3B317D7B7F00DB5ULL;
    aCarry = 0xC6EE5D9FA4E03936ULL;
    aWandererA = 0xB50A42E2D31FEAEDULL;
    aWandererB = 0xC579E772425BB3F8ULL;
    aWandererC = 0xD48394AEB7850302ULL;
    aWandererD = 0x8E1D1EC997C9CB7BULL;
    aWandererE = 0xE38D0C5CCA1032C6ULL;
    aWandererF = 0xBA8A5F2F343E5BE4ULL;
    aWandererG = 0xFD2CA37AAD64C0B3ULL;
    aWandererH = 0xFAD4A274ECC26423ULL;
    aWandererI = 0xD7ED039E380D2ABBULL;
    aWandererJ = 0xCD3216B0F189F19DULL;
    aWandererK = 0xE3D54DAFB7525753ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xFCD5A9D5C4FAFB87ULL;
    aIngress = 0x932BC303688AA969ULL;
    aCarry = 0xBD1E4BD1F3EB3FA4ULL;
    aWandererA = 0xD52C5075EF1FB106ULL;
    aWandererB = 0xE074BD68830183F3ULL;
    aWandererC = 0xCC5C55796ACEF6D3ULL;
    aWandererD = 0xF6B010441573E969ULL;
    aWandererE = 0xB1D88ADB8F772887ULL;
    aWandererF = 0xCE0ED55C9EC2C4FEULL;
    aWandererG = 0xB9D52629D0B14948ULL;
    aWandererH = 0xE4FD0441C23609EDULL;
    aWandererI = 0xAA6B76E9A71C1DC7ULL;
    aWandererJ = 0xF854178ACA8FDA06ULL;
    aWandererK = 0x8B147A31AD8B134AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xF223471118D2E40AULL;
    aIngress = 0x878F6B4251F94E42ULL;
    aCarry = 0x88119C59449749E8ULL;
    aWandererA = 0xD17A3CD270873E36ULL;
    aWandererB = 0xE3E9872FD1D813D4ULL;
    aWandererC = 0xDC0FC4DBCB19834CULL;
    aWandererD = 0x96EEC85D95D72D26ULL;
    aWandererE = 0xEFCB983E508E2809ULL;
    aWandererF = 0x84E68CB1B87BE6C2ULL;
    aWandererG = 0xC5329717305B207CULL;
    aWandererH = 0xBF740CAE3D8C9742ULL;
    aWandererI = 0xBF51B3AF6DF3B683ULL;
    aWandererJ = 0xAE7FDB0A9C3881C5ULL;
    aWandererK = 0xF7516543A6802057ULL;
    //
    TwistExpander_Pollux_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Pollux_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Pollux_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Pollux_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Pollux_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Pollux::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEB91CB00C669CE5DULL; std::uint64_t aIngress = 0xCAABAC25A2B1F9F4ULL; std::uint64_t aCarry = 0xE3CAEA0F1E6C6680ULL;

    std::uint64_t aWandererA = 0xF391A7C7DABFECC3ULL; std::uint64_t aWandererB = 0xE42A7C2E1F7CF02FULL; std::uint64_t aWandererC = 0x852F5EABD08C0645ULL; std::uint64_t aWandererD = 0xB7DA928EE68B3001ULL;
    std::uint64_t aWandererE = 0xD38744C78BC6B0AEULL; std::uint64_t aWandererF = 0x9DD40F4627E6AC32ULL; std::uint64_t aWandererG = 0xD338934A6017A4F8ULL; std::uint64_t aWandererH = 0xEDB8F0F38D1210A0ULL;
    std::uint64_t aWandererI = 0xF1653F8A03FB27A0ULL; std::uint64_t aWandererJ = 0xAB0FE32C76889319ULL; std::uint64_t aWandererK = 0xBC3611ADD4359534ULL;

    // [twist]
        aPrevious = 0xA85C8C4DE087213EULL;
        aCarry = 0xE21924C367293E3CULL;
        aWandererA = 0xA1D6AB0EBB2B4D65ULL;
        aWandererB = 0xE0F1730F22FCEB6EULL;
        aWandererC = 0xFA5A8F99A88C2D62ULL;
        aWandererD = 0x8A8E91A88CD3B3A4ULL;
        aWandererE = 0xFC704D2F6D32FD3FULL;
        aWandererF = 0xFDA62053AC238372ULL;
        aWandererG = 0x8BFBEAF52880DC2FULL;
        aWandererH = 0x967292A25DBFA9E3ULL;
        aWandererI = 0xB13CFF631D089FC9ULL;
        aWandererJ = 0xFC1201D48DF7A8E2ULL;
        aWandererK = 0xF973C9F59F7716D7ULL;
    TwistExpander_Pollux_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Pollux_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Pollux_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Pollux::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Pollux::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Pollux::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 25 of 33
    // Exploration cases: 0
    // Structural maximin 513 / 674; family total 12779
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1375U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 25 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 12834
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
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 745U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Pollux::kKeyRotateASalts = {
    {
        {
            0xA8DAB6A2B16FA709ULL, 0xF1C348AA09B824D0ULL, 0x668EA649B830997EULL, 0xDB3E15E02E66978EULL, 
            0xC08E83BB0A56D943ULL, 0x5A6426397221B464ULL, 0xAEDD05BB58E30AAAULL, 0xBF844FFE6DB933D8ULL, 
            0x03BE32F7499178D7ULL, 0x578869F304DBB282ULL, 0xEF786CA9ADF48607ULL, 0x082479B05514FC8AULL, 
            0x9A4EBE6CC95F6B24ULL, 0xCD6B4743CECE8508ULL, 0x46ED713569A7ABDAULL, 0xF6FEEF6525FA35FEULL, 
            0x620F7089C8CF034EULL, 0x8A88E66E5E258D85ULL, 0xCE6D3C935ADD772DULL, 0x864FF1FB3EDB1EFBULL, 
            0xFE21802AF8B167B9ULL, 0xCC5BE75BCE5C7D83ULL, 0xD645906D05823266ULL, 0x537238CE498A5368ULL, 
            0xFA37C9CCC389C14AULL, 0xBD9FDEABB51863A1ULL, 0x3F0B6EB3F79437D0ULL, 0xA80D8E9090F74BFBULL, 
            0x80916218A09B082DULL, 0xED62A4F7CC1510B3ULL, 0xC27C5C330EC57D8CULL, 0x78C7B2AE886A2748ULL
        },
        {
            0x1ACBC5506E3D4C52ULL, 0x0864FCC5C3007C43ULL, 0x1AC84DAE059815D3ULL, 0x9FE96B0689549FEFULL, 
            0x73848A4DCD73798CULL, 0xFC91AD474639BEA7ULL, 0xBA2DDAF3D791F229ULL, 0xA316484D47EF978BULL, 
            0x7382FD46AF92DFC2ULL, 0xFAB77A3C9920802AULL, 0x0A90536229DE0B56ULL, 0xC091594042AA9BE5ULL, 
            0xA49021C3A9E2EBE3ULL, 0x0978C77A54F78305ULL, 0x0477A435717211A3ULL, 0x1CEEC85DA83B591CULL, 
            0x7E8630160EF7B099ULL, 0x06C44EA94478F4E0ULL, 0xF848FFCE2C42E8EDULL, 0x899CCEC106E8B241ULL, 
            0x72A7D8665EF3F1B0ULL, 0x974E0DA07EC32D50ULL, 0x815D7424F0E743C5ULL, 0x4FD2470624024A12ULL, 
            0x05AFD3DDFE634A65ULL, 0xB10134A34EC11526ULL, 0x84E5FAF1942640A2ULL, 0xDF83782864D3E0D8ULL, 
            0x913F3E689C81CBB7ULL, 0x65EE6502D9FE20D6ULL, 0xCFEA70A9A169FC2AULL, 0x59991B7666D9416BULL
        },
        {
            0x98EDDAB543B06DC3ULL, 0xD8BCA87E858756DFULL, 0x79DBCD8BB92653D2ULL, 0xB6CC69C2A36E31D2ULL, 
            0xF17DA5CD6D1EAA84ULL, 0x4F223E80ED0801BBULL, 0x6592391410A6F67DULL, 0xC4D3E49FF1B511D8ULL, 
            0x1B83B47F19A75923ULL, 0xCB415B7A3A3A0866ULL, 0xD6B379C324FC32C6ULL, 0xF21524AD91174FEEULL, 
            0x1EF5364EB0327237ULL, 0x42340496C24F9A57ULL, 0xA5E07F165E0527DEULL, 0x816DF0D913AF1E56ULL, 
            0xA80923FE45171FE6ULL, 0xE11D86E2C7F4F369ULL, 0xE8BBF380F228D34BULL, 0x9EE4A1FAA5E49202ULL, 
            0x8A75E32A2106C89DULL, 0x2DEA85B340E30B6BULL, 0xCA260B317478C6A4ULL, 0xA61B51C54A9F12DAULL, 
            0xD243139BDBB1E5E1ULL, 0x34438323F417F2C7ULL, 0xC34121C890CC74C2ULL, 0xA2EBE25918368C73ULL, 
            0x56F7A895ECCDC6C8ULL, 0x387EA9F81FA2B15FULL, 0xF5843E7E12C2EC0FULL, 0xA585CEC1BD11D4E6ULL
        },
        {
            0x6D1166AE4E236102ULL, 0xB9B35BA697834818ULL, 0x367D19EC3D9692DBULL, 0x66F30DB7EE54E490ULL, 
            0x1FAD55D4F42D1349ULL, 0x6EE4108D9BD1EF5FULL, 0x605A3DD829D7BFF8ULL, 0xC060F9C2E70E7662ULL, 
            0xD7639C15E12A4730ULL, 0x022F596574B33A4EULL, 0x475373CD76DD6715ULL, 0x133C555EE63CDD1DULL, 
            0x84ED6BAEB32BD6D4ULL, 0xE7365990A9CFF6B5ULL, 0x5D8914E55C3E3465ULL, 0xE654C512910C2272ULL, 
            0x7D5954F362E2ED8FULL, 0xFAF826E859757C9EULL, 0xDCDA9383D1C7AD4BULL, 0x5732A528AB814069ULL, 
            0x237CEBE716A105C0ULL, 0x1AC6200800362878ULL, 0x13D1A0C3CCDA4C57ULL, 0xB5FE8B96A382B9B2ULL, 
            0x10D84D2914002E27ULL, 0xFC9799BAB576D984ULL, 0x45A3EB2C27DF8A07ULL, 0x5CCCF5DF2CDC662BULL, 
            0xB67540CB9EF538A8ULL, 0x7B659CB31DCE8EF7ULL, 0x3147A0D7F3ACC8EFULL, 0x1DD819CC74CDEDE0ULL
        },
        {
            0xD4A33C20ECD22281ULL, 0x91582ED24099679DULL, 0x1F5996F1C7A324C2ULL, 0x1D6D06FB6BE225F5ULL, 
            0x7097BFC29DD19FAAULL, 0x014A4FADE1790B02ULL, 0x79E8B2A96F0559F5ULL, 0xD270B451900B9AF6ULL, 
            0xDC2AB26C80A886A3ULL, 0x1DD3224E26C1FA6AULL, 0xB99A870E95CEAF49ULL, 0xBFAB74E6E1137C74ULL, 
            0xFDDE97FE34305390ULL, 0x7E1B59349BBBDCAFULL, 0x16402FBD7DD7C7F7ULL, 0xB0A25096F03825E8ULL, 
            0xEE691393270BB91FULL, 0x3899DDE177679BECULL, 0x94EAC2763DA2A486ULL, 0x8D4EB59E32E0AE7DULL, 
            0x6D4203FF18B48468ULL, 0xB553B7825B1BA2BEULL, 0xF01875C4AA9F54BDULL, 0xB5BE933868434C93ULL, 
            0xC0FA07CBCB4F5762ULL, 0x9063923DCCA8C4B7ULL, 0x99C9E272CCA1AC6CULL, 0x49CF22CE5203A360ULL, 
            0x919C9DDD3BD3DA0CULL, 0x178C20FC5BDDFD37ULL, 0x437D61257A88FCB0ULL, 0x96431323383AFA95ULL
        },
        {
            0x810628161FCAEF5BULL, 0x5C94E76D9C73948DULL, 0x1436BDDB1A693962ULL, 0x1514EDB26689B791ULL, 
            0xFE22366657B26E36ULL, 0x8A7DF0D0E47BF5E9ULL, 0x1C2CCB3FC1D85964ULL, 0xF19E9196C747E7FAULL, 
            0x13D5D9F34DEA64B5ULL, 0x12B2E7536348EE48ULL, 0x2358005CF3C98162ULL, 0x8FB2DC2669725078ULL, 
            0x828C554006947E6EULL, 0x87E18CC1784A9957ULL, 0x751EF2F50419826FULL, 0x8840B9FCE49C6FC9ULL, 
            0xB12C51271B32F1A9ULL, 0x16B5E7498CC4F3F6ULL, 0x4F80745FC62D913BULL, 0xC75F58F7809F3EB6ULL, 
            0xF2B411BD43CD7B5EULL, 0x3E800B956D71FE70ULL, 0x6154C1A4B96DED3BULL, 0xA1B73C6074E287E8ULL, 
            0xC56105D5031E9FC3ULL, 0xAB596729E01DE913ULL, 0xED126058173D911CULL, 0x310ED0BD96E19DC2ULL, 
            0x06E08DABFDE1D11EULL, 0xD440979A583844CBULL, 0x18D6E8AC39FEBD25ULL, 0x28E15006797DF8F2ULL
        }
    },
    {
        {
            0x9FF1A92242E073D5ULL, 0x142D0CB5C257C097ULL, 0x3DFC9B6DCD9D962CULL, 0x09E9C2F5271E593FULL, 
            0xDB568AE4308D266EULL, 0x4EC0BE4C1A1726F0ULL, 0xCC9E878858827CFAULL, 0x6A07206C6E37E060ULL, 
            0xAF159C735246A330ULL, 0x769CE376E60BFCF4ULL, 0xEB35DAEB7E81199DULL, 0x0E24E30B6AFADBC7ULL, 
            0xB5CE923049259E56ULL, 0x0715255EFE863571ULL, 0x5058B76FCE8B581DULL, 0xBA4E244AADD45620ULL, 
            0xE926948750034216ULL, 0xF9268CC272C974C2ULL, 0xF16206A7BA28A062ULL, 0x339B7C9D94FDC90FULL, 
            0x499D30166879490AULL, 0x64B9D45AC0E6EAAEULL, 0x5A2026C218C8F2B9ULL, 0xC3CFE805CCCCF441ULL, 
            0x37BEB42531613BEEULL, 0xC1EC2C26E1337B70ULL, 0x06CD692D316C2F2CULL, 0xF7EC5CA53C387288ULL, 
            0xF7BDDDD2F179414FULL, 0xACBF67DDA6C1E44BULL, 0x755242B917DE1A90ULL, 0x9A20B7C0383401A7ULL
        },
        {
            0xCCEF6DB786D8722AULL, 0xAAAAF2AE59A01A8EULL, 0x8550841DB3F075FDULL, 0xB1C55FDFCD282E92ULL, 
            0x434021C49BA62679ULL, 0x878BD94A963B6CD7ULL, 0x4A16AC507EA4F54CULL, 0xA6A626D48A8CF7CFULL, 
            0xAB4C706B76BE25A0ULL, 0x286BFEABC9556BE1ULL, 0x0DBF6667CF9E74DDULL, 0x5393E4B831D56851ULL, 
            0x0ED5484148754733ULL, 0x69BF573ECAF5AE17ULL, 0xC78FE9E743283EF6ULL, 0x0F28D471550F75EEULL, 
            0x0480FD4CF3DE4E7AULL, 0x70280E36CA5BEA0EULL, 0x616C3A2D2974F401ULL, 0x8B7607897279DC0FULL, 
            0x0B8DCBCC97C13CE9ULL, 0x03544E5B4748B1D1ULL, 0xD8F8F98ADBEC72CAULL, 0xCDC45B81E09FEF51ULL, 
            0x3BD2691F63EBA7CCULL, 0x835CE6C50BC913ECULL, 0x5248DCD6C9D1BCA5ULL, 0xDB21D0759432CB80ULL, 
            0x25BD4908B1BDB67BULL, 0x97BDAC15E9E9CD1BULL, 0x07C473B6B2896FD1ULL, 0x2061998E7160AC92ULL
        },
        {
            0xE4D7B02A34F7739EULL, 0x32B8E7EF44EFEFAAULL, 0xA297291927F459A0ULL, 0x5563C0B63AC15EABULL, 
            0x7FC8B95475EF54B9ULL, 0x7A1234B942E7B5A8ULL, 0xB6C05D3D2F031F8CULL, 0xEAADACAA5B282621ULL, 
            0x5A47F85328B0DF8BULL, 0x3EA9CF0547450FFEULL, 0xC237F46FA1A143F2ULL, 0xE3126CFA3B4FF8A1ULL, 
            0x65D3D462430FA2F8ULL, 0x9AE4F5410AE729F8ULL, 0xD019EB8E3292A454ULL, 0x1B91C0132B0DBD71ULL, 
            0xEB346D8417CCF051ULL, 0xC63AE981957269E0ULL, 0x0F0910188AB98E30ULL, 0xA98E3655867D999AULL, 
            0x214FE648479AD26BULL, 0x618D1E4F13578313ULL, 0xF02F6C63E0F85D49ULL, 0x853EC4F6BC26D2D0ULL, 
            0xB900E79915DF5BB5ULL, 0x4003BF7798BB70F4ULL, 0x62CD8886F1297B6CULL, 0xFA6BAFB3E143C05BULL, 
            0xC6008DF592AACA90ULL, 0xA6D3551D6755BA5AULL, 0x102871BD7670D148ULL, 0x107D3BD75BC848D9ULL
        },
        {
            0x6F7EE0BABCD4A805ULL, 0x21B82B14554BD774ULL, 0x90D552D1AE77CD9CULL, 0x2B5A27CD563943D4ULL, 
            0x23DCC26515BD29EFULL, 0x130BC842039FFE0AULL, 0x357BACD6D703BEC9ULL, 0x6F4D5298698F1416ULL, 
            0x93862C1FD4EF1243ULL, 0x13324E6AD39149DAULL, 0x81E305A6C1990E9FULL, 0x0744E5A570E7E395ULL, 
            0xA705367A06C2215BULL, 0xC0EEB3B45953BACBULL, 0x0434DDD2EC501787ULL, 0x0B26C586FAF44B6BULL, 
            0x25A46546BBB4D641ULL, 0x10B1C4DE50091E29ULL, 0xCA92682A8919F29DULL, 0xDD8D504D029BFAD7ULL, 
            0x0F227C8B5BAB2179ULL, 0x423DAD15037CA351ULL, 0x72E10ED3D047FDD8ULL, 0xC62F3951EAAB22F3ULL, 
            0x4C5A1045EF951BDEULL, 0x2ACEE26829F2E5C8ULL, 0xD029AE0338757E70ULL, 0x6D1CFEA9DF51F7A6ULL, 
            0x907616BADF504E24ULL, 0x62DC8A18992DB4BBULL, 0xA4AFC8433A86A2D9ULL, 0x9E6D39282819B946ULL
        },
        {
            0xBEB762FBE7FE93EEULL, 0x108004157CF97CF1ULL, 0x102CC6453C3B2207ULL, 0xC26E50F03E32AAEFULL, 
            0xD705D2403C9D3B96ULL, 0xD49144AD9559CEB5ULL, 0x99752565F0B7B3E4ULL, 0xE16B5F2BAB26A563ULL, 
            0xE928A2B8DE9D4269ULL, 0x84B7135870594889ULL, 0x99791D64B855EE0AULL, 0x65283DF2632D5AAFULL, 
            0x427FC2684DB1FDA7ULL, 0xB0C86FAA4A7D3EE5ULL, 0x1B424EDBB0CCCE3CULL, 0xBDA7F4499C6D34A5ULL, 
            0xEA479B0E35687D2CULL, 0x33283FCDE24B1C27ULL, 0x39529E5F1CE02053ULL, 0x8275710007979776ULL, 
            0x23FA4F38352BD29BULL, 0xE08EB729C7DC577BULL, 0x8171B45906FB24C7ULL, 0x82464D19CD07AD17ULL, 
            0xA3EA33D4AF2A648DULL, 0x48B87C512D3CB57EULL, 0xA30B84ACA6E50D13ULL, 0x27B1178495DF7A9DULL, 
            0x4723759A9C76312FULL, 0x36C530B6F0F16003ULL, 0xDE43B02D9C76E8D9ULL, 0x88C5DE343799A755ULL
        },
        {
            0x9E1577A3BD6DD707ULL, 0xDF101785AE8A4502ULL, 0x82CB96FABE43DA4EULL, 0xA571B8C920B27FCEULL, 
            0xF12AEBFBA8BE2EB8ULL, 0xCCA8819F7C15B1ABULL, 0xA8793BFEC9FA72CAULL, 0xECE4BEB8869B32FFULL, 
            0xFF2007D162D42426ULL, 0x6ABFE1CB9AB188CAULL, 0xA49ED9365FA9286EULL, 0x949FE142BF883477ULL, 
            0xD417341691A9BD67ULL, 0x3E8DF2C2067E3CB2ULL, 0x4438DCFC0F0B545BULL, 0x6D9ADB29A595566FULL, 
            0xFCFFE4D52F32532EULL, 0x681A5CAD1023A023ULL, 0xCD6562DFDB25B1A9ULL, 0x7EFB7975DCFFAC02ULL, 
            0x020E8F82639ABF91ULL, 0x22D7E79E88197461ULL, 0xCD11DEBC8C0537F6ULL, 0xE1F24B6E33D81366ULL, 
            0x673D7B17727E90AEULL, 0xBDBDB2CF3D2388EFULL, 0x8F232834A0CEC2F8ULL, 0xC481898E969356BFULL, 
            0xD64C5C885C4AE936ULL, 0x9779AA924BE1AC5EULL, 0x04242ABEAE93AC13ULL, 0x75FE6B3FC21333A3ULL
        }
    },
    {
        {
            0x96DDA1F406CD169FULL, 0x057943D43914C737ULL, 0x0D9E159383C31994ULL, 0x546D1B06DA8F7811ULL, 
            0x566460E6D9A80D0BULL, 0xB7854AD12E643399ULL, 0xF18C8871C40E4790ULL, 0xABAE5D15E1923F38ULL, 
            0x8510325361628606ULL, 0xEA3D8DC681505654ULL, 0x8B61231CB5BFF90CULL, 0xCFA0D4656FCC38BCULL, 
            0x406CF4A2A919F6DFULL, 0x6CE2E3735E7E8AEFULL, 0x9D4874C6F8BA7B1AULL, 0xA1A7C18BE6E32B28ULL, 
            0x55784198DEA95735ULL, 0x666EF803B2EDE257ULL, 0xC0DDB31074FD682DULL, 0x318AE252D34B690FULL, 
            0xBBACCF61509DDC5EULL, 0x4E40DE247F48FA4FULL, 0xFCE73432F4CE79A6ULL, 0x5F23A8F1887BAAA4ULL, 
            0x1FADDB7DFA9254DCULL, 0xE777FDFB5CFB0B1DULL, 0xE26F363E21A1FA6DULL, 0xC02747F882577F10ULL, 
            0x4BB656C54D876104ULL, 0xFBBDB087B79EAFD9ULL, 0x73BF6CCA21897056ULL, 0xDC130936BC0D6EDBULL
        },
        {
            0x0B5174744147A3DDULL, 0x4E5DE82B57D00BE1ULL, 0xCCD765155D98BC04ULL, 0xE050A15C47FD7DE9ULL, 
            0xC81AC74B53D78852ULL, 0x9F2D7654B9DAF58FULL, 0x47930DAF6944BBE6ULL, 0xBEF75A3DFC240549ULL, 
            0x6ABBA662A6418ED1ULL, 0x3194EE00A4AD267CULL, 0x268F477043F83467ULL, 0x5DAFB893E4804D16ULL, 
            0xA248220652D8CE54ULL, 0xF5CAE5F4DFE7FECBULL, 0x9D68F6E244708398ULL, 0xD2CFBF9D904105E2ULL, 
            0xEBB814BBF310BBB6ULL, 0x636953210DD3B5C4ULL, 0x8F36D8DC9F5004C2ULL, 0xF82346B74BD0C583ULL, 
            0xD1C9C42ECCDDC1F2ULL, 0x8C87F6E43262CC92ULL, 0xD9453207C1CB5B9EULL, 0x4504E0FC62B058F6ULL, 
            0x9A6F2E6B55A2D8BDULL, 0x1ADA0D81922E8C2CULL, 0x59DD9CDB79C73E79ULL, 0x46E0CDAA391F2088ULL, 
            0x282C5B74819AD77CULL, 0xC1E7AB8E62ECCA0AULL, 0xE11DE2CC6E7A3685ULL, 0x6A1FCCD2A52AEA6DULL
        },
        {
            0xBDBFC923A3290963ULL, 0x419A853F614FEDF5ULL, 0x477E44FBC87DBC9AULL, 0xBABF51A4D1FC5F38ULL, 
            0xA83FC81773A40882ULL, 0x31DC595D7D1D99E4ULL, 0x26CDD7CEAAE7B2C3ULL, 0xCD695D3D4C70BC51ULL, 
            0x89E8609D2CC56AADULL, 0x2EB4506D8828ACA5ULL, 0x929B49A3A4E35C39ULL, 0x704C65D0BECEB82EULL, 
            0xD53F7AECF1883106ULL, 0x49E807FB81291CBEULL, 0xBE3D2186B23C24ECULL, 0x4B255400A71E19C1ULL, 
            0x15069C2476FFD88BULL, 0x4CEB957A7ED843D2ULL, 0x103A4A333BE2F009ULL, 0xEDA19417EFCF527CULL, 
            0xFB37637DB912E41CULL, 0xD3CF1BDAD22FEB76ULL, 0x2503435AD3B7C101ULL, 0x8B4277AF7C3A20EAULL, 
            0x67AB13F6C0139FCCULL, 0xC7FC85F5D5B51797ULL, 0xEA09F4C181DA220FULL, 0x8B6C8D3E1E8E7AB8ULL, 
            0xA3EE91046BD80E3BULL, 0xC889D4D586009898ULL, 0x87E8A1604E88AF3DULL, 0x8E5585A2DD3CEE3EULL
        },
        {
            0x50EC4EAB105AD466ULL, 0xE2256AAFA6A2CEE4ULL, 0xEBEB706D488E6A05ULL, 0xFC63567B5DB79DC0ULL, 
            0xC1E6B48D70E76AE3ULL, 0x10C44D6EAA50E67DULL, 0x8A698D78622DD7BDULL, 0x68479CF8276C7180ULL, 
            0x6AFB06B8A45527A0ULL, 0x4FAA679579266CDDULL, 0x1F9DF4708D53198FULL, 0xF182CA07EA65393FULL, 
            0x307E73EEC02BAA72ULL, 0xB21E6EDC650C4783ULL, 0x351971028A4C8896ULL, 0x20CA5AA4ECE48F67ULL, 
            0x98E6524F2D556430ULL, 0x869971364EE5A402ULL, 0x6FBBEFD5567E081BULL, 0x42B81976E477741FULL, 
            0x2A765E05C2B60B75ULL, 0x0B73874C10E87A64ULL, 0x298A881A025D680EULL, 0xAD10507AC7E05C16ULL, 
            0xF0EE1DF83E5AEFEFULL, 0xA0435CDAD398F51FULL, 0x34432F283E6D7564ULL, 0xA3EEA12C440A9AADULL, 
            0x8392392447D4B7F3ULL, 0x576620358D62B58DULL, 0x9A1565A1ACFEEE4DULL, 0x48D0EAA22E40EA9BULL
        },
        {
            0x2E512E07838C5D95ULL, 0x5996E7E5D52AD852ULL, 0x8CEEED884334EB98ULL, 0x12F95414F6B1B5B8ULL, 
            0xE675A2E3897D9E3AULL, 0x2AF6535BEB920875ULL, 0x034A3336A15068BEULL, 0x94322E6FCF4B1709ULL, 
            0xD74C4EF048FC7F7EULL, 0x7EC279D314585876ULL, 0x1C04D1D4067880CBULL, 0xD1C23C95EE3042A4ULL, 
            0xA4FE0EFAEBD17F8AULL, 0x2E47E1EA6B98BDA3ULL, 0x6F2A860D17993BF8ULL, 0xF3F39EFA4BD339D5ULL, 
            0xA3CC96E058569323ULL, 0x55D56B37507B0047ULL, 0x7A5569CFDB3F1A35ULL, 0x15D3141B65EEAD92ULL, 
            0x0E0BCE4330B475B6ULL, 0x88709670C6D253FAULL, 0xCFD31A776AA941A1ULL, 0x75F806C5039B1269ULL, 
            0x27B587303A8B29DDULL, 0x7FAD9617163D7B0BULL, 0x7B22FA5DFE4EA7A6ULL, 0x74AE2EAB14E5B045ULL, 
            0x3FCE49D6E8AFF6AAULL, 0x5813FC923FBD80BAULL, 0xF2166677B9B08466ULL, 0x854668BB6B909D75ULL
        },
        {
            0x8E93F820AE4E396EULL, 0x24A0FD08A9D6A08BULL, 0x5DED11009CC7D9E2ULL, 0x76461A7D48593506ULL, 
            0xB718256AA463E645ULL, 0xC3A2E8004806ADC3ULL, 0x2AC896F2EEBD04A5ULL, 0xDB642490C6CD4C6AULL, 
            0xFDEBCC1FF35406C7ULL, 0x83CC31CB635A5E3BULL, 0x59331E24BAEF80C6ULL, 0x08469534040A7433ULL, 
            0x61FD093AA7C2CA90ULL, 0x56B8C79F8690742DULL, 0xFFF2FFE95CC08AA8ULL, 0x76EAE13C9FCDFF65ULL, 
            0x7F5AF2A921568BB2ULL, 0x2CAD08AC37E941FAULL, 0x28209824FE14A65EULL, 0x1330E2E568B041CFULL, 
            0xA3632D47BFCE5A9CULL, 0x9CA826383F935E4AULL, 0x5864E05499B9CBBFULL, 0xD72159F170B5AFBDULL, 
            0xFF4304FF8FB11C51ULL, 0xE2D1A63EE38BE2C8ULL, 0xEA72D2C18617DF2CULL, 0x8BB610BB0515E9C7ULL, 
            0xEF4710FD1F3864B1ULL, 0x47D8600F9025F76CULL, 0xE4ECB0BEC879AA11ULL, 0xE7027F6E7FFA4DD1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeyRotateAConstants = {
    0xBC097F47637E0D4FULL,
    0xA81D5F5267FC11C6ULL,
    0x5AF75A20EEA03243ULL,
    0xBC097F47637E0D4FULL,
    0xA81D5F5267FC11C6ULL,
    0x5AF75A20EEA03243ULL,
    0x49D7CE485EAEBC6BULL,
    0x278FAE7D4D821F93ULL,
    0xC1,
    0xCB,
    0x9B,
    0xB4,
    0x34,
    0x0D,
    0x8A,
    0xC2
};

const TwistDomainSaltSet TwistExpander_Pollux::kKeyRotateBSalts = {
    {
        {
            0xF1E066F965404C07ULL, 0xED1099869274B515ULL, 0x1CF5017DC9C0FAACULL, 0x3330D5A94D40600FULL, 
            0x49E8983A2798B02DULL, 0x05613F74B43253C2ULL, 0xCC8BBCDFEB444768ULL, 0x56586829806E66D1ULL, 
            0x3BE3B9A485EC1D1EULL, 0xBC6A59B28ED57A46ULL, 0xC21A84EC238BEE28ULL, 0x656DD2928BF7C63AULL, 
            0x02366C2E4E88A307ULL, 0x80A18EEB06F1446EULL, 0x1AB16D06140F9E1FULL, 0x37F435EAE586A0F7ULL, 
            0x192F1C83EF2C1225ULL, 0x1D4DCD36CA349280ULL, 0xFC218262D3CB1544ULL, 0x4D33399A5653119FULL, 
            0x2D097E2CE7F3A690ULL, 0x5899C6014E1B3995ULL, 0x6E3EE2929D4CA92BULL, 0xCDA2260E494CCE6FULL, 
            0xE144E464AA53947DULL, 0x29E1FEE9B149A5CAULL, 0xA44886ED3A5E4394ULL, 0x757F3466B743CE03ULL, 
            0x4C02A01B418FE1CEULL, 0x8734E088DFE69434ULL, 0x593E65813DA4F1F9ULL, 0x3C25DEAD103F9CD8ULL
        },
        {
            0x36B228ADFDDEE5ACULL, 0x795671A40CACADA6ULL, 0xC0CF2129EF81CF03ULL, 0x7A31E7B89462AC6DULL, 
            0xF830A7FF10E4FBA6ULL, 0xDF7B6924AAE8C45EULL, 0xC4BCC636086E9894ULL, 0x5EAEEE81273FD2D0ULL, 
            0x60DB88D4590657D0ULL, 0xB6AD9BCE1DBB2E80ULL, 0x980D32D1256FACB5ULL, 0xD7FF5E28B84FCBB5ULL, 
            0x61ABB0D3FE32506FULL, 0xB0B987E87DA9D91AULL, 0x383ECCDDA0CD3B80ULL, 0x5809F06C9BF6FB52ULL, 
            0x4802DA1B8A59315CULL, 0x285857E5ACAE1676ULL, 0xA6E019CCE93B3B76ULL, 0xE0F6F969F33D0206ULL, 
            0x248D5A858015CA79ULL, 0x32EFECF5BECBC334ULL, 0x84107414FD9EA3FFULL, 0x2165B11F1E88318BULL, 
            0x3E9F40BF35D06B12ULL, 0xC3B77F8384E3431BULL, 0x62F13DF9A9EFEB96ULL, 0x7914E5A05B321703ULL, 
            0x6B595ECF2A6C64B2ULL, 0x9EA5B06E9965724BULL, 0x3C2B75887593FC9BULL, 0x78A7B862A9B2A156ULL
        },
        {
            0x1E9969D68692EA75ULL, 0x006387FF725EED05ULL, 0xAC4BBAE7DA08D902ULL, 0x02E7FB14DEFAFF0CULL, 
            0x069D249E947380B7ULL, 0xA6FF704782A02ABFULL, 0x7B59A5D2CD3B32C6ULL, 0x15343049C1A3325CULL, 
            0x3A43F7F09A22429DULL, 0xCA72F778F2A4D2EFULL, 0xF75F57C2B59DFEB8ULL, 0xB40875EF86622F4AULL, 
            0x57C8AD0874BC3AD8ULL, 0x52CE706AB586FB48ULL, 0x9E3E4C4A398F70BEULL, 0xEF93201761A8F541ULL, 
            0x1AC422AA501A13F9ULL, 0xE30FC2BBC0E1B6BAULL, 0x341855F0123C31E0ULL, 0xED8124BECB5C9D64ULL, 
            0x6EBBC152D859D9ADULL, 0x1ABAFE823FA3F5A5ULL, 0x4770BF48397510AAULL, 0x62DE9092A38E8E57ULL, 
            0x15089697450CA1C9ULL, 0x1BDA50864B4C3D20ULL, 0xE05CAB56635A83EBULL, 0x090B56BEA1957C91ULL, 
            0x0FD129ACEA71B0CEULL, 0xD6C1A1A5A0AC6DDEULL, 0x371A06A2C9771D81ULL, 0x980048CA533683E7ULL
        },
        {
            0xB29F280DA1179433ULL, 0x5E42881DD5262334ULL, 0x92B9717277993714ULL, 0x380D4B6905F4D9EFULL, 
            0x6B03A7D9BACA912AULL, 0x5A9F8013CF051BFCULL, 0x3E3BFB9782FF86B8ULL, 0xC009EB0CBCD92477ULL, 
            0x9AA31D594CEA7261ULL, 0x43251481F7217041ULL, 0xB0EFF9688F6859AEULL, 0xA051729AFFDE342BULL, 
            0x83AC144C666E195BULL, 0xE3632DD33EC0FBDCULL, 0x4B72050421B53E1EULL, 0x5DA55B339A3F08E8ULL, 
            0x70071793C806E781ULL, 0xC4D180902A7B1E52ULL, 0xF5794A1D40226984ULL, 0x87C0FC09B856AA4BULL, 
            0x2C780AF459C003F1ULL, 0x14C647C1F28AD60BULL, 0x8242EE0D3EF5ECF7ULL, 0x5AC91756F9D60815ULL, 
            0x4EFE3589B2E6342EULL, 0xA7F4603366DEF1A2ULL, 0xB45BC71C0CB10126ULL, 0x2B8275D95D49BD33ULL, 
            0x37DDC1AB86B6D467ULL, 0xD32BF2ABA8C8C8A6ULL, 0xFCF92379BC6DE90EULL, 0xA929F5D80F7906D5ULL
        },
        {
            0x5DBA62DC7696C801ULL, 0x77C3C94362938846ULL, 0x4BB30A288350BCA0ULL, 0xA407421EC7070470ULL, 
            0x919B3FAF4615B34FULL, 0x4D87BA4E6213A0F8ULL, 0xB9C99AEA3FDF6317ULL, 0x86762F9BFCA735D5ULL, 
            0x93C1730913C04C78ULL, 0x1722E54013F90C89ULL, 0x49879C0121C93CFFULL, 0xE594644C8ABAEF98ULL, 
            0xACFCC3890787E246ULL, 0xCDFF5D2DB32986DAULL, 0x32219FBF1F08C554ULL, 0x5A9E722CDAD69826ULL, 
            0xA389F8AA5042E812ULL, 0xB105088C2397D05EULL, 0xD2D82924617D6487ULL, 0xDB22CA88CDF45175ULL, 
            0x3FC1534A44B9AD13ULL, 0x8654ADD71631A644ULL, 0xA8785A5ED1A3FB79ULL, 0x60146B61DA604BBCULL, 
            0x03CCBCF8B615B0A4ULL, 0x20093ABF5EA1E1A1ULL, 0x2401E0C206EF5971ULL, 0x98B8280969E0FB45ULL, 
            0x6F648CCB48EFDDE0ULL, 0xF31DA8B238A5368BULL, 0xF2222416A5A0731CULL, 0x7FC9646C2C7D6491ULL
        },
        {
            0x9C583047EF511AD3ULL, 0xFA0DF5761E861ECBULL, 0xE1DA4CE7C41C96E6ULL, 0x890341D5C2D5DF66ULL, 
            0xCF5ADA7FB5FD26F6ULL, 0xD578CD1B345D432CULL, 0xCAF3A7D1F9D98E66ULL, 0x51EDDBCDD1C87C37ULL, 
            0x6ADDEE5FDC8D4A00ULL, 0xECD6A1BCB29595F4ULL, 0x57A555061118B519ULL, 0x510C24861EE4784FULL, 
            0x1640A119E48FAD4DULL, 0xE52D10DED4CC000EULL, 0x761535F3241944DBULL, 0x43EEB2C6CC17F8CAULL, 
            0x4A4F5B77285562FCULL, 0x752C90AD97314FE1ULL, 0x21223469EBBB2C2AULL, 0x42FAF5AE426D4AF6ULL, 
            0x33D3A69A0344B4ECULL, 0xCA4A890452FAF437ULL, 0xE857B5233981314FULL, 0xE7C6AF10ADFBF6ACULL, 
            0xCBCDD1C323CDB03AULL, 0x543A87A0A26AECD7ULL, 0x72808C2B2EE41BD6ULL, 0x1234C6855C9D1B17ULL, 
            0xB82EFAF260CB738DULL, 0xB7A148319A90D81CULL, 0xBBEBC0B26B8FCF59ULL, 0x0BDC07D7074C259AULL
        }
    },
    {
        {
            0xE2F1004E225AFB7FULL, 0xD17A7B58B38D57D8ULL, 0x5C01D3B8FD83C1A6ULL, 0x295B332B1D0C87FBULL, 
            0xB4D346E472635DD5ULL, 0xB4F85A19BA22B216ULL, 0x0D2A1925BAB0A949ULL, 0x7EEFFDBE5916816CULL, 
            0xB52B8DE52D2BF8B3ULL, 0x69643A588E99467EULL, 0x5AABE701D0CDA857ULL, 0xCBDEC68F5D976589ULL, 
            0xF9CBEB12F826D0E4ULL, 0xD02704AF1535A91BULL, 0x608A9C073D7C8746ULL, 0x140F649A932E72B7ULL, 
            0x2664B50C114C0DB5ULL, 0xBC094B2BA8C5D00DULL, 0x5B3A69977CB859AEULL, 0x24D8BC87CE8811CCULL, 
            0xAA742617AEC3A498ULL, 0x37BDFE3E4B1996C7ULL, 0x1179C5B38F03F5C4ULL, 0x0E6C3DA2641C1355ULL, 
            0x40CA25AA5D5F1B5BULL, 0xB590F4AFB698C6C8ULL, 0xC1E5409760FBB6B9ULL, 0xF641944663F29DFCULL, 
            0xE3DC6AF1DD61F2F1ULL, 0x064689558F075979ULL, 0x3126980C040CD6DEULL, 0x1E50332A7FC2BB67ULL
        },
        {
            0xD08559A98113808EULL, 0x34734A4DFF9F6D48ULL, 0x8073B46AB97ACBDEULL, 0x7554BE00E7658E94ULL, 
            0xB3034E9F8E64E4F5ULL, 0x211FA2D38A1715C0ULL, 0xEE50EC40304F4A4FULL, 0x064D130A4011EF49ULL, 
            0x5DBE3000522D7017ULL, 0x6137D399BC7CFF3CULL, 0xEB300E74C7694431ULL, 0xE408C5984E52580CULL, 
            0x1CA9D1D0CE1B98E1ULL, 0xE62F5FF8740E152AULL, 0xA3CAB9AA36EC435AULL, 0x1CB58D4278DD8FBBULL, 
            0x83E168F7E4149699ULL, 0xF796DD6841B5742BULL, 0xCD9F707B13E5D393ULL, 0xA54A1253CA7827ADULL, 
            0x114036CE271FA45FULL, 0x59A0EA8FB2E937ECULL, 0x019463B8A43A2BF6ULL, 0x8562C2009D960278ULL, 
            0x32636B37AC743EE6ULL, 0xCD9DAE6937317A98ULL, 0x04E222ED36027FDAULL, 0xF2312FF4BAE2F98BULL, 
            0xBB9697D7100C309EULL, 0x8FA6F99EF09C8B66ULL, 0xB8775F3E96D126F7ULL, 0x1C34DF3E86A787F0ULL
        },
        {
            0x22EAB079944D6F84ULL, 0xB8A1BD819E51AC93ULL, 0x8ECA82A03FEC1722ULL, 0x57529E7A138DECF7ULL, 
            0x32CD95336CBFC839ULL, 0xB92F46AD94F56A9AULL, 0x54B2A9FC7D41AB78ULL, 0x18B8CEDF3DA69019ULL, 
            0xEAF7813863D6E37DULL, 0xEA020530F9FDE833ULL, 0x3DE56BE18DFD534BULL, 0x3A3CE21BE4E35F3AULL, 
            0x0BBDD91008BEBA8EULL, 0x46AEBB5A77BB1321ULL, 0xCFFB8F72C1F5BDB5ULL, 0x2BC36EE98759F309ULL, 
            0x701289BE4A84F009ULL, 0x836CB6A3685B4AEEULL, 0x70945B64FDE2D786ULL, 0x32304B76D91CDB35ULL, 
            0x6FFCE443FFF55883ULL, 0xE6690832F470BB33ULL, 0x6C691D776B39258DULL, 0x5E6F630444BC4FAEULL, 
            0xCF279CF7324441C9ULL, 0x07F6C03FCC2B213AULL, 0x5ADBFC4C450F1CACULL, 0x548803A1DBA08910ULL, 
            0x1CBFAF83C308C795ULL, 0xB31E0886A2A4FA0EULL, 0xE30728A8EAD14C3BULL, 0x9152B693B01678AAULL
        },
        {
            0xD67A1BAC0FAD977BULL, 0xB3EF39524A996B04ULL, 0x5A519511AFF24752ULL, 0x35D7A97601ECAE90ULL, 
            0x6750F61FBD2FC1F5ULL, 0xB11E9F67EE3DC5EAULL, 0xC1EDEACD4ADAF3BFULL, 0xF3B89CF7CDA99A2FULL, 
            0xE3D4F7EF5F7307EEULL, 0x04F95984396F7C1EULL, 0x5A150F054DFA6364ULL, 0xA26E542FF709B258ULL, 
            0x1B581274D8234E87ULL, 0x6DA0C6E23887158AULL, 0x4B084A5EF52B4BA8ULL, 0x2EF7C813ED3CDE7BULL, 
            0x1991765489EA1836ULL, 0x93F629D5F5A9B093ULL, 0x9B21EA912EF74459ULL, 0x8DD0EF38BC57146BULL, 
            0xCDC4B8EC38DF0847ULL, 0x163E28C15D349F88ULL, 0x0697515CF3E959C2ULL, 0x797BB08719845717ULL, 
            0x7B642FD9B7CCD834ULL, 0xF7536EB4523537F1ULL, 0x31CEA1F6CE939069ULL, 0x6B266AF07BF6591FULL, 
            0xA0818D100ABF00A8ULL, 0x7550FD4349B87F0CULL, 0xCC12DDDF50C8E1B6ULL, 0xB3BFF661EEE2AF6EULL
        },
        {
            0x00C1CB46797E566AULL, 0xEDD00653FBE86F3CULL, 0xC8B016713E941AA7ULL, 0x7CAAD48E590683D7ULL, 
            0xBA19F724D92523FAULL, 0x14050F3DF17C31E0ULL, 0x310008FF0D36FD9BULL, 0x23E06E1D591BDBD6ULL, 
            0xB9A8D6D2463C74F7ULL, 0x310AB3ED431A3C2CULL, 0x035B6C4EDB696F35ULL, 0xA4CF0E066A4EF878ULL, 
            0x0D83D75692973096ULL, 0xE34437A54332923DULL, 0x1823509F51E800ECULL, 0x6BF483F52C020D3BULL, 
            0x424B4971CED4A64BULL, 0xB7D03AA037530A66ULL, 0x5BA5160ED36A138FULL, 0xD5D6A746A607BC88ULL, 
            0x48BFF2DB44004BECULL, 0x5227360DEACD7661ULL, 0x6B4BF4294DD84B9CULL, 0x48724794101FB571ULL, 
            0x1AAE420CAF6463CFULL, 0xA5424E6749B17260ULL, 0x8C481B50BB78132EULL, 0x7476CAF88C5EB048ULL, 
            0xD6DFBB122F2BF3A1ULL, 0xA9981A2A095A9695ULL, 0xD729E1A2649CEEA6ULL, 0x9BD633D6F7BB29C8ULL
        },
        {
            0x1AF7EC23176C8ADBULL, 0x182E7A45F132CFC7ULL, 0xD254F7FFE04CF90AULL, 0x877D6EACB7ED5D8AULL, 
            0xEF9F0642BDEB0652ULL, 0xFB9BABD085D2C228ULL, 0x1570F1B085972FCFULL, 0x01F2CA76CE6D5510ULL, 
            0xB361EB7ABB1729C0ULL, 0xBF51DD663C7FADFDULL, 0x990C4C25D9C16958ULL, 0x90C73C8CCF38B653ULL, 
            0x48B33C30ECF79FD9ULL, 0x544CDF11642AFD70ULL, 0x978F3A8A890174D8ULL, 0xC079BDD2F90B905BULL, 
            0xC20865B8E535CC94ULL, 0x09FC1EE1004C404FULL, 0xF147AF9618B94839ULL, 0xD47154128035B0C9ULL, 
            0x27811A8D619C99D0ULL, 0x5AB548D0F8843C7AULL, 0xEA9484E43C4EC4C3ULL, 0xDFECBBA3B6DA57E7ULL, 
            0x07BEC0E453A6DC0AULL, 0x9BEE45CBD0A59436ULL, 0x9CF10AF64E142474ULL, 0x0903224FBD533FDBULL, 
            0xB5C861DDFECF77C8ULL, 0x5969907090930CF1ULL, 0x2D771F74FBA2CE7BULL, 0x15A0A8880852FFD5ULL
        }
    },
    {
        {
            0x69E0E258A7059D3EULL, 0x995C18EA2C750B87ULL, 0xECB5EB5D8A13C898ULL, 0x2F4851E9EE472B2CULL, 
            0x7B3B2DA97045AB43ULL, 0x6388D9F413811E1DULL, 0xD326ADEF9492E9CAULL, 0x6C0175A9B629EF84ULL, 
            0x0D87AE63C6865D95ULL, 0xE7DBCE2683A7A315ULL, 0x29016FAADB632F6BULL, 0x70114529AE5CECFEULL, 
            0x9E95BE0D2CE85627ULL, 0xA42C472E98542061ULL, 0x0ADD363FF359F6A0ULL, 0x4B9F75693ED95AC2ULL, 
            0x8740924C671472D2ULL, 0x16B18C496D5C33CBULL, 0xB8D065197BD81C5BULL, 0xD02C2DCB4ADBCFF8ULL, 
            0xEAEBD21C3644208AULL, 0xCD0F207DE2E937F5ULL, 0xEA0FC3BB1B56670AULL, 0x5C2447B0BA0AA3FAULL, 
            0x9F8499E2984B0909ULL, 0xFF8DBC83AC89FD15ULL, 0xA8F079087580404EULL, 0xFB13B9BCA16D3508ULL, 
            0xB10F9E20ADBCAE56ULL, 0x0E8F46DFC8F68231ULL, 0x6C7C7D1A1BD9D0F1ULL, 0x0A72B9C709322AA4ULL
        },
        {
            0x5CE1146396EA801CULL, 0x8405F83320CAE93AULL, 0xA797BABD48DB0F78ULL, 0x8FDF2C80409E9A0EULL, 
            0x436E616391DF51A6ULL, 0x7BD7A99661DE3F70ULL, 0xE9661376D246E5D3ULL, 0x8B3FA31AAAD730F3ULL, 
            0xFBFC9B0AB9F3ED75ULL, 0xAF129A66C7BE4866ULL, 0xD7B8AE01303C2566ULL, 0x3A356DB88C8DE8DCULL, 
            0x07DA708CF3AED57AULL, 0xF739440924A52ADDULL, 0xEAE5DE0634281B99ULL, 0x2454767E7BAD6F15ULL, 
            0x3CB0187A3C8EE30BULL, 0x06B3F0EC75BCDED8ULL, 0x46F35859CCAE5D29ULL, 0x745173B615968AC8ULL, 
            0x3C9F0F1A706AAE8BULL, 0x6242B6B8F0D88E64ULL, 0xB8C7E6C2FC95F8BBULL, 0x8BFC2FBE7F52B2C3ULL, 
            0xE615A11BC341C661ULL, 0xDBB1D4AAFCEBDC60ULL, 0x2EA28325AB7C9F6EULL, 0xEAB7F2269BDD2C54ULL, 
            0x58B20DE989F510DFULL, 0xD9E98A7C714FFB98ULL, 0x5C7E0706057227E3ULL, 0x4AC0742BF2127128ULL
        },
        {
            0x6DDA5385A18D6D38ULL, 0xC90C0A328AF487E2ULL, 0xA639AB5E73736AB4ULL, 0x120D4AFEF6939F8AULL, 
            0x102BE5907805D7B0ULL, 0x44D6CE5F97711C5CULL, 0x9A5891099275B5AEULL, 0x84A61B4FEB2F7BC0ULL, 
            0x0B0329BB437916BAULL, 0xAB6D4128ED9F0A84ULL, 0xC030A59A3BF263F3ULL, 0xED2EF6229F715ED8ULL, 
            0x14FF0198408D60B2ULL, 0x57EF85EB1517420FULL, 0xC4AD677F06B7589AULL, 0xE9615979BDA81A69ULL, 
            0x64F7C62F9861F63AULL, 0x54E29E7882E5332CULL, 0x52FB77AEC68E076BULL, 0xEDD02520640F2730ULL, 
            0xE39E86FC287DDCB2ULL, 0x57E400759C8CC75DULL, 0x22B8C4A0A4A42115ULL, 0x2BF6924C7498A477ULL, 
            0xBFD0B05FF4123040ULL, 0xAF77C9FBA902BEC8ULL, 0x0E57B9B112BD1A08ULL, 0xD090E13E33396EAFULL, 
            0x7737E19A46D2F2ADULL, 0xAB2537D534C18C0FULL, 0x60544EF681094143ULL, 0xE8724CF22E92A6B3ULL
        },
        {
            0xC04B2FAEA818C8B5ULL, 0xEC79A4BCA89C4B2FULL, 0x081A77C7B6BDBF7EULL, 0x225611CC3D1B812CULL, 
            0xA2014C19490F77E0ULL, 0x3DDFC26BE9A51139ULL, 0xF4CC259F5826B8B2ULL, 0x4E740B95BC3097F4ULL, 
            0x3CD2B05E08B10ABFULL, 0xE56ECD7E908E4FA9ULL, 0x8C148F80ACF97404ULL, 0xDB831542FE394A6BULL, 
            0xF5B135AAB64DFD95ULL, 0xB4CE78157BA63BA7ULL, 0x6F010BF14949EB9CULL, 0xBEF2FD42E5D9CED8ULL, 
            0xAE640A0AC38A022BULL, 0x3D91F322727FE6C8ULL, 0x8CF6FFCF0BC1B7EAULL, 0x5F110653D0219304ULL, 
            0x8A0B080ABC8653A5ULL, 0xF39DCB00D57F9CF0ULL, 0xF558EDFCDA8300A3ULL, 0xA3EEF17AF6D410CEULL, 
            0x8C0C4099CEB81B66ULL, 0x351371E68941AE92ULL, 0x13850D1073D4A16CULL, 0x858F60AF588A7570ULL, 
            0xD7335D1A432C1EBBULL, 0x153A74DD31B2E9ACULL, 0x7D6993A8A1F828EEULL, 0x340A1666DBDD5790ULL
        },
        {
            0xF63F7D9060C57B48ULL, 0xB2142788CC0FBA02ULL, 0x9C4EA55F03C675A8ULL, 0x5FF73CFDEEB6BFEDULL, 
            0x2816B50FEEC39ED6ULL, 0x92F60EA66A816E1EULL, 0x29AB1150B18B051AULL, 0x04DF6A1C9FA9FEF4ULL, 
            0xDD0AEF11342C07D9ULL, 0x1B5395FE50B09DA5ULL, 0x088C2FBB09BCB672ULL, 0xF70E7B5CCF29B0B2ULL, 
            0x3605E0A994F5CEA2ULL, 0xB307C4044406BF66ULL, 0x71FB149F196A0501ULL, 0x7BF579212D2A4C57ULL, 
            0x8A670288120940FCULL, 0x6EDEEBE67E6763DBULL, 0x5E03804BD5582199ULL, 0xDD07B6C795D03A41ULL, 
            0x0B7E76D8753EFC0BULL, 0x2C3E38B3ABBCE3CDULL, 0x3C5FA7E39E59722AULL, 0xECE8D332BEC6E853ULL, 
            0x3EE7D251C2F0254FULL, 0xA64BCECAB9BCB965ULL, 0x915080686CDACEC8ULL, 0xD55FA7D459C64584ULL, 
            0x91E8505A371AEE16ULL, 0xC159DA0E3902364EULL, 0xA4271F4D82C8E276ULL, 0xA741F55E0618C722ULL
        },
        {
            0x3A288718536F92F1ULL, 0x28089C70ADDDDEC2ULL, 0xE8D37E96D6DD6556ULL, 0x21E0A98EC6F8D91AULL, 
            0x588543B3D3577754ULL, 0xAAB9E99CFDBA78D5ULL, 0x80C26FB6353A5C3DULL, 0x97FCE9B6B2AB9BE2ULL, 
            0x9AF1A4D146AAF12BULL, 0xA1881502848BD72FULL, 0xF5C1A2432E437062ULL, 0x159355E2A5EE0ABDULL, 
            0xA4DCD05C19C082A5ULL, 0x19E0E90900487E27ULL, 0xBA6B93D861E0F0C5ULL, 0x14669D6CF7AC4EDEULL, 
            0xC33621F07F980BCEULL, 0xB28C7D47D43B53F6ULL, 0x755C78163C993812ULL, 0xDCBF7324BF330939ULL, 
            0x42702F229A53C6E7ULL, 0xB27555D98A8AF3F4ULL, 0x6A126D09B845AE13ULL, 0x7C31D127D6D7974AULL, 
            0x794B3E0F27C26B48ULL, 0xFBE9DA4CC85FE7C9ULL, 0xA0E8F21BCA6B01E4ULL, 0xCC2A1F5AF5009DEBULL, 
            0x1A2550B84110E810ULL, 0x43A6A9ADE6418C20ULL, 0xE41017002EFF5711ULL, 0xE4157C0227CD2642ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeyRotateBConstants = {
    0xABC7B62F425A12F6ULL,
    0x1A930FDF17EA5555ULL,
    0x421DCC574CCBB6E4ULL,
    0xABC7B62F425A12F6ULL,
    0x1A930FDF17EA5555ULL,
    0x421DCC574CCBB6E4ULL,
    0xB0581EEC232B212FULL,
    0xAC22D3C2410B3955ULL,
    0x6A,
    0x1A,
    0xEF,
    0x33,
    0x09,
    0x15,
    0x54,
    0xC3
};

const TwistDomainSaltSet TwistExpander_Pollux::kKeySpawnASalts = {
    {
        {
            0xB45B19FA956DF4D3ULL, 0xC7DBC10933F48BD0ULL, 0x7D9A2226F1081AF2ULL, 0xAAF09D5FFFF28CC1ULL, 
            0x4568A6BCE501A058ULL, 0x82DB7F8D52186B86ULL, 0x7074A2DCE2BFC060ULL, 0xC36E047AA7E8CCC8ULL, 
            0x44166CBFC5FBBB32ULL, 0x53C093C03B94556FULL, 0xFF4A34666E3CC5C2ULL, 0xD6CC855AB040566AULL, 
            0xA03666CDEAECAB1FULL, 0xC2C96E078965FE03ULL, 0xC16F28B1A9E46AE5ULL, 0xC59CCCC31C009229ULL, 
            0xA9E0619E9321812AULL, 0xA817DB3C1D544915ULL, 0x17BED3780EF0E918ULL, 0xF462ECA12C8E7721ULL, 
            0xBECC22C827CA4EFEULL, 0x0A8EDDB3FF8CB0C2ULL, 0x0D2B9C143218B996ULL, 0xF73558AA32AFF3DAULL, 
            0x3EEE5DD00B30E08DULL, 0x0AB0E61F12171F5CULL, 0x47E63A6843CBB75EULL, 0xFF1D7A9272CAFDE3ULL, 
            0x6AEF5CF4CE2FB0C9ULL, 0x1971F6357FCF60A3ULL, 0xA975B35F4293CBEEULL, 0x1A478DA4AA5E238EULL
        },
        {
            0x067826B265A643A2ULL, 0xC9C4E8762FE074A0ULL, 0xE7E43456FC5C43DDULL, 0x436D2CFFAE4A4FD3ULL, 
            0xC65D058DBE632D93ULL, 0x5267C5F7F5D7086CULL, 0x65D95468828B5161ULL, 0x2FC711D13F147A36ULL, 
            0xB2E43D083373C9D6ULL, 0x8CBEEF9165D0FD7BULL, 0x5D9CC798F15CB95AULL, 0x1E5F9327963EEAD6ULL, 
            0x36CEF5580F794D96ULL, 0x27C228603608445AULL, 0xBF8CBDB587B228E6ULL, 0xA1485E09074116F3ULL, 
            0x2207B91959726A70ULL, 0x4A00528A6E976EFCULL, 0xF3CB65542230945BULL, 0x22F8FD933DA43BF9ULL, 
            0x86D41C2DC82E36D5ULL, 0x702F0F0FCCB124F8ULL, 0xE8CC205DD05CA2FAULL, 0x7A4E37F1C6D0A18FULL, 
            0x28B8DE642975CD94ULL, 0xEAFBC9B1B9D44C87ULL, 0xB240526A92135C6BULL, 0xBA080F165CDA366EULL, 
            0x267CCE28CC7378FAULL, 0x39F4B21E5D8F7F39ULL, 0x3457400AB2A87852ULL, 0x4D1C30C66430F3FDULL
        },
        {
            0x962A4964DF967657ULL, 0xA5A58AEEF70890DBULL, 0xB2495B4E6EC89130ULL, 0x7878A10B8073B447ULL, 
            0xE02D161B9712C35AULL, 0x6B163E2E319E7974ULL, 0xA40DE5B22092B304ULL, 0xC7D5A3126A81F6E2ULL, 
            0x4DD01974D966AB28ULL, 0xAA02468B1E941E87ULL, 0x03CBDAB7240E13BAULL, 0x63E5D2111B916294ULL, 
            0x751A9DF38F8CF883ULL, 0x6643533503C199BDULL, 0xE5FBA4C01C65FB18ULL, 0x8E9C0A70E63283DDULL, 
            0x25D9EB6A08034CDCULL, 0x1033358BCE9BD594ULL, 0xB15BAD1B1554C818ULL, 0x5FBA813261AD6F63ULL, 
            0x2251A2EB494E4E82ULL, 0xFCA1374249B5CC31ULL, 0xAC3101C156E9AAD9ULL, 0x08B78AAA9EDCD959ULL, 
            0xE12053CE578DD310ULL, 0xFA6970A1EFDFC85AULL, 0x655AF1D67C9542B1ULL, 0x0619DE89E0C93FA8ULL, 
            0xE95DE77FCE5BADD7ULL, 0xD6809A13B446A0FFULL, 0x75A8AB5075BD3305ULL, 0x6400967A1784B3F3ULL
        },
        {
            0xF71147341F914529ULL, 0xDB57E761F8276D3FULL, 0xED719D947B6D95ADULL, 0x60F77C662F41DBE3ULL, 
            0x825A746E34789917ULL, 0x6ACBC1FD6F4CC740ULL, 0xE8A3671494741429ULL, 0x0CBFE8D0AE3AE66FULL, 
            0x1D0FF1993F6A38A4ULL, 0x32D86C40AC5B5E35ULL, 0x3201002F458804A3ULL, 0x064CD3A7AD8CD18DULL, 
            0xA3786EBE615A30FDULL, 0x4E53F6F2E702F608ULL, 0xA18F160E3168B501ULL, 0x4336364C51C430B5ULL, 
            0x1B9B60F065971875ULL, 0xFBC0A11704CD9109ULL, 0xFAB6917804187584ULL, 0x6DF8147BF1936BDFULL, 
            0x20B364D41C0A10ADULL, 0x117CA8A1DE19E483ULL, 0x51A4BE4D040D4C83ULL, 0xF5D2B260A6964D4AULL, 
            0x79DA563DB5433685ULL, 0x0A942EDCDC64A3AFULL, 0xB9E82918F2A02C9FULL, 0x3257DB8D37116782ULL, 
            0xA71461F804CB12FCULL, 0x1C0BC9A16F5F17F2ULL, 0x91636FA6D98F8EA1ULL, 0xAA11DC4DB54EC8CAULL
        },
        {
            0x67D49B15F99FEC34ULL, 0x839728BBFFF2FD62ULL, 0xEE31CF76B80B0206ULL, 0xB3FF6CF139F8297BULL, 
            0x84BEEEF0148A2C1EULL, 0x88B0B152C086C844ULL, 0x3FE44C4A9395E51CULL, 0xB3B5C1F1FB2720BEULL, 
            0x7D55BB971837C710ULL, 0x4E7B7677A78660E7ULL, 0xEBFF764760A6B313ULL, 0x769A4D9F781FFA5FULL, 
            0xE433558A91670040ULL, 0x4A1031336CAF0456ULL, 0x4C706D4DC7EB4398ULL, 0xE32D0D4CA4C5B16FULL, 
            0x913A4370E1D26512ULL, 0x71ECB2924FD1F35AULL, 0xA7BC8F57207CF1C7ULL, 0xDB3C78C5CA3F908BULL, 
            0x0C6668F33F62B2F8ULL, 0xCA951E6409931514ULL, 0x50DCC5F722027A5CULL, 0x486B2818C3C2F05EULL, 
            0x34531977EC086C82ULL, 0x316F0BC64E03D2FEULL, 0xA98F3FC987BD7ECDULL, 0xA44F85E0BCA76A42ULL, 
            0x2A26ED6B38E428F1ULL, 0x6BCA442F04FFE503ULL, 0x53C1C323B8404A0AULL, 0x68427A27D8990F05ULL
        },
        {
            0x9F97AE14A506EB1FULL, 0xCCF72E8A237BF5BBULL, 0x05CA22014D2BBBF6ULL, 0xC48A30BFBD5D2A3DULL, 
            0xF1A908973DAF82ADULL, 0x21BCCECEACB2D987ULL, 0x5488F74D96354D06ULL, 0x9FF3F05F8DD59A65ULL, 
            0x18F8CFA597F2A5B5ULL, 0xFA382B50D41B55A4ULL, 0xFE8AF8038435D755ULL, 0xCF47605A8993AC92ULL, 
            0x3423053D0961437CULL, 0xD23362EE8E5CBBBCULL, 0x122485AE1CEFE385ULL, 0x11402063C53E5869ULL, 
            0xD61B66C7DF1735CBULL, 0xF17D61AC6AD67255ULL, 0x3E4A09D6D113D3A5ULL, 0xB73A0D51C584619BULL, 
            0x28BE1648248742DCULL, 0x85BB5C3B8C3F97EDULL, 0xA747D82481406B44ULL, 0x82DC314B062E14FBULL, 
            0x418517951A0836EFULL, 0x2126A9CFD8D976CBULL, 0x3755F2F3CA25275BULL, 0x1B3B6BB86350FED0ULL, 
            0xA1662AFFFA6769FDULL, 0x032A8B3D0231EDF5ULL, 0x9D8D14576C44930CULL, 0x16BBD3FE0F5FDDD2ULL
        }
    },
    {
        {
            0xFEA7F6EE8846A029ULL, 0xBBA0617DEC08258BULL, 0xED29C5A4B9623345ULL, 0x5A7177DCCE2D17F4ULL, 
            0x5A1273546A369A76ULL, 0x371584C35188323BULL, 0xD0B5EEC5DC4A8A3AULL, 0x5068E3F522363126ULL, 
            0x57991597AD1F9E05ULL, 0x145091AF225CFD25ULL, 0x9A9AA4CEAA2E3526ULL, 0xE74668CEB99AA98FULL, 
            0xFFBA66927FA6E861ULL, 0xA3016EA38EDE026AULL, 0x9B56020FA5D4176FULL, 0x12E86F6293CB0441ULL, 
            0xC80DAB45FDBCB1C1ULL, 0xC8C3FDEFA5A57B27ULL, 0xCD1276B7A7CF2073ULL, 0xFA16E64B3E08623AULL, 
            0x7837AEB878FF9896ULL, 0x23908F826674E665ULL, 0x30C1F2B5810DE423ULL, 0x4F7E587266124F60ULL, 
            0xB411BC4CD93688B1ULL, 0x197FCE6BCF4089AAULL, 0x067B6F68963D7593ULL, 0x18CC4F24088CD6E6ULL, 
            0x7DD798549F554437ULL, 0xCF2D8166A87D1FC6ULL, 0x6A0BF71A455760DEULL, 0xAEFC635044E58DC1ULL
        },
        {
            0xA67AC7651ECD09A5ULL, 0x4E28767292CED996ULL, 0xE221906B6CB33480ULL, 0xACA42CE72FA5B91FULL, 
            0xF4DEE44141B94AB8ULL, 0x504FD24E34B1992EULL, 0x424F9CAA3380A26EULL, 0xB9853E40450AD475ULL, 
            0x6692C5C5A56FC0A5ULL, 0x1321180335D13431ULL, 0xBE6827C38D79D26FULL, 0x05FD8A882644278FULL, 
            0xB0C206ABA3C9FE11ULL, 0x9861FF4D81EAB42AULL, 0xFF80C7319EFD941BULL, 0x7A95DCC6F1E6648EULL, 
            0x3308A59EFEB09540ULL, 0xECD9EE5D8CDFA914ULL, 0x83681AEEDEE65CE9ULL, 0x39A09A89A852EAD1ULL, 
            0x41006D8252E2FEECULL, 0x11BEAF3C4EA05051ULL, 0xE7C2B2BFD7A3D220ULL, 0x5817B766697A01ACULL, 
            0x2C8C65EB74A22D4DULL, 0x9FB664AE8471FC8FULL, 0x49DD8B4DAD183144ULL, 0xBBE94E9171F6685EULL, 
            0x10FF2838B84C7A55ULL, 0x79B3F6570B6B342AULL, 0xE416903259CC77ADULL, 0x006A668D88232129ULL
        },
        {
            0xDABB6C3D8BBCCFB9ULL, 0xE95011918F5DCAF2ULL, 0x9C31DAC684F7E1A9ULL, 0xCEEA72659416B4DFULL, 
            0x7D4138E5D6AEAC7DULL, 0x5D81E5E2370F0A5DULL, 0x88F0F77A901CC97EULL, 0xCEC58D69459A8856ULL, 
            0xB26B21A74CA7F6CEULL, 0xA12F3504436A6071ULL, 0xA8C3892FD9097D44ULL, 0x6E5DD225A37B9171ULL, 
            0x156939674165F3A5ULL, 0x116A61953C9A8022ULL, 0xBC5A8F4B6C8B29C6ULL, 0x15DA10E1DBED03AFULL, 
            0x649171F1150894B4ULL, 0x08F4261F00C303D8ULL, 0x44AA8EDF41882C33ULL, 0xD286971AB412BDE4ULL, 
            0xEEC53BAC8B2716CDULL, 0x5568825122A72C18ULL, 0xE4798D07DE8A8858ULL, 0x15B24B9ECA0C53AEULL, 
            0xCF86EE93BC06B468ULL, 0x82C86B8B79297C1CULL, 0x212012FF3B73C313ULL, 0x992A9D4FECFE797BULL, 
            0x7C4990466B1587E6ULL, 0xDDD8F2AB7AD78557ULL, 0x75E4D61179FF276EULL, 0xD01AE0E3BD162D9EULL
        },
        {
            0x21ED8174D6B47288ULL, 0xB33BBCF76CDE68DAULL, 0x21EEBAB58FFCBC50ULL, 0x9BA6B1AF76DD0254ULL, 
            0x3A0C4C556939E0BAULL, 0x0FE6C0B2A4BD98B6ULL, 0x80724671EDCEE278ULL, 0xA1F1637A3CE9B6DAULL, 
            0x1C767B817C1B0011ULL, 0x625307D88EF2B9F3ULL, 0x409E740A123E963EULL, 0xC05ED0A881ED1B94ULL, 
            0xF031CFA44D574248ULL, 0x347AC008998A977CULL, 0xF3BA2656ED6DCF8CULL, 0xFCF7AF1B493F43ACULL, 
            0x29CAC89DC3BEEDFFULL, 0xDED7D93CF8FEC9EAULL, 0x8B387B23D63AE9A9ULL, 0x13D2C47910ED35B8ULL, 
            0xA161693DD775D578ULL, 0x7DF19762313495F6ULL, 0x4D48FCA45BA2268EULL, 0xD6EC508576439BE1ULL, 
            0xF7C05AE82ECC1554ULL, 0x74E535E0B8A8754AULL, 0xC59C34BC3C8CD3F8ULL, 0xEF2EEB3A8955E7A3ULL, 
            0xDA2FF41BABFB95ECULL, 0x1AD14B478EDDB5B8ULL, 0x3415B3440039C771ULL, 0xAB4E373B6C7C86C9ULL
        },
        {
            0x1CEBE66075BA85A0ULL, 0x066F136E34903151ULL, 0x051B5F35C2696874ULL, 0xF021149E076420DCULL, 
            0x8A8CDC60B7C7928DULL, 0xDC45A5DB811E553BULL, 0x402B5C73D8259F8BULL, 0x0D9619944E71C38BULL, 
            0xE53FDD2581F16B90ULL, 0x0016F5F0EF81087DULL, 0x86598A63A27FA2A4ULL, 0xC9E17916D57245C8ULL, 
            0x5917550B465B7965ULL, 0xDF7B36F3244A316EULL, 0x27834640DC6B935DULL, 0x4E3F75CB6B498ABAULL, 
            0x7FA623FF25C55A1EULL, 0x8BED3D3D4A9EC86AULL, 0x255CEB6C0F1F47BBULL, 0xBACC2B7A520B362DULL, 
            0xBDCAE917DFBE97F6ULL, 0x664D8531DA029252ULL, 0xDABFC93DF98935A8ULL, 0xC63964712D7EAD14ULL, 
            0x922959C05B307806ULL, 0xEEC2D5AFA6917D63ULL, 0x7026EC6836438ACAULL, 0xEEC93EC9BE438082ULL, 
            0x507E5249E9CC4E68ULL, 0x668B8A22B06F0C13ULL, 0xDA47B02CB4EEE17AULL, 0x1588768190BDF171ULL
        },
        {
            0x5285BA2D7C821CDFULL, 0x45D602E9583534D9ULL, 0x066DBCA69B9CF168ULL, 0x894200D975512738ULL, 
            0x11AB3F37EBFDC486ULL, 0xCD4FB191DC29AA99ULL, 0x9E9A2F4587FE97C4ULL, 0x335D46E7E0055281ULL, 
            0x60D4785492629D27ULL, 0xE04E5E1E5AE52A5AULL, 0xF10C922F2C79718FULL, 0x0A6F8E13CE1747A9ULL, 
            0x25E3DC9689B09305ULL, 0xF45B17E32837261CULL, 0xC59F5621EA5D0BBBULL, 0x129A2E92DCA4EF28ULL, 
            0x22EA192CFBFDC5ECULL, 0xB699E855AA53BC14ULL, 0xC221C0430DDF2250ULL, 0x205AA270BB59D4A4ULL, 
            0x4C59CAF200F39D6BULL, 0xDFF87C403284AE27ULL, 0xF72D6A4AB63767D0ULL, 0xD87C111832B4F02CULL, 
            0xA3AF0FCA30B31B15ULL, 0x1DF31121962F9485ULL, 0x56A1597EA2034B2AULL, 0x72DB3FA253A157EDULL, 
            0x317B828FCF755C0FULL, 0x7DF5AABAD4F3C319ULL, 0xE9BEE78DCC2556FCULL, 0x7F901AACD7F018F4ULL
        }
    },
    {
        {
            0xB39486CD309FBEB1ULL, 0x73B8696DB5B36A9FULL, 0x875910ADE6D37839ULL, 0x0E12C388A8E7C5B3ULL, 
            0x9593A35D34A16D94ULL, 0xC5B21DE199FC54FDULL, 0xEB25F4A9EA16B914ULL, 0x673F2BC96D6759B9ULL, 
            0xF6E5D2440712762FULL, 0xCB5979028BA7B05AULL, 0x453C0A0535404459ULL, 0x5671453AD9ED2BAFULL, 
            0x57B96FD4F0792181ULL, 0x35F42A89D65AB796ULL, 0x159AFB73FA9A348BULL, 0xED6F65361941CA5CULL, 
            0xD377AF7124B5FB1FULL, 0x7859126E0C9203ABULL, 0x6109B3E4CD4CC862ULL, 0xEC19DC22979EA67EULL, 
            0x0E0BBEF6B671E7D7ULL, 0x0C6282DE1DAAC1A8ULL, 0x1E7907C99FF379E3ULL, 0x3085ED2D245A450DULL, 
            0xCD0849B3CA966116ULL, 0xA1D49E5B88E647B7ULL, 0x70B8752C511E4EEEULL, 0x8D388E2493554F07ULL, 
            0x385585C44CA42DBFULL, 0xF0EA8A2F269D2F79ULL, 0x49D92D0FC11B784CULL, 0xED2AE2679F7A6417ULL
        },
        {
            0x719C696C4B36EC37ULL, 0x05C4AFA67E9BEAADULL, 0xAC261B7BD34AB086ULL, 0x5DFAF904CFEEAF56ULL, 
            0xBB6E043C3F639020ULL, 0xBC67F8D2D4627C23ULL, 0x049FA6487E101D2BULL, 0x1B5B5E6434DE1478ULL, 
            0xE913C938890E01D7ULL, 0xA3423E065E329FA6ULL, 0x676E5F2230F03AB5ULL, 0xA82F59229BE33711ULL, 
            0xE77F56F41AC90C3FULL, 0xED5B2BD50457534BULL, 0x453464688D2CD99AULL, 0x8B0FA3F78C379A82ULL, 
            0x7A03DB3CBE2D9805ULL, 0x2FAEBDADAC209489ULL, 0x4A403466536B096AULL, 0xC72AEF31F68B58BFULL, 
            0xB7901D46C6EC421AULL, 0x37952BDE722FED03ULL, 0x664D91BC9077BD86ULL, 0x7915CAC9D39BCA1FULL, 
            0x47A1FE1AD780DC1CULL, 0xA6531DE12E9B429BULL, 0x73FCD0452CDA3D75ULL, 0xE8EC047CA308FAC8ULL, 
            0xA147E12899849980ULL, 0x13FADF4DBF8A0055ULL, 0x974C40323904A233ULL, 0xFF9DF79668F1EB90ULL
        },
        {
            0x5ED75CA702C7D49DULL, 0x34D68BBBEEBDEF09ULL, 0x4D186F4D46EB6976ULL, 0xAEB190671FE36294ULL, 
            0x709A44042CEC19CAULL, 0x36931B6FEF132785ULL, 0x5207E8CDBCB5A03BULL, 0x953BBC433E6B62E3ULL, 
            0x25864470D731D759ULL, 0xBBF9819C0E882868ULL, 0x372525A9956DDBA3ULL, 0x67EF7935385166C2ULL, 
            0xE0307D4015DE7BBEULL, 0x7BA96780CCD6DC31ULL, 0xF549D60306898167ULL, 0xF5BA600BE14197BBULL, 
            0x2DF402660185554EULL, 0x262E85AA36737312ULL, 0xC10BFF0FB3DFC3F0ULL, 0x6C8CD2C7A1D1ECEFULL, 
            0x8A1B543BA72EFB78ULL, 0x7AEAF8A1CF3ADA43ULL, 0x0DFFE9C72404FC46ULL, 0x88306134078E522FULL, 
            0x1A575612FD0AF64AULL, 0x0F2AA888E404FAD1ULL, 0x3C502F7E80A1445EULL, 0xCB41F20BBABF9D43ULL, 
            0x3CE24E7E976E3912ULL, 0xA9F4774BC1672255ULL, 0xD87ACD4C1103B9A1ULL, 0x00CED62F6E6AEB4BULL
        },
        {
            0x81B0CFC70E371557ULL, 0x98BCF93A9F5ABD8CULL, 0xF6690F9ABA2922E9ULL, 0x1E9A66E4FA57587FULL, 
            0xD219489389EF8B13ULL, 0xA3BEFDA6C7A6C890ULL, 0x489DE862242B1B7EULL, 0x3F133D42900B8085ULL, 
            0xC5CAE015E65416B7ULL, 0x4FEBC8B431C50817ULL, 0x40138C060A9FAA47ULL, 0x65E45785C4905700ULL, 
            0x620DE80B9565B21FULL, 0xC77DECD57E855273ULL, 0x5C4DA0A6D6631AA5ULL, 0x8DF3DC8B47E69D0CULL, 
            0x0FF7322B5EAB53E4ULL, 0x78F542D7C08EE537ULL, 0xF9DD5DDFB1D533D9ULL, 0x2053AEEE8FB21667ULL, 
            0x8AFE02D22E55EFE2ULL, 0x5B5827BE1E858867ULL, 0xCFE3DA43FFBB3280ULL, 0x2792532DF6E7968CULL, 
            0x5E5E9F456B0F87D4ULL, 0xBC61B4BBE1ADFA58ULL, 0xBEE4A38DB340E700ULL, 0x59E161B022347CD4ULL, 
            0x556C74D804C51432ULL, 0xA972B4FC80030752ULL, 0xAD34B6B1BD59875EULL, 0x25239DAC6FE549B2ULL
        },
        {
            0xF218FE091D3DACE6ULL, 0xA494F47E7D3C773EULL, 0xE6A8496BE0D01705ULL, 0x31DDC112034018DBULL, 
            0x0F55482EFE64B68EULL, 0x81D302247E66BBCEULL, 0x8473822F7EC98EE1ULL, 0x9CE8A8D72B3A5F22ULL, 
            0x544124E6CBC502B9ULL, 0x74C471FD3D62E903ULL, 0xA62954D4359B9492ULL, 0x86A003D0B840C586ULL, 
            0xF64E065AC56C6CD5ULL, 0x1E7D87A63A243689ULL, 0x55C63FDE8E90F9A5ULL, 0x83941116E9BBD490ULL, 
            0x44EE1AA6096A9532ULL, 0xCADAE97B6AD8033EULL, 0xEE766C7C2E1D997EULL, 0x6A6169EBAC54159AULL, 
            0x2FC3E2BE7256E50FULL, 0xCBB0328B07D1FCBAULL, 0x29A430818681C4B0ULL, 0x35D82EB21D03930BULL, 
            0x1EE80EAF8AFC1DACULL, 0xCC74DF159112D59CULL, 0xC53B4FDEC977196CULL, 0xB75E656184BB8994ULL, 
            0x7FC29550C32828EFULL, 0xEFBB60FA7870CD37ULL, 0x51654BF439554E0DULL, 0x874006BBB57023FCULL
        },
        {
            0x70EA048844383B24ULL, 0x81FBBD3D01636C57ULL, 0x6DDBE50061F263FCULL, 0xCEBB39E327018F9AULL, 
            0x26CDF007FEC9CF48ULL, 0xA95CB0EE538C2347ULL, 0xF7E1A19E534D3C20ULL, 0xDD9C2BA26E382925ULL, 
            0xCF0C3184503CE7AEULL, 0x7137E06C9286178BULL, 0xE04C61CE509BBDC9ULL, 0x938C73903A0CC06CULL, 
            0xE227AAD0B2F6CA55ULL, 0xB43104879BEA6FA9ULL, 0xBBC7FC6C4D3F3D67ULL, 0x056F68DE64FDA26DULL, 
            0x57D8BE3C50BD3522ULL, 0x2B9FF9780BFB9365ULL, 0x12095AB31ED1178DULL, 0x72FE2BCBEA99CB63ULL, 
            0xFFB4887BDB18E862ULL, 0x29D0BF230259CB54ULL, 0x47552D070E1FBA3FULL, 0xC17E31820EA2D565ULL, 
            0x7784FD11C99DEFE9ULL, 0x30D01422EFD0A97AULL, 0x126A52955AA1C825ULL, 0xA8FD02BC48DE0934ULL, 
            0x92A86B9D41131017ULL, 0x8BD37086448FBADCULL, 0x0172B25F6303A75FULL, 0x07FE24D626FBA768ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeySpawnAConstants = {
    0x103F45DEC0B276FEULL,
    0xBC938082FB2C3476ULL,
    0x6E2B30751CADAC9FULL,
    0x103F45DEC0B276FEULL,
    0xBC938082FB2C3476ULL,
    0x6E2B30751CADAC9FULL,
    0xEE8947B7976383A9ULL,
    0x797DC0EA03769789ULL,
    0x20,
    0x7F,
    0x02,
    0x02,
    0xC5,
    0x53,
    0xBE,
    0x8B
};

const TwistDomainSaltSet TwistExpander_Pollux::kKeySpawnBSalts = {
    {
        {
            0x833A60D01EFCF484ULL, 0x59702CD9BE539953ULL, 0x01C0A7B5CF2E1931ULL, 0x91471F28A3B441DFULL, 
            0xF5FE603BD0A20B28ULL, 0x3614D8B247CD5E5FULL, 0x627DC99D045697E6ULL, 0xA3C4EEB2F4AA1994ULL, 
            0xA155C21B6789C081ULL, 0x14872B8C1E3E569DULL, 0xF737E535C29568DBULL, 0xB5334626DC03D67DULL, 
            0x3CED7B9A7CABF1CEULL, 0x07302F88E7B0055CULL, 0xF61CBC0510D1A49AULL, 0x259045E6833F9B07ULL, 
            0x0EF22637E956D3ADULL, 0x7D42044558E7E575ULL, 0x06414454A5221AD6ULL, 0xA9720B663CAB2072ULL, 
            0x4D91EFC49794404BULL, 0xA99E41DCD7F5B8CBULL, 0xBFF1C5BCDD50C5B6ULL, 0x21DD4C00C5151211ULL, 
            0x3ED44549514F66BBULL, 0x59B2273D24E7283CULL, 0x59943EA0BC725D64ULL, 0x3CAD3DDA7F2204ABULL, 
            0x435877C794F4B0E3ULL, 0xDAE0796EDE21CC42ULL, 0xB38A1D3BF2E2D0D8ULL, 0x0D25FAA5AB45F4BCULL
        },
        {
            0x4A5774950865049FULL, 0x2A9A73459795A306ULL, 0x8A586D65C5B9EA74ULL, 0xAAFF86920141FBECULL, 
            0xCF7A7D22C0F734E1ULL, 0x8E6A4F8615EE12B3ULL, 0x1161CC1D41294D58ULL, 0x8716E2B138C9D4D5ULL, 
            0x5FBA3138764964C0ULL, 0xB308DB2791A34297ULL, 0xF33D3E13BA555968ULL, 0xBB4E49B1F50BB36DULL, 
            0x3ED5B902EEDC0683ULL, 0x1B9801B3866893D1ULL, 0x3606EF78436596C1ULL, 0x6CC48B4284F86472ULL, 
            0x1D5ABA334DCDFD46ULL, 0x9C8992692CF62B1AULL, 0xF651C5D673CBE980ULL, 0x90E5335CCB72D59BULL, 
            0xC1C5E6B713EB5B27ULL, 0x5883C842E270C1D7ULL, 0x6A68470EDA235897ULL, 0xADEDC99D81BB689EULL, 
            0x03EAFB68371CAA2CULL, 0x77F3671175581A3BULL, 0x747D2E5400709F5FULL, 0x8C5E6B26C0574647ULL, 
            0x0621CDC98F5D1A60ULL, 0x4BED556A4A10BFD9ULL, 0x52AD54FD591A5DADULL, 0x7486F86EB9F6C151ULL
        },
        {
            0x6D5A81EC6BBEAFFCULL, 0x4E7F048740E7B969ULL, 0x38F7A0979B561D6BULL, 0xC8659133C1867119ULL, 
            0x00C2B28144F70017ULL, 0xECE73A73A7A0269FULL, 0xE340EB95E590D4C4ULL, 0x151AB8969CA32A6AULL, 
            0x3F1F7BB52B34660FULL, 0xA1085040F86D152CULL, 0xB0A5AF4D94A12E8FULL, 0x4C92EF58B0659045ULL, 
            0xD5AC2BFC2322462DULL, 0xF82B325E5612C8F8ULL, 0x171C6EE8A44428CEULL, 0x0132CCC7A66A8CBCULL, 
            0x6FE6FA68B516775BULL, 0x644CD666664EBF3DULL, 0x39F9DC11F29D9493ULL, 0x21FBE21F2D13544CULL, 
            0xCD5A5BBE0DBBCA5FULL, 0xF1DD647597C6281AULL, 0xAD4ABD6BD5B80EEBULL, 0x330BB5D632CCFB5BULL, 
            0x3B6ACB99512A4DFBULL, 0x33CCF82EA443CAB2ULL, 0x4DC589397C9F89D1ULL, 0xF51366B1EE5605F3ULL, 
            0x4267A35D70064800ULL, 0xFA795EBEA8134BF8ULL, 0x5B2C9408D2CA38A2ULL, 0x604ECE2286BE626EULL
        },
        {
            0x103A7F6A48CE02CAULL, 0x9AB38B9A3B97A5BDULL, 0x601FE8FD6D357E5BULL, 0x277021087C31CB28ULL, 
            0x40163B8504571B12ULL, 0xAE5D07F6CF46EE14ULL, 0x69FF2879E0194AAFULL, 0xA6ED4295367D345AULL, 
            0x0443012B7F631ED1ULL, 0x4DAF46D135538B3BULL, 0x43C482550D30E4CDULL, 0x23B1F54F4A937373ULL, 
            0x82F7F6DF196DC90AULL, 0x51D269FDAA7E665AULL, 0x709D08618A15384EULL, 0x41165ACFA8B8096CULL, 
            0x3454F3F3CEAD4C26ULL, 0x7271C817C18BB32FULL, 0xAC49DA6932701031ULL, 0x4522303452DBEF47ULL, 
            0x28AA2993AE38BCCAULL, 0x5DF05E944703D288ULL, 0x55D9CE13322A400AULL, 0x2EB779708660E201ULL, 
            0x63CF8E24788F6285ULL, 0x0F21A8A0B9E1713AULL, 0x1CE3D0F0FEC1374BULL, 0xB7ADA536585CC513ULL, 
            0xC26863D19666DE24ULL, 0x7D865011D26055F3ULL, 0xFE3EC4F3639939E6ULL, 0x107D3C0F4E59D5FFULL
        },
        {
            0x76B7A74798161E84ULL, 0x32BACA08886C7FEFULL, 0x5472DF0DABA13C4EULL, 0x5F81AEFCA224AB5EULL, 
            0xF7C3D533D53304DAULL, 0x61F70CFD50021FAAULL, 0x08A4A21F329AFC8FULL, 0x47F508D760DC383AULL, 
            0x88A610007548CFA9ULL, 0x18AF8A59F77E85C0ULL, 0x6DA355B29C1C052EULL, 0xF7D643DDDF97CABEULL, 
            0x900E9D44DE9EF452ULL, 0x1C916473A2BE2721ULL, 0xF7D5EE886092A507ULL, 0x45AB4D272689B689ULL, 
            0x53B9BDC50F2C00FFULL, 0xC82C736A96998AC2ULL, 0x9DA7ECFB18753848ULL, 0xE8DA319F6877A583ULL, 
            0x83260A58FC2FF49EULL, 0xDECEA1D85A62C8B0ULL, 0x6D5FDD106F03639EULL, 0x74AAB51B8A539CD9ULL, 
            0x51D5929C9BEFCB3BULL, 0x27F49DF2EDFEBC94ULL, 0xA62987E140992DA9ULL, 0x5CECF8559CF15F81ULL, 
            0x044B5A817445E12BULL, 0x6AF9B29AAC601C39ULL, 0x3D026E9BA90B43EAULL, 0xD1C946323FB901A7ULL
        },
        {
            0xD588E5FFA246F0B2ULL, 0xE4F8ACB1E525BF77ULL, 0x1C88E3E2D06BD954ULL, 0xC722B3C34174083EULL, 
            0xF6C5E69705C14526ULL, 0x1061E34D14552F8EULL, 0x538CD6238F4A208DULL, 0x564E44FA70F4D6F5ULL, 
            0xC280B81EADE63422ULL, 0x15C6DF35A0D80359ULL, 0xC0AF0AF8929AC9FCULL, 0x7972009747B3577DULL, 
            0x55EA09B73AD74B93ULL, 0xD8BBAA4AB9C68D9BULL, 0x74483C5678E09508ULL, 0xE4CC8F8E1345B10CULL, 
            0xBC57D9BA0B47C0E3ULL, 0x9793A69C4B05F4CCULL, 0x99F5BF8458BFA97CULL, 0x36E010A3E9618B05ULL, 
            0xBCD62C31936CD3C6ULL, 0x4007EB46CB7EA633ULL, 0x26CBDC8B72F4D81CULL, 0x4CFB0F5C9BDE7010ULL, 
            0x88EE4E94FB1555A3ULL, 0x0E053025DB1E4736ULL, 0xF71A49D1C786F185ULL, 0xE41F405E338398F7ULL, 
            0x1EE2E66728298BB5ULL, 0x5BB8106953CE587DULL, 0x809406B5AB64AED6ULL, 0x6CE96883246960BFULL
        }
    },
    {
        {
            0xB4942FAD5630D563ULL, 0x56307187B4DEA19FULL, 0x7EA1BD5390637681ULL, 0x028FA7D137B0B67EULL, 
            0x1E4C783C5AF6B2DBULL, 0xA34D8A3AC10E6DCBULL, 0x09052402694A9D74ULL, 0x78C1CDFEF5CFA6FFULL, 
            0xFDA135DADF03D5CCULL, 0x459234DDC6EAF30BULL, 0x4F6F56DFF669874EULL, 0x40E2B25D813D7BE4ULL, 
            0xDA762A59698995EFULL, 0xECCD8060716474C8ULL, 0x305E29D5707A78BBULL, 0x0512CB7C71D11463ULL, 
            0xE1640137D8EE70D9ULL, 0xD80EC8BEE4DCE847ULL, 0xB32561E64CE14294ULL, 0xE5FE2CBDF1D13A10ULL, 
            0xDDCBD6AA56810162ULL, 0xC01D248CD2C66BCAULL, 0x875FC9EBCB3589F2ULL, 0xEE63D6A77C5E826BULL, 
            0xAED51E52CBE40204ULL, 0x02930A5F6D01CE22ULL, 0xB050C8BAC6762A9AULL, 0x8D905FC5FC100C0CULL, 
            0xCE3E87F9A6D6E5A3ULL, 0x43355D3C0D2D5FE3ULL, 0xFAA5035ABD9E67F4ULL, 0x0FD6F5753B08FA50ULL
        },
        {
            0xA3FFA59F53F0F892ULL, 0x791719BD1685BD00ULL, 0xEA68623ECA4F210CULL, 0xF41C48B87AD4EFBDULL, 
            0x6FDACE1686D5280AULL, 0x52AC0896E31DD223ULL, 0x0A1C1E886BEE1ABCULL, 0xC014E7A2AC0C3E29ULL, 
            0x68BD36C78635900EULL, 0xA68E691947B4FEA9ULL, 0xA27FFEDFDCF70B67ULL, 0xD2ADCC53E627F3FBULL, 
            0x1C230EC540CC2811ULL, 0xF08C598B3CD6DA13ULL, 0x48326E73C89277F4ULL, 0xA5BA26018B410233ULL, 
            0x693A49D692374A40ULL, 0xB1B679BC9EB7BA6EULL, 0x70EFC1966A27982CULL, 0x9112CEC0A8E86B3DULL, 
            0x89640E5984214BA2ULL, 0x915C68A56CD9DF17ULL, 0x9D5F577CD1CF3663ULL, 0xFF459AEDBF7A137CULL, 
            0xFD9FA5C0243431B1ULL, 0x1BF39F49C42C0E41ULL, 0x804A6FFA31F491EAULL, 0xBE79C8233DA2067DULL, 
            0xC2E1EF20E095E054ULL, 0xEB6230471260C3C1ULL, 0xF146DDB1FBF5DECFULL, 0x72043CE14561CE00ULL
        },
        {
            0x4121172EE7D354B9ULL, 0xC4B671D4AB456C59ULL, 0x4A221011CD77F7C4ULL, 0x7D8451BA5F8EE417ULL, 
            0x1353FB55276F2B2DULL, 0x3B262033B528DC01ULL, 0x5AEB6C2305F5336FULL, 0x46AF1CA491414287ULL, 
            0x0E2565A1524A3955ULL, 0xBD93CAF870EC5890ULL, 0xE357C12F536E7EAAULL, 0xB2D0D75F0C439895ULL, 
            0x3759B05C696B2331ULL, 0x5F9C81F2D76702F8ULL, 0x162A2E0DE453B3C8ULL, 0xBE879902F21AA9C2ULL, 
            0x58F146F06EF3653DULL, 0xFA6D1357AFABA9B2ULL, 0x181EA45AEA54AD74ULL, 0x089B996CF0361FA6ULL, 
            0x537323FE4CF55D75ULL, 0xA301AE637B252B19ULL, 0x012071F641D82590ULL, 0xC080500D36B73C3BULL, 
            0x77E1AD905ED26205ULL, 0xEB892A567A72D294ULL, 0x057D8C8D338D5F32ULL, 0x19627831312276B1ULL, 
            0x7A7D857CA8F9DD40ULL, 0x6FE2BB27176682BFULL, 0xC441CBB8E8F4C981ULL, 0xAD54189032A3EACAULL
        },
        {
            0x55DA8D82763DA05CULL, 0xF7398C4189836FE5ULL, 0x845E59751FCECDA3ULL, 0x18D5E977843C866CULL, 
            0xE9E3D20CD2A4F10AULL, 0x1C9230D6DAAE9FF2ULL, 0x2B55CCDD86054067ULL, 0x39AD463EA62C3CEBULL, 
            0x169AB8A23723EFC2ULL, 0x7354CAA409B26BEDULL, 0xD6C9189C718742E1ULL, 0x079ACF5A548D5EB7ULL, 
            0x00A6372EA7D44523ULL, 0x18A5553BC842969EULL, 0xCF4F7B114A80BCF4ULL, 0xBC98D3621E2E2905ULL, 
            0x3EEE4163E3F8732DULL, 0xCF4DA458C048AD89ULL, 0xB705583D1358A976ULL, 0x4820169746EA7A86ULL, 
            0x1055D414A27BE980ULL, 0x83503B0E2D5B0486ULL, 0xF315861A560DE806ULL, 0xD8A6E7C891B8D1B1ULL, 
            0xD4626D3BF4B33E64ULL, 0x05735C452D3A9488ULL, 0x41C3228084D037E4ULL, 0x3B26609798FFD2CEULL, 
            0xDD566EC322B77B46ULL, 0xF12BB02A5F0520F9ULL, 0x13496DC986473E68ULL, 0xD7C7C532390CF1E2ULL
        },
        {
            0x6F24E3F09BFBC559ULL, 0xD8D69DB81B892B45ULL, 0xDAF9CE4D3E2079E5ULL, 0xA06B39222D3215E4ULL, 
            0xE5BBE37A6C77A7CDULL, 0xE04F0A5599F5BFB0ULL, 0x60ADEE56528A51CEULL, 0x432DBFA2DA0A7986ULL, 
            0x5BCC931D0E9CC60CULL, 0xA80CA7BAC0CE275CULL, 0x5397B5CCB20B8BB8ULL, 0x6AB13B9B529650F6ULL, 
            0x0F4615AAA3BB2136ULL, 0xFB33A81DB0C61216ULL, 0x2E07629076E42934ULL, 0xF08CE57C87105DD7ULL, 
            0xD6DCA14B3646185DULL, 0x5E983481D3445143ULL, 0xFF32D4B9065DD13CULL, 0x56F1D0B4773FCAEAULL, 
            0x2527F24CBA12FFC9ULL, 0xDC5EFE411CA1211EULL, 0x0500FED61C05EDF8ULL, 0xEDFA9AEF407DD502ULL, 
            0x2E67DE5C886F3E90ULL, 0xDF7CB15519A06663ULL, 0x21A15F5F1897A668ULL, 0x3331DFB2DD63A448ULL, 
            0x0587DFE2EF9DEB90ULL, 0xF12C5FE53B0E6BFCULL, 0xE2E0FD6784BB610FULL, 0x5B0A377CC2834869ULL
        },
        {
            0xF21F54CD76ECB21EULL, 0x8A81FA038CC9892AULL, 0xF1C0485FFF00C23CULL, 0x6D56FA77B81333B0ULL, 
            0x5CB6B2B93E074B69ULL, 0x9A9BBB33B7CEDCBDULL, 0xB43E9967F528D9B7ULL, 0xF31FE4D7A3DD4B81ULL, 
            0xB6A45E7154225F08ULL, 0xE9E6D3DB0D515AB7ULL, 0x14C038872D176763ULL, 0x72568BAD67B3C3E8ULL, 
            0xD98E41C95E10CB29ULL, 0x1F459EFA7F07D8D3ULL, 0x8DA39B97850A4936ULL, 0x4041CB904FF9F9BBULL, 
            0x156CA59A117071FCULL, 0xE0097E6114C6DE51ULL, 0x55704500B80753C0ULL, 0xFA6A6E1403F26FB4ULL, 
            0x078CCB9B0E25AE4DULL, 0x2E1F2EDA6889FA33ULL, 0x155393C88B473A0BULL, 0xC88CD52B4773A622ULL, 
            0x1728AF42061C2AA4ULL, 0x53108C160EADBCC0ULL, 0x8DE41B16042250CCULL, 0x0052251001C8214DULL, 
            0x826DD410C4A3B301ULL, 0xA4AAA971432BF21BULL, 0xCCD76091D6F6B953ULL, 0x8939BDD96694ACE8ULL
        }
    },
    {
        {
            0x96CEB1C9D5C3D187ULL, 0x7B5C9494957E6BDFULL, 0xCBC0DB65DEFDDB1CULL, 0xC0B67F682DF0C624ULL, 
            0xE68E279F84F974DBULL, 0x91FD263BC740F715ULL, 0x3E95065780767263ULL, 0x3809B97A1187A5DAULL, 
            0x8B714515A4ABB8A4ULL, 0x9F22C7723B4C9049ULL, 0xE758EFE243D12533ULL, 0x72A5E8956325343CULL, 
            0x8FBFA56CF4F2A402ULL, 0xB82DD860E03A2F71ULL, 0xC6A239F331B924F4ULL, 0x41C23599342448BBULL, 
            0xFD15D944713E76C1ULL, 0x1C3AD11D1932851DULL, 0xDBF7F7EBF809F2E0ULL, 0xCDF986ECFAB03895ULL, 
            0xBCF878C5FC7A6ED9ULL, 0x646DE8216A4A770EULL, 0x89712E773A1FA475ULL, 0xA816E7D2E289EDE8ULL, 
            0xB04976CD45DCA14EULL, 0x05BEAF91189AC8C2ULL, 0x728BBA21231D34A9ULL, 0x3DFCA74FBCB910E3ULL, 
            0xBB76ABA46E7D8C91ULL, 0x759358BC4D29C495ULL, 0xA8C6EDF967C032C2ULL, 0xB629F8F5E4B45C69ULL
        },
        {
            0x198F46CA2C1B01FAULL, 0x1521DCAE284F0F5BULL, 0x29A78FCFF4548113ULL, 0x845F1FC20CBADA9BULL, 
            0x8A63EDED6ADF8296ULL, 0xF7614114BFE08CFBULL, 0xB4D7E9ACBFE61DDDULL, 0x5FBCD076DAEEE059ULL, 
            0x51BF5794066D0CDAULL, 0xCB4E07B2D1CFC3EFULL, 0xF999A97D0D03840CULL, 0x25BBC5FC25646DAFULL, 
            0x466F95808795DFBBULL, 0x720E39891D113770ULL, 0xF1C793E0CF23C917ULL, 0xE69C66EEE5FA4759ULL, 
            0x4CCBFBC67ACA482BULL, 0x2F11457A96BA136EULL, 0x445F00FE4188756AULL, 0xB09F24D6D7AEF592ULL, 
            0x70A1A62B93D44804ULL, 0xF3B61515F90C602DULL, 0x1248ED2228C275DAULL, 0x65F413B314AC99F4ULL, 
            0xDC549ACD6DA07E76ULL, 0xBD3EB3E5D624E40DULL, 0xF2C594836DE41561ULL, 0x27DDD69174F251A8ULL, 
            0x0A3B3C4849A23A1FULL, 0x260CBAA2C752E5CBULL, 0xCCDBDEC68A0370C0ULL, 0x0717F0C1823871EDULL
        },
        {
            0xCEEFCB48F58B88ABULL, 0x2E48A3DB97CBFA56ULL, 0x53366A4BD75C066FULL, 0x29EF053FE409696EULL, 
            0x69FF1DB5A625F7E9ULL, 0x43AAB40B273B1146ULL, 0x8DC5AC909C7545B7ULL, 0x35EA20543D27D826ULL, 
            0x09A8023005220A19ULL, 0x4425FB63090EFB5CULL, 0x798240B321414478ULL, 0x1EDE9612143835DFULL, 
            0xB822DFBE7A9285C2ULL, 0x03FA27205393AFDFULL, 0x8EF7965FE3C307B2ULL, 0x01B19299543C5F5DULL, 
            0x93D2818A53BAD5DAULL, 0x7734BC39798CC46DULL, 0x77766B85FC584675ULL, 0xFD40E5B005A7D1A8ULL, 
            0x98E197614E0331C9ULL, 0x93F72B28EB631346ULL, 0xA246CC90510605B9ULL, 0xD2EB24B8F5B1DCCCULL, 
            0xCD7333739B77FB39ULL, 0xB69E124109F73919ULL, 0x4067D8F7704E6685ULL, 0xFD02D7BF9303E53AULL, 
            0x872E21A8496F2F4EULL, 0xAA0F9BF91DA392A6ULL, 0x8A313D6D688A61B8ULL, 0x0FA86F5CB00A96DFULL
        },
        {
            0x9C613FB0EC7CBF92ULL, 0x289C5D1E9B25CECEULL, 0x398042D335516422ULL, 0x89B6BC613FC06747ULL, 
            0x18E6E45EFDBA108CULL, 0x45FC2D27093D952BULL, 0xB62EFB924676C2D8ULL, 0x2275FD5B7A7D4E81ULL, 
            0x3BE7132057BF5BBCULL, 0x6903E5406F269691ULL, 0x7F6E6DDB26AB083DULL, 0x8C4A26F05E9A27C9ULL, 
            0x822C2206F6B6F899ULL, 0xFB2511303906F838ULL, 0x74B0CF6FA1F96D6CULL, 0x18F59A6CB47EDBD8ULL, 
            0xBFBEDEFA53074833ULL, 0xA240C70A73A23074ULL, 0x0CC15D33F411CF31ULL, 0xE7C7BFE226B317DBULL, 
            0xFE4657D55C6D1BEBULL, 0xFABC24B7ED873BEBULL, 0x9970280BF32C0751ULL, 0x5C70105926C9D81EULL, 
            0xC55681F17FA6E1CAULL, 0x617FA59C38D6F14CULL, 0x798E4D0E6212F486ULL, 0x75794956AAD8250FULL, 
            0x2F3FDD2C7821B8A6ULL, 0xDEC96230DF29E4B1ULL, 0x3CBAB528C5C1A876ULL, 0x2B1FCEDA86CB8FCAULL
        },
        {
            0xCCC74F4502CA73CEULL, 0x63DA4CFF10118F15ULL, 0x2375BB1888FA48D7ULL, 0x311122FFF478F69FULL, 
            0x8B40A038E5236B02ULL, 0x12EA31A7AE77E9FAULL, 0x640B4E4C5404AB3DULL, 0x6683CFBD7839C19AULL, 
            0xC781BBF9B6C02AEDULL, 0xEE8FA40DB94572F0ULL, 0xCCADAE552D3BC671ULL, 0x191A1CCFD6BA5F06ULL, 
            0x5E7CE962409DB7FAULL, 0xFAFD848948F5DCFAULL, 0x751D6039ED413BE4ULL, 0x9D79EBCF21BFA5A3ULL, 
            0x58FCF6C94C4A7D4DULL, 0xD4651951AB27EA71ULL, 0x1098327FD58268ABULL, 0x371DEC91CDC8D79CULL, 
            0x2302E96276420801ULL, 0x76EBE35181352FF5ULL, 0x2FAE115655463E47ULL, 0xF3F2FB76BF4E2423ULL, 
            0xEA45765A4D9205ACULL, 0x50A87215BD18AD3AULL, 0x107C3645D925616CULL, 0x4545257554A29A8EULL, 
            0xBB174FA8A00F1F4AULL, 0xE9A23C7AE7614D99ULL, 0xDE20B1D64CDF5F46ULL, 0x47E5A79437DC67E4ULL
        },
        {
            0x31FEF1725F9AD342ULL, 0x0D2C0DC8AB43FBC1ULL, 0x3885E046A4C096D1ULL, 0xCE47602107C34C4FULL, 
            0xC489FADEA105DCBCULL, 0x6D249FEFBB0B65F8ULL, 0x16B02179EF7D418CULL, 0xC0399FB6C19F639DULL, 
            0xE887BE147EAB6CD4ULL, 0xB177487D3E81E3E5ULL, 0x6F5420CCA753DF08ULL, 0x0F6FBEB3E6ED6C40ULL, 
            0x94F22BCB12EFD133ULL, 0x477BA648E5ABD038ULL, 0x0E841A23D722CB25ULL, 0x2CB24ED6790EFEABULL, 
            0x85CF84AD332A67A8ULL, 0x77CE2672BD5AD612ULL, 0x280F247FDF99D5FBULL, 0x5E8E09172C87700DULL, 
            0x286AFD95961A923DULL, 0xCE2CB12821A5B8BAULL, 0x2E74A8C9E627C648ULL, 0x97E93FC186D8EFA1ULL, 
            0x89C6F6EF5D593CF6ULL, 0x155EDF8CD1F4F297ULL, 0x6009E126B9C6804CULL, 0x580ED2B976AC0739ULL, 
            0xE3C2EDAA2E80D3E9ULL, 0x224BF7F7BEAB6919ULL, 0xDB1036D1D800B501ULL, 0xBD3FE94EC4D4DEAFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeySpawnBConstants = {
    0x688273CA4E506933ULL,
    0xF6829D716504916FULL,
    0x7D23C55F0060F96DULL,
    0x688273CA4E506933ULL,
    0xF6829D716504916FULL,
    0x7D23C55F0060F96DULL,
    0x8192F756FD72C142ULL,
    0x4216AFCF1EFC9742ULL,
    0xF6,
    0x1C,
    0x16,
    0x0D,
    0x23,
    0xE2,
    0xE6,
    0x05
};

const TwistDomainSaltSet TwistExpander_Pollux::kSeedSalts = {
    {
        {
            0xF4D606CD9FF5A600ULL, 0x5B026EAA27817A78ULL, 0x0F86D10AE8FA87CCULL, 0x994A6E5D2BCAA07CULL, 
            0x1B1755FCDE5DC57AULL, 0x9F9D19E223BACA75ULL, 0x0C9D0D464B22F01FULL, 0x1BCD5ABE40C8C636ULL, 
            0xB505CEFCBAB40F0BULL, 0xF9723818B98B366FULL, 0xCFE7EF35AF3F9DD7ULL, 0x443CDAA9763C1767ULL, 
            0x95BBDFF68026825CULL, 0x42FCAB63A99759A2ULL, 0xE443EDFDEAD09C82ULL, 0xBEAEEC2658D7CC32ULL, 
            0x7073C05AAEB4F18BULL, 0xDB2A1804CC892582ULL, 0x8BF943A59113CCE8ULL, 0x98C70693957CF95DULL, 
            0xA20FA1A01341E475ULL, 0x987DF3DF1818B2FAULL, 0xBCEF1255E7D66B0EULL, 0x8C02491C4E15484AULL, 
            0x4267BB139BF60D72ULL, 0x276873E32D33A5D8ULL, 0x83AE72DC83F010EDULL, 0xF8A5A5A4339E0342ULL, 
            0x5D46EECB285BB21DULL, 0xD670C5DFA74227A5ULL, 0x7BC83876C95E048AULL, 0xE63AF79D52E89169ULL
        },
        {
            0xA9A7C234A9E19E6BULL, 0x698EE4C1491A3B72ULL, 0xDC6F59D61DC5CED4ULL, 0x95081A1E026D9572ULL, 
            0x341884644A42D4EEULL, 0xA8073D5539CE1604ULL, 0x5208EC9470DF1330ULL, 0x70AE8E1296A82C01ULL, 
            0xEF4FDAA734571059ULL, 0x4EAEE30C8F6B4CC4ULL, 0xA181549606C544E2ULL, 0x87CD2F56B7AB6B5EULL, 
            0xD1A6830172DED700ULL, 0x927965CCBFA8F169ULL, 0x03239885B5A90239ULL, 0xEFDBCFED129C7280ULL, 
            0xB15D3449079F60F1ULL, 0xEC86FDFC4FFE74ABULL, 0x959D978351D14420ULL, 0x94AC7868DF3475EAULL, 
            0x1B4A32DB8058DA9EULL, 0xF63CC912FD229E10ULL, 0x43AC6C42314F5BC3ULL, 0xAD5C77853CD662E7ULL, 
            0xEAB6EAE147CAEC99ULL, 0x8C78E92F35AA4B9DULL, 0xB229FD99CAB7CAA0ULL, 0x49D69B4D86FF9760ULL, 
            0xE3FBB86C7A70DC82ULL, 0x9A32E0D9AF359913ULL, 0x24C5361D3F03E5E4ULL, 0x0E20E150844B4846ULL
        },
        {
            0x86ACDB4CB853780EULL, 0x3FEB544DDEB32D4DULL, 0x6BC8B24C9E7355BDULL, 0x3FE5DFCC051B4DBDULL, 
            0x45B049C0C0660460ULL, 0x461ED16DF39FB27DULL, 0xFA3AAE3710923F11ULL, 0x5FA960DAF147599CULL, 
            0x5F9E81AB9740DA99ULL, 0x338D05E90CEE8385ULL, 0x9C8A471FFB763001ULL, 0xC2A8C552FE127CA0ULL, 
            0xEFCA6C61B06AB89CULL, 0x3828CC7CC0C2E55CULL, 0xDFF52E3FB8629BE3ULL, 0x114D36D4CF1CDD71ULL, 
            0xBF006160A159C597ULL, 0x5D6F5C1FCB75585BULL, 0xB6E345BC030A23DCULL, 0xF9099ECE24A9FB46ULL, 
            0x2A7350A2A32524ADULL, 0xCE9EFC4AAE9717ADULL, 0x02570E62F21E8AC6ULL, 0x62259B2AC5E6A43FULL, 
            0x9BADE52171759CB1ULL, 0x5625D822756F2D86ULL, 0x524D84D8759793F2ULL, 0x178B0CD126584C0EULL, 
            0xC262A164E9132BD6ULL, 0xF270531C9FAAF0B5ULL, 0x53EBACC71342CCD8ULL, 0x1DE7B58819500B9EULL
        },
        {
            0xBB328A6E947F42EEULL, 0x3E5DF35BAC66E406ULL, 0x713AE664582BCC19ULL, 0x83D7FBFC31695CF6ULL, 
            0xC74866A4C9C541CAULL, 0xC9DB21C76FA04423ULL, 0x2AEE8693C1777D0BULL, 0x0CBA92FB488938D2ULL, 
            0xC2F5026D861ECE53ULL, 0xE26C5D1259D42525ULL, 0x53CF728F7EC5CBDCULL, 0xD37CFC0B9E5279F4ULL, 
            0x1D6193C4EEEC4928ULL, 0x3EAE55C532C17FFFULL, 0x334D9F2CA1A166C9ULL, 0x0744A691CB1388E8ULL, 
            0x326E2FE99DD3E8F7ULL, 0x6B0DF168D785479AULL, 0x7CCFE725C917D920ULL, 0xB9452A40F932F657ULL, 
            0x00F5A4BAB6D10B54ULL, 0xF3DFE5B6574FA89DULL, 0x1B0FA8119E52BA5EULL, 0x55B931980025D2B1ULL, 
            0xC7189B6D10C3A4D3ULL, 0x7FD38A96E49F0C13ULL, 0xB77D50881E248C10ULL, 0x35795F3192C1CF3FULL, 
            0xAE3D1D3D2190242FULL, 0xBC9E3B445B0B357BULL, 0x857A0BFCFA45DE3AULL, 0x5246F47E1DDF2AFBULL
        },
        {
            0xF5C5B4F962D1BA86ULL, 0x3925266F661956E3ULL, 0x374B39BF78B63DF5ULL, 0xA04EC668A44A1AA6ULL, 
            0xFC7EB98DF9A4F3F7ULL, 0x371693809B4DEDD1ULL, 0xF9F4689499175775ULL, 0x5926956792E39319ULL, 
            0x0B0D5F8B6B265F31ULL, 0x73F4D6589C16B537ULL, 0x77962EB3446715E9ULL, 0x14F533B613CC54B3ULL, 
            0x8D6FE8A83463C973ULL, 0x3D4D235104505899ULL, 0xB2732688CF6F05EDULL, 0xA2D45B319CE2C234ULL, 
            0x81162CBD0A344CEDULL, 0x5F4EF44DDEA43A63ULL, 0x75D76B866132FD61ULL, 0x20F2EF3D2E238263ULL, 
            0x0E913C210DA77D16ULL, 0x106E2B611F11BF99ULL, 0xF332BF7E0C4B260DULL, 0xC99EFE3A0944E225ULL, 
            0xB3621596C39820E6ULL, 0x5A2BFE7BE1728F71ULL, 0xF8C6AE35ABEB9313ULL, 0xC147AE930D0C4CDDULL, 
            0xDB142962C7084E3DULL, 0x2721D0A651D9A7A7ULL, 0xD4627ECD397AD645ULL, 0xF468EE8EA7173B76ULL
        },
        {
            0x673C2127916A2D98ULL, 0xA427EE3A6425FD97ULL, 0x38823D7F05C491DFULL, 0xC6397D39464C6606ULL, 
            0xA38C647F4C11294AULL, 0xC78657B019FAB9E9ULL, 0x0A06A8577AC17CBBULL, 0x6B2C5AE31629E954ULL, 
            0x2F6D8FB0F91FAC73ULL, 0xEB92233FDB5710A5ULL, 0x60083FFED26B8C9FULL, 0xBAB45D31D60A379AULL, 
            0x7D616A413C35FEFFULL, 0x72CC674FC58B2DC9ULL, 0x12D250A3BACF0502ULL, 0x2F229696CF46918AULL, 
            0xA36EDE8D18EA56FFULL, 0x46BE6E9CF7F4DD7BULL, 0xF5A7FA6553032784ULL, 0x8BAB5D6F26EC0AACULL, 
            0xE178BCE646E2D649ULL, 0x4DAFDB8F3CAD27BDULL, 0x67CF47149E70A01FULL, 0xC76C29C91F47AF0BULL, 
            0x8A80A8419BC9DE56ULL, 0xA17536F9B4713E0CULL, 0x53A9753985F7D442ULL, 0x32176EB1F756B5B6ULL, 
            0xC71D32984821BD63ULL, 0x243A4C8A3AA80CBDULL, 0x70B39A94FF1B0BABULL, 0x4F7C9E2EEBBD6F32ULL
        }
    },
    {
        {
            0x64A65B7FED34DCE8ULL, 0xF22BD308A770130FULL, 0xA8B7B25AADBBE947ULL, 0x28C9A2E27495714AULL, 
            0x09C5ED6720EEF094ULL, 0xC2DF62B60BC2397CULL, 0x80B984B90450E36EULL, 0xF3C0E0ECF22D11EAULL, 
            0x7F03F30CF98E5D7FULL, 0x868B760E29A24DDCULL, 0xAE8B319D205CF1FAULL, 0x468B6E412906CC26ULL, 
            0x2522C9EE3AD93938ULL, 0x7291037F8300ED1DULL, 0x21842121168865CBULL, 0x994E6174B07D6B08ULL, 
            0x079098BEF3896460ULL, 0x4F639437BD202696ULL, 0x21E6C50B664180FBULL, 0x890A15502932D525ULL, 
            0x0E519D70BF0D9481ULL, 0x61A1EE7CFF76BFD1ULL, 0xECF4945F28CA8FD9ULL, 0x5EC45EA1FD60E48DULL, 
            0x25E8BA5F33CEEE18ULL, 0x3DD34D0BCAA1FD97ULL, 0xDBF1F5D46AD60E8DULL, 0x71EBFE87B9353566ULL, 
            0x20157B118DDB5081ULL, 0x50D18EB35A28BB87ULL, 0xE826C5B91CD7ED56ULL, 0x28E8E8784972B865ULL
        },
        {
            0x518069C4F2C57C9BULL, 0x78073BA714B64C59ULL, 0xB75A59A10B1F6B15ULL, 0x1856D1DFF1E0E203ULL, 
            0xBD5A8841CFA8AFFCULL, 0x9F88D132CC80FB80ULL, 0xA94F8D2693384E54ULL, 0x93C4E47B03701001ULL, 
            0x5739C708585742D7ULL, 0xB3FDC22518047555ULL, 0xD68480CE11343580ULL, 0x21C665B27AC9D521ULL, 
            0xBBC77224B10841BEULL, 0xCED10B5BD579CB90ULL, 0x565A509CC7B68012ULL, 0xE4482B1E5F6AAC9DULL, 
            0x217CE0AF4B7F1CB4ULL, 0xFE8A4959EFA1121AULL, 0x4CC4E61851D98B3FULL, 0xB57F04355F6206EFULL, 
            0xB57EDDF5A1B6D850ULL, 0xC21DDD45A901186FULL, 0xDFCBFEF053BCAF28ULL, 0xAA7990D2335BABC0ULL, 
            0xE665C7C31D991D8BULL, 0xE114A8B150631B93ULL, 0x31F62FE729BEC6D1ULL, 0xE306A1928D5C4CD8ULL, 
            0x3CB21340094B3B9BULL, 0xFE293A74BFEFC54BULL, 0x98DEF98B23FADB3CULL, 0xD7A347286056313BULL
        },
        {
            0xAAF170D5D3AC26A5ULL, 0x87CB975E71735AB0ULL, 0xB0065672C525C442ULL, 0xA60C5565A5694B6AULL, 
            0x400715109728F933ULL, 0x7A64CE347532D1A7ULL, 0xEA55C9938054BC1CULL, 0xE51FAFE1D910D69BULL, 
            0x0290E593C3C6E9CFULL, 0xB2CAB235F321439DULL, 0x717C33F47418ED16ULL, 0x44D56EBB0AB4156CULL, 
            0xC924979A8602DA8DULL, 0xF499C37FB5B029CAULL, 0x925621C834E301BCULL, 0xBAEEFD3EAC7DD381ULL, 
            0x9A6FAD7B73F24AD8ULL, 0xDCF7788C6FDDFA35ULL, 0xA8E7E4B28EE84E8BULL, 0x414A5F6BFB6593FBULL, 
            0xBD96085092A72D8AULL, 0x0FA446F3E869DBC2ULL, 0xE3909AB6DD57D970ULL, 0xF567BEACECF060FDULL, 
            0x1CF8618B6768824CULL, 0x467D0DDA1D8AE8EEULL, 0x87C1FA238D14F6D7ULL, 0x0416C5A547E4F755ULL, 
            0x219903FD2FE18994ULL, 0xA0A122C77AEDEE05ULL, 0x73791D52129F2075ULL, 0x3B22265C6D7205C8ULL
        },
        {
            0x04F13E621EBBA33EULL, 0xF7E959EEFAF517C2ULL, 0x0CB4215F5909B36BULL, 0x8B5DD6EDBECF0ED4ULL, 
            0x985C9A6C95480905ULL, 0x50295C3613A72868ULL, 0xE8AD2328064110EEULL, 0xAE7F31B5915A38A5ULL, 
            0x78B8A133C2150FC5ULL, 0x4480C9CE1FC0ACD3ULL, 0x785393A48040E707ULL, 0x3182D069C4E2145CULL, 
            0x03D54A1EE3F0F034ULL, 0xA06B87FAD70E605DULL, 0x45C0C11A16624B5FULL, 0x9758576285BFFC4AULL, 
            0xEEB3879CF944158EULL, 0x8D7261FE383156C1ULL, 0x3E6493AAFDB4A77FULL, 0x5DD16168722F51F0ULL, 
            0x4A3967B063DD5FDCULL, 0x06CB3169A9F8935EULL, 0x7A5BA36BADB3CA40ULL, 0x4C156AA25C221C71ULL, 
            0x2A29CC61CE1A38AAULL, 0xDE31BA46D74B9EFBULL, 0xB0A7D25775AFA0D0ULL, 0xC7C9A34D18110CC6ULL, 
            0x3898A062F39A7B7AULL, 0x5E40D76F3F75CB6DULL, 0x99BBF9476D2C93B3ULL, 0x7ACBCC905C04C80DULL
        },
        {
            0x94329510488CDC37ULL, 0x98BD16A9BD204BDCULL, 0x3FC2DB5AADCE638AULL, 0xE8212559D6D0F5C4ULL, 
            0xA362D803D33AA876ULL, 0xF8FBF48EE914C2C2ULL, 0x81F998A1952FEE16ULL, 0xC367E2B52476069FULL, 
            0x6C5649CB9D9F4C96ULL, 0x8642EA963643673CULL, 0x120BFAADD83CFBFDULL, 0x0015523B915CB67EULL, 
            0x97521C666522EB15ULL, 0xC5ACA88C80F9CB2FULL, 0xEB70BB960EA441A7ULL, 0xE65EAD2F152D627AULL, 
            0x059DD5C9A4B4B830ULL, 0x1872800E32B06643ULL, 0x79C52E49E5F02994ULL, 0xB1626F3F9C60D775ULL, 
            0xC8B4C9312EFE0457ULL, 0x3190F5ED5D4394D1ULL, 0x6FAEA4B738C05305ULL, 0x0365FA0ACB8AD961ULL, 
            0xA1C95DE54AE490DCULL, 0x213E592D5AD28F81ULL, 0x2FE1058D3F49C969ULL, 0x5366CCEC84A99FD9ULL, 
            0x2830EC09C7702330ULL, 0xDA3AF2317EFD6C51ULL, 0x308522A6D7F18447ULL, 0x807EA2ECD3CA525AULL
        },
        {
            0x0DC2076F6A29FAC1ULL, 0x6ED8869DA6057665ULL, 0x36DBA6498845EAE2ULL, 0xC0D168F812CE8DD8ULL, 
            0x0C8E5C8609960832ULL, 0x33E2381789EA2F89ULL, 0xA7B158C0D8899F9CULL, 0x3AB141BBF4207640ULL, 
            0xBFE16F945003C534ULL, 0xC86C7CD84599A7A1ULL, 0xE639239990BD9BB2ULL, 0x0B94B6741A420943ULL, 
            0xB42DEF076E6AE871ULL, 0x9CC62E6CEE45816BULL, 0x29CF593FF6E45C50ULL, 0xB1D6BBEE53736CFBULL, 
            0xC8906B9B79A1B905ULL, 0x64E9E67EB7A15FACULL, 0xCADC3D965A5547D8ULL, 0x5110DAC27C01F24CULL, 
            0xF49F111469358424ULL, 0x08C9C9D4ACB64972ULL, 0x1196DF9AA5F2BA3CULL, 0xF004FC71F2250173ULL, 
            0x8EE04A84959BBF0AULL, 0xE35A821F86669902ULL, 0xD15CE3A3E2B2A507ULL, 0x1AA2C564921ADF62ULL, 
            0x78CE5661FC0DBA85ULL, 0x47A77365D4997077ULL, 0xB99F68AAB3FDC711ULL, 0xB9DDEFD7524FC40FULL
        }
    },
    {
        {
            0x5662D2E990AC27F4ULL, 0x68DB9B8D3AB5851DULL, 0xFE43D8E41D757E16ULL, 0x03B0B4795CD1E3CAULL, 
            0x97BAC32250913C3BULL, 0x1A99AFA58997F432ULL, 0xDD326EA21C187BF4ULL, 0x2D1EF201920BC71FULL, 
            0x11E80CC3AF0A4658ULL, 0x8F51F6E99565F465ULL, 0x7E95FF4F596C86A3ULL, 0xB25A8D2ECAE02F5DULL, 
            0x73B13972FBE42F0AULL, 0x7A2C26A920578443ULL, 0xBB4B7D227E6DF986ULL, 0x551725A2E3FA2F5CULL, 
            0x07E93C48F34F0A3FULL, 0x5AE3C38805AD33CDULL, 0xD6A34C7FB9BB5816ULL, 0x70DC6CDB1D9A476EULL, 
            0x61636C6257CCEE54ULL, 0xD968256421CA866BULL, 0x497DD18B523DFF53ULL, 0x202C10DE49C26CD5ULL, 
            0x7E5AA20C9A919121ULL, 0xDC19A7E5BE516B74ULL, 0xBC34269063E80D76ULL, 0x2EA2038B0421726CULL, 
            0x1F8756B4F1A05D7FULL, 0x406FABF159859066ULL, 0x6F42F97F661C03FFULL, 0x1D4802D8A2BE2ACFULL
        },
        {
            0x1B7ED871D875AA7FULL, 0xD09CCD1613FEE5ECULL, 0xB678EBD8B05F27F7ULL, 0x8BA07BDE9487490DULL, 
            0xB4FD6C28822071CBULL, 0x7970E850BF9E6AF6ULL, 0x142A571CBA869D3BULL, 0x6CC4D1FF4334E4EAULL, 
            0xB3CA1BCE42817B1FULL, 0xB94D50A45DAAA735ULL, 0x80A7128BC77830EFULL, 0x787262606E0FA82AULL, 
            0x7A3364C93E817139ULL, 0xCB20806B0E3E9219ULL, 0x80A4168FCF42E8B0ULL, 0x949DD4AE1780146CULL, 
            0x9A8A4DA809E02073ULL, 0xF6B0A960F31CD66DULL, 0x88066576AD710D11ULL, 0x864962FD0B59CC45ULL, 
            0xF3F372554A0D0643ULL, 0xB9DC4FFEEE76B412ULL, 0x8EE0FDA097AF3456ULL, 0x703CA23445E492AEULL, 
            0xE35D325CD1E3977FULL, 0xC06A1030846B1968ULL, 0x7B58CB7A95669956ULL, 0xA24F947CC768A1BFULL, 
            0x873879DCC37EB887ULL, 0xA9EEB0ECC5D8D9C1ULL, 0x285225F2F834E52CULL, 0x723C6E7B0BD3FBBFULL
        },
        {
            0xBFA83BFEC5E28C0CULL, 0xA5250235121D12FBULL, 0x7EED7FC4B8AE7D70ULL, 0xE46EC88C533B696AULL, 
            0xA73A36A0AF1909E6ULL, 0x94A947C3606DE6C3ULL, 0xBC1A1E5824D15CA6ULL, 0x88137A3EDA10F0A1ULL, 
            0x3E4316EF1FE9ED79ULL, 0x70D8D72EDD0A5AD3ULL, 0xB243FBAA94F4CB66ULL, 0x976F45395F3181C0ULL, 
            0x29A3033680A04B24ULL, 0xA23D8E9397EB46DBULL, 0xA2CE231533942F68ULL, 0x27E6599CDFCC8C11ULL, 
            0x02C906163BA147E5ULL, 0x7BF93B752573C10BULL, 0x5FA3B944CE3BB2A5ULL, 0x9764DC595774EDFDULL, 
            0x8ABF3D911198F8FCULL, 0xA4C49F09C138C95AULL, 0x0396D4D3D9FDBC76ULL, 0xBF2A9AE496289D03ULL, 
            0xE2523408A08AD584ULL, 0x6B6813DBDE9AC748ULL, 0x0AB78BD1DE40D911ULL, 0x5ABCE24D5CE5DDD8ULL, 
            0x9D93E52C8B3A9996ULL, 0x6250A7C83836720CULL, 0xD12024AF12EEA7DBULL, 0xEC997FCB454646A0ULL
        },
        {
            0xC8F84DC53727BDF9ULL, 0x18F805D9BD202044ULL, 0x9ED4C5EB7804290BULL, 0x49262E9E1AA5B790ULL, 
            0x397F8936A3878F47ULL, 0xAD89655E79B3139DULL, 0x57F908BA69E1CA50ULL, 0x4A3F8B4DE9DA4273ULL, 
            0xC2C65B0B136FFA4EULL, 0xFDA3C9C2EF19CCFBULL, 0x630976A9DAAA7810ULL, 0x2AD543BC2CCF6D56ULL, 
            0x70461FF4BC5A9C1FULL, 0xB0BE794EC9ED7899ULL, 0x8613D3062D9F0F6EULL, 0x9D7124F59596AC0AULL, 
            0xD3D8702818C62795ULL, 0x5878DCBB260811D7ULL, 0x6CDEDA5BCD75D6F1ULL, 0xA4A8178DE26B51D4ULL, 
            0xEDD38268A7534A51ULL, 0x6455235A57E311DFULL, 0xFF616BB373E98F86ULL, 0x3AB0F7084AE15CCCULL, 
            0x65178A7D333E1016ULL, 0xE8A3D5B8B1355186ULL, 0xEAE2B6BA9127DC97ULL, 0x1C9FF2BA1B0DAA88ULL, 
            0xD565B2859F0B8231ULL, 0x40FCC36506F64606ULL, 0x2C105298C0140284ULL, 0xE535DA127F30A8A8ULL
        },
        {
            0x2593E29B3F022AEEULL, 0xE47F77C23F0585B3ULL, 0x1DD42225BC805B54ULL, 0x5337D622C928384AULL, 
            0x7E710E2B2D4F52C5ULL, 0x1B8DDD19163406B3ULL, 0xA9CE9C0D701A4A8CULL, 0x464C0F59C7772F1AULL, 
            0x0FFA388273481428ULL, 0x49166B57BF2962AAULL, 0x9621CD9371A90765ULL, 0xCDDB26E43B3250E9ULL, 
            0x1320AA0F0DA2EE31ULL, 0x7ACD59DDD4221F06ULL, 0x3121A7F1C34386CBULL, 0x1AC531282508E550ULL, 
            0xB3C0750E989E347BULL, 0x2C150B66CBEA5D2BULL, 0x0B63E1BD7FD7C682ULL, 0x53BDF164728B57FDULL, 
            0xC3E7F4CA3BDB4D86ULL, 0x0EDC881A70B904FFULL, 0x0C0A0EEAD671BB27ULL, 0x6C6356BD9D68B838ULL, 
            0x393635242294F62DULL, 0x109C6597A3D8E7B2ULL, 0x6E807B21850535DAULL, 0xE1919392832B8008ULL, 
            0x8429F79DD2B82EBFULL, 0x8CFB5A2AE4575AFBULL, 0xB31A2172AE9F8880ULL, 0xB21D68D5BFF28DD1ULL
        },
        {
            0xAE473B9788812ABDULL, 0x1DC178C53CF377B8ULL, 0x6338CAF7BF928AFAULL, 0x90F1648B850B59A8ULL, 
            0x7AFBA362E979732DULL, 0x06E3FEF0C50088D0ULL, 0x141F7220E5D0E8A5ULL, 0xD68B40E8209800BEULL, 
            0x8FF12D3875AB149DULL, 0x4641D3B5F9AE9852ULL, 0xB36BEB8FF9EDB711ULL, 0xBE7E265363E4BA64ULL, 
            0x989D0F6A184A6C99ULL, 0xF428F16400D96215ULL, 0x7405429BBFDB79E6ULL, 0xEDD402F956F411E7ULL, 
            0x3A00D9EEA48024C9ULL, 0x0DD06FE4BFB1987FULL, 0xDC139D861EECE096ULL, 0xAA3840DBF2335F4FULL, 
            0xBFD36A424B02CE61ULL, 0x29F4C235FD664F68ULL, 0x07F430AD401414DBULL, 0x44C7D878303A9F72ULL, 
            0xFEBD42D80642920CULL, 0x61ACBFB36AA6A261ULL, 0xE200EA2FBBF2FDB9ULL, 0xAC7C755A6FE55973ULL, 
            0x8FA58790387F962EULL, 0xE68E98D907F5BF38ULL, 0x7A1487040D440EA0ULL, 0xA82E9CDFB446A4D1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kSeedConstants = {
    0x486FBB49C03FD84AULL,
    0x08D6EB3CBD6FA788ULL,
    0x39BBC92ABDB242D2ULL,
    0x486FBB49C03FD84AULL,
    0x08D6EB3CBD6FA788ULL,
    0x39BBC92ABDB242D2ULL,
    0xE4683D2E1D72CD17ULL,
    0xD1C4BE144DF90AE9ULL,
    0x50,
    0xB4,
    0xD7,
    0x35,
    0xDC,
    0x07,
    0x63,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Pollux::kTwistSalts = {
    {
        {
            0x7E918B88BF96D3C0ULL, 0x0B1102BF75DE6673ULL, 0xB071A68F4146295AULL, 0xFBD75C0E35275329ULL, 
            0xD0BC34C8E3E5D35AULL, 0x8D6F48D13BA72EDFULL, 0x6CCD5E15E1CAF5F5ULL, 0xC4EBB34B7FCF7140ULL, 
            0x4A4577452C0B753CULL, 0x8C4873D3223ACE1EULL, 0x0027B5879E32B883ULL, 0x689E7972BCCF1A10ULL, 
            0x876CACB64909676FULL, 0x4D03365969DB1083ULL, 0x6B788E3137CA9C84ULL, 0x470F86F4E7E500ECULL, 
            0x1D1938B80D36E5AFULL, 0x646B466D9AEFDB92ULL, 0x09F0A6C6BA91A986ULL, 0xB25CF05262B54347ULL, 
            0x8B92CB77C3CCBFC3ULL, 0x74AC0D03E5D957F0ULL, 0x172361EE95F4022BULL, 0xA957C86E689A167EULL, 
            0x8E1B57A3E4B1608AULL, 0x273CC0910FBFBF45ULL, 0x3A48BD05A4318EB9ULL, 0x85169D250193D633ULL, 
            0xC22AF714E4E4939FULL, 0x3E24E42D46D5C6A0ULL, 0x119CAC93B60DE01CULL, 0x2563E432C4DE77ADULL
        },
        {
            0xCD2CA14C4DAB371AULL, 0x0491410E91E0B7B1ULL, 0x54D723C5E571A351ULL, 0x67D58599A74E85C2ULL, 
            0x2440C711E113F8E6ULL, 0x09B7DF1762B54E30ULL, 0xFCD97779566F3289ULL, 0xCC1D854D9AA4929EULL, 
            0x7D8A5C0AAE2BD34FULL, 0x4946F02BF0B063D2ULL, 0x0DD3A6C8EC9B8A3AULL, 0x3AC7D529A067A7F1ULL, 
            0x044853FED450851FULL, 0xF1E96695817EB148ULL, 0xC5A84903D3D1E6C0ULL, 0x7E390E8EDB5899B6ULL, 
            0xEDB2E9BD3D59E8F6ULL, 0x34CD379F6DA2916EULL, 0xEA75931B5E5FF552ULL, 0x794496642B1D8AC0ULL, 
            0x111D9BCBA2C6F2ADULL, 0xC4B4A912334AF3C6ULL, 0x553A97DDD9C3B30DULL, 0x52E87A698DFDCBDBULL, 
            0x6FF3C47C2EC08964ULL, 0x4AE04A310EFAAFE0ULL, 0xFE276596593F818FULL, 0x1BF7356D695337F6ULL, 
            0x06365405E1C183F7ULL, 0xC502A4653D2BCD80ULL, 0xF21A1FACDCFFFDCDULL, 0x7EF5E680DF14577DULL
        },
        {
            0x799D1FB689C27AD5ULL, 0xB1F2418BB052F3C6ULL, 0x7756737EC721490DULL, 0xBC9649622A6A6198ULL, 
            0xFD2DD670C04BCA32ULL, 0xCDD3BC707671AB90ULL, 0x272ACACE00FB31DEULL, 0xA504915254F919D7ULL, 
            0x84EC216F0290CF70ULL, 0x686C2AB2E7B73F32ULL, 0x38B48D4B6BE715B3ULL, 0xC096325000E2175EULL, 
            0xBBE4D8F24DAF93BCULL, 0x5297CDB8B10019C1ULL, 0x3E58885938B01ECAULL, 0x91EEB14CB1DD7C39ULL, 
            0x1EA8354A7C3C24ACULL, 0x525E1CDD950762E0ULL, 0xB1E42AD3805E1177ULL, 0xE8AA0A882E868881ULL, 
            0x2E308ABAB7799BECULL, 0xFDE7E9FBCB2E062EULL, 0x0B3EDA5F0A69A58BULL, 0xDAB821DF22C8364EULL, 
            0xBDD9CD7D755438FFULL, 0x267CB8CD475E232FULL, 0x084A69AA89661A35ULL, 0x42B2F7876CE1F859ULL, 
            0x2B17F7DB526D487DULL, 0x5D1AEA668A6F00C5ULL, 0x1ED9077CC4A52989ULL, 0x31677D83E3568C81ULL
        },
        {
            0x35B03E12A79F200BULL, 0xDFA6B35E153902D0ULL, 0x1B5B9F7F99ABEA1EULL, 0x85704B87FAB5146DULL, 
            0x64E61E98F8DED29BULL, 0xE67168A971A3339FULL, 0x8D2434803F8B53D5ULL, 0x31B7F6DF15D9A37CULL, 
            0xA6218982E4E8D5E9ULL, 0x054BA6D1A95D3FC7ULL, 0x155CDB3EB280030CULL, 0x5E2324D15CC799C5ULL, 
            0x89FFF93A14476D88ULL, 0xD84D7C108585C366ULL, 0xCE0CBFE02EEAD23CULL, 0xF59938B4375948C4ULL, 
            0x7DD8073DFD523324ULL, 0x28893147CE4D2913ULL, 0xBF853078747EEE5AULL, 0x6EC20616FCB35A95ULL, 
            0xD62D262C32EE888BULL, 0xD2758B116B442A6AULL, 0xE3811AABB13355B4ULL, 0xAEC6FCB8DEDAEDE5ULL, 
            0xAB8E85E9BF274D15ULL, 0xC0CBDED004128D5CULL, 0xD34B638499575AF6ULL, 0xD7900F2F437B809AULL, 
            0x69D69BC1703A0A48ULL, 0xA475CA9F2EA89345ULL, 0x2B0669323170BF9EULL, 0x24CBB5D8A8E5CBB6ULL
        },
        {
            0x6589DC6BB5E84A79ULL, 0x9FEB1EE75C5F5A1CULL, 0x8CBC53006D661928ULL, 0x33F038B22100B39DULL, 
            0xEAD9D8F973C9B61EULL, 0x053BE093D805A8A9ULL, 0x30A9AB713D5AB69EULL, 0x3E75E370B93C8E10ULL, 
            0x4820BE054C7F2B52ULL, 0x16A7B08707C0040DULL, 0xEBFCD5B10AFEBD43ULL, 0x51B61C2240A11A43ULL, 
            0xE68EF33706C9F44DULL, 0x6BE91D6411A2CCD6ULL, 0x76E6C2D85AB988E0ULL, 0xBA265531B5A5844BULL, 
            0x597E0F37E7AD5F01ULL, 0xCA0ECE16F1BC3A4CULL, 0xBF841583DC4B7550ULL, 0xDE15ED37ACD29BF2ULL, 
            0x0B6C57E76CA15EABULL, 0xD6A7C2A9F515C9B4ULL, 0xF4E3834B6746B2FAULL, 0x810E17FF4F9A15F0ULL, 
            0xB58549C61D41093CULL, 0xB614479D2EACA5CAULL, 0x31A7221218413F38ULL, 0xEAED222F8293F30AULL, 
            0xB7AD64E4A2EB5746ULL, 0xDBD022328EAA134CULL, 0x36ADDE584A872604ULL, 0x6BC01F53BE8AB58AULL
        },
        {
            0x04C4E6305C82EA67ULL, 0x695F422E4840B37DULL, 0xA429EDBC8CB65E78ULL, 0x2AFC1AF7BD24D42DULL, 
            0x1372274D77350D0BULL, 0xA95B9AD993887DE8ULL, 0x40BF5F03319DEF80ULL, 0xE716736B1C87FA9FULL, 
            0xDCB7CD9AFDAA76F1ULL, 0x205107D38755D93AULL, 0xD885F17D593063EBULL, 0xDB16D5B3511C8D7CULL, 
            0xF40CF4C3C4BA91BAULL, 0x8DFD3F83439DBD2BULL, 0x8687AB6522B0CF19ULL, 0xDB54BD9F97EE36BDULL, 
            0x6C468B36DD968E05ULL, 0xFD082E027069A823ULL, 0x2FEA655A8B5413EDULL, 0x1816EC317BEE49ADULL, 
            0xA04C5DFF8C9F5882ULL, 0x7067EF5830AF26B2ULL, 0x9891417690B8587EULL, 0x7EC2324888C075DEULL, 
            0x6273088BEEF8AB75ULL, 0x2BAC9E25E04FC003ULL, 0x30B1CE601BEA2BBAULL, 0xE9C1A11E2C4C80D1ULL, 
            0x0634675DBE2E0391ULL, 0x0A9E8E50FCA1F0A0ULL, 0xC408CD5258B1212BULL, 0x290EB9AE1054B2CCULL
        }
    },
    {
        {
            0xDC165A6A9208D99FULL, 0xDDC884CD6C51B14AULL, 0x791D2131B776248AULL, 0xD307F96DA638DA5CULL, 
            0x4B8049DBEBBA5A84ULL, 0xC623427F74BA9CB9ULL, 0x76D783D374C2F228ULL, 0x3F3BA778CFBDC421ULL, 
            0x0C8C91A0F1D0F13AULL, 0x100529FB1CCE7F31ULL, 0x49866F6A94FA9612ULL, 0x1CEEB819ADDEE73BULL, 
            0x9CBCBA9D0973D42DULL, 0x1EA9B7F20221C4F5ULL, 0xF8E8C526A0643F28ULL, 0x00BBC5C7A1B0AC8DULL, 
            0xFFD6FD4962BFD7D2ULL, 0x287B35B96FEABE87ULL, 0x21F48FCA2485288BULL, 0x9BD0F42290B94D40ULL, 
            0x23DD35F72F1FC6DCULL, 0x1F1E3E228E2A595BULL, 0xDAECBDFFC4FAAF96ULL, 0xD246F4E27DD34DA5ULL, 
            0x464C76243EFF60D0ULL, 0x77A899977B961A21ULL, 0xA05356D65EAC3D66ULL, 0x378662DF7F7D7E60ULL, 
            0xE9079E370885D3D4ULL, 0x733D60F2B5F2FC2DULL, 0x6E5E62E16F7D6621ULL, 0x0C7C6AAC5FAD596EULL
        },
        {
            0xA43263FED2AAECCEULL, 0x4BA2A052C11D7F7DULL, 0x46470F00A41409FDULL, 0x4C0423EC33936D08ULL, 
            0x80D5CBE37471A6C5ULL, 0xB2982A585F39582CULL, 0xCF508B1F73A5A1F6ULL, 0xF337EF195ACCE37EULL, 
            0x8D3E906F9DD8361AULL, 0x50FC9F5FC987A9C7ULL, 0x4D99544A9459C498ULL, 0xB62412992B8E4612ULL, 
            0xE61F1EFA72DB2285ULL, 0x1BE175DA5414394CULL, 0x82325794E0035A84ULL, 0xBC161D6E5043A73CULL, 
            0xC4BE3C23DCE55834ULL, 0xDDAE8F64E5B01E7DULL, 0x56209B0203FE2E9CULL, 0xBB3066C74F7D9CB6ULL, 
            0xDB4195FC1A0D5875ULL, 0xD8343409D333F550ULL, 0x47033AA69F161327ULL, 0xC722D73042E5233DULL, 
            0x375CA1B054B69A23ULL, 0x1C501E5EAF81C9F8ULL, 0xFC2D450EB65E813AULL, 0xBE2427106B368DD5ULL, 
            0xA170A8128BD1603CULL, 0x296FEFC2789BCB12ULL, 0x3EC7516FA653D955ULL, 0x42B2777ADD19A655ULL
        },
        {
            0x375541CB161666F7ULL, 0x3369F4F256B36145ULL, 0x4B55B5C0B1C75501ULL, 0xD8A13E11DD27C3F2ULL, 
            0xE58DEA1BD9450891ULL, 0x4935C6F695522F33ULL, 0x618B7D103E3FEBB3ULL, 0xE6876B7774AF44D0ULL, 
            0x5C4EFEC4C588AC6DULL, 0x297122E2091E5DA0ULL, 0x866CFC76E4A67D0FULL, 0xC496F62686D48D58ULL, 
            0x654600C70639649EULL, 0xFFC9889509FF2C45ULL, 0x5468BD88978D2931ULL, 0x2062A8BD696C3E1BULL, 
            0x9CEB4E1181F792D4ULL, 0x242D32A37D8CEC11ULL, 0x71B0FD0A823361B0ULL, 0xFD7851F8C9294D1BULL, 
            0x18D541177FE6D6C1ULL, 0xD67528D1FD8E2F2BULL, 0xE4A6F9B9BC19A92DULL, 0x2CE066DF9C8D0615ULL, 
            0x5849B92875AB2190ULL, 0xBAE5205039DB9767ULL, 0x41CA85293BFA1B19ULL, 0x23921A75EDD71CE7ULL, 
            0x99C4682F8A95F5B2ULL, 0x9694893A3813F179ULL, 0x0E8554ACBE3D18EAULL, 0x130C0677ECBD0627ULL
        },
        {
            0x4AEE5A40CEF5325CULL, 0x76826C1F01DA6A13ULL, 0xC165B63B9DFBA6FBULL, 0x95A11E2E5D7E7892ULL, 
            0xC07379B6719EF48AULL, 0xE3F3E94DD7E82CC4ULL, 0x1288E6477BDFAE42ULL, 0xB49D80494D81F89BULL, 
            0x789B1166B9A41791ULL, 0x0BEDDDC7BAE807A9ULL, 0xC21F9EC1055177D3ULL, 0x3FC3B51BB060725FULL, 
            0xF617E514381D6800ULL, 0x0236D8B28DC62BB9ULL, 0x6A6A27CD47E24C72ULL, 0x9E956D1517043EFFULL, 
            0x05B410A438CB2803ULL, 0x2BF95F5AF9D172C3ULL, 0x6051A53A46B8CA71ULL, 0xED12ABB3D0AC1376ULL, 
            0x16F9919F154CC4CDULL, 0xD819216886AA307CULL, 0xE9ACA82877CC1210ULL, 0x09107B25A14AC57BULL, 
            0xD1C0E7D3A6E2D909ULL, 0xD2BE867A2DD88731ULL, 0x01C5ABF40AC2E20EULL, 0xB1848AEBD10B4FB1ULL, 
            0xB9D9FC543516C043ULL, 0x31C738D5CE60B3EFULL, 0x2D2B11655E2C51A3ULL, 0xF9A28B770924EA71ULL
        },
        {
            0xB4A2CF76A7B8AB7BULL, 0x0B94623EA5DFF7C9ULL, 0x538785D7B88728DCULL, 0xC26CD4809022B3AEULL, 
            0x629066730881AB67ULL, 0xE2AB26159CE78FC0ULL, 0xA62E21696D7E36CEULL, 0x2F694B8EBDB85EC7ULL, 
            0xBBB65E0FC660C577ULL, 0x5785C5EDB8CEE1EBULL, 0x0A355AB5EE5E28D4ULL, 0x024F59D3A300D4C7ULL, 
            0x1E270849A89EA1D9ULL, 0xD6C52D535AC6E4F7ULL, 0x98BB31D37D73830DULL, 0xC6B73A4F249565F0ULL, 
            0x64B19B8CE567F226ULL, 0x33CF3E74B1D90D7DULL, 0xE392C4492F801D28ULL, 0x8EBD9B6186A8023BULL, 
            0xE709EA9426A86A3AULL, 0x5DE36DC086C204ECULL, 0x1F54F591B49FFA75ULL, 0x1A39D5172B89244EULL, 
            0xECA071929A8DE7A3ULL, 0xF308BE035B766EA0ULL, 0x86D18250EAF280CAULL, 0xAA81C38235ADC1C1ULL, 
            0x6A1D519EE7D1F75AULL, 0x57376F4F6DFA1431ULL, 0x0685E27F46BCAAC4ULL, 0x6B90DFD850768C22ULL
        },
        {
            0xA0D4DF9C582F5E99ULL, 0x2564740FF75F5520ULL, 0xD2E846F762629FF6ULL, 0xA82D888C033A8B13ULL, 
            0x57F7C113A049AC3CULL, 0x7318B405FAECA08AULL, 0xB6A50E1F0AA295EBULL, 0x40FDB6AB99F33A60ULL, 
            0x8E243C7F6D790519ULL, 0x002F2F716964565EULL, 0x22344B479103409FULL, 0x45034BA8801B53D5ULL, 
            0x4386335ED081F45EULL, 0x728814AED3B21BECULL, 0x548184E7410EFF13ULL, 0xDC57A0D15081B27EULL, 
            0x75F6D6B6182AE87BULL, 0x46766D4987BF93A9ULL, 0x60C20414B9E63DE6ULL, 0x93683B4CB1EB5EDAULL, 
            0xF89E0B4B8BBE544AULL, 0x7F343F1927126C6BULL, 0x85E218FECEFF491FULL, 0x6D8169884FA89087ULL, 
            0xDB1BE3614EFF8739ULL, 0x8E9143C1C60AC7C8ULL, 0x60F1A3108E9BC510ULL, 0xA1594510B81DDE93ULL, 
            0x1CAF619F956F41AAULL, 0xDA8A8AA5E0C42DCCULL, 0x81125195A90B002FULL, 0x6375E8FD5ACC7E3AULL
        }
    },
    {
        {
            0x37CE8111A7D1F3A2ULL, 0x0602E87FCF37B1E4ULL, 0x84E96F37D8C0E7DEULL, 0xCC210D8D812C7E38ULL, 
            0x2D2A49471D3565AAULL, 0x8C1D854C71A35442ULL, 0xF941262D7738E346ULL, 0xE8D3E6D28EC61E5AULL, 
            0x7B5BB16C25D990B2ULL, 0x429979BC22621714ULL, 0x4017CD3940F39F6EULL, 0xD8937521C0048D1BULL, 
            0x0F3321A30A86EA2AULL, 0x8603382FA3BE9ABFULL, 0x1801C7DD81EFD68CULL, 0x379F4B8DA3D3BBAFULL, 
            0x625C8C938F6B8503ULL, 0x29B16235989979CDULL, 0x21EDEEA0BA9A6F81ULL, 0x0A2F116C40AB6E87ULL, 
            0x44BF7961686A3740ULL, 0xEDF413A7A1F35E15ULL, 0x364F2A38A04B6DE1ULL, 0x35BEC4455D48BF50ULL, 
            0xC8A9CC6188861587ULL, 0x11AA3B8FB3BDE5F5ULL, 0x98FA6BFE3CCBBF55ULL, 0x06FD242E8BFA90D5ULL, 
            0x2FB70BB4D936EF19ULL, 0xABDB65FBE83E6C85ULL, 0x2CA5748297B488C8ULL, 0x0BB6C6F116CD8DB2ULL
        },
        {
            0xC0784052FFD25012ULL, 0x319AFA001AF28DA2ULL, 0xD1E79AAAFD7FFD04ULL, 0x0D6219AAAEA0BFF3ULL, 
            0x0E73A7D5A761AC43ULL, 0x9E7689F83B07001DULL, 0x91AB78BD7A9F1A8FULL, 0x865DBFD65824A1C5ULL, 
            0xFF51C831F11DFCC5ULL, 0x2ACF956C87C7D5BCULL, 0xD5A06FC8171BA348ULL, 0xCABDEDA358EDC916ULL, 
            0xC51D2E6C55B121DAULL, 0x28471B0D102ECA95ULL, 0x935F05418E34B7F5ULL, 0x720A72E592170FBBULL, 
            0x662A23B51F61A869ULL, 0xAFB4A87792293912ULL, 0x901482AD1DBB0B1BULL, 0x120A3AB5E1B4F2B7ULL, 
            0x3256355124276876ULL, 0x65C613F1DB5CBBB6ULL, 0x47D507C5DE88FE97ULL, 0x0CDB048C9E68D022ULL, 
            0x8AD476F930F37D70ULL, 0xFD5FD74708F44ED1ULL, 0x50AB23FA16ADDD98ULL, 0x74558AC3B2AD40D4ULL, 
            0x8D4521939432980FULL, 0x191DA121A3CC77D5ULL, 0x51505EA7427D9387ULL, 0x9C91640B82B972B7ULL
        },
        {
            0x2255828EDDCE05B9ULL, 0x520DCAE9B5998421ULL, 0x51DAB0181CF2E544ULL, 0xA9F21A7E42AA74C9ULL, 
            0x2E1143FC6C9EF97CULL, 0x0DDF14F8495CE812ULL, 0xDA9914C80C059BC2ULL, 0xFAECE4EC1B8E99B9ULL, 
            0x7053E4339D380B7FULL, 0x19168FCCC3A29C34ULL, 0x4CE3F6DCFA81CD31ULL, 0x13788391E31966BEULL, 
            0x0FB1C94256E11AE2ULL, 0x5FED5B832B72AEF1ULL, 0xC76935BE4BEA809DULL, 0x75FADC6CE5E36F72ULL, 
            0xECF84774A76A1102ULL, 0x441486E29C690DC0ULL, 0x20AB5DA851DF99CEULL, 0xDE77705AC90AE02BULL, 
            0x3AC206D6524D4297ULL, 0x0C10DCA39308DD7BULL, 0xBF32C0DB95FF0CDDULL, 0x6CBB6512765E4336ULL, 
            0xFDF73C1A2B86F8EFULL, 0x9285A2C4A213AC40ULL, 0xDA4FC39B1DAE7950ULL, 0xB3D64B394140CD75ULL, 
            0x21BDB459E2B619FAULL, 0x63F15DCDBB6CCEFEULL, 0x78FA6C6940BA438BULL, 0xC7C817E83DFDB521ULL
        },
        {
            0xCBB48BD051F1C21DULL, 0xA5800DBBD1950905ULL, 0x4E1E2637F8C54765ULL, 0x82122EF6321459D2ULL, 
            0x7930BBA6D557714CULL, 0x3E1B4FFE7C946DAEULL, 0xB2C80D1B8FA65902ULL, 0x9CFCDECD518E7F83ULL, 
            0x280C372F8E5532FBULL, 0x808F20C524B9F60CULL, 0xECD66878FC5E6417ULL, 0xFC1E327FF14440E4ULL, 
            0x222E17168FD85766ULL, 0xA97E6BC08C095FABULL, 0x92BF40A0BC12445CULL, 0xD716DFA00FA09364ULL, 
            0xF3A314E810EBB0BCULL, 0xDA75D754EF6AABB2ULL, 0x1269D63700AB116EULL, 0x9C75EA38F9EEAC3DULL, 
            0xA88ABC9BA5A1A76CULL, 0x106819AF5E6D7998ULL, 0xC7EF8A1EA7D52A0DULL, 0x3A76A6773AFB22C0ULL, 
            0x6B3D190BD6A7EA0BULL, 0xB11FF9832B44508DULL, 0x5D3DD56353610730ULL, 0xF4410B8C2CC7AF5DULL, 
            0x65D6C92571E73A44ULL, 0x9209CA6E878E3DA8ULL, 0x8FDA12757EF4E77EULL, 0x4D9EDACA001CA1DDULL
        },
        {
            0xC84F8E323FB2FF17ULL, 0x60EEFD2AEEF4A63FULL, 0xC156CC612A2C2BACULL, 0xEB955F05BF34CC96ULL, 
            0x36B0572AB385617FULL, 0xEB19E14EA1F4EFE8ULL, 0x7CCE6F54D047A121ULL, 0xFCFA9841239587F3ULL, 
            0xE8A1D030FE676C84ULL, 0x6DD006E791AB2930ULL, 0xB6044B9B5CC1D25FULL, 0xB94433281F909908ULL, 
            0x59AFF2C46C98809DULL, 0x80073D480FD0940AULL, 0x24E8FC5CB677B9E9ULL, 0x17A1FB58B62AF241ULL, 
            0xE9EEB5AEF45A06AEULL, 0xA90F764C0182C63EULL, 0xF075CCE4F1DB1170ULL, 0x792937681B047610ULL, 
            0x098F72665965F699ULL, 0x5514203E022E5F48ULL, 0x4AC9DF78BB120178ULL, 0xD17EC4A182AF9004ULL, 
            0x52C36F86E140EA22ULL, 0x4E8BA2E0C50C8B52ULL, 0xF1726442BE2D86E4ULL, 0x4B148BB524AFF0B1ULL, 
            0x66DC1009A1B70773ULL, 0x9E1E84D37F8A0FC9ULL, 0xFCDC1E4484F0D631ULL, 0x914AAA063F27E503ULL
        },
        {
            0x656B983502B1C70BULL, 0x79BCDA7212414C66ULL, 0xEEFC0E5592392B64ULL, 0xEE3539BF4DD34A23ULL, 
            0x693D5F1211B46B5AULL, 0x824A1089E94D26A5ULL, 0xABCF12987323070FULL, 0x0EFD0328D32ECF8CULL, 
            0x54B130DAEDDC33DDULL, 0x5F75C9793E9EC9F7ULL, 0xF39B391207322BF7ULL, 0x268CB62511FD78F3ULL, 
            0x954E81A8F22E8CC4ULL, 0x0F853818C26EDAA6ULL, 0xE8526486EEE01D33ULL, 0xA9A016814A6B2D8BULL, 
            0xE55AF6F5C04FA5F4ULL, 0x1BA4AAC632CDFFE9ULL, 0x728C52DB17802A1AULL, 0x4D5C2074553CB55CULL, 
            0x59361F037F3CE278ULL, 0x820C47256D36EE94ULL, 0x3DB9663B96245EE5ULL, 0x980A35719613B4E5ULL, 
            0x6109755C6D82C28AULL, 0x8D0FF45184E0565CULL, 0x1BF957D8B683BACDULL, 0x7E23F2EE9659488DULL, 
            0x747D9550C9E333F7ULL, 0xAF698FA632B1D4DDULL, 0xE2B7F94707C8022FULL, 0x2B7399B46A701014ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kTwistConstants = {
    0xA85CBF291FA6EA22ULL,
    0xC0A6048A49393DC5ULL,
    0x8D0764F87B4DB76AULL,
    0xA85CBF291FA6EA22ULL,
    0xC0A6048A49393DC5ULL,
    0x8D0764F87B4DB76AULL,
    0x501AA198AA7FD940ULL,
    0xF40DB6FB7C84F7D3ULL,
    0x3B,
    0x3A,
    0x65,
    0x94,
    0x8B,
    0xF0,
    0x36,
    0xE2
};

