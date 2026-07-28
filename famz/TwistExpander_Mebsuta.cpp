#include "TwistExpander_Mebsuta.hpp"
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

TwistExpander_Mebsuta::TwistExpander_Mebsuta()
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

void TwistExpander_Mebsuta::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mebsuta::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB9BE029F94469B83ULL;
    std::uint64_t aIngress = 0xAA64D6D967466EFEULL;
    std::uint64_t aCarry = 0xBA38A08E228959A6ULL;

    std::uint64_t aWandererA = 0xC9C924B1672094BEULL;
    std::uint64_t aWandererB = 0x8F021AF3ACB0F5E9ULL;
    std::uint64_t aWandererC = 0x808D55A05972C5A4ULL;
    std::uint64_t aWandererD = 0x9BB8C52A89B042CFULL;
    std::uint64_t aWandererE = 0x9EEE2082B497D58CULL;
    std::uint64_t aWandererF = 0xA32FD76BB8849027ULL;
    std::uint64_t aWandererG = 0x8CCEED7E5F5F21A5ULL;
    std::uint64_t aWandererH = 0xDD06B82B05D28B4EULL;
    std::uint64_t aWandererI = 0xCE3F701405CBD369ULL;
    std::uint64_t aWandererJ = 0xA92D01E8D042E731ULL;
    std::uint64_t aWandererK = 0x894164B70C05F753ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xFF843400ABE97E86ULL;
    aIngress = 0xAE2172BEAEEA2ACEULL;
    aCarry = 0xA2E97114A7860262ULL;
    aWandererA = 0x8355E41DE33312DEULL;
    aWandererB = 0x8F251ECC06CF53BFULL;
    aWandererC = 0xD29CBDBD82F76575ULL;
    aWandererD = 0x960EF5BA96611109ULL;
    aWandererE = 0x9FF686FE1D4A27F3ULL;
    aWandererF = 0x8060050E92D1D591ULL;
    aWandererG = 0xE6FEACE31001671EULL;
    aWandererH = 0xC046EA2D1FD66001ULL;
    aWandererI = 0xDC54F3E383244E28ULL;
    aWandererJ = 0xFF363EAA3A7CDE4BULL;
    aWandererK = 0xDB1A12FB5771B6A6ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xDD9A7012E9500EC8ULL;
    aIngress = 0x9EAFC519F9443A54ULL;
    aCarry = 0xB4E6615A488A8422ULL;
    aWandererA = 0xFEB8D4E5F29E14B2ULL;
    aWandererB = 0x84E5D432C5D47E4CULL;
    aWandererC = 0x94B4C4BA63E0722CULL;
    aWandererD = 0xD1E75CF94AF7BAF6ULL;
    aWandererE = 0xDA1D3D07965280E3ULL;
    aWandererF = 0x9999951B0D9B1D8FULL;
    aWandererG = 0xDD5EEDE9A8E63645ULL;
    aWandererH = 0x8ED75EEB07A766C1ULL;
    aWandererI = 0x95D8E9F225FA66C6ULL;
    aWandererJ = 0xD6B358D133D6DE00ULL;
    aWandererK = 0xF4844656C5E17A48ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xE915A301BAE41F6AULL;
    aIngress = 0xF8E045AE891B0472ULL;
    aCarry = 0xAFEE0840EF4C4B72ULL;
    aWandererA = 0xED66E6BAB2051CFBULL;
    aWandererB = 0xB7BDC66A31D6D8C6ULL;
    aWandererC = 0xD1A4475CDB2185F0ULL;
    aWandererD = 0xAC2179BF3FCFC284ULL;
    aWandererE = 0xC338B9C381443CFDULL;
    aWandererF = 0x9874AD37C0156A58ULL;
    aWandererG = 0xFAA619AC3F34FC55ULL;
    aWandererH = 0x92E1DDA3CA24F19EULL;
    aWandererI = 0xC6071CE4DF21BA87ULL;
    aWandererJ = 0x9273B72E23CED2EBULL;
    aWandererK = 0xBA11D4D0940B74E6ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x90DC56BB85FC84C2ULL;
    aIngress = 0xF9B16DDA44014B11ULL;
    aCarry = 0xCD63BA4371E35E5CULL;
    aWandererA = 0xDBF7EDA0393045F6ULL;
    aWandererB = 0xD8938B052D6E5101ULL;
    aWandererC = 0xF47F9846C638E368ULL;
    aWandererD = 0xF115E4A0969027CFULL;
    aWandererE = 0xD98870E3AACABF03ULL;
    aWandererF = 0xEFF185A4C5D8E1CFULL;
    aWandererG = 0xF9C4FA56498E8F8BULL;
    aWandererH = 0x8555B7F58180039AULL;
    aWandererI = 0x9E1A9466D0ACFC64ULL;
    aWandererJ = 0x922FAE8AE8370BA3ULL;
    aWandererK = 0xBF06E47EDF2DD7B4ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x8EBC2DCD8C6E83A4ULL;
    aIngress = 0x86CE8C22E45F1ADEULL;
    aCarry = 0x8D403AEED6E6AA50ULL;
    aWandererA = 0x83FE8CE1A05B3E8AULL;
    aWandererB = 0xE73E001F2E742DE5ULL;
    aWandererC = 0xB447BBA7F69D5D6EULL;
    aWandererD = 0xA2836950BE4DE080ULL;
    aWandererE = 0xA63673F8472E585BULL;
    aWandererF = 0x8931ADEEFF9FB8D4ULL;
    aWandererG = 0xF3F2BA0339F57D40ULL;
    aWandererH = 0xA5D811708468EAAAULL;
    aWandererI = 0x9FE0868641BD0E10ULL;
    aWandererJ = 0xCB54452B61994E6AULL;
    aWandererK = 0xED1F7267E11C048AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xDCC2D598AC40BD80ULL;
    aIngress = 0x8E9BBAC8A640A318ULL;
    aCarry = 0x99A5E084F872C970ULL;
    aWandererA = 0xA5EC1FC3D11E0898ULL;
    aWandererB = 0x8FE691E409D50D20ULL;
    aWandererC = 0xAA57DAB590A40162ULL;
    aWandererD = 0xA53B9FCA1374A76EULL;
    aWandererE = 0xF572B8D6378E6528ULL;
    aWandererF = 0xDFF053CA0AE4B4F4ULL;
    aWandererG = 0x90A126EA32FD0A7CULL;
    aWandererH = 0xAF21AA66764C4B31ULL;
    aWandererI = 0xC270577D60CA9526ULL;
    aWandererJ = 0xA7438805436E1ACBULL;
    aWandererK = 0xED877C3FA588C85EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xF113F3ECE1180FB4ULL;
    aIngress = 0xF4FB3E505666F952ULL;
    aCarry = 0xE04B42016C7C7CA4ULL;
    aWandererA = 0xD0AC2A5223241818ULL;
    aWandererB = 0xF37744EB59272465ULL;
    aWandererC = 0xDB5749F9AD3D39A3ULL;
    aWandererD = 0xB87F836BE0BA2A08ULL;
    aWandererE = 0xEC1E675C617556E7ULL;
    aWandererF = 0xA88FEC1391D76840ULL;
    aWandererG = 0xBC08375425DE5AA8ULL;
    aWandererH = 0xE5FE2C5DBBFDA656ULL;
    aWandererI = 0xAB7845D6E526C671ULL;
    aWandererJ = 0x92E484CADF30FDD0ULL;
    aWandererK = 0x91D141D89D47B52FULL;
    //
    TwistExpander_Mebsuta_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Mebsuta_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Mebsuta::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD932B56A7B04614BULL; std::uint64_t aIngress = 0xF608B554DFB75963ULL; std::uint64_t aCarry = 0xD8969E902A58BFF7ULL;

    std::uint64_t aWandererA = 0xABCE5518407D4212ULL; std::uint64_t aWandererB = 0x877DA06755981B4BULL; std::uint64_t aWandererC = 0x8FF28001AF33B461ULL; std::uint64_t aWandererD = 0xE8522BCD7191A420ULL;
    std::uint64_t aWandererE = 0xD58A08951DD1F2C1ULL; std::uint64_t aWandererF = 0xB2F8BC7E7E285D1AULL; std::uint64_t aWandererG = 0xCE86ADE0F27785D7ULL; std::uint64_t aWandererH = 0x8AC72846ABE45856ULL;
    std::uint64_t aWandererI = 0xA909A176023AD161ULL; std::uint64_t aWandererJ = 0xDAF8A970B85F739EULL; std::uint64_t aWandererK = 0xAC476E433C664797ULL;

    // [twist]
        aPrevious = 0x8B6F1513E7A9C0A1ULL;
        aCarry = 0xAF0B33A319DFEA9CULL;
        aWandererA = 0xB38FA4D5748AC6ACULL;
        aWandererB = 0xD92FE2FB9679955EULL;
        aWandererC = 0xBA1CB021902F6198ULL;
        aWandererD = 0x862A9600ABD1AB4CULL;
        aWandererE = 0xB4ADE87D177D43A5ULL;
        aWandererF = 0xF87125C07D4EDF35ULL;
        aWandererG = 0x876BDEE4823ACA42ULL;
        aWandererH = 0xE584C7D695590E4BULL;
        aWandererI = 0xF4C9BFBBC56BE992ULL;
        aWandererJ = 0xB392A884314A96E3ULL;
        aWandererK = 0x883E54D45CEEC026ULL;
    TwistExpander_Mebsuta_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mebsuta_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Mebsuta::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mebsuta_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mebsuta_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mebsuta_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mebsuta::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mebsuta_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mebsuta_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mebsuta_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mebsuta::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 17 of 33
    // Exploration cases: 0
    // Structural maximin 523 / 674; family total 8607
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1645U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 17 of 33
    // Exploration cases: 0
    // Structural maximin 522 / 674; family total 8574
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1195U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeyRotateASalts = {
    {
        {
            0x30F3CA3F7A8ACDEFULL, 0x64E364BE20A0DA6DULL, 0xB94271E8B71F1EFFULL, 0xDB43212E96584EEFULL, 
            0x8322EBC211B39AA7ULL, 0xE8A5CC07EFC7D09BULL, 0x75BC7AA4CC1A2EA5ULL, 0x5486F8160DE8F31AULL, 
            0x10D8AED871656BB0ULL, 0x9DFD2E4D43609656ULL, 0x09E0A577C0773111ULL, 0x5B81B7C436474148ULL, 
            0x96039ED6F7779B19ULL, 0x432FA41A733C0399ULL, 0xB9A731925A715AF8ULL, 0x3F47018905A3296BULL, 
            0x681F53ED63DE6E50ULL, 0x607E1836A24FFD9EULL, 0x09ABC03C4B7B294EULL, 0x870237AE986DCAFFULL, 
            0x6508163AB8F12796ULL, 0x88F83B79FFA46C19ULL, 0xD16F2A8090CEF3F3ULL, 0x2F9E2E7A2D64CDE2ULL, 
            0xB2C6EC6E33DBA9BCULL, 0x2CC0497333869580ULL, 0x6ADD432F2A2F3879ULL, 0xCB09F499ABBB05FEULL, 
            0xCE33934AE5A1647BULL, 0x9A32B728C96BDBE0ULL, 0x2F00B6BB8567A906ULL, 0xBB25F7C87CC43A16ULL
        },
        {
            0xC18CEF0803B2241DULL, 0x3ABFCFE584A64F50ULL, 0x27097FF508D469E2ULL, 0xBAFA63D3D521B5C5ULL, 
            0x7E4CCA4DCEC7A3E0ULL, 0xFBEDC4FBA05FB477ULL, 0xAE3B773BBE3A5FB4ULL, 0xF55DF641521D43A2ULL, 
            0xE591FDDBFCC8C01AULL, 0xA02C772292B4152EULL, 0xFAA83E6D769EA1AFULL, 0x40D96D8C5E2CF2EAULL, 
            0x47AC3C9CDC2C1B47ULL, 0x9177025EED4C9F85ULL, 0x3B9907B75430B6F7ULL, 0xEDB05F70F50C728AULL, 
            0xBC8A3B006AAEF33EULL, 0xFDBB57540FEB37EFULL, 0xC66D13B4B26BECC8ULL, 0x38B9F3FEE02AACDFULL, 
            0x8C6E0A6FB45FC99EULL, 0xB134958A16E69E02ULL, 0x00CB8C313F16005EULL, 0xC8EF82C563A079D5ULL, 
            0x4491BA6ABE8F93C2ULL, 0xB4239E066C416728ULL, 0x0EB9E0413F176B8DULL, 0xD7BCE1375603CB24ULL, 
            0x4AF676FA69638296ULL, 0x4631BD829C56280EULL, 0x87762A84F6685007ULL, 0xAD19AE32A05ACBDBULL
        },
        {
            0xE6DC0CB5D2F15F28ULL, 0xF3E2B2409442B765ULL, 0x70B26376130F2DACULL, 0x31B14FB91D85EC5DULL, 
            0xF943C2003D0897CDULL, 0xD603E02FEBA53ABDULL, 0x879CBB4340ABCE54ULL, 0xEA67A657BE048444ULL, 
            0xC09BB2702A28CC6FULL, 0x1D61F6DA6FADCF27ULL, 0x97C0C31119BE2663ULL, 0x2B9534F12D89B9FBULL, 
            0x6AFBBB10DA7D9FCBULL, 0xB251629433C8BB2EULL, 0x91F9BCCF2103D04DULL, 0x04BCDAF259573022ULL, 
            0xC4341732A3C40D92ULL, 0x54B22AB28FD7DA9BULL, 0xCA34DD2E0D8A9448ULL, 0xD7B1E4CC69B8DF6AULL, 
            0xC1467CE067BE53B1ULL, 0x7113C4D11C2D57C9ULL, 0x0C61D143CEFE9647ULL, 0xF2BF98925E2199A4ULL, 
            0xB4896C80C4E0155EULL, 0xB66D0FBD368B09F0ULL, 0x1E02CA0D711969ECULL, 0xC2A4D42E4A9F3AE1ULL, 
            0x1BD50A86A0C2305EULL, 0x2E9B3A4C658F4F08ULL, 0x04E5E31DAE8CA0B6ULL, 0xD871C3B3558036E1ULL
        },
        {
            0xE527CB6A82EFE678ULL, 0x605F28F90D7284ABULL, 0xFFB2E597D6D3366BULL, 0xA6345A889083E7DEULL, 
            0x9A2C553F1ED757A0ULL, 0xF7173BCC3ABE5D8CULL, 0x0D053CD5F97BD2D6ULL, 0x75EAC7FBF959D0DCULL, 
            0xFDF2E3DC7AB875DBULL, 0xB5D6C25F3B1B4E77ULL, 0xA8C9370B9923C354ULL, 0x31C3DEAB9289FBD8ULL, 
            0xED80218F5E2F49BBULL, 0x407FBDAA36721F11ULL, 0xDA13649417DC6A22ULL, 0x3B26134FC4283735ULL, 
            0xBBED259E06C23A8DULL, 0x4478D6A8FB869A36ULL, 0x90E04078F5E7D06FULL, 0x28C8B6044838AB4AULL, 
            0x651BEF2C805C5801ULL, 0x945EB90112846071ULL, 0x434716EF66292D1BULL, 0x39DF2596B5936C2CULL, 
            0x3E8EF0D249AF3349ULL, 0x7DB66BA3007CC6A0ULL, 0x517C1F086E15DB06ULL, 0xEDBB093FE18C5BF2ULL, 
            0x78FCC70C92B412F1ULL, 0x9389E8119458F494ULL, 0x7D939C9850892C7CULL, 0x928B69B219B80CA3ULL
        },
        {
            0x1945D4628EF95C6CULL, 0xA27FD38B6CB2ED56ULL, 0x51DA4BDE6E81C7C0ULL, 0x9CCD5664EA58EED1ULL, 
            0x932E980200B4DB01ULL, 0xCC59FDDA5A98871EULL, 0x4E7244B92A5EFE89ULL, 0xA47E5369DC1578FDULL, 
            0xD5A46966CFAA19CCULL, 0xE13485151966D148ULL, 0xDA9A7A4D15AB0632ULL, 0xF653AB82A9E4D6C2ULL, 
            0xC3C6753D9923E1FEULL, 0xA8305E963AA68629ULL, 0xFFD9A080A8DEBAACULL, 0x7A135BCCAD484887ULL, 
            0x5F9754183FBD27ABULL, 0x9F7B3E217BD2C133ULL, 0xD1FA57898F174B05ULL, 0x29FFD9B078A73296ULL, 
            0x198D88239CC72E14ULL, 0xA1B00AECF44E037AULL, 0xB1A05608BFDD9BF7ULL, 0xCB4DC60A808C4CAAULL, 
            0x5493DE5533C2645AULL, 0x8BCC692DC68D56E2ULL, 0xBFF6F0CE4651BBACULL, 0x37BD03FE02AFAAA3ULL, 
            0xE9AFB32F9B113FFAULL, 0x77D08353A0CDB1F4ULL, 0xF6E8BAE7D753217DULL, 0x33FFF49658861F81ULL
        },
        {
            0xA9638FCDF9AAD9A8ULL, 0x573B870817E99884ULL, 0x26E2F8C0C7D46612ULL, 0x3C2023E4BBD445E3ULL, 
            0x4CAF4A96CB0174EBULL, 0x347E184A6B0FCA4FULL, 0xC821C7138EBBBD46ULL, 0x30548A570EA68DD4ULL, 
            0xABDE1740B9046107ULL, 0x093A110930C1BB7EULL, 0xF5A811DE02BC1238ULL, 0x644AFD6D602D2F21ULL, 
            0xDA00E71A8A07F94DULL, 0x248EE82DE24A54ADULL, 0x9DD3F3CD6D6295AEULL, 0x0D5866D5A41B1896ULL, 
            0x88BF1E5BB1EDE278ULL, 0x01FF6043A60239D4ULL, 0x3C637875D1F9CA43ULL, 0xF5424CEAC6370882ULL, 
            0x582880731A6B9A63ULL, 0xB829265A531F3B71ULL, 0x0EBA113E03013491ULL, 0xE3D80AFC81AF15B1ULL, 
            0x0C8460A15B9D7F83ULL, 0x549A55F612E4C0F6ULL, 0x4D7B665DD49C6FC1ULL, 0xF3BCDAA9F0713F74ULL, 
            0xAC307EA9C13FE5EDULL, 0x6A7A6FF6FB74844FULL, 0x8AF6AFE9F7FFDE4FULL, 0x0CE21040E1D418FBULL
        }
    },
    {
        {
            0x4E802C68893B6AEEULL, 0xA38B60944A604C36ULL, 0x881E65ACCC4C37E1ULL, 0x347287A397FC947CULL, 
            0xE7C26107E3763AEAULL, 0x058A8CE144A1C91BULL, 0xE04330BF34018826ULL, 0xAE8DF18434571368ULL, 
            0xF49FFC1A6C38E4E4ULL, 0x3E26B7EDF28DEB06ULL, 0x1B7E8B82AA170B8FULL, 0xA8969479CD01B207ULL, 
            0xF73FE7A244F18645ULL, 0x0B541C5AE5EA490AULL, 0x0BA7BF7395436CB4ULL, 0x2BA9D8B74E09A4DCULL, 
            0xB50998BDC8197E4BULL, 0x6FE5700D6D7EEE03ULL, 0xCD5C481EE8F0684DULL, 0xA5095CDA6BDFEDB0ULL, 
            0x7160C25706C76055ULL, 0x7BFB3696A3EE8425ULL, 0xCCDFF9FD5C7EB327ULL, 0x1982300225726621ULL, 
            0x8EAACEA65CA53E22ULL, 0xA371C297D31DFF03ULL, 0x1CEAB79DF3BD8FBAULL, 0x7F627E23257F9E0CULL, 
            0x3832D9A68E735933ULL, 0x84E7C01A11AB1FECULL, 0x6DCF33873C36C663ULL, 0x8F485488D92DA19DULL
        },
        {
            0xECB51A75622D8452ULL, 0xCE86DA16608339EDULL, 0x67121B9BCFCFB170ULL, 0xD7FFDF17F9B48131ULL, 
            0x4F5A6AD99CDE7626ULL, 0x72221976040763C1ULL, 0xA8FA7E437C02A097ULL, 0x7B9E623F1ECC767BULL, 
            0x7EF4CC3EF3CE05CBULL, 0xB3A48BAEA3BA81DCULL, 0xD72C61D8F842337AULL, 0x0BC192D67921BBA9ULL, 
            0xBB154ECD282BA1E4ULL, 0x5B881D66479CF9B3ULL, 0xFB83A929ADD29071ULL, 0xFD567C6E8C52429BULL, 
            0x221E38AC20E174E3ULL, 0x2B379C23271C3FBEULL, 0x586FEEBB0F0EA9ACULL, 0xC79017A480CF1632ULL, 
            0x72D88F21347919F8ULL, 0xF6F07D557DCC129CULL, 0x6E9395C55DFD5B61ULL, 0x8DEC4DFB48BD1872ULL, 
            0xC245D619064BF780ULL, 0x0B29C84A1E667EC5ULL, 0x786C5E97C1B006ECULL, 0xD023FE7C1E6F37DCULL, 
            0xF3EA13312710CD80ULL, 0xE8E20FDB953BFD5BULL, 0xD19365BA0440B21CULL, 0x6486E59A9846FB12ULL
        },
        {
            0x296B9F6AB5159A53ULL, 0xA8E5F33F0BE9A5BCULL, 0xA964868E30EC8682ULL, 0x2059FDD37E591630ULL, 
            0x7F5D54B1B571CB5FULL, 0xA55F8EF0C94C6EFFULL, 0x7F37F0A82DCBCFCBULL, 0xB78AF638D17D1191ULL, 
            0x5BCB6272400CFDFCULL, 0x1836396D85DC3828ULL, 0xD9B0DAD99A6EE27BULL, 0x7C871CD772418CA1ULL, 
            0xFC2E8366772271E0ULL, 0x30746D116583881FULL, 0xBC1796AA3CCDB391ULL, 0x9AD18F6EF4D04CC6ULL, 
            0x3C0574B06CF6387CULL, 0xF28D3FCC38187AA6ULL, 0xD6AD9FA47EDCE130ULL, 0xBF69514B5946106AULL, 
            0x021279E2756D5531ULL, 0xD64A5EBFDA7A58E4ULL, 0x454D1F81240A8F63ULL, 0x85908E6F82A25149ULL, 
            0x050D84DD8F6A33BDULL, 0x83416B50D1D05B6EULL, 0xC8875E585DB0C0D8ULL, 0x9955E98FD15E7730ULL, 
            0xE6928228A3C13469ULL, 0x9DED131462FEB6C7ULL, 0x56F82A225FD7CBC4ULL, 0xBBCF806EB5C3FB50ULL
        },
        {
            0xD86B04FA8EBCE07AULL, 0x72E829BEB7264380ULL, 0x833C33B136F32E76ULL, 0xC8CF454F02170F2BULL, 
            0x5D6FE3B15FB1028AULL, 0xE85DBED2733BC505ULL, 0x11C0FA10D1B772CFULL, 0x3D6666BDDD59690DULL, 
            0x7E86EB5DD7980389ULL, 0xF23EDDFCDEA1B8FEULL, 0x9F09E45521B7270CULL, 0x6DBDBF97574B1E04ULL, 
            0xFEB7F98FB010F37EULL, 0xEA6F0BDABDFBADB5ULL, 0x2CCF50CC75FAF27EULL, 0x871811B40462E688ULL, 
            0xE2247C0DC555AB34ULL, 0x5DB1E17766C75DCEULL, 0xDB68FD8B8BEAC80FULL, 0xA97FF1A4A99863D8ULL, 
            0xD9BDB6C620009C88ULL, 0xD17C6CA17426E289ULL, 0xB586A829AF04A90BULL, 0x9BB998C80707D945ULL, 
            0xCEFE0EF997015948ULL, 0xCECD8C8F2C6A0999ULL, 0x7D5EA1DAAC7CFBFBULL, 0xF378BEC75A29DB8AULL, 
            0x197730C2BA360CA9ULL, 0x6C7B2CBA9274E771ULL, 0xDDD01E1DE55B3D8EULL, 0x88B767753C536734ULL
        },
        {
            0xE063E790E39F8ED5ULL, 0x88A66919F2015B80ULL, 0x024283EC7F43ABB2ULL, 0xBEE35CB59B332CA8ULL, 
            0xB00FAFB4906BEAA2ULL, 0x4CDC068E648E614AULL, 0x26FAD3A088943C3BULL, 0x018D493CB74F5424ULL, 
            0x0D1D89DF24DA0CE4ULL, 0x170A8A160ED53DB8ULL, 0x60EFB8560BC87FF1ULL, 0x725D8E72ABEA9C98ULL, 
            0xA4E06834AF776B50ULL, 0xA481778CD74E3C78ULL, 0x898004C0B0416118ULL, 0x37651AE79DE0BDFBULL, 
            0xBD63E301E8B65403ULL, 0x4EA6FEC882594A64ULL, 0xA2839D7762ACAFADULL, 0x2F62984D05900AF1ULL, 
            0xFEC3D850A70CBDDFULL, 0x368CD83B4D69EBCAULL, 0xCB1339F8630CA887ULL, 0x96378D07D7E3C59CULL, 
            0x4C7665A67983B19DULL, 0xE34326E040592DA9ULL, 0x4D5BA37C9CA71374ULL, 0x33134736D82098C8ULL, 
            0x25E82D37EA3EC2A8ULL, 0xFC34515A6FB4AC0BULL, 0xCDF4D0230D476401ULL, 0x44F96153DEC56504ULL
        },
        {
            0x2B40406A53E06A3EULL, 0x3516B06ED29DCE21ULL, 0x5E66846C2F52ABEBULL, 0xA93F940640A5B45CULL, 
            0x3ECB8503C3920476ULL, 0x1D1C9230F0006A01ULL, 0xF4173FB2AE075CAFULL, 0xAC7C0B751CF1CC7DULL, 
            0x7D49890C182E4BB0ULL, 0xE30661B86E305EFAULL, 0x5D0385B9107D5C0EULL, 0xF53CFA21826084DAULL, 
            0x27AC5AD2842E88D8ULL, 0x323334B9CE72D871ULL, 0xE800BDE6FAB8E704ULL, 0x29F0635B54E52BDDULL, 
            0x73BCBE9851941D9BULL, 0x26BB2BE79666984CULL, 0x734355DC4A64DA27ULL, 0x3505ECF04A61ADABULL, 
            0x9286896DDD15286BULL, 0x78C8C926CF64BDA3ULL, 0x8C3944711BFD907BULL, 0xFD7ACBA909F6C59DULL, 
            0x4590D96E1EC10649ULL, 0x312BF6E30D8473D8ULL, 0x702C26C78D146F86ULL, 0x22A54AB99D310CFEULL, 
            0x7A564E0D4D4D32EAULL, 0xA7C64832AFB0C534ULL, 0xAB0A10F74CA02E6AULL, 0x476FC90CBD62F160ULL
        }
    },
    {
        {
            0x383A92581B7DFA8CULL, 0x2014B50FFF69BEC3ULL, 0x552B84EF70D5D9C1ULL, 0x88DCC3547654AD4DULL, 
            0x1C6CBF9DF280DFC0ULL, 0xFDE17D9A7E2109D4ULL, 0xE6ABED99761FCE0FULL, 0xCD439047DCB9011AULL, 
            0x39D3AE76F0EC691FULL, 0xFEC0A631BB2263CAULL, 0x4E55CF2A9AB70BCBULL, 0x1D9E7F6279B36C81ULL, 
            0xBBFD80FEA3AA7C97ULL, 0x4B45502E1AFEDD24ULL, 0x4F8F0EC997481B31ULL, 0x81728F6763C5CCE6ULL, 
            0xCC15F3E525FCAEE7ULL, 0xD4E371CBD7E7545BULL, 0x4D9AA743F81EC5CCULL, 0xBA155402F4921FDEULL, 
            0x193D339FBF9B4AF0ULL, 0xCA74E21D548DB917ULL, 0x94AE5FB27FA6398AULL, 0x97FD1C4683B45619ULL, 
            0xB5406219E9EDB7DAULL, 0x4D187837F76C8FA7ULL, 0x0FF7BCBAB8C37F7BULL, 0x4673C7455E554CDFULL, 
            0xC8EE6D4E39899F0FULL, 0x52779F81B211BCDFULL, 0xA50484DD33025C28ULL, 0x4960C0CC5E78B476ULL
        },
        {
            0xEDEFFB83BC52C5BFULL, 0x4B7631DB61F61A1AULL, 0xEB80A4388CF8E2BBULL, 0x98F47C0A7604DC1BULL, 
            0x2252DB5C13FDC655ULL, 0x0C861E5FBAD8D538ULL, 0xFD1294AAFDF27A8CULL, 0xE550D1A6370A0488ULL, 
            0xB308E5A1E8584AABULL, 0x3B4E68B8CC409124ULL, 0xABF08B9256067728ULL, 0xB20D50BBED9D382EULL, 
            0xF3E36B0E4654D24CULL, 0x47F8A57825937126ULL, 0xA88DF8B27CB09CBFULL, 0x0D5DA6EE7EA35E6EULL, 
            0x45F8DF942F93E4BEULL, 0xB16F7FA5963245D1ULL, 0x0064B5A647DCF35DULL, 0x171259CF4C76621EULL, 
            0x252DA0D90B6C9721ULL, 0xACB83C6BBE744672ULL, 0x8B62A774CC6AE10CULL, 0x7E3A1AA951D22349ULL, 
            0x4DF808608AE854DCULL, 0x5E515F7532B611F5ULL, 0xABAA4424017C6154ULL, 0xED128CB0688845BFULL, 
            0xEF366A484E89EDECULL, 0xAB67432DA90E5EA0ULL, 0x7790F5450E75DD9FULL, 0xBF4F226DF5977168ULL
        },
        {
            0x801C0B8EBA7304DFULL, 0x60BC19D9F9B5532BULL, 0x9B9AFE491C83982FULL, 0x73AF0EDCF37FFB8BULL, 
            0x3A23AC9C6810F44DULL, 0x65AA92F53BD86710ULL, 0x8372B7AEEE869061ULL, 0x67E1073814FB7E1BULL, 
            0xC94C311A1FA1009BULL, 0xAA940A9BFAF9ECD6ULL, 0x1AE57BABF6FF0052ULL, 0x48FC961942CF65C2ULL, 
            0xFC88BE8AE40FD6F1ULL, 0x5A63E0F63E109489ULL, 0xE0268C019E2764D6ULL, 0x1AF2B155B4FEAE95ULL, 
            0x1CCC8D5CFB66001BULL, 0x53BCA962A0FD1F7DULL, 0x439EB881A54EB9D1ULL, 0xA124C6CE0E439645ULL, 
            0xDF60AFEE1A87427FULL, 0xB35C7F862D6D18DAULL, 0x0D1BEDA91C8EF381ULL, 0x4A1DB39448A86137ULL, 
            0x84E7FBC6EE7AC84AULL, 0xA173482BB11127EBULL, 0xF201BE30AD0D6C1FULL, 0x514314A2030BF37DULL, 
            0xE34D8566EA8EC292ULL, 0x113A4A6CAA80A421ULL, 0xF408C68A1A9B7146ULL, 0x2A812605AC7E6627ULL
        },
        {
            0x0763ACEAD18D3339ULL, 0x80A1D45F8F8F0F1FULL, 0x1A50BB653A5655F2ULL, 0xA3E6883D6AF60B3CULL, 
            0xF1E87F11C4568BCEULL, 0x28EF2F9FDA5E4A5FULL, 0xE6CEA64AC87A57EBULL, 0xE2BF721E7194A911ULL, 
            0x69CEBD3C88ABFE6EULL, 0x7A93006F6B2866E3ULL, 0x4C70AA11746A0C83ULL, 0x595C105537E60EDFULL, 
            0x2D887CC0B3546451ULL, 0x8D6B4A213EE68D76ULL, 0x0E7FCBE167E234B2ULL, 0x9CC36273FEB0201DULL, 
            0x20FBAEE6D30F87E5ULL, 0x505CAF434DBFF577ULL, 0x70C3DC2A1A079CE3ULL, 0x2EE24E652A29BFC2ULL, 
            0x205EE9EC0470729FULL, 0xCDE275946CE58755ULL, 0xD0D80708D3BD416FULL, 0x1270E5CEC3C7CBF5ULL, 
            0x73A7778261554EADULL, 0x9BF479094B5E4189ULL, 0x5A3E96E30C19080BULL, 0xEBFD5EB3DFA63F5CULL, 
            0x48944FABD8FB5266ULL, 0xABB717E287448056ULL, 0x01785FD743087144ULL, 0x557838E5AD5C222DULL
        },
        {
            0x57EA4B07D62D1454ULL, 0x17F660CE74679A3AULL, 0x4768A58A269BF850ULL, 0x25B5C0CFA45517B5ULL, 
            0xDBBFA453197D80D7ULL, 0xE7CABDE482424822ULL, 0x7A41D2D69A381705ULL, 0xA95021CCF70DC9E4ULL, 
            0xAA8E916C955D3744ULL, 0x627E87DC8D2A0A07ULL, 0xA9E52346F2DF9C0BULL, 0x58D9B4B9FFE385FDULL, 
            0xA54A0D7FB7D7E720ULL, 0xCCC0F734380BF0C1ULL, 0x08555420C3CBC63DULL, 0x82C58CDAD26B4C05ULL, 
            0x165B681565A9D691ULL, 0x1D37E1A39EA3F7A1ULL, 0x29DCCCC0C3334ACBULL, 0x88B77E13F20000CCULL, 
            0x4514CBD012B00C58ULL, 0x903A85497FCFF60BULL, 0xF599EC92757443DFULL, 0xE97464A63D8CEF63ULL, 
            0xA8588C6CF49C07FBULL, 0xFDE4BFB0F94DB07EULL, 0xA6498E6277D01EC3ULL, 0xA0BBE7BA9C1AE854ULL, 
            0x3EFBA9AE5D035B0DULL, 0x4D7AFB5486BBFE9CULL, 0xF634F14F52141C9EULL, 0x1EFA7143821C0F36ULL
        },
        {
            0x22767B5EAEC1789DULL, 0xDCE2875634AE8845ULL, 0xCE6679102405499DULL, 0x1005E7305219468BULL, 
            0x15603AE27E20019EULL, 0xD3B9945A1C33B4E1ULL, 0x7149D271E623AD34ULL, 0xAFDEB4E93CDA119CULL, 
            0x088CDB189E8D4365ULL, 0xD03E3AE12047AFB7ULL, 0x7E4259878820E409ULL, 0x02DE5401E3B98F33ULL, 
            0x0164A5C329086A41ULL, 0xDF5E04A56F3A93F7ULL, 0x93357840284BBCB4ULL, 0x15CAC25DECB6653EULL, 
            0xD002603B270DAC31ULL, 0xCBE93D0CE7205E68ULL, 0x75C54DA8E30EE3B1ULL, 0x4FE59022DA59BDDFULL, 
            0x8150869231C7C3A9ULL, 0x82D719C54DA12039ULL, 0x5DAE015A223DCCE9ULL, 0x339C086914DC489CULL, 
            0xFF6681404FE9333EULL, 0xA87FAB5F1D5DF77AULL, 0xDBF4F5B5F28060F9ULL, 0x5323AB5933F87E27ULL, 
            0xDC3B659DF188E435ULL, 0x5C69BE8666987539ULL, 0xD20CB35C4EE3AD1DULL, 0x8B3540403BE2735AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeyRotateAConstants = {
    0x8B9748F1F0E92E4FULL,
    0xF9525BD1C15D4A48ULL,
    0xA4325141C22643C7ULL,
    0x8B9748F1F0E92E4FULL,
    0xF9525BD1C15D4A48ULL,
    0xA4325141C22643C7ULL,
    0x88A42A188881B3D4ULL,
    0x1F0FFDA84058C5DBULL,
    0xDB,
    0x0E,
    0x2D,
    0x56,
    0xC1,
    0xAF,
    0x5F,
    0x27
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeyRotateBSalts = {
    {
        {
            0xD67DE7509BE19C82ULL, 0x941795EE375832CDULL, 0x247A58CF1C81B99DULL, 0x30E1BCB1D7B66AC3ULL, 
            0x17173EC64D4CE803ULL, 0x58384E0207E79D97ULL, 0x769FE89FC4B1D278ULL, 0x1A369976D19A8A05ULL, 
            0x24FD7D663D0396DAULL, 0xA83206AF7CF17A48ULL, 0xA3EE689F6EE05ECDULL, 0xEA1AFB2E9B54A3F2ULL, 
            0xA2998385D1AA08F9ULL, 0xB492864837EE65F5ULL, 0x3241DE021135F0EFULL, 0x0853B5A81172EA10ULL, 
            0x8EEC8DCD998BDC08ULL, 0x0B7BCD5C14F2704EULL, 0x365927D0F2B61477ULL, 0x6B09A238D5D68072ULL, 
            0x1C01ED6388854D22ULL, 0x8A653A1CAAB807DFULL, 0x04C8402176F5E94EULL, 0x2C7E290BEC1F5298ULL, 
            0x6F28DAA39D630B55ULL, 0x55996AFB85353AB3ULL, 0x31FAA3A509FBFACCULL, 0xF16F1A80E7ADBE23ULL, 
            0xD958F633A90E23CBULL, 0x575BB89423C34450ULL, 0xA08D8277A34F18BDULL, 0xC10CE65CDB2AFA4CULL
        },
        {
            0x4A0E8239B564025AULL, 0x36AFBE4FBDC3651CULL, 0x75A8246A03361C54ULL, 0x53291D11D6BEDF1FULL, 
            0x325ED920ABA70D6EULL, 0xAEC22B97FBDA78D2ULL, 0xB444A4E2C502AB0DULL, 0x04229C987A825DC9ULL, 
            0x86D508449CAED0E2ULL, 0x56B4701A166D34BCULL, 0xA275BBF570268A22ULL, 0x69755F888FA39835ULL, 
            0xB447F155D086B19EULL, 0x4E3F8715452CBD2CULL, 0x871B7021883A3B50ULL, 0xF1289BE6AEA1D96FULL, 
            0x16DEFDAC9CFA5025ULL, 0x71CAF8C5F545FCE7ULL, 0x70B3FAD34F8B8399ULL, 0x5AADB3A14F2B48C1ULL, 
            0x04272E380104156FULL, 0xFD0A0B4B4159566DULL, 0x50991C84AF845690ULL, 0x536D95833B4B04A3ULL, 
            0x806089E3D6FF276DULL, 0xA0680686A72E02A5ULL, 0xB5AB5661CA63A7ABULL, 0x74A924894316FAB0ULL, 
            0x0655A1BEDABC041AULL, 0x773B3E07B29481B5ULL, 0xC262A8983A20AD84ULL, 0xA62AD591C27211DAULL
        },
        {
            0xDD35AB33AC07AB5CULL, 0x8DF8BE4027FFC8B7ULL, 0xB66886F1A0BDB530ULL, 0x70108CC230864461ULL, 
            0x9FA66BBA2BB56582ULL, 0xB64C20328055A316ULL, 0xC96D54F05EDB2136ULL, 0x922A3E54A4C7A8F2ULL, 
            0x8F6563ED6606F0FFULL, 0xFBAEC932193D9735ULL, 0xD59D535E0E3B7928ULL, 0x25B546668FD2F829ULL, 
            0xA83B8E3C07A39554ULL, 0x040E85BEFDF92F03ULL, 0x532CB55A0A14414FULL, 0xB71740C1E440E3E2ULL, 
            0x5E658CDA321738E9ULL, 0xAEDCE7D19CDD9A0AULL, 0x4C7497F3D2A36A82ULL, 0x717AA4FB7089D2A4ULL, 
            0x2E911ED75562E674ULL, 0xB8CC1BDB1934D4CDULL, 0x02FA09EA36447D2AULL, 0x42FE318484A330A6ULL, 
            0x00520C622170E18FULL, 0x5F970DD35FAC7B0EULL, 0x622697CF67711E1AULL, 0x1638B74A679E3128ULL, 
            0xE1587AD0A90EBD06ULL, 0x4BD8D71CDCCD3BC0ULL, 0xC039BA9925304A45ULL, 0x64A2F5238F501F5DULL
        },
        {
            0x1AE8CC21EDBF5118ULL, 0x56FDC589C784D384ULL, 0x4D9FB9291620F322ULL, 0x5C1F73E160E5EF6EULL, 
            0xB3767F813DADBD99ULL, 0xB90DBC584B51B1C2ULL, 0x1FC36EE828BB0CD4ULL, 0xB3432B3B5BCAC919ULL, 
            0xBF7EA4BF809093B0ULL, 0x7EA7E5FF09C340FFULL, 0xB1966314928B0917ULL, 0x223FE6850485DC4CULL, 
            0xA166DB5BE12FB871ULL, 0xCF39AB6DB76379F3ULL, 0x0EB0D80C13A71AE6ULL, 0x4CB2D2FEBEA4572FULL, 
            0x840059CD95F03057ULL, 0xB97D6B22DD5F6218ULL, 0xAB005D5D3CE8C264ULL, 0xFB8ED4662F6AA1CFULL, 
            0x82BD3C275F805BAEULL, 0xECE189FDB12FF64CULL, 0x342CF8B1689D0A6FULL, 0xDE168C303C467F14ULL, 
            0x81C914DA2DA36961ULL, 0xE5A65C94BA4F80B3ULL, 0xAB6DF7AE1ADDD84AULL, 0x85ECDEBE216D0178ULL, 
            0x24476487B8A4DFEBULL, 0xA5BF0EF9926775EEULL, 0x8E7D4117454FDC50ULL, 0xCD3D645795775D17ULL
        },
        {
            0x0FAA76FAE1704FC3ULL, 0x29872EB4CA60DDC8ULL, 0x09A87DBE7D2D77F0ULL, 0x5A4AFA80A741A658ULL, 
            0x9ABB225A328F6A11ULL, 0x4C451602C34F4006ULL, 0xABD48C462672333EULL, 0xF0328F7CB9236879ULL, 
            0x8773F14F303530B1ULL, 0xF62C6BF6C4D02623ULL, 0x361FDA1D842AE4ADULL, 0xA2D55C40CE03E5B5ULL, 
            0x571F4104B68A0496ULL, 0xE62A5D471B88AAEEULL, 0x1E44E13B56D62D4AULL, 0xF05331537E8987EEULL, 
            0xDEDC59059894639AULL, 0xC39EBBD06B7C545BULL, 0x2EAF21711A1311DBULL, 0xF377C28D9BAC0820ULL, 
            0x349C9F1D3761A73EULL, 0x1A07543610E9FC3AULL, 0x6123EBC8F7A9481AULL, 0x3B285F76740B1306ULL, 
            0xD3305ECB16EA407BULL, 0x4AC2471DE1D881EBULL, 0x7E873536401C4E05ULL, 0x34851631C7FE9BA3ULL, 
            0x0B9E6B3DE7D55DDAULL, 0x1EA8B9748D76D91CULL, 0x5585E44D16CBA420ULL, 0x041AB5F0E489761AULL
        },
        {
            0xB1E19CF9E0C1967FULL, 0xFDC75D413FE7DD8CULL, 0x6C6AB9D424B603B7ULL, 0x74DA8BE61BBB33BAULL, 
            0x3BC9DDBFF4B74258ULL, 0x5BBA33F0913B72B4ULL, 0x2E1376CD4C473EDAULL, 0x3E9F5E7F225F352AULL, 
            0x7160F838DAFC0592ULL, 0xC3BC4CEEDA304E5CULL, 0xAB8B9FAFA8D92457ULL, 0x2E9A8801A40696C9ULL, 
            0x0FD80331968726A7ULL, 0xCF68DB696ECEC6CBULL, 0xC84F015D1483E3CBULL, 0x74D99C8BA49B884DULL, 
            0x8CCBF3B273DE25D7ULL, 0xF735E6970B0D53FAULL, 0xEB3BFE3894D01D56ULL, 0xA97EDED56E5CC75DULL, 
            0x16959A4CE7320999ULL, 0x594167002BEC2C3CULL, 0xAC09978BBEB51077ULL, 0x97C0BEA9E2D06076ULL, 
            0x5BBCAAF97C018B65ULL, 0x7C2BB8AB4BAED4C5ULL, 0xF5F536E32074CF5DULL, 0x42D778BF045E6C74ULL, 
            0xE5FB99D1582653F1ULL, 0x25822F1890FD9AEFULL, 0x171FED7C7B7B5ED2ULL, 0x43910A1BAC60096DULL
        }
    },
    {
        {
            0x36BADC43993235C4ULL, 0xAA17D78E80B41F79ULL, 0x5F465E8F70E34F77ULL, 0x9D29D990D3B37629ULL, 
            0xF65BCA517F55C2D8ULL, 0x2D324D0521F7D1B5ULL, 0x2F1E3929C73EF349ULL, 0xEB792A0EFCE86042ULL, 
            0x25B3BEFCBAE12933ULL, 0x7D335263BE45488CULL, 0x2A0146E3115D19FAULL, 0xF11598DC5332F63AULL, 
            0x6159ECAEE537C729ULL, 0x77D56461B013C07CULL, 0x1030CC96ACC68B0DULL, 0x75170886568A270EULL, 
            0xDFD31F8BD316E8E6ULL, 0x94AC0F07380C479CULL, 0x32A4BCB33B161CBEULL, 0x697D564B19434D71ULL, 
            0x4FFA0CF509D85E6AULL, 0x131BF2D5FCA1E69EULL, 0x193F7C580EEDA493ULL, 0x4892D9FB014EB238ULL, 
            0xC0C6FBBC28987697ULL, 0x2DC5768E768A42C7ULL, 0xB7740979F03AAE85ULL, 0xCFF2551214595412ULL, 
            0xA120906829C82538ULL, 0xF127E970BA4D748DULL, 0x9491772D2BCEEDC1ULL, 0x3D632A25E83E9B80ULL
        },
        {
            0x458D19DC078A0BACULL, 0xB6601B371198BDC2ULL, 0x711C706B3C5F1605ULL, 0x96CEEF1877403DF6ULL, 
            0x9552D4CFD66C22B6ULL, 0x5AF28A2F314E87ADULL, 0xA8C908B26E0C6E42ULL, 0xBDA1B4F27B5B0858ULL, 
            0xA2636282052F46C4ULL, 0x70071D6567668F83ULL, 0xC6296777ECA5D25DULL, 0x5E4894E4C94D6EB6ULL, 
            0x48211775BEC69CF9ULL, 0xE74BE14A8EE446D6ULL, 0x57C58CA24923D7AAULL, 0xE7E6CBE3847FD048ULL, 
            0x4461791449FFB859ULL, 0x13F12B54FA720DB4ULL, 0xA56D31C69F1B2AAAULL, 0xBB0362B94A7C13B0ULL, 
            0x7B7B588B1EDD8488ULL, 0x380EE9F2487E7151ULL, 0x93293D6E9169744BULL, 0xA8ACD14818BB097FULL, 
            0xD37238C041800952ULL, 0xA8049614515815FAULL, 0x02F565EA75648FB0ULL, 0xA8E1B84A1ADAC9D4ULL, 
            0x438C65D5A7DA8085ULL, 0xC13C2FCE577B1AD8ULL, 0x7ACF2956DA2FF11DULL, 0x81B39E119762447AULL
        },
        {
            0x1BDC942D88A4DCEDULL, 0x5BD469FAD3223F1BULL, 0x842A5F3BDC4C4446ULL, 0x80ECEF4252829BAAULL, 
            0x91EBA2E02187DBF2ULL, 0x725E2787D6801A4AULL, 0x4313F26A9DB206DEULL, 0xC0C8161C87588D6EULL, 
            0x343EAD999D7F577CULL, 0xAEF539F73090525AULL, 0xAD88358ADB078E78ULL, 0xED8B764012DCB429ULL, 
            0x0C06AEB51FA2EEDAULL, 0x62CB97F77046DC85ULL, 0xBC3E47AB1D0EC2A2ULL, 0x5B72F7C41114256FULL, 
            0xEDBE9FB09347DC06ULL, 0xB70212DFC53831E7ULL, 0x2696B8170DAF7E8AULL, 0x40B70D4C4E862B9DULL, 
            0x72A2A011E6F497CFULL, 0xB678CBC7C2838EBBULL, 0x1463910A3CE95A24ULL, 0x671C3068D8E48240ULL, 
            0x8FEF38CC0EDCD512ULL, 0xEE27759372CB157BULL, 0x42890E00036054C4ULL, 0x86A551DABBFF7D17ULL, 
            0x80CA8512DCC7E08DULL, 0xC639B56877879D68ULL, 0xFA6D85B2DA591CD5ULL, 0x9EB69C2D1C74D5F4ULL
        },
        {
            0x39B7CA6B3E14495AULL, 0xC6E7945450B60D43ULL, 0x5A36406822B358D9ULL, 0x9FBEABA9BD97CC32ULL, 
            0x256C3BF00779F370ULL, 0x47F103D7B616ED1BULL, 0x65C625B4FA103EF5ULL, 0x10C8AC0FC22EDDBAULL, 
            0x0836887491167701ULL, 0x36D7FCB26F3FC603ULL, 0x1666842741CCD377ULL, 0x355B535CFAFF0F5AULL, 
            0x5B1920A73964C2B0ULL, 0xE0D5B3415E80E352ULL, 0xED0253FDC740DD1DULL, 0x0A2629BE553F473AULL, 
            0x18BC7B8FDFC5D35DULL, 0x416FB4CDA36805BEULL, 0x3D1490BC13182CF3ULL, 0x07493605D6AB3264ULL, 
            0x6A281D53463D9E26ULL, 0x3287EDAFE8C4ADACULL, 0x40920199FEA6CDCDULL, 0x70F4FEBAD09096AFULL, 
            0x317AC8E7DF15A198ULL, 0xF64E8C14B70A42A1ULL, 0x530AADC0FBD80F6AULL, 0xD413A27C8967F103ULL, 
            0xBF0E746ED55294ABULL, 0x76DE6B969512791EULL, 0x3027D276FB8EEC73ULL, 0x57194AA99A468947ULL
        },
        {
            0x6F092A7AD20A4924ULL, 0xDDED397DCF948A39ULL, 0x1425DE618F68607EULL, 0x2AF450BE16CD2454ULL, 
            0x0B9AB4E93A7E171EULL, 0x178956F8B720C46CULL, 0x34A114A2FBF0B5BFULL, 0xBC02054E68C2C48BULL, 
            0x4FBADD3CC13EC1B2ULL, 0x5711240229B8074EULL, 0xD4191F9A4F6A255FULL, 0x766B717C946F9F75ULL, 
            0x6A9105D74061CF5EULL, 0xE3BA96698DAFC337ULL, 0x21E5926AC549220BULL, 0x5F36D00529D97DEFULL, 
            0x3040F50BC4BB588FULL, 0x24747926B1EBE3C4ULL, 0x19340F0D79C13C8AULL, 0xB4DA3AFC8F21A931ULL, 
            0xEC0CF86D71C86146ULL, 0x01DD25623B8FCDB4ULL, 0x600711B97D458207ULL, 0x67C1CE46BA63A74AULL, 
            0x09B3B49050FCDE3EULL, 0x8C20181184F752FBULL, 0xF9356558229F432DULL, 0x9812E86BF093C6DFULL, 
            0xFB1E0F2C94FE09F2ULL, 0x10E3C805601D5D29ULL, 0xAD9B1E535A2DE58EULL, 0x75974869677FB18CULL
        },
        {
            0x89573E94115B6A44ULL, 0x8635B8D187A6ADFCULL, 0x8413AE08B5B074ACULL, 0xF0AF1833B696841BULL, 
            0xC77C727305B98761ULL, 0x1243019F7254B0A0ULL, 0x8E04F925B806A413ULL, 0xB05AEF82AB38891CULL, 
            0xE1858C245EF1F317ULL, 0x7546B48A6B64AD2FULL, 0x50114BAB137DC4A2ULL, 0x21F69C46C060A4A3ULL, 
            0xBCACAFE29A1B4554ULL, 0x8FB5454DBB5AF8B3ULL, 0x88A08BA1B241564AULL, 0x02BB5B4A6A0E8941ULL, 
            0xCE7F32318D135495ULL, 0x758C68A4EF7D27A8ULL, 0xEF71FC09768A81B4ULL, 0xCC0FDC7184B535D0ULL, 
            0xA9105ED2E23738B9ULL, 0x0469ECC87EA5AED8ULL, 0x4ACABE806999AA88ULL, 0x592DD627AE220A09ULL, 
            0x35B5F7A5F22CB5ABULL, 0xA623F1A78DCF90FEULL, 0x232936EE051EAE3EULL, 0x7194A7154FBC6DBEULL, 
            0xA04D2D281DE1F3ADULL, 0xA1CBBBA3E61B1A09ULL, 0x5EF0B3A130DF1B9AULL, 0xC4E0105E10A8C34BULL
        }
    },
    {
        {
            0x22B4734808673C54ULL, 0x7A7A1C92D80E71DCULL, 0xFEC915A6ED03E9E4ULL, 0xDC9615C89F4ED428ULL, 
            0xF363DF54962C6853ULL, 0xD25EF4E34935B0B3ULL, 0xF71223FBCF8F02B7ULL, 0x060DFFD1BEADC56AULL, 
            0x963BA339EC2D845DULL, 0x2C42790EB5619DE0ULL, 0xD0A0608D3BB07AECULL, 0x06135473258DA7F3ULL, 
            0xCE3FDF53C4A8349EULL, 0x2EF44821BE694ED5ULL, 0x7F5A13F807248D57ULL, 0x72B67EBB4273B9BFULL, 
            0xAEA042FFB4C776C3ULL, 0x3E0EE79B0E54B4F8ULL, 0x91B08ACCEEECC22FULL, 0x6986B8420BD0BEE3ULL, 
            0x4A585EDEFFD49807ULL, 0xD004B19AD805C5F6ULL, 0xA1AEFE30EAAA8434ULL, 0xEECCF5C0EE2C0068ULL, 
            0xDDEC699C20759A59ULL, 0xF6D4B6FB498AD712ULL, 0x615A9B29572FCD07ULL, 0xE5EC9A8EF3E1C3E0ULL, 
            0x0AD9CC57569CA599ULL, 0x9D4193735D124D2CULL, 0xF4CBB28767D1EA9BULL, 0x94C07E4C9577C87DULL
        },
        {
            0x40860540556C7343ULL, 0xD605409757B2BF0CULL, 0x0002D9CAA066713BULL, 0x3570B1469ACC27FFULL, 
            0x8521E0FE9A1651ADULL, 0x7D3A2D95E1161457ULL, 0x51C8B1A924969187ULL, 0x551B1328B5AFAB1AULL, 
            0xBCB770C6A3BD313EULL, 0xC83EE8E4DAEAB7BFULL, 0x5FB98A75B357073CULL, 0xF1B7508E4CF39015ULL, 
            0x418227042088E42EULL, 0xC4B6B89D613F9124ULL, 0x146FDEBE09936E9FULL, 0xC79C68BBDA112F05ULL, 
            0x3BC97CBDF9AED3A2ULL, 0xEA949DCD0C173034ULL, 0x084778A0577BF6DDULL, 0x719C1C3E17D41145ULL, 
            0xB76045F8337A7B56ULL, 0x2A7CD9C07CAE2581ULL, 0x11A8AD7106BC3C24ULL, 0x14FF7608B642B3FBULL, 
            0x4AC65C7D74BDABCDULL, 0x4E58822E7BC06845ULL, 0x1FA89BC7F9042015ULL, 0x27087580B8F4C7B5ULL, 
            0x19C69E8EAC6C8282ULL, 0x3CA86AD472BD01BCULL, 0xDE1A7BFD38B70154ULL, 0x85A424452B1B8F24ULL
        },
        {
            0x7AB2E7E7F3D21D8FULL, 0xB78D772FAA2FC3EDULL, 0xBAB5CC9AB8505F32ULL, 0x546769563F7FAE7FULL, 
            0xFCA9FBBC53FF6402ULL, 0x782DD81320A7689BULL, 0x2939CC0472E61E37ULL, 0x1B887E1CB6A1E7D0ULL, 
            0xBB38B5C534BB5D20ULL, 0x098EEEA771A295CEULL, 0x393ECA9A35519C75ULL, 0xDDE8F98E48F1FF8FULL, 
            0xB6756C78A0036737ULL, 0x72B4158A5CBEE19AULL, 0x8E1C1BBC3C3F79CEULL, 0xB9054F97BA28A8B5ULL, 
            0x43FEDA1731BAB8E2ULL, 0xC3F23364E353B928ULL, 0x444A7BAE41406144ULL, 0xB6A9140532ADCB30ULL, 
            0xC14F11ABC01654A7ULL, 0x946787255B487E09ULL, 0xD861D5B5717A4C1EULL, 0xD2402FAFC565DE20ULL, 
            0x62822960F8F8E5C1ULL, 0x65A25035DE35D2EEULL, 0x5B22B28BCDB669B9ULL, 0x14B8D493C8E7FA16ULL, 
            0x8C706A87A1A46441ULL, 0xC865B27AA0344667ULL, 0xCF73DB219EA5257AULL, 0x962A34F2674898D1ULL
        },
        {
            0xD9335378C7BCE721ULL, 0x61D86757310481ACULL, 0x220ADD938FD62A14ULL, 0x454EF940843725F7ULL, 
            0x3641F74E77391439ULL, 0xBDEED7A0ED54F05EULL, 0x2C12A92F7ABA0FB8ULL, 0x7A1A889BD40776CFULL, 
            0x913EA67E12B0438EULL, 0x41FB44079DF8A636ULL, 0x88815FBDBA1B3F8BULL, 0xB597DB1F8EDEE0AEULL, 
            0x73FB99741156F1D2ULL, 0xC4B9A49280F79000ULL, 0x161765620E6F49EDULL, 0x4C89FCA72B72D2FBULL, 
            0x37201FE0693EC508ULL, 0xEF0CD5F742DCD18EULL, 0x5D66DC78F667B745ULL, 0xD96F3A3CF17C4F3FULL, 
            0x71FB4C663F4D95E8ULL, 0xE9E96E2DCC036CE9ULL, 0x2024B45A64D58892ULL, 0xA1DA095F5ACE69AAULL, 
            0x042773E90558FF1CULL, 0x18C6FBF23D10186EULL, 0x1A9E316586A09D65ULL, 0x70CBDF5AB70D46ABULL, 
            0xFC656BD54ED7A7AAULL, 0xC36E43DFAD0F275DULL, 0x3D4A792C3208B15CULL, 0xD6E250049B9E5B7CULL
        },
        {
            0xECFE834A758980A4ULL, 0xD29786D1587B195CULL, 0xCEE24AAE6F13D744ULL, 0xFC92D5766CE479FAULL, 
            0xE4FE75F18EB516E6ULL, 0x2D5B301D0305C37FULL, 0x39C0B0E7BDC4CFF9ULL, 0x192EDAE7069D62D4ULL, 
            0x773F96D1B343FFD8ULL, 0x1A35E5786C30467DULL, 0xE11189FAA57F9E1DULL, 0xCF9D37FEBF976D61ULL, 
            0x104B1542DBBCBF50ULL, 0x802BD9815BDE4322ULL, 0xD8EE851EAC3CEA17ULL, 0x5E60CF69C3F5A910ULL, 
            0x42651E42CFE5F2DAULL, 0x911FBCE774B72383ULL, 0x3394A82726DD400FULL, 0x97B5AE7904052069ULL, 
            0xB56E6DCF39ED4B82ULL, 0xB8404511D0D3B0D2ULL, 0x51AF11A77F8A3E26ULL, 0xF882ED7DA32AFBB1ULL, 
            0x65959E6283404292ULL, 0xD47B86A24EDBC097ULL, 0x9DEA0F32D882E932ULL, 0xC59CB345A1B4D1DFULL, 
            0x9132CF556C2D13E9ULL, 0x6AB17D3141330C96ULL, 0xA1198B4F342A807BULL, 0x5F2D93E98CE25212ULL
        },
        {
            0x5287870A6409870BULL, 0xA6008A83FE2E3B29ULL, 0x6B5A1924013210DEULL, 0x56BF1A8235B0926AULL, 
            0x069CC77D900A80BFULL, 0xB257E9775ACE0934ULL, 0x2D70FA47A2318A5FULL, 0x1515AD8572C04862ULL, 
            0xE4AA6D926B08A1AEULL, 0xD7142A3040285FF9ULL, 0x7EEEFCA8A007233AULL, 0x5C9AFE7CF6F88BCFULL, 
            0x7C8F81EA05FB00EDULL, 0xAF683C0530174A8BULL, 0xEDB17FB943BBF073ULL, 0x73F7C68239B0B4CFULL, 
            0x554C97DD5920F6D4ULL, 0xE9D9BCE76BE1751EULL, 0xF262F3E4936600B7ULL, 0x0620E6CB135992E0ULL, 
            0x517689EF2598C34DULL, 0x86AB9E0A6DA5C045ULL, 0x70E75956705D61ABULL, 0x5B226AAB78096D05ULL, 
            0x62ABEF6B816E6397ULL, 0xE813DE41D2BF5AE2ULL, 0x74B2FE50ED4521EAULL, 0x146BEFD1ACDE06E9ULL, 
            0x35B80FA37B36BCC1ULL, 0xB4569CEEDE2D2511ULL, 0x6D186C01A55B0304ULL, 0xD45D6180C213B62FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeyRotateBConstants = {
    0x85D25D48424ADB0DULL,
    0x9DB64DE6CB007282ULL,
    0xC3B09FF455142DC2ULL,
    0x85D25D48424ADB0DULL,
    0x9DB64DE6CB007282ULL,
    0xC3B09FF455142DC2ULL,
    0x4DAB902CF1B92008ULL,
    0xF92CAE5E1656F2A9ULL,
    0xC5,
    0x7B,
    0xF0,
    0xFA,
    0x59,
    0xFE,
    0x54,
    0x2C
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeySpawnASalts = {
    {
        {
            0x60645E2D7B1A944FULL, 0x31656F4F7A87ED72ULL, 0xEF1E1C97D43E26ABULL, 0x4FFCA6D9556EA98AULL, 
            0x402D8AD94077A342ULL, 0x48C131307CD34A95ULL, 0x9478604E59336CCAULL, 0xA1367EBE25F06E09ULL, 
            0x1A89D9EF357C8DB3ULL, 0xD5AECEEAD7965FB2ULL, 0x413C0EA4EDAFB8B2ULL, 0x52A8DCB196C09735ULL, 
            0xE2D02765913D8659ULL, 0xACD86B491CC51D3AULL, 0x469BE51A9FC52E8AULL, 0xEB08A2B75FFFA3B2ULL, 
            0xD883C2286458C0A0ULL, 0xD0B3888E187E7D3FULL, 0x12B8421DC473B4EFULL, 0x357E0E51A574D084ULL, 
            0x03CE0CCA35AAB310ULL, 0x2CAC4A4C4EA23C21ULL, 0x7A698366F4517EEFULL, 0x6B1E458BD44B4DC0ULL, 
            0x2397F3471751EFB0ULL, 0x644A5E0DDA274238ULL, 0x42753CB130582018ULL, 0x1E3C65E54005A6C6ULL, 
            0x7901572C36725C1FULL, 0x191F4AAE8B26E3F4ULL, 0xCDF381AE5314FEC3ULL, 0xA25783CEEE968E6EULL
        },
        {
            0x3054A370B9654D03ULL, 0xA1ECBE509847695EULL, 0x236A44B39E45CEB2ULL, 0x97401112A4E29EA2ULL, 
            0x74530AE350F6C3A6ULL, 0xCE26BED98E8646F7ULL, 0x17CB062CE7677224ULL, 0xC987441BC20E56BEULL, 
            0x4492014430FC29CCULL, 0x0AA4E279029FACFBULL, 0xFE2EA9FA74C4574BULL, 0x9CFB186D54F670B1ULL, 
            0x91F08A5CCA31EF3FULL, 0x1B12387F937F662CULL, 0x674A891B13623937ULL, 0xC36E71F39698673AULL, 
            0x057568F57CAA21DBULL, 0x32DA28015C88AF2AULL, 0x0E024FFB1C48E873ULL, 0xF30FC02BCEC5F36DULL, 
            0xA59B4EF602815884ULL, 0xC933092CCA4340CBULL, 0xF022290176D0AC57ULL, 0xA7E69985BEAAA7F7ULL, 
            0x327EFABD2C4976DEULL, 0x496CCB5A41766F4AULL, 0xF16D6064B1669F0AULL, 0x937BDD556B731AA4ULL, 
            0x2BC6FCA6AE6AB8DBULL, 0xFBC92EFACBF27B3CULL, 0x5B13474F9F7B7D8FULL, 0x1A71D213EED2B0BCULL
        },
        {
            0xF8EA56FCCF556125ULL, 0x83EAFA3EAC10BE65ULL, 0xCA3479EA414F3035ULL, 0xA5EB88ECA0F226BDULL, 
            0xD895CC183A013EA1ULL, 0x970B94C6B322BE10ULL, 0x6371844AFE2D9064ULL, 0x9D9A119BADEAA76FULL, 
            0x02BA7F9195F627BAULL, 0xC66057B200090DF9ULL, 0x57E8BDF176C0E2EFULL, 0xA7F6B4202E846DB2ULL, 
            0x6AC1521638867806ULL, 0x759E64E4E75749D6ULL, 0x5196424F5D5DEE25ULL, 0xE744014200EA023CULL, 
            0xFB847A14808BDCA3ULL, 0xEB8BEBF58064AE37ULL, 0x5C04D971A4B3A261ULL, 0x1BA0939C3F16AEECULL, 
            0xA41E763713CF7644ULL, 0xFA65CC2CAEA7D2C3ULL, 0x101593DEA02101BFULL, 0x5E4DEAFCB555F52FULL, 
            0xE5A008C630D000A4ULL, 0xC17032688B033089ULL, 0x6FEBEA94A62CEA5DULL, 0x97E542FA7EF3B720ULL, 
            0x8EAAF4E29E9E159AULL, 0x440221376ABE4867ULL, 0x12D20356CE232833ULL, 0x80CF0B5E3EFA4F22ULL
        },
        {
            0x59092DEAFF2A16BEULL, 0x38432E21427AB2C0ULL, 0x61CFB27244AD8051ULL, 0x646BF00207395610ULL, 
            0xBB48E28DE359AD82ULL, 0x4CE17987A9FA21B4ULL, 0x88C651C1896F06A3ULL, 0x7FFC8781F204DA50ULL, 
            0x4E759FA401C4A770ULL, 0xF5AF63692D940833ULL, 0x21D87A351506629EULL, 0x0756E0C5108506AAULL, 
            0x3186D2C652E532A9ULL, 0xFC4004A0B47EA876ULL, 0xEAB95C23E8F47CE9ULL, 0x4BBB807AEEE27EF9ULL, 
            0xA0836C3C8612FF6CULL, 0x70BB6305FB3943C1ULL, 0x9BABA9A9021DC5F1ULL, 0x850834CFA392FDC2ULL, 
            0x1E82C3325BA5623BULL, 0x0CDAC0F80C5237FEULL, 0x898F3BD95E2A602CULL, 0x237F2AE9E1573E34ULL, 
            0xCE0D5D083972FC2DULL, 0xF565747D53606574ULL, 0x2072A2EA7224F76EULL, 0x33BBADF86A5FBF79ULL, 
            0xCEC96152BC356DFEULL, 0xE14DB2FC5E74D3A9ULL, 0xBAADCF6DB5B6138FULL, 0xB3E1058CE085E24AULL
        },
        {
            0xC3459B77797756D4ULL, 0x91E441597596FB23ULL, 0xFBCBCECB27162757ULL, 0xBADDF99339672C05ULL, 
            0xDBFD8A8C680CF407ULL, 0xE6759063C4ED4146ULL, 0x9CE9F826E6DCBD56ULL, 0x249159A9434B0947ULL, 
            0xA5F102E8DF44C86BULL, 0xA929159BB5A52767ULL, 0x6923887C3F3F5DCBULL, 0xF2BC319E8004375DULL, 
            0x063844B79C91C8D8ULL, 0xF4612E854992BDA0ULL, 0xA87F6E7D600AAA83ULL, 0x045A62ABED1FCDD1ULL, 
            0xFF2DC5B13B935BD5ULL, 0xBAF6AA3B06F32368ULL, 0x9C5FCAC8407BA815ULL, 0x21852840D8159309ULL, 
            0x88CC95C08F27C555ULL, 0x1D6EADE4C249481BULL, 0x56AA891FB8F9FD88ULL, 0xBE58A54794AB07DEULL, 
            0x94852BDBCB741353ULL, 0x973F2084FD5B19E5ULL, 0xBB74A3CCC00ADD70ULL, 0x36759176D42F1395ULL, 
            0x89AD418363424488ULL, 0x5D3DDB77F3C7CAE6ULL, 0x23BBA87AB9157DE1ULL, 0x4A9E4EC672102C69ULL
        },
        {
            0x4A735D383F11794EULL, 0xAAFDCDE513999BE1ULL, 0xF5BE4113583B9EB4ULL, 0x6F7660C774F40EFDULL, 
            0xD4A90EDBD8EF4A41ULL, 0x87111E8DD7E2ECE5ULL, 0xDA7ECE028866776BULL, 0xE8FB43CA64681F94ULL, 
            0x2401457AE72A4A1DULL, 0x6ECEF2B8EEF39E07ULL, 0x98295A9CAFCB9076ULL, 0x3D501A3C4C232EF7ULL, 
            0x37B2F55E4178FF76ULL, 0x4860B49CDE897164ULL, 0x1C02554EB3F3ABCAULL, 0x82D2713952A50F51ULL, 
            0x88018971E036AD2CULL, 0x26DDF6F1D21DEA61ULL, 0x6187D94B1599A4B2ULL, 0x2820D5A37D35C858ULL, 
            0x9EF2C3E20D71DDAAULL, 0x094449B1A9514D47ULL, 0x11964B931D3C1E88ULL, 0x7A01CAE1CA118947ULL, 
            0xACF8F0B26A2A64A6ULL, 0x66B85CE32F180297ULL, 0x659BD466F4D9F35BULL, 0xDE2FEE7C65DCE899ULL, 
            0x4F1589FBD18C596DULL, 0x8D8816644DCEC8C4ULL, 0x6BE4D410DC0C3375ULL, 0x4CAEFE971E7939A3ULL
        }
    },
    {
        {
            0x75965F71D18BB6BBULL, 0x3D746FEC012BBD9EULL, 0xEDD41AD09AEE7F8FULL, 0xC929361B95204CCBULL, 
            0xF928B311D8515C72ULL, 0xBDABAB3ECE6AF5AAULL, 0x3CE679AEAE2FE434ULL, 0x771B9F5BD47A0260ULL, 
            0x9486111AB3745875ULL, 0x99645AEE84A00088ULL, 0x0EADA1BBA435881BULL, 0xAAF8A5882F9539B4ULL, 
            0xE78D12D98620C26BULL, 0x31F597B4D9A4E1ADULL, 0x1540E45290397A4BULL, 0xA9428145C9A9D0E6ULL, 
            0xC334297CD2BE351CULL, 0x535D82B80B1C7A3FULL, 0xD8C398B5369F46A4ULL, 0x8DFC7D9824EDEE2DULL, 
            0x30F0D00A9812ED8AULL, 0xDC7BDFCF744D9001ULL, 0xE49891447DEADCCBULL, 0x1C4AF56346109FDEULL, 
            0xDDABF4159AD7BACCULL, 0xD2A90B481F750B6EULL, 0xB3C294EB6BE04C8BULL, 0x1EE8967C9CC5A314ULL, 
            0x0BA7C9E49637D952ULL, 0x33E0B710E0E704A5ULL, 0x382A2CBC57AF5567ULL, 0x115F4ED8E96A723AULL
        },
        {
            0x516F9A1487100DCFULL, 0x1BEEAFFF9EA7F7A1ULL, 0xBE486978E702E1BCULL, 0x0920F8F666FEDF27ULL, 
            0xC39FFEC112CF358EULL, 0x3B6F6908EAC7FC31ULL, 0x698D3B4358E6B6D3ULL, 0x5327521FF2F2DC74ULL, 
            0x7C65CB6129085709ULL, 0x45157DC835132FF6ULL, 0xB0979BA1B9565D95ULL, 0xA10F4CC3AE2B2E82ULL, 
            0x3CE202A316400845ULL, 0xAFF03C88949CC3F5ULL, 0x61274593084609CEULL, 0x4ABCBB02B6DB26FEULL, 
            0xED23485722FA9B67ULL, 0xE42165C003B888AAULL, 0x3F93CB0B440B20EAULL, 0x928F61E60B62E4F3ULL, 
            0x57DC302603AA4F1DULL, 0xF45E1BB2FCCA543FULL, 0x0CD36A943701C605ULL, 0xD24896B3AFCC20FBULL, 
            0xAB0C572F0F1A49E9ULL, 0xA599F3043C1A535FULL, 0x7BA68010752421F9ULL, 0x6B16FD67F9392531ULL, 
            0x0796BCD4EE9D7528ULL, 0xCC0D6C252263EE70ULL, 0xE315544B57C1FD66ULL, 0x2E467005B18B80AAULL
        },
        {
            0xF932DC336E2C66D9ULL, 0xF4DD40A69EC56D3FULL, 0xDBBFA9E504FC8AE2ULL, 0x8539BBEAB06493ABULL, 
            0x0B52F3A48C91D1BAULL, 0x648B17BEAC444104ULL, 0x90B6002F3D227675ULL, 0x41A97B36A75E8D75ULL, 
            0x0D0BC0C73145FDDDULL, 0x8B5C90C5DE23BF6FULL, 0x2E8CC3B226126E55ULL, 0xB27CA206C60A606CULL, 
            0x3F3FFD61AFC7622EULL, 0x56A087AAC0664932ULL, 0x1665ED8A11C97088ULL, 0xAACE480E08FBCFB5ULL, 
            0x5CB01ACABEB57D8EULL, 0x4077F23500A02643ULL, 0x49C3A0028DA340CCULL, 0x314AF11919BC5EDEULL, 
            0x8B7C3E26D90BA1E5ULL, 0x36599ADBE5514485ULL, 0xC408FA7BA87862AEULL, 0xA815E3A91F741665ULL, 
            0x3E5A2C054989593FULL, 0xEC213ACC0A9B59C5ULL, 0x6604E0ECB0FC01C5ULL, 0x8816FC32AA386BA3ULL, 
            0xF7D052A9ED50FECEULL, 0x68A4DECD36B8DD20ULL, 0x2CDEB8926904B1EDULL, 0x5CE7867B2960020DULL
        },
        {
            0x642A4A4FBE35F94FULL, 0x2344107F05A67FBFULL, 0x5B20FEA1779643BEULL, 0x9EEFEB9179FFAC31ULL, 
            0x88D9C2AF98881633ULL, 0xBF51ACA4B00CABC6ULL, 0x18A34814AF3DB29DULL, 0xFB54D78100E4EC07ULL, 
            0x7AAE9414A42D8948ULL, 0x559A48FFBD63ACF4ULL, 0x1CF3D2410C964D82ULL, 0x4F0CC76A9FE9EAC8ULL, 
            0xDDCA02CD8701B5CEULL, 0xFB3EA7362595D9EFULL, 0xCB7FCFA3D12458CEULL, 0x4C46DC3A614ED280ULL, 
            0xD7E3F58E5E8751D2ULL, 0x68EAB0184469EBE3ULL, 0x79A22F33130B963FULL, 0x319FFBB89B896233ULL, 
            0x482CC1D32BB76CF0ULL, 0x5CACF32999B25DF9ULL, 0xE84FB0463AE9BDB6ULL, 0x28BFD6C1B2AA86DFULL, 
            0x89326B71A32049B4ULL, 0x7E3F1F80361D5F45ULL, 0x09157CB7B8665798ULL, 0x93E79E3B6536F903ULL, 
            0x319ED9306A1AAF12ULL, 0x580611609E2C1204ULL, 0xA024695B838EADAEULL, 0xE5F44EB488CA54FCULL
        },
        {
            0x0BE2FD9640A70CE6ULL, 0xA5AE058AC265B6ADULL, 0x6B22B1294857DC3AULL, 0x9E56EAED4D1B0956ULL, 
            0x3F344BB2FECD945BULL, 0x04861EBA76EB7870ULL, 0x479F0BFACDBC3550ULL, 0xE737DEACB7F26F56ULL, 
            0x3334FC7E242E3E81ULL, 0xC26CBFD92C016D88ULL, 0x8B2BCB310C04DFE2ULL, 0x00E394F3DB903B34ULL, 
            0xFED5A9A5702CF658ULL, 0xE2FE7FF6DA3763CFULL, 0x470B81553A1656CEULL, 0xA0064DE330DAE4D2ULL, 
            0x15C166F81B676785ULL, 0x053BAEA39D3D50D3ULL, 0xF96CC0B9491E9EDDULL, 0xE78AA1EFB76C9FEEULL, 
            0xE23737B30A99B81FULL, 0x651BA121B152EDE9ULL, 0xF957FB5A05CF604CULL, 0x5C89221E4AC01732ULL, 
            0x96C9CDFD5BB62EB5ULL, 0xECECDA5A09CA3DE5ULL, 0x40386A3625594009ULL, 0x8605EC80E765A1C8ULL, 
            0x7C9DE8636A880CE2ULL, 0xA5FA8533BEF22350ULL, 0x97AE7BDC07213E45ULL, 0x2A2A4B39D28C4B8EULL
        },
        {
            0x874BE120AA895C08ULL, 0x17483009C2B621C2ULL, 0x04225507852ACDF4ULL, 0x3FEBC0190E5CF1A4ULL, 
            0x2BE704670F0C29BBULL, 0x79182EC2A6519FC2ULL, 0xC4F96DB531D04E60ULL, 0xB133536816594106ULL, 
            0x58EF69804F645B77ULL, 0xA0AEFC2C894AB5CFULL, 0xC92B6E54919364AEULL, 0x39C9C1410CAFE945ULL, 
            0x6B8F58FA87B9079BULL, 0x2A12F47FCC9C4149ULL, 0xAB7121DDA7C8021FULL, 0x9A12A30B8EECD9D8ULL, 
            0x9A70EDCE20C52615ULL, 0x7E6CCE7E08CB1429ULL, 0x5890DDBF17CBD80DULL, 0x8E651BA51209DEDFULL, 
            0xA1434C20604A9A40ULL, 0xD83A43FB6BB5845BULL, 0x1516FC7AAAD9CFB8ULL, 0x7930DAF8F59AD28CULL, 
            0x194151295FE0F45AULL, 0x8AFD02F58E6AE810ULL, 0x208EC03EED3B59C3ULL, 0xE2B0BE1E8F0F5267ULL, 
            0x023946BBE086A43CULL, 0x51C71C4EFBD62209ULL, 0xB40B15A2E9478C1DULL, 0xAB5AF0F3DEA5A573ULL
        }
    },
    {
        {
            0xDAC9F82BEF82F635ULL, 0x167E38EE9EB7094FULL, 0x68A795EEDD3B1C19ULL, 0x3140AA01F1000BF5ULL, 
            0xB7B0DB224F5152BCULL, 0x5C81A158E8C3FDF1ULL, 0x30B35D19C8B90355ULL, 0xB8F92FE714E3DCECULL, 
            0xFCF2813ED80B0480ULL, 0xB0FFC8685337F2FDULL, 0x243222E3FA06F8FAULL, 0xDDF69AC672298B35ULL, 
            0x3E0B22B75D6BE97CULL, 0xAED1AA54DF67C07CULL, 0xBE978772D493E43CULL, 0xAE3907C174E0438DULL, 
            0xA7ABA1CED8ED981FULL, 0x01551020435D974CULL, 0x3DB1D9460EF785A1ULL, 0x21732528546D9B86ULL, 
            0x30B331AF8F9B2B85ULL, 0x267AFD2D48EBFFD2ULL, 0xEE0D435BC0A9B92CULL, 0xFBF7C68082AA7BD3ULL, 
            0xDE0203533B1B99EDULL, 0x937BC10456752FDAULL, 0x58AB52CE2C71BD89ULL, 0xDC117B94F199A713ULL, 
            0xA921C55C4E9AB37AULL, 0x56A79D0D2DC99EBEULL, 0x9429CD36AA8BF8C2ULL, 0x611D0C9AAE256AFAULL
        },
        {
            0x3660CEACDE6744CEULL, 0x72A764E06EE5908CULL, 0x091F804A25D9D973ULL, 0xA8B64DE7C33927D1ULL, 
            0xAD431D6628CE74AAULL, 0x6124AD06388B2604ULL, 0x522BE26CA41E4678ULL, 0x0878E001828C2D79ULL, 
            0xD600456EA9F1F458ULL, 0x8257793691E5BAE2ULL, 0x24BC94018DE6E21AULL, 0xD64E0AE2D73A7654ULL, 
            0x676D0D350953681AULL, 0x1FCAE00A553E936DULL, 0x0339901F4C50F4F0ULL, 0xFEF9FCDAFFCBFCF3ULL, 
            0xA5B954F0B5789E40ULL, 0xB7BF112BFB304714ULL, 0xE6BC4932E89FFC63ULL, 0x0DD74200B92A450EULL, 
            0xDE1007C971555AA2ULL, 0x50FF4BA81F0D542BULL, 0xCFA279C2A5F2258EULL, 0x60BD60A3E50A7CC2ULL, 
            0x90EFD3F40CB83A51ULL, 0x25E1B327DB624EFFULL, 0x21ACDCFF34A1D94CULL, 0x38B9104900A125C1ULL, 
            0x32A09A6FBCEE297DULL, 0xC2895991E96D97F6ULL, 0x2069FBE758AA5C7AULL, 0xFCA7BD8ACDFA4200ULL
        },
        {
            0x3D62AB7FADCA0D55ULL, 0x1DC58E28B0EF9910ULL, 0xA5472AB34B7C4541ULL, 0xF0D4E0A526E84EB5ULL, 
            0xE546D71C22262026ULL, 0x63570F3D9FAE361AULL, 0xD66952608A9BF3A0ULL, 0xAAC4A08BB44EAE8EULL, 
            0x5C7C44F5C360B15FULL, 0xB0FBA4F6306BE4F8ULL, 0x23DED425CEC190A3ULL, 0x45C8245169FBFC5AULL, 
            0x60C93C940A2B7CE2ULL, 0x44DD3E0E1321CFD5ULL, 0x8B68B5A8BEDA3E5AULL, 0xB86726651286F2B2ULL, 
            0x6B70156EEE092AB4ULL, 0xD2D69DDBB58D0080ULL, 0xD05987426D5E8AFBULL, 0xC7EF0E1A80999045ULL, 
            0xB3C241FE2480E28DULL, 0x62DF1537FF4BDC1CULL, 0x8FF558418533D66EULL, 0xD5499C2F134A07D1ULL, 
            0x49F46E7CF456BAA1ULL, 0x15F8CCCA53B6C159ULL, 0x96EEA0344D2AD08BULL, 0xDEFC91BAB49C5063ULL, 
            0x0ECC62374F3387EDULL, 0x9F08AEAF72457884ULL, 0xEAD0DDB7968824FCULL, 0xA24D124FE8D2A471ULL
        },
        {
            0x8EB6376EB9DB1789ULL, 0x253CECD821042E78ULL, 0x462747EF673293F7ULL, 0x3CB441D0E08DCBFCULL, 
            0xB6DA594E5DACE1E4ULL, 0x0549B84EFFB975C1ULL, 0x1159BFCCB70C4927ULL, 0xE352D2597BC139FEULL, 
            0x1AE3696C611A999BULL, 0x778208672712FA49ULL, 0x6D20356BB13E5DC1ULL, 0xE60A648A9759A79DULL, 
            0xD09FFA7BF4B933BDULL, 0xEF2FD6D39ACBE127ULL, 0xC8F4CA88F1249946ULL, 0x03E920FC44B77292ULL, 
            0x808DD76128ED2003ULL, 0x37220E7CF130A66AULL, 0x3B4AEFE03210263AULL, 0xE06F0979A6782D35ULL, 
            0x00A5CCA2C7ED252FULL, 0xDA0E54242966BCEFULL, 0xF94D09197C9E1BC7ULL, 0x684D05BBA221F1E4ULL, 
            0x847B782D1CF7BA67ULL, 0xDE9936FE84181CBEULL, 0x33B91DF1C460EEE0ULL, 0x02429E395A579AE6ULL, 
            0xD89D5BD64D18CC5CULL, 0x30F7FAF6E934C4BFULL, 0x09A48309AFC40226ULL, 0x440D12C47CD293A9ULL
        },
        {
            0xAF68FF780148F658ULL, 0x10AB243D85566C8FULL, 0xCB7278A9E3E977E2ULL, 0x4D420F8A04333ADFULL, 
            0xAD677E874CDFA556ULL, 0x1F79FB8CB75F6623ULL, 0xE110426658729862ULL, 0xBA072E8FDF462B14ULL, 
            0x62033FB137798A39ULL, 0xFFE332CACE2E4A6AULL, 0x6AAC73A61DB080A3ULL, 0x551FF95316C8911BULL, 
            0x49F568410DFF1CD6ULL, 0x67C26EC23A8F0B3BULL, 0xA8D9E75962664176ULL, 0x6B00229A77BA5C68ULL, 
            0x6DE6F7A8E5396BF8ULL, 0x35FA018A435804FAULL, 0xB7AA65E6450111D9ULL, 0xE40DC71708DD55B6ULL, 
            0x638CA9D294E0A289ULL, 0x4EF4A63D4EF44CBEULL, 0x5EC19FF9506BC950ULL, 0x103E0976DB643B56ULL, 
            0xF8AAA96915E9F448ULL, 0xC7D97D8D4D9D1FF1ULL, 0xC7BA34CBACD98B15ULL, 0xC7AB79964E56E613ULL, 
            0xC2C534E330D673B3ULL, 0xD4A4C75E4603D329ULL, 0xAA0CF6184EAD3F52ULL, 0x28313EAC98CE474AULL
        },
        {
            0x59560025FB6661A4ULL, 0x559022C4A14438EEULL, 0xA5D060A662BD4DC8ULL, 0xF527B300903A8178ULL, 
            0xE433E3F91955986CULL, 0x8B3476428FCE6BAFULL, 0xA23766A285BFF2D0ULL, 0xD4725B363922C2B4ULL, 
            0xFF585538A7CE1775ULL, 0xE1EE0372832F1D46ULL, 0x85406C0796151C6CULL, 0xF3F051B13036771DULL, 
            0xC4E0029A243157C9ULL, 0x07ADD404E2693745ULL, 0x953033E9420EAF93ULL, 0x049050435B792B20ULL, 
            0xEEAB050752827267ULL, 0xC3DCF64C55595948ULL, 0x4F5C800F3BC1932BULL, 0x610AABB856B07D17ULL, 
            0x103C1021A2FB0201ULL, 0x695E9CBAE052DF64ULL, 0x21291618992C847BULL, 0x79D75CEDC5D46253ULL, 
            0xC1718EADAC3BA5C3ULL, 0x08203A59503C1C53ULL, 0x90002279C128F858ULL, 0xFD4CE038BBE3F8A9ULL, 
            0x7C3328FA0FBEEAA7ULL, 0x80648736A5E610E4ULL, 0xBFD2EFFECBFBED38ULL, 0x7B363CE52CF9E692ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeySpawnAConstants = {
    0xB5E4C4BE5A91479BULL,
    0x3D69A33D9FA73F4AULL,
    0x00E6AAF217EB88C7ULL,
    0xB5E4C4BE5A91479BULL,
    0x3D69A33D9FA73F4AULL,
    0x00E6AAF217EB88C7ULL,
    0x59E1E750C53CDFBEULL,
    0xE31D1A059AA1650BULL,
    0x17,
    0x43,
    0x36,
    0xAF,
    0x13,
    0x9D,
    0x2B,
    0x44
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeySpawnBSalts = {
    {
        {
            0xEF9E4C912B5F33ACULL, 0x6E4F58C1A90BF6C6ULL, 0xB24BCD4F8C3D9426ULL, 0xDECA00CF74121E32ULL, 
            0x1986AE1D04D56691ULL, 0xC5F59B7C0FC2A26DULL, 0x35A78C3C96BDB684ULL, 0xB720E8C2B035F112ULL, 
            0x10F242E1C5329C3CULL, 0x42DFC89A217528FEULL, 0xD98B021371B0C909ULL, 0x86206E27A18D0330ULL, 
            0xCB9CDC75E6BA690AULL, 0x5390680722AB98F5ULL, 0x5DDA98FC205C2D31ULL, 0xA8621D243AC75905ULL, 
            0x0373EE43EA2591FDULL, 0x73889E75FD741578ULL, 0x97F00801C3408D16ULL, 0x0B0526399B6D96B8ULL, 
            0x44D136D903601872ULL, 0xA4B4AC8A63B76C34ULL, 0xD876A3DBB44F9810ULL, 0x694A12C0275831D0ULL, 
            0x31D9F0B822D7FF94ULL, 0x7C88999EAABCFD47ULL, 0x3FCE1491A62F051CULL, 0x3B8CD5D382D4B787ULL, 
            0x916F5CE6F1D44FBEULL, 0x1CB35DFD2E98F05BULL, 0xEC8B11A205AE1043ULL, 0xCB45F189153EC559ULL
        },
        {
            0x0BF080C4F3189049ULL, 0x40BF59333B783864ULL, 0x5980D105409E56C9ULL, 0xF05E47955F0BB3D8ULL, 
            0x58E69368B355C8EEULL, 0x37B522CE1F7D7A77ULL, 0x9C3CC995E995B80AULL, 0xCCC85A3C3203758BULL, 
            0xC099313C7A1C2F50ULL, 0x1B6EF00A9F4AC38FULL, 0x77C21BAAA2362D9BULL, 0x118F957905616248ULL, 
            0x535E081E769BDA4AULL, 0x53E9AC70222F7094ULL, 0x3E30ACCA25D7FA42ULL, 0x49E449674C898242ULL, 
            0xAAA845B1998ADB68ULL, 0x4E6F7CFCF2A11D84ULL, 0x20CB1D170AE40267ULL, 0x5B2ED9438D68A6EFULL, 
            0x1BA1503F4B77093BULL, 0x192EB3F754649B11ULL, 0xC3CB6DF18AF8F522ULL, 0xE21944AC89D6A4DCULL, 
            0x426633AC1194DE59ULL, 0xC5A8EDA6A2782D6DULL, 0x829370D69A63B696ULL, 0xF73C42664CF4D182ULL, 
            0x0F5CD4EA829500CBULL, 0xF6508CC67AAE296DULL, 0x592E978595FFC492ULL, 0xF6F45BDF843E411AULL
        },
        {
            0xE21D285180C40B57ULL, 0x79A011AE37F596A9ULL, 0xF9103D7628F44041ULL, 0xE71585946102FB2BULL, 
            0x7C4E5DABA07C8D26ULL, 0x71AE21B2B60CB9D5ULL, 0xA8A5AA5515FD8D55ULL, 0xE32745F4016B9E9BULL, 
            0x59BEF004D4A461BEULL, 0x4BA4323742C594DCULL, 0x5207F671FBBE9238ULL, 0xDA977C7B679C9BB0ULL, 
            0x53768E17989BB554ULL, 0xC0CBF47896C050F1ULL, 0x7DE6E4852F42570FULL, 0xC30EE2582CEA09EDULL, 
            0xFEA30F0E9A6CCD66ULL, 0xA91611517A2510EFULL, 0x144DDEDDA80A58A8ULL, 0xEA8EB110070C80F5ULL, 
            0x6CA3DABCD964EE5DULL, 0x5860B780C26E7B13ULL, 0x639954F6754E1718ULL, 0xEC47BEC6EF1124A3ULL, 
            0x959E66607A76A75EULL, 0x244C4AA31C062F23ULL, 0xB63843316D389384ULL, 0xB61045B5DF46F024ULL, 
            0xDBC0137D71ECD7D1ULL, 0xDB3BFE831CEEA4BDULL, 0x881E504455EF5943ULL, 0xE273DBB268A44718ULL
        },
        {
            0x8E23637F30FD9C61ULL, 0xDCB31225279B36E4ULL, 0x9181B2B576143A54ULL, 0xCC9C1741BDA9A0B6ULL, 
            0xD45D8E343C039CCCULL, 0x99B9886A6073C4BFULL, 0x6C355DB19B2A7B50ULL, 0x16693FF0761B341FULL, 
            0x20B64BE538458DDDULL, 0x068B288F96E9D792ULL, 0xA4F4345FD3E9C52AULL, 0xEC6987159569982AULL, 
            0x1432C3E02D7E6B6BULL, 0x4D589CFB28F77E22ULL, 0xACAA271E14205F5FULL, 0x11998CC1B432C869ULL, 
            0x3DF5AAFDE0B6132EULL, 0xF8AF13B8D4BB6C96ULL, 0xDBC6435152CCBF7EULL, 0xDEC5DB859AFA812FULL, 
            0xD8260E93B75A9484ULL, 0x9F732BF86EC2A373ULL, 0xF3E39131B7BB1F5AULL, 0x006F77EE9FE2F44DULL, 
            0x807BCA80712B49F8ULL, 0xF4B5BDF6F2FA1F61ULL, 0x8918962656EF0F35ULL, 0xBE8B03E909E83593ULL, 
            0x21673F34EC14AF93ULL, 0xFA1FFA27C2C2386CULL, 0x3D303C53FC5F807AULL, 0x7E4D51F50CEE8DF3ULL
        },
        {
            0xC33FEC862A5EA1B0ULL, 0xBAF37050DED3B413ULL, 0xCF5C65F843AAD180ULL, 0xF51C93A955E62574ULL, 
            0x2D905418F3D5D09DULL, 0x035B3E12050E4BF8ULL, 0x7CD3FF929A577E14ULL, 0x9471D2E9A7F631EFULL, 
            0x4C7BDFAD6D113A66ULL, 0xA7EAC695586F65B9ULL, 0xA6E52E3A0611F144ULL, 0xFE2BE6D6846F8B5DULL, 
            0x9213B27CE7239735ULL, 0x37A1128900161424ULL, 0x81CF2B4AA351BD93ULL, 0xC8347CB2E5F36703ULL, 
            0x5A35E8C3101A6CF3ULL, 0x30E21F3E26EA2885ULL, 0xA28856AA32F2BDE5ULL, 0x09105E0ED5DD210AULL, 
            0x6AF0842D8D26FA22ULL, 0x4B845E315D479EB4ULL, 0xD76FFE837DA7868AULL, 0x760132593FA54DA0ULL, 
            0x42B176E6CE02A1F9ULL, 0x3CB0775FD69EA91CULL, 0xF5B319F91016EB53ULL, 0x7E0A532A59DEC08EULL, 
            0x88B1FCA2BC342C81ULL, 0xA6CA75407E16E231ULL, 0xAEEBB51908D92379ULL, 0x14842A5BFCE2FC76ULL
        },
        {
            0x63BD358BA0260E57ULL, 0x4E333085EC26793FULL, 0x6809C7F29CF4140AULL, 0xAE0CC22AB2B57BA2ULL, 
            0x85E08459B0F1E467ULL, 0x4700DAE820C98BE3ULL, 0x0B5FA7C4B232B983ULL, 0x522537BA1E2FBAD1ULL, 
            0x490584277BC02258ULL, 0x9017D13DE9AA2F88ULL, 0xBADC4C8F85425EEFULL, 0x80F15C7FF1AF43ECULL, 
            0x2AFC14F77431FED7ULL, 0x3CC9E3C84B5AEBA0ULL, 0x87F53DE23F75EAC8ULL, 0x0B60A941D088337FULL, 
            0x30A3FF2CF4C0ADBDULL, 0x419CFEA8219E7832ULL, 0x03604BDFD0C0AFEAULL, 0xE5B4505980A8E038ULL, 
            0xD3D71C63E92F508BULL, 0x7B88A29AB8D56CEBULL, 0x5E6A7C1595C6147DULL, 0xA22422406C709C69ULL, 
            0x4A4AA09E008BE1CBULL, 0x100F47A5D2D8B131ULL, 0xA024ACDFD393E1CFULL, 0x200114D965931A34ULL, 
            0x2EF23FF9F4136A6DULL, 0x2A57FC4004D25805ULL, 0xBFB2524A2485689AULL, 0x17AACC38BC447A2AULL
        }
    },
    {
        {
            0x9143E8E57762593FULL, 0x25D269CE0130AADEULL, 0x09425111FD6D8EADULL, 0x4778A8D2A90D693EULL, 
            0x12C81C2940BC71C0ULL, 0xB9881ECA4FA1FB79ULL, 0x17E5F84DA2825AD5ULL, 0xAAFB4DCB5B517741ULL, 
            0x91B0C58122680EA5ULL, 0x65A4ED1E7D6C1088ULL, 0x7E01A4AA7DF2F92BULL, 0x0A59860FF8804B7EULL, 
            0xC18A8FCC84AA7F92ULL, 0x7234C506313A0A33ULL, 0x54ACFB7CD80F28F7ULL, 0x2CC90549931871D5ULL, 
            0x6419F1C8CB59CA82ULL, 0x868D587056348929ULL, 0x0C81CADCBD6BECD8ULL, 0x4CC8A973C8E2A081ULL, 
            0xAFFCB5887E7D1C9AULL, 0x11E542F12BA38C26ULL, 0x47C17C303A36D62BULL, 0x5CFD10C1BF007C1EULL, 
            0xE1909BFBDFF03125ULL, 0x32EE8E86A85BF395ULL, 0x5C3EDA7C3CAD59CCULL, 0x54E642869DCA047FULL, 
            0xA329BC0B4F153AEBULL, 0xA6CECF02D769F440ULL, 0x1374C12A06B019F4ULL, 0x7F997BE6357E169EULL
        },
        {
            0xA3038FFEAF3B1934ULL, 0xB49E220230B8FA78ULL, 0x493B97BD6BF0A28EULL, 0x2E6FF8BC9E62502CULL, 
            0x1E58C8F6194E1608ULL, 0x79B08669D7AE1522ULL, 0x3C6DD09334348099ULL, 0x9CC016D098125727ULL, 
            0x28262C8274D9D877ULL, 0x8C400952F40E2ECCULL, 0xF2EFB0E9A75EE804ULL, 0x4D6AE4B225C40CBFULL, 
            0x5330F0AEF5CF883CULL, 0xA5BE8C976E75E28DULL, 0x20D8314616708D5AULL, 0xAED9E91848D5CD31ULL, 
            0x5426E8C569FB7EA3ULL, 0x7E20367379B7FD9AULL, 0xB8066106FC97F710ULL, 0x87E890B0DF446BB2ULL, 
            0x305552EDE0C09462ULL, 0x4B7A7CE18B31BFEBULL, 0x7EBC58DAB3333ABCULL, 0x988C9C4109AA88BCULL, 
            0x363618F5255C697EULL, 0xC13030BA9FBEFF2DULL, 0xDD380B3F993220B3ULL, 0x5E1019F12F27BD55ULL, 
            0x375C2E388968A3C9ULL, 0x142275293E4755DDULL, 0x853CE194E6FFAE4AULL, 0xAE1D8C128C616F54ULL
        },
        {
            0xF4821AD6356031A7ULL, 0x35619BD0E4C22C0EULL, 0xF114A309B1DAB391ULL, 0xFE96BC4BA74C4242ULL, 
            0xE27A81406C9AFAF5ULL, 0x82FAB51C2B77FEB5ULL, 0x1EF4DA4AABF6D41FULL, 0xAFC9A57860D8A40BULL, 
            0x056730B1E3F37A98ULL, 0x822A17791AE4099CULL, 0x104356C48F0AFFDEULL, 0x9717DFEE955052A7ULL, 
            0x12CA94C41A737830ULL, 0xC34E0EAAE6E0A5D4ULL, 0xA108FD488F346100ULL, 0xF3F61FBA93E77B77ULL, 
            0xC59DB8639955F367ULL, 0xBDD453BEDA90A243ULL, 0xF99405F22A53CD58ULL, 0x1D353F03645DE381ULL, 
            0x9A86ED713A5495F7ULL, 0x2A082B9D51488F39ULL, 0xAD66A82461EB6770ULL, 0x627BC3437F7B1637ULL, 
            0xD5DEA90F038B8732ULL, 0xFAFA396113DC12EDULL, 0x4D14DF9A272C2660ULL, 0x568AA016E0C64CE6ULL, 
            0x6161BBAF92FDEB2AULL, 0x7A5D880CD93AEE0DULL, 0x083E36EB240BD013ULL, 0xBB49C9AF8B7A6C4AULL
        },
        {
            0x734497688F15CF66ULL, 0xDECB93F6FA80DB88ULL, 0x0F2CCA0B042EF388ULL, 0x5EC8129A9C2FC68DULL, 
            0xB73CAE42F44614D6ULL, 0x315F834341BAF920ULL, 0xB71BBDA8C45ACC68ULL, 0x0FDCD7A76FDE4EA6ULL, 
            0xE77E1EF9F2221814ULL, 0x250C104201EFB56EULL, 0x0681715B593B7A16ULL, 0xCC54BF61D9111313ULL, 
            0xF4A2EDB1E25F37A0ULL, 0x3FC80221649C7D3AULL, 0xFDB7A2F56F0A8CF6ULL, 0x453A5B6B3E19D946ULL, 
            0x142318F847D67593ULL, 0x69984E67C8B41BCDULL, 0x7F7A1C13A1A2D0A2ULL, 0x8613C843950A3580ULL, 
            0x0BA6D41AC77BF321ULL, 0x77CF200436B0AB0CULL, 0x2B21467772C3E53CULL, 0x356C680751FDB995ULL, 
            0xE4F4D0B19DDDF8FDULL, 0x490EA8D71FDF1DFAULL, 0x37271F71F4AF9EB2ULL, 0xCE334097C79FFCEDULL, 
            0x6EBDF079140BD425ULL, 0xBA867823D8F57D9FULL, 0x3D715850CEC81FF1ULL, 0x15A3708584CCC112ULL
        },
        {
            0xC056FA2EED705A81ULL, 0x61EDF6C1A3D18D06ULL, 0xE118690FECA61735ULL, 0x67C5D72F18066866ULL, 
            0xF09889DCA2C76FDBULL, 0xEA167189CD252A57ULL, 0xE42651FF5FD54ECAULL, 0x63424C095601127BULL, 
            0xA9421CD75D97A77EULL, 0xC58DBAB80D36C08FULL, 0x0B172857DAFECCAFULL, 0x0228F00FEC925D79ULL, 
            0x854C7EA12EDCB834ULL, 0xA0FF213F72590DB8ULL, 0x8BC3D84AFD495B63ULL, 0xE3B141889C8461DFULL, 
            0xF98781E24F458803ULL, 0x8601E12481E91420ULL, 0xB1876A2702C72575ULL, 0x0A07471D77087AF6ULL, 
            0x4053CAF3EA17D5CEULL, 0x9CA2148498BB3D16ULL, 0x95A9AFA32BE24BE2ULL, 0x223D0143E7D18A7BULL, 
            0x54EC21B45F126515ULL, 0xC02FB1BA8F7FC976ULL, 0x1B293DCCFA6660BDULL, 0x463576FFF7F5BE9BULL, 
            0x48EF99E783305B9EULL, 0x32B2DAF65EF1FC52ULL, 0x1A432D963BE74120ULL, 0xD966AC81837A5614ULL
        },
        {
            0x9DEE275CC428ED9DULL, 0x772DAF583A4FF7B0ULL, 0xE77871DB5A63E319ULL, 0xF595FE4EED538FA3ULL, 
            0x7E19BBAEBA50B89EULL, 0xCEF6B9F2B91579AAULL, 0x6410DE5723EFA340ULL, 0xAA855CA9C41185E8ULL, 
            0x8A01357F6B142381ULL, 0xB13EDD6F3C0B9AABULL, 0xC6F9023D295686E6ULL, 0xE0C35B1871A51C02ULL, 
            0x0BEB50CC9DAA74E4ULL, 0x2A2AA343FF72D354ULL, 0x42741B15D98C2CBEULL, 0x270C5A866408D2D4ULL, 
            0x8691F96DE98C200BULL, 0x92DD4B68389C4AF3ULL, 0x626E138F7692F854ULL, 0xEA799D30F848D708ULL, 
            0x410CB5211998249EULL, 0x00374512CAF206CEULL, 0x9F87A5DF28757EFEULL, 0x1A677236913851C4ULL, 
            0x5C8DA32DA57D3DD2ULL, 0x539CEAE6202AD47FULL, 0x6F76EE132A34599BULL, 0xFA4ADC1E53AEDE7AULL, 
            0x9B4442C6EBAC350AULL, 0x32EA86D3B783E438ULL, 0x6F6AD025C56A033DULL, 0x9D5D5BECE57D58B5ULL
        }
    },
    {
        {
            0xE7C2A901C5BEC8B1ULL, 0x555DC49E9EA3F4E5ULL, 0x8BC2D64B06FF135CULL, 0x40C4451F5D11598BULL, 
            0x41805AAB4D3B5BE6ULL, 0xA1C3306B3EC6A344ULL, 0x9B8236CC061348ABULL, 0xECCEBEA81A5CEAB7ULL, 
            0x813FA57012E1739CULL, 0xF475854CA30929C4ULL, 0x1ACA1A6DBB0EB6D4ULL, 0x2086CFCAED0D3F9DULL, 
            0x5BAA65D61917FEEEULL, 0x98EF493C1DAC61DCULL, 0x1B6F34A676EE5766ULL, 0xF03C8A23BD1FA774ULL, 
            0x42A3541D65BCB2DAULL, 0x6D419F3D3C6595B3ULL, 0x4D6F0CFF75373637ULL, 0x3E57A3D8ACE411F1ULL, 
            0xC72002B20FA4409AULL, 0x11DF5CC6DE41F7D0ULL, 0x4BE94198D7D73002ULL, 0xF1B9B9D6E01D718BULL, 
            0xE50C6DE6DF9ED096ULL, 0xC25D6222F1B0261FULL, 0xA56F0894EE8458C5ULL, 0xD271DFD3ED04C410ULL, 
            0x042AB8853243E131ULL, 0x1912484E829B644FULL, 0x1B762D1B2C2FA803ULL, 0x28E627023BCAA06BULL
        },
        {
            0xE59DB6B2F569D3B6ULL, 0xEA4E18A1F0BD044DULL, 0xA58D8572F22D7CB3ULL, 0x782D8456CF931132ULL, 
            0xCC54579D7A300941ULL, 0xA69C8988377E6CD1ULL, 0xCBC8BDEB14871460ULL, 0x4FD56D4C4F4B7136ULL, 
            0xAC9C02B47A39DDF9ULL, 0x960C61C01F44B454ULL, 0xB6DA1E11ED35CECEULL, 0x541A51C797C20FEAULL, 
            0xBDE25D8D58066D83ULL, 0xE493654F01D3D143ULL, 0x37DE9466B2A0FA02ULL, 0x620C176FC0C0821CULL, 
            0x5DA8276D6097611FULL, 0x00A199CB7B356DF0ULL, 0x18300CBF36D90C9CULL, 0xD2CF76475DA68C3BULL, 
            0xB5F7ACB4E7B99EC3ULL, 0x15500C915360FEDFULL, 0xB965F038ECFAC98EULL, 0x2063B6049E9CB4E4ULL, 
            0xA3F4F8BE8769E14BULL, 0x874D042E6CB89478ULL, 0x0C3A5823BA0F93D9ULL, 0xEA2976868373FEDBULL, 
            0x266DA4712501220CULL, 0x34122D19D6D04FE1ULL, 0x980E5AD3528321C8ULL, 0xA18B527C8E9B3A90ULL
        },
        {
            0x49CB8105453017CBULL, 0xA0D3B5DEBC084D2BULL, 0xD5DB9DFF97973D9CULL, 0xB74BB83386D64200ULL, 
            0x8B89D47969B84538ULL, 0x2E8B4E07DAC85CBFULL, 0x49D8590F1D035B1AULL, 0xCF496579B81CEB45ULL, 
            0x41D99DB6C31F321AULL, 0xE8BEB7CCF5EE79AAULL, 0x533F0DA44DDF2CC6ULL, 0xC8CBF0CFD8C1046FULL, 
            0x401421F8D447AF67ULL, 0x1FD27D461C75AEBCULL, 0x2F847C0BEF61E962ULL, 0x2275EA37A73EA587ULL, 
            0xFE0EF5558A4E6A8AULL, 0xAF935FD082A469E5ULL, 0xA1DFDC875D0465C2ULL, 0x61F65F3CA110130BULL, 
            0x6F1D055F9D70022DULL, 0x95ED87EF268FA2A4ULL, 0xFFB357FF2D6C951EULL, 0x73762DCDB4BC9A6BULL, 
            0xB100612CE87071F6ULL, 0xA8AA4044CADBECC9ULL, 0x23A0DA4812247FC4ULL, 0x7FDABBCAF52D0797ULL, 
            0xFB898CF7101E11F9ULL, 0x1D8E6FEAFC21C20FULL, 0xB76944F3B70AD5D3ULL, 0x034F194AAA1E4D3AULL
        },
        {
            0x00DFEC9F2D9450E5ULL, 0xB028A01B9C4CAD28ULL, 0xFFBDDADFA233D7AEULL, 0x0DD81E6A60132C1EULL, 
            0x57CBC89352BB40D1ULL, 0x574B664D055B16FCULL, 0xE9B4EE5335188D5DULL, 0xB03829846CCDCFD7ULL, 
            0x51C5EA3EAFB62C40ULL, 0x65234E7906F3FAECULL, 0x10DE4650C437A26BULL, 0x039BB360C18C60D6ULL, 
            0x1E4FA5DF4149D229ULL, 0x9BB984D03302FCF0ULL, 0xE7D0252E9C5AA94CULL, 0xB44227FC6540A122ULL, 
            0x6D11D12B51973B16ULL, 0x7B608AC3635F552FULL, 0xF2361BC28BF34288ULL, 0x09A547803EFC5BD8ULL, 
            0x418DE0F40F0DF1EAULL, 0x3F3BF5BB3F9C7696ULL, 0x726F01272663F6AFULL, 0x938F6DA6C18B7A73ULL, 
            0x1FFD7EBC33AFE1E2ULL, 0x69F7F76574213FDAULL, 0x2A1D4FC1ED8CAF34ULL, 0xF0AE7C6C86B7FAE9ULL, 
            0x329792A52E44B857ULL, 0xB772DB9C7FCCFFD7ULL, 0x5252614B98B5FCD9ULL, 0x5CCC3174FDB9476CULL
        },
        {
            0x7F0648FDA2624FDCULL, 0x669310D65F096F18ULL, 0xD5017F0EE38710ACULL, 0x13B5B51C98D3EFA0ULL, 
            0x7F6E8AF8F0DBE264ULL, 0x0374C808A6B4F740ULL, 0x7CCA85E2BE60C6F9ULL, 0x369DAEE75957872FULL, 
            0x14FF548484A4AD2CULL, 0x00ADD47FFAFFC818ULL, 0x17770151BC0FE9F9ULL, 0xA27493C19FE94EF6ULL, 
            0xA33433220E69E57EULL, 0x7EE0992A7BB8DA7DULL, 0x36030EDD4B9C7076ULL, 0x0629EB132753D9ACULL, 
            0x158FDB34E1F588F4ULL, 0xB359C4D4311BEF5EULL, 0xE0D8299BAA30EE71ULL, 0xD051C07127120A62ULL, 
            0x244E25C8BDF95088ULL, 0x584A85861E040F19ULL, 0xFCE7E225D0F0FD17ULL, 0x08F7098502C0D2EDULL, 
            0xCC20B40B765AB785ULL, 0x3730815FE66ACD88ULL, 0x2F96907F424345CAULL, 0x197FD4BBEBAFE221ULL, 
            0x48209C67577F09D8ULL, 0x528B475AE4AFB8DEULL, 0x9A66EF7D47E22654ULL, 0x47D2F32B01B76BF0ULL
        },
        {
            0x53E4AC22F2F82082ULL, 0x7B4858CF3EB34D09ULL, 0x1A5F996ADF19B606ULL, 0xF00F7236F233CFB7ULL, 
            0x7431F606EFFB259FULL, 0xE9FCA7B7684683CBULL, 0xE5CC9E6A1E8B3035ULL, 0x91B5086BFF74122BULL, 
            0x01C66AFBFD67AEF2ULL, 0x64D903768A5B92DEULL, 0x89121090C06317EDULL, 0xF37C19E6EA20C505ULL, 
            0x6D77A13345BE48B0ULL, 0x544BBB2FEEADE2D7ULL, 0x5FE3C157469EDD4FULL, 0x3122982F7D96A354ULL, 
            0x4460A82CADDDCEBBULL, 0x2633D7F92E6F5CF1ULL, 0x62803289EBCC63B9ULL, 0x35AB94128E4EE5C9ULL, 
            0xEC5D24789BB613E3ULL, 0xDEFCA66B709DEA90ULL, 0x486D8C43536437A8ULL, 0x26E5DDAFF552BEC7ULL, 
            0x895CE33836E2F096ULL, 0x3888AEBACDD77F51ULL, 0x7D193F5E6C52DB82ULL, 0x63E946D0349C1E4BULL, 
            0xF4BEE30D53F918B3ULL, 0xD6CF13AF12A9B4D7ULL, 0xF424F8F50BEB827DULL, 0x85A7C572CBB3F2C1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeySpawnBConstants = {
    0xDD25C1641139F93AULL,
    0xA14B437331B1508CULL,
    0x720568D2446E468DULL,
    0xDD25C1641139F93AULL,
    0xA14B437331B1508CULL,
    0x720568D2446E468DULL,
    0x18778E0D7909C4B5ULL,
    0x4706872CC2808B11ULL,
    0xDB,
    0x89,
    0x87,
    0xF9,
    0x19,
    0xAF,
    0xE3,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kSeedSalts = {
    {
        {
            0xCBBEE2C9A62AFE07ULL, 0x61D4F3F19BC1BDB9ULL, 0x9B1F06641BFC6F57ULL, 0x1F18FD29ACBB6767ULL, 
            0x0D65B06EB3A9820AULL, 0xE25DDF49FA5DD774ULL, 0x177ADCFD0AC7923CULL, 0xA585241BA271490AULL, 
            0xFD2C62F0C66375B0ULL, 0x3FBA5C3A16BEFF52ULL, 0x2FDF8F642197D131ULL, 0x2533B082CB55F4F3ULL, 
            0x83F3F99C8FDA309BULL, 0x86A28882796FB9CEULL, 0x4AC88DAACCB6A7B7ULL, 0x9FA5C4E11B81E84BULL, 
            0x63B0E87B1D383C66ULL, 0x4D4B3D36A812EC70ULL, 0xC8CE51AAD7A99338ULL, 0x543E07B666F68652ULL, 
            0xDB6499D1AF0FA5C3ULL, 0x605EEC5DEBF95AFCULL, 0x0B638460458A9905ULL, 0xD4DF4DCA33151FCEULL, 
            0xD789FB6D18B49785ULL, 0x988672E2BA788BC9ULL, 0x1FA6DF62495312F9ULL, 0x16F965BB3601BAC9ULL, 
            0xFBE78BE748375723ULL, 0xAB29501705B70586ULL, 0xDAFA28294A6384DBULL, 0x4E721E726FD24EFFULL
        },
        {
            0x13D5C3A8A8E57F21ULL, 0x1B6E41450858C620ULL, 0x53F18A0C71AC67FBULL, 0xECE3BE9698B057FDULL, 
            0xE559511CD74535E3ULL, 0xCD474DCB109C8A41ULL, 0xA297B75DE81368E2ULL, 0x3EA9EBB2B53D17CAULL, 
            0x9B7DF94CD69903B9ULL, 0x1744C5705CD0B476ULL, 0x62FED281D957441EULL, 0x516163080C7F2CD5ULL, 
            0xABD8D4206D647199ULL, 0x33557EF2540BAA89ULL, 0x14E28DE86FB6B04BULL, 0x8B5751BEBBE209A1ULL, 
            0x569F74FD506010EBULL, 0xBB78CE0166472323ULL, 0xE5262189A363CFEAULL, 0x11185368EFBFD337ULL, 
            0x56DCCDBED1E63345ULL, 0x84FE268CBDA1DB04ULL, 0xE905EC73FDD4F3D6ULL, 0x0AC2FD93975892ABULL, 
            0xF7D9732F12FF1833ULL, 0x18677993C96A4C0CULL, 0x93BEA9B3306573B0ULL, 0x52C61D0F2A71BE71ULL, 
            0x5BEA220C38A38D9AULL, 0xC2D2CB1F5C60807CULL, 0x4A7678629D3D484DULL, 0x72211FFAB1F9D67BULL
        },
        {
            0x6E3F4A08D4BE17FAULL, 0x12513A4AA32DA1ADULL, 0xC2D4F1C037C38B21ULL, 0xD7CE648E5B9BAA9DULL, 
            0x52CD87E7F6DC9FAAULL, 0x87830DF542F72931ULL, 0x4D9683F88938CD2FULL, 0xF38948D8837C75F5ULL, 
            0xD83BA9C548A6BDE5ULL, 0xF025C16CA2BDC5C1ULL, 0x6C909FC0FB369B6BULL, 0x19A8D11133592B46ULL, 
            0xC1E1EEAF317EF4AFULL, 0x8B8985FC5117DE10ULL, 0x472824879057E645ULL, 0xCABB5DD82933ECD3ULL, 
            0xCDF2476EF86577AEULL, 0xAFF131E5CB8B6119ULL, 0x73E3D975372846FAULL, 0xECC9E3225C3A4D25ULL, 
            0x7EFCC28A710E019DULL, 0xE1E743C6970027FFULL, 0xBDEB70B53155E136ULL, 0xD24811AFD226D558ULL, 
            0x9B137810FE8C8E4CULL, 0x148F25CC634CE6FBULL, 0x940208DB62CF4D9AULL, 0x8A912FF22FEEB8A0ULL, 
            0xB9D49D3471E58816ULL, 0x8A06358D74BE261EULL, 0xB3151C22FF691735ULL, 0xC53F8662D1C97214ULL
        },
        {
            0xA2EECFEACA3751A2ULL, 0x92B9332CC78EEA1FULL, 0x7A623F5374F625A3ULL, 0x33F0B0ABC2779750ULL, 
            0xB964B2EBEA1143C9ULL, 0x1C338A2471452400ULL, 0x80E369525E7E47C2ULL, 0x4A4BA11D50DBEC24ULL, 
            0xCE1B0ABA335E0A67ULL, 0x618C818B8CC45427ULL, 0x55487BA8ABB2368EULL, 0x3497C1ED1C5193A3ULL, 
            0x0542C1DB3CAB586DULL, 0x064AEA6F6A9FBE66ULL, 0xD92B97502FFD0304ULL, 0x9C1DE44E9D6C9B86ULL, 
            0xB8DC7AA4E8202655ULL, 0xA642B114FBD293ECULL, 0xF14EE7C4CE6BFC06ULL, 0x34B36B81DA904E8FULL, 
            0x19B225BCDB0F9CE7ULL, 0x40032DCCF9E314C5ULL, 0x456906A383C5EE17ULL, 0x6E886685F67AD8A5ULL, 
            0xA8470F2DB84BC8D4ULL, 0xEB865EE4351B9A88ULL, 0xE0F2D502AFC7696AULL, 0x25127A3734697D34ULL, 
            0x5B2E814716B47FA8ULL, 0x712A73C242D2A1A8ULL, 0xC38B2B00B9BE751EULL, 0x64AFC365E9F04DD2ULL
        },
        {
            0xF445269A4778571FULL, 0xD9DDD7F6A8702A72ULL, 0xA40DD68A54F26AE5ULL, 0x2EC241D99B152C17ULL, 
            0x75F3D1271E7272A2ULL, 0xA839529800AE64CCULL, 0x41729F17600FA1E4ULL, 0x99E7196AF1FD6D13ULL, 
            0x1236B01FEA5897DBULL, 0x7FF2EF70B688A1F6ULL, 0x3FF78C0558539085ULL, 0x2D687AFB3ADC954AULL, 
            0xD6662FA55E211E05ULL, 0x991B5A5177A7DF88ULL, 0x552EA08F6ED8F4B1ULL, 0x6BFAF5048C6ECE39ULL, 
            0xDBA84D05D3816F66ULL, 0x0E962A28424CA958ULL, 0xE26B778AA89D3451ULL, 0xD87FFF898EB9B09DULL, 
            0xA64A28A86610BD83ULL, 0x99D48BC471ED4055ULL, 0x1C1211BB24A6E086ULL, 0x27C02FCD103E43CCULL, 
            0x30D746565CEEEB04ULL, 0xCE2878556218BB6BULL, 0x2164D14C720521FAULL, 0xF209679584DA732BULL, 
            0x615F102776E6A689ULL, 0xF56ACBE9DD17BC8DULL, 0x193057F85E6C9551ULL, 0x93421424A8B6A4CBULL
        },
        {
            0x82D090F0CF2CFBF4ULL, 0x780451471BC0B6D4ULL, 0x298E3EFA04A6219CULL, 0x88623497E60E452AULL, 
            0x3C1F551A91C1FBACULL, 0xD5A9184E12CEF1F2ULL, 0x5DE58F4D89AA7FF3ULL, 0x68FB8F7FD0882CD0ULL, 
            0x31D93D93D3F4F44BULL, 0xCCEE5E47C6FBDB29ULL, 0x4A40F66480AD1EF3ULL, 0x904B910F72EC2402ULL, 
            0x92ABE038BAD2CC36ULL, 0x998A96792C587509ULL, 0x2CFC45336301BB95ULL, 0xFBBE7D955B5CE141ULL, 
            0xC7101314CE177748ULL, 0x28F32418CAB1099CULL, 0xB2AB1E483E570A83ULL, 0x22695C46E0FF3595ULL, 
            0x398592787A7EC6B7ULL, 0xCEB62684AC2AF64EULL, 0xB1CFE2283F2D4BC8ULL, 0x5E290090707A18DBULL, 
            0x51B436C914B1B946ULL, 0x23B42156D8FEEE37ULL, 0x19E1DBB27564D542ULL, 0x22BBC570C89B29D6ULL, 
            0x76FC58259A67F3A1ULL, 0x4557458D6CFAF962ULL, 0xDE965F1A5A00E0C8ULL, 0x01A01263F6A4DDCEULL
        }
    },
    {
        {
            0xE38B8E1C56D74180ULL, 0x43F64A2E3CDF3D67ULL, 0xF8D3673590E421D2ULL, 0x2FA7E8642D441007ULL, 
            0x83E57183E7127ED7ULL, 0x35935FC55224F4F6ULL, 0xA44543C077849EBEULL, 0xB9D6A0D2787A3072ULL, 
            0xC153F854747C981AULL, 0xD31781727E6E5559ULL, 0x936D499AFBB24BEAULL, 0x98C1918AE93A0088ULL, 
            0x6EEDD530A4C4A3FEULL, 0x034CAD85125291DCULL, 0x88AE7216A3402E2DULL, 0xA62E0A3F624E0E0EULL, 
            0x024DD85230387E57ULL, 0x2B567C378F81B050ULL, 0x6B8B9D7B17920C88ULL, 0x2F5D2D3AED9A35FEULL, 
            0xAF1C8CC8C3BAA0C3ULL, 0x87AED4AF2E491978ULL, 0x722006FB39120533ULL, 0xFFA60246D2E35A2EULL, 
            0x3E4B132307807866ULL, 0x43B6A7C9E353EA1DULL, 0xECD3CFEE982FDF1BULL, 0xEB570B4AE1EA47F7ULL, 
            0x074AFD85050B46BAULL, 0x53963AF590B18700ULL, 0xAA1C4A03A2DC0143ULL, 0xE4AE843762F39476ULL
        },
        {
            0x6B2D35C9F743277DULL, 0xC9950AEDC4321BC5ULL, 0x2AC0FDFA5FCE41DDULL, 0x92D79040D7CA5C2BULL, 
            0xD065A2661CA5407FULL, 0x59647A87166BE45BULL, 0x633AB7DB6DE3732AULL, 0x37463325FDD7CBC9ULL, 
            0xD285F21451E876CBULL, 0x0F51248D61C10592ULL, 0x67844438B89B2288ULL, 0x777774A361C7A62AULL, 
            0xB153F00CF5305197ULL, 0x4569859E2AE0E7E4ULL, 0x9C9898123D73B977ULL, 0x3FAD4D380C3ECD4BULL, 
            0x507E0FA475E6FFC4ULL, 0x379B70810B21C27BULL, 0xC16ABD0ED73980B2ULL, 0x31323AA478C8A7FEULL, 
            0x5B8FB9FB29A7B50BULL, 0xE8AB668DEAAF322BULL, 0xE7D7F15A8547B8D9ULL, 0x140E8EA922B64BF8ULL, 
            0x74A1CD44FF9669D0ULL, 0x838F1A8C08ECE277ULL, 0xC9159E3DB77B96E0ULL, 0x22B3E68158694067ULL, 
            0x2AE76DCB69BDAD8BULL, 0x9741ECE21E65F540ULL, 0x759CBA667CCEEC8FULL, 0x17FEF0666788BFE7ULL
        },
        {
            0x060541329ECCD9BFULL, 0x00E23A4A3C87E4A7ULL, 0x4CCABF388AA8F98AULL, 0xF0A39BB327F6D28FULL, 
            0x72394BAF4D7122A8ULL, 0x91DB8FD8235CB0C1ULL, 0x19BB23F878D126AAULL, 0x59D90DFFB13CBE02ULL, 
            0x9B3D9901470A9673ULL, 0x31DDC66F3F72AB55ULL, 0x068C142F8C0F9B7BULL, 0xD385DE35D1910723ULL, 
            0x87980573FF552316ULL, 0x3BB5D5C35F60144CULL, 0xB941E99F5B82B592ULL, 0x3082EADF262D8275ULL, 
            0xE9B5C0F91CD5EF9FULL, 0xD66A86E6D1A32892ULL, 0x4513DE09184EFD7EULL, 0xE3F9B8BB1927C5BEULL, 
            0xF4B58C84D4CD8262ULL, 0x4DEBACADB7C20E3CULL, 0x05CE8226873E6A36ULL, 0xF4887D2CC8A25862ULL, 
            0x2A0CDF1B71B450F7ULL, 0x82AE96B7FC8CE7D1ULL, 0xA5EEDA522306F922ULL, 0x2A982D6924BB3B90ULL, 
            0xF8384B1D9CC81860ULL, 0xE1AFD69361017E7FULL, 0x628DA4AD6B190166ULL, 0x450A2882902B595CULL
        },
        {
            0x7B71747946B708E2ULL, 0xF5FE949019F93E14ULL, 0x41191C17EB5199B1ULL, 0xF50FC119A53DC85FULL, 
            0x7EBC98081576CC87ULL, 0x140C3E948865DF9CULL, 0x887DC95EAFC53A00ULL, 0x78E56A1429E074D1ULL, 
            0x772D6232B5C3D65CULL, 0xB3EE804B472E51A9ULL, 0x4259B8176961A508ULL, 0xAE27D2CEB5F87B25ULL, 
            0x8A7CDE2947684BA3ULL, 0xBC2CDB1A483B57F7ULL, 0x1CA96F505BA1027EULL, 0x73BA56FDECE4427FULL, 
            0x86BF48C6C752E563ULL, 0x3F9116DE8F2C8862ULL, 0x8E86C83B6DE6EA28ULL, 0x51E8FD62EAC4A2DFULL, 
            0x5BAA917706860AF1ULL, 0xD05538E583CD2792ULL, 0x0EA0F8513439021BULL, 0xFE04124CDE95AB72ULL, 
            0xB9FF27A80C979B22ULL, 0xD055F3EC174E263FULL, 0xC1AC415B644141E8ULL, 0x7EE3AFA6AA381C3DULL, 
            0x88585FE037CA7D6FULL, 0xC0A8A6007424709AULL, 0x34B4924974715025ULL, 0xA2AEC16541F881D5ULL
        },
        {
            0x8371EE6C594062A6ULL, 0x6A22C10248D18975ULL, 0xDA7FB859C0E575ABULL, 0x2B950FE4C680FE74ULL, 
            0x832CAEE1FF116C35ULL, 0xBFD5AA23D9B182A9ULL, 0x8DF2FD851679950CULL, 0xFE3A2B6ACFCC2C91ULL, 
            0x390349FB76EA07FFULL, 0x654440C301EFA6B1ULL, 0xFFFE3BFEC28ABDB9ULL, 0xD0F7DC81F574D1D5ULL, 
            0xFD72E6FB96214D3CULL, 0x5AE4AC4DFC7CBB11ULL, 0x25F484E10B16F48AULL, 0x293162C61B3FE2E1ULL, 
            0x5C7250AF21CF4C3CULL, 0xDCA73CEC7C8F6269ULL, 0x40C84E1D9E8EE261ULL, 0xB2983863A61807EAULL, 
            0x622FE07F1D3CC827ULL, 0x705BFB8013C3EC78ULL, 0xC95E994316E9D2DFULL, 0xD27568C8DB5C163BULL, 
            0xA099459A3A13D53DULL, 0xE878ED0848BF054CULL, 0x6E53CEB7B4772C83ULL, 0x3EC7DE31E500D446ULL, 
            0xE75D80CC8491662DULL, 0x9433447B71ACAB52ULL, 0x6C1C1F3108728B8FULL, 0x50FA39DE07BDB164ULL
        },
        {
            0xF4433C830C3C2CF0ULL, 0xADC24966355116DBULL, 0x7E1607ECEE5CC5E9ULL, 0x292FE49DA55003D9ULL, 
            0x0223183E1402EF35ULL, 0xDAB2CC8D4359C87CULL, 0xC9B25A8AD1EE6839ULL, 0xD6E9A6B4744806D5ULL, 
            0x7AFC876E294121EDULL, 0xEA0513CF891C7CFDULL, 0x9481148C4D6FFB66ULL, 0x84211CF0AFF27D75ULL, 
            0xCF1C6172E8A8044FULL, 0x92C0616960C227DDULL, 0xAABA95531F4CE46DULL, 0x7110F449E01C8C29ULL, 
            0x1882EC513D7EA116ULL, 0xA67C9D7351D3C39EULL, 0x44714A24B286365DULL, 0x259E0C0914C0B697ULL, 
            0x666A31533995521EULL, 0x757E70DC2F00BB64ULL, 0xECC337FC248E16B4ULL, 0xE63C5FFFA9A841C7ULL, 
            0x04E9405994E20E7EULL, 0xABABF49B1354D572ULL, 0xFCB18AF9F3D3AD52ULL, 0x3C19362BD686E98AULL, 
            0x042A81CEE05140FBULL, 0x25C78AF64420CE6CULL, 0x41BEAE961791DCE2ULL, 0xCA185FD9B8A8CB0AULL
        }
    },
    {
        {
            0xCC765BAB7F45C42DULL, 0xDD2C56C3BE100338ULL, 0xFDE09F3A79C2F73FULL, 0xCA0FEB49906102C3ULL, 
            0xD772A621E892FE4BULL, 0xDF68994AD96D9347ULL, 0x2A4047F814DB1DB5ULL, 0xE776CF8799F03BA6ULL, 
            0xB511BEDF9EF91097ULL, 0x931887F5934F9F97ULL, 0xC7CADB0907A600D2ULL, 0x302ED74D4BE69909ULL, 
            0xB63B208B1168EDDBULL, 0x05CE0F48564642FBULL, 0x523178C142FB40C3ULL, 0x9BCCD924EF9ECD8CULL, 
            0x9F411452CFB451A9ULL, 0xDF8027152CC35071ULL, 0x324642CF913D9219ULL, 0x62BC59B1D1AEB5ADULL, 
            0x99038A9BB3808BF9ULL, 0xEC3596B458B17D94ULL, 0xD29391B85166DF64ULL, 0x8BE33BD3B3BF6C27ULL, 
            0x6A88D68605411447ULL, 0x5D92B47A346C189FULL, 0x1CC1D7E65E21F295ULL, 0xBB883775342C38DDULL, 
            0xB289543BF57489DEULL, 0xB20584BD99C0B2B2ULL, 0x7AB30DC2D2099BCBULL, 0x947A4AE4DD5C2B24ULL
        },
        {
            0x3352B8C19183BEE3ULL, 0x634167A2C3391A7BULL, 0x11CC082F45D07612ULL, 0x9EABF3921B715795ULL, 
            0x3BA8CE3B34868673ULL, 0x1C1F866BE9446713ULL, 0x22C40809174DBFA5ULL, 0x14A945DA2EA6E760ULL, 
            0x49FC4090988973A3ULL, 0x0809608609EABF6AULL, 0xD448C5C629B6487BULL, 0x5D8CA9857E6EC42EULL, 
            0xF167C41F00CFCDFEULL, 0x09744ED804B76444ULL, 0x57EFCD5D9E6AD065ULL, 0xBEEA1752CBF7BF14ULL, 
            0xBF5BCCBB032167BBULL, 0x47F2E712B7B26BC5ULL, 0x9471CF7872C34E35ULL, 0x7C9AB3C97C838D16ULL, 
            0x6F0A7127B230CC82ULL, 0x47C456938463E49DULL, 0x785D74ED8A71DB97ULL, 0x102E319F87CAAF0FULL, 
            0x0DEFBEC3730C1B85ULL, 0xF1CCCB61D36747DFULL, 0x1DE436AEFB8708A7ULL, 0xBF8846A194034B0FULL, 
            0xB546FF956DFE77DEULL, 0x7A680F04C6D7FAA8ULL, 0xB4ED2749811CE9BCULL, 0x75E85381A5AA2DB4ULL
        },
        {
            0xC6C8258A074D1555ULL, 0x7ECFA4A40C005DE6ULL, 0x63601B8A03B0BDD2ULL, 0x5FEA81139435F9FCULL, 
            0x40AFBA2121741997ULL, 0x9E84BFCE19C0430FULL, 0x7F46CABCCA944473ULL, 0x2BEE0AC37AC16593ULL, 
            0x42317EC5FFD539C6ULL, 0x7B2587C56C08C6D0ULL, 0xE4E6C799D3B39E7DULL, 0x842798D6B9B27B6EULL, 
            0x2341D997550FAF1CULL, 0x9132E0FDA394E2AEULL, 0xE52FE0B8EDA62275ULL, 0xFCFF6EB7595A59F5ULL, 
            0xEA0B3AA2625350A9ULL, 0xBE43AAA2468F2076ULL, 0x6621B8636281A5D7ULL, 0x6C61F001AD6E6930ULL, 
            0xFC38253DD43A50A9ULL, 0x88F7E8BF21A93905ULL, 0x18E2CDB36466CCD7ULL, 0x34A8ABA1BDA20D2CULL, 
            0x60320AE7FF0BF884ULL, 0xA901744EA8071F55ULL, 0x3866CC27B03060DBULL, 0xCDA000FAF7E2C37CULL, 
            0xD046A69CCC26D44BULL, 0x950DF04E215D46CEULL, 0xF5FAF1670144E2D1ULL, 0x7714513095058503ULL
        },
        {
            0xC568747CC9EE7C26ULL, 0xCC8C14FD74C724E4ULL, 0xA982707A0CB1C8FDULL, 0x3C36EA2C543ADFB0ULL, 
            0x91A498F8D29DA8EAULL, 0x9C66BEC25C89D493ULL, 0xD73BCA0933A19B04ULL, 0x46A5A74C3E017754ULL, 
            0x602CA94970C803C1ULL, 0x6E521ABC1D0E489FULL, 0xB9CF786AC0675329ULL, 0xF69F6D88AA348830ULL, 
            0xDD8B43ED505BC3D0ULL, 0x988D899453A4925BULL, 0xC5203193E84C2072ULL, 0x6B5C2A2A97C719C9ULL, 
            0x48562E4CFD642428ULL, 0x964B1CF45EC45B69ULL, 0x0FA8A4663EB034C7ULL, 0x56EA84E8952FD459ULL, 
            0x563E4A4003F5DD31ULL, 0x9CE35ED4250E288AULL, 0xA1F08785953D8448ULL, 0xB8B7403C7B0134F9ULL, 
            0x179895346149759BULL, 0x8B93D48704108826ULL, 0x4B9F96425C0E6D5DULL, 0xB36F3633062FCC39ULL, 
            0x5CC5488669696C7CULL, 0xFB78DD1E7B670D4FULL, 0x9DF7B01433EA12FEULL, 0x7A5F308ECFBE45FDULL
        },
        {
            0xB61A93E038634D22ULL, 0xA82918854A046438ULL, 0x25AC0CC6E234035CULL, 0x47EB4BBC495A7A2EULL, 
            0x678E3B4649B77541ULL, 0xC314E238B5E140B2ULL, 0x9C39383621F07802ULL, 0x142B66E24197943DULL, 
            0x373C1341215DF214ULL, 0x320853C8E427092AULL, 0x2273BC494105B5D3ULL, 0x1EB7F6CD70509792ULL, 
            0xA575932A9E9AF9A0ULL, 0xDEA286F3FC9488B7ULL, 0x9565879639C571B0ULL, 0x253142D7B277830AULL, 
            0x429234ADFEE14306ULL, 0x523BED16A7E1F3A7ULL, 0x8DEE712083AE0164ULL, 0xED7905B51594FE8DULL, 
            0xA4778D18543D9959ULL, 0x5841B23AC1656BB3ULL, 0xC615DA3B3C00815CULL, 0xB3293B75A887D349ULL, 
            0x10164BC0F5179262ULL, 0x3BFA5BBC00E08E06ULL, 0x5AE0917E0DAAB64DULL, 0x1831BC48BCC54FEEULL, 
            0x7770E69AF9EE11A2ULL, 0xE320C5064A61340BULL, 0x185F01F9076A525FULL, 0x6FF49F829605CB7CULL
        },
        {
            0x7E14F9DAD89A9669ULL, 0xD6C738C4F6572E27ULL, 0x058A9929FB8CA6FAULL, 0xC0C2857F5626B489ULL, 
            0xA1C2C73ED7B4740CULL, 0x28CA6AFA3D350A55ULL, 0xAA86026480CA9C34ULL, 0x204CB1DE325B9AF4ULL, 
            0x1CF36D6EED8DB09DULL, 0x5AD04CE9D0BEAD0DULL, 0x87683D5ADAAA44C7ULL, 0xC823CBA3AEADB2BAULL, 
            0xB015576FC68475E7ULL, 0x2A69B392999DDD93ULL, 0xF2CA948DCDBB519EULL, 0xF67D6B23622FCC52ULL, 
            0x58F394E0BE20D0BBULL, 0x24FC1A331D5285EBULL, 0xAAA9F90D1FBD8650ULL, 0xF3898392383FDE94ULL, 
            0xFF31472D87049845ULL, 0x4292FEC7B5A2F1E7ULL, 0x4C493AF3E6A0007BULL, 0x8934EC93B66186B6ULL, 
            0xF2277E2F0D726EF8ULL, 0xCEA316950C76BCC3ULL, 0xA28E8605FA9F7BCBULL, 0x543C3B174FC32224ULL, 
            0x691BC804E5654FA9ULL, 0xEB0D8866315C9F2CULL, 0x39B3D61DC68EB3C5ULL, 0xBF80401AD9BD27B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kSeedConstants = {
    0x2BD0AF171BCCB72AULL,
    0x1BC1B26FB74C1B24ULL,
    0xD16C9C4F9A77272CULL,
    0x2BD0AF171BCCB72AULL,
    0x1BC1B26FB74C1B24ULL,
    0xD16C9C4F9A77272CULL,
    0x08BE41F8EED1017FULL,
    0x1A5A9AB016652BBFULL,
    0xAE,
    0x3A,
    0x5F,
    0xE2,
    0x25,
    0xEA,
    0xE8,
    0x02
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kTwistSalts = {
    {
        {
            0x38AD44CC91F36F5EULL, 0xE0E931694BCFE8DCULL, 0x826A34AA3E66A7EAULL, 0x02BD8F56067862E5ULL, 
            0x2F83A8F10ECF3675ULL, 0x04C7DE1B55111A4DULL, 0xE1405E6DD4402C32ULL, 0x1A3D5888BDDFAA80ULL, 
            0x24BFF9C93C0773E5ULL, 0xB871C3CF9ADD2F09ULL, 0xEDB900EA39C24124ULL, 0xC7AF329053A19B70ULL, 
            0xCCC223746E6D54D6ULL, 0x03A67F77A743C83FULL, 0xE15ED85DA1F7D4B4ULL, 0xC14A4C5B26E6A30FULL, 
            0x79A639DD8A0034C4ULL, 0xDB033E5C6BF704CEULL, 0x5D9E880AA18C1423ULL, 0xF618008AE5D4B51CULL, 
            0x02A9494A854F6F75ULL, 0x727AF4C2D425DB8DULL, 0xC6C1081CB9F5504DULL, 0xB9C4514EB6F81F3AULL, 
            0x083FA8FE00B54B0BULL, 0x7EE00E090D1657AAULL, 0xF27BA61975BD12C8ULL, 0x028CEC136F76DC2DULL, 
            0x218C0611CEB379CCULL, 0x2051BCD98E37C875ULL, 0x3E1E691727FC023DULL, 0xCFBBDE72C4F24962ULL
        },
        {
            0x3A45C5D02990D44CULL, 0x6CFC2AA8A107DF53ULL, 0x53AF1CABCA29A78CULL, 0x780EAB386578CBCBULL, 
            0x14C4FB35F4E19CD5ULL, 0xBDE92B34395A2B00ULL, 0x3927CBC6FC312C76ULL, 0x4C034694761C3648ULL, 
            0x3BDDB85E2827E696ULL, 0x79515B592C4C0511ULL, 0x40A9AF5F3EF168A2ULL, 0x30D7D09C31AE5147ULL, 
            0x771A5BAC804C32ACULL, 0x3DD6DE487439DED2ULL, 0xAD1DF19297F2E07BULL, 0x946D491BCE165E64ULL, 
            0x32A9BFECC187BDF5ULL, 0x9F8775526582DE88ULL, 0xE42C033FD164EDB6ULL, 0x76476305E1323BB0ULL, 
            0x887F12EB5D1E6A32ULL, 0xC4D28E0363CB7F4FULL, 0xDDB1F69B545AAFBFULL, 0xA1E94129BB071BDCULL, 
            0xD60CC15BBB212B6AULL, 0xFCB07EDD519FF72AULL, 0x10279C529AFFD699ULL, 0x316D883B85207B48ULL, 
            0x3F7FD3918720763AULL, 0x1AF4923029C8A270ULL, 0x0A567692243C89E3ULL, 0x0E261846BBB77DA1ULL
        },
        {
            0xFE01BD3E51F99D41ULL, 0xA1F2483E20942378ULL, 0xEC7648C2DD429C04ULL, 0x6046517B988B87E8ULL, 
            0x3BABAB274A930EA2ULL, 0x6B16C805E713EDBFULL, 0x3B4A6ED43BF6A2AFULL, 0xBCBFA5DB0C7E3250ULL, 
            0xE3982F8D11B97BD0ULL, 0x66123261015F0036ULL, 0x986013E10D587D13ULL, 0x90484FA7C3DE470BULL, 
            0x31FF30075FB757DBULL, 0xFB084D61EB3EC241ULL, 0x98ABA5F35F50C9F0ULL, 0x6DC22DC892DB2859ULL, 
            0xF41C248E7F95C26DULL, 0xB6645C5CFBCA3F5CULL, 0xB15963ED407592B8ULL, 0xEFB90B16B6F7EDE0ULL, 
            0xE257B8D02079096FULL, 0xF5C30A2500DDFB7BULL, 0x3468A3EC1EC6D46AULL, 0x95E1726CFAA0F300ULL, 
            0x0E9347969995E381ULL, 0xCEEBE3C1E95C3C39ULL, 0xF2F5973A7B677275ULL, 0x3C8BC893BE00A35CULL, 
            0xDFF1C5BC1998E04CULL, 0x37A40D4201648D22ULL, 0xCDF7428E56ECEAA0ULL, 0x04D97407B17B1EE7ULL
        },
        {
            0x42D59965931BAAEBULL, 0x83EBD4ACFE12B46FULL, 0x7CAFCA9646D0F691ULL, 0x01B8E318F45BAE1DULL, 
            0xB113F0C5493BFFE2ULL, 0xA6F2AD7932957069ULL, 0xDECFA35D1293EF0CULL, 0x8BC27C4BBFA1E76AULL, 
            0xC15D3F4130978501ULL, 0x82CC4290420F5DF4ULL, 0x6FC20C70A21100D6ULL, 0x27E2D8AE48F28353ULL, 
            0xF25B0DF7E6B9E968ULL, 0x9A1D90DC494CC177ULL, 0x22BD4811F8DB41D4ULL, 0xB249E525284260D5ULL, 
            0xBC04BE52F2A20659ULL, 0x89250E493EA9859FULL, 0x3B45FB128E7CBC64ULL, 0xED4374B8D628CD13ULL, 
            0x7774C706DC20CA9BULL, 0x0B8D2F32D831E5DEULL, 0x797A53460971121CULL, 0xF257CFD8EFDCFBA7ULL, 
            0x458C567ED4411027ULL, 0x5E39FC8E442820ECULL, 0xD4E6378E2F2E3ACCULL, 0xFF97970D21250A15ULL, 
            0x57896B94926E9FB9ULL, 0x18BBFA28FDB55955ULL, 0x14A011F23981BADDULL, 0x92BCB71A3FD8207FULL
        },
        {
            0x9B5297133BB229ACULL, 0xCBB278632745B253ULL, 0x0480B065CD505604ULL, 0xCE94F3F81EE81483ULL, 
            0x5980B8CA3E10550BULL, 0xDEF7CB8358ED7865ULL, 0x046C8EFA99B7123BULL, 0x07721EC213D9A669ULL, 
            0x02669E83CB4C576EULL, 0xFDCB6223CF9DAF06ULL, 0x7B9D0B708C2C2F1CULL, 0x8E4B4850725D8CF7ULL, 
            0x95BDAD404E977DA7ULL, 0xE93D4BB60725BD5AULL, 0xDD4AC535CC799B04ULL, 0xDEFFB3C41A456BE6ULL, 
            0xBF8152ED1FB80A65ULL, 0x69001BEA2A4912C9ULL, 0x4B8D3679B9D56E4FULL, 0xA79C5BC495F878C1ULL, 
            0xFCBE5507F5FC42BEULL, 0x9243B57A74053ECCULL, 0x87FCD1F9AE707B3AULL, 0xBF4FF1D31CCECFC9ULL, 
            0x11AEA3C77D38BBBFULL, 0xF56E74C7360F3102ULL, 0x27020F955AEA5B4FULL, 0x23C83E86C9159D43ULL, 
            0x151E9CEEDB88D5D1ULL, 0xF697C5D4DA836C30ULL, 0x768C1142A4D5080DULL, 0x9D40408442858F63ULL
        },
        {
            0xE1D93457506F9725ULL, 0xD8D547C368412304ULL, 0x7BEC814C6D15783CULL, 0x16ACAB8E2ADEF300ULL, 
            0xE293AD7A6360E296ULL, 0x80FD9461F843BB51ULL, 0xF074E437AD58C4F8ULL, 0x6E3313CA3926D291ULL, 
            0xF0E4B1E435E1132DULL, 0x977941D704A6746CULL, 0xD121A31A518A0B42ULL, 0x122573BDCDF4D4D1ULL, 
            0xB42A2F9BE9C27228ULL, 0xD08C3123186D53B5ULL, 0x44C9964113391C7FULL, 0x96EC2BD693CE5D2DULL, 
            0x50055E243E8ACFFFULL, 0xDC60F7314F4326B3ULL, 0xAFC1876E57258479ULL, 0xB7F437805256721BULL, 
            0x3A205EC72F0F0FFAULL, 0x6BCC8E7ADB9BFB78ULL, 0x66E53283ED21B30CULL, 0x66F866DCCD7E85ABULL, 
            0x29995B25665F1511ULL, 0x38DEE2478F8E341BULL, 0x90B3D26C2E89C021ULL, 0x29845B30C915741EULL, 
            0xE3246E61822EB950ULL, 0x4B3FBE8C82696E16ULL, 0xA2BBB890751B55DFULL, 0xF1ADDC55ED9F809DULL
        }
    },
    {
        {
            0xE29B93CAFC912EA6ULL, 0x094C22161B6EF5E4ULL, 0xA2C02BA633BAA53FULL, 0xF93735313449EB40ULL, 
            0x71340349F2A25D52ULL, 0x91809982A5FFD18DULL, 0x4EC5B2F1E5E044A3ULL, 0xC19DFA2A93286259ULL, 
            0x1206925E7D9E9BF0ULL, 0x0A402F498622D416ULL, 0xBCFA0E67E5CE2824ULL, 0x125162B171428D02ULL, 
            0xA390132294C369B7ULL, 0xF51B25241379CADEULL, 0x2D6F02AAE75500AFULL, 0xE64EFBEAADA356EAULL, 
            0x8E1097AAA350930CULL, 0x29A14A7D0D94F2EEULL, 0x9EE723AA809C43EDULL, 0xAD77CA858F6CE129ULL, 
            0x99CEC723B392FCE1ULL, 0x057F48DDA63CD167ULL, 0xB56E96BE46043B60ULL, 0x19D67F8509CF9637ULL, 
            0x0E4C7170717EB9A0ULL, 0x66857D706A940485ULL, 0xEFE0EA4F1989AFAFULL, 0x29BDF7158FE1D4FFULL, 
            0x0ED24BB01E1BE359ULL, 0xEFA4DF4563EB79D9ULL, 0x354D69720FA36A82ULL, 0xF6193EB6302CC3C8ULL
        },
        {
            0x6546A8EF41B6396CULL, 0xBDE395DA7416A83BULL, 0x331D64F76F5B5450ULL, 0x1D8F623EAF5D8650ULL, 
            0xDA492AD06B1B6E99ULL, 0xF4D55009D607EA5BULL, 0x4A524474F192936EULL, 0xBC7FCC12A76E298EULL, 
            0x7838D1A7AFE78B05ULL, 0x4978C31BF9E12374ULL, 0x686D2E784E7EFE4EULL, 0xDBEBA0972B7A2258ULL, 
            0xAD25C91D20C6404EULL, 0x7E22C980CDC3F253ULL, 0x8CC2FFA0C79B0D0EULL, 0x9E769283219B65ECULL, 
            0xC278B0A23ED4831FULL, 0xA8C106DBBA97D815ULL, 0x9CE888F163DF8942ULL, 0x9EBC39078C80B9FAULL, 
            0x98781747DB45B57FULL, 0x8596D190EA41F99BULL, 0x2A25FAA862A99EAEULL, 0x124D13F14BD692D8ULL, 
            0x995E90239E723166ULL, 0x21054F1C886637C9ULL, 0xCA29467B923DFB60ULL, 0x2E5BBC19F19C8ACAULL, 
            0x61F88AD11AFF8F94ULL, 0xF90DDF6D4691ED83ULL, 0xCC2DCA3F12C630CEULL, 0x3EE5E2E1092DCA85ULL
        },
        {
            0x7BA0A78EF0FF31F1ULL, 0x17A090A11B3AED9CULL, 0x0F6B33D5DBB36B89ULL, 0x908C4806D35FDE4CULL, 
            0x5ADA1C1F00DDC66DULL, 0xADE95BAF2DAD3982ULL, 0xF42049C7868E6EE4ULL, 0xCCAE2BCD59F6AF75ULL, 
            0x3889E0B18A9C1BE1ULL, 0xD5F432CD11C6AD6FULL, 0x6CF4D4037FD4D7D2ULL, 0xC227D23871DC7569ULL, 
            0x96D3E0503BA2B6BEULL, 0x01BB8392D235F1C3ULL, 0xEDDA274598B78D2BULL, 0xA44E6B2D481F2B27ULL, 
            0xA50E9A5BF539D791ULL, 0x19B6A50E30CDF9F9ULL, 0x21AE178781EA1CDDULL, 0x65B75E68D84646E7ULL, 
            0x9D40ABA56D16912FULL, 0xA84461517C3280E2ULL, 0x70B682E335B652D4ULL, 0xED0BFC0F8A972700ULL, 
            0xA0A6D4F4D0D5F9D7ULL, 0xC80F88C54126A726ULL, 0x8ED97D80AD00CA24ULL, 0x790563EC802E11B4ULL, 
            0x556A66A8D448BDB8ULL, 0xC12106C974B27FEAULL, 0x462854CFE044976FULL, 0xC224D1166F8D1230ULL
        },
        {
            0x2CA7C263E5DA196BULL, 0xD0F76B263A9AD1C4ULL, 0x626A2DB683508922ULL, 0x07A4488974613766ULL, 
            0x6E549C75E0312B7EULL, 0x9107D3D16E0E3BDAULL, 0x7ADCDAA40F7646CDULL, 0x28FFED013227F5B2ULL, 
            0x4F818FA074A1218AULL, 0x6492D949864FDF6EULL, 0x81F648385ACB0CC3ULL, 0xFBAF657032B8E63BULL, 
            0xAD005D6074870B69ULL, 0xAC6A9058C9257B60ULL, 0x955D0BB172A16830ULL, 0xDB94DBF5C130095DULL, 
            0x36C2B148A09CF020ULL, 0xCFC7DC96E0723FB0ULL, 0x1230150A7FE2B804ULL, 0x0086FF10935E8858ULL, 
            0x93A54EAD038EA8F5ULL, 0x75A5EC2D7CEB0E39ULL, 0xA701EA3574EBBEB0ULL, 0x3685ED9BFE121F81ULL, 
            0x9EE1E104B487AECBULL, 0x1D5ECD1C12ADB532ULL, 0xEF9789BA76C97481ULL, 0xE558115BD019DA92ULL, 
            0x8A6D21923192CA07ULL, 0xB413DA84FB696701ULL, 0x3540589D83D900B3ULL, 0x97DC9A267AAC36D2ULL
        },
        {
            0x5C2F37E97319DDA6ULL, 0x6C91AB85626937C5ULL, 0x11FEB0AFCBC3E451ULL, 0x944D546FFB6C7D18ULL, 
            0xB46193E2146B0593ULL, 0x64DAFEB5AEDD54FCULL, 0xE67243115A672147ULL, 0xD9DC50ABD776F2C9ULL, 
            0x6ACF25A4B279580BULL, 0xFF2D0224AAAA2FB0ULL, 0xE5EADAF22E657418ULL, 0x7658FAE357B42EB5ULL, 
            0xDA54AD7ADA6158CEULL, 0xCCFDC4A3E64F6F3EULL, 0x472E98804BF3769FULL, 0x10F86AA5077C9840ULL, 
            0x8EAA396141DA60ABULL, 0x4201E3F080C7A01AULL, 0xB01C156DB54D22D6ULL, 0xF4262482ED85CFE4ULL, 
            0x3BA43E74B3AD07CEULL, 0xC60EA020A820452CULL, 0x09E32CEF0AB3BB2CULL, 0xC0C52C3C58516015ULL, 
            0x9AF4331F4F26660AULL, 0x3C15445A0CEF9A24ULL, 0xE8AEC85DC7FC2E4EULL, 0x804934A99D29AF67ULL, 
            0x8368882439040ABDULL, 0x40735DCECD3CB5F0ULL, 0x88EE08FA69AE2BF2ULL, 0xCF7A89271269200EULL
        },
        {
            0x544B0F92635D6116ULL, 0x02EC3F1C3473A59EULL, 0x8789906557548094ULL, 0x1C331B455921FA26ULL, 
            0xE89D69C7C466AE76ULL, 0x5281A3F232CE13D0ULL, 0x018E6C6ACCB92F4DULL, 0x6C449C911BE76251ULL, 
            0x0F9D42AE06DB35C0ULL, 0x489B2B8EB0C5D2D2ULL, 0xA595D6F63071B293ULL, 0x646F0525207A7126ULL, 
            0xC6E5A1F410BFA05AULL, 0xCCFB65C44AA8B44FULL, 0xD71E35AA72CC7384ULL, 0x22CA5C7F8AF5C0F9ULL, 
            0x621136B3CF978234ULL, 0xD7783E66642E62AFULL, 0x6DBE5A954F7A38C4ULL, 0x3A34A291341B3095ULL, 
            0x3B5A1A023ACB1863ULL, 0x579619C9D3C62E64ULL, 0xFDEEE895459A509EULL, 0x7DA02BBAFFD52A59ULL, 
            0x508123E0488DB67FULL, 0xC71584ED0501525FULL, 0x28BA4F5306C26327ULL, 0x05565A30F145673FULL, 
            0x0255A5D1AD4A6309ULL, 0x417B124EA1C718B8ULL, 0x7721BCA698A7754CULL, 0xE0463807D99F2CB9ULL
        }
    },
    {
        {
            0x4D5F06F973407219ULL, 0x7C62930A8C17B68AULL, 0xCFAA476008F3665CULL, 0x1364A775707D5D03ULL, 
            0xD6C473AEC84E0497ULL, 0xCA0D8103353B0FE8ULL, 0x63BD0A24ABC27446ULL, 0x621A7A2CB0175DAAULL, 
            0xDFB583900080D85DULL, 0xCDD1149B6E65487BULL, 0x04BF42A94F837BC5ULL, 0xB879D0BD14C5E206ULL, 
            0x4B19613E21B3CD6EULL, 0x20A0E7E975995D50ULL, 0xE2B0ACBA1694D3D1ULL, 0xFA52FEFE1EF43D0DULL, 
            0xF98BF449203650CAULL, 0x1BDCCB17ECFF89C8ULL, 0x1246FFBFEBDAFCFBULL, 0xA27EBED26E4221F3ULL, 
            0xCF11A51CD11B12A4ULL, 0x96D0F8C7907A9BFAULL, 0xE4BF47088999DCDCULL, 0x83B5E00B95E43B63ULL, 
            0xD62714656C963B07ULL, 0xC7D171EF512649D4ULL, 0x51AF1228AC53A0F8ULL, 0x48E228D5DF31BB14ULL, 
            0xF432AF9311BFC207ULL, 0x380811BD4C12CBCFULL, 0x897E2150A2448197ULL, 0xDF6B4E79A147CB7EULL
        },
        {
            0xAC6D255A91B62112ULL, 0x4952FBA0C0A283C0ULL, 0xFD7C1513797D9DD4ULL, 0x71B628F1DDF7CC75ULL, 
            0x1045210F35BF8224ULL, 0x1308340A3F8EB414ULL, 0x19C3007C6937B236ULL, 0x1CABF38D595908B7ULL, 
            0x2078132A9FBD56E3ULL, 0x05A52755BA39843CULL, 0xEC68353BAA43D9AFULL, 0x41ED87A538A2A5A2ULL, 
            0xF6C25C3B78EBC24FULL, 0xB9AE9E021349A0F6ULL, 0x8C08C0DA487F790DULL, 0x623226BC8BA76212ULL, 
            0xFB05624F98035D02ULL, 0x8CE36A10E069DC0BULL, 0xC75A0C6956BDE29FULL, 0xB25512D50B8E7FB9ULL, 
            0x29E7EAC2FADF2ED0ULL, 0x377CF8997E584F46ULL, 0x8A04200EBE48F78EULL, 0xCCA22EADEFCC6E82ULL, 
            0xFCDBD185CAA5863FULL, 0xF117D0E3FDB7CC84ULL, 0x4EB64A432386A233ULL, 0xD5F8AA9901901168ULL, 
            0xF89B4FC1FE5FA9CEULL, 0x342067CEDDCEAC00ULL, 0xD96AC0BFBA72474AULL, 0x39F9D239C05C73DFULL
        },
        {
            0x9008B53F32CE9EA4ULL, 0x59AA98580D60E2A3ULL, 0x2E7927FD7EF44E6AULL, 0xCA04DACD07A255DBULL, 
            0xAE15BB52267A8A1BULL, 0xBB84B92EB5623943ULL, 0xE60E2EC533FA9964ULL, 0x37FE48EE5F70A530ULL, 
            0x874139ABF5F953D9ULL, 0x84EE1F291E4FAC15ULL, 0x70CE66AF12E8CA59ULL, 0x3FFF5D3405540016ULL, 
            0x0D4EDC0EE7C5677DULL, 0x55D4F1C7F925AE31ULL, 0x58336220FF3DCEEDULL, 0x0FA72D3896B69616ULL, 
            0xB61315F3DE451DE4ULL, 0xE071DFB236B5C545ULL, 0x323B45A3AE0347F4ULL, 0x6D01D04FFFBCEC15ULL, 
            0xD2BCF27927BCDF98ULL, 0xD0F4869734813DC1ULL, 0x3C40B6AB1BB31D7BULL, 0x02AD8CDD54A4A820ULL, 
            0xFF4E6B62A8C0B5DCULL, 0xA9C0919D8E2F7F50ULL, 0xCFDD7875371992D2ULL, 0x28B2B7DCB19217E2ULL, 
            0x51810EC41481C7B8ULL, 0xC84D349AE89DB627ULL, 0x3B8186CB5F99872BULL, 0x36606251E2A6C1E2ULL
        },
        {
            0xDC55ADDF25A88A21ULL, 0x427B98D85227C95FULL, 0x44728E5A794D172DULL, 0x610A744C4BA54BE8ULL, 
            0x448AD764F7F8D3CBULL, 0x39D8F30E3CE11658ULL, 0x6D9E87B8EA408E41ULL, 0xBC1164D0DD4C8AE3ULL, 
            0x57A25024A43D12B4ULL, 0x79858A6F7D093504ULL, 0xE193052D8C1EA04AULL, 0x3D32F98171FC372EULL, 
            0xEFF2B9551F32BA7BULL, 0xD28DAC0C4325E149ULL, 0x4AED8AABCF573644ULL, 0x362193DB3029E54BULL, 
            0x6BB638E8C2BDB83BULL, 0x198BE9D0F2BBF3CEULL, 0x5839FA2F99B06B82ULL, 0xE0ED75EE6C173BC5ULL, 
            0xC7903BBC4DAC6101ULL, 0xE4F47E2818FA971CULL, 0x26A87963EADF1258ULL, 0x266BF25238A697E2ULL, 
            0xE8A80EBB3753E2CFULL, 0x928240CED5E75C6EULL, 0xC2F652FD49ED66D2ULL, 0xF0CBA63C24215475ULL, 
            0xA6BBB6E6670C6AB8ULL, 0xE3930F02A18B0F2DULL, 0x0659626D24A53EAEULL, 0xD865D2B700690546ULL
        },
        {
            0xA398DEFA1508BE93ULL, 0xC94BA9BFA6E4B046ULL, 0xCF8DE155788B181EULL, 0xBF537C1C5C4076F3ULL, 
            0x12E0D6A6FB9F757AULL, 0x1C5424036AFA16FEULL, 0xF0658518D1C669BDULL, 0xCC46AE0A3FE2A5E3ULL, 
            0x11935312012A3E0EULL, 0x4EA45162392B7018ULL, 0xD0DB7790AA728FBAULL, 0x5758DEABE5F21FC8ULL, 
            0xEF21C5C550FCE60CULL, 0x01A3E4E9F3E769B0ULL, 0xE8BDB44DF22F095FULL, 0xB6B85912FD367D29ULL, 
            0x4F3EE12D9DEF28EBULL, 0x331D3AF8C6798660ULL, 0xF6178FC5EE4F7E2DULL, 0xF7D99E0EA476F784ULL, 
            0x9AD96B9BC083ECDFULL, 0x5D30FA6515BEF193ULL, 0x6873C62FABCBCFFAULL, 0x9A4209C719B549EEULL, 
            0x5BC9D442B4FCB642ULL, 0x187F7CA05B2D4195ULL, 0x5B4B6ECE5BADAAD9ULL, 0x642E8CF6846C787FULL, 
            0x887A0B2D77494CF3ULL, 0x7359E84CE5134F2FULL, 0x9D2C5A059CCE67A3ULL, 0x5E6619C5A3094258ULL
        },
        {
            0x32111D4CBEB3486AULL, 0xEA067F28D9C76993ULL, 0xCE40C0B5A4452849ULL, 0xD4C2B016C931F91BULL, 
            0x503B53ADD669BDF8ULL, 0x954C84F4A434D66FULL, 0x06F712ABA4FAF17AULL, 0xD9D5B8D0ACD1174AULL, 
            0xF4EDA6951E2B1842ULL, 0xA73550FEE168DD65ULL, 0x9E2CD5A0C2E690EAULL, 0x677C503722AA417EULL, 
            0x2A635F991C5961C8ULL, 0xFA54FB86A1B0BB25ULL, 0x43EE2CD04CF1A299ULL, 0x341625F9E000C7B1ULL, 
            0xB70E40A8EBD33F81ULL, 0xFE9A39FCB221A56BULL, 0x19DB536A5E4F4D19ULL, 0x527AF98C48445FBBULL, 
            0x28E55F0719BCBE8BULL, 0xD911504B0DE01981ULL, 0xD83E832ED0D6E7E1ULL, 0x7E403B3813E00BFCULL, 
            0x1F1FECE51E2A6850ULL, 0x5C4B8AC4F5B0275DULL, 0x76818DB3BE8DEEC8ULL, 0xBAAF2565C28AF062ULL, 
            0xF8AA0EFE0587B1EBULL, 0xD7E08B58C492995EULL, 0xEC0D9715AA06010DULL, 0x447EAE5ADCA9F767ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kTwistConstants = {
    0x8BC245CDDD1B87E9ULL,
    0x8A0FFEE23DC3CAF8ULL,
    0x3127496CA6B7085CULL,
    0x8BC245CDDD1B87E9ULL,
    0x8A0FFEE23DC3CAF8ULL,
    0x3127496CA6B7085CULL,
    0xE8903C0D62EDF706ULL,
    0x07BFFB067A1AA024ULL,
    0x1A,
    0x2B,
    0xD2,
    0x07,
    0xE5,
    0x2F,
    0xF7,
    0x78
};

