#include "TwistExpander_Mothallah.hpp"
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

TwistExpander_Mothallah::TwistExpander_Mothallah()
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

void TwistExpander_Mothallah::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mothallah::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC86CA7AF771D2E74ULL;
    std::uint64_t aIngress = 0xA8EC5D342DD99DE9ULL;
    std::uint64_t aCarry = 0xBFA0EEDE2DE1EDF3ULL;

    std::uint64_t aWandererA = 0xE11F38D020D69C9EULL;
    std::uint64_t aWandererB = 0xAEA5706D00B3EE34ULL;
    std::uint64_t aWandererC = 0xC883472BEB7ECBB2ULL;
    std::uint64_t aWandererD = 0xAE8AE4B4994B817BULL;
    std::uint64_t aWandererE = 0xAD8DDF31A4B16445ULL;
    std::uint64_t aWandererF = 0x96D508C6A0933F5CULL;
    std::uint64_t aWandererG = 0xD6959914520CE6B5ULL;
    std::uint64_t aWandererH = 0xF5B15E19A5A9DF92ULL;
    std::uint64_t aWandererI = 0x9B6F231E3CED3BA8ULL;
    std::uint64_t aWandererJ = 0xBCEB170D98481B15ULL;
    std::uint64_t aWandererK = 0xCD35A6A6D62E5EE1ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xBC4A9DED293F5423ULL;
    aIngress = 0xB9B9101C87258B27ULL;
    aCarry = 0xD373508B0E5C977FULL;
    aWandererA = 0x863B9F63EAD97E07ULL;
    aWandererB = 0xA23ED9AEC188FA9DULL;
    aWandererC = 0xD895B23C29D4D584ULL;
    aWandererD = 0xDAD54FD1F9DCEF7BULL;
    aWandererE = 0xE022F543461E1B97ULL;
    aWandererF = 0xD0BED5FF4A5492DAULL;
    aWandererG = 0x81AB90CAA3B9BFCBULL;
    aWandererH = 0xBA6BA27E1CF073A3ULL;
    aWandererI = 0xAF0D6404A37F95C9ULL;
    aWandererJ = 0xE096B67F42C59E62ULL;
    aWandererK = 0xC6632C3774056DF1ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x80FFDBB87DA060AFULL;
    aIngress = 0xA063639FDDDD2085ULL;
    aCarry = 0xCE570B87767CEA77ULL;
    aWandererA = 0xB548376B4B9C712BULL;
    aWandererB = 0xAABED19AC412D44CULL;
    aWandererC = 0xA00B8C998A73B8C1ULL;
    aWandererD = 0x85C92AF0A8EB66C7ULL;
    aWandererE = 0xB57946078699601EULL;
    aWandererF = 0xFBA095DE63C1390EULL;
    aWandererG = 0xD5037DCD1D64CE32ULL;
    aWandererH = 0xC2B80F55921D5DD0ULL;
    aWandererI = 0xE4540F927EFD2FA8ULL;
    aWandererJ = 0xF3B2640183D87B24ULL;
    aWandererK = 0xDBB43C193EC875CDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xF3C07126DF0FE2DEULL;
    aIngress = 0xCC6886F649B681AAULL;
    aCarry = 0x9B35F930F76EF24FULL;
    aWandererA = 0x86989D34D285A1B7ULL;
    aWandererB = 0x88853FE582DDDAA6ULL;
    aWandererC = 0x8D41FDA5C5999EBBULL;
    aWandererD = 0x85743E778AC4F019ULL;
    aWandererE = 0xA854FD8B35E4997FULL;
    aWandererF = 0xACCCB4F25AD2E8B7ULL;
    aWandererG = 0xF6C424F305D15E6AULL;
    aWandererH = 0xA0C66983D54B23C5ULL;
    aWandererI = 0x902E3D1F7A551E2CULL;
    aWandererJ = 0xDA719E567CC27857ULL;
    aWandererK = 0xC8F892E0B6C3687CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xB24CBF52A5689DCFULL;
    aIngress = 0x85692661CC8DD713ULL;
    aCarry = 0xA7729748D9983D77ULL;
    aWandererA = 0x9E839F2B9001EF32ULL;
    aWandererB = 0x9BAC1E3538586339ULL;
    aWandererC = 0xB9525F9DBB697BDAULL;
    aWandererD = 0xEEE560AFDAB10509ULL;
    aWandererE = 0xA9CD775E8BF282E6ULL;
    aWandererF = 0xABEB2F465F405862ULL;
    aWandererG = 0xC743E40420F3B4A1ULL;
    aWandererH = 0xBB285AE6163F1DB5ULL;
    aWandererI = 0xC3D69E06966D2EB6ULL;
    aWandererJ = 0xF7BB02863A6CCCD2ULL;
    aWandererK = 0x9AE04C39E502DE46ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC5D2A5157ECF75EBULL;
    aIngress = 0xAF225BBFD173B36FULL;
    aCarry = 0xA2466E989B8E2516ULL;
    aWandererA = 0xCFE2553EF12EC123ULL;
    aWandererB = 0xC9A9928BD690D483ULL;
    aWandererC = 0xA110EB359B7AB9D0ULL;
    aWandererD = 0x80F29685D73F65F4ULL;
    aWandererE = 0x8961F5B0378F63FAULL;
    aWandererF = 0x8AAC58917ECFFFECULL;
    aWandererG = 0xCF174479F7E5CB20ULL;
    aWandererH = 0xDDC4ADC2972B3EF7ULL;
    aWandererI = 0x8D79F34C3EF144F6ULL;
    aWandererJ = 0xA4A6043410030CBCULL;
    aWandererK = 0xB28D98C62CE95D23ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA6B69EEFED9AB076ULL;
    aIngress = 0xDF54BF5BB7C64266ULL;
    aCarry = 0xB4321BCB93952CA3ULL;
    aWandererA = 0xDA2303BD88550B17ULL;
    aWandererB = 0xFC7A1AE795AD220EULL;
    aWandererC = 0xAC51725B010E656FULL;
    aWandererD = 0x9BFCD5E4F90A64E1ULL;
    aWandererE = 0xA89A6D16FC738934ULL;
    aWandererF = 0xDC7F9DFD2CB673C2ULL;
    aWandererG = 0xFE0DAC26F6FB7B2BULL;
    aWandererH = 0xC190989F6C772A0BULL;
    aWandererI = 0x9B0D91AFCC4A7A48ULL;
    aWandererJ = 0xE6DAD94DE1A84265ULL;
    aWandererK = 0x8EE5276A720D5635ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xE4D76BB00554423CULL;
    aIngress = 0x9CF8B4FB2C385FF4ULL;
    aCarry = 0x90F88A4619739DF0ULL;
    aWandererA = 0x9F5BCEB755721640ULL;
    aWandererB = 0x990A353D124DD075ULL;
    aWandererC = 0xFD2577C1BC5F62A7ULL;
    aWandererD = 0xCDC515938BD3D172ULL;
    aWandererE = 0xAFA937415F73AF50ULL;
    aWandererF = 0xE449B92FD7532868ULL;
    aWandererG = 0xDF531864C6D5E0D2ULL;
    aWandererH = 0x94058E8756A68FB7ULL;
    aWandererI = 0xDCAD94CA947A08C7ULL;
    aWandererJ = 0xC1CFCF7CFBE0015BULL;
    aWandererK = 0xAEB6C3BCE6205688ULL;
    //
    TwistExpander_Mothallah_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Mothallah_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Mothallah::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA68222BFDA5CC049ULL; std::uint64_t aIngress = 0x95C1F8E27C2A5A96ULL; std::uint64_t aCarry = 0xC3AA9DE4BFD96DE9ULL;

    std::uint64_t aWandererA = 0x97F2B6F14F377EAFULL; std::uint64_t aWandererB = 0xEA40B51EE1641291ULL; std::uint64_t aWandererC = 0xC5EC334B27DF22DBULL; std::uint64_t aWandererD = 0xE96A645CAB412A4AULL;
    std::uint64_t aWandererE = 0xBDC40D3E711D3C01ULL; std::uint64_t aWandererF = 0x9C08AA29AFAEE399ULL; std::uint64_t aWandererG = 0xD318D44112E6D210ULL; std::uint64_t aWandererH = 0xACD2BAB1D250CF51ULL;
    std::uint64_t aWandererI = 0xB499EC7B8055817AULL; std::uint64_t aWandererJ = 0xE448E5677C955A86ULL; std::uint64_t aWandererK = 0x8EDDB1757C5E07B8ULL;

    // [twist]
        aPrevious = 0xBA3DDEA5F8E82C8CULL;
        aCarry = 0xECE2B5FD549BD232ULL;
        aWandererA = 0xDE133E5BC12DC6F1ULL;
        aWandererB = 0xA5D085219D090AD3ULL;
        aWandererC = 0xD592BCEB2291A6F6ULL;
        aWandererD = 0xF5CE2776D7C25804ULL;
        aWandererE = 0xC92BC2A593C0F613ULL;
        aWandererF = 0xE8CBF456CF9A3618ULL;
        aWandererG = 0xF2955E537CE25506ULL;
        aWandererH = 0xA7CD5C8232A6BE96ULL;
        aWandererI = 0xD1A8C5CBC4DF947AULL;
        aWandererJ = 0x94CBC3D21311FA3FULL;
        aWandererK = 0xCD7F4078CF1C87FEULL;
    TwistExpander_Mothallah_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mothallah_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Mothallah::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mothallah_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mothallah_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mothallah_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mothallah::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mothallah_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mothallah_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mothallah_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mothallah::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 22 of 33
    // Exploration cases: 0
    // Structural maximin 519 / 674; family total 11237
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 22 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 11221
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1195U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mothallah::kKeyRotateASalts = {
    {
        {
            0x4B76EC54EF975E7AULL, 0x90CD04CA69FA811CULL, 0x1ED23FA7E52AB346ULL, 0x3936970C9B19D692ULL, 
            0xCA9EDFD2B398EA41ULL, 0x20815E6DD72D8403ULL, 0x385569A0AFC05A90ULL, 0xCDC49F3DB283A21FULL, 
            0x31FA38E756B5765AULL, 0x3BB49AB85B51A90FULL, 0x67AB68E6A83A8407ULL, 0xA80A2E6ABD0FD1A1ULL, 
            0x60D11C5DC5D13956ULL, 0x8A3B45ADB7213363ULL, 0x85C8894DA26014E4ULL, 0xFEB3598A5472D2D4ULL, 
            0x9C48A1EB3EA5EDA1ULL, 0x3FF6F58F293DD6FAULL, 0x59D3F077116FE713ULL, 0x730D908526B5DC7FULL, 
            0x6D5C1EBCA8362134ULL, 0x16C7F7DDCE6F5882ULL, 0x52E74DC6F273064BULL, 0x57BC95D20C304A8CULL, 
            0xB47B34B5E132E39AULL, 0x09E84CDF5FC6A540ULL, 0x58C34923BE4DB0F6ULL, 0xE04544CC77B30294ULL, 
            0xC7D1063C97EC04A8ULL, 0x538AFA78A8275DFFULL, 0xC4D79F084270CF3CULL, 0x65DCADCAC08F375AULL
        },
        {
            0x1BD6AD6C189DEFD9ULL, 0xB266C40ABB957CF3ULL, 0x074C6E222599C0C0ULL, 0x31F3FA414C985736ULL, 
            0x762A2465FC5250E2ULL, 0x488075A9F4E7FB6FULL, 0xCE14EC1880B0F7EFULL, 0xB8626281C46D1BEAULL, 
            0x8AFC4A8A382F4236ULL, 0x69C4BB1BA8268AF7ULL, 0xD195534BABD43686ULL, 0xC1CD7FA578985A4CULL, 
            0x5978B1B191135E8AULL, 0x1DB14276B887B622ULL, 0xF873824C667272DFULL, 0x8358AA408424104BULL, 
            0x24A2C31E18010F6BULL, 0x23372AEBB9E213E1ULL, 0x426E9EDCB6778E2FULL, 0xD56F3D2B5254A535ULL, 
            0x71DF94125532392AULL, 0xE40D614013617D8DULL, 0x87A8A30441696266ULL, 0x066B160C86A0A8D3ULL, 
            0x6144468A655B65CEULL, 0x56545B6F8C5A4C2DULL, 0xCF662AFBF5AD6F72ULL, 0xBBD5644B6A000358ULL, 
            0xFE5254C9856A7646ULL, 0x9E28DAF81BB7A43EULL, 0x1D27EFA11B902AF1ULL, 0x163A76E77A5CECA7ULL
        },
        {
            0x525A8083EBCF9992ULL, 0x2EABE9CCE0D40107ULL, 0x84B531834FDA9FE1ULL, 0x7017995BCA7E7991ULL, 
            0x5363FC57C81883A9ULL, 0x6435E74958120B64ULL, 0x41B8D970B1E23143ULL, 0x23EE9A0B351C08F8ULL, 
            0xC0BF649842E22377ULL, 0x4DF24101C3CFD4E9ULL, 0x472F958C576ADE34ULL, 0xA1AEE0B6AFDFBBD6ULL, 
            0xCF44F3467187B683ULL, 0xB3BC8359336C052DULL, 0xFB4510B215D5E307ULL, 0x39BB7F34204BE9A5ULL, 
            0xDE265ABE4AA940A1ULL, 0x28655E7A980F99F4ULL, 0x7CF39ACC3D171B16ULL, 0xD470B1D1123DD35FULL, 
            0x57682E109AA3931EULL, 0x71B0F0D43AC3217FULL, 0x4B3586A178C12E16ULL, 0xB76928A6BE088B6EULL, 
            0x4E3F1AD6BD55F84BULL, 0x4D9A5C24F72B0CC2ULL, 0x10F9537070A27D47ULL, 0xAF5A0FE59EBF8479ULL, 
            0x302421422C2E55D8ULL, 0xDB1C4A3F812A5938ULL, 0x2356D022789B2428ULL, 0x9A59BCD2375FC521ULL
        },
        {
            0x6768F263EADF143DULL, 0x223F198B6EA57E9AULL, 0x8CD713375129577BULL, 0x77D0D80DBD0B7422ULL, 
            0x0206BBABFE03EE3CULL, 0xE9557224E4925445ULL, 0x4D82FB7779D29561ULL, 0xF250D95600BF2C52ULL, 
            0xC826EFB8A090664DULL, 0xB8CA333B07BF8681ULL, 0xD9F4762D41447A05ULL, 0xF27BD2E2C3FD5329ULL, 
            0x5384921AE9EF5876ULL, 0xBBA5D625695714D1ULL, 0x2B04BD9DC154B408ULL, 0xBA5DC4C6885ABEB9ULL, 
            0xC4567B71D405A03FULL, 0x68494EF5A17EF1A3ULL, 0xDF7F73A4BB777612ULL, 0x27089FE5A27E557CULL, 
            0x95CF82B7F296EBD5ULL, 0x8B307F43818F4F5BULL, 0x6A6BEB85FB8D1877ULL, 0x02B7E7BDBF1BF328ULL, 
            0x5AAD279583AC58E0ULL, 0x78FE5DD8666C0E67ULL, 0xD70054D1725C6D53ULL, 0xE77ABE1956CF3FE0ULL, 
            0x23EBC974476761A8ULL, 0x1C3EEF83BA74D8C2ULL, 0xBCACA0E93333B2E6ULL, 0x9288AD75E57F1F39ULL
        },
        {
            0x109DB70350E72561ULL, 0x97D73D5B6DA33BA8ULL, 0xD977FF03E666257FULL, 0x5D5AE7D9EBFC9646ULL, 
            0x11CB9500B0FC1CEAULL, 0xC7BBD63E3E7CB8BAULL, 0x011E7F5117F51CB1ULL, 0xD7779EEFDADA401BULL, 
            0x16F12E7454AFB9EEULL, 0xCB649E4A461E8C0DULL, 0x0F81B9C6C4FE2D89ULL, 0x1A86F481F2427C35ULL, 
            0xCA015FB54040F262ULL, 0xC0074591EF2AE241ULL, 0xCAD44644A5735425ULL, 0x9B84FBA3132A72F3ULL, 
            0x41F1E5D36C6107A9ULL, 0x96486C597BAD5487ULL, 0xF33727A9CD2FF315ULL, 0xD445A5F792F19B24ULL, 
            0x5204C2ABA3D14EC1ULL, 0x9342AE54782E55B0ULL, 0x292CC5D2138F528EULL, 0x3F40D0F7B40948DAULL, 
            0xF9E815D2864F7911ULL, 0xB2CAE427C6B79170ULL, 0x5FF9823AD21AEC74ULL, 0x5735415086335312ULL, 
            0xE3A2E2C4BB902453ULL, 0xF19539754CE65FF4ULL, 0x7F41317EF7B00098ULL, 0xCAC73DB8A703CF3DULL
        },
        {
            0x8979DBFD8A7494B1ULL, 0x68B41D6113C3753DULL, 0xB7A78B1BD1293ED0ULL, 0x8F776669B60B1164ULL, 
            0xB950E163F8B1F334ULL, 0x4156BD568F15EACCULL, 0x42DDF132AFD6EB1AULL, 0x62A7B5FE90E69063ULL, 
            0xF459AB8D59412D5DULL, 0x6282E1B1769F0EA8ULL, 0xFFD90111DE71E40BULL, 0x2A2946315F0478F5ULL, 
            0x6922CA90A300F8F9ULL, 0x413D2D00DBC1168BULL, 0x2F4195BA37741B1DULL, 0xB7E9781C4B92463CULL, 
            0x0AB9C062A3536862ULL, 0xB0EC3E3747637772ULL, 0x192A6145F5979308ULL, 0x8AFBFA2F8CFD3681ULL, 
            0x08B877A11C39D4FFULL, 0x0F351CC29015879BULL, 0x26007FAA27A261C5ULL, 0xFD888C54EBDAA7A7ULL, 
            0xA082DB710F490BACULL, 0xA5432A06D6F0998EULL, 0x5F00A50866CE0AB9ULL, 0xAA7717F3E47DFB4DULL, 
            0xCE09317704E7FC97ULL, 0x95B347F901920486ULL, 0x1EDC1CAB125B0F3DULL, 0xFAE6F519D6C1A351ULL
        }
    },
    {
        {
            0xB4E35802DCC9D43AULL, 0xBED4E638F498728FULL, 0x741C249278FE8D23ULL, 0x504305A0BD1541FAULL, 
            0x2BF24B1FBF5B1BD0ULL, 0xEDAAA0712C62E4B8ULL, 0x712A693DA0962459ULL, 0x2C474F4A65786CFAULL, 
            0xC060347FCD968E76ULL, 0xDECAE05A8A810ACCULL, 0xF2F4E3A99DE4A278ULL, 0x179F694CF54D36E4ULL, 
            0xC717C3EFEA1E69C4ULL, 0x5E8E3A502B87C8E7ULL, 0xC483E2FF3E91C975ULL, 0xEC61E2A97089A06CULL, 
            0x8B79427C585A829BULL, 0x562F8AF3521DF338ULL, 0x6D788FA807B67958ULL, 0x175AA51E5B87C7FCULL, 
            0xEB7014985399B492ULL, 0x833732D2F895326EULL, 0x52A680ACA32CCE61ULL, 0x45ADF5AFAFD3CE14ULL, 
            0xDE0CAD5200B7541EULL, 0xCB7C46BD49B330DBULL, 0x19EF5308F8B01000ULL, 0xD96D66DF3CC3931DULL, 
            0x13F5BDC16F2AFE0FULL, 0x0B9DB4E0C83F9A7BULL, 0x2A3D5EAA2E790AF4ULL, 0xE56083D95222BF34ULL
        },
        {
            0xD63801EE043A12D8ULL, 0x472B06EB7ED8D050ULL, 0xE92043B662A34CCAULL, 0x50C4045273590DDEULL, 
            0x9FCE06F0C13519D4ULL, 0x75D508DBAD413A67ULL, 0x0638946126FCA30DULL, 0x5A4C1353D061290CULL, 
            0xCFB10FDC9ED6D56BULL, 0x902F36A2B9708C5CULL, 0x9372879F38B8111AULL, 0x93C60231CF4B40F6ULL, 
            0x6AA07E964646DC1AULL, 0x1898F7286A9C884AULL, 0x406AF552CAB33DD5ULL, 0xA4C75075F68F1DD7ULL, 
            0xF6FDB4806D822169ULL, 0x1BC9E08CFAD3AC36ULL, 0xD7143F4CFE8B8B51ULL, 0x6A8DB3A13D6D75E8ULL, 
            0xF87C038B4E990A30ULL, 0x923BF14348145375ULL, 0x6C4FBC8746BDF211ULL, 0xF4CB76ACCD8DE742ULL, 
            0x398BF3A61D4EC859ULL, 0xFE188EACF5F7BB5FULL, 0x00A84E06110AC611ULL, 0xFA5BC4E6D513914CULL, 
            0x7EBCE13FCF7C5754ULL, 0xE04B2D1FD511E7EDULL, 0x5301996D73E19014ULL, 0xD41783847FAC2CE7ULL
        },
        {
            0xA0B64B287AC0DE66ULL, 0xAF4D1F2A28C3CFDBULL, 0xA643EF7866478F72ULL, 0x0664AB5C9B436ACCULL, 
            0x995580A73B33F2B0ULL, 0x2B095429975F0BC3ULL, 0xA74A5A5347E5BD91ULL, 0xD6067977E51A0992ULL, 
            0xAD1AFC3134CC12F2ULL, 0x43C14E5A4862ABA6ULL, 0xD54B8E4E554C6046ULL, 0x2AABC2162528AE56ULL, 
            0x75E1FEA93B445C2FULL, 0x7C63F3BE0AF285E3ULL, 0x57242E0855E0C08DULL, 0x39027375C1616F75ULL, 
            0xF1659DD9A3F4CBE1ULL, 0x3A5C48C57485361BULL, 0x842B27A8C5E3CF63ULL, 0x5D05BF6B1326FEC3ULL, 
            0xCC1D8CBD1D6D1FAEULL, 0xDB5813D2D5C869D2ULL, 0x7DB4013D01235E7FULL, 0x58AF0A5CF38C30F7ULL, 
            0xE7CAA5E7A960210BULL, 0xD7522991BAF92074ULL, 0x5FC226CB7D3DF97FULL, 0x239AC07431919AF5ULL, 
            0xDA2E643A21A52151ULL, 0x526490F75920E1BAULL, 0x1FAD0D469D491B9EULL, 0x837D3CA9FB8DA7B3ULL
        },
        {
            0x374C421C288EC069ULL, 0x0769D7CBB7F30FF0ULL, 0xD204682E49118265ULL, 0xBE61E4F30ADBE9C2ULL, 
            0xB23194FA55CB3C4DULL, 0x2AB68032D3A16C09ULL, 0xDC6052C859ED2F51ULL, 0xD7208CCFEA828A43ULL, 
            0x2DB2B7A7A7EFB115ULL, 0xF1AD5924B0AB0728ULL, 0xC29C56AF0334C2F9ULL, 0xF9FA9E1A579441AEULL, 
            0x13D6CCA5D3345383ULL, 0x0B208084101DC1BEULL, 0xFBA1204F75A9B17BULL, 0xEA8B8FFB21BD3786ULL, 
            0xBAF1452DD74B7D17ULL, 0xD729450ABABA3E4BULL, 0xFDA74683850F25F3ULL, 0x2F5152BC54F582E0ULL, 
            0x82558CE0B900C72EULL, 0x80F32CCD751913DFULL, 0xED627C6CBB1DD174ULL, 0x3FA3E55113DC5AA0ULL, 
            0x8E2555E5599150F1ULL, 0x3A5E10AE43688300ULL, 0xB97DC5263CD8E1A6ULL, 0xAFF64B0D35EEA485ULL, 
            0xC7958BF12F72C6D4ULL, 0x6E1E0DF8ECC45A70ULL, 0x51F41E9482157172ULL, 0xF377251D4DA02A62ULL
        },
        {
            0xEDB63F4D94598C87ULL, 0x01740F1F7F131AC3ULL, 0xE518793E883290DBULL, 0x8A88BAC8B107C133ULL, 
            0x55C5696DF9CD84A2ULL, 0x94618F0A8E9E91A5ULL, 0xBC05D981031BD959ULL, 0xFEBDA21D11781DEBULL, 
            0x4DA52F3FF655A706ULL, 0x5CD3503176920BB1ULL, 0x4DA3E3AA51E6EB61ULL, 0x2B7FEFC29E682FE6ULL, 
            0x6EE7C4555C7CB9B7ULL, 0xDC94FDF708921C59ULL, 0xE15906DE28859672ULL, 0x64EBC54D3F6A80FCULL, 
            0x094862CFE0B9E788ULL, 0x31DE46CF85BF7B38ULL, 0x859D23CF9BB20D34ULL, 0x713977A9167D9342ULL, 
            0x212A316B8D864CB5ULL, 0x0BBA0C021B694417ULL, 0xFB0B0BBF7E6D4B89ULL, 0xB43AF91CCB7EBF65ULL, 
            0xE055B2CC22DAB171ULL, 0xE4DC3750D53BF3F0ULL, 0x6DB46C12878AD105ULL, 0xA316B028E975A70CULL, 
            0x933B93553C66E373ULL, 0xC84833027157F0C2ULL, 0x7CAE243C5CC9A3C1ULL, 0xC09919363AD27E5FULL
        },
        {
            0xCFB2BA12B09F485DULL, 0x39F6ED6B2AE7945DULL, 0x6942F7D21E0A9BE2ULL, 0x215D6E6C29628BF3ULL, 
            0xDB8D3F42616CD3F1ULL, 0xA3E3A63F8DDF64D0ULL, 0xA33F5282A5BEB33BULL, 0x79EECF3FAF8C6EB7ULL, 
            0x14F46918B3DC8BFCULL, 0x29FCD3AFE8972F1BULL, 0x358C93600E807665ULL, 0x62D459CE8C7B3877ULL, 
            0x9B1640C7AF7D9443ULL, 0x45A78C19F4E2316EULL, 0xBFE53E9F97280804ULL, 0xCDB9D3CF6A3B066DULL, 
            0xF6CEC0AF4C216289ULL, 0x135A4A9317AA2EB1ULL, 0x3F1F0062BA746221ULL, 0x1C433DCFC8B4C3FCULL, 
            0xD77D00D3B4E4BC23ULL, 0x26157918CE6E5E30ULL, 0x6009E02E5AD0538DULL, 0xD0DCA0FC5D9BFD05ULL, 
            0x3A131FC56BF7CF4DULL, 0x983A94609F30F680ULL, 0xE126F163D9C42397ULL, 0xC7C769F8AD13534BULL, 
            0x4070E46EAFE2E3A7ULL, 0xAB08C8C32DDDF9E8ULL, 0xE99CC7C3C3661D35ULL, 0xB4A527385C5F9B67ULL
        }
    },
    {
        {
            0x5B2DE68FA74EF6E8ULL, 0x17E2A9C075572F46ULL, 0xC9E2E49943B370EAULL, 0x233658976C5816F3ULL, 
            0xAD46330A2E813C6AULL, 0xB9836A20EE317BD2ULL, 0x90CF9F8734A01573ULL, 0x8548007B65FF626EULL, 
            0xA725B1295CF70F07ULL, 0xE085C05FED98B568ULL, 0xE5E1CB2DAAF7403EULL, 0x41B9B519F8CDDC1CULL, 
            0xA29887CADA96CE4DULL, 0x80B88B9C62B0DCE0ULL, 0xFD0A9DFED54BBE54ULL, 0xF530D72332796E7BULL, 
            0x74CF274B4C0CACD3ULL, 0x05DE78183263B01FULL, 0x4172A398390D4D75ULL, 0x559B9D40B0244EBEULL, 
            0x4B27373D7A4ED4E4ULL, 0x1B850B2E9F546FA0ULL, 0x96EBB10DC11E4999ULL, 0x491D2DF6FE64E64DULL, 
            0xB4077750BA66E60DULL, 0xD5D7440FB1758F5EULL, 0x703722E015F2B2BBULL, 0x331A891FA73A8700ULL, 
            0xC9B315F96FC34A90ULL, 0xEBD62AF70615BD2CULL, 0xE3AD51515EAEE88EULL, 0x5FFE96EBA28A877FULL
        },
        {
            0xCDE9AE164955262FULL, 0x446CA6915C44DC84ULL, 0x3A222D1F81AD39B2ULL, 0xA4FF768A3E1027E2ULL, 
            0x68463C8BBF804CFAULL, 0xE18A41E70AC04459ULL, 0x34F9BF81A6C8EA85ULL, 0x9E07B1DF9CFB5DE3ULL, 
            0xE4455C17A966F1E8ULL, 0xC31D9355933A966AULL, 0x61E1A428894A18E1ULL, 0x1DFE84A250320DDFULL, 
            0x8EB4A2BA93D97D95ULL, 0x9F767DEAE4AC5398ULL, 0xAB2E5BA58007972DULL, 0x6C931C8C8D9A0A50ULL, 
            0x8B8AF0FB87DEDE22ULL, 0xD113FCFA52A9CF0FULL, 0x9B5715EEA73CF0B9ULL, 0x8AC4313DDAE2F322ULL, 
            0x708F11F7DBADF90EULL, 0x2FC8329A5408B23DULL, 0x652A2449D9A7A832ULL, 0x798EFB88696FAD8CULL, 
            0x8C82B7E0C189FE4CULL, 0xBBB936B6C6F2AFDCULL, 0x149B2837F8B94C7CULL, 0xF6EF94322ABBF4C7ULL, 
            0x6CC86A26A982AF69ULL, 0xA1653A76569BB1CBULL, 0xB3B3BE42D394405EULL, 0x84EB28898A91BDF7ULL
        },
        {
            0x6215AE23525D047FULL, 0x4BB94D198A834AA4ULL, 0xB46F98A28EEC1430ULL, 0xA92182022A0F4370ULL, 
            0x84905C3515E76FACULL, 0xA085FE53206EE58FULL, 0x338B7DE0537A7D9AULL, 0xFE346C1192CB32BEULL, 
            0xC3A38A8A5210AC50ULL, 0x26CC0A5738F25ACCULL, 0xFE1162728265EF72ULL, 0xF7F34EC96490CBD4ULL, 
            0x127FD91557241EC7ULL, 0x3010FC98FE6A5B33ULL, 0xD352ECF680A9FDD7ULL, 0xBBAA67032B3CD627ULL, 
            0x4FD8497EB248DAB9ULL, 0x5FC3F32188B25BB6ULL, 0x667BB9CE9FA5DD21ULL, 0x108E486837810EBEULL, 
            0x115F3AE4B5523C3BULL, 0x1A263E55192DF728ULL, 0xA5786382EB97FFCEULL, 0x3ABB550203E0F887ULL, 
            0xA4E53B1CE1525628ULL, 0xB48B1AED3A3E61ABULL, 0xA2BB1D312B726AD0ULL, 0xFA65C7B71FE9FEB9ULL, 
            0x1C67A54C8D401011ULL, 0x0FE2CF417344DA84ULL, 0xC1F5E6EA75B06596ULL, 0x9BC3EF36283B00CCULL
        },
        {
            0x6D59E5D0489E62B2ULL, 0xBF73CFFAA24E1C94ULL, 0x6BFE82CC9A910275ULL, 0x4FFF12873B850769ULL, 
            0xA19063F47D9436C8ULL, 0x2257DDC4F4C21B90ULL, 0xC961135A87E3C3FBULL, 0x3BDC26AB0FAA8C89ULL, 
            0x01DB1EDA5CBEFF7AULL, 0xAF0DAC6085A6CCC6ULL, 0x82455AE202DC0626ULL, 0x552A3394463B382EULL, 
            0x1016CB1A4C012797ULL, 0x43464EBB2DD96227ULL, 0x3F6F2070429DA2B1ULL, 0x3BDBABB712C87D17ULL, 
            0xD4D12D815099CFA2ULL, 0x81A096AF0E828EE6ULL, 0xA25B827877C19A5FULL, 0x6391ACB25F06C995ULL, 
            0x96DEC86EEB6B95DAULL, 0x8EB1E569E34FCAFEULL, 0x38E199C650F2B747ULL, 0x42BCAFFAA092368FULL, 
            0x39A9EE6709D70A96ULL, 0x1A4F1C0045D7C71FULL, 0x8F270198B6D4822BULL, 0x122A3BACFADD72D4ULL, 
            0x39B111EDBCBD43A9ULL, 0x26CFB058BD5E1E9EULL, 0xBCA61464C9A1BB9FULL, 0xF51C8BE6C0C7927FULL
        },
        {
            0x485E02DD67FA42A8ULL, 0x6DDBDAF28414FE57ULL, 0xE9C63ABE3A080C78ULL, 0x822977B2C2C9490CULL, 
            0xCE9775624647112FULL, 0x49C0E447E2518E84ULL, 0x13A27B392B42A1D4ULL, 0xD7372707E7A26090ULL, 
            0x9EB3422E8CCD1C4DULL, 0x0222233E85B431CAULL, 0x8B2202AA0D82F581ULL, 0xCC8EEB286A0A711EULL, 
            0xFB73AAA7C4250F3CULL, 0x454D2C959F0EB979ULL, 0xD1F1AB2AA54B0722ULL, 0x24DA78FF511EF630ULL, 
            0x7EAD6B6F90C089F4ULL, 0xB2527514F8964B8AULL, 0x3F12C504BF74A1B2ULL, 0x0232F9C1DC744296ULL, 
            0x60FF540D0CFFAB5DULL, 0xEFDD9EBCA4023AFDULL, 0x0EF2F8D057F37B40ULL, 0x55D9FC5E34AC1809ULL, 
            0xBE169E61E9AE9DB8ULL, 0x5D1FC4DB0B06C5FFULL, 0x47899974FA41BE6DULL, 0xF8EED844D1CEB64AULL, 
            0xC8C94F4E210D51F1ULL, 0xF0BBDF450A6800E9ULL, 0xE8604CFCFEDA8040ULL, 0x4FAF13E7B45FEF1AULL
        },
        {
            0xC5F4E96D8F640743ULL, 0x29211C13D5572AEAULL, 0xF4C980888F7D77FEULL, 0x8A22FD3A95CE4800ULL, 
            0x8ED441BC229C842CULL, 0x6551B06A9222C5FEULL, 0xA45E53A3AE1DCDE7ULL, 0xDFDA4520F2FDD60DULL, 
            0xA7B7D430F703BE09ULL, 0xB78DCE6EF019DF78ULL, 0x5E36D53732CC441FULL, 0x2DE0043A03FF2A86ULL, 
            0x47DEB6B8C75CD9B0ULL, 0x809F78C020CA3077ULL, 0xCF85180675E55B16ULL, 0x2023CB6669EFBF34ULL, 
            0x2AA24DBE5CCA37D7ULL, 0xB55C2EAF781316FCULL, 0x24548E2C03C91576ULL, 0x7336391A37713A81ULL, 
            0xA404086E98E15167ULL, 0xCEDF92F8C13FF1ADULL, 0x1C330B19D82048D7ULL, 0x0B172E5340EFAD20ULL, 
            0xDA0AC0B557E770C0ULL, 0x47E6924A70EB5CA9ULL, 0x2B28EBDABAB5D22EULL, 0xC6820310E869391FULL, 
            0x66F4001CC55D4EA1ULL, 0xE5F58F751140D21AULL, 0xC4CBF962750DD89EULL, 0x9F813DF718839DD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeyRotateAConstants = {
    0x60ABCE8164EA3DE1ULL,
    0x3F5955B8C4729C9FULL,
    0x0898834D73355792ULL,
    0x60ABCE8164EA3DE1ULL,
    0x3F5955B8C4729C9FULL,
    0x0898834D73355792ULL,
    0x3EBD0C047C6A61F2ULL,
    0x9A9361C7D00FE4C5ULL,
    0x48,
    0x5B,
    0xBF,
    0x73,
    0xA1,
    0x42,
    0x83,
    0x9A
};

const TwistDomainSaltSet TwistExpander_Mothallah::kKeyRotateBSalts = {
    {
        {
            0xE05E398ADF304A63ULL, 0x836881B29908D9CEULL, 0x63DFBCAF6CBF97DDULL, 0xB6AFF7ABFA6279AAULL, 
            0x9133666748FCC305ULL, 0x4C9307951F25DF17ULL, 0x1A1D4A1ED61B14D1ULL, 0xE0779A1D9975883AULL, 
            0x233EF79E5A1C77E2ULL, 0xAF6F753A84AB8158ULL, 0x9AB2194040E90F79ULL, 0x0F1720F53CC97427ULL, 
            0x23AD1575FD775237ULL, 0x0985BAF7819E86ECULL, 0x5C00C08242602F80ULL, 0xC2653303222CF8A4ULL, 
            0xC624136A762B844DULL, 0x42391ACBC5419E2BULL, 0xBBA30801B9F879A5ULL, 0x438D21D7128BD3ADULL, 
            0x1BE8C71DAFEBF9ADULL, 0xB16D2D071A52E6AAULL, 0xC5DC8556807F1914ULL, 0x29B4860F112F814AULL, 
            0x3055530F0474006EULL, 0xB0C36AC69EAF6538ULL, 0xDA7B65F553D52A55ULL, 0x5F1AB393ED7F2459ULL, 
            0x486ADC8A887C4D9CULL, 0x0E4D56453E5A95F4ULL, 0x98C7F36453BBA946ULL, 0xF0AA81C56AB893CBULL
        },
        {
            0xAE156794CECB1835ULL, 0xB09EE619A0926C13ULL, 0x5C5E350D56467F0FULL, 0x1EC5DC835A163FC8ULL, 
            0x78AD9157818731E3ULL, 0xBE052EC8F9C31066ULL, 0x614446AAAD6AF5FEULL, 0x65173D64CDB5489EULL, 
            0x6E2C40EB2AB94478ULL, 0x715E89CFA871800BULL, 0x7E62DB0D68EAB69CULL, 0xB400B3A304B031D1ULL, 
            0xE8197675E2FEAAE7ULL, 0xA6458196387747F0ULL, 0x64DA4D88DAD87790ULL, 0xABB85AD6F7DD436BULL, 
            0x0A5E27A2CA669F7EULL, 0x594C10E825C1899AULL, 0xA3DD9421AC24CA60ULL, 0x86A87A048AABFAB8ULL, 
            0x40D19FC185241291ULL, 0xDFE977D6CF4058DCULL, 0xC6F7BE90CFFDD61BULL, 0x99E74186CD492F93ULL, 
            0x6BE89DEBDD0DC3BBULL, 0xD47F31B5CCBD7869ULL, 0x4B553E02498DE521ULL, 0x6D1E24B5ECD116E8ULL, 
            0xF8F83EF99773F99BULL, 0xFE4DB5BAB73E5B47ULL, 0xC7E6D89C8C550EA8ULL, 0x53E89241DA1623FAULL
        },
        {
            0xE9410D336F6B606AULL, 0x0E8EDAB863CCEB58ULL, 0xD944140C6C2EEFDBULL, 0x7D7B25803C0765C8ULL, 
            0xC4E28F0F975292F7ULL, 0x20D8050A303C8663ULL, 0x54EB4CDA54C0151CULL, 0x7130EF55B809115AULL, 
            0xD87C3D4650DC3F39ULL, 0x36181739CF68E661ULL, 0xFD513F2C801284D1ULL, 0x5F3589171D2E1DEEULL, 
            0x48111DC8A89D486EULL, 0x0946D8CCF1A262B8ULL, 0x140ECBC56BB9BD65ULL, 0x684F87C6C072D598ULL, 
            0xDA5FDF1867FEE81FULL, 0x890C61159AAE857CULL, 0x6A906A649E0F9F93ULL, 0xBC9F861FC7B083DBULL, 
            0x0577C215C5D6B418ULL, 0x9352A4FE7F3F5D78ULL, 0x424B2E1913FDC477ULL, 0xCF296A1E92C393BEULL, 
            0x55EA82B6879D843CULL, 0x15E08D352F38A822ULL, 0xD431101A019B33EAULL, 0x06FACAB885C15C88ULL, 
            0x12CB5A78B944F60FULL, 0x680D55864C84229BULL, 0xCF5FF52AA2DF4DEDULL, 0x68EC244DDE93AB1BULL
        },
        {
            0xD799FE18EEC19B23ULL, 0x612A250712E921F4ULL, 0xB43A0A41729650CBULL, 0xE2E3E3260F30A526ULL, 
            0x6725E3752E03BF37ULL, 0xAA9B89154CCDC1C3ULL, 0x8FB1BB39F933B833ULL, 0x40A396AF95EB7B1BULL, 
            0x4D60F523BEDEF1D1ULL, 0x61AF7D35474B5FFFULL, 0xA0738D000370DA60ULL, 0xC095D1B572ADD3A2ULL, 
            0xB282457C10EB85A3ULL, 0xB0EDBA7FE38FE06CULL, 0x275F09FD0C6E1039ULL, 0x34393DE2F3E2C774ULL, 
            0xA81ACA10BC63D7ACULL, 0xBD2628F82A0F8B6BULL, 0x9B38C6AF491D4929ULL, 0x0A040BD2720E53B9ULL, 
            0x7B35A613F8C760A8ULL, 0xE1F80F781BE84755ULL, 0x32CE793811293D5CULL, 0x702DF531CCB3E766ULL, 
            0x25058168EACFBBD2ULL, 0x952BF8E0214F9FD4ULL, 0x7C3EF94F1DD70875ULL, 0xDC6E43AEE3E2A45CULL, 
            0xE69ED51B90E20EABULL, 0x0D00F41CA83D0D18ULL, 0xC965420A291DE906ULL, 0x2A5B0B215F234947ULL
        },
        {
            0x31BAAC8D8B6CCE12ULL, 0x0B4541C96778DC90ULL, 0x54E61F55509F5E83ULL, 0x4356159211438ACCULL, 
            0xD1620C7435E4C168ULL, 0x25D2B57B2EBD13BEULL, 0x6B3F7298AB5FA9CEULL, 0x882C5D0DAC84C6EBULL, 
            0x515049B654D9B938ULL, 0x8A46C106930959A7ULL, 0x1B27F04E37364B27ULL, 0x316384CB6F9F5B8EULL, 
            0x3041B6F27049F838ULL, 0x9E9D7FD22EFEA4D7ULL, 0x14FB561D887BBFF0ULL, 0xD8F4FC0A865237A9ULL, 
            0x8F6688C7046D3DF7ULL, 0x691E0DDE96DC24E9ULL, 0x267273B1475EFA51ULL, 0xB1861F7C6DBAB4BEULL, 
            0x045DD459C73D654BULL, 0xAD960C3C8E786818ULL, 0x9632B34B51A90302ULL, 0x474A840C1B3BCC5EULL, 
            0xC6548BFC2B7C17E5ULL, 0x96987463C7105C52ULL, 0x51D42B1AD90EF81FULL, 0x8C2409555A29B0FCULL, 
            0x7E582AAFB3B429F4ULL, 0xAA5116E3A2EA08B5ULL, 0x302B34560232A56AULL, 0x0559F4B7B5943FB5ULL
        },
        {
            0x1FF43424EB8FFE19ULL, 0xF7F6A41036BCBA07ULL, 0xAC5536020E173FC5ULL, 0xBAEBEC9059C254CAULL, 
            0xAB65A1594726ED01ULL, 0x529B0ECBC25D5B80ULL, 0xA78319921EEF0EC6ULL, 0x1EDB72965B45438EULL, 
            0x274E65D5C0AE2D2EULL, 0x5848355ACDB3DBE4ULL, 0x0EC662E60C02BC49ULL, 0x8599056D8B302730ULL, 
            0x020EC0A1AF6DB48FULL, 0x1FFB8C3D0FC5A5F0ULL, 0xEC54A9D5FA33EAFFULL, 0x58427779C731AFE5ULL, 
            0x879A5430815D4653ULL, 0xCB87F3D08051B3C7ULL, 0x8568C166807C71A1ULL, 0xEDB14EE35A1FC027ULL, 
            0xAF21EF89330A4BAEULL, 0xE84BEAE0F560FB60ULL, 0xEC424CC970698F4FULL, 0x301DBC5042522CB9ULL, 
            0xA1925252904C8AB6ULL, 0x356ED71D527D45E2ULL, 0x564131AE925341B5ULL, 0x6FA60FEF3C624325ULL, 
            0xF89F945B6C36D8BCULL, 0x6B7E6A687D710CBAULL, 0xF706088B8AFDFE78ULL, 0xB6FACCB6CABB3C4FULL
        }
    },
    {
        {
            0x7B3EC86F79B43A0AULL, 0x52CAACD0FB902252ULL, 0x5E622BB85F03ADA3ULL, 0x98DD79964F2485E5ULL, 
            0x6BC0FD9E53E3E6FCULL, 0x836DDEB5FCC103C1ULL, 0x5E12EF38DE5B9445ULL, 0x10548308939F5112ULL, 
            0x864B01FBE7854AEDULL, 0x3AB660CED71CABD0ULL, 0x4D3EE144B9D41101ULL, 0xDC664841A9FDC4A4ULL, 
            0x6646C3AF815D8FCAULL, 0xB9E38545E084F4A3ULL, 0xAD0282E736601D84ULL, 0x8FECAFDFD9A5E688ULL, 
            0x69AA5B3962D600ADULL, 0x566DA5A4C9B325C0ULL, 0x363D6457164517F0ULL, 0xBB0E474CE06E4E0FULL, 
            0x0DB60331EA495C12ULL, 0xD5E70BBDA32DFF09ULL, 0xE531833C6647F5EFULL, 0x69FBA8C932253B54ULL, 
            0xC80E1016FD966A93ULL, 0x21D2406CBBCA1723ULL, 0xE8323C72E1D28AEBULL, 0xB17C7C1D6578808EULL, 
            0xA1FF78CADCB94873ULL, 0x0773753EF7089B82ULL, 0x0031717D5C62B2FCULL, 0xDE124711313A0A5FULL
        },
        {
            0x57716617886455ABULL, 0x3D3220CC180CC38EULL, 0x06B3039EBC3B5B13ULL, 0x3CBF8609DF974E47ULL, 
            0xD6EB269084424885ULL, 0x89B47CD880F9796EULL, 0xAA268457D247E745ULL, 0x6F2828F3D1312BB9ULL, 
            0x06E028B6EC86D11FULL, 0xFFE688D11B1222F0ULL, 0x3CC37B20A12659BDULL, 0xB854CE0BE218AFEEULL, 
            0x5EA567ACE82731EEULL, 0x315930588225F25AULL, 0x9D811E77DEB7E9A5ULL, 0xF417E6814EE7554FULL, 
            0xCBA2B5D46A8B9CE9ULL, 0xFA4F902C28A485A0ULL, 0xB3F4344B84EB44FFULL, 0x8375838F4B1AEC1CULL, 
            0x3DFC615B2FCD9922ULL, 0x8B14FF66E4B493FDULL, 0x46B42E01B6E76FE9ULL, 0xA20C71135B61E5D6ULL, 
            0xF7830C5BE29856DFULL, 0x10C0F0B0112FBD38ULL, 0xDA9149EF68F6CD44ULL, 0xA8F21D31F9B32C1CULL, 
            0xD9EA0D0426A50BAFULL, 0x959362B8F0C4AE25ULL, 0x36F3189ACBBDDD44ULL, 0xCAF9FCFD9310ED22ULL
        },
        {
            0x9F9720113844A6C2ULL, 0x338256545A6EB2BEULL, 0xFE5266B001CCFED6ULL, 0x31912C209370CB8EULL, 
            0x8EB3BB72E912780EULL, 0xDA030FBA827E7A83ULL, 0x2B7E464F91AE834CULL, 0x6151CE90D32037D0ULL, 
            0x545F7E550EDAC16AULL, 0xAD0E7B3F0620F615ULL, 0xD21E81178E448D00ULL, 0x8838561632175F30ULL, 
            0x6E04626F61D94764ULL, 0xCAD5490359C6B045ULL, 0xE35D3910E49F0895ULL, 0x899EBE8D4D1E30E0ULL, 
            0x3ECD170A45A43825ULL, 0x386C3E0DA2EF7567ULL, 0x0C545722A3C404AAULL, 0xB3A04C38698DD232ULL, 
            0x486657D805C13A49ULL, 0xAF1D358B5ABD5F4AULL, 0x6D4C058052A327DFULL, 0xC1CD23C1C756D4C5ULL, 
            0x0C588B34B0A4589CULL, 0xC9560966AED414E2ULL, 0x72B60A1F187B124AULL, 0xC56EBCE8199BD62DULL, 
            0x1C3A846E008CD9E4ULL, 0x6ACA21F3093E47E0ULL, 0x8313FB233BEC8897ULL, 0x388551A2ADF494F3ULL
        },
        {
            0x7A9A030FA6837FDFULL, 0xAF254ADE9852A5F4ULL, 0xDD5BBC4A0FADCD90ULL, 0x08A0976958F8CB3BULL, 
            0xF2AAB452522B7243ULL, 0x8A88BD4C64800783ULL, 0xDA8F21F8DF9839FEULL, 0x2666FCEBBCC4283AULL, 
            0xB80AE3DFC27A70F0ULL, 0xFBCAFB2E06BFCA24ULL, 0x44909CB7C7EA0EF6ULL, 0xC165015B78BB1D03ULL, 
            0xB9B2B2B20CBE8C91ULL, 0x8B8343FE13B80AD4ULL, 0x959CDBB79C28C3EEULL, 0x92871E2FDBFF3044ULL, 
            0xAE0917B828175832ULL, 0x030E862E4B656A4BULL, 0x0C874375BBFFE3DEULL, 0x5DD72256072F2900ULL, 
            0x808CF3E979B69758ULL, 0x6278FF6768007C34ULL, 0x54BD657CBDDC7C9FULL, 0x3112C58871677E7EULL, 
            0xF46517545257D131ULL, 0x8FF427508A7B9439ULL, 0x6ABFDB0DC69DB397ULL, 0x3DABB6B73BCB5B07ULL, 
            0x2564A2E80E11E6C7ULL, 0x1D591DDEAA4EE156ULL, 0xAC7F60448FDF7664ULL, 0x3A2A118EF1CF61B4ULL
        },
        {
            0xF34DD26BC119C390ULL, 0x34210436B728F17FULL, 0xCE3F13F00935E164ULL, 0x74BCA0DDC2D776DBULL, 
            0x60E810AF7CC3B6ADULL, 0xAA90634FF734D97DULL, 0xFDD037B69B9E6AADULL, 0xB595D85DFCF80650ULL, 
            0x5B4F2DA5900B8272ULL, 0x0294BC98CA32CD0DULL, 0xD3EEC70B52370B26ULL, 0xF469FCEEDF7FE728ULL, 
            0x5329475529A8287EULL, 0xE8A3095CBE089D7DULL, 0x4F40FD543A635D39ULL, 0x187A69D14B96A011ULL, 
            0xB5DAE4CB96395E74ULL, 0x6AD648ECE66BEC6EULL, 0x2682A284016BC17CULL, 0xAE7B065AFAA19960ULL, 
            0x0793AB15F5A9E89AULL, 0x32D8009C5E7583E8ULL, 0x48B64F920C44C51BULL, 0x31BA66CCFE34C549ULL, 
            0x70EB2DBF5FFFF9E2ULL, 0x31A132E1DC92EC1DULL, 0x6D7A526F1F591CACULL, 0xABE05953953B31DCULL, 
            0x2E17FB953628F3BFULL, 0x966A9843617E75FCULL, 0xB47BF8BE4BCDCC12ULL, 0xCB3F764D5FA4119FULL
        },
        {
            0xB1A0566C7A4A5D9AULL, 0xE24509181394EFE0ULL, 0x21B4BCF766D86010ULL, 0x54E5F5453F167E94ULL, 
            0x93ADC4B420696AA8ULL, 0x873B75CCE60327FFULL, 0xA34963006E7A998EULL, 0xA51440453D6E3A72ULL, 
            0x45E3B62089153879ULL, 0x80DCEF5B78DDA613ULL, 0x07753AB80625C60BULL, 0xB13319DB8A33FD38ULL, 
            0xE88ACB9FAE118334ULL, 0x60935AD4102731D1ULL, 0xDD2D81269714BFCEULL, 0x47DDD405AC2A072BULL, 
            0x96620E52F5126F85ULL, 0xB72023FD7FFDC2E7ULL, 0xFCEA33780BDD4D86ULL, 0x401C6161FBA59DFEULL, 
            0x9E5DA84772826870ULL, 0x76F2B07FA3FFF1AFULL, 0xC89E9C71E19843A7ULL, 0xA05B3B1D2558E4C7ULL, 
            0x00012A8A4AF135CFULL, 0x9FD97588E709C90FULL, 0x1A917C0C1D89C4B8ULL, 0x383F4DAA50E4CB22ULL, 
            0x12E9CD68E0014E4CULL, 0xB8E39B7F211C785DULL, 0x553184A0A30F5A8AULL, 0x33B79E8E6202DB94ULL
        }
    },
    {
        {
            0xF8198FEC89A18981ULL, 0x4EAD615BE01AC786ULL, 0x5769B53B318BF3EDULL, 0x4C769ACAD381A23BULL, 
            0x74D08A5C1FBCC878ULL, 0x60D3C888A6BB8371ULL, 0x0D0AF76314FE2A81ULL, 0x792968AC13F0F2AFULL, 
            0x785382C01705E2EEULL, 0xB3E68243D47A8ECDULL, 0x33F652E40D91DCA0ULL, 0x65017DF2BDC86487ULL, 
            0x22DB851367FAD024ULL, 0xB5C13960A356AD5DULL, 0x6AD9D4AD1A097927ULL, 0x56402954E33A040EULL, 
            0x68236ADC74578975ULL, 0x800CA9D10DBAF82DULL, 0xD99E64A50EED146FULL, 0xA0EF93393FD1D8A3ULL, 
            0x1D2F3A9670FBC2B4ULL, 0x7FCC0733556B4410ULL, 0x91FDC2B0FE3D0359ULL, 0xBCDB68F958900810ULL, 
            0x593A5A3E3C36F807ULL, 0x97FF498B092F472AULL, 0xD1E29D622EEFC8A9ULL, 0x78E4F068D7D3FB56ULL, 
            0xB1F662FFFBFEA42FULL, 0xE04F5B6288B5356EULL, 0x0753866620F2FC0EULL, 0xE0A0D37C627A82A8ULL
        },
        {
            0x697E81CF1C42FA4BULL, 0xD7588F0A6F409EA4ULL, 0xDA31BFA8CB734338ULL, 0x1739FDA5B2A09C81ULL, 
            0xFFE2A2845CDECB7AULL, 0xD20E02DA4E311119ULL, 0x60243595828D9AEBULL, 0x45EDA78E74E0910BULL, 
            0xBE9F322A13B767EFULL, 0x6188A8613D74225EULL, 0x2E73D92C572F0E23ULL, 0x175FCF90EB62E8BBULL, 
            0xC4EDD9DDDA9890C1ULL, 0x2C76FF0C19FA8D41ULL, 0xCE363600AD53932CULL, 0xBA75B444CCF4B61FULL, 
            0x0EF32652577AB29FULL, 0x4544DEF08D767659ULL, 0x64D3BC043414414EULL, 0x958476EF68DA76DCULL, 
            0x17573F4F332B908CULL, 0x5B12701264E6C310ULL, 0x1EF05B0A979B2722ULL, 0x28FA044CEDD5D76EULL, 
            0xF326921BD5C9F8FFULL, 0x35242571A8CFE4B0ULL, 0xEA03E360EE583B1AULL, 0xDBF8F3C47D3AF0F5ULL, 
            0x57A2256577A672EAULL, 0xBCDCB845E749BD98ULL, 0x1C47CA9B1B932613ULL, 0x0C6002E40E7CC081ULL
        },
        {
            0x5689E7B46223B834ULL, 0x52F0AB9FFEA650A0ULL, 0x8367917F7385AA2DULL, 0xB7600A4D354F8F9BULL, 
            0x7AC795C808134B65ULL, 0xEAF0A5EA463FE25CULL, 0x298348339011143AULL, 0x8140F2F3D99F3165ULL, 
            0xBDF6523B1EA36ED0ULL, 0x3296D0ABB908DD5AULL, 0xF816064B108ACBC8ULL, 0xAF9D81508C8BB215ULL, 
            0x81F3A699505B9AAAULL, 0x94B7FE521A2CBF29ULL, 0x37AD6743F03E20A8ULL, 0x576B90353E4AD0A1ULL, 
            0x0B422540B36D0D90ULL, 0x16D4069651AEF868ULL, 0x058F9DCE1B292C54ULL, 0x209A25A783E5CE41ULL, 
            0xF86D341C62CA1B0CULL, 0x76DE173E1F39646FULL, 0xF21DDEAA12E5D69AULL, 0xA3677AD3EAF60F85ULL, 
            0xEBBF82E5F4D18FA1ULL, 0x19471A75411F39F7ULL, 0xDBD6B6F1813F724CULL, 0xA2C89A3787C6BA0FULL, 
            0xCA9D449BF223A56BULL, 0x77A0E927AB4F7509ULL, 0xC7F840B467B11157ULL, 0x6C48A27DBCE47342ULL
        },
        {
            0x5E04BBE981EF537FULL, 0xE5D2995270A89ED4ULL, 0x5701867F1BE142CDULL, 0x1D062A58FF9F5389ULL, 
            0xD606B353B43700FFULL, 0x770A9F739F9FFAD5ULL, 0x174465348FB80819ULL, 0x6B8A9B00CD2FEC36ULL, 
            0x2491147C1F313591ULL, 0x3E5D0AA0B2B419E8ULL, 0x3F2C33C627265CDCULL, 0x7193CD37790DD1F0ULL, 
            0x61A336A859033A1EULL, 0x018CA9725F93289EULL, 0xAFACC73C12A6629EULL, 0x73CB413A41AEEBF9ULL, 
            0xA063B538CB370C3EULL, 0x52DA8F8138F58270ULL, 0xBD5FAF8480FB8E1AULL, 0xE137DA00E862D22AULL, 
            0x4A11770FA8FBEC1BULL, 0x683E0BF3B33CD277ULL, 0x8B0EAD702BE0D6A4ULL, 0x928F3628878E9448ULL, 
            0xAF43BC3C3393FA56ULL, 0x6EF7D0ACC3296FACULL, 0x6EADF799580909BDULL, 0x1CD89F5E3209BBFDULL, 
            0x66336DD189773086ULL, 0xFB4A299D8E261EF5ULL, 0x570C0FE95B9C8569ULL, 0x1B2962A02237A58CULL
        },
        {
            0x68AFD31B8DCB7501ULL, 0x4CA44467E30E2EABULL, 0xA074FB94A5722A2DULL, 0xC65A763F0331D98BULL, 
            0xD06923B2DFA358BFULL, 0x69F199FC749984A7ULL, 0xDA1681D4FE4FAC50ULL, 0x102390BAB0775DD3ULL, 
            0xBCFF98320FEDF203ULL, 0x316310E27B0E73AEULL, 0xB6DB4E58F56E3B02ULL, 0x7E2E96B597DF0BB3ULL, 
            0xD3C421016943D67EULL, 0xCB31A872EBCB4EC4ULL, 0x6630E1D3C75A3EDBULL, 0x555234E1A39F7F51ULL, 
            0x6A0B7E274577F33FULL, 0x93C9F8368EE2E041ULL, 0xA2182785ADF975ACULL, 0xA842FF2DFB5006F1ULL, 
            0x9689513527F72D9BULL, 0x947DDE6C588D5813ULL, 0xAD717626B9814C72ULL, 0x8ADA371D6800C978ULL, 
            0x0FCFA41DDE2D097CULL, 0x2CF39A31335E752EULL, 0xBD2D3610D2F690B9ULL, 0xE0A5FA4FCCAF54E8ULL, 
            0x95C9DEE804C6C566ULL, 0xB9B7C3C435545746ULL, 0xDE1009C8C7732B35ULL, 0xB004AC3AADE4A8C2ULL
        },
        {
            0x540FD3E4AF35A6F7ULL, 0x7D727902CCC628FEULL, 0xDCD8E84FE3445E78ULL, 0xFC9C7F96946843BEULL, 
            0x1D17E5E360B31D94ULL, 0xCE8BFDC2DBAE8A00ULL, 0x6D06F0BEFF1CF465ULL, 0x461795250F9E7F85ULL, 
            0x43D8A4A908A5BB2CULL, 0xE0AD939A8A10F1B8ULL, 0x19FCAE96844490CEULL, 0x96688168DA722D53ULL, 
            0x77BE3A21F90787E4ULL, 0x6DAC853128B9D2E0ULL, 0x609DC41BEF273E63ULL, 0xDF91D359D7AD7AF5ULL, 
            0xEB85D4569D5BC02CULL, 0x51EFEE4CC2BFA2E4ULL, 0xB4E8004AB0077B5FULL, 0xD324078A294D0631ULL, 
            0x7DAD4D45BFA25170ULL, 0xF4306B4CF23F9CABULL, 0x61268E774923B02DULL, 0x3501963162711A15ULL, 
            0xA55E80900041DA67ULL, 0x5733906252160FB9ULL, 0x0E883514661DDDB6ULL, 0xF371CCF5F4FC5CCCULL, 
            0xA695A5996E14DB9EULL, 0x566068891AEA179BULL, 0xB21ADD4606FB7517ULL, 0xC013E7F2BBF1B189ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeyRotateBConstants = {
    0xCD844D40D3C7753BULL,
    0xC43DF748667985D1ULL,
    0x456E054CAAE8E78DULL,
    0xCD844D40D3C7753BULL,
    0xC43DF748667985D1ULL,
    0x456E054CAAE8E78DULL,
    0xF5F6FFF6C507C991ULL,
    0x8CC4C2B10A851363ULL,
    0x64,
    0x8C,
    0x75,
    0xBC,
    0x5A,
    0x8A,
    0xD4,
    0xC7
};

const TwistDomainSaltSet TwistExpander_Mothallah::kKeySpawnASalts = {
    {
        {
            0x779EDC5A4206269EULL, 0x25BC66B9BB9175BEULL, 0x97981CF3934F7F74ULL, 0x784C338B10590A09ULL, 
            0x7D69FE3FFA8A18C5ULL, 0x1A134D9307C75967ULL, 0x6571D81C7B42096BULL, 0xEE7C08D7CA9B8C79ULL, 
            0xC076C5F619017964ULL, 0x97FFD138D443423FULL, 0x699F2799D0155278ULL, 0x86B6718F94A9D414ULL, 
            0x5A29E9DF2BD2A249ULL, 0x03E6E4BD514420DCULL, 0x2DA38E4679699518ULL, 0xA1B67439ED02C6AFULL, 
            0x694E9FCD18B4EF01ULL, 0xE48232F4320F97E3ULL, 0x29C260D17B7F5329ULL, 0x93472CB689B6AD77ULL, 
            0x158C15F8FA432D24ULL, 0x72E00CE256F6F079ULL, 0x74349A54F56CA846ULL, 0x545D91790BB73AEDULL, 
            0xAF4F7380902E2DCCULL, 0xC0DC9F63E796A9E6ULL, 0xDF1D034761B18B93ULL, 0x01C1BF929B7BE49DULL, 
            0xA78BF50C805D8A16ULL, 0xB1644F14D4CC0778ULL, 0xA8B9D258B804870AULL, 0x036F8537935F0508ULL
        },
        {
            0x337A3C8425434F81ULL, 0x3726EBC7E8B63EF3ULL, 0x742CEBAE2A6A8A13ULL, 0x83D50504227303E6ULL, 
            0x6A916F819987A985ULL, 0x5FEA1A9152C90A0BULL, 0x386919A72B2E8042ULL, 0xAD1B642956295691ULL, 
            0xBAC4989C84B43217ULL, 0x2866D2339A5473BAULL, 0x9E757690B18CCE0AULL, 0xA0EE476FB9671B26ULL, 
            0xE03A548E3B6F2F18ULL, 0xCB4D923E2CA3DCB6ULL, 0x1596AE5F9A1A3A3BULL, 0xA08C9B14194A63FDULL, 
            0xA52C18F708ED8CBAULL, 0xEC94511754730A65ULL, 0xB179E3EEFCD537E3ULL, 0xDE53246B04A0916BULL, 
            0xA1F91C4A11DC12C6ULL, 0xE9C5F3F2C708CD2AULL, 0xB532897B9D44E090ULL, 0xA4A0A08FB6CCB53DULL, 
            0xD0C458B222E0060DULL, 0xE89F1B49D227B8B9ULL, 0xDDCB1FB40C0155D1ULL, 0xE4D637F4AE270090ULL, 
            0x93BE641E18C607FEULL, 0x5EE4F4E045FD9397ULL, 0xD5B5B480CA3C3B3BULL, 0x13DCC7B8BA9B4C38ULL
        },
        {
            0x03260DA6CEC661F4ULL, 0x3063DC5956B36BDCULL, 0x2E54995CCD2E0B01ULL, 0xD607B5C865FF28CBULL, 
            0x8FAF52E84DC1A1F6ULL, 0x8121C89C00090B9BULL, 0x92089529AB595A92ULL, 0x25F34F0533199880ULL, 
            0x2E8D8F036C19108CULL, 0x14700B59D21A4286ULL, 0x42BC09DEF77BF23FULL, 0xC6BBCD8AAD96AA45ULL, 
            0x42D50DE2DF03B4E2ULL, 0x3DFC3D561C53ECB8ULL, 0x3B6040009D555253ULL, 0x7907CD90AFD4872AULL, 
            0x66CB521243ED31CAULL, 0xD3516681A82FBDBFULL, 0x680C27E584727EEAULL, 0x3979ACDDF1785E72ULL, 
            0x3742F34FA4617625ULL, 0xF069655154E402B9ULL, 0x67E34C9395B135F8ULL, 0x7D7AD2CC9B741F7EULL, 
            0x5F8D455822365564ULL, 0x04E43328EF13A0BEULL, 0x769163B466C77A04ULL, 0x02FB9053160BD508ULL, 
            0x34B3061B52EB7C74ULL, 0xA1A1A9241C4DA3D3ULL, 0xBD9FDAA67FB2D2F2ULL, 0xF581B201E7FF174FULL
        },
        {
            0x85902C21EE51833AULL, 0x6E7695C033C4AA1FULL, 0x0CBB8F60A69D650CULL, 0x62C3A8501B827ACAULL, 
            0x34562986DAAA792BULL, 0x94D56C7596952D6BULL, 0x9A816CFF30AC0B17ULL, 0x4AD34A03B7903120ULL, 
            0x67F692BE45286E9CULL, 0xBB33E0A2896C218CULL, 0x4F5C2BE1CC4C9561ULL, 0x00714136DA72766FULL, 
            0x3544EEDF50530637ULL, 0x12EDB3EDCCC33673ULL, 0x900272861ACB8A8DULL, 0xED891536FCD0F86AULL, 
            0xB227702E7832650EULL, 0x4C62C6C7CC2AD960ULL, 0xD2FE6E6260E26189ULL, 0xB49FD71505F9CE33ULL, 
            0xB6DAE14032613E39ULL, 0x8E58EF95E3EC427CULL, 0x6D105B8DDD4A0543ULL, 0x52C96B27D1753223ULL, 
            0x363EDDB15BB9F25CULL, 0x4BE3BBC5F0FA9C8AULL, 0x05CA06D03606320CULL, 0x55035CD91CE3FDB4ULL, 
            0xDE258BB4BC83E89BULL, 0xB1571044AB2DA519ULL, 0x1D322A560D90D222ULL, 0xAB1DA4399C7067E6ULL
        },
        {
            0xB09B203A3097E405ULL, 0x798BB7FC486F7E65ULL, 0xA964B332AA7E0256ULL, 0x64F99E2384DE4E1BULL, 
            0x5A1EE330CBD3EE32ULL, 0xDA910E7422672D0BULL, 0xFF3F0E64E4468122ULL, 0xB9B7BD665AAC7780ULL, 
            0x5AAE5460D250CE85ULL, 0x4B374955B3EADCE3ULL, 0x3109EE80B9581B61ULL, 0x075256FB3D35F092ULL, 
            0xE0303872E578A955ULL, 0xB6F7CBBF5BC0E771ULL, 0x68FAA90F2A06691FULL, 0x512F040F9D99B081ULL, 
            0x3C71090ADC2275D6ULL, 0x6DCFCD5AE510116FULL, 0xBF0C427F17A809FBULL, 0x3033871B9C34D1ECULL, 
            0xA52E98DC9FAF0A36ULL, 0xADBD84114BAF276BULL, 0xF002806B885CB286ULL, 0xA3152AACCBBAC00DULL, 
            0x0361B60ECB41DA72ULL, 0x9AEC6E84EA440EEFULL, 0x38531D4EF83C6BB2ULL, 0xFBF5F4B1C35C47BDULL, 
            0x50492C0D2A237076ULL, 0x9223788CD79D0A5AULL, 0x15DFF148AC55CCFEULL, 0xE305FF9E4792BD92ULL
        },
        {
            0x37FA8F4A8D5E9A1AULL, 0xC1EED7DD0C2BBDD7ULL, 0x73BE43884D8B809FULL, 0x1DA6572A16D12909ULL, 
            0xD3D24BF557F05A1EULL, 0xB100EE7D67FBC6F4ULL, 0xEB63D6B5EAF6F526ULL, 0xA79E5FEFD1CF629BULL, 
            0x7390A768F084CF77ULL, 0x2FB36438C73FF207ULL, 0x079F6FBA3A1F886AULL, 0x2571AA6859363F21ULL, 
            0xFA70A019F4A50AA4ULL, 0xEC2D9172519EC0AAULL, 0xBCC7F9C3F6B1FC89ULL, 0xBF698F307DCE13E5ULL, 
            0x4484FD486B6537ABULL, 0x33C558761197F3C5ULL, 0x648B8B5C27C33987ULL, 0xCEB5F7FF07FA4592ULL, 
            0x062EBB57F444319EULL, 0x623A740915295ABCULL, 0x5D75714042B40F2BULL, 0x051999E034251282ULL, 
            0x4A29FC11E96C6EC1ULL, 0xE35458BFA430C1C3ULL, 0x13E3936D5B09515CULL, 0xC319DD05F2DAC2EDULL, 
            0x4B66229084F8E031ULL, 0x54DB5FA8358957E2ULL, 0x341FADD31F522AE9ULL, 0x0959C30DF6D61E2EULL
        }
    },
    {
        {
            0xEB360EC7DFC10E74ULL, 0x2EC19C25E1F6DD44ULL, 0xC9EADB4AA893C0CDULL, 0x981EA4913DCF2676ULL, 
            0x73739F326D45D91FULL, 0x859D479E51A5F026ULL, 0x1C12AAB7C1EEBCB9ULL, 0xE17CA4F66F7681E2ULL, 
            0x46E1C0BADC15444DULL, 0x7183A55888974A79ULL, 0x4232F966D7DF8A81ULL, 0x945DBF0064933067ULL, 
            0xF50B86152BD5FB13ULL, 0xD55FA889ECC0B864ULL, 0xF8568EDB158DE48AULL, 0xAF7A6E2193764C40ULL, 
            0xB80147277C40B768ULL, 0xF90872C14AF00204ULL, 0x0C891AF58C2B7A71ULL, 0x38FEFAC1EB9F5AC3ULL, 
            0xE7B66AFE7846A4C2ULL, 0x3AFC51CA49619E71ULL, 0xF6350C681A23221CULL, 0xEB05A2EB07F229B2ULL, 
            0x6512D07C1B899885ULL, 0x15F68F4A6C460336ULL, 0x2C21F862C4A61B54ULL, 0x3C07C1029A23BB49ULL, 
            0x432CED270CF97031ULL, 0x586A604726ECFF8EULL, 0x4C093034AEC1BB4AULL, 0x0EB2E8EF0DF352F7ULL
        },
        {
            0x572CBA9888F31337ULL, 0xA38CE48B1BBB3D0CULL, 0x11227AFB00763B54ULL, 0x6CA5AB9E2BC1A88AULL, 
            0x4140A7C80145F14BULL, 0xEB0C8C22254AFD42ULL, 0x17E7A57BA86BA07BULL, 0x5E0965600B163DDFULL, 
            0x0D5966404C0AEAA3ULL, 0xBDF9DCF1186A69EAULL, 0xD6B51C053070CFB4ULL, 0xCF6600B0CE57C4E8ULL, 
            0x3D99AD88FC1B4138ULL, 0x3E48B7FED6A47F17ULL, 0x3A4BFA93D34579FBULL, 0x19548672F5A924F2ULL, 
            0x56F9ADF2947CE55EULL, 0xDE4CE782924BBFC0ULL, 0x92185552E1314E6CULL, 0x0AF86708E106DC2BULL, 
            0x408255BD75747331ULL, 0x5775115F18D99EADULL, 0x405897BB4C060DC6ULL, 0xB1636792CD30E34AULL, 
            0x969BA6941C8A405FULL, 0x427D8456C0A2792BULL, 0x43112676694634B3ULL, 0x9D6CFB975CBB96F4ULL, 
            0x383E649D8C8BBBDCULL, 0xCA536612DFF6F853ULL, 0x178F686A534EBF53ULL, 0x3944EA3593C63846ULL
        },
        {
            0x2402A52D2BCB4A2BULL, 0xC1E75F53C0952CBEULL, 0x6A54C21F462E951AULL, 0x91DFB5DA27BCC210ULL, 
            0x7CC93D907E34E801ULL, 0xF2D070DB8202836BULL, 0x4C9D568C270B9578ULL, 0xED111B4287F7918EULL, 
            0x5D55B774569833CEULL, 0xC452F9037E325B51ULL, 0x57DB3D0271488DF5ULL, 0x9040E267B9DB8D2FULL, 
            0x1116533AE027B758ULL, 0x9720062AD8399F25ULL, 0xE60CF454C4E0F5E4ULL, 0xE81B0A830D00CC44ULL, 
            0xED8C6CAEA2A46C26ULL, 0x2E6EABB243B666EBULL, 0x20C75F03C9256F6AULL, 0xE061FC6FA782B71EULL, 
            0xE5E02868721A9D35ULL, 0x666C2D3C10034B02ULL, 0xABFAB173C9B453DBULL, 0x0FF1AC41C292323AULL, 
            0xE2DD843326FAF4B2ULL, 0x02F8B08F6483089AULL, 0xFDE3C753F84321B8ULL, 0x2DEA162A3876DC81ULL, 
            0x1E9D3F1A73154C9DULL, 0x05635614F1E01D20ULL, 0xB490260395EBB819ULL, 0x62292C7D7FAF04FBULL
        },
        {
            0x6073FAC77A026342ULL, 0xC85C3991D5ECE059ULL, 0x5BADDDB4BFE01ECAULL, 0x20AAB5EFB2B1F768ULL, 
            0x134EE92C23DD831FULL, 0xB7698477B71D97E2ULL, 0x146973CE83BACD77ULL, 0x868EC2484D1FC187ULL, 
            0xB2CD5C8A907D9DD9ULL, 0x389278D4FFD19775ULL, 0x40DD010D2E268925ULL, 0x753986FE4EFF5EFAULL, 
            0x13675AA10A89495AULL, 0x47842E7ABB7482ACULL, 0x9AD636800CD9D352ULL, 0xBDCB30FF39303571ULL, 
            0x8BFC69AF5C3D3707ULL, 0x2B5D517BA93A3169ULL, 0xD8C46D959A24F1AAULL, 0x7E5D4BD8D40E524BULL, 
            0x1F58F3DEB88E1AC6ULL, 0xBC770CF0D7BD76D7ULL, 0x44B8A7B16F5C34D2ULL, 0x3C77B9F9B7956077ULL, 
            0x24BA656E3556E02DULL, 0x5C2FD25F8B34A693ULL, 0x794F3C061D2E1553ULL, 0xA6BA27E274F84523ULL, 
            0x5C04124555FACC5CULL, 0xD3151CEF92AC316EULL, 0xD8D8CCB664075060ULL, 0x5BC7536102946890ULL
        },
        {
            0xBFD3F38E537D2F98ULL, 0x5C14E7B775EA781DULL, 0x4E7E51CC44137A0DULL, 0xF8812A173733602EULL, 
            0x7FDC13BF9FD92DBEULL, 0x8513DFEFCE3957B3ULL, 0xDACEFD709924995CULL, 0x948C141FE0EC200AULL, 
            0xDFA850B9F11C2771ULL, 0xDCCEC9D896B0D4ADULL, 0xB85C6776D62C8544ULL, 0x24110E0A7E845360ULL, 
            0x7060C202CDDA19D2ULL, 0x25806CF9BD332F87ULL, 0xA6DFBD376942927CULL, 0x7BD3A7D8ED5F695FULL, 
            0x8EB6511B58DAC5F3ULL, 0xBDAEE9DEAE30C086ULL, 0x9A8A0BF70A96E8E3ULL, 0x03879E06AADCC139ULL, 
            0x198CFA7BDB5B72D0ULL, 0xA24F8FFECD48B4A9ULL, 0xA9AE702BF97B2844ULL, 0x28E9F09B843AEF73ULL, 
            0x76227A753ADD874AULL, 0x6271197C539BF413ULL, 0xF401268D1C90C366ULL, 0x308634CC68C6F189ULL, 
            0x2426DF7A9D332058ULL, 0x330F664AF7E77A38ULL, 0x3877D1301048CFC3ULL, 0x70FB15F1F835BF03ULL
        },
        {
            0xDC3D703DFCEBE810ULL, 0xD3003613B7220973ULL, 0x3137AFFF20FF07A1ULL, 0x4AE3B397D0438312ULL, 
            0xFB6DF0F679E620A4ULL, 0xBF823D57A887F30CULL, 0x5460843559DF4E24ULL, 0x24E4BBEE1DADE484ULL, 
            0x3957E1FF7E406A1DULL, 0x9126AF5078F0CE25ULL, 0xCBAE02176397D72EULL, 0x103135A702C88DB6ULL, 
            0x65C635AA392BFB1EULL, 0xF995C179B1B03233ULL, 0xC64B05511E56B048ULL, 0x89924C37E6D1EB16ULL, 
            0xE80212045501BE99ULL, 0x262D59F922FA1CA3ULL, 0x8B98EC6B69530CF8ULL, 0x44494F70D96C09F7ULL, 
            0x6CF33AD0EFAB554FULL, 0xBD60525EF69B45D1ULL, 0x15EF61DCC23D6933ULL, 0x06470BE0D904C822ULL, 
            0x16D4F18CEA29F6C4ULL, 0x1AB08AAF744D22BFULL, 0x42611FE68DF75D17ULL, 0x6EF73562C67DD22FULL, 
            0x5438A1A1761C48AFULL, 0xBCAD83B54EDAFB45ULL, 0xE4ADA8163E61EB28ULL, 0xE385A967103EBA74ULL
        }
    },
    {
        {
            0xD8A3944E3750F540ULL, 0x16A3B0E532B0CECFULL, 0x3B645D06169DBC3EULL, 0xC2CD78584BAEE122ULL, 
            0xBA6D3315FD536127ULL, 0xD79213F9C6B742B2ULL, 0xBCF2ACDD8A74B191ULL, 0xD5392252D484D46CULL, 
            0x2C9421EB15EF8574ULL, 0xA7202A2D4D8CF869ULL, 0x63E8FD4196D0C74BULL, 0x823DA6CFF1445ED0ULL, 
            0x8F45F2DF816CACA3ULL, 0xF1F479868E38403CULL, 0xF9277CCAECFEEB26ULL, 0x4A251EDF7BF15836ULL, 
            0x11961356E8B7394DULL, 0xD2ED41795BCE0FDCULL, 0xBB40AA00BEDB9AE0ULL, 0x2670C0E33E2B13E2ULL, 
            0x796742803FCC99F4ULL, 0x0DAA9E1D5BF5AE15ULL, 0x0EFA6D5D41C77BACULL, 0xA9A27C8EBD5105CEULL, 
            0x8FE9ADFFB4FB885EULL, 0xBCA238F0D124E6CFULL, 0x0AC25C93E21BB3A5ULL, 0x437475370E5F8CE1ULL, 
            0x4CE0BA616F186F89ULL, 0x51DBA7751646F949ULL, 0xB66E9DB928C61F2AULL, 0x08CF8E08A05372E4ULL
        },
        {
            0x481456C53273F121ULL, 0x381960C362097125ULL, 0x9AF74F272CCB3A60ULL, 0x4D089CD7C7F84136ULL, 
            0x63C1B5FEBE715C34ULL, 0x7FE2480ADF4B12C4ULL, 0x16E104ADD7EF2DE5ULL, 0xB57E83CB33F5EB50ULL, 
            0xA672E9A313CC4554ULL, 0x7BCC747B9B8980E7ULL, 0x0F9927D219D58802ULL, 0x2956984259B69598ULL, 
            0x5EDA08271CA77CD5ULL, 0x90570911CF738421ULL, 0x81E6731CB9730639ULL, 0xA573C09E4B9D5BE5ULL, 
            0xEF6223636CBDD4B3ULL, 0x834F6A3D347278B4ULL, 0x8B43913CA3BF9912ULL, 0xEADA46E2CB6F6FBDULL, 
            0x76E069EE0F8F61D3ULL, 0x9F55CDFC07727DEDULL, 0x8BD7B86F145CC259ULL, 0x428ECD03C7015B1CULL, 
            0xADE172B649588730ULL, 0x0D6BB437070D3F2EULL, 0x7F63CB7F53EE7A49ULL, 0x9BBF804F0E7BA41FULL, 
            0x4169B7D13C08F57CULL, 0x49FBC62B48207E1FULL, 0x19DE9188DD4F98FAULL, 0x8E2909F939E047A9ULL
        },
        {
            0x71C962DB8EFDF6CDULL, 0xBBDE80D94B7BC9FAULL, 0xE94AAD04CD6CB195ULL, 0x86228FA2E48412B5ULL, 
            0x3411AFAB8AFD8566ULL, 0x618A5FAA776BE325ULL, 0x5D391C84749FE095ULL, 0x69B0716384035CE8ULL, 
            0xBE35DAD765952CB7ULL, 0x5AAB12103511CD4CULL, 0x4BEE0727A0E0DFDEULL, 0x60958B42F320A671ULL, 
            0xC108592D11D429A4ULL, 0x68960162C2D8E7D8ULL, 0x84DF20360F898205ULL, 0xBAE47226FC80823DULL, 
            0x21B1E4DA29923945ULL, 0x17850487C54F754DULL, 0xEF2D09DA6EDE5F26ULL, 0xA9522737ABD381EFULL, 
            0x97DAE2F0992F4B84ULL, 0x928B323A51546D80ULL, 0xA542D01EEB98CBC3ULL, 0x0D9B558366B36B83ULL, 
            0xA0D1A410169978B2ULL, 0x6E5DE1B67610AFBCULL, 0x78FD5436AF93D382ULL, 0x10B047E855D724ABULL, 
            0x48E09618B74EB6ABULL, 0xDB70813AD9018BC0ULL, 0xD46FC91B534E1AE2ULL, 0xC8ACDA018CE469C3ULL
        },
        {
            0xC0D20AF63E2DB9DEULL, 0xD113BB087A85893CULL, 0x79F96A0180B65CEEULL, 0x5F7A9426917BD85DULL, 
            0x66CA88EE7950D65AULL, 0x321277A4674976C0ULL, 0x69792D7F3A253F3DULL, 0x81D568A8AB379CD2ULL, 
            0xF759F38522327422ULL, 0x37E1044F2DFF0601ULL, 0x0AE2360C5815E69AULL, 0x7CA0BDBCC54898BDULL, 
            0x0255C8F9DB011CECULL, 0xF8541DDBFC1F4954ULL, 0x825D44F1829E06E0ULL, 0x9D5A6719430EF68CULL, 
            0xFDD55625227B632DULL, 0xBAE7CDDD0EFD2E23ULL, 0xA86F7D40B564C25FULL, 0xB18EC093A26C7178ULL, 
            0x6C97EB872BD59336ULL, 0x77BAA0FA08F00227ULL, 0xE9CB6CA5BE5049EFULL, 0x8A6D29DCE3495144ULL, 
            0x1164BB214C23DB8FULL, 0x7F1DEDF5DE120E51ULL, 0xE97373C3DCE2A981ULL, 0x8819929B175511C1ULL, 
            0xACB00A2413A0281AULL, 0x7C4FA050EDB41D13ULL, 0x2AF3EA1C3C8B52F9ULL, 0xD3BA6D6E0678A3A6ULL
        },
        {
            0x3B2353FD5826630EULL, 0x4932A0F8C734332EULL, 0x0AD57B3A8CCDB999ULL, 0xA6B3108F5C0B059BULL, 
            0xE3E2D6277B90F954ULL, 0x440EDA1153DC4D03ULL, 0x84CC38DBA2387BC6ULL, 0xB2E083F433FA1C89ULL, 
            0x8FDAE6D925D0F8B1ULL, 0xDCF3F81E12F5DA25ULL, 0x71E7F4E23A1FFE38ULL, 0x1B3733DB357C3A14ULL, 
            0x5BA102378A7A128FULL, 0x2BA786D955A50024ULL, 0x25B2F16503149C85ULL, 0xA6A0D70381612774ULL, 
            0xD9170F66C658EB22ULL, 0x0071AC54ABC39807ULL, 0xDC8F104879A9F57AULL, 0x85F9FABFE5715D83ULL, 
            0xCE94B8237952EB5EULL, 0x23DC93C1B78CF268ULL, 0xA435872A4EB422ADULL, 0x1186BD17DF9292CDULL, 
            0xE4323874FFC4F0BFULL, 0xE623EB5916636DE1ULL, 0x5CD6D6599B5E8015ULL, 0xB779E65623A1BA4DULL, 
            0x4CD93BD0FC1E68A3ULL, 0x0DAD3E1D40C3656AULL, 0x47F1197BA45A0F09ULL, 0x391A6B8954F37C92ULL
        },
        {
            0x0D0441B31EB53A57ULL, 0x6D8231195B37B0E3ULL, 0x5337DF6095807F76ULL, 0x1EDB62709EF5D851ULL, 
            0x3A9FDFF388690E6EULL, 0xDA4ED145C8753413ULL, 0x652ABACB0FCF39EBULL, 0x30AF3BFFA9A3A631ULL, 
            0x28FD63E75B252503ULL, 0xDCBCBC5405536101ULL, 0xE30CABFF78042CFBULL, 0x2490C612AC7757D3ULL, 
            0x5F52D5EA92621CE4ULL, 0x6C27A87C2095EFECULL, 0x292F8042A0845A25ULL, 0x710E35A2CC39C24CULL, 
            0xEE04E5C48EF15492ULL, 0x147B35DC903378C4ULL, 0x0CA81B7A243B267CULL, 0x02CBFF8B94067480ULL, 
            0x60141DA035681DF9ULL, 0xF178E531935E5F5CULL, 0x010B58F4FFC76035ULL, 0x61CBF880E772252CULL, 
            0x154303D7953228DAULL, 0xDBA18E294BEF4E93ULL, 0xBC607CDCDE9D8E2CULL, 0x59C599BDFC026820ULL, 
            0x657C8A5DC253B83BULL, 0x8A555A137DDC29DDULL, 0x7BC1F35DC03FBFF0ULL, 0x3A792A379101A7CBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeySpawnAConstants = {
    0xA590E28627F15740ULL,
    0xFCF85247BA138C99ULL,
    0xCEF43D9801A57A7FULL,
    0xA590E28627F15740ULL,
    0xFCF85247BA138C99ULL,
    0xCEF43D9801A57A7FULL,
    0xA448AE607AF958AAULL,
    0x839A9BF8875D90A2ULL,
    0x2B,
    0xA7,
    0x03,
    0x9A,
    0x33,
    0x97,
    0x58,
    0x0E
};

const TwistDomainSaltSet TwistExpander_Mothallah::kKeySpawnBSalts = {
    {
        {
            0x9ECCCC4227B2B52BULL, 0xFA7578CE07ECE448ULL, 0x3F823CE369B38D4BULL, 0x6BC1D9CA1D83C331ULL, 
            0xDBECD087CE141B25ULL, 0xC25E35F0512BA84AULL, 0x151DA0AF5E63CF33ULL, 0x76541D1005A4A349ULL, 
            0x6D1EF3929977F772ULL, 0xDFFBF9AE8164F127ULL, 0x5AD5085F6A85CD6BULL, 0x87B9EBAE780E6873ULL, 
            0x4F619659DF433F93ULL, 0x0BC078AF09152414ULL, 0x09CAA3DAD58CCAB3ULL, 0x7D84774AF85E7B12ULL, 
            0x4AD10AE9C76CD673ULL, 0x761FAB685DC13BE8ULL, 0x68D71F9C87664E5EULL, 0xBFB6A79AC02D6DE3ULL, 
            0x4DB45BB0CF27FAB5ULL, 0xB3F434B797B909C2ULL, 0x872B6CF957F54000ULL, 0xBD630ADFB2FB7E72ULL, 
            0xDC0A82F78785A624ULL, 0x8B72B3370CFE6EDDULL, 0xA2BDC5206A03EA7BULL, 0x3B54DF25D093B82CULL, 
            0xE0A73E1BEAAAC401ULL, 0xF7451F702E2A32A8ULL, 0x7CA562D255C71FC1ULL, 0x8DCB4C993AA02452ULL
        },
        {
            0xB101E18BA7276285ULL, 0xDD251DDB897F0F5FULL, 0xC14E6539A1D5D24DULL, 0x3FBA45A60852440BULL, 
            0x1F918AEBD2552242ULL, 0x1804973655B2D8A0ULL, 0x5BF472503B0F44DBULL, 0xA1123F70444A3CB5ULL, 
            0xDA75E001E8487C36ULL, 0x1032B010C7A2D982ULL, 0xBBBD312CA5A37058ULL, 0x769EE93B02D55DFEULL, 
            0x079EDDFB4CC26732ULL, 0xDFFE0B49C59BAC9EULL, 0xCB8A61DD6DE2E047ULL, 0x76D9BBD886996D96ULL, 
            0xAB4B13E70B635ED6ULL, 0x0E056B3C6F225C34ULL, 0x8A01E058AE4F37CCULL, 0x3CEFF6F2A22FF8A0ULL, 
            0xAAF8B95A008BCA6CULL, 0x266F46A86BB42F03ULL, 0x8751CCB63EF92BF0ULL, 0x06DF00B609BA0B95ULL, 
            0x0039E254D0A33E28ULL, 0x1E0FD2511B9F99C2ULL, 0xB91F02B099924CD8ULL, 0x7000C3D06EF49CBBULL, 
            0x4F5120C2047D6938ULL, 0x47C53D2E5448938AULL, 0x59EF166BDBB72CE9ULL, 0xADDA1DFB1BACAF1DULL
        },
        {
            0x4EE292403891AA62ULL, 0x9DCF461233CFDA9CULL, 0xD491ED17E5D1C977ULL, 0x875F25B531C99628ULL, 
            0xD8E3E65AFA69B1E2ULL, 0xEF9E0B0BA5A26C02ULL, 0xAD58EAFEBAB66400ULL, 0xFB27D22F4E21EE7EULL, 
            0xB7017644F542A69AULL, 0x0D8334EE72EE1465ULL, 0xD45B3ABFF03D75B9ULL, 0x2CC4D3DF9916DBADULL, 
            0x3E5807FF3168A747ULL, 0x0B2F01AC3720B84DULL, 0x74ED94B6773532D7ULL, 0x6D33BB94635B4989ULL, 
            0x5CEB5D60451E1B54ULL, 0x2CFFABD7FC6822D9ULL, 0x520AD8E7ED11A7FEULL, 0x28889B74A97E2EFBULL, 
            0x5D35F2EBA527E800ULL, 0xA1371BA2D9037565ULL, 0x0C3E54B72E03B23CULL, 0xAE9002B7B7D9DF29ULL, 
            0xD81F68BE72345DD0ULL, 0xF4D0A03834ADFA1DULL, 0x2C10618AA5E1862EULL, 0x2C6E65F5EFE2EDBEULL, 
            0x4B2864139D18A4B8ULL, 0x0093AF2E34D9532BULL, 0xE68443906CF14FFEULL, 0x632E8B8ED48CB406ULL
        },
        {
            0xF6F7144D6D039FC0ULL, 0x484F107C9D6C833DULL, 0xA58673237542D69DULL, 0x45818D2F0FA50D38ULL, 
            0xF8CA855154E8A88DULL, 0x2D749E8A9D45F645ULL, 0xB20DB1DEFAEF269AULL, 0xD50EC6279E27044FULL, 
            0xBD0B90A8A65C8B75ULL, 0x9A439AECFC13566AULL, 0x8D0AF8D577B7121BULL, 0x79362481B9A0DFB8ULL, 
            0x408610279ACEAA76ULL, 0x8D34FB2484567ACEULL, 0xF341F63C65562C35ULL, 0x1D7F5CDE169A20D9ULL, 
            0xEFED633B831E9440ULL, 0x3B408879D74D30FCULL, 0x471C3A6599DB9428ULL, 0x5DB65BA50712479FULL, 
            0x6725D378311F1B58ULL, 0x92BB628737225B6BULL, 0x7EBFB8B66AD2B854ULL, 0xDD86BE0E95E45D97ULL, 
            0x18E884D3F081A479ULL, 0xA1E824B30D1F23D1ULL, 0xC5DB38BB2F647AEEULL, 0x6DBF81D4D7496D5EULL, 
            0x9E9A6A39001A0F4BULL, 0xD87F90138E35FC91ULL, 0x41CF14DFDEDC4B55ULL, 0x8A13AE595A8EA35AULL
        },
        {
            0x50535469DB6294CBULL, 0x1D051E1A33844F70ULL, 0xA619F58A96E2AC19ULL, 0xE64C93939DDE2BB7ULL, 
            0x8323EF2CF7EA633BULL, 0x5EE106588E0288A9ULL, 0xBEB1F56BEE46B93EULL, 0xB9508DAD5EB0C643ULL, 
            0x1990C32131BFF7B6ULL, 0x7B814E6FB6DB7C96ULL, 0xBA78B0AA18249EC1ULL, 0xD46A731F1379699AULL, 
            0xC0A08C7500D4165BULL, 0xF2ED17E4B732A46AULL, 0xE326D5BBB975D502ULL, 0xDA802D69FD8B3135ULL, 
            0x06A4DB63F3103850ULL, 0x1534CC3706DD69EAULL, 0xCD8EB5B8B3CB45C2ULL, 0x70110EF1E27975C5ULL, 
            0x763FAB7F7984B0C8ULL, 0x322B6505A0B93752ULL, 0x203112EE1C183B27ULL, 0xEBDE24D9B3F8CAF7ULL, 
            0xBED22524B7D226BBULL, 0x438E9F0FA580BCACULL, 0x180483A91539FD36ULL, 0x64F3AB3E4E2C8FADULL, 
            0x534751D4AA9C9C26ULL, 0x928E0C221A1793F0ULL, 0xC07A326CBA138A35ULL, 0x0C6461AE8FE98335ULL
        },
        {
            0x184E7E0F2444E63BULL, 0x2D9433BC5DB57BCDULL, 0x6CEC3135E61B08B8ULL, 0xFB51C9C9F68AAA31ULL, 
            0xE00BE866FE65121DULL, 0x422F377A1AC9D4DDULL, 0x1FBA04F90F0E682DULL, 0x1B6B4AFAD44A5420ULL, 
            0xDC03CF73A6B618E8ULL, 0x1FA6400B57B3E988ULL, 0x229893D2C4986704ULL, 0x147BC66784930770ULL, 
            0xDFE7B7D446302D2EULL, 0x326E5A4231153840ULL, 0x8270888347E3764CULL, 0xB44B699F51BACD0FULL, 
            0xD6068DB2433CCFB9ULL, 0x894548B89B5A436BULL, 0x955E1B13A04FA732ULL, 0xAEA9EDCBA88E53FCULL, 
            0xADEB660215F6CF22ULL, 0x260A163335B6F7C3ULL, 0xF11D9D915A8E6F9FULL, 0xAC06AACA0DDBEA3DULL, 
            0x5A367E463D51142FULL, 0xAF7C15BF71B193AEULL, 0x8E9AF9739E1DF09BULL, 0xDFF0870F0256906EULL, 
            0x80B8502D0E0B98C0ULL, 0x79101FBE14453190ULL, 0x341AE30BF4642FC8ULL, 0x1FFB61D7D5670164ULL
        }
    },
    {
        {
            0xD3E2686A436865D3ULL, 0x38F3FB37B5580F39ULL, 0x636E05BD8DA9940FULL, 0x2C9E11E0356F637EULL, 
            0x8D679C277DEF0680ULL, 0xA7633F25F9AA1AB1ULL, 0xDD22D65F7E9DAD03ULL, 0xDBDA4BECC9A57E20ULL, 
            0x4EDD9C7F8EB2D4D5ULL, 0x1D6CF762060873A1ULL, 0xAA67522378DCCE66ULL, 0x7681CF398413AE56ULL, 
            0xB15DB3D9830A8141ULL, 0x74850134A02CA8D6ULL, 0x5E57009B4EE37D65ULL, 0xD6AC828DC9FB9077ULL, 
            0xC9405C2A420320E3ULL, 0xDC250F4DCF48A78CULL, 0xB5D899E4A694C0B0ULL, 0x7E9250F71D619BE6ULL, 
            0xFA47556C040AB4B8ULL, 0x06193F85EF6EB298ULL, 0x26D1BDD3945252ABULL, 0x9E88B44409BA8F65ULL, 
            0x3DCFD8F85D3A102DULL, 0x6C4DF623BE185B72ULL, 0x3857402792268470ULL, 0x983D58930D3FB521ULL, 
            0xFB644F1C1D125530ULL, 0x3BFED94C17329A0FULL, 0x757D076A38ACB947ULL, 0xD425B28C6D8954A5ULL
        },
        {
            0xE4F4576BFA114E99ULL, 0xABBBF6E8CE502B96ULL, 0x9EC1E7D4BC110C42ULL, 0x1737D41C27972DB9ULL, 
            0xFA31C4A167A48E1FULL, 0x9BF014DF6AFDBADAULL, 0x05D55D173C10BA8FULL, 0x4527292A0D23B204ULL, 
            0x0C6C42F75D8B48F1ULL, 0xE7106B3DA2A46A0CULL, 0x0FB1F7AAD5CC3919ULL, 0xAD1A5CB9B51F880EULL, 
            0x86EC7491671863CBULL, 0xFDCF733ACF5DC214ULL, 0xFC6F8BD60B670156ULL, 0xA519DFEA0D5249F9ULL, 
            0x12250204556096DBULL, 0x18982E4878B43EB4ULL, 0x259D17AC5B89B96CULL, 0x531FBC5B497FF07AULL, 
            0xE11F88313B75536CULL, 0x9ADA4ADE87C62354ULL, 0xE04970C2357C5933ULL, 0x383AED00C595DDD4ULL, 
            0xE6277A1D0BC35F44ULL, 0xF5243CDBDD32D30AULL, 0x8261E298856CB1A1ULL, 0x7A21A51CEE294863ULL, 
            0x037694B400E99964ULL, 0x4E25AAB80433973DULL, 0x45AE6726DCD4F7BDULL, 0x890CDEC781359065ULL
        },
        {
            0xE11E1ED4E25900EEULL, 0x42B03732549CFE7FULL, 0x456C91D30724DC96ULL, 0x83F4EF483680DE1DULL, 
            0x1211D5170DE00DB1ULL, 0x5D012FDBA6F45BB2ULL, 0x1A03A7EDF9CDD62BULL, 0xD54608AF3A842B07ULL, 
            0xB178224B4F03043FULL, 0x7072BA3025C3F8C3ULL, 0xC836D95157F34D64ULL, 0x60A730CFC72D7DDEULL, 
            0x256D8452B1CB336BULL, 0x5E71A8292BFB5391ULL, 0xFD18DF44C3D19CECULL, 0x43BFEB07F0F42445ULL, 
            0x701482BE96EE8512ULL, 0x4F16A338F7D1B201ULL, 0xD3C378D5E1C6C941ULL, 0x0ECA4C2B54698485ULL, 
            0xDE2650B4802C4D71ULL, 0xFAF98289B27BC4F9ULL, 0x65F1D8DA9C4D180BULL, 0x8D5F4D7BF7524D0DULL, 
            0x87E72C46D5598F71ULL, 0x10860EAD2EBD659BULL, 0x829AB9B0BA1EBE02ULL, 0x9D12B49E65EFE557ULL, 
            0x49E7913595F4F698ULL, 0xA925CF63BCAAE68CULL, 0x8BE8AA1EDB5E6F56ULL, 0x7C9F8AEDC0E718B8ULL
        },
        {
            0x5F68A7E3AF1EA4C5ULL, 0x6C9ECDDAABC7A591ULL, 0x2CB3C0794CA56AF5ULL, 0x251B181FB518F06BULL, 
            0x3A490910F3FE082CULL, 0x833C05ADB39BDE80ULL, 0xF010010B566F64F5ULL, 0xA1BE352F62393FF3ULL, 
            0xA5FFECBAD707E0F7ULL, 0x50F846AE8A6A9CB0ULL, 0x8C1546213C5B4076ULL, 0x8398FC699C4012FCULL, 
            0x7FD64E525FFBA2F8ULL, 0x4FB82ACAA606B6E0ULL, 0x4D6EAB583B1BEEA8ULL, 0xC163EAD4BE84ACE0ULL, 
            0xC6DEF9021FB3CD1FULL, 0x5A5A5EA2F41A49C6ULL, 0xE7A6E05ACD880670ULL, 0xA0E6ABD82161F12AULL, 
            0xDDC80A57E5DD44F6ULL, 0x06E7E8460F5B3624ULL, 0x781CA05A7F6C7B72ULL, 0x2E646E627C5DD66AULL, 
            0x2AC96C6129FC1DC3ULL, 0x94303D22E3AB2116ULL, 0xE4F41F3B22C8D6CFULL, 0xB8D0B06AE4C172B6ULL, 
            0xD8552C370F742607ULL, 0x413E0C7D21B54B39ULL, 0xC7369D0182FEC5BDULL, 0xA818C27CF2D6EDD0ULL
        },
        {
            0x071B43B60539E44DULL, 0xAC93C983E2BCEE27ULL, 0x0EC27912190A9492ULL, 0x4C3F294C98818BF8ULL, 
            0x1F1C1C401E933F80ULL, 0x996DFD97A9E4867BULL, 0x5D3AAD0ACEEC0516ULL, 0x3274B4A40320A655ULL, 
            0x02F81154586CCD47ULL, 0xCA06F68E38465F18ULL, 0x90EB8C336F23ED8EULL, 0xFF64E414AB23981BULL, 
            0xAE2C79642C80777BULL, 0xA18706D3DEE50C7EULL, 0x7C3D19E301FF1EE2ULL, 0x052704A62629CE74ULL, 
            0xB32A537C22AD8315ULL, 0xD197B8211F4847C0ULL, 0xFF9BCB5CE2273855ULL, 0xA0538FB60BC732BCULL, 
            0x074AB7F7626486D9ULL, 0x35A371EF4AE09053ULL, 0xA4E3F1643BBC0005ULL, 0x6CB7659A70324D53ULL, 
            0x8E8F3FB07AE4A4C1ULL, 0x45B592E8E58F690EULL, 0xCC3B0E1002651304ULL, 0x73327BFABF7F864CULL, 
            0x2E69362F41723259ULL, 0x5B15243DBF27C441ULL, 0x2859C44EDDD5B89AULL, 0xFF4B42A35F5662E5ULL
        },
        {
            0xA3686F210BEFC91BULL, 0x813C723A78225223ULL, 0x5A5A111D3F1D7D8DULL, 0xBFEB84B91252A3B6ULL, 
            0x691822A1DD1A6033ULL, 0xE18FB9B1B9684145ULL, 0x4267E0EDF239604FULL, 0xFC32AA71593EE5BDULL, 
            0x0C7F26F4D95625F5ULL, 0x643752ACBF841F1EULL, 0xE140E3BE29072E23ULL, 0x000F29B48BF6B1AAULL, 
            0x6C1719325BA8689FULL, 0xA39021AFFF7982B6ULL, 0x4EB06E948EE01B6CULL, 0x6E1F4A7D30E0BF4DULL, 
            0xF8CD826CEE4BF97DULL, 0xA77A2F7D33B3252EULL, 0x207FD29C068827D7ULL, 0xB39E337C5BF949CEULL, 
            0x886FE6042AA8996EULL, 0x568BE8421B3F05A2ULL, 0x4BEABB4FA1B26514ULL, 0x1AFCFA954ABC8717ULL, 
            0x6A68B286B7BADC2BULL, 0x647BACF6419AB9E5ULL, 0x0589C118F8819D66ULL, 0x59C45D0A1F0FE16DULL, 
            0x63A32033530BED1FULL, 0xFAB34F833D14B223ULL, 0xBEF7A2907CC185C1ULL, 0x76FB61D95914D4B2ULL
        }
    },
    {
        {
            0x0E17C4D06D0EE256ULL, 0x284527645FF3D262ULL, 0x231CEAA5D17B149DULL, 0x2BC5CA56FD8F8227ULL, 
            0x01B41E623A1F2B7EULL, 0xD8D930CC238E5EDBULL, 0x93F380DA57740EDDULL, 0x2DE68367A616810FULL, 
            0xAAB5328141195792ULL, 0xF4A8BE0EBEEB841CULL, 0xCCF012420120C94AULL, 0xDF148C233F93FB0DULL, 
            0x540F217356EBE17FULL, 0x427FB7BBF74B1398ULL, 0x966487439C470DD1ULL, 0xF8B7031B081A2ACDULL, 
            0xC457FE1524E2CD42ULL, 0x86961730B5317890ULL, 0x93864D1C6459638AULL, 0x4C89281333EACD82ULL, 
            0xF327DE39E3554BB8ULL, 0x410DBDB4C1627AB6ULL, 0x49D00EA775A3316EULL, 0x3BAB24EDDBE44DF1ULL, 
            0x5BE4CA5308528B91ULL, 0x8028BD4CEE9C87C2ULL, 0x4D4CD391AF78997CULL, 0xC8E38C69C901DBE8ULL, 
            0xD8F486893A2E4A94ULL, 0x2F3B9B54ACCF8F9AULL, 0x0AC9F4BE7AE96102ULL, 0x144B6B1B0F04E903ULL
        },
        {
            0xC645DF5D796A6E59ULL, 0x83FECF597B292678ULL, 0x5D81FD10F162A9F4ULL, 0x29CF311F153B1B8DULL, 
            0x7FA23F6332ACD080ULL, 0x427727EA0239FC5BULL, 0xF46CAB872C9C2D37ULL, 0x9C22E532D4435370ULL, 
            0x0AB4B4650B2C283EULL, 0x1A92795D2DAD79C2ULL, 0x879F8F9693E6C98BULL, 0xBBD5F46F0BB5C842ULL, 
            0x1A11F4EFBAA5BD7FULL, 0xD0A580DB30E39EE1ULL, 0xB536D2F95CBD8785ULL, 0xE232D20CE5065AF6ULL, 
            0x97C4799484391220ULL, 0x32344B045BFB7ECEULL, 0x927838B554C682A0ULL, 0xB67C4EAAF382C73DULL, 
            0xADEEABF4BB79810AULL, 0x7F8393C2329201DBULL, 0xC56320F7F9F38063ULL, 0x3697401904841684ULL, 
            0x69756CC9DEE33EF1ULL, 0x281BAA8830E43A98ULL, 0x9947380ABF8424E2ULL, 0xAA3F67555767A77EULL, 
            0xCD37152D02191977ULL, 0x527500910B977B65ULL, 0xF9DBF456D09B499BULL, 0x094F7C648FF3B848ULL
        },
        {
            0xFF858AB27697D3B5ULL, 0x7C5272CCD5016740ULL, 0xDA324F78B1947062ULL, 0x23F4D1655D737B4AULL, 
            0xDB7C74427FEA2D51ULL, 0x6C1B3CE3C657C7D4ULL, 0xD05E523911261BB2ULL, 0x1A8B60CA0ACD8505ULL, 
            0xB998233FFA9BF6BFULL, 0xAE249048FBD92EE5ULL, 0xD5348D2E213E054DULL, 0xE5D28C5937734AEDULL, 
            0x09677978958B7E82ULL, 0xCC79944B54B79685ULL, 0x50CA88DF8CD67724ULL, 0xE0E4743DB76FD5EFULL, 
            0xFAB9BF60CAF1AE70ULL, 0x2EF5DA3D4B0040A7ULL, 0xE169A96E4C9C413FULL, 0x680462F1B0EBD75DULL, 
            0x20B502B6EB7ADBE0ULL, 0x98A13900A8A94FAEULL, 0xD709666EB97A694EULL, 0x4466FEBE4A274CA2ULL, 
            0xFE3B80957880C244ULL, 0x71DA9D6B3F5263A2ULL, 0x2FD22636EEB6305AULL, 0x9CB2FF834A75BDD7ULL, 
            0x563FB2CC9B8BCF4CULL, 0x8FC0A52EFFD099D3ULL, 0x72E4B5B7C8EEAC92ULL, 0xEE2BD5DB42B6BA83ULL
        },
        {
            0x2D85AE40BEA4EFC8ULL, 0x91CBE764C1BDC828ULL, 0xE710032D43C99242ULL, 0xBA4981B7185A3054ULL, 
            0x8E723846867CBB3DULL, 0x0AE21A700C7B6DB7ULL, 0x7C12BEAE9AF9DAB9ULL, 0x27CAADE15E308BE5ULL, 
            0x460FFDA02A10D14AULL, 0x0CBC1C644003C61CULL, 0xCB42DF06B47D75E2ULL, 0x24583BAEC1DC27AFULL, 
            0x6028185706342BD8ULL, 0x86968D9835F97B2BULL, 0x4A7D88F537EF34BEULL, 0x6D8B530A54109BEAULL, 
            0xBF6B35F88444402BULL, 0xDF81B62473596B67ULL, 0xC1ED9025FA471E69ULL, 0xFCC869D15589FCE3ULL, 
            0x15EC8B08FA1C33D6ULL, 0x76CCA3B58D9AA875ULL, 0xDFD30553653F7262ULL, 0xB05799CCC1938CDFULL, 
            0x40FA397715864377ULL, 0xE8009C03F838EA16ULL, 0xE60BE799D48420D3ULL, 0x89A9FA18521FCF0DULL, 
            0xCE8BDC4C62D90C33ULL, 0xBA4AA0ECE5845712ULL, 0x49A6718CBAC00FFBULL, 0xEFFB7B6B44B8F038ULL
        },
        {
            0xBD5C2FC538D432F0ULL, 0x01F4F5693EEF398CULL, 0x6D59CF99E7440B9AULL, 0xDACC76876FA81EF9ULL, 
            0x2F3FFD870F4EF937ULL, 0x4AEE0DAF2DC4FB55ULL, 0x7DF4F7F664B1DB2DULL, 0x409A05604A273A94ULL, 
            0x14502BBB73CDCE05ULL, 0x75A31E73A77D9271ULL, 0x66707A5CACEB93B3ULL, 0x49347C7E2D501074ULL, 
            0x1743D697217666B8ULL, 0xCD83AEE151654B90ULL, 0x73B4543410BE0402ULL, 0x392EB9BE06BF0A9CULL, 
            0xD3E3E6D8F7CD178AULL, 0xFA809E5B4B5AB209ULL, 0xE03A4260F6A19DBCULL, 0x03BFA774523CF84BULL, 
            0xA94009CC58632E39ULL, 0x97042B2ACE12F419ULL, 0x4103C1ADA0E12340ULL, 0xF6FE09BFE4B3F234ULL, 
            0x87404448C77CC235ULL, 0x987BA7A41A3539AEULL, 0xAA4BA36A95FE8FA4ULL, 0x48DB688711F46B85ULL, 
            0x0CD1EF8C59C0B3FFULL, 0x33AFFF21A414DF4EULL, 0xE59809D8D31BAD37ULL, 0x4FC1B22EC837F91CULL
        },
        {
            0x9F59BDE0B1BF7FB4ULL, 0x3AD9209B48805D75ULL, 0x68D97558716A7374ULL, 0xB51E19CEA0853138ULL, 
            0xA31AC91382BE3C85ULL, 0x14D807F583044F66ULL, 0x940FECE4BC5E8F80ULL, 0xFEABC9D59F8C291AULL, 
            0xBD64D3359260B1F3ULL, 0xF5D0D81C5D2116F8ULL, 0xAA83D7639B87DB9FULL, 0x89AD9AA2B0E79DA5ULL, 
            0xA1A117CC27C37F2EULL, 0x57D3452EAC73FE53ULL, 0x7D4C494056DDCDE2ULL, 0xB59EAF204822AF33ULL, 
            0xCC8A26B192C77B1FULL, 0x866197E249BDFF8DULL, 0x3552840727B3068CULL, 0xF46EDFF6B1E68CEBULL, 
            0x0739C8D88ED2C5C3ULL, 0x9614B642142DA9C1ULL, 0xAE44471E0840835CULL, 0x284916F111290D94ULL, 
            0xA87263700DBD88F9ULL, 0x148535F99B517C39ULL, 0xFBF1E7C1DDEDE120ULL, 0xF84103B9D0B0B4ACULL, 
            0xA1A637D952240D57ULL, 0x3DC81F9B77509965ULL, 0x7EE75AE8FE8C92F4ULL, 0x6A1909316079325AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kKeySpawnBConstants = {
    0x3AD8586C8EC37077ULL,
    0x129BAB28BF6CD4D6ULL,
    0x2B3BEBB2C9AE97A0ULL,
    0x3AD8586C8EC37077ULL,
    0x129BAB28BF6CD4D6ULL,
    0x2B3BEBB2C9AE97A0ULL,
    0x98E4A47DCF6E10F6ULL,
    0x9CFC5E1247750E43ULL,
    0xEF,
    0xE4,
    0x3E,
    0x5A,
    0x92,
    0xA6,
    0x16,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Mothallah::kSeedSalts = {
    {
        {
            0x83974DF13FF2C6B5ULL, 0xF96BEF1FC7187AD7ULL, 0x3606C7AF9AB25F45ULL, 0x51DC725B7DA401A7ULL, 
            0xC29F965AF954A3BBULL, 0x165CFFCF01C001B2ULL, 0x08D343D155422E9DULL, 0x7DC36EA81CA18421ULL, 
            0x4A4097235FD77C14ULL, 0x87BFD53C1B349FF2ULL, 0x96B348A79E658902ULL, 0x839771EC7C8AA7E6ULL, 
            0xF66404278D011E22ULL, 0x7A72BD63DB593E21ULL, 0x2F19AC4150C08BDCULL, 0x36C929485D134D4FULL, 
            0x47D2E135ABAFE7EBULL, 0xE1AB074CF91388F9ULL, 0x0072489D79772725ULL, 0x336748865FD7A967ULL, 
            0x5AB910C6CD25756AULL, 0x79964E28455CB345ULL, 0xFB43E09A470C2B21ULL, 0x1083BA0924A316A3ULL, 
            0x3EA7EAEEBF27D33FULL, 0x618E698B433A51BFULL, 0x9FAA63E4D99EAFC9ULL, 0xA5A7003F55D4D78AULL, 
            0xBE25028B155F038CULL, 0xC45EB3654D92E26FULL, 0xB6D443D437B7B06EULL, 0x8D58621AA0B51FD4ULL
        },
        {
            0x99379010447BFABCULL, 0x5DE2835CACD9F002ULL, 0x4CC52844771694A6ULL, 0xD6A3BE7EA2AD2278ULL, 
            0xD6219C9B9FD28371ULL, 0x93B7CE22B0D379B9ULL, 0x44F2F481F87896C9ULL, 0x4C0D7F8279961F2EULL, 
            0x0A63823F676A10B5ULL, 0xEC4E7786D8CDC352ULL, 0xBA5DE04D4B8A8501ULL, 0x7D2A79B012F4AFB8ULL, 
            0x6A54BE9408505793ULL, 0x721C3D9F49E742D4ULL, 0x965C9031B499095DULL, 0x760FEA89CB8EB415ULL, 
            0xA2C3E9F748363AFAULL, 0x4BC5E62DB7D31EB2ULL, 0xCDB2D9AD06A89AA3ULL, 0x889F78EA68BF6C2DULL, 
            0x558B7D75FD3B596AULL, 0x4CE2094A00AF8F5CULL, 0xE7A0A70243F8D588ULL, 0xA5233A2F9E671710ULL, 
            0x5841800CDC8F6811ULL, 0x58B9A50557B12C84ULL, 0xE01E6785807FF2C6ULL, 0x24CFC230053089BBULL, 
            0xD81C266E5D7F79BDULL, 0xFC1368214DC95530ULL, 0x84C835B4C57F629AULL, 0x85CECF80058F9583ULL
        },
        {
            0xD831425EEB0D6327ULL, 0xECA9F3A0ECCF3CA5ULL, 0x755CB0608F113E44ULL, 0x2A40F7A53B904B5DULL, 
            0x1D423CF67A272D01ULL, 0x006570B2E1FD590DULL, 0x960B7B5B3B88299CULL, 0xFC380A7EC82F6756ULL, 
            0x31FDC7AAE40BEB03ULL, 0x06D6DCA1A59651D2ULL, 0xA1F22D1FB5E6B531ULL, 0xA20679C4A0E17BE7ULL, 
            0x2F2341F8398D7751ULL, 0x48373D18146FFE7FULL, 0xF3D574B932D654F9ULL, 0x80526D80EBDC46F0ULL, 
            0xD18AF026BB225D56ULL, 0xCF93FC7EE8380FE5ULL, 0x04B61A0DB4F1655CULL, 0xA893BA78DDE16F23ULL, 
            0x597005A4FD5902A4ULL, 0x352CF9FA56EF6E92ULL, 0x6216157409DF0571ULL, 0x724692BA7D0CBF07ULL, 
            0x40B215B000B6224FULL, 0xD67745AC420A5CB9ULL, 0xBDD0BD043126D4B5ULL, 0x6AD418B324B03269ULL, 
            0xD0BFA9DEB05E2771ULL, 0x74AE828666D2913EULL, 0xE32141F7ACBD0339ULL, 0x80BBE0DA72B9613DULL
        },
        {
            0x0ABE284769089F5DULL, 0x93398F99ED4CA94AULL, 0x3FB35910E8CEC507ULL, 0x07A1D9F20BC1B0D8ULL, 
            0xCCF1D66E0B499CC0ULL, 0x370F03A66C3981B7ULL, 0x2884DD842B070C46ULL, 0x288CD75505CF10F7ULL, 
            0x791AF5BA8F92F650ULL, 0xF74230E6BF31C25AULL, 0x6E751063F0CA4DE7ULL, 0xDF926396B3357966ULL, 
            0xB91D922A5B4B2696ULL, 0xD94489BD72815BA9ULL, 0x1C203D031DB7FC58ULL, 0x282ADB47BE775307ULL, 
            0x84EB5855E1E2DA58ULL, 0x2E035258C2020652ULL, 0xBC319ADA4F4BFC87ULL, 0x1E12F1BEDA55D8A2ULL, 
            0xC21A7A4EB32EC5F1ULL, 0x20B5585F109E5296ULL, 0x1B827F406C2712C0ULL, 0xBF72F64E95B4BE79ULL, 
            0x0A76D23A7D64DD23ULL, 0x835E97E9C54FC5C9ULL, 0xF4CF207F32304DECULL, 0x87380D8C3515DE22ULL, 
            0x189907C968B11763ULL, 0x1706478886B0CC86ULL, 0xDAC6AABA7B1368FCULL, 0x0BF9A2F8EE5C6435ULL
        },
        {
            0xBA46A7834BBD55A3ULL, 0x1AEDF6B017A2B54EULL, 0x9652579630A3AD11ULL, 0x981F4BA9BAD5E614ULL, 
            0x2C3D8F6BAEDB4113ULL, 0xC5C3384AF51028B9ULL, 0x986CF5DAF964D717ULL, 0x4D723F0FD6624BFBULL, 
            0xAC581E8C1237A694ULL, 0xCB8D9A3B8EDF3FEDULL, 0xC1670DFC3CA2FACAULL, 0xB34443A3F252EFBDULL, 
            0x9313423DB0619965ULL, 0x093D927C20DD53AAULL, 0x9FF3F2B775DCC8C3ULL, 0xF92A2DBB8851F8C2ULL, 
            0xA71F24DC808D8A68ULL, 0xACA8971AA2DDA6A2ULL, 0x1FDBAAD901F22381ULL, 0xE2CA3F967B0BB8AAULL, 
            0xF51777A9584606DFULL, 0x504408CC61DFABF2ULL, 0x7E49227BF6087D09ULL, 0x059C8EA2C05C1FA7ULL, 
            0x1406F42412093334ULL, 0x3300DA5CC9E67EEDULL, 0xCEBC89B22CDC1BEAULL, 0x8D20AEA0A8426274ULL, 
            0x4C5D994DDC13944BULL, 0x922B0325EEDB9C03ULL, 0x4A04D8636A4BAD25ULL, 0xC7843AFCBF4768EFULL
        },
        {
            0xFB4F1AA1EA1E15ADULL, 0x74BC18094FE35184ULL, 0xF98E21FF835EA889ULL, 0x9B312F350DC31853ULL, 
            0xE03C238F82238F65ULL, 0xC9AE4FBD7C5472CEULL, 0x7139A409ED12A03AULL, 0x244A3E27B6B2595CULL, 
            0x24EEFD9D86FF473FULL, 0xF0050ABDFCBBB94BULL, 0xF4584EED3B8EDDA0ULL, 0xB2ADD51A66D659D9ULL, 
            0xA1A36950DEBAFD82ULL, 0xEEB7F0EB4A759FFDULL, 0x797966D32338F972ULL, 0x348E38D7A74DEBACULL, 
            0xF6ECBE3FE3381C83ULL, 0xB2543FFA9878AD08ULL, 0xA4C8CFFDED21484AULL, 0x88ED94DB0677FE5FULL, 
            0xC45401C62C897870ULL, 0xED5016534ABF7545ULL, 0xD09CBB00BC66E089ULL, 0x734329016DB06194ULL, 
            0xFD127096297EEC9DULL, 0x77BB4B0953F01223ULL, 0x630593C402C43D14ULL, 0xEB12D87979253A19ULL, 
            0x514488A4C8121659ULL, 0x719D077C432FB820ULL, 0x124170D6AB2797EAULL, 0xAE53C231B3906549ULL
        }
    },
    {
        {
            0x776CB5F86427F576ULL, 0x9B4AB1A0F5FD0F29ULL, 0x1C5E513DD8A728D9ULL, 0xE42F49C9389D093CULL, 
            0xFC7ECC85BF6AAC74ULL, 0x6FBB95DFA98C38AAULL, 0xC9D74760B2CCB31CULL, 0xE4BE5382ECBAC85AULL, 
            0x22A19784C20264DFULL, 0xCC378C184AD9C8E2ULL, 0x4AE2056E4E4EDDE0ULL, 0x1043E9BE32F75E61ULL, 
            0xCFE952C78AE0A084ULL, 0xCA77D25AF4EF1F29ULL, 0x376E91EC0D6B2CEAULL, 0x23EB9FC373090E0AULL, 
            0x8754DC2EC80938A6ULL, 0xFFB22BACAA9E0C72ULL, 0x14A4C53D75C0C169ULL, 0x57BBC8C931689D57ULL, 
            0xD8915915C760FE49ULL, 0x0C3D5E751BCB5486ULL, 0x6927D26CE529F081ULL, 0x51C110EA9E072041ULL, 
            0x620CFC39039B83D6ULL, 0xA4BF9661B88077AEULL, 0xEDED766A9D80256FULL, 0xE3FB6F0F5CDC4981ULL, 
            0xE64E94526A30667DULL, 0xC67452CC2F3AD29BULL, 0x976D3253D4BA14E0ULL, 0x7C25599144F783ACULL
        },
        {
            0x18DC3B2FE0C42143ULL, 0x8D7E736B72ED95F6ULL, 0x13562143395F8746ULL, 0x1870D0060D326F15ULL, 
            0x92C9567332840CEEULL, 0xA05EF240644CB55CULL, 0x99D0AC4F63B75A28ULL, 0x6E94C371ABEF50F1ULL, 
            0xB8F53674CFF0E7E8ULL, 0xEF904D0BC20E6B62ULL, 0x2DC65F7CF0ED84EFULL, 0x5A552ADDB2D95A0BULL, 
            0x0461AE4D86A8F9AFULL, 0xD77F430CC280E3EAULL, 0x8B2EBBDB612C95EBULL, 0xD2788867035970E1ULL, 
            0x74C6EAA8DAD9B962ULL, 0x2C99B35FAE988C2EULL, 0xCC208B4B832A2B93ULL, 0x48CEDD637D6A5B4EULL, 
            0x3F9FD5C013E79B45ULL, 0x7ED689D2667C234DULL, 0x3A349E82F880BCD9ULL, 0x61DB6F10BB2C5759ULL, 
            0x20156686BF2A50BEULL, 0x57BCF514494B56EAULL, 0x735A060584657581ULL, 0xCC0F5570402FBDF1ULL, 
            0xBEE9952B3A5407E2ULL, 0xB1FB197202E6CAABULL, 0x41D83231BC78BE79ULL, 0xDEAFDAD93ABAF202ULL
        },
        {
            0x899C9800A77ECCE4ULL, 0x2AE567BA2404E405ULL, 0xABF137082EB7C1C3ULL, 0xBF737A0AF06FD913ULL, 
            0x2A89EDF59833FD9DULL, 0xD37013256DDD5000ULL, 0x2C3E3582B5FB8819ULL, 0x9A738C08456CE90BULL, 
            0x1CB31E549479BC61ULL, 0xECE1E809AE53E7DEULL, 0x2B0F34B20FBD5F64ULL, 0x229393FF5469802BULL, 
            0xCBC6EC754A94EA2EULL, 0x646243B947C207F4ULL, 0xF9E19E5A12B78FAEULL, 0x30D82B58869C5B7CULL, 
            0xAABDC700897C77B0ULL, 0xC6A1E3CF87E5FF14ULL, 0xD17CD62F44814B85ULL, 0xDD715E6F996A369FULL, 
            0x56240903EFCD0431ULL, 0x35EE379AF31D0864ULL, 0x0ED0185A40116599ULL, 0x4B8ED66B588792EEULL, 
            0x9C0EA2E8CDF767C0ULL, 0x1712CDCF92C6BDADULL, 0x19BB028BDDD91CA5ULL, 0x1AE20C06B06E9850ULL, 
            0xBAB93C01109F1B7EULL, 0x6E16B2B092ACEC44ULL, 0x1A048BFBA3239928ULL, 0xA05F56CDE9207910ULL
        },
        {
            0xEB17B4DFDBDDC709ULL, 0x62FAF386AEC70442ULL, 0xFD126068A8B4C073ULL, 0x03AF67E98E315C3FULL, 
            0xB18510EB0180FD83ULL, 0xE844CC5ED066011AULL, 0x454A917BDE84B588ULL, 0x9B305C4120E1BA4AULL, 
            0xB1B2AABE0C814DE9ULL, 0x806A3F1CBA9BB4D8ULL, 0x01248BBBB15BF663ULL, 0x6072EFC7CE6A1D85ULL, 
            0x350B4569CE270803ULL, 0x04A2A63E35792849ULL, 0x2E8D57A4A6826B65ULL, 0x494D9C5FB039E4FDULL, 
            0x6A7B3B0CCCBC30C9ULL, 0x6B879F9257D2DDB8ULL, 0xC1EAD359487146E8ULL, 0xFDB31BE0241526ABULL, 
            0xEAE641C60E49C32EULL, 0x526C62FB0302C559ULL, 0xB47B43F2BDAD24AEULL, 0xA71F1CAC1A8AF362ULL, 
            0x7371D4FAA9E57F06ULL, 0xF99BB17D496C1B38ULL, 0x3908E52E42D41847ULL, 0xE277751DEAAB1F6AULL, 
            0x6069BB635E641474ULL, 0x39411843D3EECAE7ULL, 0x4172719FF5556A86ULL, 0xDE2A45F004AD90C3ULL
        },
        {
            0x3FA7520CF993268CULL, 0x8485F00E2DA2E288ULL, 0xE0ABBE540E9E7EA4ULL, 0x6EEFCEDA6CA0D1BAULL, 
            0x11057766FCC7AC28ULL, 0x8590D76CA775B299ULL, 0xD7476F0739BD48D4ULL, 0x8AEAC6F5012BB7F4ULL, 
            0xB9A0A3521A749A35ULL, 0xC6BEEC8EDC41F098ULL, 0x457A5AF1C736A2C0ULL, 0xA5919D600E026939ULL, 
            0xF99609113AD01493ULL, 0xF6A53C7909469059ULL, 0x3EB71E6FEA626044ULL, 0x3FE56C76703FDD52ULL, 
            0x91FC776BDB0B0CCFULL, 0x8C2F53A839399770ULL, 0x83064E11AC026975ULL, 0xB6C53705C7126B02ULL, 
            0xC9071AD3C691462CULL, 0xC583B48D1654D1A9ULL, 0x5F215771DD16256DULL, 0x782B18E744AB0AE2ULL, 
            0x2B9D9FBA934C7D08ULL, 0x1134717259ED9091ULL, 0x5A59EBEF42DD709AULL, 0x399860634A49C6EEULL, 
            0x0E407FE8F5E6E6E3ULL, 0xF1EF0E6CC8B822EFULL, 0xE0D1A21669AE4825ULL, 0x1DA4E7CCE96D1F4CULL
        },
        {
            0x0827865A577CC060ULL, 0x1A2556E7C16A89E9ULL, 0x32D6E7FA23E86674ULL, 0x5D702A48F81C39CDULL, 
            0x2B29D4EB463FE08AULL, 0x70B2032E15E6DA7EULL, 0x4B3DA7DC91E64392ULL, 0x4EE6D77CFC08EF17ULL, 
            0x604A9D9D81AB861BULL, 0x0498B9DAB980653EULL, 0x537B979817192438ULL, 0xAB1D803DC1DE7772ULL, 
            0xEBD1955B6B0D9A22ULL, 0x209D14D5098FDBE1ULL, 0x73320F1851272A85ULL, 0x63A613D37840CC36ULL, 
            0x8AEC0FEA053A4FB1ULL, 0x128DB3C4132A370DULL, 0x650A2745D4346F4EULL, 0x77AC338C2FC01F48ULL, 
            0x201A80BB004E51C8ULL, 0x788AB652956C6DCBULL, 0x2790A456244BEB3DULL, 0x9EBFA3B2688EC32AULL, 
            0x108CCB283E7D2D64ULL, 0x88959786D3D9633BULL, 0xD21A65B5B5C210B8ULL, 0x86437FDB4FF0945CULL, 
            0x1175D27A71C8C113ULL, 0x339F89A944BD283CULL, 0x18C25D5EFC4EBCE0ULL, 0x4180BE34EB35E0C4ULL
        }
    },
    {
        {
            0x4C3A7DB3F493DCCBULL, 0xFBD15C20290A61C7ULL, 0x5E1B300F9D607EE7ULL, 0x694471ABDEFB7A3EULL, 
            0x91203CBC59C1A9E9ULL, 0xCCA001AFE527657FULL, 0x2DC54DB25D7F8D31ULL, 0xBEF0AADE59BF8BBAULL, 
            0x15F657D1DE6DE80BULL, 0x4A37A70F2174450DULL, 0x10A109324C33F85CULL, 0x43BF06F6F7D171F5ULL, 
            0xD2EA9AB51B2FB0B9ULL, 0xF5080C2E2C1DF83BULL, 0xF0E895EC50F48326ULL, 0x9CC9E40165595A5FULL, 
            0x46A7EA91ACE9BACAULL, 0x9B9E84CFB7A3DD9EULL, 0xBAA126E886E9DA9FULL, 0x79623E053AF6C83EULL, 
            0x3141606AD0CD997EULL, 0xC5C36509E279AE95ULL, 0x58F19F7C22DB16D6ULL, 0x08D299F40566EFD6ULL, 
            0x5E27AA3C22057A50ULL, 0x6256EE9750156EDAULL, 0xC7381B702784C9FFULL, 0xBAB5DAFBA336ED28ULL, 
            0x61ADBD253B9AC9E1ULL, 0xF10402ABAC3A1144ULL, 0x89FF39D5FA31C6E2ULL, 0xBD98105D359D6956ULL
        },
        {
            0x2884692F329A4ED9ULL, 0x99577C370E163FA3ULL, 0xF3676E262A7D6BBDULL, 0x363117EBBBEED99EULL, 
            0x822551138139441AULL, 0x35FA36A36D7135D6ULL, 0xF41003257808F63DULL, 0xDD822C0FD8D89DF6ULL, 
            0x88E87096F8D65C2AULL, 0x3E50E44331B74199ULL, 0x22502A1EE2AF8ABEULL, 0x83AE1B59C0286D68ULL, 
            0x112D832D61236192ULL, 0xB06D7043D696A357ULL, 0xB97970D8BC38D8E3ULL, 0xCC2F444B499043F8ULL, 
            0x9BD1B14191F4FD14ULL, 0x30344071D16D93E7ULL, 0x7083AE88DB81FC80ULL, 0x81EACF7323CB0DBBULL, 
            0x60CB548DD809E58BULL, 0x19B1433D9FC76446ULL, 0x8DB53F184C532746ULL, 0x2F35BD892B0414B7ULL, 
            0x965D55E97C890F9EULL, 0x7D02590A0AB7A660ULL, 0x574AF07AD7832DC1ULL, 0xD0F70E357889F9EBULL, 
            0x9753381A454AE4C7ULL, 0x8592305C7898AF1BULL, 0x038AD662F2594AB7ULL, 0x092F6126497C5F5FULL
        },
        {
            0x63B87796312DED96ULL, 0xAE97DE7DE52E4C26ULL, 0xEB5CAC3779EEC9B8ULL, 0x470FDB3D1C7DE339ULL, 
            0x8339E1979979061AULL, 0x8A67AC3F40C9A83CULL, 0xB92818B3985B672FULL, 0xF9DBE4E0EFABE233ULL, 
            0xF1E7855222CEEFDCULL, 0x8849DF25EAD9DDA6ULL, 0x86E24FA9BF9D1704ULL, 0xA3B42B819FD757E7ULL, 
            0x446682503A0C026FULL, 0xB6C132BD59A6ECF0ULL, 0x5A6F99770856A805ULL, 0xE12D7087CFFCBF99ULL, 
            0xB161ADF7FDBFB90CULL, 0x921DEC208E1854EAULL, 0xF62732F8CFD19C0BULL, 0x110F397AE6E7A2E1ULL, 
            0xF51B258523E847F7ULL, 0x7FEB94D71D39FFEEULL, 0xA75D2A0B1F966F56ULL, 0x26DAD672E8223129ULL, 
            0xEA19F00E4CBFEC10ULL, 0x088577F4A1D2E71CULL, 0xF262DE3B8964C7E3ULL, 0x1B2ECC9B032DA9CCULL, 
            0xED4C14CD58A68239ULL, 0xB30D9BA468BC0B95ULL, 0x01266DE42EEBCF40ULL, 0x6AC3780D250A3EC8ULL
        },
        {
            0xC42FDEA61E2DE452ULL, 0xD4391FC1781531A4ULL, 0x84018FAFAEDBBFBCULL, 0x91364215D5BE19AFULL, 
            0xC9333206EE7E8CA3ULL, 0xD3CDF265D96A1477ULL, 0xB1AEB920E9BAC15AULL, 0x8BD24A724E6A22B9ULL, 
            0xF63F687E95AC0A02ULL, 0x8A19E96569C8AA64ULL, 0x61E1A30FDDA86117ULL, 0xB1B87588485FF53AULL, 
            0xF2FFD25180522890ULL, 0x5769CBCF322FA801ULL, 0xFDA4C894B386DE6CULL, 0xA8295D5897C3E65DULL, 
            0x7667B72ED11FC654ULL, 0x1B677E219BD48EFFULL, 0x6651079A1E2AB74BULL, 0xBF4DAF92FEF32E3EULL, 
            0xD68FB3FCDC4309EEULL, 0xF993D2B381745A90ULL, 0xB235F5A39DF4611EULL, 0x26A628615E375E62ULL, 
            0x6BC365966DDD3679ULL, 0x4801D8D608FE07C8ULL, 0x31585DFB786C850EULL, 0x7F5896F78A88188DULL, 
            0x1BF2CCFA746DD975ULL, 0x06CAE91E0D78A7CEULL, 0xE41AE05E7989044BULL, 0xABF55683BB4DFAFEULL
        },
        {
            0x4EA97A442A949306ULL, 0xE576AFA289BDFA3DULL, 0x049FD046455409ACULL, 0x51355D7747A64F49ULL, 
            0x6A91DC1379DE4A8BULL, 0x8CDBD0BA506E1129ULL, 0x7F233D5D826660F1ULL, 0xF95BEB446478F6CEULL, 
            0x2CB5C44750F2C03DULL, 0x1F7CFD2B1C991A45ULL, 0x29E0E01A05291762ULL, 0xDD70C3FF15830861ULL, 
            0xE58CF09957A7E9ABULL, 0xA980B4840D768F35ULL, 0x8B7AC508A2A9EFB8ULL, 0xDD0ECECA82BDEAE6ULL, 
            0x1D3DA26BB419B1FDULL, 0xCE3887460CAB76B4ULL, 0x59A85DBB283CA7ECULL, 0xB4F0761F973052CFULL, 
            0xCD2BCE402D49D80AULL, 0x9558D5A799BD75F1ULL, 0x417C4FEB196DEB25ULL, 0x28BB11B615AF0DDBULL, 
            0x74F164D82A3D1326ULL, 0xD5C2C88858A327E5ULL, 0x245DF7EA5AE6F071ULL, 0xBC6F0431B4A5E68AULL, 
            0xB1C84E6F09266E21ULL, 0x5DE550AFC6CE71FCULL, 0x9CFA7CA999FB251AULL, 0x99FEEFE638751ED3ULL
        },
        {
            0x9D2084D649E586F3ULL, 0xE7A83E47FC71ED4AULL, 0x99A34E43F93081B6ULL, 0xD15C7CDD2B564BE2ULL, 
            0x3CD48AC90DAD4BB6ULL, 0x908E91F747AAB45DULL, 0xCE77D59215B3DB8CULL, 0xF5CFDF4A98B0DD5FULL, 
            0x5C454F67A9D1FFBDULL, 0x320BC52883703F36ULL, 0xBBF1A32972A0489BULL, 0x21F813149CE5148EULL, 
            0x0456232A0F8104D5ULL, 0x8C598CFB9241717DULL, 0x786A94A2D90E0508ULL, 0x27683C0E31801761ULL, 
            0xFAAA24E5CD33FB28ULL, 0xA0E782C3504EA846ULL, 0x8D67A9CF0CE41DFAULL, 0xBCC9C3AF54D243FFULL, 
            0x3D00567F6DB25CFDULL, 0x7380726B4012F7C2ULL, 0x40309E1E233347A7ULL, 0xE97345C132E0F212ULL, 
            0x0A4738E8D6270E00ULL, 0x5494B7960B1A68EAULL, 0x87A9CFAFE32D4BC0ULL, 0xB9B71CB2FBD97648ULL, 
            0xC8792B58379277B6ULL, 0xDFA55B67893620B5ULL, 0xC6A13FFFF5F0D315ULL, 0xAD7F1F2075BC038EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kSeedConstants = {
    0x2B5155887276DA27ULL,
    0x16BDD36130E75D3DULL,
    0xE31514157B7CFDF2ULL,
    0x2B5155887276DA27ULL,
    0x16BDD36130E75D3DULL,
    0xE31514157B7CFDF2ULL,
    0xBE2B2133D131D675ULL,
    0x9B7D3E002185BF44ULL,
    0x2E,
    0x4C,
    0xB9,
    0x33,
    0x9B,
    0x2E,
    0x0D,
    0x80
};

const TwistDomainSaltSet TwistExpander_Mothallah::kTwistSalts = {
    {
        {
            0xE1691CA261F78873ULL, 0xC8F083786986F755ULL, 0x525DF28E6BCAAD67ULL, 0x6D55F276296E20E2ULL, 
            0x58F1E9302885C1CEULL, 0x9711E519145DC279ULL, 0xD9627B6C8D2759FEULL, 0x94AF3CF11EBFDA2AULL, 
            0xD4B215127DBDA73EULL, 0xA765465029976A60ULL, 0xDD2E03B1C8589EE3ULL, 0xB77D9F243318B911ULL, 
            0x46131E3159F2A9E8ULL, 0x23E82ED7AF2F762CULL, 0xB19E286BB8B6EDDEULL, 0xC61D5F233C57A003ULL, 
            0xC6D8943B58540DF6ULL, 0x5FDD130E9EB05381ULL, 0xAE0AFDAE8C1C6B91ULL, 0x42D8A94749D3887BULL, 
            0xF45EF5EA81B9A9F5ULL, 0x2C18B6B5B02720ADULL, 0x4214EA929A135924ULL, 0x73F51F00E4B4E34BULL, 
            0x71B561E26097DBE6ULL, 0xF700A38A4612EBC5ULL, 0x6C21049F17559BEDULL, 0x29E99BBD77FC5307ULL, 
            0x1346F359E72D4448ULL, 0x37D847D734AE1AAFULL, 0x6AE674CCBE7DDFDEULL, 0x9F6F1138758D4A45ULL
        },
        {
            0x8E2EE75E05839A08ULL, 0x6931C045C2E5F10FULL, 0x74649AF6ED18C9A1ULL, 0x33D832DC8A49E63FULL, 
            0xFF5290A95AC6E57EULL, 0xAC1D760D18202CE6ULL, 0xE931D5683C797D0FULL, 0xCBA5B87B839C615FULL, 
            0xC1719B0A13A4825BULL, 0x0B2740FC12AE9B97ULL, 0x1AEAF716390AC205ULL, 0x82BF8D615BD67108ULL, 
            0x7D9E00BB4635FEE2ULL, 0xC1BD8AAA85B144E5ULL, 0xE988022CDD6D7C0FULL, 0x64BF79EBE72D4E23ULL, 
            0xB2A1ED60F8CC5481ULL, 0x2F07E96DE9A58FABULL, 0x30710CFA21858831ULL, 0xE64BB564B105C0A8ULL, 
            0x102F554F7773EACEULL, 0xC7E60D7663001746ULL, 0xA4A6CB94CF7846ABULL, 0x699D7384B3A3F60EULL, 
            0x434813D0EE003F36ULL, 0x12FBD6A4AC2BB810ULL, 0x41D813DD1C66FF2BULL, 0x655EBA63D695A8F0ULL, 
            0x97B57C85682AC3FBULL, 0x05B93DBB6471DE09ULL, 0x2FB9C8507B49021BULL, 0x3AD6481BCF7F903FULL
        },
        {
            0x94D6E6795264BF27ULL, 0xBE58CF6945F1D23AULL, 0xB75BD241709A076AULL, 0x6404E817EE100F42ULL, 
            0xB0F9EE3F9C5D64F8ULL, 0xC2DDF4F89B9825B7ULL, 0x59E653D1BC045836ULL, 0x4776E999C39B23DBULL, 
            0x14A8E47CBE70A4EFULL, 0x42E46DA7A971A148ULL, 0xD905CEEEFF089100ULL, 0x76951E264EF3FA03ULL, 
            0x090DC87723F14814ULL, 0x2A478DA2EB32EA08ULL, 0xA347744704A801B8ULL, 0x1B0008BE5B452A8EULL, 
            0x39C1D941C138ACE6ULL, 0x287F334C0263D176ULL, 0xC18DCC3A5A9BA8AAULL, 0xF7E0FE00C01E351AULL, 
            0x97317681173B7680ULL, 0x446724C122C5C815ULL, 0xFA1FFFB2AB0D5C16ULL, 0x756DDF925414C1B5ULL, 
            0xF569D8BAEA1FEEC6ULL, 0x990F82FC324B062CULL, 0xE051676C60D59666ULL, 0xA6D44A470DC5BFE0ULL, 
            0x229013FDEDEE6480ULL, 0x5D1782F6B22107E7ULL, 0xF3C0A5A9A849AF1BULL, 0x9F1E3862EC8BECFCULL
        },
        {
            0x3A4DECB163E324CCULL, 0x2A6411A45A2E9A46ULL, 0x8BF38EEABF9599ABULL, 0x35AFC5311BC32329ULL, 
            0x12212CC200BC7C45ULL, 0xEB32749AA5E50EFBULL, 0x0A37E5033E2FE20FULL, 0x5B7CD849CCDF5973ULL, 
            0xAD4239968052D9B6ULL, 0x3F7CA16E9BBC41E6ULL, 0xBC26A3B27862D7DFULL, 0xA463C39BEAB3D26BULL, 
            0x6D7C3B34CCC1AB66ULL, 0xAD4D041F395183CAULL, 0xF82CB26564CCAE7CULL, 0x6DE3640E1654C072ULL, 
            0x1A6C01CEC9FB1102ULL, 0xB0399CB0CBED7ED7ULL, 0xE51F9953047A5DA5ULL, 0xDB99BEDABABA67AAULL, 
            0x3C8E93D32D65E996ULL, 0x6E182B2EC08F8A85ULL, 0x66974929F51269DFULL, 0x1E545DFCFF2D464AULL, 
            0xFFBF41DCCCAF86A5ULL, 0x1D75550115B066CCULL, 0xB7F78E50ECB28489ULL, 0xBCA8282A420B1A3AULL, 
            0x19AECDFC613F315BULL, 0x433469312BCD4353ULL, 0x82F762A6A1321467ULL, 0xC9B7E740BD8B1B52ULL
        },
        {
            0x470D3278FE83D63BULL, 0x5D51C3C2C472CB69ULL, 0x8990F1AFD9D2107CULL, 0x80B0D137ECF67A28ULL, 
            0xA8D57B0D20A32CD1ULL, 0x0A2F383BE9155893ULL, 0x8AAA7B24C8D8D329ULL, 0x8DE30966CA5AF2D0ULL, 
            0xA20326ACDD5ABF05ULL, 0x0A9299E2B42BDE3EULL, 0xDB7C9751B7A2CFB0ULL, 0xF8F2C3E9A6D9F38AULL, 
            0xD807BFF4FD945934ULL, 0x897FF045F63A5EF4ULL, 0x3EE7D99046535DBAULL, 0x560D0B91E4BDB0D0ULL, 
            0xC803E85D2CD3F5F4ULL, 0xA604C8A5E0CD554AULL, 0x660C7EF486F13744ULL, 0x8DCCB8AB9516F47EULL, 
            0x7E72222E4B5324D5ULL, 0x633040620C011846ULL, 0xF38F284314BA01F2ULL, 0x0321A96BF67B2B4AULL, 
            0x0A287DF7474AA8A2ULL, 0x848F60E23FB7415AULL, 0xA08CE46551CF22C1ULL, 0xCF1570CE222B9528ULL, 
            0xEFAE6D162231160AULL, 0x783D304BFA371304ULL, 0x6919B3876575DB52ULL, 0xF88D7D7C7D36C15AULL
        },
        {
            0xDA9D9B9C92F5D3E5ULL, 0x3EFAD8091F74B251ULL, 0x4A3D253A64818FC1ULL, 0x705020A3A6AF3910ULL, 
            0x499FC00D068DDD20ULL, 0xCBF29684444CDC2EULL, 0x368F5EF864524851ULL, 0x030D1B4242551C9BULL, 
            0x65C5DBB0BB708A13ULL, 0xC97291229A6A8E14ULL, 0x2D7B9879E347D160ULL, 0x0F89919D4F8FF302ULL, 
            0xBD6852A9210BD1B9ULL, 0x51D5581F4896933CULL, 0x4FD26DA14178E281ULL, 0x53249156BBF26537ULL, 
            0x2B25290689914940ULL, 0x8428A5C84CD7B54AULL, 0x6793CE4A73262373ULL, 0x45AB709706AB8915ULL, 
            0xDC84E4EE7F0D78E5ULL, 0xAAB27564283344B8ULL, 0xB8F84662D20AFABFULL, 0xD9E398C9C41A36CBULL, 
            0x3896F8C09ACA1169ULL, 0xDC79EA43E3E02ECFULL, 0x8C434592B832A462ULL, 0xFD29F71B7B8148EEULL, 
            0x5C0EF83F97116FE5ULL, 0xBB85A48798E1CB0AULL, 0x802FA72E214D5D73ULL, 0x0D4A9661730E11A1ULL
        }
    },
    {
        {
            0x2F7935920F8A6081ULL, 0xDF278B7739ACB427ULL, 0x93FD1C1424BC05F4ULL, 0xDD9C935D162369A4ULL, 
            0x4173D3E33EBCF404ULL, 0x7475ABF267F821E3ULL, 0xB5641EE23FB5FC34ULL, 0x648FA642C006579EULL, 
            0xAFEAAF190171D629ULL, 0x6EEAE684F82093BFULL, 0x69E96363D2DBC3FEULL, 0x9EDF207A3C93FEA0ULL, 
            0x677192A50FC6027DULL, 0x6DD9937E23471682ULL, 0x10103CC0FFB51009ULL, 0x164918C642684084ULL, 
            0xE65F2CCC79157477ULL, 0xDFB9ED54B297B929ULL, 0xF9770F354C0A40BDULL, 0x5C6B7492876AD990ULL, 
            0x2A4DF1AF1B08D1E0ULL, 0x740C0C4FD2F62E4DULL, 0x71FB7E6AE175D68BULL, 0xA461F264F58E1EC2ULL, 
            0x9508AE8751BADCA1ULL, 0x8712AB3EAC3D6081ULL, 0xCA2BBAC97CED38EFULL, 0x760D1727F5A59D57ULL, 
            0x85D2152F368F12BDULL, 0x39ADB74243C310FFULL, 0xAA482436FB409B02ULL, 0x202BFB98F6AC7F84ULL
        },
        {
            0x521F185BC0F393D4ULL, 0x9F64EF9C32080881ULL, 0x91DB9819F07F29F6ULL, 0x028F7D629CE7731CULL, 
            0x5A85A851A1B6DBE7ULL, 0xB9E4828E0A0DAE7CULL, 0x33EDC455B4FA3934ULL, 0x4327D3291BC661E2ULL, 
            0x04CAB43AA3E88A2EULL, 0xB816AF66CF5D6447ULL, 0x0ECF0C077502B8EEULL, 0x5F54778C7CB08104ULL, 
            0xD865DF24A7EF5655ULL, 0xB011ECCC8C49EE34ULL, 0xE02C6FFCB9AC1E16ULL, 0x48C8F126A93BE0D7ULL, 
            0x9CF19690A212B741ULL, 0x5B26375A2F966874ULL, 0xB01EAF242BC9951FULL, 0x552F7ED1D8C1F2B6ULL, 
            0xC1E0178D89E6F8A3ULL, 0x5AB6BD83B9B81306ULL, 0x406D24F5E8C61373ULL, 0xB50B08D95C4A8639ULL, 
            0xCFB7A2145E38C165ULL, 0x4602E666823FF1E4ULL, 0xF13C3BCB75704F02ULL, 0xD74B9C5367AD4887ULL, 
            0x8B9D0A5D176A48D0ULL, 0x2D70E4D34931F463ULL, 0x91A66C76978E9385ULL, 0x2E43CA1E55581AA2ULL
        },
        {
            0x862ED1A6B45EB6A8ULL, 0x96F13012FCE1EC3DULL, 0x02F8325DE6E30366ULL, 0xCFF6DA8703A32183ULL, 
            0x47F8F13C2DF467C7ULL, 0xC35ACA1AA07A8CBAULL, 0x22D180380F01922EULL, 0x26029327694222CAULL, 
            0xDDEE0BA858C21C6CULL, 0xB957BD63FD79AB76ULL, 0x64BFF1EB8C32D39FULL, 0xCA6A9D1B89DF1A08ULL, 
            0x539B23832A3E4EDFULL, 0xABE74D95FD7DE5A0ULL, 0xF112F97EAF0FA1BDULL, 0x2EA51040E6B71402ULL, 
            0x0FF4A5FBC1FE1836ULL, 0xE7E2D1D4E83400AFULL, 0x4B851D0DDFC57150ULL, 0x0036084DF3984FD0ULL, 
            0xAA9A6257AC14AE65ULL, 0xEFD2432EC74A15C7ULL, 0x29D2D32917EFF063ULL, 0xA34F2FE2AE186300ULL, 
            0x3AE2200DC7A75DAAULL, 0xD40BB714CDB16F48ULL, 0x06CD2861EE9E6AB6ULL, 0x248F58596492FA1DULL, 
            0x0C7D8A6CC173BBA0ULL, 0x8AD92C762B54479AULL, 0x441DB7A83CE42DF9ULL, 0xF469DA15D70F3F2BULL
        },
        {
            0x99EA4D4736E0C3ABULL, 0xEC80B6DF99829672ULL, 0xC1AA6E3A68D3C92BULL, 0x2712FAA539EB39D3ULL, 
            0xDC092F4FA62DFB7AULL, 0x0A7597BB23E8DC68ULL, 0x6143BF88F559F82AULL, 0x58303D71BF75AC8BULL, 
            0x22F8906E93B98102ULL, 0xF2008F64F195F7ECULL, 0x69D1320F2C83E242ULL, 0x91EFD46958EFD97EULL, 
            0x08D39F6B7A850FC1ULL, 0x4D8A3FEC82713038ULL, 0x9D19D26A24942C69ULL, 0x489697E587DC6F97ULL, 
            0x00B726738E6C202CULL, 0xF158B86AD2A5A8B2ULL, 0x5C92294557AEFC51ULL, 0x52F0AB1393149829ULL, 
            0xC7B5475D30023920ULL, 0xDF9E788426896243ULL, 0x80707DCC35EE177DULL, 0x60E363261305D2D2ULL, 
            0xB9202BAFE80C590FULL, 0x63912C6EA899013FULL, 0xCD2FD4EACBC08835ULL, 0x774672415DF43070ULL, 
            0xF6132DB60412C27FULL, 0xCBBE65E1E75164B8ULL, 0xAF7FB2CF08637758ULL, 0xBE479662A8A64E6BULL
        },
        {
            0xAB091AF6531D1763ULL, 0xED1DAA0B64D92C47ULL, 0x833E649777BEC4B5ULL, 0x6487C2B9A3C35A17ULL, 
            0x9A51E143CB539501ULL, 0x348137A53C9B1BE0ULL, 0xF00D1365AA2ED34DULL, 0x44DE09E28E4E0735ULL, 
            0x15CBA6A1427500BCULL, 0x40F3B2C9C94DAE0DULL, 0x653F8EBF94C26BE4ULL, 0x35A67E4E184AEFA9ULL, 
            0x7253DD5E778F644BULL, 0xBBB50F204F4F8B48ULL, 0x58AEFB467698BAF4ULL, 0x47E0EAD4A4B90178ULL, 
            0x54F67F87C933927BULL, 0xEB0B2A0190CABF90ULL, 0xB6CE57E5DB3F8CCEULL, 0x943EBF23172F8D64ULL, 
            0x6334A322C29A72C6ULL, 0xF993D15CC60574E1ULL, 0x328DEDAEF5CD65F2ULL, 0x5507A03DBA38C6D8ULL, 
            0xB84DF2FC91F26467ULL, 0xEBD493FEC0B99BC7ULL, 0xC15DC230DB49CB10ULL, 0x7C2995E15E69FD52ULL, 
            0xB9EDA270D5A9EE34ULL, 0x5160BB43F508D4A5ULL, 0xA46E37C7F6CDBB92ULL, 0x49E6E4FEE90AB77AULL
        },
        {
            0xE07E8FB16154FB4EULL, 0x37DF360844260638ULL, 0x0D0ED37ACDE2B76DULL, 0x26340A724D0FFE84ULL, 
            0x18B2613A720E75C0ULL, 0xF31569FB5DD466E3ULL, 0x8410B09178B2C379ULL, 0x385716B6B406DC2FULL, 
            0x233619A8A455C538ULL, 0xB9E2F5C7548E3882ULL, 0x327A98FD8F9EECCEULL, 0xD4A114E3C0960578ULL, 
            0xE807082F350824B4ULL, 0xE8EED228B8267ECAULL, 0x15BD511C80DA113CULL, 0x836ADF816FCEDFBEULL, 
            0xD19233E116EB5C5DULL, 0xF1BE28DE2D79A79BULL, 0x54B1C7A6393069D6ULL, 0x92C6DE13790B61E0ULL, 
            0x8B1221012B2E7894ULL, 0xE227150572F54452ULL, 0x12F6F4D83CED68AFULL, 0xDCBB56A29919729CULL, 
            0xB8C627D9B8E694F8ULL, 0xC5D79F17DCA68084ULL, 0xCDF0628620AC6DE0ULL, 0x2E05E8AA87ABFB19ULL, 
            0xF75A508F08B2A705ULL, 0x8C673069AFA78461ULL, 0xC5341387E01F669EULL, 0xB4C24BCF27E8E091ULL
        }
    },
    {
        {
            0xB7858AC63608DBB1ULL, 0xE48B27015A8AB581ULL, 0x1385BAD33CDF8F7CULL, 0xB6194ACAAF5E4C50ULL, 
            0x25A839400143D8A5ULL, 0xD636230088771BE5ULL, 0x95A80ECC606173F2ULL, 0x2730E1B287E66674ULL, 
            0xFD665F9C935AF84AULL, 0x6F00DDD6D744F129ULL, 0xF3289A59DC9B7515ULL, 0x06D0B78B905DC059ULL, 
            0x7F1244F54037E701ULL, 0xEB797B8C0218AE6AULL, 0xAA8DE584829F6E6FULL, 0x8ABE93000ADB19B0ULL, 
            0x4305B4ACEE1DAAA0ULL, 0xB8E68960531EAAB3ULL, 0x20FB85F03210960FULL, 0xF63E11CF1730ABF8ULL, 
            0x8504113787621797ULL, 0x7330AD9BF0F94DF1ULL, 0x7930226E0334127CULL, 0x2A0C5C471A80F23AULL, 
            0x66B37A5F2AEAF3EAULL, 0x5E4CAED4847F9D45ULL, 0xDCF9C95763D9C565ULL, 0x9A577ADAFBDD4A83ULL, 
            0x5A2F63B5C492F034ULL, 0x138DABA327788965ULL, 0xFE6ACC8331442D70ULL, 0x72A34F7B11D1103BULL
        },
        {
            0xB2CED57AA48A6F3FULL, 0x273BE2076D871B6DULL, 0xA802C00E6BF53586ULL, 0x9EF7C4F3BEEB7853ULL, 
            0x91056C1355BA5A11ULL, 0xBBC1D50264E23DCFULL, 0x8575B5FD7501A788ULL, 0xE8A02F6A68DD93D7ULL, 
            0xF1F85CBA2E7104A0ULL, 0xB90E2299B470691DULL, 0x0FCDC46FFBB62BA3ULL, 0xEA6045727192B6F5ULL, 
            0x7B096086C795DC16ULL, 0x3B40CA4125CC3428ULL, 0x9863FACED4A251DFULL, 0xAEC716FBBC9E1C0BULL, 
            0x9E90776CC6C8FE09ULL, 0xB8C774A6A2280635ULL, 0x20F995A25AA9D71BULL, 0x6BFEA56966F0313BULL, 
            0x4C4B5F8217B88D53ULL, 0x2073866BE53F2CCBULL, 0x78FFDDC798656242ULL, 0xBB3442C540270A02ULL, 
            0x5EFE0F1EC3D76320ULL, 0xD4135EA2ABCC9BBDULL, 0xD157E3D979B893B5ULL, 0x81DFD19F45FF6460ULL, 
            0x9AEAEED44C772B00ULL, 0xF8EC5534ED9473C1ULL, 0xC571023832B7582AULL, 0xBB051CA0774E3D49ULL
        },
        {
            0x2C49A1F2131B2FCEULL, 0x4EB96BD9FE19AE27ULL, 0xD545612ABBC40341ULL, 0x716DB33F9E3F0817ULL, 
            0x0C394B7F26113557ULL, 0x10495C61B7D98C6FULL, 0x00CDD9E7E6094780ULL, 0x7BCDD5940F9BF685ULL, 
            0xA75B599ED742D9E5ULL, 0x0EEBAE0783AB1A8AULL, 0xB1B0E5A3D2B5F528ULL, 0x0B15B0F8D541FED8ULL, 
            0x59E262A67C17B3FBULL, 0x95313C89B74618F0ULL, 0x71C1EFB8A79DE4E8ULL, 0x08DF762816277788ULL, 
            0xF74E3026A8D6DE73ULL, 0x39CBD9EE8DFCF127ULL, 0xA9E2DC49AD6783B7ULL, 0x383F044FD6D0651FULL, 
            0x7321E7298F9EE9D0ULL, 0x2D7B59A3D7808B73ULL, 0x6CFB14EB98B15D16ULL, 0xD71DAA3DD3F7A63DULL, 
            0x14DEE1E678EED0F9ULL, 0x881378D16B1E96A3ULL, 0xBFDD8180A2DF3448ULL, 0xAAE919BC982B2A01ULL, 
            0x5A68283625014E4BULL, 0x340FD31BBD13C181ULL, 0x7FDA415A3567E554ULL, 0x277DAFB8A07F168EULL
        },
        {
            0x940EF8A05772AB14ULL, 0x9F32571FEFA66C25ULL, 0x65771849FFBCE902ULL, 0x97454027CCB31709ULL, 
            0x29629B44B216A409ULL, 0x1DB31B7247CFF9D4ULL, 0x6E858D18576E6C16ULL, 0x5B3EEAD36F7539F1ULL, 
            0xB24BBFE3B6D1F75EULL, 0x952FAA754B6F0331ULL, 0xA400BA5DE8072D92ULL, 0xFA2E3D2E02B5587FULL, 
            0xFFC7290BF899FD26ULL, 0x597B15A79D3FA8ECULL, 0xAB907D5C4C8AC6DCULL, 0x77A22C12DC9665D1ULL, 
            0x8A1B007A16E7E783ULL, 0xBA4F5637471F5AB5ULL, 0x217D44F9C0AAAC55ULL, 0xF79007AE26BD2CFCULL, 
            0xCD9C983E167F44A0ULL, 0x6CBF728BCBE7FFB7ULL, 0x9F114AD67BCE8466ULL, 0xB94F3931BB5BBA63ULL, 
            0x84E19A171011C515ULL, 0x5D18FD8EB1C1F1D2ULL, 0x389C807922403244ULL, 0x200DB46148ACE6B4ULL, 
            0x03363A2B0D320A2FULL, 0xD0C565ADD418E491ULL, 0x6C848CDCE24106D6ULL, 0x03540E6087978926ULL
        },
        {
            0x1F947DD8975A7688ULL, 0xD53FBB33FE733E9BULL, 0x877560CB30DE621DULL, 0x7ED3E8CF1D0D40E7ULL, 
            0x93A78980AAF73FF2ULL, 0xBB329CA9ED86105BULL, 0x8793A44F0DB3ADF7ULL, 0xCB00D4ED319A793DULL, 
            0x828B367D4237713EULL, 0x1112F5FED2F06DF8ULL, 0x459E94889C3E4552ULL, 0x65950BA3CEA5E7F0ULL, 
            0x741DA4AB1F17F375ULL, 0x8DB8D015AB0D79D4ULL, 0x61BEFF2104CF3042ULL, 0xB6FBA88ABCA767E1ULL, 
            0x845A24A61AAC2CE6ULL, 0x7CF22D57AA0678BEULL, 0x9A8A4FA19E056F91ULL, 0x54868B03E19D5A53ULL, 
            0x72ACB0C53DB9FB5AULL, 0x694D1609560F797BULL, 0xA9DF08ACCC7172E5ULL, 0xDF7E287E34EC36E5ULL, 
            0x10A3C0A29D0A8399ULL, 0xBEA9797217433398ULL, 0xAE044CA477A14A5AULL, 0x23563BF88E1C2717ULL, 
            0xF9EDB26099AC519BULL, 0x919E48DD3D214A07ULL, 0xD8D779A28C39B437ULL, 0xC41CE392D27D33DDULL
        },
        {
            0xF960A2C539496E9DULL, 0xB9BD0BD0FE891629ULL, 0x49584E027A1BD757ULL, 0xF3DE0AB543D0FE01ULL, 
            0x70E9A87490D9FD02ULL, 0xC24659D57BE46A2AULL, 0x05680E2745EF1114ULL, 0x9A7C85779A51136AULL, 
            0xED37605AF22EB91EULL, 0xFDC353C373AD5D51ULL, 0x3515192A998AAEF0ULL, 0xC62075910210676AULL, 
            0x0908F785808FE309ULL, 0x6CBE3A4F93A22323ULL, 0xDF8841AD57564F36ULL, 0x5F7BD30116F68ADCULL, 
            0x230AD11F11010FB3ULL, 0x24A71AF19F54F0DBULL, 0xC1EE50A040EE054DULL, 0x67290C493E468133ULL, 
            0x619CAB8BFC920559ULL, 0x1CD41C080F47AA30ULL, 0x86B053D641EAC19FULL, 0x4D920C1577B5AD51ULL, 
            0x032328B4B2E327F3ULL, 0xE17512DF10E0B4FDULL, 0xA23CB42E80AB78BAULL, 0x1C2A73B4C8D95E03ULL, 
            0x6744539F742EA863ULL, 0xBB686EC283DE4C11ULL, 0xDBB0FCBECD4E0426ULL, 0x925C8969247126B6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kTwistConstants = {
    0x5DBA40D4821611E4ULL,
    0xCABBF665E9204AA8ULL,
    0x94F6375B09469753ULL,
    0x5DBA40D4821611E4ULL,
    0xCABBF665E9204AA8ULL,
    0x94F6375B09469753ULL,
    0x5AC2AD0F03DAD73DULL,
    0x12CA170A74BA932FULL,
    0x03,
    0xBC,
    0xC8,
    0x47,
    0x05,
    0x55,
    0x58,
    0xCF
};

