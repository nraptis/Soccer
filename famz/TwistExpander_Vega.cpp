#include "TwistExpander_Vega.hpp"
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

TwistExpander_Vega::TwistExpander_Vega()
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

void TwistExpander_Vega::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Vega::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Vega::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9F89283024BD914EULL;
    std::uint64_t aIngress = 0xC29E44908B70CBD2ULL;
    std::uint64_t aCarry = 0x8F605D6D1BEC8692ULL;

    std::uint64_t aWandererA = 0xDA5C599B6D2E264DULL;
    std::uint64_t aWandererB = 0x907D0965D33825B2ULL;
    std::uint64_t aWandererC = 0xC56F994D637A95D0ULL;
    std::uint64_t aWandererD = 0xD75264B04B5EC9D4ULL;
    std::uint64_t aWandererE = 0xB7235B25522A44D5ULL;
    std::uint64_t aWandererF = 0xA9AC1DF80EA17B09ULL;
    std::uint64_t aWandererG = 0xFEFE47194E8F0E85ULL;
    std::uint64_t aWandererH = 0xD9EDD1AF9C4332A8ULL;
    std::uint64_t aWandererI = 0xBC25506F26EB8829ULL;
    std::uint64_t aWandererJ = 0xEAD4CC196CA17419ULL;
    std::uint64_t aWandererK = 0x81F377E4705358D8ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x87F403092CBB38EEULL;
    aIngress = 0x8586291E0282F16BULL;
    aCarry = 0xAEDE22A46A164EDBULL;
    aWandererA = 0x966DEC081564933FULL;
    aWandererB = 0x8290271DCE734E6CULL;
    aWandererC = 0x8704F9C3EA0F7CB2ULL;
    aWandererD = 0xE8F8ED15852FFDDBULL;
    aWandererE = 0x82999DC01E75BB7FULL;
    aWandererF = 0xC32D161488B1FFCBULL;
    aWandererG = 0x9FCD94C0C8CA272CULL;
    aWandererH = 0xE4D5B3224938FD7BULL;
    aWandererI = 0xAB97254D7A233B5FULL;
    aWandererJ = 0xCCDEFA4F88122EABULL;
    aWandererK = 0x87F369E7D81AA6E9ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xEA5CF6FA28118F80ULL;
    aIngress = 0xF2057AC58D5E6F8AULL;
    aCarry = 0xD89B0C1371257321ULL;
    aWandererA = 0xD9E3F4B88C52FC3AULL;
    aWandererB = 0xABA06F09F098D07EULL;
    aWandererC = 0xBA6864C09BD087B6ULL;
    aWandererD = 0xB65B70DEB052AA2DULL;
    aWandererE = 0xA28D453C32BB02B0ULL;
    aWandererF = 0xABCE2602CE877139ULL;
    aWandererG = 0xC8AE4AAEEBB0E2ADULL;
    aWandererH = 0xB4400C798DAD62FCULL;
    aWandererI = 0xFBE0069665F8060FULL;
    aWandererJ = 0xE5DFB0DC377E1A49ULL;
    aWandererK = 0xA4EE15421221BCCFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xDEE218FB7166DFEAULL;
    aIngress = 0xA0120DD377EDBA06ULL;
    aCarry = 0x900E28A12A9FD426ULL;
    aWandererA = 0xBFD52171F4D01183ULL;
    aWandererB = 0x9DA347267CD85D5BULL;
    aWandererC = 0x8A41BA7F7E15941DULL;
    aWandererD = 0xC224716CCB16D7C5ULL;
    aWandererE = 0xFD9CFDD6186AA626ULL;
    aWandererF = 0x93DFE711A69898CEULL;
    aWandererG = 0xAF23EBAA87F37499ULL;
    aWandererH = 0xDE819586FD171953ULL;
    aWandererI = 0xA6FF250FD4D3F157ULL;
    aWandererJ = 0xC0ED6534ED94442EULL;
    aWandererK = 0x81F74309159B4694ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xE0E205143C0F72EDULL;
    aIngress = 0xA91B58E4FFE7EB8FULL;
    aCarry = 0x8C2E4604A896A9EFULL;
    aWandererA = 0xB490315B68401951ULL;
    aWandererB = 0xF0EBEEDE0AF0B0F8ULL;
    aWandererC = 0xD431098269B9C4BDULL;
    aWandererD = 0xDA4306EF020501BBULL;
    aWandererE = 0xD96774787197402CULL;
    aWandererF = 0x8718F607CC365C8DULL;
    aWandererG = 0x8EBAA02B2424775AULL;
    aWandererH = 0xAC48D8E2E78CEA0FULL;
    aWandererI = 0x9432C7117BB99AB8ULL;
    aWandererJ = 0xD7FDB760ABBF0859ULL;
    aWandererK = 0xD1E712A3CD1B1EFAULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xF750C45C6DF35639ULL;
    aIngress = 0x939B5E2A457C56CBULL;
    aCarry = 0xCE2CD64A69F66C33ULL;
    aWandererA = 0xDC56FE08678CBCFDULL;
    aWandererB = 0xD9A093AF7AF98557ULL;
    aWandererC = 0xCEF10BA216B67A5AULL;
    aWandererD = 0xD2567226B2E5ADC6ULL;
    aWandererE = 0xD51F52003845AB74ULL;
    aWandererF = 0xF8313B778A7C6C2FULL;
    aWandererG = 0xA0C3E98F3842DF7AULL;
    aWandererH = 0xDA74023D16D7C0F9ULL;
    aWandererI = 0xBA80056647912CBBULL;
    aWandererJ = 0x8B3ED41B1416BFD6ULL;
    aWandererK = 0xA636FCA885944D8CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x8EB29EE42916E57DULL;
    aIngress = 0x94589E56BF662173ULL;
    aCarry = 0x96727FD40B4A5D79ULL;
    aWandererA = 0xA0E4F75E4F6CED18ULL;
    aWandererB = 0xA991CFADFF3470EBULL;
    aWandererC = 0xFFB353A41C21157FULL;
    aWandererD = 0xA5AF475BE7777018ULL;
    aWandererE = 0xFAE44B447444B99FULL;
    aWandererF = 0xEA24BD3410EC86D7ULL;
    aWandererG = 0x9EEBDB9700C9B3E3ULL;
    aWandererH = 0xA042453F5EBB5F47ULL;
    aWandererI = 0xB9BD938E253AE2B9ULL;
    aWandererJ = 0xDD132A21D8B0148CULL;
    aWandererK = 0x90CCE4133B2FA196ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xD555406A4BACF4C9ULL;
    aIngress = 0xB55F02BA5B520C8EULL;
    aCarry = 0xC5F37BB8ED87F0DFULL;
    aWandererA = 0xA1A63027B6838C41ULL;
    aWandererB = 0xB7AE9DB2D646F7A9ULL;
    aWandererC = 0xD01A4F64D9807BEFULL;
    aWandererD = 0xAA07E879A617BF91ULL;
    aWandererE = 0x87EC13E369BB1BE3ULL;
    aWandererF = 0xDF19F3411DB72DAAULL;
    aWandererG = 0xAD52E687025A1462ULL;
    aWandererH = 0x85BE04E2B1CE528AULL;
    aWandererI = 0xE0F08C8A11E1C2DCULL;
    aWandererJ = 0x9AFC77B0FC65F1DCULL;
    aWandererK = 0xE580B3D74C0C09B3ULL;
    //
    TwistExpander_Vega_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Vega_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Vega_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Vega_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Vega_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Vega::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFA1B6D24585C0438ULL; std::uint64_t aIngress = 0xC88B2F6101F15A7AULL; std::uint64_t aCarry = 0x8766C2C98BA59F5BULL;

    std::uint64_t aWandererA = 0xB138FE0044FC6F2DULL; std::uint64_t aWandererB = 0x9E64B65FDAED6006ULL; std::uint64_t aWandererC = 0xDCDA35F7B3AB2775ULL; std::uint64_t aWandererD = 0x98A4F751FC07438CULL;
    std::uint64_t aWandererE = 0xC634CFA1A4E5F6E9ULL; std::uint64_t aWandererF = 0x81243BD2061F0FFAULL; std::uint64_t aWandererG = 0x9967CC98D75F8D7DULL; std::uint64_t aWandererH = 0x80C24B7A445BDC38ULL;
    std::uint64_t aWandererI = 0xB1908479F8F4CECBULL; std::uint64_t aWandererJ = 0x8F16F4630E58EABEULL; std::uint64_t aWandererK = 0xBC225BDB02D8AB62ULL;

    // [twist]
        aPrevious = 0xF8AFFA1F6828934BULL;
        aCarry = 0xF058891E4FDE4747ULL;
        aWandererA = 0x94F522177FF01BCFULL;
        aWandererB = 0xB89D7732BA95B664ULL;
        aWandererC = 0xB1D305F410CC46F9ULL;
        aWandererD = 0xF2CB845F72FA7A5FULL;
        aWandererE = 0xA49ACF47FCAB219EULL;
        aWandererF = 0xFC51B0CF1C7D591CULL;
        aWandererG = 0x942AFD4B137BBE88ULL;
        aWandererH = 0x9D5C6CB3DC307268ULL;
        aWandererI = 0xC164428BE8CF4AFEULL;
        aWandererJ = 0xBA761CBD33DA9EB9ULL;
        aWandererK = 0xA8FBE5B861B55F68ULL;
    TwistExpander_Vega_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Vega_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Vega_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Vega::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Vega::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Vega_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Vega_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Vega::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 33 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 17119
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 33 of 33
    // Exploration cases: 0
    // Structural maximin 513 / 674; family total 17120
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1150U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Vega::kKeyRotateASalts = {
    {
        {
            0x015B21B98548AC95ULL, 0xC731217A0781DD34ULL, 0x0B1CD45BF770923DULL, 0xE677E7901D645D20ULL, 
            0x7F175D2DDDDAE969ULL, 0x590998829A10BD3BULL, 0xD7E51DAB375416A2ULL, 0xB47DA41F17D58FB8ULL, 
            0xC1044EF54D2DA019ULL, 0xD13DB0271707323FULL, 0xF92790991725A067ULL, 0x605FF128663A874FULL, 
            0x89224FDFCDA6E039ULL, 0xC31EC3CC15C13681ULL, 0xE892302EA434EAFAULL, 0x3BE9E884F145583AULL, 
            0x061931A9CBE64072ULL, 0x6016F9E7DA31A09EULL, 0xE5318EC42D5264C8ULL, 0xB79AD3ABB1D209B7ULL, 
            0xEEDBFAF9D3BC4194ULL, 0xC16BBAFF5972FA04ULL, 0xCE0A0B5DE5CFCB44ULL, 0x6E9B3100A12B2C9EULL, 
            0x400247F4132E0D40ULL, 0x38CD305AAED05A5CULL, 0x7E5C2D65D7FD8AADULL, 0x60D338C19E3A7B1CULL, 
            0x05F2AABF6234D55CULL, 0x9EE17FC6FA7606DEULL, 0xBECD96568453CC3FULL, 0x436E14ECD0453AB9ULL
        },
        {
            0x4CCCA36064CE9C3EULL, 0xD42C9842BA5ADADDULL, 0xDD4DAFA7D65401D4ULL, 0x5D6D12872C2D68F0ULL, 
            0x981D4CC96148A6DDULL, 0x5B55DE6724885764ULL, 0x8E2D4521354439F0ULL, 0x875C8A14D42F6CFBULL, 
            0x330602F6282DDDEFULL, 0xF995C8350B4BDBC5ULL, 0x1B9B5D9B361BC638ULL, 0xA0DDFCB99C8F4114ULL, 
            0xCBBB77C43F550BC9ULL, 0xBE87737243B0977AULL, 0x41FB5EE35BA59C35ULL, 0xF131CD05FA607DB5ULL, 
            0xE9FEEF6EF9DD3AE5ULL, 0x9757BBB5F666A230ULL, 0x58D52715AC192CC0ULL, 0xF98F2311866D4EE0ULL, 
            0x455CE92DF09E2231ULL, 0xFD735FEADC4D1FFAULL, 0xE7931BD016A10201ULL, 0xAE1AF8F3C5C75957ULL, 
            0x6204D9F15896C0FFULL, 0x00C095C4B6A484E6ULL, 0x56397EEB323E4753ULL, 0x6A38505BBA77CB12ULL, 
            0x6E165EADA970060DULL, 0x52B0E1FCD78E033AULL, 0x75EEA0AC070CBB78ULL, 0x8AC5A2B3821CDE7DULL
        },
        {
            0x642138156E254433ULL, 0x531371A88A7BE70EULL, 0x512EA7DD99985E8CULL, 0xB0461AFD10639E8EULL, 
            0xCE2B65A44D8258A4ULL, 0x21A4FCAE56C0D735ULL, 0x6A1F3B30CC203FF5ULL, 0x70729931BABBCC9AULL, 
            0x7586C9673F5A7B22ULL, 0x1C65EE9536949E73ULL, 0x60506A6F4F300AB7ULL, 0xB94D92BE2B495992ULL, 
            0x4CBB04909C72EDEAULL, 0x10D1C314A6B143F5ULL, 0xEFBD34D4BA8F1461ULL, 0x6F1D8D7DFFC1BC47ULL, 
            0x269D7AED1A5BF674ULL, 0xAF304AF3DE74489BULL, 0xED80C6DFEE086CD3ULL, 0x32F73FED6BBBBABDULL, 
            0x171E76E0030B04A6ULL, 0x0E3C3D77C79DC919ULL, 0x36BB663DD75BAB50ULL, 0x4ED7B570A26FC725ULL, 
            0x7D0CBA045EE09651ULL, 0x3046E4979ECAF3FAULL, 0x6D505D23949F0411ULL, 0xB760FE174C8A1DF7ULL, 
            0xF33218CFCB046CD3ULL, 0xF755B3A2D911AEF5ULL, 0x4AAA229F1678E06EULL, 0x1C453E22CC365A78ULL
        },
        {
            0x096B10096B158506ULL, 0xAB857295A40115E5ULL, 0xA1599602A163F244ULL, 0xDE1CA7418AFED1C0ULL, 
            0x4774C57F19C031C3ULL, 0x703B96368D88A6A0ULL, 0xEE55082B507D0B59ULL, 0xD896AAB81A7D41FCULL, 
            0x034EAD3557421162ULL, 0xB7F555934817839CULL, 0x72128CC7C4883F2FULL, 0xBA42E57E6776128FULL, 
            0xB6F37FC23179EAD2ULL, 0xDC448D91794C68B1ULL, 0x476BB1A9D7B951F7ULL, 0x7CC97199ACA7D746ULL, 
            0xD771B08CD09E9BD8ULL, 0xBE619B6900FC57E0ULL, 0xAA01B41438126FA1ULL, 0x2D6CE49110739F01ULL, 
            0x2FB26B50FCB398A4ULL, 0xA8179F06D445F22CULL, 0x80D262C1DA54BEBFULL, 0xB022B3F050D17C87ULL, 
            0x3DEB50F35FD67DF4ULL, 0xDE9090C331A2F593ULL, 0x6629027C16DB375FULL, 0x86E7D89DC065A0C5ULL, 
            0x3B037A05D1267044ULL, 0xFF34FF208045254EULL, 0xACDA3C7B1D5D1713ULL, 0x887C0E53DFE77787ULL
        },
        {
            0x62AC207C170CAD97ULL, 0xB42F72DA092A0B27ULL, 0xBC3A6C2F9EDE9C1EULL, 0x2C41277603288829ULL, 
            0x87D430D4C3AB1A90ULL, 0x4753020224CE9EF4ULL, 0x63AAE02FF5ED2F16ULL, 0x192E3213B6D7AAF8ULL, 
            0xA0E9DE481F2F8462ULL, 0x6018B8A444708D70ULL, 0x3C8C7D3306981109ULL, 0x577ED3E17BE2AAB9ULL, 
            0x18907154DFC416ACULL, 0xDD1A1089B079804EULL, 0xABAA5435BDEE07E3ULL, 0x7731131C387F1C7AULL, 
            0x0AD435E78C2C5879ULL, 0xB84851397E43A034ULL, 0x5CA420FFE9DF1151ULL, 0xADD50188AC5D5AB7ULL, 
            0xD4E47A92ACA8E1E2ULL, 0x5F9B051D8C0531D2ULL, 0xD9A9CEA91223CD5AULL, 0x521E28A36C6A8581ULL, 
            0x30702F2F1723A24BULL, 0x2D6751B2C467E381ULL, 0xD3FB7FF92736966AULL, 0x4DCF942E163F3913ULL, 
            0xF353117E3F2E5384ULL, 0xB86477FD6A186EBBULL, 0xD6243F0CED0DECFDULL, 0xAD9AE1CBDC7C62B6ULL
        },
        {
            0xC342AA7BB3EB94B1ULL, 0xB145F31EADB80C96ULL, 0xEFCBE01C3CE3B5A5ULL, 0x2EAC8182968B5EB1ULL, 
            0x75D0A13ABBDEAF0CULL, 0x4CAADE835BCB0DBEULL, 0xA6B5461DABFE0AFEULL, 0x07BB54ECDE4CD2A6ULL, 
            0x84F3364A7BF175A0ULL, 0x61A7FD7D8AF105D3ULL, 0x2BF0634DAABF1C95ULL, 0xBA065FD68CA6A192ULL, 
            0x36E453E99F54D29FULL, 0x3053582E3B7880E7ULL, 0x88155DB46C88914AULL, 0xAADC0523DCA51E0FULL, 
            0x4F3CC67B3F2579C3ULL, 0xBDF39D66660FBB15ULL, 0xC60021E18B08C0E1ULL, 0xB732FD983E0A163BULL, 
            0x0434D7D221E42841ULL, 0xBA730563340369ABULL, 0x05A21F215D1ABB41ULL, 0xDDEE33763608F65CULL, 
            0x021AC80A0F55302DULL, 0x62F9AF01DA745662ULL, 0x8F8E45297EA23964ULL, 0x37A99C606A7F65BFULL, 
            0xACD70F8AF6B30D5CULL, 0xF2F95A6DD7A7C8DEULL, 0xBCEE4BCE8BB5034DULL, 0x514136C4CE1E96E0ULL
        }
    },
    {
        {
            0xB32226F018B3261FULL, 0xD831E812BFD5CF41ULL, 0x125D7AFABDC1076AULL, 0xBDA0C0CF0B909FC8ULL, 
            0x5E7D3B971F3D555DULL, 0xB47CB502E7CA95DEULL, 0x04BA789CDBE0288CULL, 0x185C86ABFBF90F1EULL, 
            0x6FA622704A0F67BDULL, 0xCD19BCEAEA800839ULL, 0x904602D5EB0738ABULL, 0xD20F442236C4D75BULL, 
            0x088D3DD56942867EULL, 0x3FEE13E91864B226ULL, 0x473F64D1FA06FC5AULL, 0x26DC822274CDA181ULL, 
            0x37B9617CDB5150F9ULL, 0xB085DA5E7B9F5771ULL, 0x465CDFBA055148FDULL, 0x832621DAE3E86AE3ULL, 
            0xB269E9D6C09DDCC2ULL, 0x95D183D00D4DBE9EULL, 0xD3D3931B6D41A6F0ULL, 0xC35F466AEC8DF716ULL, 
            0x884C9B35837C8924ULL, 0xE00431E25B737B5BULL, 0xC004692BA76AF7ECULL, 0x956DEEAC8A9CA5B1ULL, 
            0xA56E86C58E4543C7ULL, 0x4265DC1CDBA39EE1ULL, 0xCB4766669265CCFCULL, 0xCECC33EDFEAE733BULL
        },
        {
            0x43A9A6BE519C70CBULL, 0x4B67302B74501FB8ULL, 0x7C2A44E23A34D872ULL, 0x3AA9E2BB130A2782ULL, 
            0xE19B2F2F7D129A33ULL, 0x3EFB2F46F8432740ULL, 0x1EB1E04C59088150ULL, 0x38F58CD7FCE4EE7FULL, 
            0x04B24F6231F39952ULL, 0x6D065F38E83AE059ULL, 0xFC13110F829AE9E1ULL, 0x64918C8BC3AF29C9ULL, 
            0xBFAB3D5AB82D7469ULL, 0xFF50DA96986B665FULL, 0xDF3032D64CBA1D24ULL, 0xFCE52BF3FDC6F63CULL, 
            0xBBB497C1AD10580FULL, 0x7AF4B003B2F41A9AULL, 0x2ACEC056C9CA480FULL, 0x85B7BBC041042F7DULL, 
            0xD4BEEA55819E0AF2ULL, 0xBDB0BA2CF803E703ULL, 0xE5ACFF361EF767BAULL, 0x6261093567124D20ULL, 
            0xC6E0DB22C7D8F77BULL, 0x2FB81AE4B7D9ABCFULL, 0x9C8A8215AF87B1E6ULL, 0x561CD6F6E35DE061ULL, 
            0xA37A48E4A60ACA5AULL, 0x43568B0A4006FDC8ULL, 0xE9C4D7958FED1777ULL, 0x44A198D811EAE173ULL
        },
        {
            0x6ED4B07B80B527C7ULL, 0x49437D50FF506690ULL, 0x761D33E76DE6D029ULL, 0x822160111F774F8FULL, 
            0x1B89B983360ED243ULL, 0x96837EC591D276BEULL, 0x5A449C616D1B4FC5ULL, 0x034A87ACC0592276ULL, 
            0x03E7D759119911A5ULL, 0xC9FEB9CEE26C7B5BULL, 0x4E8AFB0B939BDA02ULL, 0xCB2E90AE9D20F2F8ULL, 
            0x58EFD4CD766D397AULL, 0xCB4A7754D446FB75ULL, 0xBA3E2568C19E3F90ULL, 0xD76BA4AAF85AE774ULL, 
            0xDBA7CA8BD4379282ULL, 0xFE6D081BE21456B7ULL, 0xECE87636F8ED9BACULL, 0x22EAB9DA84DE94DAULL, 
            0xF2D9E6612455E654ULL, 0x7B21F91F54046E84ULL, 0xE0447AA58D5843E4ULL, 0xFF1440493DF20F4FULL, 
            0x04D8CF1C0231F86FULL, 0xE0FD7EA37FBD0448ULL, 0x3E04565B3540C402ULL, 0xD3D7FEB4B2A64BC7ULL, 
            0x719FC9C470E0FE3CULL, 0x5FD82B27E9824535ULL, 0xEFD4E7B88E397A26ULL, 0xF46DDDB60D279416ULL
        },
        {
            0x2472571B218EAA68ULL, 0x5BF42F7B42A5A428ULL, 0xE4CB18E638C93C89ULL, 0x4513E3F90243B0F4ULL, 
            0xF4619288405C25B7ULL, 0xA3D51071E7158D9DULL, 0xF47A57C57198D8E4ULL, 0x4E96E79B18F14712ULL, 
            0xEEEC502CFAD0ADC6ULL, 0x458D48EA9A35B3FFULL, 0x2EB9DA612C6FB29DULL, 0x079D22A2B2C5D4D7ULL, 
            0xF40B4290B33E6621ULL, 0x31188DCD957DE77AULL, 0xB840850FFB8395CEULL, 0xC92EB8DE6D5EA456ULL, 
            0x0D7D9714A781B3B2ULL, 0x52D625574A9EBF6DULL, 0xBD9D6469A136A7E5ULL, 0xDAAB043F9A70A844ULL, 
            0x1F0C4C38E767EB66ULL, 0x7EA786B397064D13ULL, 0xE061AAA650B716C7ULL, 0xB222E0FE73290D71ULL, 
            0xAD1143020D1E47DDULL, 0x2A596A81012CC74CULL, 0x7B358AD36F457CE6ULL, 0x0C693B0D557CAD8EULL, 
            0x486C23D1A1D837F5ULL, 0xD22886940336981DULL, 0x6B621291158B6F8BULL, 0xCBF05040F2C35067ULL
        },
        {
            0x49B75E3257AE0A07ULL, 0x973E5263C0E1A286ULL, 0x77FE91969EF25390ULL, 0x156BEB89F30EC72DULL, 
            0x9197DCCDB3BE12DFULL, 0xD61E9DCBC822414FULL, 0x273DE83673E99FEDULL, 0xC9A536825F763DD9ULL, 
            0x192AA8ACB71F215FULL, 0xF9052C221C20BDBDULL, 0x609C74FB5864E341ULL, 0xDC1EE2F54FFA0A30ULL, 
            0x8FA0B58996F6D542ULL, 0x2E468EE771249925ULL, 0x230FF04411272766ULL, 0xA8E90BBFF0AF384BULL, 
            0xEE9791568DF73C0DULL, 0x0B6263E890AE885FULL, 0xDEC9E6B456859A6CULL, 0xF615AAB4487D0E58ULL, 
            0x7763784FF4CF9292ULL, 0xE9E1C9773AF3F5BBULL, 0x6E5910BA77C1B014ULL, 0x6359642369F4A33CULL, 
            0x5A477E542155DC18ULL, 0x1CD39E34CAD4F52DULL, 0x5D9D4882EECFFCBAULL, 0x62E5FD0E03521C78ULL, 
            0x3A8DACE29157D43EULL, 0x11E3F8B0A18AC65DULL, 0xF21CEDC4B7C45925ULL, 0xB735DF9427048492ULL
        },
        {
            0x332E38678882272EULL, 0x9EFE2F1BCC7BBAD0ULL, 0x30C7786CE2DCB8BBULL, 0x76885FDA11AC41CEULL, 
            0x03E9D9C12DB0BB10ULL, 0x8DA043A15E36A59AULL, 0x7B91AD7B9634F513ULL, 0xFDAEF6D3ED7CE2F7ULL, 
            0x3AD5E706DCB508D4ULL, 0x1518DD2E17568846ULL, 0xC1E2C3D912C81AB5ULL, 0xFFF19116F5DF5D71ULL, 
            0x687B5D0DB701D3E1ULL, 0xF609FB1995F74BF7ULL, 0x9058BA1D72C3E60AULL, 0x648A46404FF736A3ULL, 
            0x06F4368E35F72DF1ULL, 0x6A0EA219CD812838ULL, 0x5B59F6CBAF39EA44ULL, 0xA9173635FEE93E08ULL, 
            0xDBDD3A270D7A19B5ULL, 0x1A897DC70DC44ABFULL, 0x788E39857D369868ULL, 0x263CF1817AFCB0DDULL, 
            0x2864BD3985E3B1CBULL, 0x78C5C3D1FF2A74C1ULL, 0xC76BB83D6CA4B092ULL, 0xA2E60A2D65066A32ULL, 
            0x0A680F7542B37B8EULL, 0x62A7A92691AD0892ULL, 0x345F072A37C2D4F6ULL, 0xE09B9AE6FF7130BDULL
        }
    },
    {
        {
            0x26E8F18FE6BE70ECULL, 0xDD3C95D1844A2E42ULL, 0x492F115E8C8B59EDULL, 0x94F09C4B19F53D14ULL, 
            0xB959908ACBFF4F50ULL, 0x738779C9474AF303ULL, 0x9D3D794DB5B12353ULL, 0xBD848DFA3BB10A6AULL, 
            0x00C5B8D4B487EAE5ULL, 0xE5183591AF0EA423ULL, 0x85BBC285F2C516CDULL, 0x194275C43E63282AULL, 
            0x7B0063374FE50AA5ULL, 0xA5770FDD32DE220BULL, 0xD7F34F9D4AE6D5ECULL, 0xCD53F5FE0B4FD35AULL, 
            0x93DABAF2D80E7DA5ULL, 0xB3B884F23B5CC215ULL, 0xC3E8240CED5B72CAULL, 0xEB479427CE15A5AEULL, 
            0xFB376F417AC89D7FULL, 0x823C9B7499AFE79BULL, 0x5D39212B6059F0B9ULL, 0x8561B57A1F83AEB3ULL, 
            0xBA335F5233C0BB2FULL, 0x4D982BB7C154CFDCULL, 0x38DBDF1687141040ULL, 0xF42E70FDCFDFD4E3ULL, 
            0xF1FB1492B22E75BEULL, 0xAD45D1B26098C81CULL, 0x9063C416A3EB5039ULL, 0x4CAF1F3EFC81DEA3ULL
        },
        {
            0x890D1846F7BAD7A2ULL, 0xBAFDAB21B9AE2F03ULL, 0xC16451C937E380B3ULL, 0x6B97CFD79E649376ULL, 
            0xF3107CA3C140EC2EULL, 0x13CA7A6A5BCDC645ULL, 0x93EECCEB8BEAE23FULL, 0x20DBBE7CE3CA7BFAULL, 
            0xBB3E3055456E4738ULL, 0xB5DBE0E0B3BAB148ULL, 0x7C817FE4BF25B185ULL, 0x49116919155D6F16ULL, 
            0x54EEBDFB29A43638ULL, 0xEB319C6DF5CCE8D2ULL, 0xECB44773D3ADB626ULL, 0xAC2CB6CC1B1B4244ULL, 
            0xBEE0C225B3C3BD16ULL, 0x3140821D92315F4BULL, 0xE0F26DB0F47CECC1ULL, 0x5D356992284E0A5DULL, 
            0x689EBB36E30C2FEEULL, 0x1D3C88DF9843F2E1ULL, 0x68F0CE09DAD75F5EULL, 0x7C1AF7948CDA6FDCULL, 
            0xEEF9F5A2D0C00983ULL, 0x26D2ED738A8F0885ULL, 0x2D8F7A227A6073EDULL, 0x531A867EB327FABEULL, 
            0x6C624D42EE03ACF4ULL, 0x36942249C0FDE57BULL, 0x8A6CAD27789961B4ULL, 0xDFD9642424E64135ULL
        },
        {
            0xA80DE3D6D8B558C3ULL, 0xA30A151428CD0A47ULL, 0x0F8326E8897809C0ULL, 0xC50AE8A372314847ULL, 
            0x2A6DD90F9791DCD6ULL, 0xB837EF2A2B9F15CFULL, 0xE9EF20365C6E14A1ULL, 0x60F6E8F30558EFF2ULL, 
            0x29E0805EB95000EAULL, 0x88F952454D75A5D7ULL, 0xDDE2016B8BBF1DADULL, 0x0BBB43889F4C672AULL, 
            0xBB9B227CE545B40EULL, 0x6FC4570261F9F23BULL, 0x73BC44450EE3E8E3ULL, 0xA6C8C58FDB616A55ULL, 
            0xBF5EA8BD0F71A279ULL, 0xC4EA364DC79A085BULL, 0x07A1CD9D56C86668ULL, 0x3C410C24A5C63AFEULL, 
            0x6055DA5DE0EB08A1ULL, 0xF7C33AB916764B3AULL, 0x56CBDCFBDC09AA64ULL, 0x1B734FAE255B5865ULL, 
            0xFEDF1C631F1F2BD0ULL, 0x1AA12FF63142302BULL, 0x21DC08C4E156CF47ULL, 0xE6936F7BD4FE7D3BULL, 
            0xCD1EEA705FB8B01AULL, 0x9B677528F302CC0DULL, 0x4DAE01EE51AA7C61ULL, 0xE23EFFA8E3A0B475ULL
        },
        {
            0xF0F93D9996793B09ULL, 0x20D7452DDA66E65CULL, 0x51E770C9324FE1A3ULL, 0xD6E320BA0155EE23ULL, 
            0x40AEE3698403B440ULL, 0x7CEF4D1A6DBFF73AULL, 0x6CB552EC34CA7926ULL, 0x5F863F5523B68D1DULL, 
            0xC6881F317EFB0BE5ULL, 0x58FB720AC6DE5B06ULL, 0x01D0FF2E461F8F46ULL, 0x18B9D3C6EDBE670AULL, 
            0x9567BDD3903DC280ULL, 0x3D46AD05DE34CC50ULL, 0x45BCC3DBB4611EB5ULL, 0xD4BACD3E45EBCA55ULL, 
            0x9104F6AB9E1308FBULL, 0xBA8D8254E32AAB30ULL, 0xF7F061D1F47EEF6FULL, 0xDF217975028EECD8ULL, 
            0xEBC007D4E957C310ULL, 0x142E3D31568936BFULL, 0xAF5BE387532369EBULL, 0x5066FBAEFAEA8520ULL, 
            0x142CF2DF94F8B0EAULL, 0xFDDD540317E22131ULL, 0xEE75D22CD94413B7ULL, 0x352A671D7B6BE60DULL, 
            0xCDD7C4623BE59332ULL, 0x80C28782078A7F26ULL, 0x5E1D38DE6773E669ULL, 0xB341E7844737050EULL
        },
        {
            0x4E47CC3487984C99ULL, 0xEB03EDEBA96A566EULL, 0x8AD32EC7CF820DEFULL, 0x2A3148424F8C9BAAULL, 
            0x74D11FCEC1015168ULL, 0x134672B1EB5F8826ULL, 0xF900C15003E33854ULL, 0xC9105BD766B75960ULL, 
            0x6DF65E7F496C5F69ULL, 0x2B7A0625D72F495CULL, 0x0AE67D87F740869EULL, 0xED1B39BF0F9DFACDULL, 
            0xE9C61DA6A0A42944ULL, 0xD7C68FCE6CEEB0EEULL, 0x926F6819059631E7ULL, 0x391DBB4BE2F23A12ULL, 
            0xD96A129D1469F961ULL, 0xCFD6A322FC5D61EDULL, 0x4FD2EEF5A09A74EBULL, 0x6DD152A3F2A0484AULL, 
            0xA52EDD82C2F2D45EULL, 0xDC29501FA01123F1ULL, 0x4F48B24B1861EADFULL, 0x3E55BECF71D649F6ULL, 
            0x83C22F85628897C6ULL, 0x9C3CA7D0525FB414ULL, 0xCC1BC44D2F32DF18ULL, 0xB4E15E6B761C68DFULL, 
            0x25ED7BDB7BBA4467ULL, 0x3D926E9DB8A20796ULL, 0x3B47030715307D46ULL, 0xC4005A505F904EFFULL
        },
        {
            0x04913C563A191D61ULL, 0x4008A0CEFC9CEAAFULL, 0xD5FCBD3CF2B70C24ULL, 0x10B3FC115B90B921ULL, 
            0x36F7243ED5914ADEULL, 0xAC08EAE842CBAE71ULL, 0xD260C0532A7BD52CULL, 0x30C5FF6C2C307709ULL, 
            0x6656C1695DD9A0FAULL, 0x7D4784E0AF7A4E5AULL, 0x7AE994B2600D28C0ULL, 0x7220FD742255EE93ULL, 
            0x247736E520740666ULL, 0x7870FE7AB2A3AFD8ULL, 0x99CE3306D4E9C94EULL, 0xF6D42490EA4F33FEULL, 
            0xBAAE5BE78231C752ULL, 0x6E6770C73D59C160ULL, 0x38533C213A3DCD85ULL, 0xB07F5C71FDAC8872ULL, 
            0x770F82DABD24EB51ULL, 0x01745795C543B058ULL, 0x5880A0972DFC1485ULL, 0xF1B96FDD79EC3EA7ULL, 
            0x8A7FA0DEA84464ECULL, 0x7E11A50090F71576ULL, 0xD56EAEBEC3E67B36ULL, 0x300C4684A055B3E0ULL, 
            0xB9E19E43E58842CAULL, 0x913D7DE13FC1676FULL, 0x2083BEFA19D4015DULL, 0x37738B3E994B2EA3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeyRotateAConstants = {
    0x900A9A7C62A2B27EULL,
    0x26CADBFB54B5621AULL,
    0x3E5560AE666B0DD4ULL,
    0x900A9A7C62A2B27EULL,
    0x26CADBFB54B5621AULL,
    0x3E5560AE666B0DD4ULL,
    0x55B480B5703168BDULL,
    0x6A87F84232F1B92EULL,
    0xF7,
    0x64,
    0x7A,
    0x46,
    0xB8,
    0xB8,
    0x32,
    0x9E
};

const TwistDomainSaltSet TwistExpander_Vega::kKeyRotateBSalts = {
    {
        {
            0xA96EB360652B98EAULL, 0x5346C2BA6EAEB44DULL, 0x8987D6937B5D1629ULL, 0x4583B5FFB911328EULL, 
            0xCE1F4CEB90032F06ULL, 0x5F3A92AE31B3ABAFULL, 0x16E547BD269F400BULL, 0x9B489A1F85D8BFB6ULL, 
            0x37680CE0AF63A924ULL, 0x4B81728CD031275BULL, 0x79A156898775CA2CULL, 0xF68FD2144DA18AD8ULL, 
            0x0144C2936AB6A431ULL, 0xEDB30C873ACBACE4ULL, 0x854D7308A9A513D7ULL, 0x205D93D3EC67397CULL, 
            0x4B28C4766F53CEE6ULL, 0xDC3BE02AC1177E16ULL, 0x54C7197D4E5034B2ULL, 0x0E6AB0DA6F9DFB63ULL, 
            0xEDBEA07439A5D23DULL, 0x7E1FCC8F7B2B1D34ULL, 0x3944D75AECA4A14BULL, 0xDE133217BEC38BC2ULL, 
            0x17007EA043435AFAULL, 0xCE9D1BE6561135BFULL, 0x7897C0350501D675ULL, 0x66E73747EA54A920ULL, 
            0x5E10DD4E5B2324A5ULL, 0xEFE8C2FB5A998980ULL, 0xCB1DD66FF4A75D4FULL, 0x39515405A0659745ULL
        },
        {
            0x52907660F8608651ULL, 0x426909EEFC44526AULL, 0x0700E16A56364A9EULL, 0x42B847859B08DBE3ULL, 
            0xCFEC91A0FD0489D7ULL, 0xF2744438547DC6CDULL, 0xF1245718898A9C0AULL, 0x614B88D054EDC42AULL, 
            0x2DE27404AD5B8009ULL, 0x78DEEE454C79BD56ULL, 0x11BFFAE93CF91F0DULL, 0x4AAB0BFE43ECBDACULL, 
            0x647F82A5C4570B8AULL, 0x76A3DA609761F21AULL, 0x7BF49D5262164FE5ULL, 0x240A23063C893BD1ULL, 
            0xE0B15BFF264CE2FEULL, 0x437C360B792DE7B2ULL, 0x51C703E0732888F2ULL, 0x1AE31E3C21A70EB7ULL, 
            0x2056C1B2D3F61CBFULL, 0x4AF1DFC24127306FULL, 0x789D3E33F59790ABULL, 0xB65D50D450A80C00ULL, 
            0xEBA935D642D7E1C6ULL, 0xEC18055BC078D845ULL, 0x42C1DDA179D12DF1ULL, 0xF53DC1F48E596463ULL, 
            0xB6792950B1C68AFCULL, 0x019FD6DD3009A452ULL, 0x21AFBB9F363958C4ULL, 0x6829C9608364A889ULL
        },
        {
            0x4FA77B09BB4032EEULL, 0xC880855ED423EE28ULL, 0x92368D349FE34A44ULL, 0x2E2A317383DCCD7EULL, 
            0xB7F0B3EF943759F5ULL, 0xD097287135B03504ULL, 0xEBDEF92E8E316B20ULL, 0x7146F0B462F6D781ULL, 
            0x89897984F8820C1BULL, 0xFD0AF067C1571EA3ULL, 0x598B8E93079CF96DULL, 0x67F98F5F9B075FCBULL, 
            0xD4BCDF74CA44CA88ULL, 0x41339859979A13E5ULL, 0xDCCF53BC97B57A03ULL, 0xD3DF5D0EFC43313CULL, 
            0xB10CC835A6A92A59ULL, 0x35DF052B61F3AF1BULL, 0x5B2AD3B11CAFBFA3ULL, 0x90733DE67E6CB5EBULL, 
            0x737594D359F31906ULL, 0x12A901A69A9811FEULL, 0x4F851FB278A9E622ULL, 0xE696E2CFE1F41167ULL, 
            0x162A66C1E7CDE7A8ULL, 0x9FB4F862E5C78886ULL, 0xD99E09AE178C2021ULL, 0xD2B44F024E41BD6DULL, 
            0xD0C6BD9F5EC11394ULL, 0x0DCED95A89D92220ULL, 0xC65730791F432E51ULL, 0x75ADB12F27251256ULL
        },
        {
            0x7A9351E3F3E18BC3ULL, 0x850B65EF16D54A80ULL, 0xA11E709A74C406CAULL, 0xA38BA2C651E90EA8ULL, 
            0xE284068524250A4AULL, 0x439DD458080CE4BFULL, 0x31C2BC4BC74CD853ULL, 0x970BB47B15DF9BCAULL, 
            0x126F3616C0528660ULL, 0xD71A5D8EDFC3361CULL, 0x1C9B2C47393DB91DULL, 0x632C692A026D5DA5ULL, 
            0x9A9C86ED0EBCBA9EULL, 0xEC1CB509E64B19AFULL, 0xCC81929597F51947ULL, 0xD8F0AA33C54A2908ULL, 
            0x1C811B31874C51EAULL, 0x831E63C25DCF00C5ULL, 0x8245A692CD237C12ULL, 0xDDCA3BB740373E50ULL, 
            0x06C22FC0C5385FD7ULL, 0x780B8D02AF31A27CULL, 0x2F2190B0CC92C7F3ULL, 0x26E1844045C21767ULL, 
            0x226905EFFAA6412EULL, 0x410BC04F553200FAULL, 0xBD1FC9627130128DULL, 0xA0484A2A973D2C30ULL, 
            0x9F79DC4431BC81D9ULL, 0x9D5687FE495086E5ULL, 0x33147F62C39747FCULL, 0x0DC8848627A753A5ULL
        },
        {
            0x77031A48A4225F00ULL, 0x26A7F8D90FB3CF75ULL, 0xAE6B8959EEEF1C39ULL, 0x78F9275DA3B2835EULL, 
            0x50C0FA061787EC99ULL, 0x37DEFC7394639AD3ULL, 0x3059636FE0453E52ULL, 0x7F3F94415AB97401ULL, 
            0xC5B8E79B51D8B498ULL, 0x0FFDCCB790D9E783ULL, 0xD2C392176043F775ULL, 0x31D3FD070E05A4DAULL, 
            0xE5295E012C39F756ULL, 0xEC258492955C6077ULL, 0x71FD6CE1F26EFA3BULL, 0x8AAD411082703537ULL, 
            0xF3521486AD6ACA78ULL, 0x2B44D30AFF94D118ULL, 0x1099439CDFBA60DAULL, 0x964FD1F42AB398F5ULL, 
            0x3E67B2B3A03C7BCAULL, 0xF9011AD6B5F62BABULL, 0x02A588E03D9F0B0EULL, 0xDE8C2F7DE9A8E231ULL, 
            0xF8E3AE9AB6F83B5BULL, 0xE148290BD35A6E93ULL, 0x52D4589A8589DD52ULL, 0x613434436B95B4FCULL, 
            0x2DAF01D27177A1D4ULL, 0x9A0A3464DAB3B30EULL, 0xB1DDAF7F5162D333ULL, 0x91C5ED006279EBEEULL
        },
        {
            0xEBB96F6BD6BF0804ULL, 0xEE9C1C6606A27919ULL, 0x15AC8AB601692028ULL, 0xD33DD5A1CF7C0844ULL, 
            0x7999D963360DF93CULL, 0x5EC1BFCA7BA1D70DULL, 0xB99106B236B63A71ULL, 0x88501DDD41C5B462ULL, 
            0x0AF2BB470893D438ULL, 0x2215E7000569D245ULL, 0x176B9D1094150948ULL, 0x6D27501BAA0D8C93ULL, 
            0x7A069DF8771959C4ULL, 0x964B381148CECC1EULL, 0x787CF413A5976CA6ULL, 0xC3C57662D8AFC8B4ULL, 
            0x9BAD3E1F288B9A32ULL, 0x40157CB343AC3F7FULL, 0x6B14441C18641871ULL, 0x81933757946B1FB2ULL, 
            0x753DA1684A252AD4ULL, 0x82452831DD8C4061ULL, 0x93971DDE4BA5A718ULL, 0x97D3633795ADE4C0ULL, 
            0xB46BBF98D1ED03C4ULL, 0x3D5AA7CE41B2D528ULL, 0xC1A36C676F4AD225ULL, 0xBC50DB2995055F0AULL, 
            0xC68188B13173E0F1ULL, 0xAD2DAC5CBF9525B5ULL, 0x24CE9B3EA6DDFD73ULL, 0xADAE6B9607380465ULL
        }
    },
    {
        {
            0x202AB5739FDD6A4EULL, 0xF8EA60CC82FC944BULL, 0x669220A311D30E13ULL, 0x39B9337921B50433ULL, 
            0xE8B2225B55EFFC03ULL, 0xF0C49EB9854BCDE1ULL, 0x01E36C2AE31830C4ULL, 0x709587188375C90AULL, 
            0xD706443731A25852ULL, 0x4A8AFCE11BAA31BEULL, 0xD16478237ACA8E9DULL, 0x38BB9968392E7A2EULL, 
            0xB27C82B48E60AAF4ULL, 0xC856E8FB3BC07312ULL, 0x3C8E5DD70F128FB3ULL, 0x981A928C2A9E8CFDULL, 
            0x4DB16B022E36470BULL, 0x043B87031BBE8CFDULL, 0xF64237B62DB070D1ULL, 0x4975B9CB6DD11597ULL, 
            0x91B68F239AE19592ULL, 0x8B5B4DC7671E46F6ULL, 0x51D94C2C4DD2BAF9ULL, 0xA7871026A5E1BE0FULL, 
            0x2BA265F4E7A5F001ULL, 0x75F37B90FC5EE15CULL, 0xC20311A3CA565640ULL, 0x11E538E7971DC180ULL, 
            0xABE877D0788C4EC4ULL, 0x9B68210A66FCEF90ULL, 0xBDC1E8C138B26A75ULL, 0x2453D449A3E58E87ULL
        },
        {
            0x17D58338DAB4604AULL, 0xB44499BF3AC00D6AULL, 0x8860B7EF5C6D5C91ULL, 0x871FE3315C477EFBULL, 
            0x0DDFC55FDB5FF120ULL, 0x7B276557768AACBFULL, 0x70748920F2C1BF6AULL, 0x0C709612BEB466F5ULL, 
            0xD6E5CBA0B3BFB4A7ULL, 0xEA5B9C4F9DA1964FULL, 0xA7A786993F385BAFULL, 0x4BA085284A4E514AULL, 
            0x9858CCCC103E7193ULL, 0x657D2FCF37E50E94ULL, 0xA3833907BAC19C1DULL, 0xD276AD90DAA17587ULL, 
            0x76A3F27D54C32650ULL, 0xFC0BA840A7EBBDC3ULL, 0x2510AEA792C9925DULL, 0xD9243D390034D6D5ULL, 
            0xEFC9BFCAE55E7611ULL, 0xF3D0F9CA33B06DFEULL, 0x5CE3974FEB38BEDCULL, 0x48951DB3584BF8F9ULL, 
            0xA156B83819F374C9ULL, 0x580EAE6ED9D6275AULL, 0x796CE671F1D67859ULL, 0x41D39C5AAF12218CULL, 
            0xBEF0A5928D52115FULL, 0x7A85262C53C105F7ULL, 0x89AD49E33E7A6168ULL, 0xB40C1079B05DA476ULL
        },
        {
            0xC1AEF1D5BA2E2707ULL, 0x05B4E76E3BB0278DULL, 0xCA3EE586FE084822ULL, 0xEC2CA67DA2981DF6ULL, 
            0x7AE5140373058C56ULL, 0x36ED2D0CFE997E61ULL, 0x25553E6F54666C56ULL, 0xB061078880D97039ULL, 
            0x7778EE7F0D89628BULL, 0xECE3CB625F68CD55ULL, 0x0D98EE83856CE530ULL, 0x42CBBEE48870F059ULL, 
            0x942639B461D56AB4ULL, 0x7CA6A4CD776DCB3DULL, 0xE9CB0AC12D41D268ULL, 0x793733129BECD674ULL, 
            0x9E52D1D1635FF868ULL, 0xC8DD07E5E2B98322ULL, 0x492D5128494EFD8CULL, 0x5238AC2D64CC9E79ULL, 
            0x8E85EFD49A733BDFULL, 0xC755D6EC08138F83ULL, 0xE47ACC25A8034767ULL, 0x4A39A79AF3E3CA0BULL, 
            0x67FD0AD80682400EULL, 0x7A6913D6B05962F5ULL, 0x4C79F6EAFE3D1614ULL, 0x8031C047E96AFA7EULL, 
            0x0A694B42912E6290ULL, 0x0542B342FF766511ULL, 0x1FC836A1CEE68323ULL, 0xAD58BA7983FE30E1ULL
        },
        {
            0xEF0C77FA3BE13F9DULL, 0x49BA89AA871CCB79ULL, 0xF104A10E7BFE21E7ULL, 0xD614260C39554866ULL, 
            0x1BED4CB269907540ULL, 0xB191E5B98D4FC497ULL, 0x2BCDBEA3E1F12C33ULL, 0x70B39960AA2A1634ULL, 
            0xC0DAE82B04E6AF24ULL, 0xB420E333578F5A2EULL, 0x9E826B555C7E2D54ULL, 0x85CEB3D430EAA8B7ULL, 
            0x491DA63DB921FB5FULL, 0x505D8958D87E73DCULL, 0xA1055C04AAB70365ULL, 0x3A2ADD547B9F591AULL, 
            0x4411E1F939918FF7ULL, 0xCB3AD257104B4C93ULL, 0x92914A9E2F15FA34ULL, 0x06DFA9EA7FB2586EULL, 
            0xF47F44FEA72F8D56ULL, 0x35884B2FFD7F8D9CULL, 0x65B1988E38CBF295ULL, 0x1F68F564A7036A7EULL, 
            0x3A4F5F2F86E82F94ULL, 0x870D48E26C72879CULL, 0xD6DB14543946073CULL, 0x692867DF2578EDEBULL, 
            0xA04FCB4936138704ULL, 0xDA9928E982218F97ULL, 0x425364F8C6140A72ULL, 0xB6AF4B0D9EAD96DDULL
        },
        {
            0x930D75321BF7E87CULL, 0x6564EFDC124F8473ULL, 0xD1F243FE87E4B4AAULL, 0x6C8CC2DF5E36E072ULL, 
            0xB7545768E2B89614ULL, 0x171521E0E8F62257ULL, 0x9DD4EEB282EC454AULL, 0xCE3E4618BD19A7D8ULL, 
            0xBDCE94DD22A92BD4ULL, 0xBF4889BC985AEB51ULL, 0x3D84C22A52EE5C2AULL, 0x37A39DD5BA6003A3ULL, 
            0x96DA55674197AAF8ULL, 0x303996C3C7E8FE8CULL, 0x83A525A4A08F8721ULL, 0xB104C010297748E7ULL, 
            0x723CD973558EAC07ULL, 0x0C162E4A5AB34BAFULL, 0xF5BE48845B952214ULL, 0x547353A809EE5299ULL, 
            0x94C09AA856DEBF50ULL, 0x9219BB48D1C2E8DFULL, 0x74FBFA346A72A6F3ULL, 0xB001B524E13EB767ULL, 
            0x657BC3872C5B003CULL, 0xF427058E8CAD9C43ULL, 0xF995414AA12303D1ULL, 0x6E42218BACB808A8ULL, 
            0x6BC4A82575A384B9ULL, 0x9DD0A33AF0FC44EDULL, 0xBDE4C93E89ABAEEEULL, 0xFB5D9A364FFE074BULL
        },
        {
            0xE9E9D83398DD7560ULL, 0x3358E253809C86D5ULL, 0x2B3D06F0E7A17806ULL, 0x2546D3AEA56D6F55ULL, 
            0x80DF520843945035ULL, 0xB4802094261F6ED7ULL, 0xD8E554546040940AULL, 0xE737F67ED6E9089DULL, 
            0x38E60B5AD00CDCBAULL, 0x9C405B0F9088EF05ULL, 0x3384B6B96C6534F1ULL, 0x6A2CBA38AE5A61DAULL, 
            0x386DAA30A3933A47ULL, 0x8204A956BF980E49ULL, 0x77A6DE8DFE110F73ULL, 0xF1ACA6554C26813CULL, 
            0xED5EDE18FD35EE7DULL, 0xFDE2EC622CB954FCULL, 0xA0359EEB7CA8E64AULL, 0x4C31F070DA3B3516ULL, 
            0x02DFE71DBA433931ULL, 0x3236BD62853B458CULL, 0xDC73DC96800D2D72ULL, 0xBDC3CF599294327FULL, 
            0x1CED9B0F3B6C2E01ULL, 0xC4E998C5C05A23F0ULL, 0xFC0940023E309357ULL, 0xC886090CEC626F04ULL, 
            0xF7B19616CC6795E1ULL, 0x2E5B25034D983AD5ULL, 0xF209F7F5BBB1EC74ULL, 0x6833D5E445D1E88FULL
        }
    },
    {
        {
            0x1674A7223D6554A6ULL, 0xE8661A82A59EF8DEULL, 0xD934F1CA7C2B187FULL, 0xEB2B4A0CD473A6EAULL, 
            0xB6B6F014937D40E9ULL, 0x4C920BA82FF9834DULL, 0x1D7ED47402FA2150ULL, 0x52E46D8F911B7EC1ULL, 
            0xD4371642502D16D0ULL, 0x1200CE47A6205BA3ULL, 0xA0EEF9BA0E73E5C6ULL, 0xD421FBDEB170B810ULL, 
            0x1EB37ECFC4513F22ULL, 0x3F01E236324BCB2EULL, 0xCE3E5848CA30848DULL, 0x4F2269F8D4FE4C1CULL, 
            0xB9B0D4AC8F979996ULL, 0xE8EF80A518AB6915ULL, 0xDAC70BC9EAA2AE07ULL, 0x45F5852672260D7AULL, 
            0x5EE9F469D8880030ULL, 0x9C18D005CABC91BEULL, 0xFB5BBA3B6EFD8FDFULL, 0x96343AE88FB15873ULL, 
            0x575A1FAD1AE39833ULL, 0xD2ABB5EBFB6340E1ULL, 0xE10077D86B723098ULL, 0x768BAA6EFE5FEB9DULL, 
            0xBC158643E6E55DD7ULL, 0x4980E28D4DE8CEDDULL, 0x8DA44FA2A75E2711ULL, 0xFD28EAFDC64BD6FBULL
        },
        {
            0x31707997FEFF8E9DULL, 0x26F6007787E14BCCULL, 0xAD7A0F2E43AACF11ULL, 0x17947E414ADCF0D3ULL, 
            0x34143852AE3D46E1ULL, 0x464B6724C1316F95ULL, 0xF57BE32B12DCE231ULL, 0x0B006CE2FC664EB4ULL, 
            0xDE1A1F1EDEE6E2A0ULL, 0x5DCC55BE441044F7ULL, 0xA92B0C2413A1B13EULL, 0xCAEDC85B6CB1F6A6ULL, 
            0xEF53689E0944FC66ULL, 0x31F6DD136D8C9F9EULL, 0x0434302B1CB16AEFULL, 0x016B95C3A945B99CULL, 
            0x5582EC817EC81924ULL, 0xF2B7062CC404E2BEULL, 0x89846F7DD674BF5CULL, 0x84C2F8F5CF22EC38ULL, 
            0x23A2C3A512912FAFULL, 0x90187DC03430114AULL, 0x4723F0C2A2AA4F67ULL, 0x34A53FCE3C44F9A9ULL, 
            0x0ACDBBF9D990FD41ULL, 0xE44EA1C2062013B1ULL, 0x1CCAC3B6BAA5D256ULL, 0xE15B61F52A5213DAULL, 
            0x1A8ABE60F69BBCC9ULL, 0x4775702579819199ULL, 0x23A19E6AADFD06AEULL, 0xC3AF43B9EF8D1ABEULL
        },
        {
            0xA0C7A4FB43434F9DULL, 0xD2FDC999E5FE2174ULL, 0x4C6483FF83ED913EULL, 0xA74E97FF8768670AULL, 
            0xA627CC3EE572DF52ULL, 0xCDF9D0ADAF883770ULL, 0x9487D7DDABDB3410ULL, 0x2AE5F85F42F95CEDULL, 
            0x3AF96F39DCDD83CCULL, 0x04044A5DBAD42D6DULL, 0xD045E277CC01C255ULL, 0x46C3A8087C0E7042ULL, 
            0xAD0B5297C198B5D6ULL, 0x52054ECDCBCC069EULL, 0xED10377A167BC3BFULL, 0xA60E68CE1C516D5FULL, 
            0x5D4B28DFF1A2F6FDULL, 0x60DE72497501A151ULL, 0x51F2CDB403A00FC2ULL, 0xDF840806605035B0ULL, 
            0xA67620122AC61FA4ULL, 0x4B5C66F404B4FB28ULL, 0x2C5C5095233BED1DULL, 0x95ADABC5B6CD1D44ULL, 
            0xF35EAC6EC9303089ULL, 0x3E410A36CF535F87ULL, 0xC10B095BD5EF73FEULL, 0xD65F1AA50E2C8763ULL, 
            0x812BEC46FDF1455EULL, 0x8D7BAC439CA3FDEAULL, 0x2C5E76CBBDA9CBF6ULL, 0x16A620B72C502B76ULL
        },
        {
            0xE337B1D412C23054ULL, 0x96971B3BE5BD5EA9ULL, 0xF2F7816031978338ULL, 0x057F108470E8F6C7ULL, 
            0xBD9A7F4EA63A2498ULL, 0x6333028090527436ULL, 0xC27CE6F67B8C9690ULL, 0xD2047283C9B9194EULL, 
            0x7C1C50CC537FBF02ULL, 0x26818C4B5A18F475ULL, 0x733424E273A274CCULL, 0xEB7500D112741C0CULL, 
            0x52B88DAE145BB15BULL, 0xE3F3309154AA10F7ULL, 0x68D01DA2AC8D4023ULL, 0xAE4286D9E60BC20DULL, 
            0x5859C61A1AFF08B0ULL, 0xC3D132A3E5A2F285ULL, 0x215EF82E14AAEF30ULL, 0x799547812D41388AULL, 
            0x43525F58E8E62DE8ULL, 0xB5F7095F3D8F226DULL, 0x7F2E6A0DD381A273ULL, 0x5572B07415007694ULL, 
            0x5678A9F432C1D277ULL, 0xAB19EA4FD0B51020ULL, 0x2A92964672E20E98ULL, 0xBFEA5A54AC66FF8EULL, 
            0x75DCB2DDE204E77EULL, 0x3C8B1B61CFE6D6B9ULL, 0x3A8D9CCB34B3429BULL, 0x555F0BA4362F49B2ULL
        },
        {
            0x5A9EF65D6B6FF969ULL, 0x7F0F13FD5942D450ULL, 0x378B630EB5FAFEDAULL, 0x453C6E1249058256ULL, 
            0x59DCD4D0AFE17413ULL, 0xC693AE3C35B7C522ULL, 0xE9B4AE763BCAB223ULL, 0xF330E541E5A1CB1DULL, 
            0xDE95D00AF07FD551ULL, 0x4905D41E4C14D633ULL, 0x317476FC45A4E345ULL, 0x8ECE13794E95E179ULL, 
            0x7D4C8575C59624E1ULL, 0x9B1F6A5412DB60EEULL, 0x12C4AC7429F7DC4CULL, 0x765FBFFE0A1CBC75ULL, 
            0x4F3DCBBAB2950321ULL, 0x20E78CA46286F8A4ULL, 0xAB83D095FA837362ULL, 0xF2D6D193A4898511ULL, 
            0x8B805ED8A51890C6ULL, 0x97B99548667EA76EULL, 0x26D5100A63167B52ULL, 0x759C63396A32F5A0ULL, 
            0x1B1D01485792F23FULL, 0xDE9EA1E2CCF167A7ULL, 0xDB98863D896651D9ULL, 0x56EA99807283A876ULL, 
            0xAFC6CE06EDD18D61ULL, 0xD0D9A2865A99D173ULL, 0x0DF6691716C75814ULL, 0xAA049714291D1FB1ULL
        },
        {
            0x56BF46A4BEC5E487ULL, 0xE21AC8AA750F4922ULL, 0x4491E86C9491A921ULL, 0x1D27FED2D82CB065ULL, 
            0xDF165E325B9CAF5BULL, 0x03676CE80B590DEDULL, 0xA8344B1ADB8D062CULL, 0x9F4DF39EC16B1835ULL, 
            0x5E6AD191B4B57503ULL, 0x14A24BA3E3BFB065ULL, 0x50E27D7F16AFD171ULL, 0x4E7EA248D8C18878ULL, 
            0xC1FFEBE45FD5C375ULL, 0x1194A3A383F52E25ULL, 0xCCAE743F2EFA6C67ULL, 0x860288DDD4B46EE1ULL, 
            0x56D3128041233E78ULL, 0x7EF77139F5FA500AULL, 0x8C8557890B399DEAULL, 0xB9B255309EAE7AE3ULL, 
            0x9EE9C13360666098ULL, 0x759061F825615008ULL, 0xD4C61CAF3EF98E06ULL, 0x6B133800F2656C72ULL, 
            0xB65FA436A46EF581ULL, 0x06A50A57BA212B8FULL, 0x7EE5ECC1BA2744EBULL, 0x3BCAE584830B2F3BULL, 
            0x1D248509A9C6A7D2ULL, 0x09F08C8C99253BE3ULL, 0x3B8620A03958322DULL, 0xFD1A54380D61912AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeyRotateBConstants = {
    0x0BD9E800532FD2A4ULL,
    0x70BFA640EF341B4CULL,
    0xFCFFFC1C199289EBULL,
    0x0BD9E800532FD2A4ULL,
    0x70BFA640EF341B4CULL,
    0xFCFFFC1C199289EBULL,
    0x7DA08BD88B905EEDULL,
    0x3DAC5FFD8ACC1477ULL,
    0xEE,
    0x2B,
    0xB8,
    0xD4,
    0x31,
    0xB4,
    0xA6,
    0x7E
};

const TwistDomainSaltSet TwistExpander_Vega::kKeySpawnASalts = {
    {
        {
            0xFE38F04C1B283E72ULL, 0x77F75481346C3AD9ULL, 0x8737DD6F50BB3747ULL, 0xB75DE60BE2CD8614ULL, 
            0xFE21F7CEE7A736FDULL, 0x082B8DDD315BCF65ULL, 0xE540A950D4653DB9ULL, 0x930AF0F903C2A561ULL, 
            0x7E0270BC8DCCD2CFULL, 0x07E26384D73E6923ULL, 0xC5528335C587F46FULL, 0xD5B4E8F4E8F0A1A9ULL, 
            0xDA00FA7EDF49FFB9ULL, 0x0CC36671378FB8C1ULL, 0x072E6550BDE5E9B8ULL, 0x145247DB761FA3D6ULL, 
            0xB091A33001BBB922ULL, 0x26822557B6B6377DULL, 0x2DC2A3F6D1563CFEULL, 0x79DA64A4CE7B1335ULL, 
            0xAA021E22C2AF4F91ULL, 0x1714664E2E7DBC07ULL, 0xB390739C70A4D7D3ULL, 0x4A8E35FD828981BAULL, 
            0x5AFB7CC1B0787EFBULL, 0xABF96EC1DBF21613ULL, 0xCF9C332854E3CA0CULL, 0x7F4ECDBFEADD3C5BULL, 
            0x78F26E3F08DF00F7ULL, 0xABA66E499FB20446ULL, 0xAE0B8B0BC3DEDBCCULL, 0xD09AC2583724D3BBULL
        },
        {
            0xC2D8685D2F657F92ULL, 0x24092B2BCD9BBFE2ULL, 0xD8995F753DAFDD5DULL, 0xBBCFCBF4C5180596ULL, 
            0x7FA01956A2521CA5ULL, 0x69E7A83B039806F7ULL, 0xDC880A22D5FF97D4ULL, 0x4911C8F45B64B836ULL, 
            0xD245934C3E098233ULL, 0x8333DF223428297EULL, 0xCAAC5A6757568142ULL, 0xC53DD83420038D57ULL, 
            0x9076D066A42F2159ULL, 0xD14EACE1BAE00D90ULL, 0xF5BC5E0B3E7D12E3ULL, 0x8D9F45360D49079DULL, 
            0xDFDC585DD656396BULL, 0xC07595FD96458139ULL, 0x2F5E0A61805F4BE5ULL, 0xAAFB9F96414EA8C9ULL, 
            0x32B015FE7E67E171ULL, 0x8297A211278DCDABULL, 0x1C20A2A026EC0D77ULL, 0x5FC55F799C7E2884ULL, 
            0x74E3AE1BF07554EAULL, 0x578902B34B2FC4DCULL, 0x9D31AD22D2A573F7ULL, 0x802375871492BFFCULL, 
            0x9B574C1C422C2C24ULL, 0x90B77A64FE26BEA1ULL, 0x90AD5DADFB81E389ULL, 0xB88C80D9D8C019A3ULL
        },
        {
            0x3D0E85ED555B9EC4ULL, 0xEC3767473CA43FAEULL, 0xE20DEC8F8C92E20BULL, 0x939D5BBC4C11E250ULL, 
            0x00F50C19EED298AAULL, 0x177FBABBDE852D7AULL, 0x33B0FEC3552C2A77ULL, 0x15BC42DE84285419ULL, 
            0xC4E022029EC37AFAULL, 0xE39221ACABB5FE24ULL, 0x634852DB7A3847ADULL, 0xC078350B60BB8F5EULL, 
            0xA33DDCEAFC572B3EULL, 0x9EA26C8B16814737ULL, 0x4B3BB82F56ECAFD3ULL, 0x783DC6DA24E3EE0CULL, 
            0x3CE311338756EAFCULL, 0xBB3610F00353D676ULL, 0x7AEED1411D84861EULL, 0x061644ACE7E97AB0ULL, 
            0x1F529366F2F56EAAULL, 0xDA89CCA0CC207526ULL, 0xA9DCC5542DA24E93ULL, 0x8C8148A4FC315A89ULL, 
            0xAACBF8C193AA7D11ULL, 0x4615579C544AB086ULL, 0x89777B1EF2CEF260ULL, 0xC443E14A47794C6BULL, 
            0x9926288F818A505EULL, 0x71A8BF5DB6AB692CULL, 0x3852D55C1A563E04ULL, 0x660B8178C3B90005ULL
        },
        {
            0x5BFBFACCF3D3661EULL, 0xC9259F413F28CCFDULL, 0x859A8DE76E93BCCBULL, 0xECE688B07C68FC30ULL, 
            0x016628A76B559233ULL, 0x6C6119C49C024053ULL, 0x9B5D4C0E68D1AD59ULL, 0xC08F0CF3775667A5ULL, 
            0xF9E477502CD66605ULL, 0xFF1B29F715622C50ULL, 0x18982D93BFA20608ULL, 0x753618454564667AULL, 
            0x175E8712EF418D86ULL, 0xD13DFEE00E6A62C7ULL, 0x6A9AE1A1E6FAA09FULL, 0xE326DFE4CBC82ED1ULL, 
            0xA2B4C2EE87FC3E5AULL, 0x48E62801EF5A95E5ULL, 0x325894251D6FEAB8ULL, 0xAF0946D08B0DFCB4ULL, 
            0x29F039B6734480F3ULL, 0xA45F9FF55027D2D1ULL, 0x4FF1FD143B67AF41ULL, 0x9E0EFAC45A32F410ULL, 
            0x0749EF9116255414ULL, 0x37851718A9139A01ULL, 0xA8733DC7B4BB189EULL, 0x51D2F9F664F334DAULL, 
            0xD0CD9EF810D60BABULL, 0x01FDF50A5F2B0C83ULL, 0xE40BD9123A8549FAULL, 0x3737B52460ECBC53ULL
        },
        {
            0xB668E5D7932ADB53ULL, 0x1703F437A68A8C93ULL, 0x853CD77416736E60ULL, 0x82D75469CF8E202AULL, 
            0xEF4ADE12B6A2FD4BULL, 0xA3F5505D32D2FC1DULL, 0xD3E4022992CD2C2FULL, 0xC0A7A3E14C085DF8ULL, 
            0x40CA6681F7887C8FULL, 0xAB05EDFC3039464BULL, 0x156990A560474C39ULL, 0xD4283AD80164D778ULL, 
            0x20EBD3FC92AFA834ULL, 0x64FCCB412EA87936ULL, 0x0F3742810E3485BDULL, 0x143687D18930E865ULL, 
            0x19666A76D9A022CCULL, 0x59BD382AD8972031ULL, 0x235D033F8A90CFC7ULL, 0xD2E55FA40BF14752ULL, 
            0x1BA7EDADA2A0211DULL, 0xE1440FB09DD58C51ULL, 0x50F119A1B86F50D1ULL, 0x68D92AF20DED5EC7ULL, 
            0xEE86E96E55BD318AULL, 0xF4186C8F4FF1D197ULL, 0xFED007FBADFA897DULL, 0x9301632E4CA99A40ULL, 
            0x38F66E960D627D0FULL, 0x0A5326BA1593DC4FULL, 0xB46CCA79CA3316E7ULL, 0xD64848BBE8932B19ULL
        },
        {
            0x704E632208FF6C9CULL, 0x0DB0B11F2D526FC1ULL, 0xB49045A510F4CAA2ULL, 0x7FEC69D28EBA10FBULL, 
            0xD3B53D538DA7865DULL, 0x9E7779D3D411AD21ULL, 0x717D080A199BBBC4ULL, 0xAE8FB921B0D97818ULL, 
            0xF5D8D87314C6C3E5ULL, 0x244748C72D320BD1ULL, 0xF53DD8F82C0E7A89ULL, 0xB70782F8234E46BAULL, 
            0x63B61506C1269068ULL, 0xBF4D8AEDD3CE1713ULL, 0xBCB309740423EA35ULL, 0xADA336913E0DF420ULL, 
            0xEEEE88D487E3984DULL, 0xA4BE5D05762B6A80ULL, 0x7B11F0E47F16AC54ULL, 0x3869A880E92CBA11ULL, 
            0x960FD40601994AFFULL, 0x4EB5BF2BC7638A44ULL, 0x33454D97DF90D9D6ULL, 0x4F4889377EA24E8EULL, 
            0xF226EE450F70F264ULL, 0x17413B526DAEF181ULL, 0xB23E86D2B371E8C4ULL, 0x1AF4398D3CED36D0ULL, 
            0xF7CECD63475F1583ULL, 0xBB17681C1B4EA864ULL, 0xC8AC643C84532005ULL, 0x21A9601204EAE448ULL
        }
    },
    {
        {
            0x6533429416D7E08CULL, 0x718914C74FD706EEULL, 0x4646B792CDD334AAULL, 0x22F892C74D1E16F0ULL, 
            0xA4E469405BD9DA62ULL, 0x2EC01954686CB4C8ULL, 0xC97781961FF5FC25ULL, 0xE648EE4FF692E224ULL, 
            0xF2A58EB56048C452ULL, 0xC1AD5F84CA54C749ULL, 0x94C47BBE74541C02ULL, 0x88BF780179D12C5FULL, 
            0xD77B80F91897E332ULL, 0xAF4D401F90196002ULL, 0x5429B4C00644750CULL, 0x75B1321EBFEB1BA6ULL, 
            0x468A03BBD3E25BDEULL, 0x7428C4A280EEE9D9ULL, 0x334CA969496C2A52ULL, 0x7C7A8FF1B220913CULL, 
            0xD2E058DD83B7DC80ULL, 0x3E68263A3D06D300ULL, 0xCECB052AF733DB87ULL, 0xDC0F20D85C0CE7EAULL, 
            0xF5E6EBD0C30EE1E6ULL, 0x0707B8E94323E3F7ULL, 0x98F47FDF40C417C7ULL, 0xB2909E3A129A6423ULL, 
            0xE0F71A21C63BBC87ULL, 0xC18A545BD96B452DULL, 0x56865AD7820E4237ULL, 0x218C628441AFCC5BULL
        },
        {
            0x4E2736AC9365CC47ULL, 0xBA8A59BA4ECCFD8BULL, 0x913C0CA5735C05B6ULL, 0xEA6CA94218320752ULL, 
            0x18CF0D13F282C4B0ULL, 0x2F6843985F622100ULL, 0xB6C30EF10600C497ULL, 0xE6BCFF46A38ED528ULL, 
            0x326FA5AC7FE37A47ULL, 0x62A7A951B58A6FC1ULL, 0x3FEA396E6DDEF83CULL, 0x09FC484E0B178223ULL, 
            0x21E5551BC16253E9ULL, 0xFD308108244631DAULL, 0xCD0E174AC713DB8AULL, 0x38C323D6CBADAA45ULL, 
            0xA6026DD51C657C34ULL, 0x9DBCED576C9D6C46ULL, 0xCE6DFCDF4266D37DULL, 0xB23FB891897D7495ULL, 
            0x06199D38A2B0953CULL, 0x6CA2B41BC95DFF9EULL, 0x5AE0AC27EED2EC8FULL, 0xDDC9642FA37A9DE0ULL, 
            0x2917F9F6BD8B7D62ULL, 0xC4D597D7907EA968ULL, 0xA1007C543B89D666ULL, 0x45F855ED811EACD0ULL, 
            0x136B73D663F04677ULL, 0xF3F85267639C1562ULL, 0x0C05B1C3202A6673ULL, 0x424CD25C9DA3F52DULL
        },
        {
            0x25D1A03446FFB6FAULL, 0x131C82D9DE4759C3ULL, 0x0E00F9278B66CFD3ULL, 0x004ECB3B0442023CULL, 
            0xF67D70025F068B16ULL, 0x4983C4681D43C1CAULL, 0xBEDE47CED992046DULL, 0x0B2812838705D444ULL, 
            0xBE974B4B8E8D7860ULL, 0x3E9CA167C831535DULL, 0xC1A257C9E2EF88A5ULL, 0x1ABA605F9856A071ULL, 
            0x618D9E9A83458127ULL, 0x9F5000AA306738CFULL, 0xFC7B4E7B1E7405D8ULL, 0x38C44BC594885A82ULL, 
            0x0C301CFDC4F728CDULL, 0x632962A48762DBFCULL, 0xAA0AC424B0310A30ULL, 0xD76D46ECF4DF5AE3ULL, 
            0x22459B0EDE542F04ULL, 0xA2FC76D1C9C60054ULL, 0xBC261312CB6B52CDULL, 0x1AB9F5F0D7755A5FULL, 
            0x6F668492B4EC64FEULL, 0x175F0E46B60344A2ULL, 0xD784869C66260875ULL, 0x2B1C046884D76733ULL, 
            0x6225E66EB097DAC8ULL, 0x7893C469E9AA5525ULL, 0x8138092898D12BEEULL, 0xFA7FF1254C19B29FULL
        },
        {
            0x64A93B6AF14DBF0FULL, 0xE39146A8F3A85114ULL, 0x99D8A5EDDB009567ULL, 0xBD80794184CD7CD2ULL, 
            0x1A409C9EECEE3BC5ULL, 0xDD1FF79092F718D3ULL, 0x2FD67E569A088502ULL, 0x115550878C947927ULL, 
            0x3DF9FA5785F3F67FULL, 0x840B2BE9ED06628EULL, 0xA7ECCEA63D212FBBULL, 0x801C61D6DC3C891EULL, 
            0x8BD22196E6B062B0ULL, 0xE0164807ABBE4D7EULL, 0x3C60C2575C13C10DULL, 0xFF1D6F8DE2FAEF4EULL, 
            0x47E6408B30399DE4ULL, 0xD2DD48BA9544F781ULL, 0x69C2D0EF8B0B8BA5ULL, 0x32DA73CD90A3B8A6ULL, 
            0x92FE9394AC6DCCD9ULL, 0x306A1137AEF876F7ULL, 0xE45087ABBEB9FA10ULL, 0x04C8967682DBA2E1ULL, 
            0x65FC309C039B0B32ULL, 0xC20DCB5C2395246FULL, 0xA51E555DDF9CB65CULL, 0x6F9E778E4F4E914CULL, 
            0x7BA372F91755D92AULL, 0xE7D6BA63413ABB8DULL, 0x5603A2829B9690A7ULL, 0x0F3A0C1B52CCA530ULL
        },
        {
            0x3826D90B785F8FDBULL, 0x166DFDA95BC1C9B3ULL, 0x4186C9E6B869B469ULL, 0xCA756467E1D78E7EULL, 
            0xAD2F96B85E4B34E0ULL, 0x169FB3AFFA804C1EULL, 0x3FEA879FF9BBB76BULL, 0x87320DE891856AF9ULL, 
            0xB35057879C540FBFULL, 0x78CF03370FF119AFULL, 0x3234FE152F4FA4C8ULL, 0xA2F0C5CE2729FD5CULL, 
            0xFFAAD04C3E9279F3ULL, 0xC3632A2D84ACF338ULL, 0x8BB8D22A6CD514A0ULL, 0x1B0DE562FA338F9EULL, 
            0xCCEAD681A43C6C87ULL, 0x6EB4361272153CCDULL, 0x25D900AAA0FA363EULL, 0x9DC6812201E030DAULL, 
            0xAB6E0FAB56DF7B4CULL, 0x5DECC7BD727226BEULL, 0xF3844CD4DA793B42ULL, 0x7E8DE91F553C9B80ULL, 
            0xDE84F481669248F5ULL, 0xF766B1813FBF7103ULL, 0x30DA23614C31795EULL, 0x64C3702C28E5AB3EULL, 
            0x7108C1AC108E9027ULL, 0xFE6C202DBCB18BB1ULL, 0x9D53E2E46136BCF8ULL, 0x61328ECF258E47B8ULL
        },
        {
            0x398C91449A280145ULL, 0x7D003AD5F47E420CULL, 0xD00A8B0D017B43C3ULL, 0x0823031FF094CB7CULL, 
            0xA268E9C4EB06E27AULL, 0x0924F0BC91E79193ULL, 0xB0B04A4EC393254EULL, 0x89E8E5BAE5CDA380ULL, 
            0x2E3039D3E899691BULL, 0x9A16450837401A16ULL, 0xAA1D6E6B25B7F8D9ULL, 0xF51CB9B5518CE0C1ULL, 
            0x49F71C5EBA693644ULL, 0x67BEDE9B12AFCED1ULL, 0xBA313BC9CC1C684AULL, 0xF8CA184498CDDA5CULL, 
            0x5B615E25087BD258ULL, 0xD5DCA4BA3D7C8E32ULL, 0x4C9C9385966BDBF9ULL, 0x0494A50B84EE7CBAULL, 
            0x98A4F464110E0CEDULL, 0xCF075033F9BE3393ULL, 0x240CD742462A0420ULL, 0x900798BD5A5ED9F5ULL, 
            0x0B0C55523FE6CC86ULL, 0x49AB091F314B5590ULL, 0xCF95C8B2FFCD5B53ULL, 0x98FDC72FAF171983ULL, 
            0x0A091D26276E5F76ULL, 0x2CA0BDB47634B84CULL, 0x4C03BC8A762AEC90ULL, 0xD32ECF0DB39239E3ULL
        }
    },
    {
        {
            0x7BDEF7BF8F87AE6AULL, 0x011CE842D90D8592ULL, 0xD58DAD5D96A7E943ULL, 0x7A7240D77F3A3464ULL, 
            0x710501D152EE1679ULL, 0x2188D94C602C58D8ULL, 0xC32157CF7928210DULL, 0xD9FA8815A62A06FCULL, 
            0x9810689854251900ULL, 0x84BE7A2476C33AF7ULL, 0x82CEEF797D3CEF1EULL, 0x63C8D68DB7DC62B2ULL, 
            0x3AEB4587C33E2C10ULL, 0xA1C9BFC472E7C8CAULL, 0x33756F6A471EBB9AULL, 0xC6C8EFC1A1215F83ULL, 
            0xD3A02A43A57ED464ULL, 0xA249567BEF60EF3EULL, 0x5D705A055B846DD1ULL, 0xB01F7C6DA4E8C767ULL, 
            0x3F4E9B983B86D17BULL, 0x8111707432A269DBULL, 0xF390A4C4AEFA85D9ULL, 0x01EA8E4C4E5E0A00ULL, 
            0x5441CC06D0222A8BULL, 0x72B573EBB0CFA85DULL, 0xDA6D1507867CE963ULL, 0xE6AE383CE4DC6EEDULL, 
            0xDD8AE857DA46D4DBULL, 0x1E43E86F33B03547ULL, 0xDC6F955BBA0A213FULL, 0x9C34191B45081D0FULL
        },
        {
            0xBE7AE176775AE355ULL, 0xE1D70A8730B85BF5ULL, 0x5501A64432E80B8CULL, 0xAA001BEB126F43CBULL, 
            0x7580A277F920715CULL, 0xBD4FCA2AA95E2D9EULL, 0xD11A0EFE9A374A22ULL, 0x07939FA07D9D2247ULL, 
            0xC8F7E3DC189FA810ULL, 0x69E4C3D01CA2283CULL, 0x5FD25C9FBC6D398BULL, 0x504105484615CD72ULL, 
            0xE3C5C50D0D76E8F0ULL, 0x1EE2A7E3770F97C6ULL, 0x7FC67D8F96A058EFULL, 0xC2C9FAE35BF6D8C8ULL, 
            0x75FF325349B42991ULL, 0x40C6D892A914E208ULL, 0x29874406EADB3989ULL, 0x3F4F2540D89B36A1ULL, 
            0x17D6B530A9E41081ULL, 0x0871E37B69B5F6D8ULL, 0x82B821D5120D3786ULL, 0xD93EA2C6E7C69FAEULL, 
            0x550190627ECE39C6ULL, 0x077696DCD32E99A3ULL, 0x7CE624C54573F57BULL, 0x1F8260B0922041DBULL, 
            0x7BC70684846081F6ULL, 0x9D8A896329D138AFULL, 0x43769DDB243A4896ULL, 0xE1950CF09162E0AAULL
        },
        {
            0x6F5B4112846D8AB1ULL, 0x3221D5E4FE3B9BA7ULL, 0x72436375DDD1AFE1ULL, 0x4F381CC8498D96D1ULL, 
            0xAB4930339701BA1EULL, 0x60F2BF7E2C606834ULL, 0x2B8EC97A4FF25022ULL, 0x4FDB923D01CBDA06ULL, 
            0xE5269D0E256063BCULL, 0x927267FBD2390BA6ULL, 0x7249BC4CBA695279ULL, 0x19581A5C95ADC88CULL, 
            0x0EEA9D8796E43CBCULL, 0x9AF236124DEAE4DBULL, 0x66D761B60BECC426ULL, 0x4C6021FD9443068DULL, 
            0x2D3658ECF1C5A510ULL, 0xCCE4503DBBCDF348ULL, 0xE484C0B667446991ULL, 0xEC5748C3C68C6CE4ULL, 
            0x11313BC3B08C4DB8ULL, 0xAD3423D02F4564A4ULL, 0xC195B2A5428AF659ULL, 0xA9BA04492CCBD262ULL, 
            0x81943C539724931BULL, 0x024E05809CE17168ULL, 0x2C39F49F7EA10025ULL, 0xB4DB66533535B974ULL, 
            0xE0F8E97AAE1F4E03ULL, 0x83596F7C3EBBA59AULL, 0x3376751A7B8D0CA7ULL, 0xE8C131066E873AA5ULL
        },
        {
            0x7F3BE44FCCCC948DULL, 0x83F18AA7431FA893ULL, 0xE2BC3B5DFB76D996ULL, 0x26F0019A09627FEBULL, 
            0xEFF5FE34BC8F1496ULL, 0xAD0CA39D0C1BC745ULL, 0xBAB0F8AFCFDAC2F4ULL, 0xDB6712CF53EE7A95ULL, 
            0x735D15442BC01201ULL, 0xFE94A7013F42D5E3ULL, 0xAC48CA1960DB1933ULL, 0x15200FB8B934656EULL, 
            0x2D14A1262BD3621DULL, 0xF45A0EB3A78A0EB0ULL, 0xD31B31F59BA031E9ULL, 0xB37AAD041C0EFAF3ULL, 
            0x5449CC3B88A86A7EULL, 0x4BE1AB04D1299A99ULL, 0xA171C7498E1657C5ULL, 0x55148E9DD6432036ULL, 
            0x74924F10C5FF8D32ULL, 0xE482B04D2C73B3A3ULL, 0x650A7823AE012AB4ULL, 0xBA3143CCC6E08A30ULL, 
            0x4214A55B2C73B59EULL, 0x97C8EAEFFB350B93ULL, 0xDB117DB3511D7DFEULL, 0x12CBDAA262BEF9EBULL, 
            0x30691F972F437D0EULL, 0x7ED82179683DDF62ULL, 0x72F66FF7C57389F4ULL, 0xBE9740E2B452D878ULL
        },
        {
            0x7BEB8C0E02641916ULL, 0xD41E9AF71E85E8BCULL, 0x4D308A39957ACCC6ULL, 0x375E117673F1829EULL, 
            0xDD1DCB3BA5254660ULL, 0xF590ED95C3B80695ULL, 0x0FAA0C6D8C437DD4ULL, 0x8623993A89E116D6ULL, 
            0xCBFDDD580C54B652ULL, 0x183B7C83EBBC12D8ULL, 0xB6702B1ACB5727F6ULL, 0x3D22A2CEA76414F9ULL, 
            0x940A12BE720F54BDULL, 0x968866854BDCF09AULL, 0x6758ADC4258F8BA6ULL, 0xCB96422ED4841CFAULL, 
            0xC26AF474F0983016ULL, 0xEA9B37591A6ED74CULL, 0xCAAE1483988F9BB3ULL, 0x6F0E45467B423CC8ULL, 
            0xB25E5AD6B2A2FC94ULL, 0x413083FD2B0ADF4DULL, 0x433F135C46D5381DULL, 0xA86C1BF99F31A9F1ULL, 
            0x9A202321EB91238EULL, 0x7CCA5522D36C1802ULL, 0x086F0A7896C520A9ULL, 0xFC12720E52C40DFDULL, 
            0x9F0A3EE2C07F0DC3ULL, 0x7C0A48D5B336FA0BULL, 0x25FBA91F61792232ULL, 0x15DD279519423000ULL
        },
        {
            0xC9665BA0FDCBC594ULL, 0x28E5FEFF01A50E90ULL, 0xFBB827DA8219037FULL, 0xBB624A5F9208894EULL, 
            0xAE2D9DA938B5A36FULL, 0xBB86F41E146D7780ULL, 0xF6237D675C55FF83ULL, 0xC1E8D312CFD43CA4ULL, 
            0x576EDB422FC30589ULL, 0x7D36B28BBA0EDE6DULL, 0xC6FD2FDCFECF8604ULL, 0x302D203D4ADF4EECULL, 
            0xFF5AA93F13F7C15FULL, 0x40619C583A1234BDULL, 0xE5D2D33585E183E2ULL, 0xE86B84AD3CA85FAFULL, 
            0x83BEB1BE3612A1C2ULL, 0xFC57250FBCEB545EULL, 0xCABE0E6A877B68A7ULL, 0x5503E689EEE77BAAULL, 
            0x28DF938D4CEC879CULL, 0x7FCBD691788BA741ULL, 0xD2D67EA00F6DCF39ULL, 0xB7CDA30936BE79C7ULL, 
            0x413D8351DA69E93EULL, 0x0A2379CBA81E6CA8ULL, 0xC42D19D5340EB6D9ULL, 0xA4F33BF1F62E6714ULL, 
            0x3BE9FF00DD560164ULL, 0xDCC849EDCFB08D26ULL, 0x592C9D805FF56363ULL, 0xFF311DC152878322ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeySpawnAConstants = {
    0xF24351A99551BFF1ULL,
    0x07B5B56946BEF268ULL,
    0x733984185C1520D2ULL,
    0xF24351A99551BFF1ULL,
    0x07B5B56946BEF268ULL,
    0x733984185C1520D2ULL,
    0x5FE6849FDEFD024FULL,
    0x7592C9A8828B0ED9ULL,
    0x13,
    0xB8,
    0x1B,
    0xB4,
    0x0E,
    0x30,
    0x2D,
    0x5F
};

const TwistDomainSaltSet TwistExpander_Vega::kKeySpawnBSalts = {
    {
        {
            0x257F00AE4C0481AEULL, 0xD561CEC1B67C4AB8ULL, 0x960B93637025248CULL, 0x2B0E73D47C4A87F8ULL, 
            0x0D37B14E96AA2D57ULL, 0x275BEF7F4304EEA1ULL, 0x16CD6DABC695521FULL, 0x60D0A2A76CC3C715ULL, 
            0x1833752B1EE84FBEULL, 0x2A7C7675CA5A80CFULL, 0x3FFA6008015B0CABULL, 0xEBD0651843066474ULL, 
            0x83E8B319A2F6AFBBULL, 0x73D0714847EAFAA0ULL, 0x131B41FD176C5CE9ULL, 0xFE9DF3ADF1AC9966ULL, 
            0x814D53580E24FBE5ULL, 0x1C11C50E30ABE74DULL, 0x59B5F83ACB33FB93ULL, 0xE55A72FC464BF9C3ULL, 
            0x0CB2C6D02BD371CFULL, 0x3FA6C35DA58CF4BDULL, 0xB98A81E04C08E150ULL, 0x353C97F41EACB3DAULL, 
            0x9B544DDF16929681ULL, 0x49090B1D03BF0EA5ULL, 0xF4D7FE5045D2F6F9ULL, 0xB8A6AD6B64B641EBULL, 
            0xEB991D44040B1BACULL, 0xA2EEED1F048DAF11ULL, 0x7CC068116F309364ULL, 0x5D49B2A091F93A62ULL
        },
        {
            0xCD340F5D36C6D1B6ULL, 0x8DD43AA167522934ULL, 0x41C73390861D7243ULL, 0x13B43BDD6C4EC378ULL, 
            0x707E0BB8D5800567ULL, 0xDB93B28002B4FA25ULL, 0xF162C10B3F99745CULL, 0x0200F2089500AB82ULL, 
            0xFEBEAFDF541607E7ULL, 0x6836B94AA81523F7ULL, 0x65974FC3D453A235ULL, 0x1A92218BC733FF78ULL, 
            0xB1CF68B40309D338ULL, 0x54FA3574B9959009ULL, 0xC2D3DEF009420C32ULL, 0x9F1FDAE9CBB906A9ULL, 
            0x460701AC00AEDE27ULL, 0x3A857956E0628BB0ULL, 0x1D0977FBC783D5C6ULL, 0xFA921890A9665F8AULL, 
            0xCDFFE53729D9A423ULL, 0xBEC477167325412BULL, 0x66EA386117BCED71ULL, 0xEBAA37061ECE5FC4ULL, 
            0xBC6B61C78DD44209ULL, 0x5AAA1C577FE601EBULL, 0xD797F6193FAE6B41ULL, 0x8DB343F8F1265990ULL, 
            0xDEC8463A5B038FE5ULL, 0x45822AB85FCFA6E6ULL, 0x23CDD3651A9D3524ULL, 0x057D2ACFF9001334ULL
        },
        {
            0x4EFC2B43AB640E34ULL, 0x3EDD3ED8DDD17E58ULL, 0x70AA46C87B461EF5ULL, 0x91789D481D5312A1ULL, 
            0xC842E064AD967D3EULL, 0xB6F8947D3821F74FULL, 0x6DAF795A6EE825C9ULL, 0x38811E21A1B6AF49ULL, 
            0xF3DCD4008E565346ULL, 0x2195C47194929097ULL, 0x95BCCE90F388656AULL, 0xE5C76680014BCA08ULL, 
            0xAAE4AB59FF808BA6ULL, 0x418D24F3FC0570F7ULL, 0x91AF14B9AE8A6C60ULL, 0x8328570511FF089AULL, 
            0x0A653306E84A5FCDULL, 0xBAABFDDB12828986ULL, 0x09B1202D3EEC3A62ULL, 0x860F108611ACB0ECULL, 
            0x3DF7312CB47D2467ULL, 0x0734BB872C3E0AB6ULL, 0x1C7C5F1A2E3C9985ULL, 0xC92B48B85C363700ULL, 
            0xA655C889560E7E77ULL, 0x4C7ACC9BE9D6FD8CULL, 0x51708BAF9DA3574BULL, 0xE808C91522DEB3ACULL, 
            0xC0EB00B8900E6197ULL, 0x0FD61397DC7904AEULL, 0x95E0B1FD1C7B3A30ULL, 0x5C3379E8BFAD3BE7ULL
        },
        {
            0x644583797015863FULL, 0xE77F0618DECF11ADULL, 0xB0F9A00D21525F0FULL, 0xFBB7B1438E825BDBULL, 
            0x08533196E73D377BULL, 0x79AD64FC806C1459ULL, 0x518EF0B3F5FDB4F4ULL, 0x53035E7D5FB653CDULL, 
            0x019394888BC1F1E1ULL, 0xF69636CB579DDB93ULL, 0x34A7238BC440F7D4ULL, 0x26FC4A7D0143838CULL, 
            0x944F58DDA47C7386ULL, 0xE25F787ECCD5A4D3ULL, 0x26361F43C2758CABULL, 0xC80A2CD747DF0719ULL, 
            0x4893B0E267AC5F26ULL, 0x1758769B87A16333ULL, 0x593CB2383CDE4BDEULL, 0x0C3500F33237B2FFULL, 
            0xA063A4FD1862CDF9ULL, 0x4B5B4CC2E381A62BULL, 0x74772ACBCBF98B70ULL, 0x394A5784C12EE570ULL, 
            0x5272E06854341FEBULL, 0x0172E754CBEDAF52ULL, 0x609750D8AECD4D37ULL, 0x9F03B1911E51A33CULL, 
            0xF9D99068477955C8ULL, 0x1A7C5BFE03A3B9D0ULL, 0x8869ACA8DBFF8521ULL, 0x03A7D13A0DBD44FAULL
        },
        {
            0xDE9ABF5AD3AFEDD0ULL, 0x1C41F9366FF11709ULL, 0xC9E79E11D67A2E6BULL, 0x97672C7B325F7235ULL, 
            0xD20B7D60DE185864ULL, 0x9616D41B69E09A9FULL, 0x7CC29B0217B7FAE5ULL, 0x904231EBDCF9E0B7ULL, 
            0xE1E0AF11D704F598ULL, 0x28A3D9F5ADD9DDB6ULL, 0x713FCCD5399C2BB8ULL, 0x691D65306EEFB6A2ULL, 
            0xE0AEE447B9A99001ULL, 0xC64E491C5345870FULL, 0x109192695832BA5BULL, 0x4F00506E3B3AE3BFULL, 
            0x526B6D4487A81ACCULL, 0x3DC44547883D39EBULL, 0x9213DAEC8368C228ULL, 0x7B6EDE49BDFC867FULL, 
            0x0B37AA00FAA335B2ULL, 0x3094261A9C7101C9ULL, 0x9A32C30D53C31777ULL, 0x7DDCE9D1202F74DDULL, 
            0x555C626E4964DD77ULL, 0x1975FA18FB196CFCULL, 0x58280B6928F10EC9ULL, 0x6514C110DCB62323ULL, 
            0x8F27886120A6E108ULL, 0x9A9FAE3AC82C776EULL, 0xE0F909052123ECD0ULL, 0x172BCEA9F7DFA592ULL
        },
        {
            0xB794CA9199BC6A9DULL, 0xDEE67CACAC953247ULL, 0xEBDE36B54F59244DULL, 0x96C541661ED6EAF7ULL, 
            0xB464777598566EF9ULL, 0x0DEE6EB5E8C8C7FEULL, 0xF41593CA85706105ULL, 0xB67CBBB6B59F506CULL, 
            0x61CD198FD543F5D6ULL, 0xE31DB67140EDE964ULL, 0x4863BD3D05F85643ULL, 0x8393A46F8BD0F597ULL, 
            0xC6DBA81D7CD943C6ULL, 0x3D18B9E250989F22ULL, 0x6FC79DC03E3A80B4ULL, 0xD3C4E75AF9C587B2ULL, 
            0x82ED463EEFB68D46ULL, 0x82D44DEF541E0076ULL, 0x8AF8CDCFBA4CB271ULL, 0x89AF25117FCDD913ULL, 
            0x4D8FBED1E63FCC6AULL, 0xFB3BF3ED46F3C300ULL, 0x24573726C5FB8670ULL, 0xC0EA46363A185C76ULL, 
            0x236C435F5D72BA39ULL, 0x6885D5D808CC3FE5ULL, 0x304CB4795165D845ULL, 0x8DE9D8FE8776C0DFULL, 
            0x45E4A981CF63538AULL, 0xE94EAD61416CB818ULL, 0x8B0F7CE3D5D2F823ULL, 0x07A6072B744D73A1ULL
        }
    },
    {
        {
            0x4942709D7B3100A9ULL, 0x39D0BCD168FEE459ULL, 0xFC7571CBC9C6C5A2ULL, 0x10EE7D766105EDFDULL, 
            0x2280BBC4C1E46AA7ULL, 0xFCCAAFA387C08968ULL, 0x23FE20800ACDE92BULL, 0xFD850AA44F4A86FBULL, 
            0x3D27FF7D701657EEULL, 0x675D2229B37AADAAULL, 0xF1B7FF37C9A64E14ULL, 0xFEE195A433B4356FULL, 
            0xF12261643133637EULL, 0x31C7E56C62382765ULL, 0x498B8E02FD15761AULL, 0x731AE0A6B4BAC8B5ULL, 
            0x10504437B7317688ULL, 0xC57D9081AF5C52A5ULL, 0xE02A681BFF66DC79ULL, 0xFBF9B4EABF3BB6E2ULL, 
            0x662488CD1107502DULL, 0xC4F76A79CECB16C6ULL, 0x4550CDB20777E6B7ULL, 0x59ADC6237F831643ULL, 
            0x02831C3053903787ULL, 0x8B7441C976E925FFULL, 0x4380DFD0F8122F58ULL, 0x8DEC25C883D14C06ULL, 
            0x7B32DC96AFBA3620ULL, 0x8C756CB7A80B8C26ULL, 0x2E48F5763E843383ULL, 0x77F9A0609CF7AE21ULL
        },
        {
            0x281605876B269C3AULL, 0xB07F9AD572502112ULL, 0x5DDE5A37364A6ADFULL, 0x8561A1B5E209733DULL, 
            0x5D18C2BC4E5540BDULL, 0xADB45831F385DD1EULL, 0x86A2BE66E39268C8ULL, 0x14C83BB0E98964C4ULL, 
            0xAAB80D2AC97E3867ULL, 0xBD83F53D115E3B5CULL, 0x1E8DC5AF1D9332F1ULL, 0x70EF06F09A2625BDULL, 
            0xF89742C8D4B10C5BULL, 0xC0AA0D192DA5A6F7ULL, 0xEEC51EF087968658ULL, 0x7879A2B498F1D57EULL, 
            0x3581813DAED79491ULL, 0x0615EFF24D6BF122ULL, 0x7FB89A66ED3DCB2CULL, 0x06B6B75F5C43E570ULL, 
            0x3BCDFEFE6E486AC2ULL, 0xBD2A2510E7F28CCEULL, 0xE78B214A0ACBBE0AULL, 0x5713C232A3DE3374ULL, 
            0x37F0A3406539334BULL, 0x43D032B4A021ACB6ULL, 0x798616C269EF0794ULL, 0x645AC06142733710ULL, 
            0x6CEAE333A43AE089ULL, 0x39C07745F4216A47ULL, 0x01FAD7D2711E2C9AULL, 0x4543EA406BD9C1A4ULL
        },
        {
            0x40894CABB6A0E6ABULL, 0x52A22A27C7CB3F62ULL, 0x627FF721380EEBC9ULL, 0x2477E6D072592F1EULL, 
            0x85136F4F00A3350AULL, 0xE0C8EEDE5C79A047ULL, 0x2F6E87D43C3468E0ULL, 0x6B4D4A5972A35D49ULL, 
            0xACEDDD1BE21794ADULL, 0x2E4810C6C61ADD43ULL, 0x511EA006B04E47B6ULL, 0x87BC7BA009016160ULL, 
            0x5CEB8308162CAA25ULL, 0x3D25CFB2C3268620ULL, 0x31B044CEB7619994ULL, 0x536A4B81A8F7569BULL, 
            0x70F481A76FAB498EULL, 0xF57D7482EB30E35FULL, 0x14FAC5F146E2877AULL, 0xC17EDC16574BF384ULL, 
            0x55C2504AB4D9C735ULL, 0xEDE7904D845DCA03ULL, 0x4BC2AA1A72BB9E7CULL, 0x30F567B08332B9A6ULL, 
            0xF1EA4D885801D3A2ULL, 0xC9601D79102EE8F4ULL, 0x01F8F166F79F8185ULL, 0x83497CCA1AD03123ULL, 
            0xE0AC13E7C3CA2AA4ULL, 0xFC07EFFD6E462683ULL, 0x45FC64197E4C6A00ULL, 0x278A4C31D745378DULL
        },
        {
            0xF37EA7AA801494B0ULL, 0xC155491723AD7DDDULL, 0xC2ACC55F2DBB3850ULL, 0x06E4BBB9AD5CB773ULL, 
            0x74E1ADEF725D5B10ULL, 0x75C66C68DA43445DULL, 0x4266BB4F3DFA46DFULL, 0x342EC502EAD28640ULL, 
            0xCC51C14E586A151AULL, 0x06E8E8D49A30D6CAULL, 0x79FF3222517EDC28ULL, 0x2705827FB696D90EULL, 
            0xB98DCF09C3681C21ULL, 0xA5BA3562208043B1ULL, 0xC558EE19D40C5582ULL, 0xD7C64B61671EB4D5ULL, 
            0xDE15C251B4C52972ULL, 0xD5FAE3EA0F9FD316ULL, 0x28B23141A5D7F496ULL, 0xE01CCE8267A2950FULL, 
            0xDCDD2708A95ABFC1ULL, 0x95773A77F7F226B8ULL, 0xA64C7EEA61B01348ULL, 0x8DCC33F607F6CBA5ULL, 
            0xDC4B9EBB02D14FE9ULL, 0x95BF074A27EC4423ULL, 0x4BB757F817478797ULL, 0x9F6DDB33D54D5989ULL, 
            0x949B038872C150E4ULL, 0x5EEEECEB310683A8ULL, 0xB4ACA352089FD3C2ULL, 0xC5AC2D53E2FF5582ULL
        },
        {
            0xF3647C5EFCE683E8ULL, 0x9E0B2F48625DFB47ULL, 0xE7BDE7A48FDA8E51ULL, 0xE9D605569E2B76A1ULL, 
            0xC269A5E4E78C0AC9ULL, 0xB9CEBDF8FB08406DULL, 0xAAF7A99B99B3448EULL, 0xB16B87ECDD014D07ULL, 
            0x4133D2161AD5B1D6ULL, 0x0F066D9009D5DE76ULL, 0x92CFF057C05A0863ULL, 0x41C6DD309A098C88ULL, 
            0x025DB2A567507AA5ULL, 0xD3560489FC79E476ULL, 0xBA794A988ED12C2EULL, 0xA78F08D8E1C4EB66ULL, 
            0xAD78EBF87EF9E2A8ULL, 0x774C15E3856A6E7AULL, 0x1D5E4606D74D21FBULL, 0x3D0519C0BE5F88A2ULL, 
            0xA7709E49A1D074F5ULL, 0xA80B8E293D4675A8ULL, 0xBDF678DB368F9293ULL, 0x5DCE5CC0E027DBECULL, 
            0x5E6CBAD30A406C7AULL, 0xE76F5331BDC426CEULL, 0xB1C2070CBD743D3EULL, 0xECA6332C1D8217DEULL, 
            0xA7AC53F95560276AULL, 0xEBD0379A88E7847AULL, 0x9EB9536FB9263690ULL, 0x88A6298663F5B03BULL
        },
        {
            0x6BD307FFB87A4076ULL, 0xFA9B6D9C528D166AULL, 0x198DDC7EBF006D36ULL, 0x9F704A6DC02AD28CULL, 
            0x3D42A36CB0DF196AULL, 0xF5274F412DA06271ULL, 0x1E86BE060D412E5AULL, 0x9304E8D3A06D4B37ULL, 
            0x404AC671819DBECEULL, 0x5CF0BEC9CC0E0FECULL, 0xD178D6E3BB274B76ULL, 0xD192FC35361E6C50ULL, 
            0xCD5F4CDCDAE69799ULL, 0xB927BA7B4AD478BEULL, 0x0DC861605ABBA683ULL, 0x7A4BE0357DA907EFULL, 
            0x738DA5493E9C0E3BULL, 0x182D2B36F2FC1F24ULL, 0x22CF30DEE47DB20CULL, 0x6078BD44C75E42F1ULL, 
            0x7A5D965ADFE9BE11ULL, 0x637B3227E411EE8AULL, 0x6D7264FAE3EE23ABULL, 0xC4FD62B951ED68D7ULL, 
            0x2FD28C343747B5D5ULL, 0x11A8FE73200CE0AAULL, 0x41BB6B61B3D56FCCULL, 0xB2F92CFC3F3A3022ULL, 
            0x2D04B14ABAE38F77ULL, 0x0662E4AF2A3E5378ULL, 0xD06E006EA2508312ULL, 0xC7865D4661413EEBULL
        }
    },
    {
        {
            0xB8C4592EB726D524ULL, 0x5D2188F0E90F89F2ULL, 0x56CD1CAF0303D932ULL, 0x815C31EC051C4F81ULL, 
            0x49CD3E60DFE7002DULL, 0x3A25A651F55AD9CBULL, 0x7B5E50793C706B27ULL, 0x06D000AC140F0213ULL, 
            0xFA581FA582026A78ULL, 0x5583C83C3D7886AAULL, 0x766AD7454DE5BE21ULL, 0x978C0A764C3A6888ULL, 
            0xC4133FC2A748D7F3ULL, 0x9690E63B1E129436ULL, 0xA9AD487ED211FFE8ULL, 0x8D92E58D5F499959ULL, 
            0xB6D751E0C37D3E2BULL, 0x962ACD595DD547B5ULL, 0x2FA104B30B76E73BULL, 0x5198693B69C7BAF6ULL, 
            0xC6AD61E56E73BCB0ULL, 0xE5F72C7A4B7A4BB8ULL, 0x9EAF120684DB9D54ULL, 0xDEAC9A4C962AF6F9ULL, 
            0x25C857DBBF56DDD0ULL, 0x4EE9A050647648B8ULL, 0x1DBA4C473B782551ULL, 0xE66F9854BDB091D9ULL, 
            0xE56D45B99A1D7372ULL, 0xCD5AE36ED07ADD60ULL, 0x2782A63C4EB82C1AULL, 0x4549C262A7E6F796ULL
        },
        {
            0x7C0E7A0976EF7AE0ULL, 0xEE282166A01646C5ULL, 0x77E9F5FD74D9DBBCULL, 0xAFEE33381348F438ULL, 
            0xFC0EFDE51548B860ULL, 0xBE78F0FD846E2777ULL, 0xD291FAA49197C6F7ULL, 0xBA2385FD8EEBB162ULL, 
            0x287DF4FE65563E93ULL, 0xB60B1C50F99F8227ULL, 0xC5D70723E6131336ULL, 0xDE90F74DA57EFAF8ULL, 
            0x48604DFD7FA3A25BULL, 0x7FA9C771A30735FAULL, 0xB1B8285B0073B76BULL, 0x3487196AACDBC8B6ULL, 
            0xBD826B07050F0A4DULL, 0xDB8B1E84D0DB7786ULL, 0xB589E343FA6BCF49ULL, 0x2588346EBEE5FBD2ULL, 
            0xB6CA9DA876BBAF50ULL, 0xB9A6B1CFB31E39C7ULL, 0xE86147FC5D79AC03ULL, 0xDE7639CA857E5207ULL, 
            0xF4FBE26A35394893ULL, 0x8D69DAC5BD1C336BULL, 0xB944D00DED90EDC1ULL, 0x433B3CB086A5B0DCULL, 
            0x140C97D917E0AAE0ULL, 0xAABAC55114C77237ULL, 0xD81AF7F86409DAA8ULL, 0x9877C861AEE6A6F8ULL
        },
        {
            0xD3CB39363BEB988CULL, 0x5127E5879A33F6F7ULL, 0x35B4043E4AD6D308ULL, 0x3C5547978F7275A9ULL, 
            0x96E0A5B5BC3CD9FBULL, 0x1092F73FA1A8DD31ULL, 0xC435FD901AC9398EULL, 0xA0CC0E2038E48056ULL, 
            0xCE2498F7431BEFAFULL, 0x6B2CE8FD89659951ULL, 0x0DD86B96D9EB2B4AULL, 0xA5759FA42FC253B2ULL, 
            0x3AFA97C90CBD2496ULL, 0x9196B04CDADD60D7ULL, 0x6D118E02A404A62AULL, 0x4E57449199EAEDCAULL, 
            0xFD98AB2EFF52981CULL, 0xF3A8B5E2298C28E0ULL, 0x1A2B7CED2FBFF27DULL, 0x2A7B09056EC65AB1ULL, 
            0x8EBA365744E562BDULL, 0xAE851855103B7F32ULL, 0xF7E3270FA6E6C896ULL, 0x665CBBA5E8A97159ULL, 
            0x9A4A60F3838B6FEAULL, 0x445CFA6E54FC7475ULL, 0x759CFE05124B8191ULL, 0x46BB77CE1788A5E2ULL, 
            0xE17CA92E3BF100CCULL, 0x16EA97A294615D66ULL, 0x098CE2CC413EF671ULL, 0xA44EFEEB8AE2333AULL
        },
        {
            0x11281AB363D168CBULL, 0x94CE6A2BCFE51C31ULL, 0x64AF30D9ED4623F2ULL, 0xA2463B7C0EE408CDULL, 
            0x8F228954498CC977ULL, 0x24C67556200C0443ULL, 0x17F299498693A723ULL, 0xE229A3FAC57F019EULL, 
            0xA86EDA475995AEC2ULL, 0x4F3132DE00699210ULL, 0x38A5C419C0230DD0ULL, 0x71F062D7A3A06596ULL, 
            0xB9400A45FDA18B2EULL, 0x1B50D33B1FC7F304ULL, 0xF11EBFDD773D9818ULL, 0x4E60167EA9498779ULL, 
            0x47A67ABFE776EF22ULL, 0x63B7448C50DF6386ULL, 0x17BFA4637DB72F99ULL, 0x1131512AEC506F2AULL, 
            0x45F406BCE0745FDCULL, 0x79C040116B4C9C31ULL, 0x11031ED197535618ULL, 0x4D0FD8065F57D34FULL, 
            0x501CC58DE68ECDB7ULL, 0x2217ED81BC9E7F93ULL, 0xE8EA1C85CAD4FAC3ULL, 0x225C7F3ADD419C7EULL, 
            0x909551F0DACF672EULL, 0x6ACB7BD00F69213EULL, 0x4F6EE1D52781F885ULL, 0xBE61D70A04BD94D2ULL
        },
        {
            0x9D43FB992BB0E821ULL, 0xB62E549953DE6EAAULL, 0x0A2E911EB05547C3ULL, 0xA91D07AC1E441152ULL, 
            0x520B3E4416995523ULL, 0xD85F31F30A0BBAB3ULL, 0xDBACE4561A835428ULL, 0xF213320273DF34F0ULL, 
            0xC1DD76A37A34579EULL, 0x1CF4F4A86F0E909FULL, 0xA54366CEE581D32AULL, 0x8A085C083E745697ULL, 
            0xF12E2C4047C1FA26ULL, 0x90E96B0D2E574041ULL, 0x07F5F2A37A9EE8C5ULL, 0xB41CA23A20EF08C3ULL, 
            0x4B0C6E5CF8EB899DULL, 0xEFF9C2DF881F5D71ULL, 0x61B548C6A92A34EDULL, 0xE11814A359D3E8C8ULL, 
            0x0FD98AD5847EB598ULL, 0xD3D889DC1CB10F79ULL, 0xB22529F599A16B4BULL, 0x676759C977D7E465ULL, 
            0x064F3D00F2232711ULL, 0x2CCF90BDBA59FA6EULL, 0xF0E98DA724BACAB1ULL, 0x9B3EDD4D83A01281ULL, 
            0xC6DF255FDDAB7C18ULL, 0x9EC38B9D15491891ULL, 0x53D14EC929B5222EULL, 0xF8EEE810AEF91C5CULL
        },
        {
            0xDDFC084F57AF0949ULL, 0x2D1A0423213002D3ULL, 0xD798DFC059E74F52ULL, 0x6AEC51CB35051D3EULL, 
            0x3CA63F074BAD5E4BULL, 0x413EE4C1BB979901ULL, 0x482597FC1799A3AEULL, 0x42CD8DADBD5B2E15ULL, 
            0x890EABA084624410ULL, 0xF7EC8B30975DF172ULL, 0x5231B23D95CA0465ULL, 0xFB8DF256C56AE8A3ULL, 
            0x81143FC50581BB82ULL, 0x367AF37D7AB560B6ULL, 0x584DDDE78DBA1082ULL, 0xA0337416C1B85A83ULL, 
            0xADC97B5E50215089ULL, 0x4C99FF35E21473D1ULL, 0xD32326B511120DEDULL, 0x53E63D9EA7DB76D0ULL, 
            0x64AEB3F0A52BEF1FULL, 0xEC15AB1CECF15F4CULL, 0x63FC7A6EAC6D7C6FULL, 0x60356E4745672A5CULL, 
            0x17CA4DED1E5AA06EULL, 0x669AE800F8B118A2ULL, 0x5543454DD49DB83FULL, 0xD85E0475C58929D4ULL, 
            0xB85A2271CF89AD97ULL, 0x07556CC5BFECBFC6ULL, 0x310EB04DEB13E74FULL, 0x778450771602C502ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kKeySpawnBConstants = {
    0x68FD63CD93CCCD67ULL,
    0xC1DD3C9F4DA73031ULL,
    0xCFE737BC916D9CC9ULL,
    0x68FD63CD93CCCD67ULL,
    0xC1DD3C9F4DA73031ULL,
    0xCFE737BC916D9CC9ULL,
    0xA9E5E2E68D9F0695ULL,
    0x193A0F2CDDD00839ULL,
    0x02,
    0x4E,
    0x3B,
    0x86,
    0xCA,
    0x73,
    0xE4,
    0x87
};

const TwistDomainSaltSet TwistExpander_Vega::kSeedSalts = {
    {
        {
            0x06BB3DE7B40D05E8ULL, 0x45C292146052F756ULL, 0xBEF3A9B2D5A3BFCDULL, 0xDCB28030E7CE71C7ULL, 
            0x2894138B3BD86DB4ULL, 0x5B57B1D2155968DFULL, 0x0A9B82682D0D8184ULL, 0x97BC3E772006BF15ULL, 
            0xF8A8D8EDECD30026ULL, 0x792190ADD14510D8ULL, 0x38CE8BDDE3AA6DDBULL, 0x2E434B5C3320CE54ULL, 
            0xCD504CD5F7675ED3ULL, 0x588DDD117A095435ULL, 0x946C08231358DF44ULL, 0x25FE2213BD6B849EULL, 
            0x35988DE2B4E76805ULL, 0x450D545C731A6EE8ULL, 0xD5F6B5A84D645F66ULL, 0x5BCDE9E808528A75ULL, 
            0x8BD7612205E4F40EULL, 0xAAC34C7F37EAFDD7ULL, 0x2C1060E86C9E8FA5ULL, 0x592FD1A863625A0EULL, 
            0x3E33BFEAC484DE04ULL, 0xEAB821B365C811C2ULL, 0xF6F77D235EC2D1E8ULL, 0x7259596E2A84E453ULL, 
            0xD7E637F8CA4BF7F7ULL, 0xDF2D6A3D89AF8C7CULL, 0xD549A4FFAA959220ULL, 0x9BFBD2A8EB515968ULL
        },
        {
            0xD1465240AD0F4A56ULL, 0xA6AB5ACB1F8FD574ULL, 0x5E09C5D631FE894DULL, 0x9889D2FC82E16547ULL, 
            0x6AC169AC62A52D40ULL, 0xA0C50FC651065C32ULL, 0xBA9B45076AB6D7F2ULL, 0xEF0CDCD0ED438543ULL, 
            0x0A33B560410D25A5ULL, 0x80C9554CDDE00EEBULL, 0xE5D2B3CF9B6F3A39ULL, 0xFC89A8BD796D6F80ULL, 
            0x7791DE64904D6182ULL, 0xF60CD005168090F9ULL, 0xBD5FDAED3C808A53ULL, 0xDD44654EC99606D8ULL, 
            0x3A0212EA782AADB1ULL, 0xE82BCAEE0AF3B2B5ULL, 0xD0F92E8C3BC54E7FULL, 0x98B0FAAB1E59D844ULL, 
            0xDD93F05D97BE07BDULL, 0x0A842FA42C67F5C2ULL, 0x700D6E21E4045F8EULL, 0xA239B7B08E2C2DFDULL, 
            0x65153DC840583934ULL, 0x5E6AC76F73351617ULL, 0x950B51D7FF840D6DULL, 0x841FCF2A670FB14EULL, 
            0x563B76B9ACEA9FACULL, 0x300D75CDE88268CAULL, 0x88CBEEBC8A55DAEDULL, 0xDFEB5AC345DD8B5CULL
        },
        {
            0x67C5DB557CC7088CULL, 0x8F322EFDB903DFDFULL, 0x2407F6BED2D3ED9EULL, 0x4D84999465F5ED2CULL, 
            0xD43D3F0112B2E36DULL, 0x7386681876DABC9EULL, 0xEDADBC05D09F9E83ULL, 0x56A8A2B580A41345ULL, 
            0xFE986D562B334B32ULL, 0xD21363169A331FD6ULL, 0xC6D32F2A9149DBE6ULL, 0xB0D7FB6C4A7E163FULL, 
            0xD2B42D3C51A905B6ULL, 0xA2357930306CCAF3ULL, 0x96CC1F65E0CFF664ULL, 0x3F3150D87712D05EULL, 
            0x0C4FC89F8F474A05ULL, 0x7B3AC01125F054ABULL, 0xD1C633485EF6B5D0ULL, 0x43CB5CD6D17D4C14ULL, 
            0x2E5D1E68C5278B4AULL, 0x21484FE593EEC32AULL, 0x1BA0BE39824C5B29ULL, 0x958AF9C500281737ULL, 
            0x3D4D00EDEF3D9041ULL, 0xB3DF4532329DCE81ULL, 0x3D020CAF6D31BA1FULL, 0x2217F06FC704FBFAULL, 
            0xECED79476A71D487ULL, 0xFDC5B7E6A9F8B931ULL, 0x82C711DFA03F53D1ULL, 0x70F63E4EF0331C38ULL
        },
        {
            0xE6F9582D1F0EC453ULL, 0x3390CF7B70D46DC6ULL, 0x9C4E9A29E4F4DAD1ULL, 0xC1E947249051D7DEULL, 
            0x96547EB991265A1DULL, 0x391BA4DB3213243EULL, 0x77D72612A047E388ULL, 0x681CA664CE1F068DULL, 
            0xDA26E8DF0CA39B4FULL, 0xA64CA9E408F94D1AULL, 0x3491934233CB276EULL, 0x694E60CA8C0E86BBULL, 
            0xD31436F9B2956C7EULL, 0xDE1DC3B9DB8E8D58ULL, 0x6267357E22BF94FAULL, 0x735D812B8342AC68ULL, 
            0xD09CAFB663328DBFULL, 0x695E068DBC9A7F46ULL, 0x65D407CA26FEC626ULL, 0x0E129733E1F527A2ULL, 
            0x820235582FCF8CD9ULL, 0x75B226707B49A47DULL, 0x4654400DA6FE5B16ULL, 0xCDC6FD19139D067DULL, 
            0xBEDAC043C53A7684ULL, 0x68D6B4660087256EULL, 0x26F7A073652D3393ULL, 0x21B1BA596F77FBF4ULL, 
            0xB17F1AE4E5201885ULL, 0x4AE810548FF0BDADULL, 0x98D30CDBCBC4F8EBULL, 0xD48CC5C23710BB27ULL
        },
        {
            0x2AA32CBF86EC1AA2ULL, 0x7434EBE7AD738EFFULL, 0x6FF77AF214A67663ULL, 0x880157B7D9C7224AULL, 
            0xFDB8DB850AADD36AULL, 0x317C6CD1A1C8128BULL, 0x54B6A6E75B3FC3E3ULL, 0xD1D60951B1C4FFBEULL, 
            0xAAAC824E08C9FEA4ULL, 0x208E1637DAF1B138ULL, 0x3CC050FA3F33186BULL, 0x587622D52D99C95DULL, 
            0xBFACA203A922C8A5ULL, 0xC7F29F015ED7A163ULL, 0xE684002B7C77006DULL, 0x97F5C185F0D5C254ULL, 
            0x94227910A9C7B328ULL, 0xBADF694D6C73F068ULL, 0xA50FF0870494AC3EULL, 0xEE1123AB7B99B0AEULL, 
            0xE96C8CE93BFEDCA5ULL, 0x57FD7BC0B58F10C7ULL, 0xF48BEFABA859343AULL, 0xC64D8514B7C4EE90ULL, 
            0x9A732C5AFC8806B9ULL, 0xCAF67E2E91788F4AULL, 0x867D75EAD3E07499ULL, 0xC359D7B2806F6AC5ULL, 
            0xD9C9E600176B859EULL, 0x5BBC8E440CBFD2FAULL, 0x5179550A45E5BAC7ULL, 0x3E814795E3C9A675ULL
        },
        {
            0x5E4DAB67D7C5B465ULL, 0xEF8686D097A4EB98ULL, 0xE69D21BEE31C1539ULL, 0xC5DF74191984C1A3ULL, 
            0x5332C2239BDCC27FULL, 0xD6F0F940551F8787ULL, 0x76044B9895D16B15ULL, 0x04BCC0FC29C03BDBULL, 
            0x483BF1C1B8AF3425ULL, 0x9B839D713CEAFE98ULL, 0x18A5BCA9A4B026B2ULL, 0x09574F291F9B35CCULL, 
            0x975403746935DCC3ULL, 0x73A3FABFB0D70B19ULL, 0xCAF9AC6B2911E033ULL, 0x591F54934CD1A75AULL, 
            0x1D3E088C7CA8F5C4ULL, 0xD614FE16CEF7431DULL, 0x28DA9ED1D63DE163ULL, 0xBE9F91FB257F4CE2ULL, 
            0xED4511FEF8D24911ULL, 0x5CFCCAAD591CC604ULL, 0x77B24F6911AD987EULL, 0x38E406707D41352AULL, 
            0xE679FA5F5EA21FDBULL, 0xF9CFFBAFF88CEF17ULL, 0x3BFC1FBF602D5FD3ULL, 0x6C3F1D35AA5BCCF5ULL, 
            0xF6664B82E9ED5AC7ULL, 0xE5292E4312AED3E6ULL, 0x06CA2838CBB52099ULL, 0x876A3043657E27DCULL
        }
    },
    {
        {
            0x38D867F1F9FCCDC9ULL, 0x00BACDF1DC2AA952ULL, 0x03D4AE594C416C70ULL, 0x3A81C3F9B2C538EFULL, 
            0xDF018E1F5B4A079EULL, 0x70DEA3127034E999ULL, 0x1D7916B21F805C79ULL, 0x636DEDF702B81286ULL, 
            0x130235BF659C9F06ULL, 0x0F36C0ABAEFC232FULL, 0x0B31CD76F7861F4AULL, 0xEF3A19E548A48C77ULL, 
            0xA66FD1D6F1C8F28DULL, 0xCE3BA5F6DA3CD82AULL, 0x6E21AB769F841C67ULL, 0x4C76AB6C035BA27CULL, 
            0x1DC4149516EFD18AULL, 0xF52A7FB56F4DFC59ULL, 0xE1EC8A8EB41902E8ULL, 0x68FA18A2CB0429E4ULL, 
            0x4EA92D720479ACCEULL, 0xA04F12F5C5C223DFULL, 0xD17E8F762AB8032AULL, 0x58C7A13ADE6C7CD3ULL, 
            0xE31FEEA19D40BC0BULL, 0x98BB7CE5CF481F9AULL, 0xC9B27CF05A1A5DFFULL, 0x3B9EDE7C6D5DC93FULL, 
            0xE9C76358C51B95D6ULL, 0x628A1F0AE2A3C581ULL, 0x3CF011F6DE4DB103ULL, 0xE06A2B38A9F9E542ULL
        },
        {
            0xBF84764A7843E2BBULL, 0x87E7A9F9ECEEB0A7ULL, 0x7390BC7C727DB6E6ULL, 0x8B16D1AB15FCE380ULL, 
            0x42E7B8861FBD8D75ULL, 0x559C35BE63221090ULL, 0x6A8DD5A8778D71D8ULL, 0x0A0059782C22BA21ULL, 
            0x3FA8F3646278F997ULL, 0x920F5AC8441F7A00ULL, 0x06BEDEB5EC171730ULL, 0x6E9B96E42A8230E6ULL, 
            0x073792BB3070FB23ULL, 0x68D7865531B2881CULL, 0x30569AFE32EB4DFCULL, 0x7F906CD4D2AF5E32ULL, 
            0x62355E069918B2D1ULL, 0xCE368C0061BFBBDCULL, 0x814BF4BEB2AD01E7ULL, 0x53EB164D47FAEF45ULL, 
            0x94797F0039AB2C00ULL, 0x981CEC4B4F7A4469ULL, 0xD71CFB2A55FF1A72ULL, 0x69D91FB7DBF51855ULL, 
            0x82ABF20F4CA6D4D0ULL, 0xB36DEC56B9AE592CULL, 0xD8F2B1D16D07B605ULL, 0x54CB8FAE2FEDB073ULL, 
            0x4FDE94BAC9C1320EULL, 0xFD9C661E5F0156DEULL, 0xA5F566912CEA7EBBULL, 0x5635125299FC33CFULL
        },
        {
            0x2C1D9C08E22F21C6ULL, 0x57FA273B65AB690EULL, 0x90FAD6EAFEB5F2C5ULL, 0x27630D6E4253CC62ULL, 
            0x96B81FD078D77ABEULL, 0xDDEB8032DF29BC86ULL, 0x13166369171B85A1ULL, 0xE7A704860FCCC766ULL, 
            0xAC05B59549CC2193ULL, 0x02A49991AA78BC05ULL, 0x0739ED5B98E66552ULL, 0x183E5875F609F776ULL, 
            0x5DE6142DF4AB3F14ULL, 0x1485800CB24AC4F9ULL, 0x8372FD6DAD981184ULL, 0x418F6B2FB844F96EULL, 
            0x4354C540F635B2E0ULL, 0x81A77224B31A0632ULL, 0x75C18D5E862F5EE0ULL, 0x4A71B03219E8FD1BULL, 
            0x98EBE7C81AAF21B5ULL, 0xB5155C6D5B1A2EBBULL, 0x7208EA2F275422B0ULL, 0x77899F364542AFB6ULL, 
            0x5844DEBB962CC549ULL, 0x70F3048C1181D2E6ULL, 0x02CBF4A1E6A236B0ULL, 0xE99A644E8948D140ULL, 
            0xC139F07D2FA7D48FULL, 0x0114969D23E05237ULL, 0x4F932A134FDDE8ACULL, 0x3E5971A7259D8CDCULL
        },
        {
            0xBFC1300B4859A46DULL, 0x0BE88456884E2890ULL, 0x4EA6FB090D217656ULL, 0x65DDD1CB6673E018ULL, 
            0x55E479869D95C421ULL, 0x8DF98A4C287694C8ULL, 0x1A4DE6EFC3CEA371ULL, 0x58B5C4CC6267EB67ULL, 
            0x3C44626F9DBC5BE2ULL, 0x14CDD01DD0A9C031ULL, 0x9EF3609A1DB225F5ULL, 0x40D595B29C2FF17BULL, 
            0x81F2240EDB65C44DULL, 0x32250AFA67A36290ULL, 0x636A62F055573BFEULL, 0xF3A42893F4F47961ULL, 
            0x51860FABFDACB474ULL, 0x33E1AF118A990D15ULL, 0xA61D4E30820ECDE6ULL, 0xDCBE79F3CAA79732ULL, 
            0xCE0361ECAB7CD441ULL, 0x5C421C69EB6E7840ULL, 0x218BD0A9581EF471ULL, 0x01D895B920B47D4EULL, 
            0x4589F3BC30DC8EDCULL, 0xEC4A7A950AD5D0FBULL, 0x75151E34D32BED3BULL, 0x4E60BC056521EF1CULL, 
            0x59E879B454325ADDULL, 0xE53B501635852FE8ULL, 0x5B1C93CC67976831ULL, 0x9FC474191C604604ULL
        },
        {
            0x2DF5F0BD3CA6B0E5ULL, 0xE0E43590CDD45760ULL, 0xE088164486AA1BF7ULL, 0xC0F28069333960C1ULL, 
            0xC97900A73FE3819EULL, 0x1DBEFC5696600724ULL, 0x5F6023A0B0F94349ULL, 0xC008B21664A82586ULL, 
            0x65E37F0DDC20B06EULL, 0xC155779B03FF31CDULL, 0x4E2AF41BE204F8E3ULL, 0x56B43BA2341F1B5BULL, 
            0x5EA57EB3A2800529ULL, 0x54C3234C09771822ULL, 0x8623D46248B107CEULL, 0x5DF5DA091E936805ULL, 
            0x9BEEE097C23BCC8AULL, 0x120F9A5A5BC47A01ULL, 0x62D29A134469EA62ULL, 0x6C383F3B7375DB75ULL, 
            0x51E5CAA687391834ULL, 0xE7DF6BE8BBE17ACBULL, 0x513691EB875BFEB2ULL, 0xF47838C080364576ULL, 
            0x1B59DE1F6B3D3C39ULL, 0x7D9937FDC41B5B43ULL, 0x1935150443AFDC04ULL, 0x6D771768A26E7065ULL, 
            0x3B6E88492C3DF02AULL, 0x5E9107926949A572ULL, 0xF6CA6C7C4A6D3A2BULL, 0xA9AEF52F57FB694FULL
        },
        {
            0x092A683716F50C9EULL, 0x21D0CC5221AA2281ULL, 0x8117A20F782C5A4EULL, 0xE1DE2B5B05C64F21ULL, 
            0x6D93388739CA1DDCULL, 0xD80B42431FC87F86ULL, 0xED4CDEFF369181E7ULL, 0x4890420EB65D2D48ULL, 
            0x5B9FE57C6C8FD852ULL, 0x70CBEB2D8D615EB6ULL, 0x376FC552F59262ACULL, 0x2A0191F68DB81457ULL, 
            0x845039D322D20A59ULL, 0x34A3533D2E8D2EFEULL, 0x5A585D5E2F9E62A3ULL, 0xAFAD7B26008C2C97ULL, 
            0xDE2020A1D26EA146ULL, 0x841010FDA5FBB7FEULL, 0xDCFB7A78A73F51CDULL, 0x7FC6BB1BBAB8A712ULL, 
            0x621691EC7493956BULL, 0x6B22845A242106E5ULL, 0x493A72B892756552ULL, 0x291F2CC80D6572AFULL, 
            0x807D9FBD67D1DEE1ULL, 0xEEC41D1C8D10E95DULL, 0xADDFCEA9EDB319F3ULL, 0x32D24953D3E1EC26ULL, 
            0x6EE4EC773264FF28ULL, 0x897AE3DCC70811C0ULL, 0xCF6D25A7A6E5D5F4ULL, 0x94F532F13C785A7CULL
        }
    },
    {
        {
            0x8BA197C465787C84ULL, 0x6627E5C8CE136A6AULL, 0x04698848731EA061ULL, 0x917D3B9B89A98274ULL, 
            0x16587770D4E96C6CULL, 0x0CD111896523D73BULL, 0x99B4CC92E68C2047ULL, 0x129A83EE99BDAC73ULL, 
            0x34B476BF0E5A810AULL, 0x105B6E1BB4BAC029ULL, 0x846C414FAC617B73ULL, 0xA5BB223A9A9FE8BFULL, 
            0x0EA6A98370A237C2ULL, 0x7364E74C35B4A370ULL, 0xDA841B057DC4FBB9ULL, 0x99D17B59D612AD91ULL, 
            0x24DD400CEF1A74E8ULL, 0xB345C67F9708C8DDULL, 0x2E134BE762DFDE5EULL, 0xEA6E1B3F0F8B10B0ULL, 
            0xA025FCFCD94BD4BCULL, 0xD830E732486C572CULL, 0x599B24F7C57720F5ULL, 0x011DDA5857ECDA7BULL, 
            0xC7B7D9C21C0E9BACULL, 0x3FCE374E14199515ULL, 0x25157A2911FF8BFAULL, 0x48473A7BE08E9CA1ULL, 
            0x686C99648E8915ABULL, 0xDC427F49F4506706ULL, 0xDFA507732CC487C4ULL, 0x2877713F5452BCD1ULL
        },
        {
            0xD2924229828C2491ULL, 0x525231D5E41B03FCULL, 0xA3DC4342A77CF081ULL, 0x28360F90D17A613AULL, 
            0x567C175E92A97AFCULL, 0xBE0E50CD2FA3C63DULL, 0x055A6A68F3839A02ULL, 0xAA99AD14098B76D8ULL, 
            0x4C269E2A51142990ULL, 0xF206C6324B64CDBCULL, 0xB328C2A9802ECAAFULL, 0x881FC3724C2C80C0ULL, 
            0x2A1BA0FE789C08F1ULL, 0x11BB82270D3FCC85ULL, 0x1A6081191AB9E0ADULL, 0x0959D1310363DB61ULL, 
            0xCA76D84B79E0585CULL, 0xD3D04BE5DEE3FD80ULL, 0xEEA0DE82B4133991ULL, 0xAD84EDCA3E949BA4ULL, 
            0x24CC7C3C2B973EC4ULL, 0xD1BA57BBBA05CC7EULL, 0xCFD7CBBE6921737BULL, 0x61CABC32A492B30FULL, 
            0x674C124497B2DA73ULL, 0x4971B193C279A479ULL, 0xBECA90042233713CULL, 0xEB77F94A14181BA1ULL, 
            0x60214ED6DEBDD146ULL, 0x71DDA5EDD7BE1CEFULL, 0x29FFF9C72E272AA2ULL, 0xBDFA9242F1863DD3ULL
        },
        {
            0xBB7902130A336A34ULL, 0xC75EF6D8E211C932ULL, 0xCF17DAFFF4150A0EULL, 0x3CE176DDEC474355ULL, 
            0x16DB7A98CA372DA8ULL, 0x4BB3754C410B8FBAULL, 0xFBD282D14C805058ULL, 0x1A62830EB741F14FULL, 
            0xBAD050BFC0D8F9CEULL, 0x86EFBFCC11020A8DULL, 0x8FC923AEC3989A29ULL, 0x5962ACEE9EB9DEAFULL, 
            0x4552E80DD5AEE925ULL, 0x83EF8B6B37038090ULL, 0xDBC371D6DC0BD109ULL, 0xB8724D1DB2A93815ULL, 
            0xF1E7763C43766158ULL, 0xBA24B94F00724122ULL, 0x0C746779D73399EEULL, 0x4593BA92CD0307D6ULL, 
            0x5F352245E330DFD0ULL, 0x0B5379FE62362F95ULL, 0xE73AB0E931CAE2E3ULL, 0x5DE0D8826FFEA006ULL, 
            0xAD8EBB1B113B467CULL, 0x9832542008CEE504ULL, 0x1AAD3E6B7FAEFD1BULL, 0x12C7FC2911422B41ULL, 
            0x0A53B171DE4F7E63ULL, 0x372600FBBB6F5936ULL, 0xB90388D3DE0C3A66ULL, 0xE8B372FF050D9715ULL
        },
        {
            0xADAB638195D1AAE8ULL, 0xD208E5E256AA23A6ULL, 0x23FC52BB1C7E4BBCULL, 0x3730CA7DB38B1F7DULL, 
            0xE30E6B952B9BC63FULL, 0x5572A4BEC11A8A38ULL, 0xBEF2270DA6ECFAF6ULL, 0x5C4F41646B3AD4E0ULL, 
            0x98948E94F82AC99EULL, 0x834CB9E71DA1F402ULL, 0x0F884184CC48E3A8ULL, 0xEBEAAF8FEFDD71E1ULL, 
            0xF582AB6AA87BB148ULL, 0x9E4D015B96A16B37ULL, 0x0EB7B4FFE39E2FF2ULL, 0x47CBE1B434CBF98CULL, 
            0x76C5743848EC1B86ULL, 0x5C788D9C9E9D20DAULL, 0xD3AB041555D8F03EULL, 0x8D6751254D9EE057ULL, 
            0xA702178F3B16E3F6ULL, 0xF403996BB947771FULL, 0xFC86B89B0221BFF1ULL, 0x4B59C43DD05F3E7BULL, 
            0xA87B6FF5A8D5AC1EULL, 0x21CD20B46B303CA4ULL, 0xA27EB9B5638236B1ULL, 0xCEE668316136BB32ULL, 
            0x03DA62B4EEFB6EECULL, 0x30787340BF9EBE9CULL, 0xBD5CEF38CE686937ULL, 0xD167DD30B550DE59ULL
        },
        {
            0xBDE06F7D09B59B0EULL, 0x794AB02E28CD367AULL, 0x5A91F0E9A1AE5F46ULL, 0x6EA54EA584CD4DFEULL, 
            0x65656CFFAF1C9442ULL, 0x251BF947383180D6ULL, 0xC0C398F6C6846238ULL, 0x76F6A0FD6FC27D85ULL, 
            0xB3D1B67402F1A1C9ULL, 0x5B30523DED6FC693ULL, 0x17EEC09665A746A4ULL, 0x5401BA999659FFC3ULL, 
            0xE8389C93108EE9DAULL, 0x6C5047F952F523C2ULL, 0xD9EC8454AA759A18ULL, 0xD34ACB3268982443ULL, 
            0x70002777CA75F521ULL, 0x7AF11D2FB1D96065ULL, 0x56198C79C35BB36BULL, 0xA08D530DCA25C3CDULL, 
            0x6BEEBAF7F945EF99ULL, 0x001E60BCEC8C8D87ULL, 0x4AD996CD0795DFBAULL, 0x76C21A02C714D6BAULL, 
            0x10F335B8783FF5C8ULL, 0x0C5D30FD6814BFB3ULL, 0xF048BEE9F32F1F8EULL, 0xB22867788645821DULL, 
            0x2A6735A1D26AD9A6ULL, 0x33DCA3253DA0E54FULL, 0xD63C66D830EA3C28ULL, 0xD9D048983A53CA26ULL
        },
        {
            0xC8FD638E75FF26CDULL, 0x51EF7685A67773F5ULL, 0x5CBCE49CFD3F964BULL, 0x3B663237364E6973ULL, 
            0x649E57E12D5D06C4ULL, 0xD2ED1FECD67FE5B6ULL, 0xD8818BEEAE0DB883ULL, 0x26FE77125046D570ULL, 
            0xF73F05830C5B7D64ULL, 0x3476CF03C7DC2F75ULL, 0x9541F44CC25F4A7CULL, 0x4F965279C7B5BBA0ULL, 
            0x60AAD31B152926D5ULL, 0xEFFF27A87D23A2BCULL, 0x39EBF643F0B97A32ULL, 0x47177B3657407101ULL, 
            0xFDC5555BCD1BB4B2ULL, 0xF0764123C40DBFD9ULL, 0x5470FBFEAD4FCC02ULL, 0x21C33A556FA9BBBFULL, 
            0x43BD95F48DBEF1C5ULL, 0x6301E56F7167D6B0ULL, 0xC103905F45EB260CULL, 0xBC1936D0CFCC3DABULL, 
            0x12E0A183B0BE03C3ULL, 0x1F705D8EB3C1A86AULL, 0x56DC7476A5B824FAULL, 0xA50CCCFDB9C984C2ULL, 
            0x01A53C0F9B7F8411ULL, 0xCAF74CE22D48C21CULL, 0xA798409187FF46DAULL, 0x8A42B2D2BD87618BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kSeedConstants = {
    0x7B08CD3F7878C776ULL,
    0xBC81B8ED623F3BA1ULL,
    0x1444B308318B96C9ULL,
    0x7B08CD3F7878C776ULL,
    0xBC81B8ED623F3BA1ULL,
    0x1444B308318B96C9ULL,
    0x008AC63D87D0E6B2ULL,
    0x2F86D7F2F32EE17FULL,
    0x6C,
    0x3E,
    0x8F,
    0x45,
    0x30,
    0x0F,
    0x81,
    0x3D
};

const TwistDomainSaltSet TwistExpander_Vega::kTwistSalts = {
    {
        {
            0x4CD66792782DC1DFULL, 0x3D060127BA6D8C9BULL, 0x47349562E6360362ULL, 0xE325AF88E356FEF1ULL, 
            0x6D7EAEC55FA72403ULL, 0xDD103F6F76B9D313ULL, 0x596B77E4F87341A9ULL, 0x875476BAF96A6F16ULL, 
            0x598B9299D05FFB39ULL, 0xB272C35C5868960BULL, 0x71F46FD0E18CCA8DULL, 0xF86E86B769E0AAB7ULL, 
            0xF0C89B1CE448F6B7ULL, 0x09BA317AF0C07174ULL, 0x23E74811FC909BD3ULL, 0xFA5418086C2739B4ULL, 
            0x005284E5FCB9B26DULL, 0x56F0A527F2419C9EULL, 0xD9348C2AACC564F7ULL, 0xC11C453918678842ULL, 
            0xF6580E5FBEFB3D7AULL, 0xA197626AE60B4885ULL, 0xCDC7BB92079EDCA1ULL, 0x2BFDF94284BF8AE3ULL, 
            0xD7EFC19FAB113865ULL, 0xE438E0AEA2899650ULL, 0x8D5A2D74E6D685FDULL, 0xC088C2E52DE351AAULL, 
            0xDCFEBAC501772D19ULL, 0xB3A2309E1250C8D9ULL, 0xDC43D01C342FE846ULL, 0xC9578CFE5B805D92ULL
        },
        {
            0x96EF4194E4B85A48ULL, 0xA264E9A876104BC5ULL, 0xA7A6B0DDCA22B41FULL, 0xC01A231B4EC863B1ULL, 
            0xA0A8C893A1EFD7D7ULL, 0x341782AF5FF7D83BULL, 0x68FFC0B50EBA71ADULL, 0xAFE124B09A1B4426ULL, 
            0x6B1E5F51C16D237BULL, 0x89A4AE6B15D79104ULL, 0xAAC75189C4E59DF4ULL, 0x6C0A9E89A44E8DB8ULL, 
            0x4902BC25F0EBE96AULL, 0x0CF2111B04FFC5CEULL, 0xF15698FBCF3B9EC3ULL, 0xA9AB0FB48BB126EAULL, 
            0x094792B6F3B75354ULL, 0x05CBF025E6FCC5DDULL, 0x6748CF44B4BF4CA0ULL, 0x6C51B17261FAE60AULL, 
            0xC07C2890AB82EA0EULL, 0x659C352570E397C5ULL, 0x1781FF7C6379AE3EULL, 0x9796EDC6CF2BB4D9ULL, 
            0xF2205E2A05BC7EC0ULL, 0x40BC9C9112184A99ULL, 0x42097739B4EF308BULL, 0x0DDF916442E95A35ULL, 
            0xD80F79DC81E4275AULL, 0x1B78B24C1A8FE288ULL, 0xB57DB8B58C38F7A8ULL, 0xB72A1B0FF002F5F1ULL
        },
        {
            0x40789822D13C93DEULL, 0x2874FB2CAB460794ULL, 0x695DC183C1797634ULL, 0xD272A187FA353649ULL, 
            0x0AF9DC18B43E6970ULL, 0x91B599EAF582DF8EULL, 0x7067949CADC0A694ULL, 0xC800035D7A5C9966ULL, 
            0x4D27984B7C78104EULL, 0x1DE37D17F5E8BFD0ULL, 0x03609C4B2FE1F1B6ULL, 0x804FCFC7B49C205FULL, 
            0x8C999DA0D9D04A9DULL, 0xAC8E447653F076E7ULL, 0x6C6C322CBE016F6EULL, 0x476FE70DFAD2BA95ULL, 
            0x1F37D1A721D940C0ULL, 0x35188839D9DACA23ULL, 0xB8DA93CCE7E967A7ULL, 0x5A91B90BC00E3457ULL, 
            0x638A68A8252778D0ULL, 0xF100B3A67316B5B6ULL, 0xDBF00F373FBC7CB8ULL, 0x8AA4EF14E3BB3324ULL, 
            0x198CC2F5D2F42814ULL, 0x09E7B58D50F672DDULL, 0xC431248A936B3DA7ULL, 0x98FB8EC11C61F0B5ULL, 
            0xC4DF85CFA75243E0ULL, 0xC5829FA25BE1D81CULL, 0x1AC80390ED03EBBDULL, 0x3440D29EB0F55DBEULL
        },
        {
            0xD124468D2DE248A8ULL, 0x7BBD5A23A2CE9FA4ULL, 0x7D6E4B5B488D57BBULL, 0x49E6A7450CFC61B6ULL, 
            0x1706B686A6E89856ULL, 0x45EA5FF72F4D65F0ULL, 0x95B1D3CE758FDE2DULL, 0x2E3181374188913DULL, 
            0xDFD67B092D2617E2ULL, 0xA9886E8537168CBEULL, 0x46B2729253E03F08ULL, 0x1A039B10477E4522ULL, 
            0x8D573666BF030B9FULL, 0xFF744924B05E2AFBULL, 0xA035B590C1879B7BULL, 0xC5247B6E2CC89799ULL, 
            0xEDC541FEAD116404ULL, 0x821865E7EE58ADD1ULL, 0x2AF02725978B4664ULL, 0xB3A28916789646E0ULL, 
            0x6BCB6EB05DFE995DULL, 0x03B56467683B0CB4ULL, 0xA8ADE021F223B5E9ULL, 0x8D35B022398D5654ULL, 
            0x4BED389FC7288C47ULL, 0x2006E08924046FC4ULL, 0x5E54FA02F40E73B5ULL, 0x87C671F070AADE7EULL, 
            0xF955DB8A2851F79FULL, 0xE8573CDCD5AB61A9ULL, 0x42894111043C7541ULL, 0xC264E7CE3A832877ULL
        },
        {
            0x8CCD694B1F68BA6CULL, 0x7307F6DCCBBAA818ULL, 0x34576FAF4F9FFBB7ULL, 0x2596108DA970ABF5ULL, 
            0xCBD330562236794BULL, 0x0BC91DD0F436E308ULL, 0x4CDAD19BEE2CD7BBULL, 0x719D0FFEB2858D78ULL, 
            0x2D89837072D56AC4ULL, 0xA296828560141E21ULL, 0x992990D4EA2965F3ULL, 0x46CB4DB5A4622A10ULL, 
            0xD4800A5FD310DA0DULL, 0xE958F4A818C0E282ULL, 0xDB8F178E82216B4FULL, 0xF73112A75B17121FULL, 
            0x4C9C348B99DE066EULL, 0x27BD8484CF0BCC0CULL, 0x290EE5B099D8ADD3ULL, 0x56BA404879E439FCULL, 
            0xBE3F7D6D0746D0E9ULL, 0x0BD36C2D5B3616FCULL, 0x4BEF1AAFC46F8443ULL, 0xAD87DAF054814B9CULL, 
            0xC99CC64F2A652936ULL, 0x922A914445FB13B7ULL, 0xB2509C42BBA3F34AULL, 0x0E1C35F53B8569ECULL, 
            0xA72CDF0579C37369ULL, 0x4F640F4625A5595AULL, 0x41CAE542281451EBULL, 0x8E2265DFE8741063ULL
        },
        {
            0x5B360D1D92FA5D59ULL, 0xAC7598974468E985ULL, 0xC6D270A911FADA06ULL, 0xFE59CCF9C45868EFULL, 
            0xD9CD843F618DA3FAULL, 0xBC0F627550EE86C9ULL, 0x6EF559EF63716145ULL, 0x38CA2799AAC1859AULL, 
            0xD54F28D3C1D1D19EULL, 0x030992CF0C853E26ULL, 0x96C6A4D2318CB9FBULL, 0x6801C17D85288647ULL, 
            0x5A61ABE15D23FF1BULL, 0x61D2A0BDBD697972ULL, 0x7AD33E36A39FD97AULL, 0x4ACC20381BB5EBEAULL, 
            0xCE84BDD82AAE9979ULL, 0xA697F05DD0D129E0ULL, 0x78C66610A1B0C6C7ULL, 0x6A2A016FF2507420ULL, 
            0xD9A1D2942EE5758DULL, 0xA3F648379058815DULL, 0xFC6333D857E4E97BULL, 0x17999EA8D446ECC7ULL, 
            0x535F12A2CBAE365CULL, 0x7A48F38F8B309A40ULL, 0xDC40805AE1A07593ULL, 0x5A3107B843F84FC0ULL, 
            0x28976CF6F812F229ULL, 0xFF72B59C1063165AULL, 0xE4C3779724773BB4ULL, 0x16C04493949A8E52ULL
        }
    },
    {
        {
            0xEF70C94D838FF00CULL, 0x4481039F9E2A7E97ULL, 0x972C0F32CA77CCDAULL, 0x873EAB786BCB6E17ULL, 
            0xC9D1904C0196210CULL, 0x0C9108474FEB6650ULL, 0x687FDEEDC2646CE3ULL, 0x6F04F318C05F8751ULL, 
            0x365503C36A58D971ULL, 0xDAC0D02B7DF0E230ULL, 0xB72E42ADEF5D89FFULL, 0x5D488C6DCEAF6CF0ULL, 
            0x338034B09B25E603ULL, 0x21F25792EB617752ULL, 0xAB0B9395757289ECULL, 0xB9112ABA4E19BCB8ULL, 
            0x3425619555B2DBDAULL, 0x843D347B3722A611ULL, 0xCEC201B57F0094D7ULL, 0x68B5763A22F333E7ULL, 
            0x6650321A4D0F1B1AULL, 0x9B0BD49556A91701ULL, 0x59B25509D87753C2ULL, 0x8C9D2AE93E9A395EULL, 
            0xF7AC863FBF3C4656ULL, 0xC30963CA0B03311DULL, 0x0545BAD683B3FE4CULL, 0x7CE8C153358FCA26ULL, 
            0xCDFC3DA9A66E777DULL, 0xFD0AA5D2C3C0394DULL, 0xBE6D9E014D6A8518ULL, 0x27F1CB87FC7B34CEULL
        },
        {
            0xF05D8A2CA60E07C4ULL, 0x017BE28A1913D8B4ULL, 0xF765D56814FCFCE5ULL, 0x576A0FAD7271A4A6ULL, 
            0x6FDA92289DA9B4DCULL, 0x64B8B8A453798B83ULL, 0x41E8C75205F5B186ULL, 0x13A7B697D5A06DD4ULL, 
            0xA71EB5A93059EE19ULL, 0xE027CEA595539973ULL, 0x3D89A981BB1E3E27ULL, 0x8611E039C4E94625ULL, 
            0x4FDEF4DC52F52412ULL, 0xBA114AE6395C5885ULL, 0xEF9133BA34F3924FULL, 0xA3F520C9E2947170ULL, 
            0x5746FDA61F847E83ULL, 0x6714DD2B6B5AE7E2ULL, 0x91DA561863A248B0ULL, 0xD4EB86E28FDADFA2ULL, 
            0x4F97130876C9F362ULL, 0x268AABCD5BA5243FULL, 0xEC5BEC510021F8AAULL, 0x51D28132CABC0CF8ULL, 
            0x8F51F2D0A21A35A4ULL, 0x1076134456EE9C33ULL, 0x286C5010A8F5311AULL, 0xD7AB364D869E3834ULL, 
            0x440089871DE74BFEULL, 0x086FD5FEE51E1180ULL, 0xA2F89C2D1271C419ULL, 0xE74E669D543D5328ULL
        },
        {
            0x3E8A10E15A1489E4ULL, 0x4817C8345556AFDAULL, 0x67CFFD038CCA4F87ULL, 0xC3417DD25D2496C1ULL, 
            0x7E6D1F01779B35AAULL, 0x3A59C356AF706167ULL, 0x525A54CB30E1F9E3ULL, 0xA8CE425F3BA8E899ULL, 
            0xE7932F69CAE0055CULL, 0x0D640F7864B52929ULL, 0xA9DBFAE4B5F235B4ULL, 0x9654D53DE2CA3819ULL, 
            0x032935D2DDFE4F20ULL, 0x701F83500CCCDCB6ULL, 0x70848C7443AB33D9ULL, 0xA83A4D74D6297D06ULL, 
            0x8AB6B071A650F677ULL, 0x0441E42D4C36835AULL, 0x4BEC396B6CDE67BDULL, 0x7EE07B8E85D55224ULL, 
            0x741C7422650DE3D4ULL, 0xDE6D6C3F9F6A2F34ULL, 0x2134F4B4552D2EF9ULL, 0x0A22269947497461ULL, 
            0x18C1CBE42E103AFEULL, 0x645C1A8051D3F0E8ULL, 0xB3098F0DE64741FCULL, 0x409BFE648310065AULL, 
            0x3A0556B572E8C538ULL, 0x936B0396A80D6948ULL, 0x3BA927860A481BE4ULL, 0xDC0331B0E083D967ULL
        },
        {
            0x616871801A83CD6AULL, 0xFB2CF171138E9460ULL, 0x23CC88A504801BAEULL, 0x6C9DE5BE2D8462F1ULL, 
            0xA32E90AA534087B1ULL, 0xC43426DD4203FC8BULL, 0x660AD77ADF930DB6ULL, 0x63DE4F71280E047CULL, 
            0x7E2E90386E7AF343ULL, 0xADBEED9E2561770AULL, 0xD6A2CECCF5B14B57ULL, 0xF723757B55D8CAB3ULL, 
            0x306C374095C8AD7CULL, 0x5E3FBD42BC00BC14ULL, 0x35084ED73D1D8266ULL, 0xF17F870CA8AABA5DULL, 
            0x161C82D6D05DB771ULL, 0x6F02BA39ACD9A993ULL, 0xA22CCA11329CCFACULL, 0xFBC1743207035F95ULL, 
            0x53439B3D04EB0D18ULL, 0x7A2F89BD50834073ULL, 0x85F9AD895D419BDBULL, 0xFDB77631642CEAD0ULL, 
            0x38733541E9D04626ULL, 0xDD9BA9A22208EBF4ULL, 0xC88D00AE1D4167D1ULL, 0xA1348C698B5C580AULL, 
            0x82A9E264933B3D9DULL, 0x32CF1B6138CAC25EULL, 0x6DBDA421A0671C8EULL, 0x622B173D49D0829FULL
        },
        {
            0x55268EE6E82A5C2CULL, 0x3B27B83A51C5903CULL, 0xF05DB74928871470ULL, 0x08FCE76CE07C189FULL, 
            0x97AF78F581174E01ULL, 0x4ECB28434DD149F9ULL, 0x23AE41D7F0B332BFULL, 0x3882AE73881EF496ULL, 
            0x687586F73385ED81ULL, 0xA4F4A5A39EBD9210ULL, 0x79EC859604951C43ULL, 0x34CEBC5DE377BD12ULL, 
            0x77D673C83BEF3152ULL, 0xB0C8A0837462A366ULL, 0x16A3EA6D1A64CF34ULL, 0xA01910C044AEDEDBULL, 
            0xD9E8DC9E8309AA5BULL, 0x2EC9F35C51C3266EULL, 0x043DE9387044A0ADULL, 0x2E6AFC5C7ECB3CF0ULL, 
            0xD933A9A8E846962BULL, 0x4AF118AD3A363EE0ULL, 0x72D11EA54D183732ULL, 0x37DD3FE99E8C599CULL, 
            0x0D6D057F3D759165ULL, 0x1E803A40834A03DAULL, 0x377D57337F6B4A76ULL, 0x227F6CA790136107ULL, 
            0x5C7D0AEB0DADD0AEULL, 0x973006DABCA3569FULL, 0x0F397955FB150897ULL, 0x0EB50B8F2A51ABC7ULL
        },
        {
            0x5098D4DC6A098218ULL, 0x4C89521C3F2873BEULL, 0x46B073D13E88D2FDULL, 0x0CBEE1703CC2F1CBULL, 
            0xBB0EE08972DDA398ULL, 0x864EEED55C9E2F80ULL, 0xC7F051C21898AA71ULL, 0x4AA1400872D7ED32ULL, 
            0x6303D307D282D4FFULL, 0x301A19E39A747594ULL, 0xC2F0E0F15893D13EULL, 0x98E8F6D88F4DF697ULL, 
            0x753A127FAA05A910ULL, 0x5F0CDF36C08F791BULL, 0xF30049D8DD4A4B15ULL, 0xCD936B1C4FBB2D1EULL, 
            0x8EEBF02E37891ACAULL, 0xAFFF8C2B49AC2079ULL, 0x08F6580FDB1A97CFULL, 0x868A69FCE00024C4ULL, 
            0xFC4FC85BF34F7F81ULL, 0x10B91CB7C28E501CULL, 0x80C7C4FF67E98A7DULL, 0x7532173601389FE3ULL, 
            0x376860D7C2607735ULL, 0xE1247C47D3D0062EULL, 0xB5D908EA2391BABBULL, 0xB0D84E43A9DC5326ULL, 
            0x24B0497E612D4778ULL, 0xFE7EB3B928AB10B1ULL, 0xC676C4A4AE7AC5D3ULL, 0x014F1CEB90B05686ULL
        }
    },
    {
        {
            0xA3A7F60C000056A4ULL, 0x0E95336B1FF58DFEULL, 0x54F83E16089BDD46ULL, 0xCD7D33F396DDDD17ULL, 
            0x50D7DFCF0D96979CULL, 0x70ADCD6E8EB9C68CULL, 0x8D4F5414EA79006BULL, 0x97C5BFDAD241CD31ULL, 
            0x3DDAF3F89714A022ULL, 0x8064E77FA7C05A75ULL, 0x5360BC2A475DE9B3ULL, 0x155820876B149238ULL, 
            0xE4412C5CE6860820ULL, 0x14A2F4E1194B4AFFULL, 0x9E42E2C7877D2BAAULL, 0xF5A4D31AC194181FULL, 
            0xE62AB8AC4EE74895ULL, 0x7FE933F28A8C3183ULL, 0xEF8879FA4CC942F8ULL, 0xC204E4C84BE5D219ULL, 
            0xB75EEB4510922FF2ULL, 0x135AFA42F1D43790ULL, 0x72F2181BF9E29B69ULL, 0xC20F98725F977233ULL, 
            0xFE0A50572176EFB1ULL, 0xBF730211A4123562ULL, 0x6E15D0FAF8AA0BDEULL, 0x5BE1EECC5EC27A75ULL, 
            0x072DABED8D5DCB2CULL, 0x89ABBCA1CB52BD68ULL, 0x56BF3CDE4EC13F8BULL, 0xBA3EAD6897C08EB8ULL
        },
        {
            0xD4BE64A23AA69B7EULL, 0xCFEC8005A89F08A6ULL, 0x34D72D277B7F2A99ULL, 0x0910A86C66703B85ULL, 
            0x6F3842F68F29A77AULL, 0x79C5CCE1C329B0B3ULL, 0x23639C696DA40708ULL, 0x8D2CB4761AF66D82ULL, 
            0x1913DE46FBB9C2C7ULL, 0x541CC891DCBEA1A1ULL, 0xC43007BA1FA91EF9ULL, 0x2FA9A2720B1431C4ULL, 
            0x207C2FDC9971F82BULL, 0x45583CDA831CEB48ULL, 0xFF741294B86EEF39ULL, 0xFEBF086ABA37CD7EULL, 
            0x85CB32B33931F426ULL, 0xA98B926CCA53E126ULL, 0x9823E1414B4E8650ULL, 0xC5B569EC6E2A7D02ULL, 
            0x42B2A52F09D0A6D2ULL, 0x4263116DD4FF8DF1ULL, 0xE41E17F61347AAF1ULL, 0x49DCA4838D621BB3ULL, 
            0xEC59C7930FD20B56ULL, 0xD464A1A18B312E8BULL, 0x511336FC64C599B7ULL, 0x21F7E2D2683A9F22ULL, 
            0x7C01D9CD96AB1A6BULL, 0x86124C155037FAA0ULL, 0x7501F01B720AB379ULL, 0xEE6FC8A7842E42E5ULL
        },
        {
            0x78A1AC4192F41635ULL, 0x19833D60FCC53736ULL, 0x08A94E52381B65B1ULL, 0x6DBBF9BFCC50AC7CULL, 
            0x415633ECB6113FB7ULL, 0x8DFDC146BD00BBF5ULL, 0x7E6379E696DEE0EEULL, 0x67D2A8FCA7B9515AULL, 
            0xDA698B0AC37C8431ULL, 0x258DB8A732984C84ULL, 0x203000044173F4DCULL, 0x13764DEBB32B8FC7ULL, 
            0xF02CBCFF2247EAEEULL, 0xE27C7C146BC69C61ULL, 0x8F53EE76D6338F61ULL, 0x437642488764B0D1ULL, 
            0xF5B884C4DF339090ULL, 0xB971EB72AE8E9AB0ULL, 0x1DC8AA69AAC36BBAULL, 0xEB44B31A3C81136FULL, 
            0x7DB7F0ACF028D2B0ULL, 0x6EB8AE53E233BE77ULL, 0x7FD0EA308BABFA23ULL, 0xC521D8916A8F5382ULL, 
            0x9431B45051F25508ULL, 0x3538B5D92C42E86EULL, 0x78D98D0053D16251ULL, 0x2B29E12C8A60CF37ULL, 
            0x28781DD968ACE5AAULL, 0x0114BA3DA3FDCE25ULL, 0xAFF61CBA19149326ULL, 0x33AACC2E2FD00E1EULL
        },
        {
            0x313F30E15530B212ULL, 0x2D98C06366591F16ULL, 0x38D69DDA476774B9ULL, 0x7F93299695AFE41FULL, 
            0xA6A3C584F8207DABULL, 0x958DBEED457D26D5ULL, 0x44DE23EE9521AA4CULL, 0x225D26CC869E8BCDULL, 
            0x76386D4C4E02B332ULL, 0x440D32F85104A37DULL, 0x21EF4BACC0451C0DULL, 0xA21426C2C8AB5CC8ULL, 
            0x8D39646F9AC1ACA3ULL, 0xF26AAE3057FB26D9ULL, 0xCA1D2136B9E48184ULL, 0x8F806D693D8FE612ULL, 
            0x7FD1F741DBE723BCULL, 0xDE696B119124FAB8ULL, 0xE1291915992BE2DBULL, 0x200F9D1D5BD72365ULL, 
            0x1C97A5748DB58D74ULL, 0xA0583C675239B634ULL, 0xC52D9249F6D37B3CULL, 0x1595DE57787B0AFDULL, 
            0x825C844141E4AAC7ULL, 0x0FC6192B8DF5E838ULL, 0x7D08AC190C92F551ULL, 0x1B2A179EC8D049CDULL, 
            0xAAB4AC749B4D6E7AULL, 0x4AFC9CDE251B1629ULL, 0xC3EC623DF3966BD9ULL, 0xB4D838ACB35E480FULL
        },
        {
            0x4BEDCDCA7E5D60B0ULL, 0x8C03AB10636FE88DULL, 0xC9CF41E304D0050DULL, 0x143E155DD8AFFBCDULL, 
            0xA681464921390553ULL, 0xEF4BF6C3FEDAFDEBULL, 0x3FC9A5C18D47B594ULL, 0x032B1E9CA82C4C5BULL, 
            0xBF9A1AE371EAEBD6ULL, 0xCFC98BAB368CDFD2ULL, 0x4BD695475BB70545ULL, 0x986919292F27542BULL, 
            0x563B8C1FB9086A91ULL, 0x6068A6FDCDDCF85AULL, 0x27834C3201CEE757ULL, 0x32A7CC781D1509D8ULL, 
            0xF19D960A610DDE14ULL, 0x4093BC1521ED50EBULL, 0x8104ADC1394FF663ULL, 0x45D4230C7E480E18ULL, 
            0x22E29FE5F769F96FULL, 0xC5E95464BF15E079ULL, 0x15DCD22A7C3D713CULL, 0xD509F9667F7EFDDEULL, 
            0x010E292D6616A04FULL, 0x4BB490E740D3605DULL, 0x170BB72CC6A6560EULL, 0x537396A3868E09D4ULL, 
            0xC343E3071148DD9FULL, 0x2C9215E4C69B2E2FULL, 0xC0A8116E6C198856ULL, 0xD6597D717C6476CDULL
        },
        {
            0xF861D8E85227CB76ULL, 0x714AFBD55B192ABAULL, 0x53827BEC4205F712ULL, 0x1C088F430427B876ULL, 
            0x76D53E004C342ACDULL, 0x3818697614D111BFULL, 0xFD85CDCB0CEF1A4BULL, 0x37E9014A824C8D0BULL, 
            0xF14BA9849C5AD2FEULL, 0xB07395CA73191AF1ULL, 0x3469FD9CE73D0CE9ULL, 0x476560BBFF618EC4ULL, 
            0x0927A4EF1A34D906ULL, 0xF6537DA3E558EAD0ULL, 0x7ED8917166C5ACE3ULL, 0x8B8220EF91E89D67ULL, 
            0x632F601C5BACEBE9ULL, 0x890C3E44ED1CF874ULL, 0x08031162B38AA814ULL, 0xCB45E7EAE75A392AULL, 
            0xA97F0D1654E3605AULL, 0xB72B78A556B04AA3ULL, 0x115741739036E0CCULL, 0xED7A4014EA71C50DULL, 
            0xC516BE65DBF6B7CEULL, 0xD4413229AEB597AFULL, 0x0DB66D60CF525C06ULL, 0x7CD63C355DB13353ULL, 
            0x433B3E060EDE896AULL, 0xA361E2767C340E14ULL, 0xCC5A623EE23B44F9ULL, 0x4EB3B2100DA4AEEEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Vega::kTwistConstants = {
    0xD8DF662A59CF72FBULL,
    0x89A24A17A093465FULL,
    0x66CA2512DAAC7716ULL,
    0xD8DF662A59CF72FBULL,
    0x89A24A17A093465FULL,
    0x66CA2512DAAC7716ULL,
    0x563F22B36D016E53ULL,
    0xF5E1500DAF58919AULL,
    0xB8,
    0xDB,
    0x8D,
    0xC4,
    0x69,
    0xDE,
    0x69,
    0x30
};

