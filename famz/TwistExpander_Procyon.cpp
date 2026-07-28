#include "TwistExpander_Procyon.hpp"
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

TwistExpander_Procyon::TwistExpander_Procyon()
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

void TwistExpander_Procyon::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Procyon::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB241F9C2C12A5A2FULL;
    std::uint64_t aIngress = 0xE30AC90A711EFDC9ULL;
    std::uint64_t aCarry = 0xA4C478ED7A061D7BULL;

    std::uint64_t aWandererA = 0xD841B2920E7A38B3ULL;
    std::uint64_t aWandererB = 0xE1FE05A6C0FDDDFFULL;
    std::uint64_t aWandererC = 0xA20B56690D9708A1ULL;
    std::uint64_t aWandererD = 0xEA96821E5EBFF010ULL;
    std::uint64_t aWandererE = 0xA39DEC4D79721863ULL;
    std::uint64_t aWandererF = 0xC9BA90E247557FB4ULL;
    std::uint64_t aWandererG = 0xCAF25925C3C811FAULL;
    std::uint64_t aWandererH = 0x83E87ED98940F5F9ULL;
    std::uint64_t aWandererI = 0x9B1DBDD4C57826F5ULL;
    std::uint64_t aWandererJ = 0xBAB5F371FD8FD641ULL;
    std::uint64_t aWandererK = 0xA1C85CE981939504ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xEFA2A1D11D4D5481ULL;
    aIngress = 0xA4058D8BCBB6507DULL;
    aCarry = 0xCAE8CDED63411216ULL;
    aWandererA = 0x82DB92B72EC71EC9ULL;
    aWandererB = 0xDD4FE7E447FC8031ULL;
    aWandererC = 0xC739D688EC9378A4ULL;
    aWandererD = 0x89BC92B5F400BF58ULL;
    aWandererE = 0xCCD7524857CB5468ULL;
    aWandererF = 0x98938337F5B39B80ULL;
    aWandererG = 0x94156D22F20DFBE4ULL;
    aWandererH = 0xFAA562E2EDA5B701ULL;
    aWandererI = 0xE6E9277E91487C08ULL;
    aWandererJ = 0x80A792D38216FD92ULL;
    aWandererK = 0xEB0A9BCEC7B5F5A1ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA47088C094552162ULL;
    aIngress = 0xBD166EABAE0ACB70ULL;
    aCarry = 0x99557DE6BABA5D5FULL;
    aWandererA = 0xFB6383BB32C8B8C6ULL;
    aWandererB = 0xAD44F7C764A6EB91ULL;
    aWandererC = 0x8887FAE7FCF28AA1ULL;
    aWandererD = 0xC684248F22E8BAE3ULL;
    aWandererE = 0xEBD7097F44958B16ULL;
    aWandererF = 0xC656EFF35DFB7023ULL;
    aWandererG = 0xF3B52DCCD26BFC4AULL;
    aWandererH = 0xF940F03EEFD8727DULL;
    aWandererI = 0xE78B05C74FD3CDC8ULL;
    aWandererJ = 0xD0E63128233FB5D4ULL;
    aWandererK = 0xD309548BF9183503ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x9B69DEA914F5BDF7ULL;
    aIngress = 0xB6B7FDCBE872A36BULL;
    aCarry = 0xE3C39F0B8A35D681ULL;
    aWandererA = 0xB408ADDFAEE53C3DULL;
    aWandererB = 0xDDC3BF89B25CCB50ULL;
    aWandererC = 0xEF351A174462D7A7ULL;
    aWandererD = 0xECDA16EF2EF0CBB3ULL;
    aWandererE = 0xAC0AED428CF50078ULL;
    aWandererF = 0xD0210F2990901BCCULL;
    aWandererG = 0xF1356CD360D86547ULL;
    aWandererH = 0x941B1A20EC24B755ULL;
    aWandererI = 0xD2F9893E28DDCFB0ULL;
    aWandererJ = 0xEDF144E59B8A4F34ULL;
    aWandererK = 0xCA51904E95950051ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE62D454EE789A361ULL;
    aIngress = 0xCED7BD89D9C6CF57ULL;
    aCarry = 0xE8BCC6668EDD49C4ULL;
    aWandererA = 0x8981B3CA91517C58ULL;
    aWandererB = 0xC47D7946DF5AD8ECULL;
    aWandererC = 0xFFFA32AA415746CDULL;
    aWandererD = 0xFD301DA2E624CDF9ULL;
    aWandererE = 0x81B281390AFC70BAULL;
    aWandererF = 0xDE68F2495D673EDCULL;
    aWandererG = 0xCB04B47935FBE411ULL;
    aWandererH = 0xEF011F0402886588ULL;
    aWandererI = 0xCF9B858B37464B82ULL;
    aWandererJ = 0xAE6265BD65F209F1ULL;
    aWandererK = 0xC5B3BE840FDD1198ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF450A4569C0316DDULL;
    aIngress = 0x803589211F214895ULL;
    aCarry = 0x8D1607DDE31A2384ULL;
    aWandererA = 0xCD104C105A3AFE1CULL;
    aWandererB = 0xA7AF97FCDFD2C289ULL;
    aWandererC = 0xAEE704FAF2FB378AULL;
    aWandererD = 0xBEB5172FF7D4A86CULL;
    aWandererE = 0xAE5EC6C6F8F64E49ULL;
    aWandererF = 0xC3625D4DA2102E84ULL;
    aWandererG = 0xA8BDBE46B35844CAULL;
    aWandererH = 0xE3F18CB14B1CA954ULL;
    aWandererI = 0xB4A1D4CDD7051867ULL;
    aWandererJ = 0x92146E6AE7850476ULL;
    aWandererK = 0xFD50CF84D6A49535ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xADA3270AB28524D8ULL;
    aIngress = 0x884B29F6B677E8A4ULL;
    aCarry = 0xE6D1C852FCBBE5DBULL;
    aWandererA = 0xA5C9F6E9223A5E1FULL;
    aWandererB = 0x8C8EFD9B08DDC78CULL;
    aWandererC = 0x85A109A37CC63878ULL;
    aWandererD = 0xFF566A483AE51EB0ULL;
    aWandererE = 0xB2C54AD855398BF1ULL;
    aWandererF = 0xB3D996F3D709BDC9ULL;
    aWandererG = 0xB1A3F52C082103D9ULL;
    aWandererH = 0xDB498CBBBE77FFC1ULL;
    aWandererI = 0xA7BF3806A832B873ULL;
    aWandererJ = 0x93E37906F95FDCFDULL;
    aWandererK = 0x8D55793F7BC935CFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xC4FCF932D48B3D42ULL;
    aIngress = 0x9D8C2FE5EBF73AC7ULL;
    aCarry = 0xDB5AF17B669855ECULL;
    aWandererA = 0xCF27AEB4FBBBC571ULL;
    aWandererB = 0xD3AF0889EEE094ACULL;
    aWandererC = 0xF61F84E8B28469FEULL;
    aWandererD = 0xA507B5AF0E86DD26ULL;
    aWandererE = 0x857D96DE3248CB02ULL;
    aWandererF = 0xA683B35973DF3E86ULL;
    aWandererG = 0x995610CEB55490EBULL;
    aWandererH = 0x8FC7B1A555BE5C7DULL;
    aWandererI = 0x8A6014601FB96F58ULL;
    aWandererJ = 0x8CB00A5A299169B1ULL;
    aWandererK = 0xB972DE4C0B8F0973ULL;
    //
    TwistExpander_Procyon_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Procyon_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Procyon_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Procyon_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Procyon_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Procyon::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x82DE30F7425D30CAULL; std::uint64_t aIngress = 0xDF606122DF90B0EBULL; std::uint64_t aCarry = 0xBEC17D663B4C4C0EULL;

    std::uint64_t aWandererA = 0x941E162A71766C84ULL; std::uint64_t aWandererB = 0xD38238E1E6384296ULL; std::uint64_t aWandererC = 0xD64FA49FA14C0316ULL; std::uint64_t aWandererD = 0x96A561489DEBB9F8ULL;
    std::uint64_t aWandererE = 0xD394D87CD21D7BEBULL; std::uint64_t aWandererF = 0xF1760F46409CAAF1ULL; std::uint64_t aWandererG = 0x9956BF5395D805F3ULL; std::uint64_t aWandererH = 0xDDAF3493F0D39710ULL;
    std::uint64_t aWandererI = 0xD8323C1082487E58ULL; std::uint64_t aWandererJ = 0xB840F909C0F8E8A2ULL; std::uint64_t aWandererK = 0xB4AC1CE0CCEC739CULL;

    // [twist]
        aPrevious = 0x979F2242A7C5B1DAULL;
        aCarry = 0xA89F397538CB8A0AULL;
        aWandererA = 0xA6FFF293721758B2ULL;
        aWandererB = 0xE813C71D1FF2C293ULL;
        aWandererC = 0xCBF45A6F45353175ULL;
        aWandererD = 0xD37773457DCB8A07ULL;
        aWandererE = 0x90F1421F940985C8ULL;
        aWandererF = 0xD2F4684C293256B5ULL;
        aWandererG = 0xAB6F067CCB1EA2B5ULL;
        aWandererH = 0xFFFBF7D8A6DC02C7ULL;
        aWandererI = 0xBA3F09051E0CE347ULL;
        aWandererJ = 0xCDC9472E9ECB510EULL;
        aWandererK = 0x8C97375F4596E108ULL;
    TwistExpander_Procyon_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Procyon_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Procyon_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Procyon::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Procyon_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Procyon_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Procyon_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Procyon::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Procyon_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Procyon_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Procyon_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Procyon::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 26 of 33
    // Exploration cases: 0
    // Structural maximin 513 / 674; family total 13323
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1600U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 26 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 13461
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 790U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Procyon::kKeyRotateASalts = {
    {
        {
            0xCAD7CB0F3E0A6FEAULL, 0x7223B7F52B1DEE51ULL, 0x1065B7ECEBAD1F42ULL, 0xE8E55DA53B171DC6ULL, 
            0xE36D3D65A385CF25ULL, 0x9EA8F2472FAF27FCULL, 0xA42F4810C5537FC1ULL, 0xD09C54A17D4DF68EULL, 
            0xD201AB8BF61867CDULL, 0xBFCE7EB6AB59D633ULL, 0x931A3AAC74F939E2ULL, 0x1C939C5DDCDBB3B3ULL, 
            0xD32F89AA556DB655ULL, 0xAA2075AAC67F056FULL, 0xD645675E77E65E6EULL, 0xCD22073D70DC8FC1ULL, 
            0xC55668D13915DA9DULL, 0x811581C7A5C6421BULL, 0x932DEFF482AB8CE3ULL, 0x702DD74522D8138CULL, 
            0xF59B3080D849DC80ULL, 0xB7091015337F6F57ULL, 0x2DC9CAE6BDBB6287ULL, 0xF57A8E27ED6DC9D2ULL, 
            0xB5655601CB3BD79CULL, 0x8D03037F613F79DFULL, 0xC70741DD5046DB90ULL, 0x02108ADA993E524BULL, 
            0xE0DD763CF0D0A6F4ULL, 0x2795CB67B4F87CDEULL, 0xC8EDC64750F155D4ULL, 0xC3E2C3D7736A2646ULL
        },
        {
            0x0C1028A6ADFA5167ULL, 0xDF9A165EA4B9BCA1ULL, 0xAE5EA714646E0CA2ULL, 0x865CD32A4E0E1148ULL, 
            0xFC48735C7065DFACULL, 0x5A4CA91BFBF534D4ULL, 0xFB38808503DB7E96ULL, 0x64BEE4FDBCB8D91DULL, 
            0xF63695683F7A7A7BULL, 0xDF03064E775E5835ULL, 0x44016F6509B9F7C0ULL, 0x57585AA4401FB30EULL, 
            0x9FA912BDA5480F51ULL, 0xF12D1D7B22A8BDE7ULL, 0x7572D00B1A939650ULL, 0x20E0487ADA8A3B9AULL, 
            0xC3B60F66A6D4EFABULL, 0xF068F9C567A532FCULL, 0xA0F8B18DB86A9E94ULL, 0x35E5E4B5C012B9E4ULL, 
            0xE5A3CDB5762B9DE5ULL, 0x84D470DF72926695ULL, 0xA590D6F0B38C74B0ULL, 0x45579C0FD308A5E7ULL, 
            0x67B1E874B09DD5D7ULL, 0x0CA1723C21B71122ULL, 0xF4C6181C7A763A68ULL, 0x5281E770D19B7FC8ULL, 
            0x8154F345D1314CAEULL, 0xDD333F3DCC915BA2ULL, 0x1074D4195CBE339AULL, 0x3C2D3A0A4D661D5BULL
        },
        {
            0xE8437E14D1261AA9ULL, 0x6EB1ACE93A1D1718ULL, 0xC2001EE12D73B0F6ULL, 0x17A1C484B10F4098ULL, 
            0x231963197BD34F9EULL, 0xC85164C1E767353CULL, 0x28CE08E3A404F89FULL, 0xDCC27DFA555D9B1FULL, 
            0x9A9D4F63CCA0D1DFULL, 0x8186DA5B7FA59814ULL, 0x6137A46C9286F19CULL, 0x5EFF1F4E527618DCULL, 
            0x9EF1BBEB0C938A30ULL, 0x45C6547AB155028BULL, 0x5C6DB4AF4ABA0A5DULL, 0xFFC667EA58A390B3ULL, 
            0x0D27B2AD3BDCCFB0ULL, 0xB7274A414F431B71ULL, 0xE33E7DE920531104ULL, 0xFF39F13F2AE0C7ECULL, 
            0x2D133DEF2BE226FEULL, 0x25683D9AC3FC2304ULL, 0xA0C172D4BAC17458ULL, 0x87131733A9E8EFBDULL, 
            0x7BC2F5B4E50E48A7ULL, 0x4C5A95AC45EC486BULL, 0xD59DFF8ADA8AC6FBULL, 0x87485786ABA29F3AULL, 
            0xFBA3A23A4CF7EBECULL, 0x1BA8F4344A4EFA6DULL, 0x5743BEA1E4E7EBC0ULL, 0xFE89A0306A311BD2ULL
        },
        {
            0x18F616DECC494895ULL, 0x8FEFF36C0E0FE3B6ULL, 0x49896F777FC9E4E6ULL, 0xFF716C53FCFB5931ULL, 
            0xB861C7F626738F49ULL, 0xE96D4045ED42048EULL, 0xDF4D4FB004241C47ULL, 0x7835D6AE487A305CULL, 
            0x93A1338066F58C30ULL, 0x0E58CC1D4581FC14ULL, 0xB2EA8FC4FC074396ULL, 0x70D74BC1BCF57A3AULL, 
            0x483BC7A29139A6A2ULL, 0xE6074BF21BAE5B73ULL, 0xEA07681F380F57D6ULL, 0xBFA37F0379CFC8F5ULL, 
            0x7C748B8E3B4DB229ULL, 0xF8EB046DF85F6E2FULL, 0x907EBFE743AE7CCDULL, 0x353C139AD87498FAULL, 
            0xCEA062D8E8263E6FULL, 0xADDD7D198CBADFD8ULL, 0xB5F522DFBD7876D2ULL, 0x935C04F16330C0AAULL, 
            0xE803C7A3DD5B29F6ULL, 0xB89B8724A711667CULL, 0x09A84F01FD88DE93ULL, 0x4D40F59B8728506FULL, 
            0x5F2B786508ADA208ULL, 0xE2FC28F91BE0E905ULL, 0x736E900E5CE07755ULL, 0x6C44E3BD2D9F04B7ULL
        },
        {
            0x9611A5A8C246D2C0ULL, 0x0BBD842700CFAF2BULL, 0xFFC7C7302380DC8AULL, 0xC8FE12ED67F090BDULL, 
            0xB68FB4ED92739DDAULL, 0x68EA99DC71B66AFAULL, 0xBB8BF3426A4B9C7CULL, 0x7C50DBCD118BC85CULL, 
            0x1300718FEBFA0F12ULL, 0xFC680DA00875B607ULL, 0xDCC0F00646D02169ULL, 0x570C94C2071409DCULL, 
            0xCF15DB366DF9B55CULL, 0x5173DC0CEEE01459ULL, 0x6002418E4DDFA24CULL, 0x62604AD1E6360E0DULL, 
            0xEAE8BBC8985961B0ULL, 0xCA9D1446948A84E1ULL, 0x6289808593CB74C9ULL, 0x904F6E9165BA2C00ULL, 
            0x0AAA824F8D17DCE0ULL, 0xACDB680404BF40E9ULL, 0xA167C1955FC36A97ULL, 0xE95AEA97F639E5F3ULL, 
            0xDD71AB85F0D0D157ULL, 0x57A9C128B5DBE548ULL, 0x0B195EA72A20F40AULL, 0x3CD5E8A3EC5E2C6DULL, 
            0x587FF488121D5962ULL, 0xB6288DBFE56C8097ULL, 0xD3F86B9CAFA10C76ULL, 0x9DFEB02D3784F4B3ULL
        },
        {
            0xB530AB463AF39EE2ULL, 0xA1EAC95CFA54A1D2ULL, 0xB18723BC0E1DFD2DULL, 0x7E8EEF064D681E97ULL, 
            0xD4544B6BECA2943EULL, 0xCF1E4F86F060FE99ULL, 0xD8B454C83FBB7950ULL, 0x8E2686AE8D404553ULL, 
            0x7478967CE5EF57A3ULL, 0xC01ED877499C208CULL, 0x0376368478E258FDULL, 0x6F265B237258CB38ULL, 
            0x48B3D5634320738FULL, 0x16C4859212A95F18ULL, 0xA7C05B3A10D136A1ULL, 0xA4FC3A52F47149EAULL, 
            0x0E42C8D63DAFF16BULL, 0x5A0084D16CE15A39ULL, 0xD2A65AC070ACC878ULL, 0x5B056FD170952E6EULL, 
            0xA97726D89BD334DAULL, 0xD611C8AA5EF43E1FULL, 0xDAADEE6D8BC988B1ULL, 0x3F43AF150D393A17ULL, 
            0xF5B5D39A1B3BA90EULL, 0x96741AB39ED3E599ULL, 0xBF08560791357319ULL, 0x35037A1621A9249AULL, 
            0x067A367E50457700ULL, 0x64BB7C6BE039833EULL, 0xD2183165F5B5E37BULL, 0x3CC1005A51D1C0D6ULL
        }
    },
    {
        {
            0xECC1300A142D5859ULL, 0x5C5311F8B4F0700FULL, 0x730799559A6F0D25ULL, 0xEB2D6904A6A710D0ULL, 
            0xEBB073EE778C52E4ULL, 0xC77914223DD4C548ULL, 0xED3B718BB76EB0D4ULL, 0x22D170FC6D8B3D31ULL, 
            0x689DDE088B47D0CCULL, 0xBBA31476C8A89AE9ULL, 0x2ABCA2DDAFC03315ULL, 0xC3335FAB3DC9D603ULL, 
            0x507C99756C5FB5E5ULL, 0xA2C1AA48B4645F7CULL, 0x0EBDC7D25AB669FCULL, 0x31587CF042EA9367ULL, 
            0x90F1AADAD685D4D2ULL, 0x364E7CEF038AAFAAULL, 0xFC5AD49E0601E121ULL, 0x6BDE3B8E9B3CC8C0ULL, 
            0xDB5A688DB46FFE15ULL, 0x318879F83D2D6938ULL, 0x9E76F58B161E9E97ULL, 0xC02947D93B30D17EULL, 
            0xED83FA2AAE48800CULL, 0x67ECBC210B7517E1ULL, 0xE040BB9A56C9C532ULL, 0x312F964C360DD524ULL, 
            0xF0BEC3198B1350C3ULL, 0xCC15BD080862442CULL, 0x50218E7CD4EBF9BCULL, 0x097593094121C8CDULL
        },
        {
            0xF23BB3A39691818DULL, 0x5B15CD2A94A4AFD8ULL, 0x5068A9DFF5C95EBFULL, 0x675C5E864CAAFF43ULL, 
            0x523389A11B6E6E49ULL, 0x8B3DF54E71177CE3ULL, 0x62576F51D4572A7BULL, 0xE5F64BA5106E1C1CULL, 
            0xF60198DA9C15C37BULL, 0xB4E935C2B7C2B877ULL, 0x56B03C204126AE61ULL, 0x23D3049272F25B51ULL, 
            0x8443F1B7A986A665ULL, 0xD5A87AE5580AAD60ULL, 0x004F6E59A3CEDC10ULL, 0xB56A492712F757B9ULL, 
            0xFA1221981783F35CULL, 0x5A4EBF92DEFA84A5ULL, 0xDE9DA6DA568687B0ULL, 0xD2B34BB11AE9294CULL, 
            0x45348B14D7946970ULL, 0xC7CE085A72742D91ULL, 0x0ACBA041719EEC71ULL, 0x9BA9AC9F1E8CE244ULL, 
            0x6DCC9494B4984887ULL, 0x674A2BF324E24B26ULL, 0xC8BFB707C8B4EEBFULL, 0x48E4070EA92E7BD0ULL, 
            0xF61B66DF3D46D9DEULL, 0x539B1D233BB84A89ULL, 0xA16B41CEC44BED72ULL, 0xF7863A2F695144FEULL
        },
        {
            0x3AAF1A6CA2F4D3ECULL, 0xA731CD7670FEFFEAULL, 0xD21E205294EC508CULL, 0x115D48C2C64C8B27ULL, 
            0x16AE592BDB06D6EFULL, 0xD30673D8A3B932D7ULL, 0xEE9A4A9664F07658ULL, 0x466C6FC3EF6EAC22ULL, 
            0xDC922EB444D2C60AULL, 0xF8FF72473FB63D34ULL, 0xAA3C0FA259AC7CD4ULL, 0x229DB67D5E50106FULL, 
            0xA9F508156A27C8DCULL, 0xAC44E60D5EF538D0ULL, 0x1A701BDF4D52B4C3ULL, 0x9E0A2F9472345AE2ULL, 
            0xD194D27263459870ULL, 0xB42C0B3EF3184644ULL, 0x73014C6F8AB7CBF8ULL, 0xAC633CB071B3F72EULL, 
            0x74C7B2DC69F40D78ULL, 0xE83CFEAEB306CBE9ULL, 0x932678464BE5404AULL, 0x362F37D550944F1CULL, 
            0x13A74C4529686B28ULL, 0xB462061CD1B25A6FULL, 0x56C4A81BC23DF07DULL, 0x1E3FEA598583FC80ULL, 
            0x845C3C3E65C2CE55ULL, 0x17F26AB30DADC90FULL, 0x7AD06B8A3073DF52ULL, 0x52896C8DB1ED843CULL
        },
        {
            0x44AD40DA28D4E0C4ULL, 0xA887D52F1AE8DA03ULL, 0x97304D6AAD4BD5A2ULL, 0xF9757526F3ECD149ULL, 
            0x03F39FF08A15E632ULL, 0x341A018B11E60166ULL, 0xCC0D1C0AF1593AB2ULL, 0x399E5B5939915123ULL, 
            0xBFEC1AB9D80278D7ULL, 0xFC941D598CF2665CULL, 0x1E21BF2DD928A696ULL, 0xB7341560F0ED375AULL, 
            0x48C744847813C055ULL, 0x55331E93BACCD29DULL, 0x353F277537A09538ULL, 0xDA3CBC4E7B20EFFAULL, 
            0xA4F40E021453DBD9ULL, 0xC020A320D7AB056FULL, 0xB50E255ED84D3114ULL, 0xFAC318E5F01D9A05ULL, 
            0x4E697021BD8B4BE2ULL, 0x12429B9E2C733674ULL, 0xBA8955F0DC09DF5FULL, 0xED744B01D223AD0DULL, 
            0xD7C046CC37D02081ULL, 0x355F951C72A12292ULL, 0x09BEEBB6FF99F0CBULL, 0xFE530E6C8CBC6A0AULL, 
            0x9BC184C85CDBE1BFULL, 0xC1EE628FD9393FD9ULL, 0xA095F93A11794BE5ULL, 0x745872E420FE59F6ULL
        },
        {
            0xA3EBAA187D0E781CULL, 0x8B02F0A96A7C643CULL, 0x9B0632D2CC7BB0CBULL, 0xC088273D38F3828AULL, 
            0xE7246A1F85BA6757ULL, 0x8D71FB0025228820ULL, 0xE578DA723620D516ULL, 0xF966F178F17EA191ULL, 
            0x08C65C19B4DCEAB1ULL, 0x0F366501F935E415ULL, 0xAF8A2937B69C08C5ULL, 0xA7579EC76CF7DBB4ULL, 
            0x81F3B67806D4AADBULL, 0x4017D2C8568499A4ULL, 0x0284FAA98FECA9E2ULL, 0xF944FED724CEA9E3ULL, 
            0x07F4FF1CD41D22FDULL, 0x3AE5B18E3614156BULL, 0x7DF7EB8DF6162F84ULL, 0x081B544097B9D58AULL, 
            0x3C6C8887BE360168ULL, 0x735B9138D978B9DEULL, 0x8C9C06595A33738CULL, 0x764A3A022C4A705DULL, 
            0x6CFE13167A543EA9ULL, 0x616E81AE93C662C5ULL, 0xDF4590E0AFFE2EDFULL, 0x4C373197DA2AA4BAULL, 
            0x16E0C96103213846ULL, 0x8C50E5DDE9289F72ULL, 0x7687BC75734C5F23ULL, 0x45E0FB45E274E74FULL
        },
        {
            0xF305637EC56AB3C2ULL, 0xF6E2B2B0E69AC332ULL, 0x5BB03305F1928197ULL, 0xF63E459B280B05CDULL, 
            0xD23D9184EB3A5089ULL, 0x3C0878974CB314D1ULL, 0x81E0955548F19120ULL, 0x7E7022AE28B31504ULL, 
            0x0C7FC0EA5061F104ULL, 0x9972BCC85E6F4052ULL, 0xD55FB4AACCE9EE3FULL, 0x71057060AD8F1363ULL, 
            0x35040D3FE60BC13AULL, 0x36C2B30D4516BE7EULL, 0xE3A3C79D06B4BE48ULL, 0x6E389FC8AB0852E7ULL, 
            0xA2D0714993D929EBULL, 0xCB43F9BE18C11A1CULL, 0x37E277CAF44BF854ULL, 0xF310D58EBCAC74D3ULL, 
            0xE9B21647575B1FDCULL, 0x584847A0A3AF85B6ULL, 0xE7BBBEE24E5D7F03ULL, 0xBB1785461AD3AAF5ULL, 
            0xC3CB541EDE48A6B7ULL, 0x1F52EC545BC1C764ULL, 0x6FEC869249CE0EFAULL, 0x72F74FCE05F78531ULL, 
            0xB02FD413E99C9BD6ULL, 0x6262C84186A60A68ULL, 0xE4D240B01E4DD983ULL, 0xB34BBFA0F7876605ULL
        }
    },
    {
        {
            0xC541F8E5BE29A44EULL, 0xEF96395E5A5F6425ULL, 0xAAF5F6897F6665A3ULL, 0x7908AEFDFDBD47ADULL, 
            0xFEAEDBEC1A6CC2E5ULL, 0xDF4CC54E1217F557ULL, 0x43AAA1AB66209189ULL, 0x5B85B6ED2A1EB10AULL, 
            0xA25113A7FD6331AFULL, 0x64CEA1340BBC9386ULL, 0x4C62ECFB1E9A0639ULL, 0xD1B70656D891D6ACULL, 
            0x3D3856D3A24B8438ULL, 0x34B0BBD2CB9A5228ULL, 0x4708432E6807A024ULL, 0xD1EF61AB860BFD9FULL, 
            0xFF08C48EB8ACB225ULL, 0x8F6ED06F1761592CULL, 0x1F9D04706848FF3EULL, 0x488DE84C1A8C1027ULL, 
            0x78EC24A029AB39C0ULL, 0x0A34A62B90DEFD6CULL, 0xA0ED9CC6206A434CULL, 0x6779C9E8C65C087EULL, 
            0xF1C4250561D2E996ULL, 0xCAF13AD4133E068FULL, 0xCDFA35F69A9EDC2EULL, 0x98D3C6ADBFA6A5A5ULL, 
            0xC88AD2A65B71B9CAULL, 0xEA9E7129DF92D233ULL, 0xC634F3B018E952D8ULL, 0xBC3256140F1A7902ULL
        },
        {
            0xBF472952D569E725ULL, 0x5CB3659BEA7CE4C6ULL, 0xB54F7C9C9C12DBB2ULL, 0x9A960F63C3F121CDULL, 
            0x61456B25EA193F01ULL, 0xE9F96AC37026DADEULL, 0x1FF97908703A3D0EULL, 0x583E71CEE2C151D1ULL, 
            0x15506BC206F9D4B8ULL, 0x97EE1E7F7A1FB3A1ULL, 0x641740A186F0E6E9ULL, 0xB8A85463A02841D3ULL, 
            0xA31FBA5FEB2E56A7ULL, 0x727FFF3BFA0696ACULL, 0xB00CB2008F298F8EULL, 0x7DD499E9C8118B17ULL, 
            0xB1D36988ABB54D34ULL, 0x62D1F4214E45E562ULL, 0x6E6BAF07F203FEF6ULL, 0x6F36A3028BFC202BULL, 
            0xCB3858FFFB59C80EULL, 0x0E8002B3234289ACULL, 0x4FB0ED98F40EB28FULL, 0x5AE0E7BDB292087DULL, 
            0xF6D5301BD74280EFULL, 0x5B46317C8B6ADB0EULL, 0x222D97A00535D391ULL, 0x98EF4499F215F430ULL, 
            0x1A3B68CC14D1FA70ULL, 0x353A7AE96F50E301ULL, 0xC8FFE1ADDC2E6356ULL, 0x11B0B918444B60DDULL
        },
        {
            0x4005D9364C88B2BAULL, 0x571261696D689D3FULL, 0x808575A9E44AC37DULL, 0x1DA2058BFF21D0BAULL, 
            0xCB36BE503151C585ULL, 0x4C033235E62E079DULL, 0xC22C1530A27204FBULL, 0xC4350ED940E58411ULL, 
            0x88B3DEFA5AE49912ULL, 0x5850A804A33DCE15ULL, 0x97EAAE0252A9709DULL, 0xF80FE289C39B7516ULL, 
            0x2ED7AFA266B82180ULL, 0xA3589665A1DB8D22ULL, 0x946F6BFE49CE3A55ULL, 0x2C74F9F05713E1A8ULL, 
            0x203C44A30D597277ULL, 0x8AB1CD699AEA3495ULL, 0xB2B55D416FAB4A38ULL, 0xC61810B80AF377BCULL, 
            0xA7ADB6B09BFEE68EULL, 0x1A2A88B5A14CE9F1ULL, 0x19DA38A7B9B8FDEBULL, 0xE245C2F888021C5BULL, 
            0x920AA692C5DFF3C8ULL, 0xFA1650C8320BA732ULL, 0x570867684634DEADULL, 0xD214A54ED9E6B6D3ULL, 
            0xA42FCA1C9AF0CC81ULL, 0xDD6931CEF026C877ULL, 0xE0DF1CA893144F6EULL, 0xA0EE374DE72F0626ULL
        },
        {
            0x61AC063EE5EBE983ULL, 0x336C330F44A9F8BAULL, 0x078F626187942043ULL, 0x211BE75548061288ULL, 
            0x5B5960E13B084F21ULL, 0x6F6CEA4766B9DA7BULL, 0x43880A28B09B3FBBULL, 0xC2999C62E9CFA7FBULL, 
            0xCC60F94B8F590991ULL, 0x458F7DEC75F546ACULL, 0xA65D3AC19D8B1CEFULL, 0xF855783DC6148D7DULL, 
            0xEA6C91E53EC71767ULL, 0xAA1952A71AD1CF78ULL, 0xB33B03DA5F7AE2A1ULL, 0xF2ABE97856EFDA57ULL, 
            0x2E7FD0253ACB8989ULL, 0x8B46A30A633072D4ULL, 0xF448F72A9465E0F5ULL, 0xA7E4705AC67010B4ULL, 
            0x980A9DED6C1192F8ULL, 0xD3E8AB1A0A26345BULL, 0x379A8B2ABD98A977ULL, 0x0EBE3D10DE4DB00EULL, 
            0xB9CAA726BD85C84AULL, 0x2ED0A28FBBB2FE53ULL, 0xBC045A7C9787A459ULL, 0x51B022257BF78172ULL, 
            0xA7084D5F786B4FEAULL, 0x4145037FF1B8CE8BULL, 0x980E5A5C62C7A3B8ULL, 0x61910FDF22E8A99EULL
        },
        {
            0xD1D7271BA7BB30A3ULL, 0x48F36F4FFE25416CULL, 0xE440BAC541E896DAULL, 0x933E4D26608FA115ULL, 
            0x503660811B525296ULL, 0x7593ECB8A0326B4AULL, 0x50BD622A130BF87AULL, 0xCE5CA1014E4D2170ULL, 
            0xE37E23B9936777BDULL, 0xD3017D40D4014F63ULL, 0xDA9F3929531B38E3ULL, 0x066B2BCD752C61C3ULL, 
            0xCC5DAACF5A1C436BULL, 0xB568C80EDF199415ULL, 0xE7B8302F79DE74EDULL, 0xFD7FCF4E5477E744ULL, 
            0x815FBCF545705BBFULL, 0xDF55078DB0222D43ULL, 0x9B465FE4730F8B84ULL, 0x755E14B94B99E052ULL, 
            0x15B0802E0921ECBCULL, 0x3195ADD0F846E1D1ULL, 0x29986CAD5848A6DDULL, 0xF5116EF7B066D22FULL, 
            0x181237B40AC6E120ULL, 0xB3B2BE76A9C85539ULL, 0x3448269DD11263AFULL, 0xFE75E201D1310341ULL, 
            0xAC9BA7AF51945AE6ULL, 0x3A1A650BA009750FULL, 0xE8D84DD668E56CD9ULL, 0x9A2E81F190E0603BULL
        },
        {
            0x8F11EEEF6E26B7AEULL, 0x83D0977F1C629E18ULL, 0xAEE64054D42F2BC9ULL, 0x7BD3AD6522A7C319ULL, 
            0x865F485F1424AF62ULL, 0xE9616AFD3DF45606ULL, 0xF3661EDF2941067BULL, 0x3C162258224C98EEULL, 
            0xBD6D59C7C731D880ULL, 0xEDC3B99F21A5E705ULL, 0xE2D22813A357C4E6ULL, 0x35F10E51712111C4ULL, 
            0xE62E4CAFEA86F66CULL, 0xE45ABA388307C8BEULL, 0x6B4CB844D09FBC71ULL, 0xDF3B548F18A8B908ULL, 
            0x60B06230E2AA6F3CULL, 0x792FA0FE43449CC1ULL, 0xA607F4B916C9BA42ULL, 0xF3FEBD3984F81773ULL, 
            0xB182D3E1BB605F61ULL, 0x4EABC13A43F1BE7BULL, 0x5AB5CEB7181206FBULL, 0x17B9761652813C2EULL, 
            0xD6608ED39C2C3E38ULL, 0x99910A4637FBEDCEULL, 0xAD87BFDA62655AE3ULL, 0xF0E58EA11361CCB5ULL, 
            0x5CB76BF23F51A38EULL, 0xEFC87D0C6290E4FAULL, 0x3D4232414E7E3C99ULL, 0xF93E3B9A1E418819ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeyRotateAConstants = {
    0x2D4B0F7631C75DFCULL,
    0xECCD87E1199A3910ULL,
    0xEF7D0F130B6AB4ADULL,
    0x2D4B0F7631C75DFCULL,
    0xECCD87E1199A3910ULL,
    0xEF7D0F130B6AB4ADULL,
    0x954BB2B8D6462BEAULL,
    0x6B46DE443FADA46BULL,
    0x3A,
    0xE1,
    0x7C,
    0xB7,
    0xA8,
    0xA7,
    0x58,
    0xE8
};

const TwistDomainSaltSet TwistExpander_Procyon::kKeyRotateBSalts = {
    {
        {
            0xB355DB2A1AC6A0D2ULL, 0x94EB3A260C8C2817ULL, 0x5613DD7D3C391F57ULL, 0x68E9C9C4A66F1FB4ULL, 
            0x30F5211A14D53629ULL, 0x2FAF2C8FD42FC0D5ULL, 0x884E62A855171CEFULL, 0xD12C050FF604694DULL, 
            0xEB363C27B1D1EF70ULL, 0x587729C26D7C8814ULL, 0x77D082BC128E02BBULL, 0x8E74E1093D8FA6DCULL, 
            0x32F1CE4DEB2DD520ULL, 0x82FCB2A08C042C7CULL, 0x8AE0A5448426DBCEULL, 0xC9D41FE322596C8BULL, 
            0x2919B5E8B7E7D5B7ULL, 0x93E12A10D71448D4ULL, 0xAC481ED800587F14ULL, 0x5C59A79D5B743598ULL, 
            0x1D6198AB304377C1ULL, 0x51062106310229AFULL, 0x31D89A671A4FFBDEULL, 0xB27D596F73542981ULL, 
            0x319C169A515FD1DFULL, 0xA042213DFD1BFFE3ULL, 0x60C81C468E510E92ULL, 0x74A6C43777E9F806ULL, 
            0x6194D4987E5C9420ULL, 0x2C313E7EA51D55E5ULL, 0x296D3FC5D5C7ABBFULL, 0x715E2AEE89C68595ULL
        },
        {
            0xF7DA5C881583A017ULL, 0x2A2932EA192EFB47ULL, 0x0DC7110E780290D6ULL, 0xE21AB18ED5F1D1D8ULL, 
            0xB9B32EFA3BEDCB0AULL, 0xBC9195DF541E5B96ULL, 0xE30F6EB1DB7F7BBAULL, 0x89F67CA74E926353ULL, 
            0xA5C54C03C7E4D798ULL, 0xA8E6DB2D6E32B3E8ULL, 0x8B1BB7F94EFDA78DULL, 0xF80DC2BAED78F1DBULL, 
            0xB91EB808406BDCBAULL, 0xD6C4412FD60DABF5ULL, 0x8473D3EA61018BB9ULL, 0x2C2D5D569D03D513ULL, 
            0x2C6CA7B6DE0B2A4EULL, 0x927275FF122A3A57ULL, 0x7CAF1781793669E3ULL, 0x3184444604774251ULL, 
            0x61DB308A6DC3AC9CULL, 0xAE9E3865D878DA80ULL, 0x149D396EFA0B02DEULL, 0x561719E352C21BD6ULL, 
            0xABEEB503FA5BCD19ULL, 0xB73492D7E7A3F828ULL, 0x1F0BD0BFBD5F33B0ULL, 0x773883EAB41111D9ULL, 
            0x5185B2E411DD6263ULL, 0xE9891797321E43F7ULL, 0x1638C4B80812589DULL, 0x2E9BB2A7EFE3450EULL
        },
        {
            0x362DD3CB535BB9D2ULL, 0x763953DAB19EB9B7ULL, 0xEFF78BB09997F26DULL, 0xA0662DFF4B5FFF19ULL, 
            0xE79C617D5FA8B0CEULL, 0x126E019CB1B95689ULL, 0xDB34352B2F23A252ULL, 0x2C3517FA4D328158ULL, 
            0x07723B6ADB5FB6ACULL, 0xF51AA1AD74CEEE60ULL, 0x1370B83B5A17E0EFULL, 0xEE65C26B73207ED4ULL, 
            0x5048CFD9EF6CBFD3ULL, 0xC64AC8911B650593ULL, 0xD58CBBD4390C63D0ULL, 0x036DE350077C560CULL, 
            0x8C11B9265F866A86ULL, 0x9309C969EE7D5DF7ULL, 0xACF458650AB4D551ULL, 0x9D01AD98DAC111B9ULL, 
            0xF39B38613BBECDB9ULL, 0xF72F9381F6B08724ULL, 0xD118088338938D1DULL, 0x05A9D1A62C10545BULL, 
            0x0F43DF2B4EA767B8ULL, 0xACC8D0FB54A74436ULL, 0x78A42FED623D40EDULL, 0xCA290ED5F2607E35ULL, 
            0x6DA6F0FE42888B94ULL, 0x6C5028319436D981ULL, 0xF5BB7DEAFB84A833ULL, 0xC6A1CD0BDD7D1578ULL
        },
        {
            0x2E397F2A1F99E591ULL, 0x2C897599CCE4A0A5ULL, 0xDC94457CA9D1D111ULL, 0x528875AD59F97A65ULL, 
            0x552F7D5FEE1D88B9ULL, 0x9A536752F3DF6AA9ULL, 0x7C12AB4294F095DFULL, 0xC0190D093FC3455AULL, 
            0xDDD025D93BBF178AULL, 0x2CFF416E96973A42ULL, 0x68390DB7DFD2F265ULL, 0x6F09C3BFF7E95D36ULL, 
            0xC8E61DC8EB59B115ULL, 0x78B2CCCACC1EE560ULL, 0x6AC86ADB30535621ULL, 0xB1665432276B9DB6ULL, 
            0xD7A4A6312F2B4B7CULL, 0x0D8CDBA36C8868DEULL, 0x77164ACF750FC460ULL, 0x151976CD9AB4587BULL, 
            0x01C4569EBB9B97B1ULL, 0x08D3790CD13A6FFEULL, 0x74FBF84EEA9CE746ULL, 0x49132BBE4B5814ECULL, 
            0x63DE3768D44AC06EULL, 0xDD3FEA9A916771FFULL, 0x421D780A4035CBD4ULL, 0xB127475346E3CCD0ULL, 
            0xD3484591E8C57E36ULL, 0x1ABDEFA305511E76ULL, 0xE29525F7586B3B6BULL, 0xDD7B5ACBC6517F7AULL
        },
        {
            0x1FE776C6E320D10EULL, 0xA59A1EEAFD611862ULL, 0x342CA3D771CACBD9ULL, 0xFC2F0C990A01A2F8ULL, 
            0xAC69FD511268A1A1ULL, 0x104FB402B56D1DF1ULL, 0xACE7CC6FA448F75BULL, 0x804EDE0F4059D68BULL, 
            0x85EE20D1661CACF4ULL, 0x1ADFECDF323AFA34ULL, 0x7985899FBE29FC52ULL, 0xD4C098B570A13E1CULL, 
            0x8E0D9779A708EC7CULL, 0x0ADBA15A0483F510ULL, 0x52791BE891F1E5EFULL, 0x5F56EE658B9C203BULL, 
            0x7C1DD142C5D9610CULL, 0x70659093CF47BDD2ULL, 0x7F6C431F66F6B8EEULL, 0xDC3DE61C3D05A2BDULL, 
            0xE445B2353C714013ULL, 0x32BEF2BEFB7D7217ULL, 0x18D0B41E988EDCB6ULL, 0x8AC0162EFD702394ULL, 
            0x653732DF4B95805AULL, 0x137E34CB2DF3DB24ULL, 0x2E8EFAFF10DEFD40ULL, 0xC2E8F782902452F8ULL, 
            0xA2C1526C9A558D49ULL, 0xA50A45309C74B621ULL, 0x0F4CB05288DC9D52ULL, 0x4A51D777CA5B1EEDULL
        },
        {
            0xAF9ED657DF58AFA8ULL, 0x8F0A2D3C2AA8F75FULL, 0x7C7354D8C57F52A4ULL, 0x5F540F0AD5E204D7ULL, 
            0x6701C4E82560428EULL, 0xEC9E48AA646C8CB5ULL, 0xF925CCE5B6753B41ULL, 0xBD758435510999A6ULL, 
            0xE30BF28A58D80826ULL, 0xED259E336DDC230AULL, 0xECE71FF0911B6AE8ULL, 0xFA13B6A0C8882994ULL, 
            0xF3F9134F5A9C99A4ULL, 0x785A492D3BE5035CULL, 0x5D4BC866AB6F8658ULL, 0x0C78CE4016F7C92DULL, 
            0xD88B670FDFC7A588ULL, 0xBA2BA1FD02880B29ULL, 0x6B581ECF9FE17138ULL, 0xF61FD5A303F126D4ULL, 
            0xF863B36B3D91A588ULL, 0x5DF1D515164B16B8ULL, 0x40802E78D7E455DBULL, 0x62BA9FF82773AEBAULL, 
            0xB5191B4DAE4838FBULL, 0x3949CBDFB1785A36ULL, 0xB3AB9E2DDC2046DAULL, 0xA393E451D4D18AA7ULL, 
            0xEDB489AEEB822194ULL, 0x954E15CC2C56DDD4ULL, 0xB292BA6726BEA306ULL, 0xF7D4EB6020AEAAD5ULL
        }
    },
    {
        {
            0x4645E76A31FF1B5EULL, 0x6EAA0437C0D2EA59ULL, 0xF3ECD0289BEF7811ULL, 0xFF7AFACB8525DC98ULL, 
            0xE21607E9AA1A1626ULL, 0x844825197B5BBF8FULL, 0x7782B563FFA50E88ULL, 0x862EA1FB60366894ULL, 
            0x1C977F9CFF795BD3ULL, 0xDF9C33A2B16AC453ULL, 0x134C7BA567057000ULL, 0x6581C82036382768ULL, 
            0xAC343EB882F2A4C1ULL, 0xFFCEF1B6C82BDCDDULL, 0x865BF0E37D3A921EULL, 0xDC9045CED36B6463ULL, 
            0x48BA34111F1299BEULL, 0x610EE33BD0BC2A20ULL, 0xCA80C37A04FC4406ULL, 0x6311B06F11436A0CULL, 
            0x13B36A9281F3CF49ULL, 0x533BF99370116078ULL, 0x31FEEE1609F03B2AULL, 0xCCECE4FEC2F5E30EULL, 
            0x16B44FC1E9F1CE9DULL, 0x3D8546D2E34EBAEFULL, 0xE1FC4D992136E4F9ULL, 0x1B99A8D80B832D45ULL, 
            0x9BD8E3FF4D0B4B7AULL, 0x3F5A5822F7306967ULL, 0xA00687A3BF369B1BULL, 0x343F1E211E1FF4EFULL
        },
        {
            0x935DCB4F2A1A54C5ULL, 0x29410E80562A3202ULL, 0x631F5972FD04C649ULL, 0x4761928D8F641F19ULL, 
            0x143720E1153504D4ULL, 0x05AE21114D4AACACULL, 0x2B516B251D0A2584ULL, 0x60D04C695391124AULL, 
            0x4D08F2A1315D5A86ULL, 0x2BDD8DA1D405C079ULL, 0x81BE8FF11D53E74FULL, 0xA6E14B58F00FCFEDULL, 
            0x9673FDB16DF307BAULL, 0x5B59B1B7DF7054FEULL, 0x7A01087968FFF0D2ULL, 0x867545367F297D8FULL, 
            0x4A4933DD9F1906EDULL, 0xBCC3C5D3FDE6F84DULL, 0x357526F575CA5043ULL, 0x4BF41F075CA95EA9ULL, 
            0x465D5FDD2504CD64ULL, 0x42ED6A63BC0AC76DULL, 0xB72B1870C2E1ACAEULL, 0xA210BBC3BCBC3631ULL, 
            0x06808EA29AD4CBC1ULL, 0x54B4153EC4FDD3A1ULL, 0xABB92161A5DFF1F8ULL, 0x2A9EF755418865FCULL, 
            0x3DFF785E2431D302ULL, 0x3C2F391215D29484ULL, 0x1C40AE3F37F542B8ULL, 0x1FBBB69ADCE8753EULL
        },
        {
            0x49FE5DD1DD201AB2ULL, 0x55E57172349D1096ULL, 0xB4249E2AAED484B8ULL, 0xC79D509F0FF230F0ULL, 
            0xE58BED8FDB40C767ULL, 0x4DC65B4EF29E1FA4ULL, 0x8D69763231B42EE3ULL, 0xEAE72E036000652AULL, 
            0x4000BF9C20C14BE0ULL, 0x7F63C93B9FE22D4BULL, 0xBB873D38688CAEF5ULL, 0x7DED555C4CBBF991ULL, 
            0x6452EFE1C03CD8FFULL, 0xB6C0E2424BC29FDFULL, 0x429D3398816FCFBFULL, 0xC4B661D57C235518ULL, 
            0xA4A3BB10D1D60C04ULL, 0x2DD75258C9A4DB67ULL, 0x323322842A0DB834ULL, 0x2FA87234F098B239ULL, 
            0x30475EC54672FEEBULL, 0x188961EE5BFBB664ULL, 0x86383212C4CAD78CULL, 0xED3D9EA2614FADC9ULL, 
            0x426DDAECE958977CULL, 0xD9A1A04614F33B0FULL, 0x0E05B72D95A90CFCULL, 0x7667956A43216A95ULL, 
            0xD30BEFA209C7A62CULL, 0x36A3DD86DD50F264ULL, 0xDD236DC445D75B2AULL, 0x267E51CEFB577718ULL
        },
        {
            0x4A818A14DED4685DULL, 0x79EA3AE5C7A20231ULL, 0xDDF72D39992F6C62ULL, 0x1009D27FC6FA298FULL, 
            0x77890370BFACE620ULL, 0xA83CF6960E40C742ULL, 0xB67B5918F70BC500ULL, 0x9EA1C71A8A1C41ECULL, 
            0x963E84E1982CDACCULL, 0xAD4E31F856561E88ULL, 0x7E587764D1B203C8ULL, 0xA114067E968A128CULL, 
            0xCCC9F46A057F2A00ULL, 0xAF9D1D0B99CCB302ULL, 0x6415D19D3C1E4029ULL, 0x2FF1F21BE445D3B9ULL, 
            0xE2EF0C35857EC389ULL, 0x9397F95AD4BC6D42ULL, 0x8C28554AD705DC65ULL, 0xC4E5888C430F2A0CULL, 
            0xF6718FB8FDCC1573ULL, 0x244294ED4E21F81CULL, 0xD0D020ED823B64E4ULL, 0x714F7CBA31CC6768ULL, 
            0x769F7A8D79EE9C48ULL, 0x1899DB01E7CE22B4ULL, 0x5D29C13E7282CBD9ULL, 0xC19A42C602550F6AULL, 
            0x93734CB1C983B2F5ULL, 0xF6FD69A0D97085D1ULL, 0x5CFCD700B24C1D89ULL, 0x35D6875BF05E4ABCULL
        },
        {
            0xEC8C62CA49E3DA5FULL, 0x769056AA323642EFULL, 0x7810C8D47F930132ULL, 0xE1E0B49034677677ULL, 
            0xD37F41355DB5FDC1ULL, 0x5F597EEB1F8F5EF4ULL, 0x764A0B8794447E0AULL, 0x5191583ACB661158ULL, 
            0x08AFB27723011488ULL, 0x5CCC70E4E0169CD3ULL, 0xC55D136812272F6DULL, 0xD449E6AF3D5B54A1ULL, 
            0x76D1CFB8908A2C67ULL, 0x26F8377578D445A3ULL, 0xE646618E7DED2285ULL, 0xBC081B5BA606860CULL, 
            0x73692608DA3AA69EULL, 0xD9E992C8AD701C25ULL, 0x9864D2B3F52C63CFULL, 0xD8DA72F55BDB1220ULL, 
            0xB5757209172BDAC6ULL, 0x254A6EC085EA09C7ULL, 0x78730FE775AC49A5ULL, 0xB52D82EFA80CD725ULL, 
            0xD58B240C4CF0E220ULL, 0xF11C70B8F080343AULL, 0x87065280B70A7707ULL, 0x29E35C7AF4B0B110ULL, 
            0x2E58859C06026579ULL, 0xD56D34B98344E913ULL, 0xB444071C93F11897ULL, 0xA3647AC7275011CDULL
        },
        {
            0xD4A3480106DEA876ULL, 0x64FC3B40BCD1670EULL, 0x9B8AAC2FBAD1C7BDULL, 0x4034D4018B2A932FULL, 
            0x0FEE0DD1337EEF99ULL, 0x0661F322118647E6ULL, 0x68E0B7C24AAC71E8ULL, 0xB783A861D441B52DULL, 
            0xBDC683C8189824BFULL, 0xFCDD15BE9FC24DD5ULL, 0x5C6B38C5B35EEAC3ULL, 0x210887F9DF879EB9ULL, 
            0x96382691DDA54B92ULL, 0xF1A6455CFE25E4EBULL, 0xC96856D2479A5CBBULL, 0xED710B7067D2CED8ULL, 
            0x30163BBCF5D3CB61ULL, 0x9E6145D080165C4BULL, 0xD5FED9D9C782307EULL, 0xA00C9BB8D3F17D05ULL, 
            0x87334F1ADF2A709DULL, 0x052A15B9205E378DULL, 0x26ED1FEFE4DC0679ULL, 0xC3B32AD6A7F7F273ULL, 
            0x8EF0A7A9F5ADD0A6ULL, 0x19F80B03DAC32874ULL, 0xDE7121F9AE87433EULL, 0x58045BB7DEFC79EEULL, 
            0xB3570E45DEACB338ULL, 0xB8F226023DEDCAC1ULL, 0x04D8F7929375234FULL, 0x6256750B87FB9FF3ULL
        }
    },
    {
        {
            0x0FFEE22275738E2DULL, 0x732A3E43426C0800ULL, 0xEB1714DF39AD14F3ULL, 0xBC3EE77A7D141C13ULL, 
            0xC686C0CAA3712B47ULL, 0x8B2F30AC33265FFCULL, 0xD34DF81CAB30D4F8ULL, 0x551ACAE95F60A26FULL, 
            0xF32221E44A5345BDULL, 0xEB60F56FCE4C31B3ULL, 0x191893B83D1C9002ULL, 0xB7B7A22A6BF2AD86ULL, 
            0x3D9D0F61FB2B00BCULL, 0x1863E54F2048B151ULL, 0xEFBF8D46EB9EE727ULL, 0x98549FEDFF0BF014ULL, 
            0x6D2B7FBD4012FA5EULL, 0xAF7F4849CAE46700ULL, 0x783E4CF6821BD57DULL, 0x92DB9AD5434AE59DULL, 
            0x88C760203CA86B73ULL, 0x29729C7231F90CF7ULL, 0xA3637CF51960AF79ULL, 0xB1DFEC656D791FFDULL, 
            0xD424D6F1B66E0189ULL, 0x87DAA5B347326B29ULL, 0xD794494548B24C73ULL, 0x2DA0674F716ED84AULL, 
            0xE99766E8A4E735F2ULL, 0x615836F08779F728ULL, 0xDC61EDD3341D0380ULL, 0x40EFD3A7FA84835BULL
        },
        {
            0xFAFB585A334D497DULL, 0xDB189DCC1640CDCDULL, 0xF382FCE53B7D49DAULL, 0xCD10EC95701FE3BBULL, 
            0xE4E9A65254669167ULL, 0x4EAAC717B028CF53ULL, 0x3E719A821B2AF105ULL, 0x40030C018B214698ULL, 
            0xDD3C08F9A6B4C781ULL, 0x7C99CB2EF781D6F4ULL, 0xB7770885FE5655B1ULL, 0xC82606F6B70E70FBULL, 
            0x7ADD3EE186568443ULL, 0x9E39CA3EFF754160ULL, 0xF13B22ABCDD45F6AULL, 0xD8F313494ACA33D3ULL, 
            0xD6BA25056EBCCB10ULL, 0x5C96AA8A0932F112ULL, 0x1685EBCFD18B58A3ULL, 0x157EEE1095448601ULL, 
            0xB8D4B284670A4944ULL, 0xFF0A8E89A023AE6FULL, 0xE60544BB8CF918CCULL, 0x0C748BA76A5E942DULL, 
            0x95BC07C1B03E283DULL, 0xB71CB82381C682D6ULL, 0x93E14C60B7BF8DFEULL, 0x093A85FAB658F218ULL, 
            0x41583577BE702BB5ULL, 0xCBDEDFB4C71AE55DULL, 0xAB3422712140CC87ULL, 0x299BF970534EDFFBULL
        },
        {
            0xA07C79CD423BADC4ULL, 0xED3BB65A71B91783ULL, 0xACAE632FDD802F52ULL, 0xFDA3A2BB5A5A8EBDULL, 
            0x457F981C17037958ULL, 0x2B7751A426DA4A59ULL, 0x0B334992423E5168ULL, 0xA68803E4F07CD796ULL, 
            0x5534692080CA2C42ULL, 0x33663BDB347E0327ULL, 0x1DE4B944E2312532ULL, 0x6C9D5EF2860340BCULL, 
            0x34ED30B3D74CF000ULL, 0xD16A031738FC0C07ULL, 0x229255214183B405ULL, 0x69190FFDBBD588BAULL, 
            0x56E9772E095033A8ULL, 0x6DB90CE0A63E9F47ULL, 0xB134F8BB74D05235ULL, 0x2E0BEE32F0E15725ULL, 
            0x8B19544356C0E63CULL, 0x4076F4192251F51DULL, 0x02CBFAAF26FE4BB3ULL, 0x48A2D1DD66250732ULL, 
            0x59677DA24D2A53DFULL, 0x0B4D7AAD004438C5ULL, 0x432FDBCA523E24ABULL, 0x36A24621C678FAA6ULL, 
            0x8A5E154D1442858EULL, 0xE91AF265FF20FA13ULL, 0x08834359F344E31FULL, 0xEF816EF6B0AAFA71ULL
        },
        {
            0x08E4F32F388F7A7EULL, 0x5992915741C1A0BAULL, 0x1F72EA7286D31335ULL, 0x291E476A11221364ULL, 
            0x640DBD449000ECE0ULL, 0xB3A79CF5A7B6179FULL, 0x28CD8B80C71F1603ULL, 0x43C26FDA9BE1DEA8ULL, 
            0x2FB28D00D40B8FECULL, 0xDCC537ADF03F8BDDULL, 0xBF9E605AE350B100ULL, 0x9FE1AB3C940B79FFULL, 
            0x5D1D7416588D0A27ULL, 0xB4F4426DCACFBC4EULL, 0x622EDDC297CB9B53ULL, 0xD578B8D6E5FF4504ULL, 
            0xA42F22A3E9D55BE6ULL, 0x430E045F0F2FA087ULL, 0xE05CE95109B6CCFFULL, 0xE4928DDD4B60EBC3ULL, 
            0xC9D07E063CC392EAULL, 0x0C118928C5C3118EULL, 0xE19655A9013EB864ULL, 0x6D70A73C277CFE7FULL, 
            0xE58ABBBC3A713004ULL, 0x71BA64F8CC28A361ULL, 0x7E7E40E6798FC4ADULL, 0xDD4B6FD436CFCACBULL, 
            0x16AD8C22C5689D1AULL, 0xB75DDF1E640674C0ULL, 0x2159739360C1426DULL, 0xB415C887AEF31652ULL
        },
        {
            0x643F9B9DD97333EFULL, 0x44B8EE90A3F627E1ULL, 0xE2B668E208D274C9ULL, 0x2CF4A138F7F7BB5CULL, 
            0x57B436612F8C97C9ULL, 0x76B1858269FFEDA6ULL, 0x763D6E3D45D29858ULL, 0xDF27EFDDFCD31BA0ULL, 
            0xA68E3CABF4858DA3ULL, 0xCE9CD3B27B3D669DULL, 0x6458D49424041FDCULL, 0x4AEBAA22997138ADULL, 
            0xC06A54E60B39D39BULL, 0x30C66E67E275FBD4ULL, 0xA031683CDFD21976ULL, 0x4508B45F5DDE959CULL, 
            0xC980A96B2D977158ULL, 0x9D90513020F39C7FULL, 0xFA3AC6C5B2EA0AE2ULL, 0x0A9AD3D532E44FB1ULL, 
            0x5D9A2B1C0B9DF5C8ULL, 0xB617F636AA6C06F0ULL, 0x119D9DCAA03E3B63ULL, 0xFF3BF28FBB3ECA4DULL, 
            0x7DF4867362132315ULL, 0x32089D73800504C5ULL, 0xACDFDAA51A0C8C7CULL, 0xDF01683A1FD8ADB1ULL, 
            0xC25EB45BC3F03797ULL, 0x05255F064E9B0C33ULL, 0xE864897B7E66A5CDULL, 0x464B25C3D5224A84ULL
        },
        {
            0xED9ECDB8E43C8F0CULL, 0x03F3FB9D66DF03B3ULL, 0xA5D0050E4D1C7A4FULL, 0x5BD13BD16A105450ULL, 
            0xFD86524EA7E479C9ULL, 0xE4B7049C08E9C387ULL, 0x42F1E1A2850088D4ULL, 0x8DCBB85F03386A5AULL, 
            0x1D3ADBC5C2AE141AULL, 0x63A699D73F801F60ULL, 0x9C5082FAF2B547CCULL, 0xEE0AD1756512EE7DULL, 
            0xE4CDC09B19178BCFULL, 0x63A1725AF96E5185ULL, 0x6F7A66082B53719FULL, 0x314526A3C328E6F7ULL, 
            0xE3C41C9DD75B95DFULL, 0x5622AEC8DC4EB0D7ULL, 0xBFAAB10538FCDB5DULL, 0x1AA9B63B529A4819ULL, 
            0x3B2499F2DFEA45C2ULL, 0x10B2049D2EBE3C52ULL, 0x9A81E849C91FC815ULL, 0x6D4669CC2F58ED83ULL, 
            0x822447D86BAD650CULL, 0x569B20FE17399C0CULL, 0x51DFB60D23276EA9ULL, 0x4E9183A407CAF409ULL, 
            0x9B066FB7CA58704FULL, 0x1A3928E868DD92C3ULL, 0xD46BCA51DA078D3FULL, 0x77F02D6F3E2951D5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeyRotateBConstants = {
    0xD684D369E45C339AULL,
    0xDBA3CCAB9E4CA143ULL,
    0x4E4A6CDE6072222FULL,
    0xD684D369E45C339AULL,
    0xDBA3CCAB9E4CA143ULL,
    0x4E4A6CDE6072222FULL,
    0xEEAC372454703B1CULL,
    0xB91ADBFF56822E12ULL,
    0x11,
    0xB1,
    0x88,
    0xEC,
    0xB9,
    0x14,
    0x57,
    0xC8
};

const TwistDomainSaltSet TwistExpander_Procyon::kKeySpawnASalts = {
    {
        {
            0x3AC37984BDF43C97ULL, 0x32F177BB161A342BULL, 0x56DC63CE924B5984ULL, 0x834358B4608F1152ULL, 
            0xBE227F9F9402F846ULL, 0xA139DF1DB87E6F04ULL, 0xC401A95900B3A982ULL, 0x360CFF35D05272ECULL, 
            0x75BCE8F0BE44C975ULL, 0x3B7EC8ABB3F74CD3ULL, 0x5C9855DBCDF085C5ULL, 0x836EF0D9F84E91A6ULL, 
            0x0DD4B5FE7710DF52ULL, 0xE4FA7845133A1581ULL, 0x292EABBE8673D70BULL, 0x5DBD84FCA0CF0A89ULL, 
            0x5ED6F81232EF1740ULL, 0x356B61CA3E73C3D3ULL, 0xCBC5B341DF028C07ULL, 0xEA5454008D34A932ULL, 
            0x80774974BF3AF64FULL, 0x56D6B42014EE2C5AULL, 0x1806216C5508466BULL, 0x669EB69086A12AF7ULL, 
            0xB2F7B034936EE5BAULL, 0x4060DE05B699126CULL, 0x6672A642A85FE248ULL, 0xFF41EB8AEFF70946ULL, 
            0x669517BBC68B0559ULL, 0x048F5F436D21B2B4ULL, 0x26009A4CA5B5EE3CULL, 0xC29CFE4BFC76F2FBULL
        },
        {
            0x3077C665139B27D1ULL, 0x698858B22F85CE97ULL, 0xBBA2BFCC0F1CA7E0ULL, 0xDE022EB9BA045731ULL, 
            0x19912B4E8B41107BULL, 0xE2CA507FBB007B7DULL, 0xB57D5FF9B8FE795CULL, 0x35924C31AD026BB4ULL, 
            0x3FA3A1DCBBD4F6DCULL, 0x3089F1C9ED665A25ULL, 0x546B781DFBD3DDA9ULL, 0xA08BF73DF9FD1077ULL, 
            0x54E3ED0208D18F59ULL, 0xB5D85EAC02883FE6ULL, 0x2F7EBD3E68706A76ULL, 0x02BBEA9A87E049E7ULL, 
            0x8C0D8E26CB0FA35EULL, 0xA99F140B01B47922ULL, 0x3B72A5CFF7A36F53ULL, 0x5B9C0E62157044B9ULL, 
            0x26BD8681CE8EB6ECULL, 0x8E1063F85A1132D0ULL, 0x0998BDBB5DF325D6ULL, 0xF38EFE6FDF32F6BBULL, 
            0xAA8ED549A6804F18ULL, 0x017EE05B42FB9652ULL, 0x7BD96E3BAB56EDCEULL, 0x7620AD602DBE4533ULL, 
            0x31E3DE40C37628D1ULL, 0x064B9DD892CDE728ULL, 0x5338813F073F9C7EULL, 0x32AB986B29F203B6ULL
        },
        {
            0x84F1533F3A5BECF7ULL, 0x44665C9111408D1FULL, 0x1929FBC1325B33B0ULL, 0x9A06A8AEEE65430FULL, 
            0xF1F655764DF17256ULL, 0xF2CE6828907FE80DULL, 0x07C090EB7876039BULL, 0x749E23FB63D866B8ULL, 
            0x2BC43B3FFEE09BE2ULL, 0x811BC83CBA496C18ULL, 0x767C7A71C3567058ULL, 0x542FA59ACF74DE86ULL, 
            0xDAF40E0EBC8E49D4ULL, 0x8242FAC0C21AE205ULL, 0xADD250E1C86F24BAULL, 0x37301EB5702E7657ULL, 
            0x999B047C845A921CULL, 0xD9718AEC20AD65ACULL, 0x4E2BEAAE8652CF11ULL, 0x80412C53F2A22F6AULL, 
            0x2EEBDEBB2318E511ULL, 0x1B89B30AE7399561ULL, 0x748CB49F0EACCBC6ULL, 0x8951939C2BF53C8CULL, 
            0x5F7850C64E63E144ULL, 0x622F5A5872B78882ULL, 0x26EF6DAA82456EE9ULL, 0x778A284E7CEF9ACFULL, 
            0x5BA58795F498D191ULL, 0x313BA39B3F16F66DULL, 0x85B1768BCE2F35BAULL, 0x0B560C6B1CF058A2ULL
        },
        {
            0x23F64FECD6850ED5ULL, 0x46F22C328F2E7AA4ULL, 0xDC3339CB2DB0EFA6ULL, 0xA8DCD14ED9B416BCULL, 
            0x50B4798A09109418ULL, 0x8C8F03639BF0201EULL, 0x2ED8848DD5F33DCAULL, 0x485732E72A44B034ULL, 
            0x9854B57B871DD18BULL, 0x53F3A905661ED78FULL, 0x48FF1CA199C56980ULL, 0x150603FF53489E70ULL, 
            0x41A8668CC160FBBFULL, 0xEA4AC18BEFE77E56ULL, 0x83137B9A1D5AC9BBULL, 0xD068F56B236C801DULL, 
            0x7513C104A2D21CAEULL, 0x964EDEB004D92785ULL, 0x0696F71CC3516383ULL, 0xA177B4022742F5FCULL, 
            0x0BB32A66758F382FULL, 0x8DFB46BFA6F0BEB4ULL, 0x358E103A609B4F0AULL, 0x87B510A5280F4230ULL, 
            0xD2AB8F762BDA549BULL, 0xAD2FCF1480F691A9ULL, 0x5D5ED29DB67F76FEULL, 0x80499CC8BD09FF0DULL, 
            0xE23DFD79D672C9BAULL, 0xC4479E9318961C94ULL, 0x5BE559685024DA05ULL, 0xE7D346FB19E66942ULL
        },
        {
            0x25DAC0AC1D9FFF70ULL, 0x6D0EDB33ECC028C5ULL, 0x5A6FB0CAFE2E39D2ULL, 0xF0763F25D7124358ULL, 
            0xAC4F3EF8EBF3E389ULL, 0x9010B75A8E67EF21ULL, 0x1959D2EDC0F38F38ULL, 0x85F15DD9934C24A4ULL, 
            0x373745702077C5CFULL, 0xAD72B3903E3F3C59ULL, 0x3D77BFBD1E8A6472ULL, 0x9B6F4D20BB8383C3ULL, 
            0xEBA588EF9C53A184ULL, 0x5076284BA0B89A02ULL, 0x442AC7E28A856CFDULL, 0x268C3AA8F677C4FDULL, 
            0xA8BE427F46DA44BBULL, 0x28516552FAB1A6E5ULL, 0x5E51D4DB4FD1D5C8ULL, 0xAFE3F3CE1FD40727ULL, 
            0x856C1F687F975CDBULL, 0xABDE1B2F7001AA64ULL, 0x4394B658A36EFD97ULL, 0xA843ADBB85B6C84BULL, 
            0x50D0ADD7A5699886ULL, 0x0E37A24EF03527EBULL, 0x4115D528510FE050ULL, 0x17FDE11BB60DFAFDULL, 
            0x917A980BAFFD8805ULL, 0x60B7406EBC630C12ULL, 0x6E88F1F890709DB0ULL, 0x80CF24666466D909ULL
        },
        {
            0xD6B4EC72C5B51086ULL, 0xFA3F2924FE5937F7ULL, 0x7504838439D7D138ULL, 0x1453EF7F3D77DF85ULL, 
            0xCCC1374C617BA5BAULL, 0x91D8E5D1FBCDFD0AULL, 0x2122A167AB0FC2B2ULL, 0x5D36BE4F8D4661A2ULL, 
            0x3A76E2E7B6380F94ULL, 0x2619E7F1A7E2CE4AULL, 0xFF7BFB07BECFE109ULL, 0xBE2410592D9CC1D9ULL, 
            0x57149B32824B2E3DULL, 0x7B605523E033A0AEULL, 0x8676AFAEF99BB72DULL, 0xB709D31CC7A9FDFBULL, 
            0xF60AA7CEF5A5845CULL, 0x3B05447A0CDF9477ULL, 0xFEF7AA02F4CC1DA5ULL, 0x5FAA8046FCDD1692ULL, 
            0x98E20DDA802C7DACULL, 0x466AB273882B564BULL, 0xA3F01A13BE06EA7DULL, 0x614C8954971FE43CULL, 
            0xBD4EB0878BF837F3ULL, 0xE415C62857BF1D29ULL, 0x7BE387CEDF2FE5D9ULL, 0xFD3533C94B6C22DCULL, 
            0x8FDE0A3356E5A5A8ULL, 0xAD76799ED0C15CFFULL, 0x0902BF1E9B3871BAULL, 0xBFD1A147AE339A0BULL
        }
    },
    {
        {
            0xE2016B8F87A8A42FULL, 0x554D8AF5D21C1343ULL, 0x94DC3DCEEAC57E83ULL, 0x1B6CEDE21279BFC1ULL, 
            0x59135DDA1C58B5D2ULL, 0x13BE011645B16EC8ULL, 0xCD98569A4A7AD43BULL, 0xC686255FC2C1B331ULL, 
            0x6E5D8B2FF9F87FA5ULL, 0x4B9F783631127FCCULL, 0x6F558053561428A8ULL, 0x74FFE537A5218A55ULL, 
            0x7FBA21907B6445C1ULL, 0x59FF3DAD9A1D83B2ULL, 0x4F7AF8EB765C4C42ULL, 0x5A3B59785184E516ULL, 
            0x265FD53A62CA84B4ULL, 0xBE577AA771D2EE51ULL, 0xF5A60CC3994B69A1ULL, 0xE2E40B6DBD27F092ULL, 
            0x36203640AD98A658ULL, 0x40A3E15A013DE636ULL, 0x73C9BE0EEE91DCB5ULL, 0xBAE3616863927B8FULL, 
            0x2039BF3556198817ULL, 0xA7C881D5ED9E7F87ULL, 0x17723A370BE32658ULL, 0xA337EB34CFA4DA1AULL, 
            0x18B2FC09D48223BFULL, 0x211DB542C0FD82BBULL, 0xCA665659581FF139ULL, 0xD76DF7B4747C3487ULL
        },
        {
            0x48CFEC95062B139AULL, 0xB5F265B07A17D626ULL, 0x98A5C5BEDDD6EA68ULL, 0x80F922EBF2930320ULL, 
            0x42C69D9129355AD2ULL, 0x653183C73E269578ULL, 0x997802C15A764078ULL, 0xE1938E5AB6EF6F91ULL, 
            0x672B692A503CB01DULL, 0x21BAA9FF6C55AEDEULL, 0x543B83EDB0CDF526ULL, 0x36B08E69306C8F71ULL, 
            0xECD045F25248B1A9ULL, 0xDC9708DBB3C6B412ULL, 0x7F61B384F13F45CBULL, 0x61D61925CD1FE0C1ULL, 
            0xE27D04C426FFC79EULL, 0x8AC878E7AA8A539AULL, 0xBEC1640ABBBB7E7FULL, 0x5DADAAF0E6EEDEFAULL, 
            0xE5F61EC9C543B2D7ULL, 0xF45E9C67C15FDC4DULL, 0x39D660DE494B3437ULL, 0xC407EBDA60C4FCD8ULL, 
            0x8B33E8DC862D467EULL, 0x9CBC1D9F2E036A1AULL, 0xBF675A21F103C41FULL, 0xABA72438FF02DEA3ULL, 
            0xFECD92E899628725ULL, 0x64E617C055E09183ULL, 0xD90E00661C151710ULL, 0xA4CE971479939ABFULL
        },
        {
            0xD61B9ED64DA0F56EULL, 0x45FE2AD2907AE4EDULL, 0x1C748192DAA159FEULL, 0x75C2A0F5A4D423C4ULL, 
            0x4860B68FAF17AA9AULL, 0x9FCA67488471D77BULL, 0xF4BCCB3A12D5DAF0ULL, 0xCF545E99C8CFA1F8ULL, 
            0x513F19557B5782C5ULL, 0xAFFE82B444E8205EULL, 0xD4F14D3709A3EFA5ULL, 0x8BCA963C48AA330AULL, 
            0x4AFA2BC7F9024BBFULL, 0xFF365C4348BB8044ULL, 0x9A55160DA724C8D7ULL, 0x7404364282EDE159ULL, 
            0x25A6D6DAE501A2A2ULL, 0x326FFAF54872AA6EULL, 0x708C9DD01E9F1740ULL, 0xBD27867C0FFB27C2ULL, 
            0x783A5C565687C6B5ULL, 0xC85753E409D8362CULL, 0xAAA2FEEB74762ED4ULL, 0xF33EA553FC07C76CULL, 
            0x737B2004C93D2F98ULL, 0xE9753CA45E8D8DB3ULL, 0x5634EFCC07C310DEULL, 0x8AFF666F3E58BBB3ULL, 
            0x9C35484761AFC059ULL, 0x379395C0E7381ABDULL, 0xBFB9F4DD05AB4FD6ULL, 0x900DC03376FDCF1EULL
        },
        {
            0xCB9D364035F11B63ULL, 0xC78F23F4620B0183ULL, 0xF5C7636B4621C5DCULL, 0x949BCB6CD50FBEA9ULL, 
            0xB091F1C4E92CE889ULL, 0x7A86A11B341AFF77ULL, 0xBFB6A8C6B9E1D9B4ULL, 0xECD0CBA16B71FCB8ULL, 
            0xAB4954816BA547E5ULL, 0x41CF68B7A47DB8EDULL, 0x0EEB03D8D0F98D19ULL, 0x4E238B7720598963ULL, 
            0x29F54F2BB7140D6BULL, 0xFDFA5B7C5A30C1AAULL, 0xC7C88A8A382073D8ULL, 0x0F4ADE55C6FC3A53ULL, 
            0x8547C08129FF32A7ULL, 0x2E9FDC47B7B21DCFULL, 0xFC404DD799077095ULL, 0x5C969919C99FB1F9ULL, 
            0xAFC71F3A3E2069FAULL, 0xB9778285113ED10FULL, 0xAE56E9543531E628ULL, 0x1B7C785ABA837AC5ULL, 
            0xDC0B4093AFA96D4FULL, 0x156FCFE18EE5D9E9ULL, 0xCB6AFEDD99CE9C82ULL, 0xB455210BEF69F41EULL, 
            0x687EFC18A371A4A7ULL, 0x3CBD169DB5A92FD3ULL, 0x89C8E61DB067ED8DULL, 0xA0A09D873A7EB7D2ULL
        },
        {
            0xAFA755AFBCE573CEULL, 0xB2379A88BCC14B9FULL, 0x58F47A59BD8CC2E4ULL, 0x09403AF4285D06E9ULL, 
            0xF223F8930531A121ULL, 0xBE650FAF7200134DULL, 0x4AD9726557BCCABFULL, 0xFFC4BA67A06C29C0ULL, 
            0xF02D50646691EE2FULL, 0xEF8B6BDAC1A6FA51ULL, 0x67BFBA5263B6A984ULL, 0x824234065EC33405ULL, 
            0x9A39B7D7AA3697FBULL, 0x87112AF35F95F6BDULL, 0xBAAC9A0610668FF5ULL, 0x4FB827B83E02515FULL, 
            0x1B2D894EC3439188ULL, 0xEA01DF3ACAAC2DEDULL, 0x0A8F4991CDF7CFE3ULL, 0xE44BA3A54CE4E017ULL, 
            0x6CF6764CCAC7CE4DULL, 0x3497C0C940096377ULL, 0xF1671FD8B21DA403ULL, 0xE6D57C1D8D320ECEULL, 
            0xB750314B57822BF5ULL, 0xD1B20D341D1EAF70ULL, 0x278D344497A90B91ULL, 0x417684E9B3AD7832ULL, 
            0xFD8D48B545DD2A7AULL, 0x94500181C20DF5F6ULL, 0x8D2448D0982A6C9CULL, 0xB6E47506C5E9FD0DULL
        },
        {
            0x0F25BF82D2AA8302ULL, 0x1713A4EC9BF9C7FEULL, 0xB544E0A652123EAFULL, 0x40332C9CE4458E28ULL, 
            0xE430C350F1C97CD9ULL, 0x841B88EBF9DC23DFULL, 0x7A03C7A5B91350ABULL, 0xBA3813BD838D0A41ULL, 
            0xD9E7E4F442D8B079ULL, 0xA6EDD26411717242ULL, 0x8ADC22527DD0648DULL, 0x4F4B5104B8CE36DEULL, 
            0x62BC247B9D472826ULL, 0x0F98704E2A9D5732ULL, 0x3BEB817D72802A1BULL, 0x57FCD96AFFB9B26DULL, 
            0x9EF396A03C02D955ULL, 0xFDD3E2565D09034EULL, 0x5ADCF3BFAFDE057CULL, 0x9ECBE10FA20F7E30ULL, 
            0xBEF8619A1227768EULL, 0x024454243B4B1DD7ULL, 0x5EEC5BF1FF3E9F9CULL, 0xF4F64DD89271B917ULL, 
            0xA09EF36662BEB906ULL, 0xF2556077A9A4D260ULL, 0x0B85A27A7A8B55D4ULL, 0x92FB9ABD7B027DD8ULL, 
            0xD2E82098AA96AC33ULL, 0x227A997B7FDE0AA8ULL, 0x857DE484E90C40E6ULL, 0x846CFB3D64B5E59DULL
        }
    },
    {
        {
            0xA74B920934C74E03ULL, 0x633BE42AEEF43B1DULL, 0xD1F6B216F26CAAC7ULL, 0xECA3F86D88C8E252ULL, 
            0x91A21F911960F790ULL, 0xDF83EEC59D865CB9ULL, 0xB0CADF62697630A1ULL, 0x33B4A743C0616215ULL, 
            0xD3276C25DB5218FEULL, 0x632592D55CC03489ULL, 0xD6F0B366BCABEB58ULL, 0x07D96751E38C3DF3ULL, 
            0x79EACE3267B46555ULL, 0x297C6AC20EE96379ULL, 0xEE9E3B040C40C748ULL, 0x25B613F1309CB56AULL, 
            0xD16273C28B4929A7ULL, 0xB1126FF5E51022E8ULL, 0xF510B54E49250E5CULL, 0x1B50A800098CB885ULL, 
            0x1D0B980F7C38D6D0ULL, 0x19D4F12E93CB7316ULL, 0xD3F24C4501E4B7B9ULL, 0x5401B6475D8DF0E7ULL, 
            0x8B3DE241181A5B2EULL, 0x1431B1A36DB74B5CULL, 0xD6C48040E82DE16AULL, 0x54F7490A47D7DA2EULL, 
            0x1BE6B406385C810BULL, 0x9825D8CCE68B618EULL, 0xCB4A53C0F00ED736ULL, 0x28B931AA6E0B0D73ULL
        },
        {
            0x652C5AFFDAB30AF7ULL, 0x4D46FAAEEB6B557FULL, 0x32965932E9A73D2BULL, 0x31A45536373EEC70ULL, 
            0xFE47A8C54DCF179CULL, 0xD8414841ACC1A49FULL, 0x39E80CF069DC0A92ULL, 0x1BC18B6B68767D13ULL, 
            0xAAFC433FD81AF838ULL, 0x3EA803AEAD990BC8ULL, 0x3F6E55C73F484F82ULL, 0x1101300FD59DF44CULL, 
            0x6E945ED9DA3593E2ULL, 0x02A181458F4D251CULL, 0xB38D05404CF94955ULL, 0xAF8216615F70FB8BULL, 
            0x82A69EF837CA3280ULL, 0xF7996E50389B0AFAULL, 0xB6F2F89F5E1193FEULL, 0xBEBDC98211D0E7BBULL, 
            0xBF3834F7E4BD95E0ULL, 0x8581468713B5BB55ULL, 0xC687B08E7F1FE868ULL, 0xC04629E4FF26F898ULL, 
            0xA0BCF9EFC7019AE7ULL, 0x19210108747CB321ULL, 0x439ACAB91366C656ULL, 0x1AB0A0BC4B44113FULL, 
            0xF327F908EDD8756BULL, 0xE91F51BC8CC2FEE5ULL, 0xDD7AA1787BD4F967ULL, 0xF10AD1C4EB285116ULL
        },
        {
            0x79F33E4ADEF1FCB4ULL, 0x6890049A10B146BBULL, 0xB1994EBE44CFAEFCULL, 0xA60363CF4D20C016ULL, 
            0xE3208571554E2ED3ULL, 0x293C6E63A6133E87ULL, 0xCD33C8AFD9EA9D94ULL, 0x9724ED64FE81B175ULL, 
            0x9809673D07200C46ULL, 0x62928DA324C36908ULL, 0x52E6B4FFA021771DULL, 0x20F011C506AC2B99ULL, 
            0xA9A31D861854B794ULL, 0x23F67CEB7F0CDFA6ULL, 0xFD0FB0B67F669162ULL, 0xF01EE8D51BC30EC2ULL, 
            0x826FF3CB2D305224ULL, 0xF2F2DFF52576E64CULL, 0x5FADED3C26878485ULL, 0xC075518A46A28760ULL, 
            0xAD166D59B97E5105ULL, 0x21D9CABCA73EE667ULL, 0xD0EBE28C5BE2D126ULL, 0x02F7CC990310886CULL, 
            0x2B6528CC35834E92ULL, 0xDCA013CD65F71A4EULL, 0xDE4E2FD4958D7E12ULL, 0xA539F457CBF6D0CDULL, 
            0x54761DF1F7E537E9ULL, 0x510FB85AC894B3F8ULL, 0x803E279E5C111610ULL, 0x43C9801E635B9D88ULL
        },
        {
            0x6FB4940E5E5230A1ULL, 0xEF97CC9BF32711E6ULL, 0x6E88BB33A5B6B696ULL, 0xE65E6CA184DAA9ABULL, 
            0xECA2E0C9A70EE869ULL, 0x1278C9C339783F50ULL, 0xD7C7161748894767ULL, 0xCE1B816169629562ULL, 
            0x9DA84955A796BD3AULL, 0x9C2314AE4466A6FFULL, 0x80263BA2C43B1647ULL, 0xE81F40D1F40DC4CDULL, 
            0x511F3B8FCCEB52FDULL, 0x6BC520953D4D3DD6ULL, 0x974FF8866EED873BULL, 0x4C8EC5711448A0F2ULL, 
            0x60E2F5211B44E6CDULL, 0xC9DA736545E1BFA9ULL, 0x3E9378077FA84A83ULL, 0x4D81D1857D5BD506ULL, 
            0xC4AC915C035DE090ULL, 0x651E0C1451BD9F08ULL, 0x7BBBF5D510798EB4ULL, 0x446F1439A7973F20ULL, 
            0xB4EF82F12ADABA84ULL, 0x1963919063F1092AULL, 0x6BA9F5F2313A3F0DULL, 0x0BAF4BD6C287284CULL, 
            0x01BE4E7A185BB6C9ULL, 0x856D73173BBF30BBULL, 0xD8A63066F098D65FULL, 0x921633FDC6948F70ULL
        },
        {
            0x3D3A6EE854AF9570ULL, 0xD6401E435D5973BAULL, 0xD390B0163A1B002EULL, 0x71D0456A7CB0E430ULL, 
            0xC5EBE66597ECA5F5ULL, 0xF1C7DD1483680328ULL, 0x5C3410D7BFA7C00AULL, 0xE6D89FC04432D983ULL, 
            0x3CDCA2436AEC8F90ULL, 0x37B119D1C3E23E50ULL, 0x506B89ABCF8A2D42ULL, 0x93C6B86769146ED9ULL, 
            0x98C8FCE2E131E479ULL, 0x3794C555A769539AULL, 0xB442D4B7BEB2316BULL, 0x52D33BA5034CAF8AULL, 
            0x22A635D57BEB4F2DULL, 0x73C7B86D4C3EDBE0ULL, 0xB3705497DB09920FULL, 0xA3BB9063D6609582ULL, 
            0xC384B5FF26A1F1A5ULL, 0xA3E62FE39D970BD2ULL, 0x0C2AA43086B14CDBULL, 0xFE56C18ED5A45631ULL, 
            0x661EF8A041E90C96ULL, 0xEACA3C44FAF09FCFULL, 0xB3379921A7808E31ULL, 0x0FA3187BBCEB5E7EULL, 
            0x97F4476C1F2DA788ULL, 0xF9AAF8AA44B775B8ULL, 0x5D6C8A8AC4BC1FF4ULL, 0x29F556B842960FE1ULL
        },
        {
            0x368D5DECFA86E7B8ULL, 0xFC32FDA8E6164175ULL, 0x11CD5FB74CD680DEULL, 0x7CE3599C346D3B9CULL, 
            0x8FD56CF934C36A08ULL, 0x77982129A40BDFFFULL, 0xB4D502E7D158C2E9ULL, 0xAA0FB44ABEBF5071ULL, 
            0xB875D55A710FECFFULL, 0xF5DF73FC33575FA6ULL, 0x9BC5979ADD325829ULL, 0x96FC628BBDC40735ULL, 
            0x6E81770AAE9C7887ULL, 0x8B61AC284CAD93A3ULL, 0xDADE7C98ABFAD90FULL, 0xB8F4050D2CDFAAE5ULL, 
            0x119D351CB40A86A2ULL, 0x0C484D21F11C17DFULL, 0x016A9E8B09BFC1B9ULL, 0xB47C6B8791B19DC7ULL, 
            0xE45B030A2CF920E2ULL, 0x9C28FFFE0BE9B759ULL, 0x588E50E9F92DF8BAULL, 0x8049C3E567B1460DULL, 
            0x8D77B40372D243CDULL, 0xC4F615BBD694D698ULL, 0xF0BFA0E696768C2DULL, 0xDC855E7A7CD32B04ULL, 
            0xAE8F5CC5475D8BF1ULL, 0x66A70D0795B71706ULL, 0x03CCCC2D9F8AA616ULL, 0xCAC7770A45C892C9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeySpawnAConstants = {
    0x5A7BB5D644FA9994ULL,
    0xEE5C0C6FB744CC5BULL,
    0x7408CA3A4D45EED1ULL,
    0x5A7BB5D644FA9994ULL,
    0xEE5C0C6FB744CC5BULL,
    0x7408CA3A4D45EED1ULL,
    0x73CA104D52A21C01ULL,
    0x9D58A077363714E7ULL,
    0x01,
    0x02,
    0xEB,
    0x56,
    0x3D,
    0xC3,
    0x8D,
    0x5A
};

const TwistDomainSaltSet TwistExpander_Procyon::kKeySpawnBSalts = {
    {
        {
            0x967DAF9DD85C3907ULL, 0xCE45876F717D8996ULL, 0xC679B00ED7131AFCULL, 0x9CEC250F93B492A5ULL, 
            0x3F8A0FCAFCD97C0CULL, 0x1990FACF1E879E86ULL, 0xEC05E92FC32F3F23ULL, 0x2E7D57BB1589D542ULL, 
            0xE655FB8D47C6C285ULL, 0xE3607A3D034C3EC5ULL, 0xD9E219621082CC1EULL, 0xDCB4069954A3A523ULL, 
            0x6F30695669AF44CBULL, 0x154948B295F6A099ULL, 0x5E00CEB06CC2FA32ULL, 0xDB4290E8C9F21922ULL, 
            0xAC6A3E4DC46AA1E1ULL, 0x394049BDE9D80E0EULL, 0x7555437CD9A1B8EAULL, 0x5DECD5D47FB1083CULL, 
            0x076BFAF3DDEA56F0ULL, 0x07E90B44746ED2CDULL, 0xBCA989609D6B42AAULL, 0x414530692BA61F3CULL, 
            0xE8BA174504758681ULL, 0xAB1EB766A7B8E4C5ULL, 0xF06A99BABB1FA4A7ULL, 0xE4DC5F3B112B176FULL, 
            0x80696ACC71D357FEULL, 0x30A5012790D1A693ULL, 0x2FC3AA927FCA6581ULL, 0x4BB06ECCFF1D00E6ULL
        },
        {
            0xC807451642F84704ULL, 0x95DB59F0ECFBB38FULL, 0xE87CFEE1DA6F3CC4ULL, 0xC8A5EB2CC7979285ULL, 
            0x8DD7F5EB6125C7B0ULL, 0xC6A4BB3717C7FA58ULL, 0xA2DEBA8E417E5C3DULL, 0x725D0448C1E94A22ULL, 
            0xA8898605AC5E5572ULL, 0x3224B10BAFA83713ULL, 0x3B29BCB8052DF1E6ULL, 0xC8DC943C964050DDULL, 
            0x1E0325BB97C0A9CFULL, 0x1186254A7EC2BAA9ULL, 0x7C37C7511BA2A648ULL, 0x060319BF427CC433ULL, 
            0xBEBD9B029D31714FULL, 0xBFA376FCBA39C530ULL, 0x88017B59C4DCED1FULL, 0x93C395C428D2A62CULL, 
            0xD6BFB0CADDB11F59ULL, 0xCB5AF2F87DB0077CULL, 0xE967E4A785B84184ULL, 0x49EB21FA0BBA38D7ULL, 
            0xE28ABA218CC0E587ULL, 0xB5EA85283DE5D8B8ULL, 0xB995160450EE6531ULL, 0xC4735A9A43A87942ULL, 
            0x42C5C86F031D5D86ULL, 0xEACD395F0C20D916ULL, 0xA0E665F666B0A8D6ULL, 0xE679F3C37703E82BULL
        },
        {
            0x9E240E348210A0FEULL, 0xF3CEAEA3D81C0ED5ULL, 0x107FD59E86392CB2ULL, 0x12C32D6BC5F0BE3DULL, 
            0x5370AFA39690F948ULL, 0x19A266B621D109C4ULL, 0x72B8B9E074FE1F0FULL, 0x24DCD8079BD0B9B8ULL, 
            0x6170FC7CCC685EE1ULL, 0x95F162F43468C9BBULL, 0xF9228DB5B2049300ULL, 0x137DA170A16CA765ULL, 
            0x6838A67ABCDA3702ULL, 0xBF0938BEB5860B76ULL, 0x07E51B485F61D7C0ULL, 0xE233365CE269E192ULL, 
            0x1C423984D6FD136FULL, 0x98E042855D7D7DFCULL, 0x08FDC4395E1AF198ULL, 0x97772222E4601453ULL, 
            0xAAA2AE612D4DEB74ULL, 0xBDEB7192D434C78FULL, 0x443A0F82B18A1330ULL, 0x46EC43F55A8BA826ULL, 
            0x73DF310A6B4F37D3ULL, 0x94995E67B0104BC8ULL, 0x5D7418D0E86320EAULL, 0x5E2216AF23E9E363ULL, 
            0xC8044A24AB62FF81ULL, 0xC9FF8DCF19BF3C6EULL, 0xE8043979BBA70CC6ULL, 0x9ABD561F0B2D4BECULL
        },
        {
            0x82F2EB5BCFA18C64ULL, 0x2B3A62F0CCEE5744ULL, 0x66E9EEE1E37CA6FDULL, 0x880CCA2B33EBFB68ULL, 
            0x201925E915D51FECULL, 0x3B0A06AD5A65F893ULL, 0x19EF34375C8FD17CULL, 0x6C4601561DF0C127ULL, 
            0xF36223EDD0814388ULL, 0x07912CCCD7D6734AULL, 0x3E8CD43949135D6DULL, 0x0E2B857AFBEA82EAULL, 
            0xD0B6CA5EB204D520ULL, 0xDB6C7F087327B5A2ULL, 0xF68966292B132FD6ULL, 0x114F0BE1D2D869ABULL, 
            0xAB0436C1725A76ACULL, 0xA89C16A5247E3571ULL, 0x4B91E6AF4ED86C0EULL, 0x7165EBDEACE41998ULL, 
            0x05D08C4E46D01747ULL, 0x587025A7502FBAF0ULL, 0xF5F73A4F1B4A2359ULL, 0x37A3E939027DC86EULL, 
            0x24B6FE39A1604B4AULL, 0x8FDB51D7A9C580DAULL, 0x3DA01A521AF65E05ULL, 0x2793B63C3CB5F7A1ULL, 
            0xFDBFBBDBC8FFBFE7ULL, 0x26CAA51E758C9465ULL, 0x16C8D7480E820442ULL, 0x4673AA54B857C4B9ULL
        },
        {
            0x73B676F13B1E3C97ULL, 0xC7BCD59E1BEFB107ULL, 0x6935543F60AA4D0FULL, 0x06368556A3FDD539ULL, 
            0xC8215A2D375809CEULL, 0x50520F952C8014B9ULL, 0xC4B0C16A04F1319DULL, 0x713E98A03B86B9BAULL, 
            0x3BF9CF112EB3CD96ULL, 0xD54A65DFD0E16BC8ULL, 0xAD5EC233C7CADCFFULL, 0x87203124F3B9D340ULL, 
            0x4978D3E7B5752CFBULL, 0xBCF26B578A828AEFULL, 0x19FE52C1F1412806ULL, 0x032D0E600E23CF22ULL, 
            0xDD59D34FB82B5E6FULL, 0xDE25746F088265BDULL, 0x9A54B963BD456B8BULL, 0x51A114F3ABF35E42ULL, 
            0xE2590E32BAD40068ULL, 0x3077A0B41AFE09A4ULL, 0x58D7FB9D599AB42AULL, 0xC43489473AE930D1ULL, 
            0x6571F8A4C2CEC512ULL, 0x100B09E7338CA556ULL, 0xD9F9AF6529F07ED0ULL, 0xC622F9D52E3F96DEULL, 
            0x07F0A601806A761FULL, 0x852745267874026DULL, 0x86640F4185FE4A71ULL, 0x299EE8BE3171AB7BULL
        },
        {
            0x25B6B935FF4CB196ULL, 0x3ADC155AD953DDF6ULL, 0xB54F5FCC6F9FE802ULL, 0xA3F81F5F0DCB7ADDULL, 
            0x875B1340641096CCULL, 0xD9BC493D2CF6AFEDULL, 0xEFF04C301497EDF2ULL, 0x0DA139705589B24EULL, 
            0x66BE5063BE5132A0ULL, 0x0FA0E6712FC516C5ULL, 0x536168D977D39AD7ULL, 0x46923A1FD7AD7B46ULL, 
            0x040514E1A9956700ULL, 0xBB6BF293BDE63EEDULL, 0xF15A7F9881C7DEE1ULL, 0xB2B287C7E08A5DDFULL, 
            0x69205F06E3039B3FULL, 0x79258C77848D447EULL, 0x74A73D9BBDE0C90CULL, 0x1CC9A4AE5CD74631ULL, 
            0x7470D5BB445FFED8ULL, 0x694C85EE2332FA28ULL, 0x610926790B7E17AEULL, 0xD3B44DACDE049A2DULL, 
            0x2E752066BCD8BB02ULL, 0x3FB8A9A26ACEC737ULL, 0xA1D4ABA8C2EB2A1DULL, 0x79C2A37B74EF9245ULL, 
            0x8A82D2CC9378E1D1ULL, 0x9C3E53C4E841499BULL, 0x05263BDBC49D550DULL, 0xCB0BDA50513F348FULL
        }
    },
    {
        {
            0xE509DE5D05A18CE9ULL, 0xE021B5D7912BB29EULL, 0x21339FB4BD47E260ULL, 0x62F4EC3C2BC2C900ULL, 
            0xD84CB3B6593588B8ULL, 0xA9533DB28A62CCFFULL, 0xF2702A03D6CF7034ULL, 0x50A9AE6F31CEF3E7ULL, 
            0xCF99F07ADE098A8AULL, 0x273908FA18C38773ULL, 0x536DA9562C723728ULL, 0xC22A6E84A289646CULL, 
            0x4F7CEF86DF4DEF73ULL, 0x96D5839156F04D03ULL, 0xC0C230184421D18BULL, 0x3E6B36A43DFB8DF9ULL, 
            0x46FC60A3FEA39CA4ULL, 0xF765886D15BDAED3ULL, 0xF21D21DC0AB22AD3ULL, 0x37C0C6FDB46C9032ULL, 
            0xDBB1C4C993C4C2F7ULL, 0xE78575499594E1C5ULL, 0x80B3535ABF61CB17ULL, 0x0C63BCA538763F01ULL, 
            0xCA0FD6E985138AABULL, 0xB30FF69ADAB36194ULL, 0x30152FF7942048BCULL, 0xD16D9EFCF2E50EA9ULL, 
            0x773F81F67A6FBE6EULL, 0x0B6329E400C22F30ULL, 0x3915397972DBC519ULL, 0x9F0788A9695A1DC9ULL
        },
        {
            0x520BA58C711B81AFULL, 0x22801285B74FD42DULL, 0x6926BA22E51CB547ULL, 0xBABA037A9AC766E9ULL, 
            0x423AC534E2BD563BULL, 0x03E52AED1B1AE314ULL, 0x2F29E588F292F51FULL, 0x8148600BC4126EA7ULL, 
            0xCEE503382F7105BEULL, 0x2BE2227F310460D1ULL, 0xD8742EF459B9C953ULL, 0x699556A02077B7D8ULL, 
            0x5BF3BD0316244656ULL, 0xF3894F2AA2824A93ULL, 0x11F20931FD0A93F6ULL, 0xE5D2FF791483F0DBULL, 
            0xA9A756F48427DA46ULL, 0xAE0EE7597791DD72ULL, 0x05F0C1DF29A0D3ABULL, 0x62DE14224B1579FBULL, 
            0xBBE9AFE6CF971ADBULL, 0x353979F3FCF12946ULL, 0xD2B3D96B5E049F3CULL, 0x02FC57D42291A690ULL, 
            0xBA25A90182CE4033ULL, 0x136BA3E98B75878EULL, 0x9C3152EF2CBF68EDULL, 0xAF621C9AD998A46FULL, 
            0x8AF3259FB6356D07ULL, 0x3172C8208FBD4918ULL, 0x123259B9B59A5A44ULL, 0xAAA44991BADB2171ULL
        },
        {
            0xCFE4F1FA67161C33ULL, 0xCCF589A480FC7162ULL, 0x5ACF80EF6897CC31ULL, 0x2D83EBA98E6777DEULL, 
            0x281FCC779519137FULL, 0x1EE01DE516AADE5DULL, 0xC396FD41AB105B2CULL, 0x94F5B29F399D1F4AULL, 
            0xEF7E0D0DEBC6D06EULL, 0xF34A1E1FC385D976ULL, 0xA047579B734CFA8AULL, 0x2FAAD0022D1515E3ULL, 
            0x7AEE3EC125A418F2ULL, 0x18DC425132E8AD52ULL, 0x99769116664DD63CULL, 0x885089CFAA264E2CULL, 
            0x1A5D03D7A60AC2F6ULL, 0xFD561B69C3D38CEDULL, 0xA9192AC51CAB58EDULL, 0x157D0BEF6E2307F2ULL, 
            0x364A2AC1D9F54CC3ULL, 0xB92B8E603DA76AE6ULL, 0xB530329C6E77AE3AULL, 0x9193D2F6BC6636FBULL, 
            0xEA6DA93484AFBE12ULL, 0xFE00D7121FBA3AFFULL, 0xBEED4AFC25091D87ULL, 0x764EE5A378C78A0BULL, 
            0x5DFEC2A1E66BA579ULL, 0x98D898DC567966C7ULL, 0x65B77C178866DF45ULL, 0x9BF14AB85F3EFC1BULL
        },
        {
            0x848948CDA529C903ULL, 0xE77E2CB149A8D225ULL, 0x0B88845F97B19FCEULL, 0x099F28783CAE4650ULL, 
            0x259A74AA4E5EBA7FULL, 0xC972324E62CA4EB0ULL, 0xD53BE2A302375807ULL, 0xF3F2965415920ED9ULL, 
            0xCD708FB4BD4D5A82ULL, 0x239DB584CF62CF9BULL, 0x1C88239E86B7E430ULL, 0x74CEB1540F06A08DULL, 
            0xF4D690F4DB12F163ULL, 0xCA76D4B66D1CEEA1ULL, 0xFA22C7E3400FD716ULL, 0x354A91A19997CB88ULL, 
            0xFEA5DA8437BA0419ULL, 0x707B9ACA2C231866ULL, 0xAA276D91FEE13F7DULL, 0xD1B840D96B9F02B4ULL, 
            0x930B52F1C550BD9CULL, 0x214B17242E905522ULL, 0x1D06235AF6788E4EULL, 0x0B5102C944D74D02ULL, 
            0x138BA3BCD58AFB2FULL, 0xF68E3DE074DDE28FULL, 0xF3CD03024FEC5052ULL, 0xE85F668CBF885241ULL, 
            0xADD78F38FD4EF9BAULL, 0x99C5ACD0A70173D9ULL, 0x65603EDCA3F43BC5ULL, 0x7A86A4FCF3458573ULL
        },
        {
            0x75A319F2F1B22368ULL, 0x449E82C4B37F0480ULL, 0xA7E6BA4BB2D67975ULL, 0xE3D1B1CFB9B7F9AAULL, 
            0xA75DFAA957A17A78ULL, 0x9179C75402806151ULL, 0xD429268D7B1A95A2ULL, 0x60C3918B5E4042D7ULL, 
            0xF9538CF12D548DFCULL, 0x63FB79E48FB5DC03ULL, 0xB3A2CE35068B261FULL, 0x2CD92EC3F4FDE9A5ULL, 
            0xA85096E497FDC27AULL, 0x15CB6D698B8C7F7DULL, 0x0055B6A03080676DULL, 0x074CAB6C61EAED9DULL, 
            0x57818CD15178A2ECULL, 0xFAEF1BA356C9E8B6ULL, 0x937AE0FFC951F068ULL, 0xAFEC3A1F2174ABC8ULL, 
            0xF024E697F8CE3D50ULL, 0xA742B368B23EDA06ULL, 0x3896A7D8B543BF39ULL, 0xE38DD57739F6F78DULL, 
            0xCF1A9445B51592EAULL, 0x65AE7EED7B5ABBECULL, 0xCE63DBEE2F3D286EULL, 0xCFA84AF171D004E5ULL, 
            0xAE9ABC57B0880179ULL, 0xDB76E17972184A76ULL, 0xB1D8FBC78E047E01ULL, 0xF845576A462C5F8EULL
        },
        {
            0x729E9317D3454D32ULL, 0x8B7FAE908F9E24B8ULL, 0x1C2640B7D0907481ULL, 0xC61F1B4F47DF54D1ULL, 
            0x4C826A8DE3DE9B5FULL, 0xB97DF45BB445BF87ULL, 0x7D202833397623BCULL, 0xCC75FFABB7C6CF49ULL, 
            0xF17212E4F3A58ADEULL, 0xC96DE7D2CF3D0522ULL, 0xBB641F6533994007ULL, 0x17378916F9EE8A75ULL, 
            0xC0E841558A611081ULL, 0x6320378ED5EC538DULL, 0xA943E8DF8785BC6CULL, 0x10918E1AE763261BULL, 
            0x18409429FE42B1D0ULL, 0x2BAFAB35121A798DULL, 0x491A6932E5505BB1ULL, 0xD7F776DB7E4E5EB5ULL, 
            0xB5BC40F2A7A636E0ULL, 0x8546EF2AE1FF962CULL, 0x2ED1913F242492B2ULL, 0x2C3ABC74AC35E472ULL, 
            0x78E512A403A44FF7ULL, 0xEDD3F83129D8A594ULL, 0x878F4F56B56C90A6ULL, 0x9C02F3463C6E6D35ULL, 
            0xAAAFCE766AC5B755ULL, 0x67B91CE005293D9AULL, 0x67DC9C93B53F6FB5ULL, 0xC0F4C553FE863099ULL
        }
    },
    {
        {
            0xCECBE61F220FE2B2ULL, 0xE9D3EF79DF67006EULL, 0xB8605CCB2793401FULL, 0x14190EAC348C1571ULL, 
            0xE291D138CDCC30A5ULL, 0xCD080EF223A2A47BULL, 0xC95ACB62C417627FULL, 0x376C1BBB01F85A3CULL, 
            0x0C2D34B2E94A7B91ULL, 0x137600DB1D37DD17ULL, 0x93560DA0C624E150ULL, 0x39BF7D540EDE8B10ULL, 
            0x7AACB4486A8846ACULL, 0x1BD319D198E93B9EULL, 0x45AF91128719C21CULL, 0xC84ED353A5DCCE20ULL, 
            0x0133CB9B4E0BD0AAULL, 0xEE54B2CA1E314E82ULL, 0x4967999E731C57D6ULL, 0x503B3F9A66CD785DULL, 
            0xB8C1CED9D7320B10ULL, 0x0C654A56933A8458ULL, 0x893D5F46F03EB9D2ULL, 0xA3463197CB0368F7ULL, 
            0x5998B22BE7F04000ULL, 0xB184CAF3D97089D6ULL, 0x1705FE557394F9F8ULL, 0xAD19331EC7CF1F1DULL, 
            0x269F7A8C3E99AFFCULL, 0x0B145B3ED9AA5571ULL, 0x818CB68A59BE185AULL, 0x99E17368DF735D69ULL
        },
        {
            0x435C943F11735960ULL, 0x5FA9C1A802671ED5ULL, 0x53632A659100E49FULL, 0xA1C32A678EF01D25ULL, 
            0x606A86B2D65A0196ULL, 0xF77F0224E2BEBAAFULL, 0x4D28A10D170A6510ULL, 0x05614627DBF83F82ULL, 
            0x4B007EE20752984BULL, 0xD4804CC1735554ECULL, 0x37EFEA8F4158DD58ULL, 0x43C95589BD7357F2ULL, 
            0x196FB0FD067A29ACULL, 0x706ECEEC7BC9F5F6ULL, 0xAA1B2ECF42E9871BULL, 0xB3FBB1C6E353EC93ULL, 
            0x5916DFEF37E77984ULL, 0x633428E8CA6F9C46ULL, 0xADD47E94F89D8192ULL, 0x10F3BBE167DB6DF4ULL, 
            0xD98CC869F09BF391ULL, 0x8059C633A79584F1ULL, 0xC9691D5279E21948ULL, 0x09D0D3CD294628AEULL, 
            0x98ACBDE686551474ULL, 0x2EDD224F5C18136AULL, 0xBB16E34FB9A0A8BAULL, 0x949C12CCF70C2AD2ULL, 
            0xAC80F427A4897CBCULL, 0xD55E3DB29B75C0F4ULL, 0x65C27A92D5F7BAEDULL, 0xE240380C4C618429ULL
        },
        {
            0x89B88CBA58E2154FULL, 0x307EC421DD2238C9ULL, 0x5F99262D10618D9AULL, 0x9FB035212F8224EDULL, 
            0x6E8F716E9C4F460CULL, 0xC63E150DEED5C81CULL, 0xC96DE77659FE4245ULL, 0xBF81C853B111DF20ULL, 
            0x935EF338A501F0BCULL, 0xDA7A45EA6DFF58E9ULL, 0x862F80EF5239255BULL, 0x7158A83C16A3C639ULL, 
            0x5DAB82C97D3BECD3ULL, 0x91E7524BC2350E7FULL, 0x3B46613F0729CE7BULL, 0x67A426853B5C88ECULL, 
            0x5F6E5845904D8EF3ULL, 0x1E6F5FD3BF7A05E8ULL, 0x14DDE4FE7F7CE11CULL, 0xE7EBBADF9EE1FFE7ULL, 
            0x6AA55490E85B6D80ULL, 0x59A1D576851413E5ULL, 0x340E55DD4FB1C8DDULL, 0xCE159A4C1083DAFAULL, 
            0xFF6398E48DA7E2C3ULL, 0x0CD69D00EDE737B4ULL, 0xC1B30BA9A50E6B43ULL, 0x3C1C62181657F037ULL, 
            0xE0E7485D40E15ED6ULL, 0x76737519206F50F6ULL, 0x8BADA572AD3D24B8ULL, 0x163F75EF0B485B01ULL
        },
        {
            0xAD1200D048B385AEULL, 0x8D399A50B419EB5BULL, 0x063BC61CE32B04D3ULL, 0x311ADCD756B11CEDULL, 
            0x7730E40A942E51AFULL, 0xA59A0B48EAB46477ULL, 0xE04CF5A4EC17F93EULL, 0xC91F3AA1EB9E8216ULL, 
            0xDDB7F0BB6B4873F8ULL, 0xD99E1573C2AECD63ULL, 0xD6E5A76B9C9B90FDULL, 0xD6F2BC9BE38C56E3ULL, 
            0xDD4E79539D60D49CULL, 0x326CA53134282016ULL, 0x531061EFCE63D1B6ULL, 0xD7AB9077854B8458ULL, 
            0xCC4E1BB38C33EAE8ULL, 0x482AD4058D9F3913ULL, 0xFFD080B02623ACB7ULL, 0xC7CD60A034386386ULL, 
            0xE5A0255C0F4EC9E9ULL, 0x7D9146B6672DB48BULL, 0x2D804AC20A3C4E15ULL, 0x785978F3273C5B2EULL, 
            0xF8A58A75AD86A4FDULL, 0xBB2F34A625E7BEE6ULL, 0x4E87B3894642B937ULL, 0x8DC26A77F17499A5ULL, 
            0xCA475E637A9521B6ULL, 0x9612704BA3EDC377ULL, 0x7DFFD3DCBD251DD5ULL, 0xDFF8D743B027311AULL
        },
        {
            0xC72BA59BBF600916ULL, 0x7BE13CC3BB377FEAULL, 0x5FA32EB1768FD4E0ULL, 0xCC9EE559FAC5BDFEULL, 
            0x2E715E42F7A98E86ULL, 0xB1386172C6D4D710ULL, 0x2955C115B54DFDA1ULL, 0xAEDB63B914DCDB43ULL, 
            0x511CC331C1806C37ULL, 0xAF4927218AA392A1ULL, 0xC2A5750F45B14D28ULL, 0x881EC45B85F3147BULL, 
            0x232C380CD8249024ULL, 0xAE2D4DC5B4C7540DULL, 0x6B401036513BC2B4ULL, 0x1AB6C267B3581C78ULL, 
            0xD852D37E5AD0314CULL, 0x2973E17D844DBCB0ULL, 0x791DE5F8FE4C3BFEULL, 0x3596CEB31F16E110ULL, 
            0xCE40B010680F3277ULL, 0x2ECB22BADDABDBE2ULL, 0xC0BCC99F17EA7878ULL, 0x43B1F9728374B415ULL, 
            0xFD3C821D0FA789C4ULL, 0x76618422BA5351E5ULL, 0x995A4F8C81793166ULL, 0x5C0ED3CF1C9833F7ULL, 
            0x531DE6BED1DBC9B1ULL, 0xA4956C350D81DEC5ULL, 0x022FE217712C1FDBULL, 0x6D84A9C0E6E28056ULL
        },
        {
            0xAB18C50DBCE1AAFFULL, 0x6EFFB5121C8AD1A8ULL, 0x46DC3CC9B7E94CCEULL, 0x9F2D00F716E0216FULL, 
            0xF95EB88B4DE69DA4ULL, 0xB36642ADECD71960ULL, 0x4AEE486376E45B51ULL, 0x4B405D3EEC3E50EDULL, 
            0xDFAFDBCB2BDC6682ULL, 0xEEF141882E590F64ULL, 0x61C1ECE255443D73ULL, 0xF1ABDAD77FDECA9CULL, 
            0x67B5E9AC1726907EULL, 0xA72D4C59C10D6810ULL, 0x41A921FCC6C159F5ULL, 0x6073D8157BBAF91EULL, 
            0x5DADC3426A277599ULL, 0xD8BD14F8563799E6ULL, 0xC8606F606CC1A39EULL, 0xBA0F6FA4A52B6291ULL, 
            0x24845373FE08EE59ULL, 0x21A226226AC80703ULL, 0x0F7624B2EE049CF2ULL, 0xA8D5E6A237170F59ULL, 
            0xAA30F2498C884002ULL, 0x6DF96F69D6AFA366ULL, 0xB361D4280BB59896ULL, 0xB5A6B997EDF8FFA1ULL, 
            0x624FD2B60698B07EULL, 0xEE993A19A49602E9ULL, 0x19BF9CEFD098E30DULL, 0xD2430B1A9C6278A8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kKeySpawnBConstants = {
    0xD47F850B83F9DED9ULL,
    0x640EC9AC0399AEC1ULL,
    0x2A70B36D49B208AFULL,
    0xD47F850B83F9DED9ULL,
    0x640EC9AC0399AEC1ULL,
    0x2A70B36D49B208AFULL,
    0x8170AE8936A528E5ULL,
    0x472BA79A46BADEDFULL,
    0x7A,
    0x01,
    0x2F,
    0x2E,
    0xEE,
    0xB0,
    0x94,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Procyon::kSeedSalts = {
    {
        {
            0xE46B35CDD74E86FAULL, 0xBE8B93CEACB1EFCCULL, 0x9267588C9D6BE554ULL, 0x36CD03CA0C10A02FULL, 
            0x002158D184873AB4ULL, 0x04C8AE649CA14027ULL, 0xFA14934CEDD52BF7ULL, 0xC409EBDD74AE884EULL, 
            0x74A7BE1F103BE91AULL, 0xECD9CF53024A131CULL, 0x82A6785163776663ULL, 0x77556220ABC9F8C2ULL, 
            0xBAF1C43FE5C96474ULL, 0x466BCAD8102BA0A6ULL, 0x4CDD92FAD045BBCFULL, 0xD82A1A9CCDDF576DULL, 
            0xFEF8CE79398C4413ULL, 0x0345BA65051CDEC6ULL, 0x86E1252308BADABDULL, 0x04DD6A19FFBD010CULL, 
            0xA41C238204D5E52BULL, 0xBF675CE928A5EA75ULL, 0xA2EAA5D208E4771EULL, 0x168B0F06DACD6458ULL, 
            0x8EF8828744B570CFULL, 0x706606BA9596BAFAULL, 0x96BA673330C9D452ULL, 0x675D7AAFD50C2B80ULL, 
            0x46653A557E84C837ULL, 0xC1547D29B8174475ULL, 0x2E7E4255FF4B4A5EULL, 0x9E1C39A1DEE160D3ULL
        },
        {
            0xA413E9E5D7746B5AULL, 0x1309C0A792C42F90ULL, 0x8CA21CAFD055B6AFULL, 0xE20BC9BB9D3293B2ULL, 
            0xA0F0699C537FAB11ULL, 0xD5FE1930F21F41A5ULL, 0x244521475A9ED986ULL, 0x23951F4930204954ULL, 
            0xCEC68F2F8DA83A85ULL, 0xF7D0DF97E74B4052ULL, 0xCAE31125549BE4F4ULL, 0xA608584A4AE39FACULL, 
            0xA28550B4AAC30627ULL, 0x9D27DA8481B0C639ULL, 0x9C94A021D0F3F3C3ULL, 0x604FD0B811F79E8EULL, 
            0x77B59E164B10D2B1ULL, 0x7E11DEDF8EA58526ULL, 0x54EAE7F7AD086C27ULL, 0xFCE647CB5862D637ULL, 
            0x87A762AE69E4342AULL, 0x758FA8B02BA8D810ULL, 0xD2B84A51F36010F2ULL, 0xEDEF1BA098979BD7ULL, 
            0xBC002837ACC3CA1EULL, 0x8707AD9BCF30AB07ULL, 0xEFE3F353360F3292ULL, 0xF2BB3B3AADB8882CULL, 
            0x720A8058F006A65AULL, 0xEAA59516FEEB9493ULL, 0xB568E5ED66281D9DULL, 0x304CAF371C6963F0ULL
        },
        {
            0x53303267BFC22DA0ULL, 0xD8B56C35197C5E2EULL, 0x09F4CC82314B619FULL, 0x5AF3626FB9243D91ULL, 
            0xF0E4DC437B4C8904ULL, 0x04CF6F4B4F3C8B5CULL, 0x9F01C99B85C31FE6ULL, 0xF7231A45CEA509FFULL, 
            0x4745882BABF19769ULL, 0xC243B32A381053F6ULL, 0xE03E79D76987AD64ULL, 0x82D4F29EB60D99C7ULL, 
            0x6356DBC4241CFA10ULL, 0x0B1C6D00AF03CDF1ULL, 0x622DA9C2ADAA43F2ULL, 0x16C1D9713B10D461ULL, 
            0x706FDF381E88E2C4ULL, 0x7E3B739BA03BB2F8ULL, 0x0B8717295085935CULL, 0xBE9653459C5ECE19ULL, 
            0x3375246415736912ULL, 0xC8F03EC816DB6308ULL, 0x43C6F49A7AD1206AULL, 0x69DD1D21CFD3C047ULL, 
            0x5900106ADE8534DEULL, 0xD6BC002DC4236B36ULL, 0x8D451B3B3359A097ULL, 0x703EF6AA86F298C5ULL, 
            0x05F4BEDCC1B8C914ULL, 0xBB08F425F92CEED2ULL, 0x8251D9D77A395E6BULL, 0x94F905C5ECDA4713ULL
        },
        {
            0x7108CD883FD1334BULL, 0xFBE97A803FAA3335ULL, 0x49A322FCF17530B1ULL, 0xA871B894BDA5D2FEULL, 
            0xD89E67C91ACD0230ULL, 0xE5DBE77F62CC6C5CULL, 0x8AB8292181E80EDAULL, 0x9E1D24245A3B6697ULL, 
            0xD0A7EFBF25F203E1ULL, 0x11CB6291C42B3590ULL, 0xC43ACE840C3E4913ULL, 0x43ECB26E7A9F324BULL, 
            0xB60ED2B466C21D33ULL, 0x8157CE455FE794F1ULL, 0x46B91AAB4C7F0DA7ULL, 0x7968D17235461835ULL, 
            0xF62B2423238A0866ULL, 0x80BA98783FE0AE40ULL, 0xF135A4FCB9A0B7CAULL, 0x3D5D8298B24C4F3EULL, 
            0x99138FD5E826E9B6ULL, 0x3C88B4596E0FE7CDULL, 0xC6685EE09837EC41ULL, 0xF338F7B241CE47B1ULL, 
            0xBD16A403A48BEABAULL, 0x720C8ECE703743FEULL, 0x4663838AE292130DULL, 0xDB11993256B62DDFULL, 
            0x11703FEFB1E22A49ULL, 0xAC477FCC061F8691ULL, 0x15D6C626D16BF1EDULL, 0x2FDE725E5ED9D4C2ULL
        },
        {
            0xBFD6DC30FAB715CEULL, 0x214128E271C24599ULL, 0xDFFEFADD816F3B91ULL, 0x49B00CFE9CCF9D3EULL, 
            0xC0626D5AA1A4984DULL, 0x43A741D72FF6BB54ULL, 0x02837BD1FC7956E6ULL, 0x1711D6750B0BD1F9ULL, 
            0x03111EDC81463CEFULL, 0xBAF0071623E4BDDEULL, 0x640CF0F07D13483FULL, 0xE840D43F182191C5ULL, 
            0x5F965463DE4A8CCAULL, 0xF6E57D3B9E67C21AULL, 0x785EE3EBAB8C4C1FULL, 0xCC69201401608F40ULL, 
            0xF472BF4E6C5C183BULL, 0x41B98D530FA0ADABULL, 0xA1A22E18A59515E6ULL, 0x0168B3386C6C3FD3ULL, 
            0xD30A0B166305FD39ULL, 0x621725DB5910BB13ULL, 0x9F80F7E3D623A9A0ULL, 0x0F3FBBB42946241BULL, 
            0x1FB0241DFFC10082ULL, 0x0AAC098DFFBBBF67ULL, 0xC21A00855B79D803ULL, 0x288C837B08B21C8BULL, 
            0x08930699B19F988FULL, 0x637BAE29259F7304ULL, 0xBA26FD91F6F2C008ULL, 0x0C9A706EF697ADAFULL
        },
        {
            0xE38963FC1DD5003EULL, 0x6E1D0E62910396DBULL, 0x483E2934E2A69BD1ULL, 0x6E737FBA8E9489F5ULL, 
            0x9CC2117014ACB37EULL, 0xE35ECDFDC2739EE2ULL, 0x937F30355EB2DBCDULL, 0x4DBEE7CB598BEB79ULL, 
            0x27BB01A0591AE767ULL, 0x3DA97F22B6684EE2ULL, 0xE9ED03BC6BB7B1C2ULL, 0xA6227054E4AD920BULL, 
            0x0FC57F15B1054140ULL, 0xA9D924F885358AFBULL, 0x8A3CB9C5A6EEE1F7ULL, 0x5DE1577287112B19ULL, 
            0x37D2DF2065027BE2ULL, 0x074058FF4A2F98D6ULL, 0xB8D0969741950909ULL, 0x50F930891C5D6921ULL, 
            0x9298D9C11801E4B4ULL, 0xD0A3582D618F73B6ULL, 0x21B21E7D886C7F02ULL, 0xAC4BA17B33D66B05ULL, 
            0x38F03663800D63B1ULL, 0x6FBFE92B89D88CDDULL, 0xC9208A9417BE0858ULL, 0x6174C2EB8669946AULL, 
            0x4D7BD614064F7273ULL, 0x0405BF00A6F3F6A2ULL, 0xF5B71C513690A160ULL, 0xCD411BAC332E600EULL
        }
    },
    {
        {
            0xA8096CA679949CC4ULL, 0xEFD98A34B43A82EFULL, 0x2BDD654517B2E033ULL, 0x400CD159C29971F9ULL, 
            0x068ADD71AAED2487ULL, 0x9DCE207C14D08381ULL, 0xF17C6F360B97164DULL, 0x5493708177061481ULL, 
            0x8998952D2F4E381DULL, 0x174059579BF7E1E6ULL, 0xF734A49049A53BE8ULL, 0x133DDE8E697CA2EDULL, 
            0xD46E01D9A00950EEULL, 0x4752417F5DB60A7BULL, 0x679D66A0A4BE0726ULL, 0xBCE1CD078A33F6A2ULL, 
            0xDCB16CD2789D6DEBULL, 0x5D82545BC67606DFULL, 0x763B740E9FCCD713ULL, 0x7B247F029D4D2559ULL, 
            0x43BD42052096D74FULL, 0x42F461968CD3F37CULL, 0x5FAA39A1DAB21C37ULL, 0x4603B0E8DA01F2CBULL, 
            0x87A6BF26F8E4B630ULL, 0x24C9B5F8BE560772ULL, 0x2738E52273B4B3FBULL, 0x485A9A087B16DEE4ULL, 
            0xEDD9587A3BC56956ULL, 0x71A5D0B165F70E90ULL, 0x06FF04C28EAA970DULL, 0xCCB6F79F44E10E38ULL
        },
        {
            0x274B990B4D774A83ULL, 0x86D59DD4F9CFD7A1ULL, 0xF5D1B9BA014D4018ULL, 0x8F87C2006F2AEEC3ULL, 
            0x518995EE33B9C228ULL, 0x7603409C9E5B582AULL, 0x961F22D30B1BF510ULL, 0x25A7EF9DCFE3D851ULL, 
            0x8CA5CE01F275BBD4ULL, 0x958BB97D1BB7F331ULL, 0x440252F09E8A1F96ULL, 0x27ED3783C3038FC3ULL, 
            0xB6B5DF219156BD20ULL, 0x85648E35D029B55DULL, 0x7E49E5A4ECCFE21EULL, 0x08E8C5750CB09718ULL, 
            0x65B2B9C227CBC01EULL, 0xEA8F65196D7EEB20ULL, 0x2483B881568D0655ULL, 0x1C991CBBDE7BDFD4ULL, 
            0x5A0AB4AE758581ABULL, 0x362CC12B8635346EULL, 0xF18149D10C1FF42CULL, 0xCC65C892BD579CC4ULL, 
            0x0C16055BE78DBB87ULL, 0x3F8EEEA47E5AF074ULL, 0x0E570E1836AED028ULL, 0xE88FA8924F2983F4ULL, 
            0xDD77F66DE5D4F4F0ULL, 0x84380A8E7EF76257ULL, 0x6AB92961939FA656ULL, 0x3BA4B988A08E3009ULL
        },
        {
            0xF676D8DE1FE77DFDULL, 0x6BD168F46B564F0DULL, 0xE12385FEAA0685FCULL, 0x6D9B9FAC1018072FULL, 
            0xA2A84367F856878CULL, 0xE99B232AE4F01C85ULL, 0x496D7FA9F3786ABCULL, 0x80A23F1FF86E620BULL, 
            0xB0A922147BBC73D5ULL, 0x0F28A5F47F095FCCULL, 0x226EAC87032282D3ULL, 0x625F8DBC959CCECAULL, 
            0xB0FDF569DECA900AULL, 0x00EEDB2C059FC2D3ULL, 0x98A795BC183755D5ULL, 0x736FC89B0C8BE51CULL, 
            0xC208486E7ED28A1CULL, 0xCACC7F7B6CD46FA3ULL, 0x752D9975E87F5FBBULL, 0xD720957BB2D27F58ULL, 
            0x93B2C9C4A5B29681ULL, 0x13BE040DA1605BF8ULL, 0x361FEBE1E26B7ED3ULL, 0x5F5A13541EFAAA5AULL, 
            0xE8456288389A1839ULL, 0xE6E1128F2C64CF9EULL, 0xAAE3A1B387A697EAULL, 0x0E384E69BD113F30ULL, 
            0x7511B177CD6714DDULL, 0xBF3D575483E2EBD5ULL, 0x40DBDD724181D398ULL, 0x896100779E6D9990ULL
        },
        {
            0x5B01569A59FD3325ULL, 0x022B233903FF1D29ULL, 0x6A48AB3A2178FBCCULL, 0xC2AB269D3985D98AULL, 
            0xE6F00A2A58D9DB38ULL, 0xADB13B47A5D6C44EULL, 0xA580BD7961B12A55ULL, 0x670C116589946D00ULL, 
            0x552799ACF922C7DBULL, 0xF7167C9BC12220CAULL, 0xD7DC1C929AECF5B5ULL, 0x0B571866A644F5DFULL, 
            0xE866145AF6E79E21ULL, 0x67AE06E1EE5A9096ULL, 0x72A86D8330B498D4ULL, 0xA8371DAE94124992ULL, 
            0x026C885812C49677ULL, 0xEBF91543CF915129ULL, 0x1EDC7732ACE2ACE8ULL, 0xC0A83E287C918913ULL, 
            0x46233701DB900FAEULL, 0xE8D2B958994DACB1ULL, 0xD80FE90628E90208ULL, 0x577A63CA6242BC9EULL, 
            0xA369D76ED03F51AAULL, 0xB64399CEDD86E69DULL, 0x21525101DE440D90ULL, 0xE07C90389CA3D88CULL, 
            0x1F909E525D7909B5ULL, 0x33F203ECBAB96C1FULL, 0x2A235DBAB57C0F7BULL, 0xF42F0D1937B75564ULL
        },
        {
            0x89FEB6E14886A1E2ULL, 0x81C57D63B8B6A970ULL, 0x560C10A9FE9EB98AULL, 0xE022834C6F981FEBULL, 
            0xECE889207F42E176ULL, 0xABE6E85F7F469FE0ULL, 0x96AB16804D31BB46ULL, 0xC4CA64352A094F5EULL, 
            0x7104489FF3B03BD2ULL, 0xE910E5F87547268BULL, 0xD2947F6EF72F90DFULL, 0xBDC33DA5FD96A37BULL, 
            0xF8FF98E8F62AF5A7ULL, 0x86E9FC72FE1CC9E9ULL, 0x941DB16160803FA3ULL, 0x0F23CB5096D9CDB8ULL, 
            0xFF7DC23DBAA3A664ULL, 0x8012E4D313B8966CULL, 0x41753B1576BDF3CFULL, 0x47437534DAFA1021ULL, 
            0x4652A77B2E2D19B3ULL, 0x8371AB2432AD1EFFULL, 0xC903C598816080C2ULL, 0xE47CE04033B2BA5BULL, 
            0xAFB4E1E19D6A747BULL, 0x32402AE33196888AULL, 0x91680A868E9A013EULL, 0x1D9AA1CDBC741C14ULL, 
            0x8C6AB5807F4C9590ULL, 0x06E99D8115C1C890ULL, 0xBB9B3D5A1E298CF9ULL, 0xEE90444A87BC62C1ULL
        },
        {
            0x214A55C2F9659B4BULL, 0xEDD27B91FE624D22ULL, 0x71E74CE81EF9EB46ULL, 0xC6375561ACB8EFE6ULL, 
            0x6D51BC6F1BD4125CULL, 0x8628164C5D5D4F30ULL, 0xEE6AEE147AE95D17ULL, 0x46CE90F499118A17ULL, 
            0x13CD498F74C2221FULL, 0xE72749E89380562EULL, 0xE744433353D69B64ULL, 0xB2768063651E4927ULL, 
            0x839B8769C27476B8ULL, 0x62E4FDA459CF647DULL, 0xA4C1BB2D8E9C1D5FULL, 0xD50D317FDBBFB5FEULL, 
            0xA91A4853D6BB5820ULL, 0xD01A79F09B2661B9ULL, 0xE135E4B0265BA839ULL, 0x4B6AF531A82EAAC3ULL, 
            0x80F28BBEDB6B7D87ULL, 0x62B2A41C20B9FA5BULL, 0x579BC472DC251500ULL, 0x5BD4249D81B04A40ULL, 
            0x108E108855EC63DBULL, 0x177089F97854D4D4ULL, 0x3D8C514C7F2837E4ULL, 0xB3506C3AD48118B1ULL, 
            0xB17D7EFC6481B952ULL, 0x5824B07CE6B95AA0ULL, 0xD08A2F3BCFAA3C77ULL, 0x94D9A7E0AE675E51ULL
        }
    },
    {
        {
            0x2F1EF6065FC90C69ULL, 0x0BAD5F2A3EDD6ACDULL, 0x61000A1949E92A29ULL, 0xCF6F99C58B22CBD0ULL, 
            0x739CFBEC2B3D4219ULL, 0x0A254017228E4BEFULL, 0x6854427C53D81E91ULL, 0xD0DF7EB05F41BC34ULL, 
            0xD476AB92965DF70DULL, 0xE703881BFBFF6387ULL, 0x02B93A7FC5960FB3ULL, 0xCFC8D17D1B8A6FF4ULL, 
            0x6D79F6A0C6CB5F6CULL, 0x5DF2D7080D1DAAA6ULL, 0x9F3C21A6DF1A8F41ULL, 0x0E0349F9701603FAULL, 
            0xC05CDB57A4CE7B4DULL, 0x78858E0F60679358ULL, 0x8F7661FB05DB2312ULL, 0xEB4838D612657AF6ULL, 
            0x4500E0F1C8934E31ULL, 0xBD8524FAEDCE5A8BULL, 0x41785FAF99816389ULL, 0x19785AE070767428ULL, 
            0xB3076B3BBC40C6B3ULL, 0x70EDF474B089B6FDULL, 0x7EFF7B168504E210ULL, 0xB5398A381AF6713CULL, 
            0x3F059841BA0F65E8ULL, 0x398F4D8FD4699619ULL, 0xB37381004F1C3431ULL, 0x4C92812E7050C409ULL
        },
        {
            0xAAFF148CC4470B53ULL, 0xDCF987675E26A5D9ULL, 0xBA8670CACFF4235DULL, 0x8DE0941D2C2943FEULL, 
            0x6065F582B7CC2365ULL, 0xB3CBBA5DBABCFA0FULL, 0x40C109D33A80108CULL, 0xFACAC39A3524D456ULL, 
            0x1A6CA5442BB7C813ULL, 0x277F9FE3D9D5A34CULL, 0x0C7924250F84781DULL, 0xF10AA58549DCDD4DULL, 
            0x3AE060ED81480A81ULL, 0xFEB3247A1E3FF7B2ULL, 0x952A7BE7BA0B900CULL, 0x3E06FF15FC335148ULL, 
            0x819EC2A7AE71516AULL, 0xCC20D8EE2C2CD5EFULL, 0xAB397611ABA33D7FULL, 0xAA0DBFD9F92F0F5AULL, 
            0xE16C35D3D86A4DC5ULL, 0xDE04FA251D7E6A1AULL, 0xC92B137B75E937BFULL, 0x0202DB22E8DE6BDCULL, 
            0x8710F49AC5143B6BULL, 0x09E92A13393D5546ULL, 0x6DD5B382D266E7EEULL, 0x4F0227E862F3EAF9ULL, 
            0x5F485E3C9ECBE372ULL, 0x0334D9CDC098E672ULL, 0x214132DB59F86A89ULL, 0xF418EF0DA3DA2EC4ULL
        },
        {
            0x6E9A3E9348958A24ULL, 0x27C4A43B52E46D77ULL, 0x35068913B8715EF5ULL, 0x23F075C43F74BBEFULL, 
            0x3807E20ABF01E17FULL, 0xB8DD939804325545ULL, 0xF59571ABD4E9DF54ULL, 0xF8CD9160A124FD18ULL, 
            0xFA99BB0675D58C3DULL, 0xB8D589D529B89E29ULL, 0xC1472F82854E4F3FULL, 0x1FD00DCDA9911504ULL, 
            0x4C4A5E59E29ED85BULL, 0xC52978D9DD605994ULL, 0xF66C81BC07E14ABEULL, 0x61BD65C6FFC48B49ULL, 
            0x0F4E910028ECC708ULL, 0xD466A13FC2287389ULL, 0xEE320A5CB1A881F5ULL, 0x52AD095ABBC0440FULL, 
            0x440E968AB6F213D6ULL, 0xDB54A2917D44AAD8ULL, 0xB6D9A0E1F2A2E06AULL, 0xFE3FF20595475653ULL, 
            0xEC4A847F94199200ULL, 0x8B7F674515FD0993ULL, 0x6B51563FDEC3C530ULL, 0x8BBFC623E885E1AEULL, 
            0x4AD0CC117AAD52D0ULL, 0xC62EB99EAA6E7F07ULL, 0xFEBEBBF1A8EFAE58ULL, 0xAF19F7D603DB9ABDULL
        },
        {
            0x32897CCEB57047A0ULL, 0xF9BFFAF7645164F0ULL, 0xCC8318B703C4876BULL, 0x6D14643BBEA9D353ULL, 
            0x935B7AE1D650B16FULL, 0xC9261578D0C6BA24ULL, 0xC4F99D6E28DB4B35ULL, 0x1A98762FA928451DULL, 
            0x428D256D5EA4B08AULL, 0x457AF15BE79E3E75ULL, 0xE89C156A01A98EEFULL, 0x8F5B2786DB8EC98AULL, 
            0x367FEE7431551934ULL, 0xD82C6FB1C7637866ULL, 0x5E4D3C3CB8CFA634ULL, 0x583F1AF39886EA69ULL, 
            0x5DE1FC5033E436AFULL, 0xEDCBC1F1BDB457C3ULL, 0x5320E935E167E577ULL, 0xFB44A26DCF9FFBF3ULL, 
            0x97156B09ED5697B0ULL, 0xE2BE3F811EFA3E83ULL, 0xB21596D68CC864E1ULL, 0x99CB18E5859C931FULL, 
            0x48BE29217465DA99ULL, 0x2A284A313452E424ULL, 0x4D7BB360D86CD423ULL, 0x7DB5690632FA3267ULL, 
            0xE463BE99B20EFA93ULL, 0xC67A1882CA5DF5ECULL, 0xD22E5E0876C96393ULL, 0x5F0477979A3A481FULL
        },
        {
            0x5733080C2C606A00ULL, 0x3EDC610190217FD0ULL, 0x3BFA3FA25425DD71ULL, 0xBD8BEAB03F1C6FC8ULL, 
            0x239269053F6C6CB8ULL, 0xB2FCC7F5B5FCCA9FULL, 0x38FCCABCED272DA5ULL, 0x371D265080E04B5CULL, 
            0x3E8343DF0208A8CAULL, 0x277A86417E519750ULL, 0xCBE54E907EC66C50ULL, 0x3CC4561F18E15C07ULL, 
            0x08B8DF7058566E62ULL, 0x299FAB6D48E0CAEDULL, 0xB9EF62A48E692C0BULL, 0x7B21558BCD0D387AULL, 
            0x61255AA958860634ULL, 0xEF71A58D3EF0048DULL, 0xBA5189C162C17DB3ULL, 0x611E44363EE0F54CULL, 
            0xA0CFBE7C21EB453BULL, 0x0149B16C0767ADABULL, 0xC849E53B87606488ULL, 0x9AFA9D6D00714F47ULL, 
            0x3B426DED88A0A5C8ULL, 0x1D049E881F7F949CULL, 0x90106DE85B36E7F9ULL, 0xDA4073505F8D6667ULL, 
            0x6B8EB60437C51C60ULL, 0xD231A535B390C27BULL, 0x04A2CECBFE79F7F6ULL, 0x79E209238D12C740ULL
        },
        {
            0x3F4F16FADC02F547ULL, 0xD2882CF90519DD12ULL, 0x7083876333C60C64ULL, 0xF13DE44150569635ULL, 
            0x55ADDCA1965F61FDULL, 0x0E2DFD163250CF0FULL, 0x98C53E9CC16C5DC4ULL, 0xED44A22218D11D2CULL, 
            0x55DE41C1176AFA48ULL, 0x6B30563AEBA5F7C8ULL, 0x0B15D7D91E2D3E38ULL, 0x34DF81EC8A5FEFE4ULL, 
            0x708989288A5CCF60ULL, 0x2A10EC07DB2E87E4ULL, 0xD9E1B58F0D7212C6ULL, 0x848FD9E8188B5625ULL, 
            0x47B5799DCF7DE8C4ULL, 0x0C61F8BB35AFBD9BULL, 0x11F12933B0252209ULL, 0xB6083A58BD1A4984ULL, 
            0x947BB9CE58F72644ULL, 0xF02B73F0DB35B7F6ULL, 0x28DDF7F53541B93FULL, 0xBC7E8AD9E0086BD9ULL, 
            0x2A1EBEB036C015DDULL, 0xB9FEF22C1E309049ULL, 0x6DB8354A104518EAULL, 0xFC09E6897C713425ULL, 
            0x971D1B4A94A4037CULL, 0x237EBD83E8970C1CULL, 0xF0DF32BFA68C95C3ULL, 0x72539ADA66FA4123ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kSeedConstants = {
    0xD9815FBC94779C15ULL,
    0x2A4012ECCA79B754ULL,
    0xB37A12C4B41E9FA6ULL,
    0xD9815FBC94779C15ULL,
    0x2A4012ECCA79B754ULL,
    0xB37A12C4B41E9FA6ULL,
    0xD00AA09C85FCB117ULL,
    0x1D51EF366FD4F37DULL,
    0xE7,
    0x88,
    0x27,
    0x49,
    0xC4,
    0x95,
    0x4F,
    0x03
};

const TwistDomainSaltSet TwistExpander_Procyon::kTwistSalts = {
    {
        {
            0xB55B34E8B6EDADBEULL, 0xD859D2C477D1AFBBULL, 0x0127AD9CBE54FD9BULL, 0xAF073C94EFA8C633ULL, 
            0x209436C0B64F57D1ULL, 0xF8477C0139ABB314ULL, 0xD52A14DDBADACFC0ULL, 0x6CA7CFA5CDCBC13DULL, 
            0xE6DF9D585264E27FULL, 0x9AEF65D8A1039563ULL, 0xF70DC57DB703333FULL, 0x713E6869B33181B4ULL, 
            0xC3B80F31F663D8B3ULL, 0x7961D714FEC1140DULL, 0x0E350F57A4517C23ULL, 0x458F24B770CA45CFULL, 
            0x5B00A4EB78755E33ULL, 0x8D9010A06221DD61ULL, 0x7A3F5726E7264F51ULL, 0x6325E65E61E59448ULL, 
            0x4AC958AF493BF0E8ULL, 0x0DBFB70567921944ULL, 0xF7DE18F9226BD6BFULL, 0x4001917D4AA06E95ULL, 
            0xF4CBA1682D10414EULL, 0xF309D06E4BE37FECULL, 0xA00C2D8BC6CC7655ULL, 0x1F8979D9E62787E1ULL, 
            0x45F49E3B4127793FULL, 0x34885066D64BAF24ULL, 0x4585D4331863C473ULL, 0xE5FC5B8EF7600D20ULL
        },
        {
            0x24AB6F548C5B72BAULL, 0xA6D1E8252B27414FULL, 0x02947EA2E2562238ULL, 0x99911D9D9D2A165FULL, 
            0x5F750C9CB2F2D25CULL, 0x4B22FFB3CDF716D3ULL, 0x717AF09709808F06ULL, 0x86230A0572A9F704ULL, 
            0x47C6773EDFC71D24ULL, 0x8291A6CD4161128FULL, 0xBE8C305B2E4DA803ULL, 0x59E7D691D3D7646BULL, 
            0x29EAC544DF5F0A26ULL, 0xFF3B1425885439C2ULL, 0xEC1D54D18E02F172ULL, 0xA2E5914BD9B2B809ULL, 
            0x860667E236233AFAULL, 0x4C61760AA03E10A7ULL, 0x1D0BE8A10DE83A80ULL, 0x727836807E269105ULL, 
            0xCBABA0FBA1720EB9ULL, 0xCD2EBF6E0D55D7A8ULL, 0xE06788E1277EEFA6ULL, 0xF9A44A79582E6F89ULL, 
            0xD95BD6586E3D0ADAULL, 0x605FD35B7FC83ED6ULL, 0x721D5EE9411755FFULL, 0xA495A5BF63E36585ULL, 
            0xD90D837B74DBD119ULL, 0x75A433281F3AEBFBULL, 0xA8EBE607F80F4605ULL, 0xE9F92A5014F85EC4ULL
        },
        {
            0x6E309292AD1CB61BULL, 0x9A6BC225350C79F2ULL, 0xB44989052AC7C77CULL, 0x46E88F0AF44B4790ULL, 
            0x1E51E00765305EFBULL, 0xC4EB911FA3F29A18ULL, 0xFA044A0786A948DAULL, 0x655CDAA98C46B6EFULL, 
            0x02FCE6B5D042998DULL, 0xDF42E6DD44D34B26ULL, 0x283B1616D375046EULL, 0x6E480E6F4C7C252CULL, 
            0x0B4BACF73B6EF3ECULL, 0x543A451AE22AD1EEULL, 0x29D21DAC0F90D9A4ULL, 0xC6D3536056469D53ULL, 
            0x2086FDD450E37B97ULL, 0x84E2F3C4EC1A3A6CULL, 0xCE69D850B649DB48ULL, 0x32E9790BF7CA3457ULL, 
            0xF90046E77507CB69ULL, 0x03C130593D3839EEULL, 0x2C195429819D913FULL, 0x82353AF7484BB021ULL, 
            0xDF7378D52880ADD4ULL, 0x3815F1DD059B234DULL, 0x7AED67C2C10348F7ULL, 0x093A0463948ACE4FULL, 
            0xE75303CEC9354A33ULL, 0xD4D822308EC152D4ULL, 0x70FF8C891EBB7F4BULL, 0xD1CA97A863DEE8B6ULL
        },
        {
            0x5902CCBCF09BDE18ULL, 0xE8B3D7A7F2994295ULL, 0xF9726500F83BB4ACULL, 0xAEAEF5807BF9B1E0ULL, 
            0xA0479F6BF11DAF55ULL, 0x40EDF7C04D2E1254ULL, 0x9F3DF15D8491623DULL, 0xFAA277B87619ADD8ULL, 
            0xBFAB1C5F4D22D635ULL, 0xAD60BECE957BF265ULL, 0xB9E64B36CF154BFAULL, 0x493556644FFAD078ULL, 
            0x56C2F630267323E1ULL, 0x9349770281D37237ULL, 0x19452E72455ECD7BULL, 0xD8B12A335B37B92CULL, 
            0x30A2F912A958FF42ULL, 0xC61247BD8D41E4B3ULL, 0x8FAB8C5CD39CAAFFULL, 0xE9F8A6A296FEB852ULL, 
            0x911B242479685B8FULL, 0x318F2F6D96D43C59ULL, 0xC2E3BE5931BCF85EULL, 0xCCA2154EE2D01962ULL, 
            0x45A8A00ACA651A44ULL, 0x885444F4A6B2698CULL, 0x17F207FECE97D254ULL, 0xF09DEEB62A7A2540ULL, 
            0x24AA0EC94F570803ULL, 0x1F4AEDA39DF0482FULL, 0xF47048038C6E345EULL, 0x124390CA939A284FULL
        },
        {
            0x35AFFB0960986167ULL, 0x558BDE9FCE041E10ULL, 0xBCB1FB8702C082C4ULL, 0x55BF26E7AF3E6984ULL, 
            0xB37A16829113A66EULL, 0x66D22B59F6E06195ULL, 0x0A58683C87EAC7FDULL, 0xA4CC68F28AD587B8ULL, 
            0x9E7F052370C0DC49ULL, 0x8A707CCE08916B1AULL, 0x1058EE5E8F3AA84FULL, 0xB390452873F2B64CULL, 
            0x6A9DD559C1C6EB35ULL, 0x3F2DD7783B2FAFB2ULL, 0x7D7ED12719E3EE07ULL, 0x8B2B5176E00AA1DCULL, 
            0x6510D3915AA8FD3BULL, 0x6713D26EFE059B02ULL, 0xA4C786C55CF38EBBULL, 0x9A6EB69D4C1EA73EULL, 
            0x5DCA2089FF86D1EDULL, 0xCA33AAF0F395A8DDULL, 0x81A798B7014C4854ULL, 0xD62E0CA2BBB35F80ULL, 
            0xF0BFB267C0FFB03BULL, 0x39141E0D87E0360CULL, 0x92568A96BCA72C8BULL, 0x5A9EB72E104738E4ULL, 
            0xA05D26F336F0F955ULL, 0xE7EBBC5D70A3E2B9ULL, 0x1E0428418974F082ULL, 0x0C49DDD1CCDADEECULL
        },
        {
            0xBCB660D16C57D424ULL, 0x126F38C7C5E521C0ULL, 0x36F347BB8317CE80ULL, 0x36006878C8CD828BULL, 
            0x0B09AE8DF724D6EEULL, 0xF80F1BFB8BEE0E3BULL, 0xF08177F40DA591FCULL, 0x9958EA841EB05C8EULL, 
            0xEB09F123B1ECCECCULL, 0x4F5B4F248A5D75E2ULL, 0x68FF87B3A900559BULL, 0xE366C7396EA8FC89ULL, 
            0x1FC68588722C1DAFULL, 0x2F2AB8712D422604ULL, 0x15F2F05A90F60324ULL, 0xB0AD009A0C495A29ULL, 
            0xBAE03DC9279F6E3DULL, 0xD7B1BC4281C0869CULL, 0x2B7B0F6361FFB084ULL, 0x7F2F36F9817C9635ULL, 
            0x2AEF56058C4D5A2DULL, 0x31E2F94D344FAED2ULL, 0x2F8BEC3AC30EC7A3ULL, 0x96E13F14436E7177ULL, 
            0x5EF78C440F597EFCULL, 0x88CE865780C4D628ULL, 0x5698DC68A8618A86ULL, 0x366673729ADD17E1ULL, 
            0xB860D7525DFC7CEFULL, 0x46EFE0099E608AFAULL, 0xA30829380B847C87ULL, 0x07AA1BF0D502A1C7ULL
        }
    },
    {
        {
            0xF73470255007CF5DULL, 0xB987BEAD2B632A39ULL, 0x0ACFD9618ACD44B5ULL, 0x29F2A1BFBB3BDE05ULL, 
            0x18D4F23D49CC9F07ULL, 0x5B573A948594DA2FULL, 0x8DBA1972D18AD4ADULL, 0xB72D1DBA32711397ULL, 
            0xEEF166937493F33DULL, 0x216544DF0F5B4F45ULL, 0x8970BCC05312815AULL, 0x6B901C58F203253DULL, 
            0xEDFF1B0A6F7212CBULL, 0x163724114500B890ULL, 0xBC171957CCC3901BULL, 0x642EF0FD41FC8C97ULL, 
            0x2BE082676161373EULL, 0x1DEE6680E6666E8FULL, 0xCE9DC4144B8FEAA6ULL, 0x1EA25219D6D6F9E6ULL, 
            0x9E97E179F30080C9ULL, 0x97C0172CFE93FCB1ULL, 0x6928E92ADC6EDB25ULL, 0xCB81ABD9FBA5724FULL, 
            0xC7A8305B8B462C6AULL, 0x717878BABCAA29C4ULL, 0x4ADD442FB5879F2DULL, 0x04CBA464C9FAF941ULL, 
            0x25A76B0448A0D93CULL, 0xFB7755472EBFC060ULL, 0xDB15788FB635E4C8ULL, 0xA44843D9CA667183ULL
        },
        {
            0xDEE4E3163A368961ULL, 0xBDD9C27A11E0DF23ULL, 0xD2DFABD0DDBFA29DULL, 0x91984C06C68B35FEULL, 
            0xEA8AAE23D7DDE075ULL, 0x2B8F0060BC1C2E8DULL, 0xB3A11F291B10D3A2ULL, 0x52481B65343D04D1ULL, 
            0x91806FEF59CE1939ULL, 0x80F06571403E5FE9ULL, 0x10859D561A1B2209ULL, 0x5B11C3AECD34D577ULL, 
            0xE9C57DA881C00209ULL, 0xCCD4E27C1426AC8CULL, 0x882672C8D485DE60ULL, 0x3817DE24801B40DBULL, 
            0x1D24707389F507B9ULL, 0x385737F6B9C87E63ULL, 0xE80F0B303B92E3D1ULL, 0x0727A73DBF8B4947ULL, 
            0xD50BD3C9CFAD705EULL, 0xCD94813AC09B3715ULL, 0x11AC99C48C353896ULL, 0x329735C78BF5B3F7ULL, 
            0xF003A1DA5D2461B9ULL, 0xF09306CB77F14586ULL, 0xB1F1531D6AC46C57ULL, 0x66828594816E6E3DULL, 
            0x265E286E270DBB3AULL, 0x1930F7DE7C53FB70ULL, 0x1A3588BF2963D4AAULL, 0x8694154990AAB4ABULL
        },
        {
            0x0581056D0FA2AE0AULL, 0x23BD04F8147079B8ULL, 0x475B54F9BC76735BULL, 0x40C91106B17F75EFULL, 
            0xF6C12CC6E08232C8ULL, 0x234FF844C90530B5ULL, 0x5A293F0A7721439FULL, 0xF895F4D7896F08A7ULL, 
            0xB03E01E84F371C5BULL, 0x7B71DDB461979020ULL, 0x890CB54BED7D7084ULL, 0xEA4EE5DFA864482CULL, 
            0x5D4BE0F88D5E282CULL, 0x8D914DAF0E9A961CULL, 0x4A18559E3A99EA5FULL, 0x29DDFB5491AE05ABULL, 
            0x59705EDC177F4EC1ULL, 0xC5C636AB93EE9D8CULL, 0xD96E6BE81587F871ULL, 0x5F46ED6D2B1DE8AFULL, 
            0xC69FC3E4238EC191ULL, 0x9A7BC302ACF91BE7ULL, 0x32261A03B3FECAD9ULL, 0x57E6EF7BB8753648ULL, 
            0x41B19B434770331DULL, 0xB77C41633BBA42FDULL, 0xA3D511EC89A959B8ULL, 0xA31B4D1D0FB22487ULL, 
            0xBED807608D140A2BULL, 0x15EF8316EF526614ULL, 0xD192535C2022926CULL, 0x711FAD64DE42BBA5ULL
        },
        {
            0xFD3B4082242316A7ULL, 0x039150D03AD3FE0AULL, 0xB25F032F4E57EF6DULL, 0xBD4F92A22DBE120DULL, 
            0xBD23D3E3489401DAULL, 0x6BB0CBF71B8B6ADAULL, 0x327C395BCD2EEC07ULL, 0xC8D37844C9A2AAE5ULL, 
            0xD6783263001F3483ULL, 0xF5C61002EC5972CDULL, 0x8DAE9E02501FBB21ULL, 0x7105A88289D8DF41ULL, 
            0xB61C65313D11465FULL, 0xB0ABDC92EF721FE6ULL, 0xEB3DA53EBEFAAD83ULL, 0x8636DE05E5D560FBULL, 
            0x072B1D07623B40A3ULL, 0x7ACC28A6C4900A30ULL, 0xBFE5A74808FB70EEULL, 0xCD38F948B2D0E5FBULL, 
            0x769CD20C21ADD2EAULL, 0xB6AEFB28545AD232ULL, 0xBDA555C63EC14BF4ULL, 0xA14E4B3FD9FB8C7CULL, 
            0xD4FF01768B2574FEULL, 0x37AC18F0E773083EULL, 0x60A5619B3B577DF3ULL, 0x862EFB07A979A472ULL, 
            0xE79932E8BCEFAA69ULL, 0x9103609E959F2616ULL, 0x2ACAA984265B5C13ULL, 0x6C8F72085F1A0301ULL
        },
        {
            0x1F5D1423F76E55C1ULL, 0x39641CFF89A3A605ULL, 0xDCD90745393599A0ULL, 0x87C001D90AE862DEULL, 
            0x8DCC10E7601891EBULL, 0x80C775BBB84290C1ULL, 0xC17719844020DC96ULL, 0xB9C5E5AA6F0FC415ULL, 
            0x32E10195E78339DBULL, 0x1D5CEE5143259F9BULL, 0xDCE11D96C6557C26ULL, 0x901D58CD2E60234DULL, 
            0xC8BFF6111458FC78ULL, 0xD32B292D334BB073ULL, 0xA4F45A90E8605EDEULL, 0xABDEF833EDB8AC5CULL, 
            0x3FA26EA8FFDE4603ULL, 0x7994773D642D3476ULL, 0xE0A496B68F83D7B2ULL, 0xBAB805142B4CFE3BULL, 
            0xE70BD87E7B927106ULL, 0x9249EB35AFCFDADDULL, 0x825C6FE3BBE27C47ULL, 0x0BEB4EBBDE2F987FULL, 
            0x0FCD25F6AF7F0184ULL, 0x06E2A2A4CE633146ULL, 0x1C0FFD25B440D711ULL, 0x33AAC76DA90321B1ULL, 
            0x6542D93AA4216DD5ULL, 0x078FE1102632EE77ULL, 0xD1101C39EFD62949ULL, 0x955F587D13A63204ULL
        },
        {
            0x2C910BD731927610ULL, 0x06654ADCEE7223D8ULL, 0x605BD5539D7544A9ULL, 0xEAB87673D8F5694EULL, 
            0xC10D9124ED5FCDBAULL, 0x161F3138E708EDA3ULL, 0x7027BA138C4FEE45ULL, 0x3DE8C34A36EFE275ULL, 
            0xEC753915E6101FB4ULL, 0x257FC979F8E4C820ULL, 0x6A69D4F5A684E4B0ULL, 0x11E1B5F157503557ULL, 
            0xC2D32D84EC9703AFULL, 0x00A9802DF9E5BF2BULL, 0xB0CC60096FB1EE2EULL, 0x2C48CB0F0E7DEC65ULL, 
            0x092D523848F1A0FAULL, 0x413EBC5F65A344DDULL, 0xF7F21D58C15F7BF8ULL, 0x21FDBF385F704C8FULL, 
            0xB2770289C21E6CEEULL, 0x81A1EE47C3B43597ULL, 0xCFC67D0E2AC0CB30ULL, 0x270EDBA977ACD525ULL, 
            0xF20BD8430C9804DCULL, 0xA42D3BA3F808B435ULL, 0x30A4B8D137449EAAULL, 0xAD241A75B8375F9EULL, 
            0x4D71739CA0C87E9EULL, 0xE6431EF5A64AA6E3ULL, 0x0229939A375B2777ULL, 0x0C208F34BF6F6DD9ULL
        }
    },
    {
        {
            0x140DA7D21629E0F8ULL, 0x9A57580DE478355FULL, 0xFE67615851002798ULL, 0xFFB0E11D3EED302CULL, 
            0x1B87DC8A670DA6A0ULL, 0xBC7AAA15D06D683FULL, 0x961BD09A9BB6B634ULL, 0x86F4AB7403B1E8C4ULL, 
            0x9A3AD83E7DCCB755ULL, 0x338DFCB6A29B5090ULL, 0x9C68B67A46DB5920ULL, 0x8D06DE0FA115E4ADULL, 
            0x57BD44BD878665CEULL, 0x1C436507CB96ECFCULL, 0x382537FE34E18CEFULL, 0xB5FDC21833728050ULL, 
            0x3C1607EF06DBE30FULL, 0x8C888977B01F2F0AULL, 0xE5B5C4BB808ED70CULL, 0x0E69E01A760B2C12ULL, 
            0xCE05933607BF7C23ULL, 0x575A31DD4036DBB5ULL, 0xFB2EADDD3A2D5FEDULL, 0x7F17B38EDA44870AULL, 
            0xA1F044AB11C6A7FBULL, 0x4060AA1DF7510538ULL, 0xCFF8CF4BCD9E92D1ULL, 0x04E578CF1F0F3ABAULL, 
            0x06097C6927F5A890ULL, 0x3800C5D2A9B2CCFAULL, 0x849FD9B48288C6C2ULL, 0x9392E2FD61A83E7EULL
        },
        {
            0x550BC42DA35320A7ULL, 0xF11A2E5489A90AB4ULL, 0x08AB30EB0AB93217ULL, 0xFF534FE4D0465F8CULL, 
            0x0767EF22AFC3981BULL, 0x8F9DB6E91FFD3D1CULL, 0x5404D5F5AEAAE35FULL, 0x003FEF3250A74A97ULL, 
            0xCC0C6FE5BD9B5040ULL, 0x318E2FDD00FF5CB8ULL, 0xEA4E34720C6417C3ULL, 0xBF2DEB009EB8FE1EULL, 
            0x6AB87B130065E495ULL, 0x90B0960A6719216AULL, 0x32CD8EF3643845A8ULL, 0x9E4A5F0E456C8C78ULL, 
            0x5CCF35A0CDEA18D9ULL, 0xC0ACC4E0488B5C2EULL, 0x571C8C516B020743ULL, 0x488CA3F9BB96EE7EULL, 
            0xCE3709550437A376ULL, 0xD79E3567C88AB70FULL, 0xF3899F5FAF0680CAULL, 0x5F7FE317038A5D06ULL, 
            0xCE961DA49C128888ULL, 0x3C6018DA1A26C136ULL, 0xE7441CB21994FF03ULL, 0xB79B1C39BD876C82ULL, 
            0x022EAC7484FAAF79ULL, 0xA9A96F86575FC8ADULL, 0xDC1D805FF01613C5ULL, 0xE92783397A47F471ULL
        },
        {
            0xDCBF4B7AEFA6A9AFULL, 0x11FDD7376DD44ACCULL, 0x7CBE9F44CF0F12EEULL, 0xEC175A964204EE1CULL, 
            0xC236E2F6BA13D21BULL, 0x9DD47CBF192E4D89ULL, 0xB204C6AA5D1B3225ULL, 0x100AB807B9534204ULL, 
            0xD400799745019FDAULL, 0x0347E64CD70EC203ULL, 0xB1B750B8DA279DCDULL, 0x8B06093DB0EF1348ULL, 
            0x7BE981D49B84A532ULL, 0xABD254475EDFA3B7ULL, 0x2FEFA3D88D354D66ULL, 0xFD83052886603756ULL, 
            0x0EB250C8EF207100ULL, 0x9BA284B1CFAA2B25ULL, 0x41E16FF48FFDAA1DULL, 0xB89C0AA84A962801ULL, 
            0xD7B4DBB164937222ULL, 0xD4467137D94B4F61ULL, 0xE5DE4F2E062BFEF1ULL, 0x0C11883345FFA836ULL, 
            0xCF1D60D415D05DE0ULL, 0x7DE12481231D1E97ULL, 0x2518126B526A6FF4ULL, 0x03E5D8271B7FFF79ULL, 
            0x589256331D104B10ULL, 0xC63DD1D8EC7FF871ULL, 0x7520AF0313E4BDF7ULL, 0xD288D382F2880303ULL
        },
        {
            0x9A2347D5CB224731ULL, 0xC1E680631AFF4B80ULL, 0x56BAF0B1635B4B85ULL, 0x51050F9463ADE2D2ULL, 
            0x0B11ACEF65DFE552ULL, 0xC31E875A74E0988EULL, 0x92E38B07B29151E2ULL, 0x9974DF905D9B33A6ULL, 
            0x97E3D27E2E4076E3ULL, 0x8EA408FDF02C3E53ULL, 0xB9E28C1189B95210ULL, 0xAF91C4AB2BCF59CDULL, 
            0xDACF5D50379869B1ULL, 0xB768598792B8D8CFULL, 0x750064743ACE10C4ULL, 0xB504D2E3FBF34237ULL, 
            0x506A06B7DF09823BULL, 0x181B3686C2339C93ULL, 0x5B6296550CE5A6F9ULL, 0xA839306BFCA1171EULL, 
            0xB2B5947134048B15ULL, 0xA0D387E192018E74ULL, 0x906EA16565E5D548ULL, 0x61F97DE57B1FB912ULL, 
            0x385A9A90ACE2F584ULL, 0xB1E6131033134887ULL, 0xCCBC1F497EA649BCULL, 0x06B12FA42AE0CCE7ULL, 
            0x5FC00068A4558438ULL, 0x8C8BC9CD6F1F4806ULL, 0x2482621147B17290ULL, 0xFAF4900B5E252F58ULL
        },
        {
            0x84CDFCD7D753FDE8ULL, 0x7AA6BF900EBB4F55ULL, 0xAC9CDDB1EFF7BA0AULL, 0xB39A574853BEB5ABULL, 
            0x6FABA9FA8AC7EFACULL, 0x17425774EB36E438ULL, 0xA719930363BB4936ULL, 0x17F453E930E88951ULL, 
            0xB131E345698C8E28ULL, 0x2302A49166C253D4ULL, 0x8155D7A5FEEA285AULL, 0xED034BE7DF2A7D7DULL, 
            0xF669A11F5A46FC7EULL, 0xF8DEAF1B1366CA52ULL, 0x5CF23021F9C78894ULL, 0x71ECB06CD02F68B8ULL, 
            0x3B6A08692226724DULL, 0x1BFA2D0C057E2896ULL, 0xA8CB54ADCAAD50F4ULL, 0x2AEE0E02FA279541ULL, 
            0x975453348797AD58ULL, 0x9C4A22E1AA3064AAULL, 0x119DFB7D36389177ULL, 0x8154BC30031EF83CULL, 
            0x1ED68E4A6F8950DDULL, 0x4B68D0A8FF1C046DULL, 0xD03B5AF048E79A2AULL, 0x15DCA6C5880C9607ULL, 
            0xA23D354D1B1ED4F4ULL, 0x45A315049D15459CULL, 0xF57027CE3F107981ULL, 0xF57F3E7326C143B2ULL
        },
        {
            0xF56992826173BE0DULL, 0x0FFCE77493EFA8FCULL, 0xA85FCAB378C28B4BULL, 0x91728B96F8D8C31EULL, 
            0x49B08375B8C0C361ULL, 0xDE3E686A9D837F89ULL, 0xFA61146F2835370CULL, 0xCB6A27EBAE9DB311ULL, 
            0xF19EFB415D7F95B6ULL, 0xB8E332A53E99A3CFULL, 0x220AA858B7EE49CCULL, 0x1B072313E53B3071ULL, 
            0x7FEDA220DC3CB8A2ULL, 0xA4FA12D4FDD9E99AULL, 0x86F8012D410100BBULL, 0x9815FFE425D0AE27ULL, 
            0x4BF816EF4658ADC1ULL, 0x3FB9AC650D9932B2ULL, 0x59D878FC410C9714ULL, 0x6CD125768C4B93F5ULL, 
            0x1D3954995E7C7D4EULL, 0x9E2ED6E6AD853729ULL, 0x6B16CCDFF4E6FEA4ULL, 0x7D6FEA9027163EA0ULL, 
            0x4BBE6A3E659324B8ULL, 0x0453C4EA10FBF9C1ULL, 0x11B288C262A9B8B1ULL, 0x32A6AD66A9A172ADULL, 
            0xB8B3C8BD12C498D0ULL, 0x97DE5252337697D7ULL, 0x9DD9FE09FEB7E80AULL, 0x6027611C2E9E212EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kTwistConstants = {
    0xF9CC6E3E9832CBCCULL,
    0x8F57E08E270E855BULL,
    0xCD352163E62C0967ULL,
    0xF9CC6E3E9832CBCCULL,
    0x8F57E08E270E855BULL,
    0xCD352163E62C0967ULL,
    0x6E232096F272D466ULL,
    0xB5543FF41AA512A8ULL,
    0xF4,
    0x79,
    0xA7,
    0x90,
    0x4E,
    0xB6,
    0xEE,
    0x2F
};

