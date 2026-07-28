#include "TwistExpander_Mimosa.hpp"
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

TwistExpander_Mimosa::TwistExpander_Mimosa()
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

void TwistExpander_Mimosa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mimosa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8777DAC83801A49FULL;
    std::uint64_t aIngress = 0x9D0C8A50927C62B8ULL;
    std::uint64_t aCarry = 0xA0FAF5C095896277ULL;

    std::uint64_t aWandererA = 0xE159D8C109D7852BULL;
    std::uint64_t aWandererB = 0xCC22B59870EEA6D4ULL;
    std::uint64_t aWandererC = 0x84EFC4C435999E1EULL;
    std::uint64_t aWandererD = 0xF6A7531B5B294854ULL;
    std::uint64_t aWandererE = 0xA2A2AF29C014D2F9ULL;
    std::uint64_t aWandererF = 0xEFBDEC3C77AB2EC2ULL;
    std::uint64_t aWandererG = 0x9841F1F8467A5A37ULL;
    std::uint64_t aWandererH = 0xAD7F55719F7694BDULL;
    std::uint64_t aWandererI = 0xF1AE1F864DC41D21ULL;
    std::uint64_t aWandererJ = 0xD01720B80A1B3A0AULL;
    std::uint64_t aWandererK = 0xD0DA0E2B8F517C77ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x97740E08A3FDADC2ULL;
    aIngress = 0xCB04F68231CCC5C8ULL;
    aCarry = 0x891AB2865BB75B2AULL;
    aWandererA = 0xE569461199B012F1ULL;
    aWandererB = 0xCFEF9794CDCE1EC7ULL;
    aWandererC = 0xD8A85C02335C5367ULL;
    aWandererD = 0x8EEBC421B8F1603AULL;
    aWandererE = 0xA28E0EB9E6E50E4CULL;
    aWandererF = 0xCBEC8BCA64A39C29ULL;
    aWandererG = 0xF5556441EF70F1B6ULL;
    aWandererH = 0x9B18BEB47EA7C82CULL;
    aWandererI = 0xDD5FC549652DAF61ULL;
    aWandererJ = 0xA58EB183AE910D3FULL;
    aWandererK = 0xE1A38CC0D7DD4179ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xED9F0A26B7590BBFULL;
    aIngress = 0xF07138069D98C1E1ULL;
    aCarry = 0xF53E65DAE52DE812ULL;
    aWandererA = 0xFCB5B54A5EBC59D4ULL;
    aWandererB = 0xE864ED00C85D1A5DULL;
    aWandererC = 0xC08E8C61792AD3F7ULL;
    aWandererD = 0xF64FB1D9C6F60C1EULL;
    aWandererE = 0xF9BEA5A2A6B62001ULL;
    aWandererF = 0xE373EDCE16265E7FULL;
    aWandererG = 0xD3698C6D4EA9A184ULL;
    aWandererH = 0xB34597B4C42CC873ULL;
    aWandererI = 0xB8C23E6BB5CC54DCULL;
    aWandererJ = 0x91650A246F3AF7A9ULL;
    aWandererK = 0xCB6C3221DCC1D9E4ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF93DDFFED436A880ULL;
    aIngress = 0xBAA6C0A45D4570B0ULL;
    aCarry = 0xAC9B114F80BD197DULL;
    aWandererA = 0xBBAA0855B0605415ULL;
    aWandererB = 0x9C490449D37CCBB2ULL;
    aWandererC = 0x97B99BDF9AE7A5FCULL;
    aWandererD = 0xE9D4F36BF2845AC6ULL;
    aWandererE = 0xF7CEADA96F22CB3AULL;
    aWandererF = 0x871F0F436D092D98ULL;
    aWandererG = 0xA700C23168669BD7ULL;
    aWandererH = 0xE34B14345FA6F76EULL;
    aWandererI = 0xD21860304F932D0AULL;
    aWandererJ = 0xFB65C487F1BC4D03ULL;
    aWandererK = 0x83CF138F54E02518ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xDA2F6272649B2F3DULL;
    aIngress = 0x96E79C87733F2DF2ULL;
    aCarry = 0x8D43AEA22A812F6EULL;
    aWandererA = 0xFBA6485772085C1FULL;
    aWandererB = 0x8AB6829315AA47C9ULL;
    aWandererC = 0xFF520C0E69C2D47EULL;
    aWandererD = 0x9B0234FF94CEAB1AULL;
    aWandererE = 0xBF1F25F105DC7AD9ULL;
    aWandererF = 0xA2B7A231FEA60ED4ULL;
    aWandererG = 0x9837DC004CDE7637ULL;
    aWandererH = 0xDFAD49C5D62FFFC2ULL;
    aWandererI = 0xADE620B91DF22F0EULL;
    aWandererJ = 0xA01D5C3CE254CB52ULL;
    aWandererK = 0xB44F5AA1AD85DF06ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x86BD81F63A892352ULL;
    aIngress = 0x8313E46235F0FBE2ULL;
    aCarry = 0xD86FA42A543F111DULL;
    aWandererA = 0xBA48A35FA5DDEC66ULL;
    aWandererB = 0xC13AE21C0EA50B48ULL;
    aWandererC = 0xB1DAE8EBED3DBF80ULL;
    aWandererD = 0xC2EB96D2CE39C026ULL;
    aWandererE = 0xC0504D58D533DFCFULL;
    aWandererF = 0xCFB1E36FD32C549CULL;
    aWandererG = 0xBAA4823EF7838092ULL;
    aWandererH = 0xC16AB30856B3F8A6ULL;
    aWandererI = 0x9EB1E73165041CFFULL;
    aWandererJ = 0xB053302F7ABD41E1ULL;
    aWandererK = 0x83876F7147C143E1ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE0C607C1698F89BCULL;
    aIngress = 0xFD6987C558BAE588ULL;
    aCarry = 0xB743016C175A9C57ULL;
    aWandererA = 0xB89C185D7AAA0D06ULL;
    aWandererB = 0xB4C8C0B60D0EDD16ULL;
    aWandererC = 0xDDB69BE3023EAAC5ULL;
    aWandererD = 0x830AB0132903FFF7ULL;
    aWandererE = 0xE47AAFC5FAE2B473ULL;
    aWandererF = 0xCF7F449B0F3D9858ULL;
    aWandererG = 0xAAB1961757D227CAULL;
    aWandererH = 0x954BF74A71B85F00ULL;
    aWandererI = 0xE0ABCC575980964BULL;
    aWandererJ = 0xF6D8A792D1BA1028ULL;
    aWandererK = 0xE3ED4A17240F7142ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xF38D1DEF3148ACCEULL;
    aIngress = 0x84DA699C7E2A7C7EULL;
    aCarry = 0x8E358C6C145EF2C5ULL;
    aWandererA = 0xDB51DB5FC45594FEULL;
    aWandererB = 0xA0F7BA5D4721CCADULL;
    aWandererC = 0xD3693FAA1803C3A7ULL;
    aWandererD = 0xDB84EFB84DB6AD59ULL;
    aWandererE = 0x95F20C6F62B9BCB0ULL;
    aWandererF = 0xF44044CDABA6E6A2ULL;
    aWandererG = 0x97AE844AFAA49D4BULL;
    aWandererH = 0xEDDAB5FB2D44125FULL;
    aWandererI = 0xE567F60AF8916437ULL;
    aWandererJ = 0xB2CB7627566D5637ULL;
    aWandererK = 0x9B5B2F8C399A1D7FULL;
    //
    TwistExpander_Mimosa_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Mimosa_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Mimosa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA938DE547885E917ULL; std::uint64_t aIngress = 0xA2EBBE6221F578E5ULL; std::uint64_t aCarry = 0xAEDCA764ADD19D06ULL;

    std::uint64_t aWandererA = 0xC36AEA04E4885B18ULL; std::uint64_t aWandererB = 0xAC6E94E9C3377721ULL; std::uint64_t aWandererC = 0x886E2F86CEB6C028ULL; std::uint64_t aWandererD = 0xE9731A721B9311DFULL;
    std::uint64_t aWandererE = 0xED42EF8AF31BCB63ULL; std::uint64_t aWandererF = 0x87546160813D2650ULL; std::uint64_t aWandererG = 0xBEC5A0E1878E5935ULL; std::uint64_t aWandererH = 0x8CD172B1C3A701B0ULL;
    std::uint64_t aWandererI = 0x840B15CFBBA709E8ULL; std::uint64_t aWandererJ = 0xAD3DF272DC4A9C82ULL; std::uint64_t aWandererK = 0x9BBE232C32CC0DC0ULL;

    // [twist]
        aPrevious = 0xC6F65E0DEBE608FAULL;
        aCarry = 0xACD4FCCBED3E63A8ULL;
        aWandererA = 0xA1CD570B485FE904ULL;
        aWandererB = 0xA5DC0E8F1A834621ULL;
        aWandererC = 0xF38C59182FB6A2F7ULL;
        aWandererD = 0x923720A65E063A59ULL;
        aWandererE = 0xFE2AE2F24B005591ULL;
        aWandererF = 0xB1C8896AFAD5DD54ULL;
        aWandererG = 0xDAB55E072462FBE6ULL;
        aWandererH = 0x8C4A6B92DE8FC18CULL;
        aWandererI = 0xB15886D8AA7E2843ULL;
        aWandererJ = 0x8B60744C0724B6ACULL;
        aWandererK = 0x8C4297758B2DB174ULL;
    TwistExpander_Mimosa_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mimosa_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Mimosa::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mimosa_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mimosa_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mimosa_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mimosa::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mimosa_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mimosa_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mimosa_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mimosa::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 19 of 33
    // Exploration cases: 0
    // Structural maximin 521 / 674; family total 9637
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1555U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 19 of 33
    // Exploration cases: 0
    // Structural maximin 521 / 674; family total 9631
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 925U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mimosa::kKeyRotateASalts = {
    {
        {
            0xA7EF9C96B4F58274ULL, 0x864B1F6F8803BDD3ULL, 0x26B851F9CF0578CBULL, 0x06C82AA22DEDFF2CULL, 
            0x33AAC30371CC3399ULL, 0x03243F91447C2F7DULL, 0xD1E05004D0004058ULL, 0x304907EEB36C7493ULL, 
            0x90056CF797274CE7ULL, 0x8CA3C3BF919318C4ULL, 0x378050F916E91D29ULL, 0x7BCEED041ABE8E6CULL, 
            0x78A766FE7B59A160ULL, 0xA45049D4EF2DCE3CULL, 0xF1712643F9AB604AULL, 0xF9635DB6D4ADBF28ULL, 
            0x7E01DF2C3E06A7F0ULL, 0xA39887AF2D252664ULL, 0x50EE7E10DF3D278CULL, 0x3A6B6252F7AD96DBULL, 
            0x7A7EF772614D4297ULL, 0x99CE6B96EBB3EA78ULL, 0x4299911DE6A6D653ULL, 0xD738B417BEABCD53ULL, 
            0x0309C08ACC20186FULL, 0x5637682B991C19DBULL, 0xA8A8BABE6CCECBD6ULL, 0xB42B837150AD1ABAULL, 
            0xA72EE44F254B8415ULL, 0x141EBD64FC2D8919ULL, 0xA31EB74EAAB5E44CULL, 0xA1379E58FCB18D96ULL
        },
        {
            0x07B133B4BC6285A5ULL, 0xD7342936507E7DA2ULL, 0x85555DD2D2BACBF9ULL, 0xD3CF99F4512EC7DFULL, 
            0x972B860CD630682BULL, 0x069CBE8B3615B9C4ULL, 0xBFC1F92D9F92DDA9ULL, 0x39A5CEEF3C09909AULL, 
            0xD8EF5E7107886476ULL, 0xF6EDF4728AC4DA8BULL, 0x2FBAE1CD5E530BC2ULL, 0xB464EBE9B9FFF899ULL, 
            0x7AD358C965D1FB06ULL, 0x45AD89BB94EF27CFULL, 0x4897E4D11DA42C84ULL, 0x2738B79B6E754D7BULL, 
            0x203A83EE0176A646ULL, 0x43F4D07F85C18717ULL, 0x62AA6BD05E392DD1ULL, 0x2FB80C44B30F408AULL, 
            0x5110DA15A0F7FA10ULL, 0x9C19C30C10695A36ULL, 0x3C70A166EBA11643ULL, 0x84DBEDF1AFFB2FDBULL, 
            0xD79307E833926661ULL, 0xA6CD32E962E87ECFULL, 0xFDFD8129EDD934CFULL, 0xFCB27F6BB9D171F2ULL, 
            0xB43CB8DC58ED8932ULL, 0x5BDAFA3975CF806AULL, 0x3F391DF4593A8BCBULL, 0x97BCD7C669B6D3D9ULL
        },
        {
            0x9455755BEC3709F8ULL, 0xEC3929D0D0F691B5ULL, 0x234C18024578DA22ULL, 0x1F58A0B0D529C42AULL, 
            0x138EB4796DF4185DULL, 0x7B084D97A9193247ULL, 0x820EC65899791018ULL, 0x2B7F212E53722234ULL, 
            0x85277331C301B76FULL, 0x3671FD4BE5D8F603ULL, 0x3465992367E9B625ULL, 0x9266D0D3D5DF1B91ULL, 
            0xA5E618E10765917BULL, 0x5D46FDB6709CAD0EULL, 0x525047692C58789BULL, 0x4DC711041C632432ULL, 
            0x540B19C4C09B976CULL, 0x565303BF719DEBD5ULL, 0x804503B9788B6C11ULL, 0x78BAAACC17519B16ULL, 
            0xFC13C17BCDD9AA64ULL, 0x8B455BB17D9D7BA3ULL, 0x72A64E61EDD2DB62ULL, 0xF0E7D6444B3E70BBULL, 
            0x15BFED99F3D47151ULL, 0x7F772FE4D6461374ULL, 0x50105E38270570E4ULL, 0x5C35B1A6506143C6ULL, 
            0xA0B29931AA1895D5ULL, 0x0AC0CB16CE3B78E5ULL, 0x60E355BE47B578E6ULL, 0xDF62753568212BD9ULL
        },
        {
            0x3F76C0FD8C481D76ULL, 0x2B239B853F16F37BULL, 0x84A949DC5A0BA746ULL, 0x5F4F759C0A1729BDULL, 
            0x3518F08B9D941E0DULL, 0x31560E1FAD8E9953ULL, 0xA82D285CDDEB21AAULL, 0x41F634A18A6BCDEEULL, 
            0x3AB8CB345E0CCECEULL, 0xD2555E5E8D0A341DULL, 0x6924C079EFEC26A1ULL, 0x829261D4B5F29D34ULL, 
            0xAFE7C215AB6E6257ULL, 0xC0F2D84B2018E56FULL, 0x2FB59FB9B8E5C4B4ULL, 0xD912D532F2843101ULL, 
            0x5D86B5BAA6C8004EULL, 0xBB7003F6CD2748BEULL, 0xA9C35B20045A1D60ULL, 0x9A2A142E7C84D858ULL, 
            0x65FF6AAC10E4C713ULL, 0xDD1B9DDE1D26F078ULL, 0x37D2B2FB7F508F32ULL, 0xB35EB3B246CA6C61ULL, 
            0x252FDB62AE19A839ULL, 0x8B7C686190AB2A00ULL, 0x681557790F2A5F1AULL, 0x51EE1CF7C691483EULL, 
            0x088360E0909E944CULL, 0xFD1E728A5319DE72ULL, 0x590E844CCDB78EE2ULL, 0x8522490387B85359ULL
        },
        {
            0xA682DA5A0BF9027BULL, 0x67F98171E44D52BDULL, 0x81FFDF2DE589F27EULL, 0xA424DCB236D02BC2ULL, 
            0xD799FE668618B0FCULL, 0xEACDBDBDDE165A1AULL, 0xD1EB8146139DE7E2ULL, 0x64C7E00715C6F161ULL, 
            0x8FD1DDACE009B034ULL, 0xDA4F6F8A8E1E362AULL, 0xFAA1F85EB5B61668ULL, 0x2A9CE7392F579156ULL, 
            0xA77EDEFB7E9508D9ULL, 0x8B5A0CADE241ADDBULL, 0xDEE0876CE8F2B219ULL, 0x25E158B204FE734EULL, 
            0xCDB93E33F502240EULL, 0x455FA65E0DB7F52FULL, 0xBE07E29CCA75F875ULL, 0x94530F8029B2B6FCULL, 
            0x358D4AEE00F22C63ULL, 0x4686848277B725AEULL, 0xB4225A8CAA6F43B4ULL, 0x264C79E4E51B3AACULL, 
            0x12E398C8BDBB470EULL, 0xAA2159D80245CC92ULL, 0x69FFFAE9A20CEFE8ULL, 0x1B037F66AFC559A5ULL, 
            0xDCA7359AA9D5B409ULL, 0x40ADE759EC991C79ULL, 0xB919182CF7713AD1ULL, 0x08575965B1D228D2ULL
        },
        {
            0xA944D914B59D2736ULL, 0x75ED02B7F982F15BULL, 0x7D02C2B3951964EDULL, 0x19765F57248F0E5AULL, 
            0xC7BD1AC5BB514213ULL, 0xB274F08C65BF6A25ULL, 0x8656C26B8761AB44ULL, 0x6B22750F2CE30A68ULL, 
            0x01C4AB8341CE4B5FULL, 0x4BDF660825EEFB45ULL, 0xBE1F78A1335E5A50ULL, 0x7C7F378848927516ULL, 
            0x3DACB01F7FDA22F7ULL, 0xB14567E8DABB491DULL, 0xBCEAFF1834CB6B17ULL, 0xA2483761D049AFC1ULL, 
            0xD4E03558CE91B5DCULL, 0xCC58576F933FC91BULL, 0xE9EB96A1826AA954ULL, 0x218C02D567847CC0ULL, 
            0xB0356275000AD055ULL, 0xC0830725879D6543ULL, 0xDAAC9144D4456939ULL, 0xCA8B985CD475FA2AULL, 
            0x3C3C66B77CCF721EULL, 0x001E2F2224758719ULL, 0x15BF3231416917FBULL, 0xBD3BB066DE3CCD3CULL, 
            0x2B95353064CFADF5ULL, 0x2058DAFFDFE343EDULL, 0xACD3DC80E82ED5ADULL, 0x91D6440F699571BCULL
        }
    },
    {
        {
            0x6DB7039B87AC5B71ULL, 0x5B44AB06D8963E14ULL, 0x3082CF3C1CCB040CULL, 0x13F7C91969ED353EULL, 
            0x8996CA386CABC9C4ULL, 0xEE29CCEE37E065FCULL, 0x5A3252DEA0EF0F12ULL, 0xCDC45B8CF35B8A98ULL, 
            0x6D7A740601CBC944ULL, 0xA11891197E2C1D46ULL, 0x47A815A14F691543ULL, 0x920814A11E97A61DULL, 
            0xE5BD857F0117CC97ULL, 0x94922CE357C1E3D3ULL, 0xEFDD283DCFDC1248ULL, 0x23F3C7083D2F8246ULL, 
            0x98C3434370EB984DULL, 0x2CA056577608F892ULL, 0x9EA7F473F966A320ULL, 0x691546F80376FDAEULL, 
            0xB4C1635F0B8289C3ULL, 0x685C0EB83DF1A382ULL, 0x1BD5CA4B14BD8B17ULL, 0x5E2A0A8AC1FE0127ULL, 
            0x5CA3919BE153ADF6ULL, 0x31EB35202D2E2F97ULL, 0x5AEE93247E03C2A9ULL, 0xD25561AD5FBF0B70ULL, 
            0xD599E5F26FC65B68ULL, 0xBC12020A89A426BDULL, 0x875593763EF6422AULL, 0xCF57EB53F2085026ULL
        },
        {
            0x3F34BD1E8FD653E4ULL, 0x5268BB8C783E0B8DULL, 0x0AC3A870FAD1790AULL, 0x7F84D726C2FF6F4EULL, 
            0x63449CA70676D489ULL, 0xF03E0F9C282B979FULL, 0xAB53327B0F8B938AULL, 0xD735D2260578A910ULL, 
            0xE01CACF032ABDB20ULL, 0x873A46ECA840CDF2ULL, 0x97B8BD683948B6F7ULL, 0xE56D68F47000796AULL, 
            0xC3A09F7D4FF51404ULL, 0x210005744E2EA96EULL, 0xFA3988939D882F81ULL, 0xD3AE4D2481CD355FULL, 
            0x951F7D7082DC8DE8ULL, 0x5C79D05D8923BB1BULL, 0x0C06605E41C089A9ULL, 0x722613911186A46BULL, 
            0x7A8DB66D51179190ULL, 0x01BE93F6DCEA14E4ULL, 0x383E60FBA4E30611ULL, 0x4B0A0E69B5370BB5ULL, 
            0xF6D4972DC0CB09C6ULL, 0x29B5E28B3A0EA959ULL, 0xA5A3D24A6A99F9C0ULL, 0xCA41DC3861D2CBE8ULL, 
            0xF11CA9D665685A11ULL, 0xD26684FE1487BA71ULL, 0x47724AB598F2ED47ULL, 0x3BF3A019713D64CEULL
        },
        {
            0x7035C59FB88DABEFULL, 0x1893F84FEBA9C591ULL, 0x76FA1B41A4BF1893ULL, 0xEDF0378FDAB42297ULL, 
            0xA5BE71F80937E050ULL, 0x3B87F194052AAABBULL, 0x6C00DA79616CDD92ULL, 0xD1EB238025407212ULL, 
            0x4EE551BFD2E7D9DDULL, 0x44E2F0929DCC4FBDULL, 0xED64CF24D72D9CF5ULL, 0xAB0E2474C7A2A782ULL, 
            0xFA984B63BD72B3F5ULL, 0x837FA5729541963DULL, 0x46CECD73915D4720ULL, 0x2F5619D7DD4C251BULL, 
            0xD662E9958E6E08BBULL, 0x757133375520112CULL, 0x08763A344C74C46FULL, 0x400001F2D74ED19BULL, 
            0xA28E1D545C2B9C50ULL, 0x395378A7D7B54502ULL, 0xA6FB1E19FC5747D9ULL, 0xF98BD3282D195393ULL, 
            0x7D07CF067BC93734ULL, 0xD335F9DFF5A52953ULL, 0xD63393F8665DE6FFULL, 0xA5308946E9C3C1CAULL, 
            0x75AF6EFC4DADC183ULL, 0xC9DA0DB264EACC61ULL, 0xA1127AA68576DBD3ULL, 0x85B91D78D69DE66BULL
        },
        {
            0xA6F2F66F959DA2E6ULL, 0x733F483959F10B15ULL, 0x8152AE8CE188D326ULL, 0xE1BAF26EC8F28B84ULL, 
            0x09D58DFFBD0F38DCULL, 0x34748768A8E08854ULL, 0x5EFF2E74F712D409ULL, 0x601435D5C12BB8ACULL, 
            0x7FEBC1F5BAB83CBCULL, 0x781210DD2E0E3438ULL, 0xB33218FBA44BF77CULL, 0xA39832BD1F3FE886ULL, 
            0x12C103F5206E9813ULL, 0x16D3183E645AB3E5ULL, 0x200B9B84C744A409ULL, 0x731BE1358D521680ULL, 
            0x9A53C48778481E52ULL, 0x68BB8AF34760C838ULL, 0xA96B0C5384A35323ULL, 0x91BF89EBC30DF372ULL, 
            0x32BF1B712677B1E9ULL, 0x40255C236BCCB427ULL, 0x7E5B11419C011F11ULL, 0x46F2DF8CF857178FULL, 
            0x80E1F9545EE2FCB8ULL, 0x44EC604FEAEC0820ULL, 0x80E50EB068C9CA06ULL, 0xA3FDFB59BED797BDULL, 
            0x7F11AD964A518D62ULL, 0x68B58B990FB25E69ULL, 0xE0277B390C3C0CE8ULL, 0xEB9437FE832B6E53ULL
        },
        {
            0xF7F7E37420D3070AULL, 0x2D8BA52D0E9F6DD2ULL, 0x8C2ACB2F1B536552ULL, 0x410D955081D8E713ULL, 
            0xC3F685A0A084AA22ULL, 0x790F4DF6FE148C59ULL, 0x08C8E069C319049AULL, 0x66D96A66C96D86E8ULL, 
            0x2F51CAEBDAA73487ULL, 0x54ED39A30DF723BAULL, 0x2FFA486FB3324F61ULL, 0xAE1244A6E6DC44A9ULL, 
            0xCC30A42E4B541F4EULL, 0x307E0E0ADEE4CFC4ULL, 0x99E13C8CC8B7F258ULL, 0x55293284C2F3DFDEULL, 
            0x92ABF27D8BEEBB29ULL, 0xCDDF2084AB828779ULL, 0x73AE743F745F25ABULL, 0x79C007A0AFC1926BULL, 
            0xE84845492AB9BB9BULL, 0xB468130F65C51136ULL, 0x2E663AF7B399EBFBULL, 0x4E826E861A81DFE3ULL, 
            0x32942F31DFE42A23ULL, 0xA934151C3CC5FA6DULL, 0xE6A6E9A2CE40FF4AULL, 0x23C76D1F4EFC4C07ULL, 
            0x440B671F1A667F6AULL, 0xCCE41A5B3592393CULL, 0x61215A766B377C11ULL, 0xFAFEC218370E32B7ULL
        },
        {
            0xBB1FCE9BDC42A33EULL, 0x99AF25817463C874ULL, 0xCFFB0756A2849B8CULL, 0xBD1F8F27077C667BULL, 
            0x70FD2A6AF1AC8866ULL, 0xB9866285B68D20E7ULL, 0xD864EB369ACC976DULL, 0xBF0B87D8005764A3ULL, 
            0xD23CD491434E2126ULL, 0xE40BBD357FF8145EULL, 0x2E8DACDCF804DC2BULL, 0x0EB18BFC922A5527ULL, 
            0x4B094874F89BFEBCULL, 0xE8905C261A9014F5ULL, 0xC2B4D034BCDE72E0ULL, 0xCE4BE2DB0A7E7F4FULL, 
            0x16332EDCC767EC41ULL, 0x2F6827B2358BECC4ULL, 0x08A1E99A4E7921BCULL, 0xE0FE1ED9C6DB57B3ULL, 
            0xE1CBDD52768522B2ULL, 0x85C20A14B81DDA84ULL, 0x506787846AA3D27CULL, 0x1CD45830834074F1ULL, 
            0x5DC387BC0F6C3F92ULL, 0xF3AFC3EEC2E7123FULL, 0x44542F7A86ABCDBCULL, 0x07AF984F42C0C431ULL, 
            0xF3802A1C7A6A1214ULL, 0xF43D9A95B019E39FULL, 0x7931052B374F84EDULL, 0xAB6E8BAD0E2428EAULL
        }
    },
    {
        {
            0x8317640C6C809D75ULL, 0xC8B4704538508898ULL, 0x454E766600656009ULL, 0x6769FFF9035A83D7ULL, 
            0xC9492C854751C10CULL, 0xDA61B353228BD5FDULL, 0x0343F7DAB0CF9626ULL, 0x4E98D0591791B2A3ULL, 
            0x62CF2108EBB29B5FULL, 0x908EA33B6AC20871ULL, 0x535D61417F8EF24BULL, 0xC00A2A04ECA4B8BBULL, 
            0xF5B58082ED56A951ULL, 0x628C3280BE356110ULL, 0xC092029EF39E28F5ULL, 0x2BE3A7DFA8A1130DULL, 
            0x3ACE8F0201D1B9FBULL, 0x02941177130DF47BULL, 0x89AB1F904C36853CULL, 0xE41B4C7CFA65787FULL, 
            0x714A6DD4D1EA96FAULL, 0x718A12230504FAF1ULL, 0xC0E418702D669F90ULL, 0x7AA92C8EB4EC1EBFULL, 
            0x329F256F8379E188ULL, 0xB7AC9DB954D64D30ULL, 0x4F11D22026411329ULL, 0x899CC63A31409116ULL, 
            0x6E2171E158B06D80ULL, 0x78B46CB1CBE66F9AULL, 0xF25357EA882F02E8ULL, 0xB7672DBE3EDDD399ULL
        },
        {
            0x28402BAE39418191ULL, 0x0EDA4DCA6C8D2234ULL, 0x3DA0FB4452FBE1F2ULL, 0x66C1E4532A15F643ULL, 
            0x8A14F4E00513019AULL, 0x3522AAF696797533ULL, 0x1F3480AFD54F463EULL, 0xDE18C61018FAF1A0ULL, 
            0x7728EA8505306436ULL, 0xA4C86CFB55A188BFULL, 0x32C63236FB7B9BD2ULL, 0xE39F7C5030F7FD64ULL, 
            0x52E74865EBC3C04FULL, 0xD60A869D38B2EA79ULL, 0xD5A9EF084B5B4BA0ULL, 0x133AB5239C45147DULL, 
            0xAB5828BA73FD0C76ULL, 0x6C278C1BD6C22A4EULL, 0x6CAB556171CB5B36ULL, 0x7F99BA3B179207FBULL, 
            0x4512A1FDE09D0B67ULL, 0xD2647E13CC1134C1ULL, 0x5E432E77980BE0CCULL, 0xF8C4C6107CE21B2CULL, 
            0xB15DB8B64366E720ULL, 0xE435CE00DFD61A7EULL, 0x0E296F7F468B4D2CULL, 0xFCD98E89D7A061E3ULL, 
            0x11233A24035919ABULL, 0xB4206C560C68082DULL, 0xE84784F93CAF0915ULL, 0x97646E3183B655B5ULL
        },
        {
            0x56FD5CF490548CA9ULL, 0xDE73D4D260A2AAB9ULL, 0xA17D00847BDBDBA2ULL, 0x5FC7866E8E429CF4ULL, 
            0xF5610AB9351DA12CULL, 0x56498E5C5AB28E44ULL, 0xE542EB70D7D7706EULL, 0x68E91B6C97F170D4ULL, 
            0xCD879167B28C7D53ULL, 0x9FBAA4B4C485B687ULL, 0x8C123C40DFD0F80EULL, 0xAA7C030E4BDB5950ULL, 
            0xC95610011F5E8E27ULL, 0xD29AE3C287E13D8CULL, 0x9FB3EF94B025434EULL, 0x59402F7FA602F0C4ULL, 
            0x2309913991F2185CULL, 0x547654F5ED86FDBDULL, 0x3F266B23ECEFFBC9ULL, 0xFA5E7D1AA68A9BBBULL, 
            0xC28544613337C41DULL, 0x23E844BE5A431551ULL, 0x17B3D5BB18833023ULL, 0x28C3969C1DC35EACULL, 
            0xB2B08C6ADA70F22EULL, 0x77743E791317BBB0ULL, 0x7657C500D25E6D95ULL, 0xF19FA71106F52CA1ULL, 
            0x486DF4C64FA48FC4ULL, 0x9950671A04362759ULL, 0x235A0CDC4DCB8003ULL, 0x452849072902995DULL
        },
        {
            0xF3D4BE60FF82FF11ULL, 0xC602CD86D4DF8774ULL, 0x7F73475EA973098EULL, 0xA600C308AB55C476ULL, 
            0x9F985C03E837A3BDULL, 0xB51C0B5A32E4E2BAULL, 0xE693C9C5C600AF7AULL, 0x18C9FB6E6DF98B84ULL, 
            0x201AD67EB747C01BULL, 0x7A2149475237ADB6ULL, 0x5F52D2AE6F0997A3ULL, 0x52802F21706B6E47ULL, 
            0xA97077DD69D250ACULL, 0xDDCC8B663E8AEB29ULL, 0x1125B26B88668AB5ULL, 0xEFA4D4E6A690533AULL, 
            0xB661AC8794C30FA3ULL, 0x61585E919D7A6304ULL, 0x7CE7AB7EF61FFB94ULL, 0x63400DBF4CD40407ULL, 
            0xA4B780507843C708ULL, 0xE2A93229EB1DF2DFULL, 0xF3244F2DBB794F6AULL, 0x057D2DF9A78027FCULL, 
            0xB84573E696ED780BULL, 0x1F72686C5C07C203ULL, 0xE4A6E1B803645B32ULL, 0xFA94756EB6007F2DULL, 
            0x9986864355E40125ULL, 0xB101420D6DAB5E6AULL, 0x6D4BE2DA94E2B12FULL, 0x3D6D5C62A4F0FF46ULL
        },
        {
            0x5795412592B0921FULL, 0x5EE39C3912D7DD7DULL, 0xB40119957D6A0D83ULL, 0xE182B0994BA75131ULL, 
            0xAA6BBAFCFE9E8851ULL, 0x64068501966B54EBULL, 0x793171D24AED9E28ULL, 0x52CE3DC339EE2751ULL, 
            0xFF53F6A2B5019984ULL, 0xB9EF0FC859E98BC5ULL, 0xDBCFE4F34DF0632BULL, 0xA399EB0260925424ULL, 
            0xBFE1D37B3C6D64EFULL, 0xA2F543C91B36FA6EULL, 0xC03AA44C76B5CCF9ULL, 0x50574F183C489C3DULL, 
            0xCAC08A797A47CE51ULL, 0x74D715B81720D652ULL, 0xB8047889AAA09210ULL, 0x0B67BF640FD41AD4ULL, 
            0x49DCE70752C3701AULL, 0x5056504AB7D75994ULL, 0x57D6F66D68A518C0ULL, 0x0BE9DAC51CFDA7D0ULL, 
            0xB7E713FC0C4079A7ULL, 0x5FF84C8EE71ABD23ULL, 0xDA45C6E61FDB822FULL, 0x4B33495D1BA54AA3ULL, 
            0x209034AD472197E8ULL, 0xEAB6D5166586079EULL, 0x60D1B467A04F990DULL, 0xFB80463F09FE0E46ULL
        },
        {
            0x12CA505A49BCEF34ULL, 0xC5B0A8D7F9D2096CULL, 0x848F1B9905C60999ULL, 0x1FEE5082C28737A3ULL, 
            0xD2A0042AD35CCF17ULL, 0x5275EF41F59AE044ULL, 0x9EA8DA848D628745ULL, 0x1311B50D12CCE1FFULL, 
            0xFC0DBF02D0465C8DULL, 0x360C15F3A7597159ULL, 0xEE60D5FDD2221C3FULL, 0x49CD70A59FC08C06ULL, 
            0x6C8EA947B99F76AFULL, 0xEBB482B6DC45E5B1ULL, 0xE79CBC216C7A6768ULL, 0x2BE0A8ED7768D1BEULL, 
            0xCE9C319A7140BACBULL, 0x64E86E835B295707ULL, 0xCCF71039B1B50093ULL, 0x3A1B8777AC14EDE7ULL, 
            0x9B0F12E60B6B849CULL, 0x5254C970411FB810ULL, 0x3371B79A5470B50EULL, 0xE4FD0E5E57258F13ULL, 
            0xAE9CA3D2487A597FULL, 0xDE7D086AE7C48CD0ULL, 0x982765361FC705A0ULL, 0x159BB4863CCBBB99ULL, 
            0xD3FE2B37B031C007ULL, 0x0114CA6FDADC85A1ULL, 0x25952108F238DD50ULL, 0x63E84E8B3DCDE873ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeyRotateAConstants = {
    0x49A835A03D42C33FULL,
    0x3EC49F519EAC4FBCULL,
    0x8CB97D48C8D18D46ULL,
    0x49A835A03D42C33FULL,
    0x3EC49F519EAC4FBCULL,
    0x8CB97D48C8D18D46ULL,
    0x6936891C682ED4C2ULL,
    0x7D84A9A087AF265FULL,
    0x89,
    0xDA,
    0xEE,
    0x6E,
    0x8E,
    0x66,
    0x85,
    0x0D
};

const TwistDomainSaltSet TwistExpander_Mimosa::kKeyRotateBSalts = {
    {
        {
            0x39FE09C3F512CC42ULL, 0x9BF8C334C8E70F25ULL, 0xE70061A774D7028FULL, 0x04C5AE85BC6EC8EAULL, 
            0xB21F9019ADF44107ULL, 0x3FCA28EBB12D5C4FULL, 0xBAE36410400D5DDEULL, 0xAFA30341D8608945ULL, 
            0x245AC3578CE61F5AULL, 0x6C1ECEC5702D6A00ULL, 0x5BA0DABF8B4695C3ULL, 0x8F923A11B37F52E7ULL, 
            0x8A516FDBFFDA9069ULL, 0x8A23E0ECEACFD104ULL, 0x206B015D9B7FF6C4ULL, 0x5F559C7135BE6050ULL, 
            0x58CDEADAC499D1CAULL, 0xF4BF13669E3BADDAULL, 0xBDB922BB7A80CC3DULL, 0x6B0AD17C1DE2D43EULL, 
            0xC3E0E777E29E30F4ULL, 0xAC014CD8B250FF3FULL, 0x2899CEFDCD5774E4ULL, 0x0F42A2C378A93E44ULL, 
            0x1537AD9F17D85D69ULL, 0xBC61B03BCEC73902ULL, 0x381853B6F25A56CCULL, 0xF8846B2DA8916339ULL, 
            0x9E948DA3AD3D836BULL, 0xF961E418BD67C674ULL, 0x37648FADCBDB67ECULL, 0xC8C408A3D3066FECULL
        },
        {
            0xF478C83EADC8B6ECULL, 0xFCE86FCFB053DC08ULL, 0xFD34325D676DDDB8ULL, 0xD09D6074FAD428B8ULL, 
            0x9258EB7C35879141ULL, 0xE41D2183DCF32F40ULL, 0x5D07133D2B63CC35ULL, 0xB80C142B502E17ACULL, 
            0xA2B46374AD7251CEULL, 0x78F13FF4FEF58FCDULL, 0x8E13F90384957906ULL, 0x7863DE16ACE13B24ULL, 
            0xC3C413C96450BB40ULL, 0xDC325B3BF36E83B5ULL, 0x4E94EE5FD1DEC27FULL, 0x1E51643DF280D59BULL, 
            0xFD3E9AE701E8F34DULL, 0x30A437B509D9780EULL, 0x6D45B9193308BCA2ULL, 0x5FD291D9379A9AFBULL, 
            0x21576DC106D855C0ULL, 0x3D9F6F53D2299C3BULL, 0xB6454FD7FE1D31A0ULL, 0x1AF6061884E5451AULL, 
            0x773BFD78E9E47B93ULL, 0x9D4AB89E9F54693AULL, 0xD2A73C9BA6866010ULL, 0xA20DDE9333D86647ULL, 
            0xCC63C23D4FF98957ULL, 0x8A81F57FDCA7AD52ULL, 0x73C99FA32E6FCCEBULL, 0x2AFC4AD10719A577ULL
        },
        {
            0x2DA3A70AB24292EDULL, 0xA110EBD311A646C3ULL, 0x7D53E0036D2935C5ULL, 0xC0B097C2C01CBCA7ULL, 
            0x8B7774B1EBEBF73DULL, 0xCE7642F76DFB5E51ULL, 0x08A27B779C1F1DDEULL, 0x0A26408E66D7D459ULL, 
            0x01173D87693F5AE1ULL, 0x3B7D0EE7DD141818ULL, 0x2F73A2F3FD40A4D5ULL, 0xFEE191750B2F3D34ULL, 
            0x841150E242ED2359ULL, 0xE791A848B4BF8141ULL, 0xA06EC08504FD8E08ULL, 0xE61DBA26E2FEEDE6ULL, 
            0xD92464B8EEB18C86ULL, 0x925DF23D971C5338ULL, 0xB6AC15F6197B7585ULL, 0x2728E8BC5BEA11D2ULL, 
            0x3B96020E513DE5E7ULL, 0x638DC4842F4D41AAULL, 0x646436B5CFDC3C7BULL, 0x26A68DBB9B7F7537ULL, 
            0x4CA039213589C9C4ULL, 0x9C48079E7F810E28ULL, 0x0B4552E05FBA46E8ULL, 0xDECEEAEC5118D0D3ULL, 
            0x07E1E023CA0944C5ULL, 0x3B869181DE4228AFULL, 0x899138991FB0061FULL, 0x7943C4C396BDB684ULL
        },
        {
            0xF07B558601071695ULL, 0x25852C1CF91FE556ULL, 0x4B93B9D7B09827AAULL, 0xBE71E82B0B34FDCDULL, 
            0x9FD4A843B3BECDB4ULL, 0x7CF1D6DCC77C058BULL, 0x2B60B93C344D4480ULL, 0x45D00B8445F61B4DULL, 
            0x85BF7FBFF2BBC0C7ULL, 0x0BC46C7815E1473CULL, 0x7F45B3CFA93E83A8ULL, 0xB60E7B7203E92EB3ULL, 
            0x1984AF23D57E6D30ULL, 0x71E46BA62CB11F04ULL, 0x51940D21729A1A54ULL, 0x531358C521875E8BULL, 
            0x00D503BA0643D59BULL, 0xF15AB5BD8A0CDDB4ULL, 0x01D6768EAD7BCB2BULL, 0x437157BD16FC7EC9ULL, 
            0xAD4100591096CA64ULL, 0x86AEE7BD6681C9A2ULL, 0x4C11E066BBBDB044ULL, 0x5BFB04BCEB05F53FULL, 
            0x90B181E56A2A9FB2ULL, 0x9B76D9AEA97A0222ULL, 0xD941BAE1B16EFFBEULL, 0x14689C74253A2479ULL, 
            0x4632C1A99DB2BDDEULL, 0x48E65E80C3F848B6ULL, 0xD642693EE766294AULL, 0xF4D067E4AD66740BULL
        },
        {
            0xCCC482359EB478DBULL, 0x4400248025E1CE7EULL, 0xCEBF07A0BAAC12B9ULL, 0xDF398459C8BB31FBULL, 
            0x662C03EED5F7C04EULL, 0xFDDC405C4C349BF2ULL, 0xD6BF899C9126BA0FULL, 0xFC9EE367AC5F7C39ULL, 
            0x4275977ACCC31A06ULL, 0xABC5FF5A838A5BC9ULL, 0xA0DF47BAA01390F3ULL, 0x4FE6E5B35733636FULL, 
            0x0DB56A2819542623ULL, 0x6CF7322D8A0C4817ULL, 0x6B0D51B4FF09903FULL, 0x41070C610DA72A37ULL, 
            0xAA3D5E04AD9FC888ULL, 0x3AE8977FE5985490ULL, 0xBA4B9477ABDE66C1ULL, 0x3EE4B6B86B70920FULL, 
            0x4C539894813B7969ULL, 0xCB39E7E5188545DCULL, 0x8DE27CD3D6414D97ULL, 0xCAAB0E6DA825518FULL, 
            0x1A45BE79C7308307ULL, 0x2DCDBA8E12FD8BBEULL, 0xA3F039923B920022ULL, 0x74CAA88EC3FE5B48ULL, 
            0x2FBB1042C7D5131CULL, 0x7E5EEBF053980823ULL, 0xEB63A0C2C4CA9BB5ULL, 0xC1F917015D1FA0A5ULL
        },
        {
            0x49C13E288A39D69DULL, 0x38FBF607C9923694ULL, 0x842455A9161E8424ULL, 0x86118F3A88D50C5DULL, 
            0x9393BC952E48C112ULL, 0x95DB9F39333ACD80ULL, 0x3758E95C2FB94902ULL, 0xC0B179F3FECCB9DDULL, 
            0xFB20BEBF9D41720EULL, 0xA05FEB428B2D6868ULL, 0xA0AE493BB89E4107ULL, 0x309B3E589432F979ULL, 
            0x56BD72FB9B24F770ULL, 0x051B4BFFA7308704ULL, 0x962B1B9DCCD11F4BULL, 0xCF6F3564FF66563BULL, 
            0xBD1F3B286B77603DULL, 0x232DC46331D805DFULL, 0x7351BA7064624564ULL, 0xA5D6159AC1DD36E8ULL, 
            0x534C0FD80DAC145CULL, 0x6E99ECD8BB3C6EABULL, 0xE0BD364A437A2065ULL, 0x38D08DA2ED23C81FULL, 
            0xB8C84451AB8C4371ULL, 0xE4E11B1680585C38ULL, 0x147F95D894FC0BA2ULL, 0x223F0C77A39ECC8FULL, 
            0xEE7DE9472D870B7DULL, 0xB6C36FF17163458EULL, 0xBED4F4B790AAEAF8ULL, 0x66D47FD1BE701A60ULL
        }
    },
    {
        {
            0x41A1245FCFF14E88ULL, 0xE8528A69C19E860AULL, 0x5DD0F3B0EC15E061ULL, 0x80E17067EB090AC8ULL, 
            0xF2D150448866F41DULL, 0x14A69DB7C2A5850BULL, 0xC2BEDB5AB98FFFAAULL, 0xCBCD937DD22CA68DULL, 
            0x9D80CC47B3A83586ULL, 0xFC21B94CEB0E3CE5ULL, 0x057113BAF2A328DEULL, 0x7139C5C9D1BDA5BDULL, 
            0x10175033B8DEB80EULL, 0x33B3A6FD2CD474FEULL, 0xA40EB8554C7E7605ULL, 0x3DC38B30D368E685ULL, 
            0xECCB3490CC63B078ULL, 0xEC9EEAA0DE29AA0DULL, 0x94A0FB4225DB02EDULL, 0x101B566BEF7CBADBULL, 
            0x9962469D2FC81A65ULL, 0x97A52FD0482B9E4BULL, 0xE4329C62432AC45EULL, 0x093BC42EDB62452AULL, 
            0x6665337256562E0CULL, 0x162B64441F4457B1ULL, 0xD9C67F01D1B39B6DULL, 0x3D01DFA441B2CE77ULL, 
            0x2BA8ED593113C13BULL, 0x6C19485EBAD6A56FULL, 0x703CB9ACA405B9B8ULL, 0x62857478179B6C5CULL
        },
        {
            0x2CCCFCB0483A6578ULL, 0x4F95B36D3498E9D6ULL, 0xA51F997E4344564DULL, 0x3DE06B27F679E61DULL, 
            0xD1BF1D23C25C8714ULL, 0x63EAE38A2F332277ULL, 0xEAC7BC901428FE94ULL, 0xFE4D89E3F89F0CC3ULL, 
            0xAAA246FEC1D1ECACULL, 0xA8B9B5390161E1D0ULL, 0xB5BBE09654971287ULL, 0xB282FF2E7BD994A2ULL, 
            0xFC99AE8FC89D39BFULL, 0xCAAA3574EF558E7DULL, 0x1D15AE7730696BA5ULL, 0x66FB8F99A931E18EULL, 
            0x08087C5C7A73B972ULL, 0xF17C96F6B769CF6CULL, 0x08C5AB5A8E66F341ULL, 0xE9D6F422B191F2CDULL, 
            0x8246D6A2D7266337ULL, 0xE717EB0416A7E62FULL, 0x24FF50D39EACC1C3ULL, 0xCEDEC2CB5C394FCFULL, 
            0xE071E1E3EA761446ULL, 0x752FC064DD370B21ULL, 0x69B817568B75C410ULL, 0x4A3C0D891647C1ABULL, 
            0x954AE72402D7E409ULL, 0xA469C9A1F2BAEA29ULL, 0xBA4B3C58AC3D9060ULL, 0xC41E46FEA9D263DCULL
        },
        {
            0xCDB49F56BF9E938AULL, 0xCAE848601F4F4B39ULL, 0x566C5EA99C4A03D1ULL, 0x24B33FECD52EA915ULL, 
            0x21780D82E47E8AEEULL, 0xE32E4DF58A9165C5ULL, 0x0D2EE23F4B2670E6ULL, 0x3420FB035CE9FFA3ULL, 
            0xF6A5A9D9B0E5B5F3ULL, 0x1A0153F3F44D5F15ULL, 0x702F2F76A44324ABULL, 0x4D33CBD1DECCAF5CULL, 
            0xE02D29C70ABA2ECDULL, 0x34ADE36C8AD10EE2ULL, 0xD2301ED96F07282BULL, 0xA7AB2C4A2DCD363CULL, 
            0xEFF9ED66E0B51484ULL, 0x2421E7D6E8DACB11ULL, 0xEEDC5EE924770BE5ULL, 0xF19F89C866FEADF6ULL, 
            0xF037BD038A96DA96ULL, 0xD5754C572414247BULL, 0x2AF5DD5FF5326D8CULL, 0x1FDBDCE32868CDA5ULL, 
            0x200D671A791A4DABULL, 0xE83385349ED4BF9BULL, 0xC299C49E77026EE6ULL, 0xE1301646D79E62BAULL, 
            0x372B5D5E62808D70ULL, 0xC892853EA6552634ULL, 0x55CBF0C37FAC2849ULL, 0x60AAA9EF87180C79ULL
        },
        {
            0xAD166D31E1E376E6ULL, 0x7759FB81B28520C3ULL, 0x5BC87887512552DDULL, 0xD652CDA751E2CEC9ULL, 
            0x746501FDDFD89C0AULL, 0xDCBEA148A014FF23ULL, 0x77E94F63C3665B1CULL, 0x2CAE66332A80D804ULL, 
            0x75969A09024B42FBULL, 0x15A4420C18BFE24EULL, 0xA92772E4633A0E15ULL, 0x7A74184C13CA4C4BULL, 
            0x94264684EDF44949ULL, 0xA4C2E21D6FA2C03BULL, 0x16A60E19C5D5883BULL, 0x66BD211D9BF27A5FULL, 
            0xFE42F9E501A3C0DCULL, 0xE59A390905D7F403ULL, 0x7AB11DB1A5DFD6F3ULL, 0x14416F271C3ABE30ULL, 
            0x3B705E3069E7B14EULL, 0xACC58383A8AF544BULL, 0xB555BE24D023DF32ULL, 0xDA291AA9B9F0ACC4ULL, 
            0xD6BFB49664073E54ULL, 0x7CC65087671F9D4DULL, 0x92AF59E6123F3E39ULL, 0xD410C391626A68EFULL, 
            0x5117D9DC91237157ULL, 0x37A144B0AE1FD7A7ULL, 0x056258FF2A913AFAULL, 0x09ED3FF5E55DE82FULL
        },
        {
            0x5573AD4A4D231D0CULL, 0x95A4C094EEFE4E88ULL, 0x552D0386B2B4C153ULL, 0x34D6C40B385B10CBULL, 
            0xD5396B97D6AEEFB2ULL, 0xFC678BFBC73E29E9ULL, 0xFBE64FCD0AC5CA70ULL, 0x7848AE531373A9F0ULL, 
            0x9FEAF3BF9DD2362FULL, 0xF93BB9C7218F31D8ULL, 0x7DD710371EA65942ULL, 0x5C41E2FC6A56D4F9ULL, 
            0xFA1B90CCA8D5BFB4ULL, 0x9CB5C5D0B7608383ULL, 0x5FFADDA442204DB1ULL, 0xE95A693580D00F59ULL, 
            0x0616170E856D5448ULL, 0x0F5F128F9AD132B2ULL, 0x52DFD32250DFFB5EULL, 0x7B7B5FEAA3432B8BULL, 
            0x902ED9C7B6414DD8ULL, 0x2775D57DC2B4E56DULL, 0x295D2179C74EBEC0ULL, 0xA02C369EB3BC2CD5ULL, 
            0xDBCF817D6988CF63ULL, 0xCE9D162122144B7CULL, 0x351E6D2C48B96EA3ULL, 0x0F214BCB1ADFDECCULL, 
            0x9BD4BDEE39442B84ULL, 0xE832D364C8E8C2FBULL, 0xFA1A605FA3D70328ULL, 0x19F8D37841708048ULL
        },
        {
            0x27EFF9F000A85485ULL, 0xCC7B7300B379ABC7ULL, 0xDB8F103D55003E58ULL, 0xF329255F9E28D183ULL, 
            0x151A1CC8E502A870ULL, 0xBCA8199E077A5700ULL, 0xB1138FF843210DB8ULL, 0x1E0635E0BF63A993ULL, 
            0x750E0CB309587388ULL, 0xE057EC2C1F36E8CBULL, 0xBBDEFBD14262E191ULL, 0x9EF9C85F12B5321FULL, 
            0x327C41E4AA7B792DULL, 0x7C08CC3EC473B1DFULL, 0x69674F7FECC211B5ULL, 0xDBFE390DD110AAFBULL, 
            0x69EE36A7A97E0FB1ULL, 0x8DB794BEC9372DC4ULL, 0xAF4D7B4FD34A323EULL, 0x714FCA03CAFB905CULL, 
            0x78F5BFB083769F02ULL, 0x7EE62BDD1417DD97ULL, 0xF9D36DD0D390E555ULL, 0x2322F4DFA644C2C8ULL, 
            0xE4EBD3F9FAF2FB51ULL, 0x1DEA2F95560C680AULL, 0xBAAA88701CA015C4ULL, 0x7FDBCC5DFD49A6C4ULL, 
            0x7C2D8B074EA2BBB0ULL, 0xB7BF1F9EC1033B17ULL, 0xE222E8F66A3A821FULL, 0x7475D90BAF72AF23ULL
        }
    },
    {
        {
            0xABD28E97917D047DULL, 0x37187D1197C65AEEULL, 0xF6D183FFDC2331F4ULL, 0xE7AAC72AABFF1493ULL, 
            0x7C0D55746E102582ULL, 0x42E0FEB1250A6B36ULL, 0x83DD55FDFC01252DULL, 0xE1937C3EE42C5DEBULL, 
            0x174A11A458FE5E8FULL, 0xCF3BB936B627E361ULL, 0x84C81AF901B97208ULL, 0x85981647D900D565ULL, 
            0x44A1711E3001DA13ULL, 0x76352DFDACD4F4BFULL, 0xBEB757770524951AULL, 0xCAF9C53450C4CF1EULL, 
            0x03A43E3103302AFBULL, 0x6B64DC06925298FAULL, 0x219A2579D78D96D2ULL, 0x0777781371BAA46FULL, 
            0xA14CEA00FF2ADC27ULL, 0xE451462AF10CBEC3ULL, 0xD21E7947F3F7B952ULL, 0x635E28A9C4E1F61BULL, 
            0xB3765184AB726705ULL, 0x423B3D70074FFCCDULL, 0xB32ED2B6A4A1C0E7ULL, 0xD3E5AA39FA931449ULL, 
            0xADCA63A52E3FF461ULL, 0x3D9C65D86BDC5C28ULL, 0x6EA7449C6CEECAE2ULL, 0xAA8A81B9AECFB586ULL
        },
        {
            0xCA3D483C70F94991ULL, 0x74BC1907A41DC345ULL, 0xDBD36D2670104D22ULL, 0xF067EC065FF903B9ULL, 
            0x1905DF12E27E43ECULL, 0x86749FE0BCE2E851ULL, 0xDE87DF664F1EEC01ULL, 0xE3BFEBE0F9A8F965ULL, 
            0x8CFB813F1817A8ECULL, 0x39F60E82E9F357E4ULL, 0x413709470C676BFDULL, 0xAB972197B497FEDBULL, 
            0xE24F3F84D74F3168ULL, 0x41CDEADD3CFC7A38ULL, 0xEE244AFFDA179BDFULL, 0xD580028D0901F7F9ULL, 
            0xD67B044E036CA4EAULL, 0xDFEC6F19902104D4ULL, 0xE505CDAAF466AACBULL, 0x28385942052D1119ULL, 
            0xB62117D5A3900645ULL, 0xF762E675477DAC49ULL, 0x63E53134DCC52979ULL, 0x2A28868BCB4C5479ULL, 
            0xBE61BC816DA1C715ULL, 0x629879C1ACDFDA18ULL, 0x8733BAB1D44BBE0BULL, 0x5870A0A185E26E00ULL, 
            0x739DB96E5E7A2760ULL, 0x2F3AECF76301F6ECULL, 0x6E2819D463600CB1ULL, 0xE9269FD11570DE66ULL
        },
        {
            0xBD69001BCC909907ULL, 0x91E7704637BF7C5CULL, 0x71D757B286F03994ULL, 0x094E16EC0ABB53DBULL, 
            0x8C0874F06C5278C1ULL, 0xB86D38E60032A937ULL, 0x80AF21424046D90EULL, 0x183FBD70B681AC0CULL, 
            0x432FEDCE4CE6181BULL, 0x57FC50C9D5F22C6AULL, 0x5803A82FE359DAC5ULL, 0xC5EF92E94E54A698ULL, 
            0xB12885AE250B0C62ULL, 0xF0CF4F9770399644ULL, 0xCAB90E36FA9E3D93ULL, 0xFB4FC724228A1540ULL, 
            0xC57A4DE18FCD29C8ULL, 0x23CCCF243E654715ULL, 0x35F9922BFD973AAFULL, 0x8D7D02444DD5D13CULL, 
            0xD4ACF2022EBBE803ULL, 0x5481BCF7668A182BULL, 0xD47551E783EBB0E6ULL, 0x4D407BFA4198238CULL, 
            0xA6F3DF9153D53266ULL, 0xA3E2994B7D204020ULL, 0xD144202CF58D216AULL, 0x64BA2890AD569848ULL, 
            0x36F5DBFDE65A1BEBULL, 0x9E76473208E4986EULL, 0x8B6706F1F928EFA6ULL, 0x6EDB6FFAE74843EBULL
        },
        {
            0x71CB53C9658F5992ULL, 0xD252BB6660B5755FULL, 0x378EB2D28FFCC815ULL, 0x8D0852C3825292ABULL, 
            0xFECDA043F092B0DBULL, 0x3ECED3ECCC72BF44ULL, 0xB842BB2EC30E8842ULL, 0x4B25D85DC5F077B0ULL, 
            0x0EEE9B44DA2E6BC0ULL, 0x9D6FA78F9BD27D30ULL, 0x31212CB00AA81075ULL, 0xFB89B256FB163E4AULL, 
            0x30ACB91ED46229D4ULL, 0x141E44BA9CD13616ULL, 0xFF66D11C2C980A33ULL, 0xDC2A3C9486E6D3F2ULL, 
            0x9663B2EC4D0A9D1DULL, 0xDC23DCE678B59600ULL, 0xBE19F13D5BB3868EULL, 0x99CCA4D53E49CB1EULL, 
            0x87A1C62D356813BEULL, 0xC0B3F2507DD1F831ULL, 0x8F9FDA67410BECBDULL, 0x5A3953C49207C9D0ULL, 
            0x48DFA8B152217B79ULL, 0xDBE5AA0610B17C72ULL, 0x431986A032FE434BULL, 0x85142FEF5F07CC9DULL, 
            0x05E973E32A0E6365ULL, 0x5D98F38B589BB4C5ULL, 0x996C7FF285C352B5ULL, 0x412C42E768196296ULL
        },
        {
            0x0E6E7B6D7E82DE8CULL, 0xB71A4000F74A48CAULL, 0x600AE0ED62EC66CAULL, 0x596E3F899BB32CEBULL, 
            0x3D03B052D1BF5487ULL, 0x1176462426D8BD1FULL, 0xCDA4491C42E8E49EULL, 0x28966F151431073DULL, 
            0x27130AF89ACA0782ULL, 0x334DC15A6C56496EULL, 0x6821B030FAB985A0ULL, 0xC9725CB57D8B9E2BULL, 
            0xE792117429D3E8D2ULL, 0xAB279FE36B683142ULL, 0xAD2D2E621F49AC60ULL, 0xBF30D353299E40FFULL, 
            0x4B5BCBFF4885D7DCULL, 0xB51D5F1312B36784ULL, 0xBFF541F0FB6B3DA3ULL, 0x18C7340A89E2BE95ULL, 
            0x23633FB006ACCC01ULL, 0x2D835C773A1455BDULL, 0xBF9A5E03F8218F9AULL, 0x8AB3DBBEC8EE1CE9ULL, 
            0x6576079C30E72ECAULL, 0xAF097DD9D48D39A6ULL, 0x319BAC81051B1B28ULL, 0x74A617A645FC82FAULL, 
            0x18EA2DE34386526BULL, 0x109053BC857A101FULL, 0x330A3144E66BA796ULL, 0xE05FA925ECE499CCULL
        },
        {
            0xD8C94F35E58C7670ULL, 0xC737E6C5CD3595C1ULL, 0xC0BDFAE7C6BFCEC7ULL, 0xA3CDF2A7A1263E9BULL, 
            0x9D8A1C7FC71388A5ULL, 0x18D7C2E52BEB5E50ULL, 0x147C1015624719F7ULL, 0x9F48F5E3EF0B43D6ULL, 
            0xF8FDB48970171AB8ULL, 0xBE0ED308204B9E88ULL, 0x56E4B51F81E6629FULL, 0x478ACBE279069311ULL, 
            0x6A7A5CB79B874041ULL, 0x43551CE7C058B23DULL, 0x092B0DFF47155437ULL, 0x29A9EE46F14DDD12ULL, 
            0x29F2E66C06585543ULL, 0x996D2C31FC023A79ULL, 0x28BBA90DC33BDA63ULL, 0x52665D07EF5FE1CAULL, 
            0x6FDC098F96569D72ULL, 0xDEF8458EE8BC5DB5ULL, 0x7E777762B7DA1564ULL, 0x6ED16178B1418963ULL, 
            0x1E571FA7891D7DCCULL, 0x506DE3992658456AULL, 0x18EC0B820809F1AEULL, 0x9579FF28487FF379ULL, 
            0x744F9B154023230DULL, 0xADAC732F395C7F44ULL, 0x1E5B345807A62451ULL, 0xB965FD71C9B61A66ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeyRotateBConstants = {
    0xEE420AC34366146AULL,
    0xC20ABA93E7820B57ULL,
    0x8C439B965B0AAB37ULL,
    0xEE420AC34366146AULL,
    0xC20ABA93E7820B57ULL,
    0x8C439B965B0AAB37ULL,
    0x05922BA590D65FE4ULL,
    0x2F8C3D2F832E9A4CULL,
    0x5F,
    0xB9,
    0x85,
    0x4A,
    0xC1,
    0xBB,
    0x68,
    0x70
};

const TwistDomainSaltSet TwistExpander_Mimosa::kKeySpawnASalts = {
    {
        {
            0x647922BF56051739ULL, 0xC6ACD8B9CB900C33ULL, 0xBD6AFA840098E5E8ULL, 0x19A2DB14E6B5F1DEULL, 
            0x9071338D9F13524AULL, 0x4E9AF9103DE98109ULL, 0xCB6DC32777803BC4ULL, 0xA934BCDBB12C2E76ULL, 
            0x808423E317776DCFULL, 0x27D3D0E4A09A1E7BULL, 0xD8877BB377E0B103ULL, 0x299A947494877D33ULL, 
            0x549BA2C8587FD83AULL, 0x6982325868729D99ULL, 0xEE61E64F4F36FB2AULL, 0x7DF08DA64CE0F897ULL, 
            0x2385C142F974C38DULL, 0x27A0CACC27059C41ULL, 0x6A9341D7BE91A6E3ULL, 0xDE112AE341E9030DULL, 
            0xFFC3923848EEC1F5ULL, 0x1EAE97634B8FEFB8ULL, 0x60538EA83576B70CULL, 0x4470A11F94F03CAAULL, 
            0x4A3C04AA6E381985ULL, 0xF371CB4D9B6788F7ULL, 0x1BF24C7915FA9F6AULL, 0x887720AC63C90482ULL, 
            0x5F41ED86D5C94930ULL, 0xC71079E460F5112AULL, 0xE23AC399F77DED90ULL, 0x9A593A45CB3FDB40ULL
        },
        {
            0x64A74389DD72C159ULL, 0xDEA6C78A5759DC4FULL, 0x175D9D0DB73E3BAFULL, 0x0A4BC92970D37FECULL, 
            0x549E73E2E32C9BACULL, 0x12D880BB95C594F1ULL, 0x2A2CFDD991F7504CULL, 0x92F9E2D5B78705AEULL, 
            0x215A5A040EF621D3ULL, 0xFD4B0F05242D1155ULL, 0x91987FEA3478773CULL, 0xE0F792E661EAD952ULL, 
            0x48499DA6E11AD747ULL, 0xDC8B5A52E1CC8A53ULL, 0xF9174FB5998D7162ULL, 0x302745D58549FEA3ULL, 
            0x62A8719CAFA2CEE0ULL, 0x7B19AB2E0ACA49E5ULL, 0x1511B0609DC73174ULL, 0x2605D79914A73D4CULL, 
            0x94CEFE8F63AC96A7ULL, 0x878E07FCD01123AAULL, 0xA38CE1F36E456292ULL, 0x12DE1035D670E97CULL, 
            0x30030FA6D3E0A65DULL, 0x6569E1652B796932ULL, 0x181C015E46B2AEDEULL, 0x2BC840806E463CD0ULL, 
            0x14BFE0405A49907EULL, 0xC221E602E8863A82ULL, 0xB5ADF395203063BBULL, 0x4E8C9D293A98BBF9ULL
        },
        {
            0x11FFEC3FE74492DBULL, 0x0309139661AB270CULL, 0xD7C381B793B139DCULL, 0xD737EC5A8EE30E35ULL, 
            0xC36945FE922A5A77ULL, 0x33A62F81CBEC8974ULL, 0x470325ED767A3519ULL, 0x1C5AAFB84A05B540ULL, 
            0xC6AD8E930BA8268AULL, 0x32E898C0E2F27E8BULL, 0x191C618037349293ULL, 0xC86AD78EECAE27ECULL, 
            0x66A70324D3624E64ULL, 0x9B89C3007C17261EULL, 0x355E60796B08816EULL, 0x78B3F7F7C33B3D9EULL, 
            0x0DF07B2EC7642ACEULL, 0x1B2FD963C4386492ULL, 0x3C6AD682F3833202ULL, 0x27CF21172A10EBA0ULL, 
            0x067D09A9893B487DULL, 0x48FBA28558160AFAULL, 0x5D0790D6A6AE9B93ULL, 0x552C80954C193D12ULL, 
            0x988C908DCF17E591ULL, 0x5838A5830B03CB13ULL, 0x5DD39B321F3D2458ULL, 0x526FEB624FCD1FFCULL, 
            0x35AB7406FE981F0EULL, 0x0792F3C22B7B68C3ULL, 0x8D1B5CC917A5667AULL, 0x2A151E73045F65FBULL
        },
        {
            0xDC9C96AA46EE5655ULL, 0xFD9A2315EA7B6C05ULL, 0xECF2FC437666ED9EULL, 0x4CB92FE654BBE20AULL, 
            0x5BC94B6C9856E31CULL, 0x8B4E3B912FBBFEC9ULL, 0x4F9C85965FDE3A1BULL, 0x7CCDCC118950272EULL, 
            0x416C6C80B891D3CBULL, 0xC3436547F31116A4ULL, 0xC7856198E15D0BFDULL, 0x8DEDE009E5147083ULL, 
            0x6730AAAAB4FC42BCULL, 0x80ABA93DAFD15696ULL, 0xC939DA9C5584236EULL, 0x54217CFE5EC334DBULL, 
            0x9278A4ADAD80A9CDULL, 0xE3B1083550B81EC6ULL, 0xCD755B1C2D7738BAULL, 0xB12FD8899DF0A428ULL, 
            0x8079C277B03A2899ULL, 0xE0241E1DE605EEABULL, 0xCA6F65F3BFD314E0ULL, 0x252F5222AA19E425ULL, 
            0xEC7F91EB6FECAAA8ULL, 0x54503FCE0E73730BULL, 0x9B2744F5028A6640ULL, 0xA721D7D9440C4A09ULL, 
            0x016F31EAAD94077EULL, 0x942D6E27D292405AULL, 0xC947AFDB6247CAE6ULL, 0x19FF88B2ED753B53ULL
        },
        {
            0x91D7721A88F0C00EULL, 0xD8ACECAFE8D065D6ULL, 0x9001D5157C79A11CULL, 0x59A6987A58484F6BULL, 
            0xA724FCF3C37DC4F0ULL, 0xF701B97DFCE462DBULL, 0x8CA387B1A02C7F6FULL, 0xB899C2F9AFEC911FULL, 
            0x9ACDB5E2EC11D2C7ULL, 0xB4F8BFE80226B723ULL, 0xAAEEA4753B001ECFULL, 0xE93EFC047AF691B1ULL, 
            0xCFCE17C4A982701BULL, 0x7EF26B848A2D176AULL, 0x2825CAAFF93132D8ULL, 0x3C8D9ABA6F351120ULL, 
            0x987B8AC772D74208ULL, 0x4328C5A2CC5BA189ULL, 0x39CAD155775C84E7ULL, 0x2B5A1C1191285EC8ULL, 
            0x20A1EA7858B3B15CULL, 0xB5E3CC6362510746ULL, 0xFD8EBC6EB2652E50ULL, 0x55FCFD7EAFF30395ULL, 
            0x791B7CB90E3DAC9CULL, 0x26F9DCE503624AA5ULL, 0xC11D639047943B53ULL, 0x2817395967D0BE02ULL, 
            0x9F4D5ED08343DEDCULL, 0x7E01017AC8D4C3C9ULL, 0xB9138E5329CEB9BBULL, 0x35EC857D4104E6B0ULL
        },
        {
            0x0C8F1F0228E6CF00ULL, 0x1C6DBD25ABAE056AULL, 0x18EED7BAC3B8AB8AULL, 0x8F1A13E017CFC879ULL, 
            0xB74F33753270F169ULL, 0xB88DFF23FE56F47CULL, 0xC8B9C6096174E602ULL, 0x2DD30472E6B4D0EAULL, 
            0x0812858A0605DFA6ULL, 0x4C540A76CB98158BULL, 0x44407984A0D33E29ULL, 0x7E1F5A251832C16BULL, 
            0x4186BE51A8332A3DULL, 0x49D9EFF0947FBAE0ULL, 0x7C5CF01176DEAA2CULL, 0xACF0628EED918365ULL, 
            0xD27DBB65DE74C4C0ULL, 0xED142FEDAC9BF38AULL, 0x6E930102A86BC236ULL, 0xAE7FEA97ED9B10BFULL, 
            0x88BE47B465A9153BULL, 0x4E45612E2D4A4C56ULL, 0x38497B379153F908ULL, 0xFB2397F2648159C2ULL, 
            0xA88214130ED4AEA1ULL, 0x5731B3005318A87AULL, 0x2EF6A2FF4DCF909BULL, 0x80AA180EB6E390A9ULL, 
            0xF3FE74F829594908ULL, 0x3FD1BBE5AC3CAD81ULL, 0x83B1D4F800B1719BULL, 0xEC97CD73460B6836ULL
        }
    },
    {
        {
            0xE112071986842AA0ULL, 0xA195CE34C131B809ULL, 0x4250D2215FBDE885ULL, 0x96C895FA797AFF98ULL, 
            0xC39F95A73635C77DULL, 0x1D3960C1B4F74024ULL, 0x94FD1742D4EC60A2ULL, 0x0191AF91C7D853B8ULL, 
            0x651C310E9376DA34ULL, 0x378DDCB9240B8DB5ULL, 0xB2BC8AA3D7292A0BULL, 0x77D7A67CE57C95BDULL, 
            0x01BDB01A6B8CFFE0ULL, 0xD8B2A3DAA6946BE0ULL, 0xEEEE1C3D58C1956CULL, 0xB49E8AF55C7314CDULL, 
            0xF3F696580D146468ULL, 0xE6CBD90511ACA34CULL, 0x2BCD8856B2E332A7ULL, 0xE388D5A9F8EA2FEAULL, 
            0xB478C921426BBD89ULL, 0x8C0C1B721082E161ULL, 0x304B4C55E46532C4ULL, 0x9CA1929CE0EF2D23ULL, 
            0x8F1089B08C98902DULL, 0x21BBF46BE8B978E0ULL, 0x7E22098CB7C0476FULL, 0x56B96DE0AF236494ULL, 
            0xC271EA7150DFF205ULL, 0xC5449ABEF356CB2AULL, 0x282AAC74104BA233ULL, 0x9E6E543DCCB47AA9ULL
        },
        {
            0x0AE8B7FACBF620A7ULL, 0x026355AAFD2348C5ULL, 0xD6AC6AD8D4CB836AULL, 0xC2CEA21FB596220BULL, 
            0x1E0D2E395FF72E2AULL, 0x662F1D688ADC49C7ULL, 0xBE876984FD18D9D4ULL, 0xA0B87DC4414B78AEULL, 
            0x5F63F4893B1E1023ULL, 0x101ECBDE3AB8B5FFULL, 0x5C4CCED665EC0C98ULL, 0x4A532B1665C9EC63ULL, 
            0xCA03C733B74E316FULL, 0x908E5035111FE0CDULL, 0x882EBAF5503E6B66ULL, 0xE8AD1C321F040DC9ULL, 
            0x46304FD02C73F4A2ULL, 0x0719E1E16E3741FAULL, 0x3FF7C45586F383E8ULL, 0x38869F2F2983E187ULL, 
            0x32A7C36F2AC228CBULL, 0x5868C73F580C6F5AULL, 0x42B88F1B4744DF33ULL, 0x97DA0304ECD62ECFULL, 
            0xEF44473BC4148FEDULL, 0xE5A88B5F65649CC9ULL, 0xB5F9127FF8CCE719ULL, 0x2F0B5D18840F01D2ULL, 
            0xCFD506796A5A2F5BULL, 0x16639960EAD3B558ULL, 0x0E8DF94A5A8D622BULL, 0x83AE5F9C75271445ULL
        },
        {
            0x30D44A5EB8F0026FULL, 0x95C983DF7824F191ULL, 0xE6014DF528871A5BULL, 0x975272BB4C85EB70ULL, 
            0x9357C263DCA67790ULL, 0xA2F444CCA1E735E7ULL, 0x3B25170C0EABE3A8ULL, 0x097AEE66D5AB616BULL, 
            0xD410802F871F4157ULL, 0xF2B600D2F345C5A2ULL, 0x6D0245B1BFBCDE34ULL, 0x02381C5CDE84B98DULL, 
            0x81FF4E32F2391C0FULL, 0x3E404750C09C1E5EULL, 0x4FD0B55E79F185F3ULL, 0xA3419B2489D7F784ULL, 
            0x01095830DF94A35DULL, 0x6E1A01B9A71A877AULL, 0x1B04385DF1EE1684ULL, 0x6E831317ABCAC40DULL, 
            0x52434614A525508FULL, 0x99F3914245125461ULL, 0x3D6CCEDA474CF2BCULL, 0xA809F37A64833E98ULL, 
            0x1C3E1DBC5E8EF198ULL, 0x6A2E173F6CF398F6ULL, 0x13D0D51547A27933ULL, 0x4C8348DA255A55B5ULL, 
            0xF2C06A3F08F39A22ULL, 0xB0F46256D1EC7178ULL, 0x522C2D06E1FE053BULL, 0xA125276306386B82ULL
        },
        {
            0x5A04BE2A1614D68BULL, 0xA1526BFB62CABFD2ULL, 0xC5C82726417E2956ULL, 0x73131D81004F1B4FULL, 
            0xE7C83405C6191005ULL, 0xC8CB2C5E26748F40ULL, 0x6F5C1CD15EC98DAAULL, 0x89C8AEED2DC21868ULL, 
            0x6ADF88E1BC540DDEULL, 0xF9C4323977061F02ULL, 0xB9E1295D1372FA2AULL, 0x2B0931E66BEB91D5ULL, 
            0xBFBAD65112BDB5CFULL, 0xCB01D7540408DDB8ULL, 0x8DC19FAE06F29795ULL, 0x789C7DE956DE01A5ULL, 
            0x159BDA14D00CE7C7ULL, 0x43C8EC8A7A1DB29AULL, 0xFF671FA648FFB23BULL, 0x6E240D5719261485ULL, 
            0x9F5E3F575F1AF2C3ULL, 0xD4A7FC374B06394FULL, 0x785DF451B2E10AFCULL, 0xA4B9A95E381E70F0ULL, 
            0xF3D88622A5AF0197ULL, 0x77E959BD04E8B99CULL, 0x46BE4534D4A56945ULL, 0x1AD6DD6D575D4C8EULL, 
            0x18640AF8710B5D3AULL, 0x0AA105176FE02516ULL, 0x08686C6ED1C561EFULL, 0x95FD8A4449C3783FULL
        },
        {
            0xD299D2889590C56FULL, 0x9459559511637618ULL, 0x95EBAB8617CF9180ULL, 0xD544490D13EB112DULL, 
            0x63AACA03D955AC31ULL, 0x9C4B77E8CFBEA0C3ULL, 0x6C4EED4853576FF8ULL, 0xB016880AB3074595ULL, 
            0xC225B3834C985EC5ULL, 0xD3BED421C16CAEEAULL, 0x33F580B1B4917705ULL, 0x3F329F45E753514EULL, 
            0xC69577A8A4C7FB4EULL, 0xBF7BF0DE6DB528FFULL, 0xCB455940F4578FC2ULL, 0xED2511DC673DA2E7ULL, 
            0x36075226180DA565ULL, 0x42FE9EE71FCC950CULL, 0x2121B06FCB0B88DEULL, 0x5C0275D84DB99CE2ULL, 
            0x817317B836C597F6ULL, 0xD91BF1629ECEECDDULL, 0x994A754F689ED926ULL, 0xE172D74DA6062D12ULL, 
            0xFA70EB1C7A9C8C12ULL, 0x7746FB2CECE05642ULL, 0x7334C080F9B0486DULL, 0x75B5C222EA2EFD68ULL, 
            0x86B2D838A4872E3DULL, 0x1AF384C1D9F265ECULL, 0x8AF5F3D77F3F4DF8ULL, 0xC7925799EECAB440ULL
        },
        {
            0x25FB56FA53307BA6ULL, 0x5901C7D64B8F29ABULL, 0xEB685F9D7A88FC1EULL, 0x4CC53ABB22FFC5FCULL, 
            0x97E7B8A243A21B5DULL, 0x446F67EDA3AF028BULL, 0xA6E6D9DC6288B8BCULL, 0x7455F899A639DE87ULL, 
            0x790147341B16C019ULL, 0x5606A019D14C7D22ULL, 0xEF96854A599D418FULL, 0x7C93BEBED03B1A80ULL, 
            0x0400F35D6C2559D1ULL, 0xEAB4B1733226F9A0ULL, 0x30926361D0E3D7D3ULL, 0xF6BAD3E2C224FB69ULL, 
            0xE6C2EE03CE31A772ULL, 0xE57B58598E6E48F8ULL, 0x939FE4125767A08BULL, 0x15EF7E1A855DE6CFULL, 
            0x5D752B86153D04F7ULL, 0x193F2F063B029BD2ULL, 0x8C2D4694A1EA0629ULL, 0x8B08E9421510973BULL, 
            0x8FF0BC0EC6DC766AULL, 0xD5F1E89DCA119DF2ULL, 0xEDBE0AA96D20ED24ULL, 0x20C335771FED28A1ULL, 
            0xBE7E32177FF46D81ULL, 0x2C06E65EF2DD3D7BULL, 0xC81CDBB4F309572EULL, 0xD7848D169D6FFAEBULL
        }
    },
    {
        {
            0x2380811E1C43DD72ULL, 0x2263F3BDC55B4A2FULL, 0x9D9EF9F6F1B9DC7CULL, 0x6D4C84DAEFEAD112ULL, 
            0x7B4102FAB7B2608EULL, 0x08452C2F3D91DA85ULL, 0xB21A9C779636EC93ULL, 0x07FAF308825BDAE3ULL, 
            0x32F9E7FC311B9C7DULL, 0xDD9AA894B6AA32D5ULL, 0xA1755DFBF8D59F73ULL, 0x4D2E792BD5460FDDULL, 
            0x11E8BDDC01C3AE86ULL, 0x0E6A34260CE622FBULL, 0x0643D30ED418BAE7ULL, 0x27A68657187AB668ULL, 
            0xF7886454D4CC12ABULL, 0xECD63543340071D6ULL, 0x1B70552255362C04ULL, 0xC0CA2BD80885E588ULL, 
            0xA30F6A418212F5F2ULL, 0xC422026193E811E4ULL, 0xCF93564C82C5F7CAULL, 0x6073AD3A13A3499DULL, 
            0xBA85853A1237B0D9ULL, 0x1978222EA1D0AA23ULL, 0x1F2623024A39C121ULL, 0x470D2D3635785ED5ULL, 
            0xCF2190F9A1801B5AULL, 0x98CA3FB031FDEAF2ULL, 0xEBEC0A63D17DE5CCULL, 0xBD06C9C6901F089AULL
        },
        {
            0x082F2347BFB7B88DULL, 0xA871A294E3B4A6E2ULL, 0xDAF47F7CBEF39BBDULL, 0xB8FFE39DAF5B0216ULL, 
            0x252084DC7D15C811ULL, 0x548F58800F7EF3C1ULL, 0xBB75397851117B7EULL, 0x54CDD94CB4E8B99AULL, 
            0xB7355B26B4AEFBA2ULL, 0x6C32C11C5B6B7E5FULL, 0x727E4BD00FE785F0ULL, 0xDAB135AA3B3CC4E7ULL, 
            0xE64C9EC7DC967623ULL, 0x1CDDD64202B36B69ULL, 0x8614350767EA7F80ULL, 0xE58C5C67F505B9E7ULL, 
            0xF4F4D7BCFCAC548BULL, 0xD8D5AD128F021F58ULL, 0x46676F38D2372DEBULL, 0x42D24F1BE8676D57ULL, 
            0x13BBD1D82C2E9C3EULL, 0xFCF00DAB8751CDFDULL, 0x705F646E3BE0FD1CULL, 0xDFF2ECD4EAAB811DULL, 
            0x2AA75C36F12914B7ULL, 0x56D522DBC8DC9A95ULL, 0x22C67A82A8FEB286ULL, 0x364A131419FAB6B8ULL, 
            0xA5DFB1717AE432ABULL, 0x7B9AC5EB9A2B6862ULL, 0x4D15B648C0DAD95AULL, 0xB552707646C48488ULL
        },
        {
            0xBE8DBF753C26CA0BULL, 0x726222619D1AC48DULL, 0x8BF9A91B2CCE5589ULL, 0x254BEB87E3429A06ULL, 
            0xCB0E9A3C926FF6F8ULL, 0xF91BBB19924F894DULL, 0x2F1D2FB3973359A2ULL, 0x740073F5855541ECULL, 
            0x3A6DE50B6AC329BDULL, 0xF30074BC8C52049DULL, 0xAFC6B4877998EF93ULL, 0x066E22A05654852CULL, 
            0x7AD37136A610CD16ULL, 0x08B50C3B0623961CULL, 0xBCB28A8D6EF13503ULL, 0x21B986AF527B4CF2ULL, 
            0x5B2D298CE61BE2F4ULL, 0x331FB43B48E98D63ULL, 0x3948CD49C5AFB082ULL, 0x4CFCAFE93E874B71ULL, 
            0xD2F9C1C9AC3600C8ULL, 0xA705E195F7759EE6ULL, 0x6BD86DDE11F13E61ULL, 0x7C0B24C5B6BA80E4ULL, 
            0x84166E5D4B70F15AULL, 0xDEC08397245784BCULL, 0xE17B5E11C999CDBFULL, 0x51E403373A5D9C48ULL, 
            0x8E6275EC25BC9B80ULL, 0x5D316F9B07CF5958ULL, 0x9FC1487E5FEA6736ULL, 0x31E1E766F02E4C14ULL
        },
        {
            0xC93A3B03BDC8314DULL, 0xEB7AE5F886489C20ULL, 0x6A5EFB0AB9665B62ULL, 0xBFB4D4094A1E3F89ULL, 
            0xDF5FFC1FEB399B6AULL, 0xE9743E8C4A0316AEULL, 0xBF8E814AC9130996ULL, 0x6AF9DA397D570279ULL, 
            0xBB8C71FC3C307842ULL, 0x793E098C2B56F188ULL, 0xAD530D86A952D1B2ULL, 0x7A1EC2C2207FCCCFULL, 
            0x4763174E1D2E03EBULL, 0xE9EACD402B0ACDB1ULL, 0x9208F965DF9ABE11ULL, 0x16CD41B701254808ULL, 
            0x5DA8644AE2E3A7BAULL, 0x3839864C8F32C1BBULL, 0x4CCEE849CECBB0B7ULL, 0xFC57C5C66AE7F849ULL, 
            0xBF9ABA17B191B8E2ULL, 0x7B12CDF24CF04120ULL, 0x6CE2BF4F4322057DULL, 0xB55D046722D200D2ULL, 
            0xAF4C2B8C3BE1EC2BULL, 0x1448EC7BE4E28FD8ULL, 0x0A784FA8E848FEFAULL, 0xBF4BFBE1ADBE5659ULL, 
            0x707AB5A27641A081ULL, 0x43C3C930A4E1B4BEULL, 0xB9D827F5265DB6B7ULL, 0x7745ACC4B3E5E46BULL
        },
        {
            0xBC0E4152DBD24162ULL, 0x926FAF80AD65F4D7ULL, 0xA7C435B4F1FC7300ULL, 0x69B377E3462677BAULL, 
            0xE36B638EB1165423ULL, 0x689CF1629C4AF3F0ULL, 0xB7078F0AFF6D4544ULL, 0xEBE1739D50CB6A37ULL, 
            0x8CE1FE11149E189DULL, 0x52DD38E7FCF87805ULL, 0xDD551901491243C5ULL, 0xFBC4159242F8EB00ULL, 
            0x7F23BF56EAEC4CFEULL, 0x5BB749B11827FA2FULL, 0xAFB5986CFEDB875FULL, 0xF06C96AD9318A5C9ULL, 
            0x5782D5AC5B475214ULL, 0x3957908747D80576ULL, 0xE03C7D9EAFC5B9BCULL, 0x3358EE33C3B87A2FULL, 
            0x8C4EF344B7D68C9CULL, 0xE8F90901F3DC1DD1ULL, 0x0F670DF887AE925AULL, 0x1A721EDFA730048CULL, 
            0x944F3FC51D4EEEA3ULL, 0x3C76FD74D9B21787ULL, 0x6D95F98F76B1203DULL, 0xCAF3D88E3D2E6641ULL, 
            0xCC91C9177DBB6694ULL, 0xE02302D3FF7EA2E8ULL, 0x9998D997A6707CB3ULL, 0xD844A5A8F7A09AE5ULL
        },
        {
            0x0DCC173E69CB6A3EULL, 0x91988C427E799EE6ULL, 0xE24E1EE618E82105ULL, 0x7E9C1A74571BA49DULL, 
            0xB381EAC08D2C9F6DULL, 0xE447A8078EFD7E36ULL, 0x33E4119F8AC6857EULL, 0x1731BBF494A76642ULL, 
            0x70C752DA30A6B058ULL, 0x9B90218A19C81DA9ULL, 0x23733AC3C26B1726ULL, 0x111E6A299AEC0FBBULL, 
            0xEAA12976BECD5D70ULL, 0x1EFC88E4411EDBA7ULL, 0x5A2C8D2AC574FD10ULL, 0x54C6FFD3C653CC44ULL, 
            0xB1607B0E2E09947FULL, 0x96F75F700364CCACULL, 0xB6EE2CAFFD40EB54ULL, 0xC635638A8203BD71ULL, 
            0x34A56556D8B2170EULL, 0x6DC9E9F6EA274A18ULL, 0x58803DA218CC5844ULL, 0x93AD1F6508E6663CULL, 
            0x74BC8C5E28C290E9ULL, 0x664AC7590E7E8148ULL, 0xBBB3B72B9A3D067DULL, 0x560B9CB5DA0A8EC3ULL, 
            0x90B8B7D9BF0B96A2ULL, 0x64F74E78A62FE06BULL, 0xA917A5E0EB5204D3ULL, 0x86F0240D50E5A830ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeySpawnAConstants = {
    0x46B449A8F375CAC0ULL,
    0xC41F5C2146F053FEULL,
    0x80250F7F25D62379ULL,
    0x46B449A8F375CAC0ULL,
    0xC41F5C2146F053FEULL,
    0x80250F7F25D62379ULL,
    0x58F1FF17C465DFEDULL,
    0xFF53F7B42CD45CFCULL,
    0xD2,
    0x4A,
    0x07,
    0x78,
    0xB1,
    0xCF,
    0x46,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Mimosa::kKeySpawnBSalts = {
    {
        {
            0x44322C3288669B73ULL, 0xED3811A3812A5172ULL, 0xF0D74E3BE49F876BULL, 0xB229B99C1FF7842AULL, 
            0x9FA682248BB4CCD1ULL, 0xD5C78A76EF978B72ULL, 0x179C03658406911AULL, 0xB16F87AF6E746058ULL, 
            0x75ABA40ECD396688ULL, 0xA0B89092A374A3C6ULL, 0x11FDECAA6A94B906ULL, 0xA9D188A87C621525ULL, 
            0xC8353A3086932D72ULL, 0x448B60828846152DULL, 0x7EB5FC874B2EE26AULL, 0x8541DBB036A348CFULL, 
            0x2CCCFE576A3680DBULL, 0x4178F9A15AF92094ULL, 0xF10FDCD513593344ULL, 0x0A4E040B4FF12E6DULL, 
            0xB60835AB99EC92ACULL, 0x28EB48BF6B8E144FULL, 0x0D6D2C1CA2366C31ULL, 0x36C93FD0D5434807ULL, 
            0x6E27D3F725CB90BAULL, 0x9A50FA42C0EBB320ULL, 0x0C50CB64E4487F11ULL, 0x900867BE8EEAE56FULL, 
            0x38F4EF5DCE2D9B58ULL, 0x427302798410F06BULL, 0xE30BCD85AE951CD6ULL, 0xEE0368EBF6C446A9ULL
        },
        {
            0xEF3246F525CCE296ULL, 0x6A9BA9DB933A4E97ULL, 0xA18FB4A52FB8C4B5ULL, 0xA46E04667742E03AULL, 
            0x1585003DDF8F287EULL, 0xC0F3711FA87F88ABULL, 0xE812AB920ECA672EULL, 0x48BA749CE68E53D4ULL, 
            0x49208CE02C1F047CULL, 0x3C667B930663E165ULL, 0x05D99E44AF4A2E55ULL, 0x85650F153A17D79DULL, 
            0x3B0B5A7347F55E3BULL, 0xA80A262BABC4C474ULL, 0x0962D2020C1D96E7ULL, 0x24729966E489B260ULL, 
            0x64FC4BBFD7217400ULL, 0x0CCCBBBBD08B24AEULL, 0x17901BC76D57B706ULL, 0xEE15A1A77ED08B16ULL, 
            0x582C4B515B1A559EULL, 0x16DD6ABE5CAB58F3ULL, 0xEE4EE171819839D8ULL, 0x05C964615B3B4BCAULL, 
            0xF126FF788BA08D8BULL, 0xF37BC221F5122DB8ULL, 0x17BD9734FBE8C741ULL, 0x73BD88416ABC03CFULL, 
            0x5CDCD772768FCC43ULL, 0x74BCC839057233D6ULL, 0x844B0C18C0D529F3ULL, 0x9F859A614D68D328ULL
        },
        {
            0xCDF2D31D36399393ULL, 0x0D34168440C5F4CEULL, 0xE9CCA92A13777988ULL, 0xC419A7686235052BULL, 
            0x409777BC2E8E0626ULL, 0x3AABC9E3A9DAC903ULL, 0x0E345B98B8D8FE55ULL, 0x5547B4ED086E8B59ULL, 
            0x0FBA8AAA14CFC909ULL, 0x7612E99595DD5990ULL, 0x82D2C471A10DAE84ULL, 0x995B325B42B228F5ULL, 
            0xBABC78528C5CD460ULL, 0x09050C09860ED75BULL, 0x96ABED39CD68500CULL, 0x869D4DB39178A5B5ULL, 
            0x79DDF36ECBD454DFULL, 0x159B752C6EB30E6FULL, 0x26AEA15103568B1FULL, 0x9965EACCC2FCEC09ULL, 
            0xC1A0C56F51499056ULL, 0xD6078C6D74335AB9ULL, 0x8F9041E6C34A9923ULL, 0x84C526783A557D06ULL, 
            0x837E79904FAA0BE9ULL, 0xC061114081E81E93ULL, 0xF44AFE55D0262753ULL, 0xF442075F4CEEC222ULL, 
            0xAC134F286F5045BEULL, 0xA46D67A80FCCB943ULL, 0x9F3257F1BC7726ADULL, 0xA775D6129920F89CULL
        },
        {
            0x8DAFB326DDC49F92ULL, 0x3B51F47DF19DAE09ULL, 0x919C86AB97C4826AULL, 0x059A39BCCCDA1A43ULL, 
            0x4DCA344E6E588FCDULL, 0xB616FCEC691548EBULL, 0xFC8747FDE9BE6EB8ULL, 0x889753D09A08B54EULL, 
            0x9785A13331A3A240ULL, 0xCCDDBCAD948056DAULL, 0x3D45B009B8AC2E69ULL, 0x9D7326098B7A1472ULL, 
            0x8BC36B3B24F2D218ULL, 0x726ABD396F853D5AULL, 0x273AD431DECC583DULL, 0xCA1339F33C7F723CULL, 
            0x096624DD9C3FB86BULL, 0xF4F82CC0A1D4FEF3ULL, 0x2A7D48E3FD32D70FULL, 0xF636016246BFA104ULL, 
            0x78D3DCD3D5A37D40ULL, 0x8899D8A2864B733FULL, 0x83B0F605AC65E788ULL, 0x47FC9C593C0DE821ULL, 
            0xF1926ABEBCF91724ULL, 0x62E6DCE91DB6998FULL, 0x68830B7BC138EECEULL, 0xC3F1BACC261C2211ULL, 
            0xF411DEEB8862F4BFULL, 0xA254040996378012ULL, 0x83445B4185EA8DA7ULL, 0x879501A7D0FB9B21ULL
        },
        {
            0x28DD62603599478FULL, 0x10091C665E263044ULL, 0xA63B37934BAB5052ULL, 0x6B199C8A6F966901ULL, 
            0x974D34A76DD09644ULL, 0x7D9F8F14BCEE9FA3ULL, 0x0FF14F6D50D1BC7BULL, 0x06EC6CF61CFAFC07ULL, 
            0xB2519FA370508085ULL, 0x23E03CBFDA6B53AFULL, 0x5A5F1FAA794C85B7ULL, 0x0A2D0A8ED89BBD18ULL, 
            0xC631071EE264AB20ULL, 0xEA408EAAE1DEB065ULL, 0xE4B5C914DFE84E12ULL, 0xB8E7BB48BAA47C91ULL, 
            0x8F5EFEF49AFF586DULL, 0x3F427A4E87209F70ULL, 0xBBB4FB819481F02BULL, 0x3C3C78204FC03BF3ULL, 
            0x1E810224D8367853ULL, 0x97DF23190C180D67ULL, 0xD6E4676E66485600ULL, 0x320186B0F89A377BULL, 
            0xE1074E193F727F5FULL, 0xE654A3E00A5C1451ULL, 0xE045388054849E71ULL, 0xE14328031F4989C3ULL, 
            0x248D7606F7205CE4ULL, 0x66C5151EB1D3147BULL, 0x447CCB62C2FB813AULL, 0x58CB3ED969E4113CULL
        },
        {
            0xC57F0A4F005EFC0AULL, 0xE72D28D07E7202EFULL, 0x22F641813BDE8236ULL, 0x4B9F0F18E9F1ED16ULL, 
            0xFABC0B3EAA27A2E5ULL, 0x1131780363E31A18ULL, 0x723978FBE154F866ULL, 0xE34F2090C9AAF18FULL, 
            0x1C1EB288F1B8C30CULL, 0xC2D126D362BED810ULL, 0x4E19CB56BC14F645ULL, 0xEDD125FEE46CE727ULL, 
            0x1F53D67252BA6CF4ULL, 0x6408BE08EB85FDF5ULL, 0x01BDEC6C0F7A3E0BULL, 0xBA46D772E9636602ULL, 
            0xA53B268821377128ULL, 0x5B3156B8A53C0621ULL, 0x08BF2D2BE49B49C6ULL, 0x2869BA4984C4DCE0ULL, 
            0xB18264C65DE9C773ULL, 0x28C02AD7AA40E556ULL, 0xB114A30BDB7B38C4ULL, 0x4125ACB949D1044BULL, 
            0x7EC960C4F83F2DA4ULL, 0x530D3C2301B5FD56ULL, 0x7B1D46800CF27919ULL, 0x2A6FD9C06ECC29ABULL, 
            0x76EFCA9522043614ULL, 0x1C2A7F3112C770F9ULL, 0x1A1BA844E56AA729ULL, 0x0FEC5AA776D4438CULL
        }
    },
    {
        {
            0x42525FB4435A4BCEULL, 0x5D1ED5913D94A12CULL, 0xC48E74ECF0A11842ULL, 0xCE24BB2320B36787ULL, 
            0x683492C9CD9DBE56ULL, 0xA13030172FC19AD2ULL, 0x43E22EEF3175F574ULL, 0xCE09B30B502F506DULL, 
            0x27047443C7DF00CDULL, 0x1F90FCB7D5447DA3ULL, 0x839C1F77526EF563ULL, 0xC62D3EFD9E138D5EULL, 
            0x8CB955FBEADD2215ULL, 0x07082C82D959183EULL, 0x1060494238D7B395ULL, 0xF8D8D8FB3D4E8C0AULL, 
            0x6522D4532D2CD738ULL, 0x6EAAB210F14CE6ADULL, 0xF518F77AD0908479ULL, 0x030E055E5D70D851ULL, 
            0xAF48A83871E624B9ULL, 0xCD995CACF3A1D45AULL, 0x293D12C31704CC59ULL, 0x984612330BA14661ULL, 
            0xC02E16362C87075DULL, 0x78D56020F8A0411FULL, 0xCFE5B34F99ED94BFULL, 0x6E676FBF42773154ULL, 
            0x73BE55485FAE5400ULL, 0xB8D6E3B6075EF913ULL, 0xDE3B6AC473596A12ULL, 0x0FEF81E4EB2824E3ULL
        },
        {
            0x2DF2DF9A739EB405ULL, 0x527854252A2AB110ULL, 0x1BAC7DE32C81EA9AULL, 0xFB876F24369827ECULL, 
            0xF3B6E5C0E5F059D7ULL, 0x39CBB3CA0E240DE8ULL, 0x6A7DA893B6D654ABULL, 0x2C602F002B100839ULL, 
            0x8DE923DD819633A8ULL, 0x51F8030D295ADD44ULL, 0xFBDD684E9A468E0DULL, 0xF8A3A5C282BDE104ULL, 
            0x02FA0CBADDE459C7ULL, 0xB7B2FED26CB01DB7ULL, 0x9F58E3314AA5210DULL, 0x9B37BEDAC9DC7CB4ULL, 
            0x8E4E589ADB1858C5ULL, 0xB6EE2E40935DBA8AULL, 0x0310FD7D4A559891ULL, 0xE4D326DC2C99A718ULL, 
            0x07567BD1B44952E5ULL, 0x31CA30CCF75B29E5ULL, 0x0BB15FFEAF7FD8AAULL, 0xA8FECAE87E89AB9BULL, 
            0x6C2526151D947BBEULL, 0xE0FB07D1D700830EULL, 0xE8AAC94D85D91558ULL, 0xCC3596BBF9684A73ULL, 
            0x1F9C4377023B0738ULL, 0xC0585A78F596DB40ULL, 0x61904684103729CCULL, 0x2A24A64A3092B81DULL
        },
        {
            0xA05035559143BB43ULL, 0x445BE66E796FB4CCULL, 0x7B96C84C60389F27ULL, 0xE7A96EC67CD7B8BAULL, 
            0x4C5863A06001E15CULL, 0x9A807EF067C468E6ULL, 0xB17619C98A30DF6FULL, 0x2E12F2F197ED8ACDULL, 
            0x3B4B542F82D2A532ULL, 0x39AEE252978663D4ULL, 0x76B7D1E4D9049C42ULL, 0xF14F6EE8E352C17AULL, 
            0x5BFE8063FFFCE62AULL, 0x77BD20FE7EECA8D8ULL, 0x839CD129ECF92478ULL, 0x8B06E63AB358CD89ULL, 
            0x5A48D09A17837829ULL, 0x70C1DE2539F69D60ULL, 0x9661AF28B6B285F5ULL, 0x9CB5989C40BD7B8AULL, 
            0x046B00E3AC74F669ULL, 0xBACC12E29BD2C0A2ULL, 0x1865C08956022E29ULL, 0x51ED2F7B024AC9D4ULL, 
            0x42F961BF408E491BULL, 0x821CE60486A95545ULL, 0x0ADEB8C6F8C1D540ULL, 0x67D2E397B207033FULL, 
            0x53A77B6D8B9C570DULL, 0xFD44F4791220C722ULL, 0xFE4305D25C84BADFULL, 0x9037215CCDC19627ULL
        },
        {
            0x849C050EDCE21874ULL, 0x8AC4CC49FEEF9BAEULL, 0x103C7615BA2F78B3ULL, 0x99A13A1C3E99E340ULL, 
            0x6F90710A96519C9AULL, 0x46770F5384311070ULL, 0x72F945E7E00BFC73ULL, 0x15EF55E82C5DBB44ULL, 
            0x1ABD699E32EF3A08ULL, 0x8A973F02B2998333ULL, 0xD6B4BF11BE655C73ULL, 0xA3266CC66C8ECB70ULL, 
            0x9527C793C443FF87ULL, 0xCFD5F819AA9F3380ULL, 0x077E38DE63C81435ULL, 0x157C53C458B631ECULL, 
            0xCAAE744714160BA5ULL, 0x235C25AE59BC4426ULL, 0xE434C023B39FFF4CULL, 0xEEEC44D641D0A5E3ULL, 
            0x649E60BA48B357C7ULL, 0xCE84119B5C54FFE1ULL, 0x64B8458D9B6FFBBCULL, 0xCADF77F92670DB36ULL, 
            0x4DFABAE0A163A7B4ULL, 0x3BC63E88332C5B3FULL, 0x8C3EAB8B9522233DULL, 0x08FC43129422890BULL, 
            0xC8D7B40B022E1E6FULL, 0xA375E578933FEDA7ULL, 0x0560C42C4DFD55BBULL, 0x26BEA0644B84BE34ULL
        },
        {
            0xEF45A2CB619C0905ULL, 0xF80CE89098AF931BULL, 0x3C39DDA24D7B1E21ULL, 0xC5295D86F9357B8DULL, 
            0x5270384ACBE373C0ULL, 0xDB676E49517C81B9ULL, 0x14C7824D0C0F6295ULL, 0x4DB9179918749DFCULL, 
            0x686E647EAB8952D2ULL, 0x22AE2A78A6FC2716ULL, 0xA36450C3D5FD7B37ULL, 0x52E825A017476CCBULL, 
            0xF8187DACE6B86808ULL, 0xAECD501F917F67EAULL, 0x756BC25E0E5E898CULL, 0x53C7C953F5573E6DULL, 
            0x146A517E64A3975FULL, 0x4482C860CF1DB40CULL, 0x43B38C5352729CD1ULL, 0x7DC57534683430EAULL, 
            0xC7EDD758934BF1B2ULL, 0x9ABC7CEEC6AC390FULL, 0x274C0809CDD692AFULL, 0x2865BC026818EC05ULL, 
            0x7C568342D7592713ULL, 0xE22A17CEBB506FCEULL, 0x5E580007AA3928CCULL, 0x40FC9911E68B191CULL, 
            0x585CE7012612B274ULL, 0x9B3CFD3E6C05A299ULL, 0x92D1FAD54996DBACULL, 0xF2EC2C293279A92AULL
        },
        {
            0x557F1DF9D61A3CD8ULL, 0xC9F076B5FCCFF778ULL, 0x3DA04C00B521E14AULL, 0x3609D3347EB306C2ULL, 
            0xD7FB68D0CD6A12B7ULL, 0x1161B921E6753A28ULL, 0x0970F614880E7915ULL, 0x3E0482DB56BF2B0BULL, 
            0x0829E7FE0C9D3A7CULL, 0x18E0669BEC358622ULL, 0xB4ED016D1C82D049ULL, 0x7EE134C504915D7EULL, 
            0x1C9A5B11ED9F1140ULL, 0xDDA3AFAC80910518ULL, 0xC19BB094C259F7F8ULL, 0x1BF2ACA580A03009ULL, 
            0x0CE2899FEB7C2006ULL, 0xE3B788DD581FA7DEULL, 0x52EB89FD8B74A298ULL, 0x12774F482871C672ULL, 
            0x3F4AF74558444536ULL, 0xB8B2C36733B8F8F6ULL, 0x48432BD5F0ABB7B3ULL, 0x84286F94374123CDULL, 
            0x078451832EF64A5AULL, 0xE61246805FB76224ULL, 0x05467B53BF9CA16DULL, 0x8AE71DAB56C33A44ULL, 
            0x2FB21FD2775E144CULL, 0x2917A3927C9B71C3ULL, 0xA4E31549E4B31A35ULL, 0xE6A1466035798269ULL
        }
    },
    {
        {
            0xCF7F476AD74CAE95ULL, 0x36F26AA42706F5AAULL, 0x0A21D72A2BBB4F85ULL, 0x17585296194CC453ULL, 
            0x8CBCBACCFE6DEB62ULL, 0x39A91E5371DC5EDEULL, 0x068BE6A433E4601DULL, 0x9680E2B0CBF6277BULL, 
            0xFECE2E49B1E8E1B4ULL, 0xB03E9C60A5F72DF8ULL, 0xCEA2AACC3FAB2DBCULL, 0xC11E34020964F5A6ULL, 
            0x2DD15596A41E190AULL, 0xB0800CBEC070198CULL, 0x5C397625CB669D86ULL, 0x1F0186C32932E07FULL, 
            0xEA06030C3BB0D561ULL, 0xF3592E6D3A692443ULL, 0x5C8D3C2A73A5AEDDULL, 0x3A826ABF6F5AD09BULL, 
            0x45887791F8824C0CULL, 0xCCB11E82AE8EC29BULL, 0xE8682CB9DAF791D6ULL, 0x8810A0F3F9C59C59ULL, 
            0x9B58DB9301711CA4ULL, 0xB81783EA3C8A5F11ULL, 0x14253329AA6909C0ULL, 0x689B30C825ED65ADULL, 
            0x35984D3D298FEB48ULL, 0xACACE3996C3A0E56ULL, 0x91F7B8168F29A984ULL, 0x8256BEF5A64B5AC7ULL
        },
        {
            0xCD5C26D635DC7958ULL, 0x10C2227BFDD62B72ULL, 0xF34543D04ABC3D41ULL, 0x9CCC47265015AF64ULL, 
            0xB0EB4676A162305AULL, 0x1E375A79850E8677ULL, 0xDFB3932837AC2A62ULL, 0x4A1C127F2284C90CULL, 
            0xD5207A05B302474DULL, 0xFA9F39383A6F0264ULL, 0x69DEC5FD3862DE3DULL, 0x9C1204EB71BF3179ULL, 
            0xFF1CA9538F60E0C6ULL, 0x511C599AAA7D739CULL, 0xE9D2169ECFA71DD1ULL, 0x0A8AACA2441E95E2ULL, 
            0x32D5EAFBC7046188ULL, 0x78680A5C3CD039BFULL, 0xBD6264293BE9D3EFULL, 0x4A2A6B2D6B4475E5ULL, 
            0x81DD912C0E21D31AULL, 0xA5C85B627B5D209DULL, 0xC35DCA81E393480DULL, 0x3348442A7987B9D1ULL, 
            0x68CC3AEB2933886DULL, 0xB27F9FD9552DEAE9ULL, 0xD7DF7F71443AE360ULL, 0xD57F978637FBEF2DULL, 
            0x52E7C2488218F72AULL, 0xE8EDE496EAC538C3ULL, 0x903B87556F7E8890ULL, 0x8425EC5B11B44534ULL
        },
        {
            0xDB254C223A60F5DAULL, 0xD7B51352B89B6A28ULL, 0xC2C6C9613C7B2C56ULL, 0xEE2376C3C08558B5ULL, 
            0x010ADC1E0D7CF921ULL, 0x8B8A02F085910132ULL, 0x2AB7D9028F02AA27ULL, 0x4C158F2EB19C32A4ULL, 
            0x76A291AEF804C0D2ULL, 0x9D9EE5476F3BA9F0ULL, 0xE359BBDD28E89351ULL, 0x8E6FC9FD8F401B6DULL, 
            0xE020A6E39AA8943AULL, 0xBFE175EF8521755DULL, 0xDDB1ACE15933A870ULL, 0x35E369BA88455B56ULL, 
            0x7218B3D744BC8F2AULL, 0x0CAB59F7EAF4532AULL, 0x57ECE38EAD04E473ULL, 0x6BD81FFF2CADD54CULL, 
            0xB1ED11BA006166EAULL, 0xF57F5FFAF12F7DA8ULL, 0x5A85327227C9BA6AULL, 0x91DDC8A4F1F3EC2BULL, 
            0xB69C5666C2DCF80FULL, 0xB4D5AF9CCB9362CAULL, 0x98057583E6FD78A9ULL, 0xB2BBEB7BD21CA1E5ULL, 
            0xBB1B29F44C4558F6ULL, 0xFEB271AE19048209ULL, 0x534EF587919EC81EULL, 0x4D6CCBEE58B84D2DULL
        },
        {
            0xFBDB9DBEBEA8E302ULL, 0xBC7EC0A7F1DECB75ULL, 0xD1D1B7ADAFDE2094ULL, 0x406E2703D0A241E9ULL, 
            0x01705AAD27AD9541ULL, 0xCBE5DC2157E8D64CULL, 0x9BE824E16DC8BE89ULL, 0xA70254B9AA21163AULL, 
            0x12876D6E307776D1ULL, 0xB16A08AA313553EDULL, 0xF92F3C857F68DEA5ULL, 0xED461E9C6BA99A2EULL, 
            0x205F6ACC1892CB8EULL, 0x0C7CD1B6365C8AE2ULL, 0xB18F8D971726044DULL, 0xA3A4ACA9A494FC48ULL, 
            0x7B5370EE7574F09FULL, 0xDCD75781A3DBFFBAULL, 0x5AF11C557D7EECE7ULL, 0x09A2C23109F0DE3CULL, 
            0xCB6B838975BF9BB6ULL, 0x5CCFCF18AE59E1F8ULL, 0x38D7895143897F62ULL, 0xE14DCC96419339E1ULL, 
            0x53BA4C7CD3DBEF4EULL, 0xEAD169DD25CDCC40ULL, 0x80DE7E457A757B60ULL, 0xDE18526231AA57AFULL, 
            0x6007D88CFF2F6AD9ULL, 0x4C1C99A669F1C115ULL, 0x4356A786B280C359ULL, 0x57581E48CA162AEFULL
        },
        {
            0x165DD55D38FFB887ULL, 0x9CDCCA6071332D72ULL, 0xD311E7E5A7711085ULL, 0xC36E931D02943CBCULL, 
            0xD5A372364903915DULL, 0x466A251B6D761216ULL, 0x44DE347A427770C8ULL, 0x3084AD449569A7B6ULL, 
            0x031B9EEECB27D65CULL, 0x1B1820E4CE4E475AULL, 0x5FE0D76E113FDC10ULL, 0xF3781C92BF9021D4ULL, 
            0x4F2A588C82720B89ULL, 0x7662B30757133FEBULL, 0x9AE47F75E2C11D75ULL, 0x62FFD2217397AC95ULL, 
            0xA7BD15624363A57EULL, 0x04BB3DB765E45AB3ULL, 0x5AE37CA6E249936DULL, 0xD103E9B09B3272C5ULL, 
            0x0A215CAABB3BBA2DULL, 0x2A36F47F2493A65DULL, 0x5BB4FE39A52257F4ULL, 0xEE5C44F2CBF68C13ULL, 
            0xE018CB9F7C54B296ULL, 0xE7D522916DB034D1ULL, 0x551F5D52BECD1B13ULL, 0xFC2D1FEEC7815AA8ULL, 
            0x11A971E8F6FA0B2EULL, 0x59789B3BE3331F03ULL, 0x78ED0A264BFE8E93ULL, 0x8F8496C5255B442DULL
        },
        {
            0x0FF89EEA037D3C24ULL, 0x7A1001491B5AF3C0ULL, 0x7D16A84910E3BE1BULL, 0x293F7BFDB82A138FULL, 
            0xD3A41BE0AA82A0B3ULL, 0x4B9532520614DAFBULL, 0x307E1525E8ABD614ULL, 0x677BEDED0CB6E1FAULL, 
            0xE8E6564CA79B566EULL, 0x0842EAD4EB76FF01ULL, 0x741C6EFAE2ACD9B9ULL, 0x9A304E929EC0D6C5ULL, 
            0x8CB8721D26E1F820ULL, 0x486F336F0744E66BULL, 0x7077391BB24C2F24ULL, 0x3136A3BB9D95461EULL, 
            0x4DCB7B3861F83EB8ULL, 0x24FA4CF7B99D207BULL, 0x927140D5692DBDA3ULL, 0xCC48528E652B47DFULL, 
            0x61458E294B509FDAULL, 0x3CB1F25D4CF5DCD0ULL, 0xC4F65727FC581827ULL, 0x38DA4A7BF977B747ULL, 
            0x6E853434EFFAE577ULL, 0x8CD46A742575120AULL, 0x8E4FAB0C2F926072ULL, 0x17C4B1515FC22D8CULL, 
            0xB34A81911D096D58ULL, 0x58ACAF448A382141ULL, 0x51CD1C25BB72FE11ULL, 0x4CDFA351799292BFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kKeySpawnBConstants = {
    0xD3B2A682FE3FEEFDULL,
    0x8B0FE1D4EA302D2FULL,
    0xBBC66FDE9A516D57ULL,
    0xD3B2A682FE3FEEFDULL,
    0x8B0FE1D4EA302D2FULL,
    0xBBC66FDE9A516D57ULL,
    0xBB4926DD90A5A159ULL,
    0x44F1988CF40332A8ULL,
    0xCF,
    0x71,
    0x1E,
    0x11,
    0x2D,
    0x86,
    0x5F,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Mimosa::kSeedSalts = {
    {
        {
            0xA5C8E64272B415D8ULL, 0x0A2A619AA14432C8ULL, 0x7AF37A70CA040BFAULL, 0xF0476C71CAD7D430ULL, 
            0xD9E1A1D7E4540B0BULL, 0xCAF6C45588B2066BULL, 0x9227D1A879427D0BULL, 0xF9E089C66ACCAEE8ULL, 
            0xB4E5B9B9FF4EE295ULL, 0xCC647766348370FFULL, 0x319D8F542428B2D5ULL, 0x546FC9C0211A3BFEULL, 
            0xAF24161096AB9C1AULL, 0x0A41E229D6E1E059ULL, 0x58FC93BBF30CD694ULL, 0x367947387CB87F93ULL, 
            0x919EF00396F06E60ULL, 0x2AC2D88F59761C13ULL, 0x7309D24B4310A612ULL, 0xB4E1E73659FC19B9ULL, 
            0x045909278035EBD8ULL, 0xAF7BE2D1148AAC47ULL, 0x60C755D2E7E50D0EULL, 0xB80BACFA1D7F1D40ULL, 
            0xD9839D72F466F32AULL, 0x5F64809697C02A08ULL, 0x10261C86B14B849FULL, 0x33EDBB8699DD330AULL, 
            0xA17FE4462777A2FAULL, 0xFE4B558B3C9F26E9ULL, 0x36123DDBE35F2CBCULL, 0xFD644883FA577DA2ULL
        },
        {
            0xE750AE0DBA2C4045ULL, 0x5305B545F3BE2DBCULL, 0x543EEF12F9167281ULL, 0x4975435B06009B36ULL, 
            0xF5D1B5B2DA9E5C7DULL, 0xA39A7999ABAE313FULL, 0x74908E69D32C6711ULL, 0x63F7F13B4C4DE879ULL, 
            0xEC81A9D0FEAF66F9ULL, 0xE9E4730DD553D2FDULL, 0x4CE9B8B45E21A3D7ULL, 0x8C6F19474D33C158ULL, 
            0x57491EED5D00E395ULL, 0xAA6CEA29111689E7ULL, 0xB0137BD3A3267FE9ULL, 0xB99502776A140D02ULL, 
            0x2937F80E38670EC3ULL, 0x9DE63D6F11EFC435ULL, 0xD78EFE0EBB06AF37ULL, 0xFA27678448DBD252ULL, 
            0x5DF6E89F36D383C9ULL, 0x63DB2381C59ABF55ULL, 0x8A516CA1E78639B1ULL, 0x4ED3A7CDC0F871C4ULL, 
            0x9BEE4CB782397710ULL, 0x38BFC3951D832527ULL, 0x63F79C7F124A53B3ULL, 0xBC568F8E3186E672ULL, 
            0xF3010343C08312B4ULL, 0x18482716E6976D94ULL, 0xA9F948BB7E9E6A86ULL, 0x0E2D53ECF5F852E5ULL
        },
        {
            0xAEA00889FB5E0347ULL, 0x3D77F667CF5F1728ULL, 0x378CAD8B2ECF636BULL, 0x00695BE582653A6DULL, 
            0x74EEC7DA8EF27E43ULL, 0xE0B1BE27F81A8941ULL, 0x93E8178AD2024992ULL, 0x1257747DBF42B02FULL, 
            0x4B2EE101FDF56888ULL, 0xCA0A1ABF71733846ULL, 0xBC59E70664287006ULL, 0xD13733F30F25C6D5ULL, 
            0xFEE667F5D5AD51DAULL, 0xF145D4037D09D7F6ULL, 0x47F88019F9337CCCULL, 0xB04728F74F8A3F44ULL, 
            0x4DAFE0D841B3F5CBULL, 0x4301A36EBA0DA045ULL, 0x01193D3273652916ULL, 0x03B53AF1D2E8EF44ULL, 
            0xD1C2568EC341D421ULL, 0xF31460C28E6D9410ULL, 0x1DA4B6A48D1B3CD2ULL, 0x68F163478597D196ULL, 
            0x37D14B5BB3BB8D0EULL, 0x042A8F496235B187ULL, 0xF9BCE3121C387210ULL, 0x8A3B2D7E6346170CULL, 
            0x14DEBC71CA0A3FD1ULL, 0x4DDDC1E667FA9D02ULL, 0x3E292CA48CF766BCULL, 0xC73431D2B6A0BCD9ULL
        },
        {
            0x81D5CFFAC9D5975DULL, 0xF392905480149D6DULL, 0x043661116D3B6F38ULL, 0xE369806438576570ULL, 
            0x0ABE467311D63C94ULL, 0xD995C64EC6DC38AFULL, 0xFA22B39D8AA96814ULL, 0xE26A2F96F9937865ULL, 
            0x3D0F0D6A1CB71B98ULL, 0xA5B66262A0A7762FULL, 0xDAF1DF942784F62AULL, 0xB5E020FF283D2B6CULL, 
            0x35F7AC6DB168064AULL, 0xBB0CC5BFE2AFD579ULL, 0x850284046F74FD7DULL, 0xF5AEF03C84673985ULL, 
            0x5CAE12692678CD90ULL, 0xD1442325320E9DBDULL, 0xBF1C8483A68023FBULL, 0x4E1CE7243A8008A7ULL, 
            0x1B943BC614594443ULL, 0x02EDF6730013FBFBULL, 0x51E666881312F7D3ULL, 0xD2EC45B69A54D691ULL, 
            0xE7D1B7BD8D87AD2BULL, 0x020E46F58C667D22ULL, 0x62660E90FFF98141ULL, 0x93F9182F794A430FULL, 
            0x5B384586E7CBBC86ULL, 0x96D2C4109CE9D2F3ULL, 0xEA44AC722F270D6AULL, 0xD25E558E27CC0D5DULL
        },
        {
            0x81022C06B78C565BULL, 0x44AE697ECD4014F9ULL, 0xF813B1319145B3C5ULL, 0x9AA608FFD35D2229ULL, 
            0x207841F2AC4A11ECULL, 0x87A451CFF4BEA145ULL, 0x6B686BD8F18DF147ULL, 0x56D1CF6BAE84D50BULL, 
            0x563A60950DB634E8ULL, 0x6D13C336F0CF9B7FULL, 0xAC3BAC92CC2EA4D3ULL, 0xCEB4A812BDA76AF6ULL, 
            0x8B3A005955F5675BULL, 0xF9FD488F56F371F5ULL, 0x6BD5160B4E8027F6ULL, 0xCEB359CCF797C25DULL, 
            0x8FF99C37AA6FA6F4ULL, 0xD4618D43C85A82C9ULL, 0x1B450437647621D2ULL, 0x034377AAB3FDA0E9ULL, 
            0x32EFA8520ECDEE93ULL, 0x08D62A4A891248F9ULL, 0x85FDA6386D06E4D8ULL, 0x979FCED285057AF7ULL, 
            0x42EEACAA996D3E05ULL, 0x9F1092E38CA80680ULL, 0x920195D266178616ULL, 0x91D2ABC0B4D18F77ULL, 
            0x8E9224A312AC7EF3ULL, 0x4E71C1BD30890D3EULL, 0x232B20B1B6D9A582ULL, 0x9D23C01433206381ULL
        },
        {
            0xFFF51B976B9B63B8ULL, 0xDB5D0F303694A74BULL, 0x8273D58035CC84CCULL, 0x7B619C86BD86088BULL, 
            0x0CD5DC1C0C1EB209ULL, 0xE3DCB8C96F2E1F4BULL, 0xDD5D78090EC67459ULL, 0xA9179BF9E0A8908FULL, 
            0x491E8159003B1B13ULL, 0xC9A4EF296DEACEE8ULL, 0x9BC8CF9C07E3583EULL, 0x4E699B5C27B67602ULL, 
            0x55EAB66A920ED52EULL, 0xB40C650F0D22F801ULL, 0xE36384BE47CACBCEULL, 0x8F9F9F3904C015E8ULL, 
            0x88A182C0130AA0B0ULL, 0x1695B2C3E7581364ULL, 0xA95AC6716A890041ULL, 0xBE80D457407014F8ULL, 
            0xC160128E6CFF452EULL, 0xF9EDBC71A46BB6B4ULL, 0xDADACB45059007C1ULL, 0x441FBBF3107B4773ULL, 
            0x70B030A9EA9BFF1DULL, 0x7F249661A5D4B66AULL, 0x88013FAC751A24BDULL, 0xCE320FE685C5ED81ULL, 
            0xA435E172EC5FA6C4ULL, 0xE2D20BB8662166AFULL, 0x30080644B49652BBULL, 0x0BA354F2BFD49F90ULL
        }
    },
    {
        {
            0xD78220DCD42CE5AFULL, 0x256FCEC9716493E9ULL, 0x2CF8ABF1BA31719AULL, 0x1E83C6A8E45912EAULL, 
            0x39DA71A3732CCB21ULL, 0x471748F89FC9417DULL, 0x5EB21345DDBC2DE8ULL, 0xACCB58BAB0181D2AULL, 
            0xCAD383949982535CULL, 0x136CE82B268851A8ULL, 0x55BF0D78BF2A6FC6ULL, 0x27D7A2588C8D3984ULL, 
            0xAE6E95EB506B90C0ULL, 0xB69A8CF425F6CEB4ULL, 0x068A2B4D25CF9B1DULL, 0xE04E1C02FED63052ULL, 
            0x9B4B80A470BAE165ULL, 0xDDF78BE2B8DC8B5FULL, 0x635F8EDE81D090B3ULL, 0xCCED871089B85D63ULL, 
            0x08D82498777760A8ULL, 0x457DBB316F88FD3EULL, 0xEE2303390C8721A9ULL, 0xB6CEBFCB7F9EFB31ULL, 
            0xCBC7FF5872139DB6ULL, 0x8E0F2056DFA3CA49ULL, 0xFEFFA9631F2C59F8ULL, 0xB7E44C01697E112FULL, 
            0x2B06ECC116A331A7ULL, 0x10331D3F7529EBB9ULL, 0x6862C2B2B0AEBB15ULL, 0x527D5A9621C62D71ULL
        },
        {
            0x1B978AAB4C16EE59ULL, 0x861377B5D54DE6FEULL, 0xA9A4BDA42B551E15ULL, 0xD078F4639B5ACC28ULL, 
            0x9AD712B86DE91D1EULL, 0xDE6D117F7FE8196FULL, 0xC84EF9EDD2F86769ULL, 0x48CB3498B20DF0BBULL, 
            0x858DF053CAF21969ULL, 0xEBB9B9332C478E98ULL, 0x90F060C07D24CFACULL, 0x3E9B3BE18A5C7CDEULL, 
            0x579C02E7A7CBA212ULL, 0x4FC3D289FC231412ULL, 0x2E6A8A8600A2B86BULL, 0x91CBAECFF6BBD468ULL, 
            0xF68CB33BA244F673ULL, 0x3B70B8F0ECCDA7D2ULL, 0xED18537B974DF2C3ULL, 0x653E699CFC21B8F0ULL, 
            0xD592587B79DF609AULL, 0x7D2ADA440540FD78ULL, 0xAB0D2C5561FDC427ULL, 0x3EE82ADA0E4E3EE1ULL, 
            0x050B89A9685BD106ULL, 0x937142384F29CC82ULL, 0x378147E0A06C9FAFULL, 0xDF0B3B3A759F6FCFULL, 
            0xE8E28D461B60B959ULL, 0x56AD8DF49FCC2CF2ULL, 0x98386C723FAA80D0ULL, 0x4DC0AB6FD8D84111ULL
        },
        {
            0x43DA0DF8950567D6ULL, 0x6DB8AE058C4BB899ULL, 0x88AE9D8A966172D7ULL, 0xD8C03FB7EBCAE4FFULL, 
            0xE8EE1497887D6141ULL, 0x99A917F16200F100ULL, 0x65BC3BA4E393870CULL, 0x3094659A82D21EDBULL, 
            0x49F41CCED3709674ULL, 0x2B0EF6FCB524C468ULL, 0xB7028F1920B7927DULL, 0x7CFE4F2F86B874DAULL, 
            0x70EF00DA25EE45BBULL, 0x747662864135DBBCULL, 0xAC0CA4CEFD8902E0ULL, 0x009830FB23897AFDULL, 
            0xA7873AC6CD9AF15DULL, 0x29F0D03D6BF8B349ULL, 0x58CBE5DE7ABED879ULL, 0x356E5F6274611F3BULL, 
            0x22BED3B3302682AAULL, 0x3C3499F928E67452ULL, 0x912C8BDE6534F057ULL, 0x7AD64DD9D822FC5BULL, 
            0x5A70FB17D5A9C9AFULL, 0x178D169A282C22C6ULL, 0x0DA0562923DD72FAULL, 0xFECC96A2718FF093ULL, 
            0x27FB8BF3AE03FB7FULL, 0x2168E7AC6BA7A9D4ULL, 0x5199002919FAEB45ULL, 0x4420DAF259F8C81FULL
        },
        {
            0x0FFBDD36A831BA91ULL, 0x89A6826D35BE481CULL, 0x485FED05FF627A3DULL, 0x6B633FAEA5B6BF72ULL, 
            0x3ACB180AA9F12B44ULL, 0xCC2D04D4EB8A8D19ULL, 0xB685318A695A658BULL, 0x0BA1A41A1BC3D1B6ULL, 
            0xF6A0E4360437759DULL, 0xE7066306261FA6F7ULL, 0xADBF32CEB3EA2D33ULL, 0xE5FA152F70064CEAULL, 
            0xDC44A9D083ACB9B7ULL, 0xAE0144816BA2138CULL, 0x04B850200C5527A2ULL, 0xAA77429444989467ULL, 
            0x8E36B0E14FF155CDULL, 0xBB48797AF68D66FBULL, 0x2D085844838B3C72ULL, 0xD278FBBCDA96A76BULL, 
            0x69012E9F878FAC1EULL, 0x889F6767B7264516ULL, 0xBCA2C0174771FAB1ULL, 0x0CB84E6FBD6234F3ULL, 
            0x73CC276598BBAB8FULL, 0x28CE763672478EE2ULL, 0x56BDCFD8F61BEB0CULL, 0x1E344043463480C6ULL, 
            0x09BCEEA800035F22ULL, 0x149960869137E38DULL, 0xB9CA36B246F83BDFULL, 0xDFCF6442C2F13654ULL
        },
        {
            0x7FCBA4D019D6EF83ULL, 0x62A1F5B88AA3525EULL, 0x3CC9EC1618F1358EULL, 0xC0E83E8A030A60A6ULL, 
            0x2FAABB99725C0A2CULL, 0xD01129C76C4CAA52ULL, 0xA826365958823443ULL, 0xDBD89AE64B567FE6ULL, 
            0x0E1D25CFDE01FEC8ULL, 0xEAC545DB9799B55AULL, 0x93B5AFD8DC2C6628ULL, 0x6665B55156D3BCF6ULL, 
            0xAA86CE91B4C896A1ULL, 0x6DF006E6C2A7B0BAULL, 0x4178620B28F22D6EULL, 0x7E5E0B920738E533ULL, 
            0x6A6D048C695BD4B4ULL, 0xBDA08D7015E3A4B5ULL, 0x21AD7F834FEB11BDULL, 0x5C1D61507F98811DULL, 
            0xF029BBE6ABB8A9EDULL, 0xD13DE6D15A5005B4ULL, 0xCEBF37C05CA45D8FULL, 0xA8D69FE5AE7CA481ULL, 
            0x614063B411070C1EULL, 0x1E9515786ED6CDEAULL, 0xE63C0FC0B921BC6BULL, 0x3D68ADFF090E5FACULL, 
            0x787E7292B39F72CCULL, 0xB3B44B47C8A83853ULL, 0xBAEE23E048CF7FC4ULL, 0xDD03663EE2CEB013ULL
        },
        {
            0xA5F9A0932805EB27ULL, 0x978FBEA1E0CFAA96ULL, 0x0429DE137A5DBDE8ULL, 0xDB236C1B712A0D6DULL, 
            0xC9C62EB8B06DD4F6ULL, 0x06B4B148EBD391E2ULL, 0x28D5F32E0B6E6A42ULL, 0xE28A425C4F7F1280ULL, 
            0xAB3FF4B96544D48CULL, 0x60B88D30179F5428ULL, 0xFCA361B417D09D89ULL, 0xD2DA83112F690BF7ULL, 
            0x6A455332E7A79393ULL, 0x9405539545A2126BULL, 0x632995241486531DULL, 0xF3877F4EF5B9F0DCULL, 
            0x1B03F1E117E4E8D2ULL, 0x09A7020684014611ULL, 0x61CB97ADB08DE495ULL, 0xE72A8CA74A8C1586ULL, 
            0xD4CA634EBF4E8F52ULL, 0x8683212C1FD279DBULL, 0xCE89DC82EBDEA83AULL, 0x9CEE8F06802E2476ULL, 
            0x9DC6765591CAE3C9ULL, 0x52D2720496CAD5A9ULL, 0x9FF86829FC944EDEULL, 0x1722BAD261122F0CULL, 
            0xCDE64B7ECA7E9590ULL, 0x22395970E1B92C89ULL, 0xFB5951DEF8C2EF67ULL, 0xF0F476244EEB8B8AULL
        }
    },
    {
        {
            0x8EB02E92C1AAB514ULL, 0x0DCF10709AD000DEULL, 0xC11579CED8491FA6ULL, 0xAF2575189FFE6404ULL, 
            0x4A781B9B018E4604ULL, 0x664348CF2CA79399ULL, 0x02ADE1A023B81218ULL, 0x4DCDE8D66D14FFEFULL, 
            0x69AFD0C0297312C6ULL, 0x93750E70FE4B8B2CULL, 0x0AED7DA549B7B4A0ULL, 0x77DE92AE5B2D4245ULL, 
            0xD9317F0B464E86EDULL, 0xC27544D086B5B7AFULL, 0xDF65456EF0BFF9ADULL, 0x39C6355F15030ED0ULL, 
            0xE9A80B2B4618323AULL, 0x063FC395AA5F2277ULL, 0xE378FE023D176A66ULL, 0x48741B9A81167FA9ULL, 
            0xC139542DF5C2EE39ULL, 0xC71693E80BF3CCC8ULL, 0x6E369F0CB0A5B254ULL, 0x4D126F33C337E1B8ULL, 
            0x5ACE6AD118F91046ULL, 0x8CD9F1418263C048ULL, 0xCFDAE5BDE6013F12ULL, 0x7327F7592D0887F0ULL, 
            0xA19115AC9454F20DULL, 0x6319485C16853203ULL, 0xBC8462CBA6927E6EULL, 0x20CEDBDFB8C0F0E8ULL
        },
        {
            0x762C51C43A56538AULL, 0x4FF3AAB934E31CCFULL, 0x5961524CAD91BF88ULL, 0x40A784FC300EE2FFULL, 
            0x29B970B8A39E703BULL, 0x0DFBBC05D940C53FULL, 0xE68AB780D71A6B41ULL, 0x7006673D66666598ULL, 
            0x66FAB7C2416E2186ULL, 0x30A707FD934936B5ULL, 0xAFEFD81E0CFFB435ULL, 0x1B921CF6C187BD3BULL, 
            0xC1A4CAE4B663F09BULL, 0x5F14E72B8FBB81F2ULL, 0x085ACE6A9A309FA3ULL, 0x7DEDE23EEACE08A2ULL, 
            0x0E513A0C803FE3E7ULL, 0x2634F02183BCBA2BULL, 0x33F9EB353F3DB4B3ULL, 0x9D8AD3A6A72620BDULL, 
            0x345E894DB3C667EAULL, 0x01E8B58E6739794AULL, 0x8B609C385FF45388ULL, 0x853C76290A3E45EDULL, 
            0xE60D2FE31507AE51ULL, 0xC50067E9483A69DEULL, 0x785E602B62D08C76ULL, 0xCA4E8BF2EA41D6D0ULL, 
            0xD0C9AF8488761623ULL, 0x10C1B16929FE09ACULL, 0x79CCA2E7358C2CE9ULL, 0xE695CD8332859C31ULL
        },
        {
            0xBEF7C506A6EE6ABDULL, 0xB9342E3480663288ULL, 0x7BAB2474B373AB2BULL, 0xFE13DCDA55AE78F0ULL, 
            0xCFA0AC86BCCA7B49ULL, 0xAB20799721DBF8DCULL, 0x2569921785F3DF14ULL, 0x2855E1B8BAE1A92AULL, 
            0x8D86557A9E7C7F1AULL, 0x48B163CB803848C1ULL, 0xDFAFB3A3C1D5F03BULL, 0xF3898BC2E0ED3315ULL, 
            0x25053680D3EEBB22ULL, 0xECC6A7B19BE80721ULL, 0x0D20D63D271A249EULL, 0xF6D5379111CA7533ULL, 
            0xFF0D9D12BF7E5723ULL, 0x168542C943203946ULL, 0xD672051C2FF412A0ULL, 0xD2FC918009707084ULL, 
            0xC6E5D2F0B77D0977ULL, 0xD66D54A43787D17DULL, 0xD90C681772F8D317ULL, 0x5E3832A34F052D70ULL, 
            0xCFE8DF44A6E0DC5BULL, 0x898A55B6506EA10CULL, 0xE85E2677BEE50762ULL, 0xE67C13B15CD5D9DEULL, 
            0x4E41E58319574632ULL, 0xE80BCDA39D4AE15CULL, 0x9C1A37E9FBC905A6ULL, 0x0D4C8C661B689C60ULL
        },
        {
            0x3CDEAC38823B5172ULL, 0xAC6534CB3251680AULL, 0x0EC8852D8B0597ACULL, 0x1BC7D07CA0FA29A2ULL, 
            0x7BAE3818D35190B1ULL, 0xB34A3A6E4D30290BULL, 0x9D171B61299DFDBAULL, 0x0A2DE46511804901ULL, 
            0xC1B1EE8818744705ULL, 0x814D4084D3D26CC9ULL, 0xFF28541DE6AF7C71ULL, 0x3C6DAF4394202C76ULL, 
            0xC83A577F285153C7ULL, 0xDB0A2860A0170982ULL, 0x80CB39F9CEB1F3ADULL, 0xEBE8553173C85937ULL, 
            0xE22C92B9ED4E5489ULL, 0x9E85BEC3016AA2CEULL, 0x34834A0499C2A684ULL, 0xEC272D7E7451C57FULL, 
            0x496E2DF958FF0D3DULL, 0xE265D530BCAEB3CCULL, 0x54F7C1297069AAC8ULL, 0x995F2455275DC790ULL, 
            0xDFEB3E73961B6A21ULL, 0x553DAFAB76E83BB3ULL, 0x0B83A87C3103AC97ULL, 0x3B385186597B2013ULL, 
            0x832980F90E0E2A4CULL, 0xD0605B0032778B23ULL, 0x7547B468BEB98FAFULL, 0xDC41095201363986ULL
        },
        {
            0xEEC04460B3A04970ULL, 0x950844BF7733A874ULL, 0x4729669B67775E89ULL, 0x04C7970557392824ULL, 
            0x215E92618BEF43F7ULL, 0xC8208EAFE0D86A09ULL, 0xA8FC24E0A82B0E88ULL, 0xFE65D1939397E36FULL, 
            0x2FF389735EB0B184ULL, 0x92ABC41F62A897C8ULL, 0x9AB3D1C3570C4B42ULL, 0x158B9A95F566F2B9ULL, 
            0xB8626DC8F6786436ULL, 0x9B7DB6E58AA68C18ULL, 0x768793B30AD63EF0ULL, 0x128CC6AF4841EC3EULL, 
            0x77D36DB7126173C5ULL, 0xFDCC9952D68BD8E3ULL, 0xE03B96C6E850316CULL, 0x1ECF62642429D3F2ULL, 
            0x3DF5516894FFCA34ULL, 0xC78ADC659D09D841ULL, 0x022B3367F85A01E5ULL, 0x89127601760DE721ULL, 
            0xD8F11E8BD5A96FC1ULL, 0xA5462AC4A6B6CDD1ULL, 0x695512EC64293F7CULL, 0x6685DD50A002E416ULL, 
            0x971C0D40EA94C216ULL, 0xB2F2D357A4EBBA62ULL, 0xFA8143B8CBC20659ULL, 0x67EC8063D81419B7ULL
        },
        {
            0x33872401640C9401ULL, 0xC18AA0099749718AULL, 0xD2CB76B5E1EC3907ULL, 0x3E2E1D373C91CD0CULL, 
            0x42ECEC183CDD0057ULL, 0x4ADC66A413420485ULL, 0x5111363759D45C33ULL, 0x78E2B8AB97D71E9BULL, 
            0xE52F56436A0B4B03ULL, 0xEBCF24686F7B7139ULL, 0x6F7EE08EE7B8CF09ULL, 0x9390756DF46E0899ULL, 
            0x318F83F4A74977CBULL, 0x56325F164462E926ULL, 0x3324719DA7EFB430ULL, 0xF7BA36FF459EFAA8ULL, 
            0x2A21B0F2C9852FEBULL, 0x48A9D5FA52204440ULL, 0xCE3B3B5B5A3AC254ULL, 0x190CCCBBDE7483F9ULL, 
            0xBD4D74E85C703376ULL, 0x0F44AFFBED0CC13EULL, 0x2141A453BA1CD7F6ULL, 0x80783AFC4E24E02FULL, 
            0x0B0C0DB00AE0E150ULL, 0x50E4FD16BEF1E891ULL, 0x50008BF6E00762B4ULL, 0x489F28D427526E44ULL, 
            0x79504CDC25A651C8ULL, 0x43DA96631DF55EB8ULL, 0x4B43198F8EF59139ULL, 0x6CC17D4FE4024E0DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kSeedConstants = {
    0xBFB601ECF3290B3AULL,
    0xF96E1A8A969712A0ULL,
    0x5D279D4A716C834FULL,
    0xBFB601ECF3290B3AULL,
    0xF96E1A8A969712A0ULL,
    0x5D279D4A716C834FULL,
    0x5C98B112A30D01B0ULL,
    0x55DC132C848C13CEULL,
    0x36,
    0x61,
    0x88,
    0x92,
    0x30,
    0x94,
    0x0E,
    0x26
};

const TwistDomainSaltSet TwistExpander_Mimosa::kTwistSalts = {
    {
        {
            0x4ACB69C760F2934EULL, 0xA992A9BE19BFA1F3ULL, 0xA41097FE94F937AEULL, 0x20A4B27CFAC51913ULL, 
            0xEFDFEF394F81C683ULL, 0x8EFEFCEBBBB32ECDULL, 0x67303FCEFBAC8C84ULL, 0x3BA8CDCE20423254ULL, 
            0x1760981ACE02743BULL, 0x29D3D34CB947DF33ULL, 0xF6A8434C540CF8FAULL, 0x2EA5F3DE99EDFA30ULL, 
            0x98D20C037519EA87ULL, 0xA1E008A7886BAE69ULL, 0xD88FCA03BC531DF2ULL, 0x511DC5AB348C03D0ULL, 
            0x8A290DAB2684D8E9ULL, 0xF91836B9F3A9B089ULL, 0x5BF9071CCBF62941ULL, 0x3C8ED0A8B296ADF9ULL, 
            0xD8C020CEF283E4EEULL, 0x48CA3C2D74D82295ULL, 0x504F3F5CBDD89E74ULL, 0xB47B521EDBC860CAULL, 
            0x128447F382F98EECULL, 0xC5DCAF0BDA75EFECULL, 0xD391E50D23012FBCULL, 0x5676D8D79A5212DFULL, 
            0x31776ED555D68B9EULL, 0xAC03B97ADA3CD8CCULL, 0xCDFE60262873F28EULL, 0x86518FDB00E6738CULL
        },
        {
            0xC64DCC5E3729880BULL, 0x7CC0241B09150289ULL, 0x52CF98851F1E4667ULL, 0xF3E044E9716DD7CCULL, 
            0xC15AAE2816BAC873ULL, 0x17B0E3AF67254E53ULL, 0x1BF32E85C2870327ULL, 0x75C3A4D33F2FA762ULL, 
            0x47B72B0F2668AAF5ULL, 0xE830C969ECACC31AULL, 0x8EF332892F1398C4ULL, 0x5356887F41D9CE72ULL, 
            0x71224D157E01536EULL, 0x27366201FBC96D22ULL, 0xC0F62336B8A7B630ULL, 0x80C16B5B1EBE92B5ULL, 
            0x084A4A1B60BF473CULL, 0xB95905765B7F7642ULL, 0x409F0325003381DFULL, 0x5AD0B44911681C1AULL, 
            0x08E2AC8F9E52000AULL, 0xF26D3F08883F7121ULL, 0x286E554C4CD46BFCULL, 0xF019D758286A201AULL, 
            0x0F9A80AAF7448FABULL, 0x2C2966A45CAD828EULL, 0x869F8DA000753A69ULL, 0x65A8CEE280667FA7ULL, 
            0xC64ACEEC2E228B7CULL, 0x4328FA2EB1039619ULL, 0x2A7A1B21C9894F0DULL, 0x47FD9F252F89CC95ULL
        },
        {
            0x36855E436EA17FA1ULL, 0xD10F5C81560DA6A7ULL, 0x8EDF42454871C5DBULL, 0x60674F1DBBEA8ECCULL, 
            0x8013B9823D5C88E9ULL, 0x9425A613D67236DDULL, 0xC845ED73EC6B7858ULL, 0x26A6E255B233730AULL, 
            0xC70B09B1BECD1EB4ULL, 0x15832F11C213E4FDULL, 0x474D4743865EAA20ULL, 0xB912D34E877A52E7ULL, 
            0x4FF1C49F42743B9FULL, 0x05011A9C070F9387ULL, 0x3056625817A823CFULL, 0xF25E8EB847821435ULL, 
            0x4F825AB62B833F4FULL, 0x963E4B2AD5289B5FULL, 0xF386CE62146C4C52ULL, 0x431F944C642F0D19ULL, 
            0xDC5467801CA9AF1BULL, 0xB677DB7CE8900C7FULL, 0x1653C92D76D768E2ULL, 0xDCEB9CF51592377DULL, 
            0x2F0621C2617B25F8ULL, 0x854CF0BFB82E99CBULL, 0x1F79E22F46B93E5AULL, 0xCF3D36C604D1F6D5ULL, 
            0x389A0E13FE0271D6ULL, 0x2D7DAAAF5E28D96DULL, 0x141C42961BFE834BULL, 0xAF5F61F8968B86B2ULL
        },
        {
            0x792CFDD58FA64902ULL, 0x535D318D3DF49CEEULL, 0xAED686B6B6FB76CDULL, 0x926556CC14B67DDEULL, 
            0x05CA359C25D441ABULL, 0x8A5B79B77E850A10ULL, 0x7FA60E5FEACF311CULL, 0x9CCAD09BCD20E40AULL, 
            0x55FA1D6D5C21D2A2ULL, 0x330E1E7E436C82FEULL, 0x7AC06B5077CC8D17ULL, 0x653D272E6F5AB4D7ULL, 
            0xA2F2F36956BAB18CULL, 0x77131ED6C5B267C3ULL, 0x5F5E098104C44622ULL, 0x2722E432C85AC141ULL, 
            0x759ECEF1FB120FDEULL, 0x937ED05F5D460A47ULL, 0x061030B317477D05ULL, 0x29CDA47BF45A4ADDULL, 
            0xE847A88615984EE5ULL, 0x3469C2F84743D103ULL, 0xCCF7634FBC9E1EC1ULL, 0xF54E9A33EFF5831FULL, 
            0x7DB14C29D94546BBULL, 0x39AEB193DE4B35F5ULL, 0x3DA9326F04890537ULL, 0x06D6497F2F84A2ACULL, 
            0x52540AB0F1856E38ULL, 0x5CCE42AFB9C6DCF9ULL, 0xC9FA8052E49E9B1AULL, 0x0DFD2DFAB4D5A258ULL
        },
        {
            0xF6BDBF1A999488A7ULL, 0x846858D74D7BCBF5ULL, 0x06B80C754965B000ULL, 0x7E7E02F51871EA29ULL, 
            0x29A90BBC915C6522ULL, 0xE46546CB40117FF8ULL, 0xB86B9175B615FE58ULL, 0xAF4EC5B5927D6034ULL, 
            0x451F92403A92A4D0ULL, 0x0753C6D6C7C4556DULL, 0x5E3B53C84AA8FDAAULL, 0x6D90927DA1D3C9D1ULL, 
            0x70780CBF8220F5D4ULL, 0xC70B87FD7E7F523DULL, 0x61FCF8F80F441420ULL, 0xD88464B3E9809EE8ULL, 
            0x7F1914519F394B71ULL, 0x4D06300D392294E2ULL, 0x049F2499FCFD5A9DULL, 0x89E5D89DAB45A1E2ULL, 
            0xF6EF051F17068358ULL, 0x26093A1D37C6102FULL, 0x15B1529F824F714FULL, 0x373EE2F72322D91BULL, 
            0xE958D91BEAAB3462ULL, 0xA298E9DE8883DF77ULL, 0x45AC5A6BB594F6FBULL, 0xEBF76EB286DFA88EULL, 
            0x80D58DEDDF3EE0E5ULL, 0xEE864B1FA1135E49ULL, 0xA336D70E1E4487D5ULL, 0x23F05F43A5A964D0ULL
        },
        {
            0x129DFB465E39B461ULL, 0xCF3B4DFEF16A9021ULL, 0x5385B4219E986E3FULL, 0x27AE9700065225B9ULL, 
            0xE5B3044EF371826BULL, 0x8E354B37F577F48BULL, 0x4B707A81963EAD83ULL, 0x19E43FA5EAB9624AULL, 
            0x67498E5FA88F5C33ULL, 0x2DEE305C3B5AAF29ULL, 0x77B61B2F9AB98B13ULL, 0x5B009C46AA7CABE8ULL, 
            0x90A82C09E08D31A4ULL, 0x7AB3AC04B54A73AEULL, 0xC09114CE7EFFA846ULL, 0x5BB883A9E1352F88ULL, 
            0x11B42472592DA3A6ULL, 0x20FDB8BC3B6C39BDULL, 0x6A8F5910A2A01EE7ULL, 0x8797790711FCC014ULL, 
            0x1F026B388E8C18B8ULL, 0x463B487C263EF24BULL, 0x431EDA549B6CF1E6ULL, 0xE3CBA11226D8A699ULL, 
            0x210F9AC0E43D3B15ULL, 0x8F1C8EE51E18D925ULL, 0x915C9D78BB42D221ULL, 0x4198CF3CA5C960B6ULL, 
            0xC1B80BE0B1123F65ULL, 0xFD2E48DDC3BF79CDULL, 0xFCB2151F397D7303ULL, 0x7A3A9203B3AAE813ULL
        }
    },
    {
        {
            0x6070C3FF49C73418ULL, 0x7F4EB0C32757F4ACULL, 0xA8EB200D82C264A9ULL, 0x95EF0CD18DB637C4ULL, 
            0x0C4BD0A0131D2766ULL, 0x271F92B566BEE7CFULL, 0x6BAD274EE430AD13ULL, 0x062384F9F14D7AA8ULL, 
            0xD751952EA445F3B9ULL, 0x4F57E2441265FFEEULL, 0x9B41566A67DEFE34ULL, 0xD616F9CB983E334EULL, 
            0x75B3F088B48D4597ULL, 0xCF9FD23DF1ED7533ULL, 0xFB57F009DA587092ULL, 0x78FD293FF084FD8EULL, 
            0xB6984DF23235972FULL, 0x21E8C8E81005C1FEULL, 0x35A7F3AE3ABBBB86ULL, 0x242E88689F2E571CULL, 
            0xCB702F6D8CCE636DULL, 0x44CC7AEBB515D883ULL, 0x0E4850C687FE6BE8ULL, 0xEFD602E046C1991FULL, 
            0x97B15C99A1E9F0F6ULL, 0x38938368336ACB8DULL, 0x77A9AC055ED58A82ULL, 0x5AA384C4169CF740ULL, 
            0x50F4B3D545B9AED0ULL, 0x8C80F0E4D9B71D8CULL, 0x943A3F8CA87AED5CULL, 0x7C9B6F2FF58D9804ULL
        },
        {
            0xCB463DCA1C07225AULL, 0xE35B2418468F493BULL, 0xEC1F6591AA78B8D9ULL, 0xE9F4B06BFA3AF974ULL, 
            0xB71184BEE46B3140ULL, 0x60773C8742CA0A3BULL, 0x1DB5DFD52C2B522FULL, 0x027BB59E93F61AA6ULL, 
            0x56CB1A45AD04BBFFULL, 0xEB6B23655DE1656FULL, 0xA347F89555B06839ULL, 0xD133F44B75AD029DULL, 
            0xA61EC6FB2185F83EULL, 0x3A564D4C04AED977ULL, 0x06839836ABB39BCEULL, 0x86C382FA1D0CE494ULL, 
            0xB6BAC2E25C267A28ULL, 0xA46EE0DABE1ED401ULL, 0xD2FE1F409EDC9427ULL, 0x0C3E1C8F60D4DB4CULL, 
            0xCF70DD39B7B9E283ULL, 0xE863F932194C433AULL, 0xAD436CF764415F81ULL, 0x4333E96C997579A5ULL, 
            0xA296AFE0521F7129ULL, 0x0C3FFC61D53D2143ULL, 0xA71C86441B16E7C3ULL, 0x164529E6E55B1657ULL, 
            0x737F341F4D02B7C0ULL, 0xB206ECBF70EB2EC1ULL, 0x4F94A48C1C03925AULL, 0x39B184F0BC567CE1ULL
        },
        {
            0x4005BA224EF13CB6ULL, 0x5550CF1F439DDF8AULL, 0xBB1A9BC132E21CE5ULL, 0xBD50AEB1653ED7F0ULL, 
            0xC9711A86872C816BULL, 0x2B870FBA60E91934ULL, 0x2E9BBB8FB8B7F049ULL, 0x3D31C7D1982B8147ULL, 
            0xB9EC7A1B362716C7ULL, 0x91F521632657780FULL, 0x8F38985C5A618D2DULL, 0xB27B51B9368C757FULL, 
            0x4A36EF218A08B00CULL, 0x46DB1C1224731163ULL, 0x0E89AAB7F525586FULL, 0x661D57F18AC2DD63ULL, 
            0x975B0717AD82C676ULL, 0x2D67B462CE2FE8A9ULL, 0x6628C2242195F4C5ULL, 0x6B3B9C6CFE732B9AULL, 
            0x00C87B968C8CEE03ULL, 0x1ECC1E73C530A3F4ULL, 0x13A791E34B95180DULL, 0x47DB2B01D506C55FULL, 
            0x7D5D571724232E3DULL, 0x02571BEA014FBBC8ULL, 0x0E86EF8689C86949ULL, 0xC95E5700F5080F1FULL, 
            0x9A81AE658B9ECE2CULL, 0x6D9ED997EE8E1D20ULL, 0xA04FC95055023064ULL, 0x064F7BCE6D7AD7BFULL
        },
        {
            0x57C54DB67C96A4D0ULL, 0x86AF37FFAFEE9F65ULL, 0x84288229597EF9F6ULL, 0x8700DFFE82CF5ABFULL, 
            0x353D2F3777632232ULL, 0x813A34DEC5DB1913ULL, 0xA4B96A04E42FCA1FULL, 0x5C65EDCEAC2081A5ULL, 
            0x2408569790832AC5ULL, 0xCF9B7A1605EEF6A9ULL, 0x8BCDA0F03E0F2EC1ULL, 0x4B7119DBB4480C5CULL, 
            0x1CFA98FE4E507D2EULL, 0xB8C53861CDBCD53AULL, 0xE7B38561FD6812A6ULL, 0x544A07CCA509A12FULL, 
            0xA2A7D4481EE35A2AULL, 0xA0BF5DDBFF310373ULL, 0x1E28485A2E30CD45ULL, 0x4A51E30E84699E7FULL, 
            0x8DA4CC4D57E7FE8AULL, 0xFC5AB6A00056378AULL, 0x346D9FE623A8FE05ULL, 0xB41A914E4E22CE7FULL, 
            0xAA6384FFF6519DD5ULL, 0x5A247AFD449B2F8EULL, 0x1B805EF69AC45345ULL, 0x3EF8B1D89DCB2292ULL, 
            0x1405812EF4957785ULL, 0x050BC0ACBA0588BFULL, 0x220C57A9E03A7477ULL, 0xD0C812F774105BA0ULL
        },
        {
            0xD6F73D544D105A81ULL, 0x735FDEDDA720E4E6ULL, 0x3805BD1E9C9DBC3DULL, 0x7E6BA5AC5F4CD20EULL, 
            0x439F211712B65C19ULL, 0xBC7287A7BD1EBB5CULL, 0x7190738CCF5A422EULL, 0xD845538856BF06F9ULL, 
            0xBC359BB0A9E83771ULL, 0xAF3C14C41D2BCBB1ULL, 0x8588390AB50DC43AULL, 0x3289A308DDDE2FFCULL, 
            0x741ADF108911C1B0ULL, 0x21AB117B40EB8ADBULL, 0x1DFD86E9A8172B9EULL, 0x1B0941539F972F09ULL, 
            0xD221256318052237ULL, 0xE8AC74CDE0261ABFULL, 0x1F466A6EBEE69F08ULL, 0x89DCC410C5BAB3A2ULL, 
            0x0194759716A383CFULL, 0x04CA341C585E5DB8ULL, 0x953C8B783538D02FULL, 0x95C25F73309CB4A3ULL, 
            0xA405E081EC09D3F4ULL, 0x2142829A4FC9E04EULL, 0xF69591AB34C4E5C4ULL, 0x43474C5DD27807DBULL, 
            0x349A1A00946AC83BULL, 0xC76B72B914EADCE1ULL, 0x312036B988432192ULL, 0xEC9ECFE71810EE0DULL
        },
        {
            0x4C1981C3A956BBDBULL, 0xC7761507808005CDULL, 0x6DF932EF4E386887ULL, 0x3A677BE647940175ULL, 
            0xBF8B9701F4E1473EULL, 0x3082099D750EE9F1ULL, 0x935A61339EA0E287ULL, 0x38F05EAFB355A142ULL, 
            0xFFAF52EEEB56E2B5ULL, 0xD187B2A129F97F6AULL, 0x445678B54895C69DULL, 0x7486B52353A5DDB4ULL, 
            0xD809BD91B1D854F6ULL, 0xA2BABCCED0F62200ULL, 0xDB4C44594B062FBAULL, 0xFFA157287D2B371EULL, 
            0x510E6FC021238356ULL, 0xD66438898A328226ULL, 0x3DBFF363F1AB022CULL, 0x4744570A62D776EEULL, 
            0xB29EA1595FC97C55ULL, 0x61BA2018A84E1A86ULL, 0xDFF7CB8E2ED2945EULL, 0xEFFD18EAC404E07FULL, 
            0xB86ED7665CD3FEEBULL, 0xEC74D885514789D5ULL, 0x0F7D85AB3C442017ULL, 0x2ACB8BC1C1759F69ULL, 
            0x9194834F3CFB5618ULL, 0x7459A663312B2136ULL, 0x24B7BD54A7990A07ULL, 0x519BA24BEA15C777ULL
        }
    },
    {
        {
            0x33551D08ACB75BF7ULL, 0x5669E5D4206E11E2ULL, 0x993C64A7FCBA7B3EULL, 0x966927FB7D44CAD1ULL, 
            0x8436131FC943D2BCULL, 0xC7A65DDAFBCB78B4ULL, 0x730C82F7C7E49541ULL, 0x8CF3FE7A7F138AD1ULL, 
            0xCCD799379F43EC58ULL, 0x103C7098DF67A8BDULL, 0x71DEE77CD586B10EULL, 0x94DFF024946EB651ULL, 
            0xB7096F59D14619D1ULL, 0x2736822E765A2A6AULL, 0x93796C2B86203299ULL, 0x2FDBDA8470571906ULL, 
            0x7BE1F26DDEBD2B4EULL, 0x859B7DF5180CC691ULL, 0xC545E1AD3E81136EULL, 0x8A46FF8674C8F14DULL, 
            0x4843D46A3592E4D0ULL, 0xD1AE5144670BACD5ULL, 0xE95104C7800571CFULL, 0x68494D21E6B25689ULL, 
            0xC7DFBAE5AD4F80CDULL, 0x69E460BAB05F6C44ULL, 0x377D154DD788CFF2ULL, 0x18F3FF97B2343EE3ULL, 
            0xFAE6B5D905A5E520ULL, 0x78151F87953D6675ULL, 0x97043E8D1C302385ULL, 0xB389F4B01F63A487ULL
        },
        {
            0x9C3421C8DA84EB16ULL, 0xC4229AEB9E6968D2ULL, 0x2AD903E6C7FC3B4AULL, 0x81662CD20B1E8BA1ULL, 
            0xCCDF8DE9FBCFDA22ULL, 0xFBF2CDDA0CC5FDC3ULL, 0x5B0BED77D066FBBDULL, 0x79731D2F6F3C35F1ULL, 
            0x2B81F991EC595814ULL, 0x7DC45E0574AC9499ULL, 0x3D0A4EDB4E85E7DFULL, 0xE9450072848A9CA4ULL, 
            0x300F9FA9F8EDDEBCULL, 0x5F66D8F38E6E3629ULL, 0xCD1D7C8E8F661E12ULL, 0xA459EF7137F83E30ULL, 
            0x8B40562951D83EF9ULL, 0x84766D07EF562FD6ULL, 0x18176532424124A2ULL, 0x7AEBAB651105D5BCULL, 
            0x478CCE3546C83A7CULL, 0xDEAE6A9767B2AD4EULL, 0xF7D3D5D19B0C7B02ULL, 0x99C45589B3DD7494ULL, 
            0xFBE10D6313BBE9B6ULL, 0xBACF9D8DA4611481ULL, 0x1AFBDEF98F52D1F1ULL, 0xEA0014FA240C2376ULL, 
            0x8CE12202134F20AEULL, 0x55A673D934E9AF3EULL, 0xF5839E13296A0A2BULL, 0xFD263402AE9764E3ULL
        },
        {
            0x3478595FA3414CC2ULL, 0x68964CADD6F0D3DEULL, 0x07E00763B7866C99ULL, 0xE0F3C30F5DA5487CULL, 
            0x6C8E0FCF82A5E9EDULL, 0xCC28D647C2D9CF64ULL, 0x4F5B1AD9D882FDECULL, 0xA780FE1DB6B8EFF0ULL, 
            0x858208CCD867F5A9ULL, 0xF4E2659F0D32A7E4ULL, 0xF7E0483A62A36E48ULL, 0x1294B1D2CE71470FULL, 
            0x5F52DA7AE8E4C4FFULL, 0xA6CC6903B35A01FDULL, 0x121D6344AE838528ULL, 0x6786D12F8373B8D3ULL, 
            0x68E57BD0776C0B96ULL, 0x8CE55D5661214789ULL, 0x1E1C56485456B394ULL, 0x4AEF258D945C6D64ULL, 
            0xD53B7B7B463DA295ULL, 0xB98D02EF18C29CFBULL, 0xADB833E9609B51C2ULL, 0x8871DB6D69E29095ULL, 
            0x20D126EBEF2C773BULL, 0xA53B265ACC2C2FBBULL, 0x0FE9E7DB4B194D44ULL, 0x14401BF95999E718ULL, 
            0xA6071B4610C2538CULL, 0x22841408BA121B66ULL, 0x8CFE157D77DB63C5ULL, 0x20586C59E0EE1239ULL
        },
        {
            0x5B48BA48054067BEULL, 0x58AAFD70D3E39181ULL, 0xAAB0F5DDF353EB85ULL, 0x5491B3262E6E8384ULL, 
            0xF3701D9606F9E83BULL, 0xC4E6EAA77181B1F2ULL, 0xBE03311B258C9DAAULL, 0x3D6F6A30A25D8814ULL, 
            0xC9AB998DF221CE85ULL, 0x144BD61B2A261AF2ULL, 0x3D05EAB9CD64C956ULL, 0x9FBAE41E1D986B4FULL, 
            0x76E1D4CD0C78060DULL, 0x579B5604EF5017B5ULL, 0x5C55167E32DC35F1ULL, 0xDD3B5CAC10312BE7ULL, 
            0x458ACFE5E95619B9ULL, 0x851CC4B26DF1E4E8ULL, 0xF5D139F216D8BC13ULL, 0x7E4B1FC7809BD5C6ULL, 
            0x8F654BCFFA17FEACULL, 0x7E2CDABC47BB7475ULL, 0xE90CBC911637828AULL, 0xA9857F8379B3D3DEULL, 
            0x5E4C930DA477E464ULL, 0x26FCA95EE9A6C9A7ULL, 0x7274EBC0A05FEEA5ULL, 0x039113BF3E331806ULL, 
            0x7B3B4132B07EB225ULL, 0x024C6E0A74A85D1FULL, 0xCB960A820A6FB65AULL, 0x5E4DCFC85CF9554BULL
        },
        {
            0xEAA97CFF39185F6EULL, 0x772A8016F2EABD7BULL, 0x13370BC40F5EEB4BULL, 0x8D7851B2C5EEB288ULL, 
            0x63562E92023988D0ULL, 0xA5325766D2E489E9ULL, 0xBE049D3E6040675EULL, 0x7C885B2FCBAB664DULL, 
            0x30C9F3435283DD0CULL, 0x908F93C694DDEBC0ULL, 0x6D8EB443D72FC1B8ULL, 0xB63552F09FDECC13ULL, 
            0xBC049798F72DC353ULL, 0x75AFEAA4CF981AACULL, 0x2579D74667EACD50ULL, 0x3D1C9EEDAC9E3F3EULL, 
            0x7179A953154C6AA0ULL, 0x550AB62F87066BC2ULL, 0x32D9B91DCBB0F7D3ULL, 0x91500206A779EAF1ULL, 
            0x173062611ECC0FB0ULL, 0xB7EE0ECB0DB751E3ULL, 0x7666F133CED990B9ULL, 0x770CC365FCD48118ULL, 
            0x008FA2C0C43B59C2ULL, 0x8AAF13EDB0C51F20ULL, 0x8D4BAD4E60560B51ULL, 0x93CBD1F87F095C23ULL, 
            0xEA6063C9F688A647ULL, 0xE11C2B37DFC272C4ULL, 0xA1DFD9EEC6276B8EULL, 0x1495559C473E0FC7ULL
        },
        {
            0xE09ED281186FCA0BULL, 0xB0E00E5FA755BA6CULL, 0xB0A9828168A94FC5ULL, 0x823C19B62A5C16E1ULL, 
            0x25BD0126A7394B47ULL, 0x5FD2F29D4716E520ULL, 0x6A279375E21DD409ULL, 0x7E8B9120C3F1E505ULL, 
            0x112AC75D33364927ULL, 0xDC6DCDBE1B0C57B5ULL, 0xC46F4AAF0535C85BULL, 0xF812945F9DF64355ULL, 
            0x1C84E11278358AE4ULL, 0xA43D537378CEC643ULL, 0x12595298B5F02050ULL, 0x62CBC67B079EB243ULL, 
            0x5945EBFADADD4DACULL, 0x28BB5CC30DA248D0ULL, 0x83E0A87A84DE9C29ULL, 0xFBD0BC4E3F39E37EULL, 
            0xCC526129A08D6F4CULL, 0x20AA6A3C8313FCC5ULL, 0x06FF103563EA384BULL, 0x742E3FE179B0724AULL, 
            0xA7B911FA589700AEULL, 0x4A04BCEDDE03110BULL, 0x1B1AF240E3ED601EULL, 0x72C82E1F56D5022AULL, 
            0x808A791AD158D604ULL, 0xB32E636F7D397709ULL, 0x4F2F33AD5DC2D2B8ULL, 0x371A84C8CA562016ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kTwistConstants = {
    0xDCCEF05CB03192DBULL,
    0x74CD5B3DFD73ACD7ULL,
    0x35EB631E21DFBEC6ULL,
    0xDCCEF05CB03192DBULL,
    0x74CD5B3DFD73ACD7ULL,
    0x35EB631E21DFBEC6ULL,
    0xA21D33751329919CULL,
    0x6F65529F0CEA138BULL,
    0x71,
    0xFF,
    0x1F,
    0x5C,
    0xAF,
    0xDC,
    0x93,
    0x7A
};

