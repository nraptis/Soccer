#include "TwistExpander_Saiph.hpp"
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

TwistExpander_Saiph::TwistExpander_Saiph()
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

void TwistExpander_Saiph::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Saiph::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x99BDE6D5029C77B5ULL;
    std::uint64_t aIngress = 0xE67446D441D963D3ULL;
    std::uint64_t aCarry = 0x98C9835835BD60CFULL;

    std::uint64_t aWandererA = 0xAE0D6A75A1C5C600ULL;
    std::uint64_t aWandererB = 0xA3E7D6E8F5BB5C8BULL;
    std::uint64_t aWandererC = 0xC35373FAF57BD1C9ULL;
    std::uint64_t aWandererD = 0xCBCF03755AA91AD0ULL;
    std::uint64_t aWandererE = 0xA4444788EFE8021AULL;
    std::uint64_t aWandererF = 0x9339894C2DE8B39FULL;
    std::uint64_t aWandererG = 0xD17E31417EC9D32EULL;
    std::uint64_t aWandererH = 0xC00F1BA88781D90EULL;
    std::uint64_t aWandererI = 0xAC1A02505E462CA1ULL;
    std::uint64_t aWandererJ = 0xDB34EB2ACA15E905ULL;
    std::uint64_t aWandererK = 0x9AD1E24501281B71ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xE21FD93E7274879FULL;
    aIngress = 0xAA88AA16DD5D5DB7ULL;
    aCarry = 0xF552AE4D619B08A8ULL;
    aWandererA = 0x9C2EB7E8E5B8752AULL;
    aWandererB = 0xED50D67C0FCAAC55ULL;
    aWandererC = 0xF01E0CD1B5412A22ULL;
    aWandererD = 0xE4FD820A25084AF4ULL;
    aWandererE = 0xB94335916D445AB1ULL;
    aWandererF = 0xC72FC7E2B58B4E83ULL;
    aWandererG = 0xC493E4EE2374EAD4ULL;
    aWandererH = 0x9D9008FB26209E31ULL;
    aWandererI = 0xB9EF80475E29ABE3ULL;
    aWandererJ = 0xEFA2118588CDF7C8ULL;
    aWandererK = 0xFDDE5011E3801434ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x84AFCE2C63712D30ULL;
    aIngress = 0xD1B1ADDE49055060ULL;
    aCarry = 0x9D8DC653862A53D5ULL;
    aWandererA = 0x95A9E3E624C7953FULL;
    aWandererB = 0xA4CCF9540C425C7FULL;
    aWandererC = 0xBC7631DA2923ECFBULL;
    aWandererD = 0xDB002AFC6D08B3B9ULL;
    aWandererE = 0xABA7114B378B68E4ULL;
    aWandererF = 0xFE8579AD1C814FDEULL;
    aWandererG = 0x8DB00BE61B9E29C6ULL;
    aWandererH = 0xC673C6A04F21856EULL;
    aWandererI = 0xAF132715E89DD532ULL;
    aWandererJ = 0xF0815FD90D3CFF09ULL;
    aWandererK = 0x9F4F310D788286C6ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xDFF8647CBE1355A3ULL;
    aIngress = 0x9A3C60060FFA1E11ULL;
    aCarry = 0xFDD4023EDEA0FC29ULL;
    aWandererA = 0xD2AC9F2D51AFCCD8ULL;
    aWandererB = 0x81FBC3688A53F566ULL;
    aWandererC = 0xBA5A4A6C59248136ULL;
    aWandererD = 0x9232C7F7C6110D4EULL;
    aWandererE = 0xAD490A67EA086A0EULL;
    aWandererF = 0xFE62F9A1C1737117ULL;
    aWandererG = 0xB52E5951497D2656ULL;
    aWandererH = 0xFFED88BAD77A4EE9ULL;
    aWandererI = 0x8C0B7031D2A3B5B1ULL;
    aWandererJ = 0xA6F26B6152CE5D5AULL;
    aWandererK = 0x9C694DCB7F6F2194ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xD647DD34D76AA09AULL;
    aIngress = 0x960BD671AF0B8FAEULL;
    aCarry = 0xB56DDD3C4788963BULL;
    aWandererA = 0xAEDE081341907D8DULL;
    aWandererB = 0xDE8A3ABBA5A61162ULL;
    aWandererC = 0xD91312DE7E786006ULL;
    aWandererD = 0xD22DC6B7D7B83FA8ULL;
    aWandererE = 0xBE99E85782463D76ULL;
    aWandererF = 0xBED560B7D8827FFDULL;
    aWandererG = 0xAD573CC9FDD0B416ULL;
    aWandererH = 0x98474FFB77EEEED8ULL;
    aWandererI = 0xEC12EBC0D8CAE7FBULL;
    aWandererJ = 0xA9448FB342BA005BULL;
    aWandererK = 0xD50F22087E101C54ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC4D68B269DA23B8BULL;
    aIngress = 0xE475F62FFE67644AULL;
    aCarry = 0xB7390C26100AE492ULL;
    aWandererA = 0xBB19F82352BBB758ULL;
    aWandererB = 0x8E600EE894AE6E74ULL;
    aWandererC = 0xA66CE58EB99749ABULL;
    aWandererD = 0x9DC675DCBA764E4BULL;
    aWandererE = 0xFBFE83692A431029ULL;
    aWandererF = 0xEC07B1435B9D7A93ULL;
    aWandererG = 0xB528EE2EA68AA6E7ULL;
    aWandererH = 0xA711C61285E74050ULL;
    aWandererI = 0xECAFBFDBEB47F797ULL;
    aWandererJ = 0xBD6EE25B42318A11ULL;
    aWandererK = 0xB8BD3E2AACB117C2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x92DD053093935D7FULL;
    aIngress = 0x9B1D83764973D8ACULL;
    aCarry = 0xEC21A293B05C651BULL;
    aWandererA = 0x9B389D05E84844D3ULL;
    aWandererB = 0x85F729EC0B3B8FACULL;
    aWandererC = 0x80E5D50546CCA4AEULL;
    aWandererD = 0xCD18303C98D41DCCULL;
    aWandererE = 0xEFFED25D64D2CE92ULL;
    aWandererF = 0x9A9D315D6CBEB932ULL;
    aWandererG = 0xFE6472824EA8D975ULL;
    aWandererH = 0xC0BDEEF91522C25AULL;
    aWandererI = 0x8E3C784832B36E0AULL;
    aWandererJ = 0xF3371F415F2A7C69ULL;
    aWandererK = 0x95B236A52F4B92BEULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE63FE0372802726AULL;
    aIngress = 0xBC5315138D73D9E2ULL;
    aCarry = 0x9D4541098FE7A024ULL;
    aWandererA = 0x88842B22FD5A8493ULL;
    aWandererB = 0x80296B2D7FD6B444ULL;
    aWandererC = 0xACDF76586E79DA6BULL;
    aWandererD = 0x9B66B87DABA54EEAULL;
    aWandererE = 0xC933B256BE826AAFULL;
    aWandererF = 0xC9FDBBEC472EDDEBULL;
    aWandererG = 0xD02545448DDDDC07ULL;
    aWandererH = 0x88E7286BE576FE71ULL;
    aWandererI = 0xB4406DC9022482F6ULL;
    aWandererJ = 0xAFAA06836A21A66EULL;
    aWandererK = 0xE5A397AB4A819D7AULL;
    //
    TwistExpander_Saiph_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Saiph_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Saiph_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Saiph_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Saiph_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Saiph::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9A8D6AF26B1B5E17ULL; std::uint64_t aIngress = 0xF38C8486482337FAULL; std::uint64_t aCarry = 0x890BF010BDEC0573ULL;

    std::uint64_t aWandererA = 0xDC435DA51F929759ULL; std::uint64_t aWandererB = 0xC02165480F3FBBF4ULL; std::uint64_t aWandererC = 0x8DA41AF179FE3AA4ULL; std::uint64_t aWandererD = 0x889ED43C241B759BULL;
    std::uint64_t aWandererE = 0x80A1859FA4A13ABFULL; std::uint64_t aWandererF = 0x96946C42207A9DE0ULL; std::uint64_t aWandererG = 0xAB48AD05243F79AEULL; std::uint64_t aWandererH = 0xA94117F1D627668FULL;
    std::uint64_t aWandererI = 0xC3342983F3A58355ULL; std::uint64_t aWandererJ = 0xE29E041B491B545BULL; std::uint64_t aWandererK = 0x99A5ADF91FA63754ULL;

    // [twist]
        aPrevious = 0xC81A8A77052CE5B7ULL;
        aCarry = 0xA4230E901F61A28BULL;
        aWandererA = 0xF5C0E74202668A17ULL;
        aWandererB = 0x9261C0162DF1AA3CULL;
        aWandererC = 0xFD10B5FA79492254ULL;
        aWandererD = 0x968943F29FC69024ULL;
        aWandererE = 0xD479F7C7CCCF792AULL;
        aWandererF = 0x96999909A559AEE7ULL;
        aWandererG = 0x8C385B48772A059FULL;
        aWandererH = 0x96BEE0A2E4B26E9DULL;
        aWandererI = 0xAE826479E05C1FF4ULL;
        aWandererJ = 0xE1374AD54972300EULL;
        aWandererK = 0x809B4FD2C3C0C101ULL;
    TwistExpander_Saiph_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Saiph_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Saiph_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Saiph::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Saiph_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Saiph_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Saiph_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Saiph::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Saiph_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Saiph_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Saiph_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Saiph::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 30 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 15474
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1870U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 30 of 33
    // Exploration cases: 0
    // Structural maximin 513 / 674; family total 15422
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 655U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Saiph::kKeyRotateASalts = {
    {
        {
            0x88F7109F5ACD7C53ULL, 0x6BFE6940AE7D7493ULL, 0xFEFA22190B403766ULL, 0xC5263A912A1D61FCULL, 
            0x63E007A204659DD0ULL, 0x6F220B771029B857ULL, 0xA3A26A144FB5EE59ULL, 0x3D741E3510964A9AULL, 
            0xFCFB522114F49FF2ULL, 0x5F08496AB53AFEB9ULL, 0x14EB343763E5D264ULL, 0x84DE1E4FA716AB24ULL, 
            0xB66AFA393671F4C9ULL, 0x5E82F8139A5F84F8ULL, 0x6D4D07E66E968377ULL, 0x3ABC9C3A7CC970C3ULL, 
            0x738A304AB61C907DULL, 0x9948621BA9D5DCCAULL, 0xAA224538E856E0A3ULL, 0xB7D044DE9517134FULL, 
            0x2166B0D035749612ULL, 0x2D6C3C955E81606DULL, 0x1C4287C80555A43CULL, 0x8B62250003C7E117ULL, 
            0xBD46A94BCB00DB9DULL, 0x9A4CA67E14D0CD18ULL, 0x14DB622583A017C0ULL, 0xBBAD4238C40B0E54ULL, 
            0x915C2C03DE898346ULL, 0x5845C35E2B9C855AULL, 0x482825898B165660ULL, 0x6E9EE4DB03165379ULL
        },
        {
            0x4DDAEDEF0D01B5BBULL, 0xFCA2ABCBFEEB5BA6ULL, 0xC703EB524C992C99ULL, 0x0EA430E803A644D1ULL, 
            0x9B6E0449ABB9409AULL, 0xAFF5B2531C572F16ULL, 0xBA6FED3A8E36C992ULL, 0xA4BF36BC11373BB7ULL, 
            0x1654DC899A0121DDULL, 0x39EB1666C609C0C3ULL, 0xB12DFEB4AE07E1C8ULL, 0xA2B43D2B20E5A4F1ULL, 
            0x806373486BC8DAC2ULL, 0x07B03B3D7CCB29D4ULL, 0x029E58B645D3BABCULL, 0x9144AA1F260FA4AEULL, 
            0xBC7E9F3696654190ULL, 0x1800BFC080CEFA11ULL, 0xBF61FF9ECE9672FEULL, 0x4F88C367586B2F8BULL, 
            0xAF27BCA31A614EC8ULL, 0xE993570796645842ULL, 0x5A82F5F1A8D796DAULL, 0xEEED3DD43325DB6FULL, 
            0xC50EF7E24832BD71ULL, 0xF5B6E301DC6E03AFULL, 0x5EEC265CFC340DE1ULL, 0x811E8EA4382974A0ULL, 
            0x8583D6131B61A24FULL, 0xF9344E712E3F7F9CULL, 0x6F2AA54A649BF7FAULL, 0x03FAEAE6CF4028A3ULL
        },
        {
            0x0FBB734EC2EB2F19ULL, 0xF762A9F05D0F9329ULL, 0xB950E478AD1BB849ULL, 0xA2B023BF7F0946F5ULL, 
            0xDDE4C814019167DFULL, 0x0E6271B8AB42A58FULL, 0x61C0AB4E9151634CULL, 0x11FE85B63F548F3DULL, 
            0xF6DF348FFABDBEACULL, 0xDF3B4C3B959F8A75ULL, 0x51A2BB5E2C30EB32ULL, 0xD435EEB3D220EB4CULL, 
            0xC0AF602CD09530E7ULL, 0x8B7C2A2474A20FF7ULL, 0xDD73641D0E890531ULL, 0xC1420ED75A18F157ULL, 
            0x4662DD7D44F3B3F5ULL, 0x24A20A902399E223ULL, 0xF9B3D90CBEA841B9ULL, 0x1137F7DD178DE6B0ULL, 
            0xF51F68E3C49FD453ULL, 0xC6FE6BC99A81869DULL, 0x7D607DD6FC6ED206ULL, 0xEAA77C2A37100808ULL, 
            0xEF6D41D591B65531ULL, 0x4D0E054A76DC2D58ULL, 0x01EC0BB7E1703BFFULL, 0x01BDA9A963DCB8AFULL, 
            0x23B7C622B8924E73ULL, 0x0E23A2B436B8E847ULL, 0xF60EF1A4DCCAF370ULL, 0xA77473D9C5B10E62ULL
        },
        {
            0xE5E447D3CB7F3374ULL, 0x74861E929DC15A3DULL, 0xA5A92EC88C4B0A42ULL, 0x4AC1BAE1E40E25F5ULL, 
            0xDFB4ED1141224325ULL, 0xCE222CFACD29858FULL, 0xABEB4BA733F672D3ULL, 0x1964D20255DDFE68ULL, 
            0x8E7847284189F410ULL, 0x134708A18C55C494ULL, 0x0A39BDAEE95F764AULL, 0x9373CADA00EC0F66ULL, 
            0xEEEC579B8ED726CEULL, 0xF08E6B4ADF8E5D04ULL, 0xFB1E3DA3DF8D33DFULL, 0xCE1DE0E108AD35D0ULL, 
            0xAB00A622A1AF249CULL, 0x2276C38A6B6AA80AULL, 0x1173F5005A098D63ULL, 0xB5D3D0DF55777779ULL, 
            0x839E96D7BDD4836AULL, 0x2A7EA941BA714E3BULL, 0xB1C2086835B9684FULL, 0x4FF8A35A5F53B62EULL, 
            0x831425C0DCD08296ULL, 0xB34504D46759955CULL, 0xCC8A5FBCB7BBD7A2ULL, 0x2777917085D45F89ULL, 
            0x77E4AEAFA4E8DA50ULL, 0x1AACDB36A96260E2ULL, 0xE88A65B95225D3F9ULL, 0x71F5C79460A618BDULL
        },
        {
            0xBF5B085B20AD1744ULL, 0xFB2F565B86308A5FULL, 0xA82DFAD25FE08092ULL, 0xCA3AC0653EF70B2BULL, 
            0x432D51F320B3B834ULL, 0x2D3707F617C0B6EFULL, 0x76574CC297CB6211ULL, 0xBC332D7FAB021379ULL, 
            0x63BF2E4DE0A137B5ULL, 0x8F7E9A6249C84721ULL, 0xAAAFED161C465038ULL, 0xDCC46E37C2658C21ULL, 
            0x24FF9F4CFC46F0E8ULL, 0xE68714E26449614BULL, 0x8C6B080D7199947EULL, 0x14166180831CB8DBULL, 
            0xA68E5C5A51AB1A0DULL, 0x76C5A7A4E81D1292ULL, 0xA3C1DBC1BADAF08DULL, 0x50BAE714B519CF70ULL, 
            0xEBAE5DC97B5CDDDDULL, 0x17A565F380F55A11ULL, 0x87111E11B6CEDE64ULL, 0x07E55E8DF4DB6B7AULL, 
            0x3343C9ACEEBF63BDULL, 0x46C174305624C8C5ULL, 0x76F93834C3C92E0EULL, 0xAFA6FAB89C425589ULL, 
            0xE6C0DB9253A83404ULL, 0xE8B92AD3235C4F6EULL, 0x06018CD86C0945E3ULL, 0xCCA6203FA94556A2ULL
        },
        {
            0x4C5B0B4C2CC668F6ULL, 0x1AA27A06500572F9ULL, 0x223601C7D0CA7A65ULL, 0x379DF1E7E5F35B5EULL, 
            0x07309948C76E440AULL, 0x210CC64365411D3CULL, 0x01D486F7DC098522ULL, 0xB35EDB9F73789CD0ULL, 
            0xFE6468B7A1E0E4FAULL, 0xC6A14510790A2B72ULL, 0x2C5198F0735A264FULL, 0x4D9DA989C02B9534ULL, 
            0xE5AEF9CD1989D260ULL, 0x6DEE8C7389E79277ULL, 0xE6EE03838D378A03ULL, 0x36980660DA67040FULL, 
            0x935E8CEC91BF2A94ULL, 0x177B380B895E6664ULL, 0xCED4DCA0F4295369ULL, 0xCE5451CDE2B70E0DULL, 
            0xB3EE43E91D97BE22ULL, 0x04347FB1E7A9C272ULL, 0xDBFBDE6E95B661DFULL, 0xD205E91B821906C0ULL, 
            0x5CC6809BA46B7E4FULL, 0x8F4B6416FE7FC4D6ULL, 0xADBF264D905FBC68ULL, 0x4EDDDC0EA7F302F5ULL, 
            0xED1C97517AF23609ULL, 0x57724D24AB89D35CULL, 0x8680FAF5548A264FULL, 0x4845F03CF2588FF0ULL
        }
    },
    {
        {
            0x1E47267F2B108DA2ULL, 0x3A3F62DFAB48CF79ULL, 0xCCA01ED5F841C42DULL, 0x6057D917AE187937ULL, 
            0x3DFE9D3630D60983ULL, 0xF77022CD8A34F449ULL, 0x29943DED77423FB2ULL, 0x3831897E03910C94ULL, 
            0xCAB6D6014CC4DD96ULL, 0x8B7768604E39D066ULL, 0x4899195357FE2B09ULL, 0x692FC5FDCEF463B1ULL, 
            0x228E690BA98C6012ULL, 0xFC2724D35C9A8D4DULL, 0xCDA658BFBD4AB0F5ULL, 0xFB9AD84DC7869C4DULL, 
            0xFC4F9CEE8A383903ULL, 0xBCB2A70459FFEA2CULL, 0xFC578CB0BB9886F9ULL, 0x3D10BBA0432ADB7EULL, 
            0x8C74EC3A201DE345ULL, 0xBB3C3D275D3AD487ULL, 0x7713F7AEF6EDAA9FULL, 0x21201C8A5438FCEAULL, 
            0x265B8BC205C43E91ULL, 0xB3C1BE1F8D854F92ULL, 0x028F6B827E3639A6ULL, 0xD7BF93CB5F9B87AEULL, 
            0xE765F6771DABD8A7ULL, 0x11289F2BC3220A78ULL, 0x05E385A6FDCFA1C7ULL, 0xF9A9260A75FCD829ULL
        },
        {
            0x0A648C5B63C09563ULL, 0xFA88BAAEE11A5DDDULL, 0x8AD12C761C0F179FULL, 0xA38FB2E2E95C2BECULL, 
            0xE85D6AE1A987A05DULL, 0x84388A98451E5A4BULL, 0x0A1B7A12C0B1A467ULL, 0xD3810370B7EE1BE0ULL, 
            0x65F06648D8F15BB2ULL, 0xB1311E3024F2F21BULL, 0x5FF74281C3074D02ULL, 0x9B1051CB5A980625ULL, 
            0x7D8E67ED96111DD5ULL, 0x8BCF83FE4DED0E93ULL, 0xEA77DE7221671F9BULL, 0x4EBBE4569A34C8CBULL, 
            0xC7C63E4EC49BEB2BULL, 0x5C25843B1E7C7CD9ULL, 0xF6BA68805F561F1EULL, 0x4E215DE627B89293ULL, 
            0x8596F3C2A5F9B1CCULL, 0x6D4120F387EFCB52ULL, 0x9476B2FC3AF25B4FULL, 0xCBB3CE265F126A3DULL, 
            0xC1DB00681AD16A14ULL, 0xD06C4DA0FA3873ADULL, 0x31E65E453B2EA088ULL, 0xE7903B819D7FB84BULL, 
            0x1268D6AEFBBFC71CULL, 0xBD2D914291CC2FA8ULL, 0x7D1FFAE652D7B73FULL, 0xE1F4D807BA5FD647ULL
        },
        {
            0x6739B059960F9CBDULL, 0xC3786B364554A0EEULL, 0x3105890B030E6C18ULL, 0xCB35BE468EEDDC2AULL, 
            0x19D82544B00109C4ULL, 0xDAFA6767EA0AF29BULL, 0xE70C7631E31FEC8AULL, 0x8C7539550616553AULL, 
            0x3A39DC12EE2C2A4EULL, 0x924553AC13A1FB4DULL, 0x202C9AB41588B641ULL, 0x7F1D234675A29BFBULL, 
            0xE77B6E6BB29EA2EBULL, 0x6135328CF1CD7657ULL, 0xD6D9D9C8E6AD0691ULL, 0x865E01D6EF7B1776ULL, 
            0x2A337CC0C1DE25BBULL, 0x113D07CEF33D1028ULL, 0xD67F79908CF11D8FULL, 0x4AD50DF8B7130959ULL, 
            0x47FCE9774D278F87ULL, 0xF34B234D855D5310ULL, 0x60245D8AFF5BC648ULL, 0x775E5C1B1F93590CULL, 
            0xD9223C792DD30EBEULL, 0x82102D3DB2A2D4ACULL, 0xBBBBEF773ABE9DF3ULL, 0xF097138D1D56D8E4ULL, 
            0x72675DE562D1FB7EULL, 0xA90D3726A16F4543ULL, 0x8502DB51B606247AULL, 0xA377054164508791ULL
        },
        {
            0xE4DD2BA1E526C89CULL, 0x919B0A289BAA5911ULL, 0x31C9B671F0EEC14EULL, 0x216426353BAF9CA6ULL, 
            0x26C9A31202714B59ULL, 0x352E557432113F4AULL, 0x6E74C1EC1752FB29ULL, 0x2E4CDD89E2620ECFULL, 
            0x4D5538FC6041AAC7ULL, 0xA9537C6BE027196DULL, 0x084771700BB5E76FULL, 0x4C0D5D326FCB7F5BULL, 
            0xC65B7DC33ECDBE47ULL, 0x13DB970043B91006ULL, 0x84C0EB80A4BA8D2AULL, 0xDEAF5FE3EEF031A6ULL, 
            0xB49AD5AA31D3635FULL, 0xCA406D2FC5603E38ULL, 0x2461BBFCF74984FBULL, 0x3DB5F137F9CF1995ULL, 
            0xE79D80F9F7ADDFE7ULL, 0x2A00B3A983E9A36DULL, 0x95DD0B90DB11A93AULL, 0xB72DD806026B6CF5ULL, 
            0x7FD1BD829266DFE8ULL, 0xA06F2D4F44D5B9CEULL, 0x717CB2B1AB4D4167ULL, 0x431C04CD287ADBBDULL, 
            0x58CBC70200D51C49ULL, 0xD9F61C244545D7C0ULL, 0x046E17FE4F3E093FULL, 0x4DBE001CE22E9B1EULL
        },
        {
            0x3B3AB390E8D47E02ULL, 0x01EE988D1C5C016DULL, 0xCC082A9260280531ULL, 0x8E659CEE0D38386CULL, 
            0x2F16A5A4C4F1ACEBULL, 0xA1E24571C0F27397ULL, 0xB93CB5EB6DCEDA85ULL, 0xD793B9AA3AAFE966ULL, 
            0xD6F6F9B094C4C3BEULL, 0xBA36CE41195C9F41ULL, 0x79AB771652FDB403ULL, 0x804CA07A217BE302ULL, 
            0x1E4D1740929413E7ULL, 0x22AD66F3A47D0E9FULL, 0xC8BFC73AE77EA7A1ULL, 0x79DB4164220115A2ULL, 
            0x9551872D677A72B9ULL, 0x826F637984E12847ULL, 0x57A6DDEC326AA2FCULL, 0x62E0997542C345EBULL, 
            0x52C41C0180953781ULL, 0x7DB4DDA61FE9DFBDULL, 0x5581A47904108F12ULL, 0xBC069783A125A166ULL, 
            0x1FFFE9109D1B3373ULL, 0x2714D29DB9A7BD36ULL, 0x598A99D9627AB9BCULL, 0x1AF983769CBDBC22ULL, 
            0x142865E6CBE95A45ULL, 0xB3B8234F56ABD231ULL, 0xEA8351FC63CB520BULL, 0x18D70B792BC08365ULL
        },
        {
            0x85A1A2501295FE32ULL, 0x5851E2A04A0F69E8ULL, 0xA720B75B8C63D9CAULL, 0xCEA7C4154C68A94FULL, 
            0x3D1F9321A8FB8337ULL, 0xCBFC44DE7A139AEAULL, 0xF23565AA364C77B3ULL, 0x5CA45A8F861FAFE4ULL, 
            0xCA4B33B1BD84F663ULL, 0xF444AD2F315F18E0ULL, 0xDDC076334182EAD5ULL, 0x00E4D2EFDDF09FB7ULL, 
            0x002C256FC0FB5890ULL, 0x20ED26A2DF8CB409ULL, 0x9A71832D5AAD7795ULL, 0x0CC11BB927E2C7A2ULL, 
            0x129625554053548EULL, 0x6BF16A7D646CA04FULL, 0x79EDB0640219D363ULL, 0xEDDAED5610969A1EULL, 
            0x48BE72110D961D33ULL, 0xA6A9D6CA662F85EEULL, 0x7D16D019173BD5F6ULL, 0xC104B79AC84C22BEULL, 
            0x2F3DBEEA3B8CC9FBULL, 0x80A7992A30B71A18ULL, 0x2E57FC26140A70C9ULL, 0xD0DC87A8F795A243ULL, 
            0x930B4E285E7DAB3BULL, 0x863A94F2409C3A21ULL, 0xB83444D7051D11B6ULL, 0xB090E2E4D8FC46FAULL
        }
    },
    {
        {
            0x3CF5BFC82C5FA708ULL, 0xE3228A71F50294A6ULL, 0x8509A75FA44E84D3ULL, 0xC5D664CE7367ED0CULL, 
            0x3734AF7FF756F4C1ULL, 0xE586460D25E7D2E3ULL, 0x5F8D2906CCE883ABULL, 0x06FDE19B89C5303EULL, 
            0x624006632FE7C13FULL, 0xC5D52976B7D51A89ULL, 0xFAFF0FFC43C7198EULL, 0xA07C60ED52573394ULL, 
            0xBA179FD86C41077DULL, 0xD4172347A1F81629ULL, 0xA03F40270DDBAB8FULL, 0x60C6FAF9EE9D8BDEULL, 
            0xB52C90BADB261C34ULL, 0xCF12A401752A0C45ULL, 0xF6ADC25643171233ULL, 0xE6A3EB791F930C5DULL, 
            0x294235A8DB9638F0ULL, 0x83C32266B2927794ULL, 0x9AFCC3D226AE551BULL, 0x893491D7190959E4ULL, 
            0x571C3CAB35395103ULL, 0x6CE565005A5A27CAULL, 0x5AC396C418EDAAFDULL, 0x8EDF22FCE8809356ULL, 
            0xDEF2E67BA7504623ULL, 0x2DAE0BDABFDE98D7ULL, 0x2F6A6DB6AD1B988BULL, 0x7912340C0EAF9EEBULL
        },
        {
            0xFAB779B6D5881EB0ULL, 0xEA91FDC75E7D08CFULL, 0x687DA0B7EF715FF0ULL, 0xF433B5CFEE2D42F3ULL, 
            0x68E184E31373709CULL, 0xB747AC7ED1C08154ULL, 0x405A6DDCEFD0D927ULL, 0xE9F9903D8B6AD0B5ULL, 
            0x75DC67EE500468FEULL, 0x64214D9EF36D5063ULL, 0xE5FF0B3FD6118609ULL, 0x1BACB594E969D3DCULL, 
            0xA96256411EA9067DULL, 0xDF8CCBC2C9413514ULL, 0x4C14040BB476A645ULL, 0xBFFE77B94A28212CULL, 
            0x86FA3682B42250EBULL, 0x61B37DB586C7673AULL, 0xAC184C3F9036006FULL, 0xE17DA5425227C182ULL, 
            0xB5957DDAD8BEF7CCULL, 0x1FC9F49F24B0E27DULL, 0xAE042D09FC60376DULL, 0x439506C2644E6845ULL, 
            0x9651F8F136529502ULL, 0x6AD601071295A8F7ULL, 0x6C02438437DA1980ULL, 0xE58869CC14EBDC47ULL, 
            0xBB3080D0182DCE07ULL, 0x95E4AEF79BF0B975ULL, 0xBE2006A2FA70FF44ULL, 0xCE76F79F8C0E0836ULL
        },
        {
            0x6B57AE5B7B584D21ULL, 0x25F2EEFD5F36EE62ULL, 0x63116FB6D87123A4ULL, 0x6F2531EB5F9DC0CFULL, 
            0xC370D5B3950DB03CULL, 0x485AA737F78C7FDDULL, 0xE2831BCA2D29FB34ULL, 0xA5FFF75C1C7DB09AULL, 
            0xDE681504BCFD53E8ULL, 0x6134A8D40A8D9048ULL, 0xEF966835D259A53DULL, 0xC1F1645F02B84749ULL, 
            0x54BA51361DAA33BFULL, 0x6CF42A2A002E7183ULL, 0xBE0633C987ED0961ULL, 0x0089C9B98CA0AACCULL, 
            0x54A27DB8DDB01360ULL, 0x750E7463EE1AFEA3ULL, 0x5D9B7BFEE8BF5B0EULL, 0x66E83E1CB38EBA5AULL, 
            0x0220AA7831E173E9ULL, 0x101D966125C9050DULL, 0x88AB15B780E42A01ULL, 0x5FB726F8055BFE72ULL, 
            0xC76F63776F530277ULL, 0x2C58DDDF9CA68AC6ULL, 0x0A5679FB91B33694ULL, 0xD9C969A13366DB1FULL, 
            0xFD29FDF5E5DFC2B0ULL, 0x52F307D124866027ULL, 0x4B4C098E92699F89ULL, 0x86D7890572E7DE00ULL
        },
        {
            0x45DBC380B0497C5DULL, 0xD74CF48D1DB10311ULL, 0xEC0ED8920A94C565ULL, 0x04A9A9556D2E07D1ULL, 
            0xB3A40147B9B11B65ULL, 0x717019E3FA102668ULL, 0xA9A533549F789494ULL, 0x92D68835261DDAF2ULL, 
            0xCD400AA1A40F4720ULL, 0x1AAA33ACA28736C3ULL, 0xD5ED78A32DF4D257ULL, 0x45771B14557CE9FAULL, 
            0x46F589E57103890AULL, 0x29DCB5F0086F4D8EULL, 0x30A78A78CE2FF8A9ULL, 0x4334FB68A3C889BCULL, 
            0x10464D9109D96BDEULL, 0x5D00A3D2356E7DD6ULL, 0x65290CF8EE77B09FULL, 0x6FC47E43F94FA5DDULL, 
            0x4102309D02E5A4A2ULL, 0x0E33BFE8942CC7AAULL, 0x9B41B2C9D70552AEULL, 0x0BC480D9E22512A7ULL, 
            0x8983D5B5B5CD7C0CULL, 0x6BADB0B078F994A5ULL, 0x95971EB8E11E7087ULL, 0x816995939DFA1D65ULL, 
            0x63ADF5D18C579B20ULL, 0xD06198D6A6A545DAULL, 0x8D572DCA1748A0CEULL, 0xB7D82061C27C62DBULL
        },
        {
            0x64279A6D4910331EULL, 0x3A00E58A48AB1D63ULL, 0x21900981BDC8205FULL, 0x4A3C81063E2FAAD7ULL, 
            0x905B7F0296D649AFULL, 0x0BAAE436B7F41633ULL, 0x7D0C13FB59F59B0FULL, 0x0F7F676A4A16AE09ULL, 
            0x2F43D5A5CB52ABBFULL, 0x737D4BEE14F7B420ULL, 0x1B845226667DA548ULL, 0x88E49EA07174748CULL, 
            0x3101E06410735C84ULL, 0xC74935E31F2578F3ULL, 0x894718CFD8DBFD8DULL, 0xB993DD6B2C161219ULL, 
            0x217DCEBF7162A09EULL, 0xA48D0C3A01B2AC87ULL, 0xF9239E7C950BE340ULL, 0x625947F3457940A6ULL, 
            0x7A8C21135CEAEF1BULL, 0x27D769ACB3A7E922ULL, 0x6387928AFAEA9837ULL, 0xE65AB68C6478849DULL, 
            0xE18EEB1C862270D6ULL, 0x131AB4FBF809AE9BULL, 0xA4A57A3332CF1981ULL, 0x2C378F98E7A351ECULL, 
            0xED31B3E0CBDEBC1CULL, 0x8BF71F48B8A2FFDBULL, 0xA93DC7C5AEC27FB6ULL, 0x5CDD334209E9718EULL
        },
        {
            0x8A53E02C07F2A9BAULL, 0xD85EC7F584423BFBULL, 0x92BDBB9C6FD0FCE2ULL, 0xDE6B58C50B4CB0FBULL, 
            0x55247942D5153EB5ULL, 0x5B7228C2AC54BF11ULL, 0x27E84C0CE4B7CE39ULL, 0x05685506A9DCE18CULL, 
            0x26A381433CCC0657ULL, 0x098570FAA5C8E271ULL, 0x942A1ACFAE3853CBULL, 0xD8A03F9B9BB80D79ULL, 
            0xBA2B90D2DBB243F3ULL, 0xEB18331E81B47CAFULL, 0x23B376470FD161C1ULL, 0x55A589FAC501F60CULL, 
            0xA303458C0ADCCF07ULL, 0x4457C8A40AC2D769ULL, 0x48E129C93A3E9731ULL, 0x9198EBDFCC395DE8ULL, 
            0x68F146F4CFF4B703ULL, 0x4091E321B29157D4ULL, 0x0FF9934EFFDE5AA6ULL, 0xFD360E21CDFCBFF6ULL, 
            0x5FE60C3AAE584A84ULL, 0xE13335488E459E94ULL, 0x04EC95E787188660ULL, 0x2C60240C709BF1D8ULL, 
            0x703DF21D3A54F0C0ULL, 0x6225C52A0A082E80ULL, 0x4ABD188F5B98864EULL, 0xBFFF524268AF5CEDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeyRotateAConstants = {
    0x5BAEBBAE3A55B5B8ULL,
    0x32DBE90DB56D975FULL,
    0xCC87D01E4EFCC1A0ULL,
    0x5BAEBBAE3A55B5B8ULL,
    0x32DBE90DB56D975FULL,
    0xCC87D01E4EFCC1A0ULL,
    0x48CD62F5A95954E5ULL,
    0xE925A54065D26D27ULL,
    0xF6,
    0xF0,
    0xAF,
    0x6A,
    0x7E,
    0xF5,
    0xD5,
    0x59
};

const TwistDomainSaltSet TwistExpander_Saiph::kKeyRotateBSalts = {
    {
        {
            0x074671C62FB0C94FULL, 0x5DCEBE3AD76E9161ULL, 0xA05A14FE930F53FDULL, 0xBD6FAEADE078AD1FULL, 
            0x175561022AAE8402ULL, 0xDC2E4217C1599133ULL, 0x9309DBC2802A7284ULL, 0xB579D95C9E4014BFULL, 
            0xA5362F90266F0BBEULL, 0x0BD95BD774FEBDFAULL, 0x9CF43FB32BFEB9D6ULL, 0xBC2E7F53280B7E82ULL, 
            0xB325F65EC824993FULL, 0xECCF280F6D46C26EULL, 0xDB294061B533559EULL, 0x903D6ED60C7450C4ULL, 
            0xAC71732E2605E5D7ULL, 0x9569D29CE714872AULL, 0x7E46BCE2906FA3AAULL, 0xEA26693FBDD18FB0ULL, 
            0x6B74384DD16F7A0FULL, 0xEFCB307384D76E17ULL, 0xED0E2F56F9AD3623ULL, 0x7BC8774C3EA5BB1EULL, 
            0x6B797CABC9BFDB99ULL, 0x23726A0F0A05E271ULL, 0x1F92ACB329EE7B1BULL, 0x96431F019B96DF9DULL, 
            0x65284D22C7660539ULL, 0x2B090D04C85FEA17ULL, 0xB9D0A5E86A68C808ULL, 0x4898D9D0DA34E3D6ULL
        },
        {
            0x85EFD79B0175E1A9ULL, 0xDB8209C00D1FFC32ULL, 0xAA96733151D47C84ULL, 0x044914689A607F81ULL, 
            0x1497581E2F8FF4ABULL, 0xF6D34A4A04CF31DBULL, 0xC3FD70F987AE1EB6ULL, 0x3632BC916E1148A4ULL, 
            0x89905B322AB903A3ULL, 0x672E26EA0008C7B6ULL, 0xCEED78E964DF2DE5ULL, 0xB20AF3E2424CF4EAULL, 
            0x55BDF1C096B04F02ULL, 0x91F42D183D6B63FDULL, 0xDEF7DA4D82E82395ULL, 0x4CC9A6D9B0820072ULL, 
            0x9F417C2FA8A914D3ULL, 0x11DB44D5512EF5D9ULL, 0x6F1932125FAFDD76ULL, 0x0873BF0BCE34CAECULL, 
            0x850726DD81E204C6ULL, 0xB6F92B737FAB6FFCULL, 0x08CB0E9FFE0C1DBCULL, 0xD8D1122346D46061ULL, 
            0xE60A56DEFEADB809ULL, 0x1B4D07118AB78D38ULL, 0x98F55AF9E82230DEULL, 0x5A1BDF57FCBB8D12ULL, 
            0x0637A3A04E587595ULL, 0x2B1343194EF17064ULL, 0xDC169432E0224B5BULL, 0x0F3A81DC5736F91FULL
        },
        {
            0x539B92A62CD2897AULL, 0x339DA174A74274B9ULL, 0x564C6C89A7DA7250ULL, 0x6C8310BF44B8ABEDULL, 
            0x940DE1B03D8020C5ULL, 0xC410EA325DD2CEAAULL, 0x08D5D7B4E88F2EFAULL, 0x1739BDD161729846ULL, 
            0xD1243455E325599AULL, 0x10C324D81967C138ULL, 0x72A461842AC89FD9ULL, 0x2B2220FE2BF4AD03ULL, 
            0x83762A76F37F6BDFULL, 0x13F3DB9648E69156ULL, 0x2472A8D2BBDF7BD8ULL, 0x8AE0D085A6F2B8FCULL, 
            0xCB7F0782B1EE93ADULL, 0x0F8EB2262074C1C5ULL, 0x16B93FFF1C4C325EULL, 0x65D0161F459C8332ULL, 
            0xC8476C4636C8DE9BULL, 0x9170CF2496BDC111ULL, 0x3D53A7D18DCE951BULL, 0xAA26DE9FF5EAAD72ULL, 
            0x39EE7C8070AB5F90ULL, 0x6D5D4FFA3D693684ULL, 0x6AAD0D635E1B9DC5ULL, 0xED4A0AE0A5DEA741ULL, 
            0x0378D44224F47112ULL, 0xA2F2A185A96FF184ULL, 0xB74A78578DD19BFFULL, 0x3B7073268D1A9991ULL
        },
        {
            0xEA9971151B482779ULL, 0x9FFD792AA4D4DCF4ULL, 0x321BCB6D4E630E92ULL, 0x57C87EFF28D404EFULL, 
            0x1EF2EC4F7B839EEBULL, 0xB8683AF71517E35AULL, 0x34CD8CB105DC00C6ULL, 0xAB95D3EF43B6421EULL, 
            0xDDED8D76A54E223DULL, 0x6DC30DD3CC065E14ULL, 0x4D816EBD1EE558CBULL, 0xA73C01E0F9A51679ULL, 
            0x4E9E0289BA12F0B9ULL, 0x23AF636F94207304ULL, 0x1EC520F617C124ADULL, 0xB7F5A334B5E863BCULL, 
            0x0227676FA7AD5840ULL, 0x44C588C18228D498ULL, 0x2A5001EDC185B02FULL, 0xB62B16D40EDC78B2ULL, 
            0x804D0AE9DE84BB13ULL, 0x793E4048E3ADD51EULL, 0x9B64F64F61D90B5CULL, 0x41D07F8A834932D9ULL, 
            0x0EA0717EBA7FBD44ULL, 0x7889CF804255D8DEULL, 0xD4C54B71E67B94C3ULL, 0x063B1B26F098EE66ULL, 
            0xE358D66EEABBEE7DULL, 0x7D5E8D4E95F58F80ULL, 0x12B58E21BE6E758AULL, 0x3AAD04298227BCFBULL
        },
        {
            0x5962012533BE8F74ULL, 0x51775CAC1F63F4D5ULL, 0x3B0420B3EFD19969ULL, 0x9F02D7EBD23C7B0CULL, 
            0xC4915001F4A34E96ULL, 0x8C624025EA762237ULL, 0x1E96A714819A3B33ULL, 0xA682A231D02C1B5FULL, 
            0x78ACE39D1E7062D6ULL, 0x79E0EB99CDF2C89DULL, 0x8B39B4E43768E09BULL, 0xE91055817D2851F1ULL, 
            0x1A15B6E08597CCD4ULL, 0x9AFC388F18C7BEDFULL, 0xCADFC3359319E9B0ULL, 0x8199A8A9FB40B109ULL, 
            0x2F3D8071A51ADFEBULL, 0x9E995D800E4D38B9ULL, 0x71E72FBAB640CBE2ULL, 0xC514EF232885B734ULL, 
            0x65BC839DD380CCA3ULL, 0xC52462BE4E8DE7F5ULL, 0x0F9F274B4D7709D4ULL, 0x406CA84A33913A6EULL, 
            0xC195493851824DDEULL, 0x775E57A12ADD320DULL, 0x645B3214D1CB8AEFULL, 0x691DD05C73934055ULL, 
            0xB916999DAE015EF7ULL, 0x63A4C1E784747869ULL, 0xB3BD1BF25F6CE195ULL, 0x959824AF66082289ULL
        },
        {
            0xF651893798768B16ULL, 0xB0C1C897F869D860ULL, 0x47556AAE81254272ULL, 0xE42EFB41EA9BF647ULL, 
            0x756000839946BBD3ULL, 0x3163C663DD9A421BULL, 0x5F2777A3E5295AB5ULL, 0x8203F65FBCD1800CULL, 
            0x8F1010EE86737003ULL, 0x63B9B18F3A17093CULL, 0x21B3D89DE93B3BBEULL, 0x28D31E8D589AA762ULL, 
            0x0A197A337238D8ACULL, 0xCBEDD5A29F1FB4ECULL, 0xF1923C1D74B3C1A3ULL, 0xEABB28E927129A0BULL, 
            0x97C5E48849CB8D28ULL, 0xC11E48DF99261B48ULL, 0xE9C1134AC69F44C0ULL, 0x2D0FD7FAE5205C86ULL, 
            0x083C2E37BF36B5D5ULL, 0xC67CFCB1E558548EULL, 0x3D5D89D1E72B4B65ULL, 0x00D3C392CC65A1D8ULL, 
            0xB4F4DE6B2000F7A0ULL, 0x32D00BA4CBA94E9FULL, 0xF97FC9DAC17249D1ULL, 0x2A6469E6F7FCD5FEULL, 
            0x1B31258FF4078BC6ULL, 0xC9F4598A823C31DDULL, 0xD1E9CB7EF7529523ULL, 0x983CB405F1E577D3ULL
        }
    },
    {
        {
            0x395F37DA78602300ULL, 0x6DFEE96137F02589ULL, 0x646F1E3065129291ULL, 0x919EDA255F96AC8FULL, 
            0xDDE5C8C4DEF1AA66ULL, 0x97BA74BFC3ED175AULL, 0x67F2A924427001A3ULL, 0x75389C6C54C15293ULL, 
            0x83BCB38E393BE64AULL, 0xA3A2093BA7BAF0C3ULL, 0x08E4420D483E72B9ULL, 0x782700C04ACB576EULL, 
            0x8874E28CABC295F7ULL, 0x051CB8BCDACC7336ULL, 0xE0AA343251CAA7C5ULL, 0xA18F7EA31972E70EULL, 
            0xB44637C8A1B50DF0ULL, 0xC217753E83F443B4ULL, 0xD72284D12E615811ULL, 0x6169F509E4DCF135ULL, 
            0x39832DB512284A69ULL, 0xB5ED71F52568D361ULL, 0xEFDFC622E4A05BB6ULL, 0x17BD3A26C2344518ULL, 
            0x35D4EACA6C059BFDULL, 0x0CD23D3D554A9636ULL, 0x0610D6550C7152D2ULL, 0x93DD45276E51798AULL, 
            0xFC4914F709817068ULL, 0xA282A6774D11A184ULL, 0x8C404A2C9E995628ULL, 0xB159A1298F90A922ULL
        },
        {
            0xC5A322CC32BBCC74ULL, 0x908CA4BCB0128FD8ULL, 0x2864D587E372F136ULL, 0xE4E702FC25632D25ULL, 
            0xBF32381020B08BCBULL, 0xF72F9A1C0E7964BBULL, 0xFF04D82F20E41BCEULL, 0xA92A4C60D81D7293ULL, 
            0x4B977F72843051D4ULL, 0x059F707B3380861FULL, 0x974763E634873B26ULL, 0x21BD475805891596ULL, 
            0xC32767B9261535C7ULL, 0xFAD399662FB0B3E8ULL, 0x420FB247B49603E1ULL, 0x7D878E74E063CB70ULL, 
            0xD7FF73EE472D1A47ULL, 0xC63A812A73A1BDA5ULL, 0x654DD356AA6E55B6ULL, 0x8C3DF06FC770A099ULL, 
            0x241B87763ED6D15EULL, 0xB06572FAB4314B9AULL, 0x2497B1EFD6529675ULL, 0xCD3A4EA407CCC10BULL, 
            0xF5762564C3CCDC96ULL, 0x0D29AFA208F9D615ULL, 0x53D824A4ED720970ULL, 0x6BB41AC1BCB7D95CULL, 
            0x6331E2C2FBBD0519ULL, 0xD2F650F6686B6E16ULL, 0xBBA893AF331C6610ULL, 0x5575F64BFBC34DF2ULL
        },
        {
            0x301ADF065DF7F0E0ULL, 0x61CAB1833DA52952ULL, 0xF16DDC3FF970DC37ULL, 0x31BAC0118B700B98ULL, 
            0x4E7EDBEA456D4A87ULL, 0xA7C7309FFCE40835ULL, 0xBEC84EDF1660CC2AULL, 0xE5A65ECD375DA3E3ULL, 
            0x9F745FD452CF40DEULL, 0xABCF6A771216197FULL, 0xDB88E64EF3F53720ULL, 0xF13545A817CB2327ULL, 
            0x69C1AC34DEC0D70FULL, 0x406D8FDA5A190718ULL, 0xC1C8D7C5AB68E3E1ULL, 0x03F57088EB0421FEULL, 
            0x501B2FC889BC844EULL, 0x59360F6BC670C37DULL, 0x4B860A81BFA4DFF9ULL, 0xA60C0D32986BA7BCULL, 
            0xECC7C5DDA1B10DA6ULL, 0x453D9BA412D67EE3ULL, 0x5ACA2A2683521D57ULL, 0xAC72523CE123834EULL, 
            0xE79D56D99A076FABULL, 0xCA171C7A434D1E31ULL, 0x43D0B39FF45DACE9ULL, 0xA02620C388F5765CULL, 
            0x127989903BC237BFULL, 0x1105E403FA3AD132ULL, 0xFDF8CA449CE5C0CBULL, 0xF63306263355118DULL
        },
        {
            0x1288FC2ADEEB35F1ULL, 0x849C72082903FBE2ULL, 0x45794ECAC657597FULL, 0xB497480F2EFBBF43ULL, 
            0x784B3584BA79840FULL, 0xABD4832D0CA11141ULL, 0x1D51BB28B75F0B87ULL, 0x16F4F72368207C0FULL, 
            0x29AAF659A1AAA232ULL, 0xA8ED7EBE85F6D8FCULL, 0x3858934E670150FDULL, 0x5821EE6E614261B9ULL, 
            0x82643BAE28E1D20DULL, 0xB9669324F5C5C92FULL, 0x95BB757FCBE52009ULL, 0x977DAB2858FAC7AEULL, 
            0xBB0BC489F0863864ULL, 0x673C15212B1CD7E2ULL, 0xCBF5B6FE2854D8F7ULL, 0x3ECA83E33F09D945ULL, 
            0x729422364F518A20ULL, 0xB1EB4CA81C6BAA7DULL, 0xAD742938CF23775AULL, 0x81DF6B5819D070AEULL, 
            0x61CFDC07920188D4ULL, 0x97777396D349AFB6ULL, 0x75FAB33CC6F148F1ULL, 0xEAB3CD7E12702DA1ULL, 
            0x9D407DF5575FCB91ULL, 0x574DA7C7AB06B025ULL, 0xC84047646242FF4AULL, 0x2C9D3632F70319B3ULL
        },
        {
            0xA9628E09A3A655BBULL, 0x03C6E3A7F0643D35ULL, 0xDD6E52C615DA028EULL, 0xD9E2CA37423E7E82ULL, 
            0xFB6DF7F6FAEB32C2ULL, 0x6D15AA7E2A2C4B4CULL, 0x080E296290625438ULL, 0x845A2F223B8B57DBULL, 
            0xD6DB6FB66F6AFB88ULL, 0xCC17BADCEB9962DEULL, 0x322876C06241D94DULL, 0x71F0EF59452557C8ULL, 
            0xBCFDAC294F77B2AEULL, 0x6CE21F1B4D5B34A8ULL, 0x2E6C7EFE919E6F5DULL, 0x64ED36C8B6961FACULL, 
            0xBA0931C47A1D085AULL, 0x00E54CBC0029EFFCULL, 0xD072173C1DF29693ULL, 0xC4B224E10782A956ULL, 
            0x473A187C4365039FULL, 0xBFC68B2D59D11917ULL, 0x747C50AA7189B3DCULL, 0xC97A97E66C231116ULL, 
            0xBF0D4CFFF61256C2ULL, 0xFBAD8DC5B5FC90B7ULL, 0x0939DEF1767A76CFULL, 0xCE1F2E8F30A08C7BULL, 
            0x5D87BD532EBA9008ULL, 0x571797C48C4ED0CAULL, 0x81485117BEDD4B6DULL, 0x06E93FD193BCD948ULL
        },
        {
            0x0EB518B15DF7F138ULL, 0x6F9AB8751155BDB0ULL, 0x99338D6840B7BB04ULL, 0xAA639C506DC0D990ULL, 
            0xEF03C6308ACF8378ULL, 0x91AFE4EA8EF28C8CULL, 0x2D121F7E425BB3B9ULL, 0xB287A0A3C999BA31ULL, 
            0x61BFE360BDD98FE5ULL, 0xFA9BDA886EB1BB69ULL, 0x41BAE45867786292ULL, 0xE47B030F570923DDULL, 
            0x0DC9097362E3E752ULL, 0x64B3E52CB19077A4ULL, 0x69A19C6873C71C72ULL, 0x51019A3D0755B08DULL, 
            0x5214CE2EB7EDA883ULL, 0xF2C85DA44ED33E81ULL, 0x3D380F1785ABBA17ULL, 0xF768A6BF44D64AE8ULL, 
            0xC612C6AE829842F8ULL, 0x4217E2D61F35D350ULL, 0x571386D53BED2874ULL, 0xF8C7272598F69C9FULL, 
            0x8869966F48C89810ULL, 0xE92D08BAB428E684ULL, 0x8CF1801689F91118ULL, 0x0DE7D2DB3C0535A3ULL, 
            0x0BB2DB2A1796CDCEULL, 0x640F019A4D15E681ULL, 0x1096FBB121E0E14BULL, 0x141885244E129501ULL
        }
    },
    {
        {
            0xCDC26A8CA744CF26ULL, 0xAC75C9862F316412ULL, 0x0C0B578136F8F86BULL, 0x3567CA2B3B285991ULL, 
            0xCE9BDAA69FF10795ULL, 0xA4A3276805438E22ULL, 0x38F5BB4DBBBEE877ULL, 0xF45A0312F9E648D2ULL, 
            0x897740777C943466ULL, 0x04C17ADDE08CCA8AULL, 0x889E75D59179940BULL, 0x16036AE1A46A3EC6ULL, 
            0x6291E876EE5378ADULL, 0x33C926DFC68AAD0DULL, 0xF900DC8758519082ULL, 0x455C14E212364DE3ULL, 
            0x1C6FF6411D672310ULL, 0xEC655469351C592CULL, 0xF234A64F9AD3DEC2ULL, 0xAD7B91CF33D19C22ULL, 
            0x56FF8FFD6D699973ULL, 0xF9A928F04A946E8AULL, 0x2040C439D288BBD0ULL, 0x825556D2E6015124ULL, 
            0xB3900CFFED8F5903ULL, 0x8225F8FCCF03B5D3ULL, 0xF00C487F42FAFB77ULL, 0x4ECA3FFB399285E1ULL, 
            0xE86634F98A48643CULL, 0xC54323CFF32DEBFEULL, 0xAED962BD68E03D0CULL, 0x83F380519DF32B15ULL
        },
        {
            0xCC5D6FE8AE03326AULL, 0xDD104ADA8E4ACF34ULL, 0x89703A4D47A94808ULL, 0x9C7CB91BCB8BC692ULL, 
            0x7BFE2D0B7FFED9F2ULL, 0x3601A78196D42874ULL, 0x941C58A3733DC461ULL, 0x0BFCC717FE1CC0B9ULL, 
            0x40BB18CEE2BFEA09ULL, 0x887C1A85F28C1C5BULL, 0x168FE442257725A1ULL, 0x25224F0C4573FB40ULL, 
            0x1C15B4DB047883C1ULL, 0xDB864E933BE4E6B0ULL, 0xDCE3A323B6F4123AULL, 0x3D51D06CF9DBCB82ULL, 
            0x0A7BD4A55522689BULL, 0xBF247867E313FD63ULL, 0x6E6425F5F0816438ULL, 0x536495454A2EFE07ULL, 
            0xACA311867B227EF8ULL, 0x3456D98640FEF55DULL, 0x23B5C8453CDF3802ULL, 0xA3610D06AAB43B79ULL, 
            0x6BA867360E75D48FULL, 0xB381BF047052F1CBULL, 0x60BEEAEDD26F8DD2ULL, 0xF650017ADE25BE37ULL, 
            0xA49D28A8AE632686ULL, 0xFC3FBFB2F2136F65ULL, 0x81A979850CCA03F8ULL, 0x857E1975148148B9ULL
        },
        {
            0x3E153B9B0B8C335BULL, 0x9104C665A3129532ULL, 0xCA2D1066712D6698ULL, 0xE2321E976E25D1A4ULL, 
            0x098B724003D149F2ULL, 0x82EBB8D569FEA38EULL, 0xBA5189BE0E425A44ULL, 0x111FFC71C47FBC5EULL, 
            0x5D35AA73AE7721C8ULL, 0x4A93ABA81623BD75ULL, 0x09DFB2B427EB689BULL, 0x603757A3E388CB63ULL, 
            0x6B73926B8B795705ULL, 0xF12FD820867C2BBAULL, 0xA2F6956E6EBDEC40ULL, 0x2C635DA29A2CA396ULL, 
            0x6495DA737EB9DB9FULL, 0xD8ED0ED3E58A041CULL, 0x5CD51989C9EA3602ULL, 0x3CD1FBCE9BDDF3D8ULL, 
            0xF5C2D9FED395E130ULL, 0xA47C24564C1123D9ULL, 0xF75649E705E33368ULL, 0xB0B15F49C35B915BULL, 
            0xB7B4286129D64EC9ULL, 0xCC1C798AD3CC0808ULL, 0x45038B3EAF8FBD5BULL, 0x5E70733674CEF71BULL, 
            0x4480C70E3C79FE89ULL, 0xD788D9F5BE185A23ULL, 0x7CD698909CC7DAE6ULL, 0xA6CF8928BE270EF2ULL
        },
        {
            0x7D5135C50C29FF98ULL, 0x93EF6C13022887D4ULL, 0xEC4C6C1800214197ULL, 0xC1842680BCC9D422ULL, 
            0x90C8B163BF8368D2ULL, 0x95CA4AFF457715FCULL, 0xCA679EBC46840E37ULL, 0xA82E510A2CF78373ULL, 
            0x4AA8961AF7CF3C8CULL, 0x79487FA09C6A63CFULL, 0xE5ACD58C00BD2B82ULL, 0xFB63DDAAF79F6739ULL, 
            0x94B23CA32D2F878AULL, 0x83BB150BE34233BAULL, 0x62DEEEBFB0DFAA36ULL, 0x2CE5E0265AA4CBE5ULL, 
            0xEBC67849069BC4EBULL, 0x6586A3AC73CCF994ULL, 0xD52B6CD66A4ADC05ULL, 0x1C0BE8C032491659ULL, 
            0xC0C67856BBCC6991ULL, 0x0B43726287001CFDULL, 0x0E2A7D72CE42406CULL, 0xDD5D1A6800E5724AULL, 
            0x36D7ACAC7C8FA136ULL, 0x7110C8798CFBD390ULL, 0x99D4E50CB0899BFAULL, 0x81F7365D7EECD255ULL, 
            0xC014455F9FA5886AULL, 0xD1717B1931E0D7E8ULL, 0x5AB2BA0C07783FFAULL, 0x39CA44854230C692ULL
        },
        {
            0x2C19CB658BF4AEDEULL, 0xDCCDA86D92841667ULL, 0xA29B79C2AA98C829ULL, 0x74363EA527D8984FULL, 
            0xB03425376EF6D078ULL, 0x17C3707128255C45ULL, 0xFE2147B01504282FULL, 0xF3752ECF3022E637ULL, 
            0xBA242264B2CD1659ULL, 0xB7F824E256D31832ULL, 0x59E4CF254239AE7BULL, 0x3A58ADB602074B37ULL, 
            0xEFA3F5A9E82C511BULL, 0xC9932C12AD557469ULL, 0x8DBB651D247F60C7ULL, 0x54544354D23B0728ULL, 
            0x05493524B5C6BA9CULL, 0xC6B033A96FA98C30ULL, 0x1E9C24372CA4B23DULL, 0x96B0384BE8CD61DAULL, 
            0xAF453666B8C37C10ULL, 0x9140E7396DA9759DULL, 0x1275170CA5E38553ULL, 0x74C59D4F480857D3ULL, 
            0x42FCC7214EB2348DULL, 0x87D14235A1EC42BCULL, 0x98CBF380964E4E3DULL, 0x7D2A4EC55BEEAB5CULL, 
            0xFB737DB96DEF40A4ULL, 0x97B428985E82A982ULL, 0x635DFF8D6D58A9F5ULL, 0xD15D144F05EB326DULL
        },
        {
            0x780701F9EC314167ULL, 0x965B587B74EA0D27ULL, 0xEDF19F3D260B227CULL, 0x099C8A13D1327B67ULL, 
            0xC0775D1315F16172ULL, 0xCB32751F2B245563ULL, 0x38AF95CD32F9B093ULL, 0x34B04E269D951FDDULL, 
            0x2AE13CD0AE0AAE64ULL, 0x1C21580AB6200078ULL, 0x751F20DC43768696ULL, 0xBD68FDCD103C650FULL, 
            0x993AC5E1AE0962FAULL, 0x95C4019753F90A66ULL, 0x66AC446814B45BF6ULL, 0x450C1BE5F41259FDULL, 
            0xB7F36986192C7079ULL, 0xE9C5CB5D3F71ACA1ULL, 0xD865E188BA328198ULL, 0xA1A944DEF12A1275ULL, 
            0x39AE2F5291E083C6ULL, 0x29864039C20E9A14ULL, 0x6998EADA41EBBFE2ULL, 0xB587CF7869C5A837ULL, 
            0x9E687EB61BA327C1ULL, 0xEA675798696FDE2AULL, 0x45B87827F0DC41C7ULL, 0x5D79CE60E2052B03ULL, 
            0x9A6FFD7A553E9104ULL, 0x5220C784C2A0BFC4ULL, 0xE9EE45EBFD7421EAULL, 0x062639F9DBC913B5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeyRotateBConstants = {
    0xD46D15C3E40578B9ULL,
    0x2107FAEF66CC2D8DULL,
    0x217603AEEF8EBF8DULL,
    0xD46D15C3E40578B9ULL,
    0x2107FAEF66CC2D8DULL,
    0x217603AEEF8EBF8DULL,
    0x4B25D70750A919C7ULL,
    0x83DCD72100FB76F0ULL,
    0xDD,
    0x68,
    0xA3,
    0x1C,
    0x90,
    0x63,
    0xA0,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Saiph::kKeySpawnASalts = {
    {
        {
            0x430076A3B63525AFULL, 0x2138A8970EA4F14BULL, 0xD79878635F755AFAULL, 0x6304C65F8508496BULL, 
            0x9DA4C3A6B205954DULL, 0x0D548E61877EC784ULL, 0x61BDB06B9C1E4D7FULL, 0x810DAFAAF0BDFB72ULL, 
            0xD992C6BAFA344140ULL, 0x51EF47A58D76BC33ULL, 0xCF23786FCD454C4AULL, 0x5ED5357950774161ULL, 
            0x3F720B828887D4A2ULL, 0xDB2B3A5416618A97ULL, 0x7BD48C4E5D51DDB1ULL, 0x6E1693F691CAB308ULL, 
            0x9A7912B6ECC48BF7ULL, 0x61707BFE90C78EBAULL, 0xF5D07A43AD97B18FULL, 0x98CBFDFABA5B282FULL, 
            0xE937847B45A771D8ULL, 0xF01C811583F037CCULL, 0x1343D24FF93124CCULL, 0xA15DF9ECDCB0D883ULL, 
            0xC37F44F9ABED1696ULL, 0x19D0E0E41A9298B7ULL, 0x01E171259DB06E14ULL, 0xF3EFCDF533CAE61CULL, 
            0x556043D3F07FCC55ULL, 0x024A8703BCCD57FEULL, 0x80C597795B11F905ULL, 0x672A175B3125F733ULL
        },
        {
            0x4AB6F27B21816C53ULL, 0x7DFF43D6E3870061ULL, 0x758EBE45B3C0CBB2ULL, 0x980CD05EE2EDABDCULL, 
            0x83DFD1E02F6D8466ULL, 0x055660672371C1EFULL, 0xDB89C2627D2F2BDBULL, 0x857A0167508D3C8CULL, 
            0x8925F883EACA6D88ULL, 0xB6FF29DDEFF379B9ULL, 0xD920380E18261478ULL, 0x8F6951C8BF123FDBULL, 
            0x17D6208C2405E768ULL, 0x7209B882F6FBD6C4ULL, 0x5C8BDC30F598B6FDULL, 0xBF629A8CDAC1CEBFULL, 
            0x73B00CDBCB6F6B7FULL, 0x5DA171B12749D6A7ULL, 0x7B08DA2ABC626082ULL, 0x8B709DC8E75F1751ULL, 
            0x6C4997E667248261ULL, 0x1746C888823B6B6CULL, 0xDF6E3BBC58ADB180ULL, 0x250ACA4326F9ADD7ULL, 
            0xACA164C1646C8DD5ULL, 0xCB4056B5008A7044ULL, 0x7D344B7252BF42B1ULL, 0x00AB80863B5FABBFULL, 
            0x87C97BCC1715569FULL, 0x51E8FF2FD7200A83ULL, 0x3441C38C973B3849ULL, 0x503F444DEC678A50ULL
        },
        {
            0xE1985E6E85E08028ULL, 0x859C3E6C7AEFA421ULL, 0x0B6329943EADB895ULL, 0x2BF67D34729044A5ULL, 
            0xBFA959BC5F0A91A0ULL, 0xBB42BB61BFFE1064ULL, 0xDFC29B28F2518799ULL, 0xB63A52348832C32AULL, 
            0xAB7B9AAFE4E5524CULL, 0x6F7EA05093E03662ULL, 0x069A2561C6AE8EFDULL, 0x1B13FB74FA3C90B5ULL, 
            0xB34DF42136691032ULL, 0x7CF9BB22F5C55F76ULL, 0xB85E43235C29971EULL, 0xE691FC08C130D0CBULL, 
            0x7DC0F73B1CE25B1CULL, 0x982F6E9B61229BECULL, 0x312A93AE53FDCCEAULL, 0x5A0D7EBB97C7C840ULL, 
            0x261E4F3696B7EEB4ULL, 0xF920A1BC93C1D8AEULL, 0x079DC0F1C8FA88E5ULL, 0x6FE2408DF5871BDCULL, 
            0xC9B7654525DF7BECULL, 0xB2C78DBE515AD31BULL, 0xA779F46EBF18B414ULL, 0x2EE4873EE0C08601ULL, 
            0xF440A3424D77A5DDULL, 0x3545F087C8A3F14EULL, 0xF71265A7BDE1017CULL, 0x96B62236FAFBD3F1ULL
        },
        {
            0xF0003270E05E2D5AULL, 0x859797082D63AB48ULL, 0xBF8AB2E47336DF6BULL, 0x6CEDE46F85AC3BCAULL, 
            0x9E129DD98084B5F1ULL, 0xF4F679AC40031202ULL, 0x969F1DC6EC69BAE0ULL, 0x02E97A2DA3E02682ULL, 
            0xF22323160449D743ULL, 0xEF83D899C3CEB308ULL, 0x4287C27A292738EBULL, 0x393BC1A6EDB152E9ULL, 
            0x5914E896A99D28B7ULL, 0x780FD5629E1D7264ULL, 0x59E4BA25BB9A9D50ULL, 0x7E51C7B8A396FA62ULL, 
            0x1F5BD2EB2A7B8E7DULL, 0xEE82B51163A2FA40ULL, 0x36FB760889A1D3DCULL, 0xD708132AAC3FAFC3ULL, 
            0x8A731AC0D4252388ULL, 0x886F5E4675C9F1ABULL, 0xAC4602F16A1593B3ULL, 0xF3F207D9A84C0D4DULL, 
            0x4B630971BD89426BULL, 0x8982EE9645BD06BDULL, 0x929120482777DA06ULL, 0xAA231F7E5062408CULL, 
            0x7C3D7C6A4C321360ULL, 0xD4A9BF8386C6FBDAULL, 0x7F0EB674203CAAC3ULL, 0x9D4004D9205D807CULL
        },
        {
            0xEEEB02099B5D2A73ULL, 0xCF1D46EE1AF6AFBAULL, 0x350DE3E4655E5F43ULL, 0xDD87D91C7F0A0D81ULL, 
            0x708D9EF3EEAD453FULL, 0x855318D2CAC8D7BDULL, 0x898E09F385B4B7F9ULL, 0x19EDB50F684EAB33ULL, 
            0x1C129152A2EE75A0ULL, 0xADCBF2712340789BULL, 0xE063A1652D9C119FULL, 0x67E7DC92BB9EF874ULL, 
            0xA27862E183B0ADECULL, 0x0D0851D0C2AE1F33ULL, 0xE7820620D66CF99FULL, 0xC3D4DF6B750A9C1AULL, 
            0x7077DC4323A9D054ULL, 0xB275B9EB7FB8BC6EULL, 0x02639B63311D7A22ULL, 0x60A2DF6CC6D3B4C6ULL, 
            0x0389BFD06C700AC0ULL, 0x43324A54C7880AC8ULL, 0xFA6C22A5EA718EBFULL, 0xCD74BA4132E412E8ULL, 
            0x853A030361530EC1ULL, 0xC01FDACBEF1A3808ULL, 0xDEBA120587534B4AULL, 0x03F3E7C98EC3733EULL, 
            0x7501D36C6AE53026ULL, 0x4C8E9B7E88766D1FULL, 0x92548FEA3D5BF170ULL, 0x5EDFE4D67362B34BULL
        },
        {
            0x6D7D06D38586C22AULL, 0x5D0C5176E2FC4F20ULL, 0x71AC31FEE3015BC7ULL, 0xB810ABAE01B69264ULL, 
            0x92573A935525F8E4ULL, 0xBFD36BA49C8BC691ULL, 0x5A254D52CC7A5C49ULL, 0xDA45C772F81C893DULL, 
            0x997C1043D1020FB7ULL, 0xFB79D1FE96D19D34ULL, 0xB0C67B5D6EB035E2ULL, 0xAA5CC8A8959B4BA8ULL, 
            0x41FD85337F44581FULL, 0x2F5185E8D9C868C9ULL, 0xE96663F97AAB387DULL, 0x690A6915F735B336ULL, 
            0x298B3AF8EC4C7541ULL, 0x3FFD38EFDC73438EULL, 0x75556A18094C3CE0ULL, 0x8A58204756653D2DULL, 
            0x6630A371173F8337ULL, 0x21AC5384DBB87558ULL, 0xCC577DA3952654CFULL, 0x53EC2589C639A70EULL, 
            0x708AB3558E1EB62EULL, 0x06FA8E20B3CD40F6ULL, 0x5ED8ACF4022BC7C0ULL, 0x1CE9EF96A05B5A04ULL, 
            0x137C60CF0CD79871ULL, 0xFA29CDC3C68372EEULL, 0x8DCFBAD32A896C46ULL, 0xD68212021E4D8615ULL
        }
    },
    {
        {
            0x8322586A83A591EBULL, 0xFAE8AB963B3EE9B3ULL, 0x67F9B411635F2E81ULL, 0x9490BE0829175B11ULL, 
            0x907DFEAF7A9888BCULL, 0x37B75155D171F68CULL, 0xACF80CF6A6DF9ECEULL, 0x1B648AFCE5D7E695ULL, 
            0xE5A862768217FC37ULL, 0x4256FE0E4945BE32ULL, 0x961C3B7EE2C84D20ULL, 0xC024B200AA4F1BEFULL, 
            0xF065C98E875C47F4ULL, 0xE8F86F057B1C0D91ULL, 0x85B92562C5A61B02ULL, 0x1229D836644F704DULL, 
            0x04A92EC6D25D8DC2ULL, 0x62B87AD6B6DCA43EULL, 0xEE6EBD4B05F93BC4ULL, 0x45B3FEA304575818ULL, 
            0x2A1EEF0BBDAC7CB1ULL, 0x3A08114D19500134ULL, 0x906D33616A9631D5ULL, 0x386498D3C7E3BC0DULL, 
            0x07DB931F08A3C7B9ULL, 0x596210ACB2959CF4ULL, 0x314A868243FE856EULL, 0xB9249A71A03A1640ULL, 
            0x30F84AD5BEE606ACULL, 0x540DEFF5BF525354ULL, 0x2C828FF0BE286755ULL, 0xBA51E38A2A5AC681ULL
        },
        {
            0xF8FEF8FE9DA13A70ULL, 0x9F54D1BEDB47B355ULL, 0x2191074F7CB3738DULL, 0xF2F114E7D68D4AA8ULL, 
            0x94AB9BE5C94E9E3FULL, 0xC7DAA492607EE6CDULL, 0xF4E91E5E6D56D04FULL, 0xDD234EB75044EBBCULL, 
            0x813CE3D8AAFB40C0ULL, 0x57BA6FDA577F767BULL, 0xB028C7C525568935ULL, 0x1EC059D1A2ACED55ULL, 
            0x6453A55E5F028581ULL, 0xD98E11CEAC083698ULL, 0x365C1772FCEE68B2ULL, 0x9143D6EF79236B40ULL, 
            0xABE5154386429D88ULL, 0xC9929B866E410963ULL, 0x9E295BC69E26E662ULL, 0x7E3FCEE2D423D143ULL, 
            0x26E0DFBDBBEE782CULL, 0x7871DE3F8DE867F1ULL, 0x2790E4448A2F310AULL, 0xE05F2E1BF4E041D7ULL, 
            0x9E8BE42233403C38ULL, 0x2E0FD1FF3E5193DEULL, 0x59877F5EBD5CA14DULL, 0x1035F64A1226B398ULL, 
            0xB239231C019BCBA7ULL, 0xDE96F422D4C73CB0ULL, 0x896F8E1BF4F5E67FULL, 0xE9856194CBCEA3ABULL
        },
        {
            0xB0C3F16137BD92D9ULL, 0xFA061B9E08DF13E5ULL, 0x935AA4CAB71F27B4ULL, 0x2ABD08DEDCCE48A2ULL, 
            0x2C52C0EFADCDF381ULL, 0xC6D20240D58EDFC4ULL, 0x58073FC4633F011EULL, 0xE866B1057EAE7EEBULL, 
            0xC8E14B1EEEA4D6FEULL, 0x35756A9A6408E27EULL, 0xF8CC5654791CBB8DULL, 0x5FACDDD0EFD36FDEULL, 
            0x8D26327B84DF505FULL, 0xC145BEC1A2F08166ULL, 0x606E9FE70CDF3C78ULL, 0xE3C454ED2422CD6CULL, 
            0x4F1CE8F3733275BCULL, 0x0771B8A62F2A4C87ULL, 0xC6FE2D7E68DA75D3ULL, 0x4EE1C447F567D1A0ULL, 
            0xCEEB6F988A12092EULL, 0x45316F09A7C8E8E1ULL, 0x6FAC9D472C288756ULL, 0xD8C7F6982D9F408CULL, 
            0x04D2975ACDF6E6EFULL, 0x5E2CB053B5798950ULL, 0x584049F964E95E22ULL, 0xAB7C85C68AEACB55ULL, 
            0x8776EF452A679748ULL, 0xB409B1D4ED9B5B2DULL, 0x10E15F830EB6E351ULL, 0x111D12ED08421B61ULL
        },
        {
            0x5E332934E07D7D75ULL, 0x1CB9FA0903B7C740ULL, 0x2F636820CBC1C21FULL, 0x06F1A52C8F485E25ULL, 
            0x44C80B63DADBB82FULL, 0x463DE1C423D21674ULL, 0x2CE11F3B829EBB6EULL, 0x00FD7CAA75FAC42EULL, 
            0x3F05E7DA3CBEB387ULL, 0xAAB500F660D961B3ULL, 0x4CE5549A2C596DDAULL, 0x1BF03344BE918882ULL, 
            0x61C9241EC30C6DE6ULL, 0x449D5EC41D282588ULL, 0xF40A45492D2A68B0ULL, 0x3C3C7A3C7462D611ULL, 
            0x91B12E45CC927A3DULL, 0xC06C7E0A7A935115ULL, 0x5981C09216E87323ULL, 0x68941DE7930B5CDDULL, 
            0x3F7E9ECCE3FFCDD8ULL, 0xEEFFC459D18BB2F8ULL, 0xE4CF62260300D920ULL, 0xF2355B5A5564BBF7ULL, 
            0xFD4BFEECF6268669ULL, 0x12959E92BC0A7FDDULL, 0xD1C375D597B93670ULL, 0x35D864214F62004FULL, 
            0x5B3E75337C3AA993ULL, 0xDCD3B6FB17CD955EULL, 0x9C1AE51BB0F74069ULL, 0x875F25E024F8EDAEULL
        },
        {
            0xFC6766EE9017AB89ULL, 0xCEFF1B8B05BCDC0AULL, 0x60EE4B640F282980ULL, 0x047EE797FBA8A47CULL, 
            0x31B6D3FF7CE1760BULL, 0x85DEE4A3B468C464ULL, 0x321ADBC2FB3744EBULL, 0x43FD486D070690B4ULL, 
            0x35C592A3EA51725CULL, 0x3BFDFADCF79C3282ULL, 0x432FF3F8EA4E9293ULL, 0x40A20127001854EFULL, 
            0xCDDB290C6C81D7EDULL, 0xBC02817C17F7136AULL, 0x225F73545BA303B3ULL, 0xEEC0A877C47F88AFULL, 
            0x0A9AA85F8418BB03ULL, 0x69E20B5734F9FFFCULL, 0x36C8A3F9D227C4C9ULL, 0x5C70607BACEA4FCFULL, 
            0x9A2DFDAD9398E4FCULL, 0xDF822A5A4563619DULL, 0x6E3B528ADA5D194BULL, 0xD5FFB9A5DCB9BBC2ULL, 
            0xB7E5186AB477B498ULL, 0x8CBCA52FC976FD0CULL, 0x8B8001D7E118CBF3ULL, 0x58518867317C319BULL, 
            0xFBBFF1CF650D05BEULL, 0x15AD1DFE6EDCD515ULL, 0xB8B393C56B0BF9AFULL, 0x6F4CAC82BAA07D1DULL
        },
        {
            0xE6AFCAC16539B9D7ULL, 0xDE793B4F58B15E48ULL, 0xC6DF9C1951E13560ULL, 0x4885AFCC2F673079ULL, 
            0xC0210B191A0F8234ULL, 0x2D74E198D2D28E5EULL, 0x5C2C855854D0D244ULL, 0x2B39B43FB819B252ULL, 
            0x63A8920D19959C9AULL, 0x1C05D1C8B8FBB3A9ULL, 0xF920FB7927E61CCAULL, 0x785CC493E1934E7BULL, 
            0x9EAFB0CD53C85789ULL, 0x38EB3FFAF9AA074FULL, 0x0767AEB5E6BA2E4CULL, 0xC9A9FF1B13BCE6F1ULL, 
            0xB8319160C5DAFDD6ULL, 0xA1D25A1005CBD227ULL, 0x72525CCB4732E07DULL, 0x154096A578787279ULL, 
            0x2DA41CAE6C0BA096ULL, 0x218FD5818166824FULL, 0xCCF27C953D66D7E9ULL, 0xD405A2D34A23E4EDULL, 
            0xEF140CDAAA19075DULL, 0xEA8006725D75B962ULL, 0xC8E29452AD8377DAULL, 0xBA418B8D0CC501BEULL, 
            0xF606E10369E7A4B6ULL, 0x32143CF6CDBF031DULL, 0xF3A126705D2275E4ULL, 0xD329B2E3B744457CULL
        }
    },
    {
        {
            0xC99EA9FE47533BBEULL, 0x270F136D826028BAULL, 0xC93F14453685267EULL, 0xF23C83739F43E0A4ULL, 
            0xF7B8D6B6007FABFFULL, 0x86E1362E6B10F492ULL, 0x6485BA0CEEED1BE1ULL, 0x56908F3F8B6B332DULL, 
            0x5C99978745ABEE42ULL, 0x2D895B2203C332D0ULL, 0xF5C659FBA8054008ULL, 0xE91E55F7322C4110ULL, 
            0x59CC304C1AE9EABAULL, 0xB81DF3EBF68BC951ULL, 0xE71C19CF0AD3F698ULL, 0x863389269D0EB616ULL, 
            0xE80C9FEB1B95DB8FULL, 0xA522D448C5EBC057ULL, 0x2C9D61D99A2DF736ULL, 0xF6595FF2F04D00DCULL, 
            0x4B51817D9C1E1D49ULL, 0x3C36992FD547BE7DULL, 0x6041C78B02393626ULL, 0x58612AD2F4CA3208ULL, 
            0x9A95E084943C2F95ULL, 0x1C42F969EADEE861ULL, 0xE33B5A4A1ECBCB81ULL, 0xD8EF750EEC76F710ULL, 
            0x055A93BAFC8A89B0ULL, 0x2271F952D2C8ABBFULL, 0x477F4C12EBBC7E73ULL, 0xD5470A1091ED9CAFULL
        },
        {
            0xBBBDF4230B367F5FULL, 0xC5EF8FF3F94A8333ULL, 0xDB9D487CDF3D4814ULL, 0x52913A6F3661803FULL, 
            0x98E3463CD01B3DDFULL, 0x4C294A6AC24E9EC3ULL, 0x24A074DAF5AC915DULL, 0x1A9149B4138D129AULL, 
            0x434F3BB9A3A2771DULL, 0x76F5CFB30DD986AAULL, 0xA7942F63CC3A15C4ULL, 0xB5F9A7442B53B27CULL, 
            0xFB301F63248467DFULL, 0xD9B8D9EE3646CFA0ULL, 0x66C9F4CC63BBF938ULL, 0x985FACB0BCF36DB8ULL, 
            0x5A07F832B97995ACULL, 0x264F4A0742D43B26ULL, 0x9ECDF4FA6112CF17ULL, 0xE92AE56F86B8CA39ULL, 
            0x95C2EE53AB211A67ULL, 0x5DC81B19F1F75CA0ULL, 0xE4BD155780F6FDE7ULL, 0x59E8C85D96B94CDEULL, 
            0xE43D6423E0386A4CULL, 0x1A8BD9BA731C5FC0ULL, 0xD70DCA42F2AFD29FULL, 0x8A00D999227F0980ULL, 
            0xEA700AF988613C00ULL, 0xF05730D7B49CCDB3ULL, 0x8D82EC89C3667CD2ULL, 0x0FB7CAE29DB22C34ULL
        },
        {
            0xE89C5B6FE02E85CAULL, 0xFECCFF01104F8281ULL, 0x09AFD242E82128B7ULL, 0x7A1D8626A4706929ULL, 
            0xCC9C68E9382B57B1ULL, 0x3E8DDD4553582E9DULL, 0xCAFEC2BE49FFB44FULL, 0xAD721D1C39681CEBULL, 
            0x4F3E63F2A0DEAE07ULL, 0x885FE2C2493B6EBFULL, 0xD3456B285400BB71ULL, 0x2F4C6F433ECF133FULL, 
            0x8A3A06CB0A1BD12EULL, 0x1F86ED857DE87BC0ULL, 0xAD74E2F3D0AB15AFULL, 0x770D3D22D199925DULL, 
            0x7B67F2F549F3462FULL, 0x6D8CA4F5DCBED725ULL, 0xCC6ABBEF114AAB15ULL, 0x46DAB4DBDA3229D2ULL, 
            0xEC0B57C109A724D7ULL, 0x911A33652CC0130BULL, 0x66A90270AC228AC5ULL, 0x83084D0C8B61D0DEULL, 
            0xD4E619F21A2D7106ULL, 0x2523D7A29C686F35ULL, 0x1221518752F14578ULL, 0xECC79C49AAA59A04ULL, 
            0xEA1DBA734B050E15ULL, 0x0C3D9806BEDEE808ULL, 0xF329E1CEABC0DF06ULL, 0x013F47AEFD103CCBULL
        },
        {
            0x0B875F19CF398348ULL, 0xA9BF1BA28DE2B221ULL, 0xAE8F97A0421A828BULL, 0x4586AF057F03FFD8ULL, 
            0xF0D72990DB7DB914ULL, 0xAA7129814FC75D6BULL, 0x225BAEA782B71402ULL, 0x7FEC9EA84DABD038ULL, 
            0x5D94A740A0E9A8C8ULL, 0xE32EEE1DF68A2385ULL, 0xEFCFBC1543F0431DULL, 0xDCCF0E260B8225A0ULL, 
            0xDE06C82B1CD2EE1CULL, 0xC69309E906FFDCE2ULL, 0x6830114F1E5EA876ULL, 0x3F5A265FBEC35BD5ULL, 
            0xF51710529D160E24ULL, 0x820BB9FECAB2EA26ULL, 0xE54F581278824B90ULL, 0x49AB386E02778AECULL, 
            0xBEC4E5860ED44EB3ULL, 0x26272143007E6A4EULL, 0x550AE4204AB973A2ULL, 0x095FBB69BF86D402ULL, 
            0xFF96CF316027905EULL, 0x61BCCF29069A6EB0ULL, 0x464C190E542F4740ULL, 0x97CBFB83710755E3ULL, 
            0x1C0AEA27757C893BULL, 0xB2FD47B07C8529AAULL, 0xEF4811C4BE8CFDA6ULL, 0x9597DE2F4ABCD8CCULL
        },
        {
            0x65472A211296A869ULL, 0x2906C0AC57F9B94AULL, 0x8FA0B79138F3AD52ULL, 0x95CD3CE8BCF57682ULL, 
            0x84874ACEA8A6DCFDULL, 0x3A5EEC470FBB7E1BULL, 0xA40FE086B40FCC25ULL, 0x47AEF8BC2EB7B1DEULL, 
            0xC707A4D47012EA2EULL, 0x5F3DC8A972222E25ULL, 0x3220CA6961E90A5EULL, 0x3CB3DD53B5266C09ULL, 
            0x1F49465217133815ULL, 0x48A76AB506285168ULL, 0xF5110D1DD8DE91FFULL, 0x85D83445FC0474E5ULL, 
            0x143014F43F578E7AULL, 0x3B28E98A0BFEAB4CULL, 0x4AC56BB97FDB18D0ULL, 0x56A8427AD1ACEDEAULL, 
            0x84606808D887D20CULL, 0xDEE416BD52D944A2ULL, 0xA4F132E305B32B09ULL, 0xEB4C64F2BC3B8837ULL, 
            0xEF6A2661B648689FULL, 0x546E499B8C261639ULL, 0x42503608F28C7418ULL, 0x712968E08466B19DULL, 
            0xB2F7CDC468E07646ULL, 0x7E1BBEFC9B6719D3ULL, 0x2C304011627DEB88ULL, 0x42C5D75A3BE469F7ULL
        },
        {
            0x55C724C0829D3D0AULL, 0x78442BEAE4E2335AULL, 0x1BD5DBDF3FE36690ULL, 0x979BD34EC2AF7A38ULL, 
            0xA52C2B34E75DA37AULL, 0xAA979BF3681A696DULL, 0x193352BB9BE02540ULL, 0xE83DFAC4581205D0ULL, 
            0x82B2882F7A05B686ULL, 0x2FB3319D4E230F70ULL, 0xA25A1B377E895C6AULL, 0x8E854BB326E8DCADULL, 
            0xBE088789602E0AF5ULL, 0x33D1AD78B68E9AFEULL, 0xA12AE9A9D4C66656ULL, 0xA3720BB21F612464ULL, 
            0x27E3328B0A5860B0ULL, 0xD8CB28024FD715C2ULL, 0xC0184E3C51ECF556ULL, 0x2F818ED62DE011BCULL, 
            0xC73A203E94177D73ULL, 0x83F92BE42747C2F4ULL, 0xD81D4C6380BF16C5ULL, 0x7E16F61825FB1413ULL, 
            0x73255AE1C05F79D9ULL, 0x7EEFEA34C60121D3ULL, 0x7182640515774A8EULL, 0x8B0D49220BDB4FACULL, 
            0x301C9FF1393A5233ULL, 0xA8BB8D99A836AD94ULL, 0x8E4A29C7ADBAD047ULL, 0x07C024B85F0E8652ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeySpawnAConstants = {
    0xD3B0AFB0A3106594ULL,
    0x375E303E4418932FULL,
    0x30F7BFB26EF1FC81ULL,
    0xD3B0AFB0A3106594ULL,
    0x375E303E4418932FULL,
    0x30F7BFB26EF1FC81ULL,
    0x1649A19028FC6372ULL,
    0x76FB9FED34FF43A8ULL,
    0xCF,
    0x6E,
    0xFE,
    0x34,
    0x2C,
    0x7C,
    0x71,
    0x1A
};

const TwistDomainSaltSet TwistExpander_Saiph::kKeySpawnBSalts = {
    {
        {
            0x5DAB70CFCD78FBB0ULL, 0x3D2EF163D924982EULL, 0x09D7851DEC0FDCFEULL, 0x50C574ABF85E9E32ULL, 
            0xE1A9FCD389ECEF12ULL, 0x39357195520B324AULL, 0x733FFAD05B711423ULL, 0xE72A2B6D9A4A537FULL, 
            0xD8A601F2EB3E6187ULL, 0x68F93E7D20FF70FFULL, 0x5F29E7326144CAB5ULL, 0xB751561D46545C83ULL, 
            0xE19EA79B19727F98ULL, 0xA09922681F03D5CAULL, 0x10DE03285860958FULL, 0xA1A9787204756CA2ULL, 
            0xEDA732234C04A812ULL, 0xACF0C7F9E6A99626ULL, 0xA58F93379217A48EULL, 0x127BA12D15296F7FULL, 
            0x3B6DB7E9A4F2C604ULL, 0x5F64AD1C737E52BFULL, 0x13698F139D15A41EULL, 0xEF572270491455A8ULL, 
            0xBA681620575C16F8ULL, 0x93B785F64E842C5CULL, 0x4BD9111319F0106DULL, 0x78B9FF16B1B3C850ULL, 
            0xEADE7013299312E9ULL, 0x593B3F28135C2955ULL, 0x71C2AD5869D956B2ULL, 0xFCE4190C9495B66DULL
        },
        {
            0xC17C0AAEA73AB6C2ULL, 0x3656FB254C4770B6ULL, 0xFD004A85D538AFA2ULL, 0x4EB7821AA5472D8EULL, 
            0xE111288CE58B073DULL, 0x4C20C2258F4009E9ULL, 0x3A1AB9879A78CF5EULL, 0x0B60FABA758049AAULL, 
            0xEFA20522DB3CD82EULL, 0x3B5E8D69B0042257ULL, 0x29D789A04E4DA5B4ULL, 0x577400F8670692F0ULL, 
            0xFF2C59EB89A85DBCULL, 0x34E5FEEFDDA5C9A4ULL, 0x6C776DBC3A26E1A5ULL, 0x9CF7C179DD9FB270ULL, 
            0x338F18D81ED5B113ULL, 0xA39CF64B6399CD50ULL, 0x265BFE6CA307C9CFULL, 0xB38B0D581FA8DE2CULL, 
            0x83D4C206F053DDDAULL, 0xAC704031856FB797ULL, 0x2DAEDCB3C50D19FAULL, 0xA83046E1707EAE62ULL, 
            0xB5E2116D81D3ECA8ULL, 0xE2E4CE4625BC5700ULL, 0xDBDAFE9E999A606EULL, 0x181102498C5BBDA4ULL, 
            0x4339343170DA5B5EULL, 0x3D0C5E414A111FB0ULL, 0x1F50B6E871451A6DULL, 0x6002DB39138120FDULL
        },
        {
            0x2CFEABFBF1BBC218ULL, 0xEB6C14387E6A0D62ULL, 0x12D7CE58534125BEULL, 0x69150F21DD562D46ULL, 
            0xDE73457AFB1BA28FULL, 0x2732C1DF61B2BF2FULL, 0x9570C4830A899935ULL, 0x92ED3CB0FDFF6A7DULL, 
            0x7C027003DF273CDFULL, 0x87909F1BC4A72E1DULL, 0xE03865FAD66C3827ULL, 0x4EE2C3955E271F7AULL, 
            0x31B8C7B9B305C892ULL, 0x4FDA5C6086B0ACE1ULL, 0xB07ABAEFCF92CD8DULL, 0xB997F52EE64989E7ULL, 
            0xF37CA306D387F0D1ULL, 0xEAF09C07C579C10AULL, 0xF62DE84A30F7071FULL, 0xA89A2AC73B47F19BULL, 
            0x1BDB516222065105ULL, 0x4DF20FD9FF68A84EULL, 0x00A97749C99AAF9DULL, 0x959CC0E78DB3A7F9ULL, 
            0xE04BE60824E8EEB0ULL, 0x091DCAA3B21D2608ULL, 0xA6B56FFDA7662CB3ULL, 0x853D622BFC263078ULL, 
            0x8D0FC0A368FFF7C9ULL, 0x4875E88AE0513ADCULL, 0x4560A2F250BFDA2AULL, 0x0EF7BC9479297F5EULL
        },
        {
            0x1201C36AD67255E8ULL, 0x57971DC419046446ULL, 0x969F8D01BF24F919ULL, 0xB1C3B944A2D4DBD4ULL, 
            0x60F81AF20BFB31FBULL, 0x4CEF566D70A63B6AULL, 0xE416799E2DAA00EAULL, 0x0C810C09957A2B57ULL, 
            0x109647DB7D5E2AE4ULL, 0x04E35C9ABC0AFA5CULL, 0x56D951424E17457CULL, 0x59DAD98008082527ULL, 
            0x77218F592C8DC6F2ULL, 0x415784B26924DBFCULL, 0x5275EF69B6544BA4ULL, 0x0836685E7703E1C4ULL, 
            0xB56BB6A47709ED7DULL, 0xE9446ED5AF73C356ULL, 0x47D32D776B63DB84ULL, 0xE10561BE2523DCDCULL, 
            0x76D2A3999C1B02DDULL, 0xA0183249F606B7C6ULL, 0x3D9F44E9BCAE7CEBULL, 0xF26C58F4769CE55CULL, 
            0x0252B1E6B38199FDULL, 0xBA92CD808ED5969AULL, 0x35A7711DF8F5E5C7ULL, 0xFA77DF7CB9D2042BULL, 
            0x209C8551231EBCC8ULL, 0xF2A24AE07E896A10ULL, 0xEF6E66167CD646D0ULL, 0x45534B6DA7247C72ULL
        },
        {
            0x145D3AFFD74FE5D5ULL, 0x640EEB4E0758A509ULL, 0xB89BD36168291B52ULL, 0xBBD20621DC9526EDULL, 
            0xBFEB9644809F11CFULL, 0x2C4A1E63D654F01CULL, 0xFF715E28415B2334ULL, 0xCAA41FD26BDF88F0ULL, 
            0xED87523A5E4F2BCDULL, 0x8266BE4838268381ULL, 0x9E660DEB4F07988CULL, 0x0672EE0C84010FA3ULL, 
            0x63658336E9E766AAULL, 0xCD0128385B19520BULL, 0xF3754C4D1E3405AEULL, 0x02350A3D8C4C9948ULL, 
            0xC828F789B5907797ULL, 0x92DA9C95A07170F4ULL, 0xD7AC88B98A90EF85ULL, 0x0CEFBE26F5F671D0ULL, 
            0x455409FAA65CCDAFULL, 0x20DD1E66C466438FULL, 0x6BC99CE86F61175BULL, 0x0E9A5FBA59F1CD2BULL, 
            0x96561D58AD8E0869ULL, 0xB3910C9F88DBF1D3ULL, 0x479771FB5D07B57BULL, 0x2EAED578498403E9ULL, 
            0x5BADBEBE429E48E3ULL, 0x4FD99FF0F278C555ULL, 0x6FAECA041ABAB898ULL, 0x9803681F76CD5D74ULL
        },
        {
            0xD39BA264A804650CULL, 0x91A1DB8B95DE3E22ULL, 0x4666C4FCF225D6A1ULL, 0x69FFFBC613177F06ULL, 
            0x94CE762A55CEFAF3ULL, 0x8C88B684280BDC14ULL, 0x11EA38538F278F39ULL, 0xDBABC9DED41732ECULL, 
            0xF6BF12734D513D67ULL, 0x5A468B3C3C21ECFFULL, 0x11981C64E6E2049EULL, 0xF5F261690F416273ULL, 
            0xFC203D53B37295E6ULL, 0xF14237C37BC3CD13ULL, 0x1EEEBD136794DC7AULL, 0x733E0E4DBBC8C29AULL, 
            0x9D13D3414DD0ED5EULL, 0xCFB27D63D098A162ULL, 0x85DCEAC1FBE6C93FULL, 0x8EAE51DD58498EB2ULL, 
            0xEE94556A0EDEFB4EULL, 0x2C7DB81AFD6F9AD6ULL, 0x527287960BCF9B3BULL, 0x07FCD4227F418CF6ULL, 
            0x7862C57AFCF776ECULL, 0x4FC67BF828E904C9ULL, 0xE7CBEA31E22C839AULL, 0xCD6C23DCC3ED14DBULL, 
            0xFFDBF46F10EC8A1DULL, 0xEC030DC606CCB8EDULL, 0xC7AD867E87A84531ULL, 0x505FD9762E4528C5ULL
        }
    },
    {
        {
            0x91C7567E1F2C6556ULL, 0x8877A9B07751FE6CULL, 0xC4E36EE327683A47ULL, 0xFE181769F6C7F821ULL, 
            0x417C21163AA42239ULL, 0x69B4B1AF59B96D72ULL, 0x14AA283E0880F0A8ULL, 0x66C9CB1D3652F419ULL, 
            0xDC680EA6949F65C5ULL, 0xE1E6B4B57A37AC01ULL, 0x13F09D6272383B51ULL, 0xAA447F37838FDA56ULL, 
            0x33FB5FE8E0A76699ULL, 0x2AEFB8465C6C4354ULL, 0x95ADE44E38C60323ULL, 0xE187A65D2BF68B48ULL, 
            0x1957F7A91FE4EE3BULL, 0x70D0F54F0191BFB2ULL, 0xFA3215E9DCE7825CULL, 0x70C58032050CE613ULL, 
            0x1DFF239AF445A67BULL, 0xEF1F01472F032BC1ULL, 0xC78243C4DD406A2BULL, 0xE65605508B109892ULL, 
            0x5D1951469FE35068ULL, 0xB4EB513EF6CF1A54ULL, 0x3EE4FAD2186E73C7ULL, 0x90A9E45797BC7D43ULL, 
            0x5B89B950D9668CAEULL, 0x9A1A451F2034F93CULL, 0x95ADF6607233CA3CULL, 0xEAB571EBD2BCBC5BULL
        },
        {
            0xE571A20E9BA5C6E5ULL, 0xD1F72E1C762528DCULL, 0x11D4851D82B42D52ULL, 0x87D3EE847E83F291ULL, 
            0x208BE233F16A4806ULL, 0xFC7BBA0DFDC910C1ULL, 0xCCF0DDCFA562FCE1ULL, 0x6BDFFA40A5EB60C1ULL, 
            0x114A981DEEAE02E1ULL, 0x22BBADD935CDF902ULL, 0x21B6D5E0345EBF33ULL, 0x4A32485922A1844AULL, 
            0x54645DF0AA701932ULL, 0x24F08599F37A7D3CULL, 0xAB8ACD21F48C8E50ULL, 0x5DE5172DD398BD76ULL, 
            0xB01A21878D4C363BULL, 0xE268A03124F57922ULL, 0x3171A826D514D036ULL, 0xFCF4CB9CC0AACAF6ULL, 
            0xE781E6860A5B3998ULL, 0x70BC2FD6489ECF4FULL, 0x37FDD85218FAAD36ULL, 0x43F3DDDE78CACDEAULL, 
            0xEF0A9F19A511BECFULL, 0x3380B2533E5D84B1ULL, 0x0FDB823E31E0B2A3ULL, 0x5D5613C1F19EFB08ULL, 
            0x8E0658AAE226A72EULL, 0x223985EB0BB415C5ULL, 0xFDBCECA6D51FEBF3ULL, 0x593D1A875DD33799ULL
        },
        {
            0xC37C06CB0F3EACF8ULL, 0xEE2325D3A92940C9ULL, 0xDA3A6B489096BC48ULL, 0xC222B1C8C00680F1ULL, 
            0x761B390AB0F117A7ULL, 0x2805D3A5F0351A3DULL, 0x12D3DBF8782C1363ULL, 0x07B1E498998319DDULL, 
            0xB6BBF1021A14E451ULL, 0xC3547E363BFC29C1ULL, 0xFF49849DD4FEDBDFULL, 0x1254C3319E767BCFULL, 
            0xCA8F5C74BAFD82F6ULL, 0x4C2DAFA5AEF7C549ULL, 0xEE420CBC63454051ULL, 0xBABBCCEB7F1970D9ULL, 
            0xDD16FA42A8C8FA0AULL, 0x59D7E57D2F0CF194ULL, 0xB19F57F348B4B0D0ULL, 0xB2B814C7796101CFULL, 
            0x329491B2784FA6F8ULL, 0x7886E05A6CFCD673ULL, 0x924EECC9237F5FA9ULL, 0x62BB61AD9890FAEFULL, 
            0x8E01CB1E399B0213ULL, 0x8D5CCE5F78853E86ULL, 0xBCBFABCFC0BDB80AULL, 0x4063F7994F1155A4ULL, 
            0x4D1E5E2440AAD464ULL, 0x3C37A4E174F69D65ULL, 0x1123A5F9978D32B0ULL, 0x2F684D97F05E7482ULL
        },
        {
            0x70151FC7C27D3FF8ULL, 0x50B8556D264BF5DBULL, 0x9A7EB264920D7154ULL, 0x20CBE04FE53662EBULL, 
            0x55B99595C9C2A86BULL, 0xEFD4934E4532DC6EULL, 0x88F05A0BB1FAFFF1ULL, 0xE5A287EFBED6E926ULL, 
            0x54C4D8B26C7D8C83ULL, 0xF42222A3340257E6ULL, 0x2A39C2D017B59074ULL, 0xFF087AA8C088197CULL, 
            0xC6D7EDEEAC1F86FEULL, 0xA407864077F380B0ULL, 0xF34C5EA5DA06B2BFULL, 0xB9D5394AB8346CB7ULL, 
            0x23CFD55E75192FEEULL, 0x88CA37AEB6C83D13ULL, 0xAC34CA80A51A67A7ULL, 0x67FBAB7A5CC3AD0FULL, 
            0x3243BB05F0238971ULL, 0xD5425AF95DEA2E86ULL, 0xD72C7072B7687A66ULL, 0x7C3BDA8972E024ACULL, 
            0xDDAF21A45F380B50ULL, 0xEE4772E08B9FF63CULL, 0x4DA6F98E2D0942D6ULL, 0x759FF5BB8A3ACA48ULL, 
            0x54ED920BBDC66EDDULL, 0x324C03F97D14E3E9ULL, 0x956FF97CC3CE7669ULL, 0x37C5F0E3DB263AA5ULL
        },
        {
            0x85237335CE39A8B8ULL, 0x9AD077CF16C6580FULL, 0x8DA6B1B22C75A30BULL, 0xD5A371F261978412ULL, 
            0x12D9B95C4335F491ULL, 0x845CA459E454542FULL, 0x63AB19405B56C3A2ULL, 0x7D5536D67C02A747ULL, 
            0x4CC56F2960959920ULL, 0x5050FCCF849C5747ULL, 0xC53F8DB788179E04ULL, 0x5ABB93CBB59F7AFEULL, 
            0x6692F5A6CF921C43ULL, 0xA816C07032639179ULL, 0x546B874F47D57F70ULL, 0x35B724D950E35AC5ULL, 
            0xDEB1095A857A8D1BULL, 0x79B7B9FE25862E71ULL, 0x5CEB9F46E38669F7ULL, 0x3B1F78812A6086EBULL, 
            0xBECB90997834A558ULL, 0xCBB945104093C753ULL, 0xAC265074CB9DB7E8ULL, 0x7164397E8077C14AULL, 
            0xABA032939F2583DAULL, 0xD58FEB2545A6780FULL, 0xFC807FCEB365EB3EULL, 0xD85E435CC9855DD8ULL, 
            0x86B965C52BC3C63CULL, 0x1DE6936B7C31C0D6ULL, 0x9A654AA45F54D51FULL, 0xD59441E33D5207A9ULL
        },
        {
            0x2548DD783B9341CCULL, 0xFAC17C2100B15032ULL, 0x0F1DEC056AA5E0DCULL, 0x88B550B7827AC6FBULL, 
            0xCF9F4D307E8C1327ULL, 0x15781D3B07095D42ULL, 0xE93DB0F461D5ABF7ULL, 0xA256C855BBD1F664ULL, 
            0x0244607728EFBD26ULL, 0xFAF8B1FFFEF9ABD8ULL, 0xF01C3C92FCDB8F5AULL, 0xCC8E0F784E3A5CDFULL, 
            0xEA1285CFE754B352ULL, 0xE3EBEB978BF2BA54ULL, 0x68915F3CED9A45CFULL, 0xAD60527CFF2B5785ULL, 
            0x4BAD95923BADFF0EULL, 0x8964E4B4BD01F1BCULL, 0xA760F4F3A8E43049ULL, 0x194BC740DF748107ULL, 
            0xE88EF9C5FCA3EB87ULL, 0xECAB75682145010DULL, 0x682575830E072976ULL, 0x6A2EEDE71E474C59ULL, 
            0xC0EC0E61787DE8C6ULL, 0xD48AE3657174F51BULL, 0x0E1649A81EDB3C08ULL, 0x0404C75E40CA2F08ULL, 
            0xD5DC772AA29DACE2ULL, 0x51A3C5FA51864B2EULL, 0x02C9BD7528EBC70DULL, 0xE56F42809F62C41BULL
        }
    },
    {
        {
            0xC991E4F2A4C87D4AULL, 0x1CF03A5BF9547AD3ULL, 0xAD295E0BD83B4CC1ULL, 0xBA40583A1B391EB5ULL, 
            0xD79EDBBBB48F3BEDULL, 0xD1E37D9B9A991076ULL, 0x26EDF32FCE8389DBULL, 0xFEAA9B922E08EF21ULL, 
            0x8A7CF9AA1BC7EE16ULL, 0xCCB2A2B6D72FFC32ULL, 0x5561B7239E415F01ULL, 0xB245CFCC6DB70634ULL, 
            0x4C409C19B451FDECULL, 0x06159CD48B0F86E4ULL, 0xDA0048BCF80943E8ULL, 0xECDF74279AC72F0CULL, 
            0xA149DBE4BD9FEB73ULL, 0x0D56DBAB88B39711ULL, 0x98662F1CEF0C82EBULL, 0xE09FFC07D044D03AULL, 
            0x79F31DB2BF2AADAFULL, 0x876BD1E425F004B3ULL, 0x2FAE28BD557606DFULL, 0xD04C4D7413189BDCULL, 
            0x2F682D721235BA59ULL, 0xB82A6FE38654B1E3ULL, 0x6C8CB12D7227BCFAULL, 0x4EFF621046226BBFULL, 
            0xC96732F1C0CA7C8CULL, 0xFEA7ECF3509F74DDULL, 0xDCD6B8C1CEA7FCA2ULL, 0xC388A4912F6AA1B9ULL
        },
        {
            0xA1824881F4276C80ULL, 0xD5882FFDF38D539EULL, 0xE822C8284398FE81ULL, 0x6C351CE5342938CBULL, 
            0x9C075A180AE11FD8ULL, 0x50DE3CB8BB3F380FULL, 0xCF9264F2E2678B8FULL, 0xAEF22CCCDC3894D1ULL, 
            0x43D4B66B6EF3EC1EULL, 0xBC24944FD5878B89ULL, 0x7DA1809D43440EF3ULL, 0x3EF8FEF5DE76A1B8ULL, 
            0x4D5E8521E1E2DEC2ULL, 0x2344A48F7E74D73BULL, 0x03377F628B2CFD28ULL, 0x78C6FE078AF4BA51ULL, 
            0xF750A254E79F4EFBULL, 0x825E61C35EAF364EULL, 0x8ADAC728C238380DULL, 0x4312DA74304A6549ULL, 
            0x7C385FBE141D234CULL, 0x760F08FFB5069A8DULL, 0x2C9A5115F8A470FDULL, 0x71EFE6E92EDA07D2ULL, 
            0xA1D46D1FEEBF054AULL, 0xC42479B0C34C2267ULL, 0xBA718B683637E090ULL, 0x8584AE19ADB9F4F5ULL, 
            0x6169F271A76DCB83ULL, 0xA6E435EE488D7F15ULL, 0x137CF9030B2C598DULL, 0xCB231CB61B9750B2ULL
        },
        {
            0xD8829369CB7F4E7EULL, 0x1DBCC70C5AB842BCULL, 0xF251BE89C20A425DULL, 0x4CE148A1B18A4672ULL, 
            0x59D6CD98710EC9E0ULL, 0x5E7B2BEE05FE0251ULL, 0xCEB66DACA0A6A3F4ULL, 0x9191203E39A552E5ULL, 
            0xAC7127326FDB9CE3ULL, 0xA9D623967F4EE129ULL, 0xE8DFBB64FD60DEC0ULL, 0xC670934AACFC5F9CULL, 
            0xCEA18846CEBF32CDULL, 0x894EE3ADEDB151C1ULL, 0x113188D76FA3D098ULL, 0x4AC28A61ADD72F42ULL, 
            0x59C31FC020DF6B3DULL, 0xBCDC33E43D6C7A1DULL, 0x9587BD78AC032927ULL, 0x8EDF8D8FA968F6D2ULL, 
            0xB593F61903C2E7B4ULL, 0x8B1920882CB7D857ULL, 0x17EA0975AE8B733CULL, 0x43DA41E47A3950B5ULL, 
            0x249189278BBD5057ULL, 0x811750B0F3120FBDULL, 0x844FD401B255449FULL, 0x01B16270D3EE0098ULL, 
            0xD9642943F7EDBA78ULL, 0xCD00374345017C9DULL, 0xC53E9CFAECE7FA1CULL, 0x3E1C26F5C209F860ULL
        },
        {
            0x13F23CEF33458724ULL, 0x22DDD6A2E6A67B5CULL, 0x78789A7F902CF3D0ULL, 0x0DD1F0FB53D623D6ULL, 
            0x76FA33CCCA4F65F7ULL, 0x8BB8B3DC438A9BFCULL, 0xC9F99F138861D6E9ULL, 0xA497B4451BCD6970ULL, 
            0xD52197FC0C4F8A41ULL, 0xA13D123F003B86D7ULL, 0x8DB4001E11C03ED3ULL, 0xE23AAB275EE09CE7ULL, 
            0x0BAB30731C260E3DULL, 0x6DCE7588BB970C97ULL, 0x591F09E447C38BACULL, 0x67DD24B19AEE5E60ULL, 
            0x486E038D63D5DF5BULL, 0x42FCB6A917AB22B7ULL, 0xB819EFED3C1F8F33ULL, 0x12AF1DB1C3E379BDULL, 
            0xAA74410FFBEE8CD9ULL, 0x2244FB31BE88FC9EULL, 0x7F1B246815085E94ULL, 0xB24AB388F7B51C04ULL, 
            0x0AC6FB5A31FE9253ULL, 0xB777CBADC37C5F52ULL, 0x23B2D1173DC4B54AULL, 0xAB583DE141675E30ULL, 
            0xE63A9C54DDDDC4D9ULL, 0x79CC76A1948F2C3BULL, 0x131C9E73B10538D9ULL, 0xABB36A283D18DE02ULL
        },
        {
            0x60868B7864B52315ULL, 0x76DB10FD5221BF8FULL, 0x7D91018B5E617BE9ULL, 0xCEB422B99BC779FBULL, 
            0xDE403A10B4AAF53FULL, 0xEE278CE6FCE596C4ULL, 0xC865737E1FDEC461ULL, 0x5107AAAC111C474BULL, 
            0x0E8A9A66147E9C78ULL, 0x1F5465FCDC3645C4ULL, 0x89B22D3E8955B7F8ULL, 0xA13A1ACCC02211BFULL, 
            0xB5C8869E42CD31FFULL, 0xDD3E0AB3D0749B74ULL, 0xE9703E49965B8F8CULL, 0x2148BA361933FEEBULL, 
            0xB85FA172B432F6C9ULL, 0x736E8EF87C8CAEDDULL, 0xF5C2CD971D0C9228ULL, 0x01515611676D4E5AULL, 
            0xF6A32E985D9E4722ULL, 0xD5ACE43776579356ULL, 0x5E249A06844D8710ULL, 0x5499188846F32ACCULL, 
            0x5B5CE868830A36B4ULL, 0x01C4D8312990394EULL, 0xC2636BBCBC2B7C6BULL, 0x2CD20A86BA15E88AULL, 
            0xA471BCA75B980042ULL, 0x01C1FD2A552A8B3EULL, 0xFFB2EA9DFCDA92D8ULL, 0x0B0D5EA9A47BAEFEULL
        },
        {
            0x09C725791F5FEEBCULL, 0x0F3F099FBFA01048ULL, 0x71A1A5D496CD074EULL, 0x4B7A8E92BECE9F6AULL, 
            0x679AAB6CB6088242ULL, 0x20A998E76B4F4340ULL, 0x5FD7C9861E787681ULL, 0xABDB5945FA151452ULL, 
            0x0EEBAEF33F649D47ULL, 0x85B826AC74E9CBC1ULL, 0x674715EE3960B951ULL, 0x4F1D5E5B426BEED0ULL, 
            0x5007C5EF6F81E412ULL, 0x25933F9B0BCE5725ULL, 0xD4AFB8F99A307D21ULL, 0xFD9E4B08E8E3A6DCULL, 
            0x2D2BE5FFE5B50322ULL, 0xD29C1C9E75164C0AULL, 0xAF8E2B78EC9E278DULL, 0x2917139E970F1247ULL, 
            0x5B6CEBD20A44C423ULL, 0xE2ABCD860EE48669ULL, 0x12677B34EAB3E4D2ULL, 0xD3A7DEC58DDE865EULL, 
            0x8CEE1CCDA815E110ULL, 0x63A3FF3D2B458AA7ULL, 0x59CF8CE7A70EAFCBULL, 0xF2AEDDD6D0E080C6ULL, 
            0x981456D7675F8C15ULL, 0xF1F9A9971F1E811CULL, 0x30A9D59CCE44F086ULL, 0x145795F1871D0DE4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kKeySpawnBConstants = {
    0x0BA9C539D7DBD981ULL,
    0x62D307DE09079E91ULL,
    0x2E40050B106383E2ULL,
    0x0BA9C539D7DBD981ULL,
    0x62D307DE09079E91ULL,
    0x2E40050B106383E2ULL,
    0x8D01DA1E3B1F8D77ULL,
    0x1561484FEF89B790ULL,
    0xFD,
    0x1F,
    0xF2,
    0x5F,
    0x45,
    0xBB,
    0xB0,
    0xB9
};

const TwistDomainSaltSet TwistExpander_Saiph::kSeedSalts = {
    {
        {
            0x06F9FCCC3F4E1957ULL, 0x1858C98D1B8A57C7ULL, 0xB65EE55C65843710ULL, 0x3DC854B421935D33ULL, 
            0xE86A041FF3AB64F1ULL, 0x84F8C9BEA9D98B60ULL, 0x0A02292CEBB75C08ULL, 0x2BF73E37AC9175CCULL, 
            0x8E70D94008D4AC3EULL, 0xCEA2D9879D478033ULL, 0x59E571A84EEF2759ULL, 0x3C60ADCA4603021EULL, 
            0xA40CA5192B07F491ULL, 0x06C5B9CE015CB9E8ULL, 0xEBACC6C21D3BE561ULL, 0x9401A6CD80992366ULL, 
            0x17FB611A899D1F0DULL, 0xF9435576E3A94CD8ULL, 0x36052E227430097CULL, 0x587F5FA269B722A1ULL, 
            0x59EC4FAEFCB5BA9BULL, 0xE3171AF787C8D017ULL, 0x666FB53CE7F5156DULL, 0x0ADBA52CB2C313CAULL, 
            0xDCAB410D1E993C7EULL, 0xD15485E7EDB8832FULL, 0x2251B2E008509756ULL, 0xB089CAFD5E4912BBULL, 
            0x867FE9520B48E39DULL, 0x7C74676B9B90E722ULL, 0xE7C5782BAE99CB5CULL, 0xAFA1382C2EB8078DULL
        },
        {
            0x079C23536013B180ULL, 0x34E71FBE726E5B71ULL, 0xB5A6014F490C3A8CULL, 0x197B2D9A2A11419EULL, 
            0x617FBEDA8A077D77ULL, 0x8EAD82298202A84FULL, 0x5569531EBAB92FB4ULL, 0x60298955B477597DULL, 
            0xF82BE0061B6623B9ULL, 0x8F313BF5FA0F09AAULL, 0xEAE4AEC314F1DF77ULL, 0x825F2AC10AB893A8ULL, 
            0xB3448AA333660CF2ULL, 0xEB3FDD42BE85C807ULL, 0x4771737C068D44A9ULL, 0xDF6E293202D77EDDULL, 
            0xAC82D811BC63BAA2ULL, 0xF156488F8F1B4D14ULL, 0x1DB35BFB8FC2EFE4ULL, 0xDC10C598E144B454ULL, 
            0x5F1F6529AEC89B23ULL, 0x0ECA4A769727A9D5ULL, 0x2A045CF909BAA1D3ULL, 0x8C748EF82493CB00ULL, 
            0x975F90BA666382ADULL, 0x55FE110AB1B973A6ULL, 0x6A5DFB2C95A6636FULL, 0x0A39A559F23C8286ULL, 
            0x0DD0B9BAF1DADC6EULL, 0x7F3DFACCBFC933C1ULL, 0x186CAA4FCEA275E8ULL, 0xC95C1FE2564B6ED3ULL
        },
        {
            0x58B96A465F20895BULL, 0xA1AA7725EE30F94CULL, 0x75A88656769A3C8AULL, 0x8008CB31E7EF5CCDULL, 
            0x519C12B7F8A4B05EULL, 0x831B0CFAAA859996ULL, 0x8B703B051BB1CF2BULL, 0x1A102B9E860282FFULL, 
            0x9E145B46AE6D108EULL, 0x3638C9845CCDEB78ULL, 0x52D3A492FBC08EBCULL, 0x8DEB0FDE0AA09170ULL, 
            0xD793CD79BBFED07FULL, 0xAE27EEF9452C8FD8ULL, 0xCB57E3B20765B2A4ULL, 0xF46B0AA22FC0EC45ULL, 
            0x34B3E82D8AFF651AULL, 0xDB3BA2AFE5000CB7ULL, 0x15FDD2CD8CC3FBEDULL, 0xF70CB5E932F5079CULL, 
            0xDA104066070471FAULL, 0x278A443811E8AAD4ULL, 0xFA41953F85B151ACULL, 0xD1D6D325A10C4392ULL, 
            0xFF445A65670AC858ULL, 0xE5C240E0C585426FULL, 0x006569DBAEDF558EULL, 0x5BB713523CC0B192ULL, 
            0x14043CAF80F4BF4EULL, 0x7CA471A19C13854CULL, 0x1ED5D9B99BC64535ULL, 0x5B9CF069FA53E8D0ULL
        },
        {
            0x64E67EADF85F77C2ULL, 0x83ADC4D34091D2D2ULL, 0x21D4F437FF27CDB2ULL, 0xF73CAF9517121B1AULL, 
            0xED9A3C980F62927AULL, 0x2CBDD2B3A9620FDEULL, 0x4F315ABDE9EC0509ULL, 0x969D95F4816E41F1ULL, 
            0x260B5278C347B912ULL, 0xD3E7A7965E77E553ULL, 0xA7384F7597CB69C6ULL, 0x480910EE51984156ULL, 
            0xBC027B13401147AFULL, 0x8D595E50CB78C66DULL, 0xEA0647F8A80E79D4ULL, 0xA0CE4080741B6D07ULL, 
            0xCCFDC9E1DE51FBC4ULL, 0x3E6B63B58A3909D5ULL, 0x60968F610D3EEC36ULL, 0xE3AEF69FCCA9AC04ULL, 
            0xA0C50524C60C7B24ULL, 0xCA26922D994BA5A2ULL, 0xC586486D53677DD1ULL, 0xAB38C60A49ECA848ULL, 
            0xD0AF8C396E7C5DDCULL, 0x6CE0DBF00B12B0F8ULL, 0x1869D05B06EF5801ULL, 0x81CFC66ADB6631A8ULL, 
            0x0D844F2BC3BBE41AULL, 0x1BC93CE9C1CBC68EULL, 0xDDAA6684BA3919ABULL, 0xDFCE53ADE2185CA3ULL
        },
        {
            0x8E68B99AF79477E4ULL, 0x72DC07A70F50B4C1ULL, 0xCA1696A7375FD3C0ULL, 0xE6E708ED8487D6C8ULL, 
            0x3F239A92732B343AULL, 0xD6F51768BB2EDB3CULL, 0x808F5EE5258F40A1ULL, 0xD778BA5E85B5D77AULL, 
            0xA94385550100D34EULL, 0x6CB01E38B9ED1313ULL, 0x55AE0532D553FDC9ULL, 0xB5F336156B1FEC3DULL, 
            0x69824AD25EBE2233ULL, 0x655EB599B1A821B1ULL, 0x7CC45D4BEC969485ULL, 0xF737EF9FA5FC6B56ULL, 
            0x228B5F50BE753DE0ULL, 0xC07A3252866856EEULL, 0x325B9C97CD31FB36ULL, 0xFC118233CFA1657BULL, 
            0xB4161230B8C201C2ULL, 0xD84C0CF5A5B29164ULL, 0x126270330AB699DDULL, 0x657D0627530AF136ULL, 
            0xEA16C1A81513F6FDULL, 0x0B9012A49917B969ULL, 0x7A08C9C3B41F7D84ULL, 0x29F41FC2D030A919ULL, 
            0x70FD2BE896A63B7CULL, 0x5F917002E19AFC8DULL, 0x263F10005704B37DULL, 0x74D212597819B450ULL
        },
        {
            0xE084FBD7D965583FULL, 0xD48616809A277268ULL, 0xB93A45A570E66B62ULL, 0x8AA263176FEEC902ULL, 
            0xFEBBD5044C296FEFULL, 0xA69B314642C7A25BULL, 0x8ABF6D28A0539DD5ULL, 0x647AE35F154422C7ULL, 
            0x9EDF5CE586541BA3ULL, 0x97137FD2FFC7F145ULL, 0xFC739DC43FF3ED53ULL, 0x8EE24FC44DCBE2BBULL, 
            0x8D252788E819DEA5ULL, 0xE0990B8E3ABDD9F2ULL, 0x0428568813C2D922ULL, 0xB4A90C2BB50E4232ULL, 
            0x3E333C6056C3EE8CULL, 0x0800739DC0F3D149ULL, 0x3A8409F82D6FDF4AULL, 0xBF17CBA53D09FBF6ULL, 
            0xCFD912603F5896B6ULL, 0x30E52BF745BB3496ULL, 0x55DDC2B8F37A822AULL, 0x6B2B472265B0E6A1ULL, 
            0x8C197F8D6B68C150ULL, 0xD8E7018778490D9AULL, 0xF50689950335F002ULL, 0xD55C40CF7628D1F2ULL, 
            0x90B8A4EC6A0E7742ULL, 0x8CBA2A64CB262C3CULL, 0xCDFE02C397A39519ULL, 0x05304C98BD663643ULL
        }
    },
    {
        {
            0x5807C13A6B7EF7B9ULL, 0x34DBAE301202EE0EULL, 0xE066A619C8E04790ULL, 0xCCCAC195A3CDC188ULL, 
            0x33E8DE5D363E6B7BULL, 0x4729513E024FCE5CULL, 0x465F2246BACD0706ULL, 0x220B911B2C923055ULL, 
            0x940F8D2EA394F286ULL, 0x55EF240E497BF49FULL, 0x22BA65F50842F61AULL, 0xCE71433981CE8AC9ULL, 
            0x0740A5D0FAACE161ULL, 0x015F60436510D51AULL, 0xC855FB8EDE2A7C2DULL, 0xDFA74FC3913FA60AULL, 
            0xC9C178D0038C3040ULL, 0x5C29CF425533E10DULL, 0xB4BECDE2B4CE6E1BULL, 0x048F9C6CA863A167ULL, 
            0xE2BC3A966D589AB7ULL, 0xFC411C35E46BF3F4ULL, 0x3EF3AB105E7C7F00ULL, 0x9A2E3C8DBDE4D7DDULL, 
            0x31F063F2E50316F0ULL, 0xED8059C9E8CBAC79ULL, 0x6F25062D44F0BC4BULL, 0x4F4E613C44C6BD3DULL, 
            0x4F8B5A9CD27748F8ULL, 0x7F64BED43E524C9FULL, 0x18649B72F9B0E463ULL, 0xE9A5C7678EBB17B2ULL
        },
        {
            0x068ED67549754379ULL, 0x0DFD1A5D1B4B61B6ULL, 0xD4A8D5EB40D6558AULL, 0x88F0FA45AFDB292FULL, 
            0x996E3C8AB489AF05ULL, 0xDC497C558DBD7F6FULL, 0x851A26A7BAB18AECULL, 0xBEA6DE6BEB020E7BULL, 
            0xC4D494979B7CC32AULL, 0x748F6594763B7502ULL, 0x5C4872F96F6C68C3ULL, 0x48C30D0FA69B714EULL, 
            0x834EFCA8BC9AFE39ULL, 0xB4341A4B2E922D1EULL, 0x4E48FFE2FEAB23F8ULL, 0x4DFE56BDF7FC2AFFULL, 
            0x33EE5DCB95525D78ULL, 0x58757D178C787C65ULL, 0x442192C0D348CD78ULL, 0x54CA92326A71820DULL, 
            0x01B28BB5B30F4FC1ULL, 0xDCF76C6E3E926ABCULL, 0x56745D2D6F9ED442ULL, 0x4394B05561A06937ULL, 
            0x131184302671423DULL, 0xDE65D5AFB9918911ULL, 0xD934C1DD887EA3A8ULL, 0x129CAA8880478C40ULL, 
            0xCDCF23EF22EAC95DULL, 0x0DE91560147B1195ULL, 0x8075155F6913D3B8ULL, 0xEDD279CD3AC80E15ULL
        },
        {
            0xF1CC480D895FEFD9ULL, 0x9735C255DBB2F9D6ULL, 0xF84E924C2247BFB7ULL, 0x73967A02195AB803ULL, 
            0x3A8ADD18B3E18FA6ULL, 0x7432CD2E90170E14ULL, 0xD48705CE8AD0251BULL, 0x184B37CD35B5A60CULL, 
            0x1D2D7E099DC7A7A8ULL, 0xD15F578F0D2B0A4AULL, 0x1A20BE7A709AB577ULL, 0x7042413B723B4D74ULL, 
            0xB82B2265B3D30588ULL, 0x15F95BA5B2D61BB3ULL, 0x4A104D3BA8F9B280ULL, 0x919766921A233708ULL, 
            0x3FF0DD6FFC038F8EULL, 0xA788E9816E3611EAULL, 0x6E39AA567AAFD3CFULL, 0xC598CA0BB0D22293ULL, 
            0xF66131A2C398C44AULL, 0x9D5502503F521FFEULL, 0x00F967428E2418CFULL, 0x78B9DA278A9E7D91ULL, 
            0xD1B42792B60DDD99ULL, 0xABF1AC0581208961ULL, 0xE5D6F3F102C74696ULL, 0x500C6A52B309E2AAULL, 
            0xFE68B5BE7AF4BF98ULL, 0x25C80D48DBE08CF6ULL, 0xBCF0363DB7A8140CULL, 0x19F020369F27C2F6ULL
        },
        {
            0x5C7AD036D68E5303ULL, 0x088CB6F711BDDA89ULL, 0x9CAF05FBF64A790BULL, 0x92AC29A5192910DFULL, 
            0xDE5A4EF0FFE6B5E0ULL, 0x7742F9F28A219344ULL, 0xCBABADB1A75045C6ULL, 0x4AD047BDD41AFEDEULL, 
            0x5606261B3955DB90ULL, 0xCF608F06D001B0F7ULL, 0x85F33380B2DBA44BULL, 0xE39BDAFBCEA3BA02ULL, 
            0xAB884B499F5E8770ULL, 0xB6D987A506FF666BULL, 0x8367EE52F64A68E8ULL, 0x02CE42DD384828BAULL, 
            0x765BDBC25C7F1DB9ULL, 0x0F828FE64BF851DFULL, 0xA8FE50B1EF6A8FCAULL, 0x5BDB7A86A0CFDBF7ULL, 
            0x9FB9F5C4194C7D55ULL, 0x52D3831366BAC80EULL, 0x70B74AE30585D843ULL, 0xFCA4F3B12919012EULL, 
            0xEC5BB6D507458641ULL, 0x0EBA3A200C8653F8ULL, 0x16FA4EE39EC33C88ULL, 0x3E39DCB1E81F7206ULL, 
            0x99B4818F1BEDADE3ULL, 0x2BAC6F95332D62D7ULL, 0x60C18140E5C432B6ULL, 0x912DA03D22D7D953ULL
        },
        {
            0xA7CA8F80803B3935ULL, 0xF6231FF03FCADA12ULL, 0xF11BCFFF78EF8149ULL, 0xAE7E53C9DFD3118DULL, 
            0xEBF1F1104A02B0B5ULL, 0x51458D5617BA61BCULL, 0xB6E0C9AAF4FD18FEULL, 0xC1AB39A8104F62CEULL, 
            0xDD58CA811D75FD37ULL, 0x8547F407CBC83F86ULL, 0xF9A2C8E9414A83B4ULL, 0x6990A507AA6CB8EAULL, 
            0xBDD8870AEF2B9A2FULL, 0x8FC47F07D6F6A307ULL, 0x9453B8FFBB4B40C4ULL, 0xFA9AE3DED3308C4BULL, 
            0x9B91FEC073C9B91AULL, 0x749A094311F2068BULL, 0x13368EE504629E1FULL, 0x930360F2CE3EBBABULL, 
            0x40645FA15D66D69CULL, 0x942BC2773890E9DBULL, 0x6ECB72274375FFD0ULL, 0x31901E19B1078A50ULL, 
            0xB325AC1EA52B8448ULL, 0xB5567EA66AC88759ULL, 0x6CCF4A7B02FB796AULL, 0x1263BA76C1B2C841ULL, 
            0x7896DE23C63C4B7DULL, 0xB85AC0CA0EBD0D13ULL, 0xE9F63555FA9A27D8ULL, 0x195F69D8341D818DULL
        },
        {
            0x02AB1D41F9F51DA4ULL, 0xB0DAD23250B024D5ULL, 0xEC4DEC5CE9877E3AULL, 0xA806DC0DF16951DFULL, 
            0x52F5C7E835E4FEB2ULL, 0x0E1F0E1536BE278BULL, 0xC3A29879FEBCEC7BULL, 0x93C6722D71EB5B1DULL, 
            0x02493B15150D4EA9ULL, 0x6145684A75C1EB52ULL, 0xFB52DF3FB2A09775ULL, 0x77F12E5899D7AC9CULL, 
            0x3AB3525215A82CE1ULL, 0x7C3B48044609AE76ULL, 0x97FBBB6A8E8C2F84ULL, 0xD46E100217A9AF24ULL, 
            0xE893F904D644FE70ULL, 0x286E717C624C80FFULL, 0x9770A53A74DEBB12ULL, 0x3EA7DAA725F294BDULL, 
            0x7FB3F2066A685981ULL, 0xB56479862FECDE43ULL, 0x261920FEDD705720ULL, 0x493AB10E1E0EFA7FULL, 
            0xFE782EFCCC7A6D35ULL, 0xB12C5DCF7B318FCFULL, 0x9A22DCC17A6BAEF6ULL, 0x695A59F151D6BFBEULL, 
            0x0E1B7D0D6F131FA9ULL, 0x5659362FFBB9EAA4ULL, 0xF40311969B7B6EF8ULL, 0x10AEB4EE7EFADF45ULL
        }
    },
    {
        {
            0x33EFF86E6D827492ULL, 0xCB0C4B6A27EAEA8FULL, 0xC208ED0C2733FA78ULL, 0x4309946EC05336BCULL, 
            0x443A8DB2C2E17340ULL, 0x7207DC2789CC3975ULL, 0xF37033A6295D3E43ULL, 0xAAEFE64F4C69FE44ULL, 
            0xBE68835F56B7F0CDULL, 0xE7CE0874208FBB40ULL, 0xE9598776F77FBCEBULL, 0xB3FE1ABC79E75110ULL, 
            0x1E3D1144E25EE295ULL, 0xE873049ED30B6162ULL, 0x8516DEB5E49E6782ULL, 0x5BA6217F2A601644ULL, 
            0x08B9409CB3447211ULL, 0x12ED04FF7A0667A5ULL, 0xA87371F9FB731A5CULL, 0x40F8F2CF58F9725DULL, 
            0x6624BD4A21510708ULL, 0xA66142B98E87AFA7ULL, 0x11C941D50AE52F54ULL, 0x2ADDA764E2F276D9ULL, 
            0xAA2B59203B665113ULL, 0x0AB47ABE9C4C5BDCULL, 0xFAD547ACD93ED36AULL, 0x097DA7835A4988A5ULL, 
            0xB2A9F37178591576ULL, 0x91C1D9C4373BA738ULL, 0xF186C529AE6F0F6DULL, 0xD84ABC605921983CULL
        },
        {
            0x65E3713947649FF7ULL, 0xC2240B557909EBD0ULL, 0x6B6A321CB69839B1ULL, 0xA49C1948EC1BB5F3ULL, 
            0xC568436775C90FF2ULL, 0x3F32433F57EAB5F3ULL, 0x24C94999B75B4DB3ULL, 0x6ABB7BEB5F0200A4ULL, 
            0x9FFAB7D6F3EE4E03ULL, 0x66E77723C1725076ULL, 0x4DFD735E087E2AA2ULL, 0xB29180DB30CBAD15ULL, 
            0x96132240D2DC7F73ULL, 0x58425AD55A6ECF94ULL, 0x4A27933E8D840642ULL, 0xB3764B3593CA1DB6ULL, 
            0x2674565EBCE47D60ULL, 0xB3C48C5679A16419ULL, 0xFD795883083BFB3CULL, 0x7C6ED4F1A0AE47EBULL, 
            0x2879BFFFC9581AA9ULL, 0xB6C74BFD3DF81A4EULL, 0xBEAF31F364F8E693ULL, 0x10719199B716C52DULL, 
            0x95C1400C0182A79AULL, 0xE4141756785C742CULL, 0x413631998327A588ULL, 0x0378E23E99356D14ULL, 
            0x0735BBE7CD65F6BAULL, 0xB2B92B35E0F05FB4ULL, 0xD356EC54C28923FCULL, 0x7431D776E7B1221BULL
        },
        {
            0xDA5AB4AEA25B428DULL, 0x55DA5E74C584900CULL, 0xF92C2A7CBE5E56C9ULL, 0xFB74E0EBC7A2393AULL, 
            0x966C1E1106C78722ULL, 0xB0C2463633DE5788ULL, 0x113B470AE3394733ULL, 0x04EF65F212F929C6ULL, 
            0x2F758F3A975D1DFBULL, 0x093779D49B158419ULL, 0xDDC1FDE2060E140DULL, 0x1EA82D8614ED4E51ULL, 
            0xFD5672DAEA242D47ULL, 0x203CB760AB4F6BFCULL, 0x0251EA0E856A727BULL, 0x7ED6C02D1B8FFD5EULL, 
            0x2C802DB17546C39DULL, 0x43EF532E8476481CULL, 0x95DA862313C6113FULL, 0x8DBC409D8181E1C0ULL, 
            0xC1B2B9E36968C50FULL, 0x294212336C8A88F0ULL, 0x4502BBB18F87B810ULL, 0x5D0BE9A9783193E3ULL, 
            0x40226ACC77ACCA25ULL, 0x91417D309A9AE7AAULL, 0x3B66C28119D81B0BULL, 0xB195414C85A0C415ULL, 
            0x9936FA9AD11395C9ULL, 0x032FE017A01B4C05ULL, 0xC58211700E7A9E20ULL, 0xC4CF4FE78BD0275AULL
        },
        {
            0xFB7DEDA27A9D1CDEULL, 0x52DC0FEC05784DA4ULL, 0x2C384EC62E7F5A0BULL, 0x4F84C525320ABA31ULL, 
            0x46976D81F3B23FABULL, 0x7A7F125A6FD6466CULL, 0x2101E4AC5260354DULL, 0xF4CF72DB047209FFULL, 
            0xADA66A97521B4AD9ULL, 0xBEE12C35710DE3C6ULL, 0x4EF3CAC414D74B25ULL, 0x3DF24FB0BCBA6E28ULL, 
            0x2DC614F9972E58E1ULL, 0xC333F7456D96D291ULL, 0xA069A7F5F36E6CDEULL, 0x9A277F09E24512A1ULL, 
            0x60365BE022E6B9E4ULL, 0xFEB64445C60C257CULL, 0xDDDB2809B185229DULL, 0xA5C5181C83B37942ULL, 
            0x873DFE0E881D07D3ULL, 0x595D3FC91C6810FFULL, 0x49D84C520D8621F0ULL, 0xD8749CBAA26B0CCEULL, 
            0xBE44B7B27740A2ABULL, 0x7F0470FF2F47A369ULL, 0x5F1C4BF9456E7AB9ULL, 0xC01A0EFB365B7345ULL, 
            0xD47332E19E2B0185ULL, 0xD5B0FDB4F599844CULL, 0x4EEF5672DF10C619ULL, 0xE9B3FB1422710B8FULL
        },
        {
            0x291A12C3CDEE985CULL, 0x78B9850007745E0DULL, 0x3CDB80C40098D2A6ULL, 0xE213EFB36E13BCA4ULL, 
            0xC75EE02F0E2D00CEULL, 0x287A59A88F114148ULL, 0xA02993103C55AC61ULL, 0x629C03943DE01F0CULL, 
            0xB44B8E47D80E505FULL, 0x730CAE8459899810ULL, 0x3759DBBAADEB4814ULL, 0x9EEADC87082640AFULL, 
            0x27B02A7484560F0DULL, 0x3A57834E05FD7CFDULL, 0x43556D4CBCA2AF0DULL, 0x5C6DB783DC2747CEULL, 
            0xCD97CA8A22D5CBECULL, 0x42F0F7727094EA80ULL, 0xA91D6AB56E3C1415ULL, 0xD68E7EE4F275698BULL, 
            0xDC2EE0EFFF7EB0D6ULL, 0x2DE3510183E592F8ULL, 0x9F81B241CE002CDEULL, 0xBBBF978F237DBB6FULL, 
            0x87B68138711C80DCULL, 0xB2BC210EFDE899AAULL, 0x2C53835D18B37352ULL, 0x8F62414F753B71EEULL, 
            0xC0C45E1CEE253022ULL, 0xBE64F3716605FB59ULL, 0xD4DFF992F3B191DDULL, 0xAA0514208B030773ULL
        },
        {
            0x287B9B000000A6AEULL, 0xF799E2290722D7B1ULL, 0xF1EE91FF38C961CEULL, 0x0DB54EF72F1E9872ULL, 
            0x44323402317111E2ULL, 0x8F081237F1337E47ULL, 0x23A6C11AC0D908E0ULL, 0x896245A8ACE02289ULL, 
            0xBB35724CD1F7C377ULL, 0x844E9EB48D26D271ULL, 0xE9C56F3E666A9C96ULL, 0xEAD2FF580F9D3578ULL, 
            0x6DF4349DF963A950ULL, 0xCBC5DDE27839C5C7ULL, 0xFFF8762A830C54D6ULL, 0xAA60C06D900FCCE5ULL, 
            0xD9C232C4DF076C28ULL, 0xDE303877551A7E2EULL, 0x31ECFBD62FC10A5EULL, 0x431B6BA1F2D9D648ULL, 
            0xE7AD7513C8201F11ULL, 0x5E2C30E7F49F384BULL, 0xA86A68F025743BFBULL, 0x08D8FA6B406B7AB6ULL, 
            0x904FA23D0711CBF0ULL, 0x9B0E16151B84E4A9ULL, 0x3FE3856CFB5A99A2ULL, 0xE98BAEFAE317D09BULL, 
            0x0F39D6418796B64FULL, 0xDD8F8050453AED48ULL, 0x7E0DF30567383FDAULL, 0x97DF918121C9B13CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kSeedConstants = {
    0x399CDC319661C862ULL,
    0xD9632188ADE62882ULL,
    0x7F36BC0A9FB3D2D5ULL,
    0x399CDC319661C862ULL,
    0xD9632188ADE62882ULL,
    0x7F36BC0A9FB3D2D5ULL,
    0x6A769107D12853C0ULL,
    0xECE99CF65DF03235ULL,
    0x4F,
    0x70,
    0xE9,
    0x6E,
    0x38,
    0xC9,
    0x97,
    0x79
};

const TwistDomainSaltSet TwistExpander_Saiph::kTwistSalts = {
    {
        {
            0x069962A3C905CA8DULL, 0xC58C3650C235A7CDULL, 0x2E9EE6DD6E73A124ULL, 0x49825954787A1546ULL, 
            0x6ADFFE3C041551F9ULL, 0xA75119F56A2F8555ULL, 0x8F6BFC086D87AD7FULL, 0x309910095169BF4DULL, 
            0x4DD6CBD0C25DA8E0ULL, 0xA9A6D7ECB524EDF3ULL, 0x22ACA460F529693FULL, 0x39AB00850C2A3FDFULL, 
            0x5023A4E1129C08C7ULL, 0x372DFED0BC25F641ULL, 0x672FFA8AD285B889ULL, 0x80246505DEE6185AULL, 
            0x6941D58888A4D251ULL, 0x86BFE769C89938C0ULL, 0x5F6D695727BCFE99ULL, 0xF28E0DB7B2C07780ULL, 
            0xCE8473D71DE0BFDDULL, 0x197FE19299B3717FULL, 0xE1BA1D49D6E729FDULL, 0xC3523E94A132C4CDULL, 
            0x91062BB295AE08E0ULL, 0xBCE8341C5BFA20BBULL, 0xE350555CB5A50002ULL, 0xB45F218A5EF8F2B4ULL, 
            0x4C8B218C96EE7C05ULL, 0x0CB75871EA83F961ULL, 0xC4F55EA9C39DCDBEULL, 0x879F42B5525D237DULL
        },
        {
            0xAB467811CE48D084ULL, 0x255FCC2B64E2CC17ULL, 0xCB04591F5A56306AULL, 0xFCAABBEF55946C72ULL, 
            0xA08E2F81CC4A4A16ULL, 0x924D00D45BE70D1AULL, 0x82273BCA57644576ULL, 0xCE7EE95A92FBF9BDULL, 
            0x0CF241D320727A66ULL, 0xD590FB4590B7B61BULL, 0x9A5B642C12BA7595ULL, 0xD8D87FFE5B66F0BAULL, 
            0x3CA58B482016D907ULL, 0xC1F479FCA7C71283ULL, 0x0F86C620BE3E6650ULL, 0xAAC6A612C19CC1C2ULL, 
            0x7EC257B8917B58E2ULL, 0x09E4DC6C51B003E5ULL, 0xA71DFAF1D1425F71ULL, 0xD6B29F63ADF509A8ULL, 
            0x179154292C121304ULL, 0x336AC5730185A6F0ULL, 0x52B62EE84C1CC7C2ULL, 0x039329B424298C6CULL, 
            0xB401732AEA75D9D2ULL, 0xB6EDBE6FF9847B56ULL, 0x39399FD97580A0BEULL, 0x682C86503008A819ULL, 
            0x682336642C41C981ULL, 0x433A8B56DD3C5DDAULL, 0xD6C4603488380EF0ULL, 0x32A90DBF9655B15AULL
        },
        {
            0x834F40ED067A614BULL, 0x376F9F02476BC9D4ULL, 0xDFEA86ADF4D8E3A6ULL, 0x9681FD434DE751B6ULL, 
            0xA337774235ED85EDULL, 0xF98B46A451644E40ULL, 0xC548310F6A05DC55ULL, 0x5730CEBF7DB4020AULL, 
            0x630E39AE9CB8DC1CULL, 0x81AB5214254AFB2DULL, 0xEE54A7406F830D31ULL, 0xF885890E72B4A7A5ULL, 
            0x5BABA23CBCFFED0AULL, 0xAEF7AD37BB3EBC5AULL, 0x70AF89839C16C4CBULL, 0x33AA874ACE90E017ULL, 
            0x9800F6357E70ABF4ULL, 0x76CAEFFE2CC9C310ULL, 0xA2D92A6AF9AD0CEEULL, 0x4437B5030CFBA932ULL, 
            0x891CC19B60FF863DULL, 0xCC8D4910D5D4B721ULL, 0x542F1F37F80D5F7CULL, 0x9CD685657147ED96ULL, 
            0x24E2D05A4DD174A0ULL, 0xBE92B178C2C12D20ULL, 0x0F8E7D9B8B8591E1ULL, 0xBA260A0D86F8F7B4ULL, 
            0x3D571763C7D7664CULL, 0xF2595A572CCBE8C3ULL, 0x7D8134B0665722F9ULL, 0x291481EDF0E4F014ULL
        },
        {
            0xA8B1CD062D9ECE0BULL, 0xF3EB66BE667EB797ULL, 0x1BE52F5825B69343ULL, 0xD23F10BBB7817F97ULL, 
            0x445F2BD247E1F7CFULL, 0xC9787B3DD90D7F37ULL, 0x3134EDA8E581B8A4ULL, 0x46D92AB71A9128E8ULL, 
            0xD2E3027211953527ULL, 0x64008FF9C4597D20ULL, 0x3D2AE1C1DB34617BULL, 0x3E22F87D10C23583ULL, 
            0x0264FFDC691B34B1ULL, 0x2A92283D427AF640ULL, 0xABD0F7D85E9DF0E8ULL, 0xB975A7A635E721A7ULL, 
            0xF7F4896BC58A836DULL, 0x130D89F73A40E6C6ULL, 0xE59B28C90E13B3E2ULL, 0xD0A4D7621BB2D805ULL, 
            0xF83AE206DCDBA693ULL, 0xC6EFFE714961F284ULL, 0x6CC48FF54C5926DEULL, 0x440B25E29C296E08ULL, 
            0x6795D59CEE2908DDULL, 0xFE358F0E1F2348D2ULL, 0xA0BCFA70219A3F1EULL, 0xEFF54EDB6FA35C96ULL, 
            0xF4CB0472FFB02CC9ULL, 0x68B4C73AE09674FDULL, 0xF17DA97D5E42C337ULL, 0x8FE5B87C1C6F8380ULL
        },
        {
            0xD3D74E8E51164080ULL, 0xD3B6409DFD58A458ULL, 0xE52D4778075C0CF3ULL, 0x0346ED3C44E12072ULL, 
            0xAE25B1ACB26A2257ULL, 0x7BB40086490E2466ULL, 0xC8F947778866B499ULL, 0x084289E6515A72D8ULL, 
            0x8BD36079392E5F5AULL, 0xBF80C18FB95485B9ULL, 0x2C2317D0C1A4A7F5ULL, 0xDA073AA80609516BULL, 
            0xF1728742A0AD6493ULL, 0x1B7B812E92AEEA05ULL, 0xFC7301F41E0BB55BULL, 0x227B8FF9360DB6D4ULL, 
            0x2B75DBCE1CBF7A42ULL, 0xBBD41AB95FAE8BB3ULL, 0x9B436F2DDBBBDCA0ULL, 0x9DEB6E656C0F25C9ULL, 
            0x30108866ADB2CE31ULL, 0x2D4FFC1CDB260268ULL, 0x0C83992306DCCB96ULL, 0x302B88A4AFEC6368ULL, 
            0x95480F139AF43F21ULL, 0x68160E0CCA2AFC65ULL, 0x3297578270AF75E4ULL, 0xFDB3BE12E8D4153AULL, 
            0xFB94B9B723E4AEAAULL, 0xFE6B1348DE854AD0ULL, 0x2AE50BB46E094C29ULL, 0x45BCE70C72F64D4BULL
        },
        {
            0x8D0D5A6F2565938BULL, 0xFD643C4F7A3EC4B1ULL, 0xB48CBDC956D8881CULL, 0x9270ED562510D3B0ULL, 
            0x68DF5E40C56D030BULL, 0xB8A6198A82389BA4ULL, 0x76908E3E6930C577ULL, 0xB5C0964C87BA0049ULL, 
            0x74AF582E88C80766ULL, 0x3F69BA5207B75708ULL, 0xF3D5379E2B83881EULL, 0x14BDDFB90BA984D5ULL, 
            0x367E155A58ABC358ULL, 0x4EF15F2F8B475A5CULL, 0x81FE3F82C1843A8AULL, 0x304A26E55179CCA1ULL, 
            0x927E2A984E164E7EULL, 0x0AF077DC07E12D02ULL, 0xCCA8228A6476701CULL, 0x2EEB50847B796906ULL, 
            0x9362D9CEA6EA786CULL, 0x473B1B9B5046FCFCULL, 0x63A20D7FCD663DC3ULL, 0x84FB64AD5EF5006BULL, 
            0x7B37A6BC75D3FBEEULL, 0x6DBF21B2FA3058B6ULL, 0x5072731B03F24AF8ULL, 0xFCAA3E2ECA35FFAAULL, 
            0x06CDE176765E5165ULL, 0xBAFB47A29369E32BULL, 0xA080D69B990D8200ULL, 0x6B5DDFBD6784673FULL
        }
    },
    {
        {
            0x6D426128D7772794ULL, 0xE9508FF1A5363C65ULL, 0x833D3EFA96A26D97ULL, 0x2AD1B2149C4F50B3ULL, 
            0x545A630633FD384DULL, 0x3072DE9155B3D826ULL, 0x04480086181747ADULL, 0xE62388015F5255F1ULL, 
            0xC79F63EB26A53E7AULL, 0xE5DE918BB5BE952AULL, 0xCC182AB5B450C1F7ULL, 0x45BA518785EB7219ULL, 
            0x655E145D0D5C40C5ULL, 0xC6E83798698FE912ULL, 0x45C990EE622574DAULL, 0x9E55B72C857790ACULL, 
            0x82FB92672932F013ULL, 0x57FCC9A3E125DD60ULL, 0xB5F76FA47C4027D8ULL, 0xBA652A4A296D1215ULL, 
            0xF70D319B93C52738ULL, 0x98813CB6DB56CFD1ULL, 0x0B59037AD75D691EULL, 0x0FB45FC3EAB12916ULL, 
            0x69182C488EB696AAULL, 0xE4CA42722D1DAEB4ULL, 0x77F22BD63752F5EBULL, 0xE09EE83A6DD8ED7DULL, 
            0x7F173F0DE76F951AULL, 0xBD3B1E35A7B83F20ULL, 0xF6751BF32C7F0F8DULL, 0x1531A6DCB052CF70ULL
        },
        {
            0xE6E157EEA03B9135ULL, 0x4BE4E8E7FB78AA05ULL, 0x33ADA713259BD37DULL, 0x27422FA9C5DCBD4DULL, 
            0x88B0FA5F5A56D6F7ULL, 0xD695C63517E1D8A0ULL, 0xB9B6AF26900471C5ULL, 0x5C7F45EE0F0A43D9ULL, 
            0x0EFD8F55C763FA5AULL, 0x60A1D24665CABF09ULL, 0x2CB6DD4D4F553F31ULL, 0x573E0B94D9A65679ULL, 
            0x398F7BE1466C7465ULL, 0xFFE8D95DA4F6C4EFULL, 0xC19E9B2AFD7B6F4AULL, 0x5723503F17440C6BULL, 
            0xABB5667820E09C0DULL, 0xA8C590F2CFB4B971ULL, 0xD97511B3483CDE76ULL, 0x06C8A70C2FC33B9DULL, 
            0x6F2D6FFD7223716EULL, 0x6867C28386E9B791ULL, 0xEA3471CA713ED56BULL, 0xA568A1540FE66723ULL, 
            0x8E627BC3FD9F1324ULL, 0x9E24015E2854C9C8ULL, 0x0984153CDA179398ULL, 0x33DA29D67A399F2BULL, 
            0xBB585FDF9466EF4EULL, 0xDB17F59CC1BF378CULL, 0x1AD6B00647108B27ULL, 0x6A76C9D8693DAF16ULL
        },
        {
            0x6457DE372EEF3F68ULL, 0x8CC8C28CD5818713ULL, 0x435CFCE6F6190895ULL, 0xB1F927186C9028EDULL, 
            0xB4A84D4068114665ULL, 0x0714AC2C6B0B1512ULL, 0x77AF97AFCF53D49BULL, 0xC76901564D6CF145ULL, 
            0xDB23879715114FB1ULL, 0xB7544EA427F9E344ULL, 0x83A0011DE3E30A8EULL, 0x051EFA61BB2E938AULL, 
            0x69C4DDC1D0C6CDEDULL, 0x028CACD0B93D72E8ULL, 0x01654ED4254A74EFULL, 0xDDF83E8BCD91EE47ULL, 
            0x9171E850DDBFA2B0ULL, 0xA62E0133A0769BEAULL, 0xB5DF01F93F9F0CC6ULL, 0x008B4B878B1E7292ULL, 
            0x9046E9C8252F9737ULL, 0x39F59E308F0ECDCFULL, 0x0F4E362A8F267097ULL, 0x120E01A9427B9396ULL, 
            0xF2CC7ABD9DE2B7F5ULL, 0x6E519BD2FCCD3E9CULL, 0x64E878303781A6AAULL, 0xC456F33C6DBC3AE8ULL, 
            0x83554D3708C89E0DULL, 0xF1B95B51DD552AF4ULL, 0x689D51687CB640F8ULL, 0x54340380486F0C57ULL
        },
        {
            0x9788C8DAE565B9C8ULL, 0x281B2017D924658CULL, 0xB8395B0CA2C12CBEULL, 0xB42BE87D363D5BC8ULL, 
            0xBE54992720947552ULL, 0x51D774E42078CC65ULL, 0xD49C63CF830D6C89ULL, 0xB336965D18C88BE0ULL, 
            0x29072CDEE345FA7EULL, 0xA99C0CB86851062EULL, 0x20D91234A463CE2BULL, 0x7288B19253D76839ULL, 
            0x7D86BAA1ADC2E730ULL, 0xCBEACB2BEABDFFEBULL, 0x3D9FD2E2C48016FBULL, 0xDC9C0178E22AD24BULL, 
            0xDFB8947C7C1088EFULL, 0xB0E3EC3BE39ED69DULL, 0xB5124FDF60EB91F1ULL, 0x7A99E4C47117BBABULL, 
            0x09DAFDC09708130DULL, 0x86D9951B2443ABB5ULL, 0x25A711979DB51E57ULL, 0x48EE765246026673ULL, 
            0x79EDFAD47A088AAFULL, 0xA22652B9FAC7DBE6ULL, 0xBCA325272D003209ULL, 0x0D59A4A2A8A7F1B2ULL, 
            0x92033FB99DCF3E97ULL, 0xDE2502A2E5627087ULL, 0x2FB93EF146AE9F2CULL, 0x0C805A8919C4A3C8ULL
        },
        {
            0x4F7F980EE478E5D7ULL, 0x3F18450546DEE879ULL, 0xF44948D40EAC1C5AULL, 0xF6D78323BC3BBC82ULL, 
            0x135A0B60FB5CDED6ULL, 0xD43292AA7C5015B4ULL, 0x41AE2CE1FF6424B1ULL, 0x87C7E6D467A6A207ULL, 
            0x532655A14EB894AAULL, 0x58F2B4C71EACE875ULL, 0xB52E42CD55E7D18DULL, 0x5B020922FE074E5CULL, 
            0x39A8A5443220A987ULL, 0x33BBAF7FB20187FEULL, 0xB8DE09AFEF88F501ULL, 0x56C305A09D699902ULL, 
            0x115047455CCF0C22ULL, 0x642E1B035C36A7FAULL, 0x33BE7C3D9267C993ULL, 0xB838247F9ADAC825ULL, 
            0x4B21193382F9AC22ULL, 0xF4E8C8219ECF73FDULL, 0x010CF19DE7B313CBULL, 0x0AB60AEC7EBB5C8EULL, 
            0x8E443BDAE1017E91ULL, 0xA7589C1049C38008ULL, 0x85520CCCF7E37505ULL, 0xB17246A612348F8AULL, 
            0x4A728DCF8E88BA36ULL, 0x65E578392A0E15C7ULL, 0x52C8399416EAB3B9ULL, 0x160DD7568DBC30D8ULL
        },
        {
            0x0134D1120C62FEBBULL, 0xEC807B44C5004FC4ULL, 0x28787D10B2245891ULL, 0x0665DBEE2FDF7F89ULL, 
            0x8EF11AC691CF9D4FULL, 0xF9D80241594E9C66ULL, 0x0C22E81ECF82A9FEULL, 0x7AD22D07A6B5EC86ULL, 
            0xD06FDA0399A6BCD9ULL, 0xAD0B13BF89254B2DULL, 0x2A22D3325BBB15C6ULL, 0xEDC44A54A909F057ULL, 
            0x81420FBFF3AF4638ULL, 0xAB34E5F3B74D0CBFULL, 0x86A52A279571FEB5ULL, 0xFDF4BDEE83CB2C77ULL, 
            0x89891E7755F27E18ULL, 0xBF922BDA5DD292E2ULL, 0x33CAD9CE4737E942ULL, 0x9AFBDC3FD424DA95ULL, 
            0x4E4A73B9554FB805ULL, 0xA1F04950AFDE22CCULL, 0x1CDDF51D9CA357F5ULL, 0xD853CD5D2723A8E6ULL, 
            0xA9D32A6A2239AA17ULL, 0xB1D39AB0CB6F8882ULL, 0x016ADD6A7B6FC8B4ULL, 0xE31A146829DB7E9CULL, 
            0xFEB516BDAF311A78ULL, 0xFB401F9BDBA4832BULL, 0x8833455C895A5682ULL, 0x80142CDF5E686034ULL
        }
    },
    {
        {
            0xF2033E9D31E3AEFBULL, 0xE9BCC8DE64ECA1D8ULL, 0xF4AA94FB1FE0A3F6ULL, 0x7CDCDD0EDE22DA0FULL, 
            0xB40F6D4B02F9AACBULL, 0x28F6105D30B0BBC5ULL, 0xBB1B929073FE15DBULL, 0xF26335FEA433523EULL, 
            0xD919CD84EE6912A1ULL, 0x9F358BFE008500B2ULL, 0x1B3D4D40CA11BAD6ULL, 0x8FE33DA83BEB5399ULL, 
            0x9AE24729274520AEULL, 0x50656C0CF8380E83ULL, 0x0AEAC19B53653154ULL, 0xF4C9E63297C88A3CULL, 
            0xEAD360F3269B8507ULL, 0x78A5DC1205AEACB4ULL, 0xA1A9CE65F6F46190ULL, 0xA763DA2935D67D24ULL, 
            0x1A6006DF7BA7713DULL, 0xC81E8072EC81C62EULL, 0x71BDDF0AE5EF3711ULL, 0xD0C0970FE557C060ULL, 
            0x899E899A88094A2BULL, 0x18352B355805AFCAULL, 0x5BF88383D68B0690ULL, 0xD5B0D4B31C6A42EFULL, 
            0x121A583F1400D26AULL, 0x5C744128113886CFULL, 0xBECBDC12EDE42B58ULL, 0x969D9855F4992DDCULL
        },
        {
            0x995AC484848CD2C4ULL, 0x1F4ABDCEA7201BD2ULL, 0x0567B17894896500ULL, 0x5F94F2A9709C4BF4ULL, 
            0x6D1F7FE5D7F50B73ULL, 0xEB97954AB11D6387ULL, 0x51BAA186632ADC03ULL, 0x43500D9DA2E30763ULL, 
            0x3B2FE3D10BFBE0A7ULL, 0xF42D5724CE0FBA47ULL, 0x582BC80773A32D02ULL, 0xE4C1E6B7364D6165ULL, 
            0xCB006F72859FD0EDULL, 0x41E1050F9764CE2CULL, 0x4106143737C0CE14ULL, 0xA4997F35A5C146BDULL, 
            0x4E79F911E01E911AULL, 0x60C48683E49CFA1CULL, 0x47C0AF7021013883ULL, 0xEFE6874697769654ULL, 
            0xDFE54C8D8080E6DEULL, 0x968F4CB94022F784ULL, 0xCECD30E32F6F0B04ULL, 0xEFFC8F1B3BEAEF37ULL, 
            0x0E85B7001D572609ULL, 0xA692F441839EE7AFULL, 0x9B49BFEE87BB6502ULL, 0x1E80D056848E3269ULL, 
            0xEBFB29527C16FC41ULL, 0x6FE5EE37A72A8012ULL, 0xD012437D110297B3ULL, 0xDCC7F478FA0D6FACULL
        },
        {
            0xAA1C4FAF46E6FF58ULL, 0xA6ADF5C7799AEAE6ULL, 0xC9683424B4E35719ULL, 0x155227139F1D494CULL, 
            0x7AFE809AF1047C4CULL, 0x1280EFDC807882FAULL, 0x30753009444A6820ULL, 0x26611D68FBA941A3ULL, 
            0xA5FAB45952F69D24ULL, 0x1336C097A972C0B7ULL, 0xD9547B9BFD1E4081ULL, 0xC0009953FE35F0C2ULL, 
            0x5AC4333712F08549ULL, 0x4EBDD36FBF60D2CEULL, 0x0B9833634BB78778ULL, 0x8C550BD6788DF4C2ULL, 
            0xC96B6A3D99FBDD49ULL, 0x3D96E34E3DFA0DE9ULL, 0x83A4ADDE02E33138ULL, 0xC10956FED965EB7FULL, 
            0xE33144A47D322EE6ULL, 0xF21120A967EA2F5FULL, 0xFD8C3DA52E5FC365ULL, 0xEE5AD293508C62D0ULL, 
            0x23E6443D1F316066ULL, 0x91EFB86897035BE6ULL, 0x47FBC040672DD149ULL, 0x27A617048097B88CULL, 
            0x9FA3307A9348EEE1ULL, 0x3273DD901DE70DBFULL, 0x99D2E2CE220D133DULL, 0x1A911EC64A6A458CULL
        },
        {
            0x81200E5A9A865945ULL, 0xC4BDD52D73E33BD7ULL, 0x3550A478900DAA51ULL, 0xDAB0A26889C9C3C9ULL, 
            0x902F95FD46C88211ULL, 0x301FBBFE0A00FC23ULL, 0x063D7C9825E101F0ULL, 0x4CE8145DA587EA72ULL, 
            0x9AC63CDA94E00778ULL, 0xA5A9EED5B987A56EULL, 0x3D5E7F3DBC4C64FDULL, 0xE52D0A0D0EA1073FULL, 
            0x2FA5BECE4742921DULL, 0xD738AB2AC2F31871ULL, 0x260C41BA6A725A1BULL, 0x6FDF1BDAFA07D279ULL, 
            0xC1D4EBB3D3281FEBULL, 0x0A7C3806378281ABULL, 0xAFCD740312A7DB9FULL, 0x082DD6ECC4CF8107ULL, 
            0x0D922D570D79998EULL, 0x33303D0C983381C2ULL, 0x55F780606210CD70ULL, 0x5824C7045356A0B3ULL, 
            0x4426F1DD24BDD33EULL, 0xF390E14485513097ULL, 0x845F2CB9D788750EULL, 0xC25D987747219277ULL, 
            0xD62A2D25C5062721ULL, 0x93C6DA1C103F97D7ULL, 0x77298C2409CE6433ULL, 0x037A1AA7C0887C26ULL
        },
        {
            0x6159366D83128D97ULL, 0x81850D5A7D6E383CULL, 0x3612B9CBCDF9CE18ULL, 0x563A9A73A655425FULL, 
            0xF2CEFFE917DD924BULL, 0x80C8A22A438D42A1ULL, 0x748173BF371B296CULL, 0xD683D1BC714E5CD3ULL, 
            0xFF1FD09D685D415FULL, 0xB435EF95C60205D3ULL, 0x6D82EB01D6E9B2F3ULL, 0x343B30A547C725EEULL, 
            0x0641303F65F83036ULL, 0x09AC3A5F656459EBULL, 0x81BCE8C9A0BB4BA4ULL, 0x5A292FB67004F421ULL, 
            0x060ED9F6E46DD34EULL, 0x037AAE8D5F75B170ULL, 0x83EC2581BAC35EB6ULL, 0x880484122F41ACBAULL, 
            0xD216806BF960C6E5ULL, 0xFBD3A067C6005C3CULL, 0xD37C7F2647FA56D1ULL, 0x93300A6D447EA765ULL, 
            0x1A26ECBBC2D9259AULL, 0x0B805EA556E6917BULL, 0x9178D6DAF5C46643ULL, 0xF11543D2D1A98AFDULL, 
            0xC04AE00E52EEECB5ULL, 0x1C6CA4CF8AF6F485ULL, 0xCC5D8E60874298AAULL, 0x2A0DAD89534494F1ULL
        },
        {
            0x07F16D5BA2FFE218ULL, 0x4DF4C80F00D4521AULL, 0x9EF51155760930A2ULL, 0x236B5BE06D1E836BULL, 
            0x351C855146BE81BBULL, 0x72C0FD1FCD2A1537ULL, 0x9EE9EFE910EB8145ULL, 0xB7B69240C34E0B0AULL, 
            0x871448E6988A3B8BULL, 0xB8C22910D73782C8ULL, 0x61B7D04081672454ULL, 0xDB50495940E1AE58ULL, 
            0x74EE414DBD99D416ULL, 0x8B9BCB38F2FB4C43ULL, 0xA440E8FAE712D048ULL, 0x636F7FD04D45D49CULL, 
            0x20DBC57A937C989FULL, 0xE32327A8ACE72383ULL, 0x065CBCC31AF9A9D2ULL, 0x5388E1271065BC67ULL, 
            0xACE967180683E7C1ULL, 0xD806716CEC755ED6ULL, 0x81F3B0FAF808BFBAULL, 0x8A8E1F682919D45AULL, 
            0x3DF74C103D7D5E2BULL, 0xCFF3000836E32E4CULL, 0x0C2184BCCCD41F73ULL, 0xCD997C208CE95C9EULL, 
            0x6A2855A50D91594CULL, 0x4EB55537316FE005ULL, 0xDDB28B5E3A4247C5ULL, 0xADD85080B6307F24ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kTwistConstants = {
    0xA8C243FC8A7A30A3ULL,
    0xDB659A70200DE319ULL,
    0x7A8A3AFBBE977205ULL,
    0xA8C243FC8A7A30A3ULL,
    0xDB659A70200DE319ULL,
    0x7A8A3AFBBE977205ULL,
    0x033059A6DDE8B7AFULL,
    0x2A2A11CE0C23ECB6ULL,
    0x74,
    0x9D,
    0x31,
    0xE7,
    0x16,
    0x1C,
    0x76,
    0xE5
};

