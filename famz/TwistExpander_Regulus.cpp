#include "TwistExpander_Regulus.hpp"
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

TwistExpander_Regulus::TwistExpander_Regulus()
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

void TwistExpander_Regulus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Regulus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC7625E5BF3F2D6D9ULL;
    std::uint64_t aIngress = 0xDB47BBCC0F36759EULL;
    std::uint64_t aCarry = 0x876A5939FBDD330DULL;

    std::uint64_t aWandererA = 0xE80D5B58D673B34EULL;
    std::uint64_t aWandererB = 0x8C5B4D3AEE83DD26ULL;
    std::uint64_t aWandererC = 0xFF36A31C1EEAEE03ULL;
    std::uint64_t aWandererD = 0xCDCB6C52CC1205BEULL;
    std::uint64_t aWandererE = 0x993A1CDBC234CB99ULL;
    std::uint64_t aWandererF = 0xFE118A19DCF7092FULL;
    std::uint64_t aWandererG = 0xF185E809D5CE6C85ULL;
    std::uint64_t aWandererH = 0x85803D851F47EEC5ULL;
    std::uint64_t aWandererI = 0xA4FFC1AF267E99EEULL;
    std::uint64_t aWandererJ = 0xCC0E49EB17F6A51BULL;
    std::uint64_t aWandererK = 0xF4638078E2238953ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x9D5D08F53A9B3DF2ULL;
    aIngress = 0xF234991EA7A00BABULL;
    aCarry = 0x9762A13F7F715B13ULL;
    aWandererA = 0xF1DAFCF3300F2B77ULL;
    aWandererB = 0xD4E69B72EBD5A0F3ULL;
    aWandererC = 0x8FE48A2F6C1F5A37ULL;
    aWandererD = 0xDFC19DE790A69A45ULL;
    aWandererE = 0xA84E9B85C3B4FF18ULL;
    aWandererF = 0xC019F884820B6C11ULL;
    aWandererG = 0xED73E1A036C35EEDULL;
    aWandererH = 0xE4D0612BDAC61309ULL;
    aWandererI = 0xC23EAC9B9906E681ULL;
    aWandererJ = 0x81CCB7DE501A3364ULL;
    aWandererK = 0xC143A34F393C19E2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x99E22E0CBC82B322ULL;
    aIngress = 0xE49C85AE5F3B1BE5ULL;
    aCarry = 0xDBE7E6B79402124CULL;
    aWandererA = 0x8B54DA7F3E438987ULL;
    aWandererB = 0xF4F1D8F4FDDBB4B6ULL;
    aWandererC = 0xB8122B03BBFCF557ULL;
    aWandererD = 0xA3C8EF9CD6901429ULL;
    aWandererE = 0x9D317FB2826237F8ULL;
    aWandererF = 0xC17D25B9B32BC6ADULL;
    aWandererG = 0x974906EBE2F84F58ULL;
    aWandererH = 0xCE6BCF1D091F85F0ULL;
    aWandererI = 0xAAA52108C6D1DE03ULL;
    aWandererJ = 0xF825CBA235535ACDULL;
    aWandererK = 0x9A79947F2E36EEE2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x92E80EAAF1EA1F29ULL;
    aIngress = 0xD57F26C271A7F683ULL;
    aCarry = 0xBB206D9D3C132C89ULL;
    aWandererA = 0xF5A1080E3D44AE1CULL;
    aWandererB = 0x9FB60A6B9AD08FE7ULL;
    aWandererC = 0xB750A2FBBE1FECEEULL;
    aWandererD = 0x8D062069520F09ACULL;
    aWandererE = 0xDF78705B8EE7AB0EULL;
    aWandererF = 0xF21C952855F3D300ULL;
    aWandererG = 0xD918979E9CED2422ULL;
    aWandererH = 0xD80326308D60279EULL;
    aWandererI = 0xAD3A6D597C5B475FULL;
    aWandererJ = 0x8C87F504DDF7611AULL;
    aWandererK = 0xDCACED8FAF58A022ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x9D0DC90E398EA900ULL;
    aIngress = 0xBFF684DEB2553141ULL;
    aCarry = 0xB8417CF737115847ULL;
    aWandererA = 0xE1B777A2EDD94D15ULL;
    aWandererB = 0x84F67A1670B9BD28ULL;
    aWandererC = 0xEA73E30EF95109E7ULL;
    aWandererD = 0xD4A4E848A9B98E91ULL;
    aWandererE = 0xDDE8A849774ED289ULL;
    aWandererF = 0xD3B06008FDE3C4B6ULL;
    aWandererG = 0xD05D9965A22E2F72ULL;
    aWandererH = 0xEA8C04A923A7E7D4ULL;
    aWandererI = 0x9CB9A7BB9F1C90AAULL;
    aWandererJ = 0xC625DBD856ABBF43ULL;
    aWandererK = 0xF7CA7046EADE27C7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xE6CC6227DA62AFDBULL;
    aIngress = 0x85893E4C2E44F6B4ULL;
    aCarry = 0x8124343AF5D3ABCDULL;
    aWandererA = 0x970B802183768475ULL;
    aWandererB = 0xB7F8B3E8F2DA43E3ULL;
    aWandererC = 0xCCC59961F18D5A2FULL;
    aWandererD = 0xB89BB1F67B2E76E2ULL;
    aWandererE = 0xE849491A368E4777ULL;
    aWandererF = 0xB1B293D2D6293744ULL;
    aWandererG = 0xDC71A5FB02110CBEULL;
    aWandererH = 0xAAC60017A3015F5DULL;
    aWandererI = 0xE36F2AF0F70EB70AULL;
    aWandererJ = 0xC09A9B18E2FC9B22ULL;
    aWandererK = 0xE43DE7F6BB445109ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x9590A873C8917B88ULL;
    aIngress = 0xC65D36EFFD478E8EULL;
    aCarry = 0x97A9E22C74D96A56ULL;
    aWandererA = 0xB93D2283FC16CC33ULL;
    aWandererB = 0xEA9608586C51ED69ULL;
    aWandererC = 0xBFC38490B9F03592ULL;
    aWandererD = 0x9D45522621C08B2CULL;
    aWandererE = 0xB8267B16F545436FULL;
    aWandererF = 0xBBD1EA8F96CA80A2ULL;
    aWandererG = 0xBE8A8663B4116EDCULL;
    aWandererH = 0x95F746EC9EEFC7DEULL;
    aWandererI = 0xFB5716EDA4A7D856ULL;
    aWandererJ = 0xE2D79262654A60BBULL;
    aWandererK = 0xB18BC9540D883039ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE2EBB31DBE8FD288ULL;
    aIngress = 0xA88A2E77D44C1472ULL;
    aCarry = 0xC54DDAA39019E0A3ULL;
    aWandererA = 0x9176A5831B821CDEULL;
    aWandererB = 0xCF47702CD4516715ULL;
    aWandererC = 0x9FAD6BAAFCCABDD8ULL;
    aWandererD = 0x94E849B65AF0E431ULL;
    aWandererE = 0xD764E9963CFD6BD4ULL;
    aWandererF = 0xEA8BD3178A50E8F2ULL;
    aWandererG = 0xC3EBDDA94B71BD29ULL;
    aWandererH = 0xE7EF0EBE37697980ULL;
    aWandererI = 0xE57CBBFA6157B346ULL;
    aWandererJ = 0xBF13C531FC332143ULL;
    aWandererK = 0xA1FBBE5E7A52E3AFULL;
    //
    TwistExpander_Regulus_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Regulus_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Regulus_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Regulus_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Regulus_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Regulus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCDAF493C3C2C9AD7ULL; std::uint64_t aIngress = 0xA09C67BDF9938CF3ULL; std::uint64_t aCarry = 0xFB9E06A76BEA7ED8ULL;

    std::uint64_t aWandererA = 0x915FE0815E15EA83ULL; std::uint64_t aWandererB = 0x8C9265DF504DC46CULL; std::uint64_t aWandererC = 0xD52C10B00ACF7D47ULL; std::uint64_t aWandererD = 0xB9E9DDCD703E5DF4ULL;
    std::uint64_t aWandererE = 0x863A16757C07CBC7ULL; std::uint64_t aWandererF = 0xE9974D3B43362322ULL; std::uint64_t aWandererG = 0x8E97FED8C750C7F6ULL; std::uint64_t aWandererH = 0x918D56BDE2B09E30ULL;
    std::uint64_t aWandererI = 0xCF13D1DAEDC4C812ULL; std::uint64_t aWandererJ = 0xB89C52F91B2BAB55ULL; std::uint64_t aWandererK = 0xE582E43360CDE217ULL;

    // [twist]
        aPrevious = 0xB003EC3741C29469ULL;
        aCarry = 0xD700C01D4F661633ULL;
        aWandererA = 0x87E5F3D1E0C6DDC9ULL;
        aWandererB = 0xEC94E4C760870345ULL;
        aWandererC = 0x9D74AEFF0CBDCC09ULL;
        aWandererD = 0xCAC66036681F86E7ULL;
        aWandererE = 0xDBFAC1AB8A97CE0FULL;
        aWandererF = 0xA1282C859A74BEFBULL;
        aWandererG = 0xA40193D72CCE3019ULL;
        aWandererH = 0xBDD32B01D20EECEAULL;
        aWandererI = 0xA7DEE5AA23DC0CA4ULL;
        aWandererJ = 0xEB0CB5474F85F8B0ULL;
        aWandererK = 0xD5E56F31FA782811ULL;
    TwistExpander_Regulus_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Regulus_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Regulus_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Regulus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Regulus_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Regulus_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Regulus_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Regulus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Regulus_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Regulus_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Regulus_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Regulus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 27 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 13912
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 27 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 13878
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 835U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Regulus::kKeyRotateASalts = {
    {
        {
            0x2D430D8F6DF9EAA8ULL, 0xDF8364ADA898CB3DULL, 0xA333CF5DEC279BDAULL, 0x9E2F76849ACF1E94ULL, 
            0x63082F2C8F8FBCD4ULL, 0x95C2C7D9EE465CF0ULL, 0xC0D6E64EA6935BE5ULL, 0xC244313D3291BB61ULL, 
            0x534AD766E2866B57ULL, 0xF2E1EE1ACFBC0103ULL, 0x9D2D72862C0782AEULL, 0x1AA98A8C463F690BULL, 
            0x2D9A94B46BAF55A5ULL, 0x7FA85BBF1043853EULL, 0xC160171715B18951ULL, 0x408D8BE6C2D83FB9ULL, 
            0xB900240AB5562074ULL, 0xF2A6D18CE9CA5FD0ULL, 0x47E122FE0203DDEAULL, 0x2A0BAB2CF176ED00ULL, 
            0xD6A55D252C4836CFULL, 0x013BE90134A23D49ULL, 0x2574141DE9D6C044ULL, 0x7B385D73A5EB869EULL, 
            0x8A68CE7A633B65C4ULL, 0xF354430B04C3A59FULL, 0xFC5C45ED43225755ULL, 0x80DA785A1FFD0891ULL, 
            0xFE3B2627B98AD6E2ULL, 0x0CC1D98C05E0AC2FULL, 0xADA7C0DF269FB09AULL, 0x95E575B24477BF7EULL
        },
        {
            0x5C27D9681C85C2C2ULL, 0x66D145636E32CEE1ULL, 0xE542409F449E3709ULL, 0xC66211B913A2D206ULL, 
            0x99E077403D6398BDULL, 0x3528A72BA1330CD1ULL, 0x6FBF9EB3BA2FDD7EULL, 0x2C79BA24D55238A8ULL, 
            0xB13C4A6311C9C620ULL, 0xD496C08C9B0A259BULL, 0x94702A9DFB4EB4DAULL, 0x65040242587EB49BULL, 
            0xAF6037045CDA5D68ULL, 0x0A9EFE0BD1F95B44ULL, 0x3AFC7182967547F0ULL, 0x04902A15D9D2A17BULL, 
            0x139A0C6459F62BCEULL, 0xD6BBB377563D432CULL, 0xA74EC5373159A061ULL, 0xD66882E9E0B70970ULL, 
            0x1EF0E1DDA8342358ULL, 0xA84F4F5B4E625605ULL, 0x0898BC38C58FDE93ULL, 0x8BBDA725C264A0D0ULL, 
            0x0A243103E23AAA9EULL, 0x7BF55322403CBA27ULL, 0x762FC9DA5190E859ULL, 0x8196FBE1765CB5C0ULL, 
            0xA41389EC2DB26761ULL, 0x7049D834AD629227ULL, 0xB7B8788696B3C89DULL, 0xE6A4C1128A833DC4ULL
        },
        {
            0xA1A7321334CA9DF6ULL, 0x234BA8E4E575CFF2ULL, 0xACFD4333F87BA78FULL, 0x55640F67C4B40D58ULL, 
            0x739E59EE4E72335AULL, 0xECE7438F7FD90E37ULL, 0x8EDB83E915D2923EULL, 0x088CA92601DAE9C8ULL, 
            0xD430C5B13EE501B1ULL, 0xE3D3FA93F31935BDULL, 0x3BA47544A53D331BULL, 0x3350F7C48ABA57A7ULL, 
            0xED702B39B8B9CA26ULL, 0xE7E8368C7F440330ULL, 0xD348DC71E2CD3985ULL, 0x43CCDEAAB94C01CCULL, 
            0xD47DF05922BAA7DFULL, 0x4FECE0689236CF07ULL, 0x18CE28B7C9DFF6C0ULL, 0x0BAF9C491E4DE849ULL, 
            0xED528B7DF9B331C4ULL, 0x98781B4FA56FB62DULL, 0x9C5337EAC20BFC7BULL, 0xA4FAAB776AE05774ULL, 
            0xF37B28AF9B1D0965ULL, 0x802BE00348F5E26FULL, 0x86D75D5D53373FE0ULL, 0x68B1084370B0F9A2ULL, 
            0x3D4EECCDE3A45549ULL, 0xECB83C13CD89E5FBULL, 0xBDFADA817CB1BAC8ULL, 0x6005F4492221370BULL
        },
        {
            0x248439DBDC02A477ULL, 0x3D71F2137DD25612ULL, 0x7FE7817F5602747AULL, 0xE0C56D2E5C3E0AADULL, 
            0x7BF8070FD8E411A8ULL, 0x4EB3DD25216C35E5ULL, 0x06A85F3FB4E286F3ULL, 0x876D0C6D3B1FC545ULL, 
            0x8EFD7BB6218CE384ULL, 0x472CD2FC5F795ABFULL, 0x40355593B63AD04BULL, 0x8EFA7057A6DCAC46ULL, 
            0xD8BFADA0F3957460ULL, 0xEA31B9751FCC24E2ULL, 0x63BF93E6756BAD8FULL, 0xBC6A5EF9BF49D008ULL, 
            0x8F37EBF5F84C2906ULL, 0xA69D5487F4654BEAULL, 0x81ECD413CA8B7899ULL, 0x05B8D23CAA8AA7ACULL, 
            0x55AAB0B1D3517D3FULL, 0x1A33C35D8A2FA4F8ULL, 0xA3E8D7D60EA46453ULL, 0x6B9FE96231EB30B4ULL, 
            0x1CA2E5A140C866B9ULL, 0x455DAB2FF97C791AULL, 0xD5BFEE6EC50CB080ULL, 0x9BEEADECF425F004ULL, 
            0xEE2E70A1AEA9A7B1ULL, 0xA5A506895B4428C3ULL, 0x77801536346291B7ULL, 0x31C45D91457D075CULL
        },
        {
            0x84098C8F790B0EDDULL, 0xF777F1B76691E89CULL, 0x7E627F7B93049DB6ULL, 0x6707BE8B5542DD37ULL, 
            0x2C9ABD47926A4C23ULL, 0x5845A9487032D498ULL, 0x3CE9599465B30DA1ULL, 0xD154C5553F4B1425ULL, 
            0x576C1601CE8C26C4ULL, 0xB7D910273FA4879EULL, 0x5BD40D88F37CA865ULL, 0xFFFE6D6771F2468BULL, 
            0x5FD5A7D7206DF30AULL, 0x94F270C04BFB2A8CULL, 0x8EEEC049E5D9091BULL, 0xE15EF3A4632940E3ULL, 
            0x07CEF7E8F569AF79ULL, 0x4D76507F9D4A2326ULL, 0x33B942176412EF9BULL, 0xE243B8C36EB1B92FULL, 
            0xA14BBCFFEC10D3DEULL, 0xCB2FF450ED32BFB8ULL, 0xA5E94A1B9B4DCDE9ULL, 0xA8677970F9E749BFULL, 
            0x4D036C4B51DA6581ULL, 0x5E9F3E23913A4779ULL, 0x1B325D3B1BA14A0AULL, 0x4D676B81F252E255ULL, 
            0xB9AF1D7A1C9574D1ULL, 0xF0FBA1D353AB79A7ULL, 0xE656E61554A3B7C4ULL, 0x747A9E648C7DF664ULL
        },
        {
            0x24E7460710D09EE1ULL, 0xFC539A138EE1F1DAULL, 0x8D7EBD6F64271AA3ULL, 0x14EB93E361F2E10CULL, 
            0x51803D5B43F27227ULL, 0x44907148F3504389ULL, 0x88110F349FDB6019ULL, 0x45F718E682CD2294ULL, 
            0x5A908C541D7F9207ULL, 0xB33B47A98D068F39ULL, 0x3240B47CBFC8BB42ULL, 0xB1A0C1A5F3D65AA3ULL, 
            0xB167613F137C67BAULL, 0x119AFC302C019C78ULL, 0xD07F86964F8BB343ULL, 0xD25719403A110759ULL, 
            0xF42F15599AF41BF5ULL, 0x941D34FE43CCDFCEULL, 0x78551435F803825DULL, 0x47A42D4406843667ULL, 
            0xB01D3CCDC4D7D973ULL, 0xE873097F8F6D698DULL, 0x24D224C8D30D7B78ULL, 0xF9FFDDFE994D1D2AULL, 
            0xF6C73E08C1513812ULL, 0x407EBA2BA08E6138ULL, 0x7E3297F2392306B3ULL, 0xFA3E4980A69D12DFULL, 
            0x90F3638285EA4830ULL, 0xF154AFA9A378BEBEULL, 0xCBEBFC98B4EBF580ULL, 0x284F7EA853485B5DULL
        }
    },
    {
        {
            0xDA792880E425906EULL, 0xB7701DC20F2472CBULL, 0x7ABD192965DF093FULL, 0xB9C1E18033C8FD62ULL, 
            0xE3A16A6688662A96ULL, 0x8DE0EAE4B5B9732DULL, 0x97668B6030A612B0ULL, 0xD7D2B87C01440955ULL, 
            0xE75294418A45A5D7ULL, 0x9AFCC9E0933E9966ULL, 0xB83486145021D8AEULL, 0xDBF8EDEA3B2DC8C2ULL, 
            0xFCE55846D2DC2D59ULL, 0x042534ED21D0BF47ULL, 0x19417FF337709AA6ULL, 0xE522772D643D485BULL, 
            0x021F4E78107C4B79ULL, 0x3A002BA532FD6E7BULL, 0x356ACEFCBA4F8BECULL, 0x2DEF64FCF1C0CC43ULL, 
            0xC0CFF75F56206517ULL, 0x303F7903BBB5310AULL, 0x4453EA5D19F318EAULL, 0x63413ACD6696AC1BULL, 
            0x59CC7EAA6921C54AULL, 0x389466261D841F08ULL, 0xDB9F00615B96C27BULL, 0x9DFD1307A2B656C2ULL, 
            0x4D883265B69CE39EULL, 0x6F5A9BB22D3E075FULL, 0x0129C5B95DAFCE57ULL, 0x2073D79DF1A2C589ULL
        },
        {
            0x3E0AD33862B7F0CFULL, 0x7204CD21A0981BCAULL, 0x3E2C4C2F791F51D0ULL, 0x3B7D2AFB23176894ULL, 
            0xAC10F59A46DC42E7ULL, 0xB597F99E5A234A58ULL, 0x565BB2996CB1D805ULL, 0xE99274ADD3C81902ULL, 
            0x282CB2DE75B9E581ULL, 0x57649702D897FE97ULL, 0x11F07B605FBC07EBULL, 0x19680CD83611D0DCULL, 
            0x63D6E6DB9541FBA7ULL, 0xE0BF4C621B3153B0ULL, 0x3CBF4B128E53812FULL, 0x0F7D8D4AA6DA969EULL, 
            0xD1C77036026ED45AULL, 0x2D0CC05F22148333ULL, 0xC74A7EAC7FA1AAF2ULL, 0x6929D2977D0D37D7ULL, 
            0x2B82A07B0DF946A5ULL, 0xE273416A9EDFCDB6ULL, 0x7502A0E80860618FULL, 0x5A1DB2854AE20D18ULL, 
            0xC3807264118CF7D3ULL, 0xD9FE1DD41D5ABE23ULL, 0x2D6CCB52EC4529BDULL, 0xD4A9D6840AC283CDULL, 
            0x676B14838F60ED03ULL, 0xD0BFCB662468442CULL, 0x5BEC978154A24C83ULL, 0x3BEE8779EB4D1F78ULL
        },
        {
            0x00A9C5D39AA77548ULL, 0x562D55A9723E433FULL, 0xCBEE30009C8A4BC6ULL, 0x6B52D68444BA4820ULL, 
            0x15BFFD045C93E8ECULL, 0x141409360A92218AULL, 0xF1D3764335D892A9ULL, 0xAC61D75E4D030829ULL, 
            0x65E76F3246D1FAAAULL, 0x6028F482BF097386ULL, 0xCEB0C4F7586B5251ULL, 0x880F103A0C9A2BC1ULL, 
            0x3BDF8686D2706815ULL, 0x2E667A10491A8950ULL, 0xE4A0422246EF6541ULL, 0xA2C78DFAE4E09516ULL, 
            0x04544A70500103DCULL, 0x74D0B5A576B5BE2FULL, 0xF6FF18C6D306EAA6ULL, 0x992CE3C4A45D7B2CULL, 
            0x24F6D0C9F83BEAAEULL, 0x4542CD726F128756ULL, 0x84FB46E11276A2ADULL, 0x2ED7D7BC3837E377ULL, 
            0x3655ECE23A9742D1ULL, 0xC390D49C48F0ABF8ULL, 0x41309B25AC4F6BDAULL, 0xB5C40FAC23AE2881ULL, 
            0xFA2DC14F0E9DE4DBULL, 0x170CABE5A35B73BDULL, 0x0A8206CEEA7663B5ULL, 0x5893F2D4E15688D4ULL
        },
        {
            0x0E778B733490C22EULL, 0x89D87CB65A79BA0DULL, 0x3003D0D5CDC8F7C5ULL, 0xFBAEE62E0B9D749FULL, 
            0xDCFE34CC2E1F0CBFULL, 0xDCA29A99F5FC288FULL, 0x9E074B867AE2DAA4ULL, 0xE496BDFD4954A494ULL, 
            0x393CB874C2B99B5DULL, 0x05B0CFDCEE2FB615ULL, 0x906124888E31F778ULL, 0xF0F7DE1DE8AAE601ULL, 
            0x2056BD828BA2C181ULL, 0x12222199E9EC7E3EULL, 0x80C71E7FAB390828ULL, 0xD632134AA19E66B0ULL, 
            0xCAB4BDB14711A392ULL, 0xCCD1ABB44D4AF5C5ULL, 0xCAE73BEAABAB732AULL, 0x1DDBD3C8DEACEDD1ULL, 
            0x8E1F0A53641B4D11ULL, 0x7EA0094B3EEDDF4DULL, 0x40C89AFD30F3A6D6ULL, 0x30C9D01997C7F2A6ULL, 
            0x67F9CC8B6C986B00ULL, 0x4DC8B944C5AC972AULL, 0x85CC44D10278D051ULL, 0xD8D2C9A7B5B4AA40ULL, 
            0xDED92203DB8B5CB2ULL, 0xDBB6D1C142C576CBULL, 0x8050ABAD9BBF4832ULL, 0x09C6EF6D1BB5D86BULL
        },
        {
            0xD8DAB80B6441A59BULL, 0xBB7AA356C7C12028ULL, 0xCD755841C7FE663DULL, 0xD6CF772D2E650EB4ULL, 
            0x0D56472274406997ULL, 0xB5604E07173CD0A7ULL, 0xA6F85522051F5EFEULL, 0x2AF6B8906D2522CDULL, 
            0x3A5FBA8591AEF70EULL, 0xEB82139097AFA967ULL, 0x8EDA29BFBA98B184ULL, 0xDC9A30140E5D8B25ULL, 
            0x0B7CF15BC6B3843DULL, 0x94920E4BB715075BULL, 0xF2A92081E749F58EULL, 0xD16650865A1DB720ULL, 
            0x3EFF587E20E76801ULL, 0x6483D4BE860E8A7FULL, 0xEA09FB7394FDFBF4ULL, 0x27C99D05E7B99CBDULL, 
            0x2A6DFD95854B8FB1ULL, 0xF0FFFA83627CA662ULL, 0xFD78B7B92057E843ULL, 0x4E9A70413C1F9F3EULL, 
            0x306B18FD2BDE831CULL, 0x628DA1790539FC52ULL, 0xF2E068EE3C538227ULL, 0x5212D8B5F4E53690ULL, 
            0x01E5ACB50A900986ULL, 0xD5AA10F157CDAFC3ULL, 0x7FAABB61938FD08AULL, 0xC13954C9A093A3CAULL
        },
        {
            0x6560A80A50DF8D40ULL, 0xC09C20FEB11C1ECCULL, 0x57DA5681A9208E94ULL, 0x29C96F9B60B7352DULL, 
            0xE13807E32DDE3CD1ULL, 0xA7FCD1459394A121ULL, 0x025C1D3DFFB3E308ULL, 0xE1EDE3D0B18EBFC3ULL, 
            0x2F32E84A56EA7F62ULL, 0xF3D7A4529E41A8B8ULL, 0xEF716B3B2DA43783ULL, 0x412DF2B6DB0A3B09ULL, 
            0x560C21C97EA7A81FULL, 0xECF42A637FA5F66BULL, 0xF747C24A5F6B0819ULL, 0xDD1F3B1A8DE9AD47ULL, 
            0xC5DA696286A1F356ULL, 0xCDA0B8F1ADBFB7B3ULL, 0x62AFAC79D1C25C37ULL, 0x37C6ABEF1F16B7DCULL, 
            0xFB14E3ACB7BA4DDDULL, 0x22835071C1F41828ULL, 0xCB7F035888033A67ULL, 0x01D836F77EF5AD92ULL, 
            0x42C779F048090AC6ULL, 0x65656A427B9D21DEULL, 0x5F54389BB84FF5A5ULL, 0xBD8FE8A00690D670ULL, 
            0x697538895876E3C4ULL, 0x6A4A698E907A7943ULL, 0xD5749BD2E43362B2ULL, 0x8AA69B0B4C69E541ULL
        }
    },
    {
        {
            0x112D66CE9711FA29ULL, 0x3197DB9F0B889E97ULL, 0x95B7AA81C118CEB8ULL, 0x364253A3C4C18B52ULL, 
            0x56772D90F91FF64FULL, 0x141BD8965D1C0E48ULL, 0xFE4B9CB92CB7B2E0ULL, 0x081F2372ED853E5AULL, 
            0x59582B8CF718A7CBULL, 0xFA08DBF8DE587EA6ULL, 0x6967C7D948B232E7ULL, 0xF862EB8B47215605ULL, 
            0x1DFE54FA8F745B76ULL, 0x9886E9DFBE539A0CULL, 0xBCC155FF89B873B7ULL, 0x5E99B66EE48FD676ULL, 
            0xFB3EB4BB0E382FAEULL, 0x7AAB6472F30CA377ULL, 0x94BDD0429DAEBD47ULL, 0xAD8D3620FDD16BEBULL, 
            0x2D036BB30D90C0E2ULL, 0x8C2905477FFF45C3ULL, 0xD21B19CEE1BA351DULL, 0x23E5572D582B7BFEULL, 
            0xAB639A1DDE2C0743ULL, 0xEF56185BBC80A768ULL, 0xD7DD3A6524FD1DABULL, 0xD3E4D4B135D69838ULL, 
            0x0D60FAAD9411236BULL, 0xCB600131DD4DF362ULL, 0xB719F8B177696628ULL, 0xACEA698152CDD933ULL
        },
        {
            0x55C2719769229B52ULL, 0x103FA47E57C51813ULL, 0xBD15E813F336CDEBULL, 0x243B7F36588EED22ULL, 
            0x42BF7F7C4568CA2BULL, 0xE92265E6205ECE2EULL, 0x40692C3F1ACC0ED9ULL, 0xDBBED40882FE1593ULL, 
            0x7E2F6C8372704548ULL, 0x012C727BB1565C3DULL, 0x09BAA19CF5D845BEULL, 0x41DE004DA55DE009ULL, 
            0xA324FDCAE9DE0121ULL, 0x59320BCF34DA3F17ULL, 0x65F1947F05E44853ULL, 0xE28E850DC6FA208EULL, 
            0x4525DA886C773540ULL, 0x3D991B74B99FEA0CULL, 0x52C56F6B0B4A09B1ULL, 0x16E2DD41ECAB436CULL, 
            0x3D86AB69703A2F45ULL, 0x01F4F116F8E6F60DULL, 0x6E629F68C72C4D9BULL, 0xB8EEFCCBD42E2BFFULL, 
            0x4213A3AA6A52A253ULL, 0x19D025CE35CB5537ULL, 0x2186F8762FCBB0CEULL, 0x844361B8243079D9ULL, 
            0x5444825F92D0AEDDULL, 0xB473DD3547055D85ULL, 0xAEDF526DA187F2F5ULL, 0x46C930BEE984A192ULL
        },
        {
            0x1DB8DF9B8107FB7BULL, 0x142475DFB892552EULL, 0x9C1D843DB79EF822ULL, 0x1599393DFBCD5745ULL, 
            0x0FFB2B702B738B2BULL, 0xD2B7AEC716150460ULL, 0x0395CB5179C8F456ULL, 0x29A27808D930BB2DULL, 
            0x5C3EF1228E3C9E58ULL, 0x56B327E2C993A6AAULL, 0xF5AB4DB7695B9CC4ULL, 0x4944DD8F185B8C20ULL, 
            0xE35E2A4907EA75CAULL, 0xE550B9038672054FULL, 0x854816404050F18AULL, 0x393146EDAFB09349ULL, 
            0x83E828814CB8DC90ULL, 0xF986083249CD3C55ULL, 0xB4EB2CDA246FC8D5ULL, 0xF9B21420F1838C6FULL, 
            0x40637E9C67F24269ULL, 0x423128D07F05CAEFULL, 0x468C51784CBED969ULL, 0xADF44AAA68DEFFD7ULL, 
            0x799106407E65EE33ULL, 0xD2BE8307EA981D26ULL, 0x5834003F4F1CDFE7ULL, 0x497FD2FFB1629A13ULL, 
            0xA4DEB7C0892FED82ULL, 0x70FDB4F91BC8D386ULL, 0x77E010B3669B2D9FULL, 0x18A01F81A9029959ULL
        },
        {
            0x04FD79D3BF074BC7ULL, 0xCA8B9ADD4E3D76DCULL, 0x88E196D0E733BA85ULL, 0x194DBE4A5A0F031DULL, 
            0xC12988BBF7F9801BULL, 0x86415828C1F03593ULL, 0x779B5BE9C2F20FB1ULL, 0xF3FC68265116981DULL, 
            0x6A728B9D1ED36822ULL, 0x423B3966BA92D5A7ULL, 0xBB4B0F82DCD94662ULL, 0x7D78687FBAC3C311ULL, 
            0x2046E47D8C46F04DULL, 0x4ACEF2541020644CULL, 0xEAA2C8CFE3B064D8ULL, 0xEEEDD04C2AF1265FULL, 
            0x69C0C5E3B883C274ULL, 0xB915ABFD6764019EULL, 0x03BBEAFE56B622D1ULL, 0xC0F995094824D71AULL, 
            0x6731D41F925E21BBULL, 0x9FC8A885156C2791ULL, 0x08A9E7B8F4836F8CULL, 0x5CD81EE3D22E6C92ULL, 
            0x07163415EE78EF24ULL, 0x66413B1146DFDE30ULL, 0xA2FFE4CEA87E9DBDULL, 0xD6ABF0ABB445E146ULL, 
            0x5CCCA64A450D53E7ULL, 0xCFF13BEFD63735B3ULL, 0xBE303EA350EA53ACULL, 0x10F6D1F5F9681415ULL
        },
        {
            0x2B0F665F42DC9FA1ULL, 0xC258318241C02C49ULL, 0x8A455837E50BC3C6ULL, 0xD1AC5AAA12B1406AULL, 
            0x35A745AE6B3905A7ULL, 0xB012AF1BEF911475ULL, 0x31475F75A22E510CULL, 0x7FCFDA1E555BF064ULL, 
            0xFA65E0ED4B35ED9EULL, 0x925EC70DF14CB168ULL, 0xB5271F328B9513FCULL, 0x6B0F2E8CD1F23230ULL, 
            0xA366FFFE2BBB25B7ULL, 0x60714550FDF23E80ULL, 0x13A5606F4B2B31F5ULL, 0xC961C77A1E53A973ULL, 
            0xB7B13684AB334E6CULL, 0x7B43CAC9666CEC5BULL, 0xD88D6995AFE7900CULL, 0x43A9CBBA491987C0ULL, 
            0xEC1C6EF4FB8D64F1ULL, 0x37ACED01A1C655AAULL, 0x4D861D087899AF2FULL, 0xFB66A14FC131AE98ULL, 
            0x72442D4B9DFA4CDFULL, 0xEFF99C57882FE055ULL, 0xB6032BA147442E34ULL, 0x99E592CF39B149A3ULL, 
            0xB33ADF8CB3EA9667ULL, 0x2346EF01AB0CC897ULL, 0xCC31531F0B6CE890ULL, 0xC7AEDC7E7E85A64AULL
        },
        {
            0x1106D6E55FB0CD55ULL, 0xB4C19D953FA971A0ULL, 0x00010C6F820B3083ULL, 0xF24751BDD901526DULL, 
            0x6886FA2C1436CA5CULL, 0x155249E52A0B5F46ULL, 0x9DCDB648EB0EA56EULL, 0xA5A1E3D57734202EULL, 
            0xAC7CC7B6A27BE2DBULL, 0x69BC54045DEE2716ULL, 0x1EEB62F8B986D80DULL, 0x8A5B13E6DA5AF914ULL, 
            0x1D51831C8864B547ULL, 0x8A216042146E8C56ULL, 0x9748986D4BD39F50ULL, 0x243C6F77777832E5ULL, 
            0x2BB5FBAA0F74AA4AULL, 0x06061949CB625FEAULL, 0x0A99D42988CB864EULL, 0x74E771B030386215ULL, 
            0x00F50E5F75CB8477ULL, 0x4403338FBD79CC60ULL, 0xCDC24F5FE651EB51ULL, 0x12E839A9D513C7B4ULL, 
            0xC923D288699E0296ULL, 0x04AAD761CB98095AULL, 0x303018680FDAB554ULL, 0xC15C406155C55DB3ULL, 
            0xA268C33187AFF488ULL, 0x4D516D105F053FD5ULL, 0x6C4AD8B555E74E50ULL, 0x898B6D8691FA3D83ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeyRotateAConstants = {
    0x42702039B4FAB186ULL,
    0x2F6B7F08EEB1733EULL,
    0xFC6B8C7FDC123690ULL,
    0x42702039B4FAB186ULL,
    0x2F6B7F08EEB1733EULL,
    0xFC6B8C7FDC123690ULL,
    0x9EE1BFE63311798DULL,
    0x89ECBEC84B3B7B85ULL,
    0xA8,
    0x2C,
    0xF7,
    0x2F,
    0x73,
    0xCB,
    0xD3,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Regulus::kKeyRotateBSalts = {
    {
        {
            0xED19B9F7A27ABC3BULL, 0xD9BAF468610CBC7AULL, 0x6AFD3C758B7583D9ULL, 0x31EFD01B1532870BULL, 
            0xB2885332FB266EB5ULL, 0x674145BEDC55CB99ULL, 0x31E7904AE3302B3CULL, 0x3C1254E64620334BULL, 
            0x4D014CD57046DE7CULL, 0xB08016BE929206B8ULL, 0x89F16DF11969BAD5ULL, 0x1D4A59544B70C309ULL, 
            0x9FBC8340F3B38461ULL, 0xD7948C91AA604DB0ULL, 0x898F2242393176B1ULL, 0x752BA7E08DBF0D97ULL, 
            0xE1EB70A2F82A6582ULL, 0xB08D5D6FB50A2D84ULL, 0xBBFE9E47AEBE8295ULL, 0x706D8BD6BD5F4318ULL, 
            0xBD28A95781C2C609ULL, 0x01C5F747C49BA901ULL, 0xD82D9664ADC62AECULL, 0x1845926C07CC9B80ULL, 
            0x7174C164A7A01B75ULL, 0xE0E5C9B681DB0271ULL, 0x8BADE07C0A13918AULL, 0xB13E2D1E32076BE4ULL, 
            0x6EA1FE11CE4F5297ULL, 0x1BC0AC02297EC43BULL, 0x70F1616D4DD377F9ULL, 0x23249AC525ED2B6FULL
        },
        {
            0xDBA0FFDF503A6712ULL, 0xD27C515BB2C23DBAULL, 0x856CB937BEE3AF2EULL, 0x334E45711FB779D2ULL, 
            0x23BCB9D930DA6FBCULL, 0xCA755D97A573CFA8ULL, 0x38AEF58D2C8375F1ULL, 0x859BE1D808F78ED8ULL, 
            0x6E165A97491AABD2ULL, 0xD9217E2D6EB2E4A7ULL, 0x79F7B4E0ACA2B37BULL, 0x0FD7DB544E5F404AULL, 
            0x089F58CEA9261999ULL, 0x100F2DAFACD04E23ULL, 0x625151F41DBF0978ULL, 0xDE488C93D57B9369ULL, 
            0xE20754AC7E52D525ULL, 0xEA40D3E2F942EAF5ULL, 0x91242B7D3B81BCF5ULL, 0x575435EFCA16236CULL, 
            0x32CEFF8A042E682BULL, 0x1C2D54DC0CADE37CULL, 0xBA32AC0F53A99748ULL, 0x7C7E5573A3F5CD28ULL, 
            0x4218768E7A15F812ULL, 0x102B10F73D780F16ULL, 0x10CFEBBD87D2E569ULL, 0x492286CD44BAB4FBULL, 
            0x5FB050706E67C413ULL, 0xD8FFFB5B118EA190ULL, 0xAEBAFB572908A69EULL, 0x99034CA6C84B94C5ULL
        },
        {
            0x87771CC5B9272959ULL, 0x049A191C7EE76073ULL, 0xF21307F78C22E618ULL, 0x91BF83F27A8DBA12ULL, 
            0x34E554E6E4B76785ULL, 0xB66076F4CE888CEAULL, 0x043E6699930ACD16ULL, 0xF92FA0C13B59CB9EULL, 
            0x17E506E302A46FFBULL, 0xE2B864C6C4149F0EULL, 0x5E34702A1D9CEB22ULL, 0xE3747240AC95CA09ULL, 
            0x6EE79C53F18C78A3ULL, 0xB3B5A3FC9EADF07EULL, 0xD42C729C020929ADULL, 0x01EA54678E57F072ULL, 
            0x55EAF5A7452F81D7ULL, 0x73A88805B9513FB1ULL, 0x9C5AEB5EEB5560AFULL, 0x528ECC5D03AFB3ECULL, 
            0x00EFD538D891DCF8ULL, 0x51AF86D1B9EB6DA4ULL, 0x1835DEC8D30C6174ULL, 0x742B35DE6FD35090ULL, 
            0xC02956CEA9BF39E2ULL, 0x3544AAF695C8B0FFULL, 0xA30DFD1E7CAF8662ULL, 0xF3D636F533E5354CULL, 
            0x98D5717FA8751CE4ULL, 0xC7180AF52AE8105CULL, 0x071D3D9A4094357FULL, 0xF48B31DFE9FFBB8AULL
        },
        {
            0x37B018F36710C3A1ULL, 0x513389BD0D1341F0ULL, 0x40B15531485577EFULL, 0x23201AF2DAA3EB62ULL, 
            0x61FAC6A7CE240EF5ULL, 0x35D09D1CCB6518F8ULL, 0x8AACB2F9FAAFED03ULL, 0x97167693CEC84D71ULL, 
            0x7704885D5AAB5C64ULL, 0x43DE5D4EDBD9A5F4ULL, 0x9416AED2D2940C89ULL, 0x5C9D8347AA2CADD4ULL, 
            0x351DA5253B853D29ULL, 0x1AB227AD3D592E1DULL, 0x3926C1CA0C6503A9ULL, 0x210BC3549A465FB7ULL, 
            0xB8D228EC169D88A3ULL, 0x1270F0C71E49B0AEULL, 0x796E6BDA24560635ULL, 0x0D3CABE919692F6AULL, 
            0x2BBBD2B8B9466961ULL, 0xBA456961255724F4ULL, 0x1D84A212E9523B3EULL, 0x315445823DC9E145ULL, 
            0x2F1A1A8361B9BF13ULL, 0x9FB5837CF6ACC5B1ULL, 0x526FDB0DF9A71B68ULL, 0xACC40D5E7649D1E0ULL, 
            0xE2AA0B44D5849B66ULL, 0xD8E22D65E9C8F7B7ULL, 0x4EC30B50F2192702ULL, 0x3B63EC4AA6E5509EULL
        },
        {
            0x647E2A38591C2739ULL, 0xA740809B15F21929ULL, 0x426EFC41DFCEBE6CULL, 0x56FF60ECBD6C965DULL, 
            0xD238FAE319DD472BULL, 0x06D4B2E45FBFCB98ULL, 0x8B0F2657604DDC47ULL, 0xC57A414F2D6F3557ULL, 
            0xEE33D37A88388A43ULL, 0x4308B729A3BCD7D7ULL, 0xDD66D1D8F5738799ULL, 0xD336B318422865C4ULL, 
            0x2089EA503CBEFBB2ULL, 0x04F009E2324CED69ULL, 0x597E669FB179AA2DULL, 0x4A09917F5B5A3E8EULL, 
            0xD42898DABCCD0C6FULL, 0x20FA534E27A824CFULL, 0x1D0FA9CE6915758EULL, 0x4D9E8C63F4B46C11ULL, 
            0x749247FAA83C5D4DULL, 0xC3F6B549E7A3830CULL, 0x19531F8E32297A8EULL, 0xAC87F3614CFBFF18ULL, 
            0x51BA212E52232C65ULL, 0xD9633891A0D8564BULL, 0xF2D95A86B522CE1BULL, 0x33BD0A99696F5AFBULL, 
            0x2EB13D371F0A0318ULL, 0x23F025A4C9C511B4ULL, 0xE23FE32432CFBF36ULL, 0xD3FEF479F4D8C758ULL
        },
        {
            0x67C3B392F0698529ULL, 0xE741A92BB147F67CULL, 0x93ACFC626C565F60ULL, 0x4BC4D83314A0ADF1ULL, 
            0x3BDA0545FAA02335ULL, 0x320C2E9344FA1207ULL, 0xCD3062ADA529443AULL, 0x0BB3DF1B5E486ACEULL, 
            0x1F66FA8BA315F64CULL, 0xCED4CEA022A113BEULL, 0xF6075B763125A90CULL, 0x98A37A2680A5D675ULL, 
            0x5DAFB3B5FD682383ULL, 0xA10702C23E89B4B2ULL, 0x909999CC26D10C26ULL, 0x82562B2E12B4007AULL, 
            0x464C45D33BE2BD92ULL, 0xE21825954A81A78FULL, 0x1249525031A87990ULL, 0x6038A8033ABB8962ULL, 
            0x668D54DC4B362150ULL, 0xAC29AB356CAAC435ULL, 0xA7B3405471B44ED5ULL, 0x8E1CC41AC9DEC55BULL, 
            0x2A6BE5BD888118D9ULL, 0x6315EFA932588C35ULL, 0xE0A3DA1BC860F3AFULL, 0x4FD29AAA1C0BA002ULL, 
            0xA19DD2D647D2634DULL, 0x7047C186E9F1158CULL, 0xA3B0DBF6B41B0657ULL, 0xCEBE958506D20F63ULL
        }
    },
    {
        {
            0x3086DB7A92679AB5ULL, 0x863855240F8DB689ULL, 0x814A711EBE1E08FBULL, 0x99AF33A75DE6537DULL, 
            0xF50A1734869BFF11ULL, 0x7F6CC3E6C5C0B99AULL, 0x76397BCE4FB262EDULL, 0xECDD4065B5710D91ULL, 
            0xF93E819210415F80ULL, 0x4AF739750FB36F2DULL, 0x33ECE3CFAA9E6A61ULL, 0xC093074C4FEAFB22ULL, 
            0x84CDC9A3B82142A8ULL, 0xD31314ABAE7B4EF2ULL, 0x15A9ADC7122B0C39ULL, 0xE8A7358A74C92D62ULL, 
            0x8C7EBF2E5B54FFB5ULL, 0x17D5762BD1491B8FULL, 0x7707D2740410A164ULL, 0x12287E86040574C9ULL, 
            0x586944D71F2CE7B5ULL, 0x372868F9A4ADA8A1ULL, 0x254DBA6426DA4C44ULL, 0xACAFFDB662A8E125ULL, 
            0xF6469DECF66933AEULL, 0xEF4EBD5C23C2C8A7ULL, 0x11D77487E2E15126ULL, 0x1E0D5DFEB937BE52ULL, 
            0xD720DB1A5BEB162BULL, 0xB9DA49A5C37060D5ULL, 0x56DC2DB275BAD8B5ULL, 0xCA95902EEF33370BULL
        },
        {
            0x45CE3BD8CFD11F07ULL, 0x9D349E3A57D8998FULL, 0x8A302C276409BC0DULL, 0xEC9EC52C7BAAAD6EULL, 
            0x722F5B70FD16ECA4ULL, 0xC170C63C018485E5ULL, 0xC3D8822542C362E7ULL, 0xC52BC4965E566FC0ULL, 
            0x22E8D0595C407FF1ULL, 0x4B553F2DF15FF496ULL, 0x60C5B814BF33AB8EULL, 0xA84F9BD5ADAC06CBULL, 
            0x16586AA035C20C82ULL, 0x1840D94CCEB8A6BDULL, 0x9BF1C30F72E251DBULL, 0x03718CF971791A1EULL, 
            0xBD31BE9151D4E3C6ULL, 0xA0D29EFAED19DA6DULL, 0xE065DDEF0726FF67ULL, 0x88AECE6F7CF7A362ULL, 
            0x036F70663353A656ULL, 0x93ACC7877F1F38ADULL, 0x297EA3C8E3DDCE6DULL, 0xC1F6EC1B82AB7FDCULL, 
            0x0CE3F1C5548ED886ULL, 0x7CE97EDB649C8B07ULL, 0xB2C17502CE9E7B47ULL, 0xBFC8B5876BED4046ULL, 
            0xA644610FF74AD144ULL, 0xF8C733D752C80B96ULL, 0xBB36D2E35CB90283ULL, 0xA4DDEE508D6702FFULL
        },
        {
            0x3018D3D782BCE5ACULL, 0xA6168992A8D3E9CDULL, 0xA3CCB393EE0E251BULL, 0x22E01A6ADDDA3536ULL, 
            0x7FD07B9D9681D9D6ULL, 0xEBD34B8A2A700D66ULL, 0xA7732D328FC40552ULL, 0x62F4A2F881C6A129ULL, 
            0x125F8BEDD9AF5C0CULL, 0x6E2A861C9CE4A0ADULL, 0x1A10C051F65BF15BULL, 0x584A4B344CA5B740ULL, 
            0x8E50A8F611766A52ULL, 0x870243BC3287FAC2ULL, 0x119985C44BFE1E18ULL, 0x6690935F09C8050AULL, 
            0x7CA985373F060326ULL, 0xD52E8AF55735E172ULL, 0xDD8E1FED3B01F573ULL, 0x5E1AC548F975373FULL, 
            0xBF3C734D9D8983CCULL, 0xC9D11ECCDEA810C2ULL, 0xB970CF73ED58D274ULL, 0x8580B2EC05427632ULL, 
            0x4EB277510E67F78BULL, 0xD650942AB9749446ULL, 0x0CE4285AA8954B4EULL, 0x9CEB52B0ED490258ULL, 
            0x871CB392B6D089A1ULL, 0x21CBDDE221BCF555ULL, 0x46236D2EBB45A5E1ULL, 0x94CB5202B2EF60ABULL
        },
        {
            0xF97B838EADC292AFULL, 0x26AF83A202E5D923ULL, 0x6860413504F1FED7ULL, 0x10BEDC6573D41425ULL, 
            0xD127DB6D01217D8AULL, 0x92C14C930C892349ULL, 0x45D0FD61F894014EULL, 0xAFB8E6CB591A477AULL, 
            0x743663E4A57DB9D9ULL, 0x94C4D8C554C9BA5BULL, 0xB2616018B4142A3AULL, 0x301BA8B3EC285CFAULL, 
            0x243A02585DAD139DULL, 0xAF702025FA828FA5ULL, 0x875820B74ACDD775ULL, 0x849039E2C44EA0B7ULL, 
            0xE0FD602B778F133CULL, 0xD61E578728B2A118ULL, 0x01688551A5A1B4AFULL, 0xAB0F5A9F6503518EULL, 
            0x163680DA805BA907ULL, 0x0E136C346D1B24AFULL, 0x87C0FE6E76F228CBULL, 0xA194D6FC09F6D6CEULL, 
            0x6F3DD12703AAD967ULL, 0x068DB75CE0BF04FFULL, 0xA217373BBCE9F840ULL, 0xD6B156E00BE3E0FFULL, 
            0x205DD79325F36C22ULL, 0x64D72781251FA4A1ULL, 0x2B0C2794EC1769A5ULL, 0x6F8B5DACE85680F3ULL
        },
        {
            0x7881A8211332B4D9ULL, 0x4DB54E4B7A03EB95ULL, 0xE6B55811DB220F99ULL, 0xB0DC5930352D5524ULL, 
            0x5459F9F48D816092ULL, 0x7791F9962487179BULL, 0x7C7DD847A423BB1CULL, 0xA3F0CFB11452FB4EULL, 
            0x005F39A5901130E6ULL, 0x9135F25678725382ULL, 0x8D3ED59640ABEA6BULL, 0xCD2E40F280115FC5ULL, 
            0xEE85E15266AA10AEULL, 0xF22E71C05BBF544DULL, 0x2B0D6547926D22A3ULL, 0x89B5C8BEF424BC33ULL, 
            0xB4309B7D3BE63345ULL, 0xF355B9498498ED55ULL, 0xCD7334A7BEA00244ULL, 0x92DB2BA7C95E62B7ULL, 
            0x94E200A00E8D5F51ULL, 0xE5824AFF659FB1ABULL, 0xD93F6999BBD8A798ULL, 0x402CBA836F590E5EULL, 
            0x850623BC63D24ED6ULL, 0x70DFF3F4A0FBFE4DULL, 0x979A78FD716302D2ULL, 0x61AFCFF5BB91BC15ULL, 
            0xC432A41752526C1AULL, 0xD740A65CCD27372EULL, 0xAEAB29181662E3E0ULL, 0xA01CB3607467DA2AULL
        },
        {
            0xC57D07BDEE8C03C1ULL, 0x444C8EA49EADE2A7ULL, 0x21C305961B42C53DULL, 0x7293FA3D84E421B8ULL, 
            0x91F4FC4C69EC2823ULL, 0x72D3ECEBB933220CULL, 0x27BB5E6B4F54FDC1ULL, 0x3EBCE654C6EA3B22ULL, 
            0xA0772C84A66AA9FBULL, 0xE747E5914FD1FCF6ULL, 0x03D375B129997695ULL, 0xDD8B74AA6919F014ULL, 
            0x3646382CDEBEFD4FULL, 0x7955505CFD07A8A0ULL, 0x3D96FA9A56269736ULL, 0xB8C4FF38944D5E89ULL, 
            0x080F10EF48813D13ULL, 0x209952795E8E3F46ULL, 0xA29C7C4B0B64477EULL, 0xF6874F927FA433E6ULL, 
            0x9182BD93E1F81C93ULL, 0xAF00DA8D837E38CEULL, 0xF96155E7977D3E00ULL, 0xED82C6D8BAADB7FFULL, 
            0x068BABF53264C309ULL, 0x86DAE87D93850BC1ULL, 0xD10A0DB35F9D2B85ULL, 0x977978D645CD43A7ULL, 
            0xF9F18DC444BF7E71ULL, 0xC8ADCE0543BC05B1ULL, 0x73D070A5A31D8053ULL, 0x6A5E20BD89A12DFAULL
        }
    },
    {
        {
            0x7269AD4848443D43ULL, 0xB10FB8E74EE8FCABULL, 0xD22016E9F64598F2ULL, 0x21A3BB347B9BBD0DULL, 
            0x7C9839E374383BFEULL, 0x8A22BCB2A6B49308ULL, 0x0D8C5369DA2050BEULL, 0x95AB21077494C345ULL, 
            0x75A285563EE15698ULL, 0x2DBD0E0DEAF669CAULL, 0x32B32CD29C71A880ULL, 0x3BDA8B53F095DBB9ULL, 
            0x9132A22096EB2553ULL, 0xA65F729372A52914ULL, 0xA8293C6494610B8AULL, 0x2798B842A043B7E7ULL, 
            0xBFA853D6F6184763ULL, 0xAA2DBE4009346EF1ULL, 0x732CBE17459739BCULL, 0x03D253FED0E6A29BULL, 
            0xDF93BB85F7D70CDEULL, 0x6A00E411E5477E03ULL, 0x06307065A22D470CULL, 0xBDDD85417C12A7D5ULL, 
            0xAC3BA665759A8C57ULL, 0xC2AB70C87BB6167FULL, 0xE10E5328A0BA1530ULL, 0x516858D61F2D8F29ULL, 
            0x79AA79778C522C75ULL, 0x0F0B813BC76302FAULL, 0xBDB26920993B9598ULL, 0x530F980D3432FA1FULL
        },
        {
            0x0D77D27C659FFF81ULL, 0x5ADDA66F8D1EA44DULL, 0xEC0CCD0DADDDD62DULL, 0x08689DEF4382A8D6ULL, 
            0x4D2F55F4CEB95CDFULL, 0x03278F0C0BF0F623ULL, 0x1B5E08851015ED75ULL, 0x10AE678B52E02434ULL, 
            0x1AC52DCBEE8864AFULL, 0x5565AAF8459411B0ULL, 0xEB94A61DF9E06A05ULL, 0xEB67FEC96F139C76ULL, 
            0x471A01CF86D4B5EBULL, 0x88C62F534CEC9EDFULL, 0xFA607298835A0BD2ULL, 0xD15BF766B9A2C1A2ULL, 
            0xD0B1BCA7D4BAA5EAULL, 0x37A3FB6D8AC24B3BULL, 0xA5CD81ACD7358B38ULL, 0x5B3971820BCAD60DULL, 
            0xD851680552F06DCCULL, 0x8491EBCD3F4B9606ULL, 0x15F6C0B987816105ULL, 0xCBB2BE9C19C615B9ULL, 
            0xBBF0261C63784F9EULL, 0xE72F66A83671C102ULL, 0xBD8A5AFDB0FBB2E9ULL, 0x1F84C75D77D23E4AULL, 
            0x38F51F663D911E9FULL, 0x73239D1A4AA45713ULL, 0xCF99130AE952F21EULL, 0x565BD12F99C44A6BULL
        },
        {
            0x45F9A83016ED1A54ULL, 0xD851094DFB95D7EAULL, 0xD16E404447F114E5ULL, 0x965C65302B9DE802ULL, 
            0xF813E25EC8CCC648ULL, 0x05399D662107AC3CULL, 0x921C7E3161BD50ACULL, 0x2909534047A9A656ULL, 
            0x0961D8A6698D53EAULL, 0x1B27AAE75DF92A21ULL, 0x3BACEF214F713137ULL, 0xCAEB023E48886D4CULL, 
            0x43F2B35209DAB715ULL, 0x779554A81B1235A1ULL, 0x60555DCCA26CA54AULL, 0x269A727E4E1300C5ULL, 
            0xFC77F279CC6B7B8EULL, 0xDC01BBF7367D0454ULL, 0x45DE3A9F7C1BA03FULL, 0x36D1E9C08410CBC2ULL, 
            0x22AE100F6F9E38DEULL, 0xFDA6FA43B7325C36ULL, 0x61902C81511B0756ULL, 0x92CE4BDDA9DF5B10ULL, 
            0x9559DCC73E3BE73BULL, 0xA3D9A78E18DB2D59ULL, 0xF013E46D03E5B7C3ULL, 0xCE508576926B47B9ULL, 
            0x3A4AD07AC86FF7A5ULL, 0x58C486BBD80B1CE1ULL, 0x756F970F8D0D58C6ULL, 0x3218ADCA8D8ECDCEULL
        },
        {
            0xC07DA436F7E10B2DULL, 0xF1538D5931A3D2D3ULL, 0x3600C33958572ABAULL, 0x3F97BF27A413DA6FULL, 
            0x747FEB3BF16EA2D4ULL, 0xCDF934612E28003BULL, 0x6AC0F205ECAA0FDBULL, 0x6345CC316BC909E3ULL, 
            0x54B064D24EED2B3CULL, 0xEADA5FEFD08A8593ULL, 0x23ADAD1D6C5F85D3ULL, 0x9D865DBAFB341027ULL, 
            0xA8F1FACF7A156D22ULL, 0x7335C63468A23F7AULL, 0x9E4511FB05DCC187ULL, 0xABED16CFE82A058BULL, 
            0xE1437CD3ACC635DEULL, 0xCBEB6A7EC7A14867ULL, 0xEB009094BADCB545ULL, 0x8B9AD642236D6576ULL, 
            0x4CF9610B227D41A0ULL, 0xF21C9768B2E9CA22ULL, 0x5E0D8BB684444A18ULL, 0xF035000A68CCC5C6ULL, 
            0x9B23C8B3253D0892ULL, 0x2921091C4647AD25ULL, 0x30024B10E101F516ULL, 0x203CB2E39741FE39ULL, 
            0x0D987D824F3CA9AFULL, 0xB96A11C4FF435176ULL, 0xD997C3DEAE23B925ULL, 0x93F829345EC84688ULL
        },
        {
            0x0C30C6E65F114B4EULL, 0x5900F4856D6C4FBBULL, 0xE2302190E1761281ULL, 0xEEE3A6E9CEBA7A79ULL, 
            0xACBFDDE7B0079384ULL, 0x9AD4525E6E96CDA2ULL, 0xDCB4F5BCA7C61780ULL, 0x1A222741C46EC06EULL, 
            0xC8098AF1E04ED6FEULL, 0x69D4978795E3C650ULL, 0x573ED539C95BCFBFULL, 0x9625CD264A2F231EULL, 
            0x9CE5094E955DEA63ULL, 0x1F9CFD48F30506D2ULL, 0x7D7D1AF4405D7507ULL, 0xA20D8EF8B02EFF41ULL, 
            0x63CEE8DF538AE012ULL, 0x73EE2989C4A47492ULL, 0x443BD442FF9C7D52ULL, 0xC9D92FEAA5ADAF3BULL, 
            0x7A2BF6920399852DULL, 0x4D9FA92868EC6AACULL, 0x1A72B08FA6F9D668ULL, 0xA326DA05221A685EULL, 
            0x1DF5159B174B079EULL, 0x78280D0ABAF5E04EULL, 0x969E7EC4A76B7268ULL, 0x2BFE376F53B34507ULL, 
            0xB0C50954E6A218D2ULL, 0xAB545D74B315074CULL, 0x0B4AA002DB65E89DULL, 0x8720BC1614CB8175ULL
        },
        {
            0x8BF7771A60E62B6AULL, 0x9AEAFB930175EAE0ULL, 0xFB5F8C2CE33D0C92ULL, 0xDEED68952F2E66FBULL, 
            0xF0FFB9E5657F7ED2ULL, 0xC32E13266714D109ULL, 0xE357C1CE46618B3AULL, 0xB20F7402A1C156D7ULL, 
            0x6F460C14465B6CFFULL, 0xF1D10B4D0DD8A26EULL, 0xD94ACE32565110C7ULL, 0xF92C54F1BB10D652ULL, 
            0x2D7F4120C1020226ULL, 0x6C4A89A0E52DA843ULL, 0x82E236CB3FAF2432ULL, 0x0BC1198A1C828DCDULL, 
            0xAB8949A4B2C60BA3ULL, 0x6D05F86040DBEC5BULL, 0x0C79A150E5DA7DE0ULL, 0x90A34E1AA4D4F71EULL, 
            0x75AAE0EAFBA3F00CULL, 0xA1E882C259736314ULL, 0xF2C2D8B67261D2EBULL, 0x259D61334CE8F0B4ULL, 
            0x3D7DF7DC231E8676ULL, 0x35E8583F4F2B38ADULL, 0x3F0EEA3CF3B139B0ULL, 0x10B4E3AEADD1F202ULL, 
            0x3388A20139C2C6E8ULL, 0xDFA164F0C54BAE6AULL, 0x71FFC36286DF9ED5ULL, 0x2B34A94904973362ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeyRotateBConstants = {
    0x8D65D17A551A613BULL,
    0x3F08BD5DA01FC654ULL,
    0x52BDF9775D800F32ULL,
    0x8D65D17A551A613BULL,
    0x3F08BD5DA01FC654ULL,
    0x52BDF9775D800F32ULL,
    0x05F1D367298B06D6ULL,
    0x74784CA2F12304B0ULL,
    0xD1,
    0x9D,
    0x59,
    0x96,
    0x06,
    0xA6,
    0xF8,
    0x15
};

const TwistDomainSaltSet TwistExpander_Regulus::kKeySpawnASalts = {
    {
        {
            0x025E76C30B13A6ACULL, 0x9875B32BB15C947CULL, 0xFA4275B63C292C83ULL, 0x5D137BCBE4D4EFBBULL, 
            0x6064E0CB0BAE04F4ULL, 0x4AFCEE8520BDF302ULL, 0xF8D15200B65835DCULL, 0x5E0639880445AD82ULL, 
            0xA80BE4C1CA95688EULL, 0x5DE8293D414CC0C6ULL, 0x9D1185F4ACF3FD2DULL, 0x99E6C2A14FCF5CF7ULL, 
            0x9CBB82C42AAA7E97ULL, 0x91A9767BB8B7DBF8ULL, 0x2E9DAD66EA2A4A89ULL, 0x80656C0F4F0545F7ULL, 
            0xF0096D2BF31CBC6CULL, 0x456E31B8084B876AULL, 0xAB16AE96F6CD293EULL, 0x85E52893C58A216FULL, 
            0x8E0C202A964EC0DFULL, 0xE815DF201A82E641ULL, 0x1B63C8DEC0F0E314ULL, 0x96B738F55828738CULL, 
            0x1941DD8E6405CD1DULL, 0xB6C614530F0A78FBULL, 0xBCDC545B2ABCAB36ULL, 0x4CE9FB087E99EEB9ULL, 
            0x802228DFB4047A12ULL, 0x6748070347AF27E7ULL, 0x0B783FFE77A0F7D3ULL, 0xC0FC40E1EB49276CULL
        },
        {
            0xD20C31B90D3BA1B4ULL, 0x0697D95BBD737ABCULL, 0x760EA634E723B7D2ULL, 0x33B4E28575817C8FULL, 
            0x96583A14701FAF96ULL, 0x7E6A0DCF37526168ULL, 0xBF1903D4B4243709ULL, 0xFC312494112E4663ULL, 
            0x3A501C93149F5ACDULL, 0x18AAA32692B973D4ULL, 0x622D7E0D8F58E6F9ULL, 0x993A1DC8B8E32058ULL, 
            0x792E65091D819291ULL, 0x8D8B4C5BADC6D8B9ULL, 0x4C74979A99588D62ULL, 0xA4F7ED2DD20B2D07ULL, 
            0x8FF8F576CE7C6106ULL, 0xF096D456D3098F0DULL, 0x52EAD329A6C79677ULL, 0x69FEA63292B66E5DULL, 
            0xB744105CB0DA3EF2ULL, 0x99AF29506FFE6056ULL, 0x7E21CBEB62996633ULL, 0xC183685D5BCF6962ULL, 
            0x4CA28F37FE480EB2ULL, 0x3B9075563676F17FULL, 0x849DD4DDC1CED38BULL, 0x2B31C95BB7E63FC8ULL, 
            0x007A4ED9981CAAF1ULL, 0x5C18A7750ADCC90BULL, 0x2C00948651DB91E3ULL, 0xE64DED94B0DAD770ULL
        },
        {
            0x8FCB98D56281AEBBULL, 0x0EC5D3E425C53796ULL, 0x205B3AD931913922ULL, 0x02EDBE3196F8417BULL, 
            0x25F0BF8CB1D6CD60ULL, 0xDE96F7B76CF3255BULL, 0x8B77E35A22097942ULL, 0x0700B60784B14579ULL, 
            0x7ECC2776FD598CE9ULL, 0x917E2763A8195D73ULL, 0x4729D0175F3C6E89ULL, 0x3EEC9A78AEE186F1ULL, 
            0x071A5B7ED5D792B9ULL, 0xA503A03B35B062C9ULL, 0xF85E2DAE5EEB7883ULL, 0xC0D0EF2BB4AC2026ULL, 
            0x4E1258161A41658BULL, 0xEC465BE28CAA966AULL, 0xA06FC33C047986ACULL, 0xF1458F7954646661ULL, 
            0x2252FA462C525456ULL, 0x2AD9F3AAC9355960ULL, 0x4AB8270080D7D8EEULL, 0x7B8EFBB0C343EC6DULL, 
            0xE67FC5F3B02E9900ULL, 0x2D10557130CF76DEULL, 0xABD7A2BAD19D4EB3ULL, 0x5C50EFF3C2C55F3AULL, 
            0x544C662B96B200EAULL, 0x200D9A0273EC685CULL, 0x8C11B06255159034ULL, 0x8374A0C0F96660AFULL
        },
        {
            0x98B714842E06A4A1ULL, 0x61C6D006C89EC875ULL, 0xE716B90E4B532C1AULL, 0xE00C8A468397D7B7ULL, 
            0x73E64CB362E17F68ULL, 0xB224D5BB6E4BFAE0ULL, 0xDB2A5F35C7D471F7ULL, 0xD5DF12C5BB7C2BAAULL, 
            0x78E2D251FBADC769ULL, 0x762F50CE5FCA941AULL, 0xABA22C3660C6A627ULL, 0x66CFA3EAF7F15417ULL, 
            0xE0F1CD5DB1409320ULL, 0xE041C63F539CFCAFULL, 0x0B9E6A155F155E04ULL, 0xD9DE8001A32C9168ULL, 
            0x1C93F87E2A7CDB8DULL, 0x975267E8657952E4ULL, 0x9B9E4AADF9D75989ULL, 0x88FB9C79A7F37D4FULL, 
            0x1A86FE5BC9EEA63BULL, 0x9E3919A4D7D9322CULL, 0x932EBF42779E1D67ULL, 0xC96D4F41DE6A3691ULL, 
            0xAC2635E53CF15737ULL, 0x3CE87188939F2457ULL, 0x19AB752BAC0DD0F1ULL, 0x52C3FE6BFD08B4B6ULL, 
            0x4FFA7D0448F76B76ULL, 0xE05E5479E131BDCBULL, 0x7413F4C1D9D9417AULL, 0x57222D21319EFFFDULL
        },
        {
            0x1D7CF1D82DC1CFF6ULL, 0x508E8D352A6C5435ULL, 0xBB2D1506235DDFEAULL, 0x9718D2C10A16ED3FULL, 
            0x210990B112E0165BULL, 0xAD46595D6B91B732ULL, 0xA7141900A55F1903ULL, 0xB05B44D05653D6AFULL, 
            0xA56566EB640F8C9FULL, 0x0DB8BC1E7D879734ULL, 0x2259D5E08678A8A5ULL, 0x7DD006533CE0C035ULL, 
            0x5D702208E56F9BC6ULL, 0x5657301C3CC4D24DULL, 0x3DEED2B6C7C8A529ULL, 0xD23D236ABB126621ULL, 
            0xC486A9183AC6A8D1ULL, 0xC20545CB9ADE89ABULL, 0x3AC81889C1520E86ULL, 0x18617557CEDC6B14ULL, 
            0xE01415B0A1908A69ULL, 0x4B83CEF5F3092A82ULL, 0x87F4406AB7A5134CULL, 0x9428A3B83C8CA5FBULL, 
            0xD7C1AE6EC18A02A9ULL, 0x4EB6FF8D2F8B6729ULL, 0xBABB676FA4721A31ULL, 0x9C94744268C6165AULL, 
            0x1ECDA62872DCD20EULL, 0x043AF9B921B3038CULL, 0x00FBA8C7F84576A5ULL, 0xC7895BDDEFC194BEULL
        },
        {
            0xE847E8523126E64DULL, 0x460E40425318E66BULL, 0xDBFE18D5EEA811A2ULL, 0x6D998D1820F0B1FEULL, 
            0x1914532F61F24842ULL, 0xEFFB542AF2218A8FULL, 0x83F8412021FBDB2EULL, 0x65CC4E5B7B9BCC17ULL, 
            0xA8473E84200F4E01ULL, 0x61214B4508B885BEULL, 0xCBFFDA7C9DC7E19DULL, 0x02510C96DF8FD140ULL, 
            0x5215CCAB3BC9A17BULL, 0xE1B847EA01A26CC4ULL, 0xB057A02B380CF06AULL, 0x366862BB87741BC7ULL, 
            0x4CD133FFB9FC66F5ULL, 0x9CA4D78202C6DF9EULL, 0x71B2FAD1FC01DBFEULL, 0x985294D218AF3806ULL, 
            0x83DBC1AC96238E20ULL, 0x38170DBFF81E6E26ULL, 0xE571C3C1274CB0EAULL, 0x0FAF59FCEFFCEBF4ULL, 
            0xA0D1EB7FED9EECDAULL, 0x28555F3D21A8C561ULL, 0x71C835AA4BA8A705ULL, 0x4EAC1258DE72F888ULL, 
            0xF9608B9B24AF41A6ULL, 0x1B90227DF52AD48AULL, 0x357DEF894488342DULL, 0x71E3898F4A9A07D4ULL
        }
    },
    {
        {
            0x1D738BE52436E249ULL, 0x53150913F2862FB0ULL, 0xD45E099D49D3407AULL, 0x0E4C49F3CAA8E574ULL, 
            0xFDD989B9D11E9D9EULL, 0x56307B16DE842113ULL, 0xF288C344F1775550ULL, 0x994A7E92828C6B09ULL, 
            0x692A16701B89A5BBULL, 0x35A94567B2EC390DULL, 0xA3B6FD128D32B13CULL, 0xEF8C8C37FBBD2D90ULL, 
            0x572D91FD33E34EEBULL, 0x5832126FC2A13815ULL, 0x80CBBB7465FEA441ULL, 0xDCB081A44B7E36A1ULL, 
            0xC54A81441F5BFE5EULL, 0xA7083DC3D3E3127AULL, 0x1557EEEA5B260074ULL, 0xEDC5281C84B003A3ULL, 
            0x42F7E1F43CE618B8ULL, 0x400523619153BB54ULL, 0xEE95065D7E5E8EF5ULL, 0x49030922C4A89980ULL, 
            0x5B9805004E7B1BC7ULL, 0xC30CB034670430CDULL, 0xA90C20DCC8862401ULL, 0x96D51C994F26E2D9ULL, 
            0xFD3396E6A710BE74ULL, 0xAF51DB0497FAD00CULL, 0x0BDE28CBCA9D5945ULL, 0x890DB621FE538F2CULL
        },
        {
            0x16FDDBD6EC455E51ULL, 0x2DC1209EE6C46EE1ULL, 0xDFB5AD4C47245346ULL, 0x73A900F4BF12A75DULL, 
            0x645F3408E7FA8415ULL, 0xB00B48CC9C1AF24EULL, 0x5BC95F50A690D54EULL, 0xA7C7F2AC1BEA8C0FULL, 
            0x70DC5B51795204E4ULL, 0x83E5363AF6B27867ULL, 0xF0284FB43973A95EULL, 0x05D29598CC87ABE2ULL, 
            0x6A26454157668411ULL, 0x30212ECDC12695FEULL, 0x011CA44462902BC5ULL, 0x21530CA68B0530E8ULL, 
            0xE8EC263926670D45ULL, 0x4F9426526FD2C46AULL, 0x3D2967B7228440C0ULL, 0xC77A9F6F58A017EFULL, 
            0xCFE19C42196BE578ULL, 0x8157FDEB317E2BD6ULL, 0xAFE2BC7BC0EEFBE6ULL, 0x39E7429B84F33799ULL, 
            0x90F145CA3207D427ULL, 0xD4A0419E731F5AD0ULL, 0x08B3D7A28F3EA3E7ULL, 0x514AF12BC29C30FEULL, 
            0x7029C4FC0F69C0E2ULL, 0x4ACDC362A1A1423AULL, 0xBFC78582E4723948ULL, 0xB876A9C3D1223DD2ULL
        },
        {
            0xD27DB1A6B18C4108ULL, 0xF7BC96BAE21A2112ULL, 0x799322D7B5D0FF1FULL, 0x5CE5926A743DE271ULL, 
            0xF90ABB8A6EAC1A9EULL, 0x8DAB3B636B132F70ULL, 0x7C291E0DF8C064D2ULL, 0x1124C3C5E0EDB251ULL, 
            0x10B57A5FCFD341B2ULL, 0x285F101AD35C51FDULL, 0x996ED1EEDEE5F737ULL, 0xF8498E0B92EE8885ULL, 
            0x18763B58332CC49EULL, 0x4B758ADBC81C6776ULL, 0x595D6476486F860BULL, 0xA37AD14B11C912FBULL, 
            0xF749356D5010D26DULL, 0xDCEF3BE60BA0426DULL, 0x225D0EB2515AD63DULL, 0xCC8B6A2D3732F794ULL, 
            0xDFC2A8FAB2BD65D3ULL, 0x044B572DDE3B3036ULL, 0xA9B97007532EE932ULL, 0x5496ED1F4F949DDCULL, 
            0x926E5DC935D42057ULL, 0x818A76E38484D533ULL, 0x00F596F1780FD15DULL, 0x320B1BD2DB0CCE4FULL, 
            0x8EB41C4CBDC0EC16ULL, 0x21558B505C18E512ULL, 0xA2244037761AB82AULL, 0xA2E49258B94AA599ULL
        },
        {
            0x9AB9D4D53EDC18A2ULL, 0x15426F5C2970FA5DULL, 0x46B50B4AC0005B4FULL, 0xD6A107B8B63CF84DULL, 
            0xCA4E34DCDA27352CULL, 0xB3C7B27EA6AED6BFULL, 0x58A8B06E14B46499ULL, 0xBBFFD91DCD0A7099ULL, 
            0xF0CDD1335C5E001FULL, 0xD348EBBCF645C6D2ULL, 0xB6E3A9333BDDF8BCULL, 0x46EC9A3B48499BBFULL, 
            0xCE4031BB70BCDDD5ULL, 0x725F46E1AB129F53ULL, 0x15644DD57FDEC613ULL, 0x6E01221E86BD914DULL, 
            0xB15AEF909FB330E5ULL, 0x33DECB9EE9E96C26ULL, 0x4C5921B5D4B40907ULL, 0x891FEA0D3C6BEC72ULL, 
            0x65AFA5516E81CB7CULL, 0x4233A7C7BEAEEE04ULL, 0x7DCF3B48E3879EEDULL, 0xEA1BB05EC5DEA5E9ULL, 
            0x5DC4014DB92EC0D0ULL, 0x0A1B290EB62E9108ULL, 0x493DF8C6D35E7076ULL, 0x5B7EB6C4BF1C4F74ULL, 
            0xD7AA293B8812FBE9ULL, 0x2BBA8EEE3D4E2EC2ULL, 0xD0E382D69AA8E5CFULL, 0x0DD246E11C1DBF21ULL
        },
        {
            0xC252F90FDB527F6DULL, 0x4625A8D9D43462F7ULL, 0x93B2FFA4879BAC4BULL, 0xB9B6B4B0CBBF82B5ULL, 
            0x741F85EC71533938ULL, 0xCCFDF8E94E7E3D66ULL, 0x94661DA148612F8CULL, 0xE266B319495673D6ULL, 
            0xE28D0FD7E892C2F2ULL, 0x43BF19450F3B0C2FULL, 0x497481884F2106C9ULL, 0x2254847905AF858BULL, 
            0xDC845837D2D80231ULL, 0xF7AB25003558183FULL, 0xD22B5C46988947CDULL, 0x4588882CADBEC6AEULL, 
            0x77729FA75C2E7738ULL, 0x8E615FA8FF574953ULL, 0xAA884BE0999EFF61ULL, 0xE843EB2268E5DA89ULL, 
            0x63CAE9E9DD8BFD04ULL, 0x690E7CB17DDD03C0ULL, 0x0925B773885D82BAULL, 0xEDF5E2B19AAED857ULL, 
            0x506DF78C1B03A166ULL, 0x88F24A5ED560C9F7ULL, 0xE066A5104D38FBD2ULL, 0x89601E6860635C9EULL, 
            0x591B3C906DC47B9BULL, 0x2B2C7BDCAAB3B858ULL, 0xD080F1C8F1C0EF6FULL, 0x63FF6BBCC201E02AULL
        },
        {
            0x17EF5BCB3984E1DEULL, 0x31A0AAB7C82299BCULL, 0xDF84F8EBA96F6149ULL, 0x3694FB135D9D58B5ULL, 
            0xF0A868487EF23A0EULL, 0x083A7F88077A9AD2ULL, 0xE8F9016047DA88DBULL, 0x375F95604EB81E10ULL, 
            0xC0106DD3EFFB3107ULL, 0xA8BCE228B1A72307ULL, 0xBB8B3357F3170EB9ULL, 0x46E3D6B68F2ED594ULL, 
            0x7DA0D318D9D15E2FULL, 0xFDE6803DECFC392FULL, 0xAB87C0B7DB420206ULL, 0xC7B690BE06DA0A69ULL, 
            0x8290311694D79EC1ULL, 0x47FBE83F96E418B6ULL, 0xF91EF0C6BD8D276EULL, 0x916766A7F760F622ULL, 
            0x34C8948E5911AF02ULL, 0x7D20EF7E28D5939CULL, 0x823D56BEB2FAF5AEULL, 0xDF6564F8F2E39611ULL, 
            0xA0B0AABC1F9E1BE9ULL, 0x1552EB1D3CB2A9DEULL, 0x6264825F18FA5613ULL, 0xC5A8788DF94950BCULL, 
            0xE355F322716FB0F6ULL, 0x954384D4AF34FE70ULL, 0xA6E59F28B066696CULL, 0x22EF4B654F13F91FULL
        }
    },
    {
        {
            0x65D9BEB6320CCCEDULL, 0x0A78AD0B377731DCULL, 0xBE7966A6626F4EFCULL, 0xC0DFE4D942BFF27FULL, 
            0xA09A2DAF036D375BULL, 0xEAE317C584BD399EULL, 0xDE059A3081608CD7ULL, 0x26DD10926BB888D4ULL, 
            0x3ACAEA22252E45B3ULL, 0x35C9FCFAC6A1C40AULL, 0x68A53F0C6A07FC2BULL, 0xFDE01F4619F5344DULL, 
            0x3459EDB199E24E8AULL, 0x829B1FFF4C486217ULL, 0x19E142CE8BC1370BULL, 0x7C03E6D604FC8744ULL, 
            0x956264FD43A256D6ULL, 0x2DC0582E6C76825CULL, 0xED3A835987745FDCULL, 0x965F56BEE7B4AC57ULL, 
            0x20A8145E2567976BULL, 0x9116D60776BA4736ULL, 0xFABF3909B5208066ULL, 0xF453CC7A91046819ULL, 
            0x511E22C7D86FF110ULL, 0xD1EC1E51759C29FEULL, 0x5639A39A28A67EFCULL, 0xBE491558688C4263ULL, 
            0x1DA40D6C6355DB3EULL, 0xE48EFA4A5654007AULL, 0x8B65E48B620EF5FFULL, 0x1E519A1DBCBDE84DULL
        },
        {
            0xD5485BF56BEB3076ULL, 0x665D826C06F58407ULL, 0x720652D714E4BF3CULL, 0x0687974053C6F743ULL, 
            0x20147BAF435935BFULL, 0xD8FDCA63A76D9F1EULL, 0xCE9D640E2FE94640ULL, 0x6E40A565DAC90445ULL, 
            0x7A1A82C069A342B8ULL, 0xEE216883E428C07DULL, 0x13654741B2D445D7ULL, 0xABCEEDB5DA65BCAAULL, 
            0x5D6815206338B276ULL, 0x5E41097D18AC522DULL, 0x279787124BFDCF24ULL, 0x988ACA0C6E8895D9ULL, 
            0xF42B212F30721EBBULL, 0xC5CEFF22FCC70774ULL, 0x009ED23FDE8F55C3ULL, 0xE1190EE572CEFCDDULL, 
            0x5073D69210C33B43ULL, 0x4B75FF1FCC7163F8ULL, 0x85428F5CEE339FFAULL, 0x73793D2A5CB0A4FFULL, 
            0xC64ADA0439E47913ULL, 0x3429A9A0E4598B81ULL, 0xDDBDFD21C73BFF80ULL, 0x9B721B17A398749AULL, 
            0x6350DB473BCB846DULL, 0x3E22E8FD8CED46F5ULL, 0x25E68DCD5D27079BULL, 0xCD53379809B181BEULL
        },
        {
            0x87F8EE1C411B9A5EULL, 0xC5F6B56A7AC64F1DULL, 0xD48DB0017AED091FULL, 0xC6567521DDBE3B99ULL, 
            0xCF89C456308EDCD2ULL, 0xB59645529CC0E02AULL, 0x2B86E5587E760A25ULL, 0x050284563AE49E51ULL, 
            0x55D2F555CBFD1D3DULL, 0x8E295DEDA39933E1ULL, 0x668AEA053B97C557ULL, 0x71EF91BD14F5F7FFULL, 
            0xFEC54F3F3B2A2F3CULL, 0xA12FDA49C97C61F1ULL, 0x34330C6C602228EDULL, 0xDCDAB8D2B476531EULL, 
            0x4539877673FFCAF0ULL, 0x8DDBD2140DD4D104ULL, 0xE8E526D7F94F0D7FULL, 0xD2C47A9F31332E64ULL, 
            0xA1ED96F8D4CA7394ULL, 0x40639B2B345D53F0ULL, 0xA58720675E500031ULL, 0x25B5BF844E3EBDD1ULL, 
            0x9F4CC64B43915B88ULL, 0xAEC4918D6FB186F6ULL, 0x27A24C576D2EE1EEULL, 0x97EBDE36DD0121C1ULL, 
            0x576BC142FDE923EDULL, 0xEFA0E47A14C480F6ULL, 0xFEE30165850E3AEDULL, 0x8FA07FB0791D2426ULL
        },
        {
            0xC399CCD75C410A50ULL, 0x4D1AC368405068F2ULL, 0xB7EACF2D2BA758DEULL, 0xF9E28BB942DE26A1ULL, 
            0xD84FF7E70EC795DEULL, 0x2DCB7E01AE3920EDULL, 0x7C98CBC4356FE74BULL, 0x1A7D4303858F3543ULL, 
            0x60A736ACB509BB54ULL, 0x34F1677B0C263819ULL, 0xCB0217949E117626ULL, 0x7390DBA36B38C7C8ULL, 
            0xF2B406F76522B9EBULL, 0x4D04B9B91B39C830ULL, 0x2C80C22F5B929B62ULL, 0x3EF08EDB2057D311ULL, 
            0x1A2D88DD7B975E4AULL, 0x6F1DF10FE0F727B4ULL, 0x2D9E59996931F455ULL, 0xB55E93A1BB778E4CULL, 
            0x0AFE62DD795EC2F1ULL, 0x65F487CDB7D060A8ULL, 0xDFCA2F2929E6922FULL, 0x97840D8E0886982BULL, 
            0xCBE3C727C614277EULL, 0x813B010A84403934ULL, 0x5A71D5ABBE7CD899ULL, 0xA3F7A822F9DEE10FULL, 
            0x82EE2BD5D9191616ULL, 0x7F54F038228B2C9EULL, 0xC4D362715F3018DAULL, 0x0059CEBCFE6A1561ULL
        },
        {
            0xCD3B79F1D246A20FULL, 0xF424D637924FCD4AULL, 0x0A1F61DBCD457BF3ULL, 0x8BE5438AF47AC9B5ULL, 
            0x7D3DEF63F888421CULL, 0x17CB50A78356400AULL, 0x3BA56D63DE3E01B5ULL, 0x137C160902BEAD2AULL, 
            0xC58D100FE46E5688ULL, 0x3AC0FD5794409707ULL, 0xCFC739B7809A7259ULL, 0xDB436BAF806100ADULL, 
            0xC0914630D5EEE951ULL, 0x8ED088C56694B774ULL, 0xB76E051E5E502485ULL, 0x13E2176EC0AD6AA6ULL, 
            0xF1B595B579A8CC3EULL, 0x9096D81840D878C6ULL, 0x6137E362359833B4ULL, 0x7095BB7E077F9871ULL, 
            0x6A97CC7EA5B83B63ULL, 0x6E35490392CC10F0ULL, 0x9DFF18292CB45DF8ULL, 0x5A38C4C76101C60AULL, 
            0x7B76F6D280B5F194ULL, 0xC53CF3197582C768ULL, 0x5EC0597C7E4A4F24ULL, 0x392E4F2110CE6265ULL, 
            0xCE6D14EED9E91561ULL, 0x21F4C7B74C3BEB53ULL, 0x4454BC0B5EE9AD6AULL, 0x4AF11706157C2E8EULL
        },
        {
            0x8C97823C5A8CC19AULL, 0x7F814BE38360A422ULL, 0xE556B98995F3B176ULL, 0xA1129B0A076C022BULL, 
            0x92911808758696BEULL, 0xE3EB4F7C287B3B04ULL, 0xDB19AA043E4A5A81ULL, 0x5891F2EC57F9E3A6ULL, 
            0xE2A4B33FE619E4F1ULL, 0xFF14F6C10D83297BULL, 0x9705D2C878F49A6FULL, 0x9CCF555EC50209E4ULL, 
            0x9D813E5D71135406ULL, 0x22BF2FDC75285830ULL, 0x329BB7393C6C2EB5ULL, 0x7C6FAD006EB2C19DULL, 
            0x4F1BA5E8C135FAF3ULL, 0x2F14D828E1F460D7ULL, 0x2D562DD071213B9DULL, 0xD351280A17BE57BBULL, 
            0x5B5C04CA0743AA6DULL, 0x513375F9724B7B65ULL, 0xF51C60A660C763C8ULL, 0x344A9F93E3253CD1ULL, 
            0x59CC436E16FB695DULL, 0xE2EA78FC8184361CULL, 0x504D1F5AA7EE6C80ULL, 0xA5572CEAE94C6646ULL, 
            0xC179BA6DFF9AA433ULL, 0xFD59CF31675F9972ULL, 0x2CFFAD3E8B1A9A20ULL, 0x0CBA1B5C0C290E19ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeySpawnAConstants = {
    0x815EA29C44283107ULL,
    0xD550BA8B91DA0AAFULL,
    0x058F9F36835A6DF6ULL,
    0x815EA29C44283107ULL,
    0xD550BA8B91DA0AAFULL,
    0x058F9F36835A6DF6ULL,
    0x4E4E70AD711998B6ULL,
    0x9100632228489713ULL,
    0xFB,
    0xF8,
    0xCF,
    0x0E,
    0xCE,
    0x82,
    0xEE,
    0x05
};

const TwistDomainSaltSet TwistExpander_Regulus::kKeySpawnBSalts = {
    {
        {
            0xA243BD5395A9EF59ULL, 0x301512FD29D0F36EULL, 0xB0710AFD0A767FB0ULL, 0x11624E6B095AA192ULL, 
            0x21A1E6ACD5CDDCC0ULL, 0x7FF9CEF2A19AE43CULL, 0x76682FB0E60E3824ULL, 0x7ECE456482BEFCDDULL, 
            0x4653D9132260DFC8ULL, 0x28E673A713083E6FULL, 0x1867727856BA629BULL, 0x44B0C755668ECA90ULL, 
            0x1C3B5A49749B849AULL, 0xF5901E4B120669A4ULL, 0x9BA373902480687AULL, 0x5ACBF286E0418B95ULL, 
            0x54AE59AA5C094B46ULL, 0x5A46C167B9EEC864ULL, 0x15CDCB0D1A122E6FULL, 0x586C30527E9DBC47ULL, 
            0x30F4AB1566D57F22ULL, 0x20C8436843EE8744ULL, 0xD1B9BC1F37D084BDULL, 0x998E52C77A36E90FULL, 
            0x60AD8896AEAC012BULL, 0x354507C6142B04BDULL, 0x0369F31D877028A2ULL, 0xE01395D2391FB264ULL, 
            0x0F1C87A8084CE522ULL, 0x0CE5EC9E9F5565A6ULL, 0xA706BAFDF1BA9C45ULL, 0x2F012CF54A578FC9ULL
        },
        {
            0x016FC96F3A47664CULL, 0xD6093F6F8860F599ULL, 0xB34BFED75F9D0EC1ULL, 0xD4BD0D4C1FCFEBE3ULL, 
            0xDA2ECC069653CDEDULL, 0xA1DA95A994D37EFDULL, 0xE8DFD99339D7BEFFULL, 0x9218F7EC1A022A3BULL, 
            0xA3A113C1BE2F9F1EULL, 0x2703CBBCDCB5FB6BULL, 0x31CE5A0233F83FCBULL, 0x26BC4098821CA739ULL, 
            0x735F1A8229F97022ULL, 0x324D8B44D9118E19ULL, 0x7E2C853AD6988690ULL, 0xC4AB2863CA654B93ULL, 
            0x5E29F3BAE69DC71AULL, 0xD1546A4914297BE1ULL, 0x798AF9A1B99537EEULL, 0x693E4253163BA2DCULL, 
            0xB096367A4677270DULL, 0xCDB43F41920393D6ULL, 0x865F776A651D093CULL, 0x5A7F5B2A8997FC32ULL, 
            0x0481BA826B9DA1FAULL, 0xD89B80C66CC296D8ULL, 0x03950162BEE1CB94ULL, 0x808FE15C50D49B90ULL, 
            0x73127E7CD5BA9899ULL, 0xF20E2FEE2FDE7FE3ULL, 0xE626AB2699F6F182ULL, 0xB929C49319E2AA3BULL
        },
        {
            0xE5D2A6EA9EAEDC58ULL, 0x13E23A15C3AAE28BULL, 0x628993C5141DCDADULL, 0x796F4CCD44118A1CULL, 
            0x4A6AAE4E0EDA6632ULL, 0x3A3CCA3F2749969AULL, 0xE79A684DBEB5B670ULL, 0x56FBD277049E1A11ULL, 
            0x03B083E2B25D90EDULL, 0x72A979FE108F3F10ULL, 0x41D0258312D5D1B4ULL, 0x4468EE9C5EE34A16ULL, 
            0xB5D37B02A384CE28ULL, 0x7B5EC6F349529D10ULL, 0x7A40447BDFAB7114ULL, 0x6839D10AB5F283AAULL, 
            0x1C9169F22B800A00ULL, 0x20725F1F0D255905ULL, 0x85428F9813B9A7D4ULL, 0xDD6FA94E4C9845DDULL, 
            0x4861C87F5F7B2E5FULL, 0xEE55B972EB1A7B0AULL, 0x89C97DE534C96546ULL, 0x0A85E898A2D38A23ULL, 
            0xCDD9C73867BCDE3DULL, 0x0C97BF1ACA9C21CAULL, 0x1860C88C902F3B13ULL, 0x7DC220B7642EF786ULL, 
            0x8411AE0702257815ULL, 0xFBD32E77F7BF0D00ULL, 0x6A8A45BDF6566741ULL, 0x830F1F1B94389D7FULL
        },
        {
            0x1B0B374749A14E5DULL, 0xD2E27D141DEC89F1ULL, 0x771DCACE6086D40BULL, 0x547EE44E59EA90D7ULL, 
            0x77D428FFF25F06B7ULL, 0x11F1A87564720980ULL, 0x695EDA26E12C6C6FULL, 0xCF89FD36EE18944DULL, 
            0xA90516233E0F89A8ULL, 0xE5D0D99070ABC431ULL, 0xB71D90DCA6F32BF8ULL, 0x15144ADF4CFE4122ULL, 
            0x676458F304E906DEULL, 0x8F02D94D2584628EULL, 0x89381A6E55804241ULL, 0xC05265EB97DC949BULL, 
            0x426FED8576C95DF6ULL, 0x50D3FA271F3CE6DCULL, 0x675B0805333B30D9ULL, 0x0E0E1D3152139D9AULL, 
            0x5C0963CB0FD10C99ULL, 0xF0B5F8872089BA0CULL, 0x11F05B865796CDFCULL, 0xFDF1010C16C22DEAULL, 
            0xCE64FA8272B26BFAULL, 0x039451ECC94ABD38ULL, 0xB0EBFDF9093BB2A2ULL, 0xFB6D4B85A4B33ACDULL, 
            0xBD149C49A53E5AACULL, 0x866D68852C010FE9ULL, 0x7D26AF706F6C6F58ULL, 0x92D1ADD1F8BD7D7AULL
        },
        {
            0xFE56F03C5572B360ULL, 0xBF098E62D8C8676CULL, 0x41FFE8978A1660FAULL, 0x8F5DE837307A6591ULL, 
            0x2BD8BC08F7576824ULL, 0xB0A8AB3F236FBB70ULL, 0x5747CFF3069124F1ULL, 0xC7AA33D484A49F79ULL, 
            0x82066E483165F6B0ULL, 0xD8B3A7EB3FA95593ULL, 0xE1FD9D8AF9B59EC8ULL, 0x83E0F49ECEF118D0ULL, 
            0xD26740C53DAA2017ULL, 0x4ACB6D4C78710245ULL, 0x77301D2A30987B5BULL, 0x2D1A220AC32A5DC5ULL, 
            0xC4D62A9284A82841ULL, 0x1AE3B17999844FEBULL, 0x189932A02DF38882ULL, 0x5FEE05B3080CDEDAULL, 
            0x479A6F41C909A535ULL, 0xD27D15E2B8C6390AULL, 0x4818F29827FECA1FULL, 0x9209303E4E735F0CULL, 
            0xFBDA193B0CB46438ULL, 0xA6E9E02DEE0B3379ULL, 0xF257A2465F017DF7ULL, 0xE6F2EBB6B9BA2900ULL, 
            0xEA6F05D19A8060CDULL, 0x40E18E42C11FB7A6ULL, 0x3B8731C65B9C1F3FULL, 0x733A082CE026F3FAULL
        },
        {
            0x120925DD9B879FB4ULL, 0xF99DC5AA59D0A501ULL, 0x4CAE8132DBEFC079ULL, 0xB70C47C0498B45C4ULL, 
            0xCC90390DD171E2B8ULL, 0x23892A897041F3B7ULL, 0x93A4362C09CB08D6ULL, 0x18F621DA25287940ULL, 
            0xEB3FAA5FB5D69633ULL, 0x41C66E938E52E2DBULL, 0x2327E4548E3300ECULL, 0x3FFE7964670B305CULL, 
            0xBEAC4D7934F93E05ULL, 0x3A67F586F26856AAULL, 0xEDEEFE778AF03C77ULL, 0x146FD32660EF3A9EULL, 
            0xA679C5AB9A7D1F43ULL, 0xA80F01E863997A07ULL, 0x636130C6B9DE88A5ULL, 0x401661A241D60FBBULL, 
            0xF0051FA5FB67E542ULL, 0x1337D3168B46D7D5ULL, 0x05E3966DEA2E4D2FULL, 0x25E54F8102892854ULL, 
            0x0699275FC834501DULL, 0x785BAA092795E04AULL, 0xC80A8F9A8A56C447ULL, 0x5F4A667608A80D9AULL, 
            0x57FC7BC491FC9252ULL, 0x53D62914C06BE781ULL, 0xD487F5EA48C2BAD0ULL, 0xC972426FA03E7036ULL
        }
    },
    {
        {
            0x5B6792AE7FB90314ULL, 0x9426589A17AF8DA3ULL, 0x087F8DA76171FC5DULL, 0x42AB507B4A868F85ULL, 
            0x56A044F35D402248ULL, 0x6A0D70E42F96010EULL, 0x66AFCE4FE6B8A048ULL, 0x5B5CD47E0F36FCD0ULL, 
            0xBDFF44C69E062C9AULL, 0x7E2407F90663CC2CULL, 0x5786FC49101A0A84ULL, 0xC7688F45771B1C97ULL, 
            0x7F3091876C717B3EULL, 0x52E084DBB2D59045ULL, 0xCED5D2A921D48A29ULL, 0xB4AF065CCC3CED40ULL, 
            0x92EBF66A39B7B053ULL, 0x1DB8CA11D8619909ULL, 0xB6BFC554D00ACF09ULL, 0x20CD9DEFDF4A71DDULL, 
            0x23823B1FB73E4769ULL, 0x8E06DC96E54AB224ULL, 0x23674C34A4CCC7B0ULL, 0x5907FA7A87BFBEE5ULL, 
            0x6D14DD3D20473AE8ULL, 0x3363204D2201C0D4ULL, 0xB8A4DE86C6F8DE90ULL, 0x87C8195A5F608259ULL, 
            0xDA8ADF42BB561C7AULL, 0xA94BCB8D097543BEULL, 0x280A8E427CB36576ULL, 0x7BC5B2F860380358ULL
        },
        {
            0xA23C322E81126755ULL, 0x099023B1ADB8712FULL, 0xE80033E3B94C1DF5ULL, 0xCD972E120975B00BULL, 
            0x67B8A52E21F14B5FULL, 0x0D64C4D2C538F751ULL, 0x15FC736C50A336EAULL, 0x64B2BBC027EC61D1ULL, 
            0x0816132E76902C69ULL, 0x49B06C78CB949A2AULL, 0x307DAD5750322262ULL, 0xDA9511E2DD026BD6ULL, 
            0xB85B99D12D76943FULL, 0xEFA171F111078AA5ULL, 0x9732E0FABF70933FULL, 0x3EEA82A469E4743FULL, 
            0xB589467A81321148ULL, 0x2FB09E4918B5A86CULL, 0xA5FDDF71546BD991ULL, 0x0C1BBD3552146A5AULL, 
            0xC88EB41C088E5180ULL, 0x4F2DF164D6C8B5BFULL, 0xB063F2875CFD39FFULL, 0xFB7FB4A14758060DULL, 
            0xEB1D8B3564DD9CF8ULL, 0xCD53FE3C1B0F8D04ULL, 0x0469E542694B6C82ULL, 0xD394683080FF982FULL, 
            0xBCA947F3E3A24732ULL, 0xDCDA884187992DF3ULL, 0x9FAA814B869B20F5ULL, 0x71DF9CA0B8A2692BULL
        },
        {
            0xC537781BAEA56D9BULL, 0x7EC5A570093B04FEULL, 0xFF1B36018AE93383ULL, 0xA320E2FF604E7DB4ULL, 
            0x92D6F1D46FDB8EA8ULL, 0x99B9C8BAD90772BBULL, 0x5732530B899B21CCULL, 0x1C7BE0841A495FE1ULL, 
            0x7EB58A76F22D9EDAULL, 0xB022D71E3716A873ULL, 0x3E885E976DD15013ULL, 0xE3A52A4A6CDF660BULL, 
            0xFC2F921BD86A2850ULL, 0x57071E161D791FADULL, 0xD26B34A07DAB5680ULL, 0xC7F6845A81B2AD82ULL, 
            0x85C46FA4C7051B0DULL, 0x52F58D4E66F5586CULL, 0x834DFD9CECECD1D7ULL, 0xEC86B9C308D1E78DULL, 
            0x6A246A4F275C12FEULL, 0x9658585622BD0517ULL, 0xD5CF5BD648FB4A29ULL, 0xA1892368DB4EA20EULL, 
            0x544342E9C2225FADULL, 0xCB83D4F4AFE0FA8EULL, 0x7D8357201CEFF366ULL, 0x1908B81217007B71ULL, 
            0x3670FAD84535D0F2ULL, 0xFD68F64BDF048CB5ULL, 0xDE6010C21C8EC36AULL, 0x4001676835598A9EULL
        },
        {
            0x5E3FE94B35571DA9ULL, 0x8E4EF3510DB643AAULL, 0x3B6E67ABAC59FD83ULL, 0xE8BF577E783F620DULL, 
            0xA4ED4EF6C34AF837ULL, 0x617C9EA6931DB36AULL, 0xAA09B7B9968C270EULL, 0xD15D596EE2991385ULL, 
            0x78B8D2A82ADCB18EULL, 0x30EEE84BE6EDB03CULL, 0xF1AE3B581C80F11DULL, 0x2A8DC047DAD9FEC4ULL, 
            0xE2C24CB961BA5498ULL, 0x4C494435C3EE4159ULL, 0x80F213F1C78B824EULL, 0x386E8F4734FBC040ULL, 
            0x9DFE97091792C92AULL, 0x289A078DDB6EB689ULL, 0x830C63ADB4B6676AULL, 0xB366FBDBDE73B1A9ULL, 
            0xE02DC83148B1839AULL, 0xAE1EF39807ABA0ACULL, 0x52E9F1A4B7D837F2ULL, 0x730150026256F6CEULL, 
            0x6496944F86066C7EULL, 0x58A73E8571B186FAULL, 0xD67FD4B0C630C827ULL, 0xFCA2EF58A20D03CDULL, 
            0x43318CAD7B3E6D17ULL, 0xA8E818681D0059B9ULL, 0x98CF62A355B9B1E0ULL, 0xA3DB75FA170C3D62ULL
        },
        {
            0xFC7F94D64C033FC2ULL, 0xED5BBB5D30C3B5C2ULL, 0xD4669688EF1FB2AAULL, 0x65855AA12434CB50ULL, 
            0xE26DC63158614B04ULL, 0x1F5F7DBA123B7D6AULL, 0x320037E7317D9DF4ULL, 0xCFC32699D2EE0002ULL, 
            0x603EF02246627678ULL, 0xFC9D68723E22A673ULL, 0xCB9D371503FF855FULL, 0x73AF2861B9374972ULL, 
            0xD8B3C87241272CBCULL, 0xF6788A650CE433D9ULL, 0x667692494C71E875ULL, 0x139612254B0B9B65ULL, 
            0x1894E6C64479AC22ULL, 0xD128CC3ED8878E98ULL, 0x079A3164A903203CULL, 0x44B7C378C3BA4686ULL, 
            0x8A22BEBDED48D0C3ULL, 0x02E3377896005877ULL, 0x055D4FE85C95BB88ULL, 0xF1ADBDB6842F00EEULL, 
            0x066C447ED03A1B1DULL, 0x47DC231C1566366FULL, 0xCF2232C4A79BD770ULL, 0x9FDCAD957FA7E7B2ULL, 
            0xF0517C338604C67DULL, 0xFCBBA3CB863D44ECULL, 0x31DFB204D1932503ULL, 0x37D12EF7F6D959D4ULL
        },
        {
            0x95AADD5F70DBD5FEULL, 0xE13D860D981931A9ULL, 0xD612F42109BF68AEULL, 0x7047E41B50CE36BAULL, 
            0xCFAF50E416D640CCULL, 0x0B151CB332934002ULL, 0xB9274A90DA9037F3ULL, 0xCDC92A9DD23755E1ULL, 
            0x44688E73C93C293BULL, 0x7E6E4E54C362B70BULL, 0x46B665DE4DA74B30ULL, 0x4C29FD3C8A5D2164ULL, 
            0x3D5A6A6BE305D5B2ULL, 0xEC4530AFF942A680ULL, 0x771226753AB89E50ULL, 0xC0FFA3ADA7174258ULL, 
            0x505BEFCF22F82459ULL, 0x2568E6167269CE68ULL, 0xC7190CA388F3DFB0ULL, 0xD32025E06ADF1CCEULL, 
            0xDF74D7B799317DB1ULL, 0xC7A0EBB9980B8FC5ULL, 0xE62E4877D3D9F76FULL, 0x11443BD88231CD26ULL, 
            0x66FF4C18E215FB02ULL, 0x775010621B27B531ULL, 0x1C7062DF951670C4ULL, 0xA81DDAA974D42FEDULL, 
            0x87760DC82C922ADBULL, 0x555F55706F0EC595ULL, 0x2C646B8AEFF555E0ULL, 0x1582C5038FDDAD1CULL
        }
    },
    {
        {
            0xC9800B17B6327E1CULL, 0x74B7953734D58CACULL, 0xF925870A312AD0B7ULL, 0x5BD23CC835C5DDCFULL, 
            0x31B739668628AA6CULL, 0xE5D2B87870EBB09DULL, 0x9D2650EC66C8617DULL, 0x875449A6365EEF86ULL, 
            0x8112F7DFAC7DF225ULL, 0x5AB9961A491A8F0CULL, 0xC6724EE098E45486ULL, 0xBC434D9A27AAEF8AULL, 
            0x231AD15CF3C5D44BULL, 0xD39B76C8AA855AD5ULL, 0xC2F934CCF520C4DFULL, 0xA2AF2080E448E582ULL, 
            0x8F39D2E19518B8D0ULL, 0x41C0EC3479C504DFULL, 0x153371663420D5FFULL, 0x782920A7C018A777ULL, 
            0x891E29188EE35236ULL, 0xC328FD1F9062A53CULL, 0xBE2836F57FF6BD2CULL, 0x62439F19B8BB81D4ULL, 
            0x4344E86EE9CA673FULL, 0x88090C59B0B07F49ULL, 0x213FE7E7616E18D4ULL, 0xB1B46FC4F6AE6CDEULL, 
            0x6E987942C3265EE7ULL, 0x9214D5280FE13D95ULL, 0x2B45407B016755A1ULL, 0x3E3D9C6F49B2FBA9ULL
        },
        {
            0xAE47A06ACA77AFA9ULL, 0x1EB13F769DEA17BFULL, 0x83D991B21E4AD1E2ULL, 0x1A33939569846737ULL, 
            0x9CC08F65B3B169B7ULL, 0x0CBD5C6B93166D0FULL, 0x9C5B42A59CE2E94EULL, 0xAA62F9E8FD0F2763ULL, 
            0x710E66DC2CB63964ULL, 0xCCA7384F4E50513DULL, 0x085F58C2C419CD1BULL, 0x5CC3CF0037702AB9ULL, 
            0xD1BC194CDBA91D2EULL, 0x5DDDC50AFF9FA62AULL, 0x723F6B314A40A475ULL, 0xEFF46C1FBF7FCC52ULL, 
            0x7C3787029BD4C8E0ULL, 0x78719A49A11775B1ULL, 0xF4595B96ED446F8AULL, 0xE675A805355E29F5ULL, 
            0x28776A15DD6AB6F2ULL, 0x18C1DA634D7E92F7ULL, 0xCE7426286890CC5EULL, 0xFFB7EDE6A1B7DCE5ULL, 
            0xB574B79B7B00F0A0ULL, 0x330D8C74E420EE09ULL, 0x0C19C32246A58AEAULL, 0x37CA3CDF6D6BE93FULL, 
            0x78EF11E424E01D6CULL, 0xA101BBEC58624BA0ULL, 0xFCACA6CCDC6E9BCEULL, 0x309B6D8B800EC38DULL
        },
        {
            0x84076C6D4A560987ULL, 0xFAF8A8C39C049F19ULL, 0x5877C55B66C2E05EULL, 0x6E866FD25E960C7CULL, 
            0xC3D767521B475BB9ULL, 0xB4F5173666C8A8E0ULL, 0xC691530C1844D592ULL, 0x5F884B69EBBD1576ULL, 
            0x67B5FEF992A4D9F0ULL, 0xE684876F073A1A98ULL, 0x8A46B83246BDEC39ULL, 0xC042EE8891CBCE1AULL, 
            0x9E13A482EE757872ULL, 0xFDE72C36509912ADULL, 0x9ED5DBE87D1B0732ULL, 0x9785397A15BA63ECULL, 
            0xA04B3409464486FDULL, 0x4C05AF566A0B9B89ULL, 0x0EA5EBB87F575A13ULL, 0x8B53D3E2D15F0514ULL, 
            0x9992D35D881AEE91ULL, 0x94CFDA2CEDD5DF50ULL, 0xEEEA1696D62AABBCULL, 0xA05EEC049D1087A4ULL, 
            0xFF1B46C91CE2D141ULL, 0x91714F3649094923ULL, 0x46948B10DFD61D1DULL, 0xC62DD7E089191F09ULL, 
            0xCDD0154B1E51CD1BULL, 0x6556736814214F87ULL, 0xC5E5C522DDC88A59ULL, 0xE6142848AC7E2964ULL
        },
        {
            0xC321C9A2610BA072ULL, 0x4E8D1BD6CEE01E15ULL, 0x2CB7F5E609872198ULL, 0x8503D7AE55DD5896ULL, 
            0xF6D2E9AAFA367E6DULL, 0xD52E06C6BE1B3BD1ULL, 0x2398BA815C3945D0ULL, 0xB915E2D192F5AE71ULL, 
            0x2232A0D3368744C2ULL, 0xE16F1BA99171E077ULL, 0x4F848A1B34821B73ULL, 0x9F1D46D8619F4F6FULL, 
            0xFF6268E8D665538BULL, 0x55955D204760CC6DULL, 0xFA6610F79DCE8C1BULL, 0x313639B177811F79ULL, 
            0xAB1616D6876D7AC3ULL, 0x2E99DC1161E8B4BCULL, 0x352EAD7C85CB43C0ULL, 0x7032ECE3885DEEEAULL, 
            0xCEFCE30CC9F94F20ULL, 0x38373796C8E61B93ULL, 0xB5B72F72DDE92B9AULL, 0x9717F453147DDA0CULL, 
            0xC2938776614EB138ULL, 0xAB914AFE70F648CAULL, 0x2952E519B1A8616BULL, 0x51B2525C90F907E0ULL, 
            0xBA085A105A6943E3ULL, 0x212587E8FC2A12C8ULL, 0x12BC8C5B55647F14ULL, 0x45C0A48CA1AFB3A0ULL
        },
        {
            0x09F77F2BF110294FULL, 0x823CDF7728262AE3ULL, 0x244EDE2D4CC293B8ULL, 0xA05740D842F27DB3ULL, 
            0xD4BF92C39CF35C73ULL, 0x29E1F94E9907ADFCULL, 0xF56C180C48C054C2ULL, 0x4D9D539CAF332EC2ULL, 
            0x5B14FB509F8F34A3ULL, 0x5401EC8BE63F9D23ULL, 0xFD12C6AA598C8982ULL, 0x11ED620D7C99630CULL, 
            0x9341D33C02AF60C4ULL, 0x98D4E17B0886890DULL, 0x634AC31B4640D47FULL, 0x16DD66E5DB0188CEULL, 
            0x501AC2B99F9B8005ULL, 0x31EFD8E6F4F68F62ULL, 0x6DA8BE657EB24815ULL, 0x6C15DD299E63AD84ULL, 
            0xB8E7300CAF0D0F7EULL, 0x14043E1C827B7988ULL, 0x0E62A4DBF977AAD5ULL, 0x78AA213925F7A3AFULL, 
            0xF254CC1F7AAC4AB7ULL, 0x08706F10E250C84CULL, 0x29469E368F844173ULL, 0xA63084844E750E32ULL, 
            0x16AD4259FF226443ULL, 0xFF3E09A24C831E71ULL, 0x74943EE0375EDE1FULL, 0xBC8FC0BF3B8BA2C7ULL
        },
        {
            0x76E2DC3D1D884560ULL, 0xA3D89CD57B3FD52CULL, 0x14E4A7D01A51B7EBULL, 0x81E55F932BAAD85FULL, 
            0xCE9B2179159CE7A7ULL, 0x354B073CD0ADC534ULL, 0x61A3DB1B48D1E7AAULL, 0xE0D0F6E4505BB3A4ULL, 
            0xADE76D5225A9CC3FULL, 0x1FCFE89B4DC2B25FULL, 0x2DF2CAA151615D78ULL, 0xFA4E615E3F66CF67ULL, 
            0x9A5081285D3A7CB6ULL, 0x1BC7811D8C750B1AULL, 0x73CA8257DB918235ULL, 0x78D3F57E1CBE5317ULL, 
            0x8A875E904CF5C319ULL, 0xFEEBDA73FDA8D7F4ULL, 0x44C76DB82625369DULL, 0x88D053EB8969E646ULL, 
            0x5E278A970DE5B387ULL, 0xE3E9CEB366C231B5ULL, 0x8F76CED7EF70516DULL, 0x4A0BADE341F90EBDULL, 
            0x3B626F724FF7532CULL, 0x5632B06EF11A8A8AULL, 0x394EE6DCF63EFABFULL, 0x3D8ED094A4032341ULL, 
            0x6E332935714672D2ULL, 0xDE27F5640535AE96ULL, 0x58C7AD5DBE95838EULL, 0x7B0ECDBC91B2F8C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeySpawnBConstants = {
    0x31DB0DD458CABF75ULL,
    0x8D07632B7486CADDULL,
    0x20759B2F8F3C45D3ULL,
    0x31DB0DD458CABF75ULL,
    0x8D07632B7486CADDULL,
    0x20759B2F8F3C45D3ULL,
    0x8CD889C04F819ECFULL,
    0x42CF8F4FF7FF7FC0ULL,
    0x43,
    0x89,
    0xEB,
    0x9F,
    0x1F,
    0x2C,
    0x50,
    0x6E
};

const TwistDomainSaltSet TwistExpander_Regulus::kSeedSalts = {
    {
        {
            0x14F3F1C23E74F977ULL, 0xE1DE0DE5CF519FF5ULL, 0xE2731FC0D7A4FDC7ULL, 0xF8EC278388FF12A1ULL, 
            0x1E38654B70C944BEULL, 0x738EBAAF82411817ULL, 0x7799342F910CBC6FULL, 0xD435CCBFC5C14F5BULL, 
            0xD82C522263C6FEBDULL, 0xB4B964B4A2BF02ECULL, 0x95708B562D5364E1ULL, 0xFE8313192A0AD5D5ULL, 
            0xB187CED4FF15F35CULL, 0x9EB402290475B316ULL, 0xA8E8C0F6E573B0EFULL, 0x66BC091562C0101FULL, 
            0xD787529F29B5B748ULL, 0x0B395A2F68FE2DB3ULL, 0x256A2B085071A238ULL, 0x959190CEE4679C25ULL, 
            0x180A86F3C13D36C1ULL, 0xACD81D03F9D7627BULL, 0xF74FF8E45799F82BULL, 0xEE94AF8F8E706ED4ULL, 
            0x00CF17AC9A88200FULL, 0x1920A4862E412CCCULL, 0x14B6982275EC1164ULL, 0x2032DF261A32E420ULL, 
            0xCB376EB2F6CB8373ULL, 0x1009A6767EE94973ULL, 0xEECEFF0D745C24D3ULL, 0x6471A188E5AF79B4ULL
        },
        {
            0x95425CA71255E796ULL, 0x5D5E4214F42B55D5ULL, 0xDF447ADA885B09F4ULL, 0x7B0FA05D82C0D433ULL, 
            0xDF94A17C6209387DULL, 0xEC69AC5DEBCC1618ULL, 0x7E04BC31AC9FBE8BULL, 0x2E04F4504ABFBBBFULL, 
            0x763B7F5B40B24F9BULL, 0xA88558F646CF3325ULL, 0xA7EE48650A4F18A0ULL, 0xFED899CF48B96F3AULL, 
            0x2D30C91BCB4C1A3EULL, 0xC6AB83F2F47FC843ULL, 0x66A9F2DBBB876F20ULL, 0xD1BF2F31482DE082ULL, 
            0x2E9FAD08C24409BBULL, 0x44BA82F4D1070F9BULL, 0x3A6C5663DCE85088ULL, 0x3A04F24A67492F39ULL, 
            0x799308680DB1B891ULL, 0x3A69752D40F63EFFULL, 0x39972B72F50C1919ULL, 0x2EE0EC980F085ECFULL, 
            0x0D0DE7F59817BA3EULL, 0xAEA426B732CA73ADULL, 0xF2BA5B89386120AEULL, 0x2323DC1FC857FEC9ULL, 
            0x1F58B576C827523FULL, 0x56E1E26161AAD7FAULL, 0x8E29981813996085ULL, 0xF12DC7E8727211F9ULL
        },
        {
            0x62EE196A91003E2DULL, 0x954001A0894CB186ULL, 0x7B300F40CF55FD0CULL, 0xA619678C2377EB38ULL, 
            0xA1D7DFE851477A5EULL, 0x595DEA9E0E805BF9ULL, 0x9403F6B49F52D875ULL, 0xA71435102515D6FEULL, 
            0x8F88CB722507EDE3ULL, 0xF33F0DFDD238D1D0ULL, 0xD2B69C9481302B01ULL, 0x359F16306D98D36AULL, 
            0xC32EB9CED1F722A1ULL, 0x81C4F7758B62EF90ULL, 0x7529603CC453E98BULL, 0xADE036C0C402C271ULL, 
            0xFB84FEBCCD42B162ULL, 0xBCC70B2C93C7EEBEULL, 0x0821992DA00FE981ULL, 0xAE15A48B945F2D57ULL, 
            0x6D0C572CDFD557C5ULL, 0x33BAEE336573BBF0ULL, 0xCAF4883C0BC18739ULL, 0x0E1F4D9F37BE70B9ULL, 
            0x23B485905774AF3CULL, 0x28CBBE26EDE4CBAFULL, 0x952C4B788B7D275BULL, 0x4D644964DAD609AAULL, 
            0x8725447F52548125ULL, 0xFC8AE02B5F877327ULL, 0x5DBF3AD7EFEA3CB4ULL, 0x562855A5662C68ABULL
        },
        {
            0x636D89B9F551B410ULL, 0xA2F1E5E797D3C255ULL, 0xC79DD97EB5379FF7ULL, 0x68D84F7A7603AF25ULL, 
            0xD1CF7E3430622D19ULL, 0x8E2C559477869276ULL, 0x91C5972505ED112AULL, 0x57321C03308FD9D2ULL, 
            0x133079F68DEA8536ULL, 0x2FF755CCED534004ULL, 0xC91A9D0F34900ADCULL, 0x309363C571548877ULL, 
            0xFFA4480C3C81A904ULL, 0xC5863E4DF1C4E799ULL, 0x5FD2E72C55E48DF8ULL, 0xC86064C607CFD952ULL, 
            0x55261E4667F4D96DULL, 0x501A538311262508ULL, 0x39A40E511CD30125ULL, 0x00C3012566501E03ULL, 
            0x8FC84201E3BF3FB9ULL, 0x69829609240DAC99ULL, 0x59D2CAE6738CC596ULL, 0x32BE67B9590CA915ULL, 
            0x3A07E7C5E2973458ULL, 0xF39C0ACC2703B9BAULL, 0x9047A263007913DBULL, 0x4B943F22098FCCFDULL, 
            0x922A6684A366C9C4ULL, 0x14E52131E5B7859CULL, 0xC9F1F64FE206AB71ULL, 0x1E7238EB1B18DD95ULL
        },
        {
            0x04817BB6EC7530BAULL, 0xDD71655D98B34855ULL, 0x21978BDD94DCEE8CULL, 0x8896280D3D0EB2F7ULL, 
            0xD0844CAAF6CAC77AULL, 0xDC01200457ABCD88ULL, 0x6B87DB167B57CCA1ULL, 0x1A158A4A7BEAA233ULL, 
            0x50EEBE6CF4825B3CULL, 0x60B705796EE13F72ULL, 0xB09363DA13578976ULL, 0x2AB3F87E49A049D4ULL, 
            0x16BEC3B97D73FE99ULL, 0x4E4D8896127DCAF5ULL, 0xE696EB6A1AE923B3ULL, 0xD8F0E925EC68651CULL, 
            0x9BE983260F7297EEULL, 0x7BBAADE0B6F6FB8FULL, 0xE507EB578484605AULL, 0x13472FF49C4BE9C9ULL, 
            0x9FD43050824CF4E7ULL, 0x5878DB46475279A1ULL, 0xC3754CA29A8CD3A1ULL, 0x01949094F3C6A620ULL, 
            0x26D9FDAC41CA1E16ULL, 0x33D61E6E64FDBC14ULL, 0x14E624301F9C44A1ULL, 0x962807A877A5D20DULL, 
            0xD0F5D038962490FAULL, 0xE1A38E285B69B6F8ULL, 0x15D10BDE39DBD3B4ULL, 0x7ECF4B833E1CFE48ULL
        },
        {
            0xF3E6605898978AE9ULL, 0xE84C34D9342C65F7ULL, 0x4971FDD335E884F3ULL, 0x6BD882B6F9ADE1C1ULL, 
            0xC51FA12632BD4BE0ULL, 0x67ECD28C59DE4932ULL, 0x3E821E853F77C8E1ULL, 0xF5BC00489C67EF42ULL, 
            0x08177B36C3097105ULL, 0xA0C9F03A10AABB2DULL, 0x22B04172108D5C40ULL, 0x5B6160C2CE9CB887ULL, 
            0x33C21192EF7C6876ULL, 0x4CE81FFC97537202ULL, 0xD0AF80555FC5ABE1ULL, 0x969C80D340673B7DULL, 
            0xE8D9F7F2B60300A4ULL, 0xC905DE4BA9FEB1A5ULL, 0xA512CDEFD669F2FAULL, 0xD04952551A4D4CDBULL, 
            0x451598133582D315ULL, 0xF1957EAF0ED2168EULL, 0x4DE68C5D5B5BC19CULL, 0x62287E7817B67F06ULL, 
            0x53C3D9127809E132ULL, 0x0DC736689CE51A50ULL, 0xF435D0F41ACD9E59ULL, 0x06533A3251912B9BULL, 
            0xA2349E720CF0223BULL, 0x62715497F7E65CB6ULL, 0xEAF539BFA775D7B8ULL, 0x83BC611B08AE1A01ULL
        }
    },
    {
        {
            0x1C90BAECDD1C6629ULL, 0x47601DCB1C1494D3ULL, 0x86909BC9DBC41664ULL, 0x69A895E1F52A32C3ULL, 
            0xC8ABDE8FCFC89DADULL, 0xE9228C3FD1444D8EULL, 0x9619A3A7A569C4C7ULL, 0x1733156A4FB18456ULL, 
            0x22D1199BBF0B5E79ULL, 0x7077455536F821FFULL, 0x33BDF05E04F6EB4FULL, 0x25A065F080B1B36EULL, 
            0xD7E086BCAE212F16ULL, 0x015D772842C64F08ULL, 0xB56C1782F999893DULL, 0xD5FE89D3B0E38DECULL, 
            0x10E05198257C56CEULL, 0x351F65024E91A140ULL, 0xDD48ED2489C54DE9ULL, 0x5774A3B2CEA7FE0DULL, 
            0xA9971C9EDEA64712ULL, 0xC58F785F009DB506ULL, 0x8F179C34E84802FAULL, 0x26F3244D2467B3E7ULL, 
            0xB8A8995B3EAB5C4FULL, 0xEBFD18781DE45CFAULL, 0x1CBB9967860F18E3ULL, 0x726310C6D5BB189DULL, 
            0x8E459A01B954CF2CULL, 0x6D7D7F22B0D508C3ULL, 0xB51983D54424AB68ULL, 0x55B848B576D54368ULL
        },
        {
            0x4FADF86F786BE3EAULL, 0xEEA5F28F7CCC2575ULL, 0x10B12C0096647203ULL, 0x47B42C0E9F289C6DULL, 
            0x403B1F5C7B2E9F47ULL, 0xCDCA5DEC1AF307EAULL, 0x899F392E3611F125ULL, 0x37CEC757FAF99240ULL, 
            0x54ECB8AD9ED6B741ULL, 0xAADFAB05CCD48175ULL, 0x2BD750471AD513C2ULL, 0xA80EE14BDC0C7FB4ULL, 
            0x8161B582791D9119ULL, 0xA855F293B3939BAEULL, 0x751EE7432AF6FF95ULL, 0x22D36F115B1AD7AEULL, 
            0xA0C40BA6B4D58C9FULL, 0x149C386F5AF84F50ULL, 0x49D947015BCE8159ULL, 0xC2BDCEA96419EE5FULL, 
            0x4D3F532A72A7A8F2ULL, 0xD5CA07031780614DULL, 0x0B4226C37FA728B9ULL, 0x5456F80503BE0698ULL, 
            0xEE32280EC918A161ULL, 0xD424CB46F4A3ECF4ULL, 0x530B6E57390DEEC4ULL, 0xD5066B66BED2C81EULL, 
            0xF94A28C2FD8EE395ULL, 0xAB0E1AD31E69B487ULL, 0x6B65470FC0BB6FA8ULL, 0x39A39A4A86E65598ULL
        },
        {
            0x9220467BCAEF42BEULL, 0xDE855B4E308796B1ULL, 0xC602E08086D3EA28ULL, 0x0CAEA5962807B740ULL, 
            0x7279BA70BD0C3488ULL, 0xA820F02EF990CB69ULL, 0x57B0715C0F1BF173ULL, 0x874D67137665CA84ULL, 
            0x09F24E2878913998ULL, 0x7791219177ECFD6EULL, 0xD8DB2FDF6F7FF270ULL, 0xECCE9FA0A8345CA8ULL, 
            0xCBF0A732368775F3ULL, 0x4E0B1F67D825AC9AULL, 0x277F7313D660A737ULL, 0xDFE9FF646AD54BDCULL, 
            0x5907CCF5BAA6048EULL, 0xDE3DC3A8900DBC0BULL, 0xDFBFC3825C00C518ULL, 0xD28E229A9CBB44E8ULL, 
            0x98DB6C256AC091CAULL, 0x6589257BCC48A523ULL, 0xD6532C76A8CC09B3ULL, 0x9FD43FC344F0B7F2ULL, 
            0x0DDD49D9C57A2500ULL, 0x5347415FF111F75AULL, 0xA8AE17227B5F9E5FULL, 0xAD721542C5CCB4B9ULL, 
            0xBF6BB2D870C1AC06ULL, 0x11EC3394ADF4F322ULL, 0x423A65F8E199A5B0ULL, 0x281EAE63317FDEA1ULL
        },
        {
            0x2787858FCF7B3DC2ULL, 0x989AF3F7C52850C6ULL, 0xA57E96FC78CC65D5ULL, 0x2DF992604C26CF13ULL, 
            0xA086EF4251831662ULL, 0x646F0F807B6290B9ULL, 0xF81496AE11A35ABAULL, 0xDABE7578EB38111AULL, 
            0x92FDE85112F50CD4ULL, 0x695DFCEFE02EEAB6ULL, 0xB721D6E8D1A6BA0FULL, 0x69404D85A6F6C4DFULL, 
            0x8E61A945C372DEDEULL, 0xD2A3A28F77D2A78DULL, 0xB1401DDC7ADECE46ULL, 0xF86AF777422DE76EULL, 
            0x7609ACA56EBED2BFULL, 0xC22C9B5FD8F0354DULL, 0x3679BA08B5372042ULL, 0x34516B658B4EAD12ULL, 
            0x24A7C93F48B5D2FAULL, 0x7ED1BEBD209FDCD9ULL, 0x0E18ADCBC0BB40ADULL, 0xDC32717F9EBD2B0BULL, 
            0x64C62D2679169EDFULL, 0xAEE26880A6CCDA24ULL, 0x84A31B2AAD01E876ULL, 0x88AF922DD483701FULL, 
            0x533CDC7CC114E48BULL, 0x6CD28AAC39AAA280ULL, 0x22E4BEC2C4197EF2ULL, 0xB3FD176877638A01ULL
        },
        {
            0xE9576B634F43DFCCULL, 0x709F25CC70628407ULL, 0xF4E1149FCAC441B3ULL, 0x60F8F95FC30BC8E4ULL, 
            0x0052634D8C9D136BULL, 0x1B39FEDAE116745FULL, 0x2D7ABB229BC6F28CULL, 0x746F2980736F86F6ULL, 
            0x8FDD98A86F8057D6ULL, 0x9DF0061AC0FFE176ULL, 0x770CB8686A5AA884ULL, 0xC9A9A25A9A8F3692ULL, 
            0xF5D3E8717DF48078ULL, 0x0C4F179D4218C15FULL, 0xFF9932BCC9F88589ULL, 0x3A4E944A7E8535FAULL, 
            0x8FCBA522B4EA2613ULL, 0xC1633D9162CD066BULL, 0x973B7C3F0D779505ULL, 0x62FF1C78A002AE8FULL, 
            0xFDB3C87C23DECC89ULL, 0x8F2E32C45D54FC95ULL, 0x66E36EDEF2AFE383ULL, 0x6D8BFD9CF303427EULL, 
            0x7825FE0B262BC57AULL, 0x5CB407A360BF05D7ULL, 0x5C0207D674186E39ULL, 0x65C9B9210C55A2DBULL, 
            0xB58F583067C2CF17ULL, 0x483A5A6C1D492192ULL, 0x4D01405029BD9E7CULL, 0x37CCE0F2F944BE13ULL
        },
        {
            0x5CFD20EBB3114802ULL, 0xD276D28950E77CB4ULL, 0x6ADD60775AA33F12ULL, 0x10AA6F014DDA5994ULL, 
            0xFFBE4B79A4901FA3ULL, 0xE62D950E3CA44707ULL, 0x5945CF137311033CULL, 0xCA79C26B11963DF8ULL, 
            0x630490DFD537682FULL, 0x238A3306A1128794ULL, 0xD7BF9DF458E3CAF8ULL, 0x96DB979517879B89ULL, 
            0xF8759C4FFD409DC7ULL, 0x9F2E2347AEAF3811ULL, 0x46D6F4F8B1A5B35EULL, 0x827CEAD9E74AD065ULL, 
            0x7A3035CF9A703676ULL, 0xE07149F53FD276A5ULL, 0xAAAB16B3276E4332ULL, 0xFFD61CAC82D02B6AULL, 
            0x178DED384A13E42DULL, 0x7AFF560D77E48BECULL, 0x537ACAE48E2F2DBBULL, 0x7DDF67439AA84896ULL, 
            0xAC8662FB7DF879BEULL, 0xD2F6E6B901BC61ADULL, 0x42C96185F365091BULL, 0xD58821C2E1108E6AULL, 
            0xDC7D419F285049EFULL, 0x2BF00C67263CF926ULL, 0x190F216F1F8B1918ULL, 0x65C9A8B4046EBDA1ULL
        }
    },
    {
        {
            0x26B7248DB3459312ULL, 0x15E3961E5FD7BE78ULL, 0x3A687DE3B32BF392ULL, 0xF7ADABB72AD0585CULL, 
            0xAE222616F51091CBULL, 0x3148D2448522B41AULL, 0x3002303D23819265ULL, 0x62161ACEAD5E73C5ULL, 
            0xC331591474559ABEULL, 0x153B383BC17420E2ULL, 0x5A68F2911C5B3560ULL, 0xD7999C85F16F6468ULL, 
            0xAC6BBEC1E16FDF10ULL, 0xFF358F5F7107C3ADULL, 0xAA9F631C311E9542ULL, 0xFC6C9B4B7261DCA6ULL, 
            0x4A21D2F7C7963788ULL, 0x1D627B8F156AEF55ULL, 0x6147A6B369519E8CULL, 0xA6F1B9026A03E5FBULL, 
            0x1CB32B9E5B31DD70ULL, 0x11DBF94250710970ULL, 0x2B6E80C6D3024CEAULL, 0x6E35D2FAEDBF8D97ULL, 
            0x998C407D2BD0CAE5ULL, 0xBD3B7CBC657B44AAULL, 0x7A9C0BD344626E37ULL, 0x6D38000853B33EEFULL, 
            0x27EE578D6505EF33ULL, 0xA3BC0903349127B6ULL, 0xA3A1912685FBE198ULL, 0x91E82F8742F6AB13ULL
        },
        {
            0x8360C6B90726316FULL, 0x0D36EE41D5479CE0ULL, 0x6A6CA3ECC112BD90ULL, 0xA8BE0D3ED73877E6ULL, 
            0xA31E6A57A3B61539ULL, 0xA2AD65863EB02DCEULL, 0xF9CF3E8E2EC331CFULL, 0x01B87FBA4D1246ABULL, 
            0x2E2CB346BAF25AAAULL, 0x0F1F09ED476D0B8CULL, 0xED303B93FCA4A838ULL, 0xDA20DE36971A8AE8ULL, 
            0x6A892B8FD00271C9ULL, 0x8CA56B02388BC165ULL, 0xCCCD7CC06524BAAEULL, 0x97A0677EB9180939ULL, 
            0x13D93FF2D97355CCULL, 0xAD99E150AA5EF64CULL, 0x99AAA7FD2F725764ULL, 0x665A4036E466738BULL, 
            0xC5C3F89803965944ULL, 0xF98081B5AA63B908ULL, 0x50F59DDBFB6BC3C8ULL, 0xFD7B0200FF8945EDULL, 
            0x0AFFE64BF0904045ULL, 0x98970EC93D339366ULL, 0x2054C9AFFE452371ULL, 0xADD5510A29C61071ULL, 
            0x031A2A5E6D4517EDULL, 0xE6EB230BC1BA6E0AULL, 0x319A1E4CE6827360ULL, 0x766648AB2C413DE0ULL
        },
        {
            0x0D8DB87301089366ULL, 0x04705D1462DEF022ULL, 0x804FB7C812BBFD83ULL, 0x12CD94983DE109B2ULL, 
            0x7BEF7AB8448BC3F8ULL, 0x45326592373538B9ULL, 0x1B0309A2A9538D4FULL, 0x036AE45D3AF57873ULL, 
            0x08A951C417E48065ULL, 0x83E925D087CB99CCULL, 0x36A10F6FF0F96C92ULL, 0x7960AE419949C707ULL, 
            0xD3BBFE99FDD4073BULL, 0xD94B90CB9B414508ULL, 0xFD4526BEEF22F281ULL, 0xBEA9E500AF818DBFULL, 
            0x51D2A82619D1F49FULL, 0x5F97D811D5798FF7ULL, 0x8E1A434A1B98E7E3ULL, 0x3690A7EBCDE64095ULL, 
            0xC3690C84C7D350F0ULL, 0x2A5318B9E6E24BBFULL, 0xD5CA1C9A43C030ABULL, 0x150E7B3AA9849DF8ULL, 
            0x2314D29D164E05A6ULL, 0xDA8606B33A98F309ULL, 0x2A8B778C7C4DBECEULL, 0xCAFDCB6D0B5E596AULL, 
            0xF38EE612FD0ED651ULL, 0x612DA3108ADFF93FULL, 0xBDA076D1CF92766FULL, 0xEEED50FD608A45B0ULL
        },
        {
            0x2629F2FA54030427ULL, 0xDDC2C138DB89E898ULL, 0xEAD36B99494E0249ULL, 0xA1027BB9C621B618ULL, 
            0xE2258BD03C6746EBULL, 0xE405F70C4B33275DULL, 0x23A4F70130222340ULL, 0xEDAEBE715EF2C463ULL, 
            0x4B6360681C6FCA4FULL, 0xE8353B679AAFE279ULL, 0x15048AFE607E73B3ULL, 0x2F2FBD98555DBA09ULL, 
            0x5D7F62471698CE8EULL, 0xADF35E494EC0FE40ULL, 0xCC3A2B6C65B12694ULL, 0x09BC0C4D4B45DA95ULL, 
            0x4E20A09083704D6AULL, 0xA8D00241AC98AFDBULL, 0x4C624D47B119C414ULL, 0xDDF26693B8EFC00BULL, 
            0xE7C1CD2090160C3BULL, 0xC4908772538D17C1ULL, 0xDA3348F1154E1EA8ULL, 0x02E7C220DD75145AULL, 
            0x68835FC9F505F16FULL, 0x2C91D969318FB48AULL, 0x6ABC813BE67FC0FCULL, 0x276A8E7A4BC6A5C4ULL, 
            0x9C33BCB727371126ULL, 0x848E32C814644826ULL, 0x87AB04AC9BEAF604ULL, 0xF15680E611E561D6ULL
        },
        {
            0x969526DD5AFF27F5ULL, 0x3A50055ACAA85007ULL, 0xDE202888E2430C7BULL, 0x880F74A06A2D4292ULL, 
            0xDCE58A07C57BA151ULL, 0x780A323847B42EB7ULL, 0x932A5648FB4E6F35ULL, 0x25A151205A301983ULL, 
            0x7C240726C8F18462ULL, 0xB8CA25BB8F71A1F1ULL, 0x6C96197DC54C962EULL, 0xFE95727503C3C9E4ULL, 
            0xE560CA167DA27A04ULL, 0x61069F2BEBDBCC4EULL, 0xF0F43AD9CBFE5662ULL, 0xA1465884EB77E337ULL, 
            0xE460F5356B7ABCC2ULL, 0xAB0A3700AB61698DULL, 0x870A3B6C377BC5C4ULL, 0xF380DAD22BE50598ULL, 
            0x2D921ABED4CC2FC6ULL, 0x43AEF6408D284A32ULL, 0x6442A0389C770C12ULL, 0xAFB0BE3D15BA1CC3ULL, 
            0xB27E69EFF42F0C57ULL, 0x54606BF5B2A90F10ULL, 0x72CF697E34BD12F1ULL, 0xA50E19241ACD4A1DULL, 
            0x3ADBC9F867DD46DEULL, 0x8E4DD787FB53C855ULL, 0x439937127E0B63CFULL, 0x8130D16A714952EBULL
        },
        {
            0x272C0FAD7221F9E2ULL, 0x7AB94DEEB33F7A4FULL, 0x5D169335D12365F0ULL, 0xA426EFF0DCD48AA5ULL, 
            0x2CB28FAE2B216FE9ULL, 0x98D54AE545305625ULL, 0x9FD2F2446AA792CAULL, 0x2B6E7D31CB9CB43CULL, 
            0xF6695AD2D8266746ULL, 0xE4E2D2661951889EULL, 0x293F0499C26CB44FULL, 0xC56654E138CAA7DCULL, 
            0x39EEA71D585E29C0ULL, 0xFAB1051026A710EBULL, 0x496199E649DB4E18ULL, 0xE7D64C64176CF23AULL, 
            0xFC4A0C540EE64889ULL, 0x2FEA202083D4D25AULL, 0x55CD615B17FB7FBFULL, 0x87D392373B6D1479ULL, 
            0x3467D612EE401247ULL, 0xECF1DFB2C6F06CDCULL, 0x6B799FA7D259BE13ULL, 0x905B4A357D41B9CEULL, 
            0x97983524090DACC4ULL, 0xCD591FEF46C96455ULL, 0xF0EE461C0442671AULL, 0xDEA3289D844859C8ULL, 
            0x5613FC82392CE713ULL, 0x8DBF71C6411A7458ULL, 0x4D35FC88D195F83FULL, 0xE53179E95E60DF4CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kSeedConstants = {
    0xC44A85D53FA92B4CULL,
    0x6F39D376F936A8B0ULL,
    0x5BB7BB7CD977EDB3ULL,
    0xC44A85D53FA92B4CULL,
    0x6F39D376F936A8B0ULL,
    0x5BB7BB7CD977EDB3ULL,
    0x3DAADC50921AF124ULL,
    0x773DC29E47975EEDULL,
    0xBC,
    0xC8,
    0x09,
    0x4F,
    0x03,
    0x87,
    0xD3,
    0x1E
};

const TwistDomainSaltSet TwistExpander_Regulus::kTwistSalts = {
    {
        {
            0xC51EB88469443578ULL, 0xF8B5935C191AC929ULL, 0xF5EBC02CDBA38283ULL, 0x4CAC63CE6ECAB61FULL, 
            0x2382B2865AE9498FULL, 0x6A9E492A535FDC96ULL, 0x73F292BD6FEF6AC6ULL, 0xE6229A9D43572523ULL, 
            0xE85D082E7F92D55FULL, 0xD720C7A3D614E869ULL, 0xCC11C3E072675FFDULL, 0xC1D208432920DDADULL, 
            0x80057B4FB76F71EFULL, 0xA5B1B937E3BC0394ULL, 0xA28D098D91902BD6ULL, 0xE0C9EE567683DC15ULL, 
            0x5AAA1F3B74B664AFULL, 0x608D132CC6A2C82CULL, 0x4CD380A0D9B3BCE6ULL, 0xA09D5CFC2C8F08EFULL, 
            0x26D18186444C549CULL, 0x9082D414FAD9CDFCULL, 0xEDD32C7DE0301EE5ULL, 0x9C3B07DC7965CEFAULL, 
            0x9FB8C1239AE880EBULL, 0xC8A4DD5873A3C92AULL, 0xEF96614A9FAD1026ULL, 0xF40CD8AB6470AFDAULL, 
            0xB40F7D2C881D8993ULL, 0x0D03956788466B54ULL, 0xEB27DE0BA45EFA5DULL, 0x78D96A3FBBE063BBULL
        },
        {
            0x2E9ABB7CB0068FA5ULL, 0x7544CC2A843623F8ULL, 0xA3465BC47A0AADECULL, 0xF2C3C27A67EC460AULL, 
            0xB280B6B80F824C06ULL, 0x8716127C53A6BB18ULL, 0x361F8706B3DD17A9ULL, 0xCE9121D7B3E9DE60ULL, 
            0x3BACD638DEA54A07ULL, 0xC4128C46222BF3DEULL, 0x6609CB26186081EEULL, 0xC313A633C4E06047ULL, 
            0x8C8466F6D0C473BAULL, 0xB8AD8A626E0E34EDULL, 0xDDD03E0BD56A44D6ULL, 0xF76FA087F13BCBBEULL, 
            0x27FC44321E87A8EDULL, 0xD5CE80E0957D60ADULL, 0xE1D644075F0ED203ULL, 0x1DFE005C19E497DCULL, 
            0x0059F8DD613AEE19ULL, 0xD6132141973F592EULL, 0xDDAE87FB7AC5AA7EULL, 0x8C5A03519E3E2FBEULL, 
            0x6D4E5509A33DE4BBULL, 0x934DBAE824AE7C33ULL, 0x61B148449CA21C28ULL, 0x7CD9B21CE5159137ULL, 
            0xD1311BE79D89CCE5ULL, 0x2654DA8862366D74ULL, 0x51D314457156763EULL, 0x6DBCBA5E615BA5B1ULL
        },
        {
            0xA79BCE798D1F8DD6ULL, 0xA6AEC3FEFA104CBAULL, 0xAD780AA6B45A32B0ULL, 0xB6C8261D7E61177AULL, 
            0xBDFED610B038DBF6ULL, 0xEC5FD8DC59789E34ULL, 0x032E3F9187C3A242ULL, 0x17DD466F58BA8B2DULL, 
            0x55164AAC7CBACF1FULL, 0xA0CF4C03F83BD99DULL, 0xDD0BE9D098BD6EC4ULL, 0xD859CD4740E5E119ULL, 
            0x4DC835748DFEAE4BULL, 0x17E0919FFCA224E4ULL, 0xFD46B6353C0A499DULL, 0xD08FBA09ED7D6058ULL, 
            0x73AEB45DCEACAD74ULL, 0x60663280DFD43F21ULL, 0xCAB0B20A79798396ULL, 0x5E99D26A2AA7E253ULL, 
            0x53FDC42F7CBC07F0ULL, 0x3090230DAEFD3DFDULL, 0xDEA330C19A8F8755ULL, 0x0FEBEA1AC1FC974CULL, 
            0x92898ED7F97154E7ULL, 0x114783FD10AFD1EFULL, 0xC333C2CF1C5FEA9BULL, 0x8A2E039BFC8B27A1ULL, 
            0x6296208885EC109DULL, 0xED9B5CC6CBC5C6BBULL, 0x30BDA1CA79619047ULL, 0x56C66754C85C933DULL
        },
        {
            0xEA7274CD0A86042AULL, 0x5A5AC034EA85B772ULL, 0x12E5B492BE9A3803ULL, 0x621D249189FB2113ULL, 
            0x6C266C14A2EDDAE8ULL, 0x56BA07E953E6EFB8ULL, 0xA628222C28A07F3EULL, 0xF427057B7DA2B41DULL, 
            0x04347F81FA9E1AD9ULL, 0x112F626335F9205EULL, 0x72B76F94694DC028ULL, 0x634B0D3EDEAB2BFAULL, 
            0x74D0AC055FEB0761ULL, 0x178C76DA2E1D4BE3ULL, 0x233A4CB66253E970ULL, 0xF3E7823E9043D374ULL, 
            0xC72CFEBCC089FDB5ULL, 0xB749E1CDFCD1D12FULL, 0xE8E2487DB6F345FFULL, 0xD0E69DF8996A5306ULL, 
            0x5A1713B3730CA74FULL, 0xD47AD96D198DFDE3ULL, 0xB8D93432C70B8190ULL, 0x164838A583696A70ULL, 
            0x90AAB50114F0BD4CULL, 0x289BAFB5F8BFCE8AULL, 0x1F5DBA951B270BB6ULL, 0xE92C1B645795D7D5ULL, 
            0x218D55AA44F8324AULL, 0x2677662C8C53C0BEULL, 0x39A7871D208B7B25ULL, 0x8D9AF26AC14B0DADULL
        },
        {
            0x3209D263329B84E8ULL, 0xF38399D968EB666EULL, 0xA3116215AA4AA702ULL, 0x6F73AC0A3F7DC3DBULL, 
            0x9074AF0AB0C98D32ULL, 0x40B0FC02BFEB4EA1ULL, 0xA93E7931F3CDF0B7ULL, 0x2B22BF5AEAB50BF7ULL, 
            0xBE33AA711D73F757ULL, 0xB8E4D98893D765EAULL, 0x86CFEC5F395644EBULL, 0x55B50B678E0773A9ULL, 
            0x19CEF667B1CBF2B3ULL, 0xE37C3AF9E6EFD1CEULL, 0xF3C87E5168519DA6ULL, 0x6D1505F0F84F80D1ULL, 
            0xB29DB7BA254E890DULL, 0x8C2E25F72CFCDBC5ULL, 0x69F6A37B6864224EULL, 0x10366D639AF20149ULL, 
            0x24ED97788EB0EDD8ULL, 0x5D95CDEDE8CE8347ULL, 0xED95A8F61A67E128ULL, 0xB0B5A08ADDDA3B4FULL, 
            0x0C9838132AD97651ULL, 0xA24DC79BDB9F758CULL, 0x91B80DD0CFA2D2A6ULL, 0x6CD49CF9864B6CC8ULL, 
            0xCD059003D328CCE5ULL, 0x9F24EC3028B89D1DULL, 0x9D2112AD2D8BD549ULL, 0x69150B8438DAB077ULL
        },
        {
            0x3AC209AE6BEE39D8ULL, 0xE05A2AE6749CF8FDULL, 0x4C04B0A5ABFE1337ULL, 0xD071B5C3D5F70573ULL, 
            0x303C434D0076CCA7ULL, 0x40FCB100669DD2EDULL, 0xEE8B2A85AB2E4ED2ULL, 0x40856D7B3D026DFDULL, 
            0xF6BA5B58AE10B083ULL, 0x977593F438EBF885ULL, 0xEDAA0B49F79ED432ULL, 0xB36AF4BB58EA3C1DULL, 
            0x95F838827A8B52C2ULL, 0x51B98A08F39866CAULL, 0x272F5B2677A69223ULL, 0xF8347F280D2CAFDAULL, 
            0xE72CB7010617DADEULL, 0xAEC7DFC5A0AFC6C5ULL, 0x19ECF7487C57AC54ULL, 0xDE0983609788AC61ULL, 
            0xEE7AF5EC05D753DCULL, 0x22FB3AE1E619A937ULL, 0x2D24D3B9DEF861A1ULL, 0xF2B9F9C531B35A4BULL, 
            0x44BD7A4D02E728DDULL, 0x2FBE3DADBB5AF623ULL, 0x14CD013E13801A1CULL, 0x34277FF208B00A50ULL, 
            0x9D0C71E983640CF7ULL, 0xE0FA448249D20DBEULL, 0x69AA10D3BEB9DDF1ULL, 0xB72F491A283FFB32ULL
        }
    },
    {
        {
            0x2A24D313C2B034B1ULL, 0x24595635A04B5BB1ULL, 0x2843421B653FB737ULL, 0x4C05CFB46EE6F8C7ULL, 
            0x1EFE89FDC4301EE7ULL, 0x64441F15602D5DEDULL, 0x8D169BE96FDBCA48ULL, 0xC7F88E0FFC4906D4ULL, 
            0x79309503AE34D080ULL, 0x7B3AE7FD69637F4DULL, 0x97B02F03FC7E8CF3ULL, 0xB431BD1ACF478E0AULL, 
            0x4B873295856043F4ULL, 0x3F541016325083D0ULL, 0x4AD87F01691313F3ULL, 0xE4C832C8C5B84C95ULL, 
            0xFBA2925AFA88125AULL, 0xED7270C938F197C5ULL, 0x3A83FEE63BC74BF9ULL, 0x519AAF1EEC5DFB5CULL, 
            0x3BC3EB47FB38BA1BULL, 0x6852F4D36F76332DULL, 0x2664E44CA7A3ABB5ULL, 0x7D46AB20923E39F4ULL, 
            0x9167009DFC5D3D31ULL, 0x5EAA7C4E60DDFA1DULL, 0xCAF376448F70B43AULL, 0x26B1CB1F3A75A616ULL, 
            0x666E5AA72AD83EB0ULL, 0xC92B54FFE0B7DAC6ULL, 0xE795C902FBEE0955ULL, 0xE067A1FD20A4DF79ULL
        },
        {
            0x61DFD2A3B51B994BULL, 0x1F2A905D1B8AF959ULL, 0xAE522E58BD50EADBULL, 0xA0A3627B9B0E172AULL, 
            0x1654268C24E3626CULL, 0x3EA6138A89D813D5ULL, 0x485124B798203E73ULL, 0x0B6050FE8D8DFCA3ULL, 
            0x4BE032283E4C8C85ULL, 0x913D2EAE8BD7FF01ULL, 0x2E3124FB2AC31830ULL, 0x8A7833C9BFB469D6ULL, 
            0xD3219933C41BFD7BULL, 0x90D9104F809E90CAULL, 0xAF42B5A622FE2DEFULL, 0x8020F8211F6B2F19ULL, 
            0x8A60842B91E6FD7DULL, 0xAF1DC976B3F68607ULL, 0xF1FF19F6715837DDULL, 0x3A423C3325822AD5ULL, 
            0x1C70A10B1F55DFF6ULL, 0x30651C62A27694F0ULL, 0x242C6FA59154F4EFULL, 0x628B52FD1C812A97ULL, 
            0x98817251A747617EULL, 0x953A89C5040EA562ULL, 0x50B0B6F8F9BFA43BULL, 0x2EF2CF35A0EAA973ULL, 
            0x2E103FE04F5BC10FULL, 0xECC5F076DE54C02BULL, 0xE3CADF7B5EAB98F3ULL, 0x944D54F452C1E3A1ULL
        },
        {
            0xBDCD77239D5DDD51ULL, 0x47C2872A7B1CA22FULL, 0x1A03E05C4368EE75ULL, 0x71B89807D0AA6990ULL, 
            0x770C2F730B460252ULL, 0x7060687DACE2D4C0ULL, 0x6FDC0985E76E5ADFULL, 0x937E6B6811A6C9DBULL, 
            0x0752AF822C4B4A4CULL, 0x4E3E953466766AD7ULL, 0x9162364179F637D4ULL, 0x564CC37194A54EEEULL, 
            0xA6CF5671FF4630C0ULL, 0x4DE5C096C1A19548ULL, 0xF8816969D1B3CE02ULL, 0x655FB9EA8985AB1CULL, 
            0x3DF71B335208A624ULL, 0xFC8D98E48D8C2335ULL, 0x14A818F9E08DE5DEULL, 0x20EB034F559E851CULL, 
            0x1292CDC8B8A39268ULL, 0x7C895FFF07243FDCULL, 0xE0EEE59224E5FA2AULL, 0xEC41865A964A18DCULL, 
            0x8F54A52B4E47C3A0ULL, 0xD29EA7F07C400F5EULL, 0x655170F0D006C2FDULL, 0x84480AA8D16E46C3ULL, 
            0x4F1A0D5C4A61CE8BULL, 0x7F29CA592A75E961ULL, 0xA88EEA57383B4D19ULL, 0xBF1699CFAF17507AULL
        },
        {
            0x83D4B19C9385DB91ULL, 0x650BA7E8A63DE1F7ULL, 0x145123E4103D33B9ULL, 0xA73D395C75177900ULL, 
            0xB28E14C42A898908ULL, 0xC2FBB200093D3F44ULL, 0x4B145BCCCB1DF5B3ULL, 0x9DB91A21A3C4B592ULL, 
            0x3D1B6AECD8B42D41ULL, 0x0638E4345C156632ULL, 0xD3CB275F226905BFULL, 0x60A00725EBEB7357ULL, 
            0x70C8BC876134FD68ULL, 0xE1740C7198CB755BULL, 0xADBF225F63C1CDDDULL, 0xD48544F79031B007ULL, 
            0x930D4E03D39E6E41ULL, 0x70E4BAFEFD19F6C8ULL, 0x58EBF07679382A1AULL, 0xC480DC8B0BAAB62BULL, 
            0xD5B855BB38FB3080ULL, 0x5ADF3E6A1E636CFDULL, 0x056E2CF7E57F98E3ULL, 0x86F2D227D4A0F929ULL, 
            0xE4606D2013FA46F4ULL, 0x9B8C53C41835E8CCULL, 0xCEA88816EBD8578BULL, 0x606A6626DB23647FULL, 
            0x48FDE5CC6AC8C6A7ULL, 0xBAC405B786F97C2CULL, 0x3B086A60C0D52E4FULL, 0xE4BD9A04BC30EB70ULL
        },
        {
            0xD585FB1B1FC8F08FULL, 0xAD960DB86B5BEC82ULL, 0x63A4BAC63D3E1D82ULL, 0x431F7AC7BC22395AULL, 
            0x89862B4A62EC45DAULL, 0x30E39BC65C10ABD8ULL, 0xB203F111CB5F115EULL, 0x09680B4004950C1BULL, 
            0x9C5A0F494FEEDC54ULL, 0x9CFC554A9831092BULL, 0xD97B7D50E16724F5ULL, 0xE145C7683CD53D5FULL, 
            0xB69E3EA22F8CF545ULL, 0xB850BE98D73C5C80ULL, 0xD8550CE38ADD4FE3ULL, 0xF0A9B092101CC04BULL, 
            0x993804CF61DF0031ULL, 0xB72BA0CA9FC7A779ULL, 0x9AC3BD0BA40D6931ULL, 0xC0642E560C5AA643ULL, 
            0x679BA1B360BEA9B1ULL, 0x1EA05BFB65169087ULL, 0x002686922D6A8DC6ULL, 0xE9E49CC57CFF5896ULL, 
            0x2AFBF785A1283B24ULL, 0xBA8DAD8DFB3DFF21ULL, 0x809A793DDEEF3684ULL, 0xFD377A1DAEC30BDEULL, 
            0xCDBBDC91697F5ABDULL, 0xB42CF74738C5FFDEULL, 0x6654B34DE51FD6F7ULL, 0x85091D9C037E351FULL
        },
        {
            0x0C8021E2277F08E0ULL, 0x66DD7E59B2FA038EULL, 0x0726AD72E7A2EC14ULL, 0xAA2AE35DD7DF3E00ULL, 
            0x5E964D32486D6827ULL, 0x765360116D857F1FULL, 0xF8F1BA9FCF0C0FB2ULL, 0x7D05D3F7F1338BBCULL, 
            0xA6045715AF198BC5ULL, 0xE30D9C20FE7D6E17ULL, 0x8E9DF7607DEFD7BDULL, 0x9466AE23DF36C090ULL, 
            0xA98B279BEFC09FE1ULL, 0xB15BB8D1BCF5CEFFULL, 0xC7BD155874DC28D3ULL, 0xB66CD5D3591040DFULL, 
            0x7AD20E365F13F103ULL, 0x016516D918F2285BULL, 0xAF28FA868BF7EA61ULL, 0xFD8FD11DD7259056ULL, 
            0x840ABA77AA244D71ULL, 0xB82DFA0B174327F9ULL, 0xF41AB2D720067586ULL, 0x8C555DDD712A29E5ULL, 
            0xA442B5F52F0C0A11ULL, 0x74613A4062C68220ULL, 0xCB40C8EB38B6EB0AULL, 0xD8F7A182FE9E98E9ULL, 
            0x2541040C132D9D7BULL, 0x143BAE1FE5C9410BULL, 0x7B24AA3D2A406E60ULL, 0x412AD9CD3FE9380DULL
        }
    },
    {
        {
            0xAA2B615FE8945BEFULL, 0x1BCE87900739B525ULL, 0x7641A75EB62CA3FEULL, 0x8B2DCED57D165724ULL, 
            0x50B2D07D0F1B62DEULL, 0xFA6D66DC9B49B8D3ULL, 0xABE9C902AB17DED1ULL, 0xFD63CCF41213100FULL, 
            0x51098AF7A6AEE39DULL, 0xBA554A17CCC5A76EULL, 0x37ABBB40D4CAD974ULL, 0x3F3DF476E42F3FDDULL, 
            0x5A255FF30B760701ULL, 0x70684D71DBC73FBDULL, 0x86B8F1A1B3296829ULL, 0xA72277A002AC77B7ULL, 
            0x087339E0B366997AULL, 0xCB2D308D9BCAEDCFULL, 0xF3B441D0BA57D3CBULL, 0xA95184125F8221F8ULL, 
            0x48B54D741BA7B204ULL, 0xB7E13B3506FD472AULL, 0x65421283164CEFFDULL, 0x65F1774E77295014ULL, 
            0x0B207D85C4C97AC7ULL, 0xFE63E33ADACA80C7ULL, 0x2E14CEDBFD7D3B0AULL, 0x926C55D370576C67ULL, 
            0x8C70BF59078A89F7ULL, 0x3AE40EF88A4EBDE6ULL, 0x6DB2AE81784B8326ULL, 0x87229AD3FBA28960ULL
        },
        {
            0x0DDAFD9316BFDF7DULL, 0xD89DE66258377DACULL, 0x5D9FF39DD5C20541ULL, 0x95ECA49F8DAE31E7ULL, 
            0x853D6C6A3D1AA473ULL, 0xE5EEC8681A78E3B2ULL, 0x2ECD6F7BEFF3E1CCULL, 0x92EC12ECDC735943ULL, 
            0xA3E18DDB9FE417F8ULL, 0x9341AB5389D667E8ULL, 0x3C5C7DD914AC585CULL, 0xB78C6D295BE15D7EULL, 
            0x2B4370836076666DULL, 0xDE63E1DFDBCD988FULL, 0x85C82894ACFEB6D1ULL, 0xD757ED6771E81BAFULL, 
            0x5B46554BA632050FULL, 0x288F157C088BAF8DULL, 0x82BAF04567B50D3FULL, 0x8131200AFAF2C7DFULL, 
            0x66FAC7A9F96DBFCDULL, 0x786B210123E47DD9ULL, 0xBA96E7D7F506C7FAULL, 0xDD7D42CF8F4E19A5ULL, 
            0x29268E6DB6722163ULL, 0xE6365BC1B385FCA6ULL, 0xBB44525BFC511F5DULL, 0xD1A4BC00438B5A09ULL, 
            0x7AE1DBDF4A55917AULL, 0x474B2F13C633F085ULL, 0x54D363DE091E518DULL, 0x66F413BCBE3F4449ULL
        },
        {
            0xA120C8D2ABF043EBULL, 0xA856E99D53DDC97AULL, 0xB568A31DFF220B1EULL, 0x7E8695B3D6EEF2CEULL, 
            0x2A4463ED34F96F01ULL, 0x1C8A3BA714EAAE16ULL, 0x9A212865701F2AE6ULL, 0x2CA93F818B48F524ULL, 
            0x3521C5C599235135ULL, 0x81D7BF11DA401E76ULL, 0x471632EB62052D30ULL, 0x0CC5C6609C7EB7EFULL, 
            0x2D44E2B34748E737ULL, 0x63399B06B370098FULL, 0xD46E905F3669E12BULL, 0xC616853275CC6546ULL, 
            0x9AE8F07CC0C6C85BULL, 0x938BF525D34744E0ULL, 0x272839B1ABAD615EULL, 0x86EA4F3A3F280A24ULL, 
            0x35EA50598D09390BULL, 0xF2FB3A09894DB248ULL, 0xB9F6A591532C66B4ULL, 0xBEE98F8EDC94CC01ULL, 
            0x73453B1F1107D0C5ULL, 0x66B823661C61C41DULL, 0x3FA22DC02A9885B1ULL, 0x7055CF548E2F07DDULL, 
            0xBCC5BE7B570D2C3BULL, 0x9E5E0E34A2E8A6A6ULL, 0x22C7A686112A01C4ULL, 0x591A353C9D8FE80FULL
        },
        {
            0x1E65D317F1C13FF8ULL, 0xCF7242727D646531ULL, 0x0C1C83B671BCB1B4ULL, 0xBE06DD47C27946A2ULL, 
            0xF9B80C65D8BD69BEULL, 0xD12A0BA951F778C6ULL, 0xFC811A9FB0FA83ACULL, 0x6992DD81B529A14DULL, 
            0xAB4E1E404C7540D7ULL, 0xE4FBA1543D818B61ULL, 0x7B50E7D6C751CE08ULL, 0xBC42E02CD5548ADBULL, 
            0x24391FF5FEB7C0E2ULL, 0x74231ECD753B0DE0ULL, 0x9B7397B16041E533ULL, 0x12E798861BA99A16ULL, 
            0x6B11F87922EA7661ULL, 0xC814FDF34615F318ULL, 0x2FD57DFBA0140B09ULL, 0x3D17B1BC94D11F4DULL, 
            0x23BBC63449A8DB5DULL, 0x1FF235E071333E22ULL, 0xF1DB11F213A9D412ULL, 0xBDAAA0F55CBC6B38ULL, 
            0x607877A451A04A41ULL, 0xD5D1D16D726B1801ULL, 0x9F54F17A216D3D8CULL, 0x8373E614E06CB6E2ULL, 
            0x6C6D93210A699557ULL, 0xD23888F909C329D8ULL, 0x33864EC7FC2C8AABULL, 0x6FC99DD677E62A3CULL
        },
        {
            0x7C4FB9DA21C3467EULL, 0x6492979732A6B0FCULL, 0xE8DD5A1582CD2A3AULL, 0xD61C05850FD54640ULL, 
            0x80FE6B8F903D3F52ULL, 0x81787C51F360EF56ULL, 0xA51D2D2CAA2CC7E8ULL, 0xF5F220D5AD3CD837ULL, 
            0x0C3EE93D3A9D3D48ULL, 0x1FA7C5220B90E86BULL, 0x7A5A86EA0296EB62ULL, 0xC07AB7B5DBE72708ULL, 
            0x8917EDE161F4B1BDULL, 0x64484C250674CC4AULL, 0xAF3107FBB841E239ULL, 0x1A44512898C2712DULL, 
            0x089D78194B999229ULL, 0x705C0743435158BCULL, 0x6DAF0A9F66575E02ULL, 0x258556317614030AULL, 
            0x8862BBC5C9216FA1ULL, 0x0A98C8CEAB57DEC5ULL, 0x90405696A2824F99ULL, 0x314119A054FC2359ULL, 
            0x888BB4D5A4FD3F28ULL, 0x3D27DDA47BD73D81ULL, 0x8871338D56B41661ULL, 0x414F92AE713744D7ULL, 
            0x56FB7CC131F371ECULL, 0x6512C335CE85BBB7ULL, 0x64B7BC6731E23402ULL, 0x3B07FA2CB7909539ULL
        },
        {
            0x2F6CF7C61E0F8ED8ULL, 0x03BCF6E655472B2FULL, 0xADFE1D12ED22A8AAULL, 0x29E7AB7733B8669CULL, 
            0x8B8A8E0410767118ULL, 0xCD0AD972A3E071B4ULL, 0x59E44E2B3EE4A27BULL, 0x856BDD0899B0DFFFULL, 
            0xD69C2CEEAA051089ULL, 0x3F9489B59BF087EFULL, 0x3AEDEC9D53F7B914ULL, 0x9AE74692DF891C4AULL, 
            0xAFC19083933746A0ULL, 0xDAC60F18A7838D61ULL, 0xFF3A69167C14BEB0ULL, 0x373DECC2BC83DAB1ULL, 
            0xD9813C23F7942662ULL, 0x44AC26E1DE9F0977ULL, 0xEF91D7FB30A0B029ULL, 0xA41E1A9C7A8C9488ULL, 
            0x5F5098D7955E8EE1ULL, 0x97B7156BFB6F99F7ULL, 0x605B611C4AF6AD8EULL, 0x0DDBBA6BE2007F80ULL, 
            0xA70003B00DD00F20ULL, 0xA65E71236D48CAD0ULL, 0x09D8203B503A4D3CULL, 0x5281351708F250DAULL, 
            0x3B4DB552A3B97745ULL, 0xC9691D7CA7CD5335ULL, 0xA03F8FEEAD59871AULL, 0x5A374580908A7762ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kTwistConstants = {
    0xE0BB6B17E1E1002BULL,
    0xA50991DE9DB38EDBULL,
    0x92BBEDBCED88CC2BULL,
    0xE0BB6B17E1E1002BULL,
    0xA50991DE9DB38EDBULL,
    0x92BBEDBCED88CC2BULL,
    0xEA034DB889BB511AULL,
    0xF3E57D38F7758FD0ULL,
    0xE6,
    0xFD,
    0xEF,
    0x4B,
    0x64,
    0x75,
    0x1E,
    0x96
};

